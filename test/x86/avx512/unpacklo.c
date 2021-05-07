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

static int
test_simde_mm512_unpacklo_epi32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int32_t a[16];
    const int32_t b[16];
    const int32_t r[16];
  } test_vec[] = {
    { { -INT32_C(  1952552182),  INT32_C(  1375111840),  INT32_C(   217036086),  INT32_C(   277958353),  INT32_C(  1662092024), -INT32_C(  2144205757),  INT32_C(  1670541238),  INT32_C(   871401769),
        -INT32_C(  1782608140),  INT32_C(  1340519705),  INT32_C(  1012716906),  INT32_C(   474803492), -INT32_C(  1300275857),  INT32_C(   389263713),  INT32_C(  1232782624),  INT32_C(  1132292942) },
      {  INT32_C(   316161273),  INT32_C(  1549975281), -INT32_C(  1214726509),  INT32_C(   450094251), -INT32_C(  1546825150),  INT32_C(   616235012),  INT32_C(   325989829), -INT32_C(  1705579616),
         INT32_C(   413937191), -INT32_C(  2139877652),  INT32_C(  2000096460),  INT32_C(   865209329),  INT32_C(  1641439069),  INT32_C(   612798815),  INT32_C(  1731720391),  INT32_C(   100765407) },
      { -INT32_C(  1952552182),  INT32_C(   316161273),  INT32_C(  1375111840),  INT32_C(  1549975281),  INT32_C(  1662092024), -INT32_C(  1546825150), -INT32_C(  2144205757),  INT32_C(   616235012),
        -INT32_C(  1782608140),  INT32_C(   413937191),  INT32_C(  1340519705), -INT32_C(  2139877652), -INT32_C(  1300275857),  INT32_C(  1641439069),  INT32_C(   389263713),  INT32_C(   612798815) } },
    { { -INT32_C(  1457606980), -INT32_C(  1993763908), -INT32_C(  1879023457), -INT32_C(   909929877),  INT32_C(  1344969457), -INT32_C(   227233749), -INT32_C(  2091209564), -INT32_C(   158770374),
        -INT32_C(   962615287), -INT32_C(   632305605), -INT32_C(  1804906711), -INT32_C(   748867870), -INT32_C(   198932280), -INT32_C(   572090312),  INT32_C(  2120237124), -INT32_C(  1518998884) },
      { -INT32_C(   848620398),  INT32_C(   111655645), -INT32_C(   325447158),  INT32_C(   163575873), -INT32_C(  1191320704), -INT32_C(  1063918468), -INT32_C(  1069550044),  INT32_C(  1919333600),
        -INT32_C(  1522544184), -INT32_C(  1767119220),  INT32_C(   981616377), -INT32_C(  1102888642), -INT32_C(  1586085595),  INT32_C(  1231096869), -INT32_C(   502620158),  INT32_C(   492073044) },
      { -INT32_C(  1457606980), -INT32_C(   848620398), -INT32_C(  1993763908),  INT32_C(   111655645),  INT32_C(  1344969457), -INT32_C(  1191320704), -INT32_C(   227233749), -INT32_C(  1063918468),
        -INT32_C(   962615287), -INT32_C(  1522544184), -INT32_C(   632305605), -INT32_C(  1767119220), -INT32_C(   198932280), -INT32_C(  1586085595), -INT32_C(   572090312),  INT32_C(  1231096869) } },
    { { -INT32_C(   842886335),  INT32_C(  1919118969), -INT32_C(   223550028),  INT32_C(  1286664231),  INT32_C(  1458382385),  INT32_C(   882855474),  INT32_C(  1125558767),  INT32_C(  1533045273),
         INT32_C(  1999119357),  INT32_C(  1172933777), -INT32_C(  1741187471), -INT32_C(  1209735290),  INT32_C(  1074647309),  INT32_C(   259304480),  INT32_C(  1867680598), -INT32_C(   204819467) },
      {  INT32_C(  1735062486), -INT32_C(   257141889),  INT32_C(  1871307753), -INT32_C(   685347382),  INT32_C(  1595355967),  INT32_C(   913214688),  INT32_C(   212189207),  INT32_C(  1241477235),
        -INT32_C(   491755165), -INT32_C(  1496163139),  INT32_C(   152460095),  INT32_C(   148978889),  INT32_C(  1348991088), -INT32_C(  1685662332),  INT32_C(   162016149), -INT32_C(    28137573) },
      { -INT32_C(   842886335),  INT32_C(  1735062486),  INT32_C(  1919118969), -INT32_C(   257141889),  INT32_C(  1458382385),  INT32_C(  1595355967),  INT32_C(   882855474),  INT32_C(   913214688),
         INT32_C(  1999119357), -INT32_C(   491755165),  INT32_C(  1172933777), -INT32_C(  1496163139),  INT32_C(  1074647309),  INT32_C(  1348991088),  INT32_C(   259304480), -INT32_C(  1685662332) } },
    { { -INT32_C(   824179951), -INT32_C(  1619741857), -INT32_C(   676820466),  INT32_C(   937396679),  INT32_C(   109528706), -INT32_C(  1314779877), -INT32_C(   725988808),  INT32_C(    47320305),
         INT32_C(  1875948303),  INT32_C(  1947092326), -INT32_C(  1773357361), -INT32_C(  1026741440), -INT32_C(  1916251022), -INT32_C(  1707185567), -INT32_C(  1502676812),  INT32_C(   346570757) },
      {  INT32_C(  1501788659), -INT32_C(  1915842114), -INT32_C(  2010899896), -INT32_C(  1219825339), -INT32_C(  1488645562),  INT32_C(   826377085), -INT32_C(  2116571268), -INT32_C(   476741392),
        -INT32_C(  1220732423), -INT32_C(   230421590),  INT32_C(  1786406949), -INT32_C(  1608334246),  INT32_C(  1413965783),  INT32_C(  1720027626),  INT32_C(   686251320), -INT32_C(   703824419) },
      { -INT32_C(   824179951),  INT32_C(  1501788659), -INT32_C(  1619741857), -INT32_C(  1915842114),  INT32_C(   109528706), -INT32_C(  1488645562), -INT32_C(  1314779877),  INT32_C(   826377085),
         INT32_C(  1875948303), -INT32_C(  1220732423),  INT32_C(  1947092326), -INT32_C(   230421590), -INT32_C(  1916251022),  INT32_C(  1413965783), -INT32_C(  1707185567),  INT32_C(  1720027626) } },
    { {  INT32_C(  1083001238),  INT32_C(  2033439060), -INT32_C(  1797018310),  INT32_C(  1228146034),  INT32_C(  1469938540),  INT32_C(  1035805188),  INT32_C(  1550165375), -INT32_C(  1204653790),
         INT32_C(   251183034), -INT32_C(   880333935),  INT32_C(  1264544729), -INT32_C(   577465488),  INT32_C(   322187534), -INT32_C(   749670061), -INT32_C(  1204832874), -INT32_C(   512728537) },
      { -INT32_C(  1292867295),  INT32_C(  1836939156),  INT32_C(  1404624098),  INT32_C(  2117094511), -INT32_C(   779000707), -INT32_C(   324738731), -INT32_C(  1113271402),  INT32_C(  1470043445),
         INT32_C(   302616446), -INT32_C(   377452794), -INT32_C(   751028125),  INT32_C(    38890629),  INT32_C(   634643152),  INT32_C(  1494316995), -INT32_C(  2145929653),  INT32_C(  1238873803) },
      {  INT32_C(  1083001238), -INT32_C(  1292867295),  INT32_C(  2033439060),  INT32_C(  1836939156),  INT32_C(  1469938540), -INT32_C(   779000707),  INT32_C(  1035805188), -INT32_C(   324738731),
         INT32_C(   251183034),  INT32_C(   302616446), -INT32_C(   880333935), -INT32_C(   377452794),  INT32_C(   322187534),  INT32_C(   634643152), -INT32_C(   749670061),  INT32_C(  1494316995) } },
    { {  INT32_C(  1264312645), -INT32_C(   885728408), -INT32_C(  1717669868), -INT32_C(  1399066660), -INT32_C(  1798148143),  INT32_C(   837739494),  INT32_C(  1689388441),  INT32_C(    11372987),
        -INT32_C(   766834326), -INT32_C(   123830044), -INT32_C(   846119696), -INT32_C(    42390228), -INT32_C(  2104341604), -INT32_C(   927694801),  INT32_C(  1076717189),  INT32_C(  1514199791) },
      { -INT32_C(   936604701), -INT32_C(    54474229),  INT32_C(   868831751),  INT32_C(   456147583), -INT32_C(  1113734514), -INT32_C(   947564222), -INT32_C(  1492667721),  INT32_C(  1879132045),
        -INT32_C(   566743597), -INT32_C(     2426376), -INT32_C(   902651061),  INT32_C(  1961190118),  INT32_C(  1731297829), -INT32_C(  1959807276), -INT32_C(   164481431),  INT32_C(  1365652350) },
      {  INT32_C(  1264312645), -INT32_C(   936604701), -INT32_C(   885728408), -INT32_C(    54474229), -INT32_C(  1798148143), -INT32_C(  1113734514),  INT32_C(   837739494), -INT32_C(   947564222),
        -INT32_C(   766834326), -INT32_C(   566743597), -INT32_C(   123830044), -INT32_C(     2426376), -INT32_C(  2104341604),  INT32_C(  1731297829), -INT32_C(   927694801), -INT32_C(  1959807276) } },
    { {  INT32_C(  1496293217), -INT32_C(   480769384), -INT32_C(  1817343315),  INT32_C(   285709036), -INT32_C(   394708972),  INT32_C(  1484040431),  INT32_C(  1548658398),  INT32_C(  1001239770),
        -INT32_C(   342565549), -INT32_C(  1798378265),  INT32_C(  1646820214),  INT32_C(   578039565),  INT32_C(  1460333928),  INT32_C(  1940881045), -INT32_C(     3080923),  INT32_C(    87719345) },
      {  INT32_C(  1106300506),  INT32_C(   819380154),  INT32_C(  1217592890), -INT32_C(  1788213715), -INT32_C(  1997769485),  INT32_C(   419208179),  INT32_C(  1243073688), -INT32_C(  1538305719),
        -INT32_C(   639287521),  INT32_C(   956939262), -INT32_C(   410936391), -INT32_C(  1786975326),  INT32_C(  1377724767), -INT32_C(  1653990908),  INT32_C(   803701222), -INT32_C(   237816110) },
      {  INT32_C(  1496293217),  INT32_C(  1106300506), -INT32_C(   480769384),  INT32_C(   819380154), -INT32_C(   394708972), -INT32_C(  1997769485),  INT32_C(  1484040431),  INT32_C(   419208179),
        -INT32_C(   342565549), -INT32_C(   639287521), -INT32_C(  1798378265),  INT32_C(   956939262),  INT32_C(  1460333928),  INT32_C(  1377724767),  INT32_C(  1940881045), -INT32_C(  1653990908) } },
    { {  INT32_C(  1959442805),  INT32_C(   783143796),  INT32_C(   286600815),  INT32_C(  2024182041), -INT32_C(     3422982), -INT32_C(   996395554), -INT32_C(  1980464201),  INT32_C(   779863993),
        -INT32_C(   173914752), -INT32_C(  2010951911), -INT32_C(  1768343427), -INT32_C(  1005633591), -INT32_C(   490481148), -INT32_C(   962109681), -INT32_C(  1689216030), -INT32_C(   473314462) },
      {  INT32_C(   702049296),  INT32_C(   967965627), -INT32_C(    53523917), -INT32_C(  1899962742), -INT32_C(   932150344), -INT32_C(   997320734),  INT32_C(   358604466), -INT32_C(  1158141527),
         INT32_C(  1357107349), -INT32_C(    24537653),  INT32_C(  1778014687), -INT32_C(   252200137),  INT32_C(   565733438),  INT32_C(   853886591), -INT32_C(   834190043),  INT32_C(    59260782) },
      {  INT32_C(  1959442805),  INT32_C(   702049296),  INT32_C(   783143796),  INT32_C(   967965627), -INT32_C(     3422982), -INT32_C(   932150344), -INT32_C(   996395554), -INT32_C(   997320734),
        -INT32_C(   173914752),  INT32_C(  1357107349), -INT32_C(  2010951911), -INT32_C(    24537653), -INT32_C(   490481148),  INT32_C(   565733438), -INT32_C(   962109681),  INT32_C(   853886591) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i a = simde_mm512_loadu_epi32(test_vec[i].a);
    simde__m512i b = simde_mm512_loadu_epi32(test_vec[i].b);
    simde__m512i r = simde_mm512_unpacklo_epi32(a, b);
    simde_test_x86_assert_equal_i32x16(r, simde_mm512_loadu_epi32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m512i a = simde_test_x86_random_i32x16();
    simde__m512i b = simde_test_x86_random_i32x16();
    simde__m512i r = simde_mm512_unpacklo_epi32(a, b);

    simde_test_x86_write_i32x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_unpacklo_epi64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int64_t a[8];
    const int64_t b[8];
    const int64_t r[8];
  } test_vec[] = {
    { { -INT64_C( 6002809510681852398),  INT64_C( 6619903918603655951), -INT64_C( 1585760270896312428),  INT64_C( 8881391389819926934),
        -INT64_C( 8860249017299191343), -INT64_C( 3146980120526282387),  INT64_C( 8455022176348119293), -INT64_C( 6979580178279447745) },
      {  INT64_C(  234476995302228806), -INT64_C( 4702515845455474008), -INT64_C( 8627910307136994066),  INT64_C( 6967722944951782981),
         INT64_C( 6876819293608914903), -INT64_C( 6346129631493002640), -INT64_C( 2244278487047923448),  INT64_C( 3873558979287386950) },
      { -INT64_C( 6002809510681852398),  INT64_C(  234476995302228806), -INT64_C( 1585760270896312428), -INT64_C( 8627910307136994066),
        -INT64_C( 8860249017299191343),  INT64_C( 6876819293608914903),  INT64_C( 8455022176348119293), -INT64_C( 2244278487047923448) } },
    { { -INT64_C( 6095321675390067372), -INT64_C( 4693653831985352324),  INT64_C( 5719547378291200484),  INT64_C( 5443006931745657589),
        -INT64_C( 5100960731892470962), -INT64_C( 4547568151836094096), -INT64_C( 3209484482486734052), -INT64_C( 2003343622545136144) },
      { -INT64_C( 5272971592716089380), -INT64_C( 6390115790093500235),  INT64_C( 2189946987079307443),  INT64_C( 1864832460068850790),
        -INT64_C( 6216086844355686465),  INT64_C(  790536041256360134),  INT64_C( 7811775055689139228),  INT64_C( 7341512422771486604) },
      { -INT64_C( 6095321675390067372), -INT64_C( 5272971592716089380),  INT64_C( 5719547378291200484),  INT64_C( 2189946987079307443),
        -INT64_C( 5100960731892470962), -INT64_C( 6216086844355686465), -INT64_C( 3209484482486734052),  INT64_C( 7811775055689139228) } },
    { { -INT64_C( 2218542767143184999),  INT64_C( 1810775787372179647),  INT64_C( 5215676054909533422), -INT64_C( 5960245736278734276),
        -INT64_C( 7420400728810015991),  INT64_C( 5834080585566402529),  INT64_C( 7247036342855817869), -INT64_C( 6831520175032392593) },
      { -INT64_C( 4776124733533557949), -INT64_C( 4128515286999865597),  INT64_C( 1042762113544681963), -INT64_C( 7818035304822882490),
         INT64_C( 1497279823527101998), -INT64_C( 2391923834539646512), -INT64_C( 4047775633983283674),  INT64_C( 6128033668937442345) },
      { -INT64_C( 2218542767143184999), -INT64_C( 4776124733533557949),  INT64_C( 5215676054909533422),  INT64_C( 1042762113544681963),
        -INT64_C( 7420400728810015991),  INT64_C( 1497279823527101998),  INT64_C( 7247036342855817869), -INT64_C( 4047775633983283674) } },
    { { -INT64_C(  751496245358379924),  INT64_C( 6870465774507330439), -INT64_C( 2525402617129711190),  INT64_C( 3159100039265294683),
        -INT64_C( 2002348816406661604), -INT64_C( 6134547004172389307),  INT64_C( 6020971821830373887),  INT64_C( 6867054035675308898) },
      {  INT64_C( 8369050605509014756),  INT64_C( 4086681551510864395), -INT64_C( 5252189656070845232), -INT64_C( 8935664342656290212),
        -INT64_C( 9026083954154496232),  INT64_C( 5682210665558617707), -INT64_C( 7215836156656105776), -INT64_C( 1132592802627406811) },
      { -INT64_C(  751496245358379924),  INT64_C( 8369050605509014756), -INT64_C( 2525402617129711190), -INT64_C( 5252189656070845232),
        -INT64_C( 2002348816406661604), -INT64_C( 9026083954154496232),  INT64_C( 6020971821830373887), -INT64_C( 7215836156656105776) } },
    { {  INT64_C( 6904569033873951960),  INT64_C( 8318111828974722978), -INT64_C( 2414364008487811420), -INT64_C( 3895073881880086488),
        -INT64_C( 4662658149481174538), -INT64_C( 3431655861685039799), -INT64_C( 7679707818446489387), -INT64_C( 1178386220270088469) },
      { -INT64_C( 1185531203556819536), -INT64_C( 8039140033311249294),  INT64_C( 4627319242526434100),  INT64_C(  324753217120161177),
        -INT64_C(  931016413692208002),  INT64_C( 6995780361897832650),  INT64_C( 6393486115537564708),  INT64_C( 1611844018749756934) },
      {  INT64_C( 6904569033873951960), -INT64_C( 1185531203556819536), -INT64_C( 2414364008487811420),  INT64_C( 4627319242526434100),
        -INT64_C( 4662658149481174538), -INT64_C(  931016413692208002), -INT64_C( 7679707818446489387),  INT64_C( 6393486115537564708) } },
    { {  INT64_C( 6285987747634819015), -INT64_C(  878497904575328704),  INT64_C( 1170414781420326951),  INT64_C( 6605594914173167869),
         INT64_C( 8637305089941563385), -INT64_C( 3211151555392390739), -INT64_C(   27594432354591613), -INT64_C( 3815322035629586401) },
      {  INT64_C( 4527576197983482151), -INT64_C( 1196222005196965145),  INT64_C( 3821332965757820678),  INT64_C(  270204832016014370),
         INT64_C( 2771181886073016486),  INT64_C( 6867180575006470129),  INT64_C(  471594707699943743),  INT64_C( 1147496969132471052) },
      {  INT64_C( 6285987747634819015),  INT64_C( 4527576197983482151),  INT64_C( 1170414781420326951),  INT64_C( 3821332965757820678),
         INT64_C( 8637305089941563385),  INT64_C( 2771181886073016486), -INT64_C(   27594432354591613),  INT64_C(  471594707699943743) } },
    { {  INT64_C( 8516231600441544394),  INT64_C( 5234343886797924587), -INT64_C( 8587474448463033110),  INT64_C( 5914737623937699485),
         INT64_C(  191273341403487404), -INT64_C( 8807937393185817997),  INT64_C( 2952996361048580599),  INT64_C( 8632912076956659188) },
      {  INT64_C( 2862406675764619935), -INT64_C( 2096030990372503351),  INT64_C( 6231663992143953096), -INT64_C( 8358503970614629954),
        -INT64_C( 4564683032371156790),  INT64_C( 8704066857795406333),  INT64_C( 3387347323780276298),  INT64_C( 4568823163327665391) },
      {  INT64_C( 8516231600441544394),  INT64_C( 2862406675764619935), -INT64_C( 8587474448463033110),  INT64_C( 6231663992143953096),
         INT64_C(  191273341403487404), -INT64_C( 4564683032371156790),  INT64_C( 2952996361048580599),  INT64_C( 3387347323780276298) } },
    { { -INT64_C( 6622431482642257312), -INT64_C( 7577773341783867986), -INT64_C( 3019305212821986952), -INT64_C( 1527255140741754599),
        -INT64_C( 6913206910057280316),  INT64_C( 7744174802725673879),  INT64_C( 1816196398087191414), -INT64_C( 4272941875689101761) },
      { -INT64_C( 1831770635312827134), -INT64_C( 2434405159497264423),  INT64_C( 4041541934592593148),  INT64_C( 3898909138821955159),
         INT64_C( 7052846511984102058), -INT64_C( 1759106541359814319), -INT64_C( 7339747798056381711), -INT64_C( 8925557377077271112) },
      { -INT64_C( 6622431482642257312), -INT64_C( 1831770635312827134), -INT64_C( 3019305212821986952),  INT64_C( 4041541934592593148),
        -INT64_C( 6913206910057280316),  INT64_C( 7052846511984102058),  INT64_C( 1816196398087191414), -INT64_C( 7339747798056381711) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i a = simde_mm512_loadu_epi64(test_vec[i].a);
    simde__m512i b = simde_mm512_loadu_epi64(test_vec[i].b);
    simde__m512i r = simde_mm512_unpacklo_epi64(a, b);
    simde_test_x86_assert_equal_i64x8(r, simde_mm512_loadu_epi64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m512i a = simde_test_x86_random_i64x8();
    simde__m512i b = simde_test_x86_random_i64x8();
    simde__m512i r = simde_mm512_unpacklo_epi64(a, b);

    simde_test_x86_write_i64x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i64x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_unpacklo_ps (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde_float32 a[16];
    const simde_float32 b[16];
    const simde_float32 r[16];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(  -110.74), SIMDE_FLOAT32_C(   845.79), SIMDE_FLOAT32_C(   510.00), SIMDE_FLOAT32_C(  -294.64),
        SIMDE_FLOAT32_C(   830.20), SIMDE_FLOAT32_C(  -245.45), SIMDE_FLOAT32_C(   636.89), SIMDE_FLOAT32_C(   791.75),
        SIMDE_FLOAT32_C(   440.51), SIMDE_FLOAT32_C(   405.90), SIMDE_FLOAT32_C(   823.90), SIMDE_FLOAT32_C(  -409.80),
        SIMDE_FLOAT32_C(  -291.85), SIMDE_FLOAT32_C(   844.38), SIMDE_FLOAT32_C(   940.18), SIMDE_FLOAT32_C(  -121.06) },
      { SIMDE_FLOAT32_C(    75.24), SIMDE_FLOAT32_C(  -455.45), SIMDE_FLOAT32_C(   169.73), SIMDE_FLOAT32_C(  -241.62),
        SIMDE_FLOAT32_C(  -356.67), SIMDE_FLOAT32_C(   194.66), SIMDE_FLOAT32_C(   -19.84), SIMDE_FLOAT32_C(  -865.15),
        SIMDE_FLOAT32_C(   761.12), SIMDE_FLOAT32_C(  -475.59), SIMDE_FLOAT32_C(  -922.34), SIMDE_FLOAT32_C(   559.98),
        SIMDE_FLOAT32_C(   339.90), SIMDE_FLOAT32_C(  -418.10), SIMDE_FLOAT32_C(   -17.43), SIMDE_FLOAT32_C(  -770.84) },
      { SIMDE_FLOAT32_C(  -110.74), SIMDE_FLOAT32_C(    75.24), SIMDE_FLOAT32_C(   845.79), SIMDE_FLOAT32_C(  -455.45),
        SIMDE_FLOAT32_C(   830.20), SIMDE_FLOAT32_C(  -356.67), SIMDE_FLOAT32_C(  -245.45), SIMDE_FLOAT32_C(   194.66),
        SIMDE_FLOAT32_C(   440.51), SIMDE_FLOAT32_C(   761.12), SIMDE_FLOAT32_C(   405.90), SIMDE_FLOAT32_C(  -475.59),
        SIMDE_FLOAT32_C(  -291.85), SIMDE_FLOAT32_C(   339.90), SIMDE_FLOAT32_C(   844.38), SIMDE_FLOAT32_C(  -418.10) } },
    { { SIMDE_FLOAT32_C(  -572.31), SIMDE_FLOAT32_C(  -507.44), SIMDE_FLOAT32_C(   -65.48), SIMDE_FLOAT32_C(  -742.11),
        SIMDE_FLOAT32_C(   247.11), SIMDE_FLOAT32_C(  -428.60), SIMDE_FLOAT32_C(  -950.36), SIMDE_FLOAT32_C(  -312.37),
        SIMDE_FLOAT32_C(   977.30), SIMDE_FLOAT32_C(   873.54), SIMDE_FLOAT32_C(   277.83), SIMDE_FLOAT32_C(  -314.55),
        SIMDE_FLOAT32_C(   717.91), SIMDE_FLOAT32_C(   218.01), SIMDE_FLOAT32_C(   564.39), SIMDE_FLOAT32_C(  -206.85) },
      { SIMDE_FLOAT32_C(   762.56), SIMDE_FLOAT32_C(  -265.88), SIMDE_FLOAT32_C(   551.53), SIMDE_FLOAT32_C(  -594.11),
        SIMDE_FLOAT32_C(   928.78), SIMDE_FLOAT32_C(  -468.31), SIMDE_FLOAT32_C(  -459.27), SIMDE_FLOAT32_C(   689.89),
        SIMDE_FLOAT32_C(    56.10), SIMDE_FLOAT32_C(  -381.61), SIMDE_FLOAT32_C(   249.87), SIMDE_FLOAT32_C(  -604.00),
        SIMDE_FLOAT32_C(   200.29), SIMDE_FLOAT32_C(  -767.56), SIMDE_FLOAT32_C(  -374.84), SIMDE_FLOAT32_C(   627.98) },
      { SIMDE_FLOAT32_C(  -572.31), SIMDE_FLOAT32_C(   762.56), SIMDE_FLOAT32_C(  -507.44), SIMDE_FLOAT32_C(  -265.88),
        SIMDE_FLOAT32_C(   247.11), SIMDE_FLOAT32_C(   928.78), SIMDE_FLOAT32_C(  -428.60), SIMDE_FLOAT32_C(  -468.31),
        SIMDE_FLOAT32_C(   977.30), SIMDE_FLOAT32_C(    56.10), SIMDE_FLOAT32_C(   873.54), SIMDE_FLOAT32_C(  -381.61),
        SIMDE_FLOAT32_C(   717.91), SIMDE_FLOAT32_C(   200.29), SIMDE_FLOAT32_C(   218.01), SIMDE_FLOAT32_C(  -767.56) } },
    { { SIMDE_FLOAT32_C(  -275.00), SIMDE_FLOAT32_C(   559.68), SIMDE_FLOAT32_C(   885.87), SIMDE_FLOAT32_C(   972.11),
        SIMDE_FLOAT32_C(  -868.92), SIMDE_FLOAT32_C(   935.50), SIMDE_FLOAT32_C(  -340.26), SIMDE_FLOAT32_C(  -891.62),
        SIMDE_FLOAT32_C(   809.04), SIMDE_FLOAT32_C(   937.57), SIMDE_FLOAT32_C(  -206.18), SIMDE_FLOAT32_C(   526.95),
        SIMDE_FLOAT32_C(   155.58), SIMDE_FLOAT32_C(  -641.79), SIMDE_FLOAT32_C(  -679.90), SIMDE_FLOAT32_C(   -81.87) },
      { SIMDE_FLOAT32_C(    92.33), SIMDE_FLOAT32_C(   871.63), SIMDE_FLOAT32_C(   324.02), SIMDE_FLOAT32_C(    21.11),
        SIMDE_FLOAT32_C(  -596.68), SIMDE_FLOAT32_C(   864.76), SIMDE_FLOAT32_C(  -289.00), SIMDE_FLOAT32_C(   459.42),
        SIMDE_FLOAT32_C(  -516.85), SIMDE_FLOAT32_C(   960.87), SIMDE_FLOAT32_C(   855.42), SIMDE_FLOAT32_C(   683.44),
        SIMDE_FLOAT32_C(  -806.69), SIMDE_FLOAT32_C(  -519.42), SIMDE_FLOAT32_C(   311.43), SIMDE_FLOAT32_C(   -81.69) },
      { SIMDE_FLOAT32_C(  -275.00), SIMDE_FLOAT32_C(    92.33), SIMDE_FLOAT32_C(   559.68), SIMDE_FLOAT32_C(   871.63),
        SIMDE_FLOAT32_C(  -868.92), SIMDE_FLOAT32_C(  -596.68), SIMDE_FLOAT32_C(   935.50), SIMDE_FLOAT32_C(   864.76),
        SIMDE_FLOAT32_C(   809.04), SIMDE_FLOAT32_C(  -516.85), SIMDE_FLOAT32_C(   937.57), SIMDE_FLOAT32_C(   960.87),
        SIMDE_FLOAT32_C(   155.58), SIMDE_FLOAT32_C(  -806.69), SIMDE_FLOAT32_C(  -641.79), SIMDE_FLOAT32_C(  -519.42) } },
    { { SIMDE_FLOAT32_C(  -959.74), SIMDE_FLOAT32_C(   197.29), SIMDE_FLOAT32_C(  -109.58), SIMDE_FLOAT32_C(  -828.66),
        SIMDE_FLOAT32_C(   132.80), SIMDE_FLOAT32_C(   550.17), SIMDE_FLOAT32_C(  -720.28), SIMDE_FLOAT32_C(   -58.16),
        SIMDE_FLOAT32_C(   487.74), SIMDE_FLOAT32_C(    73.54), SIMDE_FLOAT32_C(  -531.21), SIMDE_FLOAT32_C(  -356.68),
        SIMDE_FLOAT32_C(   431.75), SIMDE_FLOAT32_C(  -211.11), SIMDE_FLOAT32_C(   561.45), SIMDE_FLOAT32_C(  -475.92) },
      { SIMDE_FLOAT32_C(  -339.48), SIMDE_FLOAT32_C(  -114.53), SIMDE_FLOAT32_C(   545.19), SIMDE_FLOAT32_C(    63.84),
        SIMDE_FLOAT32_C(  -249.77), SIMDE_FLOAT32_C(  -743.81), SIMDE_FLOAT32_C(  -476.74), SIMDE_FLOAT32_C(   233.38),
        SIMDE_FLOAT32_C(  -782.94), SIMDE_FLOAT32_C(  -621.32), SIMDE_FLOAT32_C(   -83.17), SIMDE_FLOAT32_C(  -589.63),
        SIMDE_FLOAT32_C(  -140.74), SIMDE_FLOAT32_C(  -771.75), SIMDE_FLOAT32_C(   328.67), SIMDE_FLOAT32_C(  -100.48) },
      { SIMDE_FLOAT32_C(  -959.74), SIMDE_FLOAT32_C(  -339.48), SIMDE_FLOAT32_C(   197.29), SIMDE_FLOAT32_C(  -114.53),
        SIMDE_FLOAT32_C(   132.80), SIMDE_FLOAT32_C(  -249.77), SIMDE_FLOAT32_C(   550.17), SIMDE_FLOAT32_C(  -743.81),
        SIMDE_FLOAT32_C(   487.74), SIMDE_FLOAT32_C(  -782.94), SIMDE_FLOAT32_C(    73.54), SIMDE_FLOAT32_C(  -621.32),
        SIMDE_FLOAT32_C(   431.75), SIMDE_FLOAT32_C(  -140.74), SIMDE_FLOAT32_C(  -211.11), SIMDE_FLOAT32_C(  -771.75) } },
    { { SIMDE_FLOAT32_C(   425.54), SIMDE_FLOAT32_C(  -780.90), SIMDE_FLOAT32_C(    70.85), SIMDE_FLOAT32_C(  -441.66),
        SIMDE_FLOAT32_C(   769.26), SIMDE_FLOAT32_C(   350.57), SIMDE_FLOAT32_C(   500.18), SIMDE_FLOAT32_C(   257.00),
        SIMDE_FLOAT32_C(  -575.89), SIMDE_FLOAT32_C(   968.96), SIMDE_FLOAT32_C(   900.32), SIMDE_FLOAT32_C(   855.86),
        SIMDE_FLOAT32_C(  -242.15), SIMDE_FLOAT32_C(   461.77), SIMDE_FLOAT32_C(  -620.06), SIMDE_FLOAT32_C(   418.37) },
      { SIMDE_FLOAT32_C(  -652.76), SIMDE_FLOAT32_C(   925.13), SIMDE_FLOAT32_C(  -517.80), SIMDE_FLOAT32_C(    97.47),
        SIMDE_FLOAT32_C(  -818.68), SIMDE_FLOAT32_C(     5.46), SIMDE_FLOAT32_C(  -669.15), SIMDE_FLOAT32_C(  -601.62),
        SIMDE_FLOAT32_C(   384.13), SIMDE_FLOAT32_C(   247.67), SIMDE_FLOAT32_C(  -191.25), SIMDE_FLOAT32_C(  -756.61),
        SIMDE_FLOAT32_C(   475.92), SIMDE_FLOAT32_C(  -862.58), SIMDE_FLOAT32_C(   142.91), SIMDE_FLOAT32_C(   -98.53) },
      { SIMDE_FLOAT32_C(   425.54), SIMDE_FLOAT32_C(  -652.76), SIMDE_FLOAT32_C(  -780.90), SIMDE_FLOAT32_C(   925.13),
        SIMDE_FLOAT32_C(   769.26), SIMDE_FLOAT32_C(  -818.68), SIMDE_FLOAT32_C(   350.57), SIMDE_FLOAT32_C(     5.46),
        SIMDE_FLOAT32_C(  -575.89), SIMDE_FLOAT32_C(   384.13), SIMDE_FLOAT32_C(   968.96), SIMDE_FLOAT32_C(   247.67),
        SIMDE_FLOAT32_C(  -242.15), SIMDE_FLOAT32_C(   475.92), SIMDE_FLOAT32_C(   461.77), SIMDE_FLOAT32_C(  -862.58) } },
    { { SIMDE_FLOAT32_C(  -643.48), SIMDE_FLOAT32_C(  -786.24), SIMDE_FLOAT32_C(   459.81), SIMDE_FLOAT32_C(  -874.22),
        SIMDE_FLOAT32_C(   564.33), SIMDE_FLOAT32_C(   -40.02), SIMDE_FLOAT32_C(   382.79), SIMDE_FLOAT32_C(   988.43),
        SIMDE_FLOAT32_C(   -71.05), SIMDE_FLOAT32_C(   283.10), SIMDE_FLOAT32_C(   844.30), SIMDE_FLOAT32_C(   686.79),
        SIMDE_FLOAT32_C(  -255.13), SIMDE_FLOAT32_C(  -775.76), SIMDE_FLOAT32_C(   105.16), SIMDE_FLOAT32_C(    92.11) },
      { SIMDE_FLOAT32_C(  -850.63), SIMDE_FLOAT32_C(   587.36), SIMDE_FLOAT32_C(  -810.42), SIMDE_FLOAT32_C(  -669.31),
        SIMDE_FLOAT32_C(  -407.18), SIMDE_FLOAT32_C(  -479.58), SIMDE_FLOAT32_C(  -270.93), SIMDE_FLOAT32_C(   976.95),
        SIMDE_FLOAT32_C(   768.10), SIMDE_FLOAT32_C(   537.82), SIMDE_FLOAT32_C(  -779.65), SIMDE_FLOAT32_C(   244.02),
        SIMDE_FLOAT32_C(   675.24), SIMDE_FLOAT32_C(   363.25), SIMDE_FLOAT32_C(  -854.51), SIMDE_FLOAT32_C(  -968.24) },
      { SIMDE_FLOAT32_C(  -643.48), SIMDE_FLOAT32_C(  -850.63), SIMDE_FLOAT32_C(  -786.24), SIMDE_FLOAT32_C(   587.36),
        SIMDE_FLOAT32_C(   564.33), SIMDE_FLOAT32_C(  -407.18), SIMDE_FLOAT32_C(   -40.02), SIMDE_FLOAT32_C(  -479.58),
        SIMDE_FLOAT32_C(   -71.05), SIMDE_FLOAT32_C(   768.10), SIMDE_FLOAT32_C(   283.10), SIMDE_FLOAT32_C(   537.82),
        SIMDE_FLOAT32_C(  -255.13), SIMDE_FLOAT32_C(   675.24), SIMDE_FLOAT32_C(  -775.76), SIMDE_FLOAT32_C(   363.25) } },
    { { SIMDE_FLOAT32_C(   577.01), SIMDE_FLOAT32_C(   605.30), SIMDE_FLOAT32_C(  -842.45), SIMDE_FLOAT32_C(   141.34),
        SIMDE_FLOAT32_C(  -434.72), SIMDE_FLOAT32_C(   540.33), SIMDE_FLOAT32_C(   129.77), SIMDE_FLOAT32_C(   494.23),
        SIMDE_FLOAT32_C(  -176.56), SIMDE_FLOAT32_C(   -25.93), SIMDE_FLOAT32_C(   181.03), SIMDE_FLOAT32_C(   568.31),
        SIMDE_FLOAT32_C(   198.31), SIMDE_FLOAT32_C(  -713.81), SIMDE_FLOAT32_C(  -339.59), SIMDE_FLOAT32_C(   347.68) },
      { SIMDE_FLOAT32_C(   873.55), SIMDE_FLOAT32_C(  -150.01), SIMDE_FLOAT32_C(   678.36), SIMDE_FLOAT32_C(  -533.63),
        SIMDE_FLOAT32_C(   370.41), SIMDE_FLOAT32_C(  -592.56), SIMDE_FLOAT32_C(  -556.68), SIMDE_FLOAT32_C(   138.51),
        SIMDE_FLOAT32_C(   945.25), SIMDE_FLOAT32_C(  -336.33), SIMDE_FLOAT32_C(  -617.46), SIMDE_FLOAT32_C(   620.50),
        SIMDE_FLOAT32_C(  -973.08), SIMDE_FLOAT32_C(  -471.97), SIMDE_FLOAT32_C(   652.26), SIMDE_FLOAT32_C(   603.93) },
      { SIMDE_FLOAT32_C(   577.01), SIMDE_FLOAT32_C(   873.55), SIMDE_FLOAT32_C(   605.30), SIMDE_FLOAT32_C(  -150.01),
        SIMDE_FLOAT32_C(  -434.72), SIMDE_FLOAT32_C(   370.41), SIMDE_FLOAT32_C(   540.33), SIMDE_FLOAT32_C(  -592.56),
        SIMDE_FLOAT32_C(  -176.56), SIMDE_FLOAT32_C(   945.25), SIMDE_FLOAT32_C(   -25.93), SIMDE_FLOAT32_C(  -336.33),
        SIMDE_FLOAT32_C(   198.31), SIMDE_FLOAT32_C(  -973.08), SIMDE_FLOAT32_C(  -713.81), SIMDE_FLOAT32_C(  -471.97) } },
    { { SIMDE_FLOAT32_C(  -866.67), SIMDE_FLOAT32_C(   809.81), SIMDE_FLOAT32_C(  -254.73), SIMDE_FLOAT32_C(  -301.39),
        SIMDE_FLOAT32_C(   350.14), SIMDE_FLOAT32_C(   875.05), SIMDE_FLOAT32_C(  -807.16), SIMDE_FLOAT32_C(  -826.42),
        SIMDE_FLOAT32_C(  -150.88), SIMDE_FLOAT32_C(   373.87), SIMDE_FLOAT32_C(   741.88), SIMDE_FLOAT32_C(  -952.58),
        SIMDE_FLOAT32_C(   660.05), SIMDE_FLOAT32_C(  -597.70), SIMDE_FLOAT32_C(   395.10), SIMDE_FLOAT32_C(   533.60) },
      { SIMDE_FLOAT32_C(   252.29), SIMDE_FLOAT32_C(    73.46), SIMDE_FLOAT32_C(   999.97), SIMDE_FLOAT32_C(  -377.30),
        SIMDE_FLOAT32_C(   480.90), SIMDE_FLOAT32_C(  -556.71), SIMDE_FLOAT32_C(   761.22), SIMDE_FLOAT32_C(   426.15),
        SIMDE_FLOAT32_C(   106.96), SIMDE_FLOAT32_C(  -856.25), SIMDE_FLOAT32_C(    46.65), SIMDE_FLOAT32_C(   133.89),
        SIMDE_FLOAT32_C(  -328.22), SIMDE_FLOAT32_C(  -301.09), SIMDE_FLOAT32_C(  -262.18), SIMDE_FLOAT32_C(  -194.89) },
      { SIMDE_FLOAT32_C(  -866.67), SIMDE_FLOAT32_C(   252.29), SIMDE_FLOAT32_C(   809.81), SIMDE_FLOAT32_C(    73.46),
        SIMDE_FLOAT32_C(   350.14), SIMDE_FLOAT32_C(   480.90), SIMDE_FLOAT32_C(   875.05), SIMDE_FLOAT32_C(  -556.71),
        SIMDE_FLOAT32_C(  -150.88), SIMDE_FLOAT32_C(   106.96), SIMDE_FLOAT32_C(   373.87), SIMDE_FLOAT32_C(  -856.25),
        SIMDE_FLOAT32_C(   660.05), SIMDE_FLOAT32_C(  -328.22), SIMDE_FLOAT32_C(  -597.70), SIMDE_FLOAT32_C(  -301.09) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512 a = simde_mm512_loadu_ps(test_vec[i].a);
    simde__m512 b = simde_mm512_loadu_ps(test_vec[i].b);
    simde__m512 r = simde_mm512_unpacklo_ps(a, b);
    simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m512 a = simde_test_x86_random_f32x16(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
    simde__m512 b = simde_test_x86_random_f32x16(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
    simde__m512 r = simde_mm512_unpacklo_ps(a, b);

    simde_test_x86_write_f32x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f32x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_unpacklo_pd (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde_float64 a[8];
    const simde_float64 b[8];
    const simde_float64 r[8];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(   985.71), SIMDE_FLOAT64_C(  -483.95), SIMDE_FLOAT64_C(   896.12), SIMDE_FLOAT64_C(   377.14),
        SIMDE_FLOAT64_C(   847.20), SIMDE_FLOAT64_C(   599.54), SIMDE_FLOAT64_C(   511.27), SIMDE_FLOAT64_C(   382.16) },
      { SIMDE_FLOAT64_C(  -737.78), SIMDE_FLOAT64_C(   102.64), SIMDE_FLOAT64_C(   -75.22), SIMDE_FLOAT64_C(   362.17),
        SIMDE_FLOAT64_C(  -315.00), SIMDE_FLOAT64_C(   -69.76), SIMDE_FLOAT64_C(  -947.88), SIMDE_FLOAT64_C(    55.96) },
      { SIMDE_FLOAT64_C(   985.71), SIMDE_FLOAT64_C(  -737.78), SIMDE_FLOAT64_C(   896.12), SIMDE_FLOAT64_C(   -75.22),
        SIMDE_FLOAT64_C(   847.20), SIMDE_FLOAT64_C(  -315.00), SIMDE_FLOAT64_C(   511.27), SIMDE_FLOAT64_C(  -947.88) } },
    { { SIMDE_FLOAT64_C(   832.67), SIMDE_FLOAT64_C(   309.98), SIMDE_FLOAT64_C(   287.40), SIMDE_FLOAT64_C(    76.34),
        SIMDE_FLOAT64_C(  -560.85), SIMDE_FLOAT64_C(   802.02), SIMDE_FLOAT64_C(    93.57), SIMDE_FLOAT64_C(   668.73) },
      { SIMDE_FLOAT64_C(   -98.92), SIMDE_FLOAT64_C(  -978.50), SIMDE_FLOAT64_C(  -913.74), SIMDE_FLOAT64_C(   429.26),
        SIMDE_FLOAT64_C(   134.32), SIMDE_FLOAT64_C(  -232.63), SIMDE_FLOAT64_C(  -953.60), SIMDE_FLOAT64_C(   120.04) },
      { SIMDE_FLOAT64_C(   832.67), SIMDE_FLOAT64_C(   -98.92), SIMDE_FLOAT64_C(   287.40), SIMDE_FLOAT64_C(  -913.74),
        SIMDE_FLOAT64_C(  -560.85), SIMDE_FLOAT64_C(   134.32), SIMDE_FLOAT64_C(    93.57), SIMDE_FLOAT64_C(  -953.60) } },
    { { SIMDE_FLOAT64_C(   283.42), SIMDE_FLOAT64_C(   942.52), SIMDE_FLOAT64_C(  -502.83), SIMDE_FLOAT64_C(   130.62),
        SIMDE_FLOAT64_C(   542.06), SIMDE_FLOAT64_C(  -991.56), SIMDE_FLOAT64_C(  -487.22), SIMDE_FLOAT64_C(   804.27) },
      { SIMDE_FLOAT64_C(   111.08), SIMDE_FLOAT64_C(   437.56), SIMDE_FLOAT64_C(   166.45), SIMDE_FLOAT64_C(   796.08),
        SIMDE_FLOAT64_C(  -632.20), SIMDE_FLOAT64_C(   218.57), SIMDE_FLOAT64_C(  -147.96), SIMDE_FLOAT64_C(  -799.53) },
      { SIMDE_FLOAT64_C(   283.42), SIMDE_FLOAT64_C(   111.08), SIMDE_FLOAT64_C(  -502.83), SIMDE_FLOAT64_C(   166.45),
        SIMDE_FLOAT64_C(   542.06), SIMDE_FLOAT64_C(  -632.20), SIMDE_FLOAT64_C(  -487.22), SIMDE_FLOAT64_C(  -147.96) } },
    { { SIMDE_FLOAT64_C(  -471.45), SIMDE_FLOAT64_C(  -860.56), SIMDE_FLOAT64_C(   276.81), SIMDE_FLOAT64_C(   -32.31),
        SIMDE_FLOAT64_C(   941.46), SIMDE_FLOAT64_C(  -629.61), SIMDE_FLOAT64_C(  -363.58), SIMDE_FLOAT64_C(  -157.46) },
      { SIMDE_FLOAT64_C(  -608.11), SIMDE_FLOAT64_C(  -277.32), SIMDE_FLOAT64_C(  -728.20), SIMDE_FLOAT64_C(   526.21),
        SIMDE_FLOAT64_C(   490.05), SIMDE_FLOAT64_C(  -681.81), SIMDE_FLOAT64_C(  -353.76), SIMDE_FLOAT64_C(  -226.53) },
      { SIMDE_FLOAT64_C(  -471.45), SIMDE_FLOAT64_C(  -608.11), SIMDE_FLOAT64_C(   276.81), SIMDE_FLOAT64_C(  -728.20),
        SIMDE_FLOAT64_C(   941.46), SIMDE_FLOAT64_C(   490.05), SIMDE_FLOAT64_C(  -363.58), SIMDE_FLOAT64_C(  -353.76) } },
    { { SIMDE_FLOAT64_C(  -739.29), SIMDE_FLOAT64_C(   143.42), SIMDE_FLOAT64_C(   904.10), SIMDE_FLOAT64_C(   802.77),
        SIMDE_FLOAT64_C(   151.86), SIMDE_FLOAT64_C(  -583.12), SIMDE_FLOAT64_C(   607.04), SIMDE_FLOAT64_C(  -737.06) },
      { SIMDE_FLOAT64_C(   854.44), SIMDE_FLOAT64_C(  -226.51), SIMDE_FLOAT64_C(  -940.98), SIMDE_FLOAT64_C(  -777.76),
        SIMDE_FLOAT64_C(   992.06), SIMDE_FLOAT64_C(   -88.94), SIMDE_FLOAT64_C(  -577.29), SIMDE_FLOAT64_C(  -479.39) },
      { SIMDE_FLOAT64_C(  -739.29), SIMDE_FLOAT64_C(   854.44), SIMDE_FLOAT64_C(   904.10), SIMDE_FLOAT64_C(  -940.98),
        SIMDE_FLOAT64_C(   151.86), SIMDE_FLOAT64_C(   992.06), SIMDE_FLOAT64_C(   607.04), SIMDE_FLOAT64_C(  -577.29) } },
    { { SIMDE_FLOAT64_C(    50.50), SIMDE_FLOAT64_C(   699.52), SIMDE_FLOAT64_C(   488.30), SIMDE_FLOAT64_C(    -8.05),
        SIMDE_FLOAT64_C(  -930.09), SIMDE_FLOAT64_C(  -875.28), SIMDE_FLOAT64_C(   834.49), SIMDE_FLOAT64_C(  -538.20) },
      { SIMDE_FLOAT64_C(  -152.60), SIMDE_FLOAT64_C(  -893.71), SIMDE_FLOAT64_C(   988.00), SIMDE_FLOAT64_C(  -662.55),
        SIMDE_FLOAT64_C(  -575.52), SIMDE_FLOAT64_C(  -365.75), SIMDE_FLOAT64_C(   110.93), SIMDE_FLOAT64_C(  -314.80) },
      { SIMDE_FLOAT64_C(    50.50), SIMDE_FLOAT64_C(  -152.60), SIMDE_FLOAT64_C(   488.30), SIMDE_FLOAT64_C(   988.00),
        SIMDE_FLOAT64_C(  -930.09), SIMDE_FLOAT64_C(  -575.52), SIMDE_FLOAT64_C(   834.49), SIMDE_FLOAT64_C(   110.93) } },
    { { SIMDE_FLOAT64_C(   777.66), SIMDE_FLOAT64_C(    15.02), SIMDE_FLOAT64_C(  -512.04), SIMDE_FLOAT64_C(   -70.48),
        SIMDE_FLOAT64_C(   431.90), SIMDE_FLOAT64_C(  -905.00), SIMDE_FLOAT64_C(   192.46), SIMDE_FLOAT64_C(   286.34) },
      { SIMDE_FLOAT64_C(  -131.51), SIMDE_FLOAT64_C(   251.48), SIMDE_FLOAT64_C(   508.58), SIMDE_FLOAT64_C(  -139.45),
        SIMDE_FLOAT64_C(  -837.46), SIMDE_FLOAT64_C(   931.29), SIMDE_FLOAT64_C(   381.15), SIMDE_FLOAT64_C(   213.04) },
      { SIMDE_FLOAT64_C(   777.66), SIMDE_FLOAT64_C(  -131.51), SIMDE_FLOAT64_C(  -512.04), SIMDE_FLOAT64_C(   508.58),
        SIMDE_FLOAT64_C(   431.90), SIMDE_FLOAT64_C(  -837.46), SIMDE_FLOAT64_C(   192.46), SIMDE_FLOAT64_C(   381.15) } },
    { { SIMDE_FLOAT64_C(   630.81), SIMDE_FLOAT64_C(  -130.55), SIMDE_FLOAT64_C(  -795.01), SIMDE_FLOAT64_C(   700.72),
        SIMDE_FLOAT64_C(    -5.82), SIMDE_FLOAT64_C(  -960.51), SIMDE_FLOAT64_C(  -837.48), SIMDE_FLOAT64_C(   841.58) },
      { SIMDE_FLOAT64_C(  -854.22), SIMDE_FLOAT64_C(  -849.48), SIMDE_FLOAT64_C(  -820.97), SIMDE_FLOAT64_C(  -429.74),
        SIMDE_FLOAT64_C(  -215.23), SIMDE_FLOAT64_C(   289.96), SIMDE_FLOAT64_C(   255.45), SIMDE_FLOAT64_C(  -437.57) },
      { SIMDE_FLOAT64_C(   630.81), SIMDE_FLOAT64_C(  -854.22), SIMDE_FLOAT64_C(  -795.01), SIMDE_FLOAT64_C(  -820.97),
        SIMDE_FLOAT64_C(    -5.82), SIMDE_FLOAT64_C(  -215.23), SIMDE_FLOAT64_C(  -837.48), SIMDE_FLOAT64_C(   255.45) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512d a = simde_mm512_loadu_pd(test_vec[i].a);
    simde__m512d b = simde_mm512_loadu_pd(test_vec[i].b);
    simde__m512d r = simde_mm512_unpacklo_pd(a, b);
    simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m512d a = simde_test_x86_random_f64x8(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde__m512d b = simde_test_x86_random_f64x8(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde__m512d r = simde_mm512_unpacklo_pd(a, b);

    simde_test_x86_write_f64x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f64x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_unpacklo_epi8)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_unpacklo_epi16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_unpacklo_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_unpacklo_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_unpacklo_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_unpacklo_pd)
SIMDE_TEST_FUNC_LIST_END

#include <test/x86/avx512/test-avx512-footer.h>
