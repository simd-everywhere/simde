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
 *   2025      Michael R. Crusoe <crusoe@debian.org>
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
test_simde_mm512_cmpneq_epi8_mask(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int8_t a[64];
    const int8_t b[64];
    const simde__mmask64 r;
  } test_vec[8] = {
    { { -INT8_C(  27), -INT8_C(   4),  INT8_C(  33),  INT8_C( 109),  INT8_C(  13),  INT8_C(  47),  INT8_C(  59), -INT8_C( 119),
         INT8_C( 104),  INT8_C(  88),  INT8_C(   0), -INT8_C(  69),  INT8_C(  24),  INT8_C(  94), -INT8_C(  22),  INT8_C(  35),
        -INT8_C(  52), -INT8_C(   5), -INT8_C( 124),  INT8_C(  65), -INT8_C( 105),  INT8_C( 116), -INT8_C(  43),  INT8_C( 106),
        -INT8_C(  52), -INT8_C(   7), -INT8_C(  43),  INT8_C( 110), -INT8_C( 127), -INT8_C( 125),  INT8_C(  34),  INT8_C( 102),
             INT8_MAX,  INT8_C(  67), -INT8_C(  45), -INT8_C( 115),  INT8_C( 114),  INT8_C(  15),  INT8_C(  22), -INT8_C(  37),
         INT8_C( 103),  INT8_C(  23), -INT8_C( 106),      INT8_MIN,  INT8_C( 117),      INT8_MIN, -INT8_C(  93),  INT8_C(  66),
         INT8_C( 123),  INT8_C(  39), -INT8_C( 125),  INT8_C(  18), -INT8_C( 101),  INT8_C(  88),  INT8_C( 125),  INT8_C( 104),
         INT8_C(  81),  INT8_C(  82), -INT8_C(  42), -INT8_C(  46), -INT8_C(  43), -INT8_C(   8),  INT8_C(  56),  INT8_C(  85) },
      { -INT8_C(  27), -INT8_C(   4),  INT8_C(  33),  INT8_C( 109),  INT8_C(  13),  INT8_C(  47), -INT8_C( 119), -INT8_C( 126),
         INT8_C(  15),  INT8_C(  31),  INT8_C(   0), -INT8_C(  69),  INT8_C(  24),  INT8_C(  94), -INT8_C(  22),  INT8_C(  35),
        -INT8_C(  51),  INT8_C(  74),  INT8_C(  45),  INT8_C(  65), -INT8_C(  93), -INT8_C(  86), -INT8_C(  43),  INT8_C( 106),
        -INT8_C(   4), -INT8_C(   7), -INT8_C(  43),  INT8_C( 110), -INT8_C( 127), -INT8_C( 125),  INT8_C(  38), -INT8_C(  37),
             INT8_MAX,  INT8_C(   8), -INT8_C( 118), -INT8_C( 115),  INT8_C(   1),  INT8_C(  15),  INT8_C(  22), -INT8_C(  37),
         INT8_C( 103),  INT8_C(  23), -INT8_C( 106),      INT8_MIN,  INT8_C( 117),  INT8_C(  92), -INT8_C(  19),  INT8_C(  30),
         INT8_C( 123),  INT8_C(  26), -INT8_C( 125),  INT8_C(  18), -INT8_C(  60),  INT8_C(  88),  INT8_C(  62), -INT8_C(  64),
        -INT8_C(   2),  INT8_C(  82), -INT8_C(  42), -INT8_C(  99), -INT8_C(  43), -INT8_C(   8),  INT8_C( 121),  INT8_C(  85) },
      UINT64_C( 5319560498213487552) },
    { { -INT8_C( 117),  INT8_C( 103),  INT8_C(  28), -INT8_C(  36), -INT8_C(  60),  INT8_C(   9), -INT8_C(   6),  INT8_C( 107),
         INT8_C(  35), -INT8_C( 127), -INT8_C(  75), -INT8_C(  25), -INT8_C(  40), -INT8_C(  13), -INT8_C(  89), -INT8_C(  42),
        -INT8_C(   7),  INT8_C(  56),  INT8_C( 115), -INT8_C(   2), -INT8_C(  16), -INT8_C(  20),  INT8_C(  14), -INT8_C(  79),
        -INT8_C(  17),  INT8_C(  69),  INT8_C( 114),  INT8_C(   6),  INT8_C(  37),  INT8_C(  68),  INT8_C(  79), -INT8_C(  79),
        -INT8_C(  84),  INT8_C( 107), -INT8_C( 115),  INT8_C( 112),  INT8_C( 116), -INT8_C( 120), -INT8_C(  37), -INT8_C( 105),
         INT8_C(   9), -INT8_C( 112),  INT8_C( 126), -INT8_C(  31), -INT8_C( 125),  INT8_C(  37), -INT8_C(  73),  INT8_C( 124),
         INT8_C(  94),  INT8_C(  42),  INT8_C( 122),  INT8_C(  78),  INT8_C(  23), -INT8_C( 119), -INT8_C(   1),  INT8_C(   6),
        -INT8_C(  50),  INT8_C( 114),  INT8_C(  12), -INT8_C(  12), -INT8_C(  74),  INT8_C(  92), -INT8_C(  91),  INT8_C(  98) },
      { -INT8_C( 117),  INT8_C(  50),  INT8_C(  28),  INT8_C(  60), -INT8_C(  70),  INT8_C(   9), -INT8_C(  45), -INT8_C(  61),
         INT8_C(  35),  INT8_C(  82), -INT8_C(  92), -INT8_C(  63),  INT8_C( 119),  INT8_C(  91), -INT8_C(  89), -INT8_C(  43),
        -INT8_C( 122), -INT8_C(  72),  INT8_C(  36), -INT8_C(  99), -INT8_C(  16), -INT8_C(  20),  INT8_C(  14),  INT8_C(  15),
        -INT8_C( 107),  INT8_C(  69),  INT8_C( 114),  INT8_C(  76),  INT8_C(  37),  INT8_C(  68),  INT8_C(  79), -INT8_C(  79),
        -INT8_C(  37),  INT8_C( 107), -INT8_C( 115),  INT8_C( 112),  INT8_C( 116), -INT8_C(  29), -INT8_C(  37),  INT8_C( 108),
         INT8_C(   9), -INT8_C( 112),  INT8_C( 126), -INT8_C(  84), -INT8_C( 125),  INT8_C( 106), -INT8_C( 126), -INT8_C(  33),
         INT8_C(  34),  INT8_C(  42),  INT8_C( 124),  INT8_C(  78), -INT8_C(  55),  INT8_C(  31),  INT8_C( 115),  INT8_C(   6),
        -INT8_C(  50),  INT8_C( 118), -INT8_C(  85), -INT8_C(  12),  INT8_C(  31),  INT8_C(  92), -INT8_C(  81), -INT8_C(   6) },
      UINT64_C(15453513474739519194) },
    { { -INT8_C(  26), -INT8_C(  94), -INT8_C( 125),  INT8_C(  63),  INT8_C(  12),  INT8_C(   5),  INT8_C(  30),  INT8_C(  47),
        -INT8_C(  85), -INT8_C( 102), -INT8_C( 110),  INT8_C( 116), -INT8_C(  71),  INT8_C(   5), -INT8_C(  45), -INT8_C( 119),
         INT8_C( 124),  INT8_C( 126),  INT8_C( 100), -INT8_C( 101), -INT8_C(  40),  INT8_C(  19), -INT8_C( 107), -INT8_C(  78),
        -INT8_C(  46),  INT8_C(  36), -INT8_C(  69),  INT8_C( 115),  INT8_C(  13),  INT8_C(  48),  INT8_C(  74), -INT8_C(  13),
        -INT8_C(  46), -INT8_C(  51),  INT8_C(  50), -INT8_C(  33), -INT8_C(  46),  INT8_C(  80),  INT8_C(  14),  INT8_C( 125),
        -INT8_C(  22), -INT8_C(  96), -INT8_C(  15), -INT8_C(  93), -INT8_C(  90), -INT8_C(  59),  INT8_C(  44),  INT8_C(  34),
         INT8_C(  67), -INT8_C( 111), -INT8_C(  67),  INT8_C(  27), -INT8_C(  92),  INT8_C(  82), -INT8_C(  50),  INT8_C( 118),
         INT8_C( 118), -INT8_C( 119), -INT8_C(  22), -INT8_C( 125), -INT8_C(  70),  INT8_C(  52),  INT8_C( 118), -INT8_C( 116) },
      { -INT8_C(  26), -INT8_C(  88), -INT8_C( 125),  INT8_C(  63), -INT8_C(   8),  INT8_C( 121),  INT8_C(  80),  INT8_C(  47),
        -INT8_C(  85),  INT8_C(  65), -INT8_C( 110), -INT8_C(  64),  INT8_C(   6), -INT8_C(  78), -INT8_C(  45), -INT8_C( 119),
         INT8_C(  67),  INT8_C( 126),  INT8_C( 101), -INT8_C( 101), -INT8_C(  15),  INT8_C(  51),  INT8_C(  94),  INT8_C( 103),
        -INT8_C(  46),  INT8_C(  72), -INT8_C(  69),  INT8_C( 119),  INT8_C( 124),  INT8_C(  48),  INT8_C(   3), -INT8_C(  13),
         INT8_C(  10),  INT8_C( 111),  INT8_C(  50),  INT8_C(   2), -INT8_C(  24),  INT8_C(  80), -INT8_C(  27),  INT8_C(   2),
        -INT8_C(  22),  INT8_C( 107), -INT8_C(  15), -INT8_C(  24),  INT8_C(  29), -INT8_C(  59),  INT8_C(  50),  INT8_C(  97),
         INT8_C(  67), -INT8_C( 111),  INT8_C(  73),  INT8_C(  52), -INT8_C(  53),  INT8_C(  82), -INT8_C( 100),  INT8_C( 118),
        -INT8_C(  16), -INT8_C( 119), -INT8_C(   1),  INT8_C( 108), -INT8_C(  24),  INT8_C(   3),  INT8_C( 118), -INT8_C(  14) },
      UINT64_C(13645021606684473970) },
    { {  INT8_C(  69),  INT8_C(  31), -INT8_C(  91),  INT8_C(  98), -INT8_C(  60), -INT8_C(  40), -INT8_C(  61),  INT8_C(   7),
         INT8_C( 112),  INT8_C(  12),  INT8_C(  60),  INT8_C(  59), -INT8_C(  76), -INT8_C(  40), -INT8_C(  60), -INT8_C(  92),
         INT8_C(  95), -INT8_C(  61),  INT8_C(  16),  INT8_C(  71), -INT8_C(  58), -INT8_C(   6),  INT8_C(  58),  INT8_C(  56),
         INT8_C(  53),  INT8_C(  47), -INT8_C( 109),  INT8_C(  16),  INT8_C(   9), -INT8_C(  16), -INT8_C(  51),  INT8_C(  78),
         INT8_C(  15),  INT8_C( 114), -INT8_C(  80), -INT8_C(  45),  INT8_C(  74),  INT8_C( 116), -INT8_C(  37), -INT8_C(  70),
             INT8_MIN,  INT8_C(  23), -INT8_C(  10),  INT8_C(  52), -INT8_C(  17), -INT8_C(  70), -INT8_C(  40),  INT8_C(  78),
         INT8_C( 125), -INT8_C(  23), -INT8_C( 107),  INT8_C(  68), -INT8_C(  29), -INT8_C(  49),  INT8_C( 124),  INT8_C(  24),
        -INT8_C(   2),  INT8_C(  15),  INT8_C(  40),  INT8_C(   7), -INT8_C(   1), -INT8_C(  11),  INT8_C(  85),  INT8_C(  15) },
      {  INT8_C( 104),  INT8_C(   6), -INT8_C(  30), -INT8_C(  78), -INT8_C(  60), -INT8_C(  40), -INT8_C(  61), -INT8_C(   6),
        -INT8_C(  44),  INT8_C(  99),  INT8_C(  60), -INT8_C(  61), -INT8_C(  76),  INT8_C(   7),  INT8_C(  17), -INT8_C( 102),
        -INT8_C(  16), -INT8_C(  61), -INT8_C(  34), -INT8_C(  44), -INT8_C(  58), -INT8_C(   6), -INT8_C(  20),  INT8_C( 117),
         INT8_C(  53),  INT8_C(  47), -INT8_C( 109),  INT8_C( 106),  INT8_C(   9), -INT8_C(  46), -INT8_C(  51),  INT8_C( 114),
        -INT8_C(  40),  INT8_C( 114),  INT8_C(  37),  INT8_C(  82),  INT8_C(  25), -INT8_C( 110),  INT8_C(  76), -INT8_C(  70),
             INT8_MIN,  INT8_C( 123), -INT8_C(  10),  INT8_C(  18), -INT8_C( 125), -INT8_C(  70), -INT8_C(  40),  INT8_C(  78),
         INT8_C( 105), -INT8_C(  23),  INT8_C(  71),  INT8_C(  68), -INT8_C(  26), -INT8_C(  49),  INT8_C( 124),  INT8_C(  80),
        -INT8_C(   2), -INT8_C(  47),  INT8_C(  40),  INT8_C(   7), -INT8_C(  93),  INT8_C(  51), -INT8_C(  58),  INT8_C(  15) },
      UINT64_C( 8256534618858974095) },
    { { -INT8_C( 107),  INT8_C(  70), -INT8_C( 124),  INT8_C(  24),  INT8_C(   9),  INT8_C(  48), -INT8_C( 116),  INT8_C( 114),
        -INT8_C(  69), -INT8_C(  45),  INT8_C(  82), -INT8_C(  95),  INT8_C(   7), -INT8_C(  89), -INT8_C(  14),  INT8_C(  80),
         INT8_C( 121), -INT8_C(  84), -INT8_C(  92),  INT8_C(  28), -INT8_C(  32),  INT8_C( 106), -INT8_C( 104),  INT8_C( 111),
         INT8_C(  85),  INT8_C( 101),  INT8_C(  23), -INT8_C(  46),      INT8_MAX, -INT8_C(  84),  INT8_C(  68),  INT8_C(  21),
        -INT8_C(  13), -INT8_C(  56),  INT8_C(  45), -INT8_C(   4), -INT8_C(   8), -INT8_C(  71),  INT8_C( 110), -INT8_C(  76),
        -INT8_C( 115), -INT8_C(  63),  INT8_C(  85), -INT8_C( 108),  INT8_C( 104),  INT8_C(  71), -INT8_C(  27), -INT8_C(  31),
        -INT8_C(  12), -INT8_C( 119), -INT8_C(   2), -INT8_C(  44), -INT8_C(  13), -INT8_C( 106),  INT8_C(  67),  INT8_C(  72),
        -INT8_C(   5),  INT8_C(  90),  INT8_C(  26),  INT8_C( 123),  INT8_C(   6),  INT8_C(  94), -INT8_C( 112), -INT8_C(   7) },
      {  INT8_C(  38), -INT8_C(  67), -INT8_C( 124),  INT8_C(  30),  INT8_C(   9),  INT8_C(  48), -INT8_C(  46),  INT8_C(   4),
        -INT8_C(  69), -INT8_C(  45), -INT8_C( 104), -INT8_C( 115),  INT8_C(   7), -INT8_C(  89), -INT8_C(  14),  INT8_C(  99),
         INT8_C( 121),  INT8_C( 109),  INT8_C(  55),  INT8_C(  28), -INT8_C(  32),  INT8_C( 106),  INT8_C(  65),  INT8_C( 111),
        -INT8_C(  44),  INT8_C( 101),  INT8_C(  23), -INT8_C(  37), -INT8_C(  71),  INT8_C(   9), -INT8_C(  44), -INT8_C(  33),
        -INT8_C(  13), -INT8_C(  56), -INT8_C(   2),  INT8_C(  62),  INT8_C(  46), -INT8_C(  71),  INT8_C(  66), -INT8_C(  76),
        -INT8_C( 115), -INT8_C(  63),  INT8_C(  85),  INT8_C( 104),  INT8_C( 104),  INT8_C(  71), -INT8_C(  27),  INT8_C(  94),
        -INT8_C(  12), -INT8_C( 119),  INT8_C(  88), -INT8_C(  65), -INT8_C(  13), -INT8_C( 106), -INT8_C(  66),  INT8_C(  72),
        -INT8_C(  11),  INT8_C(  90),  INT8_C(  45),  INT8_C( 123),  INT8_C(  65),  INT8_C(  94), -INT8_C( 114), -INT8_C(   7) },
      UINT64_C( 6146437524354403531) },
    { {  INT8_C(  98),  INT8_C(  45), -INT8_C(  67), -INT8_C(  70),  INT8_C( 124), -INT8_C( 120),  INT8_C(  25),  INT8_C(  57),
        -INT8_C( 117),  INT8_C( 113), -INT8_C(   8),  INT8_C(   9),  INT8_C(  10), -INT8_C(  74),  INT8_C(  91), -INT8_C(   1),
        -INT8_C(  18), -INT8_C( 120), -INT8_C(  82),  INT8_C(  47), -INT8_C( 119),  INT8_C(  60),  INT8_C(  55),  INT8_C(  85),
        -INT8_C(  56),  INT8_C( 125),  INT8_C(  78),  INT8_C(  36),  INT8_C(   5), -INT8_C( 101),  INT8_C( 121),  INT8_C( 103),
        -INT8_C(  56),  INT8_C(  54),  INT8_C(  34),  INT8_C(  68), -INT8_C(  65),  INT8_C(  59),  INT8_C( 125),  INT8_C(  74),
        -INT8_C(  84),  INT8_C( 118),  INT8_C(  83), -INT8_C(  74),  INT8_C(  44), -INT8_C(  82), -INT8_C(  74),  INT8_C(  26),
         INT8_C(  54),  INT8_C( 100),  INT8_C(  73), -INT8_C(  64), -INT8_C(  96),      INT8_MIN,  INT8_C(  21),  INT8_C( 104),
        -INT8_C(   3),  INT8_C(  99), -INT8_C( 116),  INT8_C(   2), -INT8_C(   2),  INT8_C(   6),  INT8_C( 106), -INT8_C(  58) },
      {  INT8_C(  60),  INT8_C(  45),  INT8_C(  11), -INT8_C(   5), -INT8_C(  57), -INT8_C( 120),  INT8_C(  25),  INT8_C( 115),
        -INT8_C(   2),  INT8_C( 113), -INT8_C(   8),  INT8_C(   9),  INT8_C(  10), -INT8_C(  33),  INT8_C(  91),  INT8_C( 126),
         INT8_C(  67), -INT8_C( 120),  INT8_C(  62),  INT8_C(  47), -INT8_C( 119),  INT8_C(  60),  INT8_C(  55),  INT8_C(  13),
        -INT8_C(  73),  INT8_C( 125),  INT8_C(  15), -INT8_C(  75),  INT8_C(   5), -INT8_C( 101),  INT8_C( 124),  INT8_C(  26),
         INT8_C(   5),  INT8_C(  54),  INT8_C(  22), -INT8_C(  52),  INT8_C(  15),  INT8_C(  92),  INT8_C(  63),  INT8_C(  14),
        -INT8_C(  84),  INT8_C( 118),  INT8_C(  57), -INT8_C(  74),  INT8_C(  44), -INT8_C(  82), -INT8_C(  68), -INT8_C( 116),
         INT8_C(  13), -INT8_C(   6),  INT8_C(  73),  INT8_C(  29),  INT8_C(  78),      INT8_MIN,  INT8_C(  42),  INT8_C(   5),
        -INT8_C( 109),  INT8_C(  57), -INT8_C( 116),  INT8_C(   2), -INT8_C(  77),  INT8_C(  54), -INT8_C( 117), -INT8_C(  72) },
      UINT64_C(17571854965469979037) },
    { {  INT8_C(  45),  INT8_C(  20),  INT8_C(  48),  INT8_C( 118), -INT8_C( 110), -INT8_C(  20),  INT8_C(   2), -INT8_C(  96),
        -INT8_C(  25),  INT8_C( 113), -INT8_C(  67),  INT8_C(  53),  INT8_C(  44), -INT8_C(  25),  INT8_C(  58), -INT8_C(  65),
         INT8_C(  32), -INT8_C(  12),  INT8_C(  48), -INT8_C(  45),  INT8_C(  43), -INT8_C(  68), -INT8_C( 116), -INT8_C(  24),
         INT8_C(  93),  INT8_C(  17), -INT8_C(  75),  INT8_C(  91), -INT8_C(  43), -INT8_C( 112),  INT8_C(  78),  INT8_C(   3),
        -INT8_C(  92),  INT8_C( 126),  INT8_C( 121),  INT8_C(  55),  INT8_C( 107),  INT8_C( 123), -INT8_C(  41),  INT8_C(  82),
        -INT8_C(  20), -INT8_C( 108), -INT8_C( 121),  INT8_C(  25),  INT8_C( 123), -INT8_C(  63), -INT8_C(  40), -INT8_C( 101),
        -INT8_C(  75),  INT8_C(   9),  INT8_C( 111), -INT8_C(  32), -INT8_C(  59), -INT8_C(   5), -INT8_C(  55),  INT8_C(  34),
         INT8_C(  12),  INT8_C( 126),  INT8_C( 125), -INT8_C(  31),  INT8_C(  15), -INT8_C(  53), -INT8_C(  28), -INT8_C(  77) },
      {  INT8_C(  74),  INT8_C(  93),  INT8_C(  48), -INT8_C(  75), -INT8_C(  40), -INT8_C(  20),  INT8_C(   2), -INT8_C(  59),
        -INT8_C(  25),  INT8_C( 113), -INT8_C(  67),  INT8_C(  53),  INT8_C(  44), -INT8_C(  74),  INT8_C( 108), -INT8_C(  65),
        -INT8_C(  65), -INT8_C(  37), -INT8_C(  27), -INT8_C( 124),  INT8_C(  43), -INT8_C(  68), -INT8_C( 116), -INT8_C(  24),
         INT8_C(  93),  INT8_C(  36), -INT8_C(  61),  INT8_C(  91), -INT8_C(  16), -INT8_C(  88),  INT8_C(  78),  INT8_C(   3),
        -INT8_C(  92), -INT8_C(  39), -INT8_C(  17),  INT8_C(  55), -INT8_C( 101),  INT8_C( 123), -INT8_C(  93),  INT8_C(  82),
        -INT8_C(  20), -INT8_C( 127), -INT8_C( 121),  INT8_C(  25),  INT8_C(  55),  INT8_C(  45), -INT8_C(  40), -INT8_C(   9),
        -INT8_C(  75), -INT8_C(  68),  INT8_C( 123), -INT8_C(  32), -INT8_C(  59),  INT8_C(  34), -INT8_C(  55),  INT8_C(  34),
         INT8_C(  12), -INT8_C( 125),  INT8_C( 125),  INT8_C(  55),  INT8_C(  43), -INT8_C(  53),  INT8_C( 113),  INT8_C(  49) },
      UINT64_C(15719447632727203995) },
    { {  INT8_C(  51), -INT8_C(  25), -INT8_C(  83),  INT8_C( 106),  INT8_C(  20), -INT8_C( 124),  INT8_C(  97),  INT8_C(  28),
         INT8_C(  65), -INT8_C(  35), -INT8_C(   6), -INT8_C(  85), -INT8_C(   1), -INT8_C(  70),  INT8_C(  66),  INT8_C(  70),
         INT8_C(  62),  INT8_C(  21),  INT8_C( 125),  INT8_C( 105), -INT8_C(  42), -INT8_C(  18), -INT8_C( 102),  INT8_C( 113),
         INT8_C(  78), -INT8_C(  87), -INT8_C(  89), -INT8_C(  92),  INT8_C(  91), -INT8_C(  50),  INT8_C( 126), -INT8_C( 114),
        -INT8_C(  75),  INT8_C(  43), -INT8_C(   7), -INT8_C(  54), -INT8_C(  80),  INT8_C(  90), -INT8_C(  26), -INT8_C(  15),
         INT8_C(  55), -INT8_C(  31), -INT8_C( 100),  INT8_C(  55), -INT8_C( 101), -INT8_C(  33),  INT8_C( 125), -INT8_C(  39),
        -INT8_C(  12), -INT8_C(   5),  INT8_C(  67), -INT8_C(  54), -INT8_C(  23), -INT8_C(  35),  INT8_C(  60),  INT8_C(  56),
        -INT8_C( 121), -INT8_C(  29), -INT8_C(  36), -INT8_C(  30), -INT8_C(  79),  INT8_C(  91),  INT8_C( 113),  INT8_C( 103) },
      { -INT8_C( 122), -INT8_C(  25),  INT8_C(  49),  INT8_C(  54), -INT8_C(  60),  INT8_C(  23),  INT8_C(  39), -INT8_C(   4),
         INT8_C(  65), -INT8_C(  60),  INT8_C(  51), -INT8_C( 108), -INT8_C(  93), -INT8_C(  80),  INT8_C( 109),  INT8_C(  70),
        -INT8_C(  85),  INT8_C(  21),  INT8_C( 125), -INT8_C( 107), -INT8_C( 114), -INT8_C(  99), -INT8_C(  51),  INT8_C(  21),
        -INT8_C( 127), -INT8_C(  87), -INT8_C(   9),  INT8_C(  50),  INT8_C(   4), -INT8_C(  50), -INT8_C( 103), -INT8_C( 117),
        -INT8_C(  46), -INT8_C(  54), -INT8_C(  63), -INT8_C(  54), -INT8_C(  80), -INT8_C(  23), -INT8_C( 109), -INT8_C(  15),
         INT8_C(  55), -INT8_C(  31),  INT8_C( 110),  INT8_C(  80), -INT8_C( 101), -INT8_C(  33),  INT8_C( 125),  INT8_C(  34),
        -INT8_C(  12),  INT8_C(  72),  INT8_C(  67),  INT8_C(  26), -INT8_C(  26), -INT8_C( 124),  INT8_C(  60),  INT8_C( 103),
        -INT8_C( 121), -INT8_C(  29), -INT8_C( 103), -INT8_C(  30), -INT8_C( 113),  INT8_C(  91),  INT8_C( 113),  INT8_C( 103) },
      UINT64_C( 1493660604160376573) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512i a = simde_mm512_loadu_epi8(test_vec[i].a);
    simde__m512i b = simde_mm512_loadu_epi8(test_vec[i].b);
    simde__mmask64 r = simde_mm512_cmpneq_epi8_mask(a, b);
    simde_assert_equal_mmask64(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m512i a = simde_test_x86_random_i8x64();
    simde__m512i b = simde_mm512_mask_blend_epi8(simde_test_x86_random_mmask64(), a, simde_test_x86_random_i8x64());
    simde__mmask64 r = simde_mm512_cmpneq_epi8_mask(a, b);

    simde_test_x86_write_i8x64(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i8x64(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask64(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_mask_cmpneq_epi8_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask64 k1;
    const int8_t a[64];
    const int8_t b[64];
    const simde__mmask64 r;
  } test_vec[] = {
    { UINT64_C(13598207540318556649),
      {  INT8_C(  25),  INT8_C( 112), -INT8_C(  68),  INT8_C(   7),  INT8_C(  20),  INT8_C(  64), -INT8_C(  95),  INT8_C(  40),
         INT8_C(  36),  INT8_C( 124),  INT8_C( 114),  INT8_C( 123),  INT8_C(  87),  INT8_C(  64),  INT8_C( 108),  INT8_C(  75),
        -INT8_C( 108),  INT8_C(  30),  INT8_C(  49), -INT8_C(  41), -INT8_C(   3),  INT8_C(  46),  INT8_C(  70), -INT8_C(  26),
        -INT8_C(   1), -INT8_C(   1),  INT8_C(  12), -INT8_C(  75), -INT8_C( 120), -INT8_C(  62),  INT8_C( 113), -INT8_C(  95),
         INT8_C(  51),  INT8_C(  45), -INT8_C(  88),  INT8_C(  71),  INT8_C( 109),  INT8_C(  73),  INT8_C( 111), -INT8_C( 110),
        -INT8_C(  59), -INT8_C(  31),  INT8_C(  13),  INT8_C(  29),  INT8_C(  33),  INT8_C( 121),  INT8_C( 104), -INT8_C(  74),
        -INT8_C( 104), -INT8_C( 103), -INT8_C( 115), -INT8_C( 107), -INT8_C(  57), -INT8_C(  45),  INT8_C( 123), -INT8_C(  57),
        -INT8_C(  46), -INT8_C( 121),  INT8_C( 124),  INT8_C(  91),  INT8_C(  74), -INT8_C(  18), -INT8_C(   4),  INT8_C( 125) },
      {  INT8_C(  25), -INT8_C(  91), -INT8_C(  60),  INT8_C(   7),  INT8_C(  20),  INT8_C(  64), -INT8_C(  95), -INT8_C(  76),
         INT8_C(  36),  INT8_C(  40),  INT8_C( 114),  INT8_C( 123), -INT8_C(  95),  INT8_C(  64),  INT8_C( 108),  INT8_C(  57),
        -INT8_C( 108),  INT8_C(  30),  INT8_C(  49), -INT8_C( 103), -INT8_C(   3),  INT8_C(  46),  INT8_C(  96),  INT8_C(  31),
        -INT8_C(   1), -INT8_C(  35),  INT8_C( 122), -INT8_C(  75), -INT8_C(  53), -INT8_C(  62),  INT8_C( 113), -INT8_C(  95),
         INT8_C(  28),  INT8_C(  45),  INT8_C( 111),  INT8_C(  10), -INT8_C( 112),  INT8_C(  73),  INT8_C( 111), -INT8_C( 110),
        -INT8_C(  78), -INT8_C( 113), -INT8_C(  35),  INT8_C(  29),  INT8_C(  33),  INT8_C( 121),  INT8_C( 104), -INT8_C( 102),
        -INT8_C( 104), -INT8_C( 103),  INT8_C(  52), -INT8_C( 111), -INT8_C(  91), -INT8_C( 108),  INT8_C( 123),  INT8_C( 118),
         INT8_C( 113),  INT8_C(  43), -INT8_C( 111),  INT8_C(  60),  INT8_C(  74), -INT8_C(  18),  INT8_C(  35), -INT8_C(  66) },
      UINT64_C(10138870584126771328) },
    { UINT64_C(12067871719019485462),
      {  INT8_C(  13), -INT8_C(  83),  INT8_C(  56), -INT8_C(  78),  INT8_C(  66), -INT8_C(  23),  INT8_C(  41), -INT8_C(  77),
         INT8_C(  20), -INT8_C(  70), -INT8_C(  16), -INT8_C(  74), -INT8_C(  28),  INT8_C(  19),  INT8_C( 116),  INT8_C( 106),
        -INT8_C(  91),  INT8_C(  60),      INT8_MIN, -INT8_C(  62), -INT8_C(  61),  INT8_C(  61), -INT8_C( 110), -INT8_C(  38),
        -INT8_C(  42), -INT8_C(  75), -INT8_C(  71),  INT8_C(  58),  INT8_C( 102),  INT8_C(  50), -INT8_C(  31),  INT8_C( 115),
        -INT8_C(  32),  INT8_C(  26),  INT8_C(  38),  INT8_C(  34),  INT8_C(   3),  INT8_C(  79), -INT8_C(  43),  INT8_C(  23),
         INT8_C(   9), -INT8_C(  59), -INT8_C(  51), -INT8_C(  19), -INT8_C(  40),  INT8_C(  65),  INT8_C(  87),  INT8_C( 126),
         INT8_C( 125), -INT8_C(  40),  INT8_C(  64),  INT8_C(  65),  INT8_C(  21), -INT8_C(  46),  INT8_C(  27), -INT8_C(  21),
        -INT8_C( 120), -INT8_C(  44),  INT8_C(  37), -INT8_C(  18),  INT8_C(   6),  INT8_C(   7),  INT8_C(  98), -INT8_C(  26) },
      {  INT8_C(  33), -INT8_C( 120),  INT8_C(   8),  INT8_C(  36),  INT8_C(  66), -INT8_C(  34),  INT8_C(  41), -INT8_C(  32),
        -INT8_C(  93),  INT8_C(   8), -INT8_C(  50),  INT8_C( 124), -INT8_C(  28),  INT8_C(  37),  INT8_C( 116),  INT8_C( 106),
        -INT8_C(   3),  INT8_C(  58),      INT8_MIN,  INT8_C(  18),  INT8_C(  13),  INT8_C(  61), -INT8_C(   2), -INT8_C( 107),
        -INT8_C(  10), -INT8_C(  75), -INT8_C(  71), -INT8_C(   3),  INT8_C(  42), -INT8_C(  27), -INT8_C(  29),  INT8_C( 115),
        -INT8_C(  32), -INT8_C(  20),  INT8_C(  38),  INT8_C(  68), -INT8_C(  54),  INT8_C(  79),  INT8_C(  37),  INT8_C( 109),
         INT8_C(   9), -INT8_C(  59), -INT8_C(  51), -INT8_C(  19), -INT8_C(  40),  INT8_C(  65),  INT8_C(  87),  INT8_C( 126),
         INT8_C( 125), -INT8_C(  55),  INT8_C(  40),  INT8_C(  65),  INT8_C(  21),  INT8_C(  38), -INT8_C(  64), -INT8_C(  30),
        -INT8_C( 120), -INT8_C(  44), -INT8_C(  33),  INT8_C( 116),  INT8_C(   6),  INT8_C(   7),  INT8_C(  98), -INT8_C( 106) },
      UINT64_C( 9538624295731923206) },
    { UINT64_C(15069407961011507443),
      {  INT8_C(  19),  INT8_C(  74), -INT8_C(   4), -INT8_C(   1),  INT8_C( 112), -INT8_C(  68), -INT8_C(  30), -INT8_C(  70),
         INT8_C(   0), -INT8_C(  63),  INT8_C(  47),  INT8_C(  41), -INT8_C( 124), -INT8_C(  17), -INT8_C(  65),  INT8_C(  51),
         INT8_C(  30), -INT8_C( 102), -INT8_C(  84), -INT8_C(   8), -INT8_C( 102), -INT8_C( 109), -INT8_C( 123), -INT8_C( 115),
         INT8_C(  99),  INT8_C(  13), -INT8_C( 103),  INT8_C(  22),  INT8_C(  87), -INT8_C(  70), -INT8_C(  24),  INT8_C( 106),
         INT8_C(   4), -INT8_C(  28),  INT8_C( 106),  INT8_C( 117), -INT8_C(  95),  INT8_C(  76),  INT8_C(  47), -INT8_C(  95),
         INT8_C(  13),  INT8_C(  94), -INT8_C(  54), -INT8_C( 110),  INT8_C(  77), -INT8_C( 119), -INT8_C(  59),  INT8_C( 108),
         INT8_C(  36),  INT8_C( 114),  INT8_C( 100), -INT8_C(  66),  INT8_C(   5), -INT8_C(  23),  INT8_C(  76),  INT8_C( 104),
        -INT8_C(  10), -INT8_C(  27),  INT8_C( 126),  INT8_C(  77), -INT8_C(  97),  INT8_C( 102), -INT8_C(  72), -INT8_C(  92) },
      {  INT8_C(  19),  INT8_C(  74), -INT8_C(   4), -INT8_C(  20),  INT8_C( 110),  INT8_C(  72), -INT8_C( 115), -INT8_C(  70),
        -INT8_C(  89),  INT8_C(  87),  INT8_C(  13), -INT8_C(  12), -INT8_C( 124), -INT8_C(  17),  INT8_C(  96),  INT8_C(  51),
         INT8_C(  69), -INT8_C( 102), -INT8_C(  84), -INT8_C(   8), -INT8_C(  82), -INT8_C( 109), -INT8_C(  78), -INT8_C( 115),
        -INT8_C(  12),  INT8_C(  13), -INT8_C( 103),  INT8_C(  22), -INT8_C( 105), -INT8_C(  70), -INT8_C(  24),  INT8_C( 106),
         INT8_C(   4),  INT8_C(  80),  INT8_C( 106),  INT8_C(  58), -INT8_C(  95),  INT8_C(  91),  INT8_C(  47),  INT8_C(  64),
        -INT8_C(  78), -INT8_C(  61),  INT8_C(  52), -INT8_C( 110),  INT8_C(  77), -INT8_C( 119), -INT8_C(  59),  INT8_C( 108),
         INT8_C(  90),  INT8_C( 114),  INT8_C( 100), -INT8_C(  66),  INT8_C( 105), -INT8_C(  23), -INT8_C(  83),  INT8_C( 104),
        -INT8_C(  10), -INT8_C(  27), -INT8_C(  16), -INT8_C(  97),  INT8_C(  74),  INT8_C( 102), -INT8_C( 127), -INT8_C(  92) },
      UINT64_C( 5764891892835696752) },
    { UINT64_C( 8448054828670551755),
      { -INT8_C(  33),  INT8_C(  98),  INT8_C( 125),  INT8_C(  72),  INT8_C(  58),  INT8_C(  43), -INT8_C(  91),  INT8_C(  66),
        -INT8_C(  53), -INT8_C( 106), -INT8_C(  31),  INT8_C(  21), -INT8_C(  66),  INT8_C(  98),  INT8_C(  44),  INT8_C(  54),
        -INT8_C(  79),  INT8_C( 126),  INT8_C(  72),  INT8_C(  91), -INT8_C( 123), -INT8_C( 103), -INT8_C(  73),  INT8_C(  80),
         INT8_C(  31), -INT8_C(  91), -INT8_C(  78),  INT8_C(  58),  INT8_C(  43), -INT8_C(  17), -INT8_C(  81),  INT8_C(  10),
         INT8_C(  81),  INT8_C(  45),  INT8_C(  83), -INT8_C( 117),  INT8_C(  88), -INT8_C(   8), -INT8_C(  51),  INT8_C(  35),
        -INT8_C( 114), -INT8_C(  82),  INT8_C(  56),  INT8_C(  76),  INT8_C(  16),  INT8_C( 101), -INT8_C( 125), -INT8_C(  63),
        -INT8_C(  29), -INT8_C(  53),  INT8_C(  28),  INT8_C( 104),  INT8_C( 100), -INT8_C(  45), -INT8_C(  71), -INT8_C( 124),
         INT8_C( 121),  INT8_C( 107), -INT8_C(  66), -INT8_C(  92),  INT8_C(  90),  INT8_C( 110), -INT8_C(  82), -INT8_C(  85) },
      { -INT8_C( 101),  INT8_C(   1),  INT8_C( 125),  INT8_C(  72), -INT8_C(   6),  INT8_C(  43),  INT8_C(  22),  INT8_C(  66),
        -INT8_C(  53),  INT8_C(  78), -INT8_C(  31),  INT8_C(  21), -INT8_C(  66),  INT8_C(  98), -INT8_C( 123),  INT8_C(  54),
        -INT8_C(  79),  INT8_C( 126), -INT8_C(   1),  INT8_C(  91),  INT8_C( 117), -INT8_C(  72), -INT8_C(  73), -INT8_C(  18),
         INT8_C(  35), -INT8_C(  54), -INT8_C( 110),  INT8_C(  58),  INT8_C(  56),  INT8_C(  64), -INT8_C(  81), -INT8_C(  45),
         INT8_C(  81),  INT8_C(  95), -INT8_C(  58),  INT8_C(  60),  INT8_C( 100), -INT8_C(   8), -INT8_C(  51),  INT8_C(  35),
         INT8_C(  42), -INT8_C(  82),  INT8_C(  56), -INT8_C(  34), -INT8_C(  15),  INT8_C(  95),  INT8_C( 116), -INT8_C(  63),
        -INT8_C(  29),  INT8_C( 115), -INT8_C( 100),  INT8_C( 118),  INT8_C( 100), -INT8_C(  45),  INT8_C( 100),  INT8_C(  78),
         INT8_C( 113),  INT8_C( 107), -INT8_C(  66), -INT8_C(  87),  INT8_C(  90),  INT8_C( 110),  INT8_C( 124), -INT8_C(  85) },
      UINT64_C( 4687122523931017795) },
    { UINT64_C(  655444204514158866),
      {  INT8_C(  15), -INT8_C(  76),      INT8_MAX,  INT8_C(  58),  INT8_C(  92), -INT8_C(  29), -INT8_C( 119), -INT8_C(  51),
        -INT8_C(  39),  INT8_C(  84),  INT8_C( 119),  INT8_C(  16),  INT8_C(  72), -INT8_C(  13), -INT8_C( 120), -INT8_C( 100),
         INT8_C(  54),  INT8_C(  61),  INT8_C(  83),  INT8_C(  84), -INT8_C(  74),  INT8_C(  34), -INT8_C(  99), -INT8_C(  56),
        -INT8_C(  53), -INT8_C(  60), -INT8_C(  52), -INT8_C(  45),  INT8_C(  96), -INT8_C(  27), -INT8_C(  35),  INT8_C( 111),
        -INT8_C( 103),  INT8_C(  92), -INT8_C(  87), -INT8_C(  11),  INT8_C(  64),  INT8_C(  50), -INT8_C(  61),  INT8_C(  25),
        -INT8_C( 121),  INT8_C(  58),  INT8_C(  41), -INT8_C(  49),  INT8_C(  45), -INT8_C(  78),  INT8_C( 107),  INT8_C(  99),
        -INT8_C(  17), -INT8_C(  65), -INT8_C(  72), -INT8_C(  91), -INT8_C(  31),  INT8_C(  85),  INT8_C( 109), -INT8_C(  84),
         INT8_C(  26),  INT8_C(  58),      INT8_MAX,  INT8_C( 122),  INT8_C(  31),  INT8_C(  92), -INT8_C(  23), -INT8_C(  72) },
      {  INT8_C(  15), -INT8_C( 110), -INT8_C(  82), -INT8_C(   7),  INT8_C(  92), -INT8_C(  29), -INT8_C( 119), -INT8_C(  51),
        -INT8_C(  85),  INT8_C(  60),  INT8_C(  27),  INT8_C(  16), -INT8_C(  18), -INT8_C(  13), -INT8_C( 120), -INT8_C( 100),
         INT8_C(  70), -INT8_C(  12),  INT8_C(  83),  INT8_C(  39),  INT8_C(  73),  INT8_C(  34), -INT8_C(  99),  INT8_C(  99),
        -INT8_C(  53),  INT8_C(  82), -INT8_C(  35),  INT8_C(  72),  INT8_C(  96), -INT8_C(  58), -INT8_C(  35),  INT8_C( 111),
        -INT8_C( 103), -INT8_C(  81), -INT8_C(  87),  INT8_C(  30),  INT8_C(  64),  INT8_C(  50), -INT8_C(  61), -INT8_C(  53),
        -INT8_C(  81),  INT8_C(  58), -INT8_C(  93), -INT8_C(  49),  INT8_C(  45), -INT8_C(  78),  INT8_C( 107),  INT8_C(  99),
        -INT8_C(  45), -INT8_C(  65), -INT8_C(  72),  INT8_C(  29), -INT8_C(  20),  INT8_C(  76),      INT8_MIN,  INT8_C(  21),
         INT8_C(  26),  INT8_C(  94),      INT8_MAX,  INT8_C(  78),  INT8_C(  36),  INT8_C(  95), -INT8_C(  23), -INT8_C(  72) },
      UINT64_C(  583217285683151106) },
    { UINT64_C( 5758505768623512715),
      {  INT8_C(  78),  INT8_C(  99),  INT8_C( 108),  INT8_C(  58), -INT8_C(  80), -INT8_C(  19),  INT8_C(  80),  INT8_C(  79),
         INT8_C(  75), -INT8_C(  82), -INT8_C(  99),  INT8_C( 111),  INT8_C(  13),  INT8_C(  83), -INT8_C(  19),  INT8_C(  27),
         INT8_C( 106), -INT8_C( 120),  INT8_C(  73), -INT8_C(  12), -INT8_C( 114),  INT8_C(  66),  INT8_C(  46),  INT8_C(  25),
        -INT8_C(  34),  INT8_C(   6), -INT8_C(  80),  INT8_C(  90),  INT8_C(  88), -INT8_C( 102), -INT8_C(  86), -INT8_C(  90),
        -INT8_C(   2),  INT8_C(  22), -INT8_C(  31), -INT8_C(  82),  INT8_C(   3),  INT8_C(  49), -INT8_C(   3),  INT8_C(  78),
        -INT8_C(  33), -INT8_C( 102), -INT8_C(  66), -INT8_C(  20), -INT8_C(  19), -INT8_C(  85),  INT8_C(   7),  INT8_C(  87),
         INT8_C(  51),  INT8_C(  80),  INT8_C(  75), -INT8_C(  63), -INT8_C( 110),  INT8_C( 122), -INT8_C(  38),  INT8_C( 112),
             INT8_MIN, -INT8_C( 117), -INT8_C(  53), -INT8_C(  40),  INT8_C(  37),  INT8_C( 117),  INT8_C( 126),  INT8_C(  35) },
      { -INT8_C( 117),  INT8_C(  95), -INT8_C(  47),  INT8_C(  58), -INT8_C(  80), -INT8_C(  50),  INT8_C(  80),  INT8_C( 111),
         INT8_C( 104), -INT8_C( 101),  INT8_C(  91),  INT8_C( 111),  INT8_C(  70),  INT8_C(  83), -INT8_C(  19),  INT8_C(  27),
        -INT8_C(  78), -INT8_C(   8),  INT8_C(  73), -INT8_C(  12), -INT8_C( 114),  INT8_C(  66), -INT8_C(  75),  INT8_C(  25),
        -INT8_C(  95),  INT8_C(   6), -INT8_C(  80),  INT8_C(  90), -INT8_C(  11),  INT8_C(  72), -INT8_C(  86), -INT8_C(  90),
        -INT8_C(   2),  INT8_C(  22),  INT8_C(  15), -INT8_C(  82),  INT8_C(   3),  INT8_C(  49), -INT8_C(   3),  INT8_C(  78),
        -INT8_C( 120),  INT8_C(   3), -INT8_C(  66), -INT8_C(  49), -INT8_C(  19), -INT8_C(  12),  INT8_C(  73),  INT8_C(  24),
         INT8_C(  51),  INT8_C(  80),  INT8_C(  93), -INT8_C(  63), -INT8_C( 110),  INT8_C(  18), -INT8_C(  38),  INT8_C( 112),
             INT8_MIN, -INT8_C( 117),  INT8_C(   2), -INT8_C( 121),  INT8_C(  37),  INT8_C( 117),  INT8_C( 126),  INT8_C(  11) },
      UINT64_C(  873770912946787459) },
    { UINT64_C( 5579296247037783279),
      {  INT8_C(  41), -INT8_C(  54), -INT8_C(  85), -INT8_C(  61), -INT8_C(  36), -INT8_C(   4), -INT8_C(   1),  INT8_C( 110),
         INT8_C(  22),  INT8_C(   1), -INT8_C(  11),  INT8_C( 121), -INT8_C(  19), -INT8_C(   3), -INT8_C( 124), -INT8_C( 108),
         INT8_C(  20), -INT8_C(  56), -INT8_C(  58),  INT8_C(  24), -INT8_C(  77), -INT8_C(  22), -INT8_C(  92), -INT8_C(  94),
         INT8_C(  86),  INT8_C(   0), -INT8_C(   9), -INT8_C(  74), -INT8_C(  92),  INT8_C( 101),  INT8_C(   3), -INT8_C(  51),
         INT8_C(  47), -INT8_C(  81), -INT8_C( 111),  INT8_C(  12), -INT8_C(  85), -INT8_C( 112),  INT8_C( 122), -INT8_C(  63),
        -INT8_C( 111),  INT8_C( 112),  INT8_C(  59),  INT8_C( 126),  INT8_C( 109), -INT8_C(  65),  INT8_C(  18), -INT8_C( 127),
        -INT8_C( 121), -INT8_C(  40), -INT8_C( 103),  INT8_C(  59), -INT8_C(  62),  INT8_C(  61), -INT8_C(  35),  INT8_C(  24),
         INT8_C(  61), -INT8_C(  43), -INT8_C(  49), -INT8_C(  30),  INT8_C(  58), -INT8_C(  46), -INT8_C(  81),  INT8_C( 105) },
      {  INT8_C(  41), -INT8_C(  54),  INT8_C( 117), -INT8_C(  61), -INT8_C(  36), -INT8_C(   4), -INT8_C(   1),  INT8_C( 110),
         INT8_C(  96),  INT8_C(   1), -INT8_C(  33), -INT8_C(  51), -INT8_C(  19), -INT8_C(  14), -INT8_C( 124),  INT8_C( 112),
        -INT8_C(  54), -INT8_C(  25), -INT8_C(  85), -INT8_C( 115),  INT8_C(  36), -INT8_C( 120), -INT8_C(  92),  INT8_C(  98),
         INT8_C(  93),  INT8_C( 116), -INT8_C(   9), -INT8_C( 105), -INT8_C(  92), -INT8_C(  13),  INT8_C(   1), -INT8_C(  51),
         INT8_C(  47), -INT8_C(  81), -INT8_C( 111),  INT8_C(  12),  INT8_C( 102), -INT8_C( 112),  INT8_C( 122), -INT8_C(  58),
         INT8_C(  12),  INT8_C( 112), -INT8_C( 109),  INT8_C( 126),  INT8_C( 109), -INT8_C(  31),  INT8_C(  18), -INT8_C( 127),
        -INT8_C(  56), -INT8_C(  40), -INT8_C( 103),  INT8_C(  59), -INT8_C( 104),  INT8_C(  52), -INT8_C(  35),  INT8_C(  24),
         INT8_C(  61), -INT8_C(  43), -INT8_C( 115), -INT8_C(  16), -INT8_C( 122), -INT8_C(  46), -INT8_C(  81), -INT8_C(  70) },
      UINT64_C(  874019386197486596) },
    { UINT64_C( 8044824930431386986),
      {  INT8_C(   5),  INT8_C(  51),  INT8_C(  92), -INT8_C(  99),  INT8_C( 103), -INT8_C(  85), -INT8_C( 110),  INT8_C(  16),
         INT8_C(  62),  INT8_C(  31),  INT8_C(   0), -INT8_C(  60), -INT8_C(  83), -INT8_C(  71),      INT8_MAX, -INT8_C(  78),
         INT8_C( 102),  INT8_C(  62),  INT8_C(  29), -INT8_C(   9),  INT8_C(  99),  INT8_C(  78), -INT8_C( 109), -INT8_C(  51),
         INT8_C(  19),  INT8_C(  36),  INT8_C( 111), -INT8_C(  70),  INT8_C(  26),  INT8_C(  19),  INT8_C(  41),  INT8_C(  31),
         INT8_C(  70), -INT8_C( 123), -INT8_C(  68), -INT8_C(  82),  INT8_C(  48),  INT8_C(  78), -INT8_C(  66),  INT8_C( 110),
         INT8_C( 110), -INT8_C(  65),  INT8_C(  50),  INT8_C(  27),  INT8_C( 120), -INT8_C(  79), -INT8_C(  51), -INT8_C(  34),
        -INT8_C(  17), -INT8_C(  22), -INT8_C(  43),  INT8_C(  82),  INT8_C(  57),  INT8_C( 105),  INT8_C(  32),  INT8_C(  76),
        -INT8_C( 115), -INT8_C( 113),  INT8_C(   6), -INT8_C(  89), -INT8_C(  93),  INT8_C(  47), -INT8_C(  58), -INT8_C(  23) },
      { -INT8_C(  76), -INT8_C( 126), -INT8_C( 105), -INT8_C(  28), -INT8_C(  47), -INT8_C(  85), -INT8_C( 110),  INT8_C(  63),
         INT8_C(  62), -INT8_C( 123),  INT8_C(  90), -INT8_C(  60), -INT8_C(  83), -INT8_C(  71),      INT8_MAX, -INT8_C(  78),
         INT8_C(  18),  INT8_C(  65),  INT8_C( 120), -INT8_C(   9), -INT8_C(  86), -INT8_C( 104), -INT8_C( 104), -INT8_C(  51),
         INT8_C(  40),  INT8_C(  36),  INT8_C( 111), -INT8_C(  70),  INT8_C(  26),  INT8_C(  19), -INT8_C(  76),  INT8_C(  31),
         INT8_C(  70), -INT8_C( 123), -INT8_C(  68), -INT8_C(  82),  INT8_C(  48),  INT8_C(  78),  INT8_C(  56), -INT8_C(  73),
         INT8_C(  62), -INT8_C( 110),  INT8_C(  68),  INT8_C( 117),  INT8_C( 120), -INT8_C(  81), -INT8_C(  51), -INT8_C(  51),
        -INT8_C(  17), -INT8_C(  22), -INT8_C(  43), -INT8_C( 102), -INT8_C(  84), -INT8_C(  80), -INT8_C(  46), -INT8_C(  44),
        -INT8_C( 115), -INT8_C(  79), -INT8_C(  97),  INT8_C(  29),  INT8_C(  86),  INT8_C(  83), -INT8_C(  97),  INT8_C( 126) },
      UINT64_C( 7971553309621289994) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i a = simde_mm512_loadu_epi8(test_vec[i].a);
    simde__m512i b = simde_mm512_loadu_epi8(test_vec[i].b);
    simde__mmask64 r = simde_mm512_mask_cmpneq_epi8_mask(test_vec[i].k1, a, b);
    simde_assert_equal_mmask64(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask64 k1 = simde_test_x86_random_mmask64();
    simde__m512i a = simde_test_x86_random_i8x64();
    simde__m512i b = simde_mm512_mask_blend_epi8(simde_test_x86_random_mmask64(), a, simde_test_x86_random_i8x64());
    simde__mmask64 r = simde_mm512_mask_cmpneq_epi8_mask(k1, a, b);

    simde_test_x86_write_mmask64(2, k1, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i8x64(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i8x64(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask64(2, r, SIMDE_TEST_VEC_POS_LAST);
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
test_simde_mm512_cmpneq_epi16_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int16_t a[32];
    const int16_t b[32];
    const simde__mmask32 r;
  } test_vec[] = {
    { {  INT16_C( 15426), -INT16_C(   909),  INT16_C(  3820), -INT16_C(  9015), -INT16_C(  7646), -INT16_C( 12681),  INT16_C( 18834), -INT16_C(  7774),
         INT16_C( 16890),  INT16_C( 20734), -INT16_C( 24940),  INT16_C( 13519),  INT16_C( 18084),  INT16_C( 25717),  INT16_C( 28406),  INT16_C( 14435),
        -INT16_C( 10582), -INT16_C( 27084), -INT16_C(   283),  INT16_C(  1907), -INT16_C(  5408),  INT16_C( 29397),  INT16_C( 30515),  INT16_C( 11604),
         INT16_C( 21176),  INT16_C( 19581),  INT16_C( 19696), -INT16_C( 27264), -INT16_C(  2413), -INT16_C( 30215),  INT16_C( 23652),  INT16_C(  3777) },
      { -INT16_C(  2765), -INT16_C(   909),  INT16_C(  3820), -INT16_C( 11489), -INT16_C(  3070), -INT16_C( 12681),  INT16_C( 18834),  INT16_C(  9058),
         INT16_C( 16890), -INT16_C(  8849), -INT16_C( 24940),  INT16_C( 13519),  INT16_C( 18084),  INT16_C( 19016),  INT16_C( 28406),  INT16_C( 14435),
        -INT16_C( 10582), -INT16_C(  3565), -INT16_C(   283),  INT16_C(  6085),  INT16_C(  2854), -INT16_C( 28340),  INT16_C( 30515), -INT16_C( 27980),
         INT16_C(  9102), -INT16_C( 17809), -INT16_C(  7917), -INT16_C(  1671), -INT16_C(  2413),  INT16_C(  5187),  INT16_C( 23652), -INT16_C( 14321) },
      UINT32_C(2948211353) },
    { { -INT16_C( 32684),  INT16_C( 31430),  INT16_C(  5003),  INT16_C( 12555), -INT16_C( 16447),  INT16_C( 20419),  INT16_C( 13027), -INT16_C(  2551),
        -INT16_C( 32237),  INT16_C( 24560),  INT16_C( 13123),  INT16_C(  3444), -INT16_C( 31793),  INT16_C( 27094), -INT16_C( 28506), -INT16_C(  1512),
        -INT16_C(  8688), -INT16_C( 25483), -INT16_C( 32527), -INT16_C( 19507), -INT16_C( 28608),  INT16_C(  8962),  INT16_C(  3266), -INT16_C( 10983),
         INT16_C(  2446), -INT16_C( 11724), -INT16_C( 22467),  INT16_C(  3295), -INT16_C( 19156), -INT16_C( 11659), -INT16_C( 29370),  INT16_C( 22220) },
      { -INT16_C( 32684),  INT16_C( 31430),  INT16_C(  5003),  INT16_C( 12555),  INT16_C(  4943),  INT16_C(  4389),  INT16_C( 15903), -INT16_C( 21018),
         INT16_C(  6984), -INT16_C( 31361),  INT16_C( 24515), -INT16_C(  4207), -INT16_C( 31793),  INT16_C( 27094), -INT16_C( 29036), -INT16_C(  1512),
        -INT16_C( 23601), -INT16_C( 25483), -INT16_C( 32527), -INT16_C( 19821), -INT16_C( 28608), -INT16_C( 24380),  INT16_C(  3266), -INT16_C( 10983),
        -INT16_C( 12859), -INT16_C( 30268), -INT16_C( 22467),  INT16_C(  3295),  INT16_C( 14940), -INT16_C( 11659),  INT16_C( 19656),  INT16_C( 22220) },
      UINT32_C(1395216368) },
    { { -INT16_C( 17218),  INT16_C( 16133), -INT16_C( 13963),  INT16_C( 27872),  INT16_C( 11892),  INT16_C( 14763),  INT16_C( 28667),  INT16_C( 10434),
         INT16_C( 15300),  INT16_C(  8553),  INT16_C(  1141),  INT16_C( 15634),  INT16_C(   849),  INT16_C( 16852), -INT16_C(   685),  INT16_C(  4500),
        -INT16_C( 26182),  INT16_C( 12112),  INT16_C( 12387), -INT16_C( 10341),  INT16_C( 18014),  INT16_C( 23056), -INT16_C( 11339),  INT16_C( 31106),
        -INT16_C(  5362), -INT16_C( 31846), -INT16_C( 21265),  INT16_C( 16576), -INT16_C( 27472),  INT16_C(   897),  INT16_C(  5522),  INT16_C( 19476) },
      { -INT16_C( 17218),  INT16_C( 16133), -INT16_C( 13963), -INT16_C(  3095), -INT16_C(  1700),  INT16_C( 14763), -INT16_C( 12340), -INT16_C(  9590),
         INT16_C( 15300), -INT16_C( 21923),  INT16_C(  1141),  INT16_C( 15634),  INT16_C( 27826),  INT16_C( 16852), -INT16_C( 26495),  INT16_C(  4500),
        -INT16_C( 26182),  INT16_C( 12112),  INT16_C( 11041),  INT16_C( 32133), -INT16_C( 11483), -INT16_C(  3698), -INT16_C( 11339),  INT16_C( 31106),
         INT16_C( 10557), -INT16_C( 31846), -INT16_C( 21265), -INT16_C(  1648),  INT16_C(  5469), -INT16_C(  8387), -INT16_C( 12883), -INT16_C( 22001) },
      UINT32_C(4181480152) },
    { { -INT16_C( 15747), -INT16_C( 23946),  INT16_C(  1173),  INT16_C( 14228),  INT16_C( 24604),  INT16_C( 23188), -INT16_C( 25719), -INT16_C( 12183),
        -INT16_C(  1651), -INT16_C(  5431),  INT16_C(  1550), -INT16_C( 17207), -INT16_C(  9773), -INT16_C( 21658), -INT16_C( 23765), -INT16_C( 22364),
         INT16_C(  6757), -INT16_C(  1461), -INT16_C(  8418),  INT16_C( 15153), -INT16_C( 14785), -INT16_C( 14187), -INT16_C(   415), -INT16_C(  4455),
         INT16_C( 25335),  INT16_C(  1753), -INT16_C( 23959),  INT16_C( 15554),  INT16_C( 10363), -INT16_C( 22808), -INT16_C( 29493),  INT16_C( 12367) },
      { -INT16_C( 25945), -INT16_C( 15062),  INT16_C( 23673),  INT16_C( 14228), -INT16_C( 27358), -INT16_C( 31872),  INT16_C(  6547), -INT16_C( 12183),
         INT16_C( 19324), -INT16_C(  5431),  INT16_C( 21485), -INT16_C( 17207), -INT16_C(  9773),  INT16_C( 18191), -INT16_C( 23765), -INT16_C( 22364),
        -INT16_C( 23816),  INT16_C( 28930),  INT16_C(  1022),  INT16_C(  8233), -INT16_C( 14785), -INT16_C( 14187), -INT16_C(   415),  INT16_C( 16311),
         INT16_C( 18528),  INT16_C(  1753),  INT16_C( 18075),  INT16_C( 15554), -INT16_C( 14769), -INT16_C(  6819), -INT16_C( 10971),  INT16_C( 12367) },
      UINT32_C(1972315511) },
    { { -INT16_C( 18392), -INT16_C( 16235),  INT16_C( 14434),  INT16_C(  9964), -INT16_C( 23730), -INT16_C( 20891), -INT16_C( 29973), -INT16_C( 30980),
        -INT16_C( 19504),  INT16_C(  8093), -INT16_C(  1414), -INT16_C( 24827),  INT16_C( 10191),  INT16_C( 18108),  INT16_C( 19276),  INT16_C( 29883),
         INT16_C( 20484),  INT16_C( 26165),  INT16_C(  8585), -INT16_C( 10356), -INT16_C(  3387), -INT16_C( 20347), -INT16_C( 32132),  INT16_C( 19511),
        -INT16_C( 11211), -INT16_C( 20629),  INT16_C( 28878), -INT16_C( 25010),  INT16_C(  2968), -INT16_C(  6940), -INT16_C( 24490),  INT16_C( 23129) },
      { -INT16_C( 28944),  INT16_C( 31169),  INT16_C( 14434),  INT16_C(  9964), -INT16_C( 10689), -INT16_C( 17627), -INT16_C( 29973), -INT16_C( 30980),
         INT16_C( 29488),  INT16_C(  8093), -INT16_C( 29725), -INT16_C( 24827), -INT16_C( 32362), -INT16_C(  4768), -INT16_C( 18143),  INT16_C(  4423),
         INT16_C(  2119),  INT16_C( 26165),  INT16_C(  8585), -INT16_C( 10356), -INT16_C(  3387), -INT16_C( 20347), -INT16_C( 32132),  INT16_C(  7319),
        -INT16_C( 11061), -INT16_C( 20629),  INT16_C( 28878), -INT16_C(  2518),  INT16_C(  2968), -INT16_C(  6940), -INT16_C( 24490), -INT16_C( 30102) },
      UINT32_C(2306995507) },
    { { -INT16_C(  4911), -INT16_C( 32226),  INT16_C( 28540),  INT16_C( 26764),  INT16_C(  9160), -INT16_C( 27772), -INT16_C( 24841),  INT16_C( 22082),
         INT16_C( 27989), -INT16_C( 29364),  INT16_C( 12279),  INT16_C( 15334),  INT16_C( 20826), -INT16_C( 29243),  INT16_C( 17990),  INT16_C(  5910),
         INT16_C( 13362), -INT16_C( 20838),  INT16_C(  9892),  INT16_C( 27670), -INT16_C( 26039),  INT16_C( 16639),  INT16_C( 16953), -INT16_C( 29034),
        -INT16_C(  7249), -INT16_C( 23012),  INT16_C(   530),  INT16_C( 27873), -INT16_C( 22701), -INT16_C( 25863),  INT16_C(  4077),  INT16_C(  8369) },
      { -INT16_C(  4911), -INT16_C(  5938), -INT16_C(  6799),  INT16_C( 26764),  INT16_C(  9160), -INT16_C( 27772), -INT16_C( 24841),  INT16_C( 22082),
         INT16_C( 25460), -INT16_C( 29364), -INT16_C( 13211),  INT16_C( 15334),  INT16_C( 20826), -INT16_C( 29243),  INT16_C(  1276),  INT16_C(  5910),
         INT16_C( 13362), -INT16_C( 16088),  INT16_C( 31796), -INT16_C( 19332),  INT16_C( 30415),  INT16_C( 16639),  INT16_C( 16953),  INT16_C( 31657),
        -INT16_C(  7249),  INT16_C( 31746),  INT16_C(   530), -INT16_C( 11211), -INT16_C( 30495), -INT16_C(  8907),  INT16_C(  4077),  INT16_C(  8369) },
      UINT32_C( 983450886) },
    { {  INT16_C(  6849), -INT16_C( 28178),  INT16_C( 23440), -INT16_C( 26378), -INT16_C( 24818),  INT16_C(  9491),  INT16_C(  5428), -INT16_C( 27231),
        -INT16_C( 10742), -INT16_C(  5015), -INT16_C( 24738), -INT16_C(  5431), -INT16_C(  6315),  INT16_C( 23495),  INT16_C( 25900), -INT16_C(  4458),
        -INT16_C( 31617),  INT16_C(  3967),  INT16_C( 30175), -INT16_C(  4441), -INT16_C( 17644),  INT16_C( 18451), -INT16_C( 19248), -INT16_C(  9251),
         INT16_C( 18314), -INT16_C(  5945), -INT16_C( 28442),  INT16_C( 15314), -INT16_C( 26249), -INT16_C( 23401),  INT16_C( 11774),  INT16_C( 32146) },
      {  INT16_C(  6849), -INT16_C( 28178),  INT16_C( 13446), -INT16_C( 25985), -INT16_C( 24818), -INT16_C( 16157),  INT16_C(  5428), -INT16_C( 12133),
        -INT16_C( 10742), -INT16_C(  4680), -INT16_C( 29966),  INT16_C( 27177), -INT16_C(  6315),  INT16_C( 23495),  INT16_C( 25900), -INT16_C(  4458),
        -INT16_C( 31617),  INT16_C(  3967),  INT16_C( 30175), -INT16_C(  4441), -INT16_C( 17644),  INT16_C( 18451), -INT16_C( 19248), -INT16_C(  9251),
         INT16_C( 18314),  INT16_C(   106), -INT16_C( 27751), -INT16_C( 17046), -INT16_C( 26249), -INT16_C( 23401),  INT16_C( 11774),  INT16_C( 32146) },
      UINT32_C( 234884780) },
    { { -INT16_C( 11588), -INT16_C(   673),  INT16_C( 28806), -INT16_C(  1149), -INT16_C(  9700),  INT16_C( 10872), -INT16_C(  7448), -INT16_C( 32470),
        -INT16_C( 27275), -INT16_C( 14274),  INT16_C(  7693),  INT16_C(  9736), -INT16_C(  6499),  INT16_C( 19183), -INT16_C(  3852), -INT16_C( 20136),
        -INT16_C( 18494),  INT16_C( 18606),  INT16_C( 12583),  INT16_C( 17220), -INT16_C( 17397), -INT16_C(  2963), -INT16_C( 26722),  INT16_C(  4981),
        -INT16_C( 19412),  INT16_C( 15067), -INT16_C(  7214),  INT16_C( 28512),  INT16_C( 20425), -INT16_C( 16711),  INT16_C(  4415),  INT16_C(   367) },
      {  INT16_C(  7624), -INT16_C(  4278),  INT16_C( 28806), -INT16_C(  1149), -INT16_C(  9700),  INT16_C( 10872), -INT16_C(  7448),  INT16_C( 25595),
        -INT16_C( 10633),  INT16_C( 18845), -INT16_C(   583), -INT16_C( 32071),  INT16_C( 29261), -INT16_C( 29632), -INT16_C( 20604), -INT16_C( 20136),
        -INT16_C( 18494),  INT16_C( 18606),  INT16_C( 28262), -INT16_C( 20363), -INT16_C( 15602),  INT16_C( 17816), -INT16_C( 27770),  INT16_C(  4981),
         INT16_C( 18025),  INT16_C( 15067), -INT16_C(  7214), -INT16_C( 28508),  INT16_C( 20425), -INT16_C(  2275), -INT16_C( 21612),  INT16_C( 24899) },
      UINT32_C(3917250435) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512i a = simde_mm512_loadu_epi16(test_vec[i].a);
    simde__m512i b = simde_mm512_loadu_epi16(test_vec[i].b);
    simde__mmask32 r = simde_mm512_cmpneq_epi16_mask(a, b);
    simde_assert_equal_mmask32(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m512i a = simde_test_x86_random_i16x32();
    simde__m512i b = simde_mm512_mask_blend_epi16(simde_test_x86_random_mmask32(), a, simde_test_x86_random_i16x32());
    simde__mmask32 r = simde_mm512_cmpneq_epi16_mask(a, b);

    simde_test_x86_write_i16x32(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i16x32(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_mask_cmpneq_epi16_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask32 k1;
    const int16_t a[32];
    const int16_t b[32];
    const simde__mmask32 r;
  } test_vec[] = {
    { UINT32_C(4237947374),
      {  INT16_C( 12724),  INT16_C( 14913), -INT16_C(  5692),  INT16_C( 11576), -INT16_C( 32721),  INT16_C( 29519), -INT16_C(  3200), -INT16_C(  3325),
         INT16_C(  8408),  INT16_C( 28138),  INT16_C( 11979),  INT16_C( 20174),  INT16_C( 19117), -INT16_C( 25801), -INT16_C( 12229), -INT16_C(  4201),
        -INT16_C( 10239), -INT16_C( 15063),  INT16_C( 25282), -INT16_C(  3598),  INT16_C( 16866),  INT16_C( 25188),  INT16_C( 26677),  INT16_C(  3414),
         INT16_C( 16520),  INT16_C( 21626),  INT16_C( 18542),  INT16_C(  7330), -INT16_C(  9582), -INT16_C( 12873),  INT16_C( 20394), -INT16_C( 21316) },
      {  INT16_C( 12724),  INT16_C( 14913),  INT16_C( 25672),  INT16_C( 10971), -INT16_C( 32721), -INT16_C(  9588), -INT16_C(  3200), -INT16_C(  3325),
         INT16_C(  8408), -INT16_C( 28284),  INT16_C( 11979),  INT16_C( 15789),  INT16_C( 19117), -INT16_C( 21749), -INT16_C( 12229), -INT16_C(  9385),
        -INT16_C( 14163), -INT16_C( 15063), -INT16_C( 24532), -INT16_C(  3598), -INT16_C( 21281),  INT16_C( 25188), -INT16_C( 27506),  INT16_C(  3414),
         INT16_C( 15351),  INT16_C( 21626),  INT16_C( 18542),  INT16_C( 25311), -INT16_C(  5547), -INT16_C( 12873),  INT16_C( 25778), -INT16_C( 21316) },
      UINT32_C(1477550124) },
    { UINT32_C( 690713674),
      { -INT16_C( 10464), -INT16_C( 20560),  INT16_C( 26476),  INT16_C( 25440), -INT16_C( 23646),  INT16_C(  1029), -INT16_C(  7020), -INT16_C(  5786),
         INT16_C( 29647), -INT16_C( 32269), -INT16_C( 10025),  INT16_C(   992),  INT16_C( 13698), -INT16_C( 13220), -INT16_C( 30806), -INT16_C( 13579),
        -INT16_C( 22945), -INT16_C( 13447), -INT16_C(  9715), -INT16_C( 20434),  INT16_C( 13181),  INT16_C(  4532),  INT16_C(  6679), -INT16_C(  6405),
        -INT16_C(  4467),  INT16_C( 25703),  INT16_C( 18630),  INT16_C( 18535), -INT16_C( 15235),  INT16_C( 10004),  INT16_C(  2379), -INT16_C( 21774) },
      {  INT16_C( 27567), -INT16_C( 20560),  INT16_C( 26476),  INT16_C( 25440),  INT16_C(  8662), -INT16_C(  4396), -INT16_C(  7020), -INT16_C( 14124),
         INT16_C( 29647), -INT16_C( 31956), -INT16_C( 27772),  INT16_C(   992), -INT16_C(  8361), -INT16_C( 23767),  INT16_C(  7145), -INT16_C( 26547),
        -INT16_C( 15482), -INT16_C( 13227), -INT16_C( 15770), -INT16_C( 20434),  INT16_C( 25571),  INT16_C(  4532), -INT16_C(   205), -INT16_C(  6405),
         INT16_C(  4667), -INT16_C( 16524),  INT16_C( 16294),  INT16_C( 18535), -INT16_C(  5601),  INT16_C( 10004),  INT16_C(  2379), -INT16_C( 21774) },
      UINT32_C(  17003520) },
    { UINT32_C(2622809784),
      {  INT16_C( 32586),  INT16_C( 32186), -INT16_C( 24193), -INT16_C( 17811), -INT16_C(  7757),  INT16_C( 22906),  INT16_C( 15137),  INT16_C( 16471),
        -INT16_C(  2267),  INT16_C( 10824), -INT16_C(  5915), -INT16_C( 26955),  INT16_C(  3550), -INT16_C( 26706),  INT16_C(   755),  INT16_C( 15667),
        -INT16_C(  4734),  INT16_C(   442),  INT16_C( 10382),  INT16_C( 17083),  INT16_C( 13577),  INT16_C( 10907), -INT16_C(  3472), -INT16_C( 27286),
        -INT16_C( 19734), -INT16_C( 12353),  INT16_C( 30107),  INT16_C( 31078),  INT16_C(  5250),  INT16_C( 29968),  INT16_C( 17174), -INT16_C( 26445) },
      {  INT16_C( 27953),  INT16_C( 32186), -INT16_C( 24193), -INT16_C( 24831), -INT16_C( 25206), -INT16_C(  1079),  INT16_C( 13455),  INT16_C( 31120),
        -INT16_C(  2267),  INT16_C( 10824), -INT16_C( 20539),  INT16_C( 18427),  INT16_C(  3550), -INT16_C( 26706),  INT16_C(   755), -INT16_C( 32654),
        -INT16_C(  4734),  INT16_C( 29247),  INT16_C( 16736), -INT16_C(  5359),  INT16_C( 13577),  INT16_C( 10907),  INT16_C( 30223), -INT16_C( 27286),
         INT16_C( 12486), -INT16_C( 12353),  INT16_C( 30107), -INT16_C( 23854), -INT16_C( 28803),  INT16_C( 29968), -INT16_C(  4610), -INT16_C( 26445) },
      UINT32_C( 407143608) },
    { UINT32_C(2873384909),
      {  INT16_C( 10810),  INT16_C( 18712), -INT16_C(    95),  INT16_C( 26431), -INT16_C( 18897),  INT16_C(  3827), -INT16_C( 15064), -INT16_C( 23120),
         INT16_C( 11348),  INT16_C( 21362), -INT16_C( 16871),  INT16_C(  4654),  INT16_C( 31818),  INT16_C(  5996), -INT16_C( 20260),  INT16_C(  5826),
        -INT16_C(  9253),  INT16_C( 31840), -INT16_C( 24614),  INT16_C(  2787), -INT16_C( 10667),  INT16_C( 32024), -INT16_C( 13924), -INT16_C(  4062),
        -INT16_C( 27403),  INT16_C(  3651),  INT16_C( 29267), -INT16_C( 25311), -INT16_C( 29202), -INT16_C( 13643),  INT16_C( 30525),  INT16_C(  6369) },
      {  INT16_C( 16722),  INT16_C( 18712), -INT16_C(    95),  INT16_C( 26431),  INT16_C( 20302), -INT16_C(  5454), -INT16_C( 15064),  INT16_C(  3547),
         INT16_C( 11348),  INT16_C( 21362), -INT16_C( 16871),  INT16_C( 32601),  INT16_C(  3786),  INT16_C(  1865),  INT16_C( 10886), -INT16_C( 10208),
        -INT16_C( 19349),  INT16_C( 31840), -INT16_C( 24614),  INT16_C( 31616),  INT16_C( 12940),  INT16_C( 32024), -INT16_C( 13924),  INT16_C( 28850),
        -INT16_C( 12705),  INT16_C(  3651), -INT16_C( 31477), -INT16_C( 10898), -INT16_C( 18284), -INT16_C( 13643), -INT16_C(   798),  INT16_C( 20210) },
      UINT32_C(2298501249) },
    { UINT32_C(3226999348),
      { -INT16_C( 16820),  INT16_C( 21349),  INT16_C(  6142),  INT16_C( 24003), -INT16_C(  4123), -INT16_C(  4019), -INT16_C( 17547),  INT16_C(  2501),
        -INT16_C( 24205),  INT16_C( 22051),  INT16_C(  5534),  INT16_C( 20388),  INT16_C( 15629),  INT16_C( 16940), -INT16_C( 31401), -INT16_C( 23550),
         INT16_C( 26435),  INT16_C( 16887), -INT16_C( 17538),  INT16_C( 25503), -INT16_C(  4950),  INT16_C(  8019),  INT16_C(  6311),  INT16_C(  6952),
         INT16_C( 19386),  INT16_C( 22641),  INT16_C(  5473),  INT16_C( 28327), -INT16_C( 11438), -INT16_C( 21840), -INT16_C( 19624), -INT16_C( 25778) },
      { -INT16_C( 16820), -INT16_C( 26147),  INT16_C(  6142), -INT16_C( 21508), -INT16_C(  4123), -INT16_C(  4019), -INT16_C( 17547),  INT16_C(  8746),
        -INT16_C( 24205), -INT16_C( 24710),  INT16_C(  8624),  INT16_C( 20388), -INT16_C( 16651),  INT16_C( 19885), -INT16_C(  1167), -INT16_C( 23550),
         INT16_C( 26435),  INT16_C( 16887),  INT16_C(  8514), -INT16_C( 21780), -INT16_C( 18831),  INT16_C(  8019), -INT16_C(  6999),  INT16_C(  6952),
         INT16_C( 19386),  INT16_C( 22641), -INT16_C( 27240), -INT16_C( 29389), -INT16_C( 11438), -INT16_C( 21840), -INT16_C( 15141),  INT16_C(  6993) },
      UINT32_C(3226997248) },
    { UINT32_C( 158746776),
      {  INT16_C( 12287), -INT16_C( 22301), -INT16_C(  8173), -INT16_C( 27760),  INT16_C(  6231), -INT16_C(  4157), -INT16_C(  2387),  INT16_C(   381),
         INT16_C( 22742), -INT16_C( 20025),  INT16_C(  6172), -INT16_C( 22836),  INT16_C( 10639),  INT16_C( 10098), -INT16_C(  6031),  INT16_C( 28720),
         INT16_C(  5143),  INT16_C( 11033), -INT16_C( 22028),  INT16_C( 19390), -INT16_C( 32319),  INT16_C( 28474), -INT16_C( 18569),  INT16_C( 19824),
         INT16_C( 14095),  INT16_C( 11262), -INT16_C( 13744), -INT16_C(  8239),  INT16_C( 17395),  INT16_C( 25862),  INT16_C( 13867),  INT16_C( 17365) },
      {  INT16_C( 12287), -INT16_C( 22301),  INT16_C( 11416),  INT16_C( 22921), -INT16_C( 15187), -INT16_C(  4157), -INT16_C(  2387), -INT16_C( 29839),
         INT16_C( 22742), -INT16_C( 16202), -INT16_C( 30663), -INT16_C( 22836),  INT16_C( 10639), -INT16_C(  2158), -INT16_C(  6031),  INT16_C( 28720),
        -INT16_C( 22442),  INT16_C( 11033), -INT16_C( 22028), -INT16_C( 32441), -INT16_C( 32319),  INT16_C( 11941), -INT16_C( 18569),  INT16_C( 19824),
         INT16_C( 14095),  INT16_C( 11262), -INT16_C( 13744), -INT16_C(  8239),  INT16_C( 32191), -INT16_C( 25670), -INT16_C(  2843),  INT16_C( 17365) },
      UINT32_C(   2097304) },
    { UINT32_C(3354488853),
      { -INT16_C( 27008), -INT16_C( 13835), -INT16_C( 20820),  INT16_C( 12675), -INT16_C(   738),  INT16_C(  5615), -INT16_C(  9450), -INT16_C( 10792),
        -INT16_C( 28072),  INT16_C( 15728),  INT16_C( 12934),  INT16_C(  8824), -INT16_C( 24232),  INT16_C( 28050), -INT16_C( 31982), -INT16_C( 28107),
         INT16_C( 10777), -INT16_C( 15012), -INT16_C(  8231), -INT16_C(  2058), -INT16_C(  6436), -INT16_C(  3572), -INT16_C(  6719),  INT16_C(  6600),
         INT16_C( 14455), -INT16_C(   425), -INT16_C( 12438), -INT16_C( 15584), -INT16_C( 19599), -INT16_C( 31952),  INT16_C( 25910),  INT16_C( 20501) },
      { -INT16_C( 27008), -INT16_C( 13835),  INT16_C(  3152),  INT16_C( 12675),  INT16_C( 27890), -INT16_C( 19681), -INT16_C(  9450), -INT16_C( 10792),
         INT16_C(  8991), -INT16_C( 30009), -INT16_C(  6157),  INT16_C(  8824),  INT16_C( 32154),  INT16_C( 28050), -INT16_C( 31982),  INT16_C( 29473),
         INT16_C( 10777), -INT16_C( 16676),  INT16_C( 15426),  INT16_C( 13547),  INT16_C(  2728), -INT16_C(  1305), -INT16_C(  6719),  INT16_C(  6600),
        -INT16_C( 29993), -INT16_C( 13670), -INT16_C(  6287), -INT16_C( 15584),  INT16_C(  5477),  INT16_C( 18653), -INT16_C(   494),  INT16_C( 20501) },
      UINT32_C(1194332180) },
    { UINT32_C(2074814931),
      { -INT16_C( 27853),  INT16_C(  9333),  INT16_C( 14407),  INT16_C(  7733), -INT16_C( 12350),  INT16_C( 13545),  INT16_C(  6071),  INT16_C(  7232),
         INT16_C(  7469),  INT16_C( 16228),  INT16_C(  7963),  INT16_C( 20415), -INT16_C(   586), -INT16_C( 30266),  INT16_C( 29223),  INT16_C( 23044),
         INT16_C( 31237),  INT16_C( 19583), -INT16_C( 19278),  INT16_C( 30058),  INT16_C( 21379),  INT16_C( 15017), -INT16_C(  5781), -INT16_C( 26538),
        -INT16_C( 17914),  INT16_C(  8663), -INT16_C( 26919), -INT16_C( 28816),  INT16_C( 14227), -INT16_C( 17896),  INT16_C(  7593), -INT16_C( 20971) },
      { -INT16_C( 27497),  INT16_C( 18938),  INT16_C( 25672), -INT16_C( 13378), -INT16_C( 12350),  INT16_C( 13545),  INT16_C(  6071),  INT16_C( 22203),
        -INT16_C( 28137),  INT16_C( 16228), -INT16_C(  6104), -INT16_C( 17536), -INT16_C(   586), -INT16_C( 30266), -INT16_C( 29771),  INT16_C( 23044),
         INT16_C( 28703),  INT16_C( 26518),  INT16_C( 21716),  INT16_C( 30058),  INT16_C( 21379),  INT16_C(  3247),  INT16_C( 27285), -INT16_C( 26538),
        -INT16_C( 17914),  INT16_C(  8663),  INT16_C(  7362), -INT16_C( 28816),  INT16_C( 14227),  INT16_C( 27305),  INT16_C(  8161), -INT16_C( 20971) },
      UINT32_C(1612908931) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512i a = simde_mm512_loadu_epi16(test_vec[i].a);
    simde__m512i b = simde_mm512_loadu_epi16(test_vec[i].b);
    simde__mmask32 r = simde_mm512_mask_cmpneq_epi16_mask(test_vec[i].k1, a, b);
    simde_assert_equal_mmask32(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask32 k1 = simde_test_x86_random_mmask32();
    simde__m512i a = simde_test_x86_random_i16x32();
    simde__m512i b = simde_mm512_mask_blend_epi16(simde_test_x86_random_mmask32(), a, simde_test_x86_random_i16x32());
    simde__mmask32 r = simde_mm512_mask_cmpneq_epi16_mask(k1, a, b);

    simde_test_x86_write_mmask32(2, k1, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i16x32(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x32(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask32(2, r, SIMDE_TEST_VEC_POS_LAST);
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
test_simde_mm512_cmpneq_epi32_mask(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  const struct {
    const int32_t a[16];
    const int32_t b[16];
    const simde__mmask16 r;
  } test_vec[8] = {
    { {  INT32_C(  1412784467), -INT32_C(  2124332287), -INT32_C(  1086558940), -INT32_C(  1660694531), -INT32_C(  1772351070),  INT32_C(  1111199808),  INT32_C(  1064801510),  INT32_C(  1581942538),
        -INT32_C(   357400599), -INT32_C(   412412733),  INT32_C(  2124851073),  INT32_C(   404466294), -INT32_C(    72452165), -INT32_C(   297932537), -INT32_C(  2010270595),  INT32_C(   635860796) },
      {  INT32_C(  1412784467),  INT32_C(   765557420), -INT32_C(  1750382815), -INT32_C(  1660694531),  INT32_C(  1168662078),  INT32_C(  1111199808),  INT32_C(  1064801510),  INT32_C(  1581942538),
         INT32_C(  2022247116), -INT32_C(   412412733),  INT32_C(  2124851073),  INT32_C(   404466294), -INT32_C(    72452165),  INT32_C(   962187167),  INT32_C(   135308848),  INT32_C(   635860796) },
      UINT16_C(24854) },
    { { -INT32_C(   997418466),  INT32_C(  2098658880),  INT32_C(  1919561313),  INT32_C(   522958212), -INT32_C(  1561408951),  INT32_C(   323493379), -INT32_C(    14736857), -INT32_C(   413125176),
         INT32_C(   262925519),  INT32_C(  1284293098),  INT32_C(  1941894895), -INT32_C(   174855764), -INT32_C(  1231584845), -INT32_C(   943005792), -INT32_C(   892933886), -INT32_C(   307157474) },
      { -INT32_C(    33727213),  INT32_C(   239700254),  INT32_C(  1919561313),  INT32_C(   522958212), -INT32_C(  1561408951),  INT32_C(   323493379),  INT32_C(   728023821), -INT32_C(    65530391),
        -INT32_C(  1845881486),  INT32_C(  1284293098),  INT32_C(  1941894895), -INT32_C(   174855764), -INT32_C(  1231584845),  INT32_C(  1784020573), -INT32_C(   892933886),  INT32_C(  1101508046) },
      UINT16_C(41411) },
    { {  INT32_C(  1910792914), -INT32_C(   862900351),  INT32_C(  1245234795), -INT32_C(  1836884847),  INT32_C(  1821433879), -INT32_C(   551202486), -INT32_C(  1551043332),  INT32_C(   121917237),
         INT32_C(   846735537), -INT32_C(  1006761640),  INT32_C(  1628255952), -INT32_C(  1426812782), -INT32_C(  1172929424), -INT32_C(   761709354),  INT32_C(  1702176048),  INT32_C(   644659573) },
      {  INT32_C(  1910792914), -INT32_C(  1107535891),  INT32_C(   538904974),  INT32_C(   164238233),  INT32_C(  1841553815), -INT32_C(   551202486), -INT32_C(   139283326),  INT32_C(   121917237),
        -INT32_C(   276269566), -INT32_C(  1006761640),  INT32_C(   679267470),  INT32_C(  1982941151),  INT32_C(  1172632872), -INT32_C(   761709354),  INT32_C(  1702176048),  INT32_C(   644659573) },
      UINT16_C( 7518) },
    { {  INT32_C(    10628179),  INT32_C(    97267848), -INT32_C(  1974686888),  INT32_C(   109016098),  INT32_C(  1261031609),  INT32_C(  1854865828), -INT32_C(   615059129), -INT32_C(  1460095659),
         INT32_C(  1789500129),  INT32_C(   594507211),  INT32_C(  1135459105), -INT32_C(   397857745), -INT32_C(  1590463747), -INT32_C(  1156595084),  INT32_C(   144074419), -INT32_C(    55537893) },
      { -INT32_C(   194619095),  INT32_C(    97267848), -INT32_C(  1087126128),  INT32_C(   109016098),  INT32_C(  1653660398),  INT32_C(  1854865828), -INT32_C(   615059129), -INT32_C(  1460095659),
         INT32_C(  1789500129), -INT32_C(   383747751),  INT32_C(  1135459105), -INT32_C(   397857745), -INT32_C(  1590463747), -INT32_C(  1156595084),  INT32_C(   144074419), -INT32_C(    55537893) },
      UINT16_C(  533) },
    { {  INT32_C(   695954952),  INT32_C(    24951384),  INT32_C(   173100266),  INT32_C(   716798986),  INT32_C(  1533544516), -INT32_C(   758556067),  INT32_C(   828653711),  INT32_C(   540244248),
         INT32_C(  1078570984),  INT32_C(  1396819561),  INT32_C(   475894290),  INT32_C(  1397102351),  INT32_C(  2091822879), -INT32_C(  1722910967), -INT32_C(   808799561),  INT32_C(   351337772) },
      {  INT32_C(   695954952),  INT32_C(    24951384),  INT32_C(   908969511),  INT32_C(   716798986),  INT32_C(  1533544516), -INT32_C(   758556067),  INT32_C(   828653711),  INT32_C(   968500877),
         INT32_C(  1078570984),  INT32_C(  1396819561),  INT32_C(  1543609982),  INT32_C(   895060754),  INT32_C(  2091822879), -INT32_C(  1722910967),  INT32_C(  1136332470), -INT32_C(  1820494284) },
      UINT16_C(52356) },
    { {  INT32_C(  1669605618), -INT32_C(   201260301), -INT32_C(  1216408738), -INT32_C(  1450556856), -INT32_C(  1949293389), -INT32_C(   174487751),  INT32_C(  1198247370),  INT32_C(  1393815393),
         INT32_C(   179738391), -INT32_C(   117459046),  INT32_C(   313556682),  INT32_C(  1958492864), -INT32_C(  1728082850), -INT32_C(   561145581), -INT32_C(   953812890), -INT32_C(    14992921) },
      {  INT32_C(  1669605618), -INT32_C(   201260301),  INT32_C(  1197872007), -INT32_C(  1413799347), -INT32_C(  1035748434), -INT32_C(   174487751),  INT32_C(  1198247370), -INT32_C(   810574338),
         INT32_C(   179738391), -INT32_C(   117459046),  INT32_C(   313556682),  INT32_C(  1958492864),  INT32_C(  1514400518), -INT32_C(  2079005764), -INT32_C(   953812890), -INT32_C(  1569266893) },
      UINT16_C(45212) },
    { { -INT32_C(   464757351),  INT32_C(   882244773), -INT32_C(  1602262792),  INT32_C(   764184042), -INT32_C(   200193825),  INT32_C(    25869004), -INT32_C(   656097695), -INT32_C(   108494752),
        -INT32_C(  2099325731), -INT32_C(   910724144), -INT32_C(   966183204), -INT32_C(  1678510660),  INT32_C(   177144893),  INT32_C(   537598654),  INT32_C(   955838424),  INT32_C(  1295089776) },
      {  INT32_C(   634392404),  INT32_C(   882244773),  INT32_C(  2032490429),  INT32_C(   764184042), -INT32_C(   611015651), -INT32_C(  1761894466), -INT32_C(   656097695), -INT32_C(   108494752),
        -INT32_C(  1829954545),  INT32_C(  1643240355),  INT32_C(  2144998962),  INT32_C(  1275785007),  INT32_C(  1378328212), -INT32_C(   840359106),  INT32_C(   955838424),  INT32_C(  1295089776) },
      UINT16_C(16181) },
    { {  INT32_C(  1260050521),  INT32_C(   341920825), -INT32_C(   704409396),  INT32_C(    74749916), -INT32_C(   752373014),  INT32_C(  1267350911),  INT32_C(   426001095),  INT32_C(  1649973513),
        -INT32_C(  1414696335), -INT32_C(  1950412865),  INT32_C(  2086781599),  INT32_C(  1149293914),  INT32_C(   118990728), -INT32_C(  1403805212), -INT32_C(   322586653), -INT32_C(  1051779504) },
      {  INT32_C(  1332542608), -INT32_C(  1411765493),  INT32_C(  1210530798), -INT32_C(  1718835439),  INT32_C(   849388366),  INT32_C(   685699908), -INT32_C(    99310422),  INT32_C(  1649973513),
        -INT32_C(  1414696335),  INT32_C(  1108769876), -INT32_C(   913687112),  INT32_C(   845289188), -INT32_C(    43711815), -INT32_C(  1403805212), -INT32_C(   322586653), -INT32_C(    33794147) },
      UINT16_C(40575) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512i a = simde_mm512_loadu_epi32(test_vec[i].a);
    simde__m512i b = simde_mm512_loadu_epi32(test_vec[i].b);
    simde__mmask16 r = simde_mm512_cmpneq_epi32_mask(a, b);
    simde_assert_equal_mmask16(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m512i a = simde_test_x86_random_i32x16();
    simde__m512i b = simde_mm512_mask_blend_epi32(simde_test_x86_random_mmask16(), a, simde_test_x86_random_i32x16());
    simde__mmask16 r = simde_mm512_cmpneq_epi32_mask(a, b);

    simde_test_x86_write_i32x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_mask_cmpneq_epi32_mask(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  const struct {
    const simde__mmask16 k;
    const int32_t a[16];
    const int32_t b[16];
    const simde__mmask16 r;
  } test_vec[8] = {
    { UINT16_C(54121),
      { -INT32_C(   770343142), -INT32_C(  1583636547),  INT32_C(  1859452341), -INT32_C(   160679680),  INT32_C(  1687589244),  INT32_C(  1762472395),  INT32_C(   140904840), -INT32_C(  1025781849),
         INT32_C(   211087695),  INT32_C(  1185755280),  INT32_C(   766804269),  INT32_C(   925049018),  INT32_C(  2107357874),  INT32_C(  1961273579),  INT32_C(  1501318578),  INT32_C(  1796953884) },
      { -INT32_C(   646467512),  INT32_C(   220145120),  INT32_C(  1631310758), -INT32_C(   160679680),  INT32_C(  1687589244), -INT32_C(  1921512741),  INT32_C(   140904840), -INT32_C(  1025781849),
         INT32_C(   211087695),  INT32_C(   580947067),  INT32_C(  1401150303),  INT32_C(  1392057145),  INT32_C(  2107357874),  INT32_C(  1961273579),  INT32_C(  1501318578),  INT32_C(  1796953884) },
      UINT16_C(  545) },
    { UINT16_C(41701),
      { -INT32_C(    87784038), -INT32_C(  1706211488), -INT32_C(  1326692510), -INT32_C(  1948630428), -INT32_C(   771124976), -INT32_C(   807405009), -INT32_C(   232619573),  INT32_C(   714344591),
        -INT32_C(   299607667),  INT32_C(    59273632),  INT32_C(   481522872), -INT32_C(   962097738),  INT32_C(  1301852190),  INT32_C(  1981642667), -INT32_C(  2006433800), -INT32_C(   709690297) },
      { -INT32_C(    87784038), -INT32_C(  1706211488),  INT32_C(  1964813503), -INT32_C(  1948630428),  INT32_C(   531026804),  INT32_C(  1133888330), -INT32_C(   232619573),  INT32_C(   714344591),
        -INT32_C(  1706696109),  INT32_C(    59273632),  INT32_C(   481522872), -INT32_C(   962097738), -INT32_C(  1190190225), -INT32_C(   369318682), -INT32_C(  2006433800), -INT32_C(   709690297) },
      UINT16_C( 8228) },
    { UINT16_C(24882),
      {  INT32_C(  1515048047), -INT32_C(    25186685), -INT32_C(  1175519926),  INT32_C(   124976416),  INT32_C(  1139830689),  INT32_C(  2078221110), -INT32_C(  1458386059),  INT32_C(  1795835132),
        -INT32_C(  1798940911),  INT32_C(  1335051525),  INT32_C(  1661501762),  INT32_C(   527071870),  INT32_C(   543382249), -INT32_C(   224705923),  INT32_C(   161197325),  INT32_C(    58041842) },
      {  INT32_C(    26688508), -INT32_C(    25186685),  INT32_C(   690378923),  INT32_C(   124976416),  INT32_C(  1139830689), -INT32_C(    61245458), -INT32_C(  1458386059),  INT32_C(  1795835132),
         INT32_C(   915845557),  INT32_C(  1335051525),  INT32_C(  1661501762),  INT32_C(   527071870), -INT32_C(  1811896155), -INT32_C(   224705923),  INT32_C(   161197325),  INT32_C(    58041842) },
      UINT16_C(  288) },
    { UINT16_C(  251),
      {  INT32_C(   898102519), -INT32_C(  1035651053), -INT32_C(   681897423), -INT32_C(   630498374),  INT32_C(    18807732), -INT32_C(  1595443056),  INT32_C(   291922668),  INT32_C(  1779589491),
         INT32_C(  1772067158),  INT32_C(    53274065), -INT32_C(  1311078409), -INT32_C(  1752480285), -INT32_C(   795236032),  INT32_C(   242319394),  INT32_C(  1444992995), -INT32_C(  1899941320) },
      {  INT32_C(   898102519),  INT32_C(  1017128005), -INT32_C(   681897423), -INT32_C(   630498374),  INT32_C(  1171242787), -INT32_C(  1595443056),  INT32_C(   291922668),  INT32_C(  1779589491),
        -INT32_C(   535898470), -INT32_C(  1508069638), -INT32_C(   416019928), -INT32_C(  1752480285),  INT32_C(  1508685081),  INT32_C(   242319394),  INT32_C(  1482552499), -INT32_C(   909558738) },
      UINT16_C(   18) },
    { UINT16_C( 3497),
      { -INT32_C(  1380727419),  INT32_C(  1419044816),  INT32_C(  1543207490),  INT32_C(   649389872), -INT32_C(   650956762),  INT32_C(  1395822884), -INT32_C(   551748659),  INT32_C(  1491912147),
         INT32_C(  1510383498), -INT32_C(   911304057),  INT32_C(  1160030485), -INT32_C(  1217668720),  INT32_C(   764452361), -INT32_C(    58670545), -INT32_C(  1847812930), -INT32_C(   320223135) },
      { -INT32_C(   280563864),  INT32_C(  1419044816),  INT32_C(   803527838), -INT32_C(  1092202571),  INT32_C(   502036205),  INT32_C(  1395822884),  INT32_C(  1787360521),  INT32_C(   643199422),
        -INT32_C(   350904991),  INT32_C(   814402962),  INT32_C(  1600089769), -INT32_C(  1440922179),  INT32_C(   764452361), -INT32_C(    58670545), -INT32_C(  1796639530),  INT32_C(  1186611429) },
      UINT16_C( 3465) },
    { UINT16_C(28465),
      {  INT32_C(  1184873372), -INT32_C(   425328855),  INT32_C(     9552452),  INT32_C(  1123375308),  INT32_C(   281141561),  INT32_C(  1000647253), -INT32_C(   947822614), -INT32_C(   885607634),
        -INT32_C(  1743661458),  INT32_C(   427734741),  INT32_C(  1142558584), -INT32_C(  1585049752),  INT32_C(  1186023409), -INT32_C(   595503374), -INT32_C(   475790411),  INT32_C(   615439030) },
      {  INT32_C(  1184873372), -INT32_C(   425328855),  INT32_C(     9552452), -INT32_C(  1185629752), -INT32_C(   234879744),  INT32_C(  1000647253), -INT32_C(   947822614), -INT32_C(   885607634),
        -INT32_C(   679273630),  INT32_C(   427734741), -INT32_C(  1538000677), -INT32_C(  1585049752),  INT32_C(   144989613),  INT32_C(  1662612447), -INT32_C(   475790411),  INT32_C(   288488879) },
      UINT16_C( 9488) },
    { UINT16_C(28649),
      { -INT32_C(  1290752297),  INT32_C(  1465344934), -INT32_C(  1207323637), -INT32_C(   239031022),  INT32_C(   106223904), -INT32_C(  1774587162),  INT32_C(   145189871), -INT32_C(   143159264),
        -INT32_C(   441809089), -INT32_C(   180551190), -INT32_C(   928168266),  INT32_C(   330919667),  INT32_C(   773393735), -INT32_C(   272346624), -INT32_C(   570987587),  INT32_C(  1003843324) },
      { -INT32_C(  1290752297),  INT32_C(   936729985), -INT32_C(  1761639517), -INT32_C(   239031022),  INT32_C(   106223904), -INT32_C(   759879147), -INT32_C(  1833915242),  INT32_C(   281904411),
        -INT32_C(   441809089), -INT32_C(   180551190),  INT32_C(   981842761),  INT32_C(   963784307),  INT32_C(   117365233), -INT32_C(  1713851645),  INT32_C(  2066450528),  INT32_C(  1003843324) },
      UINT16_C(27872) },
    { UINT16_C(12695),
      { -INT32_C(  1960881086), -INT32_C(  2084199409), -INT32_C(   994297901),  INT32_C(   348830224), -INT32_C(   827481490),  INT32_C(   944363819), -INT32_C(  1219832623), -INT32_C(  1830231472),
         INT32_C(  1159530550),  INT32_C(  2143871660),  INT32_C(   709067802), -INT32_C(  1388442305), -INT32_C(   612635472), -INT32_C(  1777089339), -INT32_C(   380739944),  INT32_C(  1987786304) },
      { -INT32_C(   340027074), -INT32_C(  1788181381), -INT32_C(   994297901),  INT32_C(  1811218107), -INT32_C(  1354338326),  INT32_C(   944363819), -INT32_C(  1219832623), -INT32_C(  1830231472),
         INT32_C(  1159530550),  INT32_C(  2143871660), -INT32_C(   922904052), -INT32_C(  1388442305), -INT32_C(  1791788447), -INT32_C(  1777089339), -INT32_C(   679209459),  INT32_C(   283177542) },
      UINT16_C( 4115) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512i a = simde_mm512_loadu_epi32(test_vec[i].a);
    simde__m512i b = simde_mm512_loadu_epi32(test_vec[i].b);
    simde__mmask16 r = simde_mm512_mask_cmpneq_epi32_mask(test_vec[i].k, a, b);
    simde_assert_equal_mmask16(HEDLEY_STATIC_CAST(uint16_t, r), HEDLEY_STATIC_CAST(uint16_t, test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask16 k1 = simde_test_x86_random_mmask16();
    simde__m512i a = simde_test_x86_random_i32x16();
    simde__m512i b = simde_mm512_mask_blend_epi32(simde_test_x86_random_mmask16(), a, simde_test_x86_random_i32x16());
    simde__mmask16 r = simde_mm512_mask_cmpneq_epi32_mask(k1, a, b);

    simde_test_x86_write_mmask16(2, k1, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x16(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask16(2, r, SIMDE_TEST_VEC_POS_LAST);
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
test_simde_mm256_cmpneq_epi64_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int64_t a[4];
    const int64_t b[4];
    const simde__mmask8 r;
  } test_vec[] = {
    { { -INT64_C( 7984360561282386063),  INT64_C( 7476200742286729838),  INT64_C( 3068913588218698773), -INT64_C( 4872297439509357577) },
      { -INT64_C( 7984360561282386063),  INT64_C( 7838643070071769706), -INT64_C( 2494973417892287088), -INT64_C( 4872297439509357577) },
      UINT8_C(  6) },
    { { -INT64_C( 7151720531883849204), -INT64_C( 3119763195498913872), -INT64_C( 6135143719290344741),  INT64_C( 1636140419016823945) },
      { -INT64_C( 7151720531883849204), -INT64_C( 3119763195498913872), -INT64_C( 6135143719290344741), -INT64_C(  459241604885089408) },
      UINT8_C(  8) },
    { { -INT64_C( 5728634490977594869),  INT64_C( 8450752594526646405), -INT64_C( 6370716386954843990), -INT64_C( 3732409039907708823) },
      { -INT64_C( 5728634490977594869),  INT64_C( 8450752594526646405), -INT64_C( 6370716386954843990),  INT64_C(  590334825510442149) },
      UINT8_C(  8) },
    { { -INT64_C( 6564923823211875277),  INT64_C( 5422522128363866726), -INT64_C( 6501974031944821350), -INT64_C( 8182174813317879184) },
      { -INT64_C( 9134665519247235321),  INT64_C( 6007838981731913200), -INT64_C( 6501974031944821350),  INT64_C( 5929961203005732961) },
      UINT8_C( 11) },
    { {  INT64_C( 3576834628095830413), -INT64_C( 7498425100414568359), -INT64_C( 2428929320544208719), -INT64_C( 2304018566511786058) },
      {  INT64_C( 3576834628095830413), -INT64_C( 7498425100414568359), -INT64_C( 2428929320544208719),  INT64_C( 4539534803223207884) },
      UINT8_C(  8) },
    { {  INT64_C( 2574349795109815954),  INT64_C( 7935791562645422390),  INT64_C( 1055718834904856852),  INT64_C( 6242031710966957390) },
      {  INT64_C( 2574349795109815954),  INT64_C( 4713705501812168090),  INT64_C( 1055718834904856852), -INT64_C( 6512155886846504314) },
      UINT8_C( 10) },
    { {  INT64_C( 3905878312787251648),  INT64_C( 3758154491608903624), -INT64_C(   70073609032711488), -INT64_C( 5571412396041809512) },
      {  INT64_C( 3905878312787251648),  INT64_C( 1044243912522181039), -INT64_C(   70073609032711488), -INT64_C( 5571412396041809512) },
      UINT8_C(  2) },
    { { -INT64_C( 7492420848422311466), -INT64_C( 4476026305742680750), -INT64_C( 2881354835271813243),  INT64_C( 4403846880728112318) },
      {  INT64_C( 1210228867555601220),  INT64_C( 3274445308075487974),  INT64_C( 5909931710787106081),  INT64_C( 4403846880728112318) },
      UINT8_C(  7) },
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
    { UINT8_C( 95),
      {  INT64_C( 9049664824303691032), -INT64_C( 5461238611218841970),  INT64_C( 4179383459606678261), -INT64_C( 6926011177856753227) },
      {  INT64_C( 5022668858637670658),  INT64_C( 1835352245995396184),  INT64_C( 6096769566507235141), -INT64_C( 1019019752052026700) },
      UINT8_C( 15) },
    { UINT8_C( 94),
      { -INT64_C( 3370713918162319832), -INT64_C( 8537539057372340843),  INT64_C( 5521784192085271539), -INT64_C( 6213117551434297204) },
      { -INT64_C( 6613890029409976615), -INT64_C( 8537539057372340843),  INT64_C( 5521784192085271539), -INT64_C( 6213117551434297204) },
      UINT8_C(  0) },
    { UINT8_C(119),
      {  INT64_C( 7397532601893064944),  INT64_C( 6680234377992781537),  INT64_C( 5620874217186901189),  INT64_C( 3318045985951757219) },
      {  INT64_C( 7397532601893064944), -INT64_C( 7647635743074952516),  INT64_C( 5620874217186901189),  INT64_C( 3318045985951757219) },
      UINT8_C(  2) },
    { UINT8_C(238),
      { -INT64_C( 4273448385237949542), -INT64_C( 8252064469733637845), -INT64_C( 4898172880673224712),  INT64_C(  298116541366249372) },
      { -INT64_C( 4273448385237949542), -INT64_C( 8252064469733637845), -INT64_C( 8925781619596740690),  INT64_C( 1105312708346638055) },
      UINT8_C( 12) },
    { UINT8_C( 50),
      {  INT64_C( 8396625640983405670),  INT64_C( 5502142087226413299), -INT64_C( 9007915277067991826), -INT64_C( 9201054041984070970) },
      { -INT64_C( 3392467409527762961),  INT64_C( 5502142087226413299), -INT64_C( 9007915277067991826), -INT64_C(  580847767457645226) },
      UINT8_C(  0) },
    { UINT8_C(242),
      { -INT64_C( 7196659676556339346), -INT64_C(  126802619561840320), -INT64_C( 7963593989015570850), -INT64_C( 1660854670689860847) },
      {  INT64_C(  184756174166519500), -INT64_C(  126802619561840320), -INT64_C( 7963593989015570850), -INT64_C( 1660854670689860847) },
      UINT8_C(  0) },
    { UINT8_C( 60),
      {  INT64_C( 2446142509514924901), -INT64_C( 1711077250346421772), -INT64_C( 6119382349135302995), -INT64_C( 7935343455518148183) },
      {  INT64_C( 2446142509514924901), -INT64_C(  567285004701776918),  INT64_C( 6782683501936975432), -INT64_C( 2349505449931227480) },
      UINT8_C( 12) },
    { UINT8_C(235),
      { -INT64_C( 8659210217316922072), -INT64_C(  881182597493743482), -INT64_C( 2793486479276213539), -INT64_C( 9174648996869015459) },
      { -INT64_C( 1937138966502239898), -INT64_C( 8929986432420069882), -INT64_C( 2793486479276213539), -INT64_C( 5400297197615106506) },
      UINT8_C( 11) },  };

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
test_simde_mm512_cmpneq_epi64_mask(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  const struct {
    const int64_t a[8];
    const int64_t b[8];
    const simde__mmask8 r;
  } test_vec[8] = {
    { {  INT64_C( 8992069421483936085),  INT64_C( 1852616508990972679), -INT64_C( 7359832775155611291), -INT64_C( 8706401244466699657),
        -INT64_C( 6454923121295663249),  INT64_C( 1073148267218459108), -INT64_C( 8228727334713919969),  INT64_C( 7966041999094864083) },
      {  INT64_C( 8992069421483936085),  INT64_C( 5357409075178214817), -INT64_C( 7359832775155611291), -INT64_C( 3094180310901434973),
        -INT64_C( 6454923121295663249), -INT64_C( 8169115481582638804), -INT64_C( 8228727334713919969),  INT64_C( 7966041999094864083) },
      UINT8_C( 42) },
    { {  INT64_C( 6997523965776101976),  INT64_C( 3778432220002349905),  INT64_C( 1314958899830321698), -INT64_C( 6177541956357267877),
         INT64_C( 2761470551529267961),  INT64_C( 5076505809961120553),  INT64_C( 1912494641950495313), -INT64_C( 5015188361565648023) },
      { -INT64_C( 2371429191600373733), -INT64_C( 5198682954383096207),  INT64_C( 1908324138123994787),  INT64_C( 4828206419202715525),
         INT64_C( 2761470551529267961),  INT64_C( 5076505809961120553), -INT64_C( 2631227711271101264), -INT64_C( 3883472256770157904) },
      UINT8_C(207) },
    { {  INT64_C( 9072383314508758094), -INT64_C( 6521738884391461565), -INT64_C( 5811941100654698330), -INT64_C( 7428396996010102792),
         INT64_C( 4237913596063867588), -INT64_C( 7610091680610922828),  INT64_C( 3274561362688040549),  INT64_C( 8909582095799004867) },
      {  INT64_C( 9072383314508758094), -INT64_C( 5264215033761641621), -INT64_C( 8826798248812859874), -INT64_C( 7428396996010102792),
        -INT64_C( 6875067860115876085), -INT64_C( 7610091680610922828), -INT64_C( 6385640209586510310),  INT64_C( 8909582095799004867) },
      UINT8_C( 86) },
    { { -INT64_C( 5293370291667653622),  INT64_C( 6137346565069242662),  INT64_C( 6662244868999612513), -INT64_C( 2731226668725773310),
        -INT64_C(  837306903720713240),  INT64_C( 7588057431989996490), -INT64_C( 4467598594573028550),  INT64_C( 2912872661128480194) },
      {  INT64_C( 4539405721943616317),  INT64_C( 6137346565069242662), -INT64_C( 8450701476202487495),  INT64_C( 1441584911593782424),
         INT64_C(  749320516487075252),  INT64_C( 6831260406272663076), -INT64_C( 4467598594573028550),  INT64_C( 2912872661128480194) },
      UINT8_C( 61) },
    { {  INT64_C( 4438951223252957270), -INT64_C( 6535355536594766236),  INT64_C(  248869166228666647),  INT64_C( 2681453562866669456),
         INT64_C( 3783644701775265191), -INT64_C( 4858423411617242070), -INT64_C( 1795430645923303710), -INT64_C( 8438594634352921360) },
      {  INT64_C( 4438951223252957270), -INT64_C( 6535355536594766236),  INT64_C(  248869166228666647),  INT64_C( 2681453562866669456),
         INT64_C( 7095509361148680680), -INT64_C( 4858423411617242070), -INT64_C( 1085118654790160812), -INT64_C( 8438594634352921360) },
      UINT8_C( 80) },
    { {  INT64_C( 2284414471147119200),  INT64_C( 2182261131878519325), -INT64_C( 2848417487820459512), -INT64_C( 3415558722133898799),
         INT64_C( 1286960719765444066), -INT64_C( 7488556470405587451), -INT64_C( 4973385859769137473),  INT64_C( 1370674496272577220) },
      {  INT64_C( 2284414471147119200), -INT64_C( 4002636798647550902), -INT64_C( 2848417487820459512), -INT64_C( 3415558722133898799),
         INT64_C( 1286960719765444066), -INT64_C( 5318485724914408866), -INT64_C( 7742288097749230873), -INT64_C( 2403455004177631023) },
      UINT8_C(226) },
    { { -INT64_C( 7021150318331556465),  INT64_C( 4625968838939833946),  INT64_C( 1106146731763829419), -INT64_C( 1133124383746311378),
        -INT64_C( 5188797280586465181),  INT64_C( 8002110132764935590),  INT64_C( 5540923009918258238),  INT64_C( 1539096043360181259) },
      { -INT64_C( 7021150318331556465),  INT64_C(   48041795776450167), -INT64_C(  259877333814107655), -INT64_C( 1133124383746311378),
         INT64_C( 4197327104743461439),  INT64_C( 8002110132764935590), -INT64_C( 2473317567949829184),  INT64_C( 1705321472792597784) },
      UINT8_C(214) },
    { { -INT64_C( 6818778852167679228), -INT64_C( 3086737288144710583), -INT64_C( 7103169985339729070),  INT64_C( 4573560708862939422),
         INT64_C( 3419507442535961104), -INT64_C( 6288218776217804261), -INT64_C( 1314090327845546339), -INT64_C( 2993195259224114949) },
      { -INT64_C( 6818778852167679228), -INT64_C( 3086737288144710583), -INT64_C( 7103169985339729070), -INT64_C( 6204608376600033720),
         INT64_C( 7698579939681471852),  INT64_C( 1897212678888357538), -INT64_C(  485797561246703108), -INT64_C( 2993195259224114949) },
      UINT8_C(120) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512i a = simde_mm512_loadu_epi64(test_vec[i].a);
    simde__m512i b = simde_mm512_loadu_epi64(test_vec[i].b);
    simde__mmask8 r = simde_mm512_cmpneq_epi64_mask(a, b);
    simde_assert_equal_mmask8(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m512i a = simde_test_x86_random_i64x8();
    simde__m512i b = simde_mm512_mask_blend_epi64(simde_test_x86_random_mmask8(), a, simde_test_x86_random_i64x8());
    simde__mmask8 r = simde_mm512_cmpneq_epi64_mask(a, b);

    simde_test_x86_write_i64x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i64x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif

}

static int
test_simde_mm512_mask_cmpneq_epi64_mask(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  const struct {
    const simde__mmask8 k;
    const int64_t a[8];
    const int64_t b[8];
    const simde__mmask8 r;
  } test_vec[8] = {
    { UINT8_C(128),
      {  INT64_C( 1025408449201644390),  INT64_C( 6349312643241483048), -INT64_C( 3510818934700781972), -INT64_C( 1903840121569235650),
         INT64_C( 1293197103104912982), -INT64_C(  647204929562394506), -INT64_C( 4318973456270657928),  INT64_C( 5980338284710709657) },
      { -INT64_C( 1056612552664539301),  INT64_C( 6349312643241483048),  INT64_C( 1469112992389369624), -INT64_C( 1903840121569235650),
         INT64_C( 1293197103104912982), -INT64_C(  647204929562394506), -INT64_C( 4318973456270657928),  INT64_C( 5980338284710709657) },
      UINT8_C(  0) },
    { UINT8_C( 68),
      {  INT64_C( 3433547246076285594),  INT64_C( 6410845119708306556),  INT64_C( 8616991946263014915), -INT64_C( 8076960789369970775),
        -INT64_C( 5483547922410713680),  INT64_C( 1235746679606094115), -INT64_C( 1446540301810888976),  INT64_C( 6016378797707740667) },
      {  INT64_C(  590236419604766533),  INT64_C( 6410845119708306556),  INT64_C( 8616991946263014915), -INT64_C( 8076960789369970775),
        -INT64_C( 5483547922410713680),  INT64_C( 7967497640302864171), -INT64_C( 1446540301810888976), -INT64_C( 7566382226929635270) },
      UINT8_C(  0) },
    { UINT8_C(128),
      {  INT64_C( 4869901100157854622),  INT64_C( 2416527442471516484), -INT64_C( 2131804767979812529),  INT64_C( 1352859397427158599),
        -INT64_C( 7478132258348402762),  INT64_C( 4744534449489688527), -INT64_C( 9151202047314629822), -INT64_C( 4987018585939922620) },
      { -INT64_C( 5804602392281380220),  INT64_C( 2004732788789862559), -INT64_C( 2131804767979812529),  INT64_C( 1352859397427158599),
        -INT64_C( 7478132258348402762), -INT64_C( 2316465705665398298), -INT64_C( 9151202047314629822), -INT64_C( 4987018585939922620) },
      UINT8_C(  0) },
    { UINT8_C( 85),
      { -INT64_C( 5667426904876293428),  INT64_C( 3525759886999883777), -INT64_C( 7788374745441617338),  INT64_C(   89088161155567143),
        -INT64_C( 2677605649618987036),  INT64_C( 1399111835612203595),  INT64_C(  567733792368017118), -INT64_C( 6628406122876354612) },
      { -INT64_C( 5667426904876293428), -INT64_C( 5959370824218236053), -INT64_C( 7788374745441617338), -INT64_C( 8034648450007195110),
         INT64_C( 6170390991777515798),  INT64_C( 1399111835612203595),  INT64_C( 4019043880649310779),  INT64_C( 4216373264031871781) },
      UINT8_C( 80) },
    { UINT8_C(174),
      { -INT64_C( 6316550157885258640), -INT64_C( 7115196140026090314), -INT64_C( 6335924115175612839), -INT64_C( 2131870094396410055),
        -INT64_C( 8315813329696998697),  INT64_C( 3703027459122928631),  INT64_C(  245557001664496682), -INT64_C( 8363420129702207077) },
      { -INT64_C( 6316550157885258640), -INT64_C( 7115196140026090314), -INT64_C( 6335924115175612839), -INT64_C( 2131870094396410055),
        -INT64_C( 8304803341403928467), -INT64_C( 3775754842118182343), -INT64_C( 7358311095944602016),  INT64_C( 8455974531685383526) },
      UINT8_C(160) },
    { UINT8_C(126),
      {  INT64_C( 7960429936222096655), -INT64_C( 6436873952366136588),  INT64_C( 3050084081261721332), -INT64_C( 2244547635311387647),
        -INT64_C( 3073942170392084464),  INT64_C( 3278354695372118171),  INT64_C( 4773631162272984517), -INT64_C( 1989053005267398220) },
      { -INT64_C( 2743495649381247690),  INT64_C( 2531922798959612093),  INT64_C( 3738682030703519583), -INT64_C( 2244547635311387647),
        -INT64_C( 3073942170392084464), -INT64_C( 8141933971317981824),  INT64_C( 4171760084708178482), -INT64_C( 1246977321893192304) },
      UINT8_C(102) },
    { UINT8_C(244),
      { -INT64_C(  889562027081327777), -INT64_C( 7584572600785971326),  INT64_C( 4567556748917370849),  INT64_C( 7882423106480316350),
        -INT64_C( 5973815813191792871),  INT64_C( 2779829578409055894),  INT64_C( 3623234359532469088),  INT64_C( 8712499757989322863) },
      {  INT64_C( 6152962450436980875), -INT64_C( 1857482482311326260), -INT64_C( 2033595732863278047), -INT64_C(  617475366564370281),
        -INT64_C( 8260146245273842870), -INT64_C( 5326958373527113562),  INT64_C( 3623234359532469088),  INT64_C( 8712499757989322863) },
      UINT8_C( 52) },
    { UINT8_C(138),
      {  INT64_C( 3269122460588114256), -INT64_C(  756604005122772115),  INT64_C( 5654131381086238832),  INT64_C(  851675914147361897),
         INT64_C( 1909270800196267203), -INT64_C(  888869922990882038), -INT64_C( 7086363211272310063), -INT64_C( 5735134094369215582) },
      {  INT64_C( 4821244382562820385),  INT64_C( 7744961669271879940),  INT64_C( 5654131381086238832), -INT64_C( 2362481333397157479),
        -INT64_C( 4872167228806711320), -INT64_C(  888869922990882038), -INT64_C( 1706026090254442000),  INT64_C( 6962745862463074563) },
      UINT8_C(138) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512i a = simde_mm512_loadu_epi64(test_vec[i].a);
    simde__m512i b = simde_mm512_loadu_epi64(test_vec[i].b);
    simde__mmask8 r = simde_mm512_mask_cmpneq_epi64_mask(test_vec[i].k, a, b);
    simde_assert_equal_mmask8(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k1 = simde_test_x86_random_mmask8();
    simde__m512i a = simde_test_x86_random_i64x8();
    simde__m512i b = simde_mm512_mask_blend_epi64(simde_test_x86_random_mmask8(), a, simde_test_x86_random_i64x8());
    simde__mmask8 r = simde_mm512_mask_cmpneq_epi64_mask(k1, a, b);

    simde_test_x86_write_mmask8(2, k1, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i64x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask8(2, r, SIMDE_TEST_VEC_POS_LAST);
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
test_simde_mm512_cmpneq_epu8_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const uint8_t a[64];
    const uint8_t b[64];
    const simde__mmask64 r;
  } test_vec[] = {
    { { UINT8_C(  5), UINT8_C( 95), UINT8_C( 87), UINT8_C(196), UINT8_C(243), UINT8_C(234), UINT8_C(185), UINT8_C(109),
        UINT8_C(122), UINT8_C(187), UINT8_C(216), UINT8_C(193), UINT8_C(133), UINT8_C( 12), UINT8_C(134), UINT8_C( 56),
        UINT8_C( 58), UINT8_C( 73), UINT8_C( 34), UINT8_C(138), UINT8_C(252), UINT8_C(251), UINT8_C(171), UINT8_C( 34),
        UINT8_C( 23), UINT8_C( 86), UINT8_C(202), UINT8_C(174), UINT8_C( 48), UINT8_C(243), UINT8_C(128), UINT8_C( 53),
        UINT8_C( 83), UINT8_C(215), UINT8_C(250), UINT8_C( 70), UINT8_C(193), UINT8_C(179), UINT8_C(179), UINT8_C( 59),
        UINT8_C(110), UINT8_C(139), UINT8_C(252), UINT8_C(243), UINT8_C(151), UINT8_C(130), UINT8_C( 44), UINT8_C(209),
        UINT8_C(203), UINT8_C( 78), UINT8_C( 91), UINT8_C(199), UINT8_C( 73), UINT8_C(  6), UINT8_C(233), UINT8_C( 96),
        UINT8_C( 93), UINT8_C(179), UINT8_C( 14), UINT8_C(141), UINT8_C(167), UINT8_C(142), UINT8_C(194), UINT8_C(250) },
      { UINT8_C(  5), UINT8_C(188), UINT8_C( 87), UINT8_C( 38), UINT8_C(111), UINT8_C(234), UINT8_C(185), UINT8_C(221),
        UINT8_C(122), UINT8_C( 93), UINT8_C(209), UINT8_C( 23), UINT8_C(133), UINT8_C( 12), UINT8_C(232), UINT8_C( 56),
        UINT8_C( 75), UINT8_C( 68), UINT8_C( 34), UINT8_C(148), UINT8_C( 74), UINT8_C(251), UINT8_C(171), UINT8_C(167),
        UINT8_C( 23), UINT8_C(  3), UINT8_C( 52), UINT8_C(182), UINT8_C(146), UINT8_C(247), UINT8_C(176), UINT8_C( 53),
        UINT8_C(179), UINT8_C(215), UINT8_C( 30), UINT8_C( 35), UINT8_C(193), UINT8_C(179), UINT8_C(  0), UINT8_C(100),
        UINT8_C(110), UINT8_C(139), UINT8_C(123), UINT8_C(188), UINT8_C(206), UINT8_C(130), UINT8_C( 44), UINT8_C( 25),
        UINT8_C(203), UINT8_C(217), UINT8_C( 91), UINT8_C(199), UINT8_C( 73), UINT8_C(163), UINT8_C(153), UINT8_C( 67),
        UINT8_C( 93), UINT8_C(206), UINT8_C( 14), UINT8_C( 56), UINT8_C(167), UINT8_C(169), UINT8_C(194), UINT8_C(120) },
      UINT64_C(12313576737590693530) },
    { { UINT8_C(109), UINT8_C( 93), UINT8_C(103), UINT8_C( 60), UINT8_C(193), UINT8_C(206), UINT8_C( 85), UINT8_C(104),
        UINT8_C(167), UINT8_C(  3), UINT8_C( 90), UINT8_C(219), UINT8_C(166), UINT8_C(244), UINT8_C( 31), UINT8_C( 77),
        UINT8_C(194), UINT8_C( 24), UINT8_C(133), UINT8_C(135), UINT8_C(194), UINT8_C(181),    UINT8_MAX, UINT8_C( 92),
        UINT8_C(  3), UINT8_C(155), UINT8_C(218), UINT8_C(209), UINT8_C( 55), UINT8_C(189), UINT8_C(123), UINT8_C(164),
        UINT8_C( 26), UINT8_C(226), UINT8_C(224), UINT8_C(219), UINT8_C(176), UINT8_C( 54), UINT8_C( 68), UINT8_C( 87),
        UINT8_C( 57), UINT8_C(158), UINT8_C( 51), UINT8_C(224), UINT8_C(146), UINT8_C( 82), UINT8_C( 45), UINT8_C( 84),
        UINT8_C(106), UINT8_C(178), UINT8_C(219), UINT8_C( 44), UINT8_C(104), UINT8_C(219), UINT8_C(136), UINT8_C(107),
        UINT8_C(118), UINT8_C( 99), UINT8_C( 60), UINT8_C(173), UINT8_C( 32), UINT8_C(184), UINT8_C( 81), UINT8_C( 58) },
      { UINT8_C(109), UINT8_C( 93), UINT8_C(103), UINT8_C( 75), UINT8_C(104), UINT8_C(206), UINT8_C(162), UINT8_C(161),
        UINT8_C(167), UINT8_C(  3), UINT8_C( 90), UINT8_C(219), UINT8_C(166), UINT8_C(244), UINT8_C(223), UINT8_C( 77),
        UINT8_C( 97), UINT8_C( 24), UINT8_C(133), UINT8_C(201), UINT8_C(150), UINT8_C(181), UINT8_C( 52), UINT8_C( 12),
        UINT8_C(170), UINT8_C(155), UINT8_C(185), UINT8_C(202), UINT8_C( 55), UINT8_C(189), UINT8_C(  4), UINT8_C(164),
        UINT8_C( 60), UINT8_C(226), UINT8_C(224), UINT8_C(219), UINT8_C(116), UINT8_C(177), UINT8_C( 70), UINT8_C(109),
        UINT8_C(134), UINT8_C(199), UINT8_C(248), UINT8_C(174), UINT8_C(118), UINT8_C( 82), UINT8_C( 45), UINT8_C( 84),
        UINT8_C(106), UINT8_C(254), UINT8_C(219), UINT8_C( 40), UINT8_C( 69), UINT8_C(212), UINT8_C(136), UINT8_C(239),
        UINT8_C(118), UINT8_C( 99), UINT8_C( 60), UINT8_C(110), UINT8_C(248), UINT8_C(190), UINT8_C( 50), UINT8_C( 58) },
      UINT64_C( 8699300751473197272) },
    { { UINT8_C(230), UINT8_C(178), UINT8_C( 38), UINT8_C( 92), UINT8_C(137), UINT8_C(102), UINT8_C( 51), UINT8_C( 28),
        UINT8_C(100), UINT8_C(211), UINT8_C( 68), UINT8_C(170), UINT8_C(168), UINT8_C(121), UINT8_C(153), UINT8_C(237),
        UINT8_C(102), UINT8_C( 83), UINT8_C( 92), UINT8_C( 94), UINT8_C( 17), UINT8_C(142), UINT8_C(147), UINT8_C(233),
        UINT8_C(206), UINT8_C(108), UINT8_C( 54), UINT8_C(192), UINT8_C(139), UINT8_C(240), UINT8_C( 56), UINT8_C(113),
        UINT8_C(162), UINT8_C( 94), UINT8_C(206), UINT8_C( 44), UINT8_C(196), UINT8_C(  1), UINT8_C( 72), UINT8_C( 40),
        UINT8_C(213), UINT8_C(140), UINT8_C(210), UINT8_C(125), UINT8_C(  5), UINT8_C(108), UINT8_C(106), UINT8_C(108),
        UINT8_C(191), UINT8_C(198), UINT8_C(202), UINT8_C(208), UINT8_C( 84), UINT8_C( 93), UINT8_C(185), UINT8_C( 35),
        UINT8_C(201), UINT8_C(240), UINT8_C(227), UINT8_C( 84), UINT8_C(224), UINT8_C( 27), UINT8_C(198), UINT8_C(131) },
      { UINT8_C(230), UINT8_C(178), UINT8_C( 38), UINT8_C( 92), UINT8_C(149), UINT8_C(102), UINT8_C(101), UINT8_C(106),
        UINT8_C(100), UINT8_C(211), UINT8_C( 68), UINT8_C(170), UINT8_C(164), UINT8_C( 82), UINT8_C(153), UINT8_C(237),
        UINT8_C(102), UINT8_C(191), UINT8_C( 51), UINT8_C( 94), UINT8_C( 17), UINT8_C(236), UINT8_C(147), UINT8_C(230),
        UINT8_C(206), UINT8_C(115), UINT8_C( 59), UINT8_C(192), UINT8_C(142), UINT8_C(  1), UINT8_C( 56), UINT8_C(  7),
        UINT8_C(149), UINT8_C( 94), UINT8_C(206), UINT8_C( 42), UINT8_C(230), UINT8_C(  1), UINT8_C(149), UINT8_C(105),
        UINT8_C(225), UINT8_C(124), UINT8_C(210), UINT8_C(133), UINT8_C(206), UINT8_C(231), UINT8_C(106), UINT8_C(108),
        UINT8_C(191), UINT8_C(198), UINT8_C(202), UINT8_C(208), UINT8_C( 84), UINT8_C(228), UINT8_C(185), UINT8_C( 35),
        UINT8_C( 87), UINT8_C(229), UINT8_C(227), UINT8_C(229), UINT8_C(230), UINT8_C(225), UINT8_C(198), UINT8_C(123) },
      UINT64_C(13483843090605551824) },
    { { UINT8_C(183), UINT8_C( 18), UINT8_C( 64), UINT8_C(134), UINT8_C(250), UINT8_C( 41), UINT8_C(109), UINT8_C(161),
        UINT8_C( 68), UINT8_C(193), UINT8_C(101), UINT8_C( 76), UINT8_C(165), UINT8_C( 15), UINT8_C( 49), UINT8_C(252),
        UINT8_C(245), UINT8_C(210), UINT8_C(225), UINT8_C(219), UINT8_C(180), UINT8_C(205), UINT8_C( 87), UINT8_C(132),
        UINT8_C(253), UINT8_C(253), UINT8_C( 59), UINT8_C(214), UINT8_C( 56), UINT8_C( 91), UINT8_C(145), UINT8_C(239),
        UINT8_C(109), UINT8_C(210), UINT8_C(117), UINT8_C(103), UINT8_C(251), UINT8_C(226), UINT8_C(  8), UINT8_C( 63),
        UINT8_C(163), UINT8_C(109), UINT8_C(140), UINT8_C( 72), UINT8_C(125), UINT8_C(189), UINT8_C( 68), UINT8_C(114),
        UINT8_C(143), UINT8_C( 37), UINT8_C( 77), UINT8_C( 67), UINT8_C(242), UINT8_C(164), UINT8_C(200), UINT8_C(239),
        UINT8_C(161), UINT8_C(  3), UINT8_C(198), UINT8_C(217), UINT8_C( 94), UINT8_C( 87), UINT8_C(201), UINT8_C(203) },
      { UINT8_C(183), UINT8_C( 62), UINT8_C( 64), UINT8_C( 36), UINT8_C( 33), UINT8_C( 41), UINT8_C(100), UINT8_C(196),
        UINT8_C( 68), UINT8_C(193), UINT8_C( 13), UINT8_C( 76), UINT8_C(165), UINT8_C( 15), UINT8_C( 49), UINT8_C( 60),
        UINT8_C(245), UINT8_C(229), UINT8_C(225), UINT8_C(219), UINT8_C(138), UINT8_C( 72), UINT8_C( 89), UINT8_C( 43),
        UINT8_C( 75), UINT8_C(253), UINT8_C(  5), UINT8_C(169), UINT8_C(118), UINT8_C(206), UINT8_C(145), UINT8_C(160),
        UINT8_C(109), UINT8_C(210), UINT8_C(196), UINT8_C( 45), UINT8_C(251), UINT8_C( 40), UINT8_C(  8), UINT8_C(140),
        UINT8_C(163), UINT8_C(109), UINT8_C(178), UINT8_C( 72), UINT8_C(125), UINT8_C( 74), UINT8_C(  2), UINT8_C(199),
        UINT8_C( 47), UINT8_C( 37), UINT8_C( 77), UINT8_C(185), UINT8_C(242), UINT8_C(164), UINT8_C(229), UINT8_C(239),
        UINT8_C(169), UINT8_C(  3), UINT8_C(190), UINT8_C(217), UINT8_C( 94), UINT8_C( 87), UINT8_C(191), UINT8_C(196) },
      UINT64_C(14216145129343976666) },
    { { UINT8_C(227), UINT8_C(251), UINT8_C(138), UINT8_C( 51), UINT8_C( 69), UINT8_C(140), UINT8_C(251), UINT8_C(116),
        UINT8_C( 14), UINT8_C( 44), UINT8_C( 46), UINT8_C(216), UINT8_C(182), UINT8_C( 19), UINT8_C(237), UINT8_C( 95),
        UINT8_C(253), UINT8_C(171), UINT8_C(126), UINT8_C(181), UINT8_C(222), UINT8_C( 62), UINT8_C(121), UINT8_C(184),
        UINT8_C(194), UINT8_C(107), UINT8_C(117), UINT8_C(110), UINT8_C( 79), UINT8_C(190), UINT8_C( 51), UINT8_C( 50),
        UINT8_C(185), UINT8_C(190), UINT8_C(102), UINT8_C(254), UINT8_C( 74), UINT8_C( 97), UINT8_C(114), UINT8_C( 89),
        UINT8_C(141), UINT8_C(160), UINT8_C( 49), UINT8_C( 67), UINT8_C(179), UINT8_C( 31), UINT8_C(162), UINT8_C(176),
        UINT8_C(202), UINT8_C( 32), UINT8_C(101), UINT8_C(168), UINT8_C( 94), UINT8_C(223), UINT8_C( 96), UINT8_C( 32),
        UINT8_C( 74), UINT8_C(213), UINT8_C(143), UINT8_C(154), UINT8_C(147), UINT8_C(194), UINT8_C(204), UINT8_C( 76) },
      { UINT8_C(227), UINT8_C( 50), UINT8_C(138), UINT8_C( 51), UINT8_C(147), UINT8_C(189), UINT8_C(251), UINT8_C( 32),
        UINT8_C( 93), UINT8_C( 44), UINT8_C( 46), UINT8_C( 17), UINT8_C(116), UINT8_C(  5), UINT8_C(237), UINT8_C( 95),
        UINT8_C(253), UINT8_C( 39), UINT8_C(126), UINT8_C(132), UINT8_C(  6), UINT8_C( 72), UINT8_C(121), UINT8_C( 80),
        UINT8_C( 29), UINT8_C( 52), UINT8_C(234), UINT8_C(110), UINT8_C(246), UINT8_C(183), UINT8_C( 51), UINT8_C(119),
        UINT8_C(233), UINT8_C( 72), UINT8_C( 66), UINT8_C(125), UINT8_C(  5), UINT8_C( 97), UINT8_C(114), UINT8_C( 98),
        UINT8_C(141), UINT8_C(160), UINT8_C( 49), UINT8_C( 48), UINT8_C(  6), UINT8_C( 31), UINT8_C(111), UINT8_C(176),
        UINT8_C(202), UINT8_C( 86), UINT8_C(101), UINT8_C( 98), UINT8_C(158), UINT8_C(223), UINT8_C( 96), UINT8_C( 32),
        UINT8_C(138), UINT8_C(157), UINT8_C(143), UINT8_C(128), UINT8_C( 84), UINT8_C(194), UINT8_C(247), UINT8_C( 76) },
      UINT64_C( 6564656849851398578) },
    { { UINT8_C( 89), UINT8_C(141), UINT8_C(139), UINT8_C( 95), UINT8_C(194), UINT8_C(250), UINT8_C(140), UINT8_C( 30),
        UINT8_C( 80), UINT8_C( 61), UINT8_C(128), UINT8_C(239), UINT8_C(147), UINT8_C( 51), UINT8_C(171), UINT8_C( 29),
        UINT8_C(208), UINT8_C( 24), UINT8_C(157), UINT8_C( 36), UINT8_C(130), UINT8_C(149), UINT8_C( 97), UINT8_C( 53),
        UINT8_C(206), UINT8_C( 28), UINT8_C(236), UINT8_C(110), UINT8_C(116), UINT8_C(  6), UINT8_C(201), UINT8_C(205),
        UINT8_C(148), UINT8_C( 84), UINT8_C( 44), UINT8_C( 86), UINT8_C( 78), UINT8_C(184), UINT8_C(117), UINT8_C(158),
        UINT8_C(245), UINT8_C(245), UINT8_C(141), UINT8_C(136), UINT8_C( 40), UINT8_C( 56), UINT8_C(165), UINT8_C(248),
        UINT8_C( 80), UINT8_C( 67), UINT8_C( 28), UINT8_C(211), UINT8_C(216), UINT8_C(126), UINT8_C(  8), UINT8_C(166),
        UINT8_C(154), UINT8_C(244), UINT8_C( 20), UINT8_C( 14), UINT8_C(251), UINT8_C(221), UINT8_C(219), UINT8_C(143) },
      { UINT8_C( 49), UINT8_C(141), UINT8_C(229), UINT8_C( 95), UINT8_C(194), UINT8_C(250), UINT8_C( 30), UINT8_C( 30),
        UINT8_C( 80), UINT8_C( 61), UINT8_C(128), UINT8_C(120), UINT8_C(228), UINT8_C( 51), UINT8_C(113), UINT8_C( 29),
        UINT8_C(208), UINT8_C( 24), UINT8_C(  7), UINT8_C( 36), UINT8_C( 11), UINT8_C( 15), UINT8_C(165), UINT8_C( 53),
        UINT8_C(  4), UINT8_C(185), UINT8_C(236), UINT8_C(110), UINT8_C(151), UINT8_C(  6), UINT8_C(201), UINT8_C(205),
        UINT8_C(148), UINT8_C(115), UINT8_C( 72), UINT8_C( 86), UINT8_C(206), UINT8_C(102), UINT8_C(117), UINT8_C( 30),
        UINT8_C( 17), UINT8_C( 73), UINT8_C(150), UINT8_C(245), UINT8_C( 45), UINT8_C(  7), UINT8_C( 42), UINT8_C(248),
        UINT8_C(149), UINT8_C( 67), UINT8_C( 28), UINT8_C(211), UINT8_C( 65), UINT8_C(247), UINT8_C(  8), UINT8_C(166),
        UINT8_C(176), UINT8_C(249), UINT8_C( 68), UINT8_C( 71), UINT8_C(251), UINT8_C(221), UINT8_C( 16), UINT8_C( 30) },
      UINT64_C(14929854659697072197) },
    { { UINT8_C(201), UINT8_C(200), UINT8_C(197), UINT8_C(246), UINT8_C(207), UINT8_C(239), UINT8_C( 73), UINT8_C(100),
        UINT8_C( 32), UINT8_C(155), UINT8_C(  5), UINT8_C( 97), UINT8_C(146), UINT8_C( 75), UINT8_C(166), UINT8_C( 67),
        UINT8_C( 68), UINT8_C(234), UINT8_C(138), UINT8_C(204), UINT8_C(188), UINT8_C(154), UINT8_C(234), UINT8_C(  2),
        UINT8_C(242), UINT8_C( 94), UINT8_C( 21), UINT8_C(176), UINT8_C(222), UINT8_C( 71), UINT8_C(128), UINT8_C(167),
        UINT8_C( 15), UINT8_C( 69), UINT8_C(157), UINT8_C(222), UINT8_C( 52), UINT8_C(230), UINT8_C( 67), UINT8_C( 84),
        UINT8_C(130), UINT8_C( 72), UINT8_C(182), UINT8_C( 20), UINT8_C(147), UINT8_C( 92), UINT8_C( 87), UINT8_C(215),
        UINT8_C( 71), UINT8_C(226), UINT8_C(164), UINT8_C(  3), UINT8_C(124), UINT8_C(142), UINT8_C(  5), UINT8_C(111),
        UINT8_C(237), UINT8_C( 27), UINT8_C( 31), UINT8_C(203), UINT8_C( 98), UINT8_C(159), UINT8_C(114), UINT8_C(113) },
      { UINT8_C(201), UINT8_C( 15), UINT8_C( 79), UINT8_C( 24), UINT8_C(245), UINT8_C(239), UINT8_C(109), UINT8_C(119),
        UINT8_C(218), UINT8_C( 35), UINT8_C(140), UINT8_C( 97), UINT8_C(146), UINT8_C( 75), UINT8_C( 69), UINT8_C( 67),
        UINT8_C(197), UINT8_C(234), UINT8_C(138), UINT8_C( 66), UINT8_C(119), UINT8_C(154), UINT8_C(234), UINT8_C(  2),
        UINT8_C(234), UINT8_C( 94), UINT8_C( 47), UINT8_C( 76), UINT8_C(112), UINT8_C(161), UINT8_C(189), UINT8_C(167),
        UINT8_C(176), UINT8_C( 69), UINT8_C(157), UINT8_C(222), UINT8_C( 52), UINT8_C(218), UINT8_C( 67), UINT8_C( 84),
        UINT8_C(130), UINT8_C(169), UINT8_C(231), UINT8_C( 20), UINT8_C(141), UINT8_C( 44), UINT8_C( 87), UINT8_C(215),
        UINT8_C( 21), UINT8_C( 13), UINT8_C(148), UINT8_C(  3), UINT8_C(220), UINT8_C( 69), UINT8_C(241), UINT8_C(199),
        UINT8_C(237), UINT8_C( 33), UINT8_C( 19), UINT8_C(134), UINT8_C(194), UINT8_C(159), UINT8_C(114), UINT8_C(113) },
      UINT64_C( 2231311657845999582) },
    { { UINT8_C(224), UINT8_C(223), UINT8_C(155), UINT8_C(109), UINT8_C( 11), UINT8_C(222), UINT8_C(191), UINT8_C( 33),
        UINT8_C(235), UINT8_C( 84), UINT8_C(174), UINT8_C(199), UINT8_C(153), UINT8_C(159), UINT8_C(142), UINT8_C(175),
        UINT8_C(192), UINT8_C(162), UINT8_C( 53), UINT8_C(131), UINT8_C(115), UINT8_C( 16), UINT8_C(246), UINT8_C( 81),
        UINT8_C( 87), UINT8_C( 15), UINT8_C(206), UINT8_C(121), UINT8_C( 69), UINT8_C(198), UINT8_C(151), UINT8_C( 37),
        UINT8_C(165), UINT8_C( 50), UINT8_C(146), UINT8_C(176), UINT8_C( 16), UINT8_C( 82), UINT8_C(209), UINT8_C(251),
        UINT8_C(166), UINT8_C(127), UINT8_C(195), UINT8_C( 63), UINT8_C( 31), UINT8_C( 81), UINT8_C(239), UINT8_C(223),
        UINT8_C(243), UINT8_C( 36), UINT8_C( 98), UINT8_C(102), UINT8_C( 52), UINT8_C( 88), UINT8_C(183), UINT8_C(140),
        UINT8_C(103), UINT8_C(134), UINT8_C(  5), UINT8_C(173), UINT8_C( 76), UINT8_C(156), UINT8_C(210), UINT8_C(241) },
      { UINT8_C(224), UINT8_C(101), UINT8_C(155), UINT8_C(223), UINT8_C(183), UINT8_C(222), UINT8_C(219), UINT8_C( 93),
        UINT8_C(235), UINT8_C(158), UINT8_C(174), UINT8_C(199), UINT8_C(153), UINT8_C(139), UINT8_C(241), UINT8_C(175),
        UINT8_C(176), UINT8_C( 83), UINT8_C( 53), UINT8_C(228), UINT8_C(172), UINT8_C( 16), UINT8_C(112), UINT8_C( 19),
        UINT8_C( 87), UINT8_C(117), UINT8_C(206), UINT8_C(121), UINT8_C( 18), UINT8_C(147), UINT8_C(151), UINT8_C(225),
        UINT8_C(248), UINT8_C( 50), UINT8_C(192), UINT8_C(175), UINT8_C(216), UINT8_C(155), UINT8_C( 12), UINT8_C(203),
        UINT8_C( 57), UINT8_C(168), UINT8_C(220), UINT8_C( 63), UINT8_C( 31), UINT8_C(205), UINT8_C( 12), UINT8_C(228),
        UINT8_C( 33), UINT8_C( 36), UINT8_C(200), UINT8_C(205), UINT8_C( 86), UINT8_C( 57), UINT8_C(224), UINT8_C(140),
        UINT8_C(174), UINT8_C(161), UINT8_C(176), UINT8_C(173), UINT8_C( 52), UINT8_C(116), UINT8_C(210), UINT8_C(241) },
      UINT64_C( 3998607120988332762) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512i a = simde_x_mm512_loadu_epu8(test_vec[i].a);
    simde__m512i b = simde_x_mm512_loadu_epu8(test_vec[i].b);
    simde__mmask64 r = simde_mm512_cmpneq_epu8_mask(a, b);
    simde_assert_equal_mmask64(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m512i a = simde_test_x86_random_u8x64();
    simde__m512i b = simde_x_mm512_mask_blend_epu8(simde_test_x86_random_mmask64(), a, simde_test_x86_random_u8x64());
    simde__mmask64 r = simde_mm512_cmpneq_epu8_mask(a, b);

    simde_test_x86_write_u8x64(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_u8x64(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask64(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_mask_cmpneq_epu8_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask64 k1;
    const uint8_t a[64];
    const uint8_t b[64];
    const simde__mmask64 r;
  } test_vec[] = {
    { UINT64_C( 5235272009878887055),
      { UINT8_C(193), UINT8_C(112), UINT8_C( 21), UINT8_C( 24), UINT8_C(169), UINT8_C(246), UINT8_C(245), UINT8_C( 87),
        UINT8_C(151), UINT8_C(166), UINT8_C( 24), UINT8_C(203), UINT8_C( 26), UINT8_C(185), UINT8_C(247), UINT8_C(244),
        UINT8_C( 27), UINT8_C(210), UINT8_C(167), UINT8_C( 25), UINT8_C(185), UINT8_C( 36), UINT8_C( 80), UINT8_C( 72),
        UINT8_C(126), UINT8_C(176), UINT8_C( 12), UINT8_C(166), UINT8_C( 28), UINT8_C(179), UINT8_C(238), UINT8_C(221),
        UINT8_C( 35), UINT8_C(  4), UINT8_C(245), UINT8_C(204), UINT8_C(250), UINT8_C(235), UINT8_C( 36), UINT8_C(145),
        UINT8_C(145), UINT8_C( 60), UINT8_C( 92), UINT8_C(171), UINT8_C(245), UINT8_C( 83), UINT8_C(160), UINT8_C( 17),
        UINT8_C( 37), UINT8_C( 71), UINT8_C( 42), UINT8_C(222), UINT8_C(107), UINT8_C(122), UINT8_C( 38), UINT8_C(234),
        UINT8_C( 42), UINT8_C( 50), UINT8_C(144), UINT8_C( 70), UINT8_C(230), UINT8_C(126), UINT8_C( 35), UINT8_C(  9) },
      { UINT8_C(193), UINT8_C( 25), UINT8_C( 21), UINT8_C( 24), UINT8_C(169), UINT8_C(246), UINT8_C( 13), UINT8_C( 87),
        UINT8_C( 54), UINT8_C(105), UINT8_C( 64), UINT8_C( 43), UINT8_C( 26), UINT8_C(224), UINT8_C(247), UINT8_C(225),
        UINT8_C( 27), UINT8_C(102), UINT8_C(167), UINT8_C(147), UINT8_C(185), UINT8_C(230), UINT8_C( 80), UINT8_C( 10),
        UINT8_C(126), UINT8_C( 13), UINT8_C( 12), UINT8_C(254), UINT8_C(139), UINT8_C(179), UINT8_C(238), UINT8_C(221),
        UINT8_C(141), UINT8_C(222), UINT8_C(138), UINT8_C(204), UINT8_C(250), UINT8_C(235), UINT8_C( 38), UINT8_C(145),
        UINT8_C(145), UINT8_C( 60), UINT8_C( 92), UINT8_C(171), UINT8_C( 71), UINT8_C( 83), UINT8_C(159), UINT8_C(110),
        UINT8_C( 37), UINT8_C( 71), UINT8_C( 42), UINT8_C(189), UINT8_C(107), UINT8_C(126), UINT8_C( 38), UINT8_C(234),
        UINT8_C(139), UINT8_C( 50), UINT8_C(144), UINT8_C( 23), UINT8_C(230), UINT8_C(126), UINT8_C( 37), UINT8_C(  9) },
      UINT64_C( 5197224368830155266) },
    { UINT64_C(13036978465776558390),
      { UINT8_C(  5), UINT8_C(237), UINT8_C(113), UINT8_C( 74), UINT8_C(108), UINT8_C( 56), UINT8_C(168), UINT8_C(247),
        UINT8_C( 80), UINT8_C(  4), UINT8_C( 14), UINT8_C(220), UINT8_C(104), UINT8_C( 51), UINT8_C(245), UINT8_C(170),
        UINT8_C(227), UINT8_C(159), UINT8_C(196), UINT8_C( 42), UINT8_C(111), UINT8_C(236), UINT8_C(115), UINT8_C(166),
        UINT8_C( 77), UINT8_C(122), UINT8_C( 35), UINT8_C( 37), UINT8_C( 33), UINT8_C( 15), UINT8_C(217), UINT8_C( 38),
        UINT8_C(253), UINT8_C( 74), UINT8_C(113), UINT8_C(105), UINT8_C(130), UINT8_C( 25), UINT8_C( 96), UINT8_C(211),
        UINT8_C( 29), UINT8_C(111), UINT8_C(175), UINT8_C(133), UINT8_C(162), UINT8_C(165), UINT8_C( 47), UINT8_C(133),
        UINT8_C( 68), UINT8_C(243), UINT8_C(176), UINT8_C(180), UINT8_C(223), UINT8_C( 35), UINT8_C( 90), UINT8_C( 44),
        UINT8_C(158), UINT8_C(125), UINT8_C( 81), UINT8_C(191), UINT8_C(141), UINT8_C( 42), UINT8_C(229), UINT8_C(138) },
      { UINT8_C(116), UINT8_C( 86), UINT8_C(113), UINT8_C(247), UINT8_C(111), UINT8_C( 56), UINT8_C(202), UINT8_C(140),
        UINT8_C(194), UINT8_C(121), UINT8_C( 14), UINT8_C(101), UINT8_C(104), UINT8_C( 51), UINT8_C(234), UINT8_C( 99),
        UINT8_C( 51), UINT8_C(154), UINT8_C(196), UINT8_C( 18), UINT8_C(111), UINT8_C(236), UINT8_C( 63), UINT8_C(166),
        UINT8_C(238), UINT8_C(144), UINT8_C( 27), UINT8_C( 37), UINT8_C( 33), UINT8_C(  0), UINT8_C(217), UINT8_C( 38),
        UINT8_C(253), UINT8_C( 74), UINT8_C( 38), UINT8_C(198), UINT8_C( 76), UINT8_C(240), UINT8_C( 96), UINT8_C( 14),
        UINT8_C( 29), UINT8_C(100), UINT8_C(115), UINT8_C(136), UINT8_C(165), UINT8_C(165), UINT8_C( 47), UINT8_C(216),
        UINT8_C( 68), UINT8_C(  2), UINT8_C(235), UINT8_C(180), UINT8_C(115), UINT8_C( 42), UINT8_C( 90), UINT8_C( 44),
        UINT8_C(158), UINT8_C( 45), UINT8_C(221), UINT8_C(191), UINT8_C(141), UINT8_C(227), UINT8_C(229), UINT8_C(138) },
      UINT64_C( 2604354455361241362) },
    { UINT64_C(   36198154704431363),
      { UINT8_C(156), UINT8_C(107), UINT8_C(182), UINT8_C( 16), UINT8_C(149), UINT8_C(201), UINT8_C(114), UINT8_C( 80),
        UINT8_C(246), UINT8_C( 79), UINT8_C(197), UINT8_C( 36), UINT8_C( 50), UINT8_C(106), UINT8_C(169), UINT8_C( 14),
        UINT8_C( 54), UINT8_C(245), UINT8_C( 53), UINT8_C(242), UINT8_C(147), UINT8_C(107), UINT8_C( 24), UINT8_C(150),
        UINT8_C( 21), UINT8_C(198), UINT8_C( 62), UINT8_C( 28), UINT8_C( 96), UINT8_C(191), UINT8_C( 28), UINT8_C(253),
        UINT8_C( 42), UINT8_C(211), UINT8_C( 13), UINT8_C(192), UINT8_C(156), UINT8_C(127), UINT8_C( 16), UINT8_C(146),
        UINT8_C(206), UINT8_C(213), UINT8_C(183), UINT8_C(  1), UINT8_C( 64), UINT8_C( 96), UINT8_C( 15), UINT8_C(118),
        UINT8_C( 85), UINT8_C( 68), UINT8_C(104), UINT8_C(233), UINT8_C(176), UINT8_C(128), UINT8_C(127), UINT8_C(197),
        UINT8_C( 70), UINT8_C(190), UINT8_C(225), UINT8_C(167), UINT8_C(125), UINT8_C(254), UINT8_C(164), UINT8_C(167) },
      { UINT8_C(209), UINT8_C(177), UINT8_C(182), UINT8_C( 16), UINT8_C(149), UINT8_C(201),    UINT8_MAX, UINT8_C(254),
        UINT8_C( 77), UINT8_C(182),    UINT8_MAX, UINT8_C( 36), UINT8_C( 23), UINT8_C( 14), UINT8_C(169), UINT8_C( 14),
        UINT8_C( 83), UINT8_C(107), UINT8_C( 53), UINT8_C(  3), UINT8_C(235), UINT8_C(107), UINT8_C(200), UINT8_C( 49),
        UINT8_C(147), UINT8_C(198), UINT8_C( 62), UINT8_C( 16), UINT8_C(167), UINT8_C(191), UINT8_C(183), UINT8_C(253),
        UINT8_C( 42), UINT8_C(211), UINT8_C(229), UINT8_C( 93), UINT8_C(150), UINT8_C(127), UINT8_C( 16), UINT8_C(146),
        UINT8_C(155), UINT8_C( 91), UINT8_C(112), UINT8_C(  1), UINT8_C(106), UINT8_C(115), UINT8_C( 15), UINT8_C(118),
        UINT8_C(222), UINT8_C( 68), UINT8_C(192), UINT8_C(201), UINT8_C( 73), UINT8_C(136), UINT8_C(127), UINT8_C(197),
        UINT8_C( 49), UINT8_C(211), UINT8_C(236), UINT8_C(167), UINT8_C( 80), UINT8_C(164), UINT8_C(164), UINT8_C(125) },
      UINT64_C(      19808532439299) },
    { UINT64_C(18426910129424870802),
      { UINT8_C(253), UINT8_C(121), UINT8_C(201), UINT8_C( 71), UINT8_C(  1), UINT8_C(196), UINT8_C( 35), UINT8_C( 51),
        UINT8_C(151), UINT8_C( 16), UINT8_C( 12), UINT8_C(231), UINT8_C(180), UINT8_C( 93), UINT8_C(101), UINT8_C(119),
        UINT8_C(148), UINT8_C( 64), UINT8_C(208), UINT8_C(176), UINT8_C(119), UINT8_C( 13), UINT8_C(104), UINT8_C(  9),
        UINT8_C(187), UINT8_C(210), UINT8_C(  6), UINT8_C(220), UINT8_C( 91), UINT8_C(191), UINT8_C(219), UINT8_C( 88),
        UINT8_C( 57), UINT8_C(164), UINT8_C(159), UINT8_C( 58), UINT8_C(104), UINT8_C(195), UINT8_C(109), UINT8_C(  0),
        UINT8_C(211), UINT8_C(121), UINT8_C(231), UINT8_C(135), UINT8_C(215), UINT8_C( 76), UINT8_C(254), UINT8_C(107),
        UINT8_C(140), UINT8_C(206), UINT8_C( 28), UINT8_C(  3), UINT8_C(220), UINT8_C(132), UINT8_C( 13), UINT8_C(151),
        UINT8_C( 86), UINT8_C( 19), UINT8_C(115), UINT8_C(177), UINT8_C(210), UINT8_C( 78), UINT8_C(  9), UINT8_C( 11) },
      { UINT8_C(253), UINT8_C(169), UINT8_C( 70), UINT8_C( 91), UINT8_C(108), UINT8_C(179), UINT8_C( 91), UINT8_C( 51),
        UINT8_C( 45), UINT8_C( 67), UINT8_C( 12), UINT8_C(231), UINT8_C(143), UINT8_C( 93), UINT8_C(101), UINT8_C(119),
        UINT8_C(148), UINT8_C( 64), UINT8_C( 31), UINT8_C(110), UINT8_C(119), UINT8_C( 44), UINT8_C(  5), UINT8_C(101),
        UINT8_C( 63), UINT8_C(210), UINT8_C( 22), UINT8_C(220), UINT8_C(199), UINT8_C(191), UINT8_C(219), UINT8_C(186),
        UINT8_C( 57), UINT8_C(164), UINT8_C( 21), UINT8_C( 58), UINT8_C(104), UINT8_C(195), UINT8_C(109), UINT8_C( 68),
        UINT8_C(211), UINT8_C(121), UINT8_C(231), UINT8_C(135), UINT8_C(215), UINT8_C(183), UINT8_C( 95), UINT8_C(107),
        UINT8_C( 67), UINT8_C(206), UINT8_C( 28), UINT8_C( 82), UINT8_C(171), UINT8_C(132), UINT8_C(184), UINT8_C(235),
        UINT8_C( 86), UINT8_C( 19), UINT8_C(115), UINT8_C( 68), UINT8_C(238), UINT8_C( 26), UINT8_C(  9), UINT8_C( 11) },
      UINT64_C( 4078290940050538770) },
    { UINT64_C( 1957337236386881946),
      { UINT8_C( 90), UINT8_C( 40), UINT8_C(110), UINT8_C(  6), UINT8_C( 44), UINT8_C( 38), UINT8_C(241), UINT8_C(169),
        UINT8_C(244), UINT8_C(238), UINT8_C(237), UINT8_C(227), UINT8_C(  8), UINT8_C(235), UINT8_C(154), UINT8_C(134),
           UINT8_MAX, UINT8_C(135), UINT8_C( 27), UINT8_C(131), UINT8_C(231), UINT8_C(244), UINT8_C(188), UINT8_C(130),
        UINT8_C( 21), UINT8_C( 56), UINT8_C( 26), UINT8_C(238), UINT8_C( 19), UINT8_C( 67), UINT8_C(  9), UINT8_C(110),
        UINT8_C(107), UINT8_C(119), UINT8_C(116), UINT8_C(152), UINT8_C(157), UINT8_C(101), UINT8_C( 65), UINT8_C(146),
        UINT8_C( 83), UINT8_C( 47), UINT8_C(117), UINT8_C( 91), UINT8_C( 26), UINT8_C( 15), UINT8_C(226), UINT8_C( 25),
        UINT8_C(150), UINT8_C(253), UINT8_C(157), UINT8_C(126), UINT8_C(242), UINT8_C( 89), UINT8_C(  0), UINT8_C(  7),
        UINT8_C(145), UINT8_C( 26), UINT8_C(245), UINT8_C(164), UINT8_C( 94),    UINT8_MAX, UINT8_C( 18), UINT8_C(201) },
      { UINT8_C(118), UINT8_C( 40), UINT8_C(110), UINT8_C(  6), UINT8_C(235), UINT8_C( 38), UINT8_C(241), UINT8_C( 62),
        UINT8_C(244), UINT8_C( 27), UINT8_C(237), UINT8_C(227), UINT8_C(  8), UINT8_C(235), UINT8_C(154), UINT8_C(134),
           UINT8_MAX, UINT8_C(135), UINT8_C( 63), UINT8_C(107), UINT8_C(231), UINT8_C( 63), UINT8_C(115), UINT8_C(130),
        UINT8_C( 21), UINT8_C(104), UINT8_C( 49), UINT8_C(238), UINT8_C(103), UINT8_C( 67), UINT8_C(  9), UINT8_C(110),
        UINT8_C(107), UINT8_C(226), UINT8_C(116), UINT8_C(182), UINT8_C(133), UINT8_C(101), UINT8_C( 65), UINT8_C( 87),
        UINT8_C( 83), UINT8_C( 47), UINT8_C(117), UINT8_C( 91), UINT8_C( 26), UINT8_C( 74), UINT8_C(158), UINT8_C( 25),
        UINT8_C(150), UINT8_C(221), UINT8_C(239), UINT8_C(233), UINT8_C(242), UINT8_C( 98), UINT8_C(118), UINT8_C(  7),
        UINT8_C(203), UINT8_C( 26), UINT8_C( 45), UINT8_C( 50), UINT8_C( 94),    UINT8_MAX, UINT8_C( 16), UINT8_C(201) },
      UINT64_C(  659848367264497808) },
    { UINT64_C(16824825871275373295),
      { UINT8_C(167), UINT8_C(109), UINT8_C(210), UINT8_C(195), UINT8_C(207), UINT8_C( 72), UINT8_C( 57), UINT8_C(154),
        UINT8_C(239), UINT8_C(103), UINT8_C(205), UINT8_C(219), UINT8_C( 21), UINT8_C(221), UINT8_C(145), UINT8_C(166),
        UINT8_C(224), UINT8_C(253), UINT8_C(189), UINT8_C(122), UINT8_C( 93), UINT8_C( 43), UINT8_C(200), UINT8_C( 76),
        UINT8_C(221), UINT8_C(243), UINT8_C( 70), UINT8_C(217), UINT8_C(188), UINT8_C(195), UINT8_C(194), UINT8_C( 99),
        UINT8_C( 48), UINT8_C(148), UINT8_C( 39), UINT8_C(  0), UINT8_C(220), UINT8_C( 96), UINT8_C(154), UINT8_C(203),
        UINT8_C(199), UINT8_C(103), UINT8_C(166), UINT8_C(221), UINT8_C( 69), UINT8_C( 55), UINT8_C(131), UINT8_C( 37),
        UINT8_C( 52), UINT8_C( 64), UINT8_C(159), UINT8_C(146), UINT8_C(107), UINT8_C(103), UINT8_C(222), UINT8_C( 72),
        UINT8_C( 90), UINT8_C( 36), UINT8_C( 33), UINT8_C( 23), UINT8_C(232), UINT8_C(227), UINT8_C(122), UINT8_C( 24) },
      { UINT8_C(167), UINT8_C(161), UINT8_C(210), UINT8_C(195), UINT8_C(207), UINT8_C( 72), UINT8_C( 57), UINT8_C(201),
        UINT8_C( 26), UINT8_C(103), UINT8_C(205), UINT8_C(219), UINT8_C( 21), UINT8_C(221), UINT8_C(145), UINT8_C(166),
        UINT8_C(106), UINT8_C( 36), UINT8_C(195), UINT8_C(214), UINT8_C( 93), UINT8_C( 43), UINT8_C( 30), UINT8_C(230),
        UINT8_C(198), UINT8_C(243), UINT8_C(253), UINT8_C(217), UINT8_C( 35), UINT8_C(195), UINT8_C(194), UINT8_C( 99),
        UINT8_C( 48), UINT8_C(223), UINT8_C(238), UINT8_C( 27), UINT8_C(220), UINT8_C( 96), UINT8_C(154), UINT8_C(203),
        UINT8_C(211), UINT8_C(139), UINT8_C(166), UINT8_C(221), UINT8_C(181), UINT8_C(145), UINT8_C(131), UINT8_C( 31),
        UINT8_C( 52), UINT8_C(197), UINT8_C(159), UINT8_C(146), UINT8_C(107), UINT8_C(103), UINT8_C( 38), UINT8_C( 45),
        UINT8_C( 84), UINT8_C( 36), UINT8_C( 33), UINT8_C( 23), UINT8_C(232), UINT8_C(163), UINT8_C( 18), UINT8_C(180) },
      UINT64_C(16231114945868791938) },
    { UINT64_C( 1446697130007842366),
      { UINT8_C(120), UINT8_C(  8), UINT8_C( 85), UINT8_C(223), UINT8_C( 28), UINT8_C(123), UINT8_C( 12), UINT8_C(112),
        UINT8_C(159), UINT8_C(232), UINT8_C(232), UINT8_C( 58), UINT8_C(139), UINT8_C(250), UINT8_C(238), UINT8_C( 14),
        UINT8_C(251), UINT8_C(189), UINT8_C( 35), UINT8_C( 10), UINT8_C(112), UINT8_C(229), UINT8_C(235), UINT8_C(175),
        UINT8_C(179), UINT8_C(157), UINT8_C(162), UINT8_C( 19), UINT8_C( 80), UINT8_C(181), UINT8_C( 39), UINT8_C(200),
        UINT8_C(190), UINT8_C(124), UINT8_C(167), UINT8_C(218), UINT8_C(248), UINT8_C(179), UINT8_C( 75), UINT8_C(151),
        UINT8_C(156), UINT8_C( 51), UINT8_C(209), UINT8_C( 39), UINT8_C( 45), UINT8_C(191), UINT8_C( 53), UINT8_C( 41),
        UINT8_C(124), UINT8_C( 88), UINT8_C( 51), UINT8_C(236), UINT8_C( 61), UINT8_C( 30), UINT8_C(155), UINT8_C(241),
        UINT8_C(187), UINT8_C( 62), UINT8_C(  4), UINT8_C( 11), UINT8_C(243), UINT8_C( 43), UINT8_C(211), UINT8_C(177) },
      { UINT8_C(120), UINT8_C(122), UINT8_C(140), UINT8_C(223), UINT8_C( 46), UINT8_C(123), UINT8_C( 55), UINT8_C(112),
        UINT8_C(159), UINT8_C(232), UINT8_C(241), UINT8_C( 55), UINT8_C(199), UINT8_C( 39), UINT8_C( 96), UINT8_C( 67),
        UINT8_C(127), UINT8_C(147), UINT8_C( 47), UINT8_C( 10), UINT8_C(112), UINT8_C(203), UINT8_C(174), UINT8_C(109),
        UINT8_C(  9), UINT8_C(178), UINT8_C(121), UINT8_C( 19), UINT8_C( 80), UINT8_C( 76), UINT8_C(174), UINT8_C(200),
        UINT8_C(199), UINT8_C(124), UINT8_C(167), UINT8_C(245), UINT8_C( 17), UINT8_C(179), UINT8_C(191), UINT8_C(151),
        UINT8_C(156), UINT8_C(176), UINT8_C( 82), UINT8_C( 39), UINT8_C( 45), UINT8_C(179), UINT8_C( 53), UINT8_C( 87),
        UINT8_C(124), UINT8_C(158), UINT8_C( 51), UINT8_C(236), UINT8_C( 61), UINT8_C( 30), UINT8_C(155), UINT8_C(114),
        UINT8_C(116), UINT8_C( 62), UINT8_C(110), UINT8_C( 81), UINT8_C( 43), UINT8_C( 28), UINT8_C(211), UINT8_C(242) },
      UINT64_C( 1441893335519317014) },
    { UINT64_C(14881396786129917271),
      { UINT8_C(245), UINT8_C(153), UINT8_C(199), UINT8_C( 94), UINT8_C( 91), UINT8_C( 45), UINT8_C(208), UINT8_C(207),
        UINT8_C( 12), UINT8_C( 63), UINT8_C( 33), UINT8_C( 55), UINT8_C( 91), UINT8_C(248), UINT8_C( 42), UINT8_C(178),
        UINT8_C(244), UINT8_C( 17), UINT8_C( 25), UINT8_C( 77), UINT8_C(184), UINT8_C(156), UINT8_C( 11), UINT8_C( 15),
        UINT8_C(113), UINT8_C(244), UINT8_C( 61), UINT8_C(249), UINT8_C( 75), UINT8_C(195), UINT8_C(199), UINT8_C( 65),
        UINT8_C( 92), UINT8_C(142), UINT8_C(159), UINT8_C(184), UINT8_C(187), UINT8_C(112), UINT8_C(135), UINT8_C(199),
        UINT8_C(175), UINT8_C(168),    UINT8_MAX, UINT8_C( 10), UINT8_C(160), UINT8_C( 41), UINT8_C(188), UINT8_C(149),
        UINT8_C( 58), UINT8_C(214), UINT8_C(226), UINT8_C(242), UINT8_C(114), UINT8_C(237), UINT8_C(  1), UINT8_C(227),
        UINT8_C(225), UINT8_C( 63), UINT8_C(220), UINT8_C( 45), UINT8_C(  2), UINT8_C(163), UINT8_C(110), UINT8_C( 94) },
      { UINT8_C(245), UINT8_C(153), UINT8_C( 22), UINT8_C( 94), UINT8_C(125), UINT8_C(158), UINT8_C(208), UINT8_C(207),
        UINT8_C( 12), UINT8_C( 63), UINT8_C( 55), UINT8_C( 55), UINT8_C(221), UINT8_C(243), UINT8_C(124), UINT8_C( 23),
        UINT8_C(201), UINT8_C( 17), UINT8_C( 10), UINT8_C( 59), UINT8_C(184), UINT8_C( 11), UINT8_C( 11), UINT8_C( 15),
        UINT8_C( 74), UINT8_C(250), UINT8_C( 61), UINT8_C(249), UINT8_C(158), UINT8_C(195), UINT8_C(199), UINT8_C(208),
        UINT8_C( 92), UINT8_C(193), UINT8_C(189), UINT8_C(184), UINT8_C(187), UINT8_C(114), UINT8_C(128), UINT8_C(199),
        UINT8_C( 38), UINT8_C(168), UINT8_C(141), UINT8_C(  3), UINT8_C(160), UINT8_C(  9), UINT8_C(188), UINT8_C(116),
        UINT8_C(103), UINT8_C(214), UINT8_C(226), UINT8_C(179), UINT8_C( 48), UINT8_C(206), UINT8_C(  1), UINT8_C(227),
        UINT8_C(200), UINT8_C( 63), UINT8_C(199), UINT8_C(102), UINT8_C(  2), UINT8_C(163), UINT8_C(110), UINT8_C(218) },
      UINT64_C(10088350137881056276) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512i a = simde_x_mm512_loadu_epu8(test_vec[i].a);
    simde__m512i b = simde_x_mm512_loadu_epu8(test_vec[i].b);
    simde__mmask64 r = simde_mm512_mask_cmpneq_epu8_mask(test_vec[i].k1, a, b);
    simde_assert_equal_mmask64(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask64 k1 = simde_test_x86_random_mmask64();
    simde__m512i a = simde_test_x86_random_u8x64();
    simde__m512i b = simde_x_mm512_mask_blend_epu8(simde_test_x86_random_mmask64(), a, simde_test_x86_random_u8x64());
    simde__mmask64 r = simde_mm512_mask_cmpneq_epu8_mask(k1, a, b);

    simde_test_x86_write_mmask64(2, k1, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_u8x64(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_u8x64(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask64(2, r, SIMDE_TEST_VEC_POS_LAST);
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
test_simde_mm512_cmpneq_epu16_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const uint16_t a[32];
    const uint16_t b[32];
    const simde__mmask32 r;
  } test_vec[] = {
    { { UINT16_C(50788), UINT16_C( 3984), UINT16_C(43983), UINT16_C(14211), UINT16_C(13008), UINT16_C(  490), UINT16_C(51968), UINT16_C(51580),
        UINT16_C(17159), UINT16_C( 2863), UINT16_C(26294), UINT16_C(60133), UINT16_C( 4698), UINT16_C(49277), UINT16_C(47040), UINT16_C( 9293),
        UINT16_C(56957), UINT16_C(19763), UINT16_C(46729), UINT16_C(23172), UINT16_C(28393), UINT16_C(59739), UINT16_C(55098), UINT16_C(16818),
        UINT16_C(57882), UINT16_C(53324), UINT16_C(12616), UINT16_C(41658), UINT16_C(14403), UINT16_C(  866), UINT16_C(45295), UINT16_C(27688) },
      { UINT16_C(23438), UINT16_C( 6073), UINT16_C(43983), UINT16_C(14211), UINT16_C(52396), UINT16_C(59108), UINT16_C(51968), UINT16_C(51580),
        UINT16_C(29561), UINT16_C(49550), UINT16_C(18852), UINT16_C(59235), UINT16_C(50561), UINT16_C(28907), UINT16_C( 4981), UINT16_C(  988),
        UINT16_C(38510), UINT16_C(32795), UINT16_C(46729), UINT16_C(23172), UINT16_C(24665), UINT16_C(64613), UINT16_C(36087), UINT16_C(28858),
        UINT16_C(57882), UINT16_C(53324), UINT16_C(38034), UINT16_C( 5003), UINT16_C(30297), UINT16_C(53123), UINT16_C(24457), UINT16_C(63442) },
      UINT32_C(4243849011) },
    { { UINT16_C(62330), UINT16_C(54088), UINT16_C(44627), UINT16_C(19151), UINT16_C(35386), UINT16_C(15034), UINT16_C(60371), UINT16_C(26077),
        UINT16_C(26751), UINT16_C(55672), UINT16_C(64478), UINT16_C(26536), UINT16_C(31322), UINT16_C(20575), UINT16_C(55144), UINT16_C(57881),
        UINT16_C(25034), UINT16_C( 7861), UINT16_C(33807), UINT16_C(19048), UINT16_C( 8974), UINT16_C(57732), UINT16_C(24846), UINT16_C(36422),
        UINT16_C(48842), UINT16_C(43111), UINT16_C( 4025), UINT16_C( 5136), UINT16_C(28553), UINT16_C(61796), UINT16_C(32070), UINT16_C( 4307) },
      { UINT16_C(35038), UINT16_C(60974), UINT16_C(38669), UINT16_C( 6968), UINT16_C(35386), UINT16_C(15034), UINT16_C(60371), UINT16_C(26077),
        UINT16_C(26751), UINT16_C(55672), UINT16_C(64478), UINT16_C(26536), UINT16_C(31322), UINT16_C(20575), UINT16_C(55144), UINT16_C(57881),
        UINT16_C(38051), UINT16_C(45181), UINT16_C(33807), UINT16_C(19048), UINT16_C( 8974), UINT16_C(57732), UINT16_C( 1036), UINT16_C( 3702),
        UINT16_C(48842), UINT16_C(43111), UINT16_C( 4025), UINT16_C( 5136), UINT16_C(28553), UINT16_C(61796), UINT16_C(28486), UINT16_C(59916) },
      UINT32_C(3234005007) },
    { { UINT16_C(26174), UINT16_C(44819), UINT16_C(49455), UINT16_C(15422), UINT16_C(46277), UINT16_C(34378), UINT16_C( 5306), UINT16_C(24596),
        UINT16_C(63662), UINT16_C(31509), UINT16_C( 7972), UINT16_C(27384), UINT16_C( 1422), UINT16_C(37460), UINT16_C(61326), UINT16_C(52672),
        UINT16_C(54357), UINT16_C(34172), UINT16_C(47765), UINT16_C(23233), UINT16_C( 2926), UINT16_C(10464), UINT16_C(62752), UINT16_C(52872),
        UINT16_C(40429), UINT16_C( 4425), UINT16_C(16828), UINT16_C(19324), UINT16_C(53318), UINT16_C(54749), UINT16_C(40383), UINT16_C( 5538) },
      { UINT16_C( 7793), UINT16_C( 1690), UINT16_C(49455), UINT16_C(15422), UINT16_C(46277), UINT16_C(34378), UINT16_C(63542), UINT16_C( 9044),
        UINT16_C(40342), UINT16_C(21045), UINT16_C(45535), UINT16_C( 9629), UINT16_C(31361), UINT16_C(16890), UINT16_C(61326), UINT16_C(52672),
        UINT16_C(54357), UINT16_C(34172), UINT16_C(61515), UINT16_C(45531), UINT16_C(19249), UINT16_C(26424), UINT16_C(62752), UINT16_C(52872),
        UINT16_C(49194), UINT16_C( 2348), UINT16_C(51825), UINT16_C(61998), UINT16_C(10564), UINT16_C(23603), UINT16_C(40383), UINT16_C( 5538) },
      UINT32_C(1060913091) },
    { { UINT16_C(61542), UINT16_C(39030), UINT16_C(44603), UINT16_C(32767), UINT16_C(35386), UINT16_C(25689), UINT16_C(34378), UINT16_C(47981),
        UINT16_C(40016), UINT16_C(38062), UINT16_C(57797), UINT16_C(35569), UINT16_C(55147), UINT16_C(58379), UINT16_C( 8013), UINT16_C(45993),
        UINT16_C( 7951), UINT16_C(19275), UINT16_C(19405), UINT16_C( 1994), UINT16_C( 9429), UINT16_C( 8300), UINT16_C(55722), UINT16_C(64219),
        UINT16_C(35189), UINT16_C(14990), UINT16_C(32619), UINT16_C(54981), UINT16_C(53334), UINT16_C(41914), UINT16_C(25583), UINT16_C(65367) },
      { UINT16_C(61542), UINT16_C(39030), UINT16_C(44603), UINT16_C(32767), UINT16_C(49976), UINT16_C(58083), UINT16_C(48796), UINT16_C( 4828),
        UINT16_C(27464), UINT16_C(45900), UINT16_C( 4586), UINT16_C(16777), UINT16_C(55147), UINT16_C(58379), UINT16_C( 8013), UINT16_C(45993),
        UINT16_C( 6878), UINT16_C(52089), UINT16_C(19405), UINT16_C( 1994), UINT16_C( 9429), UINT16_C( 8300), UINT16_C(55722), UINT16_C(64219),
        UINT16_C(35189), UINT16_C(14990), UINT16_C(32619), UINT16_C(54981), UINT16_C(41463), UINT16_C(40530), UINT16_C(25583), UINT16_C(65367) },
      UINT32_C( 805507056) },
    { { UINT16_C( 5137), UINT16_C(42193), UINT16_C( 7046), UINT16_C(46803), UINT16_C( 5441), UINT16_C(53806), UINT16_C(22947), UINT16_C(16973),
        UINT16_C( 2573), UINT16_C( 1219), UINT16_C( 5547), UINT16_C(34723), UINT16_C(27447), UINT16_C(29506), UINT16_C(51372), UINT16_C(48606),
        UINT16_C(45020), UINT16_C(25185), UINT16_C(13514), UINT16_C( 2840), UINT16_C(17993), UINT16_C(60637), UINT16_C(11167), UINT16_C(44079),
        UINT16_C(62005), UINT16_C(57521), UINT16_C(21512), UINT16_C(16231), UINT16_C(43455), UINT16_C(27571), UINT16_C(37233), UINT16_C(20008) },
      { UINT16_C( 5137), UINT16_C(42193), UINT16_C(51645), UINT16_C( 1814), UINT16_C(62479), UINT16_C(45043), UINT16_C( 8735), UINT16_C(21595),
        UINT16_C( 2573), UINT16_C( 1219), UINT16_C(39776), UINT16_C( 8028), UINT16_C( 3909), UINT16_C(46730), UINT16_C(45728), UINT16_C(57604),
        UINT16_C(46395), UINT16_C(63980), UINT16_C(13514), UINT16_C( 2840), UINT16_C(17993), UINT16_C(60637), UINT16_C(11167), UINT16_C(44079),
        UINT16_C(62005), UINT16_C(57521), UINT16_C(42041), UINT16_C(32292), UINT16_C(43455), UINT16_C(27571), UINT16_C(37233), UINT16_C(20008) },
      UINT32_C( 201587964) },
    { { UINT16_C(38436), UINT16_C( 6905), UINT16_C(13961), UINT16_C(40752), UINT16_C(39374), UINT16_C(29386), UINT16_C( 4663), UINT16_C(28791),
        UINT16_C(40119), UINT16_C(27630), UINT16_C( 8779), UINT16_C(44223), UINT16_C(62811), UINT16_C(18761), UINT16_C(57110), UINT16_C(15029),
        UINT16_C(44917), UINT16_C(65365), UINT16_C(34277), UINT16_C(45982), UINT16_C(26910), UINT16_C(21797), UINT16_C(40315), UINT16_C(12997),
        UINT16_C(45881), UINT16_C(33949), UINT16_C(24022), UINT16_C(12592), UINT16_C(31314), UINT16_C(26747), UINT16_C(12377), UINT16_C(53155) },
      { UINT16_C(63711), UINT16_C(50382), UINT16_C(27773), UINT16_C(39799), UINT16_C(40405), UINT16_C(20977), UINT16_C(46650), UINT16_C(29571),
        UINT16_C( 8554), UINT16_C(16631), UINT16_C( 8779), UINT16_C(44223), UINT16_C(62811), UINT16_C(18761), UINT16_C(56093), UINT16_C(64714),
        UINT16_C(44917), UINT16_C(65365), UINT16_C(14340), UINT16_C(56044), UINT16_C(56789), UINT16_C( 3883), UINT16_C(40315), UINT16_C(12997),
        UINT16_C(31183), UINT16_C(19773), UINT16_C(44961), UINT16_C(16925), UINT16_C(22171), UINT16_C(47165), UINT16_C(12377), UINT16_C(53155) },
      UINT32_C(1060946943) },
    { { UINT16_C(16814), UINT16_C(33918), UINT16_C(43294), UINT16_C(45715), UINT16_C( 5719), UINT16_C(10159), UINT16_C(60815), UINT16_C(12404),
        UINT16_C(37532), UINT16_C(14195), UINT16_C(45288), UINT16_C( 6640), UINT16_C(42424), UINT16_C(22302), UINT16_C(29723), UINT16_C(51707),
        UINT16_C(31157), UINT16_C(54349), UINT16_C(57634), UINT16_C(31366), UINT16_C(13815), UINT16_C(34465), UINT16_C( 5410), UINT16_C(48823),
        UINT16_C(10919), UINT16_C(36854), UINT16_C(59098), UINT16_C(37545), UINT16_C(51083), UINT16_C(42730), UINT16_C(58683), UINT16_C(61807) },
      { UINT16_C(48479), UINT16_C(33221), UINT16_C(19358), UINT16_C(38395), UINT16_C(40064), UINT16_C(41755), UINT16_C(60815), UINT16_C(12404),
        UINT16_C(22524), UINT16_C(55273), UINT16_C(37437), UINT16_C(51305), UINT16_C(21337), UINT16_C(38254), UINT16_C(56889), UINT16_C(39046),
        UINT16_C(19355), UINT16_C(14617), UINT16_C( 5526), UINT16_C( 5838), UINT16_C(59825), UINT16_C(25529), UINT16_C( 5410), UINT16_C(48823),
        UINT16_C(42610), UINT16_C(45199), UINT16_C(63800), UINT16_C(37240), UINT16_C(51083), UINT16_C(42730), UINT16_C(58683), UINT16_C(61807) },
      UINT32_C( 255852351) },
    { { UINT16_C(26444), UINT16_C(64932), UINT16_C(23888), UINT16_C( 3169), UINT16_C( 7800), UINT16_C(60357), UINT16_C(21700), UINT16_C(64667),
        UINT16_C( 4941), UINT16_C(39565), UINT16_C(46330), UINT16_C(48927), UINT16_C(15712), UINT16_C(22559), UINT16_C(47220), UINT16_C(49381),
        UINT16_C(35103), UINT16_C(28861), UINT16_C( 7911), UINT16_C(24444), UINT16_C(16700), UINT16_C(   74), UINT16_C(58774), UINT16_C(58364),
        UINT16_C(35577), UINT16_C(62333), UINT16_C(40254), UINT16_C(40627), UINT16_C(53978), UINT16_C(20214), UINT16_C(56459), UINT16_C(43534) },
      { UINT16_C(26444), UINT16_C(64932), UINT16_C(38890), UINT16_C( 9900), UINT16_C(63192), UINT16_C(28199), UINT16_C( 9180), UINT16_C(54610),
        UINT16_C( 4941), UINT16_C(39565), UINT16_C(31596), UINT16_C(18058), UINT16_C(32846), UINT16_C(55700), UINT16_C(41564), UINT16_C(49795),
        UINT16_C(40558), UINT16_C(22542), UINT16_C( 7911), UINT16_C(24444), UINT16_C(16700), UINT16_C(   74), UINT16_C(52937), UINT16_C(30306),
        UINT16_C(10909), UINT16_C( 2658), UINT16_C(40254), UINT16_C(40627), UINT16_C(53978), UINT16_C(20214), UINT16_C(20615), UINT16_C(62859) },
      UINT32_C(3284401404) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i a = simde_mm512_loadu_si512(test_vec[i].a);
    simde__m512i b = simde_mm512_loadu_si512(test_vec[i].b);
    simde__mmask32 r = simde_mm512_cmpneq_epu16_mask(a, b);
    simde_assert_equal_mmask32(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m512i a = simde_test_x86_random_u16x32();
    simde__m512i b = simde_mm512_mask_blend_epi32(simde_test_x86_random_mmask32(), a, simde_test_x86_random_u16x32());
    simde__mmask32 r = simde_mm512_cmpneq_epu16_mask(a, b);

    simde_test_x86_write_u16x32(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_u16x32(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_mask_cmpneq_epu16_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask32 k1;
    const uint16_t a[32];
    const uint16_t b[32];
    const simde__mmask32 r;
  } test_vec[] = {
    { UINT32_C(  87149652),
      { UINT16_C(44401), UINT16_C(14994), UINT16_C(62587), UINT16_C( 6321), UINT16_C( 4894), UINT16_C(50210), UINT16_C(29695), UINT16_C(27576),
        UINT16_C(34136), UINT16_C(57140), UINT16_C(49110), UINT16_C(50389), UINT16_C( 8793), UINT16_C(44520), UINT16_C( 6638), UINT16_C(24754),
        UINT16_C(17606), UINT16_C(16794), UINT16_C(19256), UINT16_C(22105), UINT16_C(31838), UINT16_C(23835), UINT16_C(54255), UINT16_C(18377),
        UINT16_C(64857), UINT16_C(12070), UINT16_C(64445), UINT16_C( 5875), UINT16_C(56094), UINT16_C( 3267), UINT16_C(30196), UINT16_C(47724) },
      { UINT16_C(44401), UINT16_C(14994), UINT16_C(21842), UINT16_C(45383), UINT16_C( 4894), UINT16_C(50210), UINT16_C(55094), UINT16_C(36615),
        UINT16_C(34136), UINT16_C(57140), UINT16_C(45353), UINT16_C(18344), UINT16_C(27533), UINT16_C(33107), UINT16_C(49376), UINT16_C(39228),
        UINT16_C(14279), UINT16_C( 6538), UINT16_C(19256), UINT16_C(22105), UINT16_C(55604), UINT16_C(27165), UINT16_C( 9392), UINT16_C(34297),
        UINT16_C(64857), UINT16_C(12070), UINT16_C(49000), UINT16_C(62914), UINT16_C(56094), UINT16_C( 3267), UINT16_C(30196), UINT16_C(47724) },
      UINT32_C(  70372420) },
    { UINT32_C( 869564671),
      { UINT16_C(62041), UINT16_C( 2717), UINT16_C(38422), UINT16_C(26767), UINT16_C(42829), UINT16_C(46563), UINT16_C(42342), UINT16_C(37291),
        UINT16_C( 8891), UINT16_C(37019), UINT16_C(16341), UINT16_C(48941), UINT16_C(58220), UINT16_C(27446), UINT16_C( 2915), UINT16_C(48542),
        UINT16_C(15357), UINT16_C( 5063), UINT16_C(22225), UINT16_C( 7804), UINT16_C(24573), UINT16_C(25812), UINT16_C(32517), UINT16_C(49397),
        UINT16_C(37025), UINT16_C(30288), UINT16_C(32207), UINT16_C(15413), UINT16_C(27744), UINT16_C(50343), UINT16_C(18039), UINT16_C(29825) },
      { UINT16_C(18561), UINT16_C(21383), UINT16_C(38422), UINT16_C(26767), UINT16_C(42829), UINT16_C(46563), UINT16_C(62916), UINT16_C(25896),
        UINT16_C( 8891), UINT16_C(37019), UINT16_C( 4598), UINT16_C(22161), UINT16_C(14461), UINT16_C(62490), UINT16_C(39806), UINT16_C(  104),
        UINT16_C(15357), UINT16_C( 5063), UINT16_C(22225), UINT16_C( 7804), UINT16_C(24573), UINT16_C(25812), UINT16_C(58899), UINT16_C(38964),
        UINT16_C(37025), UINT16_C(30288), UINT16_C(32207), UINT16_C(15413), UINT16_C(27744), UINT16_C(50343), UINT16_C(63841), UINT16_C(17461) },
      UINT32_C(  12615875) },
    { UINT32_C(1462953037),
      { UINT16_C(61442), UINT16_C( 5413), UINT16_C(22998), UINT16_C(13486), UINT16_C(39785), UINT16_C(35209), UINT16_C(13338), UINT16_C(53543),
        UINT16_C(47353), UINT16_C(23046), UINT16_C(15538), UINT16_C(39839), UINT16_C(26052), UINT16_C( 4471), UINT16_C(43338), UINT16_C(19560),
        UINT16_C(36505), UINT16_C(28514), UINT16_C( 4327), UINT16_C(20643), UINT16_C(11435), UINT16_C(50650), UINT16_C(  352), UINT16_C(23190),
        UINT16_C(40377), UINT16_C(27572), UINT16_C(21465), UINT16_C(40198), UINT16_C(32185), UINT16_C(  943), UINT16_C( 5926), UINT16_C(48975) },
      { UINT16_C(45477), UINT16_C(36142), UINT16_C(22998), UINT16_C(13486), UINT16_C(47102), UINT16_C(24370), UINT16_C(51640), UINT16_C(29369),
        UINT16_C(28006), UINT16_C(16349), UINT16_C(58561), UINT16_C(31452), UINT16_C(35681), UINT16_C(34941), UINT16_C(52387), UINT16_C(18503),
        UINT16_C(36505), UINT16_C(28514), UINT16_C(45896), UINT16_C(18092), UINT16_C(57194), UINT16_C( 9125), UINT16_C(  352), UINT16_C(23190),
        UINT16_C(29388), UINT16_C(36173), UINT16_C(10582), UINT16_C(47111), UINT16_C(33973), UINT16_C(22592), UINT16_C( 5926), UINT16_C(48975) },
      UINT32_C( 389080129) },
    { UINT32_C(2475473449),
      { UINT16_C(12697), UINT16_C(16822), UINT16_C(19344), UINT16_C(23631), UINT16_C(40126), UINT16_C( 5353), UINT16_C(61638), UINT16_C(31692),
        UINT16_C( 3188), UINT16_C(50387), UINT16_C(29588), UINT16_C(37267), UINT16_C(41449), UINT16_C( 4823), UINT16_C(25435), UINT16_C(62886),
        UINT16_C(23700), UINT16_C( 9270), UINT16_C(34472), UINT16_C(26240), UINT16_C(26914), UINT16_C(59514), UINT16_C(18265), UINT16_C(52579),
        UINT16_C(13907), UINT16_C(59282), UINT16_C( 9642), UINT16_C(37753), UINT16_C(20678), UINT16_C( 8614), UINT16_C(19635), UINT16_C(18198) },
      { UINT16_C(12697), UINT16_C(16822), UINT16_C(60627), UINT16_C(62902), UINT16_C(12630), UINT16_C(45022), UINT16_C(16760), UINT16_C(52093),
        UINT16_C( 3188), UINT16_C(50387), UINT16_C(11316), UINT16_C(64181), UINT16_C(41449), UINT16_C( 4823), UINT16_C(12967), UINT16_C(20598),
        UINT16_C(23700), UINT16_C( 9270), UINT16_C(22479), UINT16_C( 9543), UINT16_C(26914), UINT16_C(59514), UINT16_C(20839), UINT16_C(57291),
        UINT16_C(13907), UINT16_C(59282), UINT16_C(46762), UINT16_C( 9870), UINT16_C(20678), UINT16_C( 8614), UINT16_C(52444), UINT16_C(23305) },
      UINT32_C(2156693544) },
    { UINT32_C(2309157889),
      { UINT16_C(30490), UINT16_C(33161), UINT16_C(21704), UINT16_C(10592), UINT16_C(25043), UINT16_C(32189), UINT16_C(19479), UINT16_C(10660),
        UINT16_C(63990), UINT16_C(53987), UINT16_C(60613), UINT16_C(29741), UINT16_C(55958), UINT16_C(38897), UINT16_C(38094), UINT16_C(59424),
        UINT16_C(43275), UINT16_C(54121), UINT16_C(51710), UINT16_C(53756), UINT16_C(47658), UINT16_C(16974), UINT16_C(61958), UINT16_C(64619),
        UINT16_C(20204), UINT16_C(45518), UINT16_C(64315), UINT16_C(53541), UINT16_C( 6101), UINT16_C(41833), UINT16_C(35243), UINT16_C(46732) },
      { UINT16_C(30490), UINT16_C(33161), UINT16_C(34495), UINT16_C(59650), UINT16_C(20544), UINT16_C(17963), UINT16_C(38723), UINT16_C(12098),
        UINT16_C( 4325), UINT16_C( 8416), UINT16_C(60613), UINT16_C(29741), UINT16_C(23325), UINT16_C(51331), UINT16_C(38094), UINT16_C(59424),
        UINT16_C( 1797), UINT16_C(50248), UINT16_C(19085), UINT16_C(52653), UINT16_C(55707), UINT16_C(56851), UINT16_C(61958), UINT16_C(64619),
        UINT16_C(20204), UINT16_C(45518), UINT16_C(64315), UINT16_C(53541), UINT16_C( 6101), UINT16_C(41833), UINT16_C(35243), UINT16_C(46732) },
      UINT32_C(   2240512) },
    { UINT32_C(3988347474),
      { UINT16_C(52275), UINT16_C(41931), UINT16_C(55330), UINT16_C(34808), UINT16_C(28357), UINT16_C(47608), UINT16_C(18646), UINT16_C(39369),
        UINT16_C(41500), UINT16_C(   65), UINT16_C(  248), UINT16_C(22248), UINT16_C(38151), UINT16_C(22850), UINT16_C(64495), UINT16_C( 8774),
        UINT16_C( 4551), UINT16_C(59845), UINT16_C(48617), UINT16_C(44913), UINT16_C(26924), UINT16_C(  616), UINT16_C(12721), UINT16_C(52892),
        UINT16_C(56787), UINT16_C(52430), UINT16_C(46813), UINT16_C(58402), UINT16_C(25675), UINT16_C(14910), UINT16_C(33887), UINT16_C(10076) },
      { UINT16_C( 8598), UINT16_C(32528), UINT16_C(55330), UINT16_C(34808), UINT16_C(28357), UINT16_C(47608), UINT16_C(18646), UINT16_C(39369),
        UINT16_C(14470), UINT16_C(25447), UINT16_C(35566), UINT16_C(14920), UINT16_C(34542), UINT16_C(20084), UINT16_C(64495), UINT16_C( 8774),
        UINT16_C( 4551), UINT16_C(59845), UINT16_C(19975), UINT16_C(61916), UINT16_C(60133), UINT16_C(44429), UINT16_C(12721), UINT16_C(52892),
        UINT16_C(45103), UINT16_C( 7805), UINT16_C(46813), UINT16_C(58402), UINT16_C(25675), UINT16_C(14910), UINT16_C(33887), UINT16_C(10076) },
      UINT32_C(  20453890) },
    { UINT32_C(1248411237),
      { UINT16_C(63272), UINT16_C(48119), UINT16_C(16366), UINT16_C( 7893), UINT16_C(21487), UINT16_C(10556), UINT16_C(37912), UINT16_C(25682),
        UINT16_C(51296), UINT16_C(65210), UINT16_C(45236), UINT16_C( 9614), UINT16_C(61383), UINT16_C(11421), UINT16_C( 1581), UINT16_C(21878),
        UINT16_C(28157), UINT16_C(60433), UINT16_C(59052), UINT16_C(39946), UINT16_C(17977), UINT16_C(21189), UINT16_C( 6106), UINT16_C(15030),
        UINT16_C(28896), UINT16_C(37944), UINT16_C(50720), UINT16_C(59321), UINT16_C(22198), UINT16_C(58131), UINT16_C(35164), UINT16_C(23097) },
      { UINT16_C(63272), UINT16_C(48119), UINT16_C(16366), UINT16_C( 7893), UINT16_C(21487), UINT16_C(10556), UINT16_C(37912), UINT16_C(25682),
        UINT16_C(51296), UINT16_C(65210), UINT16_C(18857), UINT16_C(24554), UINT16_C(64927), UINT16_C(64323), UINT16_C(31879), UINT16_C(32085),
        UINT16_C(39878), UINT16_C(63008), UINT16_C(24555), UINT16_C(33120), UINT16_C( 7268), UINT16_C(33009), UINT16_C(40078), UINT16_C(28796),
        UINT16_C( 3199), UINT16_C(10355), UINT16_C(23893), UINT16_C(62600), UINT16_C(52058), UINT16_C(57839), UINT16_C(35164), UINT16_C(23097) },
      UINT32_C( 174668800) },
    { UINT32_C(1129145567),
      { UINT16_C(16256), UINT16_C( 4035), UINT16_C(16347), UINT16_C(23167), UINT16_C(62027), UINT16_C(41090), UINT16_C( 2639), UINT16_C(43668),
        UINT16_C(33749), UINT16_C( 7307), UINT16_C(60104), UINT16_C(43305), UINT16_C(11626), UINT16_C(18805), UINT16_C(49809), UINT16_C( 4492),
        UINT16_C(20225), UINT16_C(56352), UINT16_C(41102), UINT16_C(55606), UINT16_C(47506), UINT16_C(57977), UINT16_C( 3523), UINT16_C(39308),
        UINT16_C( 6032), UINT16_C(22965), UINT16_C(57090), UINT16_C(27650), UINT16_C(30476), UINT16_C(40373), UINT16_C(16697), UINT16_C(15278) },
      { UINT16_C(53136), UINT16_C( 7703), UINT16_C(16347), UINT16_C(23167), UINT16_C(62027), UINT16_C(41090), UINT16_C( 2639), UINT16_C(43668),
        UINT16_C( 6535), UINT16_C(35174), UINT16_C(60104), UINT16_C(43305), UINT16_C(11626), UINT16_C(18805), UINT16_C(49809), UINT16_C( 4492),
        UINT16_C(20225), UINT16_C(56352), UINT16_C(41102), UINT16_C(55606), UINT16_C(47506), UINT16_C(57977), UINT16_C( 3523), UINT16_C(39308),
        UINT16_C(61703), UINT16_C(65522), UINT16_C(57090), UINT16_C(27650), UINT16_C(30476), UINT16_C(40373), UINT16_C(42740), UINT16_C( 4855) },
      UINT32_C(1124073475) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i a = simde_mm512_loadu_si512(test_vec[i].a);
    simde__m512i b = simde_mm512_loadu_si512(test_vec[i].b);
    simde__mmask32 r = simde_mm512_mask_cmpneq_epu16_mask(test_vec[i].k1, a, b);
    simde_assert_equal_mmask32(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask32 k1 = simde_test_x86_random_mmask32();
    simde__m512i a = simde_test_x86_random_u16x32();
    simde__m512i b = simde_mm512_mask_blend_epi32(simde_test_x86_random_mmask32(), a, simde_test_x86_random_u16x32());
    simde__mmask32 r = simde_mm512_mask_cmpneq_epu16_mask(k1, a, b);

    simde_test_x86_write_mmask32(2, k1, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_u16x32(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_u16x32(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask32(2, r, SIMDE_TEST_VEC_POS_LAST);
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
test_simde_mm512_cmpneq_epu32_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const uint32_t a[16];
    const uint32_t b[16];
    const simde__mmask16 r;
  } test_vec[] = {
    { { UINT32_C( 545992480), UINT32_C(2208110241), UINT32_C( 216803077), UINT32_C(1913445912), UINT32_C(1454051269), UINT32_C(2832399796), UINT32_C(3032140195), UINT32_C(2038389337),
        UINT32_C( 731450249), UINT32_C( 648951329), UINT32_C(1983093598), UINT32_C(1072185209), UINT32_C(  43357006), UINT32_C( 866805904), UINT32_C(2347263281), UINT32_C(1225025471) },
      { UINT32_C( 545992480), UINT32_C(2208110241), UINT32_C( 933883325), UINT32_C(2071367980), UINT32_C(1454051269), UINT32_C(2783520883), UINT32_C(3032140195), UINT32_C(2878682168),
        UINT32_C(2805926354), UINT32_C(3923376428), UINT32_C(1983093598), UINT32_C( 965645844), UINT32_C(  43357006), UINT32_C( 866805904), UINT32_C(3775785640), UINT32_C(4052525855) },
      UINT16_C(52140) },
    { { UINT32_C(1925503128), UINT32_C(3807685570), UINT32_C(1299777727), UINT32_C( 811146049), UINT32_C(3943140656), UINT32_C(1557508174), UINT32_C( 503313553), UINT32_C(2129177574),
        UINT32_C(1190177924), UINT32_C( 388556120), UINT32_C( 795124205), UINT32_C(3982474940), UINT32_C(2597873227), UINT32_C(2817961238), UINT32_C(2294609314), UINT32_C( 604417184) },
      { UINT32_C(2976577369), UINT32_C(3385365468), UINT32_C(1299777727), UINT32_C( 811146049), UINT32_C(3943140656), UINT32_C(  92063331), UINT32_C( 503313553), UINT32_C(2129177574),
        UINT32_C(1744300683), UINT32_C( 388556120), UINT32_C( 795124205), UINT32_C(1041006976), UINT32_C(2584992823), UINT32_C(1570803618), UINT32_C(3166186959), UINT32_C(1275214017) },
      UINT16_C(63779) },
    { { UINT32_C(3837305011), UINT32_C(4111311954), UINT32_C(2255916410), UINT32_C(3747786188), UINT32_C(3899524168), UINT32_C( 420822369), UINT32_C(4233287674), UINT32_C(3623253283),
        UINT32_C(1757130261), UINT32_C(3428698194), UINT32_C( 559076437), UINT32_C(3372266625), UINT32_C( 431058616), UINT32_C(2788411308), UINT32_C(3248653726), UINT32_C( 261658874) },
      { UINT32_C(2574734151), UINT32_C(4111311954), UINT32_C(2255916410), UINT32_C(3747786188), UINT32_C(2906629377), UINT32_C( 173240940), UINT32_C(4233287674), UINT32_C(3623253283),
        UINT32_C(3547297976), UINT32_C(3428698194), UINT32_C(4196456333), UINT32_C(3372266625), UINT32_C( 639197114), UINT32_C(3358682321), UINT32_C(3248653726), UINT32_C( 261658874) },
      UINT16_C(13617) },
    { { UINT32_C( 822771437), UINT32_C(2500368500), UINT32_C(2997449362), UINT32_C(4145112030), UINT32_C(3143885450), UINT32_C(1673053866), UINT32_C(2099059127), UINT32_C( 548621875),
        UINT32_C(1095876045), UINT32_C(3906361941), UINT32_C(2862252236), UINT32_C(1839312099), UINT32_C( 958924174), UINT32_C(2191319243), UINT32_C( 771734010), UINT32_C(3578638856) },
      { UINT32_C( 822771437), UINT32_C(2500368500), UINT32_C(2997449362), UINT32_C(2193494516), UINT32_C(3143885450), UINT32_C(3244513479), UINT32_C( 435053073), UINT32_C(2246982421),
        UINT32_C(1095876045), UINT32_C(3906361941), UINT32_C(2862252236), UINT32_C( 766930199), UINT32_C( 453931604), UINT32_C(3688657354), UINT32_C( 771734010), UINT32_C(3731809029) },
      UINT16_C(47336) },
    { { UINT32_C(1202772656), UINT32_C(3914264633), UINT32_C(3679872292), UINT32_C(2706221715), UINT32_C(2702383045), UINT32_C(3882608626), UINT32_C(1053520080), UINT32_C(4294357839),
        UINT32_C(3343361934), UINT32_C(3165689239), UINT32_C(2375485434), UINT32_C(1999627441), UINT32_C(3977790203), UINT32_C(4191519785), UINT32_C(1127719156), UINT32_C(3779276115) },
      { UINT32_C(1823050452), UINT32_C( 422074655), UINT32_C(3679872292), UINT32_C(2659833507), UINT32_C(1099669784), UINT32_C(3882608626), UINT32_C(1415409920), UINT32_C(4294357839),
        UINT32_C(3343361934), UINT32_C(3165689239), UINT32_C(1772751558), UINT32_C(1999627441), UINT32_C(4198077141), UINT32_C(4191519785), UINT32_C(2185720548), UINT32_C(1039498514) },
      UINT16_C(54363) },
    { { UINT32_C(3923481478), UINT32_C(3606290732), UINT32_C( 285922058), UINT32_C(  77914059), UINT32_C(4000815065), UINT32_C(3529530250), UINT32_C(3545199326), UINT32_C( 917023407),
        UINT32_C(1780450110), UINT32_C( 792728357), UINT32_C(2990623462), UINT32_C(  62317865), UINT32_C( 116469372), UINT32_C(1742229897), UINT32_C(1933256643), UINT32_C( 279569362) },
      { UINT32_C(3923481478), UINT32_C(3606290732), UINT32_C( 779418629), UINT32_C(1563503329), UINT32_C(4000815065), UINT32_C(3529530250), UINT32_C(3545199326), UINT32_C(3460649831),
        UINT32_C(4149853979), UINT32_C(2142835834), UINT32_C(4054658320), UINT32_C(2957958999), UINT32_C( 116469372), UINT32_C(1370282990), UINT32_C(3347535456), UINT32_C(3298151593) },
      UINT16_C(61324) },
    { { UINT32_C(1946355387), UINT32_C( 849417349), UINT32_C(1410464005), UINT32_C( 990253993), UINT32_C( 873919624), UINT32_C(3431626309), UINT32_C(3550032702), UINT32_C(3015845367),
        UINT32_C(2955396651), UINT32_C(3756181978), UINT32_C(1798567106), UINT32_C(2410035463), UINT32_C(1942207533), UINT32_C(1899973939), UINT32_C(2001000576), UINT32_C( 673843197) },
      { UINT32_C(1946355387), UINT32_C( 849417349), UINT32_C(3058219695), UINT32_C( 558231283), UINT32_C(3717466282), UINT32_C(3431626309), UINT32_C(3550032702), UINT32_C(1741846426),
        UINT32_C(3826166473), UINT32_C( 348230757), UINT32_C(1120536910), UINT32_C(2707623927), UINT32_C(1942207533), UINT32_C(1984024010), UINT32_C(4196437600), UINT32_C( 673843197) },
      UINT16_C(28572) },
    { { UINT32_C(1929642674), UINT32_C(3783021078), UINT32_C(4159730580), UINT32_C(2481850388), UINT32_C(3059857780), UINT32_C(1329905967), UINT32_C( 490817980), UINT32_C(3381517847),
        UINT32_C(4131164640), UINT32_C(2027403491), UINT32_C(1064290347), UINT32_C(1154703056), UINT32_C(1190802455), UINT32_C(2979413749), UINT32_C(2664421255), UINT32_C(2506579125) },
      { UINT32_C(1929642674), UINT32_C(3783021078), UINT32_C(4159730580), UINT32_C( 759208214), UINT32_C(3262331597), UINT32_C(   7604601), UINT32_C(2527020001), UINT32_C(3381517847),
        UINT32_C(  89962666), UINT32_C(2027403491), UINT32_C(1064290347), UINT32_C(3097527019), UINT32_C( 913970109), UINT32_C(4265012765), UINT32_C(2664421255), UINT32_C(2254225628) },
      UINT16_C(47480) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512i a = simde_x_mm512_loadu_epu32(test_vec[i].a);
    simde__m512i b = simde_x_mm512_loadu_epu32(test_vec[i].b);
    simde__mmask16 r = simde_mm512_cmpneq_epu32_mask(a, b);
    simde_assert_equal_mmask16(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m512i a = simde_test_x86_random_u32x16();
    simde__m512i b = simde_x_mm512_mask_blend_epu32(simde_test_x86_random_mmask16(), a, simde_test_x86_random_u32x16());
    simde__mmask16 r = simde_mm512_cmpneq_epu32_mask(a, b);

    simde_test_x86_write_u32x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_u32x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_mask_cmpneq_epu32_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask16 k1;
    const uint32_t a[16];
    const uint32_t b[16];
    const simde__mmask16 r;
  } test_vec[] = {
    { UINT16_C(38027),
      { UINT32_C(3151697758), UINT32_C(1412308329), UINT32_C(1561120416), UINT32_C(4271081441), UINT32_C(2818361717), UINT32_C(2071433631), UINT32_C(3389117521), UINT32_C(3948842125),
        UINT32_C( 228997540), UINT32_C(4133672022), UINT32_C(2203283106), UINT32_C(1803740917), UINT32_C(1326612144), UINT32_C(1640663311), UINT32_C(3928738653), UINT32_C(4225075543) },
      { UINT32_C(3151697758), UINT32_C(1412308329), UINT32_C(3480576729), UINT32_C(4181391177), UINT32_C(2236107893), UINT32_C( 870716117), UINT32_C( 874320349), UINT32_C(1546711962),
        UINT32_C(3195287918), UINT32_C(2108654500), UINT32_C( 793519334), UINT32_C(1803740917), UINT32_C(2820042962), UINT32_C(1608252546), UINT32_C(2811492365), UINT32_C(4225075543) },
      UINT16_C( 5256) },
    { UINT16_C(40984),
      { UINT32_C(3776890875), UINT32_C( 118516460), UINT32_C(3281533169), UINT32_C( 711700136), UINT32_C(3079227050), UINT32_C( 710810687), UINT32_C(3699663328), UINT32_C(3565001945),
        UINT32_C(1354079076), UINT32_C(4132947205), UINT32_C(2780492029), UINT32_C(1238312350), UINT32_C(2868926572), UINT32_C(1423269748), UINT32_C(2570148544), UINT32_C(1517137654) },
      { UINT32_C(3776890875), UINT32_C( 118516460), UINT32_C(2424963058), UINT32_C( 711700136), UINT32_C(3079227050), UINT32_C(4185461049), UINT32_C(3699663328), UINT32_C(3565001945),
        UINT32_C(1354079076), UINT32_C(4132947205), UINT32_C(1491826740), UINT32_C(1238312350), UINT32_C(3617989790), UINT32_C(2698059829), UINT32_C(2570148544), UINT32_C(2277817956) },
      UINT16_C(40960) },
    { UINT16_C(36242),
      { UINT32_C( 501711337), UINT32_C(3396784889), UINT32_C( 894197655), UINT32_C(3104699011), UINT32_C(3713654290), UINT32_C(2785041218), UINT32_C(1043252249), UINT32_C(1657520249),
        UINT32_C( 981512769), UINT32_C( 470152837), UINT32_C(3629207893), UINT32_C(1452367427), UINT32_C(2117331772), UINT32_C(1613050694), UINT32_C(1889424375), UINT32_C(1423141139) },
      { UINT32_C( 501711337), UINT32_C(2663158601), UINT32_C( 678825700), UINT32_C(2843609196), UINT32_C( 958902771), UINT32_C(2785041218), UINT32_C(1043252249), UINT32_C(3154517920),
        UINT32_C( 981512769), UINT32_C( 223942952), UINT32_C(2469777191), UINT32_C(3392975831), UINT32_C(2117331772), UINT32_C(1613050694), UINT32_C(1889424375), UINT32_C(   3213710) },
      UINT16_C(35986) },
    { UINT16_C(50875),
      { UINT32_C(3469939879), UINT32_C(3143698660), UINT32_C( 528916155), UINT32_C(2993129986), UINT32_C(4228025127), UINT32_C(2305951226), UINT32_C(2894701326), UINT32_C(3631367473),
        UINT32_C(1034307161), UINT32_C( 184092750), UINT32_C(2821291942), UINT32_C( 811241737), UINT32_C( 372071708), UINT32_C(1889509218), UINT32_C(1948002626), UINT32_C(3343683182) },
      { UINT32_C(3469939879), UINT32_C(2704146171), UINT32_C(2252953213), UINT32_C(  62301159), UINT32_C(1645929216), UINT32_C(2305951226), UINT32_C(2894701326), UINT32_C(3631367473),
        UINT32_C(1034307161), UINT32_C( 184092750), UINT32_C(2821291942), UINT32_C(  31708161), UINT32_C( 372071708), UINT32_C(2583639734), UINT32_C(2733193253), UINT32_C(3343683182) },
      UINT16_C(16410) },
    { UINT16_C(14762),
      { UINT32_C(  30522889), UINT32_C( 501346076), UINT32_C(2082391236), UINT32_C(2008449729), UINT32_C(3725637305), UINT32_C(2894133998), UINT32_C( 451113979), UINT32_C(3847458267),
        UINT32_C(1743136075), UINT32_C(3632580372), UINT32_C(1280615307), UINT32_C(3737389861), UINT32_C(2948388033), UINT32_C(3395042510), UINT32_C(2346991536), UINT32_C( 393230284) },
      { UINT32_C(  30522889), UINT32_C(2856911646), UINT32_C(3438714534), UINT32_C(1789573801), UINT32_C(1561945999), UINT32_C(1395094947), UINT32_C(2162101172), UINT32_C(3847458267),
        UINT32_C(1743136075), UINT32_C(3245300250), UINT32_C(1280615307), UINT32_C(3737389861), UINT32_C(1108092062), UINT32_C(1318401178), UINT32_C(2346991536), UINT32_C( 393230284) },
      UINT16_C(12330) },
    { UINT16_C(38959),
      { UINT32_C(2220465804), UINT32_C( 606463492), UINT32_C(3167957022), UINT32_C(4026457941), UINT32_C(1396544531), UINT32_C(3436514312), UINT32_C(4046976883), UINT32_C(3062523434),
        UINT32_C( 154919685), UINT32_C(3895288010), UINT32_C(3869507729), UINT32_C(4090864607), UINT32_C(1061556791), UINT32_C(2450266911), UINT32_C(1032078099), UINT32_C(2935164585) },
      { UINT32_C(2220465804), UINT32_C( 606463492), UINT32_C(3167957022), UINT32_C( 582474731), UINT32_C( 207748589), UINT32_C( 731868440), UINT32_C(1516774320), UINT32_C(3062523434),
        UINT32_C( 154919685), UINT32_C(3895288010), UINT32_C(3869507729), UINT32_C( 148243482), UINT32_C(1061556791), UINT32_C(2450266911), UINT32_C(1032078099), UINT32_C(2935164585) },
      UINT16_C( 2088) },
    { UINT16_C( 7597),
      { UINT32_C(1403447177), UINT32_C(1091040038), UINT32_C(4165590775), UINT32_C(3138477334), UINT32_C(3876673041), UINT32_C( 233816324), UINT32_C(4070644090), UINT32_C(2853130017),
        UINT32_C(1560130870), UINT32_C(2677867944), UINT32_C(4187481827), UINT32_C(1437903172), UINT32_C(  54314751), UINT32_C(  17902471), UINT32_C(1710535236), UINT32_C( 923796225) },
      { UINT32_C(1637092793), UINT32_C(1091040038), UINT32_C(4165590775), UINT32_C(3138477334), UINT32_C(3876673041), UINT32_C(1576162585), UINT32_C( 163833352), UINT32_C(2722223081),
        UINT32_C(4077180384), UINT32_C( 518522118), UINT32_C(4187481827), UINT32_C(3810536314), UINT32_C( 852714521), UINT32_C(3264202170), UINT32_C(1710535236), UINT32_C( 923796225) },
      UINT16_C( 6561) },
    { UINT16_C(59641),
      { UINT32_C(3724992832), UINT32_C( 851280312), UINT32_C(3306544556), UINT32_C(4227328321), UINT32_C(1522370478), UINT32_C(4293888473), UINT32_C(1996826261), UINT32_C(2724200034),
        UINT32_C(2558551519), UINT32_C(2479504870), UINT32_C(1549328410), UINT32_C(2002211017), UINT32_C(2966492631), UINT32_C( 867156126), UINT32_C(1235924199), UINT32_C(2464876978) },
      { UINT32_C(1428843631), UINT32_C( 851280312), UINT32_C(3306544556), UINT32_C(4227328321), UINT32_C( 706274956), UINT32_C(2388576423), UINT32_C(1996826261), UINT32_C(2724200034),
        UINT32_C(2558551519), UINT32_C(3030171615), UINT32_C(1549328410), UINT32_C(3237570099), UINT32_C(4108980557), UINT32_C(1451378905), UINT32_C(1235924199), UINT32_C(1256474139) },
      UINT16_C(43057) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512i a = simde_x_mm512_loadu_epu32(test_vec[i].a);
    simde__m512i b = simde_x_mm512_loadu_epu32(test_vec[i].b);
    simde__mmask16 r = simde_mm512_mask_cmpneq_epu32_mask(test_vec[i].k1, a, b);
    simde_assert_equal_mmask16(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask16 k1 = simde_test_x86_random_mmask16();
    simde__m512i a = simde_test_x86_random_u32x16();
    simde__m512i b = simde_x_mm512_mask_blend_epu32(simde_test_x86_random_mmask16(), a, simde_test_x86_random_u32x16());
    simde__mmask16 r = simde_mm512_mask_cmpneq_epu32_mask(k1, a, b);

    simde_test_x86_write_mmask16(2, k1, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_u32x16(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_u32x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask16(2, r, SIMDE_TEST_VEC_POS_LAST);
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

static int
test_simde_mm512_cmpneq_epu64_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const uint64_t a[8];
    const uint64_t b[8];
    const simde__mmask8 r;
  } test_vec[] = {
    { { UINT64_C( 8405579808977318475), UINT64_C( 2167660859967678745), UINT64_C(15800842934731815358), UINT64_C( 1763654916679719048),
        UINT64_C( 8752451619017114292), UINT64_C( 3264492277555878430), UINT64_C( 2508849805152860935), UINT64_C( 6410604297826984209) },
      { UINT64_C( 6388022069742421452), UINT64_C( 2167660859967678745), UINT64_C(   93727800697796496), UINT64_C(13104024558910889693),
        UINT64_C( 3364055899393045533), UINT64_C( 3264492277555878430), UINT64_C( 5563090613311992899), UINT64_C(  760450751105275375) },
      UINT8_C(221) },
    { { UINT64_C( 5250087835437982318), UINT64_C(12512387594955518165), UINT64_C( 2428683801633609651), UINT64_C( 9781844890111347770),
        UINT64_C( 9643432416424862074), UINT64_C(14425464005984724810), UINT64_C(17622656511380311907), UINT64_C( 3561669692115885772) },
      { UINT64_C(10335076445033720376), UINT64_C( 4869874304375018680), UINT64_C( 2428683801633609651), UINT64_C(16701460334263933152),
        UINT64_C( 9643432416424862074), UINT64_C( 3077136768598430353), UINT64_C( 9863368793134687825), UINT64_C( 3561669692115885772) },
      UINT8_C(107) },
    { { UINT64_C( 2523791302714233400), UINT64_C(10622270974662899944), UINT64_C(17574669712128416859), UINT64_C(  519123212863891171),
        UINT64_C(16992505821369513437), UINT64_C(14536049967648443386), UINT64_C(11275258343697806728), UINT64_C(  864579180005089833) },
      { UINT64_C( 2523791302714233400), UINT64_C(10622270974662899944), UINT64_C(17574669712128416859), UINT64_C( 8453555727826520856),
        UINT64_C(12502561663960419212), UINT64_C(14536049967648443386), UINT64_C( 3869990785886972077), UINT64_C( 7070033311874925955) },
      UINT8_C(216) },
    { { UINT64_C( 1166746140682480869), UINT64_C( 4214760477463160399), UINT64_C(10602755341346609577), UINT64_C(14965122821262003464),
        UINT64_C( 9959406260966792631), UINT64_C( 4800512406148792850), UINT64_C(10039377351997191665), UINT64_C( 4579895326564990165) },
      { UINT64_C( 1166746140682480869), UINT64_C( 1457557848235658078), UINT64_C(18179948843201994302), UINT64_C(14965122821262003464),
        UINT64_C( 9959406260966792631), UINT64_C( 4800512406148792850), UINT64_C(11492430590373041242), UINT64_C( 1846393953873181181) },
      UINT8_C(198) },
    { { UINT64_C(12732659059144188908), UINT64_C(12977114770291646336), UINT64_C( 5641619542396410109), UINT64_C(10274378308931158809),
        UINT64_C(  393058389274986447), UINT64_C( 2351116654294936268), UINT64_C( 4166877625281548400), UINT64_C( 7056469443127846588) },
      { UINT64_C(12732659059144188908), UINT64_C( 4109371695625334980), UINT64_C(17065425621187720827), UINT64_C(10274378308931158809),
        UINT64_C(12668192458048754141), UINT64_C( 9180479006705097061), UINT64_C( 4166877625281548400), UINT64_C( 7056469443127846588) },
      UINT8_C( 54) },
    { { UINT64_C(16610348880292314792), UINT64_C( 4402102712643793254), UINT64_C(  161536440645540484), UINT64_C( 9924036790232252574),
        UINT64_C( 1221366833809447616), UINT64_C(14641248877090692571), UINT64_C(12110313581589636484), UINT64_C(14296364780954043387) },
      { UINT64_C(16610348880292314792), UINT64_C( 4402102712643793254), UINT64_C( 7569803779848598619), UINT64_C( 9924036790232252574),
        UINT64_C( 2738956590639135417), UINT64_C(10896116512705283909), UINT64_C(12110313581589636484), UINT64_C( 4555383903590996545) },
      UINT8_C(180) },
    { { UINT64_C( 4069384005176602489), UINT64_C( 2950153156085183597), UINT64_C( 9895517440991697672), UINT64_C( 7111270574186279170),
        UINT64_C(12602776282507634045), UINT64_C( 8022833325823712131), UINT64_C( 5127582666471855343), UINT64_C(  347044930008594566) },
      { UINT64_C( 4069384005176602489), UINT64_C( 2950153156085183597), UINT64_C( 9895517440991697672), UINT64_C( 7636106682746379885),
        UINT64_C(12602776282507634045), UINT64_C( 2873680671716597237), UINT64_C( 5127582666471855343), UINT64_C(  347044930008594566) },
      UINT8_C( 40) },
    { { UINT64_C( 1076821221001886130), UINT64_C( 3835814841879520565), UINT64_C(18272487382275655113), UINT64_C( 4185289400204745072),
        UINT64_C( 6474531552808632731), UINT64_C(10811216145473618061), UINT64_C(13592015737177137709), UINT64_C(14386396257204177635) },
      { UINT64_C(10646066443375074624), UINT64_C( 3835814841879520565), UINT64_C( 8420397119367677906), UINT64_C( 9601541663027660108),
        UINT64_C(17077271827365679716), UINT64_C(10811216145473618061), UINT64_C( 6018114248520483967), UINT64_C( 5833019052457157928) },
      UINT8_C(221) },  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512i a = simde_x_mm512_loadu_epu64(test_vec[i].a);
    simde__m512i b = simde_x_mm512_loadu_epu64(test_vec[i].b);
    simde__mmask8 r = simde_mm512_cmpneq_epu64_mask(a, b);
    simde_assert_equal_mmask8(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m512i a = simde_test_x86_random_u64x8();
    simde__m512i b = simde_x_mm512_mask_blend_epu64(simde_test_x86_random_mmask8(), a, simde_test_x86_random_u64x8());
    simde__mmask8 r = simde_mm512_cmpneq_epu64_mask(a, b);

    simde_test_x86_write_u64x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_u64x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_mask_cmpneq_epu64_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k1;
    const uint64_t a[8];
    const uint64_t b[8];
    const simde__mmask8 r;
  } test_vec[] = {
    { UINT8_C( 74),
      { UINT64_C(13740150470938993551), UINT64_C(17038872391679196224), UINT64_C( 9338775250767524078), UINT64_C(10703791894158182017),
        UINT64_C( 6445299889015375781), UINT64_C(15790156774510801162), UINT64_C(15363476338718496280), UINT64_C( 6892655570975078158) },
      { UINT64_C(13740150470938993551), UINT64_C(17038872391679196224), UINT64_C( 9616793199934729803), UINT64_C( 1587025384012549358),
        UINT64_C( 6445299889015375781), UINT64_C(15114351404656332864), UINT64_C(15363476338718496280), UINT64_C(13598217987722901362) },
      UINT8_C(  8) },
    { UINT8_C(206),
      { UINT64_C( 1451145468967995864), UINT64_C(16966870117319879029), UINT64_C(16041615519527300424), UINT64_C( 7667410881091852004),
        UINT64_C(11572035713327081831), UINT64_C( 6354381232001163978), UINT64_C( 3020121243526365625), UINT64_C(16101260887322745718) },
      { UINT64_C( 1451145468967995864), UINT64_C(16966870117319879029), UINT64_C(16041615519527300424), UINT64_C( 7667410881091852004),
        UINT64_C(11572035713327081831), UINT64_C( 6354381232001163978), UINT64_C( 3020121243526365625), UINT64_C(16101260887322745718) },
      UINT8_C(  0) },
    { UINT8_C(201),
      { UINT64_C( 7894954878427693821), UINT64_C(10127778868325579613), UINT64_C( 5041137587320838296), UINT64_C(12541892400580087420),
        UINT64_C( 6435702128268048450), UINT64_C( 4824368578701332527), UINT64_C( 5090031620282782577), UINT64_C( 7285018951120675770) },
      { UINT64_C( 7894954878427693821), UINT64_C( 8868847753099702313), UINT64_C(12798524217341152141), UINT64_C(12541892400580087420),
        UINT64_C( 6435702128268048450), UINT64_C( 4824368578701332527), UINT64_C( 5090031620282782577), UINT64_C(15075190478920853932) },
      UINT8_C(128) },
    { UINT8_C( 12),
      { UINT64_C( 9602504819097456564), UINT64_C(13972069130621044649), UINT64_C( 5103689817271988125), UINT64_C( 4007255350588453211),
        UINT64_C( 9310965557084808304), UINT64_C( 8435878548863718776), UINT64_C(12020514549219154098), UINT64_C(18365067465114250276) },
      { UINT64_C( 9602504819097456564), UINT64_C( 6938597520835046652), UINT64_C( 5103689817271988125), UINT64_C( 4007255350588453211),
        UINT64_C( 9310965557084808304), UINT64_C( 1801413353677851888), UINT64_C(12020514549219154098), UINT64_C(12116580579701936915) },
      UINT8_C(  0) },
    { UINT8_C(155),
      { UINT64_C(15404580361264394102), UINT64_C( 6600463712874507951), UINT64_C( 1818089280532332987), UINT64_C( 3542495328854217575),
        UINT64_C(  573563917657000167), UINT64_C(18123697937442058851), UINT64_C( 2682912542487189392), UINT64_C( 8187223655398445489) },
      { UINT64_C(11782970512115796773), UINT64_C( 1977731742014651191), UINT64_C( 1818089280532332987), UINT64_C( 9260298426515619465),
        UINT64_C(  573563917657000167), UINT64_C(18123697937442058851), UINT64_C(11613114483488563344), UINT64_C( 8187223655398445489) },
      UINT8_C( 11) },
    { UINT8_C(105),
      { UINT64_C(18350666227617883298), UINT64_C( 5545137328445023473), UINT64_C( 6932429254757846094), UINT64_C( 7615554840417476826),
        UINT64_C( 3781426386450356935), UINT64_C(14630361743965565879), UINT64_C( 3573174566509569928), UINT64_C(15548438090266127767) },
      { UINT64_C( 8807016408309526720), UINT64_C(14288020826152681729), UINT64_C(11109976777101642919), UINT64_C( 7615554840417476826),
        UINT64_C( 3781426386450356935), UINT64_C(14630361743965565879), UINT64_C(15689332850711562269), UINT64_C(15548438090266127767) },
      UINT8_C( 65) },
    { UINT8_C( 66),
      { UINT64_C( 2280392441801150357), UINT64_C(10984787542446999387), UINT64_C(  891334926573341679), UINT64_C(  775922561868026575),
        UINT64_C(13810483298374045616), UINT64_C( 1576849372273399865), UINT64_C(12039000142083272611), UINT64_C(13794785209501642224) },
      { UINT64_C( 7484683711620349115), UINT64_C(10984787542446999387), UINT64_C( 5999177761494222018), UINT64_C(  775922561868026575),
        UINT64_C( 1817782789168292005), UINT64_C( 4716408445916998548), UINT64_C(12039000142083272611), UINT64_C(13794785209501642224) },
      UINT8_C(  0) },
    { UINT8_C( 32),
      { UINT64_C(12072114441226749538), UINT64_C( 2532998024493467638), UINT64_C(16249206416210936248), UINT64_C( 6608306747913693861),
        UINT64_C(11472781136736347249), UINT64_C(12174129123769838472), UINT64_C(11562966735554884722), UINT64_C( 9991211692701625682) },
      { UINT64_C(12111958547250257870), UINT64_C( 2532998024493467638), UINT64_C( 8664028643092676000), UINT64_C( 6608306747913693861),
        UINT64_C(11472781136736347249), UINT64_C(12174129123769838472), UINT64_C(11562966735554884722), UINT64_C(16223172949675830432) },
      UINT8_C(  0) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512i a = simde_x_mm512_loadu_epu64(test_vec[i].a);
    simde__m512i b = simde_x_mm512_loadu_epu64(test_vec[i].b);
    simde__mmask8 r = simde_mm512_mask_cmpneq_epu64_mask(test_vec[i].k1, a, b);
    simde_assert_equal_mmask8(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k1 = simde_test_x86_random_mmask8();
    simde__m512i a = simde_test_x86_random_u64x8();
    simde__m512i b = simde_x_mm512_mask_blend_epu64(simde_test_x86_random_mmask8(), a, simde_test_x86_random_u64x8());
    simde__mmask8 r = simde_mm512_mask_cmpneq_epu64_mask(k1, a, b);

    simde_test_x86_write_mmask8(2, k1, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_u64x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_u64x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

#if !defined(SIMDE_BUG_GCC_96174)

static int
test_simde_mm512_cmpneq_ps_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde_float32 a[16];
    const simde_float32 b[16];
    const simde__mmask16 r;
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(   520.74), SIMDE_FLOAT32_C(   928.84), SIMDE_FLOAT32_C(   588.42), SIMDE_FLOAT32_C(   751.64),
        SIMDE_FLOAT32_C(  -914.96), SIMDE_FLOAT32_C(   985.05), SIMDE_FLOAT32_C(  -163.48), SIMDE_FLOAT32_C(  -288.82),
        SIMDE_FLOAT32_C(  -854.27), SIMDE_FLOAT32_C(   -32.27), SIMDE_FLOAT32_C(  -347.86), SIMDE_FLOAT32_C(  -514.04),
        SIMDE_FLOAT32_C(   181.80), SIMDE_FLOAT32_C(   740.50), SIMDE_FLOAT32_C(   394.17), SIMDE_FLOAT32_C(   316.86) },
      { SIMDE_FLOAT32_C(   520.74), SIMDE_FLOAT32_C(  -830.02), SIMDE_FLOAT32_C(   277.96), SIMDE_FLOAT32_C(   382.64),
        SIMDE_FLOAT32_C(  -918.57), SIMDE_FLOAT32_C(  -289.86), SIMDE_FLOAT32_C(  -163.48), SIMDE_FLOAT32_C(   109.57),
        SIMDE_FLOAT32_C(  -854.27), SIMDE_FLOAT32_C(   -32.27), SIMDE_FLOAT32_C(  -347.86), SIMDE_FLOAT32_C(  -514.04),
        SIMDE_FLOAT32_C(    -3.11), SIMDE_FLOAT32_C(   740.50), SIMDE_FLOAT32_C(   -65.03), SIMDE_FLOAT32_C(   316.86) },
      UINT16_C(20670) },
    { { SIMDE_FLOAT32_C(  -730.74), SIMDE_FLOAT32_C(  -667.76), SIMDE_FLOAT32_C(  -491.56), SIMDE_FLOAT32_C(   105.78),
        SIMDE_FLOAT32_C(    43.42), SIMDE_FLOAT32_C(  -345.82), SIMDE_FLOAT32_C(  -926.49), SIMDE_FLOAT32_C(   695.56),
        SIMDE_FLOAT32_C(   140.14), SIMDE_FLOAT32_C(   255.31), SIMDE_FLOAT32_C(   436.06), SIMDE_FLOAT32_C(  -465.69),
        SIMDE_FLOAT32_C(  -427.83), SIMDE_FLOAT32_C(  -119.48), SIMDE_FLOAT32_C(  -295.71), SIMDE_FLOAT32_C(   850.14) },
      { SIMDE_FLOAT32_C(  -736.84), SIMDE_FLOAT32_C(  -667.76), SIMDE_FLOAT32_C(  -491.56), SIMDE_FLOAT32_C(   687.74),
        SIMDE_FLOAT32_C(   895.30), SIMDE_FLOAT32_C(  -389.42), SIMDE_FLOAT32_C(  -926.49), SIMDE_FLOAT32_C(  -782.37),
        SIMDE_FLOAT32_C(   140.14), SIMDE_FLOAT32_C(  -451.66), SIMDE_FLOAT32_C(  -464.01), SIMDE_FLOAT32_C(  -465.69),
        SIMDE_FLOAT32_C(  -427.83), SIMDE_FLOAT32_C(  -119.48), SIMDE_FLOAT32_C(  -295.71), SIMDE_FLOAT32_C(   850.14) },
      UINT16_C( 1721) },
    { { SIMDE_FLOAT32_C(  -558.99), SIMDE_FLOAT32_C(  -841.14), SIMDE_FLOAT32_C(   549.79), SIMDE_FLOAT32_C(  -485.48),
        SIMDE_FLOAT32_C(   854.42), SIMDE_FLOAT32_C(  -310.07), SIMDE_FLOAT32_C(   769.83), SIMDE_FLOAT32_C(   290.48),
        SIMDE_FLOAT32_C(   224.24), SIMDE_FLOAT32_C(  -658.00), SIMDE_FLOAT32_C(  -829.00), SIMDE_FLOAT32_C(   928.53),
        SIMDE_FLOAT32_C(  -807.86), SIMDE_FLOAT32_C(  -565.84), SIMDE_FLOAT32_C(  -285.75), SIMDE_FLOAT32_C(  -247.58) },
      { SIMDE_FLOAT32_C(  -558.99), SIMDE_FLOAT32_C(  -390.45), SIMDE_FLOAT32_C(   549.79), SIMDE_FLOAT32_C(  -485.48),
        SIMDE_FLOAT32_C(  -172.83), SIMDE_FLOAT32_C(  -310.07), SIMDE_FLOAT32_C(   769.83), SIMDE_FLOAT32_C(   363.17),
        SIMDE_FLOAT32_C(  -844.43), SIMDE_FLOAT32_C(  -658.00), SIMDE_FLOAT32_C(  -829.00), SIMDE_FLOAT32_C(  -457.27),
        SIMDE_FLOAT32_C(  -377.12), SIMDE_FLOAT32_C(   261.80), SIMDE_FLOAT32_C(   438.34), SIMDE_FLOAT32_C(  -247.58) },
      UINT16_C(31122) },
    { { SIMDE_FLOAT32_C(   578.41), SIMDE_FLOAT32_C(   275.08), SIMDE_FLOAT32_C(   678.06), SIMDE_FLOAT32_C(   348.25),
        SIMDE_FLOAT32_C(  -434.44), SIMDE_FLOAT32_C(   -97.70), SIMDE_FLOAT32_C(   690.25), SIMDE_FLOAT32_C(  -263.43),
        SIMDE_FLOAT32_C(  -169.17), SIMDE_FLOAT32_C(   882.39), SIMDE_FLOAT32_C(   170.73), SIMDE_FLOAT32_C(   545.08),
        SIMDE_FLOAT32_C(  -365.19), SIMDE_FLOAT32_C(   292.63), SIMDE_FLOAT32_C(  -845.37), SIMDE_FLOAT32_C(   997.81) },
      { SIMDE_FLOAT32_C(   578.41), SIMDE_FLOAT32_C(   -18.19), SIMDE_FLOAT32_C(   678.06), SIMDE_FLOAT32_C(   187.68),
        SIMDE_FLOAT32_C(  -655.03), SIMDE_FLOAT32_C(   -97.70), SIMDE_FLOAT32_C(  -524.66), SIMDE_FLOAT32_C(  -263.43),
        SIMDE_FLOAT32_C(   -12.08), SIMDE_FLOAT32_C(   882.39), SIMDE_FLOAT32_C(   753.13), SIMDE_FLOAT32_C(   545.08),
        SIMDE_FLOAT32_C(  -837.89), SIMDE_FLOAT32_C(   292.63), SIMDE_FLOAT32_C(   414.39), SIMDE_FLOAT32_C(   740.52) },
      UINT16_C(54618) },
    { { SIMDE_FLOAT32_C(    88.77), SIMDE_FLOAT32_C(    14.43), SIMDE_FLOAT32_C(   994.74), SIMDE_FLOAT32_C(  -220.98),
        SIMDE_FLOAT32_C(   750.99), SIMDE_FLOAT32_C(  -174.43), SIMDE_FLOAT32_C(  -338.59), SIMDE_FLOAT32_C(   -78.28),
        SIMDE_FLOAT32_C(  -629.35), SIMDE_FLOAT32_C(   296.22), SIMDE_FLOAT32_C(  -785.65), SIMDE_FLOAT32_C(  -474.71),
        SIMDE_FLOAT32_C(   294.03), SIMDE_FLOAT32_C(   180.34), SIMDE_FLOAT32_C(   507.09), SIMDE_FLOAT32_C(   583.65) },
      { SIMDE_FLOAT32_C(  -631.98), SIMDE_FLOAT32_C(    14.43), SIMDE_FLOAT32_C(   994.74), SIMDE_FLOAT32_C(  -156.65),
        SIMDE_FLOAT32_C(   750.99), SIMDE_FLOAT32_C(    16.75), SIMDE_FLOAT32_C(  -338.59), SIMDE_FLOAT32_C(   -78.28),
        SIMDE_FLOAT32_C(   443.01), SIMDE_FLOAT32_C(  -896.32), SIMDE_FLOAT32_C(  -785.65), SIMDE_FLOAT32_C(  -142.60),
        SIMDE_FLOAT32_C(   294.03), SIMDE_FLOAT32_C(   719.17), SIMDE_FLOAT32_C(   949.84), SIMDE_FLOAT32_C(   -67.03) },
      UINT16_C(60201) },
    { { SIMDE_FLOAT32_C(   711.99), SIMDE_FLOAT32_C(  -515.42), SIMDE_FLOAT32_C(  -229.84), SIMDE_FLOAT32_C(  -626.61),
        SIMDE_FLOAT32_C(   406.31), SIMDE_FLOAT32_C(   140.81), SIMDE_FLOAT32_C(   669.61), SIMDE_FLOAT32_C(   620.66),
        SIMDE_FLOAT32_C(   666.09), SIMDE_FLOAT32_C(   -36.36), SIMDE_FLOAT32_C(  -199.00), SIMDE_FLOAT32_C(   173.19),
        SIMDE_FLOAT32_C(  -452.71), SIMDE_FLOAT32_C(   169.01), SIMDE_FLOAT32_C(    25.25), SIMDE_FLOAT32_C(  -423.88) },
      { SIMDE_FLOAT32_C(   711.99), SIMDE_FLOAT32_C(   368.65), SIMDE_FLOAT32_C(   592.87), SIMDE_FLOAT32_C(   953.93),
        SIMDE_FLOAT32_C(   465.17), SIMDE_FLOAT32_C(    35.88), SIMDE_FLOAT32_C(   669.61), SIMDE_FLOAT32_C(   620.66),
        SIMDE_FLOAT32_C(   893.27), SIMDE_FLOAT32_C(   901.81), SIMDE_FLOAT32_C(  -199.00), SIMDE_FLOAT32_C(   843.12),
        SIMDE_FLOAT32_C(  -452.71), SIMDE_FLOAT32_C(   188.24), SIMDE_FLOAT32_C(    25.25), SIMDE_FLOAT32_C(  -453.23) },
      UINT16_C(43838) },
    { { SIMDE_FLOAT32_C(   -79.84), SIMDE_FLOAT32_C(    79.13), SIMDE_FLOAT32_C(   698.67), SIMDE_FLOAT32_C(  -410.23),
        SIMDE_FLOAT32_C(  -300.21), SIMDE_FLOAT32_C(   364.76), SIMDE_FLOAT32_C(   553.42), SIMDE_FLOAT32_C(   500.78),
        SIMDE_FLOAT32_C(  -462.05), SIMDE_FLOAT32_C(  -899.29), SIMDE_FLOAT32_C(  -330.21), SIMDE_FLOAT32_C(   563.20),
        SIMDE_FLOAT32_C(  -323.17), SIMDE_FLOAT32_C(  -317.85), SIMDE_FLOAT32_C(   -68.15), SIMDE_FLOAT32_C(  -730.31) },
      { SIMDE_FLOAT32_C(  -363.91), SIMDE_FLOAT32_C(    79.13), SIMDE_FLOAT32_C(   698.67), SIMDE_FLOAT32_C(  -306.30),
        SIMDE_FLOAT32_C(   132.51), SIMDE_FLOAT32_C(   198.84), SIMDE_FLOAT32_C(  -404.49), SIMDE_FLOAT32_C(   500.78),
        SIMDE_FLOAT32_C(    41.96), SIMDE_FLOAT32_C(  -899.29), SIMDE_FLOAT32_C(  -330.21), SIMDE_FLOAT32_C(   563.20),
        SIMDE_FLOAT32_C(  -323.17), SIMDE_FLOAT32_C(  -551.79), SIMDE_FLOAT32_C(   387.52), SIMDE_FLOAT32_C(  -102.78) },
      UINT16_C(57721) },
    { { SIMDE_FLOAT32_C(   486.99), SIMDE_FLOAT32_C(  -772.87), SIMDE_FLOAT32_C(  -549.06), SIMDE_FLOAT32_C(    40.41),
        SIMDE_FLOAT32_C(   727.91), SIMDE_FLOAT32_C(   -11.11), SIMDE_FLOAT32_C(   141.12), SIMDE_FLOAT32_C(  -602.30),
        SIMDE_FLOAT32_C(  -447.91), SIMDE_FLOAT32_C(   817.95), SIMDE_FLOAT32_C(    79.85), SIMDE_FLOAT32_C(   483.95),
        SIMDE_FLOAT32_C(  -912.36), SIMDE_FLOAT32_C(   715.94), SIMDE_FLOAT32_C(   880.98), SIMDE_FLOAT32_C(   393.21) },
      { SIMDE_FLOAT32_C(  -590.36), SIMDE_FLOAT32_C(  -772.87), SIMDE_FLOAT32_C(  -549.06), SIMDE_FLOAT32_C(    40.41),
        SIMDE_FLOAT32_C(  -399.36), SIMDE_FLOAT32_C(   634.02), SIMDE_FLOAT32_C(  -564.57), SIMDE_FLOAT32_C(   376.03),
        SIMDE_FLOAT32_C(  -536.32), SIMDE_FLOAT32_C(   817.95), SIMDE_FLOAT32_C(   824.24), SIMDE_FLOAT32_C(   851.20),
        SIMDE_FLOAT32_C(   309.71), SIMDE_FLOAT32_C(   715.94), SIMDE_FLOAT32_C(   -62.61), SIMDE_FLOAT32_C(  -203.30) },
      UINT16_C(56817) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512 a = simde_mm512_loadu_ps(test_vec[i].a);
    simde__m512 b = simde_mm512_loadu_ps(test_vec[i].b);
    simde__mmask16 r = simde_mm512_cmpneq_ps_mask(a, b);
    simde_assert_equal_mmask16(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m512 a = simde_test_x86_random_f32x16(-1000.0, 1000.0);
    simde__m512 b = simde_mm512_mask_blend_ps(simde_test_x86_random_mmask16(), a, simde_test_x86_random_f32x16(-1000.0, 1000.0));
    simde__mmask16 r = simde_mm512_cmpneq_ps_mask(a, b);

    simde_test_x86_write_f32x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f32x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_mask_cmpneq_ps_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask16 k1;
    const simde_float32 a[16];
    const simde_float32 b[16];
    const simde__mmask16 r;
  } test_vec[] = {
    { UINT16_C(13015),
      { SIMDE_FLOAT32_C(  -622.78), SIMDE_FLOAT32_C(   -21.76), SIMDE_FLOAT32_C(   704.31), SIMDE_FLOAT32_C(   -70.68),
        SIMDE_FLOAT32_C(  -203.82), SIMDE_FLOAT32_C(  -215.84), SIMDE_FLOAT32_C(  -586.73), SIMDE_FLOAT32_C(  -116.17),
        SIMDE_FLOAT32_C(  -499.90), SIMDE_FLOAT32_C(  -705.76), SIMDE_FLOAT32_C(  -722.96), SIMDE_FLOAT32_C(   -90.26),
        SIMDE_FLOAT32_C(   307.73), SIMDE_FLOAT32_C(  -130.90), SIMDE_FLOAT32_C(   914.88), SIMDE_FLOAT32_C(   908.37) },
      { SIMDE_FLOAT32_C(  -496.88), SIMDE_FLOAT32_C(  -649.69), SIMDE_FLOAT32_C(   704.31), SIMDE_FLOAT32_C(   -70.68),
        SIMDE_FLOAT32_C(  -203.82), SIMDE_FLOAT32_C(   108.63), SIMDE_FLOAT32_C(  -182.00), SIMDE_FLOAT32_C(  -927.48),
        SIMDE_FLOAT32_C(  -499.90), SIMDE_FLOAT32_C(  -705.76), SIMDE_FLOAT32_C(  -130.78), SIMDE_FLOAT32_C(   -90.26),
        SIMDE_FLOAT32_C(   307.73), SIMDE_FLOAT32_C(  -130.90), SIMDE_FLOAT32_C(   345.52), SIMDE_FLOAT32_C(   908.37) },
      UINT16_C(  195) },
    { UINT16_C(26125),
      { SIMDE_FLOAT32_C(   833.99), SIMDE_FLOAT32_C(  -136.47), SIMDE_FLOAT32_C(   364.58), SIMDE_FLOAT32_C(  -665.90),
        SIMDE_FLOAT32_C(   157.77), SIMDE_FLOAT32_C(   641.62), SIMDE_FLOAT32_C(   243.83), SIMDE_FLOAT32_C(  -534.50),
        SIMDE_FLOAT32_C(  -489.28), SIMDE_FLOAT32_C(   158.72), SIMDE_FLOAT32_C(  -626.13), SIMDE_FLOAT32_C(    13.83),
        SIMDE_FLOAT32_C(   509.03), SIMDE_FLOAT32_C(   658.26), SIMDE_FLOAT32_C(   980.63), SIMDE_FLOAT32_C(  -728.16) },
      { SIMDE_FLOAT32_C(  -233.11), SIMDE_FLOAT32_C(  -201.37), SIMDE_FLOAT32_C(   364.58), SIMDE_FLOAT32_C(  -665.90),
        SIMDE_FLOAT32_C(   157.77), SIMDE_FLOAT32_C(   641.62), SIMDE_FLOAT32_C(   243.83), SIMDE_FLOAT32_C(   697.74),
        SIMDE_FLOAT32_C(   919.91), SIMDE_FLOAT32_C(   158.72), SIMDE_FLOAT32_C(   218.69), SIMDE_FLOAT32_C(   604.48),
        SIMDE_FLOAT32_C(   509.03), SIMDE_FLOAT32_C(   668.95), SIMDE_FLOAT32_C(  -914.76), SIMDE_FLOAT32_C(   495.36) },
      UINT16_C(25601) },
    { UINT16_C(36511),
      { SIMDE_FLOAT32_C(    91.44), SIMDE_FLOAT32_C(    73.29), SIMDE_FLOAT32_C(  -844.24), SIMDE_FLOAT32_C(   602.16),
        SIMDE_FLOAT32_C(  -767.99), SIMDE_FLOAT32_C(  -470.38), SIMDE_FLOAT32_C(  -384.01), SIMDE_FLOAT32_C(   741.04),
        SIMDE_FLOAT32_C(  -812.12), SIMDE_FLOAT32_C(  -403.38), SIMDE_FLOAT32_C(  -987.12), SIMDE_FLOAT32_C(   -45.23),
        SIMDE_FLOAT32_C(   395.25), SIMDE_FLOAT32_C(  -642.77), SIMDE_FLOAT32_C(  -818.13), SIMDE_FLOAT32_C(   949.28) },
      { SIMDE_FLOAT32_C(    91.44), SIMDE_FLOAT32_C(   447.89), SIMDE_FLOAT32_C(  -844.24), SIMDE_FLOAT32_C(   490.71),
        SIMDE_FLOAT32_C(  -940.58), SIMDE_FLOAT32_C(  -134.30), SIMDE_FLOAT32_C(    95.19), SIMDE_FLOAT32_C(   741.04),
        SIMDE_FLOAT32_C(  -465.35), SIMDE_FLOAT32_C(  -403.38), SIMDE_FLOAT32_C(  -987.12), SIMDE_FLOAT32_C(   -45.23),
        SIMDE_FLOAT32_C(  -369.76), SIMDE_FLOAT32_C(    45.61), SIMDE_FLOAT32_C(  -242.61), SIMDE_FLOAT32_C(   949.28) },
      UINT16_C(   26) },
    { UINT16_C(43466),
      { SIMDE_FLOAT32_C(   442.76), SIMDE_FLOAT32_C(   939.82), SIMDE_FLOAT32_C(  -908.04), SIMDE_FLOAT32_C(   630.65),
        SIMDE_FLOAT32_C(  -463.56), SIMDE_FLOAT32_C(  -895.17), SIMDE_FLOAT32_C(  -414.58), SIMDE_FLOAT32_C(   931.70),
        SIMDE_FLOAT32_C(  -537.94), SIMDE_FLOAT32_C(  -232.71), SIMDE_FLOAT32_C(   880.97), SIMDE_FLOAT32_C(  -967.14),
        SIMDE_FLOAT32_C(  -784.82), SIMDE_FLOAT32_C(   527.99), SIMDE_FLOAT32_C(   523.57), SIMDE_FLOAT32_C(  -725.40) },
      { SIMDE_FLOAT32_C(   442.76), SIMDE_FLOAT32_C(   939.82), SIMDE_FLOAT32_C(  -908.04), SIMDE_FLOAT32_C(   630.65),
        SIMDE_FLOAT32_C(  -463.56), SIMDE_FLOAT32_C(  -895.17), SIMDE_FLOAT32_C(   995.48), SIMDE_FLOAT32_C(  -570.57),
        SIMDE_FLOAT32_C(  -537.94), SIMDE_FLOAT32_C(  -232.71), SIMDE_FLOAT32_C(  -848.90), SIMDE_FLOAT32_C(  -967.14),
        SIMDE_FLOAT32_C(  -784.82), SIMDE_FLOAT32_C(   474.94), SIMDE_FLOAT32_C(   523.57), SIMDE_FLOAT32_C(   108.77) },
      UINT16_C(41152) },
    { UINT16_C(15384),
      { SIMDE_FLOAT32_C(   -76.23), SIMDE_FLOAT32_C(   324.83), SIMDE_FLOAT32_C(   882.90), SIMDE_FLOAT32_C(   385.83),
        SIMDE_FLOAT32_C(  -907.88), SIMDE_FLOAT32_C(   763.87), SIMDE_FLOAT32_C(   418.70), SIMDE_FLOAT32_C(  -692.70),
        SIMDE_FLOAT32_C(   291.86), SIMDE_FLOAT32_C(   -57.73), SIMDE_FLOAT32_C(  -418.09), SIMDE_FLOAT32_C(   685.55),
        SIMDE_FLOAT32_C(   561.03), SIMDE_FLOAT32_C(  -422.70), SIMDE_FLOAT32_C(  -386.10), SIMDE_FLOAT32_C(   360.21) },
      { SIMDE_FLOAT32_C(   -76.23), SIMDE_FLOAT32_C(  -390.62), SIMDE_FLOAT32_C(   789.64), SIMDE_FLOAT32_C(   385.83),
        SIMDE_FLOAT32_C(  -907.88), SIMDE_FLOAT32_C(   940.74), SIMDE_FLOAT32_C(  -577.93), SIMDE_FLOAT32_C(    28.25),
        SIMDE_FLOAT32_C(   415.68), SIMDE_FLOAT32_C(   149.05), SIMDE_FLOAT32_C(  -862.99), SIMDE_FLOAT32_C(  -169.56),
        SIMDE_FLOAT32_C(   561.03), SIMDE_FLOAT32_C(  -422.70), SIMDE_FLOAT32_C(  -218.36), SIMDE_FLOAT32_C(  -108.25) },
      UINT16_C( 3072) },
    { UINT16_C(40689),
      { SIMDE_FLOAT32_C(  -571.59), SIMDE_FLOAT32_C(   696.28), SIMDE_FLOAT32_C(  -399.31), SIMDE_FLOAT32_C(   720.27),
        SIMDE_FLOAT32_C(  -361.45), SIMDE_FLOAT32_C(   182.59), SIMDE_FLOAT32_C(   405.83), SIMDE_FLOAT32_C(  -800.43),
        SIMDE_FLOAT32_C(   759.89), SIMDE_FLOAT32_C(  -980.28), SIMDE_FLOAT32_C(   559.78), SIMDE_FLOAT32_C(   548.74),
        SIMDE_FLOAT32_C(  -370.90), SIMDE_FLOAT32_C(   349.42), SIMDE_FLOAT32_C(   594.74), SIMDE_FLOAT32_C(   991.34) },
      { SIMDE_FLOAT32_C(   290.16), SIMDE_FLOAT32_C(   696.28), SIMDE_FLOAT32_C(    19.59), SIMDE_FLOAT32_C(   720.27),
        SIMDE_FLOAT32_C(   165.86), SIMDE_FLOAT32_C(   156.60), SIMDE_FLOAT32_C(   405.83), SIMDE_FLOAT32_C(   133.84),
        SIMDE_FLOAT32_C(  -966.97), SIMDE_FLOAT32_C(  -980.28), SIMDE_FLOAT32_C(  -974.41), SIMDE_FLOAT32_C(   548.74),
        SIMDE_FLOAT32_C(   -17.53), SIMDE_FLOAT32_C(  -696.83), SIMDE_FLOAT32_C(   594.74), SIMDE_FLOAT32_C(   410.88) },
      UINT16_C(38065) },
    { UINT16_C(29333),
      { SIMDE_FLOAT32_C(  -689.06), SIMDE_FLOAT32_C(  -463.02), SIMDE_FLOAT32_C(  -162.43), SIMDE_FLOAT32_C(  -929.16),
        SIMDE_FLOAT32_C(  -443.30), SIMDE_FLOAT32_C(  -602.65), SIMDE_FLOAT32_C(   619.57), SIMDE_FLOAT32_C(   185.80),
        SIMDE_FLOAT32_C(   746.78), SIMDE_FLOAT32_C(   214.32), SIMDE_FLOAT32_C(   177.15), SIMDE_FLOAT32_C(    36.94),
        SIMDE_FLOAT32_C(   231.13), SIMDE_FLOAT32_C(  -803.27), SIMDE_FLOAT32_C(   742.78), SIMDE_FLOAT32_C(  -603.02) },
      { SIMDE_FLOAT32_C(  -689.06), SIMDE_FLOAT32_C(  -463.02), SIMDE_FLOAT32_C(   530.82), SIMDE_FLOAT32_C(   386.36),
        SIMDE_FLOAT32_C(  -443.30), SIMDE_FLOAT32_C(   556.41), SIMDE_FLOAT32_C(   619.57), SIMDE_FLOAT32_C(   185.80),
        SIMDE_FLOAT32_C(   859.59), SIMDE_FLOAT32_C(   214.32), SIMDE_FLOAT32_C(   990.34), SIMDE_FLOAT32_C(    36.94),
        SIMDE_FLOAT32_C(   276.66), SIMDE_FLOAT32_C(   121.49), SIMDE_FLOAT32_C(   742.78), SIMDE_FLOAT32_C(  -603.02) },
      UINT16_C(12292) },
    { UINT16_C(31556),
      { SIMDE_FLOAT32_C(   731.96), SIMDE_FLOAT32_C(   278.02), SIMDE_FLOAT32_C(   400.98), SIMDE_FLOAT32_C(   478.74),
        SIMDE_FLOAT32_C(  -507.67), SIMDE_FLOAT32_C(  -421.88), SIMDE_FLOAT32_C(  -484.32), SIMDE_FLOAT32_C(   723.46),
        SIMDE_FLOAT32_C(  -225.14), SIMDE_FLOAT32_C(  -741.54), SIMDE_FLOAT32_C(  -879.56), SIMDE_FLOAT32_C(  -871.81),
        SIMDE_FLOAT32_C(   537.52), SIMDE_FLOAT32_C(   651.27), SIMDE_FLOAT32_C(   514.55), SIMDE_FLOAT32_C(   134.51) },
      { SIMDE_FLOAT32_C(   731.96), SIMDE_FLOAT32_C(   135.19), SIMDE_FLOAT32_C(   713.96), SIMDE_FLOAT32_C(    67.27),
        SIMDE_FLOAT32_C(   283.51), SIMDE_FLOAT32_C(   704.30), SIMDE_FLOAT32_C(  -484.32), SIMDE_FLOAT32_C(  -439.83),
        SIMDE_FLOAT32_C(  -225.14), SIMDE_FLOAT32_C(  -741.54), SIMDE_FLOAT32_C(  -852.22), SIMDE_FLOAT32_C(  -515.73),
        SIMDE_FLOAT32_C(   537.52), SIMDE_FLOAT32_C(   806.22), SIMDE_FLOAT32_C(   514.55), SIMDE_FLOAT32_C(  -510.09) },
      UINT16_C(10244) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512 a = simde_mm512_loadu_ps(test_vec[i].a);
    simde__m512 b = simde_mm512_loadu_ps(test_vec[i].b);
    simde__mmask16 r = simde_mm512_mask_cmpneq_ps_mask(test_vec[i].k1, a, b);
    simde_assert_equal_mmask16(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask16 k1 = simde_test_x86_random_mmask16();
    simde__m512 a = simde_test_x86_random_f32x16(-1000.0, 1000.0);
    simde__m512 b = simde_mm512_mask_blend_ps(simde_test_x86_random_mmask16(), a, simde_test_x86_random_f32x16(-1000.0, 1000.0));
    simde__mmask16 r = simde_mm512_mask_cmpneq_ps_mask(k1, a, b);

    simde_test_x86_write_mmask16(2, k1, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f32x16(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_cmpneq_pd_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde_float64 a[8];
    const simde_float64 b[8];
    const simde__mmask8 r;
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(   968.65), SIMDE_FLOAT64_C(   576.57), SIMDE_FLOAT64_C(  -321.45), SIMDE_FLOAT64_C(  -515.68),
        SIMDE_FLOAT64_C(   300.03), SIMDE_FLOAT64_C(   453.40), SIMDE_FLOAT64_C(  -257.22), SIMDE_FLOAT64_C(   420.47) },
      { SIMDE_FLOAT64_C(   581.59), SIMDE_FLOAT64_C(  -719.70), SIMDE_FLOAT64_C(  -321.45), SIMDE_FLOAT64_C(  -515.68),
        SIMDE_FLOAT64_C(   414.81), SIMDE_FLOAT64_C(  -720.58), SIMDE_FLOAT64_C(  -257.22), SIMDE_FLOAT64_C(   420.47) },
      UINT8_C( 51) },
    { { SIMDE_FLOAT64_C(   514.84), SIMDE_FLOAT64_C(  -166.93), SIMDE_FLOAT64_C(  -727.01), SIMDE_FLOAT64_C(  -924.99),
        SIMDE_FLOAT64_C(   658.87), SIMDE_FLOAT64_C(   696.33), SIMDE_FLOAT64_C(  -777.21), SIMDE_FLOAT64_C(  -856.86) },
      { SIMDE_FLOAT64_C(   514.84), SIMDE_FLOAT64_C(  -166.93), SIMDE_FLOAT64_C(  -157.42), SIMDE_FLOAT64_C(  -924.99),
        SIMDE_FLOAT64_C(   113.24), SIMDE_FLOAT64_C(   696.33), SIMDE_FLOAT64_C(  -777.21), SIMDE_FLOAT64_C(  -310.19) },
      UINT8_C(148) },
    { { SIMDE_FLOAT64_C(   397.17), SIMDE_FLOAT64_C(   989.84), SIMDE_FLOAT64_C(    74.96), SIMDE_FLOAT64_C(  -860.05),
        SIMDE_FLOAT64_C(   410.32), SIMDE_FLOAT64_C(  -343.45), SIMDE_FLOAT64_C(  -579.76), SIMDE_FLOAT64_C(  -517.95) },
      { SIMDE_FLOAT64_C(   397.17), SIMDE_FLOAT64_C(   989.84), SIMDE_FLOAT64_C(  -238.53), SIMDE_FLOAT64_C(   984.04),
        SIMDE_FLOAT64_C(   410.32), SIMDE_FLOAT64_C(  -343.45), SIMDE_FLOAT64_C(  -579.76), SIMDE_FLOAT64_C(   796.89) },
      UINT8_C(140) },
    { { SIMDE_FLOAT64_C(   573.89), SIMDE_FLOAT64_C(   455.76), SIMDE_FLOAT64_C(  -922.52), SIMDE_FLOAT64_C(   796.68),
        SIMDE_FLOAT64_C(   598.90), SIMDE_FLOAT64_C(  -468.24), SIMDE_FLOAT64_C(   825.69), SIMDE_FLOAT64_C(  -558.52) },
      { SIMDE_FLOAT64_C(   475.96), SIMDE_FLOAT64_C(   455.76), SIMDE_FLOAT64_C(  -922.52), SIMDE_FLOAT64_C(  -611.20),
        SIMDE_FLOAT64_C(   598.90), SIMDE_FLOAT64_C(  -468.24), SIMDE_FLOAT64_C(   825.69), SIMDE_FLOAT64_C(  -558.52) },
      UINT8_C(  9) },
    { { SIMDE_FLOAT64_C(   925.91), SIMDE_FLOAT64_C(    28.90), SIMDE_FLOAT64_C(  -262.45), SIMDE_FLOAT64_C(  -653.85),
        SIMDE_FLOAT64_C(   510.96), SIMDE_FLOAT64_C(  -509.75), SIMDE_FLOAT64_C(  -818.80), SIMDE_FLOAT64_C(  -727.57) },
      { SIMDE_FLOAT64_C(   925.91), SIMDE_FLOAT64_C(    28.90), SIMDE_FLOAT64_C(  -262.45), SIMDE_FLOAT64_C(   973.16),
        SIMDE_FLOAT64_C(   510.96), SIMDE_FLOAT64_C(  -238.27), SIMDE_FLOAT64_C(  -818.80), SIMDE_FLOAT64_C(  -727.57) },
      UINT8_C( 40) },
    { { SIMDE_FLOAT64_C(   343.74), SIMDE_FLOAT64_C(   996.58), SIMDE_FLOAT64_C(   370.97), SIMDE_FLOAT64_C(   169.42),
        SIMDE_FLOAT64_C(  -561.94), SIMDE_FLOAT64_C(  -153.07), SIMDE_FLOAT64_C(  -891.65), SIMDE_FLOAT64_C(   822.54) },
      { SIMDE_FLOAT64_C(   235.73), SIMDE_FLOAT64_C(   737.10), SIMDE_FLOAT64_C(   370.97), SIMDE_FLOAT64_C(    21.70),
        SIMDE_FLOAT64_C(  -561.94), SIMDE_FLOAT64_C(  -153.07), SIMDE_FLOAT64_C(   -52.39), SIMDE_FLOAT64_C(   822.54) },
      UINT8_C( 75) },
    { { SIMDE_FLOAT64_C(   293.76), SIMDE_FLOAT64_C(   895.55), SIMDE_FLOAT64_C(  -862.62), SIMDE_FLOAT64_C(   474.97),
        SIMDE_FLOAT64_C(  -832.03), SIMDE_FLOAT64_C(  -388.34), SIMDE_FLOAT64_C(  -380.01), SIMDE_FLOAT64_C(  -451.44) },
      { SIMDE_FLOAT64_C(  -415.17), SIMDE_FLOAT64_C(   561.90), SIMDE_FLOAT64_C(   310.29), SIMDE_FLOAT64_C(   474.97),
        SIMDE_FLOAT64_C(  -832.03), SIMDE_FLOAT64_C(  -850.50), SIMDE_FLOAT64_C(  -380.01), SIMDE_FLOAT64_C(  -451.44) },
      UINT8_C( 39) },
    { { SIMDE_FLOAT64_C(  -354.96), SIMDE_FLOAT64_C(  -605.79), SIMDE_FLOAT64_C(  -632.60), SIMDE_FLOAT64_C(  -246.61),
        SIMDE_FLOAT64_C(  -783.24), SIMDE_FLOAT64_C(   603.14), SIMDE_FLOAT64_C(  -509.51), SIMDE_FLOAT64_C(    45.34) },
      { SIMDE_FLOAT64_C(  -375.17), SIMDE_FLOAT64_C(  -605.79), SIMDE_FLOAT64_C(   954.92), SIMDE_FLOAT64_C(   572.44),
        SIMDE_FLOAT64_C(  -783.24), SIMDE_FLOAT64_C(   602.06), SIMDE_FLOAT64_C(  -133.79), SIMDE_FLOAT64_C(    45.34) },
      UINT8_C(109) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512d a = simde_mm512_loadu_pd(test_vec[i].a);
    simde__m512d b = simde_mm512_loadu_pd(test_vec[i].b);
    simde__mmask8 r = simde_mm512_cmpneq_pd_mask(a, b);
    simde_assert_equal_mmask8(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m512d a = simde_test_x86_random_f64x8(-1000.0, 1000.0);
    simde__m512d b = simde_mm512_mask_blend_pd(simde_test_x86_random_mmask8(), a, simde_test_x86_random_f64x8(-1000.0, 1000.0));
    simde__mmask8 r = simde_mm512_cmpneq_pd_mask(a, b);

    simde_test_x86_write_f64x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f64x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_mask_cmpneq_pd_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k1;
    const simde_float64 a[8];
    const simde_float64 b[8];
    const simde__mmask8 r;
  } test_vec[] = {
    { UINT8_C(246),
      { SIMDE_FLOAT64_C(  -705.71), SIMDE_FLOAT64_C(  -648.90), SIMDE_FLOAT64_C(   -38.84), SIMDE_FLOAT64_C(  -157.15),
        SIMDE_FLOAT64_C(   -64.07), SIMDE_FLOAT64_C(  -476.93), SIMDE_FLOAT64_C(  -846.87), SIMDE_FLOAT64_C(    67.81) },
      { SIMDE_FLOAT64_C(  -705.71), SIMDE_FLOAT64_C(  -697.37), SIMDE_FLOAT64_C(   -38.84), SIMDE_FLOAT64_C(  -561.20),
        SIMDE_FLOAT64_C(   823.10), SIMDE_FLOAT64_C(   188.46), SIMDE_FLOAT64_C(  -846.87), SIMDE_FLOAT64_C(    67.81) },
      UINT8_C( 50) },
    { UINT8_C( 45),
      { SIMDE_FLOAT64_C(   793.64), SIMDE_FLOAT64_C(  -567.65), SIMDE_FLOAT64_C(  -904.89), SIMDE_FLOAT64_C(  -581.53),
        SIMDE_FLOAT64_C(  -721.47), SIMDE_FLOAT64_C(  -949.96), SIMDE_FLOAT64_C(   990.92), SIMDE_FLOAT64_C(  -490.70) },
      { SIMDE_FLOAT64_C(   652.09), SIMDE_FLOAT64_C(  -142.88), SIMDE_FLOAT64_C(  -364.38), SIMDE_FLOAT64_C(  -581.53),
        SIMDE_FLOAT64_C(   198.29), SIMDE_FLOAT64_C(  -949.96), SIMDE_FLOAT64_C(   742.63), SIMDE_FLOAT64_C(  -490.70) },
      UINT8_C(  5) },
    { UINT8_C(197),
      { SIMDE_FLOAT64_C(  -317.48), SIMDE_FLOAT64_C(   925.89), SIMDE_FLOAT64_C(   746.36), SIMDE_FLOAT64_C(   165.17),
        SIMDE_FLOAT64_C(  -771.48), SIMDE_FLOAT64_C(  -710.21), SIMDE_FLOAT64_C(   603.97), SIMDE_FLOAT64_C(  -948.38) },
      { SIMDE_FLOAT64_C(  -317.48), SIMDE_FLOAT64_C(   925.89), SIMDE_FLOAT64_C(  -757.87), SIMDE_FLOAT64_C(   165.17),
        SIMDE_FLOAT64_C(   486.75), SIMDE_FLOAT64_C(  -964.23), SIMDE_FLOAT64_C(   852.46), SIMDE_FLOAT64_C(  -948.38) },
      UINT8_C( 68) },
    { UINT8_C(120),
      { SIMDE_FLOAT64_C(   631.90), SIMDE_FLOAT64_C(  -554.84), SIMDE_FLOAT64_C(  -359.70), SIMDE_FLOAT64_C(   283.99),
        SIMDE_FLOAT64_C(   302.28), SIMDE_FLOAT64_C(   275.92), SIMDE_FLOAT64_C(  -324.48), SIMDE_FLOAT64_C(  -499.42) },
      { SIMDE_FLOAT64_C(   631.90), SIMDE_FLOAT64_C(  -581.85), SIMDE_FLOAT64_C(  -359.70), SIMDE_FLOAT64_C(   978.58),
        SIMDE_FLOAT64_C(   302.28), SIMDE_FLOAT64_C(   275.92), SIMDE_FLOAT64_C(  -324.48), SIMDE_FLOAT64_C(  -156.93) },
      UINT8_C(  8) },
    { UINT8_C( 26),
      { SIMDE_FLOAT64_C(   132.86), SIMDE_FLOAT64_C(  -888.30), SIMDE_FLOAT64_C(  -815.39), SIMDE_FLOAT64_C(  -388.89),
        SIMDE_FLOAT64_C(  -451.32), SIMDE_FLOAT64_C(  -573.26), SIMDE_FLOAT64_C(  -968.78), SIMDE_FLOAT64_C(  -964.57) },
      { SIMDE_FLOAT64_C(  -537.49), SIMDE_FLOAT64_C(   883.68), SIMDE_FLOAT64_C(   617.29), SIMDE_FLOAT64_C(  -388.89),
        SIMDE_FLOAT64_C(  -985.33), SIMDE_FLOAT64_C(  -573.26), SIMDE_FLOAT64_C(  -968.78), SIMDE_FLOAT64_C(  -964.57) },
      UINT8_C( 18) },
    { UINT8_C(156),
      { SIMDE_FLOAT64_C(   930.89), SIMDE_FLOAT64_C(   208.71), SIMDE_FLOAT64_C(   164.78), SIMDE_FLOAT64_C(  -863.28),
        SIMDE_FLOAT64_C(   626.86), SIMDE_FLOAT64_C(   824.82), SIMDE_FLOAT64_C(  -884.70), SIMDE_FLOAT64_C(  -276.44) },
      { SIMDE_FLOAT64_C(   930.89), SIMDE_FLOAT64_C(  -980.23), SIMDE_FLOAT64_C(   164.78), SIMDE_FLOAT64_C(  -863.28),
        SIMDE_FLOAT64_C(  -847.24), SIMDE_FLOAT64_C(  -300.51), SIMDE_FLOAT64_C(   786.80), SIMDE_FLOAT64_C(  -276.44) },
      UINT8_C( 16) },
    { UINT8_C( 85),
      { SIMDE_FLOAT64_C(  -235.88), SIMDE_FLOAT64_C(   341.81), SIMDE_FLOAT64_C(  -629.09), SIMDE_FLOAT64_C(   226.63),
        SIMDE_FLOAT64_C(   225.49), SIMDE_FLOAT64_C(   988.20), SIMDE_FLOAT64_C(  -856.61), SIMDE_FLOAT64_C(   240.17) },
      { SIMDE_FLOAT64_C(   237.39), SIMDE_FLOAT64_C(   341.81), SIMDE_FLOAT64_C(  -629.09), SIMDE_FLOAT64_C(   226.63),
        SIMDE_FLOAT64_C(  -830.48), SIMDE_FLOAT64_C(   826.03), SIMDE_FLOAT64_C(  -856.61), SIMDE_FLOAT64_C(   240.17) },
      UINT8_C( 17) },
    { UINT8_C( 17),
      { SIMDE_FLOAT64_C(   159.11), SIMDE_FLOAT64_C(  -921.96), SIMDE_FLOAT64_C(   329.70), SIMDE_FLOAT64_C(  -673.51),
        SIMDE_FLOAT64_C(  -902.19), SIMDE_FLOAT64_C(  -103.66), SIMDE_FLOAT64_C(  -998.41), SIMDE_FLOAT64_C(  -749.43) },
      { SIMDE_FLOAT64_C(   595.83), SIMDE_FLOAT64_C(  -921.96), SIMDE_FLOAT64_C(  -412.05), SIMDE_FLOAT64_C(  -673.51),
        SIMDE_FLOAT64_C(  -902.19), SIMDE_FLOAT64_C(  -103.66), SIMDE_FLOAT64_C(  -998.41), SIMDE_FLOAT64_C(  -749.43) },
      UINT8_C(  1) },  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512d a = simde_mm512_loadu_pd(test_vec[i].a);
    simde__m512d b = simde_mm512_loadu_pd(test_vec[i].b);
    simde__mmask8 r = simde_mm512_mask_cmpneq_pd_mask(test_vec[i].k1, a, b);
    simde_assert_equal_mmask8(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k1 = simde_test_x86_random_mmask8();
    simde__m512d a = simde_test_x86_random_f64x8(-1000.0, 1000.0);
    simde__m512d b = simde_mm512_mask_blend_pd(simde_test_x86_random_mmask8(), a, simde_test_x86_random_f64x8(-1000.0, 1000.0));
    simde__mmask8 r = simde_mm512_mask_cmpneq_pd_mask(k1, a, b);

    simde_test_x86_write_mmask8(2, k1, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f64x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}
#endif /* !defined(SIMDE_BUG_GCC_96174) */

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_cmpneq_epi8_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_mask_cmpneq_epi8_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_cmpneq_epi8_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_mask_cmpneq_epi8_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_cmpneq_epi8_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_cmpneq_epi8_mask)

  SIMDE_TEST_FUNC_LIST_ENTRY(mm_cmpneq_epi16_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_mask_cmpneq_epi16_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_cmpneq_epi16_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_mask_cmpneq_epi16_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_cmpneq_epi16_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_cmpneq_epi16_mask)

  SIMDE_TEST_FUNC_LIST_ENTRY(mm_cmpneq_epi32_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_mask_cmpneq_epi32_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_cmpneq_epi32_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_mask_cmpneq_epi32_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_cmpneq_epi32_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_cmpneq_epi32_mask)

  SIMDE_TEST_FUNC_LIST_ENTRY(mm_cmpneq_epi64_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_mask_cmpneq_epi64_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_cmpneq_epi64_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_mask_cmpneq_epi64_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_cmpneq_epi64_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_cmpneq_epi64_mask)

  SIMDE_TEST_FUNC_LIST_ENTRY(mm_cmpneq_epu8_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_mask_cmpneq_epu8_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_cmpneq_epu8_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_mask_cmpneq_epu8_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_cmpneq_epu8_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_cmpneq_epu8_mask)

  SIMDE_TEST_FUNC_LIST_ENTRY(mm_cmpneq_epu16_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_mask_cmpneq_epu16_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_cmpneq_epu16_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_mask_cmpneq_epu16_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_cmpneq_epu16_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_cmpneq_epu16_mask)

  SIMDE_TEST_FUNC_LIST_ENTRY(mm_cmpneq_epu32_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_mask_cmpneq_epu32_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_cmpneq_epu32_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_mask_cmpneq_epu32_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_cmpneq_epu32_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_cmpneq_epu32_mask)

  SIMDE_TEST_FUNC_LIST_ENTRY(mm_cmpneq_epu64_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_mask_cmpneq_epu64_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_cmpneq_epu64_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_mask_cmpneq_epu64_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_cmpneq_epu64_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_cmpneq_epu64_mask)

  #if !defined(SIMDE_BUG_GCC_96174)
    SIMDE_TEST_FUNC_LIST_ENTRY(mm512_cmpneq_ps_mask)
    SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_cmpneq_ps_mask)
    SIMDE_TEST_FUNC_LIST_ENTRY(mm512_cmpneq_pd_mask)
    SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_cmpneq_pd_mask)
  #endif
SIMDE_TEST_FUNC_LIST_END

#include <test/x86/avx512/test-avx512-footer.h>
