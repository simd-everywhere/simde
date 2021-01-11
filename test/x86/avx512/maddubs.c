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
 *   2020      Ashleigh Newman-Jones <ashnewman-jones@hotmail.co.uk>
 */

#define SIMDE_TEST_X86_AVX512_INSN maddubs

#include <test/x86/avx512/test-avx512.h>
#include <simde/x86/avx512/maddubs.h>

static int
test_simde_mm_mask_maddubs_epi16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int16_t src[8];
    const simde__mmask8 k;
    const int8_t a[16];
    const int8_t b[16];
    const int16_t r[8];
  } test_vec[] = {
    { { -INT16_C( 28646), -INT16_C( 10601), -INT16_C( 25326), -INT16_C( 24892),  INT16_C( 24744),  INT16_C(  4254),  INT16_C( 10934), -INT16_C( 11273) },
      UINT8_C( 25),
      {  INT8_C(  38), -INT8_C(  48),  INT8_C( 116),  INT8_C(  16),  INT8_C(   1),  INT8_C( 122), -INT8_C(  94),  INT8_C(  26),
         INT8_C(  29), -INT8_C(   5), -INT8_C(  54), -INT8_C(  74),  INT8_C(  51), -INT8_C( 120), -INT8_C(  48), -INT8_C(  61) },
      {  INT8_C(  31), -INT8_C(  90), -INT8_C(  43), -INT8_C(  68),  INT8_C( 106),  INT8_C( 115),  INT8_C( 101), -INT8_C(  53),
         INT8_C(  17),  INT8_C( 117), -INT8_C( 127),  INT8_C(  60),  INT8_C( 108),  INT8_C(  85),  INT8_C(  85), -INT8_C( 110) },
      { -INT16_C( 17542), -INT16_C( 10601), -INT16_C( 25326),  INT16_C( 14984),  INT16_C( 29860),  INT16_C(  4254),  INT16_C( 10934), -INT16_C( 11273) } },
    { { -INT16_C( 14043),  INT16_C(  9890),  INT16_C( 17731),  INT16_C( 24641),  INT16_C(  2880),  INT16_C( 29462), -INT16_C(  6509), -INT16_C( 19658) },
      UINT8_C(140),
      {  INT8_C(  12),  INT8_C( 111), -INT8_C(   9),      INT8_MAX, -INT8_C(  44), -INT8_C(  62), -INT8_C( 111),  INT8_C(  74),
         INT8_C(  67), -INT8_C(  51), -INT8_C(  74), -INT8_C( 104),  INT8_C(  34),  INT8_C(  73), -INT8_C(  67), -INT8_C(  21) },
      { -INT8_C(  21), -INT8_C(  28),  INT8_C(  46),  INT8_C(  48),  INT8_C(  37), -INT8_C( 113),  INT8_C( 112),  INT8_C(  48),
        -INT8_C(  91), -INT8_C(  29), -INT8_C(  60), -INT8_C( 116),  INT8_C(  26),  INT8_C( 119),  INT8_C(  24),  INT8_C(  38) },
      { -INT16_C( 14043),  INT16_C(  9890), -INT16_C( 14078),  INT16_C( 19792),  INT16_C(  2880),  INT16_C( 29462), -INT16_C(  6509),  INT16_C( 13466) } },
    { {  INT16_C(  4070), -INT16_C( 17499),  INT16_C( 14033),  INT16_C(  5381), -INT16_C( 17661),  INT16_C(  9645),  INT16_C( 27396), -INT16_C(  4080) },
      UINT8_C( 79),
      {  INT8_C(  63),  INT8_C(  32),  INT8_C( 116), -INT8_C(  50), -INT8_C( 111), -INT8_C(  92),  INT8_C( 115),  INT8_C( 116),
         INT8_C( 104), -INT8_C(   1), -INT8_C( 114), -INT8_C(  33),  INT8_C(  24), -INT8_C(  76), -INT8_C(  58),  INT8_C(  39) },
      {  INT8_C(  90), -INT8_C( 127), -INT8_C(   7), -INT8_C( 112), -INT8_C( 122),  INT8_C(  14), -INT8_C( 108),  INT8_C(  65),
        -INT8_C(  69), -INT8_C(  71),  INT8_C(  70),  INT8_C(  38), -INT8_C(  54),  INT8_C(  54),  INT8_C( 117),  INT8_C(   9) },
      {  INT16_C(  1606), -INT16_C( 23884), -INT16_C( 15394), -INT16_C(  4880), -INT16_C( 17661),  INT16_C(  9645),  INT16_C(  8424), -INT16_C(  4080) } },
    { { -INT16_C(  5802), -INT16_C(  6185),  INT16_C( 19086), -INT16_C(  2468), -INT16_C(  5558),  INT16_C( 25302), -INT16_C( 25441), -INT16_C(  1655) },
      UINT8_C( 29),
      { -INT8_C( 126), -INT8_C( 119), -INT8_C(  93), -INT8_C( 112),  INT8_C(  29), -INT8_C(  28),  INT8_C(  76), -INT8_C(  41),
         INT8_C(  42),  INT8_C( 114), -INT8_C(  95),  INT8_C(  96), -INT8_C(  24), -INT8_C(  86), -INT8_C(  73), -INT8_C(  47) },
      { -INT8_C( 127), -INT8_C(  98),  INT8_C(  95), -INT8_C(  53), -INT8_C(   6),  INT8_C(  86),  INT8_C(  21), -INT8_C(  27),
         INT8_C(  44),  INT8_C( 119), -INT8_C( 124), -INT8_C(  56),  INT8_C(   1),  INT8_C( 125), -INT8_C(  27), -INT8_C( 125) },
      { -INT16_C( 29936), -INT16_C(  6185),  INT16_C( 19434), -INT16_C(  4209),  INT16_C( 15414),  INT16_C( 25302), -INT16_C( 25441), -INT16_C(  1655) } },
    { { -INT16_C( 30714),  INT16_C(  9236),  INT16_C( 24684), -INT16_C( 26629), -INT16_C( 25390), -INT16_C( 17673), -INT16_C( 20922), -INT16_C( 14452) },
      UINT8_C( 77),
      { -INT8_C(  21), -INT8_C( 110),  INT8_C(  71),  INT8_C(  65), -INT8_C(  88),  INT8_C(  44),  INT8_C( 109),  INT8_C(  31),
        -INT8_C(  80),  INT8_C(  53),  INT8_C(  32),  INT8_C(  45),  INT8_C(  26), -INT8_C(  92),  INT8_C(  52), -INT8_C(  94) },
      { -INT8_C(  72),  INT8_C(  88),  INT8_C(  15),  INT8_C(  24),  INT8_C(  83), -INT8_C(  90), -INT8_C(  22), -INT8_C(  17),
        -INT8_C(  99), -INT8_C(  91),  INT8_C(  53),  INT8_C(  76),  INT8_C(  49), -INT8_C(   4), -INT8_C( 103),  INT8_C(  28) },
      { -INT16_C(  4072),  INT16_C(  9236),  INT16_C(  9984), -INT16_C(  2925), -INT16_C( 25390), -INT16_C( 17673),  INT16_C(   618), -INT16_C( 14452) } },
    { { -INT16_C(  8050),  INT16_C( 13918), -INT16_C( 13555), -INT16_C( 17066),  INT16_C( 30209),  INT16_C(  7147),  INT16_C(  7962), -INT16_C( 11586) },
      UINT8_C(119),
      { -INT8_C(  51), -INT8_C(  22), -INT8_C(  54),  INT8_C( 115), -INT8_C(  43), -INT8_C(  71),  INT8_C(  16),  INT8_C( 122),
        -INT8_C(  18),  INT8_C(  92), -INT8_C(  85), -INT8_C(  22), -INT8_C(  11), -INT8_C(  57),  INT8_C( 120), -INT8_C(  42) },
      {  INT8_C(  37), -INT8_C(  81), -INT8_C(  29), -INT8_C(  15),  INT8_C(   5), -INT8_C(  96), -INT8_C(  14),  INT8_C( 123),
        -INT8_C( 117),  INT8_C(  13), -INT8_C( 106), -INT8_C(  86), -INT8_C(  53),  INT8_C( 104),  INT8_C(  33), -INT8_C( 104) },
      { -INT16_C( 11369), -INT16_C(  7583), -INT16_C( 16695), -INT16_C( 17066), -INT16_C( 26650),       INT16_MIN,  INT16_C(  7711), -INT16_C( 11586) } },
    { { -INT16_C(  5293),  INT16_C( 10251),  INT16_C(  7332), -INT16_C( 27998),  INT16_C( 19832),  INT16_C( 28284), -INT16_C(  2796),  INT16_C( 14916) },
      UINT8_C(164),
      {  INT8_C(  39),  INT8_C(  43), -INT8_C(  87), -INT8_C(  57),  INT8_C(  29),  INT8_C(  36),  INT8_C(  83),  INT8_C(  42),
        -INT8_C(  70), -INT8_C(   3), -INT8_C(  10),  INT8_C(  35),  INT8_C(  31), -INT8_C( 114),  INT8_C( 118),  INT8_C(  10) },
      { -INT8_C( 102), -INT8_C(  98), -INT8_C(  81), -INT8_C(  74),  INT8_C(  64),  INT8_C(  65),  INT8_C(  46), -INT8_C( 115),
        -INT8_C(  66), -INT8_C( 100), -INT8_C(  95), -INT8_C(  77), -INT8_C(  32), -INT8_C(  37),  INT8_C(  87),  INT8_C(   7) },
      { -INT16_C(  5293),  INT16_C( 10251),  INT16_C(  4196), -INT16_C( 27998),  INT16_C( 19832), -INT16_C( 26065), -INT16_C(  2796),  INT16_C( 10336) } },
    { {  INT16_C(     6),  INT16_C(  9167),  INT16_C(  8740), -INT16_C(  8370),  INT16_C( 17439),  INT16_C( 15874),  INT16_C( 30930),  INT16_C( 27721) },
      UINT8_C( 22),
      { -INT8_C(   8),  INT8_C(  34),  INT8_C(  86),  INT8_C(  57),  INT8_C(  81), -INT8_C(  29), -INT8_C(   9), -INT8_C(  19),
        -INT8_C( 124), -INT8_C(  86), -INT8_C(  50),  INT8_C(  96),  INT8_C(   1), -INT8_C(  43),  INT8_C( 102),  INT8_C(   1) },
      { -INT8_C(  92), -INT8_C( 118),  INT8_C(  38), -INT8_C(  58), -INT8_C(  40),  INT8_C(   5), -INT8_C(  26),  INT8_C(  28),
         INT8_C(   7),  INT8_C(  36), -INT8_C(  18),      INT8_MAX,  INT8_C( 109),  INT8_C(  91), -INT8_C( 107),  INT8_C( 101) },
      {  INT16_C(     6), -INT16_C(    38), -INT16_C(  2105), -INT16_C(  8370),  INT16_C(  7044),  INT16_C( 15874),  INT16_C( 30930),  INT16_C( 27721) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i src = simde_mm_loadu_epi16(test_vec[i].src);
    simde__m128i a = simde_mm_loadu_epi8(test_vec[i].a);
    simde__m128i b = simde_mm_loadu_epi8(test_vec[i].b);
    simde__m128i r = simde_mm_mask_maddubs_epi16(src, test_vec[i].k, a, b);
    simde_test_x86_assert_equal_i16x8(r, simde_mm_loadu_epi16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i src = simde_test_x86_random_i16x8();
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m128i a = simde_test_x86_random_i8x16();
    simde__m128i b = simde_test_x86_random_i8x16();
    simde__m128i r = simde_mm_mask_maddubs_epi16(src, k, a, b);

    simde_test_x86_write_i16x8(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i8x16(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i8x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_maskz_maddubs_epi16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k;
    const int8_t a[16];
    const int8_t b[16];
    const int16_t r[8];
  } test_vec[] = {
    { UINT8_C( 16),
      {  INT8_C(  57), -INT8_C(  82), -INT8_C( 102), -INT8_C(  24),  INT8_C(  14),  INT8_C( 111), -INT8_C(  56), -INT8_C( 118),
         INT8_C( 113), -INT8_C( 121), -INT8_C(  90), -INT8_C(   2),  INT8_C(  80),  INT8_C(  40),  INT8_C(  67),  INT8_C(  27) },
      {  INT8_C(  38),  INT8_C(  86),  INT8_C(  79),  INT8_C(   6),  INT8_C(  90),  INT8_C(  89),  INT8_C(   5),  INT8_C(  52),
        -INT8_C(  89), -INT8_C(  28),  INT8_C(  95),  INT8_C(  13),  INT8_C(  19), -INT8_C(  75),  INT8_C(  29),  INT8_C(  76) },
      {  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C( 13837),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
    { UINT8_C( 99),
      { -INT8_C(  73),  INT8_C(  52),  INT8_C( 113),  INT8_C(  39), -INT8_C(   3), -INT8_C(   5), -INT8_C( 104), -INT8_C( 124),
        -INT8_C(  95), -INT8_C( 106), -INT8_C(  43), -INT8_C(  55), -INT8_C(  39), -INT8_C(  16), -INT8_C(  17),  INT8_C(  47) },
      {  INT8_C(  63), -INT8_C(  10), -INT8_C( 119), -INT8_C( 104), -INT8_C(   5), -INT8_C(  66),  INT8_C(  64), -INT8_C(  33),
         INT8_C(  29),  INT8_C(  77), -INT8_C(  14), -INT8_C(  46),  INT8_C( 106),  INT8_C(  63),  INT8_C(  53),  INT8_C(  33) },
      {  INT16_C( 11009), -INT16_C( 17503),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C( 12228),       INT16_MAX,  INT16_C(     0) } },
    { UINT8_C(115),
      { -INT8_C(  90),  INT8_C(  72),  INT8_C( 112), -INT8_C(  94), -INT8_C(  32), -INT8_C(  11),  INT8_C(  67),  INT8_C( 119),
        -INT8_C(  54),  INT8_C(  13),  INT8_C(  80), -INT8_C(  70), -INT8_C(   4),      INT8_MIN, -INT8_C(   7), -INT8_C(  14) },
      {  INT8_C(   9), -INT8_C( 110), -INT8_C(  18), -INT8_C(  57), -INT8_C(  46), -INT8_C(  51), -INT8_C(  28),  INT8_C(  31),
        -INT8_C(  64), -INT8_C(  74), -INT8_C( 119), -INT8_C(   1), -INT8_C(  21), -INT8_C(  86),  INT8_C( 114), -INT8_C( 110) },
      { -INT16_C(  6426), -INT16_C( 11250),  INT16_C(     0),  INT16_C(     0), -INT16_C( 13890), -INT16_C(  9706), -INT16_C( 16300),  INT16_C(     0) } },
    { UINT8_C(243),
      { -INT8_C(  29),  INT8_C(  52), -INT8_C(  45), -INT8_C(  40),  INT8_C( 119),  INT8_C(  74), -INT8_C(  94), -INT8_C( 124),
        -INT8_C( 101),  INT8_C(  92), -INT8_C( 127),  INT8_C(  27),  INT8_C(  85),  INT8_C( 115),  INT8_C(  36), -INT8_C(  25) },
      {  INT8_C(  97), -INT8_C(  20), -INT8_C(  71),  INT8_C(  47), -INT8_C(  48), -INT8_C(  40), -INT8_C(  17), -INT8_C( 121),
         INT8_C(  97), -INT8_C(  18),  INT8_C( 114),  INT8_C(  12),  INT8_C(  96),  INT8_C(   4), -INT8_C(   1),  INT8_C(  67) },
      {  INT16_C( 20979), -INT16_C(  4829),  INT16_C(     0),  INT16_C(     0),  INT16_C( 13379),  INT16_C( 15030),  INT16_C(  8620),  INT16_C( 15441) } },
    { UINT8_C( 56),
      { -INT8_C(  46),  INT8_C(  27), -INT8_C(  80),  INT8_C(  29), -INT8_C(  67),  INT8_C(  52), -INT8_C(  72),  INT8_C(  25),
        -INT8_C(  75), -INT8_C(  45),  INT8_C( 111),  INT8_C(  41), -INT8_C(   9),  INT8_C(  86), -INT8_C( 118), -INT8_C(  29) },
      {  INT8_C(  16), -INT8_C(  71), -INT8_C(  76), -INT8_C(  24), -INT8_C(  88),  INT8_C(  59),  INT8_C(  74), -INT8_C( 106),
        -INT8_C(  83),  INT8_C(  86), -INT8_C(   9), -INT8_C(  78),  INT8_C(  85),  INT8_C(  58), -INT8_C(  22),  INT8_C(  39) },
      {  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C( 10966),  INT16_C(  3123), -INT16_C(  4197),  INT16_C(     0),  INT16_C(     0) } },
    { UINT8_C( 86),
      { -INT8_C( 102),  INT8_C(  68),  INT8_C(  19), -INT8_C(  49), -INT8_C(   4),  INT8_C(  45), -INT8_C( 124), -INT8_C(  49),
        -INT8_C( 100), -INT8_C(  83), -INT8_C(  57), -INT8_C(  14),  INT8_C(  56), -INT8_C(  86),  INT8_C(   2), -INT8_C(  15) },
      {  INT8_C(  94), -INT8_C(  21), -INT8_C( 102), -INT8_C( 103),  INT8_C(  53),  INT8_C(  48),  INT8_C(  71), -INT8_C( 117),
         INT8_C(  39), -INT8_C(   7), -INT8_C(  32),  INT8_C(  98), -INT8_C(  29),  INT8_C(   7), -INT8_C(  72),  INT8_C( 126) },
      {  INT16_C(     0), -INT16_C( 23259),  INT16_C( 15516),  INT16_C(     0),  INT16_C(  4873),  INT16_C(     0), -INT16_C(   434),  INT16_C(     0) } },
    { UINT8_C( 76),
      { -INT8_C(  53),  INT8_C(  77),  INT8_C(  72), -INT8_C(   8), -INT8_C(  47),  INT8_C(  24), -INT8_C( 108),      INT8_MAX,
        -INT8_C(  33), -INT8_C( 121), -INT8_C(  73), -INT8_C( 119), -INT8_C( 119), -INT8_C(  88), -INT8_C(  24),  INT8_C( 116) },
      {  INT8_C(  66), -INT8_C( 127), -INT8_C(  87),  INT8_C( 115), -INT8_C(  56),  INT8_C(  52), -INT8_C( 102), -INT8_C(  63),
         INT8_C(  20), -INT8_C(   4), -INT8_C(  91),  INT8_C(  28), -INT8_C(  76),  INT8_C(  35),  INT8_C( 104),      INT8_MIN },
      {  INT16_C(     0),  INT16_C(     0), -INT16_C( 10456), -INT16_C( 23097),  INT16_C(     0),  INT16_C(     0), -INT16_C(  4532),  INT16_C(     0) } },
    { UINT8_C(112),
      { -INT8_C(  80),  INT8_C( 120),  INT8_C(  65), -INT8_C(  56),  INT8_C(  13), -INT8_C(  64), -INT8_C(  89), -INT8_C( 108),
         INT8_C( 119),  INT8_C(  49),  INT8_C(  29),  INT8_C(  32),  INT8_C(  25), -INT8_C( 110),  INT8_C(  98), -INT8_C( 102) },
      {  INT8_C(  59), -INT8_C(  43),  INT8_C(  99),  INT8_C( 112),  INT8_C( 112),  INT8_C(  36), -INT8_C( 124),  INT8_C( 108),
        -INT8_C(  55), -INT8_C(  96),  INT8_C(  33), -INT8_C(  20),  INT8_C(   8), -INT8_C(  95),  INT8_C(  92), -INT8_C(  71) },
      {  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C( 11249),  INT16_C(   317), -INT16_C( 13670),  INT16_C(     0) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_x_mm_loadu_epi8(test_vec[i].a);
    simde__m128i b = simde_x_mm_loadu_epi8(test_vec[i].b);
    simde__m128i r = simde_mm_maskz_maddubs_epi16(test_vec[i].k, a, b);
    simde_test_x86_assert_equal_i16x8(r, simde_x_mm_loadu_epi16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m128i a = simde_test_x86_random_i8x16();
    simde__m128i b = simde_test_x86_random_i8x16();
    simde__m128i r = simde_mm_maskz_maddubs_epi16(k, a, b);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i8x16(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i8x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_mask_maddubs_epi16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int16_t src[16];
    const simde__mmask16 k;
    const int8_t a[32];
    const int8_t b[32];
    const int16_t r[16];
  } test_vec[] = {
    { { -INT16_C( 25063),  INT16_C(  9857),  INT16_C( 10590), -INT16_C( 10566), -INT16_C( 10150),  INT16_C( 29686),  INT16_C( 22634), -INT16_C( 23283),
         INT16_C( 28718), -INT16_C( 25067), -INT16_C( 25963),  INT16_C( 24074),  INT16_C( 11066),  INT16_C( 17227), -INT16_C( 22580), -INT16_C(  6404) },
      UINT16_C(32069),
      {  INT8_C(  12), -INT8_C(  92), -INT8_C(  90), -INT8_C(  57),  INT8_C( 122),  INT8_C(   0), -INT8_C(  97),  INT8_C( 112),
         INT8_C( 115),  INT8_C(   9), -INT8_C(  56), -INT8_C( 127), -INT8_C(  82), -INT8_C(  10), -INT8_C(  15), -INT8_C(  60),
        -INT8_C( 108), -INT8_C( 122),  INT8_C(  94), -INT8_C(  97), -INT8_C(  27), -INT8_C( 104), -INT8_C(  54),  INT8_C(  48),
        -INT8_C(  37), -INT8_C( 105), -INT8_C(  41), -INT8_C(  41),  INT8_C( 125),  INT8_C(  29),  INT8_C(  85), -INT8_C( 119) },
      { -INT8_C(  63), -INT8_C(   5),  INT8_C(  80),  INT8_C(  59), -INT8_C(   4), -INT8_C(  17), -INT8_C(  85),  INT8_C( 111),
        -INT8_C(   8),  INT8_C( 115), -INT8_C(  16), -INT8_C(  89),  INT8_C( 106), -INT8_C(  30),  INT8_C( 107), -INT8_C(   2),
         INT8_C( 104), -INT8_C(  55), -INT8_C(  99),  INT8_C(  77),  INT8_C(  97),  INT8_C( 104),  INT8_C( 125),  INT8_C(  61),
        -INT8_C(   1),  INT8_C(  85),  INT8_C(  20),  INT8_C( 124),  INT8_C( 114),  INT8_C( 105),  INT8_C(   5),  INT8_C(  51) },
      { -INT16_C(  1576),  INT16_C(  9857), -INT16_C(   488), -INT16_C( 10566), -INT16_C( 10150),  INT16_C( 29686),  INT16_C( 11064), -INT16_C( 23283),
         INT16_C(  8022), -INT16_C( 25067),       INT16_MAX,  INT16_C( 28178),  INT16_C( 12616),  INT16_C( 30960),  INT16_C( 17295), -INT16_C(  6404) } },
    { {  INT16_C( 22117),  INT16_C( 24942),  INT16_C(  6469),  INT16_C( 16080), -INT16_C( 15988), -INT16_C(  2331),  INT16_C( 20643),  INT16_C(  3061),
        -INT16_C( 28135),  INT16_C( 31321), -INT16_C( 10502), -INT16_C(  1609), -INT16_C( 13269), -INT16_C( 25227),  INT16_C( 31541), -INT16_C( 25904) },
      UINT16_C(16081),
      { -INT8_C(   5),  INT8_C(  22),  INT8_C(  87), -INT8_C(  52),  INT8_C(  84), -INT8_C(  28), -INT8_C( 115),  INT8_C(  57),
        -INT8_C(  38),  INT8_C(  48), -INT8_C( 119), -INT8_C(  49),  INT8_C(  59), -INT8_C(  94),  INT8_C(  98), -INT8_C( 108),
         INT8_C(  29),  INT8_C(  92),  INT8_C( 107), -INT8_C(  44),  INT8_C(  86), -INT8_C( 106), -INT8_C(  96), -INT8_C(  53),
         INT8_C(  52), -INT8_C(  42),  INT8_C(  70),  INT8_C(   4),  INT8_C( 112),  INT8_C(  23),  INT8_C(  67),  INT8_C( 108) },
      {  INT8_C(  46), -INT8_C( 102),  INT8_C(  56), -INT8_C( 126),  INT8_C( 126), -INT8_C(  59), -INT8_C(  68),  INT8_C(  89),
        -INT8_C(  11),  INT8_C(  69),  INT8_C(  40),  INT8_C(  48), -INT8_C(  24), -INT8_C( 118), -INT8_C(  59),  INT8_C(   5),
        -INT8_C(  25),  INT8_C(  48), -INT8_C(  39),  INT8_C(  61), -INT8_C(  58),  INT8_C( 122),  INT8_C(   8), -INT8_C(   6),
         INT8_C(  80),  INT8_C(  79), -INT8_C(   1), -INT8_C(  64),  INT8_C( 102),  INT8_C(  66),  INT8_C(  44), -INT8_C( 108) },
      {  INT16_C(  9302),  INT16_C( 24942),  INT16_C(  6469),  INT16_C( 16080),  INT16_C(   914), -INT16_C(  2331), -INT16_C( 20532), -INT16_C(  5042),
        -INT16_C( 28135),  INT16_C(  8759),  INT16_C( 13312),  INT16_C(    62),  INT16_C( 21066), -INT16_C(   326),  INT16_C( 31541), -INT16_C( 25904) } },
    { {  INT16_C( 25820),  INT16_C( 23319), -INT16_C( 11479),  INT16_C(  7860), -INT16_C(  9192),  INT16_C(    79),  INT16_C(  5223),  INT16_C( 19973),
        -INT16_C(  8380),  INT16_C(  2699), -INT16_C( 27815), -INT16_C( 22267),  INT16_C(  1250),  INT16_C( 18793), -INT16_C( 27066),  INT16_C(  8925) },
      UINT16_C(62714),
      {  INT8_C( 125),  INT8_C(  36), -INT8_C(  57),  INT8_C(  49),  INT8_C(  66), -INT8_C(  32),  INT8_C(  14), -INT8_C( 111),
        -INT8_C(  32),  INT8_C( 117), -INT8_C(  91), -INT8_C(  26), -INT8_C(  61), -INT8_C(  23), -INT8_C(  59),  INT8_C(  78),
        -INT8_C(  12),  INT8_C(  30), -INT8_C(  31), -INT8_C(   7), -INT8_C(  57), -INT8_C(  60), -INT8_C(   3),  INT8_C(  48),
         INT8_C(  13),  INT8_C(  67), -INT8_C(  58), -INT8_C(  22),  INT8_C( 101), -INT8_C(  63), -INT8_C(  33), -INT8_C(  29) },
      { -INT8_C(  27), -INT8_C(  90),  INT8_C(  20),  INT8_C(  39), -INT8_C( 122),  INT8_C(  34), -INT8_C(  71),  INT8_C( 103),
        -INT8_C( 105),  INT8_C(  94),  INT8_C(  77),  INT8_C(  90),  INT8_C(  72),  INT8_C(  18), -INT8_C(  88),  INT8_C(  60),
         INT8_C(  48), -INT8_C( 118),  INT8_C(  53), -INT8_C(   9),  INT8_C(  78),  INT8_C(  50),  INT8_C(  39),  INT8_C(  91),
         INT8_C( 117), -INT8_C(  18),  INT8_C(  69), -INT8_C(  38), -INT8_C(  81),  INT8_C(  36), -INT8_C(  67), -INT8_C( 108) },
      {  INT16_C( 25820),  INT16_C(  5891), -INT16_C( 11479),  INT16_C( 13941), -INT16_C( 12522),       INT16_MAX,  INT16_C( 18234), -INT16_C( 12656),
        -INT16_C(  8380),  INT16_C(  2699),  INT16_C( 25322), -INT16_C( 22267),  INT16_C(   315),  INT16_C(  4770), -INT16_C(  1233),       INT16_MIN } },
    { { -INT16_C( 11573),  INT16_C( 20923),  INT16_C( 29940), -INT16_C( 29512),  INT16_C(  1491),  INT16_C(  7142), -INT16_C( 28905),  INT16_C( 18263),
        -INT16_C( 29671),  INT16_C( 26430),  INT16_C( 26302),  INT16_C( 13250),  INT16_C(  1876),  INT16_C(   781), -INT16_C( 13524), -INT16_C(  2153) },
      UINT16_C(21149),
      {  INT8_C(  72), -INT8_C( 111), -INT8_C(  57),  INT8_C(   1),  INT8_C(  29), -INT8_C( 102),  INT8_C(   6),  INT8_C(   4),
        -INT8_C(  75),  INT8_C(  30), -INT8_C( 109),  INT8_C(  12),  INT8_C( 101), -INT8_C(  84), -INT8_C( 104), -INT8_C(  92),
         INT8_C(  19),  INT8_C(  86),  INT8_C(  10), -INT8_C(  43), -INT8_C( 119),  INT8_C(  94), -INT8_C(  36), -INT8_C( 106),
         INT8_C(  97),  INT8_C(   8),  INT8_C(  97), -INT8_C(   8), -INT8_C(   1), -INT8_C(   2),  INT8_C(  74),  INT8_C(  72) },
      { -INT8_C( 112),  INT8_C(  17),  INT8_C(  73), -INT8_C(  83), -INT8_C(  85),  INT8_C(  79), -INT8_C(  79),  INT8_C(  96),
         INT8_C( 109),  INT8_C(  68),  INT8_C( 108), -INT8_C(  45), -INT8_C(  16),  INT8_C(   4),  INT8_C( 119),  INT8_C(   3),
         INT8_C(  90), -INT8_C( 127), -INT8_C(  40), -INT8_C(  29), -INT8_C(  33), -INT8_C(  75),  INT8_C( 122),  INT8_C(  64),
        -INT8_C(  67), -INT8_C(  37),  INT8_C(  56), -INT8_C(  67), -INT8_C(  38), -INT8_C( 126),  INT8_C(   5),  INT8_C( 106) },
      { -INT16_C(  5599),  INT16_C( 20923),  INT16_C(  9701), -INT16_C(    90),  INT16_C( 21769),  INT16_C(  7142), -INT16_C( 28905),  INT16_C( 18580),
        -INT16_C( 29671), -INT16_C(  6577),  INT16_C( 26302),  INT16_C( 13250), -INT16_C(  6795),  INT16_C(   781),       INT16_MIN, -INT16_C(  2153) } },
    { {  INT16_C( 20116),  INT16_C( 16151), -INT16_C( 13923),  INT16_C(  2976),  INT16_C(  3085), -INT16_C(   290),  INT16_C( 21777),  INT16_C( 27393),
        -INT16_C(  9514), -INT16_C( 19121), -INT16_C( 13937),  INT16_C( 19701),  INT16_C( 11684),  INT16_C( 32265),  INT16_C(  3759),  INT16_C( 17384) },
      UINT16_C(   92),
      { -INT8_C( 125), -INT8_C(   6), -INT8_C(  55),  INT8_C(  35),  INT8_C(   5), -INT8_C(  42),  INT8_C(  47), -INT8_C(  29),
        -INT8_C(  44),  INT8_C(  64),  INT8_C(  56), -INT8_C(  42), -INT8_C(  84),  INT8_C(  14), -INT8_C(  80), -INT8_C(   5),
        -INT8_C(  61),  INT8_C(  63), -INT8_C(  60), -INT8_C(  72), -INT8_C( 117),  INT8_C( 104), -INT8_C(  27), -INT8_C( 107),
        -INT8_C(  25), -INT8_C( 108), -INT8_C(  93), -INT8_C(  49), -INT8_C(  40),  INT8_C(   0), -INT8_C(  49),  INT8_C(  91) },
      { -INT8_C(   6), -INT8_C( 104),  INT8_C( 126), -INT8_C(   1),  INT8_C( 111), -INT8_C(  83), -INT8_C(  30),  INT8_C(  67),
        -INT8_C(  18),  INT8_C(  26),  INT8_C(  25), -INT8_C( 102),  INT8_C(  40), -INT8_C(  55), -INT8_C( 107), -INT8_C(  21),
         INT8_C(   8),  INT8_C(  89), -INT8_C(  93), -INT8_C( 108), -INT8_C(  63), -INT8_C( 120),  INT8_C(  41), -INT8_C(  88),
         INT8_C(  28), -INT8_C(  52),  INT8_C( 120), -INT8_C(  12), -INT8_C(  52),  INT8_C(  71),  INT8_C(  79), -INT8_C(  58) },
      {  INT16_C( 20116),  INT16_C( 16151), -INT16_C( 17207),  INT16_C( 13799), -INT16_C(  2152), -INT16_C(   290),  INT16_C(  6110),  INT16_C( 27393),
        -INT16_C(  9514), -INT16_C( 19121), -INT16_C( 13937),  INT16_C( 19701),  INT16_C( 11684),  INT16_C( 32265),  INT16_C(  3759),  INT16_C( 17384) } },
    { { -INT16_C( 12832),  INT16_C( 20421), -INT16_C( 22661),  INT16_C( 27026), -INT16_C( 21311), -INT16_C(  5885), -INT16_C( 26507),  INT16_C( 32468),
         INT16_C( 30705), -INT16_C( 19950),  INT16_C( 15359),  INT16_C(  7259), -INT16_C( 11513), -INT16_C( 11248),  INT16_C( 24602), -INT16_C(  1382) },
      UINT16_C(24621),
      {  INT8_C(  73), -INT8_C(  88),  INT8_C(   7), -INT8_C(  36),  INT8_C(  17), -INT8_C(  55), -INT8_C( 120),  INT8_C(  20),
        -INT8_C(  78), -INT8_C(   3), -INT8_C(  84), -INT8_C( 121),  INT8_C( 123), -INT8_C(  99), -INT8_C(   2), -INT8_C( 115),
         INT8_C(  80), -INT8_C(   2), -INT8_C(  56), -INT8_C(  85),  INT8_C(  26), -INT8_C(  48),  INT8_C( 126),  INT8_C(  42),
        -INT8_C(  92), -INT8_C( 104), -INT8_C( 118),  INT8_C(  62), -INT8_C( 109), -INT8_C(  72), -INT8_C(  98), -INT8_C(  36) },
      {  INT8_C(  96), -INT8_C(  90), -INT8_C(  72),  INT8_C( 114),  INT8_C( 111),  INT8_C(  64), -INT8_C( 122),  INT8_C(  33),
         INT8_C(  62),  INT8_C(  51), -INT8_C(  88), -INT8_C(  71), -INT8_C(  48), -INT8_C(  89),  INT8_C(  71),  INT8_C(  32),
        -INT8_C(  91),  INT8_C(  15), -INT8_C(  53), -INT8_C(  65), -INT8_C(  33),  INT8_C(  73), -INT8_C(  23), -INT8_C( 125),
        -INT8_C(  30),  INT8_C( 116), -INT8_C(  62),  INT8_C( 117),  INT8_C(  44),  INT8_C(  96),  INT8_C(  81), -INT8_C( 116) },
      { -INT16_C(  8112),  INT16_C( 20421),  INT16_C( 14751), -INT16_C( 15932), -INT16_C( 21311), -INT16_C( 24721), -INT16_C( 26507),  INT16_C( 32468),
         INT16_C( 30705), -INT16_C( 19950),  INT16_C( 15359),  INT16_C(  7259), -INT16_C( 11513), -INT16_C(  1302),  INT16_C( 24132), -INT16_C(  1382) } },
    { {  INT16_C(  2566),  INT16_C( 30206), -INT16_C( 31414), -INT16_C( 30569),  INT16_C( 16312), -INT16_C( 30654), -INT16_C( 30234), -INT16_C( 29783),
         INT16_C( 29848),  INT16_C( 30794),  INT16_C( 13502), -INT16_C( 24325), -INT16_C( 16984), -INT16_C( 11243),  INT16_C( 26142),  INT16_C(  9312) },
      UINT16_C(24432),
      { -INT8_C( 102), -INT8_C(  69), -INT8_C(  28),  INT8_C(  49),  INT8_C(  67), -INT8_C( 100),  INT8_C( 112), -INT8_C( 123),
         INT8_C(  36),  INT8_C(  87),  INT8_C(  14), -INT8_C(  51), -INT8_C(  30), -INT8_C(  89),  INT8_C(  66),  INT8_C(  45),
         INT8_C(  31),  INT8_C(   0),  INT8_C(  97),  INT8_C(  26), -INT8_C(  96),  INT8_C(   9), -INT8_C(  40), -INT8_C(  75),
        -INT8_C(  35), -INT8_C(  10),  INT8_C(  27),  INT8_C(  61),  INT8_C(  26), -INT8_C( 116), -INT8_C( 100), -INT8_C(  76) },
      {  INT8_C(  71),      INT8_MIN, -INT8_C(  27), -INT8_C( 118),  INT8_C(  28),  INT8_C(  86),  INT8_C(  16),  INT8_C(  65),
        -INT8_C(  83),  INT8_C(  30),  INT8_C(  14), -INT8_C( 113), -INT8_C(  59),  INT8_C(  80), -INT8_C(  68), -INT8_C(  28),
         INT8_C(  80),  INT8_C(  29), -INT8_C(   1), -INT8_C(  16),  INT8_C(  38), -INT8_C(  41), -INT8_C(  91),  INT8_C(   3),
        -INT8_C(  51), -INT8_C(  63),  INT8_C(  65), -INT8_C(  25),  INT8_C(  77), -INT8_C(  35), -INT8_C( 100), -INT8_C( 108) },
      {  INT16_C(  2566),  INT16_C( 30206), -INT16_C( 31414), -INT16_C( 30569), -INT16_C(   378), -INT16_C( 22969),  INT16_C(    26), -INT16_C( 29783),
         INT16_C(  2480), -INT16_C(   513),  INT16_C(  5711), -INT16_C( 19113), -INT16_C( 26769), -INT16_C( 11243), -INT16_C(  2898),  INT16_C(  9312) } },
    { { -INT16_C( 32418),  INT16_C( 31262),  INT16_C( 11991), -INT16_C( 31557), -INT16_C( 13747),  INT16_C(  4628), -INT16_C( 12262),  INT16_C( 27639),
        -INT16_C(  2322),  INT16_C(  5211),  INT16_C(   461), -INT16_C( 26088),  INT16_C( 22978),  INT16_C(  3969),  INT16_C(  7478), -INT16_C( 27485) },
      UINT16_C(49567),
      {  INT8_C(  15),  INT8_C( 118), -INT8_C(  16), -INT8_C(  54), -INT8_C(   5),  INT8_C(  61), -INT8_C( 108),  INT8_C(  15),
         INT8_C(  79), -INT8_C(  81), -INT8_C(  33),  INT8_C(  70),  INT8_C(  26), -INT8_C(  51),  INT8_C(  60),  INT8_C( 117),
        -INT8_C(  30),  INT8_C(   9),  INT8_C( 118), -INT8_C(   6), -INT8_C(  93),  INT8_C(  56),  INT8_C(  83),  INT8_C(  37),
         INT8_C(  71), -INT8_C( 119),  INT8_C(  66), -INT8_C(  22),  INT8_C(  30), -INT8_C(  31), -INT8_C(  84),  INT8_C(  45) },
      {  INT8_C(  88), -INT8_C( 100), -INT8_C(   9),  INT8_C(  83), -INT8_C(  39), -INT8_C( 116),  INT8_C(  98),  INT8_C(  40),
         INT8_C(  59),  INT8_C(  65),  INT8_C( 111),  INT8_C(  85),  INT8_C(  15), -INT8_C(  85), -INT8_C(  54), -INT8_C(  15),
        -INT8_C(  75),  INT8_C(  65), -INT8_C(  21),  INT8_C(  88),  INT8_C( 121),  INT8_C(  62),  INT8_C( 125), -INT8_C(  63),
        -INT8_C(  57), -INT8_C(  64), -INT8_C(  85), -INT8_C(  27), -INT8_C(  95),  INT8_C(  87),  INT8_C(  18), -INT8_C(   7) },
      { -INT16_C( 10480),  INT16_C( 14606), -INT16_C( 16865),  INT16_C( 15104),  INT16_C( 16036),  INT16_C(  4628), -INT16_C( 12262), -INT16_C(  4995),
        -INT16_C( 16365),  INT16_C(  5211),  INT16_C(   461), -INT16_C( 26088),  INT16_C( 22978),  INT16_C(  3969),  INT16_C( 16725),  INT16_C(  2781) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256i src = simde_x_mm256_loadu_epi16(test_vec[i].src);
    simde__m256i a = simde_x_mm256_loadu_epi8(test_vec[i].a);
    simde__m256i b = simde_x_mm256_loadu_epi8(test_vec[i].b);
    simde__m256i r = simde_mm256_mask_maddubs_epi16(src, test_vec[i].k, a, b);
    simde_test_x86_assert_equal_i16x16(r, simde_x_mm256_loadu_epi16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m256i src = simde_test_x86_random_i16x16();
    simde__mmask16 k = simde_test_x86_random_mmask16();
    simde__m256i a = simde_test_x86_random_i8x32();
    simde__m256i b = simde_test_x86_random_i8x32();
    simde__m256i r = simde_mm256_mask_maddubs_epi16(src, k, a, b);

    simde_test_x86_write_i16x16(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask16(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i8x32(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i8x32(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_maskz_maddubs_epi16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask16 k;
    const int8_t a[32];
    const int8_t b[32];
    const int16_t r[16];
  } test_vec[] = {
    { UINT16_C(26598),
      {  INT8_C( 114),  INT8_C(   2),  INT8_C(  26),  INT8_C( 124), -INT8_C(  18),  INT8_C(   2),  INT8_C(  62), -INT8_C(  43),
         INT8_C(  83), -INT8_C(  95),  INT8_C(  69), -INT8_C( 118), -INT8_C(  83),  INT8_C(  46),  INT8_C(  85), -INT8_C(   9),
        -INT8_C( 123),  INT8_C( 123), -INT8_C(  55), -INT8_C(  52),  INT8_C(  82),  INT8_C(   7),  INT8_C(  82),  INT8_C(  79),
        -INT8_C(  95), -INT8_C(  65),      INT8_MAX,  INT8_C( 115), -INT8_C(  97),  INT8_C( 102), -INT8_C(  38),  INT8_C(  17) },
      {  INT8_C( 104), -INT8_C(  12), -INT8_C( 115),  INT8_C(  86), -INT8_C(   9), -INT8_C(  53),  INT8_C(  43),  INT8_C(  74),
         INT8_C( 108),  INT8_C( 112), -INT8_C(  44),  INT8_C(  25), -INT8_C(  98),  INT8_C(  42),  INT8_C(  16),  INT8_C(  35),
        -INT8_C(  91), -INT8_C(  38), -INT8_C(  17), -INT8_C(   8), -INT8_C(  31),  INT8_C(  65),  INT8_C(  71), -INT8_C( 126),
         INT8_C(   1), -INT8_C(  58), -INT8_C(  11), -INT8_C(  96),  INT8_C(  44), -INT8_C(  48), -INT8_C(  79), -INT8_C( 108) },
      {  INT16_C(     0),  INT16_C(  7674), -INT16_C(  2248),  INT16_C(     0),  INT16_C(     0),  INT16_C(   414), -INT16_C( 15022),  INT16_C( 10005),
        -INT16_C( 16777), -INT16_C(  5049), -INT16_C(  2087),  INT16_C(     0),  INT16_C(     0), -INT16_C( 12437),  INT16_C(  2100),  INT16_C(     0) } },
    { UINT16_C(16068),
      { -INT8_C(  22), -INT8_C(  69),  INT8_C(   9),  INT8_C(  21),  INT8_C(   5),  INT8_C( 118), -INT8_C( 123), -INT8_C(  38),
        -INT8_C( 113),  INT8_C(  36),  INT8_C(   4), -INT8_C(  96),  INT8_C(  71), -INT8_C(  87),  INT8_C( 122),  INT8_C(  55),
        -INT8_C(  95),  INT8_C(  91),  INT8_C( 120), -INT8_C(  24), -INT8_C(  35),  INT8_C( 121), -INT8_C(  81), -INT8_C(  46),
         INT8_C(  25), -INT8_C(  37), -INT8_C(  94), -INT8_C(  54),  INT8_C( 112),  INT8_C( 103),  INT8_C(   8),  INT8_C(  90) },
      {  INT8_C(  34),  INT8_C(  18),  INT8_C( 112),  INT8_C(  40), -INT8_C( 120), -INT8_C(  11),  INT8_C(   2),  INT8_C(  23),
         INT8_C(  25),  INT8_C(   6), -INT8_C(  73),  INT8_C(  97), -INT8_C(  81),  INT8_C(  49), -INT8_C( 104),  INT8_C(  81),
        -INT8_C( 116),  INT8_C(  16),  INT8_C(  57),  INT8_C( 105), -INT8_C( 118), -INT8_C(  24),  INT8_C(  60), -INT8_C(  93),
        -INT8_C(  60), -INT8_C(  34),  INT8_C( 110),  INT8_C(  52),  INT8_C(  69),  INT8_C( 118), -INT8_C( 114),  INT8_C( 104) },
      {  INT16_C(     0),  INT16_C(     0), -INT16_C(  1898),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(  2530), -INT16_C(  8233),
         INT16_C(     0),  INT16_C( 31200), -INT16_C( 28982), -INT16_C(  9030), -INT16_C(  8946),  INT16_C( 28324),  INT16_C(     0),  INT16_C(     0) } },
    { UINT16_C(65160),
      { -INT8_C( 112),  INT8_C(  16), -INT8_C(  12), -INT8_C( 110),  INT8_C(  40),  INT8_C(  13), -INT8_C( 104), -INT8_C(  33),
         INT8_C( 110),  INT8_C(  71),  INT8_C(  17),  INT8_C(   6), -INT8_C( 104), -INT8_C(  99),  INT8_C(  23), -INT8_C(  46),
         INT8_C(   7), -INT8_C(  95), -INT8_C(  70),  INT8_C(  67),  INT8_C(  68),  INT8_C( 126),  INT8_C(  33), -INT8_C(  78),
        -INT8_C(  78),  INT8_C( 103),  INT8_C(  41),  INT8_C(  65), -INT8_C(  49), -INT8_C(  79),  INT8_C(  63),  INT8_C(  95) },
      { -INT8_C(  62),  INT8_C(  51), -INT8_C(  15), -INT8_C(  22),  INT8_C(  65), -INT8_C( 119), -INT8_C(  55), -INT8_C(  81),
        -INT8_C(  48), -INT8_C(  38), -INT8_C(  74),  INT8_C( 105),  INT8_C( 120), -INT8_C(  51),  INT8_C(  59),      INT8_MAX,
         INT8_C( 110), -INT8_C(  11), -INT8_C(  62), -INT8_C(  78),  INT8_C( 116), -INT8_C(  29),  INT8_C( 101),  INT8_C(  38),
         INT8_C(  74), -INT8_C( 114),  INT8_C( 103),  INT8_C(  25),  INT8_C(  63), -INT8_C(  89),  INT8_C( 120),  INT8_C(   1) },
      {  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C( 26423),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C( 28027),
         INT16_C(     0), -INT16_C( 16758),  INT16_C(  4234),  INT16_C( 10097),  INT16_C(  1430),  INT16_C(  5848), -INT16_C(  2712),  INT16_C(  7655) } },
    { UINT16_C(27098),
      { -INT8_C(  21),  INT8_C(  27), -INT8_C(  14), -INT8_C(  75), -INT8_C(  53), -INT8_C(  61), -INT8_C( 113), -INT8_C( 127),
         INT8_C(  44),  INT8_C(   7),  INT8_C(  78),  INT8_C( 103), -INT8_C( 122), -INT8_C(  68),  INT8_C(  92),  INT8_C(  72),
         INT8_C( 110), -INT8_C(  48),  INT8_C(  44), -INT8_C(  45), -INT8_C(   9),  INT8_C( 118),  INT8_C(  97),  INT8_C(  94),
        -INT8_C( 112), -INT8_C(  95),  INT8_C(   5),  INT8_C(   8), -INT8_C(  94), -INT8_C(  32),  INT8_C( 114), -INT8_C( 114) },
      { -INT8_C(   5),  INT8_C( 100),  INT8_C(  67), -INT8_C(  58),  INT8_C(  39), -INT8_C(  46),  INT8_C(  71),  INT8_C(  83),
        -INT8_C(  38), -INT8_C( 107), -INT8_C(  70),  INT8_C(  96),  INT8_C(  81),  INT8_C(  23), -INT8_C(  87), -INT8_C(  64),
        -INT8_C(  25), -INT8_C(  43), -INT8_C( 109), -INT8_C(  34),  INT8_C(  75), -INT8_C(  11),  INT8_C(  61), -INT8_C(  37),
        -INT8_C( 106),  INT8_C(  66), -INT8_C(  28),  INT8_C(  56),  INT8_C(  34),  INT8_C(  86), -INT8_C(  58),  INT8_C(  30) },
      {  INT16_C(     0),  INT16_C(  5716),  INT16_C(     0),  INT16_C( 20860), -INT16_C(  2421),  INT16_C(     0),  INT16_C( 15178), -INT16_C( 12612),
        -INT16_C( 11694),  INT16_C(     0),  INT16_C(     0),  INT16_C(  2439),  INT16_C(     0),  INT16_C(   308),  INT16_C( 24772),  INT16_C(     0) } },
    { UINT16_C( 2490),
      { -INT8_C(  28), -INT8_C(  30), -INT8_C(  36),  INT8_C(  44),  INT8_C(  53), -INT8_C(  74), -INT8_C(  63), -INT8_C(  16),
         INT8_C(  22),  INT8_C(  19),  INT8_C(   7), -INT8_C(  65), -INT8_C(  45), -INT8_C(  18), -INT8_C( 108),  INT8_C( 102),
        -INT8_C(  51), -INT8_C(  32),  INT8_C(  91),  INT8_C(  10), -INT8_C(  69), -INT8_C(  15),  INT8_C(  76), -INT8_C(  97),
         INT8_C(  42),  INT8_C( 111), -INT8_C(  11), -INT8_C(  16), -INT8_C( 115), -INT8_C(  80), -INT8_C(   6),  INT8_C( 113) },
      { -INT8_C( 110), -INT8_C(  42), -INT8_C(  99), -INT8_C(  57), -INT8_C( 116),  INT8_C(  95), -INT8_C(  73), -INT8_C(  94),
         INT8_C( 114), -INT8_C(  66),  INT8_C(  98),  INT8_C(  69), -INT8_C(  83), -INT8_C(  10), -INT8_C(  85),  INT8_C( 122),
        -INT8_C(  42),  INT8_C(   7), -INT8_C( 124), -INT8_C( 110), -INT8_C(   8), -INT8_C(  48),  INT8_C(  49),  INT8_C(  34),
         INT8_C(  63),  INT8_C(  39),  INT8_C(  19), -INT8_C(  52), -INT8_C(  41),  INT8_C(  13),  INT8_C(  62),  INT8_C( 105) },
      {  INT16_C(     0), -INT16_C( 24288),  INT16_C(     0),       INT16_MIN,  INT16_C(  1254),  INT16_C( 13865),  INT16_C(     0), -INT16_C(   136),
        -INT16_C(  7042),  INT16_C(     0),  INT16_C(     0),  INT16_C(  9130),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
    { UINT16_C(56291),
      {  INT8_C(  48),  INT8_C( 111),  INT8_C(  58), -INT8_C(  24),  INT8_C(  17), -INT8_C(  84), -INT8_C(  90),  INT8_C( 115),
        -INT8_C(  15),  INT8_C(  83),  INT8_C( 106), -INT8_C(  99), -INT8_C(  51),  INT8_C(  64), -INT8_C(  92),  INT8_C(  81),
        -INT8_C(  46), -INT8_C( 100),  INT8_C(  34),  INT8_C(   4), -INT8_C(  65),  INT8_C(  97),  INT8_C(  43), -INT8_C(  46),
         INT8_C(  46),  INT8_C(   2), -INT8_C(  33),  INT8_C( 108),  INT8_C( 107), -INT8_C(  62),  INT8_C(  71), -INT8_C( 101) },
      {  INT8_C(  49), -INT8_C( 126), -INT8_C( 125),  INT8_C(  66),  INT8_C(  46),  INT8_C(  42), -INT8_C(  74),  INT8_C(  32),
         INT8_C( 125),  INT8_C(  32), -INT8_C(  67),  INT8_C(  75),  INT8_C(  96),  INT8_C(  97), -INT8_C( 100),  INT8_C(  51),
        -INT8_C(   3), -INT8_C(  66),  INT8_C(  55), -INT8_C(  68),  INT8_C(  32),  INT8_C(  98), -INT8_C( 114),  INT8_C(  78),
         INT8_C( 100),  INT8_C( 109), -INT8_C(  70), -INT8_C(  49),  INT8_C(  47),  INT8_C(   1),  INT8_C( 106),  INT8_C(  96) },
      { -INT16_C( 11634),  INT16_C(  8062),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(  4673),  INT16_C( 25888), -INT16_C( 12269),
        -INT16_C( 10926),  INT16_C(  1598),  INT16_C(     0),  INT16_C( 11478),  INT16_C(  4818),  INT16_C(     0),  INT16_C(  5223),  INT16_C( 22406) } },
    { UINT16_C(61059),
      { -INT8_C(  93), -INT8_C(  78),  INT8_C(  24),  INT8_C(  89), -INT8_C(  46), -INT8_C( 107),  INT8_C( 121), -INT8_C( 113),
        -INT8_C(  32), -INT8_C(  39), -INT8_C(  16),  INT8_C( 125),  INT8_C(  12), -INT8_C(  19),  INT8_C(  59),  INT8_C(  67),
        -INT8_C(  86),  INT8_C(  91), -INT8_C(  91),  INT8_C(  56), -INT8_C(  87),  INT8_C(   9), -INT8_C(  90),  INT8_C(  99),
        -INT8_C(  40), -INT8_C(  43),  INT8_C( 101),  INT8_C(  67),  INT8_C(  54), -INT8_C(  24),  INT8_C(  49), -INT8_C(  39) },
      { -INT8_C( 102),  INT8_C(  73),  INT8_C(  50),  INT8_C( 108), -INT8_C(  34), -INT8_C(  85), -INT8_C(   5), -INT8_C(  65),
        -INT8_C( 124), -INT8_C(  21),  INT8_C(  60), -INT8_C( 111), -INT8_C(  39),  INT8_C( 119), -INT8_C(  44), -INT8_C( 125),
        -INT8_C(  45),  INT8_C( 122), -INT8_C(  69),  INT8_C( 124), -INT8_C( 125),  INT8_C(  97), -INT8_C(  32),  INT8_C(  92),
         INT8_C(  55),  INT8_C(  69), -INT8_C(  97),  INT8_C( 109),  INT8_C(  45), -INT8_C(  48),  INT8_C(  70), -INT8_C(  56) },
      { -INT16_C(  3632),  INT16_C( 10812),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C( 10971),
         INT16_C(     0), -INT16_C(  4441), -INT16_C( 20252),  INT16_C(  3796),  INT16_C(     0), -INT16_C(  2494), -INT16_C(  8706), -INT16_C(  8722) } },
    { UINT16_C(30745),
      {  INT8_C(  52), -INT8_C(   9),  INT8_C(  35),  INT8_C(  48), -INT8_C(  74), -INT8_C(  89),  INT8_C(  27), -INT8_C(  14),
         INT8_C(  56), -INT8_C(  12),  INT8_C( 106),  INT8_C(  13),  INT8_C( 119),  INT8_C(  61), -INT8_C( 121),  INT8_C(  51),
        -INT8_C(  71),  INT8_C(  10), -INT8_C( 108), -INT8_C( 103),  INT8_C( 102), -INT8_C(  53), -INT8_C(  34),  INT8_C(   5),
         INT8_C(  56),  INT8_C(  12), -INT8_C(  43),  INT8_C( 126), -INT8_C(  44), -INT8_C(  18), -INT8_C(  10),  INT8_C(   8) },
      { -INT8_C(  26),  INT8_C(  25),  INT8_C(  56), -INT8_C( 100), -INT8_C(  63),  INT8_C(  84), -INT8_C( 113), -INT8_C(   7),
         INT8_C(  72), -INT8_C(   7),  INT8_C(   6), -INT8_C(  64),  INT8_C(  54), -INT8_C( 115), -INT8_C(  13), -INT8_C(  17),
        -INT8_C( 104), -INT8_C( 121), -INT8_C( 119), -INT8_C(   2),  INT8_C(  83),  INT8_C( 103),  INT8_C(   4), -INT8_C( 117),
         INT8_C( 115), -INT8_C(  39),  INT8_C(  10),  INT8_C(  71), -INT8_C(  56),  INT8_C(   0),  INT8_C(  80), -INT8_C(  82) },
      {  INT16_C(  4823),  INT16_C(     0),  INT16_C(     0), -INT16_C(  4745),  INT16_C(  2324),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
         INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(   303),  INT16_C(  5972),  INT16_C( 11076), -INT16_C( 11872),  INT16_C(     0) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256i a = simde_x_mm256_loadu_epi8(test_vec[i].a);
    simde__m256i b = simde_x_mm256_loadu_epi8(test_vec[i].b);
    simde__m256i r = simde_mm256_maskz_maddubs_epi16(test_vec[i].k, a, b);
    simde_test_x86_assert_equal_i16x16(r, simde_x_mm256_loadu_epi16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask16 k = simde_test_x86_random_mmask16();
    simde__m256i a = simde_test_x86_random_i8x32();
    simde__m256i b = simde_test_x86_random_i8x32();
    simde__m256i r = simde_mm256_maskz_maddubs_epi16(k, a, b);

    simde_test_x86_write_mmask16(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i8x32(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i8x32(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_maddubs_epi16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int8_t a[64];
    const int8_t b[64];
    const int16_t r[32];
  } test_vec[] = {
    { {  INT8_C(  26), -INT8_C( 120),  INT8_C(  74), -INT8_C(  37), -INT8_C(  36), -INT8_C(  39), -INT8_C(  44),  INT8_C(  37),
        -INT8_C(  46), -INT8_C(  37), -INT8_C(  27),  INT8_C(   8),  INT8_C( 104), -INT8_C(  40), -INT8_C(   8),  INT8_C(   0),
         INT8_C(  95), -INT8_C( 127), -INT8_C(   1), -INT8_C(  78), -INT8_C(  24),  INT8_C(   3),  INT8_C(  62),  INT8_C(  92),
        -INT8_C(  36),  INT8_C(  72), -INT8_C(  93), -INT8_C(  92),  INT8_C(  72), -INT8_C(  13),  INT8_C(  82),  INT8_C(  98),
         INT8_C( 124), -INT8_C(  99),  INT8_C(  61),  INT8_C(  88),  INT8_C( 118),  INT8_C(  18),  INT8_C( 125),  INT8_C(  73),
        -INT8_C(  19),  INT8_C(  98),  INT8_C(  81),  INT8_C(  85),  INT8_C(  58),  INT8_C(  73),  INT8_C(  86), -INT8_C( 102),
        -INT8_C(  54),  INT8_C(  85),  INT8_C(  76), -INT8_C(  77),  INT8_C(  88), -INT8_C( 118),  INT8_C(  15),  INT8_C(  52),
        -INT8_C(  46), -INT8_C(  78), -INT8_C(  39),  INT8_C(  27), -INT8_C(  90),  INT8_C(  43),  INT8_C( 125),  INT8_C(  34) },
      { -INT8_C(  56), -INT8_C(  69),  INT8_C( 122),  INT8_C(  63), -INT8_C(  51), -INT8_C(   8), -INT8_C( 120), -INT8_C(  70),
         INT8_C(  90), -INT8_C(  39),  INT8_C(  15), -INT8_C( 107),  INT8_C(  35),  INT8_C( 101),  INT8_C(  47), -INT8_C(  19),
        -INT8_C(  70),  INT8_C( 123), -INT8_C(  96),  INT8_C(  18),  INT8_C(   6), -INT8_C(  81),  INT8_C(  71), -INT8_C(  40),
         INT8_C(  98),  INT8_C(  32), -INT8_C(  13),  INT8_C(   8),  INT8_C(  75),  INT8_C( 113),  INT8_C(  42),  INT8_C(  20),
         INT8_C(  44), -INT8_C(  92),  INT8_C(  83), -INT8_C(   7), -INT8_C( 100), -INT8_C(  37), -INT8_C(  77), -INT8_C(   9),
        -INT8_C(  76), -INT8_C(  62), -INT8_C( 116), -INT8_C(  41),  INT8_C(  40), -INT8_C(  69), -INT8_C(  59), -INT8_C(  30),
         INT8_C(  54),  INT8_C( 101), -INT8_C(  11),  INT8_C(  60),  INT8_C(  21),  INT8_C(  60),  INT8_C(  21),  INT8_C( 119),
         INT8_C(  92),  INT8_C(   8),      INT8_MAX, -INT8_C(  89),  INT8_C( 121), -INT8_C(  87), -INT8_C(  69), -INT8_C(  91) },
      { -INT16_C( 10840),  INT16_C( 22825), -INT16_C( 12956), -INT16_C( 28030),  INT16_C( 10359),  INT16_C(  2579),  INT16_C( 25456),  INT16_C( 11656),
         INT16_C(  9217), -INT16_C( 21276),  INT16_C(  1149),  INT16_C(   722),  INT16_C( 23864), -INT16_C(   807),       INT16_MAX,  INT16_C(  5404),
        -INT16_C(  8988),  INT16_C(  4447), -INT16_C( 12466), -INT16_C( 10282), -INT16_C( 24088), -INT16_C( 12881), -INT16_C(  2717), -INT16_C(  9694),
         INT16_C( 19493),  INT16_C(  9904),  INT16_C( 10128),  INT16_C(  6503),  INT16_C( 20744),  INT16_C( 25156),  INT16_C( 16345), -INT16_C( 11719) } },
    { {  INT8_C(  77),  INT8_C(  14), -INT8_C(  98), -INT8_C(  22), -INT8_C(  23),  INT8_C(  81), -INT8_C(  31), -INT8_C(  98),
         INT8_C(  20),  INT8_C( 109),  INT8_C( 117),  INT8_C(  60),  INT8_C(  40),  INT8_C(  58),  INT8_C(  30),  INT8_C(  94),
        -INT8_C(  96),  INT8_C(  19), -INT8_C( 101), -INT8_C(  75),  INT8_C(  79), -INT8_C(  80),  INT8_C(  44), -INT8_C(  85),
        -INT8_C(  72), -INT8_C(  85),  INT8_C(  83),  INT8_C(  50),  INT8_C(  84),  INT8_C(  14), -INT8_C(  41), -INT8_C(  95),
         INT8_C(  29),  INT8_C( 118), -INT8_C( 117),  INT8_C(   6), -INT8_C(  57),  INT8_C( 108), -INT8_C(  92), -INT8_C(  37),
        -INT8_C(  39),  INT8_C(  26),  INT8_C(  23),  INT8_C(   1),  INT8_C(  84),  INT8_C(  54),  INT8_C(  96), -INT8_C(  12),
         INT8_C(  73), -INT8_C(   5), -INT8_C(  87), -INT8_C( 103), -INT8_C(  85), -INT8_C(  43),  INT8_C(  68),  INT8_C(  99),
             INT8_MIN, -INT8_C( 105), -INT8_C( 107), -INT8_C(  44), -INT8_C(  90),  INT8_C( 109),  INT8_C( 118), -INT8_C(  61) },
      { -INT8_C(  29),  INT8_C(   1), -INT8_C(  55), -INT8_C(  86),  INT8_C( 110),  INT8_C( 110), -INT8_C( 122),  INT8_C(  71),
        -INT8_C( 120), -INT8_C(  99),  INT8_C(  73), -INT8_C(  36), -INT8_C(  45), -INT8_C(  87), -INT8_C(  47),  INT8_C(  29),
        -INT8_C(  92),  INT8_C( 122), -INT8_C(  74),  INT8_C(  79),  INT8_C(  80), -INT8_C(   6), -INT8_C(  78), -INT8_C(  48),
        -INT8_C( 110),  INT8_C(  72), -INT8_C(  91),  INT8_C(  56), -INT8_C(  75),  INT8_C(  27), -INT8_C(   5), -INT8_C( 104),
         INT8_C(  28), -INT8_C(  60),  INT8_C(  66), -INT8_C( 118),  INT8_C(  50), -INT8_C(  56), -INT8_C(  46), -INT8_C(  70),
         INT8_C( 102),  INT8_C(  27), -INT8_C( 105),  INT8_C(  57), -INT8_C(  60),  INT8_C( 104),  INT8_C(  86),  INT8_C( 104),
        -INT8_C(  30),  INT8_C(  12), -INT8_C(  73),  INT8_C(  50),  INT8_C(   7),  INT8_C( 105),  INT8_C(   3), -INT8_C( 103),
        -INT8_C(  79), -INT8_C(  88), -INT8_C(  47),  INT8_C( 102), -INT8_C(  61), -INT8_C(  52), -INT8_C(   2), -INT8_C(  33) },
      { -INT16_C(  2219), -INT16_C( 28814),       INT16_MAX, -INT16_C( 16232), -INT16_C( 13191),  INT16_C(  6381), -INT16_C(  6846),  INT16_C(  1316),
        -INT16_C( 12402),  INT16_C(  2829),  INT16_C(  5264), -INT16_C( 11640), -INT16_C(  7928), -INT16_C(  4753), -INT16_C(  5922), -INT16_C( 17819),
        -INT16_C(  6268),  INT16_C(  8466),  INT16_C(  3902), -INT16_C( 22874),  INT16_C( 22836), -INT16_C(  2358),  INT16_C(   576),       INT16_MAX,
         INT16_C(   822), -INT16_C(  4687),  INT16_C( 23562), -INT16_C(  9993), -INT16_C( 23400),  INT16_C( 14621), -INT16_C( 15794), -INT16_C(  6671) } },
    { { -INT8_C( 112),  INT8_C(  65),  INT8_C( 106), -INT8_C(  61),  INT8_C(   9),  INT8_C(  60),  INT8_C( 125),  INT8_C( 111),
         INT8_C(  87),  INT8_C(  20), -INT8_C(  87),  INT8_C(  27),  INT8_C( 124), -INT8_C(   1), -INT8_C( 125),  INT8_C(  95),
         INT8_C(  12),  INT8_C(  58), -INT8_C( 111),  INT8_C(  19), -INT8_C(  93), -INT8_C( 108), -INT8_C(  84),  INT8_C(  85),
         INT8_C(  60),  INT8_C( 125), -INT8_C(  69), -INT8_C(   1),  INT8_C(  73), -INT8_C(  70), -INT8_C(  33), -INT8_C(  39),
        -INT8_C(   5),  INT8_C(  73), -INT8_C( 100),  INT8_C(   4), -INT8_C( 123),  INT8_C(  26),  INT8_C( 116), -INT8_C(  36),
         INT8_C(  46),  INT8_C(  29), -INT8_C(   9), -INT8_C(  85),  INT8_C(  28),  INT8_C( 122),  INT8_C(  10),  INT8_C(  40),
        -INT8_C(  76), -INT8_C( 101),  INT8_C(  59),  INT8_C(  87),  INT8_C(  48), -INT8_C(  25), -INT8_C(  84),  INT8_C( 108),
         INT8_C( 100),  INT8_C( 104),  INT8_C( 108), -INT8_C(  83),  INT8_C(  34),  INT8_C(  75), -INT8_C( 121),  INT8_C(  29) },
      { -INT8_C( 108),  INT8_C(  35),  INT8_C(  33),  INT8_C(  25),  INT8_C(  61), -INT8_C( 107), -INT8_C(  11),  INT8_C( 108),
        -INT8_C(  78), -INT8_C(  20),  INT8_C(  23), -INT8_C(  49),  INT8_C( 102),  INT8_C(  33), -INT8_C(   9),  INT8_C(  26),
        -INT8_C(  68),  INT8_C(  51),  INT8_C( 113), -INT8_C(  20),  INT8_C(  26),  INT8_C(  30),  INT8_C(  89),      INT8_MAX,
        -INT8_C( 122), -INT8_C(  59),  INT8_C(  44), -INT8_C(  88),  INT8_C(  16), -INT8_C(  77), -INT8_C(  59), -INT8_C(  92),
        -INT8_C(  41), -INT8_C(  26), -INT8_C(  67),  INT8_C(  20),  INT8_C( 124), -INT8_C(  78),      INT8_MIN,  INT8_C(  46),
        -INT8_C(  98), -INT8_C( 105), -INT8_C(   3),  INT8_C(   4), -INT8_C(  72), -INT8_C(  11),  INT8_C(  30),  INT8_C( 117),
         INT8_C(  40), -INT8_C( 113),  INT8_C(  97),  INT8_C(  66), -INT8_C(  83), -INT8_C(  70), -INT8_C(  63),  INT8_C(  51),
             INT8_MAX, -INT8_C(  18), -INT8_C(  37), -INT8_C( 113), -INT8_C(  95), -INT8_C(  96),  INT8_C(  51),  INT8_C( 120) },
      { -INT16_C( 13277),  INT16_C(  8373), -INT16_C(  5871),  INT16_C( 10613), -INT16_C(  7186),  INT16_C(  2564),  INT16_C( 21063),  INT16_C(  1291),
         INT16_C(  2142),  INT16_C( 16005),  INT16_C(  8678),  INT16_C( 26103), -INT16_C( 14695), -INT16_C( 14212), -INT16_C( 13154),       INT16_MIN,
        -INT16_C( 12189), -INT16_C( 10372),  INT16_C( 14464), -INT16_C(  4728), -INT16_C(  7553), -INT16_C(    57), -INT16_C(  3358),  INT16_C(  4980),
        -INT16_C( 10315),  INT16_C( 11465), -INT16_C( 20154), -INT16_C(  5328),  INT16_C( 10828), -INT16_C( 23545), -INT16_C( 10430),  INT16_C( 10365) } },
    { { -INT8_C( 121), -INT8_C(  16), -INT8_C( 115),  INT8_C(   3), -INT8_C(  94),  INT8_C(  13),  INT8_C(  49),  INT8_C(  64),
        -INT8_C(  91),  INT8_C(  47),  INT8_C(  68),  INT8_C(  93),  INT8_C(  36),  INT8_C(  98), -INT8_C(  46),  INT8_C(  76),
        -INT8_C(  14),  INT8_C(  52), -INT8_C( 114), -INT8_C(  97), -INT8_C(  18),  INT8_C(  80), -INT8_C(  45),  INT8_C( 110),
         INT8_C(  62), -INT8_C(  82), -INT8_C(   3), -INT8_C(  33),  INT8_C(  79),  INT8_C(  49),  INT8_C(  88), -INT8_C(  42),
         INT8_C(  33), -INT8_C(  27), -INT8_C(  39), -INT8_C(  60), -INT8_C(  14),  INT8_C(  10),  INT8_C(   4), -INT8_C( 105),
         INT8_C(  57),  INT8_C(  73), -INT8_C(  11),  INT8_C(  93), -INT8_C(  85), -INT8_C(  57), -INT8_C(  87), -INT8_C(  99),
        -INT8_C(   5),  INT8_C(  56),  INT8_C(  61), -INT8_C(  22), -INT8_C( 120),  INT8_C(  16),  INT8_C(  88), -INT8_C(  58),
        -INT8_C(  66),  INT8_C(  85), -INT8_C(  91),  INT8_C(  13), -INT8_C( 122), -INT8_C(   3), -INT8_C(  29), -INT8_C(  88) },
      { -INT8_C(  30), -INT8_C(  68),  INT8_C( 108), -INT8_C(  43), -INT8_C(  57),  INT8_C( 112),  INT8_C( 108),  INT8_C(   0),
        -INT8_C(  71),  INT8_C(  97),  INT8_C(  94),  INT8_C( 101),  INT8_C(  41),  INT8_C(   7),  INT8_C(   2),  INT8_C(  36),
         INT8_C(  63),  INT8_C(  63),  INT8_C(  14), -INT8_C(  57),  INT8_C(  79),  INT8_C( 102), -INT8_C( 115),  INT8_C(  14),
        -INT8_C(  68),  INT8_C(  51),  INT8_C(  27),  INT8_C(  66),  INT8_C(  48), -INT8_C(   1), -INT8_C(  22),  INT8_C(  19),
        -INT8_C(  69),  INT8_C(  86), -INT8_C(  24), -INT8_C( 126), -INT8_C(  57),  INT8_C(  84), -INT8_C( 125),      INT8_MIN,
        -INT8_C(  74), -INT8_C(  31), -INT8_C(  27), -INT8_C(  33), -INT8_C(  24), -INT8_C(  24),  INT8_C(   3),  INT8_C(  40),
         INT8_C(  39),  INT8_C(  18), -INT8_C(  17),  INT8_C( 119),  INT8_C( 120),  INT8_C( 125), -INT8_C( 123),  INT8_C(  52),
        -INT8_C(  80), -INT8_C(  96),  INT8_C( 119), -INT8_C(  32), -INT8_C(  97),  INT8_C(  97), -INT8_C(  13),  INT8_C(  91) },
      { -INT16_C( 20370),  INT16_C( 15099), -INT16_C(  7778),  INT16_C(  5292), -INT16_C(  7156),  INT16_C( 15785),  INT16_C(  2162),  INT16_C(  3156),
         INT16_C( 18522), -INT16_C(  7075),  INT16_C( 26962), -INT16_C( 22725),  INT16_C(  4658),  INT16_C( 21549),  INT16_C(  3743),  INT16_C(  2130),
         INT16_C( 17417), -INT16_C( 29904), -INT16_C( 12954), -INT16_C( 19828), -INT16_C(  6481), -INT16_C(  9684), -INT16_C(  8880),  INT16_C(  6787),
         INT16_C( 10797),  INT16_C( 26809),  INT16_C( 18320), -INT16_C(   528), -INT16_C( 23360),  INT16_C( 19219),  INT16_C( 11543),  INT16_C( 12337) } },
    { { -INT8_C(  72), -INT8_C(  37), -INT8_C(  35),      INT8_MAX,  INT8_C(  48),  INT8_C(  96), -INT8_C(   1), -INT8_C(  26),
         INT8_C(  65), -INT8_C(  27), -INT8_C(  59),  INT8_C(  42), -INT8_C(  51), -INT8_C(  56),  INT8_C(  82), -INT8_C(  12),
        -INT8_C(  38),  INT8_C(  65),  INT8_C( 107),  INT8_C(  83), -INT8_C(  66), -INT8_C(  16), -INT8_C( 121),  INT8_C( 110),
        -INT8_C( 111), -INT8_C(   2),  INT8_C(  79),  INT8_C(  48),  INT8_C(  96),  INT8_C(  66), -INT8_C( 117),  INT8_C(  24),
         INT8_C(  30),  INT8_C( 105), -INT8_C( 105),  INT8_C(  78), -INT8_C(  55), -INT8_C( 106),  INT8_C(  52),  INT8_C(  11),
         INT8_C( 123), -INT8_C(   7),  INT8_C(  53),  INT8_C(  72), -INT8_C(  63), -INT8_C( 121),  INT8_C(  61), -INT8_C( 100),
        -INT8_C(  56), -INT8_C(  88), -INT8_C(  17), -INT8_C( 121), -INT8_C( 103),  INT8_C( 118), -INT8_C(  11),  INT8_C(  42),
         INT8_C( 117),  INT8_C(  68),  INT8_C(  90), -INT8_C(  43), -INT8_C( 121), -INT8_C(  26), -INT8_C(  19), -INT8_C(  91) },
      {  INT8_C(  79), -INT8_C( 124), -INT8_C(  13),  INT8_C(  24),  INT8_C(  26),  INT8_C(  39),  INT8_C(  35), -INT8_C( 106),
         INT8_C(  32),  INT8_C(  88), -INT8_C(  34), -INT8_C(  31), -INT8_C(  33),  INT8_C(  27),  INT8_C( 125), -INT8_C(  88),
        -INT8_C(  60),  INT8_C( 108),  INT8_C(  47),  INT8_C(  93), -INT8_C(  29),  INT8_C(  36), -INT8_C( 121),  INT8_C(  88),
         INT8_C( 105), -INT8_C(  31),  INT8_C(  45), -INT8_C(  16), -INT8_C(  57),  INT8_C(  26), -INT8_C( 107),  INT8_C(  22),
        -INT8_C(  98), -INT8_C( 120),  INT8_C(  47), -INT8_C(  72), -INT8_C(  81),  INT8_C(  82),  INT8_C(  78), -INT8_C(  49),
        -INT8_C(  85),  INT8_C(  45), -INT8_C(  80), -INT8_C( 118),  INT8_C(  72),  INT8_C(  46),  INT8_C(  50),  INT8_C(  12),
        -INT8_C( 102),  INT8_C(  97),  INT8_C( 105),  INT8_C( 125), -INT8_C( 122), -INT8_C(  16), -INT8_C(  43), -INT8_C(  17),
        -INT8_C(  46),  INT8_C(   2), -INT8_C(  33), -INT8_C( 103),  INT8_C(  28),  INT8_C( 116), -INT8_C(  80), -INT8_C(  70) },
      { -INT16_C( 12620),  INT16_C(   175),  INT16_C(  4992), -INT16_C( 15455),  INT16_C( 22232), -INT16_C(  8000), -INT16_C(  1365), -INT16_C( 11222),
        -INT16_C(  6060),  INT16_C( 12748),  INT16_C(  3130), -INT16_C(  6655),  INT16_C(  7351),  INT16_C(  2787), -INT16_C(  3756), -INT16_C( 14345),
        -INT16_C( 15540),  INT16_C(  1481), -INT16_C(  3981),  INT16_C(  3517),  INT16_C(   750), -INT16_C( 12736),  INT16_C( 20106),  INT16_C(  4922),
        -INT16_C(  4104),       INT16_MAX, -INT16_C( 20554), -INT16_C( 11249), -INT16_C(  5246), -INT16_C( 24909),  INT16_C( 30460), -INT16_C( 30510) } },
    { { -INT8_C(   4), -INT8_C(  33),  INT8_C( 115), -INT8_C(  85),  INT8_C(  49), -INT8_C(  63),  INT8_C( 122), -INT8_C(  36),
        -INT8_C(  18),  INT8_C(  42),  INT8_C( 103),  INT8_C(  55),  INT8_C(  88), -INT8_C( 103),  INT8_C(  67), -INT8_C(  13),
        -INT8_C(   5), -INT8_C(  83),  INT8_C( 112), -INT8_C( 127), -INT8_C(  99),  INT8_C(  70),  INT8_C( 112),  INT8_C( 111),
         INT8_C(  72),  INT8_C(  79),  INT8_C(   9),  INT8_C( 101), -INT8_C(  61), -INT8_C(  71),  INT8_C(  31), -INT8_C(  65),
        -INT8_C( 104), -INT8_C( 110),  INT8_C( 106), -INT8_C(  55),  INT8_C(  84), -INT8_C(  28), -INT8_C(  90),  INT8_C(  66),
         INT8_C(  14),  INT8_C(  13),  INT8_C( 121),  INT8_C( 103), -INT8_C(  90), -INT8_C(  67),  INT8_C(  90), -INT8_C(  95),
         INT8_C( 106), -INT8_C(  54),  INT8_C(  34),  INT8_C(   7),  INT8_C(  16), -INT8_C( 110),  INT8_C( 119),  INT8_C(  89),
        -INT8_C(  31),      INT8_MIN, -INT8_C(  66), -INT8_C(  92),  INT8_C(  57), -INT8_C(  35),  INT8_C(  99), -INT8_C(  47) },
      {  INT8_C( 112), -INT8_C(  51), -INT8_C( 102), -INT8_C(  60), -INT8_C(  79),  INT8_C(  64),  INT8_C(   6), -INT8_C(  64),
         INT8_C(  77),      INT8_MIN,  INT8_C(  39), -INT8_C(  12),  INT8_C(  61), -INT8_C( 127), -INT8_C( 107), -INT8_C(  89),
         INT8_C(  75), -INT8_C(  72), -INT8_C(  82),  INT8_C(  92),  INT8_C(  74),  INT8_C(  37), -INT8_C(  75),  INT8_C(  44),
        -INT8_C(  91),  INT8_C( 115), -INT8_C(  48), -INT8_C(  34),  INT8_C(  80),  INT8_C(  52), -INT8_C(  81), -INT8_C(  64),
         INT8_C(   1),  INT8_C(  74), -INT8_C( 124), -INT8_C(  77), -INT8_C( 118), -INT8_C( 117),  INT8_C( 115), -INT8_C(  40),
         INT8_C(  11), -INT8_C( 102), -INT8_C(  52),  INT8_C(  72),  INT8_C(  27),  INT8_C(  97), -INT8_C(  17),  INT8_C( 102),
         INT8_C(  25), -INT8_C(  99), -INT8_C(  62),  INT8_C( 100), -INT8_C(  61),  INT8_C( 119), -INT8_C( 112),  INT8_C( 104),
        -INT8_C(  22),  INT8_C(  96),  INT8_C(  71),  INT8_C(  59), -INT8_C( 108), -INT8_C(  10), -INT8_C(   5), -INT8_C( 106) },
      {  INT16_C( 16851), -INT16_C( 21990),  INT16_C(  8481), -INT16_C( 13348),  INT16_C( 12950),  INT16_C(  3357), -INT16_C( 14063), -INT16_C( 28796),
         INT16_C(  6369),  INT16_C(  2684),  INT16_C( 14208), -INT16_C(  3516),  INT16_C(  2533), -INT16_C(  3866),  INT16_C( 25220), -INT16_C( 14735),
         INT16_C( 10956), -INT16_C( 28621),       INT16_MIN,  INT16_C( 16450), -INT16_C(  1172),  INT16_C(  1124),  INT16_C( 22815),  INT16_C( 14892),
        -INT16_C( 17348), -INT16_C(  1408),  INT16_C( 16398), -INT16_C(  4072),  INT16_C(  7338),  INT16_C( 23166), -INT16_C(  8366), -INT16_C( 22649) } },
    { {  INT8_C(  64),      INT8_MIN,  INT8_C(  73), -INT8_C(  53),  INT8_C(  11), -INT8_C(  68), -INT8_C(  93),  INT8_C(  22),
         INT8_C(  86),  INT8_C( 111),  INT8_C(  94),  INT8_C( 113), -INT8_C(  48),  INT8_C(  77), -INT8_C(  41), -INT8_C(  22),
        -INT8_C(  22), -INT8_C( 102),  INT8_C(  78), -INT8_C(  83),  INT8_C(  17), -INT8_C(  34),  INT8_C(  22), -INT8_C(   4),
         INT8_C(  62),  INT8_C(  93),  INT8_C(  55), -INT8_C(  45),  INT8_C(  83),  INT8_C(  50),  INT8_C( 105), -INT8_C( 108),
        -INT8_C(  78), -INT8_C(  78),  INT8_C(  95), -INT8_C(  67),  INT8_C( 110),  INT8_C(   2), -INT8_C(  45), -INT8_C(  60),
         INT8_C( 113),  INT8_C(  49),  INT8_C(  53),  INT8_C(  65),  INT8_C( 126),  INT8_C(  12),  INT8_C(  43),  INT8_C( 105),
        -INT8_C(  90),  INT8_C( 121),  INT8_C(  22), -INT8_C(  72),  INT8_C(  87),  INT8_C(  44), -INT8_C(  76), -INT8_C( 106),
        -INT8_C( 119), -INT8_C(  21),  INT8_C( 105), -INT8_C(  35),  INT8_C(  29), -INT8_C(  46),  INT8_C( 113), -INT8_C(  48) },
      { -INT8_C( 124), -INT8_C(  48), -INT8_C( 115), -INT8_C(  14), -INT8_C(  46),  INT8_C(  97), -INT8_C(  74),  INT8_C(  67),
        -INT8_C( 110), -INT8_C(  21), -INT8_C( 124),  INT8_C(  17), -INT8_C(   9), -INT8_C(  80),  INT8_C( 122), -INT8_C(  98),
         INT8_C(  41), -INT8_C( 112),  INT8_C(  86), -INT8_C( 127), -INT8_C(  67),  INT8_C(  10),  INT8_C(  23),  INT8_C(  70),
        -INT8_C(  11),      INT8_MIN,  INT8_C(  35),  INT8_C(  18),  INT8_C(  82), -INT8_C( 108), -INT8_C(  30), -INT8_C(  42),
         INT8_C( 100),  INT8_C( 112), -INT8_C(  56),  INT8_C(  54), -INT8_C(  47),  INT8_C( 126),  INT8_C( 121),  INT8_C(  99),
         INT8_C( 105), -INT8_C(   2),  INT8_C( 116),  INT8_C(  96), -INT8_C(  82), -INT8_C(  18), -INT8_C(   2), -INT8_C(  41),
             INT8_MAX,  INT8_C(  84),  INT8_C(  88),  INT8_C(  60),  INT8_C(  94),  INT8_C( 111), -INT8_C( 126),  INT8_C(  83),
        -INT8_C(  17), -INT8_C(  90),  INT8_C( 102),  INT8_C(  65),  INT8_C(  58),  INT8_C(  72),  INT8_C(  23), -INT8_C(  97) },
      { -INT16_C( 14080), -INT16_C( 11237),  INT16_C( 17730), -INT16_C( 10588), -INT16_C( 11791), -INT16_C(  9735), -INT16_C(  8032),  INT16_C(  3298),
        -INT16_C(  7654), -INT16_C( 15263),  INT16_C(  1081),  INT16_C( 18146), -INT16_C( 12586),  INT16_C(  5723),  INT16_C(  1406), -INT16_C(  9366),
              INT16_MAX,  INT16_C(  4886), -INT16_C(  4918),       INT16_MAX,  INT16_C( 11767),  INT16_C( 12388), -INT16_C( 10548), -INT16_C(  4391),
         INT16_C( 31246),  INT16_C( 12976),  INT16_C( 13062), -INT16_C( 10230), -INT16_C( 23479),  INT16_C( 25075),  INT16_C( 16802), -INT16_C( 17577) } },
    { { -INT8_C(  72), -INT8_C(  33), -INT8_C(  43), -INT8_C( 119),  INT8_C(  93),  INT8_C(  79), -INT8_C(  19), -INT8_C(  58),
         INT8_C(  77),  INT8_C(  97),  INT8_C(  39), -INT8_C(   5),  INT8_C(  80),  INT8_C(  37), -INT8_C(  46), -INT8_C(  49),
         INT8_C( 122),  INT8_C(  43),  INT8_C(  11), -INT8_C(  40), -INT8_C( 102), -INT8_C( 115),  INT8_C(  44), -INT8_C( 118),
         INT8_C(  51), -INT8_C( 110), -INT8_C(  53),  INT8_C( 110), -INT8_C(  38), -INT8_C(  29),  INT8_C(  13), -INT8_C( 109),
        -INT8_C(  62), -INT8_C(  30),  INT8_C(  28),  INT8_C(  32),  INT8_C(  49),  INT8_C(   9), -INT8_C(  26),  INT8_C( 126),
         INT8_C( 107),  INT8_C(  13),  INT8_C( 121), -INT8_C(  69),  INT8_C(  51),  INT8_C(  76), -INT8_C( 118), -INT8_C(  83),
         INT8_C( 119), -INT8_C( 107), -INT8_C( 123),  INT8_C(  17),  INT8_C(  34), -INT8_C(  79), -INT8_C( 101),  INT8_C(  86),
         INT8_C(  67),  INT8_C( 103), -INT8_C(  60),  INT8_C(  30),  INT8_C(  74), -INT8_C(  47), -INT8_C(  79),  INT8_C(  12) },
      { -INT8_C(  77), -INT8_C(  51),  INT8_C(  44), -INT8_C(  27), -INT8_C(  41),  INT8_C(  19),  INT8_C(  99),  INT8_C(  66),
         INT8_C(  32), -INT8_C(  35), -INT8_C(   3),  INT8_C(  83),  INT8_C(  41), -INT8_C( 121),  INT8_C(   0), -INT8_C(  96),
         INT8_C(  28), -INT8_C( 122), -INT8_C(  79),  INT8_C(  62),  INT8_C(  55),  INT8_C(  77), -INT8_C( 108),  INT8_C( 123),
        -INT8_C(  76),  INT8_C(  88), -INT8_C( 103), -INT8_C(   2),  INT8_C(  41),  INT8_C(  74),  INT8_C(  10), -INT8_C(  35),
         INT8_C(  23),  INT8_C(  55), -INT8_C(  62), -INT8_C(  18),  INT8_C(  74),  INT8_C(  37),  INT8_C(  48),  INT8_C( 106),
         INT8_C(   2),  INT8_C(  45), -INT8_C(  66),  INT8_C(  43), -INT8_C(  76), -INT8_C(  66), -INT8_C(  53), -INT8_C(  48),
         INT8_C(  68),  INT8_C( 125),  INT8_C(  15),  INT8_C( 124), -INT8_C(  54), -INT8_C(  93), -INT8_C(   9),  INT8_C( 126),
        -INT8_C(   4), -INT8_C( 112),  INT8_C( 124),  INT8_C(  37), -INT8_C(  38), -INT8_C( 122),  INT8_C(   2), -INT8_C(  15) },
      { -INT16_C( 25541),  INT16_C(  5673), -INT16_C(  2312),       INT16_MAX, -INT16_C(   931),  INT16_C( 20716), -INT16_C(  1197), -INT16_C( 19872),
        -INT16_C(  1830),  INT16_C( 12523),  INT16_C( 19327),  INT16_C( 12222),  INT16_C(  8972), -INT16_C( 21129),  INT16_C( 25736), -INT16_C(  5015),
         INT16_C( 16892), -INT16_C(  2312),  INT16_C(  3959),  INT16_C( 24396),  INT16_C(   799),  INT16_C(    55), -INT16_C(  8892), -INT16_C( 15618),
         INT16_C( 26717),  INT16_C(  4103), -INT16_C( 18297),  INT16_C(  9441), -INT16_C( 11804),  INT16_C( 25414), -INT16_C( 28310),  INT16_C(   174) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i a = simde_mm512_loadu_epi8(test_vec[i].a);
    simde__m512i b = simde_mm512_loadu_epi8(test_vec[i].b);
    simde__m512i r = simde_mm512_maddubs_epi16(a, b);
    simde_test_x86_assert_equal_i16x32(r, simde_mm512_loadu_epi16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m512i a = simde_test_x86_random_i8x64();
    simde__m512i b = simde_test_x86_random_i8x64();
    simde__m512i r = simde_mm512_maddubs_epi16(a, b);

    simde_test_x86_write_i8x64(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i8x64(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_mask_maddubs_epi16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int16_t src[32];
    const simde__mmask32 k;
    const int8_t a[64];
    const int8_t b[64];
    const int16_t r[32];
  } test_vec[] = {
    { { -INT16_C( 15171),  INT16_C(  2016),  INT16_C(  4330), -INT16_C(  5006),  INT16_C( 12350), -INT16_C(  3560), -INT16_C(  7186),  INT16_C( 13251),
        -INT16_C( 11680),  INT16_C( 10927), -INT16_C( 22923),  INT16_C( 29096),  INT16_C(  9270),  INT16_C(  4247), -INT16_C( 26197),  INT16_C( 26625),
        -INT16_C(  7842),  INT16_C( 18544), -INT16_C(  7438),  INT16_C( 12340),  INT16_C( 19474),  INT16_C(    34), -INT16_C(  6864), -INT16_C( 28621),
        -INT16_C(  7497),  INT16_C( 11707),  INT16_C( 25480), -INT16_C( 16738),  INT16_C( 13704),  INT16_C( 13262), -INT16_C( 12081),  INT16_C( 11675) },
      UINT32_C(2742356913),
      { -INT8_C(  19), -INT8_C(  87), -INT8_C(  45), -INT8_C(   1), -INT8_C(  10), -INT8_C(  10),  INT8_C(   0),  INT8_C(  38),
        -INT8_C(  37),  INT8_C(  51), -INT8_C(  74), -INT8_C( 109),  INT8_C(  22),  INT8_C( 113), -INT8_C(  64), -INT8_C(  98),
        -INT8_C(  43),  INT8_C(  94),  INT8_C(  93),  INT8_C(  93), -INT8_C( 108),  INT8_C(  43), -INT8_C( 112),  INT8_C(  99),
        -INT8_C(   5),  INT8_C(  43), -INT8_C( 112), -INT8_C(  83),  INT8_C(  55),  INT8_C(   5),  INT8_C(  80),  INT8_C(  36),
        -INT8_C(  82),  INT8_C(  36),  INT8_C(  36), -INT8_C(  92),  INT8_C(  26),  INT8_C(  36), -INT8_C(  54), -INT8_C(  11),
         INT8_C(  87), -INT8_C( 127), -INT8_C( 120),  INT8_C( 109), -INT8_C(  14),  INT8_C(  72),  INT8_C(  12), -INT8_C(  57),
        -INT8_C(  89),  INT8_C( 105),  INT8_C(  36),  INT8_C(  59), -INT8_C( 108), -INT8_C(  76), -INT8_C(  98), -INT8_C( 112),
        -INT8_C(  32),  INT8_C(  46),  INT8_C(  61),  INT8_C(  23),  INT8_C(  51), -INT8_C( 115),  INT8_C(  59), -INT8_C(  31) },
      { -INT8_C(  79),  INT8_C(  95), -INT8_C( 122), -INT8_C(  53), -INT8_C( 125),  INT8_C(  80), -INT8_C(  63), -INT8_C(  37),
        -INT8_C(  47),  INT8_C(  73),  INT8_C(  72), -INT8_C(  60), -INT8_C( 110),  INT8_C(  84), -INT8_C( 117),  INT8_C(  57),
        -INT8_C(  67), -INT8_C(  80),  INT8_C( 116),  INT8_C(  82),  INT8_C( 100),  INT8_C(  18), -INT8_C(  30),  INT8_C(  68),
         INT8_C(  64),  INT8_C(  31),  INT8_C(  91),  INT8_C( 115), -INT8_C(  84), -INT8_C( 105),  INT8_C(  84),  INT8_C(  94),
        -INT8_C(  10), -INT8_C(  38),  INT8_C(  41),  INT8_C( 122),  INT8_C(  43), -INT8_C(  22),  INT8_C(  85), -INT8_C(   4),
         INT8_C(  52), -INT8_C(  99), -INT8_C(  64), -INT8_C(  58), -INT8_C(  14),  INT8_C(  76), -INT8_C(   1), -INT8_C(  81),
        -INT8_C(   4),  INT8_C( 115),  INT8_C(   1),  INT8_C(  96), -INT8_C( 123), -INT8_C(  29), -INT8_C(  91), -INT8_C(  59),
         INT8_C(   2),  INT8_C(   0),  INT8_C(  56), -INT8_C(  81), -INT8_C( 105), -INT8_C( 116),  INT8_C(  13), -INT8_C( 114) },
      { -INT16_C(  2668),  INT16_C(  2016),  INT16_C(  4330), -INT16_C(  5006), -INT16_C(  6570),  INT16_C(  4284), -INT16_C(  7186), -INT16_C( 13458),
        -INT16_C( 21791),  INT16_C( 18414), -INT16_C( 22923),  INT16_C(  2412),  INT16_C(  9270),  INT16_C(  4247), -INT16_C( 26197),  INT16_C( 26625),
        -INT16_C(  3108),  INT16_C( 18544),  INT16_C(   326),  INT16_C( 12340), -INT16_C(  8247), -INT16_C( 15026),  INT16_C(  2084), -INT16_C( 28621),
         INT16_C( 11407),  INT16_C(  5700),  INT16_C( 25480), -INT16_C( 16738),  INT16_C( 13704),  INT16_C(  1553), -INT16_C( 12081), -INT16_C( 24883) } },
    { {  INT16_C( 13927), -INT16_C( 28152),  INT16_C( 23841),  INT16_C( 21902),  INT16_C( 20474), -INT16_C(  5093),  INT16_C(  6811), -INT16_C( 26724),
        -INT16_C( 25203),  INT16_C(  4855), -INT16_C( 25471), -INT16_C( 31785),  INT16_C(  3997),  INT16_C( 13362),  INT16_C( 16283),  INT16_C(   706),
        -INT16_C( 13706), -INT16_C( 26732),  INT16_C(  8999),  INT16_C(  8940),  INT16_C(  1906),  INT16_C(  3342), -INT16_C( 21983), -INT16_C( 20828),
        -INT16_C( 25784), -INT16_C( 13888), -INT16_C( 26824), -INT16_C( 10932),  INT16_C( 32678),  INT16_C( 16649), -INT16_C( 13122),  INT16_C( 13380) },
      UINT32_C(3201030294),
      { -INT8_C(   5), -INT8_C(  73), -INT8_C(  32),  INT8_C( 109), -INT8_C(  66), -INT8_C(  18),  INT8_C( 122), -INT8_C(  33),
        -INT8_C( 103),  INT8_C(  30), -INT8_C( 115), -INT8_C(  31), -INT8_C(  70),  INT8_C(  77), -INT8_C(  86), -INT8_C(  14),
        -INT8_C(  28), -INT8_C(  10), -INT8_C(  57), -INT8_C( 118),  INT8_C( 117), -INT8_C(  48), -INT8_C(  52),  INT8_C(  52),
        -INT8_C( 100),  INT8_C(  16),  INT8_C( 104),  INT8_C(  51), -INT8_C(  24),  INT8_C(  52), -INT8_C(  15), -INT8_C(  28),
        -INT8_C(  21), -INT8_C(  47),  INT8_C(  81), -INT8_C(  86), -INT8_C(  65), -INT8_C(  52), -INT8_C( 119),  INT8_C(  88),
        -INT8_C(  22),  INT8_C(  23),  INT8_C(  57), -INT8_C(  92),  INT8_C( 100), -INT8_C(  29), -INT8_C( 106),  INT8_C(  73),
        -INT8_C(  38),  INT8_C(  93), -INT8_C(  45),  INT8_C(  79),  INT8_C(  46), -INT8_C(  97), -INT8_C( 125), -INT8_C(  54),
        -INT8_C(  81), -INT8_C(  20), -INT8_C(   3), -INT8_C( 104),  INT8_C(  32), -INT8_C(  18),  INT8_C( 124),  INT8_C(  11) },
      { -INT8_C(  65), -INT8_C(  51), -INT8_C(  75),      INT8_MAX, -INT8_C( 103),  INT8_C(  63), -INT8_C(  41), -INT8_C( 124),
         INT8_C(  86),  INT8_C(  17),  INT8_C(  40), -INT8_C(  70), -INT8_C(  12), -INT8_C(  65),  INT8_C(   3), -INT8_C(  50),
         INT8_C(  28), -INT8_C(  41),  INT8_C(  30),  INT8_C(  74),  INT8_C( 118), -INT8_C(  95),  INT8_C(  21),  INT8_C(  38),
        -INT8_C( 115),  INT8_C(  18), -INT8_C(  66), -INT8_C(  83),  INT8_C(   1),  INT8_C(  58), -INT8_C(  71), -INT8_C(  64),
         INT8_C(   7),  INT8_C( 110),  INT8_C(  63), -INT8_C(  95), -INT8_C(  83),  INT8_C(  23),  INT8_C(  37),  INT8_C(   3),
         INT8_C(  40),  INT8_C(  77), -INT8_C(  66),  INT8_C(  28),  INT8_C(  12), -INT8_C(  63), -INT8_C(  21),  INT8_C(  41),
        -INT8_C( 104),  INT8_C(   9),  INT8_C( 115),  INT8_C(  15), -INT8_C(  86), -INT8_C( 120),  INT8_C(  53),  INT8_C(  56),
        -INT8_C( 101), -INT8_C(  13), -INT8_C(  27), -INT8_C( 100),  INT8_C(  45), -INT8_C(  98),  INT8_C(  92),  INT8_C(  52) },
      {  INT16_C( 13927), -INT16_C(  2957), -INT16_C(  4576),  INT16_C( 21902),  INT16_C( 13668), -INT16_C(  5093),  INT16_C(  6811), -INT16_C( 11590),
        -INT16_C( 25203),  INT16_C(  4855), -INT16_C( 25471),  INT16_C(  6260), -INT16_C( 17652),  INT16_C( 13362),  INT16_C(  3248), -INT16_C( 31703),
         INT16_C( 24635), -INT16_C( 11047),  INT16_C(  8999),  INT16_C(  5333),  INT16_C(  1906),  INT16_C(  3342), -INT16_C( 13101), -INT16_C(   157),
        -INT16_C( 25784),  INT16_C( 25450), -INT16_C( 23036),  INT16_C( 18255), -INT16_C( 20743), -INT16_C( 22031), -INT16_C( 13122),  INT16_C( 11980) } },
    { { -INT16_C( 25587), -INT16_C( 17707), -INT16_C(  1357), -INT16_C(  9282),  INT16_C( 31816),  INT16_C( 21751), -INT16_C(  7619), -INT16_C( 10627),
        -INT16_C(  3605), -INT16_C( 26907),  INT16_C(  6777),  INT16_C(  5326), -INT16_C( 19699),  INT16_C( 15024),  INT16_C(  3410),  INT16_C( 24430),
         INT16_C( 17577),  INT16_C( 23577), -INT16_C( 10434), -INT16_C( 31177),  INT16_C( 11859), -INT16_C( 28197),  INT16_C( 22545), -INT16_C(   921),
         INT16_C( 19529), -INT16_C( 15470),  INT16_C( 24678),  INT16_C( 29655), -INT16_C( 30700),  INT16_C( 26285),  INT16_C(  7061),  INT16_C( 16069) },
      UINT32_C(2660949599),
      { -INT8_C(  74), -INT8_C(  47),  INT8_C(  36),  INT8_C(   9), -INT8_C(   1), -INT8_C(   1), -INT8_C( 102),  INT8_C(  16),
         INT8_C(  88),  INT8_C(   1),  INT8_C(  13), -INT8_C(  95),  INT8_C(  77), -INT8_C(  97),  INT8_C( 100), -INT8_C(  77),
         INT8_C(   0),  INT8_C(  60),  INT8_C(  38),  INT8_C(  20), -INT8_C(  60), -INT8_C(  45),  INT8_C( 122),  INT8_C(  89),
        -INT8_C(  17),  INT8_C(  63), -INT8_C( 105),  INT8_C(  78),  INT8_C(  29),  INT8_C(  49), -INT8_C(  20), -INT8_C(  45),
         INT8_C(   2),  INT8_C(  17), -INT8_C(  35),  INT8_C(   1),  INT8_C(  16),  INT8_C( 119),  INT8_C(  18),  INT8_C( 104),
         INT8_C( 121),  INT8_C(  31),  INT8_C(  10), -INT8_C(  58), -INT8_C(  66),  INT8_C( 110),  INT8_C( 122), -INT8_C(  66),
        -INT8_C(  86), -INT8_C(  96), -INT8_C(  46),  INT8_C( 110),  INT8_C( 116),  INT8_C(  76), -INT8_C(  57),  INT8_C(  99),
        -INT8_C( 117),  INT8_C(  94), -INT8_C(  79), -INT8_C(  87), -INT8_C( 113), -INT8_C(  98),  INT8_C( 124), -INT8_C( 111) },
      { -INT8_C(  81),  INT8_C(  89), -INT8_C( 109), -INT8_C(  65), -INT8_C(  47), -INT8_C(  91),  INT8_C(  40),  INT8_C(  74),
        -INT8_C(  60),  INT8_C(  50),  INT8_C(  16), -INT8_C( 126), -INT8_C(  96), -INT8_C( 118),  INT8_C(  65),  INT8_C(  75),
         INT8_C(  43),  INT8_C(  19), -INT8_C(  71), -INT8_C(  97),  INT8_C(  96), -INT8_C( 127),  INT8_C(   2), -INT8_C(  21),
        -INT8_C(  33), -INT8_C(  77), -INT8_C( 108),  INT8_C( 111),  INT8_C(  81),  INT8_C(  17),  INT8_C(   0),  INT8_C(   0),
         INT8_C( 106), -INT8_C( 109), -INT8_C(  64),  INT8_C(  59),  INT8_C(  56), -INT8_C(  24), -INT8_C( 123), -INT8_C(   4),
         INT8_C(  26), -INT8_C( 106),      INT8_MAX, -INT8_C(  70),  INT8_C(  32), -INT8_C(  64),  INT8_C(   5),  INT8_C(  75),
        -INT8_C(  45), -INT8_C(  65), -INT8_C(  22),  INT8_C(  51),  INT8_C(  64), -INT8_C(  20),  INT8_C(  31),  INT8_C(  31),
        -INT8_C(  96), -INT8_C(  77), -INT8_C( 114), -INT8_C(  15), -INT8_C(  60), -INT8_C( 113), -INT8_C(  14),  INT8_C(  47) },
      {  INT16_C(  3859), -INT16_C(  4509),       INT16_MIN,  INT16_C(  7344), -INT16_C(  5230),  INT16_C( 21751), -INT16_C( 26154), -INT16_C( 10627),
        -INT16_C(  3605), -INT16_C(  4638), -INT16_C(  7981), -INT16_C(  1625), -INT16_C( 12738),  INT16_C( 15024),  INT16_C(  3182),  INT16_C(     0),
         INT16_C( 17577), -INT16_C( 14085), -INT16_C( 10434), -INT16_C(  2630), -INT16_C(   140), -INT16_C( 28197),  INT16_C( 22545),  INT16_C( 14860),
         INT16_C( 19529),  INT16_C(   990),  INT16_C(  5904),  INT16_C(  9238), -INT16_C( 20582),  INT16_C( 26285),  INT16_C(  7061),  INT16_C(  5079) } },
    { { -INT16_C( 19934),  INT16_C( 23402), -INT16_C(  3942), -INT16_C( 19369), -INT16_C( 10618), -INT16_C( 22930),  INT16_C( 29846),  INT16_C( 27378),
        -INT16_C(  9165),  INT16_C( 29597), -INT16_C( 17207),  INT16_C( 27026),  INT16_C(  8560),  INT16_C( 13402),  INT16_C( 19632), -INT16_C( 11677),
        -INT16_C( 12546), -INT16_C( 26579), -INT16_C( 31298),  INT16_C( 17484), -INT16_C( 17573), -INT16_C(  3350), -INT16_C(  9169),  INT16_C( 25180),
        -INT16_C(  1607), -INT16_C( 32043),  INT16_C( 26550),  INT16_C(  9963),  INT16_C( 17800),  INT16_C( 14426), -INT16_C( 16750), -INT16_C( 28661) },
      UINT32_C(1244215436),
      { -INT8_C(  67),  INT8_C( 117), -INT8_C( 114),  INT8_C(  25),  INT8_C(  48),  INT8_C( 120),  INT8_C(  11),  INT8_C(  95),
         INT8_C(  85),  INT8_C( 103), -INT8_C(  63),  INT8_C(  14),  INT8_C(  96), -INT8_C( 106), -INT8_C( 112),  INT8_C(  22),
        -INT8_C(   2),  INT8_C( 123),  INT8_C(  60), -INT8_C( 122), -INT8_C(  64), -INT8_C( 105), -INT8_C(  65),  INT8_C(  82),
         INT8_C(  85), -INT8_C(  54), -INT8_C(  29), -INT8_C(  31),  INT8_C(   2),  INT8_C(  12),  INT8_C(  43), -INT8_C(  64),
        -INT8_C( 127), -INT8_C(  71), -INT8_C(  39), -INT8_C(  78),  INT8_C(  49), -INT8_C(  28),  INT8_C(  17), -INT8_C( 122),
         INT8_C(  75), -INT8_C(  45), -INT8_C( 108), -INT8_C(  85),  INT8_C( 105),  INT8_C(  36), -INT8_C(  62),  INT8_C( 103),
        -INT8_C(  97), -INT8_C(   2), -INT8_C(  18),  INT8_C(  96), -INT8_C( 107), -INT8_C(  83), -INT8_C(  78), -INT8_C(  22),
         INT8_C( 119), -INT8_C( 107), -INT8_C(  53),  INT8_C( 121), -INT8_C(  95), -INT8_C(  10),  INT8_C(  57),  INT8_C(  35) },
      { -INT8_C(  81),  INT8_C(  18), -INT8_C(  43), -INT8_C(  31), -INT8_C(  10), -INT8_C(  26),  INT8_C( 103),  INT8_C(  65),
        -INT8_C(  71), -INT8_C(   4), -INT8_C(  19),  INT8_C(  35),  INT8_C(  32), -INT8_C(  81), -INT8_C( 118), -INT8_C(  64),
        -INT8_C(  83),  INT8_C( 120),  INT8_C(  32),  INT8_C(  67),  INT8_C(  37), -INT8_C(  46),  INT8_C(  45), -INT8_C( 100),
         INT8_C( 104), -INT8_C(   7),  INT8_C(  22),  INT8_C(   9), -INT8_C(  17),  INT8_C(  79),  INT8_C(  44), -INT8_C(  97),
         INT8_C(  98),  INT8_C(   1),      INT8_MIN,  INT8_C(  88), -INT8_C(  24), -INT8_C(  25), -INT8_C( 102), -INT8_C(  95),
        -INT8_C(  29), -INT8_C( 121), -INT8_C(  60),  INT8_C(   4),  INT8_C(  54),  INT8_C(  79), -INT8_C(  60), -INT8_C(  29),
        -INT8_C(  57), -INT8_C(  28),  INT8_C(  38), -INT8_C(  19), -INT8_C(  74),  INT8_C(  84), -INT8_C( 119),  INT8_C(  30),
         INT8_C(  77), -INT8_C(  97),  INT8_C(  40),  INT8_C(  60), -INT8_C(  17),  INT8_C(  84), -INT8_C(  37),  INT8_C(  81) },
      { -INT16_C( 19934),  INT16_C( 23402), -INT16_C(  3600),  INT16_C(  7308), -INT16_C( 10618), -INT16_C( 22930),  INT16_C( 29846), -INT16_C( 18400),
        -INT16_C(  9165),  INT16_C( 29597), -INT16_C( 17207),  INT16_C(   395),  INT16_C(  7426),  INT16_C(  7019),  INT16_C( 19632), -INT16_C( 11677),
         INT16_C( 12827), -INT16_C( 26579), -INT16_C( 31298), -INT16_C( 14464), -INT16_C( 17573), -INT16_C(  8196), -INT16_C(  9169),  INT16_C( 25180),
        -INT16_C(  1607),  INT16_C(  7220),  INT16_C( 26550), -INT16_C( 14162),  INT16_C( 17800),  INT16_C( 14426),  INT16_C( 17927), -INT16_C( 28661) } },
    { {  INT16_C( 23382),  INT16_C( 16041),  INT16_C( 17219),  INT16_C(  9951), -INT16_C( 23350),  INT16_C(    42), -INT16_C(  4365), -INT16_C( 17692),
         INT16_C(  2770), -INT16_C( 30297),  INT16_C( 12638), -INT16_C( 21593), -INT16_C( 12336), -INT16_C( 16408), -INT16_C( 15580),  INT16_C( 31248),
        -INT16_C( 17889),  INT16_C( 25272), -INT16_C( 26627), -INT16_C( 14200), -INT16_C( 19653),  INT16_C( 11976), -INT16_C( 21343),  INT16_C( 29929),
        -INT16_C( 28489),  INT16_C(  5629), -INT16_C( 23359), -INT16_C( 27967), -INT16_C( 22156), -INT16_C( 26543),  INT16_C( 25196), -INT16_C( 29934) },
      UINT32_C( 435014172),
      {  INT8_C(  97),  INT8_C( 118), -INT8_C(  31), -INT8_C(  99),  INT8_C(  41), -INT8_C(  86), -INT8_C(  53), -INT8_C(  54),
         INT8_C(  86), -INT8_C(  76),  INT8_C(  62),  INT8_C(  13),  INT8_C(  69),  INT8_C(  59),  INT8_C(  35),  INT8_C(   6),
        -INT8_C(  32), -INT8_C(  28), -INT8_C( 104),  INT8_C(  84), -INT8_C( 115), -INT8_C(  22), -INT8_C(  20), -INT8_C(   7),
         INT8_C(  76), -INT8_C(   2), -INT8_C( 123),  INT8_C( 104), -INT8_C(  56),  INT8_C( 114), -INT8_C( 127),  INT8_C(  41),
        -INT8_C(  24),  INT8_C(  99), -INT8_C(  58),  INT8_C(  17),  INT8_C(  13), -INT8_C( 110), -INT8_C(  36),  INT8_C(  99),
         INT8_C(  70),  INT8_C(  26),  INT8_C( 113), -INT8_C( 117),  INT8_C(  86), -INT8_C( 108), -INT8_C( 110),  INT8_C(  54),
         INT8_C( 120),  INT8_C(  42), -INT8_C( 118),  INT8_C(   5),  INT8_C(  20),  INT8_C( 118), -INT8_C(   2),  INT8_C(  96),
         INT8_C( 116), -INT8_C( 125), -INT8_C(  56),  INT8_C(  60), -INT8_C(  10),  INT8_C(  74),  INT8_C( 101), -INT8_C(  34) },
      { -INT8_C(  83),  INT8_C(  44), -INT8_C(  16), -INT8_C(  70), -INT8_C(  66), -INT8_C(  52),  INT8_C(  29),  INT8_C(   4),
        -INT8_C(  26), -INT8_C( 114), -INT8_C( 112),  INT8_C(  60),  INT8_C(  34),  INT8_C(  34),  INT8_C( 114), -INT8_C( 102),
         INT8_C(  76), -INT8_C(   4), -INT8_C(  97),  INT8_C(  97),  INT8_C( 114), -INT8_C(  98), -INT8_C(  63), -INT8_C(  26),
         INT8_C(  33), -INT8_C( 118),  INT8_C(  34),  INT8_C(  23), -INT8_C(  44), -INT8_C( 120), -INT8_C(  10), -INT8_C( 127),
        -INT8_C(  76), -INT8_C(  26),  INT8_C(  59),  INT8_C( 114), -INT8_C(  78),  INT8_C(  88),  INT8_C( 118), -INT8_C( 104),
        -INT8_C(  25),  INT8_C(   6), -INT8_C(  43),  INT8_C(   9),  INT8_C(  40),  INT8_C(  71), -INT8_C(  92),  INT8_C( 117),
         INT8_C(  68),  INT8_C(  67), -INT8_C(  42), -INT8_C(  74), -INT8_C(  31), -INT8_C( 105), -INT8_C(  99),  INT8_C(   3),
         INT8_C(  33), -INT8_C(  65),  INT8_C(  26), -INT8_C(  11),  INT8_C(  71),  INT8_C(  16),  INT8_C( 118), -INT8_C(   5) },
      {  INT16_C( 23382),  INT16_C( 16041), -INT16_C( 11546),  INT16_C(  6695), -INT16_C( 22756),  INT16_C(    42), -INT16_C(  4365), -INT16_C( 17692),
         INT16_C(  2770), -INT16_C(  6596),  INT16_C( 12638), -INT16_C( 21342), -INT16_C( 12336), -INT16_C( 16408), -INT16_C( 22480), -INT16_C(  6497),
        -INT16_C( 20206),  INT16_C( 25272),  INT16_C( 11834),  INT16_C( 15664), -INT16_C( 19653), -INT16_C(  3608),  INT16_C( 13948), -INT16_C(  7114),
         INT16_C( 10974),  INT16_C(  5629), -INT16_C( 23359), -INT16_C( 24858), -INT16_C(  4687), -INT16_C( 26543),  INT16_C( 25196), -INT16_C( 29934) } },
    { { -INT16_C( 19978), -INT16_C( 22419), -INT16_C(  7158), -INT16_C(  3775),  INT16_C(  5866),  INT16_C(  5114), -INT16_C( 24995), -INT16_C( 24184),
         INT16_C( 24290), -INT16_C( 15528), -INT16_C(  2571),  INT16_C(  6086), -INT16_C(  7756), -INT16_C(  1012), -INT16_C( 31759), -INT16_C(  5897),
         INT16_C( 25908),  INT16_C( 16016), -INT16_C( 11959),  INT16_C( 13103),  INT16_C( 10983),  INT16_C( 17734), -INT16_C( 12600), -INT16_C( 21786),
         INT16_C( 15916),  INT16_C(  8814),  INT16_C( 13363), -INT16_C(  6087),  INT16_C( 17685),  INT16_C(  2020), -INT16_C(  9272), -INT16_C(   529) },
      UINT32_C(2302377792),
      {  INT8_C(  81),  INT8_C( 107), -INT8_C(  67),  INT8_C(  56), -INT8_C( 107),  INT8_C(   3),  INT8_C( 125),  INT8_C(  93),
        -INT8_C(  46),  INT8_C( 100),  INT8_C(   8), -INT8_C(   2), -INT8_C(  94),  INT8_C( 118),  INT8_C(  32), -INT8_C(  42),
        -INT8_C(  86),  INT8_C(  89), -INT8_C(  66), -INT8_C(  64), -INT8_C(  97), -INT8_C(  94), -INT8_C(  57),  INT8_C( 103),
         INT8_C( 125), -INT8_C(  74),  INT8_C( 100), -INT8_C(  66),  INT8_C(  53), -INT8_C(  96),  INT8_C(  71), -INT8_C( 122),
         INT8_C(  11),  INT8_C(   4), -INT8_C(  65), -INT8_C(  96),  INT8_C(   8),  INT8_C(  60), -INT8_C(   3), -INT8_C(  38),
        -INT8_C(  96),  INT8_C(   5), -INT8_C(  40),  INT8_C(  67),  INT8_C( 123), -INT8_C(   7),  INT8_C(  25),  INT8_C(  38),
         INT8_C(  82), -INT8_C(  41), -INT8_C(  26), -INT8_C(  15),  INT8_C( 121), -INT8_C(  83),  INT8_C(  89), -INT8_C(  10),
         INT8_C(  99), -INT8_C(  67), -INT8_C(  76), -INT8_C( 104),  INT8_C(  93), -INT8_C(   4),  INT8_C(  31),  INT8_C( 104) },
      {  INT8_C(   0), -INT8_C(  34),  INT8_C(   8),  INT8_C(   8),  INT8_C(  26),  INT8_C(   6), -INT8_C(  30), -INT8_C(  69),
         INT8_C(  11), -INT8_C(  69), -INT8_C(   2), -INT8_C( 121), -INT8_C(  76),  INT8_C(  23), -INT8_C(  83),  INT8_C(   6),
        -INT8_C(  18), -INT8_C( 109), -INT8_C(   8),  INT8_C( 103),  INT8_C(  64),  INT8_C(  81),  INT8_C(  93), -INT8_C(  93),
         INT8_C(  14),  INT8_C(  18),  INT8_C(  59),  INT8_C( 108),  INT8_C(  14),  INT8_C(  90), -INT8_C(  44),  INT8_C(  14),
         INT8_C(  56), -INT8_C(  35),  INT8_C(  23),  INT8_C(  83), -INT8_C(  29), -INT8_C(   7),  INT8_C(  14), -INT8_C(  18),
        -INT8_C(  76),  INT8_C(  12),  INT8_C( 117),  INT8_C( 104),  INT8_C(  35),  INT8_C(  34),  INT8_C( 111),  INT8_C(  17),
        -INT8_C(  75),  INT8_C( 103),  INT8_C( 120), -INT8_C(  11), -INT8_C(  72), -INT8_C(  43), -INT8_C( 104), -INT8_C(  58),
        -INT8_C(  25), -INT8_C(  44),  INT8_C(  50), -INT8_C(  11),  INT8_C(  46),  INT8_C(   7),  INT8_C(   4),  INT8_C( 103) },
      { -INT16_C( 19978), -INT16_C( 22419), -INT16_C(  7158), -INT16_C(  3775),  INT16_C(  5866),  INT16_C(  5114), -INT16_C(  9598), -INT16_C( 24184),
        -INT16_C( 12761),  INT16_C( 18256),  INT16_C( 23298),  INT16_C(  8928),  INT16_C(  5026),  INT16_C( 26420),  INT16_C( 15142), -INT16_C(  5897),
         INT16_C(   476),  INT16_C( 17673), -INT16_C( 11959), -INT16_C(   382), -INT16_C( 12100),  INT16_C( 32240), -INT16_C( 12600), -INT16_C( 21786),
         INT16_C( 15995),  INT16_C(  8814),  INT16_C( 13363), -INT16_C( 23524),  INT16_C( 17685),  INT16_C(  2020), -INT16_C(  9272),  INT16_C( 10836) } },
    { {  INT16_C(  7140), -INT16_C( 14406), -INT16_C( 14316), -INT16_C( 13899),  INT16_C( 11220), -INT16_C(  2255), -INT16_C( 24499),  INT16_C(   776),
        -INT16_C( 32761), -INT16_C( 16392), -INT16_C( 28331),  INT16_C( 15750), -INT16_C( 18331), -INT16_C( 27854),  INT16_C( 14015), -INT16_C( 23558),
        -INT16_C( 19375),  INT16_C( 26218),  INT16_C(  8316),  INT16_C( 20527),  INT16_C( 24651), -INT16_C( 26553),  INT16_C( 20225),  INT16_C(  2203),
        -INT16_C( 27441),  INT16_C(  9672),  INT16_C( 20005), -INT16_C( 30110), -INT16_C( 27642), -INT16_C( 14819),  INT16_C(  6347),  INT16_C(  7273) },
      UINT32_C(1233310924),
      { -INT8_C(  12), -INT8_C(  79), -INT8_C( 103),  INT8_C(  63),  INT8_C(  18), -INT8_C(  31), -INT8_C(  41),  INT8_C(  19),
         INT8_C(  48),  INT8_C( 115),  INT8_C(  27),  INT8_C(   0),  INT8_C(   7), -INT8_C(  29),  INT8_C(  37),  INT8_C(  44),
         INT8_C(  49), -INT8_C( 121), -INT8_C(  74),  INT8_C(  56),  INT8_C(  27), -INT8_C(  45), -INT8_C(   2), -INT8_C(  26),
        -INT8_C(  21),  INT8_C( 103),  INT8_C(   3), -INT8_C(  72),  INT8_C(  59), -INT8_C( 123),  INT8_C(   1),  INT8_C(  47),
         INT8_C(  55), -INT8_C( 102),  INT8_C( 110),  INT8_C(  73),  INT8_C( 123),  INT8_C(  70),  INT8_C(  92), -INT8_C(  84),
        -INT8_C(  71),  INT8_C( 119), -INT8_C(  84), -INT8_C(  64),  INT8_C(  91), -INT8_C(  47), -INT8_C(  20), -INT8_C( 116),
         INT8_C(  88), -INT8_C(  94), -INT8_C(  60),  INT8_C( 115),  INT8_C( 117), -INT8_C(  62),  INT8_C(  90),  INT8_C(  97),
         INT8_C(  42),  INT8_C(  93),  INT8_C(  25),  INT8_C( 101), -INT8_C(  30),  INT8_C(  26), -INT8_C( 107),  INT8_C(  25) },
      { -INT8_C(  76),  INT8_C(   3),  INT8_C(  98),  INT8_C(  48),  INT8_C(  73), -INT8_C(  66), -INT8_C(  36),  INT8_C(   2),
         INT8_C(  54), -INT8_C( 120), -INT8_C(  62), -INT8_C( 111),  INT8_C(  89), -INT8_C(  82),  INT8_C(  29), -INT8_C(  79),
         INT8_C(  80), -INT8_C(  30),  INT8_C(  36), -INT8_C(  58), -INT8_C(  92),  INT8_C( 126),  INT8_C(  39), -INT8_C(  50),
        -INT8_C(  37),  INT8_C(  64),  INT8_C(  52), -INT8_C(  66),  INT8_C(  90), -INT8_C(  55), -INT8_C(  41),  INT8_C(  14),
        -INT8_C(  52),  INT8_C(  58),  INT8_C(  62),  INT8_C(  22), -INT8_C(   8),  INT8_C(  26),  INT8_C(  24),  INT8_C(  46),
        -INT8_C(  94), -INT8_C(  37), -INT8_C(  65), -INT8_C(   5), -INT8_C( 119), -INT8_C(  35), -INT8_C(  84), -INT8_C(  38),
        -INT8_C(  65), -INT8_C(  47), -INT8_C(  96),  INT8_C(  99),  INT8_C(  79), -INT8_C(  57),  INT8_C(  50),  INT8_C(  43),
         INT8_C(   7),  INT8_C( 102), -INT8_C(  23),  INT8_C(  97),  INT8_C(  47), -INT8_C(  64),  INT8_C( 111), -INT8_C(   5) },
      {  INT16_C(  7140), -INT16_C( 14406), -INT16_C( 13536), -INT16_C(  7702),  INT16_C( 11220), -INT16_C(  2255), -INT16_C( 17991), -INT16_C(  2403),
        -INT16_C( 32761), -INT16_C( 16392),  INT16_C( 24102),  INT16_C( 15750), -INT16_C(  2103), -INT16_C( 27854), -INT16_C(  2005),  INT16_C(   617),
        -INT16_C( 19375),  INT16_C(  8426),  INT16_C(  8316),  INT16_C( 20527),  INT16_C( 24651), -INT16_C( 26553),  INT16_C( 20225), -INT16_C( 25144),
        -INT16_C( 13334),  INT16_C(  9672),  INT16_C( 20005),  INT16_C(  8671), -INT16_C( 27642), -INT16_C( 14819),  INT16_C(  8958),  INT16_C(  7273) } },
    { { -INT16_C( 20742), -INT16_C(  3311),  INT16_C( 10952),  INT16_C( 27425), -INT16_C(  7931), -INT16_C( 29082),  INT16_C(  5054),  INT16_C( 32104),
         INT16_C(  2276),  INT16_C( 13280),  INT16_C(  4815), -INT16_C( 10658),  INT16_C( 18296), -INT16_C( 22729), -INT16_C( 22776),  INT16_C(   675),
        -INT16_C( 19371),  INT16_C(  7669),  INT16_C(  6110), -INT16_C(  7288), -INT16_C(  4104), -INT16_C( 18830), -INT16_C(  9726), -INT16_C(  6605),
         INT16_C(  5091), -INT16_C( 19943),  INT16_C( 30758), -INT16_C( 24951), -INT16_C( 16193), -INT16_C( 14522), -INT16_C(  5785), -INT16_C( 17206) },
      UINT32_C(2094710685),
      { -INT8_C(  42),  INT8_C(  98),  INT8_C(  95), -INT8_C(  50),  INT8_C(  81), -INT8_C(  47), -INT8_C( 124),  INT8_C(  83),
        -INT8_C(  84), -INT8_C(  73),  INT8_C(  57), -INT8_C( 113), -INT8_C(  53),  INT8_C(  83),  INT8_C(  65), -INT8_C(  15),
        -INT8_C(  53), -INT8_C(  54), -INT8_C( 113), -INT8_C( 118), -INT8_C( 117), -INT8_C(  43),  INT8_C(  82), -INT8_C(  14),
        -INT8_C(  66),  INT8_C(  28), -INT8_C(  81),  INT8_C(  92), -INT8_C(  37), -INT8_C( 119), -INT8_C(  40), -INT8_C(  78),
        -INT8_C(  21),  INT8_C(  55),      INT8_MIN,  INT8_C(  61),  INT8_C(   9),  INT8_C(   5), -INT8_C( 112), -INT8_C(  75),
        -INT8_C(  68), -INT8_C(  54),  INT8_C(  68), -INT8_C( 121),  INT8_C(  29), -INT8_C( 123),  INT8_C( 120), -INT8_C(  24),
         INT8_C(  80),  INT8_C(   8),  INT8_C( 114), -INT8_C(  37), -INT8_C(  35), -INT8_C(  60), -INT8_C(  51), -INT8_C( 100),
        -INT8_C(  32),  INT8_C( 124), -INT8_C(   8), -INT8_C(  68),  INT8_C(   5), -INT8_C(  48),  INT8_C( 110), -INT8_C(  15) },
      {  INT8_C(   7), -INT8_C(  18),  INT8_C(  46),  INT8_C(  16), -INT8_C(  13), -INT8_C(  66), -INT8_C(  59), -INT8_C(  80),
        -INT8_C( 120),  INT8_C(   9),  INT8_C(  55), -INT8_C(  91), -INT8_C( 113), -INT8_C(  80), -INT8_C( 115), -INT8_C(  33),
        -INT8_C(  72),  INT8_C(   0), -INT8_C(  70), -INT8_C( 107), -INT8_C(  60), -INT8_C( 121),  INT8_C(  49), -INT8_C(  91),
         INT8_C(   4),  INT8_C(  41),  INT8_C(  97),  INT8_C(   9), -INT8_C(   7), -INT8_C(  49), -INT8_C(   6),  INT8_C(   1),
        -INT8_C(  67),  INT8_C(  40),  INT8_C(  17), -INT8_C(  79), -INT8_C(  25), -INT8_C(  41),  INT8_C(  97),  INT8_C( 111),
        -INT8_C(  32), -INT8_C( 104),  INT8_C(  21),  INT8_C( 111),  INT8_C(  72), -INT8_C(  94),  INT8_C(  78),  INT8_C(   0),
        -INT8_C(  94),  INT8_C(   8), -INT8_C( 106),  INT8_C( 103), -INT8_C( 112), -INT8_C(  57),  INT8_C(  12), -INT8_C( 108),
        -INT8_C(  15),  INT8_C( 109), -INT8_C(  99), -INT8_C(  22),  INT8_C(  60), -INT8_C( 104), -INT8_C(  21), -INT8_C(   7) },
      { -INT16_C(   266), -INT16_C(  3311), -INT16_C( 14847), -INT16_C( 14428), -INT16_C( 18993), -INT16_C( 29082),  INT16_C(  5054), -INT16_C( 15428),
        -INT16_C( 14616), -INT16_C( 24776),       INT16_MIN, -INT16_C( 18004),  INT16_C(  1908),  INT16_C( 17803), -INT16_C( 22776), -INT16_C(  1118),
        -INT16_C( 19371), -INT16_C(  2643),  INT16_C(  6110),       INT16_MAX, -INT16_C( 27024), -INT16_C( 18830), -INT16_C( 10414),  INT16_C(  9360),
         INT16_C(  5091), -INT16_C( 19943),       INT16_MIN, -INT16_C( 14388),  INT16_C( 10156), -INT16_C( 28688), -INT16_C( 21332), -INT16_C( 17206) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i src = simde_mm512_loadu_epi16(test_vec[i].src);
    simde__m512i a = simde_mm512_loadu_epi8(test_vec[i].a);
    simde__m512i b = simde_mm512_loadu_epi8(test_vec[i].b);
    simde__m512i r = simde_mm512_mask_maddubs_epi16(src, test_vec[i].k, a, b);
    simde_test_x86_assert_equal_i16x32(r, simde_mm512_loadu_epi16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m512i src = simde_test_x86_random_i16x32();
    simde__mmask32 k = simde_test_x86_random_mmask32();
    simde__m512i a = simde_test_x86_random_i8x64();
    simde__m512i b = simde_test_x86_random_i8x64();
    simde__m512i r = simde_mm512_mask_maddubs_epi16(src, k, a, b);

    simde_test_x86_write_i16x32(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask32(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i8x64(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i8x64(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_maskz_maddubs_epi16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask32 k;
    const int8_t a[64];
    const int8_t b[64];
    const int16_t r[32];
  } test_vec[] = {
    { UINT32_C( 574325395),
      {  INT8_C(  51), -INT8_C(  84),  INT8_C(  45), -INT8_C( 123),  INT8_C(  17),  INT8_C(  41),  INT8_C(  63),  INT8_C(   1),
        -INT8_C(  45), -INT8_C(  38), -INT8_C( 114),  INT8_C(  51),  INT8_C( 104), -INT8_C( 110), -INT8_C(  55),  INT8_C(  70),
        -INT8_C(  31),  INT8_C( 101),  INT8_C(  36),  INT8_C(   0), -INT8_C(  50),  INT8_C( 105), -INT8_C(  71), -INT8_C( 113),
             INT8_MAX,  INT8_C(  22),  INT8_C( 122),  INT8_C(  19), -INT8_C( 104), -INT8_C(  75),  INT8_C(  53), -INT8_C(  53),
         INT8_C(  97),  INT8_C(  98),  INT8_C(  80),  INT8_C( 114), -INT8_C( 116), -INT8_C( 112),  INT8_C( 116),  INT8_C(  95),
         INT8_C( 106),  INT8_C(   2), -INT8_C( 110), -INT8_C(  46), -INT8_C( 108),  INT8_C(  91),  INT8_C(  24),  INT8_C( 118),
        -INT8_C(  64),  INT8_C(  61),  INT8_C( 118), -INT8_C( 114), -INT8_C(  90),  INT8_C(  47),  INT8_C(  29),  INT8_C(  38),
         INT8_C(  69), -INT8_C( 105),  INT8_C(  57), -INT8_C(  34),  INT8_C(  76),  INT8_C( 110), -INT8_C(  87), -INT8_C(  82) },
      { -INT8_C(  47), -INT8_C(   6),  INT8_C(  32),  INT8_C(  93), -INT8_C( 118), -INT8_C( 108), -INT8_C(  68), -INT8_C(  12),
        -INT8_C( 105),  INT8_C(  78), -INT8_C(  57),  INT8_C(  43), -INT8_C(  87), -INT8_C(  33), -INT8_C(  95),  INT8_C( 106),
         INT8_C(  28),  INT8_C(  24), -INT8_C(   8), -INT8_C(  61),  INT8_C(  71),  INT8_C(  22), -INT8_C(  23), -INT8_C( 115),
        -INT8_C(  83),  INT8_C(  34),  INT8_C( 107), -INT8_C(   6), -INT8_C( 112),  INT8_C(  20), -INT8_C(  88),  INT8_C(  97),
         INT8_C(  14), -INT8_C(  56), -INT8_C(  66), -INT8_C( 104),  INT8_C(  93),  INT8_C( 122), -INT8_C( 115), -INT8_C(  12),
        -INT8_C(  56),  INT8_C(  84),  INT8_C(  31),  INT8_C( 114),  INT8_C(  51), -INT8_C(  63), -INT8_C(  36),  INT8_C(  80),
        -INT8_C(  39), -INT8_C(  44),  INT8_C(  19),  INT8_C(  32), -INT8_C(  22), -INT8_C(   4), -INT8_C(  83), -INT8_C( 104),
         INT8_C(  30),  INT8_C(  24), -INT8_C( 110), -INT8_C(  82),  INT8_C(  45),  INT8_C(  58),  INT8_C(  16),  INT8_C(  59) },
      { -INT16_C(  3429),  INT16_C( 13809),  INT16_C(     0),  INT16_C(     0), -INT16_C(  5151),  INT16_C(     0),  INT16_C(     0), -INT16_C( 11675),
         INT16_C(     0), -INT16_C(   288),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C( 15027),
        -INT16_C(  4130), -INT16_C( 17136),  INT16_C(     0), -INT16_C( 14480), -INT16_C(  5768),  INT16_C( 28466),  INT16_C(     0),  INT16_C(     0),
         INT16_C(     0),  INT16_C(  6786),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C( 24474),  INT16_C(     0),  INT16_C(     0) } },
    { UINT32_C(1607781890),
      {  INT8_C(  73),  INT8_C(  97),  INT8_C(  83),  INT8_C(  17), -INT8_C(  75),  INT8_C( 115), -INT8_C( 125), -INT8_C(  24),
         INT8_C(  52),  INT8_C(  95),  INT8_C(  56),  INT8_C(  13),  INT8_C(  52),  INT8_C(  75),  INT8_C(  45),  INT8_C(  30),
         INT8_C(  71), -INT8_C(  37), -INT8_C(  74),  INT8_C( 101), -INT8_C(  13),  INT8_C(  72),  INT8_C(  20),  INT8_C(  32),
        -INT8_C( 126),  INT8_C(  36),  INT8_C(  92), -INT8_C( 123), -INT8_C(  14),  INT8_C(  48), -INT8_C(  28),  INT8_C(  59),
        -INT8_C( 111),  INT8_C(  56),  INT8_C(  77),  INT8_C(  70), -INT8_C(  85), -INT8_C(  48),  INT8_C(  46), -INT8_C(  33),
         INT8_C(  48),  INT8_C( 103), -INT8_C(  20),  INT8_C( 100), -INT8_C(  78),  INT8_C(  25), -INT8_C( 126), -INT8_C(   6),
        -INT8_C(  12),  INT8_C(  57),  INT8_C(  95), -INT8_C(  24), -INT8_C( 127),  INT8_C( 115),  INT8_C(   8),  INT8_C(   4),
        -INT8_C( 105),  INT8_C( 100), -INT8_C( 119), -INT8_C( 118), -INT8_C( 108),  INT8_C( 109), -INT8_C(  59),  INT8_C(  37) },
      { -INT8_C(  91),  INT8_C(  18),  INT8_C( 107),  INT8_C(  80), -INT8_C(  29), -INT8_C( 102),  INT8_C(  47),  INT8_C(  19),
         INT8_C(   1),  INT8_C(  27),  INT8_C( 119), -INT8_C(  77),  INT8_C(  53), -INT8_C(   7), -INT8_C(  83),  INT8_C(  41),
         INT8_C(  50),  INT8_C(  13),  INT8_C(  17), -INT8_C(  76),      INT8_MIN,  INT8_C(  26), -INT8_C(  72),  INT8_C(  24),
         INT8_C( 126),  INT8_C(  65), -INT8_C(  94),  INT8_C(  19), -INT8_C(  82),  INT8_C( 103),  INT8_C(  56),  INT8_C(  84),
         INT8_C( 122), -INT8_C(  92), -INT8_C(  92),  INT8_C(  93),  INT8_C(  62), -INT8_C(  44),  INT8_C( 112),  INT8_C(  63),
        -INT8_C(  17), -INT8_C(  25), -INT8_C(  14),  INT8_C(  36), -INT8_C(  32), -INT8_C(  96),  INT8_C(  78),  INT8_C(  19),
        -INT8_C(  83),  INT8_C(  95), -INT8_C(  57),  INT8_C(  45),  INT8_C( 121),      INT8_MAX,  INT8_C(  69), -INT8_C(   8),
        -INT8_C(  64), -INT8_C(  25),  INT8_C(  11),  INT8_C( 110),  INT8_C(  79),  INT8_C(  67), -INT8_C(  62), -INT8_C(  55) },
      {  INT16_C(     0),  INT16_C( 10241),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
         INT16_C(     0), -INT16_C(  4582), -INT16_C( 29232), -INT16_C(   672),  INT16_C(     0),  INT16_C(     0), -INT16_C( 14900),  INT16_C( 17724),
         INT16_C(     0),  INT16_C(     0),  INT16_C(  1450),  INT16_C(     0), -INT16_C(  3391),  INT16_C(     0), -INT16_C(  8096),  INT16_C( 14890),
        -INT16_C( 14837),  INT16_C(  5025),  INT16_C( 30214),  INT16_C(   520), -INT16_C( 12164),  INT16_C(     0),  INT16_C( 18995),  INT16_C(     0) } },
    { UINT32_C( 623273959),
      {  INT8_C(  59), -INT8_C( 106),  INT8_C( 100),  INT8_C(  42),  INT8_C( 125),  INT8_C(  87),  INT8_C(  79),  INT8_C(  93),
        -INT8_C(   9), -INT8_C(  99),  INT8_C( 112), -INT8_C(  92), -INT8_C(   4),  INT8_C(  55), -INT8_C(  47),  INT8_C( 118),
        -INT8_C(  74),  INT8_C(  23),  INT8_C( 110),  INT8_C( 118), -INT8_C(   2),  INT8_C( 121), -INT8_C(  27),  INT8_C(  77),
        -INT8_C(  68), -INT8_C(  89),  INT8_C(  22), -INT8_C(  92),  INT8_C(  14),  INT8_C(  60), -INT8_C(  55),  INT8_C(  73),
        -INT8_C(  46),  INT8_C(  46),  INT8_C( 116),  INT8_C(  79), -INT8_C( 123), -INT8_C(  61), -INT8_C(  83),  INT8_C( 124),
         INT8_C(  96),  INT8_C(  29),  INT8_C(  32),  INT8_C(  92),  INT8_C(  85), -INT8_C(  15), -INT8_C(  46),  INT8_C(  11),
         INT8_C(   8),  INT8_C(  64), -INT8_C( 126),  INT8_C(   7), -INT8_C(  71),  INT8_C( 103),  INT8_C(  84),  INT8_C( 118),
         INT8_C(  14),  INT8_C( 107),  INT8_C(  26),  INT8_C(  29), -INT8_C(  89), -INT8_C(  29),  INT8_C( 102),  INT8_C( 122) },
      {  INT8_C(  17), -INT8_C(  38), -INT8_C(  55), -INT8_C( 106), -INT8_C(  99),  INT8_C( 118),  INT8_C(  18), -INT8_C(   3),
        -INT8_C( 108),  INT8_C(  50),  INT8_C(  90), -INT8_C(  23),  INT8_C(  36),  INT8_C(  44), -INT8_C(  12),  INT8_C(  44),
         INT8_C( 109),  INT8_C( 118),  INT8_C(  51),  INT8_C(  38), -INT8_C(  35), -INT8_C( 120), -INT8_C( 100), -INT8_C(  20),
        -INT8_C(  13), -INT8_C(  74),  INT8_C(   9), -INT8_C( 102), -INT8_C( 102),  INT8_C( 111),  INT8_C(  20), -INT8_C(  85),
         INT8_C(  74), -INT8_C(  34),  INT8_C(  66), -INT8_C(  25),  INT8_C(  84),  INT8_C(  84), -INT8_C(  27), -INT8_C(  24),
        -INT8_C( 121),  INT8_C(  63), -INT8_C(  47), -INT8_C(  85),  INT8_C( 107), -INT8_C(  58), -INT8_C(  41), -INT8_C(  40),
         INT8_C(  60),  INT8_C(  11), -INT8_C(   1),  INT8_C(  26), -INT8_C( 109), -INT8_C( 101),  INT8_C(   6), -INT8_C( 122),
         INT8_C(  82),  INT8_C(  15),  INT8_C(  32), -INT8_C(  20),  INT8_C( 126),  INT8_C(  53), -INT8_C( 105), -INT8_C(  56) },
      { -INT16_C(  4697), -INT16_C(  9952), -INT16_C(  2109),  INT16_C(     0),  INT16_C(     0),  INT16_C(  6308),  INT16_C( 11492),  INT16_C(  2684),
         INT16_C( 22552),  INT16_C( 10094), -INT16_C( 23410),  INT16_C(     0),  INT16_C(     0), -INT16_C( 16530),  INT16_C(  5232),  INT16_C(     0),
         INT16_C(     0),  INT16_C(  5681),  INT16_C( 27552),  INT16_C(     0),  INT16_C(     0), -INT16_C(  9324),  INT16_C(     0),  INT16_C(     0),
         INT16_C(  1184),  INT16_C(     0), -INT16_C( 30568),  INT16_C(     0),  INT16_C(     0),  INT16_C(   252),  INT16_C(     0),  INT16_C(     0) } },
    { UINT32_C(1739643155),
      {  INT8_C(  46), -INT8_C( 107),  INT8_C(  80), -INT8_C(  75), -INT8_C(  44),  INT8_C(  33),  INT8_C(  96),  INT8_C(  63),
        -INT8_C(  25),  INT8_C(  55),  INT8_C(  24),  INT8_C(  36),  INT8_C(  66),  INT8_C(  23),  INT8_C(  62), -INT8_C(  43),
        -INT8_C(  78),  INT8_C(  68),  INT8_C(  91),  INT8_C(   4),  INT8_C(  83),  INT8_C( 124), -INT8_C(  16), -INT8_C(  47),
        -INT8_C(  79), -INT8_C( 120), -INT8_C( 102), -INT8_C(  60),  INT8_C(  97),  INT8_C(  74),  INT8_C(  43), -INT8_C( 113),
        -INT8_C(  33),  INT8_C( 123),  INT8_C(  68), -INT8_C(  77), -INT8_C(  99), -INT8_C(  92), -INT8_C(  14), -INT8_C( 124),
        -INT8_C(  36),  INT8_C(  10), -INT8_C(  88),  INT8_C(  30),  INT8_C(  33), -INT8_C(  26), -INT8_C(  12), -INT8_C(  44),
         INT8_C(  42),  INT8_C(  79), -INT8_C(  40),  INT8_C( 125), -INT8_C(  53), -INT8_C(  55),  INT8_C(  79),  INT8_C( 124),
         INT8_C(  81), -INT8_C(  23),  INT8_C(  64), -INT8_C(  78),  INT8_C(  51),  INT8_C( 108),  INT8_C(  66),  INT8_C(  18) },
      { -INT8_C(  25), -INT8_C( 122), -INT8_C(  59), -INT8_C( 124),  INT8_C(  43), -INT8_C(  73),  INT8_C(   9),  INT8_C(   7),
        -INT8_C(  62), -INT8_C(  79),  INT8_C(  37), -INT8_C(  29), -INT8_C( 104),  INT8_C(  25), -INT8_C(  73), -INT8_C(  62),
         INT8_C( 105), -INT8_C( 112),  INT8_C(  64),  INT8_C(  52),  INT8_C(  89), -INT8_C( 113), -INT8_C(  79), -INT8_C(  86),
         INT8_C( 120), -INT8_C(  15),  INT8_C(  92), -INT8_C(  85),  INT8_C(  93), -INT8_C(  98), -INT8_C(  67),  INT8_C(  69),
         INT8_C(  37), -INT8_C( 126), -INT8_C(  55),  INT8_C(  80),  INT8_C(  57), -INT8_C(  46),  INT8_C(  87), -INT8_C(   5),
        -INT8_C( 124),  INT8_C( 124), -INT8_C(  33),  INT8_C(  28), -INT8_C( 106), -INT8_C( 106), -INT8_C(  34), -INT8_C(   1),
         INT8_C(  38),  INT8_C(  30),  INT8_C(  51),      INT8_MAX, -INT8_C(  83), -INT8_C(  28),  INT8_C(  41),  INT8_C(  37),
        -INT8_C(  42), -INT8_C( 122), -INT8_C(  48),  INT8_C(  51),  INT8_C(  36), -INT8_C( 115),  INT8_C( 120),  INT8_C(  73) },
      { -INT16_C( 19328), -INT16_C( 27164),  INT16_C(     0),  INT16_C(     0), -INT16_C( 18667),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
         INT16_C( 11074),  INT16_C(     0),  INT16_C(     0),       INT16_MIN,  INT16_C( 19200),  INT16_C(     0),  INT16_C(  1769),  INT16_C(  6986),
         INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C( 26040), -INT16_C(  4704),  INT16_C(     0), -INT16_C(  8508),
         INT16_C(  3966),  INT16_C( 26891), -INT16_C( 22477),  INT16_C(     0),  INT16_C(     0),  INT16_C(  6006), -INT16_C( 10584),  INT16_C(     0) } },
    { UINT32_C(1234780687),
      {  INT8_C(  20), -INT8_C(  16),  INT8_C(  68), -INT8_C( 104),  INT8_C( 109),  INT8_C(  35), -INT8_C(  76),  INT8_C(   3),
        -INT8_C(  70), -INT8_C( 109),  INT8_C(   2), -INT8_C(  32), -INT8_C(  79),  INT8_C(  53),  INT8_C(  96),  INT8_C(  95),
         INT8_C(  26), -INT8_C( 119), -INT8_C( 124), -INT8_C(  16),  INT8_C(  15),  INT8_C(  85),  INT8_C(  35),  INT8_C(  52),
        -INT8_C(  30), -INT8_C( 100),  INT8_C( 125), -INT8_C(  14), -INT8_C(  34),  INT8_C(  23),  INT8_C(  59), -INT8_C(  14),
         INT8_C(   7),      INT8_MAX, -INT8_C( 117),  INT8_C( 116), -INT8_C(  93),  INT8_C(  63),  INT8_C( 119),  INT8_C(  93),
        -INT8_C(  46),  INT8_C( 121),  INT8_C(  61), -INT8_C( 124), -INT8_C(  81), -INT8_C(  99), -INT8_C(  29), -INT8_C(  55),
         INT8_C(  39),  INT8_C( 103), -INT8_C(  71),  INT8_C(  54), -INT8_C(  68), -INT8_C(  36),  INT8_C( 106), -INT8_C(  97),
         INT8_C( 120), -INT8_C(  24), -INT8_C( 111),  INT8_C(  86), -INT8_C(   1), -INT8_C(  52),  INT8_C(  73),  INT8_C(   6) },
      {  INT8_C(  75), -INT8_C(  44),  INT8_C( 123), -INT8_C(  18),  INT8_C(  19), -INT8_C(  14),  INT8_C(  75), -INT8_C(  26),
         INT8_C( 108), -INT8_C( 119),  INT8_C( 106),  INT8_C(  27),  INT8_C(  38),  INT8_C(  77), -INT8_C(  28),  INT8_C(  77),
        -INT8_C(  76), -INT8_C(  99), -INT8_C( 124),  INT8_C( 113),  INT8_C( 121), -INT8_C(  18),  INT8_C(  16), -INT8_C(  14),
        -INT8_C(  42), -INT8_C(  95),  INT8_C(  72), -INT8_C(  43),  INT8_C( 109), -INT8_C( 111), -INT8_C(  36), -INT8_C(  72),
         INT8_C( 101),  INT8_C(  87), -INT8_C(  89),  INT8_C( 121),  INT8_C(  73), -INT8_C(  14),  INT8_C(  95), -INT8_C(  75),
         INT8_C( 123), -INT8_C(  55), -INT8_C(  48), -INT8_C(  94),  INT8_C(  22), -INT8_C(  76), -INT8_C(  17), -INT8_C(  54),
         INT8_C(  81),  INT8_C( 115),  INT8_C(  59), -INT8_C(  53),  INT8_C(  98),  INT8_C(  75), -INT8_C(  67),  INT8_C(  56),
        -INT8_C(  20),  INT8_C(   5),  INT8_C(  14),  INT8_C(  89), -INT8_C( 105), -INT8_C(  22),  INT8_C(  18), -INT8_C(   4) },
      { -INT16_C(  9060),  INT16_C(  5628),  INT16_C(  1581),  INT16_C( 13422),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
         INT16_C(     0),  INT16_C( 10752),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C( 21645),  INT16_C(     0),
         INT16_C( 11756),  INT16_C(     0),  INT16_C(     0),  INT16_C(  4330),  INT16_C( 19175),  INT16_C(     0),  INT16_C(     0), -INT16_C( 14713),
         INT16_C( 15004),  INT16_C(     0),  INT16_C(     0),  INT16_C(  1802),  INT16_C(     0),  INT16_C(     0), -INT16_C( 31263),  INT16_C(     0) } },
    { UINT32_C(2322970945),
      { -INT8_C(  85), -INT8_C(  44),  INT8_C(  64),  INT8_C(  39), -INT8_C(  99),  INT8_C(  16), -INT8_C(  55), -INT8_C(  77),
        -INT8_C(  59), -INT8_C(  72),  INT8_C( 126),  INT8_C(  22),  INT8_C(  44), -INT8_C(  71), -INT8_C(  31), -INT8_C( 114),
         INT8_C(   5), -INT8_C(  98), -INT8_C(  58), -INT8_C(  15), -INT8_C(  92), -INT8_C(  44),  INT8_C(  75),  INT8_C(  59),
        -INT8_C(  66),  INT8_C(  93),  INT8_C(  55), -INT8_C(   1),  INT8_C(  22), -INT8_C(  83), -INT8_C( 118), -INT8_C(  63),
        -INT8_C( 127), -INT8_C(  54), -INT8_C(  24),  INT8_C(  31), -INT8_C(  38), -INT8_C(  79), -INT8_C(  46), -INT8_C(  97),
         INT8_C( 106),  INT8_C(  80), -INT8_C(  74), -INT8_C( 106),  INT8_C(  10), -INT8_C( 105),  INT8_C(  36),  INT8_C(  15),
         INT8_C(  54), -INT8_C(  22),  INT8_C(   0), -INT8_C(  38), -INT8_C(  65),  INT8_C(  75),  INT8_C(  21),  INT8_C( 125),
        -INT8_C(  88),  INT8_C(  76),  INT8_C( 125), -INT8_C(  66), -INT8_C(   7),  INT8_C(   7),      INT8_MIN,  INT8_C( 123) },
      { -INT8_C(  47),  INT8_C( 104), -INT8_C( 102), -INT8_C(  85),  INT8_C(  26),  INT8_C( 108),  INT8_C(  75), -INT8_C( 124),
        -INT8_C(  67),  INT8_C(   1),  INT8_C(  26), -INT8_C(  57), -INT8_C( 104),  INT8_C(  62), -INT8_C(  42), -INT8_C(  50),
         INT8_C(  40), -INT8_C(  42), -INT8_C(  88), -INT8_C(  25),  INT8_C(  34), -INT8_C(  67),  INT8_C( 101), -INT8_C(  54),
         INT8_C(  10), -INT8_C(  30), -INT8_C( 119),  INT8_C(   3), -INT8_C(  23),  INT8_C(   9),  INT8_C( 126), -INT8_C(  70),
         INT8_C( 113),  INT8_C(  24),  INT8_C( 101), -INT8_C( 117), -INT8_C( 123), -INT8_C(  80),  INT8_C(  15),  INT8_C(  66),
        -INT8_C(  79),  INT8_C(  41),  INT8_C(   9),  INT8_C(  74),  INT8_C( 103), -INT8_C(  33),  INT8_C(  24), -INT8_C( 112),
        -INT8_C(  75), -INT8_C(  63),  INT8_C( 119), -INT8_C(  41),  INT8_C( 126), -INT8_C(  36), -INT8_C(  94), -INT8_C( 120),
        -INT8_C(  66),  INT8_C(  43), -INT8_C( 116), -INT8_C(  89),  INT8_C(  52),  INT8_C(  10),  INT8_C(  97), -INT8_C(  91) },
      {  INT16_C( 14011),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(  6894),  INT16_C(     0),
        -INT16_C(  6436),  INT16_C(     0),  INT16_C(     0),  INT16_C(  4389), -INT16_C(   890), -INT16_C(  5780),  INT16_C(     0),  INT16_C(  3878),
         INT16_C( 19425),  INT16_C(     0),       INT16_MIN,  INT16_C(     0), -INT16_C(  5094),  INT16_C( 12738), -INT16_C(  3953),  INT16_C(     0),
         INT16_C(     0), -INT16_C(  8938),  INT16_C(     0), -INT16_C( 16974),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(  1223) } },
    { UINT32_C(2821834531),
      {  INT8_C( 119),  INT8_C(  64), -INT8_C(  22),  INT8_C(  41),  INT8_C( 106), -INT8_C(  13),  INT8_C( 115), -INT8_C(  47),
        -INT8_C(  46), -INT8_C( 117),  INT8_C(  97), -INT8_C( 121),  INT8_C(  76), -INT8_C(  39),  INT8_C(  95), -INT8_C(  53),
        -INT8_C(  75),  INT8_C(   1),  INT8_C(  83),  INT8_C( 116),  INT8_C(  44), -INT8_C(  33),  INT8_C(  27),  INT8_C(  96),
        -INT8_C(  22),  INT8_C( 125),  INT8_C(   5),  INT8_C(  13),  INT8_C(  68),  INT8_C(  54), -INT8_C(  75), -INT8_C(  69),
         INT8_C( 119), -INT8_C(  97), -INT8_C(  28), -INT8_C(  31), -INT8_C( 110),  INT8_C(  87), -INT8_C(  78),  INT8_C( 100),
        -INT8_C(  29),  INT8_C(  20), -INT8_C(  21),  INT8_C(  47), -INT8_C(  19),  INT8_C(  74), -INT8_C(   6), -INT8_C(  94),
         INT8_C(  75),  INT8_C(  78),  INT8_C(  22),  INT8_C( 119),  INT8_C(  45),  INT8_C(  50), -INT8_C(  41),  INT8_C(  23),
        -INT8_C(  81), -INT8_C(  35),  INT8_C(  36), -INT8_C(  13),  INT8_C(  19), -INT8_C(  39), -INT8_C(  82), -INT8_C( 118) },
      {  INT8_C( 120), -INT8_C( 109),  INT8_C( 107),  INT8_C(  10), -INT8_C(  22),  INT8_C(  30),  INT8_C( 110), -INT8_C(  51),
         INT8_C(  50),  INT8_C(  90), -INT8_C(   3),  INT8_C(  31), -INT8_C(  92), -INT8_C(   9), -INT8_C(  63), -INT8_C(  16),
         INT8_C(  69), -INT8_C(  40),  INT8_C( 103),  INT8_C( 115),  INT8_C(  10),  INT8_C(  63), -INT8_C( 118), -INT8_C(  71),
         INT8_C(  28), -INT8_C(  81), -INT8_C(  84),  INT8_C(  47), -INT8_C( 120),  INT8_C(  90), -INT8_C(  70),  INT8_C(   1),
        -INT8_C(  19),  INT8_C(  37),  INT8_C(  11), -INT8_C(  40),  INT8_C(  67),  INT8_C( 122), -INT8_C(  91),  INT8_C( 117),
        -INT8_C(  44), -INT8_C(  94), -INT8_C( 108),  INT8_C( 120), -INT8_C( 102),  INT8_C(  86),  INT8_C( 104), -INT8_C(  33),
         INT8_C(  46), -INT8_C(  48),  INT8_C(  82),  INT8_C(  56),  INT8_C(  15), -INT8_C(  35), -INT8_C(  15),  INT8_C(  43),
        -INT8_C( 116), -INT8_C(  99),  INT8_C(  90),  INT8_C(  20), -INT8_C(   9),  INT8_C(  20),  INT8_C(  21), -INT8_C(  27) },
      {  INT16_C(  7304),  INT16_C( 25448),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(  3894),  INT16_C(     0),  INT16_C(     0),
         INT16_C( 12449),  INT16_C( 21889),  INT16_C( 14489),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(  3300), -INT16_C( 12483),
         INT16_C(  3622),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C( 11868), -INT16_C( 19740),  INT16_C(     0),  INT16_C(     0),
         INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(  2236),  INT16_C(     0),  INT16_C(  8100),  INT16_C(     0), -INT16_C(    72) } },
    { UINT32_C(2109546810),
      { -INT8_C( 101),  INT8_C(  98), -INT8_C(  13),  INT8_C( 111),  INT8_C(   5), -INT8_C( 121), -INT8_C(  25), -INT8_C(  97),
        -INT8_C(  35),  INT8_C(  80),  INT8_C( 126),  INT8_C(  11),  INT8_C(  32), -INT8_C(  47),  INT8_C(  67),  INT8_C(  47),
        -INT8_C(  82),  INT8_C(  52),  INT8_C(  90),  INT8_C(  58), -INT8_C(  47), -INT8_C(  76),  INT8_C(  78), -INT8_C(  55),
        -INT8_C(  55),  INT8_C( 100), -INT8_C(  82),  INT8_C(   3), -INT8_C( 123),  INT8_C( 107),      INT8_MIN,  INT8_C(  32),
        -INT8_C(  51),  INT8_C( 115), -INT8_C( 113), -INT8_C(  46), -INT8_C(   5),  INT8_C( 118),  INT8_C( 113), -INT8_C(  40),
        -INT8_C(  58), -INT8_C(  16), -INT8_C(  28), -INT8_C(  26), -INT8_C(  63),  INT8_C(  39),  INT8_C(  21),  INT8_C( 111),
         INT8_C(  92),  INT8_C( 111), -INT8_C(  87),  INT8_C(  45),  INT8_C(  36), -INT8_C(   9), -INT8_C(  10), -INT8_C(  19),
         INT8_C(  91), -INT8_C(  92), -INT8_C(  16), -INT8_C(  32),  INT8_C(  15),  INT8_C( 112),  INT8_C(   0), -INT8_C(  35) },
      { -INT8_C(  28), -INT8_C( 113), -INT8_C(  81), -INT8_C(  33),  INT8_C(   6),  INT8_C(  33), -INT8_C(  73), -INT8_C(  52),
         INT8_C(  17), -INT8_C( 101), -INT8_C(  77), -INT8_C(  46), -INT8_C(  61), -INT8_C(  56),  INT8_C(  65),  INT8_C(  31),
         INT8_C(  56), -INT8_C(  22),  INT8_C(  76),  INT8_C(  92), -INT8_C(  31),  INT8_C(  67),  INT8_C(  73),  INT8_C(  61),
        -INT8_C(  25),  INT8_C(  57),  INT8_C(  29), -INT8_C(   9), -INT8_C(  87),  INT8_C(  30), -INT8_C(  44), -INT8_C( 115),
        -INT8_C(  83), -INT8_C( 125),  INT8_C( 108), -INT8_C(  77), -INT8_C(  92),  INT8_C(  36),      INT8_MIN, -INT8_C(  75),
        -INT8_C(  65),  INT8_C(  51), -INT8_C( 121), -INT8_C( 126), -INT8_C(   5), -INT8_C(  56), -INT8_C(  95),  INT8_C(  51),
        -INT8_C(  78), -INT8_C(  18), -INT8_C( 113), -INT8_C( 108),  INT8_C(  49), -INT8_C(  40), -INT8_C(  47),  INT8_C(  24),
         INT8_C(  17), -INT8_C(  18),  INT8_C(  15), -INT8_C(  69),  INT8_C(  12), -INT8_C(  29),  INT8_C(  72), -INT8_C(  70) },
      {  INT16_C(     0), -INT16_C( 23346),  INT16_C(     0), -INT16_C( 25131), -INT16_C(  4323), -INT16_C( 10208),  INT16_C(     0),  INT16_C(     0),
         INT16_C(  8600),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(  5019),  INT16_C(     0),  INT16_C(     0),
        -INT16_C( 31390),  INT16_C(     0), -INT16_C( 18844), -INT16_C( 30664), -INT16_C(   630),       INT16_MIN,  INT16_C(     0),  INT16_C(  3666),
        -INT16_C(  9174),  INT16_C(     0), -INT16_C(  8116), -INT16_C(  5874), -INT16_C(  1405), -INT16_C( 11856), -INT16_C(  3068),  INT16_C(     0) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i a = simde_mm512_loadu_epi16(test_vec[i].a);
    simde__m512i b = simde_mm512_loadu_epi16(test_vec[i].b);
    simde__m512i r = simde_mm512_maskz_maddubs_epi16(test_vec[i].k, a, b);
    simde_test_x86_assert_equal_i16x32(r, simde_mm512_loadu_epi16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask32 k = simde_test_x86_random_mmask32();
    simde__m512i a = simde_test_x86_random_i8x64();
    simde__m512i b = simde_test_x86_random_i8x64();
    simde__m512i r = simde_mm512_maskz_maddubs_epi16(k, a, b);

    simde_test_x86_write_mmask32(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i8x64(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i8x64(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_mask_maddubs_epi16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_maskz_maddubs_epi16)

  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_mask_maddubs_epi16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_maskz_maddubs_epi16)

  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_maddubs_epi16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_maddubs_epi16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_maskz_maddubs_epi16)
SIMDE_TEST_FUNC_LIST_END

#include <test/x86/avx512/test-avx512-footer.h>
