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

#define SIMDE_TEST_X86_AVX512_INSN add

#include <test/x86/avx512/test-avx512.h>
#include <simde/x86/avx512/set.h>
#include <simde/x86/avx512/add.h>

static int
test_simde_mm_mask_add_epi8 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const int8_t src[16];
    const simde__mmask16 k;
    const int8_t a[16];
    const int8_t b[16];
    const int8_t r[16];
  } test_vec[] = {
           { { -INT8_C(  27), -INT8_C( 117), -INT8_C(   6),  INT8_C(  88), -INT8_C(  46),  INT8_C(  97), -INT8_C(  33),  INT8_C(  41),
        -INT8_C(  39), -INT8_C(   6), -INT8_C(  94),  INT8_C(  57), -INT8_C(  33),  INT8_C(  58),  INT8_C( 124), -INT8_C(  31) },
      UINT16_C( 5189),
      {  INT8_C( 116),  INT8_C(  54), -INT8_C(  13),  INT8_C(   7), -INT8_C(  49), -INT8_C(  33), -INT8_C( 119),  INT8_C(  78),
         INT8_C(  14), -INT8_C(  94),  INT8_C(  14), -INT8_C(  68), -INT8_C(  88),  INT8_C(  20),  INT8_C(  70), -INT8_C( 115) },
      {  INT8_C(   9), -INT8_C( 104), -INT8_C(  11), -INT8_C( 116), -INT8_C(  58), -INT8_C(  28),  INT8_C(  17), -INT8_C( 115),
        -INT8_C(  25), -INT8_C( 123), -INT8_C(  27),  INT8_C(  40),  INT8_C(  24), -INT8_C(  71), -INT8_C(  96), -INT8_C(  45) },
      {  INT8_C( 125), -INT8_C( 117), -INT8_C(  24),  INT8_C(  88), -INT8_C(  46),  INT8_C(  97), -INT8_C( 102),  INT8_C(  41),
        -INT8_C(  39), -INT8_C(   6), -INT8_C(  13),  INT8_C(  57), -INT8_C(  64),  INT8_C(  58),  INT8_C( 124), -INT8_C(  31) } },
    { { -INT8_C(  98), -INT8_C(  92), -INT8_C(  38), -INT8_C(  68), -INT8_C(  41),  INT8_C( 122), -INT8_C(  22), -INT8_C(  38),
         INT8_C(  27), -INT8_C(  33),  INT8_C( 109), -INT8_C(  84), -INT8_C(  65), -INT8_C(  97), -INT8_C(  87), -INT8_C(  26) },
      UINT16_C(48315),
      {  INT8_C(  33), -INT8_C(  21),  INT8_C( 102),  INT8_C( 107), -INT8_C(  24),  INT8_C( 118), -INT8_C(  19), -INT8_C( 100),
         INT8_C(  41),  INT8_C(  78), -INT8_C(  81),  INT8_C(  11),  INT8_C(  38), -INT8_C( 101),  INT8_C(  39), -INT8_C( 103) },
      {  INT8_C(  68), -INT8_C(  83),      INT8_MIN,  INT8_C( 118), -INT8_C( 117),  INT8_C( 112), -INT8_C(  32), -INT8_C( 114),
         INT8_C(  16), -INT8_C(  45),  INT8_C(  93),  INT8_C(  38), -INT8_C(  71), -INT8_C(  60),  INT8_C(  99), -INT8_C(  64) },
      {  INT8_C( 101), -INT8_C( 104), -INT8_C(  38), -INT8_C(  31),  INT8_C( 115), -INT8_C(  26), -INT8_C(  22),  INT8_C(  42),
         INT8_C(  27), -INT8_C(  33),  INT8_C(  12),  INT8_C(  49), -INT8_C(  33),  INT8_C(  95), -INT8_C(  87),  INT8_C(  89) } },
    { { -INT8_C(  32), -INT8_C(  57),  INT8_C(  78), -INT8_C(  38), -INT8_C(  31), -INT8_C(  49), -INT8_C(   2), -INT8_C(  91),
         INT8_C( 122), -INT8_C( 124),  INT8_C(  43),  INT8_C( 111),  INT8_C(  13), -INT8_C(  53), -INT8_C(  99), -INT8_C(   7) },
      UINT16_C(55519),
      { -INT8_C( 112),  INT8_C(  59),  INT8_C(  27), -INT8_C(  75), -INT8_C(  30),  INT8_C(  46),  INT8_C(  88), -INT8_C(  37),
         INT8_C(  68), -INT8_C(  86), -INT8_C(  84), -INT8_C(  81),  INT8_C(  73), -INT8_C(  81),  INT8_C( 111),  INT8_C(  71) },
      {  INT8_C(  75),  INT8_C( 105),  INT8_C(  40), -INT8_C(  50), -INT8_C(  66),  INT8_C( 107), -INT8_C(  47),  INT8_C( 108),
        -INT8_C(  44), -INT8_C(  70), -INT8_C( 126),  INT8_C(  70),  INT8_C(  82), -INT8_C(  48), -INT8_C(  16), -INT8_C(  11) },
      { -INT8_C(  37), -INT8_C(  92),  INT8_C(  67), -INT8_C( 125), -INT8_C(  96), -INT8_C(  49),  INT8_C(  41),  INT8_C(  71),
         INT8_C( 122), -INT8_C( 124),  INT8_C(  43), -INT8_C(  11), -INT8_C( 101), -INT8_C(  53),  INT8_C(  95),  INT8_C(  60) } },
    { { -INT8_C(  10),  INT8_C(  74),  INT8_C(  22),      INT8_MAX, -INT8_C(  86), -INT8_C(  38), -INT8_C(  55), -INT8_C(  34),
         INT8_C(  37), -INT8_C(  93),  INT8_C( 113),  INT8_C(  90), -INT8_C(  22),  INT8_C(  95), -INT8_C(  30),  INT8_C(  36) },
      UINT16_C(49528),
      { -INT8_C(  86), -INT8_C(  18),  INT8_C(   8), -INT8_C(  80),  INT8_C(  64), -INT8_C( 123), -INT8_C(  65),  INT8_C(  70),
         INT8_C(  76), -INT8_C(  38),  INT8_C(  79),  INT8_C(   7), -INT8_C( 112), -INT8_C(  51),  INT8_C(  59),  INT8_C(  55) },
      { -INT8_C( 115), -INT8_C(  53), -INT8_C( 116), -INT8_C( 104),  INT8_C(  80),  INT8_C(  21),  INT8_C(  61),  INT8_C(   7),
        -INT8_C(  99), -INT8_C(  92), -INT8_C(  35),  INT8_C(  32), -INT8_C(   2),  INT8_C(  80),  INT8_C( 120), -INT8_C(  12) },
      { -INT8_C(  10),  INT8_C(  74),  INT8_C(  22),  INT8_C(  72), -INT8_C( 112), -INT8_C( 102), -INT8_C(   4), -INT8_C(  34),
        -INT8_C(  23), -INT8_C(  93),  INT8_C( 113),  INT8_C(  90), -INT8_C(  22),  INT8_C(  95), -INT8_C(  77),  INT8_C(  43) } },
    { {  INT8_C(   4),      INT8_MIN, -INT8_C(  71), -INT8_C(  17), -INT8_C(  48), -INT8_C(   5),      INT8_MAX,  INT8_C( 111),
         INT8_C( 107), -INT8_C( 122), -INT8_C( 126), -INT8_C(  76), -INT8_C( 121), -INT8_C(  65), -INT8_C( 115), -INT8_C(  46) },
      UINT16_C(28165),
      {  INT8_C(  27), -INT8_C(  48), -INT8_C(  86),  INT8_C(  54), -INT8_C(  32),  INT8_C(  59),  INT8_C( 122), -INT8_C(  12),
        -INT8_C(   6),  INT8_C(  28),  INT8_C(  89),  INT8_C(  69),  INT8_C(  57), -INT8_C(  19), -INT8_C(  99), -INT8_C(  37) },
      {  INT8_C(  97), -INT8_C(  39),  INT8_C( 120),  INT8_C( 103), -INT8_C(  90),  INT8_C(  20),  INT8_C( 101),  INT8_C(  30),
         INT8_C(  57),  INT8_C(  57), -INT8_C(  13),  INT8_C(  10),  INT8_C(  41), -INT8_C(  13), -INT8_C(  53),  INT8_C(  21) },
      {  INT8_C( 124),      INT8_MIN,  INT8_C(  34), -INT8_C(  17), -INT8_C(  48), -INT8_C(   5),      INT8_MAX,  INT8_C( 111),
         INT8_C( 107),  INT8_C(  85),  INT8_C(  76),  INT8_C(  79), -INT8_C( 121), -INT8_C(  32),  INT8_C( 104), -INT8_C(  46) } },
    { { -INT8_C( 125),  INT8_C( 109),  INT8_C(  50),  INT8_C(  49),  INT8_C(  76),  INT8_C(  38),  INT8_C(  43),  INT8_C(  37),
        -INT8_C( 125), -INT8_C(  52),  INT8_C( 115),  INT8_C( 100),  INT8_C(  45),  INT8_C(  74), -INT8_C(   5), -INT8_C( 110) },
      UINT16_C(47574),
      { -INT8_C(  76),  INT8_C(  26), -INT8_C( 112), -INT8_C(  90), -INT8_C(  73), -INT8_C( 123),  INT8_C(  15), -INT8_C(  19),
        -INT8_C(  57), -INT8_C(  58), -INT8_C(  79),  INT8_C(   7), -INT8_C(  26),  INT8_C(  47), -INT8_C(  11),      INT8_MAX },
      { -INT8_C(  44),  INT8_C(  76), -INT8_C(   8),  INT8_C(  91),  INT8_C(  64),  INT8_C(  42), -INT8_C(  48),  INT8_C(  22),
        -INT8_C(  10),  INT8_C(   4),  INT8_C(  93), -INT8_C(  57), -INT8_C(  42), -INT8_C(  31),  INT8_C( 109),  INT8_C(  88) },
      { -INT8_C( 125),  INT8_C( 102), -INT8_C( 120),  INT8_C(  49), -INT8_C(   9),  INT8_C(  38), -INT8_C(  33),  INT8_C(   3),
        -INT8_C(  67), -INT8_C(  52),  INT8_C( 115), -INT8_C(  50), -INT8_C(  68),  INT8_C(  16), -INT8_C(   5), -INT8_C(  41) } },
    { {  INT8_C(  20),  INT8_C(  50),  INT8_C(   9),  INT8_C(  94), -INT8_C(  69),  INT8_C(  31),  INT8_C(  50),  INT8_C(  65),
        -INT8_C(  79),  INT8_C( 123), -INT8_C(  96),  INT8_C(  34), -INT8_C(  70), -INT8_C(  37), -INT8_C(   3),  INT8_C(  22) },
      UINT16_C(58436),
      {  INT8_C( 126), -INT8_C(  47), -INT8_C( 126), -INT8_C(  42),  INT8_C(  30),  INT8_C( 111), -INT8_C(  34),  INT8_C(  96),
        -INT8_C(  65),  INT8_C(  94), -INT8_C(  39), -INT8_C(  47), -INT8_C(  73),  INT8_C( 120),  INT8_C(  10),  INT8_C(  18) },
      {  INT8_C(  72),  INT8_C(  25),  INT8_C(  71),  INT8_C(  82),  INT8_C( 115), -INT8_C(  50),  INT8_C(  16),  INT8_C(  21),
        -INT8_C(  37), -INT8_C(  92),  INT8_C(  58),  INT8_C(  57),  INT8_C(  41), -INT8_C(  77), -INT8_C( 116),  INT8_C(  92) },
      {  INT8_C(  20),  INT8_C(  50), -INT8_C(  55),  INT8_C(  94), -INT8_C(  69),  INT8_C(  31), -INT8_C(  18),  INT8_C(  65),
        -INT8_C(  79),  INT8_C( 123),  INT8_C(  19),  INT8_C(  34), -INT8_C(  70),  INT8_C(  43), -INT8_C( 106),  INT8_C( 110) } },
    { {  INT8_C(  29), -INT8_C(  38), -INT8_C(  54), -INT8_C( 111), -INT8_C(  23), -INT8_C(  86), -INT8_C(   8),  INT8_C(  21),
         INT8_C(  98),  INT8_C(  54),  INT8_C( 102), -INT8_C(  84),  INT8_C(  14),  INT8_C(  23),  INT8_C(  88),  INT8_C(  42) },
      UINT16_C(45295),
      {  INT8_C(   4),  INT8_C(  61),  INT8_C(  20), -INT8_C(  59),  INT8_C(  94),  INT8_C(  39), -INT8_C(  42),  INT8_C(  68),
        -INT8_C( 116),  INT8_C(  24), -INT8_C(  43), -INT8_C(  18),  INT8_C(  50),  INT8_C(  74), -INT8_C(  67),  INT8_C( 123) },
      { -INT8_C(   6),  INT8_C(   9),  INT8_C(  16), -INT8_C(  80), -INT8_C(  95),  INT8_C( 115), -INT8_C(  62),  INT8_C(  63),
        -INT8_C(  62), -INT8_C( 105),  INT8_C( 107), -INT8_C( 107), -INT8_C(  91), -INT8_C(  56), -INT8_C(  62), -INT8_C(  15) },
      { -INT8_C(   2),  INT8_C(  70),  INT8_C(  36),  INT8_C( 117), -INT8_C(  23), -INT8_C( 102), -INT8_C( 104), -INT8_C( 125),
         INT8_C(  98),  INT8_C(  54),  INT8_C( 102), -INT8_C(  84), -INT8_C(  41),  INT8_C(  18),  INT8_C(  88),  INT8_C( 108) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i src = simde_x_mm_loadu_epi8(test_vec[i].src);
    simde__m128i a = simde_x_mm_loadu_epi8(test_vec[i].a);
    simde__m128i b = simde_x_mm_loadu_epi8(test_vec[i].b);
    simde__m128i r = simde_mm_mask_add_epi8(src, test_vec[i].k, a, b);
    simde_test_x86_assert_equal_i8x16(r, simde_x_mm_loadu_epi8(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_mm_maskz_add_epi8 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const simde__mmask16 k;
    const int8_t a[16];
    const int8_t b[16];
    const int8_t r[16];
  } test_vec[] = {
    { UINT16_C(19804),
      {  INT8_C(  27),  INT8_C(  33), -INT8_C(  11),  INT8_C(  13), -INT8_C(  52),  INT8_C(  94),  INT8_C(  66),  INT8_C(  86),
         INT8_C(  52),  INT8_C(  23),  INT8_C(  93), -INT8_C(  33),  INT8_C(  78), -INT8_C(  48), -INT8_C(  30),  INT8_C(  75) },
      { -INT8_C(  37), -INT8_C(  52), -INT8_C(  84),  INT8_C( 110), -INT8_C(  15), -INT8_C(  31), -INT8_C(  23), -INT8_C(  34),
        -INT8_C( 103), -INT8_C(  38),  INT8_C(  65),  INT8_C(  33), -INT8_C(  16), -INT8_C(  52),  INT8_C(  35),  INT8_C( 109) },
      {  INT8_C(   0),  INT8_C(   0), -INT8_C(  95),  INT8_C( 123), -INT8_C(  67),  INT8_C(   0),  INT8_C(  43),  INT8_C(   0),
        -INT8_C(  51),  INT8_C(   0), -INT8_C(  98),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   5),  INT8_C(   0) } },
    { UINT16_C(50023),
      { -INT8_C(  40),  INT8_C(  67), -INT8_C(  16),  INT8_C(  53),  INT8_C(  73), -INT8_C(  64), -INT8_C(  41),  INT8_C( 124),
         INT8_C(  97), -INT8_C( 126),  INT8_C(  77), -INT8_C(  78), -INT8_C(  92), -INT8_C( 116),  INT8_C(  16), -INT8_C( 126) },
      {  INT8_C(  76), -INT8_C( 111),      INT8_MIN, -INT8_C(  99), -INT8_C(  91),  INT8_C( 102),  INT8_C(  51), -INT8_C(  30),
         INT8_C(  45), -INT8_C(  47),  INT8_C(  25),  INT8_C(  16),  INT8_C( 104), -INT8_C(  95), -INT8_C( 111),  INT8_C(  93) },
      {  INT8_C(  36), -INT8_C(  44),  INT8_C( 112),  INT8_C(   0),  INT8_C(   0),  INT8_C(  38),  INT8_C(  10),  INT8_C(   0),
        -INT8_C( 114),  INT8_C(  83),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  95), -INT8_C(  33) } },
    { UINT16_C( 6986),
      {  INT8_C( 119), -INT8_C(  75), -INT8_C( 115),  INT8_C( 108), -INT8_C(  41), -INT8_C(  83),  INT8_C(  24),  INT8_C( 118),
         INT8_C( 117),  INT8_C(  98), -INT8_C(  80),  INT8_C( 105), -INT8_C(  62), -INT8_C( 104), -INT8_C(  75),  INT8_C(  22) },
      {      INT8_MAX,  INT8_C( 109), -INT8_C(  49),  INT8_C( 103), -INT8_C(  97), -INT8_C(  46), -INT8_C(  64),  INT8_C(  44),
        -INT8_C( 126), -INT8_C( 107), -INT8_C(  14),  INT8_C(   2), -INT8_C(  58),  INT8_C(  69), -INT8_C(  19), -INT8_C(  91) },
      {  INT8_C(   0),  INT8_C(  34),  INT8_C(   0), -INT8_C(  45),  INT8_C(   0),  INT8_C(   0), -INT8_C(  40),  INT8_C(   0),
        -INT8_C(   9), -INT8_C(   9),  INT8_C(   0),  INT8_C( 107), -INT8_C( 120),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0) } },
    { UINT16_C(36448),
      { -INT8_C(   7),  INT8_C( 119),  INT8_C( 107),  INT8_C(  82),  INT8_C( 101),  INT8_C(  83), -INT8_C(  83),  INT8_C( 116),
         INT8_C(  14),  INT8_C(  72),  INT8_C( 114),  INT8_C(   3), -INT8_C(  28), -INT8_C(   7),  INT8_C( 124), -INT8_C(  77) },
      { -INT8_C(  10), -INT8_C( 106),  INT8_C(  24),  INT8_C( 124), -INT8_C(  82), -INT8_C(  56), -INT8_C(  50),  INT8_C( 105),
         INT8_C(  61), -INT8_C( 116),  INT8_C(  93),  INT8_C(   9),  INT8_C(  50),  INT8_C(  96),  INT8_C(  92),  INT8_C(   3) },
      {  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(  27),  INT8_C( 123),  INT8_C(   0),
         INT8_C(   0), -INT8_C(  44), -INT8_C(  49),  INT8_C(  12),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  74) } },
    { UINT16_C(37475),
      {  INT8_C(  88),  INT8_C(   7), -INT8_C(  30),  INT8_C(  23),  INT8_C(  11), -INT8_C(  12),  INT8_C(  22), -INT8_C( 112),
         INT8_C(   7),  INT8_C( 103), -INT8_C(  62),  INT8_C(  79),  INT8_C(  13), -INT8_C(   6),  INT8_C(   3),  INT8_C( 110) },
      { -INT8_C( 109),  INT8_C(  83), -INT8_C( 125), -INT8_C(  26), -INT8_C(  64),  INT8_C( 118), -INT8_C( 108),  INT8_C( 120),
         INT8_C(  65),  INT8_C(  56),  INT8_C( 108), -INT8_C(  19), -INT8_C(  92), -INT8_C(  43),  INT8_C(  59), -INT8_C(  82) },
      { -INT8_C(  21),  INT8_C(  90),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C( 106), -INT8_C(  86),  INT8_C(   0),
         INT8_C(   0), -INT8_C(  97),  INT8_C(   0),  INT8_C(   0), -INT8_C(  79),  INT8_C(   0),  INT8_C(   0),  INT8_C(  28) } },
    { UINT16_C(60868),
      { -INT8_C(  85),  INT8_C(  98), -INT8_C( 119),  INT8_C(  28), -INT8_C(  52),  INT8_C(  36), -INT8_C(  38),  INT8_C(  97),
        -INT8_C(  23),  INT8_C(  33),  INT8_C( 101),  INT8_C(  30), -INT8_C(  56),  INT8_C(  67), -INT8_C(  69), -INT8_C(  85) },
      { -INT8_C(  92),  INT8_C(  56),  INT8_C(   8),  INT8_C( 111),  INT8_C(  68), -INT8_C(  19), -INT8_C(  66),  INT8_C(  42),
         INT8_C(   1),  INT8_C(  32),  INT8_C( 112),  INT8_C(  10),  INT8_C(  11),  INT8_C( 114),  INT8_C( 126), -INT8_C( 127) },
      {  INT8_C(   0),  INT8_C(   0), -INT8_C( 111),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C( 104), -INT8_C( 117),
        -INT8_C(  22),  INT8_C(   0), -INT8_C(  43),  INT8_C(  40),  INT8_C(   0), -INT8_C(  75),  INT8_C(  57),  INT8_C(  44) } },
    { UINT16_C(25877),
      {  INT8_C(  40), -INT8_C(  65),  INT8_C(  46), -INT8_C(  42), -INT8_C(  23),  INT8_C( 101),  INT8_C(  37),  INT8_C(  87),
         INT8_C( 109), -INT8_C(  69),  INT8_C(  80), -INT8_C(  44), -INT8_C(  53),  INT8_C(  53),  INT8_C(  52),  INT8_C( 114) },
      { -INT8_C( 100),  INT8_C(   3), -INT8_C(  25), -INT8_C(  36), -INT8_C(  90), -INT8_C(  81), -INT8_C( 115), -INT8_C( 101),
         INT8_C(  18),  INT8_C( 125), -INT8_C(  12),  INT8_C( 115), -INT8_C(  22), -INT8_C(   9),  INT8_C( 117),  INT8_C(  27) },
      { -INT8_C(  60),  INT8_C(   0),  INT8_C(  21),  INT8_C(   0), -INT8_C( 113),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
             INT8_MAX,  INT8_C(   0),  INT8_C(  68),  INT8_C(   0),  INT8_C(   0),  INT8_C(  44), -INT8_C(  87),  INT8_C(   0) } },
    { UINT16_C( 8536),
      { -INT8_C(  44), -INT8_C(  95), -INT8_C(  28), -INT8_C(  36), -INT8_C( 103), -INT8_C(   7),  INT8_C(  72),  INT8_C(  25),
        -INT8_C( 117), -INT8_C( 114), -INT8_C(  95),  INT8_C(  17),  INT8_C(   7),  INT8_C(   1), -INT8_C(  44), -INT8_C(  70) },
      { -INT8_C(  68), -INT8_C(   8),  INT8_C(  12),  INT8_C(  65),  INT8_C( 102),  INT8_C(  62), -INT8_C(  99),  INT8_C( 118),
         INT8_C(   8), -INT8_C(  26),  INT8_C(  94),  INT8_C(  54),  INT8_C(   0), -INT8_C(  68),      INT8_MAX, -INT8_C( 126) },
      {  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(  29), -INT8_C(   1),  INT8_C(   0), -INT8_C(  27),  INT8_C(   0),
        -INT8_C( 109),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  67),  INT8_C(   0),  INT8_C(   0) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_x_mm_loadu_epi8(test_vec[i].a);
    simde__m128i b = simde_x_mm_loadu_epi8(test_vec[i].b);
    simde__m128i r = simde_mm_maskz_add_epi8(test_vec[i].k, a, b);
    simde_test_x86_assert_equal_i8x16(r, simde_x_mm_loadu_epi8(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_mm_mask_add_epi16 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const int16_t src[8];
    const simde__mmask8 k;
    const int16_t a[8];
    const int16_t b[8];
    const int16_t r[8];
  } test_vec[] = {
    { {  INT16_C( 17817), -INT16_C(  2243), -INT16_C( 28883), -INT16_C(  7874),  INT16_C(   338), -INT16_C( 12748), -INT16_C(  9412),  INT16_C(   228) },
      UINT8_C( 66),
      { -INT16_C( 13625), -INT16_C(   511), -INT16_C(  9176), -INT16_C( 32360), -INT16_C( 18674), -INT16_C( 29571), -INT16_C( 32208),  INT16_C(  4749) },
      { -INT16_C( 26006), -INT16_C( 12496),  INT16_C( 20326), -INT16_C(   234), -INT16_C( 21928), -INT16_C(  3464), -INT16_C( 18163), -INT16_C(  1715) },
      {  INT16_C( 17817), -INT16_C( 13007), -INT16_C( 28883), -INT16_C(  7874),  INT16_C(   338), -INT16_C( 12748),  INT16_C( 15165),  INT16_C(   228) } },
    { { -INT16_C( 31056), -INT16_C( 22914),  INT16_C( 26105), -INT16_C( 10738),  INT16_C(   397),  INT16_C( 25565), -INT16_C( 22215), -INT16_C( 22166) },
      UINT8_C( 95),
      { -INT16_C( 29933), -INT16_C(  7224),  INT16_C( 20985),  INT16_C(  6509), -INT16_C( 25426), -INT16_C( 14506), -INT16_C( 26474), -INT16_C( 16323) },
      { -INT16_C( 17906),  INT16_C(  4756), -INT16_C( 20982),  INT16_C(  9519), -INT16_C( 15356), -INT16_C( 11051),  INT16_C( 26863), -INT16_C( 25274) },
      {  INT16_C( 17697), -INT16_C(  2468),  INT16_C(     3),  INT16_C( 16028),  INT16_C( 24754),  INT16_C( 25565),  INT16_C(   389), -INT16_C( 22166) } },
    { { -INT16_C(  4880),  INT16_C(  8735),  INT16_C(  8130),  INT16_C( 26938), -INT16_C(  8020), -INT16_C( 31347),  INT16_C(  8055),  INT16_C(  9966) },
      UINT8_C(190),
      {  INT16_C(  1808),  INT16_C( 20344),  INT16_C(  2923), -INT16_C( 23307), -INT16_C( 27990), -INT16_C(  8377), -INT16_C( 32088), -INT16_C( 20615) },
      {  INT16_C( 25028), -INT16_C( 30164),  INT16_C( 13304),  INT16_C( 19564), -INT16_C( 24947),  INT16_C(  1894), -INT16_C(  6448), -INT16_C( 24485) },
      { -INT16_C(  4880), -INT16_C(  9820),  INT16_C( 16227), -INT16_C(  3743),  INT16_C( 12599), -INT16_C(  6483),  INT16_C(  8055),  INT16_C( 20436) } },
    { {  INT16_C( 13221), -INT16_C( 19991),  INT16_C( 21448),  INT16_C(  9585),  INT16_C( 18335),  INT16_C( 18834),  INT16_C( 31996), -INT16_C(  1809) },
      UINT8_C(131),
      {  INT16_C(  1798),  INT16_C( 26660), -INT16_C( 21916), -INT16_C( 14369),  INT16_C( 18610),  INT16_C( 19226), -INT16_C( 32140),  INT16_C(  6089) },
      { -INT16_C( 10658),  INT16_C( 26610),  INT16_C(  5435),  INT16_C( 22284),  INT16_C(  1294),  INT16_C( 25864),  INT16_C( 31360),  INT16_C( 29206) },
      { -INT16_C(  8860), -INT16_C( 12266),  INT16_C( 21448),  INT16_C(  9585),  INT16_C( 18335),  INT16_C( 18834),  INT16_C( 31996), -INT16_C( 30241) } },
    { {  INT16_C(  3819),  INT16_C(  7886), -INT16_C(  2308), -INT16_C( 23812), -INT16_C(    53),  INT16_C(  7661), -INT16_C(  6086), -INT16_C( 20132) },
      UINT8_C(126),
      {  INT16_C(  1025), -INT16_C(  1747),  INT16_C( 13483),  INT16_C( 15025),  INT16_C( 17328), -INT16_C( 14874),  INT16_C(  6565),  INT16_C( 14071) },
      { -INT16_C( 12931), -INT16_C( 25527), -INT16_C( 11161),  INT16_C( 18125), -INT16_C(  1194), -INT16_C( 29538), -INT16_C(  3219), -INT16_C( 14390) },
      {  INT16_C(  3819), -INT16_C( 27274),  INT16_C(  2322), -INT16_C( 32386),  INT16_C( 16134),  INT16_C( 21124),  INT16_C(  3346), -INT16_C( 20132) } },
    { {  INT16_C( 22971), -INT16_C( 32214), -INT16_C( 27903),  INT16_C( 14508),  INT16_C( 16600), -INT16_C( 22707), -INT16_C(  5461), -INT16_C( 11019) },
      UINT8_C( 35),
      {  INT16_C( 16262), -INT16_C( 24435),  INT16_C( 14751),  INT16_C( 27015), -INT16_C( 24225), -INT16_C(   541), -INT16_C(  9613),  INT16_C(  4216) },
      { -INT16_C(  1057),  INT16_C( 24640),  INT16_C( 27675),  INT16_C( 25767),  INT16_C(  8263),  INT16_C( 28018), -INT16_C( 30242),  INT16_C(  6202) },
      {  INT16_C( 15205),  INT16_C(   205), -INT16_C( 27903),  INT16_C( 14508),  INT16_C( 16600),  INT16_C( 27477), -INT16_C(  5461), -INT16_C( 11019) } },
    { {  INT16_C(  9473), -INT16_C( 12490),  INT16_C( 26373), -INT16_C( 31879), -INT16_C( 12795),  INT16_C( 27285),  INT16_C( 20597), -INT16_C(  2226) },
      UINT8_C( 62),
      { -INT16_C(  1230), -INT16_C( 11593),  INT16_C( 18697), -INT16_C(  8764), -INT16_C(  7130),  INT16_C( 25580), -INT16_C(  4090), -INT16_C( 25505) },
      {  INT16_C( 19431), -INT16_C( 14954), -INT16_C( 27621),  INT16_C( 15919), -INT16_C( 16076), -INT16_C( 32362), -INT16_C( 25322),  INT16_C( 25848) },
      {  INT16_C(  9473), -INT16_C( 26547), -INT16_C(  8924),  INT16_C(  7155), -INT16_C( 23206), -INT16_C(  6782),  INT16_C( 20597), -INT16_C(  2226) } },
    { { -INT16_C( 16798), -INT16_C( 16061),  INT16_C( 28632),  INT16_C( 12716),  INT16_C( 10145),  INT16_C( 23704),  INT16_C( 13844), -INT16_C(  1453) },
      UINT8_C( 10),
      {  INT16_C(  4456),  INT16_C(  1455), -INT16_C( 11882), -INT16_C( 21010), -INT16_C( 14517),  INT16_C(  9453),  INT16_C( 19422),  INT16_C( 22787) },
      {  INT16_C(  9815), -INT16_C(  4177), -INT16_C( 17752),  INT16_C(  8643), -INT16_C( 14132), -INT16_C( 28981),  INT16_C(  3734), -INT16_C(  2203) },
      { -INT16_C( 16798), -INT16_C(  2722),  INT16_C( 28632), -INT16_C( 12367),  INT16_C( 10145),  INT16_C( 23704),  INT16_C( 13844), -INT16_C(  1453) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i src = simde_x_mm_loadu_epi16(test_vec[i].src);
    simde__m128i a = simde_x_mm_loadu_epi16(test_vec[i].a);
    simde__m128i b = simde_x_mm_loadu_epi16(test_vec[i].b);
    simde__m128i r = simde_mm_mask_add_epi16(src, test_vec[i].k, a, b);
    simde_test_x86_assert_equal_i16x8(r, simde_x_mm_loadu_epi16(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_mm_maskz_add_epi16 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const simde__mmask8 k;
    const int16_t a[8];
    const int16_t b[8];
    const int16_t r[8];
  } test_vec[] = {
    { UINT8_C(134),
      {  INT16_C( 12554), -INT16_C( 17057), -INT16_C( 28311), -INT16_C( 28428), -INT16_C( 15318), -INT16_C( 10100), -INT16_C( 18852), -INT16_C( 16229) },
      { -INT16_C( 31990),  INT16_C( 29908),  INT16_C( 15111), -INT16_C(  4862),  INT16_C( 23252), -INT16_C( 12060), -INT16_C( 25385), -INT16_C( 12982) },
      {  INT16_C(     0),  INT16_C( 12851), -INT16_C( 13200),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C( 29211) } },
    { UINT8_C(157),
      {  INT16_C(  1408),  INT16_C( 17385), -INT16_C( 25707), -INT16_C(  3037),  INT16_C(  2190), -INT16_C( 16188),  INT16_C(  9347), -INT16_C(  7492) },
      { -INT16_C( 31565),  INT16_C( 13950), -INT16_C( 23827),  INT16_C(  2179),  INT16_C(  5735),  INT16_C(  2100), -INT16_C( 26139), -INT16_C(  8740) },
      { -INT16_C( 30157),  INT16_C(     0),  INT16_C( 16002), -INT16_C(   858),  INT16_C(  7925),  INT16_C(     0),  INT16_C(     0), -INT16_C( 16232) } },
    { UINT8_C( 24),
      { -INT16_C( 18498), -INT16_C( 16851), -INT16_C(  8942),  INT16_C( 29587), -INT16_C( 30777), -INT16_C( 18973), -INT16_C( 17141),  INT16_C( 22434) },
      { -INT16_C(  7638),  INT16_C(   677), -INT16_C( 15883),  INT16_C( 16066),  INT16_C( 29995), -INT16_C( 27669),  INT16_C(  7858), -INT16_C( 16674) },
      {  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C( 19883), -INT16_C(   782),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
    { UINT8_C(157),
      { -INT16_C( 30517), -INT16_C(  8546),  INT16_C( 22395),  INT16_C( 25788), -INT16_C(  9860),  INT16_C( 13172),  INT16_C( 13481),  INT16_C(  7362) },
      {  INT16_C( 20929), -INT16_C(    87), -INT16_C( 17569), -INT16_C( 31496),  INT16_C( 15928), -INT16_C(  7297),  INT16_C( 24667),  INT16_C( 21390) },
      { -INT16_C(  9588),  INT16_C(     0),  INT16_C(  4826), -INT16_C(  5708),  INT16_C(  6068),  INT16_C(     0),  INT16_C(     0),  INT16_C( 28752) } },
    { UINT8_C(204),
      { -INT16_C(  7807), -INT16_C( 18593),  INT16_C(  5789),  INT16_C( 10188), -INT16_C(   320), -INT16_C( 16671), -INT16_C( 20439), -INT16_C( 18566) },
      { -INT16_C( 19073), -INT16_C( 12901),  INT16_C( 26791),  INT16_C( 16857), -INT16_C( 21045), -INT16_C(  9971),  INT16_C(  2843),  INT16_C( 25436) },
      {  INT16_C(     0),  INT16_C(     0),  INT16_C( 32580),  INT16_C( 27045),  INT16_C(     0),  INT16_C(     0), -INT16_C( 17596),  INT16_C(  6870) } },
    { UINT8_C(237),
      { -INT16_C( 16461), -INT16_C(  6930),  INT16_C( 16169), -INT16_C( 32323),  INT16_C(  2552),  INT16_C(  1679), -INT16_C( 26974),  INT16_C( 14036) },
      {  INT16_C(  2376), -INT16_C( 18722),  INT16_C(  3134),  INT16_C( 10788),  INT16_C(  9045),  INT16_C( 14703),  INT16_C( 12911),  INT16_C( 27034) },
      { -INT16_C( 14085),  INT16_C(     0),  INT16_C( 19303), -INT16_C( 21535),  INT16_C(     0),  INT16_C( 16382), -INT16_C( 14063), -INT16_C( 24466) } },
    { UINT8_C( 42),
      {  INT16_C( 26325),  INT16_C(  6988),  INT16_C( 23545), -INT16_C( 22647),  INT16_C( 31625), -INT16_C(  3414),  INT16_C( 10045), -INT16_C( 17949) },
      {  INT16_C(  1997), -INT16_C( 13645), -INT16_C(  8378),  INT16_C( 19517),  INT16_C( 12495), -INT16_C( 25023),  INT16_C( 24234), -INT16_C( 25731) },
      {  INT16_C(     0), -INT16_C(  6657),  INT16_C(     0), -INT16_C(  3130),  INT16_C(     0), -INT16_C( 28437),  INT16_C(     0),  INT16_C(     0) } },
    { UINT8_C(211),
      {  INT16_C( 12889),  INT16_C( 28312),  INT16_C( 22010),  INT16_C(  4663), -INT16_C( 15800), -INT16_C( 32484), -INT16_C( 11389),  INT16_C( 13519) },
      {  INT16_C( 15116), -INT16_C( 28247),  INT16_C(   679),  INT16_C( 25752), -INT16_C( 15591),  INT16_C( 22603), -INT16_C( 32111), -INT16_C( 14859) },
      {  INT16_C( 28005),  INT16_C(    65),  INT16_C(     0),  INT16_C(     0), -INT16_C( 31391),  INT16_C(     0),  INT16_C( 22036), -INT16_C(  1340) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_x_mm_loadu_epi16(test_vec[i].a);
    simde__m128i b = simde_x_mm_loadu_epi16(test_vec[i].b);
    simde__m128i r = simde_mm_maskz_add_epi16(test_vec[i].k, a, b);
    simde_test_x86_assert_equal_i16x8(r, simde_x_mm_loadu_epi16(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_mm_mask_add_epi32 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const int32_t src[4];
    const simde__mmask8 k;
    const int32_t a[4];
    const int32_t b[4];
    const int32_t r[4];
  } test_vec[] = {
    { {  INT32_C(  1958227227),  INT32_C(  1842333829), -INT32_C(  2080453323), -INT32_C(   249177196) },
      UINT8_C(155),
      {  INT32_C(   553106004), -INT32_C(  1372587746), -INT32_C(  1712075801),  INT32_C(   993452127) },
      {  INT32_C(   777515607), -INT32_C(   712684129),  INT32_C(   223497663), -INT32_C(   489447286) },
      {  INT32_C(  1330621611), -INT32_C(  2085271875), -INT32_C(  2080453323),  INT32_C(   504004841) } },
    { {  INT32_C(   697251714), -INT32_C(   951749739),  INT32_C(   836834350), -INT32_C(   346279314) },
      UINT8_C(111),
      { -INT32_C(   885142141), -INT32_C(   194598295), -INT32_C(  1261452693),  INT32_C(   375114831) },
      {  INT32_C(  1479180836), -INT32_C(  1604991616), -INT32_C(  1780092987),  INT32_C(   634429248) },
      {  INT32_C(   594038695), -INT32_C(  1799589911),  INT32_C(  1253421616),  INT32_C(  1009544079) } },
    { {  INT32_C(  1249061656),  INT32_C(   406248213),  INT32_C(  1546568796),  INT32_C(   345790387) },
      UINT8_C(173),
      {  INT32_C(  1116067984), -INT32_C(   306617666),  INT32_C(  1471337118),  INT32_C(  1742516687) },
      {  INT32_C(  1421198449),  INT32_C(  1861843318), -INT32_C(  2139880994),  INT32_C(   418138440) },
      { -INT32_C(  1757700863),  INT32_C(   406248213), -INT32_C(   668543876), -INT32_C(  2134312169) } },
    { { -INT32_C(   455875920), -INT32_C(  1805739296), -INT32_C(   834127167), -INT32_C(   193385963) },
      UINT8_C(243),
      {  INT32_C(   397937177),  INT32_C(   447724867), -INT32_C(  1604479719), -INT32_C(  1556316088) },
      {  INT32_C(   764118341),  INT32_C(    33168795), -INT32_C(   931609255),  INT32_C(  2093992876) },
      {  INT32_C(  1162055518),  INT32_C(   480893662), -INT32_C(   834127167), -INT32_C(   193385963) } },
    { {  INT32_C(   227843937), -INT32_C(  1816959923),  INT32_C(   110120824), -INT32_C(  1826017770) },
      UINT8_C(242),
      {  INT32_C(   598721326), -INT32_C(  1962044123), -INT32_C(  1919813583), -INT32_C(  1281349718) },
      { -INT32_C(  1464369420),  INT32_C(  1889351967), -INT32_C(   174840084), -INT32_C(  1849263339) },
      {  INT32_C(   227843937), -INT32_C(    72692156),  INT32_C(   110120824), -INT32_C(  1826017770) } },
    { {  INT32_C(   585486166), -INT32_C(  1881648464), -INT32_C(  1741597697),  INT32_C(  1501172127) },
      UINT8_C(177),
      { -INT32_C(  2072152845),  INT32_C(  1678312837),  INT32_C(   175231240),  INT32_C(   639313595) },
      {  INT32_C(  1844718395),  INT32_C(  1747844119), -INT32_C(  1642309052), -INT32_C(  1463847021) },
      { -INT32_C(   227434450), -INT32_C(  1881648464), -INT32_C(  1741597697),  INT32_C(  1501172127) } },
    { {  INT32_C(  1282734968), -INT32_C(  1805890056), -INT32_C(   170454139),  INT32_C(   939566096) },
      UINT8_C(  1),
      {  INT32_C(   373441333),  INT32_C(  1967739279),  INT32_C(   363886263), -INT32_C(  1478106109) },
      { -INT32_C(  1988739640),  INT32_C(   299055662),  INT32_C(   830616967),  INT32_C(   503576578) },
      { -INT32_C(  1615298307), -INT32_C(  1805890056), -INT32_C(   170454139),  INT32_C(   939566096) } },
    { {  INT32_C(  1100203671), -INT32_C(   234656697), -INT32_C(  2035991414),  INT32_C(  1938166869) },
      UINT8_C( 44),
      { -INT32_C(    77918946), -INT32_C(   927432354), -INT32_C(  2008458249),  INT32_C(  1379220591) },
      { -INT32_C(   261431271), -INT32_C(  1794574077),  INT32_C(  1874265007),  INT32_C(   695196668) },
      {  INT32_C(  1100203671), -INT32_C(   234656697), -INT32_C(   134193242),  INT32_C(  2074417259) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i src = simde_x_mm_loadu_epi32(test_vec[i].src);
    simde__m128i a = simde_x_mm_loadu_epi32(test_vec[i].a);
    simde__m128i b = simde_x_mm_loadu_epi32(test_vec[i].b);
    simde__m128i r = simde_mm_mask_add_epi32(src, test_vec[i].k, a, b);
    simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_mm_maskz_add_epi32 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const simde__mmask8 k;
    const int32_t a[4];
    const int32_t b[4];
    const int32_t r[4];
  } test_vec[] = {
    { UINT8_C( 26),
      {  INT32_C(  1100397714),  INT32_C(  1720147146),  INT32_C(   782659498),  INT32_C(   164614002) },
      {  INT32_C(  1362429759), -INT32_C(   135924898),  INT32_C(  1277782591),  INT32_C(  1455600660) },
      {  INT32_C(           0),  INT32_C(  1584222248),  INT32_C(           0),  INT32_C(  1620214662) } },
    { UINT8_C(104),
      { -INT32_C(   511491329),  INT32_C(  2145361873), -INT32_C(   681927889), -INT32_C(  1760116045) },
      { -INT32_C(  1818488330), -INT32_C(  1227468567), -INT32_C(   914908373), -INT32_C(   761443622) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(  1773407629) } },
    { UINT8_C( 38),
      { -INT32_C(  1756543294), -INT32_C(  1924529315),  INT32_C(   753287628),  INT32_C(   821606796) },
      {  INT32_C(  1995981071),  INT32_C(  1941095443), -INT32_C(   997134313),  INT32_C(  1414962996) },
      {  INT32_C(           0),  INT32_C(    16566128), -INT32_C(   243846685),  INT32_C(           0) } },
    { UINT8_C( 11),
      {  INT32_C(  1936642854),  INT32_C(  1476527496), -INT32_C(  1916837668),  INT32_C(  1565927957) },
      {  INT32_C(   819891483),  INT32_C(    24098982),  INT32_C(  1427042923),  INT32_C(   967231402) },
      { -INT32_C(  1538432959),  INT32_C(  1500626478),  INT32_C(           0), -INT32_C(  1761807937) } },
    { UINT8_C(136),
      {  INT32_C(  2025931821), -INT32_C(  1602308853), -INT32_C(  1584066603),  INT32_C(  2144498786) },
      { -INT32_C(    32030623), -INT32_C(   522392968),  INT32_C(  2136840774),  INT32_C(   707776301) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(  1442692209) } },
    { UINT8_C( 16),
      {  INT32_C(   615979771),  INT32_C(    91372444), -INT32_C(  1715689431),  INT32_C(  1732560282) },
      {  INT32_C(  1582515072), -INT32_C(   566478811), -INT32_C(  1915644371), -INT32_C(   936530095) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
    { UINT8_C(152),
      { -INT32_C(  1815019322),  INT32_C(  2115824139), -INT32_C(   541094950), -INT32_C(   308634405) },
      { -INT32_C(   923734690),  INT32_C(   926178071),  INT32_C(  1920079652), -INT32_C(  1332173880) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(  1640808285) } },
    { UINT8_C( 27),
      {  INT32_C(  1575440202),  INT32_C(  1941889206),  INT32_C(    41623433), -INT32_C(    28396641) },
      {  INT32_C(     7451246), -INT32_C(  1374405146),  INT32_C(  1597383244), -INT32_C(  1478059980) },
      {  INT32_C(  1582891448),  INT32_C(   567484060),  INT32_C(           0), -INT32_C(  1506456621) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_x_mm_loadu_epi32(test_vec[i].a);
    simde__m128i b = simde_x_mm_loadu_epi32(test_vec[i].b);
    simde__m128i r = simde_mm_maskz_add_epi32(test_vec[i].k, a, b);
    simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_mm_mask_add_epi64 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const int64_t src[2];
    const simde__mmask8 k;
    const int64_t a[2];
    const int64_t b[2];
    const int64_t r[2];
  } test_vec[] = {
    { {  INT64_C( 8201918233897001447),  INT64_C(  363962166077692400) },
      UINT8_C(116),
      { -INT64_C( 2929372668825588728), -INT64_C( 3656510824753645306) },
      {  INT64_C( 2121463196383157106), -INT64_C( 2712448646012699723) },
      {  INT64_C( 8201918233897001447),  INT64_C(  363962166077692400) } },
    { { -INT64_C( 7660056023431247569), -INT64_C( 8800573589908441802) },
      UINT8_C( 26),
      { -INT64_C( 5155283151088348406), -INT64_C( 6777794566593036429) },
      {  INT64_C( 8217194832092526134), -INT64_C( 6988787196078811595) },
      { -INT64_C( 7660056023431247569),  INT64_C( 4680162311037703592) } },
    { { -INT64_C( 5177610656632927949), -INT64_C( 7835688890176823491) },
      UINT8_C( 38),
      {  INT64_C( 8694329990162064366), -INT64_C( 7553465337537219517) },
      {  INT64_C( 5861342603890327684),  INT64_C( 8969888432361565647) },
      { -INT64_C( 5177610656632927949),  INT64_C( 1416423094824346130) } },
    { {  INT64_C( 1563207507706856527), -INT64_C(  371485882345723171) },
      UINT8_C(246),
      { -INT64_C( 8155582183645986764), -INT64_C( 8042754456252808652) },
      { -INT64_C(  996858152082936078),  INT64_C(  999238294551887019) },
      {  INT64_C( 1563207507706856527), -INT64_C( 7043516161700921633) } },
    { {  INT64_C( 2269651972621910057),  INT64_C( 8122205111827084555) },
      UINT8_C(109),
      {  INT64_C( 5898016879431101179),  INT64_C( 8196109586946188276) },
      { -INT64_C( 3927996688380496977), -INT64_C( 8700540345223695011) },
      {  INT64_C( 1970020191050604202),  INT64_C( 8122205111827084555) } },
    { {  INT64_C( 8953512102049709771),  INT64_C( 4073568780934150804) },
      UINT8_C( 55),
      { -INT64_C( 8698567697690688449),  INT64_C( 2011128588034496860) },
      {  INT64_C( 4050759086289972052), -INT64_C( 4209687100771601707) },
      { -INT64_C( 4647808611400716397), -INT64_C( 2198558512737104847) } },
    { { -INT64_C( 2003310644913083277),  INT64_C( 3614518035412058723) },
      UINT8_C(247),
      {  INT64_C( 1202266463040515144),  INT64_C( 2203879785493297747) },
      { -INT64_C( 6903979043742968285),  INT64_C(  286701945599558971) },
      { -INT64_C( 5701712580702453141),  INT64_C( 2490581731092856718) } },
    { {  INT64_C( 9179970759417586743), -INT64_C(  419587667919506800) },
      UINT8_C( 88),
      { -INT64_C( 5871315755711329534), -INT64_C( 2058360122490679194) },
      {  INT64_C( 1804735659384354964),  INT64_C( 3266572330366650128) },
      {  INT64_C( 9179970759417586743), -INT64_C(  419587667919506800) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i src = simde_x_mm_loadu_epi64(test_vec[i].src);
    simde__m128i a = simde_x_mm_loadu_epi64(test_vec[i].a);
    simde__m128i b = simde_x_mm_loadu_epi64(test_vec[i].b);
    simde__m128i r = simde_mm_mask_add_epi64(src, test_vec[i].k, a, b);
    simde_test_x86_assert_equal_i64x2(r, simde_x_mm_loadu_epi64(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_mm_maskz_add_epi64 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const simde__mmask8 k;
    const int64_t a[2];
    const int64_t b[2];
    const int64_t r[2];
  } test_vec[] = {
    { UINT8_C(150),
      { -INT64_C(  993872781162934343),  INT64_C( 9134756112190127784) },
      { -INT64_C( 2891573308549781280), -INT64_C( 9143568260559188007) },
      {  INT64_C(                   0), -INT64_C(    8812148369060223) } },
    { UINT8_C(196),
      {  INT64_C( 6550556420904536135),  INT64_C( 8490360445651406694) },
      { -INT64_C( 1739704569367854626),  INT64_C( 4245131661435093091) },
      {  INT64_C(                   0),  INT64_C(                   0) } },
    { UINT8_C( 52),
      { -INT64_C( 2760535867334763843),  INT64_C( 7115030050339329677) },
      {  INT64_C( 7188684116250616331), -INT64_C( 2471133335336396754) },
      {  INT64_C(                   0),  INT64_C(                   0) } },
    { UINT8_C(  5),
      {  INT64_C( 3814106451400715087),  INT64_C( 6178810664702908734) },
      {  INT64_C( 1820139726703884269), -INT64_C( 2876452185216044984) },
      {  INT64_C( 5634246178104599356),  INT64_C(                   0) } },
    { UINT8_C( 77),
      { -INT64_C( 7349641843913850521),  INT64_C( 3200744105211371253) },
      {  INT64_C(  228621185812703474),  INT64_C( 6391631982896984822) },
      { -INT64_C( 7121020658101147047),  INT64_C(                   0) } },
    { UINT8_C(254),
      {  INT64_C( 5885620942751936373),  INT64_C( 3334511588433406542) },
      { -INT64_C(  254487071634799123),  INT64_C( 3127732574282601076) },
      {  INT64_C(                   0),  INT64_C( 6462244162716007618) } },
    { UINT8_C(174),
      { -INT64_C( 2725183470148505474),  INT64_C( 8524564968923083055) },
      {  INT64_C( 3417677596325229905), -INT64_C( 1448789787674024211) },
      {  INT64_C(                   0),  INT64_C( 7075775181249058844) } },
    { UINT8_C( 60),
      {  INT64_C( 5475088381666832271),  INT64_C( 2253690732183149705) },
      {  INT64_C( 9160715340915633356), -INT64_C( 3092667301170657521) },
      {  INT64_C(                   0),  INT64_C(                   0) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_x_mm_loadu_epi64(test_vec[i].a);
    simde__m128i b = simde_x_mm_loadu_epi64(test_vec[i].b);
    simde__m128i r = simde_mm_maskz_add_epi64(test_vec[i].k, a, b);
    simde_test_x86_assert_equal_i64x2(r, simde_x_mm_loadu_epi64(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_mm_mask_add_ss (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde_float32 src[4];
    const simde__mmask8 k;
    const simde_float32 a[4];
    const simde_float32 b[4];
    const simde_float32 r[4];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(  -362.02), SIMDE_FLOAT32_C(  -753.03), SIMDE_FLOAT32_C(   336.60), SIMDE_FLOAT32_C(   433.83) },
      UINT8_C(125),
      { SIMDE_FLOAT32_C(   392.81), SIMDE_FLOAT32_C(  -464.44), SIMDE_FLOAT32_C(  -422.67), SIMDE_FLOAT32_C(  -899.86) },
      { SIMDE_FLOAT32_C(  -403.90), SIMDE_FLOAT32_C(   536.42), SIMDE_FLOAT32_C(  -805.91), SIMDE_FLOAT32_C(   663.43) },
      { SIMDE_FLOAT32_C(   -11.09), SIMDE_FLOAT32_C(  -464.44), SIMDE_FLOAT32_C(  -422.67), SIMDE_FLOAT32_C(  -899.86) } },
    { { SIMDE_FLOAT32_C(  -478.45), SIMDE_FLOAT32_C(  -735.39), SIMDE_FLOAT32_C(  -353.05), SIMDE_FLOAT32_C(   917.77) },
      UINT8_C( 83),
      { SIMDE_FLOAT32_C(  -443.57), SIMDE_FLOAT32_C(   820.62), SIMDE_FLOAT32_C(   677.29), SIMDE_FLOAT32_C(    81.36) },
      { SIMDE_FLOAT32_C(   246.07), SIMDE_FLOAT32_C(   669.97), SIMDE_FLOAT32_C(   862.97), SIMDE_FLOAT32_C(   545.49) },
      { SIMDE_FLOAT32_C(  -197.50), SIMDE_FLOAT32_C(   820.62), SIMDE_FLOAT32_C(   677.29), SIMDE_FLOAT32_C(    81.36) } },
    { { SIMDE_FLOAT32_C(   289.66), SIMDE_FLOAT32_C(   153.93), SIMDE_FLOAT32_C(  -971.51), SIMDE_FLOAT32_C(   876.28) },
      UINT8_C(104),
      { SIMDE_FLOAT32_C(  -333.53), SIMDE_FLOAT32_C(  -876.75), SIMDE_FLOAT32_C(  -699.81), SIMDE_FLOAT32_C(  -899.70) },
      { SIMDE_FLOAT32_C(  -343.74), SIMDE_FLOAT32_C(   692.99), SIMDE_FLOAT32_C(  -364.15), SIMDE_FLOAT32_C(   233.59) },
      { SIMDE_FLOAT32_C(   289.66), SIMDE_FLOAT32_C(  -876.75), SIMDE_FLOAT32_C(  -699.81), SIMDE_FLOAT32_C(  -899.70) } },
    { { SIMDE_FLOAT32_C(   793.13), SIMDE_FLOAT32_C(   231.95), SIMDE_FLOAT32_C(  -229.99), SIMDE_FLOAT32_C(   987.23) },
      UINT8_C(242),
      { SIMDE_FLOAT32_C(   291.56), SIMDE_FLOAT32_C(  -748.16), SIMDE_FLOAT32_C(   542.34), SIMDE_FLOAT32_C(   209.32) },
      { SIMDE_FLOAT32_C(   326.59), SIMDE_FLOAT32_C(  -901.23), SIMDE_FLOAT32_C(    29.95), SIMDE_FLOAT32_C(     3.89) },
      { SIMDE_FLOAT32_C(   793.13), SIMDE_FLOAT32_C(  -748.16), SIMDE_FLOAT32_C(   542.34), SIMDE_FLOAT32_C(   209.32) } },
    { { SIMDE_FLOAT32_C(   180.14), SIMDE_FLOAT32_C(  -723.98), SIMDE_FLOAT32_C(  -326.15), SIMDE_FLOAT32_C(    43.10) },
      UINT8_C(222),
      { SIMDE_FLOAT32_C(   963.51), SIMDE_FLOAT32_C(  -802.96), SIMDE_FLOAT32_C(   850.00), SIMDE_FLOAT32_C(   839.79) },
      { SIMDE_FLOAT32_C(   160.62), SIMDE_FLOAT32_C(  -483.52), SIMDE_FLOAT32_C(   963.04), SIMDE_FLOAT32_C(   460.80) },
      { SIMDE_FLOAT32_C(   180.14), SIMDE_FLOAT32_C(  -802.96), SIMDE_FLOAT32_C(   850.00), SIMDE_FLOAT32_C(   839.79) } },
    { { SIMDE_FLOAT32_C(  -383.22), SIMDE_FLOAT32_C(  -380.70), SIMDE_FLOAT32_C(   153.80), SIMDE_FLOAT32_C(   252.63) },
      UINT8_C( 59),
      { SIMDE_FLOAT32_C(   -53.07), SIMDE_FLOAT32_C(  -515.42), SIMDE_FLOAT32_C(  -377.10), SIMDE_FLOAT32_C(   -65.84) },
      { SIMDE_FLOAT32_C(   379.97), SIMDE_FLOAT32_C(   914.45), SIMDE_FLOAT32_C(   186.00), SIMDE_FLOAT32_C(   -77.69) },
      { SIMDE_FLOAT32_C(   326.90), SIMDE_FLOAT32_C(  -515.42), SIMDE_FLOAT32_C(  -377.10), SIMDE_FLOAT32_C(   -65.84) } },
    { { SIMDE_FLOAT32_C(   123.78), SIMDE_FLOAT32_C(  -487.41), SIMDE_FLOAT32_C(    21.08), SIMDE_FLOAT32_C(  -846.28) },
      UINT8_C(218),
      { SIMDE_FLOAT32_C(  -798.78), SIMDE_FLOAT32_C(  -570.26), SIMDE_FLOAT32_C(  -809.67), SIMDE_FLOAT32_C(   244.32) },
      { SIMDE_FLOAT32_C(  -748.74), SIMDE_FLOAT32_C(  -846.16), SIMDE_FLOAT32_C(   441.35), SIMDE_FLOAT32_C(  -898.74) },
      { SIMDE_FLOAT32_C(   123.78), SIMDE_FLOAT32_C(  -570.26), SIMDE_FLOAT32_C(  -809.67), SIMDE_FLOAT32_C(   244.32) } },
    { { SIMDE_FLOAT32_C(   993.63), SIMDE_FLOAT32_C(  -398.03), SIMDE_FLOAT32_C(  -382.26), SIMDE_FLOAT32_C(   956.67) },
      UINT8_C( 17),
      { SIMDE_FLOAT32_C(   234.51), SIMDE_FLOAT32_C(  -424.03), SIMDE_FLOAT32_C(   216.57), SIMDE_FLOAT32_C(  -512.86) },
      { SIMDE_FLOAT32_C(  -571.15), SIMDE_FLOAT32_C(  -836.50), SIMDE_FLOAT32_C(   -28.28), SIMDE_FLOAT32_C(    51.75) },
      { SIMDE_FLOAT32_C(  -336.64), SIMDE_FLOAT32_C(  -424.03), SIMDE_FLOAT32_C(   216.57), SIMDE_FLOAT32_C(  -512.86) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128 src = simde_mm_loadu_ps(test_vec[i].src);
    simde__m128 a = simde_mm_loadu_ps(test_vec[i].a);
    simde__m128 b = simde_mm_loadu_ps(test_vec[i].b);
    simde__m128 r = simde_mm_mask_add_ss(src, test_vec[i].k, a, b);
    simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128 src = simde_test_x86_random_f32x4(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m128 a = simde_test_x86_random_f32x4(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
    simde__m128 b = simde_test_x86_random_f32x4(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
    simde__m128 r = simde_mm_mask_add_ss(src, k, a, b);

    simde_test_x86_write_f32x4(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x4(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_maskz_add_ss (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k;
    const simde_float32 a[4];
    const simde_float32 b[4];
    const simde_float32 r[4];
  } test_vec[] = {
    { UINT8_C(229),
      { SIMDE_FLOAT32_C(   695.67), SIMDE_FLOAT32_C(  -467.38), SIMDE_FLOAT32_C(   303.41), SIMDE_FLOAT32_C(   444.32) },
      { SIMDE_FLOAT32_C(  -971.51), SIMDE_FLOAT32_C(   843.53), SIMDE_FLOAT32_C(  -243.67), SIMDE_FLOAT32_C(   463.81) },
      { SIMDE_FLOAT32_C(  -275.84), SIMDE_FLOAT32_C(  -467.38), SIMDE_FLOAT32_C(   303.41), SIMDE_FLOAT32_C(   444.32) } },
    { UINT8_C(226),
      { SIMDE_FLOAT32_C(   197.10), SIMDE_FLOAT32_C(   132.05), SIMDE_FLOAT32_C(  -305.37), SIMDE_FLOAT32_C(  -575.56) },
      { SIMDE_FLOAT32_C(   496.81), SIMDE_FLOAT32_C(  -398.18), SIMDE_FLOAT32_C(   186.52), SIMDE_FLOAT32_C(    10.74) },
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   132.05), SIMDE_FLOAT32_C(  -305.37), SIMDE_FLOAT32_C(  -575.56) } },
    { UINT8_C(101),
      { SIMDE_FLOAT32_C(  -659.66), SIMDE_FLOAT32_C(  -842.89), SIMDE_FLOAT32_C(  -218.71), SIMDE_FLOAT32_C(   619.24) },
      { SIMDE_FLOAT32_C(  -897.13), SIMDE_FLOAT32_C(  -873.47), SIMDE_FLOAT32_C(   228.22), SIMDE_FLOAT32_C(     5.28) },
      { SIMDE_FLOAT32_C( -1556.79), SIMDE_FLOAT32_C(  -842.89), SIMDE_FLOAT32_C(  -218.71), SIMDE_FLOAT32_C(   619.24) } },
    { UINT8_C(252),
      { SIMDE_FLOAT32_C(    87.18), SIMDE_FLOAT32_C(   911.77), SIMDE_FLOAT32_C(  -825.67), SIMDE_FLOAT32_C(   690.54) },
      { SIMDE_FLOAT32_C(   607.43), SIMDE_FLOAT32_C(  -293.05), SIMDE_FLOAT32_C(    -6.04), SIMDE_FLOAT32_C(    51.75) },
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   911.77), SIMDE_FLOAT32_C(  -825.67), SIMDE_FLOAT32_C(   690.54) } },
    { UINT8_C( 58),
      { SIMDE_FLOAT32_C(  -162.51), SIMDE_FLOAT32_C(   808.09), SIMDE_FLOAT32_C(  -800.75), SIMDE_FLOAT32_C(   733.18) },
      { SIMDE_FLOAT32_C(     5.19), SIMDE_FLOAT32_C(   331.30), SIMDE_FLOAT32_C(  -572.20), SIMDE_FLOAT32_C(   429.63) },
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   808.09), SIMDE_FLOAT32_C(  -800.75), SIMDE_FLOAT32_C(   733.18) } },
    { UINT8_C(165),
      { SIMDE_FLOAT32_C(    29.62), SIMDE_FLOAT32_C(  -383.85), SIMDE_FLOAT32_C(   838.85), SIMDE_FLOAT32_C(   -85.88) },
      { SIMDE_FLOAT32_C(   -43.51), SIMDE_FLOAT32_C(   995.96), SIMDE_FLOAT32_C(   695.41), SIMDE_FLOAT32_C(  -424.27) },
      { SIMDE_FLOAT32_C(   -13.89), SIMDE_FLOAT32_C(  -383.85), SIMDE_FLOAT32_C(   838.85), SIMDE_FLOAT32_C(   -85.88) } },
    { UINT8_C(151),
      { SIMDE_FLOAT32_C(   821.95), SIMDE_FLOAT32_C(   803.96), SIMDE_FLOAT32_C(   104.12), SIMDE_FLOAT32_C(   482.38) },
      { SIMDE_FLOAT32_C(  -108.86), SIMDE_FLOAT32_C(    15.89), SIMDE_FLOAT32_C(   656.71), SIMDE_FLOAT32_C(  -418.32) },
      { SIMDE_FLOAT32_C(   713.09), SIMDE_FLOAT32_C(   803.96), SIMDE_FLOAT32_C(   104.12), SIMDE_FLOAT32_C(   482.38) } },
    { UINT8_C(197),
      { SIMDE_FLOAT32_C(  -636.34), SIMDE_FLOAT32_C(   575.64), SIMDE_FLOAT32_C(   675.07), SIMDE_FLOAT32_C(    99.10) },
      { SIMDE_FLOAT32_C(  -586.87), SIMDE_FLOAT32_C(   483.16), SIMDE_FLOAT32_C(   298.35), SIMDE_FLOAT32_C(  -853.69) },
      { SIMDE_FLOAT32_C( -1223.21), SIMDE_FLOAT32_C(   575.64), SIMDE_FLOAT32_C(   675.07), SIMDE_FLOAT32_C(    99.10) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128 a = simde_mm_loadu_ps(test_vec[i].a);
    simde__m128 b = simde_mm_loadu_ps(test_vec[i].b);
    simde__m128 r = simde_mm_maskz_add_ss(test_vec[i].k, a, b);
    simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m128 a = simde_test_x86_random_f32x4(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
    simde__m128 b = simde_test_x86_random_f32x4(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
    simde__m128 r = simde_mm_maskz_add_ss(k, a, b);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f32x4(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_mask_add_epi16 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const int16_t src[16];
    const simde__mmask16 k;
    const int16_t a[16];
    const int16_t b[16];
    const int16_t r[16];
  } test_vec[] = {
    { { -INT16_C( 18088),  INT16_C(  1606), -INT16_C(  7503),  INT16_C(  5992),  INT16_C( 28165),  INT16_C( 22274), -INT16_C( 26583), -INT16_C( 13076),
        -INT16_C( 12908),  INT16_C( 10372),  INT16_C( 29897),  INT16_C(   832),  INT16_C( 19766),  INT16_C( 21637), -INT16_C( 21677),  INT16_C( 16763) },
      UINT16_C(60084),
      {  INT16_C( 31188),  INT16_C( 10550), -INT16_C( 29740),  INT16_C( 24731), -INT16_C( 25844),  INT16_C( 20568), -INT16_C( 21197),  INT16_C( 13543),
        -INT16_C( 13074), -INT16_C(  5446),  INT16_C(  8264), -INT16_C( 22453), -INT16_C( 30162), -INT16_C(  8771),  INT16_C( 29554), -INT16_C(  6204) },
      {  INT16_C( 13652), -INT16_C(  1326), -INT16_C(  8634), -INT16_C( 16805), -INT16_C(  7376), -INT16_C(  1060), -INT16_C( 17004),  INT16_C(  3029),
        -INT16_C( 23256), -INT16_C( 24573), -INT16_C(  5392),  INT16_C(  9842),  INT16_C( 11581), -INT16_C( 25918), -INT16_C(  1929),  INT16_C(  6096) },
      { -INT16_C( 18088),  INT16_C(  1606),  INT16_C( 27162),  INT16_C(  5992),  INT16_C( 32316),  INT16_C( 19508), -INT16_C( 26583),  INT16_C( 16572),
        -INT16_C( 12908), -INT16_C( 30019),  INT16_C( 29897), -INT16_C( 12611),  INT16_C( 19766),  INT16_C( 30847),  INT16_C( 27625), -INT16_C(   108) } },
    { { -INT16_C( 28260),  INT16_C(  3355),  INT16_C( 30149),  INT16_C( 18841),  INT16_C(   897), -INT16_C( 18335), -INT16_C( 27856),  INT16_C( 31843),
         INT16_C( 24626), -INT16_C( 30048), -INT16_C(  8679),  INT16_C(  1167),  INT16_C(  9529),  INT16_C( 15283), -INT16_C( 18329),  INT16_C(  1611) },
      UINT16_C(36795),
      { -INT16_C( 20367),  INT16_C( 17977), -INT16_C( 10340),  INT16_C( 23796),  INT16_C(  4308), -INT16_C(  8548), -INT16_C( 31482), -INT16_C( 21319),
         INT16_C(    17), -INT16_C( 10987),  INT16_C( 12850),  INT16_C(  9166),  INT16_C(  5118), -INT16_C( 13916),  INT16_C( 27754), -INT16_C( 17049) },
      { -INT16_C( 29649),  INT16_C(  2250),  INT16_C( 31457),  INT16_C( 19428), -INT16_C( 17826),  INT16_C(  8517),  INT16_C(  3008), -INT16_C( 15739),
        -INT16_C(  3791), -INT16_C( 20340),  INT16_C( 28400),  INT16_C( 31847), -INT16_C( 20111),  INT16_C(  8560), -INT16_C(  3090), -INT16_C( 17728) },
      {  INT16_C( 15520),  INT16_C( 20227),  INT16_C( 30149), -INT16_C( 22312), -INT16_C( 13518), -INT16_C(    31), -INT16_C( 27856),  INT16_C( 28478),
        -INT16_C(  3774), -INT16_C( 31327), -INT16_C( 24286), -INT16_C( 24523),  INT16_C(  9529),  INT16_C( 15283), -INT16_C( 18329),  INT16_C( 30759) } },
    { {  INT16_C(  5027),  INT16_C( 31603), -INT16_C(  3038),  INT16_C( 25247),  INT16_C( 12894), -INT16_C(  2609),  INT16_C( 30080),  INT16_C( 22396),
        -INT16_C(  4776), -INT16_C(  7593), -INT16_C(  5922), -INT16_C( 20302),  INT16_C( 26389), -INT16_C(  2181),  INT16_C( 14645),  INT16_C(  6951) },
      UINT16_C(62936),
      { -INT16_C( 18607),  INT16_C( 18295), -INT16_C(  2304),  INT16_C( 28875), -INT16_C(  8411),  INT16_C(  2635),  INT16_C( 16083),  INT16_C(  5198),
        -INT16_C( 31435), -INT16_C(  4074),  INT16_C( 13887), -INT16_C(  4755),  INT16_C( 30885), -INT16_C(  1538), -INT16_C( 32035), -INT16_C(  4113) },
      {  INT16_C(  2642),  INT16_C(  4797), -INT16_C(  3564), -INT16_C( 27490),  INT16_C( 16589),  INT16_C( 10413),  INT16_C( 30700), -INT16_C(  8724),
         INT16_C( 25964),  INT16_C(  5287), -INT16_C( 19421),  INT16_C( 28120), -INT16_C( 30880), -INT16_C( 19119), -INT16_C( 19912), -INT16_C( 27324) },
      {  INT16_C(  5027),  INT16_C( 31603), -INT16_C(  3038),  INT16_C(  1385),  INT16_C(  8178), -INT16_C(  2609), -INT16_C( 18753), -INT16_C(  3526),
        -INT16_C(  5471), -INT16_C(  7593), -INT16_C(  5534), -INT16_C( 20302),  INT16_C(     5), -INT16_C( 20657),  INT16_C( 13589), -INT16_C( 31437) } },
    { {  INT16_C( 25041),  INT16_C( 25663),  INT16_C( 28102),  INT16_C( 28245),  INT16_C(  5599),  INT16_C( 24300), -INT16_C( 10886), -INT16_C(  9183),
         INT16_C(  3807),  INT16_C( 25125), -INT16_C( 25229), -INT16_C(  4659), -INT16_C( 15898),  INT16_C( 11743), -INT16_C( 28195),  INT16_C( 25686) },
      UINT16_C(55587),
      {  INT16_C(  2381), -INT16_C( 16078), -INT16_C( 27768),  INT16_C( 27601),  INT16_C( 16912),  INT16_C(  8673), -INT16_C( 29342), -INT16_C(  7031),
         INT16_C( 30710), -INT16_C(  7797), -INT16_C( 30252),  INT16_C( 23527), -INT16_C(  2137),  INT16_C( 31719),  INT16_C( 32572),  INT16_C( 32012) },
      { -INT16_C( 11761),  INT16_C( 10830), -INT16_C( 22217), -INT16_C( 26449), -INT16_C( 13353), -INT16_C(  6701), -INT16_C( 21906),  INT16_C( 26387),
         INT16_C( 28827), -INT16_C( 13374), -INT16_C(  1039), -INT16_C( 19312), -INT16_C(  2641),  INT16_C( 17473), -INT16_C( 21172), -INT16_C( 20086) },
      { -INT16_C(  9380), -INT16_C(  5248),  INT16_C( 28102),  INT16_C( 28245),  INT16_C(  5599),  INT16_C(  1972), -INT16_C( 10886), -INT16_C(  9183),
        -INT16_C(  5999),  INT16_C( 25125), -INT16_C( 25229),  INT16_C(  4215), -INT16_C(  4778),  INT16_C( 11743),  INT16_C( 11400),  INT16_C( 11926) } },
    { {  INT16_C( 12057),  INT16_C( 29150),  INT16_C( 23614),  INT16_C( 25130),  INT16_C( 10655), -INT16_C( 27568),  INT16_C( 28503), -INT16_C( 25443),
        -INT16_C( 10717), -INT16_C( 20322), -INT16_C( 29779), -INT16_C( 24431),  INT16_C( 27510), -INT16_C(  9356),  INT16_C(  4476),  INT16_C( 16174) },
      UINT16_C(36512),
      {  INT16_C( 19088),  INT16_C( 10128),  INT16_C( 13140),  INT16_C( 29098), -INT16_C(  3415),  INT16_C(  2524), -INT16_C( 20169), -INT16_C( 11551),
        -INT16_C( 26829),  INT16_C(  3366),  INT16_C( 12131),  INT16_C(  2463),  INT16_C( 30355),  INT16_C( 12022),  INT16_C( 19040),  INT16_C( 20815) },
      { -INT16_C( 24937),  INT16_C( 16359), -INT16_C(   602),  INT16_C( 32707), -INT16_C(  4799),  INT16_C( 16001),  INT16_C( 10569),  INT16_C(  2669),
         INT16_C(  8145), -INT16_C(   957),  INT16_C( 11518), -INT16_C( 18084), -INT16_C( 29708),  INT16_C(  9779),  INT16_C(   904), -INT16_C( 28159) },
      {  INT16_C( 12057),  INT16_C( 29150),  INT16_C( 23614),  INT16_C( 25130),  INT16_C( 10655),  INT16_C( 18525),  INT16_C( 28503), -INT16_C(  8882),
        -INT16_C( 10717),  INT16_C(  2409),  INT16_C( 23649), -INT16_C( 15621),  INT16_C( 27510), -INT16_C(  9356),  INT16_C(  4476), -INT16_C(  7344) } },
    { {  INT16_C( 13479),  INT16_C( 32082), -INT16_C(  1052), -INT16_C( 28178), -INT16_C(  5151),  INT16_C( 15355), -INT16_C( 21898), -INT16_C(  6248),
         INT16_C( 26798),  INT16_C( 24344), -INT16_C( 25169),  INT16_C( 15648), -INT16_C( 31017),  INT16_C(  1114), -INT16_C( 19793),  INT16_C( 27930) },
      UINT16_C( 8052),
      { -INT16_C( 26007),  INT16_C( 21812), -INT16_C( 28453), -INT16_C( 22252), -INT16_C(  2350),  INT16_C( 20554), -INT16_C(   112),  INT16_C( 28501),
         INT16_C( 20387),  INT16_C( 15898), -INT16_C(  4455),  INT16_C(  8743), -INT16_C(  3007),  INT16_C(  1364),  INT16_C( 26716), -INT16_C( 32024) },
      { -INT16_C( 26027), -INT16_C( 22945), -INT16_C( 11918), -INT16_C( 14268), -INT16_C( 11610), -INT16_C( 22539),  INT16_C(  6421), -INT16_C( 16498),
         INT16_C( 26152), -INT16_C( 22496), -INT16_C(  1902), -INT16_C( 10031),  INT16_C(  9340), -INT16_C( 16924), -INT16_C( 19351), -INT16_C( 25237) },
      {  INT16_C( 13479),  INT16_C( 32082),  INT16_C( 25165), -INT16_C( 28178), -INT16_C( 13960), -INT16_C(  1985),  INT16_C(  6309), -INT16_C(  6248),
        -INT16_C( 18997), -INT16_C(  6598), -INT16_C(  6357), -INT16_C(  1288),  INT16_C(  6333),  INT16_C(  1114), -INT16_C( 19793),  INT16_C( 27930) } },
    { { -INT16_C(  9402), -INT16_C(  4652),  INT16_C( 27455), -INT16_C( 17628),  INT16_C( 12568), -INT16_C(  6414), -INT16_C( 29207), -INT16_C(  1798),
        -INT16_C(  7113), -INT16_C( 19430),  INT16_C( 19790),  INT16_C( 17330), -INT16_C( 30097),  INT16_C( 28960),  INT16_C( 28059), -INT16_C( 12652) },
      UINT16_C(55494),
      {  INT16_C(  4668),  INT16_C( 21727),  INT16_C( 23842),  INT16_C(   859),  INT16_C( 24202), -INT16_C(  4733), -INT16_C( 18553), -INT16_C( 32032),
        -INT16_C( 22813),  INT16_C(   981), -INT16_C(  1521), -INT16_C( 13085), -INT16_C( 20947), -INT16_C(  1346), -INT16_C(  1102), -INT16_C( 30046) },
      {  INT16_C( 29305), -INT16_C( 30721),  INT16_C( 31389), -INT16_C(  1704),  INT16_C(  2370), -INT16_C( 31381),  INT16_C( 22976),  INT16_C(  6971),
         INT16_C(  2368),  INT16_C( 11549), -INT16_C(  7631), -INT16_C(  5582), -INT16_C( 17938), -INT16_C(  4477),  INT16_C( 28539), -INT16_C(  8234) },
      { -INT16_C(  9402), -INT16_C(  8994), -INT16_C( 10305), -INT16_C( 17628),  INT16_C( 12568), -INT16_C(  6414),  INT16_C(  4423), -INT16_C( 25061),
        -INT16_C(  7113), -INT16_C( 19430),  INT16_C( 19790), -INT16_C( 18667),  INT16_C( 26651),  INT16_C( 28960),  INT16_C( 27437),  INT16_C( 27256) } },
    { {  INT16_C( 17152), -INT16_C( 16650), -INT16_C( 14707),  INT16_C( 11632),  INT16_C( 19908), -INT16_C( 20810),  INT16_C(   377),  INT16_C( 15379),
        -INT16_C( 10283), -INT16_C( 26722), -INT16_C(   177), -INT16_C( 17760),  INT16_C(  8591),  INT16_C(  3646), -INT16_C( 16462),  INT16_C( 17616) },
      UINT16_C( 3229),
      {  INT16_C( 32634),  INT16_C( 32728),  INT16_C( 30084), -INT16_C( 23413), -INT16_C( 22910),  INT16_C( 20672),  INT16_C( 22735), -INT16_C( 29137),
        -INT16_C(  1705),  INT16_C(  5378),  INT16_C( 17391),  INT16_C( 15446), -INT16_C(  2220), -INT16_C(  3224), -INT16_C( 13014), -INT16_C( 19705) },
      {  INT16_C( 14637),  INT16_C( 15248), -INT16_C(  4954), -INT16_C( 14311), -INT16_C(   296), -INT16_C( 30474), -INT16_C(  5162), -INT16_C( 32073),
         INT16_C( 26895),  INT16_C( 18041), -INT16_C( 18825),  INT16_C(  9328),  INT16_C( 19262),  INT16_C(  3861), -INT16_C( 29853),  INT16_C( 17210) },
      { -INT16_C( 18265), -INT16_C( 16650),  INT16_C( 25130),  INT16_C( 27812), -INT16_C( 23206), -INT16_C( 20810),  INT16_C(   377),  INT16_C(  4326),
        -INT16_C( 10283), -INT16_C( 26722), -INT16_C(  1434),  INT16_C( 24774),  INT16_C(  8591),  INT16_C(  3646), -INT16_C( 16462),  INT16_C( 17616) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256i src = simde_x_mm256_loadu_epi16(test_vec[i].src);
    simde__m256i a = simde_x_mm256_loadu_epi16(test_vec[i].a);
    simde__m256i b = simde_x_mm256_loadu_epi16(test_vec[i].b);
    simde__m256i r = simde_mm256_mask_add_epi16(src, test_vec[i].k, a, b);
    simde_test_x86_assert_equal_i16x16(r, simde_x_mm256_loadu_epi16(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_mm256_maskz_add_epi16 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const simde__mmask16 k;
    const int16_t a[16];
    const int16_t b[16];
    const int16_t r[16];
  } test_vec[] = {
    { UINT16_C( 4262),
      {  INT16_C( 17131),  INT16_C( 28575),  INT16_C( 26454),  INT16_C( 26097),  INT16_C( 13425),  INT16_C(  2916),  INT16_C( 18413), -INT16_C( 10307),
        -INT16_C( 22620),  INT16_C( 19835),  INT16_C( 24739),  INT16_C( 18854), -INT16_C(  6815), -INT16_C(  4094),  INT16_C( 31637),  INT16_C( 24951) },
      { -INT16_C( 29452),  INT16_C( 29154), -INT16_C( 24158),  INT16_C( 20005), -INT16_C( 21148),  INT16_C( 28846),  INT16_C( 22284), -INT16_C( 15662),
        -INT16_C(  9581), -INT16_C( 17953), -INT16_C( 18145), -INT16_C( 27296), -INT16_C( 29945), -INT16_C( 14925), -INT16_C( 22585),  INT16_C( 11545) },
      {  INT16_C(     0), -INT16_C(  7807),  INT16_C(  2296),  INT16_C(     0),  INT16_C(     0),  INT16_C( 31762),  INT16_C(     0), -INT16_C( 25969),
         INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C( 28776),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
    { UINT16_C(12070),
      { -INT16_C( 11840), -INT16_C( 15372),  INT16_C( 32629),  INT16_C( 21795), -INT16_C( 20660), -INT16_C( 29830), -INT16_C( 24024), -INT16_C( 29778),
        -INT16_C( 10477), -INT16_C( 11462),  INT16_C(  1337),  INT16_C(  5552),  INT16_C(  5961),  INT16_C( 23833), -INT16_C( 10057), -INT16_C( 19595) },
      { -INT16_C( 22405), -INT16_C( 25821), -INT16_C( 24191), -INT16_C(  3861), -INT16_C( 24777),  INT16_C( 24020),  INT16_C( 13500), -INT16_C( 20346),
        -INT16_C(   128),  INT16_C(  5177),  INT16_C( 12366), -INT16_C(  8346), -INT16_C(  7771), -INT16_C(  8032), -INT16_C( 11287), -INT16_C( 24811) },
      {  INT16_C(     0),  INT16_C( 24343),  INT16_C(  8438),  INT16_C(     0),  INT16_C(     0), -INT16_C(  5810),  INT16_C(     0),  INT16_C(     0),
        -INT16_C( 10605), -INT16_C(  6285),  INT16_C( 13703), -INT16_C(  2794),  INT16_C(     0),  INT16_C( 15801),  INT16_C(     0),  INT16_C(     0) } },
    { UINT16_C(58512),
      { -INT16_C( 21753), -INT16_C( 12602), -INT16_C(  7088), -INT16_C( 15287),  INT16_C(  2851), -INT16_C(  3784), -INT16_C( 19644), -INT16_C(  3081),
         INT16_C( 27159),  INT16_C( 23080), -INT16_C( 12718), -INT16_C( 24689), -INT16_C( 17761),  INT16_C(  9682), -INT16_C( 30808), -INT16_C( 21236) },
      { -INT16_C( 30812),  INT16_C(  6629),  INT16_C( 21297), -INT16_C( 17253),  INT16_C( 32442),  INT16_C(  2260), -INT16_C(  2679), -INT16_C(  7556),
        -INT16_C( 10834), -INT16_C( 26189),  INT16_C(  2827), -INT16_C( 12197), -INT16_C( 13163),  INT16_C( 26769),  INT16_C( 21450),  INT16_C(  4191) },
      {  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C( 30243),  INT16_C(     0),  INT16_C(     0), -INT16_C( 10637),
         INT16_C(     0),  INT16_C(     0), -INT16_C(  9891),  INT16_C(     0),  INT16_C(     0), -INT16_C( 29085), -INT16_C(  9358), -INT16_C( 17045) } },
    { UINT16_C(26409),
      {  INT16_C( 23989), -INT16_C(  3893), -INT16_C( 10213), -INT16_C( 24561),  INT16_C( 24975), -INT16_C( 14143), -INT16_C( 26678), -INT16_C( 32272),
        -INT16_C( 25660),  INT16_C( 31804), -INT16_C( 10324),  INT16_C( 19769), -INT16_C( 22018), -INT16_C( 31803), -INT16_C( 22436),  INT16_C( 31880) },
      { -INT16_C( 13937),  INT16_C( 31205), -INT16_C( 12695),  INT16_C(  9893),  INT16_C( 19693), -INT16_C( 32334), -INT16_C( 25972),  INT16_C( 30977),
         INT16_C( 26854), -INT16_C( 10518), -INT16_C( 16582), -INT16_C( 26001), -INT16_C( 23041),  INT16_C(  5435),  INT16_C( 20892), -INT16_C(  8904) },
      {  INT16_C( 10052),  INT16_C(     0),  INT16_C(     0), -INT16_C( 14668),  INT16_C(     0),  INT16_C( 19059),  INT16_C(     0),  INT16_C(     0),
         INT16_C(  1194),  INT16_C( 21286), -INT16_C( 26906),  INT16_C(     0),  INT16_C(     0), -INT16_C( 26368), -INT16_C(  1544),  INT16_C(     0) } },
    { UINT16_C(33734),
      { -INT16_C( 22559), -INT16_C(  8699), -INT16_C(  3315),  INT16_C( 30631),  INT16_C( 26186),  INT16_C(   646),  INT16_C( 32221), -INT16_C( 21902),
         INT16_C(  8809), -INT16_C(  9404), -INT16_C( 30818),  INT16_C(  9706), -INT16_C( 24086),  INT16_C( 10730), -INT16_C( 14587), -INT16_C( 12657) },
      { -INT16_C( 32121), -INT16_C( 14411), -INT16_C( 12619),  INT16_C( 32766), -INT16_C(  5886), -INT16_C( 28837), -INT16_C( 21424),  INT16_C(  1152),
         INT16_C( 18809), -INT16_C(  4130),  INT16_C(  7614), -INT16_C( 25916), -INT16_C( 21360),  INT16_C( 31629), -INT16_C( 21160), -INT16_C( 31719) },
      {  INT16_C(     0), -INT16_C( 23110), -INT16_C( 15934),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C( 10797), -INT16_C( 20750),
         INT16_C( 27618), -INT16_C( 13534),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C( 21160) } },
    { UINT16_C(12974),
      { -INT16_C(  9110), -INT16_C( 27434), -INT16_C(  6575), -INT16_C( 17103),  INT16_C( 10872), -INT16_C( 28881), -INT16_C(  1144),  INT16_C( 11533),
        -INT16_C( 28247),  INT16_C( 19770),  INT16_C( 10309), -INT16_C( 18656), -INT16_C(  7754),  INT16_C(  3438),  INT16_C(   758), -INT16_C( 19035) },
      { -INT16_C( 10315), -INT16_C(   614),  INT16_C(  9805),  INT16_C( 29426), -INT16_C( 17671),  INT16_C( 32637),  INT16_C( 32714),  INT16_C( 16551),
        -INT16_C( 22924), -INT16_C( 21545), -INT16_C(  9595), -INT16_C( 15050),  INT16_C(  9710),  INT16_C( 18424),  INT16_C(   172), -INT16_C(  1119) },
      {  INT16_C(     0), -INT16_C( 28048),  INT16_C(  3230),  INT16_C( 12323),  INT16_C(     0),  INT16_C(  3756),  INT16_C(     0),  INT16_C( 28084),
         INT16_C(     0), -INT16_C(  1775),  INT16_C(     0),  INT16_C(     0),  INT16_C(  1956),  INT16_C( 21862),  INT16_C(     0),  INT16_C(     0) } },
    { UINT16_C(10927),
      {  INT16_C(  8380),  INT16_C( 25660),  INT16_C(  3043),  INT16_C( 26369), -INT16_C(  8173),  INT16_C( 10605),  INT16_C( 14118), -INT16_C(  4505),
        -INT16_C( 11066),  INT16_C( 28798), -INT16_C( 24766), -INT16_C( 11889), -INT16_C( 14630),  INT16_C( 31282), -INT16_C(  8140), -INT16_C(  9178) },
      {  INT16_C( 15994), -INT16_C( 30317), -INT16_C( 15077),  INT16_C( 17333), -INT16_C(  7916), -INT16_C( 24502),  INT16_C(  5769), -INT16_C( 29765),
        -INT16_C( 24127), -INT16_C( 29183), -INT16_C( 28892),  INT16_C( 13466),  INT16_C( 13695), -INT16_C(  4328),  INT16_C( 11614), -INT16_C( 16283) },
      {  INT16_C( 24374), -INT16_C(  4657), -INT16_C( 12034), -INT16_C( 21834),  INT16_C(     0), -INT16_C( 13897),  INT16_C(     0),  INT16_C( 31266),
         INT16_C(     0), -INT16_C(   385),  INT16_C(     0),  INT16_C(  1577),  INT16_C(     0),  INT16_C( 26954),  INT16_C(     0),  INT16_C(     0) } },
    { UINT16_C(24898),
      {  INT16_C( 31303), -INT16_C( 28888),  INT16_C( 32475), -INT16_C(  9009), -INT16_C( 21039),  INT16_C(  2463), -INT16_C(   235), -INT16_C( 27830),
         INT16_C( 12119), -INT16_C( 21538), -INT16_C( 26278), -INT16_C( 21134), -INT16_C( 12642), -INT16_C(  7297), -INT16_C( 26495),  INT16_C( 29429) },
      {  INT16_C( 31766),  INT16_C( 20949),  INT16_C(  1225),  INT16_C(  8709),  INT16_C( 22985), -INT16_C(  8523),  INT16_C( 31728), -INT16_C( 31368),
        -INT16_C( 17643), -INT16_C(  2286), -INT16_C( 26761),  INT16_C(  1099),  INT16_C( 26190), -INT16_C( 28221),  INT16_C( 25127), -INT16_C(  9460) },
      {  INT16_C(     0), -INT16_C(  7939),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C( 31493),  INT16_C(     0),
        -INT16_C(  5524),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C( 30018), -INT16_C(  1368),  INT16_C(     0) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256i a = simde_x_mm256_loadu_epi16(test_vec[i].a);
    simde__m256i b = simde_x_mm256_loadu_epi16(test_vec[i].b);
    simde__m256i r = simde_mm256_maskz_add_epi16(test_vec[i].k, a, b);
    simde_test_x86_assert_equal_i16x16(r, simde_x_mm256_loadu_epi16(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_mm256_mask_add_epi32 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const int32_t src[8];
    const simde__mmask8 k;
    const int32_t a[8];
    const int32_t b[8];
    const int32_t r[8];
  } test_vec[] = {
    { {  INT32_C(   426361587), -INT32_C(   443903963),  INT32_C(  1108332220),  INT32_C(  1919687830),  INT32_C(  1848164895), -INT32_C(  1877796598),  INT32_C(   483830142), -INT32_C(  2033377471) },
      UINT8_C(237),
      {  INT32_C(  1091358368),  INT32_C(   454097987),  INT32_C(   794389166),  INT32_C(   249974803),  INT32_C(   152267150),  INT32_C(   907080727), -INT32_C(  1733770061),  INT32_C(   220923521) },
      {  INT32_C(  1746020713),  INT32_C(  1017500003), -INT32_C(   803273524),  INT32_C(  1210396863),  INT32_C(   579828512), -INT32_C(   646644006),  INT32_C(  1430804319),  INT32_C(   926985775) },
      { -INT32_C(  1457588215), -INT32_C(   443903963), -INT32_C(     8884358),  INT32_C(  1460371666),  INT32_C(  1848164895),  INT32_C(   260436721), -INT32_C(   302965742),  INT32_C(  1147909296) } },
    { {  INT32_C(  1684912389),  INT32_C(  1461764767),  INT32_C(   531585245), -INT32_C(  1449055219),  INT32_C(  1704880266),  INT32_C(    70446890),  INT32_C(  2071901944), -INT32_C(   833618578) },
      UINT8_C(215),
      { -INT32_C(  1260280170),  INT32_C(    60784922),  INT32_C(  1789074221),  INT32_C(   506242865), -INT32_C(   265290717),  INT32_C(   773465711), -INT32_C(   249802610),  INT32_C(  1884100310) },
      { -INT32_C(  1123572585),  INT32_C(   950443465),  INT32_C(  1139858930), -INT32_C(  1387438223), -INT32_C(   995912866), -INT32_C(   783462299),  INT32_C(   568247403), -INT32_C(   175356258) },
      {  INT32_C(  1911114541),  INT32_C(  1011228387), -INT32_C(  1366034145), -INT32_C(  1449055219), -INT32_C(  1261203583),  INT32_C(    70446890),  INT32_C(   318444793),  INT32_C(  1708744052) } },
    { {  INT32_C(   683801390), -INT32_C(  1524037838),  INT32_C(   971777976), -INT32_C(   179262957), -INT32_C(   662180444),  INT32_C(  1746109353), -INT32_C(   120687010), -INT32_C(  1478304295) },
      UINT8_C(142),
      { -INT32_C(  1699645306),  INT32_C(  1703095819), -INT32_C(  1247556922), -INT32_C(   676606248), -INT32_C(  2057411672), -INT32_C(  2133453849),  INT32_C(  1277225381),  INT32_C(   895840639) },
      { -INT32_C(   241606211), -INT32_C(   714501803), -INT32_C(   395132250), -INT32_C(  1428661824),  INT32_C(  1298870179),  INT32_C(  1006598770), -INT32_C(  1667424466),  INT32_C(  1226468081) },
      {  INT32_C(   683801390),  INT32_C(   988594016), -INT32_C(  1642689172), -INT32_C(  2105268072), -INT32_C(   662180444),  INT32_C(  1746109353), -INT32_C(   120687010),  INT32_C(  2122308720) } },
    { { -INT32_C(  1854580385),  INT32_C(  1115024973), -INT32_C(   902732038),  INT32_C(  1105570825), -INT32_C(  2019220757),  INT32_C(  1567591273), -INT32_C(  1045989337),  INT32_C(   483693948) },
      UINT8_C( 16),
      { -INT32_C(  1622664288), -INT32_C(  1596764141),  INT32_C(  1531617719),  INT32_C(  2136124051), -INT32_C(   833907649),  INT32_C(   442458548), -INT32_C(  1966743074),  INT32_C(  1510510672) },
      {  INT32_C(  1995792121),  INT32_C(  1901624212), -INT32_C(   724913828),  INT32_C(   574753287), -INT32_C(   939006740),  INT32_C(  1662860686), -INT32_C(   798097367), -INT32_C(   819579665) },
      { -INT32_C(  1854580385),  INT32_C(  1115024973), -INT32_C(   902732038),  INT32_C(  1105570825), -INT32_C(  1772914389),  INT32_C(  1567591273), -INT32_C(  1045989337),  INT32_C(   483693948) } },
    { { -INT32_C(  2128119628),  INT32_C(   286644021), -INT32_C(   144034294), -INT32_C(   755119821),  INT32_C(   737304527), -INT32_C(   795896062), -INT32_C(  1306877446),  INT32_C(  2017207584) },
      UINT8_C( 39),
      { -INT32_C(   889153325),  INT32_C(  1946641334), -INT32_C(   394827187), -INT32_C(  1838628604), -INT32_C(  1114607536), -INT32_C(   988331075),  INT32_C(   505604917), -INT32_C(   158258489) },
      { -INT32_C(    19176166), -INT32_C(   739831540),  INT32_C(   812816619),  INT32_C(  1345615940),  INT32_C(   485266830), -INT32_C(  1880526201), -INT32_C(   347473235), -INT32_C(   631923023) },
      { -INT32_C(   908329491),  INT32_C(  1206809794),  INT32_C(   417989432), -INT32_C(   755119821),  INT32_C(   737304527),  INT32_C(  1426110020), -INT32_C(  1306877446),  INT32_C(  2017207584) } },
    { { -INT32_C(    35579584), -INT32_C(  1740792689),  INT32_C(  1827803830), -INT32_C(  1820729369), -INT32_C(  2037363614),  INT32_C(  1301089229),  INT32_C(  2117227785),  INT32_C(  1313930535) },
      UINT8_C( 29),
      {  INT32_C(   773440826), -INT32_C(    38988069), -INT32_C(   324201942),  INT32_C(   299194520), -INT32_C(   582542291),  INT32_C(   984927229),  INT32_C(   579334463),  INT32_C(   166931855) },
      { -INT32_C(  1529113807),  INT32_C(   521813891), -INT32_C(  1447212676),  INT32_C(  1970271572), -INT32_C(  1806503392),  INT32_C(  1956442032), -INT32_C(   878298291),  INT32_C(   934511007) },
      { -INT32_C(   755672981), -INT32_C(  1740792689), -INT32_C(  1771414618), -INT32_C(  2025501204),  INT32_C(  1905921613),  INT32_C(  1301089229),  INT32_C(  2117227785),  INT32_C(  1313930535) } },
    { {  INT32_C(  1988271902), -INT32_C(   928422277),  INT32_C(   751124781), -INT32_C(  1615080274), -INT32_C(  1457437893),  INT32_C(  1967921693), -INT32_C(   719093602),  INT32_C(  1590290629) },
      UINT8_C(184),
      { -INT32_C(   200700131), -INT32_C(  1501991200),  INT32_C(  1863812719), -INT32_C(  2110506296), -INT32_C(   281811570), -INT32_C(  1957556859), -INT32_C(   274670855),  INT32_C(   588775262) },
      {  INT32_C(    48549005), -INT32_C(  1189837525), -INT32_C(   246645075),  INT32_C(   710580162),  INT32_C(  1547365021), -INT32_C(  1190799946), -INT32_C(   758766312), -INT32_C(  1139192475) },
      {  INT32_C(  1988271902), -INT32_C(   928422277),  INT32_C(   751124781), -INT32_C(  1399926134),  INT32_C(  1265553451),  INT32_C(  1146610491), -INT32_C(   719093602), -INT32_C(   550417213) } },
    { { -INT32_C(  1607524027), -INT32_C(  1435945627), -INT32_C(  1834704498), -INT32_C(  2007313332), -INT32_C(  1883122106), -INT32_C(  1075124600),  INT32_C(  1649535565), -INT32_C(   868112955) },
      UINT8_C( 77),
      {  INT32_C(   441881310),  INT32_C(  1966218471),  INT32_C(  1844649392), -INT32_C(   321863841),  INT32_C(    26145081),  INT32_C(  2066060518), -INT32_C(  1310174374), -INT32_C(  1468908845) },
      {  INT32_C(   900269734),  INT32_C(  1516547149),  INT32_C(  1563014998),  INT32_C(    47500850), -INT32_C(  2090628180),  INT32_C(   430978017), -INT32_C(  2091637067),  INT32_C(  1915750227) },
      {  INT32_C(  1342151044), -INT32_C(  1435945627), -INT32_C(   887302906), -INT32_C(   274362991), -INT32_C(  1883122106), -INT32_C(  1075124600),  INT32_C(   893155855), -INT32_C(   868112955) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256i src = simde_x_mm256_loadu_epi32(test_vec[i].src);
    simde__m256i a = simde_x_mm256_loadu_epi32(test_vec[i].a);
    simde__m256i b = simde_x_mm256_loadu_epi32(test_vec[i].b);
    simde__m256i r = simde_mm256_mask_add_epi32(src, test_vec[i].k, a, b);
    simde_test_x86_assert_equal_i32x8(r, simde_x_mm256_loadu_epi32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_mm256_maskz_add_epi32 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const simde__mmask8 k;
    const int32_t a[8];
    const int32_t b[8];
    const int32_t r[8];
  } test_vec[] = {
    { UINT8_C(101),
      { -INT32_C(   628298337),  INT32_C(   792924887), -INT32_C(  1672768632), -INT32_C(  1074053347), -INT32_C(  1064007895),  INT32_C(  1455536926), -INT32_C(  1219047864),  INT32_C(  1560140371) },
      {  INT32_C(  1960233098),  INT32_C(  1892059781), -INT32_C(  1373718700), -INT32_C(   352286831),  INT32_C(  1327327802),  INT32_C(   454025751),  INT32_C(  2093702863), -INT32_C(  1771120467) },
      {  INT32_C(  1331934761),  INT32_C(           0),  INT32_C(  1248479964),  INT32_C(           0),  INT32_C(           0),  INT32_C(  1909562677),  INT32_C(   874654999),  INT32_C(           0) } },
    { UINT8_C( 88),
      { -INT32_C(   643482639),  INT32_C(  1022430836),  INT32_C(  1708754555), -INT32_C(  1303850341),  INT32_C(  1960699394),  INT32_C(   694659735),  INT32_C(   142013690),  INT32_C(   821320707) },
      { -INT32_C(   242563209),  INT32_C(  1657605631), -INT32_C(  1229937754),  INT32_C(  1696216758), -INT32_C(  1213277610), -INT32_C(   353040792),  INT32_C(   392990364),  INT32_C(  1905216013) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(   392366417),  INT32_C(   747421784),  INT32_C(           0),  INT32_C(   535004054),  INT32_C(           0) } },
    { UINT8_C(212),
      { -INT32_C(  1571159102),  INT32_C(  2016749220), -INT32_C(  1981095890), -INT32_C(  1870763484), -INT32_C(   836082282), -INT32_C(   660363674), -INT32_C(  1962323400), -INT32_C(   143449086) },
      { -INT32_C(   765186109),  INT32_C(  1029534834),  INT32_C(     6988289),  INT32_C(  1621597364), -INT32_C(   789981577),  INT32_C(  1804329931),  INT32_C(  1186001858),  INT32_C(   883248384) },
      {  INT32_C(           0),  INT32_C(           0), -INT32_C(  1974107601),  INT32_C(           0), -INT32_C(  1626063859),  INT32_C(           0), -INT32_C(   776321542),  INT32_C(   739799298) } },
    { UINT8_C(109),
      { -INT32_C(  1770917884), -INT32_C(   530889520), -INT32_C(   504237856), -INT32_C(  1597380183), -INT32_C(  1049867779), -INT32_C(   468326631),  INT32_C(   559503757),  INT32_C(   564004527) },
      {  INT32_C(  1698045997), -INT32_C(   820697417), -INT32_C(    38633790),  INT32_C(   881187224),  INT32_C(  1921955153),  INT32_C(   941315295),  INT32_C(   759745706), -INT32_C(  2126521994) },
      { -INT32_C(    72871887),  INT32_C(           0), -INT32_C(   542871646), -INT32_C(   716192959),  INT32_C(           0),  INT32_C(   472988664),  INT32_C(  1319249463),  INT32_C(           0) } },
    { UINT8_C(137),
      { -INT32_C(  1858814058), -INT32_C(  1042377463), -INT32_C(   887474565), -INT32_C(  2122945850),  INT32_C(  1667461733), -INT32_C(   205579704), -INT32_C(   975714158),  INT32_C(  1635367554) },
      { -INT32_C(  1057794330),  INT32_C(  1052274960), -INT32_C(    41436220),  INT32_C(   143840279), -INT32_C(  1906448242), -INT32_C(  1788921821),  INT32_C(    10365593),  INT32_C(    35226418) },
      {  INT32_C(  1378358908),  INT32_C(           0),  INT32_C(           0), -INT32_C(  1979105571),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(  1670593972) } },
    { UINT8_C( 14),
      {  INT32_C(   955121944), -INT32_C(  1858149961),  INT32_C(   989283609), -INT32_C(  1140579072), -INT32_C(   447254547), -INT32_C(   109214975), -INT32_C(   782653276), -INT32_C(   848887013) },
      { -INT32_C(  1458708646), -INT32_C(    83883126),  INT32_C(  1994371146),  INT32_C(  1884018050), -INT32_C(  1630751337), -INT32_C(   235406036),  INT32_C(   301613089),  INT32_C(  1337287860) },
      {  INT32_C(           0), -INT32_C(  1942033087), -INT32_C(  1311312541),  INT32_C(   743438978),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
    { UINT8_C( 68),
      { -INT32_C(    17343115), -INT32_C(  1057582083),  INT32_C(  1925676355),  INT32_C(   513737506),  INT32_C(  1449532125),  INT32_C(   651379898),  INT32_C(   265490234),  INT32_C(  1273345831) },
      {  INT32_C(  1163851905), -INT32_C(  1572780827),  INT32_C(  1722687548),  INT32_C(  1425094090),  INT32_C(    16744716),  INT32_C(  1308498419), -INT32_C(   505877045), -INT32_C(   219979393) },
      {  INT32_C(           0),  INT32_C(           0), -INT32_C(   646603393),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(   240386811),  INT32_C(           0) } },
    { UINT8_C(143),
      { -INT32_C(  1104597870), -INT32_C(   724590379),  INT32_C(  1429138415),  INT32_C(  1193975544),  INT32_C(  1467334920), -INT32_C(  1899396965),  INT32_C(  2086966300),  INT32_C(   710186623) },
      { -INT32_C(  1112373334),  INT32_C(   406415980), -INT32_C(  1125556542), -INT32_C(   990567746), -INT32_C(   543146280), -INT32_C(  1976533491), -INT32_C(   337560786),  INT32_C(   640868710) },
      {  INT32_C(  2077996092), -INT32_C(   318174399),  INT32_C(   303581873),  INT32_C(   203407798),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(  1351055333) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256i a = simde_x_mm256_loadu_epi32(test_vec[i].a);
    simde__m256i b = simde_x_mm256_loadu_epi32(test_vec[i].b);
    simde__m256i r = simde_mm256_maskz_add_epi32(test_vec[i].k, a, b);
    simde_test_x86_assert_equal_i32x8(r, simde_x_mm256_loadu_epi32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_mm256_mask_add_epi64 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const int64_t src[4];
    const simde__mmask8 k;
    const int64_t a[4];
    const int64_t b[4];
    const int64_t r[4];
  } test_vec[] = {
    { {  INT64_C(  360909485362196701),  INT64_C( 7148018188301179842),  INT64_C( 1649121149472017725),  INT64_C( 7018633285360450459) },
      UINT8_C(126),
      { -INT64_C( 2069953424375465822),  INT64_C( 2649419973831635918),  INT64_C( 6631995759656128229),  INT64_C( 9043749468674069294) },
      {  INT64_C( 9127572592675566832),  INT64_C( 3139630957469384257), -INT64_C( 5603674882213165495),  INT64_C( 5601563532454726799) },
      {  INT64_C(  360909485362196701),  INT64_C( 5789050931301020175),  INT64_C( 1028320877442962734), -INT64_C( 3801431072580755523) } },
    { {  INT64_C(  756376000083734984),  INT64_C( 9070926205802174906),  INT64_C( 8919263102054599581),  INT64_C( 7783409138876853393) },
      UINT8_C(148),
      {  INT64_C(  382287398418300828),  INT64_C( 1115930529724925645), -INT64_C( 2730316823403657925),  INT64_C(  770900165413777792) },
      {  INT64_C( 6713096438988588943),  INT64_C( 6664457870741226758),  INT64_C(  234662618570907527), -INT64_C(  313102228808514227) },
      {  INT64_C(  756376000083734984),  INT64_C( 9070926205802174906), -INT64_C( 2495654204832750398),  INT64_C( 7783409138876853393) } },
    { {  INT64_C( 1483073417317823758),  INT64_C( 8795153962326963887), -INT64_C( 4149002502104727210),  INT64_C( 8377900925383693364) },
      UINT8_C( 87),
      {  INT64_C( 9038467157306396791), -INT64_C( 9115228638979228790),  INT64_C( 3197974720961571240), -INT64_C( 4399071158149707528) },
      {  INT64_C( 4732531473964703663), -INT64_C( 5052728689924432136), -INT64_C( 7671229005429790575),  INT64_C( 8865457101011322896) },
      { -INT64_C( 4675745442438451162),  INT64_C( 4278786744805890690), -INT64_C( 4473254284468219335),  INT64_C( 8377900925383693364) } },
    { { -INT64_C( 1491568665462998214), -INT64_C( 3104012194786369954), -INT64_C( 7320413738587291346),  INT64_C( 2384471346820870965) },
      UINT8_C(225),
      {  INT64_C( 8948791811858071094),  INT64_C( 5692550040163038202),  INT64_C(  830789416759788308),  INT64_C( 8983297292243767262) },
      {  INT64_C( 1554136023168485625),  INT64_C( 4643374375046125828),  INT64_C( 1207394444856260247),  INT64_C( 1262475476216602754) },
      { -INT64_C( 7943816238682994897), -INT64_C( 3104012194786369954), -INT64_C( 7320413738587291346),  INT64_C( 2384471346820870965) } },
    { { -INT64_C( 2613596307693393920),  INT64_C( 3708150816535274390),  INT64_C( 8656585681334612292), -INT64_C( 4071969454335091598) },
      UINT8_C(205),
      {  INT64_C( 4385428620712312621), -INT64_C( 6056401822535469397), -INT64_C( 5800804598671026971), -INT64_C( 3092870165874030482) },
      { -INT64_C( 2397873348439446309),  INT64_C( 5910269085379428366), -INT64_C( 1513047638103079921),  INT64_C(   34238311786967204) },
      {  INT64_C( 1987555272272866312),  INT64_C( 3708150816535274390), -INT64_C( 7313852236774106892), -INT64_C( 3058631854087063278) } },
    { {  INT64_C( 8817443827781467208), -INT64_C( 6180758275292564870), -INT64_C( 4102290530891378202),  INT64_C( 1720054592936513257) },
      UINT8_C(101),
      {  INT64_C( 8678261917080766892),  INT64_C( 6939458579392878936), -INT64_C( 1907623884063940351), -INT64_C( 1780765326956861806) },
      {  INT64_C( 3690861860797904287),  INT64_C( 7163125489808023225), -INT64_C( 7713699132847182549), -INT64_C( 5838526841458117177) },
      { -INT64_C( 6077620295830880437), -INT64_C( 6180758275292564870),  INT64_C( 8825421056798428716),  INT64_C( 1720054592936513257) } },
    { { -INT64_C( 4226189128237357280), -INT64_C( 8943401384532428378),  INT64_C(  205521322776642791),  INT64_C( 8979119138226217421) },
      UINT8_C(100),
      {  INT64_C(   74791247571826988),  INT64_C( 6811658127022208365), -INT64_C( 2788904720803475790),  INT64_C( 2092431171636941532) },
      { -INT64_C( 4721001194988252981), -INT64_C( 5047893754993698744), -INT64_C( 9019989623988394261),  INT64_C( 6590525094843788764) },
      { -INT64_C( 4226189128237357280), -INT64_C( 8943401384532428378),  INT64_C( 6637849728917681565),  INT64_C( 8979119138226217421) } },
    { { -INT64_C( 5055154983797961474),  INT64_C(     708989412318452),  INT64_C( 3248858564412742665), -INT64_C( 1488234339305196330) },
      UINT8_C( 97),
      { -INT64_C( 1196281769919788973), -INT64_C( 5928234014316609444), -INT64_C( 3324535828431189494), -INT64_C( 5570270810707974551) },
      { -INT64_C( 1528923573651634989), -INT64_C( 8239253630832908272),  INT64_C(  446928026184942104), -INT64_C( 7452034225800619308) },
      { -INT64_C( 2725205343571423962),  INT64_C(     708989412318452),  INT64_C( 3248858564412742665), -INT64_C( 1488234339305196330) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256i src = simde_x_mm256_loadu_epi64(test_vec[i].src);
    simde__m256i a = simde_x_mm256_loadu_epi64(test_vec[i].a);
    simde__m256i b = simde_x_mm256_loadu_epi64(test_vec[i].b);
    simde__m256i r = simde_mm256_mask_add_epi64(src, test_vec[i].k, a, b);
    simde_test_x86_assert_equal_i64x4(r, simde_x_mm256_loadu_epi64(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_mm256_maskz_add_epi64 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const simde__mmask8 k;
    const int64_t a[4];
    const int64_t b[4];
    const int64_t r[4];
  } test_vec[] = {
    { UINT8_C(211),
      {  INT64_C( 5396742621358824656), -INT64_C( 5784837964580948014),  INT64_C(  745905599035155894),  INT64_C( 4432459820370420263) },
      { -INT64_C( 2375627515263830277),  INT64_C( 7298802839973142414), -INT64_C( 4614916525088736096), -INT64_C( 9037591478603085962) },
      {  INT64_C( 3021115106094994379),  INT64_C( 1513964875392194400),  INT64_C(                   0),  INT64_C(                   0) } },
    { UINT8_C(176),
      { -INT64_C( 3141262892297976873), -INT64_C( 2562411322036282317),  INT64_C( 3833520914396613866),  INT64_C( 2194941788560940840) },
      {  INT64_C(  901766347898667771),  INT64_C( 7724355933804345671), -INT64_C( 7464625842775737952), -INT64_C( 2080691623985024546) },
      {  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0) } },
    { UINT8_C(195),
      { -INT64_C( 6193321100419901660),  INT64_C( 8380227380500028405),  INT64_C( 6069563355255056514),  INT64_C( 7567844964561032724) },
      { -INT64_C( 2028429546419720554),  INT64_C( 5900094282335619633), -INT64_C( 3089803978563711891),  INT64_C(  365280098963395815) },
      { -INT64_C( 8221750646839622214), -INT64_C( 4166422410873903578),  INT64_C(                   0),  INT64_C(                   0) } },
    { UINT8_C( 97),
      { -INT64_C( 6385959693145891606),  INT64_C( 5329109541483815658), -INT64_C( 2688882311189433873),  INT64_C( 9217817113255199635) },
      {  INT64_C( 1459731060611346300), -INT64_C( 3886780218327649651),  INT64_C( 7977890084846895501),  INT64_C( 4735556178160298813) },
      { -INT64_C( 4926228632534545306),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0) } },
    { UINT8_C(134),
      {  INT64_C( 7860706032630943107),  INT64_C( 2484009629061100715),  INT64_C( 7509120629608935666), -INT64_C( 2386733518501817427) },
      {  INT64_C( 8447004062159754569), -INT64_C( 1567962289685365340), -INT64_C( 8386187512053637187), -INT64_C( 1215046594740082176) },
      {  INT64_C(                   0),  INT64_C(  916047339375735375), -INT64_C(  877066882444701521),  INT64_C(                   0) } },
    { UINT8_C(199),
      { -INT64_C( 2180470979029174228),  INT64_C( 6443804020022187526), -INT64_C( 6418035538474219843), -INT64_C( 5507798642899854187) },
      {  INT64_C( 2466999869382999871),  INT64_C(  996995031899642676), -INT64_C(   73336982042601123),  INT64_C( 6989615507504111215) },
      {  INT64_C(  286528890353825643),  INT64_C( 7440799051921830202), -INT64_C( 6491372520516820966),  INT64_C(                   0) } },
    { UINT8_C(  0),
      { -INT64_C( 8767112038748657730), -INT64_C( 7052635034042790208), -INT64_C( 6603890804231331725), -INT64_C( 3131137631410272858) },
      { -INT64_C( 1591887663143957093),  INT64_C( 8922603379407992151), -INT64_C(  206750837837817474),  INT64_C( 1015076583748941132) },
      {  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0) } },
    { UINT8_C(231),
      {  INT64_C( 6842434063541616318), -INT64_C( 6075517079359538540),  INT64_C( 1270586480222899316),  INT64_C( 7380126505793994543) },
      {  INT64_C( 8872434914943821287), -INT64_C( 6662427551341978491), -INT64_C( 3648454390316234397),  INT64_C( 6544313852933680065) },
      { -INT64_C( 2731875095224114011),  INT64_C( 5708799443008034585), -INT64_C( 2377867910093335081),  INT64_C(                   0) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256i a = simde_x_mm256_loadu_epi64(test_vec[i].a);
    simde__m256i b = simde_x_mm256_loadu_epi64(test_vec[i].b);
    simde__m256i r = simde_mm256_maskz_add_epi64(test_vec[i].k, a, b);
    simde_test_x86_assert_equal_i64x4(r, simde_x_mm256_loadu_epi64(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_mm512_add_epi8 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    const int8_t a[64];
    const int8_t b[64];
    const int8_t r[64];
  } test_vec[] = {
    { {  INT8_C(  16), -INT8_C(  23), -INT8_C(  42), -INT8_C( 110), -INT8_C(  66), -INT8_C(  42),  INT8_C(  81), -INT8_C( 107),
        -INT8_C(  64), -INT8_C(  89),  INT8_C( 109),  INT8_C(  69),  INT8_C(  32), -INT8_C(  26), -INT8_C(  52), -INT8_C( 121),
        -INT8_C(  91), -INT8_C( 119),  INT8_C(  20), -INT8_C( 127),  INT8_C(  41), -INT8_C(  19),  INT8_C(  18),  INT8_C(   3),
         INT8_C( 103),  INT8_C( 122),  INT8_C(  63), -INT8_C(  75),  INT8_C(  40), -INT8_C(  38), -INT8_C(  44),  INT8_C(  56),
        -INT8_C(  61), -INT8_C(  86), -INT8_C(  54), -INT8_C( 127),      INT8_MIN,  INT8_C(  27),  INT8_C(  22),  INT8_C(  64),
        -INT8_C(  61), -INT8_C( 125), -INT8_C( 122), -INT8_C(  29),  INT8_C( 105),  INT8_C(  82),  INT8_C( 106),  INT8_C(  14),
        -INT8_C(  37),  INT8_C( 126), -INT8_C( 113),  INT8_C(   5),  INT8_C( 107), -INT8_C(  95),  INT8_C(   8), -INT8_C(  46),
         INT8_C(  27),  INT8_C(  71), -INT8_C( 120),  INT8_C(  67),  INT8_C(  33),  INT8_C(  92),  INT8_C( 124), -INT8_C(  28) },
      {  INT8_C(   6),  INT8_C(  70),  INT8_C( 101), -INT8_C( 122),  INT8_C(  98),  INT8_C( 123), -INT8_C(  58),  INT8_C(  37),
        -INT8_C(   1),  INT8_C(  76),  INT8_C(   8),  INT8_C( 104), -INT8_C(  98),  INT8_C( 114),  INT8_C( 119),  INT8_C( 122),
        -INT8_C(  16),  INT8_C(   6),      INT8_MAX,  INT8_C(  91), -INT8_C(  88), -INT8_C( 121),  INT8_C(  45), -INT8_C(  61),
        -INT8_C(  50), -INT8_C(  75),  INT8_C(   7), -INT8_C(  17),  INT8_C(  17), -INT8_C( 125), -INT8_C(  45),  INT8_C(  23),
        -INT8_C(  55),  INT8_C(  56), -INT8_C(  99),  INT8_C(  43), -INT8_C(  77),  INT8_C( 100),  INT8_C(  80), -INT8_C(  78),
        -INT8_C(  80),  INT8_C(  88),  INT8_C(  27),  INT8_C(  79), -INT8_C(  54), -INT8_C( 110), -INT8_C(  55), -INT8_C(  70),
        -INT8_C( 104),  INT8_C(  72),  INT8_C(  21),  INT8_C(  64), -INT8_C(  49),  INT8_C(  67),  INT8_C(   4), -INT8_C(  99),
        -INT8_C(   8),  INT8_C(  11), -INT8_C( 116),  INT8_C(  10), -INT8_C( 114),  INT8_C(  95),  INT8_C(  33),  INT8_C(  87) },
      {  INT8_C(  22),  INT8_C(  47),  INT8_C(  59),  INT8_C(  24),  INT8_C(  32),  INT8_C(  81),  INT8_C(  23), -INT8_C(  70),
        -INT8_C(  65), -INT8_C(  13),  INT8_C( 117), -INT8_C(  83), -INT8_C(  66),  INT8_C(  88),  INT8_C(  67),  INT8_C(   1),
        -INT8_C( 107), -INT8_C( 113), -INT8_C( 109), -INT8_C(  36), -INT8_C(  47),  INT8_C( 116),  INT8_C(  63), -INT8_C(  58),
         INT8_C(  53),  INT8_C(  47),  INT8_C(  70), -INT8_C(  92),  INT8_C(  57),  INT8_C(  93), -INT8_C(  89),  INT8_C(  79),
        -INT8_C( 116), -INT8_C(  30),  INT8_C( 103), -INT8_C(  84),  INT8_C(  51),      INT8_MAX,  INT8_C( 102), -INT8_C(  14),
         INT8_C( 115), -INT8_C(  37), -INT8_C(  95),  INT8_C(  50),  INT8_C(  51), -INT8_C(  28),  INT8_C(  51), -INT8_C(  56),
         INT8_C( 115), -INT8_C(  58), -INT8_C(  92),  INT8_C(  69),  INT8_C(  58), -INT8_C(  28),  INT8_C(  12),  INT8_C( 111),
         INT8_C(  19),  INT8_C(  82),  INT8_C(  20),  INT8_C(  77), -INT8_C(  81), -INT8_C(  69), -INT8_C(  99),  INT8_C(  59) } },
    { { -INT8_C( 105), -INT8_C(  65), -INT8_C( 125),  INT8_C(  74),  INT8_C(  35), -INT8_C(  45), -INT8_C(   3), -INT8_C(  45),
         INT8_C(  44),  INT8_C(  24),  INT8_C(  34), -INT8_C(  10), -INT8_C(  86), -INT8_C(  21), -INT8_C(  79),  INT8_C(  66),
         INT8_C(  51), -INT8_C(  58), -INT8_C( 125),  INT8_C(   2),  INT8_C(   9), -INT8_C( 121), -INT8_C(  97),  INT8_C(   2),
        -INT8_C( 110),  INT8_C(  43),  INT8_C(  12),  INT8_C(  32), -INT8_C( 118),  INT8_C(  45),  INT8_C( 119),  INT8_C(  33),
        -INT8_C(  20), -INT8_C(   6),  INT8_C( 108),  INT8_C(  15), -INT8_C(  50),  INT8_C( 105), -INT8_C(  29), -INT8_C(   6),
        -INT8_C( 127),  INT8_C(   5), -INT8_C(  16),  INT8_C(  43), -INT8_C(  15), -INT8_C(  95),  INT8_C( 109),  INT8_C(  36),
         INT8_C( 104), -INT8_C(  16),  INT8_C(  39),  INT8_C( 113),  INT8_C( 119), -INT8_C(  58),  INT8_C( 115),  INT8_C(   9),
        -INT8_C(  14),      INT8_MAX,  INT8_C(  41),  INT8_C( 124), -INT8_C(  83), -INT8_C(  95), -INT8_C(  98), -INT8_C( 103) },
      { -INT8_C( 101),  INT8_C(  10), -INT8_C(  87),  INT8_C( 105),  INT8_C( 115), -INT8_C( 116),  INT8_C(  99), -INT8_C(  12),
        -INT8_C( 111),  INT8_C(  84),  INT8_C(  31), -INT8_C( 126), -INT8_C(  11), -INT8_C( 116), -INT8_C(  89),  INT8_C(  93),
         INT8_C( 125), -INT8_C(  50), -INT8_C(  49), -INT8_C(  12), -INT8_C( 108),  INT8_C(  66), -INT8_C(   2), -INT8_C( 122),
        -INT8_C(  62),  INT8_C(  39),  INT8_C(   3),  INT8_C( 111), -INT8_C(  56), -INT8_C(  95),  INT8_C(   8),  INT8_C( 100),
        -INT8_C(  85), -INT8_C(  79), -INT8_C(  51),  INT8_C(  30),  INT8_C(  61),  INT8_C(  49),  INT8_C(  18), -INT8_C(  49),
        -INT8_C( 123),  INT8_C(  49),  INT8_C(  81),  INT8_C( 122), -INT8_C(  67), -INT8_C(   8), -INT8_C(  40),  INT8_C(  58),
        -INT8_C(  58), -INT8_C(  89),  INT8_C(  47),  INT8_C(  91), -INT8_C(  23),  INT8_C(  45), -INT8_C(  31), -INT8_C(  85),
         INT8_C(  84), -INT8_C(  28),  INT8_C(  26),  INT8_C(  29), -INT8_C( 123),  INT8_C(  35), -INT8_C( 127),  INT8_C(  48) },
      {  INT8_C(  50), -INT8_C(  55),  INT8_C(  44), -INT8_C(  77), -INT8_C( 106),  INT8_C(  95),  INT8_C(  96), -INT8_C(  57),
        -INT8_C(  67),  INT8_C( 108),  INT8_C(  65),  INT8_C( 120), -INT8_C(  97),  INT8_C( 119),  INT8_C(  88), -INT8_C(  97),
        -INT8_C(  80), -INT8_C( 108),  INT8_C(  82), -INT8_C(  10), -INT8_C(  99), -INT8_C(  55), -INT8_C(  99), -INT8_C( 120),
         INT8_C(  84),  INT8_C(  82),  INT8_C(  15), -INT8_C( 113),  INT8_C(  82), -INT8_C(  50),      INT8_MAX, -INT8_C( 123),
        -INT8_C( 105), -INT8_C(  85),  INT8_C(  57),  INT8_C(  45),  INT8_C(  11), -INT8_C( 102), -INT8_C(  11), -INT8_C(  55),
         INT8_C(   6),  INT8_C(  54),  INT8_C(  65), -INT8_C(  91), -INT8_C(  82), -INT8_C( 103),  INT8_C(  69),  INT8_C(  94),
         INT8_C(  46), -INT8_C( 105),  INT8_C(  86), -INT8_C(  52),  INT8_C(  96), -INT8_C(  13),  INT8_C(  84), -INT8_C(  76),
         INT8_C(  70),  INT8_C(  99),  INT8_C(  67), -INT8_C( 103),  INT8_C(  50), -INT8_C(  60),  INT8_C(  31), -INT8_C(  55) } },
    { { -INT8_C(  44),  INT8_C(  78),  INT8_C(  78),  INT8_C(  18),      INT8_MAX,  INT8_C(  96), -INT8_C(  31),  INT8_C(   4),
        -INT8_C( 111),  INT8_C(  50),      INT8_MAX,  INT8_C(  79),  INT8_C(  43),  INT8_C(  87), -INT8_C( 119), -INT8_C(  15),
        -INT8_C(   2), -INT8_C(  72),  INT8_C(  76), -INT8_C(  25), -INT8_C(  27),  INT8_C(  46), -INT8_C( 109),  INT8_C(  58),
         INT8_C(  18), -INT8_C(  83),  INT8_C(  87), -INT8_C( 104), -INT8_C(  48), -INT8_C(  40), -INT8_C(  56), -INT8_C(  91),
         INT8_C(  38),  INT8_C(  23), -INT8_C(  73), -INT8_C(  90),  INT8_C( 119), -INT8_C( 104), -INT8_C(  86),  INT8_C(   9),
        -INT8_C(  54),  INT8_C(  41),  INT8_C(  88), -INT8_C(  11),      INT8_MIN, -INT8_C(  31), -INT8_C(  25),  INT8_C( 126),
        -INT8_C( 102),  INT8_C(  51),  INT8_C( 102),      INT8_MAX,  INT8_C(  97), -INT8_C(   7), -INT8_C(  71),  INT8_C( 116),
        -INT8_C(  90),  INT8_C(  16),  INT8_C(  12),  INT8_C( 119), -INT8_C(  24), -INT8_C(  44),  INT8_C(  28),  INT8_C(  15) },
      { -INT8_C(  21), -INT8_C(  45), -INT8_C(  75),  INT8_C(  99),  INT8_C( 107),  INT8_C(  95),  INT8_C( 108),  INT8_C(  53),
        -INT8_C( 119), -INT8_C(  60),  INT8_C(  43),  INT8_C(   9), -INT8_C(  91),  INT8_C(  18), -INT8_C( 120),  INT8_C(  63),
         INT8_C(  69), -INT8_C(  18), -INT8_C(  65), -INT8_C(  89), -INT8_C(  25),  INT8_C( 120),  INT8_C(  27), -INT8_C( 115),
        -INT8_C( 119),  INT8_C(  39),  INT8_C(   4),  INT8_C( 113), -INT8_C(   5),  INT8_C(  32),      INT8_MIN, -INT8_C(  25),
        -INT8_C(  13),  INT8_C(  53),  INT8_C(  74),  INT8_C(  94), -INT8_C( 107), -INT8_C(  74), -INT8_C( 108),  INT8_C(  30),
         INT8_C( 122), -INT8_C(  65),  INT8_C(  39),  INT8_C(  31), -INT8_C(  47), -INT8_C(  81),  INT8_C(  95),  INT8_C(  22),
        -INT8_C(  99),  INT8_C(  30), -INT8_C(  67), -INT8_C( 124), -INT8_C( 106), -INT8_C(  40),  INT8_C(  18),  INT8_C(  31),
        -INT8_C(   1),  INT8_C(  22), -INT8_C( 111), -INT8_C(   5),  INT8_C(  55),  INT8_C(  17), -INT8_C(  30),  INT8_C(  42) },
      { -INT8_C(  65),  INT8_C(  33),  INT8_C(   3),  INT8_C( 117), -INT8_C(  22), -INT8_C(  65),  INT8_C(  77),  INT8_C(  57),
         INT8_C(  26), -INT8_C(  10), -INT8_C(  86),  INT8_C(  88), -INT8_C(  48),  INT8_C( 105),  INT8_C(  17),  INT8_C(  48),
         INT8_C(  67), -INT8_C(  90),  INT8_C(  11), -INT8_C( 114), -INT8_C(  52), -INT8_C(  90), -INT8_C(  82), -INT8_C(  57),
        -INT8_C( 101), -INT8_C(  44),  INT8_C(  91),  INT8_C(   9), -INT8_C(  53), -INT8_C(   8),  INT8_C(  72), -INT8_C( 116),
         INT8_C(  25),  INT8_C(  76),  INT8_C(   1),  INT8_C(   4),  INT8_C(  12),  INT8_C(  78),  INT8_C(  62),  INT8_C(  39),
         INT8_C(  68), -INT8_C(  24),      INT8_MAX,  INT8_C(  20),  INT8_C(  81), -INT8_C( 112),  INT8_C(  70), -INT8_C( 108),
         INT8_C(  55),  INT8_C(  81),  INT8_C(  35),  INT8_C(   3), -INT8_C(   9), -INT8_C(  47), -INT8_C(  53), -INT8_C( 109),
        -INT8_C(  91),  INT8_C(  38), -INT8_C(  99),  INT8_C( 114),  INT8_C(  31), -INT8_C(  27), -INT8_C(   2),  INT8_C(  57) } },
    { {  INT8_C(  71),  INT8_C(  44), -INT8_C( 119), -INT8_C(  36), -INT8_C(  30),  INT8_C(  29), -INT8_C(   6),  INT8_C(  92),
        -INT8_C(  36),  INT8_C(  33),  INT8_C( 123), -INT8_C(  83), -INT8_C(  47), -INT8_C(  38), -INT8_C(  61),  INT8_C( 110),
        -INT8_C(   8), -INT8_C( 127), -INT8_C(  13), -INT8_C( 113),  INT8_C(  89),  INT8_C(   5), -INT8_C(  82),  INT8_C(  89),
         INT8_C(  27),  INT8_C(  63),  INT8_C(  84),  INT8_C(  82),  INT8_C(  81),  INT8_C(  54),  INT8_C( 125), -INT8_C( 104),
         INT8_C(  98),  INT8_C(   6),  INT8_C( 116),  INT8_C(  68),  INT8_C(  35),  INT8_C( 110), -INT8_C(  96), -INT8_C(   1),
        -INT8_C( 113),  INT8_C(  27), -INT8_C(  84),  INT8_C(  96), -INT8_C(  10),  INT8_C( 111), -INT8_C(  49), -INT8_C(  18),
        -INT8_C(  16), -INT8_C(  62),  INT8_C( 125),  INT8_C(  74), -INT8_C(  57),  INT8_C(  44), -INT8_C(  93), -INT8_C(  30),
         INT8_C( 107), -INT8_C(   9),  INT8_C(  53), -INT8_C(  68),  INT8_C(  45), -INT8_C(  78),  INT8_C(  84), -INT8_C( 113) },
      { -INT8_C(  72), -INT8_C(  56), -INT8_C(  45), -INT8_C(  37),  INT8_C(  54),  INT8_C( 115), -INT8_C(  38), -INT8_C(  58),
        -INT8_C( 114), -INT8_C( 122),  INT8_C(  38), -INT8_C( 124), -INT8_C(  11), -INT8_C(  11),  INT8_C( 115), -INT8_C(  26),
        -INT8_C(  73), -INT8_C(  16),  INT8_C(  48),  INT8_C( 126),  INT8_C(  28), -INT8_C(  45),  INT8_C(  97), -INT8_C( 120),
        -INT8_C(  54), -INT8_C( 106),  INT8_C(  68), -INT8_C(   9),  INT8_C(  72), -INT8_C( 103), -INT8_C( 122),  INT8_C(   0),
         INT8_C(  97),  INT8_C(  89), -INT8_C(  37), -INT8_C( 104), -INT8_C(  52), -INT8_C(  75),  INT8_C(  94),  INT8_C(  90),
         INT8_C(  59), -INT8_C( 124), -INT8_C(  33),  INT8_C(  48),  INT8_C( 122),  INT8_C(  82),  INT8_C(  22),  INT8_C(  49),
         INT8_C(  66),  INT8_C(  70), -INT8_C(  80),  INT8_C(  95),  INT8_C(  25),  INT8_C(  17), -INT8_C(  25), -INT8_C(  29),
        -INT8_C(  89),  INT8_C(  43), -INT8_C(  38), -INT8_C(  17), -INT8_C(  60),  INT8_C(  96), -INT8_C(  17),  INT8_C(  38) },
      { -INT8_C(   1), -INT8_C(  12),  INT8_C(  92), -INT8_C(  73),  INT8_C(  24), -INT8_C( 112), -INT8_C(  44),  INT8_C(  34),
         INT8_C( 106), -INT8_C(  89), -INT8_C(  95),  INT8_C(  49), -INT8_C(  58), -INT8_C(  49),  INT8_C(  54),  INT8_C(  84),
        -INT8_C(  81),  INT8_C( 113),  INT8_C(  35),  INT8_C(  13),  INT8_C( 117), -INT8_C(  40),  INT8_C(  15), -INT8_C(  31),
        -INT8_C(  27), -INT8_C(  43), -INT8_C( 104),  INT8_C(  73), -INT8_C( 103), -INT8_C(  49),  INT8_C(   3), -INT8_C( 104),
        -INT8_C(  61),  INT8_C(  95),  INT8_C(  79), -INT8_C(  36), -INT8_C(  17),  INT8_C(  35), -INT8_C(   2),  INT8_C(  89),
        -INT8_C(  54), -INT8_C(  97), -INT8_C( 117), -INT8_C( 112),  INT8_C( 112), -INT8_C(  63), -INT8_C(  27),  INT8_C(  31),
         INT8_C(  50),  INT8_C(   8),  INT8_C(  45), -INT8_C(  87), -INT8_C(  32),  INT8_C(  61), -INT8_C( 118), -INT8_C(  59),
         INT8_C(  18),  INT8_C(  34),  INT8_C(  15), -INT8_C(  85), -INT8_C(  15),  INT8_C(  18),  INT8_C(  67), -INT8_C(  75) } },
    { { -INT8_C(  71), -INT8_C(  54), -INT8_C(  66), -INT8_C( 123),      INT8_MAX,  INT8_C(  28), -INT8_C(  32), -INT8_C(  70),
        -INT8_C(  96), -INT8_C(  65), -INT8_C(  22),  INT8_C(  26),  INT8_C(  17),  INT8_C(   1),  INT8_C(  76),  INT8_C(  83),
         INT8_C(  71), -INT8_C(   4), -INT8_C(  78),  INT8_C(  97),  INT8_C(  13), -INT8_C( 103),  INT8_C(  68), -INT8_C(  76),
        -INT8_C(  59),  INT8_C(  31), -INT8_C(  93), -INT8_C( 119),      INT8_MAX, -INT8_C( 110), -INT8_C(  81),  INT8_C(  57),
         INT8_C(  92),  INT8_C( 109), -INT8_C(  66), -INT8_C(  37), -INT8_C( 119), -INT8_C(  98), -INT8_C( 107),  INT8_C(  42),
         INT8_C(  93),      INT8_MAX,  INT8_C(  68),  INT8_C( 110),      INT8_MIN, -INT8_C( 112), -INT8_C(  62), -INT8_C(  56),
        -INT8_C( 116),  INT8_C( 116),  INT8_C(  41), -INT8_C( 103),  INT8_C(  14),  INT8_C( 109),  INT8_C(  77), -INT8_C(  45),
        -INT8_C( 116), -INT8_C(  16),  INT8_C(  92),  INT8_C(  12), -INT8_C( 126),  INT8_C(  12),  INT8_C(  69), -INT8_C(  34) },
      {  INT8_C( 121),  INT8_C(   3), -INT8_C(  71),  INT8_C(   3), -INT8_C(  94),  INT8_C(  78),  INT8_C(  45), -INT8_C(   1),
        -INT8_C(  50),  INT8_C( 113),  INT8_C( 110),  INT8_C(  78),  INT8_C(   2),  INT8_C(  48),  INT8_C(  22), -INT8_C( 114),
        -INT8_C(  92),  INT8_C(  63),  INT8_C(  40), -INT8_C(  78), -INT8_C(  83),  INT8_C( 117), -INT8_C( 123),  INT8_C(  57),
         INT8_C( 102), -INT8_C(  30),  INT8_C(  69), -INT8_C(  24), -INT8_C(  18), -INT8_C( 118), -INT8_C(  57),  INT8_C( 103),
        -INT8_C( 114),      INT8_MIN,  INT8_C( 106),  INT8_C(  48), -INT8_C(  49), -INT8_C( 105),  INT8_C(  47), -INT8_C(  99),
         INT8_C(   9), -INT8_C(  99), -INT8_C(  21),  INT8_C(  11), -INT8_C(  51),  INT8_C(   2), -INT8_C( 103),  INT8_C( 114),
         INT8_C(  65), -INT8_C(  63),  INT8_C(  36), -INT8_C(  18),  INT8_C(  55), -INT8_C(  86),  INT8_C(  40), -INT8_C(  99),
        -INT8_C( 116),  INT8_C( 109), -INT8_C( 123),  INT8_C( 122), -INT8_C(   8),  INT8_C(  76), -INT8_C(  31), -INT8_C( 122) },
      {  INT8_C(  50), -INT8_C(  51),  INT8_C( 119), -INT8_C( 120),  INT8_C(  33),  INT8_C( 106),  INT8_C(  13), -INT8_C(  71),
         INT8_C( 110),  INT8_C(  48),  INT8_C(  88),  INT8_C( 104),  INT8_C(  19),  INT8_C(  49),  INT8_C(  98), -INT8_C(  31),
        -INT8_C(  21),  INT8_C(  59), -INT8_C(  38),  INT8_C(  19), -INT8_C(  70),  INT8_C(  14), -INT8_C(  55), -INT8_C(  19),
         INT8_C(  43),  INT8_C(   1), -INT8_C(  24),  INT8_C( 113),  INT8_C( 109),  INT8_C(  28),  INT8_C( 118), -INT8_C(  96),
        -INT8_C(  22), -INT8_C(  19),  INT8_C(  40),  INT8_C(  11),  INT8_C(  88),  INT8_C(  53), -INT8_C(  60), -INT8_C(  57),
         INT8_C( 102),  INT8_C(  28),  INT8_C(  47),  INT8_C( 121),  INT8_C(  77), -INT8_C( 110),  INT8_C(  91),  INT8_C(  58),
        -INT8_C(  51),  INT8_C(  53),  INT8_C(  77), -INT8_C( 121),  INT8_C(  69),  INT8_C(  23),  INT8_C( 117),  INT8_C( 112),
         INT8_C(  24),  INT8_C(  93), -INT8_C(  31), -INT8_C( 122),  INT8_C( 122),  INT8_C(  88),  INT8_C(  38),  INT8_C( 100) } },
    { { -INT8_C(  51),  INT8_C(  76), -INT8_C(  74), -INT8_C( 100), -INT8_C(  29), -INT8_C(  27),  INT8_C(  57), -INT8_C(  20),
        -INT8_C( 125),  INT8_C(  36), -INT8_C(   9),  INT8_C(  80),  INT8_C(  38), -INT8_C( 111), -INT8_C(  62),  INT8_C( 104),
         INT8_C(  82), -INT8_C(  25),  INT8_C(  86), -INT8_C( 119), -INT8_C( 111),  INT8_C( 126),  INT8_C(  38),  INT8_C(  29),
        -INT8_C(  20), -INT8_C(  84), -INT8_C( 105), -INT8_C(  28), -INT8_C(   8),  INT8_C( 120),  INT8_C( 106), -INT8_C(  59),
        -INT8_C(  60),  INT8_C(  32),  INT8_C(  97), -INT8_C(  88),  INT8_C(   5), -INT8_C( 102), -INT8_C( 108), -INT8_C( 120),
        -INT8_C(  65), -INT8_C( 116), -INT8_C(  39), -INT8_C(  27),  INT8_C(  29), -INT8_C( 101),  INT8_C(  77),  INT8_C( 111),
        -INT8_C( 126), -INT8_C(  92), -INT8_C(   7),  INT8_C(  19),  INT8_C(  34),  INT8_C(  31),  INT8_C(  48),  INT8_C(  14),
        -INT8_C(  53), -INT8_C(  57), -INT8_C(  14), -INT8_C(  60),  INT8_C(  64),  INT8_C(  92), -INT8_C( 119),  INT8_C(   4) },
      {  INT8_C( 124), -INT8_C(  21), -INT8_C(  84), -INT8_C( 126), -INT8_C( 123),  INT8_C(  65),  INT8_C(  10),  INT8_C(  68),
        -INT8_C(  51), -INT8_C(  29),  INT8_C(  42), -INT8_C(  22),      INT8_MAX,  INT8_C( 119),  INT8_C(  89),  INT8_C(   1),
         INT8_C(  27),  INT8_C(  82),  INT8_C(  21),  INT8_C(  62),  INT8_C( 114),  INT8_C(  69),  INT8_C(  76),  INT8_C(  61),
         INT8_C(  13),  INT8_C(  63),  INT8_C(   1),  INT8_C(  77), -INT8_C( 101), -INT8_C( 117),  INT8_C(  81),  INT8_C(  24),
         INT8_C( 118), -INT8_C(   2), -INT8_C( 102), -INT8_C(   5),  INT8_C(  63), -INT8_C(  92),  INT8_C(  64),  INT8_C(  12),
        -INT8_C( 120),  INT8_C( 106), -INT8_C(  10),  INT8_C(   7), -INT8_C(  31),  INT8_C(  79),  INT8_C(   8), -INT8_C(   3),
        -INT8_C(  94),  INT8_C(  29),  INT8_C(  59),  INT8_C(  20),  INT8_C(  99), -INT8_C( 121),  INT8_C(  81),  INT8_C( 112),
        -INT8_C(  58),  INT8_C(  83), -INT8_C(  67),  INT8_C(  98), -INT8_C(  34),  INT8_C(  14),  INT8_C( 122),  INT8_C(  84) },
      {  INT8_C(  73),  INT8_C(  55),  INT8_C(  98),  INT8_C(  30),  INT8_C( 104),  INT8_C(  38),  INT8_C(  67),  INT8_C(  48),
         INT8_C(  80),  INT8_C(   7),  INT8_C(  33),  INT8_C(  58), -INT8_C(  91),  INT8_C(   8),  INT8_C(  27),  INT8_C( 105),
         INT8_C( 109),  INT8_C(  57),  INT8_C( 107), -INT8_C(  57),  INT8_C(   3), -INT8_C(  61),  INT8_C( 114),  INT8_C(  90),
        -INT8_C(   7), -INT8_C(  21), -INT8_C( 104),  INT8_C(  49), -INT8_C( 109),  INT8_C(   3), -INT8_C(  69), -INT8_C(  35),
         INT8_C(  58),  INT8_C(  30), -INT8_C(   5), -INT8_C(  93),  INT8_C(  68),  INT8_C(  62), -INT8_C(  44), -INT8_C( 108),
         INT8_C(  71), -INT8_C(  10), -INT8_C(  49), -INT8_C(  20), -INT8_C(   2), -INT8_C(  22),  INT8_C(  85),  INT8_C( 108),
         INT8_C(  36), -INT8_C(  63),  INT8_C(  52),  INT8_C(  39), -INT8_C( 123), -INT8_C(  90), -INT8_C( 127),  INT8_C( 126),
        -INT8_C( 111),  INT8_C(  26), -INT8_C(  81),  INT8_C(  38),  INT8_C(  30),  INT8_C( 106),  INT8_C(   3),  INT8_C(  88) } },
    { {  INT8_C(  12),  INT8_C(  20),  INT8_C(  79),  INT8_C(  75), -INT8_C(  72), -INT8_C( 113),  INT8_C(  87),  INT8_C(  64),
        -INT8_C(   7),  INT8_C(  77),  INT8_C(  71), -INT8_C(  37), -INT8_C(  99),  INT8_C(  80), -INT8_C(  40),  INT8_C(  63),
         INT8_C( 109),  INT8_C(  19),  INT8_C(  83), -INT8_C(  48), -INT8_C( 102), -INT8_C(  92),  INT8_C(  64),  INT8_C(  97),
        -INT8_C(   9), -INT8_C(   3), -INT8_C(  61), -INT8_C(  43),  INT8_C(  12),  INT8_C(  61),  INT8_C(  41),  INT8_C(  24),
         INT8_C(  81),  INT8_C( 121),  INT8_C( 100),  INT8_C(   9),  INT8_C(   8), -INT8_C(  69),  INT8_C(  74),  INT8_C(   2),
         INT8_C(   9), -INT8_C( 111), -INT8_C(  35), -INT8_C(  90), -INT8_C(  31), -INT8_C(  75), -INT8_C(  27),  INT8_C(  79),
        -INT8_C(  56),  INT8_C(  56),  INT8_C(  31),  INT8_C(  98), -INT8_C(  36),  INT8_C(  96), -INT8_C(  61), -INT8_C(  44),
         INT8_C(  93), -INT8_C( 122), -INT8_C(  87),  INT8_C( 105), -INT8_C(  61), -INT8_C(  45), -INT8_C( 126),  INT8_C(  20) },
      {  INT8_C(  76), -INT8_C(  26),  INT8_C(  30),  INT8_C(  84), -INT8_C(  95),  INT8_C( 104),  INT8_C(  86), -INT8_C(  86),
        -INT8_C(   7),  INT8_C(  51),  INT8_C(  80), -INT8_C(  37), -INT8_C(  24),  INT8_C(  53),  INT8_C(  42), -INT8_C(  80),
         INT8_C( 109),  INT8_C(  73),  INT8_C(  19),  INT8_C(  74), -INT8_C(  87), -INT8_C(  42),  INT8_C(  30),  INT8_C(   7),
         INT8_C(  93), -INT8_C(  57),  INT8_C( 112),  INT8_C(  32), -INT8_C( 102), -INT8_C(  14),  INT8_C(  53), -INT8_C(  26),
        -INT8_C(  40),  INT8_C(  83),  INT8_C(  59),  INT8_C( 122), -INT8_C(  69), -INT8_C( 111),  INT8_C(  36), -INT8_C(  76),
        -INT8_C(  59),  INT8_C( 117), -INT8_C( 113), -INT8_C(  83), -INT8_C(  86), -INT8_C(  71),  INT8_C(  94),  INT8_C(  24),
         INT8_C(   3),  INT8_C( 113),  INT8_C(  98), -INT8_C(  84),  INT8_C(  71),      INT8_MIN, -INT8_C(  77), -INT8_C(  92),
         INT8_C(  71),  INT8_C(  36), -INT8_C(  59), -INT8_C(  30),  INT8_C(  22), -INT8_C(   6), -INT8_C(  56), -INT8_C(  17) },
      {  INT8_C(  88), -INT8_C(   6),  INT8_C( 109), -INT8_C(  97),  INT8_C(  89), -INT8_C(   9), -INT8_C(  83), -INT8_C(  22),
        -INT8_C(  14),      INT8_MIN, -INT8_C( 105), -INT8_C(  74), -INT8_C( 123), -INT8_C( 123),  INT8_C(   2), -INT8_C(  17),
        -INT8_C(  38),  INT8_C(  92),  INT8_C( 102),  INT8_C(  26),  INT8_C(  67),  INT8_C( 122),  INT8_C(  94),  INT8_C( 104),
         INT8_C(  84), -INT8_C(  60),  INT8_C(  51), -INT8_C(  11), -INT8_C(  90),  INT8_C(  47),  INT8_C(  94), -INT8_C(   2),
         INT8_C(  41), -INT8_C(  52), -INT8_C(  97), -INT8_C( 125), -INT8_C(  61),  INT8_C(  76),  INT8_C( 110), -INT8_C(  74),
        -INT8_C(  50),  INT8_C(   6),  INT8_C( 108),  INT8_C(  83), -INT8_C( 117),  INT8_C( 110),  INT8_C(  67),  INT8_C( 103),
        -INT8_C(  53), -INT8_C(  87), -INT8_C( 127),  INT8_C(  14),  INT8_C(  35), -INT8_C(  32),  INT8_C( 118),  INT8_C( 120),
        -INT8_C(  92), -INT8_C(  86),  INT8_C( 110),  INT8_C(  75), -INT8_C(  39), -INT8_C(  51),  INT8_C(  74),  INT8_C(   3) } },
    { {  INT8_C(  77),  INT8_C(   3),  INT8_C( 105),  INT8_C(   8), -INT8_C( 107), -INT8_C( 115), -INT8_C(  68),  INT8_C(  90),
         INT8_C(   2),  INT8_C(  76),  INT8_C(   7), -INT8_C(  83),  INT8_C(   5),  INT8_C( 101), -INT8_C(  59),  INT8_C(   8),
        -INT8_C(  42),  INT8_C(  39), -INT8_C(  75),  INT8_C(  30), -INT8_C(  89),  INT8_C( 104), -INT8_C(  62), -INT8_C(  18),
        -INT8_C( 116), -INT8_C( 121), -INT8_C(  48), -INT8_C(  93), -INT8_C( 127), -INT8_C( 103), -INT8_C( 110), -INT8_C(  50),
        -INT8_C( 100), -INT8_C(   5), -INT8_C(  42),  INT8_C(  49), -INT8_C( 120), -INT8_C( 109), -INT8_C( 117), -INT8_C( 117),
        -INT8_C(  33), -INT8_C( 109),  INT8_C(  56), -INT8_C(  28), -INT8_C(   8), -INT8_C(   3), -INT8_C(  19), -INT8_C(  49),
         INT8_C(  36), -INT8_C(  94), -INT8_C(  19), -INT8_C(  53),  INT8_C(  10), -INT8_C(  81), -INT8_C(  71), -INT8_C( 105),
         INT8_C(  55), -INT8_C( 118),  INT8_C(  58), -INT8_C(  72),  INT8_C(  35), -INT8_C(  52), -INT8_C( 121), -INT8_C(  65) },
      { -INT8_C(  57),  INT8_C(  93), -INT8_C(  15),  INT8_C(  79), -INT8_C(  16),  INT8_C( 124), -INT8_C(  38), -INT8_C(  49),
         INT8_C(  15),  INT8_C(  18), -INT8_C(  76),  INT8_C(   8),  INT8_C(  15), -INT8_C(  95), -INT8_C(  41),  INT8_C(  51),
         INT8_C(  67), -INT8_C(  60), -INT8_C(   2),  INT8_C(  77),  INT8_C( 115), -INT8_C(  72), -INT8_C(  28), -INT8_C(  86),
         INT8_C(  66),  INT8_C(  30),  INT8_C(  99),  INT8_C( 101), -INT8_C(  22), -INT8_C(  22),  INT8_C(  36), -INT8_C(  79),
         INT8_C(  71),  INT8_C(  21),  INT8_C(   1),  INT8_C(  56), -INT8_C( 110), -INT8_C(  37),  INT8_C(   7), -INT8_C(  95),
        -INT8_C(  18), -INT8_C(  69), -INT8_C(  87), -INT8_C(   3),  INT8_C(  92),      INT8_MIN,  INT8_C(  49), -INT8_C(  97),
         INT8_C(  68),  INT8_C(  47), -INT8_C(  19), -INT8_C(  72), -INT8_C(  25), -INT8_C(  47),  INT8_C(  98),  INT8_C(  41),
        -INT8_C(  16), -INT8_C(  59), -INT8_C( 114), -INT8_C(  38), -INT8_C(  81), -INT8_C(  77), -INT8_C( 116), -INT8_C(   9) },
      {  INT8_C(  20),  INT8_C(  96),  INT8_C(  90),  INT8_C(  87), -INT8_C( 123),  INT8_C(   9), -INT8_C( 106),  INT8_C(  41),
         INT8_C(  17),  INT8_C(  94), -INT8_C(  69), -INT8_C(  75),  INT8_C(  20),  INT8_C(   6), -INT8_C( 100),  INT8_C(  59),
         INT8_C(  25), -INT8_C(  21), -INT8_C(  77),  INT8_C( 107),  INT8_C(  26),  INT8_C(  32), -INT8_C(  90), -INT8_C( 104),
        -INT8_C(  50), -INT8_C(  91),  INT8_C(  51),  INT8_C(   8),  INT8_C( 107), -INT8_C( 125), -INT8_C(  74),      INT8_MAX,
        -INT8_C(  29),  INT8_C(  16), -INT8_C(  41),  INT8_C( 105),  INT8_C(  26),  INT8_C( 110), -INT8_C( 110),  INT8_C(  44),
        -INT8_C(  51),  INT8_C(  78), -INT8_C(  31), -INT8_C(  31),  INT8_C(  84),  INT8_C( 125),  INT8_C(  30),  INT8_C( 110),
         INT8_C( 104), -INT8_C(  47), -INT8_C(  38), -INT8_C( 125), -INT8_C(  15),      INT8_MIN,  INT8_C(  27), -INT8_C(  64),
         INT8_C(  39),  INT8_C(  79), -INT8_C(  56), -INT8_C( 110), -INT8_C(  46),      INT8_MAX,  INT8_C(  19), -INT8_C(  74) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i a = simde_mm512_loadu_epi8(test_vec[i].a);
    simde__m512i b = simde_mm512_loadu_epi8(test_vec[i].b);
    simde__m512i r = simde_mm512_add_epi8(a, b);
    simde_test_x86_assert_equal_i8x64(r, simde_mm512_loadu_epi8(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_mm512_mask_add_epi8 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const int8_t src[64];
    const simde__mmask64 k;
    const int8_t a[64];
    const int8_t b[64];
    const int8_t r[64];
  } test_vec[] = {
    { {  INT8_C(  20), -INT8_C(  19),  INT8_C(  38),  INT8_C(  45), -INT8_C(  89), -INT8_C(  95),  INT8_C(  34), -INT8_C(   3),
        -INT8_C(  21),  INT8_C(  99), -INT8_C(  35),  INT8_C(  73),  INT8_C(   3), -INT8_C( 119),  INT8_C(   1), -INT8_C(   7),
        -INT8_C( 123), -INT8_C(  90),  INT8_C(  32),  INT8_C(  73), -INT8_C(  12), -INT8_C( 115), -INT8_C(  93),  INT8_C(  56),
         INT8_C( 116),  INT8_C(  96), -INT8_C(  89), -INT8_C( 108),  INT8_C(  46), -INT8_C(  17),  INT8_C(  92),  INT8_C(  67),
        -INT8_C(  35), -INT8_C( 125),  INT8_C( 112), -INT8_C( 124),  INT8_C(  36), -INT8_C( 110), -INT8_C( 127),  INT8_C(  15),
        -INT8_C(  11),  INT8_C(  95),  INT8_C(  88), -INT8_C(   8), -INT8_C(  24),  INT8_C(  89), -INT8_C(  14),  INT8_C( 109),
        -INT8_C(   1),  INT8_C(  18), -INT8_C(  73), -INT8_C(  13), -INT8_C(  97),  INT8_C(  90),  INT8_C(  43),  INT8_C(  19),
        -INT8_C(  69), -INT8_C(  45), -INT8_C(  88), -INT8_C(  23), -INT8_C(  62),  INT8_C(   4),  INT8_C(  44), -INT8_C(  97) },
      UINT64_C( 2646890825868614791),
      {  INT8_C(   4),  INT8_C(  19),  INT8_C(  28), -INT8_C(  20),  INT8_C( 109),  INT8_C(  14),  INT8_C(  90),  INT8_C( 108),
         INT8_C(  32),  INT8_C(  17),  INT8_C(  96), -INT8_C(  64),  INT8_C( 107), -INT8_C( 117), -INT8_C(  45),  INT8_C(  38),
         INT8_C(  94),  INT8_C( 123),  INT8_C(  16),  INT8_C(  33),      INT8_MIN,  INT8_C(  60), -INT8_C(  64),  INT8_C(   7),
        -INT8_C(  39), -INT8_C(  28), -INT8_C(  77),  INT8_C(   7), -INT8_C( 119),  INT8_C( 110),  INT8_C(  43), -INT8_C( 115),
        -INT8_C( 127),  INT8_C(  72),  INT8_C( 121), -INT8_C(  18),  INT8_C(  86), -INT8_C(  45),  INT8_C(  91),  INT8_C( 119),
        -INT8_C(  28), -INT8_C(  69),  INT8_C(  55),  INT8_C(  80),  INT8_C(  70),  INT8_C(  10),  INT8_C( 118), -INT8_C(  91),
        -INT8_C( 122), -INT8_C( 122), -INT8_C(  58),  INT8_C(   6), -INT8_C(  61), -INT8_C( 122),  INT8_C(  13), -INT8_C( 100),
         INT8_C( 106), -INT8_C(  64), -INT8_C(  93), -INT8_C(  13),  INT8_C(  46), -INT8_C(  49),      INT8_MIN, -INT8_C(  80) },
      {  INT8_C(  23), -INT8_C(   6), -INT8_C(  98),  INT8_C( 109), -INT8_C(  51), -INT8_C(   7), -INT8_C(  28), -INT8_C(  78),
        -INT8_C(  76),  INT8_C(  27),  INT8_C(   2), -INT8_C(   5),  INT8_C(  38),  INT8_C( 120), -INT8_C(  96), -INT8_C(  84),
        -INT8_C(   1),  INT8_C( 102), -INT8_C(  78), -INT8_C(  62), -INT8_C(  20), -INT8_C(  65),  INT8_C(  94),  INT8_C(  87),
             INT8_MIN,  INT8_C(   1),  INT8_C(  74), -INT8_C(  82), -INT8_C(  48), -INT8_C(  53),  INT8_C(  94), -INT8_C(  25),
        -INT8_C(  59), -INT8_C(   3),  INT8_C(  85), -INT8_C( 110), -INT8_C(  10),  INT8_C(  57),  INT8_C(  68), -INT8_C(  85),
         INT8_C(  85),  INT8_C(  70), -INT8_C(  90),  INT8_C( 123), -INT8_C(  65),  INT8_C(  70),  INT8_C(  39), -INT8_C(  66),
        -INT8_C(  84), -INT8_C(  39),      INT8_MIN, -INT8_C( 104), -INT8_C( 104), -INT8_C(  34), -INT8_C(  17),  INT8_C(  24),
        -INT8_C(  33),  INT8_C(  58), -INT8_C(  57), -INT8_C(  80),  INT8_C(   5),  INT8_C(  37), -INT8_C( 105), -INT8_C(  54) },
      {  INT8_C(  27),  INT8_C(  13), -INT8_C(  70),  INT8_C(  45), -INT8_C(  89), -INT8_C(  95),  INT8_C(  34),  INT8_C(  30),
        -INT8_C(  21),  INT8_C(  99),  INT8_C(  98), -INT8_C(  69), -INT8_C( 111), -INT8_C( 119),  INT8_C(   1), -INT8_C(  46),
         INT8_C(  93), -INT8_C(  31),  INT8_C(  32),  INT8_C(  73), -INT8_C(  12), -INT8_C(   5), -INT8_C(  93),  INT8_C(  56),
         INT8_C(  89), -INT8_C(  27), -INT8_C(  89), -INT8_C(  75),  INT8_C(  46),  INT8_C(  57),  INT8_C(  92),  INT8_C( 116),
        -INT8_C(  35),  INT8_C(  69), -INT8_C(  50),      INT8_MIN,  INT8_C(  36),  INT8_C(  12), -INT8_C( 127),  INT8_C(  15),
         INT8_C(  57),  INT8_C(  95), -INT8_C(  35), -INT8_C(   8), -INT8_C(  24),  INT8_C(  80), -INT8_C(  14),  INT8_C(  99),
         INT8_C(  50),  INT8_C(  95), -INT8_C(  73), -INT8_C(  98),  INT8_C(  91),  INT8_C( 100),  INT8_C(  43), -INT8_C(  76),
        -INT8_C(  69), -INT8_C(  45),  INT8_C( 106), -INT8_C(  23), -INT8_C(  62), -INT8_C(  12),  INT8_C(  44), -INT8_C(  97) } },
    { {  INT8_C(  34), -INT8_C(  20),  INT8_C(  92),  INT8_C(  25),  INT8_C(  38), -INT8_C(  95), -INT8_C(  60),  INT8_C( 123),
        -INT8_C(  25),  INT8_C( 106), -INT8_C(  10), -INT8_C(  90), -INT8_C(  80),  INT8_C(  29),  INT8_C( 100),  INT8_C(  92),
        -INT8_C(  10), -INT8_C(  28), -INT8_C(  12), -INT8_C( 114), -INT8_C(  62), -INT8_C(  28), -INT8_C(  89), -INT8_C(  94),
         INT8_C(  30),  INT8_C( 110),  INT8_C(  82),  INT8_C(  35), -INT8_C( 109), -INT8_C(  23), -INT8_C(  19), -INT8_C(  74),
        -INT8_C(  42),  INT8_C(  73), -INT8_C(  49), -INT8_C(   4), -INT8_C(  22), -INT8_C( 109),  INT8_C( 119), -INT8_C(  46),
        -INT8_C(   3),  INT8_C( 109),  INT8_C( 120), -INT8_C(  83), -INT8_C( 118), -INT8_C(  35),  INT8_C(   9),      INT8_MIN,
        -INT8_C(  63), -INT8_C(   3),  INT8_C(  14), -INT8_C( 124), -INT8_C(  31), -INT8_C(  75),  INT8_C(  38), -INT8_C(   1),
         INT8_C(  35),  INT8_C( 120),  INT8_C(  34), -INT8_C(  73),  INT8_C(  97),  INT8_C(  15),  INT8_C( 109),  INT8_C(  55) },
      UINT64_C(14705847965410606169),
      {  INT8_C(  23), -INT8_C( 114),  INT8_C( 121), -INT8_C(  95),  INT8_C( 107), -INT8_C( 126),  INT8_C(  33),  INT8_C(  44),
             INT8_MAX,  INT8_C(  48), -INT8_C(  80),  INT8_C(  97), -INT8_C(  27), -INT8_C(  42),  INT8_C(  96),  INT8_C(   9),
         INT8_C(  78), -INT8_C( 125), -INT8_C(  64), -INT8_C(  80), -INT8_C( 110),  INT8_C(  45), -INT8_C(  25), -INT8_C(  21),
         INT8_C( 105),  INT8_C(  27),  INT8_C(  47),  INT8_C(  56), -INT8_C(  59),  INT8_C(  68),  INT8_C(   4), -INT8_C(  35),
        -INT8_C(  46),  INT8_C( 125),  INT8_C( 126),  INT8_C(  61), -INT8_C(   1), -INT8_C(  96),  INT8_C( 106),  INT8_C( 126),
        -INT8_C(  48),  INT8_C(  26), -INT8_C(  33), -INT8_C(  75), -INT8_C(  15),  INT8_C(  64), -INT8_C(  66),  INT8_C(  63),
        -INT8_C(  61),  INT8_C( 126), -INT8_C(  17),  INT8_C(  85), -INT8_C(  85), -INT8_C(  41),  INT8_C(  65),  INT8_C(  20),
        -INT8_C(  14),  INT8_C( 112),  INT8_C(  76), -INT8_C(  73), -INT8_C(  76),  INT8_C(  80), -INT8_C( 108), -INT8_C( 121) },
      { -INT8_C(  51),  INT8_C(  19), -INT8_C(  60), -INT8_C(  52), -INT8_C(  77),  INT8_C(  46),  INT8_C(  75), -INT8_C( 125),
         INT8_C(  73),  INT8_C(  42),  INT8_C(  56),  INT8_C(  58),  INT8_C( 106), -INT8_C(   9),  INT8_C( 121),  INT8_C(  45),
         INT8_C( 117),  INT8_C( 105), -INT8_C( 125),  INT8_C(  33),  INT8_C(  64), -INT8_C(  60),  INT8_C(  53),  INT8_C(  50),
         INT8_C(  52), -INT8_C( 126), -INT8_C(  23), -INT8_C(  24), -INT8_C(  46),  INT8_C( 126),  INT8_C( 111), -INT8_C(  96),
        -INT8_C( 111),  INT8_C(  52),  INT8_C( 108),  INT8_C(  68),  INT8_C(  98), -INT8_C(  73), -INT8_C(  57), -INT8_C(  85),
        -INT8_C(  30), -INT8_C(   1), -INT8_C(  27),  INT8_C(  76), -INT8_C(  10),  INT8_C(  95),  INT8_C( 122),  INT8_C( 108),
        -INT8_C(  56), -INT8_C(   3), -INT8_C( 115),  INT8_C(   8), -INT8_C(  63), -INT8_C(  62),  INT8_C(  58), -INT8_C(  11),
         INT8_C(  68),  INT8_C(  35), -INT8_C(  35),  INT8_C(  23), -INT8_C(  95),  INT8_C(  77), -INT8_C(  73),  INT8_C(  50) },
      { -INT8_C(  28), -INT8_C(  20),  INT8_C(  92),  INT8_C( 109),  INT8_C(  30), -INT8_C(  95),  INT8_C( 108),  INT8_C( 123),
        -INT8_C(  25),  INT8_C( 106), -INT8_C(  24), -INT8_C( 101),  INT8_C(  79), -INT8_C(  51),  INT8_C( 100),  INT8_C(  92),
        -INT8_C(  61), -INT8_C(  20), -INT8_C(  12), -INT8_C( 114), -INT8_C(  46), -INT8_C(  15), -INT8_C(  89), -INT8_C(  94),
        -INT8_C(  99), -INT8_C(  99),  INT8_C(  82),  INT8_C(  35), -INT8_C( 109), -INT8_C(  23),  INT8_C( 115), -INT8_C(  74),
         INT8_C(  99), -INT8_C(  79), -INT8_C(  22), -INT8_C( 127), -INT8_C(  22), -INT8_C( 109),  INT8_C(  49),  INT8_C(  41),
        -INT8_C(   3),  INT8_C(  25),  INT8_C( 120),  INT8_C(   1), -INT8_C( 118), -INT8_C(  97),  INT8_C(   9), -INT8_C(  85),
        -INT8_C( 117), -INT8_C(   3),  INT8_C( 124), -INT8_C( 124),  INT8_C( 108), -INT8_C(  75),  INT8_C(  38), -INT8_C(   1),
         INT8_C(  35),  INT8_C( 120),  INT8_C(  41), -INT8_C(  50),  INT8_C(  97),  INT8_C(  15),  INT8_C(  75), -INT8_C(  71) } },
    { { -INT8_C( 127),  INT8_C(  35),  INT8_C( 118), -INT8_C(  29), -INT8_C(  37),  INT8_C(  61), -INT8_C( 113), -INT8_C(  67),
         INT8_C(  61),  INT8_C( 116),  INT8_C(   9),  INT8_C(  51), -INT8_C(  45), -INT8_C( 125), -INT8_C(  97), -INT8_C( 101),
             INT8_MIN,  INT8_C(  44), -INT8_C(  93),  INT8_C(  65), -INT8_C(  17), -INT8_C(  35),  INT8_C(  54),  INT8_C(  51),
         INT8_C(   1),  INT8_C(  20),  INT8_C(  74), -INT8_C(  94),  INT8_C(  97),  INT8_C(   1), -INT8_C(  43), -INT8_C(  30),
         INT8_C(  37),  INT8_C(  75), -INT8_C(  59),  INT8_C(   0), -INT8_C( 119),  INT8_C(  84), -INT8_C(  67), -INT8_C(  58),
        -INT8_C(  55), -INT8_C(  58), -INT8_C(   7), -INT8_C( 100),  INT8_C(  74), -INT8_C( 103),  INT8_C(  56), -INT8_C(  54),
        -INT8_C(  59), -INT8_C(  37),  INT8_C(  12), -INT8_C(  76), -INT8_C(  71),  INT8_C(  66), -INT8_C(  24), -INT8_C(  70),
         INT8_C(  86),  INT8_C(  50),  INT8_C(  92), -INT8_C(  73),  INT8_C(  52),  INT8_C(  49), -INT8_C( 103),  INT8_C(  89) },
      UINT64_C( 8992587514113515389),
      { -INT8_C(  36), -INT8_C(  59),  INT8_C(  25),  INT8_C(  38),  INT8_C(  94),  INT8_C(  81), -INT8_C(  15),  INT8_C(  36),
         INT8_C(  44), -INT8_C(   3), -INT8_C(  40), -INT8_C(  27),  INT8_C(  63), -INT8_C(  64), -INT8_C(  97), -INT8_C( 106),
        -INT8_C(  13), -INT8_C(   4),  INT8_C(  77),  INT8_C(  39),  INT8_C(  45), -INT8_C(  25),      INT8_MIN, -INT8_C(  86),
         INT8_C(  70), -INT8_C(  39), -INT8_C(  80), -INT8_C(   7), -INT8_C(  17),  INT8_C( 124),  INT8_C( 118), -INT8_C(  53),
         INT8_C(  66), -INT8_C( 113), -INT8_C(  14), -INT8_C(  96), -INT8_C(  32), -INT8_C(  29), -INT8_C(  60),  INT8_C(  12),
        -INT8_C(  32), -INT8_C(  99), -INT8_C(  14),  INT8_C(  31),  INT8_C(  93), -INT8_C( 111), -INT8_C(  75),  INT8_C(  80),
        -INT8_C( 115),  INT8_C(   3),  INT8_C( 119), -INT8_C(  69), -INT8_C(  22), -INT8_C(   9),  INT8_C( 101),  INT8_C(  48),
        -INT8_C(  48),  INT8_C(  22),  INT8_C(  41), -INT8_C(  65), -INT8_C( 110), -INT8_C(  97), -INT8_C( 117), -INT8_C(  44) },
      {  INT8_C(  46),  INT8_C( 125),  INT8_C( 117),  INT8_C(  14),  INT8_C(  96),  INT8_C(  57),  INT8_C(  27),  INT8_C(  64),
        -INT8_C(  42),  INT8_C(  13),  INT8_C(  95),  INT8_C(  52), -INT8_C(  98),  INT8_C(  21), -INT8_C( 124),  INT8_C(  44),
         INT8_C(  24), -INT8_C(   4), -INT8_C(  25),  INT8_C(   2), -INT8_C(  13),  INT8_C(  76),  INT8_C(  50), -INT8_C(  60),
         INT8_C(  98),  INT8_C(  91), -INT8_C( 125), -INT8_C(  11), -INT8_C(   5),  INT8_C(  14), -INT8_C(  55),  INT8_C(  41),
        -INT8_C( 117),  INT8_C(  62),  INT8_C(  56), -INT8_C(  21),  INT8_C( 120),  INT8_C(  83),  INT8_C(  43),  INT8_C(  78),
         INT8_C(  96), -INT8_C( 117), -INT8_C( 126), -INT8_C(   2), -INT8_C(  96),  INT8_C(   7),  INT8_C(  42), -INT8_C(  72),
         INT8_C(   3),  INT8_C(  17), -INT8_C(  70), -INT8_C(  10),  INT8_C(  94), -INT8_C(  20), -INT8_C(  70), -INT8_C(  64),
         INT8_C(  71),  INT8_C(  62), -INT8_C(  75),  INT8_C(  66),  INT8_C(  76),      INT8_MAX,  INT8_C( 108), -INT8_C(  40) },
      {  INT8_C(  10),  INT8_C(  35), -INT8_C( 114),  INT8_C(  52), -INT8_C(  66), -INT8_C( 118),  INT8_C(  12), -INT8_C(  67),
         INT8_C(   2),  INT8_C(  10),  INT8_C(  55),  INT8_C(  25), -INT8_C(  35), -INT8_C( 125),  INT8_C(  35), -INT8_C( 101),
         INT8_C(  11),  INT8_C(  44), -INT8_C(  93),  INT8_C(  41),  INT8_C(  32), -INT8_C(  35), -INT8_C(  78),  INT8_C(  51),
         INT8_C(   1),  INT8_C(  52),  INT8_C(  51), -INT8_C(  94),  INT8_C(  97),  INT8_C(   1), -INT8_C(  43), -INT8_C(  30),
        -INT8_C(  51), -INT8_C(  51), -INT8_C(  59),  INT8_C(   0),  INT8_C(  88),  INT8_C(  54), -INT8_C(  67),  INT8_C(  90),
        -INT8_C(  55),  INT8_C(  40),  INT8_C( 116), -INT8_C( 100), -INT8_C(   3), -INT8_C( 103),  INT8_C(  56), -INT8_C(  54),
        -INT8_C(  59), -INT8_C(  37),  INT8_C(  49), -INT8_C(  79), -INT8_C(  71),  INT8_C(  66),  INT8_C(  31), -INT8_C(  16),
         INT8_C(  86),  INT8_C(  50), -INT8_C(  34),  INT8_C(   1), -INT8_C(  34),  INT8_C(  30), -INT8_C(   9),  INT8_C(  89) } },
    { { -INT8_C(  67), -INT8_C(  92), -INT8_C(  61),  INT8_C(  53), -INT8_C(   9), -INT8_C(  17), -INT8_C( 124),  INT8_C(  87),
         INT8_C( 122),  INT8_C(   6),  INT8_C(  85),  INT8_C(  26),  INT8_C(  13),      INT8_MIN, -INT8_C(  46),  INT8_C(  16),
        -INT8_C( 111), -INT8_C( 116),  INT8_C(   7), -INT8_C(  17),  INT8_C( 120), -INT8_C(  63), -INT8_C(  80), -INT8_C(  65),
        -INT8_C(   1),  INT8_C( 101),  INT8_C(   2),  INT8_C(  76), -INT8_C(  28),  INT8_C( 110),  INT8_C(  36), -INT8_C(  94),
         INT8_C(  18), -INT8_C(  25), -INT8_C(  41),  INT8_C(   9), -INT8_C(  42),  INT8_C(  91),  INT8_C(  96),  INT8_C(  80),
         INT8_C(  98), -INT8_C(  75),  INT8_C( 106),  INT8_C( 111),  INT8_C(  53),  INT8_C(  60),      INT8_MIN, -INT8_C(  57),
        -INT8_C(  56), -INT8_C( 121), -INT8_C(  74),  INT8_C(  64),  INT8_C(  72),  INT8_C( 102),  INT8_C(   0),  INT8_C(  72),
        -INT8_C(  52),  INT8_C(   2), -INT8_C( 108), -INT8_C(  80),  INT8_C( 112), -INT8_C(  72),  INT8_C(  82), -INT8_C( 126) },
      UINT64_C(16701295226602072735),
      { -INT8_C(  96),  INT8_C(  49),  INT8_C(  87), -INT8_C(  42),  INT8_C( 109), -INT8_C(  41), -INT8_C(  99),  INT8_C(  54),
         INT8_C(  94),  INT8_C(  83),  INT8_C( 118), -INT8_C(  90), -INT8_C(  70),  INT8_C( 118), -INT8_C(  18), -INT8_C( 122),
         INT8_C( 120), -INT8_C( 126),  INT8_C(  54), -INT8_C(  24),  INT8_C(  58), -INT8_C( 119),  INT8_C( 106), -INT8_C(  38),
        -INT8_C(  77), -INT8_C(  11),  INT8_C(  80),  INT8_C(  56), -INT8_C(  32),  INT8_C(  22),  INT8_C(  32), -INT8_C( 127),
         INT8_C(  71),  INT8_C( 119),  INT8_C(  87), -INT8_C(  75),  INT8_C(  78), -INT8_C(  12), -INT8_C(  21), -INT8_C(  84),
         INT8_C(  71),  INT8_C(  97),  INT8_C(  82),  INT8_C(   1), -INT8_C(  40),  INT8_C(  65), -INT8_C( 121),  INT8_C(  80),
        -INT8_C(  61), -INT8_C(  66),  INT8_C(  57), -INT8_C(   2),  INT8_C(  71), -INT8_C(  93), -INT8_C(  40), -INT8_C(   6),
        -INT8_C( 103),  INT8_C(  40),  INT8_C(  50),  INT8_C( 121),  INT8_C(  62),  INT8_C(  82), -INT8_C(   6), -INT8_C( 122) },
      { -INT8_C(  55),  INT8_C(  81),  INT8_C(  59),  INT8_C(  23),  INT8_C(  69),  INT8_C(  38), -INT8_C(  61), -INT8_C( 115),
        -INT8_C( 121),  INT8_C(  22), -INT8_C( 114),  INT8_C(  95),  INT8_C(  87),  INT8_C(  22), -INT8_C(  80),  INT8_C(  26),
        -INT8_C(  44), -INT8_C(  23),  INT8_C(  24),  INT8_C(  27), -INT8_C( 116), -INT8_C(  16),  INT8_C(  21),  INT8_C(  37),
         INT8_C(  24),  INT8_C(  71), -INT8_C(  97),  INT8_C(  87), -INT8_C( 102), -INT8_C( 103), -INT8_C(  35),  INT8_C(  99),
        -INT8_C(  21),  INT8_C(  24),  INT8_C( 123),  INT8_C(  48),  INT8_C(  62),  INT8_C(  62), -INT8_C(  67), -INT8_C(  59),
         INT8_C(  84),  INT8_C(  76),  INT8_C(  37), -INT8_C(  85),  INT8_C(  98), -INT8_C(  43), -INT8_C(  58),  INT8_C(  54),
        -INT8_C(  66), -INT8_C(  34),  INT8_C(  81),  INT8_C(  74), -INT8_C(  49),  INT8_C( 102),  INT8_C( 112), -INT8_C(  25),
        -INT8_C(  83),  INT8_C(  15),  INT8_C(  62),  INT8_C(  71), -INT8_C(  88),  INT8_C(  27), -INT8_C(  85), -INT8_C( 109) },
      {  INT8_C( 105), -INT8_C( 126), -INT8_C( 110), -INT8_C(  19), -INT8_C(  78), -INT8_C(  17), -INT8_C( 124), -INT8_C(  61),
         INT8_C( 122),  INT8_C( 105),  INT8_C(  85),  INT8_C(   5),  INT8_C(  13), -INT8_C( 116), -INT8_C(  46),  INT8_C(  16),
         INT8_C(  76),  INT8_C( 107),  INT8_C(   7),  INT8_C(   3),  INT8_C( 120), -INT8_C(  63), -INT8_C(  80), -INT8_C(   1),
        -INT8_C(   1),  INT8_C(  60), -INT8_C(  17),  INT8_C(  76),  INT8_C( 122), -INT8_C(  81), -INT8_C(   3), -INT8_C(  94),
         INT8_C(  50), -INT8_C(  25), -INT8_C(  46),  INT8_C(   9), -INT8_C(  42),  INT8_C(  91),  INT8_C(  96),  INT8_C( 113),
        -INT8_C( 101), -INT8_C(  83),  INT8_C( 106), -INT8_C(  84),  INT8_C(  53),  INT8_C(  22),  INT8_C(  77), -INT8_C( 122),
        -INT8_C(  56), -INT8_C( 100), -INT8_C( 118),  INT8_C(  64),  INT8_C(  72),  INT8_C( 102),  INT8_C(  72), -INT8_C(  31),
         INT8_C(  70),  INT8_C(  55),  INT8_C( 112), -INT8_C(  80),  INT8_C( 112),  INT8_C( 109), -INT8_C(  91),  INT8_C(  25) } },
    { {  INT8_C(  51),  INT8_C(  38), -INT8_C(  60),  INT8_C( 113),  INT8_C( 100), -INT8_C( 127),  INT8_C(  55), -INT8_C(  71),
        -INT8_C(  51),  INT8_C(  92),  INT8_C( 100),  INT8_C(  47),  INT8_C(  49),  INT8_C(  42),  INT8_C( 101), -INT8_C(  17),
         INT8_C(   9), -INT8_C(  74),  INT8_C(  57), -INT8_C(  40),  INT8_C(  28), -INT8_C(  87), -INT8_C(  65), -INT8_C(  54),
        -INT8_C(  72), -INT8_C(   2),  INT8_C(  17),  INT8_C(  97),  INT8_C(  25), -INT8_C(  68), -INT8_C(  12),  INT8_C(  77),
        -INT8_C(  30), -INT8_C(  72), -INT8_C(  66),  INT8_C(  71),  INT8_C(  58), -INT8_C(  11),  INT8_C(   0),  INT8_C(   7),
         INT8_C(  81),  INT8_C( 100),  INT8_C(  55), -INT8_C( 126), -INT8_C( 113), -INT8_C( 100),  INT8_C( 113), -INT8_C( 104),
         INT8_C(  83), -INT8_C(  85),  INT8_C( 112),  INT8_C( 111),  INT8_C(  84),  INT8_C(  47),  INT8_C(  57),  INT8_C(  13),
         INT8_C(  45),  INT8_C(  75),  INT8_C( 110),  INT8_C(  71),  INT8_C(   7),  INT8_C(  98), -INT8_C( 108), -INT8_C(  22) },
      UINT64_C(11050761772397056539),
      { -INT8_C( 107), -INT8_C( 109),  INT8_C(  28),  INT8_C(  36),  INT8_C(  48), -INT8_C( 115), -INT8_C(  68), -INT8_C( 125),
         INT8_C(  56),  INT8_C(  44), -INT8_C(  14), -INT8_C( 115),  INT8_C(  92),  INT8_C(  44), -INT8_C( 102), -INT8_C( 119),
         INT8_C( 119),  INT8_C(   8), -INT8_C(  48),  INT8_C( 126),  INT8_C( 106),  INT8_C( 100),  INT8_C( 104), -INT8_C( 123),
        -INT8_C(  73), -INT8_C( 103), -INT8_C(  38), -INT8_C(   1), -INT8_C(  54),  INT8_C(  55), -INT8_C( 104),  INT8_C(  96),
        -INT8_C(  54), -INT8_C(  76), -INT8_C( 124), -INT8_C(   6),  INT8_C(  66),  INT8_C(  65),  INT8_C( 125),  INT8_C( 122),
         INT8_C( 109),  INT8_C( 112),  INT8_C(   7), -INT8_C(  55), -INT8_C( 100), -INT8_C(  95),  INT8_C(  83),  INT8_C(  19),
        -INT8_C(  87),  INT8_C(  35), -INT8_C( 111),  INT8_C(  20), -INT8_C( 120), -INT8_C(   6), -INT8_C( 103),  INT8_C(  63),
        -INT8_C( 109),  INT8_C( 116),  INT8_C(  62),  INT8_C(  94), -INT8_C(  85), -INT8_C(  42), -INT8_C(  66),  INT8_C( 117) },
      { -INT8_C( 117),  INT8_C(  66),  INT8_C( 112), -INT8_C(  51), -INT8_C( 125), -INT8_C(  19),  INT8_C(  71), -INT8_C(  15),
         INT8_C(  93),  INT8_C(  79), -INT8_C(  70), -INT8_C(   7), -INT8_C(  16),  INT8_C(  13),  INT8_C(  12), -INT8_C( 102),
         INT8_C(  49), -INT8_C(  98), -INT8_C(  82), -INT8_C(  71), -INT8_C( 104),  INT8_C(  71), -INT8_C(   8),  INT8_C(  43),
        -INT8_C(  69),  INT8_C(  54), -INT8_C( 119),  INT8_C( 102),  INT8_C(  12),  INT8_C(  71), -INT8_C(  36), -INT8_C( 105),
        -INT8_C( 118),  INT8_C(  76),  INT8_C( 100),  INT8_C(  13),  INT8_C(  57), -INT8_C(  84), -INT8_C(   2), -INT8_C( 105),
        -INT8_C(   5), -INT8_C(  71), -INT8_C( 112), -INT8_C(  21), -INT8_C(  58), -INT8_C(  99), -INT8_C( 123), -INT8_C(   9),
         INT8_C(  59),  INT8_C(  51), -INT8_C(  80), -INT8_C(  45),  INT8_C( 123), -INT8_C(  88), -INT8_C(   2),  INT8_C(  54),
        -INT8_C(  34), -INT8_C( 120), -INT8_C(  99), -INT8_C(  21), -INT8_C(  49),  INT8_C( 121), -INT8_C( 126),  INT8_C(  89) },
      {  INT8_C(  32), -INT8_C(  43), -INT8_C(  60), -INT8_C(  15), -INT8_C(  77), -INT8_C( 127),  INT8_C(  55), -INT8_C(  71),
        -INT8_C(  51),  INT8_C( 123),  INT8_C( 100),  INT8_C(  47),  INT8_C(  76),  INT8_C(  42), -INT8_C(  90), -INT8_C(  17),
        -INT8_C(  88), -INT8_C(  74),  INT8_C(  57), -INT8_C(  40),  INT8_C(   2), -INT8_C(  85), -INT8_C(  65), -INT8_C(  54),
         INT8_C( 114), -INT8_C(   2),  INT8_C(  99),  INT8_C(  97), -INT8_C(  42), -INT8_C(  68),  INT8_C( 116),  INT8_C(  77),
        -INT8_C(  30), -INT8_C(  72), -INT8_C(  66),  INT8_C(   7),  INT8_C(  58), -INT8_C(  11),  INT8_C( 123),  INT8_C(   7),
         INT8_C( 104),  INT8_C( 100),  INT8_C(  55), -INT8_C( 126),  INT8_C(  98),  INT8_C(  62),  INT8_C( 113), -INT8_C( 104),
         INT8_C(  83), -INT8_C(  85),  INT8_C(  65), -INT8_C(  25),  INT8_C(   3),  INT8_C(  47), -INT8_C( 105),  INT8_C(  13),
         INT8_C( 113),  INT8_C(  75),  INT8_C( 110),  INT8_C(  73),  INT8_C( 122),  INT8_C(  98), -INT8_C( 108), -INT8_C(  50) } },
    { { -INT8_C(  59), -INT8_C(  25),  INT8_C( 103), -INT8_C(   2), -INT8_C( 109),  INT8_C( 101), -INT8_C( 107), -INT8_C( 114),
         INT8_C(  30),  INT8_C(  38),  INT8_C( 121), -INT8_C(  27), -INT8_C(  61), -INT8_C(   1), -INT8_C(  36), -INT8_C(   2),
         INT8_C(  50), -INT8_C( 115), -INT8_C(  47), -INT8_C(  83),  INT8_C(  53), -INT8_C(  49), -INT8_C(  28),  INT8_C(  20),
         INT8_C(  87), -INT8_C( 127), -INT8_C(   1),  INT8_C(  39), -INT8_C(   6), -INT8_C( 127),      INT8_MIN, -INT8_C(  65),
         INT8_C( 104), -INT8_C(  25), -INT8_C(  67), -INT8_C(   5),  INT8_C(  77),  INT8_C(  83), -INT8_C( 119),  INT8_C( 107),
         INT8_C( 121),  INT8_C(   3),  INT8_C(  80),  INT8_C(  60),  INT8_C(   2),  INT8_C(  45),  INT8_C(  58),  INT8_C(  52),
        -INT8_C(  70),  INT8_C(  11), -INT8_C(  30), -INT8_C(  17), -INT8_C(  38), -INT8_C(  58),  INT8_C(   3),  INT8_C(  50),
         INT8_C(  71),  INT8_C(   2),  INT8_C(  89),  INT8_C(  65), -INT8_C( 124), -INT8_C(  39),  INT8_C(   0), -INT8_C(  20) },
      UINT64_C( 9906073169161665985),
      {  INT8_C( 116), -INT8_C(  54), -INT8_C(  59),  INT8_C( 118), -INT8_C(   9), -INT8_C(   1), -INT8_C(  85), -INT8_C(  79),
         INT8_C(  10), -INT8_C( 115), -INT8_C(  96), -INT8_C(  27),  INT8_C(  83), -INT8_C(  92),  INT8_C(  23), -INT8_C( 102),
        -INT8_C(  90),  INT8_C( 112), -INT8_C(  37),  INT8_C(  42),  INT8_C(  73), -INT8_C(  37),  INT8_C(  23),  INT8_C(  10),
        -INT8_C( 104), -INT8_C(   1),  INT8_C(  24), -INT8_C(  87),  INT8_C( 112), -INT8_C( 110),  INT8_C(  50), -INT8_C(  27),
         INT8_C(  92), -INT8_C(   8),  INT8_C(  91),  INT8_C(  83), -INT8_C(   9),  INT8_C(   6),  INT8_C(   4),  INT8_C(   2),
        -INT8_C( 109), -INT8_C(  92), -INT8_C(  25), -INT8_C(  26),  INT8_C(  72), -INT8_C(   2),      INT8_MIN, -INT8_C(  17),
         INT8_C( 110),  INT8_C(  91),  INT8_C(  25), -INT8_C(  73),  INT8_C(  54),  INT8_C(  48), -INT8_C(  62), -INT8_C(  49),
         INT8_C(  47), -INT8_C(  38),  INT8_C( 120), -INT8_C(  96),  INT8_C( 108), -INT8_C(  86), -INT8_C( 123), -INT8_C(  56) },
      { -INT8_C(  94), -INT8_C(  32),  INT8_C(  27), -INT8_C( 102), -INT8_C(  25),  INT8_C(  31), -INT8_C( 100),  INT8_C( 122),
        -INT8_C(  60), -INT8_C( 125),  INT8_C(  97),  INT8_C(  12), -INT8_C( 127), -INT8_C(  31), -INT8_C(   5), -INT8_C(  17),
         INT8_C(  61),  INT8_C(  21), -INT8_C(  90),  INT8_C( 115),  INT8_C(  69),  INT8_C( 104),  INT8_C(  66),  INT8_C( 117),
         INT8_C(  67), -INT8_C(  70),  INT8_C(  21), -INT8_C(  81),  INT8_C( 101), -INT8_C( 102),  INT8_C( 120),  INT8_C(   7),
         INT8_C( 122), -INT8_C( 109), -INT8_C(  95),  INT8_C(  97), -INT8_C(  77),  INT8_C(  61), -INT8_C(  36),  INT8_C( 119),
        -INT8_C(  64),  INT8_C(  61), -INT8_C( 125),  INT8_C(  65),  INT8_C(  30),      INT8_MAX,  INT8_C(  48),  INT8_C(  91),
        -INT8_C( 108), -INT8_C(  41), -INT8_C(  49), -INT8_C(  39),  INT8_C(  63),  INT8_C(  17),  INT8_C(  78), -INT8_C( 126),
        -INT8_C(  52),  INT8_C(  99),  INT8_C(  50),  INT8_C(  49), -INT8_C(   3), -INT8_C(  86),  INT8_C(  56),  INT8_C( 120) },
      {  INT8_C(  22), -INT8_C(  25),  INT8_C( 103), -INT8_C(   2), -INT8_C( 109),  INT8_C( 101),  INT8_C(  71),  INT8_C(  43),
        -INT8_C(  50),  INT8_C(  38),  INT8_C(   1), -INT8_C(  15), -INT8_C(  44), -INT8_C( 123), -INT8_C(  36), -INT8_C( 119),
         INT8_C(  50), -INT8_C( 115), -INT8_C(  47), -INT8_C(  99),  INT8_C(  53),  INT8_C(  67),  INT8_C(  89),      INT8_MAX,
         INT8_C(  87), -INT8_C(  71),  INT8_C(  45),  INT8_C(  88), -INT8_C(   6), -INT8_C( 127),      INT8_MIN, -INT8_C(  65),
         INT8_C( 104), -INT8_C(  25), -INT8_C(  67), -INT8_C(   5), -INT8_C(  86),  INT8_C(  83), -INT8_C( 119),  INT8_C( 107),
         INT8_C(  83),  INT8_C(   3),  INT8_C(  80),  INT8_C(  60),  INT8_C( 102),  INT8_C( 125), -INT8_C(  80),  INT8_C(  52),
         INT8_C(   2),  INT8_C(  11), -INT8_C(  30), -INT8_C( 112),  INT8_C( 117),  INT8_C(  65),  INT8_C(  16),  INT8_C(  50),
        -INT8_C(   5),  INT8_C(   2),  INT8_C(  89), -INT8_C(  47), -INT8_C( 124), -INT8_C(  39),  INT8_C(   0),  INT8_C(  64) } },
    { {  INT8_C(  61), -INT8_C(  38), -INT8_C(  39), -INT8_C(  16),  INT8_C(  23), -INT8_C(  75),  INT8_C( 103), -INT8_C(  40),
        -INT8_C(  14), -INT8_C(  21),  INT8_C(  25),  INT8_C(  17),  INT8_C( 106),  INT8_C(  74),  INT8_C( 108), -INT8_C(   2),
         INT8_C(  33),  INT8_C(  59), -INT8_C(  41),  INT8_C(  96),  INT8_C(  77),  INT8_C(  38), -INT8_C(  29),  INT8_C(  25),
        -INT8_C( 119),  INT8_C(  21),  INT8_C(  74), -INT8_C( 121), -INT8_C(  65), -INT8_C( 126), -INT8_C(   1), -INT8_C(   4),
         INT8_C(  92), -INT8_C(  40), -INT8_C(  19),  INT8_C( 116), -INT8_C( 114),  INT8_C(  84),  INT8_C(  76),      INT8_MIN,
         INT8_C(  63),  INT8_C( 101), -INT8_C( 111), -INT8_C(  87), -INT8_C(  81), -INT8_C(   2), -INT8_C(  89), -INT8_C(  48),
         INT8_C(  57),      INT8_MAX,  INT8_C(  49), -INT8_C( 122), -INT8_C(  91),  INT8_C(  20), -INT8_C(  97),  INT8_C(  46),
         INT8_C(  41), -INT8_C(  23), -INT8_C(  75), -INT8_C(  24),  INT8_C( 108), -INT8_C(  76), -INT8_C(  28), -INT8_C(  56) },
      UINT64_C( 7321595316467978637),
      { -INT8_C(  18),  INT8_C(  45),  INT8_C(  15), -INT8_C(  99),  INT8_C(  43), -INT8_C(  74),  INT8_C( 110),  INT8_C( 100),
         INT8_C(  53), -INT8_C(  97), -INT8_C(  21), -INT8_C(  38), -INT8_C(  77), -INT8_C( 118),  INT8_C(   9), -INT8_C(  36),
         INT8_C( 116), -INT8_C(  66), -INT8_C(  60), -INT8_C(  32),  INT8_C( 115), -INT8_C(  88), -INT8_C(  88),  INT8_C(   0),
         INT8_C( 122), -INT8_C(  27),  INT8_C(  27), -INT8_C(  96),  INT8_C( 109), -INT8_C(  74),  INT8_C(   5),  INT8_C(  91),
        -INT8_C(  29),  INT8_C(  20), -INT8_C(   7),  INT8_C(  14), -INT8_C(  53),  INT8_C( 103),  INT8_C( 115),  INT8_C(   0),
         INT8_C(   6),  INT8_C(  94), -INT8_C(  37), -INT8_C(  71), -INT8_C(  24), -INT8_C(  28), -INT8_C( 107),  INT8_C(  92),
        -INT8_C(  94),  INT8_C(  89),  INT8_C(  60),  INT8_C(  21),  INT8_C(   1), -INT8_C(  27),  INT8_C(  21),  INT8_C( 123),
        -INT8_C(  54),  INT8_C(  48),  INT8_C(  27),  INT8_C(  55), -INT8_C(  25),  INT8_C(  33), -INT8_C( 109), -INT8_C(  54) },
      {  INT8_C(  53), -INT8_C( 116), -INT8_C(  39),  INT8_C(   0), -INT8_C(  13),  INT8_C(  76),  INT8_C(   1), -INT8_C(   7),
        -INT8_C(  86), -INT8_C(  36), -INT8_C(  78), -INT8_C( 110), -INT8_C(  64),  INT8_C(  71), -INT8_C(  17),  INT8_C(  98),
        -INT8_C(  96),  INT8_C(  43),  INT8_C( 120), -INT8_C(  95),  INT8_C(  16), -INT8_C( 115),  INT8_C(  29), -INT8_C(  38),
        -INT8_C(  66),  INT8_C(  56),  INT8_C(  18), -INT8_C(  91),  INT8_C(  89), -INT8_C(  91),  INT8_C( 111), -INT8_C( 113),
         INT8_C(  49),  INT8_C(  72), -INT8_C( 113),  INT8_C(  36), -INT8_C( 108), -INT8_C( 112),  INT8_C(  29),  INT8_C(  62),
         INT8_C( 108), -INT8_C(  49), -INT8_C(  47),  INT8_C(  44),  INT8_C(  22), -INT8_C(  64), -INT8_C( 113), -INT8_C(  74),
        -INT8_C(  21),  INT8_C(   7),  INT8_C(  87), -INT8_C(   4), -INT8_C( 108),  INT8_C( 116), -INT8_C(  42),  INT8_C(  82),
        -INT8_C(  83), -INT8_C(  24), -INT8_C(   9),  INT8_C(   6), -INT8_C( 115),  INT8_C( 103), -INT8_C( 107), -INT8_C(  66) },
      {  INT8_C(  35), -INT8_C(  38), -INT8_C(  24), -INT8_C(  99),  INT8_C(  23), -INT8_C(  75),  INT8_C( 103),  INT8_C(  93),
        -INT8_C(  33), -INT8_C(  21),  INT8_C(  25),  INT8_C(  17),  INT8_C( 115),  INT8_C(  74), -INT8_C(   8),  INT8_C(  62),
         INT8_C(  33),  INT8_C(  59),  INT8_C(  60), -INT8_C( 127), -INT8_C( 125),  INT8_C(  53), -INT8_C(  29),  INT8_C(  25),
         INT8_C(  56),  INT8_C(  29),  INT8_C(  74),  INT8_C(  69), -INT8_C(  58), -INT8_C( 126), -INT8_C(   1), -INT8_C(   4),
         INT8_C(  92),  INT8_C(  92), -INT8_C( 120),  INT8_C( 116), -INT8_C( 114), -INT8_C(   9),  INT8_C(  76),      INT8_MIN,
         INT8_C(  63),  INT8_C( 101), -INT8_C( 111), -INT8_C(  27), -INT8_C(  81), -INT8_C(   2), -INT8_C(  89),  INT8_C(  18),
        -INT8_C( 115),  INT8_C(  96),  INT8_C(  49),  INT8_C(  17), -INT8_C( 107),  INT8_C(  20), -INT8_C(  97), -INT8_C(  51),
         INT8_C( 119), -INT8_C(  23),  INT8_C(  18), -INT8_C(  24),  INT8_C( 108), -INT8_C( 120),  INT8_C(  40), -INT8_C(  56) } },
    { { -INT8_C(  81),  INT8_C(  37), -INT8_C(  30),  INT8_C(  68), -INT8_C(  75), -INT8_C(   1), -INT8_C( 126),  INT8_C(  34),
        -INT8_C(  50),  INT8_C(  83),  INT8_C(  78), -INT8_C(  28),  INT8_C(  19), -INT8_C(  35), -INT8_C( 102), -INT8_C(   1),
        -INT8_C(  28), -INT8_C(  14), -INT8_C(   5),  INT8_C( 121),  INT8_C( 102), -INT8_C(  47), -INT8_C(  53),  INT8_C(  19),
        -INT8_C(  70), -INT8_C(  61),  INT8_C(  26),  INT8_C(  71),  INT8_C(  42), -INT8_C(  81),  INT8_C(   6), -INT8_C(  39),
        -INT8_C(  44), -INT8_C(  24),  INT8_C(  29), -INT8_C( 118), -INT8_C(  24), -INT8_C(  96), -INT8_C(  84), -INT8_C(  74),
        -INT8_C(  13), -INT8_C(   6), -INT8_C( 101),  INT8_C(   7), -INT8_C(  40),  INT8_C(  53),  INT8_C(   6), -INT8_C(  68),
         INT8_C(  39),  INT8_C(   1),  INT8_C(  53), -INT8_C( 114), -INT8_C(  46),  INT8_C(   1), -INT8_C(  95), -INT8_C( 116),
        -INT8_C(  60), -INT8_C(  69), -INT8_C(  44), -INT8_C(  18),  INT8_C( 107), -INT8_C(  38), -INT8_C(  57),  INT8_C(  63) },
      UINT64_C( 8674343574248744386),
      {  INT8_C( 112), -INT8_C(   4),      INT8_MAX,  INT8_C(  72),  INT8_C(  49), -INT8_C( 123),  INT8_C(   4),  INT8_C(  89),
        -INT8_C( 122),  INT8_C(  58), -INT8_C(  25),  INT8_C(  89),  INT8_C(  59), -INT8_C( 120), -INT8_C(  27), -INT8_C(   1),
         INT8_C(  68), -INT8_C(  71), -INT8_C(  19), -INT8_C(  81), -INT8_C( 109), -INT8_C(  76), -INT8_C(  18),  INT8_C(  86),
        -INT8_C( 103), -INT8_C(  72),  INT8_C(   0),  INT8_C(  30),  INT8_C(  45),  INT8_C(  97), -INT8_C( 105), -INT8_C(  99),
         INT8_C(  93),  INT8_C(  22), -INT8_C(  27), -INT8_C( 113), -INT8_C( 100), -INT8_C(  22), -INT8_C(  24),  INT8_C(  34),
         INT8_C(  36), -INT8_C(  49),  INT8_C( 123),  INT8_C(  95),  INT8_C(  87),  INT8_C(  97),  INT8_C(  94), -INT8_C( 101),
         INT8_C(  26),  INT8_C(  75),  INT8_C(  74), -INT8_C(  82), -INT8_C(   1),  INT8_C(  57),  INT8_C(   4), -INT8_C( 103),
        -INT8_C(  15),  INT8_C(   4), -INT8_C(  73),  INT8_C(  30),  INT8_C( 102),  INT8_C(  78), -INT8_C(  68), -INT8_C(  61) },
      {  INT8_C( 101), -INT8_C(  95),  INT8_C(  82),  INT8_C(   1), -INT8_C( 117),  INT8_C(  58),  INT8_C(  35), -INT8_C(  81),
         INT8_C(   9), -INT8_C(  97),  INT8_C(  14),  INT8_C(  97),  INT8_C(   0),  INT8_C( 108), -INT8_C(   4),  INT8_C(  26),
        -INT8_C(  73),  INT8_C(  71), -INT8_C(  56), -INT8_C(  73),      INT8_MIN, -INT8_C(  52),  INT8_C(  80),  INT8_C( 113),
        -INT8_C(  47),  INT8_C(   7), -INT8_C( 113),  INT8_C(  55),  INT8_C(  86),  INT8_C(  75), -INT8_C(   6), -INT8_C(  69),
        -INT8_C(  19),  INT8_C(  77), -INT8_C(  68),  INT8_C( 120), -INT8_C( 121), -INT8_C(  33),  INT8_C(  40), -INT8_C( 111),
         INT8_C( 126),  INT8_C(  54), -INT8_C(  14),  INT8_C( 126), -INT8_C(  93), -INT8_C(  18), -INT8_C( 103),  INT8_C(  90),
         INT8_C(  53),  INT8_C(  97),  INT8_C(  17), -INT8_C(  75),  INT8_C(  46),  INT8_C(  97),  INT8_C(  38), -INT8_C(   1),
         INT8_C( 105), -INT8_C(  74),  INT8_C(  54), -INT8_C(  65),  INT8_C(   1),  INT8_C(  48),  INT8_C( 122), -INT8_C(  18) },
      { -INT8_C(  81), -INT8_C(  99), -INT8_C(  30),  INT8_C(  68), -INT8_C(  75), -INT8_C(   1),  INT8_C(  39),  INT8_C(   8),
        -INT8_C( 113),  INT8_C(  83), -INT8_C(  11), -INT8_C(  28),  INT8_C(  19), -INT8_C(  12), -INT8_C(  31),  INT8_C(  25),
        -INT8_C(   5), -INT8_C(  14), -INT8_C(   5),  INT8_C( 102),  INT8_C( 102), -INT8_C(  47),  INT8_C(  62), -INT8_C(  57),
        -INT8_C(  70), -INT8_C(  65),  INT8_C(  26),  INT8_C(  85),  INT8_C(  42), -INT8_C(  84),  INT8_C(   6),  INT8_C(  88),
         INT8_C(  74), -INT8_C(  24), -INT8_C(  95), -INT8_C( 118), -INT8_C(  24), -INT8_C(  96), -INT8_C(  84), -INT8_C(  77),
        -INT8_C(  94), -INT8_C(   6),  INT8_C( 109),  INT8_C(   7), -INT8_C(   6),  INT8_C(  79), -INT8_C(   9), -INT8_C(  68),
         INT8_C(  79),  INT8_C(   1),  INT8_C(  53), -INT8_C( 114), -INT8_C(  46), -INT8_C( 102),  INT8_C(  42), -INT8_C( 116),
        -INT8_C(  60), -INT8_C(  69), -INT8_C(  44), -INT8_C(  35),  INT8_C( 103),  INT8_C( 126),  INT8_C(  54),  INT8_C(  63) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i src = simde_mm512_loadu_epi8(test_vec[i].src);
    simde__m512i a = simde_mm512_loadu_epi8(test_vec[i].a);
    simde__m512i b = simde_mm512_loadu_epi8(test_vec[i].b);
    simde__m512i r = simde_mm512_mask_add_epi8(src, test_vec[i].k, a, b);
    simde_test_x86_assert_equal_i8x64(r, simde_mm512_loadu_epi8(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_mm512_maskz_add_epi8 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const simde__mmask64 k;
    const int8_t a[64];
    const int8_t b[64];
    const int8_t r[64];
  } test_vec[] = {
    { UINT64_C( 9122680976650596708),
      {  INT8_C(  68), -INT8_C(  57),  INT8_C(  11), -INT8_C( 119), -INT8_C( 113),  INT8_C( 124),  INT8_C(  91),  INT8_C(   1),
         INT8_C( 112), -INT8_C( 126),  INT8_C(  44), -INT8_C(  65),  INT8_C(  76), -INT8_C(  60), -INT8_C(  30),  INT8_C(  88),
        -INT8_C(   8),  INT8_C(  72), -INT8_C(  34), -INT8_C( 108),  INT8_C(   2),  INT8_C(  65), -INT8_C(  12),  INT8_C( 102),
         INT8_C(  50),  INT8_C( 109),  INT8_C(  10),  INT8_C(  54), -INT8_C(  77), -INT8_C(  91), -INT8_C(  76), -INT8_C(   9),
         INT8_C( 108), -INT8_C(  65),      INT8_MIN, -INT8_C(   5),  INT8_C(  60), -INT8_C(  36), -INT8_C(   4), -INT8_C(  84),
         INT8_C(  94),  INT8_C(  40),  INT8_C( 108), -INT8_C(  86), -INT8_C(  20),  INT8_C(  78),  INT8_C(   2), -INT8_C(  27),
        -INT8_C( 106), -INT8_C(  32),  INT8_C( 121), -INT8_C( 104),  INT8_C(  34),  INT8_C( 110), -INT8_C(   2),  INT8_C(  84),
        -INT8_C(  37),  INT8_C(   8), -INT8_C( 118), -INT8_C( 114), -INT8_C(  83),  INT8_C(  63), -INT8_C( 122),  INT8_C(  25) },
      { -INT8_C(   2),  INT8_C(   6),  INT8_C(  20),  INT8_C(  58), -INT8_C(  30),  INT8_C(  16), -INT8_C(  25),  INT8_C(  65),
         INT8_C(  56),  INT8_C(  83), -INT8_C(  21),  INT8_C(  37), -INT8_C(  95), -INT8_C(  18),  INT8_C(  10),  INT8_C(  55),
        -INT8_C(  50), -INT8_C( 125), -INT8_C(  49), -INT8_C(  16), -INT8_C(  15), -INT8_C(  51),  INT8_C(  69), -INT8_C(  52),
        -INT8_C(  43), -INT8_C(  49),  INT8_C(  91), -INT8_C( 125),  INT8_C(  14), -INT8_C(  31), -INT8_C( 100),  INT8_C(  13),
        -INT8_C(  25), -INT8_C(  79),  INT8_C(  71), -INT8_C(  54), -INT8_C(  63),  INT8_C(  46),  INT8_C(  11), -INT8_C(   6),
        -INT8_C( 127), -INT8_C(  10),  INT8_C(  31),  INT8_C(  34), -INT8_C(  28),  INT8_C(  41),  INT8_C(  89), -INT8_C(  77),
        -INT8_C(  84),  INT8_C(  40), -INT8_C(  93), -INT8_C(  98), -INT8_C(  11), -INT8_C(  24),  INT8_C( 106), -INT8_C(  53),
        -INT8_C(  72), -INT8_C(  59),  INT8_C(  78), -INT8_C(  58), -INT8_C(  90), -INT8_C(  22), -INT8_C(  45), -INT8_C( 114) },
      {  INT8_C(   0),  INT8_C(   0),  INT8_C(  31),  INT8_C(   0),  INT8_C(   0), -INT8_C( 116),  INT8_C(  66),  INT8_C(   0),
        -INT8_C(  88),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  19), -INT8_C(  78), -INT8_C(  20), -INT8_C( 113),
         INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C( 124), -INT8_C(  13),  INT8_C(  14),  INT8_C(  57),  INT8_C(   0),
         INT8_C(   0),  INT8_C(   0),  INT8_C( 101),  INT8_C(   0),  INT8_C(   0), -INT8_C( 122),  INT8_C(   0),  INT8_C(   4),
         INT8_C(  83),  INT8_C( 112),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
         INT8_C(   0),  INT8_C(  30), -INT8_C( 117),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(  91),  INT8_C(   0),
         INT8_C(   0),  INT8_C(   8),  INT8_C(   0),  INT8_C(  54),  INT8_C(  23),  INT8_C(   0),  INT8_C(   0),  INT8_C(  31),
         INT8_C(   0), -INT8_C(  51), -INT8_C(  40),  INT8_C(  84),  INT8_C(  83),  INT8_C(  41),  INT8_C(  89),  INT8_C(   0) } },
    { UINT64_C(14652289079423015835),
      {  INT8_C(  89),  INT8_C( 118), -INT8_C(  19),  INT8_C(  62), -INT8_C(  97),  INT8_C(  71), -INT8_C(  15),  INT8_C(  75),
         INT8_C( 111), -INT8_C( 108), -INT8_C(  23),  INT8_C( 101),  INT8_C( 125),  INT8_C(  84),  INT8_C(  48),  INT8_C(  53),
         INT8_C(  25),  INT8_C( 126), -INT8_C(   5), -INT8_C(  64),  INT8_C( 104), -INT8_C(  49),  INT8_C(  78),  INT8_C(   4),
        -INT8_C(  22), -INT8_C(  90),  INT8_C(  97),  INT8_C(  51),  INT8_C(   9), -INT8_C(  72), -INT8_C(   2),  INT8_C(  98),
         INT8_C(  46), -INT8_C(  20), -INT8_C(  96), -INT8_C(  51),  INT8_C(  51), -INT8_C( 111),  INT8_C(  24), -INT8_C(  94),
         INT8_C(  38),  INT8_C(   2),  INT8_C(   7), -INT8_C(  93),  INT8_C(  86),  INT8_C(  55), -INT8_C(  40),  INT8_C( 111),
        -INT8_C(  75), -INT8_C(  45),  INT8_C(  47),  INT8_C(  30), -INT8_C(  94),  INT8_C( 125),  INT8_C(  34), -INT8_C( 116),
         INT8_C(  35), -INT8_C( 125), -INT8_C(  64),  INT8_C(  44),  INT8_C(  59), -INT8_C(  66), -INT8_C( 113),  INT8_C( 105) },
      { -INT8_C(  86),  INT8_C(  47),  INT8_C(  54), -INT8_C(  35), -INT8_C(  63),  INT8_C(  78),      INT8_MIN, -INT8_C(  25),
         INT8_C(  80), -INT8_C( 121), -INT8_C( 118), -INT8_C(  90), -INT8_C(  65),  INT8_C(  98),  INT8_C(  22),  INT8_C( 116),
         INT8_C(  53),  INT8_C(  69), -INT8_C( 110), -INT8_C(  40), -INT8_C(  61), -INT8_C(  76),  INT8_C( 100), -INT8_C(  26),
         INT8_C(  55),  INT8_C(  36),  INT8_C(  19),  INT8_C( 114), -INT8_C(  29), -INT8_C(  94), -INT8_C(  37), -INT8_C( 115),
        -INT8_C(  47),  INT8_C(  17),  INT8_C( 107), -INT8_C( 110),  INT8_C(  96), -INT8_C(  21),  INT8_C( 121), -INT8_C(  80),
         INT8_C( 114),  INT8_C(   3),  INT8_C(  87),  INT8_C(  49),  INT8_C( 101),  INT8_C( 109), -INT8_C(  90), -INT8_C( 101),
        -INT8_C(  78),  INT8_C(  56),  INT8_C( 115),  INT8_C( 117), -INT8_C(  19), -INT8_C(  41),  INT8_C(  92),  INT8_C(  36),
        -INT8_C(   4),  INT8_C( 111), -INT8_C( 105), -INT8_C(  33),  INT8_C(  17),  INT8_C( 114),  INT8_C( 108), -INT8_C(  30) },
      {  INT8_C(   3), -INT8_C(  91),  INT8_C(   0),  INT8_C(  27),  INT8_C(  96),  INT8_C(   0),  INT8_C(   0),  INT8_C(  50),
        -INT8_C(  65),  INT8_C(  27),  INT8_C(   0),  INT8_C(  11),  INT8_C(  60),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
         INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C( 104),  INT8_C(  43),  INT8_C(   0), -INT8_C(  78),  INT8_C(   0),
         INT8_C(  33),  INT8_C(   0),  INT8_C( 116), -INT8_C(  91), -INT8_C(  20),  INT8_C(   0), -INT8_C(  39),  INT8_C(   0),
        -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(  95),  INT8_C(   0),  INT8_C(   0), -INT8_C( 111),  INT8_C(   0),
        -INT8_C( 104),  INT8_C(   5),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  92),  INT8_C( 126),  INT8_C(   0),
         INT8_C( 103),  INT8_C(  11), -INT8_C(  94),  INT8_C(   0), -INT8_C( 113),  INT8_C(   0),  INT8_C( 126),  INT8_C(   0),
         INT8_C(  31), -INT8_C(  14),  INT8_C(   0),  INT8_C(  11),  INT8_C(   0),  INT8_C(   0), -INT8_C(   5),  INT8_C(  75) } },
    { UINT64_C( 3860973301387351940),
      { -INT8_C(  14), -INT8_C(  21),  INT8_C( 102),  INT8_C(  87),  INT8_C(  88),  INT8_C(  12), -INT8_C(  14),  INT8_C(  11),
         INT8_C(  69),  INT8_C( 101),      INT8_MIN,  INT8_C(  50),  INT8_C(  61), -INT8_C(  36),  INT8_C(  86),  INT8_C(  57),
         INT8_C(  75), -INT8_C(  19),  INT8_C(  24),  INT8_C(  92),  INT8_C(  96), -INT8_C( 124),  INT8_C(  63), -INT8_C(  28),
         INT8_C(  92), -INT8_C(  76), -INT8_C(  56),  INT8_C(  30), -INT8_C(  94),  INT8_C(  92),  INT8_C(  83), -INT8_C( 108),
         INT8_C(  72), -INT8_C(  70), -INT8_C(  20), -INT8_C(  96), -INT8_C(  58), -INT8_C(  34), -INT8_C(  85),  INT8_C(  11),
         INT8_C(  68),  INT8_C(  44),  INT8_C(  61), -INT8_C( 127),  INT8_C(   8), -INT8_C( 108), -INT8_C(  70),  INT8_C(  84),
        -INT8_C( 127), -INT8_C(  46), -INT8_C(  80), -INT8_C(  31),  INT8_C(  86), -INT8_C(  17), -INT8_C(  59), -INT8_C(  78),
        -INT8_C(  93), -INT8_C( 115), -INT8_C(  47),  INT8_C(  70), -INT8_C(  22),  INT8_C(  36), -INT8_C(  38),  INT8_C(  50) },
      { -INT8_C(  34), -INT8_C(  58), -INT8_C(  46), -INT8_C(  91), -INT8_C(  91),  INT8_C( 126), -INT8_C(  80), -INT8_C(  23),
        -INT8_C(  86), -INT8_C(  18),  INT8_C( 106), -INT8_C(  78), -INT8_C( 126),  INT8_C(  36),  INT8_C(   6),  INT8_C(   3),
        -INT8_C(  10), -INT8_C(  73), -INT8_C(  27),  INT8_C(  76), -INT8_C(  90), -INT8_C(  86), -INT8_C(   1),  INT8_C(  74),
         INT8_C(  56), -INT8_C(  48), -INT8_C( 112),  INT8_C(  34), -INT8_C(  12),  INT8_C( 106),  INT8_C(  84), -INT8_C(  45),
         INT8_C(  49),  INT8_C(  38),  INT8_C( 120), -INT8_C(  42), -INT8_C(  92),  INT8_C(  40), -INT8_C(  65),  INT8_C(  78),
         INT8_C(  22),  INT8_C(  41),  INT8_C(   1), -INT8_C( 104),  INT8_C(  77),  INT8_C(   7), -INT8_C( 100),  INT8_C(  67),
        -INT8_C(  66), -INT8_C( 127), -INT8_C( 113),  INT8_C( 101),  INT8_C(  43), -INT8_C( 114), -INT8_C(  81),  INT8_C(  99),
         INT8_C(  94),  INT8_C(  63), -INT8_C( 123),  INT8_C(  83), -INT8_C(  87), -INT8_C(  39),  INT8_C(  38), -INT8_C(  38) },
      {  INT8_C(   0),  INT8_C(   0),  INT8_C(  56),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  12),
        -INT8_C(  17),  INT8_C(  83), -INT8_C(  22),  INT8_C(   0), -INT8_C(  65),  INT8_C(   0),  INT8_C(  92),  INT8_C(  60),
         INT8_C(  65),  INT8_C(   0), -INT8_C(   3),  INT8_C(   0),  INT8_C(   6),  INT8_C(  46),  INT8_C(  62),  INT8_C(   0),
         INT8_C(   0),  INT8_C(   0),  INT8_C(  88),  INT8_C(   0),  INT8_C(   0), -INT8_C(  58), -INT8_C(  89),  INT8_C( 103),
         INT8_C(   0), -INT8_C(  32),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C( 106),  INT8_C(  89),
         INT8_C(   0),  INT8_C(  85),  INT8_C(  62),  INT8_C(  25),  INT8_C(   0), -INT8_C( 101),  INT8_C(  86), -INT8_C( 105),
         INT8_C(   0),  INT8_C(   0),  INT8_C(  63),  INT8_C(   0), -INT8_C( 127),  INT8_C(   0),  INT8_C(   0),  INT8_C(  21),
         INT8_C(   1),  INT8_C(   0),  INT8_C(  86),  INT8_C(   0), -INT8_C( 109), -INT8_C(   3),  INT8_C(   0),  INT8_C(   0) } },
    { UINT64_C(15993249600680009216),
      { -INT8_C( 104), -INT8_C(  12),  INT8_C( 117), -INT8_C(  27), -INT8_C(   5),  INT8_C(  17),  INT8_C(  40), -INT8_C(  70),
        -INT8_C( 110), -INT8_C(  72),  INT8_C(  31), -INT8_C(  66),  INT8_C(  70), -INT8_C(  50),  INT8_C(  33), -INT8_C(  91),
         INT8_C(  13), -INT8_C(  89), -INT8_C(   8), -INT8_C(  74),      INT8_MIN,  INT8_C(  30), -INT8_C( 111),      INT8_MIN,
        -INT8_C(  68),  INT8_C(  65),  INT8_C(  37), -INT8_C( 126), -INT8_C(  79),  INT8_C(  24),  INT8_C(  95),  INT8_C(  73),
         INT8_C(  12), -INT8_C(  43),  INT8_C(  47),  INT8_C(   7), -INT8_C(  26),  INT8_C(  87), -INT8_C(  63),  INT8_C( 121),
         INT8_C(  15), -INT8_C(  32),  INT8_C(  55),  INT8_C(  86), -INT8_C(  82),  INT8_C(  88), -INT8_C(   5), -INT8_C(  69),
        -INT8_C(   1), -INT8_C(  13),  INT8_C( 114),      INT8_MIN,  INT8_C(  17),  INT8_C(   3),  INT8_C(   0), -INT8_C(  51),
         INT8_C(  68),  INT8_C(  37),  INT8_C(  79), -INT8_C(  11),  INT8_C(  61), -INT8_C(  81),  INT8_C(  63),  INT8_C(  73) },
      { -INT8_C( 124),  INT8_C( 110),  INT8_C(  81),  INT8_C( 106), -INT8_C(  59),  INT8_C(  18), -INT8_C(  29), -INT8_C(  43),
        -INT8_C(  13),  INT8_C(  26),  INT8_C(  43), -INT8_C(  95),  INT8_C( 115),  INT8_C(  38),  INT8_C(  93),  INT8_C( 114),
         INT8_C(  25), -INT8_C(  49), -INT8_C(  14),  INT8_C(  42), -INT8_C(  46), -INT8_C(  13), -INT8_C(   9),  INT8_C(  22),
         INT8_C(  24),  INT8_C(  70),  INT8_C(  12),  INT8_C(  86), -INT8_C(  11),  INT8_C(  75), -INT8_C(  97),  INT8_C( 121),
        -INT8_C(  71), -INT8_C(  16), -INT8_C(  28),  INT8_C( 126),  INT8_C(   3), -INT8_C(  57),  INT8_C(  83), -INT8_C(  10),
        -INT8_C(  30),  INT8_C( 126), -INT8_C( 105),  INT8_C(  85), -INT8_C(  92), -INT8_C(  12), -INT8_C(  57), -INT8_C(  67),
        -INT8_C(  61), -INT8_C(  70), -INT8_C(  25), -INT8_C( 107), -INT8_C(  83), -INT8_C(  34), -INT8_C(  84), -INT8_C(  59),
         INT8_C(  37), -INT8_C(  72),  INT8_C(  27),  INT8_C(  26),  INT8_C(   3), -INT8_C(  69), -INT8_C( 108), -INT8_C(  68) },
      {  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
         INT8_C(   0), -INT8_C(  46),  INT8_C(  74),  INT8_C(  95), -INT8_C(  71),  INT8_C(   0),  INT8_C(   0),  INT8_C(  23),
         INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(  82),  INT8_C(  17),  INT8_C(   0), -INT8_C( 106),
         INT8_C(   0),  INT8_C(   0),  INT8_C(  49),  INT8_C(   0),  INT8_C(   0),  INT8_C(  99),  INT8_C(   0), -INT8_C(  62),
         INT8_C(   0), -INT8_C(  59),  INT8_C(  19),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(  20),  INT8_C( 111),
        -INT8_C(  15),  INT8_C(  94), -INT8_C(  50), -INT8_C(  85),  INT8_C(   0),  INT8_C(  76), -INT8_C(  62),  INT8_C(   0),
        -INT8_C(  62), -INT8_C(  83),  INT8_C(   0),  INT8_C(   0), -INT8_C(  66), -INT8_C(  31), -INT8_C(  84), -INT8_C( 110),
         INT8_C( 105),  INT8_C(   0),  INT8_C( 106),  INT8_C(  15),  INT8_C(  64),  INT8_C(   0), -INT8_C(  45),  INT8_C(   5) } },
    { UINT64_C( 2424218903589320875),
      {  INT8_C(  12),  INT8_C(  60),  INT8_C( 118), -INT8_C(  79),  INT8_C(  48),  INT8_C(  62),  INT8_C( 110), -INT8_C(  12),
        -INT8_C(   8),  INT8_C(  86), -INT8_C( 119), -INT8_C(  91),  INT8_C(  52),  INT8_C(  53),  INT8_C( 106),  INT8_C(  89),
        -INT8_C(  19), -INT8_C( 122),  INT8_C( 116), -INT8_C(  16),  INT8_C(  65),  INT8_C(   8), -INT8_C(  84), -INT8_C(  20),
             INT8_MIN, -INT8_C(  25), -INT8_C( 101), -INT8_C(  65),  INT8_C( 117),  INT8_C(  63), -INT8_C(  31), -INT8_C( 127),
         INT8_C( 123),  INT8_C(  87),  INT8_C(  50), -INT8_C(  84), -INT8_C( 107), -INT8_C(  95), -INT8_C(  96), -INT8_C( 115),
        -INT8_C(   9),  INT8_C(  41),  INT8_C(  50),  INT8_C(  43),  INT8_C(  95), -INT8_C(  99), -INT8_C( 123),  INT8_C(  76),
         INT8_C(  35), -INT8_C(   7),  INT8_C(  61),  INT8_C( 100),  INT8_C(   1), -INT8_C(  23),  INT8_C(  80), -INT8_C( 127),
        -INT8_C(  48), -INT8_C(  21),  INT8_C(  64),  INT8_C(  69),  INT8_C(  43),  INT8_C(  33), -INT8_C(  57), -INT8_C(  90) },
      {  INT8_C( 121), -INT8_C(   7),  INT8_C(  82),  INT8_C(  14), -INT8_C( 102), -INT8_C(  14), -INT8_C( 100), -INT8_C( 111),
         INT8_C(  28), -INT8_C(  50), -INT8_C(  67),  INT8_C( 123),  INT8_C( 107),  INT8_C(  66), -INT8_C(  57), -INT8_C( 114),
         INT8_C(  59),  INT8_C(   4), -INT8_C(  14),  INT8_C(  60), -INT8_C(  18),  INT8_C(  67), -INT8_C(  67), -INT8_C(  66),
         INT8_C(  46), -INT8_C(   3),  INT8_C(   4),  INT8_C(  89),  INT8_C(  31), -INT8_C(  53),  INT8_C(   0), -INT8_C( 104),
        -INT8_C(  60),  INT8_C(  82), -INT8_C(  90),  INT8_C(  95),  INT8_C(  69),  INT8_C(  66), -INT8_C(  16),  INT8_C(  97),
         INT8_C(  17), -INT8_C(  83), -INT8_C(  36),  INT8_C( 124), -INT8_C(  17), -INT8_C(  93),  INT8_C(  11),  INT8_C(  42),
        -INT8_C(  88), -INT8_C(   3),  INT8_C( 102), -INT8_C( 106),  INT8_C(  64),  INT8_C(  35),  INT8_C(  84),  INT8_C( 111),
         INT8_C(  33),  INT8_C(  88), -INT8_C(  56),  INT8_C(  64),  INT8_C(  35), -INT8_C(  56), -INT8_C(  40), -INT8_C(  24) },
      { -INT8_C( 123),  INT8_C(  53),  INT8_C(   0), -INT8_C(  65),  INT8_C(   0),  INT8_C(  48),  INT8_C(   0), -INT8_C( 123),
         INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(  32), -INT8_C(  97),  INT8_C( 119),  INT8_C(  49),  INT8_C(   0),
         INT8_C(   0), -INT8_C( 118),  INT8_C(   0),  INT8_C(  44),  INT8_C(  47),  INT8_C(  75),  INT8_C(   0),  INT8_C(   0),
         INT8_C(   0), -INT8_C(  28), -INT8_C(  97),  INT8_C(  24),  INT8_C(   0),  INT8_C(  10),  INT8_C(   0),  INT8_C(  25),
         INT8_C(  63), -INT8_C(  87), -INT8_C(  40),  INT8_C(  11), -INT8_C(  38), -INT8_C(  29),  INT8_C(   0),  INT8_C(   0),
         INT8_C(   0), -INT8_C(  42),  INT8_C(  14), -INT8_C(  89),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C( 118),
         INT8_C(   0),  INT8_C(   0), -INT8_C(  93),  INT8_C(   0),  INT8_C(   0),  INT8_C(  12),  INT8_C(   0), -INT8_C(  16),
        -INT8_C(  15),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  23),  INT8_C(   0),  INT8_C(   0) } },
    { UINT64_C(15186480722153537051),
      { -INT8_C(  27), -INT8_C(  99),  INT8_C(  78), -INT8_C(  44),  INT8_C(  64),  INT8_C(  89), -INT8_C(   1), -INT8_C(  24),
         INT8_C(  87),  INT8_C( 101),  INT8_C( 126), -INT8_C( 105), -INT8_C( 119), -INT8_C(  45),  INT8_C(   6), -INT8_C(  86),
         INT8_C(  43), -INT8_C(  49), -INT8_C(  22),  INT8_C(  79), -INT8_C( 105), -INT8_C(  62),  INT8_C(  55), -INT8_C(  78),
         INT8_C(  64),  INT8_C( 126),  INT8_C(  18),  INT8_C(   1), -INT8_C(  75), -INT8_C(  45), -INT8_C(  45), -INT8_C( 102),
         INT8_C( 112),  INT8_C(  34),  INT8_C( 111), -INT8_C(  79),  INT8_C( 123),  INT8_C( 110), -INT8_C( 103), -INT8_C(  46),
        -INT8_C(  45),  INT8_C(  24),  INT8_C( 106),  INT8_C(  92), -INT8_C(  21),  INT8_C( 112),  INT8_C(   6),  INT8_C(  22),
         INT8_C(  63), -INT8_C(  16),  INT8_C( 101), -INT8_C(  41), -INT8_C(  78), -INT8_C( 100), -INT8_C( 119), -INT8_C(  13),
         INT8_C(  26), -INT8_C( 100), -INT8_C(  12), -INT8_C(  48),  INT8_C( 111), -INT8_C(  56),  INT8_C( 106), -INT8_C(  32) },
      { -INT8_C(  22), -INT8_C(  39), -INT8_C( 111),  INT8_C( 101),  INT8_C(  71),  INT8_C(  42),  INT8_C(  56),  INT8_C(  27),
         INT8_C(  66), -INT8_C(  94),  INT8_C( 119),  INT8_C(  45),  INT8_C(  18),  INT8_C( 126),  INT8_C(  68),  INT8_C(  82),
         INT8_C( 110), -INT8_C(  87),  INT8_C(  41),  INT8_C(  33),  INT8_C(  70), -INT8_C(  78),  INT8_C(  20),  INT8_C(  96),
         INT8_C(  78),  INT8_C(   8),  INT8_C(  48), -INT8_C(  66), -INT8_C(  48), -INT8_C( 101), -INT8_C(  98), -INT8_C(  70),
         INT8_C( 116),  INT8_C(  47),  INT8_C(  32), -INT8_C(  68),  INT8_C(  89),  INT8_C(  88), -INT8_C(  41), -INT8_C( 100),
        -INT8_C(   6),  INT8_C(  78), -INT8_C(  55),  INT8_C(  12), -INT8_C(  52),  INT8_C(  13),  INT8_C(  94),  INT8_C(  59),
        -INT8_C(  73), -INT8_C( 121),  INT8_C(  92), -INT8_C(   3),  INT8_C(  58),  INT8_C( 112),  INT8_C(  93), -INT8_C( 120),
         INT8_C( 120), -INT8_C( 114),  INT8_C(  70),  INT8_C(  73),  INT8_C(  41), -INT8_C(  28),  INT8_C(   3), -INT8_C(  99) },
      { -INT8_C(  49),  INT8_C( 118),  INT8_C(   0),  INT8_C(  57), -INT8_C( 121),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
         INT8_C(   0),  INT8_C(   7), -INT8_C(  11), -INT8_C(  60), -INT8_C( 101),  INT8_C(  81),  INT8_C(  74),  INT8_C(   0),
        -INT8_C( 103),  INT8_C( 120),  INT8_C(  19),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(  75),  INT8_C(   0),
         INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C( 110),  INT8_C( 113),  INT8_C(   0),
        -INT8_C(  28),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C( 112),  INT8_C( 110),
        -INT8_C(  51),  INT8_C( 102),  INT8_C(  51),  INT8_C(   0), -INT8_C(  73),  INT8_C( 125),  INT8_C(   0),  INT8_C(   0),
        -INT8_C(  10),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  26),  INT8_C( 123),
         INT8_C(   0),  INT8_C(  42),  INT8_C(   0),  INT8_C(   0), -INT8_C( 104),  INT8_C(   0),  INT8_C( 109),  INT8_C( 125) } },
    { UINT64_C( 8433325083901633299),
      {      INT8_MAX, -INT8_C(  46), -INT8_C( 126),  INT8_C(  75), -INT8_C(  32), -INT8_C(  32), -INT8_C( 122), -INT8_C( 105),
         INT8_C( 104), -INT8_C(  30), -INT8_C( 108), -INT8_C(  94),  INT8_C(  82), -INT8_C(  15),  INT8_C(  42), -INT8_C(  53),
             INT8_MAX,  INT8_C( 113),  INT8_C(  20), -INT8_C(  88),  INT8_C(  85),  INT8_C(  23),  INT8_C(  70),  INT8_C( 105),
         INT8_C(  59), -INT8_C(  97), -INT8_C(  42), -INT8_C(  74), -INT8_C(  48), -INT8_C(  33),  INT8_C(  44),  INT8_C(  79),
        -INT8_C(  79), -INT8_C(  82), -INT8_C( 102), -INT8_C( 111), -INT8_C( 114),  INT8_C(  33),  INT8_C(  40), -INT8_C(  10),
         INT8_C(   3), -INT8_C(  68), -INT8_C( 104),  INT8_C(  86), -INT8_C(  82), -INT8_C(  61),  INT8_C(  33),  INT8_C(  45),
         INT8_C(  52),  INT8_C(  53), -INT8_C(  42), -INT8_C( 119),  INT8_C(  76),  INT8_C(  28), -INT8_C(  14), -INT8_C( 121),
        -INT8_C(  69), -INT8_C(  56),  INT8_C(  62), -INT8_C( 117), -INT8_C(  89),  INT8_C( 106), -INT8_C(  38),  INT8_C(  89) },
      {  INT8_C(  24),  INT8_C( 117), -INT8_C(  22), -INT8_C(  90), -INT8_C( 106),  INT8_C(  19), -INT8_C(  99), -INT8_C( 103),
        -INT8_C(  49),  INT8_C(  53), -INT8_C(  17),  INT8_C( 125), -INT8_C(   8),  INT8_C(  16), -INT8_C(  85),  INT8_C(  44),
         INT8_C(  69), -INT8_C( 127), -INT8_C(  74), -INT8_C( 110), -INT8_C(  99), -INT8_C(  88),  INT8_C(  25),  INT8_C(  88),
         INT8_C( 113),  INT8_C(  87), -INT8_C(  28),  INT8_C(  24), -INT8_C(  63), -INT8_C(  66),  INT8_C( 113), -INT8_C(  39),
         INT8_C(  51),  INT8_C(  92),      INT8_MIN, -INT8_C(  55),  INT8_C( 111),  INT8_C(  29),  INT8_C(  99),  INT8_C(  62),
         INT8_C(  82),  INT8_C(  82), -INT8_C(  68),  INT8_C(  75),  INT8_C(  99),  INT8_C( 103),  INT8_C( 119), -INT8_C(  88),
        -INT8_C(  24),  INT8_C(  45),  INT8_C(  58), -INT8_C( 123), -INT8_C(  42),  INT8_C(  84), -INT8_C(  35),  INT8_C(  71),
        -INT8_C(  85), -INT8_C(  63),  INT8_C(  95),  INT8_C( 109),      INT8_MIN, -INT8_C(  47),  INT8_C(  70), -INT8_C(  77) },
      { -INT8_C( 105),  INT8_C(  71),  INT8_C(   0),  INT8_C(   0),  INT8_C( 118),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
         INT8_C(  55),  INT8_C(  23),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
        -INT8_C(  60),  INT8_C(   0),  INT8_C(   0),  INT8_C(  58), -INT8_C(  14),  INT8_C(   0),  INT8_C(  95),  INT8_C(   0),
        -INT8_C(  84),  INT8_C(   0), -INT8_C(  70), -INT8_C(  50),  INT8_C(   0), -INT8_C(  99), -INT8_C(  99),  INT8_C(   0),
        -INT8_C(  28),  INT8_C(  10),  INT8_C(   0),  INT8_C(  90), -INT8_C(   3),  INT8_C(  62), -INT8_C( 117),  INT8_C(   0),
         INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(  17),  INT8_C(  42),  INT8_C(   0),  INT8_C(   0),
         INT8_C(  28),  INT8_C(   0),  INT8_C(   0),  INT8_C(  14),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
         INT8_C( 102),  INT8_C(   0), -INT8_C(  99),  INT8_C(   0),  INT8_C(  39),  INT8_C(  59),  INT8_C(  32),  INT8_C(   0) } },
    { UINT64_C( 3952718891158717997),
      {  INT8_C(  50), -INT8_C( 106), -INT8_C( 127), -INT8_C( 107), -INT8_C(   3), -INT8_C(   8),  INT8_C(  62), -INT8_C(  27),
         INT8_C(  38),  INT8_C( 120),  INT8_C( 106), -INT8_C(   4), -INT8_C(  52),  INT8_C(  72),  INT8_C(  67),  INT8_C( 120),
         INT8_C(   9), -INT8_C(  94), -INT8_C(  27), -INT8_C( 119),  INT8_C( 115),  INT8_C(  43),  INT8_C(  61), -INT8_C(  96),
        -INT8_C(  14), -INT8_C(  70),  INT8_C(  60), -INT8_C(  43), -INT8_C( 102),  INT8_C(  23),  INT8_C(  11), -INT8_C(  52),
        -INT8_C(  83), -INT8_C( 116),  INT8_C(  98), -INT8_C(  85), -INT8_C( 123), -INT8_C(  96), -INT8_C( 112), -INT8_C(  85),
         INT8_C(  24), -INT8_C(   5), -INT8_C(  89), -INT8_C(  27),  INT8_C(  67), -INT8_C(  22),  INT8_C(  93),  INT8_C(  76),
        -INT8_C( 116),  INT8_C(  66), -INT8_C(  42),  INT8_C(   0),  INT8_C( 109),  INT8_C(  19), -INT8_C(  96),  INT8_C(  95),
        -INT8_C(  51), -INT8_C(  35),  INT8_C(  53),  INT8_C( 103), -INT8_C(  12),  INT8_C(  64),  INT8_C(  51), -INT8_C(  95) },
      { -INT8_C(  51), -INT8_C( 107),  INT8_C(  76),  INT8_C(  82),  INT8_C(  53), -INT8_C(  35), -INT8_C(   3),  INT8_C(  78),
        -INT8_C(  40), -INT8_C(  92),  INT8_C(  51),  INT8_C(  27), -INT8_C( 114), -INT8_C( 112),  INT8_C( 103),  INT8_C(  26),
        -INT8_C(  46),  INT8_C(  61),  INT8_C(  26),  INT8_C(  63),  INT8_C(  80), -INT8_C(  69), -INT8_C(  97),  INT8_C(  29),
        -INT8_C( 104), -INT8_C(  44), -INT8_C( 124), -INT8_C( 116),  INT8_C(  20), -INT8_C(  72),  INT8_C(  45), -INT8_C(  31),
         INT8_C(  77),  INT8_C( 122),  INT8_C(  51), -INT8_C( 125),  INT8_C(  87),  INT8_C(  48), -INT8_C(  47),  INT8_C(  47),
        -INT8_C(  44),  INT8_C(   4),  INT8_C(  74),  INT8_C(  98), -INT8_C( 108), -INT8_C(  79),  INT8_C( 125),  INT8_C( 102),
        -INT8_C(  17), -INT8_C( 105), -INT8_C(  91),  INT8_C(  63),  INT8_C(  82),  INT8_C(  68),  INT8_C(  93), -INT8_C(  22),
         INT8_C(  24), -INT8_C(  31),  INT8_C( 118),  INT8_C(  45), -INT8_C( 103), -INT8_C(  92),  INT8_C(  14), -INT8_C(  25) },
      { -INT8_C(   1),  INT8_C(   0), -INT8_C(  51), -INT8_C(  25),  INT8_C(   0), -INT8_C(  43),  INT8_C(   0),  INT8_C(   0),
         INT8_C(   0),  INT8_C(  28), -INT8_C(  99),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  86), -INT8_C( 110),
        -INT8_C(  37),  INT8_C(   0), -INT8_C(   1), -INT8_C(  56), -INT8_C(  61), -INT8_C(  26), -INT8_C(  36),  INT8_C(   0),
         INT8_C(   0),  INT8_C(   0), -INT8_C(  64),  INT8_C(  97), -INT8_C(  82),  INT8_C(   0),  INT8_C(   0), -INT8_C(  83),
        -INT8_C(   6),  INT8_C(   6),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  48),  INT8_C(  97), -INT8_C(  38),
         INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C( 101), -INT8_C(  38), -INT8_C(  78),
         INT8_C(   0), -INT8_C(  39),  INT8_C(   0),  INT8_C(  63), -INT8_C(  65),  INT8_C(   0), -INT8_C(   3),  INT8_C(  73),
         INT8_C(   0), -INT8_C(  66), -INT8_C(  85),  INT8_C(   0), -INT8_C( 115), -INT8_C(  28),  INT8_C(   0),  INT8_C(   0) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i a = simde_mm512_loadu_epi8(test_vec[i].a);
    simde__m512i b = simde_mm512_loadu_epi8(test_vec[i].b);
    simde__m512i r = simde_mm512_maskz_add_epi8(test_vec[i].k, a, b);
    simde_test_x86_assert_equal_i8x64(r, simde_mm512_loadu_epi8(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_mm512_add_epi16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    const int16_t a[32];
    const int16_t b[32];
    const int16_t r[32];
  } test_vec[] = {
    { {  INT16_C( 11452),  INT16_C( 18562),  INT16_C(  2675), -INT16_C( 17089),  INT16_C( 30550), -INT16_C( 14832), -INT16_C( 11694), -INT16_C( 20057),
         INT16_C( 31125),  INT16_C(  7807), -INT16_C( 11481),  INT16_C( 12519), -INT16_C(   410), -INT16_C( 11992),  INT16_C( 27537),  INT16_C( 19885),
         INT16_C( 12440),  INT16_C(  2965), -INT16_C( 11206), -INT16_C( 28472), -INT16_C( 10164), -INT16_C( 25001), -INT16_C(   342),  INT16_C( 16463),
        -INT16_C( 12424), -INT16_C( 24738),  INT16_C( 17826),  INT16_C(  2255), -INT16_C(  1981), -INT16_C( 11047), -INT16_C( 30877), -INT16_C(  1246) },
      { -INT16_C( 18505), -INT16_C(  3833), -INT16_C( 12404), -INT16_C( 10111), -INT16_C( 10072),  INT16_C( 21110), -INT16_C( 14633),  INT16_C( 20370),
        -INT16_C(  3947),  INT16_C( 14318), -INT16_C( 17098),  INT16_C( 31040),  INT16_C(  6581),  INT16_C(  6478),  INT16_C( 28832),  INT16_C( 22292),
         INT16_C(  6951), -INT16_C( 19640), -INT16_C( 13589), -INT16_C( 27765),  INT16_C(   674),  INT16_C( 31205),  INT16_C( 30920),  INT16_C( 24008),
        -INT16_C( 18840), -INT16_C( 24940), -INT16_C( 11148),  INT16_C( 10520),  INT16_C( 26350), -INT16_C( 29118),  INT16_C( 22486), -INT16_C(   538) },
      { -INT16_C(  7053),  INT16_C( 14729), -INT16_C(  9729), -INT16_C( 27200),  INT16_C( 20478),  INT16_C(  6278), -INT16_C( 26327),  INT16_C(   313),
         INT16_C( 27178),  INT16_C( 22125), -INT16_C( 28579), -INT16_C( 21977),  INT16_C(  6171), -INT16_C(  5514), -INT16_C(  9167), -INT16_C( 23359),
         INT16_C( 19391), -INT16_C( 16675), -INT16_C( 24795),  INT16_C(  9299), -INT16_C(  9490),  INT16_C(  6204),  INT16_C( 30578), -INT16_C( 25065),
        -INT16_C( 31264),  INT16_C( 15858),  INT16_C(  6678),  INT16_C( 12775),  INT16_C( 24369),  INT16_C( 25371), -INT16_C(  8391), -INT16_C(  1784) } },
    { {  INT16_C( 11890),  INT16_C( 23985),  INT16_C( 15608), -INT16_C( 25616), -INT16_C( 10690),  INT16_C(  1556), -INT16_C(  8882), -INT16_C( 18845),
        -INT16_C(  1901),  INT16_C(  1877),  INT16_C( 28108), -INT16_C( 17871),  INT16_C( 29651), -INT16_C( 22199),  INT16_C( 12234),  INT16_C( 15782),
         INT16_C( 22365),  INT16_C( 22170), -INT16_C( 29804), -INT16_C( 11535),  INT16_C(  1377), -INT16_C( 20519),  INT16_C( 15586),  INT16_C( 30309),
        -INT16_C( 17868),  INT16_C(   381), -INT16_C( 20953), -INT16_C(  1349),  INT16_C(  1058), -INT16_C(  4957),  INT16_C( 18995), -INT16_C( 28375) },
      { -INT16_C( 15199),  INT16_C( 13799), -INT16_C( 10161), -INT16_C( 20472), -INT16_C(  7715), -INT16_C( 16289), -INT16_C( 15331),  INT16_C( 21046),
        -INT16_C( 19585), -INT16_C( 22957),  INT16_C(  3682), -INT16_C( 31583),  INT16_C( 17427),  INT16_C( 18032), -INT16_C( 25970),  INT16_C( 12503),
        -INT16_C( 16802), -INT16_C( 21147),  INT16_C( 28054),  INT16_C( 29789), -INT16_C( 17330),  INT16_C( 27700),  INT16_C( 27264), -INT16_C(    66),
         INT16_C(  4381),  INT16_C( 32678),  INT16_C( 18207),  INT16_C( 12803),  INT16_C( 29835),  INT16_C(  6777),  INT16_C( 20494),  INT16_C( 27722) },
      { -INT16_C(  3309), -INT16_C( 27752),  INT16_C(  5447),  INT16_C( 19448), -INT16_C( 18405), -INT16_C( 14733), -INT16_C( 24213),  INT16_C(  2201),
        -INT16_C( 21486), -INT16_C( 21080),  INT16_C( 31790),  INT16_C( 16082), -INT16_C( 18458), -INT16_C(  4167), -INT16_C( 13736),  INT16_C( 28285),
         INT16_C(  5563),  INT16_C(  1023), -INT16_C(  1750),  INT16_C( 18254), -INT16_C( 15953),  INT16_C(  7181), -INT16_C( 22686),  INT16_C( 30243),
        -INT16_C( 13487), -INT16_C( 32477), -INT16_C(  2746),  INT16_C( 11454),  INT16_C( 30893),  INT16_C(  1820), -INT16_C( 26047), -INT16_C(   653) } },
    { { -INT16_C( 20721), -INT16_C( 23271),  INT16_C( 30237),  INT16_C( 27417),  INT16_C( 19762), -INT16_C( 19753), -INT16_C( 27209), -INT16_C( 10830),
         INT16_C( 22694), -INT16_C( 14764),  INT16_C( 22687),  INT16_C( 11000),  INT16_C( 29132), -INT16_C(  9660), -INT16_C( 28990), -INT16_C( 11962),
         INT16_C( 24382),  INT16_C( 23414), -INT16_C( 28459),  INT16_C(  1990), -INT16_C( 24867), -INT16_C( 27207),  INT16_C( 27443), -INT16_C(  9622),
        -INT16_C( 16701),  INT16_C( 25248), -INT16_C( 26602), -INT16_C(  7539), -INT16_C( 12022), -INT16_C( 13124),  INT16_C(   608), -INT16_C( 24931) },
      {  INT16_C(  4961),  INT16_C( 14073), -INT16_C( 16477), -INT16_C( 32451), -INT16_C(  2211), -INT16_C( 28394), -INT16_C( 32670),  INT16_C(  9835),
         INT16_C(  2878),  INT16_C( 21896),  INT16_C(  5539), -INT16_C( 21193), -INT16_C(  2841),  INT16_C( 18297),  INT16_C(  5878),  INT16_C( 22757),
        -INT16_C(  8662), -INT16_C( 12914), -INT16_C( 13155), -INT16_C(  1202),  INT16_C( 25795),  INT16_C(  9612), -INT16_C(  2076),  INT16_C(  9035),
        -INT16_C( 11262), -INT16_C( 23176), -INT16_C( 20503), -INT16_C( 12205), -INT16_C( 13149), -INT16_C( 26089), -INT16_C(   797),  INT16_C(  3570) },
      { -INT16_C( 15760), -INT16_C(  9198),  INT16_C( 13760), -INT16_C(  5034),  INT16_C( 17551),  INT16_C( 17389),  INT16_C(  5657), -INT16_C(   995),
         INT16_C( 25572),  INT16_C(  7132),  INT16_C( 28226), -INT16_C( 10193),  INT16_C( 26291),  INT16_C(  8637), -INT16_C( 23112),  INT16_C( 10795),
         INT16_C( 15720),  INT16_C( 10500),  INT16_C( 23922),  INT16_C(   788),  INT16_C(   928), -INT16_C( 17595),  INT16_C( 25367), -INT16_C(   587),
        -INT16_C( 27963),  INT16_C(  2072),  INT16_C( 18431), -INT16_C( 19744), -INT16_C( 25171),  INT16_C( 26323), -INT16_C(   189), -INT16_C( 21361) } },
    { { -INT16_C( 32550),  INT16_C( 30938),  INT16_C( 10572),  INT16_C(  3955), -INT16_C(   115),  INT16_C( 29237), -INT16_C( 32522), -INT16_C(  1899),
         INT16_C(  3412),  INT16_C( 16029), -INT16_C(  3908),  INT16_C( 24590),  INT16_C(  9917), -INT16_C( 24326), -INT16_C(  5086), -INT16_C(   595),
        -INT16_C( 30868), -INT16_C( 18059), -INT16_C(  5968),  INT16_C( 16072), -INT16_C(   537), -INT16_C(  8784),  INT16_C( 17790), -INT16_C( 11563),
         INT16_C( 29266),  INT16_C(  3600),  INT16_C(  8035),  INT16_C(  8302),  INT16_C( 26693),  INT16_C( 26560),  INT16_C( 27988), -INT16_C( 16028) },
      { -INT16_C(  9740), -INT16_C( 23174),  INT16_C( 17089), -INT16_C( 22301), -INT16_C( 27840), -INT16_C( 16763),  INT16_C( 23256),  INT16_C( 10896),
        -INT16_C( 24115),  INT16_C( 12344), -INT16_C( 22592),  INT16_C(  1360),  INT16_C(  4111),  INT16_C( 25708), -INT16_C( 11907),  INT16_C( 28965),
        -INT16_C( 24662),  INT16_C( 27670), -INT16_C(  1567),  INT16_C(  8468), -INT16_C( 25972),  INT16_C( 25823),  INT16_C( 28916), -INT16_C( 15986),
        -INT16_C( 14575), -INT16_C( 11791),  INT16_C( 16750),  INT16_C( 32214),  INT16_C( 16977), -INT16_C( 12575),  INT16_C(  1555), -INT16_C( 16832) },
      {  INT16_C( 23246),  INT16_C(  7764),  INT16_C( 27661), -INT16_C( 18346), -INT16_C( 27955),  INT16_C( 12474), -INT16_C(  9266),  INT16_C(  8997),
        -INT16_C( 20703),  INT16_C( 28373), -INT16_C( 26500),  INT16_C( 25950),  INT16_C( 14028),  INT16_C(  1382), -INT16_C( 16993),  INT16_C( 28370),
         INT16_C( 10006),  INT16_C(  9611), -INT16_C(  7535),  INT16_C( 24540), -INT16_C( 26509),  INT16_C( 17039), -INT16_C( 18830), -INT16_C( 27549),
         INT16_C( 14691), -INT16_C(  8191),  INT16_C( 24785), -INT16_C( 25020), -INT16_C( 21866),  INT16_C( 13985),  INT16_C( 29543),  INT16_C( 32676) } },
    { {  INT16_C( 22181), -INT16_C( 30934),  INT16_C( 15952), -INT16_C(  9048), -INT16_C( 30504), -INT16_C( 12991), -INT16_C( 12296),  INT16_C(  2446),
        -INT16_C( 32618),  INT16_C(  1242), -INT16_C( 20287),  INT16_C(  4994),  INT16_C( 25586),  INT16_C(  1761),  INT16_C(  8554),  INT16_C(  4036),
        -INT16_C(  4488), -INT16_C( 14186),  INT16_C( 16172),  INT16_C(  1444), -INT16_C(  6713), -INT16_C( 16430),  INT16_C( 24757),  INT16_C( 19400),
        -INT16_C( 23840), -INT16_C( 23984), -INT16_C( 11694),  INT16_C( 17589), -INT16_C( 27083), -INT16_C( 24758),  INT16_C(  3768),  INT16_C( 12463) },
      {  INT16_C( 17916),  INT16_C( 10744), -INT16_C( 25468),  INT16_C( 19246),  INT16_C(   130),  INT16_C( 14090), -INT16_C( 11680),  INT16_C( 16770),
        -INT16_C( 11660), -INT16_C( 14621), -INT16_C( 26460), -INT16_C(  9717),  INT16_C( 21806), -INT16_C(  6535),  INT16_C( 10340),  INT16_C( 24598),
         INT16_C(  3694), -INT16_C(  3447), -INT16_C( 18517),  INT16_C( 11582),  INT16_C( 18615),  INT16_C(  6244), -INT16_C(  6629), -INT16_C( 28839),
         INT16_C( 15545),  INT16_C( 23894),  INT16_C( 25044),  INT16_C(   567), -INT16_C( 20042),  INT16_C(  6889), -INT16_C(    39),  INT16_C( 18299) },
      { -INT16_C( 25439), -INT16_C( 20190), -INT16_C(  9516),  INT16_C( 10198), -INT16_C( 30374),  INT16_C(  1099), -INT16_C( 23976),  INT16_C( 19216),
         INT16_C( 21258), -INT16_C( 13379),  INT16_C( 18789), -INT16_C(  4723), -INT16_C( 18144), -INT16_C(  4774),  INT16_C( 18894),  INT16_C( 28634),
        -INT16_C(   794), -INT16_C( 17633), -INT16_C(  2345),  INT16_C( 13026),  INT16_C( 11902), -INT16_C( 10186),  INT16_C( 18128), -INT16_C(  9439),
        -INT16_C(  8295), -INT16_C(    90),  INT16_C( 13350),  INT16_C( 18156),  INT16_C( 18411), -INT16_C( 17869),  INT16_C(  3729),  INT16_C( 30762) } },
    { {  INT16_C(  1038), -INT16_C( 18118),  INT16_C( 30908),  INT16_C( 29670),  INT16_C( 19136), -INT16_C(  9333), -INT16_C(  7120), -INT16_C(  5781),
        -INT16_C( 16096), -INT16_C(  3001),  INT16_C( 32290), -INT16_C(  9993), -INT16_C(  8145),  INT16_C(  2547),  INT16_C( 28383), -INT16_C(  4784),
        -INT16_C( 30094),  INT16_C( 11942), -INT16_C( 29694), -INT16_C( 15454),  INT16_C( 11734),  INT16_C(  1950),  INT16_C(  2322),  INT16_C( 13040),
         INT16_C( 14282), -INT16_C(  5081),  INT16_C(  7862), -INT16_C(  6715), -INT16_C( 18178), -INT16_C(  8722),  INT16_C( 16166), -INT16_C( 26421) },
      {  INT16_C( 29129), -INT16_C( 13113),  INT16_C( 27134), -INT16_C( 11121),  INT16_C( 11670), -INT16_C( 22309), -INT16_C( 13257),  INT16_C(   475),
         INT16_C(   515), -INT16_C( 17938), -INT16_C( 19680),  INT16_C(  7839), -INT16_C( 29333), -INT16_C( 28165), -INT16_C( 14644), -INT16_C( 27095),
        -INT16_C(  4040),  INT16_C( 13922), -INT16_C(  3751), -INT16_C(  4086), -INT16_C(  6626),  INT16_C( 21912),  INT16_C( 29618), -INT16_C( 19113),
         INT16_C( 17781), -INT16_C( 27281),  INT16_C(  3832),  INT16_C( 25523), -INT16_C( 20581),  INT16_C( 26868),  INT16_C(  7541), -INT16_C( 20994) },
      {  INT16_C( 30167), -INT16_C( 31231), -INT16_C(  7494),  INT16_C( 18549),  INT16_C( 30806), -INT16_C( 31642), -INT16_C( 20377), -INT16_C(  5306),
        -INT16_C( 15581), -INT16_C( 20939),  INT16_C( 12610), -INT16_C(  2154),  INT16_C( 28058), -INT16_C( 25618),  INT16_C( 13739), -INT16_C( 31879),
         INT16_C( 31402),  INT16_C( 25864),  INT16_C( 32091), -INT16_C( 19540),  INT16_C(  5108),  INT16_C( 23862),  INT16_C( 31940), -INT16_C(  6073),
         INT16_C( 32063), -INT16_C( 32362),  INT16_C( 11694),  INT16_C( 18808),  INT16_C( 26777),  INT16_C( 18146),  INT16_C( 23707),  INT16_C( 18121) } },
    { {  INT16_C( 24590),  INT16_C( 26595), -INT16_C(  4527),  INT16_C( 28503), -INT16_C(  3884), -INT16_C( 31035),  INT16_C(  7267), -INT16_C(  9925),
        -INT16_C( 21919),  INT16_C( 22894),  INT16_C(  8888),  INT16_C( 21692), -INT16_C( 20271),  INT16_C( 18108), -INT16_C( 17715), -INT16_C(  9228),
        -INT16_C( 10470),  INT16_C( 27459), -INT16_C( 25915), -INT16_C( 26150), -INT16_C( 24694), -INT16_C(  4577),  INT16_C( 23483),  INT16_C(  7367),
         INT16_C( 13573), -INT16_C( 16779),  INT16_C( 12631),  INT16_C( 10258), -INT16_C( 12575), -INT16_C( 20625),  INT16_C( 25480), -INT16_C( 23926) },
      { -INT16_C( 12998),  INT16_C(    13), -INT16_C(  6296), -INT16_C(  3431), -INT16_C( 18041),  INT16_C( 17120), -INT16_C( 22764),  INT16_C(  6495),
        -INT16_C( 11043),  INT16_C( 13527), -INT16_C(  5882), -INT16_C(  6307), -INT16_C( 13129),  INT16_C( 16278),  INT16_C(  8495),  INT16_C( 27105),
        -INT16_C(  4370),  INT16_C( 22121),  INT16_C(   982),  INT16_C( 23881),  INT16_C( 10684), -INT16_C( 12129), -INT16_C(   303), -INT16_C( 20759),
        -INT16_C( 15917), -INT16_C(  9758),  INT16_C( 16298),  INT16_C( 25280),  INT16_C( 22283),  INT16_C( 15009), -INT16_C( 31880),  INT16_C( 26276) },
      {  INT16_C( 11592),  INT16_C( 26608), -INT16_C( 10823),  INT16_C( 25072), -INT16_C( 21925), -INT16_C( 13915), -INT16_C( 15497), -INT16_C(  3430),
         INT16_C( 32574), -INT16_C( 29115),  INT16_C(  3006),  INT16_C( 15385),  INT16_C( 32136), -INT16_C( 31150), -INT16_C(  9220),  INT16_C( 17877),
        -INT16_C( 14840), -INT16_C( 15956), -INT16_C( 24933), -INT16_C(  2269), -INT16_C( 14010), -INT16_C( 16706),  INT16_C( 23180), -INT16_C( 13392),
        -INT16_C(  2344), -INT16_C( 26537),  INT16_C( 28929), -INT16_C( 29998),  INT16_C(  9708), -INT16_C(  5616), -INT16_C(  6400),  INT16_C(  2350) } },
    { {  INT16_C(  3441),  INT16_C( 18365),  INT16_C(  1552), -INT16_C( 13148),  INT16_C( 17455),  INT16_C(   156), -INT16_C( 31166),  INT16_C(  5550),
        -INT16_C( 28345), -INT16_C(  3602), -INT16_C( 20528), -INT16_C(  9133), -INT16_C(  2810),  INT16_C( 32278), -INT16_C( 17800), -INT16_C(  5660),
        -INT16_C( 24120), -INT16_C( 10191), -INT16_C( 10841), -INT16_C( 10331),  INT16_C( 16665),  INT16_C( 23767), -INT16_C( 31033),  INT16_C(  3697),
         INT16_C( 24599), -INT16_C(  6400),  INT16_C( 21263),  INT16_C(  5571), -INT16_C(  9656), -INT16_C( 16237),  INT16_C( 30612),  INT16_C( 23722) },
      { -INT16_C(  9447), -INT16_C( 16331), -INT16_C(  9552), -INT16_C( 13673),  INT16_C( 28443), -INT16_C(  7386), -INT16_C( 26635),  INT16_C(  3313),
        -INT16_C(  3593),  INT16_C(  1779), -INT16_C( 18619), -INT16_C( 29413), -INT16_C( 20847),  INT16_C(  9550), -INT16_C(  2010),  INT16_C( 16258),
        -INT16_C( 18477), -INT16_C( 31745), -INT16_C( 26735), -INT16_C( 21427),  INT16_C( 29446), -INT16_C(  1137), -INT16_C( 32501),  INT16_C(   519),
        -INT16_C(  1422), -INT16_C( 18679),  INT16_C(  9393),  INT16_C( 16965), -INT16_C( 27693), -INT16_C(  1688), -INT16_C(  5493),  INT16_C( 24120) },
      { -INT16_C(  6006),  INT16_C(  2034), -INT16_C(  8000), -INT16_C( 26821), -INT16_C( 19638), -INT16_C(  7230),  INT16_C(  7735),  INT16_C(  8863),
        -INT16_C( 31938), -INT16_C(  1823),  INT16_C( 26389),  INT16_C( 26990), -INT16_C( 23657), -INT16_C( 23708), -INT16_C( 19810),  INT16_C( 10598),
         INT16_C( 22939),  INT16_C( 23600),  INT16_C( 27960), -INT16_C( 31758), -INT16_C( 19425),  INT16_C( 22630),  INT16_C(  2002),  INT16_C(  4216),
         INT16_C( 23177), -INT16_C( 25079),  INT16_C( 30656),  INT16_C( 22536),  INT16_C( 28187), -INT16_C( 17925),  INT16_C( 25119), -INT16_C( 17694) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i a = simde_mm512_loadu_epi16(test_vec[i].a);
    simde__m512i b = simde_mm512_loadu_epi16(test_vec[i].b);
    simde__m512i r = simde_mm512_add_epi16(a, b);
    simde_test_x86_assert_equal_i16x32(r, simde_mm512_loadu_epi16(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_mm512_mask_add_epi16 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const int16_t src[32];
    const simde__mmask32 k;
    const int16_t a[32];
    const int16_t b[32];
    const int16_t r[32];
  } test_vec[] = {
    { {  INT16_C( 19989),  INT16_C( 17201), -INT16_C(   484), -INT16_C(  4807), -INT16_C( 18583),  INT16_C(  7804),  INT16_C( 26728),  INT16_C( 16294),
        -INT16_C( 31636),  INT16_C( 28135), -INT16_C( 32158),  INT16_C( 20064), -INT16_C( 16695),  INT16_C(  3157),  INT16_C( 32300),  INT16_C( 16873),
         INT16_C(  6860), -INT16_C(  5755), -INT16_C( 16872), -INT16_C( 32042),  INT16_C( 21110), -INT16_C(  8544),  INT16_C( 18106),  INT16_C(  9757),
         INT16_C(  1482),  INT16_C( 11668), -INT16_C(  2937),  INT16_C( 20859), -INT16_C( 12110), -INT16_C(  8611),  INT16_C( 17999),  INT16_C(  6944) },
      UINT32_C(2030347617),
      { -INT16_C( 25811), -INT16_C(  6217), -INT16_C( 10782), -INT16_C( 21490), -INT16_C( 23846),  INT16_C( 25049),  INT16_C( 21910),  INT16_C( 18610),
         INT16_C(  4133),  INT16_C( 29734),  INT16_C( 18006), -INT16_C( 18544), -INT16_C( 27413),  INT16_C( 20273),  INT16_C( 11375), -INT16_C( 25560),
        -INT16_C(  7992), -INT16_C( 21885), -INT16_C( 28235), -INT16_C( 28842),  INT16_C( 12339), -INT16_C( 13840), -INT16_C( 23675), -INT16_C( 21999),
         INT16_C( 14515),  INT16_C(  2335), -INT16_C( 20610),  INT16_C( 27329), -INT16_C(  3517), -INT16_C( 19783), -INT16_C(  7906), -INT16_C(  6578) },
      { -INT16_C( 11583),  INT16_C( 30352), -INT16_C(  6301), -INT16_C( 26875), -INT16_C(  2537), -INT16_C( 25504),  INT16_C( 29337),  INT16_C( 19526),
         INT16_C( 26026),  INT16_C( 10325),  INT16_C(  5652),  INT16_C( 22674),  INT16_C( 19208),  INT16_C(  9994),  INT16_C( 22829), -INT16_C(  4595),
        -INT16_C( 25045), -INT16_C( 29083),  INT16_C( 27269), -INT16_C( 25563), -INT16_C( 31136), -INT16_C(  1736),  INT16_C( 32504), -INT16_C( 23995),
        -INT16_C( 25628), -INT16_C(  1846),  INT16_C( 23985), -INT16_C( 17840),  INT16_C( 23464), -INT16_C( 10783), -INT16_C(  4428), -INT16_C(  8252) },
      {  INT16_C( 28142),  INT16_C( 17201), -INT16_C(   484), -INT16_C(  4807), -INT16_C( 18583), -INT16_C(   455), -INT16_C( 14289),  INT16_C( 16294),
         INT16_C( 30159),  INT16_C( 28135),  INT16_C( 23658),  INT16_C( 20064), -INT16_C( 16695),  INT16_C( 30267),  INT16_C( 32300), -INT16_C( 30155),
         INT16_C(  6860), -INT16_C(  5755), -INT16_C(   966), -INT16_C( 32042),  INT16_C( 21110), -INT16_C(  8544),  INT16_C( 18106),  INT16_C(  9757),
        -INT16_C( 11113),  INT16_C( 11668), -INT16_C(  2937),  INT16_C(  9489),  INT16_C( 19947), -INT16_C( 30566), -INT16_C( 12334),  INT16_C(  6944) } },
    { {  INT16_C( 10636),  INT16_C(  4461), -INT16_C( 27757), -INT16_C(  2899), -INT16_C(  6887),  INT16_C(  4589),  INT16_C( 13156),  INT16_C( 18611),
         INT16_C( 32206),  INT16_C( 32576), -INT16_C( 28198), -INT16_C( 31943),  INT16_C(  6892), -INT16_C( 24488),  INT16_C(  7177), -INT16_C( 27265),
        -INT16_C(  5051), -INT16_C(  9817),  INT16_C( 21631), -INT16_C( 26419), -INT16_C( 17862), -INT16_C( 24919),  INT16_C( 23789), -INT16_C( 17434),
         INT16_C(  9946), -INT16_C( 19397),  INT16_C( 29879), -INT16_C( 23753), -INT16_C( 28529), -INT16_C( 26557), -INT16_C( 15700), -INT16_C(  3539) },
      UINT32_C( 785110191),
      {  INT16_C( 28754),  INT16_C( 16385), -INT16_C(  6195), -INT16_C( 22533),  INT16_C( 13837), -INT16_C( 15013), -INT16_C( 27733),  INT16_C( 14952),
        -INT16_C( 21469), -INT16_C( 12334), -INT16_C(   146),  INT16_C(  7617), -INT16_C( 29484), -INT16_C(   692),  INT16_C(  4900),  INT16_C( 30560),
         INT16_C( 24963),  INT16_C( 20663), -INT16_C( 19896),  INT16_C( 22007),  INT16_C( 21481), -INT16_C( 27622), -INT16_C( 31770),  INT16_C(  2510),
        -INT16_C( 24529), -INT16_C( 25128), -INT16_C( 25953),  INT16_C( 29627),  INT16_C(  1830),  INT16_C( 19312), -INT16_C( 12262), -INT16_C( 25150) },
      {  INT16_C( 31025),  INT16_C( 31214), -INT16_C(  6869),  INT16_C(  5327), -INT16_C(  5832),  INT16_C(  7848),  INT16_C( 30316), -INT16_C( 25817),
         INT16_C(    22), -INT16_C( 18887), -INT16_C(  2918), -INT16_C( 16343), -INT16_C( 25861),  INT16_C(  5387), -INT16_C( 12950), -INT16_C( 25422),
        -INT16_C( 24506),  INT16_C( 29205), -INT16_C(  7034), -INT16_C( 16762),  INT16_C( 12238),  INT16_C( 15069),  INT16_C(  1189), -INT16_C( 17194),
         INT16_C(  3844), -INT16_C( 24974), -INT16_C( 25853), -INT16_C(   417),  INT16_C( 27189), -INT16_C( 24557), -INT16_C( 15048),  INT16_C( 32316) },
      { -INT16_C(  5757), -INT16_C( 17937), -INT16_C( 13064), -INT16_C( 17206), -INT16_C(  6887), -INT16_C(  7165),  INT16_C( 13156), -INT16_C( 10865),
         INT16_C( 32206),  INT16_C( 32576), -INT16_C(  3064), -INT16_C( 31943),  INT16_C( 10191), -INT16_C( 24488), -INT16_C(  8050),  INT16_C(  5138),
         INT16_C(   457), -INT16_C( 15668),  INT16_C( 21631),  INT16_C(  5245), -INT16_C( 17862), -INT16_C( 24919), -INT16_C( 30581), -INT16_C( 14684),
         INT16_C(  9946),  INT16_C( 15434),  INT16_C( 13730),  INT16_C( 29210), -INT16_C( 28529), -INT16_C(  5245), -INT16_C( 15700), -INT16_C(  3539) } },
    { {  INT16_C( 20838), -INT16_C(  4880),  INT16_C( 30518),  INT16_C(  1194), -INT16_C( 30810),  INT16_C( 19262),  INT16_C(  5260), -INT16_C( 28665),
         INT16_C( 31011),  INT16_C(  9775), -INT16_C( 29163),  INT16_C( 18980),  INT16_C( 14328),  INT16_C( 12522),  INT16_C(  9981),  INT16_C( 25519),
        -INT16_C( 24712), -INT16_C( 20913), -INT16_C(  1770), -INT16_C( 17230), -INT16_C(  3967),  INT16_C(  3336),  INT16_C(  3845),  INT16_C( 10397),
        -INT16_C( 13175), -INT16_C( 25009),  INT16_C( 29530),  INT16_C( 21480), -INT16_C( 11349), -INT16_C( 22397),  INT16_C( 13049),  INT16_C( 28939) },
      UINT32_C(3894368978),
      { -INT16_C( 21054), -INT16_C( 14367),  INT16_C( 32700),  INT16_C( 17903),  INT16_C( 15947), -INT16_C( 22813), -INT16_C( 13134),  INT16_C( 24057),
         INT16_C( 31903), -INT16_C( 26619),  INT16_C(  4271), -INT16_C( 32502),  INT16_C( 10602), -INT16_C( 17047),  INT16_C(  3835), -INT16_C( 17006),
         INT16_C( 29627),  INT16_C( 30852),  INT16_C( 29682),  INT16_C( 16061), -INT16_C( 24142),  INT16_C( 25828), -INT16_C(  8851),  INT16_C(  3265),
        -INT16_C( 14759),  INT16_C(  2212), -INT16_C( 20778),  INT16_C( 16521), -INT16_C(  3112), -INT16_C( 11267), -INT16_C( 28927), -INT16_C( 17008) },
      {  INT16_C(  5123), -INT16_C(  2763), -INT16_C(  3449),  INT16_C( 14643),  INT16_C(  6035),  INT16_C(   157),  INT16_C( 24308),  INT16_C( 19980),
        -INT16_C( 20188), -INT16_C(  1450), -INT16_C(  8097),  INT16_C( 14138),  INT16_C( 14547), -INT16_C( 11254), -INT16_C( 25913), -INT16_C( 13679),
        -INT16_C( 14674),  INT16_C( 14016), -INT16_C(  3143),  INT16_C( 19567),  INT16_C(  3339), -INT16_C(   179),  INT16_C( 22891), -INT16_C( 28595),
        -INT16_C( 23542),  INT16_C( 27274), -INT16_C( 14972),  INT16_C( 22433), -INT16_C( 21251), -INT16_C( 15317), -INT16_C( 17082), -INT16_C(  2673) },
      {  INT16_C( 20838), -INT16_C( 17130),  INT16_C( 30518),  INT16_C(  1194),  INT16_C( 21982),  INT16_C( 19262),  INT16_C( 11174), -INT16_C( 21499),
         INT16_C( 31011), -INT16_C( 28069), -INT16_C( 29163), -INT16_C( 18364),  INT16_C( 25149),  INT16_C( 12522), -INT16_C( 22078),  INT16_C( 25519),
         INT16_C( 14953), -INT16_C( 20668),  INT16_C( 26539), -INT16_C( 29908), -INT16_C( 20803),  INT16_C(  3336),  INT16_C(  3845),  INT16_C( 10397),
        -INT16_C( 13175), -INT16_C( 25009),  INT16_C( 29530), -INT16_C( 26582), -INT16_C( 11349), -INT16_C( 26584),  INT16_C( 19527), -INT16_C( 19681) } },
    { {  INT16_C( 20355),  INT16_C( 15403), -INT16_C( 26046),  INT16_C( 19849), -INT16_C( 10585),  INT16_C(  4941), -INT16_C( 26065),  INT16_C( 15011),
         INT16_C( 11582), -INT16_C( 15708),  INT16_C( 17906), -INT16_C(  4327),  INT16_C( 17905),  INT16_C( 14516),  INT16_C( 17154), -INT16_C( 31443),
         INT16_C( 22674), -INT16_C( 11070),  INT16_C( 19442), -INT16_C( 26078),  INT16_C( 28449),  INT16_C( 20653),  INT16_C( 20489),  INT16_C( 18570),
         INT16_C( 11901),  INT16_C( 28682),  INT16_C(  9332),  INT16_C( 25951),  INT16_C(  4969),  INT16_C( 27549), -INT16_C( 13738), -INT16_C(  5904) },
      UINT32_C( 364753442),
      {  INT16_C( 23630),  INT16_C( 22383), -INT16_C(  1620),  INT16_C( 10655), -INT16_C( 21976), -INT16_C( 25447), -INT16_C(  1586),  INT16_C( 14081),
        -INT16_C( 24820),  INT16_C( 25506), -INT16_C( 28055), -INT16_C( 29621),  INT16_C(  2117),  INT16_C( 17057),  INT16_C( 20711),  INT16_C( 13665),
        -INT16_C( 12116),  INT16_C( 22669),  INT16_C( 11465), -INT16_C(  3711),  INT16_C(  7126), -INT16_C( 23411), -INT16_C( 28908),  INT16_C(  8411),
         INT16_C( 32046), -INT16_C( 26749), -INT16_C( 12528),  INT16_C( 21795), -INT16_C( 15145), -INT16_C( 16489), -INT16_C(  2028), -INT16_C( 16140) },
      { -INT16_C( 32312), -INT16_C( 28136), -INT16_C( 25938), -INT16_C( 31613),  INT16_C(  4533), -INT16_C( 14039),  INT16_C(  1184), -INT16_C( 12567),
         INT16_C( 28034), -INT16_C( 28059), -INT16_C( 30404),  INT16_C(  5095),  INT16_C( 32333),  INT16_C( 25298), -INT16_C( 14473),  INT16_C( 16162),
         INT16_C( 15176), -INT16_C(  2351),  INT16_C( 21973), -INT16_C( 30085), -INT16_C( 23450),  INT16_C(  1619),  INT16_C( 15528),  INT16_C( 10964),
         INT16_C( 14761), -INT16_C(  6724), -INT16_C( 23614),  INT16_C(  4345), -INT16_C( 13534), -INT16_C( 26254), -INT16_C( 27502), -INT16_C(  9256) },
      {  INT16_C( 20355), -INT16_C(  5753), -INT16_C( 26046),  INT16_C( 19849), -INT16_C( 10585),  INT16_C( 26050), -INT16_C( 26065),  INT16_C( 15011),
         INT16_C( 11582), -INT16_C(  2553),  INT16_C( 17906), -INT16_C(  4327), -INT16_C( 31086), -INT16_C( 23181),  INT16_C( 17154),  INT16_C( 29827),
         INT16_C(  3060), -INT16_C( 11070), -INT16_C( 32098),  INT16_C( 31740), -INT16_C( 16324), -INT16_C( 21792),  INT16_C( 20489),  INT16_C( 19375),
        -INT16_C( 18729),  INT16_C( 28682),  INT16_C( 29394),  INT16_C( 25951), -INT16_C( 28679),  INT16_C( 27549), -INT16_C( 13738), -INT16_C(  5904) } },
    { { -INT16_C( 21809), -INT16_C( 23343),  INT16_C( 19711),  INT16_C( 25902), -INT16_C( 32272), -INT16_C( 26261),  INT16_C( 16318),  INT16_C( 26563),
        -INT16_C( 32648),  INT16_C( 15181),  INT16_C( 17955),  INT16_C( 17739), -INT16_C( 17135), -INT16_C( 23330), -INT16_C( 18607),  INT16_C(  8575),
         INT16_C( 20577),  INT16_C( 24773), -INT16_C(  2915), -INT16_C( 29243),  INT16_C( 12405),  INT16_C( 13094), -INT16_C(  5521), -INT16_C(  6245),
        -INT16_C(  6038), -INT16_C( 29406),  INT16_C( 27950),  INT16_C( 16339), -INT16_C( 20182),  INT16_C( 31971),  INT16_C( 25192), -INT16_C( 13923) },
      UINT32_C(1344889523),
      {  INT16_C(  1054), -INT16_C( 29185), -INT16_C( 25874),  INT16_C( 22645), -INT16_C( 26750), -INT16_C( 20251), -INT16_C( 18427),  INT16_C( 12272),
        -INT16_C( 11414), -INT16_C( 11605),  INT16_C( 18486), -INT16_C(  5732), -INT16_C( 14933),  INT16_C(   313),  INT16_C(  5812), -INT16_C( 11571),
        -INT16_C( 13030),  INT16_C(  2144), -INT16_C( 10905), -INT16_C(  5536),  INT16_C( 18028),  INT16_C( 29082), -INT16_C( 29954),  INT16_C( 26785),
         INT16_C( 19550), -INT16_C( 27589), -INT16_C( 10347),  INT16_C( 16509), -INT16_C( 18788),  INT16_C( 20545),  INT16_C(  4044), -INT16_C(  6365) },
      { -INT16_C( 31780),  INT16_C( 17391),  INT16_C( 20568), -INT16_C( 15315), -INT16_C( 14186), -INT16_C( 27594), -INT16_C( 10414), -INT16_C( 20227),
         INT16_C( 14371), -INT16_C( 18364), -INT16_C( 16113), -INT16_C( 21512),  INT16_C( 14967),  INT16_C( 17660),  INT16_C(  8009),  INT16_C(  9515),
         INT16_C(  6818), -INT16_C(  1432), -INT16_C( 27030),  INT16_C(   190), -INT16_C(  2978), -INT16_C( 20331), -INT16_C( 27957), -INT16_C(  4255),
        -INT16_C( 23094), -INT16_C(  9817), -INT16_C( 24473), -INT16_C(  8572), -INT16_C( 32550),  INT16_C(  8994),  INT16_C( 19871),  INT16_C( 16712) },
      { -INT16_C( 30726), -INT16_C( 11794),  INT16_C( 19711),  INT16_C( 25902),  INT16_C( 24600),  INT16_C( 17691),  INT16_C( 16318), -INT16_C(  7955),
        -INT16_C( 32648), -INT16_C( 29969),  INT16_C( 17955),  INT16_C( 17739), -INT16_C( 17135),  INT16_C( 17973),  INT16_C( 13821),  INT16_C(  8575),
        -INT16_C(  6212),  INT16_C( 24773), -INT16_C(  2915), -INT16_C(  5346),  INT16_C( 12405),  INT16_C(  8751), -INT16_C(  5521), -INT16_C(  6245),
        -INT16_C(  6038), -INT16_C( 29406),  INT16_C( 27950),  INT16_C( 16339),  INT16_C( 14198),  INT16_C( 31971),  INT16_C( 23915), -INT16_C( 13923) } },
    { { -INT16_C( 20376), -INT16_C( 11717), -INT16_C(  1466), -INT16_C( 23341),  INT16_C( 26862), -INT16_C( 17835), -INT16_C( 18694), -INT16_C( 15191),
         INT16_C( 20571), -INT16_C( 15715),  INT16_C(  8688), -INT16_C( 13663), -INT16_C( 15454),  INT16_C( 16877),  INT16_C( 13585),  INT16_C( 31107),
        -INT16_C( 16666),  INT16_C( 11339),  INT16_C(  7864), -INT16_C( 22575),  INT16_C(  9862), -INT16_C( 32671),  INT16_C(  2780),  INT16_C( 14148),
        -INT16_C(  7846),  INT16_C( 19450), -INT16_C( 25853), -INT16_C( 23275),  INT16_C(   862),  INT16_C( 28646),  INT16_C( 26936),  INT16_C(  7912) },
      UINT32_C(3763024936),
      { -INT16_C(  6078),  INT16_C(  7769), -INT16_C( 24846),  INT16_C( 19797),  INT16_C( 20351), -INT16_C( 32104), -INT16_C( 21014),  INT16_C( 18727),
         INT16_C(  3760), -INT16_C(  5704), -INT16_C( 24201), -INT16_C( 24825),  INT16_C( 21205),  INT16_C( 10112),  INT16_C(  1902), -INT16_C( 20480),
         INT16_C( 23280), -INT16_C(  7474),  INT16_C(  9464),  INT16_C( 30511), -INT16_C( 14477),  INT16_C( 24314),  INT16_C(  8565),  INT16_C(  9639),
         INT16_C( 24367), -INT16_C( 22770),  INT16_C(  5632), -INT16_C( 10938), -INT16_C( 14744), -INT16_C( 10243), -INT16_C(   562), -INT16_C( 16761) },
      {  INT16_C( 22103),  INT16_C( 20384), -INT16_C( 12166), -INT16_C(  4665), -INT16_C( 15977),  INT16_C(  3147), -INT16_C(  3358),  INT16_C(  4658),
         INT16_C( 16466),  INT16_C( 21177), -INT16_C(   170), -INT16_C( 16600),  INT16_C(  9670), -INT16_C( 27498),  INT16_C(  7458),  INT16_C( 31314),
        -INT16_C(  3469), -INT16_C(  4663), -INT16_C( 28478),  INT16_C( 23259),  INT16_C(  9809),  INT16_C( 13414), -INT16_C( 26599),  INT16_C( 27462),
        -INT16_C(    39),  INT16_C( 12221), -INT16_C(  6658), -INT16_C( 15122), -INT16_C( 31734),  INT16_C( 11608), -INT16_C( 21854),  INT16_C(  5543) },
      { -INT16_C( 20376), -INT16_C( 11717), -INT16_C(  1466),  INT16_C( 15132),  INT16_C( 26862), -INT16_C( 28957), -INT16_C( 18694), -INT16_C( 15191),
         INT16_C( 20571), -INT16_C( 15715), -INT16_C( 24371), -INT16_C( 13663),  INT16_C( 30875), -INT16_C( 17386),  INT16_C( 13585),  INT16_C( 31107),
         INT16_C( 19811), -INT16_C( 12137),  INT16_C(  7864), -INT16_C( 11766),  INT16_C(  9862), -INT16_C( 32671), -INT16_C( 18034),  INT16_C( 14148),
        -INT16_C(  7846),  INT16_C( 19450), -INT16_C( 25853), -INT16_C( 23275),  INT16_C(   862),  INT16_C(  1365), -INT16_C( 22416), -INT16_C( 11218) } },
    { {  INT16_C( 28829),  INT16_C( 24323), -INT16_C(  8703),  INT16_C( 21177),  INT16_C(  8196),  INT16_C(  7558), -INT16_C( 13128), -INT16_C( 28280),
         INT16_C( 18123), -INT16_C( 13631), -INT16_C( 20693),  INT16_C( 13966), -INT16_C(  6348), -INT16_C( 10653),  INT16_C(  2705),  INT16_C( 12011),
        -INT16_C(  4486),  INT16_C( 31630),  INT16_C( 18380), -INT16_C( 11826),  INT16_C( 21607),  INT16_C(  8430),  INT16_C( 30497), -INT16_C(  4943),
         INT16_C( 29373), -INT16_C(  5962),  INT16_C( 17698),  INT16_C( 22046), -INT16_C( 32468), -INT16_C( 17108),  INT16_C(  6027),  INT16_C(  1772) },
      UINT32_C(3531700742),
      { -INT16_C( 27996), -INT16_C( 15031), -INT16_C(  1527), -INT16_C( 14671),  INT16_C( 26733), -INT16_C( 28754), -INT16_C( 12883), -INT16_C(  9755),
         INT16_C(  4430), -INT16_C(  9578), -INT16_C( 32216),  INT16_C( 12000),  INT16_C( 25084), -INT16_C( 16895), -INT16_C( 23375),  INT16_C( 21991),
         INT16_C( 12342),  INT16_C( 16154), -INT16_C( 13526), -INT16_C( 26875), -INT16_C( 19405), -INT16_C(  8154),  INT16_C(  2945), -INT16_C( 12359),
         INT16_C( 20508),  INT16_C( 17833), -INT16_C( 30254), -INT16_C( 12429),  INT16_C( 29931), -INT16_C( 25459),  INT16_C( 29721),  INT16_C( 20465) },
      {  INT16_C(  2980), -INT16_C( 12657), -INT16_C( 27434),  INT16_C(  2662), -INT16_C( 29624), -INT16_C( 13846), -INT16_C( 23400), -INT16_C( 19303),
         INT16_C( 17140), -INT16_C( 14599),  INT16_C( 28108), -INT16_C( 18539),  INT16_C(  8929), -INT16_C(  1453),  INT16_C( 17558),  INT16_C( 14922),
        -INT16_C(  9905),  INT16_C(  9481),  INT16_C( 28525), -INT16_C( 18897),  INT16_C(  6907), -INT16_C( 27777),  INT16_C(  6334), -INT16_C( 19896),
         INT16_C( 16731),  INT16_C( 10104),  INT16_C(  3758), -INT16_C( 28450),  INT16_C( 12592), -INT16_C( 14454), -INT16_C( 11147), -INT16_C( 15359) },
      {  INT16_C( 28829), -INT16_C( 27688), -INT16_C( 28961),  INT16_C( 21177),  INT16_C(  8196),  INT16_C(  7558), -INT16_C( 13128), -INT16_C( 28280),
         INT16_C( 18123), -INT16_C( 24177), -INT16_C( 20693), -INT16_C(  6539), -INT16_C( 31523), -INT16_C( 18348), -INT16_C(  5817),  INT16_C( 12011),
         INT16_C(  2437),  INT16_C( 31630),  INT16_C( 18380), -INT16_C( 11826),  INT16_C( 21607),  INT16_C(  8430),  INT16_C( 30497), -INT16_C( 32255),
         INT16_C( 29373),  INT16_C( 27937),  INT16_C( 17698),  INT16_C( 22046), -INT16_C( 23013), -INT16_C( 17108),  INT16_C( 18574),  INT16_C(  5106) } },
    { {  INT16_C(  2733),  INT16_C(  7145),  INT16_C(  6521),  INT16_C( 30161),  INT16_C( 20531), -INT16_C(  3832),  INT16_C( 20585), -INT16_C( 15197),
         INT16_C(  7058),  INT16_C( 16619), -INT16_C( 14039),  INT16_C( 23248),  INT16_C( 23546),  INT16_C( 28449),  INT16_C(  8751), -INT16_C(  8909),
         INT16_C(  7213), -INT16_C( 22792), -INT16_C( 14027),  INT16_C( 26651),  INT16_C(  9241), -INT16_C( 32167), -INT16_C(   908),  INT16_C(  1606),
         INT16_C( 12568),  INT16_C( 16711),  INT16_C(  6138), -INT16_C(  2917), -INT16_C( 17294), -INT16_C( 23965), -INT16_C( 26913),  INT16_C(  3199) },
      UINT32_C(3904010163),
      { -INT16_C( 21774),  INT16_C( 26332),  INT16_C(  8871), -INT16_C( 16531), -INT16_C( 19372),  INT16_C( 19968), -INT16_C( 25397),  INT16_C( 15939),
        -INT16_C( 22952),  INT16_C( 14304),  INT16_C( 24381), -INT16_C(  4029), -INT16_C(  2346),  INT16_C(  5848),  INT16_C( 10692), -INT16_C( 18833),
         INT16_C( 19412),  INT16_C( 31516), -INT16_C( 30354), -INT16_C( 15814),  INT16_C( 14909),  INT16_C(  2320),  INT16_C( 21462),  INT16_C( 12103),
         INT16_C( 10234),  INT16_C( 14182), -INT16_C( 21882),  INT16_C( 23591), -INT16_C(    96),  INT16_C( 25714), -INT16_C(  7895), -INT16_C(   742) },
      {  INT16_C( 13869), -INT16_C( 25736), -INT16_C( 19776), -INT16_C(   675),  INT16_C( 28140), -INT16_C( 15610),  INT16_C( 19905), -INT16_C( 17422),
         INT16_C( 22644), -INT16_C(  1294),  INT16_C(  6402), -INT16_C( 23978), -INT16_C( 14312),  INT16_C( 16646),  INT16_C(  8362), -INT16_C( 10434),
        -INT16_C( 18857),  INT16_C(  6002), -INT16_C( 12440),  INT16_C( 21780),  INT16_C(  6972), -INT16_C(   744),  INT16_C(  2664), -INT16_C(  8776),
        -INT16_C( 21918),  INT16_C( 26071),  INT16_C( 11971), -INT16_C(  9209),  INT16_C(  3830), -INT16_C( 24547),  INT16_C( 23598), -INT16_C( 31369) },
      { -INT16_C(  7905),  INT16_C(   596),  INT16_C(  6521),  INT16_C( 30161),  INT16_C(  8768),  INT16_C(  4358),  INT16_C( 20585), -INT16_C(  1483),
        -INT16_C(   308),  INT16_C( 13010),  INT16_C( 30783),  INT16_C( 23248), -INT16_C( 16658),  INT16_C( 22494),  INT16_C( 19054), -INT16_C(  8909),
         INT16_C(  7213), -INT16_C( 28018), -INT16_C( 14027),  INT16_C( 26651),  INT16_C( 21881),  INT16_C(  1576), -INT16_C(   908),  INT16_C(  3327),
         INT16_C( 12568),  INT16_C( 16711),  INT16_C(  6138),  INT16_C( 14382), -INT16_C( 17294),  INT16_C(  1167),  INT16_C( 15703), -INT16_C( 32111) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i src = simde_mm512_loadu_epi16(test_vec[i].src);
    simde__m512i a = simde_mm512_loadu_epi16(test_vec[i].a);
    simde__m512i b = simde_mm512_loadu_epi16(test_vec[i].b);
    simde__m512i r = simde_mm512_mask_add_epi16(src, test_vec[i].k, a, b);
    simde_test_x86_assert_equal_i16x32(r, simde_mm512_loadu_epi16(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_mm512_maskz_add_epi16 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const simde__mmask32 k;
    const int16_t a[32];
    const int16_t b[32];
    const int16_t r[32];
  } test_vec[] = {
    { UINT32_C(1970569674),
      { -INT16_C(  4224), -INT16_C( 11503), -INT16_C( 18041),  INT16_C(  6436), -INT16_C(  9270), -INT16_C( 15814), -INT16_C( 27569),  INT16_C( 13042),
        -INT16_C( 23737), -INT16_C( 13044),  INT16_C(  7220), -INT16_C(   316),  INT16_C( 14494), -INT16_C(   908),  INT16_C( 27220), -INT16_C( 11118),
        -INT16_C( 23719), -INT16_C(  8025), -INT16_C( 13476),  INT16_C(  9977),  INT16_C( 13479), -INT16_C(  2328), -INT16_C(  9528),  INT16_C(  3881),
         INT16_C( 13693), -INT16_C( 19747), -INT16_C( 24239), -INT16_C(  4176),  INT16_C(  9433),  INT16_C( 11756),  INT16_C( 32398), -INT16_C(  6143) },
      { -INT16_C( 22239),  INT16_C( 32200), -INT16_C( 15756),  INT16_C(  7075), -INT16_C( 29450), -INT16_C( 16878),  INT16_C( 15206), -INT16_C(  6962),
        -INT16_C( 21648), -INT16_C( 15978),  INT16_C( 17996),  INT16_C(  9649), -INT16_C( 25237), -INT16_C(  1709),  INT16_C( 21531),  INT16_C( 15585),
        -INT16_C( 21763),  INT16_C( 29369),  INT16_C( 23660),  INT16_C( 25229), -INT16_C( 24600),  INT16_C( 20256), -INT16_C(  4390),  INT16_C( 18995),
        -INT16_C( 13927), -INT16_C(  6900), -INT16_C( 17137),  INT16_C( 31243),  INT16_C( 24154),  INT16_C( 30068),  INT16_C( 21938), -INT16_C( 20303) },
      {  INT16_C(     0),  INT16_C( 20697),  INT16_C(     0),  INT16_C( 13511),  INT16_C(     0),  INT16_C(     0), -INT16_C( 12363),  INT16_C(  6080),
         INT16_C( 20151),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(  4467),
         INT16_C(     0),  INT16_C(     0),  INT16_C( 10184),  INT16_C(     0), -INT16_C( 11121),  INT16_C( 17928), -INT16_C( 13918),  INT16_C(     0),
        -INT16_C(   234),  INT16_C(     0),  INT16_C( 24160),  INT16_C(     0), -INT16_C( 31949), -INT16_C( 23712), -INT16_C( 11200),  INT16_C(     0) } },
    { UINT32_C(1797417727),
      { -INT16_C(  4529),  INT16_C( 10750),  INT16_C( 12764),  INT16_C( 30324), -INT16_C( 32518),  INT16_C(  2395),  INT16_C( 26173), -INT16_C( 26748),
        -INT16_C(  1852),  INT16_C( 30476), -INT16_C( 17075),  INT16_C( 19751),  INT16_C( 18727), -INT16_C(  4680), -INT16_C( 30984),  INT16_C( 18332),
        -INT16_C( 25996),  INT16_C( 20593), -INT16_C(  6709), -INT16_C( 14906),  INT16_C(  8805), -INT16_C( 23857),  INT16_C( 21384),  INT16_C( 19769),
         INT16_C( 17739), -INT16_C( 26428), -INT16_C(  5374),  INT16_C( 10725), -INT16_C( 25036),  INT16_C( 11286), -INT16_C( 19676), -INT16_C( 26508) },
      { -INT16_C(  6835),  INT16_C(  6632), -INT16_C( 20534),  INT16_C( 12254), -INT16_C( 21039),  INT16_C( 22993),  INT16_C(  2560),  INT16_C( 19366),
         INT16_C( 27215),  INT16_C( 20964), -INT16_C( 13995), -INT16_C( 30342), -INT16_C( 28569), -INT16_C( 29770),  INT16_C( 10819), -INT16_C( 28381),
         INT16_C(  3087), -INT16_C(  9814), -INT16_C( 30533), -INT16_C( 29688), -INT16_C(  9930),  INT16_C( 14053), -INT16_C( 29469),  INT16_C( 12930),
         INT16_C( 26358),  INT16_C( 19587), -INT16_C(   721), -INT16_C( 26667), -INT16_C( 29811), -INT16_C( 11998),  INT16_C( 18101), -INT16_C( 15262) },
      { -INT16_C( 11364),  INT16_C( 17382), -INT16_C(  7770), -INT16_C( 22958),  INT16_C( 11979),  INT16_C( 25388),  INT16_C( 28733), -INT16_C(  7382),
         INT16_C(     0), -INT16_C( 14096),  INT16_C(     0), -INT16_C( 10591),  INT16_C(     0),  INT16_C( 31086), -INT16_C( 20165),  INT16_C(     0),
         INT16_C(     0),  INT16_C( 10779),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(  9804),  INT16_C(     0),  INT16_C(     0),
        -INT16_C( 21439), -INT16_C(  6841),  INT16_C(     0), -INT16_C( 15942),  INT16_C(     0), -INT16_C(   712), -INT16_C(  1575),  INT16_C(     0) } },
    { UINT32_C( 228396114),
      {  INT16_C( 32382),  INT16_C( 24833), -INT16_C( 31990),  INT16_C(   403),  INT16_C(  5865),  INT16_C(  6221),  INT16_C(  8723), -INT16_C( 24145),
        -INT16_C( 11602),  INT16_C( 25458), -INT16_C( 11240),  INT16_C( 27176), -INT16_C( 14880),  INT16_C( 29815),  INT16_C(  4203), -INT16_C(  5825),
         INT16_C( 16526), -INT16_C( 26293), -INT16_C(  8509), -INT16_C( 21350), -INT16_C(  6155),  INT16_C(  2244),  INT16_C( 29705), -INT16_C( 18519),
         INT16_C(  6982),  INT16_C( 24091),  INT16_C( 17391), -INT16_C( 12344),  INT16_C( 16136),  INT16_C( 29508), -INT16_C( 31921), -INT16_C(  8867) },
      { -INT16_C( 22333), -INT16_C( 31114),  INT16_C(  4230),  INT16_C( 31538), -INT16_C(  2313),  INT16_C(   388),  INT16_C( 11626), -INT16_C( 20296),
        -INT16_C( 11447),  INT16_C( 14350), -INT16_C( 10730),  INT16_C(  7944),  INT16_C( 19477),  INT16_C( 25746), -INT16_C(  4145), -INT16_C( 28094),
        -INT16_C( 18281),  INT16_C(  7704),  INT16_C( 19145), -INT16_C( 16231),  INT16_C(  7488), -INT16_C( 21567),  INT16_C( 31307), -INT16_C( 27557),
         INT16_C( 27213),  INT16_C( 25804), -INT16_C( 11200),  INT16_C( 22147),  INT16_C(  5408), -INT16_C(  4166), -INT16_C(  1019), -INT16_C( 25471) },
      {  INT16_C(     0), -INT16_C(  6281),  INT16_C(     0),  INT16_C(     0),  INT16_C(  3552),  INT16_C(     0),  INT16_C( 20349),  INT16_C(     0),
         INT16_C(     0),  INT16_C(     0), -INT16_C( 21970), -INT16_C( 30416),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
        -INT16_C(  1755),  INT16_C(     0),  INT16_C( 10636),  INT16_C( 27955),  INT16_C(  1333),  INT16_C(     0),  INT16_C(     0),  INT16_C( 19460),
        -INT16_C( 31341),  INT16_C(     0),  INT16_C(  6191),  INT16_C(  9803),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
    { UINT32_C(2126158261),
      {  INT16_C(   113), -INT16_C( 17201),  INT16_C( 10874), -INT16_C( 14512),  INT16_C(  7572), -INT16_C( 10965), -INT16_C( 20751),  INT16_C(  4651),
        -INT16_C(  6716), -INT16_C( 14079), -INT16_C( 31774), -INT16_C( 26779),  INT16_C(  8220),  INT16_C(    21),  INT16_C( 21364), -INT16_C(  6876),
        -INT16_C(  3245), -INT16_C( 12894), -INT16_C(  3555), -INT16_C( 19819), -INT16_C( 16369),  INT16_C(   391), -INT16_C( 19857),  INT16_C( 13075),
         INT16_C(  5271),  INT16_C( 31228),  INT16_C( 24983), -INT16_C( 19440),  INT16_C(  9601), -INT16_C(  2636), -INT16_C( 10119), -INT16_C( 13093) },
      {  INT16_C( 32203), -INT16_C(  5990),  INT16_C( 12143),  INT16_C( 32666),  INT16_C(  8687),  INT16_C( 24192), -INT16_C( 27693),  INT16_C( 27537),
        -INT16_C( 29273),  INT16_C( 16356), -INT16_C(  2577),  INT16_C( 28915), -INT16_C( 22758), -INT16_C( 27802),  INT16_C( 16767),  INT16_C( 19040),
        -INT16_C(  1346),  INT16_C( 11570), -INT16_C( 13015),  INT16_C(  6316),  INT16_C( 11502), -INT16_C( 15753),  INT16_C(  2239),  INT16_C( 26413),
         INT16_C(  4502), -INT16_C( 31322), -INT16_C( 26362),  INT16_C(  8693),  INT16_C( 23360), -INT16_C( 16460),  INT16_C(  5276),  INT16_C( 23049) },
      {  INT16_C( 32316),  INT16_C(     0),  INT16_C( 23017),  INT16_C(     0),  INT16_C( 16259),  INT16_C( 13227),  INT16_C(     0),  INT16_C( 32188),
         INT16_C( 29547),  INT16_C(     0),  INT16_C(     0),  INT16_C(  2136), -INT16_C( 14538),  INT16_C(     0),  INT16_C(     0),  INT16_C( 12164),
         INT16_C(     0), -INT16_C(  1324),  INT16_C(     0), -INT16_C( 13503), -INT16_C(  4867), -INT16_C( 15362),  INT16_C(     0), -INT16_C( 26048),
         INT16_C(     0), -INT16_C(    94), -INT16_C(  1379), -INT16_C( 10747), -INT16_C( 32575), -INT16_C( 19096), -INT16_C(  4843),  INT16_C(     0) } },
    { UINT32_C( 931674894),
      { -INT16_C( 14495),  INT16_C(  8377), -INT16_C(  6449),  INT16_C( 25991),  INT16_C( 11767), -INT16_C(   278), -INT16_C(  7994),  INT16_C(  1567),
        -INT16_C( 11461), -INT16_C( 10043), -INT16_C( 12568), -INT16_C(  2510), -INT16_C( 17910),  INT16_C(  4654),  INT16_C( 32495),  INT16_C( 20489),
        -INT16_C( 15803),  INT16_C(  5232), -INT16_C(  1880), -INT16_C( 24454),  INT16_C( 25637), -INT16_C(  4962), -INT16_C( 17084), -INT16_C( 32526),
        -INT16_C( 18288),  INT16_C( 30808), -INT16_C( 30074), -INT16_C( 28561), -INT16_C( 25275),  INT16_C( 13475), -INT16_C( 21477),  INT16_C( 24708) },
      { -INT16_C(  2961),  INT16_C(  6004), -INT16_C(  4372),  INT16_C(  4791),  INT16_C( 21843), -INT16_C( 26626), -INT16_C(  4078), -INT16_C( 23785),
         INT16_C( 28584),  INT16_C( 12059), -INT16_C( 29958),  INT16_C( 16319),  INT16_C( 25127),  INT16_C( 17011), -INT16_C(  2289),  INT16_C( 32418),
         INT16_C(  6123), -INT16_C( 10091),  INT16_C( 19717),  INT16_C( 22762), -INT16_C(  5982), -INT16_C( 18960),  INT16_C(  2008), -INT16_C( 32424),
         INT16_C( 29559),  INT16_C( 29104),  INT16_C( 28670),  INT16_C(  9648),  INT16_C(  9170), -INT16_C(  7832),  INT16_C(  2586),  INT16_C(  1375) },
      {  INT16_C(     0),  INT16_C( 14381), -INT16_C( 10821),  INT16_C( 30782),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
         INT16_C( 17123),  INT16_C(  2016),  INT16_C(     0),  INT16_C( 13809),  INT16_C(  7217),  INT16_C( 21665),  INT16_C(     0),  INT16_C(     0),
         INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(  1692),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(   586),
         INT16_C( 11271), -INT16_C(  5624), -INT16_C(  1404),  INT16_C(     0), -INT16_C( 16105),  INT16_C(  5643),  INT16_C(     0),  INT16_C(     0) } },
    { UINT32_C( 668857377),
      {  INT16_C( 28591), -INT16_C( 30567), -INT16_C(  3721), -INT16_C(  4599), -INT16_C( 18076),  INT16_C( 25183),  INT16_C(  3880), -INT16_C(  1400),
        -INT16_C(  4046),  INT16_C( 19675),  INT16_C( 15098),  INT16_C(  7249),  INT16_C( 12079),  INT16_C( 28739), -INT16_C( 15626), -INT16_C( 22956),
        -INT16_C(  4814), -INT16_C( 22226),  INT16_C( 14302),  INT16_C( 17303), -INT16_C(  2320),  INT16_C(  6309),  INT16_C( 11525),  INT16_C( 14099),
        -INT16_C(  4579),  INT16_C(  6275), -INT16_C( 11223),  INT16_C( 22580),  INT16_C( 30467), -INT16_C(  1336),  INT16_C(  7481),  INT16_C( 27552) },
      { -INT16_C( 12790), -INT16_C(  5868), -INT16_C( 21755), -INT16_C(  2772), -INT16_C( 11871), -INT16_C( 23027),  INT16_C(  8447),  INT16_C(  7389),
         INT16_C( 24591),  INT16_C( 14388),  INT16_C( 26677),  INT16_C( 14480),  INT16_C( 22751),  INT16_C(  6450), -INT16_C( 11659), -INT16_C( 32636),
        -INT16_C( 26208), -INT16_C( 23191), -INT16_C( 27324), -INT16_C(  6502), -INT16_C( 22426),  INT16_C( 25996),  INT16_C( 27336), -INT16_C( 10366),
        -INT16_C( 18742), -INT16_C(   241), -INT16_C( 24801), -INT16_C(   456),  INT16_C( 27384),  INT16_C( 27927), -INT16_C( 25539), -INT16_C(  8723) },
      {  INT16_C( 15801),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(  2156),  INT16_C(     0),  INT16_C(     0),
         INT16_C(     0),  INT16_C(     0), -INT16_C( 23761),  INT16_C(     0), -INT16_C( 30706), -INT16_C( 30347), -INT16_C( 27285),  INT16_C(  9944),
        -INT16_C( 31022),  INT16_C(     0), -INT16_C( 13022),  INT16_C( 10801), -INT16_C( 24746),  INT16_C(     0), -INT16_C( 26675),  INT16_C(  3733),
        -INT16_C( 23321),  INT16_C(  6034),  INT16_C( 29512),  INT16_C(     0),  INT16_C(     0),  INT16_C( 26591),  INT16_C(     0),  INT16_C(     0) } },
    { UINT32_C(2038650421),
      { -INT16_C(  4923), -INT16_C( 29001),  INT16_C( 14678),  INT16_C(  8293),  INT16_C( 30192),  INT16_C(  3872),  INT16_C( 22548),  INT16_C(  3085),
         INT16_C(  9666), -INT16_C(   134),  INT16_C( 26561), -INT16_C(  2339),  INT16_C( 24766), -INT16_C( 22161), -INT16_C( 12419),  INT16_C( 17403),
        -INT16_C( 19525),  INT16_C(  4561),  INT16_C( 14060), -INT16_C(  9167),  INT16_C( 20907), -INT16_C( 16149), -INT16_C(  1623),  INT16_C( 27852),
         INT16_C( 17950), -INT16_C(  8341),  INT16_C( 18606),  INT16_C( 27861),  INT16_C( 17576),  INT16_C(  9749),  INT16_C(  4371), -INT16_C( 12695) },
      {  INT16_C( 15044), -INT16_C( 20257),  INT16_C(  4464),  INT16_C(  7309),  INT16_C( 30818),  INT16_C(  3292), -INT16_C( 22415), -INT16_C( 28808),
        -INT16_C(  7185), -INT16_C( 25234),  INT16_C( 17196), -INT16_C( 11255),  INT16_C(  7816), -INT16_C( 25606),  INT16_C( 25391), -INT16_C(  3222),
         INT16_C( 18845),  INT16_C(  3748),  INT16_C( 12634), -INT16_C( 17110),  INT16_C(  1705),  INT16_C(  7113),  INT16_C( 16814), -INT16_C( 25174),
         INT16_C(  6436),  INT16_C( 20538),  INT16_C( 17244), -INT16_C(  7131),  INT16_C(  8034), -INT16_C( 28288), -INT16_C(  5501),  INT16_C(  8325) },
      {  INT16_C( 10121),  INT16_C(     0),  INT16_C( 19142),  INT16_C(     0), -INT16_C(  4526),  INT16_C(  7164),  INT16_C(     0),  INT16_C(     0),
         INT16_C(     0), -INT16_C( 25368), -INT16_C( 21779),  INT16_C(     0),  INT16_C( 32582),  INT16_C(     0),  INT16_C( 12972),  INT16_C(     0),
        -INT16_C(   680),  INT16_C(  8309),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(  2678),
         INT16_C( 24386),  INT16_C(     0),  INT16_C(     0),  INT16_C( 20730),  INT16_C( 25610), -INT16_C( 18539), -INT16_C(  1130),  INT16_C(     0) } },
    { UINT32_C(2385389875),
      {  INT16_C(  5214),  INT16_C(  3358), -INT16_C( 13995),  INT16_C( 31146), -INT16_C(  6686),  INT16_C( 16074), -INT16_C(  4312), -INT16_C( 30173),
        -INT16_C( 23794), -INT16_C( 28388), -INT16_C( 24179), -INT16_C( 16206), -INT16_C(  7990),  INT16_C(  9294), -INT16_C( 26311), -INT16_C( 26841),
         INT16_C( 18093),  INT16_C(   676),  INT16_C( 20239), -INT16_C(  3716),  INT16_C( 17972),  INT16_C( 23599),  INT16_C( 21045),  INT16_C( 17383),
         INT16_C(  1013), -INT16_C( 32043), -INT16_C( 30812),  INT16_C( 28227), -INT16_C( 28313), -INT16_C( 24430), -INT16_C( 18133), -INT16_C( 10184) },
      { -INT16_C(  8961),  INT16_C(  3803),  INT16_C( 22315),  INT16_C( 24575),  INT16_C( 12189), -INT16_C( 11588), -INT16_C( 23679),  INT16_C( 30485),
        -INT16_C(  5466),  INT16_C( 19193),  INT16_C( 15473), -INT16_C(  9800),  INT16_C( 19150), -INT16_C(  1671), -INT16_C( 20221),  INT16_C(   977),
        -INT16_C( 21362), -INT16_C( 18159),  INT16_C(  4355), -INT16_C( 24551), -INT16_C( 10944), -INT16_C( 16014), -INT16_C( 30600),  INT16_C(  7736),
         INT16_C( 12914), -INT16_C(  7064),  INT16_C(  8302),  INT16_C( 15549),  INT16_C( 13930),  INT16_C( 27957),  INT16_C(  2024),  INT16_C( 30320) },
      { -INT16_C(  3747),  INT16_C(  7161),  INT16_C(     0),  INT16_C(     0),  INT16_C(  5503),  INT16_C(  4486),  INT16_C(     0),  INT16_C(     0),
        -INT16_C( 29260),  INT16_C(     0),  INT16_C(     0), -INT16_C( 26006),  INT16_C(     0),  INT16_C(  7623),  INT16_C(     0),  INT16_C(     0),
         INT16_C(     0), -INT16_C( 17483),  INT16_C( 24594), -INT16_C( 28267),  INT16_C(     0),  INT16_C(  7585),  INT16_C(     0),  INT16_C(     0),
         INT16_C(     0),  INT16_C( 26429), -INT16_C( 22510), -INT16_C( 21760),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C( 20136) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i a = simde_mm512_loadu_epi16(test_vec[i].a);
    simde__m512i b = simde_mm512_loadu_epi16(test_vec[i].b);
    simde__m512i r = simde_mm512_maskz_add_epi16(test_vec[i].k, a, b);
    simde_test_x86_assert_equal_i16x32(r, simde_mm512_loadu_epi16(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_mm512_add_epi32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int32_t a[16];
    int32_t b[16];
    int32_t r[16];
  } test_vec[] = {
    { { -INT32_C(  2023322181), -INT32_C(   153083711),  INT32_C(  1496228679), -INT32_C(  1879098037),  INT32_C(   556222349), -INT32_C(  1406744359),  INT32_C(   328840924),  INT32_C(   558351974),
         INT32_C(   363441491),  INT32_C(   353077710),  INT32_C(  2003712300),  INT32_C(    50752886), -INT32_C(  1926943052), -INT32_C(   767996938),  INT32_C(  1759891970), -INT32_C(   326488680) },
      { -INT32_C(  1476316198), -INT32_C(   390198084), -INT32_C(  1151325115),  INT32_C(  1321166490), -INT32_C(  1965235052),  INT32_C(   828118319), -INT32_C(  2137373976),  INT32_C(  1231823983),
         INT32_C(   334654807), -INT32_C(  1090801543),  INT32_C(  1987730396),  INT32_C(  1455765954),  INT32_C(  1289855261), -INT32_C(  1635893834), -INT32_C(   299952001), -INT32_C(  1825010884) },
      {  INT32_C(   795328917), -INT32_C(   543281795),  INT32_C(   344903564), -INT32_C(   557931547), -INT32_C(  1409012703), -INT32_C(   578626040), -INT32_C(  1808533052),  INT32_C(  1790175957),
         INT32_C(   698096298), -INT32_C(   737723833), -INT32_C(   303524600),  INT32_C(  1506518840), -INT32_C(   637087791),  INT32_C(  1891076524),  INT32_C(  1459939969),  INT32_C(  2143467732) } },
    { {  INT32_C(  1923492601), -INT32_C(  1238261286), -INT32_C(  1087525891),  INT32_C(    18215652),  INT32_C(  1229846163), -INT32_C(  1276589260),  INT32_C(   530712547), -INT32_C(  1951212910),
        -INT32_C(   553756668), -INT32_C(   141283334), -INT32_C(  1095319078),  INT32_C(  1186974643), -INT32_C(   158331710), -INT32_C(  1146521384),  INT32_C(   299584383),  INT32_C(   698191141) },
      { -INT32_C(   536372250), -INT32_C(  1529373494),  INT32_C(   291671389),  INT32_C(   441917784),  INT32_C(    84993837), -INT32_C(   557729185),  INT32_C(   737188869),  INT32_C(   257199401),
        -INT32_C(   219194328),  INT32_C(  1435944696), -INT32_C(  1402537901),  INT32_C(  1187429913),  INT32_C(    88922021), -INT32_C(  1763504751), -INT32_C(   759049303), -INT32_C(  1998449056) },
      {  INT32_C(  1387120351),  INT32_C(  1527332516), -INT32_C(   795854502),  INT32_C(   460133436),  INT32_C(  1314840000), -INT32_C(  1834318445),  INT32_C(  1267901416), -INT32_C(  1694013509),
        -INT32_C(   772950996),  INT32_C(  1294661362),  INT32_C(  1797110317), -INT32_C(  1920562740), -INT32_C(    69409689),  INT32_C(  1384941161), -INT32_C(   459464920), -INT32_C(  1300257915) } },
    { {  INT32_C(  1786433906), -INT32_C(   339799912),  INT32_C(   563553800), -INT32_C(  1989648668), -INT32_C(   963726283),  INT32_C(  1784443585), -INT32_C(  1506009531), -INT32_C(  1506927052),
        -INT32_C(  2012173840), -INT32_C(  1032597575), -INT32_C(   639431691), -INT32_C(  1637659799), -INT32_C(  1067126273), -INT32_C(  1456816029),  INT32_C(   307193822),  INT32_C(  1975025029) },
      { -INT32_C(   520239066), -INT32_C(  1918733928), -INT32_C(   446200452), -INT32_C(   796669231),  INT32_C(   529655739), -INT32_C(  2033665113), -INT32_C(  1466427614), -INT32_C(  1155706476),
        -INT32_C(  1315235047),  INT32_C(   138362252), -INT32_C(  1813141822),  INT32_C(   728002672), -INT32_C(    28641961), -INT32_C(   746319184), -INT32_C(  1099227863), -INT32_C(  2022074258) },
      {  INT32_C(  1266194840),  INT32_C(  2036433456),  INT32_C(   117353348),  INT32_C(  1508649397), -INT32_C(   434070544), -INT32_C(   249221528),  INT32_C(  1322530151),  INT32_C(  1632333768),
         INT32_C(   967558409), -INT32_C(   894235323),  INT32_C(  1842393783), -INT32_C(   909657127), -INT32_C(  1095768234),  INT32_C(  2091832083), -INT32_C(   792034041), -INT32_C(    47049229) } },
    { {  INT32_C(  1060705459),  INT32_C(   323450961), -INT32_C(  1901644770), -INT32_C(    71758940), -INT32_C(  1325792256),  INT32_C(  1082359318),  INT32_C(   167706267),  INT32_C(  1251047319),
        -INT32_C(   594883957),  INT32_C(  1626329410), -INT32_C(  1427204602), -INT32_C(  1582913631), -INT32_C(  1034772309), -INT32_C(  1174219490),  INT32_C(  1807941844),  INT32_C(    45438071) },
      {  INT32_C(  1625177886),  INT32_C(   398511377),  INT32_C(    96579172),  INT32_C(    27748182),  INT32_C(   650377479), -INT32_C(  1562327602),  INT32_C(  1007526853),  INT32_C(   373212152),
         INT32_C(   326573058),  INT32_C(  1311389674),  INT32_C(  1012133094),  INT32_C(  1530788435), -INT32_C(  1031732749), -INT32_C(  1939578426), -INT32_C(    53972476),  INT32_C(   923993909) },
      { -INT32_C(  1609083951),  INT32_C(   721962338), -INT32_C(  1805065598), -INT32_C(    44010758), -INT32_C(   675414777), -INT32_C(   479968284),  INT32_C(  1175233120),  INT32_C(  1624259471),
        -INT32_C(   268310899), -INT32_C(  1357248212), -INT32_C(   415071508), -INT32_C(    52125196), -INT32_C(  2066505058),  INT32_C(  1181169380),  INT32_C(  1753969368),  INT32_C(   969431980) } },
    { {  INT32_C(   223054371), -INT32_C(  1487178303), -INT32_C(  1243369631), -INT32_C(  1659887191), -INT32_C(   396390110), -INT32_C(   160119822),  INT32_C(  1794325813),  INT32_C(  1738671684),
         INT32_C(  1366683024), -INT32_C(   990261150),  INT32_C(   695852159),  INT32_C(   533105149),  INT32_C(   201860378),  INT32_C(   503479528), -INT32_C(    41355847), -INT32_C(  1956304133) },
      {  INT32_C(  2061359639),  INT32_C(   708761258), -INT32_C(  1336690766),  INT32_C(  1523521856),  INT32_C(   644273982),  INT32_C(   222586964),  INT32_C(  1493945694),  INT32_C(   266694903),
        -INT32_C(   192298422),  INT32_C(  1243531160), -INT32_C(  1090883202), -INT32_C(   937899382), -INT32_C(   168853855),  INT32_C(  1141060582), -INT32_C(   123859456), -INT32_C(   939031682) },
      { -INT32_C(  2010553286), -INT32_C(   778417045),  INT32_C(  1714906899), -INT32_C(   136365335),  INT32_C(   247883872),  INT32_C(    62467142), -INT32_C(  1006695789),  INT32_C(  2005366587),
         INT32_C(  1174384602),  INT32_C(   253270010), -INT32_C(   395031043), -INT32_C(   404794233),  INT32_C(    33006523),  INT32_C(  1644540110), -INT32_C(   165215303),  INT32_C(  1399631481) } },
    { { -INT32_C(   574844859), -INT32_C(   718808233), -INT32_C(   678223284), -INT32_C(  1918915604),  INT32_C(   260279849), -INT32_C(  1034647870),  INT32_C(   314241684), -INT32_C(  1160068747),
        -INT32_C(  1466460591), -INT32_C(  1099055503), -INT32_C(   862646048), -INT32_C(   463850309), -INT32_C(  2047550013), -INT32_C(   146323357), -INT32_C(  1358364102),  INT32_C(   359261123) },
      { -INT32_C(   339935111), -INT32_C(  1616299074),  INT32_C(   124468811),  INT32_C(   904643954),  INT32_C(    96133026),  INT32_C(  1643905575), -INT32_C(   955251452),  INT32_C(  1658616296),
         INT32_C(   944609913),  INT32_C(   551024341), -INT32_C(  1507376588), -INT32_C(  1428417784),  INT32_C(   447780594), -INT32_C(  1669616488), -INT32_C(  1704686414),  INT32_C(  2147237893) },
      { -INT32_C(   914779970),  INT32_C(  1959859989), -INT32_C(   553754473), -INT32_C(  1014271650),  INT32_C(   356412875),  INT32_C(   609257705), -INT32_C(   641009768),  INT32_C(   498547549),
        -INT32_C(   521850678), -INT32_C(   548031162),  INT32_C(  1924944660), -INT32_C(  1892268093), -INT32_C(  1599769419), -INT32_C(  1815939845),  INT32_C(  1231916780), -INT32_C(  1788468280) } },
    { { -INT32_C(  1346942502),  INT32_C(  1943047743), -INT32_C(   669321264), -INT32_C(    41683446),  INT32_C(   622277516), -INT32_C(  1849584929),  INT32_C(   606872862),  INT32_C(  1084434534),
        -INT32_C(  1309648270), -INT32_C(  1205485336), -INT32_C(  1030668361), -INT32_C(  1044442059),  INT32_C(   652662343), -INT32_C(  2017941400),  INT32_C(   866903245),  INT32_C(  2121551372) },
      { -INT32_C(  1875876696), -INT32_C(   616016604), -INT32_C(   912402028),  INT32_C(   881482989), -INT32_C(  1688506062), -INT32_C(   433974503),  INT32_C(    52088311), -INT32_C(  1014854117),
         INT32_C(   374584050), -INT32_C(  1678664953),  INT32_C(  1650757493),  INT32_C(   513273579),  INT32_C(  2025452127), -INT32_C(    60826875), -INT32_C(  1006667352), -INT32_C(   108625657) },
      {  INT32_C(  1072148098),  INT32_C(  1327031139), -INT32_C(  1581723292),  INT32_C(   839799543), -INT32_C(  1066228546),  INT32_C(  2011407864),  INT32_C(   658961173),  INT32_C(    69580417),
        -INT32_C(   935064220),  INT32_C(  1410817007),  INT32_C(   620089132), -INT32_C(   531168480), -INT32_C(  1616852826), -INT32_C(  2078768275), -INT32_C(   139764107),  INT32_C(  2012925715) } },
    { {  INT32_C(   974117171), -INT32_C(   371916684),  INT32_C(  2068593039), -INT32_C(  2019957976), -INT32_C(   637513003), -INT32_C(   707371219), -INT32_C(   543631912), -INT32_C(  1965547945),
         INT32_C(  1808132087),  INT32_C(  2002098919), -INT32_C(    51207724),  INT32_C(  1501793156),  INT32_C(   171148253), -INT32_C(  1159788062),  INT32_C(   899250142), -INT32_C(  1933545067) },
      {  INT32_C(  1089963352), -INT32_C(   206091233),  INT32_C(  1911532013),  INT32_C(   298480436), -INT32_C(   652476938), -INT32_C(   443287034),  INT32_C(   102378865), -INT32_C(   141370722),
         INT32_C(  2134346079), -INT32_C(  1015877930), -INT32_C(   885693801), -INT32_C(   874709035),  INT32_C(    61143037),  INT32_C(  1659386097),  INT32_C(    57148261),  INT32_C(  1039858397) },
      {  INT32_C(  2064080523), -INT32_C(   578007917), -INT32_C(   314842244), -INT32_C(  1721477540), -INT32_C(  1289989941), -INT32_C(  1150658253), -INT32_C(   441253047), -INT32_C(  2106918667),
        -INT32_C(   352489130),  INT32_C(   986220989), -INT32_C(   936901525),  INT32_C(   627084121),  INT32_C(   232291290),  INT32_C(   499598035),  INT32_C(   956398403), -INT32_C(   893686670) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i a = simde_mm512_loadu_epi32(test_vec[i].a);
    simde__m512i b = simde_mm512_loadu_epi32(test_vec[i].b);
    simde__m512i r = simde_mm512_add_epi32(a, b);
    simde_test_x86_assert_equal_i32x16(r, simde_mm512_loadu_epi32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_mm512_mask_add_epi32 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const int32_t src[16];
    const simde__mmask16 k;
    const int32_t a[16];
    const int32_t b[16];
    const int32_t r[16];
  } test_vec[] = {
    { { -INT32_C(  1958532398), -INT32_C(   733777631), -INT32_C(    61793464),  INT32_C(  1915617450),  INT32_C(   759754662),  INT32_C(   196190852), -INT32_C(    77082310), -INT32_C(   259049954),
        -INT32_C(  2105748895), -INT32_C(  1940471997), -INT32_C(  2071418662),  INT32_C(  1324791464),  INT32_C(   695943077),  INT32_C(   456404449),  INT32_C(   471309310),  INT32_C(   856467154) },
      UINT16_C(34936),
      {  INT32_C(  1554501556),  INT32_C(   715824517), -INT32_C(  1118624036),  INT32_C(  1373210451), -INT32_C(   177344477),  INT32_C(   237533590),  INT32_C(  1254743298), -INT32_C(  1653861911),
         INT32_C(  1727599584), -INT32_C(  1919900495),  INT32_C(   491513034), -INT32_C(  1905384341), -INT32_C(  1434199276),  INT32_C(  1454943060),  INT32_C(  1923121545),  INT32_C(  1930431890) },
      { -INT32_C(   774305504),  INT32_C(  2002741677), -INT32_C(  1181439411), -INT32_C(   498662706),  INT32_C(   848088029), -INT32_C(     7846794),  INT32_C(  1483876805),  INT32_C(  1456177718),
         INT32_C(   958964875),  INT32_C(  1538295565), -INT32_C(    15448783),  INT32_C(   635525959), -INT32_C(  1655214810),  INT32_C(  1989992369),  INT32_C(  1053691400),  INT32_C(   479566224) },
      { -INT32_C(  1958532398), -INT32_C(   733777631), -INT32_C(    61793464),  INT32_C(   874547745),  INT32_C(   670743552),  INT32_C(   229686796), -INT32_C(  1556347193), -INT32_C(   259049954),
        -INT32_C(  2105748895), -INT32_C(  1940471997), -INT32_C(  2071418662), -INT32_C(  1269858382),  INT32_C(   695943077),  INT32_C(   456404449),  INT32_C(   471309310), -INT32_C(  1884969182) } },
    { {  INT32_C(  1263910205),  INT32_C(  1973814596), -INT32_C(  1837843894),  INT32_C(  1018647829),  INT32_C(  1943604930), -INT32_C(   152472083),  INT32_C(   338999428), -INT32_C(  1892628143),
        -INT32_C(   891648634), -INT32_C(   717258613),  INT32_C(  1332196154), -INT32_C(   896852472),  INT32_C(   440230956),  INT32_C(  1578117082),  INT32_C(   812795103), -INT32_C(  1799380210) },
      UINT16_C(39208),
      {  INT32_C(  1520693330),  INT32_C(   992292367),  INT32_C(  1834312339),  INT32_C(  1758160265), -INT32_C(  1197916758),  INT32_C(   155998432),  INT32_C(   196914162), -INT32_C(  1671477942),
         INT32_C(  1173750326), -INT32_C(  1015014608),  INT32_C(   120641150), -INT32_C(   445580485),  INT32_C(   429721913),  INT32_C(  1394797153), -INT32_C(   547364971),  INT32_C(  1518059044) },
      { -INT32_C(   257985856),  INT32_C(   196354189),  INT32_C(   823387382),  INT32_C(   420971488), -INT32_C(   315444084),  INT32_C(   876696990),  INT32_C(  1477681204),  INT32_C(   515084126),
        -INT32_C(  1911664127),  INT32_C(  1754972786), -INT32_C(  2019906137), -INT32_C(  1130319568),  INT32_C(    78238309),  INT32_C(  1530456615), -INT32_C(   390837366), -INT32_C(   620337190) },
      {  INT32_C(  1263910205),  INT32_C(  1973814596), -INT32_C(  1837843894), -INT32_C(  2115835543),  INT32_C(  1943604930),  INT32_C(  1032695422),  INT32_C(   338999428), -INT32_C(  1892628143),
        -INT32_C(   737913801), -INT32_C(   717258613),  INT32_C(  1332196154), -INT32_C(  1575900053),  INT32_C(   507960222),  INT32_C(  1578117082),  INT32_C(   812795103),  INT32_C(   897721854) } },
    { {  INT32_C(   745149881),  INT32_C(  2123629783), -INT32_C(   519754063),  INT32_C(  1167959519), -INT32_C(  1622587784), -INT32_C(  1141145295), -INT32_C(  1482379316), -INT32_C(   813520362),
        -INT32_C(  1745097537), -INT32_C(  1592422160), -INT32_C(  1635640386),  INT32_C(   954408896), -INT32_C(  1747440538),  INT32_C(  2035471277), -INT32_C(  1742670206),  INT32_C(  1617404833) },
      UINT16_C(25487),
      { -INT32_C(   397433816),  INT32_C(   690041539),  INT32_C(   197196126),  INT32_C(  1317344204), -INT32_C(  1427725047), -INT32_C(   670347960), -INT32_C(  1554513232),  INT32_C(   928348431),
        -INT32_C(   517954531),  INT32_C(   889864663),  INT32_C(   104975162), -INT32_C(   413874466), -INT32_C(  1265485205),  INT32_C(   948739463), -INT32_C(  1344543585),  INT32_C(  2078683229) },
      { -INT32_C(  1403255083), -INT32_C(  2115934649),  INT32_C(   260514353),  INT32_C(  1425529832), -INT32_C(  1660385003), -INT32_C(   975858650), -INT32_C(   713772936), -INT32_C(  1236247583),
        -INT32_C(  1453151135),  INT32_C(  1143620371),  INT32_C(  1314173542), -INT32_C(  1549644915), -INT32_C(    96425260), -INT32_C(  1228991170), -INT32_C(  1500760891), -INT32_C(   262349681) },
      { -INT32_C(  1800688899), -INT32_C(  1425893110),  INT32_C(   457710479), -INT32_C(  1552093260), -INT32_C(  1622587784), -INT32_C(  1141145295), -INT32_C(  1482379316), -INT32_C(   307899152),
        -INT32_C(  1971105666),  INT32_C(  2033485034), -INT32_C(  1635640386),  INT32_C(   954408896), -INT32_C(  1747440538), -INT32_C(   280251707),  INT32_C(  1449662820),  INT32_C(  1617404833) } },
    { { -INT32_C(  1667645815),  INT32_C(  1759560706),  INT32_C(    62272630),  INT32_C(  1403410815),  INT32_C(  1112401411), -INT32_C(  1040708101), -INT32_C(   798522303), -INT32_C(   356465567),
        -INT32_C(  2071569790), -INT32_C(  1796446690),  INT32_C(   446145435), -INT32_C(     9552132),  INT32_C(   541178660),  INT32_C(   165755592),  INT32_C(   534333630), -INT32_C(  1895196148) },
      UINT16_C(36852),
      { -INT32_C(  1616167517), -INT32_C(  1600251525), -INT32_C(  1648303915), -INT32_C(   660102886), -INT32_C(   151486231),  INT32_C(   243597594), -INT32_C(  2027906927),  INT32_C(   991479448),
         INT32_C(  2145043204), -INT32_C(  1306560035),  INT32_C(  1934614361),  INT32_C(  1783363200), -INT32_C(  1855962249), -INT32_C(   694098619),  INT32_C(   375242877), -INT32_C(  1957595769) },
      {  INT32_C(   352988216), -INT32_C(    20501851), -INT32_C(  1972300023), -INT32_C(  2064335859),  INT32_C(  1159091200), -INT32_C(  1239697863), -INT32_C(    36931466),  INT32_C(   629677805),
        -INT32_C(   281308342), -INT32_C(   957545795),  INT32_C(   659578393),  INT32_C(   447431706), -INT32_C(   782253672), -INT32_C(   293045641), -INT32_C(   538225422), -INT32_C(  1140493198) },
      { -INT32_C(  1667645815),  INT32_C(  1759560706),  INT32_C(   674363358),  INT32_C(  1403410815),  INT32_C(  1007604969), -INT32_C(   996100269), -INT32_C(  2064838393),  INT32_C(  1621157253),
         INT32_C(  1863734862),  INT32_C(  2030861466), -INT32_C(  1700774542), -INT32_C(  2064172390),  INT32_C(   541178660),  INT32_C(   165755592),  INT32_C(   534333630),  INT32_C(  1196878329) } },
    { { -INT32_C(   995409913),  INT32_C(  1552586818),  INT32_C(   293854198), -INT32_C(  1205129697),  INT32_C(  1737067504), -INT32_C(   128642811), -INT32_C(   656981658), -INT32_C(  1131029323),
         INT32_C(  1602240540), -INT32_C(   809825575),  INT32_C(    98582245),  INT32_C(  1555893356), -INT32_C(  1664858473), -INT32_C(  1097590440),  INT32_C(   261516378),  INT32_C(  1707813704) },
      UINT16_C(19308),
      {  INT32_C(   692123069), -INT32_C(  1735983871), -INT32_C(  1674294716), -INT32_C(  1101346461),  INT32_C(  2110648373), -INT32_C(  1998415588),  INT32_C(   986556132), -INT32_C(   495525595),
        -INT32_C(   687032618), -INT32_C(   126905676),  INT32_C(  1066706140), -INT32_C(  1560416659), -INT32_C(    98579490),  INT32_C(  1216479844), -INT32_C(   830255192),  INT32_C(   129038641) },
      {  INT32_C(  1675607215),  INT32_C(   710626894),  INT32_C(  1600843762), -INT32_C(  1140758563), -INT32_C(  1766448846), -INT32_C(   874563293), -INT32_C(  1181130104),  INT32_C(   180439643),
         INT32_C(  1433313286), -INT32_C(   511718930), -INT32_C(  1774130759), -INT32_C(  2091761071), -INT32_C(  2045114013), -INT32_C(   900597438), -INT32_C(  1232802981),  INT32_C(  1002456373) },
      { -INT32_C(   995409913),  INT32_C(  1552586818), -INT32_C(    73450954),  INT32_C(  2052862272),  INT32_C(  1737067504),  INT32_C(  1421988415), -INT32_C(   194573972), -INT32_C(  1131029323),
         INT32_C(   746280668), -INT32_C(   638624606),  INT32_C(    98582245),  INT32_C(   642789566), -INT32_C(  1664858473), -INT32_C(  1097590440), -INT32_C(  2063058173),  INT32_C(  1707813704) } },
    { { -INT32_C(   745525531), -INT32_C(  1313599240),  INT32_C(  1246230009), -INT32_C(  1697736137), -INT32_C(   450828125),  INT32_C(  1018130913), -INT32_C(  1846398116),  INT32_C(  1573761656),
        -INT32_C(   651076127),  INT32_C(  1737155949),  INT32_C(   296866266),  INT32_C(   246120299),  INT32_C(  1223936871), -INT32_C(  1719360707),  INT32_C(  1328248534),  INT32_C(   179107881) },
      UINT16_C(56661),
      { -INT32_C(  1431315650), -INT32_C(  1028105637),  INT32_C(  1661709350),  INT32_C(   637308751),  INT32_C(   796141318),  INT32_C(  1966678303), -INT32_C(  1053287170), -INT32_C(   950050167),
        -INT32_C(  1737421251), -INT32_C(  1906627992),  INT32_C(   636577494), -INT32_C(    78975243),  INT32_C(   891993877), -INT32_C(   559258656),  INT32_C(   144761471), -INT32_C(  2117009596) },
      {  INT32_C(  1964654861),  INT32_C(  1090811243), -INT32_C(   798558757), -INT32_C(   104025629),  INT32_C(  1345255024), -INT32_C(   651241382), -INT32_C(    18690374), -INT32_C(   629165363),
         INT32_C(  1599117811), -INT32_C(   375368690),  INT32_C(   767166281),  INT32_C(   673613496), -INT32_C(   696757124), -INT32_C(   424630740),  INT32_C(  1122275957),  INT32_C(   924672836) },
      {  INT32_C(   533339211), -INT32_C(  1313599240),  INT32_C(   863150593), -INT32_C(  1697736137),  INT32_C(  2141396342),  INT32_C(  1018130913), -INT32_C(  1071977544),  INT32_C(  1573761656),
        -INT32_C(   138303440),  INT32_C(  1737155949),  INT32_C(  1403743775),  INT32_C(   594638253),  INT32_C(   195236753), -INT32_C(  1719360707),  INT32_C(  1267037428), -INT32_C(  1192336760) } },
    { {  INT32_C(   194407933),  INT32_C(   183842753), -INT32_C(   164122818), -INT32_C(  1323410123), -INT32_C(   578251087), -INT32_C(  1312606148),  INT32_C(   250914762),  INT32_C(   138744075),
         INT32_C(  1058266238),  INT32_C(  1363740691), -INT32_C(   330858057), -INT32_C(  1868667426),  INT32_C(   929900283),  INT32_C(   686371166), -INT32_C(   482943528),  INT32_C(  1827372014) },
      UINT16_C(65367),
      {  INT32_C(  1420493429),  INT32_C(  1659128167), -INT32_C(   845524625),  INT32_C(  1542816642),  INT32_C(  1312697184), -INT32_C(    21353817),  INT32_C(   812213545), -INT32_C(   806411175),
        -INT32_C(  1910269145),  INT32_C(  1425082340), -INT32_C(   618558632),  INT32_C(  1849038606), -INT32_C(   373525438), -INT32_C(   941066594),  INT32_C(   888689115), -INT32_C(  1677465739) },
      {  INT32_C(  1730881154), -INT32_C(  2034557907), -INT32_C(  1251877721),  INT32_C(   908302323), -INT32_C(  1440751861),  INT32_C(   812713813), -INT32_C(   832280232), -INT32_C(   748001199),
        -INT32_C(  1137011314),  INT32_C(  1480783281), -INT32_C(   988961838),  INT32_C(  1174089786),  INT32_C(  1693391631),  INT32_C(  2073321762),  INT32_C(   457832906), -INT32_C(   269503647) },
      { -INT32_C(  1143592713), -INT32_C(   375429740), -INT32_C(  2097402346), -INT32_C(  1323410123), -INT32_C(   128054677), -INT32_C(  1312606148), -INT32_C(    20066687),  INT32_C(   138744075),
         INT32_C(  1247686837), -INT32_C(  1389101675), -INT32_C(  1607520470), -INT32_C(  1271838904),  INT32_C(  1319866193),  INT32_C(  1132255168),  INT32_C(  1346522021), -INT32_C(  1946969386) } },
    { { -INT32_C(    89446071), -INT32_C(   246158049), -INT32_C(   894017392), -INT32_C(  1609518447), -INT32_C(   284819507),  INT32_C(   728406368), -INT32_C(   213470318), -INT32_C(  1327286937),
         INT32_C(  2125106783),  INT32_C(   208665980), -INT32_C(   271112866), -INT32_C(  1534072873),  INT32_C(  1200919782), -INT32_C(  1066205650),  INT32_C(   431274162),  INT32_C(  1305057262) },
      UINT16_C(29477),
      {  INT32_C(   935232863),  INT32_C(  1390103916),  INT32_C(   278491106),  INT32_C(   550505326), -INT32_C(  1304853308),  INT32_C(  1107231259), -INT32_C(   421344651),  INT32_C(  1672843268),
        -INT32_C(  2120584427), -INT32_C(  1546357055),  INT32_C(  1404268005),  INT32_C(  1030980473),  INT32_C(   602909704),  INT32_C(   610594478), -INT32_C(  1140176968), -INT32_C(   316686121) },
      { -INT32_C(   194069965),  INT32_C(   362234416),  INT32_C(   694766256), -INT32_C(   697901874),  INT32_C(   939087241), -INT32_C(    77898173),  INT32_C(  2092394149),  INT32_C(  1500108326),
        -INT32_C(  1068574576), -INT32_C(   891886310), -INT32_C(    17613008), -INT32_C(  1529587429), -INT32_C(   237187666), -INT32_C(   789825749), -INT32_C(  1018322019),  INT32_C(   169719418) },
      {  INT32_C(   741162898), -INT32_C(   246158049),  INT32_C(   973257362), -INT32_C(  1609518447), -INT32_C(   284819507),  INT32_C(  1029333086), -INT32_C(   213470318), -INT32_C(  1327286937),
         INT32_C(  1105808293),  INT32_C(  1856723931), -INT32_C(   271112866), -INT32_C(  1534072873),  INT32_C(   365722038), -INT32_C(   179231271),  INT32_C(  2136468309),  INT32_C(  1305057262) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i src = simde_mm512_loadu_epi32(test_vec[i].src);
    simde__m512i a = simde_mm512_loadu_epi32(test_vec[i].a);
    simde__m512i b = simde_mm512_loadu_epi32(test_vec[i].b);
    simde__m512i r = simde_mm512_mask_add_epi32(src, test_vec[i].k, a, b);
    simde_test_x86_assert_equal_i32x16(r, simde_mm512_loadu_epi32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_mm512_maskz_add_epi32 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const simde__mmask16 k;
    const int32_t a[16];
    const int32_t b[16];
    const int32_t r[16];
  } test_vec[] = {
    { UINT16_C(52979),
      {  INT32_C(  1318030952), -INT32_C(   938502652), -INT32_C(  1205717630),  INT32_C(  1648076236),  INT32_C(  1874746093),  INT32_C(   507402795), -INT32_C(   271937240), -INT32_C(   581761675),
        -INT32_C(  1758731373), -INT32_C(    77579399),  INT32_C(  1018397296),  INT32_C(   345959975),  INT32_C(  1954766153), -INT32_C(   527253065), -INT32_C(   925934509), -INT32_C(   190504095) },
      {  INT32_C(  2139869190),  INT32_C(  2071653131), -INT32_C(  1799934611),  INT32_C(  1688819227),  INT32_C(  1792552115),  INT32_C(  1095396078),  INT32_C(   654908102),  INT32_C(  1125887549),
        -INT32_C(  1966954626),  INT32_C(      343186), -INT32_C(  2070626967), -INT32_C(   957793005),  INT32_C(  1479590250), -INT32_C(   224822484), -INT32_C(   770006379), -INT32_C(   837470896) },
      { -INT32_C(   837067154),  INT32_C(  1133150479),  INT32_C(           0),  INT32_C(           0), -INT32_C(   627669088),  INT32_C(  1602798873),  INT32_C(   382970862),  INT32_C(   544125874),
         INT32_C(           0), -INT32_C(    77236213), -INT32_C(  1052229671), -INT32_C(   611833030),  INT32_C(           0),  INT32_C(           0), -INT32_C(  1695940888), -INT32_C(  1027974991) } },
    { UINT16_C(55260),
      {  INT32_C(   771752731), -INT32_C(  1410012863), -INT32_C(   687659861),  INT32_C(   885628063), -INT32_C(  1912151234), -INT32_C(   178513127),  INT32_C(    90486258),  INT32_C(   780260115),
         INT32_C(   408715991),  INT32_C(   381898859),  INT32_C(   351127156), -INT32_C(  1605847198), -INT32_C(  1288810598),  INT32_C(  1571392106),  INT32_C(  1382157631), -INT32_C(  1199512351) },
      { -INT32_C(   774841242), -INT32_C(  1578593492), -INT32_C(  1145711271),  INT32_C(   660340108), -INT32_C(  1210414772),  INT32_C(  1393853203),  INT32_C(  1923446417), -INT32_C(  1070979494),
         INT32_C(   798161410), -INT32_C(   422544755), -INT32_C(   593394353), -INT32_C(   821822334), -INT32_C(  1735991931), -INT32_C(   219440543),  INT32_C(  1801752848), -INT32_C(  1188327753) },
      {  INT32_C(           0),  INT32_C(           0), -INT32_C(  1833371132),  INT32_C(  1545968171),  INT32_C(  1172401290),  INT32_C(           0),  INT32_C(  2013932675), -INT32_C(   290719379),
         INT32_C(  1206877401), -INT32_C(    40645896), -INT32_C(   242267197),  INT32_C(           0),  INT32_C(  1270164767),  INT32_C(           0), -INT32_C(  1111056817),  INT32_C(  1907127192) } },
    { UINT16_C(48520),
      { -INT32_C(  1067213763),  INT32_C(   495937176), -INT32_C(  1531636413), -INT32_C(  1080647249), -INT32_C(   383059406),  INT32_C(   279074440),  INT32_C(  1260751635), -INT32_C(  2116935613),
         INT32_C(  1413559740), -INT32_C(   562966373), -INT32_C(  1803343899), -INT32_C(    95217208), -INT32_C(  1662812652), -INT32_C(   408058412),  INT32_C(  1412616720), -INT32_C(  1344994061) },
      { -INT32_C(   737929671), -INT32_C(   877431322),  INT32_C(  1683961500),  INT32_C(  1667150415),  INT32_C(    67125552), -INT32_C(   672354873),  INT32_C(  1915428479),  INT32_C(  1545732131),
        -INT32_C(    63887850),  INT32_C(   952624283),  INT32_C(  1771841050),  INT32_C(   164494297),  INT32_C(    51301692), -INT32_C(   103024006),  INT32_C(   996935192),  INT32_C(   496537095) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(   586503166),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(   571203482),
         INT32_C(  1349671890),  INT32_C(           0), -INT32_C(    31502849),  INT32_C(    69277089), -INT32_C(  1611510960), -INT32_C(   511082418),  INT32_C(           0), -INT32_C(   848456966) } },
    { UINT16_C(51636),
      { -INT32_C(   516938744),  INT32_C(  1542126879),  INT32_C(  1147140298),  INT32_C(   188627698),  INT32_C(  1195813440), -INT32_C(   328868296),  INT32_C(  1413185447),  INT32_C(  1746649952),
         INT32_C(   105467111),  INT32_C(   341914697),  INT32_C(   525910060),  INT32_C(   992646906),  INT32_C(  2021814336), -INT32_C(   161159345), -INT32_C(   951345050),  INT32_C(  1244620387) },
      { -INT32_C(    61834830), -INT32_C(   653217363),  INT32_C(  1828218994),  INT32_C(  1067918079), -INT32_C(   491246957),  INT32_C(  2027428881),  INT32_C(   524231612),  INT32_C(  1013542538),
        -INT32_C(  1808221721), -INT32_C(   579975061), -INT32_C(  1337366863),  INT32_C(   485486985),  INT32_C(   754886427), -INT32_C(  2136680764), -INT32_C(  2069830662),  INT32_C(   968886610) },
      {  INT32_C(           0),  INT32_C(           0), -INT32_C(  1319608004),  INT32_C(           0),  INT32_C(   704566483),  INT32_C(  1698560585),  INT32_C(           0), -INT32_C(  1534774806),
        -INT32_C(  1702754610),  INT32_C(           0),  INT32_C(           0),  INT32_C(  1478133891),  INT32_C(           0),  INT32_C(           0),  INT32_C(  1273791584), -INT32_C(  2081460299) } },
    { UINT16_C(63939),
      {  INT32_C(   732058786),  INT32_C(  1615303237), -INT32_C(    41073351),  INT32_C(   377368860),  INT32_C(  1738153493), -INT32_C(   358589913), -INT32_C(  1793561005),  INT32_C(  1300702122),
        -INT32_C(  1116198280), -INT32_C(   182533956),  INT32_C(   569617157), -INT32_C(   248024612), -INT32_C(  1235693169),  INT32_C(  2141321516),  INT32_C(   303348071),  INT32_C(  1432329437) },
      { -INT32_C(  2112694330), -INT32_C(  1653133161), -INT32_C(  1195480357),  INT32_C(  1789523675), -INT32_C(   215940409),  INT32_C(  1651753723),  INT32_C(  1484031867), -INT32_C(   374484189),
         INT32_C(  1114357931), -INT32_C(   857742352),  INT32_C(   696557133),  INT32_C(  1536372116),  INT32_C(   709866543), -INT32_C(   225590666),  INT32_C(  1833566537), -INT32_C(  2141783851) },
      { -INT32_C(  1380635544), -INT32_C(    37829924),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(   309529138),  INT32_C(   926217933),
        -INT32_C(     1840349),  INT32_C(           0),  INT32_C(           0),  INT32_C(  1288347504), -INT32_C(   525826626),  INT32_C(  1915730850),  INT32_C(  2136914608), -INT32_C(   709454414) } },
    { UINT16_C(49848),
      { -INT32_C(   736364480),  INT32_C(  1429188390), -INT32_C(   629113245), -INT32_C(  1966338752), -INT32_C(   470346226), -INT32_C(   966570738), -INT32_C(  1267784177),  INT32_C(   145220552),
         INT32_C(    48022236), -INT32_C(   715715727), -INT32_C(   894445686), -INT32_C(   212567068), -INT32_C(  1596568687), -INT32_C(  1469695335),  INT32_C(   677238112), -INT32_C(  1792015175) },
      {  INT32_C(   949423302), -INT32_C(  1592922601), -INT32_C(  1435714362), -INT32_C(   929185737), -INT32_C(  1519881204),  INT32_C(   239980462),  INT32_C(  1563863716),  INT32_C(  1978820270),
        -INT32_C(  1985115790),  INT32_C(  1043053176), -INT32_C(  1377265802),  INT32_C(  1668646487), -INT32_C(  1475813638),  INT32_C(  1370904237), -INT32_C(  1347425280), -INT32_C(  1004232366) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(  1399442807), -INT32_C(  1990227430), -INT32_C(   726590276),  INT32_C(           0),  INT32_C(  2124040822),
         INT32_C(           0),  INT32_C(   327337449),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(   670187168),  INT32_C(  1498719755) } },
    { UINT16_C(53547),
      {  INT32_C(  1739507983),  INT32_C(  1237984079), -INT32_C(  1359883519),  INT32_C(   687908649), -INT32_C(   438784109),  INT32_C(  2074737744),  INT32_C(  1478424525),  INT32_C(  2136604527),
         INT32_C(   417728457),  INT32_C(   744665131), -INT32_C(  1394912381), -INT32_C(  1898521605), -INT32_C(   629887350),  INT32_C(  2018909611), -INT32_C(  2066648044),  INT32_C(  1023617652) },
      {  INT32_C(  1565911346),  INT32_C(   495564697),  INT32_C(   113861643), -INT32_C(   913006785), -INT32_C(   106690482),  INT32_C(   980548134), -INT32_C(   490847634), -INT32_C(  1625308819),
         INT32_C(  1157395882),  INT32_C(   929137964),  INT32_C(   691874538),  INT32_C(   418632394),  INT32_C(     1152986), -INT32_C(    12877167),  INT32_C(   853735877),  INT32_C(  1708196283) },
      { -INT32_C(   989547967),  INT32_C(  1733548776),  INT32_C(           0), -INT32_C(   225098136),  INT32_C(           0), -INT32_C(  1239681418),  INT32_C(           0),  INT32_C(           0),
         INT32_C(  1575124339),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(   628734364),  INT32_C(           0), -INT32_C(  1212912167), -INT32_C(  1563153361) } },
    { UINT16_C(52598),
      { -INT32_C(    10086347), -INT32_C(  1005102614), -INT32_C(  2117785360),  INT32_C(  1870659754), -INT32_C(  1264491783), -INT32_C(   635800988), -INT32_C(  1837251777),  INT32_C(    63854798),
         INT32_C(  1510093936),  INT32_C(  2099124621), -INT32_C(   335617215), -INT32_C(   581206045),  INT32_C(  1167195361), -INT32_C(  1373590673),  INT32_C(  1027644783),  INT32_C(  1698697205) },
      { -INT32_C(   775994813), -INT32_C(  1672552869), -INT32_C(  1517859391), -INT32_C(  1383931188),  INT32_C(  1324553183),  INT32_C(   788272063), -INT32_C(  1502921296), -INT32_C(  1895060660),
         INT32_C(  1214303213),  INT32_C(  1793372073), -INT32_C(   938513412),  INT32_C(   762679630),  INT32_C(  1685809317),  INT32_C(   747796347),  INT32_C(    13827508), -INT32_C(  1785668184) },
      {  INT32_C(           0),  INT32_C(  1617311813),  INT32_C(   659322545),  INT32_C(           0),  INT32_C(    60061400),  INT32_C(   152471075),  INT32_C(   954794223),  INT32_C(           0),
        -INT32_C(  1570570147),  INT32_C(           0), -INT32_C(  1274130627),  INT32_C(   181473585),  INT32_C(           0),  INT32_C(           0),  INT32_C(  1041472291), -INT32_C(    86970979) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i a = simde_mm512_loadu_epi32(test_vec[i].a);
    simde__m512i b = simde_mm512_loadu_epi32(test_vec[i].b);
    simde__m512i r = simde_mm512_maskz_add_epi32(test_vec[i].k, a, b);
    simde_test_x86_assert_equal_i32x16(r, simde_mm512_loadu_epi32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_mm512_add_epi64 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const int64_t a[8];
    const int64_t b[8];
    const int64_t r[8];
  } test_vec[] = {
    { {  INT64_C( 5896694048212443049),  INT64_C( 9000266092577364175),  INT64_C( 7152103947590144860),  INT64_C( 2989496802120002433),
         INT64_C( 7710631622698424498), -INT64_C( 3633641352504339518),  INT64_C( 4274662313843579209),  INT64_C( 6826149357438294289) },
      { -INT64_C(  164363539517042510), -INT64_C( 8691483022440823005),  INT64_C( 9220214710722807807), -INT64_C( 2401321110146592095),
        -INT64_C( 1183069234730910884),  INT64_C( 5562197665816815723),  INT64_C( 1124204932795639468), -INT64_C( 3326459772972193332) },
      {  INT64_C( 5732330508695400539),  INT64_C(  308783070136541170), -INT64_C( 2074425415396598949),  INT64_C(  588175691973410338),
         INT64_C( 6527562387967513614),  INT64_C( 1928556313312476205),  INT64_C( 5398867246639218677),  INT64_C( 3499689584466100957) } },
    { {  INT64_C( 5873253456280027845), -INT64_C( 7547985786885765724),  INT64_C(  958785414761629392),  INT64_C( 8879370812030102515),
         INT64_C( 4762149369024389598),  INT64_C(  798391932315570322),  INT64_C(  147097132267652539), -INT64_C( 3786220049007964093) },
      { -INT64_C( 6906651495143342010), -INT64_C( 8287694440800363594),  INT64_C( 2452371479376447222),  INT64_C( 6726846324779217826),
         INT64_C( 5025569198072523023),  INT64_C(  225235015271111619), -INT64_C( 2487938372584494983),  INT64_C( 3745242421369017476) },
      { -INT64_C( 1033398038863314165),  INT64_C( 2611063846023422298),  INT64_C( 3411156894138076614), -INT64_C( 2840526936900231275),
        -INT64_C( 8659025506612638995),  INT64_C( 1023626947586681941), -INT64_C( 2340841240316842444), -INT64_C(   40977627638946617) } },
    { {  INT64_C( 7387045378804169392),  INT64_C( 7348215347083393770), -INT64_C( 7432287296260602942), -INT64_C( 4746462990122596405),
         INT64_C( 7669772552352133735),  INT64_C( 5083821277037292091),  INT64_C( 5407731889132030559), -INT64_C( 3084302269135830938) },
      { -INT64_C( 1461330460425637939), -INT64_C( 3061426891990558023),  INT64_C( 5599758734307477482),  INT64_C( 1862788523933954198),
        -INT64_C( 4557890179386853341),  INT64_C( 6666876053459161657), -INT64_C( 4937214972124475832),  INT64_C( 6111833508638834029) },
      {  INT64_C( 5925714918378531453),  INT64_C( 4286788455092835747), -INT64_C( 1832528561953125460), -INT64_C( 2883674466188642207),
         INT64_C( 3111882372965280394), -INT64_C( 6696046743213097868),  INT64_C(  470516917007554727),  INT64_C( 3027531239503003091) } },
    { { -INT64_C( 7991663547628636080), -INT64_C( 2555292973839346502),  INT64_C( 4212139769629200532),  INT64_C( 1966319092590916547),
         INT64_C( 1506042142180667901), -INT64_C( 9075093079022557283),  INT64_C( 7143746535270586651), -INT64_C( 2897889499141433630) },
      {  INT64_C( 6953298079720946194), -INT64_C( 6437157297342791622),  INT64_C( 8555627167819425208), -INT64_C( 4217080419303877945),
        -INT64_C(  916288211658955227),  INT64_C( 3576356706803505520), -INT64_C( 6218269451284303702), -INT64_C( 1742958193093650601) },
      { -INT64_C( 1038365467907689886), -INT64_C( 8992450271182138124), -INT64_C( 5678977136260925876), -INT64_C( 2250761326712961398),
         INT64_C(  589753930521712674), -INT64_C( 5498736372219051763),  INT64_C(  925477083986282949), -INT64_C( 4640847692235084231) } },
    { {  INT64_C( 2312342974665588586), -INT64_C( 6729576343545367823), -INT64_C( 4578026214523853331), -INT64_C( 1074221180203122067),
        -INT64_C( 1195656230424156519),  INT64_C( 3385005156404397150), -INT64_C( 2575086539621213671),  INT64_C( 4660983342689947190) },
      {  INT64_C( 5690001192450114569),  INT64_C( 6765706558176579445), -INT64_C( 8375529455621185160), -INT64_C(  280638300551000014),
         INT64_C(  791220201005032380), -INT64_C( 5337991249511014582),  INT64_C( 2478776332018633862),  INT64_C( 7142732816633802545) },
      {  INT64_C( 8002344167115703155),  INT64_C(   36130214631211622),  INT64_C( 5493188403564513125), -INT64_C( 1354859480754122081),
        -INT64_C(  404436029419124139), -INT64_C( 1952986093106617432), -INT64_C(   96310207602579809), -INT64_C( 6643027914385801881) } },
    { {  INT64_C( 7590546826509362360),  INT64_C( 4799960603843565481), -INT64_C( 3764863488869189202), -INT64_C( 8485326154395304909),
         INT64_C(  125025846558150196),  INT64_C( 4919203572335817541),  INT64_C( 1811753159855661758),  INT64_C( 6393760326532469855) },
      {  INT64_C(  421764692607537793),  INT64_C(  501672283606598428), -INT64_C( 2545232539499374162),  INT64_C( 6202803407104615064),
         INT64_C( 4980991260009414746),  INT64_C( 2385761506151573452), -INT64_C( 7628987825040033081),  INT64_C( 5850290225876708869) },
      {  INT64_C( 8012311519116900153),  INT64_C( 5301632887450163909), -INT64_C( 6310096028368563364), -INT64_C( 2282522747290689845),
         INT64_C( 5106017106567564942),  INT64_C( 7304965078487390993), -INT64_C( 5817234665184371323), -INT64_C( 6202693521300372892) } },
    { {  INT64_C( 3861145535682141991),  INT64_C( 4704120286579625139),  INT64_C( 7310649930581147103),  INT64_C( 6132617560052451027),
        -INT64_C( 4220933801323952434), -INT64_C(  467755223424977465), -INT64_C( 9153765608270723279),  INT64_C( 8400169494660134417) },
      {  INT64_C( 4306311459952605676),  INT64_C( 1432426031515283149),  INT64_C( 1311843823099622919), -INT64_C( 3392084749394608174),
         INT64_C( 8992722739203577885),  INT64_C( 5779599678188505408),  INT64_C( 5119810430763850234),  INT64_C( 6804001435340987831) },
      {  INT64_C( 8167456995634747667),  INT64_C( 6136546318094908288),  INT64_C( 8622493753680770022),  INT64_C( 2740532810657842853),
         INT64_C( 4771788937879625451),  INT64_C( 5311844454763527943), -INT64_C( 4033955177506873045), -INT64_C( 3242573143708429368) } },
    { {  INT64_C(  896142439321910083),  INT64_C( 1197503498379252485), -INT64_C( 7856220743107108291), -INT64_C( 6406762567310591882),
        -INT64_C( 4058014011976186410),  INT64_C( 9080299469053222364), -INT64_C( 7078487466013880490),  INT64_C( 7199966683762914017) },
      {  INT64_C( 7780449457883481456),  INT64_C( 1824347912971095698), -INT64_C( 8415522727832944271),  INT64_C( 7418198203865008897),
         INT64_C( 4556395623730444353),  INT64_C( 7889010207409543840), -INT64_C( 3090529460147599642), -INT64_C( 1719435354305139514) },
      {  INT64_C( 8676591897205391539),  INT64_C( 3021851411350348183),  INT64_C( 2175000602769499054),  INT64_C( 1011435636554417015),
         INT64_C(  498381611754257943), -INT64_C( 1477434397246785412),  INT64_C( 8277727147548071484),  INT64_C( 5480531329457774503) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i a = simde_mm512_loadu_epi64(test_vec[i].a);
    simde__m512i b = simde_mm512_loadu_epi64(test_vec[i].b);
    simde__m512i r = simde_mm512_add_epi64(a, b);
    simde_test_x86_assert_equal_i64x8(r, simde_mm512_loadu_epi64(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_mm512_mask_add_epi64 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const int64_t src[16];
    const simde__mmask8 k;
    const int64_t a[16];
    const int64_t b[16];
    const int64_t r[16];
  } test_vec[] = {
    { {  INT64_C( 1637095571448452370), -INT64_C( 5010656489973054228),  INT64_C( 8096577095910365922),  INT64_C( 3926524403043278656),
         INT64_C( 1692383872749537703), -INT64_C( 7546382928320257262), -INT64_C( 6602394267959061769),  INT64_C( 2598636899144412341) },
      UINT8_C( 63),
      {  INT64_C( 3064278465490095078), -INT64_C( 1676615221711466009), -INT64_C( 5333405411065419087), -INT64_C( 3810230114928306775),
        -INT64_C( 1075017760364328478),  INT64_C( 2095704811519734998), -INT64_C(  299103093840977638),  INT64_C( 5108483185182444596) },
      { -INT64_C( 4648200900296301693), -INT64_C( 4629136759825157063), -INT64_C( 5066623773317061022),  INT64_C(  536973459407932105),
         INT64_C( 2486008889004565721), -INT64_C( 3554876755438703545),  INT64_C( 1436140625484484016),  INT64_C( 5713013447801749692) },
      { -INT64_C( 1583922434806206615), -INT64_C( 6305751981536623072),  INT64_C( 8046714889327071507), -INT64_C( 3273256655520374670),
         INT64_C( 1410991128640237243), -INT64_C( 1459171943918968547), -INT64_C( 6602394267959061769),  INT64_C( 2598636899144412341) } },
    { {  INT64_C( 3991194155833482583),  INT64_C( 7365863369617845245), -INT64_C( 6217348007288128678),  INT64_C(  148675600489051978),
        -INT64_C( 5748943111581392624), -INT64_C( 9084794923389396527),  INT64_C( 6675703621262608398), -INT64_C( 3278006165881122860) },
      UINT8_C( 79),
      {  INT64_C( 7078729567351001797),  INT64_C( 3976127268296180429),  INT64_C( 6764870419675162927), -INT64_C( 6394845513855835965),
        -INT64_C( 4382478565492243517), -INT64_C( 1011318967947184367), -INT64_C( 6311831277423214532),  INT64_C( 4236157129718335039) },
      {  INT64_C( 4311691048566315805),  INT64_C(  693258357862808300), -INT64_C( 5061911316372677582),  INT64_C( 5814609134873172224),
        -INT64_C( 2890120277031405697),  INT64_C(  273070111211249652),  INT64_C( 6337650268323962303), -INT64_C(  956874791454847436) },
      { -INT64_C( 7056323457792234014),  INT64_C( 4669385626158988729),  INT64_C( 1702959103302485345), -INT64_C(  580236378982663741),
        -INT64_C( 5748943111581392624), -INT64_C( 9084794923389396527),  INT64_C(   25818990900747771), -INT64_C( 3278006165881122860) } },
    { {  INT64_C( 5402490335443754038),  INT64_C( 7004459312563912287),  INT64_C( 6873494867043635124), -INT64_C( 1746693303777676963),
         INT64_C( 4412405986682822043), -INT64_C( 3277034903515019135),  INT64_C(  971442364987875570),  INT64_C( 6704628126445290098) },
      UINT8_C(252),
      { -INT64_C( 3199500174101950700),  INT64_C( 7068896874256776325), -INT64_C(  840732006067128670), -INT64_C( 7451465598208935429),
         INT64_C(  990872770473652578),  INT64_C( 1777037797882114565), -INT64_C( 3158904769779877244),  INT64_C( 6189642379913322441) },
      { -INT64_C( 2014230672746244489),  INT64_C( 1316129223197016245),  INT64_C( 6358081634684124815),  INT64_C( 2925524125942721361),
        -INT64_C( 7645647755206468574),  INT64_C( 8364597264550793588),  INT64_C( 2245635740289228099),  INT64_C( 9124008468664275140) },
      {  INT64_C( 5402490335443754038),  INT64_C( 7004459312563912287),  INT64_C( 5517349628616996145), -INT64_C( 4525941472266214068),
        -INT64_C( 6654774984732815996), -INT64_C( 8305109011276643463), -INT64_C(  913269029490649145), -INT64_C( 3133093225131954035) } },
    { {  INT64_C( 7876626396527707865),  INT64_C( 6327703798935457910), -INT64_C( 8444156093278868254),  INT64_C(  792525990600389412),
         INT64_C( 6542343655737491300), -INT64_C( 6733297332257473758),  INT64_C( 3495113324412254258), -INT64_C( 8894133035806391978) },
      UINT8_C( 48),
      { -INT64_C( 1618640895730195884),  INT64_C(  566130083197796387), -INT64_C( 3091365637900741985), -INT64_C( 8802714067975954187),
         INT64_C( 8931894081495034460), -INT64_C( 8463108217014804938), -INT64_C( 2811541516088205358), -INT64_C( 4054272745087766267) },
      {  INT64_C( 6129898402509662270),  INT64_C(  565315231888848484), -INT64_C( 8016080185148496634), -INT64_C( 3365171251436437734),
         INT64_C( 5232753838442094123), -INT64_C( 1806946338783921745),  INT64_C( 6678716485601335700),  INT64_C( 2537267084449117649) },
      {  INT64_C( 7876626396527707865),  INT64_C( 6327703798935457910), -INT64_C( 8444156093278868254),  INT64_C(  792525990600389412),
        -INT64_C( 4282096153772423033),  INT64_C( 8176689517910824933),  INT64_C( 3495113324412254258), -INT64_C( 8894133035806391978) } },
    { { -INT64_C( 4217327386109371060),  INT64_C( 1462146507223994500),  INT64_C( 9029403535350110895), -INT64_C( 6164557771088777128),
         INT64_C( 7967243682726010805), -INT64_C( 9152970505335981211),  INT64_C( 7521223655988276535),  INT64_C( 1078941248321503985) },
      UINT8_C( 10),
      { -INT64_C( 6444823229810484523), -INT64_C( 7166643799492954826),  INT64_C( 1160825679683284586),  INT64_C( 4107978185158323148),
        -INT64_C( 8042316938503522478),  INT64_C( 4355947116441623144),  INT64_C(  124837676903243996), -INT64_C( 1113239454258551314) },
      {  INT64_C( 5394206117329760241),  INT64_C(  790827237554372843), -INT64_C( 3320718750563147595), -INT64_C( 3521057494574767212),
        -INT64_C( 3689301451095683169),  INT64_C( 4102642388072787639), -INT64_C( 6298270799792855837),  INT64_C(  908597294068841711) },
      { -INT64_C( 4217327386109371060), -INT64_C( 6375816561938581983),  INT64_C( 9029403535350110895),  INT64_C(  586920690583555936),
         INT64_C( 7967243682726010805), -INT64_C( 9152970505335981211),  INT64_C( 7521223655988276535),  INT64_C( 1078941248321503985) } },
    { {  INT64_C( 7311693701301843659),  INT64_C( 7494898546895421768),  INT64_C( 2349409172957636062),  INT64_C( 4322479761028576388),
         INT64_C( 3265778120923777598), -INT64_C( 5310310381393437343), -INT64_C( 4003064257566966751),  INT64_C( 2693634056535957430) },
      UINT8_C( 63),
      {  INT64_C(   74681461099467337), -INT64_C( 5086377914583683253), -INT64_C( 8273458662043960522), -INT64_C(   39800438883330947),
         INT64_C( 3679636505814865579), -INT64_C( 5866531736128853600), -INT64_C( 3073049960134569313),  INT64_C( 1395686423709339305) },
      {  INT64_C( 6281452445510075920),  INT64_C( 3045217899379926812),  INT64_C( 7460303757460924507),  INT64_C( 1845390670211485473),
         INT64_C( 1096976101920587563), -INT64_C( 7954793774127551260),  INT64_C(  392601397348307534), -INT64_C( 8539621634010629797) },
      {  INT64_C( 6356133906609543257), -INT64_C( 2041160015203756441), -INT64_C(  813154904583036015),  INT64_C( 1805590231328154526),
         INT64_C( 4776612607735453142),  INT64_C( 4625418563453146756), -INT64_C( 4003064257566966751),  INT64_C( 2693634056535957430) } },
    { { -INT64_C( 5625659159720783894), -INT64_C( 4262733505137438704),  INT64_C( 4771074415986154316), -INT64_C( 2710563408861215365),
        -INT64_C( 9137340262048543309),  INT64_C( 6372485775011303733), -INT64_C(  224123893461729351),  INT64_C( 7083941961317845637) },
      UINT8_C(  4),
      {  INT64_C( 7269643312887620103),  INT64_C( 4329870181778099646),  INT64_C( 2564722579906344530),  INT64_C( 7190335853134220430),
        -INT64_C(  968852038973637098),  INT64_C( 1853343154121473663), -INT64_C( 4838903194234096357), -INT64_C(  824357888695620912) },
      {  INT64_C( 1274425862000582536),  INT64_C( 9189953907530268329),  INT64_C( 5306942928662607291), -INT64_C(  321439533223302985),
        -INT64_C(  340471119033620572), -INT64_C( 3077940849910492058),  INT64_C( 4642198055108443306), -INT64_C( 8432040435859988082) },
      { -INT64_C( 5625659159720783894), -INT64_C( 4262733505137438704),  INT64_C( 7871665508568951821), -INT64_C( 2710563408861215365),
        -INT64_C( 9137340262048543309),  INT64_C( 6372485775011303733), -INT64_C(  224123893461729351),  INT64_C( 7083941961317845637) } },
    { { -INT64_C( 9127382355256823033),  INT64_C( 6974267907656827098),  INT64_C( 9068262761557100815),  INT64_C( 1459580854064754385),
        -INT64_C( 2177275983803055828), -INT64_C( 5361079444635839613), -INT64_C( 2408539542357402585), -INT64_C( 5262782123028966956) },
      UINT8_C(216),
      { -INT64_C( 2761901989156618652), -INT64_C( 7396259151174703979),  INT64_C( 1620878075755917699), -INT64_C( 4915584061870677991),
        -INT64_C(  219395007845324972),  INT64_C( 3208968296463365233), -INT64_C( 3812486535545803012),  INT64_C( 7117239981973485491) },
      { -INT64_C( 6444525492333861076),  INT64_C( 5168757207706484966), -INT64_C( 7509645842022035381),  INT64_C( 3857445270331687960),
         INT64_C( 6839094782695310862), -INT64_C( 1825179838618698216),  INT64_C( 7833075129166066744), -INT64_C( 3860117335376243408) },
      { -INT64_C( 9127382355256823033),  INT64_C( 6974267907656827098),  INT64_C( 9068262761557100815), -INT64_C( 1058138791538990031),
         INT64_C( 6619699774849985890), -INT64_C( 5361079444635839613),  INT64_C( 4020588593620263732),  INT64_C( 3257122646597242083) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i src = simde_mm512_loadu_epi64(test_vec[i].src);
    simde__m512i a = simde_mm512_loadu_epi64(test_vec[i].a);
    simde__m512i b = simde_mm512_loadu_epi64(test_vec[i].b);
    simde__m512i r = simde_mm512_mask_add_epi64(src, test_vec[i].k, a, b);
    simde_test_x86_assert_equal_i64x8(r, simde_mm512_loadu_epi64(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_mm512_maskz_add_epi64 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const simde__mmask8 k;
    const int64_t a[16];
    const int64_t b[16];
    const int64_t r[16];
  } test_vec[] = {
    { UINT8_C(165),
      {  INT64_C( 6299320458837796671), -INT64_C( 3196421240547742572), -INT64_C( 9151855083952004989), -INT64_C( 2652966953870515301),
        -INT64_C( 3361856595458879637), -INT64_C( 8765515588673012554),  INT64_C( 4218943347121949634),  INT64_C( 8056360307695763285) },
      { -INT64_C( 6084423613766652800), -INT64_C(  986696027690857020),  INT64_C(  716507424025936408),  INT64_C( 2755580261000000714),
         INT64_C( 4185659851829194101), -INT64_C( 1359153785955268607),  INT64_C( 8651579458846990930),  INT64_C( 5266260289850313545) },
      {  INT64_C(  214896845071143871),  INT64_C(                   0), -INT64_C( 8435347659926068581),  INT64_C(                   0),
         INT64_C(                   0),  INT64_C( 8322074699081270455),  INT64_C(                   0), -INT64_C( 5124123476163474786) } },
    { UINT8_C( 48),
      {  INT64_C( 1327964625155044601), -INT64_C( 1979941431104987422), -INT64_C( 6388061835839239302),  INT64_C( 6198577468949612625),
         INT64_C( 7878256497849969529), -INT64_C( 8253649976125538866),  INT64_C( 7274427282076993456), -INT64_C( 5985215513423679939) },
      { -INT64_C( 5628578266044451862),  INT64_C( 6350840359232373634), -INT64_C(  993721339898183746), -INT64_C( 7573227544723558906),
        -INT64_C( 7078269819051780816),  INT64_C( 8967324078724744818), -INT64_C( 5423879114017925356), -INT64_C(  850101963731351568) },
      {  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
         INT64_C(  799986678798188713),  INT64_C(  713674102599205952),  INT64_C(                   0),  INT64_C(                   0) } },
    { UINT8_C(169),
      { -INT64_C( 3269505804180125889),  INT64_C( 4898802782180457107), -INT64_C( 4122299440839867048), -INT64_C( 2805040416254433388),
        -INT64_C( 3881074597838727547),  INT64_C( 1644288571922952801), -INT64_C(   91554778652228748),  INT64_C( 5302276918373401890) },
      { -INT64_C( 6606572555650556850),  INT64_C( 2829390529692828527),  INT64_C( 1381995888231790022),  INT64_C( 6568329687495316506),
        -INT64_C( 1303457298250678015), -INT64_C( 2013848872050549965),  INT64_C( 1771957535492024468), -INT64_C( 3657734556536641579) },
      {  INT64_C( 8570665713878868877),  INT64_C(                   0),  INT64_C(                   0),  INT64_C( 3763289271240883118),
         INT64_C(                   0), -INT64_C(  369560300127597164),  INT64_C(                   0),  INT64_C( 1644542361836760311) } },
    { UINT8_C(222),
      {  INT64_C( 1693716282863260189), -INT64_C( 7181241992025315484), -INT64_C( 2718570591168046034), -INT64_C( 9033248451413530712),
        -INT64_C( 5937343786860347514),  INT64_C( 1858518704354021561), -INT64_C( 4687457667859782492), -INT64_C( 7792311420757763850) },
      { -INT64_C( 5252692508087571419), -INT64_C(  611453451093374081), -INT64_C( 3394024332202210286), -INT64_C( 5460606234653922919),
         INT64_C( 9036821187608596148),  INT64_C( 1013709022150741447), -INT64_C( 5106768477839482762),  INT64_C(  561708961651182727) },
      {  INT64_C(                   0), -INT64_C( 7792695443118689565), -INT64_C( 6112594923370256320),  INT64_C( 3952889387642097985),
         INT64_C( 3099477400748248634),  INT64_C(                   0),  INT64_C( 8652517928010286362), -INT64_C( 7230602459106581123) } },
    { UINT8_C(229),
      {  INT64_C( 8138391701483141613),  INT64_C( 4406625028354607943), -INT64_C( 1993379839983388751),  INT64_C( 2662541310383647862),
         INT64_C( 9046393778122708729),  INT64_C( 2568271637353789258), -INT64_C( 8121881179064237364), -INT64_C( 5039088444989734475) },
      { -INT64_C( 1722519523622035611),  INT64_C( 7561249774353008216), -INT64_C( 2405460785354645258),  INT64_C( 3464354200514345880),
        -INT64_C( 6718838163239081926), -INT64_C(  275183546372714198), -INT64_C( 6250246341167154373),  INT64_C( 2512751206208769253) },
      {  INT64_C( 6415872177861106002),  INT64_C(                   0), -INT64_C( 4398840625338034009),  INT64_C(                   0),
         INT64_C(                   0),  INT64_C( 2293088090981075060),  INT64_C( 4074616553478159879), -INT64_C( 2526337238780965222) } },
    { UINT8_C(254),
      { -INT64_C( 3622607429175870549), -INT64_C( 6274694410419404970), -INT64_C( 7031979866514108454), -INT64_C( 6667111988167567258),
         INT64_C(   12644015949398435), -INT64_C( 6358628794173882517),  INT64_C( 4907679902253939692), -INT64_C( 1348765095626235475) },
      { -INT64_C( 3412187665191306502), -INT64_C( 2311003071927724424),  INT64_C( 6505582346217724197),  INT64_C( 4346333461565343769),
        -INT64_C( 8000778778988929343), -INT64_C( 5787191995171151651), -INT64_C( 7069248972678558756), -INT64_C( 1332976243435314173) },
      {  INT64_C(                   0), -INT64_C( 8585697482347129394), -INT64_C(  526397520296384257), -INT64_C( 2320778526602223489),
        -INT64_C( 7988134763039530908),  INT64_C( 6300923284364517448), -INT64_C( 2161569070424619064), -INT64_C( 2681741339061549648) } },
    { UINT8_C(239),
      { -INT64_C( 1385535232953346975),  INT64_C( 5696251178006254957),  INT64_C( 6906112230749870041), -INT64_C(  166219096561869968),
        -INT64_C( 4862855913802450804), -INT64_C(  444736920620238273), -INT64_C( 8760446760531417455), -INT64_C(  334961341082568769) },
      {  INT64_C( 2935809197118471858),  INT64_C( 3902790899556199184),  INT64_C( 6467643616834876965), -INT64_C( 5327742948472452442),
        -INT64_C( 4008634985254182324), -INT64_C( 5837191191359649246), -INT64_C( 7634820792522817257),  INT64_C( 1904947663936929972) },
      {  INT64_C( 1550273964165124883), -INT64_C( 8847701996147097475), -INT64_C( 5072988226124804610), -INT64_C( 5493962045034322410),
         INT64_C(                   0), -INT64_C( 6281928111979887519),  INT64_C( 2051476520655316904),  INT64_C( 1569986322854361203) } },
    { UINT8_C( 94),
      { -INT64_C( 5133576159156088793), -INT64_C( 3958400705177220649), -INT64_C( 8271053347050896680), -INT64_C( 8784986448452653061),
        -INT64_C( 2149372564095095867),  INT64_C( 3728957796702186606), -INT64_C( 4321223872130680659), -INT64_C( 7079217880864431396) },
      {  INT64_C( 4154637502148371899),  INT64_C( 2033637388041814953), -INT64_C( 5191631281194602905), -INT64_C( 5010619628260266496),
         INT64_C( 7826456547109668761),  INT64_C( 2465062992106081707),  INT64_C( 7649721765552376983),  INT64_C( 7524593379129367732) },
      {  INT64_C(                   0), -INT64_C( 1924763317135405696),  INT64_C( 4984059445464052031),  INT64_C( 4651137996996632059),
         INT64_C( 5677083983014572894),  INT64_C(                   0),  INT64_C( 3328497893421696324),  INT64_C(                   0) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i a = simde_mm512_loadu_epi64(test_vec[i].a);
    simde__m512i b = simde_mm512_loadu_epi64(test_vec[i].b);
    simde__m512i r = simde_mm512_maskz_add_epi64(test_vec[i].k, a, b);
    simde_test_x86_assert_equal_i64x8(r, simde_mm512_loadu_epi64(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_mm512_add_ps (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float32 a[16];
    simde_float32 b[16];
    simde_float32 r[16];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(   667.91), SIMDE_FLOAT32_C(   656.58), SIMDE_FLOAT32_C(  -596.78), SIMDE_FLOAT32_C(  -487.31),
        SIMDE_FLOAT32_C(  -822.62), SIMDE_FLOAT32_C(   812.31), SIMDE_FLOAT32_C(    89.92), SIMDE_FLOAT32_C(  -844.98),
        SIMDE_FLOAT32_C(  -326.84), SIMDE_FLOAT32_C(  -869.81), SIMDE_FLOAT32_C(  -327.10), SIMDE_FLOAT32_C(  -520.41),
        SIMDE_FLOAT32_C(   590.39), SIMDE_FLOAT32_C(   190.09), SIMDE_FLOAT32_C(  -999.49), SIMDE_FLOAT32_C(   279.05) },
      { SIMDE_FLOAT32_C(   510.55), SIMDE_FLOAT32_C(   821.50), SIMDE_FLOAT32_C(  -282.52), SIMDE_FLOAT32_C(   624.18),
        SIMDE_FLOAT32_C(   410.62), SIMDE_FLOAT32_C(  -938.89), SIMDE_FLOAT32_C(    71.79), SIMDE_FLOAT32_C(   376.91),
        SIMDE_FLOAT32_C(   674.13), SIMDE_FLOAT32_C(    85.78), SIMDE_FLOAT32_C(   -18.27), SIMDE_FLOAT32_C(   115.82),
        SIMDE_FLOAT32_C(  -281.68), SIMDE_FLOAT32_C(  -193.16), SIMDE_FLOAT32_C(  -673.77), SIMDE_FLOAT32_C(  -613.77) },
      { SIMDE_FLOAT32_C(  1178.46), SIMDE_FLOAT32_C(  1478.08), SIMDE_FLOAT32_C(  -879.31), SIMDE_FLOAT32_C(   136.87),
        SIMDE_FLOAT32_C(  -412.00), SIMDE_FLOAT32_C(  -126.58), SIMDE_FLOAT32_C(   161.71), SIMDE_FLOAT32_C(  -468.07),
        SIMDE_FLOAT32_C(   347.28), SIMDE_FLOAT32_C(  -784.02), SIMDE_FLOAT32_C(  -345.37), SIMDE_FLOAT32_C(  -404.59),
        SIMDE_FLOAT32_C(   308.71), SIMDE_FLOAT32_C(    -3.07), SIMDE_FLOAT32_C( -1673.26), SIMDE_FLOAT32_C(  -334.72) } },
    { { SIMDE_FLOAT32_C(  -536.58), SIMDE_FLOAT32_C(  -270.56), SIMDE_FLOAT32_C(  -101.08), SIMDE_FLOAT32_C(  -359.21),
        SIMDE_FLOAT32_C(  -458.24), SIMDE_FLOAT32_C(   988.84), SIMDE_FLOAT32_C(  -204.19), SIMDE_FLOAT32_C(   214.91),
        SIMDE_FLOAT32_C(  -880.97), SIMDE_FLOAT32_C(   468.71), SIMDE_FLOAT32_C(   694.51), SIMDE_FLOAT32_C(   709.42),
        SIMDE_FLOAT32_C(  -341.20), SIMDE_FLOAT32_C(   695.02), SIMDE_FLOAT32_C(   -11.52), SIMDE_FLOAT32_C(  -830.65) },
      { SIMDE_FLOAT32_C(   516.52), SIMDE_FLOAT32_C(   705.95), SIMDE_FLOAT32_C(   793.53), SIMDE_FLOAT32_C(   -72.87),
        SIMDE_FLOAT32_C(   767.06), SIMDE_FLOAT32_C(  -134.68), SIMDE_FLOAT32_C(  -695.95), SIMDE_FLOAT32_C(   441.19),
        SIMDE_FLOAT32_C(   951.11), SIMDE_FLOAT32_C(   285.78), SIMDE_FLOAT32_C(  -442.99), SIMDE_FLOAT32_C(  -330.57),
        SIMDE_FLOAT32_C(  -907.38), SIMDE_FLOAT32_C(  -116.76), SIMDE_FLOAT32_C(    55.65), SIMDE_FLOAT32_C(  -443.96) },
      { SIMDE_FLOAT32_C(   -20.07), SIMDE_FLOAT32_C(   435.40), SIMDE_FLOAT32_C(   692.45), SIMDE_FLOAT32_C(  -432.07),
        SIMDE_FLOAT32_C(   308.82), SIMDE_FLOAT32_C(   854.16), SIMDE_FLOAT32_C(  -900.14), SIMDE_FLOAT32_C(   656.10),
        SIMDE_FLOAT32_C(    70.14), SIMDE_FLOAT32_C(   754.49), SIMDE_FLOAT32_C(   251.51), SIMDE_FLOAT32_C(   378.85),
        SIMDE_FLOAT32_C( -1248.58), SIMDE_FLOAT32_C(   578.25), SIMDE_FLOAT32_C(    44.13), SIMDE_FLOAT32_C( -1274.61) } },
    { { SIMDE_FLOAT32_C(   612.68), SIMDE_FLOAT32_C(   954.57), SIMDE_FLOAT32_C(   196.83), SIMDE_FLOAT32_C(  -845.56),
        SIMDE_FLOAT32_C(   943.41), SIMDE_FLOAT32_C(   992.64), SIMDE_FLOAT32_C(   369.35), SIMDE_FLOAT32_C(  -937.56),
        SIMDE_FLOAT32_C(   461.35), SIMDE_FLOAT32_C(    63.86), SIMDE_FLOAT32_C(   771.86), SIMDE_FLOAT32_C(  -879.85),
        SIMDE_FLOAT32_C(  -241.12), SIMDE_FLOAT32_C(  -239.67), SIMDE_FLOAT32_C(  -710.49), SIMDE_FLOAT32_C(  -724.61) },
      { SIMDE_FLOAT32_C(  -533.71), SIMDE_FLOAT32_C(  -916.96), SIMDE_FLOAT32_C(   202.53), SIMDE_FLOAT32_C(  -766.65),
        SIMDE_FLOAT32_C(   -51.64), SIMDE_FLOAT32_C(   506.57), SIMDE_FLOAT32_C(   674.54), SIMDE_FLOAT32_C(  -100.53),
        SIMDE_FLOAT32_C(  -207.65), SIMDE_FLOAT32_C(  -768.46), SIMDE_FLOAT32_C(   568.90), SIMDE_FLOAT32_C(  -115.03),
        SIMDE_FLOAT32_C(   114.78), SIMDE_FLOAT32_C(  -375.45), SIMDE_FLOAT32_C(   441.01), SIMDE_FLOAT32_C(  -272.54) },
      { SIMDE_FLOAT32_C(    78.97), SIMDE_FLOAT32_C(    37.61), SIMDE_FLOAT32_C(   399.35), SIMDE_FLOAT32_C( -1612.21),
        SIMDE_FLOAT32_C(   891.77), SIMDE_FLOAT32_C(  1499.21), SIMDE_FLOAT32_C(  1043.89), SIMDE_FLOAT32_C( -1038.09),
        SIMDE_FLOAT32_C(   253.70), SIMDE_FLOAT32_C(  -704.60), SIMDE_FLOAT32_C(  1340.75), SIMDE_FLOAT32_C(  -994.87),
        SIMDE_FLOAT32_C(  -126.35), SIMDE_FLOAT32_C(  -615.12), SIMDE_FLOAT32_C(  -269.48), SIMDE_FLOAT32_C(  -997.15) } },
    { { SIMDE_FLOAT32_C(  -420.88), SIMDE_FLOAT32_C(  -362.16), SIMDE_FLOAT32_C(  -118.10), SIMDE_FLOAT32_C(  -477.47),
        SIMDE_FLOAT32_C(  -369.52), SIMDE_FLOAT32_C(  -748.75), SIMDE_FLOAT32_C(  -415.03), SIMDE_FLOAT32_C(  -908.17),
        SIMDE_FLOAT32_C(   315.11), SIMDE_FLOAT32_C(  -643.17), SIMDE_FLOAT32_C(  -788.02), SIMDE_FLOAT32_C(  -926.02),
        SIMDE_FLOAT32_C(   117.16), SIMDE_FLOAT32_C(  -498.52), SIMDE_FLOAT32_C(  -650.63), SIMDE_FLOAT32_C(   583.45) },
      { SIMDE_FLOAT32_C(  -415.48), SIMDE_FLOAT32_C(   551.90), SIMDE_FLOAT32_C(   816.80), SIMDE_FLOAT32_C(   532.88),
        SIMDE_FLOAT32_C(    58.47), SIMDE_FLOAT32_C(   491.34), SIMDE_FLOAT32_C(  -567.65), SIMDE_FLOAT32_C(   850.83),
        SIMDE_FLOAT32_C(   722.88), SIMDE_FLOAT32_C(  -998.75), SIMDE_FLOAT32_C(  -264.20), SIMDE_FLOAT32_C(  -162.34),
        SIMDE_FLOAT32_C(  -374.20), SIMDE_FLOAT32_C(  -823.19), SIMDE_FLOAT32_C(   565.12), SIMDE_FLOAT32_C(   204.92) },
      { SIMDE_FLOAT32_C(  -836.35), SIMDE_FLOAT32_C(   189.74), SIMDE_FLOAT32_C(   698.70), SIMDE_FLOAT32_C(    55.42),
        SIMDE_FLOAT32_C(  -311.05), SIMDE_FLOAT32_C(  -257.41), SIMDE_FLOAT32_C(  -982.68), SIMDE_FLOAT32_C(   -57.35),
        SIMDE_FLOAT32_C(  1037.99), SIMDE_FLOAT32_C( -1641.92), SIMDE_FLOAT32_C( -1052.22), SIMDE_FLOAT32_C( -1088.36),
        SIMDE_FLOAT32_C(  -257.04), SIMDE_FLOAT32_C( -1321.70), SIMDE_FLOAT32_C(   -85.51), SIMDE_FLOAT32_C(   788.38) } },
    { { SIMDE_FLOAT32_C(  -185.35), SIMDE_FLOAT32_C(  -552.99), SIMDE_FLOAT32_C(   727.46), SIMDE_FLOAT32_C(   445.13),
        SIMDE_FLOAT32_C(  -301.74), SIMDE_FLOAT32_C(  -687.57), SIMDE_FLOAT32_C(   536.96), SIMDE_FLOAT32_C(  -986.63),
        SIMDE_FLOAT32_C(  -330.75), SIMDE_FLOAT32_C(   748.93), SIMDE_FLOAT32_C(  -912.65), SIMDE_FLOAT32_C(   786.42),
        SIMDE_FLOAT32_C(  -749.58), SIMDE_FLOAT32_C(  -563.28), SIMDE_FLOAT32_C(   369.87), SIMDE_FLOAT32_C(  -165.06) },
      { SIMDE_FLOAT32_C(   988.62), SIMDE_FLOAT32_C(   186.67), SIMDE_FLOAT32_C(  -632.17), SIMDE_FLOAT32_C(    47.10),
        SIMDE_FLOAT32_C(  -321.99), SIMDE_FLOAT32_C(  -199.82), SIMDE_FLOAT32_C(  -102.08), SIMDE_FLOAT32_C(  -599.11),
        SIMDE_FLOAT32_C(  -198.57), SIMDE_FLOAT32_C(   633.73), SIMDE_FLOAT32_C(   238.55), SIMDE_FLOAT32_C(   427.23),
        SIMDE_FLOAT32_C(   810.54), SIMDE_FLOAT32_C(  -196.33), SIMDE_FLOAT32_C(  -367.85), SIMDE_FLOAT32_C(  -374.81) },
      { SIMDE_FLOAT32_C(   803.28), SIMDE_FLOAT32_C(  -366.32), SIMDE_FLOAT32_C(    95.28), SIMDE_FLOAT32_C(   492.23),
        SIMDE_FLOAT32_C(  -623.73), SIMDE_FLOAT32_C(  -887.39), SIMDE_FLOAT32_C(   434.88), SIMDE_FLOAT32_C( -1585.74),
        SIMDE_FLOAT32_C(  -529.32), SIMDE_FLOAT32_C(  1382.66), SIMDE_FLOAT32_C(  -674.10), SIMDE_FLOAT32_C(  1213.65),
        SIMDE_FLOAT32_C(    60.96), SIMDE_FLOAT32_C(  -759.61), SIMDE_FLOAT32_C(     2.02), SIMDE_FLOAT32_C(  -539.87) } },
    { { SIMDE_FLOAT32_C(   250.68), SIMDE_FLOAT32_C(  -640.39), SIMDE_FLOAT32_C(  -929.68), SIMDE_FLOAT32_C(   948.94),
        SIMDE_FLOAT32_C(  -327.96), SIMDE_FLOAT32_C(   607.27), SIMDE_FLOAT32_C(   962.31), SIMDE_FLOAT32_C(   341.29),
        SIMDE_FLOAT32_C(   356.21), SIMDE_FLOAT32_C(  -950.34), SIMDE_FLOAT32_C(   127.71), SIMDE_FLOAT32_C(   606.63),
        SIMDE_FLOAT32_C(  -513.62), SIMDE_FLOAT32_C(  -502.42), SIMDE_FLOAT32_C(  -558.43), SIMDE_FLOAT32_C(  -524.99) },
      { SIMDE_FLOAT32_C(   684.24), SIMDE_FLOAT32_C(  -190.61), SIMDE_FLOAT32_C(   522.10), SIMDE_FLOAT32_C(  -637.75),
        SIMDE_FLOAT32_C(   609.57), SIMDE_FLOAT32_C(  -579.97), SIMDE_FLOAT32_C(  -236.86), SIMDE_FLOAT32_C(  -589.00),
        SIMDE_FLOAT32_C(  -946.25), SIMDE_FLOAT32_C(  -998.31), SIMDE_FLOAT32_C(   838.23), SIMDE_FLOAT32_C(   864.29),
        SIMDE_FLOAT32_C(  -194.64), SIMDE_FLOAT32_C(  -529.61), SIMDE_FLOAT32_C(  -510.52), SIMDE_FLOAT32_C(  -943.96) },
      { SIMDE_FLOAT32_C(   934.92), SIMDE_FLOAT32_C(  -831.00), SIMDE_FLOAT32_C(  -407.58), SIMDE_FLOAT32_C(   311.19),
        SIMDE_FLOAT32_C(   281.61), SIMDE_FLOAT32_C(    27.30), SIMDE_FLOAT32_C(   725.45), SIMDE_FLOAT32_C(  -247.71),
        SIMDE_FLOAT32_C(  -590.04), SIMDE_FLOAT32_C( -1948.65), SIMDE_FLOAT32_C(   965.94), SIMDE_FLOAT32_C(  1470.92),
        SIMDE_FLOAT32_C(  -708.26), SIMDE_FLOAT32_C( -1032.04), SIMDE_FLOAT32_C( -1068.95), SIMDE_FLOAT32_C( -1468.95) } },
    { { SIMDE_FLOAT32_C(  -170.00), SIMDE_FLOAT32_C(  -440.20), SIMDE_FLOAT32_C(  -995.02), SIMDE_FLOAT32_C(   502.03),
        SIMDE_FLOAT32_C(  -832.92), SIMDE_FLOAT32_C(   967.29), SIMDE_FLOAT32_C(  -156.68), SIMDE_FLOAT32_C(   523.28),
        SIMDE_FLOAT32_C(  -983.05), SIMDE_FLOAT32_C(   971.03), SIMDE_FLOAT32_C(   129.91), SIMDE_FLOAT32_C(  -496.67),
        SIMDE_FLOAT32_C(  -531.39), SIMDE_FLOAT32_C(   571.48), SIMDE_FLOAT32_C(   -21.66), SIMDE_FLOAT32_C(  -847.15) },
      { SIMDE_FLOAT32_C(  -619.13), SIMDE_FLOAT32_C(  -499.55), SIMDE_FLOAT32_C(  -484.90), SIMDE_FLOAT32_C(   990.45),
        SIMDE_FLOAT32_C(   -79.53), SIMDE_FLOAT32_C(   278.24), SIMDE_FLOAT32_C(  -598.55), SIMDE_FLOAT32_C(   -25.77),
        SIMDE_FLOAT32_C(   279.93), SIMDE_FLOAT32_C(  -760.32), SIMDE_FLOAT32_C(  -161.48), SIMDE_FLOAT32_C(  -914.71),
        SIMDE_FLOAT32_C(  -289.93), SIMDE_FLOAT32_C(   328.00), SIMDE_FLOAT32_C(  -858.67), SIMDE_FLOAT32_C(   540.06) },
      { SIMDE_FLOAT32_C(  -789.13), SIMDE_FLOAT32_C(  -939.75), SIMDE_FLOAT32_C( -1479.92), SIMDE_FLOAT32_C(  1492.48),
        SIMDE_FLOAT32_C(  -912.45), SIMDE_FLOAT32_C(  1245.53), SIMDE_FLOAT32_C(  -755.23), SIMDE_FLOAT32_C(   497.51),
        SIMDE_FLOAT32_C(  -703.12), SIMDE_FLOAT32_C(   210.71), SIMDE_FLOAT32_C(   -31.57), SIMDE_FLOAT32_C( -1411.38),
        SIMDE_FLOAT32_C(  -821.33), SIMDE_FLOAT32_C(   899.48), SIMDE_FLOAT32_C(  -880.33), SIMDE_FLOAT32_C(  -307.09) } },
    { { SIMDE_FLOAT32_C(   887.80), SIMDE_FLOAT32_C(  -853.69), SIMDE_FLOAT32_C(    42.10), SIMDE_FLOAT32_C(  -945.12),
        SIMDE_FLOAT32_C(  -886.40), SIMDE_FLOAT32_C(   885.42), SIMDE_FLOAT32_C(   578.16), SIMDE_FLOAT32_C(  -869.46),
        SIMDE_FLOAT32_C(   856.45), SIMDE_FLOAT32_C(  -291.93), SIMDE_FLOAT32_C(  -366.12), SIMDE_FLOAT32_C(  -674.94),
        SIMDE_FLOAT32_C(  -720.45), SIMDE_FLOAT32_C(   612.22), SIMDE_FLOAT32_C(  -522.09), SIMDE_FLOAT32_C(  -339.57) },
      { SIMDE_FLOAT32_C(  -887.34), SIMDE_FLOAT32_C(    -6.99), SIMDE_FLOAT32_C(  -349.13), SIMDE_FLOAT32_C(    33.14),
        SIMDE_FLOAT32_C(  -728.74), SIMDE_FLOAT32_C(    52.32), SIMDE_FLOAT32_C(  -992.63), SIMDE_FLOAT32_C(   551.19),
        SIMDE_FLOAT32_C(   292.00), SIMDE_FLOAT32_C(  -154.11), SIMDE_FLOAT32_C(   636.48), SIMDE_FLOAT32_C(  -997.93),
        SIMDE_FLOAT32_C(  -826.11), SIMDE_FLOAT32_C(   777.81), SIMDE_FLOAT32_C(   542.14), SIMDE_FLOAT32_C(  -938.31) },
      { SIMDE_FLOAT32_C(     0.46), SIMDE_FLOAT32_C(  -860.68), SIMDE_FLOAT32_C(  -307.03), SIMDE_FLOAT32_C(  -911.99),
        SIMDE_FLOAT32_C( -1615.15), SIMDE_FLOAT32_C(   937.74), SIMDE_FLOAT32_C(  -414.47), SIMDE_FLOAT32_C(  -318.27),
        SIMDE_FLOAT32_C(  1148.46), SIMDE_FLOAT32_C(  -446.04), SIMDE_FLOAT32_C(   270.35), SIMDE_FLOAT32_C( -1672.87),
        SIMDE_FLOAT32_C( -1546.56), SIMDE_FLOAT32_C(  1390.02), SIMDE_FLOAT32_C(    20.05), SIMDE_FLOAT32_C( -1277.88) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512 a = simde_mm512_loadu_ps(test_vec[i].a);
    simde__m512 b = simde_mm512_loadu_ps(test_vec[i].b);
    simde__m512 r = simde_mm512_add_ps(a, b);
    simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[i].r), 1);
  }

  return 0;
}

static int
test_simde_mm512_mask_add_ps (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float32 src[16];
    simde__mmask16 k;
    simde_float32 a[16];
    simde_float32 b[16];
    simde_float32 r[16];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(   460.46), SIMDE_FLOAT32_C(  -331.63), SIMDE_FLOAT32_C(   681.04), SIMDE_FLOAT32_C(  -156.99),
        SIMDE_FLOAT32_C(  -543.60), SIMDE_FLOAT32_C(    94.06), SIMDE_FLOAT32_C(   923.51), SIMDE_FLOAT32_C(  -881.03),
        SIMDE_FLOAT32_C(  -751.28), SIMDE_FLOAT32_C(  -565.86), SIMDE_FLOAT32_C(  -825.81), SIMDE_FLOAT32_C(   899.74),
        SIMDE_FLOAT32_C(   180.53), SIMDE_FLOAT32_C(  -308.94), SIMDE_FLOAT32_C(   105.08), SIMDE_FLOAT32_C(  -812.17) },
      UINT16_C(46254),
      { SIMDE_FLOAT32_C(   159.98), SIMDE_FLOAT32_C(   930.16), SIMDE_FLOAT32_C(  -647.50), SIMDE_FLOAT32_C(  -273.39),
        SIMDE_FLOAT32_C(  -580.12), SIMDE_FLOAT32_C(  -662.69), SIMDE_FLOAT32_C(  -636.46), SIMDE_FLOAT32_C(   880.33),
        SIMDE_FLOAT32_C(     5.69), SIMDE_FLOAT32_C(  -955.42), SIMDE_FLOAT32_C(  -276.66), SIMDE_FLOAT32_C(   462.09),
        SIMDE_FLOAT32_C(   138.64), SIMDE_FLOAT32_C(  -353.15), SIMDE_FLOAT32_C(   581.06), SIMDE_FLOAT32_C(   387.36) },
      { SIMDE_FLOAT32_C(    80.99), SIMDE_FLOAT32_C(   755.25), SIMDE_FLOAT32_C(   287.10), SIMDE_FLOAT32_C(  -738.48),
        SIMDE_FLOAT32_C(  -553.70), SIMDE_FLOAT32_C(  -607.83), SIMDE_FLOAT32_C(  -550.66), SIMDE_FLOAT32_C(   141.56),
        SIMDE_FLOAT32_C(  -486.72), SIMDE_FLOAT32_C(   158.46), SIMDE_FLOAT32_C(    11.82), SIMDE_FLOAT32_C(  -371.24),
        SIMDE_FLOAT32_C(   774.24), SIMDE_FLOAT32_C(  -643.60), SIMDE_FLOAT32_C(   412.35), SIMDE_FLOAT32_C(   -65.78) },
      { SIMDE_FLOAT32_C(   460.46), SIMDE_FLOAT32_C(  1685.41), SIMDE_FLOAT32_C(  -360.40), SIMDE_FLOAT32_C( -1011.87),
        SIMDE_FLOAT32_C(  -543.60), SIMDE_FLOAT32_C( -1270.51), SIMDE_FLOAT32_C(   923.51), SIMDE_FLOAT32_C(  1021.89),
        SIMDE_FLOAT32_C(  -751.28), SIMDE_FLOAT32_C(  -565.86), SIMDE_FLOAT32_C(  -264.84), SIMDE_FLOAT32_C(   899.74),
        SIMDE_FLOAT32_C(   912.88), SIMDE_FLOAT32_C(  -996.76), SIMDE_FLOAT32_C(   105.08), SIMDE_FLOAT32_C(   321.58) } },
    { { SIMDE_FLOAT32_C(  -713.44), SIMDE_FLOAT32_C(   764.86), SIMDE_FLOAT32_C(   660.83), SIMDE_FLOAT32_C(  -293.56),
        SIMDE_FLOAT32_C(  -897.83), SIMDE_FLOAT32_C(  -975.63), SIMDE_FLOAT32_C(  -413.23), SIMDE_FLOAT32_C(   107.86),
        SIMDE_FLOAT32_C(  -931.06), SIMDE_FLOAT32_C(   310.12), SIMDE_FLOAT32_C(  -430.05), SIMDE_FLOAT32_C(   207.58),
        SIMDE_FLOAT32_C(   956.96), SIMDE_FLOAT32_C(  -848.99), SIMDE_FLOAT32_C(  -405.06), SIMDE_FLOAT32_C(    37.95) },
      UINT16_C(56892),
      { SIMDE_FLOAT32_C(   -92.73), SIMDE_FLOAT32_C(  -494.07), SIMDE_FLOAT32_C(   416.25), SIMDE_FLOAT32_C(  -318.49),
        SIMDE_FLOAT32_C(  -137.67), SIMDE_FLOAT32_C(  -171.40), SIMDE_FLOAT32_C(   615.73), SIMDE_FLOAT32_C(   148.89),
        SIMDE_FLOAT32_C(  -406.54), SIMDE_FLOAT32_C(   276.56), SIMDE_FLOAT32_C(   855.33), SIMDE_FLOAT32_C(  -304.37),
        SIMDE_FLOAT32_C(   300.92), SIMDE_FLOAT32_C(  -557.90), SIMDE_FLOAT32_C(   803.48), SIMDE_FLOAT32_C(   369.86) },
      { SIMDE_FLOAT32_C(   752.21), SIMDE_FLOAT32_C(  -626.57), SIMDE_FLOAT32_C(  -422.55), SIMDE_FLOAT32_C(   709.18),
        SIMDE_FLOAT32_C(  -475.56), SIMDE_FLOAT32_C(   172.39), SIMDE_FLOAT32_C(  -252.87), SIMDE_FLOAT32_C(  -569.31),
        SIMDE_FLOAT32_C(    54.43), SIMDE_FLOAT32_C(  -953.40), SIMDE_FLOAT32_C(  -216.76), SIMDE_FLOAT32_C(   328.64),
        SIMDE_FLOAT32_C(   795.42), SIMDE_FLOAT32_C(  -722.64), SIMDE_FLOAT32_C(  -883.86), SIMDE_FLOAT32_C(  -297.31) },
      { SIMDE_FLOAT32_C(  -713.44), SIMDE_FLOAT32_C(   764.86), SIMDE_FLOAT32_C(    -6.30), SIMDE_FLOAT32_C(   390.69),
        SIMDE_FLOAT32_C(  -613.23), SIMDE_FLOAT32_C(     0.99), SIMDE_FLOAT32_C(  -413.23), SIMDE_FLOAT32_C(   107.86),
        SIMDE_FLOAT32_C(  -931.06), SIMDE_FLOAT32_C(  -676.84), SIMDE_FLOAT32_C(   638.57), SIMDE_FLOAT32_C(    24.27),
        SIMDE_FLOAT32_C(  1096.34), SIMDE_FLOAT32_C(  -848.99), SIMDE_FLOAT32_C(   -80.38), SIMDE_FLOAT32_C(    72.56) } },
    { { SIMDE_FLOAT32_C(  -216.71), SIMDE_FLOAT32_C(   532.39), SIMDE_FLOAT32_C(   384.21), SIMDE_FLOAT32_C(   645.62),
        SIMDE_FLOAT32_C(  -639.01), SIMDE_FLOAT32_C(    -0.07), SIMDE_FLOAT32_C(  -205.49), SIMDE_FLOAT32_C(   -45.55),
        SIMDE_FLOAT32_C(  -723.51), SIMDE_FLOAT32_C(  -350.17), SIMDE_FLOAT32_C(   650.08), SIMDE_FLOAT32_C(   577.41),
        SIMDE_FLOAT32_C(    91.93), SIMDE_FLOAT32_C(   453.57), SIMDE_FLOAT32_C(   -52.73), SIMDE_FLOAT32_C(  -155.86) },
      UINT16_C( 2131),
      { SIMDE_FLOAT32_C(   347.05), SIMDE_FLOAT32_C(   565.37), SIMDE_FLOAT32_C(    80.17), SIMDE_FLOAT32_C(   142.47),
        SIMDE_FLOAT32_C(   842.73), SIMDE_FLOAT32_C(   196.31), SIMDE_FLOAT32_C(   845.17), SIMDE_FLOAT32_C(  -373.98),
        SIMDE_FLOAT32_C(  -271.30), SIMDE_FLOAT32_C(   229.37), SIMDE_FLOAT32_C(  -728.36), SIMDE_FLOAT32_C(    89.69),
        SIMDE_FLOAT32_C(  -770.69), SIMDE_FLOAT32_C(    66.14), SIMDE_FLOAT32_C(  -955.85), SIMDE_FLOAT32_C(  -494.20) },
      { SIMDE_FLOAT32_C(   715.97), SIMDE_FLOAT32_C(   694.23), SIMDE_FLOAT32_C(  -916.79), SIMDE_FLOAT32_C(  -192.10),
        SIMDE_FLOAT32_C(   147.79), SIMDE_FLOAT32_C(    30.48), SIMDE_FLOAT32_C(   652.05), SIMDE_FLOAT32_C(   -25.21),
        SIMDE_FLOAT32_C(  -444.80), SIMDE_FLOAT32_C(  -794.64), SIMDE_FLOAT32_C(   326.23), SIMDE_FLOAT32_C(   252.31),
        SIMDE_FLOAT32_C(   505.81), SIMDE_FLOAT32_C(  -891.64), SIMDE_FLOAT32_C(     3.84), SIMDE_FLOAT32_C(  -147.13) },
      { SIMDE_FLOAT32_C(  1063.03), SIMDE_FLOAT32_C(  1259.60), SIMDE_FLOAT32_C(   384.21), SIMDE_FLOAT32_C(   645.62),
        SIMDE_FLOAT32_C(   990.52), SIMDE_FLOAT32_C(    -0.07), SIMDE_FLOAT32_C(  1497.21), SIMDE_FLOAT32_C(   -45.55),
        SIMDE_FLOAT32_C(  -723.51), SIMDE_FLOAT32_C(  -350.17), SIMDE_FLOAT32_C(   650.08), SIMDE_FLOAT32_C(   342.00),
        SIMDE_FLOAT32_C(    91.93), SIMDE_FLOAT32_C(   453.57), SIMDE_FLOAT32_C(   -52.73), SIMDE_FLOAT32_C(  -155.86) } },
    { { SIMDE_FLOAT32_C(   673.73), SIMDE_FLOAT32_C(  -915.98), SIMDE_FLOAT32_C(   995.34), SIMDE_FLOAT32_C(   516.46),
        SIMDE_FLOAT32_C(   280.33), SIMDE_FLOAT32_C(   840.51), SIMDE_FLOAT32_C(  -857.52), SIMDE_FLOAT32_C(  -990.97),
        SIMDE_FLOAT32_C(    69.88), SIMDE_FLOAT32_C(  -585.88), SIMDE_FLOAT32_C(    98.72), SIMDE_FLOAT32_C(   299.19),
        SIMDE_FLOAT32_C(   480.27), SIMDE_FLOAT32_C(   142.87), SIMDE_FLOAT32_C(   804.99), SIMDE_FLOAT32_C(   196.24) },
      UINT16_C(47953),
      { SIMDE_FLOAT32_C(   861.56), SIMDE_FLOAT32_C(  -714.09), SIMDE_FLOAT32_C(  -273.80), SIMDE_FLOAT32_C(   367.37),
        SIMDE_FLOAT32_C(  -605.73), SIMDE_FLOAT32_C(   730.04), SIMDE_FLOAT32_C(  -779.76), SIMDE_FLOAT32_C(  -932.00),
        SIMDE_FLOAT32_C(   814.06), SIMDE_FLOAT32_C(  -784.42), SIMDE_FLOAT32_C(   584.46), SIMDE_FLOAT32_C(    94.39),
        SIMDE_FLOAT32_C(  -943.91), SIMDE_FLOAT32_C(   726.95), SIMDE_FLOAT32_C(   103.42), SIMDE_FLOAT32_C(   125.97) },
      { SIMDE_FLOAT32_C(  -858.93), SIMDE_FLOAT32_C(  -797.86), SIMDE_FLOAT32_C(  -574.84), SIMDE_FLOAT32_C(   621.33),
        SIMDE_FLOAT32_C(   345.01), SIMDE_FLOAT32_C(  -769.85), SIMDE_FLOAT32_C(  -182.42), SIMDE_FLOAT32_C(  -817.89),
        SIMDE_FLOAT32_C(  -881.65), SIMDE_FLOAT32_C(  -178.28), SIMDE_FLOAT32_C(  -833.00), SIMDE_FLOAT32_C(    37.03),
        SIMDE_FLOAT32_C(  -522.09), SIMDE_FLOAT32_C(   126.68), SIMDE_FLOAT32_C(  -489.08), SIMDE_FLOAT32_C(  -660.53) },
      { SIMDE_FLOAT32_C(     2.62), SIMDE_FLOAT32_C(  -915.98), SIMDE_FLOAT32_C(   995.34), SIMDE_FLOAT32_C(   516.46),
        SIMDE_FLOAT32_C(  -260.72), SIMDE_FLOAT32_C(   840.51), SIMDE_FLOAT32_C(  -962.19), SIMDE_FLOAT32_C(  -990.97),
        SIMDE_FLOAT32_C(   -67.59), SIMDE_FLOAT32_C(  -962.70), SIMDE_FLOAT32_C(    98.72), SIMDE_FLOAT32_C(   131.42),
        SIMDE_FLOAT32_C( -1466.00), SIMDE_FLOAT32_C(   853.63), SIMDE_FLOAT32_C(   804.99), SIMDE_FLOAT32_C(  -534.56) } },
    { { SIMDE_FLOAT32_C(   412.59), SIMDE_FLOAT32_C(   237.12), SIMDE_FLOAT32_C(   706.84), SIMDE_FLOAT32_C(   806.86),
        SIMDE_FLOAT32_C(   -32.84), SIMDE_FLOAT32_C(   927.07), SIMDE_FLOAT32_C(   874.86), SIMDE_FLOAT32_C(  -218.78),
        SIMDE_FLOAT32_C(  -857.35), SIMDE_FLOAT32_C(   459.32), SIMDE_FLOAT32_C(   875.61), SIMDE_FLOAT32_C(  -801.26),
        SIMDE_FLOAT32_C(   186.27), SIMDE_FLOAT32_C(   -20.97), SIMDE_FLOAT32_C(   324.71), SIMDE_FLOAT32_C(   327.34) },
      UINT16_C(16785),
      { SIMDE_FLOAT32_C(  -412.03), SIMDE_FLOAT32_C(  -124.71), SIMDE_FLOAT32_C(   135.41), SIMDE_FLOAT32_C(    65.88),
        SIMDE_FLOAT32_C(  -998.03), SIMDE_FLOAT32_C(   646.33), SIMDE_FLOAT32_C(   405.35), SIMDE_FLOAT32_C(   414.56),
        SIMDE_FLOAT32_C(  -116.55), SIMDE_FLOAT32_C(   112.18), SIMDE_FLOAT32_C(   221.42), SIMDE_FLOAT32_C(   850.61),
        SIMDE_FLOAT32_C(    39.26), SIMDE_FLOAT32_C(    96.28), SIMDE_FLOAT32_C(  -368.17), SIMDE_FLOAT32_C(   181.91) },
      { SIMDE_FLOAT32_C(  -444.40), SIMDE_FLOAT32_C(  -492.56), SIMDE_FLOAT32_C(   380.65), SIMDE_FLOAT32_C(   741.87),
        SIMDE_FLOAT32_C(   486.46), SIMDE_FLOAT32_C(  -294.64), SIMDE_FLOAT32_C(    69.20), SIMDE_FLOAT32_C(  -332.37),
        SIMDE_FLOAT32_C(  -544.77), SIMDE_FLOAT32_C(  -982.12), SIMDE_FLOAT32_C(   193.82), SIMDE_FLOAT32_C(  -564.75),
        SIMDE_FLOAT32_C(   784.12), SIMDE_FLOAT32_C(   902.11), SIMDE_FLOAT32_C(  -466.37), SIMDE_FLOAT32_C(  -627.91) },
      { SIMDE_FLOAT32_C(  -856.43), SIMDE_FLOAT32_C(   237.12), SIMDE_FLOAT32_C(   706.84), SIMDE_FLOAT32_C(   806.86),
        SIMDE_FLOAT32_C(  -511.57), SIMDE_FLOAT32_C(   927.07), SIMDE_FLOAT32_C(   874.86), SIMDE_FLOAT32_C(    82.19),
        SIMDE_FLOAT32_C(  -661.32), SIMDE_FLOAT32_C(   459.32), SIMDE_FLOAT32_C(   875.61), SIMDE_FLOAT32_C(  -801.26),
        SIMDE_FLOAT32_C(   186.27), SIMDE_FLOAT32_C(   -20.97), SIMDE_FLOAT32_C(  -834.55), SIMDE_FLOAT32_C(   327.34) } },
    { { SIMDE_FLOAT32_C(  -222.60), SIMDE_FLOAT32_C(   669.04), SIMDE_FLOAT32_C(   437.97), SIMDE_FLOAT32_C(  -220.63),
        SIMDE_FLOAT32_C(   315.37), SIMDE_FLOAT32_C(  -156.68), SIMDE_FLOAT32_C(  -806.07), SIMDE_FLOAT32_C(  -801.18),
        SIMDE_FLOAT32_C(   955.50), SIMDE_FLOAT32_C(   415.35), SIMDE_FLOAT32_C(  -950.57), SIMDE_FLOAT32_C(    -5.24),
        SIMDE_FLOAT32_C(  -488.38), SIMDE_FLOAT32_C(  -318.75), SIMDE_FLOAT32_C(  -823.33), SIMDE_FLOAT32_C(    67.22) },
      UINT16_C(17154),
      { SIMDE_FLOAT32_C(   896.17), SIMDE_FLOAT32_C(  -463.40), SIMDE_FLOAT32_C(   153.15), SIMDE_FLOAT32_C(   680.29),
        SIMDE_FLOAT32_C(  -561.29), SIMDE_FLOAT32_C(   686.78), SIMDE_FLOAT32_C(  -947.62), SIMDE_FLOAT32_C(   216.11),
        SIMDE_FLOAT32_C(   355.82), SIMDE_FLOAT32_C(   490.35), SIMDE_FLOAT32_C(   995.48), SIMDE_FLOAT32_C(  -328.82),
        SIMDE_FLOAT32_C(  -666.33), SIMDE_FLOAT32_C(  -810.59), SIMDE_FLOAT32_C(  -130.00), SIMDE_FLOAT32_C(  -710.83) },
      { SIMDE_FLOAT32_C(   604.75), SIMDE_FLOAT32_C(   -80.58), SIMDE_FLOAT32_C(   283.92), SIMDE_FLOAT32_C(  -883.63),
        SIMDE_FLOAT32_C(   600.68), SIMDE_FLOAT32_C(   460.59), SIMDE_FLOAT32_C(   183.59), SIMDE_FLOAT32_C(  -210.63),
        SIMDE_FLOAT32_C(    17.91), SIMDE_FLOAT32_C(   992.68), SIMDE_FLOAT32_C(   464.52), SIMDE_FLOAT32_C(   280.58),
        SIMDE_FLOAT32_C(   870.97), SIMDE_FLOAT32_C(  -192.70), SIMDE_FLOAT32_C(   998.48), SIMDE_FLOAT32_C(   767.14) },
      { SIMDE_FLOAT32_C(  -222.60), SIMDE_FLOAT32_C(  -543.97), SIMDE_FLOAT32_C(   437.97), SIMDE_FLOAT32_C(  -220.63),
        SIMDE_FLOAT32_C(   315.37), SIMDE_FLOAT32_C(  -156.68), SIMDE_FLOAT32_C(  -806.07), SIMDE_FLOAT32_C(  -801.18),
        SIMDE_FLOAT32_C(   373.72), SIMDE_FLOAT32_C(  1483.03), SIMDE_FLOAT32_C(  -950.57), SIMDE_FLOAT32_C(    -5.24),
        SIMDE_FLOAT32_C(  -488.38), SIMDE_FLOAT32_C(  -318.75), SIMDE_FLOAT32_C(   868.48), SIMDE_FLOAT32_C(    67.22) } },
    { { SIMDE_FLOAT32_C(   343.91), SIMDE_FLOAT32_C(   151.64), SIMDE_FLOAT32_C(   447.43), SIMDE_FLOAT32_C(   782.62),
        SIMDE_FLOAT32_C(  -161.58), SIMDE_FLOAT32_C(   499.81), SIMDE_FLOAT32_C(    -1.27), SIMDE_FLOAT32_C(  -805.77),
        SIMDE_FLOAT32_C(    -9.84), SIMDE_FLOAT32_C(    -5.79), SIMDE_FLOAT32_C(  -134.58), SIMDE_FLOAT32_C(   323.82),
        SIMDE_FLOAT32_C(   183.61), SIMDE_FLOAT32_C(   735.41), SIMDE_FLOAT32_C(   612.99), SIMDE_FLOAT32_C(  -211.63) },
      UINT16_C(55098),
      { SIMDE_FLOAT32_C(  -918.99), SIMDE_FLOAT32_C(  -490.60), SIMDE_FLOAT32_C(  -344.01), SIMDE_FLOAT32_C(   951.99),
        SIMDE_FLOAT32_C(   316.70), SIMDE_FLOAT32_C(  -345.53), SIMDE_FLOAT32_C(   719.12), SIMDE_FLOAT32_C(  -339.39),
        SIMDE_FLOAT32_C(   806.11), SIMDE_FLOAT32_C(   166.55), SIMDE_FLOAT32_C(  -556.77), SIMDE_FLOAT32_C(  -355.47),
        SIMDE_FLOAT32_C(  -333.64), SIMDE_FLOAT32_C(   441.96), SIMDE_FLOAT32_C(  -161.24), SIMDE_FLOAT32_C(   656.52) },
      { SIMDE_FLOAT32_C(  -563.83), SIMDE_FLOAT32_C(   704.18), SIMDE_FLOAT32_C(   -19.66), SIMDE_FLOAT32_C(   619.78),
        SIMDE_FLOAT32_C(   439.59), SIMDE_FLOAT32_C(  -406.67), SIMDE_FLOAT32_C(  -591.85), SIMDE_FLOAT32_C(  -905.57),
        SIMDE_FLOAT32_C(   490.24), SIMDE_FLOAT32_C(   312.88), SIMDE_FLOAT32_C(  -650.06), SIMDE_FLOAT32_C(   847.74),
        SIMDE_FLOAT32_C(   401.22), SIMDE_FLOAT32_C(   394.82), SIMDE_FLOAT32_C(   223.15), SIMDE_FLOAT32_C(   482.23) },
      { SIMDE_FLOAT32_C(   343.91), SIMDE_FLOAT32_C(   213.57), SIMDE_FLOAT32_C(   447.43), SIMDE_FLOAT32_C(  1571.77),
        SIMDE_FLOAT32_C(   756.29), SIMDE_FLOAT32_C(  -752.20), SIMDE_FLOAT32_C(    -1.27), SIMDE_FLOAT32_C(  -805.77),
        SIMDE_FLOAT32_C(  1296.35), SIMDE_FLOAT32_C(   479.44), SIMDE_FLOAT32_C( -1206.83), SIMDE_FLOAT32_C(   323.82),
        SIMDE_FLOAT32_C(    67.58), SIMDE_FLOAT32_C(   735.41), SIMDE_FLOAT32_C(    61.91), SIMDE_FLOAT32_C(  1138.75) } },
    { { SIMDE_FLOAT32_C(   904.21), SIMDE_FLOAT32_C(   879.14), SIMDE_FLOAT32_C(   434.21), SIMDE_FLOAT32_C(   220.91),
        SIMDE_FLOAT32_C(  -466.39), SIMDE_FLOAT32_C(   153.34), SIMDE_FLOAT32_C(   881.52), SIMDE_FLOAT32_C(  -660.28),
        SIMDE_FLOAT32_C(  -680.11), SIMDE_FLOAT32_C(  -675.25), SIMDE_FLOAT32_C(   -15.75), SIMDE_FLOAT32_C(   -13.75),
        SIMDE_FLOAT32_C(   766.71), SIMDE_FLOAT32_C(   823.02), SIMDE_FLOAT32_C(  -357.23), SIMDE_FLOAT32_C(  -797.13) },
      UINT16_C(62059),
      { SIMDE_FLOAT32_C(   543.68), SIMDE_FLOAT32_C(   411.16), SIMDE_FLOAT32_C(   554.42), SIMDE_FLOAT32_C(   -55.10),
        SIMDE_FLOAT32_C(  -194.03), SIMDE_FLOAT32_C(  -222.43), SIMDE_FLOAT32_C(  -572.87), SIMDE_FLOAT32_C(  -289.81),
        SIMDE_FLOAT32_C(  -343.29), SIMDE_FLOAT32_C(   861.34), SIMDE_FLOAT32_C(   931.10), SIMDE_FLOAT32_C(   190.32),
        SIMDE_FLOAT32_C(    14.68), SIMDE_FLOAT32_C(   812.62), SIMDE_FLOAT32_C(   530.05), SIMDE_FLOAT32_C(   334.57) },
      { SIMDE_FLOAT32_C(  -862.62), SIMDE_FLOAT32_C(  -485.70), SIMDE_FLOAT32_C(  -679.18), SIMDE_FLOAT32_C(   904.08),
        SIMDE_FLOAT32_C(  -662.68), SIMDE_FLOAT32_C(   -36.41), SIMDE_FLOAT32_C(  -893.04), SIMDE_FLOAT32_C(   864.51),
        SIMDE_FLOAT32_C(  -413.30), SIMDE_FLOAT32_C(   929.61), SIMDE_FLOAT32_C(  -168.70), SIMDE_FLOAT32_C(  -196.86),
        SIMDE_FLOAT32_C(  -839.59), SIMDE_FLOAT32_C(   892.52), SIMDE_FLOAT32_C(  -490.18), SIMDE_FLOAT32_C(   704.10) },
      { SIMDE_FLOAT32_C(  -318.94), SIMDE_FLOAT32_C(   -74.54), SIMDE_FLOAT32_C(   434.21), SIMDE_FLOAT32_C(   848.98),
        SIMDE_FLOAT32_C(  -466.39), SIMDE_FLOAT32_C(  -258.84), SIMDE_FLOAT32_C( -1465.91), SIMDE_FLOAT32_C(  -660.28),
        SIMDE_FLOAT32_C(  -680.11), SIMDE_FLOAT32_C(  1790.95), SIMDE_FLOAT32_C(   -15.75), SIMDE_FLOAT32_C(   -13.75),
        SIMDE_FLOAT32_C(  -824.91), SIMDE_FLOAT32_C(  1705.14), SIMDE_FLOAT32_C(    39.87), SIMDE_FLOAT32_C(  1038.67) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512 src = simde_mm512_loadu_ps(test_vec[i].src);
    simde__m512 a = simde_mm512_loadu_ps(test_vec[i].a);
    simde__m512 b = simde_mm512_loadu_ps(test_vec[i].b);
    simde__m512 r = simde_mm512_mask_add_ps(src, test_vec[i].k, a, b);
    simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[i].r), 1);
  }

  return 0;
}

static int
test_simde_mm512_maskz_add_ps (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde__mmask16 k;
    simde_float32 a[16];
    simde_float32 b[16];
    simde_float32 r[16];
  } test_vec[] = {
    { UINT16_C( 7629),
      { SIMDE_FLOAT32_C(   914.45), SIMDE_FLOAT32_C(   855.01), SIMDE_FLOAT32_C(    38.80), SIMDE_FLOAT32_C(   492.72),
        SIMDE_FLOAT32_C(   597.40), SIMDE_FLOAT32_C(   253.75), SIMDE_FLOAT32_C(   616.90), SIMDE_FLOAT32_C(   108.68),
        SIMDE_FLOAT32_C(   217.16), SIMDE_FLOAT32_C(   439.38), SIMDE_FLOAT32_C(   724.30), SIMDE_FLOAT32_C(   474.66),
        SIMDE_FLOAT32_C(   870.80), SIMDE_FLOAT32_C(   -46.25), SIMDE_FLOAT32_C(  -743.93), SIMDE_FLOAT32_C(   176.79) },
      { SIMDE_FLOAT32_C(  -872.85), SIMDE_FLOAT32_C(   805.82), SIMDE_FLOAT32_C(   350.81), SIMDE_FLOAT32_C(  -515.94),
        SIMDE_FLOAT32_C(  -720.47), SIMDE_FLOAT32_C(   570.49), SIMDE_FLOAT32_C(   295.95), SIMDE_FLOAT32_C(   265.48),
        SIMDE_FLOAT32_C(   175.46), SIMDE_FLOAT32_C(  -217.20), SIMDE_FLOAT32_C(  -845.54), SIMDE_FLOAT32_C(   857.16),
        SIMDE_FLOAT32_C(   138.12), SIMDE_FLOAT32_C(  -599.93), SIMDE_FLOAT32_C(   503.35), SIMDE_FLOAT32_C(    52.57) },
      { SIMDE_FLOAT32_C(    41.60), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   389.61), SIMDE_FLOAT32_C(   -23.22),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   912.85), SIMDE_FLOAT32_C(   374.16),
        SIMDE_FLOAT32_C(   392.62), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -121.24), SIMDE_FLOAT32_C(  1331.82),
        SIMDE_FLOAT32_C(  1008.92), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
    { UINT16_C(26184),
      { SIMDE_FLOAT32_C(   601.56), SIMDE_FLOAT32_C(  -314.52), SIMDE_FLOAT32_C(  -512.28), SIMDE_FLOAT32_C(   472.36),
        SIMDE_FLOAT32_C(   639.23), SIMDE_FLOAT32_C(  -256.21), SIMDE_FLOAT32_C(  -350.85), SIMDE_FLOAT32_C(   766.38),
        SIMDE_FLOAT32_C(  -450.39), SIMDE_FLOAT32_C(   999.96), SIMDE_FLOAT32_C(  -749.56), SIMDE_FLOAT32_C(  -170.85),
        SIMDE_FLOAT32_C(   570.45), SIMDE_FLOAT32_C(   546.39), SIMDE_FLOAT32_C(  -905.38), SIMDE_FLOAT32_C(  -254.09) },
      { SIMDE_FLOAT32_C(  -670.81), SIMDE_FLOAT32_C(  -750.92), SIMDE_FLOAT32_C(  -396.93), SIMDE_FLOAT32_C(   467.31),
        SIMDE_FLOAT32_C(  -350.85), SIMDE_FLOAT32_C(  -893.58), SIMDE_FLOAT32_C(  -480.12), SIMDE_FLOAT32_C(   -95.76),
        SIMDE_FLOAT32_C(  -351.43), SIMDE_FLOAT32_C(    65.16), SIMDE_FLOAT32_C(  -243.28), SIMDE_FLOAT32_C(  -555.53),
        SIMDE_FLOAT32_C(   227.35), SIMDE_FLOAT32_C(   717.89), SIMDE_FLOAT32_C(   457.53), SIMDE_FLOAT32_C(  -171.09) },
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   939.67),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -830.97), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  1065.13), SIMDE_FLOAT32_C(  -992.84), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  1264.28), SIMDE_FLOAT32_C(  -447.85), SIMDE_FLOAT32_C(     0.00) } },
    { UINT16_C(38268),
      { SIMDE_FLOAT32_C(   -49.61), SIMDE_FLOAT32_C(  -940.59), SIMDE_FLOAT32_C(  -932.20), SIMDE_FLOAT32_C(  -479.16),
        SIMDE_FLOAT32_C(   605.80), SIMDE_FLOAT32_C(  -837.58), SIMDE_FLOAT32_C(   266.75), SIMDE_FLOAT32_C(   934.99),
        SIMDE_FLOAT32_C(  -588.49), SIMDE_FLOAT32_C(   869.82), SIMDE_FLOAT32_C(   402.30), SIMDE_FLOAT32_C(    60.66),
        SIMDE_FLOAT32_C(   976.24), SIMDE_FLOAT32_C(   922.17), SIMDE_FLOAT32_C(   964.89), SIMDE_FLOAT32_C(  -375.20) },
      { SIMDE_FLOAT32_C(   -12.67), SIMDE_FLOAT32_C(  -278.39), SIMDE_FLOAT32_C(    69.27), SIMDE_FLOAT32_C(  -785.32),
        SIMDE_FLOAT32_C(  -560.49), SIMDE_FLOAT32_C(  -473.20), SIMDE_FLOAT32_C(    43.59), SIMDE_FLOAT32_C(  -157.12),
        SIMDE_FLOAT32_C(  -527.94), SIMDE_FLOAT32_C(   344.87), SIMDE_FLOAT32_C(  -114.53), SIMDE_FLOAT32_C(   161.10),
        SIMDE_FLOAT32_C(  -704.71), SIMDE_FLOAT32_C(  -305.55), SIMDE_FLOAT32_C(  -600.24), SIMDE_FLOAT32_C(   245.68) },
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -862.92), SIMDE_FLOAT32_C( -1264.48),
        SIMDE_FLOAT32_C(    45.31), SIMDE_FLOAT32_C( -1310.77), SIMDE_FLOAT32_C(   310.34), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C( -1116.44), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   287.77), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(   271.52), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -129.52) } },
    { UINT16_C(37369),
      { SIMDE_FLOAT32_C(   -96.91), SIMDE_FLOAT32_C(   696.94), SIMDE_FLOAT32_C(  -897.85), SIMDE_FLOAT32_C(  -120.68),
        SIMDE_FLOAT32_C(   619.12), SIMDE_FLOAT32_C(  -932.96), SIMDE_FLOAT32_C(   504.13), SIMDE_FLOAT32_C(  -393.55),
        SIMDE_FLOAT32_C(  -211.35), SIMDE_FLOAT32_C(  -426.60), SIMDE_FLOAT32_C(  -178.87), SIMDE_FLOAT32_C(   228.16),
        SIMDE_FLOAT32_C(   100.20), SIMDE_FLOAT32_C(   864.72), SIMDE_FLOAT32_C(  -928.97), SIMDE_FLOAT32_C(   572.26) },
      { SIMDE_FLOAT32_C(   209.59), SIMDE_FLOAT32_C(   -43.49), SIMDE_FLOAT32_C(  -266.64), SIMDE_FLOAT32_C(   504.88),
        SIMDE_FLOAT32_C(   650.96), SIMDE_FLOAT32_C(   133.12), SIMDE_FLOAT32_C(  -249.44), SIMDE_FLOAT32_C(  -595.18),
        SIMDE_FLOAT32_C(   600.68), SIMDE_FLOAT32_C(  -482.93), SIMDE_FLOAT32_C(  -235.52), SIMDE_FLOAT32_C(  -769.33),
        SIMDE_FLOAT32_C(   550.34), SIMDE_FLOAT32_C(    59.13), SIMDE_FLOAT32_C(   272.16), SIMDE_FLOAT32_C(  -546.58) },
      { SIMDE_FLOAT32_C(   112.67), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   384.20),
        SIMDE_FLOAT32_C(  1270.07), SIMDE_FLOAT32_C(  -799.84), SIMDE_FLOAT32_C(   254.68), SIMDE_FLOAT32_C(  -988.73),
        SIMDE_FLOAT32_C(   389.33), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(   650.54), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(    25.68) } },
    { UINT16_C(17887),
      { SIMDE_FLOAT32_C(   410.27), SIMDE_FLOAT32_C(   802.77), SIMDE_FLOAT32_C(   458.15), SIMDE_FLOAT32_C(  -489.53),
        SIMDE_FLOAT32_C(   667.49), SIMDE_FLOAT32_C(   529.19), SIMDE_FLOAT32_C(  -917.27), SIMDE_FLOAT32_C(  -122.92),
        SIMDE_FLOAT32_C(  -514.30), SIMDE_FLOAT32_C(  -183.91), SIMDE_FLOAT32_C(  -618.04), SIMDE_FLOAT32_C(  -863.35),
        SIMDE_FLOAT32_C(   949.21), SIMDE_FLOAT32_C(   132.51), SIMDE_FLOAT32_C(  -458.53), SIMDE_FLOAT32_C(   549.89) },
      { SIMDE_FLOAT32_C(   649.59), SIMDE_FLOAT32_C(   305.95), SIMDE_FLOAT32_C(   780.56), SIMDE_FLOAT32_C(   199.92),
        SIMDE_FLOAT32_C(  -634.93), SIMDE_FLOAT32_C(    52.72), SIMDE_FLOAT32_C(   653.35), SIMDE_FLOAT32_C(   121.14),
        SIMDE_FLOAT32_C(  -572.98), SIMDE_FLOAT32_C(   -13.91), SIMDE_FLOAT32_C(   496.32), SIMDE_FLOAT32_C(   868.36),
        SIMDE_FLOAT32_C(   822.96), SIMDE_FLOAT32_C(  -522.04), SIMDE_FLOAT32_C(  -901.64), SIMDE_FLOAT32_C(   233.23) },
      { SIMDE_FLOAT32_C(  1059.85), SIMDE_FLOAT32_C(  1108.71), SIMDE_FLOAT32_C(  1238.71), SIMDE_FLOAT32_C(  -289.60),
        SIMDE_FLOAT32_C(    32.56), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -263.92), SIMDE_FLOAT32_C(    -1.78),
        SIMDE_FLOAT32_C( -1087.28), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -121.72), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C( -1360.17), SIMDE_FLOAT32_C(     0.00) } },
    { UINT16_C(52085),
      { SIMDE_FLOAT32_C(  -357.48), SIMDE_FLOAT32_C(   207.25), SIMDE_FLOAT32_C(   708.05), SIMDE_FLOAT32_C(  -408.26),
        SIMDE_FLOAT32_C(  -660.23), SIMDE_FLOAT32_C(  -750.48), SIMDE_FLOAT32_C(  -858.37), SIMDE_FLOAT32_C(   989.35),
        SIMDE_FLOAT32_C(   555.47), SIMDE_FLOAT32_C(   922.19), SIMDE_FLOAT32_C(   189.28), SIMDE_FLOAT32_C(   920.54),
        SIMDE_FLOAT32_C(   -25.09), SIMDE_FLOAT32_C(  -157.38), SIMDE_FLOAT32_C(    41.68), SIMDE_FLOAT32_C(   401.93) },
      { SIMDE_FLOAT32_C(   828.72), SIMDE_FLOAT32_C(  -462.00), SIMDE_FLOAT32_C(   270.29), SIMDE_FLOAT32_C(   651.68),
        SIMDE_FLOAT32_C(    15.96), SIMDE_FLOAT32_C(   368.65), SIMDE_FLOAT32_C(  -115.09), SIMDE_FLOAT32_C(   296.68),
        SIMDE_FLOAT32_C(   -74.83), SIMDE_FLOAT32_C(  -371.39), SIMDE_FLOAT32_C(   244.89), SIMDE_FLOAT32_C(  -989.13),
        SIMDE_FLOAT32_C(  -544.95), SIMDE_FLOAT32_C(  -929.81), SIMDE_FLOAT32_C(   582.27), SIMDE_FLOAT32_C(    97.57) },
      { SIMDE_FLOAT32_C(   471.24), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   978.34), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(  -644.28), SIMDE_FLOAT32_C(  -381.83), SIMDE_FLOAT32_C(  -973.46), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(   480.63), SIMDE_FLOAT32_C(   550.80), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   -68.59),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   623.95), SIMDE_FLOAT32_C(   499.50) } },
    { UINT16_C(30320),
      { SIMDE_FLOAT32_C(   753.13), SIMDE_FLOAT32_C(  -204.17), SIMDE_FLOAT32_C(    15.84), SIMDE_FLOAT32_C(  -271.97),
        SIMDE_FLOAT32_C(   638.45), SIMDE_FLOAT32_C(  -942.48), SIMDE_FLOAT32_C(  -870.04), SIMDE_FLOAT32_C(   467.17),
        SIMDE_FLOAT32_C(  -404.47), SIMDE_FLOAT32_C(   400.26), SIMDE_FLOAT32_C(   118.85), SIMDE_FLOAT32_C(   611.49),
        SIMDE_FLOAT32_C(  -231.09), SIMDE_FLOAT32_C(  -996.24), SIMDE_FLOAT32_C(   -91.83), SIMDE_FLOAT32_C(   694.08) },
      { SIMDE_FLOAT32_C(  -367.63), SIMDE_FLOAT32_C(  -846.94), SIMDE_FLOAT32_C(   704.95), SIMDE_FLOAT32_C(    87.42),
        SIMDE_FLOAT32_C(  -776.75), SIMDE_FLOAT32_C(   287.22), SIMDE_FLOAT32_C(  -815.01), SIMDE_FLOAT32_C(   500.69),
        SIMDE_FLOAT32_C(  -422.46), SIMDE_FLOAT32_C(   874.30), SIMDE_FLOAT32_C(   117.89), SIMDE_FLOAT32_C(  -882.62),
        SIMDE_FLOAT32_C(   705.23), SIMDE_FLOAT32_C(  -275.56), SIMDE_FLOAT32_C(   212.68), SIMDE_FLOAT32_C(   458.36) },
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(  -138.30), SIMDE_FLOAT32_C(  -655.26), SIMDE_FLOAT32_C( -1685.05), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  1274.55), SIMDE_FLOAT32_C(   236.74), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(   474.14), SIMDE_FLOAT32_C( -1271.80), SIMDE_FLOAT32_C(   120.85), SIMDE_FLOAT32_C(     0.00) } },
    { UINT16_C( 6201),
      { SIMDE_FLOAT32_C(   716.62), SIMDE_FLOAT32_C(   744.75), SIMDE_FLOAT32_C(  -506.94), SIMDE_FLOAT32_C(  -514.47),
        SIMDE_FLOAT32_C(   748.50), SIMDE_FLOAT32_C(   401.23), SIMDE_FLOAT32_C(  -820.39), SIMDE_FLOAT32_C(  -619.12),
        SIMDE_FLOAT32_C(   554.30), SIMDE_FLOAT32_C(   884.56), SIMDE_FLOAT32_C(   468.30), SIMDE_FLOAT32_C(   777.54),
        SIMDE_FLOAT32_C(   171.78), SIMDE_FLOAT32_C(   653.28), SIMDE_FLOAT32_C(   278.23), SIMDE_FLOAT32_C(   749.31) },
      { SIMDE_FLOAT32_C(   527.58), SIMDE_FLOAT32_C(  -603.88), SIMDE_FLOAT32_C(   866.69), SIMDE_FLOAT32_C(   232.81),
        SIMDE_FLOAT32_C(   120.56), SIMDE_FLOAT32_C(    79.37), SIMDE_FLOAT32_C(  -308.83), SIMDE_FLOAT32_C(  -359.16),
        SIMDE_FLOAT32_C(   307.90), SIMDE_FLOAT32_C(  -122.44), SIMDE_FLOAT32_C(   799.56), SIMDE_FLOAT32_C(   593.95),
        SIMDE_FLOAT32_C(   193.92), SIMDE_FLOAT32_C(  -574.54), SIMDE_FLOAT32_C(  -524.47), SIMDE_FLOAT32_C(   -89.46) },
      { SIMDE_FLOAT32_C(  1244.20), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -281.66),
        SIMDE_FLOAT32_C(   869.07), SIMDE_FLOAT32_C(   480.61), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  1371.50),
        SIMDE_FLOAT32_C(   365.70), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512 a = simde_mm512_loadu_ps(test_vec[i].a);
    simde__m512 b = simde_mm512_loadu_ps(test_vec[i].b);
    simde__m512 r = simde_mm512_maskz_add_ps(test_vec[i].k, a, b);
    simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[i].r), 1);
  }

  return 0;
}

static int
test_simde_mm512_add_pd (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const simde_float64 a[8];
    const simde_float64 b[8];
    const simde_float64 r[8];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(  -775.47), SIMDE_FLOAT64_C(     0.19), SIMDE_FLOAT64_C(  -757.09), SIMDE_FLOAT64_C(  -410.73),
        SIMDE_FLOAT64_C(  -780.15), SIMDE_FLOAT64_C(  -708.07), SIMDE_FLOAT64_C(   367.35), SIMDE_FLOAT64_C(  -968.32) },
      { SIMDE_FLOAT64_C(   820.33), SIMDE_FLOAT64_C(   850.82), SIMDE_FLOAT64_C(   596.13), SIMDE_FLOAT64_C(  -878.99),
        SIMDE_FLOAT64_C(  -603.61), SIMDE_FLOAT64_C(   533.64), SIMDE_FLOAT64_C(  -994.37), SIMDE_FLOAT64_C(   846.35) },
      { SIMDE_FLOAT64_C(    44.87), SIMDE_FLOAT64_C(   851.01), SIMDE_FLOAT64_C(  -160.96), SIMDE_FLOAT64_C( -1289.72),
        SIMDE_FLOAT64_C( -1383.75), SIMDE_FLOAT64_C(  -174.43), SIMDE_FLOAT64_C(  -627.02), SIMDE_FLOAT64_C(  -121.96) } },
    { { SIMDE_FLOAT64_C(  -503.42), SIMDE_FLOAT64_C(  -250.77), SIMDE_FLOAT64_C(  -532.42), SIMDE_FLOAT64_C(   815.06),
        SIMDE_FLOAT64_C(  -419.11), SIMDE_FLOAT64_C(   224.41), SIMDE_FLOAT64_C(   -34.26), SIMDE_FLOAT64_C(  -803.36) },
      { SIMDE_FLOAT64_C(  -331.10), SIMDE_FLOAT64_C(  -474.33), SIMDE_FLOAT64_C(   866.30), SIMDE_FLOAT64_C(   560.33),
        SIMDE_FLOAT64_C(   467.15), SIMDE_FLOAT64_C(   279.38), SIMDE_FLOAT64_C(  -475.96), SIMDE_FLOAT64_C(   691.69) },
      { SIMDE_FLOAT64_C(  -834.52), SIMDE_FLOAT64_C(  -725.11), SIMDE_FLOAT64_C(   333.88), SIMDE_FLOAT64_C(  1375.40),
        SIMDE_FLOAT64_C(    48.04), SIMDE_FLOAT64_C(   503.79), SIMDE_FLOAT64_C(  -510.22), SIMDE_FLOAT64_C(  -111.67) } },
    { { SIMDE_FLOAT64_C(  -720.44), SIMDE_FLOAT64_C(  -233.05), SIMDE_FLOAT64_C(  -719.04), SIMDE_FLOAT64_C(  -500.58),
        SIMDE_FLOAT64_C(    58.88), SIMDE_FLOAT64_C(   648.31), SIMDE_FLOAT64_C(  -468.90), SIMDE_FLOAT64_C(  -120.79) },
      { SIMDE_FLOAT64_C(   499.13), SIMDE_FLOAT64_C(  -872.76), SIMDE_FLOAT64_C(     0.22), SIMDE_FLOAT64_C(   895.52),
        SIMDE_FLOAT64_C(   660.88), SIMDE_FLOAT64_C(     5.85), SIMDE_FLOAT64_C(   741.88), SIMDE_FLOAT64_C(  -842.54) },
      { SIMDE_FLOAT64_C(  -221.31), SIMDE_FLOAT64_C( -1105.81), SIMDE_FLOAT64_C(  -718.83), SIMDE_FLOAT64_C(   394.94),
        SIMDE_FLOAT64_C(   719.76), SIMDE_FLOAT64_C(   654.16), SIMDE_FLOAT64_C(   272.98), SIMDE_FLOAT64_C(  -963.33) } },
    { { SIMDE_FLOAT64_C(   755.08), SIMDE_FLOAT64_C(  -790.54), SIMDE_FLOAT64_C(   972.53), SIMDE_FLOAT64_C(  -664.03),
        SIMDE_FLOAT64_C(   433.87), SIMDE_FLOAT64_C(   -61.74), SIMDE_FLOAT64_C(  -467.39), SIMDE_FLOAT64_C(  -897.23) },
      { SIMDE_FLOAT64_C(   463.93), SIMDE_FLOAT64_C(  -601.09), SIMDE_FLOAT64_C(   663.10), SIMDE_FLOAT64_C(   -68.92),
        SIMDE_FLOAT64_C(   678.29), SIMDE_FLOAT64_C(  -812.86), SIMDE_FLOAT64_C(  -377.23), SIMDE_FLOAT64_C(   957.85) },
      { SIMDE_FLOAT64_C(  1219.01), SIMDE_FLOAT64_C( -1391.63), SIMDE_FLOAT64_C(  1635.63), SIMDE_FLOAT64_C(  -732.95),
        SIMDE_FLOAT64_C(  1112.16), SIMDE_FLOAT64_C(  -874.59), SIMDE_FLOAT64_C(  -844.62), SIMDE_FLOAT64_C(    60.62) } },
    { { SIMDE_FLOAT64_C(   -45.90), SIMDE_FLOAT64_C(   -96.28), SIMDE_FLOAT64_C(  -542.73), SIMDE_FLOAT64_C(  -987.02),
        SIMDE_FLOAT64_C(  -447.97), SIMDE_FLOAT64_C(   -11.63), SIMDE_FLOAT64_C(  -107.82), SIMDE_FLOAT64_C(  -948.84) },
      { SIMDE_FLOAT64_C(   115.60), SIMDE_FLOAT64_C(   892.40), SIMDE_FLOAT64_C(   946.68), SIMDE_FLOAT64_C(  -223.52),
        SIMDE_FLOAT64_C(  -101.75), SIMDE_FLOAT64_C(   688.56), SIMDE_FLOAT64_C(   -66.05), SIMDE_FLOAT64_C(  -346.67) },
      { SIMDE_FLOAT64_C(    69.70), SIMDE_FLOAT64_C(   796.12), SIMDE_FLOAT64_C(   403.95), SIMDE_FLOAT64_C( -1210.54),
        SIMDE_FLOAT64_C(  -549.72), SIMDE_FLOAT64_C(   676.92), SIMDE_FLOAT64_C(  -173.87), SIMDE_FLOAT64_C( -1295.52) } },
    { { SIMDE_FLOAT64_C(   898.01), SIMDE_FLOAT64_C(   -93.53), SIMDE_FLOAT64_C(   -10.70), SIMDE_FLOAT64_C(   331.89),
        SIMDE_FLOAT64_C(   844.74), SIMDE_FLOAT64_C(   521.91), SIMDE_FLOAT64_C(   434.66), SIMDE_FLOAT64_C(   308.66) },
      { SIMDE_FLOAT64_C(   920.82), SIMDE_FLOAT64_C(    97.76), SIMDE_FLOAT64_C(  -760.25), SIMDE_FLOAT64_C(   599.10),
        SIMDE_FLOAT64_C(   284.91), SIMDE_FLOAT64_C(  -137.49), SIMDE_FLOAT64_C(   556.96), SIMDE_FLOAT64_C(  -761.00) },
      { SIMDE_FLOAT64_C(  1818.83), SIMDE_FLOAT64_C(     4.23), SIMDE_FLOAT64_C(  -770.96), SIMDE_FLOAT64_C(   930.99),
        SIMDE_FLOAT64_C(  1129.64), SIMDE_FLOAT64_C(   384.42), SIMDE_FLOAT64_C(   991.61), SIMDE_FLOAT64_C(  -452.33) } },
    { { SIMDE_FLOAT64_C(   766.23), SIMDE_FLOAT64_C(  -985.78), SIMDE_FLOAT64_C(  -748.02), SIMDE_FLOAT64_C(  -681.74),
        SIMDE_FLOAT64_C(     2.59), SIMDE_FLOAT64_C(   144.16), SIMDE_FLOAT64_C(  -630.58), SIMDE_FLOAT64_C(  -881.80) },
      { SIMDE_FLOAT64_C(    36.57), SIMDE_FLOAT64_C(  -683.90), SIMDE_FLOAT64_C(  -105.32), SIMDE_FLOAT64_C(   934.82),
        SIMDE_FLOAT64_C(  -995.35), SIMDE_FLOAT64_C(   828.63), SIMDE_FLOAT64_C(  -411.86), SIMDE_FLOAT64_C(   902.67) },
      { SIMDE_FLOAT64_C(   802.80), SIMDE_FLOAT64_C( -1669.68), SIMDE_FLOAT64_C(  -853.34), SIMDE_FLOAT64_C(   253.08),
        SIMDE_FLOAT64_C(  -992.76), SIMDE_FLOAT64_C(   972.79), SIMDE_FLOAT64_C( -1042.44), SIMDE_FLOAT64_C(    20.86) } },
    { { SIMDE_FLOAT64_C(  -264.90), SIMDE_FLOAT64_C(   577.44), SIMDE_FLOAT64_C(   234.56), SIMDE_FLOAT64_C(  -420.17),
        SIMDE_FLOAT64_C(    99.35), SIMDE_FLOAT64_C(  -330.78), SIMDE_FLOAT64_C(   888.50), SIMDE_FLOAT64_C(    20.17) },
      { SIMDE_FLOAT64_C(   766.98), SIMDE_FLOAT64_C(  -871.76), SIMDE_FLOAT64_C(  -380.73), SIMDE_FLOAT64_C(    51.88),
        SIMDE_FLOAT64_C(    -9.24), SIMDE_FLOAT64_C(  -823.77), SIMDE_FLOAT64_C(   290.89), SIMDE_FLOAT64_C(  -243.01) },
      { SIMDE_FLOAT64_C(   502.08), SIMDE_FLOAT64_C(  -294.31), SIMDE_FLOAT64_C(  -146.17), SIMDE_FLOAT64_C(  -368.28),
        SIMDE_FLOAT64_C(    90.11), SIMDE_FLOAT64_C( -1154.55), SIMDE_FLOAT64_C(  1179.39), SIMDE_FLOAT64_C(  -222.84) } }
  };


  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512d a = simde_mm512_loadu_pd(test_vec[i].a);
    simde__m512d b = simde_mm512_loadu_pd(test_vec[i].b);
    simde__m512d r = simde_mm512_add_pd(a, b);
    simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[i].r), 1);
  }

  return 0;
}

static int
test_simde_mm512_mask_add_pd (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const simde_float64 src[8];
    const simde__mmask8 k;
    const simde_float64 a[8];
    const simde_float64 b[8];
    const simde_float64 r[8];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(  -241.95), SIMDE_FLOAT64_C(   348.31), SIMDE_FLOAT64_C(  -125.04), SIMDE_FLOAT64_C(  -245.69),
        SIMDE_FLOAT64_C(  -588.93), SIMDE_FLOAT64_C(  -276.58), SIMDE_FLOAT64_C(  -867.91), SIMDE_FLOAT64_C(   -10.44) },
      UINT8_C( 17),
      { SIMDE_FLOAT64_C(   296.41), SIMDE_FLOAT64_C(  -576.00), SIMDE_FLOAT64_C(   367.45), SIMDE_FLOAT64_C(  -294.17),
        SIMDE_FLOAT64_C(  -916.48), SIMDE_FLOAT64_C(   266.60), SIMDE_FLOAT64_C(   288.43), SIMDE_FLOAT64_C(   471.22) },
      { SIMDE_FLOAT64_C(  -995.36), SIMDE_FLOAT64_C(   468.56), SIMDE_FLOAT64_C(    50.02), SIMDE_FLOAT64_C(   -51.51),
        SIMDE_FLOAT64_C(   997.69), SIMDE_FLOAT64_C(   806.19), SIMDE_FLOAT64_C(  -145.36), SIMDE_FLOAT64_C(   877.33) },
      { SIMDE_FLOAT64_C(  -698.96), SIMDE_FLOAT64_C(   348.31), SIMDE_FLOAT64_C(  -125.04), SIMDE_FLOAT64_C(  -245.69),
        SIMDE_FLOAT64_C(    81.21), SIMDE_FLOAT64_C(  -276.58), SIMDE_FLOAT64_C(  -867.91), SIMDE_FLOAT64_C(   -10.44) } },
    { { SIMDE_FLOAT64_C(  -303.10), SIMDE_FLOAT64_C(  -675.79), SIMDE_FLOAT64_C(   770.76), SIMDE_FLOAT64_C(   600.76),
        SIMDE_FLOAT64_C(  -105.79), SIMDE_FLOAT64_C(  -257.88), SIMDE_FLOAT64_C(  -641.18), SIMDE_FLOAT64_C(  -757.48) },
      UINT8_C(183),
      { SIMDE_FLOAT64_C(   113.13), SIMDE_FLOAT64_C(  -346.41), SIMDE_FLOAT64_C(  -659.51), SIMDE_FLOAT64_C(   245.22),
        SIMDE_FLOAT64_C(   643.14), SIMDE_FLOAT64_C(    43.25), SIMDE_FLOAT64_C(  -458.37), SIMDE_FLOAT64_C(  -932.86) },
      { SIMDE_FLOAT64_C(  -589.30), SIMDE_FLOAT64_C(   247.46), SIMDE_FLOAT64_C(  -849.33), SIMDE_FLOAT64_C(   677.31),
        SIMDE_FLOAT64_C(  -464.11), SIMDE_FLOAT64_C(   621.89), SIMDE_FLOAT64_C(   681.94), SIMDE_FLOAT64_C(  -995.54) },
      { SIMDE_FLOAT64_C(  -476.17), SIMDE_FLOAT64_C(   -98.95), SIMDE_FLOAT64_C( -1508.84), SIMDE_FLOAT64_C(   600.76),
        SIMDE_FLOAT64_C(   179.04), SIMDE_FLOAT64_C(   665.14), SIMDE_FLOAT64_C(  -641.18), SIMDE_FLOAT64_C( -1928.40) } },
    { { SIMDE_FLOAT64_C(  -328.10), SIMDE_FLOAT64_C(  -369.57), SIMDE_FLOAT64_C(  -997.86), SIMDE_FLOAT64_C(  -521.91),
        SIMDE_FLOAT64_C(   485.07), SIMDE_FLOAT64_C(   879.48), SIMDE_FLOAT64_C(   175.00), SIMDE_FLOAT64_C(   809.28) },
      UINT8_C( 91),
      { SIMDE_FLOAT64_C(  -224.24), SIMDE_FLOAT64_C(  -296.51), SIMDE_FLOAT64_C(  -607.64), SIMDE_FLOAT64_C(   134.57),
        SIMDE_FLOAT64_C(   -53.99), SIMDE_FLOAT64_C(  -990.57), SIMDE_FLOAT64_C(  -752.30), SIMDE_FLOAT64_C(   599.60) },
      { SIMDE_FLOAT64_C(  -650.08), SIMDE_FLOAT64_C(   492.93), SIMDE_FLOAT64_C(   242.74), SIMDE_FLOAT64_C(   393.17),
        SIMDE_FLOAT64_C(  -965.44), SIMDE_FLOAT64_C(   309.89), SIMDE_FLOAT64_C(   803.88), SIMDE_FLOAT64_C(   282.02) },
      { SIMDE_FLOAT64_C(  -874.32), SIMDE_FLOAT64_C(   196.42), SIMDE_FLOAT64_C(  -997.86), SIMDE_FLOAT64_C(   527.75),
        SIMDE_FLOAT64_C( -1019.43), SIMDE_FLOAT64_C(   879.48), SIMDE_FLOAT64_C(    51.58), SIMDE_FLOAT64_C(   809.28) } },
    { { SIMDE_FLOAT64_C(   460.56), SIMDE_FLOAT64_C(   481.18), SIMDE_FLOAT64_C(   817.91), SIMDE_FLOAT64_C(    82.44),
        SIMDE_FLOAT64_C(   163.12), SIMDE_FLOAT64_C(   822.36), SIMDE_FLOAT64_C(   754.35), SIMDE_FLOAT64_C(   793.56) },
      UINT8_C( 35),
      { SIMDE_FLOAT64_C(  -767.56), SIMDE_FLOAT64_C(   278.63), SIMDE_FLOAT64_C(   703.98), SIMDE_FLOAT64_C(   407.44),
        SIMDE_FLOAT64_C(    87.91), SIMDE_FLOAT64_C(   354.22), SIMDE_FLOAT64_C(  -816.81), SIMDE_FLOAT64_C(   791.41) },
      { SIMDE_FLOAT64_C(   746.58), SIMDE_FLOAT64_C(   317.77), SIMDE_FLOAT64_C(  -262.58), SIMDE_FLOAT64_C(   756.01),
        SIMDE_FLOAT64_C(   565.47), SIMDE_FLOAT64_C(  -662.99), SIMDE_FLOAT64_C(  -894.07), SIMDE_FLOAT64_C(    58.40) },
      { SIMDE_FLOAT64_C(   -20.98), SIMDE_FLOAT64_C(   596.40), SIMDE_FLOAT64_C(   817.91), SIMDE_FLOAT64_C(    82.44),
        SIMDE_FLOAT64_C(   163.12), SIMDE_FLOAT64_C(  -308.76), SIMDE_FLOAT64_C(   754.35), SIMDE_FLOAT64_C(   793.56) } },
    { { SIMDE_FLOAT64_C(   579.76), SIMDE_FLOAT64_C(   499.11), SIMDE_FLOAT64_C(    92.96), SIMDE_FLOAT64_C(  -110.35),
        SIMDE_FLOAT64_C(   302.99), SIMDE_FLOAT64_C(  -625.02), SIMDE_FLOAT64_C(  -649.80), SIMDE_FLOAT64_C(  -215.83) },
      UINT8_C(  3),
      { SIMDE_FLOAT64_C(   432.65), SIMDE_FLOAT64_C(   947.29), SIMDE_FLOAT64_C(  -984.75), SIMDE_FLOAT64_C(   186.99),
        SIMDE_FLOAT64_C(   740.85), SIMDE_FLOAT64_C(   839.76), SIMDE_FLOAT64_C(   419.43), SIMDE_FLOAT64_C(    19.48) },
      { SIMDE_FLOAT64_C(   543.74), SIMDE_FLOAT64_C(  -173.13), SIMDE_FLOAT64_C(  -892.61), SIMDE_FLOAT64_C(  -102.04),
        SIMDE_FLOAT64_C(    10.06), SIMDE_FLOAT64_C(   898.80), SIMDE_FLOAT64_C(  -355.45), SIMDE_FLOAT64_C(  -672.17) },
      { SIMDE_FLOAT64_C(   976.39), SIMDE_FLOAT64_C(   774.16), SIMDE_FLOAT64_C(    92.96), SIMDE_FLOAT64_C(  -110.35),
        SIMDE_FLOAT64_C(   302.99), SIMDE_FLOAT64_C(  -625.02), SIMDE_FLOAT64_C(  -649.80), SIMDE_FLOAT64_C(  -215.83) } },
    { { SIMDE_FLOAT64_C(  -363.79), SIMDE_FLOAT64_C(  -599.44), SIMDE_FLOAT64_C(   893.30), SIMDE_FLOAT64_C(   -26.77),
        SIMDE_FLOAT64_C(  -493.51), SIMDE_FLOAT64_C(   -48.30), SIMDE_FLOAT64_C(  -447.01), SIMDE_FLOAT64_C(  -994.40) },
      UINT8_C( 89),
      { SIMDE_FLOAT64_C(   442.63), SIMDE_FLOAT64_C(   308.59), SIMDE_FLOAT64_C(  -580.36), SIMDE_FLOAT64_C(   792.84),
        SIMDE_FLOAT64_C(  -907.24), SIMDE_FLOAT64_C(  -387.48), SIMDE_FLOAT64_C(   225.48), SIMDE_FLOAT64_C(  -959.95) },
      { SIMDE_FLOAT64_C(  -372.23), SIMDE_FLOAT64_C(  -587.52), SIMDE_FLOAT64_C(   780.90), SIMDE_FLOAT64_C(  -532.47),
        SIMDE_FLOAT64_C(   831.91), SIMDE_FLOAT64_C(  -199.62), SIMDE_FLOAT64_C(  -988.73), SIMDE_FLOAT64_C(  -341.22) },
      { SIMDE_FLOAT64_C(    70.40), SIMDE_FLOAT64_C(  -599.44), SIMDE_FLOAT64_C(   893.30), SIMDE_FLOAT64_C(   260.36),
        SIMDE_FLOAT64_C(   -75.33), SIMDE_FLOAT64_C(   -48.30), SIMDE_FLOAT64_C(  -763.25), SIMDE_FLOAT64_C(  -994.40) } },
    { { SIMDE_FLOAT64_C(   -92.23), SIMDE_FLOAT64_C(   -90.77), SIMDE_FLOAT64_C(   668.84), SIMDE_FLOAT64_C(  -193.43),
        SIMDE_FLOAT64_C(   553.78), SIMDE_FLOAT64_C(   996.67), SIMDE_FLOAT64_C(   442.78), SIMDE_FLOAT64_C(   954.34) },
      UINT8_C(200),
      { SIMDE_FLOAT64_C(  -583.99), SIMDE_FLOAT64_C(  -539.17), SIMDE_FLOAT64_C(  -158.32), SIMDE_FLOAT64_C(   -31.00),
        SIMDE_FLOAT64_C(  -533.56), SIMDE_FLOAT64_C(  -113.65), SIMDE_FLOAT64_C(  -588.37), SIMDE_FLOAT64_C(   775.02) },
      { SIMDE_FLOAT64_C(   305.99), SIMDE_FLOAT64_C(  -795.53), SIMDE_FLOAT64_C(   867.78), SIMDE_FLOAT64_C(   918.51),
        SIMDE_FLOAT64_C(   429.95), SIMDE_FLOAT64_C(   907.83), SIMDE_FLOAT64_C(  -453.72), SIMDE_FLOAT64_C(   842.43) },
      { SIMDE_FLOAT64_C(   -92.23), SIMDE_FLOAT64_C(   -90.77), SIMDE_FLOAT64_C(   668.84), SIMDE_FLOAT64_C(   887.51),
        SIMDE_FLOAT64_C(   553.78), SIMDE_FLOAT64_C(   996.67), SIMDE_FLOAT64_C( -1042.09), SIMDE_FLOAT64_C(  1617.45) } },
    { { SIMDE_FLOAT64_C(   688.73), SIMDE_FLOAT64_C(    13.81), SIMDE_FLOAT64_C(   674.34), SIMDE_FLOAT64_C(  -510.89),
        SIMDE_FLOAT64_C(    25.08), SIMDE_FLOAT64_C(  -666.88), SIMDE_FLOAT64_C(   396.88), SIMDE_FLOAT64_C(   934.31) },
      UINT8_C(155),
      { SIMDE_FLOAT64_C(  -796.55), SIMDE_FLOAT64_C(   488.09), SIMDE_FLOAT64_C(   998.63), SIMDE_FLOAT64_C(   646.24),
        SIMDE_FLOAT64_C(   442.43), SIMDE_FLOAT64_C(   888.61), SIMDE_FLOAT64_C(  -937.75), SIMDE_FLOAT64_C(   903.26) },
      { SIMDE_FLOAT64_C(  -269.71), SIMDE_FLOAT64_C(    31.25), SIMDE_FLOAT64_C(  -630.30), SIMDE_FLOAT64_C(   616.64),
        SIMDE_FLOAT64_C(   442.88), SIMDE_FLOAT64_C(  -855.28), SIMDE_FLOAT64_C(   -77.38), SIMDE_FLOAT64_C(   647.35) },
      { SIMDE_FLOAT64_C( -1066.26), SIMDE_FLOAT64_C(   519.34), SIMDE_FLOAT64_C(   674.34), SIMDE_FLOAT64_C(  1262.87),
        SIMDE_FLOAT64_C(   885.31), SIMDE_FLOAT64_C(  -666.88), SIMDE_FLOAT64_C(   396.88), SIMDE_FLOAT64_C(  1550.61) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512d src = simde_mm512_loadu_pd(test_vec[i].src);
    simde__m512d a = simde_mm512_loadu_pd(test_vec[i].a);
    simde__m512d b = simde_mm512_loadu_pd(test_vec[i].b);
    simde__m512d r = simde_mm512_mask_add_pd(src, test_vec[i].k, a, b);
    simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[i].r), 1);
  }

  return 0;
}

static int
test_simde_mm512_maskz_add_pd (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const simde__mmask8 k;
    const simde_float64 a[8];
    const simde_float64 b[8];
    const simde_float64 r[8];
  } test_vec[] = {
    { UINT8_C(141),
      { SIMDE_FLOAT64_C(   539.39), SIMDE_FLOAT64_C(   127.65), SIMDE_FLOAT64_C(  -419.83), SIMDE_FLOAT64_C(  -509.25),
        SIMDE_FLOAT64_C(   614.81), SIMDE_FLOAT64_C(  -356.87), SIMDE_FLOAT64_C(  -437.81), SIMDE_FLOAT64_C(   217.95) },
      { SIMDE_FLOAT64_C(   -60.15), SIMDE_FLOAT64_C(  -699.30), SIMDE_FLOAT64_C(   963.74), SIMDE_FLOAT64_C(   851.36),
        SIMDE_FLOAT64_C(   773.07), SIMDE_FLOAT64_C(  -457.96), SIMDE_FLOAT64_C(  -310.92), SIMDE_FLOAT64_C(   852.62) },
      { SIMDE_FLOAT64_C(   479.24), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(   543.91), SIMDE_FLOAT64_C(   342.11),
        SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(  1070.58) } },
    { UINT8_C(123),
      { SIMDE_FLOAT64_C(   902.15), SIMDE_FLOAT64_C(   661.09), SIMDE_FLOAT64_C(  -493.90), SIMDE_FLOAT64_C(   433.62),
        SIMDE_FLOAT64_C(  -884.72), SIMDE_FLOAT64_C(  -690.47), SIMDE_FLOAT64_C(  -391.44), SIMDE_FLOAT64_C(   -97.69) },
      { SIMDE_FLOAT64_C(  -732.29), SIMDE_FLOAT64_C(   446.84), SIMDE_FLOAT64_C(  -990.19), SIMDE_FLOAT64_C(   216.62),
        SIMDE_FLOAT64_C(  -720.09), SIMDE_FLOAT64_C(    35.61), SIMDE_FLOAT64_C(  -243.99), SIMDE_FLOAT64_C(   407.56) },
      { SIMDE_FLOAT64_C(   169.86), SIMDE_FLOAT64_C(  1107.93), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(   650.24),
        SIMDE_FLOAT64_C( -1604.81), SIMDE_FLOAT64_C(  -654.86), SIMDE_FLOAT64_C(  -635.42), SIMDE_FLOAT64_C(     0.00) } },
    { UINT8_C(175),
      { SIMDE_FLOAT64_C(   246.76), SIMDE_FLOAT64_C(    22.37), SIMDE_FLOAT64_C(  -741.09), SIMDE_FLOAT64_C(   808.94),
        SIMDE_FLOAT64_C(  -759.68), SIMDE_FLOAT64_C(   198.75), SIMDE_FLOAT64_C(  -890.36), SIMDE_FLOAT64_C(  -795.93) },
      { SIMDE_FLOAT64_C(    50.12), SIMDE_FLOAT64_C(   882.71), SIMDE_FLOAT64_C(  -253.90), SIMDE_FLOAT64_C(   739.19),
        SIMDE_FLOAT64_C(   735.33), SIMDE_FLOAT64_C(   572.27), SIMDE_FLOAT64_C(   641.34), SIMDE_FLOAT64_C(   396.42) },
      { SIMDE_FLOAT64_C(   296.87), SIMDE_FLOAT64_C(   905.08), SIMDE_FLOAT64_C(  -994.99), SIMDE_FLOAT64_C(  1548.14),
        SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(   771.02), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(  -399.51) } },
    { UINT8_C( 10),
      { SIMDE_FLOAT64_C(    74.96), SIMDE_FLOAT64_C(   511.70), SIMDE_FLOAT64_C(  -612.10), SIMDE_FLOAT64_C(   683.53),
        SIMDE_FLOAT64_C(  -585.99), SIMDE_FLOAT64_C(  -344.39), SIMDE_FLOAT64_C(   130.37), SIMDE_FLOAT64_C(  -576.18) },
      { SIMDE_FLOAT64_C(   872.23), SIMDE_FLOAT64_C(   410.28), SIMDE_FLOAT64_C(   459.43), SIMDE_FLOAT64_C(  -371.75),
        SIMDE_FLOAT64_C(  -182.16), SIMDE_FLOAT64_C(    75.20), SIMDE_FLOAT64_C(   875.00), SIMDE_FLOAT64_C(   840.21) },
      { SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(   921.98), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(   311.77),
        SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00) } },
    { UINT8_C( 10),
      { SIMDE_FLOAT64_C(   683.95), SIMDE_FLOAT64_C(  -919.47), SIMDE_FLOAT64_C(  -467.14), SIMDE_FLOAT64_C(   793.59),
        SIMDE_FLOAT64_C(  -715.40), SIMDE_FLOAT64_C(   582.98), SIMDE_FLOAT64_C(   676.29), SIMDE_FLOAT64_C(    30.70) },
      { SIMDE_FLOAT64_C(   322.17), SIMDE_FLOAT64_C(   411.62), SIMDE_FLOAT64_C(  -397.03), SIMDE_FLOAT64_C(   -36.48),
        SIMDE_FLOAT64_C(  -191.96), SIMDE_FLOAT64_C(  -318.66), SIMDE_FLOAT64_C(  -961.52), SIMDE_FLOAT64_C(  -680.25) },
      { SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(  -507.84), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(   757.10),
        SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00) } },
    { UINT8_C(199),
      { SIMDE_FLOAT64_C(   722.01), SIMDE_FLOAT64_C(  -266.24), SIMDE_FLOAT64_C(   724.85), SIMDE_FLOAT64_C(  -147.62),
        SIMDE_FLOAT64_C(   157.58), SIMDE_FLOAT64_C(   597.08), SIMDE_FLOAT64_C(  -737.35), SIMDE_FLOAT64_C(  -383.00) },
      { SIMDE_FLOAT64_C(  -774.68), SIMDE_FLOAT64_C(    80.49), SIMDE_FLOAT64_C(   692.21), SIMDE_FLOAT64_C(  -899.67),
        SIMDE_FLOAT64_C(   -79.30), SIMDE_FLOAT64_C(    26.32), SIMDE_FLOAT64_C(   784.27), SIMDE_FLOAT64_C(     1.24) },
      { SIMDE_FLOAT64_C(   -52.67), SIMDE_FLOAT64_C(  -185.75), SIMDE_FLOAT64_C(  1417.06), SIMDE_FLOAT64_C(     0.00),
        SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(    46.93), SIMDE_FLOAT64_C(  -381.76) } },
    { UINT8_C(108),
      { SIMDE_FLOAT64_C(   577.86), SIMDE_FLOAT64_C(   285.84), SIMDE_FLOAT64_C(   142.16), SIMDE_FLOAT64_C(   254.16),
        SIMDE_FLOAT64_C(  -683.46), SIMDE_FLOAT64_C(  -535.67), SIMDE_FLOAT64_C(  -334.22), SIMDE_FLOAT64_C(   -80.49) },
      { SIMDE_FLOAT64_C(   427.85), SIMDE_FLOAT64_C(   473.82), SIMDE_FLOAT64_C(   600.85), SIMDE_FLOAT64_C(   466.33),
        SIMDE_FLOAT64_C(   793.57), SIMDE_FLOAT64_C(  -329.91), SIMDE_FLOAT64_C(   188.34), SIMDE_FLOAT64_C(  -472.67) },
      { SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(   743.02), SIMDE_FLOAT64_C(   720.48),
        SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(  -865.57), SIMDE_FLOAT64_C(  -145.89), SIMDE_FLOAT64_C(     0.00) } },
    { UINT8_C( 48),
      { SIMDE_FLOAT64_C(  -959.29), SIMDE_FLOAT64_C(   684.90), SIMDE_FLOAT64_C(   992.02), SIMDE_FLOAT64_C(  -696.63),
        SIMDE_FLOAT64_C(  -698.09), SIMDE_FLOAT64_C(  -782.66), SIMDE_FLOAT64_C(   383.86), SIMDE_FLOAT64_C(   994.11) },
      { SIMDE_FLOAT64_C(  -682.33), SIMDE_FLOAT64_C(  -695.44), SIMDE_FLOAT64_C(    20.43), SIMDE_FLOAT64_C(  -898.06),
        SIMDE_FLOAT64_C(   305.80), SIMDE_FLOAT64_C(  -420.39), SIMDE_FLOAT64_C(   679.80), SIMDE_FLOAT64_C(  -408.37) },
      { SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00),
        SIMDE_FLOAT64_C(  -392.30), SIMDE_FLOAT64_C( -1203.04), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512d a = simde_mm512_loadu_pd(test_vec[i].a);
    simde__m512d b = simde_mm512_loadu_pd(test_vec[i].b);
    simde__m512d r = simde_mm512_maskz_add_pd(test_vec[i].k, a, b);
    #if defined(__EMSCRIPTEN__)
    (void) r;
    #else
    simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[i].r), 1);
    #endif
  }

  return 0;
}

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_mask_add_epi8)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_maskz_add_epi8)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_mask_add_epi16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_maskz_add_epi16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_mask_add_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_maskz_add_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_mask_add_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_maskz_add_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_mask_add_ss)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_maskz_add_ss)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_mask_add_epi16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_maskz_add_epi16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_mask_add_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_maskz_add_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_mask_add_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_maskz_add_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_add_epi8)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_add_epi8)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_maskz_add_epi8)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_add_epi16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_add_epi16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_maskz_add_epi16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_add_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_add_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_maskz_add_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_add_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_add_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_maskz_add_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_add_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_add_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_maskz_add_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_add_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_add_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_maskz_add_pd)
SIMDE_TEST_FUNC_LIST_END

#include <test/x86/avx512/test-avx512-footer.h>
