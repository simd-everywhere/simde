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

#define SIMDE_TEST_X86_AVX512_INSN set

#include <test/x86/avx512/test-avx512.h>
#include <simde/x86/avx512/set.h>

static int
test_simde_mm512_set_epi8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int8_t a[64];
    const int8_t r[64];
  } test_vec[] = {
    { {  INT8_C(  83),  INT8_C(  58),  INT8_C(  10),  INT8_C(  67), -INT8_C(  56), -INT8_C(  81), -INT8_C( 100),  INT8_C(  82),
        -INT8_C(   7),  INT8_C(  93), -INT8_C( 108), -INT8_C(  84), -INT8_C(  80), -INT8_C(  17), -INT8_C(  12),  INT8_C(  15),
             INT8_MIN,  INT8_C(  43), -INT8_C(  48), -INT8_C(  20),  INT8_C( 126), -INT8_C( 118),  INT8_C(   4),  INT8_C( 113),
         INT8_C(   4),  INT8_C( 115),  INT8_C(  93),  INT8_C(  20), -INT8_C(  25),  INT8_C(  42), -INT8_C(  91),  INT8_C(  58),
         INT8_C( 100), -INT8_C(  81),  INT8_C( 126),  INT8_C(  44),  INT8_C(  95),  INT8_C(  26),  INT8_C( 126),  INT8_C(  88),
         INT8_C( 119),  INT8_C(  19),  INT8_C(   4),  INT8_C(  39),  INT8_C(   2), -INT8_C(   8),  INT8_C(  54), -INT8_C( 126),
         INT8_C(  36),  INT8_C(   7),  INT8_C( 110), -INT8_C(  94), -INT8_C( 111),  INT8_C( 114),  INT8_C(  19), -INT8_C( 107),
        -INT8_C(  27),  INT8_C( 112), -INT8_C(  86), -INT8_C(  52), -INT8_C( 102),  INT8_C(  79),  INT8_C(   7), -INT8_C(   2) },
      {  INT8_C(  83),  INT8_C(  58),  INT8_C(  10),  INT8_C(  67), -INT8_C(  56), -INT8_C(  81), -INT8_C( 100),  INT8_C(  82),
        -INT8_C(   7),  INT8_C(  93), -INT8_C( 108), -INT8_C(  84), -INT8_C(  80), -INT8_C(  17), -INT8_C(  12),  INT8_C(  15),
             INT8_MIN,  INT8_C(  43), -INT8_C(  48), -INT8_C(  20),  INT8_C( 126), -INT8_C( 118),  INT8_C(   4),  INT8_C( 113),
         INT8_C(   4),  INT8_C( 115),  INT8_C(  93),  INT8_C(  20), -INT8_C(  25),  INT8_C(  42), -INT8_C(  91),  INT8_C(  58),
         INT8_C( 100), -INT8_C(  81),  INT8_C( 126),  INT8_C(  44),  INT8_C(  95),  INT8_C(  26),  INT8_C( 126),  INT8_C(  88),
         INT8_C( 119),  INT8_C(  19),  INT8_C(   4),  INT8_C(  39),  INT8_C(   2), -INT8_C(   8),  INT8_C(  54), -INT8_C( 126),
         INT8_C(  36),  INT8_C(   7),  INT8_C( 110), -INT8_C(  94), -INT8_C( 111),  INT8_C( 114),  INT8_C(  19), -INT8_C( 107),
        -INT8_C(  27),  INT8_C( 112), -INT8_C(  86), -INT8_C(  52), -INT8_C( 102),  INT8_C(  79),  INT8_C(   7), -INT8_C(   2) } },
    { { -INT8_C(   1), -INT8_C( 123),  INT8_C(  42),  INT8_C(  94), -INT8_C(  97), -INT8_C(  87), -INT8_C(  74),  INT8_C(  22),
        -INT8_C(  68), -INT8_C(  70),  INT8_C(  61), -INT8_C(  66), -INT8_C(  78),  INT8_C( 115),  INT8_C(  64), -INT8_C(  42),
         INT8_C( 122), -INT8_C(  82),  INT8_C( 120),  INT8_C(  12),  INT8_C(  32), -INT8_C( 116), -INT8_C(  95),  INT8_C(   6),
        -INT8_C(   4),  INT8_C(  75), -INT8_C(  46), -INT8_C( 105), -INT8_C( 101), -INT8_C(  39), -INT8_C( 107), -INT8_C( 102),
         INT8_C(  94), -INT8_C(  64), -INT8_C(   8), -INT8_C(   3),  INT8_C( 105), -INT8_C(  82),  INT8_C(  19),  INT8_C(  37),
         INT8_C( 104),  INT8_C(  80), -INT8_C(  29),  INT8_C(  26), -INT8_C(  60),  INT8_C(  35), -INT8_C(  15),  INT8_C(  62),
        -INT8_C(  47),  INT8_C( 105),  INT8_C(  74), -INT8_C(  15), -INT8_C(  11), -INT8_C(  20), -INT8_C(   9), -INT8_C(  14),
         INT8_C(  55), -INT8_C(  54), -INT8_C( 119), -INT8_C(  46), -INT8_C(  93),  INT8_C(  30),  INT8_C( 108),  INT8_C(   2) },
      { -INT8_C(   1), -INT8_C( 123),  INT8_C(  42),  INT8_C(  94), -INT8_C(  97), -INT8_C(  87), -INT8_C(  74),  INT8_C(  22),
        -INT8_C(  68), -INT8_C(  70),  INT8_C(  61), -INT8_C(  66), -INT8_C(  78),  INT8_C( 115),  INT8_C(  64), -INT8_C(  42),
         INT8_C( 122), -INT8_C(  82),  INT8_C( 120),  INT8_C(  12),  INT8_C(  32), -INT8_C( 116), -INT8_C(  95),  INT8_C(   6),
        -INT8_C(   4),  INT8_C(  75), -INT8_C(  46), -INT8_C( 105), -INT8_C( 101), -INT8_C(  39), -INT8_C( 107), -INT8_C( 102),
         INT8_C(  94), -INT8_C(  64), -INT8_C(   8), -INT8_C(   3),  INT8_C( 105), -INT8_C(  82),  INT8_C(  19),  INT8_C(  37),
         INT8_C( 104),  INT8_C(  80), -INT8_C(  29),  INT8_C(  26), -INT8_C(  60),  INT8_C(  35), -INT8_C(  15),  INT8_C(  62),
        -INT8_C(  47),  INT8_C( 105),  INT8_C(  74), -INT8_C(  15), -INT8_C(  11), -INT8_C(  20), -INT8_C(   9), -INT8_C(  14),
         INT8_C(  55), -INT8_C(  54), -INT8_C( 119), -INT8_C(  46), -INT8_C(  93),  INT8_C(  30),  INT8_C( 108),  INT8_C(   2) } },
    { { -INT8_C(  34),  INT8_C( 100), -INT8_C(   1),  INT8_C(  71),  INT8_C(  18),  INT8_C(  19),  INT8_C( 108),  INT8_C( 122),
         INT8_C(  99),  INT8_C(  79), -INT8_C( 107),  INT8_C(  39),  INT8_C( 114), -INT8_C( 122),  INT8_C( 102),  INT8_C(  67),
        -INT8_C(  17), -INT8_C(  80),  INT8_C(  53), -INT8_C(  27), -INT8_C( 100),  INT8_C(  44), -INT8_C(  41), -INT8_C(  44),
        -INT8_C(  10),  INT8_C(  96), -INT8_C(  90), -INT8_C( 102),  INT8_C( 126),  INT8_C(  19), -INT8_C( 100),  INT8_C(  93),
         INT8_C( 119), -INT8_C( 101), -INT8_C(  92), -INT8_C( 118), -INT8_C(  82),  INT8_C(  17),  INT8_C(   4),  INT8_C(  18),
         INT8_C(  96), -INT8_C( 103),  INT8_C(  57), -INT8_C(  45),  INT8_C(  31), -INT8_C(  97),  INT8_C(  22),  INT8_C(  15),
         INT8_C(  80),  INT8_C(  75), -INT8_C(  12), -INT8_C(  20),  INT8_C( 120), -INT8_C(  53), -INT8_C(  64),  INT8_C( 110),
         INT8_C(  43),  INT8_C( 103),  INT8_C(   8), -INT8_C(  87),  INT8_C( 122), -INT8_C(  92),  INT8_C(   6), -INT8_C(  15) },
      { -INT8_C(  34),  INT8_C( 100), -INT8_C(   1),  INT8_C(  71),  INT8_C(  18),  INT8_C(  19),  INT8_C( 108),  INT8_C( 122),
         INT8_C(  99),  INT8_C(  79), -INT8_C( 107),  INT8_C(  39),  INT8_C( 114), -INT8_C( 122),  INT8_C( 102),  INT8_C(  67),
        -INT8_C(  17), -INT8_C(  80),  INT8_C(  53), -INT8_C(  27), -INT8_C( 100),  INT8_C(  44), -INT8_C(  41), -INT8_C(  44),
        -INT8_C(  10),  INT8_C(  96), -INT8_C(  90), -INT8_C( 102),  INT8_C( 126),  INT8_C(  19), -INT8_C( 100),  INT8_C(  93),
         INT8_C( 119), -INT8_C( 101), -INT8_C(  92), -INT8_C( 118), -INT8_C(  82),  INT8_C(  17),  INT8_C(   4),  INT8_C(  18),
         INT8_C(  96), -INT8_C( 103),  INT8_C(  57), -INT8_C(  45),  INT8_C(  31), -INT8_C(  97),  INT8_C(  22),  INT8_C(  15),
         INT8_C(  80),  INT8_C(  75), -INT8_C(  12), -INT8_C(  20),  INT8_C( 120), -INT8_C(  53), -INT8_C(  64),  INT8_C( 110),
         INT8_C(  43),  INT8_C( 103),  INT8_C(   8), -INT8_C(  87),  INT8_C( 122), -INT8_C(  92),  INT8_C(   6), -INT8_C(  15) } },
    { {  INT8_C(  64), -INT8_C(  85),  INT8_C( 123), -INT8_C(  18), -INT8_C(  68),      INT8_MIN,  INT8_C(   0),  INT8_C(  28),
         INT8_C(  25),  INT8_C(  58), -INT8_C(  17),  INT8_C(  57), -INT8_C(  39),  INT8_C(   6),  INT8_C(  72),  INT8_C(  41),
         INT8_C(  81),  INT8_C(  60),  INT8_C(  22), -INT8_C(  55),  INT8_C(   7), -INT8_C(  42),  INT8_C(  56),  INT8_C(  50),
         INT8_C(  61),  INT8_C(  64), -INT8_C(  37), -INT8_C(  73), -INT8_C(  27), -INT8_C(  30), -INT8_C(  87),  INT8_C(  37),
        -INT8_C( 115),  INT8_C(  36),  INT8_C(  19),  INT8_C(  73), -INT8_C(  92),  INT8_C(  20),  INT8_C( 101), -INT8_C(  66),
         INT8_C(  78),  INT8_C(  85), -INT8_C(   9),  INT8_C(  39),  INT8_C(  91),  INT8_C(  63),  INT8_C(  81), -INT8_C(  84),
         INT8_C( 123),  INT8_C( 103),  INT8_C( 118), -INT8_C( 126),  INT8_C(  61), -INT8_C(  82), -INT8_C(  76),  INT8_C( 123),
        -INT8_C(  18), -INT8_C( 113),  INT8_C(  50), -INT8_C(  45),  INT8_C( 113), -INT8_C(  37), -INT8_C(   8), -INT8_C(   2) },
      {  INT8_C(  64), -INT8_C(  85),  INT8_C( 123), -INT8_C(  18), -INT8_C(  68),      INT8_MIN,  INT8_C(   0),  INT8_C(  28),
         INT8_C(  25),  INT8_C(  58), -INT8_C(  17),  INT8_C(  57), -INT8_C(  39),  INT8_C(   6),  INT8_C(  72),  INT8_C(  41),
         INT8_C(  81),  INT8_C(  60),  INT8_C(  22), -INT8_C(  55),  INT8_C(   7), -INT8_C(  42),  INT8_C(  56),  INT8_C(  50),
         INT8_C(  61),  INT8_C(  64), -INT8_C(  37), -INT8_C(  73), -INT8_C(  27), -INT8_C(  30), -INT8_C(  87),  INT8_C(  37),
        -INT8_C( 115),  INT8_C(  36),  INT8_C(  19),  INT8_C(  73), -INT8_C(  92),  INT8_C(  20),  INT8_C( 101), -INT8_C(  66),
         INT8_C(  78),  INT8_C(  85), -INT8_C(   9),  INT8_C(  39),  INT8_C(  91),  INT8_C(  63),  INT8_C(  81), -INT8_C(  84),
         INT8_C( 123),  INT8_C( 103),  INT8_C( 118), -INT8_C( 126),  INT8_C(  61), -INT8_C(  82), -INT8_C(  76),  INT8_C( 123),
        -INT8_C(  18), -INT8_C( 113),  INT8_C(  50), -INT8_C(  45),  INT8_C( 113), -INT8_C(  37), -INT8_C(   8), -INT8_C(   2) } },
    { {  INT8_C(   0),  INT8_C(  12),  INT8_C(  71), -INT8_C(  92),  INT8_C(  32), -INT8_C(  83),  INT8_C(  98),  INT8_C( 110),
         INT8_C(   2),  INT8_C(  89), -INT8_C( 107),  INT8_C(  93), -INT8_C( 104), -INT8_C(  26),  INT8_C(   9),  INT8_C(  19),
         INT8_C(  77),      INT8_MAX, -INT8_C( 107), -INT8_C( 117),  INT8_C(  45),  INT8_C(  73),  INT8_C(   6),  INT8_C(  28),
        -INT8_C(  39),  INT8_C(  56), -INT8_C(  17),  INT8_C(  74),  INT8_C(  20), -INT8_C(  24),  INT8_C(  73),  INT8_C(  20),
        -INT8_C(  12), -INT8_C( 112), -INT8_C(  72),  INT8_C(  20),  INT8_C(  61),  INT8_C(  27), -INT8_C( 126),  INT8_C(  63),
         INT8_C( 116),  INT8_C(  23), -INT8_C( 100),  INT8_C(  13), -INT8_C(   2), -INT8_C(  90),  INT8_C(  32),  INT8_C(  75),
         INT8_C(  37), -INT8_C(  74), -INT8_C(  42),  INT8_C(  83), -INT8_C(   1), -INT8_C(  36),  INT8_C( 111), -INT8_C(  40),
         INT8_C(  21),  INT8_C(  94),  INT8_C(  35),  INT8_C(  41),  INT8_C(  70),  INT8_C( 108),  INT8_C(  61),  INT8_C(  58) },
      {  INT8_C(   0),  INT8_C(  12),  INT8_C(  71), -INT8_C(  92),  INT8_C(  32), -INT8_C(  83),  INT8_C(  98),  INT8_C( 110),
         INT8_C(   2),  INT8_C(  89), -INT8_C( 107),  INT8_C(  93), -INT8_C( 104), -INT8_C(  26),  INT8_C(   9),  INT8_C(  19),
         INT8_C(  77),      INT8_MAX, -INT8_C( 107), -INT8_C( 117),  INT8_C(  45),  INT8_C(  73),  INT8_C(   6),  INT8_C(  28),
        -INT8_C(  39),  INT8_C(  56), -INT8_C(  17),  INT8_C(  74),  INT8_C(  20), -INT8_C(  24),  INT8_C(  73),  INT8_C(  20),
        -INT8_C(  12), -INT8_C( 112), -INT8_C(  72),  INT8_C(  20),  INT8_C(  61),  INT8_C(  27), -INT8_C( 126),  INT8_C(  63),
         INT8_C( 116),  INT8_C(  23), -INT8_C( 100),  INT8_C(  13), -INT8_C(   2), -INT8_C(  90),  INT8_C(  32),  INT8_C(  75),
         INT8_C(  37), -INT8_C(  74), -INT8_C(  42),  INT8_C(  83), -INT8_C(   1), -INT8_C(  36),  INT8_C( 111), -INT8_C(  40),
         INT8_C(  21),  INT8_C(  94),  INT8_C(  35),  INT8_C(  41),  INT8_C(  70),  INT8_C( 108),  INT8_C(  61),  INT8_C(  58) } },
    { { -INT8_C(   4), -INT8_C(  11),  INT8_C(  78),  INT8_C(  58),  INT8_C(  16), -INT8_C(  48),  INT8_C( 121), -INT8_C( 123),
        -INT8_C(  24),  INT8_C(  22), -INT8_C( 110), -INT8_C(  26), -INT8_C(  68), -INT8_C(  78),  INT8_C(  49), -INT8_C(  31),
         INT8_C( 104),  INT8_C(   8),  INT8_C(  52),  INT8_C( 104), -INT8_C(  28), -INT8_C(  93),  INT8_C(  64), -INT8_C(   7),
         INT8_C(   2),  INT8_C(  99),  INT8_C(  34),  INT8_C(  72), -INT8_C(  49),  INT8_C(  95), -INT8_C( 125), -INT8_C(  52),
         INT8_C(  85), -INT8_C(  47),  INT8_C(   6),  INT8_C( 101), -INT8_C(  94),      INT8_MAX, -INT8_C(  22), -INT8_C( 118),
        -INT8_C( 107),  INT8_C( 124),  INT8_C( 112),  INT8_C(  81),  INT8_C(  47), -INT8_C(  95),  INT8_C(  51), -INT8_C( 105),
        -INT8_C(  87),  INT8_C( 103), -INT8_C(   1), -INT8_C( 114),  INT8_C(  11),  INT8_C(  64), -INT8_C( 121),  INT8_C(  13),
        -INT8_C(  93), -INT8_C(  86),  INT8_C(  85),  INT8_C( 115),  INT8_C(   9), -INT8_C(  40),  INT8_C(  63),  INT8_C(  94) },
      { -INT8_C(   4), -INT8_C(  11),  INT8_C(  78),  INT8_C(  58),  INT8_C(  16), -INT8_C(  48),  INT8_C( 121), -INT8_C( 123),
        -INT8_C(  24),  INT8_C(  22), -INT8_C( 110), -INT8_C(  26), -INT8_C(  68), -INT8_C(  78),  INT8_C(  49), -INT8_C(  31),
         INT8_C( 104),  INT8_C(   8),  INT8_C(  52),  INT8_C( 104), -INT8_C(  28), -INT8_C(  93),  INT8_C(  64), -INT8_C(   7),
         INT8_C(   2),  INT8_C(  99),  INT8_C(  34),  INT8_C(  72), -INT8_C(  49),  INT8_C(  95), -INT8_C( 125), -INT8_C(  52),
         INT8_C(  85), -INT8_C(  47),  INT8_C(   6),  INT8_C( 101), -INT8_C(  94),      INT8_MAX, -INT8_C(  22), -INT8_C( 118),
        -INT8_C( 107),  INT8_C( 124),  INT8_C( 112),  INT8_C(  81),  INT8_C(  47), -INT8_C(  95),  INT8_C(  51), -INT8_C( 105),
        -INT8_C(  87),  INT8_C( 103), -INT8_C(   1), -INT8_C( 114),  INT8_C(  11),  INT8_C(  64), -INT8_C( 121),  INT8_C(  13),
        -INT8_C(  93), -INT8_C(  86),  INT8_C(  85),  INT8_C( 115),  INT8_C(   9), -INT8_C(  40),  INT8_C(  63),  INT8_C(  94) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i r = simde_mm512_set_epi8(
        test_vec[i].a[63], test_vec[i].a[62], test_vec[i].a[61], test_vec[i].a[60],
        test_vec[i].a[59], test_vec[i].a[58], test_vec[i].a[57], test_vec[i].a[56],
        test_vec[i].a[55], test_vec[i].a[54], test_vec[i].a[53], test_vec[i].a[52],
        test_vec[i].a[51], test_vec[i].a[50], test_vec[i].a[49], test_vec[i].a[48],
        test_vec[i].a[47], test_vec[i].a[46], test_vec[i].a[45], test_vec[i].a[44],
        test_vec[i].a[43], test_vec[i].a[42], test_vec[i].a[41], test_vec[i].a[40],
        test_vec[i].a[39], test_vec[i].a[38], test_vec[i].a[37], test_vec[i].a[36],
        test_vec[i].a[35], test_vec[i].a[34], test_vec[i].a[33], test_vec[i].a[32],
        test_vec[i].a[31], test_vec[i].a[30], test_vec[i].a[29], test_vec[i].a[28],
        test_vec[i].a[27], test_vec[i].a[26], test_vec[i].a[25], test_vec[i].a[24],
        test_vec[i].a[23], test_vec[i].a[22], test_vec[i].a[21], test_vec[i].a[20],
        test_vec[i].a[19], test_vec[i].a[18], test_vec[i].a[17], test_vec[i].a[16],
        test_vec[i].a[15], test_vec[i].a[14], test_vec[i].a[13], test_vec[i].a[12],
        test_vec[i].a[11], test_vec[i].a[10], test_vec[i].a[ 9], test_vec[i].a[ 8],
        test_vec[i].a[ 7], test_vec[i].a[ 6], test_vec[i].a[ 5], test_vec[i].a[ 4],
        test_vec[i].a[ 3], test_vec[i].a[ 2], test_vec[i].a[ 1], test_vec[i].a[ 0]);
    simde_test_x86_assert_equal_i8x64(r, simde_mm512_loadu_epi8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m512i a = simde_test_x86_random_i8x64();
    simde__m512i r = a;

    simde_test_x86_write_i8x64(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i8x64(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_set_epi16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int16_t a[32];
    const int16_t r[32];
  } test_vec[] = {
    { {  INT16_C( 28208),  INT16_C( 11568), -INT16_C( 18520),  INT16_C( 32673), -INT16_C(  5618), -INT16_C( 32516), -INT16_C( 29675), -INT16_C( 30471),
        -INT16_C( 22650), -INT16_C( 27648), -INT16_C( 32156), -INT16_C( 14845), -INT16_C( 31076), -INT16_C(  2753), -INT16_C(  2052),  INT16_C( 11282),
         INT16_C( 17253),  INT16_C(  3418), -INT16_C(  1030),  INT16_C(  2188), -INT16_C( 30235), -INT16_C(  1144), -INT16_C( 32235), -INT16_C( 25469),
        -INT16_C( 31959), -INT16_C( 29392),  INT16_C( 13062), -INT16_C( 23981), -INT16_C( 27974), -INT16_C( 18793), -INT16_C( 21879), -INT16_C(  4125) },
      {  INT16_C( 28208),  INT16_C( 11568), -INT16_C( 18520),  INT16_C( 32673), -INT16_C(  5618), -INT16_C( 32516), -INT16_C( 29675), -INT16_C( 30471),
        -INT16_C( 22650), -INT16_C( 27648), -INT16_C( 32156), -INT16_C( 14845), -INT16_C( 31076), -INT16_C(  2753), -INT16_C(  2052),  INT16_C( 11282),
         INT16_C( 17253),  INT16_C(  3418), -INT16_C(  1030),  INT16_C(  2188), -INT16_C( 30235), -INT16_C(  1144), -INT16_C( 32235), -INT16_C( 25469),
        -INT16_C( 31959), -INT16_C( 29392),  INT16_C( 13062), -INT16_C( 23981), -INT16_C( 27974), -INT16_C( 18793), -INT16_C( 21879), -INT16_C(  4125) } },
    { {  INT16_C( 15853), -INT16_C(  6148), -INT16_C( 30408),  INT16_C(  7919),  INT16_C( 30482),  INT16_C( 10009), -INT16_C( 25351),  INT16_C(  8899),
        -INT16_C(  3296),  INT16_C(  9903),  INT16_C(   807), -INT16_C(  7736),  INT16_C( 24725),  INT16_C(  8087),  INT16_C( 31242), -INT16_C(  2290),
         INT16_C(  2743), -INT16_C(  3874), -INT16_C( 12909), -INT16_C( 23282),  INT16_C( 10052),  INT16_C( 16077), -INT16_C( 28477), -INT16_C(  7328),
         INT16_C(  4228), -INT16_C( 21751), -INT16_C( 11757), -INT16_C( 22388),  INT16_C(  9010),  INT16_C( 15559), -INT16_C( 10850),  INT16_C( 21811) },
      {  INT16_C( 15853), -INT16_C(  6148), -INT16_C( 30408),  INT16_C(  7919),  INT16_C( 30482),  INT16_C( 10009), -INT16_C( 25351),  INT16_C(  8899),
        -INT16_C(  3296),  INT16_C(  9903),  INT16_C(   807), -INT16_C(  7736),  INT16_C( 24725),  INT16_C(  8087),  INT16_C( 31242), -INT16_C(  2290),
         INT16_C(  2743), -INT16_C(  3874), -INT16_C( 12909), -INT16_C( 23282),  INT16_C( 10052),  INT16_C( 16077), -INT16_C( 28477), -INT16_C(  7328),
         INT16_C(  4228), -INT16_C( 21751), -INT16_C( 11757), -INT16_C( 22388),  INT16_C(  9010),  INT16_C( 15559), -INT16_C( 10850),  INT16_C( 21811) } },
    { {  INT16_C(  4576),  INT16_C( 29509),  INT16_C( 21470),  INT16_C(  8729), -INT16_C(  6534),  INT16_C( 15968), -INT16_C( 16010), -INT16_C(  1503),
         INT16_C( 11217), -INT16_C(  7003),  INT16_C( 12797),  INT16_C( 12172),  INT16_C( 21589), -INT16_C(  3221), -INT16_C( 25047),  INT16_C(  2376),
        -INT16_C( 29009), -INT16_C( 29315), -INT16_C( 26911),  INT16_C( 23727),  INT16_C(  4220), -INT16_C(  3430), -INT16_C( 17455), -INT16_C( 23827),
        -INT16_C( 27930), -INT16_C(  7290),  INT16_C(  4804),  INT16_C(  6418),  INT16_C( 32102), -INT16_C( 28660),  INT16_C( 21531), -INT16_C( 13671) },
      {  INT16_C(  4576),  INT16_C( 29509),  INT16_C( 21470),  INT16_C(  8729), -INT16_C(  6534),  INT16_C( 15968), -INT16_C( 16010), -INT16_C(  1503),
         INT16_C( 11217), -INT16_C(  7003),  INT16_C( 12797),  INT16_C( 12172),  INT16_C( 21589), -INT16_C(  3221), -INT16_C( 25047),  INT16_C(  2376),
        -INT16_C( 29009), -INT16_C( 29315), -INT16_C( 26911),  INT16_C( 23727),  INT16_C(  4220), -INT16_C(  3430), -INT16_C( 17455), -INT16_C( 23827),
        -INT16_C( 27930), -INT16_C(  7290),  INT16_C(  4804),  INT16_C(  6418),  INT16_C( 32102), -INT16_C( 28660),  INT16_C( 21531), -INT16_C( 13671) } },
    { {  INT16_C(  5858), -INT16_C( 15273),  INT16_C(  1964),  INT16_C( 10272), -INT16_C( 17897), -INT16_C(  6117),  INT16_C(  2165),  INT16_C( 23690),
         INT16_C(  4250),  INT16_C( 24127),  INT16_C( 21026), -INT16_C( 30345), -INT16_C( 31793), -INT16_C(  5351), -INT16_C( 19752), -INT16_C( 17739),
         INT16_C(  3529),  INT16_C( 30078), -INT16_C( 25068),  INT16_C( 11166), -INT16_C( 18088), -INT16_C( 12781), -INT16_C( 25151),  INT16_C( 23338),
         INT16_C( 27053), -INT16_C( 12358),  INT16_C( 12731), -INT16_C( 29864),  INT16_C( 29109), -INT16_C( 29322),  INT16_C( 11044), -INT16_C(  4793) },
      {  INT16_C(  5858), -INT16_C( 15273),  INT16_C(  1964),  INT16_C( 10272), -INT16_C( 17897), -INT16_C(  6117),  INT16_C(  2165),  INT16_C( 23690),
         INT16_C(  4250),  INT16_C( 24127),  INT16_C( 21026), -INT16_C( 30345), -INT16_C( 31793), -INT16_C(  5351), -INT16_C( 19752), -INT16_C( 17739),
         INT16_C(  3529),  INT16_C( 30078), -INT16_C( 25068),  INT16_C( 11166), -INT16_C( 18088), -INT16_C( 12781), -INT16_C( 25151),  INT16_C( 23338),
         INT16_C( 27053), -INT16_C( 12358),  INT16_C( 12731), -INT16_C( 29864),  INT16_C( 29109), -INT16_C( 29322),  INT16_C( 11044), -INT16_C(  4793) } },
    { { -INT16_C( 14792),  INT16_C( 19554),  INT16_C(   100), -INT16_C( 17033), -INT16_C( 30023),  INT16_C( 31371), -INT16_C( 19161), -INT16_C( 11050),
        -INT16_C( 28642), -INT16_C(  9564), -INT16_C(   831),  INT16_C( 30309), -INT16_C(  9362), -INT16_C( 28157),  INT16_C( 19206),  INT16_C( 16255),
        -INT16_C(  7919),  INT16_C( 30091),  INT16_C(   994), -INT16_C( 25806), -INT16_C( 17011), -INT16_C( 19178), -INT16_C(  5006), -INT16_C( 28279),
         INT16_C( 11644),  INT16_C( 15723), -INT16_C( 12246), -INT16_C( 26444), -INT16_C( 18517), -INT16_C( 20182), -INT16_C( 22270),  INT16_C(  5104) },
      { -INT16_C( 14792),  INT16_C( 19554),  INT16_C(   100), -INT16_C( 17033), -INT16_C( 30023),  INT16_C( 31371), -INT16_C( 19161), -INT16_C( 11050),
        -INT16_C( 28642), -INT16_C(  9564), -INT16_C(   831),  INT16_C( 30309), -INT16_C(  9362), -INT16_C( 28157),  INT16_C( 19206),  INT16_C( 16255),
        -INT16_C(  7919),  INT16_C( 30091),  INT16_C(   994), -INT16_C( 25806), -INT16_C( 17011), -INT16_C( 19178), -INT16_C(  5006), -INT16_C( 28279),
         INT16_C( 11644),  INT16_C( 15723), -INT16_C( 12246), -INT16_C( 26444), -INT16_C( 18517), -INT16_C( 20182), -INT16_C( 22270),  INT16_C(  5104) } },
    { {  INT16_C( 31882),  INT16_C( 27785), -INT16_C( 17537),  INT16_C(  3080),  INT16_C(  7801), -INT16_C(  5183),  INT16_C( 19210), -INT16_C( 31108),
        -INT16_C(  6280), -INT16_C( 23869),  INT16_C( 30647),  INT16_C( 25146),  INT16_C( 25647),  INT16_C( 12564),  INT16_C(  1037), -INT16_C( 26555),
        -INT16_C( 12672), -INT16_C(   252),  INT16_C(  3209),  INT16_C(   524), -INT16_C( 13014),  INT16_C( 13550),  INT16_C( 27160), -INT16_C( 28230),
         INT16_C( 32338),  INT16_C(  2355),  INT16_C( 28405),  INT16_C(  9324), -INT16_C( 32558), -INT16_C(  8106), -INT16_C( 25724),  INT16_C(  1400) },
      {  INT16_C( 31882),  INT16_C( 27785), -INT16_C( 17537),  INT16_C(  3080),  INT16_C(  7801), -INT16_C(  5183),  INT16_C( 19210), -INT16_C( 31108),
        -INT16_C(  6280), -INT16_C( 23869),  INT16_C( 30647),  INT16_C( 25146),  INT16_C( 25647),  INT16_C( 12564),  INT16_C(  1037), -INT16_C( 26555),
        -INT16_C( 12672), -INT16_C(   252),  INT16_C(  3209),  INT16_C(   524), -INT16_C( 13014),  INT16_C( 13550),  INT16_C( 27160), -INT16_C( 28230),
         INT16_C( 32338),  INT16_C(  2355),  INT16_C( 28405),  INT16_C(  9324), -INT16_C( 32558), -INT16_C(  8106), -INT16_C( 25724),  INT16_C(  1400) } },
    { {  INT16_C( 31849), -INT16_C(  3580),  INT16_C(  4233), -INT16_C( 19467), -INT16_C(  7202), -INT16_C(  2328), -INT16_C( 23987), -INT16_C( 24697),
        -INT16_C( 17632),  INT16_C(  5801),  INT16_C(  5417), -INT16_C(  1222), -INT16_C( 28523),  INT16_C(  6619),  INT16_C( 21291), -INT16_C( 27618),
         INT16_C(  9168),  INT16_C( 22919),  INT16_C( 31795),  INT16_C(  4364), -INT16_C(  2977), -INT16_C( 21496), -INT16_C( 28777), -INT16_C( 18612),
        -INT16_C(  2742),  INT16_C( 29645),  INT16_C(  2058), -INT16_C( 24721),  INT16_C( 19096), -INT16_C( 15176), -INT16_C( 10338),  INT16_C( 28248) },
      {  INT16_C( 31849), -INT16_C(  3580),  INT16_C(  4233), -INT16_C( 19467), -INT16_C(  7202), -INT16_C(  2328), -INT16_C( 23987), -INT16_C( 24697),
        -INT16_C( 17632),  INT16_C(  5801),  INT16_C(  5417), -INT16_C(  1222), -INT16_C( 28523),  INT16_C(  6619),  INT16_C( 21291), -INT16_C( 27618),
         INT16_C(  9168),  INT16_C( 22919),  INT16_C( 31795),  INT16_C(  4364), -INT16_C(  2977), -INT16_C( 21496), -INT16_C( 28777), -INT16_C( 18612),
        -INT16_C(  2742),  INT16_C( 29645),  INT16_C(  2058), -INT16_C( 24721),  INT16_C( 19096), -INT16_C( 15176), -INT16_C( 10338),  INT16_C( 28248) } },
    { { -INT16_C(  8198),  INT16_C( 11719), -INT16_C( 11429), -INT16_C( 17857),  INT16_C( 18376),  INT16_C( 24423), -INT16_C( 19498),  INT16_C(  8470),
        -INT16_C(  7000), -INT16_C( 19820),  INT16_C(  1004), -INT16_C( 31663),  INT16_C(  2382), -INT16_C(  5048), -INT16_C( 24096), -INT16_C(  9638),
         INT16_C(  8576), -INT16_C(  9208),  INT16_C( 18420), -INT16_C( 17258), -INT16_C(   626),  INT16_C( 25627),  INT16_C( 12976),  INT16_C( 22661),
         INT16_C(  6678),  INT16_C(   522),  INT16_C( 23325),  INT16_C( 27526), -INT16_C( 12443),  INT16_C( 17751), -INT16_C( 20112), -INT16_C(  4064) },
      { -INT16_C(  8198),  INT16_C( 11719), -INT16_C( 11429), -INT16_C( 17857),  INT16_C( 18376),  INT16_C( 24423), -INT16_C( 19498),  INT16_C(  8470),
        -INT16_C(  7000), -INT16_C( 19820),  INT16_C(  1004), -INT16_C( 31663),  INT16_C(  2382), -INT16_C(  5048), -INT16_C( 24096), -INT16_C(  9638),
         INT16_C(  8576), -INT16_C(  9208),  INT16_C( 18420), -INT16_C( 17258), -INT16_C(   626),  INT16_C( 25627),  INT16_C( 12976),  INT16_C( 22661),
         INT16_C(  6678),  INT16_C(   522),  INT16_C( 23325),  INT16_C( 27526), -INT16_C( 12443),  INT16_C( 17751), -INT16_C( 20112), -INT16_C(  4064) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i r = simde_mm512_set_epi16(
        test_vec[i].a[31], test_vec[i].a[30], test_vec[i].a[29], test_vec[i].a[28],
        test_vec[i].a[27], test_vec[i].a[26], test_vec[i].a[25], test_vec[i].a[24],
        test_vec[i].a[23], test_vec[i].a[22], test_vec[i].a[21], test_vec[i].a[20],
        test_vec[i].a[19], test_vec[i].a[18], test_vec[i].a[17], test_vec[i].a[16],
        test_vec[i].a[15], test_vec[i].a[14], test_vec[i].a[13], test_vec[i].a[12],
        test_vec[i].a[11], test_vec[i].a[10], test_vec[i].a[ 9], test_vec[i].a[ 8],
        test_vec[i].a[ 7], test_vec[i].a[ 6], test_vec[i].a[ 5], test_vec[i].a[ 4],
        test_vec[i].a[ 3], test_vec[i].a[ 2], test_vec[i].a[ 1], test_vec[i].a[ 0]);
    simde_test_x86_assert_equal_i16x32(r, simde_mm512_loadu_epi16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m512i a = simde_test_x86_random_i16x32();
    simde__m512i r = a;

    simde_test_x86_write_i16x32(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i16x32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_set_epi32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int32_t a[16];
    const int32_t r[16];
  } test_vec[] = {
    { { -INT32_C(   718084918), -INT32_C(  1447421420),  INT32_C(  1848496256),  INT32_C(   279896686), -INT32_C(  1716299902),  INT32_C(   757651794), -INT32_C(   612291898), -INT32_C(  2021453635),
         INT32_C(   140293876),  INT32_C(  1353783248),  INT32_C(  1438572519),  INT32_C(  1130785985),  INT32_C(   366746051), -INT32_C(  1186789901), -INT32_C(   325794769), -INT32_C(   931981100) },
      { -INT32_C(   718084918), -INT32_C(  1447421420),  INT32_C(  1848496256),  INT32_C(   279896686), -INT32_C(  1716299902),  INT32_C(   757651794), -INT32_C(   612291898), -INT32_C(  2021453635),
         INT32_C(   140293876),  INT32_C(  1353783248),  INT32_C(  1438572519),  INT32_C(  1130785985),  INT32_C(   366746051), -INT32_C(  1186789901), -INT32_C(   325794769), -INT32_C(   931981100) } },
    { { -INT32_C(  1630416690), -INT32_C(   823229721),  INT32_C(   589605985), -INT32_C(   614036968), -INT32_C(  1762638941),  INT32_C(  2001679176), -INT32_C(   865868552), -INT32_C(   896149764),
        -INT32_C(  1922537818),  INT32_C(  1247565544),  INT32_C(   443383810), -INT32_C(  1376398582),  INT32_C(  1581573398),  INT32_C(   299209497),  INT32_C(  1943877751), -INT32_C(  1254264305) },
      { -INT32_C(  1630416690), -INT32_C(   823229721),  INT32_C(   589605985), -INT32_C(   614036968), -INT32_C(  1762638941),  INT32_C(  2001679176), -INT32_C(   865868552), -INT32_C(   896149764),
        -INT32_C(  1922537818),  INT32_C(  1247565544),  INT32_C(   443383810), -INT32_C(  1376398582),  INT32_C(  1581573398),  INT32_C(   299209497),  INT32_C(  1943877751), -INT32_C(  1254264305) } },
    { { -INT32_C(  1052531240), -INT32_C(    49569797),  INT32_C(   689403935),  INT32_C(  1658195019),  INT32_C(   197139186),  INT32_C(   622630574), -INT32_C(   577111602),  INT32_C(  1150539372),
         INT32_C(  1996871292), -INT32_C(  1804267403), -INT32_C(   725775224), -INT32_C(  1959357543),  INT32_C(  1553397422),  INT32_C(  1535226508),  INT32_C(   389552811),  INT32_C(  1834798065) },
      { -INT32_C(  1052531240), -INT32_C(    49569797),  INT32_C(   689403935),  INT32_C(  1658195019),  INT32_C(   197139186),  INT32_C(   622630574), -INT32_C(   577111602),  INT32_C(  1150539372),
         INT32_C(  1996871292), -INT32_C(  1804267403), -INT32_C(   725775224), -INT32_C(  1959357543),  INT32_C(  1553397422),  INT32_C(  1535226508),  INT32_C(   389552811),  INT32_C(  1834798065) } },
    { {  INT32_C(   384065953), -INT32_C(    89499278),  INT32_C(  2144233446), -INT32_C(  1458961157), -INT32_C(  2029674245), -INT32_C(    35486126), -INT32_C(  1844110431), -INT32_C(  1996525082),
         INT32_C(  1151263698),  INT32_C(   591350077), -INT32_C(  1415443024),  INT32_C(   223652882), -INT32_C(  1634444980), -INT32_C(  2120517664),  INT32_C(  2014556306), -INT32_C(   201321951) },
      {  INT32_C(   384065953), -INT32_C(    89499278),  INT32_C(  2144233446), -INT32_C(  1458961157), -INT32_C(  2029674245), -INT32_C(    35486126), -INT32_C(  1844110431), -INT32_C(  1996525082),
         INT32_C(  1151263698),  INT32_C(   591350077), -INT32_C(  1415443024),  INT32_C(   223652882), -INT32_C(  1634444980), -INT32_C(  2120517664),  INT32_C(  2014556306), -INT32_C(   201321951) } },
    { {  INT32_C(   842571765), -INT32_C(  1739229208), -INT32_C(  1757087867), -INT32_C(   274425693), -INT32_C(   762496782),  INT32_C(  1095969199), -INT32_C(    71670055),  INT32_C(  1844427384),
         INT32_C(  1101014873),  INT32_C(   618329503), -INT32_C(  1866785043), -INT32_C(  1467981898),  INT32_C(  1199181207),  INT32_C(   277400886), -INT32_C(  1425325517),  INT32_C(  1444543229) },
      {  INT32_C(   842571765), -INT32_C(  1739229208), -INT32_C(  1757087867), -INT32_C(   274425693), -INT32_C(   762496782),  INT32_C(  1095969199), -INT32_C(    71670055),  INT32_C(  1844427384),
         INT32_C(  1101014873),  INT32_C(   618329503), -INT32_C(  1866785043), -INT32_C(  1467981898),  INT32_C(  1199181207),  INT32_C(   277400886), -INT32_C(  1425325517),  INT32_C(  1444543229) } },
    { { -INT32_C(  1063732959), -INT32_C(  1679527250),  INT32_C(  1177329552), -INT32_C(  1762677506), -INT32_C(   253924935),  INT32_C(  1778410807), -INT32_C(  1525281880),  INT32_C(   653995781),
        -INT32_C(  1763208216), -INT32_C(  1791833339),  INT32_C(  1776049771), -INT32_C(  1006646518),  INT32_C(  1806949428), -INT32_C(   355028158), -INT32_C(  1013977922),  INT32_C(    65702427) },
      { -INT32_C(  1063732959), -INT32_C(  1679527250),  INT32_C(  1177329552), -INT32_C(  1762677506), -INT32_C(   253924935),  INT32_C(  1778410807), -INT32_C(  1525281880),  INT32_C(   653995781),
        -INT32_C(  1763208216), -INT32_C(  1791833339),  INT32_C(  1776049771), -INT32_C(  1006646518),  INT32_C(  1806949428), -INT32_C(   355028158), -INT32_C(  1013977922),  INT32_C(    65702427) } },
    { {  INT32_C(   597283102),  INT32_C(   129616796),  INT32_C(   863081769), -INT32_C(  1795723168), -INT32_C(  1895781811),  INT32_C(   477746782), -INT32_C(   572520254), -INT32_C(  1327445358),
         INT32_C(   936671643),  INT32_C(  1849658693), -INT32_C(  2103267294),  INT32_C(  1830197536), -INT32_C(  1577314749), -INT32_C(  1363249684),  INT32_C(   277585533),  INT32_C(    62942056) },
      {  INT32_C(   597283102),  INT32_C(   129616796),  INT32_C(   863081769), -INT32_C(  1795723168), -INT32_C(  1895781811),  INT32_C(   477746782), -INT32_C(   572520254), -INT32_C(  1327445358),
         INT32_C(   936671643),  INT32_C(  1849658693), -INT32_C(  2103267294),  INT32_C(  1830197536), -INT32_C(  1577314749), -INT32_C(  1363249684),  INT32_C(   277585533),  INT32_C(    62942056) } },
    { {  INT32_C(   708482277),  INT32_C(  1134065953),  INT32_C(  1254439465),  INT32_C(   397925587), -INT32_C(   541543182), -INT32_C(  1483901399),  INT32_C(  2092374292),  INT32_C(  1769961348),
         INT32_C(   764656140),  INT32_C(  1567697971),  INT32_C(   984036966),  INT32_C(    89218578),  INT32_C(  1021577490), -INT32_C(  1797033600),  INT32_C(   252811914),  INT32_C(   494440465) },
      {  INT32_C(   708482277),  INT32_C(  1134065953),  INT32_C(  1254439465),  INT32_C(   397925587), -INT32_C(   541543182), -INT32_C(  1483901399),  INT32_C(  2092374292),  INT32_C(  1769961348),
         INT32_C(   764656140),  INT32_C(  1567697971),  INT32_C(   984036966),  INT32_C(    89218578),  INT32_C(  1021577490), -INT32_C(  1797033600),  INT32_C(   252811914),  INT32_C(   494440465) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i r = simde_mm512_set_epi32(
        test_vec[i].a[15], test_vec[i].a[14], test_vec[i].a[13], test_vec[i].a[12],
        test_vec[i].a[11], test_vec[i].a[10], test_vec[i].a[ 9], test_vec[i].a[ 8],
        test_vec[i].a[ 7], test_vec[i].a[ 6], test_vec[i].a[ 5], test_vec[i].a[ 4],
        test_vec[i].a[ 3], test_vec[i].a[ 2], test_vec[i].a[ 1], test_vec[i].a[ 0]);
    simde_test_x86_assert_equal_i32x16(r, simde_mm512_loadu_epi32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m512i a = simde_test_x86_random_i32x16();
    simde__m512i r = a;

    simde_test_x86_write_i32x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_set_epi64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int64_t a[8];
    const int64_t r[8];
  } test_vec[] = {
    { {  INT64_C( 7416271910326683854), -INT64_C( 4897747652392899789),  INT64_C( 6856628829737554158), -INT64_C( 2150993203686264898),
        -INT64_C(  552480653107076628), -INT64_C( 7597675204674063523),  INT64_C( 2749860335145960499),  INT64_C( 4150965691438738086) },
      {  INT64_C( 7416271910326683854), -INT64_C( 4897747652392899789),  INT64_C( 6856628829737554158), -INT64_C( 2150993203686264898),
        -INT64_C(  552480653107076628), -INT64_C( 7597675204674063523),  INT64_C( 2749860335145960499),  INT64_C( 4150965691438738086) } },
    { {  INT64_C( 8129134851571376658),  INT64_C( 4732951216391416688),  INT64_C( 1883688221230759318),  INT64_C( 8207088352664759902),
        -INT64_C(  300305717954802351), -INT64_C( 9091710009513666428),  INT64_C( 8164361002356301502), -INT64_C( 2116124952781577775) },
      {  INT64_C( 8129134851571376658),  INT64_C( 4732951216391416688),  INT64_C( 1883688221230759318),  INT64_C( 8207088352664759902),
        -INT64_C(  300305717954802351), -INT64_C( 9091710009513666428),  INT64_C( 8164361002356301502), -INT64_C( 2116124952781577775) } },
    { { -INT64_C( 8532600538384569584),  INT64_C( 2927884471851788597), -INT64_C( 7758952549258157875), -INT64_C( 8989632965809705014),
        -INT64_C( 2818773282401122989), -INT64_C( 5048647419307688867), -INT64_C( 4751038171580904519), -INT64_C( 7975777913320843685) },
      { -INT64_C( 8532600538384569584),  INT64_C( 2927884471851788597), -INT64_C( 7758952549258157875), -INT64_C( 8989632965809705014),
        -INT64_C( 2818773282401122989), -INT64_C( 5048647419307688867), -INT64_C( 4751038171580904519), -INT64_C( 7975777913320843685) } },
    { {  INT64_C( 9176306490307866333), -INT64_C( 6743235639710953273),  INT64_C( 5418726386948769153), -INT64_C( 8947410401178858236),
         INT64_C( 5726990520023236056),  INT64_C( 8590174245068325035), -INT64_C( 8669956488264133518),  INT64_C(  618854828626003821) },
      {  INT64_C( 9176306490307866333), -INT64_C( 6743235639710953273),  INT64_C( 5418726386948769153), -INT64_C( 8947410401178858236),
         INT64_C( 5726990520023236056),  INT64_C( 8590174245068325035), -INT64_C( 8669956488264133518),  INT64_C(  618854828626003821) } },
    { { -INT64_C( 6975374382109320869),  INT64_C( 1345285050491679549),  INT64_C( 2721902299037669565), -INT64_C( 8636832967257714454),
        -INT64_C( 2235300940097051033),  INT64_C( 6018146754448600529),  INT64_C(  447361715065321816), -INT64_C( 6584470204827275543) },
      { -INT64_C( 6975374382109320869),  INT64_C( 1345285050491679549),  INT64_C( 2721902299037669565), -INT64_C( 8636832967257714454),
        -INT64_C( 2235300940097051033),  INT64_C( 6018146754448600529),  INT64_C(  447361715065321816), -INT64_C( 6584470204827275543) } },
    { {  INT64_C( 8785954047749196649),  INT64_C( 1806347803474723111), -INT64_C( 1762490757418474392),  INT64_C( 6317880597477763789),
        -INT64_C( 3545650502557192791), -INT64_C( 8273783058313988526), -INT64_C( 8995769048611334334),  INT64_C( 7893467386249750085) },
      {  INT64_C( 8785954047749196649),  INT64_C( 1806347803474723111), -INT64_C( 1762490757418474392),  INT64_C( 6317880597477763789),
        -INT64_C( 3545650502557192791), -INT64_C( 8273783058313988526), -INT64_C( 8995769048611334334),  INT64_C( 7893467386249750085) } },
    { { -INT64_C( 7900287636437209113), -INT64_C( 3894817049730946752), -INT64_C( 2061467071467093205),  INT64_C( 1264000947191279704),
         INT64_C( 1397238296100161937),  INT64_C(  663554023642106597), -INT64_C( 3823751311176089747),  INT64_C( 4141747775465784894) },
      { -INT64_C( 7900287636437209113), -INT64_C( 3894817049730946752), -INT64_C( 2061467071467093205),  INT64_C( 1264000947191279704),
         INT64_C( 1397238296100161937),  INT64_C(  663554023642106597), -INT64_C( 3823751311176089747),  INT64_C( 4141747775465784894) } },
    { { -INT64_C(  314569080322778437), -INT64_C(  982175572242785673), -INT64_C( 3091741389357168420),  INT64_C( 3158352032474005235),
        -INT64_C( 4331518035015115054), -INT64_C( 4328671828599354762), -INT64_C( 3806904150389625921), -INT64_C(  810302542018352858) },
      { -INT64_C(  314569080322778437), -INT64_C(  982175572242785673), -INT64_C( 3091741389357168420),  INT64_C( 3158352032474005235),
        -INT64_C( 4331518035015115054), -INT64_C( 4328671828599354762), -INT64_C( 3806904150389625921), -INT64_C(  810302542018352858) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i r = simde_mm512_set_epi64(
        test_vec[i].a[ 7], test_vec[i].a[ 6], test_vec[i].a[ 5], test_vec[i].a[ 4],
        test_vec[i].a[ 3], test_vec[i].a[ 2], test_vec[i].a[ 1], test_vec[i].a[ 0]);
    simde_test_x86_assert_equal_i64x8(r, simde_mm512_loadu_epi64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m512i a = simde_test_x86_random_i64x8();
    simde__m512i r = a;

    simde_test_x86_write_i64x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i64x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_set_pd (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde_float64 a[8];
    const simde_float64 r[8];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(   670.56), SIMDE_FLOAT64_C(   769.83), SIMDE_FLOAT64_C(   452.75), SIMDE_FLOAT64_C(  -321.12),
        SIMDE_FLOAT64_C(   540.94), SIMDE_FLOAT64_C(  -744.39), SIMDE_FLOAT64_C(  -392.02), SIMDE_FLOAT64_C(  -608.21) },
      { SIMDE_FLOAT64_C(   670.56), SIMDE_FLOAT64_C(   769.83), SIMDE_FLOAT64_C(   452.75), SIMDE_FLOAT64_C(  -321.12),
        SIMDE_FLOAT64_C(   540.94), SIMDE_FLOAT64_C(  -744.39), SIMDE_FLOAT64_C(  -392.02), SIMDE_FLOAT64_C(  -608.21) } },
    { { SIMDE_FLOAT64_C(  -346.44), SIMDE_FLOAT64_C(  -787.69), SIMDE_FLOAT64_C(    30.52), SIMDE_FLOAT64_C(  -179.08),
        SIMDE_FLOAT64_C(   272.54), SIMDE_FLOAT64_C(  -636.81), SIMDE_FLOAT64_C(   543.83), SIMDE_FLOAT64_C(   519.44) },
      { SIMDE_FLOAT64_C(  -346.44), SIMDE_FLOAT64_C(  -787.69), SIMDE_FLOAT64_C(    30.52), SIMDE_FLOAT64_C(  -179.08),
        SIMDE_FLOAT64_C(   272.54), SIMDE_FLOAT64_C(  -636.81), SIMDE_FLOAT64_C(   543.83), SIMDE_FLOAT64_C(   519.44) } },
    { { SIMDE_FLOAT64_C(  -541.32), SIMDE_FLOAT64_C(   265.86), SIMDE_FLOAT64_C(   389.70), SIMDE_FLOAT64_C(   719.33),
        SIMDE_FLOAT64_C(   489.83), SIMDE_FLOAT64_C(   260.51), SIMDE_FLOAT64_C(   233.90), SIMDE_FLOAT64_C(  -892.98) },
      { SIMDE_FLOAT64_C(  -541.32), SIMDE_FLOAT64_C(   265.86), SIMDE_FLOAT64_C(   389.70), SIMDE_FLOAT64_C(   719.33),
        SIMDE_FLOAT64_C(   489.83), SIMDE_FLOAT64_C(   260.51), SIMDE_FLOAT64_C(   233.90), SIMDE_FLOAT64_C(  -892.98) } },
    { { SIMDE_FLOAT64_C(   -45.07), SIMDE_FLOAT64_C(   174.26), SIMDE_FLOAT64_C(   220.48), SIMDE_FLOAT64_C(   233.05),
        SIMDE_FLOAT64_C(  -537.78), SIMDE_FLOAT64_C(  -609.38), SIMDE_FLOAT64_C(  -208.27), SIMDE_FLOAT64_C(  -867.22) },
      { SIMDE_FLOAT64_C(   -45.07), SIMDE_FLOAT64_C(   174.26), SIMDE_FLOAT64_C(   220.48), SIMDE_FLOAT64_C(   233.05),
        SIMDE_FLOAT64_C(  -537.78), SIMDE_FLOAT64_C(  -609.38), SIMDE_FLOAT64_C(  -208.27), SIMDE_FLOAT64_C(  -867.22) } },
    { { SIMDE_FLOAT64_C(  -839.55), SIMDE_FLOAT64_C(  -755.53), SIMDE_FLOAT64_C(  -188.34), SIMDE_FLOAT64_C(   701.40),
        SIMDE_FLOAT64_C(  -499.92), SIMDE_FLOAT64_C(   419.64), SIMDE_FLOAT64_C(  -906.81), SIMDE_FLOAT64_C(   153.65) },
      { SIMDE_FLOAT64_C(  -839.55), SIMDE_FLOAT64_C(  -755.53), SIMDE_FLOAT64_C(  -188.34), SIMDE_FLOAT64_C(   701.40),
        SIMDE_FLOAT64_C(  -499.92), SIMDE_FLOAT64_C(   419.64), SIMDE_FLOAT64_C(  -906.81), SIMDE_FLOAT64_C(   153.65) } },
    { { SIMDE_FLOAT64_C(   631.95), SIMDE_FLOAT64_C(   123.71), SIMDE_FLOAT64_C(   974.57), SIMDE_FLOAT64_C(   -95.51),
        SIMDE_FLOAT64_C(   486.89), SIMDE_FLOAT64_C(   518.40), SIMDE_FLOAT64_C(  -576.07), SIMDE_FLOAT64_C(   945.58) },
      { SIMDE_FLOAT64_C(   631.95), SIMDE_FLOAT64_C(   123.71), SIMDE_FLOAT64_C(   974.57), SIMDE_FLOAT64_C(   -95.51),
        SIMDE_FLOAT64_C(   486.89), SIMDE_FLOAT64_C(   518.40), SIMDE_FLOAT64_C(  -576.07), SIMDE_FLOAT64_C(   945.58) } },
    { { SIMDE_FLOAT64_C(  -215.73), SIMDE_FLOAT64_C(   813.63), SIMDE_FLOAT64_C(   664.91), SIMDE_FLOAT64_C(  -725.90),
        SIMDE_FLOAT64_C(    74.14), SIMDE_FLOAT64_C(  -101.19), SIMDE_FLOAT64_C(  -618.88), SIMDE_FLOAT64_C(  -970.94) },
      { SIMDE_FLOAT64_C(  -215.73), SIMDE_FLOAT64_C(   813.63), SIMDE_FLOAT64_C(   664.91), SIMDE_FLOAT64_C(  -725.90),
        SIMDE_FLOAT64_C(    74.14), SIMDE_FLOAT64_C(  -101.19), SIMDE_FLOAT64_C(  -618.88), SIMDE_FLOAT64_C(  -970.94) } },
    { { SIMDE_FLOAT64_C(  -926.93), SIMDE_FLOAT64_C(   601.60), SIMDE_FLOAT64_C(   262.11), SIMDE_FLOAT64_C(  -464.71),
        SIMDE_FLOAT64_C(   992.22), SIMDE_FLOAT64_C(  -946.16), SIMDE_FLOAT64_C(  -331.93), SIMDE_FLOAT64_C(  -847.32) },
      { SIMDE_FLOAT64_C(  -926.93), SIMDE_FLOAT64_C(   601.60), SIMDE_FLOAT64_C(   262.11), SIMDE_FLOAT64_C(  -464.71),
        SIMDE_FLOAT64_C(   992.22), SIMDE_FLOAT64_C(  -946.16), SIMDE_FLOAT64_C(  -331.93), SIMDE_FLOAT64_C(  -847.32) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512d r = simde_mm512_set_pd(
        test_vec[i].a[ 7], test_vec[i].a[ 6], test_vec[i].a[ 5], test_vec[i].a[ 4],
        test_vec[i].a[ 3], test_vec[i].a[ 2], test_vec[i].a[ 1], test_vec[i].a[ 0]);
    simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m512d a = simde_test_x86_random_f64x8(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde__m512d r = a;

    simde_test_x86_write_f64x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f64x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_set_ps (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde_float32 a[16];
    const simde_float32 r[16];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(  -967.45), SIMDE_FLOAT32_C(   555.14), SIMDE_FLOAT32_C(   395.62), SIMDE_FLOAT32_C(   646.95),
        SIMDE_FLOAT32_C(    -7.99), SIMDE_FLOAT32_C(  -159.39), SIMDE_FLOAT32_C(  -204.24), SIMDE_FLOAT32_C(    19.62),
        SIMDE_FLOAT32_C(   980.65), SIMDE_FLOAT32_C(  -174.06), SIMDE_FLOAT32_C(  -131.07), SIMDE_FLOAT32_C(   -28.25),
        SIMDE_FLOAT32_C(  -768.63), SIMDE_FLOAT32_C(   553.54), SIMDE_FLOAT32_C(   497.97), SIMDE_FLOAT32_C(  -142.92) },
      { SIMDE_FLOAT32_C(  -967.45), SIMDE_FLOAT32_C(   555.14), SIMDE_FLOAT32_C(   395.62), SIMDE_FLOAT32_C(   646.95),
        SIMDE_FLOAT32_C(    -7.99), SIMDE_FLOAT32_C(  -159.39), SIMDE_FLOAT32_C(  -204.24), SIMDE_FLOAT32_C(    19.62),
        SIMDE_FLOAT32_C(   980.65), SIMDE_FLOAT32_C(  -174.06), SIMDE_FLOAT32_C(  -131.07), SIMDE_FLOAT32_C(   -28.25),
        SIMDE_FLOAT32_C(  -768.63), SIMDE_FLOAT32_C(   553.54), SIMDE_FLOAT32_C(   497.97), SIMDE_FLOAT32_C(  -142.92) } },
    { { SIMDE_FLOAT32_C(   -51.14), SIMDE_FLOAT32_C(    28.70), SIMDE_FLOAT32_C(  -598.25), SIMDE_FLOAT32_C(   911.70),
        SIMDE_FLOAT32_C(  -905.59), SIMDE_FLOAT32_C(   815.98), SIMDE_FLOAT32_C(  -798.54), SIMDE_FLOAT32_C(  -677.94),
        SIMDE_FLOAT32_C(   697.56), SIMDE_FLOAT32_C(  -111.92), SIMDE_FLOAT32_C(  -783.66), SIMDE_FLOAT32_C(   226.91),
        SIMDE_FLOAT32_C(  -846.01), SIMDE_FLOAT32_C(   293.51), SIMDE_FLOAT32_C(    37.49), SIMDE_FLOAT32_C(  -813.46) },
      { SIMDE_FLOAT32_C(   -51.14), SIMDE_FLOAT32_C(    28.70), SIMDE_FLOAT32_C(  -598.25), SIMDE_FLOAT32_C(   911.70),
        SIMDE_FLOAT32_C(  -905.59), SIMDE_FLOAT32_C(   815.98), SIMDE_FLOAT32_C(  -798.54), SIMDE_FLOAT32_C(  -677.94),
        SIMDE_FLOAT32_C(   697.56), SIMDE_FLOAT32_C(  -111.92), SIMDE_FLOAT32_C(  -783.66), SIMDE_FLOAT32_C(   226.91),
        SIMDE_FLOAT32_C(  -846.01), SIMDE_FLOAT32_C(   293.51), SIMDE_FLOAT32_C(    37.49), SIMDE_FLOAT32_C(  -813.46) } },
    { { SIMDE_FLOAT32_C(  -151.35), SIMDE_FLOAT32_C(  -566.88), SIMDE_FLOAT32_C(   833.49), SIMDE_FLOAT32_C(   840.66),
        SIMDE_FLOAT32_C(   273.73), SIMDE_FLOAT32_C(  -370.75), SIMDE_FLOAT32_C(  -139.72), SIMDE_FLOAT32_C(   254.38),
        SIMDE_FLOAT32_C(   455.19), SIMDE_FLOAT32_C(   729.21), SIMDE_FLOAT32_C(  -773.88), SIMDE_FLOAT32_C(   686.56),
        SIMDE_FLOAT32_C(   282.75), SIMDE_FLOAT32_C(   724.10), SIMDE_FLOAT32_C(  -456.37), SIMDE_FLOAT32_C(  -768.39) },
      { SIMDE_FLOAT32_C(  -151.35), SIMDE_FLOAT32_C(  -566.88), SIMDE_FLOAT32_C(   833.49), SIMDE_FLOAT32_C(   840.66),
        SIMDE_FLOAT32_C(   273.73), SIMDE_FLOAT32_C(  -370.75), SIMDE_FLOAT32_C(  -139.72), SIMDE_FLOAT32_C(   254.38),
        SIMDE_FLOAT32_C(   455.19), SIMDE_FLOAT32_C(   729.21), SIMDE_FLOAT32_C(  -773.88), SIMDE_FLOAT32_C(   686.56),
        SIMDE_FLOAT32_C(   282.75), SIMDE_FLOAT32_C(   724.10), SIMDE_FLOAT32_C(  -456.37), SIMDE_FLOAT32_C(  -768.39) } },
    { { SIMDE_FLOAT32_C(  -247.20), SIMDE_FLOAT32_C(   -54.62), SIMDE_FLOAT32_C(  -856.69), SIMDE_FLOAT32_C(  -152.80),
        SIMDE_FLOAT32_C(  -238.64), SIMDE_FLOAT32_C(  -655.23), SIMDE_FLOAT32_C(   169.26), SIMDE_FLOAT32_C(  -541.09),
        SIMDE_FLOAT32_C(   232.84), SIMDE_FLOAT32_C(   385.60), SIMDE_FLOAT32_C(   685.83), SIMDE_FLOAT32_C(   386.84),
        SIMDE_FLOAT32_C(  -320.88), SIMDE_FLOAT32_C(  -276.68), SIMDE_FLOAT32_C(   573.38), SIMDE_FLOAT32_C(   527.77) },
      { SIMDE_FLOAT32_C(  -247.20), SIMDE_FLOAT32_C(   -54.62), SIMDE_FLOAT32_C(  -856.69), SIMDE_FLOAT32_C(  -152.80),
        SIMDE_FLOAT32_C(  -238.64), SIMDE_FLOAT32_C(  -655.23), SIMDE_FLOAT32_C(   169.26), SIMDE_FLOAT32_C(  -541.09),
        SIMDE_FLOAT32_C(   232.84), SIMDE_FLOAT32_C(   385.60), SIMDE_FLOAT32_C(   685.83), SIMDE_FLOAT32_C(   386.84),
        SIMDE_FLOAT32_C(  -320.88), SIMDE_FLOAT32_C(  -276.68), SIMDE_FLOAT32_C(   573.38), SIMDE_FLOAT32_C(   527.77) } },
    { { SIMDE_FLOAT32_C(   156.44), SIMDE_FLOAT32_C(   406.87), SIMDE_FLOAT32_C(   368.42), SIMDE_FLOAT32_C(  -569.84),
        SIMDE_FLOAT32_C(  -963.88), SIMDE_FLOAT32_C(  -771.30), SIMDE_FLOAT32_C(   684.54), SIMDE_FLOAT32_C(   491.30),
        SIMDE_FLOAT32_C(   957.91), SIMDE_FLOAT32_C(   910.66), SIMDE_FLOAT32_C(   177.86), SIMDE_FLOAT32_C(   240.66),
        SIMDE_FLOAT32_C(   634.76), SIMDE_FLOAT32_C(   721.49), SIMDE_FLOAT32_C(   472.26), SIMDE_FLOAT32_C(  -612.44) },
      { SIMDE_FLOAT32_C(   156.44), SIMDE_FLOAT32_C(   406.87), SIMDE_FLOAT32_C(   368.42), SIMDE_FLOAT32_C(  -569.84),
        SIMDE_FLOAT32_C(  -963.88), SIMDE_FLOAT32_C(  -771.30), SIMDE_FLOAT32_C(   684.54), SIMDE_FLOAT32_C(   491.30),
        SIMDE_FLOAT32_C(   957.91), SIMDE_FLOAT32_C(   910.66), SIMDE_FLOAT32_C(   177.86), SIMDE_FLOAT32_C(   240.66),
        SIMDE_FLOAT32_C(   634.76), SIMDE_FLOAT32_C(   721.49), SIMDE_FLOAT32_C(   472.26), SIMDE_FLOAT32_C(  -612.44) } },
    { { SIMDE_FLOAT32_C(  -333.13), SIMDE_FLOAT32_C(   615.57), SIMDE_FLOAT32_C(   234.76), SIMDE_FLOAT32_C(   428.23),
        SIMDE_FLOAT32_C(   960.34), SIMDE_FLOAT32_C(  -595.97), SIMDE_FLOAT32_C(   887.14), SIMDE_FLOAT32_C(   193.19),
        SIMDE_FLOAT32_C(   789.63), SIMDE_FLOAT32_C(   572.97), SIMDE_FLOAT32_C(  -419.98), SIMDE_FLOAT32_C(  -531.26),
        SIMDE_FLOAT32_C(  -703.71), SIMDE_FLOAT32_C(  -846.60), SIMDE_FLOAT32_C(   996.51), SIMDE_FLOAT32_C(   452.72) },
      { SIMDE_FLOAT32_C(  -333.13), SIMDE_FLOAT32_C(   615.57), SIMDE_FLOAT32_C(   234.76), SIMDE_FLOAT32_C(   428.23),
        SIMDE_FLOAT32_C(   960.34), SIMDE_FLOAT32_C(  -595.97), SIMDE_FLOAT32_C(   887.14), SIMDE_FLOAT32_C(   193.19),
        SIMDE_FLOAT32_C(   789.63), SIMDE_FLOAT32_C(   572.97), SIMDE_FLOAT32_C(  -419.98), SIMDE_FLOAT32_C(  -531.26),
        SIMDE_FLOAT32_C(  -703.71), SIMDE_FLOAT32_C(  -846.60), SIMDE_FLOAT32_C(   996.51), SIMDE_FLOAT32_C(   452.72) } },
    { { SIMDE_FLOAT32_C(   560.27), SIMDE_FLOAT32_C(   364.93), SIMDE_FLOAT32_C(   882.89), SIMDE_FLOAT32_C(   596.38),
        SIMDE_FLOAT32_C(   593.63), SIMDE_FLOAT32_C(   567.43), SIMDE_FLOAT32_C(    87.69), SIMDE_FLOAT32_C(   551.54),
        SIMDE_FLOAT32_C(   478.09), SIMDE_FLOAT32_C(  -734.45), SIMDE_FLOAT32_C(  -207.80), SIMDE_FLOAT32_C(   112.86),
        SIMDE_FLOAT32_C(   987.04), SIMDE_FLOAT32_C(  -735.54), SIMDE_FLOAT32_C(   500.42), SIMDE_FLOAT32_C(  -346.09) },
      { SIMDE_FLOAT32_C(   560.27), SIMDE_FLOAT32_C(   364.93), SIMDE_FLOAT32_C(   882.89), SIMDE_FLOAT32_C(   596.38),
        SIMDE_FLOAT32_C(   593.63), SIMDE_FLOAT32_C(   567.43), SIMDE_FLOAT32_C(    87.69), SIMDE_FLOAT32_C(   551.54),
        SIMDE_FLOAT32_C(   478.09), SIMDE_FLOAT32_C(  -734.45), SIMDE_FLOAT32_C(  -207.80), SIMDE_FLOAT32_C(   112.86),
        SIMDE_FLOAT32_C(   987.04), SIMDE_FLOAT32_C(  -735.54), SIMDE_FLOAT32_C(   500.42), SIMDE_FLOAT32_C(  -346.09) } },
    { { SIMDE_FLOAT32_C(   880.04), SIMDE_FLOAT32_C(  -264.82), SIMDE_FLOAT32_C(  -917.86), SIMDE_FLOAT32_C(   840.38),
        SIMDE_FLOAT32_C(   139.21), SIMDE_FLOAT32_C(   969.28), SIMDE_FLOAT32_C(    33.57), SIMDE_FLOAT32_C(   -71.16),
        SIMDE_FLOAT32_C(   542.24), SIMDE_FLOAT32_C(   613.59), SIMDE_FLOAT32_C(   397.58), SIMDE_FLOAT32_C(   838.53),
        SIMDE_FLOAT32_C(   766.99), SIMDE_FLOAT32_C(   394.09), SIMDE_FLOAT32_C(   291.25), SIMDE_FLOAT32_C(   327.26) },
      { SIMDE_FLOAT32_C(   880.04), SIMDE_FLOAT32_C(  -264.82), SIMDE_FLOAT32_C(  -917.86), SIMDE_FLOAT32_C(   840.38),
        SIMDE_FLOAT32_C(   139.21), SIMDE_FLOAT32_C(   969.28), SIMDE_FLOAT32_C(    33.57), SIMDE_FLOAT32_C(   -71.16),
        SIMDE_FLOAT32_C(   542.24), SIMDE_FLOAT32_C(   613.59), SIMDE_FLOAT32_C(   397.58), SIMDE_FLOAT32_C(   838.53),
        SIMDE_FLOAT32_C(   766.99), SIMDE_FLOAT32_C(   394.09), SIMDE_FLOAT32_C(   291.25), SIMDE_FLOAT32_C(   327.26) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512 r = simde_mm512_set_ps(
        test_vec[i].a[15], test_vec[i].a[14], test_vec[i].a[13], test_vec[i].a[12],
        test_vec[i].a[11], test_vec[i].a[10], test_vec[i].a[ 9], test_vec[i].a[ 8],
        test_vec[i].a[ 7], test_vec[i].a[ 6], test_vec[i].a[ 5], test_vec[i].a[ 4],
        test_vec[i].a[ 3], test_vec[i].a[ 2], test_vec[i].a[ 1], test_vec[i].a[ 0]);
    simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m512 a = simde_test_x86_random_f32x16(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
    simde__m512 r = a;

    simde_test_x86_write_f32x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f32x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_set_epi8)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_set_epi16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_set_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_set_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_set_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_set_pd)
SIMDE_TEST_FUNC_LIST_END

#include <test/x86/avx512/test-avx512-footer.h>
