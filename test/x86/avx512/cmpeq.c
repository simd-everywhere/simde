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
 *   2020      Himanshi Mathur <himanshi18037@iiitd.ac.in>
 *   2025      Michael R. Crusoe <crusoe@debian.org>
 */

#define SIMDE_TEST_X86_AVX512_INSN cmpeq

#include <test/x86/avx512/test-avx512.h>
#include <simde/x86/avx512/set.h>
#include <simde/x86/avx512/cmpeq.h>
#include <simde/x86/avx512/blend.h>

static int
test_simde_mm_cmpeq_epi8_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int8_t a[16];
    const int8_t b[16];
    const simde__mmask16 r;
  } test_vec[] = {
    { {  INT8_C(  38),  INT8_C(  24),  INT8_C(  55),  INT8_C(  99), -INT8_C(  36), -INT8_C(  67),  INT8_C(  30), -INT8_C(  90),
         INT8_C(  96), -INT8_C(  57),  INT8_C(  74),  INT8_C(   1), -INT8_C(  53), -INT8_C(  61),  INT8_C(  31), -INT8_C(   3) },
      {  INT8_C(  63),  INT8_C(  24),  INT8_C(  55), -INT8_C(  23), -INT8_C(  27), -INT8_C(  67),  INT8_C(  75),  INT8_C(  35),
         INT8_C(  96),  INT8_C(  88), -INT8_C(  35),  INT8_C(   4),  INT8_C(   0), -INT8_C(  63),  INT8_C(  71), -INT8_C(   3) },
      UINT16_C(33062) },
    { { -INT8_C( 118), -INT8_C(  75),  INT8_C(  59), -INT8_C(  88),  INT8_C(  91), -INT8_C( 100),  INT8_C( 111), -INT8_C(  90),
        -INT8_C(  99),  INT8_C(  59),  INT8_C( 105), -INT8_C(  68),  INT8_C(  56), -INT8_C(  88), -INT8_C(  90), -INT8_C(   5) },
      { -INT8_C( 111), -INT8_C(  75),  INT8_C( 115), -INT8_C(  35), -INT8_C(  81), -INT8_C( 100),  INT8_C(  53), -INT8_C( 116),
        -INT8_C( 114),  INT8_C(  54),  INT8_C(  78), -INT8_C(  43),  INT8_C(  56), -INT8_C(  88), -INT8_C(  90), -INT8_C(  25) },
      UINT16_C(28706) },
    { { -INT8_C( 113),  INT8_C(  56),  INT8_C(  43), -INT8_C(   2), -INT8_C(  34), -INT8_C(  56),  INT8_C(  57),  INT8_C(  71),
        -INT8_C( 124),  INT8_C( 113), -INT8_C(  16),  INT8_C(  43),  INT8_C( 109), -INT8_C( 127), -INT8_C(  73), -INT8_C(  32) },
      { -INT8_C( 113),  INT8_C( 102),  INT8_C( 106), -INT8_C( 108), -INT8_C(  13), -INT8_C(   8), -INT8_C(  54),  INT8_C(  71),
        -INT8_C( 124),  INT8_C( 113),  INT8_C( 104),  INT8_C(  33),  INT8_C(  14), -INT8_C( 127), -INT8_C(  79), -INT8_C(  99) },
      UINT16_C( 9089) },
    { { -INT8_C( 101),  INT8_C(  92), -INT8_C(  91), -INT8_C(  43), -INT8_C(  92),  INT8_C(  41),  INT8_C(  70), -INT8_C( 108),
         INT8_C(  84), -INT8_C(  77),  INT8_C(  21),  INT8_C(  11), -INT8_C( 109),  INT8_C( 116),  INT8_C( 114), -INT8_C(   3) },
      { -INT8_C( 101),  INT8_C( 101), -INT8_C(  11), -INT8_C(  46), -INT8_C(  92), -INT8_C(  61),  INT8_C(  70), -INT8_C( 108),
        -INT8_C(  28),  INT8_C(   7),  INT8_C(  84),  INT8_C(  11), -INT8_C(  92),  INT8_C( 116),  INT8_C( 114), -INT8_C(   3) },
      UINT16_C(59601) },
    { {  INT8_C(  20), -INT8_C(  46),  INT8_C(  64),  INT8_C(  91),  INT8_C( 102), -INT8_C( 107),  INT8_C(  14),  INT8_C( 124),
        -INT8_C(  96), -INT8_C(  94), -INT8_C(  16),  INT8_C(  18), -INT8_C(  97), -INT8_C(   8),  INT8_C( 119), -INT8_C( 107) },
      { -INT8_C(  54),  INT8_C(  29),  INT8_C(  64),  INT8_C(  91),  INT8_C(  44), -INT8_C( 107), -INT8_C(  54),  INT8_C( 124),
        -INT8_C(  46),  INT8_C( 110), -INT8_C(  16),  INT8_C(  68), -INT8_C(  83), -INT8_C(   8),  INT8_C( 119), -INT8_C(  62) },
      UINT16_C(25772) },
    { {  INT8_C(  29), -INT8_C(  71),  INT8_C(  48),  INT8_C(  43),  INT8_C(  53), -INT8_C(  47), -INT8_C(  51),  INT8_C(  37),
        -INT8_C(  29),  INT8_C( 109),  INT8_C(  29),  INT8_C(  91),  INT8_C(   2), -INT8_C(  25),  INT8_C( 120),  INT8_C(  90) },
      { -INT8_C(  86), -INT8_C(  92),  INT8_C(  48),  INT8_C(  43),  INT8_C(  53), -INT8_C(  47), -INT8_C(  51),  INT8_C(  37),
        -INT8_C(  84), -INT8_C( 112),  INT8_C(  29),  INT8_C(  91),  INT8_C(  82), -INT8_C(  25), -INT8_C(  93),  INT8_C( 111) },
      UINT16_C(11516) },
    { { -INT8_C( 102),  INT8_C(  57), -INT8_C(  92),  INT8_C( 104),  INT8_C(  94), -INT8_C( 120), -INT8_C(  43),  INT8_C( 124),
        -INT8_C(  29), -INT8_C(  41),  INT8_C(  99),  INT8_C(  91),  INT8_C(  49),  INT8_C(  14),  INT8_C(   0), -INT8_C(  57) },
      { -INT8_C( 102),  INT8_C(  57), -INT8_C(  92),  INT8_C( 101), -INT8_C( 101), -INT8_C( 120), -INT8_C(  43),  INT8_C( 124),
        -INT8_C(  28),  INT8_C(  71), -INT8_C(  36), -INT8_C( 121), -INT8_C(  74), -INT8_C(  33),  INT8_C(  90),  INT8_C(  80) },
      UINT16_C(  231) },
    { { -INT8_C(  72),  INT8_C( 119), -INT8_C( 121), -INT8_C( 115), -INT8_C(  13),  INT8_C( 106),  INT8_C( 100),  INT8_C(  86),
        -INT8_C(  59), -INT8_C( 107),  INT8_C( 100), -INT8_C(  59),  INT8_C(  93), -INT8_C(  25), -INT8_C(  22), -INT8_C( 115) },
      { -INT8_C(  72), -INT8_C( 123), -INT8_C( 121), -INT8_C( 115), -INT8_C(  13),  INT8_C(  77), -INT8_C( 120),  INT8_C(  86),
        -INT8_C(  44), -INT8_C( 107), -INT8_C(  46), -INT8_C(  59), -INT8_C( 114), -INT8_C(  21), -INT8_C(  22),  INT8_C(  71) },
      UINT16_C(19101) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i a = simde_mm_loadu_epi8(test_vec[i].a);
    simde__m128i b = simde_mm_loadu_epi8(test_vec[i].b);
    simde__mmask16 r = simde_mm_cmpeq_epi8_mask(a, b);
    simde_assert_equal_mmask16(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i a = simde_test_x86_random_i8x16();
    simde__m128i b = simde_mm_mask_blend_epi8(simde_test_x86_random_mmask16(), a, simde_test_x86_random_i8x16());
    simde__mmask16 r = simde_mm_cmpeq_epi8_mask(a, b);

    simde_test_x86_write_i8x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i8x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_mask_cmpeq_epi8_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask16 k1;
    const int8_t a[16];
    const int8_t b[16];
    const simde__mmask16 r;
  } test_vec[] = {
    { UINT16_C(21972),
      {  INT8_C(  31),  INT8_C(  57), -INT8_C(  85), -INT8_C(  28), -INT8_C(  50),  INT8_C(  16), -INT8_C(  86),  INT8_C(  43),
        -INT8_C(   9), -INT8_C( 108), -INT8_C(  72),  INT8_C(  67),  INT8_C(  25),  INT8_C(  34), -INT8_C( 124),  INT8_C(  48) },
      {  INT8_C( 111),  INT8_C(  57),  INT8_C(  35),  INT8_C(  68), -INT8_C(  50), -INT8_C(  11), -INT8_C(  86),  INT8_C(  43),
        -INT8_C(  32), -INT8_C(  95), -INT8_C(  72),  INT8_C(  67),  INT8_C(  25),  INT8_C(  34), -INT8_C( 105),  INT8_C(  48) },
      UINT16_C( 5328) },
    { UINT16_C(64345),
      {  INT8_C(  83),  INT8_C(   3),  INT8_C(  39),  INT8_C(  74), -INT8_C( 105), -INT8_C(  33), -INT8_C( 115), -INT8_C(  80),
         INT8_C(   1),  INT8_C(  17), -INT8_C(  32),  INT8_C( 113),  INT8_C(  29),  INT8_C(   3), -INT8_C(  75),  INT8_C( 103) },
      { -INT8_C(   7),  INT8_C(   3),  INT8_C(  39),  INT8_C(  74), -INT8_C(  55),  INT8_C(  95),  INT8_C(  28),  INT8_C(  31),
         INT8_C(   1), -INT8_C(  77), -INT8_C(  32),  INT8_C( 113),  INT8_C(  29), -INT8_C(  19), -INT8_C(  75),  INT8_C(  73) },
      UINT16_C(22792) },
    { UINT16_C(34963),
      { -INT8_C( 126),  INT8_C(  32),  INT8_C(  57), -INT8_C( 125),  INT8_C(  49),  INT8_C(  25), -INT8_C(  12),  INT8_C(  78),
         INT8_C(  29), -INT8_C(  87), -INT8_C(  75),  INT8_C(  22), -INT8_C(  47), -INT8_C(  11), -INT8_C(  17), -INT8_C( 102) },
      {  INT8_C(  84),  INT8_C(  11),  INT8_C(  57), -INT8_C( 125), -INT8_C(  65),  INT8_C(  77), -INT8_C(  12), -INT8_C(  75),
         INT8_C(  59), -INT8_C(  87), -INT8_C(   1),  INT8_C(  44), -INT8_C(  47), -INT8_C( 110), -INT8_C(  76), -INT8_C(  57) },
      UINT16_C(    0) },
    { UINT16_C(58442),
      {  INT8_C(   7),  INT8_C(  63),  INT8_C(  51),  INT8_C(  36), -INT8_C(  24), -INT8_C(  24),  INT8_C(  58), -INT8_C(  70),
        -INT8_C(  35),  INT8_C(  41),  INT8_C(  84),  INT8_C(  49),  INT8_C(  53),  INT8_C(  14), -INT8_C(  40), -INT8_C(  12) },
      {  INT8_C(  91), -INT8_C(   1), -INT8_C(  87),  INT8_C(  36), -INT8_C(  94), -INT8_C(  88),  INT8_C(  58), -INT8_C(  70),
         INT8_C(  59),  INT8_C(  41), -INT8_C(  82),  INT8_C(  49),  INT8_C(  53),  INT8_C(  14), -INT8_C(  40), -INT8_C(  12) },
      UINT16_C(57416) },
    { UINT16_C( 8335),
      { -INT8_C(  18), -INT8_C(  55), -INT8_C(  38), -INT8_C(  53), -INT8_C(  13),  INT8_C(  46), -INT8_C(   3),  INT8_C(  40),
         INT8_C(  60), -INT8_C(  43),  INT8_C(  28), -INT8_C( 104), -INT8_C(  43), -INT8_C(  59),  INT8_C(  46),  INT8_C( 119) },
      {  INT8_C( 110), -INT8_C(  55), -INT8_C(  38), -INT8_C(  53),  INT8_C( 104),  INT8_C(  46), -INT8_C(   3), -INT8_C(  52),
         INT8_C(  60),  INT8_C( 105),  INT8_C(  56), -INT8_C( 104),  INT8_C( 111), -INT8_C(  57),  INT8_C(  46),  INT8_C( 119) },
      UINT16_C(   14) },
    { UINT16_C(33832),
      {  INT8_C( 100),  INT8_C(  37), -INT8_C(  84), -INT8_C(  95), -INT8_C(   5), -INT8_C(  56),  INT8_C(  57), -INT8_C(  48),
        -INT8_C( 115),  INT8_C( 103),  INT8_C(  71), -INT8_C(   5),  INT8_C(  88), -INT8_C(  91), -INT8_C(  92), -INT8_C(  64) },
      { -INT8_C(  79),  INT8_C(  59), -INT8_C( 115), -INT8_C(  75), -INT8_C(  91), -INT8_C(  59),  INT8_C(  57),  INT8_C(  20),
        -INT8_C( 116),  INT8_C( 103),  INT8_C( 113),  INT8_C(  29),  INT8_C(  88), -INT8_C(  91), -INT8_C(  95), -INT8_C(  64) },
      UINT16_C(32768) },
    { UINT16_C(47753),
      {  INT8_C(  21), -INT8_C(  62), -INT8_C( 118), -INT8_C(  93),  INT8_C(  41), -INT8_C(  47), -INT8_C(  98), -INT8_C( 126),
         INT8_C( 118),  INT8_C(  67),  INT8_C(  66),  INT8_C(  39),  INT8_C( 126), -INT8_C(  49), -INT8_C(  36),  INT8_C(  35) },
      {  INT8_C(  21), -INT8_C(  50), -INT8_C( 118), -INT8_C(  93),  INT8_C(  27), -INT8_C(  47),  INT8_C(  62), -INT8_C(  97),
         INT8_C(  66),  INT8_C(  67), -INT8_C( 121),  INT8_C(  39),  INT8_C( 126), -INT8_C(  49), -INT8_C(  69),  INT8_C(  35) },
      UINT16_C(47625) },
    { UINT16_C(64486),
      {  INT8_C(  22), -INT8_C( 124),  INT8_C( 125), -INT8_C( 116), -INT8_C(  57), -INT8_C(  64), -INT8_C(  77),  INT8_C(  70),
        -INT8_C( 113), -INT8_C( 113),  INT8_C( 105),  INT8_C(  36),  INT8_C(  93), -INT8_C(  95),  INT8_C(  69),  INT8_C( 121) },
      {  INT8_C(  22), -INT8_C( 125),  INT8_C(  24), -INT8_C( 117),  INT8_C(  99), -INT8_C(  97), -INT8_C(  77),  INT8_C(  70),
        -INT8_C( 113),  INT8_C(  71),  INT8_C( 105), -INT8_C( 127), -INT8_C( 116), -INT8_C(  70),  INT8_C( 124), -INT8_C(  94) },
      UINT16_C(  448) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i a = simde_mm_loadu_epi8(test_vec[i].a);
    simde__m128i b = simde_mm_loadu_epi8(test_vec[i].b);
    simde__mmask16 r = simde_mm_mask_cmpeq_epi8_mask(test_vec[i].k1, a, b);
    simde_assert_equal_mmask16(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask16 k1 = simde_test_x86_random_mmask16();
    simde__m128i a = simde_test_x86_random_i8x16();
    simde__m128i b = simde_mm_mask_blend_epi8(simde_test_x86_random_mmask16(), a, simde_test_x86_random_i8x16());
    simde__mmask16 r = simde_mm_mask_cmpeq_epi8_mask(k1, a, b);

    simde_test_x86_write_mmask16(2, k1, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i8x16(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i8x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_cmpeq_epi8_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int8_t a[32];
    const int8_t b[32];
    const simde__mmask32 r;
  } test_vec[] = {
    { {  INT8_C(  46),  INT8_C(   6), -INT8_C(  70), -INT8_C(  31),  INT8_C(  76),  INT8_C(  73),  INT8_C( 113), -INT8_C(  75),
         INT8_C( 109), -INT8_C(  50),  INT8_C(  86), -INT8_C(  78),  INT8_C(  71), -INT8_C(  96),  INT8_C(  54),  INT8_C(  95),
         INT8_C(  43), -INT8_C( 103), -INT8_C(   2), -INT8_C(  72),  INT8_C(  42), -INT8_C(  83), -INT8_C(   1), -INT8_C(   2),
         INT8_C(  46), -INT8_C( 116), -INT8_C(  72), -INT8_C(  85),  INT8_C(  46), -INT8_C(   9), -INT8_C(  91),  INT8_C(  93) },
      {  INT8_C(  46),  INT8_C(  95),  INT8_C(  62),  INT8_C(  73),  INT8_C(  76), -INT8_C(  81),  INT8_C( 113),  INT8_C(  22),
         INT8_C( 109),  INT8_C(  85), -INT8_C(  56), -INT8_C(  59),  INT8_C(  71), -INT8_C(   2),  INT8_C(  54),  INT8_C(  95),
         INT8_C(  43), -INT8_C( 103), -INT8_C(   2), -INT8_C(  72),  INT8_C(  42), -INT8_C(  83), -INT8_C(   1), -INT8_C(   2),
         INT8_C(  46), -INT8_C( 116), -INT8_C(  72), -INT8_C(  85),  INT8_C(  46), -INT8_C(   9), -INT8_C(  91),  INT8_C(  93) },
      UINT32_C(4294955345) },
    { { -INT8_C(  74),  INT8_C(  87), -INT8_C(  35), -INT8_C(  75),  INT8_C( 109),  INT8_C(  91),  INT8_C(  10),  INT8_C(  53),
         INT8_C(  33), -INT8_C(   1),  INT8_C(  52),  INT8_C(  70),  INT8_C(  31), -INT8_C(  52),  INT8_C( 105), -INT8_C(   8),
        -INT8_C( 114),  INT8_C(  58), -INT8_C(  48),  INT8_C(  79),  INT8_C(  58),  INT8_C(  52), -INT8_C(  55), -INT8_C(  28),
        -INT8_C(  58),  INT8_C(  57),  INT8_C(  52), -INT8_C(  74), -INT8_C(  89), -INT8_C(  30), -INT8_C(  28),  INT8_C(  93) },
      {  INT8_C(  57),  INT8_C(  87), -INT8_C(  35), -INT8_C(  90),  INT8_C(  29),  INT8_C(  91), -INT8_C(  36),  INT8_C(  53),
         INT8_C(  27),  INT8_C(  16),  INT8_C(  52),  INT8_C(  70), -INT8_C(  36), -INT8_C(  52),  INT8_C(  51),  INT8_C( 106),
        -INT8_C( 114),  INT8_C(  58), -INT8_C(  48),  INT8_C(  79),  INT8_C(  58),  INT8_C(  52), -INT8_C(  55), -INT8_C(  28),
        -INT8_C(  58),  INT8_C(  57),  INT8_C(  52), -INT8_C(  74), -INT8_C(  89), -INT8_C(  30), -INT8_C(  28),  INT8_C(  93) },
      UINT32_C(4294913190) },
    { {  INT8_C(  61),  INT8_C( 118), -INT8_C(  16),  INT8_C(  25), -INT8_C(  76),  INT8_C(  11),  INT8_C(  41),  INT8_C(  56),
         INT8_C(  70),  INT8_C(   5),  INT8_C(  37),  INT8_C( 121),  INT8_C( 111),  INT8_C(  77),  INT8_C( 124),  INT8_C(  41),
        -INT8_C(  81), -INT8_C(  77), -INT8_C(  84), -INT8_C(  10), -INT8_C(  79),  INT8_C( 105),  INT8_C( 112),  INT8_C( 100),
        -INT8_C(  52), -INT8_C(  51), -INT8_C(   4), -INT8_C( 115),  INT8_C( 100),  INT8_C(  85),  INT8_C(  97), -INT8_C(  95) },
      {  INT8_C(  61),  INT8_C(  81), -INT8_C(  16),  INT8_C(  25), -INT8_C(  76), -INT8_C(  29),  INT8_C(  41), -INT8_C(  93),
         INT8_C(  70),  INT8_C(   5),  INT8_C(  28),  INT8_C(  87),  INT8_C( 111),  INT8_C(  77), -INT8_C( 127), -INT8_C(  39),
        -INT8_C(  81), -INT8_C(  77), -INT8_C(  84), -INT8_C(  10), -INT8_C(  79),  INT8_C( 105),  INT8_C( 112),  INT8_C( 100),
        -INT8_C(  52), -INT8_C(  51), -INT8_C(   4), -INT8_C( 115),  INT8_C( 100),  INT8_C(  85),  INT8_C(  97), -INT8_C(  95) },
      UINT32_C(4294914909) },
    { { -INT8_C(   3), -INT8_C(   1), -INT8_C(  81), -INT8_C(  76), -INT8_C(  94), -INT8_C( 105), -INT8_C( 112), -INT8_C(  66),
        -INT8_C(  17), -INT8_C(  70),  INT8_C(  87),  INT8_C( 112), -INT8_C( 108), -INT8_C(  92), -INT8_C(  99),  INT8_C(  99),
        -INT8_C(  95),  INT8_C(  52), -INT8_C(  93),  INT8_C(   3), -INT8_C( 105), -INT8_C(  79),  INT8_C(  97), -INT8_C( 121),
         INT8_C(  34),  INT8_C(  20), -INT8_C(  39),  INT8_C(  53), -INT8_C( 110),  INT8_C( 123),  INT8_C(   1), -INT8_C( 113) },
      { -INT8_C(   3), -INT8_C(   1),  INT8_C(  67), -INT8_C(  76), -INT8_C(  94), -INT8_C(  44), -INT8_C(  37),  INT8_C(  55),
        -INT8_C( 114),  INT8_C(  50), -INT8_C(  89),  INT8_C( 112), -INT8_C(  42), -INT8_C(  92), -INT8_C( 122),  INT8_C(  99),
        -INT8_C(  95),  INT8_C(  52), -INT8_C(  93),  INT8_C(   3), -INT8_C( 105), -INT8_C(  79),  INT8_C(  97), -INT8_C( 121),
         INT8_C(  34),  INT8_C(  20), -INT8_C(  39),  INT8_C(  53), -INT8_C( 110),  INT8_C( 123),  INT8_C(   1), -INT8_C( 113) },
      UINT32_C(4294944795) },
    { { -INT8_C( 125),  INT8_C(  45),  INT8_C(  43),  INT8_C(  94),  INT8_C( 100), -INT8_C(  71), -INT8_C( 112),  INT8_C(  12),
        -INT8_C(  36),  INT8_C( 103),  INT8_C(  81),  INT8_C(  98), -INT8_C(  33), -INT8_C(  54), -INT8_C( 117),  INT8_C(  90),
        -INT8_C(  38),  INT8_C( 102),  INT8_C(  55),  INT8_C( 113),  INT8_C(  99),  INT8_C(  41), -INT8_C(  30), -INT8_C( 107),
        -INT8_C(  83), -INT8_C(  50), -INT8_C(  56), -INT8_C(  64),  INT8_C(  52), -INT8_C(  83),  INT8_C(  23), -INT8_C(  73) },
      { -INT8_C( 125),  INT8_C(  66),  INT8_C(  21),  INT8_C(  62),  INT8_C( 100), -INT8_C(  90),  INT8_C(  74),  INT8_C(  12),
        -INT8_C(  36), -INT8_C( 101),  INT8_C(  81),  INT8_C(  98), -INT8_C(  33), -INT8_C(  59),  INT8_C(  70),  INT8_C(  90),
        -INT8_C(  38),  INT8_C( 102),  INT8_C(  55),  INT8_C( 113),  INT8_C(  99),  INT8_C(  41), -INT8_C(  30), -INT8_C( 107),
        -INT8_C(  83), -INT8_C(  50), -INT8_C(  56), -INT8_C(  64),  INT8_C(  52), -INT8_C(  83),  INT8_C(  23), -INT8_C(  73) },
      UINT32_C(4294942097) },
    { { -INT8_C(  79),  INT8_C( 106),  INT8_C(   8), -INT8_C(   4),  INT8_C(  66),  INT8_C(  21), -INT8_C( 105),  INT8_C( 124),
         INT8_C(   1), -INT8_C(   3),  INT8_C(  66),  INT8_C(  72),  INT8_C(  60),  INT8_C( 109), -INT8_C(  58), -INT8_C(  19),
        -INT8_C(   4),  INT8_C( 109),      INT8_MIN,  INT8_C(  31), -INT8_C(  63), -INT8_C(  31),  INT8_C(  11), -INT8_C(  43),
         INT8_C( 119), -INT8_C(  92),  INT8_C(   1), -INT8_C(  60),  INT8_C(  23),  INT8_C( 112),  INT8_C(  38), -INT8_C(  55) },
      { -INT8_C(  79),  INT8_C(  47), -INT8_C(  59), -INT8_C(   4),  INT8_C(  68),  INT8_C(  92), -INT8_C( 103),  INT8_C( 124),
         INT8_C(   1), -INT8_C(  37),  INT8_C(  66), -INT8_C( 106),  INT8_C(  73),  INT8_C(  84), -INT8_C(  58),  INT8_C(  69),
        -INT8_C(   4),  INT8_C( 109),      INT8_MIN,  INT8_C(  31), -INT8_C(  63), -INT8_C(  31),  INT8_C(  11), -INT8_C(  43),
         INT8_C( 119), -INT8_C(  92),  INT8_C(   1), -INT8_C(  60),  INT8_C(  23),  INT8_C( 112),  INT8_C(  38), -INT8_C(  55) },
      UINT32_C(4294919561) },
    { { -INT8_C(  64), -INT8_C(  70),  INT8_C(  22),  INT8_C(  90),  INT8_C(   0),  INT8_C( 112),  INT8_C(  53), -INT8_C( 114),
         INT8_C(   6),  INT8_C( 126), -INT8_C(  30), -INT8_C( 119), -INT8_C(  61), -INT8_C(  93), -INT8_C( 115),  INT8_C(  40),
         INT8_C(  37),  INT8_C( 115), -INT8_C( 104),  INT8_C( 125), -INT8_C(  49), -INT8_C(  84), -INT8_C(  42), -INT8_C(  16),
        -INT8_C(  40), -INT8_C(  97),  INT8_C(  55), -INT8_C(  51),  INT8_C(  66), -INT8_C(  83), -INT8_C( 121),  INT8_C(   3) },
      { -INT8_C(  64), -INT8_C(  70),  INT8_C(  93),  INT8_C( 104),  INT8_C(   0),  INT8_C( 112),  INT8_C(  53), -INT8_C( 114),
         INT8_C(   6), -INT8_C(  39), -INT8_C(  99), -INT8_C( 119),  INT8_C( 124),  INT8_C(  43), -INT8_C( 115),  INT8_C(  40),
         INT8_C(  37),  INT8_C( 115), -INT8_C( 104),  INT8_C( 125), -INT8_C(  49), -INT8_C(  84), -INT8_C(  42), -INT8_C(  16),
        -INT8_C(  40), -INT8_C(  97),  INT8_C(  55), -INT8_C(  51),  INT8_C(  66), -INT8_C(  83), -INT8_C( 121),  INT8_C(   3) },
      UINT32_C(4294953459) },
    { {  INT8_C(  17),  INT8_C(  26), -INT8_C(  55),  INT8_C(   7),  INT8_C(  46), -INT8_C(  38), -INT8_C(  32), -INT8_C(  52),
        -INT8_C(  82),  INT8_C(  93), -INT8_C(   9), -INT8_C(  85), -INT8_C(   1), -INT8_C( 107),  INT8_C(  63),  INT8_C(  30),
         INT8_C(   2),      INT8_MIN,  INT8_C(  19),  INT8_C(  96), -INT8_C( 102), -INT8_C(  89), -INT8_C(  12), -INT8_C( 127),
         INT8_C( 125),  INT8_C(  54), -INT8_C(  17),  INT8_C(  87), -INT8_C(  33), -INT8_C(   4), -INT8_C( 115), -INT8_C(  16) },
      {  INT8_C(  17),  INT8_C(  26), -INT8_C(   9),  INT8_C(   7),  INT8_C(  46), -INT8_C(  38),  INT8_C(  17), -INT8_C(  33),
        -INT8_C(  82),  INT8_C(  93), -INT8_C(   9), -INT8_C(  85), -INT8_C(  99), -INT8_C(  55),  INT8_C(  82), -INT8_C(  97),
         INT8_C(   2),      INT8_MIN,  INT8_C(  19),  INT8_C(  96), -INT8_C( 102), -INT8_C(  89), -INT8_C(  12), -INT8_C( 127),
         INT8_C( 125),  INT8_C(  54), -INT8_C(  17),  INT8_C(  87), -INT8_C(  33), -INT8_C(   4), -INT8_C( 115), -INT8_C(  16) },
      UINT32_C(4294905659) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i a = simde_mm256_loadu_epi8(test_vec[i].a);
    simde__m256i b = simde_mm256_loadu_epi8(test_vec[i].b);
    simde__mmask32 r = simde_mm256_cmpeq_epi8_mask(a, b);
    simde_assert_equal_mmask32(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m256i a = simde_test_x86_random_i8x32();
    simde__m256i b = simde_mm256_mask_blend_epi8(simde_test_x86_random_mmask16(), a, simde_test_x86_random_i8x32());
    simde__mmask32 r = simde_mm256_cmpeq_epi8_mask(a, b);

    simde_test_x86_write_i8x32(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i8x32(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_mask_cmpeq_epi8_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask32 k1;
    const int8_t a[32];
    const int8_t b[32];
    const simde__mmask32 r;
  } test_vec[] = {
     { UINT32_C(1316809289),
      { -INT8_C(  15),  INT8_C( 122), -INT8_C(  57),  INT8_C(  51),  INT8_C(  88), -INT8_C(  66),  INT8_C(  91), -INT8_C(  42),
         INT8_C(  11), -INT8_C( 101), -INT8_C(  82), -INT8_C(  90),  INT8_C( 102),  INT8_C(  43), -INT8_C(  49),  INT8_C( 126),
        -INT8_C(  30), -INT8_C(  43),  INT8_C(  78),  INT8_C(  67),  INT8_C(  76), -INT8_C( 125), -INT8_C( 100),  INT8_C( 102),
        -INT8_C( 121), -INT8_C(  79), -INT8_C(  25), -INT8_C(  48), -INT8_C( 101),  INT8_C(  99),  INT8_C(  30), -INT8_C( 115) },
      { -INT8_C(  35),  INT8_C( 122), -INT8_C(  57),  INT8_C(  54),  INT8_C(  88), -INT8_C(  66),  INT8_C(  12), -INT8_C(  81),
        -INT8_C(  73), -INT8_C( 101), -INT8_C(  82), -INT8_C(  90),  INT8_C( 102),  INT8_C(  43), -INT8_C( 100),  INT8_C( 126),
        -INT8_C(  30), -INT8_C(  22),  INT8_C(  78),  INT8_C(  70),  INT8_C(  76), -INT8_C( 125), -INT8_C( 100),  INT8_C( 102),
        -INT8_C( 121), -INT8_C(  79), -INT8_C(  59), -INT8_C(  12), -INT8_C( 101), -INT8_C(  29), -INT8_C( 127), -INT8_C( 115) },
      UINT32_C(  41200128) },
    { UINT32_C( 337319517),
      { -INT8_C(  48),  INT8_C( 113),  INT8_C(  49), -INT8_C(  74), -INT8_C( 107), -INT8_C(  51),  INT8_C( 125), -INT8_C( 113),
        -INT8_C(  72), -INT8_C( 120), -INT8_C(  43),  INT8_C(  37),  INT8_C(  47), -INT8_C( 126),  INT8_C(  26), -INT8_C( 121),
         INT8_C(  21), -INT8_C(  33),  INT8_C( 123),  INT8_C(  12), -INT8_C(  62), -INT8_C(   4), -INT8_C(  32), -INT8_C( 117),
         INT8_C(  62), -INT8_C(  22), -INT8_C(   8), -INT8_C( 101),  INT8_C(   0),  INT8_C(  19), -INT8_C(  81), -INT8_C(  48) },
      { -INT8_C( 124), -INT8_C(  32),  INT8_C(  49), -INT8_C(  74), -INT8_C( 107),  INT8_C(   4),  INT8_C( 125), -INT8_C( 113),
        -INT8_C( 116),      INT8_MAX, -INT8_C(  43),  INT8_C(  37),  INT8_C(  47), -INT8_C( 126),  INT8_C(  66), -INT8_C( 121),
         INT8_C(  21), -INT8_C(  33),  INT8_C(  34),  INT8_C(  71), -INT8_C(  70),  INT8_C(   2), -INT8_C(  46), -INT8_C( 117),
        -INT8_C(  20), -INT8_C(  22), -INT8_C(   8), -INT8_C( 101), -INT8_C(  34),  INT8_C(  19), -INT8_C(  67),  INT8_C(  98) },
      UINT32_C(  67310684) },
    { UINT32_C(3543606855),
      { -INT8_C(  91), -INT8_C(  62), -INT8_C( 114), -INT8_C(  90),  INT8_C( 104), -INT8_C(  47), -INT8_C(  68), -INT8_C(  20),
        -INT8_C( 113), -INT8_C(  33),  INT8_C(  51),  INT8_C(  73), -INT8_C(  31),  INT8_C(   6),  INT8_C(  66), -INT8_C(  50),
        -INT8_C(  48), -INT8_C(  43), -INT8_C(  70), -INT8_C(  82),  INT8_C(  24),  INT8_C( 119),  INT8_C(  17),  INT8_C(  59),
        -INT8_C(  69), -INT8_C( 115),  INT8_C(  12),  INT8_C(   2), -INT8_C(  77),  INT8_C(  67), -INT8_C(  42),  INT8_C(  88) },
      {  INT8_C(   5),  INT8_C( 100), -INT8_C( 114), -INT8_C(  90),  INT8_C(  53), -INT8_C(  69),  INT8_C(  90), -INT8_C(  20),
        -INT8_C( 102), -INT8_C( 115),  INT8_C(  51),  INT8_C( 123), -INT8_C( 109),  INT8_C(  80),  INT8_C(  66),  INT8_C( 100),
        -INT8_C(  48),  INT8_C(   4), -INT8_C(  70),  INT8_C(  61),  INT8_C( 123),  INT8_C(  35),  INT8_C(  17),  INT8_C(  59),
        -INT8_C(  79), -INT8_C( 115),  INT8_C(  12),  INT8_C( 100), -INT8_C(  77),  INT8_C(  15), -INT8_C(  42), -INT8_C(  51) },
      UINT32_C(1376060420) },
    { UINT32_C( 275616886),
      {  INT8_C(  34),  INT8_C( 123), -INT8_C( 116), -INT8_C(  75), -INT8_C(  53), -INT8_C(  43),  INT8_C(  25), -INT8_C(  15),
        -INT8_C(  39),  INT8_C(  44),  INT8_C(  46),  INT8_C(  85),  INT8_C(  79), -INT8_C(  89), -INT8_C( 117),  INT8_C(   0),
         INT8_C(  43), -INT8_C(  60),  INT8_C( 101), -INT8_C(  13), -INT8_C(  45),  INT8_C(  34), -INT8_C(  64),  INT8_C(  71),
        -INT8_C(  35), -INT8_C(   6), -INT8_C(  16),  INT8_C(  84), -INT8_C( 113),  INT8_C(  93),  INT8_C( 100), -INT8_C(  79) },
      { -INT8_C(  39),  INT8_C( 123), -INT8_C( 116), -INT8_C(  92), -INT8_C(  53), -INT8_C(  43),  INT8_C(  25), -INT8_C(  15),
        -INT8_C(  39), -INT8_C(  60),  INT8_C(  46), -INT8_C(   5),  INT8_C(  79),      INT8_MIN, -INT8_C(   4), -INT8_C( 106),
         INT8_C(  43),  INT8_C(  97),  INT8_C( 101),  INT8_C(  24), -INT8_C(  45),  INT8_C(  73), -INT8_C(  64),  INT8_C(  71),
         INT8_C(  68),  INT8_C(  79), -INT8_C(  76), -INT8_C(  45), -INT8_C( 113),  INT8_C(  93), -INT8_C( 124), -INT8_C( 123) },
      UINT32_C( 272962678) },
    { UINT32_C( 376422250),
      { -INT8_C( 125),  INT8_C(  99),  INT8_C(  18), -INT8_C(  18), -INT8_C(  29),  INT8_C(  14), -INT8_C( 123),  INT8_C(  40),
         INT8_C( 111),  INT8_C(  14),  INT8_C(  64), -INT8_C(  14),  INT8_C(  88), -INT8_C(  97),  INT8_C(  82), -INT8_C( 100),
        -INT8_C(  18),  INT8_C(   7),  INT8_C( 111), -INT8_C( 102),  INT8_C(  32), -INT8_C(  13),  INT8_C(  32),  INT8_C(  41),
        -INT8_C(  35),  INT8_C(  74), -INT8_C(   7),  INT8_C(  72),  INT8_C(   9),  INT8_C( 104),  INT8_C(  94), -INT8_C( 115) },
      { -INT8_C(  53),  INT8_C(  99),  INT8_C(  18), -INT8_C(  81),  INT8_C( 126),  INT8_C(  14), -INT8_C(  41),  INT8_C(  40),
         INT8_C( 111),  INT8_C(  23),  INT8_C(  64),  INT8_C( 103), -INT8_C(  74),  INT8_C(  50),  INT8_C(  82), -INT8_C(  92),
        -INT8_C(  18),  INT8_C( 114),  INT8_C(  62),  INT8_C(  89),  INT8_C( 101), -INT8_C(  13), -INT8_C( 126),  INT8_C(  41),
        -INT8_C(  35),  INT8_C(  74), -INT8_C(   7), -INT8_C(  78), -INT8_C(  29),  INT8_C( 104),  INT8_C(  63), -INT8_C(  81) },
      UINT32_C( 102827298) },
    { UINT32_C(3401921979),
      {  INT8_C(  76), -INT8_C(  91),  INT8_C(  49),  INT8_C(   2), -INT8_C(  41),  INT8_C(  52), -INT8_C(  90),  INT8_C(  16),
        -INT8_C(  90), -INT8_C(  28),  INT8_C( 105),  INT8_C(  11),  INT8_C(  67), -INT8_C(  21),  INT8_C(  77), -INT8_C(  21),
         INT8_C( 103), -INT8_C(  40), -INT8_C(  99),  INT8_C(  74), -INT8_C(  63), -INT8_C(  36), -INT8_C(   7),  INT8_C(  26),
        -INT8_C( 105),  INT8_C(  87), -INT8_C(  14),  INT8_C(  82), -INT8_C( 116), -INT8_C(  72),  INT8_C(  28), -INT8_C(  40) },
      {  INT8_C(  93),  INT8_C(  77), -INT8_C(  38),  INT8_C(  52), -INT8_C( 127),  INT8_C(  52),  INT8_C(  68),  INT8_C(  16),
        -INT8_C(  90), -INT8_C(  83),  INT8_C( 105), -INT8_C(  88), -INT8_C( 104), -INT8_C(  21), -INT8_C( 109), -INT8_C(   1),
         INT8_C( 103),  INT8_C(  49),  INT8_C(  74),  INT8_C(  24), -INT8_C(  63),  INT8_C(  67),  INT8_C(  51),  INT8_C(  26),
        -INT8_C( 105),  INT8_C(  87), -INT8_C(  14),  INT8_C(  82), -INT8_C( 116),  INT8_C(  18),  INT8_C(   0),  INT8_C(  58) },
      UINT32_C( 176235936) },
    { UINT32_C(3221729883),
      {  INT8_C(  95),  INT8_C(  57),  INT8_C( 104), -INT8_C(   8), -INT8_C(  71), -INT8_C(   5), -INT8_C(   9),  INT8_C(  16),
         INT8_C(  44),  INT8_C(  65),  INT8_C(  41),  INT8_C(  58), -INT8_C( 123),  INT8_C(  92), -INT8_C(  34),  INT8_C(  32),
        -INT8_C( 127), -INT8_C(  43),  INT8_C(  71),  INT8_C(  95), -INT8_C(  25),  INT8_C(  71), -INT8_C( 103),  INT8_C(  71),
         INT8_C(  34),  INT8_C(   8),  INT8_C(  39),  INT8_C( 125), -INT8_C(  70),  INT8_C(  47),  INT8_C(  61),  INT8_C(  26) },
      {  INT8_C(  95),  INT8_C(  57),  INT8_C( 104), -INT8_C(   8), -INT8_C(  71), -INT8_C(   5), -INT8_C(   9),  INT8_C(  16),
         INT8_C(  75),  INT8_C(  91),  INT8_C(   7), -INT8_C(  48), -INT8_C(  73),  INT8_C(  92), -INT8_C(  34),  INT8_C(  32),
        -INT8_C(  70), -INT8_C(  43),  INT8_C(  71), -INT8_C(  94), -INT8_C(  25),  INT8_C(  71), -INT8_C(  23), -INT8_C(  95),
         INT8_C(  34),  INT8_C(   8),  INT8_C(  39),  INT8_C( 125), -INT8_C(  70),  INT8_C(  91),  INT8_C(  61), -INT8_C(  88) },
      UINT32_C(1074176091) },
    { UINT32_C(1953364777),
      {  INT8_C(  86),  INT8_C( 116),  INT8_C(  68),  INT8_C(  13),  INT8_C(  90),  INT8_C(  52),  INT8_C(  70),  INT8_C(  20),
         INT8_C( 107), -INT8_C(  35), -INT8_C(  74), -INT8_C(  22),  INT8_C(  14), -INT8_C(  97), -INT8_C( 117),  INT8_C(  71),
        -INT8_C(  80), -INT8_C(  87),  INT8_C(  59), -INT8_C(  17),  INT8_C(   4),  INT8_C(  72), -INT8_C( 105),  INT8_C(   4),
         INT8_C( 104),  INT8_C(  97), -INT8_C(  91), -INT8_C( 111),  INT8_C(  92),  INT8_C(  18),  INT8_C(   5), -INT8_C(  77) },
      {  INT8_C(  86),  INT8_C( 116), -INT8_C(  64),  INT8_C(  13),  INT8_C(  90),  INT8_C(  52),  INT8_C(  70),  INT8_C(  20),
        -INT8_C(  28), -INT8_C(  84), -INT8_C(  74), -INT8_C(  22),  INT8_C(  75),  INT8_C(  94), -INT8_C( 117), -INT8_C(   5),
        -INT8_C(  80), -INT8_C(  87),  INT8_C(  59), -INT8_C(  17), -INT8_C(  67), -INT8_C( 126), -INT8_C( 105),  INT8_C(   4),
        -INT8_C(  29),  INT8_C(  97), -INT8_C(  91), -INT8_C( 111),  INT8_C(  92),  INT8_C(  18),  INT8_C(   5),  INT8_C(  79) },
      UINT32_C(1951221801) },
 };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i a = simde_mm256_loadu_epi8(test_vec[i].a);
    simde__m256i b = simde_mm256_loadu_epi8(test_vec[i].b);
    simde__mmask32 r = simde_mm256_mask_cmpeq_epi8_mask(test_vec[i].k1, a, b);
    simde_assert_equal_mmask32(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask32 k1 = simde_test_x86_random_mmask32();
    simde__m256i a = simde_test_x86_random_i8x32();
    simde__m256i b = simde_mm256_mask_blend_epi8(simde_test_x86_random_mmask32(), a, simde_test_x86_random_i8x32());
    simde__mmask32 r = simde_mm256_mask_cmpeq_epi8_mask(k1, a, b);

    simde_test_x86_write_mmask32(2, k1, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i8x32(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i8x32(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_cmpeq_epi8_mask(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m512i   a;
    simde__m512i   b;
    simde__mmask64 r;
  } test_vec[8] = {
    { simde_mm512_set_epi8(INT8_C(  73), INT8_C(  68), INT8_C( -71), INT8_C( -32),
                           INT8_C( 100), INT8_C( 125), INT8_C(  89), INT8_C(  95),
                           INT8_C( -23), INT8_C(  76), INT8_C(  84), INT8_C( -43),
                           INT8_C(  86), INT8_C(  29), INT8_C(  64), INT8_C(  30),
                           INT8_C( -17), INT8_C( -61), INT8_C( 115), INT8_C( -53),
                           INT8_C(-100), INT8_C( 104), INT8_C( 111), INT8_C( -59),
                           INT8_C( -31), INT8_C(  20), INT8_C(  31), INT8_C(-121),
                           INT8_C(  90), INT8_C(  18), INT8_C(   6), INT8_C(  39),
                           INT8_C(  15), INT8_C(  62), INT8_C(  39), INT8_C( -25),
                           INT8_C(  60), INT8_C( 110), INT8_C(  45), INT8_C( 113),
                           INT8_C(  81), INT8_C(  78), INT8_C( -53), INT8_C(  11),
                           INT8_C( -27), INT8_C(-113), INT8_C(  -3), INT8_C(  14),
                           INT8_C( 109), INT8_C(  43), INT8_C( -54), INT8_C( 111),
                           INT8_C( -91), INT8_C( -21), INT8_C( 102), INT8_C(   8),
                           INT8_C( -41), INT8_C( -47), INT8_C( -90), INT8_C(   3),
                           INT8_C(  18), INT8_C(  32), INT8_C(  89), INT8_C( -62)),
      simde_mm512_set_epi8(INT8_C(  73), INT8_C(  68), INT8_C( -71), INT8_C( -46),
                           INT8_C(  72), INT8_C(  42), INT8_C(  65), INT8_C( -27),
                           INT8_C( -37), INT8_C(  76), INT8_C(  84), INT8_C( -95),
                           INT8_C( -29), INT8_C(  29), INT8_C(  64), INT8_C(  75),
                           INT8_C( -17), INT8_C( -61), INT8_C(  76), INT8_C(  88),
                           INT8_C(-100), INT8_C( -91), INT8_C( 111), INT8_C( -59),
                           INT8_C( -31), INT8_C( -17), INT8_C(  31), INT8_C(  68),
                           INT8_C(  90), INT8_C(  18), INT8_C(-110), INT8_C(  39),
                           INT8_C(  15), INT8_C(  62), INT8_C(  24), INT8_C( -25),
                           INT8_C(  80), INT8_C( 122), INT8_C( 103), INT8_C(-115),
                           INT8_C(  81), INT8_C(  24), INT8_C(  32), INT8_C(  82),
                           INT8_C( -27), INT8_C( 105), INT8_C(  -3), INT8_C(  14),
                           INT8_C( 109), INT8_C(  43), INT8_C( -54), INT8_C(-121),
                           INT8_C( -91), INT8_C(-124), INT8_C( 102), INT8_C(  46),
                           INT8_C( -41), INT8_C( 101), INT8_C(  51), INT8_C(   3),
                           INT8_C(  18), INT8_C(  32), INT8_C( -12), INT8_C( -62)),
      UINT64_C(0xe066cbadd08bea9d) },
    { simde_mm512_set_epi8(INT8_C( -84), INT8_C(-108), INT8_C(  13), INT8_C( -97),
                           INT8_C( -34), INT8_C(  27), INT8_C( 124), INT8_C(-120),
                           INT8_C(   3), INT8_C(  26), INT8_C(  43), INT8_C( -96),
                           INT8_C( -63), INT8_C(  49), INT8_C( 127), INT8_C(   0),
                           INT8_C( -20), INT8_C( -31), INT8_C( 125), INT8_C(  14),
                           INT8_C( -53), INT8_C( -87), INT8_C( 115), INT8_C( -20),
                           INT8_C( -93), INT8_C(  70), INT8_C(  29), INT8_C( -90),
                           INT8_C( 105), INT8_C( -54), INT8_C(  96), INT8_C(-106),
                           INT8_C(  94), INT8_C( -52), INT8_C( -50), INT8_C( -79),
                           INT8_C( -54), INT8_C(  78), INT8_C(  17), INT8_C(  81),
                           INT8_C(  35), INT8_C( 120), INT8_C(  47), INT8_C( -25),
                           INT8_C( 110), INT8_C(  55), INT8_C(  40), INT8_C( -31),
                           INT8_C(  93), INT8_C( -23), INT8_C(   4), INT8_C(  45),
                           INT8_C(  59), INT8_C( -33), INT8_C( 124), INT8_C( -52),
                           INT8_C(  42), INT8_C( -14), INT8_C(-119), INT8_C(  88),
                           INT8_C( -38), INT8_C( -31), INT8_C(-113), INT8_C(  33)),
      simde_mm512_set_epi8(INT8_C(  25), INT8_C(-108), INT8_C(  13), INT8_C( -97),
                           INT8_C( -34), INT8_C( 119), INT8_C( 122), INT8_C(  82),
                           INT8_C(   3), INT8_C(-111), INT8_C(  60), INT8_C( -96),
                           INT8_C(  26), INT8_C(   3), INT8_C(  -7), INT8_C(  -8),
                           INT8_C(  94), INT8_C( -31), INT8_C( -71), INT8_C(  14),
                           INT8_C(-105), INT8_C( -87), INT8_C( 115), INT8_C( -68),
                           INT8_C( -93), INT8_C(  70), INT8_C( -47), INT8_C(-106),
                           INT8_C( 105), INT8_C( -54), INT8_C(  96), INT8_C( 105),
                           INT8_C(  94), INT8_C(  84), INT8_C( -50), INT8_C( -79),
                           INT8_C( -54), INT8_C(  78), INT8_C(  17), INT8_C(  39),
                           INT8_C(  35), INT8_C( -87), INT8_C( -83), INT8_C( -25),
                           INT8_C( 110), INT8_C(   2), INT8_C( -90), INT8_C( -31),
                           INT8_C(  19), INT8_C( -23), INT8_C(   4), INT8_C(  16),
                           INT8_C(  59), INT8_C( -33), INT8_C( 124), INT8_C( 127),
                           INT8_C( -60), INT8_C( -14), INT8_C(-119), INT8_C(  88),
                           INT8_C( -38), INT8_C( 109), INT8_C(-113), INT8_C(  25)),
      UINT64_C(0x789056cebe996e7a) },
    { simde_mm512_set_epi8(INT8_C(  93), INT8_C( 110), INT8_C( 120), INT8_C(  25),
                           INT8_C( -37), INT8_C( -25), INT8_C( -34), INT8_C(-108),
                           INT8_C( -77), INT8_C(-114), INT8_C(  79), INT8_C( -50),
                           INT8_C( -94), INT8_C(  22), INT8_C( -28), INT8_C(-105),
                           INT8_C( 110), INT8_C(  29), INT8_C(  -9), INT8_C( -13),
                           INT8_C( -71), INT8_C( 107), INT8_C(-115), INT8_C(  86),
                           INT8_C(-127), INT8_C(-100), INT8_C(   1), INT8_C(  21),
                           INT8_C( -55), INT8_C( -85), INT8_C( -55), INT8_C( -81),
                           INT8_C( -41), INT8_C(  39), INT8_C(  18), INT8_C( -92),
                           INT8_C(  11), INT8_C( -32), INT8_C( -53), INT8_C(  38),
                           INT8_C( -49), INT8_C(-118), INT8_C(  20), INT8_C(  66),
                           INT8_C(-106), INT8_C(-109), INT8_C(  45), INT8_C( -24),
                           INT8_C( -47), INT8_C(  95), INT8_C(  50), INT8_C( 105),
                           INT8_C(  58), INT8_C(  25), INT8_C( -53), INT8_C( -61),
                           INT8_C( -90), INT8_C(  92), INT8_C(  83), INT8_C( 120),
                           INT8_C( 107), INT8_C( -72), INT8_C(   3), INT8_C(  -1)),
      simde_mm512_set_epi8(INT8_C(  93), INT8_C( 110), INT8_C( 120), INT8_C( -75),
                           INT8_C( -37), INT8_C( -25), INT8_C(  14), INT8_C(-108),
                           INT8_C(   5), INT8_C(-114), INT8_C(  79), INT8_C(  57),
                           INT8_C( -94), INT8_C(  22), INT8_C(   4), INT8_C(   3),
                           INT8_C(  66), INT8_C(  29), INT8_C(  -9), INT8_C(  20),
                           INT8_C(  93), INT8_C( 107), INT8_C(   6), INT8_C(  86),
                           INT8_C(  84), INT8_C(-100), INT8_C(  81), INT8_C(  21),
                           INT8_C( 117), INT8_C(  22), INT8_C( -55), INT8_C( -81),
                           INT8_C( -41), INT8_C( -17), INT8_C(  19), INT8_C( 106),
                           INT8_C( 114), INT8_C( -32), INT8_C(  98), INT8_C( -16),
                           INT8_C( -49), INT8_C(-118), INT8_C(  20), INT8_C(  66),
                           INT8_C(-106), INT8_C(-109), INT8_C(  97), INT8_C(  29),
                           INT8_C( -47), INT8_C( -47), INT8_C(  50), INT8_C(-111),
                           INT8_C(  58), INT8_C( 115), INT8_C( -53), INT8_C(  93),
                           INT8_C( -90), INT8_C( -27), INT8_C(  41), INT8_C( 120),
                           INT8_C( 119), INT8_C(  86), INT8_C( -36), INT8_C(  -1)),
      UINT64_C(0xed6c655384fcaa91) },
    { simde_mm512_set_epi8(INT8_C(  10), INT8_C(  75), INT8_C(  91), INT8_C( -99),
                           INT8_C( -88), INT8_C(  99), INT8_C( -86), INT8_C(  96),
                           INT8_C(  14), INT8_C(  -1), INT8_C(  14), INT8_C( 100),
                           INT8_C(-114), INT8_C(  63), INT8_C(  68), INT8_C(-113),
                           INT8_C( -59), INT8_C( -42), INT8_C( -14), INT8_C(-111),
                           INT8_C(   6), INT8_C(  68), INT8_C(  11), INT8_C(-108),
                           INT8_C( -62), INT8_C(  87), INT8_C( -72), INT8_C( -23),
                           INT8_C(  78), INT8_C( -18), INT8_C( -36), INT8_C(  -6),
                           INT8_C( -68), INT8_C(-115), INT8_C( -24), INT8_C( 127),
                           INT8_C( -36), INT8_C(  21), INT8_C(  38), INT8_C(-106),
                           INT8_C(  33), INT8_C( -66), INT8_C(-121), INT8_C(  36),
                           INT8_C(  24), INT8_C(  61), INT8_C(  66), INT8_C(  20),
                           INT8_C(  63), INT8_C( -18), INT8_C(  11), INT8_C(-103),
                           INT8_C( -19), INT8_C( -42), INT8_C( -69), INT8_C(  53),
                           INT8_C( -40), INT8_C( 112), INT8_C(   8), INT8_C( -69),
                           INT8_C(-102), INT8_C(  62), INT8_C(  85), INT8_C(  62)),
      simde_mm512_set_epi8(INT8_C(  10), INT8_C(  75), INT8_C( -74), INT8_C( -47),
                           INT8_C( -88), INT8_C(  99), INT8_C( -86), INT8_C(-128),
                           INT8_C(  94), INT8_C(  -1), INT8_C(  99), INT8_C( 100),
                           INT8_C( -25), INT8_C(   7), INT8_C(  59), INT8_C(-113),
                           INT8_C( 119), INT8_C( -42), INT8_C( -14), INT8_C(  79),
                           INT8_C(   4), INT8_C(-111), INT8_C(  11), INT8_C(  80),
                           INT8_C( -78), INT8_C(  87), INT8_C( -72), INT8_C(-111),
                           INT8_C( -95), INT8_C( -18), INT8_C( -36), INT8_C( -40),
                           INT8_C( -68), INT8_C(-115), INT8_C( -24), INT8_C( -50),
                           INT8_C( -36), INT8_C(  10), INT8_C(  47), INT8_C(  62),
                           INT8_C( -15), INT8_C( -66), INT8_C(-122), INT8_C(  36),
                           INT8_C( -22), INT8_C(  61), INT8_C( -11), INT8_C(  20),
                           INT8_C(  63), INT8_C(  82), INT8_C(-113), INT8_C(-103),
                           INT8_C( -19), INT8_C( -42), INT8_C( -69), INT8_C(  53),
                           INT8_C( -40), INT8_C( 112), INT8_C(   8), INT8_C( -69),
                           INT8_C(-102), INT8_C(  23), INT8_C(  85), INT8_C(  62)),
      UINT64_C(0xce516266e8559ffb) },
    { simde_mm512_set_epi8(INT8_C(  -7), INT8_C(   2), INT8_C(-111), INT8_C(  64),
                           INT8_C(-100), INT8_C(  87), INT8_C( 100), INT8_C( -30),
                           INT8_C( -39), INT8_C( -38), INT8_C( 121), INT8_C(  55),
                           INT8_C( -64), INT8_C(  81), INT8_C(  -3), INT8_C(  79),
                           INT8_C( -41), INT8_C( 118), INT8_C( -37), INT8_C( -34),
                           INT8_C( -13), INT8_C(  63), INT8_C(  26), INT8_C( -81),
                           INT8_C(  90), INT8_C(  43), INT8_C( -31), INT8_C( -17),
                           INT8_C(-100), INT8_C( -71), INT8_C(-104), INT8_C( -66),
                           INT8_C( -94), INT8_C( -89), INT8_C( 100), INT8_C(  36),
                           INT8_C(  17), INT8_C( 116), INT8_C( -30), INT8_C(  16),
                           INT8_C( 110), INT8_C(  98), INT8_C(  11), INT8_C( -42),
                           INT8_C( -78), INT8_C( -68), INT8_C( -26), INT8_C( -35),
                           INT8_C(  12), INT8_C( -40), INT8_C( -27), INT8_C( -40),
                           INT8_C(-102), INT8_C(-109), INT8_C(  39), INT8_C(  29),
                           INT8_C(  21), INT8_C(   9), INT8_C(  49), INT8_C( -13),
                           INT8_C( -49), INT8_C(   7), INT8_C(  91), INT8_C(  15)),
      simde_mm512_set_epi8(INT8_C(  78), INT8_C(   2), INT8_C( -91), INT8_C(  64),
                           INT8_C(-100), INT8_C(  41), INT8_C( -34), INT8_C( -46),
                           INT8_C( -39), INT8_C(  31), INT8_C(  13), INT8_C(  55),
                           INT8_C( -42), INT8_C(  33), INT8_C(  -3), INT8_C(  79),
                           INT8_C( -41), INT8_C( 118), INT8_C( -37), INT8_C(  90),
                           INT8_C( -13), INT8_C(  63), INT8_C(  51), INT8_C( -81),
                           INT8_C(  90), INT8_C(  43), INT8_C( -31), INT8_C(-112),
                           INT8_C(-100), INT8_C(  41), INT8_C(-104), INT8_C( -66),
                           INT8_C( -94), INT8_C( -89), INT8_C( -85), INT8_C(-109),
                           INT8_C( 113), INT8_C( 116), INT8_C( 100), INT8_C(  16),
                           INT8_C(   5), INT8_C( -50), INT8_C( -51), INT8_C( -42),
                           INT8_C( -95), INT8_C( -68), INT8_C( -26), INT8_C( -35),
                           INT8_C( -73), INT8_C(  71), INT8_C(  65), INT8_C( -40),
                           INT8_C(-102), INT8_C(   7), INT8_C(  94), INT8_C(  29),
                           INT8_C(  65), INT8_C(   9), INT8_C(  49), INT8_C( -13),
                           INT8_C( -33), INT8_C(   7), INT8_C(-101), INT8_C(  15)),
      UINT64_C(0x5893edebc5171975) },
    { simde_mm512_set_epi8(INT8_C( -34), INT8_C( -12), INT8_C( 105), INT8_C(-124),
                           INT8_C( -33), INT8_C( -79), INT8_C(  -6), INT8_C(  54),
                           INT8_C(  81), INT8_C( -11), INT8_C(  67), INT8_C(  63),
                           INT8_C( 103), INT8_C( 119), INT8_C( -89), INT8_C(  40),
                           INT8_C(   8), INT8_C( -38), INT8_C(  71), INT8_C(  66),
                           INT8_C(-106), INT8_C( -45), INT8_C(  18), INT8_C( 100),
                           INT8_C( 122), INT8_C(  93), INT8_C( -42), INT8_C(   5),
                           INT8_C( -39), INT8_C(  37), INT8_C( -70), INT8_C(  13),
                           INT8_C(  99), INT8_C( -57), INT8_C( -88), INT8_C( -36),
                           INT8_C(-103), INT8_C(  25), INT8_C(  94), INT8_C(-107),
                           INT8_C( -32), INT8_C( -12), INT8_C( -14), INT8_C(  32),
                           INT8_C( -38), INT8_C(  10), INT8_C(  89), INT8_C( -69),
                           INT8_C(  -8), INT8_C(  69), INT8_C( -20), INT8_C(-122),
                           INT8_C( -75), INT8_C( -71), INT8_C(   3), INT8_C( 102),
                           INT8_C( 119), INT8_C( -58), INT8_C( -49), INT8_C(  80),
                           INT8_C( -15), INT8_C( -97), INT8_C(  45), INT8_C(  96)),
      simde_mm512_set_epi8(INT8_C( -34), INT8_C( -12), INT8_C(  81), INT8_C(-115),
                           INT8_C( -33), INT8_C( -79), INT8_C(-117), INT8_C( -34),
                           INT8_C(  81), INT8_C( -11), INT8_C( -63), INT8_C( -61),
                           INT8_C(  53), INT8_C( 119), INT8_C(  26), INT8_C(  40),
                           INT8_C(   8), INT8_C( -38), INT8_C(  25), INT8_C( -23),
                           INT8_C( -16), INT8_C( -45), INT8_C( -64), INT8_C( 100),
                           INT8_C(  91), INT8_C(  93), INT8_C( -42), INT8_C(   5),
                           INT8_C(  81), INT8_C( -76), INT8_C( -70), INT8_C(  13),
                           INT8_C(  26), INT8_C( -57), INT8_C( -88), INT8_C( -64),
                           INT8_C( -68), INT8_C( -91), INT8_C(-123), INT8_C(  38),
                           INT8_C( -32), INT8_C(  29), INT8_C(  82), INT8_C(  54),
                           INT8_C(-107), INT8_C(  10), INT8_C(  89), INT8_C(  28),
                           INT8_C( -27), INT8_C(  41), INT8_C( -20), INT8_C(-122),
                           INT8_C( -75), INT8_C( -71), INT8_C(   3), INT8_C( -30),
                           INT8_C(  97), INT8_C(  18), INT8_C( -90), INT8_C( 107),
                           INT8_C(  99), INT8_C(  10), INT8_C(  45), INT8_C(  96)),
      UINT64_C(0xccc5c57360863e03) },
    { simde_mm512_set_epi8(INT8_C(  48), INT8_C(  94), INT8_C( 112), INT8_C(-107),
                           INT8_C( -34), INT8_C( -86), INT8_C(  65), INT8_C(  92),
                           INT8_C(  97), INT8_C( -99), INT8_C(  28), INT8_C(  47),
                           INT8_C(-117), INT8_C( -22), INT8_C(-111), INT8_C( -67),
                           INT8_C( 113), INT8_C(-107), INT8_C( -23), INT8_C(  77),
                           INT8_C(  60), INT8_C( 104), INT8_C(-116), INT8_C( -86),
                           INT8_C(-113), INT8_C( -79), INT8_C( -64), INT8_C( -15),
                           INT8_C(-123), INT8_C(  99), INT8_C(  25), INT8_C(  27),
                           INT8_C( -40), INT8_C( 126), INT8_C( -66), INT8_C( -45),
                           INT8_C(  57), INT8_C( -30), INT8_C( -12), INT8_C(  16),
                           INT8_C( 122), INT8_C( 124), INT8_C( -75), INT8_C(  50),
                           INT8_C(  -6), INT8_C(  41), INT8_C( -47), INT8_C(  -3),
                           INT8_C(  29), INT8_C( -20), INT8_C( -45), INT8_C( -46),
                           INT8_C( -45), INT8_C( -14), INT8_C(  99), INT8_C(  84),
                           INT8_C( -62), INT8_C( -99), INT8_C(-104), INT8_C( -78),
                           INT8_C( 106), INT8_C(-117), INT8_C( -94), INT8_C(   3)),
      simde_mm512_set_epi8(INT8_C( -88), INT8_C( -74), INT8_C(   2), INT8_C( -83),
                           INT8_C(-112), INT8_C( -91), INT8_C(  65), INT8_C(  92),
                           INT8_C(  97), INT8_C(  52), INT8_C(  28), INT8_C( -65),
                           INT8_C(-117), INT8_C( -90), INT8_C(-111), INT8_C( -67),
                           INT8_C( 113), INT8_C(  16), INT8_C(-124), INT8_C(  77),
                           INT8_C(  60), INT8_C( -64), INT8_C(-116), INT8_C( -89),
                           INT8_C(  -7), INT8_C( -79), INT8_C(  46), INT8_C( 114),
                           INT8_C(-107), INT8_C(  99), INT8_C( -79), INT8_C(  80),
                           INT8_C( -40), INT8_C( -81), INT8_C( -66), INT8_C( -45),
                           INT8_C(  57), INT8_C( -30), INT8_C(  66), INT8_C(  71),
                           INT8_C( 122), INT8_C(  95), INT8_C( -43), INT8_C(  50),
                           INT8_C(  -6), INT8_C(  41), INT8_C( -47), INT8_C(  95),
                           INT8_C(   5), INT8_C( -20), INT8_C( -45), INT8_C(-118),
                           INT8_C(  70), INT8_C(  81), INT8_C(   0), INT8_C(  84),
                           INT8_C( -62), INT8_C(-101), INT8_C(  13), INT8_C(  33),
                           INT8_C(-104), INT8_C(-117), INT8_C( -11), INT8_C(  20)),
      UINT64_C(0x3ab9a44bc9e6184) },
    { simde_mm512_set_epi8(INT8_C(  67), INT8_C(  34), INT8_C( -33), INT8_C(  31),
                           INT8_C(-128), INT8_C(  55), INT8_C(  93), INT8_C(  58),
                           INT8_C(  57), INT8_C( 104), INT8_C(-110), INT8_C(  59),
                           INT8_C(  55), INT8_C(  33), INT8_C(-122), INT8_C(  69),
                           INT8_C(  57), INT8_C(  30), INT8_C( -13), INT8_C( -65),
                           INT8_C( -22), INT8_C(-100), INT8_C(  18), INT8_C( -65),
                           INT8_C( -60), INT8_C(-105), INT8_C(  27), INT8_C( -71),
                           INT8_C(  52), INT8_C(  12), INT8_C(  -4), INT8_C(  64),
                           INT8_C(  20), INT8_C(  51), INT8_C(  87), INT8_C(  43),
                           INT8_C(  26), INT8_C(   6), INT8_C( -66), INT8_C( -40),
                           INT8_C(  87), INT8_C(   1), INT8_C( -26), INT8_C(  92),
                           INT8_C( -33), INT8_C(   8), INT8_C(  42), INT8_C( -93),
                           INT8_C(  44), INT8_C( -55), INT8_C(-113), INT8_C( -43),
                           INT8_C(  32), INT8_C( 105), INT8_C( -27), INT8_C(  96),
                           INT8_C(  72), INT8_C(  48), INT8_C( -46), INT8_C(  24),
                           INT8_C( -10), INT8_C( -98), INT8_C( -56), INT8_C( -41)),
      simde_mm512_set_epi8(INT8_C(  67), INT8_C( -63), INT8_C( -33), INT8_C(  31),
                           INT8_C(-128), INT8_C(  55), INT8_C(  93), INT8_C(  -8),
                           INT8_C(  82), INT8_C( 104), INT8_C(-110), INT8_C(  59),
                           INT8_C(  55), INT8_C(   0), INT8_C( -25), INT8_C(  69),
                           INT8_C(  27), INT8_C(  30), INT8_C( -13), INT8_C( -65),
                           INT8_C(  -7), INT8_C( -28), INT8_C(  18), INT8_C( -65),
                           INT8_C(  67), INT8_C(  -3), INT8_C(  57), INT8_C( -68),
                           INT8_C(  52), INT8_C(  12), INT8_C(  -4), INT8_C(-128),
                           INT8_C(  20), INT8_C(  37), INT8_C(   9), INT8_C(  80),
                           INT8_C(  26), INT8_C(   6), INT8_C( -66), INT8_C(   9),
                           INT8_C( -98), INT8_C(   1), INT8_C( -26), INT8_C(  92),
                           INT8_C( -33), INT8_C(   8), INT8_C( -81), INT8_C( -93),
                           INT8_C( 116), INT8_C( -55), INT8_C(-113), INT8_C( -43),
                           INT8_C(  32), INT8_C( 105), INT8_C( -27), INT8_C(  37),
                           INT8_C(  72), INT8_C( -73), INT8_C( -19), INT8_C(  96),
                           INT8_C(  52), INT8_C( -98), INT8_C( -45), INT8_C( -41)),
      UINT64_C(0xbe79730e8e7d7e85) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__mmask64 r = simde_mm512_cmpeq_epi8_mask(test_vec[i].a, test_vec[i].b);
    simde_assert_equal_mmask64(r, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm512_mask_cmpeq_epi8_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask64 k1;
    const int8_t a[64];
    const int8_t b[64];
    const simde__mmask64 r;
  } test_vec[] = {
    { UINT64_C( 1772034261841821414),
      { -INT8_C( 110), -INT8_C(  78),  INT8_C(   8), -INT8_C( 120),  INT8_C( 115),  INT8_C( 120), -INT8_C(  38), -INT8_C(   7),
        -INT8_C(  54), -INT8_C( 105), -INT8_C(  64), -INT8_C(  98),  INT8_C(  96), -INT8_C(   6), -INT8_C(  55), -INT8_C(  25),
        -INT8_C( 106),  INT8_C( 111), -INT8_C(  25), -INT8_C(  35), -INT8_C(  99),  INT8_C(  73),  INT8_C(  96), -INT8_C( 125),
        -INT8_C( 121),  INT8_C(  72),  INT8_C(  70),  INT8_C(  77), -INT8_C(  49), -INT8_C(  35),  INT8_C( 101),  INT8_C(  97),
        -INT8_C( 113),  INT8_C( 109), -INT8_C(  23),  INT8_C(   2), -INT8_C(  26), -INT8_C(  61), -INT8_C(   4), -INT8_C(  80),
         INT8_C(  90), -INT8_C(  68),  INT8_C(  78), -INT8_C(  69), -INT8_C(  73),  INT8_C(  23), -INT8_C(  94),  INT8_C(  77),
        -INT8_C( 121), -INT8_C( 119),  INT8_C(  42),  INT8_C(  36), -INT8_C(  46), -INT8_C( 118), -INT8_C(  88),  INT8_C(  90),
        -INT8_C(  46), -INT8_C(  18), -INT8_C(  89), -INT8_C(  95), -INT8_C(  53),  INT8_C(  12),  INT8_C(   2),  INT8_C(  90) },
      { -INT8_C( 110), -INT8_C(  78),  INT8_C(  93),  INT8_C(  96),  INT8_C( 115),  INT8_C( 120),  INT8_C(  16),  INT8_C(  10),
        -INT8_C(  54), -INT8_C( 105), -INT8_C(  59), -INT8_C(  52),  INT8_C(  96),  INT8_C( 103),  INT8_C(  25), -INT8_C(  25),
        -INT8_C( 106),  INT8_C( 111), -INT8_C(  25), -INT8_C(  62), -INT8_C(  50),  INT8_C(  73),  INT8_C(  28), -INT8_C(  96),
        -INT8_C( 121),  INT8_C(  72),  INT8_C(  70),  INT8_C(  77), -INT8_C(  49),  INT8_C(  68), -INT8_C(  35),  INT8_C(  97),
         INT8_C(  48),  INT8_C(  58), -INT8_C(  86),  INT8_C(   2), -INT8_C(  26), -INT8_C(  70), -INT8_C(   4), -INT8_C(  80),
         INT8_C(  90), -INT8_C(  81),  INT8_C(  78), -INT8_C(  69), -INT8_C(  73),  INT8_C(  23), -INT8_C( 115),  INT8_C(   6),
        -INT8_C(  46), -INT8_C( 119),  INT8_C(  42), -INT8_C(  96), -INT8_C(  46), -INT8_C( 118), -INT8_C(  88),  INT8_C(  90),
        -INT8_C(  46), -INT8_C(  18), -INT8_C(  89), -INT8_C(  95), -INT8_C(  53),  INT8_C(  12), -INT8_C(  62),  INT8_C(  90) },
      UINT64_C( 1771609827792327202) },
    { UINT64_C(16180692448418233969),
      {  INT8_C(  13),  INT8_C(  85),      INT8_MIN, -INT8_C( 121),  INT8_C(  58), -INT8_C(  63), -INT8_C(  72), -INT8_C(  29),
         INT8_C(  68),  INT8_C( 109),  INT8_C(  91),  INT8_C(  12), -INT8_C(   1),  INT8_C(  30),  INT8_C(   4), -INT8_C(  53),
        -INT8_C( 118), -INT8_C(  36),  INT8_C(  43), -INT8_C(  79), -INT8_C(  98),  INT8_C(  52), -INT8_C(  14),  INT8_C(  15),
        -INT8_C(  77), -INT8_C(  62), -INT8_C( 106), -INT8_C(  64),  INT8_C(  32),  INT8_C(  35), -INT8_C(  96),  INT8_C(  46),
         INT8_C( 120),  INT8_C(  33), -INT8_C(  75), -INT8_C(  77), -INT8_C(  30),  INT8_C( 109), -INT8_C( 106),  INT8_C(  39),
        -INT8_C(  38), -INT8_C(  15),  INT8_C(  51), -INT8_C(  39),  INT8_C(  15),  INT8_C(  55), -INT8_C(  91), -INT8_C( 102),
         INT8_C(  19), -INT8_C(  48),  INT8_C(  75), -INT8_C(  79),  INT8_C(   5),  INT8_C(  61), -INT8_C(  64), -INT8_C(  72),
         INT8_C(   0),  INT8_C(  86),  INT8_C( 120),  INT8_C(  32),  INT8_C( 121),  INT8_C(  25),  INT8_C(  78), -INT8_C(  15) },
      {  INT8_C(  58),  INT8_C(   3),      INT8_MIN,  INT8_C(  28),  INT8_C( 113), -INT8_C(  63), -INT8_C(  72), -INT8_C(  29),
         INT8_C(  44),  INT8_C( 109),  INT8_C(  91),  INT8_C(  59), -INT8_C(   1), -INT8_C(  54),  INT8_C(   4), -INT8_C(  53),
        -INT8_C( 102),  INT8_C(  33),  INT8_C(  43), -INT8_C(  97), -INT8_C(  98),  INT8_C(  52),  INT8_C(  87),  INT8_C(  15),
        -INT8_C(  77), -INT8_C(  62),      INT8_MAX,  INT8_C(   0),  INT8_C(  32), -INT8_C(  51), -INT8_C(  14),  INT8_C(  35),
         INT8_C( 120),  INT8_C(  33),  INT8_C(  63),  INT8_C(  66), -INT8_C(  30), -INT8_C( 125), -INT8_C( 106), -INT8_C(   3),
        -INT8_C(   7), -INT8_C(  15),  INT8_C(  51), -INT8_C(  89),  INT8_C( 124),  INT8_C(  55),  INT8_C( 103),  INT8_C(  23),
         INT8_C(  47), -INT8_C(  48),  INT8_C(  75), -INT8_C( 115),  INT8_C(   5),  INT8_C(  14), -INT8_C(  20), -INT8_C( 110),
         INT8_C(   0),  INT8_C( 107), -INT8_C( 110),  INT8_C(  32),  INT8_C( 121), -INT8_C( 124),  INT8_C(  78),  INT8_C(   9) },
      UINT64_C( 4612818519758755424) },
    { UINT64_C( 6782337677938991499),
      { -INT8_C( 115), -INT8_C(  43), -INT8_C(  20), -INT8_C( 104), -INT8_C(  29), -INT8_C(  40),  INT8_C(  42), -INT8_C(  63),
         INT8_C(  67), -INT8_C(  68), -INT8_C( 120),  INT8_C( 123),  INT8_C(  65),  INT8_C( 114), -INT8_C( 123),  INT8_C(  92),
        -INT8_C( 100), -INT8_C(  48),  INT8_C(  72),  INT8_C(  72), -INT8_C(  87),  INT8_C(  49), -INT8_C(  18),  INT8_C(  53),
         INT8_C(  82),  INT8_C(  59),  INT8_C(  61), -INT8_C( 126), -INT8_C(  16),  INT8_C(  92), -INT8_C(  32),  INT8_C( 125),
         INT8_C(  49), -INT8_C(  52),  INT8_C(  21),  INT8_C(  21), -INT8_C(  92),  INT8_C(  63), -INT8_C(  42), -INT8_C(  25),
        -INT8_C(   4),  INT8_C(  95),  INT8_C(  99),  INT8_C(  61), -INT8_C(  47), -INT8_C(  24), -INT8_C( 103),  INT8_C( 109),
        -INT8_C(  72), -INT8_C(  31), -INT8_C(  74),  INT8_C(  98),  INT8_C(  18), -INT8_C(  92), -INT8_C( 105),  INT8_C( 100),
        -INT8_C(  32), -INT8_C(  44), -INT8_C(  26), -INT8_C(  48),  INT8_C(  48), -INT8_C(  57),  INT8_C(  77),  INT8_C(  97) },
      { -INT8_C( 109),  INT8_C(  99),  INT8_C( 118),  INT8_C(  56), -INT8_C(  94), -INT8_C(  40),  INT8_C(  42), -INT8_C(  98),
         INT8_C(  67), -INT8_C( 126), -INT8_C(  37),  INT8_C( 125),  INT8_C( 106),  INT8_C( 116), -INT8_C( 123),  INT8_C(  92),
        -INT8_C( 100), -INT8_C(  48), -INT8_C( 123),  INT8_C( 103), -INT8_C(  87),  INT8_C(  49), -INT8_C(  18),  INT8_C(  37),
         INT8_C(  82),  INT8_C(  59), -INT8_C(  11), -INT8_C( 126), -INT8_C(  16),  INT8_C(  67), -INT8_C( 127),  INT8_C(  13),
         INT8_C(  49), -INT8_C(   8),  INT8_C(  21),  INT8_C(  21), -INT8_C(  92),  INT8_C( 100), -INT8_C(  42), -INT8_C(  15),
        -INT8_C(  25), -INT8_C(  62),  INT8_C(  99),  INT8_C(  61),  INT8_C(  55),  INT8_C(  89),  INT8_C( 116),  INT8_C( 109),
        -INT8_C(   6), -INT8_C(  31), -INT8_C(  12),  INT8_C(  98),  INT8_C(  21), -INT8_C(  92),  INT8_C( 101),  INT8_C(   5),
         INT8_C( 114), -INT8_C(  44), -INT8_C(  26), -INT8_C(  20),  INT8_C(  48), -INT8_C(  57),  INT8_C(  77),  INT8_C(  68) },
      UINT64_C( 6199913028536828160) },
    { UINT64_C(10950871506499617590),
      {  INT8_C(  73), -INT8_C(  19), -INT8_C(  41),  INT8_C(  94), -INT8_C(  83),  INT8_C(  61),  INT8_C( 100),  INT8_C(  32),
        -INT8_C( 104), -INT8_C( 119),  INT8_C(  12),  INT8_C(  54),  INT8_C(  48),  INT8_C(   5),  INT8_C( 122), -INT8_C(  49),
         INT8_C(  67),  INT8_C(   6), -INT8_C(  77), -INT8_C(  27),  INT8_C( 122), -INT8_C( 120),  INT8_C( 111), -INT8_C(  80),
        -INT8_C(  52),  INT8_C(  74),  INT8_C(  29),  INT8_C( 105), -INT8_C( 103),  INT8_C(  22),  INT8_C(   0), -INT8_C(  30),
         INT8_C(   4), -INT8_C(  40),  INT8_C(  65), -INT8_C(  79),  INT8_C(  21), -INT8_C(  91), -INT8_C(  47), -INT8_C(  83),
         INT8_C(  46), -INT8_C(  35), -INT8_C(  29),  INT8_C(  95), -INT8_C(  30),  INT8_C(  93),  INT8_C(  46),  INT8_C(  37),
         INT8_C(  99), -INT8_C(  30),  INT8_C(  11), -INT8_C(  35),  INT8_C( 106),  INT8_C( 122), -INT8_C( 115),  INT8_C(  54),
        -INT8_C(  60), -INT8_C(  86), -INT8_C(  97),  INT8_C(  93), -INT8_C(  63), -INT8_C(  96),  INT8_C(  64), -INT8_C(  59) },
      {  INT8_C( 120), -INT8_C( 127), -INT8_C(  41), -INT8_C( 115), -INT8_C(  83),  INT8_C(  72),  INT8_C(  58),  INT8_C(  32),
         INT8_C(  37),  INT8_C(  29),  INT8_C(  12),  INT8_C(   8),  INT8_C(  48), -INT8_C(  30),  INT8_C(  45), -INT8_C(  49),
         INT8_C(  67),  INT8_C(   6), -INT8_C(  69),  INT8_C(  46),  INT8_C( 122),  INT8_C(  72),  INT8_C( 111), -INT8_C(  80),
        -INT8_C(  52),  INT8_C(   4),  INT8_C(  29),  INT8_C( 105), -INT8_C( 103),  INT8_C(  20),  INT8_C(   0),  INT8_C(  28),
        -INT8_C( 107), -INT8_C(  17), -INT8_C(  87), -INT8_C(  69),  INT8_C(  21), -INT8_C(  91),  INT8_C(  15), -INT8_C(  83),
         INT8_C(   0), -INT8_C(  61), -INT8_C(  29),  INT8_C( 122), -INT8_C(  91), -INT8_C( 110),  INT8_C(  46),  INT8_C(  37),
        -INT8_C(  53),  INT8_C(  19), -INT8_C( 105),  INT8_C( 125),  INT8_C(  91), -INT8_C(   4), -INT8_C(  12),  INT8_C(  78),
         INT8_C(   1), -INT8_C(  56),  INT8_C(   2), -INT8_C(  91), -INT8_C(  63), -INT8_C(  96), -INT8_C(  62), -INT8_C(  59) },
      UINT64_C(10376368928033275924) },
    { UINT64_C(13982589390078764286),
      {  INT8_C(  53), -INT8_C(  92),  INT8_C(  63), -INT8_C( 112), -INT8_C(  96),  INT8_C(  51), -INT8_C(  33), -INT8_C(  95),
        -INT8_C(   5), -INT8_C(  31),  INT8_C(  71), -INT8_C(  41),  INT8_C(  93),  INT8_C(   9),  INT8_C(  72), -INT8_C(  56),
         INT8_C( 116),  INT8_C( 116),  INT8_C( 106), -INT8_C(  61), -INT8_C(  80),  INT8_C( 106),  INT8_C(  19), -INT8_C(  82),
        -INT8_C(  50), -INT8_C(  35),  INT8_C(  82), -INT8_C(  59), -INT8_C(   1),  INT8_C(  94), -INT8_C( 121),  INT8_C(  52),
         INT8_C(   2), -INT8_C(  57), -INT8_C(  60), -INT8_C(  93), -INT8_C(   6), -INT8_C(  93),  INT8_C(  68), -INT8_C(  10),
        -INT8_C( 123), -INT8_C( 117), -INT8_C(  51), -INT8_C(  30), -INT8_C( 108),  INT8_C(  22), -INT8_C(  86),  INT8_C(   9),
        -INT8_C( 118),  INT8_C(  20), -INT8_C(  52),  INT8_C(  58),  INT8_C( 126), -INT8_C(  33), -INT8_C(  23),  INT8_C(  77),
        -INT8_C(  68),  INT8_C(  59),  INT8_C(  18), -INT8_C(  69), -INT8_C( 103), -INT8_C( 102), -INT8_C(  17), -INT8_C( 100) },
      {  INT8_C(  97), -INT8_C(  76),  INT8_C(  63),  INT8_C(  91), -INT8_C(  96), -INT8_C( 125), -INT8_C(  33), -INT8_C(  36),
         INT8_C(  15),  INT8_C(  31), -INT8_C(  66), -INT8_C(  41),  INT8_C(  93),  INT8_C( 104), -INT8_C(  84), -INT8_C(  65),
         INT8_C( 125),  INT8_C( 121),  INT8_C( 106), -INT8_C(   5), -INT8_C(  80), -INT8_C(  29),  INT8_C(  19), -INT8_C(  82),
         INT8_C(  30), -INT8_C(  35), -INT8_C(  48), -INT8_C(  59), -INT8_C(   1),  INT8_C(  94),  INT8_C(  83),  INT8_C(  86),
         INT8_C(   2), -INT8_C( 110), -INT8_C(  60), -INT8_C(  53), -INT8_C(   6),  INT8_C(   3), -INT8_C(  88),  INT8_C(  37),
         INT8_C(  34),  INT8_C( 102), -INT8_C(  51), -INT8_C(  30), -INT8_C(  49),  INT8_C(  22),  INT8_C(  22),  INT8_C(  76),
        -INT8_C( 118),  INT8_C(  16), -INT8_C(  52),  INT8_C(  70),  INT8_C( 126), -INT8_C( 112),  INT8_C(  91),  INT8_C(  17),
        -INT8_C(  68),  INT8_C(  59), -INT8_C(  55), -INT8_C(  32), -INT8_C( 103), -INT8_C( 102), -INT8_C(  17), -INT8_C( 100) },
      UINT64_C(13980334418414272596) },
    { UINT64_C( 1537269155896734266),
      { -INT8_C( 118), -INT8_C( 100),  INT8_C(  92),  INT8_C( 126),  INT8_C(  44), -INT8_C(  73), -INT8_C( 113),  INT8_C(  23),
        -INT8_C(  29),  INT8_C(  88), -INT8_C(   9), -INT8_C(  49),  INT8_C( 117),  INT8_C(  45),  INT8_C(  47),  INT8_C(  36),
         INT8_C(  21),  INT8_C(  91), -INT8_C(  23), -INT8_C(   1),  INT8_C(  46), -INT8_C(  45),  INT8_C(  12),  INT8_C( 104),
        -INT8_C( 123),  INT8_C( 111),  INT8_C( 113), -INT8_C(  83), -INT8_C(  23), -INT8_C(  58), -INT8_C(  62),  INT8_C( 116),
         INT8_C(  99),  INT8_C(  30), -INT8_C(  14), -INT8_C( 113), -INT8_C(  42), -INT8_C( 127), -INT8_C(  89), -INT8_C(  71),
        -INT8_C(  38), -INT8_C(  98), -INT8_C( 119),  INT8_C(  79), -INT8_C(  52), -INT8_C(  72),  INT8_C( 115), -INT8_C(  31),
         INT8_C(  19),  INT8_C(  92), -INT8_C(  32),  INT8_C(  66),  INT8_C(  47), -INT8_C(  20), -INT8_C(  86), -INT8_C(  76),
         INT8_C(  92),  INT8_C(  28),  INT8_C(  97),  INT8_C(  69), -INT8_C(  30),  INT8_C(  36), -INT8_C(  71),  INT8_C(  69) },
      { -INT8_C( 118), -INT8_C(  85),  INT8_C(  92),  INT8_C( 126),  INT8_C(  45), -INT8_C(  73), -INT8_C( 113),  INT8_C(   7),
         INT8_C(  26),  INT8_C(  88), -INT8_C(   9), -INT8_C(  49),  INT8_C( 117), -INT8_C(  55),  INT8_C(  47),  INT8_C(  36),
         INT8_C(  21), -INT8_C(  88),  INT8_C( 105), -INT8_C(   1),  INT8_C(  46),  INT8_C(  19),  INT8_C(  12),  INT8_C( 104),
         INT8_C(  47),  INT8_C( 106),  INT8_C( 113),  INT8_C(  18), -INT8_C( 114), -INT8_C(  17), -INT8_C(  62),  INT8_C( 116),
         INT8_C(  99),  INT8_C(  30), -INT8_C(  23), -INT8_C(  56), -INT8_C(  88), -INT8_C( 127), -INT8_C(  49), -INT8_C(  61),
         INT8_C(  22), -INT8_C(  98), -INT8_C(  87),  INT8_C(  79), -INT8_C(  18),  INT8_C( 113),  INT8_C(  80),  INT8_C(  19),
         INT8_C(  19), -INT8_C(  71),  INT8_C( 103), -INT8_C(  83), -INT8_C(  51),  INT8_C( 111), -INT8_C(  98), -INT8_C(   4),
         INT8_C(  92), -INT8_C(  44),  INT8_C(  97),  INT8_C(  69), -INT8_C(  61),  INT8_C( 102),  INT8_C(  56),  INT8_C(  94) },
      UINT64_C(  360580590610780712) },
    { UINT64_C( 3538540782700701466),
      {  INT8_C(  37), -INT8_C( 126), -INT8_C(  33), -INT8_C(  14), -INT8_C(  14),  INT8_C( 125), -INT8_C(  17), -INT8_C(  53),
         INT8_C(  81), -INT8_C(   3),  INT8_C(  51),  INT8_C(  20),  INT8_C(  99),  INT8_C( 107),  INT8_C( 115), -INT8_C(  10),
        -INT8_C( 116), -INT8_C( 103),  INT8_C(  49),  INT8_C( 104), -INT8_C( 113),  INT8_C(  47),  INT8_C(  90), -INT8_C(  87),
        -INT8_C(  42),  INT8_C( 117), -INT8_C(  78), -INT8_C(  17), -INT8_C(  31), -INT8_C(  51),  INT8_C(  32),  INT8_C(   7),
         INT8_C(  80), -INT8_C(   1), -INT8_C(   7),  INT8_C(  66),  INT8_C( 124), -INT8_C(  24),  INT8_C(  13), -INT8_C(  51),
        -INT8_C(  26),  INT8_C(  64), -INT8_C(  30),  INT8_C(  73), -INT8_C(  85),  INT8_C(  85),  INT8_C(  63),  INT8_C(  55),
        -INT8_C(  18),  INT8_C( 112), -INT8_C(  97),  INT8_C( 125), -INT8_C(  97), -INT8_C(   7),  INT8_C(  39),  INT8_C( 118),
         INT8_C( 111), -INT8_C(  39),  INT8_C( 101),  INT8_C(  80), -INT8_C(  90), -INT8_C( 123),  INT8_C(  87), -INT8_C(  10) },
      {  INT8_C(  37),  INT8_C(  81),  INT8_C(  56), -INT8_C(  14), -INT8_C(  14),  INT8_C( 125), -INT8_C(  17), -INT8_C(  53),
        -INT8_C( 122), -INT8_C(  79),  INT8_C( 105),  INT8_C(  50),  INT8_C(   6), -INT8_C(  88),  INT8_C( 115), -INT8_C(  12),
        -INT8_C( 116),  INT8_C(   9),  INT8_C( 114),  INT8_C( 104),  INT8_C(   2),  INT8_C(  47),  INT8_C(  90), -INT8_C(  87),
         INT8_C( 114), -INT8_C( 109), -INT8_C(  78), -INT8_C(  17),  INT8_C(  25), -INT8_C(  51),  INT8_C(  32), -INT8_C(  98),
         INT8_C( 106), -INT8_C(   1), -INT8_C(  97), -INT8_C(  92),  INT8_C( 124),  INT8_C( 110),  INT8_C(  13), -INT8_C(  51),
        -INT8_C(  26),  INT8_C(  44), -INT8_C(  30),  INT8_C(  37), -INT8_C(  43),  INT8_C(  85),  INT8_C(  26), -INT8_C(  18),
        -INT8_C(  72), -INT8_C( 116), -INT8_C(  90),  INT8_C( 125), -INT8_C(  97), -INT8_C(  43),  INT8_C(  39), -INT8_C( 105),
         INT8_C( 104), -INT8_C(  39), -INT8_C(  81), -INT8_C( 127), -INT8_C(  90), -INT8_C( 123),  INT8_C(  31), -INT8_C(  10) },
      UINT64_C( 3465559564534480920) },
    { UINT64_C( 6181626573162212614),
      {  INT8_C(  24),  INT8_C( 112),  INT8_C(  16),  INT8_C(  61),  INT8_C(  69),  INT8_C(  61), -INT8_C(  44), -INT8_C(  83),
         INT8_C(  43), -INT8_C( 124),  INT8_C(  47),  INT8_C(  51),  INT8_C(  66),  INT8_C(  78), -INT8_C(  90),  INT8_C(  72),
         INT8_C(  13), -INT8_C(  68), -INT8_C(  36),  INT8_C(  59), -INT8_C( 106), -INT8_C( 125), -INT8_C( 120), -INT8_C(  99),
         INT8_C( 113), -INT8_C(   6),  INT8_C( 120),  INT8_C(  14), -INT8_C( 121),  INT8_C(  66),  INT8_C(  99), -INT8_C(  97),
        -INT8_C(  78),  INT8_C( 116), -INT8_C(  35), -INT8_C(   9), -INT8_C(  79), -INT8_C(  79), -INT8_C(  92), -INT8_C(  36),
         INT8_C(  53), -INT8_C(  45),  INT8_C(  16),  INT8_C( 120),  INT8_C(  34), -INT8_C(  74), -INT8_C(  64),  INT8_C(  47),
         INT8_C( 114), -INT8_C( 100),  INT8_C( 106),  INT8_C(   9),  INT8_C(  32), -INT8_C(  14), -INT8_C(  90), -INT8_C( 111),
        -INT8_C(  19),  INT8_C(  30), -INT8_C(  97),  INT8_C( 116),  INT8_C(  96),  INT8_C(   2),  INT8_C(  19),  INT8_C(  18) },
      {  INT8_C(  24),  INT8_C( 112),  INT8_C(   9),  INT8_C(  61),  INT8_C(  69), -INT8_C(  82),  INT8_C(   4), -INT8_C(  83),
         INT8_C(  43),  INT8_C(  20),  INT8_C(  47),  INT8_C(  51), -INT8_C(  54),  INT8_C(  78), -INT8_C(  45),  INT8_C(  72),
         INT8_C(  13), -INT8_C(  68), -INT8_C(  36), -INT8_C(  52),  INT8_C(  48), -INT8_C(  21), -INT8_C( 120),  INT8_C(  29),
         INT8_C(  10), -INT8_C(   6),  INT8_C( 120),  INT8_C( 106), -INT8_C(   1),  INT8_C(  66),  INT8_C(  99),  INT8_C( 117),
        -INT8_C( 107), -INT8_C( 122), -INT8_C(  35), -INT8_C(   9),  INT8_C(  52), -INT8_C(  95),  INT8_C(  14), -INT8_C(  74),
        -INT8_C(  75),  INT8_C(  94),  INT8_C(  89),  INT8_C( 120),  INT8_C(  34), -INT8_C(  74), -INT8_C(  69),  INT8_C(  26),
         INT8_C( 106),  INT8_C(   1), -INT8_C(  25), -INT8_C( 102),  INT8_C(  32), -INT8_C(  14), -INT8_C(  73), -INT8_C( 111),
        -INT8_C(  19),  INT8_C(  30), -INT8_C(  97),  INT8_C(  64),  INT8_C(  96), -INT8_C(  34),  INT8_C(  19), -INT8_C( 127) },
      UINT64_C( 6160933138987134210) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i a = simde_mm512_loadu_epi8(test_vec[i].a);
    simde__m512i b = simde_mm512_loadu_epi8(test_vec[i].b);
    simde__mmask64 r = simde_mm512_mask_cmpeq_epi8_mask(test_vec[i].k1, a, b);
    simde_assert_equal_mmask64(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask64 k1 = simde_test_x86_random_mmask64();
    simde__m512i a = simde_test_x86_random_i8x64();
    simde__m512i b = simde_mm512_mask_blend_epi8(simde_test_x86_random_mmask64(), a, simde_test_x86_random_i8x64());
    simde__mmask64 r = simde_mm512_mask_cmpeq_epi8_mask(k1, a, b);

    simde_test_x86_write_mmask64(2, k1, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i8x64(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i8x64(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask64(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_cmpeq_epi16_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int16_t a[8];
    const int16_t b[8];
    const simde__mmask8 r;
  } test_vec[] = {
    { {  INT16_C( 15083),  INT16_C(  3421),  INT16_C( 19747),  INT16_C( 17967),  INT16_C(  6157), -INT16_C( 20712),  INT16_C( 14419),  INT16_C(  5325) },
      {  INT16_C( 17533),  INT16_C(  3421),  INT16_C( 19747),  INT16_C( 17967), -INT16_C(  3049), -INT16_C( 20712), -INT16_C( 26663), -INT16_C( 15156) },
      UINT8_C( 46) },
    { { -INT16_C( 11991),  INT16_C( 30708),  INT16_C( 14848),  INT16_C(  6532),  INT16_C( 13138), -INT16_C( 30100),        INT16_MIN,  INT16_C( 17672) },
      { -INT16_C( 11991),  INT16_C( 23473),  INT16_C( 14848),  INT16_C(  6532), -INT16_C( 15590), -INT16_C( 30100),        INT16_MIN, -INT16_C( 18046) },
      UINT8_C(109) },
    { {  INT16_C( 12406), -INT16_C( 20334), -INT16_C( 21580), -INT16_C(  6398), -INT16_C( 29417), -INT16_C( 26648),  INT16_C( 11669),  INT16_C( 10134) },
      {  INT16_C( 12406), -INT16_C( 20334), -INT16_C( 21580), -INT16_C(  6398), -INT16_C( 29417),  INT16_C( 13495),  INT16_C( 11669),  INT16_C( 21446) },
      UINT8_C( 95) },
    { {  INT16_C(   857),  INT16_C(  1108),  INT16_C( 15110), -INT16_C( 27876), -INT16_C( 19677),  INT16_C( 20520),  INT16_C( 20297),  INT16_C( 15150) },
      {  INT16_C(   857),  INT16_C(  7583),  INT16_C( 15110), -INT16_C( 27876), -INT16_C( 14978), -INT16_C(  4453), -INT16_C(  4468), -INT16_C(  6770) },
      UINT8_C( 13) },
    { { -INT16_C(  5662),  INT16_C(  7672), -INT16_C( 29947), -INT16_C( 18111), -INT16_C( 28237),  INT16_C(   514),  INT16_C( 15808),  INT16_C( 31911) },
      { -INT16_C( 15139),  INT16_C(  7672), -INT16_C( 24491), -INT16_C( 18111),  INT16_C(  4156),  INT16_C( 10919), -INT16_C( 29538),  INT16_C( 31911) },
      UINT8_C(138) },
    { { -INT16_C( 25324), -INT16_C( 24709),  INT16_C( 13534),  INT16_C( 28754),  INT16_C( 21814),  INT16_C( 29744), -INT16_C( 21252), -INT16_C( 16047) },
      { -INT16_C( 25324),  INT16_C( 11798),  INT16_C( 13534),  INT16_C( 28754),  INT16_C( 21814),  INT16_C( 25797),  INT16_C( 17841), -INT16_C( 14630) },
      UINT8_C( 29) },
    { {  INT16_C( 25941), -INT16_C( 30271),  INT16_C( 12728),  INT16_C(  3519),  INT16_C( 13153),  INT16_C(  3337), -INT16_C( 13692),  INT16_C( 31131) },
      {  INT16_C( 25941),  INT16_C(  4752), -INT16_C( 18636),  INT16_C(  3519),  INT16_C( 13153), -INT16_C( 16005), -INT16_C( 13692),  INT16_C( 32420) },
      UINT8_C( 89) },
    { {  INT16_C(  1893), -INT16_C( 27042),  INT16_C( 27591), -INT16_C(  1289),  INT16_C(  1141),  INT16_C( 16255), -INT16_C(  1888),  INT16_C( 27168) },
      {  INT16_C( 13193), -INT16_C( 27042),  INT16_C( 26654),  INT16_C( 28093),  INT16_C( 32483),  INT16_C( 16255), -INT16_C(  1888),  INT16_C( 27168) },
      UINT8_C(226) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_mm_loadu_epi16(test_vec[i].a);
    simde__m128i b = simde_mm_loadu_epi16(test_vec[i].b);
    simde__mmask8 r = simde_mm_cmpeq_epi16_mask(a, b);
    simde_assert_equal_mmask8(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i a = simde_test_x86_random_i16x8();
    simde__m128i b = simde_mm_mask_blend_epi16(simde_test_x86_random_mmask8(), a, simde_test_x86_random_i16x8());
    simde__mmask8 r = simde_mm_cmpeq_epi16_mask(a, b);

    simde_test_x86_write_i16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_mask_cmpeq_epi16_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k1;
    const int16_t a[8];
    const int16_t b[8];
    const simde__mmask8 r;
  } test_vec[] = {
    { UINT8_C( 41),
      { -INT16_C(  7139),  INT16_C(  5268),  INT16_C(  2526),  INT16_C( 23833), -INT16_C( 18103),  INT16_C( 26966), -INT16_C(  8413), -INT16_C( 15972) },
      { -INT16_C( 17889),  INT16_C(  5268),  INT16_C(  3112),  INT16_C( 23833),  INT16_C( 32048),  INT16_C( 26966), -INT16_C(  3835),  INT16_C(  8740) },
      UINT8_C( 40) },
    { UINT8_C(184),
      { -INT16_C( 19401),  INT16_C( 20674),  INT16_C(  2833),  INT16_C( 26377),  INT16_C( 11380),  INT16_C(  4422),  INT16_C( 26349),  INT16_C(  6091) },
      { -INT16_C( 19401), -INT16_C( 25309),  INT16_C(  2833),  INT16_C( 26377),  INT16_C( 11380),  INT16_C(  4422),  INT16_C( 26349),  INT16_C(  6091) },
      UINT8_C(184) },
    { UINT8_C(237),
      {  INT16_C(  5065), -INT16_C( 11528),  INT16_C( 28027), -INT16_C( 15874), -INT16_C(  4994),  INT16_C( 18727),  INT16_C( 27139),  INT16_C(  9789) },
      {  INT16_C(  5065),  INT16_C(  8826),  INT16_C( 28027), -INT16_C( 15874), -INT16_C( 31428),  INT16_C( 18727),  INT16_C( 16382),  INT16_C(  9789) },
      UINT8_C(173) },
    { UINT8_C( 78),
      { -INT16_C( 12902), -INT16_C( 26181),  INT16_C( 14735), -INT16_C( 18811), -INT16_C( 30590), -INT16_C( 16608),  INT16_C( 10414),  INT16_C( 10671) },
      { -INT16_C( 12902), -INT16_C( 26181),  INT16_C( 14735), -INT16_C( 18811),  INT16_C(  4247), -INT16_C(  4976),  INT16_C( 10414),  INT16_C( 29498) },
      UINT8_C( 78) },
    { UINT8_C(245),
      {  INT16_C( 16140), -INT16_C( 28370), -INT16_C( 19978),  INT16_C(  5657), -INT16_C( 14480),  INT16_C(  7998), -INT16_C( 30224), -INT16_C(  7355) },
      {  INT16_C( 16140),  INT16_C( 10258), -INT16_C( 22101),  INT16_C( 15160), -INT16_C( 14480),  INT16_C(  7998), -INT16_C( 30224), -INT16_C(  7355) },
      UINT8_C(241) },
    { UINT8_C(244),
      {  INT16_C(  1057),  INT16_C( 15013),  INT16_C(  5403),  INT16_C( 22785), -INT16_C(  3531),  INT16_C( 31458), -INT16_C(  1835), -INT16_C(  6189) },
      {  INT16_C(  1057),  INT16_C( 22928),  INT16_C(  5403), -INT16_C( 10134), -INT16_C(  4363), -INT16_C( 17497), -INT16_C(  1835), -INT16_C( 24657) },
      UINT8_C( 68) },
    { UINT8_C( 84),
      { -INT16_C( 10791), -INT16_C(  9623), -INT16_C( 25041),  INT16_C(  4556), -INT16_C( 24296), -INT16_C(  5110),  INT16_C( 10888),  INT16_C(  6250) },
      { -INT16_C( 10791), -INT16_C(  4802), -INT16_C( 25041), -INT16_C( 23333), -INT16_C( 24296), -INT16_C( 25254),  INT16_C(  5624), -INT16_C( 11791) },
      UINT8_C( 20) },
    { UINT8_C( 91),
      {  INT16_C(  6572),  INT16_C( 30969),  INT16_C(  4651),  INT16_C( 13594), -INT16_C( 23810),  INT16_C( 26719), -INT16_C(  7237), -INT16_C(  1651) },
      {  INT16_C(  6572), -INT16_C( 21460),  INT16_C(  4651),  INT16_C( 13594), -INT16_C( 23810), -INT16_C( 21858), -INT16_C(  7237),  INT16_C( 31493) },
      UINT8_C( 89) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_mm_loadu_epi16(test_vec[i].a);
    simde__m128i b = simde_mm_loadu_epi16(test_vec[i].b);
    simde__mmask8 r = simde_mm_mask_cmpeq_epi16_mask(test_vec[i].k1, a, b);
    simde_assert_equal_mmask8(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k1 = simde_test_x86_random_mmask8();
    simde__m128i a = simde_test_x86_random_i16x8();
    simde__m128i b = simde_mm_mask_blend_epi16(simde_test_x86_random_mmask8(), a, simde_test_x86_random_i16x8());
    simde__mmask8 r = simde_mm_mask_cmpeq_epi16_mask(k1, a, b);

    simde_test_x86_write_mmask8(2, k1, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i16x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_cmpeq_epi16_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int16_t a[16];
    const int16_t b[16];
    const simde__mmask16 r;
  } test_vec[] = {
    { { -INT16_C(  2818),  INT16_C(  4301),  INT16_C(   526), -INT16_C( 20466),  INT16_C( 30561),  INT16_C( 17515),  INT16_C( 25604), -INT16_C( 29163),
        -INT16_C( 15983), -INT16_C( 21316),  INT16_C( 17862), -INT16_C( 15260),  INT16_C(  3811),  INT16_C( 27796),  INT16_C(  3859),  INT16_C(  4622) },
      { -INT16_C(  2818),  INT16_C(  4301),  INT16_C( 12765), -INT16_C( 20466),  INT16_C( 11688), -INT16_C( 21373), -INT16_C( 26478), -INT16_C( 29163),
        -INT16_C( 15983),  INT16_C(  8143),  INT16_C( 17862),  INT16_C(  8164),  INT16_C(  3811),  INT16_C( 27796),  INT16_C(  3859), -INT16_C( 29849) },
      UINT16_C(30091) },
    { {  INT16_C( 20892),  INT16_C( 24251),  INT16_C( 25488),  INT16_C(  5004),  INT16_C(  7695),  INT16_C( 18859),  INT16_C(  1089),  INT16_C(  4159),
         INT16_C( 31523),  INT16_C(  1859), -INT16_C( 31333),  INT16_C(  9855),  INT16_C(  2011),  INT16_C( 17088),  INT16_C( 13458),  INT16_C( 11980) },
      {  INT16_C( 20892),  INT16_C(  5773),  INT16_C( 25488),  INT16_C(  5004),  INT16_C(  7695),  INT16_C( 18859), -INT16_C( 32040), -INT16_C(  1144),
        -INT16_C( 13315), -INT16_C( 26621), -INT16_C( 32175),  INT16_C(  9855),  INT16_C( 32649),  INT16_C( 17088),  INT16_C( 15283),  INT16_C( 14666) },
      UINT16_C(10301) },
    { { -INT16_C( 21169),  INT16_C( 30960),  INT16_C( 10150), -INT16_C(  5812),  INT16_C(  9375),  INT16_C( 10091),  INT16_C( 26656),  INT16_C(  9202),
         INT16_C( 17153), -INT16_C( 16219),  INT16_C( 12143), -INT16_C(  8641), -INT16_C(  3510), -INT16_C( 27623), -INT16_C(  9428),  INT16_C( 31595) },
      { -INT16_C( 21169),  INT16_C( 12276),  INT16_C( 10150), -INT16_C(  5812),  INT16_C(  9375), -INT16_C( 31416),  INT16_C( 26656),  INT16_C(  9202),
         INT16_C( 19838), -INT16_C( 16219),  INT16_C( 12143), -INT16_C( 14388), -INT16_C(  6690),  INT16_C(  2651), -INT16_C( 14400),  INT16_C( 31595) },
      UINT16_C(34525) },
    { { -INT16_C( 23176), -INT16_C( 28486),  INT16_C(  8134),  INT16_C(  3859), -INT16_C(   348),  INT16_C( 19530), -INT16_C( 14101), -INT16_C( 26727),
         INT16_C(  5814), -INT16_C( 32125),  INT16_C( 25053),  INT16_C( 14439),  INT16_C( 10347), -INT16_C(  3841),  INT16_C(  8817), -INT16_C(  5782) },
      { -INT16_C( 23176), -INT16_C( 29319),  INT16_C(  8134), -INT16_C(  6244), -INT16_C(  6518),  INT16_C( 19530), -INT16_C( 13137),  INT16_C( 25869),
         INT16_C(  5814), -INT16_C( 16408),  INT16_C( 25053),  INT16_C( 23800),  INT16_C( 10347), -INT16_C(  3841), -INT16_C( 18919), -INT16_C(  5782) },
      UINT16_C(46373) },
    { {  INT16_C(  7534),  INT16_C(  2774),  INT16_C( 24836),  INT16_C( 14321), -INT16_C( 24362), -INT16_C(  7420), -INT16_C(  6651), -INT16_C(  4749),
         INT16_C( 25766), -INT16_C( 25027), -INT16_C( 19264),  INT16_C(  3477), -INT16_C( 20579),  INT16_C( 28355), -INT16_C( 24945), -INT16_C(   583) },
      { -INT16_C( 28741),  INT16_C(  2774),  INT16_C( 24836),  INT16_C( 14321), -INT16_C(  1127), -INT16_C(  7420),  INT16_C(  7906), -INT16_C( 30580),
        -INT16_C( 13950),  INT16_C( 17190), -INT16_C( 17539),  INT16_C(  6736),  INT16_C(  4970), -INT16_C(  1399),  INT16_C( 17073),  INT16_C( 28151) },
      UINT16_C(   46) },
    { { -INT16_C( 15827),  INT16_C(  9464), -INT16_C( 28279),  INT16_C( 13088),  INT16_C(   560), -INT16_C( 17327), -INT16_C( 11126), -INT16_C( 20347),
         INT16_C(   535),  INT16_C( 26475), -INT16_C( 10723), -INT16_C( 22918),  INT16_C( 11472), -INT16_C( 14360), -INT16_C( 18023), -INT16_C( 14649) },
      { -INT16_C( 15827),  INT16_C(  1258),  INT16_C(  2641),  INT16_C( 13088),  INT16_C(   560), -INT16_C( 27075), -INT16_C( 11126),  INT16_C( 29766),
        -INT16_C( 19772), -INT16_C(  7717), -INT16_C( 10723),  INT16_C( 22663),  INT16_C( 11472), -INT16_C( 14360), -INT16_C(  6615), -INT16_C( 23327) },
      UINT16_C(13401) },
    { { -INT16_C(  2135), -INT16_C(  7722), -INT16_C(  7560), -INT16_C( 19094), -INT16_C( 14215), -INT16_C( 16521),  INT16_C( 15164),  INT16_C(  6257),
        -INT16_C(  1763), -INT16_C( 23442), -INT16_C(  4015),  INT16_C( 28948),  INT16_C( 15627), -INT16_C(  5033), -INT16_C(   543), -INT16_C( 30025) },
      { -INT16_C(  2135), -INT16_C(  7722), -INT16_C( 10640), -INT16_C(  5855), -INT16_C( 14215), -INT16_C( 16521),  INT16_C( 15164), -INT16_C(  3598),
        -INT16_C(  1763),  INT16_C( 26005), -INT16_C( 22192),  INT16_C( 23510),  INT16_C( 11750), -INT16_C( 14265), -INT16_C(   543),  INT16_C(  8018) },
      UINT16_C(16755) },
    { { -INT16_C(   884), -INT16_C( 21100),  INT16_C( 13029), -INT16_C( 29114),  INT16_C(  6668), -INT16_C(    88), -INT16_C( 17653), -INT16_C( 24481),
        -INT16_C( 20448), -INT16_C(  2486),  INT16_C( 12299),  INT16_C( 21284),  INT16_C( 20472),  INT16_C( 19282), -INT16_C(  8594), -INT16_C(  1527) },
      { -INT16_C( 25125), -INT16_C( 16216), -INT16_C(  4401), -INT16_C( 29114), -INT16_C(  2552), -INT16_C(    88), -INT16_C( 17653), -INT16_C( 24481),
        -INT16_C(   534), -INT16_C(  2486), -INT16_C(  4818),  INT16_C(  9800),  INT16_C( 20472),  INT16_C( 19282),  INT16_C( 31353), -INT16_C(  1527) },
      UINT16_C(45800) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i a = simde_mm256_loadu_epi16(test_vec[i].a);
    simde__m256i b = simde_mm256_loadu_epi16(test_vec[i].b);
    simde__mmask16 r = simde_mm256_cmpeq_epi16_mask(a, b);
    simde_assert_equal_mmask16(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m256i a = simde_test_x86_random_i16x16();
    simde__m256i b = simde_mm256_mask_blend_epi16(simde_test_x86_random_mmask16(), a, simde_test_x86_random_i16x16());
    simde__mmask16 r = simde_mm256_cmpeq_epi16_mask(a, b);

    simde_test_x86_write_i16x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i16x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_mask_cmpeq_epi16_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask16 k1;
    const int16_t a[16];
    const int16_t b[16];
    const simde__mmask16 r;
  } test_vec[] = {
    { UINT16_C(33868),
      {  INT16_C( 26621),  INT16_C(     7),  INT16_C( 24757),  INT16_C( 20456),  INT16_C( 15602), -INT16_C( 32648), -INT16_C( 30761), -INT16_C( 32507),
        -INT16_C( 30537),  INT16_C(  5534),  INT16_C(  9159),  INT16_C( 16622),  INT16_C(  4300),  INT16_C( 12060),  INT16_C( 26688),  INT16_C( 15795) },
      { -INT16_C( 17713),  INT16_C(     7),  INT16_C(  9499),  INT16_C( 20456),  INT16_C( 15602),  INT16_C( 14733), -INT16_C( 27949), -INT16_C( 30022),
         INT16_C( 22555), -INT16_C(  7521), -INT16_C( 29316),  INT16_C( 16622),  INT16_C( 16029),  INT16_C( 12060),  INT16_C( 10918),  INT16_C( 15795) },
      UINT16_C(32776) },
    { UINT16_C(  250),
      { -INT16_C( 12932), -INT16_C(  8691), -INT16_C( 26087), -INT16_C(  5097), -INT16_C( 11988),  INT16_C( 18294),  INT16_C(  5418), -INT16_C( 22998),
         INT16_C( 19619),  INT16_C( 16622),  INT16_C( 26251),  INT16_C( 12574),  INT16_C( 14480),  INT16_C( 30119), -INT16_C( 24176),  INT16_C(  3189) },
      { -INT16_C( 32146), -INT16_C(  8691),  INT16_C(   284), -INT16_C(  5097), -INT16_C(  5165), -INT16_C(   624), -INT16_C( 17920), -INT16_C( 23645),
        -INT16_C( 28409),  INT16_C( 16622),  INT16_C( 26251),  INT16_C( 12574),  INT16_C( 14480),  INT16_C( 30119),  INT16_C( 29451),  INT16_C( 31447) },
      UINT16_C(   10) },
    { UINT16_C( 4610),
      {  INT16_C( 30403), -INT16_C( 27045), -INT16_C(  5279),  INT16_C( 25235),  INT16_C( 13990), -INT16_C( 21243), -INT16_C(  5689), -INT16_C( 16577),
         INT16_C(   747),  INT16_C(  9799),  INT16_C( 17517),  INT16_C( 30960), -INT16_C( 14409), -INT16_C( 21006), -INT16_C(  2935),  INT16_C( 19647) },
      {  INT16_C( 30403), -INT16_C( 13086), -INT16_C(  5279), -INT16_C( 21714),  INT16_C( 13483),  INT16_C( 29272), -INT16_C( 26851),  INT16_C(  2353),
         INT16_C(   747),  INT16_C(  1839),  INT16_C(  8125),  INT16_C( 29823),  INT16_C( 29415), -INT16_C( 21006), -INT16_C(  2935), -INT16_C( 11844) },
      UINT16_C(    0) },
    { UINT16_C(  158),
      { -INT16_C( 13293), -INT16_C( 16725),  INT16_C(  1024),  INT16_C(  7728),  INT16_C( 25243),  INT16_C( 13607),  INT16_C( 22234), -INT16_C( 26820),
        -INT16_C( 17291),  INT16_C( 23564),  INT16_C( 11566), -INT16_C( 27444), -INT16_C( 30706),  INT16_C(  2150),  INT16_C(  1062),  INT16_C( 14600) },
      { -INT16_C( 13293), -INT16_C( 16725),  INT16_C(  1024),  INT16_C( 21487),  INT16_C( 25243),  INT16_C( 13607),  INT16_C( 22234), -INT16_C( 26820),
        -INT16_C( 17291), -INT16_C( 20674),  INT16_C( 11566),  INT16_C( 17220), -INT16_C( 30706), -INT16_C( 18100),  INT16_C( 21678),  INT16_C( 32499) },
      UINT16_C(  150) },
    { UINT16_C(49231),
      {  INT16_C( 15890), -INT16_C( 25580), -INT16_C( 25260), -INT16_C( 16383), -INT16_C(   670), -INT16_C(  7006), -INT16_C(  8187),  INT16_C( 14995),
        -INT16_C( 10262),  INT16_C( 32126), -INT16_C( 13695),  INT16_C( 12087),  INT16_C( 10782),  INT16_C( 10158), -INT16_C(   748),  INT16_C( 10215) },
      { -INT16_C(  1220), -INT16_C( 25580), -INT16_C( 25260), -INT16_C( 16383), -INT16_C(  3135), -INT16_C( 14625),  INT16_C( 29395),  INT16_C( 14995),
         INT16_C( 32586), -INT16_C( 13509), -INT16_C( 13695),  INT16_C( 26619), -INT16_C( 22116),  INT16_C( 10158), -INT16_C(   748), -INT16_C(  7465) },
      UINT16_C(16398) },
    { UINT16_C( 2675),
      { -INT16_C( 15265),  INT16_C(  8453), -INT16_C(  6985), -INT16_C( 29977), -INT16_C(  6058), -INT16_C( 24505), -INT16_C( 32153), -INT16_C( 20372),
         INT16_C( 26612), -INT16_C( 28648), -INT16_C( 23024), -INT16_C( 18879),  INT16_C(  6172), -INT16_C( 29031),  INT16_C(  3251),  INT16_C(  5016) },
      { -INT16_C( 15265), -INT16_C( 30924), -INT16_C(  6985), -INT16_C( 10479),  INT16_C( 22532),  INT16_C( 27512), -INT16_C( 32153), -INT16_C( 12516),
         INT16_C( 26612), -INT16_C( 28648), -INT16_C( 24102), -INT16_C( 18879), -INT16_C( 21831),  INT16_C( 28037),  INT16_C(  3251), -INT16_C( 31104) },
      UINT16_C( 2625) },
    { UINT16_C(15117),
      {  INT16_C(  7887), -INT16_C( 11502), -INT16_C( 30089),  INT16_C( 21055),  INT16_C( 23406), -INT16_C( 18143), -INT16_C( 32369),  INT16_C( 26900),
         INT16_C(  9762), -INT16_C(  9120), -INT16_C(  6704), -INT16_C( 30903), -INT16_C( 14078), -INT16_C( 17395),  INT16_C(  7037),  INT16_C( 19703) },
      {  INT16_C(  2617), -INT16_C( 11502), -INT16_C( 30089),  INT16_C(   770),  INT16_C(  9402),  INT16_C( 18876), -INT16_C( 32369), -INT16_C( 14158),
         INT16_C(  5111), -INT16_C( 14428), -INT16_C(  4616), -INT16_C(  1202),  INT16_C( 23734), -INT16_C( 17395),  INT16_C(  7037), -INT16_C( 20353) },
      UINT16_C( 8196) },
    { UINT16_C(19809),
      {  INT16_C( 25598), -INT16_C( 18352),  INT16_C(  3463),  INT16_C( 11521), -INT16_C( 19234), -INT16_C( 10763), -INT16_C( 26169), -INT16_C( 16484),
        -INT16_C(  5242),  INT16_C( 15546),  INT16_C( 29255), -INT16_C( 16785), -INT16_C(  4575), -INT16_C(  9618), -INT16_C( 12402), -INT16_C( 29657) },
      {  INT16_C( 25598), -INT16_C( 18352),  INT16_C(  3463),  INT16_C( 25575), -INT16_C( 19234), -INT16_C( 10763), -INT16_C( 11147), -INT16_C( 16484),
        -INT16_C(  5242),  INT16_C( 15546), -INT16_C( 22867), -INT16_C( 16785),  INT16_C( 13205),  INT16_C(  9128), -INT16_C( 12286),  INT16_C( 13743) },
      UINT16_C( 2337) },  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i a = simde_mm256_loadu_epi16(test_vec[i].a);
    simde__m256i b = simde_mm256_loadu_epi16(test_vec[i].b);
    simde__mmask16 r = simde_mm256_mask_cmpeq_epi16_mask(test_vec[i].k1, a, b);
    simde_assert_equal_mmask16(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask16 k1 = simde_test_x86_random_mmask16();
    simde__m256i a = simde_test_x86_random_i16x16();
    simde__m256i b = simde_mm256_mask_blend_epi16(simde_test_x86_random_mmask16(), a, simde_test_x86_random_i16x16());
    simde__mmask16 r = simde_mm256_mask_cmpeq_epi16_mask(k1, a, b);

    simde_test_x86_write_mmask16(2, k1, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i16x16(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_cmpeq_epi16_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int16_t a[32];
    const int16_t b[32];
    const simde__mmask32 r;
  } test_vec[] = {
    { { -INT16_C( 16653),  INT16_C(   630), -INT16_C(  8006), -INT16_C( 13055),  INT16_C( 30696), -INT16_C( 20418), -INT16_C( 22001),  INT16_C(  4402),
        -INT16_C( 11219),  INT16_C( 22806), -INT16_C( 31512),  INT16_C( 15181),  INT16_C(  1643), -INT16_C( 29254),  INT16_C( 25877),  INT16_C(  2183),
        -INT16_C(   733), -INT16_C(  8950),  INT16_C(  3294), -INT16_C( 14678), -INT16_C(  6013), -INT16_C( 27786), -INT16_C( 22382), -INT16_C( 16220),
        -INT16_C( 17795),  INT16_C( 25881),  INT16_C( 26175), -INT16_C( 21856),  INT16_C( 23148), -INT16_C( 32456), -INT16_C( 16449), -INT16_C(  7287) },
      { -INT16_C( 16653), -INT16_C( 25664),  INT16_C( 27551),  INT16_C(  9057), -INT16_C( 10413), -INT16_C( 20418), -INT16_C( 22001), -INT16_C(   602),
        -INT16_C( 11219),  INT16_C( 21602),  INT16_C(   549),  INT16_C( 15181),  INT16_C( 13916), -INT16_C( 29254),  INT16_C( 25877), -INT16_C( 19457),
        -INT16_C(   733), -INT16_C(  8950),  INT16_C(  3294),  INT16_C( 32497), -INT16_C(  6013),  INT16_C(  1636), -INT16_C( 22382), -INT16_C( 16220),
         INT16_C( 26057),  INT16_C( 25881),  INT16_C( 26175), -INT16_C( 15233),  INT16_C( 23148), -INT16_C( 32456), -INT16_C(  8404),  INT16_C( 23112) },
      UINT32_C( 920086881) },
    { {  INT16_C(  6469), -INT16_C( 13241), -INT16_C( 21568), -INT16_C( 15662), -INT16_C( 10571),  INT16_C( 32472),  INT16_C( 17211), -INT16_C( 23700),
        -INT16_C(  5204),  INT16_C( 19303),  INT16_C( 18300), -INT16_C( 22303),  INT16_C( 10534), -INT16_C( 15358),  INT16_C( 11200),  INT16_C(  1421),
        -INT16_C( 11196),  INT16_C(  1489), -INT16_C( 23425),  INT16_C( 13511), -INT16_C( 24710), -INT16_C( 19022),  INT16_C(  7906), -INT16_C( 29096),
        -INT16_C( 16631), -INT16_C( 31270), -INT16_C( 17658),  INT16_C( 11309),  INT16_C( 12516), -INT16_C( 23311),  INT16_C( 32347), -INT16_C( 24662) },
      {  INT16_C( 31571), -INT16_C( 11612), -INT16_C( 21568), -INT16_C( 26361), -INT16_C( 10571), -INT16_C(  4785),  INT16_C( 17211), -INT16_C(  7812),
         INT16_C( 22119),  INT16_C( 19303), -INT16_C( 27631), -INT16_C(  2662), -INT16_C( 29756),  INT16_C(  8090),  INT16_C( 17417),  INT16_C( 23743),
        -INT16_C( 11196),  INT16_C(  1489),  INT16_C( 14031), -INT16_C(  9608), -INT16_C( 14353), -INT16_C( 19022),  INT16_C(  7906), -INT16_C( 29096),
        -INT16_C( 16631), -INT16_C( 21949), -INT16_C( 17658),  INT16_C( 27040),  INT16_C( 14952),  INT16_C( 29320),  INT16_C( 18302), -INT16_C( 24662) },
      UINT32_C(2246246996) },
    { { -INT16_C( 27341),  INT16_C(  9044),  INT16_C(  7004), -INT16_C( 13334), -INT16_C( 27809), -INT16_C(  1887), -INT16_C(  6749),  INT16_C( 18595),
         INT16_C( 17346),  INT16_C( 11185),  INT16_C( 14717), -INT16_C(  1123),  INT16_C( 27521),  INT16_C( 11320),  INT16_C( 21865), -INT16_C( 25434),
        -INT16_C(  1302),  INT16_C( 18111), -INT16_C( 21995),  INT16_C( 29714), -INT16_C( 19651), -INT16_C(  7827),  INT16_C(  4248),  INT16_C( 23337),
        -INT16_C(  9645), -INT16_C( 12154),  INT16_C(  8979), -INT16_C( 27445),  INT16_C(   910), -INT16_C(  2112),  INT16_C( 26200),  INT16_C( 17044) },
      { -INT16_C( 27341),  INT16_C(  9044), -INT16_C( 25603), -INT16_C( 13334), -INT16_C( 27809), -INT16_C(  1887), -INT16_C(  6749), -INT16_C( 17854),
        -INT16_C( 14305),  INT16_C( 12938),  INT16_C( 14717), -INT16_C(  1123), -INT16_C( 30887),  INT16_C( 11320),  INT16_C( 21865),  INT16_C( 20212),
        -INT16_C(  1302),  INT16_C( 18111), -INT16_C( 21995),  INT16_C( 29714), -INT16_C( 19651),  INT16_C( 28237), -INT16_C( 28686),  INT16_C(  4392),
        -INT16_C(  9645), -INT16_C( 12154),  INT16_C(  2568),  INT16_C( 25020),  INT16_C( 11666), -INT16_C(  2112),  INT16_C( 26200), -INT16_C( 30002) },
      UINT32_C(1663003771) },
    { {  INT16_C( 28994),  INT16_C( 18434),  INT16_C( 20510),  INT16_C(  4278), -INT16_C(  8225),  INT16_C( 14113),  INT16_C( 26002), -INT16_C( 25991),
         INT16_C( 13679),  INT16_C(   508),  INT16_C(  3938), -INT16_C( 27519),  INT16_C( 20502), -INT16_C( 26081), -INT16_C(    29),  INT16_C(  9526),
         INT16_C( 14449), -INT16_C( 28819),  INT16_C(  9352),  INT16_C( 26784), -INT16_C( 16125), -INT16_C( 27233),  INT16_C(  6182), -INT16_C( 27089),
         INT16_C( 11086), -INT16_C( 20329),  INT16_C(  6458),  INT16_C( 20549),  INT16_C( 25705),  INT16_C( 19690),  INT16_C(  8291), -INT16_C( 11151) },
      { -INT16_C(  8615),  INT16_C( 18434),  INT16_C(  1026),  INT16_C(  4278), -INT16_C(  8225), -INT16_C(  4966), -INT16_C( 13823), -INT16_C( 25991),
         INT16_C( 13679),  INT16_C( 12543),  INT16_C(  3938), -INT16_C( 25728),  INT16_C( 20502),  INT16_C(  3303),  INT16_C( 22667), -INT16_C(  6944),
         INT16_C( 14449), -INT16_C( 28819),  INT16_C(  3912),  INT16_C( 26784), -INT16_C(  9736), -INT16_C( 27233),  INT16_C(  6182), -INT16_C( 27089),
         INT16_C( 11086), -INT16_C( 14135),  INT16_C( 18828),  INT16_C( 13411),  INT16_C( 25705),  INT16_C( 16448),  INT16_C(  8291), -INT16_C(  9692) },
      UINT32_C(1374360986) },
    { {  INT16_C( 21498), -INT16_C(  3396), -INT16_C( 18900), -INT16_C( 12053),  INT16_C( 13106), -INT16_C( 14487),  INT16_C( 12922),  INT16_C(  1679),
        -INT16_C(  3205),  INT16_C( 12347),  INT16_C( 31550), -INT16_C(  7824), -INT16_C( 27492),  INT16_C(   700), -INT16_C( 12161),  INT16_C( 31152),
         INT16_C( 27683),  INT16_C( 20331),  INT16_C( 22050),  INT16_C( 21535), -INT16_C( 30583),  INT16_C(   795), -INT16_C( 21574),  INT16_C( 13834),
         INT16_C( 17822), -INT16_C(  9114), -INT16_C( 10560),  INT16_C( 23997),  INT16_C( 31082), -INT16_C(  5793),  INT16_C(  3913),  INT16_C( 27746) },
      { -INT16_C( 12933), -INT16_C(  3396), -INT16_C( 18900), -INT16_C( 12053),  INT16_C( 13106),  INT16_C(  7856), -INT16_C( 17737),  INT16_C( 21844),
        -INT16_C( 17665), -INT16_C( 16591), -INT16_C(  4208), -INT16_C(  7824),  INT16_C( 31592),  INT16_C(   700),  INT16_C( 18314),  INT16_C(  1310),
        -INT16_C(  9708),  INT16_C( 14498),  INT16_C( 22050),  INT16_C(  6884), -INT16_C( 30583),  INT16_C(   795), -INT16_C( 29362),  INT16_C( 13834),
        -INT16_C(  8633), -INT16_C( 10227),  INT16_C( 10701),  INT16_C( 23997), -INT16_C( 18523), -INT16_C(  5793),  INT16_C(  3913),  INT16_C(  4917) },
      UINT32_C(1756637214) },
    { {  INT16_C( 12139),  INT16_C(  2993), -INT16_C(  5692),  INT16_C(  4706),  INT16_C(  3958), -INT16_C( 16800),  INT16_C( 28142), -INT16_C( 17514),
         INT16_C( 27030),  INT16_C( 15345), -INT16_C(  9952),  INT16_C(  8043), -INT16_C( 24352), -INT16_C( 16078),  INT16_C( 32119), -INT16_C(  7592),
         INT16_C(  2476),  INT16_C( 28909),  INT16_C( 20722),  INT16_C( 27011), -INT16_C(  7329),  INT16_C( 19751), -INT16_C( 17072), -INT16_C(  6647),
        -INT16_C(  1498),  INT16_C( 17954), -INT16_C( 29228), -INT16_C( 19355), -INT16_C( 26835), -INT16_C( 23435), -INT16_C( 13036), -INT16_C( 15993) },
      {  INT16_C( 29910), -INT16_C( 14287), -INT16_C( 19260),  INT16_C(  9265),  INT16_C(  3958), -INT16_C( 16800),  INT16_C( 28142), -INT16_C( 17514),
        -INT16_C(  3979),  INT16_C( 15345), -INT16_C(  6275), -INT16_C( 21763),  INT16_C( 29311), -INT16_C( 27826), -INT16_C( 10945), -INT16_C(  7592),
        -INT16_C( 31158),  INT16_C(  3805),  INT16_C( 20722), -INT16_C( 11726), -INT16_C( 23449),  INT16_C( 19751), -INT16_C( 17072), -INT16_C(  6647),
         INT16_C( 14967),  INT16_C( 17954), -INT16_C( 29228), -INT16_C( 24162), -INT16_C( 26835), -INT16_C( 23435), -INT16_C( 30270), -INT16_C( 15993) },
      UINT32_C(3068429040) },
    { {  INT16_C( 19852), -INT16_C(  3301), -INT16_C( 10767),  INT16_C(  4208),  INT16_C( 10588), -INT16_C( 11101), -INT16_C( 32669), -INT16_C( 31288),
         INT16_C( 26457), -INT16_C( 23258),  INT16_C( 23380),  INT16_C(  5679), -INT16_C( 12316), -INT16_C(  3293),  INT16_C( 15948), -INT16_C( 10180),
         INT16_C( 22667),  INT16_C( 32203),  INT16_C( 15405), -INT16_C( 30323),  INT16_C( 12389), -INT16_C( 14243),  INT16_C(  9904),  INT16_C(  2638),
         INT16_C( 29837), -INT16_C(  7761), -INT16_C(  8497), -INT16_C( 19465),  INT16_C(  6829), -INT16_C(  1626), -INT16_C(  7336), -INT16_C(  6959) },
      {  INT16_C( 19852), -INT16_C(  3301), -INT16_C(  4391),  INT16_C(  4208),  INT16_C( 20254), -INT16_C( 12538),  INT16_C( 21621),  INT16_C(   729),
         INT16_C( 26457), -INT16_C( 23258), -INT16_C(  9626),  INT16_C(  5196), -INT16_C( 12316),  INT16_C( 19725), -INT16_C(  8235),  INT16_C(  4145),
        -INT16_C( 28036),  INT16_C( 21880),  INT16_C( 27264), -INT16_C( 30323),  INT16_C( 12389), -INT16_C( 14243),  INT16_C(  9904),  INT16_C(  2638),
         INT16_C( 29837), -INT16_C(  7761), -INT16_C( 25619), -INT16_C( 19465),  INT16_C( 22414),  INT16_C( 25392),  INT16_C( 24886), -INT16_C(  6959) },
      UINT32_C(2348290827) },
    { { -INT16_C( 26026),  INT16_C(  3859), -INT16_C( 32461),  INT16_C(  8509),  INT16_C( 28104), -INT16_C( 26664),  INT16_C( 10368),  INT16_C( 28365),
         INT16_C(  5827),  INT16_C( 20816), -INT16_C( 32659), -INT16_C( 23627),  INT16_C( 10722), -INT16_C( 10667),  INT16_C( 23573),  INT16_C( 27722),
         INT16_C( 24310),  INT16_C( 10875), -INT16_C( 17953), -INT16_C( 22453),  INT16_C(  9254), -INT16_C( 22721),  INT16_C(  3148),  INT16_C(  3861),
         INT16_C( 25891), -INT16_C( 28575),  INT16_C(  5862), -INT16_C( 14284), -INT16_C( 30401),  INT16_C( 21662), -INT16_C(  5914), -INT16_C(  9024) },
      {  INT16_C( 15430),  INT16_C(  3859),  INT16_C( 21237),  INT16_C(  7118),  INT16_C(  3446), -INT16_C( 15678), -INT16_C( 10470),  INT16_C( 28365),
         INT16_C(  5827),  INT16_C(  9165),  INT16_C(   328), -INT16_C( 30741), -INT16_C( 30325), -INT16_C( 10667), -INT16_C( 25487),  INT16_C( 27722),
         INT16_C( 24310),  INT16_C( 10875), -INT16_C( 17953), -INT16_C( 22453), -INT16_C( 21575), -INT16_C( 22721), -INT16_C( 20605), -INT16_C( 16368),
        -INT16_C(  8478),  INT16_C( 10979),  INT16_C(  5862), -INT16_C( 14284), -INT16_C( 30401), -INT16_C( 14117), -INT16_C(  5914), -INT16_C(  9024) },
      UINT32_C(3694109058) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512i a = simde_mm512_loadu_epi16(test_vec[i].a);
    simde__m512i b = simde_mm512_loadu_epi16(test_vec[i].b);
    simde__mmask32 r = simde_mm512_cmpeq_epi16_mask(a, b);
    simde_assert_equal_mmask32(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m512i a = simde_test_x86_random_i16x32();
    simde__m512i b = simde_mm512_mask_blend_epi16(simde_test_x86_random_mmask32(), a, simde_test_x86_random_i16x32());
    simde__mmask32 r = simde_mm512_cmpeq_epi16_mask(a, b);

    simde_test_x86_write_i16x32(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i16x32(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_mask_cmpeq_epi16_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask32 k1;
    const int16_t a[32];
    const int16_t b[32];
    const simde__mmask32 r;
  } test_vec[] = {
    { UINT32_C(3292510474),
      {  INT16_C(  7525), -INT16_C(  5993), -INT16_C( 22324), -INT16_C( 20824), -INT16_C( 29818),  INT16_C( 26073), -INT16_C( 29863), -INT16_C( 20272),
        -INT16_C( 21735),  INT16_C( 17272), -INT16_C(  1580),  INT16_C( 20806),  INT16_C(  5975),  INT16_C( 25204), -INT16_C( 19504),  INT16_C( 13606),
        -INT16_C( 16944), -INT16_C( 25315), -INT16_C( 15003), -INT16_C(  5301),  INT16_C(  9296), -INT16_C( 22191),  INT16_C(  8623), -INT16_C( 14247),
        -INT16_C( 11572), -INT16_C( 24308),  INT16_C( 21195),  INT16_C(  8946),  INT16_C( 26473),  INT16_C( 14980), -INT16_C( 21990), -INT16_C(  5265) },
      {  INT16_C(  7525), -INT16_C(  5993), -INT16_C( 22324), -INT16_C( 23623), -INT16_C( 29818),  INT16_C( 26073), -INT16_C( 22997), -INT16_C( 20272),
        -INT16_C( 21735),  INT16_C( 17272), -INT16_C( 29746),  INT16_C( 14437), -INT16_C(  5390),  INT16_C(  3186), -INT16_C( 19504), -INT16_C(   777),
        -INT16_C( 16944), -INT16_C( 25315), -INT16_C( 15003),  INT16_C( 19300),  INT16_C(  9296), -INT16_C( 18190),  INT16_C( 25174), -INT16_C( 14247),
         INT16_C( 18654), -INT16_C( 21231),  INT16_C( 21195), -INT16_C( 14875),  INT16_C( 22369),  INT16_C( 14980), -INT16_C( 21990), -INT16_C( 22542) },
      UINT32_C(1142358274) },
    { UINT32_C(3437677631),
      { -INT16_C(  9860), -INT16_C( 11388),  INT16_C( 13115),  INT16_C(  6817), -INT16_C( 19589),  INT16_C( 20167), -INT16_C( 21462), -INT16_C( 29933),
        -INT16_C(  6909),  INT16_C( 15232),  INT16_C( 29358), -INT16_C(  2334),  INT16_C( 18990),  INT16_C( 28050),  INT16_C( 30742), -INT16_C( 27847),
        -INT16_C( 17071), -INT16_C( 29338),  INT16_C(  2033),  INT16_C( 27815),  INT16_C( 28346), -INT16_C(  6981), -INT16_C( 12774),  INT16_C(  7535),
        -INT16_C(  3917),  INT16_C( 24920),  INT16_C( 15202), -INT16_C( 28328), -INT16_C(  5499), -INT16_C( 25346),  INT16_C( 14434), -INT16_C( 19409) },
      { -INT16_C(  9860), -INT16_C( 11388),  INT16_C( 13115),  INT16_C( 22355), -INT16_C( 19589),  INT16_C( 20167), -INT16_C( 21540), -INT16_C( 29933),
        -INT16_C(  6909),  INT16_C( 15232),  INT16_C( 18720), -INT16_C(  2334), -INT16_C( 29389), -INT16_C( 27070),  INT16_C( 30742), -INT16_C( 17846),
        -INT16_C( 29946), -INT16_C( 29338), -INT16_C(  2957), -INT16_C( 13831),  INT16_C( 28346), -INT16_C(  6981), -INT16_C( 14624),  INT16_C( 31598),
         INT16_C( 24747), -INT16_C( 13192),  INT16_C( 15202), -INT16_C(  8846), -INT16_C( 19308),  INT16_C( 22899),  INT16_C( 14434),  INT16_C( 11027) },
      UINT32_C(1143097399) },
    { UINT32_C(2860828584),
      { -INT16_C( 16900), -INT16_C(  9079), -INT16_C(  2173),  INT16_C( 11863), -INT16_C( 12457),  INT16_C(   506),  INT16_C( 27862),  INT16_C( 27358),
         INT16_C( 20768),  INT16_C( 17859), -INT16_C( 10482),  INT16_C( 22128),  INT16_C( 16011),  INT16_C( 13329), -INT16_C( 27387),  INT16_C(   478),
         INT16_C( 26450), -INT16_C( 10787),  INT16_C( 13407), -INT16_C( 18941), -INT16_C(   509), -INT16_C(  9545), -INT16_C( 27286), -INT16_C( 29884),
         INT16_C(  2278), -INT16_C(  2864),  INT16_C( 16863),  INT16_C( 27210),  INT16_C( 23423), -INT16_C( 31586),  INT16_C( 32240),  INT16_C( 17029) },
      {  INT16_C( 25316), -INT16_C(  9079), -INT16_C(  2173), -INT16_C( 26118), -INT16_C( 12457),  INT16_C(   506),  INT16_C( 27862),  INT16_C( 11534),
        -INT16_C(  8256),  INT16_C( 17859), -INT16_C( 10482),  INT16_C( 22128), -INT16_C( 22328), -INT16_C( 18397), -INT16_C( 22491),  INT16_C(  2555),
         INT16_C(  4618), -INT16_C( 24499),  INT16_C( 13407),  INT16_C( 17977), -INT16_C(   509),  INT16_C( 16330), -INT16_C( 10139),  INT16_C(  9581),
        -INT16_C( 28745), -INT16_C( 10300), -INT16_C( 12805),  INT16_C( 27210), -INT16_C( 26251), -INT16_C( 25988),  INT16_C( 32240),  INT16_C( 19364) },
      UINT32_C( 134481440) },
    { UINT32_C( 821896504),
      { -INT16_C( 14382),  INT16_C( 14192), -INT16_C(  8800),  INT16_C( 22364),  INT16_C(  8300),  INT16_C( 26415), -INT16_C( 23059),  INT16_C( 25387),
        -INT16_C( 22721), -INT16_C( 32515), -INT16_C( 24290), -INT16_C( 22580), -INT16_C( 18542), -INT16_C( 13730),  INT16_C( 23772), -INT16_C( 20741),
         INT16_C( 27427), -INT16_C( 15387),  INT16_C( 16712), -INT16_C( 19429),  INT16_C( 19041),  INT16_C( 20251),  INT16_C( 18159),  INT16_C( 11954),
        -INT16_C( 20499),  INT16_C(  2991),  INT16_C( 31569), -INT16_C(  7245),  INT16_C(  4402),  INT16_C(  4014), -INT16_C( 22163), -INT16_C( 28227) },
      { -INT16_C( 23788),  INT16_C( 14192),  INT16_C( 28644),  INT16_C( 22364),  INT16_C(  8300),  INT16_C( 26415), -INT16_C( 23059),  INT16_C( 25387),
        -INT16_C( 22721),  INT16_C( 18283),  INT16_C(  7681), -INT16_C( 22580), -INT16_C(  9937), -INT16_C( 25277),  INT16_C(   130), -INT16_C( 27090),
        -INT16_C( 32093), -INT16_C( 30478),  INT16_C(   754), -INT16_C( 19429),  INT16_C( 25389),  INT16_C( 20251),  INT16_C( 11434),  INT16_C( 11954),
         INT16_C( 27314), -INT16_C( 19224),  INT16_C(  5000), -INT16_C(  7245),  INT16_C( 11244),  INT16_C( 28244), -INT16_C( 32213), -INT16_C( 12540) },
      UINT32_C(  11010360) },
    { UINT32_C( 631383544),
      { -INT16_C(  2168),  INT16_C( 12997), -INT16_C( 15325), -INT16_C( 10798), -INT16_C( 17874), -INT16_C( 18807),  INT16_C( 29133), -INT16_C( 18067),
        -INT16_C( 15716), -INT16_C( 14297),  INT16_C( 11076),  INT16_C( 18839), -INT16_C(  4575),  INT16_C(  6464), -INT16_C(  7405), -INT16_C( 25793),
         INT16_C(  1242), -INT16_C(   563), -INT16_C( 24632), -INT16_C(  2350),  INT16_C( 23642),  INT16_C( 10156),  INT16_C(  6605),  INT16_C( 27361),
         INT16_C(  2267),  INT16_C(  8242), -INT16_C( 14028),  INT16_C( 21865), -INT16_C( 21833), -INT16_C( 13713), -INT16_C( 20851),  INT16_C( 26469) },
      { -INT16_C(  2168),  INT16_C( 12997), -INT16_C( 15325),  INT16_C( 11120),  INT16_C(  7314), -INT16_C( 18807),  INT16_C( 29133),  INT16_C(  4554),
        -INT16_C( 15716), -INT16_C( 14297),  INT16_C( 11076),  INT16_C( 18839),  INT16_C( 13636),  INT16_C(  6464), -INT16_C(  7405), -INT16_C( 27336),
        -INT16_C( 25379), -INT16_C(   563), -INT16_C( 24632),  INT16_C( 26074),  INT16_C( 23642),  INT16_C( 10156), -INT16_C( 28831),  INT16_C( 27361),
         INT16_C(  4747),  INT16_C( 20494), -INT16_C( 14028), -INT16_C(  3636), -INT16_C( 21833), -INT16_C(  4925), -INT16_C(  1091),  INT16_C( 26469) },
      UINT32_C(  77735264) },
    { UINT32_C(2865767183),
      { -INT16_C( 27056), -INT16_C( 20102),  INT16_C( 23589), -INT16_C( 20146),  INT16_C( 23662),  INT16_C(  6913), -INT16_C( 12752),  INT16_C( 14605),
        -INT16_C( 12064), -INT16_C( 25051), -INT16_C( 22837),  INT16_C( 25400), -INT16_C( 32458),  INT16_C( 17870), -INT16_C( 24668), -INT16_C(  2833),
         INT16_C( 27189),  INT16_C( 23205), -INT16_C(  2874),  INT16_C( 13323),  INT16_C(  3408), -INT16_C( 32432),  INT16_C( 24027), -INT16_C( 17478),
        -INT16_C(  8147), -INT16_C(  1959), -INT16_C( 28026), -INT16_C( 17060),  INT16_C( 10771), -INT16_C( 18430), -INT16_C(  3383), -INT16_C(   340) },
      {  INT16_C( 21084),  INT16_C(  8793),  INT16_C( 25670), -INT16_C( 20146), -INT16_C( 22927),  INT16_C( 19479), -INT16_C( 12752),  INT16_C( 12296),
         INT16_C( 25010),  INT16_C( 14377), -INT16_C( 22837),  INT16_C( 25400), -INT16_C(  1873),  INT16_C( 31167),  INT16_C( 27626),  INT16_C( 18039),
         INT16_C( 27189),  INT16_C(   872), -INT16_C(  2874),  INT16_C( 13323),  INT16_C(  3408), -INT16_C( 32432), -INT16_C(  1149), -INT16_C( 17478),
        -INT16_C(  8147), -INT16_C(  1959),  INT16_C( 25415), -INT16_C(  2473),  INT16_C( 10771),  INT16_C( 17775), -INT16_C(  6271),  INT16_C( 16267) },
      UINT32_C(  42991624) },
    { UINT32_C( 395566258),
      { -INT16_C( 31090),  INT16_C(  4479),  INT16_C(  6273), -INT16_C(  8889), -INT16_C( 18982),  INT16_C(  8493), -INT16_C( 31720),  INT16_C( 29720),
        -INT16_C( 30822),  INT16_C(  7353),  INT16_C( 17774),  INT16_C(  9819), -INT16_C( 25288), -INT16_C(  5614), -INT16_C( 23174),  INT16_C(  2049),
        -INT16_C( 32469), -INT16_C( 21479),  INT16_C( 24729),  INT16_C( 29834), -INT16_C( 18667),  INT16_C( 11925), -INT16_C( 21188), -INT16_C( 10590),
         INT16_C( 23349), -INT16_C( 23566),  INT16_C( 19872), -INT16_C(  9783), -INT16_C(  8981),  INT16_C( 26051), -INT16_C( 14975), -INT16_C( 21139) },
      { -INT16_C( 31162), -INT16_C(  8359), -INT16_C(  7193), -INT16_C(   941), -INT16_C(  5733),  INT16_C(  8493), -INT16_C( 31720),  INT16_C( 29720),
        -INT16_C( 30822),  INT16_C(  7353),  INT16_C( 14573), -INT16_C( 10079), -INT16_C( 25288), -INT16_C( 27075), -INT16_C( 21974),  INT16_C( 28739),
        -INT16_C( 32469),  INT16_C(  6223), -INT16_C( 23680),  INT16_C( 29834),  INT16_C( 16268),  INT16_C(  8946), -INT16_C( 21188), -INT16_C( 10590),
         INT16_C( 23871),  INT16_C( 11772), -INT16_C( 25195), -INT16_C( 22011),  INT16_C( 17154),  INT16_C( 26051), -INT16_C( 14975),  INT16_C(  7836) },
      UINT32_C(   8458400) },
    { UINT32_C( 465193871),
      { -INT16_C( 21366), -INT16_C( 27331),  INT16_C( 11084), -INT16_C( 29751), -INT16_C( 14968),  INT16_C(  7864), -INT16_C( 16798),  INT16_C( 26056),
         INT16_C(  2049), -INT16_C(  4463),  INT16_C( 11915), -INT16_C( 22003),  INT16_C( 17178), -INT16_C( 22198),  INT16_C(  1166),  INT16_C(  6340),
         INT16_C(   433), -INT16_C(   594),  INT16_C( 30509), -INT16_C( 19064),  INT16_C( 16700), -INT16_C( 24877), -INT16_C( 25601),  INT16_C(     3),
        -INT16_C( 27229),  INT16_C( 12014), -INT16_C(  1085), -INT16_C(  8743),  INT16_C(  9023), -INT16_C( 12922),  INT16_C( 18983), -INT16_C( 10010) },
      { -INT16_C( 27573),  INT16_C( 30933),  INT16_C( 24075),  INT16_C( 18222),  INT16_C(   415),  INT16_C(  7864), -INT16_C( 16798),  INT16_C( 26056),
        -INT16_C( 29570), -INT16_C(  4463),  INT16_C( 11915), -INT16_C( 14562),  INT16_C( 17178), -INT16_C( 22198),  INT16_C(  1166),  INT16_C( 14699),
         INT16_C(   433), -INT16_C(   594), -INT16_C(  8034),  INT16_C( 15712),  INT16_C( 16700), -INT16_C( 24877), -INT16_C( 25601), -INT16_C( 21057),
         INT16_C( 11782),  INT16_C( 12014),  INT16_C(  3190), -INT16_C(  7851), -INT16_C(  5712), -INT16_C( 24973),  INT16_C( 18983),  INT16_C( 29399) },
      UINT32_C(  36848256) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512i a = simde_mm512_loadu_epi16(test_vec[i].a);
    simde__m512i b = simde_mm512_loadu_epi16(test_vec[i].b);
    simde__mmask32 r = simde_mm512_mask_cmpeq_epi16_mask(test_vec[i].k1, a, b);
    simde_assert_equal_mmask32(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask32 k1 = simde_test_x86_random_mmask32();
    simde__m512i a = simde_test_x86_random_i16x32();
    simde__m512i b = simde_mm512_mask_blend_epi16(simde_test_x86_random_mmask32(), a, simde_test_x86_random_i16x32());
    simde__mmask32 r = simde_mm512_mask_cmpeq_epi16_mask(k1, a, b);

    simde_test_x86_write_mmask32(2, k1, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i16x32(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x32(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_cmpeq_epi32_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int32_t a[4];
    const int32_t b[4];
    const simde__mmask8 r;
  } test_vec[] = {
    { {  INT32_C(  1274801257),  INT32_C(  1640617522),  INT32_C(  1443792976),  INT32_C(   753204406) },
      { -INT32_C(  1207092984),  INT32_C(  1640617522),  INT32_C(  1443792976),  INT32_C(   753204406) },
      UINT8_C( 14) },
    { {  INT32_C(   228879415), -INT32_C(  1101200075),  INT32_C(   276083476), -INT32_C(   803626601) },
      {  INT32_C(   228879415),  INT32_C(  1452243240),  INT32_C(   276083476), -INT32_C(  2140590519) },
      UINT8_C(  5) },
    { {  INT32_C(   315657741), -INT32_C(  1624862997), -INT32_C(  1556728062),  INT32_C(   559023952) },
      {  INT32_C(   315657741),  INT32_C(   518430480), -INT32_C(   613950035),  INT32_C(   559023952) },
      UINT8_C(  9) },
    { { -INT32_C(   731814330), -INT32_C(  1009385332),  INT32_C(  1041463863),  INT32_C(  1295529420) },
      {  INT32_C(   509520766),  INT32_C(  1875606673), -INT32_C(   877287709),  INT32_C(  1648429340) },
      UINT8_C(  0) },
    { { -INT32_C(  1543817565), -INT32_C(  2015707379),  INT32_C(   122886354), -INT32_C(    58286000) },
      {  INT32_C(  2056103166),  INT32_C(   358546543),  INT32_C(   122886354),  INT32_C(   237671531) },
      UINT8_C(  4) },
    { { -INT32_C(   455560923), -INT32_C(  1531486324),  INT32_C(  1391836850), -INT32_C(   397283004) },
      {  INT32_C(  2069351294), -INT32_C(  1531486324),  INT32_C(   868149407),  INT32_C(   939445266) },
      UINT8_C(  2) },
    { {  INT32_C(   889789654), -INT32_C(  1847087405), -INT32_C(  1797899613),  INT32_C(  1444069003) },
      {  INT32_C(   889789654), -INT32_C(  1847087405), -INT32_C(  1797899613),  INT32_C(   718990420) },
      UINT8_C(  7) },
    { { -INT32_C(  1831116572), -INT32_C(  2127205305),  INT32_C(    17615170),  INT32_C(  1763140571) },
      { -INT32_C(  1831116572), -INT32_C(  2127205305),  INT32_C(    17615170),  INT32_C(  1763140571) },
      UINT8_C( 15) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_mm_loadu_epi32(test_vec[i].a);
    simde__m128i b = simde_mm_loadu_epi32(test_vec[i].b);
    simde__mmask8 r = simde_mm_cmpeq_epi32_mask(a, b);
    simde_assert_equal_mmask8(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i a = simde_test_x86_random_i32x4();
    simde__m128i b = simde_mm_mask_blend_epi32(simde_test_x86_random_mmask8(), a, simde_test_x86_random_i32x4());
    simde__mmask8 r = simde_mm_cmpeq_epi32_mask(a, b);

    simde_test_x86_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_mask_cmpeq_epi32_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k1;
    const int32_t a[4];
    const int32_t b[4];
    const simde__mmask8 r;
  } test_vec[] = {
    { UINT8_C( 73),
      {  INT32_C(   699807732), -INT32_C(   973932359),  INT32_C(   271109881),  INT32_C(  1521093431) },
      {  INT32_C(   136341185), -INT32_C(   973932359),  INT32_C(  1886202625),  INT32_C(  1521093431) },
      UINT8_C(  8) },
    { UINT8_C(111),
      { -INT32_C(  1637331285),  INT32_C(  1013735699),  INT32_C(   474456946),  INT32_C(   511904253) },
      { -INT32_C(  1637331285),  INT32_C(  1189722840), -INT32_C(   459049430),  INT32_C(   511904253) },
      UINT8_C(  9) },
    { UINT8_C(187),
      { -INT32_C(  1373791678),  INT32_C(   491884502),  INT32_C(   774262443),  INT32_C(   623458412) },
      { -INT32_C(  1373791678),  INT32_C(   491884502),  INT32_C(  1109675758),  INT32_C(   623458412) },
      UINT8_C( 11) },
    { UINT8_C( 26),
      {  INT32_C(   866720482),  INT32_C(  1585534264), -INT32_C(  1382617469), -INT32_C(   206599149) },
      {  INT32_C(   866720482),  INT32_C(  1585534264), -INT32_C(  1382617469), -INT32_C(   206599149) },
      UINT8_C( 10) },
    { UINT8_C(240),
      { -INT32_C(   884651958),  INT32_C(  1035585702),  INT32_C(   617205109), -INT32_C(  1105513024) },
      {  INT32_C(    95158006), -INT32_C(  1257842428),  INT32_C(   617205109), -INT32_C(  1105513024) },
      UINT8_C(  0) },
    { UINT8_C(129),
      {  INT32_C(   558475623), -INT32_C(  1326530586), -INT32_C(     1724701),  INT32_C(   419289965) },
      { -INT32_C(   420412960), -INT32_C(  1326530586), -INT32_C(     1724701),  INT32_C(  1979719695) },
      UINT8_C(  0) },
    { UINT8_C( 73),
      { -INT32_C(  2063028073),  INT32_C(  1161096288), -INT32_C(   400514581), -INT32_C(  1427570503) },
      {  INT32_C(   128032998),  INT32_C(  1161096288), -INT32_C(   400514581), -INT32_C(  1750267393) },
      UINT8_C(  0) },
    { UINT8_C(181),
      {  INT32_C(  1352735004),  INT32_C(  2129759326),  INT32_C(  1585359476), -INT32_C(   151100331) },
      { -INT32_C(   438632085),  INT32_C(  1617837600),  INT32_C(  1585359476),  INT32_C(   553918980) },
      UINT8_C(  4) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_mm_loadu_epi32(test_vec[i].a);
    simde__m128i b = simde_mm_loadu_epi32(test_vec[i].b);
    simde__mmask8 r = simde_mm_mask_cmpeq_epi32_mask(test_vec[i].k1, a, b);
    simde_assert_equal_mmask8(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k1 = simde_test_x86_random_mmask8();
    simde__m128i a = simde_test_x86_random_i32x4();
    simde__m128i b = simde_mm_mask_blend_epi32(simde_test_x86_random_mmask8(), a, simde_test_x86_random_i32x4());
    simde__mmask8 r = simde_mm_mask_cmpeq_epi32_mask(k1, a, b);

    simde_test_x86_write_mmask8(2, k1, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x4(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_cmpeq_epi32_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int32_t a[8];
    const int32_t b[8];
    const simde__mmask8 r;
  } test_vec[] = {
    { { -INT32_C(   777240092),  INT32_C(  1199307497), -INT32_C(   569699498),  INT32_C(   997612412), -INT32_C(   827412645), -INT32_C(   107830963), -INT32_C(  1255919630),  INT32_C(  1405875567) },
      { -INT32_C(   777240092),  INT32_C(  1199307497),  INT32_C(   799437235),  INT32_C(   997612412), -INT32_C(   827412645), -INT32_C(  1408136774), -INT32_C(  1255919630),  INT32_C(  1618619690) },
      UINT8_C( 91) },
    { {  INT32_C(  1041596575),  INT32_C(  1492245990), -INT32_C(  1625022077), -INT32_C(  1519760244), -INT32_C(   866155965), -INT32_C(   914092908), -INT32_C(  1678463890), -INT32_C(   985705434) },
      { -INT32_C(  1157344044), -INT32_C(  1273760463), -INT32_C(  1571604714), -INT32_C(   951599740), -INT32_C(   866155965), -INT32_C(   914092908), -INT32_C(   356740669), -INT32_C(   985705434) },
      UINT8_C(176) },
    { { -INT32_C(  1451133517), -INT32_C(  1061210744),  INT32_C(  1178886793),  INT32_C(  1350962089), -INT32_C(  1258071394), -INT32_C(  1988549384), -INT32_C(   613456928), -INT32_C(   970249710) },
      {  INT32_C(   678407327), -INT32_C(  1061210744),  INT32_C(   984689808),  INT32_C(  1350962089), -INT32_C(  1258071394), -INT32_C(  1988549384),  INT32_C(  2037285734), -INT32_C(   970249710) },
      UINT8_C(186) },
    { { -INT32_C(   601394002), -INT32_C(  2006085284),  INT32_C(  2059380546), -INT32_C(  1089694671),  INT32_C(   577934879),  INT32_C(   747177385),  INT32_C(   232325747), -INT32_C(   279828927) },
      { -INT32_C(   601394002), -INT32_C(  2006085284),  INT32_C(   298270687), -INT32_C(  1089694671),  INT32_C(   320160361),  INT32_C(   747177385),  INT32_C(   232325747), -INT32_C(   640673217) },
      UINT8_C(107) },
    { { -INT32_C(   727723877), -INT32_C(  1884033968), -INT32_C(  2023570252), -INT32_C(   672049771),  INT32_C(   136250474),  INT32_C(  1554569795), -INT32_C(  1130657374), -INT32_C(   196053671) },
      { -INT32_C(   727723877), -INT32_C(  1884033968), -INT32_C(   719878336), -INT32_C(   672049771),  INT32_C(   136250474),  INT32_C(  1554569795), -INT32_C(   670807937), -INT32_C(   196053671) },
      UINT8_C(187) },
    { {  INT32_C(   287348885),  INT32_C(  1129427132), -INT32_C(   803264568), -INT32_C(  1596103212), -INT32_C(  1455018573),  INT32_C(   556306137), -INT32_C(   404881262),  INT32_C(  1647108557) },
      {  INT32_C(   287348885), -INT32_C(   981875459), -INT32_C(  1080715029), -INT32_C(  1596103212), -INT32_C(  1455018573), -INT32_C(   962952397), -INT32_C(   404881262),  INT32_C(  1647108557) },
      UINT8_C(217) },
    { { -INT32_C(   366802906),  INT32_C(   450291841), -INT32_C(   266824323), -INT32_C(  1701852683), -INT32_C(  1462892508),  INT32_C(   472683683),  INT32_C(   460750145),  INT32_C(  1447119152) },
      { -INT32_C(   750754735), -INT32_C(   907209140), -INT32_C(  1581709908), -INT32_C(   214218290), -INT32_C(   191166127),  INT32_C(   472683683),  INT32_C(   460750145),  INT32_C(   566901711) },
      UINT8_C( 96) },
    { {  INT32_C(   569111562), -INT32_C(   422726431), -INT32_C(  1212912018), -INT32_C(  1291278423),  INT32_C(   156302658), -INT32_C(  1806881011),  INT32_C(  1684259113), -INT32_C(  1778154357) },
      {  INT32_C(   569111562),  INT32_C(   289375395), -INT32_C(  1681328910), -INT32_C(   565260133),  INT32_C(   156302658), -INT32_C(  1806881011), -INT32_C(  2107845898), -INT32_C(  1778154357) },
      UINT8_C(177) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i a = simde_mm256_loadu_epi32(test_vec[i].a);
    simde__m256i b = simde_mm256_loadu_epi32(test_vec[i].b);
    simde__mmask8 r = simde_mm256_cmpeq_epi32_mask(a, b);
    simde_assert_equal_mmask8(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m256i a = simde_test_x86_random_i32x8();
    simde__m256i b = simde_mm256_mask_blend_epi32(simde_test_x86_random_mmask8(), a, simde_test_x86_random_i32x8());
    simde__mmask8 r = simde_mm256_cmpeq_epi32_mask(a, b);

    simde_test_x86_write_i32x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_mask_cmpeq_epi32_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k1;
    const int32_t a[8];
    const int32_t b[8];
    const simde__mmask8 r;
  } test_vec[] = {
    { UINT8_C(207),
      {  INT32_C(  1750331689), -INT32_C(   899922686),  INT32_C(   798750944), -INT32_C(  1110546218), -INT32_C(  1292723133), -INT32_C(   242882156), -INT32_C(  2091787157), -INT32_C(   732782677) },
      { -INT32_C(  1824676463), -INT32_C(   899922686),  INT32_C(  1744435601), -INT32_C(  1110546218), -INT32_C(  1292723133),  INT32_C(  1810488320),  INT32_C(  1693334200),  INT32_C(  1798848730) },
      UINT8_C( 10) },
    { UINT8_C(117),
      {  INT32_C(  1544540158), -INT32_C(  1823104870),  INT32_C(   760985352), -INT32_C(  1287340196), -INT32_C(  1584380489), -INT32_C(  1613018960), -INT32_C(   438323796),  INT32_C(   526042400) },
      {  INT32_C(   779839892), -INT32_C(  1823104870), -INT32_C(   465625720), -INT32_C(  1287340196), -INT32_C(  1584380489), -INT32_C(  1613018960), -INT32_C(   436078651),  INT32_C(  1359305916) },
      UINT8_C( 48) },
    { UINT8_C(128),
      {  INT32_C(  1095880575),  INT32_C(   543087073),  INT32_C(  1436826301),  INT32_C(    41708750), -INT32_C(    49091355),  INT32_C(   183883785), -INT32_C(  1016680002), -INT32_C(  2109527038) },
      { -INT32_C(   574384645),  INT32_C(   543087073),  INT32_C(  1436826301),  INT32_C(    41708750), -INT32_C(   202293270), -INT32_C(   704780777), -INT32_C(  1701288809), -INT32_C(  2109527038) },
      UINT8_C(128) },
    { UINT8_C(223),
      {  INT32_C(  1711398760), -INT32_C(  1945674229), -INT32_C(  1249241720), -INT32_C(    84577271),  INT32_C(  1692404839),  INT32_C(  2059958242),  INT32_C(   760633361),  INT32_C(  1275971556) },
      {  INT32_C(  1711398760), -INT32_C(  1945674229), -INT32_C(   659895857), -INT32_C(    84577271),  INT32_C(  1692404839),  INT32_C(  2059958242),  INT32_C(   760633361), -INT32_C(   849709530) },
      UINT8_C( 91) },
    { UINT8_C( 12),
      { -INT32_C(  1077481088), -INT32_C(  1870096666),  INT32_C(  1093715310),  INT32_C(  1911807081),  INT32_C(  1916935530), -INT32_C(  1026462631), -INT32_C(   751241095),  INT32_C(  1172356293) },
      { -INT32_C(  1077481088), -INT32_C(  1423668164), -INT32_C(  1158917039), -INT32_C(  1708335312),  INT32_C(  1916935530),  INT32_C(  1410916058), -INT32_C(   751241095), -INT32_C(  1159657716) },
      UINT8_C(  0) },
    { UINT8_C(229),
      {  INT32_C(  1903356493), -INT32_C(  2117745771), -INT32_C(  1436420738), -INT32_C(  1676124529), -INT32_C(   864357452),  INT32_C(  1847349319), -INT32_C(   864671509),  INT32_C(   816981218) },
      {  INT32_C(  1903356493), -INT32_C(  2117745771), -INT32_C(  1436420738), -INT32_C(  1676124529), -INT32_C(   864357452),  INT32_C(  1037074514), -INT32_C(  1962260823),  INT32_C(  2042346602) },
      UINT8_C(  5) },
    { UINT8_C( 93),
      {  INT32_C(  1120192285),  INT32_C(  1019813933), -INT32_C(  1805341428), -INT32_C(  1432977594), -INT32_C(  1305745183),  INT32_C(   821613606),  INT32_C(   468476767), -INT32_C(   109523748) },
      {  INT32_C(  1120192285),  INT32_C(  1019813933), -INT32_C(  1805341428), -INT32_C(  1432977594), -INT32_C(  1569403524),  INT32_C(   821613606), -INT32_C(  1407402288),  INT32_C(   514167946) },
      UINT8_C( 13) },
    { UINT8_C(224),
      { -INT32_C(   605737762), -INT32_C(  1824680043),  INT32_C(   824647311),  INT32_C(  1442816992),  INT32_C(   415408198), -INT32_C(  1109945695), -INT32_C(   481205954),  INT32_C(  1589846399) },
      { -INT32_C(   482760626), -INT32_C(   831097281),  INT32_C(   824647311), -INT32_C(  2016739519),  INT32_C(   415408198),  INT32_C(  1560180254), -INT32_C(   481205954), -INT32_C(  1078656399) },
      UINT8_C( 64) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i a = simde_mm256_loadu_epi32(test_vec[i].a);
    simde__m256i b = simde_mm256_loadu_epi32(test_vec[i].b);
    simde__mmask8 r = simde_mm256_mask_cmpeq_epi32_mask(test_vec[i].k1, a, b);
    simde_assert_equal_mmask8(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k1 = simde_test_x86_random_mmask8();
    simde__m256i a = simde_test_x86_random_i32x8();
    simde__m256i b = simde_mm256_mask_blend_epi32(simde_test_x86_random_mmask8(), a, simde_test_x86_random_i32x8());
    simde__mmask8 r = simde_mm256_mask_cmpeq_epi32_mask(k1, a, b);

    simde_test_x86_write_mmask8(2, k1, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_cmpeq_epi32_mask(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m512i a;
    simde__m512i b;
    simde__mmask16 r;
  } test_vec[8] = {
    { simde_mm512_set_epi32(INT32_C( 1955445938), INT32_C( 1791143901), INT32_C(-1554982337), INT32_C(-1864115653),
                            INT32_C(-1774796435), INT32_C( 1168347531), INT32_C(  660969508), INT32_C( 1153796239),
                            INT32_C(  609464964), INT32_C( 1687040663), INT32_C( -477087011), INT32_C(  309017072),
                            INT32_C(-2144421691), INT32_C(  682838279), INT32_C( 1954361304), INT32_C( 1694661655)),
      simde_mm512_set_epi32(INT32_C( 1955445938), INT32_C( 1791143901), INT32_C(-1554982337), INT32_C(-1021004514),
                            INT32_C(-1774796435), INT32_C( 1168347531), INT32_C( 1662960443), INT32_C( 1153796239),
                            INT32_C(  609464964), INT32_C(  428287860), INT32_C(  954212709), INT32_C(  309017072),
                            INT32_C(-2144421691), INT32_C( 1263291650), INT32_C( 1954361304), INT32_C( 1694661655)),
      UINT16_C(60827) },
    { simde_mm512_set_epi32(INT32_C(-1966343749), INT32_C(  200215975), INT32_C(-1192030414), INT32_C(  122433675),
                            INT32_C( 2024442800), INT32_C(-1612503082), INT32_C( -352764842), INT32_C( -964919402),
                            INT32_C(  198779956), INT32_C(-1052322954), INT32_C(-2053476283), INT32_C( 1410443780),
                            INT32_C( -220052733), INT32_C( 1401656692), INT32_C(  344284159), INT32_C(  358488145)),
      simde_mm512_set_epi32(INT32_C(-1966343749), INT32_C(  200215975), INT32_C( 1606502639), INT32_C(  122433675),
                            INT32_C( 2024442800), INT32_C( 1676122341), INT32_C( 1013297923), INT32_C( 1764819720),
                            INT32_C(-1006160158), INT32_C(  500282446), INT32_C(-2053476283), INT32_C( 1410443780),
                            INT32_C( -891361692), INT32_C( 1401656692), INT32_C(-1666424273), INT32_C(  358488145)),
      UINT16_C(55349) },
    { simde_mm512_set_epi32(INT32_C( 2029514541), INT32_C(-1405121342), INT32_C( -922299669), INT32_C(-1157312309),
                            INT32_C(  348700274), INT32_C( 1888848128), INT32_C( -909115111), INT32_C(-1689020830),
                            INT32_C( -310128293), INT32_C(-2105034529), INT32_C( 1894199289), INT32_C( -520350707),
                            INT32_C( 2077151614), INT32_C(  947639177), INT32_C(  972348424), INT32_C(  688864219)),
      simde_mm512_set_epi32(INT32_C( 2029514541), INT32_C(-1405121342), INT32_C( -922299669), INT32_C(-1157312309),
                            INT32_C( -582496350), INT32_C(  321618555), INT32_C( -707023911), INT32_C(-1689020830),
                            INT32_C(-1223923200), INT32_C( -293312096), INT32_C( 1894199289), INT32_C(  -89856908),
                            INT32_C( 2077151614), INT32_C(  947639177), INT32_C(  352633301), INT32_C( -580477735)),
      UINT16_C(61740) },
    { simde_mm512_set_epi32(INT32_C(   63224893), INT32_C( -945243939), INT32_C( 1472177104), INT32_C(-1518639341),
                            INT32_C( 1244274955), INT32_C(-1053463974), INT32_C(  207788622), INT32_C( -375726536),
                            INT32_C( -219606791), INT32_C( -871332353), INT32_C( 2036105492), INT32_C( 1465626684),
                            INT32_C(  930923741), INT32_C(-1996202276), INT32_C(  336972805), INT32_C(-1729161210)),
      simde_mm512_set_epi32(INT32_C( 1739683658), INT32_C( -945243939), INT32_C( 1472177104), INT32_C( -959740920),
                            INT32_C( 1244274955), INT32_C(  236525659), INT32_C(  207788622), INT32_C( 1159372556),
                            INT32_C( -632841040), INT32_C( -871332353), INT32_C( 2036105492), INT32_C(-1821161401),
                            INT32_C(  626098659), INT32_C(-1099705903), INT32_C( 1892226777), INT32_C(  183269504)),
      UINT16_C(27232) },
    { simde_mm512_set_epi32(INT32_C( 1660264790), INT32_C( -188014963), INT32_C( 1960568786), INT32_C(  630575470),
                            INT32_C(-1560285386), INT32_C(-1080983958), INT32_C( -186614663), INT32_C(-1365084922),
                            INT32_C( 1687374482), INT32_C( 2091712477), INT32_C( 1770300152), INT32_C( 1222615684),
                            INT32_C(  987382002), INT32_C( -869689297), INT32_C( 1381156346), INT32_C(  352829646)),
      simde_mm512_set_epi32(INT32_C( 1495188549), INT32_C( -188014963), INT32_C( -879412194), INT32_C( 1172150075),
                            INT32_C( 1163780404), INT32_C(-1080983958), INT32_C( -186614663), INT32_C(-1365084922),
                            INT32_C( 1196042729), INT32_C( 2091712477), INT32_C( 1770300152), INT32_C( 1222615684),
                            INT32_C(  987382002), INT32_C( -453542339), INT32_C(-1460537486), INT32_C( 1311735715)),
      UINT16_C(18296) },
    { simde_mm512_set_epi32(INT32_C( -830898164), INT32_C( 2065530031), INT32_C( 1849339474), INT32_C( -161498764),
                            INT32_C(  726295410), INT32_C(-1366062470), INT32_C(  110025501), INT32_C(-2061598845),
                            INT32_C(-1911113344), INT32_C(-2008355607), INT32_C( 1140427951), INT32_C( 1963231912),
                            INT32_C( 1593065931), INT32_C( 1712671682), INT32_C(-2139143015), INT32_C(  330252777)),
      simde_mm512_set_epi32(INT32_C( -830898164), INT32_C(-2132024757), INT32_C( 1102342058), INT32_C( -161498764),
                            INT32_C(-2106128090), INT32_C(  648329890), INT32_C(-1284054768), INT32_C(-2061598845),
                            INT32_C(-1911113344), INT32_C(-2008355607), INT32_C( 1715485148), INT32_C(  155412419),
                            INT32_C( 1273550758), INT32_C( 1712671682), INT32_C(-1857983881), INT32_C( 1633779150)),
      UINT16_C(37316) },
    { simde_mm512_set_epi32(INT32_C( 1956746364), INT32_C( 1930323834), INT32_C(  923874794), INT32_C(  121318212),
                            INT32_C(-1375858452), INT32_C( -462992597), INT32_C( 1495829546), INT32_C(  697040437),
                            INT32_C(  727111035), INT32_C(-2061427382), INT32_C( -815432287), INT32_C(  913775211),
                            INT32_C(-1333809472), INT32_C(  114048073), INT32_C( 1312920985), INT32_C(-1819914035)),
      simde_mm512_set_epi32(INT32_C( 1659376087), INT32_C( 1930323834), INT32_C(  923874794), INT32_C(  121318212),
                            INT32_C(-1375858452), INT32_C(-1480844812), INT32_C(-1803673478), INT32_C(  697040437),
                            INT32_C( 1793922150), INT32_C(  391658500), INT32_C( -815432287), INT32_C(  913775211),
                            INT32_C(-1333809472), INT32_C( -169359358), INT32_C(  140424991), INT32_C(-1819914035)),
      UINT16_C(31033) },
    { simde_mm512_set_epi32(INT32_C( 1334496661), INT32_C(-1765072906), INT32_C(-1980138391), INT32_C(-1150536116),
                            INT32_C( -711226926), INT32_C( 1955166809), INT32_C( 1418224832), INT32_C( 1791996583),
                            INT32_C(-1305868646), INT32_C( -507537618), INT32_C(  272749509), INT32_C(-1826072492),
                            INT32_C( -629068596), INT32_C(-2142583585), INT32_C( 2048200365), INT32_C(-1377550438)),
      simde_mm512_set_epi32(INT32_C( 1334496661), INT32_C(-1765072906), INT32_C( -890751438), INT32_C(-1150536116),
                            INT32_C(  307879329), INT32_C( 1955166809), INT32_C(-1884386825), INT32_C( 1791996583),
                            INT32_C( 1128431085), INT32_C( -507537618), INT32_C(  272749509), INT32_C( 1579228324),
                            INT32_C( 1577134581), INT32_C(-2142583585), INT32_C( 1998674783), INT32_C(-1377550438)),
      UINT16_C(54629) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__mmask16 r = simde_mm512_cmpeq_epi32_mask(test_vec[i].a, test_vec[i].b);
    simde_assert_equal_mmask16(r, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm512_mask_cmpeq_epi32_mask(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__mmask16 k;
    simde__m512i a;
    simde__m512i b;
    simde__mmask16 r;
  } test_vec[8] = {
    { UINT16_C(15798),
      simde_mm512_set_epi32(INT32_C(-1396783922), INT32_C( 2147469122), INT32_C(  245941047), INT32_C(-1608794680),
                            INT32_C( 1508622706), INT32_C( -820009589), INT32_C(-2056933337), INT32_C( 1399160559),
                            INT32_C( -781782717), INT32_C( -745938688), INT32_C( 1376412239), INT32_C(  358147007),
                            INT32_C(-2141927311), INT32_C(  -13921241), INT32_C(  993767039), INT32_C( 1399506469)),
      simde_mm512_set_epi32(INT32_C(-1396783922), INT32_C( 1246457300), INT32_C( 1479047358), INT32_C(  -46329110),
                            INT32_C( 1508622706), INT32_C( -820009589), INT32_C( 2080173402), INT32_C( 1937046285),
                            INT32_C( 1642337112), INT32_C(  717149471), INT32_C(  913865239), INT32_C(  358147007),
                            INT32_C( 1535690363), INT32_C(  -13921241), INT32_C(  993767039), INT32_C(  520030741)),
      UINT16_C( 3094) },
    { UINT16_C(11237),
      simde_mm512_set_epi32(INT32_C( -503773363), INT32_C(-1842967576), INT32_C(  214407733), INT32_C( 2136243689),
                            INT32_C(  619563347), INT32_C(-2046647578), INT32_C( -882198373), INT32_C( -832110086),
                            INT32_C(  828288790), INT32_C( 1819046419), INT32_C(  292064966), INT32_C( -747926472),
                            INT32_C( -881463995), INT32_C(-1469434386), INT32_C( -207196114), INT32_C(-1865668915)),
      simde_mm512_set_epi32(INT32_C(  261150369), INT32_C(-1842967576), INT32_C(-1148601855), INT32_C( 2136243689),
                            INT32_C(-2013121518), INT32_C(-2046647578), INT32_C(-1816537753), INT32_C( -832110086),
                            INT32_C(  828288790), INT32_C( 1801925150), INT32_C(  292064966), INT32_C(-1755078036),
                            INT32_C(-1190065823), INT32_C(  764421376), INT32_C( -207196114), INT32_C(-1865668915)),
      UINT16_C(  417) },
    { UINT16_C(   61),
      simde_mm512_set_epi32(INT32_C(  219790698), INT32_C(  346516102), INT32_C(-2082495343), INT32_C(  775700745),
                            INT32_C( -630025741), INT32_C( 1914162819), INT32_C( -226095226), INT32_C( -350619769),
                            INT32_C( 1825330894), INT32_C(  -79420124), INT32_C(  939662489), INT32_C(  667606641),
                            INT32_C(-1935137328), INT32_C(  247120548), INT32_C( -894861328), INT32_C(-1690188311)),
      simde_mm512_set_epi32(INT32_C(  400967600), INT32_C(  346516102), INT32_C(-2082495343), INT32_C(  775700745),
                            INT32_C( -630025741), INT32_C( 1914162819), INT32_C(-1771983812), INT32_C( -350619769),
                            INT32_C( 1825330894), INT32_C(-1887033010), INT32_C(  939662489), INT32_C( -440942769),
                            INT32_C(-1935137328), INT32_C(  247120548), INT32_C(-1352163534), INT32_C(-1690188311)),
      UINT16_C(   45) },
    { UINT16_C(40799),
      simde_mm512_set_epi32(INT32_C(-1103261115), INT32_C(-1530092257), INT32_C( -178076517), INT32_C( 1725180044),
                            INT32_C( -619562554), INT32_C(-2028225116), INT32_C( -516465044), INT32_C( -790492311),
                            INT32_C(  770588317), INT32_C(  966229539), INT32_C( 1696981823), INT32_C( 1846986452),
                            INT32_C(  201003704), INT32_C(  -88144749), INT32_C( -459260562), INT32_C(-1462493092)),
      simde_mm512_set_epi32(INT32_C(-1103261115), INT32_C(-1530092257), INT32_C( 1272329003), INT32_C( 1725180044),
                            INT32_C(-1714282865), INT32_C( 1964019033), INT32_C(   -6888948), INT32_C( -794446809),
                            INT32_C(  770588317), INT32_C(  966229539), INT32_C(-1587543669), INT32_C( 1846986452),
                            INT32_C(  201003704), INT32_C(  -88144749), INT32_C(-1549459108), INT32_C(-1462493092)),
      UINT16_C(36957) },
    { UINT16_C(18708),
      simde_mm512_set_epi32(INT32_C( 1654168369), INT32_C(-1358646009), INT32_C(  945188582), INT32_C( 1242452940),
                            INT32_C(-2068238117), INT32_C(  613827224), INT32_C( 1766050173), INT32_C(  788865946),
                            INT32_C( -226150288), INT32_C(   20626714), INT32_C(-1790747056), INT32_C(-1510999017),
                            INT32_C(-2059568770), INT32_C(  525242273), INT32_C(-1970979230), INT32_C( -983788353)),
      simde_mm512_set_epi32(INT32_C(-1802152524), INT32_C(-1358646009), INT32_C( 1400410557), INT32_C( 1242452940),
                            INT32_C(-2068238117), INT32_C(-1745049433), INT32_C(-1272787498), INT32_C(   36641197),
                            INT32_C( -226150288), INT32_C(-2087200149), INT32_C( -530182364), INT32_C(-1510999017),
                            INT32_C(-2082577633), INT32_C(  525242273), INT32_C(-1970979230), INT32_C( -983788353)),
      UINT16_C(18452) },
    { UINT16_C(48938),
      simde_mm512_set_epi32(INT32_C(-1802886705), INT32_C(  505130099), INT32_C( 1294359394), INT32_C(  564426410),
                            INT32_C( -813242663), INT32_C(-1097324530), INT32_C( 1599346411), INT32_C(-1815738445),
                            INT32_C( 2114996332), INT32_C( 2143192037), INT32_C(  342894910), INT32_C( 1933006347),
                            INT32_C(  215936041), INT32_C( 2138148935), INT32_C(-1975112588), INT32_C(-1313889253)),
      simde_mm512_set_epi32(INT32_C( 1272515820), INT32_C(-1571014987), INT32_C( 1294359394), INT32_C(  564426410),
                            INT32_C( -305474417), INT32_C(-2099686495), INT32_C(  217917259), INT32_C( 1770631752),
                            INT32_C( 2114996332), INT32_C( 2143192037), INT32_C(  -26985081), INT32_C(  603877714),
                            INT32_C( 1592556524), INT32_C(  420570241), INT32_C(-1975112588), INT32_C(-1313889253)),
      UINT16_C(12290) },
    { UINT16_C(14127),
      simde_mm512_set_epi32(INT32_C(  452796731), INT32_C( -256668338), INT32_C(-1710549095), INT32_C( 1982965424),
                            INT32_C( 1184306045), INT32_C( -221254467), INT32_C( 1420239721), INT32_C( 2028887361),
                            INT32_C(-1950932361), INT32_C( 1650853943), INT32_C(  239751123), INT32_C( 1018010808),
                            INT32_C( -248946240), INT32_C(  701510715), INT32_C(  824235240), INT32_C( 1829156606)),
      simde_mm512_set_epi32(INT32_C(  452796731), INT32_C( 1031814185), INT32_C(-1710549095), INT32_C(  406415467),
                            INT32_C( 1184306045), INT32_C( -221254467), INT32_C(  419739010), INT32_C( 1708161231),
                            INT32_C(-1950932361), INT32_C( 1650853943), INT32_C(  239751123), INT32_C( 1018010808),
                            INT32_C( -248946240), INT32_C(  701510715), INT32_C(-1571248435), INT32_C( 1829156606)),
      UINT16_C( 9261) },
    { UINT16_C(22801),
      simde_mm512_set_epi32(INT32_C( 1869800572), INT32_C(  184060195), INT32_C(   81710208), INT32_C( -451284065),
                            INT32_C(  397153235), INT32_C(  120564446), INT32_C(-2128920097), INT32_C( 1498011427),
                            INT32_C( -602736654), INT32_C( -931955343), INT32_C(  270436915), INT32_C( -984637478),
                            INT32_C( 2080482721), INT32_C( 1599947836), INT32_C(  374268618), INT32_C(  202341051)),
      simde_mm512_set_epi32(INT32_C( 1869800572), INT32_C(  350721255), INT32_C( 1725621650), INT32_C( 2020045509),
                            INT32_C(  397153235), INT32_C( 2059505832), INT32_C(-2128920097), INT32_C( 1498011427),
                            INT32_C(  884679844), INT32_C( -931955343), INT32_C(-1565261303), INT32_C( -984637478),
                            INT32_C( 1047792745), INT32_C(  969830078), INT32_C(  374268618), INT32_C(  202341051)),
      UINT16_C( 2321) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__mmask16 r = simde_mm512_mask_cmpeq_epi32_mask(test_vec[i].k, test_vec[i].a, test_vec[i].b);
    simde_assert_equal_mmask16(HEDLEY_STATIC_CAST(uint16_t, r), HEDLEY_STATIC_CAST(uint16_t, test_vec[i].r));
  }

  return 0;
}

static int
test_simde_mm_cmpeq_epi64_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int64_t a[2];
    const int64_t b[2];
    const simde__mmask8 r;
  } test_vec[] = {
    { {  INT64_C( 2827975768376412674), -INT64_C( 3979757541337846042) },
      {  INT64_C( 2827975768376412674), -INT64_C( 3979757541337846042) },
      UINT8_C(  3) },
    { {  INT64_C( 5839234822378808359), -INT64_C(   75518995927983486) },
      {  INT64_C( 5839234822378808359), -INT64_C(   75518995927983486) },
      UINT8_C(  3) },
    { {  INT64_C( 8662260873625556370),  INT64_C( 3179073748772374387) },
      { -INT64_C( 8705502994081794013),  INT64_C( 3179073748772374387) },
      UINT8_C(  2) },
    { { -INT64_C( 6629878250707835646), -INT64_C(  377587399999478968) },
      { -INT64_C( 6629878250707835646), -INT64_C(  377587399999478968) },
      UINT8_C(  3) },
    { { -INT64_C( 4771076057957098096),  INT64_C( 8850973129225234457) },
      { -INT64_C( 4771076057957098096),  INT64_C( 8850973129225234457) },
      UINT8_C(  3) },
    { {  INT64_C( 6315678282164348369), -INT64_C(  369580914616678197) },
      {  INT64_C( 6315678282164348369),  INT64_C( 2677760873420593886) },
      UINT8_C(  1) },
    { { -INT64_C( 6931394595059814089),  INT64_C( 1239254544441709119) },
      { -INT64_C( 6931394595059814089),  INT64_C( 3367453329867394547) },
      UINT8_C(  1) },
    { { -INT64_C( 7990440171182935776), -INT64_C(  877616391425730307) },
      { -INT64_C( 1081539959737218110), -INT64_C(  877616391425730307) },
      UINT8_C(  2) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i a = simde_mm_loadu_epi64(test_vec[i].a);
    simde__m128i b = simde_mm_loadu_epi64(test_vec[i].b);
    simde__mmask8 r = simde_mm_cmpeq_epi64_mask(a, b);
    simde_assert_equal_mmask8(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i a = simde_test_x86_random_i64x2();
    simde__m128i b = simde_mm_mask_blend_epi64(simde_test_x86_random_mmask8(), a, simde_test_x86_random_i64x2());
    simde__mmask8 r = simde_mm_cmpeq_epi64_mask(a, b);

    simde_test_x86_write_i64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_mask_cmpeq_epi64_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k1;
    const int64_t a[2];
    const int64_t b[2];
    const simde__mmask8 r;
  } test_vec[] = {
    { UINT8_C(144),
      { -INT64_C( 2850833719696014086),  INT64_C( 7304750550190193025) },
      {  INT64_C( 6482661676419023544),  INT64_C(  805778267304752047) },
      UINT8_C(  0) },
    {    UINT8_MAX,
      { -INT64_C( 7887405320068346590), -INT64_C( 2772815652027533662) },
      { -INT64_C( 4784349683816073553), -INT64_C( 2772815652027533662) },
      UINT8_C(  2) },
    { UINT8_C( 43),
      { -INT64_C( 5807361560460797080),  INT64_C(   42599601477862173) },
      {  INT64_C( 1460226915428460543),  INT64_C( 4156735390691883300) },
      UINT8_C(  0) },
    { UINT8_C( 40),
      {  INT64_C( 5897289613734902059), -INT64_C( 8682754313066777598) },
      { -INT64_C( 5440787911760206783), -INT64_C( 8682754313066777598) },
      UINT8_C(  0) },
    { UINT8_C( 15),
      { -INT64_C( 8425545637357907641), -INT64_C( 2760577320775055861) },
      {  INT64_C(  128137761428990458),  INT64_C( 5240459342120046303) },
      UINT8_C(  0) },
    { UINT8_C( 41),
      {  INT64_C(  972960972490362215),  INT64_C( 3444266245644487986) },
      {  INT64_C( 6632477798033025525), -INT64_C( 4839220785707610891) },
      UINT8_C(  0) },
    { UINT8_C(114),
      {  INT64_C( 6396039277034653749),  INT64_C( 5000063048876402990) },
      {  INT64_C( 6396039277034653749), -INT64_C( 1910386407822396621) },
      UINT8_C(  0) },
    { UINT8_C(148),
      { -INT64_C( 4897930782378586214), -INT64_C( 5388541400284930041) },
      { -INT64_C( 4897930782378586214),  INT64_C( 7027708643817939319) },
      UINT8_C(  0) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i a = simde_mm_loadu_epi64(test_vec[i].a);
    simde__m128i b = simde_mm_loadu_epi64(test_vec[i].b);
    simde__mmask8 r = simde_mm_mask_cmpeq_epi64_mask(test_vec[i].k1, a, b);
    simde_assert_equal_mmask8(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k1 = simde_test_x86_random_mmask8();
    simde__m128i a = simde_test_x86_random_i64x2();
    simde__m128i b = simde_mm_mask_blend_epi64(simde_test_x86_random_mmask8(), a, simde_test_x86_random_i64x2());
    simde__mmask8 r = simde_mm_mask_cmpeq_epi64_mask(k1, a, b);

    simde_test_x86_write_mmask8(2, k1, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i64x2(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_cmpeq_epi64_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int64_t a[4];
    const int64_t b[4];
    const simde__mmask8 r;
  } test_vec[] = {
    { { -INT64_C( 6522159191385784729), -INT64_C( 9162715149100194263),  INT64_C( 2998558734336202425),  INT64_C( 9162381131133259962) },
      { -INT64_C( 2775783415026086641),  INT64_C( 9148192673554842966),  INT64_C( 2998558734336202425),  INT64_C( 9162381131133259962) },
      UINT8_C( 12) },
    { {  INT64_C( 6134707607132411229), -INT64_C( 4479789102478551059), -INT64_C( 1490425895226434756),  INT64_C(  119447251006012175) },
      {  INT64_C( 6134707607132411229),  INT64_C( 4959623209185669255), -INT64_C( 1490425895226434756), -INT64_C( 7209190249670947763) },
      UINT8_C(  5) },
    { {  INT64_C( 7221934270795849153), -INT64_C( 1001012832597422911), -INT64_C( 2390700492608708238),  INT64_C( 8788249898618700973) },
      {  INT64_C( 7221934270795849153), -INT64_C( 1001012832597422911), -INT64_C( 2390700492608708238), -INT64_C( 1876839795059522365) },
      UINT8_C(  7) },
    { {  INT64_C( 3690337809652422688),  INT64_C( 5044330434874837447),  INT64_C( 2449099604223238203), -INT64_C( 8334988166976538852) },
      {  INT64_C( 3690337809652422688),  INT64_C( 6441359258311003984), -INT64_C( 5030925829042623761), -INT64_C( 8334988166976538852) },
      UINT8_C(  9) },
    { { -INT64_C( 7951086990119151088), -INT64_C( 3054837843350206883),  INT64_C( 5418724070742206364), -INT64_C( 5362569286295640541) },
      { -INT64_C( 5097594993023104210), -INT64_C( 3054837843350206883),  INT64_C( 5418724070742206364),  INT64_C( 4032478725834192284) },
      UINT8_C(  6) },
    { {  INT64_C( 1887746191054464771),  INT64_C( 4444397871262193412), -INT64_C( 6340062276315895184),  INT64_C( 4468952072417526844) },
      {  INT64_C( 1887746191054464771),  INT64_C( 4867616949063002110), -INT64_C( 6340062276315895184),  INT64_C( 7956226251414157041) },
      UINT8_C(  5) },
    { { -INT64_C( 6951815680569940384),  INT64_C( 5074068462233703874), -INT64_C( 9007358907034843296), -INT64_C(  655396243414897765) },
      {  INT64_C( 8939086409646312182),  INT64_C( 5074068462233703874),  INT64_C( 5187484506011352494), -INT64_C(  655396243414897765) },
      UINT8_C( 10) },
    { { -INT64_C( 6577864447312849702), -INT64_C( 5634438045989277128),  INT64_C( 7246472419909388314),  INT64_C( 3258555900517086904) },
      {  INT64_C( 7679412739106305995), -INT64_C( 5634438045989277128), -INT64_C( 7977479291170704224),  INT64_C( 3258555900517086904) },
      UINT8_C( 10) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i a = simde_mm256_loadu_epi64(test_vec[i].a);
    simde__m256i b = simde_mm256_loadu_epi64(test_vec[i].b);
    simde__mmask8 r = simde_mm256_cmpeq_epi64_mask(a, b);
    simde_assert_equal_mmask8(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m256i a = simde_test_x86_random_i64x4();
    simde__m256i b = simde_mm256_mask_blend_epi64(simde_test_x86_random_mmask8(), a, simde_test_x86_random_i64x4());
    simde__mmask8 r = simde_mm256_cmpeq_epi64_mask(a, b);

    simde_test_x86_write_i64x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i64x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_mask_cmpeq_epi64_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k1;
    const int64_t a[4];
    const int64_t b[4];
    const simde__mmask8 r;
  } test_vec[] = {
    { UINT8_C(205),
      {  INT64_C( 2075387100211849165),  INT64_C( 7598721205607379048),  INT64_C( 2567607995608747514),  INT64_C( 7070535503780623759) },
      {  INT64_C( 6299286761805819581), -INT64_C( 1273098173092995265),  INT64_C( 2567607995608747514),  INT64_C( 7070535503780623759) },
      UINT8_C( 12) },
    { UINT8_C( 65),
      { -INT64_C( 7932791702055509346), -INT64_C(  117950336150479365), -INT64_C( 2774397739678408662), -INT64_C(  199968867058052999) },
      {  INT64_C( 1423118894402767156), -INT64_C(  117950336150479365), -INT64_C( 2774397739678408662), -INT64_C( 7860347746124378994) },
      UINT8_C(  0) },
    { UINT8_C(240),
      {  INT64_C(  710069718079279552), -INT64_C( 6898131843543389884),  INT64_C( 8987122477026904318),  INT64_C( 7526470077196736153) },
      {  INT64_C(  710069718079279552),  INT64_C( 6065613496523910634),  INT64_C( 8987122477026904318),  INT64_C( 8367837085978269967) },
      UINT8_C(  0) },
    { UINT8_C(  8),
      {  INT64_C( 4476776077859609103),  INT64_C(  845004146982680129),  INT64_C( 6126888095754531264),  INT64_C(  645342930669438412) },
      {  INT64_C( 4476776077859609103),  INT64_C(  845004146982680129),  INT64_C(  946974463282195853),  INT64_C( 5322391337242788314) },
      UINT8_C(  0) },
    { UINT8_C(151),
      { -INT64_C(  974248864016818438), -INT64_C( 4235816353383179806),  INT64_C( 9173818719843481642),  INT64_C( 5420672939918690247) },
      {  INT64_C( 6123398448150785335),  INT64_C( 5549725718958557383),  INT64_C( 9173818719843481642),  INT64_C( 5420672939918690247) },
      UINT8_C(  4) },
    { UINT8_C(195),
      { -INT64_C( 8531163312536037928), -INT64_C( 6298233447737475209), -INT64_C(  263593061457286717), -INT64_C( 7413745491387420469) },
      {  INT64_C( 4439714454496382698), -INT64_C( 5873730840198332985),  INT64_C( 7095663756092707066), -INT64_C( 7413745491387420469) },
      UINT8_C(  0) },
    { UINT8_C(147),
      {  INT64_C( 2492850604840004926), -INT64_C( 5205479254288858058),  INT64_C( 8613803595194915304),  INT64_C( 3506254560258738669) },
      { -INT64_C( 2562367153792859164),  INT64_C( 3968322523435557416),  INT64_C( 8613803595194915304),  INT64_C( 3506254560258738669) },
      UINT8_C(  0) },
    { UINT8_C( 25),
      {  INT64_C(  245136622150850836), -INT64_C( 8936833893599562431), -INT64_C(  331420347236286624),  INT64_C( 2490945853903816811) },
      {  INT64_C(  245136622150850836), -INT64_C( 8936833893599562431), -INT64_C(  331420347236286624),  INT64_C( 3566246144932076364) },
      UINT8_C(  1) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i a = simde_mm256_loadu_epi64(test_vec[i].a);
    simde__m256i b = simde_mm256_loadu_epi64(test_vec[i].b);
    simde__mmask8 r = simde_mm256_mask_cmpeq_epi64_mask(test_vec[i].k1, a, b);
    simde_assert_equal_mmask8(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k1 = simde_test_x86_random_mmask8();
    simde__m256i a = simde_test_x86_random_i64x4();
    simde__m256i b = simde_mm256_mask_blend_epi64(simde_test_x86_random_mmask8(), a, simde_test_x86_random_i64x4());
    simde__mmask8 r = simde_mm256_mask_cmpeq_epi64_mask(k1, a, b);

    simde_test_x86_write_mmask8(2, k1, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i64x4(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_cmpeq_epi64_mask(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m512i a;
    simde__m512i b;
    simde__mmask8 r;
  } test_vec[8] = {
    { simde_mm512_set_epi64(INT64_C( 1145569124203592220), INT64_C( 8866992319046943109),
                            INT64_C( 1920152028348566704), INT64_C( 5434169962120345100),
                            INT64_C( 2279810443797316081), INT64_C( 8202334326145056493),
                            INT64_C(-3178237508368099649), INT64_C(  691539695110831332)),
      simde_mm512_set_epi64(INT64_C( 1145569124203592220), INT64_C( 7456258988741005047),
                            INT64_C( 1920152028348566704), INT64_C(-5531344059509930758),
                            INT64_C( 2279810443797316081), INT64_C( 4212838215119313762),
                            INT64_C(-3178237508368099649), INT64_C(  805234941373423218)),
      UINT8_C(170) },
    { simde_mm512_set_epi64(INT64_C(-9153030146845322943), INT64_C(-3269802522838954453),
                            INT64_C( 4057416377680772191), INT64_C(-4770808841142629569),
                            INT64_C(-3341852712217874901), INT64_C( 2807150139607841402),
                            INT64_C(-4019938614639236980), INT64_C(-5612844059017155926)),
      simde_mm512_set_epi64(INT64_C(-9153030146845322943), INT64_C(-3269802522838954453),
                            INT64_C( 4057416377680772191), INT64_C( -940603917401247915),
                            INT64_C(-3341852712217874901), INT64_C( 2807150139607841402),
                            INT64_C(-4019938614639236980), INT64_C(-5612844059017155926)),
      UINT8_C(239) },
    { simde_mm512_set_epi64(INT64_C(-6535160640888369935), INT64_C( 4320507985166557084),
                            INT64_C( 5472888856009482484), INT64_C(-3128657528300165720),
                            INT64_C( 7430914891859325397), INT64_C( -863913734109164798),
                            INT64_C(-7794735185814972844), INT64_C( 6163895309000776850)),
      simde_mm512_set_epi64(INT64_C(-4220461743444256802), INT64_C( 2616373937292152846),
                            INT64_C( 5472888856009482484), INT64_C(-3128657528300165720),
                            INT64_C(-4693544589206901195), INT64_C( -863913734109164798),
                            INT64_C(-7794735185814972844), INT64_C(-7914074467628930001)),
      UINT8_C( 54) },
    { simde_mm512_set_epi64(INT64_C(-2366835550617683621), INT64_C(-7526131353484035546),
                            INT64_C(  792273323175818479), INT64_C(-3293855504021481788),
                            INT64_C( 5766970185621377329), INT64_C( 8555682923177627503),
                            INT64_C( 6363802824474944219), INT64_C(-2294667848278645794)),
      simde_mm512_set_epi64(INT64_C(-2869910567061155737), INT64_C(-7526131353484035546),
                            INT64_C(  792273323175818479), INT64_C( 7002007300200137801),
                            INT64_C( 5766970185621377329), INT64_C( 8555682923177627503),
                            INT64_C( 6363802824474944219), INT64_C( 1235305386817146646)),
      UINT8_C(110) },
    { simde_mm512_set_epi64(INT64_C( 1781453983767744725), INT64_C( 8717105342239974860),
                            INT64_C(-6555437070120516632), INT64_C( -945434448901737124),
                            INT64_C( 2467182069214891728), INT64_C( 6380355612148977321),
                            INT64_C(-8948278762783625779), INT64_C( 4377995125356963906)),
      simde_mm512_set_epi64(INT64_C( 1781453983767744725), INT64_C( 8717105342239974860),
                            INT64_C(-1574265126641933862), INT64_C(-3609136820784425910),
                            INT64_C( 8413977304256335681), INT64_C(-4046135395677773903),
                            INT64_C(-8948278762783625779), INT64_C( 4377995125356963906)),
      UINT8_C(195) },
    { simde_mm512_set_epi64(INT64_C( 3163831140256245302), INT64_C(-7476767975543057611),
                            INT64_C( 4783231484571490676), INT64_C( 4356333140933542181),
                            INT64_C(-5734470250608567849), INT64_C( 5428089484060124354),
                            INT64_C( 6915844972668556704), INT64_C(-4128418267655054219)),
      simde_mm512_set_epi64(INT64_C( 3163831140256245302), INT64_C(-7945608864951271413),
                            INT64_C(-3728561425301803734), INT64_C( 6344562138072151085),
                            INT64_C(-5734470250608567849), INT64_C( 5868624435741359252),
                            INT64_C( 6915844972668556704), INT64_C(-4128418267655054219)),
      UINT8_C(139) },
    { simde_mm512_set_epi64(INT64_C(-8545152605640787948), INT64_C(-5234822620280611494),
                            INT64_C(-2932089901585751375), INT64_C( 4017618173912988951),
                            INT64_C(-8696436452927061736), INT64_C( 3602642025812661939),
                            INT64_C( 5777136991119584953), INT64_C(-5473038481952171581)),
      simde_mm512_set_epi64(INT64_C(-8545152605640787948), INT64_C(-7808252369899371159),
                            INT64_C(-2932089901585751375), INT64_C(  -26139149052321087),
                            INT64_C(-6986660196527912755), INT64_C( 3602642025812661939),
                            INT64_C( 5777136991119584953), INT64_C(-5473038481952171581)),
      UINT8_C(167) },
    { simde_mm512_set_epi64(INT64_C( 7780170108497689334), INT64_C(-8001282944915881932),
                            INT64_C(  382835809361431399), INT64_C(-5014881555296189468),
                            INT64_C(-1844642447215154571), INT64_C(-5452282829002750089),
                            INT64_C(-7793611854809744260), INT64_C(  938166230586687295)),
      simde_mm512_set_epi64(INT64_C( 7780170108497689334), INT64_C( 1739290942316187796),
                            INT64_C( 7815402837606564081), INT64_C(-5014881555296189468),
                            INT64_C(-1844642447215154571), INT64_C( -253128228754997390),
                            INT64_C(-7793611854809744260), INT64_C(  938166230586687295)),
      UINT8_C(155) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__mmask8 r = simde_mm512_cmpeq_epi64_mask(test_vec[i].a, test_vec[i].b);
    simde_assert_equal_mmask8(r, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm512_mask_cmpeq_epi64_mask(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__mmask8 k;
    simde__m512i a;
    simde__m512i b;
    simde__mmask8 r;
  } test_vec[8] = {
       { UINT8_C( 90),
      simde_mm512_set_epi64(INT64_C( 7722926897436765530), INT64_C( 7338279138551748064),
                            INT64_C( 8433308126101200079), INT64_C(-4390305748733976547),
                            INT64_C(-1482589068035252753), INT64_C(-5002011091694476743),
                            INT64_C( 5809674310022718254), INT64_C( 7620249298233351482)),
      simde_mm512_set_epi64(INT64_C( 7722926897436765530), INT64_C( 7338279138551748064),
                            INT64_C(-2656726859984743367), INT64_C(-4390305748733976547),
                            INT64_C(-1482589068035252753), INT64_C(-5269390469191050553),
                            INT64_C( 5809674310022718254), INT64_C( 7620249298233351482)),
      UINT8_C( 90) },
    { UINT8_C(178),
      simde_mm512_set_epi64(INT64_C(-8806453660480970182), INT64_C(-2722914847628644365),
                            INT64_C( 2171146127585219679), INT64_C(-7200523266853707115),
                            INT64_C( 8505301695237968355), INT64_C( 6373940775215479358),
                            INT64_C( 8209357864908427195), INT64_C( -995665125730760835)),
      simde_mm512_set_epi64(INT64_C(-8806453660480970182), INT64_C(-2722914847628644365),
                            INT64_C(-1180134256156200317), INT64_C(-7200523266853707115),
                            INT64_C(-1610604796376715795), INT64_C( 5419019224867820225),
                            INT64_C( 8209357864908427195), INT64_C( -995665125730760835)),
      UINT8_C(146) },
    { UINT8_C(171),
      simde_mm512_set_epi64(INT64_C(-6245801519083893310), INT64_C(-7866373458730819532),
                            INT64_C(-5627757407772356197), INT64_C(-2425546480980122794),
                            INT64_C(-8451301604567613199), INT64_C( 1369383717682198649),
                            INT64_C( -532343328754521574), INT64_C(-1062878680437210584)),
      simde_mm512_set_epi64(INT64_C(-9163399881020056955), INT64_C(-2992244142829238392),
                            INT64_C( -213476403626539965), INT64_C(-8591297333400286921),
                            INT64_C(-8451301604567613199), INT64_C(-8139768780594538635),
                            INT64_C(-4714070518405120331), INT64_C(-1062878680437210584)),
      UINT8_C(  9) },
    { UINT8_C( 28),
      simde_mm512_set_epi64(INT64_C( 7845956693704412298), INT64_C(-5781930833336581955),
                            INT64_C( 2851517750261041799), INT64_C(-5814293521236182366),
                            INT64_C( 2292150971239308783), INT64_C( 2594053186857735013),
                            INT64_C( 7307535341641173075), INT64_C(-4427478291595527940)),
      simde_mm512_set_epi64(INT64_C(  536264388241191871), INT64_C(-5781930833336581955),
                            INT64_C( 2851517750261041799), INT64_C( 1349842462394812975),
                            INT64_C( 2292150971239308783), INT64_C( 2594053186857735013),
                            INT64_C( 7307535341641173075), INT64_C(-4427478291595527940)),
      UINT8_C( 12) },
    { UINT8_C(248),
      simde_mm512_set_epi64(INT64_C( 4900816215694077255), INT64_C(-2732029741423656661),
                            INT64_C( 1082977534221618055), INT64_C(-3092044493389993636),
                            INT64_C(-4299277917890019767), INT64_C(-2055775203132417874),
                            INT64_C( -778633101599852237), INT64_C( -563223173848121636)),
      simde_mm512_set_epi64(INT64_C( 7049304296219110648), INT64_C(-2732029741423656661),
                            INT64_C( 7088083428992159722), INT64_C(-3092044493389993636),
                            INT64_C(-4299277917890019767), INT64_C( 4225506809727089751),
                            INT64_C( -778633101599852237), INT64_C( -563223173848121636)),
      UINT8_C( 88) },
    { UINT8_C(171),
      simde_mm512_set_epi64(INT64_C(-1412821155990992029), INT64_C( 4454576651901490962),
                            INT64_C(-7284760734604447652), INT64_C(-7443130466673006479),
                            INT64_C(  320054597637804434), INT64_C(-8860872372305530355),
                            INT64_C(-8428145646879978292), INT64_C(-6547252853189215611)),
      simde_mm512_set_epi64(INT64_C(-1412821155990992029), INT64_C(-2354123670646573707),
                            INT64_C( 4506838144989822528), INT64_C(-7443130466673006479),
                            INT64_C(-5147543239321546686), INT64_C(-8860872372305530355),
                            INT64_C(-8428145646879978292), INT64_C(-6547252853189215611)),
      UINT8_C(131) },
    { UINT8_C( 29),
      simde_mm512_set_epi64(INT64_C( 5675137803130124480), INT64_C( 1211541157654985046),
                            INT64_C( 8724633375562564314), INT64_C(-2760658800846254598),
                            INT64_C(-6714474269646576270), INT64_C( 3484180661422871715),
                            INT64_C( 1469796163712815354), INT64_C(-2336393240308600160)),
      simde_mm512_set_epi64(INT64_C( 5675137803130124480), INT64_C( 1211541157654985046),
                            INT64_C(-8867413355151838495), INT64_C(-8867147959443474315),
                            INT64_C(-6714474269646576270), INT64_C( 3484180661422871715),
                            INT64_C(-7735267815657951749), INT64_C(  413036036281601883)),
      UINT8_C( 12) },
    { UINT8_C(211),
      simde_mm512_set_epi64(INT64_C(-6713502673628263139), INT64_C( 1559753162601267291),
                            INT64_C( 5045660940436454371), INT64_C( 7013290440433503154),
                            INT64_C(-8475145246816690249), INT64_C(-6834826688677600633),
                            INT64_C(-2109099044497919348), INT64_C( 1351143524438105934)),
      simde_mm512_set_epi64(INT64_C( 5625319538109918668), INT64_C( 1559753162601267291),
                            INT64_C( 5045660940436454371), INT64_C(-4654386914804892920),
                            INT64_C( 2407237530895996207), INT64_C(-6834826688677600633),
                            INT64_C( 4684210505965066200), INT64_C( 1351143524438105934)),
      UINT8_C( 65) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__mmask8 r = simde_mm512_mask_cmpeq_epi64_mask(test_vec[i].k, test_vec[i].a, test_vec[i].b);
    simde_assert_equal_mmask8(r, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_cmpeq_epu8_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const uint8_t a[16];
    const uint8_t b[16];
    const simde__mmask16 r;
  } test_vec[] = {
    { { UINT8_C( 35), UINT8_C(223), UINT8_C( 92), UINT8_C( 48), UINT8_C(144), UINT8_C(210), UINT8_C(243), UINT8_C(148),
        UINT8_C(155), UINT8_C(162), UINT8_C(149), UINT8_C( 93), UINT8_C(212), UINT8_C(247), UINT8_C( 31), UINT8_C(171) },
      { UINT8_C(148), UINT8_C(223), UINT8_C( 92), UINT8_C(151), UINT8_C(144), UINT8_C(225), UINT8_C(227), UINT8_C(223),
        UINT8_C(155), UINT8_C(162), UINT8_C(149), UINT8_C(  3), UINT8_C(212), UINT8_C(247), UINT8_C( 31), UINT8_C(222) },
      UINT16_C(30486) },
    { { UINT8_C( 15), UINT8_C(121), UINT8_C( 90), UINT8_C(  2), UINT8_C( 14), UINT8_C(245), UINT8_C(164), UINT8_C(163),
        UINT8_C( 82), UINT8_C(120), UINT8_C(154), UINT8_C(114), UINT8_C( 36), UINT8_C( 46), UINT8_C( 70), UINT8_C( 53) },
      { UINT8_C(198), UINT8_C(121), UINT8_C( 90), UINT8_C(  2), UINT8_C(170), UINT8_C( 64), UINT8_C(231), UINT8_C(131),
        UINT8_C( 68), UINT8_C(120), UINT8_C(154), UINT8_C(114), UINT8_C(129), UINT8_C( 46), UINT8_C(247), UINT8_C( 53) },
      UINT16_C(44558) },
    { { UINT8_C(146),    UINT8_MAX, UINT8_C( 70), UINT8_C( 54), UINT8_C(162), UINT8_C(153), UINT8_C(174), UINT8_C( 61),
        UINT8_C( 11), UINT8_C(210), UINT8_C(107), UINT8_C( 81), UINT8_C(  7), UINT8_C( 49), UINT8_C( 28), UINT8_C( 30) },
      { UINT8_C(146),    UINT8_MAX, UINT8_C( 70), UINT8_C( 54), UINT8_C(162), UINT8_C(153), UINT8_C(101), UINT8_C( 61),
        UINT8_C( 18), UINT8_C(210), UINT8_C(107), UINT8_C( 81), UINT8_C(  7), UINT8_C( 65), UINT8_C( 28), UINT8_C(  8) },
      UINT16_C(24255) },
    { { UINT8_C( 62), UINT8_C(226), UINT8_C( 58), UINT8_C(236), UINT8_C( 31), UINT8_C( 69), UINT8_C(191), UINT8_C(139),
        UINT8_C(151), UINT8_C(198), UINT8_C(188), UINT8_C(179), UINT8_C(228), UINT8_C(151), UINT8_C(122), UINT8_C( 67) },
      { UINT8_C( 90), UINT8_C(226), UINT8_C( 58), UINT8_C(236), UINT8_C(157), UINT8_C( 69), UINT8_C(165), UINT8_C(139),
        UINT8_C(151), UINT8_C(198), UINT8_C(188), UINT8_C( 92), UINT8_C( 35), UINT8_C(110), UINT8_C(122), UINT8_C( 67) },
      UINT16_C(51118) },
    { { UINT8_C( 77), UINT8_C(112), UINT8_C(125), UINT8_C( 12), UINT8_C(251), UINT8_C( 20), UINT8_C(211), UINT8_C(184),
        UINT8_C(200), UINT8_C(183), UINT8_C( 79), UINT8_C( 66), UINT8_C(250), UINT8_C(169), UINT8_C(  7), UINT8_C(224) },
      { UINT8_C(104), UINT8_C(112), UINT8_C(125), UINT8_C( 12), UINT8_C(146), UINT8_C(216), UINT8_C( 40), UINT8_C(193),
        UINT8_C( 52), UINT8_C( 75), UINT8_C( 47), UINT8_C( 66), UINT8_C(250), UINT8_C(128), UINT8_C(106), UINT8_C(250) },
      UINT16_C( 6158) },
    { { UINT8_C(  6), UINT8_C(236), UINT8_C(252), UINT8_C(217), UINT8_C(164), UINT8_C(196), UINT8_C(145), UINT8_C(244),
        UINT8_C(  6), UINT8_C(139), UINT8_C(157), UINT8_C( 14), UINT8_C(107), UINT8_C(  6), UINT8_C(179), UINT8_C( 67) },
      { UINT8_C(  6), UINT8_C(236), UINT8_C( 27), UINT8_C(217), UINT8_C(  6), UINT8_C(196), UINT8_C(145), UINT8_C( 54),
        UINT8_C(130), UINT8_C( 52), UINT8_C(182), UINT8_C(236), UINT8_C(107), UINT8_C(  6), UINT8_C(211), UINT8_C( 52) },
      UINT16_C(12395) },
    { { UINT8_C( 14), UINT8_C( 56), UINT8_C(147), UINT8_C(159), UINT8_C( 44), UINT8_C(154), UINT8_C( 42), UINT8_C(202),
        UINT8_C(168), UINT8_C(150), UINT8_C(208), UINT8_C( 91), UINT8_C(217), UINT8_C(227), UINT8_C(160), UINT8_C(244) },
      { UINT8_C( 31), UINT8_C(167), UINT8_C( 68), UINT8_C(159), UINT8_C( 44), UINT8_C(154), UINT8_C( 42), UINT8_C(202),
        UINT8_C(178), UINT8_C(150), UINT8_C(208), UINT8_C(134), UINT8_C(217), UINT8_C(207), UINT8_C( 85), UINT8_C( 75) },
      UINT16_C( 5880) },
    { { UINT8_C(234), UINT8_C( 52), UINT8_C(131), UINT8_C( 21), UINT8_C(254), UINT8_C( 43), UINT8_C(171), UINT8_C(206),
        UINT8_C(134), UINT8_C(132), UINT8_C(177), UINT8_C( 38), UINT8_C(120), UINT8_C(209), UINT8_C(205), UINT8_C(189) },
      { UINT8_C(120), UINT8_C(170), UINT8_C(131), UINT8_C( 21), UINT8_C(254), UINT8_C( 43), UINT8_C(171), UINT8_C(121),
        UINT8_C(188), UINT8_C(132), UINT8_C( 72), UINT8_C( 17), UINT8_C(229), UINT8_C( 79), UINT8_C(250), UINT8_C(189) },
      UINT16_C(33404) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i a = simde_x_mm_loadu_epu8(test_vec[i].a);
    simde__m128i b = simde_x_mm_loadu_epu8(test_vec[i].b);
    simde__mmask16 r = simde_mm_cmpeq_epu8_mask(a, b);
    simde_assert_equal_mmask16(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i a = simde_test_x86_random_u8x16();
    simde__m128i b = simde_x_mm_mask_blend_epu8(simde_test_x86_random_mmask16(), a, simde_test_x86_random_u8x16());
    simde__mmask16 r = simde_mm_cmpeq_epu8_mask(a, b);

    simde_test_x86_write_u8x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_u8x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_mask_cmpeq_epu8_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask16 k1;
    const uint8_t a[16];
    const uint8_t b[16];
    const simde__mmask16 r;
  } test_vec[] = {
    { UINT16_C(33252),
      { UINT8_C(168), UINT8_C(143), UINT8_C( 79), UINT8_C( 46), UINT8_C( 19), UINT8_C(  1), UINT8_C( 85), UINT8_C(140),
        UINT8_C(210), UINT8_C( 34), UINT8_C( 73), UINT8_C( 74), UINT8_C(205), UINT8_C(204), UINT8_C(157), UINT8_C( 11) },
      { UINT8_C(  2), UINT8_C(249), UINT8_C( 79), UINT8_C(190), UINT8_C(146), UINT8_C(204), UINT8_C( 85), UINT8_C(119),
        UINT8_C(210), UINT8_C( 34), UINT8_C( 73), UINT8_C( 74), UINT8_C( 72), UINT8_C( 43), UINT8_C( 32), UINT8_C( 11) },
      UINT16_C(33092) },
    { UINT16_C(52767),
      { UINT8_C(113), UINT8_C(116), UINT8_C( 90), UINT8_C( 67), UINT8_C(150), UINT8_C(163), UINT8_C(141), UINT8_C( 99),
        UINT8_C(112), UINT8_C( 42), UINT8_C(110), UINT8_C(114), UINT8_C( 35), UINT8_C(242), UINT8_C( 49), UINT8_C(181) },
      { UINT8_C(190), UINT8_C(  1), UINT8_C( 45), UINT8_C( 67), UINT8_C(203), UINT8_C(163), UINT8_C(141), UINT8_C( 19),
        UINT8_C(159), UINT8_C(153), UINT8_C(110), UINT8_C(114), UINT8_C( 35), UINT8_C(242), UINT8_C( 49), UINT8_C(122) },
      UINT16_C(19464) },
    { UINT16_C(11709),
      { UINT8_C( 39), UINT8_C( 74), UINT8_C(145), UINT8_C(151), UINT8_C(116),    UINT8_MAX, UINT8_C(  9), UINT8_C(151),
        UINT8_C(242), UINT8_C( 58), UINT8_C( 77), UINT8_C(176), UINT8_C( 59), UINT8_C(122), UINT8_C(138), UINT8_C(  7) },
      { UINT8_C(238), UINT8_C( 74), UINT8_C(145), UINT8_C(141), UINT8_C(116), UINT8_C( 30), UINT8_C(  9), UINT8_C(151),
        UINT8_C( 65), UINT8_C( 17), UINT8_C( 33), UINT8_C(176), UINT8_C(148), UINT8_C(122), UINT8_C(138), UINT8_C(187) },
      UINT16_C(10388) },
    { UINT16_C(40274),
      { UINT8_C(150), UINT8_C( 92), UINT8_C( 53), UINT8_C(136), UINT8_C(150), UINT8_C(130), UINT8_C( 57), UINT8_C(210),
        UINT8_C(252), UINT8_C(195), UINT8_C(217), UINT8_C(234), UINT8_C(199), UINT8_C(243), UINT8_C(119), UINT8_C(100) },
      { UINT8_C( 18), UINT8_C( 95), UINT8_C( 10), UINT8_C( 83), UINT8_C(150), UINT8_C( 43), UINT8_C( 44), UINT8_C(210),
        UINT8_C( 10), UINT8_C(195), UINT8_C(192), UINT8_C(234), UINT8_C(199), UINT8_C(243), UINT8_C(119), UINT8_C(100) },
      UINT16_C(38928) },
    { UINT16_C( 1512),
      { UINT8_C(135), UINT8_C( 33), UINT8_C(215), UINT8_C(131), UINT8_C(228), UINT8_C(176), UINT8_C(109), UINT8_C(171),
        UINT8_C(164), UINT8_C(229), UINT8_C( 15), UINT8_C(182), UINT8_C( 68), UINT8_C( 26), UINT8_C(  9), UINT8_C(181) },
      { UINT8_C( 69), UINT8_C( 33), UINT8_C(215), UINT8_C( 79), UINT8_C(103), UINT8_C(176), UINT8_C(109), UINT8_C( 48),
        UINT8_C(141), UINT8_C(229), UINT8_C( 15), UINT8_C(252), UINT8_C( 88), UINT8_C( 26), UINT8_C(  2), UINT8_C(224) },
      UINT16_C( 1120) },
    { UINT16_C(32099),
      { UINT8_C(138), UINT8_C(209), UINT8_C( 41), UINT8_C( 46), UINT8_C(182), UINT8_C( 56), UINT8_C(228), UINT8_C(250),
        UINT8_C( 82), UINT8_C(237), UINT8_C(175), UINT8_C(152), UINT8_C( 35), UINT8_C(105), UINT8_C(231), UINT8_C(138) },
      { UINT8_C(138), UINT8_C(106), UINT8_C( 41), UINT8_C(113), UINT8_C(182), UINT8_C( 75), UINT8_C(228), UINT8_C(250),
        UINT8_C( 82), UINT8_C(112), UINT8_C(175), UINT8_C(152), UINT8_C( 35), UINT8_C(105), UINT8_C(231), UINT8_C(138) },
      UINT16_C(32065) },
    { UINT16_C(57345),
      { UINT8_C( 59), UINT8_C(229), UINT8_C(218), UINT8_C(141), UINT8_C(211), UINT8_C(138), UINT8_C( 37), UINT8_C(246),
        UINT8_C(243), UINT8_C( 13), UINT8_C(128), UINT8_C(215), UINT8_C(119), UINT8_C( 59), UINT8_C( 73), UINT8_C( 52) },
      { UINT8_C(134), UINT8_C(183), UINT8_C(218), UINT8_C( 73), UINT8_C(211), UINT8_C( 63), UINT8_C( 37), UINT8_C(246),
        UINT8_C(243), UINT8_C( 13), UINT8_C( 68), UINT8_C(194), UINT8_C(129), UINT8_C( 69), UINT8_C(162), UINT8_C( 52) },
      UINT16_C(32768) },
    { UINT16_C(65098),
      { UINT8_C(  6), UINT8_C(111), UINT8_C(244), UINT8_C(250), UINT8_C(124), UINT8_C(116), UINT8_C(209), UINT8_C(243),
        UINT8_C(176), UINT8_C( 26), UINT8_C( 39), UINT8_C( 54), UINT8_C(209), UINT8_C(113), UINT8_C(128), UINT8_C(248) },
      { UINT8_C(  6), UINT8_C(111), UINT8_C(105), UINT8_C( 72), UINT8_C(164), UINT8_C(116), UINT8_C(209), UINT8_C( 38),
        UINT8_C(242), UINT8_C(172), UINT8_C(226), UINT8_C( 29), UINT8_C(209), UINT8_C(113), UINT8_C(128), UINT8_C(248) },
      UINT16_C(61506) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i a = simde_x_mm_loadu_epu8(test_vec[i].a);
    simde__m128i b = simde_x_mm_loadu_epu8(test_vec[i].b);
    simde__mmask16 r = simde_mm_mask_cmpeq_epu8_mask(test_vec[i].k1, a, b);
    simde_assert_equal_mmask16(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask16 k1 = simde_test_x86_random_mmask16();
    simde__m128i a = simde_test_x86_random_u8x16();
    simde__m128i b = simde_x_mm_mask_blend_epu8(simde_test_x86_random_mmask16(), a, simde_test_x86_random_u8x16());
    simde__mmask16 r = simde_mm_mask_cmpeq_epu8_mask(k1, a, b);

    simde_test_x86_write_mmask16(2, k1, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_u8x16(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_u8x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_cmpeq_epu8_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const uint8_t a[32];
    const uint8_t b[32];
    const simde__mmask32 r;
  } test_vec[] = {
    { { UINT8_C( 41), UINT8_C( 24), UINT8_C(132), UINT8_C(250), UINT8_C( 12), UINT8_C( 52), UINT8_C( 21), UINT8_C( 51),
        UINT8_C(106), UINT8_C(230), UINT8_C(164), UINT8_C(234), UINT8_C(223), UINT8_C( 84), UINT8_C( 16), UINT8_C( 72),
        UINT8_C(156), UINT8_C(180), UINT8_C(245), UINT8_C(166), UINT8_C(218), UINT8_C(231), UINT8_C( 82), UINT8_C(189),
        UINT8_C(  5), UINT8_C(123), UINT8_C(233), UINT8_C( 32), UINT8_C(170), UINT8_C(133), UINT8_C( 48), UINT8_C(211) },
      { UINT8_C( 41), UINT8_C(180), UINT8_C(205), UINT8_C(250), UINT8_C(232), UINT8_C( 52), UINT8_C(221), UINT8_C( 82),
        UINT8_C(201), UINT8_C(230), UINT8_C(164), UINT8_C(234), UINT8_C(214), UINT8_C( 77), UINT8_C( 16), UINT8_C( 72),
        UINT8_C(156), UINT8_C(180), UINT8_C(245), UINT8_C(166), UINT8_C(218), UINT8_C(231), UINT8_C( 82), UINT8_C(189),
        UINT8_C(  5), UINT8_C(123), UINT8_C(233), UINT8_C( 32), UINT8_C(170), UINT8_C(133), UINT8_C( 48), UINT8_C(211) },
      UINT32_C(4294954537) },
    { { UINT8_C( 80), UINT8_C(190), UINT8_C( 20), UINT8_C( 45), UINT8_C( 16), UINT8_C(221), UINT8_C(175), UINT8_C( 77),
        UINT8_C(133), UINT8_C(134), UINT8_C(154), UINT8_C(117), UINT8_C(249), UINT8_C(156), UINT8_C( 90), UINT8_C( 18),
        UINT8_C(120), UINT8_C( 38), UINT8_C(126), UINT8_C( 17), UINT8_C(248), UINT8_C(101), UINT8_C(147), UINT8_C(234),
        UINT8_C(246), UINT8_C(155), UINT8_C( 12), UINT8_C( 90), UINT8_C( 65), UINT8_C(226), UINT8_C(140), UINT8_C(145) },
      { UINT8_C(160), UINT8_C(190), UINT8_C( 20), UINT8_C( 45), UINT8_C( 16), UINT8_C(110), UINT8_C(254), UINT8_C( 77),
        UINT8_C(133), UINT8_C(152), UINT8_C(119), UINT8_C(237), UINT8_C( 52), UINT8_C(209), UINT8_C(  0), UINT8_C( 18),
        UINT8_C(120), UINT8_C( 38), UINT8_C(126), UINT8_C( 17), UINT8_C(248), UINT8_C(101), UINT8_C(147), UINT8_C(234),
        UINT8_C(246), UINT8_C(155), UINT8_C( 12), UINT8_C( 90), UINT8_C( 65), UINT8_C(226), UINT8_C(140), UINT8_C(145) },
      UINT32_C(4294934942) },
    { { UINT8_C( 24), UINT8_C(222), UINT8_C(237), UINT8_C( 22), UINT8_C(224), UINT8_C(225), UINT8_C(174), UINT8_C( 87),
        UINT8_C(207), UINT8_C(227), UINT8_C( 40), UINT8_C(207), UINT8_C(143), UINT8_C( 31), UINT8_C( 77), UINT8_C( 77),
        UINT8_C( 15), UINT8_C( 49), UINT8_C(158), UINT8_C(232), UINT8_C( 12), UINT8_C(138), UINT8_C(206), UINT8_C( 65),
        UINT8_C(184), UINT8_C(149), UINT8_C(  2), UINT8_C(120), UINT8_C(253), UINT8_C( 99), UINT8_C(246), UINT8_C( 21) },
      { UINT8_C( 24), UINT8_C(222), UINT8_C( 43), UINT8_C( 33), UINT8_C(224), UINT8_C(225), UINT8_C(120), UINT8_C(148),
        UINT8_C(188), UINT8_C(160), UINT8_C( 99), UINT8_C(207), UINT8_C(191), UINT8_C( 31), UINT8_C(153), UINT8_C( 77),
        UINT8_C( 15), UINT8_C( 49), UINT8_C(158), UINT8_C(232), UINT8_C( 12), UINT8_C(138), UINT8_C(206), UINT8_C( 65),
        UINT8_C(184), UINT8_C(149), UINT8_C(  2), UINT8_C(120), UINT8_C(253), UINT8_C( 99), UINT8_C(246), UINT8_C( 21) },
      UINT32_C(4294944819) },
    { { UINT8_C(246), UINT8_C(145), UINT8_C( 49), UINT8_C(110), UINT8_C( 37), UINT8_C(237), UINT8_C( 14), UINT8_C(136),
        UINT8_C( 57), UINT8_C(205), UINT8_C( 56), UINT8_C(210), UINT8_C(156), UINT8_C( 26), UINT8_C(  9), UINT8_C( 83),
        UINT8_C(  8), UINT8_C(203), UINT8_C(216), UINT8_C( 55), UINT8_C( 69), UINT8_C(242), UINT8_C(104), UINT8_C( 55),
        UINT8_C( 10), UINT8_C(252), UINT8_C( 31), UINT8_C( 54), UINT8_C(209), UINT8_C(235), UINT8_C(142), UINT8_C(199) },
      { UINT8_C(246), UINT8_C(145), UINT8_C( 49), UINT8_C(161), UINT8_C(172), UINT8_C(237), UINT8_C( 41), UINT8_C(136),
        UINT8_C( 57), UINT8_C(205), UINT8_C( 56), UINT8_C(210), UINT8_C(124), UINT8_C(194), UINT8_C(  0), UINT8_C(133),
        UINT8_C(  8), UINT8_C(203), UINT8_C(216), UINT8_C( 55), UINT8_C( 69), UINT8_C(242), UINT8_C(104), UINT8_C( 55),
        UINT8_C( 10), UINT8_C(252), UINT8_C( 31), UINT8_C( 54), UINT8_C(209), UINT8_C(235), UINT8_C(142), UINT8_C(199) },
      UINT32_C(4294905767) },
    { { UINT8_C( 50), UINT8_C(  4), UINT8_C( 51), UINT8_C( 91), UINT8_C(234), UINT8_C( 68), UINT8_C(189), UINT8_C(163),
        UINT8_C(241), UINT8_C( 58), UINT8_C(101), UINT8_C(241), UINT8_C(191), UINT8_C(242), UINT8_C(201), UINT8_C(123),
        UINT8_C(196), UINT8_C(148), UINT8_C(160), UINT8_C(205), UINT8_C(104), UINT8_C(194), UINT8_C(245), UINT8_C(115),
        UINT8_C(181), UINT8_C(  9), UINT8_C( 12), UINT8_C(111), UINT8_C(154), UINT8_C(100), UINT8_C( 95), UINT8_C(204) },
      { UINT8_C(105), UINT8_C(147), UINT8_C( 51), UINT8_C( 91), UINT8_C(215), UINT8_C( 68), UINT8_C(246), UINT8_C(201),
        UINT8_C( 31), UINT8_C( 91), UINT8_C(101), UINT8_C(222), UINT8_C(191), UINT8_C(132), UINT8_C( 89), UINT8_C(123),
        UINT8_C(196), UINT8_C(148), UINT8_C(160), UINT8_C(205), UINT8_C(104), UINT8_C(194), UINT8_C(245), UINT8_C(115),
        UINT8_C(181), UINT8_C(  9), UINT8_C( 12), UINT8_C(111), UINT8_C(154), UINT8_C(100), UINT8_C( 95), UINT8_C(204) },
      UINT32_C(4294939692) },
    { { UINT8_C( 33), UINT8_C(170), UINT8_C( 80), UINT8_C( 24), UINT8_C(115), UINT8_C(111), UINT8_C(115), UINT8_C( 46),
        UINT8_C( 77), UINT8_C(193), UINT8_C(178), UINT8_C(166), UINT8_C(210), UINT8_C(202), UINT8_C(160), UINT8_C(177),
        UINT8_C( 74), UINT8_C( 92), UINT8_C(133), UINT8_C( 62), UINT8_C(205), UINT8_C( 98), UINT8_C( 63), UINT8_C(174),
        UINT8_C(218), UINT8_C(164), UINT8_C(238), UINT8_C( 29), UINT8_C(114), UINT8_C(193), UINT8_C(136), UINT8_C(147) },
      { UINT8_C(107), UINT8_C(216), UINT8_C( 80), UINT8_C( 24), UINT8_C(115), UINT8_C( 31), UINT8_C(115), UINT8_C(148),
        UINT8_C( 77), UINT8_C(191), UINT8_C( 59), UINT8_C(166), UINT8_C(210), UINT8_C(219), UINT8_C(160), UINT8_C(211),
        UINT8_C( 74), UINT8_C( 92), UINT8_C(133), UINT8_C( 62), UINT8_C(205), UINT8_C( 98), UINT8_C( 63), UINT8_C(174),
        UINT8_C(218), UINT8_C(164), UINT8_C(238), UINT8_C( 29), UINT8_C(114), UINT8_C(193), UINT8_C(136), UINT8_C(147) },
      UINT32_C(4294924636) },
    { { UINT8_C(173), UINT8_C(235), UINT8_C(197), UINT8_C(186), UINT8_C(127), UINT8_C(165), UINT8_C(121), UINT8_C(186),
        UINT8_C( 87), UINT8_C(  2), UINT8_C(150), UINT8_C(187), UINT8_C(213), UINT8_C(206), UINT8_C(163), UINT8_C(231),
        UINT8_C(211), UINT8_C(238), UINT8_C( 56), UINT8_C(135), UINT8_C( 19), UINT8_C( 45), UINT8_C( 40), UINT8_C( 86),
        UINT8_C(148), UINT8_C(139), UINT8_C( 33), UINT8_C(143), UINT8_C( 89), UINT8_C(196), UINT8_C( 53), UINT8_C(  6) },
      { UINT8_C(173), UINT8_C(235), UINT8_C(197), UINT8_C(186), UINT8_C(159), UINT8_C( 57), UINT8_C(121), UINT8_C(246),
        UINT8_C( 87), UINT8_C(127), UINT8_C(150), UINT8_C( 16), UINT8_C( 77), UINT8_C( 85), UINT8_C(248), UINT8_C(231),
        UINT8_C(211), UINT8_C(238), UINT8_C( 56), UINT8_C(135), UINT8_C( 19), UINT8_C( 45), UINT8_C( 40), UINT8_C( 86),
        UINT8_C(148), UINT8_C(139), UINT8_C( 33), UINT8_C(143), UINT8_C( 89), UINT8_C(196), UINT8_C( 53), UINT8_C(  6) },
      UINT32_C(4294935887) },
    { { UINT8_C(113), UINT8_C( 79), UINT8_C(179), UINT8_C( 90), UINT8_C( 70), UINT8_C(238), UINT8_C(218), UINT8_C(247),
           UINT8_MAX, UINT8_C( 39), UINT8_C( 76), UINT8_C(247), UINT8_C( 72), UINT8_C(144), UINT8_C( 39), UINT8_C(240),
        UINT8_C(231), UINT8_C(133), UINT8_C(193), UINT8_C(148), UINT8_C(120), UINT8_C( 28), UINT8_C( 98), UINT8_C(249),
        UINT8_C(209), UINT8_C(244), UINT8_C(176), UINT8_C(139), UINT8_C( 54), UINT8_C( 96), UINT8_C(  6), UINT8_C(167) },
      { UINT8_C(113), UINT8_C(185), UINT8_C(  2), UINT8_C( 90), UINT8_C(168), UINT8_C(220), UINT8_C(218), UINT8_C(247),
        UINT8_C(  3), UINT8_C( 58), UINT8_C( 76), UINT8_C( 76), UINT8_C(202), UINT8_C(197), UINT8_C( 60), UINT8_C(240),
        UINT8_C(231), UINT8_C(133), UINT8_C(193), UINT8_C(148), UINT8_C(120), UINT8_C( 28), UINT8_C( 98), UINT8_C(249),
        UINT8_C(209), UINT8_C(244), UINT8_C(176), UINT8_C(139), UINT8_C( 54), UINT8_C( 96), UINT8_C(  6), UINT8_C(167) },
      UINT32_C(4294935753) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i a = simde_x_mm256_loadu_epu8(test_vec[i].a);
    simde__m256i b = simde_x_mm256_loadu_epu8(test_vec[i].b);
    simde__mmask32 r = simde_mm256_cmpeq_epu8_mask(a, b);
    simde_assert_equal_mmask32(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m256i a = simde_test_x86_random_u8x32();
    simde__m256i b = simde_x_mm256_mask_blend_epu8(simde_test_x86_random_mmask16(), a, simde_test_x86_random_u8x32());
    simde__mmask32 r = simde_mm256_cmpeq_epu8_mask(a, b);

    simde_test_x86_write_u8x32(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_u8x32(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_mask_cmpeq_epu8_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask32 k1;
    const uint8_t a[32];
    const uint8_t b[32];
    const simde__mmask32 r;
  } test_vec[] = {
    { UINT32_C(2657756858),
      { UINT8_C(210), UINT8_C( 61), UINT8_C(144), UINT8_C( 29), UINT8_C(155), UINT8_C(202), UINT8_C( 25), UINT8_C(163),
        UINT8_C( 63), UINT8_C(  4), UINT8_C(176), UINT8_C(253), UINT8_C(134), UINT8_C(193), UINT8_C( 34), UINT8_C(106),
        UINT8_C(119), UINT8_C(217), UINT8_C(170), UINT8_C( 63), UINT8_C(148), UINT8_C(157), UINT8_C(143), UINT8_C(153),
        UINT8_C( 80), UINT8_C(191), UINT8_C( 26), UINT8_C( 10), UINT8_C(229), UINT8_C(132), UINT8_C(168), UINT8_C(183) },
      { UINT8_C(210), UINT8_C( 57), UINT8_C(213), UINT8_C( 29), UINT8_C(155), UINT8_C(238), UINT8_C(  0), UINT8_C(163),
        UINT8_C( 63), UINT8_C(  4), UINT8_C(176), UINT8_C(120), UINT8_C(134), UINT8_C( 98), UINT8_C(226), UINT8_C(232),
        UINT8_C(119), UINT8_C(140), UINT8_C( 40), UINT8_C( 63), UINT8_C(148), UINT8_C(183), UINT8_C(143), UINT8_C(153),
        UINT8_C(118), UINT8_C(191), UINT8_C( 26), UINT8_C( 92), UINT8_C(229), UINT8_C( 45), UINT8_C( 19), UINT8_C(183) },
      UINT32_C(2521302680) },
    { UINT32_C(3366725590),
      { UINT8_C(215), UINT8_C(236), UINT8_C( 65), UINT8_C( 73), UINT8_C( 79), UINT8_C( 35), UINT8_C( 49), UINT8_C(138),
        UINT8_C(176), UINT8_C( 89), UINT8_C( 90), UINT8_C(217), UINT8_C( 16), UINT8_C(195), UINT8_C( 83), UINT8_C(135),
        UINT8_C( 71), UINT8_C(216), UINT8_C(227), UINT8_C( 79), UINT8_C(  5), UINT8_C(246), UINT8_C( 24), UINT8_C(107),
        UINT8_C(223), UINT8_C( 63), UINT8_C(212), UINT8_C(181), UINT8_C(102), UINT8_C(129), UINT8_C(126), UINT8_C( 61) },
      { UINT8_C(215), UINT8_C(236), UINT8_C(134), UINT8_C( 73), UINT8_C(226), UINT8_C( 35), UINT8_C( 71), UINT8_C(138),
        UINT8_C(176), UINT8_C( 89), UINT8_C(108), UINT8_C( 34), UINT8_C(101), UINT8_C(191), UINT8_C(169), UINT8_C(135),
        UINT8_C(151), UINT8_C(140), UINT8_C(251), UINT8_C( 79), UINT8_C(  5), UINT8_C(246), UINT8_C( 24), UINT8_C( 97),
        UINT8_C(223), UINT8_C(220), UINT8_C( 23), UINT8_C(181), UINT8_C( 93), UINT8_C(149), UINT8_C(126), UINT8_C( 61) },
      UINT32_C(3358065538) },
    { UINT32_C(1187630644),
      { UINT8_C(111), UINT8_C( 53), UINT8_C(104), UINT8_C(212), UINT8_C(244), UINT8_C( 17), UINT8_C(128), UINT8_C(140),
        UINT8_C(157), UINT8_C(123), UINT8_C( 40), UINT8_C( 31), UINT8_C(143), UINT8_C( 48), UINT8_C(129), UINT8_C(225),
        UINT8_C( 12), UINT8_C(152), UINT8_C(154), UINT8_C(105), UINT8_C( 45), UINT8_C(144), UINT8_C( 51), UINT8_C(129),
        UINT8_C( 12), UINT8_C(186), UINT8_C(183), UINT8_C( 65), UINT8_C(136), UINT8_C(128), UINT8_C(135), UINT8_C(248) },
      { UINT8_C(111), UINT8_C(239), UINT8_C(204), UINT8_C(212), UINT8_C(244), UINT8_C( 77), UINT8_C(128), UINT8_C(140),
        UINT8_C(157), UINT8_C( 94), UINT8_C(188), UINT8_C( 87), UINT8_C(142), UINT8_C( 61), UINT8_C(129), UINT8_C(225),
        UINT8_C(213), UINT8_C(211), UINT8_C(154), UINT8_C(  2), UINT8_C( 99), UINT8_C(144), UINT8_C( 51), UINT8_C(129),
        UINT8_C( 12), UINT8_C( 59), UINT8_C(176), UINT8_C( 65), UINT8_C(136), UINT8_C( 55), UINT8_C(135), UINT8_C(248) },
      UINT32_C(1086373904) },
    { UINT32_C(1422086539),
      { UINT8_C(175), UINT8_C(128), UINT8_C(171), UINT8_C( 62), UINT8_C(189), UINT8_C(228), UINT8_C(216), UINT8_C(147),
        UINT8_C(183), UINT8_C(220), UINT8_C(149), UINT8_C( 26), UINT8_C( 19), UINT8_C( 25), UINT8_C(138), UINT8_C(  4),
        UINT8_C( 84), UINT8_C( 58), UINT8_C(126), UINT8_C( 15), UINT8_C(114), UINT8_C(240), UINT8_C(128), UINT8_C(152),
        UINT8_C( 47), UINT8_C(155), UINT8_C(191), UINT8_C(186), UINT8_C(236), UINT8_C(130), UINT8_C( 14), UINT8_C(156) },
      { UINT8_C(  2), UINT8_C(186), UINT8_C(218), UINT8_C( 62), UINT8_C(189), UINT8_C(228), UINT8_C( 83), UINT8_C( 86),
        UINT8_C(142), UINT8_C(232), UINT8_C(149), UINT8_C( 26), UINT8_C( 19), UINT8_C(250), UINT8_C(166), UINT8_C( 85),
        UINT8_C( 53), UINT8_C( 36), UINT8_C(126), UINT8_C( 15), UINT8_C(114), UINT8_C(240), UINT8_C( 63), UINT8_C(152),
        UINT8_C(129), UINT8_C(155), UINT8_C(254), UINT8_C(186), UINT8_C(236), UINT8_C( 13), UINT8_C(  9), UINT8_C(156) },
      UINT32_C( 276828168) },
    { UINT32_C( 616273558),
      { UINT8_C(127), UINT8_C( 44), UINT8_C(198), UINT8_C(128), UINT8_C( 38), UINT8_C(108), UINT8_C(214), UINT8_C( 91),
        UINT8_C(144), UINT8_C( 59), UINT8_C(  2), UINT8_C(165), UINT8_C( 32), UINT8_C( 66), UINT8_C(233), UINT8_C(161),
        UINT8_C( 64), UINT8_C(232), UINT8_C( 15), UINT8_C(193), UINT8_C(245), UINT8_C( 24), UINT8_C( 69), UINT8_C(188),
        UINT8_C(252), UINT8_C(136), UINT8_C( 33), UINT8_C(146), UINT8_C( 31), UINT8_C(221), UINT8_C(182), UINT8_C(158) },
      { UINT8_C(127), UINT8_C(124), UINT8_C(198), UINT8_C( 47), UINT8_C(232), UINT8_C(108), UINT8_C(139), UINT8_C(121),
        UINT8_C(144), UINT8_C(141), UINT8_C(  2), UINT8_C( 80), UINT8_C(207), UINT8_C(  8), UINT8_C(241), UINT8_C(161),
        UINT8_C( 64), UINT8_C(232), UINT8_C( 15), UINT8_C(229), UINT8_C( 25), UINT8_C( 24), UINT8_C(161), UINT8_C( 21),
        UINT8_C(252), UINT8_C(194), UINT8_C( 33), UINT8_C(146), UINT8_C( 31), UINT8_C(221), UINT8_C( 92), UINT8_C(168) },
      UINT32_C( 606307332) },
    { UINT32_C(2654692207),
      { UINT8_C(240), UINT8_C( 90), UINT8_C(238), UINT8_C(192), UINT8_C( 98), UINT8_C(224), UINT8_C(208), UINT8_C( 82),
        UINT8_C(224), UINT8_C(161), UINT8_C( 55), UINT8_C(249), UINT8_C(184), UINT8_C(216), UINT8_C( 14), UINT8_C( 87),
        UINT8_C(154), UINT8_C(181), UINT8_C( 21), UINT8_C( 58), UINT8_C( 19), UINT8_C(113), UINT8_C(226), UINT8_C(237),
        UINT8_C(235), UINT8_C(186), UINT8_C(175), UINT8_C( 90), UINT8_C( 29), UINT8_C(235), UINT8_C(249), UINT8_C( 14) },
      { UINT8_C( 69), UINT8_C(231), UINT8_C(238), UINT8_C(167), UINT8_C(199), UINT8_C(158), UINT8_C(249), UINT8_C(168),
        UINT8_C( 63), UINT8_C( 48), UINT8_C( 55), UINT8_C(249), UINT8_C(  8), UINT8_C(176), UINT8_C( 78), UINT8_C( 87),
        UINT8_C(154), UINT8_C(181), UINT8_C(220), UINT8_C(120), UINT8_C( 19), UINT8_C(191), UINT8_C(101), UINT8_C(192),
        UINT8_C(235), UINT8_C( 21), UINT8_C(175), UINT8_C( 90), UINT8_C( 29), UINT8_C(235), UINT8_C(165), UINT8_C( 69) },
      UINT32_C( 471007236) },
    { UINT32_C(1349182737),
      { UINT8_C( 21), UINT8_C( 12), UINT8_C( 72), UINT8_C( 29), UINT8_C(188), UINT8_C(150), UINT8_C(191), UINT8_C( 33),
        UINT8_C(250), UINT8_C(156), UINT8_C(154), UINT8_C(206), UINT8_C( 91),    UINT8_MAX, UINT8_C(142), UINT8_C(212),
        UINT8_C( 20), UINT8_C(169), UINT8_C(107), UINT8_C( 20), UINT8_C(188), UINT8_C( 16), UINT8_C( 89), UINT8_C(183),
        UINT8_C(131), UINT8_C( 69), UINT8_C(122), UINT8_C(148), UINT8_C( 42), UINT8_C(228), UINT8_C(229), UINT8_C( 63) },
      { UINT8_C(240), UINT8_C( 12), UINT8_C( 92), UINT8_C(172), UINT8_C(188), UINT8_C(150), UINT8_C(191), UINT8_C(189),
        UINT8_C(250), UINT8_C(104), UINT8_C(140), UINT8_C(206), UINT8_C(103), UINT8_C( 26), UINT8_C(231), UINT8_C(124),
        UINT8_C(195), UINT8_C( 83), UINT8_C(107), UINT8_C( 20), UINT8_C( 99), UINT8_C(234), UINT8_C( 89), UINT8_C(183),
        UINT8_C( 47), UINT8_C( 69), UINT8_C(122), UINT8_C(148), UINT8_C(150), UINT8_C(228), UINT8_C(153), UINT8_C( 63) },
      UINT32_C(   4718864) },
    { UINT32_C(3389915410),
      { UINT8_C(105), UINT8_C(154), UINT8_C(221), UINT8_C(208), UINT8_C(181), UINT8_C(196), UINT8_C( 76), UINT8_C(120),
        UINT8_C( 23), UINT8_C(221), UINT8_C(248), UINT8_C(123), UINT8_C(199), UINT8_C( 48), UINT8_C( 98), UINT8_C(246),
        UINT8_C(225), UINT8_C(221), UINT8_C( 80), UINT8_C(119), UINT8_C( 62), UINT8_C(234), UINT8_C(254), UINT8_C(203),
        UINT8_C(224), UINT8_C( 49), UINT8_C( 28), UINT8_C(242), UINT8_C( 50), UINT8_C( 43), UINT8_C(188), UINT8_C(155) },
      { UINT8_C(105), UINT8_C(154), UINT8_C(107), UINT8_C(208), UINT8_C( 93), UINT8_C(184), UINT8_C( 76), UINT8_C(117),
        UINT8_C( 23), UINT8_C(221), UINT8_C(240), UINT8_C( 92), UINT8_C( 27), UINT8_C( 48), UINT8_C( 82), UINT8_C(253),
        UINT8_C(225), UINT8_C(221), UINT8_C( 80), UINT8_C(119), UINT8_C( 62), UINT8_C(234), UINT8_C( 57), UINT8_C(109),
        UINT8_C(163), UINT8_C( 49), UINT8_C( 28), UINT8_C(242), UINT8_C(128), UINT8_C( 43), UINT8_C(188), UINT8_C(155) },
      UINT32_C(3389915394) },  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i a = simde_x_mm256_loadu_epu8(test_vec[i].a);
    simde__m256i b = simde_x_mm256_loadu_epu8(test_vec[i].b);
    simde__mmask32 r = simde_mm256_mask_cmpeq_epu8_mask(test_vec[i].k1, a, b);
    simde_assert_equal_mmask32(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask32 k1 = simde_test_x86_random_mmask32();
    simde__m256i a = simde_test_x86_random_u8x32();
    simde__m256i b = simde_x_mm256_mask_blend_epu8(simde_test_x86_random_mmask32(), a, simde_test_x86_random_u8x32());
    simde__mmask32 r = simde_mm256_mask_cmpeq_epu8_mask(k1, a, b);

    simde_test_x86_write_mmask32(2, k1, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_u8x32(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_u8x32(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_cmpeq_epu8_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const uint8_t a[64];
    const uint8_t b[64];
    const simde__mmask64 r;
  } test_vec[] = {
    { { UINT8_C(130), UINT8_C( 53), UINT8_C(164), UINT8_C(159), UINT8_C(200), UINT8_C(200), UINT8_C(237), UINT8_C(161),
        UINT8_C(249), UINT8_C(173), UINT8_C(237), UINT8_C( 70), UINT8_C( 19), UINT8_C(193), UINT8_C(154), UINT8_C(194),
        UINT8_C( 87), UINT8_C( 12), UINT8_C(188), UINT8_C(  0), UINT8_C(116), UINT8_C(128), UINT8_C(252), UINT8_C(250),
        UINT8_C(161), UINT8_C(240), UINT8_C( 23), UINT8_C(253), UINT8_C( 44), UINT8_C(116), UINT8_C(  9), UINT8_C(174),
        UINT8_C(170), UINT8_C(173), UINT8_C( 77), UINT8_C(114), UINT8_C(117), UINT8_C( 58), UINT8_C( 19), UINT8_C(110),
        UINT8_C(232), UINT8_C(  1), UINT8_C(181), UINT8_C(251), UINT8_C(194), UINT8_C( 79), UINT8_C(190), UINT8_C( 25),
        UINT8_C( 91), UINT8_C(122), UINT8_C( 25), UINT8_C(207), UINT8_C(251), UINT8_C( 22), UINT8_C(201), UINT8_C(156),
        UINT8_C(  6), UINT8_C(225), UINT8_C(154), UINT8_C( 50), UINT8_C( 85), UINT8_C(163), UINT8_C(224),    UINT8_MAX },
      { UINT8_C(130), UINT8_C( 53), UINT8_C(113), UINT8_C(197), UINT8_C(200), UINT8_C(200), UINT8_C(237), UINT8_C( 79),
        UINT8_C(249), UINT8_C(173), UINT8_C(237), UINT8_C( 70), UINT8_C( 19), UINT8_C(  9), UINT8_C(154), UINT8_C(194),
        UINT8_C(131), UINT8_C( 12), UINT8_C(188), UINT8_C(  0), UINT8_C(145), UINT8_C( 44), UINT8_C(252), UINT8_C(151),
        UINT8_C( 13), UINT8_C(240), UINT8_C(201), UINT8_C(253), UINT8_C( 44), UINT8_C(169), UINT8_C( 98), UINT8_C(168),
        UINT8_C(170), UINT8_C(212), UINT8_C( 77), UINT8_C(114), UINT8_C(117), UINT8_C( 58), UINT8_C(141), UINT8_C(223),
        UINT8_C(232), UINT8_C(216), UINT8_C( 39), UINT8_C(194), UINT8_C(225), UINT8_C(136), UINT8_C(190), UINT8_C( 25),
        UINT8_C( 91), UINT8_C(122), UINT8_C(227), UINT8_C(207), UINT8_C(251), UINT8_C( 22), UINT8_C( 43), UINT8_C(243),
        UINT8_C(  6), UINT8_C(225), UINT8_C( 86), UINT8_C( 11), UINT8_C( 85), UINT8_C(163), UINT8_C(179),    UINT8_MAX },
      UINT64_C(12915128824593571699) },
    { { UINT8_C( 22), UINT8_C(235), UINT8_C( 15), UINT8_C(247), UINT8_C(116), UINT8_C(101), UINT8_C( 91), UINT8_C(119),
        UINT8_C( 30), UINT8_C( 62), UINT8_C( 12), UINT8_C(  3), UINT8_C( 60), UINT8_C( 55), UINT8_C(246), UINT8_C(239),
        UINT8_C( 44), UINT8_C( 76), UINT8_C(250), UINT8_C(201), UINT8_C(  5), UINT8_C(173), UINT8_C( 61), UINT8_C(145),
        UINT8_C(206), UINT8_C(238), UINT8_C(119), UINT8_C(144), UINT8_C( 44), UINT8_C( 59), UINT8_C(220), UINT8_C( 66),
        UINT8_C( 39), UINT8_C(235), UINT8_C( 57), UINT8_C(155), UINT8_C( 80), UINT8_C(148), UINT8_C( 18), UINT8_C(110),
        UINT8_C(211), UINT8_C( 30), UINT8_C(114), UINT8_C( 15), UINT8_C( 86), UINT8_C(104),    UINT8_MAX, UINT8_C(130),
        UINT8_C(181), UINT8_C(249), UINT8_C( 75), UINT8_C(186), UINT8_C(167), UINT8_C(136), UINT8_C( 75), UINT8_C(117),
        UINT8_C(118), UINT8_C(194), UINT8_C(  5), UINT8_C(162), UINT8_C(254), UINT8_C(225), UINT8_C(228), UINT8_C( 37) },
      { UINT8_C( 22), UINT8_C( 29), UINT8_C(192), UINT8_C( 29), UINT8_C(116), UINT8_C(101), UINT8_C( 91), UINT8_C(119),
        UINT8_C(241), UINT8_C( 62), UINT8_C(148), UINT8_C(  3), UINT8_C(102), UINT8_C( 55), UINT8_C(246), UINT8_C( 27),
        UINT8_C(141), UINT8_C( 76), UINT8_C(250), UINT8_C(201), UINT8_C(157), UINT8_C(173), UINT8_C(169), UINT8_C( 19),
        UINT8_C(227), UINT8_C(174), UINT8_C(182), UINT8_C(144), UINT8_C( 44), UINT8_C(154), UINT8_C(220), UINT8_C( 92),
        UINT8_C(184), UINT8_C(198), UINT8_C( 57), UINT8_C(106), UINT8_C(153), UINT8_C(148), UINT8_C( 18), UINT8_C(138),
        UINT8_C(211), UINT8_C( 30), UINT8_C(114), UINT8_C( 15), UINT8_C( 86), UINT8_C(104), UINT8_C(134), UINT8_C(164),
        UINT8_C(174), UINT8_C(249), UINT8_C( 75), UINT8_C(186), UINT8_C(124), UINT8_C(129), UINT8_C( 75), UINT8_C(117),
        UINT8_C( 47), UINT8_C( 21), UINT8_C( 65), UINT8_C(190), UINT8_C(175), UINT8_C(225), UINT8_C(228), UINT8_C(103) },
      UINT64_C( 6975582573052193521) },
    { { UINT8_C( 68), UINT8_C(  2), UINT8_C(  9), UINT8_C( 91), UINT8_C(156), UINT8_C(143),    UINT8_MAX, UINT8_C( 75),
        UINT8_C(235), UINT8_C(215), UINT8_C(150), UINT8_C(103), UINT8_C( 88), UINT8_C(245), UINT8_C(199), UINT8_C(135),
        UINT8_C( 10), UINT8_C(  9), UINT8_C( 69), UINT8_C(186), UINT8_C( 81), UINT8_C( 96), UINT8_C( 33), UINT8_C( 95),
        UINT8_C(245), UINT8_C(243), UINT8_C(  7), UINT8_C(144), UINT8_C(179), UINT8_C( 56), UINT8_C( 47), UINT8_C(247),
        UINT8_C( 59), UINT8_C( 57), UINT8_C( 82), UINT8_C(215), UINT8_C(200), UINT8_C( 81), UINT8_C( 34), UINT8_C(179),
        UINT8_C( 40), UINT8_C(185), UINT8_C( 27), UINT8_C(128), UINT8_C(174), UINT8_C(226), UINT8_C(  7), UINT8_C(185),
        UINT8_C(235), UINT8_C( 77), UINT8_C(115), UINT8_C( 60), UINT8_C(173), UINT8_C(148), UINT8_C(156), UINT8_C(163),
        UINT8_C(135), UINT8_C(163), UINT8_C( 51), UINT8_C( 59), UINT8_C(219), UINT8_C( 99), UINT8_C( 50), UINT8_C( 22) },
      { UINT8_C(156), UINT8_C(133), UINT8_C(  9), UINT8_C( 91), UINT8_C(214), UINT8_C(143), UINT8_C( 24),    UINT8_MAX,
        UINT8_C(235), UINT8_C( 51), UINT8_C(127), UINT8_C(120), UINT8_C( 88), UINT8_C(135), UINT8_C(199), UINT8_C(135),
        UINT8_C( 10), UINT8_C(  9), UINT8_C( 69), UINT8_C(186), UINT8_C( 81), UINT8_C(217), UINT8_C( 36), UINT8_C(192),
        UINT8_C(245), UINT8_C(243), UINT8_C(  7), UINT8_C(144), UINT8_C(179), UINT8_C( 56), UINT8_C(110), UINT8_C(247),
        UINT8_C(178), UINT8_C( 57), UINT8_C( 82), UINT8_C(215), UINT8_C(200), UINT8_C( 81), UINT8_C( 34), UINT8_C(179),
        UINT8_C( 40), UINT8_C(185), UINT8_C( 27), UINT8_C( 28), UINT8_C(174), UINT8_C(223), UINT8_C( 29), UINT8_C(185),
        UINT8_C(131), UINT8_C( 90), UINT8_C(228), UINT8_C( 60), UINT8_C( 52), UINT8_C(  8), UINT8_C(124), UINT8_C(163),
        UINT8_C(135), UINT8_C(163), UINT8_C( 51), UINT8_C( 27), UINT8_C(219), UINT8_C( 99), UINT8_C( 50), UINT8_C( 22) },
      UINT64_C(17836673444584870188) },
    { { UINT8_C(111), UINT8_C( 37), UINT8_C( 36), UINT8_C(254), UINT8_C(  5), UINT8_C( 65), UINT8_C( 96), UINT8_C(136),
        UINT8_C(155), UINT8_C( 68), UINT8_C( 68), UINT8_C(207), UINT8_C( 77), UINT8_C(192), UINT8_C(128), UINT8_C(173),
        UINT8_C( 55), UINT8_C(136), UINT8_C(201), UINT8_C(220),    UINT8_MAX, UINT8_C( 59), UINT8_C( 51), UINT8_C(211),
        UINT8_C(105), UINT8_C( 19), UINT8_C( 19), UINT8_C(107), UINT8_C(123), UINT8_C(138), UINT8_C(115), UINT8_C(234),
        UINT8_C(176), UINT8_C(151), UINT8_C(232), UINT8_C(181), UINT8_C(216), UINT8_C( 73), UINT8_C( 61), UINT8_C(115),
        UINT8_C(141), UINT8_C(130), UINT8_C( 67), UINT8_C(218), UINT8_C( 66), UINT8_C(195), UINT8_C(136), UINT8_C(122),
        UINT8_C( 75), UINT8_C( 81), UINT8_C( 86), UINT8_C( 75), UINT8_C(140), UINT8_C(137), UINT8_C( 30), UINT8_C(246),
        UINT8_C(156), UINT8_C( 49), UINT8_C( 97), UINT8_C( 23), UINT8_C(188), UINT8_C(212), UINT8_C(  1), UINT8_C(108) },
      { UINT8_C(107), UINT8_C( 37), UINT8_C( 36), UINT8_C( 67), UINT8_C(  5), UINT8_C( 65), UINT8_C(182), UINT8_C(192),
        UINT8_C(155), UINT8_C(249), UINT8_C( 68), UINT8_C( 35), UINT8_C( 77), UINT8_C( 35), UINT8_C(128), UINT8_C(173),
        UINT8_C(116), UINT8_C(136), UINT8_C(201), UINT8_C(  0), UINT8_C(124), UINT8_C(113), UINT8_C( 51), UINT8_C(211),
        UINT8_C(162), UINT8_C( 87), UINT8_C( 19), UINT8_C(107), UINT8_C( 43), UINT8_C(138), UINT8_C(115), UINT8_C(234),
        UINT8_C(176), UINT8_C(235), UINT8_C(232), UINT8_C( 77), UINT8_C( 74), UINT8_C(144), UINT8_C( 61), UINT8_C( 42),
        UINT8_C(137), UINT8_C(169), UINT8_C( 77), UINT8_C(218), UINT8_C( 66), UINT8_C(195), UINT8_C( 78), UINT8_C(122),
        UINT8_C(221), UINT8_C( 81), UINT8_C( 64), UINT8_C( 89), UINT8_C( 18), UINT8_C( 55), UINT8_C( 30), UINT8_C(246),
        UINT8_C(142), UINT8_C(160), UINT8_C( 97), UINT8_C( 23), UINT8_C(188), UINT8_C(212), UINT8_C( 80), UINT8_C(108) },
      UINT64_C(13601636435077027126) },
    { { UINT8_C(240), UINT8_C(139), UINT8_C(137), UINT8_C(188), UINT8_C(117), UINT8_C(215), UINT8_C(252), UINT8_C( 83),
        UINT8_C(120), UINT8_C( 60), UINT8_C(172), UINT8_C(138), UINT8_C(115), UINT8_C( 30), UINT8_C( 63), UINT8_C(  2),
        UINT8_C(190), UINT8_C( 82), UINT8_C(188), UINT8_C(143), UINT8_C( 47), UINT8_C( 12), UINT8_C(123), UINT8_C(248),
        UINT8_C( 54), UINT8_C(180), UINT8_C( 11), UINT8_C(240), UINT8_C(251), UINT8_C( 73), UINT8_C( 52), UINT8_C(235),
        UINT8_C(212), UINT8_C(189), UINT8_C(167), UINT8_C( 73), UINT8_C(149), UINT8_C(163), UINT8_C(156), UINT8_C( 13),
        UINT8_C(223), UINT8_C( 73), UINT8_C(152), UINT8_C( 83), UINT8_C(103), UINT8_C(215), UINT8_C( 85), UINT8_C( 37),
        UINT8_C( 41), UINT8_C( 17), UINT8_C(181), UINT8_C( 88), UINT8_C( 29), UINT8_C( 48), UINT8_C( 81), UINT8_C( 84),
        UINT8_C(228), UINT8_C( 92), UINT8_C( 68), UINT8_C(223), UINT8_C(165), UINT8_C(120), UINT8_C(202), UINT8_C(121) },
      { UINT8_C(240), UINT8_C(139), UINT8_C(137), UINT8_C(188), UINT8_C(117), UINT8_C(215), UINT8_C(216), UINT8_C( 83),
        UINT8_C(120), UINT8_C( 60), UINT8_C(172), UINT8_C(138), UINT8_C(115), UINT8_C( 30), UINT8_C( 53), UINT8_C(112),
        UINT8_C(172), UINT8_C(234), UINT8_C(201), UINT8_C(202), UINT8_C( 47), UINT8_C( 26), UINT8_C( 30), UINT8_C(248),
        UINT8_C( 54), UINT8_C(180), UINT8_C( 11), UINT8_C( 28), UINT8_C(219), UINT8_C(167), UINT8_C(149), UINT8_C( 17),
        UINT8_C( 24), UINT8_C(189), UINT8_C(220), UINT8_C( 73), UINT8_C(184), UINT8_C(180), UINT8_C( 31), UINT8_C( 13),
        UINT8_C(223), UINT8_C(102), UINT8_C(112), UINT8_C(108), UINT8_C(103), UINT8_C(215), UINT8_C( 85), UINT8_C(174),
        UINT8_C(143), UINT8_C( 17), UINT8_C(181), UINT8_C(169), UINT8_C(192), UINT8_C( 48), UINT8_C(167), UINT8_C( 84),
        UINT8_C(228), UINT8_C(132), UINT8_C( 68), UINT8_C(211), UINT8_C( 43), UINT8_C(120), UINT8_C(202), UINT8_C( 67) },
      UINT64_C( 7324666681611009983) },
    { { UINT8_C(244), UINT8_C(201), UINT8_C(  6), UINT8_C(246), UINT8_C(110), UINT8_C(227), UINT8_C(164), UINT8_C(253),
        UINT8_C(137), UINT8_C( 28), UINT8_C(166), UINT8_C( 73), UINT8_C(178), UINT8_C( 77), UINT8_C(128), UINT8_C(170),
        UINT8_C(209), UINT8_C(210), UINT8_C(126), UINT8_C(252), UINT8_C(186), UINT8_C( 98), UINT8_C( 63), UINT8_C(251),
        UINT8_C( 35), UINT8_C(174), UINT8_C(243), UINT8_C(152), UINT8_C( 60), UINT8_C( 76), UINT8_C( 50), UINT8_C( 49),
        UINT8_C( 21), UINT8_C( 56), UINT8_C( 39), UINT8_C(131), UINT8_C( 28), UINT8_C(203), UINT8_C(128), UINT8_C(165),
        UINT8_C(231), UINT8_C( 38), UINT8_C(239), UINT8_C(153), UINT8_C(115), UINT8_C(111), UINT8_C( 67), UINT8_C( 68),
        UINT8_C( 65), UINT8_C(193), UINT8_C( 64), UINT8_C(252), UINT8_C( 36), UINT8_C(127), UINT8_C(247), UINT8_C( 71),
        UINT8_C( 45), UINT8_C(234), UINT8_C(223), UINT8_C(106), UINT8_C( 55), UINT8_C( 17), UINT8_C(155), UINT8_C( 76) },
      { UINT8_C(244), UINT8_C(194), UINT8_C(208), UINT8_C(246), UINT8_C(110), UINT8_C( 80), UINT8_C(164), UINT8_C(116),
        UINT8_C(137), UINT8_C(250), UINT8_C(166), UINT8_C( 73), UINT8_C(178), UINT8_C( 80), UINT8_C(128), UINT8_C(170),
        UINT8_C( 18), UINT8_C(111), UINT8_C(126), UINT8_C(252), UINT8_C(239), UINT8_C(157), UINT8_C( 63), UINT8_C(251),
        UINT8_C( 35), UINT8_C( 92), UINT8_C(243), UINT8_C(152), UINT8_C(109), UINT8_C( 76), UINT8_C( 11), UINT8_C(182),
        UINT8_C(227), UINT8_C( 56), UINT8_C( 39), UINT8_C(112), UINT8_C( 28), UINT8_C(203), UINT8_C(228), UINT8_C(163),
        UINT8_C(231), UINT8_C( 38), UINT8_C(239), UINT8_C(138), UINT8_C( 66), UINT8_C(111), UINT8_C( 67), UINT8_C( 68),
        UINT8_C( 44), UINT8_C(193), UINT8_C(138), UINT8_C(252), UINT8_C(120), UINT8_C(  7), UINT8_C( 55), UINT8_C( 71),
        UINT8_C( 45), UINT8_C(190), UINT8_C(223), UINT8_C(208), UINT8_C( 55), UINT8_C(203), UINT8_C(134), UINT8_C(195) },
      UINT64_C( 1552307241465208153) },
    { { UINT8_C(  9), UINT8_C(  3), UINT8_C(116), UINT8_C( 75), UINT8_C(191), UINT8_C(169), UINT8_C(159), UINT8_C(235),
        UINT8_C(132), UINT8_C( 41), UINT8_C(  6), UINT8_C(252), UINT8_C( 48), UINT8_C( 62), UINT8_C(253), UINT8_C(147),
        UINT8_C(252), UINT8_C(188), UINT8_C( 99), UINT8_C(219), UINT8_C(135), UINT8_C(234), UINT8_C(158), UINT8_C( 46),
        UINT8_C(140), UINT8_C(210), UINT8_C(  0), UINT8_C( 86), UINT8_C(234), UINT8_C(118), UINT8_C( 64), UINT8_C(243),
        UINT8_C(121), UINT8_C(181), UINT8_C( 63), UINT8_C( 56), UINT8_C( 94), UINT8_C(222), UINT8_C( 36), UINT8_C(226),
        UINT8_C(  8), UINT8_C( 42), UINT8_C(222), UINT8_C( 56), UINT8_C(104), UINT8_C(219), UINT8_C(204), UINT8_C(100),
        UINT8_C(152), UINT8_C( 47), UINT8_C( 64), UINT8_C( 31), UINT8_C( 25), UINT8_C(222), UINT8_C( 77), UINT8_C(166),
        UINT8_C(176), UINT8_C( 78), UINT8_C(252), UINT8_C(154), UINT8_C(196), UINT8_C( 60), UINT8_C(142), UINT8_C( 61) },
      { UINT8_C(  9), UINT8_C(205), UINT8_C(116), UINT8_C( 79), UINT8_C(171), UINT8_C(169), UINT8_C(159), UINT8_C(179),
        UINT8_C(132), UINT8_C( 41), UINT8_C(236), UINT8_C( 44), UINT8_C(235), UINT8_C( 62), UINT8_C(145), UINT8_C(147),
        UINT8_C(252), UINT8_C(209), UINT8_C( 99), UINT8_C(  1), UINT8_C(135), UINT8_C(234), UINT8_C(158), UINT8_C( 96),
        UINT8_C(140), UINT8_C(210), UINT8_C(  0), UINT8_C(  2), UINT8_C(234), UINT8_C(136), UINT8_C( 63), UINT8_C(209),
        UINT8_C(121), UINT8_C(181), UINT8_C( 32), UINT8_C(  1), UINT8_C( 94), UINT8_C( 82), UINT8_C( 36), UINT8_C( 18),
        UINT8_C(  8), UINT8_C(160), UINT8_C( 63), UINT8_C( 77), UINT8_C( 88), UINT8_C(208), UINT8_C(204), UINT8_C(100),
        UINT8_C(161), UINT8_C(116), UINT8_C( 64), UINT8_C( 80), UINT8_C(100), UINT8_C(232), UINT8_C(176), UINT8_C(163),
        UINT8_C(176), UINT8_C( 78), UINT8_C(252), UINT8_C(154), UINT8_C( 51), UINT8_C( 60), UINT8_C(142), UINT8_C( 61) },
      UINT64_C(17223103437591651173) },
    { { UINT8_C(223), UINT8_C( 58), UINT8_C( 93), UINT8_C( 55), UINT8_C( 10), UINT8_C( 46), UINT8_C(119), UINT8_C(171),
        UINT8_C(162), UINT8_C(184), UINT8_C(251), UINT8_C(  7), UINT8_C(160), UINT8_C(172), UINT8_C(170), UINT8_C( 43),
        UINT8_C( 87), UINT8_C( 79), UINT8_C(150), UINT8_C(138), UINT8_C( 52), UINT8_C(209), UINT8_C( 19), UINT8_C(206),
        UINT8_C( 45), UINT8_C(157), UINT8_C(183), UINT8_C(219), UINT8_C(220), UINT8_C(178), UINT8_C(235), UINT8_C(187),
        UINT8_C(236), UINT8_C( 73), UINT8_C(242), UINT8_C(246), UINT8_C(119), UINT8_C(106), UINT8_C(161), UINT8_C( 26),
        UINT8_C( 34), UINT8_C(156), UINT8_C( 33), UINT8_C(195), UINT8_C( 72), UINT8_C(203), UINT8_C(238), UINT8_C(159),
        UINT8_C( 26), UINT8_C(132), UINT8_C( 42), UINT8_C( 79), UINT8_C( 86), UINT8_C( 61), UINT8_C( 29), UINT8_C(131),
        UINT8_C(219), UINT8_C(212), UINT8_C( 95), UINT8_C(183), UINT8_C(134), UINT8_C( 74), UINT8_C(114), UINT8_C(114) },
      { UINT8_C(147), UINT8_C( 58), UINT8_C(104), UINT8_C( 55), UINT8_C(206), UINT8_C( 46), UINT8_C(119), UINT8_C(241),
        UINT8_C(162), UINT8_C(184), UINT8_C(251), UINT8_C(238), UINT8_C(160), UINT8_C(162), UINT8_C(170), UINT8_C( 43),
        UINT8_C( 39), UINT8_C(184), UINT8_C(150), UINT8_C(138), UINT8_C( 52), UINT8_C(209), UINT8_C( 19), UINT8_C(208),
        UINT8_C(108), UINT8_C(157), UINT8_C(135), UINT8_C(243), UINT8_C(220), UINT8_C(249), UINT8_C(101), UINT8_C(187),
        UINT8_C( 94), UINT8_C( 73), UINT8_C( 72), UINT8_C(246), UINT8_C(215), UINT8_C(106), UINT8_C(161), UINT8_C( 26),
        UINT8_C(179), UINT8_C(156), UINT8_C( 33), UINT8_C(195), UINT8_C( 72), UINT8_C(250), UINT8_C(238), UINT8_C(155),
        UINT8_C( 26), UINT8_C(106), UINT8_C( 42), UINT8_C(167), UINT8_C( 86), UINT8_C( 24), UINT8_C(120), UINT8_C(111),
        UINT8_C(120), UINT8_C(212), UINT8_C( 95), UINT8_C( 34), UINT8_C(134), UINT8_C( 74), UINT8_C( 95), UINT8_C( 87) },
      UINT64_C( 3897125414132045674) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512i a = simde_x_mm512_loadu_epu8(test_vec[i].a);
    simde__m512i b = simde_x_mm512_loadu_epu8(test_vec[i].b);
    simde__mmask64 r = simde_mm512_cmpeq_epu8_mask(a, b);
    simde_assert_equal_mmask64(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m512i a = simde_test_x86_random_u8x64();
    simde__m512i b = simde_x_mm512_mask_blend_epu8(simde_test_x86_random_mmask64(), a, simde_test_x86_random_u8x64());
    simde__mmask64 r = simde_mm512_cmpeq_epu8_mask(a, b);

    simde_test_x86_write_u8x64(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_u8x64(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask64(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_mask_cmpeq_epu8_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask64 k1;
    const uint8_t a[64];
    const uint8_t b[64];
    const simde__mmask64 r;
  } test_vec[] = {
    { UINT64_C(  180563246490408562),
      { UINT8_C(232), UINT8_C(153), UINT8_C(170), UINT8_C(234), UINT8_C(178), UINT8_C( 34), UINT8_C( 89), UINT8_C( 42),
        UINT8_C( 33), UINT8_C(187), UINT8_C( 76), UINT8_C( 26), UINT8_C(131), UINT8_C(171), UINT8_C(113), UINT8_C( 24),
        UINT8_C( 83), UINT8_C(245), UINT8_C(133), UINT8_C(105), UINT8_C(150), UINT8_C(112), UINT8_C( 50), UINT8_C(  8),
        UINT8_C(198), UINT8_C(191), UINT8_C(239), UINT8_C( 23), UINT8_C( 61), UINT8_C(112), UINT8_C( 25), UINT8_C( 37),
        UINT8_C( 10), UINT8_C(195), UINT8_C( 15), UINT8_C(188), UINT8_C(229), UINT8_C(105), UINT8_C(230), UINT8_C(  7),
        UINT8_C( 36), UINT8_C( 50), UINT8_C( 33), UINT8_C(167), UINT8_C(221), UINT8_C(147), UINT8_C(192), UINT8_C( 49),
        UINT8_C(136), UINT8_C( 69), UINT8_C(154), UINT8_C( 30), UINT8_C(181), UINT8_C(204), UINT8_C( 38), UINT8_C(124),
        UINT8_C(139), UINT8_C( 21), UINT8_C(147), UINT8_C(200), UINT8_C(134), UINT8_C(172), UINT8_C(237), UINT8_C(144) },
      { UINT8_C(112), UINT8_C(153), UINT8_C(170), UINT8_C(234), UINT8_C(102), UINT8_C( 34), UINT8_C( 92), UINT8_C( 42),
        UINT8_C( 33), UINT8_C(187), UINT8_C( 50), UINT8_C( 26), UINT8_C(131), UINT8_C(242), UINT8_C(114), UINT8_C(153),
        UINT8_C( 83), UINT8_C( 12), UINT8_C(133), UINT8_C(105), UINT8_C(150), UINT8_C(112), UINT8_C(105), UINT8_C(100),
        UINT8_C(198), UINT8_C(191), UINT8_C(239), UINT8_C(121), UINT8_C(168), UINT8_C(112), UINT8_C(  9), UINT8_C( 24),
        UINT8_C( 10), UINT8_C( 85), UINT8_C(110), UINT8_C(125), UINT8_C(229), UINT8_C(202), UINT8_C(230), UINT8_C(235),
        UINT8_C( 36), UINT8_C( 57), UINT8_C( 33), UINT8_C( 89), UINT8_C(221), UINT8_C(147), UINT8_C(242), UINT8_C( 99),
        UINT8_C(171), UINT8_C(169), UINT8_C(154), UINT8_C( 30), UINT8_C(181), UINT8_C(204), UINT8_C(232), UINT8_C(122),
        UINT8_C(181), UINT8_C( 20), UINT8_C(243), UINT8_C(200), UINT8_C( 46), UINT8_C(252), UINT8_C(118), UINT8_C( 69) },
      UINT64_C(      58618352046626) },
    { UINT64_C( 4220510078757826307),
      { UINT8_C(236), UINT8_C(226), UINT8_C(190), UINT8_C(115), UINT8_C(155), UINT8_C(166), UINT8_C(237), UINT8_C( 80),
        UINT8_C(186), UINT8_C(224), UINT8_C(173), UINT8_C(233), UINT8_C(220), UINT8_C( 35), UINT8_C( 46), UINT8_C( 45),
        UINT8_C(  7), UINT8_C(241), UINT8_C(  5), UINT8_C(182), UINT8_C(187), UINT8_C(200), UINT8_C(173), UINT8_C(190),
        UINT8_C(184), UINT8_C(253), UINT8_C(237), UINT8_C( 70), UINT8_C( 64), UINT8_C(127), UINT8_C(128), UINT8_C( 45),
        UINT8_C( 97), UINT8_C( 62), UINT8_C(160), UINT8_C(252), UINT8_C(228), UINT8_C(142), UINT8_C( 76), UINT8_C(159),
        UINT8_C(110), UINT8_C(250), UINT8_C(136), UINT8_C( 75), UINT8_C( 29), UINT8_C(182), UINT8_C(120), UINT8_C( 37),
        UINT8_C(167), UINT8_C(126), UINT8_C(219), UINT8_C( 98), UINT8_C( 70), UINT8_C(136), UINT8_C( 33), UINT8_C(254),
        UINT8_C(133), UINT8_C( 14), UINT8_C( 69), UINT8_C(198), UINT8_C(142), UINT8_C(197), UINT8_C(243), UINT8_C(239) },
      { UINT8_C(236), UINT8_C(226), UINT8_C(236), UINT8_C(232), UINT8_C(155), UINT8_C(166), UINT8_C(237), UINT8_C( 80),
        UINT8_C( 50), UINT8_C(224), UINT8_C(173), UINT8_C( 80), UINT8_C(198), UINT8_C( 83), UINT8_C( 46), UINT8_C( 45),
        UINT8_C(  7), UINT8_C( 80), UINT8_C(208), UINT8_C( 24), UINT8_C(187), UINT8_C(200), UINT8_C( 22), UINT8_C( 93),
           UINT8_MAX, UINT8_C(253), UINT8_C( 35), UINT8_C(141), UINT8_C( 64), UINT8_C( 22), UINT8_C(128), UINT8_C( 37),
        UINT8_C( 97), UINT8_C(105), UINT8_C( 13), UINT8_C(203), UINT8_C(228), UINT8_C(142), UINT8_C( 91), UINT8_C(212),
        UINT8_C(164), UINT8_C(250), UINT8_C(136), UINT8_C(106), UINT8_C( 29), UINT8_C(153), UINT8_C(120), UINT8_C( 37),
        UINT8_C(233), UINT8_C(126), UINT8_C(219), UINT8_C( 98), UINT8_C( 70), UINT8_C(136), UINT8_C( 33), UINT8_C(152),
        UINT8_C(133), UINT8_C( 66), UINT8_C( 69), UINT8_C(198), UINT8_C( 88), UINT8_C(163), UINT8_C( 43), UINT8_C(239) },
      UINT64_C(  581599869686302211) },
    { UINT64_C( 2829867222705218912),
      { UINT8_C( 93), UINT8_C(185), UINT8_C(232), UINT8_C(246), UINT8_C( 67), UINT8_C(  7), UINT8_C(142), UINT8_C( 40),
        UINT8_C( 73), UINT8_C(180), UINT8_C( 47), UINT8_C(161), UINT8_C( 87), UINT8_C( 90), UINT8_C(164), UINT8_C( 99),
        UINT8_C(147), UINT8_C(114), UINT8_C( 17), UINT8_C( 97), UINT8_C(155), UINT8_C(146), UINT8_C(212), UINT8_C(251),
        UINT8_C( 56), UINT8_C(177), UINT8_C(229), UINT8_C(118), UINT8_C(102), UINT8_C( 43), UINT8_C(158), UINT8_C(195),
        UINT8_C(228), UINT8_C(134), UINT8_C(185), UINT8_C( 39), UINT8_C(141), UINT8_C( 71), UINT8_C( 79), UINT8_C(214),
        UINT8_C(252), UINT8_C(126), UINT8_C(120), UINT8_C( 83), UINT8_C(217), UINT8_C( 28), UINT8_C(183), UINT8_C(108),
        UINT8_C(142), UINT8_C(200), UINT8_C(206), UINT8_C( 41), UINT8_C( 90), UINT8_C(162), UINT8_C( 37), UINT8_C(146),
        UINT8_C( 83), UINT8_C( 10), UINT8_C(  9), UINT8_C(185), UINT8_C( 53), UINT8_C(167), UINT8_C(124), UINT8_C( 25) },
      { UINT8_C( 45), UINT8_C(185), UINT8_C(232), UINT8_C(187), UINT8_C( 67), UINT8_C(144), UINT8_C(145), UINT8_C( 40),
        UINT8_C( 73), UINT8_C(180), UINT8_C(204), UINT8_C(231), UINT8_C( 37), UINT8_C(131), UINT8_C( 84), UINT8_C(179),
        UINT8_C( 75), UINT8_C(114), UINT8_C(221), UINT8_C(165), UINT8_C(155), UINT8_C(146), UINT8_C(212), UINT8_C(251),
        UINT8_C( 12), UINT8_C(177), UINT8_C(208), UINT8_C(118), UINT8_C(232), UINT8_C( 43), UINT8_C(158), UINT8_C( 21),
        UINT8_C(228), UINT8_C(156), UINT8_C(208), UINT8_C(253), UINT8_C( 44), UINT8_C( 71), UINT8_C(118), UINT8_C(214),
        UINT8_C(107), UINT8_C( 66), UINT8_C(120), UINT8_C( 83), UINT8_C(217), UINT8_C( 28), UINT8_C(183), UINT8_C( 16),
        UINT8_C(142), UINT8_C(200), UINT8_C(206), UINT8_C( 41), UINT8_C( 35), UINT8_C(162), UINT8_C(115), UINT8_C( 48),
        UINT8_C( 83), UINT8_C( 67), UINT8_C(  9), UINT8_C( 22), UINT8_C( 53), UINT8_C(167), UINT8_C( 44), UINT8_C( 16) },
      UINT64_C( 2667595668122501376) },
    { UINT64_C(   43522417760137925),
      { UINT8_C(193), UINT8_C( 80), UINT8_C( 92), UINT8_C(228), UINT8_C( 61), UINT8_C(207), UINT8_C( 20), UINT8_C(108),
        UINT8_C( 18), UINT8_C(134), UINT8_C(130), UINT8_C(161), UINT8_C( 84), UINT8_C(174), UINT8_C(177), UINT8_C(189),
        UINT8_C(171), UINT8_C(190), UINT8_C( 83), UINT8_C(  9), UINT8_C( 66), UINT8_C( 35), UINT8_C(211), UINT8_C(  7),
        UINT8_C( 21), UINT8_C( 46), UINT8_C(146), UINT8_C(125), UINT8_C(206), UINT8_C( 44), UINT8_C(125), UINT8_C(143),
        UINT8_C(124), UINT8_C(217), UINT8_C(115), UINT8_C(186), UINT8_C(168), UINT8_C(136), UINT8_C( 38), UINT8_C(186),
        UINT8_C( 14), UINT8_C(168), UINT8_C( 91), UINT8_C( 98), UINT8_C( 87), UINT8_C( 12), UINT8_C( 32), UINT8_C(  2),
        UINT8_C(202), UINT8_C(115), UINT8_C( 11), UINT8_C( 12), UINT8_C(150), UINT8_C(223), UINT8_C( 20), UINT8_C(171),
        UINT8_C( 13), UINT8_C(166), UINT8_C( 40), UINT8_C(219), UINT8_C(210), UINT8_C(165), UINT8_C(106), UINT8_C( 79) },
      { UINT8_C(193), UINT8_C(222), UINT8_C(  9), UINT8_C( 38), UINT8_C(102), UINT8_C(207), UINT8_C(224), UINT8_C(108),
        UINT8_C(215), UINT8_C( 59), UINT8_C(215), UINT8_C(161), UINT8_C( 84), UINT8_C(247), UINT8_C( 48), UINT8_C(189),
        UINT8_C(106), UINT8_C(190), UINT8_C( 83), UINT8_C(  0), UINT8_C( 27), UINT8_C( 35), UINT8_C(171), UINT8_C(  7),
        UINT8_C(216), UINT8_C(211), UINT8_C(  4), UINT8_C(170), UINT8_C(206), UINT8_C( 44), UINT8_C(125), UINT8_C(246),
        UINT8_C( 76), UINT8_C(  2), UINT8_C(115), UINT8_C(186), UINT8_C(168), UINT8_C(252), UINT8_C( 39), UINT8_C(186),
        UINT8_C( 14), UINT8_C(168), UINT8_C( 91), UINT8_C( 98), UINT8_C( 87), UINT8_C( 12), UINT8_C( 32), UINT8_C( 95),
        UINT8_C(202), UINT8_C(115), UINT8_C( 11), UINT8_C(191), UINT8_C(223), UINT8_C(223), UINT8_C( 20), UINT8_C(183),
        UINT8_C( 13), UINT8_C(235), UINT8_C( 40), UINT8_C( 85), UINT8_C( 90), UINT8_C(165), UINT8_C(106), UINT8_C(166) },
      UINT64_C(     597069173788801) },
    { UINT64_C(15911964294344396926),
      { UINT8_C( 85), UINT8_C( 49), UINT8_C(155), UINT8_C( 52), UINT8_C( 59), UINT8_C(130), UINT8_C(236), UINT8_C( 24),
        UINT8_C(110), UINT8_C( 78), UINT8_C(109), UINT8_C(200), UINT8_C(169), UINT8_C(184), UINT8_C(110), UINT8_C(  7),
        UINT8_C( 31), UINT8_C(199), UINT8_C(151), UINT8_C(130), UINT8_C( 71), UINT8_C( 47), UINT8_C( 28), UINT8_C(197),
           UINT8_MAX, UINT8_C( 52), UINT8_C( 56), UINT8_C( 55), UINT8_C(219), UINT8_C( 10), UINT8_C( 19), UINT8_C( 48),
        UINT8_C( 59), UINT8_C(174), UINT8_C(101), UINT8_C(118), UINT8_C( 49), UINT8_C( 81), UINT8_C(142), UINT8_C(159),
        UINT8_C(159), UINT8_C(251), UINT8_C(103), UINT8_C( 72), UINT8_C(179), UINT8_C(213), UINT8_C( 80), UINT8_C(210),
        UINT8_C(157), UINT8_C(231), UINT8_C( 84), UINT8_C(228), UINT8_C( 22), UINT8_C(112), UINT8_C(170), UINT8_C( 22),
        UINT8_C(164), UINT8_C(226), UINT8_C( 77), UINT8_C(128), UINT8_C(237), UINT8_C( 97), UINT8_C(176), UINT8_C( 40) },
      { UINT8_C( 15), UINT8_C( 21), UINT8_C(159), UINT8_C( 64), UINT8_C( 59), UINT8_C( 45), UINT8_C(223), UINT8_C(  5),
        UINT8_C( 41), UINT8_C( 70), UINT8_C( 78), UINT8_C(200), UINT8_C(169), UINT8_C(184), UINT8_C(110), UINT8_C(  7),
        UINT8_C(133), UINT8_C(199), UINT8_C(157), UINT8_C(130), UINT8_C(116), UINT8_C( 47), UINT8_C(177), UINT8_C(197),
        UINT8_C( 42),    UINT8_MAX, UINT8_C( 56), UINT8_C( 23), UINT8_C( 96), UINT8_C( 73), UINT8_C( 63), UINT8_C(111),
        UINT8_C( 59), UINT8_C(222), UINT8_C(176), UINT8_C(118), UINT8_C( 12), UINT8_C( 81), UINT8_C(142), UINT8_C( 53),
        UINT8_C(159), UINT8_C(251), UINT8_C(103), UINT8_C( 72), UINT8_C(179), UINT8_C(192), UINT8_C( 80), UINT8_C(210),
        UINT8_C(157), UINT8_C(231), UINT8_C( 84), UINT8_C(228), UINT8_C(144), UINT8_C(136), UINT8_C(170), UINT8_C( 22),
        UINT8_C(164), UINT8_C(226), UINT8_C(209), UINT8_C(231), UINT8_C(237), UINT8_C( 16), UINT8_C( 87), UINT8_C( 40) },
      UINT64_C(10431048292812509200) },
    { UINT64_C(14279235476742095160),
      { UINT8_C( 82), UINT8_C(  1), UINT8_C(254), UINT8_C(226), UINT8_C(138), UINT8_C( 78), UINT8_C(156), UINT8_C( 17),
        UINT8_C( 55), UINT8_C(109), UINT8_C(249), UINT8_C(105), UINT8_C(125), UINT8_C( 80), UINT8_C(250), UINT8_C(108),
        UINT8_C( 87), UINT8_C( 79), UINT8_C(103), UINT8_C(237), UINT8_C(111), UINT8_C(151), UINT8_C( 90), UINT8_C(168),
        UINT8_C(217), UINT8_C(184), UINT8_C(151), UINT8_C(219), UINT8_C(194), UINT8_C(193), UINT8_C(161), UINT8_C( 20),
        UINT8_C(195), UINT8_C(159), UINT8_C(246), UINT8_C( 77), UINT8_C(237), UINT8_C(146), UINT8_C( 94), UINT8_C( 37),
           UINT8_MAX, UINT8_C( 87), UINT8_C(142), UINT8_C(124), UINT8_C(167), UINT8_C(136), UINT8_C(233), UINT8_C(254),
        UINT8_C(216), UINT8_C( 80), UINT8_C(236), UINT8_C( 71), UINT8_C(232), UINT8_C( 70), UINT8_C(239), UINT8_C(193),
        UINT8_C(254), UINT8_C(134), UINT8_C(156), UINT8_C(192), UINT8_C( 72), UINT8_C( 61), UINT8_C(212), UINT8_C( 11) },
      { UINT8_C(220), UINT8_C(202), UINT8_C(254), UINT8_C(226), UINT8_C( 92), UINT8_C(182), UINT8_C(238), UINT8_C( 17),
        UINT8_C( 14), UINT8_C(109), UINT8_C(216), UINT8_C(181), UINT8_C(125), UINT8_C(193), UINT8_C(180), UINT8_C(221),
        UINT8_C( 17), UINT8_C( 79), UINT8_C(103), UINT8_C(237), UINT8_C(111), UINT8_C( 20), UINT8_C(186), UINT8_C(228),
        UINT8_C(155), UINT8_C( 86), UINT8_C(165), UINT8_C(227), UINT8_C(194), UINT8_C(121), UINT8_C(238), UINT8_C( 20),
        UINT8_C(195), UINT8_C(159), UINT8_C( 57), UINT8_C( 77), UINT8_C(252), UINT8_C(146), UINT8_C( 94), UINT8_C( 37),
        UINT8_C(164), UINT8_C( 87), UINT8_C(192), UINT8_C(170), UINT8_C(149), UINT8_C(136), UINT8_C(135), UINT8_C(166),
        UINT8_C(216), UINT8_C(172), UINT8_C(236), UINT8_C(250), UINT8_C(193), UINT8_C( 90), UINT8_C(222), UINT8_C(193),
        UINT8_C(177), UINT8_C(134), UINT8_C(156), UINT8_C( 68), UINT8_C(253), UINT8_C( 45), UINT8_C(212), UINT8_C( 65) },
      UINT64_C( 5044031593394339848) },
    { UINT64_C(14046140847064562353),
      { UINT8_C(151), UINT8_C(141), UINT8_C(188), UINT8_C( 88), UINT8_C(231), UINT8_C(154), UINT8_C(180), UINT8_C(152),
        UINT8_C( 30), UINT8_C(243), UINT8_C(221), UINT8_C( 27), UINT8_C( 32), UINT8_C(145), UINT8_C( 92), UINT8_C(147),
        UINT8_C(126), UINT8_C( 61), UINT8_C(  2), UINT8_C(146), UINT8_C( 27), UINT8_C(124), UINT8_C( 75), UINT8_C(204),
        UINT8_C(182), UINT8_C(174), UINT8_C( 19), UINT8_C(100), UINT8_C(153), UINT8_C(  0), UINT8_C( 38), UINT8_C( 48),
        UINT8_C(141), UINT8_C(226), UINT8_C(136), UINT8_C(116), UINT8_C(125), UINT8_C( 60), UINT8_C( 13), UINT8_C(155),
        UINT8_C( 47), UINT8_C(234), UINT8_C(182), UINT8_C( 79), UINT8_C(123), UINT8_C( 18), UINT8_C(226), UINT8_C(249),
        UINT8_C( 79), UINT8_C(228), UINT8_C(139), UINT8_C(106), UINT8_C( 97), UINT8_C(215), UINT8_C( 55), UINT8_C( 23),
        UINT8_C(133), UINT8_C( 74), UINT8_C(124), UINT8_C( 30), UINT8_C( 74), UINT8_C(162), UINT8_C( 78), UINT8_C(215) },
      { UINT8_C(133), UINT8_C(214), UINT8_C(188), UINT8_C(  2), UINT8_C(231), UINT8_C(154), UINT8_C(157), UINT8_C(152),
        UINT8_C( 66), UINT8_C(243), UINT8_C(221), UINT8_C(189), UINT8_C(101), UINT8_C(114), UINT8_C( 92), UINT8_C(147),
        UINT8_C(126), UINT8_C( 61), UINT8_C( 31), UINT8_C(146), UINT8_C( 25), UINT8_C( 86), UINT8_C( 75), UINT8_C(158),
        UINT8_C(182), UINT8_C(174), UINT8_C( 19), UINT8_C(100), UINT8_C(238), UINT8_C( 11), UINT8_C( 38), UINT8_C(115),
        UINT8_C(226), UINT8_C( 12), UINT8_C(136), UINT8_C(244), UINT8_C(125), UINT8_C( 60), UINT8_C( 54), UINT8_C(155),
        UINT8_C( 47), UINT8_C(198), UINT8_C(182), UINT8_C(202), UINT8_C(123), UINT8_C( 27), UINT8_C(126), UINT8_C(144),
        UINT8_C( 93), UINT8_C(157), UINT8_C( 72), UINT8_C(106), UINT8_C(243), UINT8_C(215), UINT8_C( 21), UINT8_C( 23),
        UINT8_C(133), UINT8_C( 74), UINT8_C(124), UINT8_C( 30), UINT8_C(221), UINT8_C( 62), UINT8_C( 78), UINT8_C(191) },
      UINT64_C( 4803089708144067248) },
    { UINT64_C( 3853384566705929392),
      { UINT8_C(150), UINT8_C(193), UINT8_C(172), UINT8_C(137), UINT8_C(217), UINT8_C(193), UINT8_C( 29), UINT8_C( 60),
        UINT8_C(147), UINT8_C(154), UINT8_C(141), UINT8_C(112), UINT8_C(217), UINT8_C( 81), UINT8_C( 48), UINT8_C( 36),
        UINT8_C(138), UINT8_C(228), UINT8_C(212), UINT8_C(213), UINT8_C(206), UINT8_C( 43), UINT8_C(133), UINT8_C(126),
        UINT8_C(232),    UINT8_MAX, UINT8_C(104), UINT8_C(192), UINT8_C(247), UINT8_C(225), UINT8_C(245), UINT8_C(141),
        UINT8_C(163), UINT8_C(161), UINT8_C( 23), UINT8_C(124), UINT8_C( 98), UINT8_C( 52), UINT8_C(184), UINT8_C(245),
        UINT8_C(206), UINT8_C( 69), UINT8_C(102), UINT8_C(167), UINT8_C(150), UINT8_C(150), UINT8_C(203), UINT8_C( 32),
        UINT8_C(122), UINT8_C(159), UINT8_C(245), UINT8_C( 72), UINT8_C(203), UINT8_C(122), UINT8_C(198), UINT8_C(179),
        UINT8_C(121), UINT8_C( 46), UINT8_C(115), UINT8_C(112), UINT8_C( 16), UINT8_C(104), UINT8_C(254), UINT8_C(179) },
      { UINT8_C( 10), UINT8_C(193), UINT8_C(172), UINT8_C(108), UINT8_C( 73), UINT8_C(231), UINT8_C( 98), UINT8_C( 60),
        UINT8_C(147), UINT8_C(154), UINT8_C(191), UINT8_C(112), UINT8_C(217), UINT8_C(138), UINT8_C(226), UINT8_C(216),
        UINT8_C( 42), UINT8_C(215), UINT8_C( 32), UINT8_C(213), UINT8_C(206), UINT8_C( 43), UINT8_C(133), UINT8_C(126),
        UINT8_C( 21), UINT8_C( 27), UINT8_C( 58), UINT8_C(192), UINT8_C(247), UINT8_C( 56), UINT8_C(216), UINT8_C(141),
        UINT8_C(163), UINT8_C(161), UINT8_C( 23), UINT8_C(124), UINT8_C( 98), UINT8_C( 52), UINT8_C(174), UINT8_C(245),
        UINT8_C( 36), UINT8_C( 69), UINT8_C(220), UINT8_C(167), UINT8_C(247), UINT8_C(190), UINT8_C(203), UINT8_C( 33),
        UINT8_C(149), UINT8_C(159), UINT8_C(245), UINT8_C( 72), UINT8_C(203), UINT8_C(122), UINT8_C(198), UINT8_C(117),
        UINT8_C(121), UINT8_C( 46), UINT8_C(154), UINT8_C(112), UINT8_C( 16), UINT8_C(114), UINT8_C(234), UINT8_C(179) },
      UINT64_C( 1258835915811854464) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512i a = simde_x_mm512_loadu_epu8(test_vec[i].a);
    simde__m512i b = simde_x_mm512_loadu_epu8(test_vec[i].b);
    simde__mmask64 r = simde_mm512_mask_cmpeq_epu8_mask(test_vec[i].k1, a, b);
    simde_assert_equal_mmask64(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask64 k1 = simde_test_x86_random_mmask64();
    simde__m512i a = simde_test_x86_random_u8x64();
    simde__m512i b = simde_x_mm512_mask_blend_epu8(simde_test_x86_random_mmask64(), a, simde_test_x86_random_u8x64());
    simde__mmask64 r = simde_mm512_mask_cmpeq_epu8_mask(k1, a, b);

    simde_test_x86_write_mmask64(2, k1, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_u8x64(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_u8x64(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask64(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_cmpeq_epu16_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const uint16_t a[8];
    const uint16_t b[8];
    const simde__mmask8 r;
  } test_vec[] = {
    { { UINT16_C(41967), UINT16_C(26090), UINT16_C(47385), UINT16_C(47098), UINT16_C(28601), UINT16_C(47352), UINT16_C(32569), UINT16_C(50519) },
      { UINT16_C(38942), UINT16_C(38371), UINT16_C(47385), UINT16_C(59245), UINT16_C(50302), UINT16_C(32856), UINT16_C(32569), UINT16_C(26923) },
      UINT8_C( 68) },
    { { UINT16_C(52758), UINT16_C(53204), UINT16_C(35784), UINT16_C(14216), UINT16_C(16515), UINT16_C(  624), UINT16_C(13719), UINT16_C(12321) },
      { UINT16_C(46616), UINT16_C(53204), UINT16_C(35784), UINT16_C(59349), UINT16_C(22022), UINT16_C(  624), UINT16_C(13719), UINT16_C(38873) },
      UINT8_C(102) },
    { { UINT16_C(26286), UINT16_C(14689), UINT16_C(39406), UINT16_C(11965), UINT16_C(48905), UINT16_C(16326), UINT16_C(63200), UINT16_C(38487) },
      { UINT16_C(26286), UINT16_C(27577), UINT16_C(39406), UINT16_C(55921), UINT16_C(36866), UINT16_C(16326), UINT16_C(62313), UINT16_C(38487) },
      UINT8_C(165) },
    { { UINT16_C(20935), UINT16_C(24648), UINT16_C(30478), UINT16_C(52586), UINT16_C(43325), UINT16_C(13230), UINT16_C(17408), UINT16_C(45040) },
      { UINT16_C(20935), UINT16_C(40756), UINT16_C( 3788), UINT16_C(23713), UINT16_C(43325), UINT16_C(24262), UINT16_C(17408), UINT16_C(45040) },
      UINT8_C(209) },
    { { UINT16_C(64512), UINT16_C(30524), UINT16_C( 2662), UINT16_C( 4020), UINT16_C(59320), UINT16_C(64528), UINT16_C(49111), UINT16_C(13050) },
      { UINT16_C(64512), UINT16_C(  767), UINT16_C(23355), UINT16_C( 4020), UINT16_C(51745), UINT16_C(64528), UINT16_C(49111), UINT16_C(13050) },
      UINT8_C(233) },
    { { UINT16_C(64106), UINT16_C(29821), UINT16_C(36015), UINT16_C(38444), UINT16_C(10396), UINT16_C(23662), UINT16_C(40995), UINT16_C(48207) },
      { UINT16_C(64106), UINT16_C(29821), UINT16_C(36015), UINT16_C(34844), UINT16_C(10396), UINT16_C(23662), UINT16_C(40995), UINT16_C(45903) },
      UINT8_C(119) },
    { { UINT16_C(10188), UINT16_C(22839), UINT16_C(52819), UINT16_C(31733), UINT16_C(20796), UINT16_C(56478), UINT16_C(23457), UINT16_C(62076) },
      { UINT16_C(10188), UINT16_C(62384), UINT16_C(52819), UINT16_C(31733), UINT16_C(19268), UINT16_C(56478), UINT16_C(43931), UINT16_C(26458) },
      UINT8_C( 45) },
    { { UINT16_C(49298), UINT16_C(24613), UINT16_C(41142), UINT16_C( 1948), UINT16_C(30783), UINT16_C(39592), UINT16_C(39924), UINT16_C(27628) },
      { UINT16_C(57419), UINT16_C(24613), UINT16_C(41142), UINT16_C( 1948), UINT16_C(30783), UINT16_C(39592), UINT16_C(39924), UINT16_C(27628) },
      UINT8_C(254) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i a = simde_x_mm_loadu_epu16(test_vec[i].a);
    simde__m128i b = simde_x_mm_loadu_epu16(test_vec[i].b);
    simde__mmask8 r = simde_mm_cmpeq_epu16_mask(a, b);
    simde_assert_equal_mmask8(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i a = simde_test_x86_random_u16x8();
    simde__m128i b = simde_x_mm_mask_blend_epu16(simde_test_x86_random_mmask8(), a, simde_test_x86_random_u16x8());
    simde__mmask8 r = simde_mm_cmpeq_epu16_mask(a, b);

    simde_test_x86_write_u16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_u16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_mask_cmpeq_epu16_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k1;
    const uint16_t a[8];
    const uint16_t b[8];
    const simde__mmask8 r;
  } test_vec[] = {
    { UINT8_C( 72),
      { UINT16_C(47079), UINT16_C(33768), UINT16_C(10174), UINT16_C(26619), UINT16_C(61633), UINT16_C(44546), UINT16_C(19803), UINT16_C(23182) },
      { UINT16_C(47079), UINT16_C(33768), UINT16_C(10174), UINT16_C(26619), UINT16_C(11007), UINT16_C(44546), UINT16_C(19803), UINT16_C(39018) },
      UINT8_C( 72) },
    { UINT8_C( 83),
      { UINT16_C(19995), UINT16_C( 5754), UINT16_C(15541), UINT16_C(46854), UINT16_C(25322), UINT16_C(30725), UINT16_C(55228), UINT16_C(50680) },
      { UINT16_C(19995), UINT16_C(42611), UINT16_C(29518), UINT16_C( 9936), UINT16_C(33173), UINT16_C(30725), UINT16_C(36633), UINT16_C(13395) },
      UINT8_C(  1) },
    { UINT8_C(205),
      { UINT16_C(37707), UINT16_C(20745), UINT16_C(62283), UINT16_C(20659), UINT16_C(28779), UINT16_C(25639), UINT16_C(38965), UINT16_C(43035) },
      { UINT16_C(37707), UINT16_C(20745), UINT16_C(62283), UINT16_C(20659), UINT16_C(43697), UINT16_C(25639), UINT16_C(38965), UINT16_C(10961) },
      UINT8_C( 77) },
    { UINT8_C(219),
      { UINT16_C(56187), UINT16_C(12238), UINT16_C(14891), UINT16_C(21151), UINT16_C(54430), UINT16_C(47595), UINT16_C(10876), UINT16_C(38946) },
      { UINT16_C(56187), UINT16_C(51785), UINT16_C(14891), UINT16_C(24949), UINT16_C(54430), UINT16_C(47595), UINT16_C(61054), UINT16_C(63914) },
      UINT8_C( 17) },
    { UINT8_C(121),
      { UINT16_C(62760), UINT16_C(51123), UINT16_C(20808), UINT16_C(13211), UINT16_C( 6154), UINT16_C(11357), UINT16_C(38576), UINT16_C(63967) },
      { UINT16_C(62760), UINT16_C(55027), UINT16_C(61826), UINT16_C(57386), UINT16_C( 6154), UINT16_C(11357), UINT16_C(38576), UINT16_C(51940) },
      UINT8_C(113) },
    { UINT8_C(151),
      { UINT16_C(54929), UINT16_C(11752), UINT16_C(61961), UINT16_C(26181), UINT16_C(62750), UINT16_C(65020), UINT16_C(24046), UINT16_C(57630) },
      { UINT16_C(41011), UINT16_C(24018), UINT16_C(61961), UINT16_C(20229), UINT16_C(62750), UINT16_C(65020), UINT16_C(30065), UINT16_C(57630) },
      UINT8_C(148) },
    { UINT8_C( 96),
      { UINT16_C(21551), UINT16_C(29778), UINT16_C(29114), UINT16_C(46953), UINT16_C(22382), UINT16_C(36116), UINT16_C(18488), UINT16_C( 2605) },
      { UINT16_C(21551), UINT16_C(43933), UINT16_C(29114), UINT16_C(58450), UINT16_C(50044), UINT16_C(62554), UINT16_C(42437), UINT16_C(62805) },
      UINT8_C(  0) },
    { UINT8_C(167),
      { UINT16_C(46185), UINT16_C(54040), UINT16_C(34667), UINT16_C(32810), UINT16_C(25364), UINT16_C(16840), UINT16_C(28013), UINT16_C( 2799) },
      { UINT16_C(60440), UINT16_C(27301), UINT16_C( 8657), UINT16_C(11053), UINT16_C(62229), UINT16_C(27344), UINT16_C(51944), UINT16_C( 2799) },
      UINT8_C(128) },  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i a = simde_x_mm_loadu_epu16(test_vec[i].a);
    simde__m128i b = simde_x_mm_loadu_epu16(test_vec[i].b);
    simde__mmask8 r = simde_mm_mask_cmpeq_epu16_mask(test_vec[i].k1, a, b);
    simde_assert_equal_mmask8(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k1 = simde_test_x86_random_mmask8();
    simde__m128i a = simde_test_x86_random_u8x16();
    simde__m128i b = simde_x_mm_mask_blend_epu16(simde_test_x86_random_mmask8(), a, simde_test_x86_random_u16x8());
    simde__mmask8 r = simde_mm_mask_cmpeq_epu16_mask(k1, a, b);

    simde_test_x86_write_mmask8(2, k1, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_u16x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_u16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_cmpeq_epu16_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const uint16_t a[16];
    const uint16_t b[16];
    const simde__mmask16 r;
  } test_vec[] = {
    { { UINT16_C(34285), UINT16_C( 7055), UINT16_C( 6444), UINT16_C(33065), UINT16_C( 9671), UINT16_C(37040), UINT16_C(47335), UINT16_C(14700),
        UINT16_C( 4492), UINT16_C(28894), UINT16_C(32842), UINT16_C(22071), UINT16_C(55331), UINT16_C(24286), UINT16_C( 3960), UINT16_C(25882) },
      { UINT16_C(34285), UINT16_C( 7055), UINT16_C(43715), UINT16_C(33065), UINT16_C(61903), UINT16_C(37040), UINT16_C(47335), UINT16_C(14064),
        UINT16_C(52888), UINT16_C(28894), UINT16_C(56655), UINT16_C(22071), UINT16_C( 6070), UINT16_C(24286), UINT16_C( 3960), UINT16_C(25882) },
      UINT16_C(60011) },
    { { UINT16_C(22394), UINT16_C(48319), UINT16_C(36577), UINT16_C(64685), UINT16_C(22341), UINT16_C(13699), UINT16_C( 7309), UINT16_C(13059),
        UINT16_C(21246), UINT16_C(14096), UINT16_C(50884), UINT16_C(38223), UINT16_C(30197), UINT16_C(35199), UINT16_C( 4912), UINT16_C(43678) },
      { UINT16_C(23914), UINT16_C(19558), UINT16_C(36577), UINT16_C(12360), UINT16_C(52331), UINT16_C(63589), UINT16_C(27112), UINT16_C(13059),
        UINT16_C(15291), UINT16_C(32798), UINT16_C(50884), UINT16_C(38223), UINT16_C(30197), UINT16_C( 4736), UINT16_C( 4912), UINT16_C(43678) },
      UINT16_C(56452) },
    { { UINT16_C(26206), UINT16_C(42807), UINT16_C(41623), UINT16_C(64627), UINT16_C(23450), UINT16_C(50533), UINT16_C( 8513), UINT16_C(24321),
        UINT16_C(  929), UINT16_C(46796), UINT16_C(45050), UINT16_C(31306), UINT16_C(62145), UINT16_C(32408), UINT16_C( 4869), UINT16_C(25506) },
      { UINT16_C(26206), UINT16_C(42807), UINT16_C(41623), UINT16_C(64627), UINT16_C(29400), UINT16_C( 6876), UINT16_C( 8513), UINT16_C(13433),
        UINT16_C(  929), UINT16_C(56042), UINT16_C(45050), UINT16_C(46676), UINT16_C(60455), UINT16_C(32408), UINT16_C( 4869), UINT16_C(30864) },
      UINT16_C(25935) },
    { { UINT16_C(11401), UINT16_C(38424), UINT16_C(61507), UINT16_C( 7944), UINT16_C(39946), UINT16_C(34044), UINT16_C(56528), UINT16_C(48074),
        UINT16_C(49078), UINT16_C( 2800), UINT16_C( 6005), UINT16_C(43766), UINT16_C(62788), UINT16_C(54401), UINT16_C(12909), UINT16_C(63086) },
      { UINT16_C(34398), UINT16_C(38424), UINT16_C(61507), UINT16_C( 7944), UINT16_C(48177), UINT16_C(34044), UINT16_C(53144), UINT16_C(20156),
        UINT16_C(49078), UINT16_C( 2800), UINT16_C(20164), UINT16_C(43766), UINT16_C(12355), UINT16_C(45532), UINT16_C(12909), UINT16_C(63086) },
      UINT16_C(52014) },
    { { UINT16_C(18530), UINT16_C( 8905), UINT16_C(64201), UINT16_C(53215), UINT16_C(30715), UINT16_C(47262), UINT16_C(11718), UINT16_C( 7780),
        UINT16_C(10289), UINT16_C(57197), UINT16_C(45104), UINT16_C( 3087), UINT16_C(29025), UINT16_C( 2391), UINT16_C(10290), UINT16_C(37949) },
      { UINT16_C(18530), UINT16_C( 8905), UINT16_C(38144), UINT16_C(64264), UINT16_C(42765), UINT16_C(54195), UINT16_C(11718), UINT16_C( 1521),
        UINT16_C(10289), UINT16_C(29156), UINT16_C(45104), UINT16_C( 3087), UINT16_C(29025), UINT16_C(38777), UINT16_C(46844), UINT16_C(27691) },
      UINT16_C( 7491) },
    { { UINT16_C(48294), UINT16_C(44663), UINT16_C(33976), UINT16_C(27477), UINT16_C(10583), UINT16_C(18819), UINT16_C(50222), UINT16_C( 5031),
        UINT16_C(46645), UINT16_C(45575), UINT16_C(27687), UINT16_C(41095), UINT16_C(33540), UINT16_C(12119), UINT16_C( 5104), UINT16_C(38417) },
      { UINT16_C(48294), UINT16_C(34884), UINT16_C(39437), UINT16_C(27477), UINT16_C(10583), UINT16_C(18819), UINT16_C(21819), UINT16_C( 5031),
        UINT16_C( 3084), UINT16_C(13090), UINT16_C(43384), UINT16_C(41095), UINT16_C(10797), UINT16_C( 7596), UINT16_C(48446), UINT16_C( 3763) },
      UINT16_C( 2233) },
    { { UINT16_C(21654), UINT16_C(35217), UINT16_C(21945), UINT16_C(26368), UINT16_C(15175), UINT16_C(19644), UINT16_C(51371), UINT16_C(52824),
        UINT16_C(53499), UINT16_C(53111), UINT16_C(42061), UINT16_C(63993), UINT16_C(14273), UINT16_C(29878), UINT16_C(64837), UINT16_C(56172) },
      { UINT16_C(21654), UINT16_C( 2661), UINT16_C(25938), UINT16_C(26368), UINT16_C(11681), UINT16_C(19644), UINT16_C(15862), UINT16_C(61722),
        UINT16_C(37390), UINT16_C(23488), UINT16_C(47670), UINT16_C(63993), UINT16_C( 2801), UINT16_C(14188), UINT16_C(55303), UINT16_C(56172) },
      UINT16_C(34857) },
    { { UINT16_C(10338), UINT16_C(54237), UINT16_C(32450), UINT16_C(42753), UINT16_C(63434), UINT16_C(58853), UINT16_C(62440), UINT16_C(43383),
        UINT16_C(44366), UINT16_C(41571), UINT16_C(21669), UINT16_C( 4780), UINT16_C(46219), UINT16_C(40682), UINT16_C(49164), UINT16_C(28437) },
      { UINT16_C(62185), UINT16_C(54237), UINT16_C(17264), UINT16_C(42753), UINT16_C(14138), UINT16_C( 8992), UINT16_C(62440), UINT16_C(30924),
        UINT16_C(12100), UINT16_C(41571), UINT16_C(21669), UINT16_C( 4092), UINT16_C(59003), UINT16_C(34733), UINT16_C(49164), UINT16_C(28437) },
      UINT16_C(50762) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i a = simde_x_mm256_loadu_epu16(test_vec[i].a);
    simde__m256i b = simde_x_mm256_loadu_epu16(test_vec[i].b);
    simde__mmask16 r = simde_mm256_cmpeq_epu16_mask(a, b);
    simde_assert_equal_mmask16(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m256i a = simde_test_x86_random_u16x16();
    simde__m256i b = simde_x_mm256_mask_blend_epu16(simde_test_x86_random_mmask16(), a, simde_test_x86_random_u16x16());
    simde__mmask16 r = simde_mm256_cmpeq_epu16_mask(a, b);

    simde_test_x86_write_u16x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_u16x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_mask_cmpeq_epu16_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask16 k1;
    const uint16_t a[16];
    const uint16_t b[16];
    const simde__mmask16 r;
  } test_vec[] = {
    { UINT16_C( 9531),
      { UINT16_C(36220), UINT16_C(46944), UINT16_C(32965), UINT16_C(61402), UINT16_C(42519), UINT16_C(23656), UINT16_C(33493), UINT16_C(22598),
        UINT16_C(16969), UINT16_C(50279), UINT16_C( 5160), UINT16_C(53068), UINT16_C(17111), UINT16_C(35935), UINT16_C(39547), UINT16_C(63665) },
      { UINT16_C( 4648), UINT16_C(60847), UINT16_C(35218), UINT16_C(43740), UINT16_C(17455), UINT16_C( 1030), UINT16_C(19655), UINT16_C( 4188),
        UINT16_C(16969), UINT16_C(46805), UINT16_C( 8664), UINT16_C(53068), UINT16_C(17111), UINT16_C(35935), UINT16_C(39547), UINT16_C(43223) },
      UINT16_C( 8448) },
    { UINT16_C(37269),
      { UINT16_C(28943), UINT16_C(15931), UINT16_C(16822), UINT16_C(32066), UINT16_C(40589), UINT16_C( 7053), UINT16_C(25186), UINT16_C(15314),
        UINT16_C(22659), UINT16_C(59370), UINT16_C( 9789), UINT16_C(48582), UINT16_C(40211), UINT16_C( 4709), UINT16_C(64035), UINT16_C(12963) },
      { UINT16_C(28943), UINT16_C( 8816), UINT16_C(45600), UINT16_C(32066), UINT16_C(40589), UINT16_C(46025), UINT16_C(25186), UINT16_C( 4846),
        UINT16_C(55539), UINT16_C(59370), UINT16_C( 9789), UINT16_C(48582), UINT16_C(40211), UINT16_C(32547), UINT16_C(64035), UINT16_C(12963) },
      UINT16_C(36881) },
    { UINT16_C(50908),
      { UINT16_C(31699), UINT16_C( 9332), UINT16_C(16040), UINT16_C(14295), UINT16_C(50649), UINT16_C(52553), UINT16_C(17309), UINT16_C(40190),
        UINT16_C(60418), UINT16_C(24493), UINT16_C(53568), UINT16_C(36830), UINT16_C(37016), UINT16_C(15945), UINT16_C( 9905), UINT16_C(34052) },
      { UINT16_C(31699), UINT16_C( 9332), UINT16_C(16040), UINT16_C(14295), UINT16_C(51781), UINT16_C(52553), UINT16_C(23309), UINT16_C(40190),
        UINT16_C(60418), UINT16_C(24493), UINT16_C(19965), UINT16_C(38167), UINT16_C(25053), UINT16_C(36563), UINT16_C( 9905), UINT16_C(10259) },
      UINT16_C(17036) },
    { UINT16_C( 1906),
      { UINT16_C(62012), UINT16_C(33176), UINT16_C(62908), UINT16_C(51556), UINT16_C(57937), UINT16_C(39385), UINT16_C(18190), UINT16_C( 2849),
        UINT16_C(14740), UINT16_C(29088), UINT16_C(29594), UINT16_C( 8448), UINT16_C( 4939), UINT16_C(39753), UINT16_C(48080), UINT16_C( 3235) },
      { UINT16_C(15278), UINT16_C(27278), UINT16_C(62000), UINT16_C(51556), UINT16_C(57937), UINT16_C(39385), UINT16_C(15444), UINT16_C(59886),
        UINT16_C(14740), UINT16_C(29088), UINT16_C(29594), UINT16_C(19760), UINT16_C(31086), UINT16_C(39753), UINT16_C(35893), UINT16_C(58186) },
      UINT16_C( 1840) },
    { UINT16_C(63309),
      { UINT16_C(33226), UINT16_C(40825), UINT16_C(37774), UINT16_C(58242), UINT16_C(28879), UINT16_C(17612), UINT16_C( 9983), UINT16_C(  595),
        UINT16_C(33665), UINT16_C(61263), UINT16_C(14589), UINT16_C(12845), UINT16_C(30660), UINT16_C(35605), UINT16_C(25168), UINT16_C( 6787) },
      { UINT16_C(33226), UINT16_C(40825), UINT16_C(15247), UINT16_C(58242), UINT16_C(28879), UINT16_C(17612), UINT16_C( 9983), UINT16_C(  595),
        UINT16_C(33665), UINT16_C(61263), UINT16_C(14589), UINT16_C(12845), UINT16_C(30660), UINT16_C(35605), UINT16_C(25168), UINT16_C( 1479) },
      UINT16_C(30537) },
    { UINT16_C(38007),
      { UINT16_C(52668), UINT16_C(26867), UINT16_C(38638), UINT16_C(13843), UINT16_C(49549), UINT16_C( 2303), UINT16_C(47038), UINT16_C(62335),
        UINT16_C(10652), UINT16_C(63981), UINT16_C(29671), UINT16_C( 2213), UINT16_C(27771), UINT16_C(32781), UINT16_C(34285), UINT16_C(43284) },
      { UINT16_C(52668), UINT16_C(16401), UINT16_C( 9373), UINT16_C(11127), UINT16_C(49549), UINT16_C( 2303), UINT16_C(47038), UINT16_C(62335),
        UINT16_C(10652), UINT16_C(63981), UINT16_C(27127), UINT16_C(29643), UINT16_C(55765), UINT16_C(49907), UINT16_C( 1886), UINT16_C(43284) },
      UINT16_C(32881) },
    { UINT16_C(44016),
      { UINT16_C(26529), UINT16_C(34518), UINT16_C( 2526), UINT16_C( 3114), UINT16_C(49596), UINT16_C(38870), UINT16_C(39493), UINT16_C(15706),
        UINT16_C( 9731), UINT16_C(55472), UINT16_C(41983), UINT16_C(23963), UINT16_C( 1706), UINT16_C(47117), UINT16_C(64899), UINT16_C( 9315) },
      { UINT16_C(26529), UINT16_C(17322), UINT16_C( 2526), UINT16_C(65359), UINT16_C(49596), UINT16_C(56215), UINT16_C(61887), UINT16_C(15706),
        UINT16_C( 9731), UINT16_C( 5787), UINT16_C(13931), UINT16_C( 5491), UINT16_C( 1706), UINT16_C(47117), UINT16_C(64899), UINT16_C(58339) },
      UINT16_C( 8592) },
    { UINT16_C(44582),
      { UINT16_C(30050), UINT16_C(63661), UINT16_C(17562), UINT16_C(23251), UINT16_C(60214), UINT16_C(19740), UINT16_C(47027), UINT16_C( 7780),
        UINT16_C(55277), UINT16_C(10803), UINT16_C(   88), UINT16_C(55017), UINT16_C(52528), UINT16_C(39865), UINT16_C(57179), UINT16_C(48457) },
      { UINT16_C(30050), UINT16_C(61109), UINT16_C(17562), UINT16_C(23251), UINT16_C(60214), UINT16_C(19740), UINT16_C(47027), UINT16_C( 2628),
        UINT16_C(55277), UINT16_C(10803), UINT16_C(   88), UINT16_C(43048), UINT16_C(57834), UINT16_C(17731), UINT16_C(57179), UINT16_C( 5123) },
      UINT16_C( 1572) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i a = simde_x_mm256_loadu_epu16(test_vec[i].a);
    simde__m256i b = simde_x_mm256_loadu_epu16(test_vec[i].b);
    simde__mmask16 r = simde_mm256_mask_cmpeq_epu16_mask(test_vec[i].k1, a, b);
    simde_assert_equal_mmask16(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask16 k1 = simde_test_x86_random_mmask16();
    simde__m256i a = simde_test_x86_random_u16x16();
    simde__m256i b = simde_x_mm256_mask_blend_epu16(simde_test_x86_random_mmask16(), a, simde_test_x86_random_u16x16());
    simde__mmask16 r = simde_mm256_mask_cmpeq_epu16_mask(k1, a, b);

    simde_test_x86_write_mmask16(2, k1, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_u16x16(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_u16x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_cmpeq_epu16_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const uint16_t a[32];
    const uint16_t b[32];
    const simde__mmask32 r;
  } test_vec[] = {
    { { UINT16_C(30564), UINT16_C(64050), UINT16_C(40987), UINT16_C(53280), UINT16_C(24199), UINT16_C(35800), UINT16_C(51595), UINT16_C(14813),
        UINT16_C(41579), UINT16_C(54980), UINT16_C(17791), UINT16_C(15149), UINT16_C(32414), UINT16_C(54252), UINT16_C(10540), UINT16_C(37066),
        UINT16_C(64673), UINT16_C(48266), UINT16_C(43933), UINT16_C( 9357), UINT16_C(25865), UINT16_C(38063), UINT16_C(35887), UINT16_C(39629),
        UINT16_C(37422), UINT16_C(44656), UINT16_C(40407), UINT16_C(30185), UINT16_C(54556), UINT16_C(18504), UINT16_C( 4863), UINT16_C(41177) },
      { UINT16_C(25359), UINT16_C(44124), UINT16_C(59662), UINT16_C( 6096), UINT16_C(32591), UINT16_C(32427), UINT16_C(30987), UINT16_C(14872),
        UINT16_C(41579), UINT16_C(54980), UINT16_C(53542), UINT16_C(16984), UINT16_C(41126), UINT16_C(42378), UINT16_C(25523), UINT16_C(49733),
        UINT16_C(64673), UINT16_C(48266), UINT16_C(16011), UINT16_C(56045), UINT16_C(25865), UINT16_C(38063), UINT16_C(28689), UINT16_C( 7170),
        UINT16_C(60153), UINT16_C( 8191), UINT16_C(40407), UINT16_C(30185), UINT16_C(60407), UINT16_C(43527), UINT16_C(19791), UINT16_C( 5740) },
      UINT32_C( 204669696) },
    { { UINT16_C(55320), UINT16_C(54613), UINT16_C(44401), UINT16_C(33438), UINT16_C(40990), UINT16_C( 6047), UINT16_C(40587), UINT16_C(17974),
        UINT16_C(38901), UINT16_C(60584), UINT16_C(45186), UINT16_C(53655), UINT16_C( 1021), UINT16_C(60647), UINT16_C(54238), UINT16_C(63078),
        UINT16_C(48043), UINT16_C( 7372), UINT16_C(27241), UINT16_C(34719), UINT16_C(15882), UINT16_C(38302), UINT16_C(54492), UINT16_C(53724),
        UINT16_C(33899), UINT16_C(60861), UINT16_C(21556), UINT16_C(12735), UINT16_C(42584), UINT16_C(13853), UINT16_C(33913), UINT16_C( 9516) },
      { UINT16_C(55320), UINT16_C(54613), UINT16_C(57442), UINT16_C(27951), UINT16_C(52510), UINT16_C(64002), UINT16_C(40587), UINT16_C(17974),
        UINT16_C(38901), UINT16_C(60584), UINT16_C(47581), UINT16_C(13769), UINT16_C( 1021), UINT16_C(60647), UINT16_C(54238), UINT16_C(63078),
        UINT16_C(48043), UINT16_C( 7372), UINT16_C(33312), UINT16_C(15968), UINT16_C(15882), UINT16_C(38302), UINT16_C(54492), UINT16_C(53724),
        UINT16_C(63373), UINT16_C(27451), UINT16_C(21556), UINT16_C(12735), UINT16_C( 3307), UINT16_C(21993), UINT16_C(33913), UINT16_C( 9516) },
      UINT32_C(3438539715) },
    { { UINT16_C(34772), UINT16_C( 9093), UINT16_C(48874), UINT16_C(11028), UINT16_C( 4802), UINT16_C(20687), UINT16_C( 2569), UINT16_C(47803),
        UINT16_C(23311), UINT16_C(64202), UINT16_C(45927), UINT16_C( 2895), UINT16_C(20378), UINT16_C(49216), UINT16_C(26529), UINT16_C(29959),
        UINT16_C(36079), UINT16_C(55704), UINT16_C(44362), UINT16_C( 3076), UINT16_C(54207), UINT16_C(51292), UINT16_C( 6109), UINT16_C(60546),
        UINT16_C(19571), UINT16_C(56038), UINT16_C(14079), UINT16_C(39398), UINT16_C( 9861), UINT16_C( 9818), UINT16_C(24973), UINT16_C(31899) },
      { UINT16_C(13293), UINT16_C(14165), UINT16_C(23008), UINT16_C(40771), UINT16_C(41004), UINT16_C( 2664), UINT16_C(60087), UINT16_C(10998),
        UINT16_C(56631), UINT16_C(13829), UINT16_C(45927), UINT16_C( 2895), UINT16_C(20378), UINT16_C(49216), UINT16_C(22923), UINT16_C(30747),
        UINT16_C(36079), UINT16_C(55704), UINT16_C(44362), UINT16_C( 3076), UINT16_C(54207), UINT16_C(51292), UINT16_C(63327), UINT16_C(38516),
        UINT16_C(31188), UINT16_C(59340), UINT16_C(40036), UINT16_C(30079), UINT16_C(15814), UINT16_C(20756), UINT16_C(24973), UINT16_C(31899) },
      UINT32_C(3225369600) },
    { { UINT16_C(40043), UINT16_C(64864), UINT16_C(24592), UINT16_C(28487), UINT16_C(48215), UINT16_C(11013), UINT16_C(53813), UINT16_C(39442),
        UINT16_C(37230), UINT16_C(13583), UINT16_C( 9166), UINT16_C(25734), UINT16_C(20562), UINT16_C(62087), UINT16_C( 5832), UINT16_C(13147),
        UINT16_C(48050), UINT16_C(49969), UINT16_C(30748), UINT16_C(29490), UINT16_C(14388), UINT16_C(27295), UINT16_C(45322), UINT16_C(30724),
        UINT16_C( 4931), UINT16_C( 4525), UINT16_C(13367), UINT16_C(35190), UINT16_C(64900), UINT16_C(19579), UINT16_C(55059), UINT16_C(50816) },
      { UINT16_C(40043), UINT16_C(64864), UINT16_C(47913), UINT16_C(24098), UINT16_C(48215), UINT16_C(11013), UINT16_C(52338), UINT16_C(46454),
        UINT16_C( 9183), UINT16_C( 5831), UINT16_C(15703), UINT16_C(56224), UINT16_C( 6970), UINT16_C(19752), UINT16_C( 5832), UINT16_C(13147),
        UINT16_C(40025), UINT16_C(33331), UINT16_C(30748), UINT16_C(29490), UINT16_C(14388), UINT16_C(27295), UINT16_C(45322), UINT16_C(30724),
        UINT16_C( 1506), UINT16_C(14954), UINT16_C(13367), UINT16_C(35190), UINT16_C(15654), UINT16_C( 6346), UINT16_C(56805), UINT16_C(16029) },
      UINT32_C( 217890867) },
    { { UINT16_C(41254), UINT16_C(15645), UINT16_C(26186), UINT16_C(48838), UINT16_C( 1061), UINT16_C( 2066), UINT16_C(32010), UINT16_C(19522),
        UINT16_C(22407), UINT16_C(44489), UINT16_C(37781), UINT16_C(31430), UINT16_C(25456), UINT16_C(60089), UINT16_C(31284), UINT16_C(23484),
        UINT16_C(55835), UINT16_C(26008), UINT16_C(24128), UINT16_C(26148), UINT16_C(13922), UINT16_C(27758), UINT16_C(45235), UINT16_C(15289),
        UINT16_C(33287), UINT16_C(40168), UINT16_C(44565), UINT16_C(34071), UINT16_C(53266), UINT16_C(18032), UINT16_C(11338), UINT16_C(26017) },
      { UINT16_C(41254), UINT16_C(15645), UINT16_C(26186), UINT16_C(48838), UINT16_C( 6949), UINT16_C(55654), UINT16_C( 8139), UINT16_C(53780),
        UINT16_C(22407), UINT16_C(44489), UINT16_C(37781), UINT16_C(31430), UINT16_C(44118), UINT16_C(40963), UINT16_C(31284), UINT16_C(23484),
        UINT16_C(53470), UINT16_C(30246), UINT16_C(54207), UINT16_C(58736), UINT16_C(13922), UINT16_C(27758), UINT16_C(45235), UINT16_C(15289),
        UINT16_C(64206), UINT16_C(31054), UINT16_C(44565), UINT16_C(34071), UINT16_C(53266), UINT16_C(18032), UINT16_C(11338), UINT16_C(26017) },
      UINT32_C(4243640079) },
    { { UINT16_C(41958), UINT16_C(54513), UINT16_C(44922), UINT16_C(28813), UINT16_C( 6529), UINT16_C(20231), UINT16_C(21779), UINT16_C(38089),
        UINT16_C(65503), UINT16_C( 5482), UINT16_C(57657), UINT16_C( 6180), UINT16_C( 4445), UINT16_C(43478), UINT16_C( 2341), UINT16_C( 2997),
        UINT16_C(42669), UINT16_C(10208), UINT16_C(27989), UINT16_C(54935), UINT16_C(40582), UINT16_C(39462), UINT16_C(61428), UINT16_C(54062),
        UINT16_C(39150), UINT16_C(10473), UINT16_C( 3449), UINT16_C(54848), UINT16_C( 5662), UINT16_C(17280), UINT16_C(13600), UINT16_C(52559) },
      { UINT16_C(41958), UINT16_C(54513), UINT16_C(44922), UINT16_C(28813), UINT16_C(11817), UINT16_C( 7613), UINT16_C(21779), UINT16_C(38089),
        UINT16_C(55939), UINT16_C(64819), UINT16_C(29927), UINT16_C( 1491), UINT16_C( 4445), UINT16_C(43478), UINT16_C(39049), UINT16_C(25975),
        UINT16_C(42669), UINT16_C(10208), UINT16_C(40694), UINT16_C( 8326), UINT16_C(40582), UINT16_C(39462), UINT16_C(11822), UINT16_C(45813),
        UINT16_C(10248), UINT16_C(61359), UINT16_C( 3449), UINT16_C(54848), UINT16_C(16086), UINT16_C(24529), UINT16_C(13600), UINT16_C(52559) },
      UINT32_C(3425906895) },
    { { UINT16_C(34809), UINT16_C(50635), UINT16_C( 2250), UINT16_C(63919), UINT16_C(42039), UINT16_C(16299), UINT16_C(23244), UINT16_C(26927),
        UINT16_C( 9436), UINT16_C(45712), UINT16_C(24930), UINT16_C(14353), UINT16_C(54698), UINT16_C(24533), UINT16_C(54576), UINT16_C(10506),
        UINT16_C(54620), UINT16_C(10222), UINT16_C(40413), UINT16_C( 5152), UINT16_C(52033), UINT16_C( 3668), UINT16_C(33573), UINT16_C(  375),
        UINT16_C( 1959), UINT16_C( 2484), UINT16_C(50536), UINT16_C( 4929), UINT16_C( 5787), UINT16_C(52082), UINT16_C(31979), UINT16_C(18676) },
      { UINT16_C(34809), UINT16_C(50635), UINT16_C(36736), UINT16_C(49475), UINT16_C(38746), UINT16_C(32719), UINT16_C(23244), UINT16_C(26927),
        UINT16_C( 9436), UINT16_C(45712), UINT16_C(24930), UINT16_C(14353), UINT16_C(54698), UINT16_C(24533), UINT16_C(54576), UINT16_C(10506),
        UINT16_C(49974), UINT16_C(46646), UINT16_C(31058), UINT16_C(44152), UINT16_C(52033), UINT16_C( 3668), UINT16_C(44174), UINT16_C(56299),
        UINT16_C( 1959), UINT16_C( 2484), UINT16_C(50536), UINT16_C( 4929), UINT16_C( 5787), UINT16_C(52082), UINT16_C(16931), UINT16_C(23124) },
      UINT32_C(1060175811) },
    { { UINT16_C(34820), UINT16_C( 5381), UINT16_C(12496), UINT16_C(24127), UINT16_C(11228), UINT16_C(48441), UINT16_C(52192), UINT16_C(41367),
        UINT16_C( 1829), UINT16_C(48002), UINT16_C(28886), UINT16_C(64007), UINT16_C(23731), UINT16_C(47444), UINT16_C(25831), UINT16_C(60177),
        UINT16_C( 5869), UINT16_C(48384), UINT16_C(16455), UINT16_C( 8987), UINT16_C(21611), UINT16_C(19424), UINT16_C(30751), UINT16_C(17900),
        UINT16_C(28543), UINT16_C(21760), UINT16_C( 2015), UINT16_C(37455), UINT16_C(41827), UINT16_C(19019), UINT16_C(23816), UINT16_C(62774) },
      { UINT16_C(13939), UINT16_C(47794), UINT16_C(52598), UINT16_C(57822), UINT16_C(11228), UINT16_C(48441), UINT16_C( 6454), UINT16_C(46470),
        UINT16_C( 1829), UINT16_C(48002), UINT16_C(23181), UINT16_C(61946), UINT16_C(18174), UINT16_C( 1595), UINT16_C(25831), UINT16_C(60177),
        UINT16_C( 5869), UINT16_C(48384), UINT16_C(44922), UINT16_C(39680), UINT16_C(21611), UINT16_C(19424), UINT16_C(30751), UINT16_C(17900),
        UINT16_C(28543), UINT16_C(21760), UINT16_C( 2015), UINT16_C(37455), UINT16_C(41827), UINT16_C(19019), UINT16_C(23816), UINT16_C(62774) },
      UINT32_C(4294165296) },
 };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i a = simde_mm512_loadu_si512(test_vec[i].a);
    simde__m512i b = simde_mm512_loadu_si512(test_vec[i].b);
    simde__mmask32 r = simde_mm512_cmpeq_epu16_mask(a, b);
    simde_assert_equal_mmask32(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m512i a = simde_test_x86_random_u16x32();
    simde__m512i b = simde_mm512_mask_blend_epi32(simde_test_x86_random_mmask32(), a, simde_test_x86_random_u16x32());
    simde__mmask32 r = simde_mm512_cmpeq_epu16_mask(a, b);

    simde_test_x86_write_u16x32(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_u16x32(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_mask_cmpeq_epu16_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask32 k1;
    const uint16_t a[32];
    const uint16_t b[32];
    const simde__mmask32 r;
  } test_vec[] = {
    { UINT32_C(3813746624),
      { UINT16_C(32444), UINT16_C(23510), UINT16_C( 5513), UINT16_C( 8521), UINT16_C(14710), UINT16_C(36248), UINT16_C(37951), UINT16_C(20859),
        UINT16_C(20398), UINT16_C(47447), UINT16_C(55612), UINT16_C(12503), UINT16_C(45628), UINT16_C(64564), UINT16_C(34265), UINT16_C(38367),
        UINT16_C(46339), UINT16_C(36080), UINT16_C(15050), UINT16_C(16814), UINT16_C(18035), UINT16_C(46030), UINT16_C(18906), UINT16_C(35076),
        UINT16_C(23704), UINT16_C(54594), UINT16_C( 6453), UINT16_C(28933), UINT16_C(14796), UINT16_C(42350), UINT16_C(19903), UINT16_C(49723) },
      { UINT16_C(32444), UINT16_C(23510), UINT16_C(64869), UINT16_C(55566), UINT16_C(14710), UINT16_C(36248), UINT16_C(37951), UINT16_C(20859),
        UINT16_C(59884), UINT16_C( 8851), UINT16_C(38914), UINT16_C(52883), UINT16_C(  466), UINT16_C(37236), UINT16_C(34265), UINT16_C(38367),
        UINT16_C(41690), UINT16_C(16415), UINT16_C(15050), UINT16_C(16814), UINT16_C(18035), UINT16_C(46030), UINT16_C(43061), UINT16_C( 8942),
        UINT16_C(33169), UINT16_C(37700), UINT16_C( 6453), UINT16_C(28933), UINT16_C(14796), UINT16_C(42350), UINT16_C(53381), UINT16_C(24442) },
      UINT32_C( 537919680) },
    { UINT32_C(3539318983),
      { UINT16_C(63069), UINT16_C(37634), UINT16_C(61598), UINT16_C(12213), UINT16_C(63857), UINT16_C(35522), UINT16_C( 9424), UINT16_C(43382),
        UINT16_C(62202), UINT16_C(32721), UINT16_C(19394), UINT16_C(13791), UINT16_C(32485), UINT16_C(44103), UINT16_C(15415), UINT16_C(38014),
        UINT16_C(32818), UINT16_C(53287), UINT16_C(56432), UINT16_C(57855), UINT16_C(49621), UINT16_C(42604), UINT16_C(58086), UINT16_C(57423),
        UINT16_C( 8660), UINT16_C(38752), UINT16_C(16236), UINT16_C(20940), UINT16_C( 5053), UINT16_C(62718), UINT16_C(31823), UINT16_C(33161) },
      { UINT16_C(45309), UINT16_C(27985), UINT16_C(20621), UINT16_C(25167), UINT16_C(47889), UINT16_C(63240), UINT16_C(22685), UINT16_C(29144),
        UINT16_C(62202), UINT16_C(32721), UINT16_C(54391), UINT16_C(13367), UINT16_C(13799), UINT16_C(13865), UINT16_C(45745), UINT16_C(44727),
        UINT16_C( 2146), UINT16_C(61212), UINT16_C(56432), UINT16_C(57855), UINT16_C(49621), UINT16_C(42604), UINT16_C(14770), UINT16_C(11060),
        UINT16_C(15729), UINT16_C(59409), UINT16_C(18449), UINT16_C(63773), UINT16_C(18045), UINT16_C(11823), UINT16_C(59384), UINT16_C(23261) },
      UINT32_C(   3407872) },
    { UINT32_C(2326961252),
      { UINT16_C( 5110), UINT16_C(43341), UINT16_C(33101), UINT16_C(48852), UINT16_C(58814), UINT16_C(53415), UINT16_C(50221), UINT16_C(43721),
        UINT16_C(63498), UINT16_C(  729), UINT16_C(46815), UINT16_C(53084), UINT16_C(42671), UINT16_C( 4887), UINT16_C(51522), UINT16_C(14749),
        UINT16_C(60124), UINT16_C(10722), UINT16_C(46699), UINT16_C(10984), UINT16_C(36764), UINT16_C(51706), UINT16_C(50003), UINT16_C(23924),
        UINT16_C(19899), UINT16_C(39775), UINT16_C(47875), UINT16_C(45674), UINT16_C(33122), UINT16_C(42181), UINT16_C(25162), UINT16_C( 9949) },
      { UINT16_C( 5110), UINT16_C(43341), UINT16_C(33101), UINT16_C(48852), UINT16_C(58814), UINT16_C(53415), UINT16_C(50221), UINT16_C(43721),
        UINT16_C(63498), UINT16_C(  729), UINT16_C(46815), UINT16_C(53084), UINT16_C(42671), UINT16_C( 4887), UINT16_C(30072), UINT16_C(50256),
        UINT16_C(41013), UINT16_C(43900), UINT16_C(46699), UINT16_C(10984), UINT16_C(38969), UINT16_C(55225), UINT16_C(50003), UINT16_C(23924),
        UINT16_C(19899), UINT16_C(39775), UINT16_C(47875), UINT16_C(45674), UINT16_C( 9100), UINT16_C( 1167), UINT16_C(25162), UINT16_C( 9949) },
      UINT32_C(2323651684) },
    { UINT32_C(3690477218),
      { UINT16_C(45774), UINT16_C(46771), UINT16_C(58594), UINT16_C(59707), UINT16_C(24331), UINT16_C(36993), UINT16_C( 3284), UINT16_C(24822),
        UINT16_C(34096), UINT16_C(51557), UINT16_C(11877), UINT16_C(59031), UINT16_C( 4211), UINT16_C( 5439), UINT16_C(14150), UINT16_C( 5361),
        UINT16_C(42217), UINT16_C(52427), UINT16_C( 1672), UINT16_C(37813), UINT16_C(13925), UINT16_C(14628), UINT16_C( 6722), UINT16_C(29338),
        UINT16_C(65439), UINT16_C( 1339), UINT16_C(53805), UINT16_C(41195), UINT16_C(10978), UINT16_C(10421), UINT16_C(42593), UINT16_C(19261) },
      { UINT16_C(45774), UINT16_C(46771), UINT16_C(58594), UINT16_C(59707), UINT16_C(35330), UINT16_C(17580), UINT16_C(18084), UINT16_C(17591),
        UINT16_C(34096), UINT16_C(51557), UINT16_C(13509), UINT16_C(42770), UINT16_C( 4211), UINT16_C( 5439), UINT16_C(14150), UINT16_C( 5361),
        UINT16_C( 8469), UINT16_C( 9100), UINT16_C(62189), UINT16_C(61334), UINT16_C(17021), UINT16_C( 8500), UINT16_C(60297), UINT16_C(52837),
        UINT16_C(65439), UINT16_C( 1339), UINT16_C(53805), UINT16_C(41195), UINT16_C( 6683), UINT16_C(35328), UINT16_C( 2599), UINT16_C(15427) },
      UINT32_C( 184562178) },
    { UINT32_C(1040840129),
      { UINT16_C(15671), UINT16_C(49248), UINT16_C(50472), UINT16_C( 1423), UINT16_C(53364), UINT16_C(22184), UINT16_C(61987), UINT16_C(16279),
        UINT16_C(38668), UINT16_C(13257), UINT16_C( 3233), UINT16_C(52591), UINT16_C(52955), UINT16_C(40167), UINT16_C(61635), UINT16_C(64219),
        UINT16_C(15149), UINT16_C(21947), UINT16_C(18944), UINT16_C(29786), UINT16_C(  538), UINT16_C(15819), UINT16_C(25332), UINT16_C(  124),
        UINT16_C(17913), UINT16_C(39475), UINT16_C(41553), UINT16_C(11368), UINT16_C(20336), UINT16_C(13257), UINT16_C(42047), UINT16_C(27694) },
      { UINT16_C(59871), UINT16_C(57281), UINT16_C(50472), UINT16_C( 1423), UINT16_C(53364), UINT16_C(22184), UINT16_C( 1921), UINT16_C(31251),
        UINT16_C(17996), UINT16_C(40468), UINT16_C(31977), UINT16_C(22986), UINT16_C(37835), UINT16_C( 2701), UINT16_C(61635), UINT16_C(64219),
        UINT16_C(15149), UINT16_C(21947), UINT16_C(19027), UINT16_C(28964), UINT16_C(  538), UINT16_C(15819), UINT16_C(25332), UINT16_C(  124),
        UINT16_C(17913), UINT16_C(39475), UINT16_C(41553), UINT16_C(11368), UINT16_C(44286), UINT16_C(13771), UINT16_C(42047), UINT16_C(27694) },
      UINT32_C( 234995712) },
    { UINT32_C(4114417292),
      { UINT16_C(49333), UINT16_C(27359), UINT16_C(17239), UINT16_C(13420), UINT16_C( 3259), UINT16_C(45306), UINT16_C( 6519), UINT16_C(30065),
        UINT16_C(15558), UINT16_C(11690), UINT16_C(63101), UINT16_C(63033), UINT16_C( 6968), UINT16_C(50370), UINT16_C(65314), UINT16_C(55225),
        UINT16_C(39104), UINT16_C( 5953), UINT16_C(44763), UINT16_C(38731), UINT16_C(17850), UINT16_C(12615), UINT16_C(47198), UINT16_C( 9382),
        UINT16_C(20980), UINT16_C(29266), UINT16_C(35655), UINT16_C(32872), UINT16_C(11174), UINT16_C(51268), UINT16_C(65066), UINT16_C(60063) },
      { UINT16_C(49333), UINT16_C(27359), UINT16_C(19599), UINT16_C(18697), UINT16_C(20625), UINT16_C(61563), UINT16_C( 8457), UINT16_C(64788),
        UINT16_C(15558), UINT16_C(11690), UINT16_C(63101), UINT16_C(63033), UINT16_C( 6968), UINT16_C(50370), UINT16_C(  124), UINT16_C( 4888),
        UINT16_C( 6625), UINT16_C(28805), UINT16_C(36454), UINT16_C(63417), UINT16_C(13534), UINT16_C(59367), UINT16_C(64598), UINT16_C(51429),
        UINT16_C(20980), UINT16_C(29266), UINT16_C(35655), UINT16_C(32872), UINT16_C(19515), UINT16_C(46941), UINT16_C(65066), UINT16_C(60063) },
      UINT32_C(3305113088) },
    { UINT32_C(3169605597),
      { UINT16_C(54155), UINT16_C(57763), UINT16_C(35023), UINT16_C(12970), UINT16_C(11485), UINT16_C( 2438), UINT16_C(29417), UINT16_C( 9273),
        UINT16_C(38590), UINT16_C( 3035), UINT16_C(42507), UINT16_C(39224), UINT16_C(55029), UINT16_C(54158), UINT16_C(31277), UINT16_C(47247),
        UINT16_C(12877), UINT16_C( 7578), UINT16_C(17595), UINT16_C(38991), UINT16_C(54640), UINT16_C(22945), UINT16_C(55879), UINT16_C( 1405),
        UINT16_C(22896), UINT16_C(31504), UINT16_C(18943), UINT16_C(62485), UINT16_C(41759), UINT16_C(19655), UINT16_C(22045), UINT16_C(27140) },
      { UINT16_C(54155), UINT16_C(57763), UINT16_C(35023), UINT16_C(12970), UINT16_C(32171), UINT16_C(62124), UINT16_C(10840), UINT16_C(51448),
        UINT16_C( 2179), UINT16_C(33348), UINT16_C(42507), UINT16_C(39224), UINT16_C(55029), UINT16_C(54158), UINT16_C(31277), UINT16_C(47247),
        UINT16_C(12877), UINT16_C( 7578), UINT16_C(17595), UINT16_C(38991), UINT16_C(54640), UINT16_C(22945), UINT16_C(30571), UINT16_C(61147),
        UINT16_C( 8064), UINT16_C(53616), UINT16_C(59256), UINT16_C(29762), UINT16_C(41759), UINT16_C(19655), UINT16_C(22045), UINT16_C(27140) },
      UINT32_C(2955695117) },
    { UINT32_C( 831190646),
      { UINT16_C( 2615), UINT16_C(41796), UINT16_C( 8065), UINT16_C(  401), UINT16_C(  575), UINT16_C(47059), UINT16_C( 5609), UINT16_C( 3628),
        UINT16_C(47379), UINT16_C(54215), UINT16_C(40650), UINT16_C(59122), UINT16_C(21463), UINT16_C(19940), UINT16_C(28233), UINT16_C(32894),
        UINT16_C(49784), UINT16_C(64035), UINT16_C(46561), UINT16_C( 8443), UINT16_C(52919), UINT16_C(41176), UINT16_C( 1251), UINT16_C(63406),
        UINT16_C(30141), UINT16_C(35018), UINT16_C(48148), UINT16_C(60270), UINT16_C(21007), UINT16_C(22584), UINT16_C(46785), UINT16_C(14808) },
      { UINT16_C( 2615), UINT16_C(41796), UINT16_C( 8065), UINT16_C(  401), UINT16_C(  575), UINT16_C(47059), UINT16_C( 5609), UINT16_C( 3628),
        UINT16_C(47379), UINT16_C(54215), UINT16_C( 2654), UINT16_C(27946), UINT16_C(21463), UINT16_C(19940), UINT16_C(28233), UINT16_C(32894),
        UINT16_C(35481), UINT16_C(19178), UINT16_C(25785), UINT16_C(47026), UINT16_C(52919), UINT16_C(41176), UINT16_C(28784), UINT16_C(39967),
        UINT16_C(47890), UINT16_C(28891), UINT16_C( 1733), UINT16_C( 8669), UINT16_C(41576), UINT16_C(33087), UINT16_C(38463), UINT16_C(55569) },
      UINT32_C(     62070) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i a = simde_mm512_loadu_si512(test_vec[i].a);
    simde__m512i b = simde_mm512_loadu_si512(test_vec[i].b);
    simde__mmask32 r = simde_mm512_mask_cmpeq_epu16_mask(test_vec[i].k1, a, b);
    simde_assert_equal_mmask32(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask32 k1 = simde_test_x86_random_mmask32();
    simde__m512i a = simde_test_x86_random_u16x32();
    simde__m512i b = simde_mm512_mask_blend_epi32(simde_test_x86_random_mmask32(), a, simde_test_x86_random_u16x32());
    simde__mmask32 r = simde_mm512_mask_cmpeq_epu16_mask(k1, a, b);

    simde_test_x86_write_mmask32(2, k1, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_u16x32(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_u16x32(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_cmpeq_epu32_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const uint32_t a[4];
    const uint32_t b[4];
    const simde__mmask8 r;
  } test_vec[] = {
    { { UINT32_C(1262599426), UINT32_C(3987780654), UINT32_C( 521129179), UINT32_C( 177670614) },
      { UINT32_C(2200440411), UINT32_C(3987780654), UINT32_C(1535452248), UINT32_C( 177670614) },
      UINT8_C( 10) },
    { { UINT32_C( 167020116), UINT32_C(  48554294), UINT32_C(4208526320), UINT32_C(2840978330) },
      { UINT32_C( 509597963), UINT32_C(1651923261), UINT32_C(4208526320), UINT32_C( 967628260) },
      UINT8_C(  4) },
    { { UINT32_C(2173780640), UINT32_C( 695309350), UINT32_C(1355049837), UINT32_C(2589748673) },
      { UINT32_C(2173780640), UINT32_C( 695309350), UINT32_C(1355049837), UINT32_C(2589748673) },
      UINT8_C( 15) },
    { { UINT32_C( 709277590), UINT32_C(2492952617), UINT32_C(2706761780), UINT32_C(3194875716) },
      { UINT32_C( 709277590), UINT32_C(2178183063), UINT32_C(4078468628), UINT32_C(3194875716) },
      UINT8_C(  9) },
    { { UINT32_C(3392095322), UINT32_C(3288253403), UINT32_C( 134717209), UINT32_C(2681193740) },
      { UINT32_C(3795243123), UINT32_C( 586660004), UINT32_C( 134717209), UINT32_C(2681193740) },
      UINT8_C( 12) },
    { { UINT32_C( 400433491), UINT32_C(3190858271), UINT32_C(1875589289), UINT32_C(3638716936) },
      { UINT32_C( 400433491), UINT32_C(3190858271), UINT32_C(  61032260), UINT32_C(3204905836) },
      UINT8_C(  3) },
    { { UINT32_C(2268911333), UINT32_C(1060174342), UINT32_C( 810000325), UINT32_C(1204887426) },
      { UINT32_C(2268911333), UINT32_C(1060174342), UINT32_C(1191608908), UINT32_C(1852098185) },
      UINT8_C(  3) },
    { { UINT32_C(2594436512), UINT32_C(3311460901), UINT32_C(1212649513), UINT32_C(2346946145) },
      { UINT32_C( 987635345), UINT32_C( 528906397), UINT32_C(1212649513), UINT32_C(3537966642) },
      UINT8_C(  4) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i a = simde_x_mm_loadu_epu32(test_vec[i].a);
    simde__m128i b = simde_x_mm_loadu_epu32(test_vec[i].b);
    simde__mmask8 r = simde_mm_cmpeq_epu32_mask(a, b);
    simde_assert_equal_mmask8(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i a = simde_test_x86_random_u32x4();
    simde__m128i b = simde_x_mm_mask_blend_epu32(simde_test_x86_random_mmask8(), a, simde_test_x86_random_u32x4());
    simde__mmask8 r = simde_mm_cmpeq_epu32_mask(a, b);

    simde_test_x86_write_u32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_u32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_mask_cmpeq_epu32_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k1;
    const uint32_t a[4];
    const uint32_t b[4];
    const simde__mmask8 r;
  } test_vec[] = {
     { UINT8_C(132),
      { UINT32_C(3429249388), UINT32_C(1029476342), UINT32_C(3150691799), UINT32_C( 651779144) },
      { UINT32_C( 480212630), UINT32_C(1029476342), UINT32_C(3150691799), UINT32_C( 651779144) },
      UINT8_C(  4) },
    { UINT8_C( 47),
      { UINT32_C(2227144487), UINT32_C(2403440324), UINT32_C( 720079441), UINT32_C(1335919024) },
      { UINT32_C(2227144487), UINT32_C(2403440324), UINT32_C( 720079441), UINT32_C(1335919024) },
      UINT8_C( 15) },
    { UINT8_C(204),
      { UINT32_C(3680699545), UINT32_C(2120594579), UINT32_C(2147423711), UINT32_C(3535117669) },
      { UINT32_C(3382913317), UINT32_C(2120594579), UINT32_C(2147423711), UINT32_C(4184872032) },
      UINT8_C(  4) },
    { UINT8_C(211),
      { UINT32_C( 965192916), UINT32_C( 709846571), UINT32_C(2613556454), UINT32_C( 700836998) },
      { UINT32_C( 316782518), UINT32_C(2774366161), UINT32_C(2344271131), UINT32_C(2338247606) },
      UINT8_C(  0) },
    { UINT8_C(229),
      { UINT32_C( 323791556), UINT32_C(2630300373), UINT32_C(2458472141), UINT32_C(1497972599) },
      { UINT32_C(2932874065), UINT32_C(2053893056), UINT32_C(3561824886), UINT32_C(1497972599) },
      UINT8_C(  0) },
    { UINT8_C(  6),
      { UINT32_C(1278758021), UINT32_C(1922696681), UINT32_C(3786478232), UINT32_C(1006371435) },
      { UINT32_C(1278758021), UINT32_C(2235473207), UINT32_C( 743631730), UINT32_C(1006371435) },
      UINT8_C(  0) },
    { UINT8_C(106),
      { UINT32_C(3379560238), UINT32_C( 584779633), UINT32_C(3844359913), UINT32_C(2829243777) },
      { UINT32_C( 809949938), UINT32_C(2971449439), UINT32_C( 377125348), UINT32_C(2306904155) },
      UINT8_C(  0) },
    { UINT8_C(239),
      { UINT32_C( 771162194), UINT32_C(1198776354), UINT32_C(1746728389), UINT32_C(3812757149) },
      { UINT32_C(1536926015), UINT32_C(1198776354), UINT32_C( 358428565), UINT32_C( 184937656) },
      UINT8_C(  2) },
 };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i a = simde_x_mm_loadu_epu32(test_vec[i].a);
    simde__m128i b = simde_x_mm_loadu_epu32(test_vec[i].b);
    simde__mmask8 r = simde_mm_mask_cmpeq_epu32_mask(test_vec[i].k1, a, b);
    simde_assert_equal_mmask8(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k1 = simde_test_x86_random_mmask8();
    simde__m128i a = simde_test_x86_random_u32x4();
    simde__m128i b = simde_x_mm_mask_blend_epu32(simde_test_x86_random_mmask8(), a, simde_test_x86_random_u32x4());
    simde__mmask8 r = simde_mm_mask_cmpeq_epu32_mask(k1, a, b);

    simde_test_x86_write_mmask8(2, k1, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_u32x4(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_u32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_cmpeq_epu32_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const uint32_t a[8];
    const uint32_t b[8];
    const simde__mmask8 r;
  } test_vec[] = {
    { { UINT32_C(3691985148), UINT32_C(2711705260), UINT32_C(2168326515), UINT32_C(3972014667), UINT32_C(1027480509), UINT32_C( 517082095), UINT32_C(1423435880), UINT32_C(3913409261) },
      { UINT32_C(3691985148), UINT32_C(2711705260), UINT32_C(2168326515), UINT32_C(3972014667), UINT32_C(1027480509), UINT32_C( 517082095), UINT32_C(1789812093), UINT32_C(3913409261) },
      UINT8_C(191) },
    { { UINT32_C(2273241120), UINT32_C(2653810178), UINT32_C(1392244138), UINT32_C(1027109755), UINT32_C(1624386266), UINT32_C( 834490243), UINT32_C( 203553977), UINT32_C(1982095702) },
      { UINT32_C(2273241120), UINT32_C(2653810178), UINT32_C(1392244138), UINT32_C( 869910104), UINT32_C(1624386266), UINT32_C( 834490243), UINT32_C( 203553977), UINT32_C(1897522471) },
      UINT8_C(119) },
    { { UINT32_C(2806127293), UINT32_C(3817693781), UINT32_C(3618235902), UINT32_C(2894240024), UINT32_C(2986179852), UINT32_C(4084681266), UINT32_C( 131637230), UINT32_C(3441320208) },
      { UINT32_C(3497287803), UINT32_C(3249734083), UINT32_C(4288175335), UINT32_C(2894240024), UINT32_C(2986179852), UINT32_C(3787271155), UINT32_C(3672675786), UINT32_C(3441320208) },
      UINT8_C(152) },
    { { UINT32_C(4112329282), UINT32_C(2203190507), UINT32_C(2946385667), UINT32_C(4250351177), UINT32_C(3173534208), UINT32_C( 340980267), UINT32_C(1931168204), UINT32_C(4237198010) },
      { UINT32_C(2566040493), UINT32_C(2203190507), UINT32_C(3580017291), UINT32_C(4250351177), UINT32_C(3173534208), UINT32_C(3091464172), UINT32_C(  53173832), UINT32_C(4237198010) },
      UINT8_C(154) },
    { { UINT32_C(1110774822), UINT32_C( 704430535), UINT32_C(1759767702), UINT32_C(2304960476), UINT32_C(1518947862), UINT32_C( 834195718), UINT32_C(3572144596), UINT32_C(1321553703) },
      { UINT32_C( 730921828), UINT32_C(1381338556), UINT32_C(1759767702), UINT32_C(2304960476), UINT32_C(1518947862), UINT32_C( 245450810), UINT32_C(3572144596), UINT32_C(1062709467) },
      UINT8_C( 92) },
    { { UINT32_C(3212074858), UINT32_C(1811410609), UINT32_C( 596055620), UINT32_C(3683447116), UINT32_C(  35898977), UINT32_C(3079472596), UINT32_C(1700751374), UINT32_C( 306971303) },
      { UINT32_C(3212074858), UINT32_C(1811410609), UINT32_C( 596055620), UINT32_C(3683447116), UINT32_C(1029188200), UINT32_C(1039459631), UINT32_C(1700751374), UINT32_C(3053973333) },
      UINT8_C( 79) },
    { { UINT32_C(1168269256), UINT32_C(1749647698), UINT32_C(3020635821), UINT32_C(3974001556), UINT32_C(2765164208), UINT32_C(4009172811), UINT32_C( 484264981), UINT32_C(3405090050) },
      { UINT32_C(1168269256), UINT32_C(3332790297), UINT32_C( 712683926), UINT32_C(3974001556), UINT32_C(2765164208), UINT32_C(4009172811), UINT32_C(3224993214), UINT32_C(4136316426) },
      UINT8_C( 57) },
    { { UINT32_C(3673415476), UINT32_C( 529303973), UINT32_C(3396841908), UINT32_C(  11722374), UINT32_C( 812825232), UINT32_C( 263008470), UINT32_C(2067707888), UINT32_C(3776316589) },
      { UINT32_C(3673415476), UINT32_C( 529303973), UINT32_C(2131828472), UINT32_C(2357183484), UINT32_C( 812825232), UINT32_C( 308504865), UINT32_C(2067707888), UINT32_C(2293146533) },
      UINT8_C( 83) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i a = simde_x_mm256_loadu_epu32(test_vec[i].a);
    simde__m256i b = simde_x_mm256_loadu_epu32(test_vec[i].b);
    simde__mmask8 r = simde_mm256_cmpeq_epu32_mask(a, b);
    simde_assert_equal_mmask8(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m256i a = simde_test_x86_random_u16x16();
    simde__m256i b = simde_x_mm256_mask_blend_epu32(simde_test_x86_random_mmask16(), a, simde_test_x86_random_u16x16());
    simde__mmask8 r = simde_mm256_cmpeq_epu32_mask(a, b);

    simde_test_x86_write_u32x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_u32x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_mask_cmpeq_epu32_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k1;
    const uint32_t a[8];
    const uint32_t b[8];
    const simde__mmask8 r;
  } test_vec[] = {
    { UINT8_C( 48),
      { UINT32_C(2725443858), UINT32_C(1239406699), UINT32_C( 222440670), UINT32_C(1140637430), UINT32_C(1545646305), UINT32_C(1707819123), UINT32_C(2804051228), UINT32_C( 601342225) },
      { UINT32_C(2725443858), UINT32_C(1239406699), UINT32_C( 222440670), UINT32_C(1140637430), UINT32_C( 732703928), UINT32_C(1707819123), UINT32_C(4113609700), UINT32_C( 601342225) },
      UINT8_C( 32) },
    { UINT8_C(222),
      { UINT32_C(3263459668), UINT32_C(2087933552), UINT32_C( 696574494), UINT32_C(3730127922), UINT32_C(4183147112), UINT32_C(2074884427), UINT32_C(1182933294), UINT32_C(2737164879) },
      { UINT32_C(3009849667), UINT32_C( 489675263), UINT32_C( 696574494), UINT32_C(1472961775), UINT32_C(2840600670), UINT32_C(2074884427), UINT32_C(1182933294), UINT32_C(3138515576) },
      UINT8_C( 68) },
    { UINT8_C(119),
      { UINT32_C(2639305326), UINT32_C(4266658743), UINT32_C(3281666040), UINT32_C(3890477207), UINT32_C(3320069281), UINT32_C(2422932163), UINT32_C(2172904304), UINT32_C( 217587358) },
      { UINT32_C(1890142393), UINT32_C(1265563987), UINT32_C(3473803320), UINT32_C(2713186560), UINT32_C(3320069281), UINT32_C(2422932163), UINT32_C(1385104308), UINT32_C(3680405282) },
      UINT8_C( 48) },
    { UINT8_C(  7),
      { UINT32_C(3120570955), UINT32_C(2076326253), UINT32_C(3211576072), UINT32_C(3411777892), UINT32_C( 161282441), UINT32_C(2517455111), UINT32_C(  35467171), UINT32_C(1426713610) },
      { UINT32_C(2064583182), UINT32_C(1274466883), UINT32_C(3211576072), UINT32_C(2227463931), UINT32_C( 161282441), UINT32_C(1442618034), UINT32_C(3545700809), UINT32_C(1426713610) },
      UINT8_C(  4) },
    { UINT8_C( 56),
      { UINT32_C(2215292558), UINT32_C(  82223097), UINT32_C(1567285657), UINT32_C(4072589669), UINT32_C( 730689583), UINT32_C( 491017926), UINT32_C(1400785194), UINT32_C(3935037788) },
      { UINT32_C(2439943831), UINT32_C(3465892917), UINT32_C(2586574901), UINT32_C(4186827465), UINT32_C( 730689583), UINT32_C( 491017926), UINT32_C(1400785194), UINT32_C(3935037788) },
      UINT8_C( 48) },
    { UINT8_C(104),
      { UINT32_C(1690059983), UINT32_C(1063580179), UINT32_C( 422129292), UINT32_C(1261667367), UINT32_C(3837043877), UINT32_C( 748775230), UINT32_C(1873102710), UINT32_C(1423422597) },
      { UINT32_C(1690059983), UINT32_C( 306847110), UINT32_C( 422129292), UINT32_C(2663276536), UINT32_C(3837043877), UINT32_C(1332618201), UINT32_C(1873102710), UINT32_C(1423422597) },
      UINT8_C( 64) },
    { UINT8_C(253),
      { UINT32_C( 354136267), UINT32_C(4018759363), UINT32_C(2538504921), UINT32_C(2718519840), UINT32_C(  46523284), UINT32_C(4044697394), UINT32_C(1686690847), UINT32_C(1717678747) },
      { UINT32_C( 645692515), UINT32_C(3155494371), UINT32_C(2807260039), UINT32_C(1229544629), UINT32_C(1917521471), UINT32_C(4044697394), UINT32_C(1686690847), UINT32_C(  20849566) },
      UINT8_C( 96) },
    { UINT8_C(186),
      { UINT32_C(1019249191), UINT32_C(2443134782), UINT32_C( 955143663), UINT32_C(3930533278), UINT32_C(  55215519), UINT32_C(2767095778), UINT32_C(2647100511), UINT32_C(3025692301) },
      { UINT32_C( 670046441), UINT32_C(1320783967), UINT32_C( 955143663), UINT32_C(1953353428), UINT32_C(  55215519), UINT32_C(2665047359), UINT32_C(2647100511), UINT32_C(4029977351) },
      UINT8_C( 16) },  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i a = simde_x_mm256_loadu_epu32(test_vec[i].a);
    simde__m256i b = simde_x_mm256_loadu_epu32(test_vec[i].b);
    simde__mmask8 r = simde_mm256_mask_cmpeq_epu32_mask(test_vec[i].k1, a, b);
    simde_assert_equal_mmask8(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k1 = simde_test_x86_random_mmask8();
    simde__m256i a = simde_test_x86_random_u32x8();
    simde__m256i b = simde_x_mm256_mask_blend_epu32(simde_test_x86_random_mmask8(), a, simde_test_x86_random_u32x8());
    simde__mmask8 r = simde_mm256_mask_cmpeq_epu32_mask(k1, a, b);

    simde_test_x86_write_mmask8(2, k1, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_u32x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_u32x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_cmpeq_epu32_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const uint32_t a[16];
    const uint32_t b[16];
    const simde__mmask16 r;
  } test_vec[] = {
    { { UINT32_C( 411729306), UINT32_C(3161755597), UINT32_C(2089131208), UINT32_C(3197063926), UINT32_C(2665606288), UINT32_C(3719497313), UINT32_C(2794511499), UINT32_C(  36718183),
        UINT32_C(2417670851), UINT32_C( 307007305), UINT32_C( 563008043), UINT32_C(3051298084), UINT32_C(1783873801), UINT32_C(1380386759), UINT32_C(1274664931), UINT32_C(3779930397) },
      { UINT32_C( 745629667), UINT32_C(3161755597), UINT32_C(3024342160), UINT32_C(4066976489), UINT32_C(2665606288), UINT32_C(3719497313), UINT32_C(2794511499), UINT32_C(  41500447),
        UINT32_C(2637097895), UINT32_C( 307007305), UINT32_C( 602735161), UINT32_C(3051298084), UINT32_C(3635573268), UINT32_C(2424286997), UINT32_C(3291050661), UINT32_C(1489412785) },
      UINT16_C( 2674) },
    { { UINT32_C(3043112694), UINT32_C(1572313967), UINT32_C(3568622526), UINT32_C(2521221347), UINT32_C( 524639136), UINT32_C( 361884652), UINT32_C(1991721903), UINT32_C(2439726491),
        UINT32_C(3947285883), UINT32_C( 659094888), UINT32_C(3170630873), UINT32_C(1683112388), UINT32_C(2290325660), UINT32_C( 849155459), UINT32_C(4087895384), UINT32_C( 361042842) },
      { UINT32_C(3043112694), UINT32_C(2725267657), UINT32_C(3568622526), UINT32_C(1215082924), UINT32_C(3436310601), UINT32_C(1576955397), UINT32_C(1565566915), UINT32_C(2608059834),
        UINT32_C(1793356705), UINT32_C(    808124), UINT32_C(1795779263), UINT32_C(1689482523), UINT32_C(2290325660), UINT32_C( 849155459), UINT32_C(4087895384), UINT32_C( 361042842) },
      UINT16_C(61445) },
    { { UINT32_C(  73643768), UINT32_C(3228508855), UINT32_C(1094027917), UINT32_C( 533044207), UINT32_C(3444488197), UINT32_C(2212832367), UINT32_C(3758805685), UINT32_C(1508901985),
        UINT32_C(1918784443), UINT32_C(  53661046), UINT32_C(1178888023), UINT32_C( 140904962), UINT32_C( 836089026), UINT32_C(2394208985), UINT32_C(3983457932), UINT32_C(2118606531) },
      { UINT32_C(  73643768), UINT32_C(3228508855), UINT32_C(2349887625), UINT32_C( 533044207), UINT32_C(  57567530), UINT32_C(2212832367), UINT32_C(2761752801), UINT32_C( 270722142),
        UINT32_C(4214755977), UINT32_C(  53661046), UINT32_C(1178888023), UINT32_C( 140904962), UINT32_C(1769535558), UINT32_C(4229499419), UINT32_C(3983457932), UINT32_C( 595182234) },
      UINT16_C(20011) },
    { { UINT32_C(3793029150), UINT32_C( 263711173), UINT32_C(3270246711), UINT32_C(4021957494), UINT32_C(3053049244), UINT32_C(1902838737), UINT32_C(3828548971), UINT32_C(1184237352),
        UINT32_C(3576277775), UINT32_C(3437551765), UINT32_C(1485754593), UINT32_C(2689026307), UINT32_C(4032118814), UINT32_C(2925642051), UINT32_C(4019426758), UINT32_C(2889165212) },
      { UINT32_C(3793029150), UINT32_C( 263711173), UINT32_C(3270246711), UINT32_C(4021957494), UINT32_C(1109143295), UINT32_C(3069214191), UINT32_C(3828548971), UINT32_C(2170280620),
        UINT32_C(2011880505), UINT32_C(1989615681), UINT32_C(1485754593), UINT32_C(3441330382), UINT32_C(2786015927), UINT32_C(2925642051), UINT32_C(4019426758), UINT32_C( 363975900) },
      UINT16_C(25679) },
    { { UINT32_C( 616362380), UINT32_C( 389259624), UINT32_C(2996830867), UINT32_C(3756808143), UINT32_C(1524606205), UINT32_C(3898303087), UINT32_C(1136474002), UINT32_C(3655298380),
        UINT32_C(3355286367), UINT32_C(3487445052), UINT32_C(  42040882), UINT32_C(3554766549), UINT32_C(2167259154), UINT32_C(3043657762), UINT32_C( 217589696), UINT32_C(4091926420) },
      { UINT32_C( 616362380), UINT32_C(1165924627), UINT32_C(2996830867), UINT32_C(3756808143), UINT32_C( 184675816), UINT32_C( 901802869), UINT32_C(1136474002), UINT32_C(3655298380),
        UINT32_C(3355286367), UINT32_C(2237804398), UINT32_C(  42040882), UINT32_C(3554766549), UINT32_C(2167259154), UINT32_C(3043657762), UINT32_C( 217589696), UINT32_C(1053908276) },
      UINT16_C(32205) },
    { { UINT32_C(3182534747), UINT32_C(2556944165), UINT32_C(2546612859), UINT32_C(3149261557), UINT32_C(1229012607), UINT32_C(2622914393), UINT32_C( 536447566), UINT32_C( 597765064),
        UINT32_C(4041233099), UINT32_C(2911389745), UINT32_C(2000966530), UINT32_C(3157457213), UINT32_C(2433053495), UINT32_C(1076714482), UINT32_C(2908694245), UINT32_C( 483393617) },
      { UINT32_C(3182534747), UINT32_C(2066847225), UINT32_C(2546612859), UINT32_C(2799772783), UINT32_C(2302142103), UINT32_C( 667575362), UINT32_C( 536447566), UINT32_C(2096604458),
        UINT32_C(1325401174), UINT32_C(2177511833), UINT32_C(2000966530), UINT32_C(2008844256), UINT32_C(2936140909), UINT32_C(1076714482), UINT32_C(2908694245), UINT32_C(2828777041) },
      UINT16_C(25669) },
    { { UINT32_C(3268236279), UINT32_C(2055107796), UINT32_C(1174495114), UINT32_C(3610930902), UINT32_C(4121072414), UINT32_C( 883005302), UINT32_C(1357574837), UINT32_C(2464982170),
        UINT32_C(3411327479), UINT32_C(3074806317), UINT32_C( 150816305), UINT32_C(3554621621), UINT32_C(1103659723), UINT32_C(3463801113), UINT32_C(4129251419), UINT32_C(4236774148) },
      { UINT32_C(4056407236), UINT32_C(2055107796), UINT32_C( 149464403), UINT32_C(3610930902), UINT32_C(1659478857), UINT32_C(1748066060), UINT32_C(3277738175), UINT32_C( 532670043),
        UINT32_C(1880131522), UINT32_C(3880827028), UINT32_C(1005598813), UINT32_C(3554621621), UINT32_C(2074922351), UINT32_C(3957579052), UINT32_C(4129251419), UINT32_C(3920064039) },
      UINT16_C(18442) },
    { { UINT32_C(2859436378), UINT32_C(1625541744), UINT32_C(3945587463), UINT32_C(3635977004), UINT32_C(4206224406), UINT32_C(2101076687), UINT32_C( 300639082), UINT32_C(2798182476),
        UINT32_C(3662755689), UINT32_C( 188363780), UINT32_C(1140221463), UINT32_C( 404532737), UINT32_C(1628623250), UINT32_C( 517950900), UINT32_C(4247833264), UINT32_C( 346290347) },
      { UINT32_C( 888075312), UINT32_C(1625541744), UINT32_C(3945587463), UINT32_C(3635977004), UINT32_C( 618183536), UINT32_C(2101076687), UINT32_C( 766931842), UINT32_C(2798182476),
        UINT32_C(1993289806), UINT32_C( 188363780), UINT32_C(1140221463), UINT32_C(1218454232), UINT32_C(3865934301), UINT32_C(2996809776), UINT32_C(2397000995), UINT32_C(4230619566) },
      UINT16_C( 1710) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512i a = simde_x_mm512_loadu_epu32(test_vec[i].a);
    simde__m512i b = simde_x_mm512_loadu_epu32(test_vec[i].b);
    simde__mmask16 r = simde_mm512_cmpeq_epu32_mask(a, b);
    simde_assert_equal_mmask16(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m512i a = simde_test_x86_random_u32x16();
    simde__m512i b = simde_x_mm512_mask_blend_epu32(simde_test_x86_random_mmask16(), a, simde_test_x86_random_u32x16());
    simde__mmask16 r = simde_mm512_cmpeq_epu32_mask(a, b);

    simde_test_x86_write_u32x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_u32x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_mask_cmpeq_epu32_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask16 k1;
    const uint32_t a[16];
    const uint32_t b[16];
    const simde__mmask16 r;
  } test_vec[] = {
    { UINT16_C(43635),
      { UINT32_C(1301424392), UINT32_C( 980880482), UINT32_C( 209852206), UINT32_C(3253923728), UINT32_C(3262353823), UINT32_C(2488357862), UINT32_C(3314645876), UINT32_C(2104427636),
        UINT32_C(2412380461), UINT32_C(1019822349), UINT32_C(3913829209), UINT32_C(3668589115), UINT32_C(2979864267), UINT32_C(3846565489), UINT32_C(3718960745), UINT32_C( 123345370) },
      { UINT32_C(1301424392), UINT32_C(3211026278), UINT32_C( 209852206), UINT32_C(2982171622), UINT32_C(3262353823), UINT32_C(3032983371), UINT32_C(3314645876), UINT32_C(2774592650),
        UINT32_C(2026763793), UINT32_C(1019822349), UINT32_C(3286753501), UINT32_C(2775885620), UINT32_C(1351144965), UINT32_C(4211429245), UINT32_C(3718960745), UINT32_C(2515580035) },
      UINT16_C(  593) },
    { UINT16_C(   13),
      { UINT32_C(3405858030), UINT32_C(1502537765), UINT32_C(2516451984), UINT32_C(1457882840), UINT32_C(2538728150), UINT32_C(  98739585), UINT32_C(  77255513), UINT32_C(2131011472),
        UINT32_C( 273286891), UINT32_C(2120866286), UINT32_C(3021170907), UINT32_C(3289053678), UINT32_C(1700486115), UINT32_C(1516912129), UINT32_C(2707293201), UINT32_C(2518705067) },
      { UINT32_C(1470589801), UINT32_C( 534122564), UINT32_C(1741941112), UINT32_C(1457882840), UINT32_C( 975931193), UINT32_C(3600061893), UINT32_C(1148711833), UINT32_C(2131011472),
        UINT32_C(1192657155), UINT32_C(2120866286), UINT32_C(3094428374), UINT32_C(1350475031), UINT32_C(3918178596), UINT32_C(3619626814), UINT32_C(2707293201), UINT32_C(2518705067) },
      UINT16_C(    8) },
    { UINT16_C( 2328),
      { UINT32_C(   1343274), UINT32_C(3501753785), UINT32_C(1176581922), UINT32_C( 523217888), UINT32_C(3707170506), UINT32_C(4081324581), UINT32_C(2143644424), UINT32_C(3549027753),
        UINT32_C( 366189916), UINT32_C(1172736802), UINT32_C(2743797698), UINT32_C(2109914034), UINT32_C(3461986473), UINT32_C(3535969994), UINT32_C(2991752969), UINT32_C(3246775140) },
      { UINT32_C(   1343274), UINT32_C(3501753785), UINT32_C(1176581922), UINT32_C( 523217888), UINT32_C(3707170506), UINT32_C(4081324581), UINT32_C(2143644424), UINT32_C(3549027753),
        UINT32_C(1755374468), UINT32_C(1661960351), UINT32_C( 299456747), UINT32_C( 685821028), UINT32_C(  62291480), UINT32_C(3321305054), UINT32_C(1477549514), UINT32_C(1314790857) },
      UINT16_C(   24) },
    { UINT16_C(41142),
      { UINT32_C(1778632063), UINT32_C(2189155358), UINT32_C(3232390056), UINT32_C(3099812058), UINT32_C(1115601528), UINT32_C( 563842904), UINT32_C(2909796780), UINT32_C(2001544952),
        UINT32_C( 165761259), UINT32_C(3565902892), UINT32_C(2459186616), UINT32_C( 239753366), UINT32_C(1783678994), UINT32_C(  76344151), UINT32_C(3719429093), UINT32_C( 223739425) },
      { UINT32_C(1778632063), UINT32_C(1263444627), UINT32_C(1843258071), UINT32_C(3099812058), UINT32_C(1115601528), UINT32_C( 563842904), UINT32_C(2909796780), UINT32_C(2001544952),
        UINT32_C(2562884613), UINT32_C(3565902892), UINT32_C( 762036467), UINT32_C(3631933160), UINT32_C(1783678994), UINT32_C(3020319605), UINT32_C(1645576295), UINT32_C( 223739425) },
      UINT16_C(32944) },
    { UINT16_C(11501),
      { UINT32_C(1881854333), UINT32_C(2040436113), UINT32_C( 777066619), UINT32_C(3231215946), UINT32_C(1131716316), UINT32_C(1856342303), UINT32_C( 314789900), UINT32_C( 977252797),
        UINT32_C( 330000770), UINT32_C(2039302654), UINT32_C(2896682593), UINT32_C( 728514383), UINT32_C(4251967710), UINT32_C(1986729066), UINT32_C( 562573156), UINT32_C(1650247648) },
      { UINT32_C( 779421488), UINT32_C(2980577872), UINT32_C( 811421665), UINT32_C(3231215946), UINT32_C( 342543274), UINT32_C(1856342303), UINT32_C(3831828996), UINT32_C( 977252797),
        UINT32_C( 406437064), UINT32_C(2039302654), UINT32_C(2896682593), UINT32_C(2603363569), UINT32_C(4251967710), UINT32_C(1880766828), UINT32_C( 626360395), UINT32_C(1650247648) },
      UINT16_C( 1192) },
    { UINT16_C( 5666),
      { UINT32_C(2058742858), UINT32_C(  87721236), UINT32_C(2829084337), UINT32_C(1769951229), UINT32_C(3554253192), UINT32_C(1543056921), UINT32_C( 560277962), UINT32_C(3694626706),
        UINT32_C(2287398260), UINT32_C( 613257330), UINT32_C(4107021815), UINT32_C(  73223036), UINT32_C(4275517157), UINT32_C( 794415205), UINT32_C(2337324793), UINT32_C(3127347270) },
      { UINT32_C(3879911029), UINT32_C(  87721236), UINT32_C(2829084337), UINT32_C(1769951229), UINT32_C( 839341005), UINT32_C(1543056921), UINT32_C( 560277962), UINT32_C(3694626706),
        UINT32_C(2287398260), UINT32_C( 744661296), UINT32_C(4107021815), UINT32_C(  73223036), UINT32_C(4275517157), UINT32_C( 794415205), UINT32_C(2106678852), UINT32_C(1026338926) },
      UINT16_C( 5154) },
    { UINT16_C(16730),
      { UINT32_C(3714956387), UINT32_C(2340032856), UINT32_C(2760515377), UINT32_C(3644636364), UINT32_C(2449862990), UINT32_C(3171980879), UINT32_C(1476017222), UINT32_C(1637373182),
        UINT32_C(1765672209), UINT32_C(1207220246), UINT32_C(2766897112), UINT32_C(2306680635), UINT32_C(1729921560), UINT32_C(1579494424), UINT32_C(1723146088), UINT32_C(2244431220) },
      { UINT32_C(1760429650), UINT32_C(2340032856), UINT32_C(2760515377), UINT32_C(3659970498), UINT32_C(2449862990), UINT32_C(3601819502), UINT32_C(4198261894), UINT32_C(1637373182),
        UINT32_C(1765672209), UINT32_C(1207220246), UINT32_C(2766897112), UINT32_C(2306680635), UINT32_C( 668767161), UINT32_C(1579494424), UINT32_C(1723146088), UINT32_C(2244431220) },
      UINT16_C(16658) },
    { UINT16_C(47633),
      { UINT32_C(3765268523), UINT32_C(1515699465), UINT32_C(3974473779), UINT32_C( 907329852), UINT32_C(1018630732), UINT32_C(2346595148), UINT32_C(2547221294), UINT32_C(3193037971),
        UINT32_C(1587461716), UINT32_C(2931357051), UINT32_C(3667631518), UINT32_C(2869997406), UINT32_C( 233294017), UINT32_C( 697878011), UINT32_C(3703598152), UINT32_C(2778337616) },
      { UINT32_C(3765268523), UINT32_C(3438852910), UINT32_C(3081147225), UINT32_C(  56801090), UINT32_C(1018630732), UINT32_C(1487120655), UINT32_C(2547221294), UINT32_C(1124847220),
        UINT32_C( 915213831), UINT32_C( 570590665), UINT32_C(3667631518), UINT32_C(2869997406), UINT32_C( 233294017), UINT32_C( 804191257), UINT32_C(3703598152), UINT32_C(4162232560) },
      UINT16_C( 6161) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512i a = simde_x_mm512_loadu_epu32(test_vec[i].a);
    simde__m512i b = simde_x_mm512_loadu_epu32(test_vec[i].b);
    simde__mmask16 r = simde_mm512_mask_cmpeq_epu32_mask(test_vec[i].k1, a, b);
    simde_assert_equal_mmask16(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask16 k1 = simde_test_x86_random_mmask16();
    simde__m512i a = simde_test_x86_random_u32x16();
    simde__m512i b = simde_x_mm512_mask_blend_epu32(simde_test_x86_random_mmask16(), a, simde_test_x86_random_u32x16());
    simde__mmask16 r = simde_mm512_mask_cmpeq_epu32_mask(k1, a, b);

    simde_test_x86_write_mmask16(2, k1, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_u32x16(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_u32x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_cmpeq_epu64_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const uint64_t a[2];
    const uint64_t b[2];
    const simde__mmask8 r;
  } test_vec[] = {
    { { UINT64_C( 8419833108834580270), UINT64_C( 8172968004228757917) },
      { UINT64_C( 5322635411232490957), UINT64_C(17534932024583376287) },
      UINT8_C(  0) },
    { { UINT64_C( 3989940770603345025), UINT64_C( 5607476071567940557) },
      { UINT64_C( 3989940770603345025), UINT64_C( 5607476071567940557) },
      UINT8_C(  3) },
    { { UINT64_C(12064659941434190980), UINT64_C(15098242178015458200) },
      { UINT64_C( 7871290618242826941), UINT64_C( 7454090579020154990) },
      UINT8_C(  0) },
    { { UINT64_C(16889656902914803843), UINT64_C(14340867782171606412) },
      { UINT64_C( 5843791368348240954), UINT64_C(14340867782171606412) },
      UINT8_C(  2) },
    { { UINT64_C( 6552744730883275079), UINT64_C( 5291277921462138932) },
      { UINT64_C( 6552744730883275079), UINT64_C(13716277228769420824) },
      UINT8_C(  1) },
    { { UINT64_C( 5453913108514284150), UINT64_C( 7817915054665753807) },
      { UINT64_C( 5453913108514284150), UINT64_C( 7817915054665753807) },
      UINT8_C(  3) },
    { { UINT64_C(17649736751296241647), UINT64_C(13560535994134373885) },
      { UINT64_C(16751587232679622226), UINT64_C(13560535994134373885) },
      UINT8_C(  2) },
    { { UINT64_C(10771094565280120839), UINT64_C(17287618547215255780) },
      { UINT64_C( 6138879075173041611), UINT64_C(17287618547215255780) },
      UINT8_C(  2) },
 };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i a = simde_x_mm_loadu_epu64(test_vec[i].a);
    simde__m128i b = simde_x_mm_loadu_epu64(test_vec[i].b);
    simde__mmask8 r = simde_mm_cmpeq_epu64_mask(a, b);
    simde_assert_equal_mmask8(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i a = simde_test_x86_random_u64x2();
    simde__m128i b = simde_x_mm_mask_blend_epu64(simde_test_x86_random_mmask8(), a, simde_test_x86_random_u64x2());
    simde__mmask8 r = simde_mm_cmpeq_epu64_mask(a, b);

    simde_test_x86_write_u64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_u64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_mask_cmpeq_epu64_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k1;
    const uint64_t a[2];
    const uint64_t b[2];
    const simde__mmask8 r;
  } test_vec[] = {
    { UINT8_C(126),
      { UINT64_C(16291772385631933781), UINT64_C( 4973842610806821272) },
      { UINT64_C(16291772385631933781), UINT64_C( 2992054624321862705) },
      UINT8_C(  0) },
    { UINT8_C(161),
      { UINT64_C( 7107307530914801913), UINT64_C( 6468870455028949691) },
      { UINT64_C( 9541298299761205313), UINT64_C( 6468870455028949691) },
      UINT8_C(  0) },
    { UINT8_C( 80),
      { UINT64_C(  591736276265902193), UINT64_C( 5039058456365210887) },
      { UINT64_C(  591736276265902193), UINT64_C(11697996888581984345) },
      UINT8_C(  0) },
    { UINT8_C(225),
      { UINT64_C( 6956142011659732406), UINT64_C(10023173042403049724) },
      { UINT64_C( 6956142011659732406), UINT64_C(10023173042403049724) },
      UINT8_C(  1) },
    { UINT8_C(150),
      { UINT64_C(  457889769909973328), UINT64_C( 9480109839187976363) },
      { UINT64_C(  457889769909973328), UINT64_C( 8035011210555734907) },
      UINT8_C(  0) },
    { UINT8_C( 70),
      { UINT64_C(15979530560263904072), UINT64_C(11998471151333043830) },
      { UINT64_C(  282335409798806051), UINT64_C(11998471151333043830) },
      UINT8_C(  2) },
    { UINT8_C(201),
      { UINT64_C(13444636595189441124), UINT64_C(13759903328028624631) },
      { UINT64_C(11683681612583437103), UINT64_C(14036673707234532673) },
      UINT8_C(  0) },
    { UINT8_C( 71),
      { UINT64_C( 9296326443639827433), UINT64_C(13412194604682325929) },
      { UINT64_C( 9296326443639827433), UINT64_C(13412194604682325929) },
      UINT8_C(  3) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i a = simde_x_mm_loadu_epu64(test_vec[i].a);
    simde__m128i b = simde_x_mm_loadu_epu64(test_vec[i].b);
    simde__mmask8 r = simde_mm_mask_cmpeq_epu64_mask(test_vec[i].k1, a, b);
    simde_assert_equal_mmask8(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k1 = simde_test_x86_random_mmask8();
    simde__m128i a = simde_test_x86_random_u64x2();
    simde__m128i b = simde_x_mm_mask_blend_epu64(simde_test_x86_random_mmask8(), a, simde_test_x86_random_u64x2());
    simde__mmask8 r = simde_mm_mask_cmpeq_epu64_mask(k1, a, b);

    simde_test_x86_write_mmask8(2, k1, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_u64x2(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_u64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_cmpeq_epu64_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const uint64_t a[4];
    const uint64_t b[4];
    const simde__mmask8 r;
  } test_vec[] = {
    { { UINT64_C( 5038286725686039058), UINT64_C( 5949516425498691863), UINT64_C(17435032882633277038), UINT64_C( 8357890778527008520) },
      { UINT64_C( 5038286725686039058), UINT64_C( 5949516425498691863), UINT64_C( 8687534324861158038), UINT64_C( 8357890778527008520) },
      UINT8_C( 11) },
    { { UINT64_C(  534286233313066747), UINT64_C(12890628510202145277), UINT64_C(15065629050569774165), UINT64_C( 1164154204614521368) },
      { UINT64_C(  534286233313066747), UINT64_C(12890628510202145277), UINT64_C( 4488205530295978155), UINT64_C( 1164154204614521368) },
      UINT8_C( 11) },
    { { UINT64_C( 7586279453029017552), UINT64_C(15852508646605867378), UINT64_C( 7443020145375192548), UINT64_C(14570806133637926849) },
      { UINT64_C( 3165202298775722125), UINT64_C(15852508646605867378), UINT64_C(12236692403128105991), UINT64_C(15459315222708184005) },
      UINT8_C(  2) },
    { { UINT64_C( 2591459027101619802), UINT64_C( 4141916439168946348), UINT64_C( 6605501974071698294), UINT64_C( 2670703623849178165) },
      { UINT64_C( 2591459027101619802), UINT64_C( 4141916439168946348), UINT64_C( 1483426862582819374), UINT64_C( 2670703623849178165) },
      UINT8_C( 11) },
    { { UINT64_C(11246150499107764637), UINT64_C(11313488771278166747), UINT64_C(14546050606793941200), UINT64_C( 3997790859330163171) },
      { UINT64_C(11246150499107764637), UINT64_C(11313488771278166747), UINT64_C(14546050606793941200), UINT64_C(17858820348431792901) },
      UINT8_C(  7) },
    { { UINT64_C( 3092421516453962942), UINT64_C( 1312914169864473101), UINT64_C(14246446903096387437), UINT64_C(16674212758606787115) },
      { UINT64_C(17455656271432149272), UINT64_C( 7911246749194098493), UINT64_C(  453840859912687757), UINT64_C(16674212758606787115) },
      UINT8_C(  8) },
    { { UINT64_C(15856848482349005880), UINT64_C( 2569812091565313679), UINT64_C(10734628279198713173), UINT64_C( 6994048613391402183) },
      { UINT64_C( 1234521215773223574), UINT64_C( 9697116625230783221), UINT64_C(10734628279198713173), UINT64_C( 3147841958447266597) },
      UINT8_C(  4) },
    { { UINT64_C(  645249075510086768), UINT64_C(15238692036918650323), UINT64_C(15586143050692599001), UINT64_C( 9123804718114136680) },
      { UINT64_C(  645249075510086768), UINT64_C( 2352885922718519848), UINT64_C( 2169890278787423422), UINT64_C( 7669018398578529761) },
      UINT8_C(  1) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i a = simde_x_mm256_loadu_epu64(test_vec[i].a);
    simde__m256i b = simde_x_mm256_loadu_epu64(test_vec[i].b);
    simde__mmask8 r = simde_mm256_cmpeq_epu64_mask(a, b);
    simde_assert_equal_mmask8(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m256i a = simde_test_x86_random_u64x4();
    simde__m256i b = simde_x_mm256_mask_blend_epu64(simde_test_x86_random_mmask16(), a, simde_test_x86_random_u64x4());
    simde__mmask8 r = simde_mm256_cmpeq_epu64_mask(a, b);

    simde_test_x86_write_u64x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_u64x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_mask_cmpeq_epu64_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k1;
    const uint64_t a[4];
    const uint64_t b[4];
    const simde__mmask8 r;
  } test_vec[] = {
    { UINT8_C(216),
      { UINT64_C( 8950306848998588492), UINT64_C( 6483705806878692903), UINT64_C(14612434609929320822), UINT64_C(14386383399708761188) },
      { UINT64_C( 8950306848998588492), UINT64_C( 6483705806878692903), UINT64_C(17499597879927817014), UINT64_C(18009164585675854507) },
      UINT8_C(  0) },
    { UINT8_C( 65),
      { UINT64_C( 8046431890502791381), UINT64_C(16190689811142338463), UINT64_C(17429664141826539252), UINT64_C( 8642325915966744769) },
      { UINT64_C(  396404062714968805), UINT64_C(  265890566828600374), UINT64_C(17429664141826539252), UINT64_C( 8642325915966744769) },
      UINT8_C(  0) },
    { UINT8_C( 26),
      { UINT64_C(12732978786659318023), UINT64_C(11006571840843989872), UINT64_C(11502098844205578818), UINT64_C(12409259364525322151) },
      { UINT64_C(12732978786659318023), UINT64_C( 8721659617363362986), UINT64_C(11502098844205578818), UINT64_C( 2764641593532306956) },
      UINT8_C(  0) },
    { UINT8_C(145),
      { UINT64_C( 6547991462514580008), UINT64_C( 5544621151896540819), UINT64_C( 6658209867639681778), UINT64_C(10833110307939174247) },
      { UINT64_C( 6547991462514580008), UINT64_C(18249170681648486502), UINT64_C( 6658209867639681778), UINT64_C(10833110307939174247) },
      UINT8_C(  1) },
    { UINT8_C( 47),
      { UINT64_C( 9991489112244216929), UINT64_C(13621599624276915163), UINT64_C( 9336501558095948355), UINT64_C( 4827745416905085714) },
      { UINT64_C( 9991489112244216929), UINT64_C(17733600498493034157), UINT64_C( 5136010355011832337), UINT64_C( 4827745416905085714) },
      UINT8_C(  9) },
    { UINT8_C( 14),
      { UINT64_C(11052595701938191333), UINT64_C( 4644919904871388434), UINT64_C(  651227479054658263), UINT64_C( 8278661260319427865) },
      { UINT64_C(12864015156774431665), UINT64_C( 4644919904871388434), UINT64_C( 5258399172575203327), UINT64_C( 9233507127557757220) },
      UINT8_C(  2) },
    { UINT8_C(235),
      { UINT64_C( 2195877831741050221), UINT64_C( 1059879186337043100), UINT64_C( 5437473321784829026), UINT64_C( 3641505294632895866) },
      { UINT64_C(10170711191041973959), UINT64_C( 7872689116141557937), UINT64_C( 3009880849367295565), UINT64_C( 1331747498620359299) },
      UINT8_C(  0) },
    { UINT8_C(161),
      { UINT64_C( 2438683179054325785), UINT64_C( 1750449240687698467), UINT64_C(16945596392201976146), UINT64_C(11619054528921105699) },
      { UINT64_C( 2438683179054325785), UINT64_C( 5837021354174981786), UINT64_C(16945596392201976146), UINT64_C(11619054528921105699) },
      UINT8_C(  1) },
 };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i a = simde_x_mm256_loadu_epu64(test_vec[i].a);
    simde__m256i b = simde_x_mm256_loadu_epu64(test_vec[i].b);
    simde__mmask8 r = simde_mm256_mask_cmpeq_epu64_mask(test_vec[i].k1, a, b);
    simde_assert_equal_mmask8(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k1 = simde_test_x86_random_mmask8();
    simde__m256i a = simde_test_x86_random_u64x4();
    simde__m256i b = simde_x_mm256_mask_blend_epu64(simde_test_x86_random_mmask8(), a, simde_test_x86_random_u64x4());
    simde__mmask8 r = simde_mm256_mask_cmpeq_epu64_mask(k1, a, b);

    simde_test_x86_write_mmask8(2, k1, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_u64x4(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_u64x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_cmpeq_epu64_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const uint64_t a[8];
    const uint64_t b[8];
    const simde__mmask8 r;
  } test_vec[] = {
    { { UINT64_C(18186862228859402770), UINT64_C(11974592361192443311), UINT64_C( 6868038739186650805), UINT64_C( 2667206384739868959),
        UINT64_C(10078586323778676236), UINT64_C(15750966025723435426), UINT64_C(13362870149928087098), UINT64_C( 7101066476715148372) },
      { UINT64_C( 8330572791556635700), UINT64_C(18445893898395130364), UINT64_C(16626028212003151720), UINT64_C( 2667206384739868959),
        UINT64_C( 2709676214659319382), UINT64_C(15750966025723435426), UINT64_C( 3592496089999189091), UINT64_C( 7101066476715148372) },
      UINT8_C(168) },
    { { UINT64_C( 1609656541147856597), UINT64_C( 2347621685933238765), UINT64_C(10145900109398378958), UINT64_C( 1491787961871532554),
        UINT64_C(14380825775083172708), UINT64_C(15815108129948475613), UINT64_C( 5118221393808769814), UINT64_C(16098773806195315990) },
      { UINT64_C( 1609656541147856597), UINT64_C( 2347621685933238765), UINT64_C(10145900109398378958), UINT64_C( 1491787961871532554),
        UINT64_C(14380825775083172708), UINT64_C(15030517885873861666), UINT64_C( 5118221393808769814), UINT64_C(16098773806195315990) },
      UINT8_C(223) },
    { { UINT64_C( 9466760820888259901), UINT64_C(11590213517992800858), UINT64_C( 7757939755219682866), UINT64_C( 4593395649468275474),
        UINT64_C( 7684791400528699474), UINT64_C( 8104717082054461711), UINT64_C(  596934719083592131), UINT64_C(  186731912363551319) },
      { UINT64_C( 9466760820888259901), UINT64_C(11590213517992800858), UINT64_C( 2849317109203539084), UINT64_C( 7073210640617124472),
        UINT64_C( 7430795439822753067), UINT64_C( 8104717082054461711), UINT64_C(  596934719083592131), UINT64_C(14272839169882817303) },
      UINT8_C( 99) },
    { { UINT64_C(18118008800709567309), UINT64_C(16507697237456321297), UINT64_C( 8896133154397222009), UINT64_C( 9690299689338283663),
        UINT64_C( 6178307864395852735), UINT64_C(11443776554071426493), UINT64_C( 3809607289946258282), UINT64_C(10328597623892800663) },
      { UINT64_C( 2833062592766912695), UINT64_C(16507697237456321297), UINT64_C(15778029533014577693), UINT64_C( 9690299689338283663),
        UINT64_C( 6178307864395852735), UINT64_C(11443776554071426493), UINT64_C(10491701351724939388), UINT64_C(17215376012001887242) },
      UINT8_C( 58) },
    { { UINT64_C( 9733657839125856561), UINT64_C( 9358196941742441913), UINT64_C( 8941576243473260042), UINT64_C(14850251011028857860),
        UINT64_C(  104898120560173746), UINT64_C( 3475725746543208498), UINT64_C( 7535738666354509792), UINT64_C(13362971775608641030) },
      { UINT64_C(16824071307823287090), UINT64_C( 9358196941742441913), UINT64_C( 3473591607638939496), UINT64_C(14850251011028857860),
        UINT64_C(  104898120560173746), UINT64_C(16133245679944505283), UINT64_C(12537422858062396580), UINT64_C( 7600522666477867469) },
      UINT8_C( 26) },
    { { UINT64_C(18197694132056126179), UINT64_C( 5752877186511236709), UINT64_C( 8262880055990461438), UINT64_C(10645934130263111005),
        UINT64_C(13747209660909954918), UINT64_C(10157524325585926996), UINT64_C(17401088260820364906), UINT64_C( 7101480608530499659) },
      { UINT64_C( 2577736626955282605), UINT64_C(16594568893986157872), UINT64_C( 8262880055990461438), UINT64_C(10645934130263111005),
        UINT64_C( 2988415396760388486), UINT64_C(12687258085180785328), UINT64_C(17401088260820364906), UINT64_C( 7101480608530499659) },
      UINT8_C(204) },
    { { UINT64_C(  988070399212999435), UINT64_C(17966758824275600188), UINT64_C(12464930033710598578), UINT64_C( 9300251499913519534),
        UINT64_C(14793267669562244468), UINT64_C(14776189547460713249), UINT64_C( 8942639017600907932), UINT64_C(15293217593047596612) },
      { UINT64_C(  988070399212999435), UINT64_C(17966758824275600188), UINT64_C(12464930033710598578), UINT64_C( 9300251499913519534),
        UINT64_C(11245421070162428395), UINT64_C( 6003324214242920454), UINT64_C( 7530003382692754017), UINT64_C( 9056298574333176666) },
      UINT8_C( 15) },
    { { UINT64_C(13920746815362263655), UINT64_C(10401526641683664352), UINT64_C(10580686325575231369), UINT64_C( 1983451578105070887),
        UINT64_C(11909334656321083148), UINT64_C(14299199558228219778), UINT64_C( 8887316567499550365), UINT64_C( 3020675228894395165) },
      { UINT64_C(13920746815362263655), UINT64_C(10056105781600122763), UINT64_C(  321064988683784100), UINT64_C( 1038009475267855905),
        UINT64_C(10717192764757579248), UINT64_C(14299199558228219778), UINT64_C(11863969623082130874), UINT64_C( 3020675228894395165) },
      UINT8_C(161) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512i a = simde_x_mm512_loadu_epu64(test_vec[i].a);
    simde__m512i b = simde_x_mm512_loadu_epu64(test_vec[i].b);
    simde__mmask8 r = simde_mm512_cmpeq_epu64_mask(a, b);
    simde_assert_equal_mmask8(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m512i a = simde_test_x86_random_u64x8();
    simde__m512i b = simde_x_mm512_mask_blend_epu64(simde_test_x86_random_mmask8(), a, simde_test_x86_random_u64x8());
    simde__mmask8 r = simde_mm512_cmpeq_epu64_mask(a, b);

    simde_test_x86_write_u64x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_u64x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_mask_cmpeq_epu64_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k1;
    const uint64_t a[8];
    const uint64_t b[8];
    const simde__mmask8 r;
  } test_vec[] = {
    { UINT8_C(191),
      { UINT64_C( 6357662089688737726), UINT64_C( 2621654976069595894), UINT64_C( 7835204011957282206), UINT64_C(15989208176058037801),
        UINT64_C(12380555584218776187), UINT64_C(12571394909135639299), UINT64_C( 5290512540226413430), UINT64_C(12727264037326168483) },
      { UINT64_C( 6357662089688737726), UINT64_C(12522632834547885579), UINT64_C( 7835204011957282206), UINT64_C( 8655758377874231097),
        UINT64_C( 5366526314226665317), UINT64_C(12571394909135639299), UINT64_C( 5290512540226413430), UINT64_C(12727264037326168483) },
      UINT8_C(165) },
    { UINT8_C(  9),
      { UINT64_C(  628857581166942698), UINT64_C( 9581722981176337855), UINT64_C(18370264565093959021), UINT64_C( 7955304745522005911),
        UINT64_C( 1148289609605655108), UINT64_C(12807408597194843632), UINT64_C(18328640476161842451), UINT64_C( 6765462280816176625) },
      { UINT64_C(  628857581166942698), UINT64_C( 9581722981176337855), UINT64_C(18370264565093959021), UINT64_C(12600643787540595560),
        UINT64_C( 1148289609605655108), UINT64_C(12807408597194843632), UINT64_C(18328640476161842451), UINT64_C(17813817667845771205) },
      UINT8_C(  1) },
    { UINT8_C( 33),
      { UINT64_C(16214906520714272868), UINT64_C(13607034335038223086), UINT64_C(18267519792317362811), UINT64_C(12188685919865359821),
        UINT64_C( 6214317023102139593), UINT64_C( 2108140517157616867), UINT64_C(15025367368435089168), UINT64_C(10957253286617802017) },
      { UINT64_C(16214906520714272868), UINT64_C(13607034335038223086), UINT64_C(18267519792317362811), UINT64_C(12188685919865359821),
        UINT64_C( 6214317023102139593), UINT64_C( 2108140517157616867), UINT64_C(15353906066784157775), UINT64_C(10957253286617802017) },
      UINT8_C( 33) },
    { UINT8_C(180),
      { UINT64_C( 2882507726690675328), UINT64_C(12260146498955295576), UINT64_C( 8317082200217705707), UINT64_C(13243954243741303088),
        UINT64_C(10596423723186618980), UINT64_C( 4448530939986282698), UINT64_C(15446406256788271031), UINT64_C( 8491739481113433833) },
      { UINT64_C( 2882507726690675328), UINT64_C(12260146498955295576), UINT64_C( 8317082200217705707), UINT64_C( 6427280018882258860),
        UINT64_C(16854395012476997168), UINT64_C( 4900110212212373525), UINT64_C( 8873888760566659438), UINT64_C( 1171334892294281161) },
      UINT8_C(  4) },
    { UINT8_C( 15),
      { UINT64_C(  564351663727833142), UINT64_C( 5180026188717300393), UINT64_C( 7329735031221039867), UINT64_C(16045701673918634076),
        UINT64_C( 3934402856919667384), UINT64_C( 8255031554789626089), UINT64_C(  650572979818936693), UINT64_C( 6227162850216302308) },
      { UINT64_C( 2137381560446904038), UINT64_C(13959739702969207249), UINT64_C( 7329735031221039867), UINT64_C(14138618779773143873),
        UINT64_C( 8083646454481493724), UINT64_C(13220442641964504170), UINT64_C(  650572979818936693), UINT64_C( 3865668864526770690) },
      UINT8_C(  4) },
    { UINT8_C(221),
      { UINT64_C( 9442122943782869574), UINT64_C(15867506713762829023), UINT64_C( 7622718414755494415), UINT64_C(11437666786775278135),
        UINT64_C( 9252676911796287515), UINT64_C( 2509644172254273198), UINT64_C(13182549025180166278), UINT64_C(15269821465513687028) },
      { UINT64_C(14331897777846090949), UINT64_C( 5815715888283696511), UINT64_C( 9578816178241453754), UINT64_C(11437666786775278135),
        UINT64_C( 9252676911796287515), UINT64_C(11508369290851668892), UINT64_C( 1856545553737289390), UINT64_C(  263989774385386311) },
      UINT8_C( 24) },
    { UINT8_C(162),
      { UINT64_C(17417985707368058833), UINT64_C( 1569100112806911618), UINT64_C(14638425260896755407), UINT64_C( 5153406012437066552),
        UINT64_C(11910727036759311779), UINT64_C(10113012996543163654), UINT64_C(10287141114164949953), UINT64_C(11994762576567234487) },
      { UINT64_C(10430982743507608570), UINT64_C( 1569100112806911618), UINT64_C(14638425260896755407), UINT64_C( 5153406012437066552),
        UINT64_C(11221988558598428577), UINT64_C( 2118823491839037474), UINT64_C(10287141114164949953), UINT64_C(11994762576567234487) },
      UINT8_C(130) },
    { UINT8_C(220),
      { UINT64_C(13841112995039565000), UINT64_C(14029211945837777639), UINT64_C(11983135385562305372), UINT64_C(12399589426529781533),
        UINT64_C(16011500603829220484), UINT64_C(12235117235113068313), UINT64_C( 7528828131574654385), UINT64_C( 3502592885274999564) },
      { UINT64_C( 3242266358416985129), UINT64_C(14029211945837777639), UINT64_C(11983135385562305372), UINT64_C(12399589426529781533),
        UINT64_C(16011500603829220484), UINT64_C( 1145394708284664609), UINT64_C( 7528828131574654385), UINT64_C(18074804591672284753) },
      UINT8_C( 92) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512i a = simde_x_mm512_loadu_epu64(test_vec[i].a);
    simde__m512i b = simde_x_mm512_loadu_epu64(test_vec[i].b);
    simde__mmask8 r = simde_mm512_mask_cmpeq_epu64_mask(test_vec[i].k1, a, b);
    simde_assert_equal_mmask8(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k1 = simde_test_x86_random_mmask8();
    simde__m512i a = simde_test_x86_random_u64x8();
    simde__m512i b = simde_x_mm512_mask_blend_epu64(simde_test_x86_random_mmask8(), a, simde_test_x86_random_u64x8());
    simde__mmask8 r = simde_mm512_mask_cmpeq_epu64_mask(k1, a, b);

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
test_simde_mm512_cmpeq_ps_mask (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const simde_float32 a[16];
    const simde_float32 b[16];
    const simde__mmask16 r;
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(  -330.05), SIMDE_FLOAT32_C(   847.28), SIMDE_FLOAT32_C(    61.79), SIMDE_FLOAT32_C(   748.75),
        SIMDE_FLOAT32_C(  -125.94), SIMDE_FLOAT32_C(  -287.83), SIMDE_FLOAT32_C(  -156.45), SIMDE_FLOAT32_C(  -904.26),
        SIMDE_FLOAT32_C(   393.62), SIMDE_FLOAT32_C(   694.71), SIMDE_FLOAT32_C(   345.37), SIMDE_FLOAT32_C(   245.98),
        SIMDE_FLOAT32_C(  -522.67), SIMDE_FLOAT32_C(   140.34), SIMDE_FLOAT32_C(  -555.38), SIMDE_FLOAT32_C(   596.45) },
      { SIMDE_FLOAT32_C(  -330.05), SIMDE_FLOAT32_C(  -812.74), SIMDE_FLOAT32_C(    61.79), SIMDE_FLOAT32_C(  -304.55),
        SIMDE_FLOAT32_C(    95.53), SIMDE_FLOAT32_C(  -287.83), SIMDE_FLOAT32_C(  -156.45), SIMDE_FLOAT32_C(   699.14),
        SIMDE_FLOAT32_C(   676.85), SIMDE_FLOAT32_C(   694.71), SIMDE_FLOAT32_C(   345.37), SIMDE_FLOAT32_C(   245.98),
        SIMDE_FLOAT32_C(  -161.51), SIMDE_FLOAT32_C(   140.34), SIMDE_FLOAT32_C(  -399.39), SIMDE_FLOAT32_C(   596.45) },
      UINT16_C(44645) },
    { { SIMDE_FLOAT32_C(  -717.84), SIMDE_FLOAT32_C(   512.02), SIMDE_FLOAT32_C(    98.80), SIMDE_FLOAT32_C(  -966.72),
        SIMDE_FLOAT32_C(   -60.71), SIMDE_FLOAT32_C(  -584.27), SIMDE_FLOAT32_C(   204.10), SIMDE_FLOAT32_C(   295.96),
        SIMDE_FLOAT32_C(   -70.24), SIMDE_FLOAT32_C(   661.77), SIMDE_FLOAT32_C(   894.04), SIMDE_FLOAT32_C(   352.28),
        SIMDE_FLOAT32_C(   620.44), SIMDE_FLOAT32_C(   936.22), SIMDE_FLOAT32_C(   428.81), SIMDE_FLOAT32_C(   543.55) },
      { SIMDE_FLOAT32_C(  -717.84), SIMDE_FLOAT32_C(   313.36), SIMDE_FLOAT32_C(  -806.61), SIMDE_FLOAT32_C(   690.40),
        SIMDE_FLOAT32_C(   646.60), SIMDE_FLOAT32_C(  -584.27), SIMDE_FLOAT32_C(   204.10), SIMDE_FLOAT32_C(   460.04),
        SIMDE_FLOAT32_C(   733.57), SIMDE_FLOAT32_C(   661.77), SIMDE_FLOAT32_C(   894.04), SIMDE_FLOAT32_C(  -252.47),
        SIMDE_FLOAT32_C(  -340.15), SIMDE_FLOAT32_C(   936.22), SIMDE_FLOAT32_C(   428.81), SIMDE_FLOAT32_C(   543.55) },
      UINT16_C(58977) },
    { { SIMDE_FLOAT32_C(   375.91), SIMDE_FLOAT32_C(   -19.72), SIMDE_FLOAT32_C(   336.05), SIMDE_FLOAT32_C(  -540.20),
        SIMDE_FLOAT32_C(  -665.47), SIMDE_FLOAT32_C(  -492.58), SIMDE_FLOAT32_C(    15.30), SIMDE_FLOAT32_C(   126.92),
        SIMDE_FLOAT32_C(   767.58), SIMDE_FLOAT32_C(   861.15), SIMDE_FLOAT32_C(   -58.47), SIMDE_FLOAT32_C(  -387.52),
        SIMDE_FLOAT32_C(   800.70), SIMDE_FLOAT32_C(  -537.31), SIMDE_FLOAT32_C(  -644.51), SIMDE_FLOAT32_C(  -955.44) },
      { SIMDE_FLOAT32_C(   375.91), SIMDE_FLOAT32_C(  -356.80), SIMDE_FLOAT32_C(   336.05), SIMDE_FLOAT32_C(   -10.02),
        SIMDE_FLOAT32_C(   -64.34), SIMDE_FLOAT32_C(   408.76), SIMDE_FLOAT32_C(  -734.89), SIMDE_FLOAT32_C(   126.92),
        SIMDE_FLOAT32_C(    10.21), SIMDE_FLOAT32_C(   861.15), SIMDE_FLOAT32_C(   153.18), SIMDE_FLOAT32_C(   569.21),
        SIMDE_FLOAT32_C(   321.66), SIMDE_FLOAT32_C(  -537.31), SIMDE_FLOAT32_C(   613.36), SIMDE_FLOAT32_C(  -776.54) },
      UINT16_C( 8837) },
    { { SIMDE_FLOAT32_C(  -842.85), SIMDE_FLOAT32_C(  -336.15), SIMDE_FLOAT32_C(  -966.61), SIMDE_FLOAT32_C(   670.20),
        SIMDE_FLOAT32_C(   783.55), SIMDE_FLOAT32_C(   477.19), SIMDE_FLOAT32_C(  -864.95), SIMDE_FLOAT32_C(  -372.20),
        SIMDE_FLOAT32_C(   -94.30), SIMDE_FLOAT32_C(  -879.40), SIMDE_FLOAT32_C(  -161.82), SIMDE_FLOAT32_C(   100.12),
        SIMDE_FLOAT32_C(   850.32), SIMDE_FLOAT32_C(   476.49), SIMDE_FLOAT32_C(  -174.44), SIMDE_FLOAT32_C(   934.13) },
      { SIMDE_FLOAT32_C(   404.40), SIMDE_FLOAT32_C(  -570.57), SIMDE_FLOAT32_C(   -86.01), SIMDE_FLOAT32_C(   670.20),
        SIMDE_FLOAT32_C(   312.45), SIMDE_FLOAT32_C(   381.45), SIMDE_FLOAT32_C(  -864.95), SIMDE_FLOAT32_C(  -372.20),
        SIMDE_FLOAT32_C(   -94.30), SIMDE_FLOAT32_C(  -879.40), SIMDE_FLOAT32_C(  -161.82), SIMDE_FLOAT32_C(   100.12),
        SIMDE_FLOAT32_C(   850.32), SIMDE_FLOAT32_C(   386.54), SIMDE_FLOAT32_C(   295.11), SIMDE_FLOAT32_C(  -992.52) },
      UINT16_C( 8136) },
    { { SIMDE_FLOAT32_C(   877.31), SIMDE_FLOAT32_C(   884.47), SIMDE_FLOAT32_C(  -380.38), SIMDE_FLOAT32_C(  -700.84),
        SIMDE_FLOAT32_C(   945.89), SIMDE_FLOAT32_C(   280.68), SIMDE_FLOAT32_C(   832.06), SIMDE_FLOAT32_C(   359.22),
        SIMDE_FLOAT32_C(   586.70), SIMDE_FLOAT32_C(   448.55), SIMDE_FLOAT32_C(   510.98), SIMDE_FLOAT32_C(  -325.00),
        SIMDE_FLOAT32_C(   847.13), SIMDE_FLOAT32_C(  -548.42), SIMDE_FLOAT32_C(  -663.23), SIMDE_FLOAT32_C(   110.33) },
      { SIMDE_FLOAT32_C(   877.31), SIMDE_FLOAT32_C(   884.47), SIMDE_FLOAT32_C(  -380.38), SIMDE_FLOAT32_C(  -700.84),
        SIMDE_FLOAT32_C(   945.89), SIMDE_FLOAT32_C(   280.68), SIMDE_FLOAT32_C(   832.06), SIMDE_FLOAT32_C(   359.22),
        SIMDE_FLOAT32_C(  -806.36), SIMDE_FLOAT32_C(  -673.67), SIMDE_FLOAT32_C(   510.98), SIMDE_FLOAT32_C(  -346.39),
        SIMDE_FLOAT32_C(   789.45), SIMDE_FLOAT32_C(  -548.42), SIMDE_FLOAT32_C(   989.10), SIMDE_FLOAT32_C(  -487.94) },
      UINT16_C( 9471) },
    { { SIMDE_FLOAT32_C(  -787.05), SIMDE_FLOAT32_C(   806.72), SIMDE_FLOAT32_C(   520.29), SIMDE_FLOAT32_C(  -321.05),
        SIMDE_FLOAT32_C(  -366.95), SIMDE_FLOAT32_C(  -748.89), SIMDE_FLOAT32_C(   687.71), SIMDE_FLOAT32_C(  -416.88),
        SIMDE_FLOAT32_C(  -561.92), SIMDE_FLOAT32_C(  -926.01), SIMDE_FLOAT32_C(   843.79), SIMDE_FLOAT32_C(   849.56),
        SIMDE_FLOAT32_C(   -51.86), SIMDE_FLOAT32_C(  -481.78), SIMDE_FLOAT32_C(   491.33), SIMDE_FLOAT32_C(  -936.26) },
      { SIMDE_FLOAT32_C(  -787.05), SIMDE_FLOAT32_C(   806.72), SIMDE_FLOAT32_C(   299.54), SIMDE_FLOAT32_C(   884.74),
        SIMDE_FLOAT32_C(  -278.71), SIMDE_FLOAT32_C(  -748.89), SIMDE_FLOAT32_C(   570.30), SIMDE_FLOAT32_C(  -416.88),
        SIMDE_FLOAT32_C(  -561.92), SIMDE_FLOAT32_C(    59.09), SIMDE_FLOAT32_C(   843.79), SIMDE_FLOAT32_C(   849.56),
        SIMDE_FLOAT32_C(  -136.84), SIMDE_FLOAT32_C(  -481.78), SIMDE_FLOAT32_C(   491.33), SIMDE_FLOAT32_C(  -936.26) },
      UINT16_C(60835) },
    { { SIMDE_FLOAT32_C(  -837.49), SIMDE_FLOAT32_C(   -79.02), SIMDE_FLOAT32_C(  -844.39), SIMDE_FLOAT32_C(  -973.47),
        SIMDE_FLOAT32_C(  -499.80), SIMDE_FLOAT32_C(   961.14), SIMDE_FLOAT32_C(   336.59), SIMDE_FLOAT32_C(  -368.95),
        SIMDE_FLOAT32_C(   727.99), SIMDE_FLOAT32_C(  -900.81), SIMDE_FLOAT32_C(   655.07), SIMDE_FLOAT32_C(  -624.42),
        SIMDE_FLOAT32_C(   244.09), SIMDE_FLOAT32_C(   360.96), SIMDE_FLOAT32_C(  -837.70), SIMDE_FLOAT32_C(  -929.19) },
      { SIMDE_FLOAT32_C(  -837.49), SIMDE_FLOAT32_C(   -79.02), SIMDE_FLOAT32_C(  -169.54), SIMDE_FLOAT32_C(   100.98),
        SIMDE_FLOAT32_C(  -499.80), SIMDE_FLOAT32_C(   961.14), SIMDE_FLOAT32_C(  -254.87), SIMDE_FLOAT32_C(   592.42),
        SIMDE_FLOAT32_C(   312.40), SIMDE_FLOAT32_C(   958.12), SIMDE_FLOAT32_C(  -284.13), SIMDE_FLOAT32_C(  -624.42),
        SIMDE_FLOAT32_C(  -196.30), SIMDE_FLOAT32_C(   360.96), SIMDE_FLOAT32_C(  -837.70), SIMDE_FLOAT32_C(  -975.45) },
      UINT16_C(26675) },
    { { SIMDE_FLOAT32_C(   928.69), SIMDE_FLOAT32_C(    -3.95), SIMDE_FLOAT32_C(  -214.33), SIMDE_FLOAT32_C(  -971.80),
        SIMDE_FLOAT32_C(  -780.70), SIMDE_FLOAT32_C(   950.39), SIMDE_FLOAT32_C(  -857.68), SIMDE_FLOAT32_C(  -246.08),
        SIMDE_FLOAT32_C(   789.62), SIMDE_FLOAT32_C(  -840.89), SIMDE_FLOAT32_C(   194.42), SIMDE_FLOAT32_C(  -873.48),
        SIMDE_FLOAT32_C(  -365.78), SIMDE_FLOAT32_C(  -117.81), SIMDE_FLOAT32_C(   601.86), SIMDE_FLOAT32_C(   913.26) },
      { SIMDE_FLOAT32_C(   928.69), SIMDE_FLOAT32_C(    -3.95), SIMDE_FLOAT32_C(  -214.33), SIMDE_FLOAT32_C(   377.34),
        SIMDE_FLOAT32_C(  -525.21), SIMDE_FLOAT32_C(  -436.16), SIMDE_FLOAT32_C(   186.25), SIMDE_FLOAT32_C(  -246.08),
        SIMDE_FLOAT32_C(   623.36), SIMDE_FLOAT32_C(  -840.89), SIMDE_FLOAT32_C(   194.42), SIMDE_FLOAT32_C(  -873.48),
        SIMDE_FLOAT32_C(  -679.52), SIMDE_FLOAT32_C(   447.41), SIMDE_FLOAT32_C(  -608.79), SIMDE_FLOAT32_C(   721.43) },
      UINT16_C( 3719) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512 a = simde_mm512_loadu_ps(test_vec[i].a);
    simde__m512 b = simde_mm512_loadu_ps(test_vec[i].b);
    simde__mmask16 r = simde_mm512_cmpeq_ps_mask(a, b);
    simde_assert_equal_mmask16(r, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm512_mask_cmpeq_ps_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask16 k1;
    const simde_float32 a[16];
    const simde_float32 b[16];
    const simde__mmask16 r;
  } test_vec[] = {
    { UINT16_C( 1486),
      { SIMDE_FLOAT32_C(  -978.64), SIMDE_FLOAT32_C(   145.46), SIMDE_FLOAT32_C(   882.49), SIMDE_FLOAT32_C(   348.23),
        SIMDE_FLOAT32_C(  -920.43), SIMDE_FLOAT32_C(  -833.37), SIMDE_FLOAT32_C(  -798.91), SIMDE_FLOAT32_C(   269.93),
        SIMDE_FLOAT32_C(  -930.14), SIMDE_FLOAT32_C(   218.92), SIMDE_FLOAT32_C(   852.54), SIMDE_FLOAT32_C(   -23.19),
        SIMDE_FLOAT32_C(   190.59), SIMDE_FLOAT32_C(   752.28), SIMDE_FLOAT32_C(   871.89), SIMDE_FLOAT32_C(   166.92) },
      { SIMDE_FLOAT32_C(   869.13), SIMDE_FLOAT32_C(   -44.65), SIMDE_FLOAT32_C(   882.49), SIMDE_FLOAT32_C(   348.23),
        SIMDE_FLOAT32_C(  -612.07), SIMDE_FLOAT32_C(   994.13), SIMDE_FLOAT32_C(  -798.91), SIMDE_FLOAT32_C(   269.93),
        SIMDE_FLOAT32_C(  -336.85), SIMDE_FLOAT32_C(   218.92), SIMDE_FLOAT32_C(  -536.27), SIMDE_FLOAT32_C(  -506.28),
        SIMDE_FLOAT32_C(  -784.35), SIMDE_FLOAT32_C(   -40.91), SIMDE_FLOAT32_C(   191.72), SIMDE_FLOAT32_C(  -763.00) },
      UINT16_C(  204) },
    { UINT16_C( 6821),
      { SIMDE_FLOAT32_C(   240.83), SIMDE_FLOAT32_C(   786.33), SIMDE_FLOAT32_C(   454.05), SIMDE_FLOAT32_C(   310.69),
        SIMDE_FLOAT32_C(     5.25), SIMDE_FLOAT32_C(   306.59), SIMDE_FLOAT32_C(  -712.50), SIMDE_FLOAT32_C(  -804.16),
        SIMDE_FLOAT32_C(    58.87), SIMDE_FLOAT32_C(  -840.61), SIMDE_FLOAT32_C(   362.76), SIMDE_FLOAT32_C(   -72.00),
        SIMDE_FLOAT32_C(   114.74), SIMDE_FLOAT32_C(   396.34), SIMDE_FLOAT32_C(  -429.95), SIMDE_FLOAT32_C(   502.67) },
      { SIMDE_FLOAT32_C(   240.83), SIMDE_FLOAT32_C(  -972.35), SIMDE_FLOAT32_C(   761.32), SIMDE_FLOAT32_C(  -946.38),
        SIMDE_FLOAT32_C(   439.55), SIMDE_FLOAT32_C(   306.59), SIMDE_FLOAT32_C(  -712.50), SIMDE_FLOAT32_C(   655.20),
        SIMDE_FLOAT32_C(   184.13), SIMDE_FLOAT32_C(   739.06), SIMDE_FLOAT32_C(   892.21), SIMDE_FLOAT32_C(   288.68),
        SIMDE_FLOAT32_C(   114.74), SIMDE_FLOAT32_C(   396.34), SIMDE_FLOAT32_C(  -429.95), SIMDE_FLOAT32_C(  -945.90) },
      UINT16_C( 4129) },
    { UINT16_C(55323),
      { SIMDE_FLOAT32_C(  -766.55), SIMDE_FLOAT32_C(   652.29), SIMDE_FLOAT32_C(  -535.13), SIMDE_FLOAT32_C(   292.32),
        SIMDE_FLOAT32_C(   811.68), SIMDE_FLOAT32_C(   827.63), SIMDE_FLOAT32_C(  -779.68), SIMDE_FLOAT32_C(   -73.58),
        SIMDE_FLOAT32_C(   223.97), SIMDE_FLOAT32_C(  -209.64), SIMDE_FLOAT32_C(  -570.92), SIMDE_FLOAT32_C(  -385.56),
        SIMDE_FLOAT32_C(  -181.99), SIMDE_FLOAT32_C(  -809.60), SIMDE_FLOAT32_C(  -331.94), SIMDE_FLOAT32_C(  -742.43) },
      { SIMDE_FLOAT32_C(  -766.55), SIMDE_FLOAT32_C(   652.29), SIMDE_FLOAT32_C(   912.77), SIMDE_FLOAT32_C(   599.58),
        SIMDE_FLOAT32_C(   811.68), SIMDE_FLOAT32_C(   804.98), SIMDE_FLOAT32_C(  -111.74), SIMDE_FLOAT32_C(   -73.58),
        SIMDE_FLOAT32_C(   282.42), SIMDE_FLOAT32_C(  -209.64), SIMDE_FLOAT32_C(  -570.92), SIMDE_FLOAT32_C(  -385.56),
        SIMDE_FLOAT32_C(   287.92), SIMDE_FLOAT32_C(  -809.60), SIMDE_FLOAT32_C(  -184.78), SIMDE_FLOAT32_C(  -742.43) },
      UINT16_C(34835) },
    { UINT16_C(23184),
      { SIMDE_FLOAT32_C(   107.73), SIMDE_FLOAT32_C(    34.00), SIMDE_FLOAT32_C(   577.00), SIMDE_FLOAT32_C(  -668.30),
        SIMDE_FLOAT32_C(   824.36), SIMDE_FLOAT32_C(  -993.92), SIMDE_FLOAT32_C(   -53.86), SIMDE_FLOAT32_C(  -357.63),
        SIMDE_FLOAT32_C(  -803.53), SIMDE_FLOAT32_C(   614.20), SIMDE_FLOAT32_C(  -100.06), SIMDE_FLOAT32_C(  -388.08),
        SIMDE_FLOAT32_C(  -170.40), SIMDE_FLOAT32_C(  -187.29), SIMDE_FLOAT32_C(  -788.51), SIMDE_FLOAT32_C(   784.06) },
      { SIMDE_FLOAT32_C(   107.73), SIMDE_FLOAT32_C(    34.00), SIMDE_FLOAT32_C(   551.78), SIMDE_FLOAT32_C(  -668.30),
        SIMDE_FLOAT32_C(   460.81), SIMDE_FLOAT32_C(  -993.92), SIMDE_FLOAT32_C(  -553.70), SIMDE_FLOAT32_C(  -357.63),
        SIMDE_FLOAT32_C(  -803.53), SIMDE_FLOAT32_C(   261.53), SIMDE_FLOAT32_C(  -729.91), SIMDE_FLOAT32_C(   399.11),
        SIMDE_FLOAT32_C(  -170.40), SIMDE_FLOAT32_C(  -187.29), SIMDE_FLOAT32_C(  -788.51), SIMDE_FLOAT32_C(   649.35) },
      UINT16_C(20608) },
    { UINT16_C(46431),
      { SIMDE_FLOAT32_C(   632.76), SIMDE_FLOAT32_C(   -72.81), SIMDE_FLOAT32_C(  -415.49), SIMDE_FLOAT32_C(   829.23),
        SIMDE_FLOAT32_C(  -458.61), SIMDE_FLOAT32_C(   484.45), SIMDE_FLOAT32_C(  -558.85), SIMDE_FLOAT32_C(   370.99),
        SIMDE_FLOAT32_C(  -702.84), SIMDE_FLOAT32_C(  -347.36), SIMDE_FLOAT32_C(   155.05), SIMDE_FLOAT32_C(   -85.16),
        SIMDE_FLOAT32_C(   752.39), SIMDE_FLOAT32_C(  -293.17), SIMDE_FLOAT32_C(  -185.05), SIMDE_FLOAT32_C(   213.20) },
      { SIMDE_FLOAT32_C(  -919.57), SIMDE_FLOAT32_C(   -72.81), SIMDE_FLOAT32_C(  -415.49), SIMDE_FLOAT32_C(  -359.36),
        SIMDE_FLOAT32_C(  -477.22), SIMDE_FLOAT32_C(  -767.98), SIMDE_FLOAT32_C(  -558.85), SIMDE_FLOAT32_C(    64.40),
        SIMDE_FLOAT32_C(  -702.84), SIMDE_FLOAT32_C(  -347.36), SIMDE_FLOAT32_C(   155.05), SIMDE_FLOAT32_C(   -85.16),
        SIMDE_FLOAT32_C(   716.12), SIMDE_FLOAT32_C(  -293.17), SIMDE_FLOAT32_C(  -185.05), SIMDE_FLOAT32_C(   348.88) },
      UINT16_C( 9542) },
    { UINT16_C(48334),
      { SIMDE_FLOAT32_C(   444.67), SIMDE_FLOAT32_C(   619.26), SIMDE_FLOAT32_C(   534.39), SIMDE_FLOAT32_C(   741.83),
        SIMDE_FLOAT32_C(  -728.10), SIMDE_FLOAT32_C(  -310.56), SIMDE_FLOAT32_C(  -343.33), SIMDE_FLOAT32_C(  -975.71),
        SIMDE_FLOAT32_C(   396.27), SIMDE_FLOAT32_C(   471.62), SIMDE_FLOAT32_C(   237.49), SIMDE_FLOAT32_C(   476.71),
        SIMDE_FLOAT32_C(  -267.12), SIMDE_FLOAT32_C(   199.42), SIMDE_FLOAT32_C(  -882.65), SIMDE_FLOAT32_C(   255.66) },
      { SIMDE_FLOAT32_C(   444.67), SIMDE_FLOAT32_C(   619.26), SIMDE_FLOAT32_C(  -679.94), SIMDE_FLOAT32_C(   741.83),
        SIMDE_FLOAT32_C(  -728.10), SIMDE_FLOAT32_C(  -310.56), SIMDE_FLOAT32_C(  -819.19), SIMDE_FLOAT32_C(  -975.71),
        SIMDE_FLOAT32_C(   396.27), SIMDE_FLOAT32_C(   556.52), SIMDE_FLOAT32_C(   237.49), SIMDE_FLOAT32_C(   476.71),
        SIMDE_FLOAT32_C(  -267.12), SIMDE_FLOAT32_C(   199.42), SIMDE_FLOAT32_C(  -882.65), SIMDE_FLOAT32_C(   -38.59) },
      UINT16_C(15498) },
    { UINT16_C(27010),
      { SIMDE_FLOAT32_C(   737.86), SIMDE_FLOAT32_C(   359.92), SIMDE_FLOAT32_C(  -594.90), SIMDE_FLOAT32_C(   134.13),
        SIMDE_FLOAT32_C(  -168.46), SIMDE_FLOAT32_C(   642.59), SIMDE_FLOAT32_C(  -389.17), SIMDE_FLOAT32_C(   564.42),
        SIMDE_FLOAT32_C(  -157.99), SIMDE_FLOAT32_C(  -271.82), SIMDE_FLOAT32_C(  -179.92), SIMDE_FLOAT32_C(  -726.54),
        SIMDE_FLOAT32_C(  -114.72), SIMDE_FLOAT32_C(   140.14), SIMDE_FLOAT32_C(    20.70), SIMDE_FLOAT32_C(   131.82) },
      { SIMDE_FLOAT32_C(  -826.04), SIMDE_FLOAT32_C(   201.51), SIMDE_FLOAT32_C(    94.48), SIMDE_FLOAT32_C(   134.13),
        SIMDE_FLOAT32_C(  -241.96), SIMDE_FLOAT32_C(   642.59), SIMDE_FLOAT32_C(  -389.17), SIMDE_FLOAT32_C(   564.42),
        SIMDE_FLOAT32_C(  -157.99), SIMDE_FLOAT32_C(  -271.82), SIMDE_FLOAT32_C(  -179.92), SIMDE_FLOAT32_C(     4.57),
        SIMDE_FLOAT32_C(   815.69), SIMDE_FLOAT32_C(   939.43), SIMDE_FLOAT32_C(    20.70), SIMDE_FLOAT32_C(   553.55) },
      UINT16_C(16768) },
    { UINT16_C(40733),
      { SIMDE_FLOAT32_C(   433.06), SIMDE_FLOAT32_C(   298.52), SIMDE_FLOAT32_C(   695.31), SIMDE_FLOAT32_C(  -724.93),
        SIMDE_FLOAT32_C(  -973.30), SIMDE_FLOAT32_C(  -484.61), SIMDE_FLOAT32_C(  -451.47), SIMDE_FLOAT32_C(   -88.02),
        SIMDE_FLOAT32_C(   655.53), SIMDE_FLOAT32_C(   569.23), SIMDE_FLOAT32_C(  -956.20), SIMDE_FLOAT32_C(   829.50),
        SIMDE_FLOAT32_C(  -229.26), SIMDE_FLOAT32_C(   138.28), SIMDE_FLOAT32_C(   732.09), SIMDE_FLOAT32_C(   528.78) },
      { SIMDE_FLOAT32_C(   544.29), SIMDE_FLOAT32_C(   -14.67), SIMDE_FLOAT32_C(   695.31), SIMDE_FLOAT32_C(  -560.04),
        SIMDE_FLOAT32_C(  -973.30), SIMDE_FLOAT32_C(  -484.61), SIMDE_FLOAT32_C(  -451.47), SIMDE_FLOAT32_C(   568.30),
        SIMDE_FLOAT32_C(   -20.82), SIMDE_FLOAT32_C(   569.23), SIMDE_FLOAT32_C(   121.85), SIMDE_FLOAT32_C(  -721.47),
        SIMDE_FLOAT32_C(  -229.26), SIMDE_FLOAT32_C(   138.28), SIMDE_FLOAT32_C(   732.09), SIMDE_FLOAT32_C(   528.78) },
      UINT16_C(37396) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512 a = simde_mm512_loadu_ps(test_vec[i].a);
    simde__m512 b = simde_mm512_loadu_ps(test_vec[i].b);
    simde__mmask16 r = simde_mm512_mask_cmpeq_ps_mask(test_vec[i].k1, a, b);
    simde_assert_equal_mmask16(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask16 k1 = simde_test_x86_random_mmask16();
    simde__m512 a = simde_test_x86_random_f32x16(-1000.0, 1000.0);
    simde__m512 b = simde_mm512_mask_blend_ps(simde_test_x86_random_mmask16(), a, simde_test_x86_random_f32x16(-1000.0, 1000.0));
    simde__mmask16 r = simde_mm512_mask_cmpeq_ps_mask(k1, a, b);

    simde_test_x86_write_mmask16(2, k1, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f32x16(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_cmpeq_pd_mask (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const simde_float64 a[8];
    const simde_float64 b[8];
    const simde__mmask8 r;
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(   271.69), SIMDE_FLOAT64_C(   217.70), SIMDE_FLOAT64_C(   925.72), SIMDE_FLOAT64_C(   520.03),
        SIMDE_FLOAT64_C(   127.68), SIMDE_FLOAT64_C(   -63.68), SIMDE_FLOAT64_C(  -338.02), SIMDE_FLOAT64_C(   823.86) },
      { SIMDE_FLOAT64_C(   690.45), SIMDE_FLOAT64_C(   347.44), SIMDE_FLOAT64_C(  -649.53), SIMDE_FLOAT64_C(  -641.60),
        SIMDE_FLOAT64_C(   658.05), SIMDE_FLOAT64_C(  -212.84), SIMDE_FLOAT64_C(   796.21), SIMDE_FLOAT64_C(   -36.15) },
      UINT8_C(  0) },
    { { SIMDE_FLOAT64_C(   417.99), SIMDE_FLOAT64_C(  -883.29), SIMDE_FLOAT64_C(   571.34), SIMDE_FLOAT64_C(   535.08),
        SIMDE_FLOAT64_C(  -923.74), SIMDE_FLOAT64_C(   773.69), SIMDE_FLOAT64_C(  -589.26), SIMDE_FLOAT64_C(   350.94) },
      { SIMDE_FLOAT64_C(   179.83), SIMDE_FLOAT64_C(   445.85), SIMDE_FLOAT64_C(  -677.60), SIMDE_FLOAT64_C(  -480.10),
        SIMDE_FLOAT64_C(  -974.87), SIMDE_FLOAT64_C(  -558.93), SIMDE_FLOAT64_C(    47.77), SIMDE_FLOAT64_C(   924.57) },
      UINT8_C(  0) },
    { { SIMDE_FLOAT64_C(  -695.12), SIMDE_FLOAT64_C(  -819.01), SIMDE_FLOAT64_C(   861.37), SIMDE_FLOAT64_C(  -968.92),
        SIMDE_FLOAT64_C(  -642.09), SIMDE_FLOAT64_C(   475.36), SIMDE_FLOAT64_C(  -653.40), SIMDE_FLOAT64_C(   274.91) },
      { SIMDE_FLOAT64_C(   408.72), SIMDE_FLOAT64_C(  -646.21), SIMDE_FLOAT64_C(  -843.45), SIMDE_FLOAT64_C(   107.84),
        SIMDE_FLOAT64_C(   465.38), SIMDE_FLOAT64_C(  -336.34), SIMDE_FLOAT64_C(  -820.42), SIMDE_FLOAT64_C(  -749.33) },
      UINT8_C(  0) },
    { { SIMDE_FLOAT64_C(    -9.72), SIMDE_FLOAT64_C(   643.44), SIMDE_FLOAT64_C(   336.27), SIMDE_FLOAT64_C(  -313.97),
        SIMDE_FLOAT64_C(  -863.83), SIMDE_FLOAT64_C(  -448.10), SIMDE_FLOAT64_C(   771.84), SIMDE_FLOAT64_C(   249.27) },
      { SIMDE_FLOAT64_C(  -506.33), SIMDE_FLOAT64_C(    28.98), SIMDE_FLOAT64_C(  -919.42), SIMDE_FLOAT64_C(  -710.08),
        SIMDE_FLOAT64_C(  -376.38), SIMDE_FLOAT64_C(   181.22), SIMDE_FLOAT64_C(  -315.61), SIMDE_FLOAT64_C(  -521.71) },
      UINT8_C(  0) },
    { { SIMDE_FLOAT64_C(  -309.90), SIMDE_FLOAT64_C(  -566.85), SIMDE_FLOAT64_C(   953.96), SIMDE_FLOAT64_C(  -760.71),
        SIMDE_FLOAT64_C(   715.80), SIMDE_FLOAT64_C(   511.82), SIMDE_FLOAT64_C(   185.57), SIMDE_FLOAT64_C(   958.96) },
      { SIMDE_FLOAT64_C(  -823.31), SIMDE_FLOAT64_C(   653.67), SIMDE_FLOAT64_C(   300.89), SIMDE_FLOAT64_C(  -999.35),
        SIMDE_FLOAT64_C(  -123.69), SIMDE_FLOAT64_C(  -935.82), SIMDE_FLOAT64_C(  -283.75), SIMDE_FLOAT64_C(  -911.67) },
      UINT8_C(  0) },
    { { SIMDE_FLOAT64_C(  -370.17), SIMDE_FLOAT64_C(   581.24), SIMDE_FLOAT64_C(   903.15), SIMDE_FLOAT64_C(  -702.97),
        SIMDE_FLOAT64_C(  -784.81), SIMDE_FLOAT64_C(  -282.51), SIMDE_FLOAT64_C(  -162.91), SIMDE_FLOAT64_C(   -67.74) },
      { SIMDE_FLOAT64_C(  -458.51), SIMDE_FLOAT64_C(  -138.00), SIMDE_FLOAT64_C(   634.22), SIMDE_FLOAT64_C(  -641.32),
        SIMDE_FLOAT64_C(  -700.95), SIMDE_FLOAT64_C(  -830.62), SIMDE_FLOAT64_C(  -270.15), SIMDE_FLOAT64_C(  -342.52) },
      UINT8_C(  0) },
    { { SIMDE_FLOAT64_C(  -741.30), SIMDE_FLOAT64_C(  -961.63), SIMDE_FLOAT64_C(  -159.42), SIMDE_FLOAT64_C(   596.72),
        SIMDE_FLOAT64_C(  -872.26), SIMDE_FLOAT64_C(   -77.79), SIMDE_FLOAT64_C(   608.69), SIMDE_FLOAT64_C(   181.91) },
      { SIMDE_FLOAT64_C(  -693.78), SIMDE_FLOAT64_C(  -430.90), SIMDE_FLOAT64_C(  -141.87), SIMDE_FLOAT64_C(  -384.25),
        SIMDE_FLOAT64_C(   -74.70), SIMDE_FLOAT64_C(   434.70), SIMDE_FLOAT64_C(    -4.99), SIMDE_FLOAT64_C(   104.05) },
      UINT8_C(  0) },
    { { SIMDE_FLOAT64_C(   817.79), SIMDE_FLOAT64_C(   652.33), SIMDE_FLOAT64_C(  -345.32), SIMDE_FLOAT64_C(   150.71),
        SIMDE_FLOAT64_C(   939.32), SIMDE_FLOAT64_C(  -867.25), SIMDE_FLOAT64_C(   158.96), SIMDE_FLOAT64_C(  -396.12) },
      { SIMDE_FLOAT64_C(   363.34), SIMDE_FLOAT64_C(   571.53), SIMDE_FLOAT64_C(  -232.25), SIMDE_FLOAT64_C(   496.58),
        SIMDE_FLOAT64_C(    40.81), SIMDE_FLOAT64_C(   -69.57), SIMDE_FLOAT64_C(   792.81), SIMDE_FLOAT64_C(   833.83) },
      UINT8_C(  0) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512d a = simde_mm512_loadu_pd(test_vec[i].a);
    simde__m512d b = simde_mm512_loadu_pd(test_vec[i].b);
    simde__mmask8 r = simde_mm512_cmpeq_pd_mask(a, b);
    simde_assert_equal_mmask8(r, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm512_mask_cmpeq_pd_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k1;
    const simde_float64 a[8];
    const simde_float64 b[8];
    const simde__mmask8 r;
  } test_vec[] = {
    { UINT8_C(147),
      { SIMDE_FLOAT64_C(   134.75), SIMDE_FLOAT64_C(  -379.88), SIMDE_FLOAT64_C(  -122.96), SIMDE_FLOAT64_C(  -953.27),
        SIMDE_FLOAT64_C(  -724.34), SIMDE_FLOAT64_C(  -553.73), SIMDE_FLOAT64_C(  -909.47), SIMDE_FLOAT64_C(  -894.85) },
      { SIMDE_FLOAT64_C(   134.75), SIMDE_FLOAT64_C(   228.81), SIMDE_FLOAT64_C(  -122.96), SIMDE_FLOAT64_C(  -254.21),
        SIMDE_FLOAT64_C(  -226.89), SIMDE_FLOAT64_C(  -177.42), SIMDE_FLOAT64_C(  -450.66), SIMDE_FLOAT64_C(  -894.85) },
      UINT8_C(129) },
    { UINT8_C(136),
      { SIMDE_FLOAT64_C(  -342.41), SIMDE_FLOAT64_C(  -856.52), SIMDE_FLOAT64_C(  -431.74), SIMDE_FLOAT64_C(   487.49),
        SIMDE_FLOAT64_C(   265.33), SIMDE_FLOAT64_C(  -153.21), SIMDE_FLOAT64_C(  -892.14), SIMDE_FLOAT64_C(    74.86) },
      { SIMDE_FLOAT64_C(  -342.41), SIMDE_FLOAT64_C(  -838.70), SIMDE_FLOAT64_C(  -817.09), SIMDE_FLOAT64_C(   360.94),
        SIMDE_FLOAT64_C(  -510.19), SIMDE_FLOAT64_C(   317.66), SIMDE_FLOAT64_C(   981.07), SIMDE_FLOAT64_C(    74.86) },
      UINT8_C(128) },
    { UINT8_C(236),
      { SIMDE_FLOAT64_C(   813.12), SIMDE_FLOAT64_C(   454.92), SIMDE_FLOAT64_C(  -638.13), SIMDE_FLOAT64_C(    30.13),
        SIMDE_FLOAT64_C(  -316.26), SIMDE_FLOAT64_C(  -800.88), SIMDE_FLOAT64_C(   775.92), SIMDE_FLOAT64_C(   456.85) },
      { SIMDE_FLOAT64_C(   813.12), SIMDE_FLOAT64_C(  -674.74), SIMDE_FLOAT64_C(  -638.13), SIMDE_FLOAT64_C(   596.88),
        SIMDE_FLOAT64_C(  -316.26), SIMDE_FLOAT64_C(   327.50), SIMDE_FLOAT64_C(   740.36), SIMDE_FLOAT64_C(   456.85) },
      UINT8_C(132) },
    { UINT8_C(166),
      { SIMDE_FLOAT64_C(   329.40), SIMDE_FLOAT64_C(   -77.15), SIMDE_FLOAT64_C(  -919.44), SIMDE_FLOAT64_C(  -414.39),
        SIMDE_FLOAT64_C(    84.14), SIMDE_FLOAT64_C(  -736.53), SIMDE_FLOAT64_C(   946.55), SIMDE_FLOAT64_C(   573.95) },
      { SIMDE_FLOAT64_C(   581.13), SIMDE_FLOAT64_C(   927.62), SIMDE_FLOAT64_C(  -919.44), SIMDE_FLOAT64_C(  -414.39),
        SIMDE_FLOAT64_C(  -815.66), SIMDE_FLOAT64_C(  -246.09), SIMDE_FLOAT64_C(   946.55), SIMDE_FLOAT64_C(  -453.79) },
      UINT8_C(  4) },
    { UINT8_C(210),
      { SIMDE_FLOAT64_C(  -254.67), SIMDE_FLOAT64_C(   559.95), SIMDE_FLOAT64_C(  -458.98), SIMDE_FLOAT64_C(   767.03),
        SIMDE_FLOAT64_C(   885.21), SIMDE_FLOAT64_C(   210.93), SIMDE_FLOAT64_C(   363.91), SIMDE_FLOAT64_C(   799.55) },
      { SIMDE_FLOAT64_C(  -461.57), SIMDE_FLOAT64_C(   559.95), SIMDE_FLOAT64_C(  -458.98), SIMDE_FLOAT64_C(   767.03),
        SIMDE_FLOAT64_C(   885.21), SIMDE_FLOAT64_C(   611.56), SIMDE_FLOAT64_C(   363.91), SIMDE_FLOAT64_C(  -809.48) },
      UINT8_C( 82) },
    { UINT8_C(219),
      { SIMDE_FLOAT64_C(  -546.02), SIMDE_FLOAT64_C(  -856.27), SIMDE_FLOAT64_C(   -65.64), SIMDE_FLOAT64_C(  -964.89),
        SIMDE_FLOAT64_C(  -928.65), SIMDE_FLOAT64_C(   875.16), SIMDE_FLOAT64_C(   -19.37), SIMDE_FLOAT64_C(  -744.31) },
      { SIMDE_FLOAT64_C(  -370.93), SIMDE_FLOAT64_C(   381.07), SIMDE_FLOAT64_C(  -198.10), SIMDE_FLOAT64_C(  -964.89),
        SIMDE_FLOAT64_C(  -534.76), SIMDE_FLOAT64_C(   547.24), SIMDE_FLOAT64_C(   -19.37), SIMDE_FLOAT64_C(  -744.31) },
      UINT8_C(200) },
    { UINT8_C( 37),
      { SIMDE_FLOAT64_C(  -782.80), SIMDE_FLOAT64_C(  -321.82), SIMDE_FLOAT64_C(   657.82), SIMDE_FLOAT64_C(  -244.37),
        SIMDE_FLOAT64_C(   782.45), SIMDE_FLOAT64_C(   939.98), SIMDE_FLOAT64_C(  -890.94), SIMDE_FLOAT64_C(   892.41) },
      { SIMDE_FLOAT64_C(   551.55), SIMDE_FLOAT64_C(  -614.67), SIMDE_FLOAT64_C(  -917.08), SIMDE_FLOAT64_C(  -244.37),
        SIMDE_FLOAT64_C(   745.74), SIMDE_FLOAT64_C(  -463.09), SIMDE_FLOAT64_C(   892.45), SIMDE_FLOAT64_C(  -319.90) },
      UINT8_C(  0) },
    { UINT8_C(181),
      { SIMDE_FLOAT64_C(  -444.74), SIMDE_FLOAT64_C(   552.65), SIMDE_FLOAT64_C(  -780.51), SIMDE_FLOAT64_C(   184.33),
        SIMDE_FLOAT64_C(   -66.29), SIMDE_FLOAT64_C(    21.39), SIMDE_FLOAT64_C(   597.43), SIMDE_FLOAT64_C(   398.96) },
      { SIMDE_FLOAT64_C(  -431.38), SIMDE_FLOAT64_C(   570.49), SIMDE_FLOAT64_C(  -594.78), SIMDE_FLOAT64_C(   882.89),
        SIMDE_FLOAT64_C(   -66.29), SIMDE_FLOAT64_C(  -377.58), SIMDE_FLOAT64_C(  -438.93), SIMDE_FLOAT64_C(    86.57) },
      UINT8_C( 16) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512d a = simde_mm512_loadu_pd(test_vec[i].a);
    simde__m512d b = simde_mm512_loadu_pd(test_vec[i].b);
    simde__mmask8 r = simde_mm512_mask_cmpeq_pd_mask(test_vec[i].k1, a, b);
    simde_assert_equal_mmask8(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k1 = simde_test_x86_random_mmask8();
    simde__m512d a = simde_test_x86_random_f64x8(-1000.0, 1000.0);
    simde__m512d b = simde_mm512_mask_blend_pd(simde_test_x86_random_mmask8(), a, simde_test_x86_random_f64x8(-1000.0, 1000.0));
    simde__mmask8 r = simde_mm512_mask_cmpeq_pd_mask(k1, a, b);

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
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_cmpeq_epi8_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_mask_cmpeq_epi8_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_cmpeq_epi8_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_mask_cmpeq_epi8_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_cmpeq_epi8_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_cmpeq_epi8_mask)

  SIMDE_TEST_FUNC_LIST_ENTRY(mm_cmpeq_epi16_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_mask_cmpeq_epi16_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_cmpeq_epi16_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_mask_cmpeq_epi16_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_cmpeq_epi16_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_cmpeq_epi16_mask)

  SIMDE_TEST_FUNC_LIST_ENTRY(mm_cmpeq_epi32_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_mask_cmpeq_epi32_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_cmpeq_epi32_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_mask_cmpeq_epi32_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_cmpeq_epi32_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_cmpeq_epi32_mask)

  SIMDE_TEST_FUNC_LIST_ENTRY(mm_cmpeq_epi64_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_mask_cmpeq_epi64_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_cmpeq_epi64_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_mask_cmpeq_epi64_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_cmpeq_epi64_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_cmpeq_epi64_mask)

  SIMDE_TEST_FUNC_LIST_ENTRY(mm_cmpeq_epu8_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_mask_cmpeq_epu8_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_cmpeq_epu8_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_mask_cmpeq_epu8_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_cmpeq_epu8_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_cmpeq_epu8_mask)

  SIMDE_TEST_FUNC_LIST_ENTRY(mm_cmpeq_epu16_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_mask_cmpeq_epu16_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_cmpeq_epu16_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_mask_cmpeq_epu16_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_cmpeq_epu16_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_cmpeq_epu16_mask)

  SIMDE_TEST_FUNC_LIST_ENTRY(mm_cmpeq_epu32_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_mask_cmpeq_epu32_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_cmpeq_epu32_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_mask_cmpeq_epu32_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_cmpeq_epu32_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_cmpeq_epu32_mask)

  SIMDE_TEST_FUNC_LIST_ENTRY(mm_cmpeq_epu64_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_mask_cmpeq_epu64_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_cmpeq_epu64_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_mask_cmpeq_epu64_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_cmpeq_epu64_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_cmpeq_epu64_mask)

  #if !defined(SIMDE_BUG_GCC_96174)
    SIMDE_TEST_FUNC_LIST_ENTRY(mm512_cmpeq_ps_mask)
    SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_cmpeq_ps_mask)
    SIMDE_TEST_FUNC_LIST_ENTRY(mm512_cmpeq_pd_mask)
    SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_cmpeq_pd_mask)
  #endif
SIMDE_TEST_FUNC_LIST_END

#include <test/x86/avx512/test-avx512-footer.h>
