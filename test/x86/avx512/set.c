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

#if defined(SIMDE_FLOAT16_IS_SCALAR)
static int
test_simde_mm512_set_ph (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde_float16 a[32];
    const simde_float16 r[32];
  } test_vec[] = {
   { { SIMDE_FLOAT16_VALUE(   282.25), SIMDE_FLOAT16_VALUE(   386.50), SIMDE_FLOAT16_VALUE(   -50.12), SIMDE_FLOAT16_VALUE(   737.50),
        SIMDE_FLOAT16_VALUE(  -190.00), SIMDE_FLOAT16_VALUE(   104.19), SIMDE_FLOAT16_VALUE(   655.00), SIMDE_FLOAT16_VALUE(   400.75),
        SIMDE_FLOAT16_VALUE(  -452.50), SIMDE_FLOAT16_VALUE(  -606.50), SIMDE_FLOAT16_VALUE(   463.75), SIMDE_FLOAT16_VALUE(   894.50),
        SIMDE_FLOAT16_VALUE(   273.50), SIMDE_FLOAT16_VALUE(  -503.50), SIMDE_FLOAT16_VALUE(  -643.50), SIMDE_FLOAT16_VALUE(   728.50),
        SIMDE_FLOAT16_VALUE(  -947.50), SIMDE_FLOAT16_VALUE(  -852.50), SIMDE_FLOAT16_VALUE(  -635.50), SIMDE_FLOAT16_VALUE(   796.00),
        SIMDE_FLOAT16_VALUE(    24.80), SIMDE_FLOAT16_VALUE(   897.00), SIMDE_FLOAT16_VALUE(  -993.00), SIMDE_FLOAT16_VALUE(   685.00),
        SIMDE_FLOAT16_VALUE(  -913.00), SIMDE_FLOAT16_VALUE(   547.50), SIMDE_FLOAT16_VALUE(  -630.00), SIMDE_FLOAT16_VALUE(   433.00),
        SIMDE_FLOAT16_VALUE(   177.25), SIMDE_FLOAT16_VALUE(   580.50), SIMDE_FLOAT16_VALUE(  -988.50), SIMDE_FLOAT16_VALUE(  -540.50) },
      { SIMDE_FLOAT16_VALUE(   282.25), SIMDE_FLOAT16_VALUE(   386.50), SIMDE_FLOAT16_VALUE(   -50.12), SIMDE_FLOAT16_VALUE(   737.50),
        SIMDE_FLOAT16_VALUE(  -190.00), SIMDE_FLOAT16_VALUE(   104.19), SIMDE_FLOAT16_VALUE(   655.00), SIMDE_FLOAT16_VALUE(   400.75),
        SIMDE_FLOAT16_VALUE(  -452.50), SIMDE_FLOAT16_VALUE(  -606.50), SIMDE_FLOAT16_VALUE(   463.75), SIMDE_FLOAT16_VALUE(   894.50),
        SIMDE_FLOAT16_VALUE(   273.50), SIMDE_FLOAT16_VALUE(  -503.50), SIMDE_FLOAT16_VALUE(  -643.50), SIMDE_FLOAT16_VALUE(   728.50),
        SIMDE_FLOAT16_VALUE(  -947.50), SIMDE_FLOAT16_VALUE(  -852.50), SIMDE_FLOAT16_VALUE(  -635.50), SIMDE_FLOAT16_VALUE(   796.00),
        SIMDE_FLOAT16_VALUE(    24.80), SIMDE_FLOAT16_VALUE(   897.00), SIMDE_FLOAT16_VALUE(  -993.00), SIMDE_FLOAT16_VALUE(   685.00),
        SIMDE_FLOAT16_VALUE(  -913.00), SIMDE_FLOAT16_VALUE(   547.50), SIMDE_FLOAT16_VALUE(  -630.00), SIMDE_FLOAT16_VALUE(   433.00),
        SIMDE_FLOAT16_VALUE(   177.25), SIMDE_FLOAT16_VALUE(   580.50), SIMDE_FLOAT16_VALUE(  -988.50), SIMDE_FLOAT16_VALUE(  -540.50) } },
    { { SIMDE_FLOAT16_VALUE(   -32.94), SIMDE_FLOAT16_VALUE(   -38.66), SIMDE_FLOAT16_VALUE(  -803.00), SIMDE_FLOAT16_VALUE(   777.00),
        SIMDE_FLOAT16_VALUE(  -934.50), SIMDE_FLOAT16_VALUE(   851.50), SIMDE_FLOAT16_VALUE(   177.88), SIMDE_FLOAT16_VALUE(  -387.00),
        SIMDE_FLOAT16_VALUE(  -754.50), SIMDE_FLOAT16_VALUE(  -358.25), SIMDE_FLOAT16_VALUE(  -492.75), SIMDE_FLOAT16_VALUE(   519.00),
        SIMDE_FLOAT16_VALUE(   138.25), SIMDE_FLOAT16_VALUE(  -136.25), SIMDE_FLOAT16_VALUE(   247.25), SIMDE_FLOAT16_VALUE(   190.88),
        SIMDE_FLOAT16_VALUE(    11.31), SIMDE_FLOAT16_VALUE(   612.00), SIMDE_FLOAT16_VALUE(   -13.18), SIMDE_FLOAT16_VALUE(  -964.00),
        SIMDE_FLOAT16_VALUE(   508.75), SIMDE_FLOAT16_VALUE(    -6.03), SIMDE_FLOAT16_VALUE(   721.00), SIMDE_FLOAT16_VALUE(   595.50),
        SIMDE_FLOAT16_VALUE(  -458.50), SIMDE_FLOAT16_VALUE(  -909.00), SIMDE_FLOAT16_VALUE(    28.56), SIMDE_FLOAT16_VALUE(   719.00),
        SIMDE_FLOAT16_VALUE(   671.50), SIMDE_FLOAT16_VALUE(    40.03), SIMDE_FLOAT16_VALUE(  -822.00), SIMDE_FLOAT16_VALUE(  -361.50) },
      { SIMDE_FLOAT16_VALUE(   -32.94), SIMDE_FLOAT16_VALUE(   -38.66), SIMDE_FLOAT16_VALUE(  -803.00), SIMDE_FLOAT16_VALUE(   777.00),
        SIMDE_FLOAT16_VALUE(  -934.50), SIMDE_FLOAT16_VALUE(   851.50), SIMDE_FLOAT16_VALUE(   177.88), SIMDE_FLOAT16_VALUE(  -387.00),
        SIMDE_FLOAT16_VALUE(  -754.50), SIMDE_FLOAT16_VALUE(  -358.25), SIMDE_FLOAT16_VALUE(  -492.75), SIMDE_FLOAT16_VALUE(   519.00),
        SIMDE_FLOAT16_VALUE(   138.25), SIMDE_FLOAT16_VALUE(  -136.25), SIMDE_FLOAT16_VALUE(   247.25), SIMDE_FLOAT16_VALUE(   190.88),
        SIMDE_FLOAT16_VALUE(    11.31), SIMDE_FLOAT16_VALUE(   612.00), SIMDE_FLOAT16_VALUE(   -13.18), SIMDE_FLOAT16_VALUE(  -964.00),
        SIMDE_FLOAT16_VALUE(   508.75), SIMDE_FLOAT16_VALUE(    -6.03), SIMDE_FLOAT16_VALUE(   721.00), SIMDE_FLOAT16_VALUE(   595.50),
        SIMDE_FLOAT16_VALUE(  -458.50), SIMDE_FLOAT16_VALUE(  -909.00), SIMDE_FLOAT16_VALUE(    28.56), SIMDE_FLOAT16_VALUE(   719.00),
        SIMDE_FLOAT16_VALUE(   671.50), SIMDE_FLOAT16_VALUE(    40.03), SIMDE_FLOAT16_VALUE(  -822.00), SIMDE_FLOAT16_VALUE(  -361.50) } },
    { { SIMDE_FLOAT16_VALUE(  -998.50), SIMDE_FLOAT16_VALUE(  -625.00), SIMDE_FLOAT16_VALUE(  -584.50), SIMDE_FLOAT16_VALUE(  -933.00),
        SIMDE_FLOAT16_VALUE(  -773.00), SIMDE_FLOAT16_VALUE(   593.50), SIMDE_FLOAT16_VALUE(  -320.25), SIMDE_FLOAT16_VALUE(  -528.00),
        SIMDE_FLOAT16_VALUE(  -765.00), SIMDE_FLOAT16_VALUE(   187.12), SIMDE_FLOAT16_VALUE(   991.00), SIMDE_FLOAT16_VALUE(   373.25),
        SIMDE_FLOAT16_VALUE(  -949.00), SIMDE_FLOAT16_VALUE(   238.25), SIMDE_FLOAT16_VALUE(  -435.75), SIMDE_FLOAT16_VALUE(    62.16),
        SIMDE_FLOAT16_VALUE(  -149.75), SIMDE_FLOAT16_VALUE(   551.00), SIMDE_FLOAT16_VALUE(    98.25), SIMDE_FLOAT16_VALUE(  -641.00),
        SIMDE_FLOAT16_VALUE(  -455.00), SIMDE_FLOAT16_VALUE(  -180.62), SIMDE_FLOAT16_VALUE(   954.50), SIMDE_FLOAT16_VALUE(    86.62),
        SIMDE_FLOAT16_VALUE(   -89.69), SIMDE_FLOAT16_VALUE(   -16.88), SIMDE_FLOAT16_VALUE(  -194.62), SIMDE_FLOAT16_VALUE(  -418.25),
        SIMDE_FLOAT16_VALUE(  -977.00), SIMDE_FLOAT16_VALUE(   -16.39), SIMDE_FLOAT16_VALUE(   220.38), SIMDE_FLOAT16_VALUE(  -975.50) },
      { SIMDE_FLOAT16_VALUE(  -998.50), SIMDE_FLOAT16_VALUE(  -625.00), SIMDE_FLOAT16_VALUE(  -584.50), SIMDE_FLOAT16_VALUE(  -933.00),
        SIMDE_FLOAT16_VALUE(  -773.00), SIMDE_FLOAT16_VALUE(   593.50), SIMDE_FLOAT16_VALUE(  -320.25), SIMDE_FLOAT16_VALUE(  -528.00),
        SIMDE_FLOAT16_VALUE(  -765.00), SIMDE_FLOAT16_VALUE(   187.12), SIMDE_FLOAT16_VALUE(   991.00), SIMDE_FLOAT16_VALUE(   373.25),
        SIMDE_FLOAT16_VALUE(  -949.00), SIMDE_FLOAT16_VALUE(   238.25), SIMDE_FLOAT16_VALUE(  -435.75), SIMDE_FLOAT16_VALUE(    62.16),
        SIMDE_FLOAT16_VALUE(  -149.75), SIMDE_FLOAT16_VALUE(   551.00), SIMDE_FLOAT16_VALUE(    98.25), SIMDE_FLOAT16_VALUE(  -641.00),
        SIMDE_FLOAT16_VALUE(  -455.00), SIMDE_FLOAT16_VALUE(  -180.62), SIMDE_FLOAT16_VALUE(   954.50), SIMDE_FLOAT16_VALUE(    86.62),
        SIMDE_FLOAT16_VALUE(   -89.69), SIMDE_FLOAT16_VALUE(   -16.88), SIMDE_FLOAT16_VALUE(  -194.62), SIMDE_FLOAT16_VALUE(  -418.25),
        SIMDE_FLOAT16_VALUE(  -977.00), SIMDE_FLOAT16_VALUE(   -16.39), SIMDE_FLOAT16_VALUE(   220.38), SIMDE_FLOAT16_VALUE(  -975.50) } },
    { { SIMDE_FLOAT16_VALUE(   358.75), SIMDE_FLOAT16_VALUE(   636.00), SIMDE_FLOAT16_VALUE(  -908.50), SIMDE_FLOAT16_VALUE(   585.50),
        SIMDE_FLOAT16_VALUE(   229.38), SIMDE_FLOAT16_VALUE(  -228.75), SIMDE_FLOAT16_VALUE(  -942.50), SIMDE_FLOAT16_VALUE(   464.50),
        SIMDE_FLOAT16_VALUE(   958.50), SIMDE_FLOAT16_VALUE(  -951.00), SIMDE_FLOAT16_VALUE(  -162.12), SIMDE_FLOAT16_VALUE(  -991.00),
        SIMDE_FLOAT16_VALUE(   287.00), SIMDE_FLOAT16_VALUE(   402.25), SIMDE_FLOAT16_VALUE(    71.38), SIMDE_FLOAT16_VALUE(  -862.50),
        SIMDE_FLOAT16_VALUE(   -46.75), SIMDE_FLOAT16_VALUE(  -830.50), SIMDE_FLOAT16_VALUE(  -503.75), SIMDE_FLOAT16_VALUE(   498.25),
        SIMDE_FLOAT16_VALUE(   -10.93), SIMDE_FLOAT16_VALUE(  -549.00), SIMDE_FLOAT16_VALUE(  -415.00), SIMDE_FLOAT16_VALUE(   899.50),
        SIMDE_FLOAT16_VALUE(   433.75), SIMDE_FLOAT16_VALUE(   390.25), SIMDE_FLOAT16_VALUE(  -519.00), SIMDE_FLOAT16_VALUE(   457.00),
        SIMDE_FLOAT16_VALUE(  -626.00), SIMDE_FLOAT16_VALUE(   701.50), SIMDE_FLOAT16_VALUE(   481.50), SIMDE_FLOAT16_VALUE(   732.50) },
      { SIMDE_FLOAT16_VALUE(   358.75), SIMDE_FLOAT16_VALUE(   636.00), SIMDE_FLOAT16_VALUE(  -908.50), SIMDE_FLOAT16_VALUE(   585.50),
        SIMDE_FLOAT16_VALUE(   229.38), SIMDE_FLOAT16_VALUE(  -228.75), SIMDE_FLOAT16_VALUE(  -942.50), SIMDE_FLOAT16_VALUE(   464.50),
        SIMDE_FLOAT16_VALUE(   958.50), SIMDE_FLOAT16_VALUE(  -951.00), SIMDE_FLOAT16_VALUE(  -162.12), SIMDE_FLOAT16_VALUE(  -991.00),
        SIMDE_FLOAT16_VALUE(   287.00), SIMDE_FLOAT16_VALUE(   402.25), SIMDE_FLOAT16_VALUE(    71.38), SIMDE_FLOAT16_VALUE(  -862.50),
        SIMDE_FLOAT16_VALUE(   -46.75), SIMDE_FLOAT16_VALUE(  -830.50), SIMDE_FLOAT16_VALUE(  -503.75), SIMDE_FLOAT16_VALUE(   498.25),
        SIMDE_FLOAT16_VALUE(   -10.93), SIMDE_FLOAT16_VALUE(  -549.00), SIMDE_FLOAT16_VALUE(  -415.00), SIMDE_FLOAT16_VALUE(   899.50),
        SIMDE_FLOAT16_VALUE(   433.75), SIMDE_FLOAT16_VALUE(   390.25), SIMDE_FLOAT16_VALUE(  -519.00), SIMDE_FLOAT16_VALUE(   457.00),
        SIMDE_FLOAT16_VALUE(  -626.00), SIMDE_FLOAT16_VALUE(   701.50), SIMDE_FLOAT16_VALUE(   481.50), SIMDE_FLOAT16_VALUE(   732.50) } },
    { { SIMDE_FLOAT16_VALUE(   337.50), SIMDE_FLOAT16_VALUE(   573.00), SIMDE_FLOAT16_VALUE(   318.25), SIMDE_FLOAT16_VALUE(  -433.00),
        SIMDE_FLOAT16_VALUE(  -656.00), SIMDE_FLOAT16_VALUE(   376.00), SIMDE_FLOAT16_VALUE(  -968.50), SIMDE_FLOAT16_VALUE(  -697.50),
        SIMDE_FLOAT16_VALUE(   424.75), SIMDE_FLOAT16_VALUE(  -130.62), SIMDE_FLOAT16_VALUE(  -688.00), SIMDE_FLOAT16_VALUE(  -288.25),
        SIMDE_FLOAT16_VALUE(  -728.50), SIMDE_FLOAT16_VALUE(   383.25), SIMDE_FLOAT16_VALUE(  -151.00), SIMDE_FLOAT16_VALUE(   224.75),
        SIMDE_FLOAT16_VALUE(   553.00), SIMDE_FLOAT16_VALUE(   345.25), SIMDE_FLOAT16_VALUE(  -277.00), SIMDE_FLOAT16_VALUE(  -458.25),
        SIMDE_FLOAT16_VALUE(   796.00), SIMDE_FLOAT16_VALUE(   308.00), SIMDE_FLOAT16_VALUE(  -558.50), SIMDE_FLOAT16_VALUE(   229.88),
        SIMDE_FLOAT16_VALUE(  -301.75), SIMDE_FLOAT16_VALUE(   -77.50), SIMDE_FLOAT16_VALUE(  -313.00), SIMDE_FLOAT16_VALUE(    72.25),
        SIMDE_FLOAT16_VALUE(  -376.00), SIMDE_FLOAT16_VALUE(  -831.50), SIMDE_FLOAT16_VALUE(  -195.12), SIMDE_FLOAT16_VALUE(   961.50) },
      { SIMDE_FLOAT16_VALUE(   337.50), SIMDE_FLOAT16_VALUE(   573.00), SIMDE_FLOAT16_VALUE(   318.25), SIMDE_FLOAT16_VALUE(  -433.00),
        SIMDE_FLOAT16_VALUE(  -656.00), SIMDE_FLOAT16_VALUE(   376.00), SIMDE_FLOAT16_VALUE(  -968.50), SIMDE_FLOAT16_VALUE(  -697.50),
        SIMDE_FLOAT16_VALUE(   424.75), SIMDE_FLOAT16_VALUE(  -130.62), SIMDE_FLOAT16_VALUE(  -688.00), SIMDE_FLOAT16_VALUE(  -288.25),
        SIMDE_FLOAT16_VALUE(  -728.50), SIMDE_FLOAT16_VALUE(   383.25), SIMDE_FLOAT16_VALUE(  -151.00), SIMDE_FLOAT16_VALUE(   224.75),
        SIMDE_FLOAT16_VALUE(   553.00), SIMDE_FLOAT16_VALUE(   345.25), SIMDE_FLOAT16_VALUE(  -277.00), SIMDE_FLOAT16_VALUE(  -458.25),
        SIMDE_FLOAT16_VALUE(   796.00), SIMDE_FLOAT16_VALUE(   308.00), SIMDE_FLOAT16_VALUE(  -558.50), SIMDE_FLOAT16_VALUE(   229.88),
        SIMDE_FLOAT16_VALUE(  -301.75), SIMDE_FLOAT16_VALUE(   -77.50), SIMDE_FLOAT16_VALUE(  -313.00), SIMDE_FLOAT16_VALUE(    72.25),
        SIMDE_FLOAT16_VALUE(  -376.00), SIMDE_FLOAT16_VALUE(  -831.50), SIMDE_FLOAT16_VALUE(  -195.12), SIMDE_FLOAT16_VALUE(   961.50) } },
    { { SIMDE_FLOAT16_VALUE(   741.50), SIMDE_FLOAT16_VALUE(  -877.00), SIMDE_FLOAT16_VALUE(  -471.50), SIMDE_FLOAT16_VALUE(  -914.50),
        SIMDE_FLOAT16_VALUE(   499.00), SIMDE_FLOAT16_VALUE(  -440.00), SIMDE_FLOAT16_VALUE(  -612.00), SIMDE_FLOAT16_VALUE(   -76.31),
        SIMDE_FLOAT16_VALUE(   429.25), SIMDE_FLOAT16_VALUE(  -300.25), SIMDE_FLOAT16_VALUE(   635.50), SIMDE_FLOAT16_VALUE(   701.00),
        SIMDE_FLOAT16_VALUE(  -917.00), SIMDE_FLOAT16_VALUE(  -515.50), SIMDE_FLOAT16_VALUE(   -74.44), SIMDE_FLOAT16_VALUE(   636.00),
        SIMDE_FLOAT16_VALUE(   830.00), SIMDE_FLOAT16_VALUE(   648.50), SIMDE_FLOAT16_VALUE(  -822.50), SIMDE_FLOAT16_VALUE(   626.00),
        SIMDE_FLOAT16_VALUE(   -43.28), SIMDE_FLOAT16_VALUE(  -381.00), SIMDE_FLOAT16_VALUE(  -144.25), SIMDE_FLOAT16_VALUE(   655.00),
        SIMDE_FLOAT16_VALUE(   541.50), SIMDE_FLOAT16_VALUE(   542.50), SIMDE_FLOAT16_VALUE(  -272.75), SIMDE_FLOAT16_VALUE(  -834.50),
        SIMDE_FLOAT16_VALUE(   711.00), SIMDE_FLOAT16_VALUE(   532.00), SIMDE_FLOAT16_VALUE(  -873.00), SIMDE_FLOAT16_VALUE(   452.50) },
      { SIMDE_FLOAT16_VALUE(   741.50), SIMDE_FLOAT16_VALUE(  -877.00), SIMDE_FLOAT16_VALUE(  -471.50), SIMDE_FLOAT16_VALUE(  -914.50),
        SIMDE_FLOAT16_VALUE(   499.00), SIMDE_FLOAT16_VALUE(  -440.00), SIMDE_FLOAT16_VALUE(  -612.00), SIMDE_FLOAT16_VALUE(   -76.31),
        SIMDE_FLOAT16_VALUE(   429.25), SIMDE_FLOAT16_VALUE(  -300.25), SIMDE_FLOAT16_VALUE(   635.50), SIMDE_FLOAT16_VALUE(   701.00),
        SIMDE_FLOAT16_VALUE(  -917.00), SIMDE_FLOAT16_VALUE(  -515.50), SIMDE_FLOAT16_VALUE(   -74.44), SIMDE_FLOAT16_VALUE(   636.00),
        SIMDE_FLOAT16_VALUE(   830.00), SIMDE_FLOAT16_VALUE(   648.50), SIMDE_FLOAT16_VALUE(  -822.50), SIMDE_FLOAT16_VALUE(   626.00),
        SIMDE_FLOAT16_VALUE(   -43.28), SIMDE_FLOAT16_VALUE(  -381.00), SIMDE_FLOAT16_VALUE(  -144.25), SIMDE_FLOAT16_VALUE(   655.00),
        SIMDE_FLOAT16_VALUE(   541.50), SIMDE_FLOAT16_VALUE(   542.50), SIMDE_FLOAT16_VALUE(  -272.75), SIMDE_FLOAT16_VALUE(  -834.50),
        SIMDE_FLOAT16_VALUE(   711.00), SIMDE_FLOAT16_VALUE(   532.00), SIMDE_FLOAT16_VALUE(  -873.00), SIMDE_FLOAT16_VALUE(   452.50) } },
    { { SIMDE_FLOAT16_VALUE(   655.00), SIMDE_FLOAT16_VALUE(  -344.50), SIMDE_FLOAT16_VALUE(   538.00), SIMDE_FLOAT16_VALUE(   154.25),
        SIMDE_FLOAT16_VALUE(   215.38), SIMDE_FLOAT16_VALUE(   926.00), SIMDE_FLOAT16_VALUE(  -922.00), SIMDE_FLOAT16_VALUE(  -355.50),
        SIMDE_FLOAT16_VALUE(  -374.00), SIMDE_FLOAT16_VALUE(   713.50), SIMDE_FLOAT16_VALUE(  -654.50), SIMDE_FLOAT16_VALUE(  -291.00),
        SIMDE_FLOAT16_VALUE(  -802.00), SIMDE_FLOAT16_VALUE(   271.00), SIMDE_FLOAT16_VALUE(  -655.50), SIMDE_FLOAT16_VALUE(  -972.00),
        SIMDE_FLOAT16_VALUE(   -80.31), SIMDE_FLOAT16_VALUE(  -477.75), SIMDE_FLOAT16_VALUE(   653.50), SIMDE_FLOAT16_VALUE(   876.50),
        SIMDE_FLOAT16_VALUE(   141.25), SIMDE_FLOAT16_VALUE(  -490.75), SIMDE_FLOAT16_VALUE(   531.50), SIMDE_FLOAT16_VALUE(  -317.25),
        SIMDE_FLOAT16_VALUE(  -948.00), SIMDE_FLOAT16_VALUE(  -741.50), SIMDE_FLOAT16_VALUE(  -151.75), SIMDE_FLOAT16_VALUE(   763.00),
        SIMDE_FLOAT16_VALUE(   791.00), SIMDE_FLOAT16_VALUE(   -24.83), SIMDE_FLOAT16_VALUE(   215.38), SIMDE_FLOAT16_VALUE(   446.00) },
      { SIMDE_FLOAT16_VALUE(   655.00), SIMDE_FLOAT16_VALUE(  -344.50), SIMDE_FLOAT16_VALUE(   538.00), SIMDE_FLOAT16_VALUE(   154.25),
        SIMDE_FLOAT16_VALUE(   215.38), SIMDE_FLOAT16_VALUE(   926.00), SIMDE_FLOAT16_VALUE(  -922.00), SIMDE_FLOAT16_VALUE(  -355.50),
        SIMDE_FLOAT16_VALUE(  -374.00), SIMDE_FLOAT16_VALUE(   713.50), SIMDE_FLOAT16_VALUE(  -654.50), SIMDE_FLOAT16_VALUE(  -291.00),
        SIMDE_FLOAT16_VALUE(  -802.00), SIMDE_FLOAT16_VALUE(   271.00), SIMDE_FLOAT16_VALUE(  -655.50), SIMDE_FLOAT16_VALUE(  -972.00),
        SIMDE_FLOAT16_VALUE(   -80.31), SIMDE_FLOAT16_VALUE(  -477.75), SIMDE_FLOAT16_VALUE(   653.50), SIMDE_FLOAT16_VALUE(   876.50),
        SIMDE_FLOAT16_VALUE(   141.25), SIMDE_FLOAT16_VALUE(  -490.75), SIMDE_FLOAT16_VALUE(   531.50), SIMDE_FLOAT16_VALUE(  -317.25),
        SIMDE_FLOAT16_VALUE(  -948.00), SIMDE_FLOAT16_VALUE(  -741.50), SIMDE_FLOAT16_VALUE(  -151.75), SIMDE_FLOAT16_VALUE(   763.00),
        SIMDE_FLOAT16_VALUE(   791.00), SIMDE_FLOAT16_VALUE(   -24.83), SIMDE_FLOAT16_VALUE(   215.38), SIMDE_FLOAT16_VALUE(   446.00) } },
    { { SIMDE_FLOAT16_VALUE(   630.50), SIMDE_FLOAT16_VALUE(  -246.75), SIMDE_FLOAT16_VALUE(  -399.75), SIMDE_FLOAT16_VALUE(  -154.00),
        SIMDE_FLOAT16_VALUE(  -320.75), SIMDE_FLOAT16_VALUE(  -321.75), SIMDE_FLOAT16_VALUE(   490.50), SIMDE_FLOAT16_VALUE(   305.25),
        SIMDE_FLOAT16_VALUE(  -608.50), SIMDE_FLOAT16_VALUE(   836.00), SIMDE_FLOAT16_VALUE(  -986.00), SIMDE_FLOAT16_VALUE(  -410.50),
        SIMDE_FLOAT16_VALUE(   107.00), SIMDE_FLOAT16_VALUE(  -641.00), SIMDE_FLOAT16_VALUE(  -382.75), SIMDE_FLOAT16_VALUE(  -973.50),
        SIMDE_FLOAT16_VALUE(  -118.75), SIMDE_FLOAT16_VALUE(  -729.00), SIMDE_FLOAT16_VALUE(   903.00), SIMDE_FLOAT16_VALUE(  -977.50),
        SIMDE_FLOAT16_VALUE(  -219.75), SIMDE_FLOAT16_VALUE(   434.50), SIMDE_FLOAT16_VALUE(  -294.75), SIMDE_FLOAT16_VALUE(  -167.88),
        SIMDE_FLOAT16_VALUE(   693.50), SIMDE_FLOAT16_VALUE(   553.50), SIMDE_FLOAT16_VALUE(  -405.00), SIMDE_FLOAT16_VALUE(   484.25),
        SIMDE_FLOAT16_VALUE(  -471.25), SIMDE_FLOAT16_VALUE(   810.50), SIMDE_FLOAT16_VALUE(   -69.81), SIMDE_FLOAT16_VALUE(  -840.50) },
      { SIMDE_FLOAT16_VALUE(   630.50), SIMDE_FLOAT16_VALUE(  -246.75), SIMDE_FLOAT16_VALUE(  -399.75), SIMDE_FLOAT16_VALUE(  -154.00),
        SIMDE_FLOAT16_VALUE(  -320.75), SIMDE_FLOAT16_VALUE(  -321.75), SIMDE_FLOAT16_VALUE(   490.50), SIMDE_FLOAT16_VALUE(   305.25),
        SIMDE_FLOAT16_VALUE(  -608.50), SIMDE_FLOAT16_VALUE(   836.00), SIMDE_FLOAT16_VALUE(  -986.00), SIMDE_FLOAT16_VALUE(  -410.50),
        SIMDE_FLOAT16_VALUE(   107.00), SIMDE_FLOAT16_VALUE(  -641.00), SIMDE_FLOAT16_VALUE(  -382.75), SIMDE_FLOAT16_VALUE(  -973.50),
        SIMDE_FLOAT16_VALUE(  -118.75), SIMDE_FLOAT16_VALUE(  -729.00), SIMDE_FLOAT16_VALUE(   903.00), SIMDE_FLOAT16_VALUE(  -977.50),
        SIMDE_FLOAT16_VALUE(  -219.75), SIMDE_FLOAT16_VALUE(   434.50), SIMDE_FLOAT16_VALUE(  -294.75), SIMDE_FLOAT16_VALUE(  -167.88),
        SIMDE_FLOAT16_VALUE(   693.50), SIMDE_FLOAT16_VALUE(   553.50), SIMDE_FLOAT16_VALUE(  -405.00), SIMDE_FLOAT16_VALUE(   484.25),
        SIMDE_FLOAT16_VALUE(  -471.25), SIMDE_FLOAT16_VALUE(   810.50), SIMDE_FLOAT16_VALUE(   -69.81), SIMDE_FLOAT16_VALUE(  -840.50) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512h r = simde_mm512_set_ph(
        test_vec[i].a[31], test_vec[i].a[30], test_vec[i].a[29], test_vec[i].a[28],
        test_vec[i].a[27], test_vec[i].a[26], test_vec[i].a[25], test_vec[i].a[24],
        test_vec[i].a[23], test_vec[i].a[22], test_vec[i].a[21], test_vec[i].a[20],
        test_vec[i].a[19], test_vec[i].a[18], test_vec[i].a[17], test_vec[i].a[16],
        test_vec[i].a[15], test_vec[i].a[14], test_vec[i].a[13], test_vec[i].a[12],
        test_vec[i].a[11], test_vec[i].a[10], test_vec[i].a[ 9], test_vec[i].a[ 8],
        test_vec[i].a[ 7], test_vec[i].a[ 6], test_vec[i].a[ 5], test_vec[i].a[ 4],
        test_vec[i].a[ 3], test_vec[i].a[ 2], test_vec[i].a[ 1], test_vec[i].a[ 0]);
    simde_test_x86_assert_equal_f16x32(r, simde_mm512_loadu_ph(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m512h a = simde_test_x86_random_f16x32(SIMDE_FLOAT16_VALUE(-1000.0), SIMDE_FLOAT16_VALUE(1000.0));
    simde__m512h r = a;

    simde_test_x86_write_f16x32(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f16x32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}
#endif

static int
test_simde_x_mm512_set_epu8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const uint8_t a[64];
    const uint8_t r[64];
  } test_vec[] = {
    { { UINT8_C( 95), UINT8_C(  0), UINT8_C( 21), UINT8_C( 49), UINT8_C(138), UINT8_C(176), UINT8_C( 81), UINT8_C(112),
        UINT8_C(154), UINT8_C( 14), UINT8_C( 32), UINT8_C(204), UINT8_C( 42), UINT8_C( 19), UINT8_C( 48), UINT8_C(192),
        UINT8_C(242), UINT8_C(170), UINT8_C( 39), UINT8_C( 54), UINT8_C(129), UINT8_C(142), UINT8_C( 42), UINT8_C( 41),
        UINT8_C(228), UINT8_C( 22), UINT8_C(187), UINT8_C(131), UINT8_C( 86), UINT8_C( 78), UINT8_C( 36), UINT8_C(182),
        UINT8_C( 78), UINT8_C( 57), UINT8_C(231), UINT8_C(216), UINT8_C(233), UINT8_C( 56), UINT8_C( 72), UINT8_C(131),
        UINT8_C( 71), UINT8_C(104), UINT8_C( 79), UINT8_C(113), UINT8_C(124), UINT8_C(127), UINT8_C( 49), UINT8_C(110),
        UINT8_C( 42), UINT8_C( 88), UINT8_C(165), UINT8_C(171), UINT8_C(230), UINT8_C(207), UINT8_C(212), UINT8_C(202),
        UINT8_C(229), UINT8_C(143), UINT8_C( 77), UINT8_C( 59), UINT8_C(221), UINT8_C(113), UINT8_C(241), UINT8_C( 43) },
      { UINT8_C( 95), UINT8_C(  0), UINT8_C( 21), UINT8_C( 49), UINT8_C(138), UINT8_C(176), UINT8_C( 81), UINT8_C(112),
        UINT8_C(154), UINT8_C( 14), UINT8_C( 32), UINT8_C(204), UINT8_C( 42), UINT8_C( 19), UINT8_C( 48), UINT8_C(192),
        UINT8_C(242), UINT8_C(170), UINT8_C( 39), UINT8_C( 54), UINT8_C(129), UINT8_C(142), UINT8_C( 42), UINT8_C( 41),
        UINT8_C(228), UINT8_C( 22), UINT8_C(187), UINT8_C(131), UINT8_C( 86), UINT8_C( 78), UINT8_C( 36), UINT8_C(182),
        UINT8_C( 78), UINT8_C( 57), UINT8_C(231), UINT8_C(216), UINT8_C(233), UINT8_C( 56), UINT8_C( 72), UINT8_C(131),
        UINT8_C( 71), UINT8_C(104), UINT8_C( 79), UINT8_C(113), UINT8_C(124), UINT8_C(127), UINT8_C( 49), UINT8_C(110),
        UINT8_C( 42), UINT8_C( 88), UINT8_C(165), UINT8_C(171), UINT8_C(230), UINT8_C(207), UINT8_C(212), UINT8_C(202),
        UINT8_C(229), UINT8_C(143), UINT8_C( 77), UINT8_C( 59), UINT8_C(221), UINT8_C(113), UINT8_C(241), UINT8_C( 43) } },
    { { UINT8_C(170), UINT8_C(216), UINT8_C(  3), UINT8_C(148), UINT8_C( 17), UINT8_C( 75), UINT8_C( 23), UINT8_C( 88),
        UINT8_C(179), UINT8_C(103), UINT8_C(201), UINT8_C( 47), UINT8_C(230), UINT8_C(250), UINT8_C(158), UINT8_C( 16),
        UINT8_C( 82), UINT8_C( 67), UINT8_C(187), UINT8_C( 56), UINT8_C( 18), UINT8_C(143), UINT8_C(  2), UINT8_C(247),
        UINT8_C( 30), UINT8_C( 79), UINT8_C( 50), UINT8_C(251), UINT8_C(193), UINT8_C( 36), UINT8_C( 38), UINT8_C(107),
        UINT8_C(252), UINT8_C( 41),    UINT8_MAX, UINT8_C( 13), UINT8_C(116), UINT8_C( 23), UINT8_C(101), UINT8_C( 40),
        UINT8_C(126), UINT8_C( 46), UINT8_C( 87), UINT8_C(100), UINT8_C( 40), UINT8_C(245), UINT8_C(117), UINT8_C(122),
        UINT8_C( 56), UINT8_C( 48), UINT8_C(178), UINT8_C( 74), UINT8_C(192), UINT8_C(180), UINT8_C( 65), UINT8_C(222),
        UINT8_C(  4), UINT8_C(116), UINT8_C(218), UINT8_C(197), UINT8_C(152), UINT8_C(  0), UINT8_C( 48), UINT8_C(148) },
      { UINT8_C(170), UINT8_C(216), UINT8_C(  3), UINT8_C(148), UINT8_C( 17), UINT8_C( 75), UINT8_C( 23), UINT8_C( 88),
        UINT8_C(179), UINT8_C(103), UINT8_C(201), UINT8_C( 47), UINT8_C(230), UINT8_C(250), UINT8_C(158), UINT8_C( 16),
        UINT8_C( 82), UINT8_C( 67), UINT8_C(187), UINT8_C( 56), UINT8_C( 18), UINT8_C(143), UINT8_C(  2), UINT8_C(247),
        UINT8_C( 30), UINT8_C( 79), UINT8_C( 50), UINT8_C(251), UINT8_C(193), UINT8_C( 36), UINT8_C( 38), UINT8_C(107),
        UINT8_C(252), UINT8_C( 41),    UINT8_MAX, UINT8_C( 13), UINT8_C(116), UINT8_C( 23), UINT8_C(101), UINT8_C( 40),
        UINT8_C(126), UINT8_C( 46), UINT8_C( 87), UINT8_C(100), UINT8_C( 40), UINT8_C(245), UINT8_C(117), UINT8_C(122),
        UINT8_C( 56), UINT8_C( 48), UINT8_C(178), UINT8_C( 74), UINT8_C(192), UINT8_C(180), UINT8_C( 65), UINT8_C(222),
        UINT8_C(  4), UINT8_C(116), UINT8_C(218), UINT8_C(197), UINT8_C(152), UINT8_C(  0), UINT8_C( 48), UINT8_C(148) } },
    { { UINT8_C( 42), UINT8_C( 48), UINT8_C(162), UINT8_C(158), UINT8_C( 71), UINT8_C(  7), UINT8_C(198), UINT8_C(197),
        UINT8_C( 54), UINT8_C( 30), UINT8_C( 41), UINT8_C( 94), UINT8_C( 19), UINT8_C(158), UINT8_C(217), UINT8_C( 76),
        UINT8_C(207), UINT8_C(139), UINT8_C(150), UINT8_C(143), UINT8_C( 64), UINT8_C(216), UINT8_C(109), UINT8_C( 68),
        UINT8_C( 76), UINT8_C( 71), UINT8_C(  9), UINT8_C(228), UINT8_C( 72), UINT8_C( 57), UINT8_C(120), UINT8_C(114),
        UINT8_C(105), UINT8_C( 26), UINT8_C( 16), UINT8_C(176), UINT8_C( 34), UINT8_C(215), UINT8_C(117), UINT8_C( 88),
        UINT8_C(245), UINT8_C(159), UINT8_C(182), UINT8_C(  8), UINT8_C( 61), UINT8_C(143), UINT8_C( 84), UINT8_C( 12),
        UINT8_C( 27), UINT8_C(235), UINT8_C(155), UINT8_C( 91), UINT8_C(195), UINT8_C(  9), UINT8_C(159), UINT8_C( 15),
        UINT8_C( 80), UINT8_C(168), UINT8_C(243), UINT8_C(152), UINT8_C(225), UINT8_C(107), UINT8_C( 10), UINT8_C( 75) },
      { UINT8_C( 42), UINT8_C( 48), UINT8_C(162), UINT8_C(158), UINT8_C( 71), UINT8_C(  7), UINT8_C(198), UINT8_C(197),
        UINT8_C( 54), UINT8_C( 30), UINT8_C( 41), UINT8_C( 94), UINT8_C( 19), UINT8_C(158), UINT8_C(217), UINT8_C( 76),
        UINT8_C(207), UINT8_C(139), UINT8_C(150), UINT8_C(143), UINT8_C( 64), UINT8_C(216), UINT8_C(109), UINT8_C( 68),
        UINT8_C( 76), UINT8_C( 71), UINT8_C(  9), UINT8_C(228), UINT8_C( 72), UINT8_C( 57), UINT8_C(120), UINT8_C(114),
        UINT8_C(105), UINT8_C( 26), UINT8_C( 16), UINT8_C(176), UINT8_C( 34), UINT8_C(215), UINT8_C(117), UINT8_C( 88),
        UINT8_C(245), UINT8_C(159), UINT8_C(182), UINT8_C(  8), UINT8_C( 61), UINT8_C(143), UINT8_C( 84), UINT8_C( 12),
        UINT8_C( 27), UINT8_C(235), UINT8_C(155), UINT8_C( 91), UINT8_C(195), UINT8_C(  9), UINT8_C(159), UINT8_C( 15),
        UINT8_C( 80), UINT8_C(168), UINT8_C(243), UINT8_C(152), UINT8_C(225), UINT8_C(107), UINT8_C( 10), UINT8_C( 75) } },
    { { UINT8_C(134), UINT8_C( 27), UINT8_C(251), UINT8_C(168), UINT8_C(242), UINT8_C(113), UINT8_C(  0), UINT8_C(231),
        UINT8_C( 16), UINT8_C(182), UINT8_C(239), UINT8_C( 77), UINT8_C( 70), UINT8_C( 68), UINT8_C( 90), UINT8_C( 97),
        UINT8_C( 47), UINT8_C(245), UINT8_C(188), UINT8_C(242), UINT8_C(254), UINT8_C( 91), UINT8_C(  1), UINT8_C( 79),
        UINT8_C(  3), UINT8_C(244), UINT8_C(231), UINT8_C(228), UINT8_C( 95), UINT8_C(242), UINT8_C( 47), UINT8_C(229),
        UINT8_C( 13), UINT8_C( 43), UINT8_C(141),    UINT8_MAX, UINT8_C(156), UINT8_C(141), UINT8_C(230), UINT8_C(172),
        UINT8_C( 68), UINT8_C(213), UINT8_C(249), UINT8_C(138), UINT8_C( 25), UINT8_C( 83), UINT8_C(235), UINT8_C( 72),
        UINT8_C( 73), UINT8_C(167), UINT8_C( 58), UINT8_C( 71), UINT8_C(  2), UINT8_C( 59), UINT8_C(150), UINT8_C(  5),
        UINT8_C( 47), UINT8_C(126), UINT8_C(233), UINT8_C(143), UINT8_C(112), UINT8_C( 25), UINT8_C(116), UINT8_C(125) },
      { UINT8_C(134), UINT8_C( 27), UINT8_C(251), UINT8_C(168), UINT8_C(242), UINT8_C(113), UINT8_C(  0), UINT8_C(231),
        UINT8_C( 16), UINT8_C(182), UINT8_C(239), UINT8_C( 77), UINT8_C( 70), UINT8_C( 68), UINT8_C( 90), UINT8_C( 97),
        UINT8_C( 47), UINT8_C(245), UINT8_C(188), UINT8_C(242), UINT8_C(254), UINT8_C( 91), UINT8_C(  1), UINT8_C( 79),
        UINT8_C(  3), UINT8_C(244), UINT8_C(231), UINT8_C(228), UINT8_C( 95), UINT8_C(242), UINT8_C( 47), UINT8_C(229),
        UINT8_C( 13), UINT8_C( 43), UINT8_C(141),    UINT8_MAX, UINT8_C(156), UINT8_C(141), UINT8_C(230), UINT8_C(172),
        UINT8_C( 68), UINT8_C(213), UINT8_C(249), UINT8_C(138), UINT8_C( 25), UINT8_C( 83), UINT8_C(235), UINT8_C( 72),
        UINT8_C( 73), UINT8_C(167), UINT8_C( 58), UINT8_C( 71), UINT8_C(  2), UINT8_C( 59), UINT8_C(150), UINT8_C(  5),
        UINT8_C( 47), UINT8_C(126), UINT8_C(233), UINT8_C(143), UINT8_C(112), UINT8_C( 25), UINT8_C(116), UINT8_C(125) } },
    { { UINT8_C( 68), UINT8_C(  2), UINT8_C(124), UINT8_C(224), UINT8_C(143), UINT8_C( 98), UINT8_C(140), UINT8_C(211),
        UINT8_C( 55), UINT8_C(133), UINT8_C( 93), UINT8_C( 81), UINT8_C(217), UINT8_C( 72), UINT8_C(153), UINT8_C( 34),
        UINT8_C(239), UINT8_C(212), UINT8_C(105), UINT8_C(241), UINT8_C( 15), UINT8_C(  0), UINT8_C(246), UINT8_C( 63),
        UINT8_C(126), UINT8_C(224), UINT8_C(206), UINT8_C(238), UINT8_C(249), UINT8_C( 66), UINT8_C(107), UINT8_C( 61),
        UINT8_C( 68), UINT8_C(231), UINT8_C( 29), UINT8_C(212), UINT8_C( 73), UINT8_C(169), UINT8_C(167), UINT8_C(128),
        UINT8_C( 46), UINT8_C(  5), UINT8_C(209), UINT8_C(  7), UINT8_C( 77), UINT8_C(107), UINT8_C( 41), UINT8_C( 61),
        UINT8_C( 63), UINT8_C(147), UINT8_C( 46), UINT8_C( 78), UINT8_C(147), UINT8_C( 37), UINT8_C(141), UINT8_C( 17),
        UINT8_C(  5), UINT8_C( 91),    UINT8_MAX, UINT8_C(254), UINT8_C(158), UINT8_C(106), UINT8_C( 59), UINT8_C(226) },
      { UINT8_C( 68), UINT8_C(  2), UINT8_C(124), UINT8_C(224), UINT8_C(143), UINT8_C( 98), UINT8_C(140), UINT8_C(211),
        UINT8_C( 55), UINT8_C(133), UINT8_C( 93), UINT8_C( 81), UINT8_C(217), UINT8_C( 72), UINT8_C(153), UINT8_C( 34),
        UINT8_C(239), UINT8_C(212), UINT8_C(105), UINT8_C(241), UINT8_C( 15), UINT8_C(  0), UINT8_C(246), UINT8_C( 63),
        UINT8_C(126), UINT8_C(224), UINT8_C(206), UINT8_C(238), UINT8_C(249), UINT8_C( 66), UINT8_C(107), UINT8_C( 61),
        UINT8_C( 68), UINT8_C(231), UINT8_C( 29), UINT8_C(212), UINT8_C( 73), UINT8_C(169), UINT8_C(167), UINT8_C(128),
        UINT8_C( 46), UINT8_C(  5), UINT8_C(209), UINT8_C(  7), UINT8_C( 77), UINT8_C(107), UINT8_C( 41), UINT8_C( 61),
        UINT8_C( 63), UINT8_C(147), UINT8_C( 46), UINT8_C( 78), UINT8_C(147), UINT8_C( 37), UINT8_C(141), UINT8_C( 17),
        UINT8_C(  5), UINT8_C( 91),    UINT8_MAX, UINT8_C(254), UINT8_C(158), UINT8_C(106), UINT8_C( 59), UINT8_C(226) } },
    { { UINT8_C( 81), UINT8_C( 88), UINT8_C(182), UINT8_C(154), UINT8_C(  1), UINT8_C( 94), UINT8_C( 26), UINT8_C( 47),
        UINT8_C( 99), UINT8_C(236), UINT8_C( 55), UINT8_C(176), UINT8_C( 87), UINT8_C( 96), UINT8_C(237), UINT8_C(150),
        UINT8_C(243), UINT8_C( 28), UINT8_C(228), UINT8_C(134), UINT8_C( 65), UINT8_C(114), UINT8_C(151), UINT8_C( 70),
        UINT8_C(205), UINT8_C(150), UINT8_C( 68), UINT8_C(107), UINT8_C(  0), UINT8_C(127), UINT8_C( 78), UINT8_C( 81),
        UINT8_C(215), UINT8_C(  4), UINT8_C(235), UINT8_C(216), UINT8_C( 98), UINT8_C(  6), UINT8_C(  7), UINT8_C(197),
        UINT8_C(242), UINT8_C( 62), UINT8_C(118), UINT8_C( 73), UINT8_C(159), UINT8_C( 99), UINT8_C(223), UINT8_C(146),
        UINT8_C(127), UINT8_C(195), UINT8_C( 25), UINT8_C(192), UINT8_C( 53), UINT8_C(176), UINT8_C(  6), UINT8_C(  3),
        UINT8_C( 71), UINT8_C( 74), UINT8_C(110), UINT8_C( 71), UINT8_C(201), UINT8_C(188), UINT8_C(153), UINT8_C(160) },
      { UINT8_C( 81), UINT8_C( 88), UINT8_C(182), UINT8_C(154), UINT8_C(  1), UINT8_C( 94), UINT8_C( 26), UINT8_C( 47),
        UINT8_C( 99), UINT8_C(236), UINT8_C( 55), UINT8_C(176), UINT8_C( 87), UINT8_C( 96), UINT8_C(237), UINT8_C(150),
        UINT8_C(243), UINT8_C( 28), UINT8_C(228), UINT8_C(134), UINT8_C( 65), UINT8_C(114), UINT8_C(151), UINT8_C( 70),
        UINT8_C(205), UINT8_C(150), UINT8_C( 68), UINT8_C(107), UINT8_C(  0), UINT8_C(127), UINT8_C( 78), UINT8_C( 81),
        UINT8_C(215), UINT8_C(  4), UINT8_C(235), UINT8_C(216), UINT8_C( 98), UINT8_C(  6), UINT8_C(  7), UINT8_C(197),
        UINT8_C(242), UINT8_C( 62), UINT8_C(118), UINT8_C( 73), UINT8_C(159), UINT8_C( 99), UINT8_C(223), UINT8_C(146),
        UINT8_C(127), UINT8_C(195), UINT8_C( 25), UINT8_C(192), UINT8_C( 53), UINT8_C(176), UINT8_C(  6), UINT8_C(  3),
        UINT8_C( 71), UINT8_C( 74), UINT8_C(110), UINT8_C( 71), UINT8_C(201), UINT8_C(188), UINT8_C(153), UINT8_C(160) } },
    { { UINT8_C(193), UINT8_C(132), UINT8_C(120), UINT8_C( 35), UINT8_C(138), UINT8_C(128), UINT8_C(233), UINT8_C(124),
        UINT8_C(190), UINT8_C( 95), UINT8_C(197), UINT8_C( 93), UINT8_C(194), UINT8_C(164), UINT8_C(240), UINT8_C( 66),
        UINT8_C(104), UINT8_C(  9), UINT8_C(  2), UINT8_C(157), UINT8_C(185), UINT8_C(  9), UINT8_C(160), UINT8_C(  0),
        UINT8_C( 83), UINT8_C( 15), UINT8_C( 72), UINT8_C( 29), UINT8_C(203), UINT8_C(225), UINT8_C(189), UINT8_C(140),
        UINT8_C(101), UINT8_C( 54), UINT8_C(176), UINT8_C(240), UINT8_C(182), UINT8_C(153), UINT8_C(108), UINT8_C(116),
        UINT8_C(248), UINT8_C( 50), UINT8_C(210), UINT8_C(186), UINT8_C(214), UINT8_C(194), UINT8_C(252), UINT8_C( 62),
        UINT8_C(203),    UINT8_MAX, UINT8_C(220), UINT8_C(132), UINT8_C(  8), UINT8_C(124), UINT8_C(133), UINT8_C( 91),
        UINT8_C(139), UINT8_C(205), UINT8_C(120), UINT8_C( 87), UINT8_C(174), UINT8_C( 54), UINT8_C(227), UINT8_C( 19) },
      { UINT8_C(193), UINT8_C(132), UINT8_C(120), UINT8_C( 35), UINT8_C(138), UINT8_C(128), UINT8_C(233), UINT8_C(124),
        UINT8_C(190), UINT8_C( 95), UINT8_C(197), UINT8_C( 93), UINT8_C(194), UINT8_C(164), UINT8_C(240), UINT8_C( 66),
        UINT8_C(104), UINT8_C(  9), UINT8_C(  2), UINT8_C(157), UINT8_C(185), UINT8_C(  9), UINT8_C(160), UINT8_C(  0),
        UINT8_C( 83), UINT8_C( 15), UINT8_C( 72), UINT8_C( 29), UINT8_C(203), UINT8_C(225), UINT8_C(189), UINT8_C(140),
        UINT8_C(101), UINT8_C( 54), UINT8_C(176), UINT8_C(240), UINT8_C(182), UINT8_C(153), UINT8_C(108), UINT8_C(116),
        UINT8_C(248), UINT8_C( 50), UINT8_C(210), UINT8_C(186), UINT8_C(214), UINT8_C(194), UINT8_C(252), UINT8_C( 62),
        UINT8_C(203),    UINT8_MAX, UINT8_C(220), UINT8_C(132), UINT8_C(  8), UINT8_C(124), UINT8_C(133), UINT8_C( 91),
        UINT8_C(139), UINT8_C(205), UINT8_C(120), UINT8_C( 87), UINT8_C(174), UINT8_C( 54), UINT8_C(227), UINT8_C( 19) } },
    { { UINT8_C(108), UINT8_C(147), UINT8_C(  3), UINT8_C( 34), UINT8_C( 44), UINT8_C(112), UINT8_C(150), UINT8_C( 36),
        UINT8_C(162), UINT8_C(104), UINT8_C(223), UINT8_C(120), UINT8_C( 42), UINT8_C(219), UINT8_C(183), UINT8_C(245),
        UINT8_C(218), UINT8_C(147), UINT8_C(122), UINT8_C(226), UINT8_C( 15),    UINT8_MAX, UINT8_C( 62), UINT8_C(155),
        UINT8_C(204), UINT8_C(182), UINT8_C(242), UINT8_C(122), UINT8_C(236), UINT8_C(213), UINT8_C(141), UINT8_C( 88),
        UINT8_C(105), UINT8_C(145), UINT8_C(122), UINT8_C(149), UINT8_C(  1), UINT8_C( 17), UINT8_C(186), UINT8_C(163),
        UINT8_C(121), UINT8_C(153), UINT8_C( 27), UINT8_C(164), UINT8_C(116), UINT8_C(210), UINT8_C(153), UINT8_C( 79),
        UINT8_C(101), UINT8_C( 19), UINT8_C( 49), UINT8_C(117), UINT8_C( 18), UINT8_C(111), UINT8_C( 16), UINT8_C(222),
        UINT8_C( 38), UINT8_C(  2), UINT8_C( 88), UINT8_C( 18), UINT8_C(215), UINT8_C(230), UINT8_C(107), UINT8_C( 64) },
      { UINT8_C(108), UINT8_C(147), UINT8_C(  3), UINT8_C( 34), UINT8_C( 44), UINT8_C(112), UINT8_C(150), UINT8_C( 36),
        UINT8_C(162), UINT8_C(104), UINT8_C(223), UINT8_C(120), UINT8_C( 42), UINT8_C(219), UINT8_C(183), UINT8_C(245),
        UINT8_C(218), UINT8_C(147), UINT8_C(122), UINT8_C(226), UINT8_C( 15),    UINT8_MAX, UINT8_C( 62), UINT8_C(155),
        UINT8_C(204), UINT8_C(182), UINT8_C(242), UINT8_C(122), UINT8_C(236), UINT8_C(213), UINT8_C(141), UINT8_C( 88),
        UINT8_C(105), UINT8_C(145), UINT8_C(122), UINT8_C(149), UINT8_C(  1), UINT8_C( 17), UINT8_C(186), UINT8_C(163),
        UINT8_C(121), UINT8_C(153), UINT8_C( 27), UINT8_C(164), UINT8_C(116), UINT8_C(210), UINT8_C(153), UINT8_C( 79),
        UINT8_C(101), UINT8_C( 19), UINT8_C( 49), UINT8_C(117), UINT8_C( 18), UINT8_C(111), UINT8_C( 16), UINT8_C(222),
        UINT8_C( 38), UINT8_C(  2), UINT8_C( 88), UINT8_C( 18), UINT8_C(215), UINT8_C(230), UINT8_C(107), UINT8_C( 64) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i r = simde_x_mm512_set_epu8(
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
    simde_test_x86_assert_equal_u8x64(r, simde_mm512_loadu_si512(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m512i a = simde_test_x86_random_u8x64();
    simde__m512i r = a;

    simde_test_x86_write_u8x64(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_u8x64(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_x_mm512_set_epu16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const uint16_t a[32];
    const uint16_t r[32];
  } test_vec[] = {
    { { UINT16_C( 4444), UINT16_C( 2014), UINT16_C(59869), UINT16_C(26792), UINT16_C(16109), UINT16_C(65375), UINT16_C(55446), UINT16_C(23385),
        UINT16_C(13676), UINT16_C(40345), UINT16_C(34579), UINT16_C(59195), UINT16_C(62220), UINT16_C(34651), UINT16_C(15434), UINT16_C(42737),
        UINT16_C(53070), UINT16_C(11181), UINT16_C(22200), UINT16_C(42387), UINT16_C(62100), UINT16_C(11172), UINT16_C(65226), UINT16_C(13958),
        UINT16_C( 7987), UINT16_C(18132), UINT16_C( 4007), UINT16_C(45870), UINT16_C(35074), UINT16_C(19770), UINT16_C(11205), UINT16_C( 5107) },
      { UINT16_C( 4444), UINT16_C( 2014), UINT16_C(59869), UINT16_C(26792), UINT16_C(16109), UINT16_C(65375), UINT16_C(55446), UINT16_C(23385),
        UINT16_C(13676), UINT16_C(40345), UINT16_C(34579), UINT16_C(59195), UINT16_C(62220), UINT16_C(34651), UINT16_C(15434), UINT16_C(42737),
        UINT16_C(53070), UINT16_C(11181), UINT16_C(22200), UINT16_C(42387), UINT16_C(62100), UINT16_C(11172), UINT16_C(65226), UINT16_C(13958),
        UINT16_C( 7987), UINT16_C(18132), UINT16_C( 4007), UINT16_C(45870), UINT16_C(35074), UINT16_C(19770), UINT16_C(11205), UINT16_C( 5107) } },
    { { UINT16_C(41467), UINT16_C(45887), UINT16_C(54007), UINT16_C(35673), UINT16_C(64965), UINT16_C(36790), UINT16_C(15611), UINT16_C(11974),
        UINT16_C(39516), UINT16_C(  885), UINT16_C(41897), UINT16_C(44214), UINT16_C(61484), UINT16_C(61945), UINT16_C(60444), UINT16_C( 5893),
        UINT16_C(17549), UINT16_C(33994), UINT16_C( 8982), UINT16_C(56080), UINT16_C(50721), UINT16_C( 7275), UINT16_C(12547), UINT16_C(24395),
        UINT16_C(49355), UINT16_C(29794), UINT16_C( 6243), UINT16_C(36640), UINT16_C( 6408), UINT16_C( 9344), UINT16_C(34054), UINT16_C(37691) },
      { UINT16_C(41467), UINT16_C(45887), UINT16_C(54007), UINT16_C(35673), UINT16_C(64965), UINT16_C(36790), UINT16_C(15611), UINT16_C(11974),
        UINT16_C(39516), UINT16_C(  885), UINT16_C(41897), UINT16_C(44214), UINT16_C(61484), UINT16_C(61945), UINT16_C(60444), UINT16_C( 5893),
        UINT16_C(17549), UINT16_C(33994), UINT16_C( 8982), UINT16_C(56080), UINT16_C(50721), UINT16_C( 7275), UINT16_C(12547), UINT16_C(24395),
        UINT16_C(49355), UINT16_C(29794), UINT16_C( 6243), UINT16_C(36640), UINT16_C( 6408), UINT16_C( 9344), UINT16_C(34054), UINT16_C(37691) } },
    { { UINT16_C( 1737), UINT16_C(57368), UINT16_C(10281), UINT16_C(19131), UINT16_C( 9966), UINT16_C(61799), UINT16_C(45655), UINT16_C( 8784),
        UINT16_C(45682), UINT16_C(54679), UINT16_C(47050), UINT16_C(54116), UINT16_C(58577), UINT16_C(55287), UINT16_C(13162), UINT16_C(13162),
        UINT16_C(33337), UINT16_C(25107), UINT16_C(53162), UINT16_C(39341), UINT16_C( 5365), UINT16_C(19850), UINT16_C(56262), UINT16_C(14447),
        UINT16_C( 1677), UINT16_C(22541), UINT16_C(29118), UINT16_C(36651), UINT16_C( 8789), UINT16_C(48998), UINT16_C(53333), UINT16_C(36595) },
      { UINT16_C( 1737), UINT16_C(57368), UINT16_C(10281), UINT16_C(19131), UINT16_C( 9966), UINT16_C(61799), UINT16_C(45655), UINT16_C( 8784),
        UINT16_C(45682), UINT16_C(54679), UINT16_C(47050), UINT16_C(54116), UINT16_C(58577), UINT16_C(55287), UINT16_C(13162), UINT16_C(13162),
        UINT16_C(33337), UINT16_C(25107), UINT16_C(53162), UINT16_C(39341), UINT16_C( 5365), UINT16_C(19850), UINT16_C(56262), UINT16_C(14447),
        UINT16_C( 1677), UINT16_C(22541), UINT16_C(29118), UINT16_C(36651), UINT16_C( 8789), UINT16_C(48998), UINT16_C(53333), UINT16_C(36595) } },
    { { UINT16_C( 1619), UINT16_C(65009), UINT16_C(40661), UINT16_C(52118), UINT16_C( 8626), UINT16_C(30744), UINT16_C(34812), UINT16_C(35248),
        UINT16_C(48526), UINT16_C(19681), UINT16_C( 3118), UINT16_C(33755), UINT16_C(16687), UINT16_C(33859), UINT16_C(13841), UINT16_C(25619),
        UINT16_C( 1084), UINT16_C( 4706), UINT16_C(63650), UINT16_C(21725), UINT16_C(62745), UINT16_C( 5580), UINT16_C(31868), UINT16_C( 2719),
        UINT16_C(32825), UINT16_C(26454), UINT16_C(12685), UINT16_C(48362), UINT16_C(11634), UINT16_C(33856), UINT16_C(21347), UINT16_C(41192) },
      { UINT16_C( 1619), UINT16_C(65009), UINT16_C(40661), UINT16_C(52118), UINT16_C( 8626), UINT16_C(30744), UINT16_C(34812), UINT16_C(35248),
        UINT16_C(48526), UINT16_C(19681), UINT16_C( 3118), UINT16_C(33755), UINT16_C(16687), UINT16_C(33859), UINT16_C(13841), UINT16_C(25619),
        UINT16_C( 1084), UINT16_C( 4706), UINT16_C(63650), UINT16_C(21725), UINT16_C(62745), UINT16_C( 5580), UINT16_C(31868), UINT16_C( 2719),
        UINT16_C(32825), UINT16_C(26454), UINT16_C(12685), UINT16_C(48362), UINT16_C(11634), UINT16_C(33856), UINT16_C(21347), UINT16_C(41192) } },
    { { UINT16_C(19031), UINT16_C(63922), UINT16_C(36675), UINT16_C(23629), UINT16_C( 6532), UINT16_C(  114), UINT16_C( 4501), UINT16_C(52747),
        UINT16_C(24977), UINT16_C( 7733), UINT16_C( 8339), UINT16_C( 1498), UINT16_C( 6989), UINT16_C(45449), UINT16_C(29294), UINT16_C(50769),
        UINT16_C(  956), UINT16_C(65471), UINT16_C( 3474), UINT16_C( 5724), UINT16_C(52774), UINT16_C(48150), UINT16_C( 8671), UINT16_C(28810),
        UINT16_C(49283), UINT16_C( 5775), UINT16_C(27104), UINT16_C(11547), UINT16_C(42372), UINT16_C(62430), UINT16_C(12055), UINT16_C(54201) },
      { UINT16_C(19031), UINT16_C(63922), UINT16_C(36675), UINT16_C(23629), UINT16_C( 6532), UINT16_C(  114), UINT16_C( 4501), UINT16_C(52747),
        UINT16_C(24977), UINT16_C( 7733), UINT16_C( 8339), UINT16_C( 1498), UINT16_C( 6989), UINT16_C(45449), UINT16_C(29294), UINT16_C(50769),
        UINT16_C(  956), UINT16_C(65471), UINT16_C( 3474), UINT16_C( 5724), UINT16_C(52774), UINT16_C(48150), UINT16_C( 8671), UINT16_C(28810),
        UINT16_C(49283), UINT16_C( 5775), UINT16_C(27104), UINT16_C(11547), UINT16_C(42372), UINT16_C(62430), UINT16_C(12055), UINT16_C(54201) } },
    { { UINT16_C(30770), UINT16_C(50387), UINT16_C(12165), UINT16_C(44250), UINT16_C(61949), UINT16_C(56424), UINT16_C(61970), UINT16_C(38220),
        UINT16_C(56242), UINT16_C(37547), UINT16_C(51013), UINT16_C(51648), UINT16_C(40556), UINT16_C(33724), UINT16_C(30158), UINT16_C(   86),
        UINT16_C(10734), UINT16_C(29637), UINT16_C(40792), UINT16_C(21791), UINT16_C(34704), UINT16_C(41777), UINT16_C(32378), UINT16_C(11320),
        UINT16_C(58457), UINT16_C(40639), UINT16_C(32683), UINT16_C( 5992), UINT16_C( 9245), UINT16_C(60314), UINT16_C(61594), UINT16_C(35052) },
      { UINT16_C(30770), UINT16_C(50387), UINT16_C(12165), UINT16_C(44250), UINT16_C(61949), UINT16_C(56424), UINT16_C(61970), UINT16_C(38220),
        UINT16_C(56242), UINT16_C(37547), UINT16_C(51013), UINT16_C(51648), UINT16_C(40556), UINT16_C(33724), UINT16_C(30158), UINT16_C(   86),
        UINT16_C(10734), UINT16_C(29637), UINT16_C(40792), UINT16_C(21791), UINT16_C(34704), UINT16_C(41777), UINT16_C(32378), UINT16_C(11320),
        UINT16_C(58457), UINT16_C(40639), UINT16_C(32683), UINT16_C( 5992), UINT16_C( 9245), UINT16_C(60314), UINT16_C(61594), UINT16_C(35052) } },
    { { UINT16_C(45338), UINT16_C(29435), UINT16_C( 6992), UINT16_C(57800), UINT16_C(63906), UINT16_C( 7300), UINT16_C(48247), UINT16_C(53577),
        UINT16_C( 2208), UINT16_C(19311), UINT16_C(55175), UINT16_C(42082), UINT16_C(64764), UINT16_C(38544), UINT16_C(31981), UINT16_C( 1822),
        UINT16_C( 6445), UINT16_C(32121), UINT16_C(16692), UINT16_C(55134), UINT16_C(57915), UINT16_C(45811), UINT16_C(15519), UINT16_C(16259),
        UINT16_C(62276), UINT16_C(52107), UINT16_C(60874), UINT16_C(50800), UINT16_C(  234), UINT16_C(55132), UINT16_C(31356), UINT16_C(43486) },
      { UINT16_C(45338), UINT16_C(29435), UINT16_C( 6992), UINT16_C(57800), UINT16_C(63906), UINT16_C( 7300), UINT16_C(48247), UINT16_C(53577),
        UINT16_C( 2208), UINT16_C(19311), UINT16_C(55175), UINT16_C(42082), UINT16_C(64764), UINT16_C(38544), UINT16_C(31981), UINT16_C( 1822),
        UINT16_C( 6445), UINT16_C(32121), UINT16_C(16692), UINT16_C(55134), UINT16_C(57915), UINT16_C(45811), UINT16_C(15519), UINT16_C(16259),
        UINT16_C(62276), UINT16_C(52107), UINT16_C(60874), UINT16_C(50800), UINT16_C(  234), UINT16_C(55132), UINT16_C(31356), UINT16_C(43486) } },
    { { UINT16_C(22420), UINT16_C(51238), UINT16_C(34201), UINT16_C(54431), UINT16_C(37735), UINT16_C( 1670), UINT16_C( 2767), UINT16_C( 5190),
        UINT16_C(53757), UINT16_C(51167), UINT16_C(20414), UINT16_C(43150), UINT16_C(59983), UINT16_C(52095), UINT16_C(23909), UINT16_C(63860),
        UINT16_C(39861), UINT16_C(20161), UINT16_C(24864), UINT16_C(34594), UINT16_C(43252), UINT16_C(50062), UINT16_C(54450), UINT16_C(45015),
        UINT16_C(47013), UINT16_C(25463), UINT16_C( 1286), UINT16_C(22028), UINT16_C(35823), UINT16_C(21537), UINT16_C(38633), UINT16_C(40525) },
      { UINT16_C(22420), UINT16_C(51238), UINT16_C(34201), UINT16_C(54431), UINT16_C(37735), UINT16_C( 1670), UINT16_C( 2767), UINT16_C( 5190),
        UINT16_C(53757), UINT16_C(51167), UINT16_C(20414), UINT16_C(43150), UINT16_C(59983), UINT16_C(52095), UINT16_C(23909), UINT16_C(63860),
        UINT16_C(39861), UINT16_C(20161), UINT16_C(24864), UINT16_C(34594), UINT16_C(43252), UINT16_C(50062), UINT16_C(54450), UINT16_C(45015),
        UINT16_C(47013), UINT16_C(25463), UINT16_C( 1286), UINT16_C(22028), UINT16_C(35823), UINT16_C(21537), UINT16_C(38633), UINT16_C(40525) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i r = simde_x_mm512_set_epu16(
        test_vec[i].a[31], test_vec[i].a[30], test_vec[i].a[29], test_vec[i].a[28],
        test_vec[i].a[27], test_vec[i].a[26], test_vec[i].a[25], test_vec[i].a[24],
        test_vec[i].a[23], test_vec[i].a[22], test_vec[i].a[21], test_vec[i].a[20],
        test_vec[i].a[19], test_vec[i].a[18], test_vec[i].a[17], test_vec[i].a[16],
        test_vec[i].a[15], test_vec[i].a[14], test_vec[i].a[13], test_vec[i].a[12],
        test_vec[i].a[11], test_vec[i].a[10], test_vec[i].a[ 9], test_vec[i].a[ 8],
        test_vec[i].a[ 7], test_vec[i].a[ 6], test_vec[i].a[ 5], test_vec[i].a[ 4],
        test_vec[i].a[ 3], test_vec[i].a[ 2], test_vec[i].a[ 1], test_vec[i].a[ 0]);
    simde_test_x86_assert_equal_u16x32(r, simde_mm512_loadu_si512(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m512i a = simde_test_x86_random_u16x32();
    simde__m512i r = a;

    simde_test_x86_write_u16x32(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_u16x32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_x_mm512_set_epu32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const uint32_t a[16];
    const uint32_t r[16];
  } test_vec[] = {
    { { UINT32_C(1205155406), UINT32_C(3238136312), UINT32_C(2341122395), UINT32_C(3153248567), UINT32_C(  74890403), UINT32_C(2746889127), UINT32_C( 159224512), UINT32_C(2569338698),
        UINT32_C( 769718581), UINT32_C(1592713731), UINT32_C(3421141395), UINT32_C(3716602938), UINT32_C(1071775128), UINT32_C(4041382704), UINT32_C(2029608749), UINT32_C(2484149854) },
      { UINT32_C(1205155406), UINT32_C(3238136312), UINT32_C(2341122395), UINT32_C(3153248567), UINT32_C(  74890403), UINT32_C(2746889127), UINT32_C( 159224512), UINT32_C(2569338698),
        UINT32_C( 769718581), UINT32_C(1592713731), UINT32_C(3421141395), UINT32_C(3716602938), UINT32_C(1071775128), UINT32_C(4041382704), UINT32_C(2029608749), UINT32_C(2484149854) } },
    { { UINT32_C( 448917783), UINT32_C(1719251155), UINT32_C(1664181033), UINT32_C(3611342911), UINT32_C(3843432885), UINT32_C(3923179964), UINT32_C(3076640600), UINT32_C(  88830701),
        UINT32_C( 908004451), UINT32_C(3852310716), UINT32_C( 977850107), UINT32_C( 991004806), UINT32_C(1696671913), UINT32_C(2035283745), UINT32_C(3023089862), UINT32_C(2260302627) },
      { UINT32_C( 448917783), UINT32_C(1719251155), UINT32_C(1664181033), UINT32_C(3611342911), UINT32_C(3843432885), UINT32_C(3923179964), UINT32_C(3076640600), UINT32_C(  88830701),
        UINT32_C( 908004451), UINT32_C(3852310716), UINT32_C( 977850107), UINT32_C( 991004806), UINT32_C(1696671913), UINT32_C(2035283745), UINT32_C(3023089862), UINT32_C(2260302627) } },
    { { UINT32_C(1153292424), UINT32_C(1814714993), UINT32_C(2946986536), UINT32_C(2766846203), UINT32_C(  17435616), UINT32_C(3380304130), UINT32_C( 746433289), UINT32_C(2947757607),
        UINT32_C(2146660366), UINT32_C(4075560394), UINT32_C(2342622096), UINT32_C( 741313611), UINT32_C(2586655127), UINT32_C(2623776914), UINT32_C(2076762196), UINT32_C( 606763798) },
      { UINT32_C(1153292424), UINT32_C(1814714993), UINT32_C(2946986536), UINT32_C(2766846203), UINT32_C(  17435616), UINT32_C(3380304130), UINT32_C( 746433289), UINT32_C(2947757607),
        UINT32_C(2146660366), UINT32_C(4075560394), UINT32_C(2342622096), UINT32_C( 741313611), UINT32_C(2586655127), UINT32_C(2623776914), UINT32_C(2076762196), UINT32_C( 606763798) } },
    { { UINT32_C(3047431659), UINT32_C(3416821819), UINT32_C(1851148579), UINT32_C(1838843349), UINT32_C(1359464639), UINT32_C(3303893616), UINT32_C(1614788170), UINT32_C( 495216945),
        UINT32_C(3268552839), UINT32_C(3683482296), UINT32_C(2571822020), UINT32_C( 654763112), UINT32_C( 494472620), UINT32_C(3252774519), UINT32_C(1310794012), UINT32_C( 292267658) },
      { UINT32_C(3047431659), UINT32_C(3416821819), UINT32_C(1851148579), UINT32_C(1838843349), UINT32_C(1359464639), UINT32_C(3303893616), UINT32_C(1614788170), UINT32_C( 495216945),
        UINT32_C(3268552839), UINT32_C(3683482296), UINT32_C(2571822020), UINT32_C( 654763112), UINT32_C( 494472620), UINT32_C(3252774519), UINT32_C(1310794012), UINT32_C( 292267658) } },
    { { UINT32_C(2278768078), UINT32_C(2086822072), UINT32_C(2887101507), UINT32_C(1037245585), UINT32_C(2707049513), UINT32_C(3479321779), UINT32_C(3877471325), UINT32_C(4177102890),
        UINT32_C(2122304710), UINT32_C(1895490093), UINT32_C( 521932686), UINT32_C(1432219691), UINT32_C(4025923388), UINT32_C(1354717427), UINT32_C( 104389852), UINT32_C( 738144613) },
      { UINT32_C(2278768078), UINT32_C(2086822072), UINT32_C(2887101507), UINT32_C(1037245585), UINT32_C(2707049513), UINT32_C(3479321779), UINT32_C(3877471325), UINT32_C(4177102890),
        UINT32_C(2122304710), UINT32_C(1895490093), UINT32_C( 521932686), UINT32_C(1432219691), UINT32_C(4025923388), UINT32_C(1354717427), UINT32_C( 104389852), UINT32_C( 738144613) } },
    { { UINT32_C( 715751165), UINT32_C(4019954528), UINT32_C(3725506482), UINT32_C(3828575143), UINT32_C( 382937379), UINT32_C(1583846017), UINT32_C(3563364207), UINT32_C(3456066512),
        UINT32_C(1123592418), UINT32_C(4247884619), UINT32_C(4074455114), UINT32_C(3470134955), UINT32_C(3118836023), UINT32_C(2870430780), UINT32_C(3145694187), UINT32_C(3246948063) },
      { UINT32_C( 715751165), UINT32_C(4019954528), UINT32_C(3725506482), UINT32_C(3828575143), UINT32_C( 382937379), UINT32_C(1583846017), UINT32_C(3563364207), UINT32_C(3456066512),
        UINT32_C(1123592418), UINT32_C(4247884619), UINT32_C(4074455114), UINT32_C(3470134955), UINT32_C(3118836023), UINT32_C(2870430780), UINT32_C(3145694187), UINT32_C(3246948063) } },
    { { UINT32_C(1896054822), UINT32_C(1584280851), UINT32_C( 542132853), UINT32_C(2431592024), UINT32_C( 189387983), UINT32_C( 196501536), UINT32_C(3133552091), UINT32_C(3648736947),
        UINT32_C(3796533199), UINT32_C( 692107700), UINT32_C(1531547651), UINT32_C(2263562422), UINT32_C( 747713548), UINT32_C(1882671252), UINT32_C( 824900989), UINT32_C( 453682764) },
      { UINT32_C(1896054822), UINT32_C(1584280851), UINT32_C( 542132853), UINT32_C(2431592024), UINT32_C( 189387983), UINT32_C( 196501536), UINT32_C(3133552091), UINT32_C(3648736947),
        UINT32_C(3796533199), UINT32_C( 692107700), UINT32_C(1531547651), UINT32_C(2263562422), UINT32_C( 747713548), UINT32_C(1882671252), UINT32_C( 824900989), UINT32_C( 453682764) } },
    { { UINT32_C(3657258277), UINT32_C( 285359630), UINT32_C(2238467022), UINT32_C(2416662660), UINT32_C( 566074508), UINT32_C(1653732580), UINT32_C(1049869298), UINT32_C(2254019937),
        UINT32_C(   6248178), UINT32_C(1662083476), UINT32_C( 837320365), UINT32_C(1656878038), UINT32_C(1954774671), UINT32_C(1708528755), UINT32_C( 832793040), UINT32_C(4189649926) },
      { UINT32_C(3657258277), UINT32_C( 285359630), UINT32_C(2238467022), UINT32_C(2416662660), UINT32_C( 566074508), UINT32_C(1653732580), UINT32_C(1049869298), UINT32_C(2254019937),
        UINT32_C(   6248178), UINT32_C(1662083476), UINT32_C( 837320365), UINT32_C(1656878038), UINT32_C(1954774671), UINT32_C(1708528755), UINT32_C( 832793040), UINT32_C(4189649926) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i r = simde_x_mm512_set_epu32(
        test_vec[i].a[15], test_vec[i].a[14], test_vec[i].a[13], test_vec[i].a[12],
        test_vec[i].a[11], test_vec[i].a[10], test_vec[i].a[ 9], test_vec[i].a[ 8],
        test_vec[i].a[ 7], test_vec[i].a[ 6], test_vec[i].a[ 5], test_vec[i].a[ 4],
        test_vec[i].a[ 3], test_vec[i].a[ 2], test_vec[i].a[ 1], test_vec[i].a[ 0]);
    simde_test_x86_assert_equal_u32x16(r, simde_mm512_loadu_si512(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m512i a = simde_test_x86_random_u32x16();
    simde__m512i r = a;

    simde_test_x86_write_u32x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_u32x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_x_mm512_set_epu64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const uint64_t a[8];
    const uint64_t r[8];
  } test_vec[] = {
    { { UINT64_C( 9568876967930616576), UINT64_C( 1977685269037764613), UINT64_C(12099231501399065555), UINT64_C(11415431664820641660),
        UINT64_C(15423112186462623646), UINT64_C( 9806705514186837686), UINT64_C(14593810477667070957), UINT64_C( 5277464135911991297) },
      { UINT64_C( 9568876967930616576), UINT64_C( 1977685269037764613), UINT64_C(12099231501399065555), UINT64_C(11415431664820641660),
        UINT64_C(15423112186462623646), UINT64_C( 9806705514186837686), UINT64_C(14593810477667070957), UINT64_C( 5277464135911991297) } },
    { { UINT64_C(17604808701939439528), UINT64_C(11574824657151412326), UINT64_C(18254505445852994108), UINT64_C( 3739352784258743024),
        UINT64_C(17321685887824540208), UINT64_C(10996010580011864901), UINT64_C( 1225392656820148488), UINT64_C(11993526120196382130) },
      { UINT64_C(17604808701939439528), UINT64_C(11574824657151412326), UINT64_C(18254505445852994108), UINT64_C( 3739352784258743024),
        UINT64_C(17321685887824540208), UINT64_C(10996010580011864901), UINT64_C( 1225392656820148488), UINT64_C(11993526120196382130) } },
    { { UINT64_C( 7042915254054166082), UINT64_C( 9133003683600648393), UINT64_C(  810229402012147980), UINT64_C(13563922312914922016),
        UINT64_C(10472636907640148441), UINT64_C(12538994028906458895), UINT64_C( 2934685632269354325), UINT64_C(10969075163009516291) },
      { UINT64_C( 7042915254054166082), UINT64_C( 9133003683600648393), UINT64_C(  810229402012147980), UINT64_C(13563922312914922016),
        UINT64_C(10472636907640148441), UINT64_C(12538994028906458895), UINT64_C( 2934685632269354325), UINT64_C(10969075163009516291) } },
    { { UINT64_C( 1847851379545981772), UINT64_C( 2729923334964730770), UINT64_C(15661705130239311144), UINT64_C( 6838592967500240785),
        UINT64_C(16894715616612742227), UINT64_C(16169613402998445425), UINT64_C( 6372146828696107454), UINT64_C(12173950340448109953) },
      { UINT64_C( 1847851379545981772), UINT64_C( 2729923334964730770), UINT64_C(15661705130239311144), UINT64_C( 6838592967500240785),
        UINT64_C(16894715616612742227), UINT64_C(16169613402998445425), UINT64_C( 6372146828696107454), UINT64_C(12173950340448109953) } },
    { { UINT64_C(17025149731787334659), UINT64_C( 2533718324306338705), UINT64_C( 2660262488892258764), UINT64_C( 2731619138579960811),
        UINT64_C(18047266663832808717), UINT64_C(   49658568865194281), UINT64_C( 8821566023486695589), UINT64_C(15806125943958479890) },
      { UINT64_C(17025149731787334659), UINT64_C( 2533718324306338705), UINT64_C( 2660262488892258764), UINT64_C( 2731619138579960811),
        UINT64_C(18047266663832808717), UINT64_C(   49658568865194281), UINT64_C( 8821566023486695589), UINT64_C(15806125943958479890) } },
    { { UINT64_C(14552493382336502417), UINT64_C( 5236568866277439352), UINT64_C(15166432225493336175), UINT64_C( 7550955305296147489),
        UINT64_C( 8981398135744113979), UINT64_C( 8176799704330861453), UINT64_C( 3001623896520657429), UINT64_C( 5430745283826331165) },
      { UINT64_C(14552493382336502417), UINT64_C( 5236568866277439352), UINT64_C(15166432225493336175), UINT64_C( 7550955305296147489),
        UINT64_C( 8981398135744113979), UINT64_C( 8176799704330861453), UINT64_C( 3001623896520657429), UINT64_C( 5430745283826331165) } },
    { { UINT64_C(11785862045522902799), UINT64_C(11545344382506153926), UINT64_C(12648110592980527447), UINT64_C(10386991247824035787),
        UINT64_C(15959123307507436736), UINT64_C(17444094590476177129), UINT64_C( 8343719476181633928), UINT64_C( 3497454609902759543) },
      { UINT64_C(11785862045522902799), UINT64_C(11545344382506153926), UINT64_C(12648110592980527447), UINT64_C(10386991247824035787),
        UINT64_C(15959123307507436736), UINT64_C(17444094590476177129), UINT64_C( 8343719476181633928), UINT64_C( 3497454609902759543) } },
    { { UINT64_C( 5311573959664610753), UINT64_C(14077077308112264142), UINT64_C(18120981335683017822), UINT64_C(18353996134117328919),
        UINT64_C(  888207745324858795), UINT64_C( 4892547352263725544), UINT64_C( 9510692481256833917), UINT64_C( 1929722551698321804) },
      { UINT64_C( 5311573959664610753), UINT64_C(14077077308112264142), UINT64_C(18120981335683017822), UINT64_C(18353996134117328919),
        UINT64_C(  888207745324858795), UINT64_C( 4892547352263725544), UINT64_C( 9510692481256833917), UINT64_C( 1929722551698321804) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i r = simde_x_mm512_set_epu64(
        test_vec[i].a[ 7], test_vec[i].a[ 6], test_vec[i].a[ 5], test_vec[i].a[ 4],
        test_vec[i].a[ 3], test_vec[i].a[ 2], test_vec[i].a[ 1], test_vec[i].a[ 0]);
    simde_test_x86_assert_equal_u32x16(r, simde_mm512_loadu_si512(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m512i a = simde_test_x86_random_u64x8();
    simde__m512i r = a;

    simde_test_x86_write_u64x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_u64x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_x_mm512_set_m128i (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int64_t a[2];
    const int64_t b[2];
    const int64_t c[2];
    const int64_t d[2];
    const int64_t r[8];
  } test_vec[] = {
    { { -INT64_C( 4945782109098626019), -INT64_C( 8008920059667144479) },
      {  INT64_C(  124491825340358826), -INT64_C( 2233212823795404972) },
      { -INT64_C( 6712500070265408579),  INT64_C( 2791111895643054729) },
      {  INT64_C( 3661060217106896421),  INT64_C( 7441641663673639585) },
      {  INT64_C( 3661060217106896421),  INT64_C( 7441641663673639585), -INT64_C( 6712500070265408579),  INT64_C( 2791111895643054729),
         INT64_C(  124491825340358826), -INT64_C( 2233212823795404972), -INT64_C( 4945782109098626019), -INT64_C( 8008920059667144479) } },
    { {  INT64_C( 4835561680396374457),  INT64_C( 8277945198645823295) },
      {  INT64_C( 3301716370139371969), -INT64_C( 7727655949450422865) },
      { -INT64_C( 2150704513163639254), -INT64_C( 9066169629291997584) },
      {  INT64_C( 3031191362149182807), -INT64_C( 6469343367862639927) },
      {  INT64_C( 3031191362149182807), -INT64_C( 6469343367862639927), -INT64_C( 2150704513163639254), -INT64_C( 9066169629291997584),
         INT64_C( 3301716370139371969), -INT64_C( 7727655949450422865),  INT64_C( 4835561680396374457),  INT64_C( 8277945198645823295) } },
    { { -INT64_C( 2372919338038835572), -INT64_C( 8823455275125330104) },
      {  INT64_C( 7844558766122511927),  INT64_C( 3691906778662986010) },
      { -INT64_C( 4477294391523621233),  INT64_C( 8851076585001547811) },
      { -INT64_C( 3453124338471125754), -INT64_C(  196290940105251477) },
      { -INT64_C( 3453124338471125754), -INT64_C(  196290940105251477), -INT64_C( 4477294391523621233),  INT64_C( 8851076585001547811),
         INT64_C( 7844558766122511927),  INT64_C( 3691906778662986010), -INT64_C( 2372919338038835572), -INT64_C( 8823455275125330104) } },
    { {  INT64_C( 4585464989178636392), -INT64_C( 3887339008387158704) },
      { -INT64_C( 5897314988725159517), -INT64_C( 7415451457765208404) },
      {  INT64_C( 4254526067743265455), -INT64_C( 6694360051734373495) },
      { -INT64_C( 4682296576377582828),  INT64_C( 8898252826075580083) },
      { -INT64_C( 4682296576377582828),  INT64_C( 8898252826075580083),  INT64_C( 4254526067743265455), -INT64_C( 6694360051734373495),
        -INT64_C( 5897314988725159517), -INT64_C( 7415451457765208404),  INT64_C( 4585464989178636392), -INT64_C( 3887339008387158704) } },
    { { -INT64_C( 7266186282525002237), -INT64_C( 1832681567916787731) },
      {  INT64_C( 7232011006770056588),  INT64_C( 3121491696417257225) },
      { -INT64_C( 2924732906769639237), -INT64_C( 2309688744207887815) },
      {  INT64_C( 9077527813400899811), -INT64_C( 4583076703419285230) },
      {  INT64_C( 9077527813400899811), -INT64_C( 4583076703419285230), -INT64_C( 2924732906769639237), -INT64_C( 2309688744207887815),
         INT64_C( 7232011006770056588),  INT64_C( 3121491696417257225), -INT64_C( 7266186282525002237), -INT64_C( 1832681567916787731) } },
    { { -INT64_C(  288239442164023491), -INT64_C(  181278566807845815) },
      { -INT64_C( 1938365523136743384),  INT64_C( 5589394919817964747) },
      {  INT64_C( 6899642270282489604), -INT64_C( 1707015169647065288) },
      {  INT64_C( 3902542161119600751), -INT64_C( 3429603489347057911) },
      {  INT64_C( 3902542161119600751), -INT64_C( 3429603489347057911),  INT64_C( 6899642270282489604), -INT64_C( 1707015169647065288),
        -INT64_C( 1938365523136743384),  INT64_C( 5589394919817964747), -INT64_C(  288239442164023491), -INT64_C(  181278566807845815) } },
    { { -INT64_C( 8633868530542519112),  INT64_C( 1136360251874486813) },
      { -INT64_C( 1176711747414636279),  INT64_C(  314811394258678465) },
      {  INT64_C( 7503842828377912395),  INT64_C( 3520418695472348459) },
      {  INT64_C( 7577393952696053075), -INT64_C( 1418258260653821694) },
      {  INT64_C( 7577393952696053075), -INT64_C( 1418258260653821694),  INT64_C( 7503842828377912395),  INT64_C( 3520418695472348459),
        -INT64_C( 1176711747414636279),  INT64_C(  314811394258678465), -INT64_C( 8633868530542519112),  INT64_C( 1136360251874486813) } },
    { {  INT64_C( 5908066468385727562), -INT64_C( 6773421201959337048) },
      { -INT64_C(  777148065015749850), -INT64_C( 3620730806483145164) },
      { -INT64_C( 7264199598424307528),  INT64_C( 7895207375159315875) },
      { -INT64_C( 6632269055162356723), -INT64_C( 8867243746191263840) },
      { -INT64_C( 6632269055162356723), -INT64_C( 8867243746191263840), -INT64_C( 7264199598424307528),  INT64_C( 7895207375159315875),
        -INT64_C(  777148065015749850), -INT64_C( 3620730806483145164),  INT64_C( 5908066468385727562), -INT64_C( 6773421201959337048) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_mm_loadu_epi64(test_vec[i].a);
    simde__m128i b = simde_mm_loadu_epi64(test_vec[i].b);
    simde__m128i c = simde_mm_loadu_epi64(test_vec[i].c);
    simde__m128i d = simde_mm_loadu_epi64(test_vec[i].d);
    simde__m512i r = simde_x_mm512_set_m128i(a, b, c, d);
    simde_test_x86_assert_equal_i64x8(r, simde_mm512_loadu_si512(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i a = simde_test_x86_random_i64x2();
    simde__m128i b = simde_test_x86_random_i64x2();
    simde__m128i c = simde_test_x86_random_i64x2();
    simde__m128i d = simde_test_x86_random_i64x2();
    simde__m512i r = simde_x_mm512_set_m128i(a, b, c, d);

    simde_test_x86_write_i64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x2(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x2(2, d, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_x_mm512_set_m256 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde_float32 a[8];
    const simde_float32 b[8];
    const simde_float32 r[16];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(  -637.31), SIMDE_FLOAT32_C(   760.63), SIMDE_FLOAT32_C(  -460.69), SIMDE_FLOAT32_C(   -66.62),
        SIMDE_FLOAT32_C(  -340.31), SIMDE_FLOAT32_C(   918.64), SIMDE_FLOAT32_C(    34.24), SIMDE_FLOAT32_C(   333.18) },
      { SIMDE_FLOAT32_C(  -803.92), SIMDE_FLOAT32_C(  -213.48), SIMDE_FLOAT32_C(  -929.53), SIMDE_FLOAT32_C(   348.90),
        SIMDE_FLOAT32_C(   283.65), SIMDE_FLOAT32_C(  -184.83), SIMDE_FLOAT32_C(   487.65), SIMDE_FLOAT32_C(  -858.64) },
      { SIMDE_FLOAT32_C(  -803.92), SIMDE_FLOAT32_C(  -213.48), SIMDE_FLOAT32_C(  -929.53), SIMDE_FLOAT32_C(   348.90),
        SIMDE_FLOAT32_C(   283.65), SIMDE_FLOAT32_C(  -184.83), SIMDE_FLOAT32_C(   487.65), SIMDE_FLOAT32_C(  -858.64),
        SIMDE_FLOAT32_C(  -637.31), SIMDE_FLOAT32_C(   760.63), SIMDE_FLOAT32_C(  -460.69), SIMDE_FLOAT32_C(   -66.62),
        SIMDE_FLOAT32_C(  -340.31), SIMDE_FLOAT32_C(   918.64), SIMDE_FLOAT32_C(    34.24), SIMDE_FLOAT32_C(   333.18) } },
    { { SIMDE_FLOAT32_C(  -921.22), SIMDE_FLOAT32_C(  -836.03), SIMDE_FLOAT32_C(   170.20), SIMDE_FLOAT32_C(  -248.66),
        SIMDE_FLOAT32_C(  -471.75), SIMDE_FLOAT32_C(  -816.60), SIMDE_FLOAT32_C(  -262.88), SIMDE_FLOAT32_C(   275.76) },
      { SIMDE_FLOAT32_C(  -882.42), SIMDE_FLOAT32_C(   473.83), SIMDE_FLOAT32_C(  -459.78), SIMDE_FLOAT32_C(   549.62),
        SIMDE_FLOAT32_C(  -780.98), SIMDE_FLOAT32_C(  -139.94), SIMDE_FLOAT32_C(  -217.48), SIMDE_FLOAT32_C(  -418.29) },
      { SIMDE_FLOAT32_C(  -882.42), SIMDE_FLOAT32_C(   473.83), SIMDE_FLOAT32_C(  -459.78), SIMDE_FLOAT32_C(   549.62),
        SIMDE_FLOAT32_C(  -780.98), SIMDE_FLOAT32_C(  -139.94), SIMDE_FLOAT32_C(  -217.48), SIMDE_FLOAT32_C(  -418.29),
        SIMDE_FLOAT32_C(  -921.22), SIMDE_FLOAT32_C(  -836.03), SIMDE_FLOAT32_C(   170.20), SIMDE_FLOAT32_C(  -248.66),
        SIMDE_FLOAT32_C(  -471.75), SIMDE_FLOAT32_C(  -816.60), SIMDE_FLOAT32_C(  -262.88), SIMDE_FLOAT32_C(   275.76) } },
    { { SIMDE_FLOAT32_C(  -379.31), SIMDE_FLOAT32_C(   321.82), SIMDE_FLOAT32_C(   515.09), SIMDE_FLOAT32_C(   280.38),
        SIMDE_FLOAT32_C(   240.46), SIMDE_FLOAT32_C(  -450.67), SIMDE_FLOAT32_C(  -386.44), SIMDE_FLOAT32_C(   436.54) },
      { SIMDE_FLOAT32_C(   335.85), SIMDE_FLOAT32_C(  -315.97), SIMDE_FLOAT32_C(  -214.56), SIMDE_FLOAT32_C(  -380.50),
        SIMDE_FLOAT32_C(   499.20), SIMDE_FLOAT32_C(  -726.90), SIMDE_FLOAT32_C(  -239.14), SIMDE_FLOAT32_C(   577.98) },
      { SIMDE_FLOAT32_C(   335.85), SIMDE_FLOAT32_C(  -315.97), SIMDE_FLOAT32_C(  -214.56), SIMDE_FLOAT32_C(  -380.50),
        SIMDE_FLOAT32_C(   499.20), SIMDE_FLOAT32_C(  -726.90), SIMDE_FLOAT32_C(  -239.14), SIMDE_FLOAT32_C(   577.98),
        SIMDE_FLOAT32_C(  -379.31), SIMDE_FLOAT32_C(   321.82), SIMDE_FLOAT32_C(   515.09), SIMDE_FLOAT32_C(   280.38),
        SIMDE_FLOAT32_C(   240.46), SIMDE_FLOAT32_C(  -450.67), SIMDE_FLOAT32_C(  -386.44), SIMDE_FLOAT32_C(   436.54) } },
    { { SIMDE_FLOAT32_C(  -562.93), SIMDE_FLOAT32_C(   931.06), SIMDE_FLOAT32_C(  -670.68), SIMDE_FLOAT32_C(   -34.68),
        SIMDE_FLOAT32_C(  -885.55), SIMDE_FLOAT32_C(    66.44), SIMDE_FLOAT32_C(  -758.92), SIMDE_FLOAT32_C(  -767.96) },
      { SIMDE_FLOAT32_C(  -459.73), SIMDE_FLOAT32_C(  -218.69), SIMDE_FLOAT32_C(   781.65), SIMDE_FLOAT32_C(  -240.71),
        SIMDE_FLOAT32_C(   641.36), SIMDE_FLOAT32_C(  -435.83), SIMDE_FLOAT32_C(   341.00), SIMDE_FLOAT32_C(  -737.95) },
      { SIMDE_FLOAT32_C(  -459.73), SIMDE_FLOAT32_C(  -218.69), SIMDE_FLOAT32_C(   781.65), SIMDE_FLOAT32_C(  -240.71),
        SIMDE_FLOAT32_C(   641.36), SIMDE_FLOAT32_C(  -435.83), SIMDE_FLOAT32_C(   341.00), SIMDE_FLOAT32_C(  -737.95),
        SIMDE_FLOAT32_C(  -562.93), SIMDE_FLOAT32_C(   931.06), SIMDE_FLOAT32_C(  -670.68), SIMDE_FLOAT32_C(   -34.68),
        SIMDE_FLOAT32_C(  -885.55), SIMDE_FLOAT32_C(    66.44), SIMDE_FLOAT32_C(  -758.92), SIMDE_FLOAT32_C(  -767.96) } },
    { { SIMDE_FLOAT32_C(   886.00), SIMDE_FLOAT32_C(  -143.91), SIMDE_FLOAT32_C(   542.43), SIMDE_FLOAT32_C(   126.46),
        SIMDE_FLOAT32_C(   405.42), SIMDE_FLOAT32_C(  -844.01), SIMDE_FLOAT32_C(  -437.00), SIMDE_FLOAT32_C(  -258.74) },
      { SIMDE_FLOAT32_C(  -159.98), SIMDE_FLOAT32_C(   348.44), SIMDE_FLOAT32_C(   360.76), SIMDE_FLOAT32_C(  -660.78),
        SIMDE_FLOAT32_C(   621.54), SIMDE_FLOAT32_C(  -878.38), SIMDE_FLOAT32_C(   917.20), SIMDE_FLOAT32_C(  -941.40) },
      { SIMDE_FLOAT32_C(  -159.98), SIMDE_FLOAT32_C(   348.44), SIMDE_FLOAT32_C(   360.76), SIMDE_FLOAT32_C(  -660.78),
        SIMDE_FLOAT32_C(   621.54), SIMDE_FLOAT32_C(  -878.38), SIMDE_FLOAT32_C(   917.20), SIMDE_FLOAT32_C(  -941.40),
        SIMDE_FLOAT32_C(   886.00), SIMDE_FLOAT32_C(  -143.91), SIMDE_FLOAT32_C(   542.43), SIMDE_FLOAT32_C(   126.46),
        SIMDE_FLOAT32_C(   405.42), SIMDE_FLOAT32_C(  -844.01), SIMDE_FLOAT32_C(  -437.00), SIMDE_FLOAT32_C(  -258.74) } },
    { { SIMDE_FLOAT32_C(  -947.32), SIMDE_FLOAT32_C(  -753.48), SIMDE_FLOAT32_C(    23.92), SIMDE_FLOAT32_C(  -832.87),
        SIMDE_FLOAT32_C(   312.97), SIMDE_FLOAT32_C(   265.00), SIMDE_FLOAT32_C(  -600.84), SIMDE_FLOAT32_C(   853.24) },
      { SIMDE_FLOAT32_C(  -953.69), SIMDE_FLOAT32_C(  -819.18), SIMDE_FLOAT32_C(  -387.47), SIMDE_FLOAT32_C(   687.68),
        SIMDE_FLOAT32_C(  -255.01), SIMDE_FLOAT32_C(   953.53), SIMDE_FLOAT32_C(   949.73), SIMDE_FLOAT32_C(  -369.02) },
      { SIMDE_FLOAT32_C(  -953.69), SIMDE_FLOAT32_C(  -819.18), SIMDE_FLOAT32_C(  -387.47), SIMDE_FLOAT32_C(   687.68),
        SIMDE_FLOAT32_C(  -255.01), SIMDE_FLOAT32_C(   953.53), SIMDE_FLOAT32_C(   949.73), SIMDE_FLOAT32_C(  -369.02),
        SIMDE_FLOAT32_C(  -947.32), SIMDE_FLOAT32_C(  -753.48), SIMDE_FLOAT32_C(    23.92), SIMDE_FLOAT32_C(  -832.87),
        SIMDE_FLOAT32_C(   312.97), SIMDE_FLOAT32_C(   265.00), SIMDE_FLOAT32_C(  -600.84), SIMDE_FLOAT32_C(   853.24) } },
    { { SIMDE_FLOAT32_C(  -190.38), SIMDE_FLOAT32_C(   492.16), SIMDE_FLOAT32_C(   757.44), SIMDE_FLOAT32_C(  -784.97),
        SIMDE_FLOAT32_C(   648.15), SIMDE_FLOAT32_C(  -679.57), SIMDE_FLOAT32_C(   -43.70), SIMDE_FLOAT32_C(  -511.83) },
      { SIMDE_FLOAT32_C(   668.88), SIMDE_FLOAT32_C(  -682.94), SIMDE_FLOAT32_C(  -172.61), SIMDE_FLOAT32_C(   290.41),
        SIMDE_FLOAT32_C(  -561.32), SIMDE_FLOAT32_C(  -255.40), SIMDE_FLOAT32_C(   349.01), SIMDE_FLOAT32_C(  -508.64) },
      { SIMDE_FLOAT32_C(   668.88), SIMDE_FLOAT32_C(  -682.94), SIMDE_FLOAT32_C(  -172.61), SIMDE_FLOAT32_C(   290.41),
        SIMDE_FLOAT32_C(  -561.32), SIMDE_FLOAT32_C(  -255.40), SIMDE_FLOAT32_C(   349.01), SIMDE_FLOAT32_C(  -508.64),
        SIMDE_FLOAT32_C(  -190.38), SIMDE_FLOAT32_C(   492.16), SIMDE_FLOAT32_C(   757.44), SIMDE_FLOAT32_C(  -784.97),
        SIMDE_FLOAT32_C(   648.15), SIMDE_FLOAT32_C(  -679.57), SIMDE_FLOAT32_C(   -43.70), SIMDE_FLOAT32_C(  -511.83) } },
    { { SIMDE_FLOAT32_C(    -8.88), SIMDE_FLOAT32_C(  -627.06), SIMDE_FLOAT32_C(  -341.51), SIMDE_FLOAT32_C(  -695.91),
        SIMDE_FLOAT32_C(   637.94), SIMDE_FLOAT32_C(    57.65), SIMDE_FLOAT32_C(  -842.68), SIMDE_FLOAT32_C(   684.25) },
      { SIMDE_FLOAT32_C(   238.47), SIMDE_FLOAT32_C(  -230.15), SIMDE_FLOAT32_C(   371.93), SIMDE_FLOAT32_C(   983.45),
        SIMDE_FLOAT32_C(  -276.62), SIMDE_FLOAT32_C(   321.66), SIMDE_FLOAT32_C(  -385.57), SIMDE_FLOAT32_C(   533.00) },
      { SIMDE_FLOAT32_C(   238.47), SIMDE_FLOAT32_C(  -230.15), SIMDE_FLOAT32_C(   371.93), SIMDE_FLOAT32_C(   983.45),
        SIMDE_FLOAT32_C(  -276.62), SIMDE_FLOAT32_C(   321.66), SIMDE_FLOAT32_C(  -385.57), SIMDE_FLOAT32_C(   533.00),
        SIMDE_FLOAT32_C(    -8.88), SIMDE_FLOAT32_C(  -627.06), SIMDE_FLOAT32_C(  -341.51), SIMDE_FLOAT32_C(  -695.91),
        SIMDE_FLOAT32_C(   637.94), SIMDE_FLOAT32_C(    57.65), SIMDE_FLOAT32_C(  -842.68), SIMDE_FLOAT32_C(   684.25) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256 a = simde_mm256_loadu_ps(test_vec[i].a);
    simde__m256 b = simde_mm256_loadu_ps(test_vec[i].b);
    simde__m512 r = simde_x_mm512_set_m256(a, b);
    simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m256 a = simde_test_x86_random_f32x8(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
    simde__m256 b = simde_test_x86_random_f32x8(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
    simde__m512 r = simde_x_mm512_set_m256(a, b);

    simde_test_x86_write_f32x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f32x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_x_mm512_set_m256i (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int64_t a[4];
    const int64_t b[4];
    const int64_t r[8];
  } test_vec[] = {
    { {  INT64_C( 9185948727503546778),  INT64_C( 3678627756266746177),  INT64_C( 3412567430290792151), -INT64_C( 6689949871361817491) },
      {  INT64_C( 4729318369997616495), -INT64_C( 4574934939719185189),  INT64_C( 6601267626571075438), -INT64_C( 2225916818331210642) },
      {  INT64_C( 4729318369997616495), -INT64_C( 4574934939719185189),  INT64_C( 6601267626571075438), -INT64_C( 2225916818331210642),
         INT64_C( 9185948727503546778),  INT64_C( 3678627756266746177),  INT64_C( 3412567430290792151), -INT64_C( 6689949871361817491) } },
    { {  INT64_C( 5776890669553584873), -INT64_C( 6045763373581226384), -INT64_C(   37516912470906831),  INT64_C( 2663195537103603362) },
      {  INT64_C(  855747269500008476), -INT64_C( 3183624226697084697),  INT64_C( 4915516962277354406),  INT64_C( 6634451241853890227) },
      {  INT64_C(  855747269500008476), -INT64_C( 3183624226697084697),  INT64_C( 4915516962277354406),  INT64_C( 6634451241853890227),
         INT64_C( 5776890669553584873), -INT64_C( 6045763373581226384), -INT64_C(   37516912470906831),  INT64_C( 2663195537103603362) } },
    { {  INT64_C( 4678621373850722374),  INT64_C( 8557463612466483789), -INT64_C( 3239807627526556638), -INT64_C(  635336641497439598) },
      {  INT64_C( 3859240631760657396),  INT64_C( 5575146464983970840), -INT64_C( 8967199087320232806),  INT64_C( 1739660642691141501) },
      {  INT64_C( 3859240631760657396),  INT64_C( 5575146464983970840), -INT64_C( 8967199087320232806),  INT64_C( 1739660642691141501),
         INT64_C( 4678621373850722374),  INT64_C( 8557463612466483789), -INT64_C( 3239807627526556638), -INT64_C(  635336641497439598) } },
    { { -INT64_C( 2540886964821361249),  INT64_C( 6944871434024247528),  INT64_C(  838699283998470959),  INT64_C( 1960013050450344184) },
      {  INT64_C( 8573550280122210650),  INT64_C( 1397501144658001982),  INT64_C( 2303545201378164574), -INT64_C( 1772607854487064626) },
      {  INT64_C( 8573550280122210650),  INT64_C( 1397501144658001982),  INT64_C( 2303545201378164574), -INT64_C( 1772607854487064626),
        -INT64_C( 2540886964821361249),  INT64_C( 6944871434024247528),  INT64_C(  838699283998470959),  INT64_C( 1960013050450344184) } },
    { { -INT64_C( 6481805318794442488), -INT64_C( 2326373633025730880), -INT64_C( 8154397417344865650), -INT64_C( 8762526587941220110) },
      {  INT64_C( 3194786528158837577), -INT64_C( 7052488512568819265), -INT64_C( 6863722578472342415),  INT64_C( 2467274241483970872) },
      {  INT64_C( 3194786528158837577), -INT64_C( 7052488512568819265), -INT64_C( 6863722578472342415),  INT64_C( 2467274241483970872),
        -INT64_C( 6481805318794442488), -INT64_C( 2326373633025730880), -INT64_C( 8154397417344865650), -INT64_C( 8762526587941220110) } },
    { {  INT64_C( 4793845972517149423),  INT64_C( 5753529798337189674), -INT64_C( 8295842357534774384),  INT64_C( 8274099338729488088) },
      { -INT64_C(  459273912366291237),  INT64_C( 6401879826230355115),  INT64_C( 8077053750437894198), -INT64_C( 5302718236152735117) },
      { -INT64_C(  459273912366291237),  INT64_C( 6401879826230355115),  INT64_C( 8077053750437894198), -INT64_C( 5302718236152735117),
         INT64_C( 4793845972517149423),  INT64_C( 5753529798337189674), -INT64_C( 8295842357534774384),  INT64_C( 8274099338729488088) } },
    { {  INT64_C( 3775060514461463963), -INT64_C( 2884109564918262055),  INT64_C( 8715724243471601645), -INT64_C( 6456519145089526061) },
      {  INT64_C(  632882395830319627),  INT64_C(  540891665677255945),  INT64_C( 3508163768285455153), -INT64_C(   51997053213008490) },
      {  INT64_C(  632882395830319627),  INT64_C(  540891665677255945),  INT64_C( 3508163768285455153), -INT64_C(   51997053213008490),
         INT64_C( 3775060514461463963), -INT64_C( 2884109564918262055),  INT64_C( 8715724243471601645), -INT64_C( 6456519145089526061) } },
    { { -INT64_C( 3173528335773575234),  INT64_C( 8215972274809708258), -INT64_C( 6381786419661598494),  INT64_C( 5866097473156042357) },
      {  INT64_C( 4288891779987471591), -INT64_C( 1980111581061119022), -INT64_C(  395311238656873013),  INT64_C( 4883251489614842848) },
      {  INT64_C( 4288891779987471591), -INT64_C( 1980111581061119022), -INT64_C(  395311238656873013),  INT64_C( 4883251489614842848),
        -INT64_C( 3173528335773575234),  INT64_C( 8215972274809708258), -INT64_C( 6381786419661598494),  INT64_C( 5866097473156042357) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256i a = simde_mm256_loadu_epi64(test_vec[i].a);
    simde__m256i b = simde_mm256_loadu_epi64(test_vec[i].b);
    simde__m512i r = simde_x_mm512_set_m256i(a, b);
    simde_test_x86_assert_equal_i64x8(r, simde_mm512_loadu_si512(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m256i a = simde_test_x86_random_i64x4();
    simde__m256i b = simde_test_x86_random_i64x4();
    simde__m512i r = simde_x_mm512_set_m256i(a, b);

    simde_test_x86_write_i64x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i64x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_x_mm512_set_m256d (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde_float64 a[4];
    const simde_float64 b[4];
    const simde_float64 r[8];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(  -516.49), SIMDE_FLOAT64_C(  -372.13), SIMDE_FLOAT64_C(  -232.67), SIMDE_FLOAT64_C(   646.34) },
      { SIMDE_FLOAT64_C(   990.61), SIMDE_FLOAT64_C(  -207.39), SIMDE_FLOAT64_C(   792.40), SIMDE_FLOAT64_C(  -563.99) },
      { SIMDE_FLOAT64_C(   990.61), SIMDE_FLOAT64_C(  -207.39), SIMDE_FLOAT64_C(   792.40), SIMDE_FLOAT64_C(  -563.99),
        SIMDE_FLOAT64_C(  -516.49), SIMDE_FLOAT64_C(  -372.13), SIMDE_FLOAT64_C(  -232.67), SIMDE_FLOAT64_C(   646.34) } },
    { { SIMDE_FLOAT64_C(   225.52), SIMDE_FLOAT64_C(   712.33), SIMDE_FLOAT64_C(   556.42), SIMDE_FLOAT64_C(   960.52) },
      { SIMDE_FLOAT64_C(   332.11), SIMDE_FLOAT64_C(    54.37), SIMDE_FLOAT64_C(  -217.87), SIMDE_FLOAT64_C(  -680.84) },
      { SIMDE_FLOAT64_C(   332.11), SIMDE_FLOAT64_C(    54.37), SIMDE_FLOAT64_C(  -217.87), SIMDE_FLOAT64_C(  -680.84),
        SIMDE_FLOAT64_C(   225.52), SIMDE_FLOAT64_C(   712.33), SIMDE_FLOAT64_C(   556.42), SIMDE_FLOAT64_C(   960.52) } },
    { { SIMDE_FLOAT64_C(   996.26), SIMDE_FLOAT64_C(  -253.95), SIMDE_FLOAT64_C(   521.15), SIMDE_FLOAT64_C(   662.65) },
      { SIMDE_FLOAT64_C(  -436.82), SIMDE_FLOAT64_C(  -449.85), SIMDE_FLOAT64_C(   416.62), SIMDE_FLOAT64_C(   -75.47) },
      { SIMDE_FLOAT64_C(  -436.82), SIMDE_FLOAT64_C(  -449.85), SIMDE_FLOAT64_C(   416.62), SIMDE_FLOAT64_C(   -75.47),
        SIMDE_FLOAT64_C(   996.26), SIMDE_FLOAT64_C(  -253.95), SIMDE_FLOAT64_C(   521.15), SIMDE_FLOAT64_C(   662.65) } },
    { { SIMDE_FLOAT64_C(    47.94), SIMDE_FLOAT64_C(   -71.31), SIMDE_FLOAT64_C(   520.40), SIMDE_FLOAT64_C(   630.12) },
      { SIMDE_FLOAT64_C(  -407.55), SIMDE_FLOAT64_C(  -233.01), SIMDE_FLOAT64_C(   482.29), SIMDE_FLOAT64_C(    75.96) },
      { SIMDE_FLOAT64_C(  -407.55), SIMDE_FLOAT64_C(  -233.01), SIMDE_FLOAT64_C(   482.29), SIMDE_FLOAT64_C(    75.96),
        SIMDE_FLOAT64_C(    47.94), SIMDE_FLOAT64_C(   -71.31), SIMDE_FLOAT64_C(   520.40), SIMDE_FLOAT64_C(   630.12) } },
    { { SIMDE_FLOAT64_C(   394.86), SIMDE_FLOAT64_C(  -750.38), SIMDE_FLOAT64_C(  -277.69), SIMDE_FLOAT64_C(   385.47) },
      { SIMDE_FLOAT64_C(    42.23), SIMDE_FLOAT64_C(  -485.30), SIMDE_FLOAT64_C(   821.48), SIMDE_FLOAT64_C(  -732.26) },
      { SIMDE_FLOAT64_C(    42.23), SIMDE_FLOAT64_C(  -485.30), SIMDE_FLOAT64_C(   821.48), SIMDE_FLOAT64_C(  -732.26),
        SIMDE_FLOAT64_C(   394.86), SIMDE_FLOAT64_C(  -750.38), SIMDE_FLOAT64_C(  -277.69), SIMDE_FLOAT64_C(   385.47) } },
    { { SIMDE_FLOAT64_C(  -772.97), SIMDE_FLOAT64_C(   377.90), SIMDE_FLOAT64_C(  -771.74), SIMDE_FLOAT64_C(   559.14) },
      { SIMDE_FLOAT64_C(  -567.73), SIMDE_FLOAT64_C(    10.40), SIMDE_FLOAT64_C(   878.30), SIMDE_FLOAT64_C(  -571.47) },
      { SIMDE_FLOAT64_C(  -567.73), SIMDE_FLOAT64_C(    10.40), SIMDE_FLOAT64_C(   878.30), SIMDE_FLOAT64_C(  -571.47),
        SIMDE_FLOAT64_C(  -772.97), SIMDE_FLOAT64_C(   377.90), SIMDE_FLOAT64_C(  -771.74), SIMDE_FLOAT64_C(   559.14) } },
    { { SIMDE_FLOAT64_C(   756.44), SIMDE_FLOAT64_C(   399.44), SIMDE_FLOAT64_C(  -908.83), SIMDE_FLOAT64_C(  -680.38) },
      { SIMDE_FLOAT64_C(   949.59), SIMDE_FLOAT64_C(   507.80), SIMDE_FLOAT64_C(   244.15), SIMDE_FLOAT64_C(    -2.47) },
      { SIMDE_FLOAT64_C(   949.59), SIMDE_FLOAT64_C(   507.80), SIMDE_FLOAT64_C(   244.15), SIMDE_FLOAT64_C(    -2.47),
        SIMDE_FLOAT64_C(   756.44), SIMDE_FLOAT64_C(   399.44), SIMDE_FLOAT64_C(  -908.83), SIMDE_FLOAT64_C(  -680.38) } },
    { { SIMDE_FLOAT64_C(  -563.51), SIMDE_FLOAT64_C(  -235.45), SIMDE_FLOAT64_C(  -372.34), SIMDE_FLOAT64_C(    28.93) },
      { SIMDE_FLOAT64_C(   531.55), SIMDE_FLOAT64_C(  -890.05), SIMDE_FLOAT64_C(  -895.11), SIMDE_FLOAT64_C(   -73.60) },
      { SIMDE_FLOAT64_C(   531.55), SIMDE_FLOAT64_C(  -890.05), SIMDE_FLOAT64_C(  -895.11), SIMDE_FLOAT64_C(   -73.60),
        SIMDE_FLOAT64_C(  -563.51), SIMDE_FLOAT64_C(  -235.45), SIMDE_FLOAT64_C(  -372.34), SIMDE_FLOAT64_C(    28.93) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256d a = simde_mm256_loadu_pd(test_vec[i].a);
    simde__m256d b = simde_mm256_loadu_pd(test_vec[i].b);
    simde__m512d r = simde_x_mm512_set_m256d(a, b);
    simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m256d a = simde_test_x86_random_f64x4(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde__m256d b = simde_test_x86_random_f64x4(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde__m512d r = simde_x_mm512_set_m256d(a, b);

    simde_test_x86_write_f64x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f64x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x8(2, r, SIMDE_TEST_VEC_POS_LAST);
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
  #if defined(SIMDE_FLOAT16_IS_SCALAR)
    SIMDE_TEST_FUNC_LIST_ENTRY(mm512_set_ph)
  #endif
  SIMDE_TEST_FUNC_LIST_ENTRY(x_mm512_set_epu8)
  SIMDE_TEST_FUNC_LIST_ENTRY(x_mm512_set_epu16)
  SIMDE_TEST_FUNC_LIST_ENTRY(x_mm512_set_epu32)
  SIMDE_TEST_FUNC_LIST_ENTRY(x_mm512_set_epu64)
  SIMDE_TEST_FUNC_LIST_ENTRY(x_mm512_set_m128i)
  SIMDE_TEST_FUNC_LIST_ENTRY(x_mm512_set_m256)
  SIMDE_TEST_FUNC_LIST_ENTRY(x_mm512_set_m256i)
  SIMDE_TEST_FUNC_LIST_ENTRY(x_mm512_set_m256d)
SIMDE_TEST_FUNC_LIST_END

#include <test/x86/avx512/test-avx512-footer.h>
