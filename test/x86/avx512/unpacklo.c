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

#define SIMDE_TEST_X86_AVX512_INSN unpacklo

#include <test/x86/avx512/test-avx512.h>
#include <simde/x86/avx512/unpacklo.h>

static int
test_simde_mm512_unpacklo_epi8 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const int8_t a[64];
    const int8_t b[64];
    const int8_t r[64];
  } test_vec[] = {
    { {  INT8_C(  80),  INT8_C(  87),  INT8_C(  13), -INT8_C( 102),  INT8_C(  22), -INT8_C( 121), -INT8_C(  61), -INT8_C(  74),
         INT8_C(  31),  INT8_C(  47), -INT8_C(  90), -INT8_C(  58), -INT8_C(  19), -INT8_C(  27),  INT8_C(  88), -INT8_C( 107),
         INT8_C(  92),  INT8_C(  47),  INT8_C( 105), -INT8_C( 121),  INT8_C(  54),  INT8_C(  74), -INT8_C(  28), -INT8_C( 100),
         INT8_C(   2), -INT8_C(  70),  INT8_C(  98),  INT8_C(  92),  INT8_C(  28),  INT8_C(  53),  INT8_C(  83),  INT8_C( 108),
        -INT8_C( 115),  INT8_C(  96),  INT8_C(   6), -INT8_C(  93), -INT8_C(  24), -INT8_C(  55),  INT8_C(  89),  INT8_C(   7),
        -INT8_C(   8),  INT8_C(   0), -INT8_C(  51), -INT8_C(  27), -INT8_C(  27),  INT8_C(  37),  INT8_C( 122),  INT8_C(  65),
         INT8_C(  85), -INT8_C(  29), -INT8_C(  56), -INT8_C( 117),  INT8_C(  45), -INT8_C(  84),  INT8_C(  39),  INT8_C(  47),
         INT8_C( 103), -INT8_C( 119), -INT8_C( 116), -INT8_C( 125), -INT8_C(  66), -INT8_C(  33), -INT8_C(  17),  INT8_C(  75) },
      {  INT8_C(  63), -INT8_C(  11), -INT8_C(  17),  INT8_C(  39), -INT8_C(  66),  INT8_C(  72),  INT8_C(  47), -INT8_C(  74),
         INT8_C(  72), -INT8_C(   4), -INT8_C( 100),  INT8_C(  45),  INT8_C(  34),  INT8_C(  22),  INT8_C( 110),  INT8_C( 119),
        -INT8_C(   6),  INT8_C(  54),  INT8_C(   2),  INT8_C(  39), -INT8_C(  29),  INT8_C(  41),  INT8_C(  87),  INT8_C(  74),
        -INT8_C(  78), -INT8_C(  29), -INT8_C(  51),  INT8_C( 112), -INT8_C(  62), -INT8_C(  68), -INT8_C(  68),  INT8_C(   1),
        -INT8_C(  79), -INT8_C(  85),  INT8_C(  41),  INT8_C( 111), -INT8_C(  13),  INT8_C(  88),  INT8_C(  37),  INT8_C(  60),
         INT8_C(  84), -INT8_C(  63),  INT8_C( 105),  INT8_C( 118), -INT8_C(  40), -INT8_C(  40), -INT8_C(  19), -INT8_C(  46),
         INT8_C(  14), -INT8_C(  17), -INT8_C(   7), -INT8_C(  15),  INT8_C(  24),  INT8_C(  80),  INT8_C(  59), -INT8_C(  54),
         INT8_C(  51),  INT8_C(   8),  INT8_C(  59), -INT8_C(  11), -INT8_C(  60), -INT8_C(   9), -INT8_C(   9),  INT8_C( 117) },
      {  INT8_C(  80),  INT8_C(  63),  INT8_C(  87), -INT8_C(  11),  INT8_C(  13), -INT8_C(  17), -INT8_C( 102),  INT8_C(  39),
         INT8_C(  22), -INT8_C(  66), -INT8_C( 121),  INT8_C(  72), -INT8_C(  61),  INT8_C(  47), -INT8_C(  74), -INT8_C(  74),
         INT8_C(  92), -INT8_C(   6),  INT8_C(  47),  INT8_C(  54),  INT8_C( 105),  INT8_C(   2), -INT8_C( 121),  INT8_C(  39),
         INT8_C(  54), -INT8_C(  29),  INT8_C(  74),  INT8_C(  41), -INT8_C(  28),  INT8_C(  87), -INT8_C( 100),  INT8_C(  74),
        -INT8_C( 115), -INT8_C(  79),  INT8_C(  96), -INT8_C(  85),  INT8_C(   6),  INT8_C(  41), -INT8_C(  93),  INT8_C( 111),
        -INT8_C(  24), -INT8_C(  13), -INT8_C(  55),  INT8_C(  88),  INT8_C(  89),  INT8_C(  37),  INT8_C(   7),  INT8_C(  60),
         INT8_C(  85),  INT8_C(  14), -INT8_C(  29), -INT8_C(  17), -INT8_C(  56), -INT8_C(   7), -INT8_C( 117), -INT8_C(  15),
         INT8_C(  45),  INT8_C(  24), -INT8_C(  84),  INT8_C(  80),  INT8_C(  39),  INT8_C(  59),  INT8_C(  47), -INT8_C(  54) } },
    { { -INT8_C(  94),  INT8_C(  32), -INT8_C(  28), -INT8_C( 107),  INT8_C( 120),  INT8_C(  10), -INT8_C(  47), -INT8_C(  52),
        -INT8_C(  53),  INT8_C(  59),  INT8_C(  67), -INT8_C(  93),  INT8_C(  19),  INT8_C(  48),  INT8_C( 117),  INT8_C(  33),
         INT8_C(  32),  INT8_C( 111),  INT8_C(  19),  INT8_C(  56), -INT8_C(  65),  INT8_C(  78),  INT8_C(   3), -INT8_C(  13),
         INT8_C(  87),  INT8_C(  62), -INT8_C(  24),  INT8_C(  27),  INT8_C(  53), -INT8_C(  33), -INT8_C( 111), -INT8_C(  41),
        -INT8_C(   1),  INT8_C( 117),  INT8_C( 108),  INT8_C( 119),      INT8_MAX,  INT8_C(  62),  INT8_C(  68),  INT8_C(  75),
         INT8_C( 121), -INT8_C( 121), -INT8_C(  18), -INT8_C( 116), -INT8_C(  73),  INT8_C( 100), -INT8_C(  83), -INT8_C(  41),
        -INT8_C(  45), -INT8_C(  64),  INT8_C(  16), -INT8_C( 110),  INT8_C(  15),  INT8_C(  19), -INT8_C( 123),  INT8_C( 102),
         INT8_C(  81),  INT8_C( 110), -INT8_C( 127), -INT8_C( 122),  INT8_C(  77),  INT8_C(  18),  INT8_C(  93),  INT8_C(  77) },
      { -INT8_C( 120), -INT8_C(  55), -INT8_C(  60),  INT8_C(   7),  INT8_C(   7),  INT8_C(   8),  INT8_C(  82),      INT8_MIN,
        -INT8_C( 113),  INT8_C(  65),  INT8_C(  12),  INT8_C(  71), -INT8_C(  91), -INT8_C(  70),  INT8_C(  30),  INT8_C( 120),
         INT8_C( 122),  INT8_C(  46),  INT8_C(  10), -INT8_C( 119),  INT8_C(  65), -INT8_C( 112), -INT8_C(  17), -INT8_C( 110),
        -INT8_C(   2),  INT8_C( 113),  INT8_C(  24),  INT8_C(  75), -INT8_C( 125),  INT8_C( 117), -INT8_C( 104),  INT8_C(  11),
         INT8_C(  63),  INT8_C(  93),  INT8_C(  19),  INT8_C(  70),  INT8_C( 101),  INT8_C( 101), -INT8_C(  57), -INT8_C(  11),
        -INT8_C(  90), -INT8_C(  45),  INT8_C(  60),  INT8_C(  75), -INT8_C( 115),  INT8_C(  90), -INT8_C(  61),  INT8_C(   8),
        -INT8_C( 119), -INT8_C(  50), -INT8_C( 111), -INT8_C(  54),  INT8_C(  94), -INT8_C( 127),  INT8_C(  93),  INT8_C(  92),
        -INT8_C(  14),  INT8_C( 117), -INT8_C(  89),  INT8_C( 117), -INT8_C(  21),  INT8_C(  64), -INT8_C( 127),  INT8_C(  42) },
      { -INT8_C(  94), -INT8_C( 120),  INT8_C(  32), -INT8_C(  55), -INT8_C(  28), -INT8_C(  60), -INT8_C( 107),  INT8_C(   7),
         INT8_C( 120),  INT8_C(   7),  INT8_C(  10),  INT8_C(   8), -INT8_C(  47),  INT8_C(  82), -INT8_C(  52),      INT8_MIN,
         INT8_C(  32),  INT8_C( 122),  INT8_C( 111),  INT8_C(  46),  INT8_C(  19),  INT8_C(  10),  INT8_C(  56), -INT8_C( 119),
        -INT8_C(  65),  INT8_C(  65),  INT8_C(  78), -INT8_C( 112),  INT8_C(   3), -INT8_C(  17), -INT8_C(  13), -INT8_C( 110),
        -INT8_C(   1),  INT8_C(  63),  INT8_C( 117),  INT8_C(  93),  INT8_C( 108),  INT8_C(  19),  INT8_C( 119),  INT8_C(  70),
             INT8_MAX,  INT8_C( 101),  INT8_C(  62),  INT8_C( 101),  INT8_C(  68), -INT8_C(  57),  INT8_C(  75), -INT8_C(  11),
        -INT8_C(  45), -INT8_C( 119), -INT8_C(  64), -INT8_C(  50),  INT8_C(  16), -INT8_C( 111), -INT8_C( 110), -INT8_C(  54),
         INT8_C(  15),  INT8_C(  94),  INT8_C(  19), -INT8_C( 127), -INT8_C( 123),  INT8_C(  93),  INT8_C( 102),  INT8_C(  92) } },
    { { -INT8_C(  99), -INT8_C( 108),  INT8_C( 112),  INT8_C(   2), -INT8_C(   7),  INT8_C(  55), -INT8_C(   9), -INT8_C(  96),
         INT8_C(  11),  INT8_C(  51), -INT8_C(  21), -INT8_C( 104), -INT8_C( 114), -INT8_C(  81), -INT8_C(  96),  INT8_C(  23),
         INT8_C( 125),  INT8_C(  50), -INT8_C(  31), -INT8_C(  37), -INT8_C(  77),  INT8_C(  62),  INT8_C(  55), -INT8_C(  91),
        -INT8_C(  76), -INT8_C(  34),  INT8_C(  26), -INT8_C(  97),  INT8_C(  30), -INT8_C( 101), -INT8_C(  55), -INT8_C(  69),
         INT8_C(  47),  INT8_C(  57), -INT8_C(  66),  INT8_C(  41),  INT8_C( 113), -INT8_C(  75), -INT8_C(  55),  INT8_C( 124),
        -INT8_C(  23), -INT8_C(  76),  INT8_C(  20),  INT8_C( 119),  INT8_C(  99), -INT8_C(  75), -INT8_C( 114), -INT8_C(  32),
        -INT8_C(  25),  INT8_C( 111), -INT8_C(  69), -INT8_C( 102), -INT8_C(  82), -INT8_C(  14),  INT8_C(  63),  INT8_C(  98),
        -INT8_C(  47),  INT8_C(  89),  INT8_C(   1), -INT8_C(  17), -INT8_C(  11), -INT8_C(  54), -INT8_C(  85),  INT8_C(  36) },
      {  INT8_C(   3),  INT8_C( 105),  INT8_C(  77),  INT8_C( 116),  INT8_C(  30),  INT8_C(  22), -INT8_C(  16),  INT8_C(   7),
        -INT8_C(  53),  INT8_C(   5),  INT8_C( 126),  INT8_C(  46), -INT8_C(  70),  INT8_C(  12),  INT8_C(  15), -INT8_C(  95),
         INT8_C( 124), -INT8_C(  54),  INT8_C(  59),  INT8_C(  42), -INT8_C(  67),  INT8_C( 122), -INT8_C( 116), -INT8_C( 114),
        -INT8_C(  45), -INT8_C( 115),  INT8_C( 125), -INT8_C(  56),  INT8_C(  87),  INT8_C(  40), -INT8_C(  19),  INT8_C(  90),
        -INT8_C( 111),  INT8_C(  58), -INT8_C(  49), -INT8_C(  80),  INT8_C(  81), -INT8_C(  65), -INT8_C(  73),  INT8_C(  28),
        -INT8_C(  60),  INT8_C(  54),  INT8_C(  74),  INT8_C( 126),  INT8_C(  66),  INT8_C(  89),  INT8_C(  31), -INT8_C(  66),
         INT8_C(  36),  INT8_C(  90), -INT8_C(  24), -INT8_C(  31), -INT8_C(  44),  INT8_C( 116),  INT8_C( 111), -INT8_C(  88),
         INT8_C(   1), -INT8_C(  20),  INT8_C( 112),  INT8_C(  88),  INT8_C(  21),  INT8_C(  93), -INT8_C(  77), -INT8_C(  90) },
      { -INT8_C(  99),  INT8_C(   3), -INT8_C( 108),  INT8_C( 105),  INT8_C( 112),  INT8_C(  77),  INT8_C(   2),  INT8_C( 116),
        -INT8_C(   7),  INT8_C(  30),  INT8_C(  55),  INT8_C(  22), -INT8_C(   9), -INT8_C(  16), -INT8_C(  96),  INT8_C(   7),
         INT8_C( 125),  INT8_C( 124),  INT8_C(  50), -INT8_C(  54), -INT8_C(  31),  INT8_C(  59), -INT8_C(  37),  INT8_C(  42),
        -INT8_C(  77), -INT8_C(  67),  INT8_C(  62),  INT8_C( 122),  INT8_C(  55), -INT8_C( 116), -INT8_C(  91), -INT8_C( 114),
         INT8_C(  47), -INT8_C( 111),  INT8_C(  57),  INT8_C(  58), -INT8_C(  66), -INT8_C(  49),  INT8_C(  41), -INT8_C(  80),
         INT8_C( 113),  INT8_C(  81), -INT8_C(  75), -INT8_C(  65), -INT8_C(  55), -INT8_C(  73),  INT8_C( 124),  INT8_C(  28),
        -INT8_C(  25),  INT8_C(  36),  INT8_C( 111),  INT8_C(  90), -INT8_C(  69), -INT8_C(  24), -INT8_C( 102), -INT8_C(  31),
        -INT8_C(  82), -INT8_C(  44), -INT8_C(  14),  INT8_C( 116),  INT8_C(  63),  INT8_C( 111),  INT8_C(  98), -INT8_C(  88) } },
    { { -INT8_C( 104), -INT8_C( 126),  INT8_C(  86), -INT8_C(  23),  INT8_C(  65),  INT8_C(  14),  INT8_C(   5),  INT8_C(   6),
         INT8_C(  68),  INT8_C(  79), -INT8_C( 124), -INT8_C( 122), -INT8_C(  87), -INT8_C(  92),  INT8_C(  69), -INT8_C(  51),
        -INT8_C(   2),  INT8_C(  45), -INT8_C(  82), -INT8_C(  45), -INT8_C(  94),  INT8_C(  29),  INT8_C( 123), -INT8_C(  93),
         INT8_C(   9), -INT8_C(  21), -INT8_C(   4),  INT8_C(  30),  INT8_C(  73), -INT8_C(  81), -INT8_C(  59), -INT8_C(  31),
         INT8_C(  49),  INT8_C(  27), -INT8_C(  54),  INT8_C( 114),  INT8_C(  41), -INT8_C(  49),  INT8_C( 120),  INT8_C( 109),
         INT8_C(  30), -INT8_C(   3), -INT8_C(  12), -INT8_C(  57), -INT8_C(  95),  INT8_C(  57), -INT8_C( 108), -INT8_C(  97),
         INT8_C( 102),  INT8_C(  66),  INT8_C( 114),  INT8_C(   8),  INT8_C(  95), -INT8_C(  19), -INT8_C(  84),  INT8_C( 105),
        -INT8_C(  39), -INT8_C(  88), -INT8_C( 121),  INT8_C(  34),  INT8_C(  87),  INT8_C(  76),  INT8_C(   3), -INT8_C( 120) },
      {  INT8_C( 104), -INT8_C(  51), -INT8_C(   6), -INT8_C( 111), -INT8_C( 100),  INT8_C( 115), -INT8_C(   1), -INT8_C(  70),
         INT8_C( 112), -INT8_C(  13), -INT8_C( 126),  INT8_C(  17),  INT8_C(  44),  INT8_C(  22), -INT8_C(  80), -INT8_C( 110),
         INT8_C(  89),  INT8_C(  35), -INT8_C( 101), -INT8_C(  72),  INT8_C(  16),  INT8_C(  71),  INT8_C(  33), -INT8_C(  23),
        -INT8_C(  17), -INT8_C(  87),  INT8_C(  11),  INT8_C(  70), -INT8_C(  11),  INT8_C(  14), -INT8_C(  50),  INT8_C(  93),
        -INT8_C(  37), -INT8_C(  56), -INT8_C(  17),  INT8_C( 119),  INT8_C(  59), -INT8_C(  18),  INT8_C(  50), -INT8_C(  85),
        -INT8_C(  31), -INT8_C(  76), -INT8_C(  68),  INT8_C(  13), -INT8_C(  54),  INT8_C( 109), -INT8_C(  97),  INT8_C(  35),
        -INT8_C( 112),  INT8_C(  58), -INT8_C(  36), -INT8_C(  96), -INT8_C( 127), -INT8_C(   3), -INT8_C( 118),  INT8_C( 112),
        -INT8_C(  90), -INT8_C( 107), -INT8_C(  74), -INT8_C( 100), -INT8_C(  92), -INT8_C( 124), -INT8_C(   7),      INT8_MAX },
      { -INT8_C( 104),  INT8_C( 104), -INT8_C( 126), -INT8_C(  51),  INT8_C(  86), -INT8_C(   6), -INT8_C(  23), -INT8_C( 111),
         INT8_C(  65), -INT8_C( 100),  INT8_C(  14),  INT8_C( 115),  INT8_C(   5), -INT8_C(   1),  INT8_C(   6), -INT8_C(  70),
        -INT8_C(   2),  INT8_C(  89),  INT8_C(  45),  INT8_C(  35), -INT8_C(  82), -INT8_C( 101), -INT8_C(  45), -INT8_C(  72),
        -INT8_C(  94),  INT8_C(  16),  INT8_C(  29),  INT8_C(  71),  INT8_C( 123),  INT8_C(  33), -INT8_C(  93), -INT8_C(  23),
         INT8_C(  49), -INT8_C(  37),  INT8_C(  27), -INT8_C(  56), -INT8_C(  54), -INT8_C(  17),  INT8_C( 114),  INT8_C( 119),
         INT8_C(  41),  INT8_C(  59), -INT8_C(  49), -INT8_C(  18),  INT8_C( 120),  INT8_C(  50),  INT8_C( 109), -INT8_C(  85),
         INT8_C( 102), -INT8_C( 112),  INT8_C(  66),  INT8_C(  58),  INT8_C( 114), -INT8_C(  36),  INT8_C(   8), -INT8_C(  96),
         INT8_C(  95), -INT8_C( 127), -INT8_C(  19), -INT8_C(   3), -INT8_C(  84), -INT8_C( 118),  INT8_C( 105),  INT8_C( 112) } },
    { {  INT8_C(  77), -INT8_C(  24), -INT8_C(   9), -INT8_C( 120), -INT8_C(  42),  INT8_C(  41),  INT8_C(  52), -INT8_C(  73),
        -INT8_C(  35), -INT8_C(  16), -INT8_C(  60), -INT8_C(  89),  INT8_C(  93),  INT8_C( 100), -INT8_C(  53), -INT8_C(  19),
        -INT8_C(  98), -INT8_C(  89), -INT8_C( 114),  INT8_C(  32), -INT8_C(  92),  INT8_C(  24), -INT8_C( 112),  INT8_C(  75),
        -INT8_C(  83),  INT8_C(  71), -INT8_C(  25),  INT8_C(  81), -INT8_C(  53), -INT8_C(  32), -INT8_C(  47),  INT8_C(  24),
        -INT8_C(  55), -INT8_C(  56), -INT8_C(  95), -INT8_C(  97), -INT8_C(  15), -INT8_C(  43),  INT8_C(  87), -INT8_C(  50),
        -INT8_C(  59),  INT8_C(  27),  INT8_C( 117),  INT8_C(  35),      INT8_MAX,  INT8_C(  64),  INT8_C(  16),  INT8_C(  30),
        -INT8_C(  25), -INT8_C(  98),  INT8_C(  62), -INT8_C( 116), -INT8_C(  74), -INT8_C(  50), -INT8_C(  41),  INT8_C( 100),
         INT8_C(  21), -INT8_C(  66), -INT8_C(  75), -INT8_C(  31), -INT8_C(  98), -INT8_C( 122), -INT8_C(   7),  INT8_C( 103) },
      {  INT8_C(  78), -INT8_C( 102),  INT8_C(   7),  INT8_C(  63),  INT8_C( 111),  INT8_C(  94),  INT8_C(  13),  INT8_C(  53),
         INT8_C( 121), -INT8_C( 125),  INT8_C(  88), -INT8_C(   7), -INT8_C(  61),  INT8_C( 104),  INT8_C(  23), -INT8_C(  85),
         INT8_C(   7),  INT8_C(  85),  INT8_C(  55), -INT8_C(  67),  INT8_C(  35),  INT8_C(  14),  INT8_C(  33),  INT8_C(  57),
        -INT8_C(  52), -INT8_C(  41),  INT8_C(  26),  INT8_C( 106),  INT8_C(  93),  INT8_C(  19), -INT8_C(  46), -INT8_C(  84),
        -INT8_C(  82), -INT8_C(  39), -INT8_C(  21),  INT8_C(  29),  INT8_C(  55), -INT8_C(   7),  INT8_C(  82), -INT8_C(  80),
         INT8_C( 124), -INT8_C(  86), -INT8_C(  87),  INT8_C(  63),  INT8_C(  19), -INT8_C(  64), -INT8_C(  22),  INT8_C(  26),
         INT8_C(  21),  INT8_C(  33), -INT8_C(  41),  INT8_C(  57),  INT8_C(  47), -INT8_C(   7),  INT8_C( 114), -INT8_C(   5),
        -INT8_C(  48), -INT8_C( 116),  INT8_C( 102),  INT8_C(  45), -INT8_C(  97),  INT8_C(  56), -INT8_C(  39),  INT8_C(  77) },
      {  INT8_C(  77),  INT8_C(  78), -INT8_C(  24), -INT8_C( 102), -INT8_C(   9),  INT8_C(   7), -INT8_C( 120),  INT8_C(  63),
        -INT8_C(  42),  INT8_C( 111),  INT8_C(  41),  INT8_C(  94),  INT8_C(  52),  INT8_C(  13), -INT8_C(  73),  INT8_C(  53),
        -INT8_C(  98),  INT8_C(   7), -INT8_C(  89),  INT8_C(  85), -INT8_C( 114),  INT8_C(  55),  INT8_C(  32), -INT8_C(  67),
        -INT8_C(  92),  INT8_C(  35),  INT8_C(  24),  INT8_C(  14), -INT8_C( 112),  INT8_C(  33),  INT8_C(  75),  INT8_C(  57),
        -INT8_C(  55), -INT8_C(  82), -INT8_C(  56), -INT8_C(  39), -INT8_C(  95), -INT8_C(  21), -INT8_C(  97),  INT8_C(  29),
        -INT8_C(  15),  INT8_C(  55), -INT8_C(  43), -INT8_C(   7),  INT8_C(  87),  INT8_C(  82), -INT8_C(  50), -INT8_C(  80),
        -INT8_C(  25),  INT8_C(  21), -INT8_C(  98),  INT8_C(  33),  INT8_C(  62), -INT8_C(  41), -INT8_C( 116),  INT8_C(  57),
        -INT8_C(  74),  INT8_C(  47), -INT8_C(  50), -INT8_C(   7), -INT8_C(  41),  INT8_C( 114),  INT8_C( 100), -INT8_C(   5) } },
    { {  INT8_C(  17), -INT8_C(  59),  INT8_C( 107),  INT8_C(  72), -INT8_C(  66), -INT8_C(  67), -INT8_C(   8),  INT8_C(  58),
         INT8_C( 104), -INT8_C(  94),  INT8_C( 121),  INT8_C( 123),  INT8_C(  98),  INT8_C( 100), -INT8_C( 107),  INT8_C( 120),
        -INT8_C( 123),  INT8_C( 108), -INT8_C(  79), -INT8_C(  75),  INT8_C( 101),  INT8_C(  35), -INT8_C(  80),  INT8_C(  53),
        -INT8_C(  81),  INT8_C(  22),  INT8_C(  99),  INT8_C(  78),  INT8_C(  78),  INT8_C(  60), -INT8_C( 100),  INT8_C(  95),
         INT8_C(   1),  INT8_C(   7), -INT8_C(  89), -INT8_C(  65), -INT8_C(  60), -INT8_C(  96), -INT8_C(   7),  INT8_C(  44),
         INT8_C(  66),  INT8_C( 115), -INT8_C(  89), -INT8_C(  92), -INT8_C(  41),  INT8_C(  60),  INT8_C(  28),  INT8_C(  92),
        -INT8_C(  87), -INT8_C(  51),  INT8_C(  17),  INT8_C(  14), -INT8_C(  16), -INT8_C(  62),  INT8_C(  68), -INT8_C(  97),
        -INT8_C(  40), -INT8_C(  89), -INT8_C(  18),  INT8_C(  39), -INT8_C(  29), -INT8_C( 118), -INT8_C( 122), -INT8_C(  27) },
      { -INT8_C( 111),  INT8_C(  46), -INT8_C(  92),  INT8_C(  85), -INT8_C(  50), -INT8_C(  98), -INT8_C( 126),  INT8_C(  16),
         INT8_C(  17),  INT8_C(  41), -INT8_C(  76), -INT8_C(  24),  INT8_C( 102), -INT8_C(  47),  INT8_C(  68),  INT8_C(  15),
        -INT8_C(  98),  INT8_C(  86),  INT8_C(  29), -INT8_C( 113),  INT8_C(  24),  INT8_C(  97),  INT8_C(  46), -INT8_C(  16),
         INT8_C(   8),  INT8_C(  28),  INT8_C(  23), -INT8_C(  20), -INT8_C(  90), -INT8_C(  98), -INT8_C(  47),  INT8_C(  55),
        -INT8_C(  52),  INT8_C( 117), -INT8_C( 115), -INT8_C( 102),  INT8_C(  19),  INT8_C(  15), -INT8_C(  86),  INT8_C(  36),
         INT8_C(  56),  INT8_C(  94),  INT8_C(  12), -INT8_C(  98),  INT8_C(  47),  INT8_C(  81), -INT8_C(  83), -INT8_C(  50),
        -INT8_C(  89), -INT8_C(  53),  INT8_C(  93), -INT8_C(  65),  INT8_C(  44), -INT8_C( 117), -INT8_C(  81),  INT8_C(  53),
        -INT8_C(  88), -INT8_C(  57),  INT8_C(  33),  INT8_C(  78),  INT8_C( 101), -INT8_C(  14), -INT8_C( 122),  INT8_C(  49) },
      {  INT8_C(  17), -INT8_C( 111), -INT8_C(  59),  INT8_C(  46),  INT8_C( 107), -INT8_C(  92),  INT8_C(  72),  INT8_C(  85),
        -INT8_C(  66), -INT8_C(  50), -INT8_C(  67), -INT8_C(  98), -INT8_C(   8), -INT8_C( 126),  INT8_C(  58),  INT8_C(  16),
        -INT8_C( 123), -INT8_C(  98),  INT8_C( 108),  INT8_C(  86), -INT8_C(  79),  INT8_C(  29), -INT8_C(  75), -INT8_C( 113),
         INT8_C( 101),  INT8_C(  24),  INT8_C(  35),  INT8_C(  97), -INT8_C(  80),  INT8_C(  46),  INT8_C(  53), -INT8_C(  16),
         INT8_C(   1), -INT8_C(  52),  INT8_C(   7),  INT8_C( 117), -INT8_C(  89), -INT8_C( 115), -INT8_C(  65), -INT8_C( 102),
        -INT8_C(  60),  INT8_C(  19), -INT8_C(  96),  INT8_C(  15), -INT8_C(   7), -INT8_C(  86),  INT8_C(  44),  INT8_C(  36),
        -INT8_C(  87), -INT8_C(  89), -INT8_C(  51), -INT8_C(  53),  INT8_C(  17),  INT8_C(  93),  INT8_C(  14), -INT8_C(  65),
        -INT8_C(  16),  INT8_C(  44), -INT8_C(  62), -INT8_C( 117),  INT8_C(  68), -INT8_C(  81), -INT8_C(  97),  INT8_C(  53) } },
    { {  INT8_C( 103),  INT8_C(  19), -INT8_C(  53),  INT8_C( 123),  INT8_C(  34),  INT8_C( 117), -INT8_C(  97),  INT8_C(  90),
        -INT8_C(  45), -INT8_C(  84), -INT8_C(   7),  INT8_C(   3), -INT8_C(   3), -INT8_C(  90), -INT8_C(  47), -INT8_C(  92),
         INT8_C( 113),  INT8_C(  46),  INT8_C(  99), -INT8_C(  98), -INT8_C(  71),  INT8_C(  18), -INT8_C(  45),  INT8_C(  97),
        -INT8_C(  39), -INT8_C(  12), -INT8_C(  80),  INT8_C(  62), -INT8_C(  26),  INT8_C(  54),  INT8_C( 111),  INT8_C(  77),
         INT8_C(  73),  INT8_C(  58), -INT8_C(  56),  INT8_C( 107), -INT8_C(  81),  INT8_C( 104), -INT8_C(  59), -INT8_C( 125),
         INT8_C(  20), -INT8_C(  66), -INT8_C( 122),  INT8_C(  17),  INT8_C( 101),  INT8_C(  87), -INT8_C(  75), -INT8_C(  42),
        -INT8_C( 123),  INT8_C(  24),  INT8_C( 116),  INT8_C(  62),  INT8_C(  42),  INT8_C(  71), -INT8_C(  96),  INT8_C(   4),
         INT8_C(  59),  INT8_C(  80),  INT8_C(  66),  INT8_C(  33), -INT8_C( 122), -INT8_C(  78),  INT8_C( 111), -INT8_C(  49) },
      { -INT8_C(  20),  INT8_C(  55),  INT8_C(  58), -INT8_C( 100), -INT8_C(  97), -INT8_C(   1),  INT8_C(  31), -INT8_C(  77),
        -INT8_C(  66), -INT8_C(  91), -INT8_C(  60),  INT8_C(  35), -INT8_C(   4),  INT8_C( 121), -INT8_C(   7), -INT8_C( 127),
        -INT8_C( 111),  INT8_C( 110), -INT8_C(  65), -INT8_C(  68), -INT8_C(  75),  INT8_C(  95), -INT8_C(  64), -INT8_C(  15),
        -INT8_C(  81),  INT8_C(   2),  INT8_C(  18),  INT8_C(  53), -INT8_C(  76), -INT8_C( 127),  INT8_C(   4), -INT8_C(  95),
        -INT8_C(  71),  INT8_C(  62),  INT8_C(  61),  INT8_C(  88),  INT8_C(  62),  INT8_C(  92),  INT8_C(  12), -INT8_C(   4),
         INT8_C(   1), -INT8_C(  48),  INT8_C(  31), -INT8_C(   3),  INT8_C(  74),  INT8_C(  24),  INT8_C( 126), -INT8_C(  37),
        -INT8_C( 122),  INT8_C(  61), -INT8_C( 105),  INT8_C(  60), -INT8_C(  99),  INT8_C(  87),  INT8_C(  45),  INT8_C(  76),
         INT8_C(  90),  INT8_C(  63), -INT8_C( 126),  INT8_C(  14), -INT8_C(  63), -INT8_C( 122), -INT8_C(  81),  INT8_C( 122) },
      {  INT8_C( 103), -INT8_C(  20),  INT8_C(  19),  INT8_C(  55), -INT8_C(  53),  INT8_C(  58),  INT8_C( 123), -INT8_C( 100),
         INT8_C(  34), -INT8_C(  97),  INT8_C( 117), -INT8_C(   1), -INT8_C(  97),  INT8_C(  31),  INT8_C(  90), -INT8_C(  77),
         INT8_C( 113), -INT8_C( 111),  INT8_C(  46),  INT8_C( 110),  INT8_C(  99), -INT8_C(  65), -INT8_C(  98), -INT8_C(  68),
        -INT8_C(  71), -INT8_C(  75),  INT8_C(  18),  INT8_C(  95), -INT8_C(  45), -INT8_C(  64),  INT8_C(  97), -INT8_C(  15),
         INT8_C(  73), -INT8_C(  71),  INT8_C(  58),  INT8_C(  62), -INT8_C(  56),  INT8_C(  61),  INT8_C( 107),  INT8_C(  88),
        -INT8_C(  81),  INT8_C(  62),  INT8_C( 104),  INT8_C(  92), -INT8_C(  59),  INT8_C(  12), -INT8_C( 125), -INT8_C(   4),
        -INT8_C( 123), -INT8_C( 122),  INT8_C(  24),  INT8_C(  61),  INT8_C( 116), -INT8_C( 105),  INT8_C(  62),  INT8_C(  60),
         INT8_C(  42), -INT8_C(  99),  INT8_C(  71),  INT8_C(  87), -INT8_C(  96),  INT8_C(  45),  INT8_C(   4),  INT8_C(  76) } },
    { { -INT8_C(  59), -INT8_C(  20), -INT8_C(  46),  INT8_C(   3),  INT8_C(  72), -INT8_C(  34), -INT8_C(   1),  INT8_C(  73),
        -INT8_C(  81),  INT8_C(  30),  INT8_C(  70), -INT8_C(   7),  INT8_C(  54), -INT8_C(  60), -INT8_C(  44), -INT8_C(  67),
         INT8_C(   2),  INT8_C( 108), -INT8_C(   7), -INT8_C(  97), -INT8_C(  61),  INT8_C(  38), -INT8_C(  21),  INT8_C(  29),
         INT8_C( 101),  INT8_C( 109),  INT8_C(  44),  INT8_C(  38), -INT8_C(  12), -INT8_C(  37), -INT8_C(  96), -INT8_C(  71),
        -INT8_C(  56),  INT8_C( 115), -INT8_C(  68),  INT8_C(  16),  INT8_C(  81), -INT8_C(  69),  INT8_C(  90),  INT8_C(   0),
        -INT8_C(  39), -INT8_C(  96), -INT8_C(   7),  INT8_C(  15),  INT8_C( 101), -INT8_C(  50), -INT8_C(  52),  INT8_C( 103),
         INT8_C(  58), -INT8_C(  59),  INT8_C(   6), -INT8_C(   3), -INT8_C(  21), -INT8_C(  15),  INT8_C(  27),  INT8_C(  81),
         INT8_C(  95),  INT8_C(  71),  INT8_C( 119),  INT8_C(  83),  INT8_C(  34),  INT8_C(  24),  INT8_C(  12), -INT8_C(  22) },
      { -INT8_C( 117), -INT8_C(  56), -INT8_C(   5), -INT8_C(  36), -INT8_C( 125),  INT8_C(  85), -INT8_C(  35),  INT8_C(  92),
        -INT8_C(  11), -INT8_C(  42),  INT8_C( 107),  INT8_C(  90), -INT8_C(  92),  INT8_C(  56), -INT8_C(  63), -INT8_C(  34),
        -INT8_C(   3), -INT8_C(  57), -INT8_C(  36), -INT8_C(  23), -INT8_C(  71), -INT8_C(   9),  INT8_C(  58),  INT8_C(  24),
         INT8_C(  62), -INT8_C(  79),  INT8_C( 107),  INT8_C(  96), -INT8_C(  55),  INT8_C( 119),  INT8_C(  75),  INT8_C(  84),
         INT8_C(  63),  INT8_C(  70),  INT8_C(  49), -INT8_C(  62), -INT8_C( 101),  INT8_C(  14),  INT8_C(  30), -INT8_C( 112),
        -INT8_C(  28), -INT8_C( 119), -INT8_C(  21), -INT8_C( 119), -INT8_C(  63), -INT8_C(  84),  INT8_C( 103), -INT8_C(  65),
         INT8_C( 116),  INT8_C(  67), -INT8_C(  88),  INT8_C(  45),  INT8_C(  58), -INT8_C(  30),  INT8_C(  69),  INT8_C( 120),
        -INT8_C( 109), -INT8_C(  80), -INT8_C(  39),  INT8_C(  93),  INT8_C(  39),  INT8_C(  36), -INT8_C(  79),  INT8_C( 102) },
      { -INT8_C(  59), -INT8_C( 117), -INT8_C(  20), -INT8_C(  56), -INT8_C(  46), -INT8_C(   5),  INT8_C(   3), -INT8_C(  36),
         INT8_C(  72), -INT8_C( 125), -INT8_C(  34),  INT8_C(  85), -INT8_C(   1), -INT8_C(  35),  INT8_C(  73),  INT8_C(  92),
         INT8_C(   2), -INT8_C(   3),  INT8_C( 108), -INT8_C(  57), -INT8_C(   7), -INT8_C(  36), -INT8_C(  97), -INT8_C(  23),
        -INT8_C(  61), -INT8_C(  71),  INT8_C(  38), -INT8_C(   9), -INT8_C(  21),  INT8_C(  58),  INT8_C(  29),  INT8_C(  24),
        -INT8_C(  56),  INT8_C(  63),  INT8_C( 115),  INT8_C(  70), -INT8_C(  68),  INT8_C(  49),  INT8_C(  16), -INT8_C(  62),
         INT8_C(  81), -INT8_C( 101), -INT8_C(  69),  INT8_C(  14),  INT8_C(  90),  INT8_C(  30),  INT8_C(   0), -INT8_C( 112),
         INT8_C(  58),  INT8_C( 116), -INT8_C(  59),  INT8_C(  67),  INT8_C(   6), -INT8_C(  88), -INT8_C(   3),  INT8_C(  45),
        -INT8_C(  21),  INT8_C(  58), -INT8_C(  15), -INT8_C(  30),  INT8_C(  27),  INT8_C(  69),  INT8_C(  81),  INT8_C( 120) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i a = simde_mm512_loadu_epi8(test_vec[i].a);
    simde__m512i b = simde_mm512_loadu_epi8(test_vec[i].b);
    simde__m512i r = simde_mm512_unpacklo_epi8(a, b);
    simde_test_x86_assert_equal_i8x64(r, simde_mm512_loadu_epi8(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_mm512_unpacklo_epi16 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const int16_t a[32];
    const int16_t b[32];
    const int16_t r[32];
  } test_vec[] = {
    { { -INT16_C( 31331), -INT16_C( 31002),  INT16_C( 23655),  INT16_C( 30198),  INT16_C( 10179), -INT16_C(  9689),  INT16_C( 31352),  INT16_C( 27403),
         INT16_C(  9684), -INT16_C( 30117), -INT16_C(  8450),  INT16_C( 25365), -INT16_C(  3020), -INT16_C( 21287),  INT16_C( 13982),  INT16_C( 15230),
         INT16_C( 26043),  INT16_C(  8898), -INT16_C( 18239), -INT16_C( 31593), -INT16_C( 16417),  INT16_C( 22367),  INT16_C( 27193),  INT16_C(  3779),
         INT16_C(  7824), -INT16_C( 29032), -INT16_C( 20996),  INT16_C( 12530), -INT16_C( 13406),  INT16_C( 16604),  INT16_C( 23297), -INT16_C( 17029) },
      {  INT16_C( 15808), -INT16_C( 32289),  INT16_C( 30709), -INT16_C( 11258),  INT16_C( 25910),  INT16_C( 28460), -INT16_C(  4145),  INT16_C( 24445),
         INT16_C(  5645),  INT16_C(  2798), -INT16_C(  7997),  INT16_C( 25914),  INT16_C(  6059), -INT16_C( 21083),  INT16_C(  8562),  INT16_C( 12906),
         INT16_C( 18782),  INT16_C( 21683), -INT16_C( 17984), -INT16_C(  2520),  INT16_C( 21534), -INT16_C(  4506), -INT16_C(  7357),  INT16_C( 20813),
         INT16_C( 15353), -INT16_C( 17061), -INT16_C( 27365), -INT16_C( 14558), -INT16_C( 14164),  INT16_C(  7796), -INT16_C(  8471),  INT16_C( 18256) },
      { -INT16_C( 31331),  INT16_C( 15808), -INT16_C( 31002), -INT16_C( 32289),  INT16_C( 23655),  INT16_C( 30709),  INT16_C( 30198), -INT16_C( 11258),
         INT16_C(  9684),  INT16_C(  5645), -INT16_C( 30117),  INT16_C(  2798), -INT16_C(  8450), -INT16_C(  7997),  INT16_C( 25365),  INT16_C( 25914),
         INT16_C( 26043),  INT16_C( 18782),  INT16_C(  8898),  INT16_C( 21683), -INT16_C( 18239), -INT16_C( 17984), -INT16_C( 31593), -INT16_C(  2520),
         INT16_C(  7824),  INT16_C( 15353), -INT16_C( 29032), -INT16_C( 17061), -INT16_C( 20996), -INT16_C( 27365),  INT16_C( 12530), -INT16_C( 14558) } },
    { {  INT16_C(  1063), -INT16_C(  5989), -INT16_C( 15171), -INT16_C(  8994),  INT16_C( 17432),  INT16_C( 23754),  INT16_C(  5928),  INT16_C(  8621),
         INT16_C(  2131),  INT16_C( 28382),  INT16_C(   413),  INT16_C( 18997), -INT16_C( 22071), -INT16_C( 19864), -INT16_C( 18041), -INT16_C( 20487),
        -INT16_C( 27203),  INT16_C( 31383),  INT16_C( 30041),  INT16_C( 29014),  INT16_C(  8378), -INT16_C(  7475),  INT16_C( 31288), -INT16_C( 29949),
        -INT16_C(  7550),  INT16_C(  8441),  INT16_C( 12259), -INT16_C( 21398), -INT16_C( 11560),  INT16_C( 24670),  INT16_C( 22411),  INT16_C( 18447) },
      { -INT16_C( 22804),  INT16_C( 17859),  INT16_C(  6427), -INT16_C( 10825), -INT16_C( 31686),  INT16_C( 29367), -INT16_C( 17409), -INT16_C( 32259),
        -INT16_C(  2403), -INT16_C( 32607),  INT16_C(  2853), -INT16_C(   468), -INT16_C( 29986),  INT16_C( 26974),  INT16_C( 28129), -INT16_C( 12622),
         INT16_C( 29971),  INT16_C( 11795), -INT16_C( 13682), -INT16_C( 14332), -INT16_C( 17585),  INT16_C( 20026),  INT16_C( 14198),  INT16_C(  5071),
         INT16_C( 28974),  INT16_C( 21395), -INT16_C( 16516),  INT16_C( 23121), -INT16_C( 20663),  INT16_C( 11204),  INT16_C( 30236),  INT16_C( 12281) },
      {  INT16_C(  1063), -INT16_C( 22804), -INT16_C(  5989),  INT16_C( 17859), -INT16_C( 15171),  INT16_C(  6427), -INT16_C(  8994), -INT16_C( 10825),
         INT16_C(  2131), -INT16_C(  2403),  INT16_C( 28382), -INT16_C( 32607),  INT16_C(   413),  INT16_C(  2853),  INT16_C( 18997), -INT16_C(   468),
        -INT16_C( 27203),  INT16_C( 29971),  INT16_C( 31383),  INT16_C( 11795),  INT16_C( 30041), -INT16_C( 13682),  INT16_C( 29014), -INT16_C( 14332),
        -INT16_C(  7550),  INT16_C( 28974),  INT16_C(  8441),  INT16_C( 21395),  INT16_C( 12259), -INT16_C( 16516), -INT16_C( 21398),  INT16_C( 23121) } },
    { {  INT16_C(  3307),  INT16_C( 31070),  INT16_C( 25303),  INT16_C(  9794),  INT16_C( 31773), -INT16_C( 27532),  INT16_C( 17332), -INT16_C(  7513),
         INT16_C( 15284),  INT16_C( 12597), -INT16_C( 30726),  INT16_C( 17547),  INT16_C( 20278),  INT16_C( 21359),  INT16_C( 26821), -INT16_C( 20350),
        -INT16_C(  8076),  INT16_C( 19242),  INT16_C( 27714),  INT16_C( 24689), -INT16_C(  6680), -INT16_C( 25356), -INT16_C( 25815), -INT16_C(  8834),
        -INT16_C( 19242), -INT16_C( 12018), -INT16_C( 26053),  INT16_C( 28949), -INT16_C( 31511), -INT16_C( 20540),  INT16_C( 18412),  INT16_C( 24671) },
      { -INT16_C( 30425),  INT16_C( 27308),  INT16_C(  7669), -INT16_C(  8502), -INT16_C( 16893),  INT16_C( 11386), -INT16_C(  1703),  INT16_C( 12297),
         INT16_C(  6317), -INT16_C(  6143),  INT16_C(  5810), -INT16_C( 25767),  INT16_C(  7834), -INT16_C( 31158), -INT16_C( 21915), -INT16_C( 29466),
        -INT16_C( 28109),  INT16_C( 10742), -INT16_C( 16208), -INT16_C( 19705), -INT16_C( 32386), -INT16_C( 10017), -INT16_C(  6022),  INT16_C(  9992),
         INT16_C(  2304), -INT16_C( 19953),  INT16_C( 26911), -INT16_C( 18098), -INT16_C( 26489), -INT16_C(  5057),  INT16_C(  9538),  INT16_C( 30328) },
      {  INT16_C(  3307), -INT16_C( 30425),  INT16_C( 31070),  INT16_C( 27308),  INT16_C( 25303),  INT16_C(  7669),  INT16_C(  9794), -INT16_C(  8502),
         INT16_C( 15284),  INT16_C(  6317),  INT16_C( 12597), -INT16_C(  6143), -INT16_C( 30726),  INT16_C(  5810),  INT16_C( 17547), -INT16_C( 25767),
        -INT16_C(  8076), -INT16_C( 28109),  INT16_C( 19242),  INT16_C( 10742),  INT16_C( 27714), -INT16_C( 16208),  INT16_C( 24689), -INT16_C( 19705),
        -INT16_C( 19242),  INT16_C(  2304), -INT16_C( 12018), -INT16_C( 19953), -INT16_C( 26053),  INT16_C( 26911),  INT16_C( 28949), -INT16_C( 18098) } },
    { {  INT16_C( 28600),  INT16_C( 26783), -INT16_C( 22993), -INT16_C( 20965), -INT16_C(  1497), -INT16_C( 23930), -INT16_C( 28958), -INT16_C(  7223),
        -INT16_C(  9833), -INT16_C( 18795), -INT16_C(  7358), -INT16_C( 13969), -INT16_C( 20868), -INT16_C( 16715),  INT16_C( 11731), -INT16_C( 29900),
        -INT16_C( 11364), -INT16_C( 13069),  INT16_C(  3705), -INT16_C( 24198),  INT16_C(     8), -INT16_C(  5309),  INT16_C(  3214),  INT16_C(  9678),
         INT16_C( 25573),  INT16_C( 10203),  INT16_C( 19015), -INT16_C( 15376), -INT16_C( 23048), -INT16_C( 13439), -INT16_C( 18733),  INT16_C( 28503) },
      {  INT16_C( 19081),  INT16_C(   827), -INT16_C( 19111),  INT16_C( 24996), -INT16_C(  6219),  INT16_C( 17228),  INT16_C(  6899), -INT16_C(  9880),
         INT16_C( 17278), -INT16_C( 15104), -INT16_C(  3699), -INT16_C( 31352),  INT16_C(  2454),  INT16_C( 26961), -INT16_C( 22337),  INT16_C( 18905),
         INT16_C(  5362),  INT16_C( 19276), -INT16_C(  3894),  INT16_C( 32685), -INT16_C(  1577), -INT16_C( 13629),  INT16_C( 11028), -INT16_C( 27997),
        -INT16_C( 23441), -INT16_C(   937), -INT16_C(  8299),  INT16_C( 11138), -INT16_C( 11288), -INT16_C( 22379),  INT16_C( 28283),  INT16_C( 28145) },
      {  INT16_C( 28600),  INT16_C( 19081),  INT16_C( 26783),  INT16_C(   827), -INT16_C( 22993), -INT16_C( 19111), -INT16_C( 20965),  INT16_C( 24996),
        -INT16_C(  9833),  INT16_C( 17278), -INT16_C( 18795), -INT16_C( 15104), -INT16_C(  7358), -INT16_C(  3699), -INT16_C( 13969), -INT16_C( 31352),
        -INT16_C( 11364),  INT16_C(  5362), -INT16_C( 13069),  INT16_C( 19276),  INT16_C(  3705), -INT16_C(  3894), -INT16_C( 24198),  INT16_C( 32685),
         INT16_C( 25573), -INT16_C( 23441),  INT16_C( 10203), -INT16_C(   937),  INT16_C( 19015), -INT16_C(  8299), -INT16_C( 15376),  INT16_C( 11138) } },
    { {  INT16_C( 15746),  INT16_C( 19641),  INT16_C( 26157),  INT16_C(  1228), -INT16_C( 28833),  INT16_C( 29646),  INT16_C( 29370),  INT16_C( 10501),
         INT16_C( 23574), -INT16_C( 21722), -INT16_C( 22469),  INT16_C(  9430),  INT16_C( 27515), -INT16_C(  2356), -INT16_C( 16935),  INT16_C( 23651),
         INT16_C(  7418),  INT16_C( 10152),  INT16_C( 29826), -INT16_C(  7637), -INT16_C(  1789), -INT16_C( 16811),  INT16_C( 23403), -INT16_C( 32281),
         INT16_C(  3511), -INT16_C(  3284),  INT16_C(   949),  INT16_C( 12311), -INT16_C(  7314),  INT16_C( 18470), -INT16_C( 30048), -INT16_C( 25948) },
      {  INT16_C( 19622),  INT16_C( 10689), -INT16_C(  4927), -INT16_C( 15349),  INT16_C( 24805),  INT16_C( 20866),  INT16_C( 27323),  INT16_C( 29650),
        -INT16_C(   137),  INT16_C( 11622),  INT16_C( 32002),  INT16_C( 28765), -INT16_C( 31648),  INT16_C(   184),  INT16_C( 23566), -INT16_C( 19302),
         INT16_C( 23465),  INT16_C( 27357), -INT16_C(  6073),  INT16_C( 11310), -INT16_C( 20151),  INT16_C(  1149),  INT16_C( 20507), -INT16_C( 28041),
        -INT16_C(  8881),  INT16_C( 20927),  INT16_C(  7514), -INT16_C( 17727),  INT16_C( 31393), -INT16_C( 20550),  INT16_C( 21718),  INT16_C( 32611) },
      {  INT16_C( 15746),  INT16_C( 19622),  INT16_C( 19641),  INT16_C( 10689),  INT16_C( 26157), -INT16_C(  4927),  INT16_C(  1228), -INT16_C( 15349),
         INT16_C( 23574), -INT16_C(   137), -INT16_C( 21722),  INT16_C( 11622), -INT16_C( 22469),  INT16_C( 32002),  INT16_C(  9430),  INT16_C( 28765),
         INT16_C(  7418),  INT16_C( 23465),  INT16_C( 10152),  INT16_C( 27357),  INT16_C( 29826), -INT16_C(  6073), -INT16_C(  7637),  INT16_C( 11310),
         INT16_C(  3511), -INT16_C(  8881), -INT16_C(  3284),  INT16_C( 20927),  INT16_C(   949),  INT16_C(  7514),  INT16_C( 12311), -INT16_C( 17727) } },
    { {  INT16_C( 16815), -INT16_C(  2327),  INT16_C(  6185),  INT16_C( 29219), -INT16_C( 24375), -INT16_C(  7049), -INT16_C(  4368),  INT16_C( 16246),
         INT16_C( 14028),  INT16_C(  9872),  INT16_C( 21075), -INT16_C(  2847), -INT16_C( 25652), -INT16_C( 23901),  INT16_C(  1776), -INT16_C( 24798),
         INT16_C(  2887),  INT16_C( 29078), -INT16_C( 18141), -INT16_C(  4893),  INT16_C( 23129),  INT16_C( 19152),  INT16_C( 18249),  INT16_C(  5513),
         INT16_C(  6781), -INT16_C( 12229),  INT16_C(  7276),  INT16_C( 14532),  INT16_C( 26552), -INT16_C( 22310), -INT16_C(   915), -INT16_C( 19129) },
      { -INT16_C(  8952),  INT16_C( 11046),  INT16_C(  2454), -INT16_C(  4072), -INT16_C(  6044), -INT16_C( 21190), -INT16_C( 15569), -INT16_C( 21310),
        -INT16_C(   547),  INT16_C( 18812),  INT16_C( 16410), -INT16_C( 11647),  INT16_C( 23719),  INT16_C(  5498), -INT16_C( 16040),  INT16_C( 24778),
        -INT16_C(  3937),  INT16_C( 13708), -INT16_C( 23303),  INT16_C( 23845),  INT16_C( 24460), -INT16_C( 17398), -INT16_C( 13277),  INT16_C(   104),
        -INT16_C(  6710), -INT16_C(  7094), -INT16_C( 13531), -INT16_C( 12874),  INT16_C( 12327), -INT16_C( 32542), -INT16_C( 21263), -INT16_C( 28448) },
      {  INT16_C( 16815), -INT16_C(  8952), -INT16_C(  2327),  INT16_C( 11046),  INT16_C(  6185),  INT16_C(  2454),  INT16_C( 29219), -INT16_C(  4072),
         INT16_C( 14028), -INT16_C(   547),  INT16_C(  9872),  INT16_C( 18812),  INT16_C( 21075),  INT16_C( 16410), -INT16_C(  2847), -INT16_C( 11647),
         INT16_C(  2887), -INT16_C(  3937),  INT16_C( 29078),  INT16_C( 13708), -INT16_C( 18141), -INT16_C( 23303), -INT16_C(  4893),  INT16_C( 23845),
         INT16_C(  6781), -INT16_C(  6710), -INT16_C( 12229), -INT16_C(  7094),  INT16_C(  7276), -INT16_C( 13531),  INT16_C( 14532), -INT16_C( 12874) } },
    { {  INT16_C( 27804), -INT16_C( 27194), -INT16_C(  5360), -INT16_C( 25101), -INT16_C(   693),  INT16_C( 28249), -INT16_C( 15926), -INT16_C( 27538),
        -INT16_C( 18266), -INT16_C( 13192),  INT16_C( 11908), -INT16_C( 21607),  INT16_C( 31582),  INT16_C( 20267),  INT16_C(  3111), -INT16_C( 15392),
        -INT16_C( 22920), -INT16_C( 30376),  INT16_C( 19345), -INT16_C(  9178),  INT16_C( 32585),  INT16_C(  4938), -INT16_C( 18112), -INT16_C(  6233),
         INT16_C(  8049), -INT16_C(  2637),  INT16_C( 19533), -INT16_C( 21599), -INT16_C( 13113), -INT16_C(  4358), -INT16_C(  9512),  INT16_C( 20913) },
      {  INT16_C(  2432),  INT16_C(  4826),  INT16_C(    85), -INT16_C( 24850),  INT16_C( 14719), -INT16_C( 16463),  INT16_C( 22770),  INT16_C( 25510),
         INT16_C( 22903), -INT16_C( 15271), -INT16_C(  1371),  INT16_C( 27759),  INT16_C( 27078), -INT16_C( 24742),  INT16_C(  2884), -INT16_C( 15120),
        -INT16_C( 13803),  INT16_C( 27350), -INT16_C( 14902),  INT16_C( 18696), -INT16_C( 17922), -INT16_C(  4088), -INT16_C( 20719), -INT16_C( 30637),
        -INT16_C( 21496), -INT16_C( 20916), -INT16_C( 17498),  INT16_C( 27930),  INT16_C( 29988),  INT16_C( 26636), -INT16_C(   896), -INT16_C( 27347) },
      {  INT16_C( 27804),  INT16_C(  2432), -INT16_C( 27194),  INT16_C(  4826), -INT16_C(  5360),  INT16_C(    85), -INT16_C( 25101), -INT16_C( 24850),
        -INT16_C( 18266),  INT16_C( 22903), -INT16_C( 13192), -INT16_C( 15271),  INT16_C( 11908), -INT16_C(  1371), -INT16_C( 21607),  INT16_C( 27759),
        -INT16_C( 22920), -INT16_C( 13803), -INT16_C( 30376),  INT16_C( 27350),  INT16_C( 19345), -INT16_C( 14902), -INT16_C(  9178),  INT16_C( 18696),
         INT16_C(  8049), -INT16_C( 21496), -INT16_C(  2637), -INT16_C( 20916),  INT16_C( 19533), -INT16_C( 17498), -INT16_C( 21599),  INT16_C( 27930) } },
    { {  INT16_C(   966), -INT16_C( 28417),  INT16_C(  1992), -INT16_C( 14631), -INT16_C(  7744), -INT16_C( 11850),  INT16_C(  2704), -INT16_C( 26279),
        -INT16_C( 23114),  INT16_C( 23879),  INT16_C( 24928), -INT16_C( 31286), -INT16_C( 10538),  INT16_C( 22509),  INT16_C(  6866), -INT16_C( 26388),
        -INT16_C(  5090), -INT16_C(  6616),  INT16_C(   499), -INT16_C( 19283),  INT16_C( 25570),  INT16_C( 29573), -INT16_C(  8339),  INT16_C(  9228),
         INT16_C( 21380), -INT16_C(  6783),  INT16_C( 19380), -INT16_C( 29846),  INT16_C( 22305), -INT16_C(  3102), -INT16_C( 12686), -INT16_C( 28533) },
      { -INT16_C( 19526), -INT16_C( 20874),  INT16_C(  9140), -INT16_C( 27038), -INT16_C(  6265), -INT16_C(  3063),  INT16_C(  5574),  INT16_C( 19224),
        -INT16_C( 26264),  INT16_C(  7472), -INT16_C( 25884),  INT16_C(  1448), -INT16_C( 29967),  INT16_C( 25592), -INT16_C( 31912),  INT16_C(  5107),
         INT16_C( 27190), -INT16_C(  5439),  INT16_C(  9101),  INT16_C(  5249), -INT16_C( 30198), -INT16_C( 12023),  INT16_C(  8608),  INT16_C(  2076),
         INT16_C( 19643), -INT16_C( 24795), -INT16_C( 12826), -INT16_C( 10331), -INT16_C( 25257), -INT16_C( 20421),  INT16_C( 11809),  INT16_C( 22467) },
      {  INT16_C(   966), -INT16_C( 19526), -INT16_C( 28417), -INT16_C( 20874),  INT16_C(  1992),  INT16_C(  9140), -INT16_C( 14631), -INT16_C( 27038),
        -INT16_C( 23114), -INT16_C( 26264),  INT16_C( 23879),  INT16_C(  7472),  INT16_C( 24928), -INT16_C( 25884), -INT16_C( 31286),  INT16_C(  1448),
        -INT16_C(  5090),  INT16_C( 27190), -INT16_C(  6616), -INT16_C(  5439),  INT16_C(   499),  INT16_C(  9101), -INT16_C( 19283),  INT16_C(  5249),
         INT16_C( 21380),  INT16_C( 19643), -INT16_C(  6783), -INT16_C( 24795),  INT16_C( 19380), -INT16_C( 12826), -INT16_C( 29846), -INT16_C( 10331) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i a = simde_mm512_loadu_epi16(test_vec[i].a);
    simde__m512i b = simde_mm512_loadu_epi16(test_vec[i].b);
    simde__m512i r = simde_mm512_unpacklo_epi16(a, b);
    simde_test_x86_assert_equal_i16x32(r, simde_mm512_loadu_epi16(test_vec[i].r));
  }

  return 0;
}

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_unpacklo_epi8)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_unpacklo_epi16)
SIMDE_TEST_FUNC_LIST_END

#include <test/x86/avx512/test-avx512-footer.h>
