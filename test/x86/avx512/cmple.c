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

#include "test/test.h"
#define SIMDE_TEST_X86_AVX512_INSN cmple

#include <test/x86/avx512/test-avx512.h>
#include <simde/x86/avx512/set.h>
#include <simde/x86/avx512/cmple.h>

static int
test_simde_x_mm_cmple_epi8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int8_t a[16];
    const int8_t b[16];
    const int8_t r[16];
  } test_vec[] = {
    { { -INT8_C(  73), -INT8_C(   2),  INT8_C(  94),  INT8_C(  35),  INT8_C( 118),  INT8_C(  28),  INT8_C(  97),  INT8_C( 125),
         INT8_C(  15), -INT8_C( 121),  INT8_C( 115), -INT8_C(  18),  INT8_C(  52), -INT8_C(  94),  INT8_C(  62), -INT8_C( 119) },
      {  INT8_C(  43), -INT8_C( 126), -INT8_C(  73),  INT8_C( 105), -INT8_C(  61),  INT8_C(  14), -INT8_C(  30), -INT8_C( 115),
        -INT8_C(  85),  INT8_C(  22),  INT8_C(  35), -INT8_C( 117),  INT8_C(  52),  INT8_C( 120),  INT8_C(  67), -INT8_C( 113) },
      { -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
         INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1) } },
    { {  INT8_C( 124),  INT8_C(  15),  INT8_C(  20),  INT8_C(  63),  INT8_C(  29), -INT8_C(  10), -INT8_C(  52), -INT8_C(  56),
         INT8_C(  13), -INT8_C(  16),  INT8_C(  84), -INT8_C(  27),  INT8_C( 104), -INT8_C( 105),  INT8_C( 116), -INT8_C(  34) },
      {  INT8_C(  56),  INT8_C(  38), -INT8_C(  53), -INT8_C(  11),  INT8_C(  57),  INT8_C(  54), -INT8_C(  62), -INT8_C(  44),
         INT8_C(  19),  INT8_C( 126), -INT8_C(  94), -INT8_C( 109),  INT8_C( 120), -INT8_C(   6),  INT8_C(  62), -INT8_C(  12) },
      {  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
        -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1) } },
    { { -INT8_C(  43),  INT8_C(   1),  INT8_C(   7),  INT8_C(  15),  INT8_C(  55), -INT8_C(  55), -INT8_C(  29),  INT8_C(  75),
         INT8_C(  71), -INT8_C( 123), -INT8_C(  34), -INT8_C(  65),      INT8_MAX,  INT8_C(  29), -INT8_C(  77), -INT8_C( 120) },
      { -INT8_C(  43), -INT8_C(  26), -INT8_C(  82),  INT8_C(  15), -INT8_C(  26), -INT8_C(  99),  INT8_C(  16), -INT8_C(  43),
         INT8_C(  71),  INT8_C(  75),  INT8_C(  45), -INT8_C(  71), -INT8_C(   5),  INT8_C(  99), -INT8_C(  77), -INT8_C(  48) },
      { -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
        -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1) } },
    { {  INT8_C(  60), -INT8_C(   2),  INT8_C(  12),  INT8_C(  34), -INT8_C( 101),  INT8_C(  28), -INT8_C(   9),  INT8_C( 123),
         INT8_C( 103),  INT8_C(  36),  INT8_C(  52),  INT8_C(  98), -INT8_C( 121), -INT8_C(   2),  INT8_C(  51), -INT8_C(  20) },
      { -INT8_C(  48),  INT8_C(  18), -INT8_C( 120),  INT8_C( 107), -INT8_C(  43),  INT8_C( 111),  INT8_C(  77),  INT8_C(  29),
         INT8_C(  52), -INT8_C(  17), -INT8_C(  28),  INT8_C(  23), -INT8_C( 121),  INT8_C(  52),  INT8_C( 105), -INT8_C(  20) },
      {  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
         INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1) } },
    { { -INT8_C(  95), -INT8_C(  70), -INT8_C(  73),  INT8_C( 118),  INT8_C(  41),  INT8_C(   4), -INT8_C( 109),  INT8_C(  94),
        -INT8_C(  12),  INT8_C( 119),  INT8_C( 117),  INT8_C(  57), -INT8_C(  84), -INT8_C(  34), -INT8_C(  70), -INT8_C(  33) },
      {  INT8_C(  84),  INT8_C(  93), -INT8_C(  83), -INT8_C(  27),  INT8_C(  41), -INT8_C(   9), -INT8_C(  34),  INT8_C(  94),
         INT8_C( 116),  INT8_C(  58), -INT8_C(   3), -INT8_C(  16), -INT8_C(  56),  INT8_C(  47),  INT8_C(  60),  INT8_C( 105) },
      { -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
        -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1) } },
    { {  INT8_C(  60),  INT8_C(  34), -INT8_C(   2),  INT8_C(  51),  INT8_C(  25), -INT8_C(  35), -INT8_C(  22), -INT8_C( 114),
         INT8_C(  23), -INT8_C(  25),  INT8_C( 126), -INT8_C(  33),  INT8_C(  22), -INT8_C(  69),  INT8_C(  73),  INT8_C(   0) },
      { -INT8_C(  82),  INT8_C(  34),  INT8_C(  20),  INT8_C(  51), -INT8_C( 101), -INT8_C(  35), -INT8_C( 110), -INT8_C( 114),
         INT8_C( 108), -INT8_C(  25),  INT8_C( 126),  INT8_C(  49), -INT8_C( 106), -INT8_C( 112),  INT8_C(  74), -INT8_C(  46) },
      {  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
        -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0) } },
    { { -INT8_C( 115),  INT8_C(   2), -INT8_C(  24),  INT8_C(  40), -INT8_C( 121),  INT8_C( 123), -INT8_C(  83), -INT8_C(  13),
         INT8_C(  50), -INT8_C(  56),  INT8_C(  36), -INT8_C(  55),  INT8_C(  88),  INT8_C( 110), -INT8_C( 101),  INT8_C(  11) },
      { -INT8_C(  73), -INT8_C(  95), -INT8_C(  24), -INT8_C(  36), -INT8_C( 111),  INT8_C(  49),  INT8_C(  25),  INT8_C( 104),
         INT8_C(   9),  INT8_C(  53),  INT8_C(  86), -INT8_C(  99),  INT8_C(  88),  INT8_C(  68), -INT8_C(  33),  INT8_C(  39) },
      { -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
         INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1) } },
    { {  INT8_C( 123),  INT8_C(   0), -INT8_C(  25),  INT8_C(  12),  INT8_C(  49),  INT8_C(   0),  INT8_C( 117),  INT8_C(  59),
         INT8_C(  53), -INT8_C(  53), -INT8_C(  40), -INT8_C(  49),  INT8_C(  15), -INT8_C(  73), -INT8_C(   9),  INT8_C(  85) },
      {  INT8_C( 126),  INT8_C(  71),  INT8_C(  34),  INT8_C(  12),  INT8_C(  49), -INT8_C(  29),  INT8_C(  54),  INT8_C(  10),
        -INT8_C(  55),  INT8_C( 116),  INT8_C(  41), -INT8_C(  49),  INT8_C(  77), -INT8_C(  73),  INT8_C(  40), -INT8_C(  56) },
      { -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
         INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_x_mm_loadu_epi8(test_vec[i].a);
    simde__m128i b = simde_x_mm_loadu_epi8(test_vec[i].b);
    simde__m128i r = simde_x_mm_cmple_epi8(a, b);
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
    simde__m128i r = simde_x_mm_cmple_epi8(a, b);

    simde_test_x86_write_i8x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i8x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i8x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_cmple_epi8_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int8_t a[16];
    const int8_t b[16];
    const simde__mmask16 r;
  } test_vec[] = {
    { { -INT8_C(  23), -INT8_C(   6), -INT8_C(  98), -INT8_C(  20), -INT8_C(  89),  INT8_C(  49), -INT8_C(  20), -INT8_C(   1),
         INT8_C(  35),  INT8_C(  81),  INT8_C(  22), -INT8_C(  68), -INT8_C(  42),  INT8_C(  40), -INT8_C(  34),  INT8_C(  79) },
      {  INT8_C( 101), -INT8_C(   6), -INT8_C( 116), -INT8_C(  43),  INT8_C(  28),  INT8_C(  49),  INT8_C(  16), -INT8_C(   1),
         INT8_C(  39),  INT8_C(  81), -INT8_C( 124),  INT8_C(   1), -INT8_C(  42),  INT8_C(   0), -INT8_C(  91),  INT8_C(   3) },
      UINT16_C( 7155) },
    { { -INT8_C(  86), -INT8_C(  33),  INT8_C(  26), -INT8_C(  58), -INT8_C(  74),  INT8_C(  42), -INT8_C(  60), -INT8_C(  35),
        -INT8_C(  69),  INT8_C(  72), -INT8_C(  34), -INT8_C(  43),  INT8_C(  73), -INT8_C( 125), -INT8_C(  40),  INT8_C(  68) },
      { -INT8_C(  57), -INT8_C(  33), -INT8_C(  26), -INT8_C(  58), -INT8_C(  92), -INT8_C( 120), -INT8_C(  43), -INT8_C(  47),
         INT8_C(  64),  INT8_C(  42), -INT8_C(  44), -INT8_C(  43),  INT8_C(  94), -INT8_C( 125), -INT8_C(  40),  INT8_C(   8) },
      UINT16_C(31051) },
    { { -INT8_C(  36),  INT8_C(  79), -INT8_C(   1),      INT8_MIN, -INT8_C(  41), -INT8_C(  43),  INT8_C(  81),  INT8_C(  23),
        -INT8_C(   1),  INT8_C(  37),  INT8_C(  55),  INT8_C(  93),  INT8_C(  77), -INT8_C( 100),  INT8_C( 101),  INT8_C(  83) },
      {  INT8_C(  28),  INT8_C(  52), -INT8_C(   1), -INT8_C(  57), -INT8_C(  57), -INT8_C(  87),  INT8_C(  81), -INT8_C(  94),
         INT8_C(  33),  INT8_C( 104),  INT8_C(  55),  INT8_C(  93),  INT8_C(  77),  INT8_C(  47), -INT8_C(  34),  INT8_C(  83) },
      UINT16_C(48973) },
    { { -INT8_C(  87), -INT8_C(   1),  INT8_C(  35),  INT8_C( 112), -INT8_C(  87),  INT8_C(  80),  INT8_C(  19), -INT8_C(  54),
        -INT8_C(  71), -INT8_C(  38), -INT8_C(  26),  INT8_C(  53),  INT8_C(   9), -INT8_C(  60), -INT8_C( 114), -INT8_C( 120) },
      { -INT8_C(  94),  INT8_C( 102), -INT8_C(  35),  INT8_C(  85), -INT8_C( 112),  INT8_C(  74),  INT8_C(   8), -INT8_C(  33),
        -INT8_C(  71),  INT8_C(  24), -INT8_C(  26),  INT8_C(  45), -INT8_C( 115),  INT8_C( 106), -INT8_C( 118),  INT8_C(  55) },
      UINT16_C(42882) },
    { { -INT8_C(  31),  INT8_C(   3),      INT8_MAX,  INT8_C( 113),  INT8_C(  77), -INT8_C( 121),  INT8_C(  80),  INT8_C(  59),
        -INT8_C(  97), -INT8_C(  53),  INT8_C( 104),  INT8_C(  45),  INT8_C(  53), -INT8_C(  14),  INT8_C( 100), -INT8_C(  97) },
      { -INT8_C(  96),  INT8_C(  11), -INT8_C(  78), -INT8_C(  98), -INT8_C(  58), -INT8_C( 113),  INT8_C(  85),  INT8_C(  90),
         INT8_C(  82),  INT8_C(  65), -INT8_C(   8), -INT8_C(  38), -INT8_C(  68),  INT8_C(  30),  INT8_C(   4), -INT8_C(  99) },
      UINT16_C( 9186) },
    { {  INT8_C(  71), -INT8_C(  80),  INT8_C(  67),  INT8_C(  13),  INT8_C(  64), -INT8_C( 104),  INT8_C( 103), -INT8_C( 110),
        -INT8_C(  38),  INT8_C(  96),  INT8_C( 108), -INT8_C( 106),  INT8_C( 126),  INT8_C( 112),  INT8_C(  51), -INT8_C(  96) },
      { -INT8_C(  12), -INT8_C(  80),  INT8_C(  67), -INT8_C(   1),  INT8_C(  64), -INT8_C( 104), -INT8_C(  87), -INT8_C(  56),
        -INT8_C(  38),  INT8_C(  96),  INT8_C( 108), -INT8_C(  45),  INT8_C( 126),  INT8_C(  36),  INT8_C( 120), -INT8_C(  96) },
      UINT16_C(57270) },
    { {  INT8_C(  56),  INT8_C(   7),  INT8_C( 119), -INT8_C(  41), -INT8_C(  63),  INT8_C(  33), -INT8_C(  97), -INT8_C( 113),
        -INT8_C(  94), -INT8_C(  58),  INT8_C(  98),  INT8_C(  94), -INT8_C(  22), -INT8_C(  38),  INT8_C(  98), -INT8_C(  65) },
      { -INT8_C( 106),  INT8_C(   7), -INT8_C(  44), -INT8_C(  41), -INT8_C(  22),  INT8_C( 124),  INT8_C(  25), -INT8_C(  62),
        -INT8_C( 112), -INT8_C(  34),  INT8_C(  25),  INT8_C(  20), -INT8_C(  22), -INT8_C(  38), -INT8_C( 115),  INT8_C(  14) },
      UINT16_C(45818) },
    { { -INT8_C(   6), -INT8_C(  55),  INT8_C(  37), -INT8_C(  27),  INT8_C(  69),  INT8_C(  63), -INT8_C(  89), -INT8_C(  43),
         INT8_C(  29), -INT8_C(  64), -INT8_C(  22), -INT8_C(  14), -INT8_C(  48),  INT8_C( 119),  INT8_C(   0), -INT8_C(  25) },
      {  INT8_C( 123), -INT8_C(  26), -INT8_C(  64), -INT8_C(  95),  INT8_C(  69),  INT8_C(  39),  INT8_C( 104), -INT8_C(  74),
        -INT8_C(  15), -INT8_C( 114), -INT8_C(  21), -INT8_C( 107),  INT8_C(  22),  INT8_C( 119), -INT8_C(  49),  INT8_C(  17) },
      UINT16_C(46163) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_x_mm_loadu_epi8(test_vec[i].a);
    simde__m128i b = simde_x_mm_loadu_epi8(test_vec[i].b);
    simde__mmask16 r = simde_mm_cmple_epi8_mask(a, b);
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
    simde__mmask16 r = simde_mm_cmple_epi8_mask(a, b);

    simde_test_x86_write_i8x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i8x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_mask_cmple_epi8_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask16 k;
    const int8_t a[16];
    const int8_t b[16];
    const simde__mmask16 r;
  } test_vec[] = {
    { UINT16_C( 7451),
      {  INT8_C(  42), -INT8_C(  42),  INT8_C(  66), -INT8_C( 107), -INT8_C(   3), -INT8_C(  85),  INT8_C(  75), -INT8_C(  18),
         INT8_C(  57),  INT8_C(  54), -INT8_C( 125),  INT8_C(  80),  INT8_C(  23),  INT8_C(  83),  INT8_C(  97), -INT8_C(  63) },
      {  INT8_C(  72),  INT8_C(  87), -INT8_C(  80),  INT8_C( 124), -INT8_C(  12),  INT8_C( 117), -INT8_C(  51),  INT8_C(  82),
         INT8_C(  36),  INT8_C(  54), -INT8_C( 127),  INT8_C(  80),  INT8_C(  84),  INT8_C(  83), -INT8_C(  20),  INT8_C( 126) },
      UINT16_C( 6155) },
    { UINT16_C(18990),
      { -INT8_C(  13),  INT8_C(  15), -INT8_C( 109), -INT8_C(  64),  INT8_C(  98), -INT8_C(  73), -INT8_C(  47), -INT8_C(  29),
         INT8_C(   2),  INT8_C(  37),  INT8_C( 122), -INT8_C(  18), -INT8_C(  92), -INT8_C(  25),  INT8_C(  28), -INT8_C(  73) },
      {  INT8_C(  81),  INT8_C(  15),  INT8_C(  22), -INT8_C(  64),  INT8_C(  98), -INT8_C(  85), -INT8_C( 121),  INT8_C( 108),
         INT8_C(   2), -INT8_C(  74),  INT8_C( 122), -INT8_C(  18), -INT8_C(  92), -INT8_C(  25),  INT8_C(  28),  INT8_C(  33) },
      UINT16_C(18446) },
    { UINT16_C(30252),
      { -INT8_C(   4),  INT8_C(  55), -INT8_C(  11), -INT8_C( 125), -INT8_C(  93),  INT8_C(  76),  INT8_C(  58), -INT8_C(  45),
         INT8_C(  16),  INT8_C( 104),  INT8_C(  30), -INT8_C(  15), -INT8_C( 119),  INT8_C( 121),  INT8_C( 102),  INT8_C( 107) },
      {  INT8_C(  53), -INT8_C( 110),  INT8_C(  30), -INT8_C(  43), -INT8_C(  64), -INT8_C(   9), -INT8_C(  18), -INT8_C(  36),
         INT8_C( 115),  INT8_C( 104),  INT8_C(  30), -INT8_C(  15),  INT8_C(  65),  INT8_C(  67),  INT8_C( 102),  INT8_C(  61) },
      UINT16_C(22028) },
    { UINT16_C(34062),
      { -INT8_C( 109), -INT8_C(  20),  INT8_C( 109), -INT8_C( 126), -INT8_C(  56), -INT8_C(  31),  INT8_C( 113), -INT8_C(  36),
        -INT8_C( 120), -INT8_C(  78),  INT8_C(  31),  INT8_C( 122), -INT8_C(  17), -INT8_C( 102),  INT8_C(  96), -INT8_C(  80) },
      { -INT8_C(  72), -INT8_C( 109), -INT8_C(  85), -INT8_C(  87), -INT8_C(  56),  INT8_C(  14),  INT8_C( 113), -INT8_C(  36),
        -INT8_C(   5),  INT8_C(  66), -INT8_C(  93),  INT8_C(  83),  INT8_C(   1), -INT8_C(  49), -INT8_C(  55), -INT8_C( 108) },
      UINT16_C(  264) },
    { UINT16_C(58102),
      {  INT8_C( 123), -INT8_C(  29), -INT8_C( 109),  INT8_C(  52), -INT8_C(  19), -INT8_C( 114),  INT8_C( 119), -INT8_C( 112),
        -INT8_C(  31),  INT8_C( 120),  INT8_C(  96), -INT8_C(  85),  INT8_C(  12),  INT8_C(  27), -INT8_C(  30),  INT8_C(  35) },
      { -INT8_C(  97), -INT8_C(   6), -INT8_C(  86), -INT8_C(   1), -INT8_C( 102), -INT8_C( 114),  INT8_C( 126), -INT8_C(  75),
        -INT8_C(  31), -INT8_C( 104),  INT8_C(  48), -INT8_C(  85),  INT8_C( 105),  INT8_C(  27),  INT8_C( 107), -INT8_C(  28) },
      UINT16_C(24806) },
    { UINT16_C(25929),
      { -INT8_C(  72), -INT8_C( 112), -INT8_C(  58),  INT8_C(  55),  INT8_C(  69), -INT8_C(  45), -INT8_C(  49),  INT8_C( 117),
        -INT8_C(  71),  INT8_C(  56), -INT8_C(  77),  INT8_C(  37),  INT8_C(  29), -INT8_C(  43),  INT8_C(  36),  INT8_C(  54) },
      { -INT8_C(  29), -INT8_C(  79), -INT8_C(  58), -INT8_C( 126),  INT8_C(  32), -INT8_C(  45), -INT8_C(  49),  INT8_C(  58),
        -INT8_C(  71), -INT8_C( 100),  INT8_C(  54),  INT8_C(  26),  INT8_C(  29),  INT8_C(  44), -INT8_C(   4),  INT8_C(  54) },
      UINT16_C( 9537) },
    { UINT16_C(20242),
      {  INT8_C( 102),  INT8_C( 105),  INT8_C(  51), -INT8_C(  24), -INT8_C(  92),  INT8_C(  22), -INT8_C( 124), -INT8_C(  38),
         INT8_C(  48), -INT8_C(  39),  INT8_C(   7),  INT8_C(  44), -INT8_C(  25), -INT8_C(  60), -INT8_C(  18),  INT8_C(  44) },
      { -INT8_C(  58), -INT8_C( 125),  INT8_C(  64),  INT8_C(  62), -INT8_C(  47), -INT8_C( 115),  INT8_C( 106),  INT8_C(  69),
        -INT8_C(  10), -INT8_C(  39), -INT8_C(  36), -INT8_C( 106), -INT8_C(  25),  INT8_C(  37), -INT8_C(   5), -INT8_C(  75) },
      UINT16_C(16912) },
    { UINT16_C(55699),
      { -INT8_C(  35), -INT8_C(  29), -INT8_C(  36),  INT8_C(  71),  INT8_C(  40), -INT8_C(  46), -INT8_C(  78),  INT8_C(   5),
         INT8_C( 104),  INT8_C(   0),  INT8_C(  42),  INT8_C( 100), -INT8_C(  75), -INT8_C(  71), -INT8_C( 109),  INT8_C(  82) },
      { -INT8_C(  20), -INT8_C(  40),  INT8_C( 115), -INT8_C(   6),  INT8_C(  40),  INT8_C( 110), -INT8_C(  78),  INT8_C(   5),
         INT8_C(  80), -INT8_C(  25),  INT8_C(  42),  INT8_C(  94), -INT8_C(  75), -INT8_C( 113), -INT8_C(  83),  INT8_C(  82) },
      UINT16_C(53393) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__mmask16 k = test_vec[i].k;
    simde__m128i a = simde_x_mm_loadu_epi8(test_vec[i].a);
    simde__m128i b = simde_x_mm_loadu_epi8(test_vec[i].b);
    simde__mmask16 r = simde_mm_mask_cmple_epi8_mask(k, a, b);
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
    simde__mmask16 r = simde_mm_mask_cmple_epi8_mask(k, a, b);

    simde_test_x86_write_mmask16(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i8x16(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i8x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_x_mm256_cmple_epi8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int8_t a[32];
    const int8_t b[32];
    const int8_t r[32];
  } test_vec[] = {
    { {  INT8_C(  62),  INT8_C( 117),  INT8_C(  86), -INT8_C(  68),  INT8_C(  49),  INT8_C(  44), -INT8_C(  53), -INT8_C( 127),
         INT8_C(  58),  INT8_C(  47),  INT8_C(  60),  INT8_C(  95), -INT8_C( 112),  INT8_C( 120),  INT8_C(  81), -INT8_C(  45),
        -INT8_C(   9),  INT8_C(  94),  INT8_C(  67), -INT8_C(  76),  INT8_C(  73),  INT8_C(  34), -INT8_C(  92), -INT8_C( 110),
         INT8_C(  18),  INT8_C(  52), -INT8_C(  75), -INT8_C(  59), -INT8_C(  98), -INT8_C( 105),  INT8_C( 113), -INT8_C(  36) },
      {  INT8_C(  13),  INT8_C( 117), -INT8_C( 103), -INT8_C(  68), -INT8_C(  13),  INT8_C( 100), -INT8_C(  64),  INT8_C(  45),
        -INT8_C( 108), -INT8_C(   4), -INT8_C( 116),  INT8_C(  95),  INT8_C( 116), -INT8_C(  35),  INT8_C(  81),  INT8_C( 108),
         INT8_C(  59),  INT8_C(  94),  INT8_C(  32), -INT8_C( 123),  INT8_C(  73), -INT8_C(  60),  INT8_C(  23), -INT8_C( 110),
        -INT8_C(   8),  INT8_C(  52),  INT8_C(  53), -INT8_C( 105),  INT8_C( 100), -INT8_C(  90),  INT8_C( 115), -INT8_C(  36) },
      {  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
         INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
        -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
         INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1) } },
    { {  INT8_C(  63),  INT8_C(  31), -INT8_C(  44), -INT8_C(  80), -INT8_C( 114),  INT8_C(  98), -INT8_C(  75), -INT8_C(   6),
         INT8_C( 123), -INT8_C(  33), -INT8_C(  38),  INT8_C( 114),  INT8_C(   0),  INT8_C(  38), -INT8_C(  92),  INT8_C(  93),
        -INT8_C( 110),  INT8_C(  91),  INT8_C(  24), -INT8_C(  62),  INT8_C(  41),  INT8_C(  66), -INT8_C(  22), -INT8_C(  61),
        -INT8_C(  94), -INT8_C(  86), -INT8_C(  62), -INT8_C(  87), -INT8_C(  35),  INT8_C(  49),  INT8_C(  29),  INT8_C(  28) },
      {  INT8_C(  63),  INT8_C(  31), -INT8_C(  51), -INT8_C(  33),  INT8_C(  83),  INT8_C(  98), -INT8_C(  39), -INT8_C(   6),
         INT8_C(  97), -INT8_C(  77),  INT8_C(  65),  INT8_C( 114),  INT8_C(   0), -INT8_C(  27), -INT8_C(  65),  INT8_C(  93),
         INT8_C(  64),  INT8_C(  91),  INT8_C(  45),  INT8_C( 105),  INT8_C(  41),  INT8_C(  23),  INT8_C(  44), -INT8_C(  68),
        -INT8_C(  94), -INT8_C(  18), -INT8_C(  62), -INT8_C(  87),  INT8_C(  32), -INT8_C( 126), -INT8_C(  69),  INT8_C( 112) },
      { -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
         INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
        -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
        -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1) } },
    { {  INT8_C(   7),  INT8_C(  96),  INT8_C(  95),  INT8_C(  17), -INT8_C( 119), -INT8_C(  11),  INT8_C( 125),  INT8_C( 100),
        -INT8_C(  51),  INT8_C(  75),  INT8_C(  25), -INT8_C( 119), -INT8_C(  39),  INT8_C(  56), -INT8_C( 122),  INT8_C(  62),
        -INT8_C( 123), -INT8_C(  21), -INT8_C(  67), -INT8_C(  23),  INT8_C( 125), -INT8_C(   8),  INT8_C(  14), -INT8_C(   2),
        -INT8_C( 103), -INT8_C(  46), -INT8_C(  98), -INT8_C(  67),  INT8_C(  81), -INT8_C(  81),  INT8_C(  84),  INT8_C(  88) },
      {  INT8_C(  16), -INT8_C(  77),  INT8_C( 106), -INT8_C( 103), -INT8_C(  87), -INT8_C(  25), -INT8_C(   3),  INT8_C( 100),
         INT8_C(  51),  INT8_C(  75),  INT8_C(  25),  INT8_C(  12),  INT8_C(  79), -INT8_C( 123),  INT8_C(  74), -INT8_C(  44),
         INT8_C( 113),  INT8_C(   7), -INT8_C(  67), -INT8_C(  18), -INT8_C(   1), -INT8_C(  53), -INT8_C(  20), -INT8_C( 103),
        -INT8_C(  98), -INT8_C(  46), -INT8_C(  98), -INT8_C(  17),  INT8_C(  58), -INT8_C(  81),  INT8_C(  72),  INT8_C(  88) },
      { -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
        -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
        -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
        -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1) } },
    { {  INT8_C(  42),  INT8_C(  65),  INT8_C(  39), -INT8_C(  60),  INT8_C(  34), -INT8_C(  92), -INT8_C( 112),  INT8_C(  26),
         INT8_C(  33),  INT8_C( 105),  INT8_C(  96),  INT8_C(  35), -INT8_C( 117),  INT8_C( 123), -INT8_C( 106), -INT8_C(  75),
         INT8_C(  82), -INT8_C(   9), -INT8_C(  34), -INT8_C(  11),  INT8_C(  69), -INT8_C(  96),  INT8_C(  54),  INT8_C(  30),
        -INT8_C(  72),  INT8_C( 103),  INT8_C(  50),  INT8_C( 122), -INT8_C(  33), -INT8_C( 112), -INT8_C( 101),  INT8_C(  10) },
      { -INT8_C(  47), -INT8_C(  62),  INT8_C(  39), -INT8_C(  12),  INT8_C( 103),  INT8_C(  94),  INT8_C(  14),  INT8_C(  26),
         INT8_C(  33),  INT8_C( 105), -INT8_C(  85),  INT8_C(  83), -INT8_C(  23),  INT8_C(  65),  INT8_C(   8),  INT8_C(  60),
         INT8_C(  56), -INT8_C(  26),  INT8_C(  49),  INT8_C( 126), -INT8_C( 122), -INT8_C(  96), -INT8_C( 100),  INT8_C(  62),
        -INT8_C(  49), -INT8_C(  50), -INT8_C(  72), -INT8_C(  82),  INT8_C(  94),  INT8_C(  83), -INT8_C(  72),  INT8_C(  48) },
      {  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
        -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
         INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
        -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1) } },
    { {  INT8_C(  28), -INT8_C(  59),  INT8_C(  80),  INT8_C(   1), -INT8_C(   9),  INT8_C(  85), -INT8_C(  83), -INT8_C( 105),
         INT8_C(   5), -INT8_C(  83),  INT8_C(  33), -INT8_C(  10), -INT8_C(  76), -INT8_C(  25),  INT8_C(  32), -INT8_C(  94),
        -INT8_C(  33), -INT8_C(  57),  INT8_C(  21),  INT8_C(  62),  INT8_C(  11), -INT8_C(  57),  INT8_C( 109),  INT8_C(  30),
         INT8_C(  49),  INT8_C(  74), -INT8_C( 113), -INT8_C(  18), -INT8_C(  33),  INT8_C(  48), -INT8_C(  62), -INT8_C(   5) },
      { -INT8_C(  11), -INT8_C(  59), -INT8_C(   4), -INT8_C(  20),  INT8_C( 104),  INT8_C(  85), -INT8_C( 125),  INT8_C( 109),
         INT8_C(  87), -INT8_C(  91),  INT8_C( 100),  INT8_C(  11), -INT8_C( 116), -INT8_C( 124), -INT8_C(  83),  INT8_C( 107),
         INT8_C(  75), -INT8_C(  61), -INT8_C(  86),  INT8_C(  87), -INT8_C( 118),  INT8_C(  23),  INT8_C( 117), -INT8_C(  69),
         INT8_C(  97),  INT8_C(  74), -INT8_C( 113),  INT8_C(  64),  INT8_C(  52),  INT8_C(  48), -INT8_C(  62),  INT8_C(  41) },
      {  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
        -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
        -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
        -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1) } },
    { {  INT8_C(  12), -INT8_C(  55),  INT8_C( 115), -INT8_C(  17),  INT8_C(  97), -INT8_C(  57),  INT8_C(  40), -INT8_C(  97),
         INT8_C( 126),  INT8_C( 109),  INT8_C( 105), -INT8_C(  70),  INT8_C(  96), -INT8_C(  98),  INT8_C(  65),  INT8_C(  21),
         INT8_C( 126),  INT8_C(  31),  INT8_C(  85),  INT8_C( 116),  INT8_C( 114),  INT8_C(  79), -INT8_C(  52), -INT8_C(  55),
        -INT8_C(  13),  INT8_C( 100),  INT8_C(  84),  INT8_C(   3),  INT8_C(  56),  INT8_C(   8), -INT8_C( 112),  INT8_C(  68) },
      { -INT8_C(  47),  INT8_C(   4),  INT8_C(  51),  INT8_C(  50), -INT8_C(  53),  INT8_C(  92), -INT8_C(  47),  INT8_C(  73),
        -INT8_C(  55),  INT8_C(  58),  INT8_C(   3),  INT8_C(  41), -INT8_C(  39),  INT8_C(  68),  INT8_C(  63),  INT8_C(  87),
         INT8_C(  99), -INT8_C( 108),  INT8_C(  85), -INT8_C(  43), -INT8_C(  29), -INT8_C( 105), -INT8_C(  52), -INT8_C(  55),
        -INT8_C(   5), -INT8_C(  14),  INT8_C(  84),  INT8_C(  51),  INT8_C(  56),  INT8_C(   8),  INT8_C( 120), -INT8_C(  53) },
      {  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
         INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
         INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
        -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0) } },
    { { -INT8_C(  17),  INT8_C(  89),  INT8_C( 116), -INT8_C(   9),  INT8_C(  40), -INT8_C(   9), -INT8_C(  56),  INT8_C(  50),
         INT8_C( 126), -INT8_C(  62),  INT8_C(  21),  INT8_C(  73), -INT8_C(   4),  INT8_C(  79),  INT8_C( 119), -INT8_C(  55),
         INT8_C(  85),  INT8_C( 123),  INT8_C( 122), -INT8_C(  14),  INT8_C(  30),  INT8_C(   2), -INT8_C( 118), -INT8_C(  77),
         INT8_C( 100),  INT8_C(  86),  INT8_C(  66),  INT8_C(  49), -INT8_C( 102), -INT8_C(  99),  INT8_C( 108), -INT8_C( 118) },
      { -INT8_C(  17),  INT8_C(  89),  INT8_C( 116), -INT8_C(   9), -INT8_C(  40),  INT8_C(  73),  INT8_C(  81),  INT8_C(  50),
         INT8_C(  11),  INT8_C( 103),  INT8_C(  21),  INT8_C(   7), -INT8_C(  74),  INT8_C(  22), -INT8_C(  47),  INT8_C(  11),
         INT8_C(  85),  INT8_C( 123), -INT8_C(   3), -INT8_C(  80),  INT8_C(  30),  INT8_C(   2),  INT8_C(  99), -INT8_C(  78),
        -INT8_C(  34),  INT8_C(  86),  INT8_C(  66),  INT8_C( 121), -INT8_C( 102),  INT8_C(  79),  INT8_C(   3), -INT8_C( 118) },
      { -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
         INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
        -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
         INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1) } },
    { {  INT8_C(  55),  INT8_C(  51),  INT8_C( 104),  INT8_C(   4), -INT8_C(  35), -INT8_C(  58), -INT8_C(  36), -INT8_C(  18),
        -INT8_C(  61), -INT8_C(  68), -INT8_C(  75), -INT8_C(  42),  INT8_C( 109), -INT8_C( 120),  INT8_C( 124),  INT8_C( 106),
         INT8_C(  89), -INT8_C(  47), -INT8_C(  76), -INT8_C(  79), -INT8_C( 118), -INT8_C(  79), -INT8_C(  24), -INT8_C(  24),
        -INT8_C( 110), -INT8_C( 104), -INT8_C( 119), -INT8_C(  62),  INT8_C(  75),  INT8_C(  99),  INT8_C(  34), -INT8_C( 126) },
      { -INT8_C( 106), -INT8_C( 118), -INT8_C( 122),  INT8_C( 115),  INT8_C(  80),  INT8_C(  99), -INT8_C(  36),  INT8_C(  19),
        -INT8_C(  61),  INT8_C(  23), -INT8_C(  23), -INT8_C( 115), -INT8_C(  97),  INT8_C( 101),  INT8_C( 124), -INT8_C(   8),
         INT8_C(  55), -INT8_C(  85), -INT8_C(  86), -INT8_C(  63), -INT8_C( 118), -INT8_C(  79), -INT8_C(  87), -INT8_C(  17),
         INT8_C(  43),  INT8_C(  50), -INT8_C(  79),  INT8_C( 118), -INT8_C( 107), -INT8_C(  45), -INT8_C(   7),  INT8_C(  44) },
      {  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
        -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
         INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
        -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256i a = simde_mm256_loadu_epi8(test_vec[i].a);
    simde__m256i b = simde_mm256_loadu_epi8(test_vec[i].b);
    simde__m256i r = simde_x_mm256_cmple_epi8(a, b);
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
    simde__m256i r = simde_x_mm256_cmple_epi8(a, b);

    simde_test_x86_write_i8x32(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i8x32(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i8x32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_cmple_epi8_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int8_t a[32];
    const int8_t b[32];
    const simde__mmask32 r;
  } test_vec[] = {
    { {  INT8_C(  11), -INT8_C(  26), -INT8_C(  34),  INT8_C( 101), -INT8_C(   4),  INT8_C(  19), -INT8_C( 110), -INT8_C(  34),
        -INT8_C(  25), -INT8_C(   1), -INT8_C(  29),  INT8_C(  39), -INT8_C(  84), -INT8_C(   7), -INT8_C(  21), -INT8_C( 121),
        -INT8_C( 126),  INT8_C( 113),  INT8_C( 126),  INT8_C(  50),  INT8_C( 125), -INT8_C(   1), -INT8_C(  29), -INT8_C(  62),
         INT8_C(  59),  INT8_C(  60), -INT8_C(  64),  INT8_C(  13), -INT8_C( 114), -INT8_C(   6),  INT8_C( 106), -INT8_C( 103) },
      {  INT8_C(  11),  INT8_C(  72), -INT8_C(   1), -INT8_C(  35), -INT8_C(   4), -INT8_C( 111), -INT8_C(  69), -INT8_C(  34),
        -INT8_C(  25), -INT8_C(   1),  INT8_C( 106),  INT8_C(  39), -INT8_C( 104),  INT8_C(  85), -INT8_C(  60), -INT8_C( 121),
        -INT8_C( 126),  INT8_C(  66),  INT8_C( 126),  INT8_C(  68),  INT8_C(  65),  INT8_C(  48),  INT8_C(   6),  INT8_C( 125),
         INT8_C( 108), -INT8_C(  57), -INT8_C( 118), -INT8_C(   6), -INT8_C(  63), -INT8_C(   6), -INT8_C( 109), -INT8_C(  94) },
      UINT32_C(2985144279) },
    { { -INT8_C( 109),  INT8_C(  84),  INT8_C(   9), -INT8_C(  73), -INT8_C( 114), -INT8_C(  29),  INT8_C( 107),  INT8_C( 103),
         INT8_C(  39),  INT8_C(  93), -INT8_C(  41), -INT8_C(  63),  INT8_C(  18),  INT8_C(  98),  INT8_C(  33),  INT8_C(  10),
         INT8_C(  57), -INT8_C(  58),  INT8_C(  68),  INT8_C(  64),  INT8_C( 113), -INT8_C(   6), -INT8_C(  77), -INT8_C(  29),
         INT8_C(  59),  INT8_C(  32),  INT8_C(  22),  INT8_C( 113),  INT8_C(  32), -INT8_C(  20), -INT8_C(  29), -INT8_C(  77) },
      {  INT8_C(  64), -INT8_C(  20),  INT8_C( 106), -INT8_C(  49), -INT8_C( 114), -INT8_C(  29),  INT8_C(  54), -INT8_C(   9),
         INT8_C(  51),  INT8_C(  13), -INT8_C(  41),  INT8_C(  69),  INT8_C(  18),  INT8_C(  98),  INT8_C(  80),  INT8_C(  10),
         INT8_C(  57), -INT8_C( 108), -INT8_C(  24),  INT8_C(  17), -INT8_C( 114), -INT8_C( 101), -INT8_C(  12), -INT8_C(  54),
         INT8_C(  59),  INT8_C(  32),  INT8_C(  59), -INT8_C(  36), -INT8_C(  10), -INT8_C(  20), -INT8_C( 113), -INT8_C(  77) },
      UINT32_C(2806119741) },
    { {  INT8_C(   6),  INT8_C(  71), -INT8_C(  61), -INT8_C(  42), -INT8_C( 125), -INT8_C( 107), -INT8_C(  39), -INT8_C(  51),
         INT8_C(  31),  INT8_C(  34), -INT8_C( 122), -INT8_C( 124), -INT8_C(  70), -INT8_C(  25), -INT8_C( 120), -INT8_C(  25),
         INT8_C(  49), -INT8_C(  98), -INT8_C(  94),  INT8_C(  23), -INT8_C(  89),  INT8_C(  39), -INT8_C(  72), -INT8_C(  69),
        -INT8_C(  25),  INT8_C(  53), -INT8_C(  58), -INT8_C(  59),  INT8_C(  65),  INT8_C(   7), -INT8_C(  83),  INT8_C(  72) },
      {  INT8_C(  79),  INT8_C( 112),  INT8_C(  30), -INT8_C(  42),  INT8_C(   5), -INT8_C(   8), -INT8_C(  97), -INT8_C(  51),
         INT8_C(  26),  INT8_C(  37), -INT8_C(  87), -INT8_C(  44),  INT8_C(  13), -INT8_C(  25), -INT8_C(  69),  INT8_C(  62),
        -INT8_C(  49),  INT8_C(  93),  INT8_C(  85),  INT8_C( 119), -INT8_C( 124),  INT8_C(  39),  INT8_C(  50),  INT8_C( 107),
         INT8_C(  66), -INT8_C(   8),  INT8_C(  48), -INT8_C( 124),  INT8_C(  65), -INT8_C(  34), -INT8_C(  83),  INT8_C(  79) },
      UINT32_C(3589209791) },
    { {  INT8_C(  18),  INT8_C(  53), -INT8_C( 117), -INT8_C(  12), -INT8_C(  10),  INT8_C(   4), -INT8_C(  15), -INT8_C(  35),
         INT8_C(  38), -INT8_C(  62), -INT8_C(  48),  INT8_C( 121),  INT8_C(  78),  INT8_C(   2), -INT8_C( 100),  INT8_C(  56),
        -INT8_C( 118),  INT8_C(  54), -INT8_C(  89),  INT8_C(  31),  INT8_C(   3), -INT8_C( 127), -INT8_C(  10), -INT8_C(  56),
        -INT8_C( 117),  INT8_C(  82), -INT8_C( 115),  INT8_C( 116),  INT8_C( 121), -INT8_C(  95), -INT8_C(  85), -INT8_C( 117) },
      { -INT8_C(  42),  INT8_C(  54),      INT8_MIN, -INT8_C(  12), -INT8_C(  10),  INT8_C( 113), -INT8_C(  15),  INT8_C(  96),
         INT8_C(  51),  INT8_C( 122), -INT8_C(  39), -INT8_C( 127),  INT8_C(  78),  INT8_C( 118), -INT8_C(  70),  INT8_C(  56),
        -INT8_C( 118),  INT8_C(  97), -INT8_C(  89), -INT8_C(  81),  INT8_C(   3),  INT8_C(  28),  INT8_C( 119),  INT8_C( 109),
        -INT8_C( 117),  INT8_C(   4), -INT8_C(  31), -INT8_C(  24), -INT8_C(  91), -INT8_C( 116),  INT8_C( 115), -INT8_C( 117) },
      UINT32_C(3321362426) },
    { { -INT8_C(  15), -INT8_C(  18), -INT8_C(  80),  INT8_C(  86), -INT8_C(  31),  INT8_C(  13), -INT8_C(  19),  INT8_C(  79),
         INT8_C(  67),  INT8_C(   6),  INT8_C(  57), -INT8_C(  17), -INT8_C(  39),  INT8_C(  43),  INT8_C(  71),  INT8_C(  13),
         INT8_C(  66),  INT8_C(  79),  INT8_C(  35),  INT8_C( 118), -INT8_C(  49), -INT8_C(  89),  INT8_C(  25),  INT8_C(  83),
         INT8_C(  12), -INT8_C(  93),  INT8_C( 124), -INT8_C(   3), -INT8_C(  95),  INT8_C(  34), -INT8_C(  79), -INT8_C( 109) },
      {  INT8_C(  16), -INT8_C(  18), -INT8_C(  23), -INT8_C(  14),  INT8_C( 111),  INT8_C(  13), -INT8_C(  19),  INT8_C(  79),
        -INT8_C(  35),  INT8_C( 122), -INT8_C(  95), -INT8_C(  17), -INT8_C(  91), -INT8_C(  24),  INT8_C(  71), -INT8_C(  24),
         INT8_C(  56), -INT8_C(  25),  INT8_C(  94),  INT8_C( 118), -INT8_C( 114),  INT8_C( 119),  INT8_C(  90), -INT8_C( 102),
         INT8_C(  27), -INT8_C(  42), -INT8_C( 104), -INT8_C(  68), -INT8_C(  95),  INT8_C(  73),  INT8_C(  79), -INT8_C( 109) },
      UINT32_C(4083960567) },
    { {  INT8_C( 121), -INT8_C(  62),  INT8_C(  30), -INT8_C( 120), -INT8_C(   2), -INT8_C(  21),  INT8_C( 116), -INT8_C(  76),
         INT8_C(  88),  INT8_C(  23),  INT8_C(  16), -INT8_C(  82),  INT8_C( 125),  INT8_C(  84),  INT8_C(  60), -INT8_C(  53),
        -INT8_C(   9), -INT8_C(  47), -INT8_C(  88),  INT8_C(  17), -INT8_C(  64),  INT8_C(  31),  INT8_C(  70), -INT8_C( 122),
         INT8_C(  46),  INT8_C(  55),  INT8_C(  68), -INT8_C( 122),  INT8_C( 120),  INT8_C(  11), -INT8_C( 118), -INT8_C(  14) },
      { -INT8_C(  51), -INT8_C(  87),  INT8_C( 122), -INT8_C(  53), -INT8_C( 108), -INT8_C(  17),      INT8_MAX, -INT8_C(  76),
         INT8_C(   6), -INT8_C( 112), -INT8_C( 101), -INT8_C( 125), -INT8_C(  28), -INT8_C(  41),  INT8_C(  79), -INT8_C(  37),
        -INT8_C(  87), -INT8_C(   9), -INT8_C(  20),  INT8_C( 105),  INT8_C(  22),  INT8_C(  50), -INT8_C(  17),  INT8_C(  68),
         INT8_C( 106),  INT8_C(  51), -INT8_C(  54), -INT8_C(  30),  INT8_C(  62),  INT8_C(  85), -INT8_C( 118),  INT8_C(  11) },
      UINT32_C(3921592556) },
    { {  INT8_C(  53),  INT8_C(  71),  INT8_C(  23),  INT8_C( 115), -INT8_C(  99), -INT8_C( 107), -INT8_C(  73), -INT8_C( 125),
        -INT8_C(  81),  INT8_C( 126),  INT8_C(  77), -INT8_C(  96), -INT8_C( 107), -INT8_C(  13),  INT8_C(  58), -INT8_C(  94),
        -INT8_C( 122),  INT8_C(  61), -INT8_C(  58),  INT8_C(  75),  INT8_C(  48),  INT8_C(  45),  INT8_C( 122),  INT8_C(  87),
         INT8_C(  95), -INT8_C( 117), -INT8_C(  68), -INT8_C(  26),  INT8_C( 113),  INT8_C(  44),  INT8_C( 107), -INT8_C(  90) },
      {  INT8_C( 115),  INT8_C(  71),  INT8_C(  25),  INT8_C(  16),  INT8_C(  24), -INT8_C(  48), -INT8_C( 109), -INT8_C( 125),
         INT8_C(  79),  INT8_C( 126),  INT8_C(  77), -INT8_C(  28), -INT8_C(  44), -INT8_C(  95), -INT8_C( 122),  INT8_C(  90),
        -INT8_C(  34),  INT8_C(  76), -INT8_C(  91),  INT8_C(  15),  INT8_C( 122),  INT8_C(  45),  INT8_C( 102), -INT8_C(  39),
        -INT8_C(  85),  INT8_C(  34), -INT8_C(  64),  INT8_C(  28),  INT8_C(  78),  INT8_C(  43), -INT8_C(  61), -INT8_C(  90) },
      UINT32_C(2385747895) },
    { { -INT8_C(  94), -INT8_C(  19),  INT8_C( 102),  INT8_C(  79),  INT8_C(  83), -INT8_C(  13),  INT8_C(  75), -INT8_C( 102),
        -INT8_C(  25),  INT8_C(  43), -INT8_C(  74),  INT8_C( 124), -INT8_C( 111),  INT8_C(  44), -INT8_C(  17),  INT8_C(  68),
         INT8_C(  71),  INT8_C( 114),  INT8_C( 113), -INT8_C( 126),  INT8_C(  90),  INT8_C( 120),  INT8_C( 104),  INT8_C( 101),
         INT8_C(  62),  INT8_C( 107), -INT8_C(  66),  INT8_C(  48),  INT8_C(  48), -INT8_C(  39), -INT8_C(  48), -INT8_C(  46) },
      { -INT8_C(  58), -INT8_C(  19),  INT8_C(  33),  INT8_C(  26),  INT8_C(  41),  INT8_C( 108), -INT8_C(  76), -INT8_C( 102),
        -INT8_C(  25),  INT8_C( 106), -INT8_C( 116),  INT8_C(  41), -INT8_C( 106),  INT8_C( 124), -INT8_C(  17), -INT8_C(  34),
        -INT8_C(  18), -INT8_C(  33),  INT8_C(  96),  INT8_C(  72),  INT8_C(  87), -INT8_C(  55), -INT8_C(  83), -INT8_C( 107),
         INT8_C(  52),  INT8_C( 107), -INT8_C(  58),  INT8_C( 100),  INT8_C(  68), -INT8_C( 106),  INT8_C(  55), -INT8_C(  46) },
      UINT32_C(3725095843) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256i a = simde_mm256_loadu_epi8(test_vec[i].a);
    simde__m256i b = simde_mm256_loadu_epi8(test_vec[i].b);
    simde__mmask32 r = simde_mm256_cmple_epi8_mask(a, b);
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
    simde__mmask32 r = simde_mm256_cmple_epi8_mask(a, b);

    simde_test_x86_write_i8x32(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i8x32(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_mask_cmple_epi8_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask32 k;
    const int8_t a[32];
    const int8_t b[32];
    const simde__mmask32 r;
  } test_vec[] = {
    { UINT32_C( 448367164),
      {  INT8_C(  10), -INT8_C(  45), -INT8_C(  34), -INT8_C(  49), -INT8_C(  83), -INT8_C(  27),  INT8_C(  43), -INT8_C(  15),
         INT8_C( 121), -INT8_C(  79), -INT8_C(  53), -INT8_C( 120), -INT8_C(  92), -INT8_C( 124), -INT8_C( 122),  INT8_C( 118),
        -INT8_C(  99), -INT8_C(  52), -INT8_C(  97),      INT8_MAX, -INT8_C(  65),  INT8_C(  93), -INT8_C( 107),  INT8_C(  30),
        -INT8_C(  30),  INT8_C(  15), -INT8_C(  62), -INT8_C(   3), -INT8_C(  63),  INT8_C( 112), -INT8_C(  27), -INT8_C(  53) },
      {  INT8_C(  10), -INT8_C(  45), -INT8_C( 102), -INT8_C(  15), -INT8_C(  87), -INT8_C(  27), -INT8_C(  30), -INT8_C(  15),
         INT8_C( 118), -INT8_C(  83), -INT8_C(  86),  INT8_C(  26),  INT8_C(  49),  INT8_C(  48), -INT8_C( 112), -INT8_C(  50),
        -INT8_C(   4),  INT8_C(  47),  INT8_C(  77), -INT8_C(  68), -INT8_C( 115), -INT8_C(  30), -INT8_C(  38),  INT8_C( 111),
        -INT8_C(  14), -INT8_C( 100),  INT8_C( 108), -INT8_C(  77),  INT8_C(  13),  INT8_C( 112), -INT8_C(  27), -INT8_C(  53) },
      UINT32_C( 276891688) },
    { UINT32_C(1019153136),
      { -INT8_C(  82), -INT8_C( 103),  INT8_C( 110),      INT8_MAX,  INT8_C(  35), -INT8_C(  36), -INT8_C( 126), -INT8_C(  35),
        -INT8_C(  37),  INT8_C(  84), -INT8_C( 108),  INT8_C(  10),  INT8_C( 115),  INT8_C(   7), -INT8_C(  59),  INT8_C( 116),
         INT8_C(  85), -INT8_C(  16),  INT8_C( 104),  INT8_C(  63), -INT8_C( 122),  INT8_C(  14),  INT8_C(  54),  INT8_C( 110),
         INT8_C(  51),  INT8_C( 126),  INT8_C( 106),  INT8_C( 111),  INT8_C(   8),  INT8_C(  35), -INT8_C( 119), -INT8_C(  74) },
      { -INT8_C(  68), -INT8_C( 103),  INT8_C(  53), -INT8_C(  33),  INT8_C(  35), -INT8_C(  72), -INT8_C(  67), -INT8_C(  35),
         INT8_C(  12),  INT8_C(  81), -INT8_C(  71),  INT8_C(  10),  INT8_C(  89),      INT8_MAX, -INT8_C(  13),  INT8_C( 116),
         INT8_C( 111),  INT8_C(  91), -INT8_C(  19),  INT8_C(  63),  INT8_C( 106),  INT8_C(  35),  INT8_C(  99), -INT8_C(  99),
        -INT8_C(  95), -INT8_C(  51),  INT8_C( 106),  INT8_C( 111),  INT8_C(   8), -INT8_C( 106),  INT8_C(  95), -INT8_C(  83) },
      UINT32_C( 473630928) },
    { UINT32_C( 294133345),
      {  INT8_C(  84), -INT8_C(  48), -INT8_C( 107), -INT8_C(  16), -INT8_C( 102),  INT8_C( 108), -INT8_C(  28), -INT8_C(  28),
         INT8_C(  55), -INT8_C( 121), -INT8_C( 100),  INT8_C(  94),  INT8_C(  22),  INT8_C(  74), -INT8_C(  18), -INT8_C(  55),
         INT8_C(  92),  INT8_C(  28),  INT8_C(  28),  INT8_C(  59),  INT8_C(  86),  INT8_C(  25),  INT8_C(  11),  INT8_C(  38),
         INT8_C( 116), -INT8_C( 120), -INT8_C( 125),  INT8_C( 100), -INT8_C( 109),  INT8_C(  66), -INT8_C(  95), -INT8_C(  25) },
      {  INT8_C(  84), -INT8_C(  48), -INT8_C( 107), -INT8_C(  83), -INT8_C( 102), -INT8_C(  68), -INT8_C(  28), -INT8_C(  38),
         INT8_C(  67), -INT8_C( 121),  INT8_C(  56),  INT8_C(  89),  INT8_C( 120),  INT8_C(  38),  INT8_C(  34), -INT8_C(  44),
         INT8_C(  66),  INT8_C(  63),  INT8_C(  15), -INT8_C( 104),  INT8_C(  88),  INT8_C(  25), -INT8_C(  66), -INT8_C(  52),
        -INT8_C(  94), -INT8_C( 120),  INT8_C(  49),  INT8_C(  53), -INT8_C( 124),  INT8_C(  66),  INT8_C(  29), -INT8_C( 105) },
      UINT32_C(      5697) },
    { UINT32_C(4155605870),
      { -INT8_C(  13),  INT8_C(  13),  INT8_C(   5), -INT8_C(  11), -INT8_C(  55),  INT8_C(  82),  INT8_C( 112), -INT8_C(  84),
        -INT8_C(  63), -INT8_C(  66), -INT8_C(  46),  INT8_C( 112),  INT8_C(  28), -INT8_C( 112),  INT8_C( 118), -INT8_C( 109),
         INT8_C(  12),  INT8_C(  73), -INT8_C(  83), -INT8_C(  53),  INT8_C(  77), -INT8_C(   3),  INT8_C(  14),  INT8_C(  35),
         INT8_C( 105), -INT8_C(  24),  INT8_C(   1), -INT8_C(  54),  INT8_C(   6), -INT8_C( 118), -INT8_C(  36), -INT8_C(   7) },
      { -INT8_C(  13), -INT8_C(  31),  INT8_C(   5),  INT8_C(  96), -INT8_C(  55),  INT8_C(  94),  INT8_C(  13), -INT8_C(  12),
        -INT8_C(  63), -INT8_C(  66),  INT8_C( 100),  INT8_C(  57),  INT8_C( 111), -INT8_C(  37), -INT8_C(  52),  INT8_C( 123),
         INT8_C(  36),  INT8_C( 122),  INT8_C(  70), -INT8_C(  53),  INT8_C( 119),  INT8_C(  84),  INT8_C(  14), -INT8_C(  32),
         INT8_C(  60), -INT8_C( 105), -INT8_C(  85),  INT8_C(  66),  INT8_C(  33), -INT8_C( 118),  INT8_C(  59), -INT8_C(  72) },
      UINT32_C(1882293036) },
    { UINT32_C(3113982045),
      { -INT8_C(  87),  INT8_C(  65), -INT8_C( 100), -INT8_C(  83),  INT8_C(  53),  INT8_C( 123),  INT8_C(  33),  INT8_C(   4),
         INT8_C(  38),  INT8_C(  16), -INT8_C(   9),  INT8_C(  75),  INT8_C(  69),  INT8_C(  93), -INT8_C(  25), -INT8_C(  49),
         INT8_C(  88),  INT8_C(  99), -INT8_C( 106), -INT8_C(  22), -INT8_C( 117), -INT8_C(  97), -INT8_C(  99),  INT8_C(  57),
        -INT8_C(  29),  INT8_C(   8),  INT8_C(  80),  INT8_C(  82), -INT8_C( 117),  INT8_C(   1),  INT8_C(  73),  INT8_C(  52) },
      {  INT8_C(  66), -INT8_C(  27), -INT8_C( 100),  INT8_C( 119),  INT8_C(  53),  INT8_C(   3),  INT8_C(  33), -INT8_C( 122),
         INT8_C(  19),  INT8_C( 115), -INT8_C(  47),  INT8_C(  88), -INT8_C(  48), -INT8_C(  72),  INT8_C(  40),  INT8_C(  40),
         INT8_C(  28),  INT8_C(  99),  INT8_C(  18), -INT8_C(  89),  INT8_C(  93), -INT8_C(  81), -INT8_C(  32),  INT8_C(  64),
        -INT8_C(  73),  INT8_C(  48), -INT8_C( 110),  INT8_C(  82),  INT8_C(  50),  INT8_C(   1),  INT8_C(  73),  INT8_C( 116) },
      UINT32_C(3096610909) },
    { UINT32_C(3519595060),
      {  INT8_C(   0),  INT8_C(  67),  INT8_C(  40), -INT8_C(  38), -INT8_C(  67), -INT8_C(  17), -INT8_C( 123), -INT8_C(  17),
        -INT8_C(  33),  INT8_C(  87),  INT8_C(  61), -INT8_C( 116),  INT8_C(  60),  INT8_C(  50), -INT8_C( 105), -INT8_C(  49),
         INT8_C(   7), -INT8_C(  30),  INT8_C(  26),  INT8_C(  13), -INT8_C(  65), -INT8_C(  89),  INT8_C(  69),  INT8_C( 120),
        -INT8_C(  85), -INT8_C(  14), -INT8_C(  14),  INT8_C(   8), -INT8_C( 118), -INT8_C( 114), -INT8_C(  63), -INT8_C( 118) },
      { -INT8_C(  47), -INT8_C(  23),  INT8_C( 101), -INT8_C( 114), -INT8_C(  40), -INT8_C(  22),  INT8_C( 125), -INT8_C(  73),
         INT8_C(  65), -INT8_C(  70),  INT8_C(  61),  INT8_C( 125), -INT8_C(  20), -INT8_C(  37),  INT8_C(  77), -INT8_C(  12),
         INT8_C(   7),  INT8_C( 103),  INT8_C(   1),  INT8_C( 124),  INT8_C(  14), -INT8_C(  89), -INT8_C(  11), -INT8_C(  71),
        -INT8_C(  85), -INT8_C(  14), -INT8_C(  63), -INT8_C(  61),  INT8_C( 117), -INT8_C( 126), -INT8_C(  63),  INT8_C(  71) },
      UINT32_C(3507011604) },
    { UINT32_C(2933042404),
      {  INT8_C(  21), -INT8_C(  61), -INT8_C(  81),  INT8_C(  34),  INT8_C(   2),  INT8_C(  11),  INT8_C(  28),  INT8_C(  28),
        -INT8_C(  76),  INT8_C(  10), -INT8_C(  13), -INT8_C(  60), -INT8_C(   6),  INT8_C(  71), -INT8_C(  30),  INT8_C(  48),
        -INT8_C( 113), -INT8_C(  71), -INT8_C(  96), -INT8_C(  65),  INT8_C(  81), -INT8_C(  45),  INT8_C( 101),  INT8_C( 107),
         INT8_C(  84),  INT8_C(  81), -INT8_C(  16), -INT8_C( 120),  INT8_C(  19), -INT8_C(  71),  INT8_C(  89),  INT8_C(  40) },
      {  INT8_C( 124),  INT8_C(   8),  INT8_C(  75),      INT8_MAX,  INT8_C(  20),  INT8_C( 103), -INT8_C( 101),  INT8_C(  28),
         INT8_C( 114), -INT8_C( 113), -INT8_C(  13),  INT8_C( 108), -INT8_C(  42),  INT8_C(  71), -INT8_C( 100),  INT8_C( 101),
         INT8_C(  41),  INT8_C(  60),  INT8_C(  37), -INT8_C(  65),  INT8_C(  81), -INT8_C( 118),  INT8_C( 101),  INT8_C(  99),
        -INT8_C(  37), -INT8_C(  42), -INT8_C(  21), -INT8_C(  17),  INT8_C(  19),  INT8_C(  68),  INT8_C(  23),  INT8_C(  12) },
      UINT32_C( 676506788) },
    { UINT32_C(2621450682),
      { -INT8_C(  45), -INT8_C(   5), -INT8_C(  22), -INT8_C( 120), -INT8_C(  78), -INT8_C( 110),  INT8_C(  20), -INT8_C(  40),
        -INT8_C(  41),  INT8_C(   5),  INT8_C(  39),  INT8_C(  88),  INT8_C(  27), -INT8_C(  16), -INT8_C(  24), -INT8_C(  69),
        -INT8_C(  96), -INT8_C(  36),  INT8_C(  54),  INT8_C(  38), -INT8_C(  68), -INT8_C(  95),  INT8_C(  59), -INT8_C(  32),
         INT8_C(  35),  INT8_C(  93),  INT8_C(  81),  INT8_C(   7),  INT8_C(   9),  INT8_C(  35), -INT8_C(  74), -INT8_C(  36) },
      { -INT8_C(  45), -INT8_C(  96),  INT8_C( 101), -INT8_C(  48),  INT8_C(  51),  INT8_C( 121), -INT8_C(  88), -INT8_C(  40),
         INT8_C( 126), -INT8_C(  49),  INT8_C(  98), -INT8_C( 103), -INT8_C(  64),  INT8_C(  74),  INT8_C(  84),  INT8_C(  96),
        -INT8_C(  96), -INT8_C(  36),  INT8_C(  54), -INT8_C(  29),  INT8_C(  43), -INT8_C(  63), -INT8_C(  61), -INT8_C(  32),
         INT8_C(  30),  INT8_C(  93),  INT8_C(  81),  INT8_C(  40),  INT8_C(   9),  INT8_C(  35),  INT8_C(   4), -INT8_C(  36) },
      UINT32_C(2617254328) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__mmask32 k = test_vec[i].k;
    simde__m256i a = simde_mm256_loadu_epi8(test_vec[i].a);
    simde__m256i b = simde_mm256_loadu_epi8(test_vec[i].b);
    simde__mmask32 r = simde_mm256_mask_cmple_epi8_mask(k, a, b);
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
    simde__mmask32 r = simde_mm256_mask_cmple_epi8_mask(k, a, b);

    simde_test_x86_write_mmask32(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i8x32(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i8x32(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_x_mm512_cmple_epi8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int8_t a[64];
    const int8_t b[64];
    const int8_t r[64];
  } test_vec[] = {
    { { -INT8_C(  90), -INT8_C(  13), -INT8_C( 105),  INT8_C(  71),  INT8_C( 103),  INT8_C(  39),  INT8_C( 111), -INT8_C(  58),
        -INT8_C(  76),  INT8_C( 103),  INT8_C( 112), -INT8_C(   6),  INT8_C( 100),  INT8_C( 100), -INT8_C(  22), -INT8_C(  79),
        -INT8_C(   2), -INT8_C( 113),  INT8_C( 103),  INT8_C(  48),  INT8_C( 121),  INT8_C(  65),  INT8_C(  35),  INT8_C(  28),
        -INT8_C(  18),  INT8_C( 105),  INT8_C(   5), -INT8_C(  34), -INT8_C( 124),  INT8_C(   3), -INT8_C(   8),  INT8_C(  43),
        -INT8_C(  10), -INT8_C( 113),  INT8_C( 114),  INT8_C(  94), -INT8_C(  74), -INT8_C(  31),  INT8_C(  36),  INT8_C( 107),
         INT8_C(  72), -INT8_C( 108),  INT8_C( 101), -INT8_C(  83), -INT8_C(   8),  INT8_C(  79),  INT8_C(  94), -INT8_C(  10),
        -INT8_C(  34), -INT8_C(  58),  INT8_C(  38),  INT8_C(  87),  INT8_C(   7),  INT8_C(  73),  INT8_C( 115), -INT8_C(  11),
        -INT8_C(  77),  INT8_C( 120), -INT8_C(  45),  INT8_C(  55),  INT8_C( 123), -INT8_C(  52),  INT8_C(  98),  INT8_C( 114) },
      {  INT8_C(  91), -INT8_C(  44), -INT8_C(  48),  INT8_C(  18),  INT8_C( 103), -INT8_C(  12),  INT8_C( 125), -INT8_C(  58),
        -INT8_C( 120),  INT8_C( 103), -INT8_C(  85),      INT8_MIN,  INT8_C(  49),  INT8_C( 100), -INT8_C(  22),  INT8_C(  16),
        -INT8_C(  48), -INT8_C( 113),  INT8_C( 103), -INT8_C(  41),  INT8_C( 121), -INT8_C(  37), -INT8_C(  52), -INT8_C( 104),
        -INT8_C(  18), -INT8_C(  96), -INT8_C(  48), -INT8_C(  34),  INT8_C( 108),  INT8_C(  50),  INT8_C(  65), -INT8_C(  57),
         INT8_C(   7),  INT8_C(  17),  INT8_C( 114), -INT8_C(  67),  INT8_C(   5),  INT8_C(  86), -INT8_C(  69), -INT8_C( 115),
         INT8_C(  56),  INT8_C( 103),  INT8_C(  13),  INT8_C( 106),  INT8_C( 113), -INT8_C( 125),  INT8_C(  94), -INT8_C(  10),
         INT8_C(  31), -INT8_C(  31),  INT8_C(  24),  INT8_C(   4), -INT8_C(  68), -INT8_C(  28), -INT8_C(  99),  INT8_C(  16),
        -INT8_C( 124),  INT8_C( 109), -INT8_C(  33),  INT8_C(  55), -INT8_C(  97),  INT8_C(  32), -INT8_C(  72), -INT8_C(  90) },
      { -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
         INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
         INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
        -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
        -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
         INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
        -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
         INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0) } },
    { { -INT8_C( 117),  INT8_C(   3),  INT8_C(  20), -INT8_C(  44), -INT8_C(  33),  INT8_C(  16), -INT8_C(  93), -INT8_C( 118),
        -INT8_C( 106),  INT8_C( 105), -INT8_C( 119),  INT8_C(  32),  INT8_C( 103), -INT8_C(   7), -INT8_C( 111), -INT8_C(  75),
        -INT8_C(  32), -INT8_C(  92),  INT8_C(  56), -INT8_C(  37),  INT8_C( 105),  INT8_C( 115),  INT8_C(  86), -INT8_C(  64),
         INT8_C(  88), -INT8_C(  15), -INT8_C(  55), -INT8_C(  97),  INT8_C(  82), -INT8_C(  76), -INT8_C(  40), -INT8_C(  34),
        -INT8_C(  73), -INT8_C(  19), -INT8_C(  78), -INT8_C( 106), -INT8_C(   3),  INT8_C(  86),  INT8_C(  33), -INT8_C( 109),
        -INT8_C(  65), -INT8_C(  86), -INT8_C(  77),  INT8_C(  39), -INT8_C(  93),  INT8_C(  68), -INT8_C(  36), -INT8_C( 124),
        -INT8_C(  24),  INT8_C(  20),  INT8_C(  95),  INT8_C(  82), -INT8_C( 120), -INT8_C(  75),  INT8_C(  18), -INT8_C(  32),
        -INT8_C(  90), -INT8_C(  37),      INT8_MAX, -INT8_C(   8), -INT8_C( 113),  INT8_C(  88), -INT8_C(  42),  INT8_C(  71) },
      {  INT8_C(  69), -INT8_C( 119),  INT8_C(  20),  INT8_C(  66), -INT8_C(  33), -INT8_C(   2), -INT8_C(  43), -INT8_C(  98),
        -INT8_C( 106),  INT8_C( 105), -INT8_C(  59),  INT8_C(  76),  INT8_C( 103), -INT8_C(   7), -INT8_C(  48), -INT8_C(  75),
        -INT8_C(  74),  INT8_C(  47),  INT8_C(   7), -INT8_C(  37),  INT8_C( 105),  INT8_C(  26),  INT8_C(  86), -INT8_C( 118),
        -INT8_C(  11), -INT8_C(  98), -INT8_C( 126), -INT8_C( 123), -INT8_C(  10),  INT8_C(  89), -INT8_C(  52),  INT8_C(  59),
        -INT8_C(  30), -INT8_C(  87),  INT8_C( 125), -INT8_C(  63), -INT8_C(   3),  INT8_C(  82),  INT8_C(  33),  INT8_C(  80),
        -INT8_C(  37),  INT8_C(  37), -INT8_C(  77), -INT8_C(  88), -INT8_C(  57),  INT8_C( 108),  INT8_C(  93),  INT8_C( 125),
        -INT8_C( 101),  INT8_C( 101), -INT8_C(  68),      INT8_MAX,      INT8_MAX, -INT8_C(  75),  INT8_C(  18),  INT8_C( 116),
         INT8_C( 121), -INT8_C( 116), -INT8_C(   7),  INT8_C( 112), -INT8_C(  27), -INT8_C(  59), -INT8_C(  42),  INT8_C(  71) },
      { -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
        -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
         INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
         INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
        -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
        -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
         INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
        -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1) } },
    { {  INT8_C(  75), -INT8_C( 123), -INT8_C(  38), -INT8_C( 121), -INT8_C(  26),  INT8_C(  82), -INT8_C(  48),  INT8_C(  75),
        -INT8_C(  56), -INT8_C(  19),  INT8_C(  33), -INT8_C( 101),  INT8_C(  90),  INT8_C(   2),  INT8_C(  46), -INT8_C(  43),
         INT8_C( 111),  INT8_C(   2),  INT8_C(  55),  INT8_C( 113), -INT8_C( 118), -INT8_C(   5), -INT8_C( 108), -INT8_C(  64),
        -INT8_C( 111), -INT8_C(  67),  INT8_C( 105), -INT8_C(  93), -INT8_C(  77), -INT8_C(  11),  INT8_C(  92), -INT8_C(   2),
         INT8_C( 123),  INT8_C(  54), -INT8_C( 122),  INT8_C(  97), -INT8_C( 120),  INT8_C(  86), -INT8_C(  83),  INT8_C(  80),
         INT8_C(  67), -INT8_C(  50), -INT8_C(  21), -INT8_C(  98), -INT8_C(  48),  INT8_C(  26),  INT8_C( 115),  INT8_C(  64),
         INT8_C(  28), -INT8_C(  86), -INT8_C(  79), -INT8_C(  90), -INT8_C(  90),  INT8_C(  70),  INT8_C( 102),  INT8_C(  55),
         INT8_C(   3), -INT8_C(  49), -INT8_C(  38), -INT8_C(  73), -INT8_C(  59),  INT8_C(  54), -INT8_C(  75),  INT8_C(  64) },
      {  INT8_C( 108),  INT8_C(  59), -INT8_C(  95), -INT8_C(  12), -INT8_C( 110),  INT8_C(  78), -INT8_C(  48), -INT8_C(  43),
        -INT8_C(  56),  INT8_C(  48),  INT8_C( 115), -INT8_C(  19),  INT8_C(  74), -INT8_C(  26),  INT8_C(  46),  INT8_C( 102),
        -INT8_C( 111), -INT8_C(  34),  INT8_C(  12),  INT8_C( 113),  INT8_C(  36),  INT8_C( 114),  INT8_C( 110),  INT8_C(  40),
         INT8_C(  66),  INT8_C(  72),  INT8_C( 105),  INT8_C(   7),      INT8_MAX, -INT8_C( 108),  INT8_C(  71), -INT8_C(  21),
        -INT8_C(  48), -INT8_C(  24), -INT8_C(  32),  INT8_C(  98),  INT8_C(  55),  INT8_C(  37),  INT8_C(  55),  INT8_C(  83),
         INT8_C(  67), -INT8_C(  85),  INT8_C(  64), -INT8_C(  96), -INT8_C( 111),  INT8_C( 109),  INT8_C(   6),  INT8_C(  34),
         INT8_C(  76), -INT8_C(  86),  INT8_C(  89),  INT8_C( 112), -INT8_C( 123),  INT8_C(  70), -INT8_C( 104), -INT8_C(  57),
         INT8_C(  16),  INT8_C( 119), -INT8_C(  50), -INT8_C( 113),  INT8_C(  12),  INT8_C(  54),  INT8_C( 122), -INT8_C(  36) },
      { -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
        -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
         INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
        -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
         INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
        -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
        -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
        -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0) } },
    { { -INT8_C(  95),  INT8_C(  70),  INT8_C( 100),  INT8_C(  64), -INT8_C(  63),  INT8_C(  34), -INT8_C(   1),  INT8_C(   5),
         INT8_C(  85),  INT8_C( 112),      INT8_MAX,  INT8_C(   4), -INT8_C(  75),  INT8_C( 124),  INT8_C(  65),  INT8_C(  41),
         INT8_C( 108), -INT8_C( 110), -INT8_C( 110), -INT8_C(  24), -INT8_C(  66),  INT8_C(   0),  INT8_C( 102), -INT8_C( 107),
         INT8_C(   3), -INT8_C(  12),  INT8_C(  43),  INT8_C(  21),  INT8_C( 108),  INT8_C( 126), -INT8_C( 111),  INT8_C(  14),
        -INT8_C(  60), -INT8_C(  11),  INT8_C(  78), -INT8_C( 123),  INT8_C(  24),  INT8_C(  77), -INT8_C( 118),  INT8_C( 109),
        -INT8_C(  67),  INT8_C(  10),  INT8_C( 113),  INT8_C( 114), -INT8_C( 122), -INT8_C(  78), -INT8_C( 101), -INT8_C(  13),
         INT8_C(  68),  INT8_C(  45), -INT8_C(  37),  INT8_C(   3),  INT8_C(  46),  INT8_C(  65), -INT8_C( 104),  INT8_C(  49),
         INT8_C(  53), -INT8_C(  61),  INT8_C(  71), -INT8_C(  94),  INT8_C(  65), -INT8_C(  40), -INT8_C(  80),  INT8_C(   6) },
      { -INT8_C(  51), -INT8_C(   2), -INT8_C( 117),  INT8_C(  64),  INT8_C(  75),  INT8_C(  34),  INT8_C(  83),  INT8_C(   5),
         INT8_C(  32),  INT8_C( 112),  INT8_C( 122),  INT8_C(   4),  INT8_C( 119),  INT8_C(  22), -INT8_C( 103), -INT8_C(  69),
         INT8_C( 108),  INT8_C( 116), -INT8_C(  66), -INT8_C(  24), -INT8_C(  74),  INT8_C(  86), -INT8_C(  93), -INT8_C(  21),
         INT8_C(  25), -INT8_C(  22), -INT8_C( 115),  INT8_C(  21), -INT8_C(  62),  INT8_C( 126),  INT8_C(  97), -INT8_C( 113),
         INT8_C(  59), -INT8_C(  20),  INT8_C( 117), -INT8_C( 122),  INT8_C(   2), -INT8_C(  56), -INT8_C( 114),  INT8_C(  34),
        -INT8_C( 116),  INT8_C(   9), -INT8_C(  55),  INT8_C(   3),  INT8_C(  31), -INT8_C(  78), -INT8_C(  65),  INT8_C(  98),
        -INT8_C(  41),  INT8_C( 125), -INT8_C(  44),  INT8_C(   3), -INT8_C(  44),  INT8_C( 119),  INT8_C( 120), -INT8_C(  19),
         INT8_C(  53), -INT8_C(  61),  INT8_C(  71), -INT8_C(  94),  INT8_C(  65), -INT8_C(  87), -INT8_C(  78),  INT8_C(   6) },
      { -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
         INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
        -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
        -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
        -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
         INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
         INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
        -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1) } },
    { {      INT8_MIN, -INT8_C( 109), -INT8_C(  49), -INT8_C(  91), -INT8_C(  20),  INT8_C(   2),  INT8_C( 103), -INT8_C(  55),
        -INT8_C(  76), -INT8_C(  27), -INT8_C( 115), -INT8_C(  91), -INT8_C( 126),  INT8_C(  14),  INT8_C(  82),  INT8_C(  17),
        -INT8_C(  39), -INT8_C( 113),  INT8_C(   9),  INT8_C( 104),  INT8_C(  74), -INT8_C(  52), -INT8_C(  65), -INT8_C(  54),
         INT8_C( 125),  INT8_C(  35), -INT8_C(  70), -INT8_C(  51),  INT8_C(  19), -INT8_C(  80), -INT8_C(  27), -INT8_C( 109),
         INT8_C(  67), -INT8_C(  76),  INT8_C(  57),  INT8_C(  48), -INT8_C(  74), -INT8_C(  96), -INT8_C(   7),  INT8_C( 107),
        -INT8_C( 122), -INT8_C( 122),  INT8_C(  16),  INT8_C(   8), -INT8_C( 108),  INT8_C(  99),  INT8_C(  25),  INT8_C( 110),
        -INT8_C(  14),  INT8_C(  34), -INT8_C(  42),  INT8_C(  60), -INT8_C(  17), -INT8_C( 107),  INT8_C(   7),  INT8_C( 108),
        -INT8_C(  71), -INT8_C(  63),  INT8_C(  57), -INT8_C(  52),  INT8_C( 113),  INT8_C(  31),  INT8_C(  95), -INT8_C(  75) },
      { -INT8_C(  45), -INT8_C( 104), -INT8_C(  27), -INT8_C( 118),  INT8_C(  57), -INT8_C(  34),  INT8_C( 103), -INT8_C(  65),
        -INT8_C(  76), -INT8_C(  27), -INT8_C(  57), -INT8_C(   7), -INT8_C( 126), -INT8_C(  32),  INT8_C(  82),  INT8_C(  91),
         INT8_C(   2),  INT8_C(  61), -INT8_C( 105), -INT8_C(  15),  INT8_C(  74), -INT8_C(  98),  INT8_C(  93), -INT8_C( 116),
         INT8_C(  96), -INT8_C( 105),  INT8_C(  88), -INT8_C(  47), -INT8_C(  74), -INT8_C(  80), -INT8_C( 122), -INT8_C( 109),
         INT8_C(  80), -INT8_C(  76),  INT8_C(  19), -INT8_C( 119),  INT8_C(  74),  INT8_C(   8),  INT8_C(  72), -INT8_C(  81),
         INT8_C(  14),  INT8_C(  15),  INT8_C(  16),  INT8_C( 118), -INT8_C(  17),  INT8_C(  16),  INT8_C(  25), -INT8_C(  15),
        -INT8_C(  14),  INT8_C( 105), -INT8_C(  29),  INT8_C(  60),  INT8_C(   7),  INT8_C(  64),  INT8_C(   7),  INT8_C( 103),
        -INT8_C(  41),  INT8_C(   4),  INT8_C(  57), -INT8_C( 115), -INT8_C(  68),  INT8_C(  31),  INT8_C(  23),  INT8_C(  12) },
      { -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
        -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
        -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
         INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
        -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
        -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
        -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
        -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1) } },
    { {  INT8_C(   1),  INT8_C(   9),  INT8_C(  81),  INT8_C(  54),  INT8_C(  38),  INT8_C(  91),  INT8_C(  88),  INT8_C(  16),
         INT8_C(  29),  INT8_C(  84), -INT8_C(  41),  INT8_C( 104),  INT8_C(  29), -INT8_C(  57), -INT8_C(  91), -INT8_C( 106),
         INT8_C(   2), -INT8_C(  36), -INT8_C(   2),  INT8_C(  52),  INT8_C( 115),  INT8_C(  46),  INT8_C(  98), -INT8_C(  91),
        -INT8_C(  77),  INT8_C(  71),  INT8_C(  48), -INT8_C(  92), -INT8_C(  17),  INT8_C(  63),  INT8_C(  44), -INT8_C(  16),
         INT8_C(  72),  INT8_C( 125),  INT8_C(  39),  INT8_C( 111), -INT8_C(  40),      INT8_MAX,      INT8_MAX, -INT8_C(  10),
        -INT8_C(  45),  INT8_C(  86),  INT8_C(  94), -INT8_C(  15),  INT8_C(  30),  INT8_C(   4), -INT8_C( 121),  INT8_C(  32),
        -INT8_C(  32), -INT8_C( 123),  INT8_C(  85),  INT8_C(  83), -INT8_C(  76), -INT8_C(  73), -INT8_C(   8),  INT8_C( 103),
        -INT8_C(   2),  INT8_C(  40),  INT8_C(  12), -INT8_C(  19),  INT8_C( 104),  INT8_C(  56), -INT8_C(  34), -INT8_C(  80) },
      { -INT8_C(  75),  INT8_C(   5),  INT8_C(  31),  INT8_C(  54),  INT8_C(  38), -INT8_C(  97), -INT8_C( 125),  INT8_C(  87),
         INT8_C(  29), -INT8_C(  30),  INT8_C(  72),  INT8_C(  19),  INT8_C(  29), -INT8_C(  57),  INT8_C(  52), -INT8_C(  58),
         INT8_C(  85), -INT8_C( 119),  INT8_C(  25),  INT8_C(   9),  INT8_C(  64),  INT8_C(  46),  INT8_C(  98),  INT8_C(  62),
         INT8_C(  58),  INT8_C( 124),  INT8_C(  48), -INT8_C(  92), -INT8_C(  76),  INT8_C(   9),  INT8_C(  83), -INT8_C(  16),
         INT8_C(  14),  INT8_C( 125),  INT8_C(  39), -INT8_C( 110),  INT8_C(  17),  INT8_C( 122), -INT8_C(  22),  INT8_C(   7),
        -INT8_C(  45),  INT8_C(  50),  INT8_C(  94), -INT8_C(  15),  INT8_C(   2),  INT8_C(  78), -INT8_C( 121),  INT8_C(  32),
        -INT8_C(  41),  INT8_C(  34),  INT8_C(  96),  INT8_C(  23),  INT8_C(  52), -INT8_C(  48),  INT8_C(  85),  INT8_C( 110),
        -INT8_C(   2), -INT8_C( 127),  INT8_C(  17),  INT8_C(   1), -INT8_C( 118),  INT8_C( 100),  INT8_C( 107), -INT8_C( 103) },
      {  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
        -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
        -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
        -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
         INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
        -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
         INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
        -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0) } },
    { {  INT8_C(  82), -INT8_C(  15),  INT8_C(   7), -INT8_C(  44),  INT8_C(  92),  INT8_C(  10), -INT8_C(  98), -INT8_C(  47),
        -INT8_C( 120), -INT8_C(  78), -INT8_C(  99), -INT8_C( 118),  INT8_C( 103), -INT8_C( 103),  INT8_C(  50),  INT8_C(  29),
        -INT8_C(  36), -INT8_C(  76), -INT8_C(  91), -INT8_C(  68),  INT8_C( 126),  INT8_C(  75), -INT8_C(  71), -INT8_C(  94),
         INT8_C(  17),  INT8_C(  94), -INT8_C( 124),  INT8_C(  98),  INT8_C(  68), -INT8_C(   7), -INT8_C(  96), -INT8_C( 106),
        -INT8_C(  21), -INT8_C(  89),  INT8_C( 107),  INT8_C(  71), -INT8_C(  79),  INT8_C(   9),  INT8_C(  24),  INT8_C(  57),
        -INT8_C(  68), -INT8_C(  74), -INT8_C(  61),  INT8_C(  35),  INT8_C(  79), -INT8_C(  11),  INT8_C(  65),  INT8_C(  44),
        -INT8_C(  87), -INT8_C(  26), -INT8_C(  24),  INT8_C(  40),  INT8_C(  49), -INT8_C(  95), -INT8_C(  54),  INT8_C(  66),
        -INT8_C(   1),  INT8_C(  78), -INT8_C(  92),  INT8_C(  67),  INT8_C(  72),  INT8_C(  68), -INT8_C(  39),  INT8_C(  51) },
      { -INT8_C(  21),  INT8_C(  68),  INT8_C(   7), -INT8_C(  44),  INT8_C(  78), -INT8_C( 109), -INT8_C(  98), -INT8_C(  47),
         INT8_C(  73), -INT8_C(  78), -INT8_C(  99), -INT8_C( 104),  INT8_C( 103),  INT8_C( 110),  INT8_C(  50),  INT8_C(  57),
         INT8_C(  84), -INT8_C(  76), -INT8_C(  91), -INT8_C(  68),  INT8_C(  77),  INT8_C(  43), -INT8_C(  71),  INT8_C(  76),
         INT8_C( 122),  INT8_C( 107), -INT8_C( 113), -INT8_C(  62),  INT8_C(  68), -INT8_C(   7), -INT8_C(  11), -INT8_C( 101),
        -INT8_C(  83),  INT8_C( 111),  INT8_C(  56), -INT8_C(   5), -INT8_C(  79),  INT8_C(  14),  INT8_C(   5),  INT8_C(  75),
        -INT8_C(  88),  INT8_C(  51), -INT8_C(  61),  INT8_C(  56), -INT8_C(  95), -INT8_C(  11),  INT8_C(  65), -INT8_C(  10),
        -INT8_C(  87), -INT8_C(  26),  INT8_C( 123), -INT8_C(  94), -INT8_C(   3),  INT8_C(  67), -INT8_C(  17),  INT8_C( 119),
        -INT8_C(  82),  INT8_C(  78),  INT8_C(  57),  INT8_C(  94), -INT8_C(  25),  INT8_C(  68), -INT8_C(   7), -INT8_C( 107) },
      {  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
        -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
        -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
        -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
         INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
         INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
        -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
         INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0) } },
    { {  INT8_C(  54),  INT8_C( 119),  INT8_C(  23), -INT8_C(  73), -INT8_C(  30), -INT8_C( 108),  INT8_C(   0),  INT8_C(  28),
         INT8_C(  49), -INT8_C(  76), -INT8_C(  49),  INT8_C(  95), -INT8_C(  55),  INT8_C(  80), -INT8_C(  16), -INT8_C(  71),
         INT8_C(  64), -INT8_C(  30), -INT8_C(  55), -INT8_C( 112), -INT8_C(  85), -INT8_C(  90), -INT8_C(  67), -INT8_C( 122),
        -INT8_C(  82), -INT8_C(  81), -INT8_C(  95), -INT8_C(  37), -INT8_C(   5), -INT8_C( 102),  INT8_C(  94),  INT8_C(  49),
         INT8_C(  18),  INT8_C( 117), -INT8_C(  24), -INT8_C(  12),  INT8_C(  10), -INT8_C(  23),  INT8_C(  16),  INT8_C(  59),
        -INT8_C(  99), -INT8_C(  32), -INT8_C( 101),  INT8_C( 102),  INT8_C(  48), -INT8_C( 117),  INT8_C(  32),  INT8_C( 112),
         INT8_C( 109), -INT8_C(  23),  INT8_C(   0),  INT8_C(  25), -INT8_C( 113), -INT8_C(  67), -INT8_C(  97),  INT8_C(  61),
         INT8_C( 108),  INT8_C(  65),  INT8_C(  25),  INT8_C( 103), -INT8_C(  37),  INT8_C( 119), -INT8_C( 103), -INT8_C(  19) },
      { -INT8_C(  20), -INT8_C( 127), -INT8_C(  31), -INT8_C(  10),  INT8_C( 106), -INT8_C(  14),  INT8_C(  50),  INT8_C(  28),
        -INT8_C(  46), -INT8_C(  51),  INT8_C( 110),  INT8_C(   2),  INT8_C(  88), -INT8_C( 114),  INT8_C( 114), -INT8_C(  58),
         INT8_C( 119), -INT8_C(  30), -INT8_C(  33), -INT8_C( 112), -INT8_C(  85),  INT8_C( 126),  INT8_C(  68), -INT8_C(  99),
        -INT8_C(  65),  INT8_C(  93),  INT8_C(   4), -INT8_C( 101), -INT8_C(  44), -INT8_C(  99), -INT8_C( 120), -INT8_C(  64),
         INT8_C(  31),  INT8_C( 117), -INT8_C(  73), -INT8_C(  12),  INT8_C(  92), -INT8_C(  23),  INT8_C(  16),  INT8_C(  46),
        -INT8_C(  74),  INT8_C(   0),  INT8_C(  48),  INT8_C(  14), -INT8_C( 114), -INT8_C(  94),  INT8_C(  32),  INT8_C( 112),
         INT8_C(  21), -INT8_C(  77),  INT8_C(  12),  INT8_C(  70),  INT8_C(  50),  INT8_C(  80), -INT8_C(  29), -INT8_C(  15),
        -INT8_C(  83), -INT8_C(  25), -INT8_C( 116), -INT8_C( 127), -INT8_C( 123),  INT8_C(  21),  INT8_C(  66), -INT8_C(  92) },
      {  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
         INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
        -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
        -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
        -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
        -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
         INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
         INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i a = simde_mm512_loadu_epi8(test_vec[i].a);
    simde__m512i b = simde_mm512_loadu_epi8(test_vec[i].b);
    simde__m512i r = simde_x_mm512_cmple_epi8(a, b);
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
    simde__m512i r = simde_x_mm512_cmple_epi8(a, b);

    simde_test_x86_write_i8x64(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i8x64(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i8x64(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_cmple_epi8_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int8_t a[64];
    const int8_t b[64];
    const simde__mmask64 r;
  } test_vec[] = {
    { { -INT8_C(  50), -INT8_C( 110), -INT8_C( 111), -INT8_C(  58),  INT8_C(  98),  INT8_C(  46),  INT8_C( 105),  INT8_C(  24),
         INT8_C( 112),  INT8_C( 114),  INT8_C(  51), -INT8_C(  70), -INT8_C(  71), -INT8_C(   3), -INT8_C(  82), -INT8_C(  47),
         INT8_C(  47), -INT8_C( 112), -INT8_C(  94), -INT8_C(  86),  INT8_C(  87), -INT8_C(  84), -INT8_C(   5),  INT8_C(  26),
         INT8_C(  36),  INT8_C(  80),  INT8_C(  87), -INT8_C(   4),  INT8_C(  84),  INT8_C(  76),  INT8_C(  62),  INT8_C(  35),
        -INT8_C(  34), -INT8_C(  49), -INT8_C(  23),  INT8_C(  64), -INT8_C(   3),  INT8_C(  82),  INT8_C(  88),  INT8_C( 109),
        -INT8_C(  60), -INT8_C( 117),  INT8_C(  40),  INT8_C( 125), -INT8_C( 119), -INT8_C(  42),  INT8_C(  79), -INT8_C(  72),
         INT8_C( 102), -INT8_C(  15),  INT8_C(  98), -INT8_C(  67), -INT8_C(  99),  INT8_C(  94), -INT8_C(  40), -INT8_C(  63),
        -INT8_C(  82),  INT8_C(  47), -INT8_C(  66),  INT8_C(   3),  INT8_C( 123), -INT8_C(   4),  INT8_C(  38),  INT8_C(  89) },
      { -INT8_C(  53),  INT8_C(  15), -INT8_C( 102), -INT8_C(  56),  INT8_C(  97),  INT8_C(  46),  INT8_C(  53),  INT8_C(  24),
         INT8_C( 112),  INT8_C(  93), -INT8_C(  93),  INT8_C(   7),  INT8_C(  51), -INT8_C(   3), -INT8_C(  65), -INT8_C( 102),
        -INT8_C(  29), -INT8_C( 112),  INT8_C(  87), -INT8_C(  86),      INT8_MIN, -INT8_C(  84),  INT8_C(  65),  INT8_C(  46),
         INT8_C(  94), -INT8_C(   1),  INT8_C(  49), -INT8_C(  39),  INT8_C(  84),  INT8_C(  87),  INT8_C(  51), -INT8_C(  58),
         INT8_C( 102), -INT8_C(  51), -INT8_C( 114), -INT8_C(  57), -INT8_C(  65), -INT8_C(  60), -INT8_C(  19),  INT8_C( 109),
         INT8_C(  33), -INT8_C( 117),  INT8_C(  68),  INT8_C(  85), -INT8_C( 119),  INT8_C(   4), -INT8_C(  17),  INT8_C( 101),
         INT8_C(  38),  INT8_C(  70), -INT8_C(  27), -INT8_C(  90),  INT8_C( 118),  INT8_C(  94), -INT8_C(  44), -INT8_C(  63),
         INT8_C(  38),  INT8_C(   6), -INT8_C(  66),  INT8_C(  33),  INT8_C(  93), -INT8_C(  31), -INT8_C(  24),  INT8_C(  89) },
      UINT64_C(10210425070718712238) },
    { {  INT8_C( 106), -INT8_C(  27),  INT8_C(  28),  INT8_C(  42),  INT8_C( 107),  INT8_C(  83), -INT8_C(  14), -INT8_C(  31),
         INT8_C(  60),  INT8_C(  68),  INT8_C(  75), -INT8_C(  60), -INT8_C( 122), -INT8_C(  50),  INT8_C(  51), -INT8_C(  99),
         INT8_C(  16), -INT8_C(   1), -INT8_C(  82), -INT8_C(  25), -INT8_C(   5), -INT8_C(  31),  INT8_C(  87), -INT8_C(  41),
         INT8_C(  86), -INT8_C(  65),  INT8_C( 114), -INT8_C(  11), -INT8_C(  29),  INT8_C( 124),  INT8_C(  54),  INT8_C(  77),
         INT8_C(  97),  INT8_C(  82),  INT8_C( 119), -INT8_C(  52), -INT8_C(  91),  INT8_C( 105), -INT8_C(  82), -INT8_C(  31),
        -INT8_C(  82), -INT8_C(   7), -INT8_C(  90),  INT8_C(  52), -INT8_C(  57), -INT8_C(  39), -INT8_C(  47), -INT8_C(  41),
        -INT8_C(  40),      INT8_MIN, -INT8_C(  66), -INT8_C(  44),  INT8_C(  97),  INT8_C(  22), -INT8_C(  85), -INT8_C(  73),
        -INT8_C(  43),  INT8_C(  29), -INT8_C(  84), -INT8_C(  72), -INT8_C( 103), -INT8_C(  30),  INT8_C(   6), -INT8_C(   6) },
      {  INT8_C(  52),  INT8_C( 125), -INT8_C(  57), -INT8_C(  38), -INT8_C(  25),  INT8_C(  83), -INT8_C(  14), -INT8_C( 107),
         INT8_C(  60),  INT8_C(  97), -INT8_C(  55),  INT8_C(  53),  INT8_C(  59), -INT8_C( 101),  INT8_C(  12),  INT8_C(  19),
         INT8_C(  27), -INT8_C(  53), -INT8_C(  25),  INT8_C( 124), -INT8_C(   5), -INT8_C( 110),  INT8_C(  51), -INT8_C(  74),
         INT8_C(  86), -INT8_C(  33),  INT8_C( 111),  INT8_C(  73), -INT8_C(  62),  INT8_C( 124),  INT8_C(  68),  INT8_C(  77),
        -INT8_C(  14),  INT8_C(  82), -INT8_C(  48), -INT8_C(  39),      INT8_MIN, -INT8_C( 116),  INT8_C( 110), -INT8_C(  18),
        -INT8_C(  19),  INT8_C(  56),  INT8_C(  35),  INT8_C(  40), -INT8_C(  45),  INT8_C(  47),  INT8_C(  60), -INT8_C(  41),
        -INT8_C(   6),      INT8_MIN,  INT8_C( 106), -INT8_C(  37), -INT8_C(  74),  INT8_C(  22), -INT8_C( 110),  INT8_C( 102),
         INT8_C( 124),  INT8_C(   1), -INT8_C(  81),  INT8_C(  62),  INT8_C( 118), -INT8_C(  30),  INT8_C(  53),  INT8_C( 104) },
      UINT64_C(18280101863420173154) },
    { { -INT8_C( 120), -INT8_C(  56),  INT8_C(  33), -INT8_C( 127),  INT8_C( 120), -INT8_C(  41),  INT8_C(  99), -INT8_C(  73),
         INT8_C(  53),  INT8_C(   0), -INT8_C(  75),  INT8_C( 119),  INT8_C(  70),  INT8_C( 108), -INT8_C(  65), -INT8_C(  96),
        -INT8_C(  71), -INT8_C(  59), -INT8_C(  85),  INT8_C(  44), -INT8_C(  19), -INT8_C(  30), -INT8_C(  56), -INT8_C(  24),
        -INT8_C( 123),  INT8_C(   1), -INT8_C(  87), -INT8_C(  55),  INT8_C(  65),  INT8_C(  47), -INT8_C(  78), -INT8_C(  54),
        -INT8_C(   9), -INT8_C(  45),  INT8_C(  75),  INT8_C( 111), -INT8_C(  85), -INT8_C(  82),  INT8_C(  38), -INT8_C(  32),
        -INT8_C(  82), -INT8_C(  37),  INT8_C(  87), -INT8_C(  11),  INT8_C(  72),  INT8_C(  23), -INT8_C( 107),  INT8_C(   1),
        -INT8_C(  36),  INT8_C(  64),  INT8_C(  45), -INT8_C(  55),  INT8_C(  35), -INT8_C(  11), -INT8_C(  78), -INT8_C(  88),
        -INT8_C(   9),  INT8_C(  91),  INT8_C( 113),  INT8_C(  56), -INT8_C( 118),  INT8_C(  36),  INT8_C(   2), -INT8_C( 126) },
      { -INT8_C( 120),  INT8_C(  78), -INT8_C(  15), -INT8_C(  94), -INT8_C(   4),  INT8_C(  24), -INT8_C( 125), -INT8_C(  85),
         INT8_C(  53), -INT8_C(  38), -INT8_C(  96),  INT8_C( 119),  INT8_C(  70),  INT8_C(  53),  INT8_C(  60), -INT8_C(  96),
         INT8_C( 118),  INT8_C( 106), -INT8_C(  85),  INT8_C(  44),  INT8_C(  95),  INT8_C(  73),  INT8_C(  65),  INT8_C(  86),
        -INT8_C(  92), -INT8_C(  77), -INT8_C( 113),  INT8_C(  47), -INT8_C(  41),  INT8_C(  47), -INT8_C(  79), -INT8_C(  50),
        -INT8_C(  33), -INT8_C(  94),  INT8_C( 113), -INT8_C(  36), -INT8_C(  70), -INT8_C(  12), -INT8_C( 121), -INT8_C(  82),
        -INT8_C(  82),  INT8_C(  39), -INT8_C(  23), -INT8_C(  64),  INT8_C(  92),  INT8_C(  38), -INT8_C( 115),  INT8_C(   1),
        -INT8_C(  36),  INT8_C(  36),  INT8_C( 107), -INT8_C(  55),  INT8_C( 109), -INT8_C(  83),  INT8_C(  70),  INT8_C(  18),
         INT8_C(  96), -INT8_C(  43),  INT8_C( 113),  INT8_C(  56),  INT8_C( 102), -INT8_C(  14),  INT8_C(   5), -INT8_C( 126) },
      UINT64_C(15987131291006916907) },
    { { -INT8_C(  87),  INT8_C(  55),  INT8_C(  53), -INT8_C(  57),  INT8_C( 117),  INT8_C(   3), -INT8_C(  74), -INT8_C( 102),
        -INT8_C(  54), -INT8_C(  47), -INT8_C(  53),  INT8_C(  24), -INT8_C(  21), -INT8_C( 104),  INT8_C(  16),  INT8_C( 111),
        -INT8_C(  14),  INT8_C(  33),  INT8_C(  11),  INT8_C(  29),  INT8_C(  93),  INT8_C(  31), -INT8_C(  16),  INT8_C(   4),
        -INT8_C(  31), -INT8_C(  48),  INT8_C(   8),  INT8_C(  87),  INT8_C(   3), -INT8_C(   1), -INT8_C(   9), -INT8_C(  84),
         INT8_C(  54),  INT8_C(  45),  INT8_C( 116), -INT8_C(  84),  INT8_C(  48),  INT8_C(  42),  INT8_C(  70), -INT8_C(   5),
        -INT8_C(   5),  INT8_C(  17),  INT8_C(  19), -INT8_C(  26), -INT8_C(  87),  INT8_C(  35),  INT8_C(  85), -INT8_C( 101),
         INT8_C(  69),  INT8_C(  97), -INT8_C(  71), -INT8_C(  94),      INT8_MIN, -INT8_C(  87), -INT8_C(  90),  INT8_C(  97),
         INT8_C( 121), -INT8_C(  82), -INT8_C(  72),  INT8_C( 124), -INT8_C(  83), -INT8_C(  81),  INT8_C(  41), -INT8_C(  28) },
      { -INT8_C(  36), -INT8_C(  99), -INT8_C( 112), -INT8_C(  57), -INT8_C(  57), -INT8_C(  42),  INT8_C(   8), -INT8_C(  62),
        -INT8_C(  25),  INT8_C(  27), -INT8_C(  88), -INT8_C( 112),  INT8_C(  62), -INT8_C(   3),  INT8_C(  16), -INT8_C( 125),
         INT8_C(  94), -INT8_C(  27),  INT8_C(  37),  INT8_C(  29), -INT8_C( 114),  INT8_C(  31), -INT8_C(  16),  INT8_C(   7),
         INT8_C( 122), -INT8_C(  48), -INT8_C( 125),  INT8_C(  39),  INT8_C(   3), -INT8_C(  84),  INT8_C(  11), -INT8_C( 125),
         INT8_C(  73), -INT8_C( 101), -INT8_C( 112),  INT8_C(  16),  INT8_C( 113),  INT8_C(  42), -INT8_C(  46), -INT8_C(   5),
        -INT8_C(  77),  INT8_C( 122), -INT8_C(  23), -INT8_C(  14), -INT8_C(  87),  INT8_C(  21),  INT8_C( 117), -INT8_C(  42),
         INT8_C(  69), -INT8_C( 101), -INT8_C(  75), -INT8_C( 120),  INT8_C( 102), -INT8_C(  12), -INT8_C(  90), -INT8_C(  32),
        -INT8_C(  20),  INT8_C(  18),  INT8_C(   8), -INT8_C( 109), -INT8_C(  65),  INT8_C(  19),  INT8_C(  22),  INT8_C(   8) },
      UINT64_C(13146529276783064009) },
    { {  INT8_C(  60),  INT8_C( 101), -INT8_C(  75), -INT8_C(  93),  INT8_C(   6), -INT8_C( 126),  INT8_C( 111),  INT8_C(   8),
         INT8_C(  52),  INT8_C(  26), -INT8_C( 126),  INT8_C(  65),  INT8_C( 121),  INT8_C( 108),  INT8_C(  67),  INT8_C(  65),
         INT8_C(  80), -INT8_C(  95),  INT8_C( 104), -INT8_C(  69),  INT8_C(  59), -INT8_C(  40), -INT8_C(  63),  INT8_C(  26),
         INT8_C(  38),  INT8_C(  33),  INT8_C(  81),  INT8_C( 103), -INT8_C(  30), -INT8_C( 113),  INT8_C(  66),  INT8_C(  31),
        -INT8_C(  11), -INT8_C(   8), -INT8_C(  62), -INT8_C(   5),  INT8_C( 122),  INT8_C(  49),  INT8_C(   3), -INT8_C(  81),
         INT8_C(  75), -INT8_C( 123), -INT8_C(  16), -INT8_C(  60), -INT8_C(  14),  INT8_C(  51),  INT8_C(   6),  INT8_C(  66),
        -INT8_C(  44),  INT8_C( 110), -INT8_C(   3),  INT8_C(  15),  INT8_C(  70), -INT8_C(  65),  INT8_C(  42),  INT8_C( 108),
        -INT8_C(  32),  INT8_C( 123), -INT8_C(  45), -INT8_C(  62),  INT8_C(  11),  INT8_C(  22), -INT8_C(  31),  INT8_C(   0) },
      {  INT8_C(  60), -INT8_C(  93), -INT8_C(   5), -INT8_C(  93), -INT8_C(  43), -INT8_C(   2),  INT8_C( 111),  INT8_C(  32),
        -INT8_C( 124),  INT8_C(  39), -INT8_C(  27),  INT8_C( 118),  INT8_C( 121), -INT8_C(  21), -INT8_C(  72),  INT8_C(  46),
         INT8_C(  80), -INT8_C(  75),  INT8_C(  62), -INT8_C(  97),  INT8_C( 116), -INT8_C(  40), -INT8_C(  63),  INT8_C(  84),
        -INT8_C(  29),  INT8_C(  33),  INT8_C(  23), -INT8_C(  18), -INT8_C(  11), -INT8_C( 113), -INT8_C(  18),  INT8_C(   3),
        -INT8_C( 100), -INT8_C(   8), -INT8_C( 116), -INT8_C(   5), -INT8_C(  24), -INT8_C(  61), -INT8_C( 111), -INT8_C(  81),
         INT8_C(  75), -INT8_C( 123), -INT8_C(  30), -INT8_C(  60),  INT8_C(  97), -INT8_C( 102),  INT8_C(   6), -INT8_C(  70),
         INT8_C(  79), -INT8_C(  78),  INT8_C(  90), -INT8_C(  60),  INT8_C(  26),  INT8_C( 102),  INT8_C(  24), -INT8_C(   3),
         INT8_C(  69),  INT8_C(  47), -INT8_C(  20), -INT8_C(  62),  INT8_C(  40), -INT8_C(  38),  INT8_C(  62), -INT8_C(  60) },
      UINT64_C( 6711871468784000749) },
    { {  INT8_C(  22), -INT8_C(  35),  INT8_C( 122), -INT8_C(  19),  INT8_C(  39),  INT8_C(  36),  INT8_C(   1),  INT8_C( 108),
        -INT8_C( 116), -INT8_C(  76),  INT8_C(  68),  INT8_C(  38), -INT8_C(  65),  INT8_C(   0), -INT8_C(  91),  INT8_C( 126),
         INT8_C( 100),  INT8_C(  35),  INT8_C(  85), -INT8_C( 121), -INT8_C( 100), -INT8_C( 117), -INT8_C( 102), -INT8_C(   2),
         INT8_C(  91), -INT8_C(  59),  INT8_C(  34),  INT8_C(   2), -INT8_C(  53), -INT8_C(  52),  INT8_C(  76), -INT8_C(  31),
        -INT8_C(  87), -INT8_C(  57), -INT8_C(  49), -INT8_C(  47), -INT8_C(  21), -INT8_C(  48),  INT8_C(  61),  INT8_C( 119),
        -INT8_C( 124), -INT8_C( 127), -INT8_C(  99),  INT8_C(  68), -INT8_C( 126),  INT8_C(  67), -INT8_C(  62), -INT8_C(  26),
         INT8_C( 102),  INT8_C(  23),  INT8_C( 109),  INT8_C(   2), -INT8_C(  93),  INT8_C(   8),  INT8_C(   0), -INT8_C(   2),
        -INT8_C(  51),  INT8_C(  34),  INT8_C(   0), -INT8_C( 104), -INT8_C(  17),  INT8_C(  77),  INT8_C( 121), -INT8_C( 104) },
      {  INT8_C(  20),  INT8_C(  72),  INT8_C( 105), -INT8_C(  19),  INT8_C(  25),  INT8_C(  36),  INT8_C( 118), -INT8_C(  99),
         INT8_C(  40),  INT8_C(  19), -INT8_C(  31), -INT8_C(  86),  INT8_C(  86), -INT8_C(  93), -INT8_C(  91), -INT8_C(  68),
        -INT8_C(  69), -INT8_C(   3),  INT8_C(  85),  INT8_C(  94),  INT8_C(   5), -INT8_C(  65), -INT8_C( 102), -INT8_C(  46),
        -INT8_C(  30),  INT8_C(  92),  INT8_C( 106),  INT8_C(   2), -INT8_C(  87), -INT8_C(  28),  INT8_C(  76), -INT8_C(  67),
        -INT8_C(  87), -INT8_C(  45), -INT8_C(  68),  INT8_C(  69),  INT8_C( 121), -INT8_C(  48), -INT8_C(  29), -INT8_C(  95),
         INT8_C(  70), -INT8_C(  60), -INT8_C(  99), -INT8_C( 100),  INT8_C( 104),  INT8_C(  67), -INT8_C(  62),  INT8_C(  35),
        -INT8_C(  39),  INT8_C(  24), -INT8_C( 127), -INT8_C(  34), -INT8_C(  41), -INT8_C(  35), -INT8_C(  79), -INT8_C(  71),
         INT8_C(  57),  INT8_C(  27),  INT8_C(   0), -INT8_C( 104), -INT8_C(  17),  INT8_C(  77), -INT8_C(  96), -INT8_C( 104) },
      UINT64_C(13624223657377944426) },
    { {  INT8_C(  34),  INT8_C( 116), -INT8_C(  60), -INT8_C(  95),  INT8_C(  80),  INT8_C(  69),  INT8_C(  56),  INT8_C(  89),
         INT8_C(  56),  INT8_C(  81),  INT8_C( 108), -INT8_C(  10),  INT8_C(  13),  INT8_C(  96), -INT8_C( 105), -INT8_C(  17),
         INT8_C(  21), -INT8_C(  14), -INT8_C(  46),  INT8_C(  60), -INT8_C(  62), -INT8_C(  15), -INT8_C(  17), -INT8_C( 112),
         INT8_C(  47),  INT8_C(  47),  INT8_C(  80),  INT8_C(  43),  INT8_C(  40), -INT8_C(  54),  INT8_C(  68),  INT8_C(  74),
         INT8_C(  62),  INT8_C(   8), -INT8_C(  21), -INT8_C( 114),  INT8_C(  77),  INT8_C(  36), -INT8_C(  24), -INT8_C( 123),
         INT8_C( 117),  INT8_C(  84),  INT8_C( 123), -INT8_C( 126), -INT8_C(  76),  INT8_C(  18),  INT8_C( 113), -INT8_C(  54),
         INT8_C(   4),  INT8_C(  68),  INT8_C(   6), -INT8_C(  58),  INT8_C(  53), -INT8_C(  11),  INT8_C(  86),  INT8_C( 100),
         INT8_C(  37), -INT8_C(  89), -INT8_C( 112),  INT8_C(  77),  INT8_C( 113), -INT8_C(  44), -INT8_C( 105), -INT8_C(  80) },
      {  INT8_C(  34), -INT8_C( 125),  INT8_C(  62),  INT8_C(  41),  INT8_C(  80),  INT8_C(  38), -INT8_C(  82),  INT8_C(  28),
         INT8_C( 122),  INT8_C(  41), -INT8_C(  98), -INT8_C(  10),  INT8_C(  59),  INT8_C(  16), -INT8_C(   7),  INT8_C(  63),
         INT8_C(  84), -INT8_C(   1),  INT8_C(   6), -INT8_C( 119), -INT8_C(  62),  INT8_C(  92), -INT8_C(  18), -INT8_C( 112),
         INT8_C(   3),  INT8_C( 126),  INT8_C( 102),  INT8_C( 117),  INT8_C(  82), -INT8_C(   2),  INT8_C(  68),  INT8_C(  46),
        -INT8_C( 127),  INT8_C(  99),  INT8_C(  87),  INT8_C(  40), -INT8_C( 118),  INT8_C(  36),  INT8_C(  68), -INT8_C( 123),
         INT8_C(  46), -INT8_C(  30),  INT8_C( 123), -INT8_C( 126), -INT8_C(  14),  INT8_C(  44), -INT8_C(  88), -INT8_C(  54),
         INT8_C(  43),  INT8_C(  68), -INT8_C(  48),  INT8_C(  32),  INT8_C(  53), -INT8_C(  11),  INT8_C(  57),  INT8_C(  14),
         INT8_C(  60), -INT8_C(  89), -INT8_C( 125), -INT8_C( 114), -INT8_C(  98), -INT8_C(  88), -INT8_C(  68), -INT8_C(  80) },
      UINT64_C(14068045593536092445) },
    { {  INT8_C(  25), -INT8_C( 100), -INT8_C(  86), -INT8_C(  57),  INT8_C(  36), -INT8_C(  43), -INT8_C(  29),  INT8_C( 122),
        -INT8_C(  80),  INT8_C(  95), -INT8_C(  54), -INT8_C(  30), -INT8_C( 126),  INT8_C(  65),  INT8_C(  26),  INT8_C(  27),
        -INT8_C(   3),  INT8_C(  99), -INT8_C(  24),  INT8_C(  57), -INT8_C(  53),  INT8_C(  38), -INT8_C( 107), -INT8_C(  41),
         INT8_C(  99), -INT8_C(  82),  INT8_C(  46),  INT8_C(  90), -INT8_C(  93), -INT8_C(  36),  INT8_C(  30), -INT8_C(  68),
         INT8_C( 120), -INT8_C(  56), -INT8_C( 124), -INT8_C( 100), -INT8_C(  98),  INT8_C( 103),  INT8_C(  22),  INT8_C(  78),
        -INT8_C(  57), -INT8_C(  31),  INT8_C(  48),  INT8_C(  73),  INT8_C(  34),  INT8_C(  74),  INT8_C( 100),  INT8_C(  31),
        -INT8_C(  83),  INT8_C(  76),  INT8_C(  89),  INT8_C( 120),  INT8_C( 115), -INT8_C(  18),  INT8_C(  79), -INT8_C(  42),
        -INT8_C( 100),  INT8_C( 125),  INT8_C(  48),  INT8_C(  63),  INT8_C(  90),  INT8_C(  78), -INT8_C(   4), -INT8_C(  46) },
      {  INT8_C(  23),      INT8_MIN, -INT8_C(  86), -INT8_C(  75),  INT8_C(  36), -INT8_C(  43), -INT8_C(  29), -INT8_C(  82),
        -INT8_C(  80),  INT8_C(  95), -INT8_C(  54), -INT8_C(  30),  INT8_C( 125),  INT8_C(  91), -INT8_C(  88),  INT8_C(  27),
        -INT8_C(   3),  INT8_C(   1), -INT8_C(  94),  INT8_C(  27), -INT8_C(  17), -INT8_C(  14), -INT8_C(  15), -INT8_C( 117),
         INT8_C( 111),  INT8_C(  33), -INT8_C(  54), -INT8_C(  55),  INT8_C( 111), -INT8_C(  36),  INT8_C(  30), -INT8_C( 122),
         INT8_C(  70), -INT8_C(  56), -INT8_C( 124),  INT8_C(  46), -INT8_C( 112),  INT8_C( 103), -INT8_C(  36), -INT8_C(   9),
        -INT8_C(  57), -INT8_C(  44),      INT8_MAX,  INT8_C(  73),  INT8_C(  47),  INT8_C(  39),  INT8_C( 100), -INT8_C(  41),
         INT8_C(  40), -INT8_C(  69), -INT8_C(  14),  INT8_C( 120), -INT8_C(  83), -INT8_C(  29), -INT8_C(  94), -INT8_C(  42),
        -INT8_C( 100),  INT8_C( 125), -INT8_C(  26),  INT8_C( 116),  INT8_C(  51), -INT8_C( 126), -INT8_C(   4),  INT8_C( 122) },
      UINT64_C(14666356115593346932) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i a = simde_mm512_loadu_epi8(test_vec[i].a);
    simde__m512i b = simde_mm512_loadu_epi8(test_vec[i].b);
    simde__mmask64 r = simde_mm512_cmple_epi8_mask(a, b);
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
    simde__mmask64 r = simde_mm512_cmple_epi8_mask(a, b);

    simde_test_x86_write_i8x64(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i8x64(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask64(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_mask_cmple_epi8_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask64 k;
    const int8_t a[64];
    const int8_t b[64];
    const simde__mmask64 r;
  } test_vec[] = {
    { UINT64_C( 1826496704962407036),
      { -INT8_C(  56), -INT8_C( 124),  INT8_C( 110), -INT8_C(  83),  INT8_C(  29), -INT8_C(  89), -INT8_C(  22),  INT8_C(  73),
        -INT8_C(  75), -INT8_C(  80),  INT8_C(  49), -INT8_C(  81), -INT8_C(  43), -INT8_C(   3),  INT8_C(  82),  INT8_C(  76),
        -INT8_C(  59),  INT8_C(  73), -INT8_C(   8),  INT8_C(  42), -INT8_C(  78), -INT8_C(  33), -INT8_C( 101),  INT8_C( 115),
         INT8_C( 115),  INT8_C(  74),  INT8_C(  13), -INT8_C(  80), -INT8_C(  79),  INT8_C(  13), -INT8_C(  52),  INT8_C( 121),
        -INT8_C( 110),  INT8_C(  58),  INT8_C(  38), -INT8_C(  81), -INT8_C(  30),  INT8_C(  17), -INT8_C(   8), -INT8_C( 105),
        -INT8_C(  63),  INT8_C(  42),  INT8_C(  70), -INT8_C( 106),  INT8_C(  39), -INT8_C( 104), -INT8_C(  30), -INT8_C(  20),
        -INT8_C(  30), -INT8_C(  38),  INT8_C(  23), -INT8_C( 108), -INT8_C(  71), -INT8_C(  78),  INT8_C(   7),  INT8_C(  45),
        -INT8_C(   4),  INT8_C(  20), -INT8_C(  35), -INT8_C(  83),  INT8_C(  34), -INT8_C(  87),  INT8_C(  39), -INT8_C(  76) },
      { -INT8_C(  28), -INT8_C( 124),  INT8_C(  99), -INT8_C(  58),  INT8_C(  94),  INT8_C(  91),  INT8_C(  93),  INT8_C(  73),
        -INT8_C( 123), -INT8_C(  80), -INT8_C(  75), -INT8_C(  83),  INT8_C(  60), -INT8_C( 105), -INT8_C( 103),  INT8_C(  30),
         INT8_C( 114), -INT8_C(  80), -INT8_C(  78),  INT8_C(  43),  INT8_C(  98), -INT8_C(  70), -INT8_C( 101),  INT8_C( 115),
        -INT8_C(  50),  INT8_C(  74),  INT8_C(  12), -INT8_C(  16), -INT8_C(  79),  INT8_C(  51), -INT8_C(  92), -INT8_C(  61),
             INT8_MIN,  INT8_C(  58), -INT8_C( 119), -INT8_C(  81),  INT8_C(  99), -INT8_C(  26), -INT8_C(   2), -INT8_C(  24),
        -INT8_C( 118), -INT8_C(  76),  INT8_C(  70), -INT8_C(  58),  INT8_C(  75),  INT8_C(  47), -INT8_C(  30), -INT8_C(  67),
        -INT8_C(  33), -INT8_C( 106),  INT8_C(  23),  INT8_C(  66),  INT8_C(  80),  INT8_C(  65),  INT8_C(   7),  INT8_C(  45),
         INT8_C( 119), -INT8_C(  84),  INT8_C(  15),  INT8_C(  87), -INT8_C(  33), -INT8_C(  76),  INT8_C(  39),  INT8_C(  96) },
      UINT64_C(  673292620496110200) },
    { UINT64_C( 8953814776633458092),
      {  INT8_C(  48),  INT8_C( 126), -INT8_C(  22),  INT8_C(  26), -INT8_C(  99),  INT8_C( 102),  INT8_C(  89), -INT8_C(  97),
        -INT8_C(  49),  INT8_C(  62), -INT8_C(  57), -INT8_C(  59), -INT8_C(  25), -INT8_C( 117), -INT8_C(  10),  INT8_C( 100),
         INT8_C(  66),  INT8_C(  64),  INT8_C( 105),  INT8_C(   8),  INT8_C(   3), -INT8_C(  79),      INT8_MAX,      INT8_MAX,
         INT8_C(  92),  INT8_C(  51), -INT8_C(  15),  INT8_C( 111),  INT8_C(  56),  INT8_C(  75), -INT8_C( 120),  INT8_C( 105),
        -INT8_C(  55),  INT8_C( 114), -INT8_C( 125),  INT8_C( 102), -INT8_C(  40), -INT8_C(  35),  INT8_C(   5), -INT8_C(  89),
         INT8_C(  27), -INT8_C(  52),  INT8_C( 109),  INT8_C(   2),  INT8_C(  87),  INT8_C(  99),  INT8_C( 102), -INT8_C( 102),
        -INT8_C(  93), -INT8_C(  49), -INT8_C(  94), -INT8_C(  90),      INT8_MIN,  INT8_C(  33),  INT8_C(  38), -INT8_C(  36),
         INT8_C(  85),  INT8_C(  23),  INT8_C(  76), -INT8_C( 115),  INT8_C(  98), -INT8_C(  44), -INT8_C(  10),  INT8_C(  43) },
      {  INT8_C(  48),  INT8_C( 122), -INT8_C( 111),  INT8_C(  26),  INT8_C(  87),  INT8_C( 102),  INT8_C(  89),  INT8_C( 114),
        -INT8_C(  49),  INT8_C(  52),  INT8_C( 116), -INT8_C(  69), -INT8_C( 105), -INT8_C(  38),  INT8_C(  85),  INT8_C(  58),
        -INT8_C(  87), -INT8_C(   9), -INT8_C(  32),  INT8_C(  41),  INT8_C(  24),  INT8_C(   6),  INT8_C(   6),  INT8_C( 109),
         INT8_C(  30),  INT8_C(  51), -INT8_C(   5),  INT8_C( 111),  INT8_C(  38),  INT8_C(  75), -INT8_C(  84),  INT8_C( 109),
         INT8_C( 107),  INT8_C(  61), -INT8_C( 115),  INT8_C( 102), -INT8_C(  44),  INT8_C(  84),  INT8_C(  52),  INT8_C(  56),
        -INT8_C( 120), -INT8_C(  88),  INT8_C( 109),  INT8_C(  31), -INT8_C( 126),  INT8_C(  72),  INT8_C(  89), -INT8_C( 102),
         INT8_C(  63),  INT8_C(  57), -INT8_C(  94),  INT8_C(  87),  INT8_C(  64),  INT8_C(  91),  INT8_C(  38),  INT8_C(  94),
        -INT8_C(  83), -INT8_C(  64), -INT8_C(  34), -INT8_C( 115), -INT8_C(  79), -INT8_C( 118),  INT8_C(  65),  INT8_C(  29) },
      UINT64_C( 5206728558178756008) },
    { UINT64_C(13301258476983460423),
      { -INT8_C( 106),  INT8_C(  43), -INT8_C(  18), -INT8_C(   9),  INT8_C( 126), -INT8_C(  81), -INT8_C(  76), -INT8_C( 112),
         INT8_C(  22),  INT8_C(  12), -INT8_C(  67), -INT8_C(  24),  INT8_C(  93), -INT8_C(  78), -INT8_C(  27), -INT8_C( 121),
         INT8_C(  65), -INT8_C(  65),  INT8_C(  19), -INT8_C(  83), -INT8_C( 110), -INT8_C(  55), -INT8_C(  62),  INT8_C(  62),
         INT8_C(  71), -INT8_C(  92), -INT8_C(  41),  INT8_C(  96), -INT8_C(   5),  INT8_C(  25), -INT8_C(  36), -INT8_C( 110),
         INT8_C(  68), -INT8_C(  54), -INT8_C( 119), -INT8_C(  62),  INT8_C( 122),  INT8_C(  61),  INT8_C(  83), -INT8_C( 112),
         INT8_C(  73),  INT8_C(  16),  INT8_C( 121), -INT8_C(  89), -INT8_C(  62),  INT8_C(  94),  INT8_C(  46),  INT8_C(   4),
         INT8_C(  29),  INT8_C(  65), -INT8_C(  79), -INT8_C(  81),  INT8_C(  10),  INT8_C( 115), -INT8_C(  19),  INT8_C(  81),
         INT8_C(  23), -INT8_C(  60), -INT8_C(  79),  INT8_C(  19), -INT8_C(  34), -INT8_C( 115), -INT8_C(  91),  INT8_C(  34) },
      {  INT8_C(  88),  INT8_C(  46), -INT8_C(  27), -INT8_C(  46),  INT8_C( 126),  INT8_C(  56),  INT8_C(  98), -INT8_C(  75),
         INT8_C(  72), -INT8_C(  37),  INT8_C(  92), -INT8_C(  24),  INT8_C(  93), -INT8_C( 118),  INT8_C(  15),  INT8_C(  87),
        -INT8_C(  53), -INT8_C(  64),  INT8_C(   7), -INT8_C(  42), -INT8_C( 110), -INT8_C(  12),  INT8_C(  39),  INT8_C(  62),
        -INT8_C(  71), -INT8_C(  39),  INT8_C(  94), -INT8_C( 105),  INT8_C( 102),  INT8_C(   3), -INT8_C(  71), -INT8_C(  66),
         INT8_C(  49), -INT8_C(  54), -INT8_C( 119), -INT8_C(  99), -INT8_C(  42), -INT8_C(  13),  INT8_C(  83),  INT8_C(  31),
         INT8_C(  73),  INT8_C(  16),  INT8_C(  42), -INT8_C(  89),  INT8_C(  58),  INT8_C(  57),  INT8_C(  96),  INT8_C(   5),
        -INT8_C(   7),  INT8_C( 103), -INT8_C(  79),  INT8_C(  44),  INT8_C(  10),  INT8_C(   3),  INT8_C( 119),  INT8_C(  20),
         INT8_C(  23), -INT8_C(  43), -INT8_C(  85),  INT8_C(  66), -INT8_C(  40),  INT8_C( 101),  INT8_C(   1),  INT8_C(  10) },
      UINT64_C( 2888654560312721475) },
    { UINT64_C(12716737108430812897),
      {  INT8_C(  60),  INT8_C( 120), -INT8_C(  79), -INT8_C(  92),  INT8_C(  66), -INT8_C(   2),  INT8_C(  46), -INT8_C(  46),
        -INT8_C(  51),  INT8_C(  54),  INT8_C(  41), -INT8_C( 107), -INT8_C(  48),  INT8_C(  37),  INT8_C(  44), -INT8_C(  87),
         INT8_C(   7),  INT8_C( 105),  INT8_C(  36), -INT8_C(  48),  INT8_C(  88),  INT8_C(  70),  INT8_C(  19), -INT8_C(  97),
        -INT8_C(  23),  INT8_C(  83),  INT8_C(  57),  INT8_C(   5), -INT8_C(  29), -INT8_C(  48), -INT8_C(  67),  INT8_C(  32),
         INT8_C(  72),  INT8_C( 110), -INT8_C(  60), -INT8_C( 118),  INT8_C( 109), -INT8_C(  14),  INT8_C(  92),  INT8_C(  58),
         INT8_C(  40), -INT8_C( 122), -INT8_C(  48), -INT8_C(   8), -INT8_C(  85), -INT8_C(   4), -INT8_C(  95), -INT8_C(  78),
         INT8_C( 101), -INT8_C(  58), -INT8_C( 126), -INT8_C(  67),  INT8_C(  12), -INT8_C( 107),  INT8_C(  92), -INT8_C(  11),
        -INT8_C(  24), -INT8_C( 107), -INT8_C(   6), -INT8_C(  52),  INT8_C( 101), -INT8_C(  72), -INT8_C(  20), -INT8_C(  83) },
      {  INT8_C(  60), -INT8_C(  80),  INT8_C(  56), -INT8_C( 109),  INT8_C(  66), -INT8_C( 108), -INT8_C(  50), -INT8_C(  46),
        -INT8_C(  51), -INT8_C(  98), -INT8_C(  62), -INT8_C(  59), -INT8_C(  48),  INT8_C( 100),  INT8_C( 119), -INT8_C(  87),
         INT8_C(   7), -INT8_C(   6), -INT8_C(  67), -INT8_C(  48), -INT8_C( 113),  INT8_C(  25),  INT8_C(  19),  INT8_C( 120),
        -INT8_C(  81),  INT8_C(  83),  INT8_C(  68),  INT8_C(  20), -INT8_C(  34),  INT8_C(  48), -INT8_C(  62),  INT8_C(   5),
        -INT8_C(  32), -INT8_C(   6), -INT8_C(  60), -INT8_C( 126),  INT8_C( 109), -INT8_C(  14),  INT8_C(  76),  INT8_C(  58),
         INT8_C(   4), -INT8_C( 122),  INT8_C( 110), -INT8_C(  98),  INT8_C( 114), -INT8_C(  26), -INT8_C(  98), -INT8_C( 100),
         INT8_C( 101),  INT8_C(  91), -INT8_C(  45),  INT8_C( 111),  INT8_C(  12), -INT8_C(   1), -INT8_C(  25),  INT8_C(  35),
         INT8_C(  37),  INT8_C(  43),  INT8_C(  56), -INT8_C(  52),  INT8_C(  91), -INT8_C(   6),  INT8_C(   9),  INT8_C(  59) },
      UINT64_C(11545545010515144833) },
    { UINT64_C( 3048787240246363557),
      {  INT8_C( 121),  INT8_C(  93), -INT8_C(  38),  INT8_C(  79),  INT8_C( 103),  INT8_C( 100), -INT8_C(  56),  INT8_C( 107),
        -INT8_C(  66),  INT8_C(  90),  INT8_C( 104), -INT8_C(  50),  INT8_C(  40), -INT8_C( 124), -INT8_C(  63),  INT8_C( 106),
        -INT8_C(  62), -INT8_C(  14),  INT8_C(  26),  INT8_C(  43), -INT8_C(  99),  INT8_C(  44),  INT8_C(  98),  INT8_C( 126),
         INT8_C(  35),  INT8_C( 109), -INT8_C(  96),  INT8_C(  41),  INT8_C(  90),  INT8_C(  27), -INT8_C(  38), -INT8_C(  44),
         INT8_C( 120), -INT8_C(  76),  INT8_C(  35), -INT8_C(  32),  INT8_C(  25), -INT8_C(  21),  INT8_C(  75), -INT8_C(  41),
         INT8_C(  70), -INT8_C(  76), -INT8_C(  91),  INT8_C( 110),  INT8_C(  56),  INT8_C( 103), -INT8_C(  39), -INT8_C(   6),
         INT8_C(  89), -INT8_C(  13),  INT8_C(  37), -INT8_C(  10),  INT8_C(  32), -INT8_C( 121),  INT8_C( 117),  INT8_C(  67),
        -INT8_C(  11),  INT8_C(  21),  INT8_C( 108),  INT8_C(  79),  INT8_C(  48),  INT8_C(  70),  INT8_C(  35), -INT8_C(  87) },
      {  INT8_C( 121),  INT8_C(  70), -INT8_C( 119),  INT8_C(  20),  INT8_C( 103), -INT8_C(  44), -INT8_C(  21),  INT8_C( 107),
        -INT8_C(  66), -INT8_C( 112), -INT8_C(  26), -INT8_C(  64), -INT8_C(   9), -INT8_C(  65), -INT8_C(  70),  INT8_C(  81),
        -INT8_C(  77), -INT8_C(  32),  INT8_C(  71), -INT8_C(  45),  INT8_C( 103), -INT8_C(  68),  INT8_C(  98),  INT8_C(  92),
        -INT8_C(  46), -INT8_C( 126), -INT8_C(  84),  INT8_C(   2), -INT8_C(  55), -INT8_C(  49), -INT8_C(  85), -INT8_C(  60),
         INT8_C(  22),  INT8_C(  52), -INT8_C(  40),  INT8_C(  72),  INT8_C(   9), -INT8_C(  61), -INT8_C(  64), -INT8_C( 111),
         INT8_C(  83), -INT8_C(  90), -INT8_C(  91),  INT8_C( 110),  INT8_C( 102),  INT8_C(  12), -INT8_C( 100),  INT8_C(  25),
        -INT8_C(  20), -INT8_C(  13), -INT8_C(  20), -INT8_C(  10), -INT8_C(  96),  INT8_C(   2), -INT8_C(  80),  INT8_C( 114),
        -INT8_C( 124),  INT8_C(  92),  INT8_C( 116),  INT8_C(  79),  INT8_C(  44),  INT8_C(  32),  INT8_C(  17),  INT8_C(  66) },
      UINT64_C(  723413788480504193) },
    { UINT64_C(13788483545193531702),
      { -INT8_C( 103),  INT8_C( 115), -INT8_C(  54), -INT8_C(  94),  INT8_C(   7), -INT8_C(  91),  INT8_C( 118), -INT8_C(  10),
         INT8_C(  13), -INT8_C(  76),  INT8_C(  66), -INT8_C(  76), -INT8_C(  50),  INT8_C( 113), -INT8_C(  10),  INT8_C(  58),
        -INT8_C(  49), -INT8_C(   1),  INT8_C(  22),  INT8_C( 110),  INT8_C(  17), -INT8_C(  72),  INT8_C(  55), -INT8_C(  74),
         INT8_C( 125), -INT8_C(  40),  INT8_C(  56),  INT8_C(  84),  INT8_C(  79), -INT8_C( 120),  INT8_C( 126), -INT8_C(  23),
        -INT8_C(   5),  INT8_C(  73), -INT8_C( 117),  INT8_C(   2), -INT8_C(  18),  INT8_C(   1), -INT8_C(   8), -INT8_C(   5),
        -INT8_C(  75),  INT8_C(  59), -INT8_C(  80), -INT8_C( 124), -INT8_C(  84), -INT8_C(  90), -INT8_C(  66),  INT8_C( 123),
        -INT8_C(  90), -INT8_C(  44), -INT8_C(  23), -INT8_C(  73), -INT8_C( 115),  INT8_C(  32),  INT8_C( 110),  INT8_C(  10),
        -INT8_C(   8), -INT8_C(  90),  INT8_C(  95),  INT8_C(  72),  INT8_C(  46), -INT8_C(  35),  INT8_C(  49),  INT8_C(  42) },
      { -INT8_C( 103), -INT8_C(  68),  INT8_C(  44),  INT8_C(  20),  INT8_C(   7),  INT8_C(  37),  INT8_C(  16),  INT8_C( 115),
         INT8_C(  13), -INT8_C(  64), -INT8_C(   9),  INT8_C(  12),  INT8_C( 102), -INT8_C(  75), -INT8_C(  10),  INT8_C(  12),
        -INT8_C( 118),  INT8_C( 112),  INT8_C(  22),  INT8_C(  23), -INT8_C( 112),  INT8_C(  50),  INT8_C(  33), -INT8_C( 119),
        -INT8_C(  40),      INT8_MIN,  INT8_C(  56),  INT8_C(   7),  INT8_C(  94),  INT8_C(   2),  INT8_C(  49), -INT8_C( 124),
        -INT8_C(  66),  INT8_C(  93), -INT8_C( 117),  INT8_C( 124), -INT8_C(  18), -INT8_C(  87), -INT8_C(   8), -INT8_C(   5),
        -INT8_C(  75), -INT8_C(  25), -INT8_C(  18), -INT8_C(  49), -INT8_C(  99),  INT8_C( 117), -INT8_C(  66),  INT8_C(  39),
        -INT8_C(  27), -INT8_C(  44),  INT8_C(  62),  INT8_C( 118), -INT8_C( 115),  INT8_C(  95), -INT8_C(   1), -INT8_C(  86),
        -INT8_C(  32), -INT8_C(  48), -INT8_C(  79),  INT8_C(  72), -INT8_C(  46), -INT8_C(  30), -INT8_C(  62), -INT8_C( 112) },
      UINT64_C( 3033746756841261364) },
    { UINT64_C(16211516295819169233),
      { -INT8_C(  71),  INT8_C(  96), -INT8_C(  52),  INT8_C(   3),  INT8_C(  15), -INT8_C(  56),  INT8_C(   6), -INT8_C(  92),
         INT8_C(  41), -INT8_C( 108),      INT8_MAX, -INT8_C(  19),  INT8_C(  87),      INT8_MIN, -INT8_C(  28),  INT8_C(   2),
        -INT8_C(  27), -INT8_C(  31),  INT8_C( 118),  INT8_C( 112),  INT8_C( 116), -INT8_C(  13),  INT8_C( 126), -INT8_C(  86),
         INT8_C(  61),  INT8_C(  18),      INT8_MIN, -INT8_C(   9), -INT8_C( 102), -INT8_C(  37), -INT8_C(  74),  INT8_C(  83),
         INT8_C(  59), -INT8_C( 125),  INT8_C(  86),  INT8_C(  74),  INT8_C(  75),  INT8_C(  92), -INT8_C(  18),  INT8_C( 116),
        -INT8_C(  16),  INT8_C( 109),  INT8_C(  97),  INT8_C(  71), -INT8_C(  19),  INT8_C(  70),  INT8_C(  73), -INT8_C(  46),
         INT8_C(  39), -INT8_C(  65),  INT8_C(  67), -INT8_C( 100), -INT8_C(  77), -INT8_C(  63),  INT8_C(  70), -INT8_C(  16),
        -INT8_C(  45), -INT8_C(  57), -INT8_C(  25),  INT8_C( 109), -INT8_C(  94), -INT8_C(  98), -INT8_C(  64), -INT8_C(  35) },
      {  INT8_C(  33),  INT8_C(  96),  INT8_C(  40),  INT8_C( 108),  INT8_C( 114),  INT8_C(  22), -INT8_C(  31),  INT8_C(  98),
        -INT8_C( 124),  INT8_C(  66), -INT8_C(  87),  INT8_C( 113), -INT8_C( 120), -INT8_C(  13),  INT8_C(  68), -INT8_C(  80),
        -INT8_C(  78), -INT8_C(  31),  INT8_C(  76),  INT8_C( 101),  INT8_C( 116), -INT8_C( 110),  INT8_C(  85),  INT8_C(  27),
         INT8_C(  89),  INT8_C(  61), -INT8_C( 120), -INT8_C(   9), -INT8_C( 102),  INT8_C(  72), -INT8_C(  39), -INT8_C(   4),
         INT8_C(  94),  INT8_C(   1),  INT8_C( 104),  INT8_C(  74),  INT8_C(  23),  INT8_C(  92),  INT8_C(  50), -INT8_C( 101),
        -INT8_C( 116),  INT8_C( 109),  INT8_C(  97),  INT8_C(  20), -INT8_C(  50),  INT8_C(  81),  INT8_C(  73), -INT8_C( 127),
        -INT8_C(  40),  INT8_C(  16), -INT8_C(  26),  INT8_C(  32), -INT8_C(  93), -INT8_C(  63),  INT8_C(  59), -INT8_C(   4),
         INT8_C( 121), -INT8_C(  61), -INT8_C(   8),  INT8_C(  84), -INT8_C(  94), -INT8_C(  47),  INT8_C(  80),  INT8_C( 105) },
      UINT64_C(16188857558042282129) },
    { UINT64_C( 5438556339746239249),
      { -INT8_C(  96),  INT8_C(  70),  INT8_C( 117), -INT8_C(  56),  INT8_C(  41), -INT8_C(  58),  INT8_C( 103), -INT8_C( 120),
        -INT8_C(  15),  INT8_C(  32), -INT8_C(  97),  INT8_C(  51), -INT8_C(  15), -INT8_C(  24),  INT8_C(  77), -INT8_C(  48),
        -INT8_C(  73),  INT8_C(  76), -INT8_C( 112),  INT8_C(  91), -INT8_C( 105),  INT8_C(   1), -INT8_C( 115),  INT8_C( 105),
         INT8_C(  14),  INT8_C(  79),  INT8_C(  43),  INT8_C(  60),  INT8_C(  47),  INT8_C(  37),  INT8_C(  28), -INT8_C(  49),
         INT8_C( 108), -INT8_C( 111), -INT8_C( 105), -INT8_C( 107),  INT8_C(  87), -INT8_C(   2),  INT8_C(  29),  INT8_C(  73),
         INT8_C(  31), -INT8_C(  68),  INT8_C( 124),  INT8_C(  16), -INT8_C(  91), -INT8_C(  55), -INT8_C(  32),  INT8_C(  92),
         INT8_C(  21),  INT8_C( 112), -INT8_C(  73), -INT8_C(  83),  INT8_C( 114),  INT8_C(  68),  INT8_C(  22),      INT8_MIN,
        -INT8_C( 109),  INT8_C(  65), -INT8_C(  68), -INT8_C(  62),  INT8_C( 103), -INT8_C(  40), -INT8_C( 111), -INT8_C(  45) },
      {  INT8_C( 106),  INT8_C(  70),  INT8_C( 104), -INT8_C(  56),  INT8_C(  39), -INT8_C( 123),  INT8_C(  10),  INT8_C(  70),
         INT8_C(  65), -INT8_C( 122), -INT8_C(  97),  INT8_C(  51),  INT8_C(  80),  INT8_C(  55),  INT8_C(  77), -INT8_C(  48),
        -INT8_C(  89), -INT8_C(   7),  INT8_C(  18),  INT8_C(  25),  INT8_C(  61),  INT8_C(  40), -INT8_C( 102), -INT8_C(  48),
         INT8_C( 106),  INT8_C(  86),  INT8_C(  43),  INT8_C(  60),  INT8_C(  47),  INT8_C(  36), -INT8_C(  92), -INT8_C(  49),
         INT8_C(  77),  INT8_C(  12), -INT8_C( 105), -INT8_C( 107),  INT8_C(  87),  INT8_C( 101), -INT8_C(  69), -INT8_C(  46),
        -INT8_C(  21),  INT8_C(  17), -INT8_C(  71),  INT8_C(  59),  INT8_C(  72), -INT8_C(   5), -INT8_C(  95),  INT8_C(  92),
        -INT8_C(  11), -INT8_C(  77),  INT8_C(   9),  INT8_C(  50), -INT8_C(  36),  INT8_C(  68),  INT8_C(   3),      INT8_MIN,
        -INT8_C(   6), -INT8_C( 107), -INT8_C(  68),  INT8_C(  41), -INT8_C(  71), -INT8_C(  69), -INT8_C(  62),  INT8_C(   6) },
      UINT64_C( 5271641673716527361) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__mmask64 k = test_vec[i].k;
    simde__m512i a = simde_mm512_loadu_epi8(test_vec[i].a);
    simde__m512i b = simde_mm512_loadu_epi8(test_vec[i].b);
    simde__mmask64 r = simde_mm512_mask_cmple_epi8_mask(k, a, b);
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
    simde__mmask64 r = simde_mm512_mask_cmple_epi8_mask(k, a, b);

    simde_test_x86_write_mmask64(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i8x64(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i8x64(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask64(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_x_mm_cmple_epu8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const uint8_t a[16];
    const uint8_t b[16];
    const uint8_t r[16];
  } test_vec[] = {
    { { UINT8_C(205), UINT8_C( 88), UINT8_C( 50), UINT8_C( 30), UINT8_C(123), UINT8_C( 84), UINT8_C(112), UINT8_C(149),
        UINT8_C( 68), UINT8_C( 91), UINT8_C( 25), UINT8_C(159), UINT8_C(220), UINT8_C(150), UINT8_C(124), UINT8_C(194) },
      { UINT8_C( 89), UINT8_C( 88), UINT8_C(150), UINT8_C( 30), UINT8_C(123), UINT8_C(120), UINT8_C(147), UINT8_C(149),
        UINT8_C( 68), UINT8_C( 20), UINT8_C( 25), UINT8_C(159), UINT8_C(220), UINT8_C(150), UINT8_C(102), UINT8_C( 91) },
      { UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
           UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0) } },
    { { UINT8_C(106), UINT8_C(120), UINT8_C( 66), UINT8_C(153), UINT8_C(241), UINT8_C(213), UINT8_C(112), UINT8_C(223),
        UINT8_C(233), UINT8_C(133), UINT8_C( 24), UINT8_C(119), UINT8_C( 65), UINT8_C(126), UINT8_C(210), UINT8_C( 86) },
      { UINT8_C( 22), UINT8_C( 75), UINT8_C(230), UINT8_C(  3), UINT8_C( 53), UINT8_C( 12), UINT8_C( 51), UINT8_C(121),
        UINT8_C(233), UINT8_C(  3), UINT8_C(154), UINT8_C( 31), UINT8_C( 65), UINT8_C(126), UINT8_C(210), UINT8_C(186) },
      { UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
           UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX } },
    { { UINT8_C(228), UINT8_C(198), UINT8_C(117), UINT8_C( 25), UINT8_C(210), UINT8_C(169), UINT8_C(146), UINT8_C( 29),
        UINT8_C(172), UINT8_C( 44), UINT8_C( 60), UINT8_C(252), UINT8_C(169), UINT8_C(137), UINT8_C(182), UINT8_C(158) },
      { UINT8_C(228), UINT8_C(  9), UINT8_C(132), UINT8_C(125), UINT8_C(204), UINT8_C( 73), UINT8_C(204), UINT8_C( 29),
        UINT8_C( 38), UINT8_C(146), UINT8_C( 60), UINT8_C(130), UINT8_C(169), UINT8_C(125), UINT8_C(245), UINT8_C( 14) },
      {    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,
        UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0) } },
    { { UINT8_C(123), UINT8_C(177), UINT8_C(142), UINT8_C( 71), UINT8_C(250), UINT8_C( 90), UINT8_C( 91), UINT8_C( 33),
        UINT8_C(236), UINT8_C(248), UINT8_C(163), UINT8_C( 23), UINT8_C(118), UINT8_C(152), UINT8_C( 37), UINT8_C(186) },
      { UINT8_C(123), UINT8_C( 77), UINT8_C(208), UINT8_C( 22), UINT8_C(  7), UINT8_C(  4), UINT8_C(214), UINT8_C(237),
        UINT8_C(115), UINT8_C(146), UINT8_C(125), UINT8_C( 23), UINT8_C(  4), UINT8_C(170), UINT8_C(125), UINT8_C(127) },
      {    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,
        UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0) } },
    { { UINT8_C(220), UINT8_C( 26), UINT8_C(205), UINT8_C(227), UINT8_C( 30), UINT8_C(163), UINT8_C(208), UINT8_C(146),
        UINT8_C( 54), UINT8_C( 77), UINT8_C(254), UINT8_C( 58), UINT8_C(248), UINT8_C(123), UINT8_C(186), UINT8_C( 84) },
      { UINT8_C(220), UINT8_C( 26), UINT8_C(170), UINT8_C(236), UINT8_C(162), UINT8_C( 34), UINT8_C( 63), UINT8_C(188),
        UINT8_C( 54), UINT8_C(168), UINT8_C(254), UINT8_C( 58), UINT8_C( 55), UINT8_C(150), UINT8_C(186), UINT8_C( 84) },
      {    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,
           UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX } },
    { { UINT8_C(194), UINT8_C( 11), UINT8_C( 77), UINT8_C(100), UINT8_C( 45), UINT8_C(140), UINT8_C( 32), UINT8_C(106),
        UINT8_C( 52), UINT8_C(108), UINT8_C( 90), UINT8_C(108), UINT8_C(  2), UINT8_C(  1), UINT8_C(127), UINT8_C(179) },
      { UINT8_C(117), UINT8_C(118), UINT8_C(130), UINT8_C(141), UINT8_C( 61), UINT8_C(140), UINT8_C( 32), UINT8_C( 81),
        UINT8_C( 52), UINT8_C( 98), UINT8_C( 94), UINT8_C( 28), UINT8_C(  2), UINT8_C(190), UINT8_C(124), UINT8_C(103) },
      { UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),
           UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0) } },
    { { UINT8_C(235), UINT8_C(144), UINT8_C(191), UINT8_C( 40), UINT8_C(115), UINT8_C(153), UINT8_C(122), UINT8_C(181),
        UINT8_C(252), UINT8_C(216), UINT8_C(209), UINT8_C(160), UINT8_C(150), UINT8_C( 77), UINT8_C(  7), UINT8_C( 96) },
      { UINT8_C(235), UINT8_C(211), UINT8_C( 86), UINT8_C(108), UINT8_C(191), UINT8_C(153), UINT8_C(122), UINT8_C( 23),
        UINT8_C(252), UINT8_C(236), UINT8_C(114), UINT8_C( 46), UINT8_C( 98), UINT8_C(128), UINT8_C( 96), UINT8_C( 77) },
      {    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),
           UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0) } },
    { { UINT8_C( 48), UINT8_C( 21), UINT8_C(218), UINT8_C(239), UINT8_C(204), UINT8_C(209), UINT8_C(  6), UINT8_C( 62),
        UINT8_C(189), UINT8_C(121), UINT8_C(108), UINT8_C( 31), UINT8_C(249), UINT8_C(205), UINT8_C(109), UINT8_C( 10) },
      { UINT8_C(236), UINT8_C(227), UINT8_C(218), UINT8_C(165), UINT8_C(204), UINT8_C(198), UINT8_C( 90), UINT8_C(155),
        UINT8_C(207), UINT8_C(176), UINT8_C(249), UINT8_C( 38), UINT8_C(249), UINT8_C(184), UINT8_C(148), UINT8_C( 61) },
      {    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,
           UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_x_mm_loadu_epi8(test_vec[i].a);
    simde__m128i b = simde_x_mm_loadu_epi8(test_vec[i].b);
    simde__m128i r = simde_x_mm_cmple_epu8(a, b);
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
    simde__m128i r = simde_x_mm_cmple_epu8(a, b);

    simde_test_x86_write_u8x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_u8x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_u8x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_cmple_epu8_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const uint8_t a[16];
    const uint8_t b[16];
    const simde__mmask16 r;
  } test_vec[] = {
    { { UINT8_C(127), UINT8_C( 29), UINT8_C(174), UINT8_C(  5), UINT8_C(125), UINT8_C( 92), UINT8_C(  7), UINT8_C( 87),
        UINT8_C( 11), UINT8_C(109), UINT8_C(  4), UINT8_C(125), UINT8_C( 65), UINT8_C( 23), UINT8_C(160), UINT8_C( 59) },
      { UINT8_C(127), UINT8_C(224), UINT8_C( 98), UINT8_C(126), UINT8_C(112), UINT8_C( 32), UINT8_C(  7), UINT8_C( 46),
        UINT8_C(112), UINT8_C(109), UINT8_C(  4), UINT8_C(121), UINT8_C( 65), UINT8_C( 23), UINT8_C(188), UINT8_C( 13) },
      UINT16_C(30539) },
    { { UINT8_C(208), UINT8_C(101), UINT8_C(172), UINT8_C( 64), UINT8_C(133), UINT8_C(194), UINT8_C(110), UINT8_C(245),
        UINT8_C(175), UINT8_C(126), UINT8_C(110), UINT8_C( 61), UINT8_C(181), UINT8_C( 43), UINT8_C( 74), UINT8_C(  9) },
      { UINT8_C(150), UINT8_C(101), UINT8_C(172), UINT8_C( 93), UINT8_C(117), UINT8_C(  2), UINT8_C(110), UINT8_C(251),
        UINT8_C(175), UINT8_C(128), UINT8_C(194), UINT8_C(115), UINT8_C(112), UINT8_C( 43), UINT8_C(160), UINT8_C( 64) },
      UINT16_C(61390) },
    { { UINT8_C(160), UINT8_C(  4), UINT8_C( 49), UINT8_C( 21), UINT8_C(  6), UINT8_C( 97), UINT8_C( 16), UINT8_C( 53),
        UINT8_C(225), UINT8_C(210), UINT8_C(168), UINT8_C( 81), UINT8_C(151), UINT8_C( 73), UINT8_C(145), UINT8_C(192) },
      { UINT8_C(149), UINT8_C( 17), UINT8_C(111), UINT8_C( 21), UINT8_C(  6), UINT8_C( 19), UINT8_C( 97), UINT8_C(107),
        UINT8_C( 37), UINT8_C( 92), UINT8_C(140), UINT8_C( 81), UINT8_C(160), UINT8_C(182), UINT8_C( 54), UINT8_C( 65) },
      UINT16_C(14558) },
    { { UINT8_C(156), UINT8_C(  0), UINT8_C( 33), UINT8_C(155), UINT8_C( 19), UINT8_C(130), UINT8_C(  6), UINT8_C( 56),
        UINT8_C(222), UINT8_C(146), UINT8_C(155), UINT8_C(127), UINT8_C( 72), UINT8_C(210), UINT8_C(192), UINT8_C(  2) },
      { UINT8_C(156), UINT8_C( 22), UINT8_C(195), UINT8_C(  2), UINT8_C(125), UINT8_C(130), UINT8_C(  6), UINT8_C(183),
        UINT8_C( 87), UINT8_C(166), UINT8_C(135), UINT8_C( 63), UINT8_C( 49), UINT8_C( 24), UINT8_C(188), UINT8_C(206) },
      UINT16_C(33527) },
    { { UINT8_C(147), UINT8_C( 16), UINT8_C( 13), UINT8_C( 17), UINT8_C(201), UINT8_C(184), UINT8_C(200), UINT8_C( 33),
        UINT8_C( 94), UINT8_C( 79), UINT8_C( 96), UINT8_C(144), UINT8_C(104), UINT8_C( 28), UINT8_C( 94), UINT8_C(128) },
      { UINT8_C(249), UINT8_C(199), UINT8_C(172), UINT8_C( 17), UINT8_C( 55), UINT8_C( 16), UINT8_C(150), UINT8_C( 33),
        UINT8_C( 94), UINT8_C( 83), UINT8_C( 96), UINT8_C(144), UINT8_C(208), UINT8_C(210), UINT8_C(236), UINT8_C(100) },
      UINT16_C(32655) },
    { { UINT8_C(197), UINT8_C( 33), UINT8_C(155), UINT8_C(253), UINT8_C( 49), UINT8_C( 49), UINT8_C( 55), UINT8_C( 64),
        UINT8_C(133), UINT8_C(188), UINT8_C( 33), UINT8_C( 85), UINT8_C(142), UINT8_C( 13), UINT8_C(185), UINT8_C(113) },
      { UINT8_C(  6), UINT8_C( 33), UINT8_C(155), UINT8_C(184), UINT8_C(107), UINT8_C(235), UINT8_C( 55), UINT8_C(248),
        UINT8_C( 25), UINT8_C(104), UINT8_C( 33), UINT8_C( 98), UINT8_C(102), UINT8_C( 97), UINT8_C(165), UINT8_C( 43) },
      UINT16_C(11510) },
    { { UINT8_C( 52), UINT8_C( 57), UINT8_C(225), UINT8_C(159), UINT8_C( 37), UINT8_C(169), UINT8_C(151), UINT8_C( 62),
        UINT8_C( 17), UINT8_C(132), UINT8_C(160), UINT8_C(119), UINT8_C(229), UINT8_C( 69), UINT8_C(163), UINT8_C(104) },
      { UINT8_C(133), UINT8_C(203), UINT8_C( 27), UINT8_C(247), UINT8_C( 37), UINT8_C( 15), UINT8_C(151), UINT8_C( 70),
        UINT8_C( 37), UINT8_C( 57), UINT8_C(240), UINT8_C( 72), UINT8_C( 63), UINT8_C( 69), UINT8_C(113), UINT8_C(104) },
      UINT16_C(42459) },
    { { UINT8_C(244), UINT8_C(151), UINT8_C( 11), UINT8_C( 31), UINT8_C(166), UINT8_C(248), UINT8_C(101), UINT8_C(203),
        UINT8_C( 50), UINT8_C( 86), UINT8_C( 19), UINT8_C(113), UINT8_C( 98), UINT8_C(133), UINT8_C(228), UINT8_C(167) },
      { UINT8_C(244), UINT8_C(246), UINT8_C( 18), UINT8_C(212), UINT8_C(160), UINT8_C(186), UINT8_C(226), UINT8_C(206),
        UINT8_C(  3), UINT8_C(104), UINT8_C( 19), UINT8_C(146), UINT8_C(144), UINT8_C(133), UINT8_C(228), UINT8_C(132) },
      UINT16_C(32463) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_x_mm_loadu_epi8(test_vec[i].a);
    simde__m128i b = simde_x_mm_loadu_epi8(test_vec[i].b);
    simde__mmask16 r = simde_mm_cmple_epu8_mask(a, b);
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
    simde__mmask16 r = simde_mm_cmple_epu8_mask(a, b);

    simde_test_x86_write_u8x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_u8x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_mask_cmple_epu8_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask16 k;
    const uint8_t a[16];
    const uint8_t b[16];
    const simde__mmask16 r;
  } test_vec[] = {
    { UINT16_C( 9355),
      { UINT8_C( 39), UINT8_C(122), UINT8_C(171), UINT8_C(199), UINT8_C( 53), UINT8_C(142), UINT8_C(150), UINT8_C( 56),
        UINT8_C(246), UINT8_C(120), UINT8_C(202), UINT8_C(134), UINT8_C(213), UINT8_C(112), UINT8_C( 11), UINT8_C(202) },
      { UINT8_C( 33), UINT8_C(174), UINT8_C(101), UINT8_C(203), UINT8_C(183), UINT8_C(142), UINT8_C(150), UINT8_C( 22),
        UINT8_C(246), UINT8_C(243), UINT8_C(215), UINT8_C( 68), UINT8_C( 35), UINT8_C(112), UINT8_C( 27), UINT8_C(202) },
      UINT16_C( 9226) },
    { UINT16_C(10317),
      { UINT8_C( 79), UINT8_C( 66), UINT8_C(240), UINT8_C(246), UINT8_C( 89), UINT8_C( 53), UINT8_C(233), UINT8_C( 48),
        UINT8_C(122), UINT8_C( 12), UINT8_C(112), UINT8_C(149), UINT8_C( 87), UINT8_C( 43), UINT8_C( 92), UINT8_C(105) },
      { UINT8_C( 79), UINT8_C(177), UINT8_C( 17), UINT8_C( 66), UINT8_C( 89), UINT8_C( 49), UINT8_C( 53), UINT8_C(206),
        UINT8_C( 38), UINT8_C(152), UINT8_C(170), UINT8_C(230), UINT8_C( 28), UINT8_C( 43), UINT8_C( 10), UINT8_C(108) },
      UINT16_C(10241) },
    { UINT16_C(56056),
      { UINT8_C(250), UINT8_C( 74), UINT8_C( 89), UINT8_C( 47), UINT8_C( 24), UINT8_C(128), UINT8_C(199), UINT8_C(194),
        UINT8_C(102), UINT8_C(227), UINT8_C(248), UINT8_C(112), UINT8_C( 79), UINT8_C(112), UINT8_C(107), UINT8_C(177) },
      { UINT8_C(250), UINT8_C( 74), UINT8_C(252), UINT8_C( 47), UINT8_C( 24), UINT8_C( 84), UINT8_C(180), UINT8_C(132),
        UINT8_C(102), UINT8_C( 81), UINT8_C( 32), UINT8_C(112), UINT8_C(  9), UINT8_C(110), UINT8_C( 66), UINT8_C(  3) },
      UINT16_C( 2072) },
    { UINT16_C(64031),
      { UINT8_C(126), UINT8_C( 61), UINT8_C( 46), UINT8_C( 50), UINT8_C(194), UINT8_C( 48), UINT8_C(132), UINT8_C(226),
        UINT8_C( 74), UINT8_C(141), UINT8_C( 80), UINT8_C(141), UINT8_C(144), UINT8_C(  8), UINT8_C( 41), UINT8_C(194) },
      { UINT8_C(216), UINT8_C( 69), UINT8_C( 46), UINT8_C(107), UINT8_C(199), UINT8_C( 48), UINT8_C(245), UINT8_C(226),
        UINT8_C(195), UINT8_C(240), UINT8_C( 23), UINT8_C(161), UINT8_C( 43), UINT8_C( 15), UINT8_C(123), UINT8_C(169) },
      UINT16_C(27167) },
    { UINT16_C(55426),
      { UINT8_C(142), UINT8_C(230), UINT8_C(145), UINT8_C(131), UINT8_C(159), UINT8_C( 85), UINT8_C(115), UINT8_C(182),
        UINT8_C(246), UINT8_C(159), UINT8_C(198), UINT8_C(113), UINT8_C( 72), UINT8_C( 19), UINT8_C( 26), UINT8_C( 36) },
      { UINT8_C( 34), UINT8_C(243), UINT8_C(145), UINT8_C( 19), UINT8_C( 23), UINT8_C( 85), UINT8_C( 85), UINT8_C(182),
        UINT8_C(238), UINT8_C(160), UINT8_C(162), UINT8_C( 45), UINT8_C(195), UINT8_C(193), UINT8_C( 26), UINT8_C( 36) },
      UINT16_C(53378) },
    { UINT16_C(43654),
      { UINT8_C( 12), UINT8_C(154), UINT8_C( 74), UINT8_C( 97), UINT8_C( 98), UINT8_C( 56), UINT8_C(  1), UINT8_C(  5),
        UINT8_C(102), UINT8_C(196), UINT8_C(198), UINT8_C(141), UINT8_C( 21), UINT8_C(110), UINT8_C( 70), UINT8_C(234) },
      { UINT8_C(181), UINT8_C( 84), UINT8_C( 50), UINT8_C(178), UINT8_C( 88), UINT8_C( 56), UINT8_C(  1), UINT8_C(205),
        UINT8_C(102), UINT8_C( 76), UINT8_C( 92), UINT8_C(156), UINT8_C( 69), UINT8_C(223), UINT8_C( 70), UINT8_C( 81) },
      UINT16_C(10368) },
    { UINT16_C(27815),
      { UINT8_C(124), UINT8_C(222), UINT8_C(195), UINT8_C(242), UINT8_C(172), UINT8_C( 11), UINT8_C( 63), UINT8_C(  8),
        UINT8_C(168), UINT8_C(132), UINT8_C(231), UINT8_C( 29), UINT8_C(213), UINT8_C( 96), UINT8_C(220), UINT8_C(135) },
      { UINT8_C( 60), UINT8_C(211), UINT8_C( 59), UINT8_C( 28), UINT8_C( 49), UINT8_C( 11), UINT8_C(195), UINT8_C( 28),
        UINT8_C(168), UINT8_C(216), UINT8_C( 77), UINT8_C(186), UINT8_C(162), UINT8_C(211), UINT8_C(100), UINT8_C( 31) },
      UINT16_C(10400) },
    { UINT16_C(52611),
      { UINT8_C(  7), UINT8_C(216), UINT8_C( 32), UINT8_C(202), UINT8_C(244), UINT8_C( 98), UINT8_C(163), UINT8_C( 65),
        UINT8_C( 28), UINT8_C( 69), UINT8_C( 21), UINT8_C(128), UINT8_C(100), UINT8_C(199), UINT8_C(167), UINT8_C(118) },
      { UINT8_C( 37), UINT8_C(218), UINT8_C( 32), UINT8_C(139), UINT8_C(180), UINT8_C(155), UINT8_C(163), UINT8_C(172),
        UINT8_C( 28), UINT8_C(136), UINT8_C(127), UINT8_C(117), UINT8_C(100), UINT8_C( 38), UINT8_C(226), UINT8_C(121) },
      UINT16_C(50563) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__mmask16 k = test_vec[i].k;
    simde__m128i a = simde_x_mm_loadu_epi8(test_vec[i].a);
    simde__m128i b = simde_x_mm_loadu_epi8(test_vec[i].b);
    simde__mmask16 r = simde_mm_mask_cmple_epu8_mask(k, a, b);
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
    simde__mmask16 r = simde_mm_mask_cmple_epu8_mask(k, a, b);

    simde_test_x86_write_mmask16(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_u8x16(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_u8x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_x_mm256_cmple_epu8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const uint8_t a[32];
    const uint8_t b[32];
    const uint8_t r[32];
  } test_vec[] = {
    { { UINT8_C( 60), UINT8_C(205), UINT8_C( 73), UINT8_C(106), UINT8_C( 34), UINT8_C(173), UINT8_C(229), UINT8_C(228),
        UINT8_C(115), UINT8_C(129), UINT8_C( 15), UINT8_C(225), UINT8_C( 86), UINT8_C( 98), UINT8_C(205), UINT8_C(112),
        UINT8_C(185), UINT8_C(112), UINT8_C(120), UINT8_C( 16), UINT8_C(121), UINT8_C(251), UINT8_C(169), UINT8_C( 75),
        UINT8_C(192), UINT8_C( 67), UINT8_C( 34), UINT8_C( 12), UINT8_C( 84), UINT8_C(136), UINT8_C(175), UINT8_C(144) },
      { UINT8_C( 85), UINT8_C(248), UINT8_C(251), UINT8_C(119), UINT8_C( 34), UINT8_C(224), UINT8_C( 92), UINT8_C( 25),
        UINT8_C( 97), UINT8_C(129), UINT8_C(250), UINT8_C(183), UINT8_C(206), UINT8_C( 98), UINT8_C(205), UINT8_C(135),
        UINT8_C(185), UINT8_C(159), UINT8_C(120), UINT8_C(177), UINT8_C(121), UINT8_C(251), UINT8_C(252), UINT8_C( 75),
        UINT8_C(132), UINT8_C( 31), UINT8_C( 34), UINT8_C(216), UINT8_C(167), UINT8_C(136), UINT8_C(104), UINT8_C(144) },
      {    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),
        UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
           UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
        UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX } },
    { { UINT8_C(144), UINT8_C(170), UINT8_C( 93), UINT8_C(212), UINT8_C(121), UINT8_C( 43), UINT8_C(121), UINT8_C(180),
        UINT8_C(243), UINT8_C(214), UINT8_C(189), UINT8_C(131), UINT8_C( 91), UINT8_C( 77), UINT8_C( 74), UINT8_C(127),
        UINT8_C(117), UINT8_C(194), UINT8_C( 62), UINT8_C(221), UINT8_C( 54), UINT8_C( 88), UINT8_C(201), UINT8_C(202),
        UINT8_C(218), UINT8_C(141), UINT8_C(  4), UINT8_C(115), UINT8_C(185), UINT8_C( 59), UINT8_C( 28), UINT8_C( 73) },
      { UINT8_C(229), UINT8_C(121), UINT8_C( 29), UINT8_C( 94), UINT8_C(165), UINT8_C(151), UINT8_C( 19), UINT8_C(152),
        UINT8_C(109), UINT8_C(208), UINT8_C( 27), UINT8_C(131), UINT8_C( 91), UINT8_C(101), UINT8_C( 71), UINT8_C(147),
        UINT8_C(117), UINT8_C(133), UINT8_C(112), UINT8_C( 94), UINT8_C( 54), UINT8_C( 57), UINT8_C( 40), UINT8_C(184),
        UINT8_C(198), UINT8_C( 44), UINT8_C( 44), UINT8_C(127), UINT8_C(103), UINT8_C( 72), UINT8_C(201), UINT8_C( 73) },
      {    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),
        UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,
           UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
        UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX } },
    { { UINT8_C(221), UINT8_C(185), UINT8_C(179), UINT8_C( 91), UINT8_C(119), UINT8_C(178), UINT8_C( 70), UINT8_C(  5),
        UINT8_C(204), UINT8_C(249), UINT8_C(178), UINT8_C( 76), UINT8_C(244), UINT8_C(241), UINT8_C(244), UINT8_C(117),
        UINT8_C(161), UINT8_C(249), UINT8_C(211), UINT8_C(137), UINT8_C( 39), UINT8_C(234), UINT8_C( 56), UINT8_C(129),
        UINT8_C( 45), UINT8_C(102), UINT8_C( 66), UINT8_C(184), UINT8_C( 93), UINT8_C( 80), UINT8_C(  5), UINT8_C( 58) },
      { UINT8_C(  9), UINT8_C(184), UINT8_C(149), UINT8_C(128), UINT8_C(106), UINT8_C(219), UINT8_C( 70), UINT8_C( 54),
        UINT8_C(213), UINT8_C( 56), UINT8_C(131), UINT8_C(201), UINT8_C( 41), UINT8_C(119), UINT8_C( 62), UINT8_C(202),
        UINT8_C(112), UINT8_C( 18), UINT8_C( 84), UINT8_C(151), UINT8_C(252), UINT8_C(140), UINT8_C( 56), UINT8_C( 42),
        UINT8_C(242), UINT8_C( 91), UINT8_C( 66), UINT8_C( 79), UINT8_C(171), UINT8_C(231), UINT8_C(137), UINT8_C(181) },
      { UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
           UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,
        UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),
           UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX } },
    { { UINT8_C(177), UINT8_C( 75), UINT8_C(131), UINT8_C(171), UINT8_C(  7), UINT8_C(195), UINT8_C(123), UINT8_C(250),
        UINT8_C(134), UINT8_C( 20), UINT8_C( 23), UINT8_C(192), UINT8_C(235),    UINT8_MAX, UINT8_C(106), UINT8_C(213),
        UINT8_C( 58), UINT8_C(172), UINT8_C(187), UINT8_C(  2), UINT8_C(  7), UINT8_C(203), UINT8_C(187), UINT8_C(188),
        UINT8_C(189), UINT8_C(196), UINT8_C( 29), UINT8_C(151), UINT8_C( 86), UINT8_C( 51), UINT8_C( 17), UINT8_C(  7) },
      { UINT8_C(127), UINT8_C(148), UINT8_C(178), UINT8_C(134), UINT8_C(  7), UINT8_C( 45), UINT8_C(128), UINT8_C(221),
        UINT8_C( 65), UINT8_C(152), UINT8_C(157), UINT8_C( 45), UINT8_C(151),    UINT8_MAX, UINT8_C(  2), UINT8_C(209),
        UINT8_C(180), UINT8_C(189), UINT8_C(211), UINT8_C(187), UINT8_C(136), UINT8_C(143), UINT8_C(119), UINT8_C(188),
        UINT8_C( 83), UINT8_C(196), UINT8_C(221), UINT8_C(169), UINT8_C(200), UINT8_C(238), UINT8_C(176), UINT8_C(  7) },
      { UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),
        UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),
           UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,
        UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX } },
    { { UINT8_C(191), UINT8_C(179), UINT8_C(177), UINT8_C( 79), UINT8_C(  1), UINT8_C(103), UINT8_C( 33), UINT8_C(231),
        UINT8_C(186), UINT8_C( 31), UINT8_C(100), UINT8_C( 20), UINT8_C( 32), UINT8_C(179), UINT8_C( 35), UINT8_C(221),
        UINT8_C(213), UINT8_C(236), UINT8_C( 35), UINT8_C(134), UINT8_C( 45), UINT8_C(174), UINT8_C(138), UINT8_C(  3),
        UINT8_C( 22), UINT8_C( 55), UINT8_C(162), UINT8_C(108), UINT8_C(148), UINT8_C(136), UINT8_C( 68), UINT8_C( 83) },
      { UINT8_C( 59), UINT8_C(245), UINT8_C(163), UINT8_C( 61), UINT8_C( 92), UINT8_C(196), UINT8_C( 36), UINT8_C( 22),
        UINT8_C(227), UINT8_C(137), UINT8_C( 42), UINT8_C(  3), UINT8_C( 60), UINT8_C( 77), UINT8_C( 35), UINT8_C( 17),
        UINT8_C( 58), UINT8_C(  4), UINT8_C( 35), UINT8_C(134), UINT8_C( 45), UINT8_C( 33), UINT8_C(138), UINT8_C(  3),
        UINT8_C( 22), UINT8_C( 55), UINT8_C(162), UINT8_C(236), UINT8_C(148), UINT8_C(120), UINT8_C( 63), UINT8_C(208) },
      { UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),
           UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),
        UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,
           UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX } },
    { { UINT8_C( 38), UINT8_C(227), UINT8_C(206), UINT8_C(204), UINT8_C( 21), UINT8_C(173), UINT8_C( 86), UINT8_C(208),
        UINT8_C(183), UINT8_C(228), UINT8_C(199), UINT8_C( 14), UINT8_C( 82), UINT8_C(207), UINT8_C(159), UINT8_C(197),
        UINT8_C(110), UINT8_C(151), UINT8_C(233), UINT8_C( 46), UINT8_C(251), UINT8_C(214), UINT8_C( 70), UINT8_C(107),
        UINT8_C(246), UINT8_C( 74), UINT8_C(113), UINT8_C(143), UINT8_C(142), UINT8_C( 71), UINT8_C(148), UINT8_C(180) },
      { UINT8_C( 42), UINT8_C(227), UINT8_C(128), UINT8_C( 64), UINT8_C( 16), UINT8_C(215), UINT8_C( 16), UINT8_C(199),
        UINT8_C(187), UINT8_C(228), UINT8_C(213), UINT8_C( 13), UINT8_C(167), UINT8_C(116), UINT8_C(210), UINT8_C( 22),
        UINT8_C( 12), UINT8_C(188), UINT8_C(233), UINT8_C( 46), UINT8_C(146), UINT8_C(139), UINT8_C( 70), UINT8_C(107),
        UINT8_C(213), UINT8_C( 74), UINT8_C( 23), UINT8_C(143), UINT8_C(142), UINT8_C(172), UINT8_C( 23), UINT8_C( 85) },
      {    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),
           UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),
        UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,
        UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0) } },
    { { UINT8_C(243), UINT8_C(174), UINT8_C(210), UINT8_C( 98), UINT8_C( 84), UINT8_C(185), UINT8_C(140), UINT8_C(209),
        UINT8_C(118), UINT8_C(195), UINT8_C(246), UINT8_C(167), UINT8_C(205), UINT8_C( 49), UINT8_C(228), UINT8_C(147),
        UINT8_C(177), UINT8_C( 40), UINT8_C(235), UINT8_C(187), UINT8_C(222), UINT8_C(204), UINT8_C(155), UINT8_C(120),
        UINT8_C(196), UINT8_C(223), UINT8_C( 61), UINT8_C(104), UINT8_C( 58), UINT8_C( 86), UINT8_C( 27), UINT8_C( 45) },
      { UINT8_C(  5), UINT8_C(237), UINT8_C(210), UINT8_C( 89), UINT8_C(167), UINT8_C( 27), UINT8_C( 42), UINT8_C( 29),
        UINT8_C(118), UINT8_C( 33), UINT8_C(196), UINT8_C(172), UINT8_C( 82), UINT8_C( 49), UINT8_C( 63), UINT8_C(  3),
        UINT8_C(208), UINT8_C( 43), UINT8_C(191), UINT8_C(174), UINT8_C(247), UINT8_C( 90), UINT8_C( 39), UINT8_C(187),
        UINT8_C( 57), UINT8_C(223), UINT8_C( 61), UINT8_C(115), UINT8_C(186), UINT8_C( 62), UINT8_C(160), UINT8_C(191) },
      { UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
           UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),
           UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,
        UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX } },
    { { UINT8_C( 80), UINT8_C(247), UINT8_C( 80), UINT8_C(155), UINT8_C( 58), UINT8_C( 64), UINT8_C(196), UINT8_C(158),
        UINT8_C(243), UINT8_C(153), UINT8_C( 85), UINT8_C( 79), UINT8_C(173), UINT8_C( 15), UINT8_C(122), UINT8_C(237),
        UINT8_C(136), UINT8_C( 84), UINT8_C( 35), UINT8_C( 91), UINT8_C( 85), UINT8_C( 21), UINT8_C(104), UINT8_C(186),
        UINT8_C( 41), UINT8_C(233), UINT8_C(218), UINT8_C(124), UINT8_C( 10), UINT8_C(185), UINT8_C(250), UINT8_C( 90) },
      { UINT8_C(176), UINT8_C(247), UINT8_C(245), UINT8_C(235), UINT8_C(138), UINT8_C( 64), UINT8_C(196), UINT8_C(158),
        UINT8_C( 82), UINT8_C(222), UINT8_C( 85), UINT8_C( 79), UINT8_C(173), UINT8_C( 71), UINT8_C(237), UINT8_C(237),
        UINT8_C(156), UINT8_C( 16), UINT8_C(209), UINT8_C(241), UINT8_C( 85), UINT8_C( 57), UINT8_C(172), UINT8_C( 79),
        UINT8_C( 41), UINT8_C(134), UINT8_C(203), UINT8_C( 44), UINT8_C( 63), UINT8_C(197), UINT8_C(135), UINT8_C(239) },
      {    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
        UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
           UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),
           UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256i a = simde_mm256_loadu_epi8(test_vec[i].a);
    simde__m256i b = simde_mm256_loadu_epi8(test_vec[i].b);
    simde__m256i r = simde_x_mm256_cmple_epu8(a, b);
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
    simde__m256i r = simde_x_mm256_cmple_epu8(a, b);

    simde_test_x86_write_u8x32(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_u8x32(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_u8x32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_cmple_epu8_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const uint8_t a[32];
    const uint8_t b[32];
    const simde__mmask32 r;
  } test_vec[] = {
    { { UINT8_C(248), UINT8_C(122), UINT8_C(  2), UINT8_C(253), UINT8_C(164), UINT8_C(187), UINT8_C(251), UINT8_C(207),
        UINT8_C(132), UINT8_C( 95), UINT8_C(132), UINT8_C(159), UINT8_C(133), UINT8_C( 86), UINT8_C(113), UINT8_C(114),
        UINT8_C( 34), UINT8_C( 41), UINT8_C(167), UINT8_C(206), UINT8_C(150), UINT8_C(109), UINT8_C(147), UINT8_C(139),
        UINT8_C(135), UINT8_C( 46), UINT8_C(100), UINT8_C(  6), UINT8_C(153), UINT8_C( 85), UINT8_C(153), UINT8_C(146) },
      { UINT8_C(207), UINT8_C(155), UINT8_C(143), UINT8_C(115), UINT8_C( 87), UINT8_C(187), UINT8_C( 66), UINT8_C(219),
        UINT8_C(233), UINT8_C(198), UINT8_C(132), UINT8_C(111), UINT8_C( 29), UINT8_C(236), UINT8_C(225), UINT8_C( 63),
        UINT8_C( 21), UINT8_C(136), UINT8_C( 13), UINT8_C(171), UINT8_C(245), UINT8_C(160), UINT8_C( 54), UINT8_C(124),
        UINT8_C(206), UINT8_C(154), UINT8_C(131), UINT8_C(  6), UINT8_C(239), UINT8_C( 28), UINT8_C(249), UINT8_C(190) },
      UINT32_C(3744622502) },
    { { UINT8_C(251), UINT8_C(191), UINT8_C(172), UINT8_C( 15), UINT8_C( 51), UINT8_C(150), UINT8_C( 12), UINT8_C(110),
        UINT8_C(251), UINT8_C(120), UINT8_C(197), UINT8_C( 76), UINT8_C(197), UINT8_C( 92), UINT8_C(178), UINT8_C(154),
           UINT8_MAX, UINT8_C(195), UINT8_C(101), UINT8_C( 67), UINT8_C( 10), UINT8_C(173), UINT8_C( 84), UINT8_C(235),
        UINT8_C(119), UINT8_C(205), UINT8_C(187), UINT8_C( 94), UINT8_C( 64), UINT8_C( 73), UINT8_C(252), UINT8_C( 59) },
      { UINT8_C(  9), UINT8_C(168), UINT8_C( 74), UINT8_C( 60), UINT8_C( 63), UINT8_C(150), UINT8_C( 12), UINT8_C( 58),
        UINT8_C(251), UINT8_C(112), UINT8_C(135), UINT8_C( 76), UINT8_C(197), UINT8_C( 57), UINT8_C( 46), UINT8_C(203),
           UINT8_MAX, UINT8_C(147), UINT8_C( 14), UINT8_C(  7), UINT8_C( 64), UINT8_C(173), UINT8_C(243), UINT8_C(184),
        UINT8_C( 48), UINT8_C(174), UINT8_C( 22), UINT8_C(112), UINT8_C(248), UINT8_C( 18), UINT8_C(172), UINT8_C(  1) },
      UINT32_C( 410098040) },
    { { UINT8_C(164), UINT8_C(209), UINT8_C( 69), UINT8_C(241), UINT8_C(185), UINT8_C(121), UINT8_C( 13), UINT8_C( 17),
        UINT8_C( 52), UINT8_C(188), UINT8_C( 53), UINT8_C( 40), UINT8_C(153), UINT8_C( 36), UINT8_C( 26), UINT8_C(  9),
        UINT8_C( 34), UINT8_C( 19), UINT8_C(186), UINT8_C(131),    UINT8_MAX, UINT8_C( 35), UINT8_C( 21), UINT8_C(153),
        UINT8_C(162), UINT8_C( 23), UINT8_C( 44), UINT8_C( 51), UINT8_C(197), UINT8_C(191), UINT8_C(127), UINT8_C(105) },
      { UINT8_C(144), UINT8_C(196), UINT8_C( 69), UINT8_C( 73), UINT8_C( 61), UINT8_C(104), UINT8_C( 90), UINT8_C(113),
        UINT8_C( 36), UINT8_C(143), UINT8_C( 53), UINT8_C(189), UINT8_C(153), UINT8_C(179), UINT8_C(198), UINT8_C(214),
        UINT8_C( 34), UINT8_C(129), UINT8_C(186), UINT8_C(131), UINT8_C(164), UINT8_C(111), UINT8_C( 95), UINT8_C(153),
        UINT8_C(134), UINT8_C(139), UINT8_C(122), UINT8_C( 75), UINT8_C( 74), UINT8_C(249), UINT8_C(127), UINT8_C(219) },
      UINT32_C(4008705220) },
    { { UINT8_C(247), UINT8_C(120), UINT8_C(183), UINT8_C(110), UINT8_C(247), UINT8_C( 35), UINT8_C( 10), UINT8_C(  6),
        UINT8_C( 40), UINT8_C( 98), UINT8_C(200), UINT8_C(224), UINT8_C(129), UINT8_C( 97), UINT8_C( 95), UINT8_C( 33),
        UINT8_C( 84), UINT8_C(164), UINT8_C(102), UINT8_C(182), UINT8_C( 71), UINT8_C(241), UINT8_C(158), UINT8_C(118),
        UINT8_C(247), UINT8_C(209), UINT8_C(239), UINT8_C(247), UINT8_C(185), UINT8_C( 67), UINT8_C(180), UINT8_C(176) },
      { UINT8_C(187), UINT8_C(107), UINT8_C(183), UINT8_C(179), UINT8_C(142), UINT8_C( 40), UINT8_C( 10), UINT8_C(182),
        UINT8_C(139), UINT8_C(129), UINT8_C(151), UINT8_C( 12), UINT8_C(227), UINT8_C(246), UINT8_C( 46), UINT8_C( 33),
        UINT8_C(154), UINT8_C(148), UINT8_C(238), UINT8_C(226), UINT8_C( 71), UINT8_C(140), UINT8_C( 88), UINT8_C(125),
        UINT8_C( 94), UINT8_C( 71), UINT8_C(116), UINT8_C( 23), UINT8_C(138), UINT8_C( 67), UINT8_C(199), UINT8_C( 69) },
      UINT32_C(1620947948) },
    { { UINT8_C(233), UINT8_C( 73), UINT8_C(187), UINT8_C(247), UINT8_C(251), UINT8_C(148), UINT8_C(144), UINT8_C( 46),
        UINT8_C(  3), UINT8_C( 54), UINT8_C( 68), UINT8_C(105), UINT8_C(  9), UINT8_C(145), UINT8_C(106), UINT8_C(113),
        UINT8_C(205), UINT8_C( 76), UINT8_C( 94), UINT8_C(149), UINT8_C(135), UINT8_C(200), UINT8_C(187), UINT8_C(  8),
        UINT8_C(166), UINT8_C(248), UINT8_C( 20), UINT8_C(172), UINT8_C(252), UINT8_C(101), UINT8_C( 69), UINT8_C(229) },
      { UINT8_C(233), UINT8_C( 73), UINT8_C(221), UINT8_C(169), UINT8_C(149), UINT8_C(148), UINT8_C(215), UINT8_C(152),
        UINT8_C(  3), UINT8_C( 54), UINT8_C(  2), UINT8_C(173), UINT8_C(  9), UINT8_C(145), UINT8_C( 30), UINT8_C(113),
        UINT8_C(205), UINT8_C(124), UINT8_C( 94), UINT8_C(149), UINT8_C(135), UINT8_C(200), UINT8_C( 72), UINT8_C(234),
        UINT8_C(166), UINT8_C(248), UINT8_C( 20), UINT8_C(190), UINT8_C(252), UINT8_C(219), UINT8_C( 69), UINT8_C(229) },
      UINT32_C(4290755559) },
    { { UINT8_C(176), UINT8_C( 93), UINT8_C(198), UINT8_C(158), UINT8_C( 78), UINT8_C(208), UINT8_C( 47), UINT8_C( 90),
        UINT8_C(220), UINT8_C(110), UINT8_C( 19), UINT8_C( 84), UINT8_C(202), UINT8_C( 70), UINT8_C(132), UINT8_C(163),
        UINT8_C(136), UINT8_C(244), UINT8_C(191), UINT8_C(148), UINT8_C(172), UINT8_C(198), UINT8_C( 98), UINT8_C(192),
        UINT8_C( 98), UINT8_C(238), UINT8_C(149), UINT8_C(218), UINT8_C( 29), UINT8_C(218), UINT8_C( 47), UINT8_C(205) },
      { UINT8_C( 55), UINT8_C(245), UINT8_C(107), UINT8_C(133), UINT8_C(197), UINT8_C(155), UINT8_C(223), UINT8_C(161),
        UINT8_C(  9), UINT8_C(110), UINT8_C(245), UINT8_C(211), UINT8_C( 56), UINT8_C(121), UINT8_C(118), UINT8_C(192),
        UINT8_C(110), UINT8_C( 54), UINT8_C( 84), UINT8_C( 26), UINT8_C(252), UINT8_C(182), UINT8_C(219), UINT8_C( 94),
        UINT8_C(164), UINT8_C(112), UINT8_C(149), UINT8_C(218), UINT8_C( 74), UINT8_C(104), UINT8_C(143), UINT8_C(130) },
      UINT32_C(1565568722) },
    { { UINT8_C(206), UINT8_C(217), UINT8_C(153), UINT8_C(100), UINT8_C(192), UINT8_C( 92), UINT8_C(  3), UINT8_C(154),
        UINT8_C( 20), UINT8_C(118), UINT8_C(172), UINT8_C( 70), UINT8_C( 95), UINT8_C(126), UINT8_C(229), UINT8_C(126),
        UINT8_C(165), UINT8_C(159), UINT8_C(153), UINT8_C(131), UINT8_C( 52), UINT8_C( 18), UINT8_C(  5), UINT8_C( 58),
        UINT8_C(197), UINT8_C( 73), UINT8_C(138), UINT8_C(223), UINT8_C( 28), UINT8_C( 92), UINT8_C( 87), UINT8_C(235) },
      { UINT8_C( 53), UINT8_C(217), UINT8_C(153), UINT8_C(246), UINT8_C( 77), UINT8_C( 92), UINT8_C(  3), UINT8_C(154),
        UINT8_C( 20), UINT8_C( 60), UINT8_C(172), UINT8_C( 40), UINT8_C( 95), UINT8_C(141), UINT8_C(166), UINT8_C( 96),
        UINT8_C( 44), UINT8_C( 63), UINT8_C(227), UINT8_C( 97), UINT8_C( 81), UINT8_C(232), UINT8_C(155), UINT8_C( 22),
        UINT8_C( 49), UINT8_C( 37), UINT8_C(138), UINT8_C( 77), UINT8_C( 28), UINT8_C( 77), UINT8_C( 56), UINT8_C(182) },
      UINT32_C( 343160302) },
    { { UINT8_C(157), UINT8_C( 82), UINT8_C( 36), UINT8_C(120), UINT8_C(142), UINT8_C( 16), UINT8_C( 28), UINT8_C(  7),
        UINT8_C(163), UINT8_C(232), UINT8_C( 58), UINT8_C(196), UINT8_C( 90), UINT8_C(205), UINT8_C( 17), UINT8_C( 11),
        UINT8_C( 67), UINT8_C(191), UINT8_C( 13), UINT8_C(161), UINT8_C(  8), UINT8_C( 38), UINT8_C( 48), UINT8_C(118),
        UINT8_C( 53), UINT8_C( 12), UINT8_C(101), UINT8_C(145), UINT8_C( 33), UINT8_C( 10), UINT8_C( 43), UINT8_C(190) },
      { UINT8_C(157), UINT8_C( 82), UINT8_C( 54), UINT8_C(235), UINT8_C( 95), UINT8_C( 82), UINT8_C(242), UINT8_C(  2),
        UINT8_C( 58), UINT8_C(232), UINT8_C(198), UINT8_C(148), UINT8_C( 90), UINT8_C(215), UINT8_C(159), UINT8_C( 60),
        UINT8_C(150), UINT8_C(173), UINT8_C(221), UINT8_C(158), UINT8_C(  8), UINT8_C( 13), UINT8_C( 20), UINT8_C(  9),
        UINT8_C( 25), UINT8_C(121), UINT8_C(154), UINT8_C( 59), UINT8_C(132), UINT8_C(197), UINT8_C(249), UINT8_C(224) },
      UINT32_C(4128634479) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256i a = simde_mm256_loadu_epi8(test_vec[i].a);
    simde__m256i b = simde_mm256_loadu_epi8(test_vec[i].b);
    simde__mmask32 r = simde_mm256_cmple_epu8_mask(a, b);
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
    simde__mmask32 r = simde_mm256_cmple_epu8_mask(a, b);

    simde_test_x86_write_u8x32(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_u8x32(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_mask_cmple_epu8_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask32 k;
    const uint8_t a[32];
    const uint8_t b[32];
    const simde__mmask32 r;
  } test_vec[] = {
    { UINT32_C(3393878846),
      { UINT8_C(105), UINT8_C( 49), UINT8_C(209), UINT8_C(211), UINT8_C(223), UINT8_C(  4), UINT8_C(238), UINT8_C(200),
        UINT8_C( 34), UINT8_C(200), UINT8_C(211), UINT8_C(221), UINT8_C( 68), UINT8_C( 40), UINT8_C(141), UINT8_C(116),
        UINT8_C(214), UINT8_C(210), UINT8_C(195), UINT8_C( 65), UINT8_C(250), UINT8_C(149), UINT8_C(209), UINT8_C(147),
        UINT8_C(248), UINT8_C( 43), UINT8_C(153), UINT8_C(218), UINT8_C(254), UINT8_C(220), UINT8_C( 33), UINT8_C(103) },
      { UINT8_C( 13), UINT8_C( 49), UINT8_C( 58), UINT8_C(211), UINT8_C(223), UINT8_C( 40), UINT8_C(238), UINT8_C(200),
        UINT8_C(240), UINT8_C(136), UINT8_C(211), UINT8_C(221), UINT8_C( 68), UINT8_C(130), UINT8_C(168), UINT8_C(116),
        UINT8_C( 84), UINT8_C(108), UINT8_C(200), UINT8_C( 79), UINT8_C(250), UINT8_C(153), UINT8_C(226), UINT8_C(249),
        UINT8_C(197), UINT8_C(123), UINT8_C(153), UINT8_C(218), UINT8_C( 87), UINT8_C(244), UINT8_C( 42), UINT8_C(101) },
      UINT32_C(1246263610) },
    { UINT32_C(2917456009),
      { UINT8_C(130), UINT8_C( 63), UINT8_C( 70), UINT8_C( 18), UINT8_C( 40), UINT8_C(246), UINT8_C( 82), UINT8_C(148),
        UINT8_C( 79), UINT8_C( 24), UINT8_C( 85), UINT8_C( 20), UINT8_C(167), UINT8_C(100), UINT8_C(218), UINT8_C(207),
        UINT8_C( 86), UINT8_C(154), UINT8_C(188), UINT8_C(195), UINT8_C( 45), UINT8_C(108), UINT8_C(135), UINT8_C(180),
        UINT8_C( 70), UINT8_C(177), UINT8_C( 34), UINT8_C(132), UINT8_C( 44), UINT8_C(109), UINT8_C( 78), UINT8_C(175) },
      { UINT8_C(172), UINT8_C( 63), UINT8_C( 70), UINT8_C( 18), UINT8_C(138), UINT8_C( 19), UINT8_C(105), UINT8_C(218),
        UINT8_C( 43), UINT8_C( 24), UINT8_C(238), UINT8_C(210), UINT8_C( 34), UINT8_C(201), UINT8_C(161), UINT8_C(207),
        UINT8_C( 86), UINT8_C( 93), UINT8_C(188), UINT8_C(144), UINT8_C(201), UINT8_C(195), UINT8_C( 68), UINT8_C( 15),
        UINT8_C( 70), UINT8_C(103), UINT8_C(147), UINT8_C(132), UINT8_C(212), UINT8_C(225), UINT8_C( 78), UINT8_C(175) },
      UINT32_C(2904852617) },
    { UINT32_C( 114598817),
      { UINT8_C(150), UINT8_C(190), UINT8_C(252), UINT8_C( 17), UINT8_C(134), UINT8_C( 29), UINT8_C(175), UINT8_C( 24),
        UINT8_C(224), UINT8_C(198), UINT8_C( 12), UINT8_C(  1), UINT8_C( 24), UINT8_C(145), UINT8_C(235), UINT8_C( 45),
        UINT8_C( 90), UINT8_C(228), UINT8_C(182), UINT8_C(138), UINT8_C(113), UINT8_C(223), UINT8_C(142), UINT8_C(224),
        UINT8_C( 88), UINT8_C( 18), UINT8_C(196), UINT8_C(226), UINT8_C(234), UINT8_C(168), UINT8_C(143), UINT8_C(128) },
      { UINT8_C(102), UINT8_C(139), UINT8_C(146), UINT8_C(236), UINT8_C(134), UINT8_C( 65), UINT8_C(175), UINT8_C( 24),
        UINT8_C(  7), UINT8_C( 17), UINT8_C(138), UINT8_C( 31), UINT8_C(162), UINT8_C(145), UINT8_C( 76), UINT8_C( 45),
        UINT8_C( 89), UINT8_C(  2), UINT8_C(134), UINT8_C(138), UINT8_C(226), UINT8_C( 20), UINT8_C(171), UINT8_C( 58),
        UINT8_C( 38), UINT8_C(111), UINT8_C( 28), UINT8_C(226), UINT8_C( 23), UINT8_C(171), UINT8_C(145), UINT8_C(125) },
      UINT32_C(  38838432) },
    { UINT32_C( 548017031),
      { UINT8_C( 17), UINT8_C( 60), UINT8_C(114), UINT8_C(144), UINT8_C( 46), UINT8_C(253), UINT8_C(177), UINT8_C(149),
        UINT8_C(213), UINT8_C(206), UINT8_C( 86), UINT8_C(176), UINT8_C(113), UINT8_C(225), UINT8_C(108), UINT8_C( 40),
        UINT8_C( 24), UINT8_C( 99), UINT8_C(  5), UINT8_C(189), UINT8_C(119), UINT8_C(242), UINT8_C(122), UINT8_C( 54),
        UINT8_C(113), UINT8_C(179), UINT8_C( 43), UINT8_C( 18), UINT8_C( 86), UINT8_C(  0), UINT8_C( 24), UINT8_C(103) },
      { UINT8_C( 60), UINT8_C( 60), UINT8_C(247), UINT8_C(107), UINT8_C(136), UINT8_C(168), UINT8_C(  0), UINT8_C( 93),
        UINT8_C(213), UINT8_C(206), UINT8_C( 13), UINT8_C(176), UINT8_C( 56), UINT8_C(122), UINT8_C(108), UINT8_C( 40),
        UINT8_C(221), UINT8_C( 20), UINT8_C(  5), UINT8_C( 84), UINT8_C(  7), UINT8_C(135), UINT8_C(138), UINT8_C( 54),
        UINT8_C( 59), UINT8_C(179), UINT8_C(138), UINT8_C(145), UINT8_C(182), UINT8_C(163), UINT8_C(249), UINT8_C(242) },
      UINT32_C( 545260295) },
    { UINT32_C(1912583691),
      { UINT8_C(113), UINT8_C(189), UINT8_C( 48), UINT8_C( 37), UINT8_C(222), UINT8_C( 39), UINT8_C( 18), UINT8_C(120),
        UINT8_C( 45), UINT8_C( 78), UINT8_C(240), UINT8_C( 72), UINT8_C(152), UINT8_C(189), UINT8_C(106), UINT8_C(106),
        UINT8_C( 20), UINT8_C(  4), UINT8_C(118), UINT8_C( 33), UINT8_C( 41), UINT8_C( 20), UINT8_C(228), UINT8_C(240),
        UINT8_C(171), UINT8_C(153), UINT8_C(229), UINT8_C( 51), UINT8_C(172), UINT8_C(144), UINT8_C( 83), UINT8_C( 29) },
      { UINT8_C( 77), UINT8_C(131), UINT8_C( 67), UINT8_C( 43), UINT8_C(170), UINT8_C( 85), UINT8_C(164), UINT8_C(216),
        UINT8_C( 45), UINT8_C(148), UINT8_C( 32), UINT8_C( 60), UINT8_C(152), UINT8_C(139), UINT8_C(166), UINT8_C(106),
        UINT8_C( 20), UINT8_C( 28), UINT8_C(118), UINT8_C(184), UINT8_C( 41), UINT8_C(106), UINT8_C(169), UINT8_C(240),
        UINT8_C(171), UINT8_C(142), UINT8_C(229), UINT8_C(176), UINT8_C(172), UINT8_C( 99), UINT8_C(206), UINT8_C(108) },
      UINT32_C(1371509256) },
    { UINT32_C(1327024853),
      { UINT8_C(241), UINT8_C(104), UINT8_C(123), UINT8_C(193), UINT8_C(242), UINT8_C(192), UINT8_C(227), UINT8_C(  6),
        UINT8_C(172), UINT8_C(106), UINT8_C(170), UINT8_C(180), UINT8_C(119), UINT8_C(  7), UINT8_C(237), UINT8_C(239),
        UINT8_C( 12), UINT8_C(  2), UINT8_C(107), UINT8_C(160), UINT8_C( 39), UINT8_C(152), UINT8_C( 83), UINT8_C(175),
        UINT8_C(146), UINT8_C(113), UINT8_C( 30), UINT8_C(158), UINT8_C( 39), UINT8_C( 29), UINT8_C( 15), UINT8_C( 25) },
      { UINT8_C(241), UINT8_C(104), UINT8_C(218), UINT8_C(120), UINT8_C( 75), UINT8_C(189), UINT8_C(126), UINT8_C(247),
        UINT8_C( 39), UINT8_C( 41), UINT8_C(170), UINT8_C(159), UINT8_C( 48), UINT8_C(152), UINT8_C(142), UINT8_C(239),
        UINT8_C(154), UINT8_C(  2), UINT8_C(221), UINT8_C(194), UINT8_C( 39), UINT8_C( 48), UINT8_C(113), UINT8_C( 36),
        UINT8_C(161), UINT8_C(143), UINT8_C(194), UINT8_C(158), UINT8_C( 39), UINT8_C( 29), UINT8_C(226), UINT8_C( 25) },
      UINT32_C(1327005829) },
    { UINT32_C(3417426733),
      { UINT8_C(243), UINT8_C(182), UINT8_C(240), UINT8_C( 70), UINT8_C(  0), UINT8_C( 49), UINT8_C(200), UINT8_C(225),
        UINT8_C(  0), UINT8_C(135), UINT8_C( 93), UINT8_C(201), UINT8_C( 35), UINT8_C(155), UINT8_C( 36), UINT8_C(239),
        UINT8_C( 75), UINT8_C(163), UINT8_C( 93), UINT8_C(138), UINT8_C(229), UINT8_C(147), UINT8_C(118), UINT8_C(249),
        UINT8_C(172), UINT8_C(149), UINT8_C(106), UINT8_C(129), UINT8_C( 95), UINT8_C(130), UINT8_C(208), UINT8_C( 82) },
      { UINT8_C( 56), UINT8_C(192), UINT8_C(152), UINT8_C( 56), UINT8_C(241), UINT8_C( 49), UINT8_C(200), UINT8_C(241),
        UINT8_C(232), UINT8_C(119), UINT8_C(186), UINT8_C( 12), UINT8_C( 19), UINT8_C(222), UINT8_C( 36), UINT8_C( 94),
        UINT8_C(130), UINT8_C(163), UINT8_C(232), UINT8_C(103), UINT8_C(236), UINT8_C(147), UINT8_C( 97), UINT8_C(152),
        UINT8_C(243), UINT8_C(203), UINT8_C( 25), UINT8_C(129), UINT8_C( 95), UINT8_C(130), UINT8_C(164), UINT8_C(133) },
      UINT32_C(2335260960) },
    { UINT32_C(  32664238),
      { UINT8_C(163), UINT8_C( 61), UINT8_C( 81), UINT8_C(243), UINT8_C(132), UINT8_C(228), UINT8_C( 85), UINT8_C(170),
        UINT8_C(114), UINT8_C( 22), UINT8_C( 81), UINT8_C( 88), UINT8_C(190), UINT8_C( 96), UINT8_C( 43), UINT8_C(197),
        UINT8_C(208), UINT8_C(149), UINT8_C(190), UINT8_C( 11), UINT8_C( 25), UINT8_C( 10), UINT8_C(147), UINT8_C(133),
        UINT8_C(250), UINT8_C(161), UINT8_C(155), UINT8_C( 39), UINT8_C(108), UINT8_C( 76), UINT8_C(242), UINT8_C( 16) },
      { UINT8_C(138), UINT8_C( 67), UINT8_C(  3), UINT8_C(243), UINT8_C( 39), UINT8_C( 88), UINT8_C(184), UINT8_C(153),
        UINT8_C(114), UINT8_C( 22), UINT8_C(242), UINT8_C( 45), UINT8_C(106), UINT8_C( 96), UINT8_C(242), UINT8_C( 59),
        UINT8_C(178), UINT8_C(149), UINT8_C( 70), UINT8_C(203), UINT8_C(186), UINT8_C( 10), UINT8_C(147), UINT8_C(180),
        UINT8_C(250), UINT8_C(236), UINT8_C(155), UINT8_C(231), UINT8_C( 57), UINT8_C( 76), UINT8_C(242), UINT8_C(195) },
      UINT32_C(  32662026) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__mmask32 k = test_vec[i].k;
    simde__m256i a = simde_mm256_loadu_epi8(test_vec[i].a);
    simde__m256i b = simde_mm256_loadu_epi8(test_vec[i].b);
    simde__mmask32 r = simde_mm256_mask_cmple_epu8_mask(k, a, b);
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
    simde__mmask32 r = simde_mm256_mask_cmple_epu8_mask(k, a, b);

    simde_test_x86_write_mmask32(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_u8x32(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_u8x32(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_x_mm512_cmple_epu8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const uint8_t a[64];
    const uint8_t b[64];
    const uint8_t r[64];
  } test_vec[] = {
    { { UINT8_C(  2), UINT8_C(245), UINT8_C( 52), UINT8_C( 56), UINT8_C( 89), UINT8_C( 76), UINT8_C(193), UINT8_C(155),
        UINT8_C( 49), UINT8_C( 73), UINT8_C(203), UINT8_C( 93), UINT8_C(191), UINT8_C(113), UINT8_C( 38), UINT8_C( 69),
        UINT8_C(231), UINT8_C(224), UINT8_C(240), UINT8_C(151), UINT8_C( 70), UINT8_C(235), UINT8_C(106), UINT8_C( 50),
        UINT8_C(176), UINT8_C(105), UINT8_C( 93), UINT8_C( 59), UINT8_C(239), UINT8_C(119), UINT8_C(213), UINT8_C(241),
        UINT8_C(108), UINT8_C(  9), UINT8_C( 42), UINT8_C(197), UINT8_C( 85), UINT8_C(235), UINT8_C( 97), UINT8_C(134),
        UINT8_C( 52), UINT8_C( 44), UINT8_C(227), UINT8_C(243), UINT8_C(157), UINT8_C(  9), UINT8_C( 56), UINT8_C(133),
        UINT8_C(233), UINT8_C( 41), UINT8_C( 28), UINT8_C( 47), UINT8_C( 20), UINT8_C(134), UINT8_C( 97), UINT8_C(196),
        UINT8_C(239), UINT8_C(190),    UINT8_MAX, UINT8_C(222), UINT8_C( 54), UINT8_C(212), UINT8_C(208), UINT8_C(162) },
      { UINT8_C(221), UINT8_C(250), UINT8_C(104), UINT8_C( 50), UINT8_C( 89), UINT8_C(201), UINT8_C(184), UINT8_C(155),
        UINT8_C(245), UINT8_C(156), UINT8_C( 13), UINT8_C(147), UINT8_C(165), UINT8_C( 69), UINT8_C( 24), UINT8_C(143),
        UINT8_C(110), UINT8_C( 52), UINT8_C(190), UINT8_C(130), UINT8_C(187), UINT8_C( 32), UINT8_C( 71), UINT8_C(170),
        UINT8_C(222), UINT8_C(105), UINT8_C(137), UINT8_C( 20), UINT8_C( 27), UINT8_C( 89), UINT8_C(183), UINT8_C(241),
        UINT8_C( 83), UINT8_C(  9), UINT8_C( 42), UINT8_C( 56), UINT8_C(232), UINT8_C(227), UINT8_C( 81), UINT8_C(221),
        UINT8_C(127), UINT8_C( 94), UINT8_C(227), UINT8_C(243), UINT8_C(157), UINT8_C(136), UINT8_C(180), UINT8_C(133),
        UINT8_C(189), UINT8_C(114), UINT8_C(149), UINT8_C( 47), UINT8_C( 20), UINT8_C(220), UINT8_C( 34), UINT8_C(113),
        UINT8_C( 34), UINT8_C(171), UINT8_C(133), UINT8_C( 61), UINT8_C(  4), UINT8_C( 60), UINT8_C( 54), UINT8_C(162) },
      {    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,
           UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,
        UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,
           UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,
        UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,
           UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
        UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),
        UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX } },
    { { UINT8_C(152), UINT8_C(195), UINT8_C( 66), UINT8_C(129), UINT8_C( 88), UINT8_C(169), UINT8_C(170), UINT8_C(126),
        UINT8_C(248), UINT8_C(183), UINT8_C(191), UINT8_C(229), UINT8_C(185), UINT8_C(214), UINT8_C(225), UINT8_C( 71),
        UINT8_C( 61), UINT8_C(127), UINT8_C( 59), UINT8_C( 21), UINT8_C( 48), UINT8_C(185), UINT8_C( 10), UINT8_C(121),
        UINT8_C(254), UINT8_C( 32), UINT8_C(152), UINT8_C( 64), UINT8_C(176), UINT8_C(231), UINT8_C(224), UINT8_C( 72),
        UINT8_C(170), UINT8_C( 35), UINT8_C(201), UINT8_C(  2), UINT8_C(204), UINT8_C(116), UINT8_C(128), UINT8_C(196),
        UINT8_C( 43), UINT8_C( 63), UINT8_C(169), UINT8_C(228), UINT8_C( 22), UINT8_C(138), UINT8_C( 43), UINT8_C( 83),
        UINT8_C(  9), UINT8_C(103), UINT8_C(104), UINT8_C( 57), UINT8_C( 32), UINT8_C(114), UINT8_C(179), UINT8_C( 31),
        UINT8_C(146), UINT8_C( 75), UINT8_C( 95), UINT8_C( 66), UINT8_C( 50), UINT8_C( 64), UINT8_C(138), UINT8_C(220) },
      { UINT8_C( 99), UINT8_C( 84), UINT8_C(222), UINT8_C( 47), UINT8_C(200), UINT8_C( 94), UINT8_C(243), UINT8_C(243),
        UINT8_C(158), UINT8_C(157), UINT8_C(215), UINT8_C(180), UINT8_C( 39), UINT8_C(  3), UINT8_C(  7), UINT8_C( 49),
        UINT8_C( 61), UINT8_C(111), UINT8_C(106), UINT8_C( 21), UINT8_C(225), UINT8_C( 29), UINT8_C(169), UINT8_C(115),
        UINT8_C(104), UINT8_C( 32), UINT8_C(182), UINT8_C(154), UINT8_C( 73), UINT8_C( 64), UINT8_C(118), UINT8_C(172),
        UINT8_C(170), UINT8_C( 84), UINT8_C(201), UINT8_C( 92), UINT8_C(179), UINT8_C(206), UINT8_C( 79), UINT8_C( 81),
        UINT8_C(107), UINT8_C( 63), UINT8_C(  5), UINT8_C(228), UINT8_C( 42), UINT8_C( 12), UINT8_C(196), UINT8_C(148),
        UINT8_C(123), UINT8_C(103), UINT8_C( 30), UINT8_C( 92), UINT8_C( 76), UINT8_C(114), UINT8_C(179), UINT8_C(180),
        UINT8_C(146), UINT8_C(133), UINT8_C( 79), UINT8_C( 26), UINT8_C( 50), UINT8_C(197), UINT8_C(198), UINT8_C(220) },
      { UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,
        UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
           UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),
        UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,
           UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),
           UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,
           UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
           UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX } },
    { { UINT8_C(124), UINT8_C(142), UINT8_C( 32), UINT8_C(181), UINT8_C(  8), UINT8_C(142), UINT8_C( 27), UINT8_C(166),
        UINT8_C(107), UINT8_C(217), UINT8_C(114), UINT8_C(121), UINT8_C(131), UINT8_C(233), UINT8_C(232), UINT8_C( 54),
        UINT8_C(101), UINT8_C(  4), UINT8_C(188), UINT8_C(183), UINT8_C(128), UINT8_C(228), UINT8_C(100), UINT8_C(173),
        UINT8_C(202), UINT8_C( 50), UINT8_C( 79), UINT8_C( 50), UINT8_C(124), UINT8_C(128), UINT8_C(191), UINT8_C(248),
        UINT8_C( 14), UINT8_C(223), UINT8_C(173), UINT8_C( 23), UINT8_C(109), UINT8_C(200), UINT8_C(189), UINT8_C(216),
        UINT8_C(162), UINT8_C( 47), UINT8_C( 82), UINT8_C( 37), UINT8_C( 24), UINT8_C( 58), UINT8_C( 91), UINT8_C(126),
        UINT8_C( 62), UINT8_C( 23), UINT8_C( 53), UINT8_C(191), UINT8_C(252), UINT8_C(154), UINT8_C(108), UINT8_C(198),
        UINT8_C(204), UINT8_C(187), UINT8_C(248), UINT8_C( 72), UINT8_C( 59), UINT8_C(183), UINT8_C( 64), UINT8_C( 74) },
      { UINT8_C(150), UINT8_C(237), UINT8_C( 97), UINT8_C(181), UINT8_C(182), UINT8_C( 30), UINT8_C( 27), UINT8_C( 88),
        UINT8_C( 77), UINT8_C( 46), UINT8_C(125), UINT8_C(102), UINT8_C(105), UINT8_C(216), UINT8_C(228), UINT8_C(167),
        UINT8_C(240), UINT8_C( 25), UINT8_C(188), UINT8_C(236), UINT8_C(179), UINT8_C(210), UINT8_C(100), UINT8_C(128),
        UINT8_C(141), UINT8_C( 50), UINT8_C(200), UINT8_C(201), UINT8_C( 98), UINT8_C(  9), UINT8_C(191), UINT8_C(248),
        UINT8_C( 14), UINT8_C(116), UINT8_C(252), UINT8_C(172), UINT8_C(146), UINT8_C(217), UINT8_C(  4), UINT8_C(216),
        UINT8_C(  7), UINT8_C(129), UINT8_C( 69), UINT8_C(112), UINT8_C( 90), UINT8_C( 58), UINT8_C( 91), UINT8_C( 74),
        UINT8_C( 67), UINT8_C( 23), UINT8_C( 54), UINT8_C(246), UINT8_C( 81), UINT8_C(232), UINT8_C(118), UINT8_C(222),
        UINT8_C(146), UINT8_C( 63), UINT8_C(167), UINT8_C( 72), UINT8_C( 59), UINT8_C(183), UINT8_C(237), UINT8_C( 62) },
      {    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),
        UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,
           UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),
        UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,
           UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,
        UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),
           UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
        UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0) } },
    { { UINT8_C(119), UINT8_C(138), UINT8_C( 56), UINT8_C(214), UINT8_C(124), UINT8_C( 85), UINT8_C(166), UINT8_C( 83),
        UINT8_C(172), UINT8_C( 65), UINT8_C( 57), UINT8_C( 86), UINT8_C(241), UINT8_C(113), UINT8_C(209), UINT8_C(236),
        UINT8_C(241), UINT8_C(110), UINT8_C( 26), UINT8_C( 49), UINT8_C( 12), UINT8_C( 14), UINT8_C(110), UINT8_C( 81),
        UINT8_C(187), UINT8_C(242), UINT8_C(249), UINT8_C( 16), UINT8_C(250), UINT8_C( 50), UINT8_C(245), UINT8_C(113),
        UINT8_C(189), UINT8_C( 45), UINT8_C( 72), UINT8_C( 57), UINT8_C(130), UINT8_C(238), UINT8_C(140), UINT8_C( 46),
        UINT8_C( 48), UINT8_C(197), UINT8_C(133), UINT8_C( 33), UINT8_C( 54), UINT8_C( 86), UINT8_C( 14), UINT8_C( 39),
        UINT8_C(197), UINT8_C( 40), UINT8_C( 88), UINT8_C(209), UINT8_C( 54), UINT8_C(199), UINT8_C( 34), UINT8_C(242),
        UINT8_C(185), UINT8_C( 28), UINT8_C(  2), UINT8_C(179), UINT8_C( 78), UINT8_C(247), UINT8_C( 36), UINT8_C( 11) },
      { UINT8_C( 36), UINT8_C(108), UINT8_C( 56), UINT8_C(214), UINT8_C(124), UINT8_C(208), UINT8_C(212), UINT8_C(139),
        UINT8_C(172), UINT8_C( 89), UINT8_C(172), UINT8_C( 86), UINT8_C(176), UINT8_C(186), UINT8_C(209), UINT8_C(236),
        UINT8_C(227), UINT8_C( 75), UINT8_C( 70), UINT8_C( 25), UINT8_C( 18), UINT8_C(104), UINT8_C( 11), UINT8_C(203),
        UINT8_C(132), UINT8_C( 13), UINT8_C(126), UINT8_C(211), UINT8_C(250), UINT8_C(163), UINT8_C(222), UINT8_C( 40),
        UINT8_C( 15), UINT8_C( 35), UINT8_C(206), UINT8_C(106), UINT8_C(243), UINT8_C(163), UINT8_C(140), UINT8_C(137),
        UINT8_C(252), UINT8_C(162), UINT8_C( 84), UINT8_C(172), UINT8_C( 54), UINT8_C( 71), UINT8_C( 33), UINT8_C( 63),
        UINT8_C(147), UINT8_C(103), UINT8_C( 89), UINT8_C(209), UINT8_C( 54), UINT8_C(199), UINT8_C( 34), UINT8_C( 84),
        UINT8_C(114), UINT8_C(239), UINT8_C(  2), UINT8_C(118), UINT8_C(146), UINT8_C(  6), UINT8_C(159), UINT8_C(162) },
      { UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
           UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
        UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,
        UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),
        UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,
           UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,
        UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),
        UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX } },
    { { UINT8_C(102), UINT8_C( 27), UINT8_C(104), UINT8_C(132), UINT8_C(154), UINT8_C(120), UINT8_C( 69), UINT8_C( 20),
        UINT8_C( 66), UINT8_C(  7), UINT8_C(207), UINT8_C(230), UINT8_C(  9), UINT8_C( 94), UINT8_C(205), UINT8_C(164),
        UINT8_C(104), UINT8_C(199), UINT8_C( 61), UINT8_C( 92), UINT8_C( 39), UINT8_C( 69), UINT8_C( 43), UINT8_C( 22),
        UINT8_C( 51), UINT8_C(103), UINT8_C(154), UINT8_C(166), UINT8_C(178), UINT8_C(219), UINT8_C( 11), UINT8_C( 25),
        UINT8_C(246), UINT8_C(116), UINT8_C(157), UINT8_C(144), UINT8_C(236), UINT8_C(226), UINT8_C(164), UINT8_C( 46),
        UINT8_C(234), UINT8_C(115), UINT8_C( 21), UINT8_C(243), UINT8_C(210), UINT8_C(226), UINT8_C(152), UINT8_C( 58),
        UINT8_C(169), UINT8_C(213), UINT8_C(150), UINT8_C(209), UINT8_C( 26), UINT8_C(194), UINT8_C(231), UINT8_C( 77),
        UINT8_C( 41), UINT8_C(129), UINT8_C(243), UINT8_C(220), UINT8_C( 92), UINT8_C(254), UINT8_C(245), UINT8_C( 82) },
      { UINT8_C(114), UINT8_C( 27), UINT8_C(227), UINT8_C(132), UINT8_C(116), UINT8_C(135), UINT8_C(141), UINT8_C( 20),
        UINT8_C(251), UINT8_C(162), UINT8_C( 82), UINT8_C(205), UINT8_C(  9), UINT8_C(234), UINT8_C(  7), UINT8_C( 46),
        UINT8_C(191), UINT8_C(157),    UINT8_MAX, UINT8_C(217), UINT8_C( 95), UINT8_C( 69), UINT8_C( 38), UINT8_C(137),
        UINT8_C( 51), UINT8_C( 25), UINT8_C(101), UINT8_C(197), UINT8_C( 23), UINT8_C( 90), UINT8_C( 11), UINT8_C( 25),
        UINT8_C(236), UINT8_C(250), UINT8_C(157), UINT8_C( 96), UINT8_C(236), UINT8_C(118), UINT8_C(191), UINT8_C(125),
        UINT8_C( 25), UINT8_C(115), UINT8_C( 21), UINT8_C(158), UINT8_C(251), UINT8_C( 81), UINT8_C(204), UINT8_C(186),
        UINT8_C(238), UINT8_C(204), UINT8_C(147), UINT8_C( 78), UINT8_C(179), UINT8_C(185), UINT8_C(215), UINT8_C( 27),
        UINT8_C(210), UINT8_C( 60), UINT8_C(243), UINT8_C(233), UINT8_C( 92), UINT8_C(254), UINT8_C(115), UINT8_C(130) },
      {    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
           UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),
           UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,
           UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,
        UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,
        UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,
           UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
           UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX } },
    { { UINT8_C(230), UINT8_C( 79), UINT8_C( 21), UINT8_C( 94), UINT8_C(113), UINT8_C( 19), UINT8_C(137), UINT8_C(206),
        UINT8_C(155), UINT8_C( 97), UINT8_C(184), UINT8_C(122), UINT8_C(160), UINT8_C( 29), UINT8_C(123), UINT8_C(218),
        UINT8_C( 75), UINT8_C( 81), UINT8_C(200), UINT8_C( 25), UINT8_C( 25), UINT8_C( 59), UINT8_C(195), UINT8_C(178),
        UINT8_C( 29), UINT8_C(223), UINT8_C( 20), UINT8_C(225), UINT8_C(239), UINT8_C( 51), UINT8_C(229), UINT8_C(214),
        UINT8_C(130), UINT8_C(250), UINT8_C( 52), UINT8_C(243), UINT8_C( 14), UINT8_C(189), UINT8_C(193), UINT8_C(169),
        UINT8_C( 30), UINT8_C(122), UINT8_C( 35), UINT8_C(191), UINT8_C(151), UINT8_C(158), UINT8_C(153), UINT8_C(227),
        UINT8_C(240), UINT8_C( 97), UINT8_C(252), UINT8_C(  9), UINT8_C(156), UINT8_C(192), UINT8_C(187), UINT8_C(185),
        UINT8_C(159), UINT8_C(207), UINT8_C(155), UINT8_C(143), UINT8_C(  2), UINT8_C(128), UINT8_C(101), UINT8_C(132) },
      { UINT8_C(122), UINT8_C(153), UINT8_C(119), UINT8_C(136), UINT8_C(113), UINT8_C( 57), UINT8_C( 50), UINT8_C(117),
        UINT8_C(179), UINT8_C( 85), UINT8_C( 52), UINT8_C(122), UINT8_C(244), UINT8_C(206), UINT8_C( 45), UINT8_C(228),
        UINT8_C( 47), UINT8_C( 42), UINT8_C(237), UINT8_C(204), UINT8_C(234), UINT8_C(168), UINT8_C(195), UINT8_C(137),
        UINT8_C(119), UINT8_C( 32), UINT8_C( 24), UINT8_C(225), UINT8_C(160), UINT8_C( 51), UINT8_C(254), UINT8_C(214),
        UINT8_C( 23), UINT8_C(118), UINT8_C(163), UINT8_C(110), UINT8_C(175), UINT8_C(189), UINT8_C(227), UINT8_C( 98),
        UINT8_C( 43), UINT8_C(122), UINT8_C(172), UINT8_C( 31), UINT8_C(230), UINT8_C(218), UINT8_C(  3), UINT8_C( 21),
        UINT8_C(240), UINT8_C(240), UINT8_C(225), UINT8_C(238), UINT8_C(152), UINT8_C(103), UINT8_C(119), UINT8_C(185),
        UINT8_C(135), UINT8_C(144), UINT8_C(155), UINT8_C( 40), UINT8_C( 13), UINT8_C(136), UINT8_C( 67), UINT8_C(132) },
      { UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),
           UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,
        UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),
           UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
        UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),
           UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),
           UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,
        UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX } },
    { { UINT8_C( 29), UINT8_C(112), UINT8_C( 67), UINT8_C(230), UINT8_C(220), UINT8_C(145), UINT8_C( 62), UINT8_C(  4),
        UINT8_C(229), UINT8_C(  9), UINT8_C(193), UINT8_C( 66), UINT8_C( 94), UINT8_C( 23), UINT8_C(152), UINT8_C( 30),
        UINT8_C(245), UINT8_C(127), UINT8_C(176), UINT8_C(210), UINT8_C(  7), UINT8_C(156), UINT8_C( 62), UINT8_C(184),
        UINT8_C(  9), UINT8_C( 71), UINT8_C( 28), UINT8_C( 58), UINT8_C( 16), UINT8_C( 47), UINT8_C( 23), UINT8_C( 45),
        UINT8_C(160), UINT8_C( 90), UINT8_C( 20), UINT8_C(124), UINT8_C(236), UINT8_C( 82), UINT8_C(128), UINT8_C(209),
        UINT8_C( 91), UINT8_C( 65), UINT8_C( 20), UINT8_C(186), UINT8_C( 89), UINT8_C(172), UINT8_C(216), UINT8_C( 78),
        UINT8_C( 44), UINT8_C(137), UINT8_C( 33), UINT8_C( 51), UINT8_C( 37), UINT8_C( 95), UINT8_C(235), UINT8_C( 46),
        UINT8_C(166), UINT8_C(  7), UINT8_C(104), UINT8_C(183), UINT8_C( 55), UINT8_C(127), UINT8_C(228), UINT8_C(215) },
      { UINT8_C(218), UINT8_C(248), UINT8_C( 83), UINT8_C(198), UINT8_C( 74), UINT8_C(212), UINT8_C( 62), UINT8_C(166),
        UINT8_C( 21), UINT8_C(171), UINT8_C( 96), UINT8_C(110), UINT8_C( 94), UINT8_C( 23), UINT8_C(189), UINT8_C(132),
        UINT8_C(193), UINT8_C(222), UINT8_C(183), UINT8_C(210), UINT8_C(  7), UINT8_C(162), UINT8_C( 20), UINT8_C(228),
        UINT8_C(170), UINT8_C(125), UINT8_C(155), UINT8_C( 58), UINT8_C(252), UINT8_C(127), UINT8_C(184), UINT8_C(214),
        UINT8_C(120), UINT8_C( 11), UINT8_C(156), UINT8_C(194), UINT8_C(223), UINT8_C( 52), UINT8_C(128), UINT8_C(245),
        UINT8_C(223), UINT8_C(200), UINT8_C( 99), UINT8_C( 55), UINT8_C(  1), UINT8_C( 32), UINT8_C(187), UINT8_C(194),
        UINT8_C(254), UINT8_C(114), UINT8_C(169), UINT8_C( 60), UINT8_C( 37), UINT8_C( 95), UINT8_C(235), UINT8_C(191),
        UINT8_C( 58), UINT8_C(187), UINT8_C(160), UINT8_C( 55), UINT8_C( 58), UINT8_C(127), UINT8_C(228), UINT8_C(178) },
      {    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
        UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
        UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,
           UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
        UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,
           UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,
           UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
        UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0) } },
    { { UINT8_C(188), UINT8_C(250), UINT8_C( 21), UINT8_C(205), UINT8_C(199), UINT8_C(169), UINT8_C(132), UINT8_C( 48),
        UINT8_C( 51), UINT8_C(226), UINT8_C( 85), UINT8_C(109), UINT8_C(169), UINT8_C( 53), UINT8_C(202), UINT8_C(131),
        UINT8_C( 11), UINT8_C( 95), UINT8_C( 45), UINT8_C(247), UINT8_C(235), UINT8_C(226), UINT8_C(181), UINT8_C( 14),
        UINT8_C(216), UINT8_C(127), UINT8_C( 32), UINT8_C( 29), UINT8_C(  8), UINT8_C(132), UINT8_C( 91), UINT8_C(196),
        UINT8_C(126), UINT8_C(112), UINT8_C(145), UINT8_C( 70), UINT8_C( 25), UINT8_C( 21), UINT8_C(118), UINT8_C( 76),
        UINT8_C(247), UINT8_C(204), UINT8_C(185), UINT8_C(160), UINT8_C(  1), UINT8_C(131), UINT8_C( 36), UINT8_C( 12),
        UINT8_C(226), UINT8_C( 81), UINT8_C(  3), UINT8_C(205), UINT8_C( 51), UINT8_C(185), UINT8_C(219), UINT8_C( 11),
        UINT8_C( 56), UINT8_C(251), UINT8_C( 40), UINT8_C( 64), UINT8_C(128), UINT8_C(131), UINT8_C(  4), UINT8_C(254) },
      { UINT8_C(243), UINT8_C(149), UINT8_C( 21), UINT8_C( 13), UINT8_C(170), UINT8_C(169), UINT8_C( 89), UINT8_C(161),
        UINT8_C(135), UINT8_C( 19), UINT8_C( 66), UINT8_C(136), UINT8_C(150), UINT8_C( 53), UINT8_C(202), UINT8_C(131),
        UINT8_C(183), UINT8_C(151), UINT8_C( 70), UINT8_C(235), UINT8_C( 80), UINT8_C( 34), UINT8_C(246), UINT8_C(137),
        UINT8_C( 29), UINT8_C(127), UINT8_C( 32), UINT8_C(157), UINT8_C(162), UINT8_C(132), UINT8_C( 91), UINT8_C(150),
        UINT8_C( 99), UINT8_C(224), UINT8_C(145), UINT8_C( 14), UINT8_C(155), UINT8_C(252), UINT8_C(175), UINT8_C( 34),
        UINT8_C( 15), UINT8_C(241), UINT8_C(170), UINT8_C(166), UINT8_C( 87), UINT8_C( 62), UINT8_C( 31), UINT8_C( 12),
        UINT8_C(214), UINT8_C(101), UINT8_C(250), UINT8_C(205), UINT8_C(135), UINT8_C(240), UINT8_C(175), UINT8_C(165),
        UINT8_C( 15), UINT8_C(121), UINT8_C( 40), UINT8_C(178), UINT8_C( 71), UINT8_C(222), UINT8_C(  4), UINT8_C(170) },
      {    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,
           UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
           UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,
        UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),
        UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),
        UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,
        UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,
        UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i a = simde_mm512_loadu_epi8(test_vec[i].a);
    simde__m512i b = simde_mm512_loadu_epi8(test_vec[i].b);
    simde__m512i r = simde_x_mm512_cmple_epu8(a, b);
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
    simde__m512i r = simde_x_mm512_cmple_epu8(a, b);

    simde_test_x86_write_u8x64(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_u8x64(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_u8x64(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_cmple_epu8_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const uint8_t a[64];
    const uint8_t b[64];
    const simde__mmask64 r;
  } test_vec[] = {
    { { UINT8_C( 43), UINT8_C(  7), UINT8_C(193), UINT8_C( 35), UINT8_C(243), UINT8_C( 97), UINT8_C(209), UINT8_C( 76),
        UINT8_C(  8), UINT8_C( 34), UINT8_C(246), UINT8_C( 40), UINT8_C(167), UINT8_C(232), UINT8_C(218), UINT8_C( 98),
        UINT8_C(109), UINT8_C( 62), UINT8_C( 67), UINT8_C(138), UINT8_C(103), UINT8_C(164), UINT8_C(134), UINT8_C(201),
        UINT8_C( 12), UINT8_C(121), UINT8_C(169), UINT8_C(180), UINT8_C(189), UINT8_C( 48), UINT8_C(231), UINT8_C(232),
        UINT8_C( 55), UINT8_C(168), UINT8_C( 11), UINT8_C( 42), UINT8_C(  9), UINT8_C(221), UINT8_C(119), UINT8_C( 18),
           UINT8_MAX, UINT8_C(109), UINT8_C( 58), UINT8_C(166), UINT8_C( 85), UINT8_C( 20), UINT8_C(  8), UINT8_C(194),
        UINT8_C( 83), UINT8_C( 75), UINT8_C( 77), UINT8_C(186), UINT8_C(239), UINT8_C(211), UINT8_C(131), UINT8_C(252),
        UINT8_C( 76), UINT8_C( 44), UINT8_C(176), UINT8_C(  9), UINT8_C( 92), UINT8_C(152), UINT8_C(241), UINT8_C(148) },
      { UINT8_C( 64), UINT8_C(253), UINT8_C(190), UINT8_C( 74), UINT8_C(243), UINT8_C( 53), UINT8_C( 92), UINT8_C(217),
        UINT8_C(  8), UINT8_C(150), UINT8_C(128), UINT8_C(248), UINT8_C(167), UINT8_C(136), UINT8_C(187), UINT8_C(254),
        UINT8_C(212), UINT8_C(  8), UINT8_C(184), UINT8_C(195), UINT8_C(103), UINT8_C( 59), UINT8_C(134), UINT8_C( 39),
        UINT8_C(104), UINT8_C(112), UINT8_C( 49), UINT8_C(196), UINT8_C(189), UINT8_C( 48), UINT8_C( 88), UINT8_C( 72),
        UINT8_C( 31), UINT8_C( 23), UINT8_C( 11), UINT8_C(249), UINT8_C( 76), UINT8_C(238), UINT8_C(211), UINT8_C(239),
        UINT8_C(133), UINT8_C(109), UINT8_C(232), UINT8_C( 48), UINT8_C(219), UINT8_C( 20), UINT8_C( 46), UINT8_C(194),
        UINT8_C(171), UINT8_C( 75), UINT8_C(115), UINT8_C(134), UINT8_C( 33), UINT8_C( 50), UINT8_C(173), UINT8_C(137),
        UINT8_C( 76), UINT8_C(222), UINT8_C( 78), UINT8_C(170), UINT8_C( 92), UINT8_C(166), UINT8_C(243), UINT8_C( 32) },
      UINT64_C( 8883340353166220187) },
    { { UINT8_C(175), UINT8_C(247), UINT8_C(160), UINT8_C( 25), UINT8_C(148), UINT8_C( 67), UINT8_C(195), UINT8_C( 19),
        UINT8_C( 15), UINT8_C(137), UINT8_C( 23), UINT8_C( 50), UINT8_C( 25), UINT8_C( 74), UINT8_C(146), UINT8_C(232),
        UINT8_C( 50), UINT8_C( 80), UINT8_C( 39), UINT8_C(126), UINT8_C(247), UINT8_C(121), UINT8_C( 11), UINT8_C(211),
        UINT8_C(136), UINT8_C(218), UINT8_C(140), UINT8_C( 72), UINT8_C( 13), UINT8_C(223), UINT8_C( 62), UINT8_C(188),
        UINT8_C(214), UINT8_C(222), UINT8_C(214), UINT8_C(107), UINT8_C( 33), UINT8_C(153), UINT8_C(126), UINT8_C( 48),
        UINT8_C( 34), UINT8_C(149), UINT8_C( 98), UINT8_C( 60), UINT8_C(223), UINT8_C(244), UINT8_C( 36), UINT8_C( 18),
        UINT8_C( 69), UINT8_C( 75), UINT8_C(144), UINT8_C( 60), UINT8_C(196), UINT8_C(155), UINT8_C( 15), UINT8_C( 76),
        UINT8_C(117), UINT8_C(156), UINT8_C(149), UINT8_C(130), UINT8_C(123), UINT8_C(211), UINT8_C( 63), UINT8_C( 82) },
      { UINT8_C(178), UINT8_C( 21), UINT8_C(160), UINT8_C(211), UINT8_C(174), UINT8_C( 59), UINT8_C(  4), UINT8_C(209),
        UINT8_C(209), UINT8_C(137), UINT8_C( 13), UINT8_C(176), UINT8_C( 91), UINT8_C( 49), UINT8_C(194), UINT8_C(160),
        UINT8_C(124), UINT8_C( 80), UINT8_C(220), UINT8_C( 64), UINT8_C(237), UINT8_C(235), UINT8_C(140), UINT8_C(211),
        UINT8_C(135), UINT8_C( 33), UINT8_C(229), UINT8_C( 72), UINT8_C(245), UINT8_C( 36), UINT8_C( 62), UINT8_C(167),
        UINT8_C( 57), UINT8_C(222), UINT8_C(122), UINT8_C(232), UINT8_C( 77), UINT8_C(126), UINT8_C(126), UINT8_C( 48),
        UINT8_C(229), UINT8_C(198), UINT8_C(207), UINT8_C( 60), UINT8_C(247), UINT8_C(145), UINT8_C(224), UINT8_C(115),
        UINT8_C(228), UINT8_C(188), UINT8_C(179), UINT8_C(209), UINT8_C(196), UINT8_C( 63), UINT8_C( 52), UINT8_C( 47),
        UINT8_C(117), UINT8_C( 26), UINT8_C( 50), UINT8_C( 86), UINT8_C( 62), UINT8_C(135), UINT8_C(253), UINT8_C( 82) },
      UINT64_C(13934101901062134685) },
    { { UINT8_C(106), UINT8_C(156), UINT8_C( 17), UINT8_C(  3), UINT8_C(103), UINT8_C( 73), UINT8_C(123), UINT8_C(  6),
        UINT8_C(156), UINT8_C(201), UINT8_C( 11), UINT8_C(234), UINT8_C( 96), UINT8_C( 89), UINT8_C(239), UINT8_C(243),
        UINT8_C(194), UINT8_C( 82), UINT8_C(193), UINT8_C(122), UINT8_C( 67), UINT8_C( 44), UINT8_C(156), UINT8_C(244),
        UINT8_C(138), UINT8_C(102), UINT8_C(235), UINT8_C(215), UINT8_C( 80), UINT8_C(193), UINT8_C(139), UINT8_C(186),
        UINT8_C( 94), UINT8_C(156), UINT8_C(189), UINT8_C(197), UINT8_C(229), UINT8_C( 56), UINT8_C(204), UINT8_C(129),
        UINT8_C(  1), UINT8_C(215), UINT8_C(107), UINT8_C( 97), UINT8_C( 48), UINT8_C( 90), UINT8_C( 84), UINT8_C(242),
        UINT8_C(172), UINT8_C( 22), UINT8_C(108), UINT8_C(240), UINT8_C( 66), UINT8_C(  9), UINT8_C(228), UINT8_C(204),
        UINT8_C(111), UINT8_C(207), UINT8_C(163), UINT8_C(192), UINT8_C(144), UINT8_C( 46), UINT8_C(122), UINT8_C(238) },
      { UINT8_C(202), UINT8_C(156), UINT8_C(180), UINT8_C(175), UINT8_C(112), UINT8_C( 73), UINT8_C( 48), UINT8_C(114),
        UINT8_C( 87), UINT8_C(201), UINT8_C(211), UINT8_C(135), UINT8_C(245), UINT8_C( 40), UINT8_C(121), UINT8_C(162),
        UINT8_C(194), UINT8_C(229), UINT8_C(146), UINT8_C(122), UINT8_C( 67), UINT8_C(118), UINT8_C( 77), UINT8_C( 94),
        UINT8_C( 69), UINT8_C(240), UINT8_C(235), UINT8_C(213), UINT8_C( 80), UINT8_C(152), UINT8_C(196), UINT8_C(233),
        UINT8_C(208), UINT8_C(120), UINT8_C(153), UINT8_C( 65), UINT8_C(248), UINT8_C( 56), UINT8_C(179), UINT8_C( 79),
        UINT8_C(  1), UINT8_C(215), UINT8_C(214), UINT8_C( 90), UINT8_C(174), UINT8_C( 90), UINT8_C(252), UINT8_C(236),
        UINT8_C( 52), UINT8_C(142), UINT8_C(109), UINT8_C( 35), UINT8_C( 66), UINT8_C(  9), UINT8_C(129), UINT8_C( 73),
        UINT8_C(170), UINT8_C(159), UINT8_C( 31), UINT8_C(201), UINT8_C( 55), UINT8_C(227), UINT8_C(122), UINT8_C(  8) },
      UINT64_C( 7581378078656108223) },
    { { UINT8_C(242), UINT8_C( 70), UINT8_C(250), UINT8_C(181), UINT8_C( 70), UINT8_C( 66), UINT8_C(250), UINT8_C(190),
        UINT8_C( 94), UINT8_C(113), UINT8_C(253), UINT8_C( 76), UINT8_C(  5), UINT8_C( 56), UINT8_C(154), UINT8_C( 35),
        UINT8_C(145), UINT8_C( 77), UINT8_C(134), UINT8_C(137), UINT8_C(173), UINT8_C(216), UINT8_C(192), UINT8_C(219),
        UINT8_C(227), UINT8_C(109), UINT8_C(184), UINT8_C( 89), UINT8_C(152), UINT8_C(161), UINT8_C(134), UINT8_C(138),
        UINT8_C(231), UINT8_C(129), UINT8_C( 63), UINT8_C( 46), UINT8_C(195), UINT8_C( 58), UINT8_C(236), UINT8_C( 33),
        UINT8_C(171), UINT8_C(234), UINT8_C(110), UINT8_C(176), UINT8_C( 34), UINT8_C(  8), UINT8_C(211), UINT8_C(179),
        UINT8_C( 85), UINT8_C( 90), UINT8_C( 60), UINT8_C(  3), UINT8_C( 50), UINT8_C(253), UINT8_C(222), UINT8_C( 21),
        UINT8_C(106), UINT8_C(150), UINT8_C(110), UINT8_C(  3), UINT8_C( 55), UINT8_C(245), UINT8_C(141), UINT8_C( 31) },
      { UINT8_C(118), UINT8_C(205), UINT8_C( 77), UINT8_C( 57), UINT8_C( 70), UINT8_C( 57), UINT8_C(250), UINT8_C(178),
        UINT8_C( 35), UINT8_C(113), UINT8_C( 98), UINT8_C( 69), UINT8_C(209), UINT8_C( 53), UINT8_C(154), UINT8_C( 38),
        UINT8_C(143), UINT8_C( 77), UINT8_C( 41), UINT8_C(194), UINT8_C( 50), UINT8_C(  7), UINT8_C(215), UINT8_C(156),
        UINT8_C(158), UINT8_C( 70), UINT8_C(159), UINT8_C(213), UINT8_C( 59), UINT8_C( 45), UINT8_C(134), UINT8_C(138),
        UINT8_C(250), UINT8_C(129), UINT8_C(234), UINT8_C(  1), UINT8_C(123), UINT8_C( 68), UINT8_C(179), UINT8_C(158),
        UINT8_C( 13), UINT8_C( 21), UINT8_C(110), UINT8_C(176), UINT8_C( 74), UINT8_C(  8), UINT8_C(  4), UINT8_C(218),
        UINT8_C( 85), UINT8_C( 90), UINT8_C(156), UINT8_C( 67), UINT8_C( 53), UINT8_C(115), UINT8_C(222), UINT8_C( 21),
        UINT8_C(106), UINT8_C(127), UINT8_C(169), UINT8_C(244), UINT8_C(172), UINT8_C(157), UINT8_C(165), UINT8_C(166) },
      UINT64_C(15987704630994457170) },
    { { UINT8_C(126), UINT8_C( 79), UINT8_C(218), UINT8_C( 65), UINT8_C(194), UINT8_C( 21), UINT8_C(115), UINT8_C( 17),
        UINT8_C( 16), UINT8_C( 95), UINT8_C( 25), UINT8_C(206), UINT8_C(223), UINT8_C(235), UINT8_C(125), UINT8_C(143),
        UINT8_C(204), UINT8_C( 84), UINT8_C(226), UINT8_C(154), UINT8_C( 37), UINT8_C(147), UINT8_C(214), UINT8_C(153),
        UINT8_C(149), UINT8_C( 44), UINT8_C( 79), UINT8_C(142), UINT8_C( 67), UINT8_C( 36), UINT8_C( 13), UINT8_C(193),
        UINT8_C(116), UINT8_C(231), UINT8_C(  2), UINT8_C( 54), UINT8_C(253), UINT8_C(117), UINT8_C( 71), UINT8_C( 13),
        UINT8_C(212), UINT8_C( 96), UINT8_C(219), UINT8_C(179), UINT8_C( 75), UINT8_C( 88), UINT8_C( 66), UINT8_C( 23),
        UINT8_C(172), UINT8_C( 37), UINT8_C(178), UINT8_C(209), UINT8_C(184), UINT8_C(136), UINT8_C(107), UINT8_C( 77),
        UINT8_C(181), UINT8_C(186), UINT8_C(219), UINT8_C(248), UINT8_C(222), UINT8_C(232), UINT8_C(185), UINT8_C( 82) },
      { UINT8_C(208), UINT8_C(188), UINT8_C(218), UINT8_C(205), UINT8_C( 49), UINT8_C(207), UINT8_C(115), UINT8_C(  6),
        UINT8_C( 47), UINT8_C( 95), UINT8_C( 25), UINT8_C(206), UINT8_C( 13), UINT8_C(252), UINT8_C(146), UINT8_C(186),
        UINT8_C( 33), UINT8_C( 84), UINT8_C(139), UINT8_C(154), UINT8_C( 37), UINT8_C(147), UINT8_C(214), UINT8_C(130),
        UINT8_C(149), UINT8_C(  1), UINT8_C(122), UINT8_C(143), UINT8_C(233), UINT8_C( 51), UINT8_C(225), UINT8_C(193),
        UINT8_C(116), UINT8_C(106), UINT8_C(  2), UINT8_C( 54), UINT8_C( 57), UINT8_C(117), UINT8_C( 39), UINT8_C(105),
        UINT8_C( 21), UINT8_C(224), UINT8_C(228), UINT8_C(179), UINT8_C(220), UINT8_C(118), UINT8_C(221), UINT8_C(253),
        UINT8_C(187), UINT8_C( 37), UINT8_C(178), UINT8_C(136), UINT8_C(184), UINT8_C(136), UINT8_C( 10), UINT8_C( 77),
        UINT8_C(253), UINT8_C(132), UINT8_C(158), UINT8_C(231), UINT8_C(183), UINT8_C(128), UINT8_C(160), UINT8_C( 82) },
      UINT64_C( 9347219574866243439) },
    { { UINT8_C(160), UINT8_C( 73), UINT8_C(164), UINT8_C(110), UINT8_C(118), UINT8_C(241), UINT8_C( 11), UINT8_C( 19),
        UINT8_C(254), UINT8_C( 84), UINT8_C(151), UINT8_C(168), UINT8_C( 70), UINT8_C(189), UINT8_C( 87), UINT8_C(185),
        UINT8_C( 13), UINT8_C(107), UINT8_C(168), UINT8_C(145), UINT8_C(243), UINT8_C( 17), UINT8_C(205), UINT8_C(142),
        UINT8_C(219), UINT8_C(120), UINT8_C(187), UINT8_C(166), UINT8_C( 58), UINT8_C(100), UINT8_C(154), UINT8_C(219),
        UINT8_C(174), UINT8_C( 62), UINT8_C( 73), UINT8_C( 36), UINT8_C( 47), UINT8_C( 84), UINT8_C( 55), UINT8_C( 45),
        UINT8_C(168), UINT8_C(206), UINT8_C(213), UINT8_C(238), UINT8_C(139), UINT8_C( 45), UINT8_C(167), UINT8_C(152),
        UINT8_C(152), UINT8_C( 79), UINT8_C( 41), UINT8_C(140), UINT8_C( 96), UINT8_C(246), UINT8_C( 26), UINT8_C( 59),
        UINT8_C(110), UINT8_C(213), UINT8_C(226), UINT8_C(169), UINT8_C( 57), UINT8_C(124), UINT8_C(132), UINT8_C(231) },
      { UINT8_C(160), UINT8_C(205), UINT8_C( 11), UINT8_C(234), UINT8_C( 33), UINT8_C(241), UINT8_C( 24), UINT8_C(201),
        UINT8_C( 16), UINT8_C( 84), UINT8_C(151), UINT8_C(168), UINT8_C( 70), UINT8_C( 95), UINT8_C( 51), UINT8_C(179),
        UINT8_C(174), UINT8_C( 92), UINT8_C( 63), UINT8_C(145), UINT8_C( 82), UINT8_C( 89), UINT8_C( 74), UINT8_C(193),
        UINT8_C(219), UINT8_C( 44), UINT8_C(187), UINT8_C(166), UINT8_C( 58), UINT8_C(238), UINT8_C(154), UINT8_C(100),
        UINT8_C(174), UINT8_C( 90), UINT8_C( 78), UINT8_C(220), UINT8_C( 47), UINT8_C(102), UINT8_C( 55), UINT8_C(173),
        UINT8_C( 84), UINT8_C( 92), UINT8_C( 73), UINT8_C(110), UINT8_C(187), UINT8_C( 45), UINT8_C( 33), UINT8_C(106),
        UINT8_C(217), UINT8_C( 79), UINT8_C(121), UINT8_C( 43), UINT8_C(185), UINT8_C(195), UINT8_C(236), UINT8_C(231),
        UINT8_C(240), UINT8_C( 86), UINT8_C( 79), UINT8_C(169), UINT8_C( 68), UINT8_C(158), UINT8_C(253),    UINT8_MAX },
      UINT64_C(18002911909319876331) },
    { { UINT8_C(186), UINT8_C( 11), UINT8_C(177), UINT8_C(170), UINT8_C( 97), UINT8_C(122), UINT8_C(119), UINT8_C( 66),
        UINT8_C(183), UINT8_C(220), UINT8_C( 44), UINT8_C(138), UINT8_C( 68), UINT8_C(248), UINT8_C( 83), UINT8_C( 40),
        UINT8_C(208), UINT8_C(205), UINT8_C( 74), UINT8_C(162), UINT8_C(222), UINT8_C(156), UINT8_C(196), UINT8_C(213),
        UINT8_C(181), UINT8_C(123), UINT8_C( 81), UINT8_C(148), UINT8_C(197), UINT8_C( 74), UINT8_C(131), UINT8_C(127),
        UINT8_C( 86), UINT8_C( 52), UINT8_C( 41), UINT8_C(183), UINT8_C(174), UINT8_C(160), UINT8_C(249), UINT8_C(101),
        UINT8_C(125), UINT8_C( 38), UINT8_C(239), UINT8_C(193), UINT8_C( 30), UINT8_C( 67), UINT8_C(233), UINT8_C(238),
        UINT8_C( 16), UINT8_C( 52), UINT8_C(145), UINT8_C(238), UINT8_C(208), UINT8_C( 85), UINT8_C(195), UINT8_C(133),
        UINT8_C(208), UINT8_C( 21), UINT8_C( 25), UINT8_C(150), UINT8_C( 95), UINT8_C(156), UINT8_C( 21), UINT8_C(181) },
      { UINT8_C(186), UINT8_C( 11), UINT8_C(177), UINT8_C(127), UINT8_C(223), UINT8_C(102), UINT8_C(229), UINT8_C( 92),
        UINT8_C(140), UINT8_C(212), UINT8_C( 30), UINT8_C(170), UINT8_C( 23), UINT8_C(  7), UINT8_C( 83), UINT8_C( 40),
        UINT8_C(208), UINT8_C( 41), UINT8_C( 21), UINT8_C( 11), UINT8_C(127), UINT8_C(217), UINT8_C(145), UINT8_C(213),
        UINT8_C(238), UINT8_C(170), UINT8_C(229), UINT8_C( 77), UINT8_C( 71), UINT8_C(251), UINT8_C(  3), UINT8_C( 24),
        UINT8_C( 58), UINT8_C(111), UINT8_C( 41), UINT8_C(183), UINT8_C(213), UINT8_C(160), UINT8_C(118), UINT8_C( 97),
        UINT8_C( 81), UINT8_C( 38), UINT8_C( 11), UINT8_C(104), UINT8_C(155), UINT8_C(164), UINT8_C(144), UINT8_C(215),
        UINT8_C(205), UINT8_C(165), UINT8_C(226), UINT8_C( 76), UINT8_C(208), UINT8_C( 85), UINT8_C(156), UINT8_C(108),
        UINT8_C( 30), UINT8_C(129), UINT8_C(186), UINT8_C(101), UINT8_C(124), UINT8_C(189), UINT8_C(125), UINT8_C(181) },
      UINT64_C(17741704499583633623) },
    { { UINT8_C(169), UINT8_C( 94), UINT8_C(136), UINT8_C( 60), UINT8_C(210), UINT8_C(178), UINT8_C(170), UINT8_C(181),
        UINT8_C( 39), UINT8_C(141), UINT8_C(171), UINT8_C(118), UINT8_C(188), UINT8_C(130), UINT8_C( 69), UINT8_C( 27),
        UINT8_C(133), UINT8_C( 18), UINT8_C( 28), UINT8_C( 82), UINT8_C( 75), UINT8_C(221), UINT8_C(105), UINT8_C(168),
        UINT8_C(196), UINT8_C( 71), UINT8_C(232), UINT8_C( 78), UINT8_C(162), UINT8_C( 54), UINT8_C(142), UINT8_C( 75),
        UINT8_C(148), UINT8_C( 23), UINT8_C(136), UINT8_C(103), UINT8_C(201), UINT8_C( 50), UINT8_C( 28), UINT8_C(240),
        UINT8_C(191), UINT8_C(200), UINT8_C(102), UINT8_C(123), UINT8_C( 74), UINT8_C(171), UINT8_C(150), UINT8_C(207),
        UINT8_C(190), UINT8_C(178), UINT8_C( 33), UINT8_C(  9), UINT8_C(144), UINT8_C(138), UINT8_C(177), UINT8_C( 84),
        UINT8_C(209), UINT8_C(153), UINT8_C(162), UINT8_C(116), UINT8_C(207), UINT8_C( 49), UINT8_C(191), UINT8_C(100) },
      { UINT8_C(169), UINT8_C( 71), UINT8_C(203), UINT8_C( 60), UINT8_C(121), UINT8_C(178), UINT8_C(  2), UINT8_C( 56),
        UINT8_C( 39), UINT8_C(141), UINT8_C(171), UINT8_C(249), UINT8_C( 20), UINT8_C( 74), UINT8_C(201), UINT8_C(210),
        UINT8_C(253), UINT8_C(234), UINT8_C( 28), UINT8_C( 82), UINT8_C(117), UINT8_C(221), UINT8_C(105), UINT8_C(168),
        UINT8_C( 38), UINT8_C(132), UINT8_C(186), UINT8_C(245), UINT8_C(181), UINT8_C(122), UINT8_C( 89), UINT8_C(253),
        UINT8_C(148), UINT8_C( 36), UINT8_C( 14), UINT8_C( 59), UINT8_C( 12), UINT8_C( 16), UINT8_C(115), UINT8_C(187),
        UINT8_C(121), UINT8_C( 39), UINT8_C(181), UINT8_C(123), UINT8_C(114), UINT8_C(126), UINT8_C( 95), UINT8_C(111),
        UINT8_C(104), UINT8_C(178), UINT8_C(252), UINT8_C(221), UINT8_C(144), UINT8_C(138), UINT8_C( 36), UINT8_C(236),
        UINT8_C( 97), UINT8_C(153), UINT8_C(226), UINT8_C(116), UINT8_C( 88), UINT8_C( 49), UINT8_C( 19), UINT8_C( 26) },
      UINT64_C( 3368160648545423149) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i a = simde_mm512_loadu_epi8(test_vec[i].a);
    simde__m512i b = simde_mm512_loadu_epi8(test_vec[i].b);
    simde__mmask64 r = simde_mm512_cmple_epu8_mask(a, b);
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
    simde__mmask64 r = simde_mm512_cmple_epu8_mask(a, b);

    simde_test_x86_write_u8x64(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_u8x64(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask64(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_mask_cmple_epu8_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask64 k;
    const uint8_t a[64];
    const uint8_t b[64];
    const simde__mmask64 r;
  } test_vec[] = {
    { UINT64_C(10517814227609971634),
      { UINT8_C( 19), UINT8_C(108), UINT8_C( 20), UINT8_C( 70), UINT8_C(  2), UINT8_C( 74), UINT8_C(105), UINT8_C(116),
        UINT8_C(185), UINT8_C(238), UINT8_C( 64), UINT8_C(191), UINT8_C( 68), UINT8_C(208), UINT8_C(150), UINT8_C(103),
        UINT8_C(  0), UINT8_C(  6), UINT8_C( 52), UINT8_C(244), UINT8_C(250), UINT8_C( 14), UINT8_C(140), UINT8_C( 84),
        UINT8_C( 10), UINT8_C( 31), UINT8_C( 81), UINT8_C( 60), UINT8_C(199), UINT8_C( 79), UINT8_C(198), UINT8_C(218),
        UINT8_C(188), UINT8_C(218), UINT8_C( 32), UINT8_C(190), UINT8_C( 37), UINT8_C(137), UINT8_C( 50), UINT8_C(222),
        UINT8_C(119), UINT8_C(114), UINT8_C(157), UINT8_C(187), UINT8_C( 66), UINT8_C( 51), UINT8_C( 34), UINT8_C( 66),
        UINT8_C( 57), UINT8_C( 87), UINT8_C( 55), UINT8_C( 51), UINT8_C(101), UINT8_C(195), UINT8_C(136), UINT8_C(111),
        UINT8_C(226), UINT8_C(217), UINT8_C(171), UINT8_C(169), UINT8_C( 40), UINT8_C(113), UINT8_C(132), UINT8_C(228) },
      { UINT8_C( 75), UINT8_C(164), UINT8_C(162), UINT8_C(112), UINT8_C(  2), UINT8_C(212), UINT8_C( 78), UINT8_C(116),
        UINT8_C( 71), UINT8_C(235), UINT8_C( 64), UINT8_C(137), UINT8_C( 31), UINT8_C(208), UINT8_C(204), UINT8_C( 88),
        UINT8_C(  0), UINT8_C(  3), UINT8_C( 52), UINT8_C(244), UINT8_C(250), UINT8_C( 20), UINT8_C(174), UINT8_C( 84),
        UINT8_C(237), UINT8_C( 89), UINT8_C( 81), UINT8_C( 60), UINT8_C(199), UINT8_C(213), UINT8_C(250), UINT8_C( 22),
        UINT8_C(122), UINT8_C(156), UINT8_C(134), UINT8_C(168), UINT8_C( 37), UINT8_C(213), UINT8_C( 77), UINT8_C(184),
        UINT8_C(119), UINT8_C(174), UINT8_C( 65), UINT8_C(223), UINT8_C( 50), UINT8_C( 13), UINT8_C( 56), UINT8_C( 12),
        UINT8_C( 16), UINT8_C(196), UINT8_C( 76), UINT8_C(214), UINT8_C(216), UINT8_C(195), UINT8_C(126), UINT8_C(111),
        UINT8_C( 84), UINT8_C(208), UINT8_C(171), UINT8_C( 30), UINT8_C( 40), UINT8_C(212), UINT8_C(132), UINT8_C( 31) },
      UINT64_C( 1204229460719394994) },
    { UINT64_C(12447505664385860374),
      { UINT8_C(131), UINT8_C(111), UINT8_C(186), UINT8_C(166), UINT8_C(234), UINT8_C(221), UINT8_C(245), UINT8_C(179),
        UINT8_C(208), UINT8_C( 72), UINT8_C(196), UINT8_C( 18), UINT8_C(100), UINT8_C(114), UINT8_C(114), UINT8_C( 36),
        UINT8_C(219), UINT8_C(150), UINT8_C( 91), UINT8_C( 52), UINT8_C(157), UINT8_C(124), UINT8_C( 55), UINT8_C( 80),
        UINT8_C(103), UINT8_C(116), UINT8_C(194), UINT8_C(184), UINT8_C( 61), UINT8_C(184), UINT8_C( 73), UINT8_C(192),
        UINT8_C( 39), UINT8_C(  3), UINT8_C(103), UINT8_C( 17), UINT8_C(225), UINT8_C( 92), UINT8_C(196), UINT8_C(177),
        UINT8_C(165), UINT8_C(137), UINT8_C(195), UINT8_C(  9), UINT8_C(251), UINT8_C( 53), UINT8_C( 45), UINT8_C(215),
        UINT8_C(203), UINT8_C(137), UINT8_C( 11), UINT8_C(105), UINT8_C(  5), UINT8_C( 66), UINT8_C(185), UINT8_C(108),
        UINT8_C(182), UINT8_C(123), UINT8_C( 36), UINT8_C(243), UINT8_C( 52), UINT8_C(109), UINT8_C(180), UINT8_C( 91) },
      { UINT8_C(113), UINT8_C( 27), UINT8_C(109), UINT8_C( 82), UINT8_C(119), UINT8_C(221), UINT8_C(245), UINT8_C( 28),
        UINT8_C(186), UINT8_C( 72), UINT8_C( 38), UINT8_C(182), UINT8_C(252), UINT8_C( 83), UINT8_C(141), UINT8_C(200),
        UINT8_C(220), UINT8_C(152), UINT8_C( 49), UINT8_C(225), UINT8_C(218), UINT8_C(234), UINT8_C( 78), UINT8_C( 80),
        UINT8_C(103), UINT8_C(114), UINT8_C(132), UINT8_C(184), UINT8_C(224), UINT8_C( 56), UINT8_C(245), UINT8_C( 81),
        UINT8_C( 83), UINT8_C( 98), UINT8_C(103), UINT8_C( 17), UINT8_C(147), UINT8_C( 92), UINT8_C(231), UINT8_C(177),
        UINT8_C(109), UINT8_C(137), UINT8_C(  4), UINT8_C(106), UINT8_C( 96), UINT8_C( 53), UINT8_C( 50), UINT8_C( 61),
        UINT8_C( 41), UINT8_C( 99), UINT8_C( 11), UINT8_C(  3), UINT8_C( 77), UINT8_C(108), UINT8_C(147), UINT8_C(108),
        UINT8_C(223), UINT8_C( 23), UINT8_C( 36), UINT8_C(191), UINT8_C( 79), UINT8_C( 65), UINT8_C( 16), UINT8_C(162) },
      UINT64_C( 9562382683651293696) },
    { UINT64_C( 3145669043275100634),
      { UINT8_C(168), UINT8_C(132),    UINT8_MAX, UINT8_C( 71), UINT8_C( 72), UINT8_C(148), UINT8_C(172), UINT8_C( 42),
        UINT8_C(110), UINT8_C( 36), UINT8_C(149), UINT8_C( 34), UINT8_C( 97), UINT8_C(104), UINT8_C(198), UINT8_C(176),
        UINT8_C( 99), UINT8_C(170), UINT8_C( 82), UINT8_C(150), UINT8_C(112), UINT8_C(233), UINT8_C(179), UINT8_C(134),
        UINT8_C(172), UINT8_C( 20), UINT8_C( 64), UINT8_C( 31), UINT8_C(128), UINT8_C(254), UINT8_C(204), UINT8_C( 40),
        UINT8_C(130), UINT8_C(203), UINT8_C(111), UINT8_C(202), UINT8_C( 95), UINT8_C( 27), UINT8_C(244), UINT8_C(205),
        UINT8_C( 63), UINT8_C(137), UINT8_C(239), UINT8_C(160), UINT8_C(242), UINT8_C(181), UINT8_C( 81), UINT8_C( 85),
        UINT8_C( 95), UINT8_C(163), UINT8_C(235), UINT8_C(208), UINT8_C(140), UINT8_C(158), UINT8_C( 86), UINT8_C( 56),
        UINT8_C(178), UINT8_C(150), UINT8_C( 87), UINT8_C( 50), UINT8_C(148), UINT8_C( 35), UINT8_C( 90), UINT8_C( 22) },
      { UINT8_C(238), UINT8_C(201), UINT8_C(225), UINT8_C( 77), UINT8_C(228), UINT8_C(148), UINT8_C( 27), UINT8_C( 42),
        UINT8_C( 95), UINT8_C( 36), UINT8_C(149), UINT8_C( 34), UINT8_C( 97), UINT8_C(104), UINT8_C(166), UINT8_C( 31),
        UINT8_C( 99), UINT8_C(146), UINT8_C(239), UINT8_C( 68), UINT8_C(112), UINT8_C(233), UINT8_C(124), UINT8_C(227),
        UINT8_C(220), UINT8_C(211), UINT8_C( 21), UINT8_C(113), UINT8_C(247), UINT8_C(112), UINT8_C(204), UINT8_C( 40),
        UINT8_C( 57), UINT8_C(104), UINT8_C( 51), UINT8_C( 30), UINT8_C( 62), UINT8_C( 78), UINT8_C( 65), UINT8_C(157),
        UINT8_C( 88), UINT8_C(  5), UINT8_C(238), UINT8_C( 24), UINT8_C( 26), UINT8_C(148), UINT8_C( 56), UINT8_C(210),
        UINT8_C( 38), UINT8_C(163), UINT8_C( 22), UINT8_C( 87), UINT8_C(140), UINT8_C(158), UINT8_C( 86), UINT8_C( 56),
        UINT8_C(102), UINT8_C( 79), UINT8_C(187), UINT8_C( 50), UINT8_C(191), UINT8_C( 66), UINT8_C( 90), UINT8_C( 22) },
      UINT64_C( 2928044545030500506) },
    { UINT64_C( 4515384325820041043),
      { UINT8_C( 44), UINT8_C(181), UINT8_C( 10), UINT8_C( 27), UINT8_C( 14), UINT8_C( 25), UINT8_C(159), UINT8_C(200),
        UINT8_C(173), UINT8_C( 36), UINT8_C(119), UINT8_C(  2), UINT8_C(244), UINT8_C(127), UINT8_C(102), UINT8_C(203),
        UINT8_C( 63), UINT8_C(153), UINT8_C(235), UINT8_C(248), UINT8_C(148),    UINT8_MAX, UINT8_C( 32), UINT8_C(110),
        UINT8_C(240), UINT8_C(122), UINT8_C(127), UINT8_C( 68), UINT8_C( 35), UINT8_C( 38), UINT8_C(111), UINT8_C( 79),
        UINT8_C(219), UINT8_C(122), UINT8_C(107), UINT8_C(233), UINT8_C(147), UINT8_C( 10), UINT8_C(178), UINT8_C( 64),
        UINT8_C( 46), UINT8_C( 41), UINT8_C( 66), UINT8_C( 34), UINT8_C(168), UINT8_C(168), UINT8_C(238), UINT8_C(231),
        UINT8_C( 65), UINT8_C(217), UINT8_C(223), UINT8_C(213), UINT8_C(217),    UINT8_MAX, UINT8_C( 67), UINT8_C(201),
        UINT8_C(122), UINT8_C(195), UINT8_C( 14), UINT8_C(157), UINT8_C(233), UINT8_C(125), UINT8_C(237), UINT8_C(197) },
      { UINT8_C( 44), UINT8_C( 88), UINT8_C(174), UINT8_C(138), UINT8_C( 14), UINT8_C( 96), UINT8_C(159), UINT8_C(144),
        UINT8_C(137), UINT8_C( 36), UINT8_C(178), UINT8_C( 50), UINT8_C(182), UINT8_C(160), UINT8_C( 25), UINT8_C(247),
        UINT8_C( 63), UINT8_C(153), UINT8_C(205), UINT8_C( 83), UINT8_C(148), UINT8_C( 16), UINT8_C( 28), UINT8_C(114),
        UINT8_C(211), UINT8_C( 42), UINT8_C(127), UINT8_C( 68), UINT8_C(168), UINT8_C(253), UINT8_C(111), UINT8_C(159),
        UINT8_C( 85), UINT8_C( 48), UINT8_C( 42), UINT8_C(183), UINT8_C(145), UINT8_C(245), UINT8_C(178), UINT8_C( 64),
        UINT8_C(  2), UINT8_C( 41), UINT8_C( 76), UINT8_C(184), UINT8_C(154), UINT8_C(102), UINT8_C(176), UINT8_C(231),
        UINT8_C( 65), UINT8_C(217), UINT8_C(103), UINT8_C(213), UINT8_C(141), UINT8_C(131), UINT8_C(202), UINT8_C(201),
        UINT8_C(174), UINT8_C(218), UINT8_C( 14), UINT8_C( 86), UINT8_C(215), UINT8_C(125), UINT8_C(237), UINT8_C(197) },
      UINT64_C( 2776906779870791249) },
    { UINT64_C( 7628170816664870389),
      { UINT8_C(174), UINT8_C( 35), UINT8_C(140), UINT8_C(254), UINT8_C(110), UINT8_C(103), UINT8_C( 74), UINT8_C(242),
        UINT8_C( 40), UINT8_C( 32), UINT8_C( 50), UINT8_C(151), UINT8_C(225), UINT8_C(220), UINT8_C(144), UINT8_C(171),
        UINT8_C( 70), UINT8_C(232), UINT8_C( 30), UINT8_C(102), UINT8_C(205), UINT8_C( 10), UINT8_C( 90), UINT8_C( 32),
        UINT8_C(210), UINT8_C( 56), UINT8_C( 13), UINT8_C(240), UINT8_C( 23), UINT8_C(182), UINT8_C( 46), UINT8_C(197),
        UINT8_C(217), UINT8_C(186), UINT8_C(195), UINT8_C( 71), UINT8_C( 34), UINT8_C( 13), UINT8_C( 58), UINT8_C( 74),
        UINT8_C( 45), UINT8_C(108), UINT8_C(225), UINT8_C( 14), UINT8_C( 73), UINT8_C(113), UINT8_C(185), UINT8_C(143),
        UINT8_C( 90), UINT8_C(215), UINT8_C(245), UINT8_C( 39), UINT8_C(226), UINT8_C( 80), UINT8_C( 71), UINT8_C(180),
        UINT8_C(136), UINT8_C( 84), UINT8_C(164), UINT8_C(159), UINT8_C( 10), UINT8_C(211), UINT8_C(101), UINT8_C(227) },
      { UINT8_C(141), UINT8_C( 40), UINT8_C(140), UINT8_C(175), UINT8_C( 54), UINT8_C(101), UINT8_C(249), UINT8_C( 99),
        UINT8_C(209), UINT8_C(219), UINT8_C(114), UINT8_C( 26), UINT8_C(225), UINT8_C( 43), UINT8_C(170), UINT8_C(166),
        UINT8_C(  3), UINT8_C(159), UINT8_C(205), UINT8_C(229), UINT8_C(239), UINT8_C( 21), UINT8_C(153), UINT8_C(120),
        UINT8_C(105), UINT8_C( 61), UINT8_C( 23), UINT8_C(116), UINT8_C( 16), UINT8_C(124), UINT8_C( 46), UINT8_C(158),
        UINT8_C(217), UINT8_C(130), UINT8_C( 77), UINT8_C(219), UINT8_C( 34), UINT8_C( 13), UINT8_C( 62), UINT8_C(185),
        UINT8_C( 34), UINT8_C(176), UINT8_C(211), UINT8_C( 14), UINT8_C(220), UINT8_C(125), UINT8_C( 21), UINT8_C(143),
        UINT8_C( 90), UINT8_C(226), UINT8_C(196), UINT8_C( 12), UINT8_C(247), UINT8_C( 93), UINT8_C(132), UINT8_C(180),
        UINT8_C(154), UINT8_C(156), UINT8_C(213), UINT8_C(171), UINT8_C( 10), UINT8_C(211), UINT8_C(101), UINT8_C(189) },
      UINT64_C( 7624788718343951684) },
    { UINT64_C( 9621827559429007276),
      { UINT8_C(136), UINT8_C(247), UINT8_C(129), UINT8_C(222), UINT8_C( 85), UINT8_C( 86), UINT8_C(154), UINT8_C(185),
        UINT8_C(246), UINT8_C(179), UINT8_C(128), UINT8_C(228), UINT8_C(138), UINT8_C( 70), UINT8_C(188), UINT8_C(244),
        UINT8_C(180), UINT8_C(152), UINT8_C( 30), UINT8_C( 21), UINT8_C( 52), UINT8_C(182), UINT8_C(254), UINT8_C( 41),
        UINT8_C( 83), UINT8_C( 77), UINT8_C( 78), UINT8_C( 68), UINT8_C(  1), UINT8_C( 42), UINT8_C(173), UINT8_C(137),
        UINT8_C( 34), UINT8_C( 46), UINT8_C(104), UINT8_C(119), UINT8_C(133), UINT8_C(  2), UINT8_C( 48), UINT8_C(123),
        UINT8_C(182), UINT8_C(176), UINT8_C( 95), UINT8_C( 64), UINT8_C(246), UINT8_C( 27), UINT8_C( 53), UINT8_C(171),
        UINT8_C(179), UINT8_C( 83), UINT8_C(192), UINT8_C(231), UINT8_C(  9), UINT8_C(190), UINT8_C( 16), UINT8_C( 92),
        UINT8_C( 11), UINT8_C( 94), UINT8_C(160), UINT8_C( 12), UINT8_C(137), UINT8_C( 78), UINT8_C(150), UINT8_C(171) },
      { UINT8_C(124), UINT8_C(254), UINT8_C(129), UINT8_C(  1), UINT8_C(  0), UINT8_C( 86), UINT8_C(124), UINT8_C(182),
        UINT8_C(246), UINT8_C(219), UINT8_C(247), UINT8_C(249), UINT8_C(247), UINT8_C( 70), UINT8_C(164), UINT8_C(170),
        UINT8_C(180), UINT8_C(152), UINT8_C(146), UINT8_C(136), UINT8_C( 34), UINT8_C(162), UINT8_C(228), UINT8_C( 45),
        UINT8_C(  1), UINT8_C(132), UINT8_C( 57), UINT8_C(138), UINT8_C(210), UINT8_C( 42), UINT8_C( 53), UINT8_C( 79),
        UINT8_C(205), UINT8_C( 87), UINT8_C( 80), UINT8_C(206), UINT8_C(169), UINT8_C(  2), UINT8_C(132), UINT8_C(171),
        UINT8_C(168), UINT8_C(123), UINT8_C(164), UINT8_C(159), UINT8_C(167), UINT8_C( 72), UINT8_C( 74), UINT8_C( 38),
        UINT8_C(172), UINT8_C(220), UINT8_C(174), UINT8_C(206), UINT8_C(  9), UINT8_C(190), UINT8_C( 16), UINT8_C(127),
        UINT8_C( 23), UINT8_C( 94), UINT8_C(  9), UINT8_C(233), UINT8_C(137), UINT8_C( 62), UINT8_C( 56), UINT8_C(210) },
      UINT64_C( 9332030358784583460) },
    { UINT64_C( 4660072082535984156),
      { UINT8_C(253), UINT8_C(140), UINT8_C(179), UINT8_C( 72),    UINT8_MAX, UINT8_C(100), UINT8_C( 88), UINT8_C(142),
        UINT8_C(103), UINT8_C(170), UINT8_C(205), UINT8_C(183), UINT8_C(190), UINT8_C(209), UINT8_C(138), UINT8_C(157),
        UINT8_C(133), UINT8_C(228), UINT8_C(135), UINT8_C( 33), UINT8_C(151), UINT8_C( 16), UINT8_C( 46), UINT8_C( 67),
        UINT8_C(119), UINT8_C(  2), UINT8_C( 13), UINT8_C(166), UINT8_C(156), UINT8_C(148), UINT8_C( 43), UINT8_C(153),
        UINT8_C( 32), UINT8_C(222), UINT8_C(225), UINT8_C( 31), UINT8_C( 66), UINT8_C( 57), UINT8_C(173), UINT8_C(169),
        UINT8_C(227), UINT8_C(122), UINT8_C( 97), UINT8_C(161), UINT8_C( 76), UINT8_C(235), UINT8_C( 63), UINT8_C(209),
        UINT8_C(208), UINT8_C(198), UINT8_C(243), UINT8_C(103), UINT8_C(214), UINT8_C( 33), UINT8_C(171), UINT8_C( 77),
        UINT8_C( 36), UINT8_C(184), UINT8_C(243), UINT8_C(192), UINT8_C( 76), UINT8_C( 30), UINT8_C( 89), UINT8_C(108) },
      { UINT8_C(253), UINT8_C( 58), UINT8_C(139), UINT8_C( 72), UINT8_C(116), UINT8_C( 56), UINT8_C(233), UINT8_C( 87),
        UINT8_C(103), UINT8_C(170), UINT8_C(249),    UINT8_MAX, UINT8_C( 53), UINT8_C( 56), UINT8_C(138), UINT8_C(157),
        UINT8_C(254), UINT8_C(195), UINT8_C(109), UINT8_C(212), UINT8_C(229), UINT8_C( 24), UINT8_C( 33), UINT8_C(  9),
        UINT8_C(208), UINT8_C( 20), UINT8_C(201), UINT8_C( 28), UINT8_C( 50), UINT8_C(148), UINT8_C( 43), UINT8_C( 47),
        UINT8_C( 92), UINT8_C( 19), UINT8_C(111), UINT8_C(208), UINT8_C( 75), UINT8_C( 88), UINT8_C( 40), UINT8_C(254),
        UINT8_C(162), UINT8_C( 33), UINT8_C(253), UINT8_C(215), UINT8_C( 89), UINT8_C(206), UINT8_C(221), UINT8_C(209),
        UINT8_C(145), UINT8_C( 74), UINT8_C(243), UINT8_C(103), UINT8_C( 98), UINT8_C( 76), UINT8_C(171), UINT8_C( 77),
        UINT8_C( 96), UINT8_C( 72), UINT8_C( 78), UINT8_C(146), UINT8_C(106), UINT8_C(214), UINT8_C(194), UINT8_C(199) },
      UINT64_C( 4659189973289896968) },
    { UINT64_C( 8401610583014384274),
      { UINT8_C(137), UINT8_C( 28), UINT8_C(161), UINT8_C( 12), UINT8_C( 29), UINT8_C(146), UINT8_C(185), UINT8_C(218),
        UINT8_C(138), UINT8_C(241), UINT8_C(159), UINT8_C(  7), UINT8_C(230), UINT8_C(203), UINT8_C( 83), UINT8_C(231),
        UINT8_C(241), UINT8_C(216), UINT8_C(202), UINT8_C(211), UINT8_C( 93), UINT8_C(119), UINT8_C(162), UINT8_C(122),
        UINT8_C( 35), UINT8_C(231), UINT8_C(237), UINT8_C(  1), UINT8_C(205), UINT8_C(152), UINT8_C( 65), UINT8_C( 86),
        UINT8_C(180), UINT8_C(227), UINT8_C( 99), UINT8_C(210), UINT8_C(117), UINT8_C( 28), UINT8_C(172),    UINT8_MAX,
        UINT8_C( 13), UINT8_C( 75), UINT8_C(  7), UINT8_C(243), UINT8_C( 22), UINT8_C( 90), UINT8_C(219), UINT8_C(  7),
        UINT8_C( 51), UINT8_C(165), UINT8_C(218), UINT8_C(144), UINT8_C( 28), UINT8_C(124), UINT8_C( 10), UINT8_C( 63),
        UINT8_C( 99), UINT8_C(248), UINT8_C( 64), UINT8_C( 48), UINT8_C(144), UINT8_C(129), UINT8_C(135), UINT8_C( 69) },
      { UINT8_C(100), UINT8_C(234), UINT8_C(161), UINT8_C(218), UINT8_C(  6), UINT8_C(195), UINT8_C(217), UINT8_C(218),
        UINT8_C( 15), UINT8_C(224), UINT8_C(  6), UINT8_C( 37), UINT8_C( 59), UINT8_C(225), UINT8_C( 45), UINT8_C(110),
        UINT8_C(134), UINT8_C(216), UINT8_C(254), UINT8_C(162), UINT8_C(132), UINT8_C(  9), UINT8_C(225), UINT8_C(231),
        UINT8_C(  1), UINT8_C( 33), UINT8_C(237), UINT8_C(145), UINT8_C(163), UINT8_C(152), UINT8_C( 65), UINT8_C(  7),
        UINT8_C(137), UINT8_C(237), UINT8_C(225), UINT8_C(143), UINT8_C(177), UINT8_C( 28), UINT8_C(172), UINT8_C(192),
        UINT8_C(155), UINT8_C(168), UINT8_C(229), UINT8_C(214), UINT8_C(138), UINT8_C( 18), UINT8_C( 68), UINT8_C( 16),
        UINT8_C( 26), UINT8_C( 67), UINT8_C(179), UINT8_C(158), UINT8_C( 76), UINT8_C(148), UINT8_C(133), UINT8_C( 77),
        UINT8_C(182), UINT8_C(157), UINT8_C( 64), UINT8_C( 48), UINT8_C( 60), UINT8_C(181), UINT8_C( 96), UINT8_C( 69) },
      UINT64_C( 2637003019158560898) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__mmask64 k = test_vec[i].k;
    simde__m512i a = simde_mm512_loadu_epi8(test_vec[i].a);
    simde__m512i b = simde_mm512_loadu_epi8(test_vec[i].b);
    simde__mmask64 r = simde_mm512_mask_cmple_epu8_mask(k, a, b);
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
    simde__mmask64 r = simde_mm512_mask_cmple_epu8_mask(k, a, b);

    simde_test_x86_write_mmask64(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_u8x64(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_u8x64(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask64(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_x_mm_cmple_epi16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int16_t a[8];
    const int16_t b[8];
    const int16_t r[8];
  } test_vec[] = {
    { { -INT16_C( 23214), -INT16_C(  4149),  INT16_C( 18858), -INT16_C( 10267), -INT16_C( 29341),  INT16_C( 14954),  INT16_C( 14836),  INT16_C(  5682) },
      { -INT16_C( 11413), -INT16_C(  4149),  INT16_C( 26818), -INT16_C( 10267),  INT16_C(  7514),  INT16_C(    48),  INT16_C( 19514), -INT16_C( 29627) },
      { -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0) } },
    { { -INT16_C(  8466), -INT16_C(  7433),  INT16_C( 10519), -INT16_C( 32008), -INT16_C(  9476), -INT16_C( 16847), -INT16_C( 20926), -INT16_C( 25345) },
      {  INT16_C( 12235),  INT16_C(  1692), -INT16_C(  7812),  INT16_C( 28050), -INT16_C(  9476), -INT16_C( 16847),  INT16_C( 32111), -INT16_C( 25345) },
      { -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1) } },
    { {  INT16_C(  9746),  INT16_C( 21986), -INT16_C(  7468), -INT16_C( 24591), -INT16_C( 29167), -INT16_C( 29275),  INT16_C( 14447),  INT16_C( 25083) },
      {  INT16_C(  1094),  INT16_C( 21986), -INT16_C( 19071), -INT16_C(  9198),  INT16_C( 20917), -INT16_C(  8881),  INT16_C( 17545),  INT16_C( 25083) },
      {  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1) } },
    { { -INT16_C( 31888), -INT16_C(  8091),  INT16_C( 24763),  INT16_C(   321), -INT16_C(  4507), -INT16_C(  6474), -INT16_C( 14172),  INT16_C( 22979) },
      {  INT16_C(  4633), -INT16_C( 23754),  INT16_C( 14422), -INT16_C( 16321),  INT16_C( 12317), -INT16_C(  6474), -INT16_C(  9454), -INT16_C( 31813) },
      { -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0) } },
    { { -INT16_C( 12141),  INT16_C( 14285), -INT16_C( 28520), -INT16_C( 19824), -INT16_C( 14686), -INT16_C(  1963), -INT16_C( 27393),  INT16_C(  7352) },
      { -INT16_C( 12141), -INT16_C( 10497), -INT16_C( 17519), -INT16_C(  4007), -INT16_C( 17188),  INT16_C( 23817),  INT16_C(  9313), -INT16_C(  3004) },
      { -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0) } },
    { { -INT16_C( 27519), -INT16_C( 32709), -INT16_C(  3288), -INT16_C(  4964), -INT16_C( 25431),  INT16_C( 15042),  INT16_C(  7255),  INT16_C( 13098) },
      { -INT16_C( 27519), -INT16_C( 32709), -INT16_C( 11176), -INT16_C(  4964),  INT16_C( 22757), -INT16_C( 31015),  INT16_C(  7255),  INT16_C( 13098) },
      { -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1) } },
    { { -INT16_C( 31922), -INT16_C( 23077),  INT16_C(  1439),  INT16_C( 30680),  INT16_C( 26681), -INT16_C( 28239), -INT16_C(  8643),  INT16_C(  8926) },
      { -INT16_C( 31922),  INT16_C( 19113),  INT16_C( 29392),  INT16_C( 31967), -INT16_C(  2697),  INT16_C( 28241),  INT16_C(  4519), -INT16_C(  2801) },
      { -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0) } },
    { {  INT16_C( 23770),  INT16_C(  6074), -INT16_C( 26566),  INT16_C( 28986), -INT16_C(  7344),  INT16_C(  8380), -INT16_C( 25771), -INT16_C( 13156) },
      { -INT16_C(  4720),  INT16_C( 14139),  INT16_C( 19199),  INT16_C( 28986), -INT16_C( 14796),  INT16_C(  8380),  INT16_C( 29240),  INT16_C(  4940) },
      {  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_x_mm_loadu_epi16(test_vec[i].a);
    simde__m128i b = simde_x_mm_loadu_epi16(test_vec[i].b);
    simde__m128i r = simde_x_mm_cmple_epi16(a, b);
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
    simde__m128i r = simde_x_mm_cmple_epi16(a, b);

    simde_test_x86_write_i16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_cmple_epi16_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int16_t a[8];
    const int16_t b[8];
    const simde__mmask8 r;
  } test_vec[] = {
    { { -INT16_C( 21147),  INT16_C( 31008),  INT16_C( 20543), -INT16_C( 15477),  INT16_C( 25171), -INT16_C(  4991),  INT16_C( 10160), -INT16_C(  4710) },
      {  INT16_C( 10730), -INT16_C(  1020),  INT16_C( 20543),  INT16_C( 22051),  INT16_C( 25171), -INT16_C( 24068),  INT16_C(  5741), -INT16_C( 11397) },
      UINT8_C( 29) },
    { {  INT16_C( 18233), -INT16_C(  5845), -INT16_C( 14994),  INT16_C( 22999), -INT16_C(  9233),  INT16_C( 29269),  INT16_C( 30952),  INT16_C( 27080) },
      { -INT16_C( 15134),  INT16_C( 20490), -INT16_C( 14994), -INT16_C( 25309), -INT16_C(  9233),  INT16_C(  3232),  INT16_C( 30952),  INT16_C( 32587) },
      UINT8_C(214) },
    { { -INT16_C( 14054),  INT16_C(   669),  INT16_C( 25921),  INT16_C(  9323),  INT16_C( 29993),  INT16_C(  1140), -INT16_C( 26630),  INT16_C(  7073) },
      {  INT16_C( 16646),  INT16_C( 19495),  INT16_C( 25921),  INT16_C( 21707),  INT16_C( 13289),  INT16_C(  9584), -INT16_C(  7053),  INT16_C(  7073) },
      UINT8_C(239) },
    { { -INT16_C( 30863),  INT16_C( 27520),  INT16_C(  8478),  INT16_C(  9350), -INT16_C( 20893),  INT16_C(  2672),  INT16_C( 15137),  INT16_C(  2655) },
      { -INT16_C( 30863),  INT16_C( 27520), -INT16_C( 32589),  INT16_C( 24943), -INT16_C(   146), -INT16_C( 16303),  INT16_C( 25851),  INT16_C( 27708) },
      UINT8_C(219) },
    { { -INT16_C( 24820),  INT16_C( 11595), -INT16_C( 21797),  INT16_C( 18999),  INT16_C( 26489),  INT16_C( 11564), -INT16_C( 25624),  INT16_C( 22158) },
      { -INT16_C(  8293), -INT16_C( 27114), -INT16_C( 21797),  INT16_C( 18999),  INT16_C( 26489),  INT16_C( 11564),  INT16_C( 26935),  INT16_C( 17198) },
      UINT8_C(125) },
    { {  INT16_C( 23055), -INT16_C(  2101),  INT16_C( 23029), -INT16_C( 28595),  INT16_C( 25657),  INT16_C( 32038),  INT16_C( 10423), -INT16_C( 14675) },
      { -INT16_C(  6398),  INT16_C( 14772),  INT16_C( 23029),  INT16_C( 23165), -INT16_C(  4772), -INT16_C( 32450),  INT16_C( 10423), -INT16_C( 14675) },
      UINT8_C(206) },
    { {  INT16_C( 29262),  INT16_C(  1529), -INT16_C( 22885), -INT16_C( 25141),  INT16_C( 32654), -INT16_C(  8234),  INT16_C( 21346), -INT16_C( 16839) },
      {  INT16_C( 30529), -INT16_C( 10689),  INT16_C( 24291), -INT16_C( 22149),  INT16_C( 32654), -INT16_C(  8234), -INT16_C( 20478),  INT16_C( 20488) },
      UINT8_C(189) },
    { {  INT16_C( 12704),  INT16_C(   533),  INT16_C( 20101), -INT16_C( 14656),  INT16_C(   197), -INT16_C( 22372),  INT16_C(  6238), -INT16_C( 22703) },
      {  INT16_C( 12704),  INT16_C( 12851),  INT16_C( 15206), -INT16_C( 30334),  INT16_C(   197), -INT16_C(  6585), -INT16_C( 23817), -INT16_C( 26852) },
      UINT8_C( 51) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_x_mm_loadu_epi16(test_vec[i].a);
    simde__m128i b = simde_x_mm_loadu_epi16(test_vec[i].b);
    simde__mmask8 r = simde_mm_cmple_epi16_mask(a, b);
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
    simde__mmask8 r = simde_mm_cmple_epi16_mask(a, b);

    simde_test_x86_write_i16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_mask_cmple_epi16_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k;
    const int16_t a[8];
    const int16_t b[8];
    const simde__mmask8 r;
  } test_vec[] = {
    { UINT8_C( 21),
      { -INT16_C( 17574), -INT16_C( 18194),  INT16_C( 16595),  INT16_C(   863), -INT16_C( 27914),  INT16_C( 23605), -INT16_C( 18482),  INT16_C(  3046) },
      {  INT16_C( 11662), -INT16_C( 30991),  INT16_C(  3792), -INT16_C( 23523), -INT16_C( 18624), -INT16_C( 16131),  INT16_C(  7185),  INT16_C( 27398) },
      UINT8_C( 17) },
    { UINT8_C(178),
      { -INT16_C( 30748), -INT16_C( 25629), -INT16_C(  4243), -INT16_C( 25814), -INT16_C( 20256), -INT16_C(  4501),  INT16_C(  4045), -INT16_C( 31698) },
      { -INT16_C(  4340), -INT16_C( 25629), -INT16_C(  4243), -INT16_C(  5377), -INT16_C( 21980), -INT16_C( 22753),  INT16_C( 19033),  INT16_C( 15804) },
      UINT8_C(130) },
    { UINT8_C( 52),
      {  INT16_C( 24133),  INT16_C( 21632),  INT16_C(  1164),  INT16_C( 31584), -INT16_C( 30566), -INT16_C( 25999),  INT16_C( 23432),  INT16_C( 12990) },
      {  INT16_C( 25979), -INT16_C( 14965), -INT16_C( 14302), -INT16_C( 15721), -INT16_C( 10335), -INT16_C( 25999), -INT16_C( 16207),  INT16_C( 12990) },
      UINT8_C( 48) },
    { UINT8_C( 68),
      {  INT16_C(  3991), -INT16_C(  3140), -INT16_C(  4147),  INT16_C( 13166),  INT16_C( 13178),  INT16_C( 17237),  INT16_C(  6091), -INT16_C( 23836) },
      { -INT16_C( 30872),  INT16_C( 10323),  INT16_C( 19165), -INT16_C( 19641), -INT16_C(  3434),  INT16_C( 17038),  INT16_C(   536), -INT16_C( 23836) },
      UINT8_C(  4) },
    { UINT8_C( 72),
      { -INT16_C(  8345),  INT16_C( 32271), -INT16_C( 20029),  INT16_C( 19430),  INT16_C(  3589),  INT16_C( 20264), -INT16_C(  9131),  INT16_C( 18405) },
      {  INT16_C( 10090),  INT16_C( 32271), -INT16_C( 20029), -INT16_C( 11906),  INT16_C( 23987), -INT16_C( 15117), -INT16_C( 28817), -INT16_C( 10744) },
      UINT8_C(  0) },
    { UINT8_C(168),
      {  INT16_C(  7846), -INT16_C( 32098), -INT16_C(  6909),  INT16_C( 11244),  INT16_C( 22597),  INT16_C( 21961), -INT16_C( 25898),  INT16_C( 13064) },
      { -INT16_C( 13171),  INT16_C(  7330),  INT16_C( 30933), -INT16_C(  4725), -INT16_C( 16692),  INT16_C(  1718), -INT16_C( 31429),  INT16_C( 13064) },
      UINT8_C(128) },
    { UINT8_C(201),
      {  INT16_C( 28058),  INT16_C( 13438), -INT16_C( 19850),  INT16_C( 17089), -INT16_C(  8620), -INT16_C( 13033),  INT16_C(  1129),  INT16_C( 10137) },
      {  INT16_C( 28058),  INT16_C( 16483),  INT16_C( 17647), -INT16_C(  8989), -INT16_C(  8620), -INT16_C(  2130),  INT16_C(  1129),  INT16_C( 10137) },
      UINT8_C(193) },
    { UINT8_C(  9),
      { -INT16_C(  3836),  INT16_C(  2099),  INT16_C( 23179),  INT16_C( 11203),  INT16_C(   957),  INT16_C(   538), -INT16_C(  2330),  INT16_C( 28842) },
      { -INT16_C( 24156),  INT16_C( 27595), -INT16_C( 16319),  INT16_C( 11203),  INT16_C( 18922), -INT16_C( 10705),  INT16_C( 21301),  INT16_C( 14751) },
      UINT8_C(  8) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__mmask8 k = test_vec[i].k;
    simde__m128i a = simde_x_mm_loadu_epi16(test_vec[i].a);
    simde__m128i b = simde_x_mm_loadu_epi16(test_vec[i].b);
    simde__mmask8 r = simde_mm_mask_cmple_epi16_mask(k, a, b);
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
    simde__mmask8 r = simde_mm_mask_cmple_epi16_mask(k, a, b);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i16x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_x_mm256_cmple_epi16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int16_t a[16];
    const int16_t b[16];
    const int16_t r[16];
  } test_vec[] = {
    { { -INT16_C(  1607), -INT16_C( 17244), -INT16_C( 27035), -INT16_C( 28552),  INT16_C( 24696),  INT16_C(  6121),  INT16_C( 27652),  INT16_C(  5721),
        -INT16_C( 10738),  INT16_C( 16073), -INT16_C(  7039), -INT16_C( 28531),  INT16_C(  9378), -INT16_C(  7053), -INT16_C( 16075), -INT16_C(  4453) },
      { -INT16_C(  1607),  INT16_C(  8362),  INT16_C(  8918),  INT16_C( 20400),  INT16_C( 24696), -INT16_C( 30874), -INT16_C( 16634),  INT16_C(  5277),
        -INT16_C( 10738),  INT16_C( 16073), -INT16_C(  8374), -INT16_C(  4953),  INT16_C(  6659),  INT16_C( 14545),  INT16_C( 27867), -INT16_C(  4453) },
      { -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
        -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1) } },
    { {  INT16_C( 27649),  INT16_C( 19362),  INT16_C( 18764),  INT16_C( 20279),  INT16_C(  2148),  INT16_C( 16264), -INT16_C( 20619),  INT16_C(  8661),
        -INT16_C( 29824),  INT16_C( 29860),  INT16_C( 30450), -INT16_C(  3349), -INT16_C(  5714), -INT16_C( 23047),  INT16_C(  4996), -INT16_C( 31439) },
      { -INT16_C( 11136), -INT16_C( 13104),  INT16_C(  2077), -INT16_C( 32485), -INT16_C( 23792), -INT16_C( 31295), -INT16_C( 27054), -INT16_C( 11353),
         INT16_C( 19234),  INT16_C(  5191),  INT16_C( 13250), -INT16_C(  3349), -INT16_C(   228), -INT16_C( 23047),  INT16_C( 18195), -INT16_C( 31439) },
      {  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
        -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1) } },
    { { -INT16_C( 29817),  INT16_C( 18760),  INT16_C( 20158), -INT16_C(  9542), -INT16_C( 12210),  INT16_C( 24955), -INT16_C( 24041),  INT16_C( 13300),
         INT16_C( 21401), -INT16_C( 26516),  INT16_C(  9933), -INT16_C(  5209),  INT16_C( 15522), -INT16_C( 19364), -INT16_C( 24712),  INT16_C(   232) },
      {  INT16_C( 12330), -INT16_C(  6071),  INT16_C( 20158), -INT16_C( 13117),  INT16_C( 16083), -INT16_C(  5331),  INT16_C(  8672),  INT16_C( 31006),
        -INT16_C( 30092),  INT16_C( 16913), -INT16_C( 18000),  INT16_C( 21037),  INT16_C( 15522),  INT16_C( 28166), -INT16_C(  4567),  INT16_C( 21358) },
      { -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),
         INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1) } },
    { { -INT16_C( 22239), -INT16_C( 11665), -INT16_C( 25502),  INT16_C( 22308),  INT16_C( 11046),  INT16_C( 20421),  INT16_C( 13081),  INT16_C( 14498),
        -INT16_C(  8469), -INT16_C( 22827),  INT16_C( 16093),  INT16_C(  6964), -INT16_C( 20779), -INT16_C( 29127), -INT16_C( 12219),  INT16_C( 26555) },
      {  INT16_C( 10873), -INT16_C(  9415),  INT16_C( 24006),  INT16_C( 22308), -INT16_C(  1912), -INT16_C( 24005), -INT16_C(  8660),  INT16_C(  6106),
        -INT16_C( 20548), -INT16_C( 22827), -INT16_C(  3603), -INT16_C( 15435), -INT16_C(  4449), -INT16_C(  6831),  INT16_C(  3262),  INT16_C( 14412) },
      { -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
         INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0) } },
    { {  INT16_C( 16278), -INT16_C( 31911),  INT16_C(  3632), -INT16_C( 12218), -INT16_C( 26628), -INT16_C( 17739),  INT16_C(   419), -INT16_C(  9742),
         INT16_C(  1670),  INT16_C( 26838), -INT16_C( 16564), -INT16_C( 29741), -INT16_C(  7965), -INT16_C(  6410),  INT16_C( 30919),  INT16_C( 23973) },
      { -INT16_C(   329), -INT16_C(  5919),  INT16_C(  9996),  INT16_C(  2232),  INT16_C( 28095),  INT16_C( 25282), -INT16_C( 19090), -INT16_C(  3012),
         INT16_C(  4795),  INT16_C( 26838),  INT16_C( 12497), -INT16_C( 29741), -INT16_C( 30448), -INT16_C( 10086),  INT16_C( 30919),  INT16_C( 23973) },
      {  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
        -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1) } },
    { { -INT16_C( 31315),  INT16_C( 32395),  INT16_C(  7861), -INT16_C( 15053), -INT16_C( 12888), -INT16_C( 21859), -INT16_C( 11507),  INT16_C( 19043),
         INT16_C(  1513),  INT16_C( 10132), -INT16_C(  6818),  INT16_C(  9508), -INT16_C( 31495), -INT16_C( 15783), -INT16_C( 32225), -INT16_C( 12986) },
      { -INT16_C( 11769), -INT16_C( 17333),  INT16_C( 32496), -INT16_C( 26495),  INT16_C(  8012),  INT16_C( 22850), -INT16_C( 22798), -INT16_C(  9309),
         INT16_C( 14251),  INT16_C(  2307),  INT16_C( 10013),  INT16_C(  5678), -INT16_C( 30549), -INT16_C( 13351),  INT16_C(  7946),  INT16_C(  4504) },
      { -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
        -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1) } },
    { {  INT16_C( 16098), -INT16_C(   233),  INT16_C( 18021),  INT16_C(  4373), -INT16_C(  4402), -INT16_C( 10020),  INT16_C( 29710), -INT16_C(    23),
        -INT16_C( 18857), -INT16_C( 17951),  INT16_C( 23556),  INT16_C( 29287),  INT16_C( 28185),  INT16_C( 31953),  INT16_C(  3097), -INT16_C(  1142) },
      { -INT16_C( 24246), -INT16_C( 20230),  INT16_C(  4071), -INT16_C( 19007), -INT16_C( 25090), -INT16_C( 10020),  INT16_C( 30225),  INT16_C( 26635),
        -INT16_C(  4820), -INT16_C( 17951), -INT16_C( 30391),  INT16_C( 25251),  INT16_C( 29944),  INT16_C(  4574),  INT16_C( 26753), -INT16_C( 13556) },
      {  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),
        -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0) } },
    { {  INT16_C( 29976),  INT16_C( 24840), -INT16_C( 21506), -INT16_C(  2365), -INT16_C( 24289), -INT16_C( 24569),  INT16_C(  4873),  INT16_C(  4716),
        -INT16_C(  6375),  INT16_C( 12035), -INT16_C( 21980), -INT16_C(   702),  INT16_C( 25310), -INT16_C( 30488),  INT16_C( 15245), -INT16_C( 23201) },
      {  INT16_C( 29976), -INT16_C( 20986), -INT16_C( 14062),  INT16_C( 12965), -INT16_C( 21398),  INT16_C( 29650),  INT16_C( 16064),  INT16_C(  4716),
        -INT16_C( 30426),  INT16_C( 18952),  INT16_C( 19251),  INT16_C(  4423),  INT16_C( 12205), -INT16_C( 30488),  INT16_C( 15245), -INT16_C( 23201) },
      { -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),
         INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256i a = simde_mm256_loadu_epi16(test_vec[i].a);
    simde__m256i b = simde_mm256_loadu_epi16(test_vec[i].b);
    simde__m256i r = simde_x_mm256_cmple_epi16(a, b);
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
    simde__m256i r = simde_x_mm256_cmple_epi16(a, b);

    simde_test_x86_write_i16x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i16x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_cmple_epi16_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int16_t a[16];
    const int16_t b[16];
    const simde__mmask16 r;
  } test_vec[] = {
    { {  INT16_C( 29783),  INT16_C(  4134), -INT16_C(  7330), -INT16_C( 18484), -INT16_C( 18612),  INT16_C( 24725), -INT16_C(   492),  INT16_C( 17609),
        -INT16_C(  8833),  INT16_C( 21118),  INT16_C(  1744),  INT16_C(  1974),  INT16_C(  5638),  INT16_C( 26042),  INT16_C( 21771),  INT16_C( 25372) },
      {  INT16_C( 29783),  INT16_C( 10355), -INT16_C(  7330),  INT16_C( 29151), -INT16_C( 18612),  INT16_C(  3026), -INT16_C( 25742), -INT16_C(  3761),
        -INT16_C( 12936),  INT16_C( 21118), -INT16_C(  1325), -INT16_C(  9905),  INT16_C(  2320),  INT16_C(  6974),  INT16_C( 23134),  INT16_C( 10366) },
      UINT16_C(16927) },
    { {  INT16_C( 19022),  INT16_C(  8543), -INT16_C( 20924),  INT16_C( 21754),  INT16_C( 14519),  INT16_C(  5743), -INT16_C(  4462),  INT16_C( 11838),
        -INT16_C( 28961),  INT16_C(  4335),  INT16_C(  8637),  INT16_C( 24631),  INT16_C( 26918), -INT16_C( 14987),  INT16_C( 31722),  INT16_C( 14557) },
      {  INT16_C( 19022),  INT16_C(  2393),  INT16_C( 21483), -INT16_C( 23971),  INT16_C( 14519),  INT16_C(  7608), -INT16_C(  2373), -INT16_C( 26037),
         INT16_C( 14980),  INT16_C( 16810),  INT16_C(  8637), -INT16_C( 32351),  INT16_C(  5706),  INT16_C( 13383),  INT16_C(  9362),  INT16_C( 22380) },
      UINT16_C(42869) },
    { { -INT16_C( 29883), -INT16_C( 24221),  INT16_C(  1133), -INT16_C( 18654),  INT16_C( 26907), -INT16_C( 21012),  INT16_C( 22669), -INT16_C(  4604),
         INT16_C( 25886),  INT16_C( 13881),  INT16_C( 10020), -INT16_C( 20518), -INT16_C( 25906),  INT16_C( 27638), -INT16_C( 10330), -INT16_C(  5236) },
      { -INT16_C(  4254), -INT16_C( 12404),  INT16_C(  1133),  INT16_C(  3975),  INT16_C( 29464), -INT16_C( 22852), -INT16_C( 16181), -INT16_C(  5740),
        -INT16_C( 13018),  INT16_C( 18976),  INT16_C( 10020), -INT16_C( 15367), -INT16_C(  4204),  INT16_C( 27638), -INT16_C( 17722),  INT16_C( 10534) },
      UINT16_C(48671) },
    { { -INT16_C( 14463),  INT16_C( 30361), -INT16_C( 27711),  INT16_C( 22073),  INT16_C( 26498),  INT16_C( 18832), -INT16_C( 18910), -INT16_C( 13198),
         INT16_C( 27241), -INT16_C( 13718),  INT16_C(  6122), -INT16_C(  9148),  INT16_C( 25728), -INT16_C( 22118),  INT16_C( 16920), -INT16_C( 25863) },
      { -INT16_C( 28151), -INT16_C( 13552),  INT16_C( 18981), -INT16_C( 22495), -INT16_C( 20047), -INT16_C( 11279),  INT16_C( 25448), -INT16_C( 11873),
         INT16_C(  2509), -INT16_C( 13718), -INT16_C(  8160), -INT16_C( 24428),  INT16_C( 11844),  INT16_C( 23882),  INT16_C( 16920), -INT16_C( 25863) },
      UINT16_C(58052) },
    { { -INT16_C(  4993), -INT16_C( 24452),  INT16_C(  4300),  INT16_C(  4160), -INT16_C( 30146), -INT16_C( 20627),  INT16_C( 25805), -INT16_C( 23767),
         INT16_C( 28268), -INT16_C( 16994),  INT16_C( 16852), -INT16_C(  5184), -INT16_C( 26667), -INT16_C( 13205), -INT16_C( 17651), -INT16_C( 29552) },
      {  INT16_C(  3239),  INT16_C( 29484),  INT16_C( 27932),  INT16_C( 23428), -INT16_C(  3593), -INT16_C( 15094),  INT16_C( 25805), -INT16_C( 15768),
         INT16_C(  1697),  INT16_C( 30079),  INT16_C( 16455),  INT16_C(  7264), -INT16_C( 13353), -INT16_C(  6936),  INT16_C( 30855),  INT16_C( 11888) },
      UINT16_C(64255) },
    { { -INT16_C( 20684),  INT16_C( 31567), -INT16_C( 20241), -INT16_C( 14697),  INT16_C( 32635),  INT16_C(   682),  INT16_C(  6904),  INT16_C( 32049),
        -INT16_C( 11337), -INT16_C( 16098),  INT16_C(  7161),  INT16_C(  4291), -INT16_C( 30431),  INT16_C( 23422), -INT16_C( 21064), -INT16_C(  5067) },
      { -INT16_C( 20684),  INT16_C( 31567), -INT16_C( 20241), -INT16_C( 20463), -INT16_C( 17537),  INT16_C( 30643), -INT16_C(  6954), -INT16_C( 29196),
         INT16_C(  4791), -INT16_C( 20401),  INT16_C(  4653),  INT16_C( 20416),  INT16_C( 16027),  INT16_C( 21418), -INT16_C( 21064), -INT16_C(  5067) },
      UINT16_C(55591) },
    { {  INT16_C(  5028), -INT16_C( 11960),  INT16_C(  2085), -INT16_C( 16096), -INT16_C( 13753),  INT16_C( 13076),  INT16_C( 21674),  INT16_C(  3707),
         INT16_C(  4092), -INT16_C( 23384), -INT16_C(  3403),  INT16_C(  5834),  INT16_C( 26863), -INT16_C( 12211),  INT16_C(  4601), -INT16_C( 25240) },
      { -INT16_C( 20443),  INT16_C( 19055), -INT16_C( 28744), -INT16_C( 16096),  INT16_C(  8282),  INT16_C(  1074), -INT16_C( 20876),  INT16_C( 28946),
        -INT16_C( 17731),  INT16_C( 29205), -INT16_C(  8276), -INT16_C( 25720),  INT16_C( 26863),  INT16_C( 16747), -INT16_C( 11289),  INT16_C(  3294) },
      UINT16_C(45722) },
    { {  INT16_C( 31752), -INT16_C( 19380), -INT16_C( 11172), -INT16_C( 23728), -INT16_C( 17494), -INT16_C( 28188), -INT16_C( 15473),  INT16_C(  4765),
        -INT16_C(  3312), -INT16_C(  4786), -INT16_C( 30123), -INT16_C( 10460),  INT16_C( 24568),  INT16_C(  5326),  INT16_C( 13741), -INT16_C( 18963) },
      {  INT16_C( 14770),  INT16_C(  3689), -INT16_C( 18162), -INT16_C( 23728), -INT16_C( 17494),  INT16_C(  1097), -INT16_C( 15473),  INT16_C( 26902),
         INT16_C( 26073),  INT16_C( 12119),  INT16_C( 31727), -INT16_C(  6394), -INT16_C( 11045), -INT16_C( 30469),  INT16_C( 13741), -INT16_C( 18963) },
      UINT16_C(53242) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256i a = simde_mm256_loadu_epi16(test_vec[i].a);
    simde__m256i b = simde_mm256_loadu_epi16(test_vec[i].b);
    simde__mmask16 r = simde_mm256_cmple_epi16_mask(a, b);
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
    simde__mmask16 r = simde_mm256_cmple_epi16_mask(a, b);

    simde_test_x86_write_i16x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i16x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_mask_cmple_epi16_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask16 k;
    const int16_t a[16];
    const int16_t b[16];
    const simde__mmask16 r;
  } test_vec[] = {
    { UINT16_C( 7133),
      {  INT16_C( 11092),  INT16_C( 17183),  INT16_C(  9894), -INT16_C( 32470),  INT16_C(  9722),  INT16_C(  1033),  INT16_C( 17934),  INT16_C( 12480),
        -INT16_C( 29971),  INT16_C( 19808),  INT16_C( 18438),  INT16_C(  5922), -INT16_C(  1159), -INT16_C( 28542),  INT16_C( 22250),  INT16_C( 16256) },
      { -INT16_C( 24447),  INT16_C( 17183), -INT16_C( 21050), -INT16_C( 32470), -INT16_C( 19758), -INT16_C(  7995),  INT16_C( 17934), -INT16_C(  6640),
         INT16_C( 28688),  INT16_C(  5683),  INT16_C( 18438),  INT16_C( 12589), -INT16_C( 20656), -INT16_C( 28542),  INT16_C( 22250), -INT16_C( 31111) },
      UINT16_C( 2376) },
    { UINT16_C(14771),
      { -INT16_C( 27175),  INT16_C(  1648), -INT16_C( 16185), -INT16_C( 30538), -INT16_C( 17413),  INT16_C( 29898), -INT16_C( 21438), -INT16_C(  3984),
         INT16_C(  6484), -INT16_C( 17081),  INT16_C( 20629), -INT16_C(  3606), -INT16_C( 25261),  INT16_C( 15197),  INT16_C( 14944),  INT16_C( 14679) },
      { -INT16_C( 27175), -INT16_C( 26816), -INT16_C(  2424), -INT16_C( 30538), -INT16_C( 17413), -INT16_C(  3081),  INT16_C( 26774), -INT16_C(  5149),
         INT16_C(  6484),  INT16_C(  5800), -INT16_C( 28037), -INT16_C( 12793),  INT16_C( 25904),  INT16_C( 15197),  INT16_C( 24735),  INT16_C( 14679) },
      UINT16_C(12561) },
    { UINT16_C(53726),
      {  INT16_C( 11818),  INT16_C( 13004), -INT16_C(   772),  INT16_C(  1431),  INT16_C( 13964),  INT16_C( 22118), -INT16_C( 29018), -INT16_C( 21408),
         INT16_C( 24638),  INT16_C( 29138), -INT16_C(  7662), -INT16_C( 18533),  INT16_C( 11913),  INT16_C(  6719), -INT16_C(  3518),  INT16_C( 27732) },
      {  INT16_C(  8224),  INT16_C(  7326), -INT16_C(   772), -INT16_C( 22494), -INT16_C( 30612),  INT16_C(  4863),  INT16_C( 24342),  INT16_C( 21694),
        -INT16_C( 28224), -INT16_C( 11579),  INT16_C( 24691), -INT16_C( 18533), -INT16_C( 14194), -INT16_C( 12265), -INT16_C(  3518), -INT16_C(  9411) },
      UINT16_C(16580) },
    { UINT16_C(32957),
      {  INT16_C( 21056), -INT16_C( 14031), -INT16_C( 16306),  INT16_C( 26001),  INT16_C( 19600), -INT16_C( 12848),  INT16_C( 23336),  INT16_C(  8361),
        -INT16_C( 17918),  INT16_C( 21050), -INT16_C(  9161), -INT16_C( 14688),  INT16_C( 20116), -INT16_C( 24557), -INT16_C(  3396), -INT16_C(   911) },
      { -INT16_C( 23996), -INT16_C( 27963), -INT16_C( 16306), -INT16_C(  3080), -INT16_C( 14173), -INT16_C( 12848),  INT16_C( 26916),  INT16_C(  8361),
         INT16_C(  9507),  INT16_C( 23160), -INT16_C(  9161), -INT16_C( 27360),  INT16_C( 20116),  INT16_C(  9269), -INT16_C( 23002), -INT16_C(   911) },
      UINT16_C(32932) },
    { UINT16_C(64644),
      { -INT16_C( 16826),  INT16_C( 26521),  INT16_C(    84), -INT16_C( 30309), -INT16_C( 16092),  INT16_C( 17712),  INT16_C( 31019),  INT16_C( 10027),
         INT16_C( 26660), -INT16_C( 15588), -INT16_C(  9912), -INT16_C(  3038), -INT16_C(  5446), -INT16_C( 15988),  INT16_C( 18902),  INT16_C(  7489) },
      { -INT16_C(  9721),  INT16_C( 23428),  INT16_C(    84), -INT16_C(    27), -INT16_C( 16092),  INT16_C(  2884),  INT16_C( 28558),  INT16_C( 10027),
         INT16_C( 20183),  INT16_C(  8309), -INT16_C( 26841), -INT16_C(  3038), -INT16_C( 24446),  INT16_C( 22691), -INT16_C(  6935), -INT16_C(  3723) },
      UINT16_C(10372) },
    { UINT16_C(55499),
      { -INT16_C( 21435),  INT16_C( 22932),  INT16_C(  5773),  INT16_C( 12538), -INT16_C(  7314), -INT16_C(  7147), -INT16_C( 11052),  INT16_C(  8669),
        -INT16_C(  2450),  INT16_C(  1874), -INT16_C( 26130), -INT16_C(  3355),  INT16_C( 13165), -INT16_C(  3032), -INT16_C( 21416), -INT16_C( 25103) },
      { -INT16_C( 31400), -INT16_C(  6410),  INT16_C(  5773),  INT16_C( 12538),  INT16_C( 11220), -INT16_C( 22291), -INT16_C( 13313),  INT16_C( 28105),
         INT16_C(  7361), -INT16_C( 20619),  INT16_C( 23221),  INT16_C(  8865), -INT16_C( 13939), -INT16_C(  6889),  INT16_C(  2166), -INT16_C( 12670) },
      UINT16_C(51336) },
    { UINT16_C(17508),
      { -INT16_C( 32678), -INT16_C(   973), -INT16_C( 16221), -INT16_C( 17723),  INT16_C( 15270),  INT16_C( 10434),  INT16_C( 20234), -INT16_C( 16735),
         INT16_C(  2935), -INT16_C( 22391), -INT16_C( 32696),  INT16_C( 11975), -INT16_C( 20106), -INT16_C(  9762), -INT16_C( 22180), -INT16_C( 18510) },
      { -INT16_C( 32678), -INT16_C( 12877),  INT16_C( 30885),  INT16_C( 19335),  INT16_C( 18868), -INT16_C( 16780),  INT16_C(  5528),  INT16_C(  3964),
         INT16_C(  1568),  INT16_C( 27063),  INT16_C( 32646), -INT16_C(   873),  INT16_C( 30000), -INT16_C( 29227), -INT16_C( 30945),  INT16_C( 18756) },
      UINT16_C( 1028) },
    { UINT16_C(34170),
      { -INT16_C(  5520),  INT16_C(  2243), -INT16_C(  2842), -INT16_C( 17539), -INT16_C( 25471), -INT16_C( 15037), -INT16_C( 20507), -INT16_C(  1092),
         INT16_C( 11201),  INT16_C(  8088),  INT16_C( 32335),  INT16_C( 12528), -INT16_C( 10244), -INT16_C( 30322), -INT16_C(  3361),  INT16_C( 20430) },
      { -INT16_C( 28196), -INT16_C( 15785), -INT16_C( 10875), -INT16_C( 17539), -INT16_C( 25471), -INT16_C( 15037), -INT16_C( 30864),  INT16_C( 12882),
        -INT16_C(  5197),  INT16_C(   593),  INT16_C( 32335),  INT16_C( 26162), -INT16_C( 16103), -INT16_C(  1809), -INT16_C(  3361), -INT16_C( 28601) },
      UINT16_C( 1080) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__mmask16 k = test_vec[i].k;
    simde__m256i a = simde_mm256_loadu_epi16(test_vec[i].a);
    simde__m256i b = simde_mm256_loadu_epi16(test_vec[i].b);
    simde__mmask16 r = simde_mm256_mask_cmple_epi16_mask(k, a, b);
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
    simde__mmask16 r = simde_mm256_mask_cmple_epi16_mask(k, a, b);

    simde_test_x86_write_mmask16(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i16x16(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_x_mm512_cmple_epi16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int16_t a[32];
    const int16_t b[32];
    const int16_t r[32];
  } test_vec[] = {
    { { -INT16_C( 17255), -INT16_C( 13274),  INT16_C( 27911), -INT16_C( 19235),  INT16_C( 30621),  INT16_C(  2030), -INT16_C( 12944), -INT16_C( 12254),
        -INT16_C(  5198),  INT16_C( 24643), -INT16_C(  6055),  INT16_C( 29560),  INT16_C(   864),  INT16_C(  5710),  INT16_C(   532), -INT16_C( 21006),
         INT16_C(  6334), -INT16_C( 14726),  INT16_C( 22405),  INT16_C(  8826),  INT16_C( 27086),  INT16_C( 15914),  INT16_C( 19510), -INT16_C(  5873),
         INT16_C( 21047), -INT16_C( 28599), -INT16_C( 15813), -INT16_C( 25853),  INT16_C( 20933), -INT16_C(  9807), -INT16_C( 23725),  INT16_C(  4743) },
      {  INT16_C(   443), -INT16_C( 13274),  INT16_C( 21080), -INT16_C( 19235),  INT16_C( 30621), -INT16_C(  3483),  INT16_C( 29913), -INT16_C( 12254),
         INT16_C(  9415),  INT16_C(   672), -INT16_C( 23578),  INT16_C( 29560),  INT16_C( 20213),  INT16_C( 18565),  INT16_C(  3313), -INT16_C( 21414),
         INT16_C( 12813),  INT16_C( 26348),  INT16_C( 20357),  INT16_C( 16525), -INT16_C(  3364),  INT16_C( 15914),  INT16_C( 19510),  INT16_C( 11973),
         INT16_C( 25906),  INT16_C(  6192), -INT16_C( 13047), -INT16_C( 25853),  INT16_C( 18971),  INT16_C(  3142), -INT16_C( 23725),  INT16_C( 25784) },
      { -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),
        -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
        -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),
        -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1) } },
    { { -INT16_C( 18849),  INT16_C( 21451),  INT16_C( 25613),  INT16_C( 22307), -INT16_C( 22224),  INT16_C(  2311), -INT16_C(  6411), -INT16_C( 23020),
         INT16_C( 14324), -INT16_C( 12192),  INT16_C(  6175),  INT16_C( 20934), -INT16_C( 14058), -INT16_C( 18726), -INT16_C( 14717), -INT16_C(  7639),
        -INT16_C(  2947), -INT16_C( 30155),  INT16_C( 22873), -INT16_C( 30239), -INT16_C(  5886), -INT16_C(  2158), -INT16_C( 22833), -INT16_C( 15459),
        -INT16_C(   547), -INT16_C(   621),  INT16_C( 23061),  INT16_C( 11342),  INT16_C( 10275), -INT16_C( 22814),  INT16_C(  3055),  INT16_C( 27785) },
      { -INT16_C( 16641),  INT16_C( 22774), -INT16_C( 10217),  INT16_C(  6881),  INT16_C( 29633), -INT16_C( 28655), -INT16_C(  6411), -INT16_C(  2221),
        -INT16_C(  6228), -INT16_C( 15628),  INT16_C( 16961),  INT16_C( 25838), -INT16_C( 12181),  INT16_C( 23050), -INT16_C( 27685), -INT16_C(  9530),
        -INT16_C(  2947),  INT16_C( 26931),  INT16_C( 22873),  INT16_C( 21891), -INT16_C( 27256), -INT16_C( 24091),  INT16_C( 14660), -INT16_C(  3944),
        -INT16_C(   547),  INT16_C( 25010), -INT16_C( 24369),  INT16_C( 15045), -INT16_C( 12432), -INT16_C( 22814),  INT16_C(  3055), -INT16_C( 19162) },
      { -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),
         INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
        -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),
        -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0) } },
    { {  INT16_C( 27641),  INT16_C( 26484),  INT16_C( 29965),  INT16_C( 17500), -INT16_C(  3237),  INT16_C( 31423),  INT16_C( 10787), -INT16_C(  8263),
         INT16_C( 22856),  INT16_C(  1898),  INT16_C( 12222), -INT16_C(  3530), -INT16_C( 20344),  INT16_C( 15242), -INT16_C( 10671),  INT16_C( 18948),
         INT16_C( 31041),  INT16_C( 20145),  INT16_C(  3822),  INT16_C( 18834),  INT16_C( 20737),  INT16_C(  9411),  INT16_C( 31868), -INT16_C( 15357),
         INT16_C( 28117), -INT16_C( 27701),  INT16_C(   412),  INT16_C(  9349),  INT16_C(  4018),  INT16_C(   863),  INT16_C( 25830),  INT16_C( 10061) },
      { -INT16_C(    35), -INT16_C( 13450),  INT16_C(  2061),  INT16_C(  3604), -INT16_C( 10406), -INT16_C( 10701),  INT16_C( 13907),  INT16_C( 10394),
         INT16_C( 26276),  INT16_C( 16571),  INT16_C( 16487),  INT16_C(  6501), -INT16_C( 15280),  INT16_C( 13852),  INT16_C( 27176),  INT16_C(  1373),
        -INT16_C( 11415),  INT16_C( 30416), -INT16_C(  6948),  INT16_C( 13956), -INT16_C( 18501),  INT16_C(  3596), -INT16_C( 22802), -INT16_C( 28106),
        -INT16_C(  3828),  INT16_C( 29906),  INT16_C( 14130), -INT16_C( 32115), -INT16_C( 21764),  INT16_C(  9400),  INT16_C(  5396),  INT16_C( 32042) },
      {  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),
        -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
         INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
         INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1) } },
    { { -INT16_C(  5634), -INT16_C(  8960), -INT16_C(  1183), -INT16_C( 28553),  INT16_C(  8194), -INT16_C( 20307),  INT16_C( 23552), -INT16_C( 11926),
        -INT16_C( 26403), -INT16_C( 26924),  INT16_C( 22867), -INT16_C( 18101),  INT16_C(  9622), -INT16_C(  6094),  INT16_C( 10536),  INT16_C(  9764),
         INT16_C(  9234),  INT16_C( 29443),  INT16_C( 31520),  INT16_C(  8707), -INT16_C( 20325), -INT16_C( 25646),  INT16_C( 15372), -INT16_C(  5524),
         INT16_C( 16596),  INT16_C( 10368), -INT16_C( 13159),  INT16_C( 12257),  INT16_C(  5105),  INT16_C(  6424),  INT16_C( 15420),  INT16_C( 20288) },
      {  INT16_C( 17248), -INT16_C( 32574), -INT16_C(  1183), -INT16_C( 28553),  INT16_C(  8194), -INT16_C( 20307),  INT16_C( 25266), -INT16_C( 31123),
        -INT16_C(  4702),  INT16_C( 15534),  INT16_C( 22867), -INT16_C( 21909),  INT16_C(  9622), -INT16_C(  8252),  INT16_C(  1215),  INT16_C(  8238),
        -INT16_C(  3769),  INT16_C(  1696),  INT16_C( 17335),  INT16_C( 11616),  INT16_C( 21945),  INT16_C( 27568),  INT16_C( 15372), -INT16_C(  5524),
        -INT16_C( 24565), -INT16_C( 15210), -INT16_C( 13159),  INT16_C( 12257),  INT16_C( 13189),  INT16_C( 17586), -INT16_C(  8137),  INT16_C( 20288) },
      { -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
        -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
         INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),
         INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1) } },
    { {  INT16_C( 12054),  INT16_C( 24300), -INT16_C( 24044),  INT16_C( 20064), -INT16_C( 13303), -INT16_C( 29377), -INT16_C( 29910),  INT16_C( 10268),
         INT16_C( 28524),  INT16_C( 20310),  INT16_C( 22066),  INT16_C( 10167),  INT16_C( 25608), -INT16_C( 26028), -INT16_C(   139), -INT16_C( 29698),
        -INT16_C(  5330),  INT16_C( 17129),  INT16_C( 18829), -INT16_C( 26992), -INT16_C( 12266),  INT16_C( 16419),  INT16_C( 16219), -INT16_C( 14487),
        -INT16_C( 16465), -INT16_C(  7913), -INT16_C( 12779),  INT16_C(  7432),  INT16_C( 23602), -INT16_C( 22601), -INT16_C( 18853), -INT16_C( 30158) },
      {  INT16_C(  7329),  INT16_C( 11980), -INT16_C( 24044),  INT16_C( 31685), -INT16_C(  6099), -INT16_C( 30532), -INT16_C( 29910), -INT16_C( 10417),
         INT16_C( 26340), -INT16_C(  1608),  INT16_C( 22066),  INT16_C( 26390), -INT16_C( 13027),  INT16_C( 30735), -INT16_C(   139), -INT16_C( 29698),
        -INT16_C( 12451), -INT16_C( 15533),  INT16_C( 18829),  INT16_C( 22846), -INT16_C(  1536),  INT16_C( 16419),  INT16_C( 16219),  INT16_C(  1023),
        -INT16_C( 18537), -INT16_C( 13060),  INT16_C(  4728), -INT16_C( 27341),  INT16_C( 17120),  INT16_C( 25357), -INT16_C( 18853), -INT16_C( 30158) },
      {  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
         INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),
         INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),
         INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1) } },
    { {  INT16_C( 22710), -INT16_C( 22041),  INT16_C( 19259),  INT16_C(  6556), -INT16_C( 18288),  INT16_C(  1558),  INT16_C(  5844), -INT16_C( 22766),
        -INT16_C(  5357),  INT16_C(  9202), -INT16_C( 11529),  INT16_C( 17682),  INT16_C( 26047), -INT16_C( 17128), -INT16_C( 13248), -INT16_C(  2407),
        -INT16_C( 32476),  INT16_C( 24735),  INT16_C( 15564),  INT16_C( 23929), -INT16_C( 28684), -INT16_C( 14237),  INT16_C( 30117), -INT16_C( 18065),
         INT16_C( 24928),  INT16_C( 22492), -INT16_C(  4557), -INT16_C(  3171), -INT16_C( 19116), -INT16_C( 27472),  INT16_C( 18817), -INT16_C( 23157) },
      {  INT16_C( 10954), -INT16_C( 22041),  INT16_C( 32358),  INT16_C( 23540),  INT16_C( 22285), -INT16_C( 19677), -INT16_C( 27700),  INT16_C( 11628),
         INT16_C( 18676),  INT16_C( 10372),  INT16_C(  8502), -INT16_C( 30181),  INT16_C( 26047),  INT16_C( 22303), -INT16_C( 13248), -INT16_C(  8195),
         INT16_C(   724),  INT16_C( 15222),  INT16_C( 27265), -INT16_C( 29034), -INT16_C( 17983), -INT16_C( 14237), -INT16_C( 21172), -INT16_C( 18065),
         INT16_C( 16373),  INT16_C( 22492), -INT16_C( 31648),  INT16_C( 14262), -INT16_C( 19116),  INT16_C( 25486), -INT16_C( 29825),  INT16_C( 21570) },
      {  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
        -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
        -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
         INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1) } },
    { { -INT16_C( 25594),  INT16_C( 10681),  INT16_C( 22209), -INT16_C( 24564),  INT16_C( 32053), -INT16_C( 15669),  INT16_C( 14249),  INT16_C(  4932),
        -INT16_C(  3572),  INT16_C( 26078), -INT16_C(  8106), -INT16_C( 28659),  INT16_C(  6257), -INT16_C( 29366),  INT16_C( 22374),  INT16_C( 27959),
        -INT16_C(  3852), -INT16_C( 19050), -INT16_C( 23994),  INT16_C( 31829),  INT16_C(  8224), -INT16_C( 14018), -INT16_C( 32169),  INT16_C( 25564),
        -INT16_C( 17548), -INT16_C( 13624), -INT16_C( 10853),  INT16_C(  3163), -INT16_C( 23058),  INT16_C( 21657), -INT16_C( 12036), -INT16_C(  3903) },
      {  INT16_C( 22464),  INT16_C(  1958), -INT16_C(  1030),  INT16_C(  6787), -INT16_C( 16100),  INT16_C( 29667), -INT16_C( 16573), -INT16_C( 18473),
        -INT16_C( 24710),  INT16_C(  5761), -INT16_C(  9099), -INT16_C( 28659),  INT16_C(  6257),  INT16_C( 32439),  INT16_C( 31116),  INT16_C( 19822),
         INT16_C(  5328), -INT16_C( 13740), -INT16_C( 10480),  INT16_C( 11492), -INT16_C( 14440), -INT16_C(  9313), -INT16_C( 32169),  INT16_C(   402),
         INT16_C(  4886), -INT16_C( 13624), -INT16_C( 10853),  INT16_C( 29166), -INT16_C( 23050), -INT16_C( 32017),  INT16_C( 24094), -INT16_C(  3903) },
      { -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
         INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
        -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
        -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1) } },
    { { -INT16_C( 16213), -INT16_C( 23113),  INT16_C( 25950), -INT16_C( 15560), -INT16_C( 23117),  INT16_C( 30896), -INT16_C( 24923), -INT16_C( 18350),
        -INT16_C( 18269), -INT16_C(  7237),  INT16_C( 12043),  INT16_C(  1048), -INT16_C( 12141),  INT16_C( 21788),  INT16_C(  8792),  INT16_C(   906),
         INT16_C( 16866),  INT16_C( 16552), -INT16_C(  8026),  INT16_C( 23044), -INT16_C( 19322),  INT16_C( 11218),  INT16_C(  9298), -INT16_C(  2589),
        -INT16_C( 24868), -INT16_C(  5928), -INT16_C(  3635),  INT16_C( 25068),  INT16_C(  2241),  INT16_C(  6582),  INT16_C( 16427),  INT16_C(  3356) },
      { -INT16_C( 14975),  INT16_C( 10318),  INT16_C( 25950),  INT16_C( 11138),  INT16_C( 21510),  INT16_C( 22614),  INT16_C( 14712),  INT16_C( 21837),
        -INT16_C( 18269), -INT16_C( 23235),  INT16_C( 10519),  INT16_C(  1048), -INT16_C( 12141),  INT16_C( 24050),  INT16_C(  8792),  INT16_C(   906),
         INT16_C( 16866),  INT16_C( 31142),  INT16_C( 10250),  INT16_C(  4260), -INT16_C( 19322), -INT16_C(  2712), -INT16_C( 18892), -INT16_C(  2589),
        -INT16_C( 24868), -INT16_C(  3151), -INT16_C(  3635),  INT16_C( 25068), -INT16_C( 17037),  INT16_C( 28735), -INT16_C( 21812), -INT16_C( 24593) },
      { -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),
        -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),
        -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
        -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i a = simde_mm512_loadu_epi16(test_vec[i].a);
    simde__m512i b = simde_mm512_loadu_epi16(test_vec[i].b);
    simde__m512i r = simde_x_mm512_cmple_epi16(a, b);
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
    simde__m512i r = simde_x_mm512_cmple_epi16(a, b);

    simde_test_x86_write_i16x32(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i16x32(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_cmple_epi16_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int16_t a[32];
    const int16_t b[32];
    const simde__mmask32 r;
  } test_vec[] = {
    { {  INT16_C( 28394), -INT16_C( 30373),  INT16_C( 10147), -INT16_C(  7093),  INT16_C( 24378), -INT16_C( 30044), -INT16_C( 29728), -INT16_C(  1671),
        -INT16_C( 14564),  INT16_C( 21041), -INT16_C( 25563),  INT16_C( 18984), -INT16_C( 17571), -INT16_C(  7628),  INT16_C( 20075),  INT16_C( 22150),
        -INT16_C(  7492),  INT16_C( 24799),  INT16_C( 11017),  INT16_C( 17476), -INT16_C(  6006),  INT16_C( 27598),  INT16_C( 18547), -INT16_C( 28828),
        -INT16_C( 27121),  INT16_C( 13538),  INT16_C(  2610), -INT16_C( 28801), -INT16_C( 19515),  INT16_C( 12401), -INT16_C(  2047), -INT16_C( 17018) },
      {  INT16_C( 26330), -INT16_C(  7395),  INT16_C( 25233),  INT16_C(  6951),  INT16_C( 24378), -INT16_C( 16762), -INT16_C(  5314),  INT16_C( 19789),
         INT16_C( 12161), -INT16_C( 19583),  INT16_C(    57), -INT16_C(   445), -INT16_C( 19277), -INT16_C( 19409), -INT16_C( 19028),  INT16_C( 22150),
        -INT16_C( 28901),  INT16_C( 24799),  INT16_C( 11017),  INT16_C( 17476),  INT16_C( 20103), -INT16_C( 14854),  INT16_C( 18547), -INT16_C( 17902),
        -INT16_C( 27529),  INT16_C( 13538),  INT16_C(  2610),  INT16_C( 18607), -INT16_C(  8603),  INT16_C(  4860), -INT16_C(  2047), -INT16_C( 20584) },
      UINT32_C(1591641598) },
    { { -INT16_C( 16489),  INT16_C( 11196), -INT16_C(  5917),  INT16_C( 21831),  INT16_C( 10253),  INT16_C( 31232),  INT16_C( 26139), -INT16_C( 23714),
        -INT16_C(  3270), -INT16_C( 16449),  INT16_C(  9014),  INT16_C( 22698), -INT16_C( 22909),  INT16_C( 21005),  INT16_C( 28987), -INT16_C( 11489),
        -INT16_C(  9168),  INT16_C(  5118),  INT16_C( 17860), -INT16_C( 11928),  INT16_C( 26989), -INT16_C( 30388), -INT16_C( 21809),  INT16_C(  2604),
        -INT16_C(  5219), -INT16_C( 11063),  INT16_C( 29454), -INT16_C( 28372),  INT16_C( 14618),  INT16_C( 21988),  INT16_C(   938), -INT16_C(  9688) },
      {  INT16_C( 10207),  INT16_C( 11196),  INT16_C( 22124),  INT16_C( 21831), -INT16_C( 15937),  INT16_C( 31232), -INT16_C( 28821),  INT16_C(  2457),
         INT16_C( 25210), -INT16_C( 16449),  INT16_C(  9014),  INT16_C( 22698), -INT16_C(   702), -INT16_C(  5051),  INT16_C( 28987), -INT16_C( 11489),
        -INT16_C( 19307),  INT16_C(   388), -INT16_C(  1781), -INT16_C( 13605),  INT16_C( 26989),  INT16_C(  9561), -INT16_C(  3379),  INT16_C( 18222),
         INT16_C(  2901), -INT16_C( 11063), -INT16_C(  5868),  INT16_C( 22043),  INT16_C( 24806), -INT16_C(  6334),  INT16_C(   938),  INT16_C( 25544) },
      UINT32_C(3689996207) },
    { {  INT16_C( 28974),  INT16_C( 29595),  INT16_C( 11954),  INT16_C( 12658), -INT16_C( 26854), -INT16_C(  1667),  INT16_C(  4586),  INT16_C( 18477),
        -INT16_C( 29579), -INT16_C( 15941), -INT16_C( 31482), -INT16_C(  7692),  INT16_C(  3985), -INT16_C( 22902), -INT16_C( 26895),  INT16_C(  8312),
         INT16_C(  4872), -INT16_C( 17773),  INT16_C(  1601),  INT16_C( 23787),  INT16_C( 26781), -INT16_C( 30891), -INT16_C( 31878), -INT16_C(  4145),
        -INT16_C( 29937),  INT16_C(  5808), -INT16_C( 23280), -INT16_C( 24073), -INT16_C( 32332), -INT16_C( 23225), -INT16_C( 16617),  INT16_C(  8133) },
      {  INT16_C( 22995),  INT16_C( 29595),  INT16_C( 11954), -INT16_C(   912), -INT16_C( 14803), -INT16_C( 22653),  INT16_C( 21065),  INT16_C( 18477),
        -INT16_C( 29579), -INT16_C(  4754), -INT16_C( 31482), -INT16_C(  7692), -INT16_C( 10778), -INT16_C(   443),  INT16_C(  2709),  INT16_C( 26653),
         INT16_C(  4872), -INT16_C( 15748), -INT16_C(  4677),  INT16_C( 23787),  INT16_C( 16819), -INT16_C(   881),  INT16_C(  9620),  INT16_C( 29012),
        -INT16_C( 15508),  INT16_C(  5808), -INT16_C(  4824),  INT16_C(  4087),  INT16_C( 15555),  INT16_C( 22541),  INT16_C( 10822),  INT16_C(  8133) },
      UINT32_C(4293652438) },
    { { -INT16_C( 12586), -INT16_C(   163),  INT16_C(  9209),  INT16_C( 26076), -INT16_C( 19336), -INT16_C(  3482), -INT16_C( 10015), -INT16_C( 11815),
         INT16_C(  6057),  INT16_C( 26602),  INT16_C(  4428), -INT16_C( 16919), -INT16_C( 15802), -INT16_C( 23180), -INT16_C( 10660),  INT16_C( 12837),
        -INT16_C( 31836), -INT16_C( 25295),  INT16_C(  3494),  INT16_C(  7682),  INT16_C( 26818), -INT16_C( 23792), -INT16_C(  5824), -INT16_C(  5771),
         INT16_C( 24320),  INT16_C( 19537),  INT16_C( 14960), -INT16_C( 18935),  INT16_C( 32508),  INT16_C( 22619), -INT16_C( 32428), -INT16_C(  1910) },
      { -INT16_C( 12586), -INT16_C(   163),  INT16_C(  9209), -INT16_C( 29752), -INT16_C( 19336),  INT16_C( 16431), -INT16_C( 23358), -INT16_C( 15830),
         INT16_C( 31491),  INT16_C( 29455),  INT16_C(  4428), -INT16_C( 20182), -INT16_C( 31338), -INT16_C(  5622), -INT16_C( 27642),  INT16_C(  2786),
         INT16_C( 30544),  INT16_C(  6836),  INT16_C( 31759),  INT16_C(  4005), -INT16_C( 11179), -INT16_C( 23792),  INT16_C( 31096), -INT16_C(  5771),
        -INT16_C(  5900), -INT16_C( 22033),  INT16_C(  6401), -INT16_C( 26789),  INT16_C( 26014), -INT16_C( 23166), -INT16_C( 32428),  INT16_C( 19119) },
      UINT32_C(3236374327) },
    { { -INT16_C( 14287),  INT16_C(  4436),  INT16_C( 20178), -INT16_C( 20409), -INT16_C( 27752),  INT16_C( 23302), -INT16_C( 10055), -INT16_C( 14318),
         INT16_C( 29593),  INT16_C( 29655),  INT16_C( 32303),  INT16_C( 20716),  INT16_C(  2471),  INT16_C( 13675), -INT16_C( 12330),  INT16_C(  1950),
        -INT16_C(  3176),  INT16_C( 27161),  INT16_C( 24641), -INT16_C(  9958),  INT16_C(  8435), -INT16_C( 21196),  INT16_C( 18425), -INT16_C( 28043),
         INT16_C( 19642), -INT16_C(  5626), -INT16_C(  3381),  INT16_C( 29242), -INT16_C( 23045), -INT16_C( 11609),  INT16_C( 18037),  INT16_C(  3545) },
      { -INT16_C(  3527),  INT16_C(  4436), -INT16_C( 28334),  INT16_C( 18004), -INT16_C( 30543),  INT16_C( 23302),  INT16_C( 26831), -INT16_C( 30147),
         INT16_C( 17332),  INT16_C( 32628), -INT16_C( 20939),  INT16_C( 20716), -INT16_C( 26284), -INT16_C( 14078), -INT16_C(  8993),  INT16_C(  1950),
        -INT16_C(  3176),  INT16_C(  8595), -INT16_C(  6178), -INT16_C( 28825),  INT16_C( 23151),  INT16_C( 16186),  INT16_C( 30658),  INT16_C( 30409),
         INT16_C( 19642), -INT16_C(  4106), -INT16_C(  5909),  INT16_C( 16159),  INT16_C(  8833),  INT16_C( 24840), -INT16_C(  8450), -INT16_C( 13191) },
      UINT32_C( 871484011) },
    { { -INT16_C(  5075),  INT16_C(  8687), -INT16_C( 30655), -INT16_C(  4220),  INT16_C(  9819), -INT16_C( 23200),  INT16_C( 18321),  INT16_C( 14761),
        -INT16_C( 25564), -INT16_C(  5684), -INT16_C( 24658), -INT16_C(  7377), -INT16_C( 10373),  INT16_C( 13589),  INT16_C(  5368),  INT16_C(  9498),
         INT16_C(  2305),  INT16_C( 16966), -INT16_C( 13679), -INT16_C(  5071), -INT16_C( 28176), -INT16_C( 32367),  INT16_C( 15064), -INT16_C(   838),
        -INT16_C( 30762), -INT16_C( 31259),  INT16_C(  5414), -INT16_C( 24216),  INT16_C( 32236), -INT16_C(  6954), -INT16_C(  3694), -INT16_C( 27895) },
      {  INT16_C( 20730),  INT16_C(  8687),  INT16_C(  1562),  INT16_C(  2936),  INT16_C(  2712), -INT16_C( 23200),  INT16_C( 18244),  INT16_C(  7021),
         INT16_C( 21198), -INT16_C(  2912),  INT16_C(  2151),  INT16_C( 21398),  INT16_C( 27781),  INT16_C( 13589),  INT16_C( 16733),  INT16_C( 22698),
         INT16_C( 32657), -INT16_C( 21532),  INT16_C( 23686), -INT16_C(  5071), -INT16_C( 28176), -INT16_C( 21618),  INT16_C( 15064),  INT16_C( 22726),
        -INT16_C( 30762), -INT16_C( 19124),  INT16_C(  5414), -INT16_C(  3319),  INT16_C( 32236), -INT16_C(  6954), -INT16_C(  3694),  INT16_C(  4612) },
      UINT32_C(4294836015) },
    { {  INT16_C(   689), -INT16_C(  2412),  INT16_C( 28022),  INT16_C( 11937), -INT16_C(  1835),  INT16_C( 14447),  INT16_C(  2324), -INT16_C( 26647),
         INT16_C( 20463), -INT16_C( 18553),  INT16_C( 27583),  INT16_C( 28623), -INT16_C( 27814), -INT16_C(    96), -INT16_C(  7077),  INT16_C(  3288),
         INT16_C( 28134),  INT16_C( 23810), -INT16_C( 23334), -INT16_C( 20597), -INT16_C(  1380), -INT16_C( 20249), -INT16_C( 12285), -INT16_C(  3513),
        -INT16_C( 12512), -INT16_C(  8278),  INT16_C( 31034), -INT16_C( 27314), -INT16_C(  4596),  INT16_C( 26516),  INT16_C( 27859), -INT16_C( 18060) },
      {  INT16_C( 30425), -INT16_C(  2412),  INT16_C( 28022), -INT16_C( 18845),  INT16_C( 19356),  INT16_C( 14447), -INT16_C( 20965), -INT16_C( 26647),
         INT16_C( 15485), -INT16_C( 18553),  INT16_C( 26805), -INT16_C( 16051), -INT16_C(  7849),  INT16_C( 10792), -INT16_C(  7077),  INT16_C( 10211),
        -INT16_C(  1517),  INT16_C( 11739), -INT16_C( 23334), -INT16_C( 20597),  INT16_C( 19337), -INT16_C( 23081),  INT16_C( 27129), -INT16_C(  3513),
        -INT16_C(  1115),  INT16_C( 23087),  INT16_C( 31843), -INT16_C( 17893),  INT16_C( 17245),  INT16_C( 26516), -INT16_C( 14112), -INT16_C(  3119) },
      UINT32_C(3218928311) },
    { {  INT16_C(  9968), -INT16_C(  9249),  INT16_C( 29738),  INT16_C( 31312),  INT16_C( 27104), -INT16_C( 19005), -INT16_C( 31901),  INT16_C( 22575),
         INT16_C(   882), -INT16_C(  8783), -INT16_C( 15118),  INT16_C(  9381),  INT16_C(  6075),  INT16_C( 31543),  INT16_C( 15451),  INT16_C( 19708),
        -INT16_C(  9374), -INT16_C( 29401),  INT16_C( 30543),  INT16_C( 12039), -INT16_C( 13599),  INT16_C( 17636),  INT16_C(  4941), -INT16_C( 16483),
         INT16_C( 19990),  INT16_C(  2204),  INT16_C( 16658), -INT16_C( 13011),  INT16_C( 25688), -INT16_C( 19384),  INT16_C( 17824),  INT16_C(   768) },
      {  INT16_C( 10016),  INT16_C( 28816), -INT16_C( 26721), -INT16_C( 32609), -INT16_C( 31647), -INT16_C( 19005),  INT16_C( 24983), -INT16_C( 20883),
         INT16_C(  2479), -INT16_C( 15946), -INT16_C(  7350), -INT16_C( 23921), -INT16_C( 10425),  INT16_C( 31543),  INT16_C( 22044),  INT16_C( 19708),
        -INT16_C(  9374),  INT16_C(  7597),  INT16_C( 19474),  INT16_C( 12039),  INT16_C( 25040),  INT16_C( 26657),  INT16_C(  4941),  INT16_C( 29206),
        -INT16_C( 13161), -INT16_C(  7884),  INT16_C( 16658), -INT16_C(  2173), -INT16_C(  9574), -INT16_C( 19384), -INT16_C( 13776), -INT16_C( 20748) },
      UINT32_C( 754705763) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i a = simde_mm512_loadu_epi16(test_vec[i].a);
    simde__m512i b = simde_mm512_loadu_epi16(test_vec[i].b);
    simde__mmask32 r = simde_mm512_cmple_epi16_mask(a, b);
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
    simde__mmask32 r = simde_mm512_cmple_epi16_mask(a, b);

    simde_test_x86_write_i16x32(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i16x32(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_mask_cmple_epi16_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask32 k;
    const int16_t a[32];
    const int16_t b[32];
    const simde__mmask32 r;
  } test_vec[] = {
    { UINT32_C(3487573020),
      {  INT16_C( 19009), -INT16_C( 31458),  INT16_C( 10183),  INT16_C( 17386), -INT16_C( 28179),  INT16_C( 27957), -INT16_C(  2712),  INT16_C(  8718),
        -INT16_C( 12068), -INT16_C( 11739),  INT16_C( 29958), -INT16_C( 25959),  INT16_C(  3489), -INT16_C(  9246), -INT16_C( 30169),  INT16_C( 26739),
        -INT16_C( 27948), -INT16_C( 25363), -INT16_C( 10311), -INT16_C( 22561),  INT16_C(  5224), -INT16_C( 12268),  INT16_C(  8970), -INT16_C(  6413),
         INT16_C(  6387), -INT16_C(  1608),  INT16_C( 20878),  INT16_C( 12180),  INT16_C( 30302), -INT16_C( 31478),  INT16_C( 32256), -INT16_C( 10771) },
      {  INT16_C( 19009), -INT16_C( 13967),  INT16_C( 20658),  INT16_C(  6768), -INT16_C( 31388),  INT16_C( 28395), -INT16_C(  8536), -INT16_C( 25771),
         INT16_C(  3574), -INT16_C( 11739),  INT16_C( 10335), -INT16_C( 16972), -INT16_C( 16737), -INT16_C( 24765), -INT16_C( 30169),  INT16_C( 26739),
        -INT16_C( 27948), -INT16_C( 25363), -INT16_C( 31179), -INT16_C( 25897), -INT16_C( 15861), -INT16_C( 19704),  INT16_C( 23968), -INT16_C( 26802),
         INT16_C(  6387), -INT16_C(  1608),  INT16_C( 20878), -INT16_C( 21881), -INT16_C( 13682), -INT16_C( 13750), -INT16_C( 16645),  INT16_C(  1559) },
      UINT32_C(2269118468) },
    { UINT32_C(2023714366),
      {  INT16_C( 21439),  INT16_C(  7310),  INT16_C(   463), -INT16_C( 22247), -INT16_C( 20798),  INT16_C( 26349), -INT16_C(   930), -INT16_C(  8939),
         INT16_C( 28562), -INT16_C(  3349), -INT16_C( 15597),  INT16_C( 30286), -INT16_C( 20558), -INT16_C( 12676),  INT16_C( 23764), -INT16_C( 27747),
         INT16_C( 11440),  INT16_C( 32687), -INT16_C( 14291), -INT16_C(  4312),  INT16_C(  5750), -INT16_C( 11179),  INT16_C( 27154), -INT16_C( 23374),
        -INT16_C( 25126), -INT16_C(  4714), -INT16_C(  7072),  INT16_C(  4707), -INT16_C(  8044),  INT16_C( 26848),  INT16_C( 32060), -INT16_C(  4869) },
      { -INT16_C( 21847),  INT16_C(  7310),  INT16_C(   463), -INT16_C( 22247),  INT16_C(  6826),  INT16_C( 26349), -INT16_C(   930),  INT16_C( 24416),
        -INT16_C(  2292),  INT16_C( 27724), -INT16_C( 20261),  INT16_C( 28542),  INT16_C( 24208), -INT16_C( 13097),  INT16_C( 23764), -INT16_C( 31303),
         INT16_C(  9596), -INT16_C(  4260),  INT16_C(  8633), -INT16_C(  4312), -INT16_C( 27332), -INT16_C( 11179),  INT16_C( 27154),  INT16_C(  4384),
         INT16_C( 27768),  INT16_C( 21374), -INT16_C(   996),  INT16_C(  4707), -INT16_C( 26021),  INT16_C( 14201),  INT16_C( 12909), -INT16_C(  5700) },
      UINT32_C( 143409726) },
    { UINT32_C(2166809694),
      {  INT16_C(  4894),  INT16_C( 25838),  INT16_C(  9640), -INT16_C( 16721),  INT16_C(  3196),  INT16_C( 16204),  INT16_C( 12006), -INT16_C( 17121),
        -INT16_C( 21294),  INT16_C(  4591),  INT16_C( 22705), -INT16_C(  5699),  INT16_C( 21374), -INT16_C( 17289),  INT16_C(  5825), -INT16_C(  8396),
         INT16_C(  8746), -INT16_C( 11708), -INT16_C(  3257), -INT16_C( 15471), -INT16_C(  8705), -INT16_C(  6654),  INT16_C(  8715), -INT16_C(  8541),
        -INT16_C( 27698),  INT16_C( 32751), -INT16_C( 21013),  INT16_C( 26984), -INT16_C(  8192), -INT16_C( 16091),  INT16_C( 23030),  INT16_C(  8352) },
      {  INT16_C(  4894),  INT16_C( 25838), -INT16_C( 31528), -INT16_C( 10363), -INT16_C( 30623),  INT16_C( 28093),  INT16_C( 25002),  INT16_C( 30795),
         INT16_C( 15092), -INT16_C(  8201),  INT16_C( 22705), -INT16_C(  5699),  INT16_C( 28224),  INT16_C( 13992),  INT16_C(  5825), -INT16_C(  8396),
         INT16_C( 18989),  INT16_C(  1286), -INT16_C( 29746), -INT16_C( 15471), -INT16_C( 26093), -INT16_C( 16996), -INT16_C(  6149), -INT16_C(  4299),
        -INT16_C( 27698),  INT16_C( 32751), -INT16_C( 21013), -INT16_C( 12815), -INT16_C( 26234),  INT16_C( 19971),  INT16_C( 23266),  INT16_C(  4242) },
      UINT32_C(  16966730) },
    { UINT32_C(2104968728),
      { -INT16_C( 14122),  INT16_C( 25528), -INT16_C( 21242),  INT16_C( 11500),  INT16_C( 25815),  INT16_C( 11892), -INT16_C( 14677),  INT16_C(  2578),
        -INT16_C( 15608), -INT16_C(  6929),  INT16_C(  9079), -INT16_C( 31069),  INT16_C( 29161),  INT16_C( 18234),  INT16_C( 24661),  INT16_C( 11465),
        -INT16_C( 32472),  INT16_C( 11919),  INT16_C( 31534),  INT16_C(  1371), -INT16_C( 12321), -INT16_C( 30157),  INT16_C( 17813), -INT16_C( 24940),
        -INT16_C( 31736), -INT16_C( 32638),  INT16_C(  9639), -INT16_C( 28410),  INT16_C( 16535), -INT16_C(  4904), -INT16_C( 24160), -INT16_C( 14312) },
      { -INT16_C( 22493),  INT16_C( 20983),  INT16_C( 21027),  INT16_C(   855), -INT16_C( 30175), -INT16_C( 18547),  INT16_C(  8912), -INT16_C( 10155),
        -INT16_C( 10330), -INT16_C(  6929),  INT16_C( 24573), -INT16_C( 27426), -INT16_C( 18529),  INT16_C( 16512), -INT16_C( 26280),  INT16_C( 31496),
        -INT16_C( 32472),  INT16_C( 25805),  INT16_C(  9297),  INT16_C( 29543), -INT16_C(  2642),  INT16_C( 32298),  INT16_C( 32535), -INT16_C( 17065),
        -INT16_C( 20650),  INT16_C( 21258), -INT16_C(  5874), -INT16_C( 20761),  INT16_C( 26784), -INT16_C(  1810), -INT16_C( 24160),  INT16_C( 17012) },
      UINT32_C(2037581312) },
    { UINT32_C( 562661418),
      {  INT16_C( 12628),  INT16_C( 22416),  INT16_C(  8726),  INT16_C( 31089),  INT16_C( 18443), -INT16_C( 23501),  INT16_C( 16682), -INT16_C(  2997),
        -INT16_C( 24522), -INT16_C( 27809), -INT16_C( 15645),  INT16_C(  7409), -INT16_C( 28263), -INT16_C( 20148), -INT16_C( 15401),  INT16_C( 11310),
        -INT16_C( 16652),  INT16_C(  2691), -INT16_C(  2591), -INT16_C(  4988), -INT16_C( 18627),  INT16_C( 26512), -INT16_C(  9224),  INT16_C( 11868),
        -INT16_C( 17541),  INT16_C( 24257), -INT16_C( 19843),  INT16_C(  5755), -INT16_C( 14525),  INT16_C(  7111), -INT16_C(  2678),  INT16_C( 32327) },
      { -INT16_C( 13645),  INT16_C( 22416),  INT16_C(  3519), -INT16_C(   639),  INT16_C(  4548), -INT16_C( 17052), -INT16_C( 16147), -INT16_C(  2997),
        -INT16_C( 21125), -INT16_C( 27809),  INT16_C( 16991), -INT16_C( 23794), -INT16_C( 28263), -INT16_C( 27714),  INT16_C(  1482),  INT16_C( 32273),
        -INT16_C( 25905),  INT16_C(  2691), -INT16_C( 27737),  INT16_C( 27788), -INT16_C( 18627), -INT16_C( 28119),  INT16_C(  5297),  INT16_C( 11514),
        -INT16_C( 15935),  INT16_C(  8485), -INT16_C( 19843),  INT16_C(  5755), -INT16_C( 32247), -INT16_C( 11361), -INT16_C( 20089),  INT16_C( 22097) },
      UINT32_C(  17334306) },
    { UINT32_C(3184469772),
      { -INT16_C(  5895),  INT16_C( 23486), -INT16_C(  5008),  INT16_C(  3438), -INT16_C( 20971),  INT16_C(   107), -INT16_C(  5614), -INT16_C( 21778),
        -INT16_C(  6099), -INT16_C(  3509), -INT16_C( 16254), -INT16_C( 12994), -INT16_C(  8058), -INT16_C( 20380), -INT16_C(  4760),  INT16_C( 25297),
        -INT16_C( 28714),  INT16_C( 18109),  INT16_C( 11388), -INT16_C( 28333), -INT16_C( 16678), -INT16_C(  4975),  INT16_C( 32680), -INT16_C( 10857),
        -INT16_C(  7576), -INT16_C(  5433),  INT16_C(  1442),  INT16_C( 10424),  INT16_C(  7398),  INT16_C( 20184), -INT16_C( 22007), -INT16_C(  8272) },
      {  INT16_C( 28217),  INT16_C( 23486), -INT16_C(  5008),  INT16_C( 29767), -INT16_C( 10184),  INT16_C(   107), -INT16_C(  5614), -INT16_C( 16202),
         INT16_C( 32218), -INT16_C(  3509),  INT16_C( 25219),  INT16_C( 27045),  INT16_C( 32126), -INT16_C( 30537),  INT16_C( 26663),  INT16_C( 25297),
        -INT16_C( 28714),  INT16_C( 28694),  INT16_C( 23815),  INT16_C( 16356),  INT16_C( 17462), -INT16_C( 29153),  INT16_C( 32680),  INT16_C(  5710),
        -INT16_C(  7576), -INT16_C( 10606),  INT16_C( 14171), -INT16_C(  9921), -INT16_C(  2379),  INT16_C( 20184), -INT16_C( 13986),  INT16_C( 13373) },
      UINT32_C(2781808396) },
    { UINT32_C( 452666154),
      {  INT16_C( 27568),  INT16_C( 32165),  INT16_C(  6695), -INT16_C( 18042), -INT16_C( 23074), -INT16_C( 25955),  INT16_C( 22614),  INT16_C( 16305),
        -INT16_C( 24239),  INT16_C( 16861),  INT16_C( 22771),  INT16_C(  3728),  INT16_C(  4880),  INT16_C(  7296),  INT16_C( 20282), -INT16_C(  5415),
         INT16_C( 32442), -INT16_C(  7577), -INT16_C(  4711),  INT16_C( 30619),  INT16_C( 14482), -INT16_C(  5871), -INT16_C( 15728), -INT16_C(  7640),
         INT16_C(  1635),  INT16_C( 22307), -INT16_C( 19618),  INT16_C( 28261), -INT16_C(  6714),  INT16_C(   394),  INT16_C( 25396), -INT16_C(  4117) },
      {  INT16_C( 21474),  INT16_C( 31697),  INT16_C( 27712), -INT16_C( 11278), -INT16_C( 23074),  INT16_C( 13756), -INT16_C(  6971),  INT16_C( 10263),
         INT16_C( 15082),  INT16_C( 18559), -INT16_C(  6674), -INT16_C( 19274),  INT16_C( 16586),  INT16_C(  7296), -INT16_C( 24156), -INT16_C( 30994),
        -INT16_C( 16396), -INT16_C(  7577), -INT16_C(  3285), -INT16_C( 12537), -INT16_C( 15370), -INT16_C( 17660),  INT16_C(  7080), -INT16_C( 27933),
         INT16_C( 25430),  INT16_C( 17627), -INT16_C( 28344),  INT16_C( 28261), -INT16_C( 20782),  INT16_C( 30225), -INT16_C(   177),  INT16_C( 17404) },
      UINT32_C( 138552104) },
    { UINT32_C(  50062793),
      { -INT16_C( 19294), -INT16_C(  7168), -INT16_C( 24207),  INT16_C( 19151),  INT16_C( 19494),  INT16_C(  3449), -INT16_C(  4956), -INT16_C( 29379),
         INT16_C( 32600),  INT16_C( 29001),  INT16_C( 31442),  INT16_C(  9690), -INT16_C( 31320), -INT16_C( 11721),  INT16_C( 12968),  INT16_C( 19181),
        -INT16_C(  4634),  INT16_C( 22319), -INT16_C(   369), -INT16_C( 19038),  INT16_C(  6986), -INT16_C(  4414), -INT16_C(   248),  INT16_C( 24699),
        -INT16_C( 15234),  INT16_C( 20945), -INT16_C( 21697), -INT16_C(  6282), -INT16_C( 21199), -INT16_C(  9799), -INT16_C( 22817), -INT16_C( 15068) },
      {  INT16_C( 21396),  INT16_C(  8989), -INT16_C( 16559), -INT16_C( 25640), -INT16_C( 25894), -INT16_C(  7543), -INT16_C(  4956),  INT16_C(  6210),
         INT16_C( 32600),  INT16_C( 29001),  INT16_C( 31442), -INT16_C(  3857), -INT16_C( 22387),  INT16_C( 28106), -INT16_C(  4529),  INT16_C( 19181),
         INT16_C( 20289), -INT16_C( 28154), -INT16_C(  8690), -INT16_C( 19038),  INT16_C(  6986),  INT16_C(  4811),  INT16_C(  3770), -INT16_C( 31957),
        -INT16_C( 27614), -INT16_C(  7797),  INT16_C( 31348),  INT16_C(   722), -INT16_C( 25565),  INT16_C( 29295), -INT16_C( 22817), -INT16_C( 13483) },
      UINT32_C(   7972289) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__mmask32 k = test_vec[i].k;
    simde__m512i a = simde_mm512_loadu_epi16(test_vec[i].a);
    simde__m512i b = simde_mm512_loadu_epi16(test_vec[i].b);
    simde__mmask32 r = simde_mm512_mask_cmple_epi16_mask(k, a, b);
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
    simde__mmask32 r = simde_mm512_mask_cmple_epi16_mask(k, a, b);

    simde_test_x86_write_mmask32(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i16x32(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x32(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_x_mm_cmple_epu16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const uint16_t a[8];
    const uint16_t b[8];
    const uint16_t r[8];
  } test_vec[] = {
    { { UINT16_C(30921), UINT16_C(34636), UINT16_C(51765), UINT16_C(60865), UINT16_C(61872), UINT16_C(19673), UINT16_C(53866), UINT16_C(27588) },
      { UINT16_C(12155), UINT16_C(56348), UINT16_C(51765), UINT16_C(22960), UINT16_C(62594), UINT16_C(65305), UINT16_C(31016), UINT16_C(61919) },
      { UINT16_C(    0),      UINT16_MAX,      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX, UINT16_C(    0),      UINT16_MAX } },
    { { UINT16_C(60458), UINT16_C(38385), UINT16_C(46526), UINT16_C(14848), UINT16_C( 7396), UINT16_C(18966), UINT16_C(50891), UINT16_C(20131) },
      { UINT16_C(60458), UINT16_C(38385), UINT16_C(46526), UINT16_C(10195), UINT16_C(19288), UINT16_C(18966), UINT16_C(24709), UINT16_C(45043) },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX, UINT16_C(    0),      UINT16_MAX } },
    { { UINT16_C(23392), UINT16_C(11464), UINT16_C(27681), UINT16_C(56186), UINT16_C(50985), UINT16_C(24510), UINT16_C(37364), UINT16_C(19590) },
      { UINT16_C(54237), UINT16_C(25241), UINT16_C(35891), UINT16_C(32529), UINT16_C(22129), UINT16_C( 2954), UINT16_C(53146), UINT16_C(64393) },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),      UINT16_MAX,      UINT16_MAX } },
    { { UINT16_C(58728), UINT16_C(23622), UINT16_C(52342), UINT16_C(21416), UINT16_C(17055), UINT16_C(53941), UINT16_C(51150), UINT16_C(16209) },
      { UINT16_C(56349), UINT16_C(46922), UINT16_C(54443), UINT16_C(21416), UINT16_C(55590), UINT16_C(53941), UINT16_C(18554), UINT16_C(16209) },
      { UINT16_C(    0),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(    0),      UINT16_MAX } },
    { { UINT16_C(44330), UINT16_C(63566), UINT16_C(40820), UINT16_C(37176), UINT16_C(33403), UINT16_C(10056), UINT16_C(64342), UINT16_C(31997) },
      { UINT16_C( 7892), UINT16_C(20320), UINT16_C(40820), UINT16_C(37938), UINT16_C(28988), UINT16_C(10056), UINT16_C(12377), UINT16_C(33685) },
      { UINT16_C(    0), UINT16_C(    0),      UINT16_MAX,      UINT16_MAX, UINT16_C(    0),      UINT16_MAX, UINT16_C(    0),      UINT16_MAX } },
    { { UINT16_C(10806), UINT16_C(36133), UINT16_C( 8741), UINT16_C(64009), UINT16_C(27201), UINT16_C(43081), UINT16_C(31637), UINT16_C(53820) },
      { UINT16_C(30188), UINT16_C(18155), UINT16_C(33189), UINT16_C(33481), UINT16_C(17764), UINT16_C(59347), UINT16_C(46585), UINT16_C(12518) },
      {      UINT16_MAX, UINT16_C(    0),      UINT16_MAX, UINT16_C(    0), UINT16_C(    0),      UINT16_MAX,      UINT16_MAX, UINT16_C(    0) } },
    { { UINT16_C(18480), UINT16_C(50711), UINT16_C(21443), UINT16_C(44952), UINT16_C(33736), UINT16_C(28149), UINT16_C(48900), UINT16_C(27119) },
      { UINT16_C(49668), UINT16_C(65104), UINT16_C(21443), UINT16_C(22318), UINT16_C(60226), UINT16_C(28149), UINT16_C(23473), UINT16_C(58079) },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX, UINT16_C(    0),      UINT16_MAX } },
    { { UINT16_C( 3011), UINT16_C(51327), UINT16_C(28618), UINT16_C(52785), UINT16_C(33073), UINT16_C(43468), UINT16_C(64184), UINT16_C(64000) },
      { UINT16_C( 3011), UINT16_C(38762), UINT16_C(28618), UINT16_C(23161), UINT16_C( 8511), UINT16_C(35008), UINT16_C(54625), UINT16_C( 9370) },
      {      UINT16_MAX, UINT16_C(    0),      UINT16_MAX, UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_x_mm_loadu_epi16(test_vec[i].a);
    simde__m128i b = simde_x_mm_loadu_epi16(test_vec[i].b);
    simde__m128i r = simde_x_mm_cmple_epu16(a, b);
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
    simde__m128i r = simde_x_mm_cmple_epu16(a, b);

    simde_test_x86_write_u16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_u16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_u16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_cmple_epu16_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const uint16_t a[8];
    const uint16_t b[8];
    const simde__mmask8 r;
  } test_vec[] = {
    { { UINT16_C(47626), UINT16_C(19253), UINT16_C(14449), UINT16_C(52020), UINT16_C(13862), UINT16_C(43475), UINT16_C(38363), UINT16_C( 8659) },
      { UINT16_C(40666), UINT16_C(19253), UINT16_C( 6660), UINT16_C(52020), UINT16_C(29643), UINT16_C(38401), UINT16_C(14756), UINT16_C(44627) },
      UINT8_C(154) },
    { { UINT16_C(  612), UINT16_C(16272), UINT16_C(25751), UINT16_C(29024), UINT16_C(57346), UINT16_C( 1675), UINT16_C(23546), UINT16_C(50436) },
      { UINT16_C(  612), UINT16_C(29275), UINT16_C(44607), UINT16_C(12833), UINT16_C( 6711), UINT16_C( 1675), UINT16_C(50504), UINT16_C(44255) },
      UINT8_C(103) },
    { { UINT16_C(23596), UINT16_C( 9947), UINT16_C(57527), UINT16_C(34283), UINT16_C(18406), UINT16_C( 9720), UINT16_C( 6645), UINT16_C(11351) },
      { UINT16_C(60723), UINT16_C(31524), UINT16_C(  946), UINT16_C(31271), UINT16_C( 4979), UINT16_C( 9720), UINT16_C( 6645), UINT16_C(35612) },
      UINT8_C(227) },
    { { UINT16_C(15587), UINT16_C(55778), UINT16_C(14677), UINT16_C(35077), UINT16_C(10790), UINT16_C(55556), UINT16_C(11309), UINT16_C(41043) },
      { UINT16_C(15587), UINT16_C(40679), UINT16_C(  984), UINT16_C(57385), UINT16_C(56058), UINT16_C(55556), UINT16_C(58230), UINT16_C(23183) },
      UINT8_C(121) },
    { { UINT16_C(  866), UINT16_C(37035), UINT16_C(65071), UINT16_C(28208), UINT16_C( 5932), UINT16_C( 1036), UINT16_C(13594), UINT16_C( 5604) },
      { UINT16_C(33551), UINT16_C(34279), UINT16_C(30311), UINT16_C(34783), UINT16_C( 4840), UINT16_C(38140), UINT16_C(64331), UINT16_C(44390) },
      UINT8_C(233) },
    { { UINT16_C(42885), UINT16_C(41024), UINT16_C( 9436), UINT16_C(60341), UINT16_C(40104), UINT16_C( 3952), UINT16_C(20498), UINT16_C(64406) },
      { UINT16_C(37474), UINT16_C(44431), UINT16_C( 9436), UINT16_C(35675), UINT16_C(38918), UINT16_C( 5560), UINT16_C(21254), UINT16_C(35921) },
      UINT8_C(102) },
    { { UINT16_C(12925), UINT16_C(36716), UINT16_C(  642), UINT16_C(58506), UINT16_C( 6549), UINT16_C( 8850), UINT16_C(60686), UINT16_C( 5294) },
      { UINT16_C(26245), UINT16_C(35882), UINT16_C(31674), UINT16_C(58506), UINT16_C(17420), UINT16_C( 8850), UINT16_C(19493), UINT16_C(41503) },
      UINT8_C(189) },
    { { UINT16_C(30677), UINT16_C(58437), UINT16_C(62308), UINT16_C(59896), UINT16_C( 8794), UINT16_C( 5237), UINT16_C(36253), UINT16_C(43464) },
      { UINT16_C(21457), UINT16_C(58437), UINT16_C(35488), UINT16_C( 7832), UINT16_C(51733), UINT16_C( 5237), UINT16_C(36253), UINT16_C(23494) },
      UINT8_C(114) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_x_mm_loadu_epi16(test_vec[i].a);
    simde__m128i b = simde_x_mm_loadu_epi16(test_vec[i].b);
    simde__mmask8 r = simde_mm_cmple_epu16_mask(a, b);
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
    simde__mmask8 r = simde_mm_cmple_epu16_mask(a, b);

    simde_test_x86_write_u16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_u16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_mask_cmple_epu16_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k;
    const uint16_t a[8];
    const uint16_t b[8];
    const simde__mmask8 r;
  } test_vec[] = {
    { UINT8_C(202),
      { UINT16_C(29960), UINT16_C(35959), UINT16_C(34340), UINT16_C( 2086), UINT16_C(41503), UINT16_C(14985), UINT16_C(12463), UINT16_C(21052) },
      { UINT16_C(64585), UINT16_C(57991), UINT16_C(42835), UINT16_C( 2371), UINT16_C(17191), UINT16_C(14985), UINT16_C(39278), UINT16_C(30343) },
      UINT8_C(202) },
    { UINT8_C( 95),
      { UINT16_C(57283), UINT16_C(62586), UINT16_C(52251), UINT16_C( 6205), UINT16_C( 8275), UINT16_C(64107), UINT16_C(29795), UINT16_C(42529) },
      { UINT16_C(51255), UINT16_C(53268), UINT16_C(35408), UINT16_C( 6205), UINT16_C( 4237), UINT16_C(46548), UINT16_C(29795), UINT16_C( 3712) },
      UINT8_C( 72) },
    { UINT8_C(190),
      { UINT16_C( 5111), UINT16_C(27842), UINT16_C(26676), UINT16_C(64675), UINT16_C(29820), UINT16_C( 1868), UINT16_C(39762), UINT16_C(25492) },
      { UINT16_C(18800), UINT16_C(59821), UINT16_C(48073), UINT16_C(49986), UINT16_C(47037), UINT16_C(64905), UINT16_C(41539), UINT16_C(25492) },
      UINT8_C(182) },
    { UINT8_C(140),
      { UINT16_C( 2866), UINT16_C(52753), UINT16_C(29855), UINT16_C(59454), UINT16_C(10017), UINT16_C(56754), UINT16_C(30058), UINT16_C( 8602) },
      { UINT16_C(38911), UINT16_C(52753), UINT16_C(40948), UINT16_C(59454), UINT16_C(10017), UINT16_C(37274), UINT16_C(40486), UINT16_C(22863) },
      UINT8_C(140) },
    { UINT8_C(244),
      { UINT16_C(54243), UINT16_C(22774), UINT16_C( 5997), UINT16_C( 1367), UINT16_C(63868), UINT16_C( 7161), UINT16_C( 3152), UINT16_C(36962) },
      { UINT16_C(54243), UINT16_C(17847), UINT16_C( 4162), UINT16_C(41966), UINT16_C(14135), UINT16_C(40055), UINT16_C(28008), UINT16_C(19240) },
      UINT8_C( 96) },
    { UINT8_C(245),
      { UINT16_C(52908), UINT16_C(47172), UINT16_C(54320), UINT16_C( 9054), UINT16_C(41867), UINT16_C(39781), UINT16_C( 2194), UINT16_C(51666) },
      { UINT16_C(28288), UINT16_C(60721), UINT16_C(31895), UINT16_C(46638), UINT16_C(56351), UINT16_C( 6892), UINT16_C( 2194), UINT16_C(15118) },
      UINT8_C( 80) },
    { UINT8_C(206),
      { UINT16_C(20005), UINT16_C(11911), UINT16_C(20512), UINT16_C(36782), UINT16_C(39809), UINT16_C(64806), UINT16_C(56521), UINT16_C(42268) },
      { UINT16_C(14280), UINT16_C(11911), UINT16_C(28485), UINT16_C(36782), UINT16_C(39809), UINT16_C(46271), UINT16_C(28977), UINT16_C(22441) },
      UINT8_C( 14) },
    { UINT8_C( 78),
      { UINT16_C(65173), UINT16_C(29080), UINT16_C(15642), UINT16_C(20793), UINT16_C(41330), UINT16_C(57751), UINT16_C(12149), UINT16_C(59204) },
      { UINT16_C(65173), UINT16_C(24344), UINT16_C(15642), UINT16_C(53535), UINT16_C(65524), UINT16_C(10065), UINT16_C(12149), UINT16_C( 1014) },
      UINT8_C( 76) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__mmask8 k = test_vec[i].k;
    simde__m128i a = simde_x_mm_loadu_epi16(test_vec[i].a);
    simde__m128i b = simde_x_mm_loadu_epi16(test_vec[i].b);
    simde__mmask8 r = simde_mm_mask_cmple_epu16_mask(k, a, b);
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
    simde__mmask8 r = simde_mm_mask_cmple_epu16_mask(k, a, b);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_u16x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_u16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_x_mm256_cmple_epu16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const uint16_t a[16];
    const uint16_t b[16];
    const uint16_t r[16];
  } test_vec[] = {
    { { UINT16_C(28665), UINT16_C(65092), UINT16_C(51818), UINT16_C(43481), UINT16_C(24651), UINT16_C(48406), UINT16_C(31049), UINT16_C(18330),
        UINT16_C(40494), UINT16_C(56535), UINT16_C(  593), UINT16_C(53851), UINT16_C(26859), UINT16_C(39013), UINT16_C(16721), UINT16_C(18976) },
      { UINT16_C(26033), UINT16_C( 6984), UINT16_C( 8751), UINT16_C(31428), UINT16_C(56194), UINT16_C(52023), UINT16_C(53588), UINT16_C(33554),
        UINT16_C(60015), UINT16_C(49503), UINT16_C(48108), UINT16_C(55443), UINT16_C(63523), UINT16_C(29808), UINT16_C(16721), UINT16_C(60094) },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,
             UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX } },
    { { UINT16_C(56435), UINT16_C(24792), UINT16_C(27543), UINT16_C(47672), UINT16_C(43107), UINT16_C(39982), UINT16_C(60473), UINT16_C(12167),
        UINT16_C(36083), UINT16_C( 7252), UINT16_C(62294), UINT16_C(64456), UINT16_C(16329), UINT16_C(29173), UINT16_C(29128), UINT16_C(15496) },
      { UINT16_C(56435), UINT16_C(24792), UINT16_C(27543), UINT16_C(11934), UINT16_C(43107), UINT16_C(46794), UINT16_C(20921), UINT16_C(44261),
        UINT16_C(15070), UINT16_C(13513), UINT16_C(37165), UINT16_C(64456), UINT16_C( 9680), UINT16_C(29173), UINT16_C(61590), UINT16_C(58580) },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,
        UINT16_C(    0),      UINT16_MAX, UINT16_C(    0),      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX } },
    { { UINT16_C(25238), UINT16_C(50295), UINT16_C(42995), UINT16_C(50107), UINT16_C( 9164), UINT16_C(25435), UINT16_C(12307), UINT16_C(25415),
        UINT16_C( 4000), UINT16_C(58750), UINT16_C(51062), UINT16_C(43686), UINT16_C( 7642), UINT16_C(16278), UINT16_C(12153), UINT16_C( 4226) },
      { UINT16_C(64145), UINT16_C(34004), UINT16_C(42995), UINT16_C(28231), UINT16_C( 9164), UINT16_C(50641), UINT16_C( 6355), UINT16_C(29480),
        UINT16_C(42535), UINT16_C(58750), UINT16_C(65133), UINT16_C(18248), UINT16_C( 7642), UINT16_C(38279), UINT16_C( 2318), UINT16_C(40869) },
      {      UINT16_MAX, UINT16_C(    0),      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,
             UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX, UINT16_C(    0),      UINT16_MAX } },
    { { UINT16_C(44365), UINT16_C(47809), UINT16_C( 2476), UINT16_C(50945), UINT16_C(35048), UINT16_C(63068), UINT16_C(  402), UINT16_C(38293),
        UINT16_C(47482), UINT16_C(33338), UINT16_C(19749), UINT16_C(13116), UINT16_C(47921), UINT16_C(11541), UINT16_C(27234), UINT16_C(44881) },
      { UINT16_C( 4631), UINT16_C(50025), UINT16_C(27420), UINT16_C( 1163), UINT16_C(35048), UINT16_C(34298), UINT16_C(36841), UINT16_C(38293),
        UINT16_C(21833), UINT16_C(28390), UINT16_C( 8867), UINT16_C(54433), UINT16_C(46814), UINT16_C(11541), UINT16_C(21280), UINT16_C(44881) },
      { UINT16_C(    0),      UINT16_MAX,      UINT16_MAX, UINT16_C(    0),      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX,
        UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),      UINT16_MAX, UINT16_C(    0),      UINT16_MAX, UINT16_C(    0),      UINT16_MAX } },
    { { UINT16_C(41134), UINT16_C(20934), UINT16_C(26563), UINT16_C(41253), UINT16_C(10014), UINT16_C(16097), UINT16_C(53626), UINT16_C(57462),
        UINT16_C(29227), UINT16_C(61281), UINT16_C(59384), UINT16_C(26279), UINT16_C(58726), UINT16_C(30141), UINT16_C(30781), UINT16_C(60365) },
      { UINT16_C(37656), UINT16_C(20934), UINT16_C(26563), UINT16_C(41253), UINT16_C(24201), UINT16_C( 1111), UINT16_C(52783), UINT16_C(23268),
        UINT16_C(17728), UINT16_C(14410), UINT16_C(61740), UINT16_C(37791), UINT16_C(23766), UINT16_C( 5128), UINT16_C(54996), UINT16_C(60927) },
      { UINT16_C(    0),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),
        UINT16_C(    0), UINT16_C(    0),      UINT16_MAX,      UINT16_MAX, UINT16_C(    0), UINT16_C(    0),      UINT16_MAX,      UINT16_MAX } },
    { { UINT16_C(30549), UINT16_C(33051), UINT16_C(47720), UINT16_C(16148), UINT16_C( 7447), UINT16_C(60243), UINT16_C(21235), UINT16_C(23768),
        UINT16_C(41358), UINT16_C(11457), UINT16_C(16102), UINT16_C(35156), UINT16_C(32531), UINT16_C(46683), UINT16_C(34959), UINT16_C(58521) },
      { UINT16_C(46591), UINT16_C(26725), UINT16_C(31343), UINT16_C(34471), UINT16_C(64151), UINT16_C(35442), UINT16_C(21235), UINT16_C(23768),
        UINT16_C(42987), UINT16_C(53511), UINT16_C(23526), UINT16_C(63834), UINT16_C(46811), UINT16_C(27312), UINT16_C(18750), UINT16_C(58521) },
      {      UINT16_MAX, UINT16_C(    0), UINT16_C(    0),      UINT16_MAX,      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX,
             UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(    0), UINT16_C(    0),      UINT16_MAX } },
    { { UINT16_C(30428), UINT16_C(49774), UINT16_C(51409), UINT16_C(44220), UINT16_C(27774), UINT16_C(48406), UINT16_C(25781), UINT16_C(46331),
        UINT16_C(41240), UINT16_C(17698), UINT16_C( 5870), UINT16_C(13578), UINT16_C(22653), UINT16_C(11976), UINT16_C(14221), UINT16_C(27338) },
      { UINT16_C(30428), UINT16_C(32300), UINT16_C(59393), UINT16_C(32555), UINT16_C(16724), UINT16_C( 2620), UINT16_C(14246), UINT16_C(48830),
        UINT16_C(57560), UINT16_C(50691), UINT16_C( 3574), UINT16_C(29691), UINT16_C(50278), UINT16_C(62369), UINT16_C(27899), UINT16_C(43101) },
      {      UINT16_MAX, UINT16_C(    0),      UINT16_MAX, UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),      UINT16_MAX,
             UINT16_MAX,      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX } },
    { { UINT16_C(64111), UINT16_C(25912), UINT16_C(13064), UINT16_C(28377), UINT16_C(31479), UINT16_C(62049), UINT16_C(49126), UINT16_C(35738),
        UINT16_C(49481), UINT16_C(47920), UINT16_C(21778), UINT16_C(42370), UINT16_C(21431), UINT16_C(20702), UINT16_C(54754), UINT16_C(20929) },
      { UINT16_C(64111), UINT16_C(25912), UINT16_C(36909), UINT16_C( 9286), UINT16_C(31479), UINT16_C(62049), UINT16_C(45414), UINT16_C(44924),
        UINT16_C(49481), UINT16_C(47920), UINT16_C(60674), UINT16_C(47402), UINT16_C( 2369), UINT16_C( 8969), UINT16_C(51934), UINT16_C(20929) },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,
             UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),      UINT16_MAX } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256i a = simde_mm256_loadu_epi16(test_vec[i].a);
    simde__m256i b = simde_mm256_loadu_epi16(test_vec[i].b);
    simde__m256i r = simde_x_mm256_cmple_epu16(a, b);
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
    simde__m256i r = simde_x_mm256_cmple_epu16(a, b);

    simde_test_x86_write_u16x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_u16x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_u16x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_cmple_epu16_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const uint16_t a[16];
    const uint16_t b[16];
    const simde__mmask16 r;
  } test_vec[] = {
    { { UINT16_C( 3400), UINT16_C(29956), UINT16_C(17449), UINT16_C( 6413), UINT16_C(17045), UINT16_C(51221), UINT16_C( 4617), UINT16_C(47867),
        UINT16_C(13890), UINT16_C( 6491), UINT16_C(53573), UINT16_C(18876), UINT16_C(59991), UINT16_C(24906), UINT16_C( 8311), UINT16_C(49316) },
      { UINT16_C(43053), UINT16_C(22325), UINT16_C(17133), UINT16_C(33392), UINT16_C(34180), UINT16_C(36170), UINT16_C(18072), UINT16_C(55879),
        UINT16_C(41852), UINT16_C(49651), UINT16_C(45172), UINT16_C(52235), UINT16_C(21914), UINT16_C( 4653), UINT16_C(53621), UINT16_C(41938) },
      UINT16_C(19417) },
    { { UINT16_C(21830), UINT16_C(47799), UINT16_C(49669), UINT16_C(40838), UINT16_C(46103), UINT16_C(36273), UINT16_C(33669), UINT16_C(65328),
        UINT16_C(10890), UINT16_C(54374), UINT16_C(20372), UINT16_C(33698), UINT16_C(64899), UINT16_C(64523), UINT16_C(27808), UINT16_C(59122) },
      { UINT16_C(43713), UINT16_C(50849), UINT16_C(10092), UINT16_C(33894), UINT16_C(46103), UINT16_C(36273), UINT16_C(16795), UINT16_C(65328),
        UINT16_C(51051), UINT16_C(54374), UINT16_C(39702), UINT16_C(39298), UINT16_C(36249), UINT16_C(14742), UINT16_C(27808), UINT16_C(59122) },
      UINT16_C(53171) },
    { { UINT16_C(47436), UINT16_C(25567), UINT16_C(24917), UINT16_C(61180), UINT16_C(37615), UINT16_C(59687), UINT16_C(18203), UINT16_C(19876),
        UINT16_C( 9736), UINT16_C(61932), UINT16_C( 3854), UINT16_C( 3765), UINT16_C(55875), UINT16_C(47272), UINT16_C(26719), UINT16_C(44184) },
      { UINT16_C(30498), UINT16_C(30479), UINT16_C( 3033), UINT16_C(51301), UINT16_C(35998), UINT16_C(47537), UINT16_C(21972), UINT16_C(19876),
        UINT16_C( 9736), UINT16_C(61932), UINT16_C(33282), UINT16_C( 3765), UINT16_C(16732), UINT16_C(47272), UINT16_C(26719), UINT16_C(52072) },
      UINT16_C(61378) },
    { { UINT16_C(45779), UINT16_C(54716), UINT16_C(21812), UINT16_C(37147), UINT16_C( 6806), UINT16_C(16205), UINT16_C(46513), UINT16_C(48907),
        UINT16_C(19756), UINT16_C(44711), UINT16_C(22261), UINT16_C(10703), UINT16_C(43191), UINT16_C(27953), UINT16_C( 5512), UINT16_C(23455) },
      { UINT16_C(23495), UINT16_C(64561), UINT16_C(19632), UINT16_C(18061), UINT16_C(55910), UINT16_C( 6022), UINT16_C(37263), UINT16_C(48087),
        UINT16_C(32478), UINT16_C(44711), UINT16_C(22261), UINT16_C(10703), UINT16_C(11745), UINT16_C(27128), UINT16_C(38723), UINT16_C( 2757) },
      UINT16_C(20242) },
    { { UINT16_C( 8469), UINT16_C(60083), UINT16_C(44889), UINT16_C(14965), UINT16_C(28381), UINT16_C( 8356), UINT16_C(26885), UINT16_C(63530),
        UINT16_C(12639), UINT16_C(41372), UINT16_C(34500), UINT16_C(12874), UINT16_C( 3062), UINT16_C(63278), UINT16_C(59042), UINT16_C(47318) },
      { UINT16_C(35079), UINT16_C(24738), UINT16_C(44889), UINT16_C( 5787), UINT16_C(16261), UINT16_C(35638), UINT16_C(24744), UINT16_C( 1923),
        UINT16_C( 8081), UINT16_C(22184), UINT16_C(62373), UINT16_C(39816), UINT16_C( 3062), UINT16_C(41106), UINT16_C(27036), UINT16_C(41816) },
      UINT16_C( 7205) },
    { { UINT16_C(13765), UINT16_C(27583), UINT16_C(18216), UINT16_C( 9734), UINT16_C(39422), UINT16_C(39623), UINT16_C( 7938), UINT16_C(62526),
        UINT16_C(16922), UINT16_C(11296), UINT16_C(25057), UINT16_C(49091), UINT16_C(59097), UINT16_C(45381), UINT16_C(53900), UINT16_C(20762) },
      { UINT16_C(55815), UINT16_C(12476), UINT16_C(18216), UINT16_C( 9734), UINT16_C( 7516), UINT16_C(24250), UINT16_C(63549), UINT16_C(22354),
        UINT16_C(16922), UINT16_C( 7043), UINT16_C(18132), UINT16_C(44506), UINT16_C( 7980), UINT16_C(47198), UINT16_C(53900), UINT16_C(63498) },
      UINT16_C(57677) },
    { { UINT16_C(45832), UINT16_C(56474), UINT16_C(29946), UINT16_C( 9865), UINT16_C(59283), UINT16_C(34015), UINT16_C(59744), UINT16_C(45693),
        UINT16_C(42415), UINT16_C(14630), UINT16_C(47652), UINT16_C(49438), UINT16_C(25095), UINT16_C(19866), UINT16_C(52216), UINT16_C(  204) },
      { UINT16_C(26494), UINT16_C(30941), UINT16_C(29946), UINT16_C( 9865), UINT16_C(59283), UINT16_C(44787), UINT16_C(28775), UINT16_C( 5728),
        UINT16_C(34582), UINT16_C(14927), UINT16_C(47652), UINT16_C(49438), UINT16_C(38608), UINT16_C(19866), UINT16_C(25185), UINT16_C(57288) },
      UINT16_C(48700) },
    { { UINT16_C(17135), UINT16_C(12488), UINT16_C(50096), UINT16_C(32889), UINT16_C( 3673), UINT16_C(47688), UINT16_C( 4208), UINT16_C(14746),
        UINT16_C(62134), UINT16_C(49886), UINT16_C(61929), UINT16_C(24092), UINT16_C( 9464), UINT16_C(28730), UINT16_C(11404), UINT16_C(31997) },
      { UINT16_C(50542), UINT16_C(12488), UINT16_C( 9609), UINT16_C(58014), UINT16_C(58932), UINT16_C(42141), UINT16_C( 4208), UINT16_C(44510),
        UINT16_C(62134), UINT16_C( 4719), UINT16_C(35757), UINT16_C(42608), UINT16_C( 9464), UINT16_C(28730), UINT16_C(11404), UINT16_C(17847) },
      UINT16_C(31195) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256i a = simde_mm256_loadu_epi16(test_vec[i].a);
    simde__m256i b = simde_mm256_loadu_epi16(test_vec[i].b);
    simde__mmask16 r = simde_mm256_cmple_epu16_mask(a, b);
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
    simde__mmask16 r = simde_mm256_cmple_epu16_mask(a, b);

    simde_test_x86_write_u16x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_u16x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_mask_cmple_epu16_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask16 k;
    const uint16_t a[16];
    const uint16_t b[16];
    const simde__mmask16 r;
  } test_vec[] = {
    { UINT16_C(34223),
      { UINT16_C(64508), UINT16_C(43347), UINT16_C(50054), UINT16_C(13647), UINT16_C(25965), UINT16_C(17521), UINT16_C(10361), UINT16_C(21129),
        UINT16_C(60556), UINT16_C( 5812), UINT16_C(63726), UINT16_C(55251), UINT16_C(13786), UINT16_C(62134), UINT16_C(17269), UINT16_C(28980) },
      { UINT16_C(34622), UINT16_C(50459), UINT16_C(50054), UINT16_C(47354), UINT16_C(25965), UINT16_C(18940), UINT16_C(34196), UINT16_C(21129),
        UINT16_C(20338), UINT16_C(24630), UINT16_C( 2631), UINT16_C( 8503), UINT16_C(60991), UINT16_C(62134), UINT16_C(18481), UINT16_C(28454) },
      UINT16_C(  174) },
    { UINT16_C( 5832),
      { UINT16_C(63015), UINT16_C(24463), UINT16_C(53016), UINT16_C(11341), UINT16_C(32388), UINT16_C(43636), UINT16_C(17389), UINT16_C( 8940),
        UINT16_C(39006), UINT16_C(12625), UINT16_C(60180), UINT16_C(55552), UINT16_C(21786), UINT16_C(26937), UINT16_C(59420), UINT16_C(17646) },
      { UINT16_C(32478), UINT16_C(63139), UINT16_C(61517), UINT16_C(53538), UINT16_C(38510), UINT16_C(23419), UINT16_C(26586), UINT16_C( 8940),
        UINT16_C(52991), UINT16_C( 4969), UINT16_C(60180), UINT16_C(54508), UINT16_C( 9663), UINT16_C(56125), UINT16_C(11021), UINT16_C(60447) },
      UINT16_C( 1224) },
    { UINT16_C(37530),
      { UINT16_C(33469), UINT16_C(43648), UINT16_C(16214), UINT16_C(37839), UINT16_C(56602), UINT16_C(15038), UINT16_C(26825), UINT16_C(44028),
        UINT16_C(44894), UINT16_C( 9904), UINT16_C(19663), UINT16_C(19305), UINT16_C( 5057), UINT16_C(28485), UINT16_C( 3517), UINT16_C(31621) },
      { UINT16_C( 1423), UINT16_C(58661), UINT16_C(62532), UINT16_C(24440), UINT16_C(14033), UINT16_C(39577), UINT16_C(38302), UINT16_C(64838),
        UINT16_C(44894), UINT16_C( 5155), UINT16_C(35906), UINT16_C( 1119), UINT16_C( 5057), UINT16_C(23923), UINT16_C(63665), UINT16_C(31621) },
      UINT16_C(36994) },
    { UINT16_C(28432),
      { UINT16_C(56360), UINT16_C(34846), UINT16_C(48864), UINT16_C(21292), UINT16_C(56859), UINT16_C(62284), UINT16_C(18974), UINT16_C(17648),
        UINT16_C(57740), UINT16_C(12001), UINT16_C(46500), UINT16_C(  616), UINT16_C(14376), UINT16_C(38821), UINT16_C(16205), UINT16_C(29994) },
      { UINT16_C(18460), UINT16_C(64765), UINT16_C(10758), UINT16_C( 8528), UINT16_C(39944), UINT16_C( 9748), UINT16_C( 1254), UINT16_C(29290),
        UINT16_C(19686), UINT16_C(12001), UINT16_C( 2305), UINT16_C(  616), UINT16_C(14376), UINT16_C(38821), UINT16_C(60273), UINT16_C(36100) },
      UINT16_C(27136) },
    { UINT16_C( 5911),
      { UINT16_C( 4837), UINT16_C(29048), UINT16_C(47419), UINT16_C(64675), UINT16_C( 5448), UINT16_C(19687), UINT16_C( 7074), UINT16_C(11341),
        UINT16_C(31061), UINT16_C(45062), UINT16_C(31916), UINT16_C( 1568), UINT16_C(38360), UINT16_C(42955), UINT16_C(56303), UINT16_C(54294) },
      { UINT16_C( 4837), UINT16_C(10566), UINT16_C(59719), UINT16_C(36645), UINT16_C( 3582), UINT16_C(41435), UINT16_C(10536), UINT16_C(32205),
        UINT16_C(31061), UINT16_C(20013), UINT16_C(20048), UINT16_C( 1568), UINT16_C( 8419), UINT16_C(53968), UINT16_C(59131), UINT16_C(59815) },
      UINT16_C(  261) },
    { UINT16_C( 1462),
      { UINT16_C(26688), UINT16_C(38245), UINT16_C(18577), UINT16_C(25013), UINT16_C(45082), UINT16_C(49479), UINT16_C(48025), UINT16_C(43950),
        UINT16_C(34166), UINT16_C(49635), UINT16_C(10074), UINT16_C(53480), UINT16_C(14228), UINT16_C(32019), UINT16_C(11049), UINT16_C(27028) },
      { UINT16_C(63891), UINT16_C( 9470), UINT16_C(18577), UINT16_C(25013), UINT16_C(52323), UINT16_C(64797), UINT16_C(48025), UINT16_C(64936),
        UINT16_C(35665), UINT16_C(43967), UINT16_C(42931), UINT16_C(53480), UINT16_C(36574), UINT16_C( 1988), UINT16_C(22969), UINT16_C(19568) },
      UINT16_C( 1460) },
    { UINT16_C(39761),
      { UINT16_C(27093), UINT16_C(20652), UINT16_C(35504), UINT16_C(29919), UINT16_C(39058), UINT16_C(  717), UINT16_C( 8421), UINT16_C(21873),
        UINT16_C(37556), UINT16_C(42059), UINT16_C( 3095), UINT16_C(39345), UINT16_C(35669), UINT16_C(39876), UINT16_C(31413), UINT16_C(35744) },
      { UINT16_C(19683), UINT16_C(37851), UINT16_C(47830), UINT16_C(26631), UINT16_C(39058), UINT16_C(14443), UINT16_C( 8421), UINT16_C(43405),
        UINT16_C(37556), UINT16_C(34381), UINT16_C(65253), UINT16_C(14879), UINT16_C(58249), UINT16_C(39876), UINT16_C(30045), UINT16_C(16586) },
      UINT16_C( 4432) },
    { UINT16_C(57051),
      { UINT16_C(13883), UINT16_C(23449), UINT16_C( 9072), UINT16_C(17726), UINT16_C(40034), UINT16_C(11450), UINT16_C(31708), UINT16_C(45265),
        UINT16_C(12562), UINT16_C( 4747), UINT16_C(15332), UINT16_C(53117), UINT16_C(50400), UINT16_C(11848), UINT16_C(39290), UINT16_C(46537) },
      { UINT16_C(25295), UINT16_C(23449), UINT16_C(20357), UINT16_C(17726), UINT16_C(16107), UINT16_C(50963), UINT16_C(31708), UINT16_C(52087),
        UINT16_C(  534), UINT16_C(64478), UINT16_C(23357), UINT16_C(53117), UINT16_C(50400), UINT16_C(39499), UINT16_C(39290), UINT16_C(31311) },
      UINT16_C(24267) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__mmask16 k = test_vec[i].k;
    simde__m256i a = simde_mm256_loadu_epi16(test_vec[i].a);
    simde__m256i b = simde_mm256_loadu_epi16(test_vec[i].b);
    simde__mmask16 r = simde_mm256_mask_cmple_epu16_mask(k, a, b);
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
    simde__mmask16 r = simde_mm256_mask_cmple_epu16_mask(k, a, b);

    simde_test_x86_write_mmask16(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_u16x16(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_u16x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_x_mm512_cmple_epu16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const uint16_t a[32];
    const uint16_t b[32];
    const uint16_t r[32];
  } test_vec[] = {
    { { UINT16_C(62944), UINT16_C(58069), UINT16_C(  226), UINT16_C( 9115), UINT16_C(41993), UINT16_C(59207), UINT16_C(48238), UINT16_C(12950),
        UINT16_C( 7400), UINT16_C(42019), UINT16_C(14825), UINT16_C(23914), UINT16_C( 8805), UINT16_C(17207), UINT16_C(49493), UINT16_C(13716),
        UINT16_C(27062), UINT16_C(39191), UINT16_C(45673), UINT16_C(29372), UINT16_C(  854), UINT16_C(50522), UINT16_C(61631), UINT16_C(42999),
        UINT16_C( 6924), UINT16_C(62795), UINT16_C(46676), UINT16_C(47442), UINT16_C(35544), UINT16_C(11773), UINT16_C(37195), UINT16_C(  611) },
      { UINT16_C(31482), UINT16_C(58069), UINT16_C(22317), UINT16_C(33750), UINT16_C(12379), UINT16_C( 6728), UINT16_C(16416), UINT16_C(11714),
        UINT16_C( 7400), UINT16_C(42019), UINT16_C(14825), UINT16_C(23914), UINT16_C(26111), UINT16_C(19145), UINT16_C(11510), UINT16_C(61772),
        UINT16_C(59302), UINT16_C(39191), UINT16_C(11071), UINT16_C(39511), UINT16_C(40796), UINT16_C(31924), UINT16_C(30431), UINT16_C(15017),
        UINT16_C(52356), UINT16_C(18409), UINT16_C(21057), UINT16_C(16611), UINT16_C(35544), UINT16_C(44682), UINT16_C(55256), UINT16_C(32415) },
      { UINT16_C(    0),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),
             UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,
             UINT16_MAX,      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX, UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),
             UINT16_MAX, UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX } },
    { { UINT16_C(50582), UINT16_C(46604), UINT16_C(41838), UINT16_C(46897), UINT16_C(10735), UINT16_C(45791), UINT16_C(16843), UINT16_C(14584),
        UINT16_C(34445), UINT16_C(11239), UINT16_C(54775), UINT16_C( 5249), UINT16_C(33870), UINT16_C(40457), UINT16_C(32039), UINT16_C(48557),
        UINT16_C(47426), UINT16_C(45427), UINT16_C(42332), UINT16_C(19560), UINT16_C(18382), UINT16_C(39422), UINT16_C(63112), UINT16_C( 5842),
        UINT16_C(47485), UINT16_C(29761), UINT16_C(49806), UINT16_C(56713), UINT16_C(37447), UINT16_C(28283), UINT16_C(10255), UINT16_C(21035) },
      { UINT16_C(40929), UINT16_C(15875), UINT16_C(41838), UINT16_C( 4746), UINT16_C(34994), UINT16_C(15020), UINT16_C(32382), UINT16_C(64336),
        UINT16_C(37431), UINT16_C(50544), UINT16_C(54775), UINT16_C(39842), UINT16_C( 7819), UINT16_C(39689), UINT16_C(13638), UINT16_C(48557),
        UINT16_C(47426), UINT16_C( 6246), UINT16_C(61531), UINT16_C( 3370), UINT16_C(54904), UINT16_C(39422), UINT16_C(38996), UINT16_C(35826),
        UINT16_C(47485), UINT16_C(32337), UINT16_C(62299), UINT16_C(56713), UINT16_C( 8977), UINT16_C(22657), UINT16_C(28248), UINT16_C(21035) },
      { UINT16_C(    0), UINT16_C(    0),      UINT16_MAX, UINT16_C(    0),      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX,
             UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),      UINT16_MAX,
             UINT16_MAX, UINT16_C(    0),      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,
             UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(    0), UINT16_C(    0),      UINT16_MAX,      UINT16_MAX } },
    { { UINT16_C(21817), UINT16_C( 4066), UINT16_C(43204), UINT16_C( 2653), UINT16_C(41654), UINT16_C(23716), UINT16_C(51672), UINT16_C(28972),
        UINT16_C(31552), UINT16_C(43620), UINT16_C(16099), UINT16_C(28453), UINT16_C(63898), UINT16_C(25684), UINT16_C(25932), UINT16_C(34444),
        UINT16_C(28346), UINT16_C(32661), UINT16_C(62231), UINT16_C(52617), UINT16_C(11669), UINT16_C(27946), UINT16_C(22262), UINT16_C(14046),
        UINT16_C(17361), UINT16_C(46560), UINT16_C( 1665), UINT16_C( 6948), UINT16_C(30975), UINT16_C(19327), UINT16_C( 3293), UINT16_C(39121) },
      { UINT16_C(26490), UINT16_C(37143), UINT16_C(41050), UINT16_C(61279), UINT16_C(35277), UINT16_C(50012), UINT16_C(15327), UINT16_C(45562),
        UINT16_C(55934), UINT16_C(65382), UINT16_C(35552), UINT16_C(57115), UINT16_C(39427), UINT16_C(57387), UINT16_C(25932), UINT16_C( 8568),
        UINT16_C(36707), UINT16_C(48562), UINT16_C( 4399), UINT16_C(64684), UINT16_C( 2458), UINT16_C(31424), UINT16_C(47684), UINT16_C(49707),
        UINT16_C(37268), UINT16_C(46560), UINT16_C(56347), UINT16_C( 7764), UINT16_C(32631), UINT16_C( 7679), UINT16_C(30588), UINT16_C(57150) },
      {      UINT16_MAX,      UINT16_MAX, UINT16_C(    0),      UINT16_MAX, UINT16_C(    0),      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,
             UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX, UINT16_C(    0),
             UINT16_MAX,      UINT16_MAX, UINT16_C(    0),      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,
             UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX } },
    { { UINT16_C(33722), UINT16_C(48577), UINT16_C(62668), UINT16_C( 8026), UINT16_C(29159), UINT16_C(38069), UINT16_C( 3763), UINT16_C(34517),
        UINT16_C(35880), UINT16_C( 7796), UINT16_C(33175), UINT16_C( 8588), UINT16_C( 6029), UINT16_C( 4392), UINT16_C( 3808), UINT16_C(39835),
        UINT16_C(23697), UINT16_C(23896), UINT16_C(45648), UINT16_C(14204), UINT16_C(12835), UINT16_C(54987), UINT16_C(41280), UINT16_C(26716),
        UINT16_C(53293), UINT16_C(50310), UINT16_C( 4690), UINT16_C(57317), UINT16_C( 3369), UINT16_C( 2800), UINT16_C(35867), UINT16_C(44197) },
      { UINT16_C(65000), UINT16_C(14602), UINT16_C(34479), UINT16_C( 8026), UINT16_C(15544), UINT16_C(63656), UINT16_C( 1245), UINT16_C( 2656),
        UINT16_C(59348), UINT16_C( 7796), UINT16_C(46073), UINT16_C( 8966), UINT16_C(63169), UINT16_C(56365), UINT16_C(53890), UINT16_C(27529),
        UINT16_C(23697), UINT16_C(32420), UINT16_C( 5145), UINT16_C(53840), UINT16_C(63568), UINT16_C(11722), UINT16_C(11260), UINT16_C(53303),
        UINT16_C( 1298), UINT16_C( 3063), UINT16_C( 4690), UINT16_C(57317), UINT16_C(23539), UINT16_C(30294), UINT16_C(57133), UINT16_C(44197) },
      {      UINT16_MAX, UINT16_C(    0), UINT16_C(    0),      UINT16_MAX, UINT16_C(    0),      UINT16_MAX, UINT16_C(    0), UINT16_C(    0),
             UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(    0),
             UINT16_MAX,      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX, UINT16_C(    0), UINT16_C(    0),      UINT16_MAX,
        UINT16_C(    0), UINT16_C(    0),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX } },
    { { UINT16_C(40786), UINT16_C(60604), UINT16_C( 6762), UINT16_C(11478), UINT16_C(60738), UINT16_C(38635), UINT16_C(31292), UINT16_C(37371),
        UINT16_C(27648), UINT16_C(33694), UINT16_C( 9740), UINT16_C( 2041), UINT16_C(58884), UINT16_C(49455), UINT16_C(21683), UINT16_C( 1777),
        UINT16_C(44532), UINT16_C(24306), UINT16_C(51399), UINT16_C( 2698), UINT16_C(30133), UINT16_C(62112), UINT16_C(39919), UINT16_C(61315),
        UINT16_C( 8456), UINT16_C( 5234), UINT16_C(27719), UINT16_C(19227), UINT16_C(19026), UINT16_C( 1293), UINT16_C(65183), UINT16_C(37643) },
      { UINT16_C(64940), UINT16_C(60604), UINT16_C(31685), UINT16_C(11478), UINT16_C( 7665), UINT16_C(57453), UINT16_C(61625), UINT16_C(37371),
        UINT16_C(16913), UINT16_C(22997), UINT16_C(61614), UINT16_C(  164), UINT16_C(45370), UINT16_C(49455), UINT16_C( 4528), UINT16_C( 1777),
        UINT16_C(23823), UINT16_C(24306), UINT16_C(51399), UINT16_C(51791), UINT16_C(30133), UINT16_C(62112), UINT16_C(31404), UINT16_C(48868),
        UINT16_C(47549), UINT16_C( 5234), UINT16_C(48041), UINT16_C(58476), UINT16_C(29293), UINT16_C( 7613), UINT16_C(65183), UINT16_C(37497) },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,
        UINT16_C(    0), UINT16_C(    0),      UINT16_MAX, UINT16_C(    0), UINT16_C(    0),      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,
        UINT16_C(    0),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(    0), UINT16_C(    0),
             UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(    0) } },
    { { UINT16_C(54267), UINT16_C(37150), UINT16_C(18825), UINT16_C(64657), UINT16_C(46110), UINT16_C(27932), UINT16_C(63932), UINT16_C(32378),
        UINT16_C(62190), UINT16_C(40681), UINT16_C(14550), UINT16_C(11451), UINT16_C(62788), UINT16_C(31493), UINT16_C(29096), UINT16_C(41785),
        UINT16_C(22340), UINT16_C(52788), UINT16_C(50592), UINT16_C(48842), UINT16_C(59002), UINT16_C(13868), UINT16_C(42720), UINT16_C(52916),
        UINT16_C(40344), UINT16_C(28268), UINT16_C(10197), UINT16_C( 6810), UINT16_C(40732), UINT16_C(50325), UINT16_C(52753), UINT16_C(21863) },
      { UINT16_C(54267), UINT16_C(37150), UINT16_C(61025), UINT16_C(56196), UINT16_C(45268), UINT16_C(46098), UINT16_C(50774), UINT16_C(61058),
        UINT16_C(61028), UINT16_C(40681), UINT16_C(62997), UINT16_C(12627), UINT16_C(59542), UINT16_C(42997), UINT16_C(29096), UINT16_C(56572),
        UINT16_C(22340), UINT16_C(52788), UINT16_C( 9742), UINT16_C(57910), UINT16_C(18647), UINT16_C(11671), UINT16_C(42720), UINT16_C(29212),
        UINT16_C(30728), UINT16_C(28268), UINT16_C(65391), UINT16_C( 6810), UINT16_C(40732), UINT16_C(50325), UINT16_C(43169), UINT16_C(39546) },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(    0), UINT16_C(    0),      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,
        UINT16_C(    0),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,
             UINT16_MAX,      UINT16_MAX, UINT16_C(    0),      UINT16_MAX, UINT16_C(    0), UINT16_C(    0),      UINT16_MAX, UINT16_C(    0),
        UINT16_C(    0),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(    0),      UINT16_MAX } },
    { { UINT16_C(21437), UINT16_C(   67), UINT16_C(64638), UINT16_C(61722), UINT16_C(24908), UINT16_C(46707), UINT16_C(26565), UINT16_C(41255),
        UINT16_C(46599), UINT16_C(42732), UINT16_C(15508), UINT16_C(46894), UINT16_C(21560), UINT16_C(56443), UINT16_C(55796), UINT16_C(45385),
        UINT16_C(36141), UINT16_C(43953), UINT16_C(52105), UINT16_C(54941), UINT16_C( 4141), UINT16_C(62092), UINT16_C(45943), UINT16_C(32403),
        UINT16_C(32618), UINT16_C(65060), UINT16_C(21179), UINT16_C(62389), UINT16_C(12454), UINT16_C(39887), UINT16_C( 6410), UINT16_C(14156) },
      { UINT16_C(65190), UINT16_C(12258), UINT16_C(32713), UINT16_C(62981), UINT16_C(37263), UINT16_C( 1768), UINT16_C(31557), UINT16_C(41255),
        UINT16_C(43514), UINT16_C(46509), UINT16_C(25595), UINT16_C(41640), UINT16_C(21560), UINT16_C(56443), UINT16_C(35217), UINT16_C(14292),
        UINT16_C(46983), UINT16_C(20838), UINT16_C(52105), UINT16_C(50759), UINT16_C(12541), UINT16_C(17100), UINT16_C(20907), UINT16_C(42737),
        UINT16_C(32618), UINT16_C(62811), UINT16_C(21179), UINT16_C(38295), UINT16_C(54396), UINT16_C(39887), UINT16_C( 1886), UINT16_C(58692) },
      {      UINT16_MAX,      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX,
        UINT16_C(    0),      UINT16_MAX,      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX, UINT16_C(    0), UINT16_C(    0),
             UINT16_MAX, UINT16_C(    0),      UINT16_MAX, UINT16_C(    0),      UINT16_MAX, UINT16_C(    0), UINT16_C(    0),      UINT16_MAX,
             UINT16_MAX, UINT16_C(    0),      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX, UINT16_C(    0),      UINT16_MAX } },
    { { UINT16_C(44758), UINT16_C(60780), UINT16_C(10028), UINT16_C(55809), UINT16_C(22447), UINT16_C(34611), UINT16_C(13215), UINT16_C(34394),
        UINT16_C( 8846), UINT16_C(60783), UINT16_C(61057), UINT16_C(46536), UINT16_C(45215), UINT16_C(22599), UINT16_C(49116), UINT16_C(45776),
        UINT16_C(15469), UINT16_C(39327), UINT16_C(41060), UINT16_C( 4979), UINT16_C(42744), UINT16_C(38810), UINT16_C(62681), UINT16_C(26398),
        UINT16_C(36118), UINT16_C(38996), UINT16_C( 7291), UINT16_C( 6989), UINT16_C(38348), UINT16_C(43123), UINT16_C(17236), UINT16_C(49499) },
      { UINT16_C(64128), UINT16_C(58458), UINT16_C(52635), UINT16_C(55809), UINT16_C(37235), UINT16_C(19754), UINT16_C(18566), UINT16_C(40116),
        UINT16_C( 2518), UINT16_C(20788), UINT16_C(61057), UINT16_C(62060), UINT16_C(57367), UINT16_C(27546), UINT16_C(62755), UINT16_C(41772),
        UINT16_C(34544), UINT16_C(35719), UINT16_C(32339), UINT16_C(50718), UINT16_C(18448), UINT16_C(38419), UINT16_C(51345), UINT16_C(26398),
        UINT16_C(26577), UINT16_C(63160), UINT16_C( 9705), UINT16_C(  232), UINT16_C(38348), UINT16_C(10347), UINT16_C(38776), UINT16_C(26828) },
      {      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX,
        UINT16_C(    0), UINT16_C(    0),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(    0),
             UINT16_MAX, UINT16_C(    0), UINT16_C(    0),      UINT16_MAX, UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),      UINT16_MAX,
        UINT16_C(    0),      UINT16_MAX,      UINT16_MAX, UINT16_C(    0),      UINT16_MAX, UINT16_C(    0),      UINT16_MAX, UINT16_C(    0) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i a = simde_mm512_loadu_epi16(test_vec[i].a);
    simde__m512i b = simde_mm512_loadu_epi16(test_vec[i].b);
    simde__m512i r = simde_x_mm512_cmple_epu16(a, b);
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
    simde__m512i r = simde_x_mm512_cmple_epu16(a, b);

    simde_test_x86_write_u16x32(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_u16x32(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_u16x32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_cmple_epu16_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const uint16_t a[32];
    const uint16_t b[32];
    const simde__mmask32 r;
  } test_vec[] = {
    { { UINT16_C(59621), UINT16_C(63842), UINT16_C( 8426), UINT16_C(32351), UINT16_C(40596), UINT16_C(20033), UINT16_C(52207), UINT16_C( 6601),
        UINT16_C(39428), UINT16_C(53075), UINT16_C(30908), UINT16_C(45726), UINT16_C(65429), UINT16_C( 1638), UINT16_C(32314), UINT16_C( 8027),
        UINT16_C(48486), UINT16_C(20761), UINT16_C(30941), UINT16_C(29135), UINT16_C( 4118), UINT16_C( 1472), UINT16_C(35291), UINT16_C(57119),
        UINT16_C(29219), UINT16_C(57262), UINT16_C(19690), UINT16_C(32658), UINT16_C(63564), UINT16_C(34437), UINT16_C(57463), UINT16_C(56741) },
      { UINT16_C(48797), UINT16_C(63842), UINT16_C(64822), UINT16_C(19947), UINT16_C(40596), UINT16_C(59474), UINT16_C(28981), UINT16_C(22728),
        UINT16_C(30435), UINT16_C(53075), UINT16_C(30908), UINT16_C( 3916), UINT16_C(53698), UINT16_C(14741), UINT16_C(15025), UINT16_C( 8027),
        UINT16_C(17913), UINT16_C(12232), UINT16_C(46147), UINT16_C(20604), UINT16_C(53087), UINT16_C( 1472), UINT16_C(  320), UINT16_C(57119),
        UINT16_C( 9591), UINT16_C(15089), UINT16_C(16111), UINT16_C(32658), UINT16_C(56847), UINT16_C(49643), UINT16_C(  537), UINT16_C( 4623) },
      UINT32_C( 682927798) },
    { { UINT16_C(23513), UINT16_C(26097), UINT16_C(52249), UINT16_C(42576), UINT16_C(53472), UINT16_C(62836), UINT16_C(25917), UINT16_C(53122),
        UINT16_C(18760), UINT16_C(26960), UINT16_C(33625), UINT16_C(18586), UINT16_C(35744), UINT16_C(49232), UINT16_C(27276), UINT16_C(25895),
        UINT16_C( 6342), UINT16_C(57290), UINT16_C( 7141), UINT16_C(50566), UINT16_C(64235), UINT16_C(10683), UINT16_C(15711), UINT16_C(43256),
        UINT16_C(18822), UINT16_C(57105), UINT16_C(43980), UINT16_C(27688), UINT16_C(30775), UINT16_C(49964), UINT16_C(21475), UINT16_C(43305) },
      { UINT16_C(62316), UINT16_C(20872), UINT16_C( 3598), UINT16_C(64022), UINT16_C(53512), UINT16_C(26659), UINT16_C( 6926), UINT16_C(37904),
        UINT16_C( 8548), UINT16_C(12404), UINT16_C(40141), UINT16_C(18586), UINT16_C(51476), UINT16_C(63431), UINT16_C(61469), UINT16_C(35232),
        UINT16_C(10724), UINT16_C(62170), UINT16_C(61495), UINT16_C(50566), UINT16_C(64235), UINT16_C(10683), UINT16_C(47147), UINT16_C(36709),
        UINT16_C(55769), UINT16_C(42688), UINT16_C(23925), UINT16_C(35242), UINT16_C(30775), UINT16_C(17281), UINT16_C( 8546), UINT16_C(18124) },
      UINT32_C( 427818009) },
    { { UINT16_C(41193), UINT16_C(32981), UINT16_C(38854), UINT16_C(64473), UINT16_C(  769), UINT16_C( 9051), UINT16_C(19089), UINT16_C(63774),
        UINT16_C(49402), UINT16_C( 1749), UINT16_C(15117), UINT16_C(52025), UINT16_C(45090), UINT16_C(11244), UINT16_C(21747), UINT16_C(56446),
        UINT16_C(21492), UINT16_C(47709), UINT16_C(14058), UINT16_C(60341), UINT16_C( 4153), UINT16_C(51982), UINT16_C(11355), UINT16_C(21956),
        UINT16_C(39405), UINT16_C(64091), UINT16_C(38357), UINT16_C(63429), UINT16_C(45637), UINT16_C(14370), UINT16_C(40966), UINT16_C(64020) },
      { UINT16_C(41193), UINT16_C(56757), UINT16_C(27304), UINT16_C(57800), UINT16_C(54907), UINT16_C(54956), UINT16_C(28675), UINT16_C(61483),
        UINT16_C(34314), UINT16_C( 1749), UINT16_C(44827), UINT16_C(52025), UINT16_C(63841), UINT16_C(11244), UINT16_C(44441), UINT16_C(36194),
        UINT16_C( 5918), UINT16_C(50794), UINT16_C(13185), UINT16_C(60341), UINT16_C(21513), UINT16_C( 3282), UINT16_C(11355), UINT16_C(53244),
        UINT16_C(59012), UINT16_C(40878), UINT16_C(33942), UINT16_C(63232), UINT16_C(45637), UINT16_C( 5983), UINT16_C(49477), UINT16_C(64020) },
      UINT32_C(3520757363) },
    { { UINT16_C(46644), UINT16_C(30233), UINT16_C(28552), UINT16_C(44993), UINT16_C( 6296), UINT16_C(48795), UINT16_C(22124), UINT16_C(42856),
        UINT16_C(45503), UINT16_C(44407), UINT16_C(16379), UINT16_C(56600), UINT16_C(39526), UINT16_C(19972), UINT16_C(37056), UINT16_C(62478),
        UINT16_C(10310), UINT16_C(52842), UINT16_C(11159), UINT16_C(12158), UINT16_C( 6468), UINT16_C(45293), UINT16_C(21872), UINT16_C(12119),
        UINT16_C(52999), UINT16_C(  732), UINT16_C(62478), UINT16_C(30175), UINT16_C(58254), UINT16_C(20163), UINT16_C(53875), UINT16_C(47427) },
      { UINT16_C(44538), UINT16_C(37256), UINT16_C( 1753), UINT16_C( 7617), UINT16_C(44575), UINT16_C(36813), UINT16_C(22124), UINT16_C( 3007),
        UINT16_C(45503), UINT16_C(  525), UINT16_C(60560), UINT16_C( 7799), UINT16_C(15311), UINT16_C(19972), UINT16_C(37056), UINT16_C( 2044),
        UINT16_C(10310), UINT16_C(52842), UINT16_C(22922), UINT16_C(12158), UINT16_C( 6468), UINT16_C(45293), UINT16_C(63558), UINT16_C(14871),
        UINT16_C(52999), UINT16_C( 9276), UINT16_C(46096), UINT16_C(57154), UINT16_C(45039), UINT16_C(64546), UINT16_C(53875), UINT16_C(47427) },
      UINT32_C(3959383378) },
    { { UINT16_C(50274), UINT16_C(22342), UINT16_C( 7691), UINT16_C(29524), UINT16_C(23856), UINT16_C(14881), UINT16_C( 2429), UINT16_C(49624),
        UINT16_C(39469), UINT16_C( 1557), UINT16_C(18590), UINT16_C(21197), UINT16_C(37278), UINT16_C( 4966), UINT16_C(13911), UINT16_C(47404),
        UINT16_C(29434), UINT16_C( 1296), UINT16_C(25745), UINT16_C(49528), UINT16_C(39361), UINT16_C(16123), UINT16_C(54178), UINT16_C(53503),
        UINT16_C( 5229), UINT16_C( 3030), UINT16_C(41821), UINT16_C(64350), UINT16_C(50228), UINT16_C(35855), UINT16_C(15354), UINT16_C(62789) },
      { UINT16_C(22189), UINT16_C(16122), UINT16_C(29626), UINT16_C(31999), UINT16_C(64012), UINT16_C(14881), UINT16_C(47821), UINT16_C(14975),
        UINT16_C(21966), UINT16_C( 1557), UINT16_C(42232), UINT16_C(11559), UINT16_C(13928), UINT16_C(25273), UINT16_C(65137), UINT16_C(47404),
        UINT16_C(21076), UINT16_C( 1296), UINT16_C(23749), UINT16_C(49528), UINT16_C(17751), UINT16_C( 9344),      UINT16_MAX, UINT16_C(52831),
        UINT16_C(42324), UINT16_C( 3030), UINT16_C( 8265), UINT16_C(45434), UINT16_C(13142), UINT16_C(50963), UINT16_C(27441), UINT16_C(62789) },
      UINT32_C(3813336700) },
    { { UINT16_C(28308), UINT16_C(13270), UINT16_C(10894), UINT16_C(62506), UINT16_C(17918), UINT16_C(53593), UINT16_C(36031), UINT16_C(57081),
        UINT16_C(28344), UINT16_C( 1350), UINT16_C(24413), UINT16_C(32681), UINT16_C( 5259), UINT16_C( 9171), UINT16_C(44133), UINT16_C(63863),
        UINT16_C(19995), UINT16_C(43308), UINT16_C(22136), UINT16_C(30365), UINT16_C(63131), UINT16_C(23111), UINT16_C(16770), UINT16_C(15160),
        UINT16_C(32431), UINT16_C( 3392), UINT16_C(59869), UINT16_C(27020), UINT16_C(24573), UINT16_C(25228), UINT16_C(  780), UINT16_C(10075) },
      { UINT16_C(28308), UINT16_C(51664), UINT16_C(10894), UINT16_C(31295), UINT16_C(34660), UINT16_C(53593), UINT16_C( 3528), UINT16_C(30498),
        UINT16_C(25227), UINT16_C(27012), UINT16_C( 4428), UINT16_C(18898), UINT16_C(24176), UINT16_C(31916), UINT16_C( 1889), UINT16_C(63863),
        UINT16_C(29839), UINT16_C(28284), UINT16_C(48354), UINT16_C(18152), UINT16_C(48195), UINT16_C( 2861), UINT16_C(20425), UINT16_C(21890),
        UINT16_C( 1970), UINT16_C( 3392), UINT16_C(36888), UINT16_C(27020), UINT16_C(24573), UINT16_C(20229), UINT16_C(43259), UINT16_C(35330) },
      UINT32_C(3670389303) },
    { { UINT16_C(11208), UINT16_C(  891), UINT16_C(49163), UINT16_C(43137), UINT16_C( 2611), UINT16_C(62735), UINT16_C(51734), UINT16_C(10345),
        UINT16_C(56132), UINT16_C(19795), UINT16_C( 1684), UINT16_C(16709), UINT16_C(36030), UINT16_C( 7913), UINT16_C( 7381), UINT16_C(40603),
        UINT16_C( 5959), UINT16_C(21153), UINT16_C( 9175), UINT16_C( 2811), UINT16_C( 2605), UINT16_C(17407), UINT16_C(26836), UINT16_C( 6252),
        UINT16_C(48963), UINT16_C(55398), UINT16_C(43973), UINT16_C(33561), UINT16_C(  823), UINT16_C( 3233), UINT16_C(15647), UINT16_C(26282) },
      { UINT16_C(19540), UINT16_C(11192), UINT16_C(45935), UINT16_C(39990), UINT16_C(13757), UINT16_C(37600), UINT16_C(19614), UINT16_C(57770),
        UINT16_C(56132), UINT16_C(19795), UINT16_C(54203), UINT16_C(62035), UINT16_C(62678), UINT16_C(62975), UINT16_C(43313), UINT16_C(34139),
        UINT16_C( 5109), UINT16_C(25777), UINT16_C(59335), UINT16_C(33793), UINT16_C( 2605), UINT16_C(47638), UINT16_C(49453), UINT16_C(14492),
        UINT16_C(21969), UINT16_C(36104), UINT16_C(43973), UINT16_C(65151), UINT16_C(  823), UINT16_C(33267), UINT16_C(20008), UINT16_C( 7430) },
      UINT32_C(2097053587) },
    { { UINT16_C(43450), UINT16_C(22875), UINT16_C( 2092), UINT16_C(36884), UINT16_C(35276), UINT16_C(20769), UINT16_C(60059), UINT16_C(  680),
        UINT16_C(35771), UINT16_C(59281), UINT16_C( 8174), UINT16_C(53346), UINT16_C(24481), UINT16_C(29145), UINT16_C(   98), UINT16_C( 7331),
        UINT16_C(65193), UINT16_C(54645), UINT16_C(35078), UINT16_C(54117), UINT16_C(34323), UINT16_C(44580), UINT16_C(52336), UINT16_C(11184),
        UINT16_C(16728), UINT16_C(17938), UINT16_C(30049), UINT16_C(  534), UINT16_C(61652), UINT16_C(13939), UINT16_C( 5872), UINT16_C(39506) },
      { UINT16_C(51220), UINT16_C( 6767), UINT16_C(54609), UINT16_C(25837), UINT16_C( 4699), UINT16_C(20769), UINT16_C(49886), UINT16_C(14071),
        UINT16_C(35771), UINT16_C(25981), UINT16_C(37759), UINT16_C(21351), UINT16_C(55939), UINT16_C(29145), UINT16_C(56304), UINT16_C( 1038),
        UINT16_C(65193), UINT16_C(54645), UINT16_C(35078), UINT16_C(54117), UINT16_C(27678), UINT16_C(64634), UINT16_C(28974), UINT16_C(12851),
        UINT16_C(16728), UINT16_C(64151), UINT16_C(30049), UINT16_C(51021), UINT16_C(55000), UINT16_C(13939), UINT16_C( 5872), UINT16_C(21964) },
      UINT32_C(1873769893) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i a = simde_mm512_loadu_epi16(test_vec[i].a);
    simde__m512i b = simde_mm512_loadu_epi16(test_vec[i].b);
    simde__mmask32 r = simde_mm512_cmple_epu16_mask(a, b);
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
    simde__mmask32 r = simde_mm512_cmple_epu16_mask(a, b);

    simde_test_x86_write_u16x32(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_u16x32(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_mask_cmple_epu16_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask32 k;
    const uint16_t a[32];
    const uint16_t b[32];
    const simde__mmask32 r;
  } test_vec[] = {
    { UINT32_C(1409743634),
      { UINT16_C(40543), UINT16_C(22114), UINT16_C(10562), UINT16_C(21099), UINT16_C(32106), UINT16_C( 7569), UINT16_C(  705), UINT16_C(46667),
        UINT16_C(29450), UINT16_C( 4590), UINT16_C(60905), UINT16_C(14065), UINT16_C(39207), UINT16_C(43572), UINT16_C(34829), UINT16_C(28147),
        UINT16_C(22055), UINT16_C(27075), UINT16_C(12159), UINT16_C(60092), UINT16_C(19884), UINT16_C(27911), UINT16_C(21071), UINT16_C(22819),
        UINT16_C( 4549), UINT16_C(44907), UINT16_C(23806), UINT16_C( 9701), UINT16_C( 6645), UINT16_C(  719), UINT16_C(50082), UINT16_C(51567) },
      { UINT16_C(13081), UINT16_C(38962), UINT16_C(61026), UINT16_C( 3714), UINT16_C(35131), UINT16_C( 7569), UINT16_C(40923), UINT16_C(41444),
        UINT16_C(29450), UINT16_C(44880), UINT16_C(13739), UINT16_C(14065), UINT16_C(39207), UINT16_C(61602), UINT16_C(34829), UINT16_C(32953),
        UINT16_C(22055), UINT16_C(42776), UINT16_C(39898), UINT16_C( 5813), UINT16_C(12324), UINT16_C(27911), UINT16_C(33999), UINT16_C(32929),
        UINT16_C(61907), UINT16_C(44907), UINT16_C(23806), UINT16_C( 9701), UINT16_C(49575), UINT16_C( 3685), UINT16_C(50082), UINT16_C( 6286) },
      UINT64_C(          1409743634) },
    { UINT32_C(4013356489),
      { UINT16_C(  367), UINT16_C( 5306), UINT16_C( 8604), UINT16_C(48264), UINT16_C(31784), UINT16_C( 8624), UINT16_C( 8863), UINT16_C(50495),
        UINT16_C(53938), UINT16_C( 1171), UINT16_C(28874), UINT16_C(57640), UINT16_C(26075), UINT16_C(60674), UINT16_C( 2144), UINT16_C(53313),
        UINT16_C(64265), UINT16_C(42468), UINT16_C(27676), UINT16_C(17762), UINT16_C( 4840), UINT16_C(34662), UINT16_C(42292), UINT16_C(58956),
        UINT16_C(57464), UINT16_C(17130), UINT16_C( 4944), UINT16_C(11043), UINT16_C( 9592), UINT16_C(55320), UINT16_C(22829), UINT16_C(13992) },
      { UINT16_C(35924), UINT16_C(29148), UINT16_C(16120), UINT16_C(57526), UINT16_C( 7248), UINT16_C(33895), UINT16_C(46273), UINT16_C(14698),
        UINT16_C(53938), UINT16_C( 1171), UINT16_C(40808), UINT16_C(57359), UINT16_C(10181), UINT16_C(60674), UINT16_C( 2144), UINT16_C(53313),
        UINT16_C( 1517), UINT16_C(58949), UINT16_C(64323), UINT16_C(37830), UINT16_C(11799), UINT16_C(55575), UINT16_C(42292), UINT16_C(30226),
        UINT16_C(57464), UINT16_C(15962), UINT16_C(26926), UINT16_C(11043), UINT16_C( 9592), UINT16_C( 4325), UINT16_C( 3640), UINT16_C( 9700) },
      UINT64_C(           221701449) },
    { UINT32_C(2798380137),
      { UINT16_C( 8135), UINT16_C(50988), UINT16_C(16928), UINT16_C(41641), UINT16_C(  362), UINT16_C( 8698), UINT16_C(37299), UINT16_C(52742),
        UINT16_C(56903), UINT16_C(54137), UINT16_C(13468), UINT16_C(26776), UINT16_C(33492), UINT16_C(40263), UINT16_C(32119), UINT16_C(16268),
        UINT16_C(47261), UINT16_C(48390), UINT16_C(45306), UINT16_C(25951), UINT16_C(22961), UINT16_C(25990), UINT16_C(36331), UINT16_C(12851),
        UINT16_C(44395), UINT16_C( 1797), UINT16_C(40417), UINT16_C(46447), UINT16_C(46879), UINT16_C(38739), UINT16_C(57140), UINT16_C(53718) },
      { UINT16_C(56472), UINT16_C(37518), UINT16_C(16928), UINT16_C(16119), UINT16_C(32327), UINT16_C(12963), UINT16_C(54795), UINT16_C(30308),
        UINT16_C(56903), UINT16_C(25982), UINT16_C(60679), UINT16_C(26776), UINT16_C(28068), UINT16_C(40263), UINT16_C(37709), UINT16_C(58794),
        UINT16_C(14704), UINT16_C(48390), UINT16_C(28454), UINT16_C(27962), UINT16_C(56813), UINT16_C(63647), UINT16_C(  948), UINT16_C(14190),
        UINT16_C(60525), UINT16_C(29852), UINT16_C(47066), UINT16_C(32410), UINT16_C(22564), UINT16_C(29015), UINT16_C(57140), UINT16_C(23382) },
      UINT64_C(           109765729) },
    { UINT32_C(4292290749),
      { UINT16_C(39543), UINT16_C(59344), UINT16_C(61961), UINT16_C(31499), UINT16_C(26243), UINT16_C(   90), UINT16_C(44382), UINT16_C( 3415),
        UINT16_C(11418), UINT16_C(57569), UINT16_C( 9817), UINT16_C(34833), UINT16_C(40385), UINT16_C(11250), UINT16_C(48770), UINT16_C(63953),
        UINT16_C(41560), UINT16_C(25056), UINT16_C(60308), UINT16_C( 6108), UINT16_C(13905), UINT16_C(45079), UINT16_C(28387), UINT16_C(32445),
        UINT16_C(40603), UINT16_C(62558), UINT16_C(28612), UINT16_C(34429), UINT16_C(28428), UINT16_C(36529), UINT16_C(33325), UINT16_C(34439) },
      { UINT16_C(26404), UINT16_C(47591), UINT16_C(50258), UINT16_C(31499), UINT16_C(59642), UINT16_C(   90), UINT16_C(44382), UINT16_C(61788),
        UINT16_C(47792), UINT16_C(29926), UINT16_C( 9817), UINT16_C(34833), UINT16_C(40385), UINT16_C(11250), UINT16_C(19246), UINT16_C(63953),
        UINT16_C(28083), UINT16_C( 1291), UINT16_C(56369), UINT16_C(11433), UINT16_C(64964), UINT16_C(45079), UINT16_C(26127), UINT16_C(48908),
        UINT16_C(61984), UINT16_C(18739), UINT16_C(11861), UINT16_C(34429), UINT16_C(17113), UINT16_C(36529), UINT16_C(44430), UINT16_C(16730) },
      UINT64_C(          1771055288) },
    { UINT32_C(4173105582),
      { UINT16_C(20248), UINT16_C( 1284), UINT16_C( 9426), UINT16_C(47618), UINT16_C(48464), UINT16_C(28355), UINT16_C( 5292), UINT16_C(51681),
        UINT16_C(31972), UINT16_C(63424), UINT16_C(48702), UINT16_C(44439), UINT16_C(30998), UINT16_C(54072), UINT16_C( 4001), UINT16_C(47570),
        UINT16_C(55134), UINT16_C(12478), UINT16_C(49403), UINT16_C(19691), UINT16_C(44670), UINT16_C(10938), UINT16_C(40130), UINT16_C(42996),
        UINT16_C(46104), UINT16_C(22174), UINT16_C(13682), UINT16_C(34819), UINT16_C(15278), UINT16_C(20315), UINT16_C(11850), UINT16_C(43272) },
      { UINT16_C(50949), UINT16_C( 1284), UINT16_C(50311), UINT16_C(47618), UINT16_C( 1906), UINT16_C(13616), UINT16_C( 5292), UINT16_C(48092),
        UINT16_C(31448), UINT16_C(18961), UINT16_C( 5295), UINT16_C(24274), UINT16_C(11600), UINT16_C(54072), UINT16_C(46683), UINT16_C(24643),
        UINT16_C(55134), UINT16_C( 1121), UINT16_C(49403), UINT16_C(19691), UINT16_C(15028), UINT16_C(10938), UINT16_C(40130), UINT16_C(13842),
        UINT16_C( 9183), UINT16_C(36480), UINT16_C(21048), UINT16_C(35052), UINT16_C(15278), UINT16_C(56098), UINT16_C(26192), UINT16_C(52539) },
      UINT64_C(          4163633166) },
    { UINT32_C(1982381117),
      { UINT16_C(29796), UINT16_C(31478), UINT16_C(19638), UINT16_C(23789), UINT16_C(38837), UINT16_C(16866), UINT16_C(63168), UINT16_C(15365),
        UINT16_C(20982), UINT16_C(37175), UINT16_C( 3519), UINT16_C(38011), UINT16_C(13086), UINT16_C(52459), UINT16_C(42940), UINT16_C( 8388),
        UINT16_C(47900), UINT16_C(53914), UINT16_C(34823), UINT16_C(48174), UINT16_C( 4127), UINT16_C(57341), UINT16_C(  518), UINT16_C(64795),
        UINT16_C(21075), UINT16_C( 5006), UINT16_C( 2399), UINT16_C(32423), UINT16_C(37436), UINT16_C(63562), UINT16_C( 3898), UINT16_C(22041) },
      { UINT16_C(46026), UINT16_C(31478), UINT16_C(22075), UINT16_C(23182), UINT16_C(35687), UINT16_C(27962), UINT16_C(21902), UINT16_C(57706),
        UINT16_C(63656), UINT16_C( 2036), UINT16_C(39682), UINT16_C(38011), UINT16_C(53294), UINT16_C(26679), UINT16_C(20703), UINT16_C(43454),
        UINT16_C(58883), UINT16_C(16250), UINT16_C(34823), UINT16_C(41881), UINT16_C(54164), UINT16_C(57341), UINT16_C(31529), UINT16_C(53507),
        UINT16_C(21075), UINT16_C(30424), UINT16_C(24211), UINT16_C(49588), UINT16_C(37436), UINT16_C(63562), UINT16_C(59195), UINT16_C(16310) },
      UINT64_C(          1981848613) },
    { UINT32_C(1129687492),
      { UINT16_C(54740), UINT16_C(48963), UINT16_C(12948), UINT16_C(52947), UINT16_C(47140), UINT16_C( 3964), UINT16_C(41077), UINT16_C(37261),
        UINT16_C(52344), UINT16_C(15578), UINT16_C(12597), UINT16_C(34364), UINT16_C(31293), UINT16_C(31396), UINT16_C(52279), UINT16_C( 3056),
        UINT16_C(13217), UINT16_C(13770), UINT16_C(40293), UINT16_C(35331), UINT16_C(32597), UINT16_C(51865), UINT16_C( 9759), UINT16_C(39003),
        UINT16_C(14066), UINT16_C(10452), UINT16_C( 4199), UINT16_C(42158), UINT16_C(21131), UINT16_C(49695), UINT16_C( 3870), UINT16_C(49101) },
      { UINT16_C(38723), UINT16_C(43253), UINT16_C(63540), UINT16_C(35122), UINT16_C(52088), UINT16_C(38739), UINT16_C(41077), UINT16_C(58415),
        UINT16_C( 1253), UINT16_C(19468), UINT16_C(47636), UINT16_C(40944), UINT16_C(31293), UINT16_C(10849), UINT16_C(52279), UINT16_C(25321),
        UINT16_C(57029), UINT16_C(63754), UINT16_C(15831), UINT16_C(20354), UINT16_C(54792), UINT16_C(64230), UINT16_C( 5765), UINT16_C(27358),
        UINT16_C(59930), UINT16_C(11958), UINT16_C( 4199), UINT16_C(42158), UINT16_C(12214), UINT16_C(54746), UINT16_C( 3870), UINT16_C(49101) },
      UINT64_C(          1125222596) },
    { UINT32_C(3345032102),
      { UINT16_C( 7496), UINT16_C(48842), UINT16_C(19404), UINT16_C(37048), UINT16_C( 7594), UINT16_C(62319), UINT16_C(31799), UINT16_C(63712),
        UINT16_C(32087), UINT16_C(24943), UINT16_C(48116), UINT16_C(11978), UINT16_C(22078), UINT16_C(  779), UINT16_C(24831), UINT16_C(18246),
        UINT16_C( 4222), UINT16_C(18949), UINT16_C(48731), UINT16_C( 1498), UINT16_C(18907), UINT16_C( 4856), UINT16_C(55493), UINT16_C( 7179),
        UINT16_C(31317), UINT16_C(18814), UINT16_C(18486), UINT16_C(29815), UINT16_C(33438), UINT16_C(40311), UINT16_C(48611), UINT16_C(25060) },
      { UINT16_C(60109), UINT16_C(10411), UINT16_C(34216), UINT16_C(37048), UINT16_C( 9679), UINT16_C(38037), UINT16_C(41213), UINT16_C(63712),
        UINT16_C(12059), UINT16_C(20891), UINT16_C( 4983), UINT16_C( 5573), UINT16_C(15765), UINT16_C(30898), UINT16_C(38650), UINT16_C(51417),
        UINT16_C( 4222), UINT16_C(10480), UINT16_C( 7690), UINT16_C(55723), UINT16_C(16707), UINT16_C( 4856), UINT16_C( 7905), UINT16_C(64659),
        UINT16_C(31317), UINT16_C(50253), UINT16_C(18486), UINT16_C(55257), UINT16_C(35664), UINT16_C(19024), UINT16_C(48611), UINT16_C(41490) },
      UINT64_C(          3340836996) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__mmask32 k = test_vec[i].k;
    simde__m512i a = simde_mm512_loadu_epi16(test_vec[i].a);
    simde__m512i b = simde_mm512_loadu_epi16(test_vec[i].b);
    simde__mmask32 r = simde_mm512_mask_cmple_epu16_mask(k, a, b);
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
    simde__mmask32 r = simde_mm512_mask_cmple_epu16_mask(k, a, b);

    simde_test_x86_write_mmask32(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_u16x32(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_u16x32(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask64(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_x_mm_cmple_epi32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int32_t a[4];
    const int32_t b[4];
    const int32_t r[4];
  } test_vec[] = {
    { {  INT32_C(  1317607804), -INT32_C(  2060402645),  INT32_C(   477145098),  INT32_C(  1694483027) },
      {  INT32_C(  1317607804), -INT32_C(   550479462), -INT32_C(  1147302465),  INT32_C(   869647286) },
      { -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0) } },
    { {  INT32_C(   680309278), -INT32_C(  1387987878), -INT32_C(  1961737282), -INT32_C(  1232637668) },
      { -INT32_C(  1986611254), -INT32_C(    79350971), -INT32_C(   768730378), -INT32_C(  1232637668) },
      {  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1) } },
    { {  INT32_C(   560596067),  INT32_C(  1672248391), -INT32_C(  1223019539),  INT32_C(   809611499) },
      { -INT32_C(   651458845),  INT32_C(   413883040), -INT32_C(  1223019539),  INT32_C(  1328050156) },
      {  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1) } },
    { { -INT32_C(    81912562),  INT32_C(  1001601104), -INT32_C(   882117400),  INT32_C(   446994298) },
      { -INT32_C(    80588815),  INT32_C(  1001601104), -INT32_C(   882117400),  INT32_C(   813596706) },
      { -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1) } },
    { { -INT32_C(  1138106412),  INT32_C(  1300731347),  INT32_C(   493300524),  INT32_C(  1343789435) },
      { -INT32_C(  1138106412),  INT32_C(   814752014),  INT32_C(   493300524), -INT32_C(  2144498261) },
      { -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0) } },
    { {  INT32_C(   395101419),  INT32_C(  1781855215),  INT32_C(   146427020), -INT32_C(   623588405) },
      {  INT32_C(   395101419),  INT32_C(   533556084),  INT32_C(  1688206072),  INT32_C(  1017371728) },
      { -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1) } },
    { { -INT32_C(  1342535646), -INT32_C(  1598573356),  INT32_C(  1819970432),  INT32_C(  1694139632) },
      { -INT32_C(   393951248),  INT32_C(   307045313), -INT32_C(  1622216449),  INT32_C(  1110417696) },
      { -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0) } },
    { {  INT32_C(  1570679005),  INT32_C(   617224244), -INT32_C(  1937128292),  INT32_C(  1299516812) },
      {  INT32_C(   811582000),  INT32_C(   617224244),  INT32_C(  2014707279),  INT32_C(    91620903) },
      {  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_x_mm_loadu_epi32(test_vec[i].a);
    simde__m128i b = simde_x_mm_loadu_epi32(test_vec[i].b);
    simde__m128i r = simde_x_mm_cmple_epi32(a, b);
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
    simde__m128i r = simde_x_mm_cmple_epi32(a, b);

    simde_test_x86_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_cmple_epi32_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int32_t a[4];
    const int32_t b[4];
    const simde__mmask8 r;
  } test_vec[] = {
    { {  INT32_C(   363995336), -INT32_C(   484819939), -INT32_C(  1611755952),  INT32_C(   771383933) },
      {  INT32_C(   363995336), -INT32_C(  1688820384), -INT32_C(  1611755952), -INT32_C(  1773341746) },
      UINT8_C(  5) },
    { { -INT32_C(  1961572805), -INT32_C(   785710508),  INT32_C(   520037733),  INT32_C(  1912329233) },
      { -INT32_C(  1861463687),  INT32_C(   176720699), -INT32_C(  1818176385),  INT32_C(   264522963) },
      UINT8_C(  3) },
    { {  INT32_C(  1077462491), -INT32_C(    77645846), -INT32_C(  2056496628), -INT32_C(   417957717) },
      { -INT32_C(  2081317372), -INT32_C(    77645846), -INT32_C(   262808866), -INT32_C(   417957717) },
      UINT8_C( 14) },
    { { -INT32_C(   744804665),  INT32_C(   878250120), -INT32_C(  2078576768), -INT32_C(  2130244594) },
      { -INT32_C(   744804665), -INT32_C(  1418977800), -INT32_C(  1036336371),  INT32_C(   459410003) },
      UINT8_C( 13) },
    { { -INT32_C(  2030745850), -INT32_C(   989130569), -INT32_C(  1186590180),  INT32_C(   674565424) },
      {  INT32_C(   936616234), -INT32_C(  1191571868),  INT32_C(  1356028952),  INT32_C(   674565424) },
      UINT8_C( 13) },
    { {  INT32_C(   847639062),  INT32_C(   887933700),  INT32_C(    56369624),  INT32_C(   641347778) },
      {  INT32_C(  1457402942), -INT32_C(   341397103),  INT32_C(  2085402739), -INT32_C(   717474882) },
      UINT8_C(  5) },
    { {  INT32_C(  1683944332), -INT32_C(   697845228),  INT32_C(   687710954),  INT32_C(  1736367062) },
      {  INT32_C(     5449101), -INT32_C(  1686331427), -INT32_C(   143607598),  INT32_C(  1736367062) },
      UINT8_C(  8) },
    { {  INT32_C(   592892217),  INT32_C(  1229738867), -INT32_C(  1129199057), -INT32_C(   860093201) },
      {  INT32_C(   592892217),  INT32_C(  1768741104), -INT32_C(  1133605808),  INT32_C(  1144837899) },
      UINT8_C( 11) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_x_mm_loadu_epi32(test_vec[i].a);
    simde__m128i b = simde_x_mm_loadu_epi32(test_vec[i].b);
    simde__mmask8 r = simde_mm_cmple_epi32_mask(a, b);
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
    simde__mmask8 r = simde_mm_cmple_epi32_mask(a, b);

    simde_test_x86_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_mask_cmple_epi32_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k;
    const int32_t a[4];
    const int32_t b[4];
    const simde__mmask8 r;
  } test_vec[] = {
    { UINT8_C(107),
      { -INT32_C(  1479671056),  INT32_C(  1041260083),  INT32_C(  1598914449),  INT32_C(  1092645200) },
      { -INT32_C(  1479671056),  INT32_C(  1041260083),  INT32_C(  1598914449),  INT32_C(  1092645200) },
      UINT8_C( 11) },
    { UINT8_C( 84),
      {  INT32_C(    16577152), -INT32_C(  1320133825),  INT32_C(   129929595),  INT32_C(  1737832902) },
      { -INT32_C(   845928040),  INT32_C(  1403406293), -INT32_C(  1831571579),  INT32_C(  1610451167) },
      UINT8_C(  0) },
    { UINT8_C( 83),
      {  INT32_C(  1104177839),  INT32_C(  1644681001), -INT32_C(  1761972628),  INT32_C(  1248577282) },
      {  INT32_C(  1104177839),  INT32_C(  1644681001),  INT32_C(  1469324126),  INT32_C(   715935354) },
      UINT8_C(  3) },
    { UINT8_C(164),
      { -INT32_C(   507559054),  INT32_C(    98784574),  INT32_C(  2138254784),  INT32_C(  1578192893) },
      { -INT32_C(   507559054),  INT32_C(   245372096),  INT32_C(  1019726528), -INT32_C(  1466980299) },
      UINT8_C(  0) },
    { UINT8_C(144),
      { -INT32_C(  1704644756), -INT32_C(   224926558),  INT32_C(   570291701), -INT32_C(   941481038) },
      { -INT32_C(  1903693629), -INT32_C(   224926558), -INT32_C(  1572050093), -INT32_C(   941481038) },
      UINT8_C(  0) },
    { UINT8_C(242),
      { -INT32_C(  2021311854),  INT32_C(  1513793335),  INT32_C(  2031944073),  INT32_C(  1278323592) },
      { -INT32_C(   627011217),  INT32_C(  1406091997),  INT32_C(  2031944073), -INT32_C(  1111146453) },
      UINT8_C(  0) },
    { UINT8_C(104),
      {  INT32_C(  2138770302), -INT32_C(   737610711), -INT32_C(  1237101531),  INT32_C(   932388596) },
      {  INT32_C(   499181293),  INT32_C(   524875487),  INT32_C(   110757307),  INT32_C(   932388596) },
      UINT8_C(  8) },
    { UINT8_C(237),
      { -INT32_C(  1534241713), -INT32_C(  1231534952), -INT32_C(  1096560681), -INT32_C(  2036481904) },
      {  INT32_C(   222411784), -INT32_C(  1571403690), -INT32_C(  1258742208), -INT32_C(  1256425114) },
      UINT8_C(  9) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__mmask8 k = test_vec[i].k;
    simde__m128i a = simde_x_mm_loadu_epi32(test_vec[i].a);
    simde__m128i b = simde_x_mm_loadu_epi32(test_vec[i].b);
    simde__mmask8 r = simde_mm_mask_cmple_epi32_mask(k, a, b);
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
    simde__mmask8 r = simde_mm_mask_cmple_epi32_mask(k, a, b);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x4(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_x_mm256_cmple_epi32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int32_t a[8];
    const int32_t b[8];
    const int32_t r[8];
  } test_vec[] = {
    { { -INT32_C(  1672296139),  INT32_C(  1872310616), -INT32_C(   626752141),  INT32_C(  1799902444),  INT32_C(  1460083707), -INT32_C(   586080319), -INT32_C(   249076482), -INT32_C(  1498483088) },
      {  INT32_C(   390201535),  INT32_C(  1872310616), -INT32_C(   626752141),  INT32_C(  1799902444),  INT32_C(  1460083707), -INT32_C(   561978401), -INT32_C(  1194350777),  INT32_C(  1549696413) },
      { -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1) } },
    { { -INT32_C(  1540631515),  INT32_C(  2099176603), -INT32_C(  2078216028),  INT32_C(   442671571), -INT32_C(   422432440),  INT32_C(   759312559),  INT32_C(  1306375889), -INT32_C(   701812047) },
      { -INT32_C(  1540631515),  INT32_C(  2099176603), -INT32_C(  2078216028),  INT32_C(   678872287), -INT32_C(   422432440),  INT32_C(  1255297145), -INT32_C(  1198018809), -INT32_C(   410074399) },
      { -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1) } },
    { { -INT32_C(   997944348),  INT32_C(  1324153432), -INT32_C(  1124861373),  INT32_C(  1359398218),  INT32_C(  1426693492),  INT32_C(  2017236832),  INT32_C(  1087095967),  INT32_C(  1315568746) },
      { -INT32_C(   418189937),  INT32_C(   724958952),  INT32_C(  1139222776),  INT32_C(  1637150189),  INT32_C(  1426693492), -INT32_C(   714870219),  INT32_C(   538259126),  INT32_C(  1315568746) },
      { -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1) } },
    { { -INT32_C(   323262977), -INT32_C(   582070190),  INT32_C(   600245486), -INT32_C(  1376245001), -INT32_C(  2100425384), -INT32_C(   147047029),  INT32_C(  1045093822), -INT32_C(  1296578125) },
      { -INT32_C(  2120256978), -INT32_C(  1335956030), -INT32_C(   388749839), -INT32_C(  1466512304),  INT32_C(  1697342682),  INT32_C(  1599891361), -INT32_C(   140597436), -INT32_C(  1633004176) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0) } },
    { { -INT32_C(   217051485), -INT32_C(  1248090405), -INT32_C(  1424308726),  INT32_C(  1896511277), -INT32_C(  1905678306), -INT32_C(   986967043), -INT32_C(  1840296868),  INT32_C(  1824098761) },
      {  INT32_C(  1935657368),  INT32_C(  2032728943), -INT32_C(   282836287), -INT32_C(   681562183), -INT32_C(   714749481),  INT32_C(   949654236), -INT32_C(  1479874082),  INT32_C(  1824098761) },
      { -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1) } },
    { { -INT32_C(  1591780376),  INT32_C(  1635352458),  INT32_C(   624352841),  INT32_C(  1314836592),  INT32_C(   754329785), -INT32_C(    97121620), -INT32_C(   323505027),  INT32_C(  1092414809) },
      { -INT32_C(   756860088),  INT32_C(    53763258), -INT32_C(  1423349190),  INT32_C(  1314836592),  INT32_C(  1545662383),  INT32_C(  2002147321), -INT32_C(   323505027),  INT32_C(  1134985210) },
      { -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1) } },
    { { -INT32_C(   271933004), -INT32_C(   672938968), -INT32_C(  1389165389),  INT32_C(  1713670491), -INT32_C(  1848997994), -INT32_C(  1059819514), -INT32_C(   566957575), -INT32_C(   402740173) },
      { -INT32_C(   271933004),  INT32_C(  1078835596),  INT32_C(   418218173),  INT32_C(  1713670491), -INT32_C(  1848997994), -INT32_C(  1285683783), -INT32_C(   566957575), -INT32_C(  1945530561) },
      { -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0) } },
    { { -INT32_C(   647097905), -INT32_C(  1166349022), -INT32_C(   279401674), -INT32_C(  1599949135), -INT32_C(  2000538551),  INT32_C(   454347715),  INT32_C(  1107302058),  INT32_C(   899163237) },
      {  INT32_C(  1477314358),  INT32_C(   705923316), -INT32_C(   451318988),  INT32_C(  1803926562), -INT32_C(  1275901968), -INT32_C(  1127282926),  INT32_C(  1107302058),  INT32_C(   699963379) },
      { -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256i a = simde_mm256_loadu_epi32(test_vec[i].a);
    simde__m256i b = simde_mm256_loadu_epi32(test_vec[i].b);
    simde__m256i r = simde_x_mm256_cmple_epi32(a, b);
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
    simde__m256i r = simde_x_mm256_cmple_epi32(a, b);

    simde_test_x86_write_i32x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_cmple_epi32_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int32_t a[8];
    const int32_t b[8];
    const simde__mmask8 r;
  } test_vec[] = {
    { { -INT32_C(   676032757), -INT32_C(  1220471585),  INT32_C(   656288713), -INT32_C(  1228551841), -INT32_C(   314923927), -INT32_C(   690793790),  INT32_C(  2042331638), -INT32_C(  1639227246) },
      { -INT32_C(   814350353), -INT32_C(   595151341),  INT32_C(  1073980641), -INT32_C(  1228551841), -INT32_C(   314923927),  INT32_C(  2047186819), -INT32_C(  1410088936),  INT32_C(   273235488) },
      UINT16_C(  190) },
    { {  INT32_C(  2006331401),  INT32_C(  1716424185),  INT32_C(  1100288958), -INT32_C(  1011115094),  INT32_C(  2087628379),  INT32_C(   697087980), -INT32_C(   377853067), -INT32_C(   650139696) },
      { -INT32_C(   799942953),  INT32_C(  1716424185),  INT32_C(  1566756018), -INT32_C(  1011115094), -INT32_C(  1187082548), -INT32_C(  1159542203),  INT32_C(    94592053), -INT32_C(   606084349) },
      UINT16_C(  206) },
    { {  INT32_C(   366976942), -INT32_C(  1965555779), -INT32_C(   767355251),  INT32_C(   378283488), -INT32_C(  2061815934), -INT32_C(   882836974), -INT32_C(    85521366), -INT32_C(  1669585682) },
      { -INT32_C(  2119083068), -INT32_C(   418674598), -INT32_C(   767355251),  INT32_C(   378283488), -INT32_C(  2021937036), -INT32_C(   715989845), -INT32_C(   691062040),  INT32_C(   577915742) },
      UINT16_C(  190) },
    { {  INT32_C(  1925816574),  INT32_C(  1516789477), -INT32_C(  1176378610), -INT32_C(  1483787329), -INT32_C(   864199059),  INT32_C(  1357836202), -INT32_C(  1101950446),  INT32_C(  1074280514) },
      { -INT32_C(  1095577127),  INT32_C(  1024989743), -INT32_C(  1176378610), -INT32_C(  1704688083), -INT32_C(  1905859868),  INT32_C(  1357836202),  INT32_C(   698495207),  INT32_C(  1097443944) },
      UINT16_C(  228) },
    { {  INT32_C(  1072750098),  INT32_C(  1238979684),  INT32_C(   148324406),  INT32_C(  2095888021),  INT32_C(  1336315622), -INT32_C(  1282404552),  INT32_C(  1616744491), -INT32_C(  1147976535) },
      { -INT32_C(  2013625565),  INT32_C(   248566744), -INT32_C(  1474910189),  INT32_C(  1160053342), -INT32_C(   929772656), -INT32_C(  1282404552),  INT32_C(  1583798453),  INT32_C(  1075443997) },
      UINT16_C(  160) },
    { { -INT32_C(  1633519040),  INT32_C(   233031548),  INT32_C(  1842706322),  INT32_C(  1366446492),  INT32_C(  1185929257),  INT32_C(  1334233298), -INT32_C(  1046196517),  INT32_C(   649791462) },
      { -INT32_C(    20685183), -INT32_C(  1207195611),  INT32_C(  1842706322),  INT32_C(  1527551793),  INT32_C(  1117895536),  INT32_C(  1586571395),  INT32_C(  1545614710), -INT32_C(  1098720452) },
      UINT16_C(  109) },
    { { -INT32_C(   641123161),  INT32_C(  1127536339),  INT32_C(   361092497),  INT32_C(  1936922365), -INT32_C(  1999662261), -INT32_C(  1471786641), -INT32_C(  2046360936),  INT32_C(  1888755401) },
      {  INT32_C(   776560218),  INT32_C(  1127536339),  INT32_C(  1356527443),  INT32_C(  1506037261),  INT32_C(  1356960737),  INT32_C(  2113480677), -INT32_C(   234684375),  INT32_C(  1888755401) },
      UINT16_C(  247) },
    { {  INT32_C(   500025872), -INT32_C(   109670120),  INT32_C(   155866916), -INT32_C(  1484373122),  INT32_C(  1654229571),  INT32_C(   417135650), -INT32_C(   784170072), -INT32_C(  1404161636) },
      {  INT32_C(   332012539), -INT32_C(   804437844),  INT32_C(   383408024), -INT32_C(   574725990),  INT32_C(   205543402),  INT32_C(   417135650),  INT32_C(  1020094111), -INT32_C(  1813505128) },
      UINT16_C(  108) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256i a = simde_mm256_loadu_epi32(test_vec[i].a);
    simde__m256i b = simde_mm256_loadu_epi32(test_vec[i].b);
    simde__mmask8 r = simde_mm256_cmple_epi32_mask(a, b);
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
    simde__mmask8 r = simde_mm256_cmple_epi32_mask(a, b);

    simde_test_x86_write_i32x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_mask_cmple_epi32_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k;
    const int32_t a[8];
    const int32_t b[8];
    const simde__mmask8 r;
  } test_vec[] = {
    { UINT8_C(173),
      { -INT32_C(  1516139509), -INT32_C(   679321619),  INT32_C(   182764215),  INT32_C(  2114324702),  INT32_C(   129684335),  INT32_C(   614114030),  INT32_C(  1208369493),  INT32_C(    13875445) },
      { -INT32_C(  1516139509), -INT32_C(  1962333996), -INT32_C(   912921110),  INT32_C(  2114324702),  INT32_C(  1550582126), -INT32_C(   125827421),  INT32_C(  1027638856), -INT32_C(  2076306625) },
      UINT8_C(  9) },
    { UINT8_C( 45),
      {  INT32_C(   413384572),  INT32_C(   126224390),  INT32_C(  2058019700), -INT32_C(   356342941), -INT32_C(   148307741),  INT32_C(   562015550),  INT32_C(   573430627),  INT32_C(  1053762498) },
      { -INT32_C(   396987678),  INT32_C(   126224390),  INT32_C(   594123200),  INT32_C(   537733948),  INT32_C(  1763128875),  INT32_C(   562015550),  INT32_C(   573430627), -INT32_C(  1116653349) },
      UINT8_C( 40) },
    { UINT8_C(174),
      { -INT32_C(  1469413251), -INT32_C(   858486122),  INT32_C(   934296993), -INT32_C(  2136410424), -INT32_C(  1738810529),  INT32_C(   339941452),  INT32_C(  1371105469), -INT32_C(   109109636) },
      {  INT32_C(  1034086823),  INT32_C(   336164467),  INT32_C(  2085337523),  INT32_C(   268235696),  INT32_C(   447174862),  INT32_C(   339941452), -INT32_C(   813701037), -INT32_C(   109109636) },
      UINT8_C(174) },
    { UINT8_C(189),
      { -INT32_C(  1403121479),  INT32_C(  1702522125), -INT32_C(     2779883), -INT32_C(  1403911228), -INT32_C(  2118966653),  INT32_C(  1449746923),  INT32_C(  1094173516), -INT32_C(   336606414) },
      { -INT32_C(   375894564), -INT32_C(   816966982), -INT32_C(     2779883), -INT32_C(  1441259225), -INT32_C(  2118966653),  INT32_C(  2038731821),  INT32_C(  1094173516),  INT32_C(  1668655495) },
      UINT8_C(181) },
    { UINT8_C( 84),
      {  INT32_C(  1910780751),  INT32_C(   380931659),  INT32_C(  1313072058),  INT32_C(   598130023),  INT32_C(   564801655), -INT32_C(  1290334810), -INT32_C(   204224423), -INT32_C(  1733256375) },
      {  INT32_C(  1910780751), -INT32_C(   584073693),  INT32_C(   137130913), -INT32_C(  1490300368), -INT32_C(  1446456061),  INT32_C(   995942626), -INT32_C(   248631128), -INT32_C(  1718951989) },
      UINT8_C(  0) },
    { UINT8_C(  5),
      {  INT32_C(  1938095009), -INT32_C(    59364314), -INT32_C(   723640332), -INT32_C(  1401087364),  INT32_C(   662138440), -INT32_C(  1935994632), -INT32_C(  1545784382),  INT32_C(  1241043112) },
      { -INT32_C(   239305525), -INT32_C(  1645399128), -INT32_C(   831402926), -INT32_C(  1401087364),  INT32_C(  1431761245), -INT32_C(  1008602879), -INT32_C(   865616092),  INT32_C(  1511350159) },
      UINT8_C(  0) },
    { UINT8_C(241),
      { -INT32_C(  2115295598), -INT32_C(  1830938208),  INT32_C(  1637036911), -INT32_C(   729458923),  INT32_C(   493048510),  INT32_C(   972602727),  INT32_C(  1094614024),  INT32_C(   809932445) },
      {  INT32_C(  1555116476), -INT32_C(  1158770869), -INT32_C(   686062910), -INT32_C(   729458923),  INT32_C(  1521749747), -INT32_C(   728453941), -INT32_C(   971648471),  INT32_C(   620125288) },
      UINT8_C( 17) },
    { UINT8_C( 44),
      {  INT32_C(  1338691758), -INT32_C(  1975361156), -INT32_C(  1034511083),  INT32_C(    65743409), -INT32_C(  1687375553),  INT32_C(  1328124072), -INT32_C(  2121924335),  INT32_C(  1131577236) },
      { -INT32_C(   879608497), -INT32_C(  1269377634), -INT32_C(  1552503694),  INT32_C(   363225558), -INT32_C(  1162800622),  INT32_C(  1328124072),  INT32_C(  1882558683),  INT32_C(  1131577236) },
      UINT8_C( 40) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__mmask8 k = test_vec[i].k;
    simde__m256i a = simde_mm256_loadu_epi32(test_vec[i].a);
    simde__m256i b = simde_mm256_loadu_epi32(test_vec[i].b);
    simde__mmask8 r = simde_mm256_mask_cmple_epi32_mask(k, a, b);
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
    simde__mmask8 r = simde_mm256_mask_cmple_epi32_mask(k, a, b);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_x_mm512_cmple_epi32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int32_t a[16];
    const int32_t b[16];
    const int32_t r[16];
  } test_vec[] = {
    { {  INT32_C(   577295616), -INT32_C(  2121405039),  INT32_C(  1177911348), -INT32_C(  1509817208), -INT32_C(   970391085),  INT32_C(   921756312), -INT32_C(   121081175),  INT32_C(   125600775),
        -INT32_C(   349510567),  INT32_C(   107788242), -INT32_C(  1068654280),  INT32_C(  2019970981), -INT32_C(   398487728),  INT32_C(   438185841), -INT32_C(  1475090783), -INT32_C(   995127446) },
      {  INT32_C(  1169152371), -INT32_C(   917759087),  INT32_C(  1653184957),  INT32_C(   970715112), -INT32_C(   266265986), -INT32_C(   368426935), -INT32_C(  1852695258),  INT32_C(   542458284),
        -INT32_C(   349510567), -INT32_C(   596266721), -INT32_C(  1068654280),  INT32_C(  1802246893),  INT32_C(  2103151924),  INT32_C(   438185841),  INT32_C(   814086531),  INT32_C(  1431362106) },
      { -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),
        -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1) } },
    { { -INT32_C(  1411110690),  INT32_C(   312429454),  INT32_C(  2118263876), -INT32_C(   590048514), -INT32_C(  1361390265), -INT32_C(  1067404212),  INT32_C(     2245837),  INT32_C(  1936191381),
        -INT32_C(  1507964137), -INT32_C(   625426794), -INT32_C(   514262302), -INT32_C(   742577012),  INT32_C(  1317181186),  INT32_C(   403628619), -INT32_C(  1156042714),  INT32_C(   925794079) },
      {  INT32_C(  1625116106), -INT32_C(   314927861),  INT32_C(   466523023), -INT32_C(  1041331009),  INT32_C(  1863282723),  INT32_C(  2038898258),  INT32_C(  1848942670), -INT32_C(   358259937),
        -INT32_C(  1152744784), -INT32_C(   625426794), -INT32_C(   675186920), -INT32_C(   742577012),  INT32_C(  1922410528),  INT32_C(   367730118), -INT32_C(   595386179),  INT32_C(   868624515) },
      { -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),
        -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0) } },
    { { -INT32_C(  1922380601), -INT32_C(  1499310615), -INT32_C(   125622923), -INT32_C(   148158131), -INT32_C(   256370342), -INT32_C(  1113710672),  INT32_C(   533603399),  INT32_C(   152438082),
        -INT32_C(  1147698991),  INT32_C(  1264662998), -INT32_C(  1404771233), -INT32_C(  2002489554),  INT32_C(   964254857), -INT32_C(  1007282308),  INT32_C(  2128790587), -INT32_C(  1685587511) },
      {  INT32_C(  1331043961), -INT32_C(  1214531752), -INT32_C(   125622923), -INT32_C(   682490034), -INT32_C(   256370342),  INT32_C(   514000867), -INT32_C(  1784903989), -INT32_C(   131062657),
        -INT32_C(  1706523070),  INT32_C(  1264662998),  INT32_C(   279164354),  INT32_C(   552138428), -INT32_C(  1543440191), -INT32_C(   876370689),  INT32_C(  2128790587), -INT32_C(  1685587511) },
      { -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),
         INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1) } },
    { {  INT32_C(  2133607551),  INT32_C(   306900968), -INT32_C(   759453105),  INT32_C(  1352162618),  INT32_C(   329513286),  INT32_C(   312594603),  INT32_C(  1731543201),  INT32_C(  1206876615),
        -INT32_C(  1496965954),  INT32_C(  1522077707), -INT32_C(   198347590),  INT32_C(   407160273),  INT32_C(  1764485054),  INT32_C(  1501285560), -INT32_C(   725569267), -INT32_C(   400838614) },
      {  INT32_C(  2133607551), -INT32_C(  1422767887), -INT32_C(  1902157892), -INT32_C(   475602140), -INT32_C(  2092117557),  INT32_C(   312594603), -INT32_C(  1551917959),  INT32_C(   411867724),
         INT32_C(  1844452220),  INT32_C(  1522077707), -INT32_C(   198347590),  INT32_C(  1736987548),  INT32_C(  1764485054),  INT32_C(  1501285560), -INT32_C(   725569267), -INT32_C(   400838614) },
      { -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),
        -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1) } },
    { { -INT32_C(    87413155),  INT32_C(  1443903476), -INT32_C(  1476015582),  INT32_C(  1890241807),  INT32_C(  1580407428), -INT32_C(   474474846), -INT32_C(  1950304089), -INT32_C(  1634532287),
         INT32_C(   647585330), -INT32_C(  1216501355), -INT32_C(  2090827149), -INT32_C(   722269617), -INT32_C(   953014748), -INT32_C(   458560963), -INT32_C(   462459997), -INT32_C(  1568538001) },
      { -INT32_C(    87413155),  INT32_C(   950879685),  INT32_C(   398134728),  INT32_C(  1890241807),  INT32_C(   302194133), -INT32_C(  1409897208), -INT32_C(  1950304089), -INT32_C(   936767129),
        -INT32_C(   222432723), -INT32_C(  1216501355), -INT32_C(  2090827149), -INT32_C(   722269617),  INT32_C(   679202336), -INT32_C(  1798082181),  INT32_C(  1042047702), -INT32_C(  1593424268) },
      { -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),
         INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0) } },
    { {  INT32_C(  1238638029),  INT32_C(  1709025166),  INT32_C(  2124675338),  INT32_C(  1998563647), -INT32_C(  1696026004),  INT32_C(   322984047),  INT32_C(  1800107232),  INT32_C(  1092086900),
        -INT32_C(  1735726327), -INT32_C(  1661114478), -INT32_C(  1625644960), -INT32_C(  1256769207),  INT32_C(  1532035051),  INT32_C(   946770007),  INT32_C(  2023995652), -INT32_C(  1346717019) },
      {  INT32_C(   944194725),  INT32_C(   215237804),  INT32_C(   766308324),  INT32_C(  1998563647),  INT32_C(   426717890),  INT32_C(   322984047),  INT32_C(   994047382),  INT32_C(  1441462703),
        -INT32_C(   359845570), -INT32_C(  1661114478), -INT32_C(  1625644960), -INT32_C(  1256769207),  INT32_C(  1581382811),  INT32_C(  1864733401),  INT32_C(  2023995652), -INT32_C(  1346717019) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),
        -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1) } },
    { { -INT32_C(  1501631027),  INT32_C(   118858623),  INT32_C(  1715388168),  INT32_C(   453167700),  INT32_C(  1566017763),  INT32_C(   589884420), -INT32_C(  1918342136),  INT32_C(   179196989),
        -INT32_C(  1062196159), -INT32_C(   657996336), -INT32_C(   650246779), -INT32_C(  1292615473), -INT32_C(   871347256),  INT32_C(  1089484856), -INT32_C(   489776987),  INT32_C(   770538732) },
      {  INT32_C(  2028838312),  INT32_C(   118858623), -INT32_C(  1967026502), -INT32_C(  1774405938),  INT32_C(   962808833),  INT32_C(   589884420), -INT32_C(   687060757),  INT32_C(  1812265412),
        -INT32_C(    85593705),  INT32_C(  1642214822), -INT32_C(   650246779),  INT32_C(  1529423705), -INT32_C(   871347256), -INT32_C(   903672097), -INT32_C(   489776987),  INT32_C(   770538732) },
      { -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),
        -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1) } },
    { { -INT32_C(  1944221523), -INT32_C(   313114473), -INT32_C(  1727465616),  INT32_C(   844730268), -INT32_C(  1670441989), -INT32_C(   301855313),  INT32_C(  1200093846), -INT32_C(   932480229),
        -INT32_C(  1688958716),  INT32_C(   965257929),  INT32_C(  1037209761),  INT32_C(   443493151), -INT32_C(   306716866), -INT32_C(  2082686484), -INT32_C(   825597005), -INT32_C(   476695073) },
      { -INT32_C(  2004948290),  INT32_C(   901842580), -INT32_C(  1234004841), -INT32_C(    19799617), -INT32_C(  1377072960), -INT32_C(   198129855),  INT32_C(   180550187), -INT32_C(   932480229),
        -INT32_C(   696882366),  INT32_C(   134952817), -INT32_C(  1950384693),  INT32_C(   529109086),  INT32_C(  1506571288), -INT32_C(  2082686484), -INT32_C(   825597005), -INT32_C(  1458348441) },
      {  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),
        -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i a = simde_mm512_loadu_epi32(test_vec[i].a);
    simde__m512i b = simde_mm512_loadu_epi32(test_vec[i].b);
    simde__m512i r = simde_x_mm512_cmple_epi32(a, b);
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
    simde__m512i r = simde_x_mm512_cmple_epi32(a, b);

    simde_test_x86_write_i32x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_cmple_epi32_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int32_t a[16];
    const int32_t b[16];
    const simde__mmask16 r;
  } test_vec[] = {
    { {  INT32_C(   994357701),  INT32_C(   688848153), -INT32_C(  2104233397), -INT32_C(  1611306108),  INT32_C(  1953885069), -INT32_C(   273992678),  INT32_C(  1152847471),  INT32_C(   643007584),
         INT32_C(  1315018805), -INT32_C(   529043563), -INT32_C(   429782430),  INT32_C(    42293109),  INT32_C(  1568078403), -INT32_C(  1655954898), -INT32_C(  1847458768), -INT32_C(  1112066680) },
      {  INT32_C(  1661671629), -INT32_C(   381451641),  INT32_C(    47163020),  INT32_C(  1074025725),  INT32_C(  2090695502), -INT32_C(   853874019),  INT32_C(  1985936622), -INT32_C(    13429455),
        -INT32_C(  1251852755),  INT32_C(  1285465536), -INT32_C(   429782430),  INT32_C(   294212546),  INT32_C(  1568078403), -INT32_C(    13064431), -INT32_C(   713713757), -INT32_C(   623597396) },
      UINT16_C(65117) },
    { {  INT32_C(   835583008),  INT32_C(  1194329508),  INT32_C(  1226614172),  INT32_C(   857993293),  INT32_C(    47821350),  INT32_C(  2066336991), -INT32_C(  1579575027), -INT32_C(  1291630446),
        -INT32_C(   387657660),  INT32_C(  1915753941),  INT32_C(   146492602),  INT32_C(  1664867901),  INT32_C(  1868895632), -INT32_C(   286617887), -INT32_C(  1164983513),  INT32_C(  1349358091) },
      {  INT32_C(   926437730),  INT32_C(   564750438), -INT32_C(   232168267),  INT32_C(   857993293),  INT32_C(  1514322809),  INT32_C(  2066336991), -INT32_C(    81012752), -INT32_C(  1291630446),
         INT32_C(  1342407913), -INT32_C(  1586385684),  INT32_C(  1402182161),  INT32_C(  1664867901), -INT32_C(   304977756), -INT32_C(  2074207340), -INT32_C(  1164983513),  INT32_C(   187157281) },
      UINT16_C(19961) },
    { {  INT32_C(  1592504265), -INT32_C(  1126020406), -INT32_C(   182951213),  INT32_C(  2097168430),  INT32_C(  1102666602), -INT32_C(  1926654169),  INT32_C(  1659987208), -INT32_C(  1872703802),
         INT32_C(  1206799229),  INT32_C(  1761857685),  INT32_C(  1633557555), -INT32_C(   958505380), -INT32_C(   536307527),  INT32_C(   929902895),  INT32_C(  1570332310), -INT32_C(  1444021972) },
      { -INT32_C(   621749436), -INT32_C(  1126020406), -INT32_C(   182951213), -INT32_C(  1204674817), -INT32_C(   443008330),  INT32_C(    35390828), -INT32_C(  1872775837), -INT32_C(  1872703802),
        -INT32_C(   741594585),  INT32_C(   783355678), -INT32_C(  1348800080), -INT32_C(   983053297),  INT32_C(  1940586247),  INT32_C(  1752548868),  INT32_C(   704173435),  INT32_C(  1226518817) },
      UINT16_C(45222) },
    { { -INT32_C(  1014481730),  INT32_C(  2100034818), -INT32_C(   190438446), -INT32_C(  1338129836), -INT32_C(  1591125590), -INT32_C(   448147162),  INT32_C(   548577554),  INT32_C(   506807648),
        -INT32_C(  2065580671), -INT32_C(  1929311045), -INT32_C(  2071877585),  INT32_C(   339000938),  INT32_C(  1052073239),  INT32_C(  1092878126),  INT32_C(     6411680), -INT32_C(  1675716838) },
      {  INT32_C(   253755476),  INT32_C(  1016930572), -INT32_C(   190438446), -INT32_C(   196610851), -INT32_C(  2144141999), -INT32_C(  1665051140),  INT32_C(  1167860267),  INT32_C(   506807648),
        -INT32_C(   954400326), -INT32_C(   335300061), -INT32_C(  1239366695),  INT32_C(   145385399),  INT32_C(  1619582308),  INT32_C(  1576814898),  INT32_C(   631478380),  INT32_C(   221480019) },
      UINT16_C(63437) },
    { {  INT32_C(  1424155170), -INT32_C(  1733108180), -INT32_C(   893561481),  INT32_C(  1607987673),  INT32_C(  1292414018),  INT32_C(   506633859),  INT32_C(  1886374995),  INT32_C(   871549201),
        -INT32_C(   662121300),  INT32_C(   695220914),  INT32_C(  1760767375),  INT32_C(  1623771934), -INT32_C(    89206665), -INT32_C(  1038557074), -INT32_C(  1103984468), -INT32_C(    34528175) },
      { -INT32_C(  1412072968),  INT32_C(  1121207731), -INT32_C(  1851013005),  INT32_C(   183661459), -INT32_C(  1308319677),  INT32_C(   745807232), -INT32_C(   152394075),  INT32_C(   871549201),
         INT32_C(   158255445), -INT32_C(  2108996849), -INT32_C(  1642858997), -INT32_C(  1381497495), -INT32_C(    89206665),  INT32_C(  1850921929),  INT32_C(  1147485305),  INT32_C(  1846040856) },
      UINT16_C(61858) },
    { { -INT32_C(  2137575753),  INT32_C(  2079320321),  INT32_C(  1052726310), -INT32_C(   810760275), -INT32_C(   150920386), -INT32_C(  1615022874),  INT32_C(  1220615803), -INT32_C(   524644055),
        -INT32_C(  1050652225),  INT32_C(  1631342395),  INT32_C(  1352661923),  INT32_C(    18894019),  INT32_C(  1442324847),  INT32_C(  1374991573), -INT32_C(    57035053),  INT32_C(   115102535) },
      { -INT32_C(   540590940),  INT32_C(   792724364), -INT32_C(  1031741185), -INT32_C(  1681678292), -INT32_C(  1762542655),  INT32_C(  1139271024),  INT32_C(  1220615803),  INT32_C(  2028542931),
        -INT32_C(   480792489), -INT32_C(  1290561356), -INT32_C(  1535798408),  INT32_C(    18894019),  INT32_C(  1670000883), -INT32_C(  1314491882), -INT32_C(    57035053),  INT32_C(  1480490240) },
      UINT16_C(55777) },
    { { -INT32_C(   812084295), -INT32_C(   142524667),  INT32_C(   633148708), -INT32_C(  1082262638), -INT32_C(  1096697711), -INT32_C(   396086009), -INT32_C(  2130858689), -INT32_C(   256572106),
        -INT32_C(  1648406888), -INT32_C(  1315618675), -INT32_C(   405384619), -INT32_C(   542682290),  INT32_C(   329074700), -INT32_C(  1124400771), -INT32_C(   448923473), -INT32_C(  1764363522) },
      { -INT32_C(   852191936),  INT32_C(   729795029),  INT32_C(  1762809115), -INT32_C(  1253525079),  INT32_C(  2143872513), -INT32_C(  1774468121), -INT32_C(  2130858689), -INT32_C(   256572106),
        -INT32_C(  1132886810),  INT32_C(  1776810061), -INT32_C(   153945779), -INT32_C(  1263854669), -INT32_C(   399281407), -INT32_C(   209752265),  INT32_C(  1387133927),  INT32_C(   872349004) },
      UINT16_C(59350) },
    { {  INT32_C(   152005330), -INT32_C(  1040412967), -INT32_C(   703354487),  INT32_C(   671682982), -INT32_C(   134678392), -INT32_C(  1649135410),  INT32_C(  1629513531), -INT32_C(  1752672315),
        -INT32_C(  1683973951), -INT32_C(  1336107994), -INT32_C(   326734011),  INT32_C(   152342401),  INT32_C(  1426132103),  INT32_C(  2029172029), -INT32_C(   505802212),  INT32_C(   729375337) },
      {  INT32_C(   152005330), -INT32_C(  1040412967),  INT32_C(   317151121),  INT32_C(  1830616294),  INT32_C(  1170349320), -INT32_C(   289491758),  INT32_C(  1629513531), -INT32_C(   178566918),
         INT32_C(   404103522), -INT32_C(  1336107994),  INT32_C(   619182910),  INT32_C(   152342401), -INT32_C(   230337760), -INT32_C(   824179961), -INT32_C(  1778405221),  INT32_C(   729375337) },
      UINT16_C(36863) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i a = simde_mm512_loadu_epi32(test_vec[i].a);
    simde__m512i b = simde_mm512_loadu_epi32(test_vec[i].b);
    simde__mmask16 r = simde_mm512_cmple_epi32_mask(a, b);
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
    simde__mmask16 r = simde_mm512_cmple_epi32_mask(a, b);

    simde_test_x86_write_i32x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_mask_cmple_epi32_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask16 k;
    const int32_t a[16];
    const int32_t b[16];
    const simde__mmask16 r;
  } test_vec[] = {
    { UINT16_C(42980),
      { -INT32_C(   711803699),  INT32_C(  1520661439),  INT32_C(   468754979),  INT32_C(  2037807869), -INT32_C(  1573328869), -INT32_C(   278344338), -INT32_C(   932753079), -INT32_C(  1721180212),
         INT32_C(  1534000027), -INT32_C(  1850404242), -INT32_C(  1314085452),  INT32_C(   992616992),  INT32_C(  2044551947),  INT32_C(  2036942128),  INT32_C(  1665257623),  INT32_C(  1274849967) },
      {  INT32_C(   329673637),  INT32_C(   832854909),  INT32_C(   568545281),  INT32_C(  2119961971), -INT32_C(  1594410640),  INT32_C(   370761855), -INT32_C(   932753079), -INT32_C(  1439992571),
         INT32_C(  1572721120),  INT32_C(   781148461), -INT32_C(  1314085452), -INT32_C(   257774721),  INT32_C(  1670421220),  INT32_C(   729393914),  INT32_C(   168620549),  INT32_C(  1219770216) },
      UINT16_C( 2020) },
    { UINT16_C(60168),
      {  INT32_C(   525459366),  INT32_C(   370300426),  INT32_C(   340687456),  INT32_C(  1753569218), -INT32_C(   241346675), -INT32_C(  2103163686), -INT32_C(  2117270933), -INT32_C(   366431932),
        -INT32_C(  1693812336),  INT32_C(   800136399),  INT32_C(  1480851350), -INT32_C(   473839530), -INT32_C(    86745569),  INT32_C(   243038371), -INT32_C(  1081128582), -INT32_C(  1951811333) },
      {  INT32_C(   525459366),  INT32_C(  1697700047),  INT32_C(   340687456),  INT32_C(  1544650556), -INT32_C(   241346675), -INT32_C(   644951458),  INT32_C(   395845148),  INT32_C(   128074198),
        -INT32_C(  1006056971),  INT32_C(   800136399), -INT32_C(   374937427),  INT32_C(  1145419879), -INT32_C(    86745569),  INT32_C(   243038371),  INT32_C(  1201761649), -INT32_C(  1538309201) },
      UINT16_C(60160) },
    { UINT16_C(37418),
      { -INT32_C(   197233121), -INT32_C(  1587367936),  INT32_C(  1189351927),  INT32_C(   496955829), -INT32_C(   995086690), -INT32_C(  1819202964),  INT32_C(   855577868),  INT32_C(  1461520184),
         INT32_C(  2102090621),  INT32_C(    52342027),  INT32_C(  1934164926), -INT32_C(  1835931660), -INT32_C(  2108210922),  INT32_C(  1997924459),  INT32_C(   900273405), -INT32_C(  1718827492) },
      {  INT32_C(   756537378),  INT32_C(  1144010117),  INT32_C(   750221880),  INT32_C(  2009024609), -INT32_C(   168225143), -INT32_C(    76804354),  INT32_C(   855577868), -INT32_C(    19350052),
         INT32_C(   455929749),  INT32_C(  1566530597),  INT32_C(   948573910), -INT32_C(  1835931660),  INT32_C(  1574807903), -INT32_C(   631747913),  INT32_C(   900273405), -INT32_C(   600051129) },
      UINT16_C(37418) },
    { UINT16_C(37071),
      {  INT32_C(  1272767219), -INT32_C(   690668356), -INT32_C(  1278731144), -INT32_C(   266688008),  INT32_C(   340188848),  INT32_C(  1241691000),  INT32_C(   885733759), -INT32_C(  1027148081),
        -INT32_C(  1811045672),  INT32_C(  1449845470), -INT32_C(   150326530), -INT32_C(  1931008804),  INT32_C(  2057317634),  INT32_C(  1623499489), -INT32_C(  1433104165),  INT32_C(  1584159366) },
      { -INT32_C(   621643268), -INT32_C(   690668356),  INT32_C(  1800485775),  INT32_C(  1660368991),  INT32_C(  1205639014),  INT32_C(  1241691000), -INT32_C(  1212269519), -INT32_C(  1027148081),
        -INT32_C(  1811045672), -INT32_C(   195387804),  INT32_C(   962571481), -INT32_C(  1931008804),  INT32_C(  2057317634),  INT32_C(  1623499489),  INT32_C(   184613749), -INT32_C(   912386779) },
      UINT16_C( 4238) },
    { UINT16_C( 9770),
      {  INT32_C(  2143938626),  INT32_C(   846872113), -INT32_C(   397959350),  INT32_C(   854877289),  INT32_C(  1532403686), -INT32_C(   533715421), -INT32_C(   633840421), -INT32_C(  1184233609),
         INT32_C(   557331695), -INT32_C(  1135365518), -INT32_C(  1146774958), -INT32_C(   437413377),  INT32_C(  1530938424),  INT32_C(  1161523562),  INT32_C(  1142911949),  INT32_C(  1795066491) },
      {  INT32_C(  2143938626),  INT32_C(  1005444841),  INT32_C(  2029425273),  INT32_C(  1683874603), -INT32_C(  1832936153), -INT32_C(   589825266), -INT32_C(   383715474),  INT32_C(  1062477441),
         INT32_C(  1047519061), -INT32_C(  1135365518),  INT32_C(   447705070), -INT32_C(   437413377),  INT32_C(  1530938424), -INT32_C(  1483414728),  INT32_C(  1536210138),  INT32_C(   681239763) },
      UINT16_C( 1546) },
    { UINT16_C( 6607),
      {  INT32_C(  1762288597), -INT32_C(  1709251574), -INT32_C(   629149376),  INT32_C(  2145665817),  INT32_C(  2120108997),  INT32_C(   266775712),  INT32_C(  1744591436),  INT32_C(  1301096055),
        -INT32_C(  1816750199), -INT32_C(  1137781636), -INT32_C(   560550459), -INT32_C(  1252164624),  INT32_C(  1714666438), -INT32_C(  1267394201), -INT32_C(   367300237),  INT32_C(   557295767) },
      { -INT32_C(  1128993216), -INT32_C(  2005343550),  INT32_C(  2137394831),  INT32_C(  2145665817), -INT32_C(   407541889), -INT32_C(   207934848),  INT32_C(   870233755), -INT32_C(  1638656674),
        -INT32_C(   967178237), -INT32_C(  1137781636),  INT32_C(  1794815201), -INT32_C(   122016136),  INT32_C(   383741846),  INT32_C(   889879194), -INT32_C(  1905727440),  INT32_C(    19774717) },
      UINT16_C( 2316) },
    { UINT16_C(51929),
      {  INT32_C(   160655871),  INT32_C(   133284766),  INT32_C(  2126770001), -INT32_C(  1224308496),  INT32_C(  1674338360),  INT32_C(  1082627483),  INT32_C(   295754455), -INT32_C(  1020629053),
         INT32_C(  1993129432), -INT32_C(   763511168), -INT32_C(  1655684691),  INT32_C(    39081673),  INT32_C(  1365582006), -INT32_C(  1919750987), -INT32_C(  1969343801),  INT32_C(  2035141025) },
      {  INT32_C(   133110406), -INT32_C(  2049348136),  INT32_C(  1998727598),  INT32_C(   913929856),  INT32_C(  1674338360),  INT32_C(  1082627483),  INT32_C(   295754455), -INT32_C(  1020629053),
         INT32_C(  1556960644), -INT32_C(   763511168), -INT32_C(  1655684691),  INT32_C(    39081673),  INT32_C(   190451264),  INT32_C(  1956459304), -INT32_C(   362694230), -INT32_C(  1481586909) },
      UINT16_C(19160) },
    { UINT16_C(62656),
      { -INT32_C(  2114125084), -INT32_C(   667179146),  INT32_C(  1100963473),  INT32_C(   163560454), -INT32_C(   319888228),  INT32_C(   488953304), -INT32_C(  1511473866),  INT32_C(  2070921623),
         INT32_C(   989686979), -INT32_C(  1542309869), -INT32_C(  1662602858),  INT32_C(   178693486),  INT32_C(  1660327049), -INT32_C(  1619060119),  INT32_C(  1850042327), -INT32_C(   320162776) },
      {  INT32_C(   874964769), -INT32_C(  1244055521),  INT32_C(  1465040873), -INT32_C(   295569308), -INT32_C(   179284084),  INT32_C(  1234554737),  INT32_C(  1589107254), -INT32_C(  1354063474),
        -INT32_C(  1478201208), -INT32_C(  1839350360), -INT32_C(   521556100),  INT32_C(   869157799),  INT32_C(  1660327049),  INT32_C(   593346029),  INT32_C(  1850042327),  INT32_C(  1054198966) },
      UINT16_C(62528) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__mmask16 k = test_vec[i].k;
    simde__m512i a = simde_mm512_loadu_epi32(test_vec[i].a);
    simde__m512i b = simde_mm512_loadu_epi32(test_vec[i].b);
    simde__mmask16 r = simde_mm512_mask_cmple_epi32_mask(k, a, b);
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
    simde__mmask16 r = simde_mm512_mask_cmple_epi32_mask(k, a, b);

    simde_test_x86_write_mmask16(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x16(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_x_mm_cmple_epu32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const uint32_t a[4];
    const uint32_t b[4];
    const uint32_t r[4];
  } test_vec[] = {
    { { UINT32_C(2007884217), UINT32_C(4003892444), UINT32_C(2201152985), UINT32_C(2618951952) },
      { UINT32_C(2007884217), UINT32_C(4003892444), UINT32_C(1063170571), UINT32_C(2618951952) },
      {           UINT32_MAX,           UINT32_MAX, UINT32_C(         0),           UINT32_MAX } },
    { { UINT32_C(1639160200), UINT32_C(2531583366), UINT32_C(3929210606), UINT32_C(2995374446) },
      { UINT32_C(1639160200), UINT32_C(   1405758), UINT32_C(1669096570), UINT32_C(3894898528) },
      {           UINT32_MAX, UINT32_C(         0), UINT32_C(         0),           UINT32_MAX } },
    { { UINT32_C(2904894911), UINT32_C(2576897835), UINT32_C(3964412193), UINT32_C(3955450285) },
      { UINT32_C(1340856532), UINT32_C(2628937788), UINT32_C(3766802903), UINT32_C(1936641460) },
      { UINT32_C(         0),           UINT32_MAX, UINT32_C(         0), UINT32_C(         0) } },
    { { UINT32_C( 213891563), UINT32_C(2281180122), UINT32_C(1098038124), UINT32_C(3499122324) },
      { UINT32_C(2641183430), UINT32_C(3481137435), UINT32_C(3108236479), UINT32_C(1793025151) },
      {           UINT32_MAX,           UINT32_MAX,           UINT32_MAX, UINT32_C(         0) } },
    { { UINT32_C( 394227626), UINT32_C(3193499946), UINT32_C( 361752655), UINT32_C(1169423402) },
      { UINT32_C( 394227626), UINT32_C(2623952924), UINT32_C(3641066940), UINT32_C(2412805604) },
      {           UINT32_MAX, UINT32_C(         0),           UINT32_MAX,           UINT32_MAX } },
    { { UINT32_C(2429943361), UINT32_C( 279340262), UINT32_C(1297439072), UINT32_C(2801429129) },
      { UINT32_C(2118279362), UINT32_C(2320976037), UINT32_C(2971216069), UINT32_C(3100163959) },
      { UINT32_C(         0),           UINT32_MAX,           UINT32_MAX,           UINT32_MAX } },
    { { UINT32_C(1639182081), UINT32_C(3517843528), UINT32_C( 897034355), UINT32_C(2931079432) },
      { UINT32_C(3342338818), UINT32_C(2876854579), UINT32_C( 897034355), UINT32_C(3748703454) },
      {           UINT32_MAX, UINT32_C(         0),           UINT32_MAX,           UINT32_MAX } },
    { { UINT32_C(2662723115), UINT32_C(2681482391), UINT32_C(3897395430), UINT32_C(3350168979) },
      { UINT32_C(3866241238), UINT32_C(1202967913), UINT32_C(3897395430), UINT32_C(3350168979) },
      {           UINT32_MAX, UINT32_C(         0),           UINT32_MAX,           UINT32_MAX } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_x_mm_loadu_epi32(test_vec[i].a);
    simde__m128i b = simde_x_mm_loadu_epi32(test_vec[i].b);
    simde__m128i r = simde_x_mm_cmple_epu32(a, b);
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
    simde__m128i r = simde_x_mm_cmple_epu32(a, b);

    simde_test_x86_write_u32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_u32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_u32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_cmple_epu32_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const uint32_t a[4];
    const uint32_t b[4];
    const simde__mmask8 r;
  } test_vec[] = {
    { { UINT32_C(2479520121), UINT32_C(1719995145), UINT32_C(3567432133), UINT32_C(3575138209) },
      { UINT32_C(2479520121), UINT32_C(3043708927), UINT32_C(1284070362), UINT32_C(4039090038) },
      UINT8_C( 11) },
    { { UINT32_C(1518798997), UINT32_C(1529752250), UINT32_C(2570078065), UINT32_C(1811627628) },
      { UINT32_C(1746954125), UINT32_C( 968141250), UINT32_C(2570078065), UINT32_C(2457971965) },
      UINT8_C( 13) },
    { { UINT32_C(2764708659), UINT32_C(3460168290), UINT32_C(3325638969), UINT32_C(1647204768) },
      { UINT32_C(1268507139), UINT32_C(1403831382), UINT32_C( 652619121), UINT32_C(1771426358) },
      UINT8_C(  8) },
    { { UINT32_C(2451393369), UINT32_C( 609834628), UINT32_C(3012003760), UINT32_C(3237880426) },
      { UINT32_C(1477683943), UINT32_C( 243202520), UINT32_C(3111654348), UINT32_C(3406399090) },
      UINT8_C( 12) },
    { { UINT32_C( 763017085), UINT32_C(2833252670), UINT32_C( 191421988), UINT32_C(1633909897) },
      { UINT32_C(1097851253), UINT32_C(1727784948), UINT32_C( 191421988), UINT32_C(2811596586) },
      UINT8_C( 13) },
    { { UINT32_C( 892187665), UINT32_C( 473994899), UINT32_C(2273157906), UINT32_C(2026499204) },
      { UINT32_C(1105118420), UINT32_C( 473994899), UINT32_C(3852080543), UINT32_C( 912944677) },
      UINT8_C(  7) },
    { { UINT32_C(1087548206), UINT32_C(3536277326), UINT32_C( 256544827), UINT32_C( 475080788) },
      { UINT32_C(1087548206), UINT32_C( 213690855), UINT32_C( 256544827), UINT32_C(3975196094) },
      UINT8_C( 13) },
    { { UINT32_C(1299772433), UINT32_C(3646734980), UINT32_C( 569748970), UINT32_C(1727530111) },
      { UINT32_C(3312628909), UINT32_C(2583672026), UINT32_C(3112562785), UINT32_C(3294606002) },
      UINT8_C( 13) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_x_mm_loadu_epi32(test_vec[i].a);
    simde__m128i b = simde_x_mm_loadu_epi32(test_vec[i].b);
    simde__mmask8 r = simde_mm_cmple_epu32_mask(a, b);
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
    simde__mmask8 r = simde_mm_cmple_epu32_mask(a, b);

    simde_test_x86_write_u32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_u32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_mask_cmple_epu32_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k;
    const uint32_t a[4];
    const uint32_t b[4];
    const simde__mmask8 r;
  } test_vec[] = {
    { UINT8_C( 94),
      { UINT32_C( 466847294), UINT32_C(1027282440), UINT32_C( 876632995), UINT32_C(2396219020) },
      { UINT32_C(2558868179), UINT32_C(1027282440), UINT32_C( 244705920), UINT32_C(3077950841) },
      UINT8_C( 10) },
    { UINT8_C(180),
      { UINT32_C(1761777678), UINT32_C(1056323288), UINT32_C(1142064138), UINT32_C(3517426185) },
      { UINT32_C(3562182378), UINT32_C(4182597676), UINT32_C( 491521237), UINT32_C(3850086359) },
      UINT8_C(  0) },
    { UINT8_C(180),
      { UINT32_C(3367916868), UINT32_C( 315753063), UINT32_C(1090298793), UINT32_C(1433194741) },
      { UINT32_C( 573203742), UINT32_C(1492731825), UINT32_C(1083694787), UINT32_C(1911860781) },
      UINT8_C(  0) },
    { UINT8_C(199),
      { UINT32_C(2942205196), UINT32_C(1235590777), UINT32_C(1869085194), UINT32_C(1814071845) },
      { UINT32_C(2942205196), UINT32_C(3180294159), UINT32_C( 398458980), UINT32_C(1187719994) },
      UINT8_C(  3) },
    { UINT8_C( 16),
      { UINT32_C(2513529755), UINT32_C(1555710162), UINT32_C(3638568800), UINT32_C(3337044566) },
      { UINT32_C(3509298385), UINT32_C(1555710162), UINT32_C( 926503437), UINT32_C(3337044566) },
      UINT8_C(  0) },
    { UINT8_C(194),
      { UINT32_C(1517417523), UINT32_C( 380717524), UINT32_C(3588716337), UINT32_C(3829053858) },
      { UINT32_C(1517417523), UINT32_C(1583360260), UINT32_C(4146348839), UINT32_C(4027104444) },
      UINT8_C(  2) },
    { UINT8_C( 52),
      { UINT32_C(1945345019), UINT32_C(1008060803), UINT32_C(3456236035), UINT32_C( 366090476) },
      { UINT32_C(3158061432), UINT32_C( 293090389), UINT32_C(3049351228), UINT32_C(2927052467) },
      UINT8_C(  0) },
    { UINT8_C(231),
      { UINT32_C( 825729335), UINT32_C(3122464418), UINT32_C( 154350296), UINT32_C(2724130670) },
      { UINT32_C(3504238439), UINT32_C(2005111601), UINT32_C(1985556747), UINT32_C(2326445651) },
      UINT8_C(  5) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__mmask8 k = test_vec[i].k;
    simde__m128i a = simde_x_mm_loadu_epi32(test_vec[i].a);
    simde__m128i b = simde_x_mm_loadu_epi32(test_vec[i].b);
    simde__mmask8 r = simde_mm_mask_cmple_epu32_mask(k, a, b);
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
    simde__mmask8 r = simde_mm_mask_cmple_epu32_mask(k, a, b);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_u32x4(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_u32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_x_mm256_cmple_epu32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const uint32_t a[8];
    const uint32_t b[8];
    const uint32_t r[8];
  } test_vec[] = {
    { { UINT32_C(3364611298), UINT32_C(  11589996), UINT32_C( 902258782), UINT32_C(4061870472), UINT32_C(2419707662), UINT32_C( 967729394), UINT32_C( 464236486), UINT32_C(1191689061) },
      { UINT32_C( 202412960), UINT32_C(3389833324), UINT32_C( 902258782), UINT32_C( 463149836), UINT32_C(3702248682), UINT32_C(4212480308), UINT32_C(1830207496), UINT32_C( 481631868) },
      { UINT32_C(         0),           UINT32_MAX,           UINT32_MAX, UINT32_C(         0),           UINT32_MAX,           UINT32_MAX,           UINT32_MAX, UINT32_C(         0) } },
    { { UINT32_C( 357558024), UINT32_C(3962628610), UINT32_C(4090026942), UINT32_C(1039064629), UINT32_C( 447415454), UINT32_C(3543556130), UINT32_C(2867879717), UINT32_C(2622544020) },
      { UINT32_C(3249643455), UINT32_C(3962628610), UINT32_C(4090026942), UINT32_C(4063177043), UINT32_C(1343019565), UINT32_C(1596146490), UINT32_C( 906630306), UINT32_C(2882689772) },
      {           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX, UINT32_C(         0), UINT32_C(         0),           UINT32_MAX } },
    { { UINT32_C(3792963214), UINT32_C(1574192175), UINT32_C(1504567326), UINT32_C(3317223459), UINT32_C(3506160356), UINT32_C( 393989661), UINT32_C(3080382290), UINT32_C(2413454848) },
      { UINT32_C(2624712300), UINT32_C(1375290674), UINT32_C(1235920421), UINT32_C(3317223459), UINT32_C(3506160356), UINT32_C( 710518744), UINT32_C(2413949838), UINT32_C(3323902809) },
      { UINT32_C(         0), UINT32_C(         0), UINT32_C(         0),           UINT32_MAX,           UINT32_MAX,           UINT32_MAX, UINT32_C(         0),           UINT32_MAX } },
    { { UINT32_C(2000869121), UINT32_C(1607618874), UINT32_C( 866254427), UINT32_C( 861797029), UINT32_C(1203912429), UINT32_C(2752372986), UINT32_C(1132490607), UINT32_C(3409817290) },
      { UINT32_C(3208806277), UINT32_C( 723391952), UINT32_C(3093217043), UINT32_C(2817244089), UINT32_C(4109283066), UINT32_C(4271438734), UINT32_C( 876681322), UINT32_C(1291812550) },
      {           UINT32_MAX, UINT32_C(         0),           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX, UINT32_C(         0), UINT32_C(         0) } },
    { { UINT32_C(2736871657), UINT32_C( 239734036), UINT32_C(1224882363), UINT32_C(2638715443), UINT32_C(2043775410), UINT32_C(  96849927), UINT32_C(1758777361), UINT32_C(3838955258) },
      { UINT32_C(2736871657), UINT32_C(3142111488), UINT32_C(1006914057), UINT32_C(2638715443), UINT32_C(2043775410), UINT32_C(2346898810), UINT32_C(2700326565), UINT32_C(2860828036) },
      {           UINT32_MAX,           UINT32_MAX, UINT32_C(         0),           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX, UINT32_C(         0) } },
    { { UINT32_C(1545697144), UINT32_C(2566126275), UINT32_C( 510985124), UINT32_C(2125027288), UINT32_C(2434702605), UINT32_C( 440115810), UINT32_C(2312249517), UINT32_C(3329115470) },
      { UINT32_C(2149748668), UINT32_C( 756553353), UINT32_C(4065037593), UINT32_C(2125027288), UINT32_C(4085419665), UINT32_C(3708665392), UINT32_C( 744939486), UINT32_C(3329115470) },
      {           UINT32_MAX, UINT32_C(         0),           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX, UINT32_C(         0),           UINT32_MAX } },
    { { UINT32_C(3946210311), UINT32_C(3940394584), UINT32_C(1692229428), UINT32_C(4232178461), UINT32_C(4012419018), UINT32_C(3738180475), UINT32_C(1539977520), UINT32_C(2980045738) },
      { UINT32_C(2694698567), UINT32_C(2978642556), UINT32_C(4145375193), UINT32_C( 502486866), UINT32_C(4012419018), UINT32_C(3738180475), UINT32_C(1539977520), UINT32_C(1315528966) },
      { UINT32_C(         0), UINT32_C(         0),           UINT32_MAX, UINT32_C(         0),           UINT32_MAX,           UINT32_MAX,           UINT32_MAX, UINT32_C(         0) } },
    { { UINT32_C( 844135135), UINT32_C(3478078417), UINT32_C(2504612703), UINT32_C(1157407287), UINT32_C(3422272965), UINT32_C(1427727390), UINT32_C(3926460266), UINT32_C(1598319999) },
      { UINT32_C(3096548583), UINT32_C(3478078417), UINT32_C(2504612703), UINT32_C( 951502963), UINT32_C(3422272965), UINT32_C(1427727390), UINT32_C(2758476581), UINT32_C(1476636528) },
      {           UINT32_MAX,           UINT32_MAX,           UINT32_MAX, UINT32_C(         0),           UINT32_MAX,           UINT32_MAX, UINT32_C(         0), UINT32_C(         0) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256i a = simde_mm256_loadu_epi32(test_vec[i].a);
    simde__m256i b = simde_mm256_loadu_epi32(test_vec[i].b);
    simde__m256i r = simde_x_mm256_cmple_epu32(a, b);
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
    simde__m256i r = simde_x_mm256_cmple_epu32(a, b);

    simde_test_x86_write_u32x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_u32x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_u32x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_cmple_epu32_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const uint32_t a[8];
    const uint32_t b[8];
    const simde__mmask8 r;
  } test_vec[] = {
    { { UINT32_C(3540564829), UINT32_C(1109039876), UINT32_C(1249538632), UINT32_C( 768615689), UINT32_C( 724822978), UINT32_C( 712725067), UINT32_C( 988732041), UINT32_C(1011182559) },
      { UINT32_C( 705646118), UINT32_C( 829172457), UINT32_C(2776360860), UINT32_C( 768615689), UINT32_C( 724822978), UINT32_C(3786175832), UINT32_C( 790403664), UINT32_C(1011182559) },
      UINT16_C(  188) },
    { { UINT32_C(3068544169), UINT32_C(3330652304), UINT32_C( 373850046), UINT32_C(1157166324), UINT32_C(2490569871), UINT32_C( 633396853), UINT32_C(4257027673), UINT32_C(2185136088) },
      { UINT32_C(1530406091), UINT32_C(2602745308), UINT32_C( 816933436), UINT32_C(1157166324), UINT32_C(2490569871), UINT32_C( 542655175), UINT32_C( 823989592), UINT32_C(2185136088) },
      UINT16_C(  156) },
    { { UINT32_C(2937366608), UINT32_C( 261982546), UINT32_C( 960634738), UINT32_C(3126434402), UINT32_C(1290499760), UINT32_C(1370791634), UINT32_C( 833452169), UINT32_C(2903876701) },
      { UINT32_C(2673617485), UINT32_C( 261982546), UINT32_C(2069819673), UINT32_C( 993376139), UINT32_C(   8921390), UINT32_C(1230060735), UINT32_C( 310050740), UINT32_C(4039086243) },
      UINT16_C(  134) },
    { { UINT32_C(3131699503), UINT32_C(3623280553), UINT32_C(3218570752), UINT32_C(1862805690), UINT32_C(3414262567), UINT32_C(3451600915), UINT32_C(1916423004), UINT32_C(3097546121) },
      { UINT32_C(1752320703), UINT32_C( 692021289), UINT32_C(2716341990), UINT32_C(1712386366), UINT32_C(2268172660), UINT32_C( 777317585), UINT32_C(1916423004), UINT32_C( 460865628) },
      UINT16_C(   64) },
    { { UINT32_C( 383501784), UINT32_C( 712829878), UINT32_C(1303489916), UINT32_C(3514500506), UINT32_C(4019329939), UINT32_C(3859417692), UINT32_C(1234865653), UINT32_C( 662926927) },
      { UINT32_C(4047396411), UINT32_C(3306928713), UINT32_C(  34786408), UINT32_C(3514500506), UINT32_C(4019329939), UINT32_C(1709989744), UINT32_C(1018070764), UINT32_C( 662926927) },
      UINT16_C(  155) },
    { { UINT32_C(3821449233), UINT32_C(3880294718), UINT32_C(1877843199), UINT32_C(3906263547), UINT32_C(1529119583), UINT32_C(1150519220), UINT32_C(2233253161), UINT32_C( 323598850) },
      { UINT32_C(3821449233), UINT32_C(3880294718), UINT32_C(3591797979), UINT32_C(3906263547), UINT32_C( 571531886), UINT32_C(2472977258), UINT32_C(2233253161), UINT32_C(2809553213) },
      UINT16_C(  239) },
    { { UINT32_C(2958874203), UINT32_C( 795155393), UINT32_C(1733457405), UINT32_C(2046474264), UINT32_C(2027622971), UINT32_C(3810480499), UINT32_C(1778151102), UINT32_C(2834283597) },
      { UINT32_C(1415072658), UINT32_C(1686355302), UINT32_C(1271649586), UINT32_C(3385116302), UINT32_C(1279434712), UINT32_C(2939118065), UINT32_C( 488123344), UINT32_C(2059732967) },
      UINT16_C(   10) },
    { { UINT32_C(3042502695), UINT32_C(2273189038), UINT32_C(2916335804), UINT32_C(4066116130), UINT32_C( 353334318), UINT32_C(3448755323), UINT32_C(3431357937), UINT32_C(3604652975) },
      { UINT32_C( 982200972), UINT32_C( 197200207), UINT32_C(3971519690), UINT32_C(3319665815), UINT32_C(  64679304), UINT32_C(3000003265), UINT32_C(1988057031), UINT32_C(2253150714) },
      UINT16_C(    4) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256i a = simde_mm256_loadu_epi32(test_vec[i].a);
    simde__m256i b = simde_mm256_loadu_epi32(test_vec[i].b);
    simde__mmask8 r = simde_mm256_cmple_epu32_mask(a, b);
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
    simde__mmask8 r = simde_mm256_cmple_epu32_mask(a, b);

    simde_test_x86_write_u32x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_u32x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_mask_cmple_epu32_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k;
    const uint32_t a[8];
    const uint32_t b[8];
    const simde__mmask8 r;
  } test_vec[] = {
    { UINT8_C(248),
      { UINT32_C(3701063624), UINT32_C( 215041808), UINT32_C( 858645074), UINT32_C(2189078536), UINT32_C(1548054098), UINT32_C(3411401571), UINT32_C(2698953835), UINT32_C(2914247908) },
      { UINT32_C(3028896931), UINT32_C(3854588563), UINT32_C(1142549820), UINT32_C(4039545758), UINT32_C(1699482369), UINT32_C(1378918887), UINT32_C(1240600165), UINT32_C(2532746995) },
      UINT8_C( 24) },
    { UINT8_C(227),
      { UINT32_C( 412506500), UINT32_C( 723093023), UINT32_C(1930591954), UINT32_C(3185075374), UINT32_C(4256178775), UINT32_C(2565817880), UINT32_C(2624681361), UINT32_C(1704232929) },
      { UINT32_C( 412506500), UINT32_C(2217449393), UINT32_C(3304537365), UINT32_C(4169257121), UINT32_C( 183841266), UINT32_C( 144893303), UINT32_C(1000608858), UINT32_C(2074163611) },
      UINT8_C(131) },
    { UINT8_C(202),
      { UINT32_C(1636142993), UINT32_C(1095990544), UINT32_C(1488477555), UINT32_C( 347259136), UINT32_C(2662329957), UINT32_C(2902600335), UINT32_C(1281562790), UINT32_C(1110453937) },
      { UINT32_C(3450058173), UINT32_C(2769221170), UINT32_C(1425917524), UINT32_C(3983061127), UINT32_C(2662329957), UINT32_C(3889860161), UINT32_C(1463041446), UINT32_C(1110453937) },
      UINT8_C(202) },
    { UINT8_C(119),
      { UINT32_C(2656165102), UINT32_C(1530674756), UINT32_C(1486645706), UINT32_C(2180940868), UINT32_C( 485316024), UINT32_C( 758453743), UINT32_C( 241270795), UINT32_C(1624828273) },
      { UINT32_C(2656165102), UINT32_C( 845429608), UINT32_C(3901358244), UINT32_C(1013614724), UINT32_C(3445118942), UINT32_C(2012908908), UINT32_C(2139511566), UINT32_C( 165633604) },
      UINT8_C(117) },
    { UINT8_C( 92),
      { UINT32_C( 922461870), UINT32_C(1729378320), UINT32_C( 517202576), UINT32_C( 942427100), UINT32_C( 796699601), UINT32_C(1773700747), UINT32_C( 260221336), UINT32_C(2055618508) },
      { UINT32_C(4122051045), UINT32_C(1729378320), UINT32_C( 517202576), UINT32_C(1287427195), UINT32_C(3397072959), UINT32_C(1773700747), UINT32_C(2842080732), UINT32_C(3659787509) },
      UINT8_C( 92) },
    { UINT8_C( 18),
      { UINT32_C(1842857433), UINT32_C(3131843457), UINT32_C(3531110303), UINT32_C(1622134698), UINT32_C( 559241269), UINT32_C(1351561083), UINT32_C( 753579775), UINT32_C(   8923943) },
      { UINT32_C(1919770865), UINT32_C(3131843457), UINT32_C(3531110303), UINT32_C(2862326900), UINT32_C(2009854204), UINT32_C( 533158431), UINT32_C( 927707408), UINT32_C(3459765213) },
      UINT8_C( 18) },
    { UINT8_C(245),
      { UINT32_C(1921419726), UINT32_C( 342765604), UINT32_C(1446307580), UINT32_C(1600607149), UINT32_C(1899798174), UINT32_C(2057636566), UINT32_C(3073924170), UINT32_C(  80316213) },
      { UINT32_C( 896946192), UINT32_C(2085217664), UINT32_C(2027126219), UINT32_C(1859599056), UINT32_C(2933920728), UINT32_C(1747551517), UINT32_C( 371155425), UINT32_C(4179290600) },
      UINT8_C(148) },
    { UINT8_C(125),
      { UINT32_C(1137031433), UINT32_C(2753246353), UINT32_C(2579679764), UINT32_C(1417292531), UINT32_C( 842895433), UINT32_C(1013659307), UINT32_C(3685885284), UINT32_C(1691415387) },
      { UINT32_C(1034393260), UINT32_C(2753246353), UINT32_C(2138547340), UINT32_C( 399831502), UINT32_C( 743051649), UINT32_C(2875766087), UINT32_C( 897981146), UINT32_C(3130611469) },
      UINT8_C( 32) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__mmask8 k = test_vec[i].k;
    simde__m256i a = simde_mm256_loadu_epi32(test_vec[i].a);
    simde__m256i b = simde_mm256_loadu_epi32(test_vec[i].b);
    simde__mmask8 r = simde_mm256_mask_cmple_epu32_mask(k, a, b);
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
    simde__mmask8 r = simde_mm256_mask_cmple_epu32_mask(k, a, b);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_u32x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_u32x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_x_mm512_cmple_epu32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const uint32_t a[16];
    const uint32_t b[16];
    const uint32_t r[16];
  } test_vec[] = {
    { { UINT32_C( 933016233), UINT32_C(1360642415), UINT32_C(3606228196), UINT32_C(2556374863), UINT32_C(2505372749), UINT32_C(3269366274), UINT32_C(2746455433), UINT32_C(3869727804),
        UINT32_C(2115846927), UINT32_C(3922671109), UINT32_C( 851428067), UINT32_C(1053433841), UINT32_C( 366223123), UINT32_C( 987280049), UINT32_C(2229111624), UINT32_C(4150953192) },
      { UINT32_C( 933016233), UINT32_C(2713076926), UINT32_C(4174607622), UINT32_C(2822151828), UINT32_C(1857882813), UINT32_C(3269366274), UINT32_C( 160007457), UINT32_C(3869727804),
        UINT32_C( 966686075), UINT32_C(3235534009), UINT32_C(1589161674), UINT32_C( 151449164), UINT32_C( 366223123), UINT32_C(2059083609), UINT32_C(2911061156), UINT32_C(3028255544) },
      {           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX, UINT32_C(         0),           UINT32_MAX, UINT32_C(         0),           UINT32_MAX,
        UINT32_C(         0), UINT32_C(         0),           UINT32_MAX, UINT32_C(         0),           UINT32_MAX,           UINT32_MAX,           UINT32_MAX, UINT32_C(         0) } },
    { { UINT32_C(3200729701), UINT32_C(  87655009), UINT32_C(4289903815), UINT32_C( 951267648), UINT32_C(3253379407), UINT32_C(3757923433), UINT32_C(2678167430), UINT32_C(2645584952),
        UINT32_C( 257718446), UINT32_C(3239351802), UINT32_C(2445395537), UINT32_C(1204450552), UINT32_C(2114499605), UINT32_C(2539455761), UINT32_C(3577151132), UINT32_C( 410183530) },
      { UINT32_C(1495780959), UINT32_C(3038460771), UINT32_C(4198947842), UINT32_C( 951267648), UINT32_C(3605285317), UINT32_C(3757923433), UINT32_C(2678167430), UINT32_C(3938661003),
        UINT32_C(1682172672), UINT32_C( 672751142), UINT32_C(2334285626), UINT32_C( 905012080), UINT32_C(4195079596), UINT32_C(1491433495), UINT32_C(3577151132), UINT32_C(3616655062) },
      { UINT32_C(         0),           UINT32_MAX, UINT32_C(         0),           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,
                  UINT32_MAX, UINT32_C(         0), UINT32_C(         0), UINT32_C(         0),           UINT32_MAX, UINT32_C(         0),           UINT32_MAX,           UINT32_MAX } },
    { { UINT32_C(3610076095), UINT32_C(4163834588), UINT32_C(2376086199), UINT32_C(2858693112), UINT32_C( 981638918), UINT32_C(2812838643), UINT32_C( 751477157), UINT32_C(1247749003),
        UINT32_C(1646365830), UINT32_C(1448824991), UINT32_C(2078538626), UINT32_C( 858081324), UINT32_C(3681396711), UINT32_C(3481408809), UINT32_C(1106988214), UINT32_C(4136327791) },
      { UINT32_C(3610076095), UINT32_C(2161882109), UINT32_C(2376086199), UINT32_C(3993903111), UINT32_C(4039736263), UINT32_C(1186941840), UINT32_C( 126335640), UINT32_C(1247749003),
        UINT32_C(3179304639), UINT32_C(3091029001), UINT32_C( 580073499), UINT32_C( 521183576), UINT32_C(2886720028), UINT32_C(3186806565), UINT32_C(1106988214), UINT32_C(1268368011) },
      {           UINT32_MAX, UINT32_C(         0),           UINT32_MAX,           UINT32_MAX,           UINT32_MAX, UINT32_C(         0), UINT32_C(         0),           UINT32_MAX,
                  UINT32_MAX,           UINT32_MAX, UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0),           UINT32_MAX, UINT32_C(         0) } },
    { { UINT32_C(3268805533), UINT32_C(1551943890), UINT32_C(3438953793), UINT32_C( 538415879), UINT32_C( 574758828), UINT32_C(3786546276), UINT32_C(2545313161), UINT32_C(3317803560),
        UINT32_C(2156369838), UINT32_C(2698774367), UINT32_C(1416418892), UINT32_C( 376734825), UINT32_C( 137934499), UINT32_C(1542056658), UINT32_C(2012389455), UINT32_C(4164727626) },
      { UINT32_C(2843329610), UINT32_C(1551943890), UINT32_C(2506929452), UINT32_C(3719028793), UINT32_C( 574758828), UINT32_C( 499371726), UINT32_C(3113596270), UINT32_C(2997997928),
        UINT32_C(1633364629), UINT32_C(2698774367), UINT32_C(1416418892), UINT32_C( 376734825), UINT32_C(2663601616), UINT32_C(1542056658), UINT32_C(2739622203), UINT32_C(3092642850) },
      { UINT32_C(         0),           UINT32_MAX, UINT32_C(         0),           UINT32_MAX,           UINT32_MAX, UINT32_C(         0),           UINT32_MAX, UINT32_C(         0),
        UINT32_C(         0),           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX, UINT32_C(         0) } },
    { { UINT32_C( 703617541), UINT32_C( 465284320), UINT32_C( 549324541), UINT32_C( 702026498), UINT32_C( 399569347), UINT32_C(4207158147), UINT32_C( 959841720), UINT32_C(3146501557),
        UINT32_C( 132414503), UINT32_C( 639803176), UINT32_C(2806440101), UINT32_C(3067158259), UINT32_C(2462949647), UINT32_C(2106364357), UINT32_C(1287045782), UINT32_C(3053929103) },
      { UINT32_C(3871206334), UINT32_C( 789372810), UINT32_C(3000390335), UINT32_C(2137565040), UINT32_C( 236008777), UINT32_C(1569430982), UINT32_C(4004069727), UINT32_C(1101312131),
        UINT32_C( 623403419), UINT32_C(4283708480), UINT32_C(4155583111), UINT32_C( 460790226), UINT32_C( 355043406), UINT32_C(2106364357), UINT32_C(2037652469), UINT32_C(1723472075) },
      {           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX, UINT32_C(         0), UINT32_C(         0),           UINT32_MAX, UINT32_C(         0),
                  UINT32_MAX,           UINT32_MAX,           UINT32_MAX, UINT32_C(         0), UINT32_C(         0),           UINT32_MAX,           UINT32_MAX, UINT32_C(         0) } },
    { { UINT32_C(3152551829), UINT32_C(3376437971), UINT32_C(1078113397), UINT32_C(1202126029), UINT32_C(4127273439), UINT32_C( 445954832), UINT32_C(2901748007), UINT32_C(3414158390),
        UINT32_C(3750127627), UINT32_C( 950585026), UINT32_C(1215883899), UINT32_C(3314491366), UINT32_C(1639682128), UINT32_C(1937461068), UINT32_C(2938073209), UINT32_C(1752866396) },
      { UINT32_C(3376873478), UINT32_C(1090645958), UINT32_C(3213457881), UINT32_C(3917813912), UINT32_C(4115284137), UINT32_C( 157861264), UINT32_C(2461566773), UINT32_C( 754594341),
        UINT32_C(4176822578), UINT32_C( 950585026), UINT32_C( 147374959), UINT32_C(2247183836), UINT32_C( 511327118), UINT32_C( 891806208), UINT32_C(2395463529), UINT32_C(1136312593) },
      {           UINT32_MAX, UINT32_C(         0),           UINT32_MAX,           UINT32_MAX, UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0),
                  UINT32_MAX,           UINT32_MAX, UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0) } },
    { { UINT32_C(1241322569), UINT32_C(1602102518), UINT32_C( 351094275), UINT32_C( 173516807), UINT32_C(4248605527), UINT32_C(1091729416), UINT32_C(3444977532), UINT32_C(2259546173),
        UINT32_C(4207913476), UINT32_C(3529067983), UINT32_C(2615625619), UINT32_C(1185234671), UINT32_C(3661881809), UINT32_C(3575338329), UINT32_C(3248714372), UINT32_C(1732726882) },
      { UINT32_C(3378583290), UINT32_C(1602102518), UINT32_C(4052910850), UINT32_C(2469869505), UINT32_C(1919777561), UINT32_C(1430816976), UINT32_C(3444977532), UINT32_C( 902061627),
        UINT32_C(3640599924), UINT32_C(3805322208), UINT32_C(2615625619), UINT32_C(3010595738), UINT32_C(1445322630), UINT32_C(1655401832), UINT32_C(3248714372), UINT32_C(1732726882) },
      {           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX, UINT32_C(         0),           UINT32_MAX,           UINT32_MAX, UINT32_C(         0),
        UINT32_C(         0),           UINT32_MAX,           UINT32_MAX,           UINT32_MAX, UINT32_C(         0), UINT32_C(         0),           UINT32_MAX,           UINT32_MAX } },
    { { UINT32_C( 438768306), UINT32_C(3632124543), UINT32_C(3026926740), UINT32_C(1766405312), UINT32_C(1609742076), UINT32_C(2464177907), UINT32_C(3905700254), UINT32_C(3334060052),
        UINT32_C(1256317130), UINT32_C(1193434802), UINT32_C(1526435226), UINT32_C(3200468162), UINT32_C(3978213114), UINT32_C(2994798100), UINT32_C(1402686527), UINT32_C(3474609156) },
      { UINT32_C(3860462388), UINT32_C(3632124543), UINT32_C(2320378312), UINT32_C(1749619053), UINT32_C(3696584647), UINT32_C(2777601381), UINT32_C(3905700254), UINT32_C(3334060052),
        UINT32_C(1721241101), UINT32_C(1193434802), UINT32_C(1526435226), UINT32_C(2177164729), UINT32_C(2975668556), UINT32_C(2994798100), UINT32_C(2453032725), UINT32_C(1866738529) },
      {           UINT32_MAX,           UINT32_MAX, UINT32_C(         0), UINT32_C(         0),           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,
                  UINT32_MAX,           UINT32_MAX,           UINT32_MAX, UINT32_C(         0), UINT32_C(         0),           UINT32_MAX,           UINT32_MAX, UINT32_C(         0) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i a = simde_mm512_loadu_epi32(test_vec[i].a);
    simde__m512i b = simde_mm512_loadu_epi32(test_vec[i].b);
    simde__m512i r = simde_x_mm512_cmple_epu32(a, b);
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
    simde__m512i r = simde_x_mm512_cmple_epu32(a, b);

    simde_test_x86_write_u32x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_u32x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_u32x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_cmple_epu32_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const uint32_t a[16];
    const uint32_t b[16];
    const simde__mmask16 r;
  } test_vec[] = {
    { { UINT32_C( 575431328), UINT32_C(2962085046), UINT32_C(2508724265), UINT32_C( 860292622), UINT32_C( 727529022), UINT32_C(3157991410), UINT32_C(2167759479), UINT32_C( 675949448),
        UINT32_C(1129027469), UINT32_C(2515851371), UINT32_C(4280974576), UINT32_C(3241308803), UINT32_C(2599260328), UINT32_C( 643180719), UINT32_C( 329747339), UINT32_C(1144844982) },
      { UINT32_C( 575431328), UINT32_C(1351187295), UINT32_C(2068821240), UINT32_C(3460071718), UINT32_C(3228051729), UINT32_C(3722952274), UINT32_C(4293955145), UINT32_C( 155397248),
        UINT32_C( 335465395), UINT32_C(1046710086), UINT32_C(1639559739), UINT32_C(1160771123), UINT32_C(1896191775), UINT32_C(2655972437), UINT32_C(4221452155), UINT32_C(1144844982) },
      UINT16_C(57465) },
    { { UINT32_C(1148372462), UINT32_C( 753057969), UINT32_C(1797816575), UINT32_C( 243936610), UINT32_C(3120675888), UINT32_C(2558538577), UINT32_C(4279412766), UINT32_C(3992965887),
        UINT32_C(1211199895), UINT32_C( 829756466), UINT32_C(4137459092), UINT32_C(4194641610), UINT32_C( 867436258), UINT32_C(1472935225), UINT32_C(3696680669), UINT32_C(1204377264) },
      { UINT32_C(1148372462), UINT32_C(2737505295), UINT32_C(1805305761), UINT32_C( 243936610), UINT32_C(3120675888), UINT32_C(2558538577), UINT32_C(1560841645), UINT32_C(2862928355),
        UINT32_C(3684971724), UINT32_C( 829756466), UINT32_C(2219121046), UINT32_C(1565895608), UINT32_C( 339499461), UINT32_C(1472935225), UINT32_C(3811788800), UINT32_C(1204377264) },
      UINT16_C(58175) },
    { { UINT32_C(4075334601), UINT32_C( 516433950), UINT32_C(2298608496), UINT32_C(3748630483), UINT32_C(3240374720), UINT32_C(3411559025), UINT32_C(3051123622), UINT32_C(2911456228),
        UINT32_C( 362770935), UINT32_C( 154429337), UINT32_C( 915617123), UINT32_C(2232812228), UINT32_C(2772843059), UINT32_C( 594583164), UINT32_C(4124593169), UINT32_C(2409849496) },
      { UINT32_C(1839481555), UINT32_C( 225892522), UINT32_C(3527608590), UINT32_C(1062689036), UINT32_C( 283418003), UINT32_C(3411559025), UINT32_C( 960629665), UINT32_C(1103684973),
        UINT32_C(3534646312), UINT32_C(1407132741), UINT32_C( 975512110), UINT32_C( 259620220), UINT32_C(1444896282), UINT32_C( 594583164), UINT32_C(3415008606), UINT32_C(4077671627) },
      UINT16_C(42788) },
    { { UINT32_C(3513544990), UINT32_C( 572788676), UINT32_C(3220025844), UINT32_C(3333618181), UINT32_C(2479650740), UINT32_C(3802146075), UINT32_C(2669995940), UINT32_C(3333781160),
        UINT32_C(2895585768), UINT32_C( 634305584), UINT32_C(1927592813), UINT32_C(1782159285), UINT32_C( 721224974), UINT32_C(3473710635), UINT32_C( 762196101), UINT32_C(2415142055) },
      { UINT32_C(1983613765), UINT32_C(3030059335), UINT32_C(2049408964), UINT32_C( 635723798), UINT32_C(2479650740), UINT32_C(3802146075), UINT32_C( 842190475), UINT32_C(3333781160),
        UINT32_C(4188929202), UINT32_C(3400419333), UINT32_C(3729053128), UINT32_C(2583898165), UINT32_C(2301317641), UINT32_C( 965642925), UINT32_C(1248575576), UINT32_C(2575445479) },
      UINT16_C(57266) },
    { { UINT32_C( 586616948), UINT32_C(4082861466), UINT32_C( 759023174), UINT32_C( 499564531), UINT32_C(1733056751), UINT32_C(2930197913), UINT32_C(3891905922), UINT32_C(1549131495),
        UINT32_C(2289978862), UINT32_C( 410769874), UINT32_C(2470820255), UINT32_C(1739590520), UINT32_C(4258200676), UINT32_C(3282793793), UINT32_C( 581608507), UINT32_C(1887371138) },
      { UINT32_C( 586616948), UINT32_C(4082861466), UINT32_C(2785574189), UINT32_C(3960322184), UINT32_C(1733056751), UINT32_C(2360907089), UINT32_C(3165610553), UINT32_C(2922130785),
        UINT32_C(2289978862), UINT32_C(3346269338), UINT32_C(2470820255), UINT32_C(1739590520), UINT32_C(2833113175), UINT32_C(2922747253), UINT32_C(1500177655), UINT32_C( 990353169) },
      UINT16_C(20383) },
    { { UINT32_C(2936415802), UINT32_C(3009297340), UINT32_C( 806144031), UINT32_C( 476844895), UINT32_C(3228739559), UINT32_C(2182778966), UINT32_C( 585334300), UINT32_C( 327167192),
        UINT32_C( 247629394), UINT32_C(3770818753), UINT32_C(1209061097), UINT32_C(3378805986), UINT32_C(2055853859), UINT32_C(2214372199), UINT32_C(4205240097), UINT32_C(1577920011) },
      { UINT32_C(1835847596), UINT32_C(3645714160), UINT32_C(3743505917), UINT32_C(4255680218), UINT32_C(3228739559), UINT32_C(4148720853), UINT32_C( 585334300), UINT32_C( 327167192),
        UINT32_C(3173853645), UINT32_C(3770818753), UINT32_C(2973022423), UINT32_C(2611993662), UINT32_C(3831440910), UINT32_C(2214372199), UINT32_C(4205240097), UINT32_C(2540243658) },
      UINT16_C(63486) },
    { { UINT32_C( 165928047), UINT32_C( 435666563), UINT32_C(1422017674), UINT32_C(2196515918), UINT32_C(3540861378), UINT32_C(3501977132), UINT32_C(4088484866), UINT32_C( 217263773),
        UINT32_C(2367018506), UINT32_C( 530976149), UINT32_C(2691983697), UINT32_C(1461870741), UINT32_C(3442093985), UINT32_C( 547218717), UINT32_C(3608366906), UINT32_C(2279802493) },
      { UINT32_C(1913977053), UINT32_C(1469168389), UINT32_C(3119973668), UINT32_C( 101718373), UINT32_C(3540861378), UINT32_C(1518760224), UINT32_C(1026660800), UINT32_C(2110002336),
        UINT32_C( 317708557), UINT32_C( 530976149), UINT32_C(3950076038), UINT32_C(1461870741), UINT32_C(3710437052), UINT32_C(4164398647), UINT32_C(3879037255), UINT32_C(2321873533) },
      UINT16_C(65175) },
    { { UINT32_C( 900451069), UINT32_C(3224232568), UINT32_C(3383190091), UINT32_C( 793971804), UINT32_C( 865529951), UINT32_C(1586345463), UINT32_C(1463735109), UINT32_C( 136700170),
        UINT32_C( 608030891), UINT32_C(4276382386), UINT32_C( 700943308), UINT32_C(4149746327), UINT32_C(  36368139), UINT32_C(3932207268), UINT32_C(2504105611), UINT32_C( 731735679) },
      { UINT32_C( 900451069), UINT32_C(3224232568), UINT32_C(1446686142), UINT32_C( 793971804), UINT32_C( 865529951), UINT32_C(3121624367), UINT32_C(1397772755), UINT32_C(3984518583),
        UINT32_C( 215338440), UINT32_C(3189619712), UINT32_C( 823416681), UINT32_C(4149746327), UINT32_C(  36368139), UINT32_C(3804471566), UINT32_C(2838828018), UINT32_C(3365319424) },
      UINT16_C(56507) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i a = simde_mm512_loadu_epi32(test_vec[i].a);
    simde__m512i b = simde_mm512_loadu_epi32(test_vec[i].b);
    simde__mmask16 r = simde_mm512_cmple_epu32_mask(a, b);
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
    simde__mmask16 r = simde_mm512_cmple_epu32_mask(a, b);

    simde_test_x86_write_u32x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_u32x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_mask_cmple_epu32_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask16 k;
    const uint32_t a[16];
    const uint32_t b[16];
    const simde__mmask16 r;
  } test_vec[] = {
    { UINT16_C(45910),
      { UINT32_C(2908886535), UINT32_C(2101724715), UINT32_C(2535498832), UINT32_C(3928398417), UINT32_C(1291413525), UINT32_C( 926186445), UINT32_C(3328377662), UINT32_C(  99714046),
        UINT32_C(3316798362), UINT32_C(1782773530), UINT32_C(3959513755), UINT32_C( 316024828), UINT32_C(1566494863), UINT32_C(2308215627), UINT32_C(2488268694), UINT32_C( 362365051) },
      { UINT32_C(2933541780), UINT32_C(3726122307), UINT32_C(2093685119), UINT32_C(3499008320), UINT32_C(1291413525), UINT32_C( 356893055), UINT32_C( 866751672), UINT32_C(  99714046),
        UINT32_C(3316798362), UINT32_C(3215929152), UINT32_C(3959513755), UINT32_C( 316024828), UINT32_C( 894076342), UINT32_C(4283141958), UINT32_C(4180866084), UINT32_C( 362365051) },
      UINT64_C(               41746) },
    { UINT16_C(  408),
      { UINT32_C(3645087118), UINT32_C(3469567900), UINT32_C(3259565152), UINT32_C(1597761481), UINT32_C(1671816133), UINT32_C(1262249427), UINT32_C(2854018625), UINT32_C(3311301431),
        UINT32_C(2896077072), UINT32_C(1752853256), UINT32_C( 959104112), UINT32_C(1905878443), UINT32_C( 466894408), UINT32_C(3831894179), UINT32_C( 630096878), UINT32_C( 116059382) },
      { UINT32_C(2511505549), UINT32_C(1694313716), UINT32_C(2627545072), UINT32_C(1597761481), UINT32_C(1671816133), UINT32_C(3757790961), UINT32_C(2854018625), UINT32_C(  81129334),
        UINT32_C(2896077072), UINT32_C(1752853256), UINT32_C(1262513598), UINT32_C(1905878443), UINT32_C( 523243310), UINT32_C(1056844645), UINT32_C( 739050421), UINT32_C(1798365939) },
      UINT64_C(                 280) },
    { UINT16_C(31866),
      { UINT32_C(2569862554), UINT32_C(1218241083), UINT32_C(1042976526), UINT32_C(3506934778), UINT32_C(1886939312), UINT32_C(4050750855), UINT32_C( 377142853), UINT32_C(3558282042),
        UINT32_C(1282229264), UINT32_C( 882117158), UINT32_C(2490548121), UINT32_C(  40204626), UINT32_C(1752424161), UINT32_C(2958681195), UINT32_C(3704083618), UINT32_C(4155629287) },
      { UINT32_C(1212358178), UINT32_C(3262961704), UINT32_C(3914788503), UINT32_C(1240251240), UINT32_C(  78798745), UINT32_C(3853847363), UINT32_C(3334634719), UINT32_C(3558282042),
        UINT32_C(1282229264), UINT32_C(1887191769), UINT32_C(2490548121), UINT32_C( 669140621), UINT32_C(3895170213), UINT32_C(2144198815), UINT32_C(3704083618), UINT32_C(4155629287) },
      UINT64_C(               23618) },
    { UINT16_C(41698),
      { UINT32_C(1230772860), UINT32_C(3738810777), UINT32_C(2766330736), UINT32_C(3181242223), UINT32_C( 344447429), UINT32_C(1237132101), UINT32_C(2637212749), UINT32_C(3155798592),
        UINT32_C(1560704708), UINT32_C(2671566639), UINT32_C( 709041850), UINT32_C(3404193797), UINT32_C(4276055993), UINT32_C(3746077842), UINT32_C(2306701385), UINT32_C(3880162850) },
      { UINT32_C( 994331660), UINT32_C(3856302123), UINT32_C(2735676830), UINT32_C(3077502974), UINT32_C(4172696934), UINT32_C( 853081833), UINT32_C(2562479478), UINT32_C(4169073387),
        UINT32_C(2033435726), UINT32_C(3814592068), UINT32_C( 696675883), UINT32_C(3404193797), UINT32_C( 734238529), UINT32_C( 190684053), UINT32_C(3701676528), UINT32_C(1775510299) },
      UINT64_C(                 642) },
    { UINT16_C(44109),
      { UINT32_C(1396602870), UINT32_C( 644689538), UINT32_C(3729360906), UINT32_C(3571855602), UINT32_C(1779825499), UINT32_C(2818556988), UINT32_C(3086125272), UINT32_C(1230689619),
        UINT32_C(3483211852), UINT32_C(3522497222), UINT32_C(2226077330), UINT32_C(3378091374), UINT32_C(3442699921), UINT32_C( 192164403), UINT32_C( 247687099), UINT32_C(2287476028) },
      { UINT32_C(1396602870), UINT32_C(2437696767), UINT32_C(3729360906), UINT32_C(3571855602), UINT32_C( 284227037), UINT32_C(3810288680), UINT32_C( 133291979), UINT32_C(1230689619),
        UINT32_C(3483211852), UINT32_C(3201268020), UINT32_C( 112715125), UINT32_C(3378091374), UINT32_C(2520914286), UINT32_C( 192164403), UINT32_C( 961571645), UINT32_C(4092256436) },
      UINT64_C(               43021) },
    { UINT16_C(50846),
      { UINT32_C(1762314991), UINT32_C(1691633427), UINT32_C(1782876288), UINT32_C(2894072955), UINT32_C(3282767880), UINT32_C( 523538452), UINT32_C( 844308424), UINT32_C(1742643320),
        UINT32_C(2127620203), UINT32_C(2950865967), UINT32_C(2820220717), UINT32_C(1012177459), UINT32_C(3204382890), UINT32_C(1490957200), UINT32_C(3398119762), UINT32_C(1026714066) },
      { UINT32_C(2176516690), UINT32_C(1691633427), UINT32_C(4168895173), UINT32_C(2385826276), UINT32_C(1632449489), UINT32_C( 523538452), UINT32_C( 844308424), UINT32_C(1742643320),
        UINT32_C(2127620203), UINT32_C(2318643909), UINT32_C(3783438589), UINT32_C(1383118721), UINT32_C(1370734058), UINT32_C(1141599464), UINT32_C(1601408945), UINT32_C(1026714066) },
      UINT64_C(               33926) },
    { UINT16_C(29348),
      { UINT32_C(3576923850), UINT32_C(1046799563), UINT32_C(2719787331), UINT32_C(  58860198), UINT32_C(1100223980), UINT32_C( 387503269), UINT32_C(2851645078), UINT32_C(3899692830),
        UINT32_C(3904742173), UINT32_C(3391496583), UINT32_C(1902920650), UINT32_C(1366617701), UINT32_C(2844919812), UINT32_C(1942006493), UINT32_C(1864153424), UINT32_C(1834454096) },
      { UINT32_C(3059094831), UINT32_C(  25197622), UINT32_C(2719787331), UINT32_C(3749111515), UINT32_C(1100223980), UINT32_C(  54479283), UINT32_C(1383226114), UINT32_C( 398445288),
        UINT32_C( 365827551), UINT32_C(1360416402), UINT32_C( 376866875), UINT32_C(1593175151), UINT32_C(2804579828), UINT32_C(3366676934), UINT32_C(1864153424), UINT32_C(3334789863) },
      UINT64_C(               24580) },
    { UINT16_C(18613),
      { UINT32_C(2094754513), UINT32_C(1301913395), UINT32_C( 271024460), UINT32_C( 597825351), UINT32_C(1796637336), UINT32_C(3484717470), UINT32_C(3287738747), UINT32_C(3828718099),
        UINT32_C( 929042436), UINT32_C(4219861423), UINT32_C(3255544954), UINT32_C(1558556099), UINT32_C(3469212464), UINT32_C( 127761548), UINT32_C(2026541925), UINT32_C( 844955437) },
      { UINT32_C(2094754513), UINT32_C( 817557174), UINT32_C(1592968859), UINT32_C(2746931315), UINT32_C(1796637336), UINT32_C(1667698686), UINT32_C(3504091810), UINT32_C(3828718099),
        UINT32_C(2868931573), UINT32_C(4124818010), UINT32_C(3255544954), UINT32_C(2039942822), UINT32_C(3469212464), UINT32_C( 127761548), UINT32_C(2760559987), UINT32_C( 844955437) },
      UINT64_C(               18581) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__mmask16 k = test_vec[i].k;
    simde__m512i a = simde_mm512_loadu_epi32(test_vec[i].a);
    simde__m512i b = simde_mm512_loadu_epi32(test_vec[i].b);
    simde__mmask16 r = simde_mm512_mask_cmple_epu32_mask(k, a, b);
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
    simde__mmask16 r = simde_mm512_mask_cmple_epu32_mask(k, a, b);

    simde_test_x86_write_mmask16(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_u32x16(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_u32x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask64(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_x_mm_cmple_epi64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int64_t a[2];
    const int64_t b[2];
    const int64_t r[2];
  } test_vec[] = {
    { {  INT64_C( 8055085246885031881),  INT64_C( 7244117151542607800) },
      {  INT64_C( 7301315269705031202), -INT64_C( 5106790676633862229) },
      {  INT64_C(                   0),  INT64_C(                   0) } },
    { {  INT64_C( 4844276988323352945), -INT64_C( 5740774741077564050) },
      {  INT64_C( 4396030314978992750),  INT64_C( 2011909099956334998) },
      {  INT64_C(                   0), -INT64_C(                   1) } },
    { { -INT64_C( 7280831783269249450), -INT64_C( 7316180678301336000) },
      { -INT64_C( 7280831783269249450), -INT64_C( 8921198553314094401) },
      { -INT64_C(                   1),  INT64_C(                   0) } },
    { {  INT64_C( 5316385028238174484),  INT64_C( 4783513098474305069) },
      {  INT64_C( 5316385028238174484),  INT64_C( 3238503854381372594) },
      { -INT64_C(                   1),  INT64_C(                   0) } },
    { {  INT64_C( 3401077751453706293), -INT64_C( 8110546121784163150) },
      {  INT64_C( 3401077751453706293),  INT64_C( 6082436885891052334) },
      { -INT64_C(                   1), -INT64_C(                   1) } },
    { {  INT64_C( 1407104886932783440), -INT64_C(  748299724232012514) },
      {  INT64_C( 5879007368431224008),  INT64_C( 6503630012799366542) },
      { -INT64_C(                   1), -INT64_C(                   1) } },
    { { -INT64_C( 1210692807352435747), -INT64_C( 4309600125334810800) },
      {  INT64_C(  659989072050274012), -INT64_C( 4309600125334810800) },
      { -INT64_C(                   1), -INT64_C(                   1) } },
    { {  INT64_C( 5156698363092396238),  INT64_C(  838054193926247730) },
      { -INT64_C( 3590914558785801776),  INT64_C(  838054193926247730) },
      {  INT64_C(                   0), -INT64_C(                   1) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_x_mm_loadu_epi64(test_vec[i].a);
    simde__m128i b = simde_x_mm_loadu_epi64(test_vec[i].b);
    simde__m128i r = simde_x_mm_cmple_epi64(a, b);
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
    simde__m128i r = simde_x_mm_cmple_epi64(a, b);

    simde_test_x86_write_i64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_cmple_epi64_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int64_t a[2];
    const int64_t b[2];
    const simde__mmask8 r;
  } test_vec[] = {
    { {  INT64_C( 4478793845656381527), -INT64_C( 2999663542803349349) },
      { -INT64_C(  720981654573440946),  INT64_C( 8131475734791255667) },
      UINT8_C(  2) },
    { { -INT64_C( 4703763273352873136),  INT64_C(  609140942985469557) },
      {  INT64_C( 6583149311219430759),  INT64_C( 3925133254493566266) },
      UINT8_C(  3) },
    { { -INT64_C( 7132273744292277330),  INT64_C( 1859738716343859942) },
      { -INT64_C( 4731489261174113660),  INT64_C( 2424756789109931121) },
      UINT8_C(  3) },
    { { -INT64_C( 5762571255193183096), -INT64_C( 4062436381906990699) },
      { -INT64_C( 5762571255193183096), -INT64_C( 4062436381906990699) },
      UINT8_C(  3) },
    { {  INT64_C( 7566488941599975793), -INT64_C( 8013045671877893130) },
      {  INT64_C( 6376720280297455228), -INT64_C( 8013045671877893130) },
      UINT8_C(  2) },
    { { -INT64_C( 8913889438140375129),  INT64_C( 7971355152201659926) },
      {  INT64_C( 3642823068257611573),  INT64_C( 2384607049176468259) },
      UINT8_C(  1) },
    { { -INT64_C(  807772168516404535), -INT64_C( 7519293392000052968) },
      {  INT64_C( 3361270956742929869),  INT64_C(  682914647111704514) },
      UINT8_C(  3) },
    { { -INT64_C( 8792738824937362658), -INT64_C( 8127188560838166110) },
      { -INT64_C( 8792738824937362658), -INT64_C(  800543600252760627) },
      UINT8_C(  3) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_x_mm_loadu_epi64(test_vec[i].a);
    simde__m128i b = simde_x_mm_loadu_epi64(test_vec[i].b);
    simde__mmask8 r = simde_mm_cmple_epi64_mask(a, b);
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
    simde__mmask8 r = simde_mm_cmple_epi64_mask(a, b);

    simde_test_x86_write_i64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_mask_cmple_epi64_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k;
    const int64_t a[2];
    const int64_t b[2];
    const simde__mmask8 r;
  } test_vec[] = {
    { UINT8_C(206),
      {  INT64_C( 6075147771103424733),  INT64_C( 2312187117230448522) },
      { -INT64_C( 2931878406463972618),  INT64_C( 2312187117230448522) },
      UINT8_C(  2) },
    { UINT8_C(212),
      { -INT64_C( 1348690453920374222),  INT64_C( 5305133465933762923) },
      { -INT64_C( 5597200660377796674),  INT64_C( 5305133465933762923) },
      UINT8_C(  0) },
    { UINT8_C(153),
      {  INT64_C( 3500684105716873635), -INT64_C( 8748435850363194444) },
      {  INT64_C(    8012345944594166),  INT64_C(  627790790711570323) },
      UINT8_C(  0) },
    { UINT8_C(198),
      {  INT64_C( 8230997322103636026),  INT64_C( 3004005958441077073) },
      { -INT64_C( 7120414505682261873),  INT64_C( 6573888903169936282) },
      UINT8_C(  2) },
    { UINT8_C(168),
      { -INT64_C(  876361225485629094),  INT64_C( 6086838939931587850) },
      { -INT64_C( 1623813446220665721),  INT64_C( 6086838939931587850) },
      UINT8_C(  0) },
    { UINT8_C( 75),
      {  INT64_C( 1659775355734383218),  INT64_C( 9173616231437030520) },
      {  INT64_C( 1553621528270495106), -INT64_C( 1830232259695403756) },
      UINT8_C(  0) },
    { UINT8_C(  5),
      {  INT64_C( 1160001554356620147),  INT64_C( 4753476658556589186) },
      { -INT64_C( 8087076666870756791),  INT64_C( 8904530193044502882) },
      UINT8_C(  0) },
    { UINT8_C( 98),
      { -INT64_C( 7872447659223675313),  INT64_C( 2691766945732721993) },
      { -INT64_C(  907085362253706830),  INT64_C( 2691766945732721993) },
      UINT8_C(  2) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__mmask8 k = test_vec[i].k;
    simde__m128i a = simde_x_mm_loadu_epi64(test_vec[i].a);
    simde__m128i b = simde_x_mm_loadu_epi64(test_vec[i].b);
    simde__mmask8 r = simde_mm_mask_cmple_epi64_mask(k, a, b);
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
    simde__mmask8 r = simde_mm_mask_cmple_epi64_mask(k, a, b);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i64x2(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_x_mm256_cmple_epi64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int64_t a[4];
    const int64_t b[4];
    const int64_t r[4];
  } test_vec[] = {
    { {  INT64_C( 5518505813229536495),  INT64_C( 4963381827884117518),  INT64_C( 1608700868298153074),  INT64_C( 5890296414681658187) },
      { -INT64_C( 1142112330988833011), -INT64_C( 4931019064670695468),  INT64_C( 1608700868298153074),  INT64_C( 1067399297607956509) },
      {  INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0) } },
    { {  INT64_C( 2749679422816849415), -INT64_C( 6379849077216921261), -INT64_C( 8394439732338552093), -INT64_C(  521429158088519649) },
      {  INT64_C( 1987490173831870096), -INT64_C( 7896074934050654796),  INT64_C(  624051915328844947),  INT64_C( 6146370902352741219) },
      {  INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1) } },
    { {  INT64_C( 8904233069454907162), -INT64_C( 2710427067634287183),  INT64_C( 1543162710246689971), -INT64_C( 1153152582598084939) },
      {  INT64_C(  417796089005810820),  INT64_C( 3177197698852510028),  INT64_C( 1737734572575226296),  INT64_C( 4117993981240837986) },
      {  INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1) } },
    { { -INT64_C( 6288196955217832398),  INT64_C( 3333533211322274434), -INT64_C( 7180051829189353278), -INT64_C( 7630680633532579487) },
      { -INT64_C(  103636131063224649),  INT64_C( 4366939653932671905), -INT64_C( 7180051829189353278),  INT64_C( 5636610727170618942) },
      { -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1) } },
    { { -INT64_C( 6833195215581035747), -INT64_C( 2685765340945857254), -INT64_C( 1667569563363959813),  INT64_C( 9163817413785294045) },
      {  INT64_C( 5257504163209515054),  INT64_C(  985999227706332206), -INT64_C( 7616111740173541612),  INT64_C( 9163817413785294045) },
      { -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1) } },
    { {  INT64_C( 5818597112733002429),  INT64_C( 5062508385335668424),  INT64_C(  258176415476518854), -INT64_C( 4672602248824377916) },
      {  INT64_C( 5660297431467407359),  INT64_C( 6245204675707726808), -INT64_C( 8785421428379645701), -INT64_C( 4010583245188746090) },
      {  INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1) } },
    { {  INT64_C( 1057011647641064301), -INT64_C( 6865252890468591954), -INT64_C( 3832691920532484959), -INT64_C( 7628086040471591146) },
      {  INT64_C( 1057011647641064301),  INT64_C( 8600907540824727005), -INT64_C( 3832691920532484959),  INT64_C( 9107863202762242725) },
      { -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1) } },
    { { -INT64_C( 3142848440677572152),  INT64_C( 5738988082964512491), -INT64_C( 2742988465154765959),  INT64_C( 6757792620175905683) },
      { -INT64_C( 7767471679189332383), -INT64_C(  813603989703917532), -INT64_C( 5860870746085840565), -INT64_C( 2141490751650070187) },
      {  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256i a = simde_mm256_loadu_epi64(test_vec[i].a);
    simde__m256i b = simde_mm256_loadu_epi64(test_vec[i].b);
    simde__m256i r = simde_x_mm256_cmple_epi64(a, b);
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
    simde__m256i r = simde_x_mm256_cmple_epi64(a, b);

    simde_test_x86_write_i64x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i64x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_cmple_epi64_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int64_t a[4];
    const int64_t b[4];
    const simde__mmask8 r;
  } test_vec[] = {
    { {  INT64_C( 6961688778430421588),  INT64_C( 1967640177331526545),  INT64_C( 2117735781713066256), -INT64_C( 6298869753754235939) },
      {  INT64_C( 6961688778430421588), -INT64_C( 7152144413766248877),  INT64_C( 8451608981952193203),  INT64_C( 4750729418209906928) },
      UINT8_C( 13) },
    { {  INT64_C( 7870251324428045121),  INT64_C( 8150051712037222201), -INT64_C( 1142141115724045071),  INT64_C( 2117686728322061127) },
      { -INT64_C( 1107344865555712173),  INT64_C( 7506646772544809954), -INT64_C( 6485059914127764901),  INT64_C(  971665614213558915) },
      UINT8_C(  0) },
    { {  INT64_C(  411946939121852954),  INT64_C( 6190401058170135678), -INT64_C( 3167538953440204760), -INT64_C( 3499821696601192783) },
      {  INT64_C( 2132599144962529285), -INT64_C( 1823148890418444697),  INT64_C(  267572008165944775), -INT64_C( 4636694707429730270) },
      UINT8_C(  5) },
    { { -INT64_C( 5711986058904998923),  INT64_C( 7816604197949172945), -INT64_C( 8953957835563126333), -INT64_C( 3717275268725644212) },
      {  INT64_C( 2820065177597666432), -INT64_C( 6569279745928677297), -INT64_C( 5208335547092089749),  INT64_C( 1246841308983786410) },
      UINT8_C( 13) },
    { {  INT64_C( 4472159494617277784), -INT64_C( 7842900923136154232),  INT64_C( 7772523405685481650), -INT64_C(  527484517473310153) },
      {  INT64_C( 1171128901810731684),  INT64_C( 4562194310287794836),  INT64_C( 7772523405685481650),  INT64_C( 8231546364306575012) },
      UINT8_C( 14) },
    { {  INT64_C( 7267448423297954954), -INT64_C( 1277263323055576236),  INT64_C( 3864637580533143737),  INT64_C( 4821416456227380550) },
      {  INT64_C( 7267448423297954954), -INT64_C( 1277263323055576236), -INT64_C( 6816297699902199605), -INT64_C(  325282637126824318) },
      UINT8_C(  3) },
    { {  INT64_C( 5308085190565801239), -INT64_C( 8625532186752137906), -INT64_C( 1489109553849453927), -INT64_C( 4320209139177958917) },
      {  INT64_C( 5308085190565801239),  INT64_C( 6370351293101099698),  INT64_C( 3127126722033783226),  INT64_C(  580293457781869467) },
      UINT8_C( 15) },
    { { -INT64_C(  230370509780257989), -INT64_C(  663214666501769833),  INT64_C( 5798018916200558994),  INT64_C(  961502930405983057) },
      { -INT64_C(  230370509780257989), -INT64_C(  663214666501769833), -INT64_C( 2348079038570112356),  INT64_C(  961502930405983057) },
      UINT8_C( 11) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256i a = simde_mm256_loadu_epi64(test_vec[i].a);
    simde__m256i b = simde_mm256_loadu_epi64(test_vec[i].b);
    simde__mmask8 r = simde_mm256_cmple_epi64_mask(a, b);
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
    simde__mmask8 r = simde_mm256_cmple_epi64_mask(a, b);

    simde_test_x86_write_i64x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i64x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_mask_cmple_epi64_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k;
    const int64_t a[4];
    const int64_t b[4];
    const simde__mmask8 r;
  } test_vec[] = {
    { UINT8_C( 16),
      {  INT64_C( 2856962138038018638),  INT64_C( 3192109381195703071), -INT64_C( 8293423987400284054), -INT64_C( 5968559922310207967) },
      { -INT64_C( 4494080457374389363),  INT64_C(  950792385176599924),  INT64_C( 8479117375373409869), -INT64_C( 5968559922310207967) },
      UINT8_C(  0) },
    { UINT8_C(165),
      { -INT64_C( 4147944029381375537),  INT64_C( 6165201893960416444),  INT64_C( 5747086893734692062),  INT64_C( 8224907327584957908) },
      { -INT64_C( 1175812014245762810), -INT64_C( 3317541094489931478), -INT64_C( 1792383092847259203),  INT64_C( 1853545785488725411) },
      UINT8_C(  1) },
    { UINT8_C(188),
      { -INT64_C( 3646950239168894289), -INT64_C( 3546764331942464157), -INT64_C( 4042622055270470019), -INT64_C( 5904911806348984719) },
      { -INT64_C( 5884373701706720140), -INT64_C( 5033289090592415306), -INT64_C( 4042622055270470019), -INT64_C( 3234369173867342224) },
      UINT8_C( 12) },
    { UINT8_C( 98),
      { -INT64_C( 7363162810186789710), -INT64_C( 8442012789300425744), -INT64_C(  617158346008782791),  INT64_C( 5799906926175863430) },
      { -INT64_C( 6089230927066304395),  INT64_C( 2008899971242520383), -INT64_C(  617158346008782791),  INT64_C( 5799906926175863430) },
      UINT8_C(  2) },
    { UINT8_C(164),
      { -INT64_C( 7027875380734107738),  INT64_C( 6266941111382676185),  INT64_C( 6212060709454529024),  INT64_C( 5082316165859997815) },
      { -INT64_C(  246762144956405150),  INT64_C( 8860737131743597797),  INT64_C( 5552680877556771179),  INT64_C( 5082316165859997815) },
      UINT8_C(  0) },
    { UINT8_C(204),
      { -INT64_C( 7018249836985498548),  INT64_C(  730078973392393250), -INT64_C( 2409206026368159791),  INT64_C( 6427002863830193212) },
      { -INT64_C( 7018249836985498548), -INT64_C( 4455902881168347607), -INT64_C( 4277431697123720734), -INT64_C( 8773993981432190762) },
      UINT8_C(  0) },
    { UINT8_C(253),
      { -INT64_C( 1346553777050278095), -INT64_C( 8824922199928401347),  INT64_C( 2293808433010002744), -INT64_C( 7278242061309158533) },
      {  INT64_C( 4903092914256212900), -INT64_C( 6348726994997093797), -INT64_C(  445191713925414891), -INT64_C( 7278242061309158533) },
      UINT8_C(  9) },
    { UINT8_C( 24),
      {  INT64_C( 8557604192717924728),  INT64_C( 5501779098999679388), -INT64_C( 6203387982317923312),  INT64_C( 2201955268961908957) },
      {  INT64_C( 4212329784458470995),  INT64_C( 5501779098999679388), -INT64_C( 6203387982317923312),  INT64_C( 2201955268961908957) },
      UINT8_C(  8) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__mmask8 k = test_vec[i].k;
    simde__m256i a = simde_mm256_loadu_epi64(test_vec[i].a);
    simde__m256i b = simde_mm256_loadu_epi64(test_vec[i].b);
    simde__mmask8 r = simde_mm256_mask_cmple_epi64_mask(k, a, b);
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
    simde__mmask8 r = simde_mm256_mask_cmple_epi64_mask(k, a, b);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i64x4(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_x_mm512_cmple_epi64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int64_t a[8];
    const int64_t b[8];
    const int64_t r[8];
  } test_vec[] = {
    { {  INT64_C( 8266322416699925394),  INT64_C( 8633183062980258699),  INT64_C( 4636995730526157655), -INT64_C( 2167834169090223564),
        -INT64_C( 7740414485746210383),  INT64_C(  120112480745254897), -INT64_C( 3692413378265830028),  INT64_C( 3273212561656327483) },
      { -INT64_C( 5435875798633464590),  INT64_C( 8633183062980258699), -INT64_C( 5574638886851277250),  INT64_C( 4376841650098241813),
         INT64_C( 4853973235315182822),  INT64_C(  120112480745254897), -INT64_C( 3692413378265830028), -INT64_C( 4354548880482028789) },
      {  INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1),
        -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0) } },
    { {  INT64_C( 1365249598968301579),  INT64_C( 8211551296375085973), -INT64_C( 2441698350886109059),  INT64_C( 6664812128389794080),
        -INT64_C( 6085718702186250701), -INT64_C( 6277917642738704374),  INT64_C( 2252680519898801948),  INT64_C(  312522788400244393) },
      { -INT64_C( 3689845839838211317), -INT64_C( 6216624943409712664), -INT64_C( 8727604589981942333),  INT64_C( 6664812128389794080),
         INT64_C( 4177075808863078761),  INT64_C( 1322939329920316198), -INT64_C( 5609596468381586749), -INT64_C( 1843020647442504090) },
      {  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),
        -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0) } },
    { {  INT64_C( 3286992667864622140), -INT64_C( 8316473788513554136), -INT64_C( 1946579418404089959),  INT64_C( 5920787748750626289),
         INT64_C( 8348119324725972034),  INT64_C( 3791728087064356843), -INT64_C( 2650853358460825860),  INT64_C( 1926837882569816660) },
      {  INT64_C( 3286992667864622140),  INT64_C(  727244542340899400), -INT64_C( 1946579418404089959), -INT64_C( 1693875885143794804),
         INT64_C( 3302276408977343934),  INT64_C( 3791728087064356843), -INT64_C( 4598449877569920630),  INT64_C( 1926837882569816660) },
      { -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0),
         INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1) } },
    { { -INT64_C( 4794895220232221946), -INT64_C( 2400102504916289858),  INT64_C( 7054679331110180533),  INT64_C( 6535331446099162022),
         INT64_C( 7144518416068020533), -INT64_C( 1567808793975908637),  INT64_C( 4807100688160611036),  INT64_C( 4837158533362935156) },
      { -INT64_C( 4794895220232221946), -INT64_C( 3168555054893764120),  INT64_C( 7054679331110180533),  INT64_C( 3681690087589713605),
         INT64_C( 9009179018262266647),  INT64_C( 4090572310385971449), -INT64_C( 7802921973067747839), -INT64_C( 6422839437567815159) },
      { -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),
        -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0) } },
    { { -INT64_C( 8202462786182452197), -INT64_C( 2643922142756839699),  INT64_C( 8335707927323456888),  INT64_C( 6361505164205552300),
         INT64_C( 8116459055503541127),  INT64_C( 3566704367642596306),  INT64_C( 1356963814649168943),  INT64_C( 4570688219495013849) },
      { -INT64_C(   86139948422088485), -INT64_C( 6722148613756880437), -INT64_C( 5791953654768210139), -INT64_C( 2167301216893817099),
         INT64_C( 8116459055503541127), -INT64_C(   64667937574111227), -INT64_C( 1462215267851755985), -INT64_C( 7295685509729715240) },
      { -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
        -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0) } },
    { { -INT64_C(  262997905625150336), -INT64_C( 1755358151604771390), -INT64_C( 8828313382038389966),  INT64_C( 8404992289080093830),
        -INT64_C( 7648194280513720813), -INT64_C( 4034115218483323380), -INT64_C( 2922233278223496916), -INT64_C( 8018644304863300016) },
      { -INT64_C( 4998066851000842693),  INT64_C( 1047326476989820970), -INT64_C( 6500263995734609502),  INT64_C( 8404992289080093830),
         INT64_C( 6309874227835756585), -INT64_C( 2085835950896224482), -INT64_C( 2897045514571347760), -INT64_C( 9182516009780202029) },
      {  INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1),
        -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0) } },
    { {  INT64_C( 1401873213275153232), -INT64_C( 4771840972588299652), -INT64_C( 6084253540269523272),  INT64_C( 2390967000925988990),
        -INT64_C( 8835176222520339186),  INT64_C( 6347891429405465712), -INT64_C( 3815683248069481797),  INT64_C( 7193305603636456160) },
      {  INT64_C( 2081814956859491670), -INT64_C( 4771840972588299652), -INT64_C( 1400131250371357831),  INT64_C( 2390967000925988990),
        -INT64_C( 8835176222520339186),  INT64_C( 6347891429405465712), -INT64_C( 2817118999999711760), -INT64_C( 1451225650855311943) },
      { -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1),
        -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0) } },
    { {  INT64_C( 5945605151237899649), -INT64_C( 3060419024475224195), -INT64_C( 2694470265878520646), -INT64_C(  678739017188103735),
         INT64_C( 6835550409360988455),  INT64_C( 1889422085869808199), -INT64_C( 4081836868989440529),  INT64_C( 8284966672537332111) },
      {  INT64_C( 4482728662620977142), -INT64_C( 4215692690649431549), -INT64_C( 2694470265878520646), -INT64_C( 1583511202112088503),
         INT64_C( 6835550409360988455),  INT64_C( 1889422085869808199),  INT64_C(  213213694470854921), -INT64_C( 1860096102178080942) },
      {  INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),
        -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i a = simde_mm512_loadu_epi64(test_vec[i].a);
    simde__m512i b = simde_mm512_loadu_epi64(test_vec[i].b);
    simde__m512i r = simde_x_mm512_cmple_epi64(a, b);
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
    simde__m512i r = simde_x_mm512_cmple_epi64(a, b);

    simde_test_x86_write_i64x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i64x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_cmple_epi64_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int64_t a[8];
    const int64_t b[8];
    const simde__mmask8 r;
  } test_vec[] = {
    { { -INT64_C( 8529479443917465672), -INT64_C( 5924686159848809915), -INT64_C( 5296663220892778104),  INT64_C(  848656204639303170),
        -INT64_C( 1599420775950642016), -INT64_C( 4439578117358251805),  INT64_C( 8046134312070930307), -INT64_C( 1899443421474833338) },
      { -INT64_C( 8529479443917465672),  INT64_C(   85754753073753250), -INT64_C( 5296663220892778104),  INT64_C(  848656204639303170),
        -INT64_C( 1599420775950642016), -INT64_C( 4439578117358251805), -INT64_C( 5960426508503665740), -INT64_C( 1899443421474833338) },
      UINT8_C(191) },
    { {  INT64_C( 4341451571759908598), -INT64_C(  593856239661944047),  INT64_C( 9011461471445589980),  INT64_C( 6075344207714014247),
         INT64_C( 6336814567703000039),  INT64_C( 3076967277566049750),  INT64_C( 5329671208588882758),  INT64_C( 5101419904634497062) },
      {  INT64_C( 7885261560928088078), -INT64_C(  593856239661944047),  INT64_C(   88530131089404346), -INT64_C( 2807230432306635888),
         INT64_C( 6336814567703000039),  INT64_C( 3076967277566049750),  INT64_C( 5329671208588882758),  INT64_C( 5101419904634497062) },
      UINT8_C(243) },
    { { -INT64_C( 7830003627808070645),  INT64_C( 5517220854109837397),  INT64_C( 1240616035646952692), -INT64_C( 6070450286286758335),
         INT64_C( 1302815148128418897),  INT64_C( 7697220719749651300),  INT64_C( 2410137044327138712),  INT64_C( 7309472026793912100) },
      { -INT64_C( 7830003627808070645), -INT64_C( 6234691830783817064),  INT64_C( 2262454888363064866), -INT64_C( 6070450286286758335),
         INT64_C( 1302815148128418897),  INT64_C( 4308705801735777618),  INT64_C( 2410137044327138712),  INT64_C( 7309472026793912100) },
      UINT8_C(221) },
    { { -INT64_C( 4246357624998006214),  INT64_C( 1158589210237222993), -INT64_C( 3105069485458992819), -INT64_C( 4279417905092770588),
        -INT64_C( 1073362353613588455), -INT64_C( 8622001595150800503),  INT64_C( 2298678845162956624), -INT64_C( 5104147546682399408) },
      { -INT64_C( 4246357624998006214),  INT64_C( 1158589210237222993), -INT64_C( 7700301845358266167), -INT64_C( 7421889995251846291),
        -INT64_C( 1073362353613588455), -INT64_C( 3407376610310101785),  INT64_C( 5558841483451488330),  INT64_C( 6981868356262699243) },
      UINT8_C(243) },
    { { -INT64_C( 2560519771353241003), -INT64_C( 7440437166523347945), -INT64_C( 2831098483669073425), -INT64_C( 1528180986318353219),
        -INT64_C( 4517866159360838815),  INT64_C( 5440002401560256341), -INT64_C( 3779138924705267513),  INT64_C( 8489690569056248766) },
      {  INT64_C( 2362058614755594861), -INT64_C( 7440437166523347945),  INT64_C( 6951546417073476994), -INT64_C( 1528180986318353219),
        -INT64_C( 4517866159360838815), -INT64_C( 3186593255836610468), -INT64_C( 6067481274862267448), -INT64_C(  473499633734072315) },
      UINT8_C( 31) },
    { {  INT64_C( 6065999712325679917),  INT64_C( 7347487556073735051), -INT64_C( 5607376788445750228),  INT64_C( 8561894061998270701),
         INT64_C( 6808993213600014962),  INT64_C( 3475315483120861140),  INT64_C( 1236481272777200246), -INT64_C( 5320768189561008280) },
      { -INT64_C( 1100111837350851726), -INT64_C( 4084201512073064419), -INT64_C( 8246276572429507546), -INT64_C( 2656447127709838105),
         INT64_C( 6808993213600014962),  INT64_C( 7646216358790644984),  INT64_C( 1236481272777200246),  INT64_C( 4663090174983235441) },
      UINT8_C(240) },
    { { -INT64_C( 2241136548873155951),  INT64_C( 2552903568847830126), -INT64_C( 5352127706035504978), -INT64_C( 7289290713347619627),
         INT64_C( 7212676385149358858), -INT64_C( 8973438933475846130),  INT64_C( 8084802024116056542),  INT64_C(  635770381849759360) },
      { -INT64_C( 2241136548873155951),  INT64_C( 2552903568847830126), -INT64_C( 5352127706035504978), -INT64_C( 2392045490604763142),
         INT64_C( 7212676385149358858), -INT64_C( 8973438933475846130),  INT64_C( 1734876642658791721), -INT64_C( 3871217986796977892) },
      UINT8_C( 63) },
    { { -INT64_C( 7226228291511824670),  INT64_C( 5802298940312073715), -INT64_C( 9003627731748578559),  INT64_C( 5128638119645346066),
         INT64_C( 1312448684415245056),  INT64_C(  894959631754011639),  INT64_C(  966914919026268460), -INT64_C( 5289133183664889540) },
      {  INT64_C( 4702395677130320661),  INT64_C( 5802298940312073715), -INT64_C( 9003627731748578559),  INT64_C( 5128638119645346066),
         INT64_C( 1312448684415245056),  INT64_C(  894959631754011639),  INT64_C( 8317612370634191012),  INT64_C(  110925331219180305) },
         UINT8_MAX }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i a = simde_mm512_loadu_epi64(test_vec[i].a);
    simde__m512i b = simde_mm512_loadu_epi64(test_vec[i].b);
    simde__mmask8 r = simde_mm512_cmple_epi64_mask(a, b);
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
    simde__mmask8 r = simde_mm512_cmple_epi64_mask(a, b);

    simde_test_x86_write_i64x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i64x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_mask_cmple_epi64_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k;
    const int64_t a[8];
    const int64_t b[8];
    const simde__mmask8 r;
  } test_vec[] = {
    { UINT8_C(  7),
      { -INT64_C( 2844516344074405785), -INT64_C( 9060153030387865896), -INT64_C( 4931879254686392600), -INT64_C(  341981563328331772),
        -INT64_C(  122095103505996031),  INT64_C( 2519366219364261025), -INT64_C( 5124420506340539851),  INT64_C(  285265001784473702) },
      { -INT64_C( 8681875868039402914), -INT64_C( 6737119590515747037),  INT64_C( 2639017842594961459), -INT64_C( 6149362596272220764),
         INT64_C(  948768487561437886),  INT64_C( 5375866489581217162), -INT64_C( 5124420506340539851),  INT64_C(  285265001784473702) },
      UINT8_C(  6) },
    { UINT8_C( 64),
      { -INT64_C(  165392278068723833),  INT64_C( 1949711027235894425),  INT64_C( 7298230093203242782), -INT64_C(  349333037090908355),
         INT64_C( 5008601660917564651),  INT64_C( 8199291664203682005), -INT64_C(  163295342336197701),  INT64_C( 8476130236459425586) },
      {  INT64_C(  250367792194915975), -INT64_C( 6858846011697059828),  INT64_C( 8103296511388312502),  INT64_C( 6579962275641659472),
         INT64_C( 5008601660917564651), -INT64_C( 2615182749837710800), -INT64_C(  163295342336197701),  INT64_C( 8476130236459425586) },
      UINT8_C( 64) },
    { UINT8_C( 34),
      { -INT64_C( 4516195534072618515),  INT64_C( 3723855707882059410),  INT64_C( 8020557285167585107), -INT64_C( 2219192744305543076),
         INT64_C( 7714988152427944249),  INT64_C( 5572765808561696538), -INT64_C( 8785740937101284537), -INT64_C( 5920916892272714241) },
      { -INT64_C( 2050528948349196986),  INT64_C(  469602233190075965), -INT64_C( 4433587382898787129), -INT64_C( 2219192744305543076),
        -INT64_C( 4405770004897433809),  INT64_C(  333685550965449181),  INT64_C( 6773253333381958265),  INT64_C( 7990129283662787935) },
      UINT8_C(  0) },
    { UINT8_C(129),
      { -INT64_C( 2715279630866059685),  INT64_C( 4838904008080854617), -INT64_C( 1286076730519181977), -INT64_C( 8954926098594675114),
        -INT64_C( 3094627723791099740), -INT64_C( 7994800649950925509), -INT64_C( 3107832842380603672), -INT64_C( 7263421127783136888) },
      {  INT64_C( 8470387143927107132), -INT64_C( 3061239465151419959),  INT64_C( 7650107109555904728), -INT64_C(  759052551531620892),
        -INT64_C( 1401964036128684325), -INT64_C( 1358851149156791710),  INT64_C( 8129681826664147333),  INT64_C( 1563527777214065667) },
      UINT8_C(129) },
    { UINT8_C( 72),
      {  INT64_C( 6333048911557905146),  INT64_C(  664091954478533574),  INT64_C(  463687862119036064), -INT64_C( 5711519020425962364),
        -INT64_C( 7301475377093848347), -INT64_C( 8979044183519097027), -INT64_C( 8815700610349750278), -INT64_C( 4009754105739196429) },
      { -INT64_C( 7404261536663049777),  INT64_C(  990044328396328022), -INT64_C( 1187447286399064577), -INT64_C( 7977857623668472418),
        -INT64_C( 9055767789788896163), -INT64_C( 7016755968151369857),  INT64_C( 4758373669021830430), -INT64_C( 4009754105739196429) },
      UINT8_C( 64) },
    { UINT8_C(106),
      {  INT64_C( 7165654808771655386),  INT64_C( 4012788169182776100), -INT64_C( 8392805793278272501),  INT64_C( 1854027565592748401),
         INT64_C( 5387392736161472843),  INT64_C( 2248494767590787688),  INT64_C( 3981951482700563230),  INT64_C( 5924031242049237725) },
      { -INT64_C( 1696319391790882300),  INT64_C( 7526388304525461312), -INT64_C( 8392805793278272501),  INT64_C( 3093290313098052500),
         INT64_C( 6241647232967548982), -INT64_C( 4935349676755221296), -INT64_C( 7463669633697013306), -INT64_C( 7869159242174576517) },
      UINT8_C( 10) },
    { UINT8_C(227),
      { -INT64_C(  595667751745825832),  INT64_C( 1843259020232287585),  INT64_C( 2353138505765696966), -INT64_C( 8889891619549380785),
        -INT64_C( 3611265209274292074),  INT64_C( 3856342899417931035),  INT64_C( 5751593706379344305),  INT64_C( 3707629753508158019) },
      {  INT64_C( 4541600004315213517),  INT64_C( 1910422796256341726), -INT64_C( 6379175818646741208), -INT64_C( 1132641965752976008),
         INT64_C( 4998204380896913146),  INT64_C( 6891094807600629790),  INT64_C( 5751593706379344305),  INT64_C( 6850504328383912190) },
      UINT8_C(227) },
    { UINT8_C( 10),
      {  INT64_C( 2473454436993339783), -INT64_C( 8790549091253851134),  INT64_C( 7959066925616210507), -INT64_C( 6952042596120583225),
         INT64_C( 1894483927179763572),  INT64_C( 8624146081671641596), -INT64_C( 6133032001849812415), -INT64_C( 7858269946624820166) },
      {  INT64_C( 2473454436993339783),  INT64_C( 2387069296126902654),  INT64_C( 1637755396268934188),  INT64_C( 5252984801038173749),
         INT64_C( 1894483927179763572), -INT64_C( 7117958516554473674),  INT64_C( 9053192133450452658), -INT64_C( 1473319861784343699) },
      UINT8_C( 10) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__mmask8 k = test_vec[i].k;
    simde__m512i a = simde_mm512_loadu_epi64(test_vec[i].a);
    simde__m512i b = simde_mm512_loadu_epi64(test_vec[i].b);
    simde__mmask8 r = simde_mm512_mask_cmple_epi64_mask(k, a, b);
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
    simde__mmask8 r = simde_mm512_mask_cmple_epi64_mask(k, a, b);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i64x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_x_mm_cmple_epu64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const uint64_t a[2];
    const uint64_t b[2];
    const uint64_t r[2];
  } test_vec[] = {
    { { UINT64_C( 7497652662862585409), UINT64_C(  781118043477523484) },
      { UINT64_C(12224597918401654093), UINT64_C(  781118043477523484) },
      {                     UINT64_MAX,                     UINT64_MAX } },
    { { UINT64_C(  422150779129527442), UINT64_C(17140815207222449052) },
      { UINT64_C(13241951331757648424), UINT64_C( 8382699609670529588) },
      {                     UINT64_MAX, UINT64_C(                   0) } },
    { { UINT64_C(15529086322983089683), UINT64_C( 8764963707944902872) },
      { UINT64_C(15529086322983089683), UINT64_C( 1624754944659263286) },
      {                     UINT64_MAX, UINT64_C(                   0) } },
    { { UINT64_C(15179543702109076229), UINT64_C( 9449801264997774667) },
      { UINT64_C(12657439552840667755), UINT64_C(14388993943322340301) },
      { UINT64_C(                   0),                     UINT64_MAX } },
    { { UINT64_C( 6029272178002446159), UINT64_C( 7596498749468498485) },
      { UINT64_C( 5448080471855178312), UINT64_C( 8352763493606579666) },
      { UINT64_C(                   0),                     UINT64_MAX } },
    { { UINT64_C( 8282228214570244970), UINT64_C( 7046984110037945788) },
      { UINT64_C( 8282228214570244970), UINT64_C(15347961222014695213) },
      {                     UINT64_MAX,                     UINT64_MAX } },
    { { UINT64_C(  515462483676099306), UINT64_C( 1754939572513529202) },
      { UINT64_C( 1733588370304844611), UINT64_C( 1754939572513529202) },
      {                     UINT64_MAX,                     UINT64_MAX } },
    { { UINT64_C(10743192476594117650), UINT64_C( 3591520016251573690) },
      { UINT64_C( 7007931289368217787), UINT64_C( 3591520016251573690) },
      { UINT64_C(                   0),                     UINT64_MAX } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_x_mm_loadu_epi64(test_vec[i].a);
    simde__m128i b = simde_x_mm_loadu_epi64(test_vec[i].b);
    simde__m128i r = simde_x_mm_cmple_epu64(a, b);
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
    simde__m128i r = simde_x_mm_cmple_epu64(a, b);

    simde_test_x86_write_u64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_u64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_u64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_cmple_epu64_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const uint64_t a[2];
    const uint64_t b[2];
    const simde__mmask8 r;
  } test_vec[] = {
    { { UINT64_C( 6332166541751048136), UINT64_C(13130143720381828358) },
      { UINT64_C( 2303792469689634398), UINT64_C( 3987844490946977973) },
      UINT8_C(  0) },
    { { UINT64_C( 8288993057121365467), UINT64_C(17680981380770049306) },
      { UINT64_C(17194288776464919302), UINT64_C( 2332190904172482048) },
      UINT8_C(  1) },
    { { UINT64_C( 6417990391817948635), UINT64_C(10909080502100030873) },
      { UINT64_C( 6417990391817948635), UINT64_C(14010588385116341840) },
      UINT8_C(  3) },
    { { UINT64_C(15180928469092903334), UINT64_C( 2939298251803236215) },
      { UINT64_C(15180928469092903334), UINT64_C( 9740217133673618976) },
      UINT8_C(  3) },
    { { UINT64_C( 6450007552084205375), UINT64_C(18254432736944435939) },
      { UINT64_C( 7749164032316109109), UINT64_C( 3557135561273535263) },
      UINT8_C(  1) },
    { { UINT64_C( 4130882110425926429), UINT64_C(11117755993046265476) },
      { UINT64_C(17696412420239190944), UINT64_C(15483035468914788500) },
      UINT8_C(  3) },
    { { UINT64_C( 8212084615589542262), UINT64_C(16662269400784904711) },
      { UINT64_C( 8212084615589542262), UINT64_C(10693681993520138166) },
      UINT8_C(  1) },
    { { UINT64_C( 6374643732632912477), UINT64_C( 5433889938126812314) },
      { UINT64_C(12388213906778157333), UINT64_C(18074091669027948634) },
      UINT8_C(  3) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_x_mm_loadu_epi64(test_vec[i].a);
    simde__m128i b = simde_x_mm_loadu_epi64(test_vec[i].b);
    simde__mmask8 r = simde_mm_cmple_epu64_mask(a, b);
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
    simde__mmask8 r = simde_mm_cmple_epu64_mask(a, b);

    simde_test_x86_write_u64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_u64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_mask_cmple_epu64_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k;
    const uint64_t a[2];
    const uint64_t b[2];
    const simde__mmask8 r;
  } test_vec[] = {
    { UINT8_C( 49),
      { UINT64_C(14638986229949113091), UINT64_C(10942928995937214267) },
      { UINT64_C(14929758724764457670), UINT64_C(10942928995937214267) },
      UINT8_C(  1) },
    { UINT8_C(121),
      { UINT64_C( 4136338160363334004), UINT64_C(13880640808443870762) },
      { UINT64_C(14579038218255190374), UINT64_C( 4179174177999207160) },
      UINT8_C(  1) },
    { UINT8_C( 54),
      { UINT64_C( 9134812683183362677), UINT64_C( 5933185867255363236) },
      { UINT64_C( 4888762350429371629), UINT64_C( 9788462818306179108) },
      UINT8_C(  2) },
    { UINT8_C(  6),
      { UINT64_C( 2272261426191734506), UINT64_C( 1640701550826713549) },
      { UINT64_C(12027759218941371493), UINT64_C(11456653552651175489) },
      UINT8_C(  2) },
    { UINT8_C(152),
      { UINT64_C(10924324737631824390), UINT64_C(11052819680730057566) },
      { UINT64_C(11235367073607881416), UINT64_C( 8314651434970390974) },
      UINT8_C(  0) },
    { UINT8_C(150),
      { UINT64_C(14099008256755298742), UINT64_C( 7046647917673064877) },
      { UINT64_C(17348269917418149259), UINT64_C( 5253242885537748188) },
      UINT8_C(  0) },
    { UINT8_C(134),
      { UINT64_C(14586712255673390724), UINT64_C(15639147397409679195) },
      { UINT64_C(11763665374734350589), UINT64_C( 4494772450773075073) },
      UINT8_C(  0) },
    { UINT8_C(  5),
      { UINT64_C( 2259430852938500349), UINT64_C(12628834162517329358) },
      { UINT64_C( 9017459569121505782), UINT64_C( 4535824395156703021) },
      UINT8_C(  1) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__mmask8 k = test_vec[i].k;
    simde__m128i a = simde_x_mm_loadu_epi64(test_vec[i].a);
    simde__m128i b = simde_x_mm_loadu_epi64(test_vec[i].b);
    simde__mmask8 r = simde_mm_mask_cmple_epu64_mask(k, a, b);
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
    simde__mmask8 r = simde_mm_mask_cmple_epu64_mask(k, a, b);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_u64x2(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_u64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_x_mm256_cmple_epu64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const uint64_t a[4];
    const uint64_t b[4];
    const uint64_t r[4];
  } test_vec[] = {
    { { UINT64_C( 1476731742708374801), UINT64_C( 4655441209613413243), UINT64_C(  147669206914890556), UINT64_C(13573384914390209031) },
      { UINT64_C(17094928003036875639), UINT64_C(12009934077131028046), UINT64_C(13777690727706531798), UINT64_C(16458768148132008963) },
      {                     UINT64_MAX,                     UINT64_MAX,                     UINT64_MAX,                     UINT64_MAX } },
    { { UINT64_C(12351673116835269552), UINT64_C(16490621820216612049), UINT64_C(10400657768479657637), UINT64_C(13760610179596206042) },
      { UINT64_C( 8266962539187580110), UINT64_C(16490621820216612049), UINT64_C( 6319997772008189186), UINT64_C( 8840422775291521508) },
      { UINT64_C(                   0),                     UINT64_MAX, UINT64_C(                   0), UINT64_C(                   0) } },
    { { UINT64_C(15002430783941854354), UINT64_C(16749947404286328139), UINT64_C(18284268492297283817), UINT64_C( 7797703317449567811) },
      { UINT64_C(15002430783941854354), UINT64_C(16749947404286328139), UINT64_C( 9462224721582324481), UINT64_C(  956777189476452097) },
      {                     UINT64_MAX,                     UINT64_MAX, UINT64_C(                   0), UINT64_C(                   0) } },
    { { UINT64_C( 9234885443286271723), UINT64_C( 2311294249377227968), UINT64_C(17567859538405843952), UINT64_C( 9277595094188365243) },
      { UINT64_C(16756342974510875049), UINT64_C( 6981069185089082082), UINT64_C(15221919454738941216), UINT64_C(10109151677151658036) },
      {                     UINT64_MAX,                     UINT64_MAX, UINT64_C(                   0),                     UINT64_MAX } },
    { { UINT64_C(11799685238500499740), UINT64_C( 4544225649019298212), UINT64_C( 8247003029871677301), UINT64_C( 8695208828909632809) },
      { UINT64_C( 8471050798845389239), UINT64_C( 6718891158169883352), UINT64_C( 8247003029871677301), UINT64_C(16792718158624299830) },
      { UINT64_C(                   0),                     UINT64_MAX,                     UINT64_MAX,                     UINT64_MAX } },
    { { UINT64_C(16037357814983189433), UINT64_C(12480109118934994542), UINT64_C(11278264070972952507), UINT64_C(14573183377181347625) },
      { UINT64_C(13299670980182615997), UINT64_C(14449503695278230714), UINT64_C( 9640023563699940034), UINT64_C(14573183377181347625) },
      { UINT64_C(                   0),                     UINT64_MAX, UINT64_C(                   0),                     UINT64_MAX } },
    { { UINT64_C( 9332435295317567727), UINT64_C( 5789945717716552299), UINT64_C( 1724075395584959042), UINT64_C( 9829830320008697268) },
      { UINT64_C(  445774568380047930), UINT64_C(13764283031696472511), UINT64_C( 1724075395584959042), UINT64_C( 9111213350697415248) },
      { UINT64_C(                   0),                     UINT64_MAX,                     UINT64_MAX, UINT64_C(                   0) } },
    { { UINT64_C( 6038342853121039448), UINT64_C(12096635243295068174), UINT64_C(  997117176175007388), UINT64_C( 4823558518936979200) },
      { UINT64_C( 6038342853121039448), UINT64_C(14791904959654285302), UINT64_C( 1825242187243889022), UINT64_C( 4823558518936979200) },
      {                     UINT64_MAX,                     UINT64_MAX,                     UINT64_MAX,                     UINT64_MAX } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256i a = simde_mm256_loadu_epi64(test_vec[i].a);
    simde__m256i b = simde_mm256_loadu_epi64(test_vec[i].b);
    simde__m256i r = simde_x_mm256_cmple_epu64(a, b);
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
    simde__m256i r = simde_x_mm256_cmple_epu64(a, b);

    simde_test_x86_write_u64x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_u64x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_u64x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_cmple_epu64_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const uint64_t a[4];
    const uint64_t b[4];
    const simde__mmask8 r;
  } test_vec[] = {
    { { UINT64_C(13113748037153260330), UINT64_C(13545033770481086776), UINT64_C(17281602610360489750), UINT64_C(17893200228637262013) },
      { UINT64_C(13113748037153260330), UINT64_C( 7442617644148371482), UINT64_C(11351147899263863188), UINT64_C(17893200228637262013) },
      UINT8_C(  9) },
    { { UINT64_C( 9791991305610495547), UINT64_C( 6254789010400357793), UINT64_C( 9793027610944689625), UINT64_C( 1960977746939399426) },
      { UINT64_C( 9791991305610495547), UINT64_C( 5715242156672810114), UINT64_C( 1744071829637055475), UINT64_C( 1438989978319976701) },
      UINT8_C(  1) },
    { { UINT64_C( 1817923335221061822), UINT64_C(16414971711422237229), UINT64_C(13599489861730697697), UINT64_C(15759055092509029224) },
      { UINT64_C( 1817923335221061822), UINT64_C(16414971711422237229), UINT64_C(  852134306630831133), UINT64_C(15759055092509029224) },
      UINT8_C( 11) },
    { { UINT64_C(13693543033376448381), UINT64_C(14450977142257195352), UINT64_C(  926456201272844178), UINT64_C(10321961249506126270) },
      { UINT64_C(13848274633602313369), UINT64_C( 8537350331132392845), UINT64_C( 8948646674853482017), UINT64_C(16898694725982902499) },
      UINT8_C( 13) },
    { { UINT64_C( 2496333664771475556), UINT64_C( 3083197097191153284), UINT64_C(11712350048898971826), UINT64_C(16288365907205164761) },
      { UINT64_C(16126958551285602414), UINT64_C(15000450349662561942), UINT64_C( 5492685599806968391), UINT64_C( 1972179354402932478) },
      UINT8_C(  3) },
    { { UINT64_C( 1820281061790815657), UINT64_C(12978335368996286013), UINT64_C(14464026102357579071), UINT64_C(17643883201332189218) },
      { UINT64_C( 8166280887209772095), UINT64_C(14688790953275506148), UINT64_C( 9748819184137656679), UINT64_C( 1592783154879933915) },
      UINT8_C(  3) },
    { { UINT64_C( 8055974236119672259), UINT64_C(16396554551965689251), UINT64_C(15854995076903786246), UINT64_C( 3609709249349952245) },
      { UINT64_C( 8055974236119672259), UINT64_C(13739496994839360586), UINT64_C(15854995076903786246), UINT64_C( 6155387614518847946) },
      UINT8_C( 13) },
    { { UINT64_C( 9727538586281466603), UINT64_C( 2042635056648137639), UINT64_C( 2635353137869459086), UINT64_C( 3481451033647513595) },
      { UINT64_C( 6217331091123373811), UINT64_C(   67462128605629713), UINT64_C( 2635353137869459086), UINT64_C( 1972664770322468842) },
      UINT8_C(  4) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256i a = simde_mm256_loadu_epi64(test_vec[i].a);
    simde__m256i b = simde_mm256_loadu_epi64(test_vec[i].b);
    simde__mmask8 r = simde_mm256_cmple_epu64_mask(a, b);
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
    simde__mmask8 r = simde_mm256_cmple_epu64_mask(a, b);

    simde_test_x86_write_u64x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_u64x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_mask_cmple_epu64_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k;
    const uint64_t a[4];
    const uint64_t b[4];
    const simde__mmask8 r;
  } test_vec[] = {
    { UINT8_C( 64),
      { UINT64_C( 2598630522797958188), UINT64_C( 6631688277175042268), UINT64_C(15385238253478616681), UINT64_C(15349619557848376232) },
      { UINT64_C( 2598630522797958188), UINT64_C(15193187365607893795), UINT64_C( 3651478712159121961), UINT64_C(15349619557848376232) },
      UINT8_C(  0) },
    { UINT8_C( 28),
      { UINT64_C(11392665132327997637), UINT64_C(13436100338130611386), UINT64_C(  959964192855926859), UINT64_C( 8206199178299288965) },
      { UINT64_C(16070879926670214614), UINT64_C(13436100338130611386), UINT64_C( 4129786239347866089), UINT64_C(  990155534006743200) },
      UINT8_C(  4) },
    { UINT8_C(189),
      { UINT64_C( 1493646767642969982), UINT64_C(  459436515731010419), UINT64_C( 3582035660814850446), UINT64_C(13235053707708842671) },
      { UINT64_C(16377549434051162466), UINT64_C( 1462526959200192049), UINT64_C( 3582035660814850446), UINT64_C( 2376720544950280971) },
      UINT8_C(  5) },
    { UINT8_C(161),
      { UINT64_C(10477682402995933853), UINT64_C( 6364458252500696191), UINT64_C(15378006054015329608), UINT64_C( 8889758075436960162) },
      { UINT64_C(    2470059169435093), UINT64_C( 9631725416933761859), UINT64_C( 6234840834981760425), UINT64_C(12933307741416921635) },
      UINT8_C(  0) },
    { UINT8_C(148),
      { UINT64_C( 6454562710282839347), UINT64_C(16331093799587682529), UINT64_C( 5129890183613184313), UINT64_C( 4827593884255839620) },
      { UINT64_C(18096637696278127413), UINT64_C(16331093799587682529), UINT64_C( 5129890183613184313), UINT64_C( 4827593884255839620) },
      UINT8_C(  4) },
    { UINT8_C(201),
      { UINT64_C(14834122973733476316), UINT64_C(17277438021701202131), UINT64_C( 9505119847880377736), UINT64_C( 7693029478754538951) },
      { UINT64_C(14834122973733476316), UINT64_C( 3062977309940963387), UINT64_C( 9505119847880377736), UINT64_C( 7693029478754538951) },
      UINT8_C(  9) },
    { UINT8_C(186),
      { UINT64_C(  893286315297345514), UINT64_C( 3381216963848277784), UINT64_C( 1662933782237780428), UINT64_C(  956327878458589182) },
      { UINT64_C(18002635800051730846), UINT64_C(15266616730105907652), UINT64_C( 1662933782237780428), UINT64_C(10571585449540412804) },
      UINT8_C( 10) },
    { UINT8_C( 90),
      { UINT64_C(15979948997896827699), UINT64_C( 1098980882282354443), UINT64_C(12450268084727730287), UINT64_C(16875481172954995441) },
      { UINT64_C(16826691612274241716), UINT64_C( 1098980882282354443), UINT64_C( 2103266974796017577), UINT64_C(16875481172954995441) },
      UINT8_C( 10) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__mmask8 k = test_vec[i].k;
    simde__m256i a = simde_mm256_loadu_epi64(test_vec[i].a);
    simde__m256i b = simde_mm256_loadu_epi64(test_vec[i].b);
    simde__mmask8 r = simde_mm256_mask_cmple_epu64_mask(k, a, b);
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
    simde__mmask8 r = simde_mm256_mask_cmple_epu64_mask(k, a, b);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_u64x4(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_u64x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_x_mm512_cmple_epu64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const uint64_t a[8];
    const uint64_t b[8];
    const uint64_t r[8];
  } test_vec[] = {
    { { UINT64_C( 6060435681224086660), UINT64_C( 2029956866819318118), UINT64_C(17943460631708860267), UINT64_C(16810317165288097710),
        UINT64_C( 2633338862061273106), UINT64_C(17510052014234053856), UINT64_C(16000226454784063155), UINT64_C(  256642440654271040) },
      { UINT64_C( 6010551172752601990), UINT64_C( 6407556456319971697), UINT64_C(11275455856720421484), UINT64_C( 4764194586652505641),
        UINT64_C(10127170711782381252), UINT64_C( 7160285763345956961), UINT64_C( 7677645884082932116), UINT64_C(  256642440654271040) },
      { UINT64_C(                   0),                     UINT64_MAX, UINT64_C(                   0), UINT64_C(                   0),
                            UINT64_MAX, UINT64_C(                   0), UINT64_C(                   0),                     UINT64_MAX } },
    { { UINT64_C( 2972566613222433765), UINT64_C( 3107947439216738423), UINT64_C( 4501287655389635956), UINT64_C( 2157205768843039424),
        UINT64_C( 7192312293503876626), UINT64_C(  242979490653464953), UINT64_C( 4712610745464305889), UINT64_C(13327796879093184160) },
      { UINT64_C(11629754561150840342), UINT64_C( 3107947439216738423), UINT64_C(17343409789476389613), UINT64_C( 9745716413960067554),
        UINT64_C( 7192312293503876626), UINT64_C( 7910920741637409647), UINT64_C(11258873424776040190), UINT64_C( 8151062075882538790) },
      {                     UINT64_MAX,                     UINT64_MAX,                     UINT64_MAX,                     UINT64_MAX,
                            UINT64_MAX,                     UINT64_MAX,                     UINT64_MAX, UINT64_C(                   0) } },
    { { UINT64_C( 9652336085370620421), UINT64_C( 9430558906726535050), UINT64_C( 7588627390895031322), UINT64_C( 6161191817182877152),
        UINT64_C( 4128339262772589374), UINT64_C( 5511383612743622301), UINT64_C(12552232339015177826), UINT64_C(11436793811119336465) },
      { UINT64_C(18249339268044657242), UINT64_C( 9316104984946262220), UINT64_C(  181971312624497930), UINT64_C(12603353606035647978),
        UINT64_C( 4128339262772589374), UINT64_C( 9248998864822862522), UINT64_C(  969644063598356096), UINT64_C(11569536284411549836) },
      {                     UINT64_MAX, UINT64_C(                   0), UINT64_C(                   0),                     UINT64_MAX,
                            UINT64_MAX,                     UINT64_MAX, UINT64_C(                   0),                     UINT64_MAX } },
    { { UINT64_C(10785891400618871225), UINT64_C( 8216390802134730709), UINT64_C( 2947291071766486611), UINT64_C(  316362800243643176),
        UINT64_C( 4442488114257279228), UINT64_C( 8881727561117642218), UINT64_C(11412305581957027226), UINT64_C(17981020624344517434) },
      { UINT64_C(10785891400618871225), UINT64_C( 6053574269304733022), UINT64_C(11981805280775947314), UINT64_C( 6624430808372039415),
        UINT64_C(  619997740841433200), UINT64_C( 8881727561117642218), UINT64_C(11918692502010118741), UINT64_C(13120261451780100609) },
      {                     UINT64_MAX, UINT64_C(                   0),                     UINT64_MAX,                     UINT64_MAX,
        UINT64_C(                   0),                     UINT64_MAX,                     UINT64_MAX, UINT64_C(                   0) } },
    { { UINT64_C(12153640150159704405), UINT64_C(14591329408064755242), UINT64_C( 2332469472813848674), UINT64_C(15746128583770907921),
        UINT64_C( 5204027148448413245), UINT64_C(15209956050949153153), UINT64_C( 4717477932031514550), UINT64_C( 8889821159428243966) },
      { UINT64_C(  800026147320176564), UINT64_C(10315611328652589796), UINT64_C( 2332469472813848674), UINT64_C(11229830018639063326),
        UINT64_C(  798130160689603453), UINT64_C(15209956050949153153), UINT64_C(10026549259274555437), UINT64_C(   63543539822765407) },
      { UINT64_C(                   0), UINT64_C(                   0),                     UINT64_MAX, UINT64_C(                   0),
        UINT64_C(                   0),                     UINT64_MAX,                     UINT64_MAX, UINT64_C(                   0) } },
    { { UINT64_C(17089854092642170757), UINT64_C(  244247320514211691), UINT64_C(12638554157717474274), UINT64_C( 1145127660682833528),
        UINT64_C(15795409704515409286), UINT64_C( 7739460739008810176), UINT64_C( 6132836013423243874), UINT64_C( 7799256973570119331) },
      { UINT64_C(17719103994656433051), UINT64_C( 1344257075975985587), UINT64_C( 5811504637378787188), UINT64_C( 7675183588584605746),
        UINT64_C(15098137562158872157), UINT64_C( 1781373367095321078), UINT64_C(  372127321788331821), UINT64_C(13876048274606893143) },
      {                     UINT64_MAX,                     UINT64_MAX, UINT64_C(                   0),                     UINT64_MAX,
        UINT64_C(                   0), UINT64_C(                   0), UINT64_C(                   0),                     UINT64_MAX } },
    { { UINT64_C(13219955561119863994), UINT64_C( 5028475618100109295), UINT64_C( 6667576524363588964), UINT64_C( 7980687173488859652),
        UINT64_C( 7434671645015195884), UINT64_C(16020695281006394913), UINT64_C(13958956236849660118), UINT64_C( 1020322750472456710) },
      { UINT64_C( 6307768698686272682), UINT64_C( 8919865754470757233), UINT64_C(11671799276825439867), UINT64_C( 7980687173488859652),
        UINT64_C( 8215800479093510007), UINT64_C(11472399039977056790), UINT64_C( 3949888441463344532), UINT64_C( 2718410206142868469) },
      { UINT64_C(                   0),                     UINT64_MAX,                     UINT64_MAX,                     UINT64_MAX,
                            UINT64_MAX, UINT64_C(                   0), UINT64_C(                   0),                     UINT64_MAX } },
    { { UINT64_C(10882101885868235840), UINT64_C(11808040949912099851), UINT64_C(10778343761171042241), UINT64_C( 9004419950963681010),
        UINT64_C(14525767677829496828), UINT64_C(12831124711713889216), UINT64_C(  522335186434766366), UINT64_C(18218157806793580571) },
      { UINT64_C(10882101885868235840), UINT64_C(  761347948381969900), UINT64_C( 9415887072418640271), UINT64_C( 9004419950963681010),
        UINT64_C( 5211709704254442337), UINT64_C( 9460574023586224723), UINT64_C(  522335186434766366), UINT64_C(18218157806793580571) },
      {                     UINT64_MAX, UINT64_C(                   0), UINT64_C(                   0),                     UINT64_MAX,
        UINT64_C(                   0), UINT64_C(                   0),                     UINT64_MAX,                     UINT64_MAX } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i a = simde_mm512_loadu_epi64(test_vec[i].a);
    simde__m512i b = simde_mm512_loadu_epi64(test_vec[i].b);
    simde__m512i r = simde_x_mm512_cmple_epu64(a, b);
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
    simde__m512i r = simde_x_mm512_cmple_epu64(a, b);

    simde_test_x86_write_u64x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_u64x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_u64x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_cmple_epu64_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const uint64_t a[8];
    const uint64_t b[8];
    const simde__mmask8 r;
  } test_vec[] = {
    { { UINT64_C( 1477767704824611884), UINT64_C( 4828864202893554438), UINT64_C( 9378776310782652972), UINT64_C(16635880011119592098),
        UINT64_C(10881061260540607240), UINT64_C(15125644624700445502), UINT64_C(12927048440276514183), UINT64_C(13960118401208628252) },
      { UINT64_C( 1148612318178739657), UINT64_C( 4828864202893554438), UINT64_C( 7014611805456706453), UINT64_C(16635880011119592098),
        UINT64_C(10881061260540607240), UINT64_C( 4962783923632345130), UINT64_C(12927048440276514183), UINT64_C(15131481594662773514) },
      UINT8_C(218) },
    { { UINT64_C(14085472095698412677), UINT64_C(12733850595397296903), UINT64_C(15944375208510485277), UINT64_C( 6693385706924564736),
        UINT64_C( 6454795512453376915), UINT64_C(17925560010413842798), UINT64_C( 6915473349379134293), UINT64_C( 2613671707310613011) },
      { UINT64_C( 5761662900384421451), UINT64_C(12733850595397296903), UINT64_C(12643972073005378234), UINT64_C( 2306369494317544780),
        UINT64_C( 3018733911287854772), UINT64_C( 2929640409949751121), UINT64_C(14943430113386109206), UINT64_C( 2613671707310613011) },
      UINT8_C(194) },
    { { UINT64_C( 4460145999003187790), UINT64_C(14918826739138307768), UINT64_C(  482016427810993739), UINT64_C( 2742257695958028824),
        UINT64_C( 6688910480790193518), UINT64_C( 6962180284227306478), UINT64_C(13962060073883873881), UINT64_C(14845054455143787269) },
      { UINT64_C(11403174385564247871), UINT64_C(15235127208296962297), UINT64_C( 3073798167944294717), UINT64_C( 5650905993170179134),
        UINT64_C(18393389200984690676), UINT64_C( 6962180284227306478), UINT64_C(13962060073883873881), UINT64_C(14319691798712665436) },
      UINT8_C(127) },
    { { UINT64_C(10236123543216367195), UINT64_C(15015244650743131436), UINT64_C( 1025401775760062626), UINT64_C(12530492255915976160),
        UINT64_C( 9337881040531968486), UINT64_C( 3820048174235039422), UINT64_C( 1498542211890495041), UINT64_C(10990814656927527561) },
      { UINT64_C(15663578997321648777), UINT64_C( 5959686249731885292), UINT64_C(14741928938730118989), UINT64_C(12076171636490299212),
        UINT64_C( 6516117594192623480), UINT64_C( 3820048174235039422), UINT64_C(  647934210142101998), UINT64_C( 5375502259067528403) },
      UINT8_C( 37) },
    { { UINT64_C(17664461373145577413), UINT64_C( 4209498303171623847), UINT64_C(16637919973975225032), UINT64_C(15374382099069584355),
        UINT64_C(13635570453490913087), UINT64_C( 5720569364317496002), UINT64_C( 3960017927988219645), UINT64_C( 2627705133791649426) },
      { UINT64_C(11789762888588761802), UINT64_C( 5034794897120214280), UINT64_C( 3046481291862264253), UINT64_C(15374382099069584355),
        UINT64_C(13635570453490913087), UINT64_C( 1905856468085059045), UINT64_C( 3960017927988219645), UINT64_C( 8026585042215653079) },
      UINT8_C(218) },
    { { UINT64_C(15290737873795096508), UINT64_C(12024238062032346466), UINT64_C(14050038694268606714), UINT64_C( 8415058056974575794),
        UINT64_C(17533288026137817961), UINT64_C( 2635519660528860445), UINT64_C( 7447172255256212183), UINT64_C( 5836659510180224212) },
      { UINT64_C(15290737873795096508), UINT64_C(12024238062032346466), UINT64_C(14050038694268606714), UINT64_C( 1273296193772333684),
        UINT64_C( 4173710518752540980), UINT64_C(  488902431795659216), UINT64_C(10732798233162499980), UINT64_C( 5836659510180224212) },
      UINT8_C(199) },
    { { UINT64_C( 7158178962847164708), UINT64_C( 3886934667025771837), UINT64_C(10339702322888892869), UINT64_C( 9098438215542404732),
        UINT64_C(11765974426347991310), UINT64_C( 8197099619688153616), UINT64_C( 5827367454790767571), UINT64_C( 5784183510571424878) },
      { UINT64_C( 5118199373099308029), UINT64_C(14708639807627790081), UINT64_C(10339702322888892869), UINT64_C( 6748093600061838357),
        UINT64_C( 6745204066290293790), UINT64_C( 8197099619688153616), UINT64_C(13713800242177552579), UINT64_C( 5784183510571424878) },
      UINT8_C(230) },
    { { UINT64_C( 5408676400484146335), UINT64_C(17695189310868731946), UINT64_C(17899877089878582535), UINT64_C(14705163376408657321),
        UINT64_C(11271242620572006553), UINT64_C(   78814067815287351), UINT64_C( 4827458136030475941), UINT64_C(13801926637802547600) },
      { UINT64_C(12705019009903360579), UINT64_C( 7372652900722655317), UINT64_C(11330328845819345506), UINT64_C(  304246693486622035),
        UINT64_C(13261143099104172256), UINT64_C( 3094632412811353292), UINT64_C( 2052342670057365201), UINT64_C(11357461149019133912) },
      UINT8_C( 49) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i a = simde_mm512_loadu_epi64(test_vec[i].a);
    simde__m512i b = simde_mm512_loadu_epi64(test_vec[i].b);
    simde__mmask8 r = simde_mm512_cmple_epu64_mask(a, b);
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
    simde__mmask8 r = simde_mm512_cmple_epu64_mask(a, b);

    simde_test_x86_write_u64x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_u64x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_mask_cmple_epu64_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k;
    const uint64_t a[8];
    const uint64_t b[8];
    const simde__mmask8 r;
  } test_vec[] = {
    { UINT8_C(173),
      { UINT64_C( 3516940084831783131), UINT64_C( 3382635801166672908), UINT64_C( 4231806211819275872), UINT64_C(10038106507138281660),
        UINT64_C(14131167226466601612), UINT64_C( 1402460836594264561), UINT64_C( 6890766516886781457), UINT64_C( 3807456657693156252) },
      { UINT64_C(17605761729770292695), UINT64_C( 3382635801166672908), UINT64_C(16497686302375697649), UINT64_C( 1697300983025988274),
        UINT64_C( 5693671336613228043), UINT64_C(16422819085880344552), UINT64_C( 6890766516886781457), UINT64_C( 6644218268858075869) },
      UINT64_C(                 165) },
    { UINT8_C(161),
      { UINT64_C(16271931007146336335), UINT64_C( 7873242278713100538), UINT64_C( 8179410579056648403), UINT64_C( 6169658836153539972),
        UINT64_C(13552185329535368744), UINT64_C(10277325104838957840), UINT64_C(18288245591431601861), UINT64_C( 4926249818473305091) },
      { UINT64_C(12414886628298233036), UINT64_C(10749670994103725028), UINT64_C( 8179410579056648403), UINT64_C(11327080630522627024),
        UINT64_C(13552185329535368744), UINT64_C(18106406865246330081), UINT64_C(13934883754952766834), UINT64_C( 3987900927291811049) },
      UINT64_C(                  32) },
    { UINT8_C(137),
      { UINT64_C(  491096663977265789), UINT64_C(18418236055174494475), UINT64_C( 3371501409563464805), UINT64_C(14260648530500091714),
        UINT64_C( 7665676731149493899), UINT64_C( 8559008700522256557), UINT64_C(14331443045230873097), UINT64_C(10813412134169152002) },
      { UINT64_C(15449127011526718620), UINT64_C(18418236055174494475), UINT64_C( 8231130341699874032), UINT64_C(15673878269038249955),
        UINT64_C( 8359027019074532866), UINT64_C(17812688737464787132), UINT64_C(14331443045230873097), UINT64_C(13548051135659830766) },
      UINT64_C(                 137) },
    { UINT8_C(169),
      { UINT64_C( 2228587979143692860), UINT64_C(14449806944671673332), UINT64_C(10376645072497390554), UINT64_C(16256150378949875751),
        UINT64_C(11981947420587076148), UINT64_C( 5241567019710572569), UINT64_C(12016866591514509436), UINT64_C(  980184764960368404) },
      { UINT64_C( 2228587979143692860), UINT64_C( 6385632423645090535), UINT64_C(12229613389299325330), UINT64_C( 4079694732863893175),
        UINT64_C( 4124794037190578966), UINT64_C(13221491144091685705), UINT64_C( 1118160826122438725), UINT64_C(18007147108672464623) },
      UINT64_C(                 161) },
    { UINT8_C( 24),
      { UINT64_C( 8402457325365882665), UINT64_C(16195187229827298895), UINT64_C(11513660618947391099), UINT64_C(17209639308137409108),
        UINT64_C( 8771569692134646746), UINT64_C(16010306993160554070), UINT64_C(  390509910432347255), UINT64_C( 5925334649473633416) },
      { UINT64_C(13135120363972755623), UINT64_C( 1448248799809410009), UINT64_C(10799995904306753322), UINT64_C(17209639308137409108),
        UINT64_C( 8771569692134646746), UINT64_C( 1952798553002916457), UINT64_C( 2093847570156026219), UINT64_C(12445995602270875880) },
      UINT64_C(                  24) },
    { UINT8_C(218),
      { UINT64_C(11315052878202768096), UINT64_C( 9140899378832244506), UINT64_C(15548178060565862508), UINT64_C(13644350912778706659),
        UINT64_C(11692576668305154819), UINT64_C(10658734054428649440), UINT64_C(10714016998348519494), UINT64_C( 2165722464218686324) },
      { UINT64_C(12159167898539354260), UINT64_C( 9140899378832244506), UINT64_C( 4881777541521602937), UINT64_C( 6587537852548289841),
        UINT64_C( 7816900109298774282), UINT64_C(  886838124225991047), UINT64_C(17129993946978004391), UINT64_C( 2165722464218686324) },
      UINT64_C(                 194) },
    { UINT8_C(159),
      { UINT64_C(11788025200907200321), UINT64_C( 1455311149495946673), UINT64_C( 6126301979804468359), UINT64_C(15488035885197170380),
        UINT64_C( 9858200188576161206), UINT64_C(  235702841047461738), UINT64_C( 1543948835312716518), UINT64_C( 6968787894121733196) },
      { UINT64_C( 4816701885606820984), UINT64_C( 1455311149495946673), UINT64_C(13646424128010861315), UINT64_C(15488035885197170380),
        UINT64_C( 9858200188576161206), UINT64_C(  235702841047461738), UINT64_C( 1543948835312716518), UINT64_C(12474080217315969364) },
      UINT64_C(                 158) },
    { UINT8_C(107),
      { UINT64_C( 6803762467957038892), UINT64_C( 1032700379234015799), UINT64_C(17937441957918494907), UINT64_C( 1427062632171188974),
        UINT64_C(10095148786461541585), UINT64_C( 6871051177770664390), UINT64_C(14741651428475881008), UINT64_C( 2525050799767904272) },
      { UINT64_C(13704164458591341388), UINT64_C(14608661905431771833), UINT64_C(10976955131113155498), UINT64_C( 7336250653558132826),
        UINT64_C(10095148786461541585), UINT64_C( 3698432246823003375), UINT64_C(14741651428475881008), UINT64_C(15123238652030407522) },
      UINT64_C(                  75) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__mmask8 k = test_vec[i].k;
    simde__m512i a = simde_mm512_loadu_epi64(test_vec[i].a);
    simde__m512i b = simde_mm512_loadu_epi64(test_vec[i].b);
    simde__mmask8 r = simde_mm512_mask_cmple_epu64_mask(k, a, b);
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
    simde__mmask8 r = simde_mm512_mask_cmple_epu64_mask(k, a, b);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_u64x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_u64x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask64(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(x_mm_cmple_epi8)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_cmple_epi8_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_mask_cmple_epi8_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(x_mm256_cmple_epi8)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_cmple_epi8_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_mask_cmple_epi8_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(x_mm512_cmple_epi8)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_cmple_epi8_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_cmple_epi8_mask)

  SIMDE_TEST_FUNC_LIST_ENTRY(x_mm_cmple_epu8)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_cmple_epu8_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_mask_cmple_epu8_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(x_mm256_cmple_epu8)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_cmple_epu8_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_mask_cmple_epu8_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(x_mm512_cmple_epu8)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_cmple_epu8_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_cmple_epu8_mask)

  SIMDE_TEST_FUNC_LIST_ENTRY(x_mm_cmple_epi16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_cmple_epi16_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_mask_cmple_epi16_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(x_mm256_cmple_epi16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_cmple_epi16_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_mask_cmple_epi16_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(x_mm512_cmple_epi16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_cmple_epi16_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_cmple_epi16_mask)

  SIMDE_TEST_FUNC_LIST_ENTRY(x_mm_cmple_epu16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_cmple_epu16_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_mask_cmple_epu16_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(x_mm256_cmple_epu16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_cmple_epu16_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_mask_cmple_epu16_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(x_mm512_cmple_epu16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_cmple_epu16_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_cmple_epu16_mask)

  SIMDE_TEST_FUNC_LIST_ENTRY(x_mm_cmple_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_cmple_epi32_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_mask_cmple_epi32_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(x_mm256_cmple_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_cmple_epi32_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_mask_cmple_epi32_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(x_mm512_cmple_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_cmple_epi32_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_cmple_epi32_mask)

  SIMDE_TEST_FUNC_LIST_ENTRY(x_mm_cmple_epu32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_cmple_epu32_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_mask_cmple_epu32_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(x_mm256_cmple_epu32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_cmple_epu32_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_mask_cmple_epu32_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(x_mm512_cmple_epu32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_cmple_epu32_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_cmple_epu32_mask)

  SIMDE_TEST_FUNC_LIST_ENTRY(x_mm_cmple_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_cmple_epi64_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_mask_cmple_epi64_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(x_mm256_cmple_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_cmple_epi64_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_mask_cmple_epi64_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(x_mm512_cmple_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_cmple_epi64_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_cmple_epi64_mask)

  SIMDE_TEST_FUNC_LIST_ENTRY(x_mm_cmple_epu64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_cmple_epu64_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_mask_cmple_epu64_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(x_mm256_cmple_epu64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_cmple_epu64_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_mask_cmple_epu64_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(x_mm512_cmple_epu64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_cmple_epu64_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_cmple_epu64_mask)
SIMDE_TEST_FUNC_LIST_END

#include <test/x86/avx512/test-avx512-footer.h>
