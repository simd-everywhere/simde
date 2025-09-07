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

#define SIMDE_TEST_X86_AVX512_INSN expandloadu

#include <test/x86/avx512/test-avx512.h>
#include <simde/x86/avx512/set.h>
#include <simde/x86/avx512/expandloadu.h>

/* The test vectors are from simde/x86/avx512/expand.h */

static int
test_simde_mm_mask_expandloadu_epi8 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const int8_t src[16];
    const simde__mmask16 k;
    SIMDE_ALIGN_LIKE_64(simde__m128i) const int8_t mem_addr[16];
    const int8_t r[16];
  } test_vec[] = {
    { {      INT8_MIN, -INT8_C( 121),  INT8_C(  60), -INT8_C(  74), -INT8_C( 107),  INT8_C(   9), -INT8_C(   8),  INT8_C( 108),
         INT8_C(  48), -INT8_C(  48), -INT8_C(  53),  INT8_C(  19),  INT8_C(  83), -INT8_C(  97), -INT8_C(  78), -INT8_C( 112) },
      UINT16_C(15966),
      { -INT8_C(  20),  INT8_C(  67), -INT8_C( 104), -INT8_C(   1),  INT8_C( 119),  INT8_C(  49), -INT8_C(  21), -INT8_C(  11),
        -INT8_C(  60),  INT8_C(  32),  INT8_C(   8), -INT8_C(  11), -INT8_C(  32), -INT8_C( 120),  INT8_C( 124),  INT8_C(  28) },
      {      INT8_MIN, -INT8_C(  20),  INT8_C(  67), -INT8_C( 104), -INT8_C(   1),  INT8_C(   9),  INT8_C( 119),  INT8_C( 108),
         INT8_C(  48),  INT8_C(  49), -INT8_C(  21), -INT8_C(  11), -INT8_C(  60),  INT8_C(  32), -INT8_C(  78), -INT8_C( 112) } },
    { {  INT8_C(  62),  INT8_C(  17),  INT8_C(  38),  INT8_C(  54),  INT8_C( 125),  INT8_C(  86),  INT8_C(   6),  INT8_C(  72),
         INT8_C( 105),  INT8_C(  90), -INT8_C(  24),  INT8_C(  27), -INT8_C(  22),  INT8_C(  70),  INT8_C(  90), -INT8_C(  42) },
      UINT16_C(62089),
      { -INT8_C(  42),  INT8_C(   1),  INT8_C(  35), -INT8_C(  63), -INT8_C(  10), -INT8_C(  24), -INT8_C(  31), -INT8_C(   2),
        -INT8_C(  35), -INT8_C(  63), -INT8_C( 122),  INT8_C(  89), -INT8_C(  34), -INT8_C(  60),  INT8_C( 106),  INT8_C(   4) },
      { -INT8_C(  42),  INT8_C(  17),  INT8_C(  38),  INT8_C(   1),  INT8_C( 125),  INT8_C(  86),  INT8_C(   6),  INT8_C(  35),
         INT8_C( 105), -INT8_C(  63), -INT8_C(  24),  INT8_C(  27), -INT8_C(  10), -INT8_C(  24), -INT8_C(  31), -INT8_C(   2) } },
    { { -INT8_C(   6), -INT8_C(  25),  INT8_C(  90),  INT8_C(   1),  INT8_C(  48), -INT8_C(  60),  INT8_C(  91),  INT8_C(  24),
        -INT8_C(  33),  INT8_C(  69),  INT8_C(  94),  INT8_C(  57),  INT8_C(  27), -INT8_C(  25),  INT8_C(  43), -INT8_C(  15) },
      UINT16_C(20456),
      { -INT8_C(  77), -INT8_C(  33),  INT8_C(  55), -INT8_C( 108), -INT8_C(  35),  INT8_C(  20),  INT8_C(  86),  INT8_C( 100),
         INT8_C( 109),  INT8_C(  52),  INT8_C(  40), -INT8_C(  41),  INT8_C(  56),  INT8_C(  35), -INT8_C(  66), -INT8_C( 110) },
      { -INT8_C(   6), -INT8_C(  25),  INT8_C(  90), -INT8_C(  77),  INT8_C(  48), -INT8_C(  33),  INT8_C(  55), -INT8_C( 108),
        -INT8_C(  35),  INT8_C(  20),  INT8_C(  86),  INT8_C( 100),  INT8_C(  27), -INT8_C(  25),  INT8_C( 109), -INT8_C(  15) } },
    { {  INT8_C(  36), -INT8_C(  18),  INT8_C(  86),      INT8_MAX,  INT8_C(   6),  INT8_C(  54), -INT8_C(  60),  INT8_C( 100),
         INT8_C( 111), -INT8_C(  33),  INT8_C(  76), -INT8_C( 101), -INT8_C(  47),  INT8_C(  52), -INT8_C(  22), -INT8_C( 124) },
      UINT16_C( 8467),
      {  INT8_C(  24), -INT8_C(  15),  INT8_C(  53),  INT8_C( 110),  INT8_C(  85), -INT8_C(  94), -INT8_C(  94),  INT8_C( 125),
         INT8_C( 121), -INT8_C(  38), -INT8_C(  96),  INT8_C(  55),  INT8_C( 109), -INT8_C(  60),  INT8_C(  38), -INT8_C(  61) },
      {  INT8_C(  24), -INT8_C(  15),  INT8_C(  86),      INT8_MAX,  INT8_C(  53),  INT8_C(  54), -INT8_C(  60),  INT8_C( 100),
         INT8_C( 110), -INT8_C(  33),  INT8_C(  76), -INT8_C( 101), -INT8_C(  47),  INT8_C(  85), -INT8_C(  22), -INT8_C( 124) } },
    { {  INT8_C(  67),  INT8_C(  44), -INT8_C(   7),  INT8_C(   7), -INT8_C( 111),  INT8_C( 105), -INT8_C(  25), -INT8_C(  35),
         INT8_C(   4), -INT8_C(  72),  INT8_C(  17), -INT8_C(  18),  INT8_C(  60),  INT8_C(  37),  INT8_C(  15),  INT8_C(  84) },
      UINT16_C(17430),
      { -INT8_C(  61),  INT8_C( 107), -INT8_C(  26),  INT8_C( 101), -INT8_C(  24),  INT8_C(  95),  INT8_C(  64), -INT8_C( 119),
        -INT8_C( 106), -INT8_C(  83),  INT8_C(  77), -INT8_C(  68),  INT8_C( 112), -INT8_C( 111), -INT8_C(  23),  INT8_C( 106) },
      {  INT8_C(  67), -INT8_C(  61),  INT8_C( 107),  INT8_C(   7), -INT8_C(  26),  INT8_C( 105), -INT8_C(  25), -INT8_C(  35),
         INT8_C(   4), -INT8_C(  72),  INT8_C( 101), -INT8_C(  18),  INT8_C(  60),  INT8_C(  37), -INT8_C(  24),  INT8_C(  84) } },
    { { -INT8_C( 104),  INT8_C( 122), -INT8_C(  45),      INT8_MAX,  INT8_C(  87), -INT8_C(  41),  INT8_C(  55),  INT8_C( 104),
        -INT8_C(  59),  INT8_C( 115), -INT8_C( 115), -INT8_C(  44), -INT8_C(  56), -INT8_C(  93),  INT8_C(  24), -INT8_C( 117) },
      UINT16_C(65038),
      { -INT8_C(  16), -INT8_C(   9),  INT8_C(  93),  INT8_C(  48),      INT8_MIN, -INT8_C(  13), -INT8_C(  35), -INT8_C(  51),
        -INT8_C(  80),  INT8_C(  78),  INT8_C(  94), -INT8_C( 103), -INT8_C(  72), -INT8_C(   9),  INT8_C(  19), -INT8_C( 117) },
      { -INT8_C( 104), -INT8_C(  16), -INT8_C(   9),  INT8_C(  93),  INT8_C(  87), -INT8_C(  41),  INT8_C(  55),  INT8_C( 104),
        -INT8_C(  59),  INT8_C(  48),      INT8_MIN, -INT8_C(  13), -INT8_C(  35), -INT8_C(  51), -INT8_C(  80),  INT8_C(  78) } },
    { {  INT8_C( 118),  INT8_C( 106),  INT8_C(  98), -INT8_C(  82), -INT8_C(  46),  INT8_C(  39),  INT8_C(  33),  INT8_C(  96),
        -INT8_C(   5), -INT8_C(  23),  INT8_C(   3),  INT8_C(  19),  INT8_C( 116),  INT8_C(  18),  INT8_C(  17),  INT8_C( 101) },
      UINT16_C(28169),
      { -INT8_C( 107), -INT8_C( 119),  INT8_C(  97),  INT8_C( 115),  INT8_C(  86),  INT8_C(  17), -INT8_C(  63), -INT8_C(  75),
        -INT8_C(  86),  INT8_C( 121), -INT8_C(  84), -INT8_C(  67),  INT8_C(   4),  INT8_C(  34),  INT8_C(  39),  INT8_C( 102) },
      { -INT8_C( 107),  INT8_C( 106),  INT8_C(  98), -INT8_C( 119), -INT8_C(  46),  INT8_C(  39),  INT8_C(  33),  INT8_C(  96),
        -INT8_C(   5),  INT8_C(  97),  INT8_C( 115),  INT8_C(  86),  INT8_C( 116),  INT8_C(  17), -INT8_C(  63),  INT8_C( 101) } },
    { { -INT8_C(  48), -INT8_C(   6), -INT8_C( 115), -INT8_C(  14),  INT8_C(  90), -INT8_C( 120), -INT8_C(  37),  INT8_C(  93),
        -INT8_C( 101),  INT8_C(  80),  INT8_C( 111), -INT8_C(  84), -INT8_C(  75),  INT8_C( 120),  INT8_C(  26),  INT8_C(  74) },
      UINT16_C(31489),
      { -INT8_C(  67),  INT8_C(  88), -INT8_C( 115),  INT8_C( 126),  INT8_C(  13),  INT8_C(  55), -INT8_C(   9), -INT8_C(  71),
        -INT8_C(  11), -INT8_C(   5), -INT8_C(  37),  INT8_C(  28),  INT8_C(  97), -INT8_C(  84),  INT8_C(  22), -INT8_C(  18) },
      { -INT8_C(  67), -INT8_C(   6), -INT8_C( 115), -INT8_C(  14),  INT8_C(  90), -INT8_C( 120), -INT8_C(  37),  INT8_C(  93),
         INT8_C(  88), -INT8_C( 115),  INT8_C( 111),  INT8_C( 126),  INT8_C(  13),  INT8_C(  55), -INT8_C(   9),  INT8_C(  74) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i src = simde_mm_loadu_epi8(test_vec[i].src);
    simde__mmask16 k = test_vec[i].k;
    simde__m128i r = simde_mm_mask_expandloadu_epi8(src, k, test_vec[i].mem_addr);
    simde_test_x86_assert_equal_i8x16(r, simde_mm_loadu_epi8(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_mm_maskz_expandloadu_epi8 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const simde__mmask16 k;
    SIMDE_ALIGN_LIKE_64(simde__m128i) const int8_t mem_addr[16];
    const int8_t r[16];
  } test_vec[] = {
    { UINT16_C(28830),
      {  INT8_C( 118),  INT8_C( 121), -INT8_C(  50),  INT8_C(  17), -INT8_C(  55),  INT8_C(  61), -INT8_C(  67),  INT8_C( 126),
        -INT8_C(  74), -INT8_C(  41), -INT8_C(  55), -INT8_C(  73),  INT8_C(  83), -INT8_C( 122),  INT8_C(  15), -INT8_C(  32) },
      {  INT8_C(   0),  INT8_C( 118),  INT8_C( 121), -INT8_C(  50),  INT8_C(  17),  INT8_C(   0),  INT8_C(   0), -INT8_C(  55),
         INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(  61), -INT8_C(  67),  INT8_C( 126),  INT8_C(   0) } },
    { UINT16_C( 7173),
      {  INT8_C(  23), -INT8_C(   4), -INT8_C(  43),  INT8_C(  12), -INT8_C(   8), -INT8_C(  79),  INT8_C(  41),  INT8_C(  89),
         INT8_C(  93),  INT8_C(  63),  INT8_C(  72), -INT8_C(   5), -INT8_C(  80), -INT8_C(  66),  INT8_C( 116),  INT8_C( 126) },
      {  INT8_C(  23),  INT8_C(   0), -INT8_C(   4),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
         INT8_C(   0),  INT8_C(   0), -INT8_C(  43),  INT8_C(  12), -INT8_C(   8),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0) } },
    { UINT16_C(16080),
      { -INT8_C(  69), -INT8_C( 115), -INT8_C(  68),  INT8_C( 113),  INT8_C( 101), -INT8_C( 123),  INT8_C(  41), -INT8_C(  72),
         INT8_C(  12),  INT8_C(  56), -INT8_C( 104),  INT8_C(  17),  INT8_C(  85), -INT8_C(  81),  INT8_C(  13),  INT8_C(  42) },
      {  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  69),  INT8_C(   0), -INT8_C( 115), -INT8_C(  68),
         INT8_C(   0),  INT8_C( 113),  INT8_C( 101), -INT8_C( 123),  INT8_C(  41), -INT8_C(  72),  INT8_C(   0),  INT8_C(   0) } },
    { UINT16_C( 1468),
      { -INT8_C(  37), -INT8_C(  27),  INT8_C(  95),  INT8_C(  56),  INT8_C(  36), -INT8_C(  89),  INT8_C(  51), -INT8_C(  44),
         INT8_C( 101), -INT8_C(  88),  INT8_C(  82),  INT8_C(  53), -INT8_C(  26),  INT8_C(  14), -INT8_C(  61), -INT8_C(  94) },
      {  INT8_C(   0),  INT8_C(   0), -INT8_C(  37), -INT8_C(  27),  INT8_C(  95),  INT8_C(  56),  INT8_C(   0),  INT8_C(  36),
        -INT8_C(  89),  INT8_C(   0),  INT8_C(  51),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0) } },
    { UINT16_C(10367),
      {  INT8_C(  40), -INT8_C(  88), -INT8_C(  32),  INT8_C(  52), -INT8_C(  31),  INT8_C( 120),  INT8_C(  69),  INT8_C(  54),
         INT8_C(  39),  INT8_C(  82),  INT8_C(  96), -INT8_C(  29),  INT8_C(  88),  INT8_C(  60), -INT8_C(  56), -INT8_C(  73) },
      {  INT8_C(  40), -INT8_C(  88), -INT8_C(  32),  INT8_C(  52), -INT8_C(  31),  INT8_C( 120),  INT8_C(  69),  INT8_C(   0),
         INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(  54),  INT8_C(   0),  INT8_C(  39),  INT8_C(   0),  INT8_C(   0) } },
    { UINT16_C(60788),
      {  INT8_C(  94), -INT8_C(  88), -INT8_C(  63), -INT8_C(  61),  INT8_C(  80),  INT8_C(  20), -INT8_C(   7),  INT8_C(  54),
         INT8_C(  34), -INT8_C(  68), -INT8_C(  40), -INT8_C(  95), -INT8_C(  28),  INT8_C(   0),  INT8_C(  74), -INT8_C(  60) },
      {  INT8_C(   0),  INT8_C(   0),  INT8_C(  94),  INT8_C(   0), -INT8_C(  88), -INT8_C(  63), -INT8_C(  61),  INT8_C(   0),
         INT8_C(  80),  INT8_C(   0),  INT8_C(  20), -INT8_C(   7),  INT8_C(   0),  INT8_C(  54),  INT8_C(  34), -INT8_C(  68) } },
    { UINT16_C(11060),
      {  INT8_C(  60),  INT8_C( 121),  INT8_C(  97),  INT8_C(  99), -INT8_C(  52), -INT8_C(  63),  INT8_C(  71),  INT8_C(  36),
        -INT8_C(   3),  INT8_C(  15), -INT8_C(  37),  INT8_C( 114), -INT8_C(   4),  INT8_C(  57),  INT8_C(  26), -INT8_C(  66) },
      {  INT8_C(   0),  INT8_C(   0),  INT8_C(  60),  INT8_C(   0),  INT8_C( 121),  INT8_C(  97),  INT8_C(   0),  INT8_C(   0),
         INT8_C(  99), -INT8_C(  52),  INT8_C(   0), -INT8_C(  63),  INT8_C(   0),  INT8_C(  71),  INT8_C(   0),  INT8_C(   0) } },
    { UINT16_C(27388),
      { -INT8_C(  46), -INT8_C(  11), -INT8_C(  96), -INT8_C(  12), -INT8_C(  79),  INT8_C( 120), -INT8_C( 107), -INT8_C( 107),
         INT8_C( 121), -INT8_C(  33),  INT8_C(  89), -INT8_C(  83),  INT8_C(  10), -INT8_C( 107),  INT8_C(  39),  INT8_C( 107) },
      {  INT8_C(   0),  INT8_C(   0), -INT8_C(  46), -INT8_C(  11), -INT8_C(  96), -INT8_C(  12), -INT8_C(  79),  INT8_C( 120),
         INT8_C(   0), -INT8_C( 107),  INT8_C(   0), -INT8_C( 107),  INT8_C(   0),  INT8_C( 121), -INT8_C(  33),  INT8_C(   0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__mmask16 k = test_vec[i].k;
    simde__m128i r = simde_mm_maskz_expandloadu_epi8(k, test_vec[i].mem_addr);
    simde_test_x86_assert_equal_i8x16(r, simde_mm_loadu_epi8(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_mm256_mask_expandloadu_epi8 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const int8_t src[32];
    const simde__mmask32 k;
    SIMDE_ALIGN_LIKE_64(simde__m256i) const int8_t mem_addr[32];
    const int8_t r[32];
  } test_vec[] = {
    { { -INT8_C(   7), -INT8_C(  13),  INT8_C(  45),  INT8_C(  64),  INT8_C(  23),  INT8_C(  42),  INT8_C(  79), -INT8_C(  14),
        -INT8_C( 100),  INT8_C(  76),  INT8_C(  43), -INT8_C(  74),  INT8_C(  10),  INT8_C(  39),  INT8_C(  32), -INT8_C(  36),
         INT8_C(  29), -INT8_C(  64), -INT8_C(  48), -INT8_C(  50),  INT8_C(  57),  INT8_C( 101),  INT8_C( 100), -INT8_C(  78),
         INT8_C(  69), -INT8_C(  67),  INT8_C(  95),  INT8_C(  79),  INT8_C(  83), -INT8_C( 122), -INT8_C(  69),  INT8_C(  76) },
      UINT32_C(2425153657),
      {  INT8_C(  18), -INT8_C(  37), -INT8_C( 126), -INT8_C(  81),  INT8_C(  39), -INT8_C(  83),  INT8_C( 101),  INT8_C(  49),
        -INT8_C(  43), -INT8_C( 122),  INT8_C(  13), -INT8_C(  14),  INT8_C(  70), -INT8_C(  35), -INT8_C(  64),      INT8_MAX,
         INT8_C(  67),  INT8_C(  36),  INT8_C(  49), -INT8_C( 120), -INT8_C(  30), -INT8_C( 111), -INT8_C(  41),  INT8_C(  53),
         INT8_C(  23), -INT8_C( 110), -INT8_C( 127), -INT8_C( 111),  INT8_C( 122),  INT8_C(  13),  INT8_C(  33), -INT8_C( 115) },
      {  INT8_C(  18), -INT8_C(  13),  INT8_C(  45), -INT8_C(  37), -INT8_C( 126), -INT8_C(  81),  INT8_C(  39), -INT8_C(  14),
        -INT8_C( 100),  INT8_C(  76),  INT8_C(  43), -INT8_C(  83),  INT8_C(  10),  INT8_C( 101),  INT8_C(  49), -INT8_C(  43),
         INT8_C(  29), -INT8_C(  64), -INT8_C( 122),  INT8_C(  13),  INT8_C(  57),  INT8_C( 101),  INT8_C( 100), -INT8_C(  14),
         INT8_C(  69), -INT8_C(  67),  INT8_C(  95),  INT8_C(  79),  INT8_C(  70), -INT8_C( 122), -INT8_C(  69), -INT8_C(  35) } },
    { { -INT8_C(  24), -INT8_C(  92),  INT8_C(  60),  INT8_C(  16),  INT8_C(  81), -INT8_C(  95),  INT8_C(  65),  INT8_C(  38),
         INT8_C(  39),  INT8_C(  79),  INT8_C(  24),  INT8_C( 110),  INT8_C(  44), -INT8_C(  39), -INT8_C(  19),  INT8_C( 111),
        -INT8_C(   3),  INT8_C(  31), -INT8_C(   9), -INT8_C(  33), -INT8_C(  80), -INT8_C(  49),  INT8_C(  20), -INT8_C(  57),
         INT8_C(  97), -INT8_C( 107),  INT8_C(  88), -INT8_C(  36), -INT8_C(  94),  INT8_C( 122),  INT8_C( 105), -INT8_C( 117) },
      UINT32_C(1872471326),
      {  INT8_C(  70), -INT8_C(  36), -INT8_C( 106),  INT8_C( 110),  INT8_C(  43), -INT8_C(  82), -INT8_C(  36),  INT8_C(  88),
        -INT8_C( 121), -INT8_C(  55), -INT8_C(  57), -INT8_C( 123), -INT8_C(  24), -INT8_C(  65),  INT8_C( 100), -INT8_C( 104),
        -INT8_C( 114),  INT8_C( 121),  INT8_C(  96), -INT8_C(  17),  INT8_C(  14), -INT8_C(  72), -INT8_C(  53), -INT8_C(  79),
         INT8_C(  50),  INT8_C(  52),  INT8_C(  60),  INT8_C(  80), -INT8_C(  39), -INT8_C(  41), -INT8_C(  64),  INT8_C(  32) },
      { -INT8_C(  24),  INT8_C(  70), -INT8_C(  36), -INT8_C( 106),  INT8_C( 110), -INT8_C(  95),  INT8_C(  65),  INT8_C(  38),
         INT8_C(  43),  INT8_C(  79), -INT8_C(  82),  INT8_C( 110),  INT8_C(  44), -INT8_C(  36), -INT8_C(  19),  INT8_C(  88),
        -INT8_C( 121), -INT8_C(  55), -INT8_C(   9), -INT8_C(  57), -INT8_C( 123), -INT8_C(  49),  INT8_C(  20), -INT8_C(  24),
        -INT8_C(  65),  INT8_C( 100), -INT8_C( 104), -INT8_C( 114), -INT8_C(  94),  INT8_C( 121),  INT8_C(  96), -INT8_C( 117) } },
    { { -INT8_C(  77),  INT8_C(  86), -INT8_C( 114), -INT8_C(  33),  INT8_C(   4),  INT8_C( 106),  INT8_C(  55), -INT8_C( 116),
         INT8_C(  51), -INT8_C(   2),  INT8_C(  17),  INT8_C(  28), -INT8_C(  67),  INT8_C( 117), -INT8_C(  76),  INT8_C(  75),
        -INT8_C(  18),  INT8_C(  20),  INT8_C(  59), -INT8_C(   3), -INT8_C(  51),  INT8_C(   6), -INT8_C(  82), -INT8_C(   1),
         INT8_C(  59), -INT8_C(  22),  INT8_C(  80),  INT8_C(  20), -INT8_C(  63),  INT8_C(  16),  INT8_C(  52),  INT8_C( 116) },
      UINT32_C(1783874150),
      {  INT8_C(  44), -INT8_C( 118), -INT8_C(  10),  INT8_C(  96), -INT8_C( 119),  INT8_C(   7),  INT8_C( 124),  INT8_C(  70),
         INT8_C( 125),  INT8_C(  48), -INT8_C( 110),  INT8_C( 107),  INT8_C(  69), -INT8_C(  51),  INT8_C( 104),  INT8_C(  18),
        -INT8_C(  45),  INT8_C(  22),  INT8_C(  17),  INT8_C(  14),  INT8_C(   0),  INT8_C(  97),  INT8_C(  35), -INT8_C(  63),
         INT8_C( 113),  INT8_C(  87),  INT8_C(  54), -INT8_C(  41),  INT8_C(  26), -INT8_C( 119),  INT8_C(  66),  INT8_C(  70) },
      { -INT8_C(  77),  INT8_C(  44), -INT8_C( 118), -INT8_C(  33),  INT8_C(   4), -INT8_C(  10),  INT8_C(  96), -INT8_C( 116),
         INT8_C(  51), -INT8_C( 119),  INT8_C(  17),  INT8_C(  28), -INT8_C(  67),  INT8_C( 117),  INT8_C(   7),  INT8_C( 124),
         INT8_C(  70),  INT8_C( 125),  INT8_C(  59), -INT8_C(   3),  INT8_C(  48),  INT8_C(   6), -INT8_C( 110), -INT8_C(   1),
         INT8_C(  59),  INT8_C( 107),  INT8_C(  80),  INT8_C(  69), -INT8_C(  63), -INT8_C(  51),  INT8_C( 104),  INT8_C( 116) } },
    { {  INT8_C(  20),  INT8_C(  56), -INT8_C(  90), -INT8_C(  99),  INT8_C(  64),  INT8_C(  34), -INT8_C(  29), -INT8_C(  67),
         INT8_C(  83),  INT8_C( 117),  INT8_C(  40), -INT8_C( 104),  INT8_C(  66), -INT8_C( 111), -INT8_C(  86),  INT8_C(  22),
        -INT8_C(  89), -INT8_C(  69),  INT8_C(  36), -INT8_C(  88),  INT8_C(  29),  INT8_C(  71),  INT8_C( 105), -INT8_C( 114),
        -INT8_C(  97), -INT8_C(  97),  INT8_C( 102), -INT8_C(  71),  INT8_C(  41), -INT8_C(  88), -INT8_C(   1),  INT8_C(  61) },
      UINT32_C( 551200480),
      { -INT8_C(  56), -INT8_C(  67), -INT8_C(  35),  INT8_C(  27),  INT8_C(  51),  INT8_C(   6), -INT8_C(  77),  INT8_C( 117),
        -INT8_C( 105),  INT8_C(  93), -INT8_C( 117),  INT8_C(  62),  INT8_C(  25), -INT8_C(  80), -INT8_C(  26),  INT8_C(  54),
        -INT8_C(   9),  INT8_C(  80), -INT8_C(  60), -INT8_C( 106), -INT8_C(  17),  INT8_C(  42),  INT8_C(  79),  INT8_C(  24),
        -INT8_C(  46),  INT8_C(  79),  INT8_C(  85), -INT8_C(  77), -INT8_C(  11),  INT8_C(  47), -INT8_C(  45), -INT8_C(  67) },
      {  INT8_C(  20),  INT8_C(  56), -INT8_C(  90), -INT8_C(  99),  INT8_C(  64), -INT8_C(  56), -INT8_C(  67), -INT8_C(  35),
         INT8_C(  83),  INT8_C(  27),  INT8_C(  51), -INT8_C( 104),  INT8_C(  66),  INT8_C(   6), -INT8_C(  86), -INT8_C(  77),
        -INT8_C(  89),  INT8_C( 117),  INT8_C(  36), -INT8_C( 105),  INT8_C(  93),  INT8_C(  71), -INT8_C( 117),  INT8_C(  62),
        -INT8_C(  97), -INT8_C(  97),  INT8_C( 102), -INT8_C(  71),  INT8_C(  41),  INT8_C(  25), -INT8_C(   1),  INT8_C(  61) } },
    { { -INT8_C(  19), -INT8_C(  79), -INT8_C(  39),  INT8_C(  32), -INT8_C(  73), -INT8_C( 116), -INT8_C( 107),  INT8_C(  78),
        -INT8_C(  22),  INT8_C(  33), -INT8_C( 116),  INT8_C(   3), -INT8_C(  47),  INT8_C( 115),  INT8_C(  57), -INT8_C(  56),
        -INT8_C(  61), -INT8_C(   3),  INT8_C(  95), -INT8_C(  78),  INT8_C(  40), -INT8_C(  82), -INT8_C(  53), -INT8_C(   6),
        -INT8_C(   3),  INT8_C(  32), -INT8_C(  83), -INT8_C(  14),  INT8_C(  80), -INT8_C( 127), -INT8_C(  80),  INT8_C(  61) },
      UINT32_C(3915221298),
      {  INT8_C(  21), -INT8_C(  14),  INT8_C(  55), -INT8_C(   1),  INT8_C(  19), -INT8_C(  61),  INT8_C(   2), -INT8_C(  28),
         INT8_C(  54),  INT8_C(  59), -INT8_C(  83), -INT8_C(   7),  INT8_C(  57),  INT8_C(  12), -INT8_C(  84),  INT8_C(  97),
        -INT8_C(  70),  INT8_C( 119),  INT8_C(  91), -INT8_C(  72), -INT8_C( 105),  INT8_C(   9), -INT8_C(  86), -INT8_C(  25),
        -INT8_C( 118),  INT8_C(  90),  INT8_C(  36), -INT8_C(  68), -INT8_C(  29), -INT8_C( 127), -INT8_C(  91), -INT8_C(   7) },
      { -INT8_C(  19),  INT8_C(  21), -INT8_C(  39),  INT8_C(  32), -INT8_C(  14),  INT8_C(  55), -INT8_C( 107),  INT8_C(  78),
        -INT8_C(   1),  INT8_C(  33), -INT8_C( 116),  INT8_C(  19), -INT8_C(  47),  INT8_C( 115),  INT8_C(  57), -INT8_C(  61),
         INT8_C(   2), -INT8_C(   3), -INT8_C(  28),  INT8_C(  54),  INT8_C(  59), -INT8_C(  82), -INT8_C(  83), -INT8_C(   6),
        -INT8_C(   7),  INT8_C(  32), -INT8_C(  83),  INT8_C(  57),  INT8_C(  80),  INT8_C(  12), -INT8_C(  84),  INT8_C(  97) } },
    { {  INT8_C( 116), -INT8_C(  36), -INT8_C(   8), -INT8_C( 121), -INT8_C(  97), -INT8_C(   5),  INT8_C( 108), -INT8_C(  42),
         INT8_C(  54),  INT8_C(  25), -INT8_C(  49),  INT8_C( 111),  INT8_C(  37),  INT8_C( 123), -INT8_C(  48), -INT8_C(  33),
        -INT8_C(  14),  INT8_C(  44), -INT8_C( 105), -INT8_C( 118),  INT8_C(  53),  INT8_C(  66),  INT8_C( 113), -INT8_C(  65),
        -INT8_C( 100), -INT8_C( 106),  INT8_C( 123),      INT8_MIN,  INT8_C(  23),  INT8_C(  32),  INT8_C( 121), -INT8_C( 117) },
      UINT32_C(2601742844),
      {  INT8_C( 108),      INT8_MAX,  INT8_C( 113), -INT8_C(  93), -INT8_C( 104),  INT8_C(  65),  INT8_C(  18), -INT8_C(  67),
        -INT8_C(  68), -INT8_C(  29), -INT8_C( 100), -INT8_C(  81),  INT8_C(  15),  INT8_C(  52),  INT8_C(  57),  INT8_C(  68),
         INT8_C( 118), -INT8_C(  86),  INT8_C(   3),  INT8_C(  18),  INT8_C(  64),  INT8_C( 126), -INT8_C( 110),  INT8_C(  88),
        -INT8_C(  98),  INT8_C(  11), -INT8_C(  29), -INT8_C( 102),  INT8_C( 125), -INT8_C(  10),  INT8_C(  53), -INT8_C(  23) },
      {  INT8_C( 116), -INT8_C(  36),  INT8_C( 108),      INT8_MAX,  INT8_C( 113), -INT8_C(  93), -INT8_C( 104),  INT8_C(  65),
         INT8_C(  18),  INT8_C(  25), -INT8_C(  49),  INT8_C( 111), -INT8_C(  67), -INT8_C(  68), -INT8_C(  29), -INT8_C(  33),
        -INT8_C( 100), -INT8_C(  81), -INT8_C( 105), -INT8_C( 118),  INT8_C(  15),  INT8_C(  66),  INT8_C( 113), -INT8_C(  65),
         INT8_C(  52),  INT8_C(  57),  INT8_C( 123),  INT8_C(  68),  INT8_C( 118),  INT8_C(  32),  INT8_C( 121), -INT8_C(  86) } },
    { {  INT8_C( 117), -INT8_C(  89), -INT8_C( 116),  INT8_C(  13), -INT8_C(  24), -INT8_C(  97), -INT8_C(  54), -INT8_C(  92),
        -INT8_C( 126),  INT8_C( 103),  INT8_C(  83), -INT8_C( 111), -INT8_C( 101), -INT8_C( 116), -INT8_C(  43),  INT8_C(  17),
         INT8_C(  55), -INT8_C(  40),  INT8_C(  35),  INT8_C( 119),  INT8_C(  86), -INT8_C(  74), -INT8_C(  49), -INT8_C(  12),
        -INT8_C(  63), -INT8_C(  77), -INT8_C( 114),  INT8_C(  62), -INT8_C(  87), -INT8_C(  61),  INT8_C(  40),  INT8_C(  31) },
      UINT32_C(1378661482),
      {  INT8_C(  83), -INT8_C(   9), -INT8_C(   9), -INT8_C(  43),  INT8_C(  94),  INT8_C(  74),  INT8_C( 102), -INT8_C(   7),
        -INT8_C(  41),  INT8_C(  59),  INT8_C(  10),  INT8_C(  14),  INT8_C(  19),  INT8_C(  45), -INT8_C( 123),  INT8_C( 105),
        -INT8_C(  29),  INT8_C(  85),  INT8_C(  93), -INT8_C(  91),  INT8_C(   8), -INT8_C(  21), -INT8_C(  29), -INT8_C(  79),
        -INT8_C(  81),  INT8_C(  11), -INT8_C(  48),  INT8_C(  25), -INT8_C(  64), -INT8_C(   3),  INT8_C( 108),  INT8_C(  19) },
      {  INT8_C( 117),  INT8_C(  83), -INT8_C( 116), -INT8_C(   9), -INT8_C(  24), -INT8_C(   9), -INT8_C(  43), -INT8_C(  92),
        -INT8_C( 126),  INT8_C( 103),  INT8_C(  94), -INT8_C( 111),  INT8_C(  74),  INT8_C( 102), -INT8_C(  43), -INT8_C(   7),
         INT8_C(  55), -INT8_C(  40), -INT8_C(  41),  INT8_C(  59),  INT8_C(  86),  INT8_C(  10), -INT8_C(  49), -INT8_C(  12),
        -INT8_C(  63),  INT8_C(  14), -INT8_C( 114),  INT8_C(  62),  INT8_C(  19), -INT8_C(  61),  INT8_C(  45),  INT8_C(  31) } },
    { { -INT8_C(  12),  INT8_C(  99), -INT8_C(  23),  INT8_C(  82), -INT8_C(  83),  INT8_C(  79),  INT8_C(  75), -INT8_C( 124),
        -INT8_C( 117),  INT8_C(  85), -INT8_C( 110), -INT8_C(  98), -INT8_C( 126),  INT8_C(  24),  INT8_C(   8),  INT8_C( 102),
         INT8_C( 109),  INT8_C( 101),  INT8_C(  11),  INT8_C( 117),  INT8_C(  81), -INT8_C(  18),  INT8_C(  38),  INT8_C(   0),
        -INT8_C(   6), -INT8_C(   9),  INT8_C(  25), -INT8_C(  70), -INT8_C(  12), -INT8_C( 123), -INT8_C(  51), -INT8_C(  24) },
      UINT32_C(2520430312),
      {  INT8_C(   6), -INT8_C( 123),  INT8_C(  26), -INT8_C( 111), -INT8_C(  38), -INT8_C(  83),  INT8_C(  47),  INT8_C(  92),
        -INT8_C(  59),  INT8_C(  55), -INT8_C(  62),  INT8_C(  50), -INT8_C(  99), -INT8_C(  51), -INT8_C(  89), -INT8_C(  18),
        -INT8_C(  68), -INT8_C(  51), -INT8_C(  18), -INT8_C(  74), -INT8_C(  60),  INT8_C(   7),  INT8_C( 112), -INT8_C(  72),
        -INT8_C( 115),  INT8_C(  61), -INT8_C(  96),  INT8_C( 117), -INT8_C(  12), -INT8_C(  38),  INT8_C(  11), -INT8_C(   6) },
      { -INT8_C(  12),  INT8_C(  99), -INT8_C(  23),  INT8_C(   6), -INT8_C(  83), -INT8_C( 123),  INT8_C(  26), -INT8_C( 111),
        -INT8_C( 117), -INT8_C(  38), -INT8_C(  83), -INT8_C(  98),  INT8_C(  47),  INT8_C(  92),  INT8_C(   8), -INT8_C(  59),
         INT8_C( 109),  INT8_C(  55),  INT8_C(  11), -INT8_C(  62),  INT8_C(  50), -INT8_C(  99),  INT8_C(  38),  INT8_C(   0),
        -INT8_C(   6), -INT8_C(  51), -INT8_C(  89), -INT8_C(  70), -INT8_C(  18), -INT8_C( 123), -INT8_C(  51), -INT8_C(  68) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256i src = simde_mm256_loadu_epi8(test_vec[i].src);
    simde__mmask32 k = test_vec[i].k;
    simde__m256i r = simde_mm256_mask_expandloadu_epi8(src, k, test_vec[i].mem_addr);
    simde_test_x86_assert_equal_i8x32(r, simde_mm256_loadu_epi8(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_mm256_maskz_expandloadu_epi8 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const simde__mmask32 k;
    SIMDE_ALIGN_LIKE_64(simde__m256i) const int8_t mem_addr[32];
    const int8_t r[32];
  } test_vec[] = {
    { UINT32_C( 965420639),
      { -INT8_C(  45), -INT8_C(  70), -INT8_C( 106), -INT8_C( 104), -INT8_C(  14),  INT8_C(  88), -INT8_C(  54), -INT8_C( 113),
         INT8_C(  38),  INT8_C( 113),  INT8_C( 125), -INT8_C(  30),  INT8_C(  62),  INT8_C( 107), -INT8_C( 104),  INT8_C(   3),
         INT8_C( 114),  INT8_C(   8), -INT8_C(  69), -INT8_C(   1),  INT8_C(  69),  INT8_C(  92),  INT8_C( 117),  INT8_C(  57),
         INT8_C(  54),      INT8_MIN,  INT8_C(  51), -INT8_C( 106), -INT8_C(  90), -INT8_C(  66), -INT8_C(  49),  INT8_C( 121) },
      { -INT8_C(  45), -INT8_C(  70), -INT8_C( 106), -INT8_C( 104), -INT8_C(  14),  INT8_C(   0),  INT8_C(  88),  INT8_C(   0),
         INT8_C(   0), -INT8_C(  54), -INT8_C( 113),  INT8_C(   0),  INT8_C(   0),  INT8_C(  38),  INT8_C(   0),  INT8_C(   0),
         INT8_C( 113),  INT8_C( 125),  INT8_C(   0), -INT8_C(  30),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(  62),
         INT8_C( 107),  INT8_C(   0),  INT8_C(   0), -INT8_C( 104),  INT8_C(   3),  INT8_C( 114),  INT8_C(   0),  INT8_C(   0) } },
    { UINT32_C(1796302201),
      { -INT8_C(  66), -INT8_C(  37), -INT8_C(   6), -INT8_C(  28),  INT8_C(  76),  INT8_C( 119), -INT8_C(  58), -INT8_C( 117),
        -INT8_C(  30),  INT8_C(  94), -INT8_C( 114),  INT8_C(  84),  INT8_C( 102),  INT8_C(  73),  INT8_C(  84), -INT8_C(  85),
        -INT8_C(  91), -INT8_C(  55), -INT8_C(  27), -INT8_C(  36),  INT8_C(  73),  INT8_C(  24),  INT8_C( 114), -INT8_C(  16),
        -INT8_C(  41),  INT8_C(  65),  INT8_C( 105),  INT8_C(  80), -INT8_C(  89),  INT8_C( 123), -INT8_C(  69),  INT8_C( 101) },
      { -INT8_C(  66),  INT8_C(   0),  INT8_C(   0), -INT8_C(  37), -INT8_C(   6), -INT8_C(  28),  INT8_C(  76),  INT8_C(   0),
         INT8_C( 119),  INT8_C(   0), -INT8_C(  58),  INT8_C(   0),  INT8_C(   0), -INT8_C( 117), -INT8_C(  30),  INT8_C(   0),
         INT8_C(  94),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C( 114),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
         INT8_C(  84),  INT8_C( 102),  INT8_C(   0),  INT8_C(  73),  INT8_C(   0),  INT8_C(  84), -INT8_C(  85),  INT8_C(   0) } },
    { UINT32_C(2739516758),
      {  INT8_C(  44),  INT8_C(  15),  INT8_C(  46),  INT8_C(  14),  INT8_C( 109), -INT8_C(  68),  INT8_C(  98), -INT8_C(  45),
         INT8_C(   5), -INT8_C(  74),  INT8_C( 126), -INT8_C(  85),      INT8_MAX,  INT8_C(  99), -INT8_C( 121), -INT8_C(  55),
         INT8_C( 124), -INT8_C(   7), -INT8_C(  71),  INT8_C(  83),  INT8_C(  58),  INT8_C(  34), -INT8_C(  93), -INT8_C(  31),
        -INT8_C(  99),  INT8_C(  94),  INT8_C(  70), -INT8_C(  12),  INT8_C(  19), -INT8_C( 113), -INT8_C( 105),  INT8_C(  63) },
      {  INT8_C(   0),  INT8_C(  44),  INT8_C(  15),  INT8_C(   0),  INT8_C(  46),  INT8_C(   0),  INT8_C(  14),  INT8_C(   0),
         INT8_C( 109),  INT8_C(   0), -INT8_C(  68),  INT8_C(   0),  INT8_C(  98), -INT8_C(  45),  INT8_C(   0),  INT8_C(   5),
        -INT8_C(  74),  INT8_C(   0),  INT8_C(   0),  INT8_C( 126),  INT8_C(   0),  INT8_C(   0), -INT8_C(  85),  INT8_C(   0),
             INT8_MAX,  INT8_C(  99),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C( 121),  INT8_C(   0), -INT8_C(  55) } },
    { UINT32_C( 189646238),
      { -INT8_C( 127), -INT8_C(  81), -INT8_C(  34), -INT8_C( 122),  INT8_C( 102),  INT8_C(  93),  INT8_C(  49), -INT8_C(  27),
        -INT8_C(  64), -INT8_C(  72), -INT8_C(  82),  INT8_C(  60), -INT8_C(  79),  INT8_C( 103), -INT8_C( 113), -INT8_C(  20),
        -INT8_C( 118),  INT8_C(  50), -INT8_C(  51),  INT8_C(  39), -INT8_C( 112),  INT8_C(  20),  INT8_C(  27), -INT8_C(  93),
        -INT8_C(  93), -INT8_C(  78), -INT8_C(  30),  INT8_C(  66),  INT8_C( 119),  INT8_C(  47),  INT8_C(  77), -INT8_C(   8) },
      {  INT8_C(   0), -INT8_C( 127), -INT8_C(  81), -INT8_C(  34), -INT8_C( 122),  INT8_C(   0),  INT8_C(   0),  INT8_C( 102),
         INT8_C(  93),  INT8_C(   0),  INT8_C(  49),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  27), -INT8_C(  64),
        -INT8_C(  72),  INT8_C(   0), -INT8_C(  82),  INT8_C(  60),  INT8_C(   0),  INT8_C(   0), -INT8_C(  79),  INT8_C(   0),
         INT8_C( 103), -INT8_C( 113),  INT8_C(   0), -INT8_C(  20),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0) } },
    { UINT32_C(1165962463),
      { -INT8_C( 119), -INT8_C(  80),  INT8_C(  42),  INT8_C(  73),  INT8_C( 105), -INT8_C(  39), -INT8_C( 122),  INT8_C(  26),
         INT8_C(  64),  INT8_C(  21),  INT8_C(   6), -INT8_C(  54),  INT8_C(  72), -INT8_C(  44), -INT8_C(  14), -INT8_C(  40),
        -INT8_C(  24),  INT8_C(  13),  INT8_C( 124), -INT8_C( 117), -INT8_C(  64),  INT8_C(  94), -INT8_C(  51),  INT8_C(  55),
        -INT8_C( 114),  INT8_C(  27),  INT8_C(  48),  INT8_C( 109),  INT8_C(  71), -INT8_C(  81), -INT8_C(  78), -INT8_C(  48) },
      { -INT8_C( 119), -INT8_C(  80),  INT8_C(  42),  INT8_C(  73),  INT8_C( 105),  INT8_C(   0), -INT8_C(  39), -INT8_C( 122),
         INT8_C(   0),  INT8_C(   0),  INT8_C(  26),  INT8_C(  64),  INT8_C(   0),  INT8_C(  21),  INT8_C(   0),  INT8_C(   0),
         INT8_C(   6), -INT8_C(  54),  INT8_C(  72), -INT8_C(  44), -INT8_C(  14), -INT8_C(  40), -INT8_C(  24),  INT8_C(   0),
         INT8_C(  13),  INT8_C(   0),  INT8_C( 124),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C( 117),  INT8_C(   0) } },
    { UINT32_C(3357138015),
      { -INT8_C(  75), -INT8_C(  97), -INT8_C(  29), -INT8_C(  10), -INT8_C(  75), -INT8_C(  23), -INT8_C(  64), -INT8_C(   3),
        -INT8_C(  67), -INT8_C(  78), -INT8_C(  43), -INT8_C(  91), -INT8_C(  64),  INT8_C(  81),  INT8_C(  49),      INT8_MIN,
        -INT8_C(  80), -INT8_C(   2), -INT8_C(  73),  INT8_C(  62),  INT8_C(  25), -INT8_C(  25), -INT8_C(  85),  INT8_C(  96),
        -INT8_C( 106),  INT8_C(  93),  INT8_C(  48), -INT8_C(  10),  INT8_C(  57),  INT8_C(  74), -INT8_C(  66), -INT8_C(  17) },
      { -INT8_C(  75), -INT8_C(  97), -INT8_C(  29), -INT8_C(  10), -INT8_C(  75),  INT8_C(   0), -INT8_C(  23),  INT8_C(   0),
         INT8_C(   0),  INT8_C(   0), -INT8_C(  64), -INT8_C(   3), -INT8_C(  67),  INT8_C(   0), -INT8_C(  78), -INT8_C(  43),
        -INT8_C(  91),  INT8_C(   0),  INT8_C(   0), -INT8_C(  64),  INT8_C(  81),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
         INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(  49),  INT8_C(   0),  INT8_C(   0),      INT8_MIN, -INT8_C(  80) } },
    { UINT32_C(2665849321),
      { -INT8_C( 117), -INT8_C(  91), -INT8_C( 101),  INT8_C(  72),  INT8_C(  88),  INT8_C( 113), -INT8_C(  18),  INT8_C(  24),
        -INT8_C(  62),  INT8_C(  31), -INT8_C( 104),  INT8_C( 114),  INT8_C(  29),  INT8_C(  79), -INT8_C(  80),  INT8_C(  55),
         INT8_C(  55),  INT8_C(  91), -INT8_C( 105), -INT8_C(  51), -INT8_C(  72), -INT8_C(  56), -INT8_C(  61), -INT8_C(  14),
         INT8_C(  18), -INT8_C( 126), -INT8_C(  31), -INT8_C(   5),  INT8_C(  35), -INT8_C(  58), -INT8_C( 102), -INT8_C(  82) },
      { -INT8_C( 117),  INT8_C(   0),  INT8_C(   0), -INT8_C(  91),  INT8_C(   0), -INT8_C( 101),  INT8_C(  72),  INT8_C(  88),
         INT8_C( 113),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  18),  INT8_C(   0),  INT8_C(  24),
        -INT8_C(  62),  INT8_C(   0),  INT8_C(  31),  INT8_C(   0),  INT8_C(   0), -INT8_C( 104),  INT8_C( 114),  INT8_C(  29),
         INT8_C(   0),  INT8_C(  79), -INT8_C(  80),  INT8_C(  55),  INT8_C(  55),  INT8_C(   0),  INT8_C(   0),  INT8_C(  91) } },
    { UINT32_C(3287758187),
      { -INT8_C(  90), -INT8_C(  27), -INT8_C(  37),  INT8_C( 105),  INT8_C(   4),  INT8_C( 115), -INT8_C(  37),  INT8_C(  33),
        -INT8_C(  61), -INT8_C( 116),  INT8_C(  88), -INT8_C(   6), -INT8_C(  25), -INT8_C(  16), -INT8_C(  57), -INT8_C(  96),
        -INT8_C(  72), -INT8_C( 117), -INT8_C( 110), -INT8_C(  54),  INT8_C(  13),  INT8_C( 115), -INT8_C(  59),  INT8_C(  48),
         INT8_C(  57),  INT8_C(  95), -INT8_C(  33), -INT8_C(  92), -INT8_C( 107), -INT8_C(  42),  INT8_C( 104),  INT8_C(  59) },
      { -INT8_C(  90), -INT8_C(  27),  INT8_C(   0), -INT8_C(  37),  INT8_C(   0),  INT8_C( 105),  INT8_C(   4),  INT8_C(   0),
         INT8_C( 115),  INT8_C(   0), -INT8_C(  37),  INT8_C(   0),  INT8_C(  33), -INT8_C(  61),  INT8_C(   0),  INT8_C(   0),
        -INT8_C( 116),  INT8_C(  88), -INT8_C(   6),  INT8_C(   0), -INT8_C(  25), -INT8_C(  16), -INT8_C(  57), -INT8_C(  96),
        -INT8_C(  72), -INT8_C( 117),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C( 110), -INT8_C(  54) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__mmask32 k = test_vec[i].k;
    simde__m256i r = simde_mm256_maskz_expandloadu_epi8(k, test_vec[i].mem_addr);
    simde_test_x86_assert_equal_i8x32(r, simde_mm256_loadu_epi8(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_mm512_mask_expandloadu_epi8 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const int8_t src[64];
    const simde__mmask64 k;
    SIMDE_ALIGN_LIKE_64(simde__m512i) const int8_t mem_addr[64];
    const int8_t r[64];
  } test_vec[] = {
    { { -INT8_C(  69),  INT8_C(  67), -INT8_C(  92), -INT8_C(  65), -INT8_C(  73),      INT8_MIN, -INT8_C(  32),  INT8_C( 122),
         INT8_C(  12),  INT8_C(  57),  INT8_C( 116), -INT8_C(  13),  INT8_C(  41),  INT8_C(  59), -INT8_C( 109), -INT8_C(  31),
        -INT8_C(  58),  INT8_C(  37), -INT8_C(  85), -INT8_C(  45), -INT8_C( 104),  INT8_C( 112),  INT8_C(   4), -INT8_C(  47),
        -INT8_C(  48), -INT8_C(  29),  INT8_C( 118),  INT8_C( 101), -INT8_C(  71), -INT8_C(  34), -INT8_C(  96),  INT8_C( 116),
         INT8_C(  33),  INT8_C(  69),  INT8_C(  51), -INT8_C(  40), -INT8_C(  59),  INT8_C(  19),  INT8_C(  82), -INT8_C(  47),
         INT8_C(  76), -INT8_C(  58), -INT8_C(  60),  INT8_C( 117),  INT8_C(   2),  INT8_C(  88),  INT8_C(  86), -INT8_C(  56),
         INT8_C( 125),  INT8_C(   1), -INT8_C( 100),  INT8_C(  22),  INT8_C( 114), -INT8_C(  96), -INT8_C(  25),  INT8_C(  66),
        -INT8_C( 125),  INT8_C(  93), -INT8_C(  89),  INT8_C(  60),  INT8_C(  59),  INT8_C(  71), -INT8_C(  80),  INT8_C(  93) },
      UINT64_C( 4837579541255152524),
      {  INT8_C(  78), -INT8_C(  25), -INT8_C(  72),  INT8_C(  80),  INT8_C(  63),  INT8_C(  15),  INT8_C(  25), -INT8_C(  68),
         INT8_C(  16), -INT8_C(  75), -INT8_C(  46), -INT8_C( 126),  INT8_C(  85), -INT8_C(  70), -INT8_C(  60), -INT8_C(  40),
         INT8_C(  23),  INT8_C( 107),  INT8_C(  20),  INT8_C(  83), -INT8_C(  77), -INT8_C(  60), -INT8_C(  80),  INT8_C(  63),
        -INT8_C(  89), -INT8_C(  27), -INT8_C( 111), -INT8_C(  99),  INT8_C( 109), -INT8_C(  77), -INT8_C(  32), -INT8_C(  68),
        -INT8_C( 102), -INT8_C( 103),  INT8_C(  12), -INT8_C(  39), -INT8_C(  88),  INT8_C(  37), -INT8_C( 106), -INT8_C(  72),
        -INT8_C(  38),  INT8_C( 104),  INT8_C(  59),  INT8_C(  47),  INT8_C(  34), -INT8_C(   1),  INT8_C(   7),  INT8_C(  58),
         INT8_C( 107),  INT8_C(  27), -INT8_C( 115),  INT8_C(  30), -INT8_C(  33),  INT8_C(  61),  INT8_C(  93), -INT8_C( 122),
         INT8_C(  34), -INT8_C(  18),  INT8_C(  36), -INT8_C( 112), -INT8_C(  94),  INT8_C(   4),  INT8_C(  76),  INT8_C(  60) },
      { -INT8_C(  69),  INT8_C(  67),  INT8_C(  78), -INT8_C(  25), -INT8_C(  73),      INT8_MIN, -INT8_C(  32), -INT8_C(  72),
         INT8_C(  80),  INT8_C(  63),  INT8_C( 116), -INT8_C(  13),  INT8_C(  41),  INT8_C(  15),  INT8_C(  25), -INT8_C(  68),
         INT8_C(  16),  INT8_C(  37), -INT8_C(  75), -INT8_C(  45), -INT8_C(  46), -INT8_C( 126),  INT8_C(   4), -INT8_C(  47),
         INT8_C(  85), -INT8_C(  29),  INT8_C( 118),  INT8_C( 101), -INT8_C(  70), -INT8_C(  34), -INT8_C(  60),  INT8_C( 116),
         INT8_C(  33), -INT8_C(  40),  INT8_C(  23), -INT8_C(  40),  INT8_C( 107),  INT8_C(  20),  INT8_C(  83), -INT8_C(  77),
         INT8_C(  76), -INT8_C(  58), -INT8_C(  60), -INT8_C(  60),  INT8_C(   2),  INT8_C(  88),  INT8_C(  86), -INT8_C(  80),
         INT8_C( 125),  INT8_C(  63), -INT8_C( 100),  INT8_C(  22),  INT8_C( 114), -INT8_C(  89), -INT8_C(  25),  INT8_C(  66),
        -INT8_C(  27), -INT8_C( 111), -INT8_C(  89),  INT8_C(  60),  INT8_C(  59),  INT8_C(  71), -INT8_C(  99),  INT8_C(  93) } },
    { { -INT8_C(  99),  INT8_C(  88),  INT8_C(  22),  INT8_C(  69),  INT8_C( 126), -INT8_C(  84), -INT8_C(   2),  INT8_C(  88),
         INT8_C(  20),  INT8_C(  57), -INT8_C( 120),  INT8_C(  55),  INT8_C(  56), -INT8_C( 113),  INT8_C( 113), -INT8_C(  93),
        -INT8_C(  85), -INT8_C(   2), -INT8_C(  63), -INT8_C( 118),  INT8_C(  59),  INT8_C(  31),  INT8_C(  17),  INT8_C(  93),
         INT8_C(  13),  INT8_C(  53), -INT8_C(  19), -INT8_C(  81),  INT8_C(  57),  INT8_C(  57), -INT8_C(  20), -INT8_C(  41),
        -INT8_C( 110),  INT8_C(   2),  INT8_C(  28),  INT8_C(  16), -INT8_C(  82),  INT8_C(  26),  INT8_C( 104), -INT8_C(  62),
         INT8_C(  83), -INT8_C(  16), -INT8_C(   7), -INT8_C( 116),      INT8_MIN,  INT8_C( 106),  INT8_C(  47),  INT8_C(  43),
         INT8_C( 104), -INT8_C(  15), -INT8_C(  75), -INT8_C(  93),  INT8_C(  16), -INT8_C(  58),  INT8_C(   1),  INT8_C(  29),
        -INT8_C(   5), -INT8_C(  18), -INT8_C(  51),  INT8_C(  53),  INT8_C(  40), -INT8_C(  71),  INT8_C(  12), -INT8_C(  70) },
      UINT64_C(10820797794806802619),
      {  INT8_C(  35),  INT8_C(  37),  INT8_C(  34), -INT8_C(  93), -INT8_C( 113),  INT8_C(  82), -INT8_C(  50), -INT8_C(   8),
         INT8_C(  67), -INT8_C( 125), -INT8_C( 101),  INT8_C(  83),  INT8_C(  74), -INT8_C( 100),  INT8_C( 112),  INT8_C(  69),
        -INT8_C( 117),  INT8_C(  61),  INT8_C( 122), -INT8_C(  77), -INT8_C(  10), -INT8_C( 122),  INT8_C( 109), -INT8_C(  79),
        -INT8_C(  81),  INT8_C(  55),  INT8_C(  26), -INT8_C(  14),  INT8_C( 105),  INT8_C(  70), -INT8_C( 120), -INT8_C( 116),
         INT8_C( 107), -INT8_C(  85),  INT8_C(  47), -INT8_C(   6), -INT8_C(   3), -INT8_C(   3), -INT8_C(  14),  INT8_C(  64),
        -INT8_C( 127), -INT8_C( 114), -INT8_C( 109), -INT8_C(  53),  INT8_C(  42),  INT8_C(   3),  INT8_C(  16), -INT8_C(  75),
         INT8_C(  65), -INT8_C( 117),  INT8_C( 104),  INT8_C(  55),  INT8_C(  17), -INT8_C(  43), -INT8_C(  23), -INT8_C(  64),
         INT8_C(  12),  INT8_C(   3), -INT8_C(  78),  INT8_C( 118),  INT8_C(  73),  INT8_C(  59),  INT8_C(   2), -INT8_C(  76) },
      {  INT8_C(  35),  INT8_C(  37),  INT8_C(  22),  INT8_C(  34), -INT8_C(  93), -INT8_C( 113), -INT8_C(   2),  INT8_C(  82),
         INT8_C(  20),  INT8_C(  57), -INT8_C( 120), -INT8_C(  50),  INT8_C(  56), -INT8_C(   8),  INT8_C( 113), -INT8_C(  93),
        -INT8_C(  85),  INT8_C(  67), -INT8_C(  63), -INT8_C( 125),  INT8_C(  59),  INT8_C(  31), -INT8_C( 101),  INT8_C(  83),
         INT8_C(  74),  INT8_C(  53), -INT8_C(  19), -INT8_C( 100),  INT8_C(  57),  INT8_C( 112),  INT8_C(  69), -INT8_C(  41),
        -INT8_C( 117),  INT8_C(  61),  INT8_C(  28),  INT8_C(  16), -INT8_C(  82),  INT8_C(  26),  INT8_C( 122), -INT8_C(  62),
         INT8_C(  83), -INT8_C(  77), -INT8_C(   7), -INT8_C( 116), -INT8_C(  10), -INT8_C( 122),  INT8_C(  47),  INT8_C(  43),
         INT8_C( 109), -INT8_C(  79), -INT8_C(  75), -INT8_C(  81),  INT8_C(  16),  INT8_C(  55),  INT8_C(   1),  INT8_C(  29),
        -INT8_C(   5),  INT8_C(  26), -INT8_C(  14),  INT8_C(  53),  INT8_C( 105), -INT8_C(  71),  INT8_C(  12),  INT8_C(  70) } },
    { { -INT8_C(  26),  INT8_C(  50), -INT8_C(  81), -INT8_C(  29),  INT8_C(  47), -INT8_C(  95),  INT8_C(  35), -INT8_C(  80),
         INT8_C(  47), -INT8_C(  74),  INT8_C( 123),  INT8_C(  90), -INT8_C(  71), -INT8_C( 116),  INT8_C(  15), -INT8_C(   6),
         INT8_C(  23),  INT8_C( 120),  INT8_C(  50),  INT8_C(  40),  INT8_C(  77),  INT8_C(  27), -INT8_C(  23),  INT8_C(  90),
         INT8_C(  30), -INT8_C( 101), -INT8_C(  48),  INT8_C( 104), -INT8_C(  42), -INT8_C(  46),  INT8_C(  28), -INT8_C(  68),
         INT8_C(   4), -INT8_C(  53), -INT8_C(  97),  INT8_C(  52),  INT8_C( 109), -INT8_C(  62), -INT8_C(  28), -INT8_C( 100),
         INT8_C( 120),  INT8_C(  96), -INT8_C(  10),  INT8_C(  50), -INT8_C(  20),  INT8_C(   6),  INT8_C(  44),  INT8_C(   3),
         INT8_C( 126),  INT8_C(  94),  INT8_C(  43), -INT8_C(  53),  INT8_C( 121),  INT8_C(  20),  INT8_C(  37), -INT8_C( 104),
        -INT8_C(  80), -INT8_C(  11),  INT8_C(   0), -INT8_C( 122), -INT8_C(  56),  INT8_C(  28),  INT8_C(  67), -INT8_C(  52) },
      UINT64_C( 2157758194745664232),
      {  INT8_C(  69), -INT8_C(  24),  INT8_C(  79),  INT8_C(  49), -INT8_C(  18),  INT8_C( 124),  INT8_C(  52),  INT8_C( 108),
        -INT8_C(  38),  INT8_C(  95),  INT8_C(  55),  INT8_C(  84),  INT8_C( 116),  INT8_C(  93), -INT8_C(  20),  INT8_C(  36),
         INT8_C(  82), -INT8_C(  20), -INT8_C(  86),  INT8_C(  26),  INT8_C(   8), -INT8_C(  19), -INT8_C(  25), -INT8_C(  16),
        -INT8_C(  48), -INT8_C(  25),  INT8_C(  69),  INT8_C( 117), -INT8_C(  52),  INT8_C(  55), -INT8_C( 110),  INT8_C(  17),
         INT8_C(  31), -INT8_C(  30),  INT8_C(  66),  INT8_C(  13),  INT8_C(  94),  INT8_C( 118),  INT8_C( 121),  INT8_C(  56),
        -INT8_C(  42), -INT8_C(  80), -INT8_C( 116),  INT8_C(  74),  INT8_C(  13),  INT8_C( 120),  INT8_C( 110),  INT8_C(  96),
         INT8_C( 100),  INT8_C(  24),  INT8_C( 122),  INT8_C( 109),  INT8_C(   6),  INT8_C(  97),  INT8_C(  93), -INT8_C(  42),
         INT8_C(  73), -INT8_C(  93),  INT8_C(  75),  INT8_C(  21), -INT8_C(  38), -INT8_C(  35),  INT8_C(  39), -INT8_C(   7) },
      { -INT8_C(  26),  INT8_C(  50), -INT8_C(  81),  INT8_C(  69),  INT8_C(  47), -INT8_C(  24),  INT8_C(  79),  INT8_C(  49),
         INT8_C(  47), -INT8_C(  18),  INT8_C( 123),  INT8_C(  90), -INT8_C(  71),  INT8_C( 124),  INT8_C(  52),  INT8_C( 108),
         INT8_C(  23),  INT8_C( 120),  INT8_C(  50),  INT8_C(  40),  INT8_C(  77),  INT8_C(  27), -INT8_C(  23),  INT8_C(  90),
        -INT8_C(  38), -INT8_C( 101),  INT8_C(  95),  INT8_C( 104),  INT8_C(  55), -INT8_C(  46),  INT8_C(  84), -INT8_C(  68),
         INT8_C( 116), -INT8_C(  53),  INT8_C(  93),  INT8_C(  52),  INT8_C( 109), -INT8_C(  20), -INT8_C(  28),  INT8_C(  36),
         INT8_C(  82),  INT8_C(  96), -INT8_C(  20),  INT8_C(  50), -INT8_C(  20), -INT8_C(  86),  INT8_C(  26),  INT8_C(   8),
        -INT8_C(  19),  INT8_C(  94),  INT8_C(  43), -INT8_C(  53), -INT8_C(  25), -INT8_C(  16), -INT8_C(  48), -INT8_C(  25),
         INT8_C(  69), -INT8_C(  11),  INT8_C( 117), -INT8_C(  52),  INT8_C(  55),  INT8_C(  28),  INT8_C(  67), -INT8_C(  52) } },
    { { -INT8_C(  65),  INT8_C( 105),  INT8_C(   6),  INT8_C(  29), -INT8_C(  32),      INT8_MAX,  INT8_C(  86), -INT8_C(  74),
         INT8_C(  47), -INT8_C(  30),  INT8_C(   0),  INT8_C(  61),  INT8_C(  91),  INT8_C( 110), -INT8_C(  99), -INT8_C(  65),
        -INT8_C( 122),  INT8_C(  23),  INT8_C(  44), -INT8_C( 116),  INT8_C( 121), -INT8_C( 118),  INT8_C(  98), -INT8_C(  62),
         INT8_C(  45), -INT8_C(  83), -INT8_C(  41),  INT8_C(   7), -INT8_C( 117), -INT8_C(   2),  INT8_C(   0),  INT8_C(  74),
         INT8_C( 104),  INT8_C(   6),  INT8_C( 104),  INT8_C(  72), -INT8_C( 123), -INT8_C(  66), -INT8_C(   2), -INT8_C(  76),
        -INT8_C(  96), -INT8_C(   2), -INT8_C(  15), -INT8_C(   5),  INT8_C( 108), -INT8_C( 114), -INT8_C(  69), -INT8_C(  14),
        -INT8_C(  90), -INT8_C(  25),      INT8_MAX,  INT8_C(  31),  INT8_C( 113), -INT8_C(  31), -INT8_C(  31), -INT8_C(  98),
        -INT8_C( 113), -INT8_C(  72), -INT8_C(  91),  INT8_C(  26), -INT8_C(  73), -INT8_C(  91),  INT8_C( 100),  INT8_C(  31) },
      UINT64_C( 3163045957489642667),
      {  INT8_C(  99), -INT8_C(  42),  INT8_C(  38), -INT8_C(  49),  INT8_C( 101), -INT8_C(  31), -INT8_C(  63),  INT8_C(  11),
        -INT8_C(  55),  INT8_C(  64),  INT8_C(  42),  INT8_C(  58),  INT8_C(  34),  INT8_C(  11), -INT8_C(  39), -INT8_C(  79),
        -INT8_C(  61),  INT8_C( 126), -INT8_C(  53),  INT8_C( 122),  INT8_C(  36),  INT8_C(  47), -INT8_C( 103), -INT8_C(  49),
        -INT8_C(   4),  INT8_C(   0),  INT8_C(   0), -INT8_C( 122),  INT8_C( 101), -INT8_C(  27), -INT8_C(  79), -INT8_C(  56),
        -INT8_C(  69), -INT8_C(  40), -INT8_C( 105),  INT8_C(  32), -INT8_C(  71),  INT8_C(  89),  INT8_C(  43), -INT8_C( 126),
        -INT8_C( 103),  INT8_C(  85), -INT8_C(  67), -INT8_C(  69),  INT8_C(  96), -INT8_C( 106),  INT8_C( 108),  INT8_C(  36),
         INT8_C(  20),  INT8_C(  55), -INT8_C(  98),  INT8_C(  56),  INT8_C( 103),  INT8_C(  56),  INT8_C(   8),  INT8_C(  99),
         INT8_C(  56),  INT8_C(   8), -INT8_C(  23), -INT8_C(  98), -INT8_C(  19), -INT8_C( 101),  INT8_C( 102), -INT8_C(  88) },
      {  INT8_C(  99), -INT8_C(  42),  INT8_C(   6),  INT8_C(  38), -INT8_C(  32), -INT8_C(  49),  INT8_C(  86),  INT8_C( 101),
         INT8_C(  47), -INT8_C(  30), -INT8_C(  31), -INT8_C(  63),  INT8_C(  91),  INT8_C( 110),  INT8_C(  11), -INT8_C(  55),
         INT8_C(  64),  INT8_C(  42),  INT8_C(  58), -INT8_C( 116),  INT8_C( 121),  INT8_C(  34),  INT8_C(  11), -INT8_C(  62),
         INT8_C(  45), -INT8_C(  83), -INT8_C(  41),  INT8_C(   7), -INT8_C(  39), -INT8_C(  79),  INT8_C(   0),  INT8_C(  74),
         INT8_C( 104), -INT8_C(  61),  INT8_C( 104),  INT8_C( 126), -INT8_C( 123), -INT8_C(  66), -INT8_C(   2), -INT8_C(  53),
         INT8_C( 122), -INT8_C(   2),  INT8_C(  36), -INT8_C(   5),  INT8_C( 108),  INT8_C(  47), -INT8_C( 103), -INT8_C(  14),
        -INT8_C(  49), -INT8_C(  25), -INT8_C(   4),  INT8_C(  31),  INT8_C( 113),  INT8_C(   0),  INT8_C(   0), -INT8_C( 122),
         INT8_C( 101), -INT8_C(  27), -INT8_C(  91), -INT8_C(  79), -INT8_C(  73), -INT8_C(  56),  INT8_C( 100),  INT8_C(  31) } },
    { {  INT8_C( 115), -INT8_C(   2), -INT8_C(  55),  INT8_C(  44),  INT8_C(  87), -INT8_C(  12), -INT8_C(  81), -INT8_C(  16),
         INT8_C(  74),  INT8_C( 108), -INT8_C(  84), -INT8_C(  86),  INT8_C(   2),  INT8_C(  24), -INT8_C(  50),  INT8_C(  22),
         INT8_C(  80),  INT8_C( 109),  INT8_C(  79), -INT8_C(  73), -INT8_C(  91),  INT8_C(  87),  INT8_C(  26), -INT8_C(  35),
         INT8_C(  95),  INT8_C(   3),  INT8_C( 123),  INT8_C(  76), -INT8_C(  98), -INT8_C(  30), -INT8_C(  12),  INT8_C(  17),
        -INT8_C(  32), -INT8_C(  67),  INT8_C(  62),  INT8_C(  55), -INT8_C(  78), -INT8_C(  19),  INT8_C(  39), -INT8_C(   4),
         INT8_C(  89), -INT8_C(  45), -INT8_C(  90),  INT8_C(  91), -INT8_C(  20),  INT8_C( 117),  INT8_C( 113),  INT8_C(  60),
        -INT8_C(  30), -INT8_C(  64), -INT8_C(  13), -INT8_C( 121),  INT8_C(  23),  INT8_C(  13),  INT8_C( 100),  INT8_C( 118),
         INT8_C(  16), -INT8_C(  32), -INT8_C(  62), -INT8_C(  81), -INT8_C(  62), -INT8_C(  73), -INT8_C(  64), -INT8_C(  94) },
      UINT64_C( 4909487553756397172),
      { -INT8_C(  44), -INT8_C(  55), -INT8_C(  97), -INT8_C(  64),  INT8_C(  62),  INT8_C(  17), -INT8_C(   4),  INT8_C(  32),
        -INT8_C(  47), -INT8_C(  17), -INT8_C(  89), -INT8_C(  23), -INT8_C(   4),  INT8_C(  11),  INT8_C(  95),  INT8_C(  12),
        -INT8_C(  21),  INT8_C(  34), -INT8_C(  69), -INT8_C(  83), -INT8_C(  39),  INT8_C( 124),  INT8_C(  79),  INT8_C(  77),
         INT8_C( 122),  INT8_C(  40),  INT8_C( 116),  INT8_C( 102),  INT8_C(  41), -INT8_C( 106), -INT8_C(  86), -INT8_C(   3),
         INT8_C(  95),  INT8_C(  74), -INT8_C(  67), -INT8_C(  99),  INT8_C(  91), -INT8_C(  71), -INT8_C(  67),  INT8_C(  44),
        -INT8_C(  88),  INT8_C( 100),  INT8_C(  21), -INT8_C(  92),  INT8_C( 112),  INT8_C( 117), -INT8_C(  80),  INT8_C(  91),
        -INT8_C( 105),  INT8_C( 108),  INT8_C(   9),  INT8_C( 112), -INT8_C(  24),  INT8_C(  88), -INT8_C(  67),  INT8_C(  98),
        -INT8_C( 127),  INT8_C(  49), -INT8_C(  56), -INT8_C(  86), -INT8_C(  56),  INT8_C( 115), -INT8_C(  89),  INT8_C(  39) },
      {  INT8_C( 115), -INT8_C(   2), -INT8_C(  44),  INT8_C(  44), -INT8_C(  55), -INT8_C(  97), -INT8_C(  64), -INT8_C(  16),
         INT8_C(  74),  INT8_C(  62),  INT8_C(  17), -INT8_C(   4),  INT8_C(  32), -INT8_C(  47), -INT8_C(  17), -INT8_C(  89),
        -INT8_C(  23),  INT8_C( 109),  INT8_C(  79), -INT8_C(   4),  INT8_C(  11),  INT8_C(  87),  INT8_C(  95),  INT8_C(  12),
         INT8_C(  95), -INT8_C(  21),  INT8_C(  34),  INT8_C(  76), -INT8_C(  98), -INT8_C(  69), -INT8_C(  12),  INT8_C(  17),
        -INT8_C(  83), -INT8_C(  39),  INT8_C(  62),  INT8_C( 124), -INT8_C(  78),  INT8_C(  79),  INT8_C(  77),  INT8_C( 122),
         INT8_C(  89), -INT8_C(  45), -INT8_C(  90),  INT8_C(  91), -INT8_C(  20),  INT8_C( 117),  INT8_C( 113),  INT8_C(  60),
        -INT8_C(  30),  INT8_C(  40), -INT8_C(  13), -INT8_C( 121),  INT8_C(  23),  INT8_C( 116),  INT8_C( 100),  INT8_C( 118),
         INT8_C(  16), -INT8_C(  32),  INT8_C( 102), -INT8_C(  81), -INT8_C(  62), -INT8_C(  73),  INT8_C(  41), -INT8_C(  94) } },
    { { -INT8_C(  67),  INT8_C( 100), -INT8_C(  59),  INT8_C(  24),  INT8_C(  29), -INT8_C( 126),  INT8_C(  68), -INT8_C(  59),
        -INT8_C(  25),  INT8_C(  90),  INT8_C( 105),  INT8_C(  87), -INT8_C(  49),  INT8_C(  25), -INT8_C(  78),  INT8_C( 102),
        -INT8_C( 123), -INT8_C(  69), -INT8_C(  42),  INT8_C( 109),  INT8_C(  20), -INT8_C( 109), -INT8_C(  48), -INT8_C( 107),
        -INT8_C(  59), -INT8_C( 104),  INT8_C(  63), -INT8_C( 115),  INT8_C(  11), -INT8_C(  26), -INT8_C(  76), -INT8_C(  56),
         INT8_C(  74),  INT8_C( 121), -INT8_C(  32),  INT8_C( 103), -INT8_C(   4),  INT8_C(  37),  INT8_C(  44), -INT8_C(  29),
             INT8_MAX, -INT8_C( 107),  INT8_C(  58),  INT8_C(  78), -INT8_C(  82), -INT8_C(  20), -INT8_C(  76),  INT8_C(  52),
        -INT8_C(  88), -INT8_C( 118), -INT8_C(  95), -INT8_C(  68),  INT8_C(  29),  INT8_C( 113),  INT8_C(  81), -INT8_C(  30),
         INT8_C(  10), -INT8_C( 112),  INT8_C( 111),  INT8_C(  21),  INT8_C( 118),  INT8_C(  36), -INT8_C(  34), -INT8_C(  64) },
      UINT64_C( 7096639349821259421),
      { -INT8_C(  24), -INT8_C(  74), -INT8_C(  80), -INT8_C( 106), -INT8_C(  93),  INT8_C( 100), -INT8_C(  54),  INT8_C(  75),
        -INT8_C(  18),  INT8_C( 108),  INT8_C(   7),  INT8_C(  12), -INT8_C(  35),  INT8_C(  88), -INT8_C(  18), -INT8_C(  25),
        -INT8_C(  24),  INT8_C(  94), -INT8_C(   3),  INT8_C(  94), -INT8_C( 126), -INT8_C(  37),  INT8_C(  30),  INT8_C(  31),
        -INT8_C( 103),  INT8_C(  69), -INT8_C(  71),  INT8_C( 125), -INT8_C( 104),  INT8_C(  53), -INT8_C(  33),      INT8_MIN,
        -INT8_C(  20), -INT8_C( 112),  INT8_C(  22), -INT8_C( 113), -INT8_C(  12), -INT8_C(  31), -INT8_C(  38), -INT8_C(  29),
         INT8_C(  77), -INT8_C(  31), -INT8_C(  17),  INT8_C(  42),  INT8_C(  57), -INT8_C(  35),  INT8_C(  18),  INT8_C(  33),
         INT8_C(  59),  INT8_C(  15),      INT8_MAX, -INT8_C(  67), -INT8_C(  22), -INT8_C(  99), -INT8_C(  35), -INT8_C( 125),
        -INT8_C(  30), -INT8_C( 106),  INT8_C(   0),  INT8_C( 122), -INT8_C(  53), -INT8_C(  32), -INT8_C(   6), -INT8_C(  73) },
      { -INT8_C(  24),  INT8_C( 100), -INT8_C(  74), -INT8_C(  80), -INT8_C( 106), -INT8_C( 126),  INT8_C(  68), -INT8_C(  93),
        -INT8_C(  25),  INT8_C( 100), -INT8_C(  54),  INT8_C(  75), -INT8_C(  18),  INT8_C( 108), -INT8_C(  78),  INT8_C(   7),
         INT8_C(  12), -INT8_C(  35),  INT8_C(  88),  INT8_C( 109),  INT8_C(  20), -INT8_C(  18), -INT8_C(  48), -INT8_C( 107),
        -INT8_C(  25), -INT8_C( 104),  INT8_C(  63), -INT8_C(  24),  INT8_C(  94), -INT8_C(  26), -INT8_C(  76), -INT8_C(   3),
         INT8_C(  94), -INT8_C( 126), -INT8_C(  32),  INT8_C( 103), -INT8_C(   4), -INT8_C(  37),  INT8_C(  30),  INT8_C(  31),
        -INT8_C( 103),  INT8_C(  69),  INT8_C(  58),  INT8_C(  78), -INT8_C(  71), -INT8_C(  20),  INT8_C( 125),  INT8_C(  52),
        -INT8_C(  88), -INT8_C( 118), -INT8_C( 104),  INT8_C(  53), -INT8_C(  33),      INT8_MIN, -INT8_C(  20), -INT8_C(  30),
         INT8_C(  10), -INT8_C( 112),  INT8_C( 111),  INT8_C(  21),  INT8_C( 118),  INT8_C(  22), -INT8_C( 113), -INT8_C(  64) } },
    { {  INT8_C( 112),  INT8_C(  16),  INT8_C(  70),  INT8_C( 100), -INT8_C(  15),  INT8_C(  32),  INT8_C(  71),  INT8_C(  62),
         INT8_C(   1),  INT8_C(  54),  INT8_C( 105),  INT8_C(  58),  INT8_C(  20),  INT8_C( 123),  INT8_C(  91),  INT8_C(  79),
        -INT8_C( 118), -INT8_C(  38),  INT8_C(  13),  INT8_C( 116),  INT8_C( 119), -INT8_C(  22), -INT8_C(   9),  INT8_C(  89),
             INT8_MIN, -INT8_C(   8), -INT8_C(  45),  INT8_C(  75), -INT8_C(  40), -INT8_C(  51),  INT8_C(   3),  INT8_C(  72),
        -INT8_C(  34),  INT8_C(  73), -INT8_C(  84), -INT8_C(  49),  INT8_C( 106), -INT8_C(  12),  INT8_C(  14),  INT8_C( 107),
         INT8_C(  42),  INT8_C( 119), -INT8_C(  90),  INT8_C(  62), -INT8_C(  14),  INT8_C(   1), -INT8_C( 114),  INT8_C( 124),
        -INT8_C(  36), -INT8_C( 101), -INT8_C(  16),  INT8_C(  83), -INT8_C( 123), -INT8_C(  25), -INT8_C(  83),  INT8_C(   5),
        -INT8_C(  33),      INT8_MIN,  INT8_C(  80), -INT8_C(  73),  INT8_C(  78),  INT8_C(  83), -INT8_C(   1),  INT8_C(  44) },
      UINT64_C(14587732725939809437),
      {      INT8_MIN,  INT8_C(  24),  INT8_C(   9),  INT8_C( 114),  INT8_C(  26), -INT8_C( 105), -INT8_C(  18), -INT8_C(  10),
         INT8_C(  50), -INT8_C(  34),  INT8_C(  73), -INT8_C(  73), -INT8_C(  58), -INT8_C(  10), -INT8_C(  68), -INT8_C(  91),
         INT8_C( 119),  INT8_C(  12),  INT8_C(  93), -INT8_C(  59),  INT8_C(  96),  INT8_C(  92), -INT8_C(  15), -INT8_C(   3),
         INT8_C(   8), -INT8_C(  20),  INT8_C(   4), -INT8_C(  88), -INT8_C(  10),  INT8_C( 118),  INT8_C( 115),  INT8_C( 118),
        -INT8_C( 113),  INT8_C( 124), -INT8_C(  23), -INT8_C(  87),  INT8_C(  19), -INT8_C(  41), -INT8_C(  97),  INT8_C(  69),
        -INT8_C(  74), -INT8_C(  24), -INT8_C(   4),  INT8_C( 124), -INT8_C(  33), -INT8_C(  72),  INT8_C(  33),  INT8_C(  86),
        -INT8_C(  60),  INT8_C( 126),  INT8_C(  27),  INT8_C(  36), -INT8_C(  37),  INT8_C(  12),  INT8_C(  33), -INT8_C(  29),
        -INT8_C(   8),  INT8_C(  37), -INT8_C( 116), -INT8_C(  18), -INT8_C( 100), -INT8_C(   1),  INT8_C( 101),  INT8_C(  43) },
      {      INT8_MIN,  INT8_C(  16),  INT8_C(  24),  INT8_C(   9),  INT8_C( 114),  INT8_C(  32),  INT8_C(  71),  INT8_C(  26),
         INT8_C(   1),  INT8_C(  54), -INT8_C( 105), -INT8_C(  18),  INT8_C(  20), -INT8_C(  10),  INT8_C(  91),  INT8_C(  50),
        -INT8_C(  34),  INT8_C(  73),  INT8_C(  13), -INT8_C(  73), -INT8_C(  58), -INT8_C(  10), -INT8_C(  68), -INT8_C(  91),
         INT8_C( 119),  INT8_C(  12),  INT8_C(  93),  INT8_C(  75), -INT8_C(  40), -INT8_C(  51),  INT8_C(   3),  INT8_C(  72),
        -INT8_C(  34),  INT8_C(  73), -INT8_C(  84), -INT8_C(  49),  INT8_C( 106), -INT8_C(  59),  INT8_C(  14),  INT8_C(  96),
         INT8_C(  92),  INT8_C( 119), -INT8_C(  90), -INT8_C(  15), -INT8_C(  14),  INT8_C(   1), -INT8_C( 114),  INT8_C( 124),
        -INT8_C(  36), -INT8_C(   3), -INT8_C(  16),  INT8_C(  83),  INT8_C(   8), -INT8_C(  20),  INT8_C(   4),  INT8_C(   5),
        -INT8_C(  33), -INT8_C(  88),  INT8_C(  80), -INT8_C(  10),  INT8_C(  78),  INT8_C(  83),  INT8_C( 118),  INT8_C( 115) } },
    { {  INT8_C( 123),  INT8_C(  78), -INT8_C(  44), -INT8_C( 114),  INT8_C(  37),  INT8_C( 115), -INT8_C(  45), -INT8_C(  37),
         INT8_C(  91), -INT8_C(  49),  INT8_C(  87),  INT8_C(  58), -INT8_C( 121),  INT8_C( 121), -INT8_C( 112),  INT8_C(  75),
        -INT8_C(   9), -INT8_C(  85),  INT8_C( 112), -INT8_C(  46), -INT8_C(  73), -INT8_C( 111), -INT8_C(  74), -INT8_C(  80),
        -INT8_C(  73),  INT8_C(  66), -INT8_C(  98),  INT8_C(  83),  INT8_C(  65),  INT8_C(   3),  INT8_C( 126), -INT8_C(  68),
         INT8_C(  81),  INT8_C(  82),  INT8_C(  74),  INT8_C( 119), -INT8_C(  59),  INT8_C(  29),  INT8_C(  82),  INT8_C(  32),
        -INT8_C(  20), -INT8_C(  86),  INT8_C(  91),  INT8_C( 115),  INT8_C(  35), -INT8_C(  21), -INT8_C(  66),  INT8_C(  26),
        -INT8_C( 105),  INT8_C(  46), -INT8_C(  19),  INT8_C(  78), -INT8_C(  64), -INT8_C(  93), -INT8_C(   2),  INT8_C( 119),
        -INT8_C(  27), -INT8_C(  99), -INT8_C(  54),  INT8_C(  38), -INT8_C(  96),  INT8_C(  72), -INT8_C(  30), -INT8_C(  14) },
      UINT64_C( 3855005729860168858),
      {  INT8_C( 101), -INT8_C(  38), -INT8_C(  88), -INT8_C( 120), -INT8_C(  58),  INT8_C( 102), -INT8_C(  93),  INT8_C(  93),
        -INT8_C( 107), -INT8_C( 112), -INT8_C(  85),  INT8_C(  85),  INT8_C(  51), -INT8_C(  86), -INT8_C(  52),  INT8_C(  24),
         INT8_C(  71), -INT8_C( 106),  INT8_C(  62), -INT8_C(  25), -INT8_C(  34),  INT8_C(  32), -INT8_C(  39),  INT8_C( 120),
         INT8_C(  76),  INT8_C(  66), -INT8_C(  41), -INT8_C( 107), -INT8_C(   2),  INT8_C(  86), -INT8_C(  54),  INT8_C(  99),
         INT8_C(  49),  INT8_C( 114), -INT8_C(  20), -INT8_C(   9), -INT8_C(  40), -INT8_C( 113),  INT8_C(  84),  INT8_C( 109),
         INT8_C(  31), -INT8_C(   1), -INT8_C(  62),  INT8_C(  82), -INT8_C(  87), -INT8_C( 114),  INT8_C( 106), -INT8_C(  16),
         INT8_C(  36), -INT8_C(  88), -INT8_C(  40),  INT8_C(   2), -INT8_C(  56), -INT8_C(  79),  INT8_C( 122),  INT8_C(  20),
        -INT8_C(  12),  INT8_C(  81), -INT8_C(  87), -INT8_C(  14), -INT8_C(  88),  INT8_C( 115),  INT8_C(  85), -INT8_C(  39) },
      {  INT8_C( 123),  INT8_C( 101), -INT8_C(  44), -INT8_C(  38), -INT8_C(  88),  INT8_C( 115), -INT8_C(  45), -INT8_C( 120),
         INT8_C(  91), -INT8_C(  49), -INT8_C(  58),  INT8_C( 102), -INT8_C( 121), -INT8_C(  93), -INT8_C( 112),  INT8_C(  75),
         INT8_C(  93), -INT8_C(  85),  INT8_C( 112), -INT8_C( 107), -INT8_C(  73), -INT8_C( 112), -INT8_C(  85), -INT8_C(  80),
         INT8_C(  85),  INT8_C(  51), -INT8_C(  86), -INT8_C(  52),  INT8_C(  24),  INT8_C(   3),  INT8_C(  71), -INT8_C(  68),
        -INT8_C( 106),  INT8_C(  82),  INT8_C(  74),  INT8_C(  62), -INT8_C(  59),  INT8_C(  29), -INT8_C(  25),  INT8_C(  32),
        -INT8_C(  34),  INT8_C(  32),  INT8_C(  91), -INT8_C(  39),  INT8_C( 120),  INT8_C(  76), -INT8_C(  66),  INT8_C(  66),
        -INT8_C(  41), -INT8_C( 107), -INT8_C(   2),  INT8_C(  86), -INT8_C(  54),  INT8_C(  99),  INT8_C(  49),  INT8_C( 119),
         INT8_C( 114), -INT8_C(  99), -INT8_C(  20),  INT8_C(  38), -INT8_C(   9), -INT8_C(  40), -INT8_C(  30), -INT8_C(  14) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i src = simde_mm512_loadu_epi8(test_vec[i].src);
    simde__mmask64 k = test_vec[i].k;
    simde__m512i r = simde_mm512_mask_expandloadu_epi8(src, k, test_vec[i].mem_addr);
    simde_test_x86_assert_equal_i8x64(r, simde_mm512_loadu_epi8(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_mm512_maskz_expandloadu_epi8 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const simde__mmask64 k;
    SIMDE_ALIGN_LIKE_64(simde__m512i) const int8_t mem_addr[64];
    const int8_t r[64];
  } test_vec[] = {
    { UINT64_C(17233908878019674597),
      {  INT8_C(  35), -INT8_C(  19),  INT8_C(  65), -INT8_C(  51),  INT8_C( 124), -INT8_C(  85), -INT8_C(  67), -INT8_C(  96),
         INT8_C(  83), -INT8_C( 107), -INT8_C(  93),  INT8_C(  27),  INT8_C(  71),  INT8_C(  29),  INT8_C(  47),  INT8_C(  59),
         INT8_C( 111), -INT8_C(  40),  INT8_C(  45),  INT8_C(  23),  INT8_C(  75), -INT8_C( 126), -INT8_C(  16),  INT8_C(  48),
        -INT8_C(  60), -INT8_C(  64), -INT8_C(  18), -INT8_C( 108), -INT8_C(  28),  INT8_C(  25), -INT8_C( 124),  INT8_C(   7),
         INT8_C(   6), -INT8_C(  59), -INT8_C(  44), -INT8_C( 126),  INT8_C( 113), -INT8_C( 110),  INT8_C(  35), -INT8_C(  60),
         INT8_C(  39), -INT8_C(  58), -INT8_C(  32),  INT8_C( 110), -INT8_C(  29),  INT8_C(  15), -INT8_C(  87),  INT8_C(  82),
        -INT8_C(  24), -INT8_C(  42),  INT8_C( 105),  INT8_C(  51),  INT8_C(  89),  INT8_C(  89),  INT8_C( 100),  INT8_C(  29),
         INT8_C(  25),  INT8_C(  82), -INT8_C(  79), -INT8_C(   3),  INT8_C( 107),  INT8_C(  53),  INT8_C(   5),  INT8_C( 113) },
      {  INT8_C(  35),  INT8_C(   0), -INT8_C(  19),  INT8_C(   0),  INT8_C(   0),  INT8_C(  65), -INT8_C(  51),  INT8_C( 124),
        -INT8_C(  85),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  67),  INT8_C(   0),
         INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  96),  INT8_C(   0),  INT8_C(  83), -INT8_C( 107),
        -INT8_C(  93),  INT8_C(   0),  INT8_C(  27),  INT8_C(  71),  INT8_C(  29),  INT8_C(  47),  INT8_C(   0),  INT8_C(  59),
         INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C( 111),  INT8_C(   0), -INT8_C(  40),  INT8_C(  45),
         INT8_C(   0),  INT8_C(   0),  INT8_C(  23),  INT8_C(   0),  INT8_C(   0),  INT8_C(  75),  INT8_C(   0),  INT8_C(   0),
        -INT8_C( 126), -INT8_C(  16),  INT8_C(   0),  INT8_C(  48),  INT8_C(   0), -INT8_C(  60),  INT8_C(   0),  INT8_C(   0),
        -INT8_C(  64), -INT8_C(  18), -INT8_C( 108), -INT8_C(  28),  INT8_C(   0),  INT8_C(  25), -INT8_C( 124),  INT8_C(   7) } },
    { UINT64_C(10606002872614443515),
      { -INT8_C(  35),  INT8_C(  16),  INT8_C(   1), -INT8_C(  64),  INT8_C(  32), -INT8_C(  85),  INT8_C(  19),  INT8_C(   8),
        -INT8_C( 127),  INT8_C( 124),  INT8_C(  59), -INT8_C(  38), -INT8_C(  42), -INT8_C(  97), -INT8_C(   9), -INT8_C(  17),
        -INT8_C(  15), -INT8_C(  87), -INT8_C(  19),  INT8_C(  92), -INT8_C(  34), -INT8_C(  14), -INT8_C(  50), -INT8_C(  39),
        -INT8_C(  53), -INT8_C(  62),  INT8_C(  69),  INT8_C(  55), -INT8_C(  39),  INT8_C( 118), -INT8_C(  54), -INT8_C(  74),
        -INT8_C( 122), -INT8_C(  53),  INT8_C( 118), -INT8_C(  90),  INT8_C( 118), -INT8_C( 119), -INT8_C(  82), -INT8_C(   8),
         INT8_C(   6), -INT8_C(  22), -INT8_C(  46), -INT8_C(  36), -INT8_C( 119), -INT8_C(  54), -INT8_C(  53),  INT8_C( 123),
         INT8_C( 115), -INT8_C(  72), -INT8_C(  41),  INT8_C(  81), -INT8_C(  86), -INT8_C(  91),  INT8_C(  43),  INT8_C( 118),
         INT8_C( 103),  INT8_C( 112), -INT8_C(  83),  INT8_C(  64), -INT8_C(  26),  INT8_C( 119), -INT8_C(  10),  INT8_C( 109) },
      { -INT8_C(  35),  INT8_C(  16),  INT8_C(   0),  INT8_C(   1), -INT8_C(  64),  INT8_C(  32), -INT8_C(  85),  INT8_C(  19),
         INT8_C(   8),  INT8_C(   0),  INT8_C(   0), -INT8_C( 127),  INT8_C( 124),  INT8_C(   0),  INT8_C(  59), -INT8_C(  38),
         INT8_C(   0),  INT8_C(   0), -INT8_C(  42),  INT8_C(   0), -INT8_C(  97), -INT8_C(   9), -INT8_C(  17), -INT8_C(  15),
         INT8_C(   0),  INT8_C(   0), -INT8_C(  87), -INT8_C(  19),  INT8_C(   0),  INT8_C(  92), -INT8_C(  34),  INT8_C(   0),
        -INT8_C(  14), -INT8_C(  50),  INT8_C(   0), -INT8_C(  39),  INT8_C(   0), -INT8_C(  53), -INT8_C(  62),  INT8_C(   0),
         INT8_C(  69),  INT8_C(  55), -INT8_C(  39),  INT8_C(   0),  INT8_C( 118),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
         INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  54), -INT8_C(  74),  INT8_C(   0),  INT8_C(   0),
        -INT8_C( 122), -INT8_C(  53),  INT8_C(   0),  INT8_C(   0),  INT8_C( 118),  INT8_C(   0),  INT8_C(   0), -INT8_C(  90) } },
    { UINT64_C(18208549133358427458),
      { -INT8_C(  84), -INT8_C( 125), -INT8_C(  40),  INT8_C(  53),  INT8_C(  77), -INT8_C(  92), -INT8_C(  80), -INT8_C(  64),
         INT8_C(  92), -INT8_C( 120),  INT8_C(  18),  INT8_C(   7),  INT8_C(  45),  INT8_C(  61),  INT8_C( 125), -INT8_C( 107),
        -INT8_C(  83),  INT8_C(  42), -INT8_C(  43), -INT8_C( 108), -INT8_C(  95), -INT8_C(  52),  INT8_C(   1), -INT8_C(  29),
         INT8_C(  57),  INT8_C(  20), -INT8_C( 100),  INT8_C(  47), -INT8_C(  42),  INT8_C(  77),  INT8_C(  44), -INT8_C( 126),
        -INT8_C(  47),  INT8_C(   4), -INT8_C(  72),  INT8_C(  30), -INT8_C(  88),  INT8_C( 104), -INT8_C(  33),  INT8_C(   5),
        -INT8_C(  16), -INT8_C(  15),  INT8_C(  12),  INT8_C(  30),  INT8_C(  46), -INT8_C( 119), -INT8_C(  77), -INT8_C(  37),
        -INT8_C(  77), -INT8_C( 120),  INT8_C( 111),  INT8_C(  84),  INT8_C(  84),  INT8_C( 112),  INT8_C(  55), -INT8_C( 115),
        -INT8_C( 123), -INT8_C(  44), -INT8_C(  67),  INT8_C(  91),  INT8_C(  33), -INT8_C(  23), -INT8_C(  34), -INT8_C(  14) },
      {  INT8_C(   0), -INT8_C(  84),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C( 125),  INT8_C(   0),
        -INT8_C(  40),  INT8_C(   0),  INT8_C(  53),  INT8_C(  77),  INT8_C(   0), -INT8_C(  92), -INT8_C(  80),  INT8_C(   0),
        -INT8_C(  64),  INT8_C(  92),  INT8_C(   0),  INT8_C(   0), -INT8_C( 120),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
         INT8_C(  18),  INT8_C(   0),  INT8_C(   0),  INT8_C(   7),  INT8_C(  45),  INT8_C(  61),  INT8_C(   0),  INT8_C( 125),
         INT8_C(   0), -INT8_C( 107), -INT8_C(  83),  INT8_C(   0),  INT8_C(  42), -INT8_C(  43), -INT8_C( 108), -INT8_C(  95),
         INT8_C(   0), -INT8_C(  52),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   1), -INT8_C(  29),
         INT8_C(  57),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(  20), -INT8_C( 100),  INT8_C(   0),  INT8_C(  47),
         INT8_C(   0),  INT8_C(   0), -INT8_C(  42),  INT8_C(  77),  INT8_C(  44), -INT8_C( 126), -INT8_C(  47),  INT8_C(   4) } },
    { UINT64_C(17265658572685022957),
      { -INT8_C(  31), -INT8_C(  89),  INT8_C(  13),  INT8_C(  15),  INT8_C(  48), -INT8_C(  64), -INT8_C(  22), -INT8_C(  29),
         INT8_C(  72),  INT8_C(  90),  INT8_C(  55), -INT8_C(  99), -INT8_C(  54),  INT8_C( 110),  INT8_C(  42),  INT8_C(  79),
         INT8_C(  66), -INT8_C(  25), -INT8_C(  85),  INT8_C( 100), -INT8_C(  48), -INT8_C( 119),  INT8_C(  86), -INT8_C(  66),
         INT8_C(  31),  INT8_C( 103),  INT8_C(  84),  INT8_C(  29),  INT8_C(  87), -INT8_C(  17),  INT8_C(  12),  INT8_C(  56),
        -INT8_C( 106),  INT8_C(  25),  INT8_C(  71), -INT8_C(  58), -INT8_C(  39),  INT8_C(  50), -INT8_C(  87),  INT8_C(  34),
        -INT8_C( 116), -INT8_C(  32), -INT8_C(  65),  INT8_C(  86),  INT8_C(  78), -INT8_C(  23), -INT8_C(  90), -INT8_C( 111),
        -INT8_C(  47),  INT8_C(  81), -INT8_C(  11), -INT8_C(  95), -INT8_C(  38),  INT8_C(  75),  INT8_C(  95), -INT8_C(   7),
        -INT8_C(  77), -INT8_C(  77),  INT8_C(  22),  INT8_C(  10), -INT8_C(  94),  INT8_C(  35),  INT8_C(  67),  INT8_C(  56) },
      { -INT8_C(  31),  INT8_C(   0), -INT8_C(  89),  INT8_C(  13),  INT8_C(   0),  INT8_C(  15),  INT8_C(  48), -INT8_C(  64),
         INT8_C(   0), -INT8_C(  22), -INT8_C(  29),  INT8_C(   0),  INT8_C(  72),  INT8_C(   0),  INT8_C(   0),  INT8_C(  90),
         INT8_C(  55),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  99),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
         INT8_C(   0), -INT8_C(  54),  INT8_C( 110),  INT8_C(   0),  INT8_C(  42),  INT8_C(   0),  INT8_C(   0),  INT8_C(  79),
         INT8_C(   0),  INT8_C(  66), -INT8_C(  25), -INT8_C(  85),  INT8_C( 100), -INT8_C(  48), -INT8_C( 119),  INT8_C(  86),
         INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  66),  INT8_C(  31),  INT8_C( 103),  INT8_C(  84),
         INT8_C(  29),  INT8_C(  87),  INT8_C(   0), -INT8_C(  17),  INT8_C(  12),  INT8_C(   0),  INT8_C(   0),  INT8_C(  56),
        -INT8_C( 106),  INT8_C(  25),  INT8_C(  71), -INT8_C(  58),  INT8_C(   0), -INT8_C(  39),  INT8_C(  50), -INT8_C(  87) } },
    { UINT64_C( 5204093795708078652),
      { -INT8_C( 121), -INT8_C(   9), -INT8_C(  97), -INT8_C(  42), -INT8_C(  32),  INT8_C(  69),  INT8_C( 103), -INT8_C(  79),
        -INT8_C( 106),  INT8_C(  92),  INT8_C(  83),  INT8_C( 112), -INT8_C(  89), -INT8_C(  78),  INT8_C( 105),  INT8_C(  90),
         INT8_C( 102),      INT8_MAX,  INT8_C( 101),  INT8_C(   8), -INT8_C(  94), -INT8_C(  88),  INT8_C(  65), -INT8_C(  33),
         INT8_C(  50),  INT8_C(  63), -INT8_C(  11), -INT8_C(  17), -INT8_C(  25),  INT8_C(  45),  INT8_C(  55),  INT8_C( 110),
         INT8_C(  36), -INT8_C(  42),  INT8_C(  68),  INT8_C(   4),  INT8_C(  27), -INT8_C(  85), -INT8_C(  74), -INT8_C(  79),
         INT8_C(   7),  INT8_C(   9),  INT8_C(  33), -INT8_C(  81), -INT8_C(  69), -INT8_C( 118),  INT8_C(   9),  INT8_C(  33),
         INT8_C(  10),  INT8_C( 110),  INT8_C(  42), -INT8_C(  84),  INT8_C(  22),  INT8_C( 107), -INT8_C( 117),  INT8_C(  73),
        -INT8_C(  86),      INT8_MIN,  INT8_C(  56), -INT8_C( 111), -INT8_C(  83),  INT8_C( 111),  INT8_C(   0), -INT8_C(  47) },
      {  INT8_C(   0),  INT8_C(   0), -INT8_C( 121), -INT8_C(   9), -INT8_C(  97), -INT8_C(  42),  INT8_C(   0),  INT8_C(   0),
         INT8_C(   0), -INT8_C(  32),  INT8_C(   0),  INT8_C(  69),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C( 103),
         INT8_C(   0), -INT8_C(  79), -INT8_C( 106),  INT8_C(  92),  INT8_C(  83),  INT8_C( 112), -INT8_C(  89), -INT8_C(  78),
         INT8_C(   0),  INT8_C( 105),  INT8_C(  90),  INT8_C(   0),  INT8_C( 102),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
         INT8_C(   0),  INT8_C(   0),      INT8_MAX,  INT8_C( 101),  INT8_C(   8), -INT8_C(  94),  INT8_C(   0), -INT8_C(  88),
         INT8_C(  65), -INT8_C(  33),  INT8_C(  50),  INT8_C(   0),  INT8_C(   0),  INT8_C(  63),  INT8_C(   0), -INT8_C(  11),
         INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  17), -INT8_C(  25),  INT8_C(  45),  INT8_C(   0),  INT8_C(   0),
         INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(  55),  INT8_C(   0),  INT8_C(   0),  INT8_C( 110),  INT8_C(   0) } },
    { UINT64_C(17803728715987174470),
      { -INT8_C( 107),  INT8_C(  52), -INT8_C(  90),  INT8_C(  80), -INT8_C(  65), -INT8_C(  80),  INT8_C( 114), -INT8_C(  55),
         INT8_C(  30), -INT8_C( 100),  INT8_C( 117),  INT8_C(  53),  INT8_C(   7),  INT8_C(   1),  INT8_C( 126), -INT8_C(  79),
        -INT8_C( 127), -INT8_C(  74),  INT8_C(  67),  INT8_C(  47),  INT8_C(  37),  INT8_C(  67),  INT8_C(   0),  INT8_C( 107),
        -INT8_C( 121), -INT8_C(  42), -INT8_C(  51),  INT8_C( 119),  INT8_C(  98), -INT8_C(  32),  INT8_C( 111), -INT8_C(   9),
         INT8_C(  20),  INT8_C(  21),  INT8_C(  72), -INT8_C(  45), -INT8_C(  59), -INT8_C(  70), -INT8_C( 100), -INT8_C(  28),
         INT8_C(  86),  INT8_C(  18),  INT8_C(  25),  INT8_C(  93),  INT8_C(  19), -INT8_C( 105),  INT8_C(  14), -INT8_C( 108),
         INT8_C(  77),  INT8_C(  81), -INT8_C(  61),  INT8_C( 114), -INT8_C( 108), -INT8_C(  60), -INT8_C(  34),  INT8_C(  28),
        -INT8_C( 102), -INT8_C(  85), -INT8_C( 109), -INT8_C(   3), -INT8_C( 117),  INT8_C(   2), -INT8_C(  12), -INT8_C(  97) },
      {  INT8_C(   0), -INT8_C( 107),  INT8_C(  52),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  90),  INT8_C(   0),
         INT8_C(   0),  INT8_C(   0),  INT8_C(  80),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  65),  INT8_C(   0),
         INT8_C(   0), -INT8_C(  80),  INT8_C( 114),  INT8_C(   0), -INT8_C(  55),  INT8_C(   0),  INT8_C(  30), -INT8_C( 100),
         INT8_C( 117),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(  53),  INT8_C(   7),  INT8_C(   0),
         INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   1),  INT8_C( 126), -INT8_C(  79), -INT8_C( 127),
         INT8_C(   0),  INT8_C(   0), -INT8_C(  74),  INT8_C(  67),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(  47),
         INT8_C(  37),  INT8_C(  67),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
         INT8_C( 107), -INT8_C( 121), -INT8_C(  42),  INT8_C(   0), -INT8_C(  51),  INT8_C( 119),  INT8_C(  98), -INT8_C(  32) } },
    { UINT64_C( 5530719370339367960),
      {  INT8_C(  33), -INT8_C(  38), -INT8_C(  87),  INT8_C(  52),  INT8_C( 113), -INT8_C(  72), -INT8_C(  55), -INT8_C(  66),
         INT8_C(   9), -INT8_C( 116),  INT8_C(  49), -INT8_C(  98),  INT8_C(  80),  INT8_C(  15), -INT8_C(  70), -INT8_C(  21),
        -INT8_C(  70),  INT8_C(  77), -INT8_C(  24),  INT8_C(  69),  INT8_C(  80), -INT8_C(  36), -INT8_C(  28),  INT8_C( 104),
         INT8_C(  25),  INT8_C(  87),  INT8_C(  69),  INT8_C(  15),  INT8_C( 103),  INT8_C(   7),  INT8_C(  92), -INT8_C( 120),
        -INT8_C(  31),  INT8_C(   5), -INT8_C(  67),  INT8_C(  83), -INT8_C(  67), -INT8_C( 122),  INT8_C(  17), -INT8_C(  57),
         INT8_C(  18),  INT8_C(  66),  INT8_C( 101),  INT8_C(  99),  INT8_C(  81),  INT8_C(  31),  INT8_C(  78),  INT8_C(  11),
         INT8_C( 108),  INT8_C(  54),  INT8_C(  80), -INT8_C(  68),  INT8_C(  18),  INT8_C(  53),  INT8_C(  36),  INT8_C(  43),
        -INT8_C( 116),  INT8_C( 106),  INT8_C(  59), -INT8_C(  13),  INT8_C( 113), -INT8_C( 105),  INT8_C( 124),  INT8_C(  82) },
      {  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(  33), -INT8_C(  38),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
         INT8_C(   0),  INT8_C(   0), -INT8_C(  87),  INT8_C(  52),  INT8_C( 113), -INT8_C(  72),  INT8_C(   0),  INT8_C(   0),
        -INT8_C(  55), -INT8_C(  66),  INT8_C(   0),  INT8_C(   0),  INT8_C(   9), -INT8_C( 116),  INT8_C(  49),  INT8_C(   0),
        -INT8_C(  98),  INT8_C(   0),  INT8_C(  80),  INT8_C(  15), -INT8_C(  70),  INT8_C(   0), -INT8_C(  21), -INT8_C(  70),
         INT8_C(   0),  INT8_C(  77), -INT8_C(  24),  INT8_C(   0),  INT8_C(  69),  INT8_C(  80), -INT8_C(  36), -INT8_C(  28),
         INT8_C( 104),  INT8_C(  25),  INT8_C(  87),  INT8_C(  69),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
         INT8_C(  15),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C( 103),  INT8_C(   7),
         INT8_C(   0),  INT8_C(   0),  INT8_C(  92), -INT8_C( 120),  INT8_C(   0),  INT8_C(   0), -INT8_C(  31),  INT8_C(   0) } },
    { UINT64_C(15069527860645804444),
      { -INT8_C(   7), -INT8_C( 122),  INT8_C(  52),  INT8_C(  75), -INT8_C(  91), -INT8_C( 126),  INT8_C(  86),  INT8_C(  17),
        -INT8_C(  72), -INT8_C(  89), -INT8_C(  50), -INT8_C(  53), -INT8_C(  36), -INT8_C(  14), -INT8_C(  10),  INT8_C( 104),
         INT8_C(  92),  INT8_C(  49),  INT8_C(  92), -INT8_C(  51), -INT8_C(  56), -INT8_C(  40),  INT8_C(  32),  INT8_C( 101),
         INT8_C(  17), -INT8_C(  59), -INT8_C(  65), -INT8_C(  48),  INT8_C( 124), -INT8_C(  32), -INT8_C(  95),  INT8_C( 118),
         INT8_C( 102), -INT8_C(  42), -INT8_C(  63),  INT8_C(  11),  INT8_C(  88),  INT8_C(  23),  INT8_C(  28),  INT8_C(  17),
        -INT8_C(  66), -INT8_C(  22), -INT8_C(  36), -INT8_C( 102), -INT8_C(  35), -INT8_C(  46),  INT8_C(   3),  INT8_C(  57),
         INT8_C(   4),  INT8_C(  95),  INT8_C(   7), -INT8_C(  52),  INT8_C(  55),  INT8_C(  39),  INT8_C(  49),  INT8_C(  72),
        -INT8_C(  20), -INT8_C(  16),  INT8_C(  24),  INT8_C( 105), -INT8_C(  48), -INT8_C(  71), -INT8_C(  33),  INT8_C(  54) },
      {  INT8_C(   0),  INT8_C(   0), -INT8_C(   7), -INT8_C( 122),  INT8_C(  52),  INT8_C(   0),  INT8_C(   0),  INT8_C(  75),
        -INT8_C(  91),  INT8_C(   0),  INT8_C(   0), -INT8_C( 126),  INT8_C(  86),  INT8_C(  17),  INT8_C(   0),  INT8_C(   0),
        -INT8_C(  72),  INT8_C(   0), -INT8_C(  89),  INT8_C(   0),  INT8_C(   0), -INT8_C(  50),  INT8_C(   0), -INT8_C(  53),
         INT8_C(   0), -INT8_C(  36),  INT8_C(   0), -INT8_C(  14), -INT8_C(  10),  INT8_C(   0),  INT8_C( 104),  INT8_C(   0),
         INT8_C(  92),  INT8_C(  49),  INT8_C(  92), -INT8_C(  51), -INT8_C(  56), -INT8_C(  40),  INT8_C(   0),  INT8_C(  32),
         INT8_C( 101),  INT8_C(  17), -INT8_C(  59),  INT8_C(   0), -INT8_C(  65), -INT8_C(  48),  INT8_C(   0),  INT8_C( 124),
        -INT8_C(  32),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  95),  INT8_C(   0),  INT8_C(   0),
         INT8_C( 118),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C( 102),  INT8_C(   0), -INT8_C(  42), -INT8_C(  63) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__mmask64 k = test_vec[i].k;
    simde__m512i r = simde_mm512_maskz_expandloadu_epi8(k, test_vec[i].mem_addr);
    simde_test_x86_assert_equal_i8x64(r, simde_mm512_loadu_epi8(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_mm_mask_expandloadu_epi16 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const int16_t src[8];
    const simde__mmask8 k;
    SIMDE_ALIGN_LIKE_64(simde__m128i) const int16_t mem_addr[8];
    const int16_t r[8];
  } test_vec[] = {
    { { -INT16_C( 24433), -INT16_C(  6079),  INT16_C( 24247),  INT16_C( 30457), -INT16_C( 10936),  INT16_C(  9488),  INT16_C(  5031), -INT16_C( 21665) },
      UINT8_C(114),
      {  INT16_C( 30822), -INT16_C( 29271), -INT16_C(  3671), -INT16_C( 25991), -INT16_C(  7671), -INT16_C( 15510), -INT16_C( 24127),  INT16_C( 24914) },
      { -INT16_C( 24433),  INT16_C( 30822),  INT16_C( 24247),  INT16_C( 30457), -INT16_C( 29271), -INT16_C(  3671), -INT16_C( 25991), -INT16_C( 21665) } },
    { {  INT16_C( 15074),  INT16_C( 16409), -INT16_C( 28877),  INT16_C(  2185), -INT16_C( 20833), -INT16_C( 19536),  INT16_C( 23309),  INT16_C( 29477) },
      UINT8_C(211),
      {  INT16_C(   207), -INT16_C( 16259),  INT16_C(  6010),  INT16_C( 23754), -INT16_C( 29311),  INT16_C(  8734),  INT16_C( 32735),  INT16_C(  6661) },
      {  INT16_C(   207), -INT16_C( 16259), -INT16_C( 28877),  INT16_C(  2185),  INT16_C(  6010), -INT16_C( 19536),  INT16_C( 23754), -INT16_C( 29311) } },
    { {  INT16_C( 17816),  INT16_C( 10061),  INT16_C( 22222),  INT16_C( 32199),  INT16_C( 31238),  INT16_C( 24970), -INT16_C(   353),  INT16_C( 28213) },
      UINT8_C(254),
      {  INT16_C( 12210), -INT16_C( 13960), -INT16_C( 10759), -INT16_C( 31158),  INT16_C( 28147),  INT16_C( 29285),  INT16_C( 32626), -INT16_C( 18677) },
      {  INT16_C( 17816),  INT16_C( 12210), -INT16_C( 13960), -INT16_C( 10759), -INT16_C( 31158),  INT16_C( 28147),  INT16_C( 29285),  INT16_C( 32626) } },
    { {  INT16_C( 13005),  INT16_C(  9094),  INT16_C(  1017),  INT16_C( 29481), -INT16_C( 30067), -INT16_C( 29933), -INT16_C( 32321),  INT16_C( 29066) },
      UINT8_C(176),
      {  INT16_C( 14850), -INT16_C( 10327),  INT16_C( 12165), -INT16_C(  3382),  INT16_C( 15765),  INT16_C(  5220),  INT16_C(  6984),  INT16_C( 31457) },
      {  INT16_C( 13005),  INT16_C(  9094),  INT16_C(  1017),  INT16_C( 29481),  INT16_C( 14850), -INT16_C( 10327), -INT16_C( 32321),  INT16_C( 12165) } },
    { {  INT16_C(  1185), -INT16_C( 23436), -INT16_C(  6355), -INT16_C( 18382), -INT16_C( 16902),  INT16_C( 31863), -INT16_C(  5817),  INT16_C( 18988) },
      UINT8_C( 35),
      {  INT16_C(  8662),  INT16_C(  1448), -INT16_C( 25876),  INT16_C( 10650), -INT16_C( 20482),  INT16_C(  6769), -INT16_C(  5232), -INT16_C( 27205) },
      {  INT16_C(  8662),  INT16_C(  1448), -INT16_C(  6355), -INT16_C( 18382), -INT16_C( 16902), -INT16_C( 25876), -INT16_C(  5817),  INT16_C( 18988) } },
    { {  INT16_C( 24671),  INT16_C( 18370),  INT16_C( 31378),  INT16_C( 20289), -INT16_C( 16910), -INT16_C(  9321), -INT16_C(  7702), -INT16_C( 16130) },
      UINT8_C(  2),
      { -INT16_C( 14937),  INT16_C( 16878),  INT16_C(  5984),  INT16_C(  3904),  INT16_C( 23176),  INT16_C( 29855),  INT16_C( 13333),  INT16_C( 30163) },
      {  INT16_C( 24671), -INT16_C( 14937),  INT16_C( 31378),  INT16_C( 20289), -INT16_C( 16910), -INT16_C(  9321), -INT16_C(  7702), -INT16_C( 16130) } },
    { {  INT16_C(  6903),  INT16_C( 28935),  INT16_C( 22364),  INT16_C(  6499),  INT16_C( 16110), -INT16_C( 12541), -INT16_C( 15555), -INT16_C(  6959) },
      UINT8_C(137),
      {  INT16_C(  9664), -INT16_C( 10263), -INT16_C(  1947), -INT16_C( 16544), -INT16_C( 11113), -INT16_C( 13099),  INT16_C( 19111), -INT16_C( 15677) },
      {  INT16_C(  9664),  INT16_C( 28935),  INT16_C( 22364), -INT16_C( 10263),  INT16_C( 16110), -INT16_C( 12541), -INT16_C( 15555), -INT16_C(  1947) } },
    { {  INT16_C( 13394), -INT16_C( 22242),  INT16_C( 14232), -INT16_C( 10601),  INT16_C( 26171), -INT16_C(   493), -INT16_C(  2249), -INT16_C(  2169) },
      UINT8_C( 29),
      { -INT16_C( 12432),  INT16_C( 26754),  INT16_C( 16943),  INT16_C(   768), -INT16_C( 13289),  INT16_C( 25002),  INT16_C( 27791), -INT16_C( 15437) },
      { -INT16_C( 12432), -INT16_C( 22242),  INT16_C( 26754),  INT16_C( 16943),  INT16_C(   768), -INT16_C(   493), -INT16_C(  2249), -INT16_C(  2169) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i src = simde_mm_loadu_epi16(test_vec[i].src);
    simde__mmask8 k = test_vec[i].k;
    simde__m128i r = simde_mm_mask_expandloadu_epi16(src, k, test_vec[i].mem_addr);
    simde_test_x86_assert_equal_i16x8(r, simde_mm_loadu_epi16(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_mm_maskz_expandloadu_epi16 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const simde__mmask8 k;
    SIMDE_ALIGN_LIKE_64(simde__m128i) const int16_t mem_addr[8];
    const int16_t r[8];
  } test_vec[] = {
    { UINT8_C(138),
      {  INT16_C( 23388), -INT16_C(  3134), -INT16_C(   718),  INT16_C( 17753), -INT16_C( 28165), -INT16_C( 31939),  INT16_C( 23176),  INT16_C( 22515) },
      {  INT16_C(     0),  INT16_C( 23388),  INT16_C(     0), -INT16_C(  3134),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(   718) } },
    { UINT8_C(220),
      { -INT16_C( 31140),  INT16_C( 23582),  INT16_C( 13705),  INT16_C( 13352), -INT16_C( 18537),  INT16_C( 19104),  INT16_C( 11130), -INT16_C( 10585) },
      {  INT16_C(     0),  INT16_C(     0), -INT16_C( 31140),  INT16_C( 23582),  INT16_C( 13705),  INT16_C(     0),  INT16_C( 13352), -INT16_C( 18537) } },
    { UINT8_C(237),
      {  INT16_C(  2202), -INT16_C(  2838), -INT16_C(  6835), -INT16_C( 30075),  INT16_C(  3432),  INT16_C( 23780), -INT16_C( 16027), -INT16_C(  5192) },
      {  INT16_C(  2202),  INT16_C(     0), -INT16_C(  2838), -INT16_C(  6835),  INT16_C(     0), -INT16_C( 30075),  INT16_C(  3432),  INT16_C( 23780) } },
    { UINT8_C(223),
      {  INT16_C( 29972),  INT16_C( 15381), -INT16_C( 21335),  INT16_C( 18931),  INT16_C( 28150), -INT16_C( 25228),  INT16_C( 24899),  INT16_C( 19256) },
      {  INT16_C( 29972),  INT16_C( 15381), -INT16_C( 21335),  INT16_C( 18931),  INT16_C( 28150),  INT16_C(     0), -INT16_C( 25228),  INT16_C( 24899) } },
    { UINT8_C( 75),
      { -INT16_C( 26324), -INT16_C( 20175), -INT16_C( 26333),  INT16_C(  2238),  INT16_C(  9205), -INT16_C( 21047), -INT16_C( 22513), -INT16_C( 31551) },
      { -INT16_C( 26324), -INT16_C( 20175),  INT16_C(     0), -INT16_C( 26333),  INT16_C(     0),  INT16_C(     0),  INT16_C(  2238),  INT16_C(     0) } },
    { UINT8_C(189),
      {  INT16_C( 11773), -INT16_C(  3991),  INT16_C( 24694), -INT16_C(  5282), -INT16_C( 24067),  INT16_C( 13644), -INT16_C( 26387), -INT16_C( 31135) },
      {  INT16_C( 11773),  INT16_C(     0), -INT16_C(  3991),  INT16_C( 24694), -INT16_C(  5282), -INT16_C( 24067),  INT16_C(     0),  INT16_C( 13644) } },
    { UINT8_C(201),
      { -INT16_C( 22254), -INT16_C( 11934),  INT16_C( 22705),  INT16_C( 31476),  INT16_C(   773), -INT16_C( 14557), -INT16_C(  8057), -INT16_C( 19260) },
      { -INT16_C( 22254),  INT16_C(     0),  INT16_C(     0), -INT16_C( 11934),  INT16_C(     0),  INT16_C(     0),  INT16_C( 22705),  INT16_C( 31476) } },
    { UINT8_C( 74),
      {  INT16_C( 11189),  INT16_C(  5034), -INT16_C( 22762),  INT16_C( 25268), -INT16_C( 24099),  INT16_C( 16122), -INT16_C( 15577), -INT16_C( 11951) },
      {  INT16_C(     0),  INT16_C( 11189),  INT16_C(     0),  INT16_C(  5034),  INT16_C(     0),  INT16_C(     0), -INT16_C( 22762),  INT16_C(     0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__mmask8 k = test_vec[i].k;
    simde__m128i r = simde_mm_maskz_expandloadu_epi16(k, test_vec[i].mem_addr);
    simde_test_x86_assert_equal_i16x8(r, simde_mm_loadu_epi16(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_mm256_mask_expandloadu_epi16 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const int16_t src[16];
    const simde__mmask16 k;
    SIMDE_ALIGN_LIKE_64(simde__m256i) const int16_t mem_addr[16];
    const int16_t r[16];
  } test_vec[] = {
    { {  INT16_C(  8742),  INT16_C( 32386), -INT16_C(   746),  INT16_C(  6787),  INT16_C( 18976),  INT16_C(   161),  INT16_C( 22031), -INT16_C( 15286),
        -INT16_C(  2943), -INT16_C( 26665), -INT16_C( 29796),  INT16_C( 31225), -INT16_C(  3027),  INT16_C( 21687),  INT16_C(  2231), -INT16_C(  8923) },
      UINT16_C(43050),
      {  INT16_C( 16731), -INT16_C(  8283), -INT16_C( 15013), -INT16_C(   983),  INT16_C( 14533),  INT16_C(  4178), -INT16_C( 11268), -INT16_C( 11516),
        -INT16_C( 24470),  INT16_C( 25695), -INT16_C( 29671), -INT16_C( 11944),  INT16_C(  4064),  INT16_C(  1753),  INT16_C(  1261),  INT16_C( 18606) },
      {  INT16_C(  8742),  INT16_C( 16731), -INT16_C(   746), -INT16_C(  8283),  INT16_C( 18976), -INT16_C( 15013),  INT16_C( 22031), -INT16_C( 15286),
        -INT16_C(  2943), -INT16_C( 26665), -INT16_C( 29796), -INT16_C(   983), -INT16_C(  3027),  INT16_C( 14533),  INT16_C(  2231),  INT16_C(  4178) } },
    { {  INT16_C( 21317), -INT16_C( 24537),  INT16_C( 20760), -INT16_C(  8804), -INT16_C(  4215), -INT16_C( 30995), -INT16_C(  3390),  INT16_C( 11609),
        -INT16_C( 18286), -INT16_C( 21359), -INT16_C(  5820),  INT16_C(  9597),  INT16_C( 22264), -INT16_C(  6869), -INT16_C(  9894), -INT16_C( 24786) },
      UINT16_C(21804),
      {  INT16_C( 17471), -INT16_C(  9050),  INT16_C( 12321),  INT16_C(  4043), -INT16_C( 29258),  INT16_C(  3841), -INT16_C( 27718),  INT16_C( 19400),
         INT16_C(  3135), -INT16_C( 17356),  INT16_C( 11569),  INT16_C( 23571),  INT16_C( 27922),  INT16_C( 16437),  INT16_C( 24845),  INT16_C( 19606) },
      {  INT16_C( 21317), -INT16_C( 24537),  INT16_C( 17471), -INT16_C(  9050), -INT16_C(  4215),  INT16_C( 12321), -INT16_C(  3390),  INT16_C( 11609),
         INT16_C(  4043), -INT16_C( 21359), -INT16_C( 29258),  INT16_C(  9597),  INT16_C(  3841), -INT16_C(  6869), -INT16_C( 27718), -INT16_C( 24786) } },
    { {  INT16_C( 15525), -INT16_C( 14552), -INT16_C(  3220),  INT16_C(  8918), -INT16_C( 10367),  INT16_C( 15154), -INT16_C(  1430), -INT16_C( 21881),
        -INT16_C( 17658),  INT16_C( 14438),  INT16_C( 31208), -INT16_C(  1132), -INT16_C( 13593), -INT16_C(  3013), -INT16_C( 11989), -INT16_C( 11968) },
      UINT16_C(26894),
      {  INT16_C( 31384),  INT16_C( 28252), -INT16_C(  8803), -INT16_C( 12475), -INT16_C( 20711), -INT16_C( 24375), -INT16_C( 12455), -INT16_C( 16293),
         INT16_C( 17415), -INT16_C( 25543),  INT16_C(  8255),  INT16_C( 31334), -INT16_C( 28396),  INT16_C( 21836),  INT16_C( 23138), -INT16_C(  1346) },
      {  INT16_C( 15525),  INT16_C( 31384),  INT16_C( 28252), -INT16_C(  8803), -INT16_C( 10367),  INT16_C( 15154), -INT16_C(  1430), -INT16_C( 21881),
        -INT16_C( 12475),  INT16_C( 14438),  INT16_C( 31208), -INT16_C( 20711), -INT16_C( 13593), -INT16_C( 24375), -INT16_C( 12455), -INT16_C( 11968) } },
    { {  INT16_C(  6868),  INT16_C( 29032), -INT16_C( 21000),  INT16_C(  4416),  INT16_C(  2397), -INT16_C( 18767),  INT16_C(  3289), -INT16_C(  8074),
        -INT16_C( 20400), -INT16_C( 28804), -INT16_C(  7472), -INT16_C(  6902),  INT16_C( 22132), -INT16_C( 10694), -INT16_C(  1872), -INT16_C( 31535) },
      UINT16_C(14610),
      {  INT16_C(  2806),  INT16_C( 14055),  INT16_C( 17435), -INT16_C( 13248),  INT16_C(  6650),  INT16_C( 29145),  INT16_C( 10745),  INT16_C( 30241),
        -INT16_C(  3655), -INT16_C( 15528), -INT16_C( 13098),  INT16_C(  4121), -INT16_C( 13917),  INT16_C( 29704),  INT16_C(  6989),  INT16_C( 17325) },
      {  INT16_C(  6868),  INT16_C(  2806), -INT16_C( 21000),  INT16_C(  4416),  INT16_C( 14055), -INT16_C( 18767),  INT16_C(  3289), -INT16_C(  8074),
         INT16_C( 17435), -INT16_C( 28804), -INT16_C(  7472), -INT16_C( 13248),  INT16_C(  6650),  INT16_C( 29145), -INT16_C(  1872), -INT16_C( 31535) } },
    { { -INT16_C( 27611),  INT16_C( 16762), -INT16_C( 17704), -INT16_C( 11507), -INT16_C(  6445), -INT16_C( 13244),  INT16_C( 25872), -INT16_C( 14014),
        -INT16_C( 25770),  INT16_C( 11660), -INT16_C( 23193),  INT16_C(  2621),  INT16_C( 18030), -INT16_C( 17538),  INT16_C( 11361), -INT16_C( 30977) },
      UINT16_C(31168),
      { -INT16_C( 26169), -INT16_C( 10957),  INT16_C(  1644), -INT16_C( 20293), -INT16_C( 13358),  INT16_C(  5397),  INT16_C( 27540),  INT16_C(  8368),
         INT16_C(  6040), -INT16_C( 10555),  INT16_C( 13090), -INT16_C( 24548),  INT16_C( 32239), -INT16_C(  4404), -INT16_C( 29437), -INT16_C( 13465) },
      { -INT16_C( 27611),  INT16_C( 16762), -INT16_C( 17704), -INT16_C( 11507), -INT16_C(  6445), -INT16_C( 13244), -INT16_C( 26169), -INT16_C( 10957),
         INT16_C(  1644),  INT16_C( 11660), -INT16_C( 23193), -INT16_C( 20293), -INT16_C( 13358),  INT16_C(  5397),  INT16_C( 27540), -INT16_C( 30977) } },
    { { -INT16_C( 26074), -INT16_C( 28000),  INT16_C( 23456),  INT16_C( 29250),  INT16_C( 22311), -INT16_C( 17529),  INT16_C( 14274),  INT16_C( 23516),
        -INT16_C( 24241),  INT16_C( 28977),  INT16_C( 19925), -INT16_C( 15343), -INT16_C(  8502), -INT16_C( 12878),  INT16_C(  6507), -INT16_C( 28264) },
      UINT16_C(14515),
      {  INT16_C( 21283),  INT16_C( 26004), -INT16_C( 17467),  INT16_C( 19900),  INT16_C( 32374),  INT16_C( 21124), -INT16_C( 11303),  INT16_C(  2804),
        -INT16_C( 14012),  INT16_C( 22103),  INT16_C(  8589),  INT16_C( 16180), -INT16_C( 24593), -INT16_C( 30888),  INT16_C(  2864),  INT16_C( 21440) },
      {  INT16_C( 21283),  INT16_C( 26004),  INT16_C( 23456),  INT16_C( 29250), -INT16_C( 17467),  INT16_C( 19900),  INT16_C( 14274),  INT16_C( 32374),
        -INT16_C( 24241),  INT16_C( 28977),  INT16_C( 19925),  INT16_C( 21124), -INT16_C( 11303),  INT16_C(  2804),  INT16_C(  6507), -INT16_C( 28264) } },
    { {  INT16_C( 21598),  INT16_C(  9144),  INT16_C( 29711), -INT16_C( 31376), -INT16_C(  2574), -INT16_C( 13096), -INT16_C( 13112),  INT16_C(  3542),
         INT16_C( 11925),  INT16_C(  8803), -INT16_C( 26801),  INT16_C( 15969), -INT16_C( 18122),  INT16_C( 26310), -INT16_C( 31036),  INT16_C(  8889) },
      UINT16_C(29146),
      { -INT16_C(  5819), -INT16_C( 18715), -INT16_C( 10386),  INT16_C( 18091),  INT16_C( 29603),  INT16_C( 31250), -INT16_C( 22656), -INT16_C(  7256),
        -INT16_C(  2103),  INT16_C( 10874), -INT16_C( 20426), -INT16_C(   797), -INT16_C( 22762), -INT16_C( 12414),  INT16_C( 23753),  INT16_C(  3904) },
      {  INT16_C( 21598), -INT16_C(  5819),  INT16_C( 29711), -INT16_C( 18715), -INT16_C( 10386), -INT16_C( 13096),  INT16_C( 18091),  INT16_C( 29603),
         INT16_C( 31250),  INT16_C(  8803), -INT16_C( 26801),  INT16_C( 15969), -INT16_C( 22656), -INT16_C(  7256), -INT16_C(  2103),  INT16_C(  8889) } },
    { {  INT16_C(  9541), -INT16_C( 19515),  INT16_C( 28925), -INT16_C( 24326),  INT16_C(  3299),  INT16_C( 25626), -INT16_C( 15692),  INT16_C( 32071),
        -INT16_C( 15686), -INT16_C(  3928), -INT16_C( 29838), -INT16_C( 30228),  INT16_C( 28211), -INT16_C(   936), -INT16_C( 26166),  INT16_C(  3851) },
      UINT16_C(53438),
      { -INT16_C( 17470), -INT16_C( 17344),  INT16_C(  9308),  INT16_C( 30409),  INT16_C( 32136), -INT16_C( 12487), -INT16_C(  3078), -INT16_C( 23919),
         INT16_C(  1251), -INT16_C( 12498),  INT16_C( 24973), -INT16_C(  6851),  INT16_C(  1885),  INT16_C( 27006),  INT16_C( 15638), -INT16_C( 10183) },
      {  INT16_C(  9541), -INT16_C( 17470), -INT16_C( 17344),  INT16_C(  9308),  INT16_C( 30409),  INT16_C( 32136), -INT16_C( 15692), -INT16_C( 12487),
        -INT16_C( 15686), -INT16_C(  3928), -INT16_C( 29838), -INT16_C( 30228), -INT16_C(  3078), -INT16_C(   936), -INT16_C( 23919),  INT16_C(  1251) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256i src = simde_mm256_loadu_epi16(test_vec[i].src);
    simde__mmask16 k = test_vec[i].k;
    simde__m256i r = simde_mm256_mask_expandloadu_epi16(src, k, test_vec[i].mem_addr);
    simde_test_x86_assert_equal_i16x16(r, simde_mm256_loadu_epi16(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_mm256_maskz_expandloadu_epi16 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const simde__mmask16 k;
    SIMDE_ALIGN_LIKE_64(simde__m256i) const int16_t mem_addr[16];
    const int16_t r[16];
  } test_vec[] = {
    { UINT16_C(31480),
      {  INT16_C( 21653),  INT16_C( 24222),  INT16_C(  9931),  INT16_C(  1243), -INT16_C( 10763), -INT16_C( 30729), -INT16_C(  9608), -INT16_C( 22901),
         INT16_C(  6313), -INT16_C(  6649),  INT16_C( 25853),  INT16_C( 31981),  INT16_C(   973),  INT16_C(  1977), -INT16_C( 20005),  INT16_C( 28801) },
      {  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C( 21653),  INT16_C( 24222),  INT16_C(  9931),  INT16_C(  1243), -INT16_C( 10763),
         INT16_C(     0), -INT16_C( 30729),  INT16_C(     0), -INT16_C(  9608), -INT16_C( 22901),  INT16_C(  6313), -INT16_C(  6649),  INT16_C(     0) } },
    { UINT16_C( 7942),
      { -INT16_C( 11826), -INT16_C( 22203),  INT16_C( 15061), -INT16_C( 13185), -INT16_C(  2111),  INT16_C( 19622),  INT16_C( 20381), -INT16_C( 23452),
         INT16_C( 25141),  INT16_C(  8712), -INT16_C( 10530), -INT16_C( 26843),  INT16_C(   221),  INT16_C( 24136),  INT16_C( 20081),  INT16_C( 16253) },
      {  INT16_C(     0), -INT16_C( 11826), -INT16_C( 22203),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
         INT16_C( 15061), -INT16_C( 13185), -INT16_C(  2111),  INT16_C( 19622),  INT16_C( 20381),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
    { UINT16_C(49695),
      { -INT16_C(  2839),  INT16_C( 26876), -INT16_C( 16704),  INT16_C( 26207), -INT16_C(  1014),  INT16_C( 28597), -INT16_C(  5472), -INT16_C( 22319),
        -INT16_C( 20724),  INT16_C( 12670),  INT16_C( 23366), -INT16_C( 29134), -INT16_C( 23623),  INT16_C( 14045), -INT16_C(   798), -INT16_C( 13320) },
      { -INT16_C(  2839),  INT16_C( 26876), -INT16_C( 16704),  INT16_C( 26207), -INT16_C(  1014),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
         INT16_C(     0),  INT16_C( 28597),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(  5472), -INT16_C( 22319) } },
    { UINT16_C(62961),
      { -INT16_C( 20173), -INT16_C( 27981), -INT16_C( 17128), -INT16_C( 12914),  INT16_C( 11820), -INT16_C(   584), -INT16_C( 15145),  INT16_C( 21932),
        -INT16_C(  3338),  INT16_C( 10417),  INT16_C( 27265),  INT16_C( 24267), -INT16_C( 21087), -INT16_C( 26278),  INT16_C( 19321), -INT16_C( 21362) },
      { -INT16_C( 20173),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C( 27981), -INT16_C( 17128), -INT16_C( 12914),  INT16_C( 11820),
        -INT16_C(   584),  INT16_C(     0), -INT16_C( 15145),  INT16_C(     0),  INT16_C( 21932), -INT16_C(  3338),  INT16_C( 10417),  INT16_C( 27265) } },
    { UINT16_C(16893),
      {  INT16_C(  5439), -INT16_C( 12801),  INT16_C( 11234), -INT16_C( 25860), -INT16_C( 11479), -INT16_C( 10913),  INT16_C( 21800), -INT16_C(  9784),
         INT16_C( 18813),  INT16_C( 18500), -INT16_C(  6745),  INT16_C(   501),  INT16_C( 28286),  INT16_C(  3405),  INT16_C( 18971),  INT16_C( 23118) },
      {  INT16_C(  5439),  INT16_C(     0), -INT16_C( 12801),  INT16_C( 11234), -INT16_C( 25860), -INT16_C( 11479), -INT16_C( 10913),  INT16_C( 21800),
        -INT16_C(  9784),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C( 18813),  INT16_C(     0) } },
    { UINT16_C(19807),
      {  INT16_C( 16679),  INT16_C(  9081), -INT16_C( 23844),  INT16_C( 15350),  INT16_C(  8055),  INT16_C( 16272),  INT16_C(  3576),  INT16_C( 15496),
         INT16_C( 12117),  INT16_C( 18977), -INT16_C( 24527),  INT16_C( 32441), -INT16_C( 11091), -INT16_C(  1080),  INT16_C( 10030),  INT16_C( 21833) },
      {  INT16_C( 16679),  INT16_C(  9081), -INT16_C( 23844),  INT16_C( 15350),  INT16_C(  8055),  INT16_C(     0),  INT16_C( 16272),  INT16_C(     0),
         INT16_C(  3576),  INT16_C(     0),  INT16_C( 15496),  INT16_C( 12117),  INT16_C(     0),  INT16_C(     0),  INT16_C( 18977),  INT16_C(     0) } },
    { UINT16_C(49768),
      {  INT16_C( 17529),  INT16_C( 28516), -INT16_C(  9345),  INT16_C(  3982), -INT16_C( 30949), -INT16_C( 23780),  INT16_C( 29123), -INT16_C(  6701),
         INT16_C(  1212),  INT16_C( 30085),  INT16_C( 12930),  INT16_C( 19017),  INT16_C( 30509),  INT16_C( 30321), -INT16_C(  9780),  INT16_C( 17720) },
      {  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C( 17529),  INT16_C(     0),  INT16_C( 28516), -INT16_C(  9345),  INT16_C(     0),
         INT16_C(     0),  INT16_C(  3982),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C( 30949), -INT16_C( 23780) } },
    { UINT16_C(39966),
      { -INT16_C( 25163),  INT16_C( 17272), -INT16_C( 27731), -INT16_C( 13878), -INT16_C( 29130),  INT16_C(  2363), -INT16_C(  2189), -INT16_C(  2035),
        -INT16_C( 28820), -INT16_C( 19158),  INT16_C( 22489),  INT16_C( 18988), -INT16_C(  1842),  INT16_C(  1572),  INT16_C( 16958), -INT16_C(  3165) },
      {  INT16_C(     0), -INT16_C( 25163),  INT16_C( 17272), -INT16_C( 27731), -INT16_C( 13878),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
         INT16_C(     0),  INT16_C(     0), -INT16_C( 29130),  INT16_C(  2363), -INT16_C(  2189),  INT16_C(     0),  INT16_C(     0), -INT16_C(  2035) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__mmask16 k = test_vec[i].k;
    simde__m256i r = simde_mm256_maskz_expandloadu_epi16(k, test_vec[i].mem_addr);
    simde_test_x86_assert_equal_i16x16(r, simde_mm256_loadu_epi16(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_mm512_mask_expandloadu_epi16 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const int16_t src[32];
    const simde__mmask32 k;
    SIMDE_ALIGN_LIKE_64(simde__m512i) const int16_t mem_addr[32];
    const int16_t r[32];
  } test_vec[] = {
    { {  INT16_C(  7135), -INT16_C( 29642),  INT16_C(   430), -INT16_C(  7082), -INT16_C( 28273),  INT16_C(   750), -INT16_C(  1144), -INT16_C(  2822),
         INT16_C(  9355),  INT16_C( 25769), -INT16_C( 10885),  INT16_C( 18863), -INT16_C( 11315),  INT16_C(  2896), -INT16_C(  3307), -INT16_C(  2818),
         INT16_C( 13582), -INT16_C( 17279), -INT16_C( 10442), -INT16_C( 14944), -INT16_C( 29080), -INT16_C(  3897), -INT16_C( 15990),  INT16_C(  5604),
        -INT16_C( 29211),  INT16_C( 24697),  INT16_C( 10338),  INT16_C( 12202), -INT16_C(  1285),  INT16_C(  4155),  INT16_C( 14829), -INT16_C(  1275) },
      UINT32_C(2763490926),
      {  INT16_C( 22365), -INT16_C( 14999),  INT16_C( 12518),  INT16_C( 28853), -INT16_C( 26127), -INT16_C( 10619), -INT16_C(   474), -INT16_C( 30665),
        -INT16_C(  7897),  INT16_C(  8887), -INT16_C(  3365), -INT16_C( 14285),  INT16_C( 14380), -INT16_C( 25917),  INT16_C( 31422),  INT16_C(  6975),
        -INT16_C( 22319), -INT16_C( 18464), -INT16_C( 27175), -INT16_C( 13785), -INT16_C( 21458),  INT16_C( 21665), -INT16_C( 10069), -INT16_C( 11556),
        -INT16_C( 27719), -INT16_C( 27404),  INT16_C( 10118), -INT16_C( 19876),  INT16_C(  8031),  INT16_C(  7500), -INT16_C( 29799),  INT16_C( 27192) },
      {  INT16_C(  7135),  INT16_C( 22365), -INT16_C( 14999),  INT16_C( 12518), -INT16_C( 28273),  INT16_C( 28853), -INT16_C( 26127), -INT16_C(  2822),
         INT16_C(  9355), -INT16_C( 10619), -INT16_C(   474),  INT16_C( 18863), -INT16_C( 11315),  INT16_C(  2896), -INT16_C(  3307), -INT16_C( 30665),
        -INT16_C(  7897),  INT16_C(  8887), -INT16_C(  3365), -INT16_C( 14944), -INT16_C( 14285),  INT16_C( 14380), -INT16_C( 15990), -INT16_C( 25917),
        -INT16_C( 29211),  INT16_C( 24697),  INT16_C( 31422),  INT16_C( 12202), -INT16_C(  1285),  INT16_C(  6975),  INT16_C( 14829), -INT16_C( 22319) } },
    { {  INT16_C(  6196),  INT16_C(  3362),  INT16_C( 18861), -INT16_C(  9257),  INT16_C( 30966), -INT16_C( 24273),  INT16_C(  2896),  INT16_C(  2419),
         INT16_C( 26527),  INT16_C(  9629), -INT16_C(  1649), -INT16_C(  4393),  INT16_C(  8984), -INT16_C( 20212),  INT16_C( 17583), -INT16_C(  7396),
         INT16_C( 15965),  INT16_C(  2800), -INT16_C( 14457),  INT16_C( 32230),  INT16_C(  5440), -INT16_C( 28642), -INT16_C( 28383), -INT16_C( 16230),
         INT16_C( 14329), -INT16_C( 30491), -INT16_C( 17359),  INT16_C( 18806), -INT16_C( 32033), -INT16_C( 28933),  INT16_C(  6087),  INT16_C(  9329) },
      UINT32_C(3694027093),
      {  INT16_C(  5161),  INT16_C( 26970),  INT16_C( 30762),  INT16_C( 19449), -INT16_C( 27894),  INT16_C(   779), -INT16_C(  3893), -INT16_C(   885),
         INT16_C(   428), -INT16_C( 29883),  INT16_C( 16516),  INT16_C( 19226), -INT16_C( 29865), -INT16_C( 21393), -INT16_C( 25107),  INT16_C(  5769),
        -INT16_C(  7246), -INT16_C(  9089),  INT16_C( 30811),  INT16_C( 25895),  INT16_C( 12812), -INT16_C( 10392), -INT16_C(  3294), -INT16_C( 12589),
         INT16_C(  6389),  INT16_C( 31065),  INT16_C( 29529), -INT16_C( 20284),  INT16_C( 13311), -INT16_C(  5027), -INT16_C(  6448), -INT16_C( 32254) },
      {  INT16_C(  5161),  INT16_C(  3362),  INT16_C( 26970), -INT16_C(  9257),  INT16_C( 30762), -INT16_C( 24273),  INT16_C( 19449),  INT16_C(  2419),
        -INT16_C( 27894),  INT16_C(  9629), -INT16_C(  1649), -INT16_C(  4393),  INT16_C(  8984),  INT16_C(   779), -INT16_C(  3893), -INT16_C(  7396),
         INT16_C( 15965), -INT16_C(   885),  INT16_C(   428), -INT16_C( 29883),  INT16_C(  5440),  INT16_C( 16516), -INT16_C( 28383), -INT16_C( 16230),
         INT16_C( 14329), -INT16_C( 30491),  INT16_C( 19226), -INT16_C( 29865), -INT16_C( 21393), -INT16_C( 28933), -INT16_C( 25107),  INT16_C(  5769) } },
    { { -INT16_C( 32311),  INT16_C(  9310), -INT16_C( 31239),  INT16_C(  1418), -INT16_C(  3401), -INT16_C(  9764), -INT16_C( 20506), -INT16_C(  9305),
         INT16_C(   456),  INT16_C(  8532),  INT16_C(  6260),  INT16_C( 29649),  INT16_C( 11851),  INT16_C(  7007),  INT16_C( 24852), -INT16_C(  8802),
        -INT16_C(   798), -INT16_C(  9214), -INT16_C( 29566),  INT16_C( 14817), -INT16_C( 16770),  INT16_C( 25619), -INT16_C( 17811),  INT16_C( 13631),
        -INT16_C( 27717),  INT16_C( 12374),  INT16_C( 10411), -INT16_C(  2397),  INT16_C(   854),  INT16_C( 27410), -INT16_C( 20380),  INT16_C( 18248) },
      UINT32_C( 774064812),
      {  INT16_C(  1238),  INT16_C( 21864),  INT16_C( 31682),  INT16_C( 12473), -INT16_C(  1739), -INT16_C(  3739), -INT16_C( 17268),  INT16_C( 14369),
        -INT16_C( 15132),  INT16_C( 14894),  INT16_C( 16583),  INT16_C( 11429), -INT16_C(  4368), -INT16_C( 25229), -INT16_C( 27080),  INT16_C(  4043),
         INT16_C( 13210),  INT16_C( 23908),  INT16_C(  7598), -INT16_C(  7027), -INT16_C(  3562), -INT16_C( 23595), -INT16_C(  2386), -INT16_C( 27941),
         INT16_C(  2490), -INT16_C( 32051),  INT16_C( 29258),  INT16_C( 15022),  INT16_C(  8544), -INT16_C( 26153), -INT16_C( 23625),  INT16_C( 20904) },
      { -INT16_C( 32311),  INT16_C(  9310),  INT16_C(  1238),  INT16_C( 21864), -INT16_C(  3401),  INT16_C( 31682), -INT16_C( 20506),  INT16_C( 12473),
         INT16_C(   456), -INT16_C(  1739),  INT16_C(  6260), -INT16_C(  3739),  INT16_C( 11851),  INT16_C(  7007), -INT16_C( 17268), -INT16_C(  8802),
         INT16_C( 14369), -INT16_C( 15132), -INT16_C( 29566),  INT16_C( 14817), -INT16_C( 16770),  INT16_C( 14894), -INT16_C( 17811),  INT16_C( 13631),
        -INT16_C( 27717),  INT16_C( 16583),  INT16_C( 11429), -INT16_C(  4368),  INT16_C(   854), -INT16_C( 25229), -INT16_C( 20380),  INT16_C( 18248) } },
    { {  INT16_C(  3286), -INT16_C( 31314),  INT16_C( 15145),  INT16_C( 16489),  INT16_C( 15918), -INT16_C(  8989), -INT16_C( 16844), -INT16_C(  4497),
         INT16_C( 15559),  INT16_C(  4464),  INT16_C(  7854),  INT16_C(  3916),  INT16_C(  9023), -INT16_C(  2392),  INT16_C( 20678), -INT16_C( 25272),
        -INT16_C(  2468), -INT16_C( 31454), -INT16_C( 29902),  INT16_C( 24773), -INT16_C( 22327), -INT16_C(   708), -INT16_C( 21658),  INT16_C( 12011),
         INT16_C( 23783), -INT16_C( 27073), -INT16_C( 29830), -INT16_C( 17755),  INT16_C( 19887),  INT16_C( 30128), -INT16_C(  1891), -INT16_C(  1774) },
      UINT32_C( 561919215),
      {  INT16_C( 17599), -INT16_C( 30591), -INT16_C( 16916),  INT16_C( 21381),  INT16_C( 29033),  INT16_C( 20609), -INT16_C( 16179),  INT16_C( 18406),
        -INT16_C( 29876), -INT16_C(  1279), -INT16_C( 19752),  INT16_C( 30064), -INT16_C( 31830), -INT16_C( 26258), -INT16_C(  4681),  INT16_C( 30650),
         INT16_C( 15153),  INT16_C(  7679), -INT16_C( 31239),  INT16_C( 25200), -INT16_C(  3594), -INT16_C( 15438), -INT16_C( 26190), -INT16_C(   502),
         INT16_C(  3108), -INT16_C(   519),  INT16_C( 27070),  INT16_C( 26738), -INT16_C(  7700), -INT16_C( 23550), -INT16_C( 17202), -INT16_C(   229) },
      {  INT16_C( 17599), -INT16_C( 30591), -INT16_C( 16916),  INT16_C( 21381),  INT16_C( 15918),  INT16_C( 29033),  INT16_C( 20609), -INT16_C( 16179),
         INT16_C( 15559),  INT16_C(  4464),  INT16_C( 18406),  INT16_C(  3916), -INT16_C( 29876), -INT16_C(  1279),  INT16_C( 20678), -INT16_C( 25272),
        -INT16_C(  2468), -INT16_C( 19752),  INT16_C( 30064), -INT16_C( 31830), -INT16_C( 26258), -INT16_C(  4681),  INT16_C( 30650),  INT16_C( 12011),
         INT16_C( 15153), -INT16_C( 27073), -INT16_C( 29830), -INT16_C( 17755),  INT16_C( 19887),  INT16_C(  7679), -INT16_C(  1891), -INT16_C(  1774) } },
    { {  INT16_C(  6904), -INT16_C(  3812), -INT16_C( 29281), -INT16_C( 27309),  INT16_C(  1406),  INT16_C( 12376),  INT16_C( 25502), -INT16_C( 15570),
         INT16_C( 10095),  INT16_C( 11712),  INT16_C( 12945),  INT16_C( 32149), -INT16_C( 26861), -INT16_C(  7903),  INT16_C( 15444),  INT16_C( 19680),
        -INT16_C(   681), -INT16_C(  2499), -INT16_C( 28534),  INT16_C(  2188), -INT16_C(  7019),  INT16_C( 13369),  INT16_C( 26439), -INT16_C( 18697),
        -INT16_C( 18545),  INT16_C(  8419),  INT16_C( 31209), -INT16_C(   611), -INT16_C( 16624),  INT16_C( 25822), -INT16_C( 16389),  INT16_C( 21168) },
      UINT32_C(1179250108),
      { -INT16_C( 10883),  INT16_C(  4942), -INT16_C( 30791),  INT16_C(   327),  INT16_C( 16111),  INT16_C( 32439), -INT16_C( 25611), -INT16_C(  8546),
         INT16_C( 15124),  INT16_C(  9435), -INT16_C( 17670), -INT16_C(  2423),  INT16_C( 14713),  INT16_C( 13640), -INT16_C( 28377), -INT16_C( 23429),
        -INT16_C( 13978),  INT16_C(  8375), -INT16_C(   431),  INT16_C( 16417), -INT16_C( 10180),  INT16_C( 12734),  INT16_C( 23667), -INT16_C( 30960),
        -INT16_C(  5225), -INT16_C( 27988),  INT16_C( 13733),  INT16_C(  7816), -INT16_C( 12178), -INT16_C( 27309), -INT16_C( 12702), -INT16_C( 14278) },
      {  INT16_C(  6904), -INT16_C(  3812), -INT16_C( 10883),  INT16_C(  4942), -INT16_C( 30791),  INT16_C(   327),  INT16_C( 25502),  INT16_C( 16111),
         INT16_C( 32439),  INT16_C( 11712), -INT16_C( 25611), -INT16_C(  8546), -INT16_C( 26861),  INT16_C( 15124),  INT16_C(  9435), -INT16_C( 17670),
        -INT16_C(  2423), -INT16_C(  2499), -INT16_C( 28534),  INT16_C( 14713), -INT16_C(  7019),  INT16_C( 13369),  INT16_C( 13640), -INT16_C( 18697),
        -INT16_C( 18545), -INT16_C( 28377), -INT16_C( 23429), -INT16_C(   611), -INT16_C( 16624),  INT16_C( 25822), -INT16_C( 13978),  INT16_C( 21168) } },
    { { -INT16_C(  3688), -INT16_C(  5656),  INT16_C(  2544),  INT16_C( 11305), -INT16_C(  6174),  INT16_C( 21854),  INT16_C( 28227), -INT16_C(  9507),
        -INT16_C( 30375), -INT16_C(   148), -INT16_C(  2882),  INT16_C( 11293),  INT16_C( 29125),  INT16_C( 10178), -INT16_C(   961), -INT16_C( 10257),
        -INT16_C( 10003), -INT16_C(  8768), -INT16_C(  5663), -INT16_C( 15606),  INT16_C( 26832),  INT16_C(  4889), -INT16_C(  2346),  INT16_C( 12270),
         INT16_C( 23167),  INT16_C( 15662),  INT16_C( 19535),  INT16_C(  5225),  INT16_C( 11197), -INT16_C(   965),  INT16_C( 10791),  INT16_C(  5588) },
      UINT32_C(3841102850),
      { -INT16_C(   898),  INT16_C( 20135), -INT16_C( 16284),  INT16_C( 14946),  INT16_C( 20662),  INT16_C( 13674), -INT16_C( 26454), -INT16_C(  1678),
        -INT16_C(  8988), -INT16_C( 24307),  INT16_C( 18439),  INT16_C( 12190),  INT16_C( 29299),  INT16_C( 30020),  INT16_C( 13830), -INT16_C( 31655),
         INT16_C(   307), -INT16_C( 26669),  INT16_C( 13761),  INT16_C( 30930),  INT16_C( 15493),  INT16_C( 12205),  INT16_C(  8404), -INT16_C( 18135),
         INT16_C( 14076),  INT16_C(   858), -INT16_C(  1921), -INT16_C(  3534),  INT16_C( 30314),  INT16_C( 29031), -INT16_C( 15955), -INT16_C(  7947) },
      { -INT16_C(  3688), -INT16_C(   898),  INT16_C(  2544),  INT16_C( 11305), -INT16_C(  6174),  INT16_C( 21854),  INT16_C( 28227), -INT16_C(  9507),
        -INT16_C( 30375), -INT16_C(   148),  INT16_C( 20135),  INT16_C( 11293), -INT16_C( 16284),  INT16_C( 10178), -INT16_C(   961),  INT16_C( 14946),
        -INT16_C( 10003),  INT16_C( 20662), -INT16_C(  5663), -INT16_C( 15606),  INT16_C( 13674), -INT16_C( 26454), -INT16_C(  1678), -INT16_C(  8988),
         INT16_C( 23167),  INT16_C( 15662), -INT16_C( 24307),  INT16_C(  5225),  INT16_C( 11197),  INT16_C( 18439),  INT16_C( 12190),  INT16_C( 29299) } },
    { { -INT16_C( 14142), -INT16_C( 31881),  INT16_C( 18941), -INT16_C( 32005), -INT16_C( 22139),  INT16_C( 23218), -INT16_C(  9271), -INT16_C( 15085),
         INT16_C( 27921), -INT16_C( 28472), -INT16_C(  1178), -INT16_C( 12158), -INT16_C(  5519),  INT16_C(  7745),  INT16_C( 14251),  INT16_C( 28158),
         INT16_C( 30463), -INT16_C(   528), -INT16_C(  4929),  INT16_C( 17791),  INT16_C( 12693),  INT16_C( 24223), -INT16_C( 19956),  INT16_C(  7715),
        -INT16_C(  5345), -INT16_C( 31314),  INT16_C( 12774),  INT16_C( 22614), -INT16_C( 26853), -INT16_C( 14730),  INT16_C( 30158), -INT16_C( 12749) },
      UINT32_C(2865439723),
      {  INT16_C( 18959), -INT16_C( 23313), -INT16_C( 29060), -INT16_C( 30718),  INT16_C(  9536),  INT16_C( 24742),  INT16_C( 21777), -INT16_C(  2075),
         INT16_C( 15238), -INT16_C( 24241), -INT16_C( 14637), -INT16_C( 24217), -INT16_C( 26053),  INT16_C(  9839),  INT16_C( 15037), -INT16_C( 12848),
        -INT16_C( 16251),  INT16_C(   369),  INT16_C( 29774), -INT16_C( 28791),  INT16_C( 12441), -INT16_C( 21777), -INT16_C( 11131),  INT16_C(  2978),
        -INT16_C(  3824), -INT16_C(  7252),  INT16_C(  5047), -INT16_C(  3452), -INT16_C(  2899),  INT16_C( 27160), -INT16_C(  5842), -INT16_C( 19657) },
      {  INT16_C( 18959), -INT16_C( 23313),  INT16_C( 18941), -INT16_C( 29060), -INT16_C( 22139), -INT16_C( 30718),  INT16_C(  9536),  INT16_C( 24742),
         INT16_C( 21777), -INT16_C(  2075), -INT16_C(  1178), -INT16_C( 12158), -INT16_C(  5519),  INT16_C( 15238),  INT16_C( 14251),  INT16_C( 28158),
        -INT16_C( 24241), -INT16_C( 14637), -INT16_C(  4929), -INT16_C( 24217),  INT16_C( 12693),  INT16_C( 24223), -INT16_C( 26053),  INT16_C(  9839),
        -INT16_C(  5345),  INT16_C( 15037),  INT16_C( 12774), -INT16_C( 12848), -INT16_C( 26853), -INT16_C( 16251),  INT16_C( 30158),  INT16_C(   369) } },
    { { -INT16_C( 22103), -INT16_C(  2124),  INT16_C( 15901), -INT16_C( 18810),  INT16_C( 30062), -INT16_C(  3231),  INT16_C(   842),  INT16_C( 23294),
        -INT16_C( 21772), -INT16_C( 21443), -INT16_C( 15939),  INT16_C( 27294), -INT16_C( 18507), -INT16_C(  6956),  INT16_C(  3232),  INT16_C( 18839),
         INT16_C( 19637), -INT16_C( 11712), -INT16_C( 14454), -INT16_C(  1912), -INT16_C(  5828), -INT16_C( 30997), -INT16_C(  5652), -INT16_C(  7712),
         INT16_C(  7571),  INT16_C( 20621),  INT16_C( 11231), -INT16_C( 27462), -INT16_C( 28958), -INT16_C( 32136),  INT16_C(  4250),  INT16_C( 20427) },
      UINT32_C(3860925532),
      { -INT16_C( 21805),  INT16_C(  4062), -INT16_C( 13933), -INT16_C( 32618),  INT16_C( 30386),  INT16_C( 17761), -INT16_C(  4460),  INT16_C( 29589),
         INT16_C( 20249), -INT16_C(  1017), -INT16_C( 32547),  INT16_C( 30846),  INT16_C( 19088), -INT16_C(  4921), -INT16_C(  5802),  INT16_C( 10706),
        -INT16_C( 20333),  INT16_C(  9784), -INT16_C( 12679),  INT16_C( 11174),  INT16_C(  1861), -INT16_C(  9872),  INT16_C(  1525),  INT16_C(  3916),
         INT16_C( 21332),  INT16_C( 12555), -INT16_C( 30253),  INT16_C( 25513),  INT16_C( 29139),  INT16_C( 10575),  INT16_C(  8538), -INT16_C(  4782) },
      { -INT16_C( 22103), -INT16_C(  2124), -INT16_C( 21805),  INT16_C(  4062), -INT16_C( 13933), -INT16_C(  3231), -INT16_C( 32618),  INT16_C( 23294),
        -INT16_C( 21772), -INT16_C( 21443),  INT16_C( 30386),  INT16_C( 17761), -INT16_C( 18507), -INT16_C(  6956),  INT16_C(  3232),  INT16_C( 18839),
        -INT16_C(  4460), -INT16_C( 11712), -INT16_C( 14454), -INT16_C(  1912), -INT16_C(  5828),  INT16_C( 29589), -INT16_C(  5652), -INT16_C(  7712),
         INT16_C(  7571),  INT16_C( 20249), -INT16_C(  1017), -INT16_C( 27462), -INT16_C( 28958), -INT16_C( 32547),  INT16_C( 30846),  INT16_C( 19088) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i src = simde_mm512_loadu_epi16(test_vec[i].src);
    simde__mmask32 k = test_vec[i].k;
    simde__m512i r = simde_mm512_mask_expandloadu_epi16(src, k, test_vec[i].mem_addr);
    simde_test_x86_assert_equal_i16x32(r, simde_mm512_loadu_epi16(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_mm512_maskz_expandloadu_epi16 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const simde__mmask32 k;
    SIMDE_ALIGN_LIKE_64(simde__m512i) const int16_t mem_addr[32];
    const int16_t r[32];
  } test_vec[] = {
    { UINT32_C(  67692159),
      {  INT16_C(  1673),  INT16_C( 24885),  INT16_C( 25110), -INT16_C(  8473), -INT16_C( 10074),  INT16_C( 13078),  INT16_C( 19692),  INT16_C( 12518),
         INT16_C( 18945),  INT16_C( 22335),  INT16_C( 19307), -INT16_C(  3383),  INT16_C( 18288), -INT16_C(  4139), -INT16_C(  8915), -INT16_C( 18701),
         INT16_C( 10724), -INT16_C(  1513), -INT16_C(   373),  INT16_C( 12760), -INT16_C(  4137), -INT16_C( 15516),  INT16_C( 19259),  INT16_C( 15603),
         INT16_C( 13205),  INT16_C(   147),  INT16_C( 23934), -INT16_C(  4366), -INT16_C( 14428), -INT16_C( 11810), -INT16_C( 11867), -INT16_C( 30328) },
      {  INT16_C(  1673),  INT16_C( 24885),  INT16_C( 25110), -INT16_C(  8473), -INT16_C( 10074),  INT16_C( 13078),  INT16_C( 19692),  INT16_C(     0),
         INT16_C(     0),  INT16_C( 12518),  INT16_C( 18945),  INT16_C(     0),  INT16_C(     0),  INT16_C( 22335),  INT16_C( 19307), -INT16_C(  3383),
         INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C( 18288),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
         INT16_C(     0),  INT16_C(     0), -INT16_C(  4139),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
    { UINT32_C(2239995898),
      {  INT16_C( 23710),  INT16_C( 30134),  INT16_C(  6987), -INT16_C( 31176),  INT16_C( 11366), -INT16_C(  1086),  INT16_C( 21855), -INT16_C(  8709),
        -INT16_C(  4686),  INT16_C( 22220), -INT16_C( 21836),  INT16_C( 22824), -INT16_C( 20357),  INT16_C( 30434),  INT16_C( 26191), -INT16_C(  4613),
        -INT16_C( 19774),  INT16_C(  3426), -INT16_C( 25651),  INT16_C( 13203),  INT16_C( 21959),  INT16_C(  9774),  INT16_C( 10666),  INT16_C( 23811),
        -INT16_C( 12522), -INT16_C( 13645), -INT16_C(  9351), -INT16_C(  2780),  INT16_C(  1675), -INT16_C(  9365),  INT16_C( 26220),  INT16_C( 11976) },
      {  INT16_C(     0),  INT16_C( 23710),  INT16_C(     0),  INT16_C( 30134),  INT16_C(  6987), -INT16_C( 31176),  INT16_C( 11366), -INT16_C(  1086),
         INT16_C( 21855), -INT16_C(  8709), -INT16_C(  4686),  INT16_C( 22220), -INT16_C( 21836),  INT16_C(     0),  INT16_C(     0),  INT16_C( 22824),
        -INT16_C( 20357),  INT16_C( 30434),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C( 26191),
        -INT16_C(  4613),  INT16_C(     0), -INT16_C( 19774),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(  3426) } },
    { UINT32_C(3845860120),
      { -INT16_C( 12602), -INT16_C( 29416),  INT16_C( 17955), -INT16_C( 12621), -INT16_C( 18833), -INT16_C( 31445), -INT16_C(  8570), -INT16_C(   176),
         INT16_C( 29882),  INT16_C( 17908),  INT16_C( 24442), -INT16_C(  6368), -INT16_C(  5690), -INT16_C(  8683),  INT16_C( 20756), -INT16_C(  9532),
        -INT16_C(  9185),  INT16_C( 17255),  INT16_C(  6691), -INT16_C( 28143),  INT16_C( 15568),  INT16_C( 22040),  INT16_C( 26650), -INT16_C( 11178),
         INT16_C( 19164),  INT16_C( 22042),  INT16_C( 15018),  INT16_C( 28733),  INT16_C( 21283),  INT16_C( 14158),  INT16_C(  4772), -INT16_C( 15599) },
      {  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C( 12602), -INT16_C( 29416),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
         INT16_C( 17955), -INT16_C( 12621),  INT16_C(     0), -INT16_C( 18833),  INT16_C(     0), -INT16_C( 31445),  INT16_C(     0),  INT16_C(     0),
        -INT16_C(  8570), -INT16_C(   176),  INT16_C(     0),  INT16_C( 29882),  INT16_C( 17908),  INT16_C( 24442),  INT16_C(     0),  INT16_C(     0),
        -INT16_C(  6368),  INT16_C(     0), -INT16_C(  5690),  INT16_C(     0),  INT16_C(     0), -INT16_C(  8683),  INT16_C( 20756), -INT16_C(  9532) } },
    { UINT32_C( 302414063),
      {  INT16_C(  6034),  INT16_C( 25508), -INT16_C( 17325),  INT16_C( 28345),  INT16_C(  3876),  INT16_C(    66),  INT16_C( 23642),  INT16_C(  1111),
        -INT16_C( 27497), -INT16_C( 17804), -INT16_C( 15641), -INT16_C( 29710),  INT16_C(   981), -INT16_C( 15281),  INT16_C( 21884),  INT16_C(  3798),
         INT16_C( 31341), -INT16_C( 16271),  INT16_C( 11063),  INT16_C( 23342),  INT16_C( 28986), -INT16_C( 27556), -INT16_C( 19507),  INT16_C( 25752),
         INT16_C(  3143),  INT16_C( 12063),  INT16_C(  4559), -INT16_C( 23366),  INT16_C(  2324), -INT16_C( 28568),  INT16_C( 15967), -INT16_C( 13153) },
      {  INT16_C(  6034),  INT16_C( 25508), -INT16_C( 17325),  INT16_C( 28345),  INT16_C(     0),  INT16_C(  3876),  INT16_C(    66),  INT16_C( 23642),
         INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(  1111), -INT16_C( 27497), -INT16_C( 17804), -INT16_C( 15641),  INT16_C(     0),
         INT16_C(     0), -INT16_C( 29710),  INT16_C(   981),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
         INT16_C(     0), -INT16_C( 15281),  INT16_C(     0),  INT16_C(     0),  INT16_C( 21884),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
    { UINT32_C(4018933944),
      { -INT16_C( 17605),  INT16_C( 30283), -INT16_C( 22740), -INT16_C(  1782), -INT16_C( 23718), -INT16_C( 24226),  INT16_C( 32175),  INT16_C( 32464),
        -INT16_C( 29810), -INT16_C( 24030), -INT16_C( 30060), -INT16_C(  3277), -INT16_C( 11576), -INT16_C( 32321),  INT16_C( 19682),  INT16_C(  7792),
        -INT16_C( 17657),  INT16_C( 13204), -INT16_C( 24990), -INT16_C( 17364), -INT16_C( 30143), -INT16_C(  3746),  INT16_C( 11783), -INT16_C( 27281),
        -INT16_C( 27975),  INT16_C( 20024),  INT16_C( 27420), -INT16_C(  6847),  INT16_C(   317),  INT16_C(  8038), -INT16_C( 10675),  INT16_C( 21565) },
      {  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C( 17605),  INT16_C( 30283), -INT16_C( 22740),  INT16_C(     0), -INT16_C(  1782),
         INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C( 23718),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
         INT16_C(     0),  INT16_C(     0), -INT16_C( 24226),  INT16_C( 32175),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C( 32464),
        -INT16_C( 29810), -INT16_C( 24030), -INT16_C( 30060), -INT16_C(  3277),  INT16_C(     0), -INT16_C( 11576), -INT16_C( 32321),  INT16_C( 19682) } },
    { UINT32_C(4102541714),
      { -INT16_C( 19600), -INT16_C( 20047),  INT16_C(  3902),  INT16_C( 17826),  INT16_C(  4669), -INT16_C(  2085),  INT16_C(  5028), -INT16_C( 16315),
        -INT16_C( 31106), -INT16_C( 17499),  INT16_C(  2951), -INT16_C( 11046),  INT16_C(  6370),  INT16_C( 29736), -INT16_C( 20503),  INT16_C( 22888),
         INT16_C(  6499), -INT16_C( 24309), -INT16_C( 21208),  INT16_C( 26342), -INT16_C( 15937),  INT16_C( 25437), -INT16_C( 23852),  INT16_C( 21028),
        -INT16_C( 14040), -INT16_C( 20467), -INT16_C(  5931), -INT16_C( 18556), -INT16_C( 21248), -INT16_C(  5845), -INT16_C( 27812), -INT16_C( 16573) },
      {  INT16_C(     0), -INT16_C( 19600),  INT16_C(     0),  INT16_C(     0), -INT16_C( 20047),  INT16_C(     0),  INT16_C(     0),  INT16_C(  3902),
         INT16_C( 17826),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(  4669),  INT16_C(     0), -INT16_C(  2085),  INT16_C(  5028),
        -INT16_C( 16315), -INT16_C( 31106), -INT16_C( 17499),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(  2951),
         INT16_C(     0),  INT16_C(     0), -INT16_C( 11046),  INT16_C(     0),  INT16_C(  6370),  INT16_C( 29736), -INT16_C( 20503),  INT16_C( 22888) } },
    { UINT32_C(3579858605),
      {  INT16_C( 18427), -INT16_C( 17605), -INT16_C( 26616), -INT16_C(  8930),  INT16_C( 16954),  INT16_C( 25391),  INT16_C( 15628), -INT16_C(  7917),
        -INT16_C( 26843),  INT16_C(  9624), -INT16_C( 15548), -INT16_C( 24306),  INT16_C( 20822),  INT16_C(   864), -INT16_C( 15969), -INT16_C( 25639),
         INT16_C(  5128),  INT16_C(  4182),  INT16_C( 29869), -INT16_C(  6163),  INT16_C(  7607), -INT16_C( 15542),  INT16_C( 23898),  INT16_C( 32676),
         INT16_C( 15605),  INT16_C( 14756), -INT16_C( 19713),  INT16_C( 21978),  INT16_C( 15108), -INT16_C( 23719),  INT16_C( 13052),  INT16_C(  1086) },
      {  INT16_C( 18427),  INT16_C(     0), -INT16_C( 17605), -INT16_C( 26616),  INT16_C(     0), -INT16_C(  8930),  INT16_C(     0),  INT16_C( 16954),
         INT16_C(     0),  INT16_C( 25391),  INT16_C( 15628), -INT16_C(  7917),  INT16_C(     0),  INT16_C(     0), -INT16_C( 26843),  INT16_C(     0),
         INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(  9624), -INT16_C( 15548),  INT16_C(     0),
        -INT16_C( 24306),  INT16_C(     0),  INT16_C( 20822),  INT16_C(     0),  INT16_C(   864),  INT16_C(     0), -INT16_C( 15969), -INT16_C( 25639) } },
    { UINT32_C(4078212166),
      {  INT16_C(   521), -INT16_C( 16165),  INT16_C(  9503),  INT16_C( 31107),  INT16_C( 10115),  INT16_C( 30968), -INT16_C( 25501),  INT16_C( 25265),
        -INT16_C( 29618),  INT16_C( 21175),  INT16_C(  4295), -INT16_C( 15370),  INT16_C( 13378), -INT16_C( 30265), -INT16_C(  9271), -INT16_C( 11652),
         INT16_C( 22493), -INT16_C(   878),  INT16_C(  5501),  INT16_C(   117),  INT16_C( 27964), -INT16_C( 24712),  INT16_C( 10505),  INT16_C( 22529),
        -INT16_C( 18251),  INT16_C( 31914), -INT16_C( 24375),  INT16_C(  2879),  INT16_C(  1749), -INT16_C( 24940),  INT16_C(  4578), -INT16_C( 16528) },
      {  INT16_C(     0),  INT16_C(   521), -INT16_C( 16165),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(  9503),  INT16_C(     0),
         INT16_C(     0),  INT16_C(     0),  INT16_C( 31107),  INT16_C(     0),  INT16_C( 10115),  INT16_C(     0),  INT16_C(     0),  INT16_C( 30968),
         INT16_C(     0),  INT16_C(     0), -INT16_C( 25501),  INT16_C(     0),  INT16_C( 25265),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
        -INT16_C( 29618),  INT16_C( 21175),  INT16_C(     0),  INT16_C(     0),  INT16_C(  4295), -INT16_C( 15370),  INT16_C( 13378), -INT16_C( 30265) } },  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__mmask32 k = test_vec[i].k;
    simde__m512i r = simde_mm512_maskz_expandloadu_epi16(k, test_vec[i].mem_addr);
    simde_test_x86_assert_equal_i16x32(r, simde_mm512_loadu_epi16(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_mm_mask_expandloadu_epi32 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const int32_t src[4];
    const simde__mmask8 k;
    SIMDE_ALIGN_LIKE_64(simde__m128i) const int32_t mem_addr[4];
    const int32_t r[4];
  } test_vec[] = {
    { {  INT32_C(  1242794961), -INT32_C(  1636451751), -INT32_C(  1216879167),  INT32_C(  1053213674) },
      UINT8_C( 23),
      {  INT32_C(  1525313745), -INT32_C(  1976676839), -INT32_C(  1075554403),  INT32_C(   898683306) },
      {  INT32_C(  1525313745), -INT32_C(  1976676839), -INT32_C(  1075554403),  INT32_C(  1053213674) } },
    { { -INT32_C(  1618027547),  INT32_C(   912272720),  INT32_C(  1746933668), -INT32_C(  1367384099) },
      UINT8_C(207),
      { -INT32_C(  1209530007), -INT32_C(  1907002569),  INT32_C(   691541079),  INT32_C(  2131652004) },
      { -INT32_C(  1209530007), -INT32_C(  1907002569),  INT32_C(   691541079),  INT32_C(  2131652004) } },
    { {  INT32_C(   701541884),  INT32_C(   634193421), -INT32_C(  2063452890),  INT32_C(   508866996) },
      UINT8_C(186),
      { -INT32_C(  1326328515),  INT32_C(  1040678698),  INT32_C(   635646136), -INT32_C(   350133698) },
      {  INT32_C(   701541884), -INT32_C(  1326328515), -INT32_C(  2063452890),  INT32_C(  1040678698) } },
    { {  INT32_C(   955861554),  INT32_C(  1298079256), -INT32_C(   788339680),  INT32_C(  1988829241) },
      UINT8_C(245),
      { -INT32_C(    65001860),  INT32_C(  1588878893), -INT32_C(  1533224639),  INT32_C(  1171687675) },
      { -INT32_C(    65001860),  INT32_C(  1298079256),  INT32_C(  1588878893),  INT32_C(  1988829241) } },
    { { -INT32_C(  1621291135),  INT32_C(  1388292974), -INT32_C(   846491219), -INT32_C(  1715338980) },
      UINT8_C( 39),
      {  INT32_C(  1096127970),  INT32_C(   578990921), -INT32_C(   685955505),  INT32_C(   207119357) },
      {  INT32_C(  1096127970),  INT32_C(   578990921), -INT32_C(   685955505), -INT32_C(  1715338980) } },
    { {  INT32_C(  1803220928),  INT32_C(  1209584823),  INT32_C(  1499784536), -INT32_C(  1971192408) },
      UINT8_C(146),
      { -INT32_C(  1982084138),  INT32_C(  1960377934),  INT32_C(  2121379867),  INT32_C(     4160776) },
      {  INT32_C(  1803220928), -INT32_C(  1982084138),  INT32_C(  1499784536), -INT32_C(  1971192408) } },
    { { -INT32_C(   994596105), -INT32_C(  1474494525),  INT32_C(  1632662883), -INT32_C(   856433674) },
      UINT8_C(166),
      { -INT32_C(   839625265), -INT32_C(   555194066),  INT32_C(  1491494874),  INT32_C(  1347413670) },
      { -INT32_C(   994596105), -INT32_C(   839625265), -INT32_C(   555194066), -INT32_C(   856433674) } },
    { { -INT32_C(  1676471395), -INT32_C(  1526678481), -INT32_C(   409247476),  INT32_C(   596535380) },
      UINT8_C(189),
      { -INT32_C(   336859006),  INT32_C(  1086769625), -INT32_C(  1763303760), -INT32_C(  2127284627) },
      { -INT32_C(   336859006), -INT32_C(  1526678481),  INT32_C(  1086769625), -INT32_C(  1763303760) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i src = simde_mm_loadu_epi32(test_vec[i].src);
    simde__mmask8 k = test_vec[i].k;
    simde__m128i r = simde_mm_mask_expandloadu_epi32(src, k, test_vec[i].mem_addr);
    simde_test_x86_assert_equal_i32x4(r, simde_mm_loadu_epi32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_mm_maskz_expandloadu_epi32 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const simde__mmask8 k;
    SIMDE_ALIGN_LIKE_64(simde__m128i) const int32_t mem_addr[4];
    const int32_t r[4];
  } test_vec[] = {
    { UINT8_C( 74),
      { -INT32_C(   804867888), -INT32_C(   248442283), -INT32_C(  2007398662), -INT32_C(  1710614871) },
      {  INT32_C(           0), -INT32_C(   804867888),  INT32_C(           0), -INT32_C(   248442283) } },
    { UINT8_C(  2),
      { -INT32_C(  1127517194), -INT32_C(  1713734733),  INT32_C(  1187989266),  INT32_C(  2031491528) },
      {  INT32_C(           0), -INT32_C(  1127517194),  INT32_C(           0),  INT32_C(           0) } },
    { UINT8_C( 31),
      {  INT32_C(   405982951),  INT32_C(   413019327), -INT32_C(  1104197452),  INT32_C(  1437872610) },
      {  INT32_C(   405982951),  INT32_C(   413019327), -INT32_C(  1104197452),  INT32_C(  1437872610) } },
    { UINT8_C(252),
      {  INT32_C(  1249380464),  INT32_C(  1888651937), -INT32_C(   427140400), -INT32_C(  1563579949) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(  1249380464),  INT32_C(  1888651937) } },
    { UINT8_C(219),
      { -INT32_C(  2079890970), -INT32_C(  1446200454),  INT32_C(   786083450),  INT32_C(   195024387) },
      { -INT32_C(  2079890970), -INT32_C(  1446200454),  INT32_C(           0),  INT32_C(   786083450) } },
    { UINT8_C( 78),
      {  INT32_C(  2077797609), -INT32_C(  1479104483),  INT32_C(  1548790159), -INT32_C(  1388172213) },
      {  INT32_C(           0),  INT32_C(  2077797609), -INT32_C(  1479104483),  INT32_C(  1548790159) } },
    { UINT8_C( 51),
      { -INT32_C(  1813043257), -INT32_C(  1438488112),  INT32_C(   914376087), -INT32_C(    48181423) },
      { -INT32_C(  1813043257), -INT32_C(  1438488112),  INT32_C(           0),  INT32_C(           0) } },
    { UINT8_C(167),
      {  INT32_C(  1901075099),  INT32_C(   303816641),  INT32_C(  2118018619),  INT32_C(   977629459) },
      {  INT32_C(  1901075099),  INT32_C(   303816641),  INT32_C(  2118018619),  INT32_C(           0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__mmask8 k = test_vec[i].k;
    simde__m128i r = simde_mm_maskz_expandloadu_epi32(k, test_vec[i].mem_addr);
    simde_test_x86_assert_equal_i32x4(r, simde_mm_loadu_epi32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_mm256_mask_expandloadu_epi32 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const int32_t src[8];
    const simde__mmask8 k;
    SIMDE_ALIGN_LIKE_64(simde__m256i) const int32_t mem_addr[8];
    const int32_t r[8];
  } test_vec[] = {
    { { -INT32_C(  1807377691), -INT32_C(  1704232880), -INT32_C(  1778826755), -INT32_C(    21052482),  INT32_C(   806970891),  INT32_C(   545047790),  INT32_C(   398939030), -INT32_C(  1548893250) },
      UINT8_C( 93),
      {  INT32_C(  1806579955), -INT32_C(   462927709),  INT32_C(    94567746),  INT32_C(   571515067),  INT32_C(  2098217401),  INT32_C(   269693117), -INT32_C(  1160827913), -INT32_C(   887655720) },
      {  INT32_C(  1806579955), -INT32_C(  1704232880), -INT32_C(   462927709),  INT32_C(    94567746),  INT32_C(   571515067),  INT32_C(   545047790),  INT32_C(  2098217401), -INT32_C(  1548893250) } },
    { {  INT32_C(  1295500714),  INT32_C(  1345429262),  INT32_C(  1482019997),  INT32_C(   779773556),  INT32_C(  1688963751), -INT32_C(  1317748806), -INT32_C(  1033157654),  INT32_C(  1619952566) },
      UINT8_C( 72),
      {  INT32_C(  1683402437), -INT32_C(  1291737377),  INT32_C(  1646811900),  INT32_C(  1594447572), -INT32_C(  1072075519),  INT32_C(   631950305), -INT32_C(  1176801994), -INT32_C(  1073595397) },
      {  INT32_C(  1295500714),  INT32_C(  1345429262),  INT32_C(  1482019997),  INT32_C(  1683402437),  INT32_C(  1688963751), -INT32_C(  1317748806), -INT32_C(  1291737377),  INT32_C(  1619952566) } },
    { { -INT32_C(   920364823), -INT32_C(    75749633),  INT32_C(  1415423104), -INT32_C(    55351558), -INT32_C(  1262694957), -INT32_C(   824612968), -INT32_C(   813124396), -INT32_C(   644904208) },
      UINT8_C(226),
      { -INT32_C(   639524173), -INT32_C(  1017521121), -INT32_C(  1614893511),  INT32_C(   779270753), -INT32_C(   574216330), -INT32_C(  1246653184), -INT32_C(  1482325987), -INT32_C(  1014399473) },
      { -INT32_C(   920364823), -INT32_C(   639524173),  INT32_C(  1415423104), -INT32_C(    55351558), -INT32_C(  1262694957), -INT32_C(  1017521121), -INT32_C(  1614893511),  INT32_C(   779270753) } },
    { {  INT32_C(  1083992865), -INT32_C(  2130446777),  INT32_C(    86032804), -INT32_C(   231435397), -INT32_C(  1160774982), -INT32_C(  1401978481),  INT32_C(   290657281), -INT32_C(  1261118061) },
      UINT8_C( 72),
      {  INT32_C(  1720710256), -INT32_C(  1190522633), -INT32_C(  1003220943),  INT32_C(  1048454724),  INT32_C(  2010003702), -INT32_C(  1132954968), -INT32_C(  1420850738), -INT32_C(   822934691) },
      {  INT32_C(  1083992865), -INT32_C(  2130446777),  INT32_C(    86032804),  INT32_C(  1720710256), -INT32_C(  1160774982), -INT32_C(  1401978481), -INT32_C(  1190522633), -INT32_C(  1261118061) } },
    { { -INT32_C(   281771273), -INT32_C(   995606637), -INT32_C(  1819747249), -INT32_C(   103741949), -INT32_C(   428826818), -INT32_C(   391911398), -INT32_C(   812387726), -INT32_C(   308443402) },
      UINT8_C(  8),
      {  INT32_C(   295427282),  INT32_C(  1633705860), -INT32_C(   312151065),  INT32_C(  1680629188), -INT32_C(  1250028851), -INT32_C(  1473812811),  INT32_C(  2141124601),  INT32_C(  1720159124) },
      { -INT32_C(   281771273), -INT32_C(   995606637), -INT32_C(  1819747249),  INT32_C(   295427282), -INT32_C(   428826818), -INT32_C(   391911398), -INT32_C(   812387726), -INT32_C(   308443402) } },
    { { -INT32_C(   327736472),  INT32_C(  1783486338), -INT32_C(  1890078262), -INT32_C(   604798194),  INT32_C(  1267822998), -INT32_C(   789333801),  INT32_C(  1146065327), -INT32_C(  2052401635) },
      UINT8_C(249),
      { -INT32_C(   109285086),  INT32_C(  1891952319), -INT32_C(  1048620227), -INT32_C(  1219012026), -INT32_C(  1534156053),  INT32_C(   659775126), -INT32_C(  2092656723),  INT32_C(  1685965122) },
      { -INT32_C(   109285086),  INT32_C(  1783486338), -INT32_C(  1890078262),  INT32_C(  1891952319), -INT32_C(  1048620227), -INT32_C(  1219012026), -INT32_C(  1534156053),  INT32_C(   659775126) } },
    { { -INT32_C(    94504645),  INT32_C(   476717535), -INT32_C(  1159861900),  INT32_C(   795948100),  INT32_C(  1842610135),  INT32_C(   177481565),  INT32_C(     9361854), -INT32_C(   580645982) },
      UINT8_C(  4),
      { -INT32_C(   471607358),  INT32_C(   727252802),  INT32_C(   292491997), -INT32_C(  2081906812), -INT32_C(  1713285774), -INT32_C(  1017582614), -INT32_C(  2073732999),  INT32_C(  2139636669) },
      { -INT32_C(    94504645),  INT32_C(   476717535), -INT32_C(   471607358),  INT32_C(   795948100),  INT32_C(  1842610135),  INT32_C(   177481565),  INT32_C(     9361854), -INT32_C(   580645982) } },
    { {  INT32_C(  1549953818),  INT32_C(  1216920171),  INT32_C(  1364850637),  INT32_C(   164905622), -INT32_C(  2120043113),  INT32_C(   440728225),  INT32_C(   278899283),  INT32_C(   126822381) },
      UINT8_C(147),
      { -INT32_C(  1392614159), -INT32_C(   478591252), -INT32_C(   512046433),  INT32_C(  1417249694),  INT32_C(   552991269), -INT32_C(   378335425), -INT32_C(   690584658),  INT32_C(    57269522) },
      { -INT32_C(  1392614159), -INT32_C(   478591252),  INT32_C(  1364850637),  INT32_C(   164905622), -INT32_C(   512046433),  INT32_C(   440728225),  INT32_C(   278899283),  INT32_C(  1417249694) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256i src = simde_x_mm256_loadu_epi32(test_vec[i].src);
    simde__mmask8 k = test_vec[i].k;
    simde__m256i r = simde_mm256_mask_expandloadu_epi32(src, k, test_vec[i].mem_addr);
    simde_test_x86_assert_equal_i32x8(r, simde_x_mm256_loadu_epi32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_mm256_maskz_expandloadu_epi32 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const simde__mmask8 k;
    SIMDE_ALIGN_LIKE_64(simde__m256i) const int32_t mem_addr[8];
    const int32_t r[8];
  } test_vec[] = {
    { UINT8_C(166),
      {  INT32_C(   153778204), -INT32_C(   592711181),  INT32_C(   298932777),  INT32_C(   778264931), -INT32_C(   278534587),  INT32_C(  2090262096), -INT32_C(   140643639),  INT32_C(   949866012) },
      {  INT32_C(           0),  INT32_C(   153778204), -INT32_C(   592711181),  INT32_C(           0),  INT32_C(           0),  INT32_C(   298932777),  INT32_C(           0),  INT32_C(   778264931) } },
    { UINT8_C( 70),
      { -INT32_C(  1187429945),  INT32_C(  1205999085),  INT32_C(  1219228646),  INT32_C(  1015929174),  INT32_C(   495746367),  INT32_C(    98961427),  INT32_C(  1948442277),  INT32_C(  1136286331) },
      {  INT32_C(           0), -INT32_C(  1187429945),  INT32_C(  1205999085),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(  1219228646),  INT32_C(           0) } },
    { UINT8_C(156),
      {  INT32_C(   160038132), -INT32_C(   772747042),  INT32_C(  1428633723),  INT32_C(  1117021381), -INT32_C(   111758864),  INT32_C(  1973312407), -INT32_C(   655289731), -INT32_C(  1049348915) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(   160038132), -INT32_C(   772747042),  INT32_C(  1428633723),  INT32_C(           0),  INT32_C(           0),  INT32_C(  1117021381) } },
    { UINT8_C( 48),
      { -INT32_C(   854668547), -INT32_C(   230039622),  INT32_C(  1790483974), -INT32_C(   480511438), -INT32_C(  1401269168),  INT32_C(    86634738),  INT32_C(   366084577),  INT32_C(  1917162357) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(   854668547), -INT32_C(   230039622),  INT32_C(           0),  INT32_C(           0) } },
    { UINT8_C( 93),
      {  INT32_C(   840450131),  INT32_C(   657984137), -INT32_C(  1118198846),  INT32_C(  1376599294), -INT32_C(  1505445450), -INT32_C(   460895773), -INT32_C(  1369793509),  INT32_C(   873254113) },
      {  INT32_C(   840450131),  INT32_C(           0),  INT32_C(   657984137), -INT32_C(  1118198846),  INT32_C(  1376599294),  INT32_C(           0), -INT32_C(  1505445450),  INT32_C(           0) } },
    { UINT8_C( 12),
      {  INT32_C(   781542948),  INT32_C(  1123138719),  INT32_C(  1363193365),  INT32_C(  1963496123),  INT32_C(   542682838), -INT32_C(   767869898),  INT32_C(  1672800918),  INT32_C(   443541750) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(   781542948),  INT32_C(  1123138719),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
    { UINT8_C( 79),
      { -INT32_C(  1041348603), -INT32_C(   405327815),  INT32_C(    44247152), -INT32_C(   539486160), -INT32_C(  1407846288),  INT32_C(   507766580), -INT32_C(  2079021413),  INT32_C(   450047509) },
      { -INT32_C(  1041348603), -INT32_C(   405327815),  INT32_C(    44247152), -INT32_C(   539486160),  INT32_C(           0),  INT32_C(           0), -INT32_C(  1407846288),  INT32_C(           0) } },
    { UINT8_C(118),
      { -INT32_C(   240067391), -INT32_C(   614361165),  INT32_C(  1376543546),  INT32_C(   885189435), -INT32_C(   412586240),  INT32_C(  1485014706), -INT32_C(   932378726), -INT32_C(  1690400550) },
      {  INT32_C(           0), -INT32_C(   240067391), -INT32_C(   614361165),  INT32_C(           0),  INT32_C(  1376543546),  INT32_C(   885189435), -INT32_C(   412586240),  INT32_C(           0) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__mmask8 k = test_vec[i].k;
    simde__m256i r = simde_mm256_maskz_expandloadu_epi32(k, test_vec[i].mem_addr);
    simde_test_x86_assert_equal_i32x8(r, simde_x_mm256_loadu_epi32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_mm512_mask_expandloadu_epi32 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const int32_t src[16];
    const simde__mmask16 k;
    SIMDE_ALIGN_LIKE_64(simde__m512i) const int32_t mem_addr[16];
    const int32_t r[16];
  } test_vec[] = {
    { { -INT32_C(   922036128),  INT32_C(  1617015834),  INT32_C(    78747445),  INT32_C(  1403760311), -INT32_C(  1966801975),  INT32_C(   379379674),  INT32_C(  1502927430), -INT32_C(  1399531188),
        -INT32_C(   864641359), -INT32_C(  2010327213),  INT32_C(   646765934),  INT32_C(  1417230219),  INT32_C(   232734003),  INT32_C(  1663269661), -INT32_C(  1564690602),  INT32_C(  1112428688) },
      UINT16_C(50415),
      {  INT32_C(   983253518),  INT32_C(  1444350666), -INT32_C(  1450335696), -INT32_C(   689520393), -INT32_C(   246348850),  INT32_C(   598320998), -INT32_C(  1737279159), -INT32_C(  1990434181),
         INT32_C(  1858336932),  INT32_C(   851761666),  INT32_C(  1960530557), -INT32_C(   531971822),  INT32_C(   735222725), -INT32_C(  1941013693),  INT32_C(   807715508), -INT32_C(   910589660) },
      {  INT32_C(   983253518),  INT32_C(  1444350666), -INT32_C(  1450335696), -INT32_C(   689520393), -INT32_C(  1966801975), -INT32_C(   246348850),  INT32_C(   598320998), -INT32_C(  1737279159),
        -INT32_C(   864641359), -INT32_C(  2010327213), -INT32_C(  1990434181),  INT32_C(  1417230219),  INT32_C(   232734003),  INT32_C(  1663269661),  INT32_C(  1858336932),  INT32_C(   851761666) } },
    { {  INT32_C(  2067234169), -INT32_C(   726795177),  INT32_C(  1615366222),  INT32_C(   239178313),  INT32_C(  1899631406),  INT32_C(  1123911822),  INT32_C(  1869750858),  INT32_C(   473443491),
         INT32_C(     9924521), -INT32_C(  1177205653),  INT32_C(   354033100), -INT32_C(   568042576), -INT32_C(    61907346),  INT32_C(   826166502),  INT32_C(   295743854), -INT32_C(  2043815715) },
      UINT16_C(50247),
      {  INT32_C(  1527296902), -INT32_C(  2038836116),  INT32_C(   249637354),  INT32_C(  1449938695), -INT32_C(  1969073589),  INT32_C(   591073667),  INT32_C(  1358632994),  INT32_C(   605307806),
         INT32_C(  1652563446), -INT32_C(   605423119),  INT32_C(   703187490),  INT32_C(  1702843674),  INT32_C(   737092008),  INT32_C(  1431251506), -INT32_C(   526038462), -INT32_C(  2096776819) },
      {  INT32_C(  1527296902), -INT32_C(  2038836116),  INT32_C(   249637354),  INT32_C(   239178313),  INT32_C(  1899631406),  INT32_C(  1123911822),  INT32_C(  1449938695),  INT32_C(   473443491),
         INT32_C(     9924521), -INT32_C(  1177205653), -INT32_C(  1969073589), -INT32_C(   568042576), -INT32_C(    61907346),  INT32_C(   826166502),  INT32_C(   591073667),  INT32_C(  1358632994) } },
    { { -INT32_C(   924416554), -INT32_C(  1599877250), -INT32_C(  1278636647), -INT32_C(  1978054430), -INT32_C(  1665791895),  INT32_C(  1978729779), -INT32_C(   581527985),  INT32_C(   643849039),
         INT32_C(  1592674016), -INT32_C(  1342271211),  INT32_C(    23250718),  INT32_C(  2022406927), -INT32_C(  1223409276), -INT32_C(  1775499962), -INT32_C(   344751461), -INT32_C(  1122905123) },
      UINT16_C(65306),
      {  INT32_C(   428879643),  INT32_C(  1105244126),  INT32_C(  1002237872),  INT32_C(  2088583272),  INT32_C(   612549623), -INT32_C(   861528743),  INT32_C(   429949960),  INT32_C(  1561901633),
        -INT32_C(   931747351),  INT32_C(   134829912), -INT32_C(  1371290298), -INT32_C(    47464442), -INT32_C(   584995452), -INT32_C(   743782198), -INT32_C(  1913894324), -INT32_C(   303430396) },
      { -INT32_C(   924416554),  INT32_C(   428879643), -INT32_C(  1278636647),  INT32_C(  1105244126),  INT32_C(  1002237872),  INT32_C(  1978729779), -INT32_C(   581527985),  INT32_C(   643849039),
         INT32_C(  2088583272),  INT32_C(   612549623), -INT32_C(   861528743),  INT32_C(   429949960),  INT32_C(  1561901633), -INT32_C(   931747351),  INT32_C(   134829912), -INT32_C(  1371290298) } },
    { {  INT32_C(   112550318), -INT32_C(    32588104), -INT32_C(  1968352892), -INT32_C(  1769482222),  INT32_C(  1332980101), -INT32_C(  1121837711),  INT32_C(  1800015719), -INT32_C(  1034341100),
         INT32_C(  1321733782),  INT32_C(  1363990221),  INT32_C(   970717479),  INT32_C(  1456431825),  INT32_C(  2091270923), -INT32_C(   935737248), -INT32_C(   348945193),  INT32_C(  1336773817) },
      UINT16_C(30107),
      { -INT32_C(   380933987), -INT32_C(  1797033031),  INT32_C(  2096542892), -INT32_C(  1312882165), -INT32_C(  1200021634),  INT32_C(   456937959), -INT32_C(   358091460), -INT32_C(   513850812),
         INT32_C(  1674226602), -INT32_C(   889737954),  INT32_C(  1833365090),  INT32_C(  1847461360),  INT32_C(   203855653),  INT32_C(   623338216), -INT32_C(  1693462697), -INT32_C(  1132696047) },
      { -INT32_C(   380933987), -INT32_C(  1797033031), -INT32_C(  1968352892),  INT32_C(  2096542892), -INT32_C(  1312882165), -INT32_C(  1121837711),  INT32_C(  1800015719), -INT32_C(  1200021634),
         INT32_C(   456937959),  INT32_C(  1363990221), -INT32_C(   358091460),  INT32_C(  1456431825), -INT32_C(   513850812),  INT32_C(  1674226602), -INT32_C(   889737954),  INT32_C(  1336773817) } },
    { {  INT32_C(   924796697),  INT32_C(  1442977780), -INT32_C(   171751419),  INT32_C(  1935925582),  INT32_C(  1635748473),  INT32_C(  1149675500), -INT32_C(  2015390346),  INT32_C(   490953732),
        -INT32_C(  1756011613),  INT32_C(  2146326394), -INT32_C(   311119457),  INT32_C(   207673235),  INT32_C(  1315823713), -INT32_C(    40700793), -INT32_C(  1920700023),  INT32_C(  1890306253) },
      UINT16_C(   43),
      { -INT32_C(   162028280), -INT32_C(  1733822940),  INT32_C(  1148140260), -INT32_C(  1272655546), -INT32_C(  1314346209),  INT32_C(   757215656),  INT32_C(  1794502847),  INT32_C(  1751785568),
        -INT32_C(   379665979), -INT32_C(  1686042953), -INT32_C(  2015301568), -INT32_C(   533003071),  INT32_C(  1485956016), -INT32_C(   746212332),  INT32_C(    71137956),  INT32_C(  1601021850) },
      { -INT32_C(   162028280), -INT32_C(  1733822940), -INT32_C(   171751419),  INT32_C(  1148140260),  INT32_C(  1635748473), -INT32_C(  1272655546), -INT32_C(  2015390346),  INT32_C(   490953732),
        -INT32_C(  1756011613),  INT32_C(  2146326394), -INT32_C(   311119457),  INT32_C(   207673235),  INT32_C(  1315823713), -INT32_C(    40700793), -INT32_C(  1920700023),  INT32_C(  1890306253) } },
    { {  INT32_C(   541641576),  INT32_C(   314296785),  INT32_C(  2073664442),  INT32_C(  1348261024), -INT32_C(   878121545),  INT32_C(  1168060065),  INT32_C(  1128979624), -INT32_C(   324880508),
         INT32_C(  1410132866),  INT32_C(  1852229812),  INT32_C(    65732451), -INT32_C(  1974253869), -INT32_C(   715785165), -INT32_C(   769985494),  INT32_C(  1427465425), -INT32_C(  1639860197) },
      UINT16_C(20131),
      {  INT32_C(  1477859314), -INT32_C(  1336444474), -INT32_C(   789173635),  INT32_C(   164374964),  INT32_C(   436139774), -INT32_C(   562180151),  INT32_C(  1704368420),  INT32_C(   699611447),
         INT32_C(  1468123537), -INT32_C(  1073227709), -INT32_C(  1232012030),  INT32_C(   633298214),  INT32_C(   473873747), -INT32_C(  1325679732), -INT32_C(  1961455276),  INT32_C(  1555352011) },
      {  INT32_C(  1477859314), -INT32_C(  1336444474),  INT32_C(  2073664442),  INT32_C(  1348261024), -INT32_C(   878121545), -INT32_C(   789173635),  INT32_C(  1128979624),  INT32_C(   164374964),
         INT32_C(  1410132866),  INT32_C(   436139774), -INT32_C(   562180151),  INT32_C(  1704368420), -INT32_C(   715785165), -INT32_C(   769985494),  INT32_C(   699611447), -INT32_C(  1639860197) } },
    { { -INT32_C(   692898413),  INT32_C(   261536269), -INT32_C(   574282057), -INT32_C(   687700605), -INT32_C(   806141886),  INT32_C(  1350561532),  INT32_C(  1272747392), -INT32_C(   223899553),
        -INT32_C(   741844282), -INT32_C(   874291692),  INT32_C(   145270916),  INT32_C(  1893706541), -INT32_C(   415247637),  INT32_C(  1094237889), -INT32_C(  1282665388),  INT32_C(  1789211556) },
      UINT16_C(28045),
      {  INT32_C(   566993214),  INT32_C(   348737388),  INT32_C(   918550359), -INT32_C(  1509315737), -INT32_C(   899364206), -INT32_C(  1747011573),  INT32_C(   281707371),  INT32_C(   729634797),
         INT32_C(  1682721016), -INT32_C(   277342568),  INT32_C(  1948661773),  INT32_C(  1964650467),  INT32_C(    71335673), -INT32_C(  1566892489), -INT32_C(  1884068447), -INT32_C(  1262866244) },
      {  INT32_C(   566993214),  INT32_C(   261536269),  INT32_C(   348737388),  INT32_C(   918550359), -INT32_C(   806141886),  INT32_C(  1350561532),  INT32_C(  1272747392), -INT32_C(  1509315737),
        -INT32_C(   899364206), -INT32_C(   874291692), -INT32_C(  1747011573),  INT32_C(   281707371), -INT32_C(   415247637),  INT32_C(   729634797),  INT32_C(  1682721016),  INT32_C(  1789211556) } },
    { {  INT32_C(   286787449),  INT32_C(   704679965), -INT32_C(  1415698744),  INT32_C(  1310832725),  INT32_C(  1834115382),  INT32_C(   554757503),  INT32_C(   246465362),  INT32_C(  1824680691),
        -INT32_C(  1904354703),  INT32_C(   867729003), -INT32_C(    86026588),  INT32_C(  1162346510), -INT32_C(   525165727), -INT32_C(   620641656),  INT32_C(  2045358469), -INT32_C(  1914328036) },
      UINT16_C(25478),
      { -INT32_C(   723390180),  INT32_C(    69960997), -INT32_C(   939247233),  INT32_C(   828597630),  INT32_C(  1207167813), -INT32_C(  1325893178), -INT32_C(   681831182), -INT32_C(  1103437150),
        -INT32_C(   107865132),  INT32_C(   553500065),  INT32_C(  1978139127), -INT32_C(  1415165082), -INT32_C(    34432457),  INT32_C(    95283987), -INT32_C(  1579415041), -INT32_C(  1067509780) },
      {  INT32_C(   286787449), -INT32_C(   723390180),  INT32_C(    69960997),  INT32_C(  1310832725),  INT32_C(  1834115382),  INT32_C(   554757503),  INT32_C(   246465362), -INT32_C(   939247233),
         INT32_C(   828597630),  INT32_C(  1207167813), -INT32_C(    86026588),  INT32_C(  1162346510), -INT32_C(   525165727), -INT32_C(  1325893178), -INT32_C(   681831182), -INT32_C(  1914328036) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i src = simde_mm512_loadu_epi32(test_vec[i].src);
    simde__mmask16 k = test_vec[i].k;
    simde__m512i r = simde_mm512_mask_expandloadu_epi32(src, k, test_vec[i].mem_addr);
    simde_test_x86_assert_equal_i32x16(r, simde_mm512_loadu_epi32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_mm512_maskz_expandloadu_epi32 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const simde__mmask16 k;
    SIMDE_ALIGN_LIKE_64(simde__m512i) const int32_t mem_addr[16];
    const int32_t r[16];
  } test_vec[] = {
    { UINT16_C(   50),
      { -INT32_C(  1345078798), -INT32_C(  1213795146),  INT32_C(   672996572),  INT32_C(  1549781186), -INT32_C(  1502651205),  INT32_C(   329610250),  INT32_C(  1761560401), -INT32_C(  1734688858),
         INT32_C(   776498808),  INT32_C(  1055256162), -INT32_C(   848952822), -INT32_C(  2044082741),  INT32_C(   741120290),  INT32_C(  1581240589), -INT32_C(  1077526760),  INT32_C(  2002215422) },
      {  INT32_C(           0), -INT32_C(  1345078798),  INT32_C(           0),  INT32_C(           0), -INT32_C(  1213795146),  INT32_C(   672996572),  INT32_C(           0),  INT32_C(           0),
         INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
    { UINT16_C(  207),
      { -INT32_C(  1909348961), -INT32_C(  1919389813), -INT32_C(  1688705578),  INT32_C(   683531919), -INT32_C(   600446710),  INT32_C(  1760859177), -INT32_C(  1150897318), -INT32_C(  1433740021),
         INT32_C(   238599043),  INT32_C(    26988843), -INT32_C(   979569610), -INT32_C(   571647278),  INT32_C(  1824072515),  INT32_C(   299150775),  INT32_C(  1825389409), -INT32_C(  1693034728) },
      { -INT32_C(  1909348961), -INT32_C(  1919389813), -INT32_C(  1688705578),  INT32_C(   683531919),  INT32_C(           0),  INT32_C(           0), -INT32_C(   600446710),  INT32_C(  1760859177),
         INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
    { UINT16_C(   19),
      {  INT32_C(   540977487),  INT32_C(   961953605),  INT32_C(   889920731),  INT32_C(   746186761),  INT32_C(  1340335521), -INT32_C(   172952134),  INT32_C(   420289730), -INT32_C(  2127779534),
        -INT32_C(  1751029166), -INT32_C(  2049902423),  INT32_C(   498785300),  INT32_C(  1716138948), -INT32_C(   743101159), -INT32_C(   456628958), -INT32_C(  1275144831), -INT32_C(   785044866) },
      {  INT32_C(   540977487),  INT32_C(   961953605),  INT32_C(           0),  INT32_C(           0),  INT32_C(   889920731),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
         INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
    { UINT16_C(  149),
      { -INT32_C(   834770730),  INT32_C(   367182649), -INT32_C(  1311178626),  INT32_C(  2009743178),  INT32_C(  1503305204),  INT32_C(  1004174949), -INT32_C(  1481011588), -INT32_C(  1724085565),
         INT32_C(   745044723), -INT32_C(  1136571842), -INT32_C(  1804789174),  INT32_C(  1309423706),  INT32_C(  1000908501), -INT32_C(  1586068956), -INT32_C(   750244080), -INT32_C(  1385331526) },
      { -INT32_C(   834770730),  INT32_C(           0),  INT32_C(   367182649),  INT32_C(           0), -INT32_C(  1311178626),  INT32_C(           0),  INT32_C(           0),  INT32_C(  2009743178),
         INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
    { UINT16_C(  254),
      {  INT32_C(   524081621),  INT32_C(   879425562), -INT32_C(  1634795930), -INT32_C(  1334584054),  INT32_C(   131444357),  INT32_C(  1410889252),  INT32_C(  1108274110),  INT32_C(   759216984),
        -INT32_C(  1370653292), -INT32_C(   605898891), -INT32_C(  1065782859), -INT32_C(   747573938), -INT32_C(  1059437157),  INT32_C(  2031415995),  INT32_C(   918233822),  INT32_C(  1902443741) },
      {  INT32_C(           0),  INT32_C(   524081621),  INT32_C(   879425562), -INT32_C(  1634795930), -INT32_C(  1334584054),  INT32_C(   131444357),  INT32_C(  1410889252),  INT32_C(  1108274110),
         INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
    { UINT16_C(  121),
      {  INT32_C(  1760436145),  INT32_C(  1914554881),  INT32_C(   817945923), -INT32_C(  1815309490),  INT32_C(  1615826030), -INT32_C(  1036072800), -INT32_C(  2137033340), -INT32_C(  1963388711),
         INT32_C(   821225263), -INT32_C(   173862991),  INT32_C(   992306157),  INT32_C(  1708061175),  INT32_C(   499457405),  INT32_C(  1793000678),  INT32_C(  1391099513), -INT32_C(  1109597298) },
      {  INT32_C(  1760436145),  INT32_C(           0),  INT32_C(           0),  INT32_C(  1914554881),  INT32_C(   817945923), -INT32_C(  1815309490),  INT32_C(  1615826030),  INT32_C(           0),
         INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
    { UINT16_C(  202),
      { -INT32_C(   579014962), -INT32_C(   188059247), -INT32_C(  1997863530), -INT32_C(   251309868),  INT32_C(   450306838), -INT32_C(  2121055998),  INT32_C(   235922731), -INT32_C(  1881551423),
         INT32_C(  1282168251),  INT32_C(  1547712454),  INT32_C(   283388988), -INT32_C(  1845302660),  INT32_C(   262985997),  INT32_C(  1183858459), -INT32_C(   447373276),  INT32_C(   678702701) },
      {  INT32_C(           0), -INT32_C(   579014962),  INT32_C(           0), -INT32_C(   188059247),  INT32_C(           0),  INT32_C(           0), -INT32_C(  1997863530), -INT32_C(   251309868),
         INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
    { UINT16_C(  131),
      {  INT32_C(   407467233), -INT32_C(   531323468),  INT32_C(  1952277898),  INT32_C(  1082257255), -INT32_C(   614756196), -INT32_C(  1056923103),  INT32_C(   623830519),  INT32_C(  1000887898),
         INT32_C(  2119430602),  INT32_C(   543139734),  INT32_C(  1939127308),  INT32_C(  1202984363), -INT32_C(   954003546), -INT32_C(  1467472975),  INT32_C(  1657648648), -INT32_C(   694323956) },
      {  INT32_C(   407467233), -INT32_C(   531323468),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(  1952277898),
         INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__mmask16 k = test_vec[i].k;
    simde__m512i r = simde_mm512_maskz_expandloadu_epi32(k, test_vec[i].mem_addr);
    simde_test_x86_assert_equal_i32x16(r, simde_mm512_loadu_epi32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_mm_mask_expandloadu_epi64 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const int64_t src[2];
    const simde__mmask8 k;
    SIMDE_ALIGN_LIKE_64(simde__m128i) const int64_t mem_addr[2];
    const int64_t r[2];
  } test_vec[] = {
    { { -INT64_C( 6620938407498157978),  INT64_C( 7882087453376950895) },
      UINT8_C(219),
      {  INT64_C( 8264445875599520901), -INT64_C( 6782609392589204733) },
      {  INT64_C( 8264445875599520901), -INT64_C( 6782609392589204733) } },
    { { -INT64_C( 6067229435399381847), -INT64_C( 3486383929115285514) },
      UINT8_C( 21),
      {  INT64_C( 4351396605183751978), -INT64_C( 7583904842575389758) },
      {  INT64_C( 4351396605183751978), -INT64_C( 3486383929115285514) } },
    { { -INT64_C( 3486846141078692664),  INT64_C( 2784606636757049006) },
      UINT8_C( 95),
      { -INT64_C( 4288336237044398475),  INT64_C( 8000386710338769841) },
      { -INT64_C( 4288336237044398475),  INT64_C( 8000386710338769841) } },
    { { -INT64_C( 6372831749439181403),  INT64_C( 4073727698699230784) },
      UINT8_C( 79),
      {  INT64_C(   37713720544653584),  INT64_C( 8734383810710586491) },
      {  INT64_C(   37713720544653584),  INT64_C( 8734383810710586491) } },
    { { -INT64_C( 4214407559676487909),  INT64_C( 4838484703554611981) },
      UINT8_C(177),
      {  INT64_C( 7049575548105725789), -INT64_C( 5453394479619938701) },
      {  INT64_C( 7049575548105725789),  INT64_C( 4838484703554611981) } },
    { { -INT64_C( 4404202578655866007),  INT64_C( 4258780020760492201) },
      UINT8_C( 80),
      { -INT64_C( 3329199805851396807), -INT64_C( 1834334682784857477) },
      { -INT64_C( 4404202578655866007),  INT64_C( 4258780020760492201) } },
    { { -INT64_C(  555984269697261698),  INT64_C(  377758986312004020) },
      UINT8_C(166),
      {  INT64_C( 3239461604522221099), -INT64_C(    4391859837266609) },
      { -INT64_C(  555984269697261698),  INT64_C( 3239461604522221099) } },
    { { -INT64_C( 8586613142908268702),  INT64_C( 3226081469924623118) },
      UINT8_C(182),
      { -INT64_C( 5834680937880705578), -INT64_C(  553011012797761141) },
      { -INT64_C( 8586613142908268702), -INT64_C( 5834680937880705578) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i src = simde_mm_loadu_epi64(test_vec[i].src);
    simde__mmask8 k = test_vec[i].k;
    simde__m128i r = simde_mm_mask_expandloadu_epi64(src, k, test_vec[i].mem_addr);
    simde_test_x86_assert_equal_i64x2(r, simde_mm_loadu_epi64(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_mm_maskz_expandloadu_epi64 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const simde__mmask8 k;
    SIMDE_ALIGN_LIKE_64(simde__m128i) const int64_t mem_addr[2];
    const int64_t r[2];
  } test_vec[] = {
    { UINT8_C(143),
      { -INT64_C( 6192776767165968523), -INT64_C( 2120710279028076299) },
      { -INT64_C( 6192776767165968523), -INT64_C( 2120710279028076299) } },
    { UINT8_C(154),
      {  INT64_C( 8847376625275665224), -INT64_C(  510217197666619101) },
      {  INT64_C(                   0),  INT64_C( 8847376625275665224) } },
    { UINT8_C( 31),
      { -INT64_C(  191987948945322186), -INT64_C( 1189143320816348762) },
      { -INT64_C(  191987948945322186), -INT64_C( 1189143320816348762) } },
    { UINT8_C(247),
      {  INT64_C( 6685959318588168655),  INT64_C( 4243750857603347138) },
      {  INT64_C( 6685959318588168655),  INT64_C( 4243750857603347138) } },
    { UINT8_C(201),
      { -INT64_C( 1724779488657263575), -INT64_C( 8295578346654760047) },
      { -INT64_C( 1724779488657263575),  INT64_C(                   0) } },
    { UINT8_C( 88),
      {  INT64_C( 3473233520990887799), -INT64_C( 8276544808646599147) },
      {  INT64_C(                   0),  INT64_C(                   0) } },
    { UINT8_C(130),
      { -INT64_C( 2362860767258231135),  INT64_C( 6041410895476598655) },
      {  INT64_C(                   0), -INT64_C( 2362860767258231135) } },
    { UINT8_C( 11),
      {  INT64_C(  317653304265068311),  INT64_C(  884205598597628289) },
      {  INT64_C(  317653304265068311),  INT64_C(  884205598597628289) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__mmask8 k = test_vec[i].k;
    simde__m128i r = simde_mm_maskz_expandloadu_epi64(k, test_vec[i].mem_addr);
    simde_test_x86_assert_equal_i64x2(r, simde_mm_loadu_epi64(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_mm256_mask_expandloadu_epi64 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const int64_t src[4];
    const simde__mmask8 k;
    SIMDE_ALIGN_LIKE_64(simde__m256i) const int64_t mem_addr[4];
    const int64_t r[4];
  } test_vec[] = {
    { { -INT64_C( 3233705287056361679),  INT64_C( 7859725100223266720), -INT64_C( 8202145580458670807), -INT64_C( 8918121962942562591) },
      UINT8_C(110),
      { -INT64_C( 4386103321570958097), -INT64_C( 4469675034434524811),  INT64_C( 5422435438743658558), -INT64_C( 7245126678779891570) },
      { -INT64_C( 3233705287056361679), -INT64_C( 4386103321570958097), -INT64_C( 4469675034434524811),  INT64_C( 5422435438743658558) } },
    { { -INT64_C(  986783658933481657),  INT64_C( 3198886069923833702),  INT64_C( 2121983289643971289),  INT64_C( 8900124637319598140) },
      UINT8_C(167),
      { -INT64_C( 4881033013118105953),  INT64_C( 8964933244217386455),  INT64_C( 1326917030041587810),  INT64_C( 8398019054564430412) },
      { -INT64_C( 4881033013118105953),  INT64_C( 8964933244217386455),  INT64_C( 1326917030041587810),  INT64_C( 8900124637319598140) } },
    { { -INT64_C( 7144515759541997625), -INT64_C( 4809961659954330759), -INT64_C( 4739380609558033883),  INT64_C(  644627455988105384) },
      UINT8_C(220),
      { -INT64_C( 9128446804954634941), -INT64_C( 7123400124539333527),  INT64_C(  469445864756038788),  INT64_C( 3997595526995837296) },
      { -INT64_C( 7144515759541997625), -INT64_C( 4809961659954330759), -INT64_C( 9128446804954634941), -INT64_C( 7123400124539333527) } },
    { { -INT64_C( 4326728504225948556), -INT64_C( 1340974922045665165), -INT64_C( 5638986937776180430), -INT64_C( 3929731157351004852) },
      UINT8_C(230),
      {  INT64_C(   24772206961572997), -INT64_C(  730332445342622012),  INT64_C( 6536384783926597150), -INT64_C( 1087768384001542857) },
      { -INT64_C( 4326728504225948556),  INT64_C(   24772206961572997), -INT64_C(  730332445342622012), -INT64_C( 3929731157351004852) } },
    { { -INT64_C( 1304868334074517836), -INT64_C( 4412834234673640117),  INT64_C( 1709927362343008268), -INT64_C( 7623749871948240426) },
      UINT8_C( 37),
      { -INT64_C( 5944685128531936505),  INT64_C(  600688560987786708), -INT64_C( 2596325798790514881),  INT64_C( 8303603536667425047) },
      { -INT64_C( 5944685128531936505), -INT64_C( 4412834234673640117),  INT64_C(  600688560987786708), -INT64_C( 7623749871948240426) } },
    { { -INT64_C( 7216129146279654706),  INT64_C( 9191350133036756085), -INT64_C( 8268723856078768397),  INT64_C( 2211514052275141841) },
      UINT8_C(106),
      {  INT64_C( 6050247619445345368), -INT64_C( 9160301808221717583), -INT64_C( 9143851489222572622),  INT64_C( 6949879992756033319) },
      { -INT64_C( 7216129146279654706),  INT64_C( 6050247619445345368), -INT64_C( 8268723856078768397), -INT64_C( 9160301808221717583) } },
    { {  INT64_C( 2357589803368817468),  INT64_C( 1070992891856177746),  INT64_C( 9023369040904049203),  INT64_C( 3833397785668094665) },
      UINT8_C(153),
      { -INT64_C( 7332940665765455597),  INT64_C( 5069087752481839159),  INT64_C( 6095368429737087323), -INT64_C( 5967969231259735907) },
      { -INT64_C( 7332940665765455597),  INT64_C( 1070992891856177746),  INT64_C( 9023369040904049203),  INT64_C( 5069087752481839159) } },
    { { -INT64_C( 7636182611851266532),  INT64_C( 6568240575562906732),  INT64_C( 8846126146076132133), -INT64_C( 5733016815528963800) },
      UINT8_C(113),
      {  INT64_C( 2182106319380552712),  INT64_C( 1467180968323197218), -INT64_C( 6878285742293791838), -INT64_C( 4168392897366569351) },
      {  INT64_C( 2182106319380552712),  INT64_C( 6568240575562906732),  INT64_C( 8846126146076132133), -INT64_C( 5733016815528963800) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256i src = simde_mm256_loadu_epi64(test_vec[i].src);
    simde__mmask8 k = test_vec[i].k;
    simde__m256i r = simde_mm256_mask_expandloadu_epi64(src, k, test_vec[i].mem_addr);
    simde_test_x86_assert_equal_i64x4(r, simde_mm256_loadu_epi64(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_mm256_maskz_expandloadu_epi64 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const simde__mmask8 k;
    SIMDE_ALIGN_LIKE_64(simde__m256i) const int64_t mem_addr[4];
    const int64_t r[4];
  } test_vec[] = {
    { UINT8_C(  0),
      {  INT64_C( 1476970582424855286), -INT64_C( 2487541627121978018), -INT64_C( 5382069389565830037),  INT64_C( 2316040056754930496) },
      {  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0) } },
    { UINT8_C(221),
      { -INT64_C( 5628130657155121850),  INT64_C( 1308190369435073346),  INT64_C( 5717371730821512460), -INT64_C( 1820974183128400733) },
      { -INT64_C( 5628130657155121850),  INT64_C(                   0),  INT64_C( 1308190369435073346),  INT64_C( 5717371730821512460) } },
    { UINT8_C( 22),
      {  INT64_C(  838165755627465858), -INT64_C( 9137148866938708602),  INT64_C( 2206232353792936652), -INT64_C( 5096768325657133931) },
      {  INT64_C(                   0),  INT64_C(  838165755627465858), -INT64_C( 9137148866938708602),  INT64_C(                   0) } },
    { UINT8_C( 16),
      {  INT64_C( 1630422607375374422),  INT64_C( 4957368046099023789), -INT64_C( 2118374738997360408),  INT64_C( 7167709761983072451) },
      {  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0) } },
    { UINT8_C(234),
      { -INT64_C( 1877234554991575591), -INT64_C( 8766781423330856365), -INT64_C( 4768801883279238647), -INT64_C( 8384526360595777048) },
      {  INT64_C(                   0), -INT64_C( 1877234554991575591),  INT64_C(                   0), -INT64_C( 8766781423330856365) } },
    { UINT8_C(171),
      { -INT64_C( 5452822575555424185),  INT64_C( 8266630996161642892), -INT64_C( 3342194738971883802),  INT64_C( 4955664920218917101) },
      { -INT64_C( 5452822575555424185),  INT64_C( 8266630996161642892),  INT64_C(                   0), -INT64_C( 3342194738971883802) } },
    { UINT8_C(222),
      {  INT64_C( 6541852946578032015), -INT64_C(  673882770712201018),  INT64_C( 5862384864842373962), -INT64_C( 3760906748868790558) },
      {  INT64_C(                   0),  INT64_C( 6541852946578032015), -INT64_C(  673882770712201018),  INT64_C( 5862384864842373962) } },
    { UINT8_C(216),
      {  INT64_C( 5370765557898414190),  INT64_C( 5217826906534725692), -INT64_C( 6322892032289155073),  INT64_C( 7803805761743892705) },
      {  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C( 5370765557898414190) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__mmask8 k = test_vec[i].k;
    simde__m256i r = simde_mm256_maskz_expandloadu_epi64(k, test_vec[i].mem_addr);
    simde_test_x86_assert_equal_i64x4(r, simde_mm256_loadu_epi64(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_mm512_mask_expandloadu_epi64 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const int64_t src[8];
    const simde__mmask8 k;
    SIMDE_ALIGN_LIKE_64(simde__m512i) const int64_t mem_addr[8];
    const int64_t r[8];
  } test_vec[] = {
    { {  INT64_C( 1863730804855264457), -INT64_C( 4506351302470454347),  INT64_C( 1866362986000551131),  INT64_C( 3801974231157508705),
         INT64_C( 2201122676118395943), -INT64_C( 4591617845899187160), -INT64_C( 3481009358092712104), -INT64_C( 9177782602148084478) },
      UINT8_C( 19),
      {  INT64_C( 3015049439648477881),  INT64_C( 7716019268517518704),  INT64_C( 6979075684997639136), -INT64_C( 6636270749936432932),
         INT64_C( 8057547761841693740), -INT64_C( 8172837406523006843), -INT64_C(  962011010294190614), -INT64_C( 4245296199159619704) },
      {  INT64_C( 3015049439648477881),  INT64_C( 7716019268517518704),  INT64_C( 1866362986000551131),  INT64_C( 3801974231157508705),
         INT64_C( 6979075684997639136), -INT64_C( 4591617845899187160), -INT64_C( 3481009358092712104), -INT64_C( 9177782602148084478) } },
    { {  INT64_C( 1477251660977694225), -INT64_C( 3072348935554159840), -INT64_C( 8410541559034166720), -INT64_C( 3711226970424668896),
         INT64_C( 5700533680642846329),  INT64_C( 7910988558223890952), -INT64_C( 4194246923109866436),  INT64_C( 6097873740077451287) },
      UINT8_C(237),
      { -INT64_C( 3179142794675790724), -INT64_C( 9061684874816989816),  INT64_C( 1248038370993995311),  INT64_C( 4492411832080540524),
         INT64_C( 7415451518697436060), -INT64_C( 8867967730424682290),  INT64_C( 7890041570986956068),  INT64_C( 5202555513960164146) },
      { -INT64_C( 3179142794675790724), -INT64_C( 3072348935554159840), -INT64_C( 9061684874816989816),  INT64_C( 1248038370993995311),
         INT64_C( 5700533680642846329),  INT64_C( 4492411832080540524),  INT64_C( 7415451518697436060), -INT64_C( 8867967730424682290) } },
    { {  INT64_C( 1362415047826820004),  INT64_C( 1947645169868099629),  INT64_C(  499908167942587777), -INT64_C( 7104657140123711373),
         INT64_C( 4093779804000601466),  INT64_C( 4280884451727789655),  INT64_C( 7737656916985115014),  INT64_C(  363932350595882102) },
      UINT8_C(183),
      { -INT64_C( 2194948932759338197),  INT64_C( 3529931775996057268),  INT64_C( 1492825316289697428),  INT64_C( 6757551400338531870),
         INT64_C( 3953342998763243880), -INT64_C( 2063026521250170385),  INT64_C( 4164382812740617982),  INT64_C( 8616249264811108611) },
      { -INT64_C( 2194948932759338197),  INT64_C( 3529931775996057268),  INT64_C( 1492825316289697428), -INT64_C( 7104657140123711373),
         INT64_C( 6757551400338531870),  INT64_C( 3953342998763243880),  INT64_C( 7737656916985115014), -INT64_C( 2063026521250170385) } },
    { {  INT64_C( 3049869587470557850), -INT64_C( 6486108534519300151),  INT64_C(  112631765001773372), -INT64_C( 8929290151671703153),
        -INT64_C( 6822402751274579988), -INT64_C( 7259882453052249613),  INT64_C( 5753210813740653528), -INT64_C( 4338371791921803684) },
      UINT8_C(137),
      { -INT64_C( 1994247755951642004), -INT64_C( 4085645379909718595),  INT64_C(  626237818364502993),  INT64_C( 3265008307527546564),
         INT64_C( 8047616642647961742), -INT64_C( 6719035494939495987), -INT64_C( 1921165529054820013),  INT64_C( 7461333019172484764) },
      { -INT64_C( 1994247755951642004), -INT64_C( 6486108534519300151),  INT64_C(  112631765001773372), -INT64_C( 4085645379909718595),
        -INT64_C( 6822402751274579988), -INT64_C( 7259882453052249613),  INT64_C( 5753210813740653528),  INT64_C(  626237818364502993) } },
    { { -INT64_C( 4049615702809568854),  INT64_C( 3693940020672049360),  INT64_C( 8922430069025028556),  INT64_C( 2543800934477692428),
         INT64_C( 3332184738621324926),  INT64_C( 5624734812868706300),  INT64_C( 8333081417965342795),  INT64_C( 7072805238064381835) },
      UINT8_C( 37),
      {  INT64_C( 1725072278494042535),  INT64_C( 7844399585494158463),  INT64_C( 3151188970131555874), -INT64_C( 8256661733015306338),
         INT64_C( 2052077500997168202),  INT64_C( 2127259210074690365),  INT64_C( 4352739610796578961),  INT64_C( 3620027585108473800) },
      {  INT64_C( 1725072278494042535),  INT64_C( 3693940020672049360),  INT64_C( 7844399585494158463),  INT64_C( 2543800934477692428),
         INT64_C( 3332184738621324926),  INT64_C( 3151188970131555874),  INT64_C( 8333081417965342795),  INT64_C( 7072805238064381835) } },
    { {  INT64_C( 7823050719918144983),  INT64_C( 6501803445451046690),  INT64_C( 6502352960261425251), -INT64_C( 9182481575797211786),
         INT64_C( 6313348716161148419), -INT64_C( 7932897029608102972), -INT64_C(  710215792962994120),  INT64_C( 8481656276912450955) },
      UINT8_C( 11),
      {  INT64_C( 7490216548871743400), -INT64_C( 1588321057984118771),  INT64_C( 1157810910516527032), -INT64_C( 6726978192495393357),
        -INT64_C( 8553529225589496673), -INT64_C( 4641737837282664125),  INT64_C( 1148232486397279739),  INT64_C(  736421464536216220) },
      {  INT64_C( 7490216548871743400), -INT64_C( 1588321057984118771),  INT64_C( 6502352960261425251),  INT64_C( 1157810910516527032),
         INT64_C( 6313348716161148419), -INT64_C( 7932897029608102972), -INT64_C(  710215792962994120),  INT64_C( 8481656276912450955) } },
    { {  INT64_C(  952013013394524208), -INT64_C( 5412677249382384613),  INT64_C( 1997208440267810636), -INT64_C( 2708095307933982987),
        -INT64_C( 5851938898098890255),  INT64_C( 2136310213032051257), -INT64_C( 5732100756622460710), -INT64_C(  117522341796240166) },
      UINT8_C(211),
      {  INT64_C(  421672070693698277), -INT64_C( 6164878745689207579),  INT64_C( 7065889692983872184), -INT64_C( 2921869744897289435),
        -INT64_C( 3192959851261535960),  INT64_C( 3691505263550564127), -INT64_C( 2790693874804744282),  INT64_C( 5463970412234388746) },
      {  INT64_C(  421672070693698277), -INT64_C( 6164878745689207579),  INT64_C( 1997208440267810636), -INT64_C( 2708095307933982987),
         INT64_C( 7065889692983872184),  INT64_C( 2136310213032051257), -INT64_C( 2921869744897289435), -INT64_C( 3192959851261535960) } },
    { { -INT64_C( 4789957953107637307),  INT64_C( 8348416751134765357), -INT64_C( 4344112468472741336), -INT64_C( 2251920642041499823),
        -INT64_C( 8558780636606450211),  INT64_C( 4056349155863398155), -INT64_C( 8085427813234728370), -INT64_C(  435228367415703047) },
      UINT8_C(119),
      {  INT64_C( 3940469004603389321),  INT64_C( 8495898669315688332),  INT64_C( 4780081418408816274), -INT64_C( 1621762745854694587),
         INT64_C( 4084830474001469644),  INT64_C(  507702193895372483),  INT64_C( 5017777445607358118),  INT64_C( 2553200516012965925) },
      {  INT64_C( 3940469004603389321),  INT64_C( 8495898669315688332),  INT64_C( 4780081418408816274), -INT64_C( 2251920642041499823),
        -INT64_C( 1621762745854694587),  INT64_C( 4084830474001469644),  INT64_C(  507702193895372483), -INT64_C(  435228367415703047) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i src = simde_mm512_loadu_epi64(test_vec[i].src);
    simde__mmask8 k = test_vec[i].k;
    simde__m512i r = simde_mm512_mask_expandloadu_epi64(src, k, test_vec[i].mem_addr);
    simde_test_x86_assert_equal_i64x8(r, simde_mm512_loadu_epi64(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_mm512_maskz_expandloadu_epi64 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const simde__mmask8 k;
    SIMDE_ALIGN_LIKE_64(simde__m512i) const int64_t mem_addr[8];
    const int64_t r[8];
  } test_vec[] = {
    { UINT8_C(183),
      { -INT64_C(   88995886217548099),  INT64_C( 2575272066151146317), -INT64_C( 8364594790446851210),  INT64_C( 7514244620504096737),
        -INT64_C( 1163982991652761565),  INT64_C( 7928141811236586646),  INT64_C( 4281624008903318661),  INT64_C(  924667191768118465) },
      { -INT64_C(   88995886217548099),  INT64_C( 2575272066151146317), -INT64_C( 8364594790446851210),  INT64_C(                   0),
         INT64_C( 7514244620504096737), -INT64_C( 1163982991652761565),  INT64_C(                   0),  INT64_C( 7928141811236586646) } },
    { UINT8_C(227),
      { -INT64_C( 9074905263201982779),  INT64_C( 6058161702501544482),  INT64_C( 6017910120299557728), -INT64_C( 8454864236634640204),
        -INT64_C( 4076019733403389905),  INT64_C( 3697569449945393411), -INT64_C( 7202529142901440934), -INT64_C( 4559878606001321879) },
      { -INT64_C( 9074905263201982779),  INT64_C( 6058161702501544482),  INT64_C(                   0),  INT64_C(                   0),
         INT64_C(                   0),  INT64_C( 6017910120299557728), -INT64_C( 8454864236634640204), -INT64_C( 4076019733403389905) } },
    { UINT8_C( 62),
      {  INT64_C(  418740331042024890),  INT64_C( 1927552857127046143), -INT64_C( 3683207253432567808), -INT64_C( 8985492936445849599),
        -INT64_C( 2672008024103636790), -INT64_C( 3521814023735557142), -INT64_C( 4411227727143099784),  INT64_C(  902724618720191803) },
      {  INT64_C(                   0),  INT64_C(  418740331042024890),  INT64_C( 1927552857127046143), -INT64_C( 3683207253432567808),
        -INT64_C( 8985492936445849599), -INT64_C( 2672008024103636790),  INT64_C(                   0),  INT64_C(                   0) } },
    { UINT8_C( 79),
      { -INT64_C( 6782978633147682090),  INT64_C( 2863514229933139012), -INT64_C( 6345947346594383481),  INT64_C( 5758686075697164923),
         INT64_C( 6730667137217795305), -INT64_C( 6975126845282658298),  INT64_C( 4630333484820405016),  INT64_C(  862937556304210993) },
      { -INT64_C( 6782978633147682090),  INT64_C( 2863514229933139012), -INT64_C( 6345947346594383481),  INT64_C( 5758686075697164923),
         INT64_C(                   0),  INT64_C(                   0),  INT64_C( 6730667137217795305),  INT64_C(                   0) } },
    { UINT8_C(217),
      {  INT64_C( 1397611475311448637), -INT64_C( 4653965932825447950),  INT64_C( 8254188023525409819),  INT64_C( 7871905328396515231),
         INT64_C( 8268945919081984114), -INT64_C( 3384967809011028829), -INT64_C( 1231249276451124687), -INT64_C( 8030322630784287248) },
      {  INT64_C( 1397611475311448637),  INT64_C(                   0),  INT64_C(                   0), -INT64_C( 4653965932825447950),
         INT64_C( 8254188023525409819),  INT64_C(                   0),  INT64_C( 7871905328396515231),  INT64_C( 8268945919081984114) } },
    { UINT8_C(193),
      { -INT64_C( 1571838739561235110),  INT64_C(  492425613930428023), -INT64_C( 5528376121196458850),  INT64_C( 5829734852983810197),
         INT64_C( 6090851162705963166),  INT64_C( 4037141276803999619),  INT64_C( 3676018795820833562), -INT64_C( 3277142560864611521) },
      { -INT64_C( 1571838739561235110),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
         INT64_C(                   0),  INT64_C(                   0),  INT64_C(  492425613930428023), -INT64_C( 5528376121196458850) } },
    { UINT8_C(105),
      {  INT64_C( 2157956450876747362),  INT64_C( 5943325404515725714), -INT64_C( 6803772672721237378), -INT64_C( 5681388448253621891),
        -INT64_C( 7482710963710301163),  INT64_C( 5426119355072568835), -INT64_C( 2329710786544386499),  INT64_C( 4466660603496071421) },
      {  INT64_C( 2157956450876747362),  INT64_C(                   0),  INT64_C(                   0),  INT64_C( 5943325404515725714),
         INT64_C(                   0), -INT64_C( 6803772672721237378), -INT64_C( 5681388448253621891),  INT64_C(                   0) } },
    { UINT8_C( 49),
      {  INT64_C( 5634794164512573468), -INT64_C( 5154820048348828217), -INT64_C( 5965024113568612090), -INT64_C( 7166052193360641129),
         INT64_C( 6492216574530471001), -INT64_C( 6891621670481349847),  INT64_C(  604628529599707019), -INT64_C( 6579212280122820203) },
      {  INT64_C( 5634794164512573468),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
        -INT64_C( 5154820048348828217), -INT64_C( 5965024113568612090),  INT64_C(                   0),  INT64_C(                   0) } },  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__mmask8 k = test_vec[i].k;
    simde__m512i r = simde_mm512_maskz_expandloadu_epi64(k, test_vec[i].mem_addr);
    simde_test_x86_assert_equal_i64x8(r, simde_mm512_loadu_epi64(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_mm_mask_expandloadu_ps (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const simde_float32 src[4];
    const simde__mmask8 k;
    SIMDE_ALIGN_LIKE_64(simde__m128) const simde_float32 mem_addr[4];
    const simde_float32 r[4];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(  -793.49), SIMDE_FLOAT32_C(   730.39), SIMDE_FLOAT32_C(   328.76), SIMDE_FLOAT32_C(  -745.63) },
      UINT8_C(212),
      { SIMDE_FLOAT32_C(  -368.86), SIMDE_FLOAT32_C(   -39.88), SIMDE_FLOAT32_C(    18.02), SIMDE_FLOAT32_C(   240.90) },
      { SIMDE_FLOAT32_C(  -793.49), SIMDE_FLOAT32_C(   730.39), SIMDE_FLOAT32_C(  -368.86), SIMDE_FLOAT32_C(  -745.63) } },
    { { SIMDE_FLOAT32_C(  -520.66), SIMDE_FLOAT32_C(   476.29), SIMDE_FLOAT32_C(    34.88), SIMDE_FLOAT32_C(  -660.37) },
      UINT8_C(230),
      { SIMDE_FLOAT32_C(   770.42), SIMDE_FLOAT32_C(  -679.09), SIMDE_FLOAT32_C(  -166.86), SIMDE_FLOAT32_C(   765.91) },
      { SIMDE_FLOAT32_C(  -520.66), SIMDE_FLOAT32_C(   770.42), SIMDE_FLOAT32_C(  -679.09), SIMDE_FLOAT32_C(  -660.37) } },
    { { SIMDE_FLOAT32_C(   889.39), SIMDE_FLOAT32_C(  -289.77), SIMDE_FLOAT32_C(   831.23), SIMDE_FLOAT32_C(   287.06) },
      UINT8_C(133),
      { SIMDE_FLOAT32_C(  -993.30), SIMDE_FLOAT32_C(  -444.72), SIMDE_FLOAT32_C(   -31.12), SIMDE_FLOAT32_C(  -986.94) },
      { SIMDE_FLOAT32_C(  -993.30), SIMDE_FLOAT32_C(  -289.77), SIMDE_FLOAT32_C(  -444.72), SIMDE_FLOAT32_C(   287.06) } },
    { { SIMDE_FLOAT32_C(  -430.06), SIMDE_FLOAT32_C(   344.73), SIMDE_FLOAT32_C(   421.82), SIMDE_FLOAT32_C(   917.78) },
      UINT8_C(119),
      { SIMDE_FLOAT32_C(   152.21), SIMDE_FLOAT32_C(   246.54), SIMDE_FLOAT32_C(   805.61), SIMDE_FLOAT32_C(   -16.71) },
      { SIMDE_FLOAT32_C(   152.21), SIMDE_FLOAT32_C(   246.54), SIMDE_FLOAT32_C(   805.61), SIMDE_FLOAT32_C(   917.78) } },
    { { SIMDE_FLOAT32_C(   877.68), SIMDE_FLOAT32_C(  -234.27), SIMDE_FLOAT32_C(  -998.69), SIMDE_FLOAT32_C(   118.58) },
      UINT8_C( 96),
      { SIMDE_FLOAT32_C(   477.60), SIMDE_FLOAT32_C(  -846.54), SIMDE_FLOAT32_C(   584.70), SIMDE_FLOAT32_C(   770.70) },
      { SIMDE_FLOAT32_C(   877.68), SIMDE_FLOAT32_C(  -234.27), SIMDE_FLOAT32_C(  -998.69), SIMDE_FLOAT32_C(   118.58) } },
    { { SIMDE_FLOAT32_C(   923.88), SIMDE_FLOAT32_C(   905.61), SIMDE_FLOAT32_C(  -396.16), SIMDE_FLOAT32_C(   689.79) },
      UINT8_C(146),
      { SIMDE_FLOAT32_C(   314.07), SIMDE_FLOAT32_C(   521.02), SIMDE_FLOAT32_C(    82.07), SIMDE_FLOAT32_C(  -508.83) },
      { SIMDE_FLOAT32_C(   923.88), SIMDE_FLOAT32_C(   314.07), SIMDE_FLOAT32_C(  -396.16), SIMDE_FLOAT32_C(   689.79) } },
    { { SIMDE_FLOAT32_C(   527.72), SIMDE_FLOAT32_C(   637.35), SIMDE_FLOAT32_C(   460.05), SIMDE_FLOAT32_C(   540.78) },
      UINT8_C( 89),
      { SIMDE_FLOAT32_C(  -195.22), SIMDE_FLOAT32_C(   -37.40), SIMDE_FLOAT32_C(  -874.93), SIMDE_FLOAT32_C(  -643.99) },
      { SIMDE_FLOAT32_C(  -195.22), SIMDE_FLOAT32_C(   637.35), SIMDE_FLOAT32_C(   460.05), SIMDE_FLOAT32_C(   -37.40) } },
    { { SIMDE_FLOAT32_C(  -885.19), SIMDE_FLOAT32_C(   371.61), SIMDE_FLOAT32_C(  -838.38), SIMDE_FLOAT32_C(    98.10) },
      UINT8_C(  8),
      { SIMDE_FLOAT32_C(   -72.65), SIMDE_FLOAT32_C(    99.41), SIMDE_FLOAT32_C(  -632.14), SIMDE_FLOAT32_C(  -827.59) },
      { SIMDE_FLOAT32_C(  -885.19), SIMDE_FLOAT32_C(   371.61), SIMDE_FLOAT32_C(  -838.38), SIMDE_FLOAT32_C(   -72.65) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128 src = simde_mm_loadu_ps(test_vec[i].src);
    simde__mmask8 k = test_vec[i].k;
    simde__m128 r = simde_mm_mask_expandloadu_ps(src, k, test_vec[i].mem_addr);
    simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[i].r), 1);
  }

  return 0;
}

static int
test_simde_mm_maskz_expandloadu_ps (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const simde__mmask8 k;
    SIMDE_ALIGN_LIKE_64(simde__m128) const simde_float32 mem_addr[4];
    const simde_float32 r[4];
  } test_vec[] = {
    { UINT8_C(205),
      { SIMDE_FLOAT32_C(  -478.67), SIMDE_FLOAT32_C(   757.11), SIMDE_FLOAT32_C(  -652.29), SIMDE_FLOAT32_C(  -554.79) },
      { SIMDE_FLOAT32_C(  -478.67), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   757.11), SIMDE_FLOAT32_C(  -652.29) } },
    { UINT8_C( 68),
      { SIMDE_FLOAT32_C(   -48.44), SIMDE_FLOAT32_C(  -865.00), SIMDE_FLOAT32_C(   457.73), SIMDE_FLOAT32_C(  -734.38) },
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   -48.44), SIMDE_FLOAT32_C(     0.00) } },
    { UINT8_C(107),
      { SIMDE_FLOAT32_C(  -460.20), SIMDE_FLOAT32_C(  -243.20), SIMDE_FLOAT32_C(   183.74), SIMDE_FLOAT32_C(  -822.86) },
      { SIMDE_FLOAT32_C(  -460.20), SIMDE_FLOAT32_C(  -243.20), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   183.74) } },
    { UINT8_C(104),
      { SIMDE_FLOAT32_C(  -275.47), SIMDE_FLOAT32_C(  -615.57), SIMDE_FLOAT32_C(    21.62), SIMDE_FLOAT32_C(   687.13) },
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -275.47) } },
    { UINT8_C(145),
      { SIMDE_FLOAT32_C(   377.63), SIMDE_FLOAT32_C(   801.94), SIMDE_FLOAT32_C(   881.11), SIMDE_FLOAT32_C(   539.25) },
      { SIMDE_FLOAT32_C(   377.63), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
    { UINT8_C(227),
      { SIMDE_FLOAT32_C(   130.40), SIMDE_FLOAT32_C(  -533.40), SIMDE_FLOAT32_C(   999.45), SIMDE_FLOAT32_C(   498.26) },
      { SIMDE_FLOAT32_C(   130.40), SIMDE_FLOAT32_C(  -533.40), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
    { UINT8_C(229),
      { SIMDE_FLOAT32_C(  -423.53), SIMDE_FLOAT32_C(  -980.42), SIMDE_FLOAT32_C(  -603.88), SIMDE_FLOAT32_C(   -75.82) },
      { SIMDE_FLOAT32_C(  -423.53), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -980.42), SIMDE_FLOAT32_C(     0.00) } },
    { UINT8_C(166),
      { SIMDE_FLOAT32_C(  -941.16), SIMDE_FLOAT32_C(   875.74), SIMDE_FLOAT32_C(  -400.20), SIMDE_FLOAT32_C(   516.57) },
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -941.16), SIMDE_FLOAT32_C(   875.74), SIMDE_FLOAT32_C(     0.00) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__mmask8 k = test_vec[i].k;
    simde__m128 r = simde_mm_maskz_expandloadu_ps(k, test_vec[i].mem_addr);
    simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[i].r), 1);
  }

  return 0;
}

static int
test_simde_mm256_mask_expandloadu_ps (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const simde_float32 src[8];
    const simde__mmask8 k;
    SIMDE_ALIGN_LIKE_64(simde__m256) const simde_float32 mem_addr[8];
    const simde_float32 r[8];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(  1000.00), SIMDE_FLOAT32_C(  1000.00), SIMDE_FLOAT32_C(  1000.00), SIMDE_FLOAT32_C(  1000.00),
        SIMDE_FLOAT32_C(  1000.00), SIMDE_FLOAT32_C(  1000.00), SIMDE_FLOAT32_C(  1000.00), SIMDE_FLOAT32_C(  1000.00) },
      UINT8_C(208),
      { SIMDE_FLOAT32_C(  -863.38), SIMDE_FLOAT32_C(   851.22), SIMDE_FLOAT32_C(   127.45), SIMDE_FLOAT32_C(   514.24),
        SIMDE_FLOAT32_C(   653.16), SIMDE_FLOAT32_C(     8.56), SIMDE_FLOAT32_C(    53.49), SIMDE_FLOAT32_C(  -446.80) },
      { SIMDE_FLOAT32_C(  1000.00), SIMDE_FLOAT32_C(  1000.00), SIMDE_FLOAT32_C(  1000.00), SIMDE_FLOAT32_C(  1000.00),
        SIMDE_FLOAT32_C(  -863.38), SIMDE_FLOAT32_C(  1000.00), SIMDE_FLOAT32_C(   851.22), SIMDE_FLOAT32_C(   127.45) } },
    { { SIMDE_FLOAT32_C(  1000.00), SIMDE_FLOAT32_C(  1000.00), SIMDE_FLOAT32_C(  1000.00), SIMDE_FLOAT32_C(  1000.00),
        SIMDE_FLOAT32_C(  1000.00), SIMDE_FLOAT32_C(  1000.00), SIMDE_FLOAT32_C(  1000.00), SIMDE_FLOAT32_C(  1000.00) },
      UINT8_C(188),
      { SIMDE_FLOAT32_C(  -878.41), SIMDE_FLOAT32_C(  -385.93), SIMDE_FLOAT32_C(   929.04), SIMDE_FLOAT32_C(  -278.61),
        SIMDE_FLOAT32_C(  -869.36), SIMDE_FLOAT32_C(  -929.60), SIMDE_FLOAT32_C(   -22.79), SIMDE_FLOAT32_C(  -812.99) },
      { SIMDE_FLOAT32_C(  1000.00), SIMDE_FLOAT32_C(  1000.00), SIMDE_FLOAT32_C(  -878.41), SIMDE_FLOAT32_C(  -385.93),
        SIMDE_FLOAT32_C(   929.04), SIMDE_FLOAT32_C(  -278.61), SIMDE_FLOAT32_C(  1000.00), SIMDE_FLOAT32_C(  -869.36) } },
    { { SIMDE_FLOAT32_C(  1000.00), SIMDE_FLOAT32_C(  1000.00), SIMDE_FLOAT32_C(  1000.00), SIMDE_FLOAT32_C(  1000.00),
        SIMDE_FLOAT32_C(  1000.00), SIMDE_FLOAT32_C(  1000.00), SIMDE_FLOAT32_C(  1000.00), SIMDE_FLOAT32_C(  1000.00) },
      UINT8_C(218),
      { SIMDE_FLOAT32_C(   734.41), SIMDE_FLOAT32_C(  -914.76), SIMDE_FLOAT32_C(   174.47), SIMDE_FLOAT32_C(  -212.09),
        SIMDE_FLOAT32_C(  -361.56), SIMDE_FLOAT32_C(   313.42), SIMDE_FLOAT32_C(  -692.00), SIMDE_FLOAT32_C(   191.10) },
      { SIMDE_FLOAT32_C(  1000.00), SIMDE_FLOAT32_C(   734.41), SIMDE_FLOAT32_C(  1000.00), SIMDE_FLOAT32_C(  -914.76),
        SIMDE_FLOAT32_C(   174.47), SIMDE_FLOAT32_C(  1000.00), SIMDE_FLOAT32_C(  -212.09), SIMDE_FLOAT32_C(  -361.56) } },
    { { SIMDE_FLOAT32_C(  1000.00), SIMDE_FLOAT32_C(  1000.00), SIMDE_FLOAT32_C(  1000.00), SIMDE_FLOAT32_C(  1000.00),
        SIMDE_FLOAT32_C(  1000.00), SIMDE_FLOAT32_C(  1000.00), SIMDE_FLOAT32_C(  1000.00), SIMDE_FLOAT32_C(  1000.00) },
      UINT8_C(223),
      { SIMDE_FLOAT32_C(   450.41), SIMDE_FLOAT32_C(   767.04), SIMDE_FLOAT32_C(  -627.03), SIMDE_FLOAT32_C(  -572.38),
        SIMDE_FLOAT32_C(   954.05), SIMDE_FLOAT32_C(   341.52), SIMDE_FLOAT32_C(  -155.61), SIMDE_FLOAT32_C(  -625.43) },
      { SIMDE_FLOAT32_C(   450.41), SIMDE_FLOAT32_C(   767.04), SIMDE_FLOAT32_C(  -627.03), SIMDE_FLOAT32_C(  -572.38),
        SIMDE_FLOAT32_C(   954.05), SIMDE_FLOAT32_C(  1000.00), SIMDE_FLOAT32_C(   341.52), SIMDE_FLOAT32_C(  -155.61) } },
    { { SIMDE_FLOAT32_C(  1000.00), SIMDE_FLOAT32_C(  1000.00), SIMDE_FLOAT32_C(  1000.00), SIMDE_FLOAT32_C(  1000.00),
        SIMDE_FLOAT32_C(  1000.00), SIMDE_FLOAT32_C(  1000.00), SIMDE_FLOAT32_C(  1000.00), SIMDE_FLOAT32_C(  1000.00) },
      UINT8_C( 74),
      { SIMDE_FLOAT32_C(  -832.43), SIMDE_FLOAT32_C(  -418.98), SIMDE_FLOAT32_C(  -933.14), SIMDE_FLOAT32_C(  -524.43),
        SIMDE_FLOAT32_C(   772.12), SIMDE_FLOAT32_C(    17.49), SIMDE_FLOAT32_C(   -57.33), SIMDE_FLOAT32_C(  -907.66) },
      { SIMDE_FLOAT32_C(  1000.00), SIMDE_FLOAT32_C(  -832.43), SIMDE_FLOAT32_C(  1000.00), SIMDE_FLOAT32_C(  -418.98),
        SIMDE_FLOAT32_C(  1000.00), SIMDE_FLOAT32_C(  1000.00), SIMDE_FLOAT32_C(  -933.14), SIMDE_FLOAT32_C(  1000.00) } },
    { { SIMDE_FLOAT32_C(  1000.00), SIMDE_FLOAT32_C(  1000.00), SIMDE_FLOAT32_C(  1000.00), SIMDE_FLOAT32_C(  1000.00),
        SIMDE_FLOAT32_C(  1000.00), SIMDE_FLOAT32_C(  1000.00), SIMDE_FLOAT32_C(  1000.00), SIMDE_FLOAT32_C(  1000.00) },
      UINT8_C( 24),
      { SIMDE_FLOAT32_C(  -768.04), SIMDE_FLOAT32_C(   322.48), SIMDE_FLOAT32_C(  -517.08), SIMDE_FLOAT32_C(    76.35),
        SIMDE_FLOAT32_C(   697.05), SIMDE_FLOAT32_C(   908.00), SIMDE_FLOAT32_C(  -498.40), SIMDE_FLOAT32_C(   110.09) },
      { SIMDE_FLOAT32_C(  1000.00), SIMDE_FLOAT32_C(  1000.00), SIMDE_FLOAT32_C(  1000.00), SIMDE_FLOAT32_C(  -768.04),
        SIMDE_FLOAT32_C(   322.48), SIMDE_FLOAT32_C(  1000.00), SIMDE_FLOAT32_C(  1000.00), SIMDE_FLOAT32_C(  1000.00) } },
    { { SIMDE_FLOAT32_C(  1000.00), SIMDE_FLOAT32_C(  1000.00), SIMDE_FLOAT32_C(  1000.00), SIMDE_FLOAT32_C(  1000.00),
        SIMDE_FLOAT32_C(  1000.00), SIMDE_FLOAT32_C(  1000.00), SIMDE_FLOAT32_C(  1000.00), SIMDE_FLOAT32_C(  1000.00) },
      UINT8_C(  9),
      { SIMDE_FLOAT32_C(   576.04), SIMDE_FLOAT32_C(  -345.36), SIMDE_FLOAT32_C(  -473.17), SIMDE_FLOAT32_C(  -481.29),
        SIMDE_FLOAT32_C(  -253.02), SIMDE_FLOAT32_C(  -848.24), SIMDE_FLOAT32_C(  -516.29), SIMDE_FLOAT32_C(   212.85) },
      { SIMDE_FLOAT32_C(   576.04), SIMDE_FLOAT32_C(  1000.00), SIMDE_FLOAT32_C(  1000.00), SIMDE_FLOAT32_C(  -345.36),
        SIMDE_FLOAT32_C(  1000.00), SIMDE_FLOAT32_C(  1000.00), SIMDE_FLOAT32_C(  1000.00), SIMDE_FLOAT32_C(  1000.00) } },
    { { SIMDE_FLOAT32_C(  1000.00), SIMDE_FLOAT32_C(  1000.00), SIMDE_FLOAT32_C(  1000.00), SIMDE_FLOAT32_C(  1000.00),
        SIMDE_FLOAT32_C(  1000.00), SIMDE_FLOAT32_C(  1000.00), SIMDE_FLOAT32_C(  1000.00), SIMDE_FLOAT32_C(  1000.00) },
      UINT8_C(113),
      { SIMDE_FLOAT32_C(   618.36), SIMDE_FLOAT32_C(  -526.94), SIMDE_FLOAT32_C(   513.61), SIMDE_FLOAT32_C(  -880.03),
        SIMDE_FLOAT32_C(   583.15), SIMDE_FLOAT32_C(    66.85), SIMDE_FLOAT32_C(  -521.10), SIMDE_FLOAT32_C(  -727.79) },
      { SIMDE_FLOAT32_C(   618.36), SIMDE_FLOAT32_C(  1000.00), SIMDE_FLOAT32_C(  1000.00), SIMDE_FLOAT32_C(  1000.00),
        SIMDE_FLOAT32_C(  -526.94), SIMDE_FLOAT32_C(   513.61), SIMDE_FLOAT32_C(  -880.03), SIMDE_FLOAT32_C(  1000.00) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256 src = simde_mm256_loadu_ps(test_vec[i].src);
    simde__mmask8 k = test_vec[i].k;
    simde__m256 r = simde_mm256_mask_expandloadu_ps(src, k, test_vec[i].mem_addr);
    simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[i].r), 1);
  }

  return 0;
}

static int
test_simde_mm256_maskz_expandloadu_ps (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const simde__mmask8 k;
    SIMDE_ALIGN_LIKE_64(simde__m256) const simde_float32 mem_addr[8];
    const simde_float32 r[8];
  } test_vec[] = {
    { UINT8_C( 44),
      { SIMDE_FLOAT32_C(  -219.59), SIMDE_FLOAT32_C(   714.69), SIMDE_FLOAT32_C(   100.22), SIMDE_FLOAT32_C(   662.94),
        SIMDE_FLOAT32_C(   224.03), SIMDE_FLOAT32_C(  -323.74), SIMDE_FLOAT32_C(  -682.42), SIMDE_FLOAT32_C(   750.87) },
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -219.59), SIMDE_FLOAT32_C(   714.69),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   100.22), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
    { UINT8_C(124),
      { SIMDE_FLOAT32_C(    64.57), SIMDE_FLOAT32_C(   902.62), SIMDE_FLOAT32_C(   678.67), SIMDE_FLOAT32_C(  -722.58),
        SIMDE_FLOAT32_C(  -591.68), SIMDE_FLOAT32_C(   763.77), SIMDE_FLOAT32_C(  -741.29), SIMDE_FLOAT32_C(  -281.64) },
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(    64.57), SIMDE_FLOAT32_C(   902.62),
        SIMDE_FLOAT32_C(   678.67), SIMDE_FLOAT32_C(  -722.58), SIMDE_FLOAT32_C(  -591.68), SIMDE_FLOAT32_C(     0.00) } },
    { UINT8_C( 18),
      { SIMDE_FLOAT32_C(   381.39), SIMDE_FLOAT32_C(   260.37), SIMDE_FLOAT32_C(   993.32), SIMDE_FLOAT32_C(   -13.00),
        SIMDE_FLOAT32_C(  -121.27), SIMDE_FLOAT32_C(  -533.62), SIMDE_FLOAT32_C(  -499.39), SIMDE_FLOAT32_C(    -1.30) },
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   381.39), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(   260.37), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
    { UINT8_C(112),
      { SIMDE_FLOAT32_C(   567.45), SIMDE_FLOAT32_C(   477.60), SIMDE_FLOAT32_C(  -678.26), SIMDE_FLOAT32_C(   567.20),
        SIMDE_FLOAT32_C(  -741.99), SIMDE_FLOAT32_C(  -963.57), SIMDE_FLOAT32_C(  -332.58), SIMDE_FLOAT32_C(   920.95) },
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(   567.45), SIMDE_FLOAT32_C(   477.60), SIMDE_FLOAT32_C(  -678.26), SIMDE_FLOAT32_C(     0.00) } },
    { UINT8_C( 82),
      { SIMDE_FLOAT32_C(   343.68), SIMDE_FLOAT32_C(  -761.47), SIMDE_FLOAT32_C(    11.33), SIMDE_FLOAT32_C(  -461.35),
        SIMDE_FLOAT32_C(   303.10), SIMDE_FLOAT32_C(   -86.05), SIMDE_FLOAT32_C(  -782.68), SIMDE_FLOAT32_C(   580.52) },
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   343.68), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(  -761.47), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(    11.33), SIMDE_FLOAT32_C(     0.00) } },
    { UINT8_C(159),
      { SIMDE_FLOAT32_C(   981.09), SIMDE_FLOAT32_C(   839.22), SIMDE_FLOAT32_C(  -959.37), SIMDE_FLOAT32_C(   198.40),
        SIMDE_FLOAT32_C(   220.61), SIMDE_FLOAT32_C(   301.00), SIMDE_FLOAT32_C(   191.72), SIMDE_FLOAT32_C(  -792.39) },
      { SIMDE_FLOAT32_C(   981.09), SIMDE_FLOAT32_C(   839.22), SIMDE_FLOAT32_C(  -959.37), SIMDE_FLOAT32_C(   198.40),
        SIMDE_FLOAT32_C(   220.61), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   301.00) } },
    { UINT8_C( 47),
      { SIMDE_FLOAT32_C(   658.09), SIMDE_FLOAT32_C(  -291.78), SIMDE_FLOAT32_C(   178.43), SIMDE_FLOAT32_C(   707.62),
        SIMDE_FLOAT32_C(  -724.33), SIMDE_FLOAT32_C(  -343.97), SIMDE_FLOAT32_C(  -970.64), SIMDE_FLOAT32_C(   842.88) },
      { SIMDE_FLOAT32_C(   658.09), SIMDE_FLOAT32_C(  -291.78), SIMDE_FLOAT32_C(   178.43), SIMDE_FLOAT32_C(   707.62),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -724.33), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
    { UINT8_C( 13),
      { SIMDE_FLOAT32_C(  -934.21), SIMDE_FLOAT32_C(  -489.70), SIMDE_FLOAT32_C(  -165.00), SIMDE_FLOAT32_C(   326.25),
        SIMDE_FLOAT32_C(   853.98), SIMDE_FLOAT32_C(    73.53), SIMDE_FLOAT32_C(  -662.41), SIMDE_FLOAT32_C(  -607.37) },
      { SIMDE_FLOAT32_C(  -934.21), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -489.70), SIMDE_FLOAT32_C(  -165.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__mmask8 k = test_vec[i].k;
    simde__m256 r = simde_mm256_maskz_expandloadu_ps(k, test_vec[i].mem_addr);
    simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[i].r), 1);
  }

  return 0;
}

static int
test_simde_mm512_mask_expandloadu_ps (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const simde_float32 src[16];
    const simde__mmask16 k;
    SIMDE_ALIGN_LIKE_64(simde__m512) const simde_float32 mem_addr[16];
    const simde_float32 r[16];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(  -623.37), SIMDE_FLOAT32_C(   251.54), SIMDE_FLOAT32_C(  -390.05), SIMDE_FLOAT32_C(   957.15),
        SIMDE_FLOAT32_C(  -426.19), SIMDE_FLOAT32_C(  -408.96), SIMDE_FLOAT32_C(   796.37), SIMDE_FLOAT32_C(  -385.55),
        SIMDE_FLOAT32_C(   789.44), SIMDE_FLOAT32_C(    16.99), SIMDE_FLOAT32_C(   915.45), SIMDE_FLOAT32_C(   -18.84),
        SIMDE_FLOAT32_C(   224.60), SIMDE_FLOAT32_C(  -904.81), SIMDE_FLOAT32_C(  -360.75), SIMDE_FLOAT32_C(   932.82) },
      UINT16_C(54176),
      { SIMDE_FLOAT32_C(  -791.51), SIMDE_FLOAT32_C(   929.65), SIMDE_FLOAT32_C(  -623.76), SIMDE_FLOAT32_C(  -948.63),
        SIMDE_FLOAT32_C(  -156.30), SIMDE_FLOAT32_C(  -557.97), SIMDE_FLOAT32_C(  -438.33), SIMDE_FLOAT32_C(   678.70),
        SIMDE_FLOAT32_C(   768.28), SIMDE_FLOAT32_C(  -584.34), SIMDE_FLOAT32_C(  -247.77), SIMDE_FLOAT32_C(  -894.13),
        SIMDE_FLOAT32_C(  -191.71), SIMDE_FLOAT32_C(   128.86), SIMDE_FLOAT32_C(   357.41), SIMDE_FLOAT32_C(   418.24) },
      { SIMDE_FLOAT32_C(  -623.37), SIMDE_FLOAT32_C(   251.54), SIMDE_FLOAT32_C(  -390.05), SIMDE_FLOAT32_C(   957.15),
        SIMDE_FLOAT32_C(  -426.19), SIMDE_FLOAT32_C(  -791.51), SIMDE_FLOAT32_C(   796.37), SIMDE_FLOAT32_C(   929.65),
        SIMDE_FLOAT32_C(  -623.76), SIMDE_FLOAT32_C(  -948.63), SIMDE_FLOAT32_C(   915.45), SIMDE_FLOAT32_C(   -18.84),
        SIMDE_FLOAT32_C(  -156.30), SIMDE_FLOAT32_C(  -904.81), SIMDE_FLOAT32_C(  -557.97), SIMDE_FLOAT32_C(  -438.33) } },
    { { SIMDE_FLOAT32_C(    86.01), SIMDE_FLOAT32_C(   931.22), SIMDE_FLOAT32_C(  -990.72), SIMDE_FLOAT32_C(  -117.61),
        SIMDE_FLOAT32_C(  -454.33), SIMDE_FLOAT32_C(   798.73), SIMDE_FLOAT32_C(   899.38), SIMDE_FLOAT32_C(  -538.88),
        SIMDE_FLOAT32_C(  -220.12), SIMDE_FLOAT32_C(   123.98), SIMDE_FLOAT32_C(  -443.69), SIMDE_FLOAT32_C(   419.14),
        SIMDE_FLOAT32_C(    56.80), SIMDE_FLOAT32_C(   829.93), SIMDE_FLOAT32_C(   766.01), SIMDE_FLOAT32_C(   265.29) },
      UINT16_C(12391),
      { SIMDE_FLOAT32_C(   316.67), SIMDE_FLOAT32_C(  -396.72), SIMDE_FLOAT32_C(  -415.72), SIMDE_FLOAT32_C(   878.34),
        SIMDE_FLOAT32_C(  -718.02), SIMDE_FLOAT32_C(  -647.43), SIMDE_FLOAT32_C(  -706.00), SIMDE_FLOAT32_C(    34.22),
        SIMDE_FLOAT32_C(  -541.56), SIMDE_FLOAT32_C(   102.29), SIMDE_FLOAT32_C(  -836.92), SIMDE_FLOAT32_C(   815.84),
        SIMDE_FLOAT32_C(  -479.47), SIMDE_FLOAT32_C(   249.09), SIMDE_FLOAT32_C(   747.07), SIMDE_FLOAT32_C(  -470.19) },
      { SIMDE_FLOAT32_C(   316.67), SIMDE_FLOAT32_C(  -396.72), SIMDE_FLOAT32_C(  -415.72), SIMDE_FLOAT32_C(  -117.61),
        SIMDE_FLOAT32_C(  -454.33), SIMDE_FLOAT32_C(   878.34), SIMDE_FLOAT32_C(  -718.02), SIMDE_FLOAT32_C(  -538.88),
        SIMDE_FLOAT32_C(  -220.12), SIMDE_FLOAT32_C(   123.98), SIMDE_FLOAT32_C(  -443.69), SIMDE_FLOAT32_C(   419.14),
        SIMDE_FLOAT32_C(  -647.43), SIMDE_FLOAT32_C(  -706.00), SIMDE_FLOAT32_C(   766.01), SIMDE_FLOAT32_C(   265.29) } },
    { { SIMDE_FLOAT32_C(  -868.52), SIMDE_FLOAT32_C(  -707.27), SIMDE_FLOAT32_C(  -671.46), SIMDE_FLOAT32_C(  -969.14),
        SIMDE_FLOAT32_C(  -246.15), SIMDE_FLOAT32_C(   108.42), SIMDE_FLOAT32_C(   154.83), SIMDE_FLOAT32_C(   310.16),
        SIMDE_FLOAT32_C(  -472.44), SIMDE_FLOAT32_C(  -788.37), SIMDE_FLOAT32_C(   140.09), SIMDE_FLOAT32_C(  -706.43),
        SIMDE_FLOAT32_C(   476.93), SIMDE_FLOAT32_C(  -100.33), SIMDE_FLOAT32_C(  -564.18), SIMDE_FLOAT32_C(  -206.41) },
      UINT16_C(63944),
      { SIMDE_FLOAT32_C(  -328.07), SIMDE_FLOAT32_C(   784.94), SIMDE_FLOAT32_C(   372.66), SIMDE_FLOAT32_C(   -34.07),
        SIMDE_FLOAT32_C(  -180.85), SIMDE_FLOAT32_C(   831.10), SIMDE_FLOAT32_C(  -931.79), SIMDE_FLOAT32_C(   -17.77),
        SIMDE_FLOAT32_C(   646.94), SIMDE_FLOAT32_C(  -411.26), SIMDE_FLOAT32_C(  -768.67), SIMDE_FLOAT32_C(   394.01),
        SIMDE_FLOAT32_C(   118.55), SIMDE_FLOAT32_C(  -637.19), SIMDE_FLOAT32_C(   686.74), SIMDE_FLOAT32_C(   447.09) },
      { SIMDE_FLOAT32_C(  -868.52), SIMDE_FLOAT32_C(  -707.27), SIMDE_FLOAT32_C(  -671.46), SIMDE_FLOAT32_C(  -328.07),
        SIMDE_FLOAT32_C(  -246.15), SIMDE_FLOAT32_C(   108.42), SIMDE_FLOAT32_C(   784.94), SIMDE_FLOAT32_C(   372.66),
        SIMDE_FLOAT32_C(   -34.07), SIMDE_FLOAT32_C(  -788.37), SIMDE_FLOAT32_C(   140.09), SIMDE_FLOAT32_C(  -180.85),
        SIMDE_FLOAT32_C(   831.10), SIMDE_FLOAT32_C(  -931.79), SIMDE_FLOAT32_C(   -17.77), SIMDE_FLOAT32_C(   646.94) } },
    { { SIMDE_FLOAT32_C(  -606.33), SIMDE_FLOAT32_C(  -559.41), SIMDE_FLOAT32_C(  -444.49), SIMDE_FLOAT32_C(   548.50),
        SIMDE_FLOAT32_C(   750.76), SIMDE_FLOAT32_C(    83.06), SIMDE_FLOAT32_C(   760.13), SIMDE_FLOAT32_C(  -109.15),
        SIMDE_FLOAT32_C(   376.63), SIMDE_FLOAT32_C(   237.06), SIMDE_FLOAT32_C(   790.52), SIMDE_FLOAT32_C(   812.45),
        SIMDE_FLOAT32_C(  -969.35), SIMDE_FLOAT32_C(   293.47), SIMDE_FLOAT32_C(  -167.46), SIMDE_FLOAT32_C(  -297.42) },
      UINT16_C(37025),
      { SIMDE_FLOAT32_C(   668.51), SIMDE_FLOAT32_C(   897.56), SIMDE_FLOAT32_C(  -963.70), SIMDE_FLOAT32_C(   736.72),
        SIMDE_FLOAT32_C(  -120.20), SIMDE_FLOAT32_C(   683.24), SIMDE_FLOAT32_C(  -674.54), SIMDE_FLOAT32_C(   111.12),
        SIMDE_FLOAT32_C(    77.25), SIMDE_FLOAT32_C(   444.01), SIMDE_FLOAT32_C(   473.93), SIMDE_FLOAT32_C(  -236.01),
        SIMDE_FLOAT32_C(  -108.90), SIMDE_FLOAT32_C(   867.60), SIMDE_FLOAT32_C(   204.59), SIMDE_FLOAT32_C(   446.61) },
      { SIMDE_FLOAT32_C(   668.51), SIMDE_FLOAT32_C(  -559.41), SIMDE_FLOAT32_C(  -444.49), SIMDE_FLOAT32_C(   548.50),
        SIMDE_FLOAT32_C(   750.76), SIMDE_FLOAT32_C(   897.56), SIMDE_FLOAT32_C(   760.13), SIMDE_FLOAT32_C(  -963.70),
        SIMDE_FLOAT32_C(   376.63), SIMDE_FLOAT32_C(   237.06), SIMDE_FLOAT32_C(   790.52), SIMDE_FLOAT32_C(   812.45),
        SIMDE_FLOAT32_C(   736.72), SIMDE_FLOAT32_C(   293.47), SIMDE_FLOAT32_C(  -167.46), SIMDE_FLOAT32_C(  -120.20) } },
    { { SIMDE_FLOAT32_C(   416.10), SIMDE_FLOAT32_C(   -44.66), SIMDE_FLOAT32_C(  -470.33), SIMDE_FLOAT32_C(   176.23),
        SIMDE_FLOAT32_C(   846.19), SIMDE_FLOAT32_C(   906.30), SIMDE_FLOAT32_C(  -586.71), SIMDE_FLOAT32_C(   636.70),
        SIMDE_FLOAT32_C(   718.74), SIMDE_FLOAT32_C(  -556.06), SIMDE_FLOAT32_C(   -69.83), SIMDE_FLOAT32_C(  -448.71),
        SIMDE_FLOAT32_C(   146.52), SIMDE_FLOAT32_C(  -991.42), SIMDE_FLOAT32_C(  -243.51), SIMDE_FLOAT32_C(  -184.98) },
      UINT16_C(50056),
      { SIMDE_FLOAT32_C(  -448.25), SIMDE_FLOAT32_C(  -214.06), SIMDE_FLOAT32_C(  -523.97), SIMDE_FLOAT32_C(  -122.79),
        SIMDE_FLOAT32_C(   897.07), SIMDE_FLOAT32_C(   553.28), SIMDE_FLOAT32_C(  -678.78), SIMDE_FLOAT32_C(   371.00),
        SIMDE_FLOAT32_C(  -682.73), SIMDE_FLOAT32_C(   212.32), SIMDE_FLOAT32_C(   238.60), SIMDE_FLOAT32_C(   521.86),
        SIMDE_FLOAT32_C(  -341.07), SIMDE_FLOAT32_C(  -345.30), SIMDE_FLOAT32_C(  -522.80), SIMDE_FLOAT32_C(   188.60) },
      { SIMDE_FLOAT32_C(   416.10), SIMDE_FLOAT32_C(   -44.66), SIMDE_FLOAT32_C(  -470.33), SIMDE_FLOAT32_C(  -448.25),
        SIMDE_FLOAT32_C(   846.19), SIMDE_FLOAT32_C(   906.30), SIMDE_FLOAT32_C(  -586.71), SIMDE_FLOAT32_C(  -214.06),
        SIMDE_FLOAT32_C(  -523.97), SIMDE_FLOAT32_C(  -122.79), SIMDE_FLOAT32_C(   -69.83), SIMDE_FLOAT32_C(  -448.71),
        SIMDE_FLOAT32_C(   146.52), SIMDE_FLOAT32_C(  -991.42), SIMDE_FLOAT32_C(   897.07), SIMDE_FLOAT32_C(   553.28) } },
    { { SIMDE_FLOAT32_C(   830.93), SIMDE_FLOAT32_C(  -676.61), SIMDE_FLOAT32_C(    94.90), SIMDE_FLOAT32_C(  -755.79),
        SIMDE_FLOAT32_C(   960.09), SIMDE_FLOAT32_C(  -186.36), SIMDE_FLOAT32_C(  -311.85), SIMDE_FLOAT32_C(  -109.74),
        SIMDE_FLOAT32_C(   364.93), SIMDE_FLOAT32_C(   834.67), SIMDE_FLOAT32_C(  -101.15), SIMDE_FLOAT32_C(  -878.58),
        SIMDE_FLOAT32_C(  -350.31), SIMDE_FLOAT32_C(  -195.01), SIMDE_FLOAT32_C(   -85.79), SIMDE_FLOAT32_C(   201.44) },
      UINT16_C(11082),
      { SIMDE_FLOAT32_C(  -921.35), SIMDE_FLOAT32_C(   488.01), SIMDE_FLOAT32_C(   -56.48), SIMDE_FLOAT32_C(  -600.13),
        SIMDE_FLOAT32_C(  -140.99), SIMDE_FLOAT32_C(   260.79), SIMDE_FLOAT32_C(   612.19), SIMDE_FLOAT32_C(  -902.39),
        SIMDE_FLOAT32_C(  -217.35), SIMDE_FLOAT32_C(  -728.88), SIMDE_FLOAT32_C(  -247.70), SIMDE_FLOAT32_C(   259.85),
        SIMDE_FLOAT32_C(   459.72), SIMDE_FLOAT32_C(  -416.77), SIMDE_FLOAT32_C(   583.23), SIMDE_FLOAT32_C(  -445.38) },
      { SIMDE_FLOAT32_C(   830.93), SIMDE_FLOAT32_C(  -921.35), SIMDE_FLOAT32_C(    94.90), SIMDE_FLOAT32_C(   488.01),
        SIMDE_FLOAT32_C(   960.09), SIMDE_FLOAT32_C(  -186.36), SIMDE_FLOAT32_C(   -56.48), SIMDE_FLOAT32_C(  -109.74),
        SIMDE_FLOAT32_C(  -600.13), SIMDE_FLOAT32_C(  -140.99), SIMDE_FLOAT32_C(  -101.15), SIMDE_FLOAT32_C(   260.79),
        SIMDE_FLOAT32_C(  -350.31), SIMDE_FLOAT32_C(   612.19), SIMDE_FLOAT32_C(   -85.79), SIMDE_FLOAT32_C(   201.44) } },
    { { SIMDE_FLOAT32_C(  -172.55), SIMDE_FLOAT32_C(   543.32), SIMDE_FLOAT32_C(   368.26), SIMDE_FLOAT32_C(   515.60),
        SIMDE_FLOAT32_C(  -566.42), SIMDE_FLOAT32_C(  -266.81), SIMDE_FLOAT32_C(   350.27), SIMDE_FLOAT32_C(   332.43),
        SIMDE_FLOAT32_C(  -145.39), SIMDE_FLOAT32_C(   999.96), SIMDE_FLOAT32_C(  -862.58), SIMDE_FLOAT32_C(   768.82),
        SIMDE_FLOAT32_C(   201.40), SIMDE_FLOAT32_C(   728.36), SIMDE_FLOAT32_C(   159.06), SIMDE_FLOAT32_C(   280.05) },
      UINT16_C(41504),
      { SIMDE_FLOAT32_C(   679.92), SIMDE_FLOAT32_C(  -924.62), SIMDE_FLOAT32_C(   363.37), SIMDE_FLOAT32_C(   292.11),
        SIMDE_FLOAT32_C(  -827.02), SIMDE_FLOAT32_C(  -853.99), SIMDE_FLOAT32_C(   563.24), SIMDE_FLOAT32_C(   -74.71),
        SIMDE_FLOAT32_C(   405.86), SIMDE_FLOAT32_C(    22.96), SIMDE_FLOAT32_C(   508.52), SIMDE_FLOAT32_C(   -10.91),
        SIMDE_FLOAT32_C(   577.58), SIMDE_FLOAT32_C(  -664.03), SIMDE_FLOAT32_C(  -467.59), SIMDE_FLOAT32_C(   -54.15) },
      { SIMDE_FLOAT32_C(  -172.55), SIMDE_FLOAT32_C(   543.32), SIMDE_FLOAT32_C(   368.26), SIMDE_FLOAT32_C(   515.60),
        SIMDE_FLOAT32_C(  -566.42), SIMDE_FLOAT32_C(   679.92), SIMDE_FLOAT32_C(   350.27), SIMDE_FLOAT32_C(   332.43),
        SIMDE_FLOAT32_C(  -145.39), SIMDE_FLOAT32_C(  -924.62), SIMDE_FLOAT32_C(  -862.58), SIMDE_FLOAT32_C(   768.82),
        SIMDE_FLOAT32_C(   201.40), SIMDE_FLOAT32_C(   363.37), SIMDE_FLOAT32_C(   159.06), SIMDE_FLOAT32_C(   292.11) } },
    { { SIMDE_FLOAT32_C(   851.56), SIMDE_FLOAT32_C(   -34.00), SIMDE_FLOAT32_C(   679.04), SIMDE_FLOAT32_C(   201.83),
        SIMDE_FLOAT32_C(  -701.57), SIMDE_FLOAT32_C(  -466.35), SIMDE_FLOAT32_C(   201.79), SIMDE_FLOAT32_C(  -564.15),
        SIMDE_FLOAT32_C(  -697.54), SIMDE_FLOAT32_C(  -596.81), SIMDE_FLOAT32_C(  -835.79), SIMDE_FLOAT32_C(   461.52),
        SIMDE_FLOAT32_C(   683.24), SIMDE_FLOAT32_C(   380.58), SIMDE_FLOAT32_C(   564.10), SIMDE_FLOAT32_C(   363.16) },
      UINT16_C(59078),
      { SIMDE_FLOAT32_C(  -344.73), SIMDE_FLOAT32_C(   628.94), SIMDE_FLOAT32_C(    73.48), SIMDE_FLOAT32_C(  -781.49),
        SIMDE_FLOAT32_C(  -445.77), SIMDE_FLOAT32_C(  -520.66), SIMDE_FLOAT32_C(   241.47), SIMDE_FLOAT32_C(  -937.25),
        SIMDE_FLOAT32_C(   468.43), SIMDE_FLOAT32_C(  -180.95), SIMDE_FLOAT32_C(  -601.28), SIMDE_FLOAT32_C(  -999.16),
        SIMDE_FLOAT32_C(   764.89), SIMDE_FLOAT32_C(  -749.72), SIMDE_FLOAT32_C(   -33.16), SIMDE_FLOAT32_C(   443.93) },
      { SIMDE_FLOAT32_C(   851.56), SIMDE_FLOAT32_C(  -344.73), SIMDE_FLOAT32_C(   628.94), SIMDE_FLOAT32_C(   201.83),
        SIMDE_FLOAT32_C(  -701.57), SIMDE_FLOAT32_C(  -466.35), SIMDE_FLOAT32_C(    73.48), SIMDE_FLOAT32_C(  -781.49),
        SIMDE_FLOAT32_C(  -697.54), SIMDE_FLOAT32_C(  -445.77), SIMDE_FLOAT32_C(  -520.66), SIMDE_FLOAT32_C(   461.52),
        SIMDE_FLOAT32_C(   683.24), SIMDE_FLOAT32_C(   241.47), SIMDE_FLOAT32_C(  -937.25), SIMDE_FLOAT32_C(   468.43) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512 src = simde_mm512_loadu_ps(test_vec[i].src);
    simde__mmask16 k = test_vec[i].k;
    simde__m512 r = simde_mm512_mask_expandloadu_ps(src, k, test_vec[i].mem_addr);
    simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[i].r), 1);
  }

  return 0;
}

static int
test_simde_mm512_maskz_expandloadu_ps (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const simde__mmask16 k;
    SIMDE_ALIGN_LIKE_64(simde__m512) const simde_float32 mem_addr[16];
    const simde_float32 r[16];
  } test_vec[] = {
    { UINT16_C(58986),
      { SIMDE_FLOAT32_C(   945.13), SIMDE_FLOAT32_C(  -560.55), SIMDE_FLOAT32_C(  -439.62), SIMDE_FLOAT32_C(     6.20),
        SIMDE_FLOAT32_C(  -720.16), SIMDE_FLOAT32_C(   208.72), SIMDE_FLOAT32_C(   844.91), SIMDE_FLOAT32_C(  -447.49),
        SIMDE_FLOAT32_C(  -581.89), SIMDE_FLOAT32_C(   526.35), SIMDE_FLOAT32_C(  -387.42), SIMDE_FLOAT32_C(   874.30),
        SIMDE_FLOAT32_C(    37.86), SIMDE_FLOAT32_C(   926.57), SIMDE_FLOAT32_C(  -641.66), SIMDE_FLOAT32_C(    81.66) },
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   945.13), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -560.55),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -439.62), SIMDE_FLOAT32_C(     6.20), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -720.16), SIMDE_FLOAT32_C(   208.72), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   844.91), SIMDE_FLOAT32_C(  -447.49), SIMDE_FLOAT32_C(  -581.89) } },
    { UINT16_C(23380),
      { SIMDE_FLOAT32_C(   866.25), SIMDE_FLOAT32_C(   903.73), SIMDE_FLOAT32_C(    54.01), SIMDE_FLOAT32_C(  -755.94),
        SIMDE_FLOAT32_C(  -502.05), SIMDE_FLOAT32_C(   197.87), SIMDE_FLOAT32_C(   967.60), SIMDE_FLOAT32_C(   744.77),
        SIMDE_FLOAT32_C(  -286.71), SIMDE_FLOAT32_C(  -382.39), SIMDE_FLOAT32_C(  -291.43), SIMDE_FLOAT32_C(    33.37),
        SIMDE_FLOAT32_C(  -110.63), SIMDE_FLOAT32_C(  -346.30), SIMDE_FLOAT32_C(   472.82), SIMDE_FLOAT32_C(   449.76) },
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   866.25), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(   903.73), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(    54.01), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(  -755.94), SIMDE_FLOAT32_C(  -502.05), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   197.87),
        SIMDE_FLOAT32_C(   967.60), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   744.77), SIMDE_FLOAT32_C(     0.00) } },
    { UINT16_C(52126),
      { SIMDE_FLOAT32_C(  -341.52), SIMDE_FLOAT32_C(   504.81), SIMDE_FLOAT32_C(  -694.83), SIMDE_FLOAT32_C(    76.58),
        SIMDE_FLOAT32_C(    31.16), SIMDE_FLOAT32_C(   -82.25), SIMDE_FLOAT32_C(   -49.11), SIMDE_FLOAT32_C(  -930.98),
        SIMDE_FLOAT32_C(  -155.68), SIMDE_FLOAT32_C(   309.22), SIMDE_FLOAT32_C(   150.68), SIMDE_FLOAT32_C(  -861.79),
        SIMDE_FLOAT32_C(   990.98), SIMDE_FLOAT32_C(    16.92), SIMDE_FLOAT32_C(  -958.06), SIMDE_FLOAT32_C(    44.98) },
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -341.52), SIMDE_FLOAT32_C(   504.81), SIMDE_FLOAT32_C(  -694.83),
        SIMDE_FLOAT32_C(    76.58), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(    31.16),
        SIMDE_FLOAT32_C(   -82.25), SIMDE_FLOAT32_C(   -49.11), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -930.98),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -155.68), SIMDE_FLOAT32_C(   309.22) } },
    { UINT16_C(25260),
      { SIMDE_FLOAT32_C(  -757.15), SIMDE_FLOAT32_C(   228.58), SIMDE_FLOAT32_C(  -715.33), SIMDE_FLOAT32_C(   -43.86),
        SIMDE_FLOAT32_C(   846.19), SIMDE_FLOAT32_C(    -6.76), SIMDE_FLOAT32_C(   989.51), SIMDE_FLOAT32_C(  -264.44),
        SIMDE_FLOAT32_C(   646.93), SIMDE_FLOAT32_C(   462.33), SIMDE_FLOAT32_C(  -814.68), SIMDE_FLOAT32_C(   306.83),
        SIMDE_FLOAT32_C(   214.99), SIMDE_FLOAT32_C(  -156.20), SIMDE_FLOAT32_C(  -188.36), SIMDE_FLOAT32_C(   520.16) },
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -757.15), SIMDE_FLOAT32_C(   228.58),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -715.33), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   -43.86),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   846.19), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(    -6.76), SIMDE_FLOAT32_C(   989.51), SIMDE_FLOAT32_C(     0.00) } },
    { UINT16_C(13102),
      { SIMDE_FLOAT32_C(  -562.09), SIMDE_FLOAT32_C(  -128.73), SIMDE_FLOAT32_C(   911.83), SIMDE_FLOAT32_C(   282.22),
        SIMDE_FLOAT32_C(  -819.51), SIMDE_FLOAT32_C(    62.51), SIMDE_FLOAT32_C(   420.43), SIMDE_FLOAT32_C(  -828.53),
        SIMDE_FLOAT32_C(  -920.57), SIMDE_FLOAT32_C(   462.37), SIMDE_FLOAT32_C(   216.46), SIMDE_FLOAT32_C(   340.42),
        SIMDE_FLOAT32_C(  -997.73), SIMDE_FLOAT32_C(   459.31), SIMDE_FLOAT32_C(  -431.00), SIMDE_FLOAT32_C(  -713.07) },
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -562.09), SIMDE_FLOAT32_C(  -128.73), SIMDE_FLOAT32_C(   911.83),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   282.22), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(  -819.51), SIMDE_FLOAT32_C(    62.51), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(   420.43), SIMDE_FLOAT32_C(  -828.53), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
    { UINT16_C(51127),
      { SIMDE_FLOAT32_C(   280.17), SIMDE_FLOAT32_C(  -595.04), SIMDE_FLOAT32_C(   150.76), SIMDE_FLOAT32_C(   -72.89),
        SIMDE_FLOAT32_C(   867.29), SIMDE_FLOAT32_C(   336.08), SIMDE_FLOAT32_C(  -766.06), SIMDE_FLOAT32_C(    82.27),
        SIMDE_FLOAT32_C(  -820.12), SIMDE_FLOAT32_C(    45.58), SIMDE_FLOAT32_C(  -397.57), SIMDE_FLOAT32_C(  -899.74),
        SIMDE_FLOAT32_C(  -111.62), SIMDE_FLOAT32_C(    40.34), SIMDE_FLOAT32_C(   -28.47), SIMDE_FLOAT32_C(  -199.79) },
      { SIMDE_FLOAT32_C(   280.17), SIMDE_FLOAT32_C(  -595.04), SIMDE_FLOAT32_C(   150.76), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(   -72.89), SIMDE_FLOAT32_C(   867.29), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   336.08),
        SIMDE_FLOAT32_C(  -766.06), SIMDE_FLOAT32_C(    82.27), SIMDE_FLOAT32_C(  -820.12), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(    45.58), SIMDE_FLOAT32_C(  -397.57) } },
    { UINT16_C(25751),
      { SIMDE_FLOAT32_C(   862.72), SIMDE_FLOAT32_C(   742.99), SIMDE_FLOAT32_C(   323.50), SIMDE_FLOAT32_C(   942.15),
        SIMDE_FLOAT32_C(   205.36), SIMDE_FLOAT32_C(  -460.04), SIMDE_FLOAT32_C(   282.57), SIMDE_FLOAT32_C(   207.63),
        SIMDE_FLOAT32_C(   999.27), SIMDE_FLOAT32_C(   851.57), SIMDE_FLOAT32_C(   494.56), SIMDE_FLOAT32_C(  -585.28),
        SIMDE_FLOAT32_C(  -733.24), SIMDE_FLOAT32_C(  -225.26), SIMDE_FLOAT32_C(  -180.32), SIMDE_FLOAT32_C(   417.52) },
      { SIMDE_FLOAT32_C(   862.72), SIMDE_FLOAT32_C(   742.99), SIMDE_FLOAT32_C(   323.50), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(   942.15), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   205.36),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -460.04), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   282.57), SIMDE_FLOAT32_C(   207.63), SIMDE_FLOAT32_C(     0.00) } },
    { UINT16_C(11132),
      { SIMDE_FLOAT32_C(  -246.40), SIMDE_FLOAT32_C(   935.78), SIMDE_FLOAT32_C(   769.24), SIMDE_FLOAT32_C(   -66.52),
        SIMDE_FLOAT32_C(   -18.65), SIMDE_FLOAT32_C(  -628.33), SIMDE_FLOAT32_C(    33.74), SIMDE_FLOAT32_C(   869.74),
        SIMDE_FLOAT32_C(   412.00), SIMDE_FLOAT32_C(  -994.72), SIMDE_FLOAT32_C(  -330.05), SIMDE_FLOAT32_C(   734.56),
        SIMDE_FLOAT32_C(   157.30), SIMDE_FLOAT32_C(  -467.33), SIMDE_FLOAT32_C(   477.55), SIMDE_FLOAT32_C(  -519.19) },
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -246.40), SIMDE_FLOAT32_C(   935.78),
        SIMDE_FLOAT32_C(   769.24), SIMDE_FLOAT32_C(   -66.52), SIMDE_FLOAT32_C(   -18.65), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(  -628.33), SIMDE_FLOAT32_C(    33.74), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   869.74),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   412.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__mmask16 k = test_vec[i].k;
    simde__m512 r = simde_mm512_maskz_expandloadu_ps(k, test_vec[i].mem_addr);
    simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[i].r), 1);
  }

  return 0;
}

static int
test_simde_mm_mask_expandloadu_pd (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const simde_float64 src[2];
    const simde__mmask8 k;
    SIMDE_ALIGN_LIKE_64(simde__m128d) const simde_float64 mem_addr[2];
    const simde_float64 r[2];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(   517.44), SIMDE_FLOAT64_C(  -199.09) },
      UINT8_C( 44),
      { SIMDE_FLOAT64_C(   159.21), SIMDE_FLOAT64_C(  -663.33) },
      { SIMDE_FLOAT64_C(   517.44), SIMDE_FLOAT64_C(  -199.09) } },
    { { SIMDE_FLOAT64_C(   155.80), SIMDE_FLOAT64_C(  -756.92) },
      UINT8_C( 17),
      { SIMDE_FLOAT64_C(  -440.30), SIMDE_FLOAT64_C(  -622.21) },
      { SIMDE_FLOAT64_C(  -440.30), SIMDE_FLOAT64_C(  -756.92) } },
    { { SIMDE_FLOAT64_C(    -6.79), SIMDE_FLOAT64_C(    95.93) },
      UINT8_C( 22),
      { SIMDE_FLOAT64_C(   629.16), SIMDE_FLOAT64_C(   624.77) },
      { SIMDE_FLOAT64_C(    -6.79), SIMDE_FLOAT64_C(   629.16) } },
    { { SIMDE_FLOAT64_C(   372.27), SIMDE_FLOAT64_C(  -865.96) },
      UINT8_C( 70),
      { SIMDE_FLOAT64_C(   854.77), SIMDE_FLOAT64_C(   127.54) },
      { SIMDE_FLOAT64_C(   372.27), SIMDE_FLOAT64_C(   854.77) } },
    { { SIMDE_FLOAT64_C(  -358.77), SIMDE_FLOAT64_C(   744.78) },
      UINT8_C(  6),
      { SIMDE_FLOAT64_C(   -26.65), SIMDE_FLOAT64_C(   681.78) },
      { SIMDE_FLOAT64_C(  -358.77), SIMDE_FLOAT64_C(   -26.65) } },
    { { SIMDE_FLOAT64_C(    49.57), SIMDE_FLOAT64_C(   849.31) },
      UINT8_C(  8),
      { SIMDE_FLOAT64_C(   -19.32), SIMDE_FLOAT64_C(   695.39) },
      { SIMDE_FLOAT64_C(    49.57), SIMDE_FLOAT64_C(   849.31) } },
    { { SIMDE_FLOAT64_C(   801.72), SIMDE_FLOAT64_C(  -501.88) },
      UINT8_C(239),
      { SIMDE_FLOAT64_C(   528.49), SIMDE_FLOAT64_C(   657.33) },
      { SIMDE_FLOAT64_C(   528.49), SIMDE_FLOAT64_C(   657.33) } },
    { { SIMDE_FLOAT64_C(  -167.03), SIMDE_FLOAT64_C(  -315.70) },
      UINT8_C(231),
      { SIMDE_FLOAT64_C(  -314.76), SIMDE_FLOAT64_C(   244.00) },
      { SIMDE_FLOAT64_C(  -314.76), SIMDE_FLOAT64_C(   244.00) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128d src = simde_mm_loadu_pd(test_vec[i].src);
    simde__mmask8 k = test_vec[i].k;
    simde__m128d r = simde_mm_mask_expandloadu_pd(src, k, test_vec[i].mem_addr);
    simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[i].r), 1);
  }

  return 0;
}

static int
test_simde_mm_maskz_expandloadu_pd (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const simde__mmask8 k;
    SIMDE_ALIGN_LIKE_64(simde__m128d) const simde_float64 mem_addr[2];
    const simde_float64 r[2];
  } test_vec[] = {
    { UINT8_C(126),
      { SIMDE_FLOAT64_C(   678.45), SIMDE_FLOAT64_C(  -660.08) },
      { SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(   678.45) } },
    { UINT8_C(149),
      { SIMDE_FLOAT64_C(   307.61), SIMDE_FLOAT64_C(   964.69) },
      { SIMDE_FLOAT64_C(   307.61), SIMDE_FLOAT64_C(     0.00) } },
    { UINT8_C(111),
      { SIMDE_FLOAT64_C(   441.65), SIMDE_FLOAT64_C(   731.10) },
      { SIMDE_FLOAT64_C(   441.65), SIMDE_FLOAT64_C(   731.10) } },
    { UINT8_C( 68),
      { SIMDE_FLOAT64_C(  -430.81), SIMDE_FLOAT64_C(  -627.67) },
      { SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00) } },
    { UINT8_C(171),
      { SIMDE_FLOAT64_C(   350.00), SIMDE_FLOAT64_C(   345.68) },
      { SIMDE_FLOAT64_C(   350.00), SIMDE_FLOAT64_C(   345.68) } },
    { UINT8_C( 87),
      { SIMDE_FLOAT64_C(  -600.43), SIMDE_FLOAT64_C(   195.00) },
      { SIMDE_FLOAT64_C(  -600.43), SIMDE_FLOAT64_C(   195.00) } },
    { UINT8_C( 95),
      { SIMDE_FLOAT64_C(   380.25), SIMDE_FLOAT64_C(  -109.62) },
      { SIMDE_FLOAT64_C(   380.25), SIMDE_FLOAT64_C(  -109.62) } },
    { UINT8_C(184),
      { SIMDE_FLOAT64_C(   878.37), SIMDE_FLOAT64_C(   386.67) },
      { SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__mmask8 k = test_vec[i].k;
    simde__m128d r = simde_mm_maskz_expandloadu_pd(k, test_vec[i].mem_addr);
    simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[i].r), 1);
  }

  return 0;
}

static int
test_simde_mm256_mask_expandloadu_pd (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const simde_float64 src[4];
    const simde__mmask8 k;
    SIMDE_ALIGN_LIKE_64(simde__m256d) const simde_float64 mem_addr[4];
    const simde_float64 r[4];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(  1000.00), SIMDE_FLOAT64_C(  1000.00), SIMDE_FLOAT64_C(  1000.00), SIMDE_FLOAT64_C(  1000.00) },
      UINT8_C( 43),
      { SIMDE_FLOAT64_C(   -95.12), SIMDE_FLOAT64_C(  -512.68), SIMDE_FLOAT64_C(   714.31), SIMDE_FLOAT64_C(  -416.66) },
      { SIMDE_FLOAT64_C(   -95.12), SIMDE_FLOAT64_C(  -512.68), SIMDE_FLOAT64_C(  1000.00), SIMDE_FLOAT64_C(   714.31) } },
    { { SIMDE_FLOAT64_C(  1000.00), SIMDE_FLOAT64_C(  1000.00), SIMDE_FLOAT64_C(  1000.00), SIMDE_FLOAT64_C(  1000.00) },
      UINT8_C(173),
      { SIMDE_FLOAT64_C(   332.60), SIMDE_FLOAT64_C(  -476.97), SIMDE_FLOAT64_C(   126.29), SIMDE_FLOAT64_C(   901.79) },
      { SIMDE_FLOAT64_C(   332.60), SIMDE_FLOAT64_C(  1000.00), SIMDE_FLOAT64_C(  -476.97), SIMDE_FLOAT64_C(   126.29) } },
    { { SIMDE_FLOAT64_C(  1000.00), SIMDE_FLOAT64_C(  1000.00), SIMDE_FLOAT64_C(  1000.00), SIMDE_FLOAT64_C(  1000.00) },
      UINT8_C(243),
      { SIMDE_FLOAT64_C(   651.37), SIMDE_FLOAT64_C(   436.05), SIMDE_FLOAT64_C(   855.62), SIMDE_FLOAT64_C(    31.61) },
      { SIMDE_FLOAT64_C(   651.37), SIMDE_FLOAT64_C(   436.05), SIMDE_FLOAT64_C(  1000.00), SIMDE_FLOAT64_C(  1000.00) } },
    { { SIMDE_FLOAT64_C(  1000.00), SIMDE_FLOAT64_C(  1000.00), SIMDE_FLOAT64_C(  1000.00), SIMDE_FLOAT64_C(  1000.00) },
      UINT8_C( 73),
      { SIMDE_FLOAT64_C(  -554.33), SIMDE_FLOAT64_C(   932.74), SIMDE_FLOAT64_C(  -311.50), SIMDE_FLOAT64_C(   881.78) },
      { SIMDE_FLOAT64_C(  -554.33), SIMDE_FLOAT64_C(  1000.00), SIMDE_FLOAT64_C(  1000.00), SIMDE_FLOAT64_C(   932.74) } },
    { { SIMDE_FLOAT64_C(  1000.00), SIMDE_FLOAT64_C(  1000.00), SIMDE_FLOAT64_C(  1000.00), SIMDE_FLOAT64_C(  1000.00) },
      UINT8_C( 17),
      { SIMDE_FLOAT64_C(  -752.05), SIMDE_FLOAT64_C(   311.91), SIMDE_FLOAT64_C(  -205.02), SIMDE_FLOAT64_C(   209.65) },
      { SIMDE_FLOAT64_C(  -752.05), SIMDE_FLOAT64_C(  1000.00), SIMDE_FLOAT64_C(  1000.00), SIMDE_FLOAT64_C(  1000.00) } },
    { { SIMDE_FLOAT64_C(  1000.00), SIMDE_FLOAT64_C(  1000.00), SIMDE_FLOAT64_C(  1000.00), SIMDE_FLOAT64_C(  1000.00) },
      UINT8_C(156),
      { SIMDE_FLOAT64_C(   371.59), SIMDE_FLOAT64_C(   798.10), SIMDE_FLOAT64_C(  -545.57), SIMDE_FLOAT64_C(   998.40) },
      { SIMDE_FLOAT64_C(  1000.00), SIMDE_FLOAT64_C(  1000.00), SIMDE_FLOAT64_C(   371.59), SIMDE_FLOAT64_C(   798.10) } },
    { { SIMDE_FLOAT64_C(  1000.00), SIMDE_FLOAT64_C(  1000.00), SIMDE_FLOAT64_C(  1000.00), SIMDE_FLOAT64_C(  1000.00) },
      UINT8_C(162),
      { SIMDE_FLOAT64_C(  -259.83), SIMDE_FLOAT64_C(   391.06), SIMDE_FLOAT64_C(   930.01), SIMDE_FLOAT64_C(  -814.65) },
      { SIMDE_FLOAT64_C(  1000.00), SIMDE_FLOAT64_C(  -259.83), SIMDE_FLOAT64_C(  1000.00), SIMDE_FLOAT64_C(  1000.00) } },
    { { SIMDE_FLOAT64_C(  1000.00), SIMDE_FLOAT64_C(  1000.00), SIMDE_FLOAT64_C(  1000.00), SIMDE_FLOAT64_C(  1000.00) },
      UINT8_C( 94),
      { SIMDE_FLOAT64_C(  -950.34), SIMDE_FLOAT64_C(   314.60), SIMDE_FLOAT64_C(  -878.66), SIMDE_FLOAT64_C(  -947.28) },
      { SIMDE_FLOAT64_C(  1000.00), SIMDE_FLOAT64_C(  -950.34), SIMDE_FLOAT64_C(   314.60), SIMDE_FLOAT64_C(  -878.66) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256d src = simde_mm256_loadu_pd(test_vec[i].src);
    simde__mmask8 k = test_vec[i].k;
    simde__m256d r = simde_mm256_mask_expandloadu_pd(src, k, test_vec[i].mem_addr);
    simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[i].r), 1);
  }

  return 0;
}

static int
test_simde_mm256_maskz_expandloadu_pd (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const simde__mmask8 k;
    SIMDE_ALIGN_LIKE_64(simde__m256d) const simde_float64 mem_addr[4];
    const simde_float64 r[4];
  } test_vec[] = {
    { UINT8_C(245),
      { SIMDE_FLOAT64_C(   433.25), SIMDE_FLOAT64_C(  -152.30), SIMDE_FLOAT64_C(  -227.80), SIMDE_FLOAT64_C(  -922.23) },
      { SIMDE_FLOAT64_C(   433.25), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(  -152.30), SIMDE_FLOAT64_C(     0.00) } },
    { UINT8_C(184),
      { SIMDE_FLOAT64_C(   108.13), SIMDE_FLOAT64_C(  -375.93), SIMDE_FLOAT64_C(  -620.90), SIMDE_FLOAT64_C(  -520.28) },
      { SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(   108.13) } },
    { UINT8_C( 85),
      { SIMDE_FLOAT64_C(  -166.47), SIMDE_FLOAT64_C(  -521.88), SIMDE_FLOAT64_C(   871.65), SIMDE_FLOAT64_C(  -276.00) },
      { SIMDE_FLOAT64_C(  -166.47), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(  -521.88), SIMDE_FLOAT64_C(     0.00) } },
    { UINT8_C(  9),
      { SIMDE_FLOAT64_C(  -647.27), SIMDE_FLOAT64_C(   -59.10), SIMDE_FLOAT64_C(    72.32), SIMDE_FLOAT64_C(   743.78) },
      { SIMDE_FLOAT64_C(  -647.27), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(   -59.10) } },
    { UINT8_C( 10),
      { SIMDE_FLOAT64_C(   257.67), SIMDE_FLOAT64_C(   580.51), SIMDE_FLOAT64_C(  -266.34), SIMDE_FLOAT64_C(  -868.49) },
      { SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(   257.67), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(   580.51) } },
    { UINT8_C(105),
      { SIMDE_FLOAT64_C(   434.04), SIMDE_FLOAT64_C(  -818.83), SIMDE_FLOAT64_C(  -386.38), SIMDE_FLOAT64_C(   555.38) },
      { SIMDE_FLOAT64_C(   434.04), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(  -818.83) } },
    { UINT8_C( 73),
      { SIMDE_FLOAT64_C(  -823.83), SIMDE_FLOAT64_C(   -11.37), SIMDE_FLOAT64_C(    81.59), SIMDE_FLOAT64_C(   -51.63) },
      { SIMDE_FLOAT64_C(  -823.83), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(   -11.37) } },
    { UINT8_C(120),
      { SIMDE_FLOAT64_C(   247.31), SIMDE_FLOAT64_C(  -943.50), SIMDE_FLOAT64_C(   690.47), SIMDE_FLOAT64_C(   626.40) },
      { SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(   247.31) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__mmask8 k = test_vec[i].k;
    simde__m256d r = simde_mm256_maskz_expandloadu_pd(k, test_vec[i].mem_addr);
    simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[i].r), 1);
  }

  return 0;
}

static int
test_simde_mm512_mask_expandloadu_pd (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const simde_float64 src[8];
    const simde__mmask8 k;
    SIMDE_ALIGN_LIKE_64(simde__m512d) const simde_float64 mem_addr[8];
    const simde_float64 r[8];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(  -463.78), SIMDE_FLOAT64_C(  -887.35), SIMDE_FLOAT64_C(  -540.07), SIMDE_FLOAT64_C(    14.34),
        SIMDE_FLOAT64_C(   984.29), SIMDE_FLOAT64_C(   183.93), SIMDE_FLOAT64_C(   346.49), SIMDE_FLOAT64_C(  -662.98) },
      UINT8_C(218),
      { SIMDE_FLOAT64_C(  -581.19), SIMDE_FLOAT64_C(  -919.20), SIMDE_FLOAT64_C(    -4.26), SIMDE_FLOAT64_C(   676.47),
        SIMDE_FLOAT64_C(   661.31), SIMDE_FLOAT64_C(   729.40), SIMDE_FLOAT64_C(   807.98), SIMDE_FLOAT64_C(   -39.67) },
      { SIMDE_FLOAT64_C(  -463.78), SIMDE_FLOAT64_C(  -581.19), SIMDE_FLOAT64_C(  -540.07), SIMDE_FLOAT64_C(  -919.20),
        SIMDE_FLOAT64_C(    -4.26), SIMDE_FLOAT64_C(   183.93), SIMDE_FLOAT64_C(   676.47), SIMDE_FLOAT64_C(   661.31) } },
    { { SIMDE_FLOAT64_C(   163.44), SIMDE_FLOAT64_C(   989.16), SIMDE_FLOAT64_C(   573.94), SIMDE_FLOAT64_C(  -281.18),
        SIMDE_FLOAT64_C(  -776.95), SIMDE_FLOAT64_C(   750.11), SIMDE_FLOAT64_C(   707.45), SIMDE_FLOAT64_C(   304.64) },
      UINT8_C(212),
      { SIMDE_FLOAT64_C(  -226.16), SIMDE_FLOAT64_C(  -448.05), SIMDE_FLOAT64_C(  -245.03), SIMDE_FLOAT64_C(  -535.69),
        SIMDE_FLOAT64_C(  -821.65), SIMDE_FLOAT64_C(   291.20), SIMDE_FLOAT64_C(  -423.04), SIMDE_FLOAT64_C(  -361.72) },
      { SIMDE_FLOAT64_C(   163.44), SIMDE_FLOAT64_C(   989.16), SIMDE_FLOAT64_C(  -226.16), SIMDE_FLOAT64_C(  -281.18),
        SIMDE_FLOAT64_C(  -448.05), SIMDE_FLOAT64_C(   750.11), SIMDE_FLOAT64_C(  -245.03), SIMDE_FLOAT64_C(  -535.69) } },
    { { SIMDE_FLOAT64_C(  -694.46), SIMDE_FLOAT64_C(  -438.75), SIMDE_FLOAT64_C(   822.20), SIMDE_FLOAT64_C(   652.03),
        SIMDE_FLOAT64_C(  -101.73), SIMDE_FLOAT64_C(   947.04), SIMDE_FLOAT64_C(  -929.17), SIMDE_FLOAT64_C(   -20.94) },
      UINT8_C(137),
      { SIMDE_FLOAT64_C(   747.31), SIMDE_FLOAT64_C(  -359.63), SIMDE_FLOAT64_C(  -327.82), SIMDE_FLOAT64_C(   555.29),
        SIMDE_FLOAT64_C(   600.70), SIMDE_FLOAT64_C(   835.62), SIMDE_FLOAT64_C(   544.45), SIMDE_FLOAT64_C(   174.64) },
      { SIMDE_FLOAT64_C(   747.31), SIMDE_FLOAT64_C(  -438.75), SIMDE_FLOAT64_C(   822.20), SIMDE_FLOAT64_C(  -359.63),
        SIMDE_FLOAT64_C(  -101.73), SIMDE_FLOAT64_C(   947.04), SIMDE_FLOAT64_C(  -929.17), SIMDE_FLOAT64_C(  -327.82) } },
    { { SIMDE_FLOAT64_C(  -445.56), SIMDE_FLOAT64_C(   767.50), SIMDE_FLOAT64_C(   -75.25), SIMDE_FLOAT64_C(  -738.11),
        SIMDE_FLOAT64_C(    72.14), SIMDE_FLOAT64_C(   623.22), SIMDE_FLOAT64_C(    35.73), SIMDE_FLOAT64_C(   624.09) },
      UINT8_C(  6),
      { SIMDE_FLOAT64_C(   500.04), SIMDE_FLOAT64_C(   802.44), SIMDE_FLOAT64_C(   669.39), SIMDE_FLOAT64_C(  -923.00),
        SIMDE_FLOAT64_C(  -559.29), SIMDE_FLOAT64_C(   974.93), SIMDE_FLOAT64_C(  -361.75), SIMDE_FLOAT64_C(  -737.08) },
      { SIMDE_FLOAT64_C(  -445.56), SIMDE_FLOAT64_C(   500.04), SIMDE_FLOAT64_C(   802.44), SIMDE_FLOAT64_C(  -738.11),
        SIMDE_FLOAT64_C(    72.14), SIMDE_FLOAT64_C(   623.22), SIMDE_FLOAT64_C(    35.73), SIMDE_FLOAT64_C(   624.09) } },
    { { SIMDE_FLOAT64_C(   626.96), SIMDE_FLOAT64_C(   536.52), SIMDE_FLOAT64_C(  -790.05), SIMDE_FLOAT64_C(   697.79),
        SIMDE_FLOAT64_C(  -484.42), SIMDE_FLOAT64_C(   152.73), SIMDE_FLOAT64_C(   445.10), SIMDE_FLOAT64_C(   155.95) },
      UINT8_C(203),
      { SIMDE_FLOAT64_C(     0.39), SIMDE_FLOAT64_C(  -243.35), SIMDE_FLOAT64_C(   660.53), SIMDE_FLOAT64_C(  -455.16),
        SIMDE_FLOAT64_C(   931.29), SIMDE_FLOAT64_C(  -785.03), SIMDE_FLOAT64_C(  -687.66), SIMDE_FLOAT64_C(  -143.97) },
      { SIMDE_FLOAT64_C(     0.39), SIMDE_FLOAT64_C(  -243.35), SIMDE_FLOAT64_C(  -790.05), SIMDE_FLOAT64_C(   660.53),
        SIMDE_FLOAT64_C(  -484.42), SIMDE_FLOAT64_C(   152.73), SIMDE_FLOAT64_C(  -455.16), SIMDE_FLOAT64_C(   931.29) } },
    { { SIMDE_FLOAT64_C(  -523.14), SIMDE_FLOAT64_C(   384.48), SIMDE_FLOAT64_C(  -520.75), SIMDE_FLOAT64_C(   512.59),
        SIMDE_FLOAT64_C(     8.56), SIMDE_FLOAT64_C(  -142.56), SIMDE_FLOAT64_C(    12.64), SIMDE_FLOAT64_C(  -189.00) },
      UINT8_C( 96),
      { SIMDE_FLOAT64_C(    89.64), SIMDE_FLOAT64_C(   251.71), SIMDE_FLOAT64_C(  -498.24), SIMDE_FLOAT64_C(   727.89),
        SIMDE_FLOAT64_C(   514.63), SIMDE_FLOAT64_C(  -871.28), SIMDE_FLOAT64_C(   264.40), SIMDE_FLOAT64_C(   724.58) },
      { SIMDE_FLOAT64_C(  -523.14), SIMDE_FLOAT64_C(   384.48), SIMDE_FLOAT64_C(  -520.75), SIMDE_FLOAT64_C(   512.59),
        SIMDE_FLOAT64_C(     8.56), SIMDE_FLOAT64_C(    89.64), SIMDE_FLOAT64_C(   251.71), SIMDE_FLOAT64_C(  -189.00) } },
    { { SIMDE_FLOAT64_C(   826.51), SIMDE_FLOAT64_C(   779.98), SIMDE_FLOAT64_C(  -122.69), SIMDE_FLOAT64_C(   271.60),
        SIMDE_FLOAT64_C(   -64.07), SIMDE_FLOAT64_C(  -297.78), SIMDE_FLOAT64_C(  -728.01), SIMDE_FLOAT64_C(   692.58) },
      UINT8_C( 25),
      { SIMDE_FLOAT64_C(  -183.17), SIMDE_FLOAT64_C(   623.87), SIMDE_FLOAT64_C(  -422.27), SIMDE_FLOAT64_C(   129.17),
        SIMDE_FLOAT64_C(  -520.10), SIMDE_FLOAT64_C(    54.59), SIMDE_FLOAT64_C(  -486.35), SIMDE_FLOAT64_C(   -40.85) },
      { SIMDE_FLOAT64_C(  -183.17), SIMDE_FLOAT64_C(   779.98), SIMDE_FLOAT64_C(  -122.69), SIMDE_FLOAT64_C(   623.87),
        SIMDE_FLOAT64_C(  -422.27), SIMDE_FLOAT64_C(  -297.78), SIMDE_FLOAT64_C(  -728.01), SIMDE_FLOAT64_C(   692.58) } },
    { { SIMDE_FLOAT64_C(  -432.82), SIMDE_FLOAT64_C(   522.21), SIMDE_FLOAT64_C(   816.60), SIMDE_FLOAT64_C(   579.82),
        SIMDE_FLOAT64_C(  -666.79), SIMDE_FLOAT64_C(  -656.57), SIMDE_FLOAT64_C(  -330.54), SIMDE_FLOAT64_C(   584.92) },
      UINT8_C(131),
      { SIMDE_FLOAT64_C(  -602.66), SIMDE_FLOAT64_C(    99.55), SIMDE_FLOAT64_C(   -26.10), SIMDE_FLOAT64_C(   661.75),
        SIMDE_FLOAT64_C(  -175.87), SIMDE_FLOAT64_C(  -199.59), SIMDE_FLOAT64_C(   441.73), SIMDE_FLOAT64_C(   701.44) },
      { SIMDE_FLOAT64_C(  -602.66), SIMDE_FLOAT64_C(    99.55), SIMDE_FLOAT64_C(   816.60), SIMDE_FLOAT64_C(   579.82),
        SIMDE_FLOAT64_C(  -666.79), SIMDE_FLOAT64_C(  -656.57), SIMDE_FLOAT64_C(  -330.54), SIMDE_FLOAT64_C(   -26.10) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512d src = simde_mm512_loadu_pd(test_vec[i].src);
    simde__mmask8 k = test_vec[i].k;
    simde__m512d r = simde_mm512_mask_expandloadu_pd(src, k, test_vec[i].mem_addr);
    simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[i].r), 1);
  }

  return 0;
}

static int
test_simde_mm512_maskz_expandloadu_pd (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const simde__mmask8 k;
    SIMDE_ALIGN_LIKE_64(simde__m512d) const simde_float64 mem_addr[8];
    const simde_float64 r[8];
  } test_vec[] = {
    { UINT8_C(225),
      { SIMDE_FLOAT64_C(  -622.33), SIMDE_FLOAT64_C(  -596.33), SIMDE_FLOAT64_C(  -656.00), SIMDE_FLOAT64_C(  -929.75),
        SIMDE_FLOAT64_C(  -233.57), SIMDE_FLOAT64_C(   160.83), SIMDE_FLOAT64_C(   694.12), SIMDE_FLOAT64_C(   344.16) },
      { SIMDE_FLOAT64_C(  -622.33), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00),
        SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(  -596.33), SIMDE_FLOAT64_C(  -656.00), SIMDE_FLOAT64_C(  -929.75) } },
    { UINT8_C(195),
      { SIMDE_FLOAT64_C(  -825.98), SIMDE_FLOAT64_C(  -601.25), SIMDE_FLOAT64_C(  -196.35), SIMDE_FLOAT64_C(   133.17),
        SIMDE_FLOAT64_C(   -34.07), SIMDE_FLOAT64_C(  -674.14), SIMDE_FLOAT64_C(   -50.24), SIMDE_FLOAT64_C(  -454.25) },
      { SIMDE_FLOAT64_C(  -825.98), SIMDE_FLOAT64_C(  -601.25), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00),
        SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(  -196.35), SIMDE_FLOAT64_C(   133.17) } },
    { UINT8_C(252),
      { SIMDE_FLOAT64_C(   293.19), SIMDE_FLOAT64_C(   215.21), SIMDE_FLOAT64_C(  -756.01), SIMDE_FLOAT64_C(  -861.62),
        SIMDE_FLOAT64_C(   612.55), SIMDE_FLOAT64_C(   343.54), SIMDE_FLOAT64_C(   112.28), SIMDE_FLOAT64_C(   274.30) },
      { SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(   293.19), SIMDE_FLOAT64_C(   215.21),
        SIMDE_FLOAT64_C(  -756.01), SIMDE_FLOAT64_C(  -861.62), SIMDE_FLOAT64_C(   612.55), SIMDE_FLOAT64_C(   343.54) } },
    { UINT8_C(151),
      { SIMDE_FLOAT64_C(   912.68), SIMDE_FLOAT64_C(  -283.97), SIMDE_FLOAT64_C(   869.11), SIMDE_FLOAT64_C(   984.69),
        SIMDE_FLOAT64_C(    93.69), SIMDE_FLOAT64_C(  -727.22), SIMDE_FLOAT64_C(  -671.30), SIMDE_FLOAT64_C(   163.94) },
      { SIMDE_FLOAT64_C(   912.68), SIMDE_FLOAT64_C(  -283.97), SIMDE_FLOAT64_C(   869.11), SIMDE_FLOAT64_C(     0.00),
        SIMDE_FLOAT64_C(   984.69), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(    93.69) } },
    { UINT8_C(110),
      { SIMDE_FLOAT64_C(   489.53), SIMDE_FLOAT64_C(  -141.94), SIMDE_FLOAT64_C(  -616.64), SIMDE_FLOAT64_C(   779.53),
        SIMDE_FLOAT64_C(    32.08), SIMDE_FLOAT64_C(  -217.89), SIMDE_FLOAT64_C(  -416.83), SIMDE_FLOAT64_C(  -834.76) },
      { SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(   489.53), SIMDE_FLOAT64_C(  -141.94), SIMDE_FLOAT64_C(  -616.64),
        SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(   779.53), SIMDE_FLOAT64_C(    32.08), SIMDE_FLOAT64_C(     0.00) } },
    { UINT8_C(123),
      { SIMDE_FLOAT64_C(   -90.97), SIMDE_FLOAT64_C(   115.01), SIMDE_FLOAT64_C(  -706.21), SIMDE_FLOAT64_C(   568.10),
        SIMDE_FLOAT64_C(  -591.80), SIMDE_FLOAT64_C(   509.00), SIMDE_FLOAT64_C(   812.08), SIMDE_FLOAT64_C(  -453.42) },
      { SIMDE_FLOAT64_C(   -90.97), SIMDE_FLOAT64_C(   115.01), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(  -706.21),
        SIMDE_FLOAT64_C(   568.10), SIMDE_FLOAT64_C(  -591.80), SIMDE_FLOAT64_C(   509.00), SIMDE_FLOAT64_C(     0.00) } },
    { UINT8_C(237),
      { SIMDE_FLOAT64_C(   155.62), SIMDE_FLOAT64_C(   658.85), SIMDE_FLOAT64_C(  -604.15), SIMDE_FLOAT64_C(   323.29),
        SIMDE_FLOAT64_C(   571.54), SIMDE_FLOAT64_C(   111.88), SIMDE_FLOAT64_C(   192.41), SIMDE_FLOAT64_C(   556.23) },
      { SIMDE_FLOAT64_C(   155.62), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(   658.85), SIMDE_FLOAT64_C(  -604.15),
        SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(   323.29), SIMDE_FLOAT64_C(   571.54), SIMDE_FLOAT64_C(   111.88) } },
    { UINT8_C( 64),
      { SIMDE_FLOAT64_C(   465.19), SIMDE_FLOAT64_C(   884.93), SIMDE_FLOAT64_C(   369.51), SIMDE_FLOAT64_C(  -495.61),
        SIMDE_FLOAT64_C(   374.45), SIMDE_FLOAT64_C(  -772.43), SIMDE_FLOAT64_C(  -112.24), SIMDE_FLOAT64_C(   153.98) },
      { SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00),
        SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(   465.19), SIMDE_FLOAT64_C(     0.00) } },  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__mmask8 k = test_vec[i].k;
    simde__m512d r = simde_mm512_maskz_expandloadu_pd(k, test_vec[i].mem_addr);
    simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[i].r), 1);
  }

  return 0;
}

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_mask_expandloadu_epi8)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_maskz_expandloadu_epi8)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_mask_expandloadu_epi8)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_maskz_expandloadu_epi8)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_expandloadu_epi8)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_maskz_expandloadu_epi8)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_mask_expandloadu_epi16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_maskz_expandloadu_epi16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_mask_expandloadu_epi16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_maskz_expandloadu_epi16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_expandloadu_epi16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_maskz_expandloadu_epi16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_mask_expandloadu_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_maskz_expandloadu_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_mask_expandloadu_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_maskz_expandloadu_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_expandloadu_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_maskz_expandloadu_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_mask_expandloadu_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_maskz_expandloadu_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_mask_expandloadu_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_maskz_expandloadu_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_expandloadu_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_maskz_expandloadu_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_mask_expandloadu_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_maskz_expandloadu_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_mask_expandloadu_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_maskz_expandloadu_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_expandloadu_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_maskz_expandloadu_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_mask_expandloadu_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_maskz_expandloadu_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_mask_expandloadu_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_maskz_expandloadu_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_expandloadu_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_maskz_expandloadu_pd)
SIMDE_TEST_FUNC_LIST_END

#include <test/x86/avx512/test-avx512-footer.h>
