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
 *   2021      Evan Nemerson <evan@nemerson.com>
 */

#define SIMDE_TEST_X86_AVX512_INSN cmpneq

#include <test/x86/avx512/test-avx512.h>
#include <simde/x86/avx512/set.h>
#include <simde/x86/avx512/cmpneq.h>
#include <simde/x86/avx512/blend.h>

static int
test_simde_mm_cmpneq_epi8_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int8_t a[16];
    const int8_t b[16];
    const simde__mmask16 r;
  } test_vec[] = {
    { {  INT8_C(  15),  INT8_C( 112), -INT8_C(  32),  INT8_C(  43), -INT8_C(  96),  INT8_C(  81),  INT8_C( 113), -INT8_C(  57),
         INT8_C(  36),  INT8_C(   4), -INT8_C(  56),  INT8_C(  19),  INT8_C(  21),      INT8_MAX,  INT8_C(  99),  INT8_C( 120) },
      { -INT8_C(  86),  INT8_C( 112), -INT8_C(  32),  INT8_C(   5), -INT8_C(  96),  INT8_C(  81), -INT8_C(  59),  INT8_C( 102),
         INT8_C(  36), -INT8_C( 125), -INT8_C(  56),  INT8_C(  49),  INT8_C(  21),  INT8_C(  89), -INT8_C( 118),  INT8_C( 120) },
      UINT16_C(27337) },
    { {  INT8_C(  67),  INT8_C( 106), -INT8_C(  69), -INT8_C(  76),  INT8_C(  49), -INT8_C(  33), -INT8_C(  71), -INT8_C(   7),
        -INT8_C(  13), -INT8_C(  50),  INT8_C( 120),  INT8_C(  86),  INT8_C(  70),  INT8_C(  35), -INT8_C(  57), -INT8_C(   2) },
      {  INT8_C(  67), -INT8_C(  85), -INT8_C(  69), -INT8_C(  19),  INT8_C(  17), -INT8_C(  33),  INT8_C( 112), -INT8_C(   7),
        -INT8_C(  13), -INT8_C(  50),  INT8_C(  38),  INT8_C(  86), -INT8_C( 111),  INT8_C(  35), -INT8_C(  57), -INT8_C(   2) },
      UINT16_C( 5210) },
    { { -INT8_C( 119), -INT8_C( 117), -INT8_C(  13),  INT8_C(  66), -INT8_C( 124), -INT8_C(  26),  INT8_C(  17), -INT8_C(   3),
         INT8_C(  61),  INT8_C(  87),  INT8_C(  32),  INT8_C(   4),  INT8_C(  85),  INT8_C(  72), -INT8_C(  81), -INT8_C(  36) },
      {  INT8_C(  54), -INT8_C( 117), -INT8_C(  13), -INT8_C(  90), -INT8_C( 124), -INT8_C(  26),  INT8_C(  17), -INT8_C(  76),
         INT8_C(  95), -INT8_C(  79), -INT8_C(  92), -INT8_C(  72), -INT8_C( 122), -INT8_C(   2), -INT8_C(  81),  INT8_C(  16) },
      UINT16_C(49033) },
    { {  INT8_C(  82),  INT8_C(  13), -INT8_C(  90),  INT8_C(  99),  INT8_C(  10), -INT8_C(  29), -INT8_C(  69),  INT8_C(  42),
        -INT8_C(  25),  INT8_C(  16),  INT8_C( 115), -INT8_C( 105), -INT8_C(  20), -INT8_C(  87),  INT8_C(  87), -INT8_C(   6) },
      {  INT8_C(  79),  INT8_C(  13), -INT8_C(  90),  INT8_C(  99), -INT8_C( 103), -INT8_C(  29),  INT8_C(  33),  INT8_C(  61),
        -INT8_C( 125),  INT8_C(  16),  INT8_C(  59), -INT8_C( 105), -INT8_C(  73), -INT8_C(  60),  INT8_C(  87),  INT8_C(  10) },
      UINT16_C(46545) },
    { {  INT8_C( 109), -INT8_C(  36), -INT8_C( 104),  INT8_C(  40),  INT8_C(   6),      INT8_MAX,  INT8_C(  57),  INT8_C( 121),
         INT8_C(  22),  INT8_C(  37),  INT8_C(  34),  INT8_C( 110),  INT8_C(  32),  INT8_C( 114),  INT8_C(  83), -INT8_C( 116) },
      { -INT8_C(  31), -INT8_C(  36),  INT8_C(  87),  INT8_C(  40),  INT8_C(  41),      INT8_MAX, -INT8_C(  86),  INT8_C( 100),
         INT8_C(  22),  INT8_C(  97),  INT8_C(  40),  INT8_C( 110),  INT8_C(  32),  INT8_C( 114),  INT8_C(  83), -INT8_C(  39) },
      UINT16_C(34517) },
    { {  INT8_C(   1), -INT8_C(  36),  INT8_C(   6),  INT8_C(  58),  INT8_C(  85),  INT8_C(  28),  INT8_C(  96),  INT8_C( 120),
        -INT8_C( 118),      INT8_MIN, -INT8_C(  22), -INT8_C(  35),  INT8_C(  12), -INT8_C(  53), -INT8_C(  55),  INT8_C(  99) },
      { -INT8_C(  50), -INT8_C(  36),  INT8_C(   6),  INT8_C( 120),  INT8_C(  85),  INT8_C( 105),  INT8_C(  96),  INT8_C( 120),
        -INT8_C(  94),      INT8_MIN,  INT8_C( 120), -INT8_C( 111),  INT8_C(  30), -INT8_C(  53), -INT8_C(  55),  INT8_C(  99) },
      UINT16_C( 7465) },
    { {  INT8_C(  90),      INT8_MAX,  INT8_C(  58), -INT8_C(  70), -INT8_C(   9), -INT8_C(  60),  INT8_C(  58), -INT8_C(  31),
        -INT8_C(  94),  INT8_C(  70), -INT8_C(  84),  INT8_C( 107), -INT8_C(  87),  INT8_C( 122),  INT8_C(  94), -INT8_C(  24) },
      { -INT8_C(  14),      INT8_MAX,  INT8_C(  58), -INT8_C(  70), -INT8_C(   9), -INT8_C(  13),  INT8_C(  58), -INT8_C(  85),
        -INT8_C( 124),  INT8_C(  47), -INT8_C(  84),  INT8_C( 107),  INT8_C(  78),  INT8_C(  34), -INT8_C(  71), -INT8_C(  88) },
      UINT16_C(62369) },
    { {  INT8_C(  98), -INT8_C( 104), -INT8_C(  72), -INT8_C( 100),  INT8_C( 121),  INT8_C(  90), -INT8_C(  30),  INT8_C(  37),
        -INT8_C(  59), -INT8_C( 116), -INT8_C(  96),  INT8_C(  35),  INT8_C( 116), -INT8_C( 110), -INT8_C(  40), -INT8_C(  59) },
      {  INT8_C(  94), -INT8_C( 104), -INT8_C(  72),  INT8_C( 111),  INT8_C( 121),  INT8_C(  90), -INT8_C(  30),  INT8_C(  37),
        -INT8_C(  59), -INT8_C(  19), -INT8_C(  48), -INT8_C( 110), -INT8_C( 107),  INT8_C( 113), -INT8_C(  40), -INT8_C(  59) },
      UINT16_C(15881) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_mm_loadu_epi8(test_vec[i].a);
    simde__m128i b = simde_mm_loadu_epi8(test_vec[i].b);
    simde__mmask16 r = simde_mm_cmpneq_epi8_mask(a, b);
    simde_assert_equal_mmask16(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i a = simde_test_x86_random_i8x16();
    simde__m128i b = simde_mm_mask_blend_epi8(simde_test_x86_random_mmask16(), a, simde_test_x86_random_i8x16());
    simde__mmask16 r = simde_mm_cmpneq_epi8_mask(a, b);

    simde_test_x86_write_i8x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i8x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_mask_cmpneq_epi8_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask16 k1;
    const int8_t a[16];
    const int8_t b[16];
    const simde__mmask16 r;
  } test_vec[] = {
    { UINT16_C(43285),
      {  INT8_C( 119),  INT8_C(  46), -INT8_C(  81), -INT8_C(  25), -INT8_C( 126),  INT8_C(  57), -INT8_C(  39),  INT8_C(  89),
         INT8_C(  78), -INT8_C(  40), -INT8_C(  34),  INT8_C(  75), -INT8_C(  57), -INT8_C(  90),  INT8_C(  94),  INT8_C(  70) },
      {  INT8_C( 119),  INT8_C(  77), -INT8_C(  95), -INT8_C(  25), -INT8_C( 126),  INT8_C(  57), -INT8_C(  39),  INT8_C(  66),
         INT8_C(  78),  INT8_C( 112), -INT8_C(  34),  INT8_C(  75), -INT8_C( 106), -INT8_C(  90),  INT8_C(  94),  INT8_C(  70) },
      UINT16_C(    4) },
    { UINT16_C( 2293),
      {  INT8_C(  76), -INT8_C(  49),  INT8_C(  97), -INT8_C( 102), -INT8_C(  89),  INT8_C(  64), -INT8_C(  27),  INT8_C( 110),
        -INT8_C(  26),  INT8_C(  67), -INT8_C(  76), -INT8_C(  96), -INT8_C( 111),  INT8_C(  85),  INT8_C( 119),  INT8_C(  88) },
      { -INT8_C(  59), -INT8_C(  49), -INT8_C( 102), -INT8_C( 102), -INT8_C(  89), -INT8_C(  35),  INT8_C(  57),  INT8_C(  18),
        -INT8_C(  26), -INT8_C( 100),  INT8_C(  32), -INT8_C(  96), -INT8_C( 111),  INT8_C(  22),  INT8_C( 119),  INT8_C(  88) },
      UINT16_C(  229) },
    { UINT16_C(35989),
      {  INT8_C( 102),  INT8_C( 122), -INT8_C(   6),  INT8_C(  76), -INT8_C(  67), -INT8_C(  82), -INT8_C(  20),  INT8_C(  78),
         INT8_C(   4),  INT8_C(  99), -INT8_C(  89), -INT8_C(  55),  INT8_C( 111),  INT8_C(  65),  INT8_C(  71), -INT8_C(  21) },
      {  INT8_C( 102),      INT8_MIN, -INT8_C(   3),  INT8_C(  76),  INT8_C(  29), -INT8_C(  82),  INT8_C(  16), -INT8_C(  52),
         INT8_C(  52), -INT8_C(  43), -INT8_C(  57),  INT8_C(  25), -INT8_C(   5),  INT8_C(  65),  INT8_C(  71),  INT8_C(  97) },
      UINT16_C(35988) },
    { UINT16_C(37805),
      {  INT8_C(  77), -INT8_C( 103), -INT8_C(  30),  INT8_C(  81), -INT8_C(   4), -INT8_C( 119),  INT8_C(  26),  INT8_C( 107),
        -INT8_C(  54),  INT8_C(  98),  INT8_C(  86), -INT8_C(  23), -INT8_C(  30),  INT8_C(  83),  INT8_C(  62), -INT8_C(   1) },
      {  INT8_C( 113), -INT8_C( 103), -INT8_C(  53),  INT8_C(  81), -INT8_C(   4), -INT8_C( 119), -INT8_C(  66),  INT8_C(  30),
        -INT8_C(  54),  INT8_C(  99),  INT8_C(  86), -INT8_C(  60),  INT8_C(   2),  INT8_C(  44),  INT8_C(  62), -INT8_C(   1) },
      UINT16_C( 4741) },
    { UINT16_C(49569),
      { -INT8_C(  61), -INT8_C(  68),  INT8_C(  44), -INT8_C( 115),  INT8_C(  30), -INT8_C( 126),  INT8_C( 119),  INT8_C(   0),
        -INT8_C(  42), -INT8_C(  75),  INT8_C(   0),  INT8_C(  71),  INT8_C(   3), -INT8_C(  53), -INT8_C(  19),  INT8_C(  39) },
      {  INT8_C(  94), -INT8_C(  85),  INT8_C(  69),  INT8_C(  76),  INT8_C(  15), -INT8_C(  59),  INT8_C( 119),  INT8_C(  17),
        -INT8_C(  15), -INT8_C(  75),  INT8_C(  97),  INT8_C(  71),  INT8_C(   3),  INT8_C(   3), -INT8_C(  19),  INT8_C( 102) },
      UINT16_C(33185) },
    { UINT16_C(56819),
      {  INT8_C(  39),  INT8_C( 106), -INT8_C(  35), -INT8_C(   3),  INT8_C(  31), -INT8_C(  35),  INT8_C(  69),  INT8_C(  35),
        -INT8_C(  87),  INT8_C(  50),  INT8_C(  74),  INT8_C(   7), -INT8_C(  35), -INT8_C( 113),  INT8_C(  83), -INT8_C(  20) },
      {  INT8_C(  39),  INT8_C( 106), -INT8_C(   2), -INT8_C(   3), -INT8_C(  51),  INT8_C(  95),  INT8_C(  69),  INT8_C(  35),
        -INT8_C(  87),  INT8_C(  50), -INT8_C(  42),  INT8_C(  33),  INT8_C(  26), -INT8_C( 113), -INT8_C(   2),  INT8_C(  66) },
      UINT16_C(56368) },
    { UINT16_C(21567),
      { -INT8_C(  71), -INT8_C( 124),  INT8_C( 119),  INT8_C(  98), -INT8_C(  74), -INT8_C(  63),  INT8_C( 105), -INT8_C( 108),
         INT8_C(  80), -INT8_C(  67),      INT8_MIN, -INT8_C(  91),  INT8_C(  33),  INT8_C( 126), -INT8_C(  21), -INT8_C(  17) },
      { -INT8_C(  71), -INT8_C(  24),  INT8_C(  95),  INT8_C(  64),  INT8_C(  93),  INT8_C(  54),  INT8_C(  98), -INT8_C( 108),
         INT8_C(   0),  INT8_C(  96), -INT8_C(  70),  INT8_C(  52),  INT8_C(  60), -INT8_C(   7), -INT8_C( 120), -INT8_C(  10) },
      UINT16_C(21566) },
    { UINT16_C(13400),
      { -INT8_C(  64), -INT8_C(  62), -INT8_C(  56),  INT8_C(  17),      INT8_MAX,  INT8_C(  73), -INT8_C(  74), -INT8_C(  96),
        -INT8_C(  57), -INT8_C(  95), -INT8_C( 113), -INT8_C(  91), -INT8_C( 119), -INT8_C(  17), -INT8_C(  26), -INT8_C(  26) },
      {  INT8_C(  37), -INT8_C(  62),  INT8_C(  94),  INT8_C(  17), -INT8_C(  88),  INT8_C(  24),  INT8_C(  89), -INT8_C(  27),
         INT8_C(  18), -INT8_C(  95), -INT8_C(  37), -INT8_C( 112), -INT8_C( 119), -INT8_C(  17), -INT8_C(  26), -INT8_C(  94) },
      UINT16_C( 1104) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_mm_loadu_epi8(test_vec[i].a);
    simde__m128i b = simde_mm_loadu_epi8(test_vec[i].b);
    simde__mmask16 r = simde_mm_mask_cmpneq_epi8_mask(test_vec[i].k1, a, b);
    simde_assert_equal_mmask16(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask16 k1 = simde_test_x86_random_mmask16();
    simde__m128i a = simde_test_x86_random_i8x16();
    simde__m128i b = simde_mm_mask_blend_epi8(simde_test_x86_random_mmask16(), a, simde_test_x86_random_i8x16());
    simde__mmask16 r = simde_mm_mask_cmpneq_epi8_mask(k1, a, b);

    simde_test_x86_write_mmask16(2, k1, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i8x16(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i8x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_cmpneq_epu8_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const uint8_t a[16];
    const uint8_t b[16];
    const simde__mmask16 r;
  } test_vec[] = {
    { { UINT8_C( 40), UINT8_C(174), UINT8_C(150), UINT8_C(231), UINT8_C( 66), UINT8_C( 19), UINT8_C( 35), UINT8_C( 15),
        UINT8_C(109), UINT8_C( 29), UINT8_C(173), UINT8_C( 55), UINT8_C(124), UINT8_C(133), UINT8_C( 86), UINT8_C(191) },
      { UINT8_C( 40), UINT8_C(174), UINT8_C(100), UINT8_C(231), UINT8_C( 66), UINT8_C( 29), UINT8_C( 35), UINT8_C( 15),
        UINT8_C(147), UINT8_C( 29), UINT8_C( 13), UINT8_C(243), UINT8_C(196), UINT8_C(133), UINT8_C( 86), UINT8_C(236) },
      UINT16_C(40228) },
    { { UINT8_C(211), UINT8_C(102), UINT8_C(176), UINT8_C(246), UINT8_C(118), UINT8_C( 29), UINT8_C( 20), UINT8_C( 35),
        UINT8_C( 85), UINT8_C(144), UINT8_C(168), UINT8_C(171), UINT8_C( 80), UINT8_C(223), UINT8_C(182), UINT8_C(180) },
      { UINT8_C(211), UINT8_C(205), UINT8_C(176), UINT8_C(150), UINT8_C(118), UINT8_C( 29), UINT8_C( 11), UINT8_C(201),
        UINT8_C( 87), UINT8_C(207), UINT8_C(168), UINT8_C( 94), UINT8_C( 80), UINT8_C( 99), UINT8_C(182), UINT8_C(143) },
      UINT16_C(43978) },
    { { UINT8_C(133), UINT8_C( 64), UINT8_C(201), UINT8_C(153), UINT8_C( 99), UINT8_C( 30), UINT8_C( 42), UINT8_C( 11),
        UINT8_C(201), UINT8_C(122), UINT8_C(235), UINT8_C(127), UINT8_C( 46), UINT8_C( 41), UINT8_C( 76),    UINT8_MAX },
      { UINT8_C(133), UINT8_C(  8), UINT8_C( 99), UINT8_C(202), UINT8_C(209), UINT8_C(186), UINT8_C(153), UINT8_C( 11),
        UINT8_C( 24), UINT8_C( 84), UINT8_C(116), UINT8_C(127), UINT8_C( 46), UINT8_C( 41), UINT8_C( 76), UINT8_C(105) },
      UINT16_C(34686) },
    { { UINT8_C(  2), UINT8_C(225), UINT8_C(165), UINT8_C( 44), UINT8_C(236), UINT8_C(110), UINT8_C(166), UINT8_C(215),
        UINT8_C(238), UINT8_C(212), UINT8_C(  0), UINT8_C( 58), UINT8_C(211), UINT8_C(191), UINT8_C( 67), UINT8_C( 54) },
      { UINT8_C(  2), UINT8_C( 20), UINT8_C(240), UINT8_C( 44), UINT8_C( 37), UINT8_C(  8), UINT8_C(166), UINT8_C(215),
        UINT8_C( 27), UINT8_C( 90), UINT8_C(215), UINT8_C( 58), UINT8_C(211), UINT8_C(191), UINT8_C( 67), UINT8_C( 54) },
      UINT16_C( 1846) },
    { { UINT8_C(242), UINT8_C( 34), UINT8_C(117), UINT8_C(153), UINT8_C(250), UINT8_C( 99), UINT8_C(109), UINT8_C(250),
        UINT8_C(158), UINT8_C( 65), UINT8_C(186), UINT8_C(225), UINT8_C(119), UINT8_C( 67), UINT8_C(245), UINT8_C(104) },
      { UINT8_C(242), UINT8_C( 34), UINT8_C(117), UINT8_C(221), UINT8_C(179), UINT8_C(140), UINT8_C(109), UINT8_C(250),
        UINT8_C(158), UINT8_C( 65), UINT8_C(223), UINT8_C(225), UINT8_C(119), UINT8_C( 67), UINT8_C(206), UINT8_C(104) },
      UINT16_C(17464) },
    { { UINT8_C( 76), UINT8_C( 50), UINT8_C(167), UINT8_C(186), UINT8_C( 44), UINT8_C( 69), UINT8_C(251), UINT8_C(230),
        UINT8_C( 38), UINT8_C(114), UINT8_C( 42), UINT8_C( 28), UINT8_C(218), UINT8_C(144), UINT8_C( 54), UINT8_C( 75) },
      { UINT8_C(109), UINT8_C(234), UINT8_C(167), UINT8_C(186), UINT8_C(116), UINT8_C( 69), UINT8_C(159), UINT8_C( 84),
        UINT8_C( 38), UINT8_C( 96), UINT8_C(105), UINT8_C(211), UINT8_C( 20), UINT8_C(161), UINT8_C( 54), UINT8_C( 96) },
      UINT16_C(48851) },
    { { UINT8_C( 26), UINT8_C(  0), UINT8_C(  4), UINT8_C( 21), UINT8_C(230), UINT8_C( 42), UINT8_C(136), UINT8_C( 16),
        UINT8_C( 70), UINT8_C( 98), UINT8_C(160), UINT8_C(125), UINT8_C(173), UINT8_C( 13), UINT8_C(103), UINT8_C(132) },
      { UINT8_C( 26), UINT8_C(219), UINT8_C(193), UINT8_C( 81), UINT8_C(230), UINT8_C( 42), UINT8_C(136), UINT8_C( 16),
        UINT8_C( 70), UINT8_C(198), UINT8_C(160), UINT8_C(125), UINT8_C( 38), UINT8_C( 14), UINT8_C(110), UINT8_C(132) },
      UINT16_C(29198) },
    { { UINT8_C( 86), UINT8_C(244), UINT8_C(157), UINT8_C(222), UINT8_C(  5), UINT8_C(227), UINT8_C( 65), UINT8_C(165),
        UINT8_C( 96), UINT8_C(238), UINT8_C(179), UINT8_C(199), UINT8_C(115), UINT8_C(101), UINT8_C(163), UINT8_C( 52) },
      { UINT8_C( 86), UINT8_C(210), UINT8_C(250), UINT8_C(222), UINT8_C(107), UINT8_C(147), UINT8_C( 65), UINT8_C(166),
        UINT8_C( 67), UINT8_C(238), UINT8_C(179), UINT8_C(199), UINT8_C(115), UINT8_C(101), UINT8_C( 36), UINT8_C(236) },
      UINT16_C(49590) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_mm_loadu_epi8(test_vec[i].a);
    simde__m128i b = simde_mm_loadu_epi8(test_vec[i].b);
    simde__mmask16 r = simde_mm_cmpneq_epu8_mask(a, b);
    simde_assert_equal_mmask16(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i a = simde_test_x86_random_u8x16();
    simde__m128i b = simde_mm_mask_blend_epi8(simde_test_x86_random_mmask16(), a, simde_test_x86_random_u8x16());
    simde__mmask16 r = simde_mm_cmpneq_epu8_mask(a, b);

    simde_test_x86_write_u8x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_u8x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_mask_cmpneq_epu8_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask16 k1;
    const uint8_t a[16];
    const uint8_t b[16];
    const simde__mmask16 r;
  } test_vec[] = {
    { UINT16_C(48075),
      { UINT8_C(165), UINT8_C( 12), UINT8_C( 97), UINT8_C(  5), UINT8_C(250), UINT8_C( 20), UINT8_C(205), UINT8_C(109),
        UINT8_C(121), UINT8_C(112), UINT8_C(162), UINT8_C( 47), UINT8_C( 66), UINT8_C(156), UINT8_C(152), UINT8_C(174) },
      { UINT8_C( 48), UINT8_C( 12), UINT8_C( 84), UINT8_C(  5), UINT8_C( 27), UINT8_C(  8), UINT8_C( 37), UINT8_C(109),
        UINT8_C(202), UINT8_C(112), UINT8_C(158), UINT8_C(128), UINT8_C( 11), UINT8_C(156), UINT8_C(152), UINT8_C(176) },
      UINT16_C(39233) },
    { UINT16_C(28598),
      { UINT8_C(177), UINT8_C(131), UINT8_C(221), UINT8_C( 42), UINT8_C(243), UINT8_C(127), UINT8_C( 89), UINT8_C( 53),
        UINT8_C( 27), UINT8_C(241), UINT8_C(227), UINT8_C( 75), UINT8_C(184), UINT8_C( 55), UINT8_C(191), UINT8_C(211) },
      { UINT8_C( 63), UINT8_C(228), UINT8_C(221), UINT8_C( 42), UINT8_C(243), UINT8_C( 35), UINT8_C( 89), UINT8_C( 53),
        UINT8_C(140), UINT8_C(241), UINT8_C(234), UINT8_C(  1), UINT8_C(184), UINT8_C( 55), UINT8_C(112), UINT8_C(211) },
      UINT16_C(19746) },
    { UINT16_C( 5694),
      { UINT8_C(204), UINT8_C(151), UINT8_C( 76), UINT8_C(232), UINT8_C(137), UINT8_C( 47), UINT8_C( 51), UINT8_C( 65),
        UINT8_C(103), UINT8_C(242), UINT8_C( 20), UINT8_C(166), UINT8_C(215), UINT8_C(153), UINT8_C(176), UINT8_C(  5) },
      { UINT8_C(204), UINT8_C(151), UINT8_C( 63), UINT8_C( 72), UINT8_C(137), UINT8_C( 47), UINT8_C( 73), UINT8_C( 65),
        UINT8_C(103), UINT8_C(242), UINT8_C( 20), UINT8_C(166), UINT8_C(  7), UINT8_C(153), UINT8_C(  4), UINT8_C(  5) },
      UINT16_C( 4108) },
    { UINT16_C(54716),
      { UINT8_C(128), UINT8_C(239), UINT8_C( 22), UINT8_C(231), UINT8_C(226), UINT8_C( 43), UINT8_C(141), UINT8_C(185),
        UINT8_C(196), UINT8_C( 61), UINT8_C(190), UINT8_C(129), UINT8_C(119), UINT8_C(254), UINT8_C(201), UINT8_C(119) },
      { UINT8_C(128), UINT8_C(239), UINT8_C(218), UINT8_C(231), UINT8_C(205), UINT8_C( 43), UINT8_C(224), UINT8_C(185),
        UINT8_C(  6), UINT8_C(229), UINT8_C(168), UINT8_C( 83), UINT8_C( 53), UINT8_C(100), UINT8_C(201), UINT8_C(119) },
      UINT16_C( 5396) },
    { UINT16_C(13980),
      { UINT8_C(106), UINT8_C( 42), UINT8_C(239), UINT8_C( 46), UINT8_C(103), UINT8_C(173), UINT8_C(175), UINT8_C(223),
        UINT8_C(171), UINT8_C(121), UINT8_C( 86), UINT8_C(211), UINT8_C(140), UINT8_C( 49), UINT8_C(198), UINT8_C( 89) },
      { UINT8_C(130), UINT8_C( 42), UINT8_C( 45), UINT8_C(137), UINT8_C(139), UINT8_C(214), UINT8_C(175), UINT8_C(223),
        UINT8_C( 58), UINT8_C(  4), UINT8_C( 86), UINT8_C(211), UINT8_C( 67), UINT8_C( 19), UINT8_C(198), UINT8_C(173) },
      UINT16_C(12828) },
    { UINT16_C(42204),
      { UINT8_C( 97), UINT8_C(139), UINT8_C(131), UINT8_C( 12), UINT8_C(  4), UINT8_C(218), UINT8_C(224), UINT8_C(144),
        UINT8_C( 11), UINT8_C(166), UINT8_C(233), UINT8_C(141), UINT8_C( 76), UINT8_C( 23), UINT8_C( 22), UINT8_C(216) },
      { UINT8_C(237), UINT8_C(242), UINT8_C(153), UINT8_C( 39), UINT8_C(  4), UINT8_C(218), UINT8_C(182), UINT8_C(144),
        UINT8_C( 34), UINT8_C(122), UINT8_C(232), UINT8_C(141), UINT8_C( 76), UINT8_C( 23), UINT8_C( 22), UINT8_C(143) },
      UINT16_C(33868) },
    { UINT16_C(21659),
      { UINT8_C( 97), UINT8_C(123), UINT8_C(228), UINT8_C(108), UINT8_C( 33), UINT8_C(206), UINT8_C(250), UINT8_C(110),
        UINT8_C(229), UINT8_C( 16), UINT8_C( 70), UINT8_C(210), UINT8_C(  3), UINT8_C(223), UINT8_C(249), UINT8_C(250) },
      { UINT8_C( 97), UINT8_C(175), UINT8_C( 52), UINT8_C( 17), UINT8_C( 42), UINT8_C( 28), UINT8_C(112), UINT8_C( 88),
        UINT8_C(229), UINT8_C( 16), UINT8_C( 70), UINT8_C( 48), UINT8_C(  3), UINT8_C(130), UINT8_C(132), UINT8_C(250) },
      UINT16_C(16538) },
    { UINT16_C( 8138),
      { UINT8_C( 54), UINT8_C(196), UINT8_C(141), UINT8_C( 27), UINT8_C(212), UINT8_C(211), UINT8_C(237), UINT8_C(215),
        UINT8_C(178), UINT8_C(231), UINT8_C(209), UINT8_C(161), UINT8_C(150), UINT8_C(  6), UINT8_C(178), UINT8_C(192) },
      { UINT8_C( 54), UINT8_C( 34), UINT8_C( 24), UINT8_C(  3), UINT8_C(151),    UINT8_MAX, UINT8_C( 51), UINT8_C(215),
        UINT8_C(130), UINT8_C(231), UINT8_C(240), UINT8_C(128), UINT8_C(150), UINT8_C(186), UINT8_C(178), UINT8_C(192) },
      UINT16_C( 3402) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_mm_loadu_epi8(test_vec[i].a);
    simde__m128i b = simde_mm_loadu_epi8(test_vec[i].b);
    simde__mmask16 r = simde_mm_mask_cmpneq_epu8_mask(test_vec[i].k1, a, b);
    simde_assert_equal_mmask16(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask16 k1 = simde_test_x86_random_mmask16();
    simde__m128i a = simde_test_x86_random_u8x16();
    simde__m128i b = simde_mm_mask_blend_epi8(simde_test_x86_random_mmask16(), a, simde_test_x86_random_u8x16());
    simde__mmask16 r = simde_mm_mask_cmpneq_epu8_mask(k1, a, b);

    simde_test_x86_write_mmask16(2, k1, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_u8x16(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_u8x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_cmpneq_epi16_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int16_t a[8];
    const int16_t b[8];
    const simde__mmask8 r;
  } test_vec[] = {
    { { -INT16_C( 18013),  INT16_C( 18652), -INT16_C( 26325),  INT16_C(  6164), -INT16_C( 21146), -INT16_C( 29070),  INT16_C( 25810), -INT16_C(  8957) },
      { -INT16_C( 32319),  INT16_C( 18652), -INT16_C( 20263),  INT16_C(  6164),  INT16_C( 15127), -INT16_C( 29070),  INT16_C( 25810), -INT16_C(  8957) },
      UINT8_C( 21) },
    { { -INT16_C( 22599),  INT16_C( 21057),  INT16_C( 22971),  INT16_C( 26808),  INT16_C( 18123),  INT16_C( 12347),  INT16_C(  6218), -INT16_C( 13327) },
      { -INT16_C( 27994),  INT16_C( 21057),  INT16_C( 16880),  INT16_C( 11118),  INT16_C( 18123),  INT16_C( 13798),  INT16_C( 17914), -INT16_C( 19637) },
      UINT8_C(237) },
    { {  INT16_C(  1420), -INT16_C(  6744),  INT16_C(  4541),  INT16_C(  1201), -INT16_C(  7860),  INT16_C( 25678),  INT16_C(  6610),  INT16_C( 25610) },
      {  INT16_C(  1420), -INT16_C(   428),  INT16_C( 32719), -INT16_C(  4905),  INT16_C(  3430),  INT16_C( 25678),  INT16_C(  6610), -INT16_C(  7016) },
      UINT8_C(158) },
    { { -INT16_C( 14015),  INT16_C( 21084),  INT16_C( 24698),  INT16_C( 23454),  INT16_C(   686), -INT16_C( 14547), -INT16_C( 28147),  INT16_C( 28292) },
      { -INT16_C( 31770),  INT16_C( 21084),  INT16_C( 10586),  INT16_C( 26572),  INT16_C(   686), -INT16_C( 22081), -INT16_C( 23792),  INT16_C( 28292) },
      UINT8_C(109) },
    { { -INT16_C( 23644),  INT16_C(  1255),  INT16_C( 17217),  INT16_C( 17330),  INT16_C( 31088),  INT16_C(   592), -INT16_C( 16643), -INT16_C( 32535) },
      { -INT16_C( 23644),  INT16_C(  9691),  INT16_C( 16923),  INT16_C( 17330), -INT16_C(  8702),  INT16_C(   592), -INT16_C( 16643), -INT16_C( 13806) },
      UINT8_C(150) },
    { { -INT16_C( 12550),  INT16_C( 15831),  INT16_C(  7040), -INT16_C(  1619), -INT16_C( 20373),  INT16_C( 10999),  INT16_C( 30617), -INT16_C(  6107) },
      {  INT16_C( 19026),  INT16_C( 15831), -INT16_C( 27265),  INT16_C( 24215),  INT16_C( 15416),  INT16_C( 10999),  INT16_C( 30617), -INT16_C(  6107) },
      UINT8_C( 29) },
    { { -INT16_C( 31079), -INT16_C( 19298), -INT16_C( 26829), -INT16_C(  7392),  INT16_C( 19086),  INT16_C(  1660),  INT16_C( 25711), -INT16_C( 17832) },
      { -INT16_C(  4761), -INT16_C(   711), -INT16_C( 26748), -INT16_C( 16075),  INT16_C( 24604),  INT16_C(  1660),  INT16_C( 22818), -INT16_C( 17272) },
      UINT8_C(223) },
    { {  INT16_C( 28710), -INT16_C( 16878), -INT16_C(  2416), -INT16_C(  9652),  INT16_C( 21106), -INT16_C( 10422),  INT16_C(  1195), -INT16_C( 26562) },
      {  INT16_C( 28710), -INT16_C( 16878), -INT16_C(  2416), -INT16_C(  9652),  INT16_C( 21106),  INT16_C( 18419),  INT16_C(  1195), -INT16_C( 26562) },
      UINT8_C( 32) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_mm_loadu_epi16(test_vec[i].a);
    simde__m128i b = simde_mm_loadu_epi16(test_vec[i].b);
    simde__mmask8 r = simde_mm_cmpneq_epi16_mask(a, b);
    simde_assert_equal_mmask8(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i a = simde_test_x86_random_i16x8();
    simde__m128i b = simde_mm_mask_blend_epi16(simde_test_x86_random_mmask8(), a, simde_test_x86_random_i16x8());
    simde__mmask8 r = simde_mm_cmpneq_epi16_mask(a, b);

    simde_test_x86_write_i16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_mask_cmpneq_epi16_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k1;
    const int16_t a[8];
    const int16_t b[8];
    const simde__mmask8 r;
  } test_vec[] = {
    { UINT8_C( 62),
      {  INT16_C( 17578), -INT16_C(  3927),  INT16_C( 20836), -INT16_C( 31549),  INT16_C( 32108),  INT16_C( 11114), -INT16_C( 24083),  INT16_C( 24275) },
      {  INT16_C(  8028), -INT16_C(  3927),  INT16_C( 20836), -INT16_C( 31549),  INT16_C( 32108),  INT16_C( 24573), -INT16_C( 25145),  INT16_C( 29342) },
      UINT8_C( 32) },
    { UINT8_C( 71),
      {  INT16_C( 18018),  INT16_C(  9624),  INT16_C(  1226),  INT16_C( 13475), -INT16_C( 28625),  INT16_C(   725),  INT16_C( 13038), -INT16_C( 24543) },
      {  INT16_C( 18018), -INT16_C( 14494),  INT16_C(  1226), -INT16_C(  2565), -INT16_C( 15791), -INT16_C(  4205),  INT16_C( 13038), -INT16_C( 27082) },
      UINT8_C(  2) },
    { UINT8_C(206),
      { -INT16_C( 31300),  INT16_C( 24530),  INT16_C(   697), -INT16_C( 28689), -INT16_C(  8956),  INT16_C(  9921),  INT16_C(  1149), -INT16_C(  8219) },
      { -INT16_C( 31300), -INT16_C( 14384),  INT16_C(   697),  INT16_C( 26249), -INT16_C( 16880),  INT16_C(  9921),  INT16_C(  1149), -INT16_C(  8219) },
      UINT8_C( 10) },
    { UINT8_C(231),
      { -INT16_C( 11409),  INT16_C( 24297), -INT16_C(  4766),  INT16_C(  9019), -INT16_C( 18413), -INT16_C(  2008), -INT16_C(  2921),  INT16_C( 26838) },
      { -INT16_C( 11409),  INT16_C( 24297), -INT16_C( 26097), -INT16_C(  5886), -INT16_C( 18413), -INT16_C(  2690), -INT16_C( 26521),  INT16_C( 26838) },
      UINT8_C(100) },
    { UINT8_C(197),
      { -INT16_C( 12747),  INT16_C( 29106), -INT16_C( 14606),  INT16_C(  6697), -INT16_C( 15938), -INT16_C( 27634), -INT16_C( 14039), -INT16_C( 19907) },
      {  INT16_C( 19469),  INT16_C(  4172),  INT16_C( 11574),  INT16_C(  6697), -INT16_C( 15938), -INT16_C( 27634), -INT16_C( 14039), -INT16_C(  9277) },
      UINT8_C(133) },
    { UINT8_C(117),
      {  INT16_C( 31052),  INT16_C( 30011), -INT16_C(  1389), -INT16_C( 24266),  INT16_C( 24462), -INT16_C( 13206),  INT16_C( 30738),  INT16_C( 24088) },
      {  INT16_C( 31052), -INT16_C(  4213), -INT16_C(  1389),  INT16_C( 20669),  INT16_C( 24462), -INT16_C( 13206),  INT16_C( 30738),  INT16_C( 24088) },
      UINT8_C(  0) },
    { UINT8_C( 31),
      { -INT16_C( 25089),  INT16_C( 13849), -INT16_C( 22465), -INT16_C( 22123), -INT16_C( 22668), -INT16_C( 29663), -INT16_C( 22266), -INT16_C( 28197) },
      { -INT16_C(  8552),  INT16_C( 22079), -INT16_C(  5586),  INT16_C( 14265), -INT16_C( 22668),  INT16_C( 15815), -INT16_C( 11903), -INT16_C( 28197) },
      UINT8_C( 15) },
    { UINT8_C(118),
      { -INT16_C( 20810),  INT16_C( 19486), -INT16_C( 28073),  INT16_C( 31219), -INT16_C(  1762), -INT16_C(  1758), -INT16_C( 17525), -INT16_C( 13609) },
      { -INT16_C( 20810), -INT16_C( 13644), -INT16_C( 28073),  INT16_C( 31219),  INT16_C( 16970), -INT16_C( 22571),  INT16_C( 17602),  INT16_C( 31005) },
      UINT8_C(114) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_mm_loadu_epi16(test_vec[i].a);
    simde__m128i b = simde_mm_loadu_epi16(test_vec[i].b);
    simde__mmask8 r = simde_mm_mask_cmpneq_epi16_mask(test_vec[i].k1, a, b);
    simde_assert_equal_mmask8(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k1 = simde_test_x86_random_mmask8();
    simde__m128i a = simde_test_x86_random_i16x8();
    simde__m128i b = simde_mm_mask_blend_epi16(simde_test_x86_random_mmask8(), a, simde_test_x86_random_i16x8());
    simde__mmask8 r = simde_mm_mask_cmpneq_epi16_mask(k1, a, b);

    simde_test_x86_write_mmask8(2, k1, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i16x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_cmpneq_epu16_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const uint16_t a[8];
    const uint16_t b[8];
    const simde__mmask8 r;
  } test_vec[] = {
    { { UINT16_C(50491), UINT16_C(52554), UINT16_C(50104), UINT16_C(45803), UINT16_C(58853), UINT16_C(41021), UINT16_C( 1980), UINT16_C(49841) },
      { UINT16_C(31675), UINT16_C(51710), UINT16_C(  572), UINT16_C(32275), UINT16_C(47832), UINT16_C( 7233), UINT16_C(47831), UINT16_C(49841) },
      UINT8_C(127) },
    { { UINT16_C(57177), UINT16_C( 7223), UINT16_C(59851), UINT16_C(45057), UINT16_C(41510), UINT16_C(11628), UINT16_C(11859), UINT16_C(53225) },
      { UINT16_C(45613), UINT16_C( 7223), UINT16_C(59851), UINT16_C(32775), UINT16_C(41510), UINT16_C(11628), UINT16_C(27187), UINT16_C(53225) },
      UINT8_C( 73) },
    { { UINT16_C(43067), UINT16_C( 9492), UINT16_C(50345), UINT16_C(19275), UINT16_C(31025), UINT16_C(24479), UINT16_C(28258), UINT16_C( 5260) },
      { UINT16_C(43067), UINT16_C(  985), UINT16_C(22979), UINT16_C(59342), UINT16_C(31025), UINT16_C(24479), UINT16_C(42583), UINT16_C( 5260) },
      UINT8_C( 78) },
    { { UINT16_C(47225), UINT16_C(15864), UINT16_C(17155), UINT16_C(31854), UINT16_C(52962), UINT16_C(20702), UINT16_C(62042), UINT16_C( 5834) },
      { UINT16_C(47225), UINT16_C( 9690), UINT16_C(17155), UINT16_C(31854), UINT16_C(61916), UINT16_C(20702), UINT16_C(62042), UINT16_C(53201) },
      UINT8_C(146) },
    { { UINT16_C( 3273), UINT16_C( 3221), UINT16_C( 4731), UINT16_C(18927), UINT16_C(16368), UINT16_C(58275), UINT16_C(47625), UINT16_C(55215) },
      { UINT16_C( 3273), UINT16_C(21875), UINT16_C(25259), UINT16_C(39985), UINT16_C(16368), UINT16_C(58275), UINT16_C(49541), UINT16_C(19989) },
      UINT8_C(206) },
    { { UINT16_C(23211), UINT16_C(48457), UINT16_C(37449), UINT16_C(35245), UINT16_C(36917), UINT16_C(61330), UINT16_C(26943), UINT16_C( 5251) },
      { UINT16_C(23211), UINT16_C(48457), UINT16_C(23306), UINT16_C(48872), UINT16_C(36917), UINT16_C( 3907), UINT16_C(37249), UINT16_C(11485) },
      UINT8_C(236) },
    { { UINT16_C(59686), UINT16_C(47157), UINT16_C(48791), UINT16_C(10222), UINT16_C(56657), UINT16_C(47719), UINT16_C(31585), UINT16_C(14999) },
      { UINT16_C(59686), UINT16_C(38212), UINT16_C(48791), UINT16_C(10222), UINT16_C(56657), UINT16_C(47719), UINT16_C(55504), UINT16_C(63428) },
      UINT8_C(194) },
    { { UINT16_C(45049), UINT16_C(47193), UINT16_C(32925), UINT16_C(31497), UINT16_C(50151), UINT16_C(25308), UINT16_C( 5722), UINT16_C(12444) },
      { UINT16_C(12890), UINT16_C(24047), UINT16_C( 6421), UINT16_C( 2212), UINT16_C(31941), UINT16_C(40665), UINT16_C(53312), UINT16_C(12444) },
      UINT8_C(127) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_mm_loadu_epi16(test_vec[i].a);
    simde__m128i b = simde_mm_loadu_epi16(test_vec[i].b);
    simde__mmask8 r = simde_mm_cmpneq_epu16_mask(a, b);
    simde_assert_equal_mmask8(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i a = simde_test_x86_random_u16x8();
    simde__m128i b = simde_mm_mask_blend_epi16(simde_test_x86_random_mmask8(), a, simde_test_x86_random_u16x8());
    simde__mmask8 r = simde_mm_cmpneq_epu16_mask(a, b);

    simde_test_x86_write_u16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_u16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_mask_cmpneq_epu16_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k1;
    const uint16_t a[8];
    const uint16_t b[8];
    const simde__mmask8 r;
  } test_vec[] = {
    { UINT8_C(185),
      { UINT16_C( 7665), UINT16_C(64057), UINT16_C( 8600), UINT16_C(29886), UINT16_C( 6275), UINT16_C( 8330), UINT16_C(58441), UINT16_C(14418) },
      { UINT16_C(26434), UINT16_C(64057), UINT16_C( 6000), UINT16_C(29886), UINT16_C(41653), UINT16_C( 5401), UINT16_C(58441), UINT16_C(52686) },
      UINT8_C(177) },
    { UINT8_C(  7),
      { UINT16_C(19911), UINT16_C(34088), UINT16_C(44225), UINT16_C(19358), UINT16_C(59340), UINT16_C( 7728), UINT16_C(29215), UINT16_C(28805) },
      { UINT16_C(62808), UINT16_C(47751), UINT16_C(44225), UINT16_C(19358), UINT16_C(14161), UINT16_C( 8176), UINT16_C(42244), UINT16_C(52263) },
      UINT8_C(  3) },
    { UINT8_C( 79),
      { UINT16_C(46161), UINT16_C(61435), UINT16_C(50944), UINT16_C(12502), UINT16_C(62949), UINT16_C(27554), UINT16_C(64102), UINT16_C(60768) },
      { UINT16_C(40884), UINT16_C( 4138), UINT16_C(50944), UINT16_C(12502), UINT16_C(19611), UINT16_C(49804), UINT16_C(64102), UINT16_C(60768) },
      UINT8_C(  3) },
    { UINT8_C( 13),
      { UINT16_C(13145), UINT16_C(12244), UINT16_C(47715), UINT16_C( 1317), UINT16_C(35621), UINT16_C(34303), UINT16_C(45944), UINT16_C(41508) },
      { UINT16_C( 7107), UINT16_C( 2846), UINT16_C(47715), UINT16_C( 1317), UINT16_C(28539), UINT16_C(35852), UINT16_C(16600), UINT16_C(41508) },
      UINT8_C(  1) },
    { UINT8_C(110),
      { UINT16_C(55137), UINT16_C(34344), UINT16_C(19932), UINT16_C(56337), UINT16_C(35282), UINT16_C(63375), UINT16_C(21292), UINT16_C(18962) },
      { UINT16_C(55137), UINT16_C(34344), UINT16_C(19932), UINT16_C(44324), UINT16_C(64522), UINT16_C(42221), UINT16_C(21292), UINT16_C(18962) },
      UINT8_C( 40) },
    { UINT8_C( 58),
      { UINT16_C( 5141), UINT16_C( 9863), UINT16_C(23024), UINT16_C(32943), UINT16_C(56144), UINT16_C(25299), UINT16_C(12581), UINT16_C(10358) },
      { UINT16_C( 6118), UINT16_C( 2726), UINT16_C(45508), UINT16_C(45574), UINT16_C(13397), UINT16_C(25299), UINT16_C(19395), UINT16_C(10358) },
      UINT8_C( 26) },
    { UINT8_C( 40),
      { UINT16_C(20734), UINT16_C(44673), UINT16_C(53968), UINT16_C(41865), UINT16_C(44852), UINT16_C(43732), UINT16_C(47831), UINT16_C(32449) },
      { UINT16_C(34500), UINT16_C(44673), UINT16_C(33848), UINT16_C(41865), UINT16_C(44852), UINT16_C(43732), UINT16_C(62875), UINT16_C(32449) },
      UINT8_C(  0) },
    { UINT8_C( 53),
      { UINT16_C( 5447), UINT16_C(53511), UINT16_C(15544), UINT16_C(35968), UINT16_C(22502), UINT16_C(43078), UINT16_C( 2773), UINT16_C( 1070) },
      { UINT16_C(26325), UINT16_C(54408), UINT16_C(29617), UINT16_C(35968), UINT16_C(12799), UINT16_C(43078), UINT16_C( 2773), UINT16_C( 4841) },
      UINT8_C( 21) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_mm_loadu_epi16(test_vec[i].a);
    simde__m128i b = simde_mm_loadu_epi16(test_vec[i].b);
    simde__mmask8 r = simde_mm_mask_cmpneq_epu16_mask(test_vec[i].k1, a, b);
    simde_assert_equal_mmask8(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k1 = simde_test_x86_random_mmask8();
    simde__m128i a = simde_test_x86_random_u16x8();
    simde__m128i b = simde_mm_mask_blend_epi16(simde_test_x86_random_mmask8(), a, simde_test_x86_random_u16x8());
    simde__mmask8 r = simde_mm_mask_cmpneq_epu16_mask(k1, a, b);

    simde_test_x86_write_mmask8(2, k1, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_u16x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_u16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_cmpneq_epi32_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int32_t a[4];
    const int32_t b[4];
    const simde__mmask8 r;
  } test_vec[] = {
    { {  INT32_C(   743498736), -INT32_C(  1156326301),  INT32_C(   764459811),  INT32_C(  1325569513) },
      { -INT32_C(  1862216163), -INT32_C(  1634711699),  INT32_C(    90784899),  INT32_C(   496860205) },
      UINT8_C( 15) },
    { { -INT32_C(   909948179),  INT32_C(   418152029), -INT32_C(  1560208882), -INT32_C(   205434852) },
      { -INT32_C(  1755295152),  INT32_C(   639303394), -INT32_C(  1560208882), -INT32_C(  1438420547) },
      UINT8_C( 11) },
    { { -INT32_C(  2078772474),  INT32_C(  2056466528), -INT32_C(  2120862159),  INT32_C(  1238469111) },
      { -INT32_C(   399742743),  INT32_C(  2056466528),  INT32_C(   392115366),  INT32_C(  2127694199) },
      UINT8_C( 13) },
    { {  INT32_C(   450691818), -INT32_C(   867477611),  INT32_C(  2009320685),  INT32_C(    90181021) },
      {  INT32_C(   450691818), -INT32_C(   867477611), -INT32_C(  1824241527),  INT32_C(    90181021) },
      UINT8_C(  4) },
    { {  INT32_C(  1146756845),  INT32_C(   892413545), -INT32_C(   153966359),  INT32_C(  1362089737) },
      {  INT32_C(  1146756845),  INT32_C(   890418924), -INT32_C(   153966359),  INT32_C(  1362089737) },
      UINT8_C(  2) },
    { {  INT32_C(    31254235), -INT32_C(  1058402024), -INT32_C(  1144397340), -INT32_C(   887481584) },
      {  INT32_C(    31254235),  INT32_C(  1538715062), -INT32_C(  1144397340), -INT32_C(   838618125) },
      UINT8_C( 10) },
    { { -INT32_C(   256716833), -INT32_C(  1680575814),  INT32_C(  1470861372),  INT32_C(  1314682794) },
      {  INT32_C(   470030127), -INT32_C(  1680575814),  INT32_C(  1470861372),  INT32_C(  1314682794) },
      UINT8_C(  1) },
    { { -INT32_C(   494158992),  INT32_C(   538846864),  INT32_C(  1238005202), -INT32_C(   378005295) },
      { -INT32_C(   494158992),  INT32_C(   538846864),  INT32_C(  1238005202),  INT32_C(  1056804046) },
      UINT8_C(  8) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_mm_loadu_epi32(test_vec[i].a);
    simde__m128i b = simde_mm_loadu_epi32(test_vec[i].b);
    simde__mmask8 r = simde_mm_cmpneq_epi32_mask(a, b);
    simde_assert_equal_mmask8(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i a = simde_test_x86_random_i32x4();
    simde__m128i b = simde_mm_mask_blend_epi32(simde_test_x86_random_mmask8(), a, simde_test_x86_random_i32x4());
    simde__mmask8 r = simde_mm_cmpneq_epi32_mask(a, b);

    simde_test_x86_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_mask_cmpneq_epi32_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k1;
    const int32_t a[4];
    const int32_t b[4];
    const simde__mmask8 r;
  } test_vec[] = {
    { UINT8_C(137),
      {  INT32_C(  1068488737), -INT32_C(  1028292104),  INT32_C(  1121683146),  INT32_C(   651622255) },
      {  INT32_C(  1068488737),  INT32_C(  1517307544),  INT32_C(  1894137714),  INT32_C(   651622255) },
      UINT8_C(  0) },
    { UINT8_C(168),
      { -INT32_C(  1825898786), -INT32_C(  1676020543),  INT32_C(   227772727), -INT32_C(   875558993) },
      { -INT32_C(   686659225), -INT32_C(  1676020543), -INT32_C(   304573196),  INT32_C(   278322738) },
      UINT8_C(  8) },
    { UINT8_C(192),
      { -INT32_C(  1112236381), -INT32_C(   850990278), -INT32_C(   908790279), -INT32_C(   768459840) },
      { -INT32_C(  1112236381), -INT32_C(   850990278), -INT32_C(   908790279), -INT32_C(   768459840) },
      UINT8_C(  0) },
    { UINT8_C( 67),
      { -INT32_C(  1490089375), -INT32_C(  1399052072),  INT32_C(   619207921), -INT32_C(  2045117649) },
      { -INT32_C(  1490089375), -INT32_C(  2049832401),  INT32_C(   619207921), -INT32_C(  2045117649) },
      UINT8_C(  2) },
    { UINT8_C(219),
      {  INT32_C(   436431486), -INT32_C(     8915945),  INT32_C(   855287320), -INT32_C(    34988500) },
      { -INT32_C(   771220992),  INT32_C(  1453711775),  INT32_C(   855287320),  INT32_C(  1909551603) },
      UINT8_C( 11) },
    { UINT8_C(212),
      {  INT32_C(    63500940), -INT32_C(   341188111), -INT32_C(    49621741), -INT32_C(   636024110) },
      {  INT32_C(    63500940), -INT32_C(   342030835), -INT32_C(    49621741), -INT32_C(  1902036990) },
      UINT8_C(  0) },
    { UINT8_C(105),
      {  INT32_C(   977935505),  INT32_C(   286219527),  INT32_C(  1914495323),  INT32_C(  2016016828) },
      {  INT32_C(   977935505),  INT32_C(   286219527), -INT32_C(   390681785), -INT32_C(   900603847) },
      UINT8_C(  8) },
    { UINT8_C(156),
      {  INT32_C(   335086596),  INT32_C(   838095893), -INT32_C(   265637689), -INT32_C(  1507416792) },
      {  INT32_C(   335086596),  INT32_C(   838095893), -INT32_C(  1587786929),  INT32_C(   423450645) },
      UINT8_C( 12) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_mm_loadu_epi32(test_vec[i].a);
    simde__m128i b = simde_mm_loadu_epi32(test_vec[i].b);
    simde__mmask8 r = simde_mm_mask_cmpneq_epi32_mask(test_vec[i].k1, a, b);
    simde_assert_equal_mmask8(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k1 = simde_test_x86_random_mmask8();
    simde__m128i a = simde_test_x86_random_i32x4();
    simde__m128i b = simde_mm_mask_blend_epi32(simde_test_x86_random_mmask8(), a, simde_test_x86_random_i32x4());
    simde__mmask8 r = simde_mm_mask_cmpneq_epi32_mask(k1, a, b);

    simde_test_x86_write_mmask8(2, k1, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x4(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_cmpneq_epu32_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const uint32_t a[4];
    const uint32_t b[4];
    const simde__mmask8 r;
  } test_vec[] = {
    { { UINT32_C(2339515446), UINT32_C(3511853856), UINT32_C(1945715406), UINT32_C(2939265128) },
      { UINT32_C( 678795456), UINT32_C(4118278314), UINT32_C(2768902220), UINT32_C(2348884821) },
      UINT8_C( 15) },
    { { UINT32_C( 393222003), UINT32_C(2883928425), UINT32_C(3658700858), UINT32_C( 580633226) },
      { UINT32_C( 684573495), UINT32_C(1400160826), UINT32_C(3658700858), UINT32_C(2386572315) },
      UINT8_C( 11) },
    { { UINT32_C(4055147952), UINT32_C(3811270538), UINT32_C( 896337522), UINT32_C(1684836257) },
      { UINT32_C( 530486364), UINT32_C(3811270538), UINT32_C( 896337522), UINT32_C(1684836257) },
      UINT8_C(  1) },
    { { UINT32_C( 788315598), UINT32_C(4020297705), UINT32_C(3683702092), UINT32_C(3594056770) },
      { UINT32_C( 788315598), UINT32_C( 522060355), UINT32_C( 188542015), UINT32_C(3594056770) },
      UINT8_C(  6) },
    { { UINT32_C(1487864697), UINT32_C(2040831651), UINT32_C( 582713134), UINT32_C( 246714807) },
      { UINT32_C(1934702705), UINT32_C(2040831651), UINT32_C( 582713134), UINT32_C( 246714807) },
      UINT8_C(  1) },
    { { UINT32_C(3368356906), UINT32_C( 804667056), UINT32_C(2330401017), UINT32_C( 100398541) },
      { UINT32_C(3368356906), UINT32_C(3747979041), UINT32_C(2330401017), UINT32_C(3223899798) },
      UINT8_C( 10) },
    { { UINT32_C( 730499565), UINT32_C(2552543615), UINT32_C(2523246496), UINT32_C( 433941162) },
      { UINT32_C( 730499565), UINT32_C(2552543615), UINT32_C(  27940147), UINT32_C( 433941162) },
      UINT8_C(  4) },
    { { UINT32_C( 510891621), UINT32_C(1790905275), UINT32_C(3675542896), UINT32_C(3349228850) },
      { UINT32_C(2160133991), UINT32_C(1790905275), UINT32_C(3675542896), UINT32_C(4108292751) },
      UINT8_C(  9) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_mm_loadu_epi32(test_vec[i].a);
    simde__m128i b = simde_mm_loadu_epi32(test_vec[i].b);
    simde__mmask8 r = simde_mm_cmpneq_epu32_mask(a, b);
    simde_assert_equal_mmask8(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i a = simde_test_x86_random_u32x4();
    simde__m128i b = simde_mm_mask_blend_epi32(simde_test_x86_random_mmask8(), a, simde_test_x86_random_u32x4());
    simde__mmask8 r = simde_mm_cmpneq_epu32_mask(a, b);

    simde_test_x86_write_u32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_u32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_mask_cmpneq_epu32_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k1;
    const uint32_t a[4];
    const uint32_t b[4];
    const simde__mmask8 r;
  } test_vec[] = {
    { UINT8_C( 82),
      { UINT32_C(3529434131), UINT32_C(1646775886), UINT32_C(1267751337), UINT32_C(3780310816) },
      { UINT32_C(3529434131), UINT32_C(1646775886), UINT32_C(1267751337), UINT32_C(2001941604) },
      UINT8_C(  0) },
    { UINT8_C(177),
      { UINT32_C(1887397449), UINT32_C(1489578440), UINT32_C(3327191412), UINT32_C(2154678474) },
      { UINT32_C(3552034547), UINT32_C(1094965302), UINT32_C(3327191412), UINT32_C(2154678474) },
      UINT8_C(  1) },
    { UINT8_C( 92),
      { UINT32_C(2693119191), UINT32_C(1686763796), UINT32_C( 741102527), UINT32_C(2330599635) },
      { UINT32_C( 912466419), UINT32_C(1686763796), UINT32_C(1164311400), UINT32_C(2330599635) },
      UINT8_C(  4) },
    { UINT8_C( 39),
      { UINT32_C(1646275033), UINT32_C(3132481678), UINT32_C(4158294284), UINT32_C(1981337107) },
      { UINT32_C(3803347460), UINT32_C(3101497938), UINT32_C(  17907807), UINT32_C(1395140217) },
      UINT8_C(  7) },
    { UINT8_C( 72),
      { UINT32_C(1797840309), UINT32_C(1928607128), UINT32_C(1145046828), UINT32_C( 817775998) },
      { UINT32_C(  72028455), UINT32_C(1928607128), UINT32_C(3540041387), UINT32_C(3323744017) },
      UINT8_C(  8) },
    { UINT8_C( 68),
      { UINT32_C( 628737329), UINT32_C(2016257335), UINT32_C(2831002601), UINT32_C( 649716955) },
      { UINT32_C( 768705256), UINT32_C(2016257335), UINT32_C(1823210576), UINT32_C(4105230530) },
      UINT8_C(  4) },
    { UINT8_C( 42),
      { UINT32_C(1188025625), UINT32_C( 183613773), UINT32_C( 451857761), UINT32_C(3298612979) },
      { UINT32_C(1188025625), UINT32_C(4293562708), UINT32_C( 451857761), UINT32_C(3134682529) },
      UINT8_C( 10) },
    { UINT8_C(167),
      { UINT32_C(4066416385), UINT32_C(2411708833), UINT32_C(2003219419), UINT32_C(3094309239) },
      { UINT32_C(4066416385), UINT32_C(2599372482), UINT32_C(2003219419), UINT32_C(3094309239) },
      UINT8_C(  2) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_mm_loadu_epi32(test_vec[i].a);
    simde__m128i b = simde_mm_loadu_epi32(test_vec[i].b);
    simde__mmask8 r = simde_mm_mask_cmpneq_epu32_mask(test_vec[i].k1, a, b);
    simde_assert_equal_mmask8(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k1 = simde_test_x86_random_mmask8();
    simde__m128i a = simde_test_x86_random_u32x4();
    simde__m128i b = simde_mm_mask_blend_epi32(simde_test_x86_random_mmask8(), a, simde_test_x86_random_u32x4());
    simde__mmask8 r = simde_mm_mask_cmpneq_epu32_mask(k1, a, b);

    simde_test_x86_write_mmask8(2, k1, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_u32x4(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_u32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_cmpneq_epi64_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int64_t a[4];
    const int64_t b[4];
    const simde__mmask8 r;
  } test_vec[] = {
    { { -INT64_C( 2395685559586529103), -INT64_C( 3134027570735926721) },
      { -INT64_C( 5893510356011409085),  INT64_C( 2190428841884919221) },
      UINT8_C(  3) },
    { {  INT64_C( 4450509753596267188),  INT64_C( 6943029722049953124) },
      {  INT64_C( 2536543627709958002),  INT64_C( 6943029722049953124) },
      UINT8_C(  1) },
    { { -INT64_C(  934144298817686975),  INT64_C( 4687986054940205060) },
      {  INT64_C( 1624499570496933120),  INT64_C( 4687986054940205060) },
      UINT8_C(  1) },
    { {  INT64_C( 4459366402878805149),  INT64_C( 1990301376776208268) },
      {  INT64_C( 4074334652475325238),  INT64_C( 1990301376776208268) },
      UINT8_C(  1) },
    { { -INT64_C( 6737592695842783207), -INT64_C(  636894597407040006) },
      { -INT64_C( 6737592695842783207),  INT64_C( 2818018671853296476) },
      UINT8_C(  2) },
    { { -INT64_C( 5233002883489654238),  INT64_C( 4342714117228024531) },
      { -INT64_C( 5233002883489654238),  INT64_C( 4342714117228024531) },
      UINT8_C(  0) },
    { {  INT64_C(  300530274922025397), -INT64_C( 1532705406965561051) },
      {  INT64_C(  300530274922025397), -INT64_C( 1532705406965561051) },
      UINT8_C(  0) },
    { { -INT64_C( 8878351628961443598), -INT64_C( 1278463652121126335) },
      {  INT64_C( 5449155417840321052),  INT64_C( 2368901301691889176) },
      UINT8_C(  3) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_mm_loadu_epi64(test_vec[i].a);
    simde__m128i b = simde_mm_loadu_epi64(test_vec[i].b);
    simde__mmask8 r = simde_mm_cmpneq_epi64_mask(a, b);
    simde_assert_equal_mmask8(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i a = simde_test_x86_random_i64x2();
    simde__m128i b = simde_mm_mask_blend_epi64(simde_test_x86_random_mmask8(), a, simde_test_x86_random_i64x2());
    simde__mmask8 r = simde_mm_cmpneq_epi64_mask(a, b);

    simde_test_x86_write_i64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_mask_cmpneq_epi64_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k1;
    const int64_t a[4];
    const int64_t b[4];
    const simde__mmask8 r;
  } test_vec[] = {
    { UINT8_C(158),
      { -INT64_C( 1592125996090240060),  INT64_C( 3342237076986133407) },
      { -INT64_C( 1592125996090240060),  INT64_C( 3342237076986133407) },
      UINT8_C(  0) },
    { UINT8_C( 65),
      {  INT64_C( 1128576297155641542),  INT64_C( 4044621420906517090) },
      { -INT64_C( 4626274607261234607),  INT64_C( 4044621420906517090) },
      UINT8_C(  1) },
    { UINT8_C(117),
      { -INT64_C( 4167982818674628883), -INT64_C( 1654939679374907107) },
      {  INT64_C( 6773276987916339697), -INT64_C( 1654939679374907107) },
      UINT8_C(  1) },
    { UINT8_C(210),
      {  INT64_C( 7011058131223147323),  INT64_C( 7735157032161602950) },
      { -INT64_C( 2881527237705801334), -INT64_C( 7289730897741366744) },
      UINT8_C(  2) },
    { UINT8_C(  0),
      { -INT64_C( 7658424242303116803),  INT64_C( 7464694914884963934) },
      { -INT64_C( 7191594749958367882),  INT64_C( 7464694914884963934) },
      UINT8_C(  0) },
    { UINT8_C(116),
      {  INT64_C( 8302563008153091186),  INT64_C( 4811487179498893656) },
      {  INT64_C( 8302563008153091186), -INT64_C( 2902708067688760298) },
      UINT8_C(  0) },
    { UINT8_C(250),
      { -INT64_C( 2023536238105194751), -INT64_C( 2730580753305238813) },
      { -INT64_C( 2023536238105194751),  INT64_C( 1211400198052657182) },
      UINT8_C(  2) },
    { UINT8_C(107),
      { -INT64_C( 1065590353167428279),  INT64_C( 1887148247034133483) },
      { -INT64_C( 5106215605561347561), -INT64_C( 8276685637411916824) },
      UINT8_C(  3) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_mm_loadu_epi64(test_vec[i].a);
    simde__m128i b = simde_mm_loadu_epi64(test_vec[i].b);
    simde__mmask8 r = simde_mm_mask_cmpneq_epi64_mask(test_vec[i].k1, a, b);
    simde_assert_equal_mmask8(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k1 = simde_test_x86_random_mmask8();
    simde__m128i a = simde_test_x86_random_i64x2();
    simde__m128i b = simde_mm_mask_blend_epi64(simde_test_x86_random_mmask8(), a, simde_test_x86_random_i64x2());
    simde__mmask8 r = simde_mm_mask_cmpneq_epi64_mask(k1, a, b);

    simde_test_x86_write_mmask8(2, k1, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i64x2(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_cmpneq_epu64_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const uint64_t a[4];
    const uint64_t b[4];
    const simde__mmask8 r;
  } test_vec[] = {
    { { UINT64_C( 8192554557433954435), UINT64_C(11194507111956920516) },
      { UINT64_C( 8192554557433954435), UINT64_C(11194507111956920516) },
      UINT8_C(  0) },
    { { UINT64_C( 6926981152710588049), UINT64_C(  221208262895756379) },
      { UINT64_C( 6305611008499841907), UINT64_C(16032591800372074214) },
      UINT8_C(  3) },
    { { UINT64_C(13947985996387924898), UINT64_C(15696034117424565628) },
      { UINT64_C(13947985996387924898), UINT64_C( 5864482414301360130) },
      UINT8_C(  2) },
    { { UINT64_C(16637753985556252470), UINT64_C(12114856824361207213) },
      { UINT64_C(16637753985556252470), UINT64_C(12114856824361207213) },
      UINT8_C(  0) },
    { { UINT64_C(12069553967307521445), UINT64_C(16596441715800256367) },
      { UINT64_C( 6043267580424852514), UINT64_C(16596441715800256367) },
      UINT8_C(  1) },
    { { UINT64_C(16682400882115197032), UINT64_C( 8508599194069930122) },
      { UINT64_C(16682400882115197032), UINT64_C( 5681192957810524882) },
      UINT8_C(  2) },
    { { UINT64_C( 8453394922095403514), UINT64_C(17242258045645832755) },
      { UINT64_C( 5517159178812375068), UINT64_C(17242258045645832755) },
      UINT8_C(  1) },
    { { UINT64_C(14982697015241489725), UINT64_C(14302610009214008978) },
      { UINT64_C(14982697015241489725), UINT64_C( 3148409690873808719) },
      UINT8_C(  2) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_mm_loadu_epi64(test_vec[i].a);
    simde__m128i b = simde_mm_loadu_epi64(test_vec[i].b);
    simde__mmask8 r = simde_mm_cmpneq_epu64_mask(a, b);
    simde_assert_equal_mmask8(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i a = simde_test_x86_random_u64x2();
    simde__m128i b = simde_mm_mask_blend_epi64(simde_test_x86_random_mmask8(), a, simde_test_x86_random_u64x2());
    simde__mmask8 r = simde_mm_cmpneq_epu64_mask(a, b);

    simde_test_x86_write_u64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_u64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_mask_cmpneq_epu64_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k1;
    const uint64_t a[4];
    const uint64_t b[4];
    const simde__mmask8 r;
  } test_vec[] = {
    { UINT8_C(119),
      { UINT64_C( 2562624049221087205), UINT64_C( 3341020412631291813) },
      { UINT64_C( 2562624049221087205), UINT64_C( 5806142034820218987) },
      UINT8_C(  2) },
    { UINT8_C( 69),
      { UINT64_C( 1750262947806559522), UINT64_C( 2510147485344245584) },
      { UINT64_C( 1750262947806559522), UINT64_C( 2510147485344245584) },
      UINT8_C(  0) },
    { UINT8_C(166),
      { UINT64_C(12534685329645686018), UINT64_C(12184034610476403410) },
      { UINT64_C(12534685329645686018), UINT64_C(12184034610476403410) },
      UINT8_C(  0) },
    { UINT8_C(133),
      { UINT64_C( 6732174296479313327), UINT64_C(15296287027956242724) },
      { UINT64_C( 6732174296479313327), UINT64_C(13842346793370496739) },
      UINT8_C(  0) },
    { UINT8_C(195),
      { UINT64_C(  660169092870696291), UINT64_C(16941336737288629151) },
      { UINT64_C(  660169092870696291), UINT64_C(16941336737288629151) },
      UINT8_C(  0) },
    { UINT8_C( 87),
      { UINT64_C(  381498267298143991), UINT64_C(18017410305297828672) },
      { UINT64_C(  381498267298143991), UINT64_C(18017410305297828672) },
      UINT8_C(  0) },
    { UINT8_C( 91),
      { UINT64_C( 7027855829276925936), UINT64_C( 6500397098080714320) },
      { UINT64_C( 2708750386108858614), UINT64_C( 3652268945294979507) },
      UINT8_C(  3) },
    { UINT8_C(101),
      { UINT64_C( 3581394273848441710), UINT64_C(18355604207257349125) },
      { UINT64_C( 3581394273848441710), UINT64_C(  253344612200506224) },
      UINT8_C(  0) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_mm_loadu_epi64(test_vec[i].a);
    simde__m128i b = simde_mm_loadu_epi64(test_vec[i].b);
    simde__mmask8 r = simde_mm_mask_cmpneq_epu64_mask(test_vec[i].k1, a, b);
    simde_assert_equal_mmask8(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k1 = simde_test_x86_random_mmask8();
    simde__m128i a = simde_test_x86_random_u64x2();
    simde__m128i b = simde_mm_mask_blend_epi64(simde_test_x86_random_mmask8(), a, simde_test_x86_random_u64x2());
    simde__mmask8 r = simde_mm_mask_cmpneq_epu64_mask(k1, a, b);

    simde_test_x86_write_mmask8(2, k1, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_u64x2(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_u64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_cmpneq_epi8_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int8_t a[32];
    const int8_t b[32];
    const simde__mmask32 r;
  } test_vec[] = {
    { { -INT8_C(  50),  INT8_C(  42), -INT8_C( 104),  INT8_C(  30),  INT8_C(  19), -INT8_C(   9),  INT8_C(  52),  INT8_C( 116),
        -INT8_C(  17),  INT8_C(  27),  INT8_C( 120), -INT8_C(  58), -INT8_C(  74),  INT8_C(  37), -INT8_C(  41),  INT8_C(  83),
        -INT8_C(  63),  INT8_C( 104),  INT8_C(  49), -INT8_C(  93), -INT8_C( 124), -INT8_C( 121), -INT8_C(  37),  INT8_C( 106),
         INT8_C( 100),  INT8_C(  52), -INT8_C(  52),  INT8_C(  73),  INT8_C(  71), -INT8_C( 106),  INT8_C(  10),  INT8_C(  21) },
      { -INT8_C(  50),  INT8_C(  42), -INT8_C( 104),  INT8_C(  30),  INT8_C(  19),  INT8_C( 104),  INT8_C(  52), -INT8_C( 119),
        -INT8_C(  17), -INT8_C(  64),  INT8_C( 120),  INT8_C(  57), -INT8_C(  74),  INT8_C(  39), -INT8_C( 116), -INT8_C(  89),
        -INT8_C(  63),  INT8_C( 104),  INT8_C(  74), -INT8_C(  93),  INT8_C(  69),  INT8_C(  37),  INT8_C( 126),  INT8_C( 106),
         INT8_C( 100),  INT8_C(  74), -INT8_C(  52), -INT8_C(  95), -INT8_C(  32), -INT8_C(   2),  INT8_C(  10),  INT8_C(  21) },
      UINT32_C( 980740768) },
    { {  INT8_C(  82), -INT8_C(  67), -INT8_C(  60), -INT8_C(  43),  INT8_C( 125),  INT8_C(  19),  INT8_C(  15),  INT8_C(  99),
         INT8_C(  58), -INT8_C( 101),  INT8_C(  10), -INT8_C(  54),  INT8_C(  89),  INT8_C(  85), -INT8_C(  35), -INT8_C(  97),
         INT8_C( 122),  INT8_C(  91),  INT8_C(  73), -INT8_C(  44), -INT8_C(  91),  INT8_C(  60),  INT8_C( 117), -INT8_C( 123),
         INT8_C(  58),  INT8_C(  43),  INT8_C(  38), -INT8_C(  37),  INT8_C(  21), -INT8_C( 102),  INT8_C(  21),  INT8_C( 103) },
      {  INT8_C(  82), -INT8_C(  39), -INT8_C(  60), -INT8_C(  43),  INT8_C( 125),  INT8_C(  76),  INT8_C(  56),  INT8_C(  99),
        -INT8_C(  25), -INT8_C( 101),  INT8_C(  10), -INT8_C(  54),  INT8_C(  89),  INT8_C(  85), -INT8_C(  32), -INT8_C(  97),
         INT8_C( 122),  INT8_C(  41),  INT8_C(  73), -INT8_C(  44), -INT8_C(  91),  INT8_C(  60),  INT8_C(  85), -INT8_C( 123),
        -INT8_C( 121),  INT8_C( 123),  INT8_C( 123), -INT8_C(  37),  INT8_C(  22), -INT8_C( 102),  INT8_C(   4),  INT8_C( 103) },
      UINT32_C(1463959906) },
    { { -INT8_C( 115),  INT8_C( 123),  INT8_C( 126),  INT8_C( 116), -INT8_C(  66),  INT8_C( 112), -INT8_C(  75),  INT8_C(  86),
         INT8_C(  63), -INT8_C( 107),  INT8_C( 104),  INT8_C( 105), -INT8_C(  66),  INT8_C(  79),  INT8_C(  57),  INT8_C(  36),
        -INT8_C(  86), -INT8_C( 113), -INT8_C(  60),  INT8_C(  49),  INT8_C(  10),  INT8_C(  63), -INT8_C(  50),  INT8_C(  32),
        -INT8_C(  49), -INT8_C(  46), -INT8_C( 114),  INT8_C(  57),  INT8_C(  19), -INT8_C(  48), -INT8_C( 112), -INT8_C(  96) },
      {  INT8_C(  75),  INT8_C( 123),  INT8_C(  20),  INT8_C(   9), -INT8_C(  66), -INT8_C(  54),  INT8_C(  95), -INT8_C(  66),
         INT8_C(  63), -INT8_C(  56),  INT8_C( 104),  INT8_C(  30),  INT8_C(  23),  INT8_C(  79),  INT8_C(  66),  INT8_C(  36),
        -INT8_C(  86),  INT8_C(   6), -INT8_C(  13), -INT8_C(   6),  INT8_C(  10),  INT8_C(  63),  INT8_C(  27),  INT8_C(  20),
        -INT8_C(  49), -INT8_C(  46),  INT8_C(  78), -INT8_C(  90),  INT8_C(  19), -INT8_C(  34),  INT8_C(  70), -INT8_C(  96) },
      UINT32_C(1825463021) },
    { {  INT8_C(  36),  INT8_C(  46),  INT8_C(  42), -INT8_C( 124), -INT8_C(  10),  INT8_C(  82), -INT8_C(  94),  INT8_C(  13),
        -INT8_C(  77), -INT8_C(  28), -INT8_C(  50), -INT8_C(  93), -INT8_C(  22), -INT8_C(  63), -INT8_C(  99),  INT8_C(  47),
        -INT8_C( 126), -INT8_C(  72),  INT8_C(  67),  INT8_C(  21),  INT8_C(  97), -INT8_C( 111), -INT8_C(  69), -INT8_C(  37),
         INT8_C( 112),  INT8_C(   1), -INT8_C(  96),  INT8_C(  93),  INT8_C(  92),  INT8_C( 110), -INT8_C(  54),      INT8_MIN },
      {  INT8_C(  36),  INT8_C(  46),  INT8_C(   4), -INT8_C( 124), -INT8_C(  10),  INT8_C(  82), -INT8_C(  94),  INT8_C(  13),
        -INT8_C( 118), -INT8_C(  28), -INT8_C( 100), -INT8_C(  93), -INT8_C(  22),  INT8_C(  58), -INT8_C(  93),  INT8_C(  47),
        -INT8_C( 126), -INT8_C(  72), -INT8_C(  57),  INT8_C(  84),  INT8_C(  97), -INT8_C( 125),  INT8_C(  47), -INT8_C(  37),
        -INT8_C( 124), -INT8_C(  49), -INT8_C(  96), -INT8_C(  32),  INT8_C(  92),  INT8_C( 110),  INT8_C(  97),      INT8_MIN },
      UINT32_C(1265394948) },
    { {  INT8_C(  12),  INT8_C(  12),  INT8_C(  68), -INT8_C( 106),  INT8_C( 122), -INT8_C(  31),  INT8_C(  11), -INT8_C(  87),
         INT8_C(  27), -INT8_C(  82),  INT8_C(  91),  INT8_C(  13), -INT8_C( 107),  INT8_C(  35),  INT8_C(  97),  INT8_C(  14),
        -INT8_C(  90), -INT8_C( 112), -INT8_C(  10),  INT8_C(  42),  INT8_C(  95),  INT8_C(  60),  INT8_C(  11), -INT8_C(  99),
         INT8_C(  76),  INT8_C( 108),  INT8_C( 119),  INT8_C(  81), -INT8_C(  47), -INT8_C(  29), -INT8_C( 100), -INT8_C(  35) },
      {  INT8_C(  12), -INT8_C(  32),  INT8_C( 116),  INT8_C( 105), -INT8_C(  63), -INT8_C(  31),  INT8_C(  11), -INT8_C(  87),
         INT8_C(  27), -INT8_C(  82), -INT8_C(  22), -INT8_C(  61), -INT8_C( 111),  INT8_C(  75), -INT8_C(  47),  INT8_C(  55),
        -INT8_C(  90), -INT8_C( 112),  INT8_C(  98),  INT8_C(  59),  INT8_C(  95),  INT8_C(  60),  INT8_C(  11),  INT8_C(  80),
        -INT8_C(  39),  INT8_C(  79), -INT8_C(  95), -INT8_C(  86),  INT8_C(  51), -INT8_C(  29), -INT8_C( 120),  INT8_C(  34) },
      UINT32_C(3750558750) },
    { {  INT8_C( 123), -INT8_C(  97), -INT8_C(  68), -INT8_C(  88),  INT8_C(  13), -INT8_C(  90),  INT8_C( 107), -INT8_C(  97),
        -INT8_C(  15),  INT8_C(  60), -INT8_C(  42), -INT8_C(  51),  INT8_C(   4),  INT8_C(  56),  INT8_C(   9),  INT8_C(   8),
        -INT8_C(  91), -INT8_C(  31),  INT8_C(  88),  INT8_C( 126),  INT8_C(  49), -INT8_C(   6),  INT8_C(  41),  INT8_C( 100),
         INT8_C(  55), -INT8_C(  79), -INT8_C( 122),  INT8_C(  85), -INT8_C(  83),  INT8_C(  18),  INT8_C(  53),  INT8_C(  40) },
      {  INT8_C( 123), -INT8_C(  15), -INT8_C(  68), -INT8_C(  65),  INT8_C(  13), -INT8_C(  90),  INT8_C( 107), -INT8_C( 120),
        -INT8_C(  15),  INT8_C(  60), -INT8_C(  42), -INT8_C(  51),  INT8_C( 109),  INT8_C(  56),  INT8_C(   9),  INT8_C(   8),
         INT8_C(  64), -INT8_C(  35), -INT8_C( 111),  INT8_C( 113), -INT8_C(  41), -INT8_C(   6), -INT8_C(  43),  INT8_C(  14),
         INT8_C( 107), -INT8_C(  79), -INT8_C( 122),  INT8_C(  85), -INT8_C(  83), -INT8_C( 103),  INT8_C(  53),  INT8_C(  40) },
      UINT32_C( 568266890) },
    { {  INT8_C(  76),  INT8_C(  61), -INT8_C(  87), -INT8_C(  59),  INT8_C( 113), -INT8_C(   1),  INT8_C(  65), -INT8_C(  34),
         INT8_C(  94), -INT8_C(  58), -INT8_C(  15), -INT8_C(  97), -INT8_C(  93), -INT8_C( 126),  INT8_C(  16),  INT8_C( 122),
         INT8_C(  60), -INT8_C(  26), -INT8_C( 120), -INT8_C(  89),  INT8_C(  66), -INT8_C(  20), -INT8_C(  65), -INT8_C(  80),
        -INT8_C( 123), -INT8_C(   1), -INT8_C(  48),  INT8_C(  15),  INT8_C(  15), -INT8_C(  81),  INT8_C(  48),  INT8_C(  92) },
      {  INT8_C(  76), -INT8_C(  38), -INT8_C(  87),  INT8_C(  94), -INT8_C(  39), -INT8_C(   1),  INT8_C(  60), -INT8_C(  34),
         INT8_C(  40), -INT8_C(  58), -INT8_C(  41), -INT8_C(  53), -INT8_C(  81), -INT8_C( 126),  INT8_C(  69), -INT8_C(  21),
         INT8_C(  60), -INT8_C(  50), -INT8_C( 120),  INT8_C(  15),  INT8_C(  66), -INT8_C(  20), -INT8_C(  65),  INT8_C(  64),
         INT8_C(  80), -INT8_C( 112), -INT8_C(  48),  INT8_C(  15),  INT8_C(  64),      INT8_MIN,  INT8_C(  48),  INT8_C(  92) },
      UINT32_C( 864738650) },
    { {  INT8_C(  63), -INT8_C(  57),  INT8_C( 107),  INT8_C( 104), -INT8_C(  12),  INT8_C(  66),  INT8_C(  51), -INT8_C(  92),
         INT8_C(  42),  INT8_C( 121), -INT8_C( 113), -INT8_C(   9),  INT8_C(  71),  INT8_C(  34),  INT8_C(   7),  INT8_C(   1),
         INT8_C( 115), -INT8_C(  57),  INT8_C(  65), -INT8_C(  60),  INT8_C(  87), -INT8_C( 111),  INT8_C(  36), -INT8_C( 105),
         INT8_C(  17), -INT8_C(  32), -INT8_C(  60),  INT8_C( 107), -INT8_C(  67),  INT8_C(  78), -INT8_C(  98), -INT8_C(   4) },
      {  INT8_C(  63), -INT8_C(  57),  INT8_C( 107),  INT8_C( 104),  INT8_C(  76),  INT8_C(  66), -INT8_C(  82), -INT8_C(  92),
         INT8_C(  17),  INT8_C( 121), -INT8_C( 113),  INT8_C(  88),  INT8_C(  95),  INT8_C( 117),  INT8_C(   7), -INT8_C(  45),
         INT8_C(  60), -INT8_C(  57), -INT8_C( 105), -INT8_C( 109),  INT8_C(  44), -INT8_C( 111),  INT8_C(  43), -INT8_C( 105),
        -INT8_C( 101), -INT8_C(  32), -INT8_C(  88),  INT8_C(  88),  INT8_C(  61),  INT8_C(  78), -INT8_C(  98),  INT8_C(  83) },
      UINT32_C(2640165200) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256i a = simde_mm256_loadu_epi8(test_vec[i].a);
    simde__m256i b = simde_mm256_loadu_epi8(test_vec[i].b);
    simde__mmask32 r = simde_mm256_cmpneq_epi8_mask(a, b);
    simde_assert_equal_mmask32(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m256i a = simde_test_x86_random_i8x32();
    simde__m256i b = simde_mm256_mask_blend_epi8(simde_test_x86_random_mmask32(), a, simde_test_x86_random_i8x32());
    simde__mmask32 r = simde_mm256_cmpneq_epi8_mask(a, b);

    simde_test_x86_write_i8x32(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i8x32(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_mask_cmpneq_epi8_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask32 k1;
    const int8_t a[32];
    const int8_t b[32];
    const simde__mmask32 r;
  } test_vec[] = {
    { UINT32_C(2633305875),
      {  INT8_C(  94),  INT8_C(  57),  INT8_C( 114), -INT8_C( 115), -INT8_C(  89),  INT8_C(  68), -INT8_C(  54), -INT8_C(  15),
        -INT8_C( 118),  INT8_C(   4), -INT8_C(  40), -INT8_C(  27),  INT8_C(  58),  INT8_C(  16),  INT8_C(   7), -INT8_C( 125),
        -INT8_C( 127),  INT8_C(  11), -INT8_C(  48), -INT8_C(  10), -INT8_C(  12), -INT8_C(  67),  INT8_C(  14),  INT8_C(  64),
        -INT8_C(  29),  INT8_C(   9),  INT8_C(  22), -INT8_C(  10),  INT8_C(  24),  INT8_C(  11), -INT8_C( 109),  INT8_C( 119) },
      {  INT8_C(  94),  INT8_C(   5),  INT8_C(   4), -INT8_C(  20), -INT8_C(  89),  INT8_C(  68), -INT8_C(  54), -INT8_C(  45),
        -INT8_C(  46), -INT8_C(  75), -INT8_C(  72), -INT8_C(  27),  INT8_C(  58), -INT8_C(  64), -INT8_C( 113),  INT8_C(  70),
        -INT8_C( 127),  INT8_C(  95), -INT8_C(  48), -INT8_C(  10),  INT8_C(  28), -INT8_C(  67),  INT8_C(   0),  INT8_C(  64),
        -INT8_C(  29),  INT8_C(   9),  INT8_C(  22),  INT8_C( 108),  INT8_C(  34),  INT8_C(  11), -INT8_C(  29),  INT8_C( 102) },
      UINT32_C(2555381506) },
    { UINT32_C(2292920245),
      { -INT8_C(  28),  INT8_C( 100), -INT8_C( 108), -INT8_C(  87),  INT8_C(  36),  INT8_C(  36), -INT8_C(  17), -INT8_C(  17),
        -INT8_C( 125),  INT8_C(  43), -INT8_C(  81), -INT8_C(  96),  INT8_C( 118), -INT8_C(  81), -INT8_C(  96), -INT8_C(  54),
        -INT8_C(  58), -INT8_C( 106),  INT8_C(  54), -INT8_C(  24),  INT8_C(  32),  INT8_C(  26),  INT8_C(  78), -INT8_C(  82),
         INT8_C(   1), -INT8_C(  95), -INT8_C( 122), -INT8_C(  73), -INT8_C(  48),  INT8_C(  50),  INT8_C(  63), -INT8_C(  75) },
      { -INT8_C( 106),  INT8_C( 100),  INT8_C(  94), -INT8_C(  87), -INT8_C(   9),  INT8_C(  36), -INT8_C(  87),  INT8_C( 123),
        -INT8_C( 125),  INT8_C(  89), -INT8_C(  81), -INT8_C(  17),  INT8_C( 118), -INT8_C(  81), -INT8_C(  96), -INT8_C(  50),
        -INT8_C(  58), -INT8_C( 106),  INT8_C(  54),  INT8_C( 113),  INT8_C(  32),  INT8_C(   5),  INT8_C(  78), -INT8_C(  82),
         INT8_C(   1), -INT8_C(  95), -INT8_C(  62),  INT8_C( 118), -INT8_C(  48),  INT8_C(  50),  INT8_C(  43),  INT8_C( 110) },
      UINT32_C(2284325525) },
    { UINT32_C(1363661528),
      {  INT8_C(  43),  INT8_C(  98),  INT8_C(  65),  INT8_C(  51),  INT8_C(  29), -INT8_C(   6),  INT8_C(   2),  INT8_C( 111),
        -INT8_C(  22), -INT8_C(  72), -INT8_C(  32), -INT8_C(  12), -INT8_C(  67),  INT8_C(   0),  INT8_C(   0),  INT8_C(  99),
        -INT8_C(  89), -INT8_C(  62), -INT8_C(  38),      INT8_MAX, -INT8_C(  60),  INT8_C(   5), -INT8_C(  18), -INT8_C( 103),
        -INT8_C( 113),  INT8_C(  22),  INT8_C( 101),  INT8_C( 103), -INT8_C(  24), -INT8_C(  83), -INT8_C(  71),  INT8_C(  19) },
      {  INT8_C(  43),  INT8_C(  98),  INT8_C(  71),  INT8_C(  45),  INT8_C(  29),  INT8_C(  73),  INT8_C(   2), -INT8_C(  33),
         INT8_C(   1),  INT8_C( 124), -INT8_C(  32), -INT8_C(  65), -INT8_C(  67), -INT8_C(  45),  INT8_C(  34),  INT8_C(  36),
        -INT8_C(  89), -INT8_C(   4), -INT8_C(  38),      INT8_MAX, -INT8_C(  60),  INT8_C(   5), -INT8_C(  13), -INT8_C( 103),
        -INT8_C( 113),  INT8_C(  22),  INT8_C( 101),  INT8_C( 103), -INT8_C(  24), -INT8_C(  78), -INT8_C(  71),  INT8_C(  21) },
      UINT32_C(   4375176) },
    { UINT32_C( 897572404),
      {  INT8_C(  90),  INT8_C(  83), -INT8_C(  12), -INT8_C(  41),  INT8_C(  38),  INT8_C(  23), -INT8_C(   5), -INT8_C(  68),
         INT8_C(  19), -INT8_C(  97),  INT8_C(  22),  INT8_C(  21),  INT8_C(  48),  INT8_C(   9), -INT8_C(  89), -INT8_C(  40),
         INT8_C(  98), -INT8_C(  96),  INT8_C( 105),  INT8_C( 103),  INT8_C(  82),  INT8_C(  13),  INT8_C( 124), -INT8_C(   2),
        -INT8_C(   8), -INT8_C(  66), -INT8_C(  98),  INT8_C(  44), -INT8_C( 100),  INT8_C(  30),  INT8_C(  97), -INT8_C(   9) },
      {  INT8_C( 113),  INT8_C(  86), -INT8_C(  12), -INT8_C(  41),  INT8_C(  38),  INT8_C(  23),  INT8_C(  84),      INT8_MIN,
         INT8_C(  19),  INT8_C( 106),  INT8_C(  22), -INT8_C( 103),  INT8_C( 116),  INT8_C(   9),  INT8_C( 114), -INT8_C(  42),
         INT8_C(  98), -INT8_C(  37),  INT8_C( 105),  INT8_C( 103), -INT8_C(  24), -INT8_C(  70),  INT8_C(  45), -INT8_C(  32),
        -INT8_C(   8), -INT8_C(  66), -INT8_C(  98),  INT8_C(  44), -INT8_C(  23),  INT8_C( 109),  INT8_C(  97), -INT8_C(   9) },
      UINT32_C( 812833280) },
    { UINT32_C( 229721764),
      { -INT8_C(  80),  INT8_C(  71), -INT8_C(  89),  INT8_C(  36), -INT8_C( 124),  INT8_C(  25), -INT8_C(   6),  INT8_C(  97),
        -INT8_C(  12),  INT8_C(  56), -INT8_C( 112), -INT8_C(  36), -INT8_C(  14), -INT8_C(  67), -INT8_C(  68),  INT8_C( 106),
        -INT8_C( 120), -INT8_C(  56),      INT8_MAX,  INT8_C( 114),  INT8_C(  53), -INT8_C( 117), -INT8_C(  52), -INT8_C(   7),
         INT8_C( 102), -INT8_C(  66),  INT8_C(  41),  INT8_C(  10),  INT8_C(   4), -INT8_C(  38),  INT8_C(  24), -INT8_C(  75) },
      {  INT8_C(  33), -INT8_C(  65), -INT8_C(  89), -INT8_C(  91), -INT8_C(  40), -INT8_C(  44), -INT8_C(   6), -INT8_C(  52),
        -INT8_C(  12),  INT8_C(  56), -INT8_C(  88), -INT8_C(   2), -INT8_C(  14),  INT8_C( 100),  INT8_C( 104),  INT8_C( 106),
         INT8_C(  44), -INT8_C(  56),  INT8_C(  78),  INT8_C( 114),  INT8_C(  53),  INT8_C(  26), -INT8_C(  52), -INT8_C(   7),
        -INT8_C(  39), -INT8_C( 124),  INT8_C(  41),  INT8_C(  10),  INT8_C(  94), -INT8_C(  38),  INT8_C(  24),      INT8_MIN },
      UINT32_C(  18957472) },
    { UINT32_C(1281305664),
      { -INT8_C(  62),  INT8_C(   7),  INT8_C(  74),  INT8_C(  22),  INT8_C( 107), -INT8_C(  78), -INT8_C(  14), -INT8_C( 105),
        -INT8_C( 102),  INT8_C(  64), -INT8_C(   8),  INT8_C(  14),  INT8_C(  90),  INT8_C(  83), -INT8_C(  25),  INT8_C(  51),
        -INT8_C(  41), -INT8_C(  53),  INT8_C(  17),  INT8_C(  53), -INT8_C(  57), -INT8_C(  93), -INT8_C(  75), -INT8_C( 126),
         INT8_C(  15), -INT8_C(  37),  INT8_C(  21),  INT8_C(  79),  INT8_C(   7),  INT8_C( 116), -INT8_C( 101), -INT8_C(  55) },
      { -INT8_C(  62),  INT8_C(   7), -INT8_C(  33),  INT8_C(  22), -INT8_C( 104), -INT8_C(  47), -INT8_C(  14), -INT8_C( 105),
        -INT8_C( 102),  INT8_C( 118),  INT8_C(  64),  INT8_C(  14), -INT8_C(  55),  INT8_C(  83), -INT8_C(  25),  INT8_C(  51),
        -INT8_C(  13), -INT8_C(  53),  INT8_C(  17), -INT8_C(  69), -INT8_C(  57), -INT8_C( 117), -INT8_C(  75), -INT8_C( 126),
         INT8_C(  15), -INT8_C(  37), -INT8_C(  77),  INT8_C( 109),  INT8_C(   7),  INT8_C( 116),  INT8_C(  54),  INT8_C(  67) },
      UINT32_C(1275659264) },
    { UINT32_C(4194215911),
      {  INT8_C(  29),  INT8_C(  63),  INT8_C( 101), -INT8_C(  26),  INT8_C( 103),  INT8_C(   4), -INT8_C( 122),  INT8_C(  90),
        -INT8_C(  75),  INT8_C(  91),  INT8_C(  21),  INT8_C(   9), -INT8_C(  26),  INT8_C(  83),  INT8_C( 108),  INT8_C(  76),
        -INT8_C(  90),  INT8_C(  31), -INT8_C(  71),  INT8_C( 109),  INT8_C( 110), -INT8_C(  16), -INT8_C(  80), -INT8_C(  94),
         INT8_C(   6), -INT8_C(  38),  INT8_C( 110), -INT8_C(  19), -INT8_C( 127),  INT8_C( 108), -INT8_C(  26), -INT8_C(  98) },
      { -INT8_C(  85),  INT8_C(  75), -INT8_C( 124), -INT8_C(  26),  INT8_C( 103),  INT8_C(  10),  INT8_C( 109),  INT8_C(  90),
        -INT8_C(  75), -INT8_C( 126),  INT8_C(  14),  INT8_C(   9), -INT8_C(  43),  INT8_C(  83),  INT8_C( 108),  INT8_C(  76),
        -INT8_C(  90),  INT8_C(  82), -INT8_C(  71),  INT8_C( 109),  INT8_C( 110), -INT8_C(  16), -INT8_C(  86), -INT8_C(  94),
         INT8_C( 115),  INT8_C(  24),  INT8_C(  53), -INT8_C(  19), -INT8_C( 124),  INT8_C(  28), -INT8_C(  26),  INT8_C(  48) },
      UINT32_C(2973894247) },
    { UINT32_C(2260512544),
      {  INT8_C(  50), -INT8_C(  54), -INT8_C(  46),  INT8_C(   7),  INT8_C(  69),  INT8_C( 106), -INT8_C( 125), -INT8_C(  33),
        -INT8_C(  68),  INT8_C( 108), -INT8_C(  25), -INT8_C(   2),  INT8_C(   5), -INT8_C( 111),  INT8_C(  70),  INT8_C( 121),
        -INT8_C(  87),  INT8_C( 124),  INT8_C( 109),  INT8_C(  45), -INT8_C( 104),  INT8_C(   0),  INT8_C(  93), -INT8_C(   1),
         INT8_C(  22), -INT8_C(  96), -INT8_C(  73),  INT8_C(  55),  INT8_C(  79),  INT8_C( 115), -INT8_C(  67), -INT8_C( 127) },
      {  INT8_C(  62), -INT8_C(  54), -INT8_C( 119), -INT8_C( 125), -INT8_C(   7),  INT8_C(  12),  INT8_C(  98), -INT8_C(  74),
        -INT8_C(  68),  INT8_C( 108), -INT8_C(  25),  INT8_C( 125),  INT8_C(   5), -INT8_C( 111),  INT8_C(  70),  INT8_C( 121),
        -INT8_C(  87),  INT8_C( 100),  INT8_C( 109),  INT8_C(  15),  INT8_C( 100),  INT8_C(  14),  INT8_C(  14),  INT8_C( 122),
        -INT8_C(  82), -INT8_C(  59), -INT8_C(  79),  INT8_C(  55),  INT8_C(  57),  INT8_C( 110),      INT8_MAX,  INT8_C( 119) },
      UINT32_C(2260207648) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256i a = simde_mm256_loadu_epi8(test_vec[i].a);
    simde__m256i b = simde_mm256_loadu_epi8(test_vec[i].b);
    simde__mmask32 r = simde_mm256_mask_cmpneq_epi8_mask(test_vec[i].k1, a, b);
    simde_assert_equal_mmask32(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask32 k1 = simde_test_x86_random_mmask32();
    simde__m256i a = simde_test_x86_random_i8x32();
    simde__m256i b = simde_mm256_mask_blend_epi8(simde_test_x86_random_mmask32(), a, simde_test_x86_random_i8x32());
    simde__mmask32 r = simde_mm256_mask_cmpneq_epi8_mask(k1, a, b);

    simde_test_x86_write_mmask32(2, k1, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i8x32(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i8x32(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_cmpneq_epu8_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const uint8_t a[32];
    const uint8_t b[32];
    const simde__mmask32 r;
  } test_vec[] = {
    { { UINT8_C( 20), UINT8_C( 92), UINT8_C(173), UINT8_C(140), UINT8_C(165), UINT8_C( 97), UINT8_C(  9), UINT8_C(127),
        UINT8_C( 92), UINT8_C(  0), UINT8_C(  2), UINT8_C(211), UINT8_C(100), UINT8_C(178), UINT8_C(226), UINT8_C(200),
        UINT8_C(192), UINT8_C(241), UINT8_C( 66), UINT8_C(110), UINT8_C(182), UINT8_C(244), UINT8_C(108), UINT8_C(239),
        UINT8_C( 98), UINT8_C(235), UINT8_C(102), UINT8_C( 96), UINT8_C(243), UINT8_C( 96), UINT8_C( 87), UINT8_C(  7) },
      { UINT8_C( 20), UINT8_C( 92), UINT8_C(147), UINT8_C( 97), UINT8_C(101), UINT8_C( 97), UINT8_C(  9), UINT8_C(127),
        UINT8_C( 92), UINT8_C(  0), UINT8_C(  2), UINT8_C(  0), UINT8_C(100), UINT8_C(120), UINT8_C(226), UINT8_C( 85),
        UINT8_C(192), UINT8_C(241), UINT8_C(196), UINT8_C(110),    UINT8_MAX, UINT8_C( 48), UINT8_C( 15), UINT8_C( 97),
        UINT8_C( 98), UINT8_C(117), UINT8_C(102), UINT8_C( 96), UINT8_C(243), UINT8_C( 96), UINT8_C( 87), UINT8_C(146) },
      UINT32_C(2197071900) },
    { { UINT8_C( 68), UINT8_C(212), UINT8_C( 68), UINT8_C(225), UINT8_C(183), UINT8_C(217), UINT8_C(225), UINT8_C( 76),
        UINT8_C( 81), UINT8_C(170), UINT8_C(161), UINT8_C(186), UINT8_C(181), UINT8_C(101), UINT8_C(218), UINT8_C(180),
        UINT8_C(149), UINT8_C(233), UINT8_C( 21), UINT8_C(176), UINT8_C( 94), UINT8_C(215), UINT8_C(190), UINT8_C( 52),
        UINT8_C(239), UINT8_C(211), UINT8_C(199), UINT8_C( 12), UINT8_C(123), UINT8_C(187), UINT8_C(142), UINT8_C(192) },
      { UINT8_C(143), UINT8_C(212), UINT8_C(161), UINT8_C( 70), UINT8_C(171), UINT8_C(217), UINT8_C(146), UINT8_C(253),
        UINT8_C( 81), UINT8_C( 52), UINT8_C(183), UINT8_C(225), UINT8_C(181), UINT8_C(101), UINT8_C(149), UINT8_C(180),
        UINT8_C(122), UINT8_C(233), UINT8_C(223), UINT8_C(176), UINT8_C( 94), UINT8_C(158), UINT8_C( 13), UINT8_C( 52),
        UINT8_C(113), UINT8_C(211), UINT8_C(199), UINT8_C(237), UINT8_C(123), UINT8_C(187), UINT8_C(142), UINT8_C( 31) },
      UINT32_C(2305117917) },
    { { UINT8_C(208), UINT8_C(248), UINT8_C(134), UINT8_C(253), UINT8_C( 44), UINT8_C( 61), UINT8_C(222), UINT8_C(197),
        UINT8_C(207), UINT8_C(116), UINT8_C(244), UINT8_C( 73), UINT8_C( 31), UINT8_C(212), UINT8_C( 34), UINT8_C(161),
        UINT8_C(114), UINT8_C( 48), UINT8_C( 18), UINT8_C(227), UINT8_C(  4), UINT8_C(144), UINT8_C(208), UINT8_C(148),
        UINT8_C(155), UINT8_C(125), UINT8_C(179), UINT8_C(121), UINT8_C(203), UINT8_C( 24), UINT8_C(  2), UINT8_C(156) },
      { UINT8_C(208), UINT8_C(248), UINT8_C(153), UINT8_C( 60), UINT8_C( 44), UINT8_C(119), UINT8_C(  2), UINT8_C(148),
        UINT8_C(207), UINT8_C(246), UINT8_C(222), UINT8_C( 10), UINT8_C( 31), UINT8_C(  0), UINT8_C(171), UINT8_C(161),
        UINT8_C( 48), UINT8_C( 48), UINT8_C( 18), UINT8_C(227), UINT8_C(  4), UINT8_C(240), UINT8_C(201), UINT8_C(233),
        UINT8_C(155), UINT8_C(124), UINT8_C(179), UINT8_C(121), UINT8_C(148), UINT8_C(100), UINT8_C(  2), UINT8_C(165) },
      UINT32_C(3001118444) },
    { { UINT8_C(230), UINT8_C(227), UINT8_C( 70), UINT8_C(209), UINT8_C(218), UINT8_C( 36), UINT8_C(220), UINT8_C(164),
        UINT8_C( 37), UINT8_C(135), UINT8_C(225), UINT8_C( 85), UINT8_C( 69), UINT8_C(  1), UINT8_C(138), UINT8_C(147),
        UINT8_C(241), UINT8_C( 83), UINT8_C(125), UINT8_C( 95), UINT8_C(207), UINT8_C(223), UINT8_C(153), UINT8_C(100),
        UINT8_C( 68), UINT8_C(110), UINT8_C(  9), UINT8_C( 48), UINT8_C(221), UINT8_C(234), UINT8_C(226), UINT8_C(195) },
      { UINT8_C(206), UINT8_C(227), UINT8_C(148), UINT8_C(168), UINT8_C(218), UINT8_C(112), UINT8_C(220), UINT8_C(114),
        UINT8_C(248), UINT8_C( 45), UINT8_C(225), UINT8_C( 61), UINT8_C( 46), UINT8_C( 82), UINT8_C(138), UINT8_C( 32),
        UINT8_C(166), UINT8_C( 78), UINT8_C(125), UINT8_C( 95), UINT8_C(207), UINT8_C(223), UINT8_C(217), UINT8_C(100),
        UINT8_C(135), UINT8_C(226), UINT8_C(  9), UINT8_C(100), UINT8_C(205), UINT8_C(132), UINT8_C( 39), UINT8_C(155) },
      UINT32_C(4215520173) },
    { { UINT8_C( 44), UINT8_C(143), UINT8_C(109), UINT8_C( 36), UINT8_C(189), UINT8_C( 53), UINT8_C( 97), UINT8_C(235),
        UINT8_C(136), UINT8_C( 50), UINT8_C( 11), UINT8_C( 46), UINT8_C(128), UINT8_C(139), UINT8_C(163), UINT8_C(174),
        UINT8_C(163), UINT8_C(125), UINT8_C( 31), UINT8_C( 42), UINT8_C( 95), UINT8_C(193), UINT8_C(142), UINT8_C( 44),
        UINT8_C( 70), UINT8_C(181), UINT8_C(199), UINT8_C(243), UINT8_C(113), UINT8_C( 10), UINT8_C(238), UINT8_C(157) },
      { UINT8_C( 44), UINT8_C(143), UINT8_C(109), UINT8_C( 87), UINT8_C(189), UINT8_C( 34), UINT8_C( 66), UINT8_C( 25),
        UINT8_C(136), UINT8_C( 78), UINT8_C( 11), UINT8_C(213), UINT8_C(217), UINT8_C(235), UINT8_C(163), UINT8_C(124),
        UINT8_C(104), UINT8_C(163), UINT8_C(167), UINT8_C( 42), UINT8_C(100), UINT8_C( 53), UINT8_C(142), UINT8_C(170),
        UINT8_C( 70), UINT8_C(187), UINT8_C(199), UINT8_C( 92), UINT8_C(198), UINT8_C(140), UINT8_C(249), UINT8_C(157) },
      UINT32_C(2058861288) },
    { { UINT8_C(220), UINT8_C(249), UINT8_C(147), UINT8_C( 49), UINT8_C( 71), UINT8_C(219), UINT8_C(  7), UINT8_C( 32),
        UINT8_C(198), UINT8_C(138), UINT8_C(157), UINT8_C( 46), UINT8_C( 45), UINT8_C( 68), UINT8_C(245), UINT8_C(146),
        UINT8_C(121), UINT8_C(233), UINT8_C( 60), UINT8_C(100), UINT8_C(165), UINT8_C(218), UINT8_C(192), UINT8_C(107),
        UINT8_C(103), UINT8_C(185), UINT8_C(203), UINT8_C( 79), UINT8_C(115), UINT8_C(130), UINT8_C(201), UINT8_C( 80) },
      { UINT8_C(220), UINT8_C( 93), UINT8_C(129), UINT8_C( 49), UINT8_C( 71), UINT8_C(219), UINT8_C(227), UINT8_C(254),
        UINT8_C( 19), UINT8_C(138), UINT8_C(157), UINT8_C( 46), UINT8_C( 45), UINT8_C( 33), UINT8_C(210), UINT8_C(146),
        UINT8_C(121), UINT8_C( 15), UINT8_C(162), UINT8_C(100), UINT8_C(165), UINT8_C( 99), UINT8_C(192), UINT8_C( 80),
        UINT8_C(103), UINT8_C(230), UINT8_C(160), UINT8_C(144), UINT8_C(104), UINT8_C(105), UINT8_C(224), UINT8_C(227) },
      UINT32_C(4272316870) },
    { { UINT8_C(234), UINT8_C(138), UINT8_C(252), UINT8_C(253), UINT8_C( 10), UINT8_C( 40), UINT8_C( 61), UINT8_C(207),
        UINT8_C( 74), UINT8_C( 16), UINT8_C( 13), UINT8_C( 85), UINT8_C( 31), UINT8_C(175), UINT8_C(  5), UINT8_C(  8),
        UINT8_C( 18), UINT8_C( 32), UINT8_C( 89), UINT8_C( 47), UINT8_C(  6), UINT8_C(249), UINT8_C(191), UINT8_C(110),
        UINT8_C( 98), UINT8_C(159), UINT8_C( 81), UINT8_C( 41), UINT8_C(  0), UINT8_C(248), UINT8_C( 39), UINT8_C(234) },
      { UINT8_C(130), UINT8_C(138), UINT8_C(231), UINT8_C(253), UINT8_C( 10), UINT8_C( 40), UINT8_C( 61), UINT8_C(150),
        UINT8_C( 74), UINT8_C(104), UINT8_C( 13), UINT8_C( 84), UINT8_C( 31), UINT8_C(175), UINT8_C(  5), UINT8_C( 42),
        UINT8_C( 18), UINT8_C( 32), UINT8_C( 89), UINT8_C( 22), UINT8_C(174), UINT8_C(249), UINT8_C(132), UINT8_C( 17),
        UINT8_C( 98), UINT8_C(214), UINT8_C( 81), UINT8_C( 41), UINT8_C(206), UINT8_C(248), UINT8_C(162), UINT8_C( 80) },
      UINT32_C(3537406597) },
    { { UINT8_C(175), UINT8_C( 56), UINT8_C(104), UINT8_C(228), UINT8_C(160), UINT8_C( 84), UINT8_C( 56), UINT8_C(184),
        UINT8_C( 68), UINT8_C(148), UINT8_C(227), UINT8_C( 85), UINT8_C( 74), UINT8_C( 60), UINT8_C(107), UINT8_C(248),
        UINT8_C( 85), UINT8_C(240), UINT8_C(  9), UINT8_C( 12), UINT8_C(198), UINT8_C( 67), UINT8_C(196), UINT8_C(148),
        UINT8_C(165), UINT8_C(103), UINT8_C(228), UINT8_C( 42), UINT8_C(241), UINT8_C(192), UINT8_C(252), UINT8_C(160) },
      { UINT8_C(248), UINT8_C( 56), UINT8_C(104), UINT8_C(228), UINT8_C(185), UINT8_C( 84), UINT8_C( 56), UINT8_C(184),
        UINT8_C( 80), UINT8_C( 52), UINT8_C(227), UINT8_C( 85), UINT8_C(113), UINT8_C( 60), UINT8_C(107), UINT8_C(248),
        UINT8_C( 85), UINT8_C(156), UINT8_C(210), UINT8_C(116), UINT8_C(224), UINT8_C(151), UINT8_C(196), UINT8_C(148),
        UINT8_C(165), UINT8_C(236), UINT8_C(228), UINT8_C(239), UINT8_C(241), UINT8_C(192), UINT8_C(143), UINT8_C(165) },
      UINT32_C(3393065745) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256i a = simde_mm256_loadu_epi8(test_vec[i].a);
    simde__m256i b = simde_mm256_loadu_epi8(test_vec[i].b);
    simde__mmask32 r = simde_mm256_cmpneq_epu8_mask(a, b);
    simde_assert_equal_mmask32(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m256i a = simde_test_x86_random_u8x32();
    simde__m256i b = simde_mm256_mask_blend_epi8(simde_test_x86_random_mmask32(), a, simde_test_x86_random_u8x32());
    simde__mmask32 r = simde_mm256_cmpneq_epu8_mask(a, b);

    simde_test_x86_write_u8x32(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_u8x32(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_mask_cmpneq_epu8_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask32 k1;
    const uint8_t a[32];
    const uint8_t b[32];
    const simde__mmask32 r;
  } test_vec[] = {
    { UINT32_C( 515966288),
      { UINT8_C(176), UINT8_C(116), UINT8_C(169), UINT8_C( 62), UINT8_C(127), UINT8_C(163), UINT8_C( 42), UINT8_C(254),
        UINT8_C(155), UINT8_C(101), UINT8_C( 19), UINT8_C( 53), UINT8_C(153), UINT8_C( 41), UINT8_C( 51), UINT8_C(145),
        UINT8_C(173), UINT8_C(250), UINT8_C(104), UINT8_C( 69), UINT8_C(162), UINT8_C( 11), UINT8_C( 45), UINT8_C(248),
        UINT8_C(232), UINT8_C( 28), UINT8_C(234), UINT8_C( 56), UINT8_C( 33), UINT8_C(171), UINT8_C( 86), UINT8_C(210) },
      { UINT8_C(176), UINT8_C(116), UINT8_C( 16), UINT8_C( 62), UINT8_C(163), UINT8_C( 58), UINT8_C( 42), UINT8_C( 62),
        UINT8_C(159), UINT8_C(101), UINT8_C( 19), UINT8_C( 56), UINT8_C(218), UINT8_C( 41), UINT8_C( 51), UINT8_C(145),
        UINT8_C(161), UINT8_C(250), UINT8_C(104), UINT8_C( 69), UINT8_C( 62), UINT8_C( 11), UINT8_C( 45), UINT8_C( 38),
        UINT8_C(232), UINT8_C( 28), UINT8_C(234), UINT8_C( 55), UINT8_C(209), UINT8_C(171), UINT8_C(  9), UINT8_C(210) },
      UINT32_C( 411107600) },
    { UINT32_C(4069928787),
      { UINT8_C(224), UINT8_C( 10), UINT8_C( 43), UINT8_C(187), UINT8_C(177), UINT8_C(245), UINT8_C( 66), UINT8_C( 83),
        UINT8_C( 39), UINT8_C( 15), UINT8_C(150), UINT8_C(101), UINT8_C(  9), UINT8_C(210), UINT8_C(139), UINT8_C( 31),
        UINT8_C(248), UINT8_C(233), UINT8_C( 86), UINT8_C(201), UINT8_C(158), UINT8_C( 96), UINT8_C(187), UINT8_C( 82),
        UINT8_C(121), UINT8_C( 76), UINT8_C(170), UINT8_C(205), UINT8_C(123), UINT8_C( 65), UINT8_C(191), UINT8_C( 91) },
      { UINT8_C( 75), UINT8_C(234), UINT8_C( 22), UINT8_C(187), UINT8_C(223), UINT8_C( 89), UINT8_C( 66), UINT8_C( 83),
        UINT8_C( 39), UINT8_C(230), UINT8_C(108), UINT8_C(113), UINT8_C(  9), UINT8_C(248), UINT8_C(144), UINT8_C( 31),
        UINT8_C(248), UINT8_C(230), UINT8_C(122), UINT8_C(201), UINT8_C(158), UINT8_C( 96), UINT8_C(187), UINT8_C( 82),
        UINT8_C(121), UINT8_C(124), UINT8_C(141), UINT8_C(205), UINT8_C(189), UINT8_C( 65), UINT8_C(191), UINT8_C( 91) },
      UINT32_C( 302394899) },
    { UINT32_C( 790451911),
      { UINT8_C( 60), UINT8_C(138), UINT8_C(160), UINT8_C(245), UINT8_C(130), UINT8_C( 48), UINT8_C(165), UINT8_C( 99),
        UINT8_C( 22), UINT8_C( 31), UINT8_C(227), UINT8_C( 93), UINT8_C( 84), UINT8_C(181), UINT8_C( 29), UINT8_C(213),
        UINT8_C( 49), UINT8_C(170), UINT8_C(209), UINT8_C(239), UINT8_C(246), UINT8_C( 41), UINT8_C(248), UINT8_C( 45),
        UINT8_C(151), UINT8_C(254), UINT8_C( 68), UINT8_C( 94), UINT8_C( 84), UINT8_C( 97), UINT8_C(141), UINT8_C(144) },
      { UINT8_C( 60), UINT8_C( 45), UINT8_C(133), UINT8_C(109), UINT8_C( 93), UINT8_C( 48), UINT8_C(165), UINT8_C( 99),
        UINT8_C( 74), UINT8_C( 31), UINT8_C(227), UINT8_C(159), UINT8_C( 84), UINT8_C(237), UINT8_C(116), UINT8_C(154),
        UINT8_C( 49), UINT8_C( 70), UINT8_C(209), UINT8_C(142), UINT8_C(111), UINT8_C(129), UINT8_C(248), UINT8_C(  6),
        UINT8_C(127),    UINT8_MAX, UINT8_C( 68), UINT8_C(211), UINT8_C( 97), UINT8_C(241), UINT8_C(100), UINT8_C(144) },
      UINT32_C( 723009542) },
    { UINT32_C(1609468692),
      { UINT8_C( 63), UINT8_C(191), UINT8_C(254), UINT8_C(168), UINT8_C(172), UINT8_C(114), UINT8_C( 66), UINT8_C( 68),
        UINT8_C(184), UINT8_C(204), UINT8_C(210), UINT8_C( 39), UINT8_C( 77), UINT8_C(141), UINT8_C( 45), UINT8_C(205),
        UINT8_C(141), UINT8_C(145), UINT8_C(160), UINT8_C(238), UINT8_C(130), UINT8_C(  4), UINT8_C( 58), UINT8_C(160),
        UINT8_C(238), UINT8_C(244), UINT8_C( 27), UINT8_C(  2), UINT8_C(127), UINT8_C( 10), UINT8_C( 97), UINT8_C(190) },
      { UINT8_C( 63), UINT8_C( 95), UINT8_C(102), UINT8_C(168), UINT8_C(172), UINT8_C(169), UINT8_C(185), UINT8_C(138),
        UINT8_C(117), UINT8_C(139), UINT8_C(178), UINT8_C( 39), UINT8_C( 77), UINT8_C(223), UINT8_C(143), UINT8_C(205),
        UINT8_C(141), UINT8_C(145), UINT8_C(160), UINT8_C(243), UINT8_C( 52), UINT8_C(206), UINT8_C(148), UINT8_C( 34),
        UINT8_C(238), UINT8_C(244), UINT8_C( 27), UINT8_C( 66), UINT8_C(185), UINT8_C(134), UINT8_C( 97), UINT8_C(130) },
      UINT32_C( 417858308) },
    { UINT32_C(2235740432),
      { UINT8_C( 61), UINT8_C(244), UINT8_C( 72), UINT8_C( 86), UINT8_C(212), UINT8_C(215), UINT8_C(252), UINT8_C( 69),
        UINT8_C(  7), UINT8_C(144), UINT8_C( 56), UINT8_C( 60), UINT8_C( 94), UINT8_C(204), UINT8_C( 94), UINT8_C( 33),
        UINT8_C(124), UINT8_C(131), UINT8_C(100), UINT8_C( 53), UINT8_C( 10), UINT8_C(101), UINT8_C(184), UINT8_C(240),
        UINT8_C(204), UINT8_C(176), UINT8_C(168), UINT8_C(221), UINT8_C( 97), UINT8_C(234), UINT8_C( 98), UINT8_C(158) },
      { UINT8_C( 61), UINT8_C(244), UINT8_C( 72), UINT8_C( 86), UINT8_C(212), UINT8_C(215), UINT8_C(252), UINT8_C(137),
        UINT8_C(128), UINT8_C( 48), UINT8_C( 56), UINT8_C(223), UINT8_C( 94), UINT8_C(204), UINT8_C( 94), UINT8_C( 33),
        UINT8_C(124), UINT8_C(100), UINT8_C(174), UINT8_C( 53), UINT8_C( 10), UINT8_C(101), UINT8_C(161), UINT8_C(150),
        UINT8_C(204), UINT8_C( 73), UINT8_C(168), UINT8_C(221), UINT8_C( 97), UINT8_C(234), UINT8_C( 98), UINT8_C(158) },
      UINT32_C(   4325632) },
    { UINT32_C(2089533179),
      { UINT8_C(238), UINT8_C( 81), UINT8_C( 91), UINT8_C(235), UINT8_C(117), UINT8_C( 91), UINT8_C(100), UINT8_C( 28),
        UINT8_C(192), UINT8_C( 19), UINT8_C(206), UINT8_C(137), UINT8_C(121), UINT8_C(111), UINT8_C( 31), UINT8_C(144),
        UINT8_C(185), UINT8_C(146), UINT8_C(  8), UINT8_C(237), UINT8_C(104), UINT8_C( 30), UINT8_C(  0), UINT8_C(232),
        UINT8_C( 41), UINT8_C(198), UINT8_C(234), UINT8_C( 37), UINT8_C(132), UINT8_C(117), UINT8_C(161), UINT8_C(114) },
      { UINT8_C(198), UINT8_C( 81), UINT8_C( 91), UINT8_C(235), UINT8_C( 87), UINT8_C(194), UINT8_C( 88), UINT8_C( 23),
        UINT8_C(192), UINT8_C( 38), UINT8_C(161), UINT8_C(137), UINT8_C(149), UINT8_C(111), UINT8_C(223), UINT8_C(144),
        UINT8_C(185), UINT8_C(146), UINT8_C( 59), UINT8_C(237), UINT8_C(104), UINT8_C( 30), UINT8_C(  0), UINT8_C(232),
        UINT8_C( 41), UINT8_C(198), UINT8_C(234), UINT8_C(133), UINT8_C(132), UINT8_C(117), UINT8_C(248), UINT8_C(114) },
      UINT32_C(1207965425) },
    { UINT32_C(3999292440),
      { UINT8_C(130), UINT8_C(  1), UINT8_C( 61), UINT8_C( 24), UINT8_C(193), UINT8_C( 28), UINT8_C(102), UINT8_C( 20),
        UINT8_C(  3), UINT8_C(162), UINT8_C(207), UINT8_C(  8), UINT8_C(221), UINT8_C(114), UINT8_C( 55), UINT8_C(223),
           UINT8_MAX, UINT8_C(139), UINT8_C(100), UINT8_C(  2), UINT8_C(128), UINT8_C( 92), UINT8_C(203), UINT8_C(113),
        UINT8_C(178), UINT8_C(207), UINT8_C(186), UINT8_C(203), UINT8_C( 44), UINT8_C( 26), UINT8_C(185), UINT8_C(174) },
      { UINT8_C( 27), UINT8_C(  1), UINT8_C( 61), UINT8_C(220), UINT8_C( 18), UINT8_C( 45), UINT8_C(241), UINT8_C( 20),
        UINT8_C(  3), UINT8_C(162), UINT8_C(207), UINT8_C(  8), UINT8_C( 51), UINT8_C( 85), UINT8_C(139), UINT8_C(223),
           UINT8_MAX, UINT8_C(240), UINT8_C( 52), UINT8_C( 97), UINT8_C( 76), UINT8_C( 92), UINT8_C(203),    UINT8_MAX,
        UINT8_C(207), UINT8_C(140), UINT8_C(186), UINT8_C(251), UINT8_C( 44), UINT8_C( 26), UINT8_C(185), UINT8_C(193) },
      UINT32_C(2315276312) },
    { UINT32_C(1822461853),
      { UINT8_C( 79), UINT8_C(189), UINT8_C( 24), UINT8_C(130), UINT8_C( 18), UINT8_C(164), UINT8_C(181), UINT8_C(243),
        UINT8_C(148), UINT8_C(233), UINT8_C( 84), UINT8_C(224), UINT8_C(233), UINT8_C( 38), UINT8_C(223), UINT8_C(184),
        UINT8_C(179), UINT8_C(169), UINT8_C(179), UINT8_C( 89), UINT8_C( 44), UINT8_C( 92), UINT8_C( 27), UINT8_C(165),
        UINT8_C(204), UINT8_C(185), UINT8_C( 48), UINT8_C(105), UINT8_C( 72), UINT8_C(208), UINT8_C(213), UINT8_C(151) },
      { UINT8_C( 79), UINT8_C(238), UINT8_C( 24), UINT8_C(130), UINT8_C( 18), UINT8_C(207), UINT8_C(147), UINT8_C(243),
        UINT8_C(148), UINT8_C(233), UINT8_C( 84), UINT8_C(161), UINT8_C(233), UINT8_C(230), UINT8_C( 89), UINT8_C(193),
        UINT8_C(143), UINT8_C(169), UINT8_C(179), UINT8_C( 89), UINT8_C(105), UINT8_C( 92), UINT8_C( 27), UINT8_C( 53),
        UINT8_C(204), UINT8_C(185), UINT8_C(159), UINT8_C(105), UINT8_C( 98), UINT8_C(116), UINT8_C(206), UINT8_C(240) },
      UINT32_C(1686145024) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256i a = simde_mm256_loadu_epi8(test_vec[i].a);
    simde__m256i b = simde_mm256_loadu_epi8(test_vec[i].b);
    simde__mmask32 r = simde_mm256_mask_cmpneq_epu8_mask(test_vec[i].k1, a, b);
    simde_assert_equal_mmask32(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask32 k1 = simde_test_x86_random_mmask32();
    simde__m256i a = simde_test_x86_random_u8x32();
    simde__m256i b = simde_mm256_mask_blend_epi8(simde_test_x86_random_mmask32(), a, simde_test_x86_random_u8x32());
    simde__mmask32 r = simde_mm256_mask_cmpneq_epu8_mask(k1, a, b);

    simde_test_x86_write_mmask32(2, k1, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_u8x32(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_u8x32(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_cmpneq_epi16_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int16_t a[16];
    const int16_t b[16];
    const simde__mmask16 r;
  } test_vec[] = {
    { {  INT16_C( 20215),  INT16_C(  3225), -INT16_C( 10842),  INT16_C( 18746),  INT16_C(  9081), -INT16_C( 20312),  INT16_C(  5157), -INT16_C(  5095),
         INT16_C(  6709), -INT16_C( 30698), -INT16_C( 20858),  INT16_C( 12807),  INT16_C(  4033), -INT16_C( 14799), -INT16_C( 21214),  INT16_C(  6576) },
      {  INT16_C( 18939),  INT16_C(  3225), -INT16_C( 10842), -INT16_C( 26390), -INT16_C( 27773), -INT16_C( 20312),  INT16_C( 24999), -INT16_C(  9068),
         INT16_C(  6709), -INT16_C( 30698),  INT16_C( 27481),  INT16_C(  6709),  INT16_C( 26234), -INT16_C( 14799), -INT16_C( 28653),  INT16_C(  3766) },
      UINT16_C(56537) },
    { { -INT16_C(  1872), -INT16_C( 26052), -INT16_C( 16496), -INT16_C( 10195), -INT16_C( 11161), -INT16_C(  1223), -INT16_C( 19024),  INT16_C(  5286),
        -INT16_C(    72), -INT16_C(  4736), -INT16_C(  1510), -INT16_C(  1453),  INT16_C( 26519),  INT16_C( 19851),  INT16_C( 25717),  INT16_C(  9513) },
      {  INT16_C( 25948), -INT16_C(  4928), -INT16_C( 16496), -INT16_C( 10195), -INT16_C(   318),  INT16_C( 29318),  INT16_C( 11699),  INT16_C(  5286),
        -INT16_C(    72),  INT16_C( 18008), -INT16_C( 21503), -INT16_C( 26559),  INT16_C( 26519), -INT16_C( 30491),  INT16_C(  3632),  INT16_C(  9513) },
      UINT16_C(28275) },
    { { -INT16_C( 26759),  INT16_C( 15963),  INT16_C(  7458), -INT16_C( 22212), -INT16_C(  4208),  INT16_C(  6102),  INT16_C(   603), -INT16_C( 19682),
         INT16_C(  8009), -INT16_C( 30113),  INT16_C( 29368), -INT16_C( 25258), -INT16_C( 30981), -INT16_C( 22100),  INT16_C(  7955), -INT16_C( 29417) },
      { -INT16_C( 26759),  INT16_C( 15963),  INT16_C(  1936), -INT16_C( 22212), -INT16_C(  4208),  INT16_C(  6102),  INT16_C(   603), -INT16_C( 19682),
         INT16_C(  8009),  INT16_C( 11310), -INT16_C( 31529), -INT16_C( 25258),  INT16_C( 30218),  INT16_C(  7803), -INT16_C( 28011), -INT16_C( 29417) },
      UINT16_C(30212) },
    { { -INT16_C( 27610), -INT16_C( 22403),  INT16_C( 29620), -INT16_C(  5375),  INT16_C( 23749), -INT16_C( 13760), -INT16_C( 19200),  INT16_C( 11822),
         INT16_C(  1505), -INT16_C( 21582), -INT16_C( 17193),  INT16_C( 21025), -INT16_C( 18470), -INT16_C( 31260), -INT16_C(  5885),  INT16_C( 10747) },
      {  INT16_C( 30845),  INT16_C( 13010), -INT16_C( 11284), -INT16_C( 20195),  INT16_C( 24111), -INT16_C( 13760), -INT16_C( 19200), -INT16_C(  2979),
         INT16_C(  4015), -INT16_C( 31072), -INT16_C( 15925),  INT16_C( 21025), -INT16_C( 17032),  INT16_C( 31787),  INT16_C( 10150),  INT16_C( 10747) },
      UINT16_C(30623) },
    { { -INT16_C( 29866),  INT16_C( 29514),  INT16_C( 31036), -INT16_C( 18479), -INT16_C(  7000),  INT16_C(  1377),  INT16_C(  4313),  INT16_C( 30996),
        -INT16_C(  8042),  INT16_C( 28474), -INT16_C( 19578), -INT16_C( 20179), -INT16_C( 11473), -INT16_C( 11048),  INT16_C( 30967),  INT16_C( 19788) },
      { -INT16_C( 29866),  INT16_C( 29514), -INT16_C( 28144), -INT16_C( 18185),  INT16_C( 22647),  INT16_C(  1377),  INT16_C(  4313), -INT16_C(    55),
         INT16_C(   946),  INT16_C( 28474), -INT16_C( 25674), -INT16_C( 20179), -INT16_C( 15761),  INT16_C( 26298),  INT16_C(  1594),  INT16_C( 19788) },
      UINT16_C(30108) },
    { { -INT16_C( 21378),  INT16_C( 29959),  INT16_C( 32357),  INT16_C(  9166),  INT16_C( 14030), -INT16_C( 26635), -INT16_C( 22475), -INT16_C( 23397),
         INT16_C( 20960), -INT16_C( 13761), -INT16_C( 20937), -INT16_C(  3699), -INT16_C( 14571), -INT16_C( 13833), -INT16_C( 27899), -INT16_C( 31938) },
      { -INT16_C( 21378), -INT16_C( 23047), -INT16_C( 14396),  INT16_C(  9166),  INT16_C( 14030),  INT16_C( 13098), -INT16_C( 22475), -INT16_C( 23397),
         INT16_C(  5654),  INT16_C( 19728), -INT16_C( 25147), -INT16_C(  3699), -INT16_C( 14571),  INT16_C( 27299), -INT16_C(  7735),  INT16_C(  2542) },
      UINT16_C(59174) },
    { { -INT16_C(  5458),  INT16_C( 30382), -INT16_C( 21635), -INT16_C( 22733), -INT16_C( 26146), -INT16_C( 19092), -INT16_C( 32033), -INT16_C(  4148),
        -INT16_C( 28208),  INT16_C(  3725), -INT16_C(  3477),  INT16_C(  3652),  INT16_C(  3420),  INT16_C( 19183),  INT16_C(  5398), -INT16_C( 15311) },
      { -INT16_C(  5458),  INT16_C( 30382),  INT16_C( 28043),  INT16_C( 26916), -INT16_C( 26146), -INT16_C( 19092), -INT16_C( 32033), -INT16_C(  4148),
        -INT16_C( 28208), -INT16_C(  6159),  INT16_C( 13652),  INT16_C(  3652), -INT16_C(  7102),  INT16_C( 19183),  INT16_C( 11513), -INT16_C( 15311) },
      UINT16_C(22028) },
    { { -INT16_C( 26762), -INT16_C( 25917), -INT16_C( 13824),  INT16_C(  7978),  INT16_C( 15791), -INT16_C( 31734), -INT16_C( 31201),  INT16_C(  4326),
         INT16_C( 14957),  INT16_C( 25157), -INT16_C( 30741), -INT16_C(  6586),  INT16_C( 16607), -INT16_C(  1262),  INT16_C(  7737), -INT16_C( 20399) },
      { -INT16_C( 26762), -INT16_C( 25917), -INT16_C( 13824),  INT16_C(  7978), -INT16_C(  8014), -INT16_C( 12013), -INT16_C(  1690), -INT16_C( 11038),
         INT16_C( 10036),  INT16_C( 25157), -INT16_C( 30741), -INT16_C(  6586),  INT16_C(  6077), -INT16_C(  2422), -INT16_C(  9418), -INT16_C(  5210) },
      UINT16_C(61936) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256i a = simde_mm256_loadu_epi16(test_vec[i].a);
    simde__m256i b = simde_mm256_loadu_epi16(test_vec[i].b);
    simde__mmask16 r = simde_mm256_cmpneq_epi16_mask(a, b);
    simde_assert_equal_mmask16(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m256i a = simde_test_x86_random_i16x16();
    simde__m256i b = simde_mm256_mask_blend_epi16(simde_test_x86_random_mmask16(), a, simde_test_x86_random_i16x16());
    simde__mmask16 r = simde_mm256_cmpneq_epi16_mask(a, b);

    simde_test_x86_write_i16x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i16x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_mask_cmpneq_epi16_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask16 k1;
    const int16_t a[16];
    const int16_t b[16];
    const simde__mmask16 r;
  } test_vec[] = {
    { UINT16_C(53153),
      {  INT16_C( 30566),  INT16_C(  6238),  INT16_C( 29015), -INT16_C( 16919), -INT16_C( 13462), -INT16_C( 24943), -INT16_C( 14093), -INT16_C( 23875),
        -INT16_C( 15803),  INT16_C(   560), -INT16_C( 17702),  INT16_C(  4344), -INT16_C( 24682), -INT16_C( 30981), -INT16_C( 25200), -INT16_C(  2474) },
      { -INT16_C( 19436),  INT16_C(  6238),  INT16_C( 29015), -INT16_C( 28888), -INT16_C( 13462), -INT16_C( 18898), -INT16_C(  5246), -INT16_C( 23875),
        -INT16_C( 15803),  INT16_C(   560), -INT16_C( 16061),  INT16_C(  4344), -INT16_C( 27808), -INT16_C(  4001), -INT16_C( 19152),  INT16_C( 17638) },
      UINT16_C(50209) },
    { UINT16_C(36527),
      { -INT16_C( 10004), -INT16_C( 20706),  INT16_C( 19602),  INT16_C(  5221), -INT16_C( 17097), -INT16_C(  6693), -INT16_C( 23483), -INT16_C( 30611),
         INT16_C(  1381), -INT16_C( 14751), -INT16_C( 15975), -INT16_C( 13898), -INT16_C( 25226), -INT16_C(  8178), -INT16_C( 17007),  INT16_C( 32110) },
      { -INT16_C( 10004), -INT16_C( 20706),  INT16_C( 19602),  INT16_C(  5221),  INT16_C(  5710), -INT16_C(  6693), -INT16_C( 23483),  INT16_C(  8220),
         INT16_C( 32360), -INT16_C( 14751), -INT16_C( 25537), -INT16_C( 13898), -INT16_C(  9927), -INT16_C( 13419),  INT16_C(  1174),  INT16_C( 32110) },
      UINT16_C( 1152) },
    { UINT16_C(26963),
      { -INT16_C( 28922),  INT16_C( 21881),  INT16_C( 28325),  INT16_C( 24809),  INT16_C(  1489),  INT16_C( 14976),  INT16_C( 26243), -INT16_C( 15813),
         INT16_C(  1538),  INT16_C( 15480),  INT16_C(  3551),  INT16_C( 30215),  INT16_C( 20241), -INT16_C( 23902), -INT16_C(  2620), -INT16_C( 13557) },
      { -INT16_C( 28922),  INT16_C( 21881),  INT16_C(  2546), -INT16_C( 15222),  INT16_C(  2574),  INT16_C( 14976),  INT16_C( 26243), -INT16_C( 15813),
         INT16_C(  1538),  INT16_C( 15480), -INT16_C( 18982),  INT16_C( 30215),  INT16_C( 14085), -INT16_C( 13939), -INT16_C(  2620), -INT16_C( 20076) },
      UINT16_C( 8208) },
    { UINT16_C( 4059),
      {  INT16_C( 26045), -INT16_C( 13101), -INT16_C( 11921), -INT16_C(  8354), -INT16_C( 19958),  INT16_C( 19026),  INT16_C(   127),  INT16_C( 22890),
        -INT16_C(    74), -INT16_C( 17596), -INT16_C( 11721),  INT16_C( 25732),  INT16_C(  6506), -INT16_C( 30955), -INT16_C(  3635), -INT16_C( 29802) },
      {  INT16_C( 26045), -INT16_C( 14761), -INT16_C( 19142), -INT16_C(  8354), -INT16_C( 19958),  INT16_C( 19026), -INT16_C(  1544),  INT16_C( 22890),
        -INT16_C(    74),  INT16_C( 12137), -INT16_C(  4778),  INT16_C( 25732), -INT16_C( 22266), -INT16_C( 11193), -INT16_C(  3635), -INT16_C(  4001) },
      UINT16_C( 1602) },
    { UINT16_C(32950),
      {  INT16_C( 23659), -INT16_C( 11579),  INT16_C( 21587),  INT16_C( 19385), -INT16_C(  1971),  INT16_C( 17913),  INT16_C( 25212), -INT16_C( 11659),
         INT16_C(  2128),  INT16_C( 22163), -INT16_C(  9551),  INT16_C( 19242), -INT16_C( 30280), -INT16_C(   452), -INT16_C(  3521), -INT16_C( 21889) },
      {  INT16_C( 23659), -INT16_C( 11579),  INT16_C( 13976),  INT16_C( 19385), -INT16_C(  1971), -INT16_C( 21718), -INT16_C( 24759), -INT16_C( 11659),
         INT16_C(  4264),  INT16_C( 23024), -INT16_C(  9551), -INT16_C( 23643), -INT16_C( 30280), -INT16_C(   452), -INT16_C(  3521), -INT16_C( 21889) },
      UINT16_C(   36) },
    { UINT16_C(64708),
      { -INT16_C( 20159),  INT16_C( 28641),  INT16_C(  3224), -INT16_C(  7654), -INT16_C( 26453),  INT16_C( 21371),  INT16_C( 27560), -INT16_C( 27731),
         INT16_C( 21126),  INT16_C( 10806), -INT16_C( 10189),  INT16_C(  1549), -INT16_C( 25608),  INT16_C( 23848), -INT16_C(  4954), -INT16_C(  6311) },
      { -INT16_C( 20159),  INT16_C( 13911),  INT16_C( 28999), -INT16_C(  3560), -INT16_C( 27639), -INT16_C( 19898),  INT16_C( 27560), -INT16_C( 27731),
         INT16_C( 31813),  INT16_C( 10806), -INT16_C( 17068),  INT16_C( 19582), -INT16_C( 22696), -INT16_C(    87), -INT16_C(  4954), -INT16_C(  6311) },
      UINT16_C(15364) },
    { UINT16_C(34152),
      { -INT16_C( 32593), -INT16_C( 18313), -INT16_C( 17132),  INT16_C(  5226), -INT16_C( 20304), -INT16_C(  2663),  INT16_C( 18732), -INT16_C( 32659),
        -INT16_C(  5114),  INT16_C( 24268),  INT16_C( 30355),  INT16_C(  9821),  INT16_C( 17529), -INT16_C( 18600), -INT16_C( 16255),  INT16_C( 12348) },
      { -INT16_C( 19648), -INT16_C( 18313), -INT16_C( 17132),  INT16_C(  5226),  INT16_C(   515), -INT16_C(  2663),  INT16_C( 18732), -INT16_C( 32659),
        -INT16_C(  5114),  INT16_C( 24268),  INT16_C(  3570),  INT16_C( 27434),  INT16_C( 17529), -INT16_C( 11486),  INT16_C( 24130), -INT16_C( 32253) },
      UINT16_C(33792) },
    { UINT16_C(33495),
      {  INT16_C( 16448),  INT16_C( 17316), -INT16_C( 17597), -INT16_C( 29069),  INT16_C(  8767), -INT16_C( 20256), -INT16_C( 28514), -INT16_C( 28493),
        -INT16_C(  8803), -INT16_C(  4101),  INT16_C(  7519), -INT16_C( 24126), -INT16_C( 14981), -INT16_C( 29404), -INT16_C(  1102), -INT16_C(  3569) },
      {  INT16_C( 16448),  INT16_C( 32565), -INT16_C( 22418), -INT16_C( 20979), -INT16_C(  4661), -INT16_C( 20256),  INT16_C(  4477),  INT16_C(  7162),
        -INT16_C(  2577),  INT16_C( 19978),  INT16_C(  7519), -INT16_C( 28944), -INT16_C( 14981),  INT16_C( 17179),  INT16_C( 11023), -INT16_C(  3569) },
      UINT16_C(  726) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256i a = simde_mm256_loadu_epi16(test_vec[i].a);
    simde__m256i b = simde_mm256_loadu_epi16(test_vec[i].b);
    simde__mmask16 r = simde_mm256_mask_cmpneq_epi16_mask(test_vec[i].k1, a, b);
    simde_assert_equal_mmask16(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask16 k1 = simde_test_x86_random_mmask16();
    simde__m256i a = simde_test_x86_random_i16x16();
    simde__m256i b = simde_mm256_mask_blend_epi16(simde_test_x86_random_mmask16(), a, simde_test_x86_random_i16x16());
    simde__mmask16 r = simde_mm256_mask_cmpneq_epi16_mask(k1, a, b);

    simde_test_x86_write_mmask16(2, k1, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i16x16(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_cmpneq_epu16_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const uint16_t a[16];
    const uint16_t b[16];
    const simde__mmask16 r;
  } test_vec[] = {
    { { UINT16_C(19914), UINT16_C(55315), UINT16_C(57083), UINT16_C(22981), UINT16_C(17224), UINT16_C(17002), UINT16_C(22878), UINT16_C(26679),
        UINT16_C(19112), UINT16_C(38964), UINT16_C(50649), UINT16_C(62636), UINT16_C(47881), UINT16_C(15903), UINT16_C(65031), UINT16_C(53673) },
      { UINT16_C(48459), UINT16_C(18089), UINT16_C(28571), UINT16_C(58271), UINT16_C( 2482), UINT16_C(17002), UINT16_C(22878), UINT16_C(26679),
        UINT16_C(19112), UINT16_C(38964), UINT16_C(20337), UINT16_C(31349), UINT16_C(47881), UINT16_C(15903), UINT16_C(65031), UINT16_C(56803) },
      UINT16_C(35871) },
    { { UINT16_C(47907), UINT16_C(49915), UINT16_C(44446), UINT16_C(50380), UINT16_C(12221), UINT16_C(13601), UINT16_C(51258), UINT16_C(56801),
        UINT16_C(21321), UINT16_C(48684), UINT16_C(14029), UINT16_C(34386), UINT16_C(58696), UINT16_C(11241), UINT16_C( 2242), UINT16_C(59063) },
      { UINT16_C(47907), UINT16_C(25256), UINT16_C(44446), UINT16_C( 7718), UINT16_C(18339), UINT16_C(56659), UINT16_C(13583), UINT16_C(22714),
        UINT16_C(59016), UINT16_C(21782), UINT16_C(26909), UINT16_C(26076), UINT16_C(50510), UINT16_C(11241), UINT16_C( 2242), UINT16_C(37366) },
      UINT16_C(40954) },
    { { UINT16_C(23539), UINT16_C( 6419), UINT16_C(46969), UINT16_C(52320), UINT16_C(28564), UINT16_C(20225), UINT16_C(35272), UINT16_C(56885),
        UINT16_C(21215), UINT16_C(47943), UINT16_C(38327), UINT16_C(18304), UINT16_C(19878), UINT16_C(40079), UINT16_C(35294), UINT16_C(53563) },
      { UINT16_C(23539), UINT16_C(24042), UINT16_C(46969), UINT16_C(39466), UINT16_C(28564), UINT16_C(20225), UINT16_C(35272), UINT16_C(56885),
        UINT16_C(43121), UINT16_C(10575), UINT16_C(53053), UINT16_C(18304), UINT16_C(65308), UINT16_C(64384), UINT16_C(35294), UINT16_C(28108) },
      UINT16_C(46858) },
    { { UINT16_C( 4299), UINT16_C(62721), UINT16_C(48043), UINT16_C(37920), UINT16_C(54589), UINT16_C(40627), UINT16_C( 9577), UINT16_C(47174),
        UINT16_C(33614), UINT16_C(48775), UINT16_C(42087), UINT16_C(59326), UINT16_C(18335), UINT16_C(27554), UINT16_C(44468), UINT16_C(32546) },
      { UINT16_C( 9405), UINT16_C(62721), UINT16_C(48043), UINT16_C( 7677), UINT16_C(54589), UINT16_C(40627), UINT16_C( 9577), UINT16_C(47174),
        UINT16_C( 5252), UINT16_C(60386), UINT16_C(41144), UINT16_C(22482), UINT16_C(18335), UINT16_C(27554), UINT16_C(44468), UINT16_C(57115) },
      UINT16_C(36617) },
    { { UINT16_C(59464), UINT16_C(17700), UINT16_C(36613), UINT16_C(49397), UINT16_C(52067), UINT16_C(61377), UINT16_C(18158), UINT16_C(53251),
        UINT16_C(47921), UINT16_C( 1136), UINT16_C(22290), UINT16_C(54649), UINT16_C(39923), UINT16_C( 3770), UINT16_C(50042), UINT16_C(49821) },
      { UINT16_C(49835), UINT16_C(45319), UINT16_C(64849), UINT16_C(46193), UINT16_C(52067), UINT16_C(46755), UINT16_C(18158), UINT16_C(43655),
        UINT16_C(63330), UINT16_C(30126), UINT16_C(10063), UINT16_C(54649), UINT16_C(39923), UINT16_C( 3770), UINT16_C(50042), UINT16_C(49821) },
      UINT16_C( 1967) },
    { { UINT16_C(   35), UINT16_C(38148), UINT16_C(52404), UINT16_C(22728), UINT16_C(16770), UINT16_C( 2559), UINT16_C(25067), UINT16_C(39425),
        UINT16_C(20694), UINT16_C( 8385), UINT16_C(33938), UINT16_C(57892), UINT16_C(60353), UINT16_C(49359), UINT16_C(32606), UINT16_C(33223) },
      { UINT16_C(52095), UINT16_C(13334), UINT16_C(56983), UINT16_C( 6796), UINT16_C(35615), UINT16_C( 2851), UINT16_C( 9452), UINT16_C(50085),
        UINT16_C(26228), UINT16_C( 8385), UINT16_C(33938), UINT16_C(44008), UINT16_C(60353), UINT16_C(20844), UINT16_C(13111), UINT16_C(46803) },
      UINT16_C(59903) },
    { { UINT16_C(38634), UINT16_C(30408), UINT16_C(59312), UINT16_C(54273), UINT16_C(61170), UINT16_C(38904), UINT16_C(28081), UINT16_C(38142),
        UINT16_C(59507), UINT16_C(23708), UINT16_C(37012), UINT16_C(   20), UINT16_C(19425), UINT16_C(46131), UINT16_C(12801), UINT16_C(60574) },
      { UINT16_C(38634), UINT16_C(31074), UINT16_C(25677), UINT16_C(16461), UINT16_C(18002), UINT16_C(38904), UINT16_C(54707), UINT16_C(38142),
        UINT16_C(13502), UINT16_C(23708), UINT16_C(37012), UINT16_C(   20), UINT16_C(34273), UINT16_C(58202), UINT16_C(12801), UINT16_C(60574) },
      UINT16_C(12638) },
    { { UINT16_C(44026), UINT16_C(18581), UINT16_C(59371), UINT16_C(50062), UINT16_C(16874), UINT16_C(33432), UINT16_C(22119), UINT16_C(60086),
        UINT16_C(31400), UINT16_C(64128), UINT16_C(25119), UINT16_C(31104), UINT16_C(14405), UINT16_C( 5233), UINT16_C(53177), UINT16_C(45893) },
      { UINT16_C(44026), UINT16_C(18581), UINT16_C(59371), UINT16_C(44329), UINT16_C(49866), UINT16_C(12847), UINT16_C(58648), UINT16_C(60086),
        UINT16_C(40031), UINT16_C(32443), UINT16_C(25119), UINT16_C(17400), UINT16_C(26995), UINT16_C( 5233), UINT16_C(40249), UINT16_C(46304) },
      UINT16_C(56184) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256i a = simde_mm256_loadu_epi16(test_vec[i].a);
    simde__m256i b = simde_mm256_loadu_epi16(test_vec[i].b);
    simde__mmask16 r = simde_mm256_cmpneq_epu16_mask(a, b);
    simde_assert_equal_mmask16(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m256i a = simde_test_x86_random_u16x16();
    simde__m256i b = simde_mm256_mask_blend_epi16(simde_test_x86_random_mmask16(), a, simde_test_x86_random_u16x16());
    simde__mmask16 r = simde_mm256_cmpneq_epu16_mask(a, b);

    simde_test_x86_write_u16x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_u16x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_mask_cmpneq_epu16_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask16 k1;
    const uint16_t a[16];
    const uint16_t b[16];
    const simde__mmask16 r;
  } test_vec[] = {
    { UINT16_C(14874),
      { UINT16_C(17509), UINT16_C(12263), UINT16_C( 5638), UINT16_C( 7777), UINT16_C(32251), UINT16_C(23263), UINT16_C(39706), UINT16_C( 6361),
        UINT16_C(53718), UINT16_C(19036), UINT16_C(45882), UINT16_C(29558), UINT16_C(22096), UINT16_C(51239), UINT16_C(16946), UINT16_C(38659) },
      { UINT16_C(17509), UINT16_C(36038), UINT16_C(10241), UINT16_C(64682), UINT16_C(32251), UINT16_C(48983), UINT16_C(12325), UINT16_C(64472),
        UINT16_C(53718), UINT16_C(15173), UINT16_C(45882), UINT16_C(29558), UINT16_C(22096), UINT16_C(17408), UINT16_C(16946), UINT16_C(40667) },
      UINT16_C( 8714) },
    { UINT16_C(61226),
      { UINT16_C(54730), UINT16_C(28651), UINT16_C(16991), UINT16_C(33839), UINT16_C( 1906), UINT16_C(29567), UINT16_C(50491), UINT16_C( 8879),
        UINT16_C(24193), UINT16_C(37722), UINT16_C(23348), UINT16_C(19928), UINT16_C(45918), UINT16_C(19691), UINT16_C( 5717), UINT16_C( 7995) },
      { UINT16_C(10219), UINT16_C(28651), UINT16_C(48745), UINT16_C(33839), UINT16_C( 1906), UINT16_C(   79), UINT16_C(65042), UINT16_C(37666),
        UINT16_C(24193), UINT16_C(37159), UINT16_C(65496), UINT16_C(19928), UINT16_C(51634), UINT16_C( 2179), UINT16_C( 5717), UINT16_C(51751) },
      UINT16_C(42528) },
    { UINT16_C(20244),
      { UINT16_C(57972), UINT16_C(14635), UINT16_C(31280), UINT16_C(16953), UINT16_C(23673), UINT16_C(54742), UINT16_C(64985), UINT16_C(45414),
        UINT16_C(17660), UINT16_C(44775), UINT16_C(27150), UINT16_C(60854), UINT16_C(56873), UINT16_C( 3768), UINT16_C(52372), UINT16_C( 2397) },
      { UINT16_C(34991), UINT16_C(14635), UINT16_C(31280), UINT16_C(16953), UINT16_C(63448), UINT16_C(54742), UINT16_C(47348), UINT16_C(61538),
        UINT16_C(18940), UINT16_C( 2719), UINT16_C(27150), UINT16_C(60854), UINT16_C(45107), UINT16_C( 3768), UINT16_C(52372), UINT16_C( 2397) },
      UINT16_C(  784) },
    { UINT16_C(54282),
      { UINT16_C(11407), UINT16_C(26448), UINT16_C(41507), UINT16_C( 6168), UINT16_C(31322), UINT16_C(22024), UINT16_C(42948), UINT16_C(30817),
        UINT16_C(23037), UINT16_C(12373), UINT16_C(16393), UINT16_C(34296), UINT16_C(51593), UINT16_C(23473), UINT16_C(48093), UINT16_C(27695) },
      { UINT16_C(11407), UINT16_C(26448), UINT16_C(60450), UINT16_C(31779), UINT16_C(31322), UINT16_C(22024), UINT16_C(13267), UINT16_C(53411),
        UINT16_C(23037), UINT16_C(12373), UINT16_C(16393), UINT16_C(34296), UINT16_C(51593), UINT16_C(40733), UINT16_C(19591), UINT16_C(28428) },
      UINT16_C(49160) },
    { UINT16_C(61050),
      { UINT16_C(40396), UINT16_C(13162), UINT16_C(15816), UINT16_C(39774), UINT16_C(  368), UINT16_C(64875), UINT16_C(27897), UINT16_C(12946),
        UINT16_C(44389), UINT16_C(10228), UINT16_C( 4473), UINT16_C(  455), UINT16_C(54109), UINT16_C(10864), UINT16_C(60083), UINT16_C(32536) },
      { UINT16_C(40396), UINT16_C(20403), UINT16_C( 4544), UINT16_C(39774), UINT16_C(  368), UINT16_C( 3117), UINT16_C(49346), UINT16_C(12946),
        UINT16_C(44389), UINT16_C(59215), UINT16_C( 5699), UINT16_C(41448), UINT16_C(54109), UINT16_C(10864), UINT16_C(58178), UINT16_C(51483) },
      UINT16_C(52834) },
    { UINT16_C( 9752),
      { UINT16_C(  992), UINT16_C(62295), UINT16_C(33882), UINT16_C( 7423), UINT16_C(15940), UINT16_C(45636), UINT16_C(37744), UINT16_C(46233),
        UINT16_C(33193), UINT16_C(37461), UINT16_C( 8409), UINT16_C( 6958), UINT16_C(18691), UINT16_C(27364), UINT16_C(64536), UINT16_C(63632) },
      { UINT16_C(59136), UINT16_C(23275), UINT16_C(60012), UINT16_C( 7423), UINT16_C(15940), UINT16_C(39266), UINT16_C(37744), UINT16_C(63053),
        UINT16_C(41596), UINT16_C(21896), UINT16_C( 8409), UINT16_C(50544), UINT16_C(21504), UINT16_C( 6191), UINT16_C(49233), UINT16_C(20752) },
      UINT16_C( 8704) },
    { UINT16_C( 5035),
      { UINT16_C( 8677), UINT16_C( 3780), UINT16_C( 9948), UINT16_C(10663), UINT16_C(62498), UINT16_C(40480), UINT16_C(43158), UINT16_C(22772),
        UINT16_C(25695), UINT16_C(24349), UINT16_C(19897), UINT16_C( 2679), UINT16_C(34573), UINT16_C(46171), UINT16_C( 1666), UINT16_C(26568) },
      { UINT16_C( 8677), UINT16_C(  885), UINT16_C( 7346), UINT16_C(54317), UINT16_C(19728), UINT16_C(42611), UINT16_C(26613), UINT16_C(22772),
        UINT16_C(25695), UINT16_C(24349), UINT16_C(19897), UINT16_C( 2679), UINT16_C(59825), UINT16_C(46171), UINT16_C( 1666), UINT16_C(26568) },
      UINT16_C( 4138) },
    { UINT16_C(12570),
      { UINT16_C(18221), UINT16_C(15621), UINT16_C(30868), UINT16_C(35556), UINT16_C(58079), UINT16_C(43998), UINT16_C(37630), UINT16_C(26415),
        UINT16_C(48828), UINT16_C(28381), UINT16_C( 2215), UINT16_C(38817), UINT16_C(15610), UINT16_C(31150), UINT16_C(51277), UINT16_C(31402) },
      { UINT16_C(18221), UINT16_C(42167), UINT16_C(39720), UINT16_C(35556), UINT16_C( 3454), UINT16_C(43998), UINT16_C(37630), UINT16_C(23524),
        UINT16_C(48828), UINT16_C(18377), UINT16_C(27593), UINT16_C(38817), UINT16_C(15610), UINT16_C(62525), UINT16_C(51277), UINT16_C(31402) },
      UINT16_C( 8210) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256i a = simde_mm256_loadu_epi16(test_vec[i].a);
    simde__m256i b = simde_mm256_loadu_epi16(test_vec[i].b);
    simde__mmask16 r = simde_mm256_mask_cmpneq_epu16_mask(test_vec[i].k1, a, b);
    simde_assert_equal_mmask16(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask16 k1 = simde_test_x86_random_mmask16();
    simde__m256i a = simde_test_x86_random_u16x16();
    simde__m256i b = simde_mm256_mask_blend_epi16(simde_test_x86_random_mmask16(), a, simde_test_x86_random_u16x16());
    simde__mmask16 r = simde_mm256_mask_cmpneq_epu16_mask(k1, a, b);

    simde_test_x86_write_mmask16(2, k1, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_u16x16(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_u16x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_cmpneq_epi32_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int32_t a[8];
    const int32_t b[8];
    const simde__mmask8 r;
  } test_vec[] = {
    { { -INT32_C(   200139574),  INT32_C(   790375587),  INT32_C(   559121868), -INT32_C(  1645190390), -INT32_C(   222328761), -INT32_C(   774091716), -INT32_C(  1259523395), -INT32_C(   978259205) },
      { -INT32_C(   200139574), -INT32_C(  1142892817),  INT32_C(   559121868), -INT32_C(  1645190390), -INT32_C(  1848524459), -INT32_C(   899502835), -INT32_C(   629190689),  INT32_C(  1335832385) },
      UINT8_C(242) },
    { {  INT32_C(   803275097),  INT32_C(   361405665),  INT32_C(  1185804409), -INT32_C(  1264874510),  INT32_C(   163654748), -INT32_C(   555185010),  INT32_C(   975159819), -INT32_C(  1154650270) },
      {  INT32_C(   803275097),  INT32_C(   610760107),  INT32_C(  1185804409), -INT32_C(    66320993), -INT32_C(  1090138831), -INT32_C(   555185010),  INT32_C(   312458672), -INT32_C(  1664168916) },
      UINT8_C(218) },
    { {  INT32_C(   780529081),  INT32_C(  1754573140),  INT32_C(   403237907), -INT32_C(   985070344), -INT32_C(   148961015),  INT32_C(  1671988134), -INT32_C(   292570590),  INT32_C(  1103702920) },
      {  INT32_C(   780529081),  INT32_C(  1754573140),  INT32_C(   403237907), -INT32_C(   340955678),  INT32_C(   501468278),  INT32_C(  1921026896), -INT32_C(   832499643),  INT32_C(  1103702920) },
      UINT8_C(120) },
    { { -INT32_C(  2089762177),  INT32_C(  1987280024),  INT32_C(   223894432), -INT32_C(   712752375), -INT32_C(  1322933978),  INT32_C(   838309921),  INT32_C(   594396665),  INT32_C(  1419493844) },
      { -INT32_C(  2089762177),  INT32_C(   680610696), -INT32_C(  1355421274), -INT32_C(   712752375), -INT32_C(  1322933978),  INT32_C(   838309921),  INT32_C(   594396665),  INT32_C(  1419493844) },
      UINT8_C(  6) },
    { {  INT32_C(   210664385), -INT32_C(   156060148), -INT32_C(  1524407573), -INT32_C(  1845528857),  INT32_C(  2010413947),  INT32_C(  1127747369),  INT32_C(  1746914926),  INT32_C(  2020507575) },
      {  INT32_C(   109378810), -INT32_C(   156060148), -INT32_C(  2143150183), -INT32_C(  1845528857), -INT32_C(   427170371),  INT32_C(  1663746549),  INT32_C(  1746914926),  INT32_C(  2020507575) },
      UINT8_C( 53) },
    { {  INT32_C(  2078787908), -INT32_C(   451640123),  INT32_C(   159093959), -INT32_C(  1949922139), -INT32_C(   679432939),  INT32_C(   543613911), -INT32_C(   404116050), -INT32_C(  1323521171) },
      {  INT32_C(   975962996),  INT32_C(  1310670983),  INT32_C(   159093959),  INT32_C(  1006902822), -INT32_C(  1575779125),  INT32_C(   543613911), -INT32_C(   404116050), -INT32_C(  1323521171) },
      UINT8_C( 27) },
    { { -INT32_C(  1314716303), -INT32_C(  1098518236),  INT32_C(  1743126089), -INT32_C(  2026757885), -INT32_C(  1376791500),  INT32_C(  1121191062),  INT32_C(   429484033),  INT32_C(   506815661) },
      { -INT32_C(  1314716303), -INT32_C(  1098518236),  INT32_C(  1743126089), -INT32_C(  2015515821),  INT32_C(   372558975), -INT32_C(   765982255),  INT32_C(   535556465), -INT32_C(  1086513067) },
      UINT8_C(248) },
    { {  INT32_C(  1640123917), -INT32_C(   843787109), -INT32_C(   115340722), -INT32_C(  1267095576), -INT32_C(   461008933), -INT32_C(   665430041),  INT32_C(  1663923523), -INT32_C(  1084428878) },
      {  INT32_C(  1640123917),  INT32_C(  1084478962), -INT32_C(   115340722),  INT32_C(  1165800298),  INT32_C(   690618946), -INT32_C(  1677623207), -INT32_C(  1493160203), -INT32_C(  1084428878) },
      UINT8_C(122) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256i a = simde_mm256_loadu_epi32(test_vec[i].a);
    simde__m256i b = simde_mm256_loadu_epi32(test_vec[i].b);
    simde__mmask8 r = simde_mm256_cmpneq_epi32_mask(a, b);
    simde_assert_equal_mmask8(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m256i a = simde_test_x86_random_i32x8();
    simde__m256i b = simde_mm256_mask_blend_epi32(simde_test_x86_random_mmask8(), a, simde_test_x86_random_i32x8());
    simde__mmask8 r = simde_mm256_cmpneq_epi32_mask(a, b);

    simde_test_x86_write_i32x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_mask_cmpneq_epi32_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k1;
    const int32_t a[8];
    const int32_t b[8];
    const simde__mmask8 r;
  } test_vec[] = {
    { UINT8_C( 46),
      {  INT32_C(   514505752), -INT32_C(   955756114), -INT32_C(   809161708), -INT32_C(   245318317),  INT32_C(   654847975),  INT32_C(   624017433),  INT32_C(  1213431609), -INT32_C(   596180540) },
      {  INT32_C(  1828397501), -INT32_C(  2026699917), -INT32_C(  2108229329), -INT32_C(   245318317), -INT32_C(    20677403),  INT32_C(   624017433),  INT32_C(   952006516), -INT32_C(   596180540) },
      UINT8_C(  6) },
    { UINT8_C( 16),
      { -INT32_C(   720123230), -INT32_C(  1479654831),  INT32_C(   962430149), -INT32_C(   441105631),  INT32_C(  1708847681),  INT32_C(   651972456), -INT32_C(  1671670649),  INT32_C(   749515658) },
      { -INT32_C(   838680707), -INT32_C(  1479654831),  INT32_C(  1979765333), -INT32_C(   441105631),  INT32_C(   263992999),  INT32_C(   651972456), -INT32_C(  1671670649),  INT32_C(   749515658) },
      UINT8_C( 16) },
    { UINT8_C(165),
      {  INT32_C(    91625360), -INT32_C(   556282914), -INT32_C(  1651184319),  INT32_C(    13908804), -INT32_C(  2120722101),  INT32_C(   269714534), -INT32_C(  1620682501), -INT32_C(  1438352614) },
      {  INT32_C(  1907341971), -INT32_C(   556282914), -INT32_C(  1218124685),  INT32_C(  1790392351), -INT32_C(  2120722101), -INT32_C(   821494060),  INT32_C(  1886285398), -INT32_C(  1438352614) },
      UINT8_C( 37) },
    { UINT8_C(201),
      {  INT32_C(  1045492718),  INT32_C(   505594810),  INT32_C(   844579451), -INT32_C(  1736250964), -INT32_C(   359246111), -INT32_C(  1806111451),  INT32_C(  2017935965), -INT32_C(  1371425601) },
      {  INT32_C(  1642893735),  INT32_C(   505594810),  INT32_C(   844579451), -INT32_C(  1736250964), -INT32_C(   359246111), -INT32_C(  1806111451), -INT32_C(   420553946),  INT32_C(   932458639) },
      UINT8_C(193) },
    { UINT8_C(128),
      {  INT32_C(   412030616), -INT32_C(   370155290),  INT32_C(  1936568286), -INT32_C(   593541039), -INT32_C(   591349688),  INT32_C(   498591535),  INT32_C(  1632454349),  INT32_C(   383848317) },
      {  INT32_C(   204370213),  INT32_C(   804593233),  INT32_C(  1936568286), -INT32_C(   593541039), -INT32_C(   591349688),  INT32_C(  1866958242),  INT32_C(  1632454349),  INT32_C(   383848317) },
      UINT8_C(  0) },
    { UINT8_C(142),
      { -INT32_C(   894667563),  INT32_C(  1194162596), -INT32_C(  1819682920), -INT32_C(  1739684662), -INT32_C(   165744210),  INT32_C(   831253088), -INT32_C(  1813827789), -INT32_C(   836696328) },
      { -INT32_C(   894667563),  INT32_C(  1194162596),  INT32_C(  1735520157),  INT32_C(   587186291),  INT32_C(   286793137),  INT32_C(   994222855), -INT32_C(  1813827789), -INT32_C(  1499926741) },
      UINT8_C(140) },
    { UINT8_C( 49),
      {  INT32_C(   720765636),  INT32_C(  1377407969), -INT32_C(    99447558), -INT32_C(   971521106),  INT32_C(   392765397),  INT32_C(   675101530), -INT32_C(  1642633210), -INT32_C(   741354738) },
      {  INT32_C(   720765636),  INT32_C(  1409881689),  INT32_C(  1364073378), -INT32_C(   971521106), -INT32_C(   557088380), -INT32_C(  1039791940),  INT32_C(  2137070961), -INT32_C(   967692048) },
      UINT8_C( 48) },
    { UINT8_C( 79),
      { -INT32_C(  2056957828), -INT32_C(   224327516),  INT32_C(  1884782681), -INT32_C(      926668), -INT32_C(  1056395590), -INT32_C(   773949072),  INT32_C(  1258475512),  INT32_C(   295368853) },
      { -INT32_C(  2056957828),  INT32_C(  1641953288),  INT32_C(  1884782681), -INT32_C(   856964334), -INT32_C(  1056395590), -INT32_C(   773949072), -INT32_C(   793725637),  INT32_C(   295368853) },
      UINT8_C( 74) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256i a = simde_mm256_loadu_epi32(test_vec[i].a);
    simde__m256i b = simde_mm256_loadu_epi32(test_vec[i].b);
    simde__mmask8 r = simde_mm256_mask_cmpneq_epi32_mask(test_vec[i].k1, a, b);
    simde_assert_equal_mmask8(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k1 = simde_test_x86_random_mmask8();
    simde__m256i a = simde_test_x86_random_i32x8();
    simde__m256i b = simde_mm256_mask_blend_epi32(simde_test_x86_random_mmask8(), a, simde_test_x86_random_i32x8());
    simde__mmask8 r = simde_mm256_mask_cmpneq_epi32_mask(k1, a, b);

    simde_test_x86_write_mmask8(2, k1, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_cmpneq_epu32_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const uint32_t a[8];
    const uint32_t b[8];
    const simde__mmask8 r;
  } test_vec[] = {
    { { UINT32_C(2958221944), UINT32_C(4150834113), UINT32_C(1208571013), UINT32_C( 867816768), UINT32_C(3483408995), UINT32_C(  34211149), UINT32_C(4289780405), UINT32_C( 877307579) },
      { UINT32_C(1239719048), UINT32_C(4150834113), UINT32_C(3776792993), UINT32_C( 867816768), UINT32_C(3193025904), UINT32_C(  34211149), UINT32_C(4033769525), UINT32_C( 877307579) },
      UINT8_C( 85) },
    { { UINT32_C(1453713417), UINT32_C(1928821289), UINT32_C(1838274967), UINT32_C(2749174766), UINT32_C(3210582884), UINT32_C(3438595164), UINT32_C(4091798842), UINT32_C( 306741769) },
      { UINT32_C(2473127274), UINT32_C(1928821289), UINT32_C( 661362489), UINT32_C(2749174766), UINT32_C(1087317988), UINT32_C(3438595164), UINT32_C(2988502952), UINT32_C( 306741769) },
      UINT8_C( 85) },
    { { UINT32_C(2377936685), UINT32_C( 231127669), UINT32_C(1857613093), UINT32_C(3729967031), UINT32_C(1523683990), UINT32_C(2382560926), UINT32_C(2281681951), UINT32_C(2799557497) },
      { UINT32_C(3224607051), UINT32_C(2043541844), UINT32_C(2649196006), UINT32_C(3729967031), UINT32_C(1523683990), UINT32_C(1777877066), UINT32_C(1844574196), UINT32_C(2799557497) },
      UINT8_C(103) },
    { { UINT32_C(1069276742), UINT32_C( 824522156), UINT32_C(1451147804), UINT32_C(2300666429), UINT32_C(3755248543), UINT32_C(2077506947), UINT32_C(4232986926), UINT32_C(2607049813) },
      { UINT32_C(1069276742), UINT32_C(1898446932), UINT32_C(1451147804), UINT32_C(2827675656), UINT32_C(3755248543), UINT32_C(2077506947), UINT32_C(4073111709), UINT32_C(2607049813) },
      UINT8_C( 74) },
    { { UINT32_C(1771990376), UINT32_C(1009520533), UINT32_C(3208916182), UINT32_C( 338947254), UINT32_C(3484428916), UINT32_C(1567390365), UINT32_C(1804230208), UINT32_C(1421148652) },
      { UINT32_C(  79516526), UINT32_C( 960555363), UINT32_C(3438838806), UINT32_C(3856739185), UINT32_C(4088697174), UINT32_C(1263542539), UINT32_C(1804230208), UINT32_C(1254124507) },
      UINT8_C(191) },
    { { UINT32_C(1730301565), UINT32_C( 310205326), UINT32_C(2139310420), UINT32_C(3151325226), UINT32_C(1053214749), UINT32_C(4089254425), UINT32_C( 885991880), UINT32_C(1727207913) },
      { UINT32_C(4123858279), UINT32_C(3288812144), UINT32_C(3192163220), UINT32_C(3151325226), UINT32_C(4216209634), UINT32_C(4089254425), UINT32_C( 508542261), UINT32_C(1727207913) },
      UINT8_C( 87) },
    { { UINT32_C(2630300242), UINT32_C(3308293178), UINT32_C(3921211344), UINT32_C(2848704873), UINT32_C( 603768343), UINT32_C(1918375861), UINT32_C(2823386726), UINT32_C(1308591867) },
      { UINT32_C(2630300242), UINT32_C( 582490706), UINT32_C(3921211344), UINT32_C(2848704873), UINT32_C( 603768343), UINT32_C(1918375861), UINT32_C(2823386726), UINT32_C(1308591867) },
      UINT8_C(  2) },
    { { UINT32_C(2404663669), UINT32_C(1771599865), UINT32_C(1520634499), UINT32_C(1039725605), UINT32_C( 896224104), UINT32_C( 528023569), UINT32_C(2025109308), UINT32_C(3095003715) },
      { UINT32_C(2404663669), UINT32_C(1771599865), UINT32_C( 237193705), UINT32_C(1039725605), UINT32_C(2027665255), UINT32_C(4086781111), UINT32_C(2025109308), UINT32_C(2449925454) },
      UINT8_C(180) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256i a = simde_mm256_loadu_epi32(test_vec[i].a);
    simde__m256i b = simde_mm256_loadu_epi32(test_vec[i].b);
    simde__mmask8 r = simde_mm256_cmpneq_epu32_mask(a, b);
    simde_assert_equal_mmask8(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m256i a = simde_test_x86_random_u32x8();
    simde__m256i b = simde_mm256_mask_blend_epi32(simde_test_x86_random_mmask8(), a, simde_test_x86_random_u32x8());
    simde__mmask8 r = simde_mm256_cmpneq_epu32_mask(a, b);

    simde_test_x86_write_u32x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_u32x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_mask_cmpneq_epu32_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k1;
    const uint32_t a[8];
    const uint32_t b[8];
    const simde__mmask8 r;
  } test_vec[] = {
    { UINT8_C( 77),
      { UINT32_C(1949104590), UINT32_C(3854374338), UINT32_C(1862335012), UINT32_C(2066114464), UINT32_C(2010111455), UINT32_C(1019468497), UINT32_C( 790761769), UINT32_C(1920849571) },
      { UINT32_C(1949104590), UINT32_C(3816203455), UINT32_C(1862335012), UINT32_C(2066114464), UINT32_C(2010111455), UINT32_C(2355427427), UINT32_C(2914747913), UINT32_C( 723466332) },
      UINT8_C( 64) },
    { UINT8_C(  5),
      { UINT32_C( 866755005), UINT32_C(3601483908), UINT32_C(1078954374), UINT32_C(2093524551), UINT32_C( 829696973), UINT32_C(1941405111), UINT32_C(1235948330), UINT32_C(4233071935) },
      { UINT32_C(2989488174), UINT32_C(3347700288), UINT32_C(1078954374), UINT32_C(2093524551), UINT32_C(2994576123), UINT32_C(1941405111), UINT32_C(2274087240), UINT32_C(2374228574) },
      UINT8_C(  1) },
    { UINT8_C(179),
      { UINT32_C(3364688703), UINT32_C(3785486554), UINT32_C(3232833434), UINT32_C(3915033707), UINT32_C(2216587614), UINT32_C(1062561459), UINT32_C(1897509870), UINT32_C(2149903424) },
      { UINT32_C(3662196992), UINT32_C(1002236321), UINT32_C(1962634505), UINT32_C(3915033707), UINT32_C(2063301575), UINT32_C(1062561459), UINT32_C(1897509870), UINT32_C(2149903424) },
      UINT8_C( 19) },
    { UINT8_C( 13),
      { UINT32_C(1459009946), UINT32_C(4039376884), UINT32_C(3511016564), UINT32_C(1330449491), UINT32_C(1084174215), UINT32_C(1075028991), UINT32_C(2896614376), UINT32_C( 750370450) },
      { UINT32_C(1803726967), UINT32_C(4039376884), UINT32_C(1979031841), UINT32_C(1330449491), UINT32_C(1084174215), UINT32_C(1075028991), UINT32_C(2896614376), UINT32_C( 750370450) },
      UINT8_C(  5) },
    { UINT8_C(157),
      { UINT32_C(1407366391), UINT32_C(3455321304), UINT32_C(1024434553), UINT32_C(1268809942), UINT32_C(2698225648), UINT32_C( 855060374), UINT32_C( 931597341), UINT32_C(2429848728) },
      { UINT32_C(1407366391), UINT32_C(3455321304), UINT32_C(1316091000), UINT32_C(1687753076), UINT32_C(1325755833), UINT32_C(3112303772), UINT32_C(2716862473), UINT32_C(2429848728) },
      UINT8_C( 28) },
    { UINT8_C( 20),
      { UINT32_C(3555407853), UINT32_C(3704054891), UINT32_C(1290615986), UINT32_C(2780407456), UINT32_C(2007127542), UINT32_C(4269845262), UINT32_C(2126713932), UINT32_C(3616686057) },
      { UINT32_C(3786047094), UINT32_C(2495443426), UINT32_C(1290615986), UINT32_C(1207146833), UINT32_C(4240414190), UINT32_C(4269845262), UINT32_C(2126713932), UINT32_C(3616686057) },
      UINT8_C( 16) },
    { UINT8_C(190),
      { UINT32_C( 321912150), UINT32_C(1925111186), UINT32_C( 504107051), UINT32_C( 380959319), UINT32_C(4065719543), UINT32_C(2360387969), UINT32_C(4197101286), UINT32_C(2042119459) },
      { UINT32_C(3582781251), UINT32_C(4014427076), UINT32_C(2987283291), UINT32_C( 380959319), UINT32_C(4065719543), UINT32_C(2360387969), UINT32_C(3114790550), UINT32_C(2042119459) },
      UINT8_C(  6) },
    { UINT8_C(190),
      { UINT32_C(2466843468), UINT32_C( 166159611), UINT32_C(3771413783), UINT32_C(2986246522), UINT32_C(2123941561), UINT32_C( 460074611), UINT32_C( 427466983), UINT32_C(1675149591) },
      { UINT32_C(3371688397), UINT32_C(1574035014), UINT32_C(2369625107), UINT32_C(3611179805), UINT32_C(1968559617), UINT32_C(3968909573), UINT32_C( 427466983), UINT32_C(2581454540) },
      UINT8_C(190) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256i a = simde_mm256_loadu_epi32(test_vec[i].a);
    simde__m256i b = simde_mm256_loadu_epi32(test_vec[i].b);
    simde__mmask8 r = simde_mm256_mask_cmpneq_epu32_mask(test_vec[i].k1, a, b);
    simde_assert_equal_mmask8(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k1 = simde_test_x86_random_mmask8();
    simde__m256i a = simde_test_x86_random_u32x8();
    simde__m256i b = simde_mm256_mask_blend_epi32(simde_test_x86_random_mmask8(), a, simde_test_x86_random_u32x8());
    simde__mmask8 r = simde_mm256_mask_cmpneq_epu32_mask(k1, a, b);

    simde_test_x86_write_mmask8(2, k1, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_u32x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_u32x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_cmpneq_epi64_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int64_t a[4];
    const int64_t b[4];
    const simde__mmask8 r;
  } test_vec[] = {
    { {  INT64_C( 6919654948592371252), -INT64_C( 7965550595212700457), -INT64_C( 6928874164762241056),  INT64_C( 9128223919614953140) },
      {  INT64_C( 6919654948592371252), -INT64_C( 6798605020699028443), -INT64_C( 6928874164762241056), -INT64_C(  922588431330984342) },
      UINT8_C( 10) },
    { { -INT64_C( 1625054179981216708), -INT64_C( 3690616133344655439), -INT64_C( 6654596329976953000), -INT64_C( 4023600627642180928) },
      { -INT64_C( 1625054179981216708),  INT64_C( 1011599854480419087), -INT64_C( 6654596329976953000),  INT64_C( 2422722340083455306) },
      UINT8_C( 10) },
    { {  INT64_C( 2255195888284465076), -INT64_C( 5181985575152547531),  INT64_C( 4640678396798234157), -INT64_C( 7986144531930071788) },
      { -INT64_C( 8192301326302099334),  INT64_C( 3814201469690651811),  INT64_C( 4640678396798234157), -INT64_C( 7986144531930071788) },
      UINT8_C(  3) },
    { {  INT64_C( 6912368174706780977), -INT64_C(  301289202230287526),  INT64_C(  692397981288558317),  INT64_C(  176210833079758388) },
      {  INT64_C( 6912368174706780977),  INT64_C( 8965404135288664926),  INT64_C(  692397981288558317),  INT64_C(  720447400532512811) },
      UINT8_C( 10) },
    { { -INT64_C( 5267830841453365684),  INT64_C( 1192822502880269465),  INT64_C( 2290835837807839714),  INT64_C( 1327506111182849991) },
      {  INT64_C( 4678533745053581429), -INT64_C( 2981125721010982191),  INT64_C( 2290835837807839714),  INT64_C( 5323003885373003015) },
      UINT8_C( 11) },
    { { -INT64_C( 6789807081386770057), -INT64_C( 2649969305104132834),  INT64_C( 7937537001676306912),  INT64_C( 5363941996568507514) },
      { -INT64_C( 6789807081386770057), -INT64_C(  276388514321813158), -INT64_C( 2318435280415319413),  INT64_C( 5363941996568507514) },
      UINT8_C(  6) },
    { { -INT64_C(  364127148702028653),  INT64_C(  491757040571924789),  INT64_C( 2353213313525692206), -INT64_C( 7315408168043695425) },
      { -INT64_C( 7502394026319805025),  INT64_C(  491757040571924789),  INT64_C( 2353213313525692206), -INT64_C( 7315408168043695425) },
      UINT8_C(  1) },
    { { -INT64_C( 6024291605214408230),  INT64_C( 5972883681268217672), -INT64_C( 4469769944038254947), -INT64_C( 8574866139257305823) },
      { -INT64_C( 6024291605214408230),  INT64_C( 5972883681268217672), -INT64_C( 5340048063922805448), -INT64_C( 8574866139257305823) },
      UINT8_C(  4) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256i a = simde_mm256_loadu_epi64(test_vec[i].a);
    simde__m256i b = simde_mm256_loadu_epi64(test_vec[i].b);
    simde__mmask8 r = simde_mm256_cmpneq_epi64_mask(a, b);
    simde_assert_equal_mmask8(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m256i a = simde_test_x86_random_i64x4();
    simde__m256i b = simde_mm256_mask_blend_epi64(simde_test_x86_random_mmask8(), a, simde_test_x86_random_i64x4());
    simde__mmask8 r = simde_mm256_cmpneq_epi64_mask(a, b);

    simde_test_x86_write_i64x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i64x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_mask_cmpneq_epi64_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k1;
    const int64_t a[4];
    const int64_t b[4];
    const simde__mmask8 r;
  } test_vec[] = {
    { UINT8_C( 24),
      {  INT64_C( 5991238671981105186), -INT64_C( 4592567285600422567), -INT64_C( 3395024115577923569), -INT64_C( 7915597032342763908) },
      { -INT64_C( 6008364499405755530), -INT64_C( 4592567285600422567),  INT64_C( 2162611421324586661), -INT64_C( 5481916227252381974) },
      UINT8_C(  8) },
    { UINT8_C(199),
      {  INT64_C(  499543852077011198), -INT64_C( 4874731551745430253),  INT64_C( 4955589172369881772), -INT64_C( 5487894853027691996) },
      {  INT64_C( 7883055656130813668),  INT64_C( 6891617609777166955),  INT64_C( 8163007751854654443), -INT64_C( 5487894853027691996) },
      UINT8_C(  7) },
    { UINT8_C(141),
      {  INT64_C( 6330149848381805113), -INT64_C(  413710028633502692), -INT64_C( 9124112522984648904),  INT64_C( 7348416830271804463) },
      {  INT64_C( 1602119261592339492), -INT64_C(  413710028633502692), -INT64_C( 1069656852042604890), -INT64_C(  525134637637434844) },
      UINT8_C( 13) },
    { UINT8_C(187),
      {  INT64_C(  187466926188468187), -INT64_C( 5635481694936411813), -INT64_C( 2553921975730729883),  INT64_C( 3919911075045532405) },
      {  INT64_C( 6888508537438994537), -INT64_C( 3086419915565190856),  INT64_C( 5025155514374400865),  INT64_C( 3919911075045532405) },
      UINT8_C(  3) },
    { UINT8_C( 47),
      { -INT64_C( 4140128863712289726),  INT64_C( 3575011278073887687),  INT64_C( 2488648025453489372), -INT64_C( 5029446045441274847) },
      {  INT64_C( 6822706697808922925),  INT64_C( 2602213383114541850),  INT64_C( 2488648025453489372), -INT64_C( 5029446045441274847) },
      UINT8_C(  3) },
    { UINT8_C(218),
      { -INT64_C( 7383629284268905587), -INT64_C( 5667677927542304513), -INT64_C( 5533222050225190299), -INT64_C( 2326372738731758186) },
      { -INT64_C( 7383629284268905587), -INT64_C( 5667677927542304513), -INT64_C( 5533222050225190299), -INT64_C( 7293782319376068969) },
      UINT8_C(  8) },
    { UINT8_C(227),
      {  INT64_C( 6998870359877860831), -INT64_C( 5291488758399902108), -INT64_C( 1127527867830194694),  INT64_C( 8343533571943168287) },
      { -INT64_C( 5633914840332348691), -INT64_C( 5291488758399902108), -INT64_C( 1127527867830194694),  INT64_C( 8343533571943168287) },
      UINT8_C(  1) },
    { UINT8_C(149),
      {  INT64_C( 1133522684893015680),  INT64_C( 5454768720491511877),  INT64_C( 1421745843164180744),  INT64_C( 8212740468285562879) },
      {  INT64_C( 1133522684893015680), -INT64_C( 5473816741884366722),  INT64_C( 1421745843164180744),  INT64_C( 8212740468285562879) },
      UINT8_C(  0) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256i a = simde_mm256_loadu_epi64(test_vec[i].a);
    simde__m256i b = simde_mm256_loadu_epi64(test_vec[i].b);
    simde__mmask8 r = simde_mm256_mask_cmpneq_epi64_mask(test_vec[i].k1, a, b);
    simde_assert_equal_mmask8(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k1 = simde_test_x86_random_mmask8();
    simde__m256i a = simde_test_x86_random_i64x4();
    simde__m256i b = simde_mm256_mask_blend_epi64(simde_test_x86_random_mmask8(), a, simde_test_x86_random_i64x4());
    simde__mmask8 r = simde_mm256_mask_cmpneq_epi64_mask(k1, a, b);

    simde_test_x86_write_mmask8(2, k1, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i64x4(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_cmpneq_epu64_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const uint64_t a[4];
    const uint64_t b[4];
    const simde__mmask8 r;
  } test_vec[] = {
    { { UINT64_C( 7508958499971618362), UINT64_C(13057564781669839762), UINT64_C( 9911934572948098627), UINT64_C( 5013456412997358701) },
      { UINT64_C( 5194676451118254263), UINT64_C(13057564781669839762), UINT64_C( 9911934572948098627), UINT64_C( 5013456412997358701) },
      UINT8_C(  1) },
    { { UINT64_C( 6952060514577292321), UINT64_C(14555508053418286241), UINT64_C( 4634879024334647359), UINT64_C( 8634918177407906299) },
      { UINT64_C( 6952060514577292321), UINT64_C( 3899930323119860193), UINT64_C(16190166767911600005), UINT64_C( 8634918177407906299) },
      UINT8_C(  6) },
    { { UINT64_C(13615944436381990607), UINT64_C(16914650942907042786), UINT64_C( 9285489885333891998), UINT64_C( 4369920374713444788) },
      { UINT64_C( 1612646229694522962), UINT64_C(11305454529837602193), UINT64_C( 9285489885333891998), UINT64_C( 4369920374713444788) },
      UINT8_C(  3) },
    { { UINT64_C(11120862499592152191), UINT64_C(16990451052746199434), UINT64_C( 9446695400822004342), UINT64_C(13425000946219355151) },
      { UINT64_C(11120862499592152191), UINT64_C(13278753835164240933), UINT64_C(  892950767190447734), UINT64_C(10910172702411592818) },
      UINT8_C( 14) },
    { { UINT64_C(17357190605639413991), UINT64_C( 1875163774440324594), UINT64_C( 6777394392104166967), UINT64_C(  825067084183682188) },
      { UINT64_C( 7457863631297205674), UINT64_C(15241021837681275364), UINT64_C( 5371244860847200994), UINT64_C(  825067084183682188) },
      UINT8_C(  7) },
    { { UINT64_C(15040953067368128560), UINT64_C( 4686066498927404074), UINT64_C(16963170552665552048), UINT64_C( 7003489060816865496) },
      { UINT64_C(15040953067368128560), UINT64_C( 4686066498927404074), UINT64_C( 2479207725511213245), UINT64_C( 2397373082558642610) },
      UINT8_C( 12) },
    { { UINT64_C(10992363343097709694), UINT64_C( 5728450421420805433), UINT64_C( 1992767389541464587), UINT64_C( 5625940212794821560) },
      { UINT64_C( 7020915181890924702), UINT64_C( 4555569366923716762), UINT64_C( 4979253361153200540), UINT64_C( 5369768135306793319) },
      UINT8_C( 15) },
    { { UINT64_C( 4048235304364482630), UINT64_C( 2349095941181216603), UINT64_C(  153951078649206751), UINT64_C( 2597442144518887709) },
      { UINT64_C( 8493759324889801240), UINT64_C( 2349095941181216603), UINT64_C(  153951078649206751), UINT64_C( 2597442144518887709) },
      UINT8_C(  1) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256i a = simde_mm256_loadu_epi64(test_vec[i].a);
    simde__m256i b = simde_mm256_loadu_epi64(test_vec[i].b);
    simde__mmask8 r = simde_mm256_cmpneq_epu64_mask(a, b);
    simde_assert_equal_mmask8(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m256i a = simde_test_x86_random_u64x4();
    simde__m256i b = simde_mm256_mask_blend_epi64(simde_test_x86_random_mmask8(), a, simde_test_x86_random_u64x4());
    simde__mmask8 r = simde_mm256_cmpneq_epu64_mask(a, b);

    simde_test_x86_write_u64x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_u64x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_mask_cmpneq_epu64_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k1;
    const uint64_t a[4];
    const uint64_t b[4];
    const simde__mmask8 r;
  } test_vec[] = {
    { UINT8_C(196),
      { UINT64_C( 8423321203886361786), UINT64_C( 4500542638721653489), UINT64_C( 3013465215719210615), UINT64_C(11075241950410493155) },
      { UINT64_C( 8423321203886361786), UINT64_C( 5107300568226966515), UINT64_C(12543620951613624389), UINT64_C(12261421575611206576) },
      UINT8_C(  4) },
    { UINT8_C( 92),
      { UINT64_C(17813821911322702177), UINT64_C( 6898109783627073034), UINT64_C(15117726553355880173), UINT64_C(14774569213450436996) },
      { UINT64_C(17813821911322702177), UINT64_C( 6898109783627073034), UINT64_C(18384141709795362332), UINT64_C(14774569213450436996) },
      UINT8_C(  4) },
    { UINT8_C(234),
      { UINT64_C(16624494916620982973), UINT64_C( 3152124323942929653), UINT64_C(16450834941350132200), UINT64_C(13067984835205292767) },
      { UINT64_C(16624494916620982973), UINT64_C(15376930618073306587), UINT64_C(16450834941350132200), UINT64_C(13067984835205292767) },
      UINT8_C(  2) },
    { UINT8_C(203),
      { UINT64_C(11501891672226311023), UINT64_C( 4662775245196987175), UINT64_C(12445973663410092232), UINT64_C( 3857433989985356673) },
      { UINT64_C(12623058174119680518), UINT64_C( 4662775245196987175), UINT64_C(12445973663410092232), UINT64_C( 3857433989985356673) },
      UINT8_C(  1) },
    { UINT8_C( 91),
      { UINT64_C( 9513606034132277559), UINT64_C(17520231896535345703), UINT64_C(17606657842508059745), UINT64_C(15729241312306395665) },
      { UINT64_C(  496036834137063446), UINT64_C(17520231896535345703), UINT64_C( 9036892027759231342), UINT64_C(15729241312306395665) },
      UINT8_C(  1) },
    { UINT8_C( 51),
      { UINT64_C(15059731879051285701), UINT64_C(17287868481314403184), UINT64_C( 4506665970792486221), UINT64_C(  659329036504521982) },
      { UINT64_C(15059731879051285701), UINT64_C(17287868481314403184), UINT64_C( 7724719468763252770), UINT64_C(  659329036504521982) },
      UINT8_C(  0) },
    { UINT8_C(144),
      { UINT64_C(10132152109655633507), UINT64_C( 7670328621203572430), UINT64_C(12162451600859848560), UINT64_C(  503365921183389836) },
      { UINT64_C(12408804413874978047), UINT64_C( 7670328621203572430), UINT64_C(12162451600859848560), UINT64_C(  503365921183389836) },
      UINT8_C(  0) },
    { UINT8_C( 57),
      { UINT64_C( 9277091886594932733), UINT64_C( 6673892919562782665), UINT64_C(13006255585392512927), UINT64_C( 2919240941080008034) },
      { UINT64_C( 5468522795843103097), UINT64_C( 8825943505004031199), UINT64_C(11608998081130118875), UINT64_C( 2919240941080008034) },
      UINT8_C(  1) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256i a = simde_mm256_loadu_epi64(test_vec[i].a);
    simde__m256i b = simde_mm256_loadu_epi64(test_vec[i].b);
    simde__mmask8 r = simde_mm256_mask_cmpneq_epu64_mask(test_vec[i].k1, a, b);
    simde_assert_equal_mmask8(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k1 = simde_test_x86_random_mmask8();
    simde__m256i a = simde_test_x86_random_u64x4();
    simde__m256i b = simde_mm256_mask_blend_epi64(simde_test_x86_random_mmask8(), a, simde_test_x86_random_u64x4());
    simde__mmask8 r = simde_mm256_mask_cmpneq_epu64_mask(k1, a, b);

    simde_test_x86_write_mmask8(2, k1, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_u64x4(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_u64x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_cmpneq_epi8_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_mask_cmpneq_epi8_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_cmpneq_epu8_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_mask_cmpneq_epu8_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_cmpneq_epi16_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_mask_cmpneq_epi16_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_cmpneq_epu16_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_mask_cmpneq_epu16_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_cmpneq_epi32_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_mask_cmpneq_epi32_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_cmpneq_epu32_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_mask_cmpneq_epu32_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_cmpneq_epi64_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_mask_cmpneq_epi64_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_cmpneq_epu64_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_mask_cmpneq_epu64_mask)

  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_cmpneq_epi8_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_mask_cmpneq_epi8_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_cmpneq_epu8_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_mask_cmpneq_epu8_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_cmpneq_epi16_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_mask_cmpneq_epi16_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_cmpneq_epu16_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_mask_cmpneq_epu16_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_cmpneq_epi32_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_mask_cmpneq_epi32_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_cmpneq_epu32_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_mask_cmpneq_epu32_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_cmpneq_epi64_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_mask_cmpneq_epi64_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_cmpneq_epu64_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_mask_cmpneq_epu64_mask)
SIMDE_TEST_FUNC_LIST_END

#include <test/x86/avx512/test-avx512-footer.h>
