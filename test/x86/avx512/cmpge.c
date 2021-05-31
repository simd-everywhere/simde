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

#include "test/test.h"
#define SIMDE_TEST_X86_AVX512_INSN cmpge

#include <test/x86/avx512/test-avx512.h>
#include <simde/x86/avx512/set.h>
#include <simde/x86/avx512/cmpge.h>

static int
test_simde_x_mm_cmpge_epi8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int8_t a[16];
    const int8_t b[16];
    const int8_t r[16];
  } test_vec[] = {
    { { -INT8_C(  17),  INT8_C(  13),  INT8_C( 107),  INT8_C( 117), -INT8_C(  12),  INT8_C( 113), -INT8_C(  34),  INT8_C(  28),
         INT8_C(   3), -INT8_C( 123), -INT8_C(  35), -INT8_C(  44),  INT8_C(  43), -INT8_C( 111),      INT8_MAX,  INT8_C(   1) },
      { -INT8_C(  17),  INT8_C(  13),  INT8_C(  16),  INT8_C( 117), -INT8_C(  32), -INT8_C( 103), -INT8_C(  63),  INT8_C(  28),
         INT8_C(   3), -INT8_C( 127), -INT8_C(  35),  INT8_C( 121),  INT8_C(   1),  INT8_C(  75),      INT8_MAX, -INT8_C(  16) },
      { -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
        -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1) } },
    { { -INT8_C( 103),  INT8_C(   5),  INT8_C(  19),  INT8_C( 122), -INT8_C(  98), -INT8_C(  44), -INT8_C(  59), -INT8_C(  35),
         INT8_C(  85),  INT8_C(  80),  INT8_C(  87),  INT8_C(  86), -INT8_C( 101),  INT8_C( 123),  INT8_C(  70), -INT8_C(  13) },
      { -INT8_C( 103), -INT8_C(  85),  INT8_C(  19),  INT8_C(  12), -INT8_C(  18), -INT8_C(  87),  INT8_C(  16), -INT8_C(  73),
        -INT8_C(  17), -INT8_C(  23), -INT8_C(  86), -INT8_C(  58),  INT8_C(  64), -INT8_C(  97), -INT8_C( 108), -INT8_C(  38) },
      { -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
        -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1) } },
    { {  INT8_C(  25),  INT8_C(  57),  INT8_C(  10),  INT8_C(   8), -INT8_C(  30),  INT8_C(  26), -INT8_C(  65), -INT8_C(  47),
         INT8_C(   3),  INT8_C( 105), -INT8_C( 105),  INT8_C(  68),  INT8_C(   8),  INT8_C(  44),  INT8_C(  30), -INT8_C(  84) },
      { -INT8_C(  45),  INT8_C( 114), -INT8_C(  18),  INT8_C(  79), -INT8_C(  30),  INT8_C(  14), -INT8_C(  65), -INT8_C(  47),
        -INT8_C( 124),  INT8_C(  71), -INT8_C( 105),  INT8_C(  68), -INT8_C(  75), -INT8_C(  12),  INT8_C(  30), -INT8_C(  49) },
      { -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
        -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0) } },
    { {  INT8_C( 112), -INT8_C(  93), -INT8_C(  58), -INT8_C(   5), -INT8_C(  79), -INT8_C(  26), -INT8_C(  15),  INT8_C(  53),
         INT8_C(  45), -INT8_C(  20), -INT8_C(  84), -INT8_C(  29), -INT8_C(  32),  INT8_C(  32), -INT8_C(  78),  INT8_C(  13) },
      { -INT8_C(  98), -INT8_C(  93), -INT8_C(  58),  INT8_C(  54),  INT8_C(  31), -INT8_C(   4), -INT8_C(  15),  INT8_C(  30),
         INT8_C( 115), -INT8_C(  20),  INT8_C(  38),  INT8_C(  23), -INT8_C(  32),  INT8_C(  32), -INT8_C( 114),  INT8_C(  32) },
      { -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
         INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0) } },
    { { -INT8_C( 123),  INT8_C(   2),  INT8_C(   5), -INT8_C(  92), -INT8_C(   2), -INT8_C(  41), -INT8_C(  61),  INT8_C( 113),
        -INT8_C( 118), -INT8_C(  23), -INT8_C( 120),  INT8_C(  58), -INT8_C(  60),  INT8_C(  22),  INT8_C(  91),  INT8_C(  66) },
      {  INT8_C( 106),  INT8_C( 119),  INT8_C( 113), -INT8_C(  92), -INT8_C( 124), -INT8_C(  41),  INT8_C(  12),  INT8_C( 113),
        -INT8_C(  26),  INT8_C(  86),  INT8_C(  86),  INT8_C(  23), -INT8_C(  60),  INT8_C(  60),  INT8_C(  91), -INT8_C(  40) },
      {  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
         INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1) } },
    { {  INT8_C(  88), -INT8_C(  94),  INT8_C(  91), -INT8_C(  36),  INT8_C( 120),  INT8_C( 103),  INT8_C(  89),  INT8_C(  94),
        -INT8_C(  66), -INT8_C(  81),  INT8_C( 117),  INT8_C(  17), -INT8_C(  21),  INT8_C(  91), -INT8_C(  23),  INT8_C(  41) },
      {  INT8_C(  88), -INT8_C(  94),  INT8_C(  91), -INT8_C(  36), -INT8_C(  90),  INT8_C(  19),  INT8_C(  83), -INT8_C(  48),
         INT8_C(  73), -INT8_C(  81), -INT8_C(  66), -INT8_C( 107), -INT8_C(  69),  INT8_C(  91),  INT8_C(  76),  INT8_C(  20) },
      { -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
         INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1) } },
    { {  INT8_C(  46),  INT8_C( 116), -INT8_C( 124), -INT8_C(  43), -INT8_C( 121), -INT8_C(  40), -INT8_C(  91), -INT8_C(  48),
        -INT8_C(  78),  INT8_C(  99),  INT8_C( 101),  INT8_C( 109),  INT8_C(  81), -INT8_C(  78), -INT8_C( 127), -INT8_C(  30) },
      {  INT8_C(  90),  INT8_C( 114), -INT8_C(  22), -INT8_C(  43), -INT8_C(  68),  INT8_C(  81), -INT8_C(  91), -INT8_C(  75),
         INT8_C(  46),  INT8_C(  21), -INT8_C( 102),  INT8_C( 101), -INT8_C(  35), -INT8_C(  78), -INT8_C( 127),  INT8_C(  12) },
      {  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
         INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0) } },
    { {  INT8_C(  82),  INT8_C(   7),  INT8_C(  79),  INT8_C(  14),  INT8_C(  88), -INT8_C( 122), -INT8_C(  61), -INT8_C( 122),
        -INT8_C( 101),  INT8_C(  94), -INT8_C(  20),  INT8_C( 121),  INT8_C(   7), -INT8_C(  50), -INT8_C( 123),  INT8_C(  36) },
      {  INT8_C(  53),  INT8_C( 102),  INT8_C(  79),  INT8_C( 116), -INT8_C(  20),  INT8_C(  60),  INT8_C( 101), -INT8_C(  43),
         INT8_C(  21), -INT8_C(  60), -INT8_C(  20),  INT8_C( 121),  INT8_C(   7),  INT8_C(  44), -INT8_C( 123), -INT8_C(  10) },
      { -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
         INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_x_mm_loadu_epi8(test_vec[i].a);
    simde__m128i b = simde_x_mm_loadu_epi8(test_vec[i].b);
    simde__m128i r = simde_x_mm_cmpge_epi8(a, b);
    simde_test_x86_assert_equal_i8x16(r, simde_x_mm_loadu_epi8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    int8_t a_[16];
    int8_t b_[16];

    simde_test_codegen_random_memory(sizeof(a_), HEDLEY_REINTERPRET_CAST(uint8_t*, a_));
    simde_test_codegen_random_memory(sizeof(b_), HEDLEY_REINTERPRET_CAST(uint8_t*, b_));
    for (size_t j = 0 ; j < (sizeof(a_) / sizeof(a_[0])) ; j++)
      if ((simde_test_codegen_rand() & 3) == 0)
        b_[j] = a_[j];

    simde__m128i a = simde_mm_loadu_epi8(a_);
    simde__m128i b = simde_mm_loadu_epi8(b_);
    simde__m128i r = simde_x_mm_cmpge_epi8(a, b);

    simde_test_x86_write_i8x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i8x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i8x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_cmpge_epi8_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int8_t a[16];
    const int8_t b[16];
    const simde__mmask16 r;
  } test_vec[] = {
    { {  INT8_C(  37), -INT8_C( 113),  INT8_C(  14),  INT8_C(  48), -INT8_C(  82), -INT8_C( 103), -INT8_C(  58),  INT8_C( 100),
        -INT8_C(  10), -INT8_C(  79), -INT8_C(  56),      INT8_MAX, -INT8_C(  96),  INT8_C(  64), -INT8_C(   4), -INT8_C(  13) },
      { -INT8_C(   6),  INT8_C(  23), -INT8_C(  91),  INT8_C(  69), -INT8_C(  82),  INT8_C(  66), -INT8_C(  36),  INT8_C(  60),
        -INT8_C(  88), -INT8_C(  52),  INT8_C(  67),  INT8_C(  98), -INT8_C(  26), -INT8_C(  73),  INT8_C( 113),  INT8_C(  11) },
      UINT16_C(10645) },
    { { -INT8_C(  95), -INT8_C(  20), -INT8_C(  95), -INT8_C(  53),  INT8_C(  46),  INT8_C( 125),  INT8_C(   8), -INT8_C(  42),
         INT8_C(  74),  INT8_C(  75),  INT8_C(  56),  INT8_C(  48),  INT8_C(   2), -INT8_C(  86),  INT8_C(  59),  INT8_C(  73) },
      {  INT8_C(  41),  INT8_C( 118),  INT8_C(  62), -INT8_C(  53),  INT8_C( 120), -INT8_C( 105),  INT8_C(  81),  INT8_C(  43),
        -INT8_C(  72), -INT8_C(  33),      INT8_MAX,  INT8_C(  25),  INT8_C( 105), -INT8_C(  86),  INT8_C(  59),  INT8_C(  10) },
      UINT16_C(60200) },
    { { -INT8_C(  65), -INT8_C(  78),  INT8_C(   4),  INT8_C(  55),  INT8_C(  73),  INT8_C(  85),  INT8_C(  99),  INT8_C(   1),
         INT8_C(  52), -INT8_C(  30),  INT8_C(  27), -INT8_C(  99), -INT8_C(  89), -INT8_C( 112), -INT8_C(  88),  INT8_C(  89) },
      { -INT8_C(  90),  INT8_C( 126),  INT8_C(  57),  INT8_C(  57),  INT8_C(  73), -INT8_C(  17),  INT8_C(  23),  INT8_C(   1),
         INT8_C(  52),  INT8_C(  36), -INT8_C(  80), -INT8_C(  99),  INT8_C( 109),  INT8_C(  37),  INT8_C(  58),  INT8_C(  44) },
      UINT16_C(36337) },
    { { -INT8_C( 116), -INT8_C(  30), -INT8_C(  83), -INT8_C(  24), -INT8_C(  47), -INT8_C(  60),  INT8_C( 109), -INT8_C(  80),
        -INT8_C(  24),  INT8_C(  29),  INT8_C(  39),  INT8_C(  85),  INT8_C(  66),  INT8_C(  97), -INT8_C( 127),  INT8_C(  26) },
      { -INT8_C(  96), -INT8_C(  27), -INT8_C(  83), -INT8_C(  24), -INT8_C(  85),  INT8_C(  93),  INT8_C( 109),  INT8_C(  84),
        -INT8_C( 101),  INT8_C(  29), -INT8_C(  92),  INT8_C( 104),  INT8_C( 112),  INT8_C(  97), -INT8_C(  36), -INT8_C(   4) },
      UINT16_C(42844) },
    { { -INT8_C(  15),  INT8_C(   6),  INT8_C(  13), -INT8_C(  99),  INT8_C( 100),  INT8_C(  10), -INT8_C(  15), -INT8_C(   1),
         INT8_C( 108), -INT8_C( 107),  INT8_C( 103), -INT8_C(  35), -INT8_C(  30),  INT8_C(  67), -INT8_C(  39),  INT8_C(  17) },
      { -INT8_C(  52), -INT8_C(  66),  INT8_C(  17),  INT8_C(  25),  INT8_C( 100), -INT8_C(  62),  INT8_C(  79),  INT8_C( 126),
        -INT8_C( 102), -INT8_C( 107),  INT8_C(  48), -INT8_C(  45), -INT8_C(  30), -INT8_C(   5), -INT8_C(  83),  INT8_C(  17) },
      UINT16_C(65331) },
    { { -INT8_C(  91), -INT8_C(   1), -INT8_C(  10), -INT8_C(  75), -INT8_C(  63),  INT8_C(  69),  INT8_C(  51),  INT8_C(  91),
         INT8_C(  31),  INT8_C(  99),  INT8_C(  47),  INT8_C(   5),  INT8_C(  95), -INT8_C(  36), -INT8_C(  35),  INT8_C(  97) },
      { -INT8_C( 106),  INT8_C(  82), -INT8_C(  10),  INT8_C(  91), -INT8_C(  63),  INT8_C(  44), -INT8_C( 116), -INT8_C(  77),
        -INT8_C(   8), -INT8_C( 102),  INT8_C(  47),  INT8_C(   8), -INT8_C( 127),  INT8_C( 126), -INT8_C(  27),  INT8_C(  97) },
      UINT16_C(38901) },
    { {  INT8_C( 116), -INT8_C(   6), -INT8_C( 105),  INT8_C(  45),  INT8_C(  38),  INT8_C(  35), -INT8_C(  32),  INT8_C(  30),
        -INT8_C(  67),  INT8_C( 113),  INT8_C(  39),  INT8_C(  63), -INT8_C(  17),  INT8_C(  12),  INT8_C( 102),  INT8_C( 109) },
      { -INT8_C(  25), -INT8_C(   6), -INT8_C(  83),  INT8_C(   7),  INT8_C(  81),  INT8_C(  72), -INT8_C(  32), -INT8_C(  60),
         INT8_C(  18), -INT8_C( 118),  INT8_C(  39), -INT8_C(  72), -INT8_C(  84), -INT8_C(  55),  INT8_C( 102),  INT8_C(  33) },
      UINT16_C(65227) },
    { {  INT8_C(  84), -INT8_C(  87),  INT8_C(  41), -INT8_C(  91), -INT8_C(  15),  INT8_C( 111),  INT8_C( 106),  INT8_C(   3),
        -INT8_C(   7),  INT8_C(   0), -INT8_C(  69), -INT8_C(  90), -INT8_C(  54), -INT8_C(  80), -INT8_C(  57), -INT8_C( 115) },
      {  INT8_C(  84), -INT8_C(  87),  INT8_C(  41), -INT8_C(  21),  INT8_C(  67),      INT8_MAX,  INT8_C(  88),  INT8_C(   3),
        -INT8_C(  82),  INT8_C(   0),  INT8_C( 114), -INT8_C(  90), -INT8_C(  54),  INT8_C( 110),  INT8_C(  11), -INT8_C( 115) },
      UINT16_C(39879) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_x_mm_loadu_epi8(test_vec[i].a);
    simde__m128i b = simde_x_mm_loadu_epi8(test_vec[i].b);
    simde__mmask16 r = simde_mm_cmpge_epi8_mask(a, b);
    simde_assert_equal_mmask16(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    int8_t a_[16];
    int8_t b_[16];

    simde_test_codegen_random_memory(sizeof(a_), HEDLEY_REINTERPRET_CAST(uint8_t*, a_));
    simde_test_codegen_random_memory(sizeof(b_), HEDLEY_REINTERPRET_CAST(uint8_t*, b_));
    for (size_t j = 0 ; j < (sizeof(a_) / sizeof(a_[0])) ; j++)
      if ((simde_test_codegen_rand() & 3) == 0)
        b_[j] = a_[j];

    simde__m128i a = simde_mm_loadu_epi8(a_);
    simde__m128i b = simde_mm_loadu_epi8(b_);
    simde__mmask16 r = simde_mm_cmpge_epi8_mask(a, b);

    simde_test_x86_write_i8x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i8x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_mask_cmpge_epi8_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask16 k;
    const int8_t a[16];
    const int8_t b[16];
    const simde__mmask16 r;
  } test_vec[] = {
    { UINT16_C( 1862),
      { -INT8_C( 105), -INT8_C(  74), -INT8_C(  96),  INT8_C( 108), -INT8_C(  98),  INT8_C( 103),  INT8_C(  53),  INT8_C(  26),
         INT8_C(  16),  INT8_C(  59),  INT8_C( 101), -INT8_C(  91), -INT8_C(  55), -INT8_C(  51),  INT8_C( 113),  INT8_C(  36) },
      {  INT8_C(  49), -INT8_C(  74), -INT8_C(  96), -INT8_C(  61), -INT8_C(  46),  INT8_C(  26),  INT8_C(  77), -INT8_C( 105),
             INT8_MAX, -INT8_C(  50), -INT8_C(  33), -INT8_C(  97),  INT8_C(  92), -INT8_C( 101),  INT8_C(  64), -INT8_C(  12) },
      UINT16_C( 1542) },
    { UINT16_C(22349),
      {  INT8_C(  48),  INT8_C(  24),  INT8_C(  33),  INT8_C( 125), -INT8_C(  81), -INT8_C(  96),  INT8_C(  76), -INT8_C( 114),
         INT8_C(  63), -INT8_C(  88),  INT8_C(  41),      INT8_MAX, -INT8_C( 100),  INT8_C( 122),  INT8_C(  96), -INT8_C(   3) },
      {  INT8_C(  48), -INT8_C(  89), -INT8_C( 109),  INT8_C( 114), -INT8_C(   1),  INT8_C( 100), -INT8_C(  32), -INT8_C(   4),
        -INT8_C(   1),  INT8_C(  28),  INT8_C( 106), -INT8_C(  67), -INT8_C( 119), -INT8_C(  80),  INT8_C(  96), -INT8_C(  71) },
      UINT16_C(20813) },
    { UINT16_C(18052),
      { -INT8_C( 123),  INT8_C(  76), -INT8_C(  68),  INT8_C( 102),  INT8_C(  72), -INT8_C(  69), -INT8_C( 126), -INT8_C(  78),
         INT8_C( 120),  INT8_C(  11),  INT8_C(  98),  INT8_C(  61), -INT8_C(  60),  INT8_C(  42),  INT8_C(  35), -INT8_C(   6) },
      { -INT8_C(  95), -INT8_C(  87),  INT8_C( 125), -INT8_C(  90),  INT8_C( 111), -INT8_C(  88), -INT8_C(  43), -INT8_C(  75),
         INT8_C( 111),      INT8_MAX,  INT8_C(  98),  INT8_C(  52), -INT8_C( 110), -INT8_C(  89), -INT8_C( 117),  INT8_C(  23) },
      UINT16_C(17408) },
    { UINT16_C(63465),
      { -INT8_C(  63), -INT8_C(  12), -INT8_C(  18), -INT8_C( 106), -INT8_C(  87),  INT8_C(  93),  INT8_C(  21),  INT8_C(   3),
        -INT8_C( 111), -INT8_C(  89), -INT8_C(  85),  INT8_C(  29), -INT8_C(  65), -INT8_C(  98),  INT8_C( 100),  INT8_C(  60) },
      { -INT8_C(  38),  INT8_C( 103),  INT8_C(  60), -INT8_C(  57), -INT8_C(  30),  INT8_C(  93),  INT8_C(  23), -INT8_C( 102),
         INT8_C(  21), -INT8_C( 112),  INT8_C( 117), -INT8_C(  34), -INT8_C(  85), -INT8_C(   7),  INT8_C(  36),  INT8_C( 108) },
      UINT16_C(21152) },
    { UINT16_C(58527),
      { -INT8_C( 123), -INT8_C(  53),  INT8_C(  61), -INT8_C( 100),  INT8_C( 101),  INT8_C(  82),  INT8_C(  44), -INT8_C(  38),
         INT8_C(  48), -INT8_C(  41), -INT8_C(  44),  INT8_C(  84),  INT8_C(  67), -INT8_C(  63),  INT8_C( 102),  INT8_C(  70) },
      { -INT8_C( 123), -INT8_C(  42),  INT8_C(  94), -INT8_C(  14), -INT8_C(  41),  INT8_C(  29),  INT8_C(  44), -INT8_C(  11),
        -INT8_C( 100), -INT8_C(  41),  INT8_C( 119),  INT8_C(  84), -INT8_C(  40),  INT8_C(  97),  INT8_C(  78),  INT8_C(  93) },
      UINT16_C(16401) },
    { UINT16_C(31980),
      {  INT8_C(  76),  INT8_C( 118),  INT8_C(   2), -INT8_C( 125),  INT8_C( 107), -INT8_C(  98), -INT8_C(  99), -INT8_C(  29),
        -INT8_C(  11),  INT8_C( 117),  INT8_C(  68),  INT8_C(  67), -INT8_C(  46),  INT8_C( 112), -INT8_C(  50), -INT8_C(  53) },
      {  INT8_C(   2), -INT8_C(  84), -INT8_C(  15),  INT8_C( 111), -INT8_C(  69), -INT8_C(  98), -INT8_C(  99),  INT8_C(  30),
         INT8_C(  46),  INT8_C( 117), -INT8_C(  25),  INT8_C(  67), -INT8_C(  46),  INT8_C( 112), -INT8_C( 103),  INT8_C(  87) },
      UINT16_C(31844) },
    { UINT16_C(36534),
      {  INT8_C( 114), -INT8_C(  89),  INT8_C( 106),  INT8_C(  33), -INT8_C(  59), -INT8_C( 103), -INT8_C(  45), -INT8_C(  83),
         INT8_C(  78), -INT8_C(  34),  INT8_C(  52), -INT8_C(  25),  INT8_C(  54),  INT8_C(  49), -INT8_C( 125),  INT8_C(  16) },
      {  INT8_C( 114), -INT8_C(  89), -INT8_C( 120), -INT8_C(  26), -INT8_C(  21), -INT8_C( 103),  INT8_C( 118),  INT8_C(  92),
         INT8_C(  54),  INT8_C( 119), -INT8_C( 100), -INT8_C(  63),  INT8_C(  54), -INT8_C( 119),  INT8_C(  62), -INT8_C(  20) },
      UINT16_C(35878) },
    { UINT16_C(62347),
      { -INT8_C( 119), -INT8_C(  95),  INT8_C(   4),  INT8_C(   0), -INT8_C(   2),  INT8_C(  58),  INT8_C( 119), -INT8_C( 102),
        -INT8_C(   5), -INT8_C(  15),  INT8_C(  35),  INT8_C(  57), -INT8_C(  35),  INT8_C(  84), -INT8_C(  30), -INT8_C(  22) },
      { -INT8_C( 119),  INT8_C(  35), -INT8_C(  53), -INT8_C(  19), -INT8_C(   2),  INT8_C(  58),  INT8_C( 119), -INT8_C( 102),
             INT8_MAX, -INT8_C(  15),  INT8_C(  36), -INT8_C( 124), -INT8_C(  35), -INT8_C(  38), -INT8_C(  30), -INT8_C(   7) },
      UINT16_C(29321) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__mmask16 k = test_vec[i].k;
    simde__m128i a = simde_x_mm_loadu_epi8(test_vec[i].a);
    simde__m128i b = simde_x_mm_loadu_epi8(test_vec[i].b);
    simde__mmask16 r = simde_mm_mask_cmpge_epi8_mask(k, a, b);
    simde_assert_equal_mmask16(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    int8_t a_[16];
    int8_t b_[16];

    simde_test_codegen_random_memory(sizeof(a_), HEDLEY_REINTERPRET_CAST(uint8_t*, a_));
    simde_test_codegen_random_memory(sizeof(b_), HEDLEY_REINTERPRET_CAST(uint8_t*, b_));
    for (size_t j = 0 ; j < (sizeof(a_) / sizeof(a_[0])) ; j++)
      if ((simde_test_codegen_rand() & 3) == 0)
        b_[j] = a_[j];

    simde__mmask16 k = simde_test_x86_random_mmask16();
    simde__m128i a = simde_mm_loadu_epi8(a_);
    simde__m128i b = simde_mm_loadu_epi8(b_);
    simde__mmask16 r = simde_mm_mask_cmpge_epi8_mask(k, a, b);

    simde_test_x86_write_mmask16(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i8x16(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i8x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_x_mm256_cmpge_epi8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int8_t a[32];
    const int8_t b[32];
    const int8_t r[32];
  } test_vec[] = {
    { {  INT8_C( 104),  INT8_C( 102), -INT8_C( 108), -INT8_C(  96),  INT8_C(  68),  INT8_C(  26), -INT8_C(  96), -INT8_C(  81),
         INT8_C(  23), -INT8_C( 127), -INT8_C(  17),  INT8_C(  67),  INT8_C(   7), -INT8_C(  43),  INT8_C(  47), -INT8_C(  43),
        -INT8_C(  57), -INT8_C(  67),  INT8_C( 103),  INT8_C( 109), -INT8_C( 127),  INT8_C(   6),  INT8_C( 112), -INT8_C(  68),
        -INT8_C(  79),  INT8_C( 104),  INT8_C(  59),  INT8_C(  49),  INT8_C(  24), -INT8_C(  57), -INT8_C(  52),      INT8_MIN },
      {  INT8_C( 104),  INT8_C(  97),  INT8_C(  32),  INT8_C( 113),  INT8_C( 123), -INT8_C(  64),  INT8_C(  32), -INT8_C( 110),
         INT8_C(  65),  INT8_C(  16), -INT8_C(  43),  INT8_C(  73),  INT8_C(   7), -INT8_C(  43),  INT8_C(  47), -INT8_C(  83),
        -INT8_C(  62), -INT8_C( 123),  INT8_C(  26),  INT8_C(  67), -INT8_C( 127), -INT8_C( 118), -INT8_C(   1),  INT8_C(  61),
        -INT8_C(  79),  INT8_C(  59),  INT8_C(  59),  INT8_C(  10),  INT8_C(   2),  INT8_C(  59), -INT8_C( 118),  INT8_C(  48) },
      { -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
         INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
        -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
        -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0) } },
    { {  INT8_C(  58), -INT8_C( 104), -INT8_C(  63), -INT8_C(  91),  INT8_C(  90),  INT8_C( 107),  INT8_C(  82),  INT8_C(  44),
        -INT8_C(  22),  INT8_C(  72), -INT8_C(  28),  INT8_C( 110),  INT8_C(  92),  INT8_C(  72), -INT8_C(  76), -INT8_C(  10),
        -INT8_C(  57),  INT8_C(  62),  INT8_C(  27), -INT8_C(  49), -INT8_C(  56),  INT8_C( 126), -INT8_C(  54), -INT8_C( 116),
         INT8_C(  80), -INT8_C(  50),  INT8_C(  83),  INT8_C(  94),  INT8_C(  93),  INT8_C(  74),  INT8_C(   8), -INT8_C( 105) },
      {  INT8_C(  58), -INT8_C(  55),  INT8_C(  61),  INT8_C(  61),  INT8_C(  52),  INT8_C( 107),  INT8_C( 106),  INT8_C(  30),
        -INT8_C(  40),  INT8_C(  72), -INT8_C( 116),  INT8_C(  52), -INT8_C( 106),  INT8_C(  65),  INT8_C(  42), -INT8_C(  10),
        -INT8_C(  57),  INT8_C(  70),  INT8_C(  27), -INT8_C(  49), -INT8_C(  60),  INT8_C( 126), -INT8_C(  44), -INT8_C( 116),
        -INT8_C(  59), -INT8_C(  50),  INT8_C( 115),  INT8_C(  35),  INT8_C( 114),  INT8_C( 123), -INT8_C(  70), -INT8_C( 105) },
      { -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
        -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
        -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
        -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1) } },
    { { -INT8_C(   3), -INT8_C( 127), -INT8_C( 119), -INT8_C( 124),  INT8_C( 125),  INT8_C(  32), -INT8_C(  29), -INT8_C(  56),
         INT8_C(  68),  INT8_C( 118), -INT8_C(  87), -INT8_C(  87),  INT8_C(  52), -INT8_C(  25), -INT8_C( 114),  INT8_C(  56),
         INT8_C(  83), -INT8_C(  70),  INT8_C(   1), -INT8_C(  75), -INT8_C(  70), -INT8_C(  34), -INT8_C(  35), -INT8_C(  31),
         INT8_C(  47),  INT8_C(  40),  INT8_C( 123), -INT8_C(   6),  INT8_C(  46),  INT8_C( 105),  INT8_C(  10),  INT8_C(  43) },
      { -INT8_C(   3), -INT8_C( 109), -INT8_C( 119), -INT8_C( 124), -INT8_C(  76),  INT8_C(  32),  INT8_C(  48), -INT8_C(   8),
         INT8_C(   8), -INT8_C(  39), -INT8_C(  94),  INT8_C(  61), -INT8_C(  64), -INT8_C(  25),  INT8_C( 117),  INT8_C(  19),
        -INT8_C(  22),  INT8_C( 118), -INT8_C(  55), -INT8_C(  92),  INT8_C(  85), -INT8_C(  90), -INT8_C( 123), -INT8_C(  31),
        -INT8_C(  49),  INT8_C(   0),  INT8_C( 126), -INT8_C(   3),  INT8_C( 106), -INT8_C( 119),  INT8_C(  40),  INT8_C(  84) },
      { -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
        -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
        -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
        -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0) } },
    { { -INT8_C(  44),  INT8_C(  42),  INT8_C( 104),  INT8_C(  61),  INT8_C(  22),  INT8_C(  49), -INT8_C(  82), -INT8_C(  36),
        -INT8_C( 100),  INT8_C(  93),  INT8_C(  98),  INT8_C(  55), -INT8_C( 127), -INT8_C(   5), -INT8_C(  68),  INT8_C(  27),
         INT8_C(  94), -INT8_C(  27),  INT8_C(  11),  INT8_C( 103), -INT8_C( 109),  INT8_C( 126),  INT8_C(  63),  INT8_C(  66),
         INT8_C( 112),  INT8_C(  20),  INT8_C(  91), -INT8_C(  21),  INT8_C(  17), -INT8_C(  55), -INT8_C( 125), -INT8_C(  27) },
      { -INT8_C(  13), -INT8_C(  21),  INT8_C(  34),  INT8_C(   9),  INT8_C(  28),  INT8_C(  49), -INT8_C(  27), -INT8_C(  72),
        -INT8_C( 100),  INT8_C(  93), -INT8_C(  17), -INT8_C(  82),  INT8_C(  67), -INT8_C(  85), -INT8_C(  68), -INT8_C(  95),
        -INT8_C( 112), -INT8_C(  27),  INT8_C(   8),  INT8_C(  35),  INT8_C(  83),  INT8_C(  71),  INT8_C( 102), -INT8_C(  60),
         INT8_C(  91), -INT8_C(  63), -INT8_C(  81),  INT8_C( 108),  INT8_C(  17),  INT8_C(  50),  INT8_C(  81),  INT8_C( 125) },
      {  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
        -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
        -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
        -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0) } },
    { {  INT8_C( 114), -INT8_C(  11),  INT8_C(  15), -INT8_C(  75),  INT8_C(  98),  INT8_C(   0),  INT8_C(  38),  INT8_C(  22),
        -INT8_C(  31),  INT8_C(  70),  INT8_C(  13),  INT8_C( 108),  INT8_C(  47), -INT8_C(  91), -INT8_C( 120), -INT8_C(  18),
         INT8_C(  69), -INT8_C(  57),  INT8_C(   0),  INT8_C(  44),  INT8_C( 108), -INT8_C(  42),  INT8_C( 110), -INT8_C(  46),
         INT8_C(  91),  INT8_C(  28), -INT8_C(  61),  INT8_C(  19),  INT8_C(  27),  INT8_C(  50), -INT8_C(  23), -INT8_C( 115) },
      {  INT8_C(  39), -INT8_C(   8),  INT8_C(  66), -INT8_C( 119),  INT8_C(  98),  INT8_C( 105),  INT8_C(  38), -INT8_C(  39),
        -INT8_C(  81), -INT8_C(  84),  INT8_C(  70), -INT8_C(  34),  INT8_C(  47), -INT8_C(  50), -INT8_C(  52), -INT8_C( 106),
        -INT8_C( 107), -INT8_C(  57), -INT8_C(  62),  INT8_C(   1), -INT8_C(  94),  INT8_C(  48), -INT8_C(  45), -INT8_C(   2),
         INT8_C(  76),  INT8_C(  28),  INT8_C(  17),  INT8_C( 103), -INT8_C(  55), -INT8_C(   6), -INT8_C(  12), -INT8_C(  16) },
      { -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
        -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
        -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
        -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0) } },
    { {      INT8_MIN,  INT8_C(  12),  INT8_C(  80),  INT8_C(  32),  INT8_C(  38),  INT8_C(  21),  INT8_C( 111), -INT8_C(  20),
         INT8_C(  31), -INT8_C(  99),  INT8_C(   3), -INT8_C(   8), -INT8_C( 105), -INT8_C(  79),  INT8_C( 101),  INT8_C(  93),
         INT8_C(  34), -INT8_C(  44), -INT8_C(  58), -INT8_C(  61),  INT8_C(  22),  INT8_C(  45), -INT8_C(  80), -INT8_C(  17),
        -INT8_C(  90),  INT8_C(   5), -INT8_C( 111),  INT8_C(  25),  INT8_C(  79),  INT8_C(  35),  INT8_C( 126), -INT8_C(  49) },
      {  INT8_C(  48),  INT8_C(  12),  INT8_C(  80),  INT8_C(  86),  INT8_C(  38),  INT8_C(  95),  INT8_C(  66), -INT8_C(  20),
         INT8_C(  31), -INT8_C(  99),  INT8_C(   3), -INT8_C( 109), -INT8_C(   9),  INT8_C(  97),  INT8_C( 101),  INT8_C(  25),
         INT8_C(  34), -INT8_C(  44), -INT8_C(  36),  INT8_C(  75),  INT8_C(  22), -INT8_C( 116), -INT8_C(  80), -INT8_C( 117),
        -INT8_C( 110),  INT8_C(   5), -INT8_C(  92), -INT8_C(  31), -INT8_C(  18),  INT8_C(  35), -INT8_C(  80), -INT8_C(  49) },
      {  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
        -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
        -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
        -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1) } },
    { {  INT8_C(  56),  INT8_C(  60),  INT8_C(  54),  INT8_C(  56), -INT8_C(  14),  INT8_C(  15),  INT8_C(  53), -INT8_C(  18),
        -INT8_C(  29), -INT8_C(  59), -INT8_C(  31),  INT8_C(  25),  INT8_C(  70), -INT8_C(  19), -INT8_C( 125),  INT8_C( 126),
        -INT8_C(  43),  INT8_C(  57), -INT8_C( 100),  INT8_C(  74),  INT8_C(  40),  INT8_C(  68),  INT8_C(  80), -INT8_C(  29),
        -INT8_C( 111),  INT8_C(  56), -INT8_C( 116),  INT8_C(   0), -INT8_C(  48),  INT8_C(  83),  INT8_C(  96),  INT8_C(   8) },
      {  INT8_C(  56), -INT8_C( 106),  INT8_C(  65), -INT8_C( 126), -INT8_C(  91),  INT8_C( 118),  INT8_C( 112), -INT8_C( 119),
         INT8_C(  59), -INT8_C(  59), -INT8_C(  94), -INT8_C( 127),  INT8_C(  63),  INT8_C(  37), -INT8_C(   1),  INT8_C( 126),
         INT8_C(  94), -INT8_C( 101),  INT8_C(  95), -INT8_C( 121),  INT8_C(  40), -INT8_C(  81),  INT8_C( 106), -INT8_C(  29),
        -INT8_C(  25),  INT8_C(  56),  INT8_C( 113), -INT8_C(  73),  INT8_C(  73), -INT8_C(  47), -INT8_C(  64), -INT8_C(  39) },
      { -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
         INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
         INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
         INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1) } },
    { { -INT8_C(  32),  INT8_C(  33), -INT8_C(  41),  INT8_C(  87), -INT8_C(  20),  INT8_C( 109),  INT8_C(   9),  INT8_C(  10),
        -INT8_C(  90),  INT8_C(  60),  INT8_C( 103),  INT8_C(   4),  INT8_C( 111), -INT8_C(  39), -INT8_C(  64),  INT8_C(  61),
        -INT8_C(  86),  INT8_C(   4), -INT8_C(  21),  INT8_C(  42), -INT8_C(  79),  INT8_C(  10), -INT8_C( 110),  INT8_C(  85),
        -INT8_C( 102), -INT8_C(  78),  INT8_C(  66), -INT8_C(   5), -INT8_C( 111),  INT8_C(   8), -INT8_C(  59),  INT8_C( 114) },
      {  INT8_C(  41), -INT8_C( 100), -INT8_C(  55),  INT8_C(  87), -INT8_C(  20), -INT8_C(  45),  INT8_C(   9),  INT8_C(  10),
         INT8_C(  15), -INT8_C( 122), -INT8_C(  77),  INT8_C(   4),  INT8_C(  95),  INT8_C( 116), -INT8_C(  69),  INT8_C(   9),
        -INT8_C(  86), -INT8_C(  90),  INT8_C(  52),  INT8_C(  41), -INT8_C(  79), -INT8_C(  58),  INT8_C( 126),  INT8_C(  74),
        -INT8_C( 102), -INT8_C(  64),  INT8_C(  70), -INT8_C(   5), -INT8_C( 111),  INT8_C(  11),  INT8_C( 124), -INT8_C(  15) },
      {  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
         INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
        -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
        -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256i a = simde_mm256_loadu_epi8(test_vec[i].a);
    simde__m256i b = simde_mm256_loadu_epi8(test_vec[i].b);
    simde__m256i r = simde_x_mm256_cmpge_epi8(a, b);
    simde_test_x86_assert_equal_i8x32(r, simde_mm256_loadu_epi8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    int8_t a_[32];
    int8_t b_[32];

    simde_test_codegen_random_memory(sizeof(a_), HEDLEY_REINTERPRET_CAST(uint8_t*, a_));
    simde_test_codegen_random_memory(sizeof(b_), HEDLEY_REINTERPRET_CAST(uint8_t*, b_));
    for (size_t j = 0 ; j < (sizeof(a_) / sizeof(a_[0])) ; j++)
      if ((simde_test_codegen_rand() & 3) == 0)
        b_[j] = a_[j];

    simde__m256i a = simde_mm256_loadu_epi8(a_);
    simde__m256i b = simde_mm256_loadu_epi8(b_);
    simde__m256i r = simde_x_mm256_cmpge_epi8(a, b);

    simde_test_x86_write_i8x32(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i8x32(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i8x32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_cmpge_epi8_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int8_t a[32];
    const int8_t b[32];
    const simde__mmask32 r;
  } test_vec[] = {
    { {  INT8_C(  84),  INT8_C(  41), -INT8_C(  84),  INT8_C( 109),  INT8_C(  79),  INT8_C(  12), -INT8_C( 107), -INT8_C(   4),
         INT8_C(  31),  INT8_C(  59),  INT8_C(   9), -INT8_C(  89), -INT8_C(  99),  INT8_C(  31), -INT8_C(  90), -INT8_C(  90),
         INT8_C( 105), -INT8_C(  49),  INT8_C(  95),  INT8_C( 121),  INT8_C( 119),  INT8_C(  98),  INT8_C(   2), -INT8_C(  33),
        -INT8_C(  84), -INT8_C( 107),  INT8_C(  15),  INT8_C(   0), -INT8_C(  92),  INT8_C(  49), -INT8_C(   4), -INT8_C(   7) },
      {  INT8_C(  84),  INT8_C(  41), -INT8_C(  84),  INT8_C( 109), -INT8_C(  76), -INT8_C(   5), -INT8_C(  90), -INT8_C(  45),
         INT8_C(  54), -INT8_C(  81),  INT8_C( 122), -INT8_C(  89), -INT8_C(  50),  INT8_C(  31), -INT8_C(  90),  INT8_C(  55),
        -INT8_C(  16), -INT8_C(  39), -INT8_C(  79),  INT8_C( 121),  INT8_C( 119), -INT8_C(  77),  INT8_C(   2), -INT8_C(  25),
         INT8_C(  73), -INT8_C( 107), -INT8_C(  24), -INT8_C(  19), -INT8_C(  92), -INT8_C(  28), -INT8_C(  26), -INT8_C(   7) },
      UINT32_C(4269632191) },
    { { -INT8_C(  74), -INT8_C( 103),  INT8_C(  96), -INT8_C(   3), -INT8_C(  53),  INT8_C( 115),  INT8_C( 123), -INT8_C(  83),
         INT8_C(   1), -INT8_C(  51),  INT8_C(  94), -INT8_C(  80), -INT8_C( 103),  INT8_C(  70),  INT8_C(  80),  INT8_C(  62),
        -INT8_C(  33),  INT8_C(  87),  INT8_C(  31),  INT8_C(  43), -INT8_C(  92), -INT8_C(  25), -INT8_C(  63),  INT8_C(  72),
        -INT8_C( 105),  INT8_C(  68),  INT8_C( 115),  INT8_C(  43), -INT8_C(  83),      INT8_MIN,  INT8_C(  75),  INT8_C(  99) },
      { -INT8_C(  74), -INT8_C(  85),  INT8_C(  96), -INT8_C(  28), -INT8_C(  53), -INT8_C(  36), -INT8_C( 110),  INT8_C(  32),
        -INT8_C(  86), -INT8_C(  16), -INT8_C(  48), -INT8_C(  80),  INT8_C(  54),  INT8_C(  32), -INT8_C( 126),  INT8_C(  21),
        -INT8_C(  33), -INT8_C(  95),  INT8_C(  64),  INT8_C(  43), -INT8_C( 120),  INT8_C(   1),  INT8_C( 100),  INT8_C(  31),
         INT8_C(  69), -INT8_C(  41),  INT8_C( 115), -INT8_C(  13),  INT8_C(  87), -INT8_C( 107),  INT8_C(  86),  INT8_C( 112) },
      UINT32_C( 245099901) },
    { { -INT8_C(  86),  INT8_C(  89), -INT8_C(  55),  INT8_C(  62),  INT8_C(  64),  INT8_C(  71),  INT8_C( 124),  INT8_C(  22),
        -INT8_C( 106), -INT8_C(   3),  INT8_C(  35),  INT8_C(   6),  INT8_C(   1),  INT8_C(  68), -INT8_C(  19), -INT8_C(  91),
        -INT8_C(  90), -INT8_C(  16), -INT8_C(  46),  INT8_C(  10),  INT8_C(  87),  INT8_C(  29), -INT8_C(  77), -INT8_C( 107),
        -INT8_C(  77),  INT8_C(  79),  INT8_C(  42), -INT8_C(  35),  INT8_C(  65),  INT8_C(  47),  INT8_C(  72), -INT8_C(  21) },
      { -INT8_C( 120),  INT8_C(  17), -INT8_C(  55), -INT8_C(  56),  INT8_C(  88), -INT8_C(  91), -INT8_C(  33),  INT8_C(  22),
        -INT8_C(  93),  INT8_C(   2),  INT8_C(  35), -INT8_C(  92),  INT8_C(  70), -INT8_C(  30), -INT8_C(  19), -INT8_C(  19),
        -INT8_C(  46),  INT8_C(  27), -INT8_C(  46),  INT8_C(  41),  INT8_C(  57), -INT8_C(  86), -INT8_C(  66), -INT8_C(  20),
        -INT8_C(   7), -INT8_C(  24), -INT8_C(  55),  INT8_C(  58),  INT8_C(  23),  INT8_C(  17),  INT8_C(  72), -INT8_C(  97) },
      UINT32_C(4130630895) },
    { { -INT8_C(  58),  INT8_C(   0),  INT8_C(  62), -INT8_C(  69),  INT8_C(  71), -INT8_C(  88),  INT8_C(  83), -INT8_C( 112),
         INT8_C(   7), -INT8_C( 113),  INT8_C(  32),  INT8_C(  72),  INT8_C(  21), -INT8_C( 100),  INT8_C(  91), -INT8_C(  74),
         INT8_C(  16), -INT8_C( 105), -INT8_C( 112),  INT8_C(  45), -INT8_C( 111),  INT8_C(  86),  INT8_C(  68),  INT8_C( 115),
        -INT8_C(  27), -INT8_C( 107),  INT8_C( 108), -INT8_C( 122),  INT8_C(  12),  INT8_C(   5),  INT8_C(  74), -INT8_C(  46) },
      { -INT8_C(  58), -INT8_C( 120), -INT8_C( 114),  INT8_C(  77),  INT8_C(  49), -INT8_C(  31), -INT8_C(  35),  INT8_C(  56),
         INT8_C(   7), -INT8_C(   3), -INT8_C( 127), -INT8_C( 122), -INT8_C( 102), -INT8_C(  36),  INT8_C(  91), -INT8_C(  86),
         INT8_C( 116), -INT8_C(  52), -INT8_C(  41),  INT8_C(   5),  INT8_C(  34),  INT8_C(  27),  INT8_C( 121),  INT8_C(   7),
        -INT8_C(  80), -INT8_C(  27),  INT8_C( 108), -INT8_C(  68), -INT8_C(  22), -INT8_C(  40), -INT8_C( 113), -INT8_C(  16) },
      UINT32_C(1974000983) },
    { {  INT8_C( 104),  INT8_C(  23),      INT8_MAX,  INT8_C( 102),  INT8_C(  49),  INT8_C(  73), -INT8_C(  42),  INT8_C(  73),
        -INT8_C( 108), -INT8_C(  53), -INT8_C(   5), -INT8_C(  69), -INT8_C(   3),  INT8_C(  87),  INT8_C(  87), -INT8_C(   6),
        -INT8_C( 117), -INT8_C(   8),  INT8_C(  26), -INT8_C(  38),  INT8_C(  18),  INT8_C(  65), -INT8_C(  39),  INT8_C(  17),
        -INT8_C(  10), -INT8_C( 107), -INT8_C(   5), -INT8_C( 125), -INT8_C(  32), -INT8_C(  43),  INT8_C( 112),  INT8_C(  72) },
      {  INT8_C( 104), -INT8_C(  17), -INT8_C(  81),  INT8_C( 102),  INT8_C(  56), -INT8_C( 123),  INT8_C( 103),  INT8_C(  73),
        -INT8_C( 108),  INT8_C(  99), -INT8_C( 120),  INT8_C(  77), -INT8_C(   3), -INT8_C(  33),  INT8_C(  87),  INT8_C(  69),
        -INT8_C(  41), -INT8_C(   8),  INT8_C(  26), -INT8_C(  23), -INT8_C(  93), -INT8_C(   7), -INT8_C(   6), -INT8_C( 103),
        -INT8_C(  10), -INT8_C(  10),  INT8_C(  28), -INT8_C( 125), -INT8_C(  32), -INT8_C( 116),  INT8_C( 112),  INT8_C(  72) },
      UINT32_C(4189484463) },
    { { -INT8_C(  44), -INT8_C(  14),  INT8_C(  72), -INT8_C(  64),  INT8_C(  47), -INT8_C(  55), -INT8_C(   4), -INT8_C(  48),
        -INT8_C(  46), -INT8_C( 123),  INT8_C(  43), -INT8_C(  70),  INT8_C(  87), -INT8_C(  53),  INT8_C( 121), -INT8_C( 118),
        -INT8_C( 117),  INT8_C(  33),  INT8_C(  97),  INT8_C(  68), -INT8_C(  60), -INT8_C(  48), -INT8_C( 116),  INT8_C(  92),
         INT8_C(  92),  INT8_C(  66), -INT8_C(  64),  INT8_C( 116), -INT8_C(  80), -INT8_C(  36),  INT8_C(   8), -INT8_C( 123) },
      { -INT8_C(  50),  INT8_C(  80),  INT8_C(  72), -INT8_C(  64),  INT8_C(  26),  INT8_C(  65), -INT8_C(   4), -INT8_C(  20),
        -INT8_C(  58), -INT8_C(   7), -INT8_C(  89),  INT8_C(  29),  INT8_C(  87),  INT8_C(  32), -INT8_C(  88),  INT8_C(  80),
         INT8_C(  66),  INT8_C(  33),  INT8_C(  97),  INT8_C(   6), -INT8_C(  60),  INT8_C(  32),  INT8_C(  98),  INT8_C(  53),
         INT8_C(  99),  INT8_C(  66), -INT8_C(  87),  INT8_C(  19), -INT8_C(   1), -INT8_C(  79), -INT8_C( 104), -INT8_C(  50) },
      UINT32_C(1855870301) },
    { {  INT8_C(  73),  INT8_C(  55),  INT8_C(  59),  INT8_C( 103), -INT8_C(  47),  INT8_C(  68),  INT8_C(  76),  INT8_C( 100),
        -INT8_C(  13),  INT8_C(  79), -INT8_C(  69), -INT8_C(  61), -INT8_C(   7),  INT8_C(  99), -INT8_C(  43), -INT8_C(  83),
        -INT8_C(  97), -INT8_C(  19),  INT8_C(  58), -INT8_C(   5),  INT8_C( 104), -INT8_C(   4), -INT8_C(  69),  INT8_C(   5),
         INT8_C( 104), -INT8_C( 114), -INT8_C(  94), -INT8_C( 122), -INT8_C(   7),  INT8_C(  13), -INT8_C(  91),  INT8_C(  66) },
      {  INT8_C(  68), -INT8_C(  31), -INT8_C(  86),  INT8_C( 103), -INT8_C(  47),  INT8_C(  68),  INT8_C( 121),  INT8_C(  24),
         INT8_C(  69),  INT8_C(  53), -INT8_C(  69),  INT8_C(  63), -INT8_C( 104),  INT8_C(  99), -INT8_C(  43),  INT8_C(  55),
        -INT8_C(  97),  INT8_C(  38),  INT8_C(  58),  INT8_C(   7),  INT8_C( 104), -INT8_C(  19), -INT8_C(  69), -INT8_C( 117),
         INT8_C( 104), -INT8_C(  81), -INT8_C(  94), -INT8_C( 122), -INT8_C(  68),  INT8_C(  13), -INT8_C(  73),  INT8_C(   1) },
      UINT32_C(3186980543) },
    { { -INT8_C(  67), -INT8_C( 104), -INT8_C(  73),  INT8_C(  21),  INT8_C(  40), -INT8_C( 116), -INT8_C(  77), -INT8_C(  19),
         INT8_C(  61), -INT8_C( 113),  INT8_C(  74), -INT8_C(  96),  INT8_C(  88), -INT8_C(  34), -INT8_C(  95),  INT8_C(  70),
        -INT8_C(  92), -INT8_C(  86),  INT8_C(  87),  INT8_C(  88), -INT8_C(  65), -INT8_C(  13), -INT8_C( 120), -INT8_C( 125),
        -INT8_C(  96),  INT8_C(  44),  INT8_C(   3),  INT8_C(   4), -INT8_C( 120), -INT8_C( 123), -INT8_C(   1),  INT8_C(  70) },
      {  INT8_C(  29), -INT8_C(  74), -INT8_C(  73),  INT8_C(  21),  INT8_C(  40),  INT8_C(  14),  INT8_C(  50),      INT8_MIN,
        -INT8_C(  98),  INT8_C( 124),  INT8_C(  74), -INT8_C(  96),  INT8_C(  90), -INT8_C(  34),  INT8_C(  60), -INT8_C(   2),
        -INT8_C(  92), -INT8_C( 108),  INT8_C(  87),  INT8_C(  88), -INT8_C( 121), -INT8_C(  13), -INT8_C( 120), -INT8_C( 125),
         INT8_C(  11),  INT8_C(  44),  INT8_C(   3),  INT8_C(   4),  INT8_C(  54),  INT8_C(  43), -INT8_C(   1),  INT8_C(  70) },
      UINT32_C(3472862620) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256i a = simde_mm256_loadu_epi8(test_vec[i].a);
    simde__m256i b = simde_mm256_loadu_epi8(test_vec[i].b);
    simde__mmask32 r = simde_mm256_cmpge_epi8_mask(a, b);
    simde_assert_equal_mmask32(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    int8_t a_[32];
    int8_t b_[32];

    simde_test_codegen_random_memory(sizeof(a_), HEDLEY_REINTERPRET_CAST(uint8_t*, a_));
    simde_test_codegen_random_memory(sizeof(b_), HEDLEY_REINTERPRET_CAST(uint8_t*, b_));
    for (size_t j = 0 ; j < (sizeof(a_) / sizeof(a_[0])) ; j++)
      if ((simde_test_codegen_rand() & 3) == 0)
        b_[j] = a_[j];

    simde__m256i a = simde_mm256_loadu_epi8(a_);
    simde__m256i b = simde_mm256_loadu_epi8(b_);
    simde__mmask32 r = simde_mm256_cmpge_epi8_mask(a, b);

    simde_test_x86_write_i8x32(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i8x32(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_mask_cmpge_epi8_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask32 k;
    const int8_t a[32];
    const int8_t b[32];
    const simde__mmask32 r;
  } test_vec[] = {
    { UINT32_C( 499934921),
      { -INT8_C( 124), -INT8_C(  96), -INT8_C(  75), -INT8_C(  56),  INT8_C( 107),  INT8_C(  90), -INT8_C(  86), -INT8_C(  79),
         INT8_C(  31), -INT8_C( 126),  INT8_C(  82), -INT8_C(  89), -INT8_C( 106), -INT8_C(  15), -INT8_C( 102),  INT8_C(  63),
        -INT8_C(  25), -INT8_C(  71),  INT8_C( 111), -INT8_C(  68), -INT8_C( 123), -INT8_C(  57), -INT8_C( 100),  INT8_C(   3),
         INT8_C(  75),  INT8_C(  17), -INT8_C(  72), -INT8_C(   6),  INT8_C(  95), -INT8_C(  64), -INT8_C( 118), -INT8_C(  29) },
      {  INT8_C(  96),  INT8_C(  63), -INT8_C(  75), -INT8_C(  53),  INT8_C( 107),  INT8_C(  85), -INT8_C(  86), -INT8_C(  79),
         INT8_C(  31), -INT8_C( 126),  INT8_C(  96), -INT8_C(  89), -INT8_C(  64), -INT8_C(   6), -INT8_C(  83), -INT8_C(  89),
        -INT8_C(  77),  INT8_C(  28),  INT8_C(  99),  INT8_C(  57), -INT8_C(  29), -INT8_C(  57), -INT8_C( 100),  INT8_C(  46),
         INT8_C(  75),  INT8_C(  17),  INT8_C(  40),  INT8_C( 112), -INT8_C(  76), -INT8_C(  78),  INT8_C(  83), -INT8_C(  29) },
      UINT32_C( 289669824) },
    { UINT32_C(3677230027),
      { -INT8_C(  60),  INT8_C(  16),  INT8_C(  73), -INT8_C(  16), -INT8_C(  75), -INT8_C(  29), -INT8_C(  35),  INT8_C(  84),
         INT8_C(  42),  INT8_C( 112), -INT8_C(  90), -INT8_C( 115),  INT8_C( 103),  INT8_C(  50), -INT8_C(  45),  INT8_C(  93),
        -INT8_C(   6),  INT8_C(  71),  INT8_C(  99), -INT8_C(  74), -INT8_C(  29), -INT8_C(  38),  INT8_C(  39),  INT8_C(  50),
        -INT8_C(  92), -INT8_C(  83),  INT8_C( 114),  INT8_C( 109),  INT8_C(  20),  INT8_C(  62), -INT8_C( 118), -INT8_C(  40) },
      {  INT8_C(  79), -INT8_C(  44),  INT8_C(  73),  INT8_C(   4), -INT8_C(  75), -INT8_C(  29), -INT8_C(  35), -INT8_C(  30),
         INT8_C(  22),  INT8_C( 112),  INT8_C( 111),  INT8_C( 125),  INT8_C(  48),  INT8_C(  67), -INT8_C(  38),  INT8_C(  42),
        -INT8_C( 118),  INT8_C(  61), -INT8_C(  31),  INT8_C( 110),  INT8_C(  23),  INT8_C(   8), -INT8_C(  96), -INT8_C(  69),
        -INT8_C(  74),  INT8_C(  18),  INT8_C(  40), -INT8_C(  54),  INT8_C(  81), -INT8_C(  77), -INT8_C(  94), -INT8_C(  40) },
      UINT32_C(2282099650) },
    { UINT32_C(2139441104),
      {  INT8_C(  15),  INT8_C(  79),  INT8_C(   1),  INT8_C(   9), -INT8_C(  33), -INT8_C(  92),  INT8_C(  52), -INT8_C(  78),
         INT8_C(  33), -INT8_C( 118),  INT8_C(  15), -INT8_C(  36), -INT8_C(  64), -INT8_C(  37), -INT8_C(  82), -INT8_C(   1),
         INT8_C(  70),  INT8_C(  59), -INT8_C(  12), -INT8_C(  60), -INT8_C(  15), -INT8_C(  77), -INT8_C( 109),  INT8_C(  90),
         INT8_C(  20),  INT8_C(   2),  INT8_C(  74), -INT8_C(  32),  INT8_C(  21),  INT8_C( 121), -INT8_C(  69),  INT8_C(  36) },
      { -INT8_C(  56),  INT8_C(  79),  INT8_C(  46), -INT8_C(  89),  INT8_C(  97), -INT8_C(  92),  INT8_C(  89), -INT8_C( 125),
         INT8_C(  33),  INT8_C( 104),  INT8_C(  15), -INT8_C(  36),  INT8_C(  67),  INT8_C(  13), -INT8_C(  84), -INT8_C( 118),
         INT8_C(  72),  INT8_C(  59), -INT8_C(  12),  INT8_C(  58),  INT8_C(  84), -INT8_C(  30), -INT8_C( 108),  INT8_C( 105),
         INT8_C(  20),  INT8_C(   2),  INT8_C(  73), -INT8_C(  32),  INT8_C(  88),  INT8_C(   4), -INT8_C(  69),  INT8_C(  32) },
      UINT32_C(1862550912) },
    { UINT32_C(  77490830),
      {  INT8_C( 103),  INT8_C(  43),  INT8_C(  26), -INT8_C(  17),  INT8_C(  48),  INT8_C(  99), -INT8_C(  69),  INT8_C(  66),
         INT8_C(  88),  INT8_C(  17), -INT8_C(  99), -INT8_C(  18), -INT8_C(  74),  INT8_C(  49), -INT8_C(  40),  INT8_C(  60),
         INT8_C(  90),  INT8_C(  44), -INT8_C(  89),  INT8_C(  98), -INT8_C(  56),  INT8_C(  12), -INT8_C(  62),  INT8_C( 105),
        -INT8_C( 112),  INT8_C(  66), -INT8_C(  52),  INT8_C(  96), -INT8_C( 119),  INT8_C(  81), -INT8_C(  33), -INT8_C(  16) },
      {  INT8_C( 103), -INT8_C(   7), -INT8_C(  32), -INT8_C(  17),  INT8_C(  92), -INT8_C( 101), -INT8_C(  16), -INT8_C(  76),
        -INT8_C(  83), -INT8_C( 115), -INT8_C(  94), -INT8_C(  18), -INT8_C(  66),  INT8_C( 123), -INT8_C(  97),  INT8_C(  25),
         INT8_C(  90),  INT8_C(  71),  INT8_C( 123),  INT8_C(  98),  INT8_C(  83),  INT8_C(  62), -INT8_C(  39), -INT8_C(  29),
             INT8_MIN, -INT8_C(  91),  INT8_C(  67),  INT8_C(  10), -INT8_C(  10),  INT8_C(  81), -INT8_C(   6),  INT8_C( 115) },
      UINT32_C(   8931982) },
    { UINT32_C(2174189822),
      {  INT8_C( 123), -INT8_C(  53),  INT8_C(  39),  INT8_C(  25), -INT8_C( 102), -INT8_C(  83),  INT8_C( 117), -INT8_C(  27),
        -INT8_C(  45), -INT8_C(  21), -INT8_C(  42),  INT8_C(  63), -INT8_C(  36),  INT8_C(  55), -INT8_C(   1),  INT8_C(  11),
         INT8_C( 113), -INT8_C(  93), -INT8_C(  70),  INT8_C(  80), -INT8_C( 118),  INT8_C( 116),  INT8_C(  38), -INT8_C( 109),
         INT8_C(  40),  INT8_C( 111), -INT8_C(  71), -INT8_C(  74), -INT8_C(  39),  INT8_C(  87), -INT8_C(  69),  INT8_C(  84) },
      {  INT8_C(  34), -INT8_C(  53),  INT8_C( 109), -INT8_C(  68), -INT8_C( 112), -INT8_C(  30), -INT8_C(  95), -INT8_C(  27),
        -INT8_C(  51), -INT8_C(  21), -INT8_C(  94), -INT8_C(  87), -INT8_C(  81), -INT8_C(  94), -INT8_C(  76),  INT8_C(  33),
         INT8_C(  69), -INT8_C(  93),  INT8_C( 113),  INT8_C(  80), -INT8_C( 118), -INT8_C( 105),  INT8_C(  98),  INT8_C(  11),
         INT8_C(  40),  INT8_C(  27), -INT8_C(  63), -INT8_C(  33),  INT8_C( 114),  INT8_C( 124),  INT8_C(  51),  INT8_C(  84) },
      UINT32_C(2165506266) },
    { UINT32_C( 219410072),
      {  INT8_C( 115), -INT8_C(  23), -INT8_C(  47), -INT8_C(  35), -INT8_C(  34), -INT8_C(  53), -INT8_C(   9),  INT8_C( 116),
         INT8_C( 122),  INT8_C(  50),  INT8_C(  80), -INT8_C( 105), -INT8_C(  33), -INT8_C(   6), -INT8_C( 104),  INT8_C(  35),
         INT8_C(   7), -INT8_C(  93),  INT8_C( 109),  INT8_C(  48),  INT8_C( 112), -INT8_C( 105), -INT8_C(  53), -INT8_C(  70),
        -INT8_C(  11), -INT8_C(   6),  INT8_C(  98), -INT8_C(  13),  INT8_C( 123), -INT8_C(   6),  INT8_C( 116), -INT8_C(  18) },
      { -INT8_C(  29),  INT8_C(  69), -INT8_C(  53), -INT8_C(  63),  INT8_C(  17), -INT8_C(  53),  INT8_C(  54), -INT8_C( 117),
        -INT8_C(  11),  INT8_C(  50),  INT8_C(  34), -INT8_C(  44),      INT8_MIN, -INT8_C(  70), -INT8_C(   9), -INT8_C( 120),
         INT8_C(  94),  INT8_C( 101), -INT8_C(  72),  INT8_C(  48), -INT8_C(   4), -INT8_C( 105), -INT8_C( 120), -INT8_C(  15),
         INT8_C( 125), -INT8_C(  21), -INT8_C(  28), -INT8_C(  13), -INT8_C(  27),  INT8_C(  88),  INT8_C( 116), -INT8_C(  18) },
      UINT32_C( 202417800) },
    { UINT32_C(2615593128),
      { -INT8_C(  82),  INT8_C(  77),  INT8_C( 119), -INT8_C(  12), -INT8_C(  86), -INT8_C(  74), -INT8_C(  69), -INT8_C(  63),
        -INT8_C(  19),  INT8_C(   9),  INT8_C(  54), -INT8_C( 120),  INT8_C(  16),  INT8_C( 121),  INT8_C(  32), -INT8_C( 103),
         INT8_C(  69), -INT8_C(  86), -INT8_C(  96), -INT8_C(   4),  INT8_C(  24), -INT8_C(  96), -INT8_C( 104), -INT8_C(  34),
        -INT8_C( 122), -INT8_C(   3),  INT8_C(  67),  INT8_C(  30), -INT8_C(  21),  INT8_C(  86),  INT8_C(  43), -INT8_C( 102) },
      { -INT8_C(  92), -INT8_C(  94), -INT8_C( 114),  INT8_C(  78),  INT8_C(  89),  INT8_C(  73),  INT8_C(  15),  INT8_C(  70),
         INT8_C(  83),  INT8_C(   9), -INT8_C(  50),  INT8_C(  99), -INT8_C(  66), -INT8_C(  17), -INT8_C(   4), -INT8_C( 103),
        -INT8_C( 103), -INT8_C(  99),  INT8_C(   0), -INT8_C(   4),  INT8_C(  61), -INT8_C(  96), -INT8_C( 113), -INT8_C(  61),
        -INT8_C( 106), -INT8_C(   3), -INT8_C(  31),  INT8_C(  30), -INT8_C(  21),  INT8_C(  12),  INT8_C(  27), -INT8_C(  51) },
      UINT32_C( 451067904) },
    { UINT32_C(3803105722),
      { -INT8_C(  14),  INT8_C(  51), -INT8_C(  30),  INT8_C(  97),  INT8_C(  79), -INT8_C( 117), -INT8_C( 114),  INT8_C(  90),
         INT8_C(  49), -INT8_C(  64), -INT8_C(   2),  INT8_C( 116), -INT8_C(  14),  INT8_C(  83), -INT8_C(  12), -INT8_C(  67),
         INT8_C(  56),  INT8_C(  55),  INT8_C(  30), -INT8_C(  17),  INT8_C(  91),  INT8_C(   0), -INT8_C(  49), -INT8_C( 117),
        -INT8_C(   2),  INT8_C( 124),  INT8_C( 106), -INT8_C(  90),  INT8_C(  68),  INT8_C(  80),  INT8_C(  66),  INT8_C(  54) },
      { -INT8_C( 125),  INT8_C(  36), -INT8_C( 105), -INT8_C(  45),  INT8_C(  79),  INT8_C(  37),  INT8_C(  45), -INT8_C(  31),
        -INT8_C(  27), -INT8_C(  64),  INT8_C(  85), -INT8_C(  41),      INT8_MAX,  INT8_C(  74), -INT8_C( 108), -INT8_C(  73),
         INT8_C(  56),  INT8_C(  55),  INT8_C(  30), -INT8_C(  35), -INT8_C(  77),  INT8_C( 117), -INT8_C(  49), -INT8_C(  79),
        -INT8_C(  15),  INT8_C( 124),  INT8_C( 106),  INT8_C(  53),  INT8_C(  34),  INT8_C(  80),  INT8_C(  66),  INT8_C(  54) },
      UINT32_C(3792619930) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__mmask32 k = test_vec[i].k;
    simde__m256i a = simde_mm256_loadu_epi8(test_vec[i].a);
    simde__m256i b = simde_mm256_loadu_epi8(test_vec[i].b);
    simde__mmask32 r = simde_mm256_mask_cmpge_epi8_mask(k, a, b);
    simde_assert_equal_mmask32(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    int8_t a_[32];
    int8_t b_[32];

    simde_test_codegen_random_memory(sizeof(a_), HEDLEY_REINTERPRET_CAST(uint8_t*, a_));
    simde_test_codegen_random_memory(sizeof(b_), HEDLEY_REINTERPRET_CAST(uint8_t*, b_));
    for (size_t j = 0 ; j < (sizeof(a_) / sizeof(a_[0])) ; j++)
      if ((simde_test_codegen_rand() & 3) == 0)
        b_[j] = a_[j];

    simde__mmask32 k = simde_test_x86_random_mmask32();
    simde__m256i a = simde_mm256_loadu_epi8(a_);
    simde__m256i b = simde_mm256_loadu_epi8(b_);
    simde__mmask32 r = simde_mm256_mask_cmpge_epi8_mask(k, a, b);

    simde_test_x86_write_mmask32(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i8x32(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i8x32(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_x_mm512_cmpge_epi8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int8_t a[64];
    const int8_t b[64];
    const int8_t r[64];
  } test_vec[] = {
    { { -INT8_C(  94), -INT8_C(  47), -INT8_C(  52), -INT8_C(  85),  INT8_C(  25), -INT8_C( 118),  INT8_C( 121), -INT8_C(   5),
        -INT8_C(  38), -INT8_C(   9),  INT8_C(  20),  INT8_C( 108), -INT8_C(  24), -INT8_C(   1), -INT8_C(  70), -INT8_C(  28),
        -INT8_C(  68), -INT8_C( 108), -INT8_C( 124),  INT8_C(  12), -INT8_C(  38),  INT8_C( 126),  INT8_C(  61),  INT8_C(  70),
        -INT8_C(  87),  INT8_C( 120), -INT8_C(  67), -INT8_C(  77),      INT8_MIN, -INT8_C(  81),  INT8_C( 105),  INT8_C(  34),
             INT8_MIN,  INT8_C(  53), -INT8_C(  51), -INT8_C( 103), -INT8_C(  65),  INT8_C(  70), -INT8_C( 108), -INT8_C( 102),
         INT8_C(  62), -INT8_C(  87),  INT8_C(   6),  INT8_C(  38), -INT8_C(  88), -INT8_C(  64),  INT8_C(  11),  INT8_C( 100),
         INT8_C(  84), -INT8_C( 113),  INT8_C( 112),  INT8_C(  47),  INT8_C(  13), -INT8_C(  83),  INT8_C( 117), -INT8_C(  73),
         INT8_C(  37),  INT8_C(  50),  INT8_C( 106), -INT8_C(  90), -INT8_C(  31), -INT8_C(  45), -INT8_C(  56),  INT8_C(  97) },
      {  INT8_C(   8), -INT8_C( 106), -INT8_C(   6), -INT8_C(  56), -INT8_C(  36), -INT8_C( 114),  INT8_C( 121),  INT8_C(  26),
         INT8_C(  55),  INT8_C( 104),  INT8_C(  20), -INT8_C(  33),  INT8_C(  40),  INT8_C(  76),  INT8_C(  68),  INT8_C( 125),
        -INT8_C(  68), -INT8_C(  76), -INT8_C(  84), -INT8_C(  23),  INT8_C(  98),  INT8_C( 126), -INT8_C(  96), -INT8_C( 121),
        -INT8_C(  87),  INT8_C(  10),  INT8_C(  45),  INT8_C(  52), -INT8_C(  34), -INT8_C(  10),  INT8_C( 105),  INT8_C(  34),
        -INT8_C( 116), -INT8_C( 113), -INT8_C(  82),  INT8_C( 104), -INT8_C(  65),  INT8_C(  70), -INT8_C( 125),  INT8_C(  85),
         INT8_C( 120), -INT8_C(  60),  INT8_C(  52), -INT8_C(  95),  INT8_C(  16), -INT8_C(  64),  INT8_C(  30), -INT8_C(  21),
         INT8_C(  45), -INT8_C(  54), -INT8_C(  44), -INT8_C( 113), -INT8_C(  21),  INT8_C( 116),  INT8_C( 117),  INT8_C(  62),
             INT8_MAX,  INT8_C(  68),  INT8_C( 106), -INT8_C(  90), -INT8_C(  31), -INT8_C(  45), -INT8_C(  56), -INT8_C(  58) },
      {  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
         INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
        -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
        -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
         INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
         INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
        -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
         INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1) } },
    { {  INT8_C(  95),  INT8_C(  47),  INT8_C(  89),  INT8_C(  11),  INT8_C(  39), -INT8_C(  94),  INT8_C(  44),  INT8_C(  92),
         INT8_C(   7), -INT8_C(  45),  INT8_C(  71), -INT8_C(  90), -INT8_C(  21),  INT8_C(  20),  INT8_C(  73),  INT8_C(  73),
         INT8_C(  82), -INT8_C(  37),  INT8_C(  96),  INT8_C(  25), -INT8_C( 102), -INT8_C(  79), -INT8_C(  85), -INT8_C(   8),
        -INT8_C( 105),  INT8_C(  68), -INT8_C(   4),  INT8_C(  87), -INT8_C(  88),  INT8_C(  60), -INT8_C(  29),  INT8_C(   7),
         INT8_C( 108),  INT8_C(  60),  INT8_C(  18), -INT8_C( 109), -INT8_C(  33),  INT8_C(  63), -INT8_C(  16), -INT8_C(  26),
         INT8_C(  18),  INT8_C(  55), -INT8_C( 115), -INT8_C(   2),  INT8_C(  75), -INT8_C(  42),  INT8_C(  71), -INT8_C(  99),
        -INT8_C(  78), -INT8_C(  89), -INT8_C(  74),  INT8_C(  76),  INT8_C(  88),  INT8_C(  98),  INT8_C(  69), -INT8_C(  16),
        -INT8_C(  90),  INT8_C(  65),  INT8_C(  71),  INT8_C(  78),  INT8_C( 126),  INT8_C(  42),  INT8_C(  86), -INT8_C(  22) },
      {  INT8_C( 103),  INT8_C( 104),  INT8_C(  89),  INT8_C(  70), -INT8_C(  89),  INT8_C( 109),  INT8_C(  44), -INT8_C(  70),
         INT8_C(   7), -INT8_C(  45), -INT8_C(  72), -INT8_C(  17), -INT8_C( 112), -INT8_C(   1),  INT8_C(  73),  INT8_C(  66),
         INT8_C(  82),  INT8_C(  67), -INT8_C( 114),  INT8_C(  25), -INT8_C( 102), -INT8_C(  45), -INT8_C(  17), -INT8_C(   8),
        -INT8_C( 105),  INT8_C(  54), -INT8_C( 102),  INT8_C(  87),  INT8_C(  97), -INT8_C(  16), -INT8_C(  29), -INT8_C(  56),
         INT8_C(  88),  INT8_C(  60),  INT8_C(  14),  INT8_C(   0),  INT8_C( 104),  INT8_C(  58), -INT8_C(  16),  INT8_C(  12),
        -INT8_C(  12),  INT8_C( 114), -INT8_C(   4), -INT8_C( 124),  INT8_C( 113), -INT8_C( 119), -INT8_C(  58),  INT8_C(  23),
        -INT8_C(  52),  INT8_C(  84),  INT8_C(  22),  INT8_C( 114),  INT8_C(  88),  INT8_C(   5), -INT8_C(  67), -INT8_C(  16),
         INT8_C(  60),  INT8_C(  87),  INT8_C(  71), -INT8_C(  99),  INT8_C(  71),  INT8_C(  42),  INT8_C( 101), -INT8_C(  96) },
      {  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
        -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
        -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
        -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
        -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
        -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
         INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
         INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1) } },
    { {  INT8_C(  64), -INT8_C(  56),  INT8_C(  68), -INT8_C(  74),  INT8_C(  61), -INT8_C(  76), -INT8_C(   8),  INT8_C( 106),
         INT8_C(  74),  INT8_C( 119), -INT8_C(  40), -INT8_C(  52),  INT8_C(  75),  INT8_C(  83), -INT8_C( 115), -INT8_C( 119),
         INT8_C(  78), -INT8_C(  73),  INT8_C(  56), -INT8_C( 122), -INT8_C( 123), -INT8_C( 108),  INT8_C(  83), -INT8_C(  55),
         INT8_C(  57), -INT8_C(   5), -INT8_C(  50), -INT8_C( 116),  INT8_C(  32), -INT8_C(  35),  INT8_C(   1),  INT8_C(  96),
        -INT8_C(  91),  INT8_C(  69),  INT8_C(  23), -INT8_C(  30), -INT8_C(   6),  INT8_C(  15),  INT8_C(  76),  INT8_C(  68),
        -INT8_C( 121),  INT8_C(  36),  INT8_C(  16), -INT8_C(  46),  INT8_C( 120), -INT8_C(  98),  INT8_C(  91), -INT8_C(  58),
         INT8_C(  85), -INT8_C( 108),  INT8_C(  77), -INT8_C(  38),  INT8_C(  40), -INT8_C(  96), -INT8_C(  93),  INT8_C(  97),
        -INT8_C( 101),  INT8_C( 114), -INT8_C(  19), -INT8_C(  69),  INT8_C(  79), -INT8_C(  17),  INT8_C(  28), -INT8_C(  11) },
      {  INT8_C(  52),  INT8_C(  51), -INT8_C(  41), -INT8_C(  74),  INT8_C(  66), -INT8_C(  76),  INT8_C( 115), -INT8_C(  55),
         INT8_C(  72), -INT8_C( 125), -INT8_C( 101), -INT8_C(  64),  INT8_C(  33), -INT8_C(   9), -INT8_C( 121),  INT8_C( 118),
        -INT8_C( 117), -INT8_C(  73),  INT8_C(  81), -INT8_C(  77),  INT8_C( 116), -INT8_C( 108),  INT8_C(  20),  INT8_C(  15),
         INT8_C( 102),  INT8_C(   1), -INT8_C(  53), -INT8_C(  74), -INT8_C(  16), -INT8_C(  25), -INT8_C(  85),  INT8_C(  96),
         INT8_C(  26), -INT8_C( 126),  INT8_C(  23),  INT8_C(  92), -INT8_C(  90), -INT8_C(  58),  INT8_C(  38),  INT8_C(  68),
         INT8_C(  74),  INT8_C(  36), -INT8_C(  81),  INT8_C( 107), -INT8_C(  72), -INT8_C(  98), -INT8_C(  30),  INT8_C(  67),
         INT8_C(  10), -INT8_C( 108), -INT8_C(  10), -INT8_C(  38),  INT8_C(  40),  INT8_C(  10), -INT8_C( 114), -INT8_C( 114),
         INT8_C(  12),  INT8_C(  89),  INT8_C(  68), -INT8_C(  69),  INT8_C(  64), -INT8_C(  17),  INT8_C(  28),  INT8_C(  90) },
      { -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
        -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
        -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
         INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
         INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
         INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
        -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
         INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0) } },
    { {  INT8_C(  50),  INT8_C( 116),  INT8_C(   3), -INT8_C(  68), -INT8_C(  13), -INT8_C(   2), -INT8_C(  28),  INT8_C(  40),
        -INT8_C(  22),  INT8_C(  99),  INT8_C(  75), -INT8_C(  87),  INT8_C( 123),  INT8_C( 101),  INT8_C( 110),  INT8_C(  36),
        -INT8_C(  11),  INT8_C(  96),  INT8_C( 104), -INT8_C( 119),  INT8_C(  14),  INT8_C(  83),  INT8_C( 122), -INT8_C(  68),
        -INT8_C(  30),  INT8_C(   8),  INT8_C(  88),  INT8_C(  53), -INT8_C( 115),  INT8_C(  84), -INT8_C(  61), -INT8_C(  65),
        -INT8_C(  56), -INT8_C(  58),  INT8_C( 124), -INT8_C(  69), -INT8_C(  60),  INT8_C(  96), -INT8_C(  29), -INT8_C(  82),
        -INT8_C(  61),  INT8_C(  46),  INT8_C(  87),  INT8_C(  63), -INT8_C( 109), -INT8_C(  59),  INT8_C(  99), -INT8_C( 120),
         INT8_C(  37), -INT8_C(  52),  INT8_C(  17),  INT8_C(  52),  INT8_C(  31), -INT8_C( 117), -INT8_C(  16),  INT8_C(   1),
        -INT8_C( 109),  INT8_C(  72),  INT8_C(  55),  INT8_C(  32), -INT8_C( 100), -INT8_C(   6), -INT8_C(  32),  INT8_C( 100) },
      { -INT8_C(  64),  INT8_C( 116),  INT8_C(  31), -INT8_C( 124), -INT8_C(  68), -INT8_C(   2), -INT8_C(  28),      INT8_MIN,
         INT8_C(  49), -INT8_C( 119), -INT8_C(  65), -INT8_C(  60),  INT8_C(  78),  INT8_C( 101),  INT8_C( 110),  INT8_C(  36),
        -INT8_C(  18),  INT8_C(  94),  INT8_C( 104),  INT8_C(  14), -INT8_C(  22), -INT8_C( 105),  INT8_C( 122),  INT8_C( 125),
        -INT8_C(  33),  INT8_C(  70), -INT8_C(  98),  INT8_C( 123),  INT8_C(  64),  INT8_C( 126), -INT8_C(  33),  INT8_C(   0),
        -INT8_C(  38), -INT8_C(  58), -INT8_C( 124), -INT8_C(  69), -INT8_C(  60), -INT8_C(  74),  INT8_C(  22),  INT8_C(  50),
         INT8_C(  63), -INT8_C(  43),  INT8_C(  87), -INT8_C( 115), -INT8_C(   8),  INT8_C(  67),  INT8_C(   1), -INT8_C(  26),
        -INT8_C(  94), -INT8_C(  88),  INT8_C(  17), -INT8_C( 116),  INT8_C(  64),  INT8_C(   4),  INT8_C(   9),  INT8_C(   1),
        -INT8_C( 109), -INT8_C(  89), -INT8_C( 101), -INT8_C( 117),  INT8_C(  37), -INT8_C(   6), -INT8_C( 117), -INT8_C(   1) },
      { -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
         INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
        -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
        -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
         INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
         INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
        -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
        -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1) } },
    { { -INT8_C(  84), -INT8_C(  50),  INT8_C(  29), -INT8_C(  39),  INT8_C(  31), -INT8_C(  76), -INT8_C( 121),  INT8_C(  19),
        -INT8_C(  34), -INT8_C(  80), -INT8_C(  20), -INT8_C( 100),  INT8_C(  57),  INT8_C(  78), -INT8_C( 104),  INT8_C(  23),
        -INT8_C(  61),  INT8_C(  16),  INT8_C(  78),  INT8_C(  86),  INT8_C(  37),  INT8_C(  40), -INT8_C(  82),  INT8_C( 114),
         INT8_C(  49), -INT8_C(  15),  INT8_C( 112), -INT8_C(  12),  INT8_C(  29), -INT8_C( 102), -INT8_C( 127), -INT8_C(  54),
         INT8_C( 104), -INT8_C(  97), -INT8_C(  93), -INT8_C( 120),  INT8_C(  83),  INT8_C(  42), -INT8_C( 101),  INT8_C(  49),
        -INT8_C(  38), -INT8_C( 121), -INT8_C(  51),  INT8_C(  19), -INT8_C(  43),  INT8_C( 101),  INT8_C(  42), -INT8_C( 103),
         INT8_C( 118),  INT8_C( 120), -INT8_C(  17), -INT8_C( 101), -INT8_C(  95), -INT8_C(  98),  INT8_C(  13), -INT8_C(  46),
        -INT8_C( 113),  INT8_C( 126), -INT8_C(  57), -INT8_C(  84),  INT8_C(  24),  INT8_C(  72),  INT8_C( 118),      INT8_MIN },
      { -INT8_C(  25), -INT8_C(  50),  INT8_C(   8),  INT8_C(  58),  INT8_C(  68), -INT8_C(  76),  INT8_C( 107),  INT8_C(  19),
         INT8_C(  43),  INT8_C(  57),  INT8_C(  50),  INT8_C(   0), -INT8_C(  98),  INT8_C(  92), -INT8_C( 103),  INT8_C(  23),
        -INT8_C(  61), -INT8_C( 119), -INT8_C(  80),  INT8_C( 118),  INT8_C(  39),  INT8_C(  40),  INT8_C(  72), -INT8_C(  74),
         INT8_C(  59),  INT8_C(  15),  INT8_C(  98), -INT8_C(  12),  INT8_C(  88), -INT8_C( 102), -INT8_C(  44), -INT8_C(  54),
         INT8_C( 104), -INT8_C(  97),  INT8_C( 122),  INT8_C(  54),      INT8_MIN,  INT8_C(  42),  INT8_C(  85),  INT8_C(  49),
         INT8_C(  30), -INT8_C( 121), -INT8_C(  85), -INT8_C(  67), -INT8_C(  29),  INT8_C(  69), -INT8_C(  47), -INT8_C(  72),
        -INT8_C(  50),  INT8_C( 120), -INT8_C(  17), -INT8_C(  11), -INT8_C(  95),  INT8_C( 119), -INT8_C(  85),  INT8_C( 122),
        -INT8_C( 122),  INT8_C(  13), -INT8_C(  50), -INT8_C(  34), -INT8_C(  26), -INT8_C(  94),  INT8_C(  30), -INT8_C(  39) },
      {  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
         INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
        -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
         INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
        -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
         INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
        -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
        -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0) } },
    { { -INT8_C( 125), -INT8_C( 111),  INT8_C( 113), -INT8_C(  52), -INT8_C( 115), -INT8_C(  46),  INT8_C(   0), -INT8_C(  34),
        -INT8_C( 115),  INT8_C(   4), -INT8_C(  55),  INT8_C( 114), -INT8_C( 113),  INT8_C(  28),  INT8_C(   3), -INT8_C(  48),
        -INT8_C(  52),      INT8_MAX,  INT8_C(  62), -INT8_C( 124),  INT8_C(  96),  INT8_C(  95),  INT8_C(  81),  INT8_C( 117),
         INT8_C(  19),  INT8_C(  27),  INT8_C(  96),  INT8_C( 118), -INT8_C(  71), -INT8_C(  98),  INT8_C(  34),  INT8_C(  60),
         INT8_C(  47), -INT8_C( 109),  INT8_C(   8), -INT8_C(  68),  INT8_C( 101),  INT8_C(   9), -INT8_C( 102), -INT8_C(  14),
         INT8_C(  13),  INT8_C(  99),  INT8_C( 100), -INT8_C( 100),      INT8_MAX,  INT8_C( 103),  INT8_C( 108),  INT8_C(  75),
        -INT8_C(  26), -INT8_C(  86), -INT8_C(  49),  INT8_C(  71),  INT8_C(   9),  INT8_C(  33), -INT8_C(  68),  INT8_C(  28),
         INT8_C(  60),  INT8_C(  28), -INT8_C( 109), -INT8_C(  11), -INT8_C(  69), -INT8_C(  75),  INT8_C(  50), -INT8_C(  22) },
      {  INT8_C(  72),  INT8_C(  58), -INT8_C(  89), -INT8_C(  52),  INT8_C(  67),  INT8_C(  65), -INT8_C(  96),  INT8_C(  80),
        -INT8_C(  91),  INT8_C(   4), -INT8_C(  55),  INT8_C(  36),  INT8_C( 108),  INT8_C(  88),  INT8_C(   3),  INT8_C(  82),
         INT8_C(   2),  INT8_C(  63), -INT8_C( 103), -INT8_C( 124),  INT8_C(  96),  INT8_C(  86),  INT8_C(  40), -INT8_C( 100),
         INT8_C(  19), -INT8_C(  69), -INT8_C( 110),  INT8_C( 118), -INT8_C(  71), -INT8_C(  98),  INT8_C(  24), -INT8_C(  72),
        -INT8_C(   2), -INT8_C( 109),  INT8_C( 102), -INT8_C(  68),  INT8_C( 101),  INT8_C(   6), -INT8_C( 110), -INT8_C(  91),
         INT8_C(  13),      INT8_MAX,  INT8_C( 100),  INT8_C( 118), -INT8_C(  41),  INT8_C( 103), -INT8_C(  55), -INT8_C(  38),
         INT8_C( 121),  INT8_C(  98), -INT8_C(  26), -INT8_C(  38), -INT8_C(  72),  INT8_C(  14),  INT8_C( 118),  INT8_C(  43),
         INT8_C(  60),  INT8_C(   8),  INT8_C(  88), -INT8_C(  11), -INT8_C(  52),  INT8_C( 112),  INT8_C(  50), -INT8_C(  53) },
      {  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
         INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
         INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
        -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
        -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
        -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
         INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
        -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1) } },
    { {  INT8_C(  66),  INT8_C(  35), -INT8_C(  21),  INT8_C(  50),  INT8_C(  16), -INT8_C(  55),  INT8_C(  64), -INT8_C(  99),
        -INT8_C( 122),  INT8_C(  69),  INT8_C(   3), -INT8_C(  19),  INT8_C(  25), -INT8_C(  68),  INT8_C(  95), -INT8_C(  92),
        -INT8_C(  94), -INT8_C( 107), -INT8_C(  13),  INT8_C(  43), -INT8_C(  70), -INT8_C(  48),  INT8_C(  97),  INT8_C(  38),
         INT8_C( 119),  INT8_C(  15),  INT8_C(  75), -INT8_C(  39),  INT8_C(   0),  INT8_C(  87),  INT8_C(  81),  INT8_C(  66),
         INT8_C( 122),  INT8_C(  60),  INT8_C( 116), -INT8_C( 117),  INT8_C(   5), -INT8_C(  75),  INT8_C(  40), -INT8_C( 116),
        -INT8_C(   6),  INT8_C(  43),  INT8_C( 121),  INT8_C(  19), -INT8_C(  25), -INT8_C(  40), -INT8_C(  73), -INT8_C( 119),
         INT8_C( 109), -INT8_C(  86), -INT8_C(  76),  INT8_C(  39),  INT8_C( 123),  INT8_C(  21),  INT8_C(  77), -INT8_C(  14),
         INT8_C(  36), -INT8_C( 104), -INT8_C(  53),  INT8_C(  37), -INT8_C(  17),  INT8_C(  28),  INT8_C( 103),  INT8_C( 106) },
      {  INT8_C(  89), -INT8_C(  36), -INT8_C(  11),  INT8_C(  94), -INT8_C( 111),  INT8_C(  29), -INT8_C(  22), -INT8_C( 117),
         INT8_C(  72),  INT8_C(  99),  INT8_C(   3),  INT8_C(  47),  INT8_C(  59),  INT8_C(  86), -INT8_C(  72), -INT8_C(  88),
         INT8_C(   0),  INT8_C( 108), -INT8_C(  49),  INT8_C( 123), -INT8_C( 126),  INT8_C(  29),  INT8_C( 109), -INT8_C(  90),
        -INT8_C(  75),  INT8_C(  15),  INT8_C(  75), -INT8_C(  91),  INT8_C(  85),  INT8_C(  51),  INT8_C(  15), -INT8_C(  82),
         INT8_C(  15),  INT8_C(  60),  INT8_C( 116), -INT8_C( 117),  INT8_C(  33), -INT8_C(   9),  INT8_C(  43), -INT8_C( 116),
         INT8_C(  91), -INT8_C(  55), -INT8_C( 104), -INT8_C( 106), -INT8_C(  25),  INT8_C(  80), -INT8_C(  73),  INT8_C(  32),
        -INT8_C(  68),  INT8_C(  14), -INT8_C( 101),  INT8_C(  62),  INT8_C(  43),  INT8_C(   9), -INT8_C(  27), -INT8_C(  31),
         INT8_C(  66), -INT8_C( 104), -INT8_C(  53), -INT8_C( 105), -INT8_C(  29), -INT8_C( 107),  INT8_C( 103),  INT8_C( 106) },
      {  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
         INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
         INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
        -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
        -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
         INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
        -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
         INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1) } },
    { {  INT8_C(  53),  INT8_C( 116),  INT8_C(   4), -INT8_C(   9), -INT8_C( 101), -INT8_C(  47),  INT8_C(  63),  INT8_C( 125),
        -INT8_C(  37),  INT8_C(  46),  INT8_C( 106),  INT8_C(  95), -INT8_C(  28),  INT8_C(  30),  INT8_C( 109), -INT8_C(   5),
        -INT8_C(  39),  INT8_C(  48),  INT8_C( 126),  INT8_C( 126), -INT8_C( 119), -INT8_C(  83), -INT8_C(  65), -INT8_C(   2),
         INT8_C(  33),      INT8_MAX,  INT8_C(  36),  INT8_C(  32), -INT8_C(  79), -INT8_C( 108), -INT8_C(   4), -INT8_C(  26),
         INT8_C(   8),  INT8_C(   0), -INT8_C(  35), -INT8_C(  93), -INT8_C(  47),  INT8_C(  29),  INT8_C(  32), -INT8_C(  84),
         INT8_C(  75), -INT8_C( 118),  INT8_C(  12),  INT8_C(  47), -INT8_C(  87),  INT8_C( 121),  INT8_C(  43), -INT8_C( 126),
        -INT8_C(  86), -INT8_C(  87),  INT8_C(   0),  INT8_C(  51),  INT8_C(  86), -INT8_C(  64),  INT8_C(  50),  INT8_C( 120),
         INT8_C(  63),  INT8_C(  86), -INT8_C( 104), -INT8_C(  16), -INT8_C(  21), -INT8_C( 108), -INT8_C(  41), -INT8_C(  13) },
      { -INT8_C( 108), -INT8_C(  76), -INT8_C( 105),  INT8_C( 101), -INT8_C(  47), -INT8_C(  73),  INT8_C(  18),  INT8_C(  29),
         INT8_C(  66),  INT8_C(  30),  INT8_C(  76), -INT8_C(  21), -INT8_C( 105),  INT8_C(  30),  INT8_C( 109),  INT8_C(  65),
         INT8_C(  32),  INT8_C(  48),  INT8_C( 117),  INT8_C( 126),  INT8_C(  45), -INT8_C(  89), -INT8_C(  17),  INT8_C( 109),
        -INT8_C(   3), -INT8_C( 121),  INT8_C(  93),  INT8_C(  32),  INT8_C(  27),  INT8_C(  52), -INT8_C(  36), -INT8_C(  26),
        -INT8_C(  23),  INT8_C( 115),  INT8_C(  20), -INT8_C(  70),  INT8_C(  42),  INT8_C(  38), -INT8_C(  41), -INT8_C(  84),
         INT8_C(  75), -INT8_C( 118),  INT8_C(  87), -INT8_C(  36), -INT8_C(  87), -INT8_C(  60),  INT8_C(  29), -INT8_C(  68),
         INT8_C(  50), -INT8_C(  87),  INT8_C(  51),  INT8_C(  51),  INT8_C(  57),  INT8_C(  34), -INT8_C(  52),  INT8_C(  55),
         INT8_C(  63),  INT8_C(  42),  INT8_C(  31), -INT8_C(  60), -INT8_C(  21), -INT8_C( 108),  INT8_C( 115),  INT8_C(  71) },
      { -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
         INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
         INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
        -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
        -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
        -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
         INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
        -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i a = simde_mm512_loadu_epi8(test_vec[i].a);
    simde__m512i b = simde_mm512_loadu_epi8(test_vec[i].b);
    simde__m512i r = simde_x_mm512_cmpge_epi8(a, b);
    simde_test_x86_assert_equal_i8x64(r, simde_mm512_loadu_epi8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    int8_t a_[64];
    int8_t b_[64];

    simde_test_codegen_random_memory(sizeof(a_), HEDLEY_REINTERPRET_CAST(uint8_t*, a_));
    simde_test_codegen_random_memory(sizeof(b_), HEDLEY_REINTERPRET_CAST(uint8_t*, b_));
    for (size_t j = 0 ; j < (sizeof(a_) / sizeof(a_[0])) ; j++)
      if ((simde_test_codegen_rand() & 3) == 0)
        b_[j] = a_[j];

    simde__m512i a = simde_mm512_loadu_epi8(a_);
    simde__m512i b = simde_mm512_loadu_epi8(b_);
    simde__m512i r = simde_x_mm512_cmpge_epi8(a, b);

    simde_test_x86_write_i8x64(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i8x64(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i8x64(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_cmpge_epi8_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int8_t a[64];
    const int8_t b[64];
    const simde__mmask64 r;
  } test_vec[] = {
    { {  INT8_C( 110),  INT8_C(  52),  INT8_C(  13), -INT8_C( 103),  INT8_C(  75), -INT8_C(  65), -INT8_C(  63), -INT8_C(  65),
         INT8_C(  64), -INT8_C( 125),  INT8_C(  85), -INT8_C(  84), -INT8_C( 103),  INT8_C(  62), -INT8_C( 105),  INT8_C(  56),
        -INT8_C(  38),  INT8_C(  58),      INT8_MIN, -INT8_C(  11), -INT8_C(  52),  INT8_C(  28), -INT8_C(  70),  INT8_C( 109),
        -INT8_C(  50), -INT8_C( 121),  INT8_C(  23),  INT8_C(  11), -INT8_C(  92),  INT8_C(  58),  INT8_C(  89),  INT8_C(  18),
         INT8_C( 111),  INT8_C( 102), -INT8_C(  85), -INT8_C(  70),  INT8_C(  38),  INT8_C( 108),  INT8_C( 122),  INT8_C( 102),
        -INT8_C(  17), -INT8_C(  49),  INT8_C(  18), -INT8_C( 119),  INT8_C(  13), -INT8_C(  86), -INT8_C(  63), -INT8_C(  25),
        -INT8_C(  28),  INT8_C(  65), -INT8_C(  36), -INT8_C(  79),  INT8_C(  93), -INT8_C( 105),  INT8_C(  30),  INT8_C(  44),
         INT8_C(  30),  INT8_C(  53),  INT8_C(  55), -INT8_C(  62),  INT8_C( 112), -INT8_C( 112), -INT8_C(  44), -INT8_C(  33) },
      { -INT8_C(  10),  INT8_C(  52), -INT8_C( 103),  INT8_C(  28), -INT8_C(  20),  INT8_C(  19), -INT8_C( 126), -INT8_C(  37),
         INT8_C(  64), -INT8_C( 107),  INT8_C(  85), -INT8_C(  84), -INT8_C( 103),  INT8_C(  62), -INT8_C( 105),  INT8_C(  35),
         INT8_C( 103),  INT8_C(  58), -INT8_C(  44), -INT8_C(  60), -INT8_C(  52), -INT8_C(  14), -INT8_C(  70),  INT8_C( 109),
        -INT8_C(  50), -INT8_C( 121),  INT8_C(  23),  INT8_C(  11), -INT8_C(  73), -INT8_C(   1),  INT8_C(  89), -INT8_C(  82),
             INT8_MAX,  INT8_C(  16), -INT8_C(  85),  INT8_C( 107),  INT8_C(  36),  INT8_C(  77),  INT8_C(  70),  INT8_C(   6),
        -INT8_C(  30), -INT8_C(  85),  INT8_C(  18),  INT8_C(  33), -INT8_C(  48), -INT8_C(  86),  INT8_C(  68),  INT8_C(  55),
        -INT8_C(  28),  INT8_C(  25), -INT8_C(  36), -INT8_C(  79),  INT8_C(  11), -INT8_C(  20),  INT8_C(  50),  INT8_C(  51),
         INT8_C(  20),  INT8_C(  93), -INT8_C(  53), -INT8_C(  53),  INT8_C(  92),  INT8_C(  66),  INT8_C( 121), -INT8_C(  33) },
      UINT64_C(10745368769656978775) },
    { { -INT8_C(  80),  INT8_C(  41), -INT8_C(  22), -INT8_C(  45), -INT8_C(  81), -INT8_C(  76),  INT8_C(  47), -INT8_C(  87),
         INT8_C(  17), -INT8_C( 109), -INT8_C(  30),  INT8_C(  71),  INT8_C(  55), -INT8_C(  37),  INT8_C( 111),  INT8_C(  23),
         INT8_C(  93), -INT8_C( 109),  INT8_C(  31), -INT8_C( 102), -INT8_C(  24),  INT8_C( 100), -INT8_C(  17),  INT8_C(  57),
        -INT8_C(  79), -INT8_C(  71), -INT8_C(  55),      INT8_MIN, -INT8_C(  46), -INT8_C(  22),  INT8_C(  20), -INT8_C( 126),
         INT8_C(  19), -INT8_C(   2),  INT8_C(  86), -INT8_C(  61), -INT8_C(  78), -INT8_C( 123),  INT8_C( 108), -INT8_C(  60),
         INT8_C(  24),  INT8_C(  78),  INT8_C(  11),  INT8_C(  79),  INT8_C(  42),  INT8_C( 122),  INT8_C( 102), -INT8_C( 121),
         INT8_C(  14), -INT8_C( 123),  INT8_C(  34), -INT8_C(  10), -INT8_C(  22),  INT8_C(  17),  INT8_C(  48), -INT8_C( 101),
        -INT8_C(  54), -INT8_C(   7),  INT8_C(  27), -INT8_C(  99), -INT8_C(  29),  INT8_C(  47),  INT8_C(  31), -INT8_C(  10) },
      {  INT8_C(  46),  INT8_C( 117), -INT8_C(  71), -INT8_C(  32), -INT8_C(   6), -INT8_C(  76), -INT8_C(  92),  INT8_C(  18),
         INT8_C(  17), -INT8_C( 109),  INT8_C(  97),  INT8_C(  71),  INT8_C(  55), -INT8_C(  37),  INT8_C( 111),  INT8_C(  23),
         INT8_C(  77), -INT8_C( 109),  INT8_C(  31), -INT8_C( 102),  INT8_C(  89),  INT8_C( 100), -INT8_C(  46),  INT8_C(  35),
         INT8_C(  88), -INT8_C(  18), -INT8_C(  64),  INT8_C(  59), -INT8_C(  46), -INT8_C(  22),  INT8_C(  49),  INT8_C(  75),
         INT8_C(  85), -INT8_C(  21),  INT8_C(  44),  INT8_C(  80),  INT8_C(  16), -INT8_C(  48),  INT8_C(  98), -INT8_C( 124),
             INT8_MIN, -INT8_C(  60),  INT8_C(  34), -INT8_C(  85), -INT8_C( 117),  INT8_C(  72), -INT8_C(  29), -INT8_C(  40),
        -INT8_C( 113),  INT8_C(  18),  INT8_C(  15), -INT8_C(  24),  INT8_C( 113),  INT8_C(  17),  INT8_C(  12), -INT8_C( 101),
        -INT8_C(  48), -INT8_C(  52),  INT8_C(   4), -INT8_C(  19), -INT8_C(  84),  INT8_C(  54),  INT8_C(  31), -INT8_C(  10) },
      UINT64_C(15487170784818887524) },
    { { -INT8_C(  38), -INT8_C(  37), -INT8_C(  81),  INT8_C(   0), -INT8_C(  80), -INT8_C(  60), -INT8_C(  97),  INT8_C(  94),
         INT8_C(  58),  INT8_C(  65),  INT8_C(  44), -INT8_C(  11), -INT8_C(  64), -INT8_C(  86),  INT8_C(   6),  INT8_C(  43),
        -INT8_C(  64), -INT8_C(  32),  INT8_C( 100),  INT8_C( 123),  INT8_C(  76),  INT8_C(  59), -INT8_C(  89),  INT8_C(  79),
        -INT8_C(  98), -INT8_C(  15),  INT8_C(  30), -INT8_C(  59),  INT8_C(  90), -INT8_C(  38),  INT8_C(  21),  INT8_C(  52),
        -INT8_C(  74), -INT8_C(  59),  INT8_C(  53),  INT8_C( 102), -INT8_C( 119), -INT8_C(  44), -INT8_C(  60), -INT8_C(  60),
         INT8_C(  21), -INT8_C(  16), -INT8_C(  71), -INT8_C(  42), -INT8_C( 102), -INT8_C(  65),  INT8_C(   1),  INT8_C(  91),
        -INT8_C(  96),  INT8_C( 102), -INT8_C(  42), -INT8_C(  20), -INT8_C(  95),  INT8_C( 126),  INT8_C(  59),  INT8_C(  63),
         INT8_C( 111),  INT8_C(  89),  INT8_C(   4), -INT8_C(  55),  INT8_C(  52),  INT8_C(  26), -INT8_C(   3), -INT8_C(  22) },
      { -INT8_C(  33),  INT8_C(  50), -INT8_C(  81),  INT8_C( 104), -INT8_C(  80),  INT8_C(  21),  INT8_C(  44),  INT8_C(  28),
         INT8_C(   5), -INT8_C(  27), -INT8_C(  14), -INT8_C(  96), -INT8_C(  91), -INT8_C(  13), -INT8_C(   5),  INT8_C(  69),
        -INT8_C(  64), -INT8_C(  47),  INT8_C( 100), -INT8_C(   5),  INT8_C(  79),  INT8_C( 109),  INT8_C(  58), -INT8_C(  66),
        -INT8_C(  98),  INT8_C(  63), -INT8_C( 121), -INT8_C(   6),  INT8_C(  89), -INT8_C( 123),  INT8_C(  21),  INT8_C(  56),
        -INT8_C(  73), -INT8_C(  59), -INT8_C(  96), -INT8_C(  66),  INT8_C(  74), -INT8_C(  51), -INT8_C(  38), -INT8_C(  60),
         INT8_C(  21), -INT8_C(  52), -INT8_C(  17),  INT8_C(  87), -INT8_C(  65), -INT8_C(  65), -INT8_C( 100),  INT8_C(  25),
        -INT8_C(  68), -INT8_C(  50),  INT8_C(  20), -INT8_C(  20),  INT8_C(  59),  INT8_C(  78), -INT8_C(  54),  INT8_C(   1),
        -INT8_C( 115),  INT8_C(  81), -INT8_C(   4), -INT8_C(  26), -INT8_C(  42),  INT8_C(  26), -INT8_C(   3), -INT8_C( 114) },
      UINT64_C(17864341210354638740) },
    { { -INT8_C(  80), -INT8_C( 102),  INT8_C(  96), -INT8_C(  13), -INT8_C(  40), -INT8_C(  87),  INT8_C(  39), -INT8_C(  76),
        -INT8_C( 120),  INT8_C(  13),  INT8_C(  25), -INT8_C( 103), -INT8_C(  66), -INT8_C(  61), -INT8_C(  85),  INT8_C(  77),
        -INT8_C(  67), -INT8_C(   7),  INT8_C(   9), -INT8_C(  46), -INT8_C( 125),      INT8_MAX,  INT8_C(  83),  INT8_C(  71),
        -INT8_C( 105),  INT8_C(  23),  INT8_C(  36),  INT8_C( 110), -INT8_C(  85),  INT8_C(  48), -INT8_C(  61),  INT8_C(  91),
        -INT8_C(  54),  INT8_C(  35),  INT8_C(  78), -INT8_C(  94), -INT8_C(  52),  INT8_C( 118),  INT8_C(  86),  INT8_C(  84),
        -INT8_C( 125),  INT8_C( 111), -INT8_C(  18),  INT8_C(  65),  INT8_C(  50), -INT8_C( 103), -INT8_C( 114), -INT8_C(  16),
        -INT8_C( 110), -INT8_C( 105), -INT8_C(  62),  INT8_C(  22),  INT8_C(  23),  INT8_C(  22),  INT8_C(  93), -INT8_C(  82),
         INT8_C(  45), -INT8_C( 127),  INT8_C(  28), -INT8_C(  40), -INT8_C(  79), -INT8_C(  33),  INT8_C(  51),  INT8_C( 123) },
      {  INT8_C(   3), -INT8_C( 126),  INT8_C(  96), -INT8_C(  49), -INT8_C(  40),  INT8_C( 116),  INT8_C(  39), -INT8_C(  76),
        -INT8_C(  28),  INT8_C(  13),  INT8_C(  25),  INT8_C(  22), -INT8_C(  85),  INT8_C(  75),  INT8_C(   6),  INT8_C(  62),
        -INT8_C(  29), -INT8_C(   7),  INT8_C(  84), -INT8_C(   6), -INT8_C(  33), -INT8_C(  79), -INT8_C(  88),  INT8_C(  12),
         INT8_C(  50), -INT8_C(  60), -INT8_C(  28),  INT8_C( 110), -INT8_C(  93),  INT8_C(  23),  INT8_C(  94), -INT8_C(  90),
        -INT8_C( 103),  INT8_C(  35),  INT8_C( 118), -INT8_C( 111), -INT8_C(  15), -INT8_C( 102),  INT8_C(  13), -INT8_C(  43),
        -INT8_C(  84), -INT8_C(  54), -INT8_C(  21),  INT8_C(  65),  INT8_C(  50), -INT8_C(  14), -INT8_C( 107), -INT8_C(   8),
        -INT8_C(  69), -INT8_C( 105), -INT8_C(  14), -INT8_C( 102), -INT8_C( 102), -INT8_C( 102), -INT8_C(  90), -INT8_C(  82),
         INT8_C(  45), -INT8_C( 118),  INT8_C(  28), -INT8_C(  40), -INT8_C(  95), -INT8_C(  33), -INT8_C(  88),  INT8_C(  59) },
      UINT64_C(18300974033642100446) },
    { { -INT8_C(  88),  INT8_C(  67),  INT8_C(  46), -INT8_C(  35), -INT8_C(   7), -INT8_C(  79), -INT8_C(  74), -INT8_C(  21),
        -INT8_C(  16),  INT8_C(  72),  INT8_C(  11),      INT8_MIN, -INT8_C( 116),  INT8_C(  20),  INT8_C(  76),  INT8_C( 115),
        -INT8_C(  96), -INT8_C(  19), -INT8_C( 103),  INT8_C(  85),  INT8_C(  48),  INT8_C(  92), -INT8_C(  67), -INT8_C(  60),
        -INT8_C(  66),  INT8_C( 122), -INT8_C(  72),  INT8_C( 104), -INT8_C(  58), -INT8_C( 106),  INT8_C( 119),  INT8_C( 110),
        -INT8_C(  38), -INT8_C(  91),  INT8_C(  75), -INT8_C(  45),  INT8_C(  86),  INT8_C(   2), -INT8_C(  65),  INT8_C(  70),
         INT8_C(  74), -INT8_C(  54), -INT8_C(  57), -INT8_C(  42), -INT8_C(  33),  INT8_C(  19),  INT8_C(  74),      INT8_MAX,
         INT8_C(   0), -INT8_C(  29), -INT8_C(  43),  INT8_C(  48),  INT8_C(  64), -INT8_C( 110), -INT8_C(  12), -INT8_C(   2),
         INT8_C(  12), -INT8_C(  83),  INT8_C( 102), -INT8_C(  46),  INT8_C(  67), -INT8_C(  34),  INT8_C(  64),  INT8_C(  29) },
      { -INT8_C( 125), -INT8_C( 116),  INT8_C(  46), -INT8_C(  35), -INT8_C( 114), -INT8_C(  80), -INT8_C(  74), -INT8_C(  40),
        -INT8_C(  16), -INT8_C(  25), -INT8_C(  81),  INT8_C(  89), -INT8_C(   6), -INT8_C(   7), -INT8_C(  39), -INT8_C(   6),
        -INT8_C(  96), -INT8_C(  82), -INT8_C( 103),  INT8_C(  28),  INT8_C(  64),  INT8_C(  31),  INT8_C(  27),  INT8_C(  77),
        -INT8_C(  66), -INT8_C( 127),  INT8_C(  31),  INT8_C(  15),  INT8_C(  95),  INT8_C(  96),  INT8_C( 119),  INT8_C( 110),
        -INT8_C(  20), -INT8_C(  91),  INT8_C(  75),  INT8_C( 122), -INT8_C(  50),  INT8_C(   2), -INT8_C(  65),  INT8_C(  72),
        -INT8_C(  59),  INT8_C(   1), -INT8_C(  94), -INT8_C(  42), -INT8_C(   6),  INT8_C( 123), -INT8_C(  70), -INT8_C(  41),
         INT8_C(   0), -INT8_C(  28), -INT8_C(  43),  INT8_C( 105),  INT8_C(   3),  INT8_C(  14), -INT8_C(  74), -INT8_C(  49),
        -INT8_C( 112), -INT8_C(  42),  INT8_C( 102), -INT8_C(  17),  INT8_C(  54),  INT8_C(  12), -INT8_C(  46),  INT8_C(  29) },
      UINT64_C(15408447610216769535) },
    { { -INT8_C( 127), -INT8_C(  33), -INT8_C(  42), -INT8_C(  32), -INT8_C( 112),  INT8_C(  26),  INT8_C(  47),  INT8_C(  35),
         INT8_C(  80),  INT8_C( 105),  INT8_C(  19),  INT8_C(  49),  INT8_C( 100), -INT8_C( 118), -INT8_C(  94),  INT8_C(  20),
        -INT8_C(  15), -INT8_C(  90), -INT8_C( 121), -INT8_C(   1),  INT8_C(  14),  INT8_C(  78), -INT8_C( 119), -INT8_C(  73),
         INT8_C(  88), -INT8_C(  59), -INT8_C(  81),  INT8_C( 120), -INT8_C(  42),  INT8_C(  30),  INT8_C(  60),  INT8_C(  88),
        -INT8_C(   2),  INT8_C(  19),  INT8_C(  56), -INT8_C( 114),  INT8_C(  45),  INT8_C( 104), -INT8_C(  79),  INT8_C( 125),
        -INT8_C(  47), -INT8_C(  60), -INT8_C(  82),  INT8_C(  53),  INT8_C(  79),  INT8_C(  80),  INT8_C(  73),  INT8_C(  64),
        -INT8_C(   9), -INT8_C(  48),  INT8_C(  63),  INT8_C(   5),  INT8_C(  31), -INT8_C(  56), -INT8_C(  68),  INT8_C( 119),
        -INT8_C( 114),  INT8_C( 107), -INT8_C(  17),  INT8_C( 100), -INT8_C( 118),  INT8_C(  44), -INT8_C(  68), -INT8_C( 120) },
      { -INT8_C( 127), -INT8_C(  33),  INT8_C(  22), -INT8_C(  32), -INT8_C( 112),  INT8_C(  26), -INT8_C(  22),  INT8_C(  46),
        -INT8_C( 117), -INT8_C( 104),  INT8_C(  99), -INT8_C(  38), -INT8_C(  23), -INT8_C( 118),  INT8_C(  27), -INT8_C(  32),
         INT8_C( 124), -INT8_C(  90), -INT8_C( 121), -INT8_C( 101),  INT8_C(  14),  INT8_C(  78),  INT8_C(  19), -INT8_C(  79),
         INT8_C(  13),  INT8_C(   2), -INT8_C(  81),  INT8_C( 120),  INT8_C(  46), -INT8_C(  46),  INT8_C(  31),  INT8_C( 109),
        -INT8_C(  57),  INT8_C(  19), -INT8_C(  38),  INT8_C(  36),  INT8_C(  45), -INT8_C(  60), -INT8_C(  79), -INT8_C( 121),
         INT8_C(  92), -INT8_C(  75),  INT8_C(  98),  INT8_C(  69),  INT8_C(  97),  INT8_C( 125),  INT8_C(  73), -INT8_C(  35),
        -INT8_C(  41), -INT8_C(  48),  INT8_C(  63), -INT8_C(   6),  INT8_C(  31), -INT8_C( 116), -INT8_C(  85), -INT8_C(  71),
        -INT8_C( 114), -INT8_C(  63),  INT8_C(  80), -INT8_C(  67), -INT8_C( 109),  INT8_C( 111), -INT8_C(  68), -INT8_C( 120) },
      UINT64_C(14699682076714515323) },
    { { -INT8_C(  13),  INT8_C( 126), -INT8_C(  85),  INT8_C( 115), -INT8_C(  88), -INT8_C(  36),  INT8_C( 120),  INT8_C(  92),
         INT8_C( 119),  INT8_C(  99),  INT8_C(  22), -INT8_C(  94),  INT8_C(  18), -INT8_C(  82),  INT8_C( 103), -INT8_C(   3),
         INT8_C(  30),  INT8_C( 115), -INT8_C(  80),  INT8_C(  19),      INT8_MAX, -INT8_C(  69),  INT8_C(  76), -INT8_C(  38),
        -INT8_C(  39),  INT8_C(  94), -INT8_C(  13),  INT8_C(  54), -INT8_C(  95),  INT8_C( 111), -INT8_C(  42), -INT8_C( 107),
        -INT8_C(  18), -INT8_C( 126),  INT8_C(   8), -INT8_C( 106),  INT8_C(  94), -INT8_C( 127), -INT8_C(  14), -INT8_C(  43),
        -INT8_C(  28),  INT8_C(   8),  INT8_C( 119), -INT8_C(  10), -INT8_C(  74), -INT8_C(  34), -INT8_C(  13), -INT8_C(  43),
         INT8_C(  82), -INT8_C(  92), -INT8_C(  24), -INT8_C(  47),  INT8_C(  95),  INT8_C(  52), -INT8_C(  85),  INT8_C(  56),
        -INT8_C( 110), -INT8_C(  98),  INT8_C( 111),  INT8_C(  52),  INT8_C(  14),  INT8_C(  69), -INT8_C(  55), -INT8_C(   4) },
      { -INT8_C(  57), -INT8_C(  47), -INT8_C( 110),  INT8_C(  37),  INT8_C(  82), -INT8_C( 123), -INT8_C(   6),  INT8_C(  55),
        -INT8_C( 115),  INT8_C(  99),  INT8_C(  45),  INT8_C(  68),  INT8_C(  80),  INT8_C(  33),  INT8_C(  25), -INT8_C(  94),
        -INT8_C(  59),  INT8_C(   1),  INT8_C( 115),  INT8_C(  36),  INT8_C(  53), -INT8_C(  69),  INT8_C(  92), -INT8_C(  56),
        -INT8_C(  68), -INT8_C(  53), -INT8_C(   4), -INT8_C(  54),  INT8_C(  17), -INT8_C(  59), -INT8_C(  58), -INT8_C(  40),
        -INT8_C( 106),  INT8_C(  89),  INT8_C(   8), -INT8_C(  23), -INT8_C(  34), -INT8_C(   8),  INT8_C(  32),  INT8_C( 107),
         INT8_C( 106),  INT8_C(  77), -INT8_C(  81), -INT8_C(  70),  INT8_C( 110), -INT8_C(  34),  INT8_C(  92),  INT8_C(  51),
        -INT8_C(  55), -INT8_C(  49), -INT8_C(  24), -INT8_C(   1), -INT8_C(  19), -INT8_C(  76), -INT8_C(  57), -INT8_C(  87),
             INT8_MAX, -INT8_C(  61),  INT8_C( 116), -INT8_C( 112), -INT8_C( 120),  INT8_C(  69),  INT8_C( 105), -INT8_C(   4) },
      UINT64_C(13309592744276247535) },
    { {  INT8_C(  82),  INT8_C(  73),  INT8_C(  82), -INT8_C(  49),  INT8_C(  31),  INT8_C( 125), -INT8_C(  63), -INT8_C( 127),
         INT8_C(  44), -INT8_C( 106),  INT8_C(  56), -INT8_C(  69), -INT8_C( 125),  INT8_C(  13), -INT8_C(   8), -INT8_C(  34),
         INT8_C(   0), -INT8_C(  48),  INT8_C(  91), -INT8_C(  40), -INT8_C(  18),  INT8_C( 123),  INT8_C(  87), -INT8_C(  60),
        -INT8_C(  51),  INT8_C(   5), -INT8_C( 114), -INT8_C(  70),  INT8_C(   2), -INT8_C(  33), -INT8_C(  86),  INT8_C(  84),
         INT8_C(  41), -INT8_C(   4),  INT8_C(  35),  INT8_C(  72),  INT8_C( 122), -INT8_C(  28), -INT8_C(  55), -INT8_C(  90),
         INT8_C( 122),  INT8_C(   1),  INT8_C(  97), -INT8_C(   3),  INT8_C(  14),  INT8_C(  89), -INT8_C(  37),  INT8_C(  15),
         INT8_C(  42),  INT8_C(  55), -INT8_C(  25),  INT8_C(  24), -INT8_C(  78),  INT8_C(  62), -INT8_C(  36),      INT8_MAX,
         INT8_C(  67),  INT8_C( 107),  INT8_C(  57),  INT8_C(  69),  INT8_C(  74), -INT8_C(  28), -INT8_C( 103),  INT8_C( 115) },
      { -INT8_C(  32),  INT8_C(  73), -INT8_C(  69),  INT8_C(  90), -INT8_C(  96), -INT8_C( 124),  INT8_C(   1),  INT8_C(  27),
        -INT8_C( 123), -INT8_C( 106),  INT8_C(  24), -INT8_C(  69), -INT8_C( 125),  INT8_C(  13), -INT8_C(  93), -INT8_C(  26),
         INT8_C(   0), -INT8_C( 118),  INT8_C(  91), -INT8_C(  35), -INT8_C(  18), -INT8_C(  38),  INT8_C(  92), -INT8_C(  60),
        -INT8_C(  51), -INT8_C( 107),  INT8_C(  81), -INT8_C( 112),  INT8_C( 121), -INT8_C(  22),  INT8_C(   3),  INT8_C(  84),
        -INT8_C(  89), -INT8_C(   4), -INT8_C(  76),  INT8_C(  71),  INT8_C(  67), -INT8_C(  75),  INT8_C(  98), -INT8_C(  55),
         INT8_C(  24),  INT8_C( 123),  INT8_C(  93), -INT8_C(  44),  INT8_C( 111),  INT8_C(   0), -INT8_C(  70), -INT8_C( 102),
        -INT8_C( 118), -INT8_C(  72),  INT8_C( 119),  INT8_C(  82), -INT8_C( 110), -INT8_C(  45),  INT8_C(  93), -INT8_C(  40),
         INT8_C(  67), -INT8_C(  82),  INT8_C( 104), -INT8_C(  30),  INT8_C(  74),  INT8_C( 107),  INT8_C(  60),  INT8_C(  64) },
      UINT64_C(11219571953892818743) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i a = simde_mm512_loadu_epi8(test_vec[i].a);
    simde__m512i b = simde_mm512_loadu_epi8(test_vec[i].b);
    simde__mmask64 r = simde_mm512_cmpge_epi8_mask(a, b);
    simde_assert_equal_mmask64(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    int8_t a_[64];
    int8_t b_[64];

    simde_test_codegen_random_memory(sizeof(a_), HEDLEY_REINTERPRET_CAST(uint8_t*, a_));
    simde_test_codegen_random_memory(sizeof(b_), HEDLEY_REINTERPRET_CAST(uint8_t*, b_));
    for (size_t j = 0 ; j < (sizeof(a_) / sizeof(a_[0])) ; j++)
      if ((simde_test_codegen_rand() & 3) == 0)
        b_[j] = a_[j];

    simde__m512i a = simde_mm512_loadu_epi8(a_);
    simde__m512i b = simde_mm512_loadu_epi8(b_);
    simde__mmask64 r = simde_mm512_cmpge_epi8_mask(a, b);

    simde_test_x86_write_i8x64(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i8x64(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask64(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_mask_cmpge_epi8_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask64 k;
    const int8_t a[64];
    const int8_t b[64];
    const simde__mmask64 r;
  } test_vec[] = {
    { UINT64_C( 3683588123492366466),
      {  INT8_C(  87), -INT8_C(  39),  INT8_C( 112),  INT8_C(  30), -INT8_C(  21),  INT8_C(   3),  INT8_C(  73), -INT8_C( 112),
         INT8_C(  40),  INT8_C(  73), -INT8_C(  54), -INT8_C( 103), -INT8_C(  74),  INT8_C(  33),  INT8_C(  14),  INT8_C(   9),
        -INT8_C(  23),  INT8_C(  25),  INT8_C(  19),  INT8_C( 126), -INT8_C( 109),  INT8_C(  62), -INT8_C( 113), -INT8_C(  28),
         INT8_C( 108), -INT8_C(  75),  INT8_C( 118), -INT8_C(  40),  INT8_C(  48),  INT8_C( 117),  INT8_C( 115), -INT8_C( 121),
         INT8_C(  79), -INT8_C(  29), -INT8_C(  91),  INT8_C(  58), -INT8_C(  26), -INT8_C(  17), -INT8_C(  54),  INT8_C(  14),
         INT8_C(  56), -INT8_C( 108), -INT8_C(  89), -INT8_C(  18), -INT8_C(  74), -INT8_C(  75), -INT8_C(   9), -INT8_C(  97),
        -INT8_C(  50),  INT8_C(  11),  INT8_C(  29),  INT8_C(  98),  INT8_C(  73), -INT8_C(  84),  INT8_C(  70), -INT8_C(  75),
         INT8_C(  97), -INT8_C(  68), -INT8_C( 115), -INT8_C( 111),  INT8_C(  50),  INT8_C(   0),  INT8_C(  24), -INT8_C( 127) },
      { -INT8_C(  29), -INT8_C(  66), -INT8_C(  69),  INT8_C(  30), -INT8_C(  83), -INT8_C( 123),  INT8_C(  73), -INT8_C(  27),
         INT8_C(  26),  INT8_C(  73), -INT8_C(  45), -INT8_C( 103),  INT8_C(  51), -INT8_C(  53),  INT8_C( 111),  INT8_C(   2),
        -INT8_C(  42), -INT8_C( 116),  INT8_C( 100),  INT8_C(  31),  INT8_C(  56), -INT8_C(  86), -INT8_C(  43), -INT8_C( 103),
         INT8_C( 102),  INT8_C(  98),  INT8_C( 118), -INT8_C(  40),  INT8_C(  99),  INT8_C(  66),  INT8_C(  25), -INT8_C( 121),
         INT8_C(   0), -INT8_C(  44), -INT8_C(  91), -INT8_C(  83), -INT8_C(  26), -INT8_C(  25), -INT8_C( 110),  INT8_C( 116),
         INT8_C( 102),  INT8_C( 102),  INT8_C(  68), -INT8_C( 103),  INT8_C(  49), -INT8_C(  77), -INT8_C( 101),  INT8_C(   7),
        -INT8_C(  50), -INT8_C(   1),  INT8_C(  29),  INT8_C( 119), -INT8_C(  87), -INT8_C(   5),  INT8_C(  70),  INT8_C(  16),
         INT8_C(  94), -INT8_C(  68), -INT8_C(  88), -INT8_C( 111),  INT8_C( 124), -INT8_C(  62),  INT8_C(  24),  INT8_C( 125) },
      UINT64_C( 2528252640803432450) },
    { UINT64_C(12957502087676957823),
      { -INT8_C(  39), -INT8_C(  46), -INT8_C(  32), -INT8_C( 112), -INT8_C(  32),  INT8_C(  39), -INT8_C(  31),  INT8_C( 112),
             INT8_MIN,  INT8_C( 117),  INT8_C( 125), -INT8_C(   5),  INT8_C(  92),  INT8_C( 101), -INT8_C(  47),  INT8_C(  63),
        -INT8_C(  23),      INT8_MAX, -INT8_C(  33),  INT8_C(  17), -INT8_C( 126), -INT8_C(  45), -INT8_C(  13),  INT8_C(   4),
         INT8_C(  11), -INT8_C( 112), -INT8_C(  61), -INT8_C(  19),  INT8_C(  75), -INT8_C(  30),  INT8_C(  32),  INT8_C(  36),
        -INT8_C(  76),  INT8_C(   0), -INT8_C(  75), -INT8_C( 108),  INT8_C(  39), -INT8_C( 106),  INT8_C(   5), -INT8_C(  88),
         INT8_C(  12), -INT8_C( 126), -INT8_C(  93),  INT8_C( 104), -INT8_C(  24),  INT8_C( 116), -INT8_C(  89), -INT8_C(  47),
        -INT8_C(  13), -INT8_C( 122), -INT8_C(  30),  INT8_C( 117),  INT8_C(  89), -INT8_C(  42),  INT8_C( 121),  INT8_C( 101),
         INT8_C( 102),  INT8_C(  61),  INT8_C(  82), -INT8_C(  79),  INT8_C(  31),  INT8_C( 114), -INT8_C(  42), -INT8_C(  45) },
      {  INT8_C( 114), -INT8_C( 117),  INT8_C( 103), -INT8_C( 103),  INT8_C(  33),  INT8_C( 108),  INT8_C(  65),  INT8_C(  45),
        -INT8_C(  17), -INT8_C(  28), -INT8_C( 106), -INT8_C(  41),  INT8_C(  92),  INT8_C(  61), -INT8_C(  88),  INT8_C(  75),
        -INT8_C(  60), -INT8_C( 117), -INT8_C(  64),  INT8_C(  17),  INT8_C(  97),  INT8_C(  58), -INT8_C( 126), -INT8_C(  57),
         INT8_C(  11), -INT8_C(  44),  INT8_C( 120), -INT8_C( 106),  INT8_C(  70),  INT8_C(  78),  INT8_C(  32), -INT8_C(  72),
        -INT8_C(  39), -INT8_C(  48),  INT8_C(  82), -INT8_C( 108),  INT8_C(  61), -INT8_C( 109),  INT8_C(  40),  INT8_C(  44),
         INT8_C(  12), -INT8_C(  66),  INT8_C(   3),  INT8_C( 104), -INT8_C(  24),  INT8_C( 116),  INT8_C(  28), -INT8_C(  64),
         INT8_C(  54), -INT8_C(  36), -INT8_C(  35), -INT8_C( 105),  INT8_C(  22), -INT8_C(  42),  INT8_C( 121), -INT8_C( 115),
         INT8_C(  52), -INT8_C(  41),  INT8_C(  82), -INT8_C(  79),  INT8_C(  37), -INT8_C( 116),  INT8_C(  51), -INT8_C(   1) },
      UINT64_C( 2580572662884340738) },
    { UINT64_C( 6384507260715537604),
      { -INT8_C( 102),  INT8_C(  73),  INT8_C(  91),  INT8_C( 102),  INT8_C(  93), -INT8_C(  81), -INT8_C( 116), -INT8_C(  20),
         INT8_C(  69),  INT8_C(  34),  INT8_C(  85),  INT8_C( 124), -INT8_C(  73), -INT8_C(  51),  INT8_C(  43),  INT8_C( 109),
        -INT8_C(  49),  INT8_C( 119), -INT8_C(  47), -INT8_C( 114),  INT8_C(  96),  INT8_C(  64), -INT8_C( 111), -INT8_C(  32),
         INT8_C(  84), -INT8_C(  17),  INT8_C(  24), -INT8_C(  45),  INT8_C(  59), -INT8_C(  21), -INT8_C( 122), -INT8_C(  43),
         INT8_C(  52), -INT8_C(  31),  INT8_C(  59), -INT8_C( 110), -INT8_C( 112), -INT8_C(  57),  INT8_C( 126), -INT8_C(  43),
        -INT8_C(  23), -INT8_C(  45),  INT8_C(  81), -INT8_C(  96), -INT8_C(  96),  INT8_C( 124),  INT8_C(  13),  INT8_C( 111),
        -INT8_C(  12), -INT8_C(  34), -INT8_C(   3),  INT8_C(  84),  INT8_C(  30), -INT8_C( 114),  INT8_C(  52),  INT8_C( 114),
         INT8_C( 126),  INT8_C(  77),  INT8_C(  69), -INT8_C(  71),  INT8_C(  56), -INT8_C(  53), -INT8_C( 114),  INT8_C( 108) },
      { -INT8_C(  83), -INT8_C(  55), -INT8_C(   2),  INT8_C(  61), -INT8_C( 112),  INT8_C( 124),  INT8_C(  19), -INT8_C(  20),
         INT8_C(  79),  INT8_C( 100),  INT8_C(  26), -INT8_C(  17), -INT8_C(  31),  INT8_C(  39),  INT8_C(  43), -INT8_C(  43),
         INT8_C(   6),  INT8_C(  92),  INT8_C(  41), -INT8_C( 114), -INT8_C(  22),  INT8_C(  94), -INT8_C( 105), -INT8_C(  32),
        -INT8_C(  85), -INT8_C(  17),  INT8_C(  33), -INT8_C(  29), -INT8_C(  88), -INT8_C(  21),  INT8_C(  79), -INT8_C(  43),
         INT8_C( 120), -INT8_C(  31), -INT8_C( 110), -INT8_C( 110), -INT8_C(  54), -INT8_C(  91),  INT8_C( 126),  INT8_C(  26),
         INT8_C(  10), -INT8_C(  45),  INT8_C(   9), -INT8_C(  21), -INT8_C(  61),  INT8_C( 104),  INT8_C(  13),  INT8_C( 111),
        -INT8_C(  60), -INT8_C(  34), -INT8_C(  18), -INT8_C(  82),  INT8_C(  71), -INT8_C( 114),  INT8_C(  23), -INT8_C(  14),
         INT8_C( 126),  INT8_C(  77),  INT8_C(  69),  INT8_C(   9), -INT8_C(  24), -INT8_C(  53),  INT8_C(  94),  INT8_C(  96) },
      UINT64_C( 1191837647624602756) },
    { UINT64_C(15288418247558423895),
      {  INT8_C(  87), -INT8_C( 109), -INT8_C(  12), -INT8_C(  90), -INT8_C(  96),  INT8_C(  28),  INT8_C(  43), -INT8_C(  81),
             INT8_MIN,  INT8_C(  44),  INT8_C(  69),  INT8_C(  55), -INT8_C( 100), -INT8_C(  60),  INT8_C( 120),  INT8_C(  80),
         INT8_C(  52),  INT8_C(  45),  INT8_C( 110), -INT8_C(  11), -INT8_C(  75),  INT8_C( 105), -INT8_C(   8),  INT8_C( 121),
         INT8_C( 125), -INT8_C(  46),  INT8_C( 101),  INT8_C(   3),  INT8_C(  37),  INT8_C(   0),  INT8_C(  92),  INT8_C( 124),
        -INT8_C( 109),  INT8_C(  80),  INT8_C(  35),  INT8_C(  52),  INT8_C( 108),  INT8_C(  78), -INT8_C(  29), -INT8_C(  19),
         INT8_C( 122),  INT8_C(  41),  INT8_C(  36),  INT8_C(  22), -INT8_C(  19), -INT8_C( 100),  INT8_C( 102),  INT8_C(  33),
        -INT8_C(  55), -INT8_C(  43),  INT8_C(  23),  INT8_C( 126),  INT8_C(  62),  INT8_C(  15), -INT8_C(   8), -INT8_C(  69),
        -INT8_C(  31),  INT8_C(  93), -INT8_C(  65),  INT8_C(   7),  INT8_C(  93),  INT8_C(  27), -INT8_C( 125), -INT8_C(  15) },
      {  INT8_C( 107), -INT8_C(  90),  INT8_C(  37), -INT8_C(  90), -INT8_C(  12),  INT8_C(  28),  INT8_C(  43), -INT8_C(  81),
             INT8_MIN, -INT8_C(  24),  INT8_C(  69),  INT8_C(  30), -INT8_C( 123), -INT8_C(  21),  INT8_C(  64),  INT8_C(  78),
        -INT8_C(  64),  INT8_C(  87), -INT8_C(  51), -INT8_C(   2),  INT8_C( 102), -INT8_C(  59), -INT8_C(  71),  INT8_C(  71),
         INT8_C(  34),  INT8_C( 120),  INT8_C(  78),      INT8_MIN, -INT8_C( 109),  INT8_C(   0),  INT8_C( 113), -INT8_C(   2),
         INT8_C( 120), -INT8_C( 106), -INT8_C(  42),  INT8_C( 109),  INT8_C( 108),  INT8_C(  78), -INT8_C(  37), -INT8_C(  19),
        -INT8_C( 125),  INT8_C(  96),  INT8_C(  36),  INT8_C(  22),  INT8_C(  75),  INT8_C(  46),  INT8_C(  86),  INT8_C(  11),
        -INT8_C( 123),  INT8_C(  35),  INT8_C(   9),  INT8_C( 126), -INT8_C(  24),  INT8_C(  15),  INT8_C(  51),  INT8_C(  11),
         INT8_C(  59),  INT8_C(  93), -INT8_C( 117), -INT8_C(  50),  INT8_C(  83), -INT8_C(   4), -INT8_C(  51), -INT8_C(  15) },
      UINT64_C(10676149483638736192) },
    { UINT64_C( 5783730621706696781),
      {  INT8_C(  53),  INT8_C(  15),  INT8_C(  96),  INT8_C(  42), -INT8_C(  66), -INT8_C( 112),  INT8_C(  97),  INT8_C(  64),
         INT8_C(  78), -INT8_C(  60),  INT8_C(  88), -INT8_C(  51),  INT8_C(  92),  INT8_C(  65), -INT8_C( 112), -INT8_C(  74),
        -INT8_C(  55), -INT8_C(  23), -INT8_C(  52), -INT8_C(  66), -INT8_C(  92),  INT8_C(  50), -INT8_C(  61), -INT8_C(   5),
         INT8_C(  23),  INT8_C(  20),  INT8_C(   2),  INT8_C( 124),  INT8_C( 115),  INT8_C(  46),  INT8_C(  80), -INT8_C(  88),
         INT8_C(  61), -INT8_C(  80), -INT8_C(  46), -INT8_C(   5),  INT8_C(  64),  INT8_C(  52),  INT8_C(  59), -INT8_C( 114),
        -INT8_C(   8), -INT8_C( 109),  INT8_C(  92),  INT8_C(  84), -INT8_C(  44), -INT8_C(  20),  INT8_C(  10), -INT8_C(  98),
        -INT8_C(  43), -INT8_C(  41),  INT8_C(  92),  INT8_C( 121),  INT8_C(   9),  INT8_C(  31),  INT8_C( 117),  INT8_C(  32),
         INT8_C(  52),  INT8_C( 119), -INT8_C( 100), -INT8_C(  89), -INT8_C(  91), -INT8_C(  20),  INT8_C(  80), -INT8_C(  29) },
      { -INT8_C( 100),  INT8_C(  34), -INT8_C(  34), -INT8_C(  35),  INT8_C(  86), -INT8_C( 112),  INT8_C( 107),  INT8_C(  78),
        -INT8_C(  83), -INT8_C(  57), -INT8_C(  93), -INT8_C( 126),  INT8_C(  92), -INT8_C(  83),  INT8_C(  32), -INT8_C(  74),
        -INT8_C( 124),  INT8_C( 124),  INT8_C(   2), -INT8_C( 115), -INT8_C( 100),  INT8_C( 119), -INT8_C(  83), -INT8_C(  48),
        -INT8_C(  18),  INT8_C(  73),  INT8_C(   2),  INT8_C( 124),  INT8_C(  53),  INT8_C(  46),  INT8_C( 119), -INT8_C(  46),
        -INT8_C(  22),  INT8_C(  85), -INT8_C(  81),  INT8_C(  64),  INT8_C( 111),  INT8_C(  26),  INT8_C(  59), -INT8_C( 114),
        -INT8_C(  30),  INT8_C(  50), -INT8_C(  97), -INT8_C( 107), -INT8_C(  44), -INT8_C(  65),  INT8_C(  30),  INT8_C( 100),
         INT8_C(  59),  INT8_C(  32), -INT8_C(  15),  INT8_C( 121),  INT8_C(   9), -INT8_C(  97), -INT8_C(  89), -INT8_C( 123),
        -INT8_C(  24),  INT8_C(  31),  INT8_C(  25),  INT8_C(  30), -INT8_C(  26), -INT8_C( 112), -INT8_C(  16), -INT8_C(  48) },
      UINT64_C( 4629753473158625293) },
    { UINT64_C(  708416538020962542),
      { -INT8_C(  78), -INT8_C(  39),  INT8_C(  22), -INT8_C(  62), -INT8_C( 124), -INT8_C(  25),  INT8_C(  66),  INT8_C(  54),
        -INT8_C( 100), -INT8_C(  57), -INT8_C( 114), -INT8_C(  36), -INT8_C(  40),  INT8_C( 116), -INT8_C(  58), -INT8_C( 114),
         INT8_C(   7),  INT8_C(  65),  INT8_C( 122),  INT8_C(  55),  INT8_C(  28), -INT8_C( 127), -INT8_C(  94),  INT8_C( 106),
        -INT8_C(   7),  INT8_C(   2), -INT8_C(  55),  INT8_C(  84), -INT8_C(  14),  INT8_C(  13), -INT8_C(  91), -INT8_C(  92),
        -INT8_C(  26), -INT8_C(  69),  INT8_C( 103),  INT8_C( 106), -INT8_C(  94), -INT8_C(  87), -INT8_C(  96),  INT8_C(  63),
         INT8_C( 112),  INT8_C(  46),  INT8_C(  27),  INT8_C(  73), -INT8_C(  94), -INT8_C(  30), -INT8_C(  41), -INT8_C(  86),
         INT8_C(  35),  INT8_C(  81), -INT8_C(  31),  INT8_C(  63), -INT8_C(  46), -INT8_C( 125), -INT8_C(  87), -INT8_C(  53),
        -INT8_C( 123),  INT8_C( 115),  INT8_C(  32),  INT8_C( 119),      INT8_MIN, -INT8_C(  59),  INT8_C(  28),  INT8_C( 102) },
      { -INT8_C(  78), -INT8_C(  39),  INT8_C(  22), -INT8_C(  62),  INT8_C(  44),  INT8_C( 112),  INT8_C(  97),  INT8_C(  54),
        -INT8_C(  98), -INT8_C(  57), -INT8_C(  27), -INT8_C(  36),  INT8_C(  95), -INT8_C(  67), -INT8_C(  22), -INT8_C( 126),
         INT8_C(  14),  INT8_C(  65), -INT8_C(  63), -INT8_C(  31),  INT8_C(  78),  INT8_C( 107), -INT8_C(  94), -INT8_C(  45),
        -INT8_C(  34),  INT8_C(   2),  INT8_C(  75),  INT8_C(  94), -INT8_C(  14),  INT8_C( 103), -INT8_C(  91), -INT8_C(  92),
        -INT8_C(  22), -INT8_C(  69),  INT8_C( 103),  INT8_C( 106),  INT8_C(   4), -INT8_C( 107), -INT8_C(  78), -INT8_C(  94),
         INT8_C(  18), -INT8_C( 104), -INT8_C(  30),  INT8_C(  73), -INT8_C(  94), -INT8_C(  51), -INT8_C(  13),  INT8_C(  99),
        -INT8_C( 104), -INT8_C(  75),  INT8_C(  68), -INT8_C(  25),  INT8_C(  32), -INT8_C(  15), -INT8_C(  70), -INT8_C(  53),
        -INT8_C(  67),  INT8_C(   5),  INT8_C(  92),  INT8_C(  79),  INT8_C( 108),  INT8_C(  32),  INT8_C(  96),  INT8_C(  86) },
      UINT64_C(  612503870920204430) },
    { UINT64_C( 8380881417213229152),
      { -INT8_C( 120),  INT8_C(  46),  INT8_C(   6), -INT8_C(  28), -INT8_C(   8), -INT8_C(  92), -INT8_C( 105),  INT8_C( 118),
        -INT8_C(  52), -INT8_C(  63), -INT8_C( 103),  INT8_C(  55),  INT8_C(  95),  INT8_C(  31), -INT8_C(  21), -INT8_C(  51),
         INT8_C(  86),  INT8_C(  84),  INT8_C(  44), -INT8_C(  97), -INT8_C(  54),  INT8_C(  48), -INT8_C( 114), -INT8_C(  72),
        -INT8_C( 112),  INT8_C(  78),  INT8_C(  61), -INT8_C(  90),  INT8_C(  27),  INT8_C(  17), -INT8_C(  80), -INT8_C(  93),
         INT8_C(  64), -INT8_C(  74), -INT8_C( 120),  INT8_C(  56),  INT8_C(  90),  INT8_C(  31), -INT8_C(  81),  INT8_C(  38),
        -INT8_C(  32),  INT8_C(  72),  INT8_C(  93),  INT8_C(  63),  INT8_C( 103),  INT8_C(  72),  INT8_C(  13), -INT8_C(  67),
        -INT8_C(  99),  INT8_C(  57),  INT8_C(  92),  INT8_C( 103),  INT8_C( 105), -INT8_C(  21),  INT8_C(  31), -INT8_C(   7),
         INT8_C(  57),  INT8_C(  92), -INT8_C(  96),  INT8_C(  85),  INT8_C( 110),  INT8_C(  80), -INT8_C(   8), -INT8_C(  82) },
      {  INT8_C(   6),      INT8_MIN, -INT8_C(  26),  INT8_C(  96), -INT8_C(  96), -INT8_C( 107), -INT8_C( 121),  INT8_C( 118),
        -INT8_C(  52), -INT8_C(  28), -INT8_C(  64),  INT8_C(  55),  INT8_C(  95), -INT8_C(  51),  INT8_C(   3), -INT8_C(  54),
         INT8_C(   6),  INT8_C(  84),  INT8_C(  49),  INT8_C( 112),  INT8_C(  74),  INT8_C(  48),  INT8_C( 105), -INT8_C(  72),
        -INT8_C(  84),  INT8_C(   9), -INT8_C(  39),  INT8_C(  26),  INT8_C(  27), -INT8_C(  47), -INT8_C(  56),  INT8_C(  95),
         INT8_C(  82), -INT8_C(  81), -INT8_C( 120),  INT8_C(  56),  INT8_C(  68),  INT8_C(  71), -INT8_C(  81),  INT8_C(  34),
         INT8_C(  43),  INT8_C(  50),  INT8_C( 104),  INT8_C(  88), -INT8_C(   1),  INT8_C( 107),  INT8_C(  34), -INT8_C(  67),
        -INT8_C(  54),  INT8_C(  57),  INT8_C( 118),  INT8_C(  21), -INT8_C(  93), -INT8_C(  33), -INT8_C( 103),  INT8_C(  80),
        -INT8_C(  23),  INT8_C( 114),  INT8_C( 106),  INT8_C(  66),  INT8_C(  67),  INT8_C(  51), -INT8_C(   8), -INT8_C( 107) },
      UINT64_C( 8091440338081855584) },
    { UINT64_C( 9951626568414863475),
      {  INT8_C(  64),  INT8_C(   8), -INT8_C(  57), -INT8_C(  15), -INT8_C(  13),  INT8_C(   0),  INT8_C(  69), -INT8_C( 121),
         INT8_C(  52), -INT8_C(  32), -INT8_C(  94), -INT8_C(   3),  INT8_C(  17),  INT8_C(  45), -INT8_C(  51),  INT8_C(  67),
         INT8_C( 108), -INT8_C(  26), -INT8_C(  87), -INT8_C(   1), -INT8_C(  33),  INT8_C(  37),  INT8_C(  74),  INT8_C(  63),
        -INT8_C(  35), -INT8_C(  12),  INT8_C(   0),  INT8_C(  27), -INT8_C(  45),  INT8_C(  79), -INT8_C( 112),  INT8_C(  20),
         INT8_C(  87),  INT8_C(  87),  INT8_C(   5),  INT8_C(  74),  INT8_C(  87),  INT8_C(  75), -INT8_C(  47), -INT8_C( 117),
         INT8_C(  43),  INT8_C( 115), -INT8_C( 119),  INT8_C(  60), -INT8_C(  95),  INT8_C(  86),      INT8_MAX,  INT8_C(  13),
         INT8_C(  60),  INT8_C(  40),  INT8_C(  12),  INT8_C(  28),  INT8_C(  77),  INT8_C(  86),  INT8_C(  91),  INT8_C(  42),
         INT8_C(  75),  INT8_C(  92),  INT8_C(  70),  INT8_C(  30), -INT8_C(  85), -INT8_C(  42),  INT8_C(  50),  INT8_C(   2) },
      {  INT8_C(  64),  INT8_C(   8), -INT8_C(  57), -INT8_C( 124), -INT8_C( 125),  INT8_C(  30),  INT8_C(  15), -INT8_C(  82),
        -INT8_C( 111), -INT8_C( 104), -INT8_C(  22),  INT8_C(  50), -INT8_C(  18),  INT8_C( 105),  INT8_C(  63),  INT8_C(  43),
        -INT8_C( 111), -INT8_C(  26),  INT8_C(  71), -INT8_C(   1), -INT8_C(  94),  INT8_C(  37),  INT8_C(   8), -INT8_C(  19),
        -INT8_C(   2),  INT8_C(  78),  INT8_C(   0), -INT8_C(  87),  INT8_C(  36),  INT8_C(  62), -INT8_C( 112),  INT8_C(  81),
         INT8_C( 118),  INT8_C(  87), -INT8_C(  43), -INT8_C(   7),  INT8_C(  22), -INT8_C(  27), -INT8_C(  89), -INT8_C( 117),
         INT8_C( 125),  INT8_C( 115), -INT8_C( 119),  INT8_C( 108), -INT8_C(   6),  INT8_C(  25), -INT8_C( 105), -INT8_C( 117),
         INT8_C( 101),  INT8_C(  40),  INT8_C( 105),  INT8_C(   8),  INT8_C(  77),  INT8_C(  86), -INT8_C(  11),      INT8_MAX,
         INT8_C(  75),  INT8_C(   1),  INT8_C(  40), -INT8_C(  27),  INT8_C(  64), -INT8_C(  44),  INT8_C(  54), -INT8_C(  74) },
      UINT64_C( 9951343989312520275) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__mmask64 k = test_vec[i].k;
    simde__m512i a = simde_mm512_loadu_epi8(test_vec[i].a);
    simde__m512i b = simde_mm512_loadu_epi8(test_vec[i].b);
    simde__mmask64 r = simde_mm512_mask_cmpge_epi8_mask(k, a, b);
    simde_assert_equal_mmask64(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    int8_t a_[64];
    int8_t b_[64];

    simde_test_codegen_random_memory(sizeof(a_), HEDLEY_REINTERPRET_CAST(uint8_t*, a_));
    simde_test_codegen_random_memory(sizeof(b_), HEDLEY_REINTERPRET_CAST(uint8_t*, b_));
    for (size_t j = 0 ; j < (sizeof(a_) / sizeof(a_[0])) ; j++)
      if ((simde_test_codegen_rand() & 3) == 0)
        b_[j] = a_[j];

    simde__mmask64 k = simde_test_x86_random_mmask64();
    simde__m512i a = simde_mm512_loadu_epi8(a_);
    simde__m512i b = simde_mm512_loadu_epi8(b_);
    simde__mmask64 r = simde_mm512_mask_cmpge_epi8_mask(k, a, b);

    simde_test_x86_write_mmask64(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i8x64(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i8x64(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask64(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_x_mm_cmpge_epu8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const uint8_t a[16];
    const uint8_t b[16];
    const uint8_t r[16];
  } test_vec[] = {
    { { UINT8_C( 83), UINT8_C( 57), UINT8_C( 47), UINT8_C( 99), UINT8_C( 60), UINT8_C(157), UINT8_C(100), UINT8_C( 41),
        UINT8_C( 61), UINT8_C(245), UINT8_C(249), UINT8_C( 50), UINT8_C(148), UINT8_C(168), UINT8_C(125), UINT8_C(141) },
      { UINT8_C( 25), UINT8_C( 79), UINT8_C(146), UINT8_C(218), UINT8_C( 56), UINT8_C(239), UINT8_C(100), UINT8_C( 41),
        UINT8_C( 61), UINT8_C( 48), UINT8_C(150), UINT8_C( 50), UINT8_C( 68), UINT8_C( 78), UINT8_C(110), UINT8_C(151) },
      {    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,
           UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0) } },
    { { UINT8_C(119), UINT8_C(  7), UINT8_C(129), UINT8_C(175), UINT8_C(246), UINT8_C(190), UINT8_C(223), UINT8_C(166),
        UINT8_C(239), UINT8_C(117), UINT8_C( 73), UINT8_C( 51), UINT8_C(195), UINT8_C(183), UINT8_C(202), UINT8_C( 74) },
      { UINT8_C( 85), UINT8_C(196), UINT8_C(129), UINT8_C(143), UINT8_C(246), UINT8_C(250), UINT8_C(  7), UINT8_C(118),
        UINT8_C(224), UINT8_C(117), UINT8_C( 94), UINT8_C( 51), UINT8_C(195), UINT8_C(183), UINT8_C( 20), UINT8_C( 80) },
      {    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,
           UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0) } },
    { { UINT8_C(  4), UINT8_C(113), UINT8_C( 92), UINT8_C( 39), UINT8_C(107), UINT8_C(100), UINT8_C(157), UINT8_C( 75),
        UINT8_C( 22), UINT8_C(252), UINT8_C(185), UINT8_C(239), UINT8_C(207), UINT8_C(205), UINT8_C( 64), UINT8_C(170) },
      { UINT8_C( 99), UINT8_C(113), UINT8_C(123), UINT8_C( 39), UINT8_C(107), UINT8_C(242), UINT8_C(157), UINT8_C(116),
        UINT8_C(179), UINT8_C(114), UINT8_C(141), UINT8_C( 43), UINT8_C(178), UINT8_C(240), UINT8_C(248), UINT8_C(183) },
      { UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),
        UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0) } },
    { { UINT8_C( 62), UINT8_C(108), UINT8_C(186), UINT8_C( 93), UINT8_C( 94), UINT8_C(181), UINT8_C(210), UINT8_C( 17),
        UINT8_C( 39), UINT8_C( 95), UINT8_C( 60), UINT8_C(218), UINT8_C( 79), UINT8_C( 52), UINT8_C(145), UINT8_C(176) },
      { UINT8_C(137), UINT8_C(108), UINT8_C(124), UINT8_C( 93), UINT8_C(234), UINT8_C(148), UINT8_C( 16), UINT8_C( 98),
        UINT8_C( 39), UINT8_C(206), UINT8_C(169), UINT8_C(  4), UINT8_C(204), UINT8_C( 52), UINT8_C(  6), UINT8_C(176) },
      { UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),
           UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX } },
    { { UINT8_C(119), UINT8_C( 20), UINT8_C(177), UINT8_C( 97), UINT8_C(168), UINT8_C(193), UINT8_C(195), UINT8_C( 14),
        UINT8_C(143), UINT8_C(108), UINT8_C( 18), UINT8_C( 91), UINT8_C(  6), UINT8_C( 24), UINT8_C(101), UINT8_C( 12) },
      { UINT8_C(216), UINT8_C(205), UINT8_C(113), UINT8_C( 77), UINT8_C(  6), UINT8_C(231), UINT8_C(195), UINT8_C(159),
        UINT8_C(153), UINT8_C( 97), UINT8_C(134), UINT8_C( 91), UINT8_C(105), UINT8_C( 24), UINT8_C(240), UINT8_C(224) },
      { UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),
        UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0) } },
    { { UINT8_C(129), UINT8_C(246), UINT8_C( 56), UINT8_C(135), UINT8_C(221), UINT8_C( 34), UINT8_C( 38), UINT8_C(118),
        UINT8_C(132), UINT8_C(173), UINT8_C(247), UINT8_C(237), UINT8_C(203), UINT8_C(231), UINT8_C(206), UINT8_C(253) },
      { UINT8_C(137), UINT8_C( 16), UINT8_C(215), UINT8_C(135), UINT8_C( 21), UINT8_C(192), UINT8_C(224), UINT8_C(135),
        UINT8_C(186), UINT8_C( 46), UINT8_C(  0), UINT8_C(205), UINT8_C(226), UINT8_C(133), UINT8_C(183), UINT8_C( 99) },
      { UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
        UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX } },
    { { UINT8_C( 97), UINT8_C( 94), UINT8_C( 35), UINT8_C(119), UINT8_C( 30), UINT8_C(  3), UINT8_C(254), UINT8_C(216),
        UINT8_C( 50), UINT8_C(254), UINT8_C(165), UINT8_C( 20), UINT8_C(131), UINT8_C( 93), UINT8_C(120), UINT8_C(254) },
      { UINT8_C( 76), UINT8_C( 99), UINT8_C( 86), UINT8_C( 94), UINT8_C(116), UINT8_C(  3), UINT8_C(244), UINT8_C( 51),
        UINT8_C(234), UINT8_C(120), UINT8_C(188), UINT8_C(151), UINT8_C(201), UINT8_C( 67), UINT8_C(206), UINT8_C( 43) },
      {    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
        UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX } },
    { { UINT8_C( 22), UINT8_C(119), UINT8_C( 69), UINT8_C(139), UINT8_C(156), UINT8_C( 57), UINT8_C(190), UINT8_C(135),
        UINT8_C(177), UINT8_C(122), UINT8_C( 30), UINT8_C(123), UINT8_C(189), UINT8_C(236), UINT8_C(166), UINT8_C( 94) },
      { UINT8_C(222), UINT8_C( 72), UINT8_C( 29), UINT8_C(211), UINT8_C(232), UINT8_C( 57), UINT8_C(250), UINT8_C(135),
        UINT8_C(242), UINT8_C(122), UINT8_C(170), UINT8_C(123), UINT8_C(233), UINT8_C(203), UINT8_C(114),    UINT8_MAX },
      { UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,
        UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_x_mm_loadu_epi8(test_vec[i].a);
    simde__m128i b = simde_x_mm_loadu_epi8(test_vec[i].b);
    simde__m128i r = simde_x_mm_cmpge_epu8(a, b);
    simde_test_x86_assert_equal_u8x16(r, simde_x_mm_loadu_epi8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    uint8_t a_[16];
    uint8_t b_[16];

    simde_test_codegen_random_memory(sizeof(a_), HEDLEY_REINTERPRET_CAST(uint8_t*, a_));
    simde_test_codegen_random_memory(sizeof(b_), HEDLEY_REINTERPRET_CAST(uint8_t*, b_));
    for (size_t j = 0 ; j < (sizeof(a_) / sizeof(a_[0])) ; j++)
      if ((simde_test_codegen_rand() & 3) == 0)
        b_[j] = a_[j];

    simde__m128i a = simde_mm_loadu_epi8(a_);
    simde__m128i b = simde_mm_loadu_epi8(b_);
    simde__m128i r = simde_x_mm_cmpge_epu8(a, b);

    simde_test_x86_write_u8x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_u8x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_u8x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_cmpge_epu8_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const uint8_t a[16];
    const uint8_t b[16];
    const simde__mmask16 r;
  } test_vec[] = {
    { { UINT8_C( 11), UINT8_C(252), UINT8_C( 34), UINT8_C(244), UINT8_C(177), UINT8_C( 28), UINT8_C(123), UINT8_C(163),
        UINT8_C( 81), UINT8_C( 37), UINT8_C( 47), UINT8_C( 58), UINT8_C(240), UINT8_C(162), UINT8_C( 58), UINT8_C( 51) },
      { UINT8_C( 11), UINT8_C(196), UINT8_C( 18), UINT8_C( 74), UINT8_C( 13), UINT8_C(120), UINT8_C(237), UINT8_C(163),
        UINT8_C(252), UINT8_C( 37), UINT8_C( 80), UINT8_C(109), UINT8_C(206), UINT8_C(162), UINT8_C(188), UINT8_C( 51) },
      UINT16_C(45727) },
    { { UINT8_C(133), UINT8_C(164), UINT8_C(246), UINT8_C(146), UINT8_C( 28), UINT8_C(227), UINT8_C( 98), UINT8_C( 24),
        UINT8_C(238), UINT8_C(178), UINT8_C(134), UINT8_C(188), UINT8_C(226), UINT8_C( 66), UINT8_C(149), UINT8_C( 14) },
      { UINT8_C( 33), UINT8_C( 99), UINT8_C(235), UINT8_C( 27), UINT8_C(172), UINT8_C(108), UINT8_C( 98), UINT8_C( 26),
        UINT8_C( 29), UINT8_C(238), UINT8_C(121), UINT8_C(188), UINT8_C(226), UINT8_C( 11), UINT8_C( 27), UINT8_C( 51) },
      UINT16_C(32111) },
    { { UINT8_C(152), UINT8_C(181), UINT8_C(233), UINT8_C( 68), UINT8_C( 34), UINT8_C( 80), UINT8_C( 94), UINT8_C( 63),
        UINT8_C( 62), UINT8_C(216), UINT8_C(174), UINT8_C(237), UINT8_C(227), UINT8_C(202), UINT8_C( 32), UINT8_C(147) },
      { UINT8_C(220), UINT8_C(230), UINT8_C( 94), UINT8_C(209), UINT8_C( 34), UINT8_C( 80), UINT8_C( 94), UINT8_C(231),
        UINT8_C( 62), UINT8_C( 84), UINT8_C(163), UINT8_C( 89), UINT8_C(227), UINT8_C(202), UINT8_C( 38), UINT8_C(147) },
      UINT16_C(49012) },
    { { UINT8_C(146), UINT8_C(113), UINT8_C(170), UINT8_C(159), UINT8_C(179), UINT8_C( 95), UINT8_C(135), UINT8_C( 96),
        UINT8_C(179), UINT8_C( 42), UINT8_C(185), UINT8_C( 61), UINT8_C(152), UINT8_C(223), UINT8_C( 94), UINT8_C(187) },
      { UINT8_C(239), UINT8_C(196), UINT8_C(  0), UINT8_C( 79), UINT8_C(179), UINT8_C(132), UINT8_C(237), UINT8_C( 96),
        UINT8_C(179), UINT8_C(121), UINT8_C(163), UINT8_C( 61), UINT8_C( 37), UINT8_C(182), UINT8_C(139), UINT8_C(183) },
      UINT16_C(48540) },
    { { UINT8_C(167), UINT8_C( 91), UINT8_C( 17), UINT8_C( 47), UINT8_C(223), UINT8_C(254), UINT8_C( 83), UINT8_C(149),
        UINT8_C(119), UINT8_C(247), UINT8_C( 72), UINT8_C(156), UINT8_C(173), UINT8_C(212), UINT8_C( 83), UINT8_C(212) },
      { UINT8_C(  9), UINT8_C(170), UINT8_C(174), UINT8_C( 47), UINT8_C(135), UINT8_C(233), UINT8_C(230), UINT8_C(149),
        UINT8_C(119), UINT8_C(107), UINT8_C( 47), UINT8_C(175), UINT8_C( 78), UINT8_C(212), UINT8_C(113), UINT8_C(212) },
      UINT16_C(47033) },
    { { UINT8_C(146), UINT8_C(159), UINT8_C( 30), UINT8_C( 26), UINT8_C(136), UINT8_C(  4), UINT8_C(169), UINT8_C(101),
        UINT8_C(111), UINT8_C(217), UINT8_C( 20), UINT8_C(189), UINT8_C( 99), UINT8_C(134), UINT8_C(179), UINT8_C( 73) },
      { UINT8_C(  8), UINT8_C(217), UINT8_C( 30), UINT8_C( 26), UINT8_C( 82), UINT8_C(103), UINT8_C(130), UINT8_C(194),
        UINT8_C( 10), UINT8_C( 23), UINT8_C(223), UINT8_C(128),    UINT8_MAX, UINT8_C(208), UINT8_C(  0), UINT8_C( 73) },
      UINT16_C(52061) },
    { { UINT8_C(219), UINT8_C(232), UINT8_C(137), UINT8_C( 45), UINT8_C( 80), UINT8_C( 11), UINT8_C(239), UINT8_C( 90),
        UINT8_C( 34), UINT8_C(206), UINT8_C(218), UINT8_C( 34), UINT8_C(158), UINT8_C(219), UINT8_C(180), UINT8_C( 14) },
      { UINT8_C(249), UINT8_C( 96), UINT8_C(137), UINT8_C( 28), UINT8_C(181), UINT8_C( 99), UINT8_C(173), UINT8_C(228),
        UINT8_C(212), UINT8_C(252), UINT8_C(118), UINT8_C( 34),    UINT8_MAX, UINT8_C( 81), UINT8_C(204), UINT8_C(218) },
      UINT16_C(11342) },
    { { UINT8_C(185), UINT8_C(120), UINT8_C(174), UINT8_C(111), UINT8_C(219), UINT8_C( 92), UINT8_C( 83), UINT8_C(176),
        UINT8_C( 88), UINT8_C(201), UINT8_C(124), UINT8_C( 87), UINT8_C( 26), UINT8_C( 72), UINT8_C( 50), UINT8_C( 83) },
      { UINT8_C(157), UINT8_C(120), UINT8_C(221), UINT8_C(254), UINT8_C(219), UINT8_C( 92), UINT8_C(130), UINT8_C(247),
        UINT8_C(126), UINT8_C( 39), UINT8_C(124), UINT8_C( 23), UINT8_C(129), UINT8_C(206), UINT8_C(170), UINT8_C( 83) },
      UINT16_C(36403) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_x_mm_loadu_epi8(test_vec[i].a);
    simde__m128i b = simde_x_mm_loadu_epi8(test_vec[i].b);
    simde__mmask16 r = simde_mm_cmpge_epu8_mask(a, b);
    simde_assert_equal_mmask16(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    uint8_t a_[16];
    uint8_t b_[16];

    simde_test_codegen_random_memory(sizeof(a_), HEDLEY_REINTERPRET_CAST(uint8_t*, a_));
    simde_test_codegen_random_memory(sizeof(b_), HEDLEY_REINTERPRET_CAST(uint8_t*, b_));
    for (size_t j = 0 ; j < (sizeof(a_) / sizeof(a_[0])) ; j++)
      if ((simde_test_codegen_rand() & 3) == 0)
        b_[j] = a_[j];

    simde__m128i a = simde_mm_loadu_epi8(a_);
    simde__m128i b = simde_mm_loadu_epi8(b_);
    simde__mmask16 r = simde_mm_cmpge_epu8_mask(a, b);

    simde_test_x86_write_u8x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_u8x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_mask_cmpge_epu8_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask16 k;
    const uint8_t a[16];
    const uint8_t b[16];
    const simde__mmask16 r;
  } test_vec[] = {
    { UINT16_C(25457),
      { UINT8_C(208), UINT8_C( 16), UINT8_C( 50), UINT8_C(  2), UINT8_C(208), UINT8_C(180), UINT8_C(249), UINT8_C( 79),
        UINT8_C(220), UINT8_C( 85), UINT8_C(102), UINT8_C( 93), UINT8_C( 36), UINT8_C( 16), UINT8_C(151), UINT8_C(107) },
      { UINT8_C(105), UINT8_C( 65), UINT8_C( 50), UINT8_C( 29), UINT8_C(208), UINT8_C( 96), UINT8_C( 42), UINT8_C( 79),
        UINT8_C(174), UINT8_C(143), UINT8_C(226), UINT8_C( 69), UINT8_C( 36), UINT8_C( 16), UINT8_C(121), UINT8_C(246) },
      UINT16_C(24945) },
    { UINT16_C(35872),
      { UINT8_C( 66), UINT8_C(175), UINT8_C(195), UINT8_C(109), UINT8_C(178), UINT8_C(114), UINT8_C(252), UINT8_C(148),
        UINT8_C(183), UINT8_C( 33), UINT8_C(170), UINT8_C( 48), UINT8_C( 23), UINT8_C(207), UINT8_C(219), UINT8_C( 15) },
      { UINT8_C(197), UINT8_C(175), UINT8_C(  1), UINT8_C( 10), UINT8_C(119), UINT8_C( 72), UINT8_C(252), UINT8_C( 16),
        UINT8_C(183), UINT8_C(114), UINT8_C( 65), UINT8_C(137), UINT8_C(151), UINT8_C(207), UINT8_C(236), UINT8_C(217) },
      UINT16_C( 1056) },
    { UINT16_C(58348),
      { UINT8_C(241), UINT8_C(151), UINT8_C(212), UINT8_C(167), UINT8_C(168), UINT8_C(135), UINT8_C( 25), UINT8_C(233),
        UINT8_C( 16), UINT8_C(176), UINT8_C(155), UINT8_C(252), UINT8_C(138), UINT8_C(253), UINT8_C(172), UINT8_C(208) },
      { UINT8_C(241), UINT8_C(206), UINT8_C(212), UINT8_C(167), UINT8_C(168), UINT8_C(119), UINT8_C( 10), UINT8_C(233),
        UINT8_C(242), UINT8_C( 44), UINT8_C(149), UINT8_C(252), UINT8_C( 19), UINT8_C(181), UINT8_C(172), UINT8_C(  4) },
      UINT16_C(58092) },
    { UINT16_C(27958),
      { UINT8_C( 63), UINT8_C(147), UINT8_C( 90), UINT8_C( 73), UINT8_C( 68), UINT8_C( 77), UINT8_C(117), UINT8_C(217),
        UINT8_C(202), UINT8_C(136), UINT8_C(142), UINT8_C(212), UINT8_C(141), UINT8_C(218), UINT8_C(177), UINT8_C( 57) },
      { UINT8_C( 63), UINT8_C( 22), UINT8_C(254), UINT8_C( 73), UINT8_C( 68), UINT8_C( 77), UINT8_C( 37), UINT8_C(251),
        UINT8_C(202), UINT8_C(155), UINT8_C( 25), UINT8_C( 69), UINT8_C( 34), UINT8_C(218), UINT8_C( 40), UINT8_C( 97) },
      UINT16_C(27954) },
    { UINT16_C(36948),
      { UINT8_C(153), UINT8_C(192), UINT8_C(225), UINT8_C(191), UINT8_C(188), UINT8_C( 86), UINT8_C( 90), UINT8_C(213),
        UINT8_C(155), UINT8_C(124), UINT8_C(218), UINT8_C(195), UINT8_C(221), UINT8_C(114), UINT8_C( 70), UINT8_C(136) },
      { UINT8_C( 79), UINT8_C( 22), UINT8_C(168), UINT8_C(  4), UINT8_C(177), UINT8_C( 80), UINT8_C( 72), UINT8_C(213),
        UINT8_C(134), UINT8_C(102), UINT8_C( 63), UINT8_C(195), UINT8_C( 83), UINT8_C(117), UINT8_C( 70), UINT8_C(236) },
      UINT16_C( 4180) },
    { UINT16_C(52567),
      { UINT8_C(103), UINT8_C(  5), UINT8_C(224), UINT8_C(175), UINT8_C( 37), UINT8_C(102), UINT8_C( 21), UINT8_C(100),
        UINT8_C( 91), UINT8_C(104), UINT8_C(218), UINT8_C(188), UINT8_C( 84), UINT8_C( 16),    UINT8_MAX, UINT8_C(  0) },
      { UINT8_C(103), UINT8_C(152), UINT8_C(  6), UINT8_C(201), UINT8_C(204), UINT8_C(136), UINT8_C(106), UINT8_C(196),
        UINT8_C(232), UINT8_C(125), UINT8_C(  2), UINT8_C(208), UINT8_C(224), UINT8_C( 86), UINT8_C( 96), UINT8_C( 71) },
      UINT16_C(17413) },
    { UINT16_C(55445),
      { UINT8_C(154), UINT8_C( 35), UINT8_C( 86), UINT8_C(  4), UINT8_C(231), UINT8_C( 62), UINT8_C(130), UINT8_C(233),
        UINT8_C( 15), UINT8_C( 98), UINT8_C( 64), UINT8_C(111), UINT8_C(169), UINT8_C(156), UINT8_C(176), UINT8_C(159) },
      { UINT8_C( 29), UINT8_C( 88), UINT8_C(170), UINT8_C(  2), UINT8_C( 90), UINT8_C( 62), UINT8_C(194), UINT8_C( 25),
        UINT8_C(228), UINT8_C(145), UINT8_C( 64), UINT8_C(172), UINT8_C( 99), UINT8_C( 47), UINT8_C(121), UINT8_C(159) },
      UINT16_C(53393) },
    { UINT16_C(35026),
      { UINT8_C( 31), UINT8_C(239), UINT8_C(245), UINT8_C(225), UINT8_C(  9), UINT8_C(217), UINT8_C(114), UINT8_C(225),
        UINT8_C(133), UINT8_C(213), UINT8_C( 16),    UINT8_MAX, UINT8_C(211), UINT8_C( 98), UINT8_C(206), UINT8_C(213) },
      { UINT8_C(156), UINT8_C(220), UINT8_C( 89), UINT8_C(225), UINT8_C(249), UINT8_C( 63), UINT8_C( 35), UINT8_C(225),
        UINT8_C(206), UINT8_C( 35), UINT8_C(195), UINT8_C(252), UINT8_C(211), UINT8_C( 88), UINT8_C(212), UINT8_C(213) },
      UINT16_C(35010) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__mmask16 k = test_vec[i].k;
    simde__m128i a = simde_x_mm_loadu_epi8(test_vec[i].a);
    simde__m128i b = simde_x_mm_loadu_epi8(test_vec[i].b);
    simde__mmask16 r = simde_mm_mask_cmpge_epu8_mask(k, a, b);
    simde_assert_equal_mmask16(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    uint8_t a_[16];
    uint8_t b_[16];

    simde_test_codegen_random_memory(sizeof(a_), HEDLEY_REINTERPRET_CAST(uint8_t*, a_));
    simde_test_codegen_random_memory(sizeof(b_), HEDLEY_REINTERPRET_CAST(uint8_t*, b_));
    for (size_t j = 0 ; j < (sizeof(a_) / sizeof(a_[0])) ; j++)
      if ((simde_test_codegen_rand() & 3) == 0)
        b_[j] = a_[j];

    simde__mmask16 k = simde_test_x86_random_mmask16();
    simde__m128i a = simde_mm_loadu_epi8(a_);
    simde__m128i b = simde_mm_loadu_epi8(b_);
    simde__mmask16 r = simde_mm_mask_cmpge_epu8_mask(k, a, b);

    simde_test_x86_write_mmask16(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_u8x16(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_u8x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_x_mm256_cmpge_epu8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const uint8_t a[32];
    const uint8_t b[32];
    const uint8_t r[32];
  } test_vec[] = {
    { { UINT8_C( 95), UINT8_C(146), UINT8_C(185), UINT8_C( 38), UINT8_C(204), UINT8_C( 79), UINT8_C(108), UINT8_C(118),
        UINT8_C(166), UINT8_C( 66), UINT8_C(181), UINT8_C( 97), UINT8_C(146), UINT8_C( 43), UINT8_C( 54), UINT8_C(166),
        UINT8_C( 39), UINT8_C( 80), UINT8_C( 27), UINT8_C(130), UINT8_C(126), UINT8_C( 12), UINT8_C(163), UINT8_C(172),
        UINT8_C(229), UINT8_C( 72), UINT8_C(149), UINT8_C(  4), UINT8_C( 88), UINT8_C( 96), UINT8_C(171), UINT8_C(183) },
      { UINT8_C(242), UINT8_C(146), UINT8_C(185), UINT8_C(191), UINT8_C(180), UINT8_C( 74), UINT8_C(108), UINT8_C( 90),
        UINT8_C(166), UINT8_C(235), UINT8_C(187), UINT8_C( 30), UINT8_C( 22), UINT8_C(242), UINT8_C(196), UINT8_C(166),
        UINT8_C( 66), UINT8_C(223), UINT8_C(192), UINT8_C(193), UINT8_C(236), UINT8_C( 99), UINT8_C(109), UINT8_C(172),
        UINT8_C(171), UINT8_C(  2), UINT8_C(149), UINT8_C(  3), UINT8_C( 88), UINT8_C(128), UINT8_C(171), UINT8_C( 85) },
      { UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
           UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,
        UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,
           UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX } },
    { { UINT8_C(175), UINT8_C(224), UINT8_C(195), UINT8_C(146), UINT8_C( 42), UINT8_C(183), UINT8_C(  1), UINT8_C( 94),
        UINT8_C(102), UINT8_C(142), UINT8_C(169), UINT8_C(  8), UINT8_C(224), UINT8_C( 50), UINT8_C(236), UINT8_C( 18),
        UINT8_C(124), UINT8_C(145), UINT8_C( 47), UINT8_C( 41), UINT8_C(163), UINT8_C( 30), UINT8_C(129), UINT8_C(184),
        UINT8_C(225), UINT8_C(221), UINT8_C( 48), UINT8_C( 37), UINT8_C(244), UINT8_C(252), UINT8_C( 79), UINT8_C(164) },
      { UINT8_C(221), UINT8_C(224), UINT8_C( 54), UINT8_C(  7), UINT8_C(201), UINT8_C( 55), UINT8_C(101), UINT8_C( 94),
        UINT8_C(197), UINT8_C( 15), UINT8_C( 55), UINT8_C(166), UINT8_C( 65), UINT8_C( 35), UINT8_C(236), UINT8_C(189),
        UINT8_C(180), UINT8_C(231), UINT8_C(230), UINT8_C( 88), UINT8_C(  5), UINT8_C(104), UINT8_C( 16), UINT8_C(184),
        UINT8_C( 69), UINT8_C( 64), UINT8_C( 12), UINT8_C( 58), UINT8_C( 61), UINT8_C(252), UINT8_C(222), UINT8_C(164) },
      { UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,
        UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),
        UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,
           UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX } },
    { { UINT8_C( 84), UINT8_C(150), UINT8_C( 78), UINT8_C(159), UINT8_C( 29), UINT8_C(180), UINT8_C(176), UINT8_C(178),
        UINT8_C( 82), UINT8_C(102), UINT8_C(137), UINT8_C( 19), UINT8_C(213), UINT8_C( 30), UINT8_C(136), UINT8_C( 43),
        UINT8_C(153), UINT8_C( 86), UINT8_C(134), UINT8_C(124), UINT8_C( 52), UINT8_C(201), UINT8_C(164), UINT8_C( 82),
        UINT8_C( 24), UINT8_C(  7), UINT8_C(174), UINT8_C(194), UINT8_C( 71), UINT8_C( 35), UINT8_C(218), UINT8_C(156) },
      { UINT8_C(186), UINT8_C(150), UINT8_C( 59), UINT8_C(215), UINT8_C( 29), UINT8_C(235), UINT8_C(176), UINT8_C( 47),
        UINT8_C( 82), UINT8_C( 19), UINT8_C( 66), UINT8_C( 39), UINT8_C( 49), UINT8_C(203), UINT8_C( 82), UINT8_C(202),
        UINT8_C( 33), UINT8_C(216), UINT8_C(134), UINT8_C( 85), UINT8_C(161), UINT8_C(234), UINT8_C(167), UINT8_C(185),
        UINT8_C(241), UINT8_C( 85), UINT8_C(174), UINT8_C( 57), UINT8_C(121), UINT8_C( 86), UINT8_C(213), UINT8_C(156) },
      { UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,
           UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),
           UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
        UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX } },
    { { UINT8_C(226), UINT8_C(195), UINT8_C(169), UINT8_C(222), UINT8_C( 86), UINT8_C( 54), UINT8_C( 44), UINT8_C(253),
        UINT8_C(  5), UINT8_C(161), UINT8_C(212), UINT8_C(159), UINT8_C(104), UINT8_C(118), UINT8_C( 90), UINT8_C(  7),
        UINT8_C( 93), UINT8_C(106), UINT8_C( 72), UINT8_C( 47), UINT8_C( 33), UINT8_C( 67), UINT8_C(243), UINT8_C( 46),
        UINT8_C(185), UINT8_C(239), UINT8_C(180), UINT8_C(134), UINT8_C(193), UINT8_C(109), UINT8_C(211), UINT8_C(163) },
      { UINT8_C(226), UINT8_C(124), UINT8_C(169), UINT8_C(135), UINT8_C( 86), UINT8_C( 54), UINT8_C(132), UINT8_C(183),
        UINT8_C(  5), UINT8_C( 88), UINT8_C(212), UINT8_C(182), UINT8_C(206), UINT8_C(176), UINT8_C(189), UINT8_C(  7),
        UINT8_C( 26), UINT8_C(  6), UINT8_C( 72), UINT8_C( 47), UINT8_C( 73), UINT8_C( 78), UINT8_C(106), UINT8_C(  2),
        UINT8_C( 62), UINT8_C(239), UINT8_C(137),    UINT8_MAX, UINT8_C(193), UINT8_C(109), UINT8_C(162), UINT8_C(163) },
      {    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,
           UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,
           UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,
           UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX } },
    { { UINT8_C(199), UINT8_C(183), UINT8_C( 43), UINT8_C(151), UINT8_C(127), UINT8_C(110), UINT8_C(181), UINT8_C(159),
        UINT8_C(  7), UINT8_C(137), UINT8_C(142), UINT8_C( 80), UINT8_C( 26), UINT8_C(169), UINT8_C(180), UINT8_C(178),
        UINT8_C( 32), UINT8_C( 84), UINT8_C(146), UINT8_C(229), UINT8_C( 95), UINT8_C(117), UINT8_C(232), UINT8_C(136),
        UINT8_C(225), UINT8_C(234), UINT8_C( 62), UINT8_C(169), UINT8_C(142), UINT8_C(177), UINT8_C( 74), UINT8_C( 85) },
      { UINT8_C(104), UINT8_C(117), UINT8_C(236), UINT8_C(151), UINT8_C(227), UINT8_C(161), UINT8_C(135), UINT8_C(159),
        UINT8_C(  7), UINT8_C( 21), UINT8_C(142), UINT8_C( 68), UINT8_C(191), UINT8_C(239), UINT8_C(246), UINT8_C(223),
        UINT8_C( 32), UINT8_C(137), UINT8_C(146), UINT8_C(163), UINT8_C(254), UINT8_C(117), UINT8_C( 43), UINT8_C(136),
        UINT8_C(150), UINT8_C(234), UINT8_C( 62), UINT8_C( 36), UINT8_C( 27), UINT8_C(211), UINT8_C(121), UINT8_C( 85) },
      {    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,
           UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
           UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
           UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX } },
    { { UINT8_C(174), UINT8_C(201), UINT8_C(165), UINT8_C(180), UINT8_C(187), UINT8_C(188), UINT8_C(228), UINT8_C(195),
        UINT8_C( 14), UINT8_C( 88), UINT8_C(138), UINT8_C( 79), UINT8_C(195), UINT8_C( 48), UINT8_C(213), UINT8_C(183),
        UINT8_C(154), UINT8_C(253), UINT8_C(170), UINT8_C(176), UINT8_C( 81), UINT8_C(124), UINT8_C( 92), UINT8_C( 15),
        UINT8_C(216), UINT8_C( 44), UINT8_C(233), UINT8_C(  8), UINT8_C(117), UINT8_C( 70), UINT8_C(128), UINT8_C( 35) },
      { UINT8_C(174), UINT8_C( 37), UINT8_C(165), UINT8_C(203), UINT8_C(225), UINT8_C(187), UINT8_C(142), UINT8_C(239),
        UINT8_C( 14), UINT8_C( 88), UINT8_C( 63), UINT8_C(215), UINT8_C(195), UINT8_C( 48), UINT8_C(143), UINT8_C(228),
        UINT8_C( 17), UINT8_C( 57), UINT8_C(170), UINT8_C( 99), UINT8_C(181), UINT8_C(241), UINT8_C( 92), UINT8_C( 15),
        UINT8_C( 29), UINT8_C( 91), UINT8_C(150), UINT8_C(  8), UINT8_C(162), UINT8_C( 22), UINT8_C(182), UINT8_C(177) },
      {    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),
           UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),
           UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,
           UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0) } },
    { { UINT8_C(204), UINT8_C(114), UINT8_C( 70), UINT8_C( 21), UINT8_C(125), UINT8_C( 83), UINT8_C(115), UINT8_C(161),
        UINT8_C(159), UINT8_C(168), UINT8_C( 15),    UINT8_MAX, UINT8_C(108), UINT8_C( 96), UINT8_C(113), UINT8_C(105),
        UINT8_C( 70), UINT8_C( 69), UINT8_C( 27), UINT8_C( 29), UINT8_C(140), UINT8_C( 92), UINT8_C( 18), UINT8_C( 47),
        UINT8_C( 50), UINT8_C(153), UINT8_C(115), UINT8_C( 31), UINT8_C(215), UINT8_C(105), UINT8_C( 72), UINT8_C(163) },
      { UINT8_C(220), UINT8_C(143), UINT8_C(185), UINT8_C( 21), UINT8_C(226), UINT8_C( 44), UINT8_C(251), UINT8_C(130),
        UINT8_C(212), UINT8_C(168), UINT8_C(129), UINT8_C( 64), UINT8_C(106), UINT8_C(242), UINT8_C(169), UINT8_C(177),
        UINT8_C( 56), UINT8_C(196), UINT8_C(206), UINT8_C( 29), UINT8_C( 32), UINT8_C(224), UINT8_C(243), UINT8_C( 83),
        UINT8_C(122), UINT8_C(103), UINT8_C(114), UINT8_C( 81), UINT8_C(215), UINT8_C(187), UINT8_C(245), UINT8_C(172) },
      { UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,
        UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
           UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
        UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0) } },
    { { UINT8_C( 68), UINT8_C(252), UINT8_C(115), UINT8_C( 30), UINT8_C(253), UINT8_C( 33), UINT8_C(204), UINT8_C(  8),
        UINT8_C( 81), UINT8_C(186), UINT8_C(126), UINT8_C(116), UINT8_C( 81), UINT8_C(164), UINT8_C(206), UINT8_C(172),
        UINT8_C(153), UINT8_C(237), UINT8_C( 40), UINT8_C(111), UINT8_C(  0), UINT8_C(247), UINT8_C(190), UINT8_C(121),
        UINT8_C( 57), UINT8_C( 95), UINT8_C(195), UINT8_C( 53), UINT8_C(245), UINT8_C(186), UINT8_C(124), UINT8_C( 57) },
      { UINT8_C( 68), UINT8_C(252), UINT8_C( 87), UINT8_C(180), UINT8_C( 16), UINT8_C( 33), UINT8_C(188), UINT8_C( 98),
        UINT8_C(221), UINT8_C( 58), UINT8_C(214), UINT8_C( 46), UINT8_C(223), UINT8_C(164), UINT8_C(219), UINT8_C(120),
        UINT8_C(146), UINT8_C(  3), UINT8_C(231), UINT8_C(146), UINT8_C(251), UINT8_C(166), UINT8_C( 11), UINT8_C( 52),
        UINT8_C( 57), UINT8_C(207), UINT8_C(195), UINT8_C(251), UINT8_C(245), UINT8_C(186), UINT8_C(124), UINT8_C( 57) },
      {    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),
        UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,
           UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
           UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256i a = simde_mm256_loadu_epi8(test_vec[i].a);
    simde__m256i b = simde_mm256_loadu_epi8(test_vec[i].b);
    simde__m256i r = simde_x_mm256_cmpge_epu8(a, b);
    simde_test_x86_assert_equal_u8x32(r, simde_mm256_loadu_epi8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    uint8_t a_[32];
    uint8_t b_[32];

    simde_test_codegen_random_memory(sizeof(a_), HEDLEY_REINTERPRET_CAST(uint8_t*, a_));
    simde_test_codegen_random_memory(sizeof(b_), HEDLEY_REINTERPRET_CAST(uint8_t*, b_));
    for (size_t j = 0 ; j < (sizeof(a_) / sizeof(a_[0])) ; j++)
      if ((simde_test_codegen_rand() & 3) == 0)
        b_[j] = a_[j];

    simde__m256i a = simde_mm256_loadu_epi8(a_);
    simde__m256i b = simde_mm256_loadu_epi8(b_);
    simde__m256i r = simde_x_mm256_cmpge_epu8(a, b);

    simde_test_x86_write_u8x32(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_u8x32(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_u8x32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_cmpge_epu8_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const uint8_t a[32];
    const uint8_t b[32];
    const simde__mmask32 r;
  } test_vec[] = {
    { { UINT8_C(144), UINT8_C(124), UINT8_C(209), UINT8_C( 64), UINT8_C( 44), UINT8_C( 24), UINT8_C(205), UINT8_C( 22),
        UINT8_C( 53), UINT8_C(136), UINT8_C(224), UINT8_C(247), UINT8_C( 31), UINT8_C( 34), UINT8_C( 74), UINT8_C(185),
        UINT8_C( 75), UINT8_C( 48), UINT8_C( 78), UINT8_C( 27), UINT8_C( 33), UINT8_C( 23), UINT8_C(240), UINT8_C(225),
        UINT8_C( 73), UINT8_C(192), UINT8_C( 42), UINT8_C( 97), UINT8_C(196), UINT8_C(178), UINT8_C( 78), UINT8_C( 85) },
      { UINT8_C(144), UINT8_C(124), UINT8_C(149), UINT8_C( 64), UINT8_C( 56), UINT8_C( 98), UINT8_C(113), UINT8_C( 22),
        UINT8_C( 53), UINT8_C( 81), UINT8_C(100), UINT8_C(  9), UINT8_C(115), UINT8_C( 34), UINT8_C(194), UINT8_C(185),
        UINT8_C(223), UINT8_C( 16), UINT8_C( 78), UINT8_C( 27), UINT8_C( 39), UINT8_C(201), UINT8_C(225), UINT8_C(113),
        UINT8_C( 73), UINT8_C(192), UINT8_C( 42), UINT8_C( 78), UINT8_C(196), UINT8_C( 32), UINT8_C(163), UINT8_C( 85) },
      UINT32_C(3217993679) },
    { { UINT8_C(143), UINT8_C(180), UINT8_C(164), UINT8_C( 41), UINT8_C(107), UINT8_C(138), UINT8_C(174), UINT8_C(116),
        UINT8_C(212), UINT8_C( 60), UINT8_C(239), UINT8_C(205), UINT8_C(140), UINT8_C( 41), UINT8_C(165), UINT8_C(237),
        UINT8_C( 61), UINT8_C(125), UINT8_C(118), UINT8_C( 26), UINT8_C( 54), UINT8_C(111), UINT8_C(128), UINT8_C(250),
        UINT8_C( 59), UINT8_C( 53), UINT8_C(123), UINT8_C( 40), UINT8_C(140), UINT8_C(233), UINT8_C( 84), UINT8_C( 28) },
      { UINT8_C(143), UINT8_C(180), UINT8_C(164), UINT8_C(  8), UINT8_C(131), UINT8_C(138), UINT8_C(124), UINT8_C( 87),
        UINT8_C(212), UINT8_C(108), UINT8_C( 36), UINT8_C(188), UINT8_C(149), UINT8_C( 41), UINT8_C(165), UINT8_C(210),
        UINT8_C( 61), UINT8_C( 31), UINT8_C(236), UINT8_C(124), UINT8_C(143), UINT8_C(109), UINT8_C(118), UINT8_C(250),
        UINT8_C( 59), UINT8_C( 53), UINT8_C(242), UINT8_C( 46), UINT8_C(218), UINT8_C( 71), UINT8_C( 74), UINT8_C(119) },
      UINT32_C(1675881967) },
    { { UINT8_C(213), UINT8_C(  2), UINT8_C(206), UINT8_C( 88),    UINT8_MAX, UINT8_C(232), UINT8_C( 11), UINT8_C(103),
        UINT8_C( 38), UINT8_C(122), UINT8_C(101), UINT8_C( 45), UINT8_C(147), UINT8_C( 54), UINT8_C(122), UINT8_C(203),
        UINT8_C(243), UINT8_C( 67), UINT8_C(146), UINT8_C( 29), UINT8_C(130), UINT8_C( 35), UINT8_C(233), UINT8_C(178),
        UINT8_C(167), UINT8_C(227), UINT8_C(189), UINT8_C(114), UINT8_C( 40), UINT8_C( 64), UINT8_C(125), UINT8_C(253) },
      { UINT8_C( 66), UINT8_C( 75), UINT8_C( 86), UINT8_C( 65), UINT8_C( 51), UINT8_C( 97), UINT8_C(169), UINT8_C( 89),
        UINT8_C(220), UINT8_C( 14), UINT8_C(134), UINT8_C(111), UINT8_C( 68), UINT8_C(  0), UINT8_C( 58), UINT8_C( 55),
        UINT8_C( 67), UINT8_C(204), UINT8_C( 84), UINT8_C(197), UINT8_C(239), UINT8_C( 61), UINT8_C(120), UINT8_C(178),
        UINT8_C( 33), UINT8_C( 53), UINT8_C(  9), UINT8_C( 73), UINT8_C(117), UINT8_C( 64), UINT8_C( 71), UINT8_C(184) },
      UINT32_C(4022727357) },
    { { UINT8_C( 13), UINT8_C(196), UINT8_C( 63), UINT8_C( 12), UINT8_C(102), UINT8_C(158), UINT8_C(230), UINT8_C( 23),
        UINT8_C(132), UINT8_C( 48), UINT8_C( 13), UINT8_C(107), UINT8_C(179), UINT8_C( 58), UINT8_C(149), UINT8_C(  3),
        UINT8_C(187), UINT8_C(132), UINT8_C( 66), UINT8_C(122), UINT8_C(236), UINT8_C( 24), UINT8_C( 90), UINT8_C(137),
        UINT8_C(247), UINT8_C(132), UINT8_C(155), UINT8_C( 94), UINT8_C(244), UINT8_C(102), UINT8_C(151), UINT8_C(  2) },
      { UINT8_C( 42), UINT8_C(196), UINT8_C( 14), UINT8_C( 12), UINT8_C(102), UINT8_C(244), UINT8_C(168), UINT8_C(249),
        UINT8_C( 36), UINT8_C(181), UINT8_C(100), UINT8_C(216), UINT8_C(239), UINT8_C( 58), UINT8_C(219), UINT8_C(170),
        UINT8_C(125), UINT8_C( 29), UINT8_C( 37), UINT8_C(105), UINT8_C( 53), UINT8_C(127), UINT8_C(242), UINT8_C( 44),
        UINT8_C(  3), UINT8_C(142), UINT8_C(138), UINT8_C(248), UINT8_C(244), UINT8_C( 33), UINT8_C(250), UINT8_C( 30) },
      UINT32_C( 899621214) },
    { { UINT8_C( 71), UINT8_C(234), UINT8_C( 98), UINT8_C( 67), UINT8_C( 64), UINT8_C(199), UINT8_C(100), UINT8_C( 76),
        UINT8_C(144), UINT8_C( 93), UINT8_C( 70), UINT8_C( 82), UINT8_C( 49), UINT8_C(235), UINT8_C(145), UINT8_C( 34),
        UINT8_C(181), UINT8_C( 58), UINT8_C( 72),    UINT8_MAX, UINT8_C(214), UINT8_C(155), UINT8_C( 76),    UINT8_MAX,
        UINT8_C(120), UINT8_C(145), UINT8_C( 29), UINT8_C(118), UINT8_C(208), UINT8_C( 88), UINT8_C(108), UINT8_C( 23) },
      { UINT8_C( 66), UINT8_C(234), UINT8_C( 98), UINT8_C(131), UINT8_C(149), UINT8_C(191), UINT8_C(100), UINT8_C( 37),
        UINT8_C(144), UINT8_C( 93), UINT8_C(119), UINT8_C( 78), UINT8_C(  1), UINT8_C(  9), UINT8_C(145), UINT8_C( 34),
        UINT8_C( 67), UINT8_C(185), UINT8_C(181), UINT8_C( 25), UINT8_C( 84), UINT8_C(  1), UINT8_C( 25), UINT8_C(204),
        UINT8_C(146), UINT8_C( 54), UINT8_C( 29), UINT8_C( 98), UINT8_C(208), UINT8_C(175), UINT8_C(108), UINT8_C(209) },
      UINT32_C(1593441255) },
    { { UINT8_C(233), UINT8_C( 24), UINT8_C(201), UINT8_C(124), UINT8_C( 59), UINT8_C(  1), UINT8_C( 44), UINT8_C(116),
        UINT8_C(177), UINT8_C( 41), UINT8_C(173), UINT8_C(106), UINT8_C(151), UINT8_C(157), UINT8_C(103), UINT8_C(190),
        UINT8_C( 67), UINT8_C(125), UINT8_C( 57), UINT8_C(234), UINT8_C(172), UINT8_C(128), UINT8_C( 35), UINT8_C( 17),
        UINT8_C( 10), UINT8_C(191), UINT8_C(  4), UINT8_C( 66), UINT8_C(213), UINT8_C(201), UINT8_C(248), UINT8_C(190) },
      { UINT8_C(225), UINT8_C(193), UINT8_C(201), UINT8_C( 29), UINT8_C(195), UINT8_C(103), UINT8_C(145), UINT8_C(116),
        UINT8_C(144), UINT8_C( 62), UINT8_C(223), UINT8_C( 40), UINT8_C(220), UINT8_C(157), UINT8_C(230), UINT8_C( 31),
        UINT8_C( 67), UINT8_C( 32), UINT8_C(  9), UINT8_C(111), UINT8_C(172), UINT8_C( 44), UINT8_C(128), UINT8_C( 17),
        UINT8_C(236), UINT8_C(191), UINT8_C(237), UINT8_C(193), UINT8_C( 77), UINT8_C(201), UINT8_C(127), UINT8_C( 47) },
      UINT32_C(4072647053) },
    { { UINT8_C( 51), UINT8_C(  2), UINT8_C( 15), UINT8_C( 84), UINT8_C(223), UINT8_C(237), UINT8_C(  6), UINT8_C(251),
        UINT8_C(171), UINT8_C(224), UINT8_C(242), UINT8_C(174), UINT8_C(161), UINT8_C(  9), UINT8_C(117), UINT8_C(129),
        UINT8_C( 40), UINT8_C(170), UINT8_C(  2), UINT8_C(116), UINT8_C( 96), UINT8_C( 46), UINT8_C(172), UINT8_C(154),
        UINT8_C( 70), UINT8_C(165), UINT8_C( 33), UINT8_C( 68), UINT8_C( 30), UINT8_C(216), UINT8_C(233), UINT8_C( 81) },
      { UINT8_C( 51), UINT8_C(  2), UINT8_C(165), UINT8_C(186), UINT8_C(223), UINT8_C(237), UINT8_C(181), UINT8_C(251),
        UINT8_C(140), UINT8_C(167), UINT8_C( 63), UINT8_C(174), UINT8_C(176), UINT8_C(180), UINT8_C(175), UINT8_C(217),
        UINT8_C( 95), UINT8_C(177), UINT8_C( 77), UINT8_C(191), UINT8_C( 96), UINT8_C(250), UINT8_C(172), UINT8_C(154),
        UINT8_C(159), UINT8_C(122), UINT8_C(106), UINT8_C(189), UINT8_C( 82), UINT8_C(216), UINT8_C(233), UINT8_C( 45) },
      UINT32_C(3805286323) },
    { { UINT8_C( 52), UINT8_C( 15), UINT8_C(189), UINT8_C(148), UINT8_C(171), UINT8_C(129), UINT8_C(128), UINT8_C(239),
        UINT8_C(132), UINT8_C(154), UINT8_C(227), UINT8_C( 59), UINT8_C( 99), UINT8_C(176), UINT8_C( 82), UINT8_C(222),
        UINT8_C(202), UINT8_C( 39), UINT8_C( 56), UINT8_C(223), UINT8_C( 86), UINT8_C(184), UINT8_C(147),    UINT8_MAX,
        UINT8_C(162), UINT8_C(  4), UINT8_C(250), UINT8_C(225), UINT8_C(132), UINT8_C( 35), UINT8_C(108), UINT8_C(184) },
      { UINT8_C( 50), UINT8_C( 41), UINT8_C( 76), UINT8_C(148), UINT8_C(170), UINT8_C(205), UINT8_C(205), UINT8_C( 46),
        UINT8_C(103), UINT8_C(176), UINT8_C(106), UINT8_C(203), UINT8_C( 96), UINT8_C(188), UINT8_C(169), UINT8_C(222),
        UINT8_C(202), UINT8_C(225), UINT8_C(  9), UINT8_C( 57), UINT8_C( 86), UINT8_C(156), UINT8_C(147), UINT8_C( 59),
        UINT8_C(161), UINT8_C( 51), UINT8_C( 28), UINT8_C( 37), UINT8_C( 86), UINT8_C( 35), UINT8_C(108), UINT8_C(136) },
      UINT32_C(4261254557) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256i a = simde_mm256_loadu_epi8(test_vec[i].a);
    simde__m256i b = simde_mm256_loadu_epi8(test_vec[i].b);
    simde__mmask32 r = simde_mm256_cmpge_epu8_mask(a, b);
    simde_assert_equal_mmask32(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    uint8_t a_[32];
    uint8_t b_[32];

    simde_test_codegen_random_memory(sizeof(a_), HEDLEY_REINTERPRET_CAST(uint8_t*, a_));
    simde_test_codegen_random_memory(sizeof(b_), HEDLEY_REINTERPRET_CAST(uint8_t*, b_));
    for (size_t j = 0 ; j < (sizeof(a_) / sizeof(a_[0])) ; j++)
      if ((simde_test_codegen_rand() & 3) == 0)
        b_[j] = a_[j];

    simde__m256i a = simde_mm256_loadu_epi8(a_);
    simde__m256i b = simde_mm256_loadu_epi8(b_);
    simde__mmask32 r = simde_mm256_cmpge_epu8_mask(a, b);

    simde_test_x86_write_u8x32(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_u8x32(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_mask_cmpge_epu8_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask32 k;
    const uint8_t a[32];
    const uint8_t b[32];
    const simde__mmask32 r;
  } test_vec[] = {
    { UINT32_C(1703903725),
      { UINT8_C( 79), UINT8_C(168), UINT8_C(116), UINT8_C( 79), UINT8_C(  9), UINT8_C(111), UINT8_C(105), UINT8_C( 41),
        UINT8_C(190), UINT8_C(241), UINT8_C(146), UINT8_C(205), UINT8_C(103), UINT8_C(177), UINT8_C(167), UINT8_C( 14),
        UINT8_C( 37), UINT8_C( 23), UINT8_C(142), UINT8_C( 61), UINT8_C( 94), UINT8_C(171), UINT8_C(  7), UINT8_C(253),
        UINT8_C(196), UINT8_C(217), UINT8_C(226), UINT8_C(242), UINT8_C( 82), UINT8_C(216), UINT8_C(202), UINT8_C(161) },
      { UINT8_C(128), UINT8_C( 63), UINT8_C(241), UINT8_C( 79), UINT8_C(  9), UINT8_C(111), UINT8_C(179), UINT8_C(108),
        UINT8_C( 75), UINT8_C( 69), UINT8_C( 58), UINT8_C(205), UINT8_C(103), UINT8_C(225), UINT8_C(193), UINT8_C( 14),
        UINT8_C(248), UINT8_C( 23), UINT8_C( 89), UINT8_C( 86), UINT8_C(250), UINT8_C( 96), UINT8_C(  7), UINT8_C(190),
        UINT8_C( 57), UINT8_C( 54), UINT8_C(177), UINT8_C(242), UINT8_C( 82), UINT8_C(123), UINT8_C(202), UINT8_C(143) },
      UINT32_C(1703313704) },
    { UINT32_C(3445983211),
      { UINT8_C( 77), UINT8_C(100), UINT8_C( 40), UINT8_C( 94), UINT8_C(115), UINT8_C(159), UINT8_C(102), UINT8_C( 99),
        UINT8_C(214), UINT8_C(138), UINT8_C( 76), UINT8_C( 93), UINT8_C(  6), UINT8_C(139), UINT8_C(223), UINT8_C(227),
        UINT8_C( 30), UINT8_C( 31), UINT8_C(250), UINT8_C(231), UINT8_C( 16), UINT8_C(156), UINT8_C(192), UINT8_C(124),
        UINT8_C(107), UINT8_C( 40), UINT8_C(163), UINT8_C( 88), UINT8_C(169), UINT8_C( 51), UINT8_C(189), UINT8_C(246) },
      { UINT8_C(151), UINT8_C(229), UINT8_C( 40), UINT8_C( 11), UINT8_C(132), UINT8_C(187), UINT8_C(110), UINT8_C( 91),
        UINT8_C( 69), UINT8_C(186), UINT8_C(184), UINT8_C( 75), UINT8_C( 69), UINT8_C(151), UINT8_C( 47), UINT8_C(227),
        UINT8_C(182), UINT8_C( 41), UINT8_C( 75), UINT8_C(198), UINT8_C( 16), UINT8_C( 11), UINT8_C( 67), UINT8_C( 48),
        UINT8_C(107), UINT8_C(230), UINT8_C(136), UINT8_C(220), UINT8_C(169), UINT8_C( 69), UINT8_C(210), UINT8_C(177) },
      UINT32_C(2237956488) },
    { UINT32_C( 519542194),
      { UINT8_C(177), UINT8_C(111), UINT8_C(243), UINT8_C(150), UINT8_C( 50), UINT8_C(101), UINT8_C(193), UINT8_C(140),
        UINT8_C(  6), UINT8_C( 79), UINT8_C(156), UINT8_C(208), UINT8_C( 40), UINT8_C(115), UINT8_C( 95), UINT8_C( 12),
        UINT8_C(141), UINT8_C( 30), UINT8_C( 35), UINT8_C(142), UINT8_C(101), UINT8_C( 22), UINT8_C(168), UINT8_C(241),
        UINT8_C(219), UINT8_C(115), UINT8_C(168), UINT8_C(198), UINT8_C(250), UINT8_C( 13), UINT8_C(147), UINT8_C(171) },
      { UINT8_C(125), UINT8_C(135), UINT8_C( 66), UINT8_C(175), UINT8_C( 50), UINT8_C(  3), UINT8_C( 59), UINT8_C(243),
        UINT8_C(  6), UINT8_C(215), UINT8_C(156), UINT8_C(122), UINT8_C( 75), UINT8_C( 35), UINT8_C( 95), UINT8_C(216),
        UINT8_C( 65), UINT8_C(169), UINT8_C(102), UINT8_C(167), UINT8_C(191), UINT8_C( 14), UINT8_C(168), UINT8_C(154),
        UINT8_C(129), UINT8_C(115), UINT8_C( 96), UINT8_C(198), UINT8_C(250), UINT8_C(244), UINT8_C( 39), UINT8_C(203) },
      UINT32_C( 518063408) },
    { UINT32_C( 543536449),
      { UINT8_C( 74), UINT8_C( 81), UINT8_C(220), UINT8_C(215), UINT8_C(111), UINT8_C( 20), UINT8_C(174), UINT8_C(176),
        UINT8_C(210), UINT8_C( 94), UINT8_C( 51), UINT8_C( 57), UINT8_C(117), UINT8_C( 92), UINT8_C( 95), UINT8_C(154),
        UINT8_C( 30), UINT8_C( 31), UINT8_C( 64), UINT8_C( 33), UINT8_C( 63), UINT8_C( 98), UINT8_C(113), UINT8_C( 84),
        UINT8_C(171), UINT8_C(141), UINT8_C(227), UINT8_C( 93), UINT8_C( 34), UINT8_C(218), UINT8_C(123), UINT8_C(109) },
      { UINT8_C( 44), UINT8_C( 87), UINT8_C( 68), UINT8_C(155), UINT8_C(107), UINT8_C(242), UINT8_C(174), UINT8_C(176),
        UINT8_C(210), UINT8_C(127), UINT8_C(118), UINT8_C( 57), UINT8_C(117), UINT8_C(213), UINT8_C( 96), UINT8_C(154),
        UINT8_C(244), UINT8_C(160), UINT8_C( 64), UINT8_C( 52), UINT8_C(  3), UINT8_C( 98), UINT8_C(113), UINT8_C(174),
        UINT8_C(171), UINT8_C(141), UINT8_C( 12), UINT8_C( 60), UINT8_C( 34), UINT8_C(218), UINT8_C(123), UINT8_C(114) },
      UINT32_C( 543461697) },
    { UINT32_C(1478443571),
      { UINT8_C( 15), UINT8_C(237), UINT8_C( 81), UINT8_C(231), UINT8_C(236), UINT8_C( 71), UINT8_C(155), UINT8_C(192),
        UINT8_C(158), UINT8_C( 73), UINT8_C(136), UINT8_C(149), UINT8_C( 18), UINT8_C(133), UINT8_C(143), UINT8_C(104),
        UINT8_C(  9), UINT8_C( 55), UINT8_C(215), UINT8_C(249), UINT8_C(236), UINT8_C(130), UINT8_C( 47), UINT8_C( 40),
        UINT8_C(214), UINT8_C(215), UINT8_C( 67), UINT8_C( 23), UINT8_C(141), UINT8_C(168), UINT8_C( 55), UINT8_C(156) },
      { UINT8_C(150), UINT8_C(136), UINT8_C(131), UINT8_C(130), UINT8_C(208), UINT8_C( 31), UINT8_C( 66), UINT8_C(110),
        UINT8_C(104), UINT8_C(202), UINT8_C(136), UINT8_C(123), UINT8_C( 18), UINT8_C(146), UINT8_C(227), UINT8_C( 89),
        UINT8_C(201), UINT8_C( 55), UINT8_C( 82), UINT8_C(181), UINT8_C( 60), UINT8_C(130), UINT8_C(221), UINT8_C( 40),
        UINT8_C( 89), UINT8_C(215), UINT8_C( 41), UINT8_C(230), UINT8_C(201), UINT8_C( 96), UINT8_C(130), UINT8_C( 95) },
      UINT32_C(   1966130) },
    { UINT32_C(2806853537),
      { UINT8_C(101), UINT8_C( 70), UINT8_C(229), UINT8_C( 82), UINT8_C(112), UINT8_C(238), UINT8_C(143), UINT8_C( 44),
        UINT8_C(217), UINT8_C( 37), UINT8_C(177), UINT8_C(127), UINT8_C( 14), UINT8_C(236), UINT8_C( 96), UINT8_C(120),
        UINT8_C(  5), UINT8_C( 84), UINT8_C( 60), UINT8_C( 62), UINT8_C(112), UINT8_C(231), UINT8_C( 64), UINT8_C(237),
        UINT8_C( 20), UINT8_C(161), UINT8_C( 83), UINT8_C( 71), UINT8_C(227), UINT8_C(114), UINT8_C(159), UINT8_C( 72) },
      { UINT8_C(101), UINT8_C( 70), UINT8_C(229), UINT8_C( 40), UINT8_C(114), UINT8_C( 42), UINT8_C( 84), UINT8_C( 76),
        UINT8_C( 79), UINT8_C(  6), UINT8_C(203), UINT8_C( 93), UINT8_C(242), UINT8_C( 43), UINT8_C(214), UINT8_C(120),
        UINT8_C(127), UINT8_C( 18), UINT8_C( 60), UINT8_C(240), UINT8_C(112), UINT8_C(117), UINT8_C(221), UINT8_C( 13),
        UINT8_C( 22), UINT8_C( 49), UINT8_C( 83), UINT8_C(249), UINT8_C(163), UINT8_C(243), UINT8_C( 65), UINT8_C( 92) },
      UINT32_C( 100936481) },
    { UINT32_C( 875947688),
      { UINT8_C(  8), UINT8_C(131), UINT8_C(253), UINT8_C(231), UINT8_C(133), UINT8_C(176), UINT8_C(184), UINT8_C(178),
        UINT8_C( 57), UINT8_C(129), UINT8_C( 94), UINT8_C(212), UINT8_C(128), UINT8_C(251), UINT8_C(105), UINT8_C(244),
        UINT8_C(117), UINT8_C( 12), UINT8_C(126), UINT8_C( 32), UINT8_C(  3), UINT8_C(  2), UINT8_C(110), UINT8_C(237),
        UINT8_C(200), UINT8_C( 25), UINT8_C( 80), UINT8_C(105), UINT8_C( 72), UINT8_C(157), UINT8_C( 17), UINT8_C( 80) },
      { UINT8_C( 32), UINT8_C(131), UINT8_C(253), UINT8_C(231), UINT8_C(133), UINT8_C(176), UINT8_C( 87), UINT8_C(247),
        UINT8_C(113), UINT8_C(182), UINT8_C(203), UINT8_C(241), UINT8_C(128), UINT8_C( 53), UINT8_C(229), UINT8_C( 38),
        UINT8_C( 65), UINT8_C( 99), UINT8_C( 70), UINT8_C( 32), UINT8_C(102), UINT8_C(180), UINT8_C( 49), UINT8_C( 46),
        UINT8_C(200), UINT8_C(129), UINT8_C(151), UINT8_C( 21), UINT8_C( 30), UINT8_C(157), UINT8_C(101), UINT8_C( 63) },
      UINT32_C( 805675048) },
    { UINT32_C( 409954945),
      { UINT8_C( 34), UINT8_C(161), UINT8_C( 49), UINT8_C( 20), UINT8_C(216), UINT8_C( 31), UINT8_C(183), UINT8_C( 68),
        UINT8_C(242), UINT8_C(128), UINT8_C(241), UINT8_C( 41), UINT8_C(143), UINT8_C(226), UINT8_C(197), UINT8_C( 82),
        UINT8_C(  4), UINT8_C(144), UINT8_C(227), UINT8_C(168), UINT8_C(242), UINT8_C(138), UINT8_C(107), UINT8_C(252),
        UINT8_C(150), UINT8_C(108), UINT8_C(189), UINT8_C( 62), UINT8_C( 82), UINT8_C(243), UINT8_C(115), UINT8_C(116) },
      { UINT8_C(148), UINT8_C(164), UINT8_C( 49), UINT8_C(108), UINT8_C(196), UINT8_C( 31), UINT8_C(176), UINT8_C(182),
        UINT8_C(191), UINT8_C(128), UINT8_C(241), UINT8_C( 41), UINT8_C(131), UINT8_C(165), UINT8_C(161), UINT8_C(135),
        UINT8_C( 53), UINT8_C(132), UINT8_C( 48), UINT8_C(168), UINT8_C( 14), UINT8_C(155), UINT8_C( 35), UINT8_C(164),
        UINT8_C(  7), UINT8_C(108), UINT8_C(189), UINT8_C( 90), UINT8_C(212), UINT8_C( 86), UINT8_C(206), UINT8_C(116) },
      UINT32_C(   5138944) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__mmask32 k = test_vec[i].k;
    simde__m256i a = simde_mm256_loadu_epi8(test_vec[i].a);
    simde__m256i b = simde_mm256_loadu_epi8(test_vec[i].b);
    simde__mmask32 r = simde_mm256_mask_cmpge_epu8_mask(k, a, b);
    simde_assert_equal_mmask32(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    uint8_t a_[32];
    uint8_t b_[32];

    simde_test_codegen_random_memory(sizeof(a_), HEDLEY_REINTERPRET_CAST(uint8_t*, a_));
    simde_test_codegen_random_memory(sizeof(b_), HEDLEY_REINTERPRET_CAST(uint8_t*, b_));
    for (size_t j = 0 ; j < (sizeof(a_) / sizeof(a_[0])) ; j++)
      if ((simde_test_codegen_rand() & 3) == 0)
        b_[j] = a_[j];

    simde__mmask32 k = simde_test_x86_random_mmask32();
    simde__m256i a = simde_mm256_loadu_epi8(a_);
    simde__m256i b = simde_mm256_loadu_epi8(b_);
    simde__mmask32 r = simde_mm256_mask_cmpge_epu8_mask(k, a, b);

    simde_test_x86_write_mmask32(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_u8x32(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_u8x32(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_x_mm512_cmpge_epu8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const uint8_t a[64];
    const uint8_t b[64];
    const uint8_t r[64];
  } test_vec[] = {
    { { UINT8_C(238), UINT8_C(228), UINT8_C(110), UINT8_C( 19), UINT8_C( 56), UINT8_C( 18), UINT8_C(187), UINT8_C( 50),
        UINT8_C( 88), UINT8_C(234), UINT8_C( 96), UINT8_C( 34), UINT8_C( 74), UINT8_C(182), UINT8_C(250), UINT8_C( 68),
        UINT8_C( 47), UINT8_C(119), UINT8_C( 70), UINT8_C(137), UINT8_C(215), UINT8_C(162), UINT8_C(183), UINT8_C(141),
        UINT8_C(205), UINT8_C( 77), UINT8_C( 62), UINT8_C( 78), UINT8_C(183), UINT8_C(173), UINT8_C(102), UINT8_C(165),
        UINT8_C(145), UINT8_C(212), UINT8_C(184), UINT8_C(201), UINT8_C(231), UINT8_C(115), UINT8_C(251), UINT8_C( 63),
        UINT8_C( 93), UINT8_C( 92), UINT8_C( 97), UINT8_C(167), UINT8_C( 18), UINT8_C( 91), UINT8_C(236), UINT8_C( 65),
        UINT8_C(211), UINT8_C( 50), UINT8_C(202), UINT8_C(170), UINT8_C(213), UINT8_C(129), UINT8_C( 56), UINT8_C(162),
        UINT8_C(206), UINT8_C(118), UINT8_C(240), UINT8_C(133), UINT8_C( 35), UINT8_C( 87), UINT8_C( 42), UINT8_C(180) },
      { UINT8_C( 43), UINT8_C(226), UINT8_C(110), UINT8_C( 18), UINT8_C( 56), UINT8_C(121), UINT8_C( 81), UINT8_C(178),
        UINT8_C(213), UINT8_C(178), UINT8_C( 96), UINT8_C(231), UINT8_C( 74), UINT8_C(182), UINT8_C(250), UINT8_C(225),
        UINT8_C(120), UINT8_C(119), UINT8_C(139), UINT8_C( 77), UINT8_C(115), UINT8_C(195), UINT8_C(239), UINT8_C( 65),
        UINT8_C( 57), UINT8_C( 77), UINT8_C( 62), UINT8_C( 78), UINT8_C( 55), UINT8_C(173), UINT8_C( 16), UINT8_C( 98),
        UINT8_C(210), UINT8_C(142), UINT8_C(117), UINT8_C( 39), UINT8_C(  7), UINT8_C(198), UINT8_C(217), UINT8_C( 63),
        UINT8_C(121), UINT8_C( 51), UINT8_C(195), UINT8_C(167), UINT8_C(121), UINT8_C(235), UINT8_C(104), UINT8_C(242),
        UINT8_C(221), UINT8_C(243), UINT8_C( 63), UINT8_C( 80), UINT8_C(183), UINT8_C(129), UINT8_C( 56), UINT8_C(240),
        UINT8_C(206), UINT8_C(118), UINT8_C( 77), UINT8_C( 70), UINT8_C( 35), UINT8_C( 93), UINT8_C(168), UINT8_C( 25) },
      {    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),
        UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),
        UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,
           UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
        UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,
        UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),
        UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),
           UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX } },
    { { UINT8_C( 22), UINT8_C(130), UINT8_C(116), UINT8_C( 97), UINT8_C(192), UINT8_C(247), UINT8_C(249), UINT8_C(143),
        UINT8_C( 94), UINT8_C( 88), UINT8_C(219), UINT8_C( 17), UINT8_C(111), UINT8_C(129), UINT8_C(  4), UINT8_C(126),
        UINT8_C(208), UINT8_C(237), UINT8_C(180), UINT8_C( 89), UINT8_C(189), UINT8_C( 32), UINT8_C(116), UINT8_C(193),
        UINT8_C(  8), UINT8_C(104), UINT8_C( 86), UINT8_C( 20), UINT8_C( 77), UINT8_C(105), UINT8_C( 99), UINT8_C( 99),
        UINT8_C(235), UINT8_C(215), UINT8_C(197), UINT8_C(171), UINT8_C(207), UINT8_C(190), UINT8_C( 58), UINT8_C( 45),
        UINT8_C( 22), UINT8_C( 22), UINT8_C( 63), UINT8_C(133), UINT8_C(151), UINT8_C( 67), UINT8_C(  3), UINT8_C(103),
        UINT8_C( 48), UINT8_C(183), UINT8_C(192), UINT8_C(237), UINT8_C(215), UINT8_C( 53), UINT8_C(174), UINT8_C(223),
        UINT8_C(157), UINT8_C(  4), UINT8_C(244), UINT8_C(234), UINT8_C(109), UINT8_C( 87), UINT8_C( 77), UINT8_C( 88) },
      { UINT8_C( 46), UINT8_C( 18), UINT8_C(116), UINT8_C(253), UINT8_C(209), UINT8_C( 62), UINT8_C( 43), UINT8_C(231),
        UINT8_C( 84), UINT8_C(106), UINT8_C(109), UINT8_C(235), UINT8_C(173), UINT8_C(112), UINT8_C(  4), UINT8_C(221),
        UINT8_C( 40), UINT8_C(237), UINT8_C(180),    UINT8_MAX, UINT8_C( 71), UINT8_C( 32), UINT8_C(223), UINT8_C(228),
        UINT8_C(124), UINT8_C(211), UINT8_C(206), UINT8_C( 20), UINT8_C( 42), UINT8_C( 28), UINT8_C( 99), UINT8_C( 99),
        UINT8_C(235), UINT8_C(215), UINT8_C( 86),    UINT8_MAX, UINT8_C(132), UINT8_C(190), UINT8_C(231), UINT8_C(216),
        UINT8_C(235), UINT8_C( 22), UINT8_C(195), UINT8_C(152), UINT8_C(151), UINT8_C( 21), UINT8_C(117), UINT8_C(236),
        UINT8_C( 39), UINT8_C( 63), UINT8_C(192), UINT8_C(111), UINT8_C(183), UINT8_C(203), UINT8_C( 83), UINT8_C( 51),
        UINT8_C(158), UINT8_C( 34), UINT8_C( 29), UINT8_C(200), UINT8_C(109), UINT8_C( 87), UINT8_C( 32), UINT8_C( 88) },
      { UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),
           UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),
           UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),
        UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
           UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),
        UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),
           UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,
        UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX } },
    { { UINT8_C(212), UINT8_C(237), UINT8_C(212), UINT8_C( 36), UINT8_C( 85), UINT8_C(186), UINT8_C( 26), UINT8_C(131),
        UINT8_C( 26), UINT8_C(124), UINT8_C(138), UINT8_C(106), UINT8_C( 54), UINT8_C(147), UINT8_C(233), UINT8_C( 52),
        UINT8_C( 13), UINT8_C( 77), UINT8_C( 65), UINT8_C( 74), UINT8_C(202), UINT8_C(251), UINT8_C(110), UINT8_C(125),
        UINT8_C( 42), UINT8_C(181), UINT8_C(199), UINT8_C(239), UINT8_C(141), UINT8_C( 78), UINT8_C(191), UINT8_C( 98),
        UINT8_C( 59), UINT8_C(147), UINT8_C(134), UINT8_C(144), UINT8_C( 77), UINT8_C(160), UINT8_C( 19), UINT8_C(104),
        UINT8_C( 29), UINT8_C(158), UINT8_C(210), UINT8_C( 83), UINT8_C( 49), UINT8_C(187), UINT8_C(136), UINT8_C( 62),
        UINT8_C(  8), UINT8_C(201), UINT8_C(137), UINT8_C(210), UINT8_C(197), UINT8_C(247), UINT8_C( 80), UINT8_C(239),
        UINT8_C(172), UINT8_C( 23), UINT8_C(222), UINT8_C( 58), UINT8_C(101), UINT8_C(158), UINT8_C(156), UINT8_C(160) },
      { UINT8_C( 49), UINT8_C(237), UINT8_C( 49), UINT8_C( 36), UINT8_C(194), UINT8_C(186), UINT8_C(231), UINT8_C(223),
        UINT8_C( 26), UINT8_C(185), UINT8_C( 51), UINT8_C( 20), UINT8_C(117), UINT8_C(147), UINT8_C( 82), UINT8_C(125),
        UINT8_C(132), UINT8_C( 77), UINT8_C( 80), UINT8_C( 73), UINT8_C(210), UINT8_C(160), UINT8_C( 57), UINT8_C(127),
        UINT8_C( 42), UINT8_C(181), UINT8_C(185), UINT8_C( 29), UINT8_C(181), UINT8_C( 78), UINT8_C(189), UINT8_C( 98),
        UINT8_C( 59), UINT8_C(147), UINT8_C(102), UINT8_C( 57), UINT8_C( 51), UINT8_C( 77), UINT8_C( 25), UINT8_C( 21),
        UINT8_C(  6), UINT8_C(158), UINT8_C( 41), UINT8_C(123), UINT8_C( 49), UINT8_C(187), UINT8_C(249), UINT8_C(139),
        UINT8_C(  8), UINT8_C( 73), UINT8_C(213), UINT8_C( 42), UINT8_C(197), UINT8_C( 14), UINT8_C(169), UINT8_C(239),
        UINT8_C( 37), UINT8_C( 23), UINT8_C(189), UINT8_C( 58), UINT8_C(101), UINT8_C(158), UINT8_C(194), UINT8_C( 46) },
      {    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),
           UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),
        UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),
           UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
           UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,
           UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),
           UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,
           UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX } },
    { { UINT8_C(104), UINT8_C(  2), UINT8_C(162), UINT8_C( 25), UINT8_C(181), UINT8_C(191), UINT8_C(151), UINT8_C( 67),
        UINT8_C(211), UINT8_C(232), UINT8_C( 41), UINT8_C(215), UINT8_C(152), UINT8_C(190), UINT8_C( 20), UINT8_C(124),
        UINT8_C( 44), UINT8_C(115), UINT8_C(162), UINT8_C( 28), UINT8_C(149), UINT8_C( 47), UINT8_C(240), UINT8_C( 54),
           UINT8_MAX, UINT8_C( 95), UINT8_C(211), UINT8_C(212), UINT8_C(151), UINT8_C(212), UINT8_C(213), UINT8_C(  0),
        UINT8_C(214), UINT8_C(119), UINT8_C( 25), UINT8_C(139), UINT8_C( 55), UINT8_C(176), UINT8_C(206), UINT8_C( 10),
        UINT8_C(152), UINT8_C(248), UINT8_C(226), UINT8_C( 48), UINT8_C(182), UINT8_C(246), UINT8_C(172), UINT8_C(227),
        UINT8_C(106), UINT8_C( 78),    UINT8_MAX,    UINT8_MAX, UINT8_C(126), UINT8_C(240), UINT8_C( 53), UINT8_C(125),
        UINT8_C( 79), UINT8_C(  8), UINT8_C( 81), UINT8_C(231), UINT8_C(220), UINT8_C( 38), UINT8_C(231), UINT8_C(178) },
      { UINT8_C(158), UINT8_C(  0), UINT8_C( 61), UINT8_C(213), UINT8_C(177), UINT8_C(191), UINT8_C(223), UINT8_C( 73),
        UINT8_C(211), UINT8_C(193), UINT8_C(122), UINT8_C(186), UINT8_C(184), UINT8_C( 38), UINT8_C(157), UINT8_C( 34),
        UINT8_C(117), UINT8_C(157), UINT8_C(162), UINT8_C(243), UINT8_C(141), UINT8_C( 86), UINT8_C(240), UINT8_C(220),
           UINT8_MAX, UINT8_C( 95), UINT8_C(195), UINT8_C(212), UINT8_C(232), UINT8_C(170), UINT8_C(238), UINT8_C(134),
        UINT8_C(171), UINT8_C( 43), UINT8_C( 91), UINT8_C( 92), UINT8_C( 55), UINT8_C( 59), UINT8_C(165), UINT8_C( 59),
        UINT8_C(252), UINT8_C( 31), UINT8_C(226), UINT8_C(180), UINT8_C( 70), UINT8_C(147), UINT8_C(172), UINT8_C(187),
        UINT8_C(106), UINT8_C( 78), UINT8_C(174), UINT8_C(189), UINT8_C( 78), UINT8_C( 30), UINT8_C( 53), UINT8_C(173),
        UINT8_C(224), UINT8_C( 93), UINT8_C(232), UINT8_C(201), UINT8_C(  8), UINT8_C(214), UINT8_C( 79), UINT8_C(179) },
      { UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),
           UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,
        UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),
           UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),
           UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),
        UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
           UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),
        UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0) } },
    { { UINT8_C(248), UINT8_C(109), UINT8_C( 34), UINT8_C( 90), UINT8_C( 61), UINT8_C( 48), UINT8_C(145), UINT8_C(119),
        UINT8_C(213), UINT8_C(225), UINT8_C(176), UINT8_C(232), UINT8_C(  7), UINT8_C( 24), UINT8_C( 95), UINT8_C(175),
        UINT8_C(109), UINT8_C(138), UINT8_C(249), UINT8_C( 72), UINT8_C( 20), UINT8_C(197), UINT8_C(  7), UINT8_C(231),
        UINT8_C(220), UINT8_C(178), UINT8_C(217), UINT8_C(142), UINT8_C(252), UINT8_C(236), UINT8_C(133), UINT8_C(244),
        UINT8_C( 90), UINT8_C(167), UINT8_C( 78), UINT8_C(151), UINT8_C(216), UINT8_C(223), UINT8_C( 14), UINT8_C(173),
        UINT8_C(193), UINT8_C(191), UINT8_C(149), UINT8_C(200), UINT8_C(215), UINT8_C(245), UINT8_C(119), UINT8_C( 68),
        UINT8_C(127), UINT8_C(113), UINT8_C(140), UINT8_C(147), UINT8_C( 54), UINT8_C(147), UINT8_C(123), UINT8_C( 19),
        UINT8_C( 69), UINT8_C( 84), UINT8_C(161), UINT8_C( 65), UINT8_C( 65), UINT8_C( 38), UINT8_C( 53), UINT8_C(155) },
      { UINT8_C(205), UINT8_C(109), UINT8_C( 50), UINT8_C( 90), UINT8_C( 99), UINT8_C( 64), UINT8_C( 83), UINT8_C( 36),
           UINT8_MAX, UINT8_C(232), UINT8_C(236), UINT8_C(215), UINT8_C(221), UINT8_C(100), UINT8_C( 27), UINT8_C( 92),
        UINT8_C(213), UINT8_C(168), UINT8_C(240), UINT8_C( 11), UINT8_C( 59), UINT8_C(107), UINT8_C( 30), UINT8_C(231),
        UINT8_C(191), UINT8_C(191), UINT8_C(194), UINT8_C(142), UINT8_C(252), UINT8_C(236), UINT8_C(155), UINT8_C(179),
        UINT8_C( 90), UINT8_C(205), UINT8_C( 88), UINT8_C(151), UINT8_C(216), UINT8_C(171), UINT8_C(  4), UINT8_C( 13),
        UINT8_C(148), UINT8_C(191), UINT8_C(228), UINT8_C(113), UINT8_C( 84), UINT8_C(  0), UINT8_C(206), UINT8_C( 68),
        UINT8_C(168), UINT8_C(190), UINT8_C( 53), UINT8_C(227), UINT8_C( 41), UINT8_C( 83), UINT8_C(100), UINT8_C(232),
        UINT8_C( 69), UINT8_C( 84), UINT8_C(233), UINT8_C( 65), UINT8_C( 31), UINT8_C(132), UINT8_C(171), UINT8_C(155) },
      {    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,
        UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,
        UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,
           UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,
           UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
           UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,
        UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),
           UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX } },
    { { UINT8_C( 78), UINT8_C(216), UINT8_C( 25), UINT8_C(106), UINT8_C(184), UINT8_C( 61), UINT8_C(245), UINT8_C(233),
        UINT8_C( 21), UINT8_C( 68), UINT8_C(109), UINT8_C(113), UINT8_C(127), UINT8_C(234), UINT8_C( 13), UINT8_C(221),
        UINT8_C( 69), UINT8_C( 20), UINT8_C(176), UINT8_C(226), UINT8_C(109), UINT8_C( 11), UINT8_C(232), UINT8_C(  1),
        UINT8_C(232), UINT8_C(118), UINT8_C( 86), UINT8_C(241), UINT8_C( 39), UINT8_C(188), UINT8_C( 42), UINT8_C(118),
        UINT8_C(149), UINT8_C( 68), UINT8_C(224), UINT8_C( 77), UINT8_C(129), UINT8_C(214), UINT8_C( 54), UINT8_C(150),
        UINT8_C( 26), UINT8_C(163), UINT8_C(  7), UINT8_C(153), UINT8_C(142), UINT8_C( 21), UINT8_C(118), UINT8_C(211),
        UINT8_C( 41), UINT8_C( 38), UINT8_C(182), UINT8_C(150), UINT8_C( 50), UINT8_C(158), UINT8_C(151), UINT8_C( 26),
        UINT8_C( 21), UINT8_C(237), UINT8_C( 11), UINT8_C( 60), UINT8_C(170), UINT8_C( 53), UINT8_C(178), UINT8_C( 63) },
      { UINT8_C(121), UINT8_C(147), UINT8_C(140), UINT8_C(250), UINT8_C(184), UINT8_C( 61), UINT8_C(145), UINT8_C(131),
        UINT8_C( 21), UINT8_C(152), UINT8_C(109), UINT8_C(244), UINT8_C(173), UINT8_C(234), UINT8_C(199), UINT8_C(214),
        UINT8_C( 69), UINT8_C(125), UINT8_C(108), UINT8_C(226), UINT8_C( 28), UINT8_C( 11), UINT8_C(  5), UINT8_C(  1),
        UINT8_C(241), UINT8_C( 16), UINT8_C( 86), UINT8_C(155), UINT8_C( 70), UINT8_C( 32), UINT8_C(218), UINT8_C(118),
        UINT8_C(149), UINT8_C( 68), UINT8_C(186), UINT8_C( 77), UINT8_C( 41), UINT8_C( 75), UINT8_C(159), UINT8_C(143),
        UINT8_C(227), UINT8_C(163), UINT8_C(131), UINT8_C(145), UINT8_C(142), UINT8_C( 74), UINT8_C(103), UINT8_C(211),
        UINT8_C( 41), UINT8_C( 38), UINT8_C(182), UINT8_C(228), UINT8_C(216), UINT8_C(249), UINT8_C( 21), UINT8_C( 26),
        UINT8_C( 21), UINT8_C(130), UINT8_C(101), UINT8_C( 79), UINT8_C(162), UINT8_C( 53), UINT8_C( 15), UINT8_C( 85) },
      { UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
           UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,
           UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
        UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,
           UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,
        UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,
           UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,
           UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0) } },
    { { UINT8_C( 97), UINT8_C(141), UINT8_C(162), UINT8_C( 74), UINT8_C(106), UINT8_C(238),    UINT8_MAX, UINT8_C( 40),
        UINT8_C(194), UINT8_C(206), UINT8_C( 17), UINT8_C(134), UINT8_C(192), UINT8_C(238), UINT8_C( 14), UINT8_C(200),
        UINT8_C(163), UINT8_C( 50), UINT8_C(223), UINT8_C( 68), UINT8_C(187), UINT8_C( 15), UINT8_C( 84), UINT8_C( 15),
        UINT8_C(166), UINT8_C(117), UINT8_C(109), UINT8_C(181), UINT8_C(254), UINT8_C(123), UINT8_C(  3), UINT8_C( 95),
        UINT8_C(  8), UINT8_C(166), UINT8_C(169), UINT8_C(114), UINT8_C(148), UINT8_C(168), UINT8_C(154), UINT8_C( 86),
        UINT8_C(118), UINT8_C(172), UINT8_C(220), UINT8_C( 55), UINT8_C(154), UINT8_C(234),    UINT8_MAX, UINT8_C( 61),
        UINT8_C( 28), UINT8_C(223), UINT8_C(129), UINT8_C(215), UINT8_C(238), UINT8_C(213), UINT8_C(231), UINT8_C(148),
        UINT8_C( 75), UINT8_C( 84), UINT8_C( 73), UINT8_C( 73), UINT8_C(208), UINT8_C( 77), UINT8_C(168), UINT8_C(216) },
      { UINT8_C( 97), UINT8_C( 81), UINT8_C( 75), UINT8_C(135), UINT8_C(249), UINT8_C(238), UINT8_C(221), UINT8_C(111),
        UINT8_C(194), UINT8_C(206), UINT8_C(166), UINT8_C( 44), UINT8_C(163), UINT8_C(166), UINT8_C(105), UINT8_C(191),
        UINT8_C(163), UINT8_C(235), UINT8_C(223), UINT8_C( 68), UINT8_C(192), UINT8_C(125), UINT8_C(  7), UINT8_C( 11),
        UINT8_C(210), UINT8_C( 81), UINT8_C( 84), UINT8_C(162), UINT8_C(158), UINT8_C(252), UINT8_C(  3), UINT8_C(145),
        UINT8_C( 77), UINT8_C(197), UINT8_C(169), UINT8_C( 70), UINT8_C(171), UINT8_C(245), UINT8_C(182), UINT8_C( 60),
        UINT8_C(174), UINT8_C( 92), UINT8_C(104), UINT8_C( 81), UINT8_C(  2), UINT8_C(234),    UINT8_MAX, UINT8_C(135),
        UINT8_C(189), UINT8_C(166), UINT8_C(129), UINT8_C(215), UINT8_C( 36), UINT8_C(  2), UINT8_C(137), UINT8_C(246),
        UINT8_C( 83), UINT8_C(221), UINT8_C(152), UINT8_C(241), UINT8_C(218), UINT8_C( 18), UINT8_C(130), UINT8_C( 39) },
      {    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),
           UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,
           UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,
        UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),
        UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,
        UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),
        UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),
        UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX } },
    { { UINT8_C(165), UINT8_C(175), UINT8_C( 23), UINT8_C(212), UINT8_C(210), UINT8_C( 74), UINT8_C(131), UINT8_C( 30),
        UINT8_C( 11), UINT8_C(181), UINT8_C( 99), UINT8_C(106), UINT8_C(241), UINT8_C( 96), UINT8_C( 14), UINT8_C( 51),
        UINT8_C(145), UINT8_C( 26), UINT8_C(123), UINT8_C(127), UINT8_C(132), UINT8_C( 30), UINT8_C(  9), UINT8_C(229),
        UINT8_C( 11), UINT8_C(  7), UINT8_C( 79), UINT8_C(198), UINT8_C(162), UINT8_C(154), UINT8_C(231), UINT8_C( 72),
        UINT8_C( 73),    UINT8_MAX, UINT8_C( 28), UINT8_C( 28), UINT8_C( 73), UINT8_C(159), UINT8_C( 58), UINT8_C( 85),
        UINT8_C( 84), UINT8_C(157), UINT8_C(191), UINT8_C( 69), UINT8_C(253), UINT8_C(205), UINT8_C(120), UINT8_C(142),
        UINT8_C(231), UINT8_C(244), UINT8_C( 14), UINT8_C(108), UINT8_C( 18), UINT8_C( 23), UINT8_C( 81), UINT8_C( 29),
        UINT8_C( 30), UINT8_C(161), UINT8_C(227), UINT8_C(193), UINT8_C( 59), UINT8_C(203), UINT8_C(  9), UINT8_C(133) },
      { UINT8_C(202), UINT8_C( 37), UINT8_C( 23), UINT8_C( 19), UINT8_C(210), UINT8_C(219), UINT8_C(131), UINT8_C( 24),
        UINT8_C(120), UINT8_C( 40), UINT8_C( 93), UINT8_C(118), UINT8_C(245), UINT8_C(214), UINT8_C(  4), UINT8_C(221),
        UINT8_C(145), UINT8_C( 18), UINT8_C( 73), UINT8_C(127), UINT8_C( 41), UINT8_C(154), UINT8_C(249), UINT8_C(229),
        UINT8_C( 59), UINT8_C(221), UINT8_C(  9), UINT8_C(119), UINT8_C(162), UINT8_C(154), UINT8_C(231), UINT8_C( 72),
        UINT8_C( 55),    UINT8_MAX, UINT8_C(133), UINT8_C(251), UINT8_C(120), UINT8_C(238), UINT8_C( 19), UINT8_C(240),
        UINT8_C( 22), UINT8_C(112), UINT8_C(191), UINT8_C( 11), UINT8_C( 70), UINT8_C(107), UINT8_C(232), UINT8_C( 16),
        UINT8_C(125), UINT8_C(244), UINT8_C(236), UINT8_C(167), UINT8_C(204), UINT8_C(230), UINT8_C(239), UINT8_C(  7),
        UINT8_C(195), UINT8_C(248), UINT8_C(126), UINT8_C(193), UINT8_C( 10), UINT8_C(122), UINT8_C(  9), UINT8_C(133) },
      { UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,
        UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),
           UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,
        UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
           UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),
           UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,
           UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,
        UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i a = simde_mm512_loadu_epi8(test_vec[i].a);
    simde__m512i b = simde_mm512_loadu_epi8(test_vec[i].b);
    simde__m512i r = simde_x_mm512_cmpge_epu8(a, b);
    simde_test_x86_assert_equal_u8x64(r, simde_mm512_loadu_epi8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    uint8_t a_[64];
    uint8_t b_[64];

    simde_test_codegen_random_memory(sizeof(a_), HEDLEY_REINTERPRET_CAST(uint8_t*, a_));
    simde_test_codegen_random_memory(sizeof(b_), HEDLEY_REINTERPRET_CAST(uint8_t*, b_));
    for (size_t j = 0 ; j < (sizeof(a_) / sizeof(a_[0])) ; j++)
      if ((simde_test_codegen_rand() & 3) == 0)
        b_[j] = a_[j];

    simde__m512i a = simde_mm512_loadu_epi8(a_);
    simde__m512i b = simde_mm512_loadu_epi8(b_);
    simde__m512i r = simde_x_mm512_cmpge_epu8(a, b);

    simde_test_x86_write_u8x64(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_u8x64(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_u8x64(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_cmpge_epu8_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const uint8_t a[64];
    const uint8_t b[64];
    const simde__mmask64 r;
  } test_vec[] = {
    { { UINT8_C(177), UINT8_C(195), UINT8_C(175), UINT8_C(228), UINT8_C( 67), UINT8_C(189), UINT8_C(215), UINT8_C(169),
        UINT8_C( 60), UINT8_C(207), UINT8_C( 96), UINT8_C( 22), UINT8_C(222), UINT8_C(231), UINT8_C(124), UINT8_C(240),
        UINT8_C(227), UINT8_C( 58), UINT8_C(235), UINT8_C( 69), UINT8_C( 88), UINT8_C(146), UINT8_C(  3), UINT8_C( 83),
        UINT8_C( 80), UINT8_C( 41), UINT8_C(167), UINT8_C(  2), UINT8_C(246), UINT8_C(107), UINT8_C( 11), UINT8_C(168),
        UINT8_C( 47), UINT8_C(186), UINT8_C(140), UINT8_C(114), UINT8_C(119), UINT8_C( 99), UINT8_C( 27), UINT8_C(180),
        UINT8_C( 51), UINT8_C(123), UINT8_C(202), UINT8_C( 17), UINT8_C( 98), UINT8_C( 71), UINT8_C(  2), UINT8_C( 70),
        UINT8_C(129), UINT8_C(237), UINT8_C(139), UINT8_C(217), UINT8_C(128), UINT8_C(142), UINT8_C( 45), UINT8_C(208),
        UINT8_C(183), UINT8_C(212), UINT8_C(211), UINT8_C(174), UINT8_C( 64), UINT8_C(222), UINT8_C( 86), UINT8_C(111) },
      { UINT8_C(177), UINT8_C(226), UINT8_C(225), UINT8_C( 16), UINT8_C( 70), UINT8_C(189), UINT8_C(196), UINT8_C(121),
        UINT8_C(119), UINT8_C(142), UINT8_C(138), UINT8_C(218), UINT8_C(213), UINT8_C(140), UINT8_C( 32), UINT8_C( 87),
        UINT8_C(122), UINT8_C( 58), UINT8_C( 48), UINT8_C(250), UINT8_C( 88), UINT8_C( 93), UINT8_C(202), UINT8_C(241),
        UINT8_C( 50), UINT8_C(157), UINT8_C(159), UINT8_C(114), UINT8_C(123), UINT8_C(245), UINT8_C(225), UINT8_C( 20),
        UINT8_C( 47), UINT8_C(194), UINT8_C( 36), UINT8_C( 29), UINT8_C(190), UINT8_C(232), UINT8_C(150), UINT8_C( 53),
        UINT8_C(118), UINT8_C(123), UINT8_C( 15), UINT8_C( 17), UINT8_C(173), UINT8_C( 47), UINT8_C(163), UINT8_C( 39),
        UINT8_C(218), UINT8_C(211), UINT8_C(139), UINT8_C( 20), UINT8_C(128), UINT8_C(236), UINT8_C(  5), UINT8_C( 99),
        UINT8_C(137), UINT8_C(164), UINT8_C(213), UINT8_C(  5), UINT8_C( 64), UINT8_C(222), UINT8_C( 25), UINT8_C(112) },
      UINT64_C( 8925763434611995369) },
    { { UINT8_C(186), UINT8_C(130), UINT8_C( 42), UINT8_C(184), UINT8_C( 24), UINT8_C(247), UINT8_C(251), UINT8_C( 42),
        UINT8_C(172), UINT8_C( 50), UINT8_C(230), UINT8_C(235), UINT8_C(131), UINT8_C( 39), UINT8_C(136), UINT8_C( 16),
        UINT8_C(  1), UINT8_C(180), UINT8_C(197), UINT8_C(121), UINT8_C(210), UINT8_C( 43), UINT8_C( 51), UINT8_C(183),
        UINT8_C( 72), UINT8_C(200), UINT8_C( 25), UINT8_C( 53), UINT8_C(168), UINT8_C(112), UINT8_C( 46), UINT8_C( 98),
        UINT8_C(242), UINT8_C( 88), UINT8_C( 26), UINT8_C( 10), UINT8_C( 80), UINT8_C( 22), UINT8_C( 52), UINT8_C(252),
        UINT8_C( 72), UINT8_C( 26), UINT8_C(231), UINT8_C(203), UINT8_C( 65), UINT8_C(111), UINT8_C(219), UINT8_C( 66),
        UINT8_C( 35), UINT8_C(160), UINT8_C(187), UINT8_C(245), UINT8_C(203), UINT8_C(238), UINT8_C(172), UINT8_C( 20),
        UINT8_C(182), UINT8_C(197), UINT8_C( 73), UINT8_C( 95), UINT8_C( 53), UINT8_C(119), UINT8_C(193), UINT8_C( 39) },
      { UINT8_C(207), UINT8_C(220), UINT8_C( 49), UINT8_C(184), UINT8_C(242), UINT8_C(247), UINT8_C( 27), UINT8_C( 58),
        UINT8_C(128), UINT8_C(  2), UINT8_C(  5), UINT8_C(194), UINT8_C(131), UINT8_C(224), UINT8_C(136), UINT8_C(148),
        UINT8_C(128), UINT8_C(192), UINT8_C(197), UINT8_C( 75), UINT8_C(174), UINT8_C( 53), UINT8_C( 95), UINT8_C(101),
        UINT8_C(250), UINT8_C(168), UINT8_C(196), UINT8_C( 47), UINT8_C( 31), UINT8_C(133), UINT8_C( 86), UINT8_C(239),
        UINT8_C( 97), UINT8_C(136), UINT8_C( 14), UINT8_C( 83), UINT8_C(238), UINT8_C( 42), UINT8_C(141), UINT8_C(110),
        UINT8_C( 72), UINT8_C( 26), UINT8_C( 48), UINT8_C(203), UINT8_C(114), UINT8_C( 53), UINT8_C( 50), UINT8_C( 66),
        UINT8_C(245), UINT8_C(188), UINT8_C(187), UINT8_C(245), UINT8_C(241), UINT8_C(157), UINT8_C(  8), UINT8_C( 20),
        UINT8_C( 70), UINT8_C(204), UINT8_C( 73), UINT8_C(101), UINT8_C( 53), UINT8_C(114), UINT8_C( 84), UINT8_C(179) },
      UINT64_C( 8497429951897427816) },
    { { UINT8_C(153), UINT8_C(193), UINT8_C(146), UINT8_C( 99), UINT8_C(171), UINT8_C(163), UINT8_C( 85), UINT8_C( 27),
        UINT8_C( 12), UINT8_C(224), UINT8_C( 72), UINT8_C(254), UINT8_C(247), UINT8_C( 37), UINT8_C( 55), UINT8_C(216),
        UINT8_C( 87), UINT8_C(167), UINT8_C( 32), UINT8_C(230), UINT8_C( 58), UINT8_C( 22), UINT8_C(159), UINT8_C( 13),
        UINT8_C( 31), UINT8_C(211), UINT8_C(144), UINT8_C(144), UINT8_C( 54), UINT8_C(191), UINT8_C(203), UINT8_C(207),
        UINT8_C(128), UINT8_C( 93), UINT8_C( 50), UINT8_C( 43), UINT8_C(  1), UINT8_C(135), UINT8_C( 71), UINT8_C( 13),
        UINT8_C(103), UINT8_C(143), UINT8_C( 11), UINT8_C( 94), UINT8_C(180), UINT8_C( 66), UINT8_C( 54), UINT8_C( 12),
        UINT8_C(233), UINT8_C( 87), UINT8_C(242), UINT8_C( 36), UINT8_C(109), UINT8_C(145), UINT8_C( 49), UINT8_C(141),
        UINT8_C(100), UINT8_C(193), UINT8_C( 29), UINT8_C(154), UINT8_C(128), UINT8_C(232), UINT8_C(105), UINT8_C(  1) },
      { UINT8_C( 69), UINT8_C(193), UINT8_C( 44), UINT8_C( 70), UINT8_C( 35), UINT8_C(115), UINT8_C( 83), UINT8_C(139),
        UINT8_C(  2), UINT8_C( 95), UINT8_C(233), UINT8_C(254), UINT8_C(161), UINT8_C( 32), UINT8_C(195), UINT8_C(216),
        UINT8_C(119), UINT8_C(181), UINT8_C( 32), UINT8_C(230), UINT8_C( 71), UINT8_C(224), UINT8_C(113), UINT8_C(171),
        UINT8_C(161), UINT8_C(142), UINT8_C( 70), UINT8_C( 34), UINT8_C(118), UINT8_C(191), UINT8_C( 35), UINT8_C(188),
        UINT8_C(128), UINT8_C( 79), UINT8_C(  2), UINT8_C(111), UINT8_C(195), UINT8_C(135), UINT8_C(250), UINT8_C( 13),
        UINT8_C(181), UINT8_C(227), UINT8_C(124), UINT8_C( 86), UINT8_C(  3), UINT8_C( 66), UINT8_C(225), UINT8_C(122),
        UINT8_C(245), UINT8_C(144), UINT8_C( 95), UINT8_C( 36), UINT8_C(112), UINT8_C(208), UINT8_C(231), UINT8_C( 18),
        UINT8_C( 95), UINT8_C( 45), UINT8_C( 52), UINT8_C(213), UINT8_C(221), UINT8_C( 87), UINT8_C(145), UINT8_C( 40) },
      UINT64_C( 2561484581975669631) },
    { { UINT8_C(141), UINT8_C( 47), UINT8_C( 88), UINT8_C(237), UINT8_C(227), UINT8_C( 94), UINT8_C(193), UINT8_C( 66),
        UINT8_C( 89), UINT8_C( 14), UINT8_C(141), UINT8_C( 43), UINT8_C( 78), UINT8_C(183), UINT8_C(100), UINT8_C(224),
        UINT8_C(254), UINT8_C(118), UINT8_C(149), UINT8_C( 72), UINT8_C(113), UINT8_C(203), UINT8_C(195), UINT8_C(139),
        UINT8_C( 88), UINT8_C( 76), UINT8_C( 25), UINT8_C(205), UINT8_C( 11), UINT8_C(195), UINT8_C(191), UINT8_C(153),
        UINT8_C(242), UINT8_C( 24), UINT8_C(134), UINT8_C(213), UINT8_C(118), UINT8_C( 71), UINT8_C( 24), UINT8_C(207),
        UINT8_C( 86), UINT8_C(165), UINT8_C(250), UINT8_C(164), UINT8_C( 92), UINT8_C( 94), UINT8_C(133), UINT8_C( 90),
        UINT8_C(212), UINT8_C( 26), UINT8_C(162), UINT8_C( 70), UINT8_C(229), UINT8_C(101), UINT8_C(209), UINT8_C( 61),
        UINT8_C(177), UINT8_C(234), UINT8_C( 10), UINT8_C(189), UINT8_C(174), UINT8_C(202), UINT8_C( 86), UINT8_C(160) },
      { UINT8_C(226), UINT8_C(220), UINT8_C(118), UINT8_C( 88), UINT8_C( 35), UINT8_C(142), UINT8_C(193), UINT8_C( 66),
        UINT8_C( 51), UINT8_C( 33), UINT8_C( 30), UINT8_C(143), UINT8_C(127), UINT8_C(163), UINT8_C(234), UINT8_C(224),
        UINT8_C(189), UINT8_C(118), UINT8_C(154), UINT8_C(162), UINT8_C(242), UINT8_C(107), UINT8_C(223), UINT8_C(163),
        UINT8_C( 88), UINT8_C(233), UINT8_C( 96), UINT8_C(  3), UINT8_C(179), UINT8_C(182), UINT8_C(164), UINT8_C(149),
        UINT8_C(146), UINT8_C( 24), UINT8_C(237), UINT8_C(182), UINT8_C(168), UINT8_C( 20), UINT8_C( 47), UINT8_C(207),
        UINT8_C( 53), UINT8_C( 77), UINT8_C(250), UINT8_C(164), UINT8_C(240), UINT8_C( 84), UINT8_C(133), UINT8_C(173),
        UINT8_C(225), UINT8_C(163), UINT8_C( 79), UINT8_C( 70), UINT8_C( 14), UINT8_C( 46), UINT8_C(118), UINT8_C( 99),
        UINT8_C( 24), UINT8_C(215), UINT8_C(103), UINT8_C(189), UINT8_C(141), UINT8_C( 11), UINT8_C( 97), UINT8_C( 32) },
      UINT64_C(13509795766346163672) },
    { { UINT8_C( 69), UINT8_C(141), UINT8_C( 28), UINT8_C( 55), UINT8_C(  4), UINT8_C( 26), UINT8_C(123), UINT8_C(142),
        UINT8_C(101), UINT8_C(  3), UINT8_C(126), UINT8_C(  6), UINT8_C(124), UINT8_C(183), UINT8_C(161), UINT8_C( 54),
        UINT8_C( 10), UINT8_C( 68), UINT8_C( 94), UINT8_C(239), UINT8_C( 81), UINT8_C( 14), UINT8_C( 61), UINT8_C( 49),
        UINT8_C( 16), UINT8_C(128), UINT8_C(237), UINT8_C(197), UINT8_C(218), UINT8_C(172), UINT8_C(125), UINT8_C( 31),
        UINT8_C( 57), UINT8_C(153), UINT8_C( 86), UINT8_C( 62), UINT8_C(179), UINT8_C(210), UINT8_C(204), UINT8_C( 24),
        UINT8_C(213), UINT8_C( 74), UINT8_C( 31), UINT8_C( 82), UINT8_C(  1), UINT8_C(192), UINT8_C(136), UINT8_C( 12),
        UINT8_C(  4), UINT8_C(230), UINT8_C(251), UINT8_C( 86), UINT8_C(244), UINT8_C( 56), UINT8_C(135), UINT8_C(  4),
        UINT8_C(185), UINT8_C(116), UINT8_C(202), UINT8_C(147), UINT8_C( 32), UINT8_C( 71), UINT8_C(178), UINT8_C( 90) },
      { UINT8_C(224), UINT8_C(  9), UINT8_C( 28), UINT8_C(148), UINT8_C(219), UINT8_C(100), UINT8_C(172), UINT8_C(176),
        UINT8_C(101), UINT8_C(  3), UINT8_C(  2), UINT8_C(  6), UINT8_C(140), UINT8_C(138), UINT8_C(188), UINT8_C(144),
        UINT8_C( 10), UINT8_C( 68), UINT8_C( 94), UINT8_C(239), UINT8_C( 81), UINT8_C(109), UINT8_C(106), UINT8_C(169),
        UINT8_C(226), UINT8_C( 52), UINT8_C(237), UINT8_C(  2), UINT8_C(123), UINT8_C(238), UINT8_C( 92), UINT8_C( 91),
        UINT8_C(247), UINT8_C(244), UINT8_C(239), UINT8_C( 62), UINT8_C( 88), UINT8_C(210), UINT8_C(131), UINT8_C(  7),
        UINT8_C(213), UINT8_C( 74), UINT8_C(183), UINT8_C(243), UINT8_C( 16), UINT8_C(192), UINT8_C(136), UINT8_C(129),
        UINT8_C(  4), UINT8_C(230), UINT8_C(230), UINT8_C( 86), UINT8_C(244), UINT8_C( 80), UINT8_C(195), UINT8_C(186),
        UINT8_C(132),    UINT8_MAX, UINT8_C(202),    UINT8_MAX, UINT8_C(238), UINT8_C( 25), UINT8_C( 91), UINT8_C(229) },
      UINT64_C( 7286652640490893062) },
    { { UINT8_C( 57), UINT8_C(173), UINT8_C(212), UINT8_C(158), UINT8_C( 37), UINT8_C(186), UINT8_C(196), UINT8_C(193),
        UINT8_C(226), UINT8_C(187), UINT8_C(244), UINT8_C(208), UINT8_C(  3), UINT8_C(233), UINT8_C(237), UINT8_C(131),
        UINT8_C(185), UINT8_C( 19), UINT8_C(139), UINT8_C( 41), UINT8_C(250), UINT8_C(161), UINT8_C( 56), UINT8_C( 96),
        UINT8_C(195), UINT8_C(212), UINT8_C( 94), UINT8_C( 76), UINT8_C(227), UINT8_C(  0), UINT8_C(136), UINT8_C( 28),
        UINT8_C(174), UINT8_C( 92), UINT8_C(186), UINT8_C(211), UINT8_C( 22), UINT8_C(127), UINT8_C(149), UINT8_C(249),
        UINT8_C( 58), UINT8_C(137), UINT8_C(201), UINT8_C( 61), UINT8_C(114), UINT8_C(182), UINT8_C(192), UINT8_C( 44),
        UINT8_C(201), UINT8_C( 75), UINT8_C( 85), UINT8_C(196), UINT8_C(236), UINT8_C(142), UINT8_C( 36), UINT8_C(175),
        UINT8_C( 98), UINT8_C(130), UINT8_C(252), UINT8_C( 69), UINT8_C(131), UINT8_C(132), UINT8_C( 97), UINT8_C( 49) },
      { UINT8_C(224), UINT8_C(173), UINT8_C(  4), UINT8_C(158), UINT8_C(155), UINT8_C(153), UINT8_C(196), UINT8_C(213),
        UINT8_C( 35), UINT8_C(184), UINT8_C( 18), UINT8_C(208), UINT8_C(111), UINT8_C(210), UINT8_C(237), UINT8_C(131),
        UINT8_C( 29), UINT8_C( 23), UINT8_C(139), UINT8_C( 10), UINT8_C(165), UINT8_C( 33), UINT8_C(185), UINT8_C(  7),
        UINT8_C(163), UINT8_C(181), UINT8_C( 77), UINT8_C( 38), UINT8_C( 57), UINT8_C(174), UINT8_C( 87), UINT8_C( 25),
        UINT8_C(202), UINT8_C( 92), UINT8_C( 16), UINT8_C(211), UINT8_C(245), UINT8_C(127), UINT8_C(149), UINT8_C( 24),
        UINT8_C(184), UINT8_C( 76), UINT8_C(174), UINT8_C( 61), UINT8_C(114), UINT8_C(111), UINT8_C( 95), UINT8_C( 60),
        UINT8_C(134), UINT8_C( 92), UINT8_C( 70), UINT8_C( 43), UINT8_C(236),    UINT8_MAX, UINT8_C( 51), UINT8_C( 32),
        UINT8_C(181), UINT8_C(128), UINT8_C(252), UINT8_C( 69), UINT8_C( 46), UINT8_C(158), UINT8_C( 97), UINT8_C( 49) },
      UINT64_C(16041117012184657774) },
    { { UINT8_C(156), UINT8_C(199), UINT8_C( 29), UINT8_C( 70), UINT8_C(239), UINT8_C( 77), UINT8_C(213), UINT8_C(206),
        UINT8_C(115), UINT8_C(105), UINT8_C(210), UINT8_C(240), UINT8_C( 60), UINT8_C(131), UINT8_C( 30), UINT8_C(150),
        UINT8_C( 12), UINT8_C(124), UINT8_C(117), UINT8_C(160), UINT8_C( 41), UINT8_C(142), UINT8_C(191), UINT8_C(108),
        UINT8_C(209), UINT8_C(152), UINT8_C(229), UINT8_C( 68), UINT8_C( 35), UINT8_C(141), UINT8_C(  1), UINT8_C(191),
        UINT8_C( 84), UINT8_C( 30), UINT8_C(  5), UINT8_C( 68), UINT8_C(107), UINT8_C(218), UINT8_C( 18), UINT8_C(222),
        UINT8_C( 67), UINT8_C(228), UINT8_C(206), UINT8_C(128), UINT8_C(104), UINT8_C(237), UINT8_C( 22), UINT8_C(116),
        UINT8_C(105), UINT8_C(139), UINT8_C( 21), UINT8_C(146), UINT8_C( 25), UINT8_C(212), UINT8_C(254), UINT8_C(234),
        UINT8_C(108), UINT8_C(227), UINT8_C( 47), UINT8_C(143), UINT8_C(112), UINT8_C( 48), UINT8_C( 78), UINT8_C(197) },
      { UINT8_C(156), UINT8_C(199), UINT8_C(  9), UINT8_C(185), UINT8_C(239), UINT8_C( 27), UINT8_C(151), UINT8_C(113),
           UINT8_MAX, UINT8_C(102), UINT8_C(241), UINT8_C(103), UINT8_C( 83), UINT8_C(131), UINT8_C(220), UINT8_C(188),
        UINT8_C(146), UINT8_C(124), UINT8_C(117), UINT8_C(172), UINT8_C(197), UINT8_C( 76), UINT8_C(150), UINT8_C( 50),
        UINT8_C( 48), UINT8_C(197), UINT8_C(193), UINT8_C(160), UINT8_C(245), UINT8_C( 16), UINT8_C(  1), UINT8_C( 67),
        UINT8_C( 99), UINT8_C(110), UINT8_C(252), UINT8_C(145), UINT8_C(137), UINT8_C(148), UINT8_C(  3), UINT8_C(137),
        UINT8_C(250), UINT8_C(228), UINT8_C(206), UINT8_C( 77), UINT8_C(104), UINT8_C(204), UINT8_C(  9), UINT8_C(142),
        UINT8_C(189), UINT8_C( 87), UINT8_C( 58), UINT8_C(131), UINT8_C( 25), UINT8_C(209), UINT8_C(181), UINT8_C(211),
        UINT8_C(150), UINT8_C(118), UINT8_C(116), UINT8_C(140), UINT8_C(112), UINT8_C(217), UINT8_C( 78), UINT8_C(234) },
      UINT64_C( 6555691711986019063) },
    { { UINT8_C(205), UINT8_C(189), UINT8_C(194), UINT8_C(187), UINT8_C(253), UINT8_C( 67), UINT8_C( 28), UINT8_C(135),
        UINT8_C(107), UINT8_C(236), UINT8_C( 41), UINT8_C( 67), UINT8_C(185), UINT8_C(160), UINT8_C( 34), UINT8_C(191),
        UINT8_C(111), UINT8_C(172), UINT8_C(205), UINT8_C( 75), UINT8_C(179), UINT8_C(123), UINT8_C(171), UINT8_C(173),
        UINT8_C( 85), UINT8_C( 20), UINT8_C(114), UINT8_C( 41), UINT8_C(114), UINT8_C( 74), UINT8_C(197), UINT8_C( 63),
        UINT8_C(  8), UINT8_C(135), UINT8_C(250), UINT8_C(  5), UINT8_C(203), UINT8_C( 22), UINT8_C(140), UINT8_C( 54),
        UINT8_C(  2), UINT8_C(182), UINT8_C(122), UINT8_C(187), UINT8_C( 86), UINT8_C(156), UINT8_C(122), UINT8_C(198),
        UINT8_C( 72), UINT8_C( 72), UINT8_C( 17), UINT8_C(252), UINT8_C(195), UINT8_C(188), UINT8_C(169), UINT8_C( 24),
        UINT8_C(209), UINT8_C( 27), UINT8_C( 66), UINT8_C( 67), UINT8_C(101), UINT8_C(  7), UINT8_C(130), UINT8_C(109) },
      { UINT8_C(142), UINT8_C(124), UINT8_C(114), UINT8_C( 89), UINT8_C(146),    UINT8_MAX, UINT8_C(144), UINT8_C(148),
        UINT8_C(181), UINT8_C( 10), UINT8_C( 79), UINT8_C( 11), UINT8_C(166), UINT8_C(160), UINT8_C(209), UINT8_C(239),
        UINT8_C( 18), UINT8_C(227), UINT8_C(235), UINT8_C(213), UINT8_C(179), UINT8_C(148), UINT8_C(238), UINT8_C(112),
        UINT8_C(175), UINT8_C( 20), UINT8_C(114), UINT8_C( 20), UINT8_C( 55), UINT8_C( 53), UINT8_C(130), UINT8_C(197),
        UINT8_C(177), UINT8_C(244), UINT8_C( 31), UINT8_C( 67), UINT8_C(243), UINT8_C(175), UINT8_C(140), UINT8_C( 54),
        UINT8_C(185), UINT8_C( 39), UINT8_C(180), UINT8_C( 95), UINT8_C(241), UINT8_C(133), UINT8_C( 78), UINT8_C(  3),
        UINT8_C( 72), UINT8_C( 57), UINT8_C(216), UINT8_C(252), UINT8_C(205), UINT8_C(198), UINT8_C(120), UINT8_C(124),
        UINT8_C(246), UINT8_C( 44), UINT8_C( 66), UINT8_C( 45), UINT8_C( 97), UINT8_C( 19), UINT8_C(130), UINT8_C( 19) },
      UINT64_C(15874039441255381535) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i a = simde_mm512_loadu_epi8(test_vec[i].a);
    simde__m512i b = simde_mm512_loadu_epi8(test_vec[i].b);
    simde__mmask64 r = simde_mm512_cmpge_epu8_mask(a, b);
    simde_assert_equal_mmask64(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    uint8_t a_[64];
    uint8_t b_[64];

    simde_test_codegen_random_memory(sizeof(a_), HEDLEY_REINTERPRET_CAST(uint8_t*, a_));
    simde_test_codegen_random_memory(sizeof(b_), HEDLEY_REINTERPRET_CAST(uint8_t*, b_));
    for (size_t j = 0 ; j < (sizeof(a_) / sizeof(a_[0])) ; j++)
      if ((simde_test_codegen_rand() & 3) == 0)
        b_[j] = a_[j];

    simde__m512i a = simde_mm512_loadu_epi8(a_);
    simde__m512i b = simde_mm512_loadu_epi8(b_);
    simde__mmask64 r = simde_mm512_cmpge_epu8_mask(a, b);

    simde_test_x86_write_u8x64(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_u8x64(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask64(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_mask_cmpge_epu8_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask64 k;
    const uint8_t a[64];
    const uint8_t b[64];
    const simde__mmask64 r;
  } test_vec[] = {
    { UINT64_C( 9654859831595975890),
      { UINT8_C(236), UINT8_C(190), UINT8_C(165), UINT8_C(215), UINT8_C(180), UINT8_C(241), UINT8_C( 23), UINT8_C(  1),
        UINT8_C( 22), UINT8_C(157), UINT8_C( 43), UINT8_C(100), UINT8_C(108), UINT8_C(154), UINT8_C( 19), UINT8_C( 92),
        UINT8_C( 87), UINT8_C(241), UINT8_C( 53), UINT8_C(218), UINT8_C(122), UINT8_C(236), UINT8_C( 79), UINT8_C( 64),
        UINT8_C(175), UINT8_C( 24), UINT8_C( 86), UINT8_C(113), UINT8_C( 71), UINT8_C(194), UINT8_C( 68), UINT8_C( 51),
        UINT8_C(129), UINT8_C(233), UINT8_C( 10), UINT8_C( 53), UINT8_C(218), UINT8_C( 33), UINT8_C( 54), UINT8_C(240),
        UINT8_C(190), UINT8_C( 97), UINT8_C( 84), UINT8_C( 42), UINT8_C(251), UINT8_C(103), UINT8_C(134), UINT8_C( 83),
        UINT8_C( 88), UINT8_C(187), UINT8_C( 45), UINT8_C(211), UINT8_C(167), UINT8_C(125), UINT8_C( 19), UINT8_C( 86),
        UINT8_C(149), UINT8_C(105), UINT8_C(199), UINT8_C(220), UINT8_C( 44), UINT8_C( 11), UINT8_C( 15), UINT8_C(173) },
      { UINT8_C(244), UINT8_C( 25), UINT8_C(226), UINT8_C(206), UINT8_C(180), UINT8_C( 24), UINT8_C(191), UINT8_C(248),
        UINT8_C(121), UINT8_C( 19), UINT8_C( 43), UINT8_C(116), UINT8_C(123), UINT8_C(168), UINT8_C(199), UINT8_C(211),
        UINT8_C( 87), UINT8_C(241), UINT8_C( 53), UINT8_C( 11), UINT8_C(114), UINT8_C(186), UINT8_C( 98), UINT8_C( 64),
        UINT8_C( 35), UINT8_C( 41), UINT8_C(227), UINT8_C(113), UINT8_C( 71), UINT8_C(194), UINT8_C(252), UINT8_C( 51),
        UINT8_C( 11), UINT8_C(233), UINT8_C(248), UINT8_C( 69), UINT8_C(218), UINT8_C(183), UINT8_C( 54), UINT8_C(111),
        UINT8_C(202), UINT8_C( 97), UINT8_C( 84), UINT8_C( 69), UINT8_C(  7), UINT8_C(171), UINT8_C( 25), UINT8_C(107),
        UINT8_C(160), UINT8_C(191), UINT8_C(119), UINT8_C(211), UINT8_C(121), UINT8_C(217), UINT8_C( 19), UINT8_C(157),
        UINT8_C(  2), UINT8_C(252), UINT8_C(236), UINT8_C( 55), UINT8_C( 44), UINT8_C(233), UINT8_C( 97), UINT8_C(249) },
      UINT64_C(   96918448385754130) },
    { UINT64_C( 4268896767879416885),
      { UINT8_C(143), UINT8_C(225), UINT8_C(235), UINT8_C(100), UINT8_C( 19), UINT8_C(174), UINT8_C( 49), UINT8_C(  9),
        UINT8_C(226), UINT8_C(113), UINT8_C(157), UINT8_C(159), UINT8_C(191), UINT8_C(209), UINT8_C(226), UINT8_C(  9),
        UINT8_C(221), UINT8_C(153), UINT8_C( 56), UINT8_C( 33), UINT8_C(191), UINT8_C( 18), UINT8_C(246), UINT8_C(145),
        UINT8_C( 87), UINT8_C(109), UINT8_C(139), UINT8_C( 51), UINT8_C( 96), UINT8_C(135), UINT8_C(184), UINT8_C(239),
        UINT8_C(104), UINT8_C(163), UINT8_C( 83), UINT8_C(123), UINT8_C( 81), UINT8_C(133), UINT8_C(133), UINT8_C( 51),
        UINT8_C(246), UINT8_C( 34), UINT8_C(210), UINT8_C(181), UINT8_C(244), UINT8_C(180), UINT8_C(191), UINT8_C(209),
        UINT8_C( 78), UINT8_C(247), UINT8_C(242), UINT8_C( 13), UINT8_C(  9), UINT8_C(232), UINT8_C(158), UINT8_C( 96),
        UINT8_C( 86), UINT8_C( 41), UINT8_C(147), UINT8_C(182), UINT8_C(176), UINT8_C( 75), UINT8_C(166), UINT8_C( 25) },
      { UINT8_C(238), UINT8_C(249), UINT8_C(235), UINT8_C( 64), UINT8_C(126), UINT8_C( 25), UINT8_C(115), UINT8_C(116),
        UINT8_C( 60), UINT8_C( 70), UINT8_C( 42), UINT8_C( 48), UINT8_C(191), UINT8_C(233), UINT8_C(  1), UINT8_C(  9),
        UINT8_C(224), UINT8_C(243), UINT8_C( 85), UINT8_C( 33), UINT8_C(219), UINT8_C( 18), UINT8_C( 74), UINT8_C( 49),
        UINT8_C( 28), UINT8_C(109), UINT8_C(139), UINT8_C( 51), UINT8_C( 41), UINT8_C(142), UINT8_C(230), UINT8_C(239),
        UINT8_C(135), UINT8_C(122), UINT8_C( 87), UINT8_C(  6), UINT8_C(148), UINT8_C(203), UINT8_C(122), UINT8_C(208),
        UINT8_C( 17), UINT8_C( 34), UINT8_C(  0), UINT8_C( 11), UINT8_C(141), UINT8_C(  1), UINT8_C( 84), UINT8_C(109),
        UINT8_C(244), UINT8_C(247), UINT8_C( 87), UINT8_C(207), UINT8_C(157), UINT8_C(232), UINT8_C(  1), UINT8_C(185),
        UINT8_C( 86), UINT8_C(233), UINT8_C(134), UINT8_C(167), UINT8_C(119), UINT8_C(108), UINT8_C(191), UINT8_C( 25) },
      UINT64_C( 1812182397517564964) },
    { UINT64_C( 9387263019044765107),
      { UINT8_C( 14), UINT8_C(  5), UINT8_C(196), UINT8_C( 68), UINT8_C(234), UINT8_C(141), UINT8_C(117), UINT8_C( 69),
        UINT8_C(102), UINT8_C( 63), UINT8_C(183), UINT8_C( 79), UINT8_C( 91), UINT8_C(189), UINT8_C( 49), UINT8_C( 80),
        UINT8_C(  0), UINT8_C(132), UINT8_C(137), UINT8_C( 63), UINT8_C( 70), UINT8_C(239), UINT8_C(143), UINT8_C(124),
        UINT8_C(251), UINT8_C(211), UINT8_C(164), UINT8_C(250), UINT8_C(253), UINT8_C(226), UINT8_C( 53), UINT8_C( 11),
        UINT8_C(231), UINT8_C(250), UINT8_C( 79), UINT8_C(209), UINT8_C(135), UINT8_C(197), UINT8_C( 23), UINT8_C(237),
        UINT8_C(  4), UINT8_C(206), UINT8_C( 60), UINT8_C( 96), UINT8_C(139), UINT8_C(110), UINT8_C(176), UINT8_C(140),
        UINT8_C(242), UINT8_C( 57), UINT8_C(203), UINT8_C( 57), UINT8_C( 40), UINT8_C( 90), UINT8_C(181), UINT8_C( 36),
        UINT8_C( 46), UINT8_C( 89), UINT8_C( 30), UINT8_C( 43), UINT8_C( 59), UINT8_C( 83), UINT8_C( 55), UINT8_C( 34) },
      { UINT8_C( 14), UINT8_C(  5), UINT8_C(243), UINT8_C(213), UINT8_C(234), UINT8_C( 10), UINT8_C(117), UINT8_C( 69),
        UINT8_C(216),    UINT8_MAX, UINT8_C(183), UINT8_C(100), UINT8_C( 91), UINT8_C(189), UINT8_C(240), UINT8_C( 95),
        UINT8_C(153), UINT8_C(132), UINT8_C(152), UINT8_C(194), UINT8_C( 21), UINT8_C( 77), UINT8_C(230), UINT8_C( 67),
        UINT8_C(166), UINT8_C(  4), UINT8_C(164), UINT8_C(225), UINT8_C( 87), UINT8_C(166), UINT8_C(  3), UINT8_C(165),
        UINT8_C( 44), UINT8_C(250), UINT8_C(122), UINT8_C(120), UINT8_C(135), UINT8_C( 60), UINT8_C(200), UINT8_C(218),
        UINT8_C( 59), UINT8_C(120), UINT8_C( 62), UINT8_C(168), UINT8_C(139), UINT8_C(110), UINT8_C(176), UINT8_C(113),
        UINT8_C(242), UINT8_C( 57), UINT8_C(203), UINT8_C(254), UINT8_C(238), UINT8_C( 25), UINT8_C( 66), UINT8_C( 36),
        UINT8_C( 29), UINT8_C(177), UINT8_C(118), UINT8_C( 43), UINT8_C( 87), UINT8_C(121), UINT8_C( 26), UINT8_C(131) },
      UINT64_C(   19774417572869299) },
    { UINT64_C(12109866112139735298),
      { UINT8_C(229), UINT8_C(193), UINT8_C(193), UINT8_C( 69), UINT8_C(193), UINT8_C(162), UINT8_C(  2), UINT8_C(122),
        UINT8_C( 34), UINT8_C( 10), UINT8_C(  4), UINT8_C(131), UINT8_C(241), UINT8_C(126), UINT8_C(119), UINT8_C( 46),
        UINT8_C( 93), UINT8_C( 85), UINT8_C( 58), UINT8_C(186), UINT8_C(159), UINT8_C(134), UINT8_C( 41), UINT8_C( 82),
        UINT8_C(131), UINT8_C(124), UINT8_C( 49), UINT8_C(125), UINT8_C(189), UINT8_C(120),    UINT8_MAX, UINT8_C(162),
        UINT8_C( 57), UINT8_C(193), UINT8_C(231), UINT8_C(251), UINT8_C( 99), UINT8_C(233), UINT8_C(117), UINT8_C(133),
        UINT8_C(243), UINT8_C(121), UINT8_C(  8), UINT8_C(229), UINT8_C(248), UINT8_C(128), UINT8_C( 19), UINT8_C( 85),
        UINT8_C(213), UINT8_C( 78), UINT8_C( 15), UINT8_C(116), UINT8_C(212), UINT8_C( 56), UINT8_C(199), UINT8_C( 87),
        UINT8_C(180), UINT8_C(248), UINT8_C(212), UINT8_C(114), UINT8_C(112), UINT8_C(212), UINT8_C( 20), UINT8_C(170) },
      { UINT8_C(229), UINT8_C(193), UINT8_C(193), UINT8_C( 69), UINT8_C(229), UINT8_C( 26), UINT8_C(125), UINT8_C(122),
        UINT8_C(147), UINT8_C(133), UINT8_C(  4), UINT8_C(139), UINT8_C(  5), UINT8_C(209), UINT8_C(224), UINT8_C(218),
        UINT8_C( 93), UINT8_C(239), UINT8_C( 58), UINT8_C(243), UINT8_C( 40), UINT8_C( 22), UINT8_C( 74), UINT8_C(220),
        UINT8_C( 14), UINT8_C( 31), UINT8_C( 78), UINT8_C(127), UINT8_C(189), UINT8_C(120), UINT8_C( 41), UINT8_C(162),
        UINT8_C( 57), UINT8_C(206), UINT8_C(231), UINT8_C( 68), UINT8_C(232), UINT8_C(233), UINT8_C( 29), UINT8_C(123),
        UINT8_C(130), UINT8_C(219), UINT8_C(  7), UINT8_C(229), UINT8_C(248), UINT8_C(128), UINT8_C( 98), UINT8_C( 85),
        UINT8_C(215), UINT8_C(177), UINT8_C( 15), UINT8_C(116), UINT8_C(199), UINT8_C( 10), UINT8_C(219), UINT8_C(214),
        UINT8_C(180), UINT8_C( 42), UINT8_C( 85), UINT8_C(114), UINT8_C(141), UINT8_C(126), UINT8_C(164), UINT8_C(236) },
      UINT64_C( 2885858488836231170) },
    { UINT64_C(17089211020051693277),
      { UINT8_C( 81), UINT8_C(127), UINT8_C(220), UINT8_C( 78), UINT8_C(147), UINT8_C(134), UINT8_C(138), UINT8_C( 10),
        UINT8_C(163), UINT8_C(206), UINT8_C(238), UINT8_C( 16), UINT8_C(240), UINT8_C(106), UINT8_C(247), UINT8_C( 68),
        UINT8_C(153), UINT8_C(228), UINT8_C( 72), UINT8_C( 32), UINT8_C(195), UINT8_C( 73), UINT8_C( 35), UINT8_C(198),
        UINT8_C(123), UINT8_C(197), UINT8_C( 57), UINT8_C(140), UINT8_C(168), UINT8_C( 71), UINT8_C( 52), UINT8_C(250),
        UINT8_C(198), UINT8_C( 17), UINT8_C( 72), UINT8_C( 89), UINT8_C(151), UINT8_C(210), UINT8_C( 99), UINT8_C( 58),
        UINT8_C(161), UINT8_C( 82), UINT8_C( 75), UINT8_C(145), UINT8_C(188), UINT8_C( 66), UINT8_C(213), UINT8_C( 85),
        UINT8_C( 38), UINT8_C( 29), UINT8_C(117), UINT8_C(233), UINT8_C(103), UINT8_C(152), UINT8_C(175), UINT8_C(226),
        UINT8_C( 93), UINT8_C(233), UINT8_C(110), UINT8_C(  6), UINT8_C( 48), UINT8_C(163), UINT8_C(  0), UINT8_C(247) },
      { UINT8_C(180), UINT8_C( 72), UINT8_C( 80), UINT8_C( 75), UINT8_C( 26), UINT8_C(134), UINT8_C(133), UINT8_C(187),
        UINT8_C(  6), UINT8_C(206), UINT8_C(238), UINT8_C(194), UINT8_C( 18), UINT8_C( 33), UINT8_C( 23), UINT8_C( 56),
        UINT8_C( 63), UINT8_C(140), UINT8_C( 34), UINT8_C(166), UINT8_C(195), UINT8_C(209), UINT8_C(136), UINT8_C(130),
        UINT8_C(186), UINT8_C(197), UINT8_C( 57), UINT8_C(235), UINT8_C(153), UINT8_C(136), UINT8_C(226), UINT8_C(250),
        UINT8_C(208), UINT8_C( 17), UINT8_C(152), UINT8_C(234), UINT8_C(151), UINT8_C( 30), UINT8_C(166), UINT8_C(236),
        UINT8_C(161), UINT8_C(242), UINT8_C(174), UINT8_C(  1), UINT8_C( 20), UINT8_C( 66), UINT8_C( 57), UINT8_C( 83),
        UINT8_C( 81), UINT8_C( 91), UINT8_C(249), UINT8_C(118), UINT8_C(103), UINT8_C(129), UINT8_C(248), UINT8_C(231),
        UINT8_C(119), UINT8_C(128), UINT8_C(210), UINT8_C(  6), UINT8_C(  8), UINT8_C(180), UINT8_C(  0), UINT8_C(247) },
      UINT64_C(14422795536624465500) },
    { UINT64_C(17826334788593600725),
      { UINT8_C( 73), UINT8_C(107), UINT8_C( 39), UINT8_C(190), UINT8_C(112), UINT8_C(225), UINT8_C(204), UINT8_C( 47),
        UINT8_C(144), UINT8_C(161), UINT8_C( 43), UINT8_C( 44), UINT8_C( 36), UINT8_C(218), UINT8_C( 54), UINT8_C( 40),
        UINT8_C( 77), UINT8_C(182), UINT8_C( 96), UINT8_C(228), UINT8_C(131), UINT8_C(181), UINT8_C(148), UINT8_C( 96),
        UINT8_C(243), UINT8_C(116), UINT8_C(181), UINT8_C(212), UINT8_C(134), UINT8_C(222), UINT8_C(194), UINT8_C(207),
        UINT8_C( 74), UINT8_C(233), UINT8_C(141), UINT8_C(186), UINT8_C(202), UINT8_C( 89), UINT8_C(233), UINT8_C( 90),
        UINT8_C(251), UINT8_C( 20), UINT8_C(135), UINT8_C( 31), UINT8_C(238), UINT8_C(189), UINT8_C( 71), UINT8_C( 60),
        UINT8_C(115), UINT8_C(168), UINT8_C( 32), UINT8_C(246), UINT8_C( 93), UINT8_C(180), UINT8_C( 86), UINT8_C( 80),
        UINT8_C( 40), UINT8_C( 12), UINT8_C( 36), UINT8_C(174), UINT8_C(234), UINT8_C(230), UINT8_C(125), UINT8_C( 52) },
      { UINT8_C( 73), UINT8_C( 10), UINT8_C( 39), UINT8_C(190), UINT8_C(100), UINT8_C(216), UINT8_C(204), UINT8_C( 95),
        UINT8_C(236), UINT8_C(124), UINT8_C( 43), UINT8_C(219), UINT8_C( 57), UINT8_C(218), UINT8_C( 23), UINT8_C(173),
        UINT8_C(110), UINT8_C( 55), UINT8_C(163), UINT8_C(203), UINT8_C(131), UINT8_C(250), UINT8_C(148), UINT8_C( 20),
        UINT8_C(  6), UINT8_C(116), UINT8_C(194), UINT8_C(240), UINT8_C( 38), UINT8_C( 64), UINT8_C( 37), UINT8_C(246),
        UINT8_C( 74), UINT8_C( 19), UINT8_C(144), UINT8_C(186), UINT8_C(202), UINT8_C(133), UINT8_C( 13), UINT8_C(216),
        UINT8_C(  1), UINT8_C(140), UINT8_C(179), UINT8_C( 59), UINT8_C( 82), UINT8_C(189), UINT8_C( 71), UINT8_C(192),
        UINT8_C(  1), UINT8_C(139), UINT8_C(139), UINT8_C(236), UINT8_C(133), UINT8_C(166), UINT8_C(  0), UINT8_C(139),
        UINT8_C(229), UINT8_C(195), UINT8_C( 36), UINT8_C(174), UINT8_C(  3), UINT8_C(161), UINT8_C(  1), UINT8_C( 77) },
      UINT64_C( 8386636035849338965) },
    { UINT64_C( 3453141464312438216),
      { UINT8_C(190), UINT8_C(220), UINT8_C(217), UINT8_C(220), UINT8_C(252), UINT8_C(177), UINT8_C(193), UINT8_C( 79),
        UINT8_C(108), UINT8_C(243), UINT8_C(123), UINT8_C(  9), UINT8_C(253), UINT8_C(100), UINT8_C( 77), UINT8_C( 92),
        UINT8_C( 23), UINT8_C( 57), UINT8_C(177), UINT8_C(149), UINT8_C( 28), UINT8_C(175), UINT8_C(112), UINT8_C(242),
        UINT8_C(248), UINT8_C(192), UINT8_C(195), UINT8_C(  2), UINT8_C(157), UINT8_C( 38), UINT8_C(250), UINT8_C( 91),
        UINT8_C(  2), UINT8_C(211), UINT8_C( 55),    UINT8_MAX, UINT8_C(133), UINT8_C(248), UINT8_C( 78), UINT8_C(241),
        UINT8_C(235), UINT8_C(201), UINT8_C(250), UINT8_C(233), UINT8_C( 46), UINT8_C( 71), UINT8_C( 69), UINT8_C( 69),
        UINT8_C(129), UINT8_C(246), UINT8_C(219), UINT8_C(157), UINT8_C(166), UINT8_C( 75), UINT8_C(143), UINT8_C(158),
        UINT8_C( 11), UINT8_C( 83), UINT8_C(160), UINT8_C(168), UINT8_C(121), UINT8_C(154), UINT8_C(  4), UINT8_C(124) },
      { UINT8_C(190), UINT8_C(220), UINT8_C(123), UINT8_C(243), UINT8_C( 52), UINT8_C(201), UINT8_C(228), UINT8_C( 79),
        UINT8_C(147), UINT8_C(222), UINT8_C(  8), UINT8_C(  9), UINT8_C( 38), UINT8_C( 78), UINT8_C(  6), UINT8_C(167),
        UINT8_C( 68), UINT8_C(225), UINT8_C(177), UINT8_C(234), UINT8_C( 45), UINT8_C(212), UINT8_C(136), UINT8_C( 56),
        UINT8_C( 39), UINT8_C( 41), UINT8_C(195), UINT8_C(160), UINT8_C(195), UINT8_C( 38), UINT8_C(250), UINT8_C( 49),
        UINT8_C( 32), UINT8_C(151), UINT8_C( 36), UINT8_C( 84), UINT8_C( 97), UINT8_C(248), UINT8_C(116), UINT8_C(244),
        UINT8_C(231), UINT8_C(124), UINT8_C(181), UINT8_C( 13), UINT8_C( 46), UINT8_C(187), UINT8_C(180), UINT8_C( 15),
        UINT8_C(157), UINT8_C(248), UINT8_C(249), UINT8_C(202), UINT8_C(204), UINT8_C(130), UINT8_C(  2), UINT8_C(158),
        UINT8_C(171), UINT8_C(227), UINT8_C(148), UINT8_C(168), UINT8_C(121), UINT8_C(176), UINT8_C(160), UINT8_C(233) },
      UINT64_C(  918739945080773760) },
    { UINT64_C(11163256801159494718),
      { UINT8_C( 72), UINT8_C( 14), UINT8_C(143), UINT8_C(  0), UINT8_C( 55), UINT8_C(153), UINT8_C( 37), UINT8_C( 97),
        UINT8_C( 23), UINT8_C(133), UINT8_C( 14), UINT8_C( 13), UINT8_C( 18), UINT8_C(233), UINT8_C( 93), UINT8_C( 96),
        UINT8_C( 96), UINT8_C(208), UINT8_C( 33), UINT8_C( 20), UINT8_C( 79), UINT8_C(155), UINT8_C(201), UINT8_C( 23),
        UINT8_C(121), UINT8_C( 76), UINT8_C(219), UINT8_C( 86), UINT8_C( 81), UINT8_C(199), UINT8_C(134), UINT8_C(153),
        UINT8_C(213), UINT8_C( 21), UINT8_C(153), UINT8_C( 12), UINT8_C(174), UINT8_C(191), UINT8_C(109), UINT8_C(197),
        UINT8_C( 68), UINT8_C(123), UINT8_C(210), UINT8_C( 86), UINT8_C(100), UINT8_C( 47), UINT8_C(182), UINT8_C(197),
           UINT8_MAX, UINT8_C(215), UINT8_C(217), UINT8_C( 78), UINT8_C(115), UINT8_C(163), UINT8_C(102), UINT8_C(236),
        UINT8_C(239), UINT8_C( 65), UINT8_C( 66), UINT8_C( 65), UINT8_C(  8), UINT8_C(200), UINT8_C(218), UINT8_C(222) },
      { UINT8_C( 72), UINT8_C( 14), UINT8_C(234), UINT8_C(139), UINT8_C( 51), UINT8_C( 88), UINT8_C( 81), UINT8_C(119),
        UINT8_C(211), UINT8_C( 35), UINT8_C(205), UINT8_C( 56), UINT8_C( 83), UINT8_C(131), UINT8_C( 93), UINT8_C( 82),
        UINT8_C( 96), UINT8_C(208), UINT8_C(161), UINT8_C( 20), UINT8_C(121), UINT8_C(  7), UINT8_C(201), UINT8_C( 23),
        UINT8_C(121), UINT8_C( 76), UINT8_C(219), UINT8_C( 80), UINT8_C(197), UINT8_C(132), UINT8_C( 46), UINT8_C(162),
        UINT8_C(248), UINT8_C( 25), UINT8_C(153), UINT8_C( 43), UINT8_C(113), UINT8_C(127), UINT8_C(162), UINT8_C( 68),
        UINT8_C( 68), UINT8_C(111), UINT8_C(210), UINT8_C(245), UINT8_C(100), UINT8_C( 47), UINT8_C( 72), UINT8_C(197),
           UINT8_MAX, UINT8_C(215), UINT8_C(217), UINT8_C(201), UINT8_C(240), UINT8_C(163), UINT8_C( 50), UINT8_C( 56),
        UINT8_C(210), UINT8_C(220), UINT8_C( 66), UINT8_C( 65), UINT8_C(  8), UINT8_C(183), UINT8_C(218), UINT8_C( 89) },
      UINT64_C(11016880699348295730) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__mmask64 k = test_vec[i].k;
    simde__m512i a = simde_mm512_loadu_epi8(test_vec[i].a);
    simde__m512i b = simde_mm512_loadu_epi8(test_vec[i].b);
    simde__mmask64 r = simde_mm512_mask_cmpge_epu8_mask(k, a, b);
    simde_assert_equal_mmask64(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    uint8_t a_[64];
    uint8_t b_[64];

    simde_test_codegen_random_memory(sizeof(a_), HEDLEY_REINTERPRET_CAST(uint8_t*, a_));
    simde_test_codegen_random_memory(sizeof(b_), HEDLEY_REINTERPRET_CAST(uint8_t*, b_));
    for (size_t j = 0 ; j < (sizeof(a_) / sizeof(a_[0])) ; j++)
      if ((simde_test_codegen_rand() & 3) == 0)
        b_[j] = a_[j];

    simde__mmask64 k = simde_test_x86_random_mmask64();
    simde__m512i a = simde_mm512_loadu_epi8(a_);
    simde__m512i b = simde_mm512_loadu_epi8(b_);
    simde__mmask64 r = simde_mm512_mask_cmpge_epu8_mask(k, a, b);

    simde_test_x86_write_mmask64(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_u8x64(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_u8x64(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask64(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_x_mm_cmpge_epi16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int16_t a[8];
    const int16_t b[8];
    const int16_t r[8];
  } test_vec[] = {
    { { -INT16_C( 20967),  INT16_C( 23470),  INT16_C(  5545),  INT16_C( 17346), -INT16_C( 27606),  INT16_C( 32215),  INT16_C( 13416),  INT16_C( 23476) },
      { -INT16_C( 22511),  INT16_C( 23470),  INT16_C( 23741),  INT16_C( 17346), -INT16_C( 27606),  INT16_C( 22885),  INT16_C( 13416),  INT16_C( 25268) },
      { -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0) } },
    { {  INT16_C(  4325), -INT16_C(  5585),  INT16_C( 29400), -INT16_C( 27360), -INT16_C(  4070),  INT16_C(  9592), -INT16_C( 25925),  INT16_C( 11841) },
      {  INT16_C( 31842),  INT16_C( 15042),  INT16_C( 29400),  INT16_C(  2512),  INT16_C( 18642),  INT16_C(  9592),  INT16_C( 28899),  INT16_C( 14779) },
      {  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0) } },
    { {  INT16_C(  4513),  INT16_C( 12907),  INT16_C( 28210),  INT16_C( 12216), -INT16_C( 13389),  INT16_C( 18974), -INT16_C(  6614),  INT16_C(  1603) },
      {  INT16_C(  4513), -INT16_C( 23490), -INT16_C(  2328), -INT16_C( 25645), -INT16_C(  3391), -INT16_C(  4891), -INT16_C(  6614),  INT16_C( 18418) },
      { -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0) } },
    { {  INT16_C( 23086), -INT16_C( 27657), -INT16_C(  9323), -INT16_C( 19043), -INT16_C( 17225), -INT16_C(  3263), -INT16_C(  9749), -INT16_C( 27743) },
      {  INT16_C( 29107),  INT16_C( 18612), -INT16_C(  9323),  INT16_C(  1022), -INT16_C( 17225), -INT16_C(  1802), -INT16_C( 26856), -INT16_C( 14452) },
      {  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0) } },
    { { -INT16_C( 21458),  INT16_C( 12538), -INT16_C( 12037), -INT16_C( 12140), -INT16_C( 26680),  INT16_C(  6294),  INT16_C( 32019),  INT16_C(    28) },
      { -INT16_C( 14863), -INT16_C(  4916),  INT16_C( 24982), -INT16_C( 12140),  INT16_C( 21496),  INT16_C(  2934), -INT16_C( 27952), -INT16_C(  5877) },
      {  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1) } },
    { { -INT16_C( 25498),  INT16_C(  8462), -INT16_C(  2425),  INT16_C( 25478),  INT16_C( 24761), -INT16_C( 15956), -INT16_C( 28155),  INT16_C( 28602) },
      {  INT16_C( 31559), -INT16_C( 12765), -INT16_C( 22159),  INT16_C( 25478), -INT16_C(  8695),  INT16_C(  3820), -INT16_C( 22672), -INT16_C( 19075) },
      {  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1) } },
    { { -INT16_C( 16168), -INT16_C( 27565),  INT16_C(  4914),  INT16_C(  8180),  INT16_C( 24271),  INT16_C( 14247),  INT16_C( 12854), -INT16_C( 30235) },
      { -INT16_C( 18163),  INT16_C( 16475),  INT16_C( 20428), -INT16_C( 25761),  INT16_C(  1709), -INT16_C(  7214), -INT16_C( 18376),  INT16_C(  6252) },
      { -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0) } },
    { {  INT16_C(   764), -INT16_C(  3325), -INT16_C( 13083), -INT16_C( 13309), -INT16_C( 20689), -INT16_C(  8032),  INT16_C( 15297), -INT16_C( 29538) },
      { -INT16_C(  3410), -INT16_C( 27535),  INT16_C( 30142), -INT16_C(  4512),  INT16_C(    36), -INT16_C(  6450),  INT16_C( 27708),  INT16_C( 28018) },
      { -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_x_mm_loadu_epi16(test_vec[i].a);
    simde__m128i b = simde_x_mm_loadu_epi16(test_vec[i].b);
    simde__m128i r = simde_x_mm_cmpge_epi16(a, b);
    simde_test_x86_assert_equal_i16x8(r, simde_x_mm_loadu_epi16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    int16_t a_[8];
    int16_t b_[8];

    simde_test_codegen_random_memory(sizeof(a_), HEDLEY_REINTERPRET_CAST(uint8_t*, a_));
    simde_test_codegen_random_memory(sizeof(b_), HEDLEY_REINTERPRET_CAST(uint8_t*, b_));
    for (size_t j = 0 ; j < (sizeof(a_) / sizeof(a_[0])) ; j++)
      if ((simde_test_codegen_rand() & 3) == 0)
        b_[j] = a_[j];

    simde__m128i a = simde_mm_loadu_epi16(a_);
    simde__m128i b = simde_mm_loadu_epi16(b_);
    simde__m128i r = simde_x_mm_cmpge_epi16(a, b);

    simde_test_x86_write_i16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_cmpge_epi16_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int16_t a[8];
    const int16_t b[8];
    const simde__mmask8 r;
  } test_vec[] = {
    { {  INT16_C( 16006),  INT16_C( 16101),  INT16_C(  6957), -INT16_C( 10991), -INT16_C(  6387),  INT16_C(  1082), -INT16_C( 12320),  INT16_C(  3312) },
      { -INT16_C( 13630), -INT16_C(  4309),  INT16_C( 15590), -INT16_C( 10991), -INT16_C(   221),  INT16_C(  1271), -INT16_C(  6194),  INT16_C( 28944) },
      UINT8_C( 11) },
    { {  INT16_C(   814), -INT16_C( 22504),  INT16_C(  9826), -INT16_C( 13880),  INT16_C(  6128),  INT16_C( 15766),  INT16_C( 20810),  INT16_C( 18508) },
      {  INT16_C( 21861), -INT16_C( 14563), -INT16_C(  6532),  INT16_C( 27792),  INT16_C(  6128),  INT16_C( 18345), -INT16_C(  2696), -INT16_C( 20336) },
      UINT8_C(212) },
    { { -INT16_C(  2071), -INT16_C( 22081), -INT16_C(  9052),  INT16_C( 15675),  INT16_C( 21848),  INT16_C( 14109),  INT16_C( 29357),  INT16_C( 23162) },
      { -INT16_C(  2071), -INT16_C( 23057),  INT16_C( 11159), -INT16_C(  4126), -INT16_C(   128),  INT16_C( 11558), -INT16_C( 24207),  INT16_C( 21895) },
      UINT8_C(251) },
    { {  INT16_C( 13137),  INT16_C( 29812), -INT16_C( 24744), -INT16_C( 21012), -INT16_C(  4376),  INT16_C( 15454),  INT16_C( 21995), -INT16_C( 23664) },
      {  INT16_C( 15456), -INT16_C( 18261), -INT16_C( 24744), -INT16_C( 15515), -INT16_C( 15483),  INT16_C( 28927), -INT16_C( 28648),  INT16_C( 21523) },
      UINT8_C( 86) },
    { { -INT16_C( 14708), -INT16_C( 15822), -INT16_C(  3514),  INT16_C( 25998), -INT16_C(  2755), -INT16_C( 19351), -INT16_C( 23516), -INT16_C( 28788) },
      {  INT16_C( 26248), -INT16_C( 12716), -INT16_C(  7592), -INT16_C( 27341), -INT16_C( 25385), -INT16_C(  1207), -INT16_C( 23516), -INT16_C( 13686) },
      UINT8_C( 92) },
    { {  INT16_C( 12002),  INT16_C(  7999),  INT16_C(  3339),  INT16_C( 25924), -INT16_C(  5514), -INT16_C( 24123), -INT16_C( 18749),  INT16_C(   596) },
      {  INT16_C(   505),  INT16_C(  1181),  INT16_C(  3339), -INT16_C( 31382), -INT16_C(  5514), -INT16_C( 28890),  INT16_C( 31717),  INT16_C(   596) },
      UINT8_C(191) },
    { {  INT16_C( 20714), -INT16_C(  9772), -INT16_C( 29326), -INT16_C( 21245), -INT16_C( 19788), -INT16_C( 22908), -INT16_C(  9949), -INT16_C( 27247) },
      { -INT16_C( 17040), -INT16_C(  9772), -INT16_C(  2230), -INT16_C(   369), -INT16_C( 19788), -INT16_C( 13148),  INT16_C( 14060), -INT16_C( 18334) },
      UINT8_C( 19) },
    { { -INT16_C(  8816),  INT16_C(  9699), -INT16_C(  9611),  INT16_C( 32259), -INT16_C( 11612), -INT16_C( 28745),  INT16_C(  2953), -INT16_C(   278) },
      { -INT16_C( 22012),  INT16_C(  9699),  INT16_C(  1156),  INT16_C( 10743), -INT16_C( 11612),  INT16_C( 24760),  INT16_C(  2953),  INT16_C(  3422) },
      UINT8_C( 91) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_x_mm_loadu_epi16(test_vec[i].a);
    simde__m128i b = simde_x_mm_loadu_epi16(test_vec[i].b);
    simde__mmask8 r = simde_mm_cmpge_epi16_mask(a, b);
    simde_assert_equal_mmask8(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    int16_t a_[8];
    int16_t b_[8];

    simde_test_codegen_random_memory(sizeof(a_), HEDLEY_REINTERPRET_CAST(uint8_t*, a_));
    simde_test_codegen_random_memory(sizeof(b_), HEDLEY_REINTERPRET_CAST(uint8_t*, b_));
    for (size_t j = 0 ; j < (sizeof(a_) / sizeof(a_[0])) ; j++)
      if ((simde_test_codegen_rand() & 3) == 0)
        b_[j] = a_[j];

    simde__m128i a = simde_mm_loadu_epi16(a_);
    simde__m128i b = simde_mm_loadu_epi16(b_);
    simde__mmask8 r = simde_mm_cmpge_epi16_mask(a, b);

    simde_test_x86_write_i16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_mask_cmpge_epi16_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k;
    const int16_t a[8];
    const int16_t b[8];
    const simde__mmask8 r;
  } test_vec[] = {
    { UINT8_C(137),
      { -INT16_C( 30888),  INT16_C( 20842), -INT16_C( 20459), -INT16_C(  8172), -INT16_C(  1134), -INT16_C(  1813),  INT16_C( 25636),  INT16_C( 11126) },
      { -INT16_C( 30888),  INT16_C( 28836), -INT16_C( 18091), -INT16_C(  6320),  INT16_C( 15540), -INT16_C( 10017),  INT16_C( 25636),  INT16_C( 14851) },
      UINT8_C(  1) },
    { UINT8_C(196),
      {  INT16_C( 19144),  INT16_C( 29912), -INT16_C( 30822),  INT16_C( 21688), -INT16_C(  2387),  INT16_C(  3554), -INT16_C( 13433), -INT16_C( 17391) },
      { -INT16_C( 22288),  INT16_C( 29912), -INT16_C(  3281), -INT16_C(  8994), -INT16_C( 16151),  INT16_C(  3554), -INT16_C(  1396), -INT16_C( 17391) },
      UINT8_C(128) },
    { UINT8_C(  7),
      {  INT16_C(  3995), -INT16_C( 11287), -INT16_C( 10516),  INT16_C(  2376), -INT16_C( 17655),  INT16_C(  3276),  INT16_C( 32757),  INT16_C( 27062) },
      {  INT16_C( 32139), -INT16_C( 11287), -INT16_C(  4269),  INT16_C( 23936), -INT16_C( 17655),  INT16_C(  3276),  INT16_C(  8140), -INT16_C( 30455) },
      UINT8_C(  2) },
    { UINT8_C( 63),
      { -INT16_C( 25767),  INT16_C( 28931), -INT16_C(  7820), -INT16_C( 13657),  INT16_C(  5518), -INT16_C( 12645), -INT16_C(  1961),  INT16_C( 16268) },
      { -INT16_C(  3047),  INT16_C( 28931), -INT16_C( 26667),  INT16_C( 25431), -INT16_C(  3155),  INT16_C(  1073), -INT16_C( 16917),  INT16_C( 16268) },
      UINT8_C( 22) },
    { UINT8_C( 70),
      {  INT16_C( 26887), -INT16_C( 25036), -INT16_C(  6224), -INT16_C( 12190),  INT16_C( 19588),  INT16_C(  4719),  INT16_C( 10164),  INT16_C(  3220) },
      { -INT16_C( 28506), -INT16_C( 25036),  INT16_C( 20087), -INT16_C(   985), -INT16_C( 26982),  INT16_C( 19982), -INT16_C( 23619),  INT16_C(  3220) },
      UINT8_C( 66) },
    { UINT8_C( 66),
      {  INT16_C(  5395), -INT16_C(  8141),  INT16_C( 23002), -INT16_C(  9791), -INT16_C(  5732),  INT16_C( 14870), -INT16_C(  1698), -INT16_C( 16792) },
      { -INT16_C( 18775), -INT16_C(  8141), -INT16_C( 10737), -INT16_C( 21667),  INT16_C( 29631),  INT16_C( 14870),  INT16_C( 19820), -INT16_C( 24613) },
      UINT8_C(  2) },
    { UINT8_C(197),
      {  INT16_C(  4841), -INT16_C( 22208), -INT16_C( 30085), -INT16_C( 26965), -INT16_C( 12527),  INT16_C(  6724), -INT16_C( 25561), -INT16_C( 27687) },
      {  INT16_C(  4841), -INT16_C( 22208),  INT16_C( 26109),  INT16_C(  3673), -INT16_C( 25292),  INT16_C( 23336), -INT16_C( 25561), -INT16_C( 20241) },
      UINT8_C( 65) },
    { UINT8_C( 90),
      { -INT16_C( 11782), -INT16_C( 19358), -INT16_C(  3043), -INT16_C( 26914),  INT16_C( 12407),  INT16_C( 11334),  INT16_C( 15762), -INT16_C( 20908) },
      {  INT16_C(  8000),  INT16_C( 24048), -INT16_C(  3043), -INT16_C( 29964),  INT16_C( 12407),  INT16_C( 11334),  INT16_C( 15762),  INT16_C( 28479) },
      UINT8_C( 88) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__mmask8 k = test_vec[i].k;
    simde__m128i a = simde_x_mm_loadu_epi16(test_vec[i].a);
    simde__m128i b = simde_x_mm_loadu_epi16(test_vec[i].b);
    simde__mmask8 r = simde_mm_mask_cmpge_epi16_mask(k, a, b);
    simde_assert_equal_mmask8(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    int16_t a_[8];
    int16_t b_[8];

    simde_test_codegen_random_memory(sizeof(a_), HEDLEY_REINTERPRET_CAST(uint8_t*, a_));
    simde_test_codegen_random_memory(sizeof(b_), HEDLEY_REINTERPRET_CAST(uint8_t*, b_));
    for (size_t j = 0 ; j < (sizeof(a_) / sizeof(a_[0])) ; j++)
      if ((simde_test_codegen_rand() & 3) == 0)
        b_[j] = a_[j];

    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m128i a = simde_mm_loadu_epi16(a_);
    simde__m128i b = simde_mm_loadu_epi16(b_);
    simde__mmask8 r = simde_mm_mask_cmpge_epi16_mask(k, a, b);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i16x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_x_mm256_cmpge_epi16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int16_t a[16];
    const int16_t b[16];
    const int16_t r[16];
  } test_vec[] = {
    { {  INT16_C( 25425), -INT16_C(  3630),  INT16_C( 26785), -INT16_C( 26484), -INT16_C( 12490),  INT16_C(  5360), -INT16_C( 14520), -INT16_C( 29904),
         INT16_C( 22110), -INT16_C( 30143), -INT16_C( 15019), -INT16_C( 14307),  INT16_C( 19439), -INT16_C( 24885),  INT16_C( 21283),  INT16_C( 29762) },
      {  INT16_C( 25425),  INT16_C( 22373), -INT16_C(  3460), -INT16_C( 26484), -INT16_C(  7999),  INT16_C(  2503), -INT16_C(  2137),  INT16_C(  1428),
        -INT16_C( 10675), -INT16_C( 23665), -INT16_C( 15019), -INT16_C( 29845),  INT16_C( 14071),  INT16_C(  6697),  INT16_C( 27529),  INT16_C( 16270) },
      { -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
        -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1) } },
    { { -INT16_C( 24293), -INT16_C( 18850), -INT16_C( 14003),  INT16_C( 17473),  INT16_C( 27136), -INT16_C( 30370), -INT16_C(  4906),  INT16_C( 22217),
         INT16_C( 24543), -INT16_C( 15022),  INT16_C(   741),  INT16_C( 19308),  INT16_C(  7288), -INT16_C(  6568),  INT16_C( 27233),  INT16_C( 31906) },
      {  INT16_C(    11), -INT16_C( 18850), -INT16_C( 14003), -INT16_C( 13668), -INT16_C(  1313), -INT16_C( 30370),  INT16_C(  7398),  INT16_C( 22217),
         INT16_C( 23932), -INT16_C( 15022), -INT16_C(  2209), -INT16_C( 10067),  INT16_C(  1299), -INT16_C(  6568),  INT16_C( 24688),  INT16_C( 31729) },
      {  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
        -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1) } },
    { { -INT16_C( 23915), -INT16_C(  2750), -INT16_C(  4199), -INT16_C( 21043), -INT16_C( 29707),  INT16_C( 25890),  INT16_C(  5100),  INT16_C( 19936),
        -INT16_C( 19400), -INT16_C( 11912),  INT16_C( 27941), -INT16_C( 28599),  INT16_C( 30389),  INT16_C(  6881), -INT16_C(  1618),  INT16_C( 17403) },
      { -INT16_C( 23915),  INT16_C( 13624), -INT16_C(  4199),  INT16_C(  8930),  INT16_C(  1169),  INT16_C( 32135),  INT16_C(  5100),  INT16_C( 19936),
         INT16_C( 16924), -INT16_C( 11912),  INT16_C( 27055),  INT16_C( 25809),  INT16_C( 30389), -INT16_C( 29313),  INT16_C( 31404),  INT16_C( 17403) },
      { -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),
         INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1) } },
    { { -INT16_C(  5591), -INT16_C( 10154),  INT16_C( 10067),  INT16_C( 13116), -INT16_C( 17446), -INT16_C( 31040), -INT16_C( 28362), -INT16_C(  4402),
         INT16_C( 19099), -INT16_C( 21804), -INT16_C(  8791),  INT16_C(  2890),  INT16_C( 26477),  INT16_C( 25989),  INT16_C( 20302),  INT16_C( 30585) },
      { -INT16_C(  5591), -INT16_C( 29617), -INT16_C( 29705), -INT16_C( 11841), -INT16_C( 32697),  INT16_C( 32088), -INT16_C( 28362), -INT16_C( 21397),
         INT16_C( 16496), -INT16_C( 21804), -INT16_C( 24547),  INT16_C(  2890), -INT16_C( 22009),  INT16_C( 21999),  INT16_C( 20302),  INT16_C( 13004) },
      { -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),
        -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1) } },
    { {  INT16_C(  4886),  INT16_C( 13064),  INT16_C( 11699), -INT16_C( 17475), -INT16_C( 21288), -INT16_C( 12016), -INT16_C(  8939),  INT16_C( 19716),
        -INT16_C( 15368), -INT16_C( 24708),  INT16_C( 31809),  INT16_C( 16525), -INT16_C(  1835),  INT16_C( 21328),  INT16_C(  3279), -INT16_C(  6846) },
      {  INT16_C( 19231), -INT16_C( 11495), -INT16_C( 10632), -INT16_C( 17475), -INT16_C( 24957), -INT16_C( 26590), -INT16_C(  8939),  INT16_C( 19716),
         INT16_C( 25065),  INT16_C( 10771),  INT16_C( 31809), -INT16_C( 19862), -INT16_C(  1835),  INT16_C( 26630),  INT16_C( 18631), -INT16_C(  6578) },
      {  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),
         INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
    { { -INT16_C(  5730),  INT16_C( 31928),  INT16_C(  8842),  INT16_C(  9006),  INT16_C( 13533), -INT16_C( 23412), -INT16_C(  9603),  INT16_C(  4234),
         INT16_C( 17473),  INT16_C( 32284),  INT16_C( 31115),  INT16_C( 28991), -INT16_C( 26633), -INT16_C( 25389), -INT16_C( 22315),  INT16_C( 29481) },
      { -INT16_C(  5730),  INT16_C(  7151),  INT16_C(  7684),  INT16_C(  9006), -INT16_C( 13486), -INT16_C( 23412),  INT16_C(  4005), -INT16_C(  6432),
        -INT16_C(   941), -INT16_C(  8348), -INT16_C( 23691),  INT16_C( 28991),  INT16_C(  9019),  INT16_C(  4105),  INT16_C( 13004),  INT16_C( 23939) },
      { -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
        -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1) } },
    { {  INT16_C( 29327),  INT16_C(  1472),  INT16_C(  4118),  INT16_C( 20850),  INT16_C( 31540),  INT16_C(    97), -INT16_C(  6995), -INT16_C( 16035),
        -INT16_C( 10665), -INT16_C(  5927), -INT16_C( 11634),  INT16_C(  4556),  INT16_C( 32592), -INT16_C(  8647),  INT16_C( 18194), -INT16_C( 24129) },
      {  INT16_C( 32698), -INT16_C( 12122),  INT16_C(  6287), -INT16_C( 15583),  INT16_C( 31540),  INT16_C( 16835),  INT16_C(  8550), -INT16_C( 16894),
        -INT16_C(  8969), -INT16_C( 31066), -INT16_C( 11634),  INT16_C(  4556), -INT16_C( 11791),  INT16_C(   989), -INT16_C( 25576), -INT16_C( 11611) },
      {  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
         INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0) } },
    { {  INT16_C(  4119), -INT16_C( 14896),  INT16_C( 26499),  INT16_C( 29892), -INT16_C( 24264),  INT16_C( 20856),  INT16_C(  7485),  INT16_C( 22563),
        -INT16_C( 14744), -INT16_C( 13309),  INT16_C( 29065), -INT16_C( 12348), -INT16_C(   862), -INT16_C(  2693), -INT16_C(  6857),  INT16_C( 20031) },
      {  INT16_C(  4085),  INT16_C( 30740),  INT16_C( 26499),  INT16_C( 29892),  INT16_C( 25978), -INT16_C( 18688),  INT16_C(  9090),  INT16_C( 22563),
         INT16_C(  5097),  INT16_C( 29623),  INT16_C( 31620), -INT16_C( 12348), -INT16_C( 17033), -INT16_C( 20709),  INT16_C( 23202),  INT16_C( 20031) },
      { -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
         INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256i a = simde_mm256_loadu_epi16(test_vec[i].a);
    simde__m256i b = simde_mm256_loadu_epi16(test_vec[i].b);
    simde__m256i r = simde_x_mm256_cmpge_epi16(a, b);
    simde_test_x86_assert_equal_i16x16(r, simde_mm256_loadu_epi16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    int16_t a_[16];
    int16_t b_[16];

    simde_test_codegen_random_memory(sizeof(a_), HEDLEY_REINTERPRET_CAST(uint8_t*, a_));
    simde_test_codegen_random_memory(sizeof(b_), HEDLEY_REINTERPRET_CAST(uint8_t*, b_));
    for (size_t j = 0 ; j < (sizeof(a_) / sizeof(a_[0])) ; j++)
      if ((simde_test_codegen_rand() & 3) == 0)
        b_[j] = a_[j];

    simde__m256i a = simde_mm256_loadu_epi16(a_);
    simde__m256i b = simde_mm256_loadu_epi16(b_);
    simde__m256i r = simde_x_mm256_cmpge_epi16(a, b);

    simde_test_x86_write_i16x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i16x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_cmpge_epi16_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int16_t a[16];
    const int16_t b[16];
    const simde__mmask16 r;
  } test_vec[] = {
    { { -INT16_C(  2755),  INT16_C( 10522),  INT16_C( 12193), -INT16_C( 24448),  INT16_C(  9573),  INT16_C( 28763), -INT16_C( 25115), -INT16_C( 26892),
        -INT16_C( 29557), -INT16_C( 20772), -INT16_C( 25345),  INT16_C(  7245), -INT16_C( 19801),  INT16_C( 13332), -INT16_C(  3995), -INT16_C( 23993) },
      {  INT16_C( 25062), -INT16_C( 30772),  INT16_C( 12193), -INT16_C(  2521), -INT16_C( 31887),  INT16_C( 28763), -INT16_C( 25115), -INT16_C( 21268),
        -INT16_C( 13850), -INT16_C(  6566), -INT16_C( 22683),  INT16_C(  3074),  INT16_C(  5721), -INT16_C( 16832), -INT16_C( 30713), -INT16_C(  4767) },
      UINT16_C(26742) },
    { {  INT16_C( 17910),  INT16_C( 23549),  INT16_C(   236),  INT16_C( 17767), -INT16_C( 22506),  INT16_C(  7428),  INT16_C( 25904),  INT16_C(  6410),
         INT16_C( 32658),  INT16_C(  2963),  INT16_C(   795),  INT16_C( 15093),  INT16_C( 14042),  INT16_C(  2937),  INT16_C( 25956),  INT16_C( 23074) },
      {  INT16_C(  8362), -INT16_C( 26698),  INT16_C(  7456),  INT16_C( 14044), -INT16_C( 22506), -INT16_C(  2732),  INT16_C( 25904), -INT16_C( 10481),
        -INT16_C( 23843),  INT16_C(  2963), -INT16_C( 10074), -INT16_C( 32718), -INT16_C( 21490),  INT16_C( 29323),  INT16_C( 25956),  INT16_C( 23074) },
      UINT16_C(57339) },
    { {  INT16_C(  3853), -INT16_C( 19540), -INT16_C(  8217), -INT16_C(  2765), -INT16_C( 16757), -INT16_C( 25496),  INT16_C( 13675),  INT16_C( 14679),
        -INT16_C( 21832),  INT16_C( 22566),  INT16_C( 19161), -INT16_C(  5954),  INT16_C(  6850), -INT16_C( 26307),  INT16_C( 27268), -INT16_C( 28339) },
      { -INT16_C(  1671),  INT16_C( 24644),  INT16_C( 30680),  INT16_C( 25429), -INT16_C( 17099), -INT16_C( 25496),  INT16_C( 22514), -INT16_C( 21798),
         INT16_C(     1),  INT16_C( 22566),  INT16_C( 19161), -INT16_C(  5954),  INT16_C(   219),  INT16_C( 24742), -INT16_C(  3222), -INT16_C( 28339) },
      UINT16_C(57009) },
    { { -INT16_C(  2466), -INT16_C( 22182),  INT16_C(  7607), -INT16_C( 27721),  INT16_C( 23837), -INT16_C( 30733), -INT16_C(  7087),  INT16_C( 15978),
        -INT16_C( 21222), -INT16_C( 14333),  INT16_C( 11333), -INT16_C( 25685),  INT16_C( 12117), -INT16_C( 11036), -INT16_C( 10355), -INT16_C(  5291) },
      { -INT16_C( 20531), -INT16_C( 31595),  INT16_C( 19660), -INT16_C(  5865),  INT16_C(  2729), -INT16_C( 30733), -INT16_C(  7087),  INT16_C(  2360),
         INT16_C( 15495), -INT16_C( 12847),  INT16_C( 31848), -INT16_C( 17048),  INT16_C( 19627),  INT16_C( 14482), -INT16_C(  6365), -INT16_C(  4060) },
      UINT16_C(  243) },
    { {  INT16_C( 24861), -INT16_C( 30996),  INT16_C( 21725), -INT16_C( 30397), -INT16_C( 10847), -INT16_C( 15167), -INT16_C(  6724),  INT16_C( 21429),
         INT16_C( 10910), -INT16_C( 23626),  INT16_C(   694),  INT16_C( 19794), -INT16_C(  1089),  INT16_C( 22483),  INT16_C( 25564), -INT16_C(  1418) },
      {  INT16_C( 25284), -INT16_C( 24192), -INT16_C( 15434),  INT16_C( 22314), -INT16_C(  4967),  INT16_C( 21788), -INT16_C( 11823),  INT16_C( 28840),
         INT16_C( 24315), -INT16_C( 20205),  INT16_C( 25953),  INT16_C(  8447), -INT16_C( 11680),  INT16_C( 15735), -INT16_C(  4811), -INT16_C(  1737) },
      UINT16_C(63556) },
    { {  INT16_C(  1648), -INT16_C( 11785), -INT16_C(  2452), -INT16_C( 13071),  INT16_C( 27080), -INT16_C(   503),  INT16_C( 16470), -INT16_C( 22793),
        -INT16_C( 27913),  INT16_C( 29356),  INT16_C(  2392),  INT16_C(  2437), -INT16_C(  4477), -INT16_C( 12916),  INT16_C( 32512),  INT16_C( 28691) },
      {  INT16_C(  2694), -INT16_C(  3519),  INT16_C( 12800), -INT16_C( 14146), -INT16_C( 14181), -INT16_C(   503), -INT16_C( 16888),  INT16_C(   152),
        -INT16_C( 27913), -INT16_C( 22414), -INT16_C(  2227), -INT16_C( 12110), -INT16_C(  4477), -INT16_C(  6498), -INT16_C( 20034),  INT16_C( 28691) },
      UINT16_C(57208) },
    { {  INT16_C( 14131), -INT16_C( 32767), -INT16_C( 19666),  INT16_C(  5201), -INT16_C(  4111), -INT16_C( 20486),  INT16_C( 20640),  INT16_C( 23539),
         INT16_C( 10727), -INT16_C( 20202), -INT16_C( 26338), -INT16_C(  9706),  INT16_C( 28131), -INT16_C(  5217),  INT16_C( 25692), -INT16_C( 28860) },
      {  INT16_C( 17819), -INT16_C( 13809), -INT16_C( 19666), -INT16_C(  5666), -INT16_C(  4111), -INT16_C(  4199), -INT16_C( 29655),  INT16_C(  4426),
         INT16_C( 24758), -INT16_C( 20202), -INT16_C(  9990), -INT16_C(  8786),  INT16_C( 20037), -INT16_C( 24119),  INT16_C(  3506),  INT16_C( 20016) },
      UINT16_C(29404) },
    { { -INT16_C( 13174), -INT16_C( 31517), -INT16_C( 28252), -INT16_C(  5791),  INT16_C( 10975), -INT16_C( 28022), -INT16_C( 17865), -INT16_C( 30240),
        -INT16_C(  1799), -INT16_C( 26157),  INT16_C(  2030), -INT16_C( 16759),  INT16_C( 26835),  INT16_C( 11447), -INT16_C( 15983),  INT16_C(  6971) },
      {  INT16_C(  7821),  INT16_C( 12703), -INT16_C( 28252), -INT16_C( 28902), -INT16_C( 23509),  INT16_C( 25377), -INT16_C( 17865),  INT16_C( 22508),
        -INT16_C( 16135), -INT16_C(  5903),  INT16_C( 31431), -INT16_C( 16759),  INT16_C( 24034),  INT16_C( 29639),  INT16_C(   542), -INT16_C( 21617) },
      UINT16_C(39260) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256i a = simde_mm256_loadu_epi16(test_vec[i].a);
    simde__m256i b = simde_mm256_loadu_epi16(test_vec[i].b);
    simde__mmask16 r = simde_mm256_cmpge_epi16_mask(a, b);
    simde_assert_equal_mmask16(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    int16_t a_[16];
    int16_t b_[16];

    simde_test_codegen_random_memory(sizeof(a_), HEDLEY_REINTERPRET_CAST(uint8_t*, a_));
    simde_test_codegen_random_memory(sizeof(b_), HEDLEY_REINTERPRET_CAST(uint8_t*, b_));
    for (size_t j = 0 ; j < (sizeof(a_) / sizeof(a_[0])) ; j++)
      if ((simde_test_codegen_rand() & 3) == 0)
        b_[j] = a_[j];

    simde__m256i a = simde_mm256_loadu_epi16(a_);
    simde__m256i b = simde_mm256_loadu_epi16(b_);
    simde__mmask16 r = simde_mm256_cmpge_epi16_mask(a, b);

    simde_test_x86_write_i16x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i16x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_mask_cmpge_epi16_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask16 k;
    const int16_t a[16];
    const int16_t b[16];
    const simde__mmask16 r;
  } test_vec[] = {
    { UINT16_C(17783),
      {  INT16_C( 16490),  INT16_C( 12645),  INT16_C(  3002), -INT16_C( 25396), -INT16_C( 27800), -INT16_C( 31216), -INT16_C( 24683), -INT16_C( 18895),
         INT16_C(  3533), -INT16_C(   633), -INT16_C(  6141), -INT16_C( 25256),  INT16_C(  5738), -INT16_C(  4715), -INT16_C(  6976),  INT16_C( 11114) },
      {  INT16_C( 16490), -INT16_C(  8356),  INT16_C(  3002),  INT16_C( 17020), -INT16_C( 27800), -INT16_C( 31216), -INT16_C(  1749), -INT16_C(  2041),
         INT16_C(  3533),  INT16_C(  2549), -INT16_C(  6141), -INT16_C(  7770),  INT16_C( 15203), -INT16_C(  4715), -INT16_C(  6976),  INT16_C( 17743) },
      UINT16_C(17719) },
    { UINT16_C(52607),
      { -INT16_C(  4361), -INT16_C( 24941), -INT16_C(  2353), -INT16_C( 25127), -INT16_C(  1766),  INT16_C( 27094), -INT16_C(  8386),  INT16_C( 25365),
        -INT16_C(  5694), -INT16_C(  6397),  INT16_C( 12408),  INT16_C( 22997), -INT16_C( 17017), -INT16_C( 10431), -INT16_C( 18261), -INT16_C( 24035) },
      { -INT16_C(  4361),  INT16_C( 30016),  INT16_C(  6822), -INT16_C( 16110), -INT16_C(  1766),  INT16_C( 27094), -INT16_C(  8386), -INT16_C( 30027),
        -INT16_C( 18392), -INT16_C( 24207),  INT16_C( 18408),  INT16_C( 28922),  INT16_C( 15108), -INT16_C( 20665),  INT16_C( 25843), -INT16_C( 26287) },
      UINT16_C(33137) },
    { UINT16_C( 2737),
      {  INT16_C( 26543), -INT16_C( 22252),  INT16_C(  6359),  INT16_C(  8164), -INT16_C( 10297),  INT16_C(  6275), -INT16_C( 26512),  INT16_C( 32426),
         INT16_C( 22099), -INT16_C( 12385), -INT16_C( 22506),  INT16_C( 10101),  INT16_C( 23418), -INT16_C( 10770),  INT16_C( 28010),  INT16_C(  6562) },
      { -INT16_C( 18732), -INT16_C( 22252),  INT16_C(  6359),  INT16_C(  8164),  INT16_C( 20095), -INT16_C(  4178),  INT16_C( 22758),  INT16_C( 14702),
         INT16_C(  3503), -INT16_C( 12385),  INT16_C( 32437),  INT16_C( 10101),  INT16_C( 23418), -INT16_C( 10770), -INT16_C( 22713),  INT16_C(  7261) },
      UINT16_C( 2721) },
    { UINT16_C(63616),
      {  INT16_C( 26172),  INT16_C( 10632),  INT16_C( 24982), -INT16_C( 25853),  INT16_C( 19365),  INT16_C(   578), -INT16_C( 24473),  INT16_C( 12066),
        -INT16_C(  5683), -INT16_C( 28734), -INT16_C( 23760),  INT16_C( 26367), -INT16_C( 14485),  INT16_C( 27914), -INT16_C( 17601),  INT16_C( 31607) },
      { -INT16_C(   223), -INT16_C( 18524), -INT16_C( 22432),  INT16_C(  1362), -INT16_C( 27149),  INT16_C( 23047),  INT16_C( 10549),  INT16_C(   649),
         INT16_C( 19219),  INT16_C( 17297), -INT16_C( 23760),  INT16_C( 26367), -INT16_C( 14485), -INT16_C( 26681),  INT16_C( 15982), -INT16_C( 28910) },
      UINT16_C(47232) },
    { UINT16_C( 4657),
      {  INT16_C( 28202), -INT16_C( 11384), -INT16_C(  7992), -INT16_C( 28794), -INT16_C(  2953), -INT16_C( 30003),  INT16_C(  2691), -INT16_C( 13759),
        -INT16_C( 24408),  INT16_C( 19300), -INT16_C( 27918), -INT16_C( 24843), -INT16_C( 13834),  INT16_C( 24019),  INT16_C( 21424), -INT16_C(  9643) },
      { -INT16_C(  8767), -INT16_C( 11384),  INT16_C( 13246), -INT16_C( 28794), -INT16_C(  6361), -INT16_C( 21569),  INT16_C(   241), -INT16_C( 26251),
        -INT16_C(  9824), -INT16_C( 27932), -INT16_C(  9620), -INT16_C( 24843),  INT16_C(   931),  INT16_C( 21695),  INT16_C(  5206),  INT16_C(  6190) },
      UINT16_C(  529) },
    { UINT16_C(17365),
      { -INT16_C( 25128),  INT16_C(  2540), -INT16_C( 28673), -INT16_C( 16628),  INT16_C( 25571),  INT16_C(  4819), -INT16_C( 14981),  INT16_C(  7662),
        -INT16_C(   651),  INT16_C( 23512),  INT16_C( 31540),  INT16_C(  5632), -INT16_C( 23281),  INT16_C( 15470), -INT16_C( 24597), -INT16_C( 15282) },
      { -INT16_C( 25128),  INT16_C( 15309), -INT16_C(  9782), -INT16_C( 20998), -INT16_C( 12740), -INT16_C( 18497), -INT16_C( 14981),  INT16_C(  7662),
        -INT16_C( 21077), -INT16_C(  8348),  INT16_C( 25640),  INT16_C( 14326),  INT16_C( 25609),  INT16_C( 15470), -INT16_C( 15869), -INT16_C( 15282) },
      UINT16_C(  977) },
    { UINT16_C(60799),
      { -INT16_C(   661),  INT16_C( 24999), -INT16_C( 20172), -INT16_C( 22587), -INT16_C( 14170),  INT16_C( 24425),  INT16_C( 26119), -INT16_C( 32027),
         INT16_C( 17452), -INT16_C( 24329),  INT16_C( 15072),  INT16_C( 13524), -INT16_C( 19184), -INT16_C(  4004),  INT16_C( 12609), -INT16_C( 21453) },
      { -INT16_C(  9426),  INT16_C( 25102), -INT16_C( 20172),  INT16_C( 12809),  INT16_C( 29596), -INT16_C( 23663),  INT16_C( 30425),  INT16_C(  1317),
         INT16_C( 17452), -INT16_C( 24329),  INT16_C( 31318),  INT16_C( 26575),  INT16_C( 11055),  INT16_C( 28759), -INT16_C( 30116), -INT16_C( 30180) },
      UINT16_C(49445) },
    { UINT16_C(18456),
      { -INT16_C( 10624),  INT16_C( 20327), -INT16_C( 27075), -INT16_C( 27526), -INT16_C( 10746),  INT16_C(  8734), -INT16_C( 31648),  INT16_C( 19533),
         INT16_C( 19317), -INT16_C( 26303), -INT16_C( 21787),  INT16_C(  8781),  INT16_C( 30955),  INT16_C( 12933),  INT16_C(  1373), -INT16_C(  8929) },
      { -INT16_C( 31013),  INT16_C( 20327), -INT16_C( 23012), -INT16_C( 27526), -INT16_C( 13700), -INT16_C(  9147), -INT16_C( 28082), -INT16_C( 15320),
         INT16_C( 19317), -INT16_C( 15779), -INT16_C( 21997), -INT16_C(    28),  INT16_C( 27170),  INT16_C( 32561),  INT16_C( 20847),  INT16_C( 19036) },
      UINT16_C( 2072) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__mmask16 k = test_vec[i].k;
    simde__m256i a = simde_mm256_loadu_epi16(test_vec[i].a);
    simde__m256i b = simde_mm256_loadu_epi16(test_vec[i].b);
    simde__mmask16 r = simde_mm256_mask_cmpge_epi16_mask(k, a, b);
    simde_assert_equal_mmask16(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    int16_t a_[16];
    int16_t b_[16];

    simde_test_codegen_random_memory(sizeof(a_), HEDLEY_REINTERPRET_CAST(uint8_t*, a_));
    simde_test_codegen_random_memory(sizeof(b_), HEDLEY_REINTERPRET_CAST(uint8_t*, b_));
    for (size_t j = 0 ; j < (sizeof(a_) / sizeof(a_[0])) ; j++)
      if ((simde_test_codegen_rand() & 3) == 0)
        b_[j] = a_[j];

    simde__mmask16 k = simde_test_x86_random_mmask16();
    simde__m256i a = simde_mm256_loadu_epi16(a_);
    simde__m256i b = simde_mm256_loadu_epi16(b_);
    simde__mmask16 r = simde_mm256_mask_cmpge_epi16_mask(k, a, b);

    simde_test_x86_write_mmask16(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i16x16(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_x_mm512_cmpge_epi16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int16_t a[32];
    const int16_t b[32];
    const int16_t r[32];
  } test_vec[] = {
    { {  INT16_C( 11148),  INT16_C( 29170),  INT16_C(  5418),  INT16_C( 23771),  INT16_C( 19092), -INT16_C(  3667), -INT16_C( 31596), -INT16_C(  2439),
        -INT16_C( 22408), -INT16_C( 28924), -INT16_C(  9134), -INT16_C(  9750), -INT16_C( 10237), -INT16_C(  4473), -INT16_C( 24670),  INT16_C( 12086),
         INT16_C( 10699), -INT16_C(  2656),  INT16_C( 31550), -INT16_C( 11695), -INT16_C(   315),  INT16_C( 22979),  INT16_C( 15747), -INT16_C(  1201),
         INT16_C( 21477),  INT16_C( 14218),  INT16_C( 29999),  INT16_C( 13072), -INT16_C( 26547), -INT16_C(  4319),  INT16_C( 22583),  INT16_C(   542) },
      { -INT16_C( 16767), -INT16_C( 16392),  INT16_C( 18745),  INT16_C( 23771),  INT16_C( 21832), -INT16_C( 13481), -INT16_C( 22894),  INT16_C( 30662),
        -INT16_C( 22408), -INT16_C( 28924), -INT16_C(  9134),  INT16_C(  4956), -INT16_C( 10237), -INT16_C( 29182),  INT16_C(  8661),  INT16_C( 22161),
         INT16_C( 10699),  INT16_C(  6421),  INT16_C( 31550),  INT16_C(  6679),  INT16_C( 28668), -INT16_C( 28955),  INT16_C( 15747),  INT16_C(  3845),
        -INT16_C( 19459),  INT16_C( 14218), -INT16_C( 27534),  INT16_C( 13072), -INT16_C( 10223), -INT16_C(  6312), -INT16_C(  5639), -INT16_C(  9923) },
      { -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
        -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
        -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
        -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1) } },
    { {  INT16_C(  9202), -INT16_C(  5008), -INT16_C( 12499), -INT16_C( 23070),  INT16_C( 26131),  INT16_C(  1075), -INT16_C( 12049),  INT16_C( 11249),
        -INT16_C( 23899),  INT16_C(  3802),  INT16_C( 21288), -INT16_C( 30839), -INT16_C(  5597), -INT16_C(  8736),  INT16_C(  4489),  INT16_C( 31496),
         INT16_C( 30773),  INT16_C( 25191),  INT16_C( 18759),  INT16_C( 23303),  INT16_C( 15279), -INT16_C( 24993),  INT16_C( 20491), -INT16_C( 20022),
        -INT16_C( 23310),  INT16_C(  7103),  INT16_C( 18679),  INT16_C(  7074), -INT16_C( 32205), -INT16_C( 17160),  INT16_C(   148), -INT16_C( 14024) },
      { -INT16_C( 24711), -INT16_C( 16341),  INT16_C( 13033), -INT16_C( 26597),  INT16_C( 31341),  INT16_C( 31031), -INT16_C( 12049), -INT16_C( 17110),
        -INT16_C(  5723), -INT16_C( 25128),  INT16_C( 31538),  INT16_C( 26040), -INT16_C( 20227), -INT16_C( 28383),  INT16_C( 22960),  INT16_C( 10586),
        -INT16_C( 31239), -INT16_C(  7446),  INT16_C(  1464),  INT16_C(  9594), -INT16_C( 20096),  INT16_C( 19358),  INT16_C( 20491), -INT16_C( 20022),
        -INT16_C(  7758), -INT16_C(  6923), -INT16_C( 21156),  INT16_C( 22857),  INT16_C( 27229),  INT16_C(  3563),  INT16_C( 17860), -INT16_C( 14024) },
      { -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),
         INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
        -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),
         INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1) } },
    { {  INT16_C( 31034),  INT16_C( 24591), -INT16_C( 18542),  INT16_C( 23815), -INT16_C(  1794),  INT16_C(  3803), -INT16_C( 20238), -INT16_C( 12849),
         INT16_C( 30075), -INT16_C(  3580), -INT16_C( 27293), -INT16_C( 17209), -INT16_C( 22256), -INT16_C( 11815), -INT16_C( 19518), -INT16_C(   931),
         INT16_C( 27692), -INT16_C( 16548),  INT16_C( 25380),  INT16_C(  8732), -INT16_C(  2212),  INT16_C( 20016),  INT16_C(   168),  INT16_C(  8988),
         INT16_C(  8309), -INT16_C( 10219), -INT16_C(  9035), -INT16_C( 14699),  INT16_C( 28293),  INT16_C( 18327), -INT16_C(  2782),  INT16_C( 20035) },
      { -INT16_C( 24479),  INT16_C( 24591),  INT16_C( 10755),  INT16_C( 24488), -INT16_C( 10207), -INT16_C( 13906), -INT16_C( 20238),  INT16_C( 19948),
         INT16_C(   746), -INT16_C(  3580), -INT16_C( 17442),  INT16_C( 25702), -INT16_C(   727),  INT16_C( 19371), -INT16_C(  4110), -INT16_C(   931),
         INT16_C( 27692), -INT16_C( 27943), -INT16_C( 32303), -INT16_C(  3086), -INT16_C( 24486),  INT16_C( 12988), -INT16_C( 22166),  INT16_C( 21632),
         INT16_C(  8309), -INT16_C( 30220),  INT16_C( 23137), -INT16_C( 14699), -INT16_C( 26280),  INT16_C( 19158),  INT16_C( 28808),  INT16_C(  6046) },
      { -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
        -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
        -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
        -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1) } },
    { {  INT16_C( 17666), -INT16_C(  1058), -INT16_C( 17696),  INT16_C(  7247), -INT16_C( 10926), -INT16_C( 27455), -INT16_C( 17445), -INT16_C( 30848),
        -INT16_C(  2390), -INT16_C(  3180),  INT16_C( 11098),  INT16_C( 22164),  INT16_C( 32665),  INT16_C( 30427),  INT16_C( 30217),  INT16_C(  2923),
         INT16_C( 18875), -INT16_C( 25593),  INT16_C( 22019),  INT16_C( 22200),  INT16_C( 31019),  INT16_C(  1770),  INT16_C( 27189), -INT16_C(  8307),
         INT16_C(  8545), -INT16_C( 17454),  INT16_C( 26188), -INT16_C(  6895), -INT16_C(  4891), -INT16_C(  4260), -INT16_C( 14493),  INT16_C(  7930) },
      {  INT16_C(   273),  INT16_C(  5306), -INT16_C( 17696), -INT16_C( 32150),  INT16_C( 21740),  INT16_C(  8584),  INT16_C(  5567),  INT16_C(  8192),
        -INT16_C( 11722), -INT16_C( 31781), -INT16_C(  5064),  INT16_C(  7528), -INT16_C( 15143),  INT16_C( 15372),  INT16_C(  1932), -INT16_C( 25254),
         INT16_C(  5384),  INT16_C( 24753),  INT16_C( 22019),  INT16_C( 29666),  INT16_C( 27504),  INT16_C(  1770), -INT16_C( 27520), -INT16_C(  8307),
         INT16_C( 10854), -INT16_C( 25030), -INT16_C( 24041), -INT16_C(  6895), -INT16_C( 14233), -INT16_C(  3284), -INT16_C( 14493),  INT16_C(  7930) },
      { -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
        -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),
        -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),
         INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1) } },
    { {  INT16_C( 10437),  INT16_C(  8943), -INT16_C( 31165), -INT16_C( 14096), -INT16_C(  4431),  INT16_C( 28878), -INT16_C( 29893), -INT16_C( 19818),
         INT16_C( 23426),  INT16_C(  7233), -INT16_C( 16421),  INT16_C(  9244),  INT16_C(  4202), -INT16_C( 25795),  INT16_C( 11667),  INT16_C( 22631),
         INT16_C( 22358), -INT16_C( 26245),  INT16_C( 27613), -INT16_C( 29087),  INT16_C( 12377), -INT16_C( 27394), -INT16_C( 27205),  INT16_C( 15943),
        -INT16_C( 30480), -INT16_C( 13478),  INT16_C( 30279), -INT16_C( 19984),  INT16_C( 11654),  INT16_C(  6732), -INT16_C( 19366), -INT16_C( 20366) },
      {  INT16_C( 10437),  INT16_C(  8943), -INT16_C( 31165), -INT16_C( 19850),  INT16_C( 29915), -INT16_C( 27065), -INT16_C( 29175), -INT16_C(  1580),
         INT16_C( 11798),  INT16_C( 24005), -INT16_C( 16421),  INT16_C( 11023),  INT16_C(  4202), -INT16_C( 25795), -INT16_C( 18417),  INT16_C(  6893),
         INT16_C( 13989), -INT16_C( 26245),  INT16_C( 30945), -INT16_C( 17231), -INT16_C(  1811), -INT16_C( 27394),  INT16_C( 10118), -INT16_C( 25360),
        -INT16_C( 30480), -INT16_C( 13478),  INT16_C( 30279), -INT16_C( 19984),  INT16_C( 27748),  INT16_C( 29576),  INT16_C( 29988), -INT16_C( 13938) },
      { -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
        -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),
        -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
        -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
    { {  INT16_C( 23947), -INT16_C( 27521), -INT16_C( 13866),  INT16_C( 18314),  INT16_C( 30310),  INT16_C( 10814), -INT16_C( 11949), -INT16_C(  7099),
         INT16_C( 23134), -INT16_C(  3104),  INT16_C( 10134),  INT16_C( 16108),  INT16_C( 22775),  INT16_C( 15626), -INT16_C( 24493), -INT16_C(  8658),
        -INT16_C( 20995), -INT16_C( 11150), -INT16_C(   906), -INT16_C(  9189),  INT16_C( 23154), -INT16_C( 15097),  INT16_C( 19499), -INT16_C( 30294),
        -INT16_C( 30042),  INT16_C( 15740),  INT16_C( 26801), -INT16_C( 22149), -INT16_C( 31039),  INT16_C(  5350),  INT16_C(  5158),  INT16_C(  9202) },
      {  INT16_C( 25794),  INT16_C( 14583), -INT16_C( 13866), -INT16_C( 11755),  INT16_C(  7277),  INT16_C( 10814),  INT16_C( 17000),  INT16_C(  3618),
        -INT16_C( 24884),  INT16_C( 32075),  INT16_C( 10134), -INT16_C( 14298),  INT16_C( 22775),  INT16_C( 29660), -INT16_C( 12767), -INT16_C(  7274),
        -INT16_C( 29134), -INT16_C( 28133),  INT16_C( 12449),  INT16_C(  3684),  INT16_C( 23154), -INT16_C( 19290), -INT16_C( 14274),  INT16_C(  2755),
         INT16_C(  3687),  INT16_C( 28296), -INT16_C( 20779),  INT16_C(  8758),  INT16_C(  4795), -INT16_C(  9067),  INT16_C( 11488),  INT16_C(  4799) },
      {  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
        -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
        -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
         INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1) } },
    { { -INT16_C( 29771), -INT16_C( 16212),  INT16_C(  5523), -INT16_C( 26601),  INT16_C(  8996), -INT16_C(   804),  INT16_C( 10994), -INT16_C( 12229),
        -INT16_C(  6144), -INT16_C( 31613),  INT16_C( 22731), -INT16_C( 16188), -INT16_C(  8253),  INT16_C( 23189),  INT16_C( 31930),  INT16_C( 28587),
         INT16_C( 22279), -INT16_C( 25809),  INT16_C( 18028), -INT16_C( 28365),  INT16_C(  3946),  INT16_C( 23693), -INT16_C( 14023),  INT16_C( 14636),
        -INT16_C( 20559),  INT16_C( 32190), -INT16_C( 32248), -INT16_C( 13507), -INT16_C( 11423),  INT16_C(  6950), -INT16_C( 11953),  INT16_C( 22410) },
      { -INT16_C( 18135), -INT16_C( 27150),  INT16_C(  9472),  INT16_C( 27174), -INT16_C( 19403),  INT16_C( 28358), -INT16_C(  3203), -INT16_C( 12229),
        -INT16_C(  6144), -INT16_C( 21845),  INT16_C( 22731), -INT16_C( 16188), -INT16_C( 25412),  INT16_C(  2917), -INT16_C(  4243),  INT16_C( 28587),
         INT16_C( 21673), -INT16_C( 22228),  INT16_C( 18028), -INT16_C( 20717),  INT16_C(  3946), -INT16_C( 31971), -INT16_C( 14023),  INT16_C( 14636),
         INT16_C( 23851),  INT16_C(  4889), -INT16_C( 28858), -INT16_C( 13507), -INT16_C( 15829),  INT16_C(  6950),  INT16_C( 28849),  INT16_C( 22410) },
      {  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),
        -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),
        -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),
         INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1) } },
    { {  INT16_C( 15908), -INT16_C( 11757),  INT16_C(   341),  INT16_C( 17798), -INT16_C( 16884), -INT16_C(  8959),  INT16_C( 11688), -INT16_C(  3878),
        -INT16_C(  5518),  INT16_C( 18046),  INT16_C(  3671), -INT16_C( 31162), -INT16_C(  8275), -INT16_C( 17306), -INT16_C( 24152), -INT16_C( 13168),
        -INT16_C( 23584),  INT16_C( 13726),  INT16_C(  9380), -INT16_C( 20358),  INT16_C( 31715), -INT16_C( 29810),  INT16_C( 26792),  INT16_C(  6779),
        -INT16_C(  1710), -INT16_C( 22175), -INT16_C( 22776), -INT16_C( 19153), -INT16_C( 27257),  INT16_C( 12145),  INT16_C(   311),  INT16_C(  6139) },
      { -INT16_C( 26204),  INT16_C( 18508), -INT16_C( 14659), -INT16_C( 24328), -INT16_C( 16884), -INT16_C(  5588),  INT16_C( 11688),  INT16_C( 16388),
         INT16_C( 26017), -INT16_C( 22039),  INT16_C(  3671), -INT16_C( 27554), -INT16_C(  8275), -INT16_C(  6717), -INT16_C( 16688),  INT16_C( 29948),
         INT16_C( 18519),  INT16_C(  5308),  INT16_C(  9380),  INT16_C( 20405),  INT16_C( 31715), -INT16_C( 29810),  INT16_C( 26792),  INT16_C( 10602),
        -INT16_C(  1710), -INT16_C( 20270),  INT16_C( 12396),  INT16_C(  6724),  INT16_C(  2047), -INT16_C( 12289), -INT16_C(  1083),  INT16_C(  7235) },
      { -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
         INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
         INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
        -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i a = simde_mm512_loadu_epi16(test_vec[i].a);
    simde__m512i b = simde_mm512_loadu_epi16(test_vec[i].b);
    simde__m512i r = simde_x_mm512_cmpge_epi16(a, b);
    simde_test_x86_assert_equal_i16x32(r, simde_mm512_loadu_epi16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    int16_t a_[32];
    int16_t b_[32];

    simde_test_codegen_random_memory(sizeof(a_), HEDLEY_REINTERPRET_CAST(uint8_t*, a_));
    simde_test_codegen_random_memory(sizeof(b_), HEDLEY_REINTERPRET_CAST(uint8_t*, b_));
    for (size_t j = 0 ; j < (sizeof(a_) / sizeof(a_[0])) ; j++)
      if ((simde_test_codegen_rand() & 3) == 0)
        b_[j] = a_[j];

    simde__m512i a = simde_mm512_loadu_epi16(a_);
    simde__m512i b = simde_mm512_loadu_epi16(b_);
    simde__m512i r = simde_x_mm512_cmpge_epi16(a, b);

    simde_test_x86_write_i16x32(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i16x32(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_cmpge_epi16_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int16_t a[32];
    const int16_t b[32];
    const simde__mmask32 r;
  } test_vec[] = {
    { { -INT16_C( 10411),  INT16_C(  2760), -INT16_C( 11574),  INT16_C(  5542),  INT16_C(  7856), -INT16_C(  8989), -INT16_C( 10862),  INT16_C(  1833),
         INT16_C( 26137), -INT16_C( 28206), -INT16_C( 27817), -INT16_C( 22631),  INT16_C( 15525), -INT16_C( 26625),  INT16_C( 12948), -INT16_C(  5833),
         INT16_C(    10), -INT16_C( 11021), -INT16_C( 26158), -INT16_C( 32022), -INT16_C( 12873),  INT16_C( 18783), -INT16_C( 30558), -INT16_C( 17584),
         INT16_C(  9198),  INT16_C( 17996), -INT16_C(  6474),  INT16_C( 23789), -INT16_C(  5086), -INT16_C( 18701),  INT16_C( 10783),  INT16_C( 10655) },
      { -INT16_C( 28118), -INT16_C(   515), -INT16_C(  6357),  INT16_C(  5542), -INT16_C(  8524),  INT16_C( 22060),  INT16_C( 32102),  INT16_C( 21778),
         INT16_C( 24224),  INT16_C( 22171), -INT16_C( 30652), -INT16_C( 22631), -INT16_C( 23180), -INT16_C( 27876), -INT16_C( 17456), -INT16_C(  1348),
        -INT16_C( 17843),  INT16_C( 31223),  INT16_C( 30625),  INT16_C( 22108), -INT16_C( 12873), -INT16_C( 17236), -INT16_C( 30558), -INT16_C( 17584),
         INT16_C(  9198),  INT16_C( 17996), -INT16_C(  6474),  INT16_C( 23789), -INT16_C(  5086),  INT16_C(  9276), -INT16_C(  1888), -INT16_C(  4834) },
      UINT32_C(3757145371) },
    { {  INT16_C( 13389), -INT16_C(  9613),  INT16_C(  7670),  INT16_C( 16828),  INT16_C( 23411), -INT16_C( 30574), -INT16_C( 30710),  INT16_C( 26298),
         INT16_C( 20090),  INT16_C(  6901),  INT16_C( 11689), -INT16_C(  5873),  INT16_C( 10145),  INT16_C(  3785), -INT16_C( 26786), -INT16_C( 21715),
        -INT16_C( 24373), -INT16_C( 15995),  INT16_C( 17085),  INT16_C( 12291), -INT16_C( 27235), -INT16_C( 22599),  INT16_C( 29469), -INT16_C( 26867),
         INT16_C(   961),  INT16_C( 27569), -INT16_C( 16336), -INT16_C( 11692),  INT16_C(  7912),  INT16_C( 18144),  INT16_C(  3509), -INT16_C( 32526) },
      {  INT16_C( 30637),  INT16_C( 27201),  INT16_C( 17593),  INT16_C( 22170),  INT16_C( 21465), -INT16_C(  2306),  INT16_C(  3015), -INT16_C( 30579),
         INT16_C( 20090),  INT16_C( 16371),  INT16_C( 18687), -INT16_C(  6383), -INT16_C(  3738),  INT16_C(  6958), -INT16_C( 26786), -INT16_C( 21605),
        -INT16_C(  9065),  INT16_C( 20757),  INT16_C( 17085), -INT16_C(  1369), -INT16_C( 23293), -INT16_C( 22599),  INT16_C( 32433), -INT16_C( 16558),
         INT16_C( 18109),  INT16_C( 27569),  INT16_C(  3982), -INT16_C(  2908), -INT16_C( 11776), -INT16_C(   497), -INT16_C( 21774), -INT16_C( 30039) },
      UINT32_C(1915509136) },
    { {  INT16_C( 23053),  INT16_C( 31548), -INT16_C(  8483),  INT16_C(  1516),  INT16_C( 10097), -INT16_C( 31778),  INT16_C( 30389), -INT16_C( 30638),
        -INT16_C(  8691), -INT16_C( 19222),  INT16_C( 16142),  INT16_C(  4443),  INT16_C(   164), -INT16_C( 19961), -INT16_C( 31153),  INT16_C( 23879),
        -INT16_C( 31519), -INT16_C( 16680), -INT16_C( 15006), -INT16_C( 11069), -INT16_C( 24084), -INT16_C( 24233), -INT16_C( 22249),  INT16_C(  9514),
         INT16_C(  5255), -INT16_C( 27175),  INT16_C( 13395), -INT16_C(  2137), -INT16_C( 20940), -INT16_C( 31574), -INT16_C(  3788),  INT16_C(  5601) },
      { -INT16_C( 18059),  INT16_C( 31548), -INT16_C( 27010),  INT16_C(  1516),  INT16_C(   823),  INT16_C( 20236),  INT16_C( 13996), -INT16_C( 30638),
         INT16_C( 19786), -INT16_C( 24888),  INT16_C( 28545), -INT16_C( 19051),  INT16_C( 16157),  INT16_C( 21049),  INT16_C(  6705), -INT16_C( 22937),
         INT16_C( 15316),  INT16_C( 21118), -INT16_C( 15006),  INT16_C(  2493), -INT16_C( 24084), -INT16_C(  9896), -INT16_C( 13312),  INT16_C( 19212),
         INT16_C(  5255), -INT16_C( 25879),  INT16_C( 32324), -INT16_C(  2137), -INT16_C( 30274), -INT16_C(  4172),  INT16_C(  7075),  INT16_C( 30613) },
      UINT32_C( 420776671) },
    { { -INT16_C( 15013), -INT16_C( 26341),  INT16_C( 19533), -INT16_C( 25083),  INT16_C( 19413),  INT16_C( 10992), -INT16_C( 29283), -INT16_C( 15208),
        -INT16_C( 24557),  INT16_C(  6191), -INT16_C(   520), -INT16_C( 10022), -INT16_C( 29570),  INT16_C(  7004),  INT16_C( 22739),  INT16_C( 11791),
         INT16_C( 10781),  INT16_C( 27335), -INT16_C( 12937),  INT16_C( 19465), -INT16_C(  1768), -INT16_C( 19081),  INT16_C(  3975), -INT16_C( 25991),
        -INT16_C( 22352), -INT16_C( 22350), -INT16_C( 29275),  INT16_C(  9344), -INT16_C(  8935), -INT16_C(  5057),  INT16_C( 20021),  INT16_C( 21018) },
      { -INT16_C(  7815), -INT16_C(  3907), -INT16_C( 14674), -INT16_C( 25083), -INT16_C( 19521),  INT16_C( 18043), -INT16_C(  2877),  INT16_C( 29665),
        -INT16_C( 24557),  INT16_C( 16923), -INT16_C( 25824),  INT16_C( 14694), -INT16_C( 22920), -INT16_C( 21211),  INT16_C( 16372),  INT16_C( 27904),
        -INT16_C( 17119), -INT16_C( 12451), -INT16_C( 25981),  INT16_C( 17046),  INT16_C(  4429), -INT16_C( 19081),  INT16_C(  3975), -INT16_C( 23677),
        -INT16_C( 24835), -INT16_C( 22350),  INT16_C( 19514), -INT16_C( 19881), -INT16_C(  8935), -INT16_C(  6560),  INT16_C( 24764), -INT16_C(  8876) },
      UINT32_C(3144639772) },
    { {  INT16_C(  3085),  INT16_C( 22581),  INT16_C(  5967), -INT16_C( 23311), -INT16_C( 25725),  INT16_C( 22782), -INT16_C(   824), -INT16_C( 27861),
         INT16_C(  7391),  INT16_C(  3737),  INT16_C( 20837),  INT16_C( 10799),  INT16_C( 13929), -INT16_C(  7764),  INT16_C(  3218), -INT16_C( 24714),
        -INT16_C( 21736),  INT16_C( 26871), -INT16_C(  5694),  INT16_C( 17676),  INT16_C(  2692),  INT16_C( 19614), -INT16_C( 14074), -INT16_C(  6689),
         INT16_C( 30950),  INT16_C( 19443),  INT16_C(  8905),  INT16_C( 12917),  INT16_C(  8793), -INT16_C(  5357), -INT16_C( 30418),  INT16_C( 18058) },
      { -INT16_C( 32460), -INT16_C(  2130), -INT16_C( 17814), -INT16_C(  4548), -INT16_C(  9531), -INT16_C( 13510), -INT16_C(   824), -INT16_C( 30031),
         INT16_C(  7391),  INT16_C( 23765),  INT16_C( 19143),  INT16_C( 10799), -INT16_C( 23956), -INT16_C( 26101), -INT16_C( 27349),  INT16_C( 24801),
        -INT16_C( 28906), -INT16_C( 32425), -INT16_C( 27830),  INT16_C(  3951), -INT16_C( 21906),  INT16_C( 19614), -INT16_C( 29756),  INT16_C( 22172),
         INT16_C( 28976),  INT16_C( 19443),  INT16_C( 16827),  INT16_C( 10263),  INT16_C(  8931),  INT16_C(  3778), -INT16_C( 23625), -INT16_C( 12946) },
      UINT32_C(2340388327) },
    { {  INT16_C(  9627), -INT16_C(  2849),  INT16_C( 27619),  INT16_C( 19387), -INT16_C( 27438), -INT16_C( 15241), -INT16_C(  1783), -INT16_C(  4122),
        -INT16_C(   210), -INT16_C( 23407),  INT16_C( 23087), -INT16_C( 32259),  INT16_C( 26086),  INT16_C(  5770),  INT16_C( 24635), -INT16_C( 10632),
         INT16_C( 22661),  INT16_C( 26827), -INT16_C( 31037), -INT16_C( 27213),  INT16_C( 10779),  INT16_C(  9305),  INT16_C( 16164),  INT16_C( 21012),
        -INT16_C( 23234),  INT16_C( 28151), -INT16_C(  2817), -INT16_C(  6418),  INT16_C( 30809), -INT16_C( 27396),  INT16_C( 29913),  INT16_C( 24171) },
      {  INT16_C(  9627), -INT16_C( 28473),  INT16_C( 31420), -INT16_C( 10459),  INT16_C( 32677), -INT16_C( 13828),  INT16_C(  4286), -INT16_C(   741),
         INT16_C(  4789), -INT16_C( 19350),  INT16_C( 22791),  INT16_C( 24730), -INT16_C( 26927), -INT16_C( 21771),  INT16_C( 24635), -INT16_C( 10487),
        -INT16_C( 12138),  INT16_C( 26827), -INT16_C( 29366), -INT16_C(  4310),  INT16_C(  9740),  INT16_C(  9305), -INT16_C( 11210), -INT16_C(  5177),
         INT16_C( 13030), -INT16_C(  4705),  INT16_C( 14987),  INT16_C( 23630),  INT16_C( 17360), -INT16_C(  9465),  INT16_C(  4259),  INT16_C( 14771) },
      UINT32_C(3539170315) },
    { {  INT16_C( 29519), -INT16_C(  2176), -INT16_C( 26072),  INT16_C(  1194),  INT16_C( 10349),  INT16_C(  4885),  INT16_C(  4718), -INT16_C(  6752),
         INT16_C(  7086), -INT16_C( 31512),  INT16_C( 18403), -INT16_C(  4310), -INT16_C( 21331),  INT16_C(  9117), -INT16_C( 31263),  INT16_C( 12665),
        -INT16_C(  1544),  INT16_C(  8232), -INT16_C( 11628),  INT16_C(   292),  INT16_C( 15099),  INT16_C( 26900), -INT16_C( 19124), -INT16_C(  1458),
         INT16_C( 14032), -INT16_C( 19586), -INT16_C( 22403),  INT16_C( 10914),  INT16_C( 16469),  INT16_C( 13901), -INT16_C( 14651), -INT16_C( 17049) },
      { -INT16_C( 28736), -INT16_C(  2176),  INT16_C(   610),  INT16_C( 23893),  INT16_C( 10349), -INT16_C( 30522),  INT16_C(  5150), -INT16_C(  4478),
         INT16_C(    75), -INT16_C( 14174),  INT16_C( 17576), -INT16_C(  4310),  INT16_C( 16516),  INT16_C(  9117), -INT16_C( 25849), -INT16_C( 14586),
        -INT16_C(  7125), -INT16_C( 29413), -INT16_C( 11628),  INT16_C(  8938), -INT16_C( 20263), -INT16_C(  1878),  INT16_C( 11460),  INT16_C(  4070),
         INT16_C( 14032), -INT16_C( 11048), -INT16_C( 22403),  INT16_C( 20946),  INT16_C( 16469),  INT16_C(  4763), -INT16_C( 24159), -INT16_C( 13095) },
      UINT32_C(1966583091) },
    { {  INT16_C(   854), -INT16_C( 17423),  INT16_C( 32327),  INT16_C( 15097),  INT16_C( 12214),  INT16_C(  6642), -INT16_C( 17845), -INT16_C(  3927),
         INT16_C(  3417), -INT16_C( 15262),  INT16_C(  9795),  INT16_C( 32570), -INT16_C( 15740), -INT16_C( 31652),  INT16_C(  1572),  INT16_C( 31498),
        -INT16_C(  1270),  INT16_C( 20790),  INT16_C( 12153),  INT16_C( 12171),  INT16_C( 32350), -INT16_C( 22199), -INT16_C(  3528), -INT16_C( 28262),
        -INT16_C(   769),  INT16_C( 16981), -INT16_C( 28894), -INT16_C( 22591),  INT16_C(  7506),  INT16_C( 30251),  INT16_C( 13604),  INT16_C( 12017) },
      {  INT16_C(   854), -INT16_C( 17423),  INT16_C(  2646),  INT16_C( 15097),  INT16_C(  8840), -INT16_C( 16290), -INT16_C( 17845),  INT16_C(  4946),
        -INT16_C( 22540), -INT16_C( 15262),  INT16_C(  5687),  INT16_C( 32570), -INT16_C(  5836), -INT16_C( 31652), -INT16_C(  3809),  INT16_C( 20358),
         INT16_C(  1304),  INT16_C( 28665), -INT16_C( 11505), -INT16_C( 26589), -INT16_C( 32267), -INT16_C( 22199), -INT16_C( 21895),  INT16_C( 28189),
         INT16_C( 29522),  INT16_C( 16981),  INT16_C( 17289), -INT16_C( 22591),  INT16_C(  4396),  INT16_C( 19221), -INT16_C( 25854),  INT16_C( 12017) },
      UINT32_C(4202491775) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i a = simde_mm512_loadu_epi16(test_vec[i].a);
    simde__m512i b = simde_mm512_loadu_epi16(test_vec[i].b);
    simde__mmask32 r = simde_mm512_cmpge_epi16_mask(a, b);
    simde_assert_equal_mmask32(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    int16_t a_[32];
    int16_t b_[32];

    simde_test_codegen_random_memory(sizeof(a_), HEDLEY_REINTERPRET_CAST(uint8_t*, a_));
    simde_test_codegen_random_memory(sizeof(b_), HEDLEY_REINTERPRET_CAST(uint8_t*, b_));
    for (size_t j = 0 ; j < (sizeof(a_) / sizeof(a_[0])) ; j++)
      if ((simde_test_codegen_rand() & 3) == 0)
        b_[j] = a_[j];

    simde__m512i a = simde_mm512_loadu_epi16(a_);
    simde__m512i b = simde_mm512_loadu_epi16(b_);
    simde__mmask32 r = simde_mm512_cmpge_epi16_mask(a, b);

    simde_test_x86_write_i16x32(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i16x32(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_mask_cmpge_epi16_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask32 k;
    const int16_t a[32];
    const int16_t b[32];
    const simde__mmask32 r;
  } test_vec[] = {
    { UINT32_C(3894966127),
      { -INT16_C(  7594), -INT16_C(  9043), -INT16_C( 30349), -INT16_C(  1394),  INT16_C( 29044), -INT16_C(  7776), -INT16_C( 29802),  INT16_C( 21919),
        -INT16_C( 10551),  INT16_C(  9064),  INT16_C(  8096), -INT16_C(   852),  INT16_C( 32334), -INT16_C( 22370), -INT16_C( 23174), -INT16_C( 12232),
        -INT16_C(  6520), -INT16_C(  1107),  INT16_C( 15215), -INT16_C(  7178), -INT16_C( 26964),  INT16_C( 17093),  INT16_C( 25633), -INT16_C(  5224),
         INT16_C(    58), -INT16_C(  9458), -INT16_C( 17889),  INT16_C( 28119),  INT16_C( 30008), -INT16_C( 19946),  INT16_C( 19995), -INT16_C( 23678) },
      { -INT16_C(  7594), -INT16_C( 23394), -INT16_C( 27541), -INT16_C(  1394),  INT16_C( 19499),  INT16_C( 19546), -INT16_C(  3408),  INT16_C( 21919),
         INT16_C( 17906),  INT16_C(  4550),  INT16_C(  8096),  INT16_C( 14206), -INT16_C( 27629),  INT16_C( 12009),  INT16_C( 27875),  INT16_C(  6097),
        -INT16_C(  6520), -INT16_C(  1107),  INT16_C( 17156),  INT16_C( 12062),  INT16_C( 30863),  INT16_C( 16507),  INT16_C( 25633),  INT16_C( 23595),
        -INT16_C(  3592), -INT16_C(  9458), -INT16_C(  5234), -INT16_C( 24273),  INT16_C( 30008),  INT16_C( 25551),  INT16_C( 19995), -INT16_C( 23678) },
      UINT32_C(3357545995) },
    { UINT32_C( 734765565),
      {  INT16_C( 27580),  INT16_C( 31216),  INT16_C( 14634), -INT16_C( 25696),  INT16_C(  9132),  INT16_C(  4357),  INT16_C( 26387), -INT16_C(  4604),
        -INT16_C( 26375), -INT16_C( 23734),  INT16_C(  2300),  INT16_C(   467),  INT16_C(  9025), -INT16_C( 20459),  INT16_C( 16026),  INT16_C( 22168),
        -INT16_C( 30295), -INT16_C( 11313),  INT16_C( 28610),  INT16_C( 28271),  INT16_C( 29842), -INT16_C( 23169), -INT16_C( 31780), -INT16_C( 10861),
        -INT16_C(  8932),  INT16_C(  6264),  INT16_C( 19430),  INT16_C( 10009),  INT16_C( 12142),  INT16_C(  2264),  INT16_C( 28781),  INT16_C(  5726) },
      {  INT16_C( 11769),  INT16_C( 31216),  INT16_C( 22940), -INT16_C( 25696), -INT16_C( 22067), -INT16_C( 22061),  INT16_C( 26413), -INT16_C(  4604),
        -INT16_C(  2236),  INT16_C( 10849),  INT16_C(  2300), -INT16_C( 20142),  INT16_C( 10922),  INT16_C(  6073),  INT16_C( 16026),  INT16_C( 22168),
        -INT16_C( 30295), -INT16_C(  7601),  INT16_C( 28610),  INT16_C( 15888), -INT16_C(  7133), -INT16_C( 23169),  INT16_C( 26187), -INT16_C( 10861),
        -INT16_C(  1443), -INT16_C( 24646),  INT16_C(  3189),  INT16_C( 10009),  INT16_C(  2614), -INT16_C( 12234),  INT16_C( 28781),  INT16_C( 26468) },
      UINT32_C( 713654457) },
    { UINT32_C(2655822161),
      { -INT16_C(  2565),  INT16_C( 14715),  INT16_C(  7174),  INT16_C( 32450), -INT16_C(  9387), -INT16_C( 30382), -INT16_C( 14675), -INT16_C( 29645),
        -INT16_C(   885),  INT16_C( 22944), -INT16_C( 31237),  INT16_C( 24394), -INT16_C( 23857), -INT16_C( 13250),  INT16_C(  2371),  INT16_C( 16375),
         INT16_C( 29694),  INT16_C(  1144),  INT16_C( 15247), -INT16_C(  7038), -INT16_C( 10986), -INT16_C( 15506), -INT16_C( 24165),  INT16_C(  9807),
        -INT16_C(  3939), -INT16_C( 26496), -INT16_C( 13707),  INT16_C( 17655),  INT16_C( 13676), -INT16_C( 20719),  INT16_C(  2110),  INT16_C( 15598) },
      {  INT16_C( 26491),  INT16_C(  2625), -INT16_C( 15454), -INT16_C( 18193),  INT16_C( 23960),  INT16_C( 13435), -INT16_C( 14675), -INT16_C( 25766),
        -INT16_C(   885),  INT16_C( 22944), -INT16_C( 31237),  INT16_C(  4213), -INT16_C( 31136), -INT16_C( 24640), -INT16_C( 20850),  INT16_C(  2779),
         INT16_C(  7189), -INT16_C( 18668),  INT16_C(   992),  INT16_C( 30831), -INT16_C(  5280),  INT16_C( 24236),  INT16_C(  1974),  INT16_C(  9807),
        -INT16_C(  3939), -INT16_C( 31071),  INT16_C(  5720), -INT16_C( 18282),  INT16_C( 22172), -INT16_C( 20719),  INT16_C( 13061),  INT16_C(  6709) },
      UINT32_C(2315559232) },
    { UINT32_C(3788273363),
      { -INT16_C(  2845),  INT16_C(  3916),  INT16_C( 22601), -INT16_C( 23310),  INT16_C( 17757), -INT16_C( 28447), -INT16_C( 23494),  INT16_C( 17946),
         INT16_C( 24062), -INT16_C( 20754), -INT16_C( 15880), -INT16_C( 15005),  INT16_C( 13001),  INT16_C(  6882),  INT16_C( 12244), -INT16_C( 18503),
         INT16_C(  1315),  INT16_C( 27846), -INT16_C( 18339), -INT16_C( 17903), -INT16_C(  3330),  INT16_C( 14410),  INT16_C( 26007), -INT16_C( 27266),
         INT16_C( 27842), -INT16_C( 17853), -INT16_C( 22995), -INT16_C(  2432),  INT16_C( 25304), -INT16_C( 21487), -INT16_C( 13679), -INT16_C( 19101) },
      { -INT16_C(  2845),  INT16_C( 11297),  INT16_C( 13026), -INT16_C( 23310),  INT16_C( 12581), -INT16_C( 17383), -INT16_C( 26730),  INT16_C( 22609),
        -INT16_C( 27644),  INT16_C( 12563), -INT16_C( 27846),  INT16_C(  4648),  INT16_C( 13001), -INT16_C( 30785),  INT16_C(  8707), -INT16_C( 11716),
         INT16_C( 23884),  INT16_C( 12286), -INT16_C(  7024), -INT16_C( 17903),  INT16_C( 10261),  INT16_C( 14410), -INT16_C( 15680), -INT16_C( 15356),
         INT16_C(  5974), -INT16_C( 28427),  INT16_C(  7594), -INT16_C( 24670),  INT16_C( 25304),  INT16_C( 22822),  INT16_C( 25220), -INT16_C( 19101) },
      UINT32_C(2169009233) },
    { UINT32_C(1936510759),
      { -INT16_C( 11899), -INT16_C( 17403), -INT16_C( 11193),  INT16_C( 32692),  INT16_C( 28583), -INT16_C( 28403),  INT16_C( 11040), -INT16_C(  4315),
         INT16_C( 22764),  INT16_C(  3604), -INT16_C( 27982),  INT16_C( 28596),  INT16_C( 10812),  INT16_C(  4331), -INT16_C( 18272),  INT16_C(  9713),
        -INT16_C(  2423), -INT16_C( 11806), -INT16_C( 26934),  INT16_C( 29008),  INT16_C( 24069),  INT16_C(  9730),  INT16_C( 10121),  INT16_C( 29973),
         INT16_C( 10624),  INT16_C( 12931),  INT16_C( 14267), -INT16_C(  1887), -INT16_C( 29342),  INT16_C(   520), -INT16_C(  1723), -INT16_C( 12760) },
      {  INT16_C(  2800), -INT16_C( 17761), -INT16_C(  3936), -INT16_C( 23252),  INT16_C( 11854), -INT16_C( 10293), -INT16_C(  8106), -INT16_C( 10675),
         INT16_C( 22764), -INT16_C( 15096), -INT16_C( 27982),  INT16_C( 28596), -INT16_C( 15049),  INT16_C(  4331), -INT16_C( 27458),  INT16_C(  9713),
        -INT16_C(  2423), -INT16_C( 11806), -INT16_C( 27174),  INT16_C( 10468),  INT16_C( 24069),  INT16_C(  9730),  INT16_C( 19600),  INT16_C( 29973),
         INT16_C( 10624),  INT16_C( 12931),  INT16_C(  7074), -INT16_C(  1887), -INT16_C(  1056), -INT16_C( 24747), -INT16_C( 24688),  INT16_C( 11853) },
      UINT32_C(1663880962) },
    { UINT32_C(2406932820),
      { -INT16_C(  2016),  INT16_C(  8578), -INT16_C( 21885),  INT16_C( 23217), -INT16_C(  9278), -INT16_C( 11697),  INT16_C( 26724),  INT16_C(  2180),
         INT16_C(  3857), -INT16_C( 19060), -INT16_C( 20241),  INT16_C( 28649),  INT16_C( 19233),  INT16_C( 18552), -INT16_C(  7141),  INT16_C( 15291),
         INT16_C( 15836),  INT16_C( 24412),  INT16_C(  3816), -INT16_C( 21830),  INT16_C(  2537),  INT16_C( 19837),  INT16_C(   369), -INT16_C( 32171),
        -INT16_C(  7663),  INT16_C(    55),  INT16_C(  8338), -INT16_C( 19601), -INT16_C(  6292), -INT16_C( 30725), -INT16_C( 18484), -INT16_C( 22334) },
      {  INT16_C(  8180),  INT16_C(  8578), -INT16_C( 15827),  INT16_C(  5767),  INT16_C(  1227),  INT16_C( 15460), -INT16_C( 18171),  INT16_C(  5823),
         INT16_C(  3857),  INT16_C( 11543), -INT16_C( 31209),  INT16_C( 28649),  INT16_C( 19233),  INT16_C( 14858), -INT16_C(  7141), -INT16_C( 30750),
         INT16_C( 15836),  INT16_C(  6244), -INT16_C(  5204), -INT16_C( 21830),  INT16_C(  2537), -INT16_C(  2892),  INT16_C( 29516), -INT16_C(  6133),
         INT16_C(  8809), -INT16_C( 32747), -INT16_C(  2392),  INT16_C(  5635),  INT16_C(  3538),  INT16_C( 25936),  INT16_C( 13274), -INT16_C( 22334) },
      UINT32_C(2251743552) },
    { UINT32_C( 271519147),
      { -INT16_C( 18450), -INT16_C( 28998), -INT16_C(  9811),  INT16_C(  5498),  INT16_C( 20227),  INT16_C( 20455),  INT16_C( 14905),  INT16_C(  6467),
         INT16_C( 20112), -INT16_C(  3125), -INT16_C(  7510),  INT16_C( 14385),  INT16_C( 13541),  INT16_C( 14820),  INT16_C( 23061),  INT16_C(   969),
        -INT16_C( 31982), -INT16_C( 16495),  INT16_C(  2908),  INT16_C( 24532), -INT16_C( 17318), -INT16_C( 27730), -INT16_C(  3594), -INT16_C( 31060),
         INT16_C( 30528), -INT16_C(  5511), -INT16_C( 21927),  INT16_C( 16162),  INT16_C(  2014), -INT16_C(  3208),  INT16_C( 16737),  INT16_C( 29686) },
      { -INT16_C( 18450),  INT16_C(  8242),  INT16_C(  1939), -INT16_C(  4737),  INT16_C( 11715), -INT16_C( 18047),  INT16_C( 11551),  INT16_C( 24383),
        -INT16_C( 18267), -INT16_C(   439),  INT16_C( 27491),  INT16_C( 14385), -INT16_C( 18830), -INT16_C( 11211),  INT16_C( 11255), -INT16_C( 17337),
         INT16_C( 31411),  INT16_C( 18140),  INT16_C( 23681),  INT16_C( 17459), -INT16_C( 17318), -INT16_C( 22275),  INT16_C( 15586), -INT16_C( 30969),
         INT16_C( 20724), -INT16_C(  5511), -INT16_C( 15428),  INT16_C( 11929), -INT16_C( 12679),  INT16_C( 28674),  INT16_C( 19193), -INT16_C( 21460) },
      UINT32_C( 268962089) },
    { UINT32_C(3001661619),
      { -INT16_C( 18381),  INT16_C(  3838), -INT16_C( 27330),  INT16_C(   202),  INT16_C(  3636),  INT16_C(  9142), -INT16_C( 15145),  INT16_C( 25550),
        -INT16_C( 22677), -INT16_C(  8088), -INT16_C(  8829), -INT16_C( 22193),  INT16_C( 27263),  INT16_C( 10899), -INT16_C( 15753), -INT16_C( 21702),
         INT16_C( 14714), -INT16_C( 18247), -INT16_C( 31794),  INT16_C(   696),  INT16_C( 28561),  INT16_C( 26661), -INT16_C(  3277), -INT16_C( 24629),
         INT16_C( 13211),  INT16_C(  7807), -INT16_C( 12783), -INT16_C( 28472),  INT16_C( 23352), -INT16_C( 20293), -INT16_C(  2786), -INT16_C( 26533) },
      { -INT16_C( 18381), -INT16_C(   687),  INT16_C(  2455),  INT16_C( 10751),  INT16_C(  9592), -INT16_C( 21359),  INT16_C( 23832), -INT16_C( 19637),
        -INT16_C( 13680), -INT16_C( 24110), -INT16_C( 25959), -INT16_C( 22193), -INT16_C(  4619),  INT16_C(  4993), -INT16_C( 15753),  INT16_C(  4524),
         INT16_C( 14714), -INT16_C( 30706),  INT16_C(  3334),  INT16_C( 32689),  INT16_C( 16946),  INT16_C( 26661),  INT16_C( 30367),  INT16_C( 12542),
         INT16_C( 13211), -INT16_C(  9775),  INT16_C(   874),  INT16_C( 24747),  INT16_C( 11504), -INT16_C( 11405),  INT16_C(  7945), -INT16_C(  1564) },
      UINT32_C( 304167075) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__mmask32 k = test_vec[i].k;
    simde__m512i a = simde_mm512_loadu_epi16(test_vec[i].a);
    simde__m512i b = simde_mm512_loadu_epi16(test_vec[i].b);
    simde__mmask32 r = simde_mm512_mask_cmpge_epi16_mask(k, a, b);
    simde_assert_equal_mmask32(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    int16_t a_[32];
    int16_t b_[32];

    simde_test_codegen_random_memory(sizeof(a_), HEDLEY_REINTERPRET_CAST(uint8_t*, a_));
    simde_test_codegen_random_memory(sizeof(b_), HEDLEY_REINTERPRET_CAST(uint8_t*, b_));
    for (size_t j = 0 ; j < (sizeof(a_) / sizeof(a_[0])) ; j++)
      if ((simde_test_codegen_rand() & 3) == 0)
        b_[j] = a_[j];

    simde__mmask32 k = simde_test_x86_random_mmask32();
    simde__m512i a = simde_mm512_loadu_epi16(a_);
    simde__m512i b = simde_mm512_loadu_epi16(b_);
    simde__mmask32 r = simde_mm512_mask_cmpge_epi16_mask(k, a, b);

    simde_test_x86_write_mmask32(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i16x32(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x32(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_x_mm_cmpge_epu16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const uint16_t a[8];
    const uint16_t b[8];
    const uint16_t r[8];
  } test_vec[] = {
    { { UINT16_C(35819), UINT16_C(24804), UINT16_C(24920), UINT16_C(39796), UINT16_C(47581), UINT16_C(10526), UINT16_C(31695), UINT16_C(59615) },
      { UINT16_C(55907), UINT16_C(47920), UINT16_C(24920), UINT16_C( 6486), UINT16_C(30045), UINT16_C(11330), UINT16_C(31695), UINT16_C(29717) },
      { UINT16_C(    0), UINT16_C(    0),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX } },
    { { UINT16_C( 1150), UINT16_C(21987), UINT16_C(42021), UINT16_C(29628), UINT16_C(26452), UINT16_C(56742), UINT16_C(43272), UINT16_C(33994) },
      { UINT16_C( 1150), UINT16_C(18836), UINT16_C(20517), UINT16_C(31165), UINT16_C(25528), UINT16_C(49239), UINT16_C( 8461), UINT16_C(59716) },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(    0) } },
    { { UINT16_C(29170), UINT16_C(32457), UINT16_C(45304), UINT16_C(51497), UINT16_C( 9952), UINT16_C(12123), UINT16_C(11457), UINT16_C(56739) },
      { UINT16_C(29170), UINT16_C(57285), UINT16_C(61019), UINT16_C(51497), UINT16_C( 9952), UINT16_C(54635), UINT16_C( 3631), UINT16_C(49330) },
      {      UINT16_MAX, UINT16_C(    0), UINT16_C(    0),      UINT16_MAX,      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX } },
    { { UINT16_C(33113), UINT16_C(  514), UINT16_C(  572), UINT16_C(55701), UINT16_C(17827), UINT16_C(48075), UINT16_C(  982), UINT16_C( 5050) },
      { UINT16_C(50784), UINT16_C(40106), UINT16_C(16584), UINT16_C(27766), UINT16_C(16773), UINT16_C(48075), UINT16_C(57668), UINT16_C(18030) },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(    0), UINT16_C(    0) } },
    { { UINT16_C(63282), UINT16_C(51768), UINT16_C(31514), UINT16_C(  799), UINT16_C(32034), UINT16_C(42810), UINT16_C( 6560), UINT16_C(35213) },
      { UINT16_C(39288), UINT16_C(37753), UINT16_C(38932), UINT16_C(13974), UINT16_C(53269), UINT16_C(42810), UINT16_C(27369), UINT16_C(35646) },
      {      UINT16_MAX,      UINT16_MAX, UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),      UINT16_MAX, UINT16_C(    0), UINT16_C(    0) } },
    { { UINT16_C(56534), UINT16_C(42933), UINT16_C(30350), UINT16_C(42260), UINT16_C(17652), UINT16_C(62264), UINT16_C(31700), UINT16_C(65130) },
      { UINT16_C(42657), UINT16_C(12267), UINT16_C(   28), UINT16_C( 4308), UINT16_C( 3396), UINT16_C( 6147), UINT16_C(28040), UINT16_C(48662) },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX } },
    { { UINT16_C(25520), UINT16_C(45514), UINT16_C(18590), UINT16_C(60338), UINT16_C(28581), UINT16_C(51111), UINT16_C(42780), UINT16_C(28554) },
      { UINT16_C(27377), UINT16_C(37046), UINT16_C(26802), UINT16_C(60338), UINT16_C(28581), UINT16_C(62239), UINT16_C(42780), UINT16_C(23650) },
      { UINT16_C(    0),      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX } },
    { { UINT16_C(42082), UINT16_C(65468), UINT16_C(16172), UINT16_C(43388), UINT16_C(50998), UINT16_C(47994), UINT16_C(20402), UINT16_C( 2098) },
      { UINT16_C(10302), UINT16_C(27356), UINT16_C(16172), UINT16_C(40211), UINT16_C(50998), UINT16_C(47994), UINT16_C(20402), UINT16_C(47322) },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(    0) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_x_mm_loadu_epi16(test_vec[i].a);
    simde__m128i b = simde_x_mm_loadu_epi16(test_vec[i].b);
    simde__m128i r = simde_x_mm_cmpge_epu16(a, b);
    simde_test_x86_assert_equal_u16x8(r, simde_x_mm_loadu_epi16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    uint16_t a_[8];
    uint16_t b_[8];

    simde_test_codegen_random_memory(sizeof(a_), HEDLEY_REINTERPRET_CAST(uint8_t*, a_));
    simde_test_codegen_random_memory(sizeof(b_), HEDLEY_REINTERPRET_CAST(uint8_t*, b_));
    for (size_t j = 0 ; j < (sizeof(a_) / sizeof(a_[0])) ; j++)
      if ((simde_test_codegen_rand() & 3) == 0)
        b_[j] = a_[j];

    simde__m128i a = simde_mm_loadu_epi16(a_);
    simde__m128i b = simde_mm_loadu_epi16(b_);
    simde__m128i r = simde_x_mm_cmpge_epu16(a, b);

    simde_test_x86_write_u16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_u16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_u16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_cmpge_epu16_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const uint16_t a[8];
    const uint16_t b[8];
    const simde__mmask8 r;
  } test_vec[] = {
    { { UINT16_C(45503), UINT16_C( 7214), UINT16_C( 4307), UINT16_C(20075), UINT16_C(54722), UINT16_C( 3396), UINT16_C( 6059), UINT16_C(43671) },
      { UINT16_C(13944), UINT16_C( 7214), UINT16_C( 2631), UINT16_C( 2457), UINT16_C(56799), UINT16_C(35606), UINT16_C(44788), UINT16_C(47669) },
      UINT8_C( 15) },
    { { UINT16_C(51781), UINT16_C(41347), UINT16_C(31305), UINT16_C(47214), UINT16_C(38414), UINT16_C(26858), UINT16_C(40902), UINT16_C(11578) },
      { UINT16_C( 4403), UINT16_C(31808), UINT16_C(44683), UINT16_C(39220), UINT16_C( 7749), UINT16_C( 2817), UINT16_C(15293), UINT16_C(45368) },
      UINT8_C(123) },
    { { UINT16_C(17266), UINT16_C( 5646), UINT16_C(19928), UINT16_C(50968), UINT16_C(62388), UINT16_C(33551), UINT16_C(63324), UINT16_C(54917) },
      { UINT16_C(29594), UINT16_C(29213), UINT16_C(13761), UINT16_C(50968), UINT16_C(18728), UINT16_C(34040), UINT16_C(32064), UINT16_C(24154) },
      UINT8_C(220) },
    { { UINT16_C(44738), UINT16_C(29437), UINT16_C(48144), UINT16_C(43325), UINT16_C(65426), UINT16_C(49110), UINT16_C( 2854), UINT16_C(49543) },
      { UINT16_C(49654), UINT16_C( 1924), UINT16_C(49534), UINT16_C( 4272), UINT16_C(34496), UINT16_C(59344), UINT16_C(22417), UINT16_C(49543) },
      UINT8_C(154) },
    { { UINT16_C(63717), UINT16_C(39433), UINT16_C(18010), UINT16_C(33030), UINT16_C(28529), UINT16_C(58872), UINT16_C(33181), UINT16_C(35919) },
      { UINT16_C(12000), UINT16_C(15109), UINT16_C( 2932), UINT16_C(59068), UINT16_C(46202), UINT16_C( 6091), UINT16_C( 6709), UINT16_C(35919) },
      UINT8_C(231) },
    { { UINT16_C(38731), UINT16_C(24167), UINT16_C(43690), UINT16_C( 9013), UINT16_C(30127), UINT16_C(40226), UINT16_C(35801), UINT16_C(27755) },
      { UINT16_C(38731), UINT16_C( 5836), UINT16_C(43690), UINT16_C(22329), UINT16_C(30127), UINT16_C(20724), UINT16_C(24551), UINT16_C(57788) },
      UINT8_C(119) },
    { { UINT16_C( 9533), UINT16_C(52308), UINT16_C( 4833), UINT16_C( 4211), UINT16_C( 1073), UINT16_C( 9057), UINT16_C( 8235), UINT16_C(20353) },
      { UINT16_C(26258), UINT16_C(29860), UINT16_C( 6009), UINT16_C(43652), UINT16_C( 1073), UINT16_C(18381), UINT16_C( 8235), UINT16_C(20353) },
      UINT8_C(210) },
    { { UINT16_C(43909), UINT16_C(29937), UINT16_C(33995), UINT16_C(30392), UINT16_C(50612), UINT16_C(20668), UINT16_C(55780), UINT16_C(27007) },
      { UINT16_C(18138), UINT16_C(42351), UINT16_C(10186), UINT16_C(32283), UINT16_C(55276), UINT16_C(53455), UINT16_C(55780), UINT16_C(19002) },
      UINT8_C(197) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_x_mm_loadu_epi16(test_vec[i].a);
    simde__m128i b = simde_x_mm_loadu_epi16(test_vec[i].b);
    simde__mmask8 r = simde_mm_cmpge_epu16_mask(a, b);
    simde_assert_equal_mmask8(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    uint16_t a_[8];
    uint16_t b_[8];

    simde_test_codegen_random_memory(sizeof(a_), HEDLEY_REINTERPRET_CAST(uint8_t*, a_));
    simde_test_codegen_random_memory(sizeof(b_), HEDLEY_REINTERPRET_CAST(uint8_t*, b_));
    for (size_t j = 0 ; j < (sizeof(a_) / sizeof(a_[0])) ; j++)
      if ((simde_test_codegen_rand() & 3) == 0)
        b_[j] = a_[j];

    simde__m128i a = simde_mm_loadu_epi16(a_);
    simde__m128i b = simde_mm_loadu_epi16(b_);
    simde__mmask8 r = simde_mm_cmpge_epu16_mask(a, b);

    simde_test_x86_write_u16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_u16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_mask_cmpge_epu16_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k;
    const uint16_t a[8];
    const uint16_t b[8];
    const simde__mmask8 r;
  } test_vec[] = {
    { UINT8_C( 92),
      { UINT16_C(54888), UINT16_C( 6834), UINT16_C(50426), UINT16_C(49491), UINT16_C(55362), UINT16_C(61182), UINT16_C(14001), UINT16_C(53621) },
      { UINT16_C(35525), UINT16_C( 6834), UINT16_C(36942), UINT16_C(36993), UINT16_C(55362), UINT16_C( 6783), UINT16_C(62646), UINT16_C(38123) },
      UINT8_C( 28) },
    { UINT8_C(100),
      { UINT16_C(51797), UINT16_C(65317), UINT16_C(19020), UINT16_C(41885), UINT16_C(62799), UINT16_C(11752), UINT16_C(62320), UINT16_C(10388) },
      { UINT16_C( 9256), UINT16_C(29884), UINT16_C(22894), UINT16_C(41885), UINT16_C(65358), UINT16_C(49131), UINT16_C(32754), UINT16_C(45031) },
      UINT8_C( 64) },
    { UINT8_C(  9),
      { UINT16_C(59947), UINT16_C(46558), UINT16_C(18075), UINT16_C(23954), UINT16_C(55120), UINT16_C(23164), UINT16_C(50392), UINT16_C(38536) },
      { UINT16_C(33538), UINT16_C(40509), UINT16_C(53449), UINT16_C(23954), UINT16_C(30631), UINT16_C(32628), UINT16_C(64571), UINT16_C(47893) },
      UINT8_C(  9) },
    { UINT8_C(137),
      { UINT16_C(34332), UINT16_C(19933), UINT16_C(59114), UINT16_C(55143), UINT16_C(56624), UINT16_C( 8157), UINT16_C(59099), UINT16_C( 5777) },
      { UINT16_C(13344), UINT16_C( 2581), UINT16_C(31770), UINT16_C(55143), UINT16_C(48985), UINT16_C(13417), UINT16_C(64421), UINT16_C(12618) },
      UINT8_C(  9) },
    { UINT8_C( 31),
      { UINT16_C(40743), UINT16_C(52938), UINT16_C( 4729), UINT16_C( 1552), UINT16_C(64935), UINT16_C(37933), UINT16_C(29873), UINT16_C(31670) },
      { UINT16_C(40743), UINT16_C( 7997), UINT16_C(19892), UINT16_C(23589), UINT16_C(64935), UINT16_C(64496), UINT16_C(42694), UINT16_C(35702) },
      UINT8_C( 19) },
    { UINT8_C( 88),
      { UINT16_C(57831), UINT16_C(21429), UINT16_C(31835), UINT16_C(10302), UINT16_C(29074), UINT16_C(33020), UINT16_C(30227), UINT16_C(61969) },
      { UINT16_C(57831), UINT16_C(52568), UINT16_C(38718), UINT16_C(53749), UINT16_C(29074), UINT16_C( 7249), UINT16_C(30227), UINT16_C(30734) },
      UINT8_C( 80) },
    { UINT8_C(139),
      { UINT16_C(45273), UINT16_C( 1050), UINT16_C(57832), UINT16_C(57577), UINT16_C(60567), UINT16_C(22890), UINT16_C(26357), UINT16_C(22494) },
      { UINT16_C( 2835), UINT16_C( 1050), UINT16_C( 4077), UINT16_C(57577), UINT16_C(17915), UINT16_C(61917), UINT16_C(26357), UINT16_C(56136) },
      UINT8_C( 11) },
    { UINT8_C(207),
      { UINT16_C(58352), UINT16_C(22899), UINT16_C(51599), UINT16_C(40569), UINT16_C(57783), UINT16_C(38671), UINT16_C(37996), UINT16_C( 7299) },
      { UINT16_C(58352), UINT16_C(44235), UINT16_C(17663), UINT16_C(46666), UINT16_C(23078), UINT16_C(37454), UINT16_C(53742), UINT16_C( 7299) },
      UINT8_C(133) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__mmask8 k = test_vec[i].k;
    simde__m128i a = simde_x_mm_loadu_epi16(test_vec[i].a);
    simde__m128i b = simde_x_mm_loadu_epi16(test_vec[i].b);
    simde__mmask8 r = simde_mm_mask_cmpge_epu16_mask(k, a, b);
    simde_assert_equal_mmask8(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    uint16_t a_[8];
    uint16_t b_[8];

    simde_test_codegen_random_memory(sizeof(a_), HEDLEY_REINTERPRET_CAST(uint8_t*, a_));
    simde_test_codegen_random_memory(sizeof(b_), HEDLEY_REINTERPRET_CAST(uint8_t*, b_));
    for (size_t j = 0 ; j < (sizeof(a_) / sizeof(a_[0])) ; j++)
      if ((simde_test_codegen_rand() & 3) == 0)
        b_[j] = a_[j];

    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m128i a = simde_mm_loadu_epi16(a_);
    simde__m128i b = simde_mm_loadu_epi16(b_);
    simde__mmask8 r = simde_mm_mask_cmpge_epu16_mask(k, a, b);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_u16x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_u16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_x_mm256_cmpge_epu16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const uint16_t a[16];
    const uint16_t b[16];
    const uint16_t r[16];
  } test_vec[] = {
    { { UINT16_C(38869), UINT16_C(43294), UINT16_C(55813), UINT16_C(16443), UINT16_C(58804), UINT16_C(63222), UINT16_C( 1286), UINT16_C(27505),
        UINT16_C(38409), UINT16_C(14835), UINT16_C(44529), UINT16_C( 6932), UINT16_C( 8031), UINT16_C(41991), UINT16_C(21762), UINT16_C(55216) },
      { UINT16_C(38869), UINT16_C(62081), UINT16_C(48296), UINT16_C(16443), UINT16_C(10657), UINT16_C(42834), UINT16_C( 1286), UINT16_C(27505),
        UINT16_C( 1370), UINT16_C(19312), UINT16_C(33970), UINT16_C( 6932), UINT16_C(28324), UINT16_C(42678), UINT16_C(21762), UINT16_C(55216) },
      {      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,
             UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX, UINT16_C(    0), UINT16_C(    0),      UINT16_MAX,      UINT16_MAX } },
    { { UINT16_C(54298), UINT16_C(52467), UINT16_C(23129), UINT16_C(64990), UINT16_C(38088), UINT16_C(36003), UINT16_C( 8698), UINT16_C(11836),
        UINT16_C(57120), UINT16_C(56074), UINT16_C(17076), UINT16_C(45623), UINT16_C(15052), UINT16_C( 6878), UINT16_C(16975), UINT16_C(27074) },
      { UINT16_C(46615), UINT16_C(28726), UINT16_C( 5136), UINT16_C(64990), UINT16_C( 4264), UINT16_C(41573), UINT16_C(41266), UINT16_C(21200),
        UINT16_C(57120), UINT16_C(13358), UINT16_C(25884), UINT16_C(59622), UINT16_C(50592), UINT16_C(61187), UINT16_C(16975), UINT16_C(27074) },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),
             UINT16_MAX,      UINT16_MAX, UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),      UINT16_MAX,      UINT16_MAX } },
    { { UINT16_C(48791), UINT16_C(45856), UINT16_C( 1828), UINT16_C(50331), UINT16_C(40652), UINT16_C(54195), UINT16_C( 3172), UINT16_C(57330),
        UINT16_C(32923), UINT16_C(15979), UINT16_C(53372), UINT16_C(34953), UINT16_C(30362), UINT16_C( 1734), UINT16_C(22067), UINT16_C(51954) },
      { UINT16_C(48791), UINT16_C(14717), UINT16_C( 6425), UINT16_C(58877), UINT16_C(45239), UINT16_C( 7097), UINT16_C(43965), UINT16_C(22779),
        UINT16_C(26155), UINT16_C(15979), UINT16_C( 8247), UINT16_C(34953), UINT16_C(62871), UINT16_C(51927), UINT16_C(51532), UINT16_C(24981) },
      {      UINT16_MAX,      UINT16_MAX, UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,
             UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),      UINT16_MAX } },
    { { UINT16_C(62560), UINT16_C(38674), UINT16_C(16660), UINT16_C(43880), UINT16_C(16439), UINT16_C(33654), UINT16_C( 2825), UINT16_C(58852),
        UINT16_C(32285), UINT16_C(18907), UINT16_C(46613), UINT16_C(23596), UINT16_C(10826), UINT16_C(35169), UINT16_C(48676), UINT16_C(34035) },
      { UINT16_C( 1458), UINT16_C(50715), UINT16_C(16660), UINT16_C(32370), UINT16_C(59587), UINT16_C(52481), UINT16_C( 2825), UINT16_C( 4274),
        UINT16_C(36195), UINT16_C(30809), UINT16_C(34115), UINT16_C(36308), UINT16_C(13744), UINT16_C(54294), UINT16_C( 2803), UINT16_C(42328) },
      {      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX, UINT16_C(    0), UINT16_C(    0),      UINT16_MAX,      UINT16_MAX,
        UINT16_C(    0), UINT16_C(    0),      UINT16_MAX, UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),      UINT16_MAX, UINT16_C(    0) } },
    { { UINT16_C( 9159), UINT16_C( 2709), UINT16_C(27304), UINT16_C(22680), UINT16_C(44703), UINT16_C(37676), UINT16_C(33976), UINT16_C(51256),
        UINT16_C(42231), UINT16_C(60958), UINT16_C(62338), UINT16_C(18600), UINT16_C(12232), UINT16_C(33537), UINT16_C(52072), UINT16_C(12192) },
      { UINT16_C( 9159), UINT16_C(38458), UINT16_C(53920), UINT16_C(22680), UINT16_C(44703), UINT16_C(14802), UINT16_C(33976), UINT16_C(38657),
        UINT16_C( 8111), UINT16_C(12933), UINT16_C(11538), UINT16_C(56186), UINT16_C(31836), UINT16_C(50526), UINT16_C(65095), UINT16_C(13812) },
      {      UINT16_MAX, UINT16_C(    0), UINT16_C(    0),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,
             UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) } },
    { { UINT16_C(37850), UINT16_C(60883), UINT16_C(19904), UINT16_C( 7624), UINT16_C( 9929), UINT16_C( 4322), UINT16_C(54820), UINT16_C(22853),
        UINT16_C( 4357), UINT16_C( 1325), UINT16_C(16843), UINT16_C(41350), UINT16_C(16424), UINT16_C( 6423), UINT16_C( 9723), UINT16_C(54970) },
      { UINT16_C(36280), UINT16_C(60883), UINT16_C(35803), UINT16_C(42133), UINT16_C(30641), UINT16_C(54709), UINT16_C(64078), UINT16_C(22853),
        UINT16_C(23563), UINT16_C(55128), UINT16_C(57245), UINT16_C(41350), UINT16_C(36895), UINT16_C( 6423), UINT16_C(39349), UINT16_C(28145) },
      {      UINT16_MAX,      UINT16_MAX, UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),      UINT16_MAX,
        UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),      UINT16_MAX, UINT16_C(    0),      UINT16_MAX, UINT16_C(    0),      UINT16_MAX } },
    { { UINT16_C(60496), UINT16_C(60728), UINT16_C(45515), UINT16_C(60083), UINT16_C(37441), UINT16_C(62981), UINT16_C(63019), UINT16_C(21091),
        UINT16_C(18602), UINT16_C(59732), UINT16_C(64451), UINT16_C(46809), UINT16_C(40790), UINT16_C(44278), UINT16_C(35475), UINT16_C(58126) },
      { UINT16_C(18038), UINT16_C(16848), UINT16_C(33783), UINT16_C(14379), UINT16_C(12565), UINT16_C(16686), UINT16_C(37159), UINT16_C(53907),
        UINT16_C(59610), UINT16_C(40379), UINT16_C(64451), UINT16_C(14675), UINT16_C(18996), UINT16_C(44278), UINT16_C(62676), UINT16_C(58126) },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(    0),
        UINT16_C(    0),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(    0),      UINT16_MAX } },
    { { UINT16_C(40144), UINT16_C(45986), UINT16_C(62769), UINT16_C(26092), UINT16_C(53823), UINT16_C( 4908), UINT16_C(54982), UINT16_C(  349),
        UINT16_C(59473), UINT16_C(20275), UINT16_C(40351), UINT16_C(34402), UINT16_C(46902), UINT16_C(24981), UINT16_C(30367), UINT16_C(28517) },
      { UINT16_C( 1811), UINT16_C(17442), UINT16_C( 3837), UINT16_C(15530), UINT16_C(55009), UINT16_C(42832), UINT16_C(44461), UINT16_C(65192),
        UINT16_C(56214), UINT16_C(13645), UINT16_C(44921), UINT16_C(34402), UINT16_C(46902), UINT16_C( 1296), UINT16_C(30407), UINT16_C(55924) },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(    0), UINT16_C(    0),      UINT16_MAX, UINT16_C(    0),
             UINT16_MAX,      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(    0), UINT16_C(    0) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256i a = simde_mm256_loadu_epi16(test_vec[i].a);
    simde__m256i b = simde_mm256_loadu_epi16(test_vec[i].b);
    simde__m256i r = simde_x_mm256_cmpge_epu16(a, b);
    simde_test_x86_assert_equal_u16x16(r, simde_mm256_loadu_epi16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    uint16_t a_[16];
    uint16_t b_[16];

    simde_test_codegen_random_memory(sizeof(a_), HEDLEY_REINTERPRET_CAST(uint8_t*, a_));
    simde_test_codegen_random_memory(sizeof(b_), HEDLEY_REINTERPRET_CAST(uint8_t*, b_));
    for (size_t j = 0 ; j < (sizeof(a_) / sizeof(a_[0])) ; j++)
      if ((simde_test_codegen_rand() & 3) == 0)
        b_[j] = a_[j];

    simde__m256i a = simde_mm256_loadu_epi16(a_);
    simde__m256i b = simde_mm256_loadu_epi16(b_);
    simde__m256i r = simde_x_mm256_cmpge_epu16(a, b);

    simde_test_x86_write_u16x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_u16x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_u16x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_cmpge_epu16_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const uint16_t a[16];
    const uint16_t b[16];
    const simde__mmask16 r;
  } test_vec[] = {
    { { UINT16_C(38833), UINT16_C(10879), UINT16_C(15175), UINT16_C(44506), UINT16_C(60044), UINT16_C(21427), UINT16_C(10080), UINT16_C(56878),
        UINT16_C(19902), UINT16_C(25432), UINT16_C( 3862), UINT16_C(46569), UINT16_C( 5654), UINT16_C(51970), UINT16_C(19692), UINT16_C(40469) },
      { UINT16_C(38372), UINT16_C(11208), UINT16_C(41680), UINT16_C(23768), UINT16_C(35725), UINT16_C(21427), UINT16_C(56755), UINT16_C(29131),
        UINT16_C( 9258), UINT16_C(16596), UINT16_C(48435), UINT16_C(19190), UINT16_C( 5654), UINT16_C(49173), UINT16_C(10820), UINT16_C(10334) },
      UINT16_C(64441) },
    { { UINT16_C(44851), UINT16_C(26339), UINT16_C(55660), UINT16_C(16560), UINT16_C(50641), UINT16_C( 5632), UINT16_C(24304), UINT16_C(44862),
        UINT16_C(37508), UINT16_C(19775), UINT16_C(10942), UINT16_C(30115), UINT16_C(59333), UINT16_C(16096), UINT16_C(48118), UINT16_C(10721) },
      { UINT16_C(50283), UINT16_C(26339), UINT16_C(16542), UINT16_C(28439), UINT16_C(50641), UINT16_C(62853), UINT16_C(50293), UINT16_C(64165),
        UINT16_C(58454), UINT16_C( 5191), UINT16_C(60174), UINT16_C(30115), UINT16_C(27090), UINT16_C(16096), UINT16_C(62245), UINT16_C(10721) },
      UINT16_C(47638) },
    { { UINT16_C(19780), UINT16_C(21368), UINT16_C(  568), UINT16_C( 2599), UINT16_C(14699), UINT16_C(37074), UINT16_C(49964), UINT16_C(58144),
        UINT16_C(34884), UINT16_C( 1081), UINT16_C(65031), UINT16_C(40394), UINT16_C(34376), UINT16_C(22441), UINT16_C(45030), UINT16_C(11195) },
      { UINT16_C(13565), UINT16_C(13694), UINT16_C(42294), UINT16_C(41280), UINT16_C( 4830), UINT16_C( 2610), UINT16_C(21206), UINT16_C( 6893),
        UINT16_C( 9946), UINT16_C(57630), UINT16_C(59684), UINT16_C(28031), UINT16_C(10351), UINT16_C(21956), UINT16_C(32728), UINT16_C(54656) },
      UINT16_C(32243) },
    { { UINT16_C(27551), UINT16_C(50379), UINT16_C(19028), UINT16_C(49969), UINT16_C(62835), UINT16_C(19225), UINT16_C(39284), UINT16_C(10272),
        UINT16_C(10904), UINT16_C(15121), UINT16_C(40053), UINT16_C(53949), UINT16_C(18521), UINT16_C(26885), UINT16_C(21185), UINT16_C(24915) },
      { UINT16_C( 7869), UINT16_C(50379), UINT16_C(22121), UINT16_C(56533), UINT16_C(61003), UINT16_C(19225), UINT16_C(18312), UINT16_C( 8423),
        UINT16_C(63857), UINT16_C(58971), UINT16_C( 6293), UINT16_C(61368), UINT16_C(18521), UINT16_C(26885), UINT16_C(43791), UINT16_C(52611) },
      UINT16_C(13555) },
    { { UINT16_C(42729), UINT16_C(32724), UINT16_C(36287), UINT16_C( 8302), UINT16_C(50762), UINT16_C(23106), UINT16_C(50801), UINT16_C(14887),
        UINT16_C( 1646), UINT16_C(28013), UINT16_C(31674), UINT16_C(23990), UINT16_C(49073), UINT16_C(11656), UINT16_C(54192), UINT16_C(39195) },
      { UINT16_C(61562), UINT16_C(14616), UINT16_C(34429), UINT16_C(51033), UINT16_C(39756), UINT16_C(48417), UINT16_C(18529), UINT16_C(14887),
        UINT16_C(25934), UINT16_C(28013), UINT16_C(62432), UINT16_C(37222), UINT16_C(61363), UINT16_C(25535), UINT16_C(56002), UINT16_C(15612) },
      UINT16_C(33494) },
    { { UINT16_C(55298), UINT16_C(58320), UINT16_C(14284), UINT16_C(32628), UINT16_C(13094), UINT16_C(59618), UINT16_C(56846), UINT16_C(55333),
        UINT16_C(39667), UINT16_C(36640), UINT16_C(12137), UINT16_C(54135), UINT16_C( 7263), UINT16_C(55454), UINT16_C(15034), UINT16_C(48288) },
      { UINT16_C(28690), UINT16_C(56991), UINT16_C( 5287), UINT16_C(52573), UINT16_C(16199), UINT16_C(59618), UINT16_C(56094), UINT16_C( 4398),
        UINT16_C(39667), UINT16_C(36640), UINT16_C( 6013), UINT16_C(56497), UINT16_C(20532), UINT16_C(61109), UINT16_C(21898), UINT16_C(40106) },
      UINT16_C(34791) },
    { { UINT16_C(59511), UINT16_C(62495), UINT16_C(53759), UINT16_C(13264), UINT16_C(34081), UINT16_C(43809), UINT16_C(52442), UINT16_C(41031),
        UINT16_C(49686), UINT16_C(29709), UINT16_C(18331), UINT16_C(45849), UINT16_C( 5176), UINT16_C( 1001), UINT16_C(12349), UINT16_C(46148) },
      { UINT16_C(25624), UINT16_C( 6312), UINT16_C(31029), UINT16_C(22091), UINT16_C(34081), UINT16_C(55553), UINT16_C(52442), UINT16_C(20345),
        UINT16_C(34315), UINT16_C(42691), UINT16_C(18331), UINT16_C(45849), UINT16_C(17137), UINT16_C(11785), UINT16_C(19826), UINT16_C(35811) },
      UINT16_C(36311) },
    { { UINT16_C(42715), UINT16_C(43063), UINT16_C(36995), UINT16_C(29870), UINT16_C(47058), UINT16_C(17570), UINT16_C(34052), UINT16_C(46799),
        UINT16_C(29201), UINT16_C( 5532), UINT16_C(55649), UINT16_C(48152), UINT16_C(62486), UINT16_C(40017), UINT16_C(13385), UINT16_C( 9261) },
      { UINT16_C(25819), UINT16_C(43063), UINT16_C(31732), UINT16_C(50898), UINT16_C(29746), UINT16_C(13835), UINT16_C(56058), UINT16_C( 3052),
        UINT16_C(35149), UINT16_C(44576), UINT16_C(55649), UINT16_C(30826), UINT16_C(47917), UINT16_C(40017), UINT16_C(13385), UINT16_C( 9261) },
      UINT16_C(64695) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256i a = simde_mm256_loadu_epi16(test_vec[i].a);
    simde__m256i b = simde_mm256_loadu_epi16(test_vec[i].b);
    simde__mmask16 r = simde_mm256_cmpge_epu16_mask(a, b);
    simde_assert_equal_mmask16(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    uint16_t a_[16];
    uint16_t b_[16];

    simde_test_codegen_random_memory(sizeof(a_), HEDLEY_REINTERPRET_CAST(uint8_t*, a_));
    simde_test_codegen_random_memory(sizeof(b_), HEDLEY_REINTERPRET_CAST(uint8_t*, b_));
    for (size_t j = 0 ; j < (sizeof(a_) / sizeof(a_[0])) ; j++)
      if ((simde_test_codegen_rand() & 3) == 0)
        b_[j] = a_[j];

    simde__m256i a = simde_mm256_loadu_epi16(a_);
    simde__m256i b = simde_mm256_loadu_epi16(b_);
    simde__mmask16 r = simde_mm256_cmpge_epu16_mask(a, b);

    simde_test_x86_write_u16x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_u16x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_mask_cmpge_epu16_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask16 k;
    const uint16_t a[16];
    const uint16_t b[16];
    const simde__mmask16 r;
  } test_vec[] = {
    { UINT16_C(54340),
      { UINT16_C(38337), UINT16_C( 9026), UINT16_C(44494), UINT16_C(64412), UINT16_C(45416), UINT16_C(22642), UINT16_C( 3827), UINT16_C(39459),
        UINT16_C(19574), UINT16_C(23094), UINT16_C(38983), UINT16_C(46959), UINT16_C(47877), UINT16_C(19488), UINT16_C(38388), UINT16_C(46561) },
      { UINT16_C(38337), UINT16_C(63705), UINT16_C(30160), UINT16_C(64412), UINT16_C(26150), UINT16_C( 6545), UINT16_C(46452), UINT16_C(60084),
        UINT16_C(59905), UINT16_C(18756), UINT16_C(46210), UINT16_C(34560), UINT16_C(47877), UINT16_C(25555), UINT16_C(46261), UINT16_C(57113) },
      UINT16_C( 4100) },
    { UINT16_C(23637),
      { UINT16_C(50802), UINT16_C(29320), UINT16_C(63309), UINT16_C( 8595), UINT16_C(18523), UINT16_C(29909), UINT16_C(44328), UINT16_C(65382),
        UINT16_C(52566), UINT16_C(14282), UINT16_C(64346), UINT16_C(  170), UINT16_C(53920), UINT16_C(12379), UINT16_C(40956), UINT16_C(28164) },
      { UINT16_C(35942), UINT16_C(46049), UINT16_C(63309), UINT16_C(57044), UINT16_C(43708), UINT16_C(29909), UINT16_C(44328), UINT16_C(44516),
        UINT16_C(44677), UINT16_C(57317), UINT16_C(36778), UINT16_C(19168), UINT16_C(15202), UINT16_C(24186), UINT16_C(32474), UINT16_C(16588) },
      UINT16_C(21573) },
    { UINT16_C(55458),
      { UINT16_C(65500), UINT16_C(48364), UINT16_C(20041), UINT16_C(50423), UINT16_C(53932), UINT16_C(30786), UINT16_C(19730), UINT16_C( 1574),
        UINT16_C(18395), UINT16_C(18383), UINT16_C(16677), UINT16_C(59398), UINT16_C(32267), UINT16_C(33678), UINT16_C(58235), UINT16_C(22495) },
      { UINT16_C(65500), UINT16_C(11284), UINT16_C( 2841), UINT16_C(50672), UINT16_C(53932), UINT16_C(61502), UINT16_C(25727), UINT16_C(23286),
        UINT16_C(18395), UINT16_C(53666), UINT16_C(43015), UINT16_C( 4793), UINT16_C(18214), UINT16_C(33678), UINT16_C(29995), UINT16_C( 3577) },
      UINT16_C(55298) },
    { UINT16_C(22523),
      { UINT16_C(43326), UINT16_C(63360), UINT16_C(42939), UINT16_C(20798), UINT16_C(26952), UINT16_C(16838), UINT16_C( 1655), UINT16_C(45134),
        UINT16_C(26464), UINT16_C(32986), UINT16_C(13917), UINT16_C(17373), UINT16_C(40721), UINT16_C(18207), UINT16_C(49420), UINT16_C(18975) },
      { UINT16_C(41066), UINT16_C( 9793), UINT16_C(42939), UINT16_C(20798), UINT16_C(15849), UINT16_C(24785), UINT16_C( 8003), UINT16_C(45134),
        UINT16_C(26464), UINT16_C(32986), UINT16_C(13917), UINT16_C(12838), UINT16_C(40721), UINT16_C(18207), UINT16_C(39175), UINT16_C(29430) },
      UINT16_C(22427) },
    { UINT16_C(45527),
      { UINT16_C( 7018), UINT16_C(36953), UINT16_C(63821), UINT16_C(51158), UINT16_C(56998), UINT16_C(40032), UINT16_C(39248), UINT16_C(59604),
        UINT16_C(35609), UINT16_C(10487), UINT16_C(17195), UINT16_C(11017), UINT16_C( 2514), UINT16_C( 1595), UINT16_C(13967), UINT16_C(63837) },
      { UINT16_C(46674), UINT16_C(40842), UINT16_C(24752), UINT16_C(22118), UINT16_C(50750), UINT16_C(36594), UINT16_C(50783), UINT16_C(30838),
        UINT16_C(35609), UINT16_C(31905), UINT16_C(43696), UINT16_C(33703), UINT16_C( 2514), UINT16_C(17033), UINT16_C(13967), UINT16_C(27452) },
      UINT16_C(37268) },
    { UINT16_C(47803),
      { UINT16_C(34858), UINT16_C(53595), UINT16_C( 3595), UINT16_C(38068), UINT16_C(52816), UINT16_C(35962), UINT16_C( 5945), UINT16_C(17490),
        UINT16_C(31076), UINT16_C( 1974), UINT16_C(61150), UINT16_C(53661), UINT16_C(63877), UINT16_C(38203), UINT16_C( 5030), UINT16_C(53318) },
      { UINT16_C(41371), UINT16_C(42658), UINT16_C(22191), UINT16_C(   58), UINT16_C(46116), UINT16_C(24204), UINT16_C(57292), UINT16_C(12450),
        UINT16_C(22616), UINT16_C(13880), UINT16_C(61150), UINT16_C(52231), UINT16_C(63877), UINT16_C(29793), UINT16_C(43094), UINT16_C(53318) },
      UINT16_C(47290) },
    { UINT16_C(25249),
      { UINT16_C(  498), UINT16_C(64143), UINT16_C(24013), UINT16_C(12093), UINT16_C(37841), UINT16_C( 5847), UINT16_C( 8324), UINT16_C( 7165),
        UINT16_C(15129), UINT16_C( 4844), UINT16_C(29085), UINT16_C(23960), UINT16_C(64707), UINT16_C(17855), UINT16_C(31417), UINT16_C(44031) },
      { UINT16_C(36476), UINT16_C(18853), UINT16_C(58091), UINT16_C(48248), UINT16_C(20341), UINT16_C(63955), UINT16_C(53360), UINT16_C(35092),
        UINT16_C(   11), UINT16_C(43164), UINT16_C(29085), UINT16_C(13573), UINT16_C(50480), UINT16_C(17855), UINT16_C(31039), UINT16_C(48021) },
      UINT16_C(24576) },
    { UINT16_C( 7286),
      { UINT16_C( 4870), UINT16_C( 2966), UINT16_C(51016), UINT16_C(49872), UINT16_C( 4272), UINT16_C(17723), UINT16_C(17099), UINT16_C(53376),
        UINT16_C(40244), UINT16_C(57934), UINT16_C( 6959), UINT16_C(47972), UINT16_C(46680), UINT16_C( 7772), UINT16_C(64787), UINT16_C( 6529) },
      { UINT16_C( 5904), UINT16_C(22565), UINT16_C(62942), UINT16_C(49872), UINT16_C(21765), UINT16_C(53716), UINT16_C(21655), UINT16_C(53376),
        UINT16_C(40244), UINT16_C( 8621), UINT16_C( 4362), UINT16_C(25308), UINT16_C(46680), UINT16_C(56193), UINT16_C(  565), UINT16_C(17908) },
      UINT16_C( 7168) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__mmask16 k = test_vec[i].k;
    simde__m256i a = simde_mm256_loadu_epi16(test_vec[i].a);
    simde__m256i b = simde_mm256_loadu_epi16(test_vec[i].b);
    simde__mmask16 r = simde_mm256_mask_cmpge_epu16_mask(k, a, b);
    simde_assert_equal_mmask16(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    uint16_t a_[16];
    uint16_t b_[16];

    simde_test_codegen_random_memory(sizeof(a_), HEDLEY_REINTERPRET_CAST(uint8_t*, a_));
    simde_test_codegen_random_memory(sizeof(b_), HEDLEY_REINTERPRET_CAST(uint8_t*, b_));
    for (size_t j = 0 ; j < (sizeof(a_) / sizeof(a_[0])) ; j++)
      if ((simde_test_codegen_rand() & 3) == 0)
        b_[j] = a_[j];

    simde__mmask16 k = simde_test_x86_random_mmask16();
    simde__m256i a = simde_mm256_loadu_epi16(a_);
    simde__m256i b = simde_mm256_loadu_epi16(b_);
    simde__mmask16 r = simde_mm256_mask_cmpge_epu16_mask(k, a, b);

    simde_test_x86_write_mmask16(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_u16x16(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_u16x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_x_mm512_cmpge_epu16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const uint16_t a[32];
    const uint16_t b[32];
    const uint16_t r[32];
  } test_vec[] = {
    { { UINT16_C(28305), UINT16_C(17936), UINT16_C(27460), UINT16_C(46313), UINT16_C(26932), UINT16_C( 6811), UINT16_C(56971), UINT16_C(56852),
        UINT16_C(34579), UINT16_C(38943), UINT16_C(  315), UINT16_C(27535), UINT16_C( 1191), UINT16_C( 7646), UINT16_C(23711), UINT16_C(12373),
        UINT16_C(26059), UINT16_C( 3958), UINT16_C(24784), UINT16_C( 1220), UINT16_C(24521), UINT16_C(21791), UINT16_C(13117), UINT16_C(20787),
        UINT16_C(21178), UINT16_C(63209), UINT16_C(30803), UINT16_C(64353), UINT16_C(16252), UINT16_C( 6936), UINT16_C(28060), UINT16_C(26443) },
      { UINT16_C(49874), UINT16_C(41590), UINT16_C(14882), UINT16_C(60327), UINT16_C(50842), UINT16_C( 6811), UINT16_C(29689), UINT16_C(56852),
        UINT16_C( 4549), UINT16_C( 6570), UINT16_C(  315), UINT16_C( 1556), UINT16_C(11338), UINT16_C( 7646), UINT16_C(28057), UINT16_C(27469),
        UINT16_C(50223), UINT16_C( 3958), UINT16_C(46334), UINT16_C(38973), UINT16_C(24521), UINT16_C(29808), UINT16_C(39153), UINT16_C(46632),
        UINT16_C(21178), UINT16_C(63209), UINT16_C(30803), UINT16_C(10042), UINT16_C(16252), UINT16_C(43022), UINT16_C(23498), UINT16_C(63763) },
      { UINT16_C(    0), UINT16_C(    0),      UINT16_MAX, UINT16_C(    0), UINT16_C(    0),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,
             UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(    0),      UINT16_MAX, UINT16_C(    0), UINT16_C(    0),
        UINT16_C(    0),      UINT16_MAX, UINT16_C(    0), UINT16_C(    0),      UINT16_MAX, UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),
             UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(    0),      UINT16_MAX, UINT16_C(    0) } },
    { { UINT16_C(16972), UINT16_C( 8809), UINT16_C( 8394), UINT16_C(53362), UINT16_C(13894), UINT16_C( 1478), UINT16_C(29474), UINT16_C(57454),
        UINT16_C( 3056), UINT16_C(20603), UINT16_C(15843), UINT16_C( 6079), UINT16_C(55054), UINT16_C(14869), UINT16_C( 3075), UINT16_C(20357),
        UINT16_C(61263), UINT16_C( 6513), UINT16_C(58127), UINT16_C(21993), UINT16_C(45081), UINT16_C(15195), UINT16_C(51491), UINT16_C( 4891),
        UINT16_C(38613), UINT16_C(47203), UINT16_C( 9172), UINT16_C(58063), UINT16_C(58618), UINT16_C(64796), UINT16_C(41456), UINT16_C(16205) },
      { UINT16_C(48784), UINT16_C( 8809), UINT16_C( 8394), UINT16_C(48117), UINT16_C(20722), UINT16_C( 5879), UINT16_C( 4633), UINT16_C(60969),
        UINT16_C(36265), UINT16_C(32166), UINT16_C(30128), UINT16_C( 6079), UINT16_C(31577), UINT16_C(14869), UINT16_C(62748), UINT16_C(44425),
        UINT16_C(61263), UINT16_C( 6513), UINT16_C(16677), UINT16_C( 5905), UINT16_C( 2193), UINT16_C(15195), UINT16_C(51491), UINT16_C(50073),
        UINT16_C(16612), UINT16_C(37952), UINT16_C(40885), UINT16_C( 3902), UINT16_C(58618), UINT16_C(14169), UINT16_C(58075), UINT16_C(36836) },
      { UINT16_C(    0),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(    0), UINT16_C(    0),      UINT16_MAX, UINT16_C(    0),
        UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(    0), UINT16_C(    0),
             UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(    0),
             UINT16_MAX,      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(    0), UINT16_C(    0) } },
    { { UINT16_C(29217), UINT16_C(37687), UINT16_C(14439), UINT16_C(26007), UINT16_C(17767), UINT16_C(60797), UINT16_C(22669), UINT16_C( 5463),
        UINT16_C(21876), UINT16_C(12371), UINT16_C(40850), UINT16_C(46342), UINT16_C( 4933), UINT16_C(52659), UINT16_C(16644), UINT16_C( 9498),
        UINT16_C(20915), UINT16_C( 6841), UINT16_C(20617), UINT16_C(61823), UINT16_C(64661), UINT16_C( 9182), UINT16_C(13909), UINT16_C(51512),
        UINT16_C(35723), UINT16_C( 7673), UINT16_C(65323), UINT16_C(28882), UINT16_C(34322), UINT16_C( 5693), UINT16_C(22471), UINT16_C(31292) },
      { UINT16_C(62888), UINT16_C(37687), UINT16_C( 5189), UINT16_C(55842), UINT16_C(17767), UINT16_C(26109), UINT16_C(13879), UINT16_C(49711),
        UINT16_C(10433), UINT16_C(60640), UINT16_C(45608), UINT16_C(14940), UINT16_C( 4933), UINT16_C(65361), UINT16_C(36336), UINT16_C( 9498),
        UINT16_C(20915), UINT16_C( 6841), UINT16_C(60450), UINT16_C(12961), UINT16_C(40941), UINT16_C( 9368), UINT16_C(13909), UINT16_C(51512),
        UINT16_C(35723), UINT16_C( 6019), UINT16_C(57209), UINT16_C(28882), UINT16_C(34322), UINT16_C( 5693), UINT16_C(11056), UINT16_C(45570) },
      { UINT16_C(    0),      UINT16_MAX,      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(    0),
             UINT16_MAX, UINT16_C(    0), UINT16_C(    0),      UINT16_MAX,      UINT16_MAX, UINT16_C(    0), UINT16_C(    0),      UINT16_MAX,
             UINT16_MAX,      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX,
             UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(    0) } },
    { { UINT16_C(17208), UINT16_C(61460), UINT16_C(41566), UINT16_C( 6038), UINT16_C(25031), UINT16_C(46246), UINT16_C(51986), UINT16_C(35728),
        UINT16_C(33651), UINT16_C(64125), UINT16_C( 8649), UINT16_C(45563), UINT16_C(25974), UINT16_C(63434), UINT16_C(38097), UINT16_C( 2480),
        UINT16_C(50648), UINT16_C(14073), UINT16_C(36967), UINT16_C(11853), UINT16_C(62449), UINT16_C(  994), UINT16_C(29374), UINT16_C(12686),
        UINT16_C( 3062), UINT16_C(48940), UINT16_C(10028), UINT16_C(41840), UINT16_C(14988), UINT16_C(23962), UINT16_C(19151), UINT16_C(42854) },
      { UINT16_C(24335), UINT16_C(30429), UINT16_C(41566), UINT16_C( 6038), UINT16_C(25031), UINT16_C(46246), UINT16_C(29434), UINT16_C(35728),
        UINT16_C(14974), UINT16_C(64125), UINT16_C( 8033), UINT16_C(60749), UINT16_C(25974), UINT16_C(10570), UINT16_C(45106), UINT16_C(16848),
        UINT16_C(44303), UINT16_C(14073), UINT16_C(24023), UINT16_C(11853), UINT16_C(62449), UINT16_C(57042), UINT16_C(57398), UINT16_C(46286),
        UINT16_C(32026), UINT16_C(31582), UINT16_C(44189), UINT16_C(63336), UINT16_C(45715), UINT16_C(23962), UINT16_C(61538), UINT16_C(42854) },
      { UINT16_C(    0),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,
             UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX, UINT16_C(    0), UINT16_C(    0),
             UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),
        UINT16_C(    0),      UINT16_MAX, UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),      UINT16_MAX, UINT16_C(    0),      UINT16_MAX } },
    { { UINT16_C( 3879), UINT16_C(17376), UINT16_C(19039), UINT16_C(29251), UINT16_C( 8838), UINT16_C(41660), UINT16_C(47568), UINT16_C(64472),
        UINT16_C(35093), UINT16_C( 7619), UINT16_C(33442), UINT16_C(28089), UINT16_C( 6753), UINT16_C(12442), UINT16_C(14722), UINT16_C(43420),
        UINT16_C(31816), UINT16_C(42988), UINT16_C(12231), UINT16_C(19737), UINT16_C(54610), UINT16_C( 8944), UINT16_C(51343), UINT16_C(42013),
        UINT16_C(57426), UINT16_C(62658), UINT16_C(31586), UINT16_C(50018), UINT16_C(64661), UINT16_C( 6131), UINT16_C(36661), UINT16_C(32192) },
      { UINT16_C(44043), UINT16_C(53796), UINT16_C(16091), UINT16_C(11552), UINT16_C( 4115), UINT16_C(41551), UINT16_C(47568), UINT16_C(10823),
        UINT16_C( 2380), UINT16_C(44575), UINT16_C(33156), UINT16_C(28089), UINT16_C(25725), UINT16_C(45872), UINT16_C(61683), UINT16_C(65328),
        UINT16_C(21916), UINT16_C(30673), UINT16_C(61843), UINT16_C(42661), UINT16_C(62465), UINT16_C(55881), UINT16_C(36961), UINT16_C(44292),
        UINT16_C( 9113), UINT16_C( 7516), UINT16_C(52644), UINT16_C( 8758), UINT16_C(64661), UINT16_C( 9685), UINT16_C( 1366), UINT16_C(61988) },
      { UINT16_C(    0), UINT16_C(    0),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,
             UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX, UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),
             UINT16_MAX,      UINT16_MAX, UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),      UINT16_MAX, UINT16_C(    0),
             UINT16_MAX,      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX, UINT16_C(    0),      UINT16_MAX, UINT16_C(    0) } },
    { { UINT16_C(28845), UINT16_C(38100), UINT16_C(26751), UINT16_C(33405), UINT16_C(16453), UINT16_C(45798), UINT16_C(63240), UINT16_C(62392),
        UINT16_C(56165), UINT16_C(41090), UINT16_C(13364), UINT16_C(62221), UINT16_C(40890), UINT16_C(17928), UINT16_C( 3926), UINT16_C(  813),
        UINT16_C(  383), UINT16_C(65176), UINT16_C( 5481), UINT16_C(44672), UINT16_C(26198), UINT16_C(24160), UINT16_C( 6238), UINT16_C(50001),
        UINT16_C(54259), UINT16_C(10083), UINT16_C(28679), UINT16_C(49690), UINT16_C( 8719), UINT16_C(26120), UINT16_C(13617), UINT16_C(45161) },
      { UINT16_C(28845), UINT16_C(38100), UINT16_C(12055), UINT16_C(27981), UINT16_C(44438), UINT16_C(62667), UINT16_C( 7365), UINT16_C(47287),
        UINT16_C( 6895), UINT16_C(63455), UINT16_C(13364), UINT16_C(62221), UINT16_C(49435), UINT16_C(19711), UINT16_C(27127), UINT16_C(11773),
        UINT16_C(44138), UINT16_C(33229), UINT16_C( 6875), UINT16_C(29166), UINT16_C(47560), UINT16_C(24160), UINT16_C( 7381), UINT16_C(50001),
        UINT16_C( 9526), UINT16_C(10083), UINT16_C(29983), UINT16_C(49690), UINT16_C( 8719), UINT16_C(11655), UINT16_C(33986), UINT16_C(45161) },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(    0), UINT16_C(    0),      UINT16_MAX,      UINT16_MAX,
             UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX, UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),
        UINT16_C(    0),      UINT16_MAX, UINT16_C(    0),      UINT16_MAX, UINT16_C(    0),      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,
             UINT16_MAX,      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(    0),      UINT16_MAX } },
    { { UINT16_C(18185), UINT16_C(19363), UINT16_C( 8420), UINT16_C(15190), UINT16_C(60931), UINT16_C(  615), UINT16_C(22732), UINT16_C(53047),
        UINT16_C(11525), UINT16_C(10226), UINT16_C(20349), UINT16_C(10111), UINT16_C( 1331), UINT16_C(39827), UINT16_C(11494), UINT16_C(61235),
        UINT16_C(54899), UINT16_C(22587), UINT16_C(37367), UINT16_C(64147), UINT16_C(64127), UINT16_C(19452), UINT16_C(13138), UINT16_C(22298),
        UINT16_C( 3169), UINT16_C(56958), UINT16_C(64859), UINT16_C(36357), UINT16_C(38915), UINT16_C(59689), UINT16_C(23748), UINT16_C(14553) },
      { UINT16_C(18185), UINT16_C(10896), UINT16_C( 8420), UINT16_C(15190), UINT16_C( 8221), UINT16_C(  615), UINT16_C(35155), UINT16_C(46278),
        UINT16_C(17558), UINT16_C(61843), UINT16_C(20349), UINT16_C(10111), UINT16_C(43313), UINT16_C(62766), UINT16_C( 1798), UINT16_C(14637),
        UINT16_C(48411), UINT16_C(49251), UINT16_C(34784), UINT16_C(64996), UINT16_C(21415), UINT16_C(19452), UINT16_C(13020), UINT16_C(22298),
        UINT16_C(17014), UINT16_C(56958), UINT16_C(58586), UINT16_C(36357), UINT16_C(10893), UINT16_C(59689), UINT16_C(23748), UINT16_C(19660) },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,
        UINT16_C(    0), UINT16_C(    0),      UINT16_MAX,      UINT16_MAX, UINT16_C(    0), UINT16_C(    0),      UINT16_MAX,      UINT16_MAX,
             UINT16_MAX, UINT16_C(    0),      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,
        UINT16_C(    0),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(    0) } },
    { { UINT16_C(18935), UINT16_C(44567), UINT16_C(57657), UINT16_C(32011), UINT16_C(25367), UINT16_C(32925), UINT16_C(12138), UINT16_C(45920),
        UINT16_C(63270), UINT16_C(  215), UINT16_C( 1675), UINT16_C(19048), UINT16_C(25654), UINT16_C(37946), UINT16_C(30252), UINT16_C( 9183),
        UINT16_C(63167), UINT16_C(63953), UINT16_C(56791), UINT16_C(61046), UINT16_C( 4928), UINT16_C(43887), UINT16_C(53058), UINT16_C(26718),
        UINT16_C(13766), UINT16_C(21097), UINT16_C(53563), UINT16_C(29084), UINT16_C(54837), UINT16_C(24838), UINT16_C(58700), UINT16_C( 3205) },
      { UINT16_C(18935), UINT16_C(45573), UINT16_C(31539), UINT16_C(29856), UINT16_C( 3982), UINT16_C(53279), UINT16_C(32222), UINT16_C(42297),
        UINT16_C(41651), UINT16_C(61175), UINT16_C(37747), UINT16_C(43360), UINT16_C(26217), UINT16_C(46346), UINT16_C(36683), UINT16_C( 9921),
        UINT16_C(50918), UINT16_C( 6616), UINT16_C(30785), UINT16_C(53133), UINT16_C(44168), UINT16_C(26272), UINT16_C(55594), UINT16_C(56587),
        UINT16_C(  635), UINT16_C(61131), UINT16_C(11157), UINT16_C(65175), UINT16_C(41617), UINT16_C(56500), UINT16_C(30001), UINT16_C( 5890) },
      {      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(    0), UINT16_C(    0),      UINT16_MAX,
             UINT16_MAX, UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),
             UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(    0),      UINT16_MAX, UINT16_C(    0), UINT16_C(    0),
             UINT16_MAX, UINT16_C(    0),      UINT16_MAX, UINT16_C(    0),      UINT16_MAX, UINT16_C(    0),      UINT16_MAX, UINT16_C(    0) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i a = simde_mm512_loadu_epi16(test_vec[i].a);
    simde__m512i b = simde_mm512_loadu_epi16(test_vec[i].b);
    simde__m512i r = simde_x_mm512_cmpge_epu16(a, b);
    simde_test_x86_assert_equal_u16x32(r, simde_mm512_loadu_epi16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    uint16_t a_[32];
    uint16_t b_[32];

    simde_test_codegen_random_memory(sizeof(a_), HEDLEY_REINTERPRET_CAST(uint8_t*, a_));
    simde_test_codegen_random_memory(sizeof(b_), HEDLEY_REINTERPRET_CAST(uint8_t*, b_));
    for (size_t j = 0 ; j < (sizeof(a_) / sizeof(a_[0])) ; j++)
      if ((simde_test_codegen_rand() & 3) == 0)
        b_[j] = a_[j];

    simde__m512i a = simde_mm512_loadu_epi16(a_);
    simde__m512i b = simde_mm512_loadu_epi16(b_);
    simde__m512i r = simde_x_mm512_cmpge_epu16(a, b);

    simde_test_x86_write_u16x32(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_u16x32(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_u16x32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_cmpge_epu16_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const uint16_t a[32];
    const uint16_t b[32];
    const simde__mmask32 r;
  } test_vec[] = {
    { { UINT16_C(58292), UINT16_C( 1990), UINT16_C( 5025), UINT16_C( 3298), UINT16_C( 8960), UINT16_C(50849), UINT16_C( 4976), UINT16_C(49159),
        UINT16_C(14161), UINT16_C(47781), UINT16_C(35070), UINT16_C(26548), UINT16_C(35616), UINT16_C(11521), UINT16_C(45925), UINT16_C( 6518),
        UINT16_C(15510), UINT16_C(14368), UINT16_C(  592), UINT16_C(20548), UINT16_C(58917), UINT16_C(38423), UINT16_C( 7929), UINT16_C(19030),
        UINT16_C(64341), UINT16_C(21252), UINT16_C(47491), UINT16_C(41914), UINT16_C(48196), UINT16_C(43472), UINT16_C(18031), UINT16_C( 1730) },
      { UINT16_C(57987), UINT16_C(54078), UINT16_C( 5025), UINT16_C( 2595), UINT16_C(14952), UINT16_C(25248), UINT16_C(63065), UINT16_C(44716),
        UINT16_C(45553), UINT16_C(29698), UINT16_C(48234), UINT16_C(26548), UINT16_C(59512), UINT16_C(59480), UINT16_C( 6703), UINT16_C(45806),
        UINT16_C(15510), UINT16_C(57733), UINT16_C(43182), UINT16_C( 6123), UINT16_C(35811), UINT16_C(15481), UINT16_C( 9601), UINT16_C(19030),
        UINT16_C(64341), UINT16_C(21252), UINT16_C(65449), UINT16_C( 8687), UINT16_C(18407), UINT16_C( 5641), UINT16_C(18031), UINT16_C(24264) },
      UINT32_C(2075740845) },
    { { UINT16_C(54437), UINT16_C(39853), UINT16_C(38400), UINT16_C(46964), UINT16_C(35320), UINT16_C(32751), UINT16_C(39560), UINT16_C(29917),
        UINT16_C(31788), UINT16_C(48393), UINT16_C(49161), UINT16_C(56886), UINT16_C(50560), UINT16_C(14100), UINT16_C(43036), UINT16_C(49426),
        UINT16_C(49021), UINT16_C(32092), UINT16_C(53333), UINT16_C(19764), UINT16_C( 9049), UINT16_C(58061), UINT16_C(43710), UINT16_C(59990),
        UINT16_C(24614), UINT16_C(12456), UINT16_C(56864), UINT16_C(40974), UINT16_C( 8867), UINT16_C(49111), UINT16_C(60106), UINT16_C(18305) },
      { UINT16_C(56745), UINT16_C(39853), UINT16_C(38400), UINT16_C(46964), UINT16_C( 6428), UINT16_C(56041), UINT16_C(16580), UINT16_C(60100),
        UINT16_C(31788), UINT16_C(49178), UINT16_C(10314), UINT16_C(60768), UINT16_C(14154), UINT16_C( 5549), UINT16_C(11809), UINT16_C(52060),
        UINT16_C( 8459), UINT16_C(47562), UINT16_C(53333), UINT16_C(19764), UINT16_C(43568), UINT16_C(62479), UINT16_C(43710), UINT16_C(59990),
        UINT16_C(63808), UINT16_C(35658), UINT16_C(43553), UINT16_C(27768), UINT16_C( 9698), UINT16_C(  897), UINT16_C(56659), UINT16_C(24526) },
      UINT32_C(1825404254) },
    { { UINT16_C(25914), UINT16_C(59821), UINT16_C(64063), UINT16_C(50120), UINT16_C(39767), UINT16_C(34865), UINT16_C(10829), UINT16_C(63482),
        UINT16_C(63086), UINT16_C(23747), UINT16_C(64363), UINT16_C( 1580), UINT16_C(65460), UINT16_C(19444), UINT16_C(16801), UINT16_C(56544),
        UINT16_C(36262), UINT16_C(58821), UINT16_C(36487), UINT16_C(57256), UINT16_C(55849), UINT16_C(30311), UINT16_C(24836), UINT16_C(29294),
        UINT16_C(12632), UINT16_C(50126), UINT16_C(64045), UINT16_C(57801), UINT16_C(48634), UINT16_C(39724), UINT16_C( 3326), UINT16_C(42359) },
      { UINT16_C(15769), UINT16_C( 8586), UINT16_C(13259), UINT16_C(62464), UINT16_C(26381), UINT16_C( 4459), UINT16_C(10829), UINT16_C( 8580),
        UINT16_C(21002), UINT16_C(14308), UINT16_C(44621), UINT16_C(18201), UINT16_C(17771), UINT16_C(19444), UINT16_C(23122), UINT16_C(56544),
        UINT16_C(39319), UINT16_C(25100), UINT16_C( 3276), UINT16_C(55638), UINT16_C(55849), UINT16_C(30311), UINT16_C(28570), UINT16_C(42334),
        UINT16_C(12632), UINT16_C( 3804), UINT16_C(64045), UINT16_C(23637), UINT16_C(14395), UINT16_C(36294), UINT16_C(54674), UINT16_C(10616) },
      UINT32_C(3208558583) },
    { { UINT16_C( 4730), UINT16_C( 2932), UINT16_C(35059), UINT16_C(38417), UINT16_C(21384), UINT16_C(63188), UINT16_C(46836), UINT16_C(55078),
        UINT16_C(25973), UINT16_C(10922), UINT16_C(56057), UINT16_C(50457), UINT16_C(38607), UINT16_C(39459), UINT16_C(43659), UINT16_C( 1491),
        UINT16_C(18364), UINT16_C(44816), UINT16_C( 8655), UINT16_C(22342), UINT16_C( 6773), UINT16_C(26958), UINT16_C(29904), UINT16_C(17984),
        UINT16_C(60121), UINT16_C(53872), UINT16_C(35268), UINT16_C(38039), UINT16_C(47647), UINT16_C(43566), UINT16_C(  356), UINT16_C( 8367) },
      { UINT16_C( 4730), UINT16_C( 2932), UINT16_C( 5857), UINT16_C(22127), UINT16_C(21384), UINT16_C(  191), UINT16_C(65329), UINT16_C( 2886),
        UINT16_C(46826), UINT16_C(10922), UINT16_C(30016), UINT16_C(24386), UINT16_C(28719), UINT16_C(37898), UINT16_C(47473), UINT16_C(47540),
        UINT16_C(18364), UINT16_C(23505), UINT16_C(16538), UINT16_C(22342), UINT16_C(29181), UINT16_C(11979), UINT16_C( 4464), UINT16_C(23097),
        UINT16_C( 6088), UINT16_C( 2057), UINT16_C(19340), UINT16_C(47975), UINT16_C(29116), UINT16_C(11599), UINT16_C( 1067), UINT16_C(42215) },
      UINT32_C( 929775295) },
    { { UINT16_C(17098), UINT16_C(49850), UINT16_C(43251), UINT16_C( 5559), UINT16_C(55904), UINT16_C(10919), UINT16_C(37943), UINT16_C(43964),
        UINT16_C(22154), UINT16_C(52395), UINT16_C(26456), UINT16_C(52169), UINT16_C(62578), UINT16_C(33129), UINT16_C(43782), UINT16_C(53272),
        UINT16_C(54253), UINT16_C(57490), UINT16_C(18811), UINT16_C(56309), UINT16_C(40228), UINT16_C(23302), UINT16_C(49713), UINT16_C(48135),
        UINT16_C(45593), UINT16_C(29064), UINT16_C(20761), UINT16_C(35644), UINT16_C(42310), UINT16_C(19468), UINT16_C( 9552), UINT16_C(15901) },
      { UINT16_C(45048), UINT16_C(29470), UINT16_C( 5369), UINT16_C( 7502), UINT16_C(21681), UINT16_C(57976), UINT16_C(32535), UINT16_C(12446),
        UINT16_C( 9778), UINT16_C(19361), UINT16_C(56696), UINT16_C(48855), UINT16_C(58242), UINT16_C(53770), UINT16_C( 9992), UINT16_C(   16),
        UINT16_C(12247), UINT16_C(53363), UINT16_C(49731), UINT16_C(62701), UINT16_C(25878), UINT16_C(11734), UINT16_C(49713), UINT16_C( 5981),
        UINT16_C(65179), UINT16_C(29064), UINT16_C(14811), UINT16_C(24017), UINT16_C(56349), UINT16_C( 9520), UINT16_C( 9552), UINT16_C(15901) },
      UINT32_C(4008958934) },
    { { UINT16_C(55191), UINT16_C(62151), UINT16_C(28014), UINT16_C(27492), UINT16_C( 1258), UINT16_C(56397), UINT16_C(17921), UINT16_C(64618),
        UINT16_C( 2978), UINT16_C(14291), UINT16_C( 2173), UINT16_C(52457), UINT16_C(49260), UINT16_C( 4382), UINT16_C(19134), UINT16_C(21798),
        UINT16_C(60705), UINT16_C(36935), UINT16_C(44122), UINT16_C(17915), UINT16_C(18864), UINT16_C(45345), UINT16_C(35727), UINT16_C(12717),
        UINT16_C(33174), UINT16_C( 5224), UINT16_C(20873), UINT16_C(62944), UINT16_C(65042), UINT16_C(53255), UINT16_C(11592), UINT16_C(27173) },
      { UINT16_C(27674), UINT16_C(29946), UINT16_C(28014), UINT16_C(51385), UINT16_C(56126), UINT16_C(52857), UINT16_C(10086), UINT16_C(65023),
        UINT16_C(26792), UINT16_C(14291), UINT16_C(61881), UINT16_C(52457), UINT16_C(11759), UINT16_C( 4382), UINT16_C(49242), UINT16_C(29857),
        UINT16_C(39725), UINT16_C(17897), UINT16_C(41617), UINT16_C(53006), UINT16_C(18864), UINT16_C(58525), UINT16_C(40366), UINT16_C(12717),
        UINT16_C(33174), UINT16_C(48775), UINT16_C(44771), UINT16_C(53898), UINT16_C(65042), UINT16_C(53255), UINT16_C(44006), UINT16_C( 5034) },
      UINT32_C(3113695847) },
    { { UINT16_C(42616), UINT16_C(44786), UINT16_C(39180), UINT16_C(64097), UINT16_C(63965), UINT16_C(49047), UINT16_C(35441), UINT16_C(56485),
        UINT16_C(18948), UINT16_C(11561), UINT16_C(18809), UINT16_C(52785), UINT16_C(27506), UINT16_C(17928), UINT16_C(22095), UINT16_C(51040),
        UINT16_C(21244), UINT16_C( 2165), UINT16_C(55275), UINT16_C(51459), UINT16_C(39632), UINT16_C(16776), UINT16_C(11556), UINT16_C(10269),
        UINT16_C(18296), UINT16_C(61781), UINT16_C(34448), UINT16_C(  703), UINT16_C(51441), UINT16_C(16712), UINT16_C(43038), UINT16_C( 6664) },
      { UINT16_C(32507), UINT16_C(58914), UINT16_C(39180), UINT16_C( 9647), UINT16_C(14271), UINT16_C(58214), UINT16_C(35441), UINT16_C(56588),
        UINT16_C(25035), UINT16_C(23502), UINT16_C(36584), UINT16_C(55645), UINT16_C(42326), UINT16_C(29722), UINT16_C( 9037), UINT16_C(18574),
        UINT16_C(21244), UINT16_C(63023), UINT16_C(57046), UINT16_C(38171), UINT16_C(33046), UINT16_C(31609), UINT16_C(34053), UINT16_C(10269),
        UINT16_C( 9958), UINT16_C(52779), UINT16_C(34996), UINT16_C( 2728), UINT16_C(49709), UINT16_C(31614), UINT16_C( 3301), UINT16_C(34499) },
      UINT32_C(1402585181) },
    { { UINT16_C(11777), UINT16_C(53882), UINT16_C(41926), UINT16_C(57273), UINT16_C( 6980), UINT16_C(27645), UINT16_C(60629), UINT16_C(46712),
        UINT16_C(21255), UINT16_C(43595), UINT16_C(60119), UINT16_C( 7546), UINT16_C(50696), UINT16_C(13128), UINT16_C(64213), UINT16_C(54810),
        UINT16_C(38185), UINT16_C(61353), UINT16_C(25144), UINT16_C(31950), UINT16_C(52094), UINT16_C(21479), UINT16_C(24504), UINT16_C(48905),
        UINT16_C(21683), UINT16_C(35433), UINT16_C(58175), UINT16_C(18343), UINT16_C(61353), UINT16_C(32378), UINT16_C(38378), UINT16_C( 4949) },
      { UINT16_C(65066), UINT16_C(25090), UINT16_C(41926), UINT16_C(57054), UINT16_C(50843), UINT16_C(21298), UINT16_C(15141), UINT16_C(46712),
        UINT16_C(21255), UINT16_C(53090), UINT16_C(60119), UINT16_C( 2070), UINT16_C(37369), UINT16_C(13128), UINT16_C(56358), UINT16_C(20726),
        UINT16_C(63706), UINT16_C(15026), UINT16_C(37064), UINT16_C(31950), UINT16_C(19286), UINT16_C(21479), UINT16_C(51590), UINT16_C( 5716),
        UINT16_C(46917), UINT16_C(42213), UINT16_C(64704), UINT16_C(47532), UINT16_C(61353), UINT16_C(45980), UINT16_C(38378), UINT16_C(59651) },
      UINT32_C(1354431982) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i a = simde_mm512_loadu_epi16(test_vec[i].a);
    simde__m512i b = simde_mm512_loadu_epi16(test_vec[i].b);
    simde__mmask32 r = simde_mm512_cmpge_epu16_mask(a, b);
    simde_assert_equal_mmask32(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    uint16_t a_[32];
    uint16_t b_[32];

    simde_test_codegen_random_memory(sizeof(a_), HEDLEY_REINTERPRET_CAST(uint8_t*, a_));
    simde_test_codegen_random_memory(sizeof(b_), HEDLEY_REINTERPRET_CAST(uint8_t*, b_));
    for (size_t j = 0 ; j < (sizeof(a_) / sizeof(a_[0])) ; j++)
      if ((simde_test_codegen_rand() & 3) == 0)
        b_[j] = a_[j];

    simde__m512i a = simde_mm512_loadu_epi16(a_);
    simde__m512i b = simde_mm512_loadu_epi16(b_);
    simde__mmask32 r = simde_mm512_cmpge_epu16_mask(a, b);

    simde_test_x86_write_u16x32(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_u16x32(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_mask_cmpge_epu16_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask32 k;
    const uint16_t a[32];
    const uint16_t b[32];
    const simde__mmask32 r;
  } test_vec[] = {
    { UINT32_C(  18269749),
      { UINT16_C( 7422), UINT16_C(17577), UINT16_C(24409), UINT16_C(57824), UINT16_C(63692), UINT16_C( 1008), UINT16_C( 5476), UINT16_C(34942),
        UINT16_C(40479), UINT16_C( 9836), UINT16_C( 2410), UINT16_C(27065), UINT16_C(   67), UINT16_C( 4216), UINT16_C(29001), UINT16_C(18535),
        UINT16_C( 4237), UINT16_C(59276), UINT16_C(27760), UINT16_C(15560), UINT16_C(47204), UINT16_C(51263), UINT16_C(48845), UINT16_C(60752),
        UINT16_C(48220), UINT16_C(50707), UINT16_C(52422), UINT16_C( 2351), UINT16_C(43212), UINT16_C( 5657), UINT16_C(32793), UINT16_C(42590) },
      { UINT16_C( 7422), UINT16_C(  397), UINT16_C(24409), UINT16_C(57824), UINT16_C(32014), UINT16_C(56450), UINT16_C(54075), UINT16_C(38857),
        UINT16_C(56463), UINT16_C( 9836), UINT16_C(36008), UINT16_C(30047), UINT16_C(30772), UINT16_C(19851), UINT16_C(59897), UINT16_C(35572),
        UINT16_C(33235), UINT16_C(10635), UINT16_C(51415), UINT16_C(59107), UINT16_C(25925), UINT16_C(32962), UINT16_C(48845), UINT16_C(60752),
        UINT16_C(29799), UINT16_C( 3869), UINT16_C(31745), UINT16_C(13700), UINT16_C( 4085), UINT16_C(61059), UINT16_C(30712), UINT16_C(52088) },
      UINT64_C(            17957397) },
    { UINT32_C(2035818840),
      { UINT16_C(52381), UINT16_C(55826), UINT16_C(41796), UINT16_C(18256), UINT16_C(36172), UINT16_C(27313), UINT16_C(11240), UINT16_C(49288),
        UINT16_C(56361), UINT16_C(13964), UINT16_C(18355), UINT16_C(  316), UINT16_C( 3705), UINT16_C(44872), UINT16_C(24276), UINT16_C(29104),
        UINT16_C(49707), UINT16_C(28492), UINT16_C(40037), UINT16_C(45751), UINT16_C(26665), UINT16_C( 4636), UINT16_C(42131), UINT16_C(48338),
        UINT16_C(24193), UINT16_C(13555), UINT16_C(12197), UINT16_C( 7990), UINT16_C(32317), UINT16_C( 4558), UINT16_C(32476), UINT16_C( 1923) },
      { UINT16_C(53056), UINT16_C(42359), UINT16_C(41796), UINT16_C(37975), UINT16_C(29590), UINT16_C(10918), UINT16_C(30744), UINT16_C(39398),
        UINT16_C(55767), UINT16_C(31949), UINT16_C(  777), UINT16_C(18075), UINT16_C(27009), UINT16_C(24152), UINT16_C(56295), UINT16_C(10085),
        UINT16_C(56490), UINT16_C( 5581), UINT16_C( 9226), UINT16_C(41385), UINT16_C(20632), UINT16_C(45259), UINT16_C(45512), UINT16_C(40777),
        UINT16_C( 5771), UINT16_C(13555), UINT16_C(46874), UINT16_C(39898), UINT16_C(12833), UINT16_C( 2297), UINT16_C(32476), UINT16_C(46896) },
      UINT64_C(          1897406736) },
    { UINT32_C(1431029746),
      { UINT16_C(16279), UINT16_C(23859), UINT16_C(40177), UINT16_C(21995), UINT16_C( 6479), UINT16_C( 6211), UINT16_C(50787), UINT16_C(26107),
        UINT16_C(31011), UINT16_C(45703), UINT16_C(45809), UINT16_C(51279), UINT16_C(41997), UINT16_C(26075), UINT16_C(13253), UINT16_C(23775),
        UINT16_C( 4723), UINT16_C(25785), UINT16_C(42158), UINT16_C(64953), UINT16_C(64958), UINT16_C( 8469), UINT16_C( 4291), UINT16_C(59014),
        UINT16_C( 3722), UINT16_C(31640), UINT16_C(59584), UINT16_C(52804), UINT16_C( 8076), UINT16_C(20787), UINT16_C( 4690), UINT16_C(50605) },
      { UINT16_C(16279), UINT16_C(54058), UINT16_C(58122), UINT16_C(51408), UINT16_C(59104), UINT16_C(41962), UINT16_C(28918), UINT16_C(32905),
        UINT16_C( 8830), UINT16_C(16380), UINT16_C(16394), UINT16_C(38413), UINT16_C(41997), UINT16_C(45543), UINT16_C(37971), UINT16_C(23775),
        UINT16_C(41466), UINT16_C(25785), UINT16_C( 7044), UINT16_C(26061), UINT16_C(46849), UINT16_C(63240), UINT16_C(37415), UINT16_C(59014),
        UINT16_C(29876), UINT16_C(48869), UINT16_C(62132), UINT16_C(52804), UINT16_C(15154), UINT16_C(34244), UINT16_C(15311), UINT16_C(51709) },
      UINT64_C(              689984) },
    { UINT32_C( 901310607),
      { UINT16_C( 4449), UINT16_C(46008), UINT16_C( 5088), UINT16_C(16428), UINT16_C(19430), UINT16_C(11605), UINT16_C(10063), UINT16_C(17704),
        UINT16_C(13902), UINT16_C(44909), UINT16_C( 6921), UINT16_C( 6112), UINT16_C(55750), UINT16_C(47361), UINT16_C(19872), UINT16_C(  526),
        UINT16_C(50782), UINT16_C(16053), UINT16_C(57818), UINT16_C(49279), UINT16_C(54316), UINT16_C(31726), UINT16_C( 5883), UINT16_C(18880),
        UINT16_C(11597), UINT16_C(22265), UINT16_C(55625), UINT16_C( 3949), UINT16_C(28338), UINT16_C(21448), UINT16_C(54971), UINT16_C( 6741) },
      { UINT16_C( 2717), UINT16_C(30552), UINT16_C(55275), UINT16_C( 5943), UINT16_C( 9643), UINT16_C(42898), UINT16_C(10063), UINT16_C(35312),
        UINT16_C(59775), UINT16_C(51423), UINT16_C(19650), UINT16_C(30168), UINT16_C(41146), UINT16_C(30408), UINT16_C( 7543), UINT16_C( 5264),
        UINT16_C(59431), UINT16_C(16053), UINT16_C(49856), UINT16_C(27433), UINT16_C(48104), UINT16_C( 9234), UINT16_C(  781), UINT16_C(36013),
        UINT16_C(36076), UINT16_C(44885), UINT16_C(11736), UINT16_C(37412), UINT16_C(60621), UINT16_C(21448), UINT16_C(38921), UINT16_C(12376) },
      UINT64_C(           607674379) },
    { UINT32_C( 691333898),
      { UINT16_C(25939), UINT16_C(31171), UINT16_C(29988), UINT16_C(59052), UINT16_C(27860), UINT16_C(49044), UINT16_C(62080), UINT16_C(49794),
        UINT16_C(55411), UINT16_C(57809), UINT16_C( 9270), UINT16_C(11351), UINT16_C(65232), UINT16_C(24740), UINT16_C(23782), UINT16_C(14997),
        UINT16_C(22977), UINT16_C(58803), UINT16_C(24782), UINT16_C(41931), UINT16_C(24780), UINT16_C(19554), UINT16_C(58706), UINT16_C(50446),
        UINT16_C(57277), UINT16_C(62374), UINT16_C(65028), UINT16_C(54303), UINT16_C(50172), UINT16_C(57908), UINT16_C(51744), UINT16_C(57628) },
      { UINT16_C(25939), UINT16_C(31171), UINT16_C(37424), UINT16_C(64660), UINT16_C(63474), UINT16_C(17480), UINT16_C(22492), UINT16_C(49794),
        UINT16_C(45110), UINT16_C(14988), UINT16_C(43950), UINT16_C(43535), UINT16_C(17263), UINT16_C(24740), UINT16_C(43277), UINT16_C(12400),
        UINT16_C(14201), UINT16_C(58803), UINT16_C(24782), UINT16_C(48293), UINT16_C(61101), UINT16_C(19554), UINT16_C( 2885), UINT16_C(31522),
        UINT16_C(44731), UINT16_C(27318), UINT16_C(50522), UINT16_C(51476), UINT16_C(41224), UINT16_C( 5720), UINT16_C(51275), UINT16_C(50246) },
      UINT64_C(           690266882) },
    { UINT32_C(2914871076),
      { UINT16_C(48127), UINT16_C(  246), UINT16_C(19522), UINT16_C(54599), UINT16_C( 2500), UINT16_C(60195), UINT16_C(56193), UINT16_C(48748),
        UINT16_C(46759), UINT16_C( 5379), UINT16_C(24408), UINT16_C(50126), UINT16_C(19457), UINT16_C( 2861), UINT16_C(25143), UINT16_C(13877),
        UINT16_C(11037), UINT16_C(24375), UINT16_C(32375), UINT16_C(15156), UINT16_C(22407), UINT16_C( 2087), UINT16_C(37682), UINT16_C(56006),
        UINT16_C(51530), UINT16_C(41711), UINT16_C(48680), UINT16_C(10597), UINT16_C(37642), UINT16_C(16693), UINT16_C(27381), UINT16_C( 4728) },
      { UINT16_C(48127), UINT16_C(  246), UINT16_C(42541), UINT16_C(46151), UINT16_C(28413), UINT16_C(12476), UINT16_C(33282), UINT16_C(48748),
        UINT16_C(46759), UINT16_C( 5379), UINT16_C(21687), UINT16_C(49565), UINT16_C(53991), UINT16_C(56323), UINT16_C(31548), UINT16_C(53742),
        UINT16_C(24362), UINT16_C(22493), UINT16_C( 9477), UINT16_C(  779), UINT16_C(22407), UINT16_C(38195), UINT16_C(15689), UINT16_C(38113),
        UINT16_C(53302), UINT16_C(60936), UINT16_C(42532), UINT16_C( 2991), UINT16_C(45688), UINT16_C(16693), UINT16_C(27381), UINT16_C(22406) },
      UINT64_C(           748422944) },
    { UINT32_C(1069575507),
      { UINT16_C(64032), UINT16_C(41418), UINT16_C(31850), UINT16_C( 5994), UINT16_C(51215), UINT16_C(29690), UINT16_C(52271), UINT16_C(15354),
        UINT16_C(36173), UINT16_C(32960), UINT16_C(64006), UINT16_C(21985), UINT16_C(39611), UINT16_C(57304), UINT16_C(38145), UINT16_C( 8589),
        UINT16_C(22415), UINT16_C(63938), UINT16_C(11731), UINT16_C(57872), UINT16_C( 2805), UINT16_C( 9301), UINT16_C(20694), UINT16_C( 9056),
        UINT16_C( 8413), UINT16_C(58276), UINT16_C(34075), UINT16_C(54840), UINT16_C( 4127), UINT16_C( 8373), UINT16_C(17061), UINT16_C(13378) },
      { UINT16_C( 1177), UINT16_C(27693), UINT16_C(15665), UINT16_C(10063), UINT16_C(51215), UINT16_C( 7755), UINT16_C(52271), UINT16_C(53570),
        UINT16_C(59084), UINT16_C(59317), UINT16_C(60779), UINT16_C(21985), UINT16_C(29438), UINT16_C(41899), UINT16_C(60853), UINT16_C(20184),
        UINT16_C(22415), UINT16_C( 9147), UINT16_C( 2627), UINT16_C(35658), UINT16_C( 2805), UINT16_C(41897), UINT16_C(20694), UINT16_C( 9056),
        UINT16_C(10705), UINT16_C(58276), UINT16_C(45335), UINT16_C(54840), UINT16_C(29476), UINT16_C( 8373), UINT16_C(36961), UINT16_C(21287) },
      UINT64_C(           717237331) },
    { UINT32_C( 651766040),
      { UINT16_C( 9262), UINT16_C(34266), UINT16_C( 6193), UINT16_C(10782), UINT16_C(50379), UINT16_C(42997), UINT16_C(64606), UINT16_C(43674),
        UINT16_C(41676), UINT16_C( 3866), UINT16_C(25442), UINT16_C(46003), UINT16_C(43732), UINT16_C(10138), UINT16_C(23063), UINT16_C(18022),
        UINT16_C(16766), UINT16_C(45259), UINT16_C(59737), UINT16_C( 9434), UINT16_C(53165), UINT16_C( 3275), UINT16_C(26060), UINT16_C(39094),
        UINT16_C(53511), UINT16_C(27303), UINT16_C(23092), UINT16_C( 2077), UINT16_C(47108), UINT16_C( 6959), UINT16_C(38418), UINT16_C(37217) },
      { UINT16_C(11735), UINT16_C(12353), UINT16_C( 6934), UINT16_C(50261), UINT16_C( 8427), UINT16_C(47056), UINT16_C(34438), UINT16_C(36175),
        UINT16_C(41676), UINT16_C(36087), UINT16_C( 5456), UINT16_C(21652), UINT16_C(50381), UINT16_C(10138), UINT16_C(53594), UINT16_C(12656),
        UINT16_C(45566), UINT16_C(45259), UINT16_C(46797), UINT16_C(47320), UINT16_C(43223), UINT16_C(23919), UINT16_C(48687), UINT16_C(34538),
        UINT16_C(58036), UINT16_C( 1042), UINT16_C(42999), UINT16_C(50264), UINT16_C(51051), UINT16_C(50595), UINT16_C( 5272), UINT16_C(38646) },
      UINT64_C(            43002128) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__mmask32 k = test_vec[i].k;
    simde__m512i a = simde_mm512_loadu_epi16(test_vec[i].a);
    simde__m512i b = simde_mm512_loadu_epi16(test_vec[i].b);
    simde__mmask32 r = simde_mm512_mask_cmpge_epu16_mask(k, a, b);
    simde_assert_equal_mmask32(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    uint16_t a_[32];
    uint16_t b_[32];

    simde_test_codegen_random_memory(sizeof(a_), HEDLEY_REINTERPRET_CAST(uint8_t*, a_));
    simde_test_codegen_random_memory(sizeof(b_), HEDLEY_REINTERPRET_CAST(uint8_t*, b_));
    for (size_t j = 0 ; j < (sizeof(a_) / sizeof(a_[0])) ; j++)
      if ((simde_test_codegen_rand() & 3) == 0)
        b_[j] = a_[j];

    simde__mmask32 k = simde_test_x86_random_mmask32();
    simde__m512i a = simde_mm512_loadu_epi16(a_);
    simde__m512i b = simde_mm512_loadu_epi16(b_);
    simde__mmask32 r = simde_mm512_mask_cmpge_epu16_mask(k, a, b);

    simde_test_x86_write_mmask32(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_u16x32(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_u16x32(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask64(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_x_mm_cmpge_epi32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int32_t a[4];
    const int32_t b[4];
    const int32_t r[4];
  } test_vec[] = {
    { { -INT32_C(  1655441224), -INT32_C(   600825204),  INT32_C(  1375078415), -INT32_C(  1671647570) },
      { -INT32_C(   939367616), -INT32_C(  1760696454),  INT32_C(  1375078415), -INT32_C(  1425737230) },
      {  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0) } },
    { { -INT32_C(  1990559622),  INT32_C(   802836608),  INT32_C(  1053505278),  INT32_C(   319278489) },
      { -INT32_C(  1990559622), -INT32_C(   176489981),  INT32_C(  1053505278),  INT32_C(  1331947733) },
      { -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0) } },
    { {  INT32_C(   202420749), -INT32_C(  2109023255),  INT32_C(  1553355176),  INT32_C(  1754611813) },
      {  INT32_C(   777916218), -INT32_C(  2109023255),  INT32_C(  1553355176),  INT32_C(  1076398899) },
      {  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1) } },
    { { -INT32_C(  1146513645),  INT32_C(  1310212072), -INT32_C(  1162433153),  INT32_C(  1256723645) },
      { -INT32_C(  1146513645),  INT32_C(  1310212072),  INT32_C(   686058219),  INT32_C(  1256723645) },
      { -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1) } },
    { { -INT32_C(  1224832713), -INT32_C(   193940169), -INT32_C(   599893815), -INT32_C(   992547757) },
      {  INT32_C(   929568844),  INT32_C(   610225538), -INT32_C(   599893815), -INT32_C(   992547757) },
      {  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1) } },
    { {  INT32_C(  1929381034), -INT32_C(  1336918179),  INT32_C(  2004166187), -INT32_C(  1062281922) },
      {  INT32_C(  1929381034),  INT32_C(  1659813820), -INT32_C(   515840757), -INT32_C(  2064788262) },
      { -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1) } },
    { {  INT32_C(  1491486509), -INT32_C(  1395696786),  INT32_C(  1668119864),  INT32_C(  1175147146) },
      {  INT32_C(  1491486509), -INT32_C(  1174476321), -INT32_C(  1791104067),  INT32_C(   113980633) },
      { -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1) } },
    { {  INT32_C(  1150692620),  INT32_C(   900137898),  INT32_C(  1736160085), -INT32_C(  1937496915) },
      { -INT32_C(   901414387),  INT32_C(  1197507181),  INT32_C(  1736160085), -INT32_C(  1937496915) },
      { -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_x_mm_loadu_epi32(test_vec[i].a);
    simde__m128i b = simde_x_mm_loadu_epi32(test_vec[i].b);
    simde__m128i r = simde_x_mm_cmpge_epi32(a, b);
    simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    int32_t a_[4];
    int32_t b_[4];

    simde_test_codegen_random_memory(sizeof(a_), HEDLEY_REINTERPRET_CAST(uint8_t*, a_));
    simde_test_codegen_random_memory(sizeof(b_), HEDLEY_REINTERPRET_CAST(uint8_t*, b_));
    for (size_t j = 0 ; j < (sizeof(a_) / sizeof(a_[0])) ; j++)
      if ((simde_test_codegen_rand() & 3) == 0)
        b_[j] = a_[j];

    simde__m128i a = simde_mm_loadu_epi32(a_);
    simde__m128i b = simde_mm_loadu_epi32(b_);
    simde__m128i r = simde_x_mm_cmpge_epi32(a, b);

    simde_test_x86_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_cmpge_epi32_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int32_t a[4];
    const int32_t b[4];
    const simde__mmask8 r;
  } test_vec[] = {
    { { -INT32_C(   546249719),  INT32_C(  1983871877),  INT32_C(  1227473824), -INT32_C(   836561550) },
      {  INT32_C(  2018964847),  INT32_C(  1843215079),  INT32_C(  1227473824), -INT32_C(   442887716) },
      UINT8_C(  6) },
    { {  INT32_C(   653329286),  INT32_C(   946805446), -INT32_C(  1626893777),  INT32_C(  1847025031) },
      { -INT32_C(  1076104040), -INT32_C(   372540403), -INT32_C(  2083625587),  INT32_C(  1847025031) },
      UINT8_C( 15) },
    { {  INT32_C(   949258761), -INT32_C(  1529373924), -INT32_C(  1861030151), -INT32_C(   279908638) },
      { -INT32_C(   120054934), -INT32_C(   277109120), -INT32_C(  1861030151),  INT32_C(  1881800807) },
      UINT8_C(  5) },
    { {  INT32_C(  1397456986),  INT32_C(  1373920878), -INT32_C(  1237306292), -INT32_C(   810673841) },
      { -INT32_C(   121755201),  INT32_C(   164012962),  INT32_C(   796520612), -INT32_C(   810673841) },
      UINT8_C( 11) },
    { { -INT32_C(   866041984), -INT32_C(  1031626381),  INT32_C(  2056335802), -INT32_C(    59617190) },
      { -INT32_C(  1761265421), -INT32_C(   691634648),  INT32_C(  1105173920),  INT32_C(  1062288063) },
      UINT8_C(  5) },
    { {  INT32_C(   246451540),  INT32_C(   428360126), -INT32_C(  2062157167),  INT32_C(  1511791410) },
      {  INT32_C(   959570841),  INT32_C(  1065029760), -INT32_C(   998323126), -INT32_C(   743274113) },
      UINT8_C(  8) },
    { {  INT32_C(   904817315), -INT32_C(  1749417116), -INT32_C(  1192110562),  INT32_C(   972104377) },
      {  INT32_C(  2105044018), -INT32_C(  1203636679), -INT32_C(  1769213057), -INT32_C(   110400427) },
      UINT8_C( 12) },
    { {  INT32_C(  2077419612),  INT32_C(  2016658366),  INT32_C(   414262502), -INT32_C(   896193903) },
      { -INT32_C(  1602037984),  INT32_C(   540413386),  INT32_C(  1343857017),  INT32_C(  1451968506) },
      UINT8_C(  3) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_x_mm_loadu_epi32(test_vec[i].a);
    simde__m128i b = simde_x_mm_loadu_epi32(test_vec[i].b);
    simde__mmask8 r = simde_mm_cmpge_epi32_mask(a, b);
    simde_assert_equal_mmask8(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    int32_t a_[4];
    int32_t b_[4];

    simde_test_codegen_random_memory(sizeof(a_), HEDLEY_REINTERPRET_CAST(uint8_t*, a_));
    simde_test_codegen_random_memory(sizeof(b_), HEDLEY_REINTERPRET_CAST(uint8_t*, b_));
    for (size_t j = 0 ; j < (sizeof(a_) / sizeof(a_[0])) ; j++)
      if ((simde_test_codegen_rand() & 3) == 0)
        b_[j] = a_[j];

    simde__m128i a = simde_mm_loadu_epi32(a_);
    simde__m128i b = simde_mm_loadu_epi32(b_);
    simde__mmask8 r = simde_mm_cmpge_epi32_mask(a, b);

    simde_test_x86_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_mask_cmpge_epi32_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k;
    const int32_t a[4];
    const int32_t b[4];
    const simde__mmask8 r;
  } test_vec[] = {
    { UINT8_C(245),
      {  INT32_C(   696025189),  INT32_C(  2079121996), -INT32_C(  1614249714),  INT32_C(    95355611) },
      {  INT32_C(  1392887934),  INT32_C(   427697865),  INT32_C(   529104048), -INT32_C(   828970391) },
      UINT8_C(  0) },
    { UINT8_C(132),
      {  INT32_C(  1694708196), -INT32_C(    79650055),  INT32_C(   444155217),  INT32_C(  1893977418) },
      { -INT32_C(   954139317),  INT32_C(  1898987654), -INT32_C(   371458346), -INT32_C(   622947594) },
      UINT8_C(  4) },
    { UINT8_C(171),
      { -INT32_C(   975783809), -INT32_C(    15732686), -INT32_C(   800423725), -INT32_C(   531164512) },
      {  INT32_C(  1102563394),  INT32_C(   892838051), -INT32_C(   800423725), -INT32_C(   531164512) },
      UINT8_C(  8) },
    { UINT8_C(247),
      {  INT32_C(   612343716), -INT32_C(    54243350),  INT32_C(  1849599398), -INT32_C(    65896612) },
      { -INT32_C(   948222026), -INT32_C(    54243350),  INT32_C(  2103830466),  INT32_C(   522782075) },
      UINT8_C(  3) },
    { UINT8_C( 16),
      { -INT32_C(  1382118648),  INT32_C(  1225329865),  INT32_C(  1727989022),  INT32_C(  1571211137) },
      { -INT32_C(   987783714),  INT32_C(   121740546),  INT32_C(  1856790726),  INT32_C(  1571211137) },
      UINT8_C(  0) },
    { UINT8_C(114),
      {  INT32_C(  1731123554), -INT32_C(  1612147496), -INT32_C(   662813125),  INT32_C(    47858533) },
      { -INT32_C(   439819900), -INT32_C(   913754482), -INT32_C(  1617939044), -INT32_C(   256958322) },
      UINT8_C(  0) },
    { UINT8_C( 91),
      { -INT32_C(  2035453632),  INT32_C(   854296047),  INT32_C(  1102573151), -INT32_C(   305161034) },
      { -INT32_C(  2035453632),  INT32_C(  1223174184), -INT32_C(  1237198632),  INT32_C(  1864897327) },
      UINT8_C(  1) },
    { UINT8_C(195),
      { -INT32_C(   809785887), -INT32_C(   125436836),  INT32_C(  1662874315),  INT32_C(   613185531) },
      {  INT32_C(   939316319),  INT32_C(   694661654),  INT32_C(  1662874315), -INT32_C(  1391714100) },
      UINT8_C(  0) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__mmask8 k = test_vec[i].k;
    simde__m128i a = simde_x_mm_loadu_epi32(test_vec[i].a);
    simde__m128i b = simde_x_mm_loadu_epi32(test_vec[i].b);
    simde__mmask8 r = simde_mm_mask_cmpge_epi32_mask(k, a, b);
    simde_assert_equal_mmask8(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    int32_t a_[4];
    int32_t b_[4];

    simde_test_codegen_random_memory(sizeof(a_), HEDLEY_REINTERPRET_CAST(uint8_t*, a_));
    simde_test_codegen_random_memory(sizeof(b_), HEDLEY_REINTERPRET_CAST(uint8_t*, b_));
    for (size_t j = 0 ; j < (sizeof(a_) / sizeof(a_[0])) ; j++)
      if ((simde_test_codegen_rand() & 3) == 0)
        b_[j] = a_[j];

    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m128i a = simde_mm_loadu_epi32(a_);
    simde__m128i b = simde_mm_loadu_epi32(b_);
    simde__mmask8 r = simde_mm_mask_cmpge_epi32_mask(k, a, b);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x4(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_x_mm256_cmpge_epi32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int32_t a[8];
    const int32_t b[8];
    const int32_t r[8];
  } test_vec[] = {
    { {  INT32_C(  1128554292), -INT32_C(  1766527256), -INT32_C(   848889338),  INT32_C(  1668150183),  INT32_C(  1060450639),  INT32_C(   481120356), -INT32_C(  1257195853),  INT32_C(  1934755903) },
      {  INT32_C(  1337431655), -INT32_C(  1766527256),  INT32_C(   207113317),  INT32_C(  1668150183),  INT32_C(  1523492342), -INT32_C(  1451852811),  INT32_C(  1902020402),  INT32_C(  1934755903) },
      {  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1) } },
    { { -INT32_C(  1233539209),  INT32_C(  1782966644), -INT32_C(  2084301938), -INT32_C(  1070842994),  INT32_C(  1362267074), -INT32_C(  2092492996), -INT32_C(  1169191757),  INT32_C(   791062200) },
      { -INT32_C(   907632811),  INT32_C(   372452232), -INT32_C(   862259138), -INT32_C(   175258061), -INT32_C(  1924743343), -INT32_C(  1995338282), -INT32_C(  1169191757),  INT32_C(   791062200) },
      {  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1) } },
    { { -INT32_C(  2078522799),  INT32_C(  1517922568),  INT32_C(  1055375208),  INT32_C(  1724381260),  INT32_C(  1614219865),  INT32_C(  2109487220),  INT32_C(   823058975), -INT32_C(  1920879044) },
      {  INT32_C(    17997560), -INT32_C(  1336177849),  INT32_C(  1055375208), -INT32_C(  1795312069),  INT32_C(   888419776), -INT32_C(  1917734803), -INT32_C(   809582445),  INT32_C(  1868316790) },
      {  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0) } },
    { {  INT32_C(  1222427661),  INT32_C(   987552378),  INT32_C(  2087702543),  INT32_C(   336142465),  INT32_C(  1474545888), -INT32_C(   423215352), -INT32_C(  1475660114),  INT32_C(   250470657) },
      {  INT32_C(  1222427661), -INT32_C(  1302776925), -INT32_C(  2060466172), -INT32_C(   912705303),  INT32_C(   136346624), -INT32_C(   423215352),  INT32_C(   487717404), -INT32_C(  2144534821) },
      { -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1) } },
    { { -INT32_C(  1438691903), -INT32_C(  2039228283),  INT32_C(   277779540), -INT32_C(  1753645702),  INT32_C(  1387563895),  INT32_C(  1372774537),  INT32_C(   448622947),  INT32_C(   718592873) },
      { -INT32_C(  1438691903),  INT32_C(  1093880044),  INT32_C(  1448198876), -INT32_C(  1225930177), -INT32_C(   553082283), -INT32_C(   433005950), -INT32_C(  1275007669), -INT32_C(   253766456) },
      { -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1) } },
    { { -INT32_C(   768710765), -INT32_C(  2021123279),  INT32_C(  1080463549), -INT32_C(  1255762326),  INT32_C(  1282025092), -INT32_C(   482522630), -INT32_C(   122102788),  INT32_C(  1087360684) },
      { -INT32_C(   768710765), -INT32_C(   689071335), -INT32_C(  1776921813),  INT32_C(  1850424554),  INT32_C(  1282025092), -INT32_C(    79628290),  INT32_C(  2146695378),  INT32_C(  1087360684) },
      { -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1) } },
    { { -INT32_C(  1943091550),  INT32_C(  1710913794),  INT32_C(   767735087),  INT32_C(  2133328556), -INT32_C(  1057088518), -INT32_C(  1631863330), -INT32_C(    76079986),  INT32_C(   244524651) },
      { -INT32_C(   275070484),  INT32_C(  1767150906),  INT32_C(   767735087),  INT32_C(  2133328556), -INT32_C(  1177390117), -INT32_C(  1631863330),  INT32_C(   364564137),  INT32_C(   244524651) },
      {  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1) } },
    { {  INT32_C(  1385384250), -INT32_C(   479983608), -INT32_C(  1399048580),  INT32_C(  1819014083), -INT32_C(  1233050175), -INT32_C(  2137545614), -INT32_C(  1261869214), -INT32_C(   984515701) },
      { -INT32_C(   870849340), -INT32_C(   479983608),  INT32_C(  1947552945),  INT32_C(    31490112),  INT32_C(   414671526),  INT32_C(  1754877446),  INT32_C(  1075667637), -INT32_C(   984515701) },
      { -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256i a = simde_mm256_loadu_epi32(test_vec[i].a);
    simde__m256i b = simde_mm256_loadu_epi32(test_vec[i].b);
    simde__m256i r = simde_x_mm256_cmpge_epi32(a, b);
    simde_test_x86_assert_equal_i32x8(r, simde_mm256_loadu_epi32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    int32_t a_[8];
    int32_t b_[8];

    simde_test_codegen_random_memory(sizeof(a_), HEDLEY_REINTERPRET_CAST(uint8_t*, a_));
    simde_test_codegen_random_memory(sizeof(b_), HEDLEY_REINTERPRET_CAST(uint8_t*, b_));
    for (size_t j = 0 ; j < (sizeof(a_) / sizeof(a_[0])) ; j++)
      if ((simde_test_codegen_rand() & 3) == 0)
        b_[j] = a_[j];

    simde__m256i a = simde_mm256_loadu_epi32(a_);
    simde__m256i b = simde_mm256_loadu_epi32(b_);
    simde__m256i r = simde_x_mm256_cmpge_epi32(a, b);

    simde_test_x86_write_i32x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_cmpge_epi32_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int32_t a[8];
    const int32_t b[8];
    const simde__mmask8 r;
  } test_vec[] = {
    { { -INT32_C(   583642054),  INT32_C(   351783869),  INT32_C(   481759204),  INT32_C(  1348173171), -INT32_C(   475513727),  INT32_C(  1633215348),  INT32_C(   292249929), -INT32_C(  1639074204) },
      { -INT32_C(   948206838),  INT32_C(   351783869), -INT32_C(   196111487), -INT32_C(  1840993775),  INT32_C(  1534520806),  INT32_C(   431804112), -INT32_C(  1825954001), -INT32_C(   416188195) },
      UINT16_C(  111) },
    { {  INT32_C(   798280734),  INT32_C(  1556273270), -INT32_C(  1766377275),  INT32_C(   900690694),  INT32_C(  2009717402),  INT32_C(  1298135634), -INT32_C(   979956057), -INT32_C(  1218112359) },
      {  INT32_C(  1458043360),  INT32_C(  1556273270), -INT32_C(   416453919),  INT32_C(   900690694),  INT32_C(   150005174),  INT32_C(  1298135634), -INT32_C(   162730659), -INT32_C(   491933438) },
      UINT16_C(   58) },
    { {  INT32_C(   872759382), -INT32_C(   743628260), -INT32_C(   405037817),  INT32_C(  1231958508),  INT32_C(   557824799),  INT32_C(   386133100), -INT32_C(  1097646975),  INT32_C(  2145232424) },
      {  INT32_C(    45343462),  INT32_C(   215310340), -INT32_C(   369905155),  INT32_C(    20079330), -INT32_C(  1994231523), -INT32_C(   543152546), -INT32_C(  1952631966), -INT32_C(  1089832231) },
      UINT16_C(  249) },
    { {  INT32_C(   721772872), -INT32_C(   533973053),  INT32_C(   124342185), -INT32_C(   672789899),  INT32_C(   392332093),  INT32_C(  1540779262),  INT32_C(  1220319274),  INT32_C(  2019764784) },
      {  INT32_C(   721772872),  INT32_C(  1227804832), -INT32_C(  1806657761), -INT32_C(   672789899), -INT32_C(  1208561991),  INT32_C(  1540779262), -INT32_C(  1783836827),  INT32_C(  2019764784) },
      UINT16_C(  253) },
    { {  INT32_C(   959754647), -INT32_C(  1592221721), -INT32_C(  1470624147),  INT32_C(  1057778650),  INT32_C(   869579066),  INT32_C(  1102570185),  INT32_C(   341477779),  INT32_C(   548715401) },
      {  INT32_C(  1415178349), -INT32_C(   168463993), -INT32_C(  1470624147), -INT32_C(   208033351),  INT32_C(   723938914), -INT32_C(   479339184), -INT32_C(   268974234), -INT32_C(   284185726) },
      UINT16_C(  252) },
    { {  INT32_C(  1085582471), -INT32_C(  1204597418),  INT32_C(   199514555), -INT32_C(  1662103242), -INT32_C(  1702107880),  INT32_C(   596286352), -INT32_C(   566309372), -INT32_C(  1892135673) },
      {  INT32_C(  1355803898), -INT32_C(   184024262), -INT32_C(  1828590500),  INT32_C(  1429204797),  INT32_C(  1710275541),  INT32_C(  1518959190),  INT32_C(  1329121096),  INT32_C(   249458964) },
      UINT16_C(    4) },
    { { -INT32_C(  1851748781),  INT32_C(  1390858365), -INT32_C(   507980149), -INT32_C(  1740947120),  INT32_C(   484995848),  INT32_C(  1110165220),  INT32_C(   635013492),  INT32_C(  1144219376) },
      {  INT32_C(  1926616052),  INT32_C(  1390858365), -INT32_C(   502301550), -INT32_C(   981775683), -INT32_C(  1562221634), -INT32_C(  1629221591),  INT32_C(   635013492),  INT32_C(   432797220) },
      UINT16_C(  242) },
    { { -INT32_C(  1982813236), -INT32_C(  1269871626), -INT32_C(   682217042), -INT32_C(   730514626),  INT32_C(   492517881), -INT32_C(   113891793),  INT32_C(   577225158), -INT32_C(   586218735) },
      { -INT32_C(  1536761938), -INT32_C(   665275094), -INT32_C(   682217042), -INT32_C(   470211094), -INT32_C(  1912581026),  INT32_C(  1099380603),  INT32_C(   157544184), -INT32_C(  1595509775) },
      UINT16_C(  212) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256i a = simde_mm256_loadu_epi32(test_vec[i].a);
    simde__m256i b = simde_mm256_loadu_epi32(test_vec[i].b);
    simde__mmask8 r = simde_mm256_cmpge_epi32_mask(a, b);
    simde_assert_equal_mmask16(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    int32_t a_[8];
    int32_t b_[8];

    simde_test_codegen_random_memory(sizeof(a_), HEDLEY_REINTERPRET_CAST(uint8_t*, a_));
    simde_test_codegen_random_memory(sizeof(b_), HEDLEY_REINTERPRET_CAST(uint8_t*, b_));
    for (size_t j = 0 ; j < (sizeof(a_) / sizeof(a_[0])) ; j++)
      if ((simde_test_codegen_rand() & 3) == 0)
        b_[j] = a_[j];

    simde__m256i a = simde_mm256_loadu_epi32(a_);
    simde__m256i b = simde_mm256_loadu_epi32(b_);
    simde__mmask8 r = simde_mm256_cmpge_epi32_mask(a, b);

    simde_test_x86_write_i32x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_mask_cmpge_epi32_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k;
    const int32_t a[8];
    const int32_t b[8];
    const simde__mmask8 r;
  } test_vec[] = {
    { UINT8_C( 85),
      {  INT32_C(   906822988), -INT32_C(  1994848725), -INT32_C(   703129253),  INT32_C(  1226284880),  INT32_C(  2136112013),  INT32_C(  1075788270), -INT32_C(  2000854138),  INT32_C(  1282478848) },
      {  INT32_C(  1132625688), -INT32_C(   523396219), -INT32_C(   703129253),  INT32_C(   290377347),  INT32_C(   932225353),  INT32_C(  1618456538),  INT32_C(   333985042),  INT32_C(  1616861768) },
      UINT8_C( 20) },
    { UINT8_C( 66),
      { -INT32_C(  1009174283),  INT32_C(   655157894),  INT32_C(   687948666), -INT32_C(   264543813), -INT32_C(  1539813814), -INT32_C(  1870817106), -INT32_C(  1391600836),  INT32_C(   268648474) },
      { -INT32_C(  1009174283),  INT32_C(  1076289734), -INT32_C(   563534045), -INT32_C(   741432183), -INT32_C(  1586034957), -INT32_C(   617483105), -INT32_C(   360104241), -INT32_C(   151352194) },
      UINT8_C(  0) },
    { UINT8_C(124),
      {  INT32_C(  2076946391), -INT32_C(  2073125250),  INT32_C(   153292565),  INT32_C(  2144993088),  INT32_C(   352174984), -INT32_C(  1971522371),  INT32_C(    70822633), -INT32_C(   280622824) },
      {  INT32_C(   912921272), -INT32_C(   960767568),  INT32_C(   701488872),  INT32_C(  1705552093),  INT32_C(   679060843), -INT32_C(  2102135399), -INT32_C(  1215894625), -INT32_C(  1398354444) },
      UINT8_C(104) },
    { UINT8_C( 46),
      { -INT32_C(   849675483),  INT32_C(  1228521379),  INT32_C(   786587961), -INT32_C(     3250924), -INT32_C(  1192000021),  INT32_C(  1033347116),  INT32_C(   556214147), -INT32_C(  1583482500) },
      { -INT32_C(  1737492491),  INT32_C(  1228521379),  INT32_C(   505332745),  INT32_C(   337505321), -INT32_C(  1192000021),  INT32_C(   886793393),  INT32_C(   139788939), -INT32_C(   257297669) },
      UINT8_C( 38) },
    { UINT8_C( 36),
      { -INT32_C(  1671960401),  INT32_C(   370043909), -INT32_C(  1647858631), -INT32_C(  1993737337),  INT32_C(  1132736848), -INT32_C(   215124518),  INT32_C(  1756614398),  INT32_C(   244809055) },
      {  INT32_C(  1806364261), -INT32_C(  1820215206), -INT32_C(   349091484), -INT32_C(  1993737337),  INT32_C(  1708718475),  INT32_C(  1817707886),  INT32_C(  1756614398),  INT32_C(   244809055) },
      UINT8_C(  0) },
    { UINT8_C(165),
      { -INT32_C(   748031111),  INT32_C(  1633615464), -INT32_C(   607140906),  INT32_C(   682507036),  INT32_C(  2075254799),  INT32_C(   198549536), -INT32_C(   693138950),  INT32_C(  1257945041) },
      {  INT32_C(   303915946),  INT32_C(  1633615464),  INT32_C(  1527923263), -INT32_C(  1920745347), -INT32_C(  1056426848), -INT32_C(   808657451), -INT32_C(   693138950), -INT32_C(   578641870) },
      UINT8_C(160) },
    { UINT8_C(132),
      {  INT32_C(  1864611247),  INT32_C(  1829810232), -INT32_C(  1790783048),  INT32_C(   435884445),  INT32_C(  1464546231),  INT32_C(  1448749238),  INT32_C(  2071052056),  INT32_C(   186698844) },
      { -INT32_C(  1166392447),  INT32_C(  1829810232), -INT32_C(  1790783048),  INT32_C(   435884445),  INT32_C(   629693807), -INT32_C(  1636047994),  INT32_C(  2071052056),  INT32_C(   973683129) },
      UINT8_C(  4) },
    { UINT8_C( 63),
      { -INT32_C(  1728093348), -INT32_C(   771215243), -INT32_C(  1671942727), -INT32_C(  1774258519),  INT32_C(  1229929743), -INT32_C(   892958394), -INT32_C(  1713817986), -INT32_C(  1356971182) },
      {  INT32_C(   457645478),  INT32_C(   116215629), -INT32_C(  1671942727), -INT32_C(  1774258519),  INT32_C(  1687489310),  INT32_C(   305093524), -INT32_C(   458487663), -INT32_C(   241972661) },
      UINT8_C( 12) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__mmask8 k = test_vec[i].k;
    simde__m256i a = simde_mm256_loadu_epi32(test_vec[i].a);
    simde__m256i b = simde_mm256_loadu_epi32(test_vec[i].b);
    simde__mmask8 r = simde_mm256_mask_cmpge_epi32_mask(k, a, b);
    simde_assert_equal_mmask8(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    int32_t a_[8];
    int32_t b_[8];

    simde_test_codegen_random_memory(sizeof(a_), HEDLEY_REINTERPRET_CAST(uint8_t*, a_));
    simde_test_codegen_random_memory(sizeof(b_), HEDLEY_REINTERPRET_CAST(uint8_t*, b_));
    for (size_t j = 0 ; j < (sizeof(a_) / sizeof(a_[0])) ; j++)
      if ((simde_test_codegen_rand() & 3) == 0)
        b_[j] = a_[j];

    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m256i a = simde_mm256_loadu_epi32(a_);
    simde__m256i b = simde_mm256_loadu_epi32(b_);
    simde__mmask8 r = simde_mm256_mask_cmpge_epi32_mask(k, a, b);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_x_mm512_cmpge_epi32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int32_t a[16];
    const int32_t b[16];
    const int32_t r[16];
  } test_vec[] = {
    { { -INT32_C(  1099117091), -INT32_C(  1797470071), -INT32_C(  1205321379),  INT32_C(  2018065264), -INT32_C(  1312608793), -INT32_C(  1684491072), -INT32_C(  1178219328), -INT32_C(   436638713),
        -INT32_C(  1029475015), -INT32_C(  1705607107),  INT32_C(   827489985), -INT32_C(  1599497287), -INT32_C(  1991152439), -INT32_C(   534451936), -INT32_C(  1113986634), -INT32_C(  1901948331) },
      {  INT32_C(  1146111495), -INT32_C(  1797470071), -INT32_C(  1205321379), -INT32_C(  1786814004), -INT32_C(   316747571),  INT32_C(  1892500410), -INT32_C(  2110953940),  INT32_C(     1102073),
        -INT32_C(   599432938),  INT32_C(   744694535),  INT32_C(   537598804),  INT32_C(  1236634236),  INT32_C(   339137370), -INT32_C(   534451936),  INT32_C(  1657123433), -INT32_C(  1738287742) },
      {  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),
         INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0) } },
    { { -INT32_C(   563155512),  INT32_C(  1495397360),  INT32_C(   666691237), -INT32_C(   222355524), -INT32_C(  1842334777), -INT32_C(    55403766),  INT32_C(   275443984), -INT32_C(  1368776218),
        -INT32_C(    24324082),  INT32_C(  1884794571),  INT32_C(  1352078228), -INT32_C(   113027534), -INT32_C(  1819511927),  INT32_C(   529481230),  INT32_C(   355465519),  INT32_C(   683907354) },
      {  INT32_C(  1025921137), -INT32_C(  1834123522), -INT32_C(   991738479),  INT32_C(   633153179), -INT32_C(  1842334777), -INT32_C(  1211676537),  INT32_C(  1556936257), -INT32_C(  1368776218),
        -INT32_C(   566383648),  INT32_C(  1884794571), -INT32_C(   880913616), -INT32_C(   113027534), -INT32_C(  1819511927),  INT32_C(   529481230),  INT32_C(   126783608),  INT32_C(      463648) },
      {  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),
        -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1) } },
    { { -INT32_C(  1225856315), -INT32_C(   454512020),  INT32_C(  1676375875),  INT32_C(  1214575242),  INT32_C(  1731150391),  INT32_C(   885510289),  INT32_C(  1280373744), -INT32_C(   735150321),
        -INT32_C(   712369047),  INT32_C(   314143439),  INT32_C(  1937089769), -INT32_C(   826549866), -INT32_C(  1388975588), -INT32_C(  1411252805), -INT32_C(      511504),  INT32_C(   433268400) },
      {  INT32_C(   300834114), -INT32_C(   454512020), -INT32_C(   500393653),  INT32_C(  1214575242), -INT32_C(  1925388846), -INT32_C(   768008734), -INT32_C(     3067569), -INT32_C(  1726372777),
        -INT32_C(   712369047), -INT32_C(    91566417),  INT32_C(  1937089769),  INT32_C(  1902677150),  INT32_C(  1425974386), -INT32_C(  1411252805), -INT32_C(  1089406872), -INT32_C(  1638323811) },
      {  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),
        -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1) } },
    { { -INT32_C(   485835231),  INT32_C(  1593061877), -INT32_C(   971176919),  INT32_C(  1600484910),  INT32_C(  1296028794),  INT32_C(  2122783182),  INT32_C(   348953552),  INT32_C(   952732695),
         INT32_C(  1058788170),  INT32_C(   782044932),  INT32_C(  1123334932), -INT32_C(  1398712015), -INT32_C(    50733010), -INT32_C(   897941255),  INT32_C(   853427739),  INT32_C(   476817362) },
      {  INT32_C(  2136770171), -INT32_C(  1431438954), -INT32_C(   420699468),  INT32_C(   697470459),  INT32_C(  1713736557),  INT32_C(   640720651),  INT32_C(   348953552),  INT32_C(   836092854),
        -INT32_C(   525323958), -INT32_C(   544580054), -INT32_C(    70945280), -INT32_C(  1398712015), -INT32_C(    50733010), -INT32_C(   804059158),  INT32_C(   853427739),  INT32_C(  2046582063) },
      {  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),
        -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0) } },
    { {  INT32_C(  1619239542), -INT32_C(  1087334743),  INT32_C(   814397441), -INT32_C(  1532393706),  INT32_C(  1063060020),  INT32_C(  1045100005),  INT32_C(   110776402), -INT32_C(   224631172),
        -INT32_C(  1303240951), -INT32_C(  1217297739),  INT32_C(  1357380666), -INT32_C(  1208643197),  INT32_C(  2046186131), -INT32_C(  1699266488),  INT32_C(   211899024), -INT32_C(  1040302664) },
      {  INT32_C(  1619239542),  INT32_C(   231335378),  INT32_C(  1683861985), -INT32_C(  1532393706),  INT32_C(  1063060020),  INT32_C(  1045100005),  INT32_C(   284043352), -INT32_C(   224631172),
         INT32_C(   282412605),  INT32_C(   220045099), -INT32_C(  1838056880),  INT32_C(  1919389133), -INT32_C(   262162786),  INT32_C(   349365948),  INT32_C(  1965342735), -INT32_C(   348588371) },
      { -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),
         INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
    { {  INT32_C(  1744973996),  INT32_C(   645714967),  INT32_C(  1117495444), -INT32_C(   751971433), -INT32_C(  1925502752), -INT32_C(   762728384),  INT32_C(   171055255), -INT32_C(  1172569330),
         INT32_C(  1260527156), -INT32_C(  2022596878), -INT32_C(   708244418), -INT32_C(  1079380257),  INT32_C(  1582097438),  INT32_C(   741398165), -INT32_C(    63544594), -INT32_C(  1699327130) },
      {  INT32_C(  1744973996), -INT32_C(  1259645322),  INT32_C(  1117495444), -INT32_C(   751971433), -INT32_C(  1406776041),  INT32_C(   299390499),  INT32_C(   520949689), -INT32_C(  1172569330),
         INT32_C(   288857755),  INT32_C(  1455760116), -INT32_C(   708244418), -INT32_C(  1079380257),  INT32_C(  1582097438),  INT32_C(  2115510213), -INT32_C(  1868749522), -INT32_C(  2090641688) },
      { -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),
        -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1) } },
    { { -INT32_C(  1873277749),  INT32_C(  1494118699),  INT32_C(  2146020246), -INT32_C(   184398591), -INT32_C(  1512204312), -INT32_C(  1707533327),  INT32_C(  1573277424),  INT32_C(  1991150763),
        -INT32_C(  1006172519),  INT32_C(   236852599), -INT32_C(  1030944831),  INT32_C(  1018728276),  INT32_C(   400725286), -INT32_C(  1582163023),  INT32_C(   352221289), -INT32_C(  1635013627) },
      {  INT32_C(   711103155),  INT32_C(  1494118699), -INT32_C(   601111160),  INT32_C(  2065294165), -INT32_C(  1512204312), -INT32_C(  2134162154),  INT32_C(  1573277424),  INT32_C(   694165366),
         INT32_C(  1498661809),  INT32_C(   236852599), -INT32_C(  1030944831),  INT32_C(  1210237391), -INT32_C(   764299844), -INT32_C(  1219347206),  INT32_C(  2088429318), -INT32_C(  1197090298) },
      {  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),
         INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
    { {  INT32_C(  1302612051), -INT32_C(  1979320700), -INT32_C(   469336099), -INT32_C(   140727463),  INT32_C(   685288868),  INT32_C(  1056867455), -INT32_C(   288523303),  INT32_C(  1841341209),
         INT32_C(  1891263723),  INT32_C(   955957082), -INT32_C(  1742995138),  INT32_C(  1351596204), -INT32_C(   461805723), -INT32_C(  1004308501),  INT32_C(   213119218),  INT32_C(  2138665875) },
      {  INT32_C(   837759959),  INT32_C(   829024755), -INT32_C(   469336099), -INT32_C(  1561896899), -INT32_C(  1417191233), -INT32_C(   898651432),  INT32_C(   769008282),  INT32_C(  1823231893),
         INT32_C(  1891263723),  INT32_C(   955957082), -INT32_C(   905547379), -INT32_C(  1989284151),  INT32_C(   641004622),  INT32_C(   955360158),  INT32_C(  1533396934), -INT32_C(  1698164201) },
      { -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),
        -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i a = simde_mm512_loadu_epi32(test_vec[i].a);
    simde__m512i b = simde_mm512_loadu_epi32(test_vec[i].b);
    simde__m512i r = simde_x_mm512_cmpge_epi32(a, b);
    simde_test_x86_assert_equal_i32x16(r, simde_mm512_loadu_epi32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    int32_t a_[16];
    int32_t b_[16];

    simde_test_codegen_random_memory(sizeof(a_), HEDLEY_REINTERPRET_CAST(uint8_t*, a_));
    simde_test_codegen_random_memory(sizeof(b_), HEDLEY_REINTERPRET_CAST(uint8_t*, b_));
    for (size_t j = 0 ; j < (sizeof(a_) / sizeof(a_[0])) ; j++)
      if ((simde_test_codegen_rand() & 3) == 0)
        b_[j] = a_[j];

    simde__m512i a = simde_mm512_loadu_epi32(a_);
    simde__m512i b = simde_mm512_loadu_epi32(b_);
    simde__m512i r = simde_x_mm512_cmpge_epi32(a, b);

    simde_test_x86_write_i32x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_cmpge_epi32_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int32_t a[16];
    const int32_t b[16];
    const simde__mmask16 r;
  } test_vec[] = {
    { {  INT32_C(  1354561720), -INT32_C(  1285220726), -INT32_C(   367136982),  INT32_C(  1896163411),  INT32_C(  1218436393), -INT32_C(   949536718), -INT32_C(   733973257),  INT32_C(   717881714),
        -INT32_C(  2072279047), -INT32_C(   952639331),  INT32_C(   582046927), -INT32_C(  1500203140), -INT32_C(   940690540),  INT32_C(  1670272364),  INT32_C(  1010290377), -INT32_C(   916061745) },
      {  INT32_C(  1354561720), -INT32_C(  1863482175),  INT32_C(  1437834968), -INT32_C(   352630955),  INT32_C(  1218436393),  INT32_C(   122240830), -INT32_C(   599556083),  INT32_C(   178629250),
         INT32_C(  1295053451),  INT32_C(  1339891062),  INT32_C(   582046927),  INT32_C(  1392222167), -INT32_C(   969364344), -INT32_C(   120749333), -INT32_C(  2066476798),  INT32_C(  1183808187) },
      UINT16_C(29851) },
    { {  INT32_C(   985883471), -INT32_C(   399339291),  INT32_C(  1550583713), -INT32_C(   308020351), -INT32_C(  1764739398), -INT32_C(  1456602457),  INT32_C(  1300420312), -INT32_C(   917852806),
        -INT32_C(   167506672),  INT32_C(  1071527582), -INT32_C(  1097053635),  INT32_C(    11288390),  INT32_C(   496467061),  INT32_C(  1472644479),  INT32_C(   363153563),  INT32_C(    98562037) },
      { -INT32_C(  1677990915),  INT32_C(  1473960217),  INT32_C(  1779791396),  INT32_C(   728416693), -INT32_C(  1119354562), -INT32_C(  1456602457),  INT32_C(  1266137430), -INT32_C(  1504684375),
        -INT32_C(   167506672),  INT32_C(  1071527582),  INT32_C(  1202962322), -INT32_C(  1083040127), -INT32_C(   428033505),  INT32_C(   508072136),  INT32_C(   363153563),  INT32_C(  1335474710) },
      UINT16_C(31713) },
    { { -INT32_C(  1001600772), -INT32_C(  1562143656),  INT32_C(  1771392083),  INT32_C(   213462534), -INT32_C(    29861112), -INT32_C(  1266307672),  INT32_C(   474043605), -INT32_C(  1836937834),
        -INT32_C(  1386820011), -INT32_C(  1253033630), -INT32_C(  1944066682),  INT32_C(   479844372), -INT32_C(   618999501),  INT32_C(  1401921662), -INT32_C(  1972383500), -INT32_C(  1306726051) },
      { -INT32_C(  1001600772), -INT32_C(  1562143656), -INT32_C(  1447037291),  INT32_C(    29776078), -INT32_C(    29861112), -INT32_C(  1266307672), -INT32_C(  1694537155),  INT32_C(   458038363),
         INT32_C(   993832335), -INT32_C(   227667107), -INT32_C(   677630711), -INT32_C(  1361485179), -INT32_C(  1017792958),  INT32_C(  1597525794), -INT32_C(  1972383500), -INT32_C(  1306726051) },
      UINT16_C(55423) },
    { {  INT32_C(   306659824),  INT32_C(  1249017744),  INT32_C(   174025910), -INT32_C(  1477668941),  INT32_C(  2079853307),  INT32_C(  1325742998),  INT32_C(  1552770587), -INT32_C(  1864336992),
         INT32_C(  1268918202),  INT32_C(  1570051238),  INT32_C(   862450816),  INT32_C(  2128237443), -INT32_C(   184888738),  INT32_C(   692387598),  INT32_C(    92655973),  INT32_C(    93677131) },
      {  INT32_C(   877672333),  INT32_C(  1249017744),  INT32_C(  1543567577), -INT32_C(  1445209525), -INT32_C(  1147218515),  INT32_C(   971301588), -INT32_C(    29464141), -INT32_C(  1864336992),
         INT32_C(  1452364810),  INT32_C(   321069626),  INT32_C(  1701847834), -INT32_C(  1441838083), -INT32_C(   194663136),  INT32_C(  1110264207), -INT32_C(  2109641805),  INT32_C(  1222591806) },
      UINT16_C(23282) },
    { {  INT32_C(  1572270798), -INT32_C(   274734276), -INT32_C(  1938694066), -INT32_C(  1076604635),  INT32_C(  1418884033),  INT32_C(   436238645),  INT32_C(  1929188048),  INT32_C(    20220467),
        -INT32_C(  1201739140),  INT32_C(   463994573),  INT32_C(    78059998),  INT32_C(   734231658),  INT32_C(   629102063), -INT32_C(  1623228209), -INT32_C(   971883374),  INT32_C(  1137133254) },
      {  INT32_C(  1572270798),  INT32_C(    35300132),  INT32_C(   637977020),  INT32_C(   760334653), -INT32_C(   296562401), -INT32_C(   477261487),  INT32_C(  1929188048),  INT32_C(   399995366),
        -INT32_C(  1156197481),  INT32_C(   463994573),  INT32_C(   777569521), -INT32_C(  1403278963), -INT32_C(   879055494), -INT32_C(  1623228209), -INT32_C(  1381934905),  INT32_C(  1137133254) },
      UINT16_C(64113) },
    { {  INT32_C(  1899721010),  INT32_C(  1635707545),  INT32_C(   202252099), -INT32_C(   462564456), -INT32_C(  1230600019), -INT32_C(    21915039), -INT32_C(   601236762), -INT32_C(  1874067362),
         INT32_C(   184649585), -INT32_C(  1251180686),  INT32_C(   935426719), -INT32_C(    98816435),  INT32_C(   414302903),  INT32_C(  1125605981), -INT32_C(  1709227972), -INT32_C(  1322554560) },
      {  INT32_C(  1899721010),  INT32_C(  1260005548), -INT32_C(   259859549), -INT32_C(  1041523190), -INT32_C(  1230600019), -INT32_C(    21915039),  INT32_C(  1892950320),  INT32_C(  2133000076),
        -INT32_C(   656089556), -INT32_C(  1251180686), -INT32_C(   459627046), -INT32_C(  1515879100),  INT32_C(   526614049), -INT32_C(  1621531537),  INT32_C(   303050373),  INT32_C(  1502687789) },
      UINT16_C(12095) },
    { { -INT32_C(   987609514),  INT32_C(   811891882), -INT32_C(   683510614), -INT32_C(  1221471322), -INT32_C(  1093770679), -INT32_C(  1324576585), -INT32_C(   839958548),  INT32_C(  1825624598),
        -INT32_C(  1036913896),  INT32_C(   435328623), -INT32_C(  1309658102),  INT32_C(  1365778696),  INT32_C(   990852740), -INT32_C(  1293148986),  INT32_C(  1904270171), -INT32_C(   975286099) },
      { -INT32_C(  1299771581),  INT32_C(   811891882), -INT32_C(   683510614), -INT32_C(  1221471322), -INT32_C(   962848769), -INT32_C(  1904703437),  INT32_C(   268499043), -INT32_C(  1932140983),
        -INT32_C(  1824563731), -INT32_C(  2059203881), -INT32_C(  1539529530),  INT32_C(  1365778696), -INT32_C(  1892507045), -INT32_C(  1910658262),  INT32_C(  1904270171), -INT32_C(   377916165) },
      UINT16_C(32687) },
    { { -INT32_C(     6787116), -INT32_C(  1114786534), -INT32_C(   827708461),  INT32_C(  1891050399), -INT32_C(  1659358245),  INT32_C(  1428571890),  INT32_C(  1562727343),  INT32_C(  1516659334),
        -INT32_C(   346423599), -INT32_C(  2035751245), -INT32_C(  1319808494),  INT32_C(  1344408693),  INT32_C(   854473280),  INT32_C(   814224512), -INT32_C(   292704920), -INT32_C(   532090097) },
      { -INT32_C(  1530158351), -INT32_C(  1708428152),  INT32_C(  1011646662), -INT32_C(   863211892), -INT32_C(  1659358245),  INT32_C(  1428571890),  INT32_C(  1562727343), -INT32_C(   903598631),
         INT32_C(  1483665615),  INT32_C(   720542052), -INT32_C(  1503248871),  INT32_C(  1433596844), -INT32_C(    58822291),  INT32_C(   770955256), -INT32_C(   292704920), -INT32_C(   715090682) },
      UINT16_C(62715) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i a = simde_mm512_loadu_epi32(test_vec[i].a);
    simde__m512i b = simde_mm512_loadu_epi32(test_vec[i].b);
    simde__mmask16 r = simde_mm512_cmpge_epi32_mask(a, b);
    simde_assert_equal_mmask16(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    int32_t a_[16];
    int32_t b_[16];

    simde_test_codegen_random_memory(sizeof(a_), HEDLEY_REINTERPRET_CAST(uint8_t*, a_));
    simde_test_codegen_random_memory(sizeof(b_), HEDLEY_REINTERPRET_CAST(uint8_t*, b_));
    for (size_t j = 0 ; j < (sizeof(a_) / sizeof(a_[0])) ; j++)
      if ((simde_test_codegen_rand() & 3) == 0)
        b_[j] = a_[j];

    simde__m512i a = simde_mm512_loadu_epi32(a_);
    simde__m512i b = simde_mm512_loadu_epi32(b_);
    simde__mmask16 r = simde_mm512_cmpge_epi32_mask(a, b);

    simde_test_x86_write_i32x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_mask_cmpge_epi32_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask16 k;
    const int32_t a[16];
    const int32_t b[16];
    const simde__mmask16 r;
  } test_vec[] = {
    { UINT16_C( 1302),
      {  INT32_C(    81255947),  INT32_C(  1915866037), -INT32_C(  1459051869), -INT32_C(  1115723721), -INT32_C(  1633244106),  INT32_C(   723565260), -INT32_C(  1573501131), -INT32_C(   310536479),
         INT32_C(   703681908), -INT32_C(  1013243360), -INT32_C(    76700732),  INT32_C(  1102638091),  INT32_C(  1709203352),  INT32_C(  1318060057),  INT32_C(   703710791), -INT32_C(   803836324) },
      {  INT32_C(    81255947),  INT32_C(  1915866037), -INT32_C(  1459051869), -INT32_C(  1115723721),  INT32_C(   436036352), -INT32_C(  1419211421), -INT32_C(  1573501131), -INT32_C(  1954551097),
         INT32_C(   443447537),  INT32_C(  1124537612), -INT32_C(    76700732), -INT32_C(  1866331760), -INT32_C(   794116244), -INT32_C(  1602547123),  INT32_C(   844124011),  INT32_C(   717082425) },
      UINT16_C( 1286) },
    { UINT16_C(31280),
      { -INT32_C(   568892573),  INT32_C(  1395491331),  INT32_C(  1914922677), -INT32_C(   727815280),  INT32_C(  1461706943), -INT32_C(   545957557), -INT32_C(  2143904988), -INT32_C(  1853535186),
        -INT32_C(  1301307985), -INT32_C(   737764321), -INT32_C(  1840830206),  INT32_C(  1399252372),  INT32_C(   279676357),  INT32_C(    66068703), -INT32_C(   360503621),  INT32_C(   561711474) },
      { -INT32_C(   975967322), -INT32_C(  1969563257), -INT32_C(  1776492286), -INT32_C(  1930787898),  INT32_C(  1461706943), -INT32_C(   545957557),  INT32_C(   609906354),  INT32_C(   491116151),
         INT32_C(  1222842817), -INT32_C(   170754574),  INT32_C(   613150558),  INT32_C(  2058384754), -INT32_C(  1084076790), -INT32_C(  1942991399), -INT32_C(   360503621),  INT32_C(   558954080) },
      UINT16_C(28720) },
    { UINT16_C(59270),
      { -INT32_C(   238613823),  INT32_C(  1182565014),  INT32_C(   104651957),  INT32_C(  1748585470),  INT32_C(  1134881357),  INT32_C(   734384376), -INT32_C(  2062566035), -INT32_C(  2130755649),
        -INT32_C(   546126263), -INT32_C(    31003063), -INT32_C(   939236662), -INT32_C(    80724306),  INT32_C(   540988712),  INT32_C(   306971813), -INT32_C(  2137498687), -INT32_C(   469723238) },
      { -INT32_C(  1480363426),  INT32_C(   732293472), -INT32_C(    84694452),  INT32_C(   284501224),  INT32_C(  1134881357), -INT32_C(   122651593), -INT32_C(  2062566035), -INT32_C(  2130755649),
        -INT32_C(   546126263),  INT32_C(  1333234179),  INT32_C(   474573364), -INT32_C(  2027143538), -INT32_C(  1457169039), -INT32_C(  1314793767), -INT32_C(    31253986),  INT32_C(  2117892499) },
      UINT16_C( 8582) },
    { UINT16_C(47292),
      {  INT32_C(   666722438),  INT32_C(   876731409),  INT32_C(   397268186),  INT32_C(   490225491), -INT32_C(  1184897835), -INT32_C(  1025045563),  INT32_C(   132862533), -INT32_C(  1242598865),
        -INT32_C(   472011566),  INT32_C(  1662459528),  INT32_C(  1182450931), -INT32_C(   664555005),  INT32_C(  1553121943),  INT32_C(   320764365), -INT32_C(    82179637),  INT32_C(  1303382395) },
      {  INT32_C(   666722438), -INT32_C(  1616820308),  INT32_C(   266672907),  INT32_C(  1709656270), -INT32_C(   658409205), -INT32_C(  1025045563),  INT32_C(  1689847528), -INT32_C(  1242598865),
        -INT32_C(  1559960841),  INT32_C(   893560105), -INT32_C(  1891358783),  INT32_C(  2062822255), -INT32_C(  1756121691),  INT32_C(  2085961364),  INT32_C(  1423969860),  INT32_C(  1863946872) },
      UINT16_C( 4260) },
    { UINT16_C(39646),
      { -INT32_C(   722055042), -INT32_C(  1377682484), -INT32_C(  1472243057), -INT32_C(   607734839),  INT32_C(   590317904),  INT32_C(   540649997), -INT32_C(    98075755), -INT32_C(   508370078),
        -INT32_C(     4872141),  INT32_C(  1923913699), -INT32_C(  1155798030), -INT32_C(   275258978),  INT32_C(  1997719146),  INT32_C(   110578545),  INT32_C(   687914695), -INT32_C(   737496415) },
      {  INT32_C(  1054064474), -INT32_C(  1377682484),  INT32_C(   168086379), -INT32_C(   607734839),  INT32_C(   590317904),  INT32_C(   500769878), -INT32_C(  2092443166), -INT32_C(   447262325),
        -INT32_C(     4872141),  INT32_C(   380753067),  INT32_C(  1277212063), -INT32_C(  1285416623),  INT32_C(  1997719146), -INT32_C(   141009132),  INT32_C(   687914695),  INT32_C(  1118360113) },
      UINT16_C( 6746) },
    { UINT16_C( 9095),
      {  INT32_C(   821686936),  INT32_C(  1678782953), -INT32_C(  1657388556),  INT32_C(   761869187), -INT32_C(  1719137829), -INT32_C(   730294200),  INT32_C(   247624186),  INT32_C(   648650894),
         INT32_C(  2086052498), -INT32_C(   924817708),  INT32_C(   711268007),  INT32_C(   609734217),  INT32_C(   549314519),  INT32_C(  1928607352),  INT32_C(   897627815), -INT32_C(   396678826) },
      { -INT32_C(  1604013620), -INT32_C(  1083685864), -INT32_C(  1544892838),  INT32_C(  1959215516), -INT32_C(  1718319839), -INT32_C(   730294200), -INT32_C(  1802007746), -INT32_C(  2122517835),
        -INT32_C(  1155407453), -INT32_C(   924817708), -INT32_C(   199006889), -INT32_C(   949425242),  INT32_C(   727776368), -INT32_C(  1030919292), -INT32_C(  1403640585), -INT32_C(  1188179434) },
      UINT16_C( 9091) },
    { UINT16_C(44586),
      { -INT32_C(  1886450942),  INT32_C(   598968013),  INT32_C(  1609943346), -INT32_C(   122836605), -INT32_C(   605518718), -INT32_C(   698925645), -INT32_C(    77480136), -INT32_C(  1725962090),
        -INT32_C(  1071075597),  INT32_C(  1726209076),  INT32_C(   684054949),  INT32_C(    69235330), -INT32_C(  1428223754),  INT32_C(  2122331717), -INT32_C(  1938169099), -INT32_C(  1104832310) },
      {  INT32_C(  2055097670),  INT32_C(   598968013), -INT32_C(  1107843781),  INT32_C(   247535639),  INT32_C(  1723375648), -INT32_C(   857458474), -INT32_C(   447193830), -INT32_C(  1725962090),
        -INT32_C(  1071075597),  INT32_C(  1726209076),  INT32_C(  1417394749), -INT32_C(   211665710), -INT32_C(  1286006052),  INT32_C(  1837055315), -INT32_C(  1873619046),  INT32_C(   516814164) },
      UINT16_C(10786) },
    { UINT16_C(32151),
      {  INT32_C(   535526816),  INT32_C(  1039566570), -INT32_C(   483243498),  INT32_C(  2070366569),  INT32_C(  1028752356), -INT32_C(  2012093989), -INT32_C(  1718083005), -INT32_C(  1337474544),
         INT32_C(   701510463), -INT32_C(   815348039),  INT32_C(  2058590481), -INT32_C(   957015326),  INT32_C(  2030257821),  INT32_C(  1795233063),  INT32_C(  1191483703), -INT32_C(  1695003813) },
      {  INT32_C(   535526816),  INT32_C(  1039566570), -INT32_C(   483243498),  INT32_C(  1919684564),  INT32_C(  1028752356), -INT32_C(  1125585787), -INT32_C(  1718083005), -INT32_C(  1233322953),
         INT32_C(  1391280324), -INT32_C(   815348039), -INT32_C(  2083255378), -INT32_C(   957015326),  INT32_C(   904782000),  INT32_C(  1391646156),  INT32_C(  1191483703), -INT32_C(  1230065422) },
      UINT16_C(31767) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__mmask16 k = test_vec[i].k;
    simde__m512i a = simde_mm512_loadu_epi32(test_vec[i].a);
    simde__m512i b = simde_mm512_loadu_epi32(test_vec[i].b);
    simde__mmask16 r = simde_mm512_mask_cmpge_epi32_mask(k, a, b);
    simde_assert_equal_mmask16(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    int32_t a_[16];
    int32_t b_[16];

    simde_test_codegen_random_memory(sizeof(a_), HEDLEY_REINTERPRET_CAST(uint8_t*, a_));
    simde_test_codegen_random_memory(sizeof(b_), HEDLEY_REINTERPRET_CAST(uint8_t*, b_));
    for (size_t j = 0 ; j < (sizeof(a_) / sizeof(a_[0])) ; j++)
      if ((simde_test_codegen_rand() & 3) == 0)
        b_[j] = a_[j];

    simde__mmask16 k = simde_test_x86_random_mmask16();
    simde__m512i a = simde_mm512_loadu_epi32(a_);
    simde__m512i b = simde_mm512_loadu_epi32(b_);
    simde__mmask16 r = simde_mm512_mask_cmpge_epi32_mask(k, a, b);

    simde_test_x86_write_mmask16(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x16(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_x_mm_cmpge_epu32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const uint32_t a[4];
    const uint32_t b[4];
    const uint32_t r[4];
  } test_vec[] = {
    { { UINT32_C(1968333699), UINT32_C(3932885942), UINT32_C(3130678540), UINT32_C( 458656275) },
      { UINT32_C(1830217700), UINT32_C(3905494054), UINT32_C(3130678540), UINT32_C( 927610548) },
      {           UINT32_MAX,           UINT32_MAX,           UINT32_MAX, UINT32_C(         0) } },
    { { UINT32_C(3157858224), UINT32_C(2272777076), UINT32_C(1117965661), UINT32_C(3668949172) },
      { UINT32_C( 297957588), UINT32_C(2480824799), UINT32_C( 835332247), UINT32_C(1988130501) },
      {           UINT32_MAX, UINT32_C(         0),           UINT32_MAX,           UINT32_MAX } },
    { { UINT32_C(3951602061), UINT32_C( 724380279), UINT32_C(3070680291), UINT32_C( 868796500) },
      { UINT32_C(3251021354), UINT32_C( 724380279), UINT32_C(2466935558), UINT32_C(3130277165) },
      {           UINT32_MAX,           UINT32_MAX,           UINT32_MAX, UINT32_C(         0) } },
    { { UINT32_C( 713675335), UINT32_C(  65114030), UINT32_C(2167843415), UINT32_C( 524549456) },
      { UINT32_C( 713675335), UINT32_C(  65114030), UINT32_C(3801136379), UINT32_C( 524236248) },
      {           UINT32_MAX,           UINT32_MAX, UINT32_C(         0),           UINT32_MAX } },
    { { UINT32_C(2948148055), UINT32_C( 623964373), UINT32_C(2051372013), UINT32_C(1359935913) },
      { UINT32_C(3005691575), UINT32_C( 623964373), UINT32_C(4109030636), UINT32_C(4104860573) },
      { UINT32_C(         0),           UINT32_MAX, UINT32_C(         0), UINT32_C(         0) } },
    { { UINT32_C(1096406100), UINT32_C(4038893127), UINT32_C(1313000087), UINT32_C(4060178688) },
      { UINT32_C(1096406100), UINT32_C( 134326123), UINT32_C( 972860634), UINT32_C(1701617680) },
      {           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX } },
    { { UINT32_C(4205601379), UINT32_C( 759819821), UINT32_C(1998604887), UINT32_C(1283710433) },
      { UINT32_C(1582597252), UINT32_C( 759819821), UINT32_C(1688601840), UINT32_C(1283710433) },
      {           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX } },
    { { UINT32_C( 285831354), UINT32_C(2626169275), UINT32_C(2330462982), UINT32_C(3236510864) },
      { UINT32_C(2097250444), UINT32_C(2626169275), UINT32_C(2330462982), UINT32_C(2273288909) },
      { UINT32_C(         0),           UINT32_MAX,           UINT32_MAX,           UINT32_MAX } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_x_mm_loadu_epi32(test_vec[i].a);
    simde__m128i b = simde_x_mm_loadu_epi32(test_vec[i].b);
    simde__m128i r = simde_x_mm_cmpge_epu32(a, b);
    simde_test_x86_assert_equal_u32x4(r, simde_x_mm_loadu_epi32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    uint32_t a_[4];
    uint32_t b_[4];

    simde_test_codegen_random_memory(sizeof(a_), HEDLEY_REINTERPRET_CAST(uint8_t*, a_));
    simde_test_codegen_random_memory(sizeof(b_), HEDLEY_REINTERPRET_CAST(uint8_t*, b_));
    for (size_t j = 0 ; j < (sizeof(a_) / sizeof(a_[0])) ; j++)
      if ((simde_test_codegen_rand() & 3) == 0)
        b_[j] = a_[j];

    simde__m128i a = simde_mm_loadu_epi32(a_);
    simde__m128i b = simde_mm_loadu_epi32(b_);
    simde__m128i r = simde_x_mm_cmpge_epu32(a, b);

    simde_test_x86_write_u32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_u32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_u32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_cmpge_epu32_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const uint32_t a[4];
    const uint32_t b[4];
    const simde__mmask8 r;
  } test_vec[] = {
    { { UINT32_C(3924342818), UINT32_C(3539223246), UINT32_C(2564506460), UINT32_C(2610371779) },
      { UINT32_C(3924342818), UINT32_C(3539223246), UINT32_C(3362503962), UINT32_C( 736937993) },
      UINT8_C( 11) },
    { { UINT32_C(1931544854), UINT32_C( 252443724), UINT32_C( 917217816), UINT32_C(2504585409) },
      { UINT32_C(2954923669), UINT32_C(1417186123), UINT32_C(3548341331), UINT32_C(1310889016) },
      UINT8_C(  8) },
    { { UINT32_C(1492765759), UINT32_C( 797877358), UINT32_C( 717608853), UINT32_C(2967135589) },
      { UINT32_C(3271840368), UINT32_C(4002841526), UINT32_C(3040720920), UINT32_C(1000341243) },
      UINT8_C(  8) },
    { { UINT32_C(3530105149), UINT32_C(1576873720), UINT32_C(2198722323), UINT32_C(3762688298) },
      { UINT32_C(3530105149), UINT32_C(1576873720), UINT32_C(3586851338), UINT32_C(3762688298) },
      UINT8_C( 11) },
    { { UINT32_C(3117852838), UINT32_C(2839339903), UINT32_C(2324333301), UINT32_C(4080490846) },
      { UINT32_C(1870960997), UINT32_C(2839339903), UINT32_C( 772756654), UINT32_C(1923529420) },
      UINT8_C( 15) },
    { { UINT32_C(1435199328), UINT32_C(1205802473), UINT32_C(3543864942), UINT32_C(1262665647) },
      { UINT32_C(3162605326), UINT32_C(2817167579), UINT32_C(2887356746), UINT32_C(1262665647) },
      UINT8_C( 12) },
    { { UINT32_C(2631704878), UINT32_C(1735333815), UINT32_C(3836916182), UINT32_C( 346108729) },
      { UINT32_C( 247237572), UINT32_C( 716952860), UINT32_C(3836916182), UINT32_C(2421840482) },
      UINT8_C(  7) },
    { { UINT32_C( 588946253), UINT32_C(2231880780), UINT32_C(3281692927), UINT32_C(1355961908) },
      { UINT32_C(1165659435), UINT32_C(2231880780), UINT32_C(1741186412), UINT32_C(3894080667) },
      UINT8_C(  6) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_x_mm_loadu_epi32(test_vec[i].a);
    simde__m128i b = simde_x_mm_loadu_epi32(test_vec[i].b);
    simde__mmask8 r = simde_mm_cmpge_epu32_mask(a, b);
    simde_assert_equal_mmask8(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    uint32_t a_[4];
    uint32_t b_[4];

    simde_test_codegen_random_memory(sizeof(a_), HEDLEY_REINTERPRET_CAST(uint8_t*, a_));
    simde_test_codegen_random_memory(sizeof(b_), HEDLEY_REINTERPRET_CAST(uint8_t*, b_));
    for (size_t j = 0 ; j < (sizeof(a_) / sizeof(a_[0])) ; j++)
      if ((simde_test_codegen_rand() & 3) == 0)
        b_[j] = a_[j];

    simde__m128i a = simde_mm_loadu_epi32(a_);
    simde__m128i b = simde_mm_loadu_epi32(b_);
    simde__mmask8 r = simde_mm_cmpge_epu32_mask(a, b);

    simde_test_x86_write_u32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_u32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_mask_cmpge_epu32_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k;
    const uint32_t a[4];
    const uint32_t b[4];
    const simde__mmask8 r;
  } test_vec[] = {
    { UINT8_C(179),
      { UINT32_C(   6361600), UINT32_C(4022598587), UINT32_C(2084541777), UINT32_C(4173511202) },
      { UINT32_C( 942722508), UINT32_C(4022598587), UINT32_C(2075507436), UINT32_C(4015505646) },
      UINT8_C(  2) },
    { UINT8_C( 58),
      { UINT32_C(1208253618), UINT32_C(1986691260), UINT32_C( 256009026), UINT32_C(2353101459) },
      { UINT32_C(1208253618), UINT32_C(2210591939), UINT32_C(  56013131), UINT32_C(2353101459) },
      UINT8_C(  8) },
    { UINT8_C(246),
      { UINT32_C(1753059845), UINT32_C(1325108436), UINT32_C(3697772494), UINT32_C(4104141568) },
      { UINT32_C(2923373565), UINT32_C(1565409913), UINT32_C(3697772494), UINT32_C(1089263931) },
      UINT8_C(  4) },
    { UINT8_C(250),
      { UINT32_C( 734301603), UINT32_C( 791388404), UINT32_C(1680613184), UINT32_C(2698893918) },
      { UINT32_C(3382196776), UINT32_C(3489942263), UINT32_C(2688238646), UINT32_C(2698893918) },
      UINT8_C(  8) },
    { UINT8_C(127),
      { UINT32_C(  70986725), UINT32_C( 845324120), UINT32_C(3076194940), UINT32_C(3836617882) },
      { UINT32_C(  70986725), UINT32_C( 845324120), UINT32_C(3076194940), UINT32_C(3836617882) },
      UINT8_C( 15) },
    { UINT8_C(246),
      { UINT32_C(4059885294), UINT32_C(1837871945), UINT32_C(3767890017), UINT32_C(1184563595) },
      { UINT32_C(1100468313), UINT32_C(1172521484), UINT32_C(3366546151), UINT32_C(3846661622) },
      UINT8_C(  6) },
    { UINT8_C( 61),
      { UINT32_C(3512207969), UINT32_C(2707175584), UINT32_C(2751177427), UINT32_C(2075147321) },
      { UINT32_C(2305029407), UINT32_C(2707175584), UINT32_C(3059115378), UINT32_C(2628580155) },
      UINT8_C(  1) },
    { UINT8_C(139),
      { UINT32_C(1829781450), UINT32_C(1990636602), UINT32_C(1502945892), UINT32_C(2968985477) },
      { UINT32_C(  69401247), UINT32_C(1145034832), UINT32_C(2302860165), UINT32_C( 348577865) },
      UINT8_C( 11) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__mmask8 k = test_vec[i].k;
    simde__m128i a = simde_x_mm_loadu_epi32(test_vec[i].a);
    simde__m128i b = simde_x_mm_loadu_epi32(test_vec[i].b);
    simde__mmask8 r = simde_mm_mask_cmpge_epu32_mask(k, a, b);
    simde_assert_equal_mmask8(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    uint32_t a_[4];
    uint32_t b_[4];

    simde_test_codegen_random_memory(sizeof(a_), HEDLEY_REINTERPRET_CAST(uint8_t*, a_));
    simde_test_codegen_random_memory(sizeof(b_), HEDLEY_REINTERPRET_CAST(uint8_t*, b_));
    for (size_t j = 0 ; j < (sizeof(a_) / sizeof(a_[0])) ; j++)
      if ((simde_test_codegen_rand() & 3) == 0)
        b_[j] = a_[j];

    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m128i a = simde_mm_loadu_epi32(a_);
    simde__m128i b = simde_mm_loadu_epi32(b_);
    simde__mmask8 r = simde_mm_mask_cmpge_epu32_mask(k, a, b);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_u32x4(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_u32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_x_mm256_cmpge_epu32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const uint32_t a[8];
    const uint32_t b[8];
    const uint32_t r[8];
  } test_vec[] = {
    { { UINT32_C(1240453159), UINT32_C(2244888678), UINT32_C( 958692927), UINT32_C(2039031969), UINT32_C(1123994983), UINT32_C(4018964495), UINT32_C( 621781070), UINT32_C(1219520801) },
      { UINT32_C(1240453159), UINT32_C( 639918311), UINT32_C(2153728223), UINT32_C(3623479664), UINT32_C(3323656374), UINT32_C(3468011136), UINT32_C(1744094278), UINT32_C(1739564077) },
      {           UINT32_MAX,           UINT32_MAX, UINT32_C(         0), UINT32_C(         0), UINT32_C(         0),           UINT32_MAX, UINT32_C(         0), UINT32_C(         0) } },
    { { UINT32_C(3825316211), UINT32_C(1371273882), UINT32_C(1914164722), UINT32_C(3242314875), UINT32_C(3190306193), UINT32_C( 489019609), UINT32_C(3142134809), UINT32_C(3392969559) },
      { UINT32_C(3825316211), UINT32_C(1371273882), UINT32_C(3147648831), UINT32_C(3242314875), UINT32_C(3966477587), UINT32_C(2517274749), UINT32_C( 324162492), UINT32_C( 987664110) },
      {           UINT32_MAX,           UINT32_MAX, UINT32_C(         0),           UINT32_MAX, UINT32_C(         0), UINT32_C(         0),           UINT32_MAX,           UINT32_MAX } },
    { { UINT32_C(3304180648), UINT32_C(3161484713), UINT32_C(2410273554), UINT32_C( 673624940), UINT32_C(4097603590), UINT32_C(3526236678), UINT32_C(2648068262), UINT32_C(1389561257) },
      { UINT32_C(2048312528), UINT32_C(3161484713), UINT32_C(2410273554), UINT32_C( 673624940), UINT32_C(2022453873), UINT32_C(4081761100), UINT32_C(2648068262), UINT32_C(4127613734) },
      {           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX, UINT32_C(         0),           UINT32_MAX, UINT32_C(         0) } },
    { { UINT32_C( 433287302), UINT32_C(3685861737), UINT32_C(1213415164), UINT32_C(  71015929), UINT32_C(3837316030), UINT32_C(1440464686), UINT32_C(2125351899), UINT32_C(2038647538) },
      { UINT32_C( 613570234), UINT32_C( 486490912), UINT32_C(2053395073), UINT32_C(2927534319), UINT32_C(2593273707), UINT32_C(3522129398), UINT32_C(2874187193), UINT32_C(2720322536) },
      { UINT32_C(         0),           UINT32_MAX, UINT32_C(         0), UINT32_C(         0),           UINT32_MAX, UINT32_C(         0), UINT32_C(         0), UINT32_C(         0) } },
    { { UINT32_C( 133614103), UINT32_C(3602216042), UINT32_C(2708490155), UINT32_C(1853054901), UINT32_C(3843671037), UINT32_C(3230088854), UINT32_C(3993652980), UINT32_C( 728395795) },
      { UINT32_C(2771542075), UINT32_C(2155603924), UINT32_C(3810650926), UINT32_C(1213305931), UINT32_C(3995954007), UINT32_C(2645472425), UINT32_C( 378321154), UINT32_C( 728395795) },
      { UINT32_C(         0),           UINT32_MAX, UINT32_C(         0),           UINT32_MAX, UINT32_C(         0),           UINT32_MAX,           UINT32_MAX,           UINT32_MAX } },
    { { UINT32_C(3161246833), UINT32_C(3087318368), UINT32_C(3517329704), UINT32_C(3899610341), UINT32_C( 939457293), UINT32_C(1201356785), UINT32_C( 208774578), UINT32_C(2626952235) },
      { UINT32_C(1213726952), UINT32_C(3858783422), UINT32_C(3517329704), UINT32_C(3899610341), UINT32_C( 322918434), UINT32_C(1201356785), UINT32_C(2874526592), UINT32_C(2626952235) },
      {           UINT32_MAX, UINT32_C(         0),           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX, UINT32_C(         0),           UINT32_MAX } },
    { { UINT32_C(3137030079), UINT32_C(2428654958), UINT32_C(1168310958), UINT32_C(1569717725), UINT32_C(2953438408), UINT32_C(3112128718), UINT32_C(3949041648), UINT32_C(1869934768) },
      { UINT32_C(3137030079), UINT32_C(1916136388), UINT32_C(3401111789), UINT32_C(1569717725), UINT32_C(2953438408), UINT32_C(1907608961), UINT32_C( 358421605), UINT32_C(1015337221) },
      {           UINT32_MAX,           UINT32_MAX, UINT32_C(         0),           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX } },
    { { UINT32_C(3310366704), UINT32_C(2707650678), UINT32_C( 731623849), UINT32_C(3835448959), UINT32_C(1761212771), UINT32_C( 178552266), UINT32_C(3255797290), UINT32_C(2387117726) },
      { UINT32_C( 726899125), UINT32_C(2707650678), UINT32_C(3890636904), UINT32_C( 432767670), UINT32_C(1182909564), UINT32_C(1800480321), UINT32_C(3255797290), UINT32_C(2614654694) },
      {           UINT32_MAX,           UINT32_MAX, UINT32_C(         0),           UINT32_MAX,           UINT32_MAX, UINT32_C(         0),           UINT32_MAX, UINT32_C(         0) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256i a = simde_mm256_loadu_epi32(test_vec[i].a);
    simde__m256i b = simde_mm256_loadu_epi32(test_vec[i].b);
    simde__m256i r = simde_x_mm256_cmpge_epu32(a, b);
    simde_test_x86_assert_equal_u32x8(r, simde_mm256_loadu_epi32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    uint32_t a_[8];
    uint32_t b_[8];

    simde_test_codegen_random_memory(sizeof(a_), HEDLEY_REINTERPRET_CAST(uint8_t*, a_));
    simde_test_codegen_random_memory(sizeof(b_), HEDLEY_REINTERPRET_CAST(uint8_t*, b_));
    for (size_t j = 0 ; j < (sizeof(a_) / sizeof(a_[0])) ; j++)
      if ((simde_test_codegen_rand() & 3) == 0)
        b_[j] = a_[j];

    simde__m256i a = simde_mm256_loadu_epi32(a_);
    simde__m256i b = simde_mm256_loadu_epi32(b_);
    simde__m256i r = simde_x_mm256_cmpge_epu32(a, b);

    simde_test_x86_write_u32x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_u32x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_u32x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_cmpge_epu32_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const uint32_t a[8];
    const uint32_t b[8];
    const simde__mmask8 r;
  } test_vec[] = {
    { { UINT32_C(3324874442), UINT32_C(3750080581), UINT32_C(2093684796), UINT32_C(1650397168), UINT32_C(2693337172), UINT32_C(1678164158), UINT32_C(1553455685), UINT32_C(3878587677) },
      { UINT32_C(1638816540), UINT32_C(1212166923), UINT32_C(2093684796), UINT32_C(1872569114), UINT32_C(4061079091), UINT32_C(1678164158), UINT32_C( 243854832), UINT32_C(2549462907) },
      UINT16_C(  231) },
    { { UINT32_C(1566386755), UINT32_C(2160917325), UINT32_C( 141745185), UINT32_C(3795110386), UINT32_C( 837860534), UINT32_C(2261313139), UINT32_C(1621409929), UINT32_C( 998378232) },
      { UINT32_C(2174345012), UINT32_C(4227950042), UINT32_C( 855929921), UINT32_C(4078319677), UINT32_C( 837860534), UINT32_C(1995369964), UINT32_C(2799080110), UINT32_C(3504494748) },
      UINT16_C(   48) },
    { { UINT32_C(  55907014), UINT32_C(1056402250), UINT32_C(1587944562), UINT32_C(3084162057), UINT32_C(3260983846), UINT32_C( 982663170), UINT32_C(2605507515), UINT32_C(4240267830) },
      { UINT32_C(3053458284), UINT32_C(4042585982), UINT32_C( 474979091), UINT32_C(1456743215), UINT32_C(3260983846), UINT32_C( 755673970), UINT32_C(2605507515), UINT32_C( 482444976) },
      UINT16_C(  252) },
    { { UINT32_C(2447857506), UINT32_C(1223146362), UINT32_C(1595474157), UINT32_C( 965485483), UINT32_C( 721311098), UINT32_C(1950859227), UINT32_C( 948640128), UINT32_C(1107530720) },
      { UINT32_C(1708452586), UINT32_C(2477636518), UINT32_C(1727252155), UINT32_C( 965485483), UINT32_C(2945359572), UINT32_C(3710113117), UINT32_C( 948640128), UINT32_C( 756160578) },
      UINT16_C(  201) },
    { { UINT32_C(4039323398), UINT32_C(2203345838), UINT32_C(1580392961), UINT32_C(2805683896), UINT32_C(1198936069), UINT32_C(1802799208), UINT32_C( 269682286), UINT32_C(1282232134) },
      { UINT32_C(4039323398), UINT32_C(2511376532), UINT32_C( 720691826), UINT32_C(2805683896), UINT32_C(3901048960), UINT32_C(1062468048), UINT32_C(1179608832), UINT32_C(1282232134) },
      UINT16_C(  173) },
    { { UINT32_C( 771427060), UINT32_C(3110784057), UINT32_C(3852660500), UINT32_C(3911513577), UINT32_C( 321876828), UINT32_C( 457752879), UINT32_C(3986467471), UINT32_C(2965222076) },
      { UINT32_C(4124948668), UINT32_C(2578401413), UINT32_C( 545149239), UINT32_C(3911513577), UINT32_C(1152792597), UINT32_C(2288058105), UINT32_C(1685453992), UINT32_C(1779708846) },
      UINT16_C(  206) },
    { { UINT32_C(2794621023), UINT32_C(1078565675), UINT32_C(3448111060), UINT32_C(2773935613), UINT32_C(2399783905), UINT32_C(3942194686), UINT32_C(1230657551), UINT32_C(3334169703) },
      { UINT32_C( 409751021), UINT32_C(3159930344), UINT32_C(3448111060), UINT32_C(2740379842), UINT32_C(2855428011), UINT32_C(3942194686), UINT32_C(3956731524), UINT32_C(3334169703) },
      UINT16_C(  173) },
    { { UINT32_C(1345916302), UINT32_C(2566164717), UINT32_C(1816274671), UINT32_C(3606697554), UINT32_C( 415354821), UINT32_C(1045983840), UINT32_C(1678028944), UINT32_C(4008478560) },
      { UINT32_C(2168399252), UINT32_C(2769957813), UINT32_C(2870041689), UINT32_C(3606697554), UINT32_C( 957367001), UINT32_C(1165453493), UINT32_C(2024373272), UINT32_C(2556925187) },
      UINT16_C(  136) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256i a = simde_mm256_loadu_epi32(test_vec[i].a);
    simde__m256i b = simde_mm256_loadu_epi32(test_vec[i].b);
    simde__mmask8 r = simde_mm256_cmpge_epu32_mask(a, b);
    simde_assert_equal_mmask16(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    uint32_t a_[8];
    uint32_t b_[8];

    simde_test_codegen_random_memory(sizeof(a_), HEDLEY_REINTERPRET_CAST(uint8_t*, a_));
    simde_test_codegen_random_memory(sizeof(b_), HEDLEY_REINTERPRET_CAST(uint8_t*, b_));
    for (size_t j = 0 ; j < (sizeof(a_) / sizeof(a_[0])) ; j++)
      if ((simde_test_codegen_rand() & 3) == 0)
        b_[j] = a_[j];

    simde__m256i a = simde_mm256_loadu_epi32(a_);
    simde__m256i b = simde_mm256_loadu_epi32(b_);
    simde__mmask8 r = simde_mm256_cmpge_epu32_mask(a, b);

    simde_test_x86_write_u32x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_u32x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_mask_cmpge_epu32_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k;
    const uint32_t a[8];
    const uint32_t b[8];
    const simde__mmask8 r;
  } test_vec[] = {
    { UINT8_C(135),
      { UINT32_C(3286116240), UINT32_C( 196828977), UINT32_C(1464126370), UINT32_C(1268562995), UINT32_C(1002653240), UINT32_C(2530421467), UINT32_C(2835869136), UINT32_C(2967215136) },
      { UINT32_C(1970518595), UINT32_C(3145739801), UINT32_C( 739427577), UINT32_C(3094851456), UINT32_C(3505667061), UINT32_C( 912770917), UINT32_C(3588189876), UINT32_C(3464870794) },
      UINT8_C(  5) },
    { UINT8_C( 95),
      { UINT32_C( 201870685), UINT32_C(    114885), UINT32_C(2087047604), UINT32_C(2788203320), UINT32_C( 909182331), UINT32_C(2225930123), UINT32_C(  95107906), UINT32_C(3800878213) },
      { UINT32_C( 201870685), UINT32_C( 165670741), UINT32_C(4186260673), UINT32_C(1537259232), UINT32_C(1183961531), UINT32_C( 315243984), UINT32_C(4262950520), UINT32_C(1558225730) },
      UINT8_C(  9) },
    { UINT8_C(241),
      { UINT32_C(3527375132), UINT32_C(3935148569), UINT32_C(1773851691), UINT32_C( 350342302), UINT32_C(2253905891), UINT32_C(2411639744), UINT32_C( 156060655), UINT32_C(4268281314) },
      { UINT32_C(1607509830), UINT32_C(1833524545), UINT32_C(3503686449), UINT32_C(3001333711), UINT32_C(2253905891), UINT32_C(3739678703), UINT32_C( 619131714), UINT32_C(1176653824) },
      UINT8_C(145) },
    { UINT8_C(  5),
      { UINT32_C( 868241788), UINT32_C(1909092918), UINT32_C(2724209067), UINT32_C(1004813831), UINT32_C(1983580454), UINT32_C( 510493227), UINT32_C( 376350247), UINT32_C(3355963212) },
      { UINT32_C(2013055041), UINT32_C(1909092918), UINT32_C(2724209067), UINT32_C(2905238663), UINT32_C(2686674549), UINT32_C( 510493227), UINT32_C(2217028663), UINT32_C(1565273372) },
      UINT8_C(  4) },
    { UINT8_C(248),
      { UINT32_C( 143517340), UINT32_C(2004695569), UINT32_C(4015988318), UINT32_C( 153513692), UINT32_C(3240471188), UINT32_C(1068925687), UINT32_C( 307160406), UINT32_C(2534950394) },
      { UINT32_C(1033872684), UINT32_C(1035214303), UINT32_C( 388764475), UINT32_C( 153513692), UINT32_C(3240471188), UINT32_C( 489983175), UINT32_C(1815118450), UINT32_C(4093855944) },
      UINT8_C( 56) },
    { UINT8_C( 32),
      { UINT32_C(2306413110), UINT32_C(2022149939), UINT32_C(4064312165), UINT32_C( 845438383), UINT32_C(3589984397), UINT32_C(2009263828), UINT32_C(  70749983), UINT32_C(3489411737) },
      { UINT32_C(2002351428), UINT32_C(1794170884), UINT32_C(4064312165), UINT32_C( 457031821), UINT32_C(1693464464), UINT32_C(2009263828), UINT32_C(  70749983), UINT32_C(2309637188) },
      UINT8_C( 32) },
    { UINT8_C( 63),
      { UINT32_C(1152273028), UINT32_C(3201616263), UINT32_C(1826830777), UINT32_C( 665724692), UINT32_C(3010169199), UINT32_C( 929887284), UINT32_C(3843762933), UINT32_C(3590740562) },
      { UINT32_C(1152273028), UINT32_C( 921300861), UINT32_C(1017367592), UINT32_C(1650676211), UINT32_C( 253087707), UINT32_C(3091628483), UINT32_C(4271792556), UINT32_C(1607836859) },
      UINT8_C( 23) },
    { UINT8_C(142),
      { UINT32_C(   3294126), UINT32_C(1977324710), UINT32_C( 725215913), UINT32_C(2463625520), UINT32_C( 860738959), UINT32_C(2592845226), UINT32_C(2876792887), UINT32_C( 451575660) },
      { UINT32_C(1746542018), UINT32_C(1977324710), UINT32_C( 277223391), UINT32_C(2463625520), UINT32_C(3721129778), UINT32_C(3564591004), UINT32_C( 595586999), UINT32_C( 809396590) },
      UINT8_C( 14) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__mmask8 k = test_vec[i].k;
    simde__m256i a = simde_mm256_loadu_epi32(test_vec[i].a);
    simde__m256i b = simde_mm256_loadu_epi32(test_vec[i].b);
    simde__mmask8 r = simde_mm256_mask_cmpge_epu32_mask(k, a, b);
    simde_assert_equal_mmask8(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    uint32_t a_[8];
    uint32_t b_[8];

    simde_test_codegen_random_memory(sizeof(a_), HEDLEY_REINTERPRET_CAST(uint8_t*, a_));
    simde_test_codegen_random_memory(sizeof(b_), HEDLEY_REINTERPRET_CAST(uint8_t*, b_));
    for (size_t j = 0 ; j < (sizeof(a_) / sizeof(a_[0])) ; j++)
      if ((simde_test_codegen_rand() & 3) == 0)
        b_[j] = a_[j];

    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m256i a = simde_mm256_loadu_epi32(a_);
    simde__m256i b = simde_mm256_loadu_epi32(b_);
    simde__mmask8 r = simde_mm256_mask_cmpge_epu32_mask(k, a, b);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_u32x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_u32x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_x_mm512_cmpge_epu32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const uint32_t a[16];
    const uint32_t b[16];
    const uint32_t r[16];
  } test_vec[] = {
    { { UINT32_C(1989557529), UINT32_C(3483905759), UINT32_C(1366001146), UINT32_C(3959963644), UINT32_C( 676998334), UINT32_C(3266218858), UINT32_C(2601575972), UINT32_C(2452176505),
        UINT32_C(1527299963), UINT32_C(3895112174), UINT32_C( 859411766), UINT32_C(2468299221), UINT32_C(3619387757), UINT32_C( 681208324), UINT32_C(3401820752), UINT32_C(1683811560) },
      { UINT32_C(1989557529), UINT32_C(3483905759), UINT32_C(1400879998), UINT32_C(1793564412), UINT32_C( 474063384), UINT32_C(3266218858), UINT32_C(1848051846), UINT32_C(2714928117),
        UINT32_C(4265316840), UINT32_C(3895112174), UINT32_C(1951189624), UINT32_C(2178823017), UINT32_C(3801948374), UINT32_C( 681208324), UINT32_C(3401820752), UINT32_C(3531719402) },
      {           UINT32_MAX,           UINT32_MAX, UINT32_C(         0),           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX, UINT32_C(         0),
        UINT32_C(         0),           UINT32_MAX, UINT32_C(         0),           UINT32_MAX, UINT32_C(         0),           UINT32_MAX,           UINT32_MAX, UINT32_C(         0) } },
    { { UINT32_C(1593863780), UINT32_C(1004617552), UINT32_C(2417742246), UINT32_C(3881999507), UINT32_C(3518378840), UINT32_C( 918715727), UINT32_C(3649382545), UINT32_C(3505804908),
        UINT32_C( 338687684), UINT32_C(3696234550), UINT32_C(1970039777), UINT32_C(1616694792), UINT32_C(1362235906), UINT32_C( 562558096), UINT32_C(2298088732), UINT32_C( 660140387) },
      { UINT32_C( 490440935), UINT32_C(2063174552), UINT32_C(4293879287), UINT32_C( 912214836), UINT32_C(4001861982), UINT32_C( 918715727), UINT32_C(2133527068), UINT32_C(3505804908),
        UINT32_C(2751521035), UINT32_C(1679751533), UINT32_C(2472742239), UINT32_C(3066675800), UINT32_C(1362235906), UINT32_C( 562558096), UINT32_C(2298088732), UINT32_C( 660140387) },
      {           UINT32_MAX, UINT32_C(         0), UINT32_C(         0),           UINT32_MAX, UINT32_C(         0),           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,
        UINT32_C(         0),           UINT32_MAX, UINT32_C(         0), UINT32_C(         0),           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX } },
    { { UINT32_C(  10926496), UINT32_C( 729490285), UINT32_C(4125390538), UINT32_C(2553052950), UINT32_C(2961638939), UINT32_C(  77912831), UINT32_C( 157428624), UINT32_C( 466974587),
        UINT32_C(2635824176), UINT32_C(1774753695), UINT32_C( 593472525), UINT32_C(1186761515), UINT32_C(2432058257), UINT32_C(2929039902), UINT32_C(1085798341), UINT32_C(2656865646) },
      { UINT32_C(2822469385), UINT32_C( 454099726), UINT32_C(4125390538), UINT32_C(2367814651), UINT32_C(1545410622), UINT32_C(2014032562), UINT32_C( 414761642), UINT32_C(1488393295),
        UINT32_C(2583753356), UINT32_C(2780173046), UINT32_C(2122380674), UINT32_C( 772514544), UINT32_C(1821059258), UINT32_C(2246350555), UINT32_C(2828901720), UINT32_C(1023431857) },
      { UINT32_C(         0),           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX, UINT32_C(         0), UINT32_C(         0), UINT32_C(         0),
                  UINT32_MAX, UINT32_C(         0), UINT32_C(         0),           UINT32_MAX,           UINT32_MAX,           UINT32_MAX, UINT32_C(         0),           UINT32_MAX } },
    { { UINT32_C( 573254727), UINT32_C( 463933634), UINT32_C(1589855405), UINT32_C(3768370073), UINT32_C(3609031876), UINT32_C(2238578434), UINT32_C(1744339042), UINT32_C(3861289375),
        UINT32_C(2282246854), UINT32_C( 262385506), UINT32_C(2355980019), UINT32_C(4000057642), UINT32_C(2143717757), UINT32_C(3942921097), UINT32_C(1381235891), UINT32_C(1547205014) },
      { UINT32_C( 573254727), UINT32_C( 463933634), UINT32_C(1589855405), UINT32_C(3768370073), UINT32_C(3609031876), UINT32_C(3017454848), UINT32_C(1191587249), UINT32_C(1923301030),
        UINT32_C(1855948927), UINT32_C(4266777616), UINT32_C( 957858182), UINT32_C(4000057642), UINT32_C(2143717757), UINT32_C(2174667728), UINT32_C(2664015096), UINT32_C(1645243619) },
      {           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX, UINT32_C(         0),           UINT32_MAX,           UINT32_MAX,
                  UINT32_MAX, UINT32_C(         0),           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX, UINT32_C(         0), UINT32_C(         0) } },
    { { UINT32_C(2702078929), UINT32_C( 908241982), UINT32_C( 886434641), UINT32_C(1284957528), UINT32_C( 558982805), UINT32_C(1798526088), UINT32_C(2800451438), UINT32_C( 113864245),
        UINT32_C( 547870689), UINT32_C(3562457475), UINT32_C( 218639285), UINT32_C(2790891025), UINT32_C(2378738181), UINT32_C(1828322302), UINT32_C(2937250938), UINT32_C( 884333394) },
      { UINT32_C( 911498418), UINT32_C( 908241982), UINT32_C(3890746326), UINT32_C(1284957528), UINT32_C( 558982805), UINT32_C(1798526088), UINT32_C(2800451438), UINT32_C(4154994757),
        UINT32_C(3006135437), UINT32_C(3562457475), UINT32_C( 218639285), UINT32_C(2746479031), UINT32_C(2542729030), UINT32_C(1432610100), UINT32_C(2479480398), UINT32_C(2609606926) },
      {           UINT32_MAX,           UINT32_MAX, UINT32_C(         0),           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX, UINT32_C(         0),
        UINT32_C(         0),           UINT32_MAX,           UINT32_MAX,           UINT32_MAX, UINT32_C(         0),           UINT32_MAX,           UINT32_MAX, UINT32_C(         0) } },
    { { UINT32_C( 381893602), UINT32_C(1869293088), UINT32_C( 302134532), UINT32_C( 346983846), UINT32_C( 908655686), UINT32_C( 728938713), UINT32_C(2436213420), UINT32_C(2008933269),
        UINT32_C(1066237982), UINT32_C(2863593638), UINT32_C(3569135661), UINT32_C(2229824062), UINT32_C(1085935719), UINT32_C(1969958088), UINT32_C(1795596758), UINT32_C(2732770180) },
      { UINT32_C(3923865411), UINT32_C(2509475688), UINT32_C(2120831040), UINT32_C( 346983846), UINT32_C( 711048289), UINT32_C(3214921193), UINT32_C(4062946670), UINT32_C(2008933269),
        UINT32_C(3851843197), UINT32_C(1165633797), UINT32_C(3569135661), UINT32_C(2538980661), UINT32_C(1807857538), UINT32_C(4062863492), UINT32_C(1795596758), UINT32_C(2732770180) },
      { UINT32_C(         0), UINT32_C(         0), UINT32_C(         0),           UINT32_MAX,           UINT32_MAX, UINT32_C(         0), UINT32_C(         0),           UINT32_MAX,
        UINT32_C(         0),           UINT32_MAX,           UINT32_MAX, UINT32_C(         0), UINT32_C(         0), UINT32_C(         0),           UINT32_MAX,           UINT32_MAX } },
    { { UINT32_C( 414167444), UINT32_C( 369809937), UINT32_C(2458250799), UINT32_C(1433575527), UINT32_C( 726218577), UINT32_C(2592047991), UINT32_C(1123223424), UINT32_C(2038948837),
        UINT32_C(2777822868), UINT32_C(1086102544), UINT32_C(4073865611), UINT32_C( 843531745), UINT32_C(4082995580), UINT32_C(2492390676), UINT32_C(3386278372), UINT32_C(4181941605) },
      { UINT32_C( 414167444), UINT32_C(4242824049), UINT32_C(2112796572), UINT32_C(1433575527), UINT32_C(3681291463), UINT32_C(2592047991), UINT32_C(1123223424), UINT32_C( 937089699),
        UINT32_C(2777822868), UINT32_C(1880998100), UINT32_C(4073865611), UINT32_C( 166435906), UINT32_C(2464438184), UINT32_C(3445642065), UINT32_C(1001256856), UINT32_C(2171766738) },
      {           UINT32_MAX, UINT32_C(         0),           UINT32_MAX,           UINT32_MAX, UINT32_C(         0),           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,
                  UINT32_MAX, UINT32_C(         0),           UINT32_MAX,           UINT32_MAX,           UINT32_MAX, UINT32_C(         0),           UINT32_MAX,           UINT32_MAX } },
    { { UINT32_C(2349398843), UINT32_C(3864619086), UINT32_C( 824313695), UINT32_C(2410910862), UINT32_C(4033041890), UINT32_C(3782584341), UINT32_C(2817486297), UINT32_C(2350712401),
        UINT32_C(1326982401), UINT32_C(3962991245), UINT32_C( 119429241), UINT32_C(3482767852), UINT32_C(1019214374), UINT32_C(2065511842), UINT32_C(4079095202), UINT32_C( 360660755) },
      { UINT32_C(2349398843), UINT32_C(2212403722), UINT32_C( 824313695), UINT32_C(4088275405), UINT32_C(4033041890), UINT32_C(1161317794), UINT32_C(1832409946), UINT32_C(4286757018),
        UINT32_C(1525737296), UINT32_C(1960693377), UINT32_C(2538825674), UINT32_C(2743796104), UINT32_C( 291551854), UINT32_C(1633065223), UINT32_C(2395967220), UINT32_C( 360660755) },
      {           UINT32_MAX,           UINT32_MAX,           UINT32_MAX, UINT32_C(         0),           UINT32_MAX,           UINT32_MAX,           UINT32_MAX, UINT32_C(         0),
        UINT32_C(         0),           UINT32_MAX, UINT32_C(         0),           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i a = simde_mm512_loadu_epi32(test_vec[i].a);
    simde__m512i b = simde_mm512_loadu_epi32(test_vec[i].b);
    simde__m512i r = simde_x_mm512_cmpge_epu32(a, b);
    simde_test_x86_assert_equal_u32x16(r, simde_mm512_loadu_epi32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    uint32_t a_[16];
    uint32_t b_[16];

    simde_test_codegen_random_memory(sizeof(a_), HEDLEY_REINTERPRET_CAST(uint8_t*, a_));
    simde_test_codegen_random_memory(sizeof(b_), HEDLEY_REINTERPRET_CAST(uint8_t*, b_));
    for (size_t j = 0 ; j < (sizeof(a_) / sizeof(a_[0])) ; j++)
      if ((simde_test_codegen_rand() & 3) == 0)
        b_[j] = a_[j];

    simde__m512i a = simde_mm512_loadu_epi32(a_);
    simde__m512i b = simde_mm512_loadu_epi32(b_);
    simde__m512i r = simde_x_mm512_cmpge_epu32(a, b);

    simde_test_x86_write_u32x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_u32x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_u32x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_cmpge_epu32_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const uint32_t a[16];
    const uint32_t b[16];
    const simde__mmask16 r;
  } test_vec[] = {
    { { UINT32_C( 397728546), UINT32_C(1478408998), UINT32_C(3072887695), UINT32_C( 476226706), UINT32_C(1247373219), UINT32_C(3818868521), UINT32_C( 863216225), UINT32_C( 607670530),
        UINT32_C(1379658796), UINT32_C( 933910952), UINT32_C(2012140517), UINT32_C( 445927799), UINT32_C(3798265272), UINT32_C(2646934332), UINT32_C(2832218278), UINT32_C(3050047881) },
      { UINT32_C( 397728546), UINT32_C(1188409953), UINT32_C(4240294789), UINT32_C(3440791828), UINT32_C(2058320702), UINT32_C(3818868521), UINT32_C( 863216225), UINT32_C(3874265329),
        UINT32_C(1379658796), UINT32_C( 709319077), UINT32_C(2012140517), UINT32_C(2499689814), UINT32_C(3798265272), UINT32_C(3462080033), UINT32_C(4278527758), UINT32_C(3050047881) },
      UINT16_C(38755) },
    { { UINT32_C(3708200635), UINT32_C(3685441996), UINT32_C(1239068809), UINT32_C(2259271841), UINT32_C(3977251370), UINT32_C(1590543538), UINT32_C(3076644255), UINT32_C(2810706156),
        UINT32_C(1787072158), UINT32_C(2017800431), UINT32_C(2193694944), UINT32_C( 185101024), UINT32_C( 653793396), UINT32_C(2089141724), UINT32_C(2402543267), UINT32_C(2083961822) },
      { UINT32_C( 954645321), UINT32_C(3417386219), UINT32_C(1239068809), UINT32_C(1362580957), UINT32_C(3977251370), UINT32_C(2563177973), UINT32_C(3076644255), UINT32_C(4248657588),
        UINT32_C(1787072158), UINT32_C(2017800431), UINT32_C(2193694944), UINT32_C(3767074674), UINT32_C( 653793396), UINT32_C(2089141724), UINT32_C(2661410281), UINT32_C(1553718851) },
      UINT16_C(46943) },
    { { UINT32_C(3439905232), UINT32_C(2729297593), UINT32_C(3997191851), UINT32_C( 776657964), UINT32_C(1719642797), UINT32_C( 645426137), UINT32_C(3571826720), UINT32_C(1639416977),
        UINT32_C( 103792717), UINT32_C( 833150086), UINT32_C(1461709099), UINT32_C(1921345989), UINT32_C(3973579795), UINT32_C(2417119344), UINT32_C(2724525841), UINT32_C(3355646843) },
      { UINT32_C(3439905232), UINT32_C( 982677263), UINT32_C(3997191851), UINT32_C( 764876570), UINT32_C(2333765659), UINT32_C(3508219072), UINT32_C(2675146532), UINT32_C(1986557851),
        UINT32_C(3101177513), UINT32_C( 233990829), UINT32_C( 909280284), UINT32_C(3060058779), UINT32_C(3973579795), UINT32_C(3469499818), UINT32_C(2724525841), UINT32_C(1626265270) },
      UINT16_C(54863) },
    { { UINT32_C( 284697189), UINT32_C(1574880384), UINT32_C(3134540804), UINT32_C( 790283042), UINT32_C(3152622474), UINT32_C(3439898686), UINT32_C(1861716906), UINT32_C(3631011699),
        UINT32_C(2062050810), UINT32_C( 769115945), UINT32_C( 921218067), UINT32_C(4184146543), UINT32_C(1941196341), UINT32_C(2839592190), UINT32_C(3138860872), UINT32_C( 160662543) },
      { UINT32_C( 284697189), UINT32_C(1447057987), UINT32_C(3134540804), UINT32_C( 790283042), UINT32_C(1054024511), UINT32_C(3439898686), UINT32_C(1524891211), UINT32_C(1801680514),
        UINT32_C(2062050810), UINT32_C(1183628864), UINT32_C( 280762598), UINT32_C(1232087818), UINT32_C( 780616782), UINT32_C(2740350552), UINT32_C(3138860872), UINT32_C( 160662543) },
      UINT16_C(65023) },
    { { UINT32_C(2587055938), UINT32_C( 859670982), UINT32_C(1931623363), UINT32_C(3843390877), UINT32_C(3983404374), UINT32_C(3463068753), UINT32_C(2102720711), UINT32_C( 948053238),
        UINT32_C(1121105276), UINT32_C(  24448830), UINT32_C(3899955019), UINT32_C(1808632341), UINT32_C(3378068087), UINT32_C(1050133367), UINT32_C(2981948347), UINT32_C(2364096016) },
      { UINT32_C( 835632115), UINT32_C( 372458443), UINT32_C(4026443738), UINT32_C(2841365297), UINT32_C(2087891973), UINT32_C(3463068753), UINT32_C(  82081780), UINT32_C(2828062389),
        UINT32_C(1121105276), UINT32_C(2087324833), UINT32_C(3899955019), UINT32_C(1808632341), UINT32_C(4071948410), UINT32_C(4263866377), UINT32_C(2617379303), UINT32_C(1631884247) },
      UINT16_C(52603) },
    { { UINT32_C(1554885203), UINT32_C(  39506459), UINT32_C(3013565916), UINT32_C(3776242672), UINT32_C( 745851393), UINT32_C(1913291754), UINT32_C(1060032254), UINT32_C(1962550049),
        UINT32_C(3922766030), UINT32_C(1458252666), UINT32_C(2013956744), UINT32_C(1868111470), UINT32_C(3533426408), UINT32_C(1329964625), UINT32_C(2509140852), UINT32_C(1695123863) },
      { UINT32_C(2874071601), UINT32_C(2365733125), UINT32_C( 839191748), UINT32_C( 329342506), UINT32_C(2128952620), UINT32_C(1913291754), UINT32_C( 904748190), UINT32_C( 379254501),
        UINT32_C(3922766030), UINT32_C(1458252666), UINT32_C(4195837903), UINT32_C(4060985798), UINT32_C(3648058102), UINT32_C(1329964625), UINT32_C(2509140852), UINT32_C(3835005460) },
      UINT16_C(25580) },
    { { UINT32_C(   1617379), UINT32_C(2243643883), UINT32_C(2047126374), UINT32_C(2808060213), UINT32_C( 154802671), UINT32_C(3119756085), UINT32_C(2365838916), UINT32_C(2865578183),
        UINT32_C(3635078637), UINT32_C(2505925934), UINT32_C(1158635792), UINT32_C(3924586234), UINT32_C(3186828935), UINT32_C( 511108826), UINT32_C(2209053372), UINT32_C(2804775098) },
      { UINT32_C(2357188446), UINT32_C(2243643883), UINT32_C( 932262205), UINT32_C( 656440735), UINT32_C( 154802671), UINT32_C(3063700217), UINT32_C(2386118612), UINT32_C( 506816448),
        UINT32_C(2074784830), UINT32_C(3452423312), UINT32_C(2617530877), UINT32_C(2059609558), UINT32_C( 855156536), UINT32_C(3605566466), UINT32_C(2623873500), UINT32_C(3350895240) },
      UINT16_C( 6590) },
    { { UINT32_C( 927050805), UINT32_C( 470624576), UINT32_C(3552080458), UINT32_C(1553625613), UINT32_C( 121363671), UINT32_C(1211492581), UINT32_C(1887567770), UINT32_C(3246339212),
        UINT32_C( 569950432), UINT32_C( 876414697), UINT32_C(2231891576), UINT32_C(1071751528), UINT32_C(1648827773), UINT32_C(2678750213), UINT32_C( 118500219), UINT32_C(1086951264) },
      { UINT32_C( 962707792), UINT32_C(1080926151), UINT32_C(4257576085), UINT32_C(2453514005), UINT32_C(3388310724), UINT32_C(2070519552), UINT32_C(1887567770), UINT32_C(1483426568),
        UINT32_C( 569950432), UINT32_C(  18153324), UINT32_C(2231891576), UINT32_C(1159478145), UINT32_C(3205370303), UINT32_C(2678750213), UINT32_C(4188454384), UINT32_C( 357634568) },
      UINT16_C(42944) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i a = simde_mm512_loadu_epi32(test_vec[i].a);
    simde__m512i b = simde_mm512_loadu_epi32(test_vec[i].b);
    simde__mmask16 r = simde_mm512_cmpge_epu32_mask(a, b);
    simde_assert_equal_mmask16(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    uint32_t a_[16];
    uint32_t b_[16];

    simde_test_codegen_random_memory(sizeof(a_), HEDLEY_REINTERPRET_CAST(uint8_t*, a_));
    simde_test_codegen_random_memory(sizeof(b_), HEDLEY_REINTERPRET_CAST(uint8_t*, b_));
    for (size_t j = 0 ; j < (sizeof(a_) / sizeof(a_[0])) ; j++)
      if ((simde_test_codegen_rand() & 3) == 0)
        b_[j] = a_[j];

    simde__m512i a = simde_mm512_loadu_epi32(a_);
    simde__m512i b = simde_mm512_loadu_epi32(b_);
    simde__mmask16 r = simde_mm512_cmpge_epu32_mask(a, b);

    simde_test_x86_write_u32x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_u32x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_mask_cmpge_epu32_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask16 k;
    const uint32_t a[16];
    const uint32_t b[16];
    const simde__mmask16 r;
  } test_vec[] = {
    { UINT16_C( 8372),
      { UINT32_C(3188043021), UINT32_C( 356073252), UINT32_C(  84861180), UINT32_C(3508166642), UINT32_C( 639370307), UINT32_C(3682428931), UINT32_C( 943021490), UINT32_C(1736364890),
        UINT32_C(2770699136), UINT32_C(3216662466), UINT32_C( 834979903), UINT32_C(1778572839), UINT32_C(3868204771), UINT32_C( 952176006), UINT32_C(3312580203), UINT32_C(1244458954) },
      { UINT32_C( 888099442), UINT32_C( 356073252), UINT32_C(2569123697), UINT32_C(2030248854), UINT32_C(3344929857), UINT32_C( 218046625), UINT32_C( 943021490), UINT32_C(3509321311),
        UINT32_C(2770699136), UINT32_C( 921827780), UINT32_C(1204753073), UINT32_C(1992348213), UINT32_C( 138223462), UINT32_C(1444166719), UINT32_C( 204990125), UINT32_C(1244458954) },
      UINT64_C(                  32) },
    { UINT16_C(23504),
      { UINT32_C(2640114824), UINT32_C(2189625674), UINT32_C(4108674838), UINT32_C(3503842203), UINT32_C( 519484837), UINT32_C( 426061380), UINT32_C(2125430683), UINT32_C(2292081408),
        UINT32_C(2720397911), UINT32_C( 438609924), UINT32_C(2853046543), UINT32_C( 293267052), UINT32_C(3744428187), UINT32_C( 972658078), UINT32_C( 347580436), UINT32_C(1671255307) },
      { UINT32_C(1409663568), UINT32_C(2054039915), UINT32_C(4108674838), UINT32_C(4256145250), UINT32_C(2933776144), UINT32_C(2296960628), UINT32_C(2308808574), UINT32_C(1173109493),
        UINT32_C(1738142204), UINT32_C( 438609924), UINT32_C(3857319811), UINT32_C( 293267052), UINT32_C(3982868345), UINT32_C( 326454677), UINT32_C(3785167596), UINT32_C(1227262284) },
      UINT64_C(                2944) },
    { UINT16_C(39931),
      { UINT32_C(1118332620), UINT32_C( 374642041), UINT32_C(2644550006), UINT32_C(2589727722), UINT32_C(2452431792), UINT32_C(2606745196), UINT32_C(4255958278), UINT32_C(1901624485),
        UINT32_C(1555235298), UINT32_C( 208799894), UINT32_C(2477331113), UINT32_C(3727492653), UINT32_C(2507168297), UINT32_C( 657510177), UINT32_C( 975494293), UINT32_C(1001094489) },
      { UINT32_C( 345464702), UINT32_C( 270535271), UINT32_C(1252248092), UINT32_C(4180201680), UINT32_C(1284413483), UINT32_C(4252221288), UINT32_C(4097284251), UINT32_C(2469454357),
        UINT32_C(2829567809), UINT32_C(4005087185), UINT32_C(2477331113), UINT32_C(1465540652), UINT32_C(1621355000), UINT32_C(1130174120), UINT32_C( 975494293), UINT32_C(3092670583) },
      UINT64_C(                6227) },
    { UINT16_C(36766),
      { UINT32_C(1035052000), UINT32_C( 533881063), UINT32_C(2055686435), UINT32_C(1652012545), UINT32_C(2793159863), UINT32_C(1271787923), UINT32_C(2321372306), UINT32_C(3022346708),
        UINT32_C(3824277244), UINT32_C(1510130486), UINT32_C( 248809740), UINT32_C(4151331648), UINT32_C( 463400072), UINT32_C(1868983261), UINT32_C(2499396544), UINT32_C( 424156700) },
      { UINT32_C( 737950197), UINT32_C( 159776765), UINT32_C(3356973448), UINT32_C( 767592613), UINT32_C(1380474484), UINT32_C(1271787923), UINT32_C(2321372306), UINT32_C(3467077081),
        UINT32_C(2633671583), UINT32_C(1510130486), UINT32_C( 248809740), UINT32_C(3115037509), UINT32_C(3674993425), UINT32_C( 308596129), UINT32_C(1637909128), UINT32_C(2251311079) },
      UINT64_C(                3866) },
    { UINT16_C( 2008),
      { UINT32_C(2958835532), UINT32_C(4063421522), UINT32_C(1966742085), UINT32_C(3281986976), UINT32_C(1804290482), UINT32_C(3424063691), UINT32_C(1568110298), UINT32_C( 871110375),
        UINT32_C(2816755797), UINT32_C(1922700844), UINT32_C(3521631280), UINT32_C(2878638073), UINT32_C(2601918416), UINT32_C( 157756719), UINT32_C(2338774948), UINT32_C(1254052853) },
      { UINT32_C(3371344795), UINT32_C(3929705657), UINT32_C(1505436000), UINT32_C(2013548456), UINT32_C(2635340654), UINT32_C(3970333512), UINT32_C(1333267546), UINT32_C(4221187935),
        UINT32_C(2816755797), UINT32_C(1922700844), UINT32_C(3352377374), UINT32_C(4114601351), UINT32_C( 965891056), UINT32_C( 157756719), UINT32_C(2759433541), UINT32_C(2929660884) },
      UINT64_C(                1864) },
    { UINT16_C(58284),
      { UINT32_C( 608217087), UINT32_C(1237485008), UINT32_C(3378288169), UINT32_C(2267806533), UINT32_C(3779496882), UINT32_C(1323384329), UINT32_C( 869447614), UINT32_C(2084219517),
        UINT32_C( 580942417), UINT32_C( 694903551), UINT32_C(1056098553), UINT32_C(1992629699), UINT32_C(2975271848), UINT32_C( 150944074), UINT32_C(1832637168), UINT32_C(3471406460) },
      { UINT32_C( 608217087), UINT32_C(3843578860), UINT32_C(3378288169), UINT32_C(3495815208), UINT32_C(1031976179), UINT32_C(3712319981), UINT32_C(3494543443), UINT32_C(2084219517),
        UINT32_C(2849345213), UINT32_C( 227471081), UINT32_C(1056098553), UINT32_C(1992629699), UINT32_C(4090131205), UINT32_C(1221595124), UINT32_C(2249726864), UINT32_C( 191673934) },
      UINT64_C(               33412) },
    { UINT16_C(30981),
      { UINT32_C(1223860600), UINT32_C(  23298793), UINT32_C(1958195720), UINT32_C(1924594621), UINT32_C(1672799528), UINT32_C(1452386317), UINT32_C(1301221684), UINT32_C( 238042262),
        UINT32_C(3327534045), UINT32_C(2932325029), UINT32_C( 690126444), UINT32_C(2711345273), UINT32_C(3406057662), UINT32_C( 740398840), UINT32_C(1031451047), UINT32_C(3393956589) },
      { UINT32_C(1223860600), UINT32_C(3340851035), UINT32_C(1324434389), UINT32_C(3673132060), UINT32_C(3567645916), UINT32_C(1452386317), UINT32_C(1701739384), UINT32_C( 238042262),
        UINT32_C(3060186970), UINT32_C(3950872342), UINT32_C(3862523594), UINT32_C(3619694843), UINT32_C(2796316188), UINT32_C(2782375213), UINT32_C(1292518696), UINT32_C(1497381374) },
      UINT64_C(                4357) },
    { UINT16_C(50704),
      { UINT32_C(4112921117), UINT32_C(3778694871), UINT32_C(3692706204), UINT32_C(2709721746), UINT32_C( 422424608), UINT32_C(2269849768), UINT32_C(3961955614), UINT32_C( 979708700),
        UINT32_C( 875531357), UINT32_C(1981114842), UINT32_C( 877866914), UINT32_C(1641403969), UINT32_C( 796525446), UINT32_C(1253492011), UINT32_C(2268519530), UINT32_C(1690409735) },
      { UINT32_C(4112921117), UINT32_C(4235767129), UINT32_C( 489737180), UINT32_C( 679347873), UINT32_C( 878180361), UINT32_C(2269849768), UINT32_C(4037981417), UINT32_C( 979708700),
        UINT32_C(3111775327), UINT32_C(1981114842), UINT32_C(1603462589), UINT32_C(4102492395), UINT32_C( 796525446), UINT32_C(3572279275), UINT32_C(2898565980), UINT32_C(1690409735) },
      UINT64_C(               33280) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__mmask16 k = test_vec[i].k;
    simde__m512i a = simde_mm512_loadu_epi32(test_vec[i].a);
    simde__m512i b = simde_mm512_loadu_epi32(test_vec[i].b);
    simde__mmask16 r = simde_mm512_mask_cmpge_epu32_mask(k, a, b);
    simde_assert_equal_mmask16(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    uint32_t a_[16];
    uint32_t b_[16];

    simde_test_codegen_random_memory(sizeof(a_), HEDLEY_REINTERPRET_CAST(uint8_t*, a_));
    simde_test_codegen_random_memory(sizeof(b_), HEDLEY_REINTERPRET_CAST(uint8_t*, b_));
    for (size_t j = 0 ; j < (sizeof(a_) / sizeof(a_[0])) ; j++)
      if ((simde_test_codegen_rand() & 3) == 0)
        b_[j] = a_[j];

    simde__mmask16 k = simde_test_x86_random_mmask16();
    simde__m512i a = simde_mm512_loadu_epi32(a_);
    simde__m512i b = simde_mm512_loadu_epi32(b_);
    simde__mmask16 r = simde_mm512_mask_cmpge_epu32_mask(k, a, b);

    simde_test_x86_write_mmask16(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_u32x16(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_u32x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask64(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_x_mm_cmpge_epi64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int64_t a[2];
    const int64_t b[2];
    const int64_t r[2];
  } test_vec[] = {
    { { -INT64_C( 5413701711126883235), -INT64_C( 7189676535904208844) },
      {  INT64_C( 3528541057930929936), -INT64_C( 4499001035972542309) },
      {  INT64_C(                   0),  INT64_C(                   0) } },
    { {  INT64_C( 1199024682873251021), -INT64_C( 2079181399449670587) },
      {  INT64_C( 8712042758086888176), -INT64_C( 2603441164525876126) },
      {  INT64_C(                   0), -INT64_C(                   1) } },
    { {  INT64_C( 8653246967611995526),  INT64_C( 5381991225391619584) },
      {  INT64_C( 8653246967611995526),  INT64_C( 3914762432369317123) },
      { -INT64_C(                   1), -INT64_C(                   1) } },
    { { -INT64_C( 5326326818828680608), -INT64_C( 8190367801926248902) },
      {  INT64_C( 5985181552393271410),  INT64_C( 6226675041952251779) },
      {  INT64_C(                   0),  INT64_C(                   0) } },
    { {  INT64_C( 3276595000163636172), -INT64_C( 8771438780132075336) },
      {  INT64_C( 3276595000163636172), -INT64_C( 5302270670658104190) },
      { -INT64_C(                   1),  INT64_C(                   0) } },
    { { -INT64_C( 4942557005705745768), -INT64_C(  215290055398174833) },
      { -INT64_C( 3083792146534726399), -INT64_C(  215290055398174833) },
      {  INT64_C(                   0), -INT64_C(                   1) } },
    { {  INT64_C( 1095600381008478844), -INT64_C( 5713042595807950289) },
      {  INT64_C( 5702950127994083538), -INT64_C( 5713042595807950289) },
      {  INT64_C(                   0), -INT64_C(                   1) } },
    { { -INT64_C( 4898352287826608953), -INT64_C( 7453525838769812032) },
      {  INT64_C( 2082349459312377287), -INT64_C(  924197607614952722) },
      {  INT64_C(                   0),  INT64_C(                   0) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_x_mm_loadu_epi64(test_vec[i].a);
    simde__m128i b = simde_x_mm_loadu_epi64(test_vec[i].b);
    simde__m128i r = simde_x_mm_cmpge_epi64(a, b);
    simde_test_x86_assert_equal_i64x2(r, simde_x_mm_loadu_epi64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    int64_t a_[2];
    int64_t b_[2];

    simde_test_codegen_random_memory(sizeof(a_), HEDLEY_REINTERPRET_CAST(uint8_t*, a_));
    simde_test_codegen_random_memory(sizeof(b_), HEDLEY_REINTERPRET_CAST(uint8_t*, b_));
    for (size_t j = 0 ; j < (sizeof(a_) / sizeof(a_[0])) ; j++)
      if ((simde_test_codegen_rand() & 3) == 0)
        b_[j] = a_[j];

    simde__m128i a = simde_mm_loadu_epi64(a_);
    simde__m128i b = simde_mm_loadu_epi64(b_);
    simde__m128i r = simde_x_mm_cmpge_epi64(a, b);

    simde_test_x86_write_i64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_cmpge_epi64_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int64_t a[2];
    const int64_t b[2];
    const simde__mmask8 r;
  } test_vec[] = {
    { {  INT64_C( 5188667230373125871), -INT64_C( 2279717140316963248) },
      {  INT64_C( 2156321821549209789), -INT64_C(  312218369263396365) },
      UINT8_C(  1) },
    { {  INT64_C( 1274778217703325680), -INT64_C( 4300761828966660405) },
      {  INT64_C( 1274778217703325680),  INT64_C( 4544013617341617058) },
      UINT8_C(  1) },
    { {  INT64_C( 5829736466713369648),  INT64_C( 2481537901506055818) },
      { -INT64_C( 4973865648332135585),  INT64_C( 2481537901506055818) },
      UINT8_C(  3) },
    { { -INT64_C( 6102991312497709928), -INT64_C( 6322988996551188308) },
      { -INT64_C( 3160537902540141599), -INT64_C(  335670577216443611) },
      UINT8_C(  0) },
    { {  INT64_C( 2713449874416770427),  INT64_C( 4775295906199153465) },
      {  INT64_C( 2713449874416770427),  INT64_C( 4775295906199153465) },
      UINT8_C(  3) },
    { { -INT64_C( 2963057984803942003),  INT64_C( 4369676323020878996) },
      { -INT64_C( 2963057984803942003),  INT64_C( 5499554575210773050) },
      UINT8_C(  1) },
    { {  INT64_C(  979499888025607810),  INT64_C( 8188310801589931706) },
      {  INT64_C(  979499888025607810),  INT64_C( 5927914480708453311) },
      UINT8_C(  3) },
    { { -INT64_C( 7900671302666403402),  INT64_C(  876624223417378188) },
      { -INT64_C( 7900671302666403402),  INT64_C( 5828563478703130637) },
      UINT8_C(  1) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_x_mm_loadu_epi64(test_vec[i].a);
    simde__m128i b = simde_x_mm_loadu_epi64(test_vec[i].b);
    simde__mmask8 r = simde_mm_cmpge_epi64_mask(a, b);
    simde_assert_equal_mmask8(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    int64_t a_[2];
    int64_t b_[2];

    simde_test_codegen_random_memory(sizeof(a_), HEDLEY_REINTERPRET_CAST(uint8_t*, a_));
    simde_test_codegen_random_memory(sizeof(b_), HEDLEY_REINTERPRET_CAST(uint8_t*, b_));
    for (size_t j = 0 ; j < (sizeof(a_) / sizeof(a_[0])) ; j++)
      if ((simde_test_codegen_rand() & 3) == 0)
        b_[j] = a_[j];

    simde__m128i a = simde_mm_loadu_epi64(a_);
    simde__m128i b = simde_mm_loadu_epi64(b_);
    simde__mmask8 r = simde_mm_cmpge_epi64_mask(a, b);

    simde_test_x86_write_i64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_mask_cmpge_epi64_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k;
    const int64_t a[2];
    const int64_t b[2];
    const simde__mmask8 r;
  } test_vec[] = {
    { UINT8_C(113),
      { -INT64_C( 6584527251079706722), -INT64_C(   40467790019513027) },
      {  INT64_C( 5687492607806777134),  INT64_C( 8616792196076898650) },
      UINT8_C(  0) },
    { UINT8_C(193),
      { -INT64_C( 3761133081519446497), -INT64_C( 2557513290049976441) },
      {  INT64_C( 2457651362403158599), -INT64_C(  209753976479540947) },
      UINT8_C(  0) },
    { UINT8_C(252),
      { -INT64_C(  478060564186207401),  INT64_C( 2122045929627009228) },
      { -INT64_C( 7295178333472897047),  INT64_C( 2122045929627009228) },
      UINT8_C(  0) },
    { UINT8_C(251),
      { -INT64_C( 8671229328474107340), -INT64_C( 6667646768429486558) },
      {  INT64_C( 2594626402425161911), -INT64_C( 3652261413389150343) },
      UINT8_C(  0) },
    { UINT8_C(203),
      { -INT64_C( 6484811385973488256), -INT64_C( 3750401750153182231) },
      { -INT64_C( 5326734292916835876), -INT64_C( 3750401750153182231) },
      UINT8_C(  2) },
    { UINT8_C(117),
      {  INT64_C( 8079617036198410845), -INT64_C( 2043986743729650422) },
      { -INT64_C( 8400170419617380689), -INT64_C( 2043986743729650422) },
      UINT8_C(  1) },
    { UINT8_C( 47),
      { -INT64_C( 6203537153921202156),  INT64_C( 5284853097796679037) },
      {  INT64_C( 7939235697720225811), -INT64_C( 6138385859422296856) },
      UINT8_C(  2) },
    { UINT8_C( 46),
      { -INT64_C( 2332217547218812498), -INT64_C( 1859944557669108688) },
      {  INT64_C( 5132829156955063539), -INT64_C( 2889484492792705523) },
      UINT8_C(  2) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__mmask8 k = test_vec[i].k;
    simde__m128i a = simde_x_mm_loadu_epi64(test_vec[i].a);
    simde__m128i b = simde_x_mm_loadu_epi64(test_vec[i].b);
    simde__mmask8 r = simde_mm_mask_cmpge_epi64_mask(k, a, b);
    simde_assert_equal_mmask8(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    int64_t a_[2];
    int64_t b_[2];

    simde_test_codegen_random_memory(sizeof(a_), HEDLEY_REINTERPRET_CAST(uint8_t*, a_));
    simde_test_codegen_random_memory(sizeof(b_), HEDLEY_REINTERPRET_CAST(uint8_t*, b_));
    for (size_t j = 0 ; j < (sizeof(a_) / sizeof(a_[0])) ; j++)
      if ((simde_test_codegen_rand() & 3) == 0)
        b_[j] = a_[j];

    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m128i a = simde_mm_loadu_epi64(a_);
    simde__m128i b = simde_mm_loadu_epi64(b_);
    simde__mmask8 r = simde_mm_mask_cmpge_epi64_mask(k, a, b);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i64x2(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_x_mm256_cmpge_epi64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int64_t a[4];
    const int64_t b[4];
    const int64_t r[4];
  } test_vec[] = {
    { { -INT64_C( 1809812392385594053),  INT64_C( 8473630397573938694), -INT64_C( 9037984721552467452), -INT64_C( 9144184911774117410) },
      { -INT64_C( 1809812392385594053), -INT64_C( 1345651694353020950),  INT64_C( 5164627569191930210), -INT64_C( 9144184911774117410) },
      { -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1) } },
    { {  INT64_C( 3532922485006123327), -INT64_C( 8265233259980432450),  INT64_C( 1421566123145820016), -INT64_C( 3078792439534943464) },
      {  INT64_C( 4695291246103432367), -INT64_C( 5254665817519142815),  INT64_C( 7679451357592021156), -INT64_C( 8227144279407267993) },
      {  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1) } },
    { {  INT64_C( 4521756924712038105),  INT64_C(  959863462630380334), -INT64_C( 5663133786394074110), -INT64_C( 1798410635541857327) },
      { -INT64_C( 2835330793375454863),  INT64_C(  959863462630380334),  INT64_C( 5072898666480989153), -INT64_C( 2828404155998886710) },
      { -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1) } },
    { {  INT64_C( 4460486142045317058), -INT64_C( 3789743529673530671), -INT64_C( 2787583641678393682), -INT64_C( 5550419425314664704) },
      { -INT64_C( 4063919262460796454),  INT64_C( 7102988824090415985),  INT64_C( 2880943829427069872),  INT64_C( 8781111760385912122) },
      { -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0) } },
    { { -INT64_C( 5239059637249675245), -INT64_C( 6352902865755185918),  INT64_C( 2126996986217287711),  INT64_C( 8730066684474712162) },
      { -INT64_C( 1325947337826251555), -INT64_C( 4229313641416969690),  INT64_C( 1936727853712219205), -INT64_C( 4475862370322516477) },
      {  INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1) } },
    { { -INT64_C( 7712748689387734232),  INT64_C( 1751189285661983812), -INT64_C( 8680523753921041124),  INT64_C( 8266614721571482144) },
      { -INT64_C(  240740583109171162),  INT64_C( 1751189285661983812),  INT64_C( 6569132531855631616), -INT64_C( 8978336670972546390) },
      {  INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1) } },
    { { -INT64_C( 4812470848165953569), -INT64_C( 8493212411705841026),  INT64_C( 2083398337727646795),  INT64_C( 6330995068213612609) },
      { -INT64_C( 4812470848165953569),  INT64_C( 2444835393882475027), -INT64_C( 3822429591694749159),  INT64_C( 4476677852304872272) },
      { -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1) } },
    { {  INT64_C(  806672329973525435),  INT64_C( 8835292745349996204), -INT64_C( 1342703651524406972), -INT64_C( 8394389955972137700) },
      {  INT64_C( 4885713555172210573), -INT64_C( 9145783634768561752),  INT64_C( 3840007085531420472),  INT64_C( 2687012460777273071) },
      {  INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256i a = simde_mm256_loadu_epi64(test_vec[i].a);
    simde__m256i b = simde_mm256_loadu_epi64(test_vec[i].b);
    simde__m256i r = simde_x_mm256_cmpge_epi64(a, b);
    simde_test_x86_assert_equal_i64x4(r, simde_mm256_loadu_epi64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    int64_t a_[4];
    int64_t b_[4];

    simde_test_codegen_random_memory(sizeof(a_), HEDLEY_REINTERPRET_CAST(uint8_t*, a_));
    simde_test_codegen_random_memory(sizeof(b_), HEDLEY_REINTERPRET_CAST(uint8_t*, b_));
    for (size_t j = 0 ; j < (sizeof(a_) / sizeof(a_[0])) ; j++)
      if ((simde_test_codegen_rand() & 3) == 0)
        b_[j] = a_[j];

    simde__m256i a = simde_mm256_loadu_epi64(a_);
    simde__m256i b = simde_mm256_loadu_epi64(b_);
    simde__m256i r = simde_x_mm256_cmpge_epi64(a, b);

    simde_test_x86_write_i64x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i64x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_cmpge_epi64_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int64_t a[4];
    const int64_t b[4];
    const simde__mmask8 r;
  } test_vec[] = {
    { { -INT64_C( 1553801597950053330), -INT64_C(  935480046457748880),  INT64_C( 6675133738829565683), -INT64_C( 4798470435622491131) },
      {  INT64_C( 7112314052840532252), -INT64_C( 7758840547253804922),  INT64_C( 6376561967254436957), -INT64_C( 4798470435622491131) },
      UINT8_C( 14) },
    { { -INT64_C( 4264850420797930518), -INT64_C(  881631713714166972), -INT64_C( 6159640872690695446), -INT64_C( 6351906448927107268) },
      { -INT64_C( 4264850420797930518),  INT64_C( 9051921424920265483), -INT64_C( 5399550449505408732),  INT64_C( 4624529132544737480) },
      UINT8_C(  1) },
    { { -INT64_C( 6421438094748528596), -INT64_C( 2025334045840998310), -INT64_C(  877816869365942910),  INT64_C( 8106226732076695294) },
      { -INT64_C( 6421438094748528596), -INT64_C( 2025334045840998310),  INT64_C( 5489174698692898564), -INT64_C( 1933893087299411595) },
      UINT8_C( 11) },
    { { -INT64_C( 6496035860523874982),  INT64_C( 7980279723324354945), -INT64_C( 4013645917726184419), -INT64_C( 6847143492814277352) },
      { -INT64_C( 6496035860523874982), -INT64_C( 3774446748152822001),  INT64_C( 2051858038081345892), -INT64_C( 3961629225982876129) },
      UINT8_C(  3) },
    { { -INT64_C( 1790084945383902488),  INT64_C( 2586210916021552847), -INT64_C( 5169925097716228676),  INT64_C( 4059340098397881651) },
      { -INT64_C( 1790084945383902488), -INT64_C( 9195733869720194530), -INT64_C( 8013983613385465459), -INT64_C( 3068690815753958687) },
      UINT8_C( 15) },
    { {  INT64_C( 7155786183952887025), -INT64_C( 5817737775148715867),  INT64_C( 5543292697562778842), -INT64_C( 2279086465421846900) },
      {  INT64_C( 7155786183952887025), -INT64_C(  437384496097664787),  INT64_C( 5543292697562778842), -INT64_C(  952752149001541128) },
      UINT8_C(  5) },
    { { -INT64_C( 8637867346661438988),  INT64_C( 2655494563216559674), -INT64_C( 9027642973447675176),  INT64_C( 2943103680132775554) },
      { -INT64_C( 9188422655512271733),  INT64_C(  835903936037715257), -INT64_C( 9027642973447675176),  INT64_C( 7740872885056757520) },
      UINT8_C(  7) },
    { {  INT64_C(  959519448770141346), -INT64_C( 5988393199170098784),  INT64_C(  998674512700460679),  INT64_C( 7196991629024643612) },
      {  INT64_C( 7754511138334631349),  INT64_C( 3548919702374299256),  INT64_C( 2149524349211181209), -INT64_C( 2660404556659667473) },
      UINT8_C(  8) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256i a = simde_mm256_loadu_epi64(test_vec[i].a);
    simde__m256i b = simde_mm256_loadu_epi64(test_vec[i].b);
    simde__mmask8 r = simde_mm256_cmpge_epi64_mask(a, b);
    simde_assert_equal_mmask8(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    int64_t a_[4];
    int64_t b_[4];

    simde_test_codegen_random_memory(sizeof(a_), HEDLEY_REINTERPRET_CAST(uint8_t*, a_));
    simde_test_codegen_random_memory(sizeof(b_), HEDLEY_REINTERPRET_CAST(uint8_t*, b_));
    for (size_t j = 0 ; j < (sizeof(a_) / sizeof(a_[0])) ; j++)
      if ((simde_test_codegen_rand() & 3) == 0)
        b_[j] = a_[j];

    simde__m256i a = simde_mm256_loadu_epi64(a_);
    simde__m256i b = simde_mm256_loadu_epi64(b_);
    simde__mmask8 r = simde_mm256_cmpge_epi64_mask(a, b);

    simde_test_x86_write_i64x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i64x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_mask_cmpge_epi64_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k;
    const int64_t a[4];
    const int64_t b[4];
    const simde__mmask8 r;
  } test_vec[] = {
    { UINT8_C( 46),
      {  INT64_C( 7560940960015976673),  INT64_C( 3424815094089526823), -INT64_C( 3555093101321299192), -INT64_C(  980355283376554722) },
      { -INT64_C( 2647208707044419300),  INT64_C( 5243354626461064551), -INT64_C(  723696529830833794), -INT64_C( 3555109552136282713) },
      UINT8_C(  8) },
    { UINT8_C(113),
      { -INT64_C( 2447377936469909524),  INT64_C( 8923744750240813550), -INT64_C( 3186901342884803466),  INT64_C( 3001267885120328835) },
      { -INT64_C( 2447377936469909524), -INT64_C( 5667169644959188660), -INT64_C( 2673015751500792585), -INT64_C( 5511005241864992482) },
      UINT8_C(  1) },
    { UINT8_C(213),
      {  INT64_C( 7891885730555686544), -INT64_C( 8734316980940294410), -INT64_C( 1182756792746859681),  INT64_C(  895298770426874244) },
      { -INT64_C( 4802285500422083925), -INT64_C( 7668792105418834415), -INT64_C( 1182756792746859681),  INT64_C(  895298770426874244) },
      UINT8_C(  5) },
    { UINT8_C(155),
      { -INT64_C(  266571087638769065), -INT64_C(  868300688820870779), -INT64_C( 8594651061647528016),  INT64_C( 2026877965401770063) },
      { -INT64_C(  266571087638769065),  INT64_C( 3706796210107667807), -INT64_C( 8594651061647528016),  INT64_C( 5326884852233249291) },
      UINT8_C(  1) },
    { UINT8_C( 65),
      { -INT64_C( 3486779382465665853), -INT64_C( 7307389082824486935), -INT64_C( 4833640211480768068), -INT64_C(   64583953664166815) },
      {  INT64_C( 8458240091017975026), -INT64_C( 7307389082824486935), -INT64_C( 1001764419734529146),  INT64_C( 4644490284803146040) },
      UINT8_C(  0) },
    { UINT8_C(128),
      { -INT64_C(  774442663188062157),  INT64_C( 1856284677182913302), -INT64_C( 5619992990462134798),  INT64_C( 5190254623747818042) },
      { -INT64_C( 9037658558865748963), -INT64_C( 2669940886620401724),  INT64_C( 4828859396145365803), -INT64_C( 1212293127209331248) },
      UINT8_C(  0) },
    { UINT8_C( 81),
      { -INT64_C(  786127177861772512),  INT64_C(  890711613687001359), -INT64_C( 4927849853446414219),  INT64_C( 4045888435747654639) },
      { -INT64_C( 7556338105726834002),  INT64_C( 2952750244299424367), -INT64_C( 8625362396108367898),  INT64_C( 4045888435747654639) },
      UINT8_C(  1) },
    { UINT8_C(150),
      {  INT64_C(  917237635368410052),  INT64_C( 7140602162193818280),  INT64_C( 2340658828892020943),  INT64_C( 6358557742640001307) },
      {  INT64_C( 6183187947989172221),  INT64_C( 1383709290838409723),  INT64_C( 8969555693258912140),  INT64_C( 6358557742640001307) },
      UINT8_C(  2) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__mmask8 k = test_vec[i].k;
    simde__m256i a = simde_mm256_loadu_epi64(test_vec[i].a);
    simde__m256i b = simde_mm256_loadu_epi64(test_vec[i].b);
    simde__mmask8 r = simde_mm256_mask_cmpge_epi64_mask(k, a, b);
    simde_assert_equal_mmask8(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    int64_t a_[4];
    int64_t b_[4];

    simde_test_codegen_random_memory(sizeof(a_), HEDLEY_REINTERPRET_CAST(uint8_t*, a_));
    simde_test_codegen_random_memory(sizeof(b_), HEDLEY_REINTERPRET_CAST(uint8_t*, b_));
    for (size_t j = 0 ; j < (sizeof(a_) / sizeof(a_[0])) ; j++)
      if ((simde_test_codegen_rand() & 3) == 0)
        b_[j] = a_[j];

    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m256i a = simde_mm256_loadu_epi64(a_);
    simde__m256i b = simde_mm256_loadu_epi64(b_);
    simde__mmask8 r = simde_mm256_mask_cmpge_epi64_mask(k, a, b);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i64x4(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_x_mm512_cmpge_epi64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int64_t a[8];
    const int64_t b[8];
    const int64_t r[8];
  } test_vec[] = {
    { {  INT64_C( 7570376691530443017),  INT64_C( 3289684820937220757),  INT64_C( 3790105143712752584),  INT64_C( 6006728001215729736),
        -INT64_C( 1964082568733200680), -INT64_C( 3862169822944382129),  INT64_C( 4086318405415258100), -INT64_C( 7407758652632821356) },
      {  INT64_C( 7570376691530443017),  INT64_C( 3289684820937220757),  INT64_C( 3484840098412762932), -INT64_C(  176131085664560588),
        -INT64_C( 8440851634034738030), -INT64_C( 8890640782157093959),  INT64_C( 7276696805074111537), -INT64_C( 2372579735414174880) },
      { -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1),
        -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0) } },
    { {  INT64_C( 5657157878036038830), -INT64_C( 7970219937038128177),  INT64_C(  670957890200583459), -INT64_C( 5292382637261439648),
         INT64_C( 4908421623015813810),  INT64_C( 8296941477544868194), -INT64_C( 2084266664137602459),  INT64_C(  733958476388018800) },
      {  INT64_C( 9040966468863910845), -INT64_C( 3966486670323172560),  INT64_C( 8819989853070678271), -INT64_C( 5912624946983246704),
        -INT64_C(  820404161041413115), -INT64_C( 2144441426221093615), -INT64_C( 8663013674008178623), -INT64_C( 2176537301655504594) },
      {  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),
        -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1) } },
    { {  INT64_C(  365007916690266699),  INT64_C( 7877103885504050388),  INT64_C( 5876729275000537553),  INT64_C( 8652584957862121217),
         INT64_C( 3696529914487806850), -INT64_C( 8658364117993743061), -INT64_C( 5006662785045339376),  INT64_C( 8211981797110368081) },
      {  INT64_C( 9151037725803584876),  INT64_C( 6764055128776965537),  INT64_C( 2708657704864387619), -INT64_C( 7981054581316299812),
        -INT64_C( 7347520565216938698), -INT64_C( 8658364117993743061), -INT64_C( 5006662785045339376),  INT64_C( 8211981797110368081) },
      {  INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1),
        -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1) } },
    { { -INT64_C( 4947749713755829551), -INT64_C( 1596724743150500187),  INT64_C( 4552569379353012936), -INT64_C( 5398453775604317018),
        -INT64_C( 3137727804260016160), -INT64_C(  519045144660089452),  INT64_C( 1378107451162260262), -INT64_C( 7808159061613748983) },
      { -INT64_C( 4947749713755829551),  INT64_C( 4670137271345618598), -INT64_C( 5360338346698561763), -INT64_C( 5398453775604317018),
        -INT64_C( 3137727804260016160),  INT64_C( 3227320681447318895),  INT64_C( 5244532106728958310), -INT64_C( 3163357956354249806) },
      { -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),
        -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0) } },
    { { -INT64_C( 3132674179821162933),  INT64_C( 4673803540222131306), -INT64_C( 6511849417263614438),  INT64_C( 3648487334481559731),
         INT64_C( 5041801614756436661), -INT64_C( 6332704776289329329),  INT64_C( 4451271163736573868), -INT64_C( 3805451426412359913) },
      {  INT64_C( 2219685069888404652),  INT64_C(  791534423647168454), -INT64_C( 6511849417263614438), -INT64_C( 2890802805631690752),
         INT64_C( 9041305793418154123), -INT64_C( 1424599226304596782),  INT64_C( 6226787608523334976), -INT64_C( 3805451426412359913) },
      {  INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1),
         INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1) } },
    { {  INT64_C( 3612906089213076649), -INT64_C( 3625567061968946941), -INT64_C( 8744401234237187219),  INT64_C( 4571628156567183835),
         INT64_C( 8572770613229704659), -INT64_C( 4154713208179919726), -INT64_C( 6446710679661894247),  INT64_C( 7414425354655491087) },
      { -INT64_C( 8785918190524015831), -INT64_C( 3625567061968946941), -INT64_C(     137506180152947),  INT64_C( 4571628156567183835),
        -INT64_C( 3864352698719695643),  INT64_C( 7298493143538495729),  INT64_C( 3145128571375076277),  INT64_C( 7414425354655491087) },
      { -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1),
        -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1) } },
    { { -INT64_C( 1107940233841359263), -INT64_C( 5115743814772499183), -INT64_C( 5183142170272455292), -INT64_C(  688202378524449797),
        -INT64_C( 2885453011856852791),  INT64_C( 5260115047814629676),  INT64_C( 5851216425395523539),  INT64_C( 8710247208417537110) },
      {  INT64_C(  907599435536273915), -INT64_C( 5115743814772499183), -INT64_C( 5725916420873541663),  INT64_C( 1677727324396263713),
         INT64_C( 3421451716713301390),  INT64_C( 5260115047814629676),  INT64_C( 5851216425395523539),  INT64_C( 5408927322476003548) },
      {  INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0),
         INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1) } },
    { {  INT64_C(  369899257160234498), -INT64_C(  414155110797845547), -INT64_C( 2816717112864516383), -INT64_C( 2786959785664077077),
         INT64_C(  333016987749452080),  INT64_C( 2058214554877270648),  INT64_C( 8080481949329294230),  INT64_C( 4608597555171054917) },
      { -INT64_C( 8843811769947656176),  INT64_C( 1759408280097800979),  INT64_C(  875254994404844591), -INT64_C( 1069008005885207844),
        -INT64_C( 8169119077475745010),  INT64_C( 2058214554877270648),  INT64_C( 1819018006161700458), -INT64_C( 7773161807303907507) },
      { -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
        -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i a = simde_mm512_loadu_epi64(test_vec[i].a);
    simde__m512i b = simde_mm512_loadu_epi64(test_vec[i].b);
    simde__m512i r = simde_x_mm512_cmpge_epi64(a, b);
    simde_test_x86_assert_equal_i64x8(r, simde_mm512_loadu_epi64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    int64_t a_[8];
    int64_t b_[8];

    simde_test_codegen_random_memory(sizeof(a_), HEDLEY_REINTERPRET_CAST(uint8_t*, a_));
    simde_test_codegen_random_memory(sizeof(b_), HEDLEY_REINTERPRET_CAST(uint8_t*, b_));
    for (size_t j = 0 ; j < (sizeof(a_) / sizeof(a_[0])) ; j++)
      if ((simde_test_codegen_rand() & 3) == 0)
        b_[j] = a_[j];

    simde__m512i a = simde_mm512_loadu_epi64(a_);
    simde__m512i b = simde_mm512_loadu_epi64(b_);
    simde__m512i r = simde_x_mm512_cmpge_epi64(a, b);

    simde_test_x86_write_i64x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i64x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_cmpge_epi64_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int64_t a[8];
    const int64_t b[8];
    const simde__mmask8 r;
  } test_vec[] = {
    { { -INT64_C( 2070406487669628552),  INT64_C( 6033198852448188866), -INT64_C( 8771555583276337456), -INT64_C( 6247784398762580305),
         INT64_C( 5421483137630060159), -INT64_C( 6091085634613302848), -INT64_C( 6098927215402166741), -INT64_C( 5361333910066565601) },
      { -INT64_C( 4700505673719400200),  INT64_C( 4011118774330795803), -INT64_C( 8771555583276337456), -INT64_C( 5152602031313986136),
         INT64_C( 5421483137630060159),  INT64_C( 5377004911177899809), -INT64_C( 6098927215402166741), -INT64_C( 5361333910066565601) },
      UINT8_C(215) },
    { { -INT64_C( 3063590015048229106), -INT64_C( 4372310828088001350),  INT64_C( 2492401349229931920), -INT64_C( 8916306517105278411),
         INT64_C( 5745159163347787721), -INT64_C( 3246098094953558599),  INT64_C( 3764134979146192977),  INT64_C( 2071041554726676674) },
      { -INT64_C( 3063590015048229106), -INT64_C( 8120843085131959426),  INT64_C( 2492401349229931920), -INT64_C( 8916306517105278411),
         INT64_C( 5745159163347787721),  INT64_C( 5216882201505415066), -INT64_C(  866871744191073277),  INT64_C( 2071041554726676674) },
      UINT8_C(223) },
    { {  INT64_C( 1631201269732211482), -INT64_C( 1778412233284305250),  INT64_C( 2892346289493979719), -INT64_C( 1671051179763429497),
         INT64_C( 4626915955823893559), -INT64_C( 1449619988363544355), -INT64_C(  186057200457070430), -INT64_C( 4479664861571625186) },
      {  INT64_C( 1631201269732211482), -INT64_C( 3196899116407668300), -INT64_C( 5003077546601513827), -INT64_C( 1671051179763429497),
         INT64_C( 4626915955823893559), -INT64_C( 1449619988363544355), -INT64_C(  244866230786263450), -INT64_C( 4479664861571625186) },
         UINT8_MAX },
    { {  INT64_C( 6848597962113556279),  INT64_C( 5737131772028018935), -INT64_C( 3772983710966437864),  INT64_C( 7018232378220900620),
         INT64_C(  923820387530613988), -INT64_C( 5975650444467555632), -INT64_C(  649815498661194527),  INT64_C( 8558449954491867318) },
      {  INT64_C( 6848597962113556279), -INT64_C( 4499318267031935411),  INT64_C( 7710141345086656713),  INT64_C( 7018232378220900620),
         INT64_C(  923820387530613988), -INT64_C(  911841306946374473),  INT64_C( 4750447914218441165), -INT64_C( 7640472553337525139) },
      UINT8_C(155) },
    { { -INT64_C( 1153370640605693277),  INT64_C( 1132080221335667828), -INT64_C( 1465132411842238730), -INT64_C( 5706615493297889979),
        -INT64_C( 6986169154367274087),  INT64_C( 2697355968751665768),  INT64_C( 3665890805737483329),  INT64_C( 7027787086634162021) },
      { -INT64_C( 1153370640605693277),  INT64_C( 1132080221335667828),  INT64_C(  108886406931043118), -INT64_C( 4220331205228729618),
        -INT64_C( 6986169154367274087),  INT64_C( 2697355968751665768),  INT64_C( 3665890805737483329), -INT64_C( 5751750833037396153) },
      UINT8_C(243) },
    { {  INT64_C( 4710425771568093719), -INT64_C( 5388253254782416154),  INT64_C( 5700295880660371918), -INT64_C( 6342197767696188539),
         INT64_C( 1631127906549316429), -INT64_C( 2532615895400845786),  INT64_C( 5715459121382704668),  INT64_C( 7242361527322268809) },
      {  INT64_C( 4710425771568093719), -INT64_C( 1713807894409840568), -INT64_C( 4488895985528111206), -INT64_C( 8643925628399479617),
         INT64_C( 5151605598035325941), -INT64_C( 2532615895400845786), -INT64_C( 4505019085183924778),  INT64_C( 7242361527322268809) },
      UINT8_C(237) },
    { { -INT64_C( 6849446161879530233),  INT64_C( 2764540273332043607), -INT64_C( 1949062962900069623),  INT64_C(  293241014071293751),
         INT64_C( 7480339412603055661),  INT64_C( 1080262500340732740),  INT64_C( 3883464065613460848), -INT64_C( 2560484415599595700) },
      { -INT64_C( 3218663528601546274), -INT64_C( 5052773796691313656), -INT64_C( 1949062962900069623),  INT64_C(  293241014071293751),
         INT64_C( 5711769694809244895),  INT64_C( 1080262500340732740),  INT64_C( 3883464065613460848), -INT64_C( 2560484415599595700) },
      UINT8_C(254) },
    { { -INT64_C( 8942631822463564757), -INT64_C( 4201418977405660276), -INT64_C( 5114839028479455467),  INT64_C( 3271557684383008634),
         INT64_C( 7267829963420562845), -INT64_C( 6372503786117725673),  INT64_C( 3765978758849136146),  INT64_C( 2489876541376326684) },
      { -INT64_C( 8942631822463564757), -INT64_C( 4201418977405660276), -INT64_C( 5114839028479455467), -INT64_C( 3566541239550304114),
         INT64_C( 7267829963420562845), -INT64_C( 6372503786117725673), -INT64_C( 4856433806884225568),  INT64_C( 2489876541376326684) },
         UINT8_MAX }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i a = simde_mm512_loadu_epi64(test_vec[i].a);
    simde__m512i b = simde_mm512_loadu_epi64(test_vec[i].b);
    simde__mmask8 r = simde_mm512_cmpge_epi64_mask(a, b);
    simde_assert_equal_mmask8(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    int64_t a_[8];
    int64_t b_[8];

    simde_test_codegen_random_memory(sizeof(a_), HEDLEY_REINTERPRET_CAST(uint8_t*, a_));
    simde_test_codegen_random_memory(sizeof(b_), HEDLEY_REINTERPRET_CAST(uint8_t*, b_));
    for (size_t j = 0 ; j < 8 ; j++)
      if (!(simde_test_codegen_random_i64() & 1))
        a_[j] = b_[j];

    simde__m512i a = simde_mm512_loadu_epi64(a_);
    simde__m512i b = simde_mm512_loadu_epi64(b_);
    simde__mmask8 r = simde_mm512_cmpge_epi64_mask(a, b);

    simde_test_x86_write_i64x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i64x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_mask_cmpge_epi64_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k;
    const int64_t a[8];
    const int64_t b[8];
    const simde__mmask8 r;
  } test_vec[] = {
    { UINT8_C(209),
      { -INT64_C( 6575068657072266552),  INT64_C( 4013434222016497330), -INT64_C( 8548118326975907316),  INT64_C( 8183997823267763076),
         INT64_C( 6273992175176055688),  INT64_C( 7104768532289929528), -INT64_C( 5646205320154303889),  INT64_C(  266591417202906522) },
      { -INT64_C( 7992059370065123814),  INT64_C( 4537812918492961089), -INT64_C( 9034786100595834434),  INT64_C( 7174366463707588882),
         INT64_C( 6273992175176055688),  INT64_C( 5034552175911107281), -INT64_C( 5646205320154303889),  INT64_C( 6387620748358566648) },
      UINT8_C( 81) },
    { UINT8_C(111),
      { -INT64_C( 8726958688954715651),  INT64_C( 2348064657815265231),  INT64_C( 4943179416380037331),  INT64_C( 2029177430987799426),
        -INT64_C( 1270772521671818873), -INT64_C( 1428729495098222417), -INT64_C( 4846793239176247302), -INT64_C( 7029206327740858313) },
      { -INT64_C( 2464363797335908417),  INT64_C( 8498035739473893610),  INT64_C( 4943179416380037331), -INT64_C( 6530556018687301463),
        -INT64_C( 8018570463250426964), -INT64_C( 1428729495098222417), -INT64_C( 2781886260586838381),  INT64_C( 4176516411458961257) },
      UINT8_C( 44) },
    { UINT8_C( 12),
      { -INT64_C( 5284835417757542766),  INT64_C( 3231261734394529964), -INT64_C( 7702860583741675688),  INT64_C( 1892023704047486981),
        -INT64_C( 7760027718238901913),  INT64_C( 5438336189025367263),  INT64_C( 2932321791485030656),  INT64_C( 5250700056402202683) },
      { -INT64_C( 4386735952901435996), -INT64_C(  315101360870645406),  INT64_C( 2883651684860967609),  INT64_C( 1892023704047486981),
         INT64_C( 8322238771167290327), -INT64_C( 3413614066788692311),  INT64_C( 6608945048697223330),  INT64_C( 4955112350321845166) },
      UINT8_C(  8) },
    { UINT8_C( 38),
      {  INT64_C( 6580309514420159303),  INT64_C( 4323235294646952096), -INT64_C( 2854739368375359667),  INT64_C( 3780750916656655853),
         INT64_C( 3453475380024089583),  INT64_C( 5686216749242960150),  INT64_C( 7920446909963276903),  INT64_C( 6026748019143637122) },
      { -INT64_C( 3194790749406918678),  INT64_C( 1219185400858356124),  INT64_C( 3884933792621895421), -INT64_C(  270700785302191482),
        -INT64_C( 7899561177117285169),  INT64_C( 5116681035822653512),  INT64_C( 7920446909963276903),  INT64_C( 6592957097143715184) },
      UINT8_C( 34) },
    { UINT8_C(149),
      {  INT64_C( 8256145186417101759), -INT64_C( 1901539801125486723), -INT64_C( 8075572483040666109),  INT64_C( 4188905638352513972),
        -INT64_C( 4033070998238227897),  INT64_C( 1093124613165264038),  INT64_C( 2223057936730922413), -INT64_C( 4790920199373489458) },
      {  INT64_C( 8256145186417101759),  INT64_C( 1233802005419185157), -INT64_C( 4144098940266342923), -INT64_C( 6926093320673323090),
        -INT64_C( 8047764809552743894), -INT64_C( 3899623782060360596),  INT64_C( 2131230047789923285),  INT64_C( 6894485686540411453) },
      UINT8_C( 17) },
    { UINT8_C( 27),
      {  INT64_C( 6387567845343640336), -INT64_C( 6395142235670220196),  INT64_C( 7177395286356741669), -INT64_C(  382016612990813437),
        -INT64_C( 6089588735407940599),  INT64_C( 5588382373049615585), -INT64_C( 6369725245391869638), -INT64_C( 3273987420436824917) },
      {  INT64_C( 6387567845343640336), -INT64_C( 6395142235670220196), -INT64_C( 6930139377291443064), -INT64_C( 7076627204981549522),
        -INT64_C( 1038911804270525921),  INT64_C( 5588382373049615585), -INT64_C( 4297332797590510392), -INT64_C( 3273987420436824917) },
      UINT8_C( 11) },
    { UINT8_C(135),
      {  INT64_C( 8723807916393646149), -INT64_C( 4873224461424275924),  INT64_C( 7592657604444409744), -INT64_C( 7784228625124827672),
        -INT64_C( 5209558062182147547),  INT64_C( 2784368709940134588),  INT64_C( 2892887938482091999),  INT64_C( 2979973399914555000) },
      { -INT64_C( 2190132446079273384),  INT64_C( 4365796037345431001),  INT64_C( 7592657604444409744), -INT64_C( 1697569471584300732),
        -INT64_C( 4305045508150471364), -INT64_C( 7327978410218353996), -INT64_C( 6345983766456089188), -INT64_C( 2624929393919682021) },
      UINT8_C(133) },
    { UINT8_C(244),
      {  INT64_C( 2269982273795165209),  INT64_C( 1313407837233383829), -INT64_C( 3049344353417698280), -INT64_C( 3544870893159460919),
        -INT64_C(  461001704210314078),  INT64_C( 6720868476083772603),  INT64_C( 5513396069940524599), -INT64_C( 2894300305127432365) },
      {  INT64_C( 8325728238115653421),  INT64_C( 3219207272498897673),  INT64_C( 6463331796801716962), -INT64_C( 3544870893159460919),
        -INT64_C( 3248803111423910979),  INT64_C( 6720868476083772603),  INT64_C( 7615716627811896912),  INT64_C(  374823820463903162) },
      UINT8_C( 48) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__mmask8 k = test_vec[i].k;
    simde__m512i a = simde_mm512_loadu_epi64(test_vec[i].a);
    simde__m512i b = simde_mm512_loadu_epi64(test_vec[i].b);
    simde__mmask8 r = simde_mm512_mask_cmpge_epi64_mask(k, a, b);
    simde_assert_equal_mmask8(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    int64_t a_[8];
    int64_t b_[8];

    simde_test_codegen_random_memory(sizeof(a_), HEDLEY_REINTERPRET_CAST(uint8_t*, a_));
    simde_test_codegen_random_memory(sizeof(b_), HEDLEY_REINTERPRET_CAST(uint8_t*, b_));
    for (size_t j = 0 ; j < (sizeof(a_) / sizeof(a_[0])) ; j++)
      if ((simde_test_codegen_rand() & 3) == 0)
        b_[j] = a_[j];

    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m512i a = simde_mm512_loadu_epi64(a_);
    simde__m512i b = simde_mm512_loadu_epi64(b_);
    simde__mmask8 r = simde_mm512_mask_cmpge_epi64_mask(k, a, b);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i64x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_x_mm_cmpge_epu64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const uint64_t a[2];
    const uint64_t b[2];
    const uint64_t r[2];
  } test_vec[] = {
    { { UINT64_C(16093839016326110779), UINT64_C( 8124269835523436432) },
      { UINT64_C(16093839016326110779), UINT64_C( 8124269835523436432) },
      {                     UINT64_MAX,                     UINT64_MAX } },
    { { UINT64_C( 2314953929543021848), UINT64_C(11980600780732596068) },
      { UINT64_C(17205609296858158488), UINT64_C(14107412221314505526) },
      { UINT64_C(                   0), UINT64_C(                   0) } },
    { { UINT64_C(15623928853367644724), UINT64_C(14723415526180962939) },
      { UINT64_C( 3855254737132114719), UINT64_C( 2576581182599539556) },
      {                     UINT64_MAX,                     UINT64_MAX } },
    { { UINT64_C( 1445242718108106872), UINT64_C(12208775095051188039) },
      { UINT64_C( 1445242718108106872), UINT64_C( 7227231683006417366) },
      {                     UINT64_MAX,                     UINT64_MAX } },
    { { UINT64_C(16011748811242315952), UINT64_C( 7521103879243987139) },
      { UINT64_C(  119038582845522947), UINT64_C(12043842527716545151) },
      {                     UINT64_MAX, UINT64_C(                   0) } },
    { { UINT64_C(12399239379735717733), UINT64_C(12558291527392047907) },
      { UINT64_C(12399239379735717733), UINT64_C( 2021216518760173793) },
      {                     UINT64_MAX,                     UINT64_MAX } },
    { { UINT64_C(12032299506703596214), UINT64_C(15806097871648495572) },
      { UINT64_C(12032299506703596214), UINT64_C(15806097871648495572) },
      {                     UINT64_MAX,                     UINT64_MAX } },
    { { UINT64_C( 3322935814565715595), UINT64_C( 3422958088326046348) },
      { UINT64_C( 3322935814565715595), UINT64_C( 3422958088326046348) },
      {                     UINT64_MAX,                     UINT64_MAX } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_x_mm_loadu_epi64(test_vec[i].a);
    simde__m128i b = simde_x_mm_loadu_epi64(test_vec[i].b);
    simde__m128i r = simde_x_mm_cmpge_epu64(a, b);
    simde_test_x86_assert_equal_u64x2(r, simde_x_mm_loadu_epi64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    uint64_t a_[2];
    uint64_t b_[2];

    simde_test_codegen_random_memory(sizeof(a_), HEDLEY_REINTERPRET_CAST(uint8_t*, a_));
    simde_test_codegen_random_memory(sizeof(b_), HEDLEY_REINTERPRET_CAST(uint8_t*, b_));
    for (size_t j = 0 ; j < (sizeof(a_) / sizeof(a_[0])) ; j++)
      if ((simde_test_codegen_rand() & 3) == 0)
        b_[j] = a_[j];

    simde__m128i a = simde_mm_loadu_epi64(a_);
    simde__m128i b = simde_mm_loadu_epi64(b_);
    simde__m128i r = simde_x_mm_cmpge_epu64(a, b);

    simde_test_x86_write_u64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_u64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_u64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_cmpge_epu64_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const uint64_t a[2];
    const uint64_t b[2];
    const simde__mmask8 r;
  } test_vec[] = {
    { { UINT64_C( 2918548540063498496), UINT64_C(17352060324935810731) },
      { UINT64_C( 2918548540063498496), UINT64_C(17352060324935810731) },
      UINT8_C(  3) },
    { { UINT64_C(16367779724344019175), UINT64_C(15019748866105349172) },
      { UINT64_C( 2215711382947317265), UINT64_C(15019748866105349172) },
      UINT8_C(  3) },
    { { UINT64_C(17571344980922877599), UINT64_C(  842140894052343544) },
      { UINT64_C(17571344980922877599), UINT64_C(14054794510615178489) },
      UINT8_C(  1) },
    { { UINT64_C(15942947243250817417), UINT64_C(14934802757272530722) },
      { UINT64_C(17054288024290382630), UINT64_C(14934802757272530722) },
      UINT8_C(  2) },
    { { UINT64_C( 5309968852701588608), UINT64_C( 9274463571429665438) },
      { UINT64_C(15043383104477613637), UINT64_C(17822140618056816950) },
      UINT8_C(  0) },
    { { UINT64_C(15137557626000911288), UINT64_C(10254021311501536586) },
      { UINT64_C(12586040713241921421), UINT64_C(15082350747349950973) },
      UINT8_C(  1) },
    { { UINT64_C( 1070111482701866809), UINT64_C(15609254710042290123) },
      { UINT64_C( 5355464566970120071), UINT64_C( 8441719578711648959) },
      UINT8_C(  2) },
    { { UINT64_C( 6521846341947466689), UINT64_C( 4678984719857153880) },
      { UINT64_C( 8144036312604644680), UINT64_C( 8596349922951053435) },
      UINT8_C(  0) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_x_mm_loadu_epi64(test_vec[i].a);
    simde__m128i b = simde_x_mm_loadu_epi64(test_vec[i].b);
    simde__mmask8 r = simde_mm_cmpge_epu64_mask(a, b);
    simde_assert_equal_mmask8(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    uint64_t a_[2];
    uint64_t b_[2];

    simde_test_codegen_random_memory(sizeof(a_), HEDLEY_REINTERPRET_CAST(uint8_t*, a_));
    simde_test_codegen_random_memory(sizeof(b_), HEDLEY_REINTERPRET_CAST(uint8_t*, b_));
    for (size_t j = 0 ; j < (sizeof(a_) / sizeof(a_[0])) ; j++)
      if ((simde_test_codegen_rand() & 3) == 0)
        b_[j] = a_[j];

    simde__m128i a = simde_mm_loadu_epi64(a_);
    simde__m128i b = simde_mm_loadu_epi64(b_);
    simde__mmask8 r = simde_mm_cmpge_epu64_mask(a, b);

    simde_test_x86_write_u64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_u64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_mask_cmpge_epu64_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k;
    const uint64_t a[2];
    const uint64_t b[2];
    const simde__mmask8 r;
  } test_vec[] = {
    { UINT8_C(176),
      { UINT64_C(11352266300081746450), UINT64_C( 5248942729709574738) },
      { UINT64_C(11303243590772570008), UINT64_C( 2080939048733152210) },
      UINT8_C(  0) },
    { UINT8_C(220),
      { UINT64_C(15063860771517316283), UINT64_C( 4624177172606094127) },
      { UINT64_C( 5557354177436146824), UINT64_C( 9549337419441839034) },
      UINT8_C(  0) },
    { UINT8_C( 13),
      { UINT64_C(18182427550065252058), UINT64_C( 7058693387832571032) },
      { UINT64_C( 3976005982177306291), UINT64_C( 7117235007847742565) },
      UINT8_C(  1) },
    { UINT8_C( 12),
      { UINT64_C( 1477204026685760603), UINT64_C(13201370710759048274) },
      { UINT64_C( 1477204026685760603), UINT64_C(12977002861935494312) },
      UINT8_C(  0) },
    { UINT8_C(154),
      { UINT64_C(10706060033244565108), UINT64_C(11233271956621509448) },
      { UINT64_C(13173350710175073486), UINT64_C( 1242509283393692797) },
      UINT8_C(  2) },
    { UINT8_C(216),
      { UINT64_C(11678520626056616630), UINT64_C( 7493579088167611331) },
      { UINT64_C(11678520626056616630), UINT64_C(10296595270566150713) },
      UINT8_C(  0) },
    { UINT8_C(164),
      { UINT64_C(11817329168090825175), UINT64_C(12587495814443665680) },
      { UINT64_C(11817329168090825175), UINT64_C(12587495814443665680) },
      UINT8_C(  0) },
    { UINT8_C(110),
      { UINT64_C(12811946242819173001), UINT64_C( 3100074089388216813) },
      { UINT64_C(12811946242819173001), UINT64_C( 4807247050912658918) },
      UINT8_C(  0) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__mmask8 k = test_vec[i].k;
    simde__m128i a = simde_x_mm_loadu_epi64(test_vec[i].a);
    simde__m128i b = simde_x_mm_loadu_epi64(test_vec[i].b);
    simde__mmask8 r = simde_mm_mask_cmpge_epu64_mask(k, a, b);
    simde_assert_equal_mmask8(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    uint64_t a_[2];
    uint64_t b_[2];

    simde_test_codegen_random_memory(sizeof(a_), HEDLEY_REINTERPRET_CAST(uint8_t*, a_));
    simde_test_codegen_random_memory(sizeof(b_), HEDLEY_REINTERPRET_CAST(uint8_t*, b_));
    for (size_t j = 0 ; j < (sizeof(a_) / sizeof(a_[0])) ; j++)
      if ((simde_test_codegen_rand() & 3) == 0)
        b_[j] = a_[j];

    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m128i a = simde_mm_loadu_epi64(a_);
    simde__m128i b = simde_mm_loadu_epi64(b_);
    simde__mmask8 r = simde_mm_mask_cmpge_epu64_mask(k, a, b);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_u64x2(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_u64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_x_mm256_cmpge_epu64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const uint64_t a[4];
    const uint64_t b[4];
    const uint64_t r[4];
  } test_vec[] = {
    { { UINT64_C( 1097978310966412842), UINT64_C( 1756550201089517763), UINT64_C(16857605451591315770), UINT64_C(15179937420450707704) },
      { UINT64_C( 8431560606216021375), UINT64_C( 1756550201089517763), UINT64_C(  321597309435039413), UINT64_C(10141517082387223875) },
      { UINT64_C(                   0),                     UINT64_MAX,                     UINT64_MAX,                     UINT64_MAX } },
    { { UINT64_C( 3825624922860126807), UINT64_C(17753090679787756317), UINT64_C(17896805648347878704), UINT64_C(16027753105726905121) },
      { UINT64_C( 3825624922860126807), UINT64_C( 3898722023448994107), UINT64_C(17896805648347878704), UINT64_C(16027753105726905121) },
      {                     UINT64_MAX,                     UINT64_MAX,                     UINT64_MAX,                     UINT64_MAX } },
    { { UINT64_C(12399096586360407473), UINT64_C(10459481776733695355), UINT64_C( 9033764768653175442), UINT64_C( 3047317884080416558) },
      { UINT64_C(18146737374679732100), UINT64_C(10459481776733695355), UINT64_C(13481218229444095080), UINT64_C( 2914219991104054735) },
      { UINT64_C(                   0),                     UINT64_MAX, UINT64_C(                   0),                     UINT64_MAX } },
    { { UINT64_C( 2567126417085835441), UINT64_C( 9494575333693246145), UINT64_C(16321140974333909353), UINT64_C( 3106740997750190522) },
      { UINT64_C( 2567126417085835441), UINT64_C( 7644573401691488157), UINT64_C( 7347099059777393877), UINT64_C(16265504721049026580) },
      {                     UINT64_MAX,                     UINT64_MAX,                     UINT64_MAX, UINT64_C(                   0) } },
    { { UINT64_C( 5688131324038467008), UINT64_C(  374180686669022793), UINT64_C( 9593224832966338430), UINT64_C( 9829296163380452265) },
      { UINT64_C( 5688131324038467008), UINT64_C(12050052781620448731), UINT64_C( 5275787329447568522), UINT64_C(14161590236826279479) },
      {                     UINT64_MAX, UINT64_C(                   0),                     UINT64_MAX, UINT64_C(                   0) } },
    { { UINT64_C(10904515893093376067), UINT64_C(15222018527855546114), UINT64_C( 6849068026535114709), UINT64_C( 5099393107290789338) },
      { UINT64_C(15300340723361329744), UINT64_C(16235372256692376393), UINT64_C(  904372718620535576), UINT64_C(12743281906581680271) },
      { UINT64_C(                   0), UINT64_C(                   0),                     UINT64_MAX, UINT64_C(                   0) } },
    { { UINT64_C( 7187311068649407480), UINT64_C(12347518299414990102), UINT64_C(17892571078102411309), UINT64_C( 6851688514051385449) },
      { UINT64_C( 7187311068649407480), UINT64_C(12347518299414990102), UINT64_C(16193047017309816872), UINT64_C( 6851688514051385449) },
      {                     UINT64_MAX,                     UINT64_MAX,                     UINT64_MAX,                     UINT64_MAX } },
    { { UINT64_C(17762255121171813679), UINT64_C(15014474876472594548), UINT64_C(17482807150843533155), UINT64_C(14900096279156936502) },
      { UINT64_C(13744679620163737307), UINT64_C( 8080505619022081018), UINT64_C( 8159639871606936529), UINT64_C( 2385332504260280492) },
      {                     UINT64_MAX,                     UINT64_MAX,                     UINT64_MAX,                     UINT64_MAX } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256i a = simde_mm256_loadu_epi64(test_vec[i].a);
    simde__m256i b = simde_mm256_loadu_epi64(test_vec[i].b);
    simde__m256i r = simde_x_mm256_cmpge_epu64(a, b);
    simde_test_x86_assert_equal_u64x4(r, simde_mm256_loadu_epi64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    uint64_t a_[4];
    uint64_t b_[4];

    simde_test_codegen_random_memory(sizeof(a_), HEDLEY_REINTERPRET_CAST(uint8_t*, a_));
    simde_test_codegen_random_memory(sizeof(b_), HEDLEY_REINTERPRET_CAST(uint8_t*, b_));
    for (size_t j = 0 ; j < (sizeof(a_) / sizeof(a_[0])) ; j++)
      if ((simde_test_codegen_rand() & 3) == 0)
        b_[j] = a_[j];

    simde__m256i a = simde_mm256_loadu_epi64(a_);
    simde__m256i b = simde_mm256_loadu_epi64(b_);
    simde__m256i r = simde_x_mm256_cmpge_epu64(a, b);

    simde_test_x86_write_u64x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_u64x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_u64x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_cmpge_epu64_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const uint64_t a[4];
    const uint64_t b[4];
    const simde__mmask8 r;
  } test_vec[] = {
    { { UINT64_C( 6080662749559587540), UINT64_C( 7798098598880735579), UINT64_C( 5781003121714018010), UINT64_C( 1651287529084890275) },
      { UINT64_C( 6080662749559587540), UINT64_C( 8504161262981100092), UINT64_C( 5781003121714018010), UINT64_C( 5981135193637402536) },
      UINT8_C(  5) },
    { { UINT64_C(12612626608586285365), UINT64_C(13094610924539874790), UINT64_C(14516830050836073955), UINT64_C(10871843848831399782) },
      { UINT64_C( 4553157199874444397), UINT64_C(11607163541537445405), UINT64_C( 7676565905147289786), UINT64_C(11390537155549963291) },
      UINT8_C(  7) },
    { { UINT64_C( 7253165561817288747), UINT64_C(11588381536604830809), UINT64_C( 3490427149948181207), UINT64_C(14583762382536737741) },
      { UINT64_C( 6794167146840824382), UINT64_C(11588381536604830809), UINT64_C(  562595058634571167), UINT64_C(14459322871080721472) },
      UINT8_C( 15) },
    { { UINT64_C(14339818855186298487), UINT64_C(12377983533151532170), UINT64_C(13567978097079391531), UINT64_C( 2872788246063281402) },
      { UINT64_C( 9310091581607752231), UINT64_C(17286629307336775114), UINT64_C(13255402934882768902), UINT64_C( 2872788246063281402) },
      UINT8_C( 13) },
    { { UINT64_C(10061838470376747676), UINT64_C(16034176011851237446), UINT64_C(11196711670683891837), UINT64_C(17730296088229630900) },
      { UINT64_C( 5940246864360978460), UINT64_C(16034176011851237446), UINT64_C( 9595121116760054684), UINT64_C( 6619158130186753163) },
      UINT8_C( 15) },
    { { UINT64_C( 6514227723405143863), UINT64_C(15743438648828816978), UINT64_C( 8580847369726239653), UINT64_C( 7039709136813224260) },
      { UINT64_C(14174384323131622081), UINT64_C(16238060764541373813), UINT64_C( 8580847369726239653), UINT64_C( 7039709136813224260) },
      UINT8_C( 12) },
    { { UINT64_C(13708564206413428042), UINT64_C( 6243028472510257352), UINT64_C(15866564632410727640), UINT64_C(16186643593593803980) },
      { UINT64_C(13708564206413428042), UINT64_C( 2458450046782773622), UINT64_C(16474804160556088399), UINT64_C(16036760986805576727) },
      UINT8_C( 11) },
    { { UINT64_C(17747325677014749965), UINT64_C( 4497453523333048661), UINT64_C(15434828440634854509), UINT64_C(18289345617403953547) },
      { UINT64_C(17475035956183593953), UINT64_C( 3718285289992919861), UINT64_C(14885218394574470412), UINT64_C(17841496005089576876) },
      UINT8_C( 15) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256i a = simde_mm256_loadu_epi64(test_vec[i].a);
    simde__m256i b = simde_mm256_loadu_epi64(test_vec[i].b);
    simde__mmask8 r = simde_mm256_cmpge_epu64_mask(a, b);
    simde_assert_equal_mmask8(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    uint64_t a_[4];
    uint64_t b_[4];

    simde_test_codegen_random_memory(sizeof(a_), HEDLEY_REINTERPRET_CAST(uint8_t*, a_));
    simde_test_codegen_random_memory(sizeof(b_), HEDLEY_REINTERPRET_CAST(uint8_t*, b_));
    for (size_t j = 0 ; j < (sizeof(a_) / sizeof(a_[0])) ; j++)
      if ((simde_test_codegen_rand() & 3) == 0)
        b_[j] = a_[j];

    simde__m256i a = simde_mm256_loadu_epi64(a_);
    simde__m256i b = simde_mm256_loadu_epi64(b_);
    simde__mmask8 r = simde_mm256_cmpge_epu64_mask(a, b);

    simde_test_x86_write_u64x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_u64x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_mask_cmpge_epu64_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k;
    const uint64_t a[4];
    const uint64_t b[4];
    const simde__mmask8 r;
  } test_vec[] = {
    { UINT8_C(250),
      { UINT64_C(17839394700410414976), UINT64_C( 9818094218214002580), UINT64_C( 3489728695404369186), UINT64_C(15983596533711947142) },
      { UINT64_C(11167217361106945035), UINT64_C(17469501230930915132), UINT64_C(  624509970817647031), UINT64_C(15983596533711947142) },
      UINT8_C(  8) },
    { UINT8_C(160),
      { UINT64_C( 1991469518583896036), UINT64_C(10345415797787301263), UINT64_C( 3282806900727061238), UINT64_C( 5231529529396459666) },
      { UINT64_C( 1991469518583896036), UINT64_C(10345415797787301263), UINT64_C( 4207102745734465978), UINT64_C( 6828709548436031001) },
      UINT8_C(  0) },
    { UINT8_C(165),
      { UINT64_C( 6873941362974503387), UINT64_C( 8887377615793014757), UINT64_C(15987233777744384176), UINT64_C(11985579217210391765) },
      { UINT64_C( 6170782993685170693), UINT64_C(13484439236098964685), UINT64_C(11255147235814586091), UINT64_C(12609700348162036876) },
      UINT8_C(  5) },
    { UINT8_C(242),
      { UINT64_C( 1539416039475034006), UINT64_C(15761003901207189564), UINT64_C( 5657856660050695816), UINT64_C(13475228741902807741) },
      { UINT64_C(14567291623849161560), UINT64_C(  569273790467221890), UINT64_C( 5657856660050695816), UINT64_C(18264952628266140570) },
      UINT8_C(  2) },
    { UINT8_C(107),
      { UINT64_C( 2657829311799947321), UINT64_C( 3729093520857885031), UINT64_C(15190796218529581097), UINT64_C( 1693514944461131014) },
      { UINT64_C( 2657829311799947321), UINT64_C(15367779102942643781), UINT64_C(11914784772280357594), UINT64_C(15678353391127610783) },
      UINT8_C(  1) },
    { UINT8_C(169),
      { UINT64_C(15947460189833263710), UINT64_C(17850366931437561095), UINT64_C( 5022661003781234328), UINT64_C(17663693434754272680) },
      { UINT64_C(11344542819266712325), UINT64_C(17850366931437561095), UINT64_C( 9053940410499121871), UINT64_C(17663693434754272680) },
      UINT8_C(  9) },
    { UINT8_C( 22),
      { UINT64_C( 9669486878809087653), UINT64_C(10785758852181994775), UINT64_C(13226899898608200796), UINT64_C( 1150003857286378635) },
      { UINT64_C(12654001800850615296), UINT64_C(  240158249251828024), UINT64_C( 8465223493929436770), UINT64_C(18388397385941277879) },
      UINT8_C(  6) },
    { UINT8_C(104),
      { UINT64_C( 7442495465545705905), UINT64_C(14183116440748051812), UINT64_C(13791039151899691271), UINT64_C( 3021664080841761486) },
      { UINT64_C(12708337143794908612), UINT64_C(13504166304300017506), UINT64_C( 5729285169787954360), UINT64_C( 9477288576516924389) },
      UINT8_C(  0) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__mmask8 k = test_vec[i].k;
    simde__m256i a = simde_mm256_loadu_epi64(test_vec[i].a);
    simde__m256i b = simde_mm256_loadu_epi64(test_vec[i].b);
    simde__mmask8 r = simde_mm256_mask_cmpge_epu64_mask(k, a, b);
    simde_assert_equal_mmask8(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    uint64_t a_[4];
    uint64_t b_[4];

    simde_test_codegen_random_memory(sizeof(a_), HEDLEY_REINTERPRET_CAST(uint8_t*, a_));
    simde_test_codegen_random_memory(sizeof(b_), HEDLEY_REINTERPRET_CAST(uint8_t*, b_));
    for (size_t j = 0 ; j < (sizeof(a_) / sizeof(a_[0])) ; j++)
      if ((simde_test_codegen_rand() & 3) == 0)
        b_[j] = a_[j];

    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m256i a = simde_mm256_loadu_epi64(a_);
    simde__m256i b = simde_mm256_loadu_epi64(b_);
    simde__mmask8 r = simde_mm256_mask_cmpge_epu64_mask(k, a, b);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_u64x4(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_u64x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_x_mm512_cmpge_epu64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const uint64_t a[8];
    const uint64_t b[8];
    const uint64_t r[8];
  } test_vec[] = {
    { { UINT64_C( 6535126494145565142), UINT64_C( 1025648140550892758), UINT64_C(14680134669323963223), UINT64_C(10129090025051143639),
        UINT64_C(11554049487530449938), UINT64_C(10971214270223248295), UINT64_C( 6674138409978770720), UINT64_C(10578136939385765770) },
      { UINT64_C( 4097685846966097779), UINT64_C(17089944309440657234), UINT64_C(10791856209188208354), UINT64_C(15362240543137876511),
        UINT64_C(18142171280627122683), UINT64_C(13826818168922714151), UINT64_C( 2528748120387855223), UINT64_C(10190507492287704629) },
      {                     UINT64_MAX, UINT64_C(                   0),                     UINT64_MAX, UINT64_C(                   0),
        UINT64_C(                   0), UINT64_C(                   0),                     UINT64_MAX,                     UINT64_MAX } },
    { { UINT64_C( 1705857797285668623), UINT64_C(17525670805354697487), UINT64_C(11870914596183866014), UINT64_C(14156603315408000883),
        UINT64_C( 9005331652145119298), UINT64_C(16276508519066210864), UINT64_C(15155685180897848000), UINT64_C(17446991893374391718) },
      { UINT64_C( 6778987464122224938), UINT64_C(17525670805354697487), UINT64_C(11870914596183866014), UINT64_C(15069753156741397888),
        UINT64_C( 9005331652145119298), UINT64_C(17487554707718417694), UINT64_C(15155685180897848000), UINT64_C( 9631097542173633327) },
      { UINT64_C(                   0),                     UINT64_MAX,                     UINT64_MAX, UINT64_C(                   0),
                            UINT64_MAX, UINT64_C(                   0),                     UINT64_MAX,                     UINT64_MAX } },
    { { UINT64_C( 5288599731213248535), UINT64_C( 3410577313455623530), UINT64_C(13847914926737570168), UINT64_C( 4031959850975114686),
        UINT64_C( 8162507173325776271), UINT64_C( 1479683837759901274), UINT64_C(17987351880107069085), UINT64_C(10841632182213255455) },
      { UINT64_C( 5288599731213248535), UINT64_C(16526916817690518698), UINT64_C( 2317773815016593397), UINT64_C(  189947939645189636),
        UINT64_C(13664828448649328626), UINT64_C(16125806878222746269), UINT64_C(17840794361417207670), UINT64_C(13569527965578163881) },
      {                     UINT64_MAX, UINT64_C(                   0),                     UINT64_MAX,                     UINT64_MAX,
        UINT64_C(                   0), UINT64_C(                   0),                     UINT64_MAX, UINT64_C(                   0) } },
    { { UINT64_C( 9712640490216665344), UINT64_C(13741490808635185866), UINT64_C( 4040394466850092683), UINT64_C( 7750085185037200403),
        UINT64_C(  152030815324601734), UINT64_C( 4309507993944136442), UINT64_C( 5457697786597333801), UINT64_C( 4640355487673345423) },
      { UINT64_C( 9712640490216665344), UINT64_C( 7924559928136814861), UINT64_C(13551523889887218316), UINT64_C( 1121426231589756309),
        UINT64_C( 7459141144109082326), UINT64_C(11940200506470983427), UINT64_C(16902426485064378023), UINT64_C( 4116231111262750680) },
      {                     UINT64_MAX,                     UINT64_MAX, UINT64_C(                   0),                     UINT64_MAX,
        UINT64_C(                   0), UINT64_C(                   0), UINT64_C(                   0),                     UINT64_MAX } },
    { { UINT64_C(15750052391643846100), UINT64_C( 5860098426052541715), UINT64_C( 9809825528425844103), UINT64_C( 5665532150214167742),
        UINT64_C(15719478904739289368), UINT64_C(11283090559042049484), UINT64_C( 3748308215751243300), UINT64_C( 3566290262133184183) },
      { UINT64_C( 6124230873383287387), UINT64_C(18170105674931454072), UINT64_C( 1355720220730765349), UINT64_C(10366372874255741586),
        UINT64_C( 8383644203278817659), UINT64_C( 4954851430520451567), UINT64_C( 5280664864038075355), UINT64_C(14386133609926134754) },
      {                     UINT64_MAX, UINT64_C(                   0),                     UINT64_MAX, UINT64_C(                   0),
                            UINT64_MAX,                     UINT64_MAX, UINT64_C(                   0), UINT64_C(                   0) } },
    { { UINT64_C(11779024943465733139), UINT64_C(16842092646869063611), UINT64_C(12231958557011980205), UINT64_C(13905263715320630012),
        UINT64_C(17398086193646908935), UINT64_C( 1923914922713107394), UINT64_C( 6122313119643710413), UINT64_C( 4092452857970148958) },
      { UINT64_C(17018391789205700358), UINT64_C( 8884874936279535813), UINT64_C(12231958557011980205), UINT64_C(13905263715320630012),
        UINT64_C( 3692637707935479079), UINT64_C( 8907191379900691570), UINT64_C( 6122313119643710413), UINT64_C(  487595883070453467) },
      { UINT64_C(                   0),                     UINT64_MAX,                     UINT64_MAX,                     UINT64_MAX,
                            UINT64_MAX, UINT64_C(                   0),                     UINT64_MAX,                     UINT64_MAX } },
    { { UINT64_C(  892992531614025354), UINT64_C(16913317943345173999), UINT64_C(11207765526740079780), UINT64_C(  188068679974904180),
        UINT64_C(  392744550145952621), UINT64_C(10997175614503896996), UINT64_C( 4889965604986672356), UINT64_C(13258788944387122054) },
      { UINT64_C(16092929622611585849), UINT64_C( 2370635289414757465), UINT64_C( 3248851967914606852), UINT64_C( 1181117203289417825),
        UINT64_C( 7939762671713223446), UINT64_C(17761813142234251809), UINT64_C( 9112997687909277603), UINT64_C(16423940430920065543) },
      { UINT64_C(                   0),                     UINT64_MAX,                     UINT64_MAX, UINT64_C(                   0),
        UINT64_C(                   0), UINT64_C(                   0), UINT64_C(                   0), UINT64_C(                   0) } },
    { { UINT64_C(10884636198744117797), UINT64_C(13580702214957160157), UINT64_C( 4875858194453865210), UINT64_C( 7419680668846317268),
        UINT64_C( 6043419990571186258), UINT64_C( 1356082769554227040), UINT64_C(14257698168544848489), UINT64_C(11099564696823088994) },
      { UINT64_C( 8130333304930010635), UINT64_C( 5956387543426867838), UINT64_C( 7672103000129438657), UINT64_C( 7419680668846317268),
        UINT64_C( 6043419990571186258), UINT64_C( 1356082769554227040), UINT64_C( 2974036127678091476), UINT64_C(  527050257205449721) },
      {                     UINT64_MAX,                     UINT64_MAX, UINT64_C(                   0),                     UINT64_MAX,
                            UINT64_MAX,                     UINT64_MAX,                     UINT64_MAX,                     UINT64_MAX } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i a = simde_mm512_loadu_epi64(test_vec[i].a);
    simde__m512i b = simde_mm512_loadu_epi64(test_vec[i].b);
    simde__m512i r = simde_x_mm512_cmpge_epu64(a, b);
    simde_test_x86_assert_equal_u64x8(r, simde_mm512_loadu_epi64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    uint64_t a_[8];
    uint64_t b_[8];

    simde_test_codegen_random_memory(sizeof(a_), HEDLEY_REINTERPRET_CAST(uint8_t*, a_));
    simde_test_codegen_random_memory(sizeof(b_), HEDLEY_REINTERPRET_CAST(uint8_t*, b_));
    for (size_t j = 0 ; j < (sizeof(a_) / sizeof(a_[0])) ; j++)
      if ((simde_test_codegen_rand() & 3) == 0)
        b_[j] = a_[j];

    simde__m512i a = simde_mm512_loadu_epi64(a_);
    simde__m512i b = simde_mm512_loadu_epi64(b_);
    simde__m512i r = simde_x_mm512_cmpge_epu64(a, b);

    simde_test_x86_write_u64x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_u64x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_u64x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_cmpge_epu64_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const uint64_t a[8];
    const uint64_t b[8];
    const simde__mmask8 r;
  } test_vec[] = {
    { { UINT64_C(13415704210704668024), UINT64_C( 8915679766151339127), UINT64_C(18059551816749300782), UINT64_C(11612183272042681836),
        UINT64_C( 9870274175176075609), UINT64_C(11158744959867785438), UINT64_C( 5456905207201068303), UINT64_C(12462556739880849448) },
      { UINT64_C( 2839772770037663695), UINT64_C( 7168431348590805366), UINT64_C(12106200818229947991), UINT64_C( 8461680575373820013),
        UINT64_C(13070780097845615092), UINT64_C(11886989865865702207), UINT64_C( 7343501789210745536), UINT64_C(12462556739880849448) },
      UINT8_C(143) },
    { { UINT64_C( 5494693415509260624), UINT64_C( 1336012138544470829), UINT64_C( 3670163513534558554), UINT64_C(12062401592823902613),
        UINT64_C(13948921917282222779), UINT64_C(17521942198305038625), UINT64_C(11356122260837432610), UINT64_C(17797348571926493694) },
      { UINT64_C( 5494693415509260624), UINT64_C( 3710730872828240115), UINT64_C(12235212193206541607), UINT64_C(10186854462920738605),
        UINT64_C( 7127298726506699834), UINT64_C( 4189874960785664480), UINT64_C(11356122260837432610), UINT64_C(10391184595302833021) },
      UINT8_C(249) },
    { { UINT64_C(13380461328344040035), UINT64_C(14755986247057808050), UINT64_C(13478331641566023719), UINT64_C( 8805946945738546529),
        UINT64_C(12010715329697153605), UINT64_C( 1069345319554915515), UINT64_C( 5933096623042939491), UINT64_C( 5460581589894104117) },
      { UINT64_C(13380461328344040035), UINT64_C( 4611956352009292298), UINT64_C( 6305656451190459199), UINT64_C(17764284976945442613),
        UINT64_C(12010715329697153605), UINT64_C( 1069345319554915515), UINT64_C( 5933096623042939491), UINT64_C( 5460581589894104117) },
      UINT8_C(247) },
    { { UINT64_C( 1161689926210757789), UINT64_C( 9506857756065148727), UINT64_C(15720130996589732221), UINT64_C( 1771888807819316151),
        UINT64_C(16577036301645613095), UINT64_C( 2155902193656298405), UINT64_C( 1775131156692287982), UINT64_C( 6676387661704540435) },
      { UINT64_C( 1830824799603588819), UINT64_C(  260483188768491489), UINT64_C(10891514262305111213), UINT64_C(17884019682645039775),
        UINT64_C(14940942376208402635), UINT64_C(17564862380516563370), UINT64_C( 1775131156692287982), UINT64_C( 6676387661704540435) },
      UINT8_C(214) },
    { { UINT64_C(  751442674101728308), UINT64_C(11010595847547678263), UINT64_C(  244847889182833833), UINT64_C(17807511944728963193),
        UINT64_C(16743502367830378289), UINT64_C(18193672041660077389), UINT64_C(10665372852269497124), UINT64_C( 5271088534248954732) },
      { UINT64_C(14072896123003705523), UINT64_C( 8294543432171873997), UINT64_C( 3102266283076598622), UINT64_C(17866765179113085073),
        UINT64_C( 6076103047943786264), UINT64_C( 8921507838328895757), UINT64_C( 5275124428503794251), UINT64_C( 5271088534248954732) },
      UINT8_C(242) },
    { { UINT64_C(11644918119784301827), UINT64_C( 2977690312399097681), UINT64_C(11793198087714326128), UINT64_C( 7982051355938283531),
        UINT64_C( 7326275859894896054), UINT64_C(12209752516550613176), UINT64_C( 6906220912201857031), UINT64_C( 2165112567259756339) },
      { UINT64_C( 8900756372114217483), UINT64_C(13551389232492442670), UINT64_C( 4710984068910561965), UINT64_C( 7982051355938283531),
        UINT64_C(17420864279851232645), UINT64_C(12209752516550613176), UINT64_C(12822531488300444835), UINT64_C( 4738098777495687529) },
      UINT8_C( 45) },
    { { UINT64_C( 2590963414783694546), UINT64_C(10287846786346540192), UINT64_C( 4725506604544105623), UINT64_C( 4257251203312590322),
        UINT64_C(16034146449948625890), UINT64_C(13099765281653413912), UINT64_C(13424276967982131411), UINT64_C(  530768507082070713) },
      { UINT64_C(17875892893188171254), UINT64_C(10383612699991147846), UINT64_C( 8713032336953516649), UINT64_C( 4257251203312590322),
        UINT64_C(  861995976319686685), UINT64_C(10790213679588584562), UINT64_C( 9575972507019008684), UINT64_C(10773835677350723378) },
      UINT8_C(120) },
    { { UINT64_C(12283472317063525301), UINT64_C( 2362412806295600386), UINT64_C( 4721184246578852984), UINT64_C( 6333816588855744737),
        UINT64_C( 8887766426282741936), UINT64_C(16139925139960655342), UINT64_C( 7173201220793761084), UINT64_C(12782469190255560044) },
      { UINT64_C( 4339700165265825093), UINT64_C(13720520290656123171), UINT64_C(17903661797505317009), UINT64_C(13622661513038070874),
        UINT64_C( 5085044617640635399), UINT64_C( 5759885937455704494), UINT64_C( 7173201220793761084), UINT64_C( 7787377300852767708) },
      UINT8_C(241) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i a = simde_mm512_loadu_epi64(test_vec[i].a);
    simde__m512i b = simde_mm512_loadu_epi64(test_vec[i].b);
    simde__mmask8 r = simde_mm512_cmpge_epu64_mask(a, b);
    simde_assert_equal_mmask8(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    uint64_t a_[8];
    uint64_t b_[8];

    simde_test_codegen_random_memory(sizeof(a_), HEDLEY_REINTERPRET_CAST(uint8_t*, a_));
    simde_test_codegen_random_memory(sizeof(b_), HEDLEY_REINTERPRET_CAST(uint8_t*, b_));
    for (size_t j = 0 ; j < (sizeof(a_) / sizeof(a_[0])) ; j++)
      if ((simde_test_codegen_rand() & 3) == 0)
        b_[j] = a_[j];

    simde__m512i a = simde_mm512_loadu_epi64(a_);
    simde__m512i b = simde_mm512_loadu_epi64(b_);
    simde__mmask8 r = simde_mm512_cmpge_epu64_mask(a, b);

    simde_test_x86_write_u64x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_u64x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_mask_cmpge_epu64_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k;
    const uint64_t a[8];
    const uint64_t b[8];
    const simde__mmask8 r;
  } test_vec[] = {
    { UINT8_C( 77),
      { UINT64_C(11748221487535028477), UINT64_C( 2486152219949362441), UINT64_C(15376284284490335377), UINT64_C( 8452375209166906647),
        UINT64_C( 9848311901953486551), UINT64_C( 8435137532179533224), UINT64_C( 2832991835313178212), UINT64_C(13610668508630353652) },
      { UINT64_C(17673093941408633404), UINT64_C( 7501011276833973183), UINT64_C( 5165685206482650233), UINT64_C( 4384982114457891385),
        UINT64_C(15054191127759921064), UINT64_C( 4182308867737374366), UINT64_C( 6461384673343040784), UINT64_C(13610668508630353652) },
      UINT64_C(                  12) },
    { UINT8_C(191),
      { UINT64_C( 5611846191341786694), UINT64_C( 5703183239366919435), UINT64_C( 9909011745022987070), UINT64_C(11475543871826331253),
        UINT64_C(11841461608170672296), UINT64_C(14399776614078726807), UINT64_C( 8091803029845056019), UINT64_C(16454365493330241889) },
      { UINT64_C( 5611846191341786694), UINT64_C(12778137786615747845), UINT64_C(16975965341667798570), UINT64_C(11475543871826331253),
        UINT64_C(18201394616230852041), UINT64_C(  935588610127352493), UINT64_C( 8091803029845056019), UINT64_C( 8140678158341351618) },
      UINT64_C(                 169) },
    { UINT8_C(118),
      { UINT64_C(15501862057050992051), UINT64_C(16386583895375821022), UINT64_C(16232093197642943119), UINT64_C( 5403045868420427599),
        UINT64_C( 2821221807420185830), UINT64_C(10400277194819316023), UINT64_C( 2928995458080497408), UINT64_C( 6643477360339647568) },
      { UINT64_C(15501862057050992051), UINT64_C(16386583895375821022), UINT64_C( 6695963191529319147), UINT64_C(12296083377832087763),
        UINT64_C( 2007015679947853702), UINT64_C(10400277194819316023), UINT64_C( 2928995458080497408), UINT64_C( 8423202373430966155) },
      UINT64_C(                 118) },
    { UINT8_C(141),
      { UINT64_C(15296650074031178458), UINT64_C(14678244192968057069), UINT64_C(12172998708102295086), UINT64_C( 4004147965568915511),
        UINT64_C( 3558121076971251033), UINT64_C( 8447077552037146140), UINT64_C( 6374788243159577595), UINT64_C( 4465324411082460516) },
      { UINT64_C(15296650074031178458), UINT64_C( 9193374628573312984), UINT64_C(11734908647037104481), UINT64_C(18028854140878408978),
        UINT64_C(18406499919547923718), UINT64_C( 8447077552037146140), UINT64_C(11962914746425265957), UINT64_C( 4465324411082460516) },
      UINT64_C(                 133) },
    { UINT8_C(215),
      { UINT64_C( 2803792411185108497), UINT64_C(13326820147658902535), UINT64_C( 1628125786390814716), UINT64_C(10317817658957663162),
        UINT64_C(16758806676786892566), UINT64_C(12218741524761824649), UINT64_C(  786736096929385487), UINT64_C(12512650780709050264) },
      { UINT64_C(13724065884993681580), UINT64_C(13326820147658902535), UINT64_C( 7606496008126055733), UINT64_C(14217622241150974986),
        UINT64_C( 1302040670266092061), UINT64_C(  634737973261871610), UINT64_C( 6055683751504877263), UINT64_C(14642967853980354904) },
      UINT64_C(                  18) },
    { UINT8_C(157),
      { UINT64_C(10046320161745151634), UINT64_C(11507586648868457535), UINT64_C(16290672528614827039), UINT64_C( 5061054996451285814),
        UINT64_C(15501476334665983648), UINT64_C( 4400268754835141978), UINT64_C(12413528567510621449), UINT64_C(10415503158058972817) },
      { UINT64_C( 1702718815565344306), UINT64_C(13949786288346944315), UINT64_C( 9229962438334757365), UINT64_C(12060446789753710815),
        UINT64_C(15501476334665983648), UINT64_C(12205025141995740134), UINT64_C(12413528567510621449), UINT64_C( 8246088391345398356) },
      UINT64_C(                 149) },
    { UINT8_C(123),
      { UINT64_C( 6905137371144026543), UINT64_C(17333822313473110030), UINT64_C(12049123271264917177), UINT64_C( 9377186925478904579),
        UINT64_C( 8802560816833852143), UINT64_C( 5361890023924069866), UINT64_C( 2667598975032364184), UINT64_C(  365015967071903930) },
      { UINT64_C( 2028297900396525375), UINT64_C(17333822313473110030), UINT64_C( 4058050569910240778), UINT64_C(  564031635814022328),
        UINT64_C(  170247930558718222), UINT64_C(17906107535375462576), UINT64_C( 2667598975032364184), UINT64_C(  365015967071903930) },
      UINT64_C(                  91) },
    { UINT8_C( 96),
      { UINT64_C( 6272495886206060347), UINT64_C( 7092149452764354181), UINT64_C(15795022089234327183), UINT64_C(16385260552662248543),
        UINT64_C(12936713273321246058), UINT64_C( 8665518224813492359), UINT64_C( 1406033155752232128), UINT64_C(13201283392428911272) },
      { UINT64_C(10309145302776977455), UINT64_C(11050340185071927289), UINT64_C( 5115459839065088821), UINT64_C(10084346112616430317),
        UINT64_C(12936713273321246058), UINT64_C( 5848630125299985080), UINT64_C( 2074533450290523109), UINT64_C(10311633653038735667) },
      UINT64_C(                  32) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__mmask8 k = test_vec[i].k;
    simde__m512i a = simde_mm512_loadu_epi64(test_vec[i].a);
    simde__m512i b = simde_mm512_loadu_epi64(test_vec[i].b);
    simde__mmask8 r = simde_mm512_mask_cmpge_epu64_mask(k, a, b);
    simde_assert_equal_mmask8(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    uint64_t a_[8];
    uint64_t b_[8];

    simde_test_codegen_random_memory(sizeof(a_), HEDLEY_REINTERPRET_CAST(uint8_t*, a_));
    simde_test_codegen_random_memory(sizeof(b_), HEDLEY_REINTERPRET_CAST(uint8_t*, b_));
    for (size_t j = 0 ; j < (sizeof(a_) / sizeof(a_[0])) ; j++)
      if ((simde_test_codegen_rand() & 3) == 0)
        b_[j] = a_[j];

    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m512i a = simde_mm512_loadu_epi64(a_);
    simde__m512i b = simde_mm512_loadu_epi64(b_);
    simde__mmask8 r = simde_mm512_mask_cmpge_epu64_mask(k, a, b);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_u64x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_u64x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask64(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(x_mm_cmpge_epi8)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_cmpge_epi8_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_mask_cmpge_epi8_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(x_mm256_cmpge_epi8)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_cmpge_epi8_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_mask_cmpge_epi8_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(x_mm512_cmpge_epi8)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_cmpge_epi8_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_cmpge_epi8_mask)

  SIMDE_TEST_FUNC_LIST_ENTRY(x_mm_cmpge_epu8)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_cmpge_epu8_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_mask_cmpge_epu8_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(x_mm256_cmpge_epu8)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_cmpge_epu8_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_mask_cmpge_epu8_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(x_mm512_cmpge_epu8)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_cmpge_epu8_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_cmpge_epu8_mask)

  SIMDE_TEST_FUNC_LIST_ENTRY(x_mm_cmpge_epi16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_cmpge_epi16_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_mask_cmpge_epi16_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(x_mm256_cmpge_epi16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_cmpge_epi16_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_mask_cmpge_epi16_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(x_mm512_cmpge_epi16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_cmpge_epi16_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_cmpge_epi16_mask)

  SIMDE_TEST_FUNC_LIST_ENTRY(x_mm_cmpge_epu16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_cmpge_epu16_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_mask_cmpge_epu16_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(x_mm256_cmpge_epu16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_cmpge_epu16_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_mask_cmpge_epu16_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(x_mm512_cmpge_epu16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_cmpge_epu16_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_cmpge_epu16_mask)

  SIMDE_TEST_FUNC_LIST_ENTRY(x_mm_cmpge_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_cmpge_epi32_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_mask_cmpge_epi32_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(x_mm256_cmpge_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_cmpge_epi32_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_mask_cmpge_epi32_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(x_mm512_cmpge_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_cmpge_epi32_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_cmpge_epi32_mask)

  SIMDE_TEST_FUNC_LIST_ENTRY(x_mm_cmpge_epu32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_cmpge_epu32_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_mask_cmpge_epu32_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(x_mm256_cmpge_epu32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_cmpge_epu32_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_mask_cmpge_epu32_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(x_mm512_cmpge_epu32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_cmpge_epu32_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_cmpge_epu32_mask)

  SIMDE_TEST_FUNC_LIST_ENTRY(x_mm_cmpge_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_cmpge_epi64_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_mask_cmpge_epi64_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(x_mm256_cmpge_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_cmpge_epi64_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_mask_cmpge_epi64_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(x_mm512_cmpge_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_cmpge_epi64_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_cmpge_epi64_mask)

  SIMDE_TEST_FUNC_LIST_ENTRY(x_mm_cmpge_epu64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_cmpge_epu64_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_mask_cmpge_epu64_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(x_mm256_cmpge_epu64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_cmpge_epu64_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_mask_cmpge_epu64_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(x_mm512_cmpge_epu64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_cmpge_epu64_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_cmpge_epu64_mask)
SIMDE_TEST_FUNC_LIST_END

#include <test/x86/avx512/test-avx512-footer.h>
