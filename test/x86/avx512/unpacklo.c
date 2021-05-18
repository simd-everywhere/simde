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
test_simde_mm512_mask_unpacklo_epi8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int8_t src[64];
    const simde__mmask64 k;
    const int8_t a[64];
    const int8_t b[64];
    const int8_t r[64];
  } test_vec[] = {
    { {  INT8_C(  60),  INT8_C( 106), -INT8_C( 102),  INT8_C(  87),  INT8_C( 115),  INT8_C(  79),  INT8_C(  15), -INT8_C(  42),
         INT8_C(  47), -INT8_C(   2), -INT8_C(  34),  INT8_C(   0), -INT8_C( 114),  INT8_C(  38),  INT8_C(  88), -INT8_C(   5),
         INT8_C(  82), -INT8_C(  79),  INT8_C( 107), -INT8_C( 116), -INT8_C(  92), -INT8_C(  41), -INT8_C(  20), -INT8_C(  38),
         INT8_C(  33), -INT8_C(  25),  INT8_C( 116),  INT8_C(  99),  INT8_C(  54),  INT8_C( 106),  INT8_C(  78),  INT8_C( 114),
        -INT8_C(  44), -INT8_C(  23), -INT8_C(  55),  INT8_C(  71),  INT8_C(  56), -INT8_C(  40),  INT8_C(  30),  INT8_C( 103),
        -INT8_C(  42), -INT8_C(   4),  INT8_C( 104),  INT8_C( 100),  INT8_C(  34), -INT8_C(  64),  INT8_C(  96),  INT8_C( 117),
         INT8_C( 113), -INT8_C(  53),  INT8_C(   1),  INT8_C(  21), -INT8_C(  94), -INT8_C(  19), -INT8_C(  16), -INT8_C(  61),
        -INT8_C(  44),  INT8_C( 100),  INT8_C(  39),  INT8_C(  10), -INT8_C(  50),  INT8_C( 117),  INT8_C( 124), -INT8_C(  94) },
      UINT64_C(17581497818985088350),
      {  INT8_C(   3),  INT8_C( 102),  INT8_C(  88),  INT8_C(  38),  INT8_C(  39), -INT8_C(  72), -INT8_C( 101), -INT8_C( 104),
        -INT8_C( 125), -INT8_C( 100), -INT8_C(  82),  INT8_C(  37), -INT8_C( 119), -INT8_C(  98), -INT8_C(  24),  INT8_C(  93),
         INT8_C(   2),  INT8_C(  15),  INT8_C( 103), -INT8_C(  48), -INT8_C( 123), -INT8_C(  29),  INT8_C( 114), -INT8_C(  29),
         INT8_C(  40),  INT8_C(  91),  INT8_C( 122),  INT8_C(  69),  INT8_C(  99),  INT8_C( 121),  INT8_C(  56),  INT8_C( 102),
        -INT8_C(  33), -INT8_C( 112), -INT8_C( 116),  INT8_C(   6),  INT8_C(  72),  INT8_C(  39), -INT8_C(  97), -INT8_C(  53),
        -INT8_C(  61),  INT8_C(  77), -INT8_C(  16),  INT8_C(  76), -INT8_C(  21), -INT8_C(  39), -INT8_C(  87), -INT8_C(  19),
        -INT8_C(  24),  INT8_C(  16), -INT8_C(  67),  INT8_C( 109), -INT8_C(  13),  INT8_C(  47),  INT8_C(  81),  INT8_C(  27),
        -INT8_C( 118), -INT8_C(  53),  INT8_C(  96), -INT8_C(  19),  INT8_C(  68), -INT8_C( 103),  INT8_C(  84),  INT8_C(  36) },
      {  INT8_C(  41), -INT8_C(  32),  INT8_C(  42),  INT8_C( 114),  INT8_C(   8), -INT8_C(  55),  INT8_C(  61), -INT8_C(  53),
         INT8_C(  22),  INT8_C(  46),  INT8_C(  24),  INT8_C(   1),  INT8_C(   7), -INT8_C(  63), -INT8_C(  18), -INT8_C(  17),
        -INT8_C(  46), -INT8_C(  85),  INT8_C(  93), -INT8_C(  59), -INT8_C(  38), -INT8_C(  82), -INT8_C(  31),  INT8_C( 101),
         INT8_C( 121),  INT8_C(  65),  INT8_C(  82), -INT8_C(  66), -INT8_C(  38), -INT8_C(  90), -INT8_C(  30),  INT8_C(   4),
        -INT8_C( 121),  INT8_C(  12),  INT8_C( 118), -INT8_C( 113), -INT8_C(  42), -INT8_C(  77),  INT8_C(  90), -INT8_C(  20),
        -INT8_C(  31),  INT8_C( 114), -INT8_C(  18), -INT8_C(  24),  INT8_C(  52), -INT8_C(  36), -INT8_C(  40),  INT8_C(   6),
        -INT8_C( 120),  INT8_C(  53), -INT8_C(  53),  INT8_C(  98), -INT8_C(  29), -INT8_C(  84), -INT8_C(  57),  INT8_C(  92),
        -INT8_C(  18),  INT8_C(  26),  INT8_C(  26), -INT8_C(  56), -INT8_C(  64), -INT8_C(   4), -INT8_C(  52),  INT8_C(  71) },
      {  INT8_C(  60),  INT8_C(  41),  INT8_C( 102), -INT8_C(  32),  INT8_C(  88),  INT8_C(  79),  INT8_C(  38), -INT8_C(  42),
         INT8_C(  39), -INT8_C(   2), -INT8_C(  72),  INT8_C(   0), -INT8_C( 114),  INT8_C(  38), -INT8_C( 104), -INT8_C(   5),
         INT8_C(   2), -INT8_C(  79),  INT8_C( 107), -INT8_C(  85), -INT8_C(  92),  INT8_C(  93), -INT8_C(  48), -INT8_C(  59),
        -INT8_C( 123), -INT8_C(  38), -INT8_C(  29),  INT8_C(  99),  INT8_C( 114),  INT8_C( 106),  INT8_C(  78),  INT8_C( 101),
        -INT8_C(  33), -INT8_C(  23), -INT8_C( 112),  INT8_C(  12), -INT8_C( 116), -INT8_C(  40),  INT8_C(  30),  INT8_C( 103),
         INT8_C(  72), -INT8_C(  42),  INT8_C(  39),  INT8_C( 100),  INT8_C(  34), -INT8_C(  64),  INT8_C(  96),  INT8_C( 117),
         INT8_C( 113), -INT8_C( 120),  INT8_C(  16),  INT8_C(  53), -INT8_C(  67), -INT8_C(  53),  INT8_C( 109),  INT8_C(  98),
        -INT8_C(  13), -INT8_C(  29),  INT8_C(  39),  INT8_C(  10),  INT8_C(  81), -INT8_C(  57),  INT8_C(  27),  INT8_C(  92) } },
    { {  INT8_C(   9),  INT8_C(  66), -INT8_C(  42), -INT8_C(  33), -INT8_C(  10),  INT8_C(  49), -INT8_C(  53), -INT8_C(  41),
        -INT8_C(  93), -INT8_C(  71), -INT8_C(  64), -INT8_C(  41), -INT8_C( 106), -INT8_C( 104), -INT8_C(  35),  INT8_C(  30),
        -INT8_C(  51), -INT8_C(  87),      INT8_MIN, -INT8_C(  80),  INT8_C(  85),  INT8_C(  72),  INT8_C(  12),  INT8_C(  67),
         INT8_C(  98),  INT8_C(  39),  INT8_C(  12),  INT8_C(  34),  INT8_C(  35), -INT8_C(  40),  INT8_C( 106),  INT8_C(  44),
         INT8_C(  27),  INT8_C(  64),  INT8_C(  11),  INT8_C(  17),  INT8_C( 113), -INT8_C(  41), -INT8_C(  24),  INT8_C(  21),
        -INT8_C( 112), -INT8_C(  88), -INT8_C(  20),  INT8_C(  38),  INT8_C(  64), -INT8_C(  54),  INT8_C(  68),  INT8_C(  13),
         INT8_C( 115), -INT8_C(  59), -INT8_C(  67), -INT8_C(  56),  INT8_C(  13), -INT8_C(  54),  INT8_C(  12),  INT8_C( 111),
        -INT8_C(  15),  INT8_C(  24), -INT8_C( 111),  INT8_C(  20), -INT8_C(  16), -INT8_C(   5),  INT8_C(  65),  INT8_C(  11) },
      UINT64_C(13024978723095202876),
      { -INT8_C(  83), -INT8_C(  81), -INT8_C(  38), -INT8_C(  18),  INT8_C( 121),  INT8_C(  31), -INT8_C(   5), -INT8_C(  20),
        -INT8_C(  28), -INT8_C(  71), -INT8_C(  76), -INT8_C(  15), -INT8_C( 125), -INT8_C(  64),  INT8_C(  96),  INT8_C( 116),
        -INT8_C(  40), -INT8_C(  15), -INT8_C( 120), -INT8_C(  55), -INT8_C(  19), -INT8_C(  55), -INT8_C(  44),  INT8_C(  41),
         INT8_C(  22), -INT8_C(  15), -INT8_C(  42),  INT8_C(  57), -INT8_C(  10), -INT8_C( 103), -INT8_C(  19), -INT8_C(  93),
         INT8_C(  72), -INT8_C(  56), -INT8_C( 111), -INT8_C(  63), -INT8_C(  25), -INT8_C( 115), -INT8_C(  83), -INT8_C(  53),
         INT8_C(  70),  INT8_C(  97), -INT8_C(  68), -INT8_C(  55),  INT8_C(  34),  INT8_C(  28),  INT8_C(  61), -INT8_C(   6),
         INT8_C(  13), -INT8_C(  59), -INT8_C(  61), -INT8_C(   6), -INT8_C( 113), -INT8_C( 104),  INT8_C(  35), -INT8_C(  91),
        -INT8_C( 119), -INT8_C(   6), -INT8_C(  34),      INT8_MAX, -INT8_C( 109), -INT8_C(  52),  INT8_C(  34), -INT8_C(  37) },
      { -INT8_C( 108), -INT8_C(  76), -INT8_C( 100),  INT8_C( 123),  INT8_C(  65),  INT8_C(  73),  INT8_C(  70), -INT8_C( 121),
        -INT8_C(  86),  INT8_C(   2),  INT8_C(  80), -INT8_C(  52),  INT8_C(  30), -INT8_C( 115), -INT8_C(  57),  INT8_C(  43),
         INT8_C(  82), -INT8_C( 118),  INT8_C(  38), -INT8_C(  31),  INT8_C(  34),  INT8_C(  73), -INT8_C( 122), -INT8_C(  85),
         INT8_C(  67),  INT8_C( 101),  INT8_C(  42), -INT8_C(  42),  INT8_C(  49),  INT8_C(  77), -INT8_C(  79), -INT8_C(  59),
         INT8_C(   1),  INT8_C(  77),  INT8_C(  64),  INT8_C(  66), -INT8_C( 106), -INT8_C( 122), -INT8_C(  55),  INT8_C(  65),
        -INT8_C( 120),  INT8_C(  25),  INT8_C(  13), -INT8_C(  90), -INT8_C(  90), -INT8_C(  44), -INT8_C(  47), -INT8_C(   8),
         INT8_C(  95), -INT8_C(   9), -INT8_C(  38), -INT8_C( 127),  INT8_C(  65),  INT8_C(  96),  INT8_C(  45), -INT8_C( 124),
        -INT8_C(  59),  INT8_C(  87),  INT8_C(  91), -INT8_C(  10), -INT8_C(  92),  INT8_C(  12), -INT8_C(  69), -INT8_C(  91) },
      {  INT8_C(   9),  INT8_C(  66), -INT8_C(  81), -INT8_C(  76), -INT8_C(  38), -INT8_C( 100), -INT8_C(  53), -INT8_C(  41),
        -INT8_C(  93), -INT8_C(  71),  INT8_C(  31),  INT8_C(  73), -INT8_C( 106), -INT8_C( 104), -INT8_C(  20),  INT8_C(  30),
        -INT8_C(  51), -INT8_C(  87), -INT8_C(  15), -INT8_C( 118), -INT8_C( 120),  INT8_C(  72),  INT8_C(  12),  INT8_C(  67),
        -INT8_C(  19),  INT8_C(  39), -INT8_C(  55),  INT8_C(  73),  INT8_C(  35), -INT8_C( 122),  INT8_C( 106), -INT8_C(  85),
         INT8_C(  72),  INT8_C(   1),  INT8_C(  11),  INT8_C(  17),  INT8_C( 113),  INT8_C(  64), -INT8_C(  24),  INT8_C(  21),
        -INT8_C(  25), -INT8_C(  88), -INT8_C( 115),  INT8_C(  38),  INT8_C(  64), -INT8_C(  54),  INT8_C(  68),  INT8_C(  13),
         INT8_C( 115),  INT8_C(  95), -INT8_C(  67), -INT8_C(  56),  INT8_C(  13), -INT8_C(  54), -INT8_C(   6), -INT8_C( 127),
        -INT8_C(  15),  INT8_C(  24), -INT8_C( 104),  INT8_C(  20),  INT8_C(  35),  INT8_C(  45),  INT8_C(  65), -INT8_C( 124) } },
    { {  INT8_C(  90), -INT8_C(   5), -INT8_C(  25), -INT8_C(  16), -INT8_C( 127), -INT8_C(  80),  INT8_C(  49),  INT8_C(   9),
        -INT8_C(  55),  INT8_C(  63), -INT8_C(  81),  INT8_C( 111),  INT8_C(  19), -INT8_C( 127),  INT8_C( 104),  INT8_C( 114),
         INT8_C( 120),  INT8_C(  66), -INT8_C(  12), -INT8_C(  71), -INT8_C(  94),  INT8_C(  33),  INT8_C(  62),  INT8_C( 104),
         INT8_C( 120), -INT8_C( 103),  INT8_C(  94),  INT8_C(  29), -INT8_C(  91),  INT8_C(  26), -INT8_C(  62), -INT8_C(   1),
         INT8_C(  21), -INT8_C(  86), -INT8_C(  16), -INT8_C( 105),  INT8_C(  90),  INT8_C(  33), -INT8_C(  96),  INT8_C(  36),
         INT8_C(  96),  INT8_C(  80), -INT8_C( 109),  INT8_C( 116), -INT8_C(  47), -INT8_C(   5), -INT8_C(  26),  INT8_C(  73),
         INT8_C(  61), -INT8_C(  38),  INT8_C(   3), -INT8_C(  32), -INT8_C(   5),  INT8_C(  65),  INT8_C(  72),  INT8_C( 116),
        -INT8_C(  38), -INT8_C(  90), -INT8_C( 111),      INT8_MAX, -INT8_C(  64),  INT8_C(  83),      INT8_MAX, -INT8_C(  42) },
      UINT64_C(17400797973862772733),
      {  INT8_C(  93),  INT8_C(  15),  INT8_C( 101),  INT8_C(  46),  INT8_C(  11),  INT8_C(  75),  INT8_C( 120),  INT8_C(  72),
         INT8_C(  38),  INT8_C( 123),  INT8_C(  40),  INT8_C(  33), -INT8_C(  68),  INT8_C( 112), -INT8_C( 107), -INT8_C( 106),
         INT8_C(  23),  INT8_C(  38),  INT8_C(  21), -INT8_C(  41),  INT8_C( 122), -INT8_C( 108), -INT8_C(  83),  INT8_C( 119),
         INT8_C(   3),  INT8_C(  26), -INT8_C(  49), -INT8_C( 108),  INT8_C(  40),  INT8_C(  75), -INT8_C( 123), -INT8_C( 123),
         INT8_C(  91), -INT8_C(  22), -INT8_C(  76),  INT8_C( 102),  INT8_C(  53),  INT8_C(  44), -INT8_C(  82),  INT8_C(  91),
        -INT8_C(  89), -INT8_C(  41),  INT8_C( 125),  INT8_C(  99),  INT8_C(  71),  INT8_C(  18), -INT8_C(   7),  INT8_C(  94),
         INT8_C(  57),  INT8_C(  14),  INT8_C(  54), -INT8_C(  77), -INT8_C(  93), -INT8_C(  29),  INT8_C(  42), -INT8_C(  90),
        -INT8_C(   2), -INT8_C(   6),  INT8_C(  58),  INT8_C(  38),  INT8_C(  69), -INT8_C(  65), -INT8_C(  85), -INT8_C(  96) },
      { -INT8_C(  87),  INT8_C(  95),  INT8_C(   6), -INT8_C(  33), -INT8_C( 117), -INT8_C(  75),  INT8_C(  58),  INT8_C(  50),
        -INT8_C( 116), -INT8_C(  73), -INT8_C( 107), -INT8_C(  45), -INT8_C(  54), -INT8_C( 114),  INT8_C(  50),  INT8_C(   3),
        -INT8_C(  99),  INT8_C( 104), -INT8_C(  74),  INT8_C(  64),  INT8_C(  75), -INT8_C(  32), -INT8_C(  26),  INT8_C(  73),
        -INT8_C(  38),  INT8_C(  33),  INT8_C( 111),  INT8_C(  32), -INT8_C(  32),  INT8_C(  27), -INT8_C(  64), -INT8_C( 118),
         INT8_C( 122), -INT8_C(  57),  INT8_C( 105),  INT8_C(   6),  INT8_C( 124), -INT8_C(  93),  INT8_C(  56),  INT8_C(   8),
         INT8_C(  91), -INT8_C(  50), -INT8_C(  37),  INT8_C(  37),  INT8_C(  92),  INT8_C(  13),  INT8_C(  40), -INT8_C(   7),
         INT8_C( 117), -INT8_C(  34),  INT8_C(  57), -INT8_C(  63), -INT8_C(  66),  INT8_C(  32),  INT8_C(  10), -INT8_C( 103),
         INT8_C(  65),  INT8_C( 122), -INT8_C(  71),  INT8_C(  33), -INT8_C( 107),  INT8_C( 121), -INT8_C(  85),  INT8_C(  15) },
      {  INT8_C(  93), -INT8_C(   5),  INT8_C(  15),  INT8_C(  95),  INT8_C( 101),  INT8_C(   6),  INT8_C(  46), -INT8_C(  33),
         INT8_C(  11), -INT8_C( 117),  INT8_C(  75), -INT8_C(  75),  INT8_C(  19),  INT8_C(  58),  INT8_C(  72),  INT8_C( 114),
         INT8_C(  23),  INT8_C(  66),  INT8_C(  38),  INT8_C( 104), -INT8_C(  94), -INT8_C(  74), -INT8_C(  41),  INT8_C( 104),
         INT8_C( 120), -INT8_C( 103),  INT8_C(  94), -INT8_C(  32), -INT8_C(  83),  INT8_C(  26),  INT8_C( 119), -INT8_C(   1),
         INT8_C(  21), -INT8_C(  86), -INT8_C(  16), -INT8_C( 105), -INT8_C(  76),  INT8_C(  33), -INT8_C(  96),  INT8_C(   6),
         INT8_C(  53),  INT8_C(  80),  INT8_C(  44), -INT8_C(  93), -INT8_C(  47), -INT8_C(   5), -INT8_C(  26),  INT8_C(  73),
         INT8_C(  61), -INT8_C(  38),  INT8_C(  14), -INT8_C(  34),  INT8_C(  54),  INT8_C(  57), -INT8_C(  77),  INT8_C( 116),
        -INT8_C(  93), -INT8_C(  90), -INT8_C( 111),      INT8_MAX,  INT8_C(  42),  INT8_C(  10), -INT8_C(  90), -INT8_C( 103) } },
    { {  INT8_C(  64),  INT8_C(  20),  INT8_C(  21), -INT8_C(  68), -INT8_C(  72),  INT8_C(  78), -INT8_C(  60),  INT8_C(  19),
         INT8_C(  28), -INT8_C(  96),  INT8_C(  56),  INT8_C( 120), -INT8_C(  83),  INT8_C(  96),  INT8_C( 114),  INT8_C(  35),
         INT8_C(  62), -INT8_C(  85), -INT8_C(  28), -INT8_C(   4), -INT8_C(  53), -INT8_C(  18), -INT8_C( 107),  INT8_C(  12),
         INT8_C( 104),  INT8_C(  78),  INT8_C(  46), -INT8_C(   3), -INT8_C(  56), -INT8_C(  39),  INT8_C(  13),  INT8_C(   8),
        -INT8_C(  18),  INT8_C(  34), -INT8_C(  59), -INT8_C(  90),  INT8_C( 112), -INT8_C( 119), -INT8_C(  71), -INT8_C( 116),
         INT8_C(  41), -INT8_C(  15),  INT8_C(   5), -INT8_C(  41),  INT8_C(  81),  INT8_C( 119), -INT8_C(   6), -INT8_C( 113),
         INT8_C(  34), -INT8_C(  34), -INT8_C( 117), -INT8_C(  18), -INT8_C(  52),  INT8_C(  33), -INT8_C(   6),  INT8_C(  53),
         INT8_C( 111),  INT8_C(  40),  INT8_C(  50),  INT8_C(  55),  INT8_C(   2),  INT8_C(  63),  INT8_C(  64), -INT8_C(  16) },
      UINT64_C(13285424900603250018),
      {  INT8_C(  64),  INT8_C( 100), -INT8_C( 113), -INT8_C( 111), -INT8_C(  37), -INT8_C( 119),  INT8_C(  32), -INT8_C(   3),
         INT8_C( 103), -INT8_C(  85), -INT8_C(  21),  INT8_C(  51), -INT8_C(  52), -INT8_C(  26),  INT8_C( 104),  INT8_C(  60),
         INT8_C(  14), -INT8_C( 101),  INT8_C( 115),  INT8_C(  16), -INT8_C(  38), -INT8_C(  77),  INT8_C(   0),  INT8_C(  60),
        -INT8_C(  72), -INT8_C( 106),  INT8_C(  15),  INT8_C(  71), -INT8_C(  27),  INT8_C( 110), -INT8_C(   1),  INT8_C(  37),
        -INT8_C(  46), -INT8_C( 114), -INT8_C(  74), -INT8_C(  83),  INT8_C(  23), -INT8_C(  42), -INT8_C(  86),  INT8_C( 126),
        -INT8_C( 126), -INT8_C( 106), -INT8_C(  79),  INT8_C(  78),  INT8_C( 124),  INT8_C(  26), -INT8_C( 118), -INT8_C( 118),
        -INT8_C(  75), -INT8_C(   2), -INT8_C( 101), -INT8_C( 113), -INT8_C(  79), -INT8_C( 101), -INT8_C(  52),  INT8_C( 106),
         INT8_C(  50), -INT8_C(  37), -INT8_C(  79),  INT8_C(  23),  INT8_C(  73), -INT8_C(  80),  INT8_C(  61),  INT8_C(  27) },
      {  INT8_C(  62), -INT8_C(  13), -INT8_C(  56),  INT8_C(  85), -INT8_C(  54),  INT8_C( 114), -INT8_C(  45),  INT8_C(  76),
         INT8_C(   8), -INT8_C( 124), -INT8_C( 102), -INT8_C( 124), -INT8_C(  98),  INT8_C(  37),  INT8_C(  15),  INT8_C(  83),
         INT8_C(  35), -INT8_C(  86), -INT8_C(  29), -INT8_C(  44),  INT8_C(  69), -INT8_C(  81),  INT8_C(  62),  INT8_C( 119),
        -INT8_C( 118), -INT8_C(  17), -INT8_C( 113), -INT8_C(  45), -INT8_C(  97), -INT8_C(  52), -INT8_C(  18), -INT8_C(  35),
        -INT8_C(  65), -INT8_C(  74),  INT8_C(  50), -INT8_C( 119),  INT8_C(  40),  INT8_C(   5), -INT8_C(  43),  INT8_C(  49),
        -INT8_C( 118),  INT8_C( 112), -INT8_C(  75),  INT8_C(  40), -INT8_C( 107), -INT8_C(  60),  INT8_C( 124), -INT8_C(  72),
         INT8_C( 110),  INT8_C(  95), -INT8_C( 116), -INT8_C(  76),  INT8_C(  14), -INT8_C(  53),  INT8_C(  43), -INT8_C( 104),
        -INT8_C(  70), -INT8_C(  70),  INT8_C( 107),  INT8_C(  90), -INT8_C( 122),  INT8_C(  89),  INT8_C(  55),  INT8_C(  70) },
      {  INT8_C(  64),  INT8_C(  62),  INT8_C(  21), -INT8_C(  68), -INT8_C(  72), -INT8_C(  56), -INT8_C( 111),  INT8_C(  19),
        -INT8_C(  37), -INT8_C(  96), -INT8_C( 119),  INT8_C( 120), -INT8_C(  83),  INT8_C(  96),  INT8_C( 114),  INT8_C(  35),
         INT8_C(  62),  INT8_C(  35), -INT8_C( 101), -INT8_C(   4),  INT8_C( 115), -INT8_C(  18), -INT8_C( 107), -INT8_C(  44),
         INT8_C( 104),  INT8_C(  69),  INT8_C(  46), -INT8_C(   3),  INT8_C(   0), -INT8_C(  39),  INT8_C(  60),  INT8_C( 119),
        -INT8_C(  18), -INT8_C(  65), -INT8_C( 114), -INT8_C(  74),  INT8_C( 112), -INT8_C( 119), -INT8_C(  71), -INT8_C( 119),
         INT8_C(  23),  INT8_C(  40), -INT8_C(  42),  INT8_C(   5),  INT8_C(  81),  INT8_C( 119),  INT8_C( 126), -INT8_C( 113),
        -INT8_C(  75),  INT8_C( 110), -INT8_C(   2),  INT8_C(  95), -INT8_C( 101),  INT8_C(  33), -INT8_C( 113),  INT8_C(  53),
         INT8_C( 111),  INT8_C(  40),  INT8_C(  50), -INT8_C(  53), -INT8_C(  52),  INT8_C(  43),  INT8_C(  64), -INT8_C( 104) } },
    { {  INT8_C(  15),  INT8_C( 106), -INT8_C(  49),  INT8_C(  55),  INT8_C( 111), -INT8_C(  91),  INT8_C( 104), -INT8_C(   7),
         INT8_C(  21),  INT8_C(  30),  INT8_C(  34), -INT8_C(  86), -INT8_C(  30), -INT8_C(  98),  INT8_C(  98),  INT8_C(  81),
        -INT8_C(   3), -INT8_C(  18),  INT8_C(   5),  INT8_C(  11), -INT8_C(  71),  INT8_C(  48), -INT8_C(  93),  INT8_C( 116),
        -INT8_C(  21),  INT8_C(  14), -INT8_C(  50),  INT8_C( 113),  INT8_C( 103),  INT8_C(   5), -INT8_C(  73),  INT8_C( 118),
         INT8_C( 111), -INT8_C( 121), -INT8_C(  83), -INT8_C(  33),  INT8_C(  44),  INT8_C(  22), -INT8_C(  40),  INT8_C(  65),
         INT8_C(  52), -INT8_C(   6), -INT8_C(  21),  INT8_C(  22), -INT8_C( 104),  INT8_C(  77),  INT8_C( 103), -INT8_C( 107),
         INT8_C(  59),  INT8_C( 108), -INT8_C(  96), -INT8_C(  11), -INT8_C(  99),  INT8_C(  67),  INT8_C( 105), -INT8_C( 120),
         INT8_C(  81),  INT8_C(  55), -INT8_C(   7), -INT8_C(  72),  INT8_C(  60), -INT8_C(  79),  INT8_C(  46), -INT8_C(  84) },
      UINT64_C( 2784741837318642744),
      {  INT8_C(  94), -INT8_C( 112),  INT8_C(  60), -INT8_C(  10), -INT8_C(  35), -INT8_C(  92), -INT8_C( 116),  INT8_C(  24),
         INT8_C(  16),  INT8_C(  44),  INT8_C(  13), -INT8_C(  83),  INT8_C( 112),  INT8_C( 118),  INT8_C(  53), -INT8_C(  63),
        -INT8_C(  83),  INT8_C(  47),  INT8_C( 122), -INT8_C(  22), -INT8_C(  32), -INT8_C(  88), -INT8_C( 106),  INT8_C(  24),
        -INT8_C( 124),  INT8_C(  33),  INT8_C( 124),  INT8_C( 118), -INT8_C( 124),  INT8_C(  33), -INT8_C( 100), -INT8_C(  30),
        -INT8_C(  79), -INT8_C(  39), -INT8_C(  39), -INT8_C( 114),  INT8_C( 125),  INT8_C( 101), -INT8_C(  90), -INT8_C( 115),
        -INT8_C( 111), -INT8_C(  76),  INT8_C(  59),  INT8_C(   1),  INT8_C(  42),  INT8_C( 112), -INT8_C(  61), -INT8_C(  40),
        -INT8_C(  97),  INT8_C(  61), -INT8_C(  62),      INT8_MAX, -INT8_C(  27),  INT8_C(  88), -INT8_C( 105),  INT8_C( 106),
         INT8_C( 121),  INT8_C(  19), -INT8_C(  32), -INT8_C(   3),  INT8_C(  52),  INT8_C( 125), -INT8_C(  32), -INT8_C(  27) },
      {  INT8_C(  86), -INT8_C(  71),  INT8_C( 115), -INT8_C(  45),  INT8_C(  30),  INT8_C(  26),  INT8_C(  96), -INT8_C(  81),
        -INT8_C(  50), -INT8_C( 101), -INT8_C(  79), -INT8_C(   8),  INT8_C(  12),  INT8_C( 116), -INT8_C(  48), -INT8_C(  85),
        -INT8_C(  79), -INT8_C( 110),  INT8_C(  43), -INT8_C( 106), -INT8_C(  22), -INT8_C(  62),  INT8_C(   0),  INT8_C(  99),
        -INT8_C(  42), -INT8_C(  31),  INT8_C(  97),  INT8_C(  10),  INT8_C(  94),  INT8_C(  65), -INT8_C(  16), -INT8_C(  76),
        -INT8_C(   6),  INT8_C(  99), -INT8_C( 121),  INT8_C(  24),  INT8_C( 125), -INT8_C(  25), -INT8_C(  57),  INT8_C(  75),
        -INT8_C( 125),  INT8_C( 120),  INT8_C(  68), -INT8_C( 113), -INT8_C(  20),  INT8_C(  20),  INT8_C(  58), -INT8_C(  99),
        -INT8_C(  89),  INT8_C( 101),  INT8_C(  52), -INT8_C( 111),  INT8_C(  40),  INT8_C(  52), -INT8_C(  11), -INT8_C(   2),
         INT8_C(  21),  INT8_C(  86),  INT8_C(   8),  INT8_C( 115), -INT8_C( 105), -INT8_C(   8),  INT8_C(  39), -INT8_C( 111) },
      {  INT8_C(  15),  INT8_C( 106), -INT8_C(  49), -INT8_C(  71),  INT8_C(  60),  INT8_C( 115),  INT8_C( 104), -INT8_C(   7),
         INT8_C(  21),  INT8_C(  30), -INT8_C(  92),  INT8_C(  26), -INT8_C( 116), -INT8_C(  98),  INT8_C(  24), -INT8_C(  81),
        -INT8_C(  83), -INT8_C(  79),  INT8_C(   5), -INT8_C( 110), -INT8_C(  71),  INT8_C(  48), -INT8_C(  93), -INT8_C( 106),
        -INT8_C(  21),  INT8_C(  14), -INT8_C(  88),  INT8_C( 113),  INT8_C( 103),  INT8_C(   0),  INT8_C(  24),  INT8_C( 118),
         INT8_C( 111), -INT8_C(   6), -INT8_C(  83), -INT8_C(  33), -INT8_C(  39), -INT8_C( 121), -INT8_C( 114),  INT8_C(  24),
         INT8_C( 125),  INT8_C( 125), -INT8_C(  21),  INT8_C(  22), -INT8_C( 104), -INT8_C(  57), -INT8_C( 115), -INT8_C( 107),
        -INT8_C(  97),  INT8_C( 108),  INT8_C(  61), -INT8_C(  11), -INT8_C(  99),  INT8_C(  52),  INT8_C( 105), -INT8_C( 111),
         INT8_C(  81),  INT8_C(  40),  INT8_C(  88), -INT8_C(  72),  INT8_C(  60), -INT8_C(  11),  INT8_C(  46), -INT8_C(  84) } },
    { {  INT8_C(  92), -INT8_C(  82), -INT8_C(  87), -INT8_C(  39), -INT8_C( 106),  INT8_C( 112),  INT8_C(  37),  INT8_C(  25),
        -INT8_C(  23),  INT8_C( 105), -INT8_C(  88), -INT8_C(  43),  INT8_C( 125), -INT8_C(  30),  INT8_C( 115),  INT8_C(  36),
         INT8_C(  72), -INT8_C(  89), -INT8_C(  74),  INT8_C( 112), -INT8_C(  37), -INT8_C(  85),  INT8_C( 110), -INT8_C(  15),
         INT8_C(   1),  INT8_C( 118),  INT8_C( 100), -INT8_C( 104),  INT8_C( 111), -INT8_C( 116),  INT8_C(  41), -INT8_C(  53),
         INT8_C(  58), -INT8_C(  46), -INT8_C(  92), -INT8_C(  48),  INT8_C(  66), -INT8_C(  55), -INT8_C(  23),  INT8_C(  43),
         INT8_C(  50), -INT8_C( 111),  INT8_C(   1), -INT8_C(  80),  INT8_C( 116),  INT8_C( 116), -INT8_C(  44), -INT8_C(  68),
         INT8_C(  27), -INT8_C( 118),  INT8_C(  44), -INT8_C(  10),  INT8_C(  53), -INT8_C( 102), -INT8_C(  25),  INT8_C(  54),
         INT8_C(  16),  INT8_C(  76), -INT8_C(  50),      INT8_MAX, -INT8_C(  40), -INT8_C(   9),  INT8_C(  74),  INT8_C(  18) },
      UINT64_C(16949240813494464457),
      {  INT8_C(  94),  INT8_C(  56), -INT8_C( 101), -INT8_C(  46), -INT8_C(  84),  INT8_C( 111), -INT8_C( 114), -INT8_C(  57),
        -INT8_C(   6), -INT8_C(  70), -INT8_C(  66),  INT8_C(  47),  INT8_C(  84), -INT8_C(  91),  INT8_C( 102),  INT8_C( 100),
        -INT8_C(  15),  INT8_C(  52), -INT8_C(  28), -INT8_C(  55),  INT8_C(  44),  INT8_C(  46), -INT8_C(  36), -INT8_C(  11),
         INT8_C(  29), -INT8_C(  65),  INT8_C(   1), -INT8_C(  42), -INT8_C( 117),  INT8_C(  57), -INT8_C(  63), -INT8_C(  23),
         INT8_C( 113),  INT8_C(  92), -INT8_C(  69),  INT8_C(  30), -INT8_C(  53),  INT8_C(  73), -INT8_C(  27), -INT8_C(  59),
         INT8_C(   3), -INT8_C(  93), -INT8_C(  11),  INT8_C(  87),  INT8_C(  73),  INT8_C(  91), -INT8_C(  68),  INT8_C(  58),
        -INT8_C( 113), -INT8_C(  96),  INT8_C(   4), -INT8_C(  69), -INT8_C(  50), -INT8_C(  32), -INT8_C(  79), -INT8_C(  20),
        -INT8_C(  97), -INT8_C(  78), -INT8_C(  62),  INT8_C(  42), -INT8_C(  21), -INT8_C( 125),  INT8_C(  20),  INT8_C(  93) },
      { -INT8_C(  33), -INT8_C(  49),  INT8_C( 123), -INT8_C(  86),  INT8_C(  25),  INT8_C(  96),  INT8_C( 112),  INT8_C(  28),
         INT8_C(   4),  INT8_C( 101),  INT8_C( 116),  INT8_C(  77), -INT8_C(  64),  INT8_C(  48), -INT8_C( 121),  INT8_C(  79),
        -INT8_C(  48), -INT8_C( 117),  INT8_C(  11), -INT8_C(  98),  INT8_C( 107), -INT8_C(  68), -INT8_C( 118),  INT8_C(  10),
         INT8_C( 110),  INT8_C(  76),  INT8_C(  53),  INT8_C(  90), -INT8_C(  49),  INT8_C(  73), -INT8_C(  73), -INT8_C(  82),
         INT8_C(  24),  INT8_C(  50),  INT8_C(  89),  INT8_C(  49), -INT8_C( 110), -INT8_C(  55),  INT8_C(  78), -INT8_C( 106),
         INT8_C(  46), -INT8_C(  62), -INT8_C(  29), -INT8_C(  18), -INT8_C(  14),  INT8_C( 107),  INT8_C(  61), -INT8_C(  62),
        -INT8_C(  10),  INT8_C(  72),  INT8_C(  96),  INT8_C(  98),  INT8_C(   4), -INT8_C(  21),  INT8_C( 108),  INT8_C( 115),
         INT8_C(  55), -INT8_C(  95), -INT8_C(  51),  INT8_C(   7), -INT8_C(  22), -INT8_C( 124), -INT8_C(  75),  INT8_C(   3) },
      {  INT8_C(  94), -INT8_C(  82), -INT8_C(  87), -INT8_C(  49), -INT8_C( 106),  INT8_C( 112), -INT8_C(  46), -INT8_C(  86),
        -INT8_C(  84),  INT8_C(  25),  INT8_C( 111),  INT8_C(  96),  INT8_C( 125),  INT8_C( 112), -INT8_C(  57),  INT8_C(  28),
        -INT8_C(  15), -INT8_C(  48), -INT8_C(  74),  INT8_C( 112), -INT8_C(  37),  INT8_C(  11), -INT8_C(  55), -INT8_C(  98),
         INT8_C(   1),  INT8_C( 118),  INT8_C(  46), -INT8_C(  68),  INT8_C( 111), -INT8_C( 116),  INT8_C(  41), -INT8_C(  53),
         INT8_C(  58), -INT8_C(  46), -INT8_C(  92),  INT8_C(  50), -INT8_C(  69),  INT8_C(  89), -INT8_C(  23),  INT8_C(  49),
         INT8_C(  50), -INT8_C( 111),  INT8_C(  73), -INT8_C(  55),  INT8_C( 116),  INT8_C( 116), -INT8_C(  59), -INT8_C( 106),
        -INT8_C( 113), -INT8_C(  10), -INT8_C(  96), -INT8_C(  10),  INT8_C(   4),  INT8_C(  96), -INT8_C(  25),  INT8_C(  54),
        -INT8_C(  50),  INT8_C(   4), -INT8_C(  50), -INT8_C(  21), -INT8_C(  40),  INT8_C( 108), -INT8_C(  20),  INT8_C( 115) } },
    { { -INT8_C(  74),  INT8_C(  14),  INT8_C(  52),  INT8_C(  72), -INT8_C(  41), -INT8_C( 126), -INT8_C(  33),  INT8_C(   5),
         INT8_C(  68), -INT8_C(  62), -INT8_C(  13),  INT8_C(  54),  INT8_C(  45),  INT8_C(  49), -INT8_C(   8),  INT8_C(  36),
         INT8_C( 121),  INT8_C(  89), -INT8_C( 122),  INT8_C( 126),  INT8_C(  68), -INT8_C(  14), -INT8_C(  15),  INT8_C( 123),
        -INT8_C( 108), -INT8_C(  66), -INT8_C( 126),  INT8_C( 126),  INT8_C(  66),  INT8_C(  56), -INT8_C( 127), -INT8_C(   8),
         INT8_C(  70), -INT8_C(  74),  INT8_C(  64),  INT8_C(  30),  INT8_C(  56),  INT8_C(  31),  INT8_C(  35),  INT8_C( 125),
        -INT8_C(  30),  INT8_C(  23), -INT8_C(  77),  INT8_C(  15),  INT8_C(  72), -INT8_C(  84),  INT8_C(  51), -INT8_C(  63),
         INT8_C(   5), -INT8_C(  71),  INT8_C(  63),  INT8_C(  73), -INT8_C(  84),  INT8_C(  48), -INT8_C(  60),  INT8_C(  64),
        -INT8_C(  18),  INT8_C(  71), -INT8_C(  66),  INT8_C(  48),      INT8_MAX,  INT8_C(  64),  INT8_C(  40), -INT8_C(  59) },
      UINT64_C( 7686245470521485814),
      {  INT8_C(  30),  INT8_C(  95),  INT8_C( 122),  INT8_C( 102),  INT8_C(  11), -INT8_C(  83),  INT8_C(  39),  INT8_C(  16),
         INT8_C( 103),  INT8_C( 103),  INT8_C(  89),  INT8_C(  19), -INT8_C( 105),  INT8_C(  29),  INT8_C(  83), -INT8_C( 122),
         INT8_C( 100),  INT8_C(  17), -INT8_C(  74), -INT8_C(  29),  INT8_C(  81), -INT8_C(  33), -INT8_C(  87),  INT8_C(  71),
         INT8_C(  72), -INT8_C( 116),  INT8_C( 118), -INT8_C(  48), -INT8_C( 109),  INT8_C(  33),  INT8_C(  59), -INT8_C(  79),
             INT8_MIN, -INT8_C(  75),  INT8_C(  23), -INT8_C( 117),  INT8_C(  98),  INT8_C(  63), -INT8_C( 101), -INT8_C(  55),
        -INT8_C(  90), -INT8_C(  12), -INT8_C(  36),  INT8_C(  61),  INT8_C(  18),  INT8_C(  47), -INT8_C(  61),  INT8_C( 118),
         INT8_C(  65),  INT8_C( 122),  INT8_C(  90), -INT8_C( 110),  INT8_C(  89),  INT8_C(   3), -INT8_C(  38), -INT8_C(  95),
        -INT8_C( 113),  INT8_C(  80),  INT8_C( 113),  INT8_C(  35),  INT8_C( 113), -INT8_C(  84), -INT8_C(  44), -INT8_C(  14) },
      {  INT8_C(  97), -INT8_C(  20),  INT8_C( 125), -INT8_C(  60),  INT8_C(  43),  INT8_C(  25), -INT8_C( 115), -INT8_C(  47),
         INT8_C(  13),  INT8_C( 106),  INT8_C(  14),  INT8_C(  31), -INT8_C( 103), -INT8_C(  46), -INT8_C( 106), -INT8_C(  38),
         INT8_C(  76), -INT8_C(  16),  INT8_C( 109), -INT8_C(  91), -INT8_C(  13),  INT8_C(  71),  INT8_C(  70), -INT8_C( 126),
        -INT8_C( 105), -INT8_C(  73), -INT8_C(  91),  INT8_C(   8),  INT8_C( 100),  INT8_C( 122), -INT8_C(   6), -INT8_C(  59),
         INT8_C( 102),  INT8_C( 120), -INT8_C( 119), -INT8_C( 111), -INT8_C( 111),  INT8_C(  23),  INT8_C(  98), -INT8_C(  98),
        -INT8_C( 127),  INT8_C( 112), -INT8_C(  66),  INT8_C(  26),  INT8_C(  66),  INT8_C(  84), -INT8_C(  11), -INT8_C( 114),
         INT8_C(  68),  INT8_C(  98),  INT8_C(  51),  INT8_C(  55), -INT8_C(  87),  INT8_C( 121), -INT8_C(  71),  INT8_C(  64),
         INT8_C(  49),  INT8_C(  95),  INT8_C(  72), -INT8_C( 107), -INT8_C(  39),  INT8_C(  67),  INT8_C(  90),  INT8_C(  63) },
      { -INT8_C(  74),  INT8_C(  97),  INT8_C(  95),  INT8_C(  72),  INT8_C( 122),  INT8_C( 125),  INT8_C( 102), -INT8_C(  60),
         INT8_C(  11), -INT8_C(  62), -INT8_C(  13),  INT8_C(  25),  INT8_C(  45), -INT8_C( 115),  INT8_C(  16),  INT8_C(  36),
         INT8_C( 100),  INT8_C(  76), -INT8_C( 122),  INT8_C( 126),  INT8_C(  68),  INT8_C( 109), -INT8_C(  29), -INT8_C(  91),
        -INT8_C( 108), -INT8_C(  13), -INT8_C(  33),  INT8_C(  71),  INT8_C(  66),  INT8_C(  70), -INT8_C( 127), -INT8_C(   8),
         INT8_C(  70), -INT8_C(  74),  INT8_C(  64),  INT8_C( 120),  INT8_C(  56),  INT8_C(  31),  INT8_C(  35), -INT8_C( 111),
         INT8_C(  98), -INT8_C( 111),  INT8_C(  63),  INT8_C(  15),  INT8_C(  72), -INT8_C(  84),  INT8_C(  51), -INT8_C(  63),
         INT8_C(  65),  INT8_C(  68),  INT8_C(  63),  INT8_C(  98), -INT8_C(  84),  INT8_C(  51), -INT8_C(  60),  INT8_C(  55),
        -INT8_C(  18), -INT8_C(  87), -INT8_C(  66),  INT8_C( 121),      INT8_MAX, -INT8_C(  71), -INT8_C(  95), -INT8_C(  59) } },
    { { -INT8_C(  69), -INT8_C(  28), -INT8_C(  48),  INT8_C(  76), -INT8_C(   5),  INT8_C(  50), -INT8_C(  22),  INT8_C( 124),
        -INT8_C(  94), -INT8_C(  88), -INT8_C( 106), -INT8_C(  27), -INT8_C(   4), -INT8_C( 117),  INT8_C( 115),  INT8_C(  64),
        -INT8_C(  19), -INT8_C(  89),  INT8_C( 119), -INT8_C( 106),  INT8_C(  32),  INT8_C(  49), -INT8_C(  42),  INT8_C(  81),
        -INT8_C( 112),  INT8_C(  31), -INT8_C(  26),  INT8_C( 105),  INT8_C(  98),  INT8_C(  65), -INT8_C(  88),  INT8_C(  29),
         INT8_C(  37),  INT8_C( 120),  INT8_C( 105),  INT8_C(  32), -INT8_C(  86),  INT8_C(  83), -INT8_C( 100),  INT8_C(  76),
        -INT8_C(   4),  INT8_C(  50),  INT8_C(  49), -INT8_C(   8), -INT8_C(  66), -INT8_C(  91),  INT8_C(  57), -INT8_C(  85),
         INT8_C(  76), -INT8_C(  80),  INT8_C(  66),  INT8_C( 108), -INT8_C(  31),  INT8_C(  24), -INT8_C(  66),  INT8_C( 113),
         INT8_C(  55), -INT8_C(  92), -INT8_C(  38), -INT8_C( 103), -INT8_C(  27), -INT8_C( 126), -INT8_C(  74),  INT8_C(  10) },
      UINT64_C( 8066446607575031802),
      { -INT8_C(   7),  INT8_C(  34),  INT8_C( 103), -INT8_C(  73), -INT8_C(  57), -INT8_C(  96),  INT8_C(  98),  INT8_C(  19),
         INT8_C(  81), -INT8_C(  92),      INT8_MIN,  INT8_C(  50), -INT8_C(  67),  INT8_C(  62), -INT8_C(  92), -INT8_C(  12),
        -INT8_C(  30),  INT8_C( 126), -INT8_C( 114), -INT8_C(  56),  INT8_C(   1),  INT8_C(  68), -INT8_C(  46), -INT8_C(   5),
         INT8_C( 100), -INT8_C(   3), -INT8_C(  96), -INT8_C(  41), -INT8_C(  61), -INT8_C( 111),  INT8_C(  70), -INT8_C(  68),
        -INT8_C(  77), -INT8_C(  83),  INT8_C( 115),  INT8_C( 123),  INT8_C(  78), -INT8_C(  42), -INT8_C( 114), -INT8_C(  97),
         INT8_C( 122),  INT8_C(  14), -INT8_C(  47),  INT8_C(  55),  INT8_C(  76),  INT8_C( 117),  INT8_C(  44),  INT8_C(  47),
        -INT8_C(  12), -INT8_C(  70), -INT8_C(   9), -INT8_C(  11), -INT8_C(   2), -INT8_C(  55), -INT8_C(  16),  INT8_C(  98),
        -INT8_C(  58), -INT8_C( 112),  INT8_C(  57), -INT8_C( 118),  INT8_C(  33),      INT8_MAX,  INT8_C(  70), -INT8_C(  43) },
      {  INT8_C(  45), -INT8_C(  70),  INT8_C(  80),  INT8_C( 123), -INT8_C( 112), -INT8_C(  34),  INT8_C(  26),  INT8_C(  10),
        -INT8_C(  19), -INT8_C(  21),  INT8_C(  66),  INT8_C(  57),  INT8_C(  97),  INT8_C( 110),  INT8_C( 104),  INT8_C(  85),
         INT8_C(  40),  INT8_C(  95),  INT8_C(  74),  INT8_C(  38),  INT8_C(  41),  INT8_C(  58), -INT8_C( 119), -INT8_C(  17),
        -INT8_C(  53), -INT8_C(  62),  INT8_C( 121), -INT8_C(  20),  INT8_C(  66), -INT8_C(  64), -INT8_C(  63),  INT8_C( 111),
         INT8_C( 122),  INT8_C(  17), -INT8_C(  22),  INT8_C(  10), -INT8_C(  16),  INT8_C(   4),  INT8_C(  20), -INT8_C(  35),
        -INT8_C(  17),  INT8_C(  86),  INT8_C(  22),  INT8_C(  80), -INT8_C(  60),      INT8_MAX, -INT8_C(  91), -INT8_C(  20),
        -INT8_C(  34), -INT8_C(  17),  INT8_C(  19),  INT8_C(   7),  INT8_C(  42), -INT8_C( 100), -INT8_C(   9), -INT8_C(  11),
         INT8_C(  94),  INT8_C( 112), -INT8_C(  31), -INT8_C(  96),  INT8_C(  48), -INT8_C(  93),  INT8_C(  15), -INT8_C(  86) },
      { -INT8_C(  69),  INT8_C(  45), -INT8_C(  48), -INT8_C(  70),  INT8_C( 103),  INT8_C(  80), -INT8_C(  73),  INT8_C( 123),
        -INT8_C(  57), -INT8_C( 112), -INT8_C(  96), -INT8_C(  34),  INT8_C(  98), -INT8_C( 117),  INT8_C( 115),  INT8_C(  64),
        -INT8_C(  19),  INT8_C(  40),  INT8_C( 119),  INT8_C(  95),  INT8_C(  32),  INT8_C(  74), -INT8_C(  42),  INT8_C(  81),
        -INT8_C( 112),  INT8_C(  31),  INT8_C(  68),  INT8_C( 105),  INT8_C(  98), -INT8_C( 119), -INT8_C(  88), -INT8_C(  17),
        -INT8_C(  77),  INT8_C( 122),  INT8_C( 105),  INT8_C(  32),  INT8_C( 115), -INT8_C(  22),  INT8_C( 123),  INT8_C(  76),
        -INT8_C(   4), -INT8_C(  16), -INT8_C(  42), -INT8_C(   8), -INT8_C(  66), -INT8_C(  91), -INT8_C(  97), -INT8_C(  35),
        -INT8_C(  12), -INT8_C(  80),  INT8_C(  66),  INT8_C( 108), -INT8_C(   9),  INT8_C(  19), -INT8_C(  11),  INT8_C(   7),
        -INT8_C(   2),  INT8_C(  42), -INT8_C(  55), -INT8_C( 100), -INT8_C(  27), -INT8_C(   9),  INT8_C(  98),  INT8_C(  10) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i src = simde_mm512_loadu_epi8(test_vec[i].src);
    simde__m512i a = simde_mm512_loadu_epi8(test_vec[i].a);
    simde__m512i b = simde_mm512_loadu_epi8(test_vec[i].b);
    simde__m512i r = simde_mm512_mask_unpacklo_epi8(src, test_vec[i].k, a, b);
    simde_test_x86_assert_equal_i8x64(r, simde_mm512_loadu_epi8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m512i src = simde_test_x86_random_i8x64();
    simde__mmask64 k = simde_test_x86_random_mmask64();
    simde__m512i a = simde_test_x86_random_i8x64();
    simde__m512i b = simde_test_x86_random_i8x64();
    simde__m512i r = simde_mm512_mask_unpacklo_epi8(src, k, a, b);

    simde_test_x86_write_i8x64(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask64(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i8x64(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i8x64(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i8x64(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_maskz_unpacklo_epi8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask64 k;
    const int8_t a[64];
    const int8_t b[64];
    const int8_t r[64];
  } test_vec[] = {
    { UINT64_C( 7559978641320233557),
      { -INT8_C(  23), -INT8_C(  31),  INT8_C(  84),  INT8_C(  49), -INT8_C(   6),  INT8_C(  66), -INT8_C(  77), -INT8_C(  40),
         INT8_C(  96), -INT8_C(  83),  INT8_C(   6), -INT8_C(  77),  INT8_C(  43), -INT8_C( 117), -INT8_C(  24),  INT8_C(  79),
         INT8_C(   8),  INT8_C(  39), -INT8_C(   6),  INT8_C(  10),  INT8_C(  36),  INT8_C(   5), -INT8_C(  84),  INT8_C( 121),
        -INT8_C(  48),  INT8_C(  26), -INT8_C( 118),  INT8_C(  85), -INT8_C( 118),  INT8_C( 116), -INT8_C(  67),  INT8_C( 115),
         INT8_C(  86),  INT8_C(  17), -INT8_C(  92),  INT8_C(  80),  INT8_C(  84),  INT8_C(  87),  INT8_C(  40), -INT8_C(  76),
         INT8_C(   5),  INT8_C(  46),  INT8_C( 103),  INT8_C(  48), -INT8_C(  71),  INT8_C(  80),      INT8_MAX, -INT8_C(  63),
         INT8_C( 119),  INT8_C( 121), -INT8_C(  53), -INT8_C( 101),  INT8_C( 126),  INT8_C( 119),  INT8_C(  20),  INT8_C(  78),
        -INT8_C( 111), -INT8_C(  97), -INT8_C(  93),  INT8_C(  27),  INT8_C(  19),  INT8_C(  97), -INT8_C( 113),  INT8_C( 105) },
      {  INT8_C( 114),  INT8_C(  51), -INT8_C(  71), -INT8_C(  58), -INT8_C( 117), -INT8_C(  31),  INT8_C( 122), -INT8_C( 112),
         INT8_C(  15), -INT8_C(  30), -INT8_C(  64), -INT8_C(  56),  INT8_C(  50),  INT8_C(  63), -INT8_C( 119), -INT8_C(  87),
        -INT8_C(  72),  INT8_C(  84),  INT8_C(  69),  INT8_C(  54), -INT8_C(  53),  INT8_C(  89), -INT8_C( 123),  INT8_C(  92),
        -INT8_C(   8),  INT8_C(  40),  INT8_C( 120),  INT8_C(  12), -INT8_C( 119),  INT8_C(   7),  INT8_C( 117), -INT8_C(   4),
         INT8_C(  58),  INT8_C(  47), -INT8_C(  62), -INT8_C(  59),  INT8_C(  16),  INT8_C(  61),  INT8_C(  85),  INT8_C(  32),
         INT8_C(  31),  INT8_C(  21), -INT8_C(  24),  INT8_C(  81),  INT8_C(  84),  INT8_C( 114), -INT8_C(   6),  INT8_C(  12),
        -INT8_C(  58),  INT8_C(  63),  INT8_C(  67), -INT8_C( 110), -INT8_C( 103), -INT8_C(  56), -INT8_C(  18), -INT8_C( 111),
        -INT8_C(  16),  INT8_C( 102), -INT8_C(  99),  INT8_C( 122),  INT8_C( 109),  INT8_C(  19),  INT8_C( 118), -INT8_C(  88) },
      { -INT8_C(  23),  INT8_C(   0), -INT8_C(  31),  INT8_C(   0),  INT8_C(  84),  INT8_C(   0),  INT8_C(  49),  INT8_C(   0),
         INT8_C(   0), -INT8_C( 117),  INT8_C(   0), -INT8_C(  31),  INT8_C(   0),  INT8_C(   0), -INT8_C(  40), -INT8_C( 112),
         INT8_C(   0), -INT8_C(  72),  INT8_C(  39),  INT8_C(  84),  INT8_C(   0),  INT8_C(  69),  INT8_C(  10),  INT8_C(   0),
         INT8_C(  36),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  84),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
         INT8_C(  86),  INT8_C(   0),  INT8_C(  17),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  59),
         INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(  40),  INT8_C(  85), -INT8_C(  76),  INT8_C(   0),
         INT8_C(   0), -INT8_C(  58),  INT8_C(   0),  INT8_C(  63),  INT8_C(   0),  INT8_C(  67), -INT8_C( 101), -INT8_C( 110),
         INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  56),  INT8_C(   0), -INT8_C(  18),  INT8_C(  78),  INT8_C(   0) } },
    { UINT64_C(10696826973619828802),
      { -INT8_C(  40),  INT8_C(  91), -INT8_C(  27),  INT8_C(  45), -INT8_C(  51), -INT8_C(  32),  INT8_C(  57), -INT8_C( 109),
         INT8_C(  31),  INT8_C( 124),  INT8_C(  37), -INT8_C(  72),  INT8_C(  68),  INT8_C(  20),  INT8_C(  74),  INT8_C(  53),
         INT8_C( 122), -INT8_C(  25), -INT8_C(  81), -INT8_C(  24), -INT8_C(   6),  INT8_C(  37), -INT8_C( 112),  INT8_C(  60),
         INT8_C(  93), -INT8_C(   3), -INT8_C( 113), -INT8_C(  45), -INT8_C(  64),  INT8_C(   1),  INT8_C( 103), -INT8_C( 103),
         INT8_C(  92),  INT8_C(  77), -INT8_C(  58),  INT8_C(  41),  INT8_C(  45), -INT8_C(   1), -INT8_C(  67),  INT8_C(  76),
         INT8_C( 124), -INT8_C(  30),  INT8_C(   5), -INT8_C(  64), -INT8_C(  10),  INT8_C(  79), -INT8_C(  11),  INT8_C( 113),
         INT8_C(  54), -INT8_C(  92),  INT8_C(  89),  INT8_C(  49), -INT8_C(  55), -INT8_C(  23),  INT8_C( 109),  INT8_C(  39),
        -INT8_C(  26), -INT8_C(   4), -INT8_C(   6), -INT8_C(  89), -INT8_C(   2),  INT8_C(  97),  INT8_C(  64),  INT8_C(  90) },
      { -INT8_C(  82),  INT8_C(   6), -INT8_C( 124), -INT8_C(  37),  INT8_C(   5),  INT8_C(  65),  INT8_C(  40), -INT8_C( 127),
         INT8_C(  35),  INT8_C(  45),  INT8_C(  66),  INT8_C(  26),  INT8_C( 124),  INT8_C(  55), -INT8_C( 117), -INT8_C(  78),
        -INT8_C(  36), -INT8_C(  28), -INT8_C(  29), -INT8_C(  91), -INT8_C(  51),  INT8_C(  81), -INT8_C(  52), -INT8_C(  77),
         INT8_C(  77), -INT8_C(  58),  INT8_C(  90),  INT8_C(  75),  INT8_C(  40), -INT8_C( 102), -INT8_C(  90), -INT8_C(  42),
        -INT8_C(  96),  INT8_C(  42), -INT8_C(  78), -INT8_C(  90),  INT8_C( 107), -INT8_C(  38),  INT8_C(  39), -INT8_C( 114),
         INT8_C(   7),  INT8_C( 105), -INT8_C(  88), -INT8_C( 125), -INT8_C(  95),  INT8_C(  51),  INT8_C(  53),  INT8_C( 125),
         INT8_C(  23),  INT8_C(  25),  INT8_C(  34), -INT8_C(  28),  INT8_C( 106), -INT8_C(  17), -INT8_C( 104), -INT8_C(  73),
        -INT8_C(  75), -INT8_C(  14),  INT8_C(   3), -INT8_C(  35), -INT8_C( 115), -INT8_C(  87), -INT8_C(  76),  INT8_C(  45) },
      {  INT8_C(   0), -INT8_C(  82),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(  45),  INT8_C(   0),
         INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(  65),  INT8_C(  57),  INT8_C(  40),  INT8_C(   0),  INT8_C(   0),
         INT8_C( 122),  INT8_C(   0), -INT8_C(  25), -INT8_C(  28),  INT8_C(   0), -INT8_C(  29), -INT8_C(  24),  INT8_C(   0),
         INT8_C(   0), -INT8_C(  51),  INT8_C(   0),  INT8_C(   0), -INT8_C( 112),  INT8_C(   0),  INT8_C(  60),  INT8_C(   0),
         INT8_C(  92),  INT8_C(   0),  INT8_C(  77),  INT8_C(   0), -INT8_C(  58), -INT8_C(  78),  INT8_C(  41),  INT8_C(   0),
         INT8_C(  45),  INT8_C( 107),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(  76), -INT8_C( 114),
         INT8_C(   0),  INT8_C(  23),  INT8_C(   0),  INT8_C(   0),  INT8_C(  89),  INT8_C(  34),  INT8_C(  49),  INT8_C(   0),
         INT8_C(   0),  INT8_C(   0), -INT8_C(  23),  INT8_C(   0),  INT8_C( 109),  INT8_C(   0),  INT8_C(   0), -INT8_C(  73) } },
    { UINT64_C( 5173786325292377811),
      {  INT8_C( 100),  INT8_C( 117), -INT8_C(  54),  INT8_C(   5), -INT8_C(  88), -INT8_C(   1), -INT8_C( 126), -INT8_C(  64),
         INT8_C(  24), -INT8_C(  91), -INT8_C(  92), -INT8_C( 126), -INT8_C( 108),  INT8_C(  60),  INT8_C(  58),  INT8_C(  73),
         INT8_C(  47),  INT8_C(  61),  INT8_C(  39), -INT8_C(  68), -INT8_C(  26), -INT8_C(  37), -INT8_C(  23), -INT8_C(  71),
         INT8_C(  65), -INT8_C(  67), -INT8_C(   9), -INT8_C( 127), -INT8_C(  72), -INT8_C(  61), -INT8_C(  56),  INT8_C(  28),
         INT8_C(  56), -INT8_C( 110),  INT8_C(  34), -INT8_C(  31), -INT8_C( 111), -INT8_C(  92), -INT8_C(  95), -INT8_C(  86),
         INT8_C(  73),  INT8_C(  69),  INT8_C(  44), -INT8_C(  35), -INT8_C( 126),  INT8_C( 102),  INT8_C(  39), -INT8_C(  79),
        -INT8_C(  93),  INT8_C(  78),  INT8_C( 109), -INT8_C( 119),  INT8_C(  41),  INT8_C(  86),  INT8_C(  66),  INT8_C( 106),
         INT8_C(  19),  INT8_C(  57), -INT8_C(  21), -INT8_C(  53), -INT8_C(   3), -INT8_C(  77), -INT8_C(  24),  INT8_C(  53) },
      {  INT8_C(  69),  INT8_C(  10),  INT8_C(  22), -INT8_C(  42), -INT8_C(  82), -INT8_C(  73),      INT8_MIN, -INT8_C(   8),
        -INT8_C(   3), -INT8_C(  83), -INT8_C(  43),      INT8_MAX,  INT8_C(  19), -INT8_C(   4),  INT8_C(  48), -INT8_C(  73),
         INT8_C(  74), -INT8_C(  99),  INT8_C(  64),  INT8_C( 115), -INT8_C(  13), -INT8_C( 125), -INT8_C(  35),  INT8_C(   7),
        -INT8_C(  68), -INT8_C(  56), -INT8_C(  46), -INT8_C(  71),  INT8_C( 123), -INT8_C(  70), -INT8_C(  17), -INT8_C(  64),
        -INT8_C(  60),  INT8_C(   5), -INT8_C( 105),  INT8_C( 115), -INT8_C(  67),  INT8_C(  23),  INT8_C( 107), -INT8_C(  70),
        -INT8_C(  60),  INT8_C(  64),  INT8_C(  57), -INT8_C(  40),  INT8_C(  61),  INT8_C( 105), -INT8_C( 113), -INT8_C( 121),
         INT8_C(   6), -INT8_C(  49), -INT8_C(   5), -INT8_C(   7),  INT8_C(  82), -INT8_C(  40),  INT8_C(   0),  INT8_C(  15),
        -INT8_C(  95), -INT8_C(  45), -INT8_C(  56),  INT8_C(  28), -INT8_C( 115), -INT8_C(  73), -INT8_C(  35),  INT8_C(  82) },
      {  INT8_C( 100),  INT8_C(  69),  INT8_C(   0),  INT8_C(   0), -INT8_C(  54),  INT8_C(   0),  INT8_C(   5), -INT8_C(  42),
         INT8_C(   0), -INT8_C(  82), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),      INT8_MIN, -INT8_C(  64),  INT8_C(   0),
         INT8_C(  47),  INT8_C(  74),  INT8_C(   0),  INT8_C(   0),  INT8_C(  39),  INT8_C(   0), -INT8_C(  68),  INT8_C( 115),
         INT8_C(   0), -INT8_C(  13), -INT8_C(  37), -INT8_C( 125), -INT8_C(  23), -INT8_C(  35),  INT8_C(   0),  INT8_C(   0),
         INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  31),  INT8_C(   0),
        -INT8_C( 111), -INT8_C(  67),  INT8_C(   0),  INT8_C(  23), -INT8_C(  95),  INT8_C( 107), -INT8_C(  86), -INT8_C(  70),
         INT8_C(   0),  INT8_C(   0),  INT8_C(  78), -INT8_C(  49),  INT8_C(   0),  INT8_C(   0), -INT8_C( 119), -INT8_C(   7),
         INT8_C(  41),  INT8_C(  82),  INT8_C(  86),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C( 106),  INT8_C(   0) } },
    { UINT64_C( 5779297597441537213),
      {  INT8_C( 112),  INT8_C( 109),  INT8_C(  40), -INT8_C(  83), -INT8_C(  42), -INT8_C(  73),  INT8_C(  53), -INT8_C(  36),
        -INT8_C( 122),  INT8_C(  48), -INT8_C(  43), -INT8_C(  39),  INT8_C(   8), -INT8_C(  42), -INT8_C(  24), -INT8_C(  87),
        -INT8_C(  87), -INT8_C(  80), -INT8_C(  58),  INT8_C(  54),  INT8_C( 104), -INT8_C(  93), -INT8_C( 120),  INT8_C(  37),
         INT8_C(  23),  INT8_C(  77), -INT8_C(  97), -INT8_C(  94),  INT8_C( 125), -INT8_C(  45), -INT8_C(  14), -INT8_C(  18),
         INT8_C(  64),  INT8_C(  26), -INT8_C( 101),  INT8_C(  22), -INT8_C(  47), -INT8_C(  48), -INT8_C(  14),  INT8_C(  88),
         INT8_C(   0), -INT8_C(  57),  INT8_C(  49),  INT8_C(   9), -INT8_C(  99),  INT8_C(  25), -INT8_C(  78),  INT8_C(  70),
        -INT8_C(  55),  INT8_C( 120),  INT8_C( 125),  INT8_C(  49),  INT8_C(  27),  INT8_C(   5),  INT8_C(  86),  INT8_C(  50),
         INT8_C(  83), -INT8_C(  11), -INT8_C(  43), -INT8_C(  48), -INT8_C(  56), -INT8_C(  57), -INT8_C(  66),  INT8_C(   8) },
      { -INT8_C(  30),  INT8_C(  90),  INT8_C(  30), -INT8_C(  77),  INT8_C(  42),  INT8_C(  16),  INT8_C(  11),  INT8_C(  43),
        -INT8_C(  40),  INT8_C(  60),  INT8_C(  52),  INT8_C( 117),  INT8_C(  85), -INT8_C(  26), -INT8_C(  68),  INT8_C(  31),
         INT8_C(  95),  INT8_C(  57),  INT8_C(  80),  INT8_C( 122),  INT8_C(  62), -INT8_C(  89), -INT8_C(  83), -INT8_C( 111),
        -INT8_C( 100), -INT8_C( 126),  INT8_C(  98),  INT8_C( 101),  INT8_C(  73),  INT8_C(  32),  INT8_C( 109),  INT8_C(  43),
         INT8_C( 122), -INT8_C( 116), -INT8_C(  33), -INT8_C(  91), -INT8_C( 100), -INT8_C(  22), -INT8_C(  48),  INT8_C( 116),
         INT8_C(  39),  INT8_C(   4), -INT8_C(  22),  INT8_C( 124), -INT8_C(  22), -INT8_C(  90), -INT8_C( 101),  INT8_C(  73),
        -INT8_C(  33), -INT8_C(  20), -INT8_C(  60),  INT8_C(  29), -INT8_C( 109),  INT8_C( 113), -INT8_C(  81),  INT8_C(  47),
        -INT8_C(  13),  INT8_C(  17), -INT8_C( 108),  INT8_C(  60),  INT8_C(  49),  INT8_C(   2),  INT8_C( 104), -INT8_C(  84) },
      {  INT8_C( 112),  INT8_C(   0),  INT8_C( 109),  INT8_C(  90),  INT8_C(  40),  INT8_C(  30),  INT8_C(   0), -INT8_C(  77),
         INT8_C(   0),  INT8_C(   0), -INT8_C(  73),  INT8_C(   0),  INT8_C(  53),  INT8_C(  11), -INT8_C(  36),  INT8_C(   0),
        -INT8_C(  87),  INT8_C(   0), -INT8_C(  80),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(  54),  INT8_C( 122),
         INT8_C(   0),  INT8_C(  62),  INT8_C(   0), -INT8_C(  89), -INT8_C( 120), -INT8_C(  83),  INT8_C(  37),  INT8_C(   0),
         INT8_C(  64),  INT8_C( 122),  INT8_C(   0), -INT8_C( 116),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  91),
         INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  14), -INT8_C(  48),  INT8_C(   0),  INT8_C(   0),
         INT8_C(   0),  INT8_C(   0),  INT8_C( 120),  INT8_C(   0),  INT8_C( 125), -INT8_C(  60),  INT8_C(   0),  INT8_C(   0),
         INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(  86),  INT8_C(   0),  INT8_C(  50),  INT8_C(   0) } },
    { UINT64_C( 6385859291681736590),
      {  INT8_C(  37), -INT8_C( 119), -INT8_C(  43),  INT8_C(  15),  INT8_C(  47),  INT8_C( 112),  INT8_C(  89),  INT8_C(  14),
         INT8_C(  92),  INT8_C(  29),  INT8_C(  43), -INT8_C(  17), -INT8_C( 114), -INT8_C(  38),  INT8_C(  31), -INT8_C( 127),
        -INT8_C(  21), -INT8_C(  77), -INT8_C(  67),  INT8_C(  29), -INT8_C(  75),  INT8_C(  37), -INT8_C(  55),  INT8_C(  67),
         INT8_C( 108),  INT8_C(  26),  INT8_C( 110), -INT8_C(  98),  INT8_C(  59),  INT8_C(  13), -INT8_C(  10),  INT8_C(  96),
        -INT8_C( 106), -INT8_C(  53),  INT8_C( 111), -INT8_C(  59),  INT8_C(  60), -INT8_C(  56), -INT8_C(  45), -INT8_C( 104),
        -INT8_C(  27), -INT8_C(   2), -INT8_C( 120),  INT8_C( 115), -INT8_C(  39), -INT8_C(  89), -INT8_C(  12), -INT8_C(  60),
         INT8_C(  90), -INT8_C(  78), -INT8_C(  31),  INT8_C(  16), -INT8_C(  41), -INT8_C(  86),  INT8_C(  83),  INT8_C(  68),
        -INT8_C(  60), -INT8_C(  63), -INT8_C(  30), -INT8_C(   1), -INT8_C(  50), -INT8_C(  40),  INT8_C(  95),  INT8_C( 100) },
      { -INT8_C(  92), -INT8_C(  49),  INT8_C(  41), -INT8_C(  32), -INT8_C( 105), -INT8_C(   4),  INT8_C( 120),  INT8_C( 125),
        -INT8_C(   5),  INT8_C(   0), -INT8_C(  16), -INT8_C(  44), -INT8_C(  89), -INT8_C(  27), -INT8_C( 104),  INT8_C(   2),
        -INT8_C( 105),  INT8_C( 122),  INT8_C(  18),  INT8_C( 110),  INT8_C(  36),  INT8_C( 101), -INT8_C(  78), -INT8_C(  23),
         INT8_C(  39), -INT8_C( 108), -INT8_C(  24), -INT8_C(  11),  INT8_C( 109),  INT8_C(  72),  INT8_C(  90),  INT8_C(  17),
         INT8_C(  23), -INT8_C( 125), -INT8_C(  15), -INT8_C(  82),      INT8_MIN,  INT8_C( 105),  INT8_C(  43),  INT8_C( 123),
         INT8_C( 106),  INT8_C(  28),  INT8_C(  79),  INT8_C(  17),  INT8_C(   1), -INT8_C(  25),  INT8_C(  19), -INT8_C( 104),
         INT8_C(  97),  INT8_C(  37),  INT8_C(   6), -INT8_C( 122), -INT8_C( 117), -INT8_C(  71),  INT8_C( 111), -INT8_C(  78),
         INT8_C(  77),  INT8_C(  87), -INT8_C(  89), -INT8_C(  70), -INT8_C(  97),  INT8_C(   1), -INT8_C(  53), -INT8_C(  74) },
      {  INT8_C(   0), -INT8_C(  92), -INT8_C( 119), -INT8_C(  49),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  32),
         INT8_C(  47), -INT8_C( 105),  INT8_C( 112),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(  14),  INT8_C(   0),
        -INT8_C(  21),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  67),  INT8_C(   0),  INT8_C(  29),  INT8_C(   0),
         INT8_C(   0),  INT8_C(  36),  INT8_C(   0),  INT8_C( 101),  INT8_C(   0), -INT8_C(  78),  INT8_C(   0),  INT8_C(   0),
        -INT8_C( 106),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C( 111), -INT8_C(  15),  INT8_C(   0),  INT8_C(   0),
         INT8_C(  60),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(  43),  INT8_C(   0),  INT8_C(   0),
         INT8_C(  90),  INT8_C(  97), -INT8_C(  78),  INT8_C(  37), -INT8_C(  31),  INT8_C(   0),  INT8_C(   0), -INT8_C( 122),
         INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  71),  INT8_C(  83),  INT8_C(   0),  INT8_C(  68),  INT8_C(   0) } },
    { UINT64_C(10412480831454297221),
      { -INT8_C(  84), -INT8_C(  49), -INT8_C(  95), -INT8_C(  83), -INT8_C(  74), -INT8_C(  75),  INT8_C(  69),  INT8_C(  24),
        -INT8_C(  38),  INT8_C(  76), -INT8_C(  98),  INT8_C( 101),  INT8_C(   5),  INT8_C(  13),  INT8_C(  23),  INT8_C(  82),
         INT8_C( 100), -INT8_C(  65),  INT8_C(  13),  INT8_C(   4), -INT8_C(  64), -INT8_C(  40), -INT8_C(  70),  INT8_C(  69),
        -INT8_C( 107),  INT8_C(  31),  INT8_C(  74), -INT8_C(  69), -INT8_C(  80), -INT8_C(  54),  INT8_C(  75),  INT8_C(  92),
        -INT8_C( 103), -INT8_C(  20),  INT8_C(  10),  INT8_C(  80), -INT8_C(  95),  INT8_C(  79),  INT8_C( 104),  INT8_C( 124),
        -INT8_C( 101),  INT8_C(   6), -INT8_C(  31), -INT8_C(  96),  INT8_C(  19), -INT8_C(   7), -INT8_C(  13),  INT8_C( 119),
        -INT8_C(  72),  INT8_C(   0),  INT8_C( 123),  INT8_C( 120), -INT8_C(  40),  INT8_C(  54), -INT8_C(  66),  INT8_C( 109),
         INT8_C(  85),  INT8_C(   8),  INT8_C(  40),  INT8_C(   5), -INT8_C(  45),  INT8_C( 115),  INT8_C(  98),  INT8_C( 108) },
      {  INT8_C(  96),  INT8_C( 108), -INT8_C(  68),  INT8_C(   1), -INT8_C(  69),  INT8_C(  36),  INT8_C( 125),  INT8_C(  87),
         INT8_C(  42),  INT8_C(  95), -INT8_C(   9),  INT8_C(  61),  INT8_C(  88), -INT8_C(  22), -INT8_C(  75),  INT8_C(  16),
        -INT8_C(  22),  INT8_C(  48), -INT8_C( 120), -INT8_C(  61),  INT8_C( 102),  INT8_C(  70),  INT8_C(  48), -INT8_C(  68),
         INT8_C(  79),  INT8_C(  89), -INT8_C(  63),  INT8_C(  34), -INT8_C(  52),  INT8_C(  35), -INT8_C( 114),  INT8_C(  44),
        -INT8_C( 113),  INT8_C(  75),  INT8_C(  46),  INT8_C(  75),  INT8_C( 111), -INT8_C(  85), -INT8_C(  94), -INT8_C( 102),
         INT8_C(  10), -INT8_C( 103), -INT8_C(  41),  INT8_C(  98), -INT8_C( 124), -INT8_C( 116),  INT8_C( 114),  INT8_C( 110),
        -INT8_C(  67), -INT8_C(   5),  INT8_C(  49),  INT8_C(  35),  INT8_C(  65),  INT8_C(  98), -INT8_C(  33), -INT8_C( 112),
        -INT8_C(  69), -INT8_C(  95), -INT8_C(  78), -INT8_C( 121), -INT8_C(  60),  INT8_C(  65), -INT8_C(  76),  INT8_C(  84) },
      { -INT8_C(  84),  INT8_C(   0), -INT8_C(  49),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   1),
         INT8_C(   0),  INT8_C(   0), -INT8_C(  75),  INT8_C(  36),  INT8_C(  69),  INT8_C( 125),  INT8_C(   0),  INT8_C(  87),
         INT8_C( 100),  INT8_C(   0), -INT8_C(  65),  INT8_C(   0),  INT8_C(   0), -INT8_C( 120),  INT8_C(   4),  INT8_C(   0),
        -INT8_C(  64),  INT8_C(   0), -INT8_C(  40),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
         INT8_C(   0), -INT8_C( 113), -INT8_C(  20),  INT8_C(   0),  INT8_C(   0),  INT8_C(  46),  INT8_C(   0),  INT8_C(   0),
         INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C( 104),  INT8_C(   0),  INT8_C(   0), -INT8_C( 102),
         INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(  35),
         INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  66),  INT8_C(   0),  INT8_C(   0), -INT8_C( 112) } },
    { UINT64_C(10994766143362687628),
      { -INT8_C(  38),  INT8_C( 109), -INT8_C(   6),  INT8_C(  94), -INT8_C(   7),  INT8_C( 109), -INT8_C(  51), -INT8_C(  74),
         INT8_C( 104), -INT8_C(   2), -INT8_C(  38), -INT8_C(  87),  INT8_C(  96), -INT8_C(  71),  INT8_C(  58),  INT8_C(  27),
         INT8_C(  90), -INT8_C(  20), -INT8_C(  93),  INT8_C(  31),  INT8_C(  45),  INT8_C(  87),  INT8_C( 115), -INT8_C(  71),
         INT8_C(  57),  INT8_C(  18), -INT8_C(  75), -INT8_C(  58),  INT8_C(  83),  INT8_C(  74),  INT8_C(  94),  INT8_C(  45),
        -INT8_C(  73),  INT8_C(  89), -INT8_C( 116), -INT8_C(  79), -INT8_C(  58),  INT8_C(  89),  INT8_C( 103),  INT8_C(  46),
         INT8_C(  87),  INT8_C(  65), -INT8_C(  41), -INT8_C(  72), -INT8_C(   5),  INT8_C(  17), -INT8_C(  45),  INT8_C(  85),
        -INT8_C(   2),  INT8_C( 118),  INT8_C( 116),  INT8_C(  43), -INT8_C(  51), -INT8_C(  25), -INT8_C(  27),  INT8_C(   6),
        -INT8_C(   7), -INT8_C( 102), -INT8_C(  51),  INT8_C(  76), -INT8_C(  28),  INT8_C(  43),  INT8_C( 122), -INT8_C( 100) },
      { -INT8_C( 124),  INT8_C(   6),  INT8_C(  77),  INT8_C(  74),  INT8_C(  95), -INT8_C(  76),  INT8_C( 120), -INT8_C(  74),
        -INT8_C(  10),  INT8_C(  80),  INT8_C( 110), -INT8_C(  15),  INT8_C(  97),  INT8_C(  66),  INT8_C(  70),  INT8_C(  95),
        -INT8_C(  72), -INT8_C(  69), -INT8_C( 117), -INT8_C( 122), -INT8_C(  94),  INT8_C( 112), -INT8_C( 116), -INT8_C( 100),
         INT8_C(  10),  INT8_C(  89), -INT8_C(  24), -INT8_C(  18), -INT8_C( 123),  INT8_C(  98), -INT8_C( 118),  INT8_C(   9),
         INT8_C( 104), -INT8_C(  41),  INT8_C(  84), -INT8_C(  57), -INT8_C( 116), -INT8_C(  52),  INT8_C( 126), -INT8_C( 126),
         INT8_C(  28), -INT8_C(  20),  INT8_C( 115),  INT8_C( 126),  INT8_C(  46), -INT8_C(  71), -INT8_C(  35), -INT8_C(  25),
         INT8_C( 116),  INT8_C( 104),  INT8_C( 109),  INT8_C(  23), -INT8_C(  40), -INT8_C(   7), -INT8_C(  77), -INT8_C(  30),
         INT8_C(  83), -INT8_C( 101), -INT8_C(  47), -INT8_C(  40), -INT8_C(   2),  INT8_C(  91), -INT8_C(  31),  INT8_C( 102) },
      {  INT8_C(   0),  INT8_C(   0),  INT8_C( 109),  INT8_C(   6),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(  74),
         INT8_C(   0),  INT8_C(  95),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C( 120), -INT8_C(  74), -INT8_C(  74),
         INT8_C(  90), -INT8_C(  72), -INT8_C(  20), -INT8_C(  69), -INT8_C(  93),  INT8_C(   0),  INT8_C(   0), -INT8_C( 122),
         INT8_C(  45), -INT8_C(  94),  INT8_C(   0),  INT8_C( 112),  INT8_C( 115), -INT8_C( 116), -INT8_C(  71), -INT8_C( 100),
        -INT8_C(  73),  INT8_C(   0),  INT8_C(  89), -INT8_C(  41),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  57),
        -INT8_C(  58),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(  46),  INT8_C(   0),
        -INT8_C(   2),  INT8_C(   0),  INT8_C( 118),  INT8_C(   0),  INT8_C( 116),  INT8_C(   0),  INT8_C(   0),  INT8_C(  23),
         INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   7), -INT8_C(  27),  INT8_C(   0),  INT8_C(   0), -INT8_C(  30) } },
    { UINT64_C( 2180212822421419315),
      { -INT8_C( 104), -INT8_C(  76), -INT8_C( 100), -INT8_C(  57),  INT8_C( 109),  INT8_C( 122), -INT8_C(  82), -INT8_C(  30),
        -INT8_C(  30),  INT8_C(  27), -INT8_C(   7), -INT8_C(  69),  INT8_C(  20), -INT8_C(  84), -INT8_C(  99),  INT8_C( 103),
         INT8_C(  71),  INT8_C( 110),  INT8_C(  63),  INT8_C(  69), -INT8_C(  54),  INT8_C(  33), -INT8_C(  84), -INT8_C(   3),
         INT8_C(  86), -INT8_C(  38), -INT8_C(  68),  INT8_C(  88), -INT8_C( 122), -INT8_C(   3),  INT8_C( 119),  INT8_C(  30),
        -INT8_C(  79),  INT8_C(  19), -INT8_C(  27),  INT8_C(  30), -INT8_C( 115), -INT8_C( 109),  INT8_C(   0),  INT8_C( 112),
        -INT8_C(  82), -INT8_C(   7),  INT8_C(  43), -INT8_C(  61), -INT8_C(  91), -INT8_C(  56),  INT8_C(  42), -INT8_C(  19),
         INT8_C(  55),  INT8_C( 106),  INT8_C(  50),  INT8_C(   1), -INT8_C( 117), -INT8_C(  34), -INT8_C(   2), -INT8_C(  31),
        -INT8_C(  72), -INT8_C(  70),  INT8_C(  58),  INT8_C(  62), -INT8_C(  73), -INT8_C(  79),  INT8_C(  93),  INT8_C( 104) },
      { -INT8_C(  60),  INT8_C(  66), -INT8_C( 122),  INT8_C(  82), -INT8_C(  42), -INT8_C( 121), -INT8_C(  62), -INT8_C( 124),
             INT8_MIN, -INT8_C(  19),  INT8_C(  71),  INT8_C(  38), -INT8_C(  75),  INT8_C( 114),  INT8_C(  19), -INT8_C(  20),
        -INT8_C(  36),  INT8_C(  69), -INT8_C(  19),  INT8_C( 103),  INT8_C(  36), -INT8_C(  21),  INT8_C(  72), -INT8_C(  36),
        -INT8_C(  91), -INT8_C( 126),  INT8_C(  27),  INT8_C(  92),  INT8_C(  51),  INT8_C( 120), -INT8_C(  60), -INT8_C(   8),
        -INT8_C(  70),  INT8_C(  75),  INT8_C(  74), -INT8_C( 112), -INT8_C(  46),  INT8_C(  12),  INT8_C(  21),  INT8_C(  82),
        -INT8_C(   7),  INT8_C(  92),  INT8_C( 120), -INT8_C(  82), -INT8_C(  50), -INT8_C( 117), -INT8_C( 101), -INT8_C(  86),
        -INT8_C(  47), -INT8_C( 120),  INT8_C(  17), -INT8_C(  11),  INT8_C( 116),  INT8_C(  90), -INT8_C(  47),  INT8_C(  25),
        -INT8_C(  36), -INT8_C(  20),  INT8_C( 118),  INT8_C(  16),  INT8_C( 100),  INT8_C(  58),  INT8_C(   8),  INT8_C(  31) },
      { -INT8_C( 104), -INT8_C(  60),  INT8_C(   0),  INT8_C(   0), -INT8_C( 100), -INT8_C( 122),  INT8_C(   0),  INT8_C(   0),
         INT8_C( 109),  INT8_C(   0),  INT8_C( 122),  INT8_C(   0), -INT8_C(  82), -INT8_C(  62),  INT8_C(   0),  INT8_C(   0),
         INT8_C(   0), -INT8_C(  36),  INT8_C( 110),  INT8_C(  69),  INT8_C(   0), -INT8_C(  19),  INT8_C(   0),  INT8_C(   0),
        -INT8_C(  54),  INT8_C(  36),  INT8_C(  33), -INT8_C(  21), -INT8_C(  84),  INT8_C(  72),  INT8_C(   0), -INT8_C(  36),
         INT8_C(   0), -INT8_C(  70),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
         INT8_C(   0),  INT8_C(   0), -INT8_C( 109),  INT8_C(  12),  INT8_C(   0),  INT8_C(  21),  INT8_C(   0),  INT8_C(  82),
         INT8_C(  55),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   1),  INT8_C(   0),
         INT8_C(   0),  INT8_C( 116), -INT8_C(  34),  INT8_C(  90), -INT8_C(   2),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i a = simde_mm512_loadu_epi8(test_vec[i].a);
    simde__m512i b = simde_mm512_loadu_epi8(test_vec[i].b);
    simde__m512i r = simde_mm512_maskz_unpacklo_epi8(test_vec[i].k, a, b);
    simde_test_x86_assert_equal_i8x64(r, simde_mm512_loadu_epi8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask64 k = simde_test_x86_random_mmask64();
    simde__m512i a = simde_test_x86_random_i8x64();
    simde__m512i b = simde_test_x86_random_i8x64();
    simde__m512i r = simde_mm512_maskz_unpacklo_epi8(k, a, b);

    simde_test_x86_write_mmask64(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i8x64(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i8x64(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i8x64(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_mask_unpacklo_epi8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int8_t src[32];
    const simde__mmask32 k;
    const int8_t a[32];
    const int8_t b[32];
    const int8_t r[32];
  } test_vec[] = {
    { { -INT8_C( 106),  INT8_C(  16), -INT8_C(  79), -INT8_C(  40), -INT8_C( 117),  INT8_C(  42),  INT8_C(  11),  INT8_C(  68),
         INT8_C(  80), -INT8_C(  96), -INT8_C( 120),  INT8_C(  41),  INT8_C(  96), -INT8_C(  13),  INT8_C( 126),  INT8_C(  27),
         INT8_C( 104), -INT8_C(  46),  INT8_C(  64),  INT8_C(  30),  INT8_C(  56), -INT8_C( 119),  INT8_C(  13),  INT8_C(  40),
        -INT8_C( 115),  INT8_C(  49),  INT8_C( 114), -INT8_C(  59), -INT8_C(  36),  INT8_C(  58), -INT8_C(  10),  INT8_C( 114) },
      UINT32_C(3595216714),
      { -INT8_C(  47),  INT8_C(  86),  INT8_C(  26),  INT8_C(  33), -INT8_C(  10), -INT8_C(  93),  INT8_C(  74),  INT8_C(  86),
        -INT8_C( 106), -INT8_C(  55),  INT8_C( 114), -INT8_C(   2), -INT8_C( 101), -INT8_C(  78),  INT8_C(  29), -INT8_C(  45),
         INT8_C(  59),  INT8_C(  42), -INT8_C(   5), -INT8_C(  56),  INT8_C(  91),  INT8_C( 109), -INT8_C( 115),  INT8_C(  56),
        -INT8_C(  88), -INT8_C( 125), -INT8_C(  86), -INT8_C(  14),  INT8_C(  42), -INT8_C(  11), -INT8_C(  56), -INT8_C(   5) },
      {  INT8_C(  75), -INT8_C(  29),  INT8_C(  29),  INT8_C(  65), -INT8_C( 122),  INT8_C( 103), -INT8_C( 104),  INT8_C(  28),
         INT8_C(  48),  INT8_C(  10),  INT8_C(  27), -INT8_C(  53), -INT8_C(  68),  INT8_C(  56), -INT8_C(  98), -INT8_C(   9),
         INT8_C(  98), -INT8_C( 102), -INT8_C(  64), -INT8_C(  66),  INT8_C(   7),  INT8_C(  77), -INT8_C(  10), -INT8_C(  81),
        -INT8_C(  47), -INT8_C(  96), -INT8_C(  94), -INT8_C(   5), -INT8_C( 107),  INT8_C( 106), -INT8_C(   9), -INT8_C(  32) },
      { -INT8_C( 106),  INT8_C(  75), -INT8_C(  79), -INT8_C(  29), -INT8_C( 117),  INT8_C(  42),  INT8_C(  33),  INT8_C(  68),
        -INT8_C(  10), -INT8_C( 122), -INT8_C(  93),  INT8_C(  41),  INT8_C(  96), -INT8_C( 104),  INT8_C( 126),  INT8_C(  28),
         INT8_C( 104),  INT8_C(  98),  INT8_C(  64), -INT8_C( 102),  INT8_C(  56), -INT8_C( 119), -INT8_C(  56),  INT8_C(  40),
        -INT8_C( 115),  INT8_C(   7),  INT8_C( 109), -INT8_C(  59), -INT8_C( 115),  INT8_C(  58),  INT8_C(  56), -INT8_C(  81) } },
    { {  INT8_C(  77),  INT8_C(  20),  INT8_C(  34), -INT8_C(  45),  INT8_C( 123), -INT8_C(  70), -INT8_C(  16), -INT8_C(  84),
        -INT8_C(  60),  INT8_C(  11),  INT8_C( 119),      INT8_MIN,  INT8_C(  67),  INT8_C(  22),  INT8_C( 119), -INT8_C(  91),
        -INT8_C(  80),  INT8_C(  55),  INT8_C(  99), -INT8_C(  73), -INT8_C( 123),  INT8_C(  89),  INT8_C( 103),  INT8_C(  86),
        -INT8_C(   6),  INT8_C(   9),  INT8_C(  81), -INT8_C( 113),  INT8_C( 115),  INT8_C(  72),  INT8_C( 112), -INT8_C(  63) },
      UINT32_C(3633615452),
      {  INT8_C(  76), -INT8_C( 124), -INT8_C( 124),  INT8_C(  16), -INT8_C( 113), -INT8_C(   5), -INT8_C( 112), -INT8_C(  46),
         INT8_C(  17),  INT8_C(   7),  INT8_C( 120), -INT8_C(  63),  INT8_C(  63), -INT8_C(  37),  INT8_C( 121), -INT8_C(  60),
         INT8_C(  53), -INT8_C(  32),  INT8_C(  26),  INT8_C(  47), -INT8_C(  23),  INT8_C( 107), -INT8_C(  66),  INT8_C(  92),
        -INT8_C(  76),  INT8_C(  46),  INT8_C(  29),  INT8_C(  16), -INT8_C(  64), -INT8_C(  78), -INT8_C(  24),  INT8_C(  12) },
      {  INT8_C(  54),  INT8_C( 108),  INT8_C(  28), -INT8_C(  58),  INT8_C( 104), -INT8_C(  84), -INT8_C( 104),  INT8_C( 121),
        -INT8_C(  76),  INT8_C(  16),  INT8_C(  59), -INT8_C(  13), -INT8_C(  20), -INT8_C(  76), -INT8_C(  73),  INT8_C(  33),
        -INT8_C( 108), -INT8_C(  47),  INT8_C(  80),  INT8_C( 125),  INT8_C(  60),  INT8_C(  14), -INT8_C(  39), -INT8_C(  16),
         INT8_C(  61), -INT8_C(   9),  INT8_C(   1), -INT8_C(   3), -INT8_C(  87), -INT8_C(  23),  INT8_C(  10), -INT8_C(  33) },
      {  INT8_C(  77),  INT8_C(  20), -INT8_C( 124),  INT8_C( 108), -INT8_C( 124), -INT8_C(  70),  INT8_C(  16), -INT8_C(  84),
        -INT8_C(  60),  INT8_C( 104),  INT8_C( 119),      INT8_MIN, -INT8_C( 112),  INT8_C(  22),  INT8_C( 119),  INT8_C( 121),
        -INT8_C(  80),  INT8_C(  55), -INT8_C(  32), -INT8_C(  73),  INT8_C(  26),  INT8_C(  89),  INT8_C( 103),  INT8_C( 125),
        -INT8_C(   6),  INT8_C(   9),  INT8_C(  81),  INT8_C(  14), -INT8_C(  66),  INT8_C(  72),  INT8_C(  92), -INT8_C(  16) } },
    { {  INT8_C(  86),  INT8_C(  38), -INT8_C(  91), -INT8_C(  66), -INT8_C(  45),  INT8_C(  62),  INT8_C(  55), -INT8_C( 121),
         INT8_C(  78),  INT8_C( 114),  INT8_C( 122),  INT8_C(  58),  INT8_C(  38),  INT8_C(  49),  INT8_C(  91), -INT8_C(  70),
         INT8_C(   2), -INT8_C(  85),  INT8_C(  55),  INT8_C(  62), -INT8_C(  70),  INT8_C(  17),  INT8_C(  47), -INT8_C(   9),
         INT8_C(   8),  INT8_C(  48), -INT8_C(  12), -INT8_C(  79),  INT8_C(  25), -INT8_C(   2), -INT8_C( 112),  INT8_C( 111) },
      UINT32_C(4163712549),
      {  INT8_C( 116),  INT8_C( 101),      INT8_MAX, -INT8_C(  62), -INT8_C(  41), -INT8_C(   7), -INT8_C(   3), -INT8_C(   2),
         INT8_C(  42),  INT8_C(  88), -INT8_C(  72),  INT8_C(  44),  INT8_C(   4), -INT8_C(  16),  INT8_C( 106), -INT8_C(  66),
         INT8_C(   1), -INT8_C( 103), -INT8_C(  75),  INT8_C(   9), -INT8_C(  55), -INT8_C(  87), -INT8_C(  70), -INT8_C(  29),
        -INT8_C(  88),  INT8_C(  74),  INT8_C(  82), -INT8_C(  51),      INT8_MIN,      INT8_MIN, -INT8_C(  59), -INT8_C(  12) },
      { -INT8_C(  27),  INT8_C(  68), -INT8_C(  73), -INT8_C(  68),  INT8_C(  61), -INT8_C(  76), -INT8_C(  70),  INT8_C( 103),
         INT8_C(  12),  INT8_C( 115), -INT8_C( 109),  INT8_C(  16),  INT8_C(  99), -INT8_C(   3), -INT8_C(  50),  INT8_C( 100),
        -INT8_C( 105), -INT8_C( 125),  INT8_C( 109),  INT8_C(  96),  INT8_C(  45),  INT8_C(  39),  INT8_C(  67), -INT8_C(  43),
         INT8_C( 113), -INT8_C( 106), -INT8_C(  94), -INT8_C(  14),  INT8_C(  22),  INT8_C( 103), -INT8_C(  26), -INT8_C(   5) },
      {  INT8_C( 116),  INT8_C(  38),  INT8_C( 101), -INT8_C(  66), -INT8_C(  45), -INT8_C(  73),  INT8_C(  55), -INT8_C( 121),
         INT8_C(  78),  INT8_C(  61), -INT8_C(   7),  INT8_C(  58), -INT8_C(   3), -INT8_C(  70),  INT8_C(  91), -INT8_C(  70),
         INT8_C(   1), -INT8_C(  85), -INT8_C( 103), -INT8_C( 125), -INT8_C(  70),  INT8_C( 109),  INT8_C(  47), -INT8_C(   9),
         INT8_C(   8),  INT8_C(  48), -INT8_C(  12),  INT8_C(  39), -INT8_C(  70),  INT8_C(  67), -INT8_C(  29), -INT8_C(  43) } },
    { { -INT8_C(  85), -INT8_C(  99), -INT8_C(  73), -INT8_C(  24),  INT8_C(  81),  INT8_C( 114),  INT8_C(  79),  INT8_C(  94),
        -INT8_C(  27), -INT8_C(  30),  INT8_C( 110),  INT8_C(  72), -INT8_C(  33),  INT8_C(  61), -INT8_C(  84),  INT8_C( 118),
        -INT8_C(  64),  INT8_C(  25), -INT8_C(  41), -INT8_C(  19),  INT8_C(  64),  INT8_C(  26), -INT8_C(  62), -INT8_C(  79),
        -INT8_C(  80),  INT8_C( 100), -INT8_C(  93), -INT8_C(  58), -INT8_C(  53), -INT8_C( 118), -INT8_C(  63),  INT8_C( 118) },
      UINT32_C(2036234535),
      { -INT8_C(  21), -INT8_C(  83), -INT8_C(  41), -INT8_C(  48), -INT8_C( 113),  INT8_C(  69),  INT8_C(  24),  INT8_C( 111),
        -INT8_C( 126), -INT8_C(  60), -INT8_C(  27),  INT8_C(  67), -INT8_C(  35), -INT8_C(  68),  INT8_C(  48),  INT8_C(  29),
        -INT8_C(  41), -INT8_C(  13), -INT8_C(  50), -INT8_C( 121),  INT8_C(  87),  INT8_C( 114),  INT8_C(  78),  INT8_C(  35),
        -INT8_C(   4),  INT8_C(  15), -INT8_C( 103),  INT8_C(  35), -INT8_C( 120), -INT8_C(   8), -INT8_C( 100),  INT8_C( 115) },
      { -INT8_C(  91),  INT8_C( 115),  INT8_C(  67),  INT8_C(  53), -INT8_C(  71),  INT8_C(  91), -INT8_C(  92),  INT8_C(  59),
         INT8_C(  31), -INT8_C( 119),  INT8_C( 126), -INT8_C(   4),  INT8_C(  70), -INT8_C(  81),  INT8_C(  25),  INT8_C(  29),
        -INT8_C(  94), -INT8_C(  24), -INT8_C(  92), -INT8_C(   7),  INT8_C(  90), -INT8_C(  14),  INT8_C(  28),  INT8_C(  86),
         INT8_C(   2), -INT8_C(  74),  INT8_C( 121), -INT8_C( 118), -INT8_C(  82),  INT8_C(  22), -INT8_C(   2),  INT8_C(  83) },
      { -INT8_C(  21), -INT8_C(  91), -INT8_C(  83), -INT8_C(  24),  INT8_C(  81),  INT8_C(  67),  INT8_C(  79),  INT8_C(  94),
        -INT8_C( 113), -INT8_C(  30),  INT8_C( 110),  INT8_C(  91),  INT8_C(  24), -INT8_C(  92),  INT8_C( 111),  INT8_C( 118),
        -INT8_C(  64), -INT8_C(  94), -INT8_C(  13), -INT8_C(  24), -INT8_C(  50),  INT8_C(  26), -INT8_C( 121), -INT8_C(  79),
         INT8_C(  87),  INT8_C( 100), -INT8_C(  93), -INT8_C(  14),  INT8_C(  78),  INT8_C(  28),  INT8_C(  35),  INT8_C( 118) } },
    { { -INT8_C( 119),  INT8_C(  65), -INT8_C( 120),  INT8_C(  66), -INT8_C(  99),  INT8_C(  44),  INT8_C( 126), -INT8_C(  68),
        -INT8_C(  74), -INT8_C(   4), -INT8_C(  71), -INT8_C(   4), -INT8_C(  85), -INT8_C(  46),  INT8_C(  25),  INT8_C(  77),
        -INT8_C(  70), -INT8_C(  67),  INT8_C(  71),  INT8_C(  20), -INT8_C(  80),  INT8_C(  99),  INT8_C( 106), -INT8_C(  78),
         INT8_C(  25), -INT8_C(  28),  INT8_C(  60), -INT8_C(  57), -INT8_C(   6),  INT8_C(  58),  INT8_C(  27), -INT8_C( 125) },
      UINT32_C( 432448380),
      { -INT8_C(  48),  INT8_C(  68), -INT8_C(  43), -INT8_C( 122),  INT8_C(  64), -INT8_C( 114), -INT8_C( 126), -INT8_C(  20),
         INT8_C(  97), -INT8_C( 101),  INT8_C(  57),  INT8_C(  27),  INT8_C(  88),      INT8_MIN,  INT8_C(  48),  INT8_C(   8),
        -INT8_C(  28), -INT8_C( 102), -INT8_C(  70), -INT8_C(   3),  INT8_C( 126), -INT8_C(   9), -INT8_C(  59),  INT8_C( 120),
         INT8_C(  49), -INT8_C(  32), -INT8_C(   4), -INT8_C(  83), -INT8_C( 125), -INT8_C(  62), -INT8_C(  58),  INT8_C(  83) },
      {  INT8_C(   6), -INT8_C( 100), -INT8_C(  39),  INT8_C(  70),  INT8_C(  42),  INT8_C(  91),  INT8_C(  50), -INT8_C( 117),
        -INT8_C(  10),  INT8_C( 108), -INT8_C(  89),  INT8_C(  79), -INT8_C(  20), -INT8_C(  41),  INT8_C(  87), -INT8_C(  48),
         INT8_C( 113),  INT8_C(  18), -INT8_C(  50), -INT8_C(  16),  INT8_C(   9), -INT8_C( 109),  INT8_C( 104),  INT8_C(  58),
         INT8_C( 115),  INT8_C( 100), -INT8_C(  24), -INT8_C(  10),  INT8_C(  38), -INT8_C(  82),  INT8_C(  74),  INT8_C(  44) },
      { -INT8_C( 119),  INT8_C(  65),  INT8_C(  68), -INT8_C( 100), -INT8_C(  43), -INT8_C(  39), -INT8_C( 122), -INT8_C(  68),
         INT8_C(  64),  INT8_C(  42), -INT8_C(  71), -INT8_C(   4), -INT8_C(  85),  INT8_C(  50),  INT8_C(  25), -INT8_C( 117),
        -INT8_C(  70),  INT8_C( 113), -INT8_C( 102),  INT8_C(  20), -INT8_C(  80),  INT8_C(  99), -INT8_C(   3), -INT8_C(  16),
         INT8_C( 126), -INT8_C(  28),  INT8_C(  60), -INT8_C( 109), -INT8_C(  59),  INT8_C(  58),  INT8_C(  27), -INT8_C( 125) } },
    { {  INT8_C(  74),  INT8_C(  35),  INT8_C( 115),  INT8_C( 117),      INT8_MAX, -INT8_C(  91),  INT8_C(   0),  INT8_C( 117),
         INT8_C(  17), -INT8_C(  89), -INT8_C(  60), -INT8_C(   2),  INT8_C( 126),  INT8_C(  28), -INT8_C(  50), -INT8_C(  16),
         INT8_C(  46), -INT8_C( 100), -INT8_C(  32),  INT8_C(  55),  INT8_C(  47),  INT8_C(  72),  INT8_C( 113), -INT8_C(  94),
        -INT8_C(  83),  INT8_C(  89), -INT8_C( 103), -INT8_C(  45),  INT8_C(   8), -INT8_C(  29),  INT8_C(   0),  INT8_C(  82) },
      UINT32_C(2244440838),
      {  INT8_C(  24), -INT8_C(  56), -INT8_C(   5),  INT8_C(  42),  INT8_C( 111), -INT8_C(  65),  INT8_C(  40), -INT8_C(  18),
        -INT8_C(  37), -INT8_C(  10), -INT8_C(  34),  INT8_C(   9), -INT8_C( 109), -INT8_C(  66),  INT8_C(  64), -INT8_C(  62),
         INT8_C(   6), -INT8_C(  78),  INT8_C( 101), -INT8_C(  77),  INT8_C(  11), -INT8_C(   2), -INT8_C( 121),  INT8_C(  19),
        -INT8_C(  31), -INT8_C( 121),  INT8_C( 102), -INT8_C(  25), -INT8_C(   6),  INT8_C(  45),  INT8_C( 109),  INT8_C(  18) },
      { -INT8_C(  11),  INT8_C( 104),  INT8_C(  60),  INT8_C( 101),  INT8_C(  39),  INT8_C( 100),  INT8_C(  83),  INT8_C(   3),
         INT8_C(  91),  INT8_C(  49),  INT8_C(  12), -INT8_C(  18), -INT8_C(  17),  INT8_C(  77), -INT8_C(  80), -INT8_C(  11),
        -INT8_C(   1),  INT8_C(  21), -INT8_C(  87),  INT8_C(  10),  INT8_C(  19),  INT8_C(  48),  INT8_C(  30), -INT8_C(  12),
        -INT8_C(  73), -INT8_C( 124), -INT8_C(  36), -INT8_C(  79), -INT8_C(  79),  INT8_C(  73), -INT8_C(  61), -INT8_C(  89) },
      {  INT8_C(  74), -INT8_C(  11), -INT8_C(  56),  INT8_C( 117),      INT8_MAX, -INT8_C(  91),  INT8_C(   0),  INT8_C( 117),
         INT8_C( 111),  INT8_C(  39), -INT8_C(  60), -INT8_C(   2),  INT8_C(  40),  INT8_C(  83), -INT8_C(  18), -INT8_C(  16),
         INT8_C(   6), -INT8_C(   1), -INT8_C(  78),  INT8_C(  55),  INT8_C(  47),  INT8_C(  72), -INT8_C(  77),  INT8_C(  10),
         INT8_C(  11),  INT8_C(  89), -INT8_C(   2), -INT8_C(  45),  INT8_C(   8), -INT8_C(  29),  INT8_C(   0), -INT8_C(  12) } },
    { { -INT8_C(  79),  INT8_C(   0),  INT8_C(  12), -INT8_C(  40),  INT8_C( 100),  INT8_C(  95), -INT8_C(  37), -INT8_C(  65),
        -INT8_C( 112), -INT8_C(  24), -INT8_C(  83),      INT8_MAX,  INT8_C(  53),  INT8_C(  94),  INT8_C( 116),  INT8_C(  52),
         INT8_C( 115),  INT8_C(  29),  INT8_C(  62), -INT8_C( 121),  INT8_C(  77),  INT8_C(  92),  INT8_C( 123),  INT8_C(   4),
        -INT8_C(  32),  INT8_C(  87), -INT8_C(  75), -INT8_C( 110), -INT8_C(  96),  INT8_C( 121),  INT8_C(  57),  INT8_C(  81) },
      UINT32_C(3710535033),
      { -INT8_C(  92),  INT8_C(   5), -INT8_C(  99),  INT8_C(  52), -INT8_C(  19),  INT8_C(  74), -INT8_C(  77),  INT8_C(  34),
        -INT8_C(  88),  INT8_C(  39),  INT8_C(  86),  INT8_C(  28),  INT8_C(  69), -INT8_C( 107), -INT8_C(  93), -INT8_C( 110),
        -INT8_C(  15),  INT8_C(  30), -INT8_C( 105), -INT8_C(  46),  INT8_C( 118),  INT8_C(  76),  INT8_C( 100),  INT8_C(  22),
        -INT8_C(  59), -INT8_C(  99),  INT8_C( 104),  INT8_C(  62), -INT8_C(  30), -INT8_C( 110),  INT8_C(  28), -INT8_C( 122) },
      { -INT8_C( 105), -INT8_C(  71), -INT8_C(  70), -INT8_C( 123),  INT8_C(   3),  INT8_C( 109), -INT8_C(  89), -INT8_C(  84),
        -INT8_C( 108), -INT8_C(   2), -INT8_C(  56), -INT8_C(  39), -INT8_C( 109),  INT8_C( 107),  INT8_C( 108), -INT8_C( 124),
        -INT8_C( 119),  INT8_C(   3),  INT8_C(  86), -INT8_C(   1),  INT8_C(  79), -INT8_C(  70),  INT8_C(  22),  INT8_C(  21),
         INT8_C(  87),  INT8_C( 126),  INT8_C(  83),  INT8_C(  57),  INT8_C(  16),  INT8_C( 111), -INT8_C(  65), -INT8_C(  89) },
      { -INT8_C(  92),  INT8_C(   0),  INT8_C(  12), -INT8_C(  71), -INT8_C(  99), -INT8_C(  70),  INT8_C(  52), -INT8_C(  65),
        -INT8_C(  19), -INT8_C(  24),  INT8_C(  74),      INT8_MAX,  INT8_C(  53),  INT8_C(  94),  INT8_C(  34),  INT8_C(  52),
         INT8_C( 115), -INT8_C( 119),  INT8_C(  62),  INT8_C(   3),  INT8_C(  77),  INT8_C(  86),  INT8_C( 123),  INT8_C(   4),
         INT8_C( 118),  INT8_C(  87),  INT8_C(  76), -INT8_C(  70),  INT8_C( 100),  INT8_C( 121),  INT8_C(  22),  INT8_C(  21) } },
    { {  INT8_C(  40),  INT8_C( 121),  INT8_C(  44),  INT8_C(  44), -INT8_C(  26), -INT8_C(  44), -INT8_C(  40),  INT8_C( 123),
        -INT8_C(  46), -INT8_C(  96),  INT8_C(  84),  INT8_C( 101),  INT8_C(  11), -INT8_C(  64), -INT8_C(  23), -INT8_C( 108),
        -INT8_C(  61),  INT8_C(  64), -INT8_C( 108),  INT8_C(  19), -INT8_C(   6), -INT8_C(  86),  INT8_C(  40),  INT8_C(  82),
         INT8_C(  40),  INT8_C( 123), -INT8_C( 117),  INT8_C(  56), -INT8_C(  21),  INT8_C(  75), -INT8_C(  33),  INT8_C(  19) },
      UINT32_C(2873035972),
      { -INT8_C(  32),  INT8_C(  23),  INT8_C(  38), -INT8_C(  78), -INT8_C(  73),  INT8_C( 122),  INT8_C(  23), -INT8_C(  62),
         INT8_C(  59),  INT8_C(   0),  INT8_C(  87), -INT8_C(   2),  INT8_C(  64), -INT8_C(  21),  INT8_C(  17),  INT8_C(  59),
        -INT8_C( 107),  INT8_C(  57), -INT8_C( 115), -INT8_C(  67), -INT8_C(  75),  INT8_C(  24), -INT8_C(  11), -INT8_C(  96),
         INT8_C(  99), -INT8_C(  44), -INT8_C(  77),  INT8_C(  40), -INT8_C(  32), -INT8_C(  13), -INT8_C(  45), -INT8_C(  64) },
      {  INT8_C(  10), -INT8_C(   7),  INT8_C( 114), -INT8_C(  62),  INT8_C( 115), -INT8_C( 119), -INT8_C( 124), -INT8_C(  82),
        -INT8_C( 118), -INT8_C(  37), -INT8_C(  83), -INT8_C(  54), -INT8_C(  58), -INT8_C(  66),  INT8_C(   5),  INT8_C(  91),
        -INT8_C(   8), -INT8_C( 110),  INT8_C(  24), -INT8_C(  83), -INT8_C(  85),  INT8_C(  13),  INT8_C(  77),  INT8_C(  14),
        -INT8_C(  30),  INT8_C(   0),  INT8_C(  54), -INT8_C(  62), -INT8_C(  13),  INT8_C(   9), -INT8_C( 125), -INT8_C(   2) },
      {  INT8_C(  40),  INT8_C( 121),  INT8_C(  23),  INT8_C(  44), -INT8_C(  26), -INT8_C(  44), -INT8_C(  78), -INT8_C(  62),
        -INT8_C(  46), -INT8_C(  96),  INT8_C( 122), -INT8_C( 119),  INT8_C(  11), -INT8_C(  64), -INT8_C(  23), -INT8_C( 108),
        -INT8_C( 107), -INT8_C(   8),  INT8_C(  57), -INT8_C( 110), -INT8_C( 115),  INT8_C(  24),  INT8_C(  40),  INT8_C(  82),
        -INT8_C(  75), -INT8_C(  85), -INT8_C( 117),  INT8_C(  13), -INT8_C(  21),  INT8_C(  77), -INT8_C(  33),  INT8_C(  14) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256i src = simde_x_mm256_loadu_epi8(test_vec[i].src);
    simde__m256i a = simde_x_mm256_loadu_epi8(test_vec[i].a);
    simde__m256i b = simde_x_mm256_loadu_epi8(test_vec[i].b);
    simde__m256i r = simde_mm256_mask_unpacklo_epi8(src, test_vec[i].k, a, b);
    simde_test_x86_assert_equal_i8x32(r, simde_x_mm256_loadu_epi8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m256i src = simde_test_x86_random_i8x32();
    simde__mmask32 k = simde_test_x86_random_mmask32();
    simde__m256i a = simde_test_x86_random_i8x32();
    simde__m256i b = simde_test_x86_random_i8x32();
    simde__m256i r = simde_mm256_mask_unpacklo_epi8(src, k, a, b);

    simde_test_x86_write_i8x32(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask32(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i8x32(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i8x32(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i8x32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_maskz_unpacklo_epi8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask32 k;
    const int8_t a[32];
    const int8_t b[32];
    const int8_t r[32];
  } test_vec[] = {
    { UINT32_C(2819348023),
      {  INT8_C(  26), -INT8_C(  25), -INT8_C(  10), -INT8_C(  78),  INT8_C(  75),  INT8_C(  62), -INT8_C(  58),  INT8_C(  20),
        -INT8_C(  96), -INT8_C(  20),  INT8_C(  16), -INT8_C( 116),  INT8_C( 115),  INT8_C( 123), -INT8_C(  52),      INT8_MAX,
        -INT8_C(  37),  INT8_C(  53),  INT8_C(  98), -INT8_C(   1),  INT8_C(   0), -INT8_C(  13), -INT8_C(  76),  INT8_C(  36),
         INT8_C(  99), -INT8_C(  37), -INT8_C(  16), -INT8_C( 102), -INT8_C(  79), -INT8_C(   5),  INT8_C(  67), -INT8_C(  52) },
      { -INT8_C(  30),  INT8_C(  57),  INT8_C( 126),  INT8_C(  45),  INT8_C( 120),  INT8_C(  68),  INT8_C(  65),  INT8_C(  24),
         INT8_C(  49),  INT8_C(  82), -INT8_C(  92), -INT8_C(  92), -INT8_C(  51),  INT8_C( 112),  INT8_C(  36), -INT8_C(  87),
        -INT8_C(  91), -INT8_C( 122), -INT8_C(  88), -INT8_C(  90),  INT8_C( 121),  INT8_C(  92), -INT8_C(  54), -INT8_C(  35),
         INT8_C(  56), -INT8_C(  70),  INT8_C( 119), -INT8_C(  23), -INT8_C(  75), -INT8_C(  70), -INT8_C(  75), -INT8_C( 105) },
      {  INT8_C(  26), -INT8_C(  30), -INT8_C(  25),  INT8_C(   0), -INT8_C(  10),  INT8_C( 126),  INT8_C(   0),  INT8_C(   0),
         INT8_C(   0),  INT8_C( 120),  INT8_C(  62),  INT8_C(   0), -INT8_C(  58),  INT8_C(   0),  INT8_C(  20),  INT8_C(  24),
        -INT8_C(  37), -INT8_C(  91),  INT8_C(   0), -INT8_C( 122),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
         INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(  92),  INT8_C(   0), -INT8_C(  54),  INT8_C(   0), -INT8_C(  35) } },
    { UINT32_C(1824863220),
      {  INT8_C( 120),  INT8_C(   6), -INT8_C( 124), -INT8_C(  87),  INT8_C(  88),  INT8_C(  40),  INT8_C(  77),  INT8_C(  38),
        -INT8_C( 104),  INT8_C( 113), -INT8_C(  49),  INT8_C(  62), -INT8_C(   8),  INT8_C( 119), -INT8_C(  28),  INT8_C( 113),
        -INT8_C(  44), -INT8_C(  82),  INT8_C(  78),  INT8_C(  12),  INT8_C( 104), -INT8_C(  58), -INT8_C(  11),  INT8_C(  29),
             INT8_MIN, -INT8_C(  85), -INT8_C(  76),  INT8_C( 116), -INT8_C(  34),  INT8_C( 121), -INT8_C(  32),  INT8_C(  86) },
      {      INT8_MIN,  INT8_C( 100), -INT8_C(   1), -INT8_C(  40), -INT8_C( 116),  INT8_C(  77), -INT8_C(   2),  INT8_C(  37),
        -INT8_C(  66), -INT8_C(  51),  INT8_C(  99), -INT8_C(  74),  INT8_C(  69),  INT8_C(  71),  INT8_C(  40),  INT8_C(  25),
        -INT8_C(  11),  INT8_C( 118),  INT8_C(  37),  INT8_C(  93),  INT8_C(  60),  INT8_C(  26),  INT8_C( 122), -INT8_C(  67),
        -INT8_C(  59),  INT8_C(  46),  INT8_C(  49), -INT8_C(  92), -INT8_C(  88),  INT8_C(  18), -INT8_C(   6),  INT8_C(  40) },
      {  INT8_C(   0),  INT8_C(   0),  INT8_C(   6),  INT8_C(   0), -INT8_C( 124), -INT8_C(   1), -INT8_C(  87), -INT8_C(  40),
         INT8_C(  88), -INT8_C( 116),  INT8_C(   0),  INT8_C(   0),  INT8_C(  77), -INT8_C(   2),  INT8_C(   0),  INT8_C(   0),
        -INT8_C(  44),  INT8_C(   0), -INT8_C(  82),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(  12),  INT8_C(  93),
         INT8_C(   0),  INT8_C(   0), -INT8_C(  58),  INT8_C(  26),  INT8_C(   0),  INT8_C( 122),  INT8_C(  29),  INT8_C(   0) } },
    { UINT32_C(  50395766),
      {  INT8_C(  71), -INT8_C(   1),  INT8_C(  40),  INT8_C(   5), -INT8_C(  52), -INT8_C( 117), -INT8_C(  68),  INT8_C(  17),
        -INT8_C(  46), -INT8_C(  28),  INT8_C(  42), -INT8_C(  57),  INT8_C(  90),  INT8_C(  79),  INT8_C(  36), -INT8_C( 105),
         INT8_C( 106), -INT8_C(  98),  INT8_C(  84),  INT8_C(  47), -INT8_C(  52), -INT8_C( 123), -INT8_C(  45),  INT8_C( 116),
        -INT8_C( 105), -INT8_C(  50), -INT8_C( 100),  INT8_C(  14), -INT8_C(  56), -INT8_C(  99),  INT8_C(  17),  INT8_C(  15) },
      { -INT8_C( 100),  INT8_C(  57),  INT8_C(  20),  INT8_C( 104), -INT8_C(  60), -INT8_C(  48),  INT8_C( 122), -INT8_C( 106),
        -INT8_C(  76), -INT8_C(  92),  INT8_C(  93),  INT8_C(  15), -INT8_C(  12), -INT8_C( 127), -INT8_C(  90),  INT8_C(  94),
         INT8_C(  31), -INT8_C(   6), -INT8_C( 115), -INT8_C(  21),      INT8_MAX,  INT8_C(  97),  INT8_C(  96),  INT8_C(  23),
         INT8_C(  47), -INT8_C(   4),  INT8_C(  37), -INT8_C(   9), -INT8_C( 103),  INT8_C(  54),  INT8_C(   6),  INT8_C(  53) },
      {  INT8_C(   0), -INT8_C( 100), -INT8_C(   1),  INT8_C(   0),  INT8_C(  40),  INT8_C(  20),  INT8_C(   5),  INT8_C(   0),
         INT8_C(   0), -INT8_C(  60),  INT8_C(   0), -INT8_C(  48), -INT8_C(  68),  INT8_C( 122),  INT8_C(  17), -INT8_C( 106),
         INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
        -INT8_C(  52),      INT8_MAX,  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0) } },
    { UINT32_C( 865999471),
      { -INT8_C(  21),  INT8_C(  24), -INT8_C(  55), -INT8_C(  97), -INT8_C(  68),  INT8_C(  38), -INT8_C(  82), -INT8_C(  80),
        -INT8_C(  89),  INT8_C(  84),  INT8_C(  14), -INT8_C(  58),  INT8_C(  78), -INT8_C( 100), -INT8_C(  79), -INT8_C(  50),
        -INT8_C(   3),  INT8_C(  17), -INT8_C(  27),  INT8_C(  44),  INT8_C(  14),  INT8_C(  10),  INT8_C(  35), -INT8_C(  89),
         INT8_C(  64),  INT8_C(  41), -INT8_C(  35), -INT8_C(  81),  INT8_C(  67),  INT8_C( 123), -INT8_C(  30),  INT8_C(  46) },
      { -INT8_C( 109), -INT8_C(  85), -INT8_C(  50),  INT8_C(  79), -INT8_C(  47),  INT8_C( 124),  INT8_C(   0),  INT8_C( 120),
        -INT8_C(  47),  INT8_C(  14),  INT8_C(  62),  INT8_C(  31), -INT8_C(  86), -INT8_C(  17), -INT8_C(  19), -INT8_C(  89),
         INT8_C(   1), -INT8_C(  46), -INT8_C(  45),  INT8_C(  15), -INT8_C(  36), -INT8_C(  10), -INT8_C(  74),  INT8_C(  28),
         INT8_C(  31), -INT8_C( 109), -INT8_C(  53),  INT8_C(  99),  INT8_C(  14), -INT8_C(  83), -INT8_C( 111), -INT8_C(  95) },
      { -INT8_C(  21), -INT8_C( 109),  INT8_C(  24), -INT8_C(  85),  INT8_C(   0), -INT8_C(  50), -INT8_C(  97),  INT8_C(   0),
         INT8_C(   0), -INT8_C(  47),  INT8_C(   0),  INT8_C( 124), -INT8_C(  82),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
         INT8_C(   0),  INT8_C(   1),  INT8_C(  17), -INT8_C(  46), -INT8_C(  27),  INT8_C(   0),  INT8_C(   0),  INT8_C(  15),
         INT8_C(  14), -INT8_C(  36),  INT8_C(   0),  INT8_C(   0),  INT8_C(  35), -INT8_C(  74),  INT8_C(   0),  INT8_C(   0) } },
    { UINT32_C( 703684440),
      { -INT8_C(  36), -INT8_C(  15), -INT8_C(  95), -INT8_C(  83), -INT8_C(   1), -INT8_C(  33), -INT8_C(  52), -INT8_C(  86),
        -INT8_C(  49), -INT8_C(  70),  INT8_C(  81), -INT8_C(  48), -INT8_C( 116),  INT8_C(  37), -INT8_C(  33),  INT8_C( 105),
         INT8_C(  27), -INT8_C( 107), -INT8_C( 123),  INT8_C(  59),  INT8_C(  41),  INT8_C(  81), -INT8_C(  98),  INT8_C(  55),
        -INT8_C(   2),  INT8_C(  47), -INT8_C(  39),  INT8_C(  87), -INT8_C( 113), -INT8_C(  54),      INT8_MIN,  INT8_C( 107) },
      { -INT8_C(  69),  INT8_C(  34),  INT8_C(  24), -INT8_C(  70),  INT8_C(   1), -INT8_C(  28),  INT8_C( 100), -INT8_C(  48),
        -INT8_C(  98), -INT8_C(  74), -INT8_C(  96),  INT8_C(  43), -INT8_C(  37),      INT8_MAX, -INT8_C( 108), -INT8_C(  10),
         INT8_C(  21),  INT8_C(  25),  INT8_C(  49),  INT8_C(  62),  INT8_C( 106), -INT8_C(  49),  INT8_C( 117),  INT8_C( 105),
        -INT8_C(   1),  INT8_C(  78), -INT8_C(  64), -INT8_C( 114),  INT8_C(  24),  INT8_C(  64), -INT8_C(   7), -INT8_C(  45) },
      {  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(  34), -INT8_C(  95),  INT8_C(   0), -INT8_C(  83),  INT8_C(   0),
        -INT8_C(   1),  INT8_C(   1), -INT8_C(  33), -INT8_C(  28), -INT8_C(  52),  INT8_C(   0), -INT8_C(  86),  INT8_C(   0),
         INT8_C(  27),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C( 123),  INT8_C(  49),  INT8_C(  59),  INT8_C(  62),
         INT8_C(  41),  INT8_C(   0),  INT8_C(   0), -INT8_C(  49),  INT8_C(   0),  INT8_C( 117),  INT8_C(   0),  INT8_C(   0) } },
    { UINT32_C(1687032162),
      { -INT8_C(  11), -INT8_C(  14),  INT8_C(  52), -INT8_C( 108), -INT8_C(  88), -INT8_C(  43), -INT8_C(  65), -INT8_C( 125),
         INT8_C(  84),  INT8_C(  83),  INT8_C( 122),  INT8_C( 105),  INT8_C( 108), -INT8_C(  85), -INT8_C(  89), -INT8_C(  41),
         INT8_C( 123),  INT8_C(  29),  INT8_C(  64),  INT8_C( 122),  INT8_C( 107),  INT8_C(   0),  INT8_C(   8), -INT8_C( 124),
         INT8_C(  64),  INT8_C(   1),  INT8_C(  87), -INT8_C(  93),  INT8_C(  18), -INT8_C(  27),  INT8_C(   7),  INT8_C(   7) },
      { -INT8_C(  40),  INT8_C(  59), -INT8_C( 101),      INT8_MIN,  INT8_C(  16),  INT8_C(  90),  INT8_C(   4),  INT8_C( 101),
        -INT8_C(  83),  INT8_C( 126), -INT8_C(  50),  INT8_C(  26),  INT8_C(  41),  INT8_C( 118), -INT8_C(  15), -INT8_C(  92),
        -INT8_C( 109),  INT8_C(  49),  INT8_C(  30), -INT8_C(   2),  INT8_C(  49),  INT8_C(  38), -INT8_C( 126),  INT8_C( 113),
         INT8_C(  39), -INT8_C(  38),  INT8_C(  20),  INT8_C(  57), -INT8_C(  65),  INT8_C(  27),  INT8_C(  65), -INT8_C( 105) },
      {  INT8_C(   0), -INT8_C(  40),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C( 101), -INT8_C( 108),  INT8_C(   0),
        -INT8_C(  88),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  65),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
         INT8_C(   0), -INT8_C( 109),  INT8_C(  29),  INT8_C(  49),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   2),
         INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C( 126), -INT8_C( 124),  INT8_C(   0) } },
    { UINT32_C(1729682519),
      {  INT8_C(  55),  INT8_C(  28), -INT8_C(  52), -INT8_C(  28), -INT8_C( 102), -INT8_C( 101), -INT8_C(   2), -INT8_C(  61),
         INT8_C(  17), -INT8_C(  17),  INT8_C( 104), -INT8_C(  92),  INT8_C(  32), -INT8_C( 122), -INT8_C(  94),  INT8_C(  81),
        -INT8_C(  83),  INT8_C(  37), -INT8_C(  61), -INT8_C(  44), -INT8_C(   1), -INT8_C(  41),  INT8_C(  14), -INT8_C(  66),
        -INT8_C(  13),  INT8_C(  79),  INT8_C(  86),  INT8_C(  74),  INT8_C(  43),  INT8_C( 110), -INT8_C(  79),  INT8_C(  98) },
      { -INT8_C( 118),  INT8_C( 126),  INT8_C(  71),  INT8_C(  36),  INT8_C(  25),  INT8_C(  69), -INT8_C(  25),  INT8_C(  42),
         INT8_C(  53),  INT8_C(  79), -INT8_C(  50),  INT8_C(  85), -INT8_C(  42),  INT8_C( 112), -INT8_C(  89), -INT8_C( 125),
        -INT8_C( 107),  INT8_C( 106),  INT8_C(  87), -INT8_C( 108),  INT8_C(  65),  INT8_C( 101),  INT8_C(  83),  INT8_C(  52),
        -INT8_C(  76), -INT8_C(  87),  INT8_C( 126), -INT8_C(  32),  INT8_C(  23),  INT8_C(  48),  INT8_C(  66), -INT8_C(  95) },
      {  INT8_C(  55), -INT8_C( 118),  INT8_C(  28),  INT8_C(   0), -INT8_C(  52),  INT8_C(   0), -INT8_C(  28),  INT8_C(   0),
         INT8_C(   0),  INT8_C(   0), -INT8_C( 101),  INT8_C(  69), -INT8_C(   2),  INT8_C(   0), -INT8_C(  61),  INT8_C(  42),
         INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C( 106), -INT8_C(  61),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
        -INT8_C(   1),  INT8_C(  65), -INT8_C(  41),  INT8_C(   0),  INT8_C(   0),  INT8_C(  83), -INT8_C(  66),  INT8_C(   0) } },
    { UINT32_C(3351611822),
      { -INT8_C(  49), -INT8_C(  84), -INT8_C(  15),  INT8_C(   4), -INT8_C(   4), -INT8_C(  65),  INT8_C(  89), -INT8_C(  46),
         INT8_C(  47),  INT8_C(   0),  INT8_C(  85), -INT8_C(  59),  INT8_C( 106), -INT8_C(  84),  INT8_C(  89), -INT8_C(  84),
         INT8_C(  18), -INT8_C(  84), -INT8_C(  32), -INT8_C(  58),  INT8_C(  85),  INT8_C(  95), -INT8_C(  90),  INT8_C( 108),
        -INT8_C( 113), -INT8_C(  23),  INT8_C(  13),  INT8_C(  61),  INT8_C( 114), -INT8_C(  46),  INT8_C(   4),  INT8_C(  65) },
      {      INT8_MAX, -INT8_C(  11),  INT8_C(  69),  INT8_C( 123), -INT8_C(  76), -INT8_C(  97),  INT8_C(  77), -INT8_C(  29),
        -INT8_C(  97), -INT8_C(  94), -INT8_C(  88),  INT8_C(  10),  INT8_C(  78),  INT8_C(   2), -INT8_C(  74),  INT8_C(  96),
        -INT8_C(  82), -INT8_C( 106),  INT8_C(  39),  INT8_C(   4), -INT8_C(  11), -INT8_C(  51),  INT8_C( 112), -INT8_C( 124),
        -INT8_C(  74),  INT8_C( 126), -INT8_C(  63),  INT8_C(  41),  INT8_C(  80), -INT8_C(  59),  INT8_C( 106), -INT8_C(  49) },
      {  INT8_C(   0),      INT8_MAX, -INT8_C(  84), -INT8_C(  11),  INT8_C(   0),  INT8_C(  69),  INT8_C(   0),  INT8_C( 123),
        -INT8_C(   4),  INT8_C(   0),  INT8_C(   0), -INT8_C(  97),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  29),
         INT8_C(  18),  INT8_C(   0), -INT8_C(  84),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  58),  INT8_C(   4),
         INT8_C(  85), -INT8_C(  11),  INT8_C(  95),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C( 108), -INT8_C( 124) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256i a = simde_x_mm256_loadu_epi8(test_vec[i].a);
    simde__m256i b = simde_x_mm256_loadu_epi8(test_vec[i].b);
    simde__m256i r = simde_mm256_maskz_unpacklo_epi8(test_vec[i].k, a, b);
    simde_test_x86_assert_equal_i8x32(r, simde_x_mm256_loadu_epi8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask32 k = simde_test_x86_random_mmask32();
    simde__m256i a = simde_test_x86_random_i8x32();
    simde__m256i b = simde_test_x86_random_i8x32();
    simde__m256i r = simde_mm256_maskz_unpacklo_epi8(k, a, b);

    simde_test_x86_write_mmask32(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i8x32(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i8x32(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i8x32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_mask_unpacklo_epi8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int8_t src[16];
    const simde__mmask16 k;
    const int8_t a[16];
    const int8_t b[16];
    const int8_t r[16];
  } test_vec[] = {
    { {  INT8_C( 100), -INT8_C(  23), -INT8_C(  37),  INT8_C( 104),  INT8_C( 114),  INT8_C(  59), -INT8_C(   1), -INT8_C(   1),
         INT8_C(  12), -INT8_C(  62), -INT8_C(  69),  INT8_C(  65),  INT8_C( 124),  INT8_C( 125), -INT8_C(  33), -INT8_C(  12) },
      UINT16_C(11272),
      {  INT8_C( 120), -INT8_C( 122),  INT8_C( 121),  INT8_C(  50), -INT8_C(   2),  INT8_C(  98), -INT8_C(  51),  INT8_C(  66),
             INT8_MAX, -INT8_C(  67),  INT8_C(  18),  INT8_C(  57),      INT8_MIN,  INT8_C( 119),  INT8_C(  34),  INT8_C(  91) },
      { -INT8_C(  33), -INT8_C( 107), -INT8_C( 105), -INT8_C(  34), -INT8_C( 108), -INT8_C(  93), -INT8_C(  95),  INT8_C(  79),
        -INT8_C(  27),  INT8_C(  29), -INT8_C(  52), -INT8_C(  60),  INT8_C(  17), -INT8_C(  44), -INT8_C(  16), -INT8_C( 118) },
      {  INT8_C( 100), -INT8_C(  23), -INT8_C(  37), -INT8_C( 107),  INT8_C( 114),  INT8_C(  59), -INT8_C(   1), -INT8_C(   1),
         INT8_C(  12), -INT8_C(  62),  INT8_C(  98), -INT8_C(  93),  INT8_C( 124), -INT8_C(  95), -INT8_C(  33), -INT8_C(  12) } },
    { {  INT8_C(  91),  INT8_C( 105), -INT8_C(  68),  INT8_C(  89), -INT8_C(  53), -INT8_C( 118), -INT8_C( 101),  INT8_C(  74),
         INT8_C(  71), -INT8_C(  83), -INT8_C( 125), -INT8_C(  57),  INT8_C(  36), -INT8_C(  90),  INT8_C(  35),  INT8_C(   4) },
      UINT16_C(47675),
      { -INT8_C(  30), -INT8_C(  49),  INT8_C(  93), -INT8_C( 125),  INT8_C(  30),  INT8_C(  66), -INT8_C(  96), -INT8_C(  22),
         INT8_C(   7), -INT8_C(  78), -INT8_C(  66), -INT8_C(   9),  INT8_C(  60),  INT8_C(  25),  INT8_C(  97), -INT8_C(   8) },
      {  INT8_C( 114),  INT8_C(  44), -INT8_C( 126),  INT8_C(  13),  INT8_C( 119), -INT8_C(  54), -INT8_C(  69), -INT8_C(   6),
        -INT8_C( 111), -INT8_C(  33), -INT8_C(  96), -INT8_C(  76), -INT8_C(  29), -INT8_C(  37),  INT8_C( 110), -INT8_C(  58) },
      { -INT8_C(  30),  INT8_C( 114), -INT8_C(  68),  INT8_C(  44),  INT8_C(  93), -INT8_C( 126), -INT8_C( 101),  INT8_C(  74),
         INT8_C(  71),  INT8_C( 119), -INT8_C( 125), -INT8_C(  54), -INT8_C(  96), -INT8_C(  69),  INT8_C(  35), -INT8_C(   6) } },
    { { -INT8_C(  86), -INT8_C(  52),  INT8_C(  73), -INT8_C(  56),  INT8_C(  14), -INT8_C(  22), -INT8_C(  78),  INT8_C(  21),
        -INT8_C( 100),  INT8_C( 113),  INT8_C(  13), -INT8_C(  40), -INT8_C( 118),  INT8_C( 110), -INT8_C(  48), -INT8_C(   3) },
      UINT16_C(21402),
      {  INT8_C(  10),  INT8_C(  17),  INT8_C(  29), -INT8_C(  59),  INT8_C(  12), -INT8_C(  82), -INT8_C(  91), -INT8_C(  84),
         INT8_C(  99), -INT8_C( 120), -INT8_C( 120), -INT8_C(  47),  INT8_C(  78),  INT8_C(  50), -INT8_C(  99), -INT8_C( 104) },
      { -INT8_C(   5), -INT8_C(  84), -INT8_C( 126), -INT8_C(  83), -INT8_C(  63),  INT8_C(  30),  INT8_C(  30), -INT8_C(  50),
        -INT8_C(  10), -INT8_C(  87),  INT8_C(  60), -INT8_C(  58), -INT8_C(  90), -INT8_C(  41),  INT8_C(  25), -INT8_C(  80) },
      { -INT8_C(  86), -INT8_C(   5),  INT8_C(  73), -INT8_C(  84),  INT8_C(  29), -INT8_C(  22), -INT8_C(  78), -INT8_C(  83),
         INT8_C(  12), -INT8_C(  63),  INT8_C(  13), -INT8_C(  40), -INT8_C(  91),  INT8_C( 110), -INT8_C(  84), -INT8_C(   3) } },
    { { -INT8_C(  24),  INT8_C(  54),  INT8_C( 118), -INT8_C(  12), -INT8_C(  27),  INT8_C(  27), -INT8_C(  95),  INT8_C(  72),
        -INT8_C(  93),  INT8_C(  41),  INT8_C(  25), -INT8_C(  14),  INT8_C(  91), -INT8_C(  73), -INT8_C( 118),  INT8_C(  86) },
      UINT16_C( 3171),
      {  INT8_C(   4),  INT8_C(  36),  INT8_C(  42),  INT8_C(  34), -INT8_C(  13),  INT8_C(  32), -INT8_C(  53),  INT8_C(  47),
        -INT8_C(  26),  INT8_C( 113),  INT8_C(   6),  INT8_C(   0),  INT8_C(  34), -INT8_C(  17),  INT8_C(  54), -INT8_C( 104) },
      { -INT8_C(  29),  INT8_C(  27), -INT8_C(  77), -INT8_C( 124),  INT8_C(  99),  INT8_C(  86), -INT8_C(  83),  INT8_C( 125),
         INT8_C(  72),  INT8_C(   9),  INT8_C(  52), -INT8_C(  46),  INT8_C(  95), -INT8_C( 105), -INT8_C(  34),  INT8_C(  99) },
      {  INT8_C(   4), -INT8_C(  29),  INT8_C( 118), -INT8_C(  12), -INT8_C(  27), -INT8_C(  77),  INT8_C(  34),  INT8_C(  72),
        -INT8_C(  93),  INT8_C(  41),  INT8_C(  32),  INT8_C(  86),  INT8_C(  91), -INT8_C(  73), -INT8_C( 118),  INT8_C(  86) } },
    { { -INT8_C(  69),  INT8_C(   8), -INT8_C( 122), -INT8_C(  82),  INT8_C(  40),  INT8_C(  81), -INT8_C(  34),  INT8_C(  15),
        -INT8_C(  61), -INT8_C(  28),  INT8_C(  15), -INT8_C(  27), -INT8_C(  45),  INT8_C(  69),  INT8_C( 125), -INT8_C(  73) },
      UINT16_C(12385),
      {  INT8_C(  59), -INT8_C(  60), -INT8_C( 122), -INT8_C(  23),  INT8_C(  65), -INT8_C(  49), -INT8_C(  14),  INT8_C( 117),
        -INT8_C(  95),  INT8_C(  81),  INT8_C(  12),      INT8_MIN, -INT8_C(  75), -INT8_C(  56), -INT8_C( 120),  INT8_C(  59) },
      {  INT8_C( 118), -INT8_C(  79), -INT8_C( 116),  INT8_C(  84), -INT8_C(  64),  INT8_C(  79),  INT8_C(  57), -INT8_C(  49),
         INT8_C(  52),  INT8_C(  12),  INT8_C(  20), -INT8_C(  79), -INT8_C(  61),  INT8_C( 117), -INT8_C(  31), -INT8_C(   1) },
      {  INT8_C(  59),  INT8_C(   8), -INT8_C( 122), -INT8_C(  82),  INT8_C(  40), -INT8_C( 116), -INT8_C(  23),  INT8_C(  15),
        -INT8_C(  61), -INT8_C(  28),  INT8_C(  15), -INT8_C(  27), -INT8_C(  14),  INT8_C(  57),  INT8_C( 125), -INT8_C(  73) } },
    { {  INT8_C(  58),  INT8_C( 104), -INT8_C(  24),  INT8_C( 123),  INT8_C(  55), -INT8_C(  38), -INT8_C(  15), -INT8_C(  40),
         INT8_C(  43), -INT8_C(   3),  INT8_C(  88), -INT8_C(  32), -INT8_C(  59), -INT8_C(  31),  INT8_C(  27),  INT8_C(  60) },
      UINT16_C(43154),
      { -INT8_C( 112),  INT8_C(  82), -INT8_C(   9), -INT8_C(  55),  INT8_C(  33),  INT8_C(  44), -INT8_C(  42),  INT8_C(  53),
        -INT8_C(  35), -INT8_C( 103), -INT8_C(  85), -INT8_C(  65), -INT8_C( 104), -INT8_C(  27),  INT8_C(  39),      INT8_MIN },
      {  INT8_C(  96),  INT8_C(  94),  INT8_C(  90),  INT8_C(  81),  INT8_C(  54), -INT8_C( 122),  INT8_C(  79), -INT8_C( 113),
         INT8_C( 102),  INT8_C(  20),  INT8_C( 112), -INT8_C( 126),  INT8_C(  80),  INT8_C(   2),  INT8_C(  42), -INT8_C(  31) },
      {  INT8_C(  58),  INT8_C(  96), -INT8_C(  24),  INT8_C( 123), -INT8_C(   9), -INT8_C(  38), -INT8_C(  15),  INT8_C(  81),
         INT8_C(  43), -INT8_C(   3),  INT8_C(  88), -INT8_C( 122), -INT8_C(  59),  INT8_C(  79),  INT8_C(  27), -INT8_C( 113) } },
    { {  INT8_C(  84),  INT8_C(  33), -INT8_C(  86),  INT8_C( 117),  INT8_C(  77),      INT8_MIN, -INT8_C(  86),  INT8_C(  43),
         INT8_C(  26),  INT8_C(  85), -INT8_C(  22), -INT8_C(  78),  INT8_C(  58),  INT8_C(  17),  INT8_C(  51), -INT8_C( 101) },
      UINT16_C(36207),
      { -INT8_C(  20), -INT8_C(  91),  INT8_C(  19),  INT8_C(  59),  INT8_C(  52),  INT8_C( 122),  INT8_C(  80), -INT8_C(  92),
        -INT8_C(   4), -INT8_C(  96), -INT8_C(  90),  INT8_C(  38), -INT8_C( 127), -INT8_C(   6),  INT8_C(  71),  INT8_C(  44) },
      {  INT8_C( 111), -INT8_C( 107), -INT8_C(  84),  INT8_C(  26), -INT8_C(  64), -INT8_C(  58),  INT8_C( 111), -INT8_C(  86),
         INT8_C( 121), -INT8_C(  86), -INT8_C(  69), -INT8_C(  84),  INT8_C(  69),  INT8_C(  42),  INT8_C(  57),  INT8_C(  49) },
      { -INT8_C(  20),  INT8_C( 111), -INT8_C(  91), -INT8_C( 107),  INT8_C(  77), -INT8_C(  84),  INT8_C(  59),  INT8_C(  43),
         INT8_C(  52),  INT8_C(  85),  INT8_C( 122), -INT8_C(  58),  INT8_C(  58),  INT8_C(  17),  INT8_C(  51), -INT8_C(  86) } },
    { { -INT8_C(  49),  INT8_C(  77),  INT8_C( 109),  INT8_C(   4), -INT8_C(  57), -INT8_C(  67), -INT8_C(  88), -INT8_C(  61),
         INT8_C(  93),  INT8_C(  79), -INT8_C(  23), -INT8_C(  33),  INT8_C(  73),  INT8_C(  48),  INT8_C(  11), -INT8_C(  71) },
      UINT16_C(47045),
      { -INT8_C(  45), -INT8_C( 123),  INT8_C( 126),  INT8_C(  66),  INT8_C(  47), -INT8_C(   9), -INT8_C(  20), -INT8_C(  22),
        -INT8_C(  93),  INT8_C(  49),  INT8_C(  20), -INT8_C(  36),  INT8_C(  99), -INT8_C(  28),  INT8_C(  41), -INT8_C(  48) },
      { -INT8_C(  24), -INT8_C(  16), -INT8_C( 115), -INT8_C( 112), -INT8_C(  77), -INT8_C(  22), -INT8_C(  33), -INT8_C( 100),
        -INT8_C(  55),  INT8_C(  41), -INT8_C(  51), -INT8_C(  44), -INT8_C(  30), -INT8_C( 110), -INT8_C( 116), -INT8_C(  75) },
      { -INT8_C(  45),  INT8_C(  77), -INT8_C( 123),  INT8_C(   4), -INT8_C(  57), -INT8_C(  67),  INT8_C(  66), -INT8_C( 112),
         INT8_C(  47), -INT8_C(  77), -INT8_C(   9), -INT8_C(  33), -INT8_C(  20), -INT8_C(  33),  INT8_C(  11), -INT8_C( 100) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i src = simde_mm_loadu_epi8(test_vec[i].src);
    simde__m128i a = simde_mm_loadu_epi8(test_vec[i].a);
    simde__m128i b = simde_mm_loadu_epi8(test_vec[i].b);
    simde__m128i r = simde_mm_mask_unpacklo_epi8(src, test_vec[i].k, a, b);
    simde_test_x86_assert_equal_i8x16(r, simde_mm_loadu_epi8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i src = simde_test_x86_random_i8x16();
    simde__mmask16 k = simde_test_x86_random_mmask16();
    simde__m128i a = simde_test_x86_random_i8x16();
    simde__m128i b = simde_test_x86_random_i8x16();
    simde__m128i r = simde_mm_mask_unpacklo_epi8(src, k, a, b);

    simde_test_x86_write_i8x16(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask16(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i8x16(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i8x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i8x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_maskz_unpacklo_epi8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask16 k;
    const int8_t a[16];
    const int8_t b[16];
    const int8_t r[16];
  } test_vec[] = {
    { UINT16_C(35092),
      {  INT8_C(  18), -INT8_C(  56), -INT8_C(  76),  INT8_C(   9),  INT8_C(  99),  INT8_C(   2), -INT8_C(  25), -INT8_C(  58),
        -INT8_C(  55), -INT8_C( 116), -INT8_C(  58),  INT8_C(  81), -INT8_C(  87),  INT8_C(  90),  INT8_C(  69), -INT8_C(  43) },
      { -INT8_C(  50),  INT8_C(  20),  INT8_C( 115), -INT8_C( 114),  INT8_C( 121),  INT8_C( 105),  INT8_C(  25),  INT8_C(  77),
         INT8_C(  69), -INT8_C(  25), -INT8_C(  48),  INT8_C(  56),  INT8_C( 119), -INT8_C(  28), -INT8_C(  62), -INT8_C( 119) },
      {  INT8_C(   0),  INT8_C(   0), -INT8_C(  56),  INT8_C(   0), -INT8_C(  76),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
         INT8_C(  99),  INT8_C(   0),  INT8_C(   0),  INT8_C( 105),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(  77) } },
    { UINT16_C(30380),
      { -INT8_C( 109),  INT8_C(  16),  INT8_C( 120),  INT8_C( 122), -INT8_C(  42),  INT8_C(  66),  INT8_C(   6), -INT8_C( 100),
        -INT8_C( 109), -INT8_C(  80), -INT8_C(  10), -INT8_C(  40), -INT8_C( 123), -INT8_C(  59), -INT8_C(  20), -INT8_C(   8) },
      {  INT8_C(  83),  INT8_C( 101),  INT8_C(  98),  INT8_C( 108), -INT8_C(  78), -INT8_C(  89),  INT8_C(  83), -INT8_C( 126),
        -INT8_C(  32), -INT8_C(  53),  INT8_C( 103), -INT8_C(  94),  INT8_C(  84),  INT8_C(  19),  INT8_C(  24), -INT8_C(  25) },
      {  INT8_C(   0),  INT8_C(   0),  INT8_C(  16),  INT8_C( 101),  INT8_C(   0),  INT8_C(  98),  INT8_C(   0),  INT8_C( 108),
         INT8_C(   0), -INT8_C(  78),  INT8_C(  66),  INT8_C(   0),  INT8_C(   6),  INT8_C(  83), -INT8_C( 100),  INT8_C(   0) } },
    { UINT16_C(36899),
      {  INT8_C(  98), -INT8_C(   7), -INT8_C(  46),  INT8_C( 104), -INT8_C( 107),  INT8_C( 102),  INT8_C(  24), -INT8_C( 116),
         INT8_C(  62), -INT8_C(  99),  INT8_C(  81),  INT8_C(  43), -INT8_C( 106), -INT8_C(  92), -INT8_C( 112), -INT8_C(   8) },
      {  INT8_C(  16),  INT8_C(  67), -INT8_C(  97),  INT8_C(  99), -INT8_C(  59),      INT8_MAX,  INT8_C(  46),  INT8_C(  44),
         INT8_C(  33), -INT8_C( 125),  INT8_C(  64),  INT8_C(  57),  INT8_C( 106),  INT8_C(  99), -INT8_C(  54), -INT8_C(  52) },
      {  INT8_C(  98),  INT8_C(  16),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  97),  INT8_C(   0),  INT8_C(   0),
         INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(  24),  INT8_C(   0),  INT8_C(   0),  INT8_C(  44) } },
    { UINT16_C(40029),
      {  INT8_C(  53), -INT8_C(  14),  INT8_C(   2),  INT8_C(  77),  INT8_C( 126),  INT8_C(  65), -INT8_C(  21), -INT8_C(  49),
         INT8_C( 108), -INT8_C( 127),  INT8_C( 115), -INT8_C(   4),  INT8_C( 121), -INT8_C( 125),  INT8_C(  63),  INT8_C(  24) },
      { -INT8_C(  25),  INT8_C(   5), -INT8_C( 104),  INT8_C(  21),  INT8_C(  49), -INT8_C(  71), -INT8_C( 104),  INT8_C( 113),
        -INT8_C(  13),  INT8_C(   3), -INT8_C(  43), -INT8_C(  67), -INT8_C(  49),  INT8_C(  50),  INT8_C(  89),  INT8_C(   4) },
      {  INT8_C(  53),  INT8_C(   0), -INT8_C(  14),  INT8_C(   5),  INT8_C(   2),  INT8_C(   0),  INT8_C(  77),  INT8_C(   0),
         INT8_C(   0),  INT8_C(   0),  INT8_C(  65), -INT8_C(  71), -INT8_C(  21),  INT8_C(   0),  INT8_C(   0),  INT8_C( 113) } },
    { UINT16_C(23588),
      {  INT8_C(  82), -INT8_C(  93), -INT8_C(  99),  INT8_C(  61),  INT8_C( 114),  INT8_C(   9), -INT8_C(  66), -INT8_C(  26),
         INT8_C(   5),  INT8_C(  55),  INT8_C( 105),  INT8_C(  69),  INT8_C(  79),  INT8_C(  80),  INT8_C(  74), -INT8_C(  25) },
      {  INT8_C( 102),  INT8_C( 123), -INT8_C(  95), -INT8_C(   2), -INT8_C(  19), -INT8_C( 108),  INT8_C(   1), -INT8_C(  62),
         INT8_C(  81), -INT8_C(  47), -INT8_C(  12), -INT8_C(  86), -INT8_C(  43),  INT8_C(  24),  INT8_C(   6),  INT8_C(  39) },
      {  INT8_C(   0),  INT8_C(   0), -INT8_C(  93),  INT8_C(   0),  INT8_C(   0), -INT8_C(  95),  INT8_C(   0),  INT8_C(   0),
         INT8_C(   0),  INT8_C(   0),  INT8_C(   9), -INT8_C( 108), -INT8_C(  66),  INT8_C(   0), -INT8_C(  26),  INT8_C(   0) } },
    { UINT16_C(41915),
      {  INT8_C( 100),  INT8_C(  46), -INT8_C(  84),  INT8_C(  34),  INT8_C(  20), -INT8_C(  78),  INT8_C(  89),  INT8_C( 125),
        -INT8_C(   9), -INT8_C(  87), -INT8_C(  50),  INT8_C(  65), -INT8_C( 112),  INT8_C(  52), -INT8_C(  68),  INT8_C(  49) },
      {  INT8_C(  50), -INT8_C(  87), -INT8_C(  59),  INT8_C(  52),  INT8_C( 107),  INT8_C(  22),  INT8_C(   5),  INT8_C(  95),
        -INT8_C(  63), -INT8_C(  38),  INT8_C( 120), -INT8_C(  57),  INT8_C(   2),  INT8_C(  51),  INT8_C( 107),  INT8_C( 102) },
      {  INT8_C( 100),  INT8_C(  50),  INT8_C(   0), -INT8_C(  87), -INT8_C(  84), -INT8_C(  59),  INT8_C(   0),  INT8_C(  52),
         INT8_C(  20),  INT8_C( 107),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   5),  INT8_C(   0),  INT8_C(  95) } },
    { UINT16_C( 5985),
      { -INT8_C( 119),  INT8_C( 117), -INT8_C(  55), -INT8_C(  30), -INT8_C(  13), -INT8_C(  64), -INT8_C( 117), -INT8_C(  63),
         INT8_C(   1),  INT8_C(  28), -INT8_C(  11), -INT8_C(  66),  INT8_C(  77),  INT8_C(  39),  INT8_C( 103),  INT8_C(  19) },
      {  INT8_C(  91), -INT8_C(  45),  INT8_C(  41),  INT8_C(  96),  INT8_C(  50), -INT8_C(  22),  INT8_C(  59), -INT8_C(  86),
        -INT8_C(  78),  INT8_C(  61), -INT8_C(  34),  INT8_C(  29), -INT8_C(  93),  INT8_C(  63),  INT8_C(  52),  INT8_C(  44) },
      { -INT8_C( 119),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(  41), -INT8_C(  30),  INT8_C(   0),
        -INT8_C(  13),  INT8_C(  50), -INT8_C(  64),  INT8_C(   0), -INT8_C( 117),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0) } },
    { UINT16_C(65205),
      {  INT8_C(  15), -INT8_C(  88), -INT8_C(  66), -INT8_C( 102),  INT8_C( 105), -INT8_C(  64), -INT8_C(  74),  INT8_C(  94),
         INT8_C( 126),  INT8_C(   4), -INT8_C( 123), -INT8_C(  27),  INT8_C(  23), -INT8_C(  31), -INT8_C(  72),  INT8_C(  64) },
      {  INT8_C(  65), -INT8_C(  21),  INT8_C(  43),  INT8_C( 124), -INT8_C( 107), -INT8_C(  35), -INT8_C(  71),  INT8_C( 115),
        -INT8_C(   6),  INT8_C(  93), -INT8_C(  77),  INT8_C(  46), -INT8_C( 119),  INT8_C( 104),  INT8_C(  44), -INT8_C( 104) },
      {  INT8_C(  15),  INT8_C(   0), -INT8_C(  88),  INT8_C(   0), -INT8_C(  66),  INT8_C(  43),  INT8_C(   0),  INT8_C( 124),
         INT8_C(   0), -INT8_C( 107), -INT8_C(  64), -INT8_C(  35), -INT8_C(  74), -INT8_C(  71),  INT8_C(  94),  INT8_C( 115) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_x_mm_loadu_epi8(test_vec[i].a);
    simde__m128i b = simde_x_mm_loadu_epi8(test_vec[i].b);
    simde__m128i r = simde_mm_maskz_unpacklo_epi8(test_vec[i].k, a, b);
    simde_test_x86_assert_equal_i8x16(r, simde_x_mm_loadu_epi8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask16 k = simde_test_x86_random_mmask16();
    simde__m128i a = simde_test_x86_random_i8x16();
    simde__m128i b = simde_test_x86_random_i8x16();
    simde__m128i r = simde_mm_maskz_unpacklo_epi8(k, a, b);

    simde_test_x86_write_mmask16(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i8x16(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i8x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i8x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
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
test_simde_mm512_mask_unpacklo_epi16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int16_t src[32];
    const simde__mmask32 k;
    const int16_t a[32];
    const int16_t b[32];
    const int16_t r[32];
  } test_vec[] = {
    { {  INT16_C(  6059),  INT16_C( 27756), -INT16_C( 11949), -INT16_C(  4826),  INT16_C( 30524), -INT16_C( 14643),  INT16_C( 15717),  INT16_C( 26358),
         INT16_C(   801),  INT16_C( 16671), -INT16_C( 29551),  INT16_C( 12030),  INT16_C( 18500),  INT16_C( 18475), -INT16_C( 20743), -INT16_C( 23423),
        -INT16_C(  4411),  INT16_C(  6417),  INT16_C( 14271), -INT16_C(  1274), -INT16_C( 11345),  INT16_C(  5313), -INT16_C( 18671),  INT16_C( 12922),
        -INT16_C( 26182),  INT16_C( 19572),  INT16_C( 29222),  INT16_C( 27258), -INT16_C( 23110), -INT16_C( 19278),  INT16_C( 13139),  INT16_C(  6488) },
      UINT32_C(3778177313),
      {  INT16_C( 14497),  INT16_C( 20700), -INT16_C( 25077),  INT16_C(  7268), -INT16_C(  8363),  INT16_C(  4175), -INT16_C( 15496), -INT16_C( 24996),
        -INT16_C( 10699), -INT16_C(  4088), -INT16_C( 17797), -INT16_C( 12380), -INT16_C(   786),  INT16_C(  4072),  INT16_C(  6758),  INT16_C(  2032),
        -INT16_C( 12974),  INT16_C( 23895), -INT16_C( 17557), -INT16_C( 16262), -INT16_C( 13926),  INT16_C(  5072),  INT16_C( 11404), -INT16_C( 15951),
        -INT16_C( 17918),  INT16_C( 32433),  INT16_C( 21876),  INT16_C( 25165),  INT16_C( 13650), -INT16_C( 18318),  INT16_C( 25167), -INT16_C( 24129) },
      {  INT16_C(  5679), -INT16_C( 25858),  INT16_C( 30929),  INT16_C( 27739),  INT16_C( 11073), -INT16_C( 12929),  INT16_C( 12376),  INT16_C( 23183),
         INT16_C( 16618),  INT16_C( 24536),  INT16_C(  9622), -INT16_C(  5951),  INT16_C( 13146), -INT16_C( 22112),  INT16_C( 24470), -INT16_C( 15030),
         INT16_C( 18805),  INT16_C( 18016), -INT16_C( 17471),  INT16_C(   946),  INT16_C( 12774),  INT16_C( 16080),  INT16_C( 24418),  INT16_C( 19609),
         INT16_C( 29088),  INT16_C( 13995),  INT16_C( 28055), -INT16_C(  3810), -INT16_C( 16736),  INT16_C( 13979), -INT16_C(  6883), -INT16_C( 27908) },
      {  INT16_C( 14497),  INT16_C( 27756), -INT16_C( 11949), -INT16_C(  4826),  INT16_C( 30524),  INT16_C( 30929),  INT16_C( 15717),  INT16_C( 26358),
        -INT16_C( 10699),  INT16_C( 16671), -INT16_C( 29551),  INT16_C( 24536),  INT16_C( 18500),  INT16_C(  9622), -INT16_C( 12380), -INT16_C( 23423),
        -INT16_C(  4411),  INT16_C( 18805),  INT16_C( 14271), -INT16_C(  1274), -INT16_C( 17557), -INT16_C( 17471), -INT16_C( 18671),  INT16_C( 12922),
        -INT16_C( 17918),  INT16_C( 19572),  INT16_C( 29222),  INT16_C( 27258), -INT16_C( 23110),  INT16_C( 28055),  INT16_C( 25165), -INT16_C(  3810) } },
    { {  INT16_C( 23598), -INT16_C(  3880), -INT16_C( 29929), -INT16_C(   525), -INT16_C( 15428),  INT16_C(  7740), -INT16_C( 10973), -INT16_C( 15509),
         INT16_C(  5702), -INT16_C(  8711),  INT16_C(  6019),  INT16_C(  9423),  INT16_C( 27349), -INT16_C(  3494),  INT16_C( 22095),  INT16_C( 32388),
         INT16_C( 23730), -INT16_C( 13970),  INT16_C( 25063), -INT16_C( 23353),  INT16_C(   804),  INT16_C( 18370),  INT16_C( 11736),  INT16_C(  7690),
         INT16_C(   836), -INT16_C( 14340), -INT16_C( 13542), -INT16_C(  4117),  INT16_C( 17973), -INT16_C( 31519),  INT16_C( 26012),  INT16_C( 20226) },
      UINT32_C(2836951234),
      { -INT16_C(  8239), -INT16_C(  2483),  INT16_C(  4322), -INT16_C( 17859),  INT16_C( 18493), -INT16_C( 32295), -INT16_C( 10933),  INT16_C( 26185),
         INT16_C( 13472), -INT16_C( 10923),  INT16_C( 14202),  INT16_C(  5977),  INT16_C( 23708),  INT16_C( 24166),  INT16_C( 32460), -INT16_C( 25080),
         INT16_C( 21854),  INT16_C( 16532), -INT16_C( 11931), -INT16_C( 23557), -INT16_C( 11239),  INT16_C( 25892),  INT16_C( 28073),  INT16_C( 18891),
         INT16_C(  8354),  INT16_C(  7198),  INT16_C( 30551), -INT16_C(  3021), -INT16_C( 26157), -INT16_C( 24494),  INT16_C( 23064),  INT16_C( 30270) },
      { -INT16_C( 11600),  INT16_C(  5558), -INT16_C( 20061), -INT16_C( 16968), -INT16_C(  8827),  INT16_C( 11810), -INT16_C(  4790), -INT16_C(  5001),
        -INT16_C( 27379),  INT16_C( 25865),  INT16_C( 15373), -INT16_C(  8103), -INT16_C( 21546), -INT16_C(  4480), -INT16_C( 16890), -INT16_C( 18844),
         INT16_C(  6800),  INT16_C( 13515), -INT16_C( 31540),  INT16_C( 20977),  INT16_C(  4961), -INT16_C( 21632), -INT16_C(  2304),  INT16_C(  3480),
        -INT16_C( 24179), -INT16_C( 25998), -INT16_C( 13347), -INT16_C( 19590), -INT16_C(  1161),  INT16_C( 32161),  INT16_C(  1465),  INT16_C( 18995) },
      {  INT16_C( 23598), -INT16_C( 11600), -INT16_C( 29929), -INT16_C(   525), -INT16_C( 15428),  INT16_C(  7740), -INT16_C( 17859), -INT16_C( 16968),
         INT16_C(  5702), -INT16_C(  8711),  INT16_C(  6019),  INT16_C(  9423),  INT16_C( 14202),  INT16_C( 15373),  INT16_C(  5977),  INT16_C( 32388),
         INT16_C( 23730), -INT16_C( 13970),  INT16_C( 25063),  INT16_C( 13515), -INT16_C( 11931),  INT16_C( 18370),  INT16_C( 11736),  INT16_C(  7690),
         INT16_C(  8354), -INT16_C( 14340), -INT16_C( 13542), -INT16_C( 25998),  INT16_C( 17973), -INT16_C( 13347),  INT16_C( 26012), -INT16_C( 19590) } },
    { { -INT16_C(   480), -INT16_C(  4994),  INT16_C( 28546), -INT16_C(  7363), -INT16_C( 17022), -INT16_C( 32113),  INT16_C( 10165),  INT16_C( 17039),
         INT16_C(   712), -INT16_C( 23076),  INT16_C( 22221),  INT16_C( 17497), -INT16_C(  1455),  INT16_C(  3009), -INT16_C(  3072),  INT16_C(  8277),
        -INT16_C( 11277),  INT16_C( 29964),  INT16_C( 18754), -INT16_C( 15271), -INT16_C(  6137), -INT16_C( 17338), -INT16_C( 10993), -INT16_C( 10242),
        -INT16_C(  9513), -INT16_C( 23172), -INT16_C( 10960), -INT16_C( 32023), -INT16_C( 21552), -INT16_C( 12147), -INT16_C(  7521), -INT16_C( 27920) },
      UINT32_C(4144561333),
      {  INT16_C( 24901),  INT16_C( 19643),  INT16_C(   329),  INT16_C( 22536),  INT16_C(  1750), -INT16_C( 20945), -INT16_C( 21536),  INT16_C(  4435),
         INT16_C( 15489),  INT16_C( 20883),  INT16_C(  8423), -INT16_C( 30943),  INT16_C(  4354), -INT16_C( 18663),  INT16_C(  8461),  INT16_C( 21166),
         INT16_C( 27010), -INT16_C( 13409), -INT16_C( 22678),  INT16_C( 16419),  INT16_C( 21166), -INT16_C( 28946),  INT16_C( 16894),  INT16_C( 32671),
         INT16_C( 12926),  INT16_C( 26064), -INT16_C(  3758),  INT16_C( 21740),  INT16_C(  1538),  INT16_C(  3851), -INT16_C( 18137), -INT16_C( 21919) },
      {  INT16_C(    34), -INT16_C( 29579), -INT16_C( 26200),  INT16_C( 22221), -INT16_C( 17429), -INT16_C(  5660), -INT16_C( 31491),  INT16_C( 31592),
         INT16_C( 14518),  INT16_C(  2528), -INT16_C( 13015),  INT16_C( 11101),  INT16_C( 27091), -INT16_C(  1478), -INT16_C( 25566),  INT16_C( 17828),
         INT16_C(  6812),  INT16_C( 17617), -INT16_C( 24909), -INT16_C( 24934),  INT16_C( 32602),  INT16_C( 22408), -INT16_C(  4093), -INT16_C( 17966),
        -INT16_C( 19927),  INT16_C( 21186),  INT16_C(  8319),  INT16_C( 21118), -INT16_C( 18295), -INT16_C( 21683), -INT16_C(  3756), -INT16_C(  3600) },
      {  INT16_C( 24901), -INT16_C(  4994),  INT16_C( 19643), -INT16_C(  7363),  INT16_C(   329), -INT16_C( 26200),  INT16_C( 10165),  INT16_C( 22221),
         INT16_C(   712), -INT16_C( 23076),  INT16_C( 20883),  INT16_C(  2528),  INT16_C(  8423), -INT16_C( 13015), -INT16_C( 30943),  INT16_C( 11101),
        -INT16_C( 11277),  INT16_C( 29964),  INT16_C( 18754),  INT16_C( 17617), -INT16_C(  6137), -INT16_C( 17338), -INT16_C( 10993), -INT16_C( 10242),
         INT16_C( 12926), -INT16_C( 19927),  INT16_C( 26064), -INT16_C( 32023), -INT16_C(  3758),  INT16_C(  8319),  INT16_C( 21740),  INT16_C( 21118) } },
    { { -INT16_C( 15861), -INT16_C( 16843), -INT16_C( 12192), -INT16_C( 17827), -INT16_C(  6833),  INT16_C( 21009), -INT16_C(  7211), -INT16_C(   501),
        -INT16_C( 12650),  INT16_C(  5457), -INT16_C( 12306),  INT16_C( 30568), -INT16_C( 19065), -INT16_C(  9182),  INT16_C(  5030), -INT16_C( 19763),
         INT16_C(   725),  INT16_C( 13680), -INT16_C( 12846),  INT16_C(  8688),  INT16_C(   434), -INT16_C( 30605),  INT16_C( 32741),  INT16_C( 31622),
        -INT16_C( 10419),  INT16_C( 15248), -INT16_C(  1882),  INT16_C( 11954), -INT16_C( 11091),  INT16_C( 21514), -INT16_C( 10265), -INT16_C( 17402) },
      UINT32_C(2901571289),
      { -INT16_C(  7612), -INT16_C(  2355),  INT16_C( 16867), -INT16_C( 14210),  INT16_C(  1472),  INT16_C(  3395), -INT16_C( 11044), -INT16_C( 31928),
        -INT16_C(  1332),  INT16_C( 31409), -INT16_C( 17458), -INT16_C( 18738), -INT16_C( 11118),  INT16_C( 27506),  INT16_C( 25674), -INT16_C( 29161),
        -INT16_C(  6842),  INT16_C( 10885),  INT16_C(   806), -INT16_C(  6414),  INT16_C( 13832), -INT16_C(  6669),  INT16_C( 15114), -INT16_C( 10648),
         INT16_C(  6453),  INT16_C(   848),  INT16_C(  7892),  INT16_C( 26297),  INT16_C( 11506),  INT16_C( 15825), -INT16_C(  5744), -INT16_C( 10293) },
      {  INT16_C( 20686), -INT16_C(  3071), -INT16_C(  3244),  INT16_C( 23770), -INT16_C( 13015),  INT16_C( 13121), -INT16_C( 22264),  INT16_C( 15626),
         INT16_C( 23234), -INT16_C( 27072), -INT16_C(  1415),  INT16_C( 27644), -INT16_C( 12762), -INT16_C( 18776),  INT16_C( 29879), -INT16_C( 31347),
        -INT16_C( 28988),  INT16_C(  6265),  INT16_C( 21378), -INT16_C( 21643), -INT16_C( 18912),  INT16_C( 10463), -INT16_C(  5792),  INT16_C(  8805),
        -INT16_C( 23229), -INT16_C( 17223), -INT16_C( 19041), -INT16_C( 15064), -INT16_C( 12157),  INT16_C( 14972),  INT16_C(  2372),  INT16_C(  2495) },
      { -INT16_C(  7612), -INT16_C( 16843), -INT16_C( 12192), -INT16_C(  3071),  INT16_C( 16867),  INT16_C( 21009), -INT16_C( 14210),  INT16_C( 23770),
        -INT16_C( 12650),  INT16_C( 23234),  INT16_C( 31409),  INT16_C( 30568), -INT16_C( 17458), -INT16_C(  1415), -INT16_C( 18738), -INT16_C( 19763),
         INT16_C(   725), -INT16_C( 28988), -INT16_C( 12846),  INT16_C(  8688),  INT16_C(   806),  INT16_C( 21378), -INT16_C(  6414), -INT16_C( 21643),
        -INT16_C( 10419),  INT16_C( 15248),  INT16_C(   848), -INT16_C( 17223), -INT16_C( 11091), -INT16_C( 19041), -INT16_C( 10265), -INT16_C( 15064) } },
    { {  INT16_C( 14488),  INT16_C(  6689), -INT16_C( 26997), -INT16_C( 21563), -INT16_C( 23475), -INT16_C( 21037),  INT16_C( 14477), -INT16_C( 11825),
        -INT16_C( 30498),  INT16_C( 32141), -INT16_C( 19138), -INT16_C( 16061), -INT16_C( 16506), -INT16_C( 13572), -INT16_C( 17464),  INT16_C( 24787),
        -INT16_C(  2572),  INT16_C( 32634),  INT16_C( 16523), -INT16_C( 10197), -INT16_C(   284),  INT16_C( 29317),  INT16_C( 21815),  INT16_C(  5443),
        -INT16_C( 12067),  INT16_C(  7058), -INT16_C( 10874),  INT16_C(  3293), -INT16_C(  9836),  INT16_C( 24022), -INT16_C( 21868), -INT16_C( 30531) },
      UINT32_C( 705181855),
      {  INT16_C( 13176),  INT16_C( 23555), -INT16_C( 30671),  INT16_C( 26830),  INT16_C(  4573), -INT16_C( 17539),  INT16_C(  4322),  INT16_C( 26838),
        -INT16_C( 19483),  INT16_C( 31348),  INT16_C( 19084),  INT16_C(  8663), -INT16_C( 27404), -INT16_C( 27735), -INT16_C( 20020),  INT16_C( 17598),
        -INT16_C( 15900),  INT16_C(  5793),  INT16_C( 28489),  INT16_C( 10110), -INT16_C(   895),  INT16_C( 25570), -INT16_C( 18420), -INT16_C(  3637),
         INT16_C( 16236), -INT16_C(  1941),  INT16_C( 17033),  INT16_C( 32281), -INT16_C( 15401), -INT16_C( 23791), -INT16_C( 12428),  INT16_C( 23016) },
      { -INT16_C( 30320), -INT16_C(  9617), -INT16_C(  4616),  INT16_C( 30977), -INT16_C(  7191), -INT16_C(  2596), -INT16_C( 22629),  INT16_C(  2023),
         INT16_C( 21222),  INT16_C( 28672),  INT16_C(  6549),  INT16_C( 27886), -INT16_C(    36),  INT16_C( 20751), -INT16_C(  2097),  INT16_C( 24490),
         INT16_C(  6528),  INT16_C( 31033),  INT16_C( 14854), -INT16_C(  3854), -INT16_C( 12515), -INT16_C( 17947), -INT16_C( 13194),  INT16_C( 24000),
        -INT16_C( 16353), -INT16_C( 19251), -INT16_C( 17446), -INT16_C( 18912),  INT16_C( 12218), -INT16_C( 30457), -INT16_C( 20185), -INT16_C( 22551) },
      {  INT16_C( 13176), -INT16_C( 30320),  INT16_C( 23555), -INT16_C(  9617), -INT16_C( 30671), -INT16_C( 21037),  INT16_C( 14477),  INT16_C( 30977),
        -INT16_C( 30498),  INT16_C( 32141), -INT16_C( 19138),  INT16_C( 28672),  INT16_C( 19084),  INT16_C(  6549), -INT16_C( 17464),  INT16_C( 24787),
        -INT16_C(  2572),  INT16_C( 32634),  INT16_C( 16523),  INT16_C( 31033), -INT16_C(   284),  INT16_C( 29317),  INT16_C( 21815),  INT16_C(  5443),
        -INT16_C( 12067), -INT16_C( 16353), -INT16_C( 10874), -INT16_C( 19251), -INT16_C(  9836), -INT16_C( 17446), -INT16_C( 21868), -INT16_C( 30531) } },
    { {  INT16_C(  8906), -INT16_C( 12000),  INT16_C(  4957),  INT16_C( 31425), -INT16_C( 22814),  INT16_C( 22579), -INT16_C(  2957), -INT16_C( 27979),
        -INT16_C( 32076), -INT16_C( 29114),  INT16_C( 26173), -INT16_C(  1979),  INT16_C( 19605), -INT16_C( 17279),  INT16_C( 27390), -INT16_C( 14236),
        -INT16_C( 31603), -INT16_C(  5479),  INT16_C( 23191),  INT16_C( 31076), -INT16_C( 26623),  INT16_C( 29906), -INT16_C( 30836),  INT16_C( 16390),
         INT16_C( 19466),  INT16_C( 18383),  INT16_C(  5298),  INT16_C( 18239), -INT16_C( 16032),  INT16_C( 24068),  INT16_C( 26667), -INT16_C( 18393) },
      UINT32_C(2225258732),
      {  INT16_C(  1819),  INT16_C(  7421), -INT16_C( 12385),  INT16_C( 11152), -INT16_C( 27049),  INT16_C( 24939),  INT16_C( 15074), -INT16_C( 27480),
        -INT16_C(  6066), -INT16_C( 20517), -INT16_C(  8279), -INT16_C( 11251),  INT16_C( 13383),  INT16_C( 13453),  INT16_C( 12277),  INT16_C(  4280),
        -INT16_C( 19146), -INT16_C( 10964), -INT16_C( 17275), -INT16_C(  9216),  INT16_C( 27730),  INT16_C( 13373), -INT16_C(  6746), -INT16_C(  2616),
        -INT16_C( 23603),  INT16_C( 30372), -INT16_C( 20093), -INT16_C( 13749), -INT16_C( 10010), -INT16_C(  9218), -INT16_C( 18937),  INT16_C( 16107) },
      {  INT16_C(  5996), -INT16_C(  3821),  INT16_C(  5331),  INT16_C(  9677),  INT16_C(  2688),  INT16_C(  9817),  INT16_C(  8687), -INT16_C( 17125),
        -INT16_C( 16444),  INT16_C( 18227),  INT16_C( 32369),  INT16_C( 22290),  INT16_C(  4182),  INT16_C( 24114),  INT16_C(  7623),  INT16_C( 13212),
        -INT16_C( 20684),  INT16_C(  1828), -INT16_C(  3645),  INT16_C( 17196), -INT16_C( 31237), -INT16_C(  5526), -INT16_C( 31322),  INT16_C( 27303),
        -INT16_C(  9403), -INT16_C( 18766), -INT16_C( 15271), -INT16_C( 20467),  INT16_C( 16340), -INT16_C( 25842), -INT16_C( 21924), -INT16_C( 28466) },
      {  INT16_C(  8906), -INT16_C( 12000),  INT16_C(  7421), -INT16_C(  3821), -INT16_C( 22814),  INT16_C(  5331),  INT16_C( 11152),  INT16_C(  9677),
        -INT16_C( 32076), -INT16_C( 29114),  INT16_C( 26173), -INT16_C(  1979),  INT16_C( 19605), -INT16_C( 17279), -INT16_C( 11251),  INT16_C( 22290),
        -INT16_C( 31603), -INT16_C( 20684),  INT16_C( 23191),  INT16_C( 31076), -INT16_C( 26623), -INT16_C(  3645), -INT16_C( 30836),  INT16_C( 17196),
         INT16_C( 19466),  INT16_C( 18383),  INT16_C( 30372),  INT16_C( 18239), -INT16_C( 16032),  INT16_C( 24068),  INT16_C( 26667), -INT16_C( 20467) } },
    { { -INT16_C(  3495),  INT16_C(  7575), -INT16_C( 15389), -INT16_C(  8608), -INT16_C( 13752), -INT16_C(  4407),  INT16_C( 28752), -INT16_C( 27304),
         INT16_C(  2635), -INT16_C( 23221),  INT16_C( 22734), -INT16_C( 23723),  INT16_C( 25495), -INT16_C(  3266),  INT16_C(  3341),  INT16_C( 26243),
         INT16_C(  6911), -INT16_C(  7293), -INT16_C(  6947),  INT16_C(  9665), -INT16_C( 30034), -INT16_C(   493),  INT16_C( 27643),  INT16_C( 18067),
        -INT16_C(  8586),  INT16_C( 17643),  INT16_C( 16438), -INT16_C( 12825),  INT16_C(  9891), -INT16_C( 20288),  INT16_C( 17203),  INT16_C( 12823) },
      UINT32_C( 974494301),
      { -INT16_C( 10370),  INT16_C( 11615),  INT16_C( 29281),  INT16_C( 23595), -INT16_C( 16418),  INT16_C( 21667), -INT16_C( 29027), -INT16_C( 11112),
        -INT16_C( 32561),  INT16_C( 29345),  INT16_C( 25254), -INT16_C(  9949),  INT16_C( 15013),  INT16_C(   779),  INT16_C(  8660),  INT16_C( 21309),
        -INT16_C( 25096),  INT16_C( 22912), -INT16_C( 21745), -INT16_C(  4682),  INT16_C( 22890),  INT16_C(  2113), -INT16_C(  9497), -INT16_C( 18724),
         INT16_C( 32090),  INT16_C(    41),  INT16_C( 19679), -INT16_C( 31271), -INT16_C(  7034),  INT16_C( 23176), -INT16_C( 15099), -INT16_C(   595) },
      {  INT16_C( 11618),  INT16_C( 29271),  INT16_C(  3545),  INT16_C( 17247), -INT16_C( 24218),  INT16_C( 19787),  INT16_C( 10107), -INT16_C( 11004),
         INT16_C( 11685), -INT16_C( 31531), -INT16_C( 20871), -INT16_C(   247), -INT16_C( 28270), -INT16_C( 26535),  INT16_C(  1879), -INT16_C( 18027),
        -INT16_C(  5068),  INT16_C(  3371), -INT16_C( 29703),  INT16_C( 24401), -INT16_C( 25556), -INT16_C( 22611), -INT16_C( 20028),  INT16_C( 27004),
         INT16_C( 20958),  INT16_C( 22509), -INT16_C(  2049), -INT16_C( 28330), -INT16_C( 20600), -INT16_C(  8407), -INT16_C( 16458), -INT16_C(  5223) },
      { -INT16_C( 10370),  INT16_C(  7575),  INT16_C( 11615),  INT16_C( 29271),  INT16_C( 29281), -INT16_C(  4407),  INT16_C( 23595), -INT16_C( 27304),
         INT16_C(  2635),  INT16_C( 11685),  INT16_C( 22734), -INT16_C( 31531),  INT16_C( 25254), -INT16_C(  3266),  INT16_C(  3341), -INT16_C(   247),
        -INT16_C( 25096), -INT16_C(  7293),  INT16_C( 22912),  INT16_C(  9665), -INT16_C( 21745), -INT16_C(   493),  INT16_C( 27643),  INT16_C( 18067),
        -INT16_C(  8586),  INT16_C( 20958),  INT16_C( 16438),  INT16_C( 22509),  INT16_C( 19679), -INT16_C(  2049),  INT16_C( 17203),  INT16_C( 12823) } },
    { { -INT16_C( 15189), -INT16_C( 23048),  INT16_C( 18767),  INT16_C( 31492), -INT16_C( 19994), -INT16_C( 21982), -INT16_C( 24990),  INT16_C( 16403),
         INT16_C(   239), -INT16_C(  4457), -INT16_C(  4617), -INT16_C( 32640), -INT16_C( 22115),  INT16_C( 21343), -INT16_C(  1944),  INT16_C(  5182),
         INT16_C( 14269),  INT16_C(  3257), -INT16_C( 17024),  INT16_C( 26248), -INT16_C( 21905), -INT16_C( 12016),  INT16_C(  9033),  INT16_C( 14354),
        -INT16_C( 22236),  INT16_C(  6951), -INT16_C( 22633),  INT16_C( 13467), -INT16_C(  1200), -INT16_C( 18041), -INT16_C( 14605), -INT16_C( 20275) },
      UINT32_C(2109572861),
      {  INT16_C( 17731), -INT16_C( 19740), -INT16_C(  2833),  INT16_C( 14468), -INT16_C( 27112),  INT16_C( 15473), -INT16_C( 26561), -INT16_C( 10665),
        -INT16_C(  3265), -INT16_C( 28918), -INT16_C( 27922), -INT16_C(  7864),  INT16_C(  5464),  INT16_C( 21906),  INT16_C( 20379), -INT16_C(  8238),
        -INT16_C( 18796), -INT16_C( 31855),  INT16_C(  5547), -INT16_C( 15428),  INT16_C( 11691), -INT16_C(  5121),  INT16_C( 22213),  INT16_C(  1217),
        -INT16_C( 13239),  INT16_C( 14227), -INT16_C(  9122), -INT16_C( 18919), -INT16_C( 21519), -INT16_C( 29429), -INT16_C(  8710), -INT16_C( 29076) },
      { -INT16_C(   620),  INT16_C( 16145), -INT16_C( 13037), -INT16_C( 16894),  INT16_C(   506), -INT16_C( 16471),  INT16_C( 27479), -INT16_C( 24125),
         INT16_C( 22327), -INT16_C( 27176), -INT16_C(  3789),  INT16_C(  9291),  INT16_C( 22172), -INT16_C( 26959),  INT16_C(  7475), -INT16_C( 14556),
         INT16_C( 13851),  INT16_C( 11782),  INT16_C(  2051), -INT16_C(   276), -INT16_C( 27127),  INT16_C( 25021), -INT16_C( 32511),  INT16_C( 14338),
        -INT16_C(  9512),  INT16_C(  3021),  INT16_C(  6348),  INT16_C( 26671), -INT16_C(  7826), -INT16_C( 24065),  INT16_C(  9214),  INT16_C(  6505) },
      {  INT16_C( 17731), -INT16_C( 23048), -INT16_C( 19740),  INT16_C( 16145), -INT16_C(  2833), -INT16_C( 13037),  INT16_C( 14468), -INT16_C( 16894),
         INT16_C(   239),  INT16_C( 22327), -INT16_C( 28918), -INT16_C( 32640), -INT16_C( 22115),  INT16_C( 21343), -INT16_C(  1944),  INT16_C(  9291),
        -INT16_C( 18796),  INT16_C(  3257), -INT16_C( 31855),  INT16_C( 11782),  INT16_C(  5547),  INT16_C(  2051),  INT16_C(  9033), -INT16_C(   276),
        -INT16_C( 13239),  INT16_C(  6951),  INT16_C( 14227),  INT16_C(  3021), -INT16_C(  9122),  INT16_C(  6348), -INT16_C( 18919), -INT16_C( 20275) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i src = simde_mm512_loadu_epi16(test_vec[i].src);
    simde__m512i a = simde_mm512_loadu_epi16(test_vec[i].a);
    simde__m512i b = simde_mm512_loadu_epi16(test_vec[i].b);
    simde__m512i r = simde_mm512_mask_unpacklo_epi16(src, test_vec[i].k, a, b);
    simde_test_x86_assert_equal_i16x32(r, simde_mm512_loadu_epi16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m512i src = simde_test_x86_random_i16x32();
    simde__mmask32 k = simde_test_x86_random_mmask32();
    simde__m512i a = simde_test_x86_random_i16x32();
    simde__m512i b = simde_test_x86_random_i16x32();
    simde__m512i r = simde_mm512_mask_unpacklo_epi16(src, k, a, b);

    simde_test_x86_write_i16x32(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask32(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x32(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x32(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_maskz_unpacklo_epi16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask32 k;
    const int16_t a[32];
    const int16_t b[32];
    const int16_t r[32];
  } test_vec[] = {
    { UINT32_C(3133238717),
      {  INT16_C( 26447), -INT16_C( 14797), -INT16_C( 12530),  INT16_C( 13064), -INT16_C(  9779),  INT16_C(  7790), -INT16_C( 18728),  INT16_C(  9343),
        -INT16_C( 11264),  INT16_C( 17142), -INT16_C( 11172),  INT16_C( 32461), -INT16_C(  9863),  INT16_C( 13871), -INT16_C(  3770), -INT16_C( 26896),
         INT16_C(  9304),  INT16_C( 26460),  INT16_C( 25843), -INT16_C( 16230),  INT16_C(  2366),  INT16_C(  5854),  INT16_C( 23999), -INT16_C( 16582),
         INT16_C( 12337), -INT16_C( 29439), -INT16_C( 12796),  INT16_C( 32012),  INT16_C( 15272), -INT16_C(  4428), -INT16_C( 23508), -INT16_C( 31356) },
      { -INT16_C(  7992), -INT16_C( 17428), -INT16_C( 31163), -INT16_C( 31876),  INT16_C( 23183),  INT16_C( 20121), -INT16_C( 11080), -INT16_C(  5875),
         INT16_C(  3588),  INT16_C(  2423), -INT16_C( 31779), -INT16_C( 31354),  INT16_C( 15038), -INT16_C(  5261), -INT16_C(  1825), -INT16_C( 22672),
         INT16_C( 23768),  INT16_C(  7523), -INT16_C(  8222),  INT16_C( 29344),  INT16_C( 14905), -INT16_C(  3648), -INT16_C( 12786),  INT16_C(  4827),
         INT16_C( 21212), -INT16_C( 18149), -INT16_C( 23851), -INT16_C( 27842), -INT16_C( 19748), -INT16_C( 17538), -INT16_C(  4438), -INT16_C( 32157) },
      {  INT16_C( 26447),  INT16_C(     0), -INT16_C( 14797), -INT16_C( 17428), -INT16_C( 12530), -INT16_C( 31163),  INT16_C(     0), -INT16_C( 31876),
        -INT16_C( 11264),  INT16_C(     0),  INT16_C( 17142),  INT16_C(  2423),  INT16_C(     0), -INT16_C( 31779),  INT16_C( 32461),  INT16_C(     0),
         INT16_C(  9304),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C( 16230),  INT16_C( 29344),
         INT16_C(     0),  INT16_C( 21212),  INT16_C(     0), -INT16_C( 18149), -INT16_C( 12796), -INT16_C( 23851),  INT16_C(     0), -INT16_C( 27842) } },
    { UINT32_C( 765511242),
      {  INT16_C( 16549), -INT16_C(  8545),  INT16_C( 24442), -INT16_C( 30512), -INT16_C( 21715),  INT16_C(  2715), -INT16_C( 18691), -INT16_C( 11581),
         INT16_C(   600),  INT16_C( 13669), -INT16_C(  6988),  INT16_C( 24304),  INT16_C( 21458),  INT16_C(  7648), -INT16_C( 32743), -INT16_C( 16822),
        -INT16_C(  5695),  INT16_C( 15261),  INT16_C( 27976),  INT16_C( 30404),  INT16_C( 24344),  INT16_C(  5504),  INT16_C( 17173),  INT16_C( 28391),
         INT16_C( 19525), -INT16_C(  1629), -INT16_C( 27856),  INT16_C(   855),  INT16_C( 14567),  INT16_C(    32),  INT16_C( 27320),  INT16_C( 31167) },
      {  INT16_C( 23635), -INT16_C( 25675),  INT16_C( 31177), -INT16_C(  7919), -INT16_C( 28200), -INT16_C(  4618), -INT16_C(  8747),  INT16_C(  6747),
        -INT16_C(   471),  INT16_C( 23060),  INT16_C( 27538),  INT16_C( 31069),  INT16_C( 32163),  INT16_C( 23673),  INT16_C( 14567),  INT16_C( 15061),
        -INT16_C( 30060),  INT16_C( 24021), -INT16_C(  6397), -INT16_C(  9410),  INT16_C( 13432),  INT16_C( 19913),  INT16_C(  9233),  INT16_C( 15208),
         INT16_C( 31779), -INT16_C( 19051), -INT16_C(  3353), -INT16_C( 29906), -INT16_C( 22673),  INT16_C( 22247), -INT16_C( 17184),  INT16_C( 29840) },
      {  INT16_C(     0),  INT16_C( 23635),  INT16_C(     0), -INT16_C( 25675),  INT16_C(     0),  INT16_C(     0), -INT16_C( 30512),  INT16_C(     0),
         INT16_C(     0), -INT16_C(   471),  INT16_C( 13669),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C( 24304),  INT16_C( 31069),
         INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(  6397),  INT16_C(     0), -INT16_C(  9410),
         INT16_C( 19525),  INT16_C(     0), -INT16_C(  1629), -INT16_C( 19051),  INT16_C(     0), -INT16_C(  3353),  INT16_C(     0),  INT16_C(     0) } },
    { UINT32_C(1255302471),
      {  INT16_C(  4172), -INT16_C( 15066), -INT16_C(  4283),  INT16_C( 22034),  INT16_C( 31251),  INT16_C( 13969),  INT16_C(  9974), -INT16_C(  8469),
         INT16_C(  6424), -INT16_C( 30871),  INT16_C( 20673), -INT16_C( 24099),  INT16_C( 27916),  INT16_C( 21269), -INT16_C(  6189),  INT16_C(  8094),
        -INT16_C( 15112),  INT16_C( 15844), -INT16_C(  2125), -INT16_C( 14701),  INT16_C(  9585),  INT16_C( 26877), -INT16_C(  6069),  INT16_C( 25670),
        -INT16_C( 20734), -INT16_C( 15381), -INT16_C( 13825),  INT16_C(  2916),  INT16_C( 31030),  INT16_C(  2399), -INT16_C(   671),  INT16_C( 22825) },
      {  INT16_C(  3521),  INT16_C( 29846),  INT16_C( 10500),  INT16_C( 30266),  INT16_C( 14158), -INT16_C( 25890),  INT16_C(  9248),  INT16_C(  8958),
        -INT16_C(  5677), -INT16_C( 11547),  INT16_C( 18866), -INT16_C(  5667),  INT16_C( 15554),  INT16_C(  9202),  INT16_C(  6969), -INT16_C(  1412),
         INT16_C(  4649),  INT16_C( 11630), -INT16_C( 22212), -INT16_C( 30045), -INT16_C( 32288),  INT16_C(    36),  INT16_C(  8869),  INT16_C( 30754),
         INT16_C(  1804), -INT16_C( 16822),  INT16_C( 10320),  INT16_C(  5031), -INT16_C( 26012), -INT16_C( 25034), -INT16_C( 19531), -INT16_C(  8552) },
      {  INT16_C(  4172),  INT16_C(  3521), -INT16_C( 15066),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C( 22034),  INT16_C(     0),
         INT16_C(  6424),  INT16_C(     0), -INT16_C( 30871),  INT16_C(     0),  INT16_C(     0),  INT16_C( 18866), -INT16_C( 24099),  INT16_C(     0),
         INT16_C(     0),  INT16_C(  4649),  INT16_C(     0),  INT16_C(     0), -INT16_C(  2125),  INT16_C(     0), -INT16_C( 14701), -INT16_C( 30045),
         INT16_C(     0),  INT16_C(  1804),  INT16_C(     0), -INT16_C( 16822),  INT16_C(     0),  INT16_C(     0),  INT16_C(  2916),  INT16_C(     0) } },
    { UINT32_C(  17565637),
      { -INT16_C( 20560), -INT16_C( 28532), -INT16_C( 20431), -INT16_C( 10607), -INT16_C( 19501), -INT16_C(  8369), -INT16_C( 26181),  INT16_C(  2973),
         INT16_C( 17857),  INT16_C(  9758),  INT16_C( 21983), -INT16_C( 27452),  INT16_C( 23560), -INT16_C( 12941),  INT16_C( 32611),  INT16_C(  5071),
         INT16_C( 23342),  INT16_C( 24484),  INT16_C( 13579), -INT16_C(  8650), -INT16_C( 31256), -INT16_C( 23619),  INT16_C( 23326), -INT16_C(  8017),
        -INT16_C( 12896),  INT16_C( 32518), -INT16_C( 13790),  INT16_C( 10771), -INT16_C( 31194), -INT16_C( 29960), -INT16_C( 14587),  INT16_C( 13469) },
      {  INT16_C( 16674),  INT16_C( 11667), -INT16_C( 13962),  INT16_C( 24332), -INT16_C( 14002),  INT16_C( 27906), -INT16_C( 20188), -INT16_C( 15283),
         INT16_C( 21375), -INT16_C( 24253),  INT16_C( 22301),  INT16_C( 17356), -INT16_C( 15139), -INT16_C(  7219),  INT16_C( 27531), -INT16_C( 21225),
        -INT16_C( 21844),  INT16_C(  9178), -INT16_C(  6540), -INT16_C( 15742), -INT16_C( 31568), -INT16_C( 11217),  INT16_C( 31798), -INT16_C( 19047),
        -INT16_C(  9009), -INT16_C(  5034),  INT16_C(  8755),  INT16_C(  4400), -INT16_C(   538),  INT16_C( 29172),  INT16_C(  2920),  INT16_C(  5406) },
      { -INT16_C( 20560),  INT16_C(     0), -INT16_C( 28532),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C( 10607),  INT16_C( 24332),
         INT16_C( 17857),  INT16_C( 21375),  INT16_C(  9758),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
         INT16_C(     0),  INT16_C(     0),  INT16_C( 24484),  INT16_C(  9178),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
        -INT16_C( 12896),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
    { UINT32_C( 691599797),
      { -INT16_C( 17697), -INT16_C( 28692),  INT16_C(  6974),  INT16_C( 29796), -INT16_C(   616),  INT16_C( 26409), -INT16_C( 32551),  INT16_C(  3412),
        -INT16_C( 31582), -INT16_C( 30434),  INT16_C(  4737), -INT16_C(  5382),  INT16_C(  6429), -INT16_C( 11521),  INT16_C( 14098), -INT16_C(  3588),
        -INT16_C(  5903),  INT16_C( 12161), -INT16_C(  6909), -INT16_C( 25692), -INT16_C( 12830), -INT16_C( 17661),  INT16_C( 22349), -INT16_C(  3896),
        -INT16_C(  6437),  INT16_C( 23673),  INT16_C( 29688),  INT16_C(  5446),  INT16_C( 17804), -INT16_C( 24856), -INT16_C(  7044),  INT16_C( 28048) },
      {  INT16_C(  4556), -INT16_C( 12387),  INT16_C( 16886), -INT16_C( 10133),  INT16_C( 28174),  INT16_C( 23699),  INT16_C( 23749), -INT16_C( 24500),
        -INT16_C( 15038),  INT16_C( 15356),  INT16_C( 17208), -INT16_C( 15024),  INT16_C( 14472),  INT16_C(  1379), -INT16_C(  3300), -INT16_C(  6030),
         INT16_C(  3844), -INT16_C(  1352),  INT16_C(  9040),  INT16_C( 24530),  INT16_C( 26257),  INT16_C( 22203),  INT16_C(  1986),  INT16_C(  1270),
        -INT16_C(  3380),  INT16_C(  1087), -INT16_C( 28619), -INT16_C( 16695),  INT16_C( 11720), -INT16_C(  6717),  INT16_C( 13600),  INT16_C(  9677) },
      { -INT16_C( 17697),  INT16_C(     0), -INT16_C( 28692),  INT16_C(     0),  INT16_C(  6974),  INT16_C( 16886),  INT16_C(     0), -INT16_C( 10133),
        -INT16_C( 31582),  INT16_C(     0),  INT16_C(     0),  INT16_C( 15356),  INT16_C(  4737),  INT16_C( 17208), -INT16_C(  5382), -INT16_C( 15024),
         INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(  1352), -INT16_C(  6909),  INT16_C(  9040),  INT16_C(     0),  INT16_C(     0),
        -INT16_C(  6437),  INT16_C(     0),  INT16_C(     0),  INT16_C(  1087),  INT16_C(     0), -INT16_C( 28619),  INT16_C(     0),  INT16_C(     0) } },
    { UINT32_C(2501870917),
      { -INT16_C(  3416),  INT16_C( 14836), -INT16_C( 20648),  INT16_C(  6799), -INT16_C( 31306), -INT16_C( 32226),  INT16_C( 24184), -INT16_C( 21113),
         INT16_C( 20718), -INT16_C( 18837),  INT16_C( 11901), -INT16_C( 24933),  INT16_C( 26980), -INT16_C( 22077), -INT16_C(  7442), -INT16_C( 26818),
         INT16_C( 13268),  INT16_C( 11472),  INT16_C( 24802), -INT16_C( 26298),  INT16_C( 26085),  INT16_C( 23835), -INT16_C( 23869), -INT16_C( 20213),
         INT16_C( 30451),  INT16_C( 28775),  INT16_C(   933),  INT16_C(  2318), -INT16_C( 11924),  INT16_C( 23218), -INT16_C(  3916), -INT16_C( 30479) },
      { -INT16_C( 15837),  INT16_C(  1717), -INT16_C(  1246),  INT16_C(  1951), -INT16_C( 17824),  INT16_C(  9061),  INT16_C( 28765),  INT16_C( 20692),
         INT16_C( 15590), -INT16_C( 29760), -INT16_C( 12481), -INT16_C( 21612),  INT16_C( 18080),  INT16_C( 21509), -INT16_C(  2249),  INT16_C( 23261),
        -INT16_C( 27975), -INT16_C(  9376), -INT16_C(   115), -INT16_C(  4382),  INT16_C( 18362),  INT16_C(  5905), -INT16_C(  6473), -INT16_C( 24985),
         INT16_C( 10018),  INT16_C( 24873), -INT16_C( 16650), -INT16_C( 26868),  INT16_C(  4356),  INT16_C( 15339), -INT16_C( 14328), -INT16_C( 15978) },
      { -INT16_C(  3416),  INT16_C(     0),  INT16_C( 14836),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(  6799),  INT16_C(     0),
         INT16_C( 20718),  INT16_C(     0), -INT16_C( 18837),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C( 21612),
         INT16_C( 13268), -INT16_C( 27975),  INT16_C( 11472), -INT16_C(  9376),  INT16_C( 24802),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
         INT16_C( 30451),  INT16_C(     0),  INT16_C( 28775),  INT16_C(     0),  INT16_C(   933),  INT16_C(     0),  INT16_C(     0), -INT16_C( 26868) } },
    { UINT32_C(3902600794),
      {  INT16_C( 32758), -INT16_C( 20266), -INT16_C(  6202),  INT16_C( 32455),  INT16_C( 11981), -INT16_C(  4324),  INT16_C( 17749),  INT16_C( 19536),
         INT16_C( 23555),  INT16_C(  2275), -INT16_C( 12690),  INT16_C( 30275), -INT16_C(  9833), -INT16_C(  3784), -INT16_C( 11056), -INT16_C( 14631),
        -INT16_C( 20653),  INT16_C(  6774),  INT16_C( 15767),  INT16_C( 25752), -INT16_C( 19349), -INT16_C( 16300), -INT16_C( 23303), -INT16_C(   756),
        -INT16_C(  4351),  INT16_C( 28421),  INT16_C( 18622),  INT16_C( 21989),  INT16_C(  7458), -INT16_C(  3514),  INT16_C(  8434),  INT16_C( 17848) },
      {  INT16_C( 11983),  INT16_C( 26207), -INT16_C(  2197), -INT16_C( 10549),  INT16_C(  8107), -INT16_C( 23146), -INT16_C( 23613), -INT16_C( 15198),
        -INT16_C( 22638),  INT16_C( 20531),  INT16_C(  6639),  INT16_C(  4517), -INT16_C(  5066),  INT16_C( 10243), -INT16_C( 17652), -INT16_C(  9362),
        -INT16_C( 12823),  INT16_C( 21570),  INT16_C(  3525),  INT16_C( 28714), -INT16_C( 16084), -INT16_C(  4331), -INT16_C( 18588), -INT16_C(  2380),
        -INT16_C(  6306),  INT16_C( 20039), -INT16_C(  5120),  INT16_C( 14175),  INT16_C( 25560), -INT16_C(  7073), -INT16_C( 13026),  INT16_C(  2240) },
      {  INT16_C(     0),  INT16_C( 11983),  INT16_C(     0),  INT16_C( 26207), -INT16_C(  6202),  INT16_C(     0),  INT16_C( 32455),  INT16_C(     0),
         INT16_C(     0), -INT16_C( 22638),  INT16_C(  2275),  INT16_C(     0), -INT16_C( 12690),  INT16_C(  6639),  INT16_C( 30275),  INT16_C(  4517),
         INT16_C(     0),  INT16_C(     0),  INT16_C(  6774),  INT16_C( 21570),  INT16_C( 15767),  INT16_C(     0),  INT16_C(     0),  INT16_C( 28714),
         INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C( 20039),  INT16_C(     0), -INT16_C(  5120),  INT16_C( 21989),  INT16_C( 14175) } },
    { UINT32_C(1616642715),
      { -INT16_C( 30961),  INT16_C( 15312), -INT16_C(  6584), -INT16_C( 21462), -INT16_C(  8547), -INT16_C(   862), -INT16_C(  5690), -INT16_C( 14774),
        -INT16_C( 22058), -INT16_C( 20739),  INT16_C( 23820),  INT16_C( 11155),  INT16_C( 21290), -INT16_C( 15053), -INT16_C( 28843),  INT16_C( 25637),
        -INT16_C(  2538),  INT16_C( 24223), -INT16_C( 13860),  INT16_C( 30986), -INT16_C( 21080),  INT16_C( 28277), -INT16_C( 16490),  INT16_C( 27700),
         INT16_C( 12905),  INT16_C( 29979), -INT16_C( 20849), -INT16_C( 18016), -INT16_C( 11519),  INT16_C( 22143), -INT16_C( 23453),  INT16_C( 31162) },
      {  INT16_C( 22938),  INT16_C( 30424), -INT16_C(  7646), -INT16_C( 13584),  INT16_C( 25999),  INT16_C(  9784),  INT16_C( 27941), -INT16_C( 29038),
        -INT16_C( 21089),  INT16_C( 11779), -INT16_C( 23461),  INT16_C( 23783),  INT16_C( 26231), -INT16_C(  9550),  INT16_C( 27659), -INT16_C( 23212),
         INT16_C( 11461), -INT16_C(  6116),  INT16_C(  3086), -INT16_C( 24910), -INT16_C(  5263), -INT16_C( 26940),  INT16_C( 22104), -INT16_C(  2268),
         INT16_C( 10244),  INT16_C( 24357),  INT16_C(  3276),  INT16_C( 17340),  INT16_C( 28275),  INT16_C( 32286),  INT16_C( 29403), -INT16_C( 24541) },
      { -INT16_C( 30961),  INT16_C( 22938),  INT16_C(     0),  INT16_C( 30424), -INT16_C(  6584),  INT16_C(     0),  INT16_C(     0), -INT16_C( 13584),
         INT16_C(     0), -INT16_C( 21089),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
         INT16_C(     0),  INT16_C(     0),  INT16_C( 24223), -INT16_C(  6116), -INT16_C( 13860),  INT16_C(     0),  INT16_C( 30986),  INT16_C(     0),
         INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(  3276), -INT16_C( 18016),  INT16_C(     0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i a = simde_mm512_loadu_epi16(test_vec[i].a);
    simde__m512i b = simde_mm512_loadu_epi16(test_vec[i].b);
    simde__m512i r = simde_mm512_maskz_unpacklo_epi16(test_vec[i].k, a, b);
    simde_test_x86_assert_equal_i16x32(r, simde_mm512_loadu_epi16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask32 k = simde_test_x86_random_mmask32();
    simde__m512i a = simde_test_x86_random_i16x32();
    simde__m512i b = simde_test_x86_random_i16x32();
    simde__m512i r = simde_mm512_maskz_unpacklo_epi16(k, a, b);

    simde_test_x86_write_mmask32(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i16x32(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x32(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_mask_unpacklo_epi16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int16_t src[16];
    const simde__mmask16 k;
    const int16_t a[16];
    const int16_t b[16];
    const int16_t r[16];
  } test_vec[] = {
    { { -INT16_C( 10561), -INT16_C( 27874),  INT16_C( 25667),  INT16_C( 13281),  INT16_C( 21068), -INT16_C( 25055),  INT16_C( 22618),  INT16_C( 18925),
         INT16_C( 29118), -INT16_C( 32366), -INT16_C( 25758),  INT16_C( 10637), -INT16_C(   393), -INT16_C(  5835),  INT16_C( 32652),  INT16_C( 19333) },
      UINT16_C(42069),
      { -INT16_C( 26402), -INT16_C( 16632),  INT16_C( 21707), -INT16_C(  4846),  INT16_C( 27891), -INT16_C(  8123),  INT16_C(   949),  INT16_C( 18257),
        -INT16_C( 19580),  INT16_C(  4579),  INT16_C( 23260),  INT16_C(  4368), -INT16_C( 25533), -INT16_C( 13935), -INT16_C(  6425), -INT16_C( 14739) },
      {  INT16_C( 30079),  INT16_C( 19077), -INT16_C( 26678), -INT16_C( 17097),  INT16_C( 32004), -INT16_C( 18019), -INT16_C(  4480),  INT16_C(  1281),
        -INT16_C(  7006),  INT16_C( 32278),  INT16_C(  9790), -INT16_C( 32368),  INT16_C(  8642), -INT16_C( 21942), -INT16_C( 18681), -INT16_C( 31120) },
      { -INT16_C( 26402), -INT16_C( 27874), -INT16_C( 16632),  INT16_C( 13281),  INT16_C( 21707), -INT16_C( 25055), -INT16_C(  4846),  INT16_C( 18925),
         INT16_C( 29118), -INT16_C( 32366),  INT16_C(  4579),  INT16_C( 10637), -INT16_C(   393),  INT16_C(  9790),  INT16_C( 32652), -INT16_C( 32368) } },
    { { -INT16_C(  2771), -INT16_C(  2095),  INT16_C(  2189), -INT16_C( 28236),  INT16_C( 20869),  INT16_C(  1610),  INT16_C( 19263), -INT16_C(  7925),
         INT16_C(  8495),  INT16_C( 28000), -INT16_C(  4024),  INT16_C(  2799),  INT16_C( 14609),  INT16_C(  6324),  INT16_C(  9457),  INT16_C(  7839) },
      UINT16_C(28698),
      { -INT16_C( 22763), -INT16_C( 13960), -INT16_C(   456), -INT16_C( 32230),  INT16_C( 22788),  INT16_C(  4046), -INT16_C(   709), -INT16_C( 25808),
         INT16_C( 30827),  INT16_C( 23179), -INT16_C( 25469),  INT16_C( 14227), -INT16_C( 31564),  INT16_C( 21340),  INT16_C( 30370), -INT16_C( 18493) },
      {  INT16_C( 15389),  INT16_C( 21888), -INT16_C( 26054),  INT16_C( 16087), -INT16_C( 23052),  INT16_C( 12109),  INT16_C( 32163),  INT16_C(  3786),
         INT16_C( 22006),  INT16_C( 31080), -INT16_C(  1039), -INT16_C( 23120),  INT16_C(  3200),  INT16_C(  8953), -INT16_C( 17278), -INT16_C( 24614) },
      { -INT16_C(  2771),  INT16_C( 15389),  INT16_C(  2189),  INT16_C( 21888), -INT16_C(   456),  INT16_C(  1610),  INT16_C( 19263), -INT16_C(  7925),
         INT16_C(  8495),  INT16_C( 28000), -INT16_C(  4024),  INT16_C(  2799), -INT16_C( 25469), -INT16_C(  1039),  INT16_C( 14227),  INT16_C(  7839) } },
    { {  INT16_C( 23288),  INT16_C( 13044), -INT16_C( 13067), -INT16_C(  5776), -INT16_C( 17039),  INT16_C(  5144), -INT16_C(  7621),  INT16_C( 12578),
        -INT16_C( 30153),  INT16_C( 10410),  INT16_C( 23174),  INT16_C(  1741), -INT16_C( 14745), -INT16_C(  5848),  INT16_C(   643),  INT16_C( 31625) },
      UINT16_C(32093),
      {  INT16_C( 21166),  INT16_C(  7753), -INT16_C( 17605),  INT16_C( 21468),  INT16_C(  6095), -INT16_C(  3531),  INT16_C( 27720), -INT16_C(  3460),
         INT16_C(   660),  INT16_C( 24908), -INT16_C( 19704),  INT16_C( 12584), -INT16_C( 21603),  INT16_C(  9779), -INT16_C( 28634), -INT16_C( 11101) },
      { -INT16_C(  4638),  INT16_C(  7667), -INT16_C( 12376),  INT16_C( 30576), -INT16_C( 23066),  INT16_C( 11881), -INT16_C(  6639), -INT16_C( 23264),
         INT16_C( 27880), -INT16_C(  3833),  INT16_C( 12064), -INT16_C( 17118),  INT16_C( 21978),  INT16_C(   227), -INT16_C( 31002), -INT16_C( 14123) },
      {  INT16_C( 21166),  INT16_C( 13044),  INT16_C(  7753),  INT16_C(  7667), -INT16_C( 17605),  INT16_C(  5144),  INT16_C( 21468),  INT16_C( 12578),
         INT16_C(   660),  INT16_C( 10410),  INT16_C( 24908), -INT16_C(  3833), -INT16_C( 19704),  INT16_C( 12064),  INT16_C( 12584),  INT16_C( 31625) } },
    { { -INT16_C( 14221),  INT16_C(  7142),  INT16_C( 22167),  INT16_C( 32147), -INT16_C(   772),  INT16_C(  3499), -INT16_C( 13342), -INT16_C( 13389),
        -INT16_C( 17865),  INT16_C( 22460), -INT16_C(  8471), -INT16_C( 15596), -INT16_C(  2253),  INT16_C(  6595), -INT16_C( 26498), -INT16_C(  3614) },
      UINT16_C(51296),
      { -INT16_C(  2291), -INT16_C( 24546),  INT16_C(  6772),  INT16_C(  8092),  INT16_C( 32552), -INT16_C(  9238),  INT16_C(  8778),  INT16_C(  1685),
         INT16_C( 32377), -INT16_C( 28956),  INT16_C(  5953),  INT16_C(  1157),  INT16_C(   817),  INT16_C(  5021), -INT16_C(   523),  INT16_C(   731) },
      { -INT16_C(  1547),  INT16_C( 27042),  INT16_C( 15892),  INT16_C( 15497),  INT16_C( 29629),  INT16_C(  1815), -INT16_C( 21355),  INT16_C(  3853),
        -INT16_C(  3798),  INT16_C( 27549),  INT16_C(  8713),  INT16_C( 14959),  INT16_C(  3110),  INT16_C(  6989),  INT16_C( 10250), -INT16_C(   227) },
      { -INT16_C( 14221),  INT16_C(  7142),  INT16_C( 22167),  INT16_C( 32147), -INT16_C(   772),  INT16_C( 15892),  INT16_C(  8092), -INT16_C( 13389),
        -INT16_C( 17865),  INT16_C( 22460), -INT16_C(  8471),  INT16_C( 27549), -INT16_C(  2253),  INT16_C(  6595),  INT16_C(  1157),  INT16_C( 14959) } },
    { { -INT16_C( 16607),  INT16_C( 13672), -INT16_C(  3587), -INT16_C( 17551), -INT16_C( 30619), -INT16_C(  1342), -INT16_C( 12236),  INT16_C( 24073),
        -INT16_C( 22847), -INT16_C( 13623),  INT16_C( 14793), -INT16_C(  4348),  INT16_C( 20805),  INT16_C( 20234),  INT16_C( 10105), -INT16_C( 25778) },
      UINT16_C(47078),
      { -INT16_C(  7216),  INT16_C( 17064),  INT16_C(  3486),  INT16_C( 25034), -INT16_C(   248),  INT16_C(  4401), -INT16_C(  3491),  INT16_C( 10168),
        -INT16_C( 32323), -INT16_C( 16032), -INT16_C( 23184),  INT16_C( 31251), -INT16_C( 29451),  INT16_C( 17313), -INT16_C( 30937), -INT16_C(  1798) },
      { -INT16_C( 23702),  INT16_C(  2362),  INT16_C(  1200), -INT16_C( 18326), -INT16_C( 25853),  INT16_C( 25034), -INT16_C( 32115),  INT16_C( 19080),
        -INT16_C(  6141),  INT16_C( 29452),  INT16_C(  8077), -INT16_C( 32019), -INT16_C( 29013), -INT16_C( 11322), -INT16_C( 16363),  INT16_C( 32715) },
      { -INT16_C( 16607), -INT16_C( 23702),  INT16_C( 17064), -INT16_C( 17551), -INT16_C( 30619),  INT16_C(  1200),  INT16_C( 25034), -INT16_C( 18326),
        -INT16_C( 32323), -INT16_C(  6141), -INT16_C( 16032), -INT16_C(  4348), -INT16_C( 23184),  INT16_C(  8077),  INT16_C( 10105), -INT16_C( 32019) } },
    { {  INT16_C(  1379),  INT16_C(  5256), -INT16_C(  3575),  INT16_C(  3532), -INT16_C( 26995),  INT16_C(  7022), -INT16_C(  2536),  INT16_C(  7013),
         INT16_C( 29150),  INT16_C( 27534),  INT16_C( 31632),  INT16_C( 15598), -INT16_C( 19447),  INT16_C(  7695), -INT16_C(  9612), -INT16_C( 10082) },
      UINT16_C( 9951),
      { -INT16_C(  5908), -INT16_C( 18407), -INT16_C( 22795),  INT16_C( 25423),  INT16_C( 26561),  INT16_C( 10073),  INT16_C( 14211),  INT16_C(  4504),
         INT16_C( 10659), -INT16_C( 28275), -INT16_C( 27035),  INT16_C( 29765), -INT16_C( 17995),  INT16_C( 21326),  INT16_C( 11665),  INT16_C( 32121) },
      { -INT16_C( 28139),  INT16_C(  2870), -INT16_C( 31431), -INT16_C(  1426), -INT16_C( 14100),  INT16_C( 28449), -INT16_C( 17665), -INT16_C( 23935),
         INT16_C(  3811),  INT16_C( 18483),  INT16_C( 30884),  INT16_C( 22972),  INT16_C(  2610), -INT16_C( 15444),  INT16_C(  9783),  INT16_C( 19521) },
      { -INT16_C(  5908), -INT16_C( 28139), -INT16_C( 18407),  INT16_C(  2870), -INT16_C( 22795),  INT16_C(  7022),  INT16_C( 25423), -INT16_C(  1426),
         INT16_C( 29150),  INT16_C(  3811), -INT16_C( 28275),  INT16_C( 15598), -INT16_C( 19447),  INT16_C( 30884), -INT16_C(  9612), -INT16_C( 10082) } },
    { {  INT16_C( 30648), -INT16_C(  3753), -INT16_C( 14596), -INT16_C(  5908),  INT16_C(  3470), -INT16_C( 29352), -INT16_C(  9785), -INT16_C( 21968),
         INT16_C( 25575), -INT16_C( 29710), -INT16_C( 20772),  INT16_C(  3813), -INT16_C( 28232), -INT16_C(  4143),  INT16_C(  4791),  INT16_C( 28732) },
      UINT16_C(37769),
      { -INT16_C( 31391),  INT16_C( 19801), -INT16_C(  6290), -INT16_C( 14757),  INT16_C(  8821), -INT16_C( 23137), -INT16_C( 31027), -INT16_C( 16632),
        -INT16_C(  7151), -INT16_C(  2450),  INT16_C(  9970), -INT16_C( 15224),  INT16_C( 16150),  INT16_C( 21206),  INT16_C( 24751),  INT16_C(  4581) },
      {  INT16_C( 16357),  INT16_C( 21342), -INT16_C( 18138), -INT16_C( 25831), -INT16_C( 18212), -INT16_C( 22208),  INT16_C( 18750),  INT16_C( 20584),
        -INT16_C( 10707),  INT16_C(  8262), -INT16_C( 12547),  INT16_C(  5092), -INT16_C( 17906), -INT16_C( 17051),  INT16_C( 18970),  INT16_C(   206) },
      { -INT16_C( 31391), -INT16_C(  3753), -INT16_C( 14596),  INT16_C( 21342),  INT16_C(  3470), -INT16_C( 29352), -INT16_C(  9785), -INT16_C( 25831),
        -INT16_C(  7151), -INT16_C( 10707), -INT16_C( 20772),  INT16_C(  3813),  INT16_C(  9970), -INT16_C(  4143),  INT16_C(  4791),  INT16_C(  5092) } },
    { {  INT16_C( 11657), -INT16_C( 20397),  INT16_C( 28134), -INT16_C( 15797), -INT16_C( 29659),  INT16_C( 25707), -INT16_C( 11051),  INT16_C(   692),
        -INT16_C(  1366), -INT16_C( 22750),  INT16_C(  1737), -INT16_C( 10310),  INT16_C(  8129), -INT16_C(  9324),  INT16_C( 25450), -INT16_C(  3109) },
      UINT16_C(12176),
      {  INT16_C( 30371), -INT16_C(  4196), -INT16_C( 16071), -INT16_C( 23429),  INT16_C( 20517), -INT16_C(  9864),  INT16_C(  9042),  INT16_C( 30164),
        -INT16_C( 25142), -INT16_C( 31365),  INT16_C( 15476),  INT16_C(  2212),  INT16_C(  3608), -INT16_C(  3221), -INT16_C(  1278), -INT16_C( 23262) },
      { -INT16_C( 16782), -INT16_C( 21612),  INT16_C(  3968), -INT16_C( 23217), -INT16_C( 14241), -INT16_C( 19841),  INT16_C( 21483), -INT16_C( 19161),
        -INT16_C( 23824),  INT16_C( 25658), -INT16_C(  8225), -INT16_C(  2196), -INT16_C( 10003), -INT16_C(  4118),  INT16_C(  3539),  INT16_C( 17813) },
      {  INT16_C( 11657), -INT16_C( 20397),  INT16_C( 28134), -INT16_C( 15797), -INT16_C( 16071),  INT16_C( 25707), -INT16_C( 11051), -INT16_C( 23217),
        -INT16_C( 25142), -INT16_C( 23824), -INT16_C( 31365),  INT16_C( 25658),  INT16_C(  8129), -INT16_C(  8225),  INT16_C( 25450), -INT16_C(  3109) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256i src = simde_x_mm256_loadu_epi16(test_vec[i].src);
    simde__m256i a = simde_x_mm256_loadu_epi16(test_vec[i].a);
    simde__m256i b = simde_x_mm256_loadu_epi16(test_vec[i].b);
    simde__m256i r = simde_mm256_mask_unpacklo_epi16(src, test_vec[i].k, a, b);
    simde_test_x86_assert_equal_i16x16(r, simde_x_mm256_loadu_epi16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m256i src = simde_test_x86_random_i16x16();
    simde__mmask16 k = simde_test_x86_random_mmask16();
    simde__m256i a = simde_test_x86_random_i16x16();
    simde__m256i b = simde_test_x86_random_i16x16();
    simde__m256i r = simde_mm256_mask_unpacklo_epi16(src, k, a, b);

    simde_test_x86_write_i16x16(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask16(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x16(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_maskz_unpacklo_epi16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask16 k;
    const int16_t a[16];
    const int16_t b[16];
    const int16_t r[16];
  } test_vec[] = {
    { UINT16_C(42438),
      { -INT16_C(  2735),  INT16_C(  7245),  INT16_C( 28373), -INT16_C(  9239),  INT16_C( 11311), -INT16_C( 25428),  INT16_C(  7835),  INT16_C( 24478),
         INT16_C( 19063), -INT16_C(    67),  INT16_C( 19464), -INT16_C(  1391), -INT16_C( 12750),  INT16_C(   514), -INT16_C( 14212), -INT16_C( 12889) },
      { -INT16_C(  2627), -INT16_C( 27926), -INT16_C( 11421), -INT16_C( 28051),  INT16_C(  6911), -INT16_C( 26066), -INT16_C( 13256), -INT16_C( 20486),
        -INT16_C( 18666),  INT16_C(  8111),  INT16_C( 16387),  INT16_C( 13593),  INT16_C(  6926), -INT16_C( 30153), -INT16_C(  8221), -INT16_C( 24488) },
      {  INT16_C(     0), -INT16_C(  2627),  INT16_C(  7245),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(  9239), -INT16_C( 28051),
         INT16_C( 19063),  INT16_C(     0), -INT16_C(    67),  INT16_C(     0),  INT16_C(     0),  INT16_C( 16387),  INT16_C(     0),  INT16_C( 13593) } },
    { UINT16_C(17108),
      {  INT16_C( 14131), -INT16_C( 24555),  INT16_C(  5321), -INT16_C(  2118), -INT16_C(  3153), -INT16_C( 22077), -INT16_C(  9566),  INT16_C( 20832),
         INT16_C( 25593),  INT16_C(  4753), -INT16_C( 24423), -INT16_C( 12242),  INT16_C(  4394), -INT16_C( 32081), -INT16_C( 31822), -INT16_C(  6716) },
      { -INT16_C(  9798), -INT16_C( 31867),  INT16_C( 16622), -INT16_C( 25222),  INT16_C( 15923), -INT16_C( 10938), -INT16_C( 23016),  INT16_C(  4391),
        -INT16_C( 18423), -INT16_C( 24029),  INT16_C( 20824), -INT16_C( 31885),  INT16_C(  8803),  INT16_C(  5381), -INT16_C( 13658),  INT16_C( 24826) },
      {  INT16_C(     0),  INT16_C(     0), -INT16_C( 24555),  INT16_C(     0),  INT16_C(  5321),  INT16_C(     0), -INT16_C(  2118), -INT16_C( 25222),
         INT16_C(     0), -INT16_C( 18423),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C( 12242),  INT16_C(     0) } },
    { UINT16_C(32675),
      { -INT16_C( 28188),  INT16_C( 24255), -INT16_C(  3538),  INT16_C( 29852), -INT16_C( 19256), -INT16_C(  4326),  INT16_C(  9413), -INT16_C(  5721),
         INT16_C(   198),  INT16_C( 14650), -INT16_C( 25213), -INT16_C( 30628),  INT16_C(   690), -INT16_C( 21422), -INT16_C(  2462),  INT16_C( 17964) },
      { -INT16_C(  5241), -INT16_C( 18779),  INT16_C( 16862), -INT16_C( 22998),  INT16_C( 17910), -INT16_C( 17515),  INT16_C( 15465),  INT16_C( 12196),
        -INT16_C(  8388), -INT16_C( 16535), -INT16_C( 14980),  INT16_C( 12104), -INT16_C( 25913),  INT16_C( 10715),  INT16_C(  1936),  INT16_C(  6256) },
      { -INT16_C( 28188), -INT16_C(  5241),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C( 16862),  INT16_C(     0), -INT16_C( 22998),
         INT16_C(   198), -INT16_C(  8388),  INT16_C( 14650), -INT16_C( 16535), -INT16_C( 25213), -INT16_C( 14980), -INT16_C( 30628),  INT16_C(     0) } },
    { UINT16_C( 5619),
      { -INT16_C( 11826), -INT16_C(  1962),  INT16_C( 19575),  INT16_C(  3133), -INT16_C( 23032), -INT16_C( 21432), -INT16_C( 31274),  INT16_C( 16267),
         INT16_C(  2116), -INT16_C( 29692), -INT16_C( 13513),  INT16_C(  4647), -INT16_C( 18444),  INT16_C( 25626),  INT16_C(  3535), -INT16_C( 25223) },
      { -INT16_C( 12066),  INT16_C( 21910), -INT16_C( 11492),  INT16_C(  9313), -INT16_C( 22150),  INT16_C( 20689),  INT16_C( 23598),  INT16_C( 29583),
        -INT16_C( 27804), -INT16_C( 25601),  INT16_C(  9822),  INT16_C( 21166), -INT16_C( 14114), -INT16_C( 21065),  INT16_C( 12501), -INT16_C( 19637) },
      { -INT16_C( 11826), -INT16_C( 12066),  INT16_C(     0),  INT16_C(     0),  INT16_C( 19575), -INT16_C( 11492),  INT16_C(  3133),  INT16_C(  9313),
         INT16_C(  2116),  INT16_C(     0), -INT16_C( 29692),  INT16_C(     0), -INT16_C( 13513),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
    { UINT16_C(57600),
      {  INT16_C(  7432),  INT16_C( 27060),  INT16_C( 11841),  INT16_C(  4626),  INT16_C( 16766),  INT16_C(  3439), -INT16_C( 11340), -INT16_C( 19552),
        -INT16_C(   401),  INT16_C(  7642), -INT16_C( 18351),  INT16_C(  2277), -INT16_C( 17819), -INT16_C( 20424),  INT16_C( 14701),  INT16_C( 30097) },
      {  INT16_C( 18006), -INT16_C( 26658), -INT16_C(  3980), -INT16_C(  3158),  INT16_C(  6449), -INT16_C(  6912), -INT16_C( 24084),  INT16_C( 23449),
         INT16_C( 29599), -INT16_C(  3976),  INT16_C( 23851), -INT16_C( 28424),  INT16_C( 12567), -INT16_C( 31679), -INT16_C( 11670), -INT16_C( 16135) },
      {  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
        -INT16_C(   401),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C( 23851),  INT16_C(  2277), -INT16_C( 28424) } },
    { UINT16_C(55064),
      { -INT16_C( 29353),  INT16_C(   456), -INT16_C(  1664), -INT16_C( 32742),  INT16_C(  2015),  INT16_C( 30753), -INT16_C( 16030), -INT16_C(  9237),
         INT16_C(  5809), -INT16_C( 21960),  INT16_C( 20646), -INT16_C(  6181),  INT16_C( 17876), -INT16_C( 12614), -INT16_C( 11771),  INT16_C( 23717) },
      {  INT16_C( 27999), -INT16_C(  8354),  INT16_C( 30823),  INT16_C( 18016), -INT16_C( 32385), -INT16_C(  7490), -INT16_C( 22206), -INT16_C(  2883),
        -INT16_C(  2625),  INT16_C( 26014),  INT16_C( 31045),  INT16_C(  6733),  INT16_C(  1982), -INT16_C( 15384), -INT16_C( 29223),  INT16_C( 14623) },
      {  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(  8354), -INT16_C(  1664),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
         INT16_C(  5809), -INT16_C(  2625), -INT16_C( 21960),  INT16_C(     0),  INT16_C( 20646),  INT16_C(     0), -INT16_C(  6181),  INT16_C(  6733) } },
    { UINT16_C(32251),
      {  INT16_C( 25112),  INT16_C( 30966),  INT16_C( 30120),  INT16_C( 26362),  INT16_C( 15447),  INT16_C(  5135), -INT16_C( 12752), -INT16_C( 12790),
         INT16_C( 20275), -INT16_C( 32697),  INT16_C(  1385),  INT16_C( 20871),  INT16_C( 25032), -INT16_C(  5921), -INT16_C(  9574), -INT16_C( 19867) },
      {  INT16_C( 23356), -INT16_C(  7125),  INT16_C(  9681),  INT16_C( 10314),  INT16_C( 22881), -INT16_C( 28099),  INT16_C( 18215),  INT16_C( 23136),
        -INT16_C( 22378),  INT16_C(   219),  INT16_C( 25261),  INT16_C( 30289),  INT16_C( 12483),  INT16_C( 23902), -INT16_C( 15606),  INT16_C( 17936) },
      {  INT16_C( 25112),  INT16_C( 23356),  INT16_C(     0), -INT16_C(  7125),  INT16_C( 30120),  INT16_C(  9681),  INT16_C( 26362),  INT16_C( 10314),
         INT16_C( 20275),  INT16_C(     0), -INT16_C( 32697),  INT16_C(   219),  INT16_C(  1385),  INT16_C( 25261),  INT16_C( 20871),  INT16_C(     0) } },
    { UINT16_C(15135),
      { -INT16_C(  4054),  INT16_C( 29792), -INT16_C( 16104),  INT16_C( 21965), -INT16_C(  2989), -INT16_C( 19300),  INT16_C( 13135),  INT16_C( 10844),
         INT16_C(  2355), -INT16_C( 31604),  INT16_C( 20607), -INT16_C(  8779), -INT16_C( 16467), -INT16_C( 16991), -INT16_C( 16378),  INT16_C( 12536) },
      {  INT16_C( 22704), -INT16_C( 14171),  INT16_C( 29210),  INT16_C( 27934), -INT16_C( 17817), -INT16_C( 18911),  INT16_C( 32237),  INT16_C(  8416),
         INT16_C( 27783),  INT16_C(  1701),  INT16_C( 23228),  INT16_C( 27364), -INT16_C( 31463),  INT16_C(  7975),  INT16_C(  8261), -INT16_C(  2736) },
      { -INT16_C(  4054),  INT16_C( 22704),  INT16_C( 29792), -INT16_C( 14171), -INT16_C( 16104),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
         INT16_C(  2355),  INT16_C( 27783),  INT16_C(     0),  INT16_C(  1701),  INT16_C( 20607),  INT16_C( 23228),  INT16_C(     0),  INT16_C(     0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256i a = simde_x_mm256_loadu_epi16(test_vec[i].a);
    simde__m256i b = simde_x_mm256_loadu_epi16(test_vec[i].b);
    simde__m256i r = simde_mm256_maskz_unpacklo_epi16(test_vec[i].k, a, b);
    simde_test_x86_assert_equal_i16x16(r, simde_x_mm256_loadu_epi16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask16 k = simde_test_x86_random_mmask16();
    simde__m256i a = simde_test_x86_random_i16x16();
    simde__m256i b = simde_test_x86_random_i16x16();
    simde__m256i r = simde_mm256_maskz_unpacklo_epi16(k, a, b);

    simde_test_x86_write_mmask16(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i16x16(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_mask_unpacklo_epi16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int16_t src[8];
    const simde__mmask8 k;
    const int16_t a[8];
    const int16_t b[8];
    const int16_t r[8];
  } test_vec[] = {
    { {  INT16_C(  6519),  INT16_C( 13810), -INT16_C( 23672), -INT16_C( 21987),  INT16_C( 10659),  INT16_C( 23063),  INT16_C(  4489),  INT16_C(  2023) },
      UINT8_C(244),
      {  INT16_C( 26733),  INT16_C(  2639), -INT16_C(  5894),  INT16_C(  5730),  INT16_C( 26930),  INT16_C( 21588), -INT16_C( 24315),  INT16_C(  8140) },
      {  INT16_C(   403),  INT16_C( 14247),  INT16_C( 20767),  INT16_C( 18650),  INT16_C( 13672),  INT16_C( 31185), -INT16_C(  9956), -INT16_C( 30355) },
      {  INT16_C(  6519),  INT16_C( 13810),  INT16_C(  2639), -INT16_C( 21987), -INT16_C(  5894),  INT16_C( 20767),  INT16_C(  5730),  INT16_C( 18650) } },
    { { -INT16_C( 17343),  INT16_C( 15251), -INT16_C(  2651), -INT16_C( 10415), -INT16_C( 23202),  INT16_C( 25387), -INT16_C(  2234), -INT16_C(  9598) },
      UINT8_C(249),
      {  INT16_C(  4394),  INT16_C( 31512),  INT16_C( 24811),  INT16_C(  8420),  INT16_C( 23857),  INT16_C(  2620), -INT16_C( 14901), -INT16_C( 30901) },
      { -INT16_C( 31144),  INT16_C( 19756),  INT16_C(   983),  INT16_C( 31915),  INT16_C(  3887),  INT16_C(  9923), -INT16_C( 25199), -INT16_C( 17633) },
      {  INT16_C(  4394),  INT16_C( 15251), -INT16_C(  2651),  INT16_C( 19756),  INT16_C( 24811),  INT16_C(   983),  INT16_C(  8420),  INT16_C( 31915) } },
    { {  INT16_C( 14254), -INT16_C( 26313),  INT16_C(  7063), -INT16_C( 13894), -INT16_C(  2440),  INT16_C( 17363),  INT16_C(  8124),  INT16_C(  5323) },
      UINT8_C(165),
      {  INT16_C( 25335), -INT16_C(  1155), -INT16_C(  1779),  INT16_C(  7210),  INT16_C( 20668),  INT16_C( 22958),  INT16_C( 26992), -INT16_C( 22777) },
      { -INT16_C( 24160), -INT16_C( 17601),  INT16_C(  2139),  INT16_C( 20788),  INT16_C( 30683), -INT16_C(  1523),  INT16_C(  8770),  INT16_C( 15008) },
      {  INT16_C( 25335), -INT16_C( 26313), -INT16_C(  1155), -INT16_C( 13894), -INT16_C(  2440),  INT16_C(  2139),  INT16_C(  8124),  INT16_C( 20788) } },
    { {  INT16_C(  7556), -INT16_C( 28363),  INT16_C( 24342), -INT16_C( 11346),  INT16_C( 23727),  INT16_C(  7980),  INT16_C( 13509),  INT16_C( 26311) },
      UINT8_C(213),
      {  INT16_C(  8454),  INT16_C(  3632), -INT16_C( 32427), -INT16_C( 12823), -INT16_C(  7025), -INT16_C( 20209),  INT16_C( 18820), -INT16_C( 24267) },
      { -INT16_C( 14722), -INT16_C(  8777), -INT16_C( 30092), -INT16_C( 12147), -INT16_C( 21321), -INT16_C(  5226), -INT16_C(   909),  INT16_C( 31168) },
      {  INT16_C(  8454), -INT16_C( 28363),  INT16_C(  3632), -INT16_C( 11346), -INT16_C( 32427),  INT16_C(  7980), -INT16_C( 12823), -INT16_C( 12147) } },
    { { -INT16_C(  4067),  INT16_C( 29575),  INT16_C( 29041),  INT16_C(    64),  INT16_C( 20309), -INT16_C(  9807), -INT16_C(  6503),  INT16_C(  6010) },
      UINT8_C(173),
      { -INT16_C(  2767), -INT16_C( 17375), -INT16_C(  3454),  INT16_C( 11891),  INT16_C( 24200), -INT16_C( 31582),  INT16_C(  6942),  INT16_C(  3745) },
      {  INT16_C(  5283),  INT16_C(  5247), -INT16_C( 32684), -INT16_C( 23447),  INT16_C( 16945),  INT16_C(  6205),  INT16_C( 21692), -INT16_C(  4667) },
      { -INT16_C(  2767),  INT16_C( 29575), -INT16_C( 17375),  INT16_C(  5247),  INT16_C( 20309), -INT16_C( 32684), -INT16_C(  6503), -INT16_C( 23447) } },
    { { -INT16_C(  6583), -INT16_C( 13399),  INT16_C(  7384),  INT16_C( 24826), -INT16_C( 25478), -INT16_C( 26396), -INT16_C( 31049),  INT16_C( 23206) },
      UINT8_C(154),
      {  INT16_C( 28198), -INT16_C( 22801), -INT16_C( 27689),  INT16_C(  6615), -INT16_C(  4144),  INT16_C(  9429), -INT16_C( 15436), -INT16_C( 25746) },
      {  INT16_C( 14700), -INT16_C( 30349), -INT16_C( 11213), -INT16_C( 12541), -INT16_C( 25416),  INT16_C( 16007), -INT16_C(  7870),  INT16_C( 26841) },
      { -INT16_C(  6583),  INT16_C( 14700),  INT16_C(  7384), -INT16_C( 30349), -INT16_C( 27689), -INT16_C( 26396), -INT16_C( 31049), -INT16_C( 12541) } },
    { { -INT16_C( 14256),  INT16_C(  9998), -INT16_C(  6565),  INT16_C( 11073),  INT16_C(  5845), -INT16_C( 30129), -INT16_C( 16935),  INT16_C( 17957) },
      UINT8_C(247),
      { -INT16_C( 12392),  INT16_C( 27690), -INT16_C(  1326),  INT16_C( 28197),  INT16_C( 25473),  INT16_C( 25265),  INT16_C(  6460),  INT16_C(  1202) },
      { -INT16_C(  9688),  INT16_C(  3679), -INT16_C( 30181),  INT16_C( 12771),  INT16_C( 28122), -INT16_C( 26869),  INT16_C( 20882),  INT16_C( 11150) },
      { -INT16_C( 12392), -INT16_C(  9688),  INT16_C( 27690),  INT16_C( 11073), -INT16_C(  1326), -INT16_C( 30181),  INT16_C( 28197),  INT16_C( 12771) } },
    { { -INT16_C( 18144), -INT16_C(  3433), -INT16_C( 17229),  INT16_C( 13409),  INT16_C(  4640),  INT16_C( 23702),  INT16_C( 18731),  INT16_C( 21345) },
      UINT8_C( 35),
      {  INT16_C( 25024),  INT16_C( 19262),  INT16_C( 28485), -INT16_C( 19931), -INT16_C( 17286), -INT16_C( 13499),  INT16_C( 28747),  INT16_C(  1259) },
      { -INT16_C(  8697), -INT16_C( 15177), -INT16_C(  5313),  INT16_C( 20964),  INT16_C( 16513), -INT16_C( 13700), -INT16_C( 12127),  INT16_C( 25325) },
      {  INT16_C( 25024), -INT16_C(  8697), -INT16_C( 17229),  INT16_C( 13409),  INT16_C(  4640), -INT16_C(  5313),  INT16_C( 18731),  INT16_C( 21345) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i src = simde_mm_loadu_epi16(test_vec[i].src);
    simde__m128i a = simde_mm_loadu_epi16(test_vec[i].a);
    simde__m128i b = simde_mm_loadu_epi16(test_vec[i].b);
    simde__m128i r = simde_mm_mask_unpacklo_epi16(src, test_vec[i].k, a, b);
    simde_test_x86_assert_equal_i16x8(r, simde_mm_loadu_epi16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i src = simde_test_x86_random_i16x8();
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m128i a = simde_test_x86_random_i16x8();
    simde__m128i b = simde_test_x86_random_i16x8();
    simde__m128i r = simde_mm_mask_unpacklo_epi16(src, k, a, b);

    simde_test_x86_write_i16x8(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_maskz_unpacklo_epi16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k;
    const int16_t a[8];
    const int16_t b[8];
    const int16_t r[8];
  } test_vec[] = {
    { UINT8_C( 12),
      { -INT16_C( 27740), -INT16_C(   197),  INT16_C(  5326),  INT16_C( 24413),  INT16_C( 13109), -INT16_C(  3534),  INT16_C( 31201), -INT16_C( 28268) },
      {  INT16_C(  2597),  INT16_C( 27876),  INT16_C( 24345), -INT16_C( 18430), -INT16_C( 31800),  INT16_C(  8739), -INT16_C(  7422), -INT16_C( 22994) },
      {  INT16_C(     0),  INT16_C(     0), -INT16_C(   197),  INT16_C( 27876),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
    { UINT8_C(118),
      { -INT16_C( 23191),  INT16_C( 32324), -INT16_C( 23806),  INT16_C( 14003), -INT16_C( 22827),  INT16_C( 19991), -INT16_C( 22470),  INT16_C( 17524) },
      { -INT16_C(  8051), -INT16_C(  5027),  INT16_C(  5602),  INT16_C( 26036), -INT16_C( 10696),  INT16_C(  7015),  INT16_C(  3332),  INT16_C( 28305) },
      {  INT16_C(     0), -INT16_C(  8051),  INT16_C( 32324),  INT16_C(     0), -INT16_C( 23806),  INT16_C(  5602),  INT16_C( 14003),  INT16_C(     0) } },
    { UINT8_C(179),
      { -INT16_C(  4907),  INT16_C( 31157), -INT16_C(  5217),  INT16_C( 17742), -INT16_C( 25342), -INT16_C( 21632), -INT16_C( 15343), -INT16_C(  3784) },
      {  INT16_C(  9250),  INT16_C( 14291),  INT16_C( 14552), -INT16_C( 20624), -INT16_C( 29793), -INT16_C( 21325),  INT16_C(  8477), -INT16_C(  3489) },
      { -INT16_C(  4907),  INT16_C(  9250),  INT16_C(     0),  INT16_C(     0), -INT16_C(  5217),  INT16_C( 14552),  INT16_C(     0), -INT16_C( 20624) } },
    { UINT8_C( 13),
      {  INT16_C( 27413),  INT16_C(   173), -INT16_C(  3398),  INT16_C( 22275), -INT16_C( 20878),  INT16_C( 14184),  INT16_C( 23014),  INT16_C(  2649) },
      { -INT16_C( 28628),  INT16_C( 25826), -INT16_C( 28416), -INT16_C( 29693), -INT16_C( 20667),  INT16_C( 26281), -INT16_C( 25841),  INT16_C(  9332) },
      {  INT16_C( 27413),  INT16_C(     0),  INT16_C(   173),  INT16_C( 25826),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
    { UINT8_C(  7),
      {  INT16_C(  9249),  INT16_C(  5057),  INT16_C(  6183), -INT16_C( 10874), -INT16_C( 17024), -INT16_C(  9797), -INT16_C( 15082), -INT16_C( 23035) },
      {  INT16_C( 27048),  INT16_C( 14759),  INT16_C( 13164),  INT16_C(  7038), -INT16_C(  6692),  INT16_C( 30506),  INT16_C( 20057),  INT16_C( 31358) },
      {  INT16_C(  9249),  INT16_C( 27048),  INT16_C(  5057),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
    { UINT8_C(115),
      { -INT16_C( 29377),  INT16_C( 22426),  INT16_C( 28691), -INT16_C( 12073), -INT16_C( 20437), -INT16_C(  3610), -INT16_C( 29259),  INT16_C(  7833) },
      { -INT16_C( 11724),  INT16_C( 26506), -INT16_C( 22959),  INT16_C( 13891), -INT16_C( 17712),  INT16_C(  8079),  INT16_C(  2361),  INT16_C( 30866) },
      { -INT16_C( 29377), -INT16_C( 11724),  INT16_C(     0),  INT16_C(     0),  INT16_C( 28691), -INT16_C( 22959), -INT16_C( 12073),  INT16_C(     0) } },
    { UINT8_C(150),
      { -INT16_C( 12244), -INT16_C( 25430),  INT16_C( 31399),  INT16_C( 22728), -INT16_C( 18079), -INT16_C(  4595),  INT16_C( 11346),  INT16_C(  9250) },
      { -INT16_C( 30282),  INT16_C( 23669), -INT16_C( 21556), -INT16_C( 31187),  INT16_C( 19514),  INT16_C( 17343),  INT16_C( 14558),  INT16_C(  2778) },
      {  INT16_C(     0), -INT16_C( 30282), -INT16_C( 25430),  INT16_C(     0),  INT16_C( 31399),  INT16_C(     0),  INT16_C(     0), -INT16_C( 31187) } },
    { UINT8_C(  8),
      { -INT16_C( 22652), -INT16_C(   337),  INT16_C(  1903),  INT16_C( 10335),  INT16_C( 19733),  INT16_C( 16762), -INT16_C( 24977), -INT16_C(  1801) },
      {  INT16_C( 21524), -INT16_C( 16444),  INT16_C( 19329), -INT16_C( 12806),  INT16_C( 15626),  INT16_C( 17067), -INT16_C( 19177), -INT16_C( 25782) },
      {  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C( 16444),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_x_mm_loadu_epi16(test_vec[i].a);
    simde__m128i b = simde_x_mm_loadu_epi16(test_vec[i].b);
    simde__m128i r = simde_mm_maskz_unpacklo_epi16(test_vec[i].k, a, b);
    simde_test_x86_assert_equal_i16x8(r, simde_x_mm_loadu_epi16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m128i a = simde_test_x86_random_i16x8();
    simde__m128i b = simde_test_x86_random_i16x8();
    simde__m128i r = simde_mm_maskz_unpacklo_epi16(k, a, b);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i16x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
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
test_simde_mm512_mask_unpacklo_epi32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int32_t src[16];
    const simde__mmask16 k;
    const int32_t a[16];
    const int32_t b[16];
    const int32_t r[16];
  } test_vec[] = {
    { { -INT32_C(  1340429016),  INT32_C(  1000343311), -INT32_C(  2062872037),  INT32_C(  1692174286),  INT32_C(  1000848059),  INT32_C(   359858081), -INT32_C(   395984796), -INT32_C(   954325090),
        -INT32_C(   461948715),  INT32_C(  1528764224), -INT32_C(   136304087),  INT32_C(  1834794418),  INT32_C(   413729655),  INT32_C(  1714297602),  INT32_C(  2052035547), -INT32_C(  1874760261) },
      UINT16_C(47270),
      { -INT32_C(  1798314380),  INT32_C(   582940737),  INT32_C(  1272934639), -INT32_C(  2024909090), -INT32_C(  1667083922),  INT32_C(   103841207),  INT32_C(   947186679), -INT32_C(   269477253),
         INT32_C(  1099153152), -INT32_C(  1486667081), -INT32_C(  1863171406),  INT32_C(   118964632),  INT32_C(  1235466642),  INT32_C(   777048887),  INT32_C(   963101886), -INT32_C(   567715874) },
      { -INT32_C(   836785129), -INT32_C(  1586134034),  INT32_C(  1580296389),  INT32_C(   996493737),  INT32_C(   964954114), -INT32_C(  1704405796),  INT32_C(  1993658264),  INT32_C(  1028980006),
        -INT32_C(  1744014167), -INT32_C(  1137081865), -INT32_C(  1843762455), -INT32_C(  1228046413),  INT32_C(  1693405832), -INT32_C(  1073850586),  INT32_C(  1295372838),  INT32_C(  2039122639) },
      { -INT32_C(  1340429016), -INT32_C(   836785129),  INT32_C(   582940737),  INT32_C(  1692174286),  INT32_C(  1000848059),  INT32_C(   964954114), -INT32_C(   395984796), -INT32_C(  1704405796),
        -INT32_C(   461948715),  INT32_C(  1528764224), -INT32_C(   136304087), -INT32_C(  1137081865),  INT32_C(  1235466642),  INT32_C(  1693405832),  INT32_C(  2052035547), -INT32_C(  1073850586) } },
    { { -INT32_C(   183396610),  INT32_C(    28396056),  INT32_C(  1754582196), -INT32_C(   752983733), -INT32_C(   633926221), -INT32_C(  1952893339), -INT32_C(   656880120),  INT32_C(  1448174424),
         INT32_C(   290153209),  INT32_C(  1611922860),  INT32_C(   348694473), -INT32_C(  1125587448),  INT32_C(  1503010804),  INT32_C(  1592012629),  INT32_C(  1446428157),  INT32_C(   430737184) },
      UINT16_C(63721),
      {  INT32_C(  1056281899), -INT32_C(  1092239627), -INT32_C(  1163596334),  INT32_C(  1071290537), -INT32_C(   697421839), -INT32_C(  1013748595),  INT32_C(  1850389442), -INT32_C(   144297012),
        -INT32_C(  1103799352), -INT32_C(   327411175), -INT32_C(  1314512888), -INT32_C(  1427013447),  INT32_C(  1031823280), -INT32_C(  1929309237), -INT32_C(  1812182074),  INT32_C(  1200251519) },
      { -INT32_C(   687488834), -INT32_C(   490503718),  INT32_C(  1536453282), -INT32_C(  1710914070), -INT32_C(  1327986972),  INT32_C(  1614666137), -INT32_C(  1544341212),  INT32_C(  1525382556),
         INT32_C(   405925949),  INT32_C(   351991154),  INT32_C(  1232047711), -INT32_C(   119245805), -INT32_C(  1800880902), -INT32_C(  1175132779), -INT32_C(  1151473889), -INT32_C(  1575663516) },
      {  INT32_C(  1056281899),  INT32_C(    28396056),  INT32_C(  1754582196), -INT32_C(   490503718), -INT32_C(   633926221), -INT32_C(  1327986972), -INT32_C(  1013748595),  INT32_C(  1614666137),
         INT32_C(   290153209),  INT32_C(  1611922860),  INT32_C(   348694473),  INT32_C(   351991154),  INT32_C(  1031823280), -INT32_C(  1800880902), -INT32_C(  1929309237), -INT32_C(  1175132779) } },
    { { -INT32_C(  1430632904), -INT32_C(  1698778053),  INT32_C(  1457794371), -INT32_C(  1672558430),  INT32_C(   422639236), -INT32_C(    70114084),  INT32_C(  1890987787), -INT32_C(  1340945545),
         INT32_C(  1297796113), -INT32_C(  1008264832), -INT32_C(   400897210),  INT32_C(   394619027),  INT32_C(   993047903), -INT32_C(   449444902), -INT32_C(  1437209550), -INT32_C(   933599305) },
      UINT16_C(46131),
      { -INT32_C(    36850667), -INT32_C(  1849158537), -INT32_C(  2114298628), -INT32_C(  1539876493), -INT32_C(   895020652),  INT32_C(  1287051766), -INT32_C(   575443581),  INT32_C(  1267918645),
         INT32_C(   306732955),  INT32_C(  1889800307), -INT32_C(   521036180), -INT32_C(  1954273033),  INT32_C(   810887993), -INT32_C(  2005136636), -INT32_C(  1385877640), -INT32_C(  1309083882) },
      { -INT32_C(   893108137), -INT32_C(  1120245679), -INT32_C(    40031226), -INT32_C(  1903681196),  INT32_C(  1371462988),  INT32_C(  1624849128), -INT32_C(  2146615703), -INT32_C(  1926166986),
        -INT32_C(  1755843258),  INT32_C(  1666552413),  INT32_C(   308343486),  INT32_C(  1621157908), -INT32_C(  1380884795),  INT32_C(    34441880), -INT32_C(     8250423),  INT32_C(  1737274145) },
      { -INT32_C(    36850667), -INT32_C(   893108137),  INT32_C(  1457794371), -INT32_C(  1672558430), -INT32_C(   895020652),  INT32_C(  1371462988),  INT32_C(  1890987787), -INT32_C(  1340945545),
         INT32_C(  1297796113), -INT32_C(  1008264832),  INT32_C(  1889800307),  INT32_C(   394619027),  INT32_C(   810887993), -INT32_C(  1380884795), -INT32_C(  1437209550),  INT32_C(    34441880) } },
    { {  INT32_C(   117433257),  INT32_C(   862606453),  INT32_C(  1514588742),  INT32_C(  2025580211), -INT32_C(   584684475), -INT32_C(  1059113993),  INT32_C(  1874813262), -INT32_C(  1093186795),
        -INT32_C(  1530603986),  INT32_C(  1893150250), -INT32_C(  1395974663),  INT32_C(  1227130372), -INT32_C(   383366414), -INT32_C(   861337986),  INT32_C(  2084333671), -INT32_C(   499510349) },
      UINT16_C(65513),
      {  INT32_C(  1563235206),  INT32_C(  1316693635), -INT32_C(   137068590), -INT32_C(   297678904),  INT32_C(  1525989296), -INT32_C(   926786420),  INT32_C(   333149912), -INT32_C(   569195432),
         INT32_C(  1513832407),  INT32_C(   950646374), -INT32_C(    47219403), -INT32_C(   169053884), -INT32_C(  1135615952),  INT32_C(   360976700), -INT32_C(   551002233), -INT32_C(    88262109) },
      { -INT32_C(   548013703), -INT32_C(   451346769), -INT32_C(  1058912389), -INT32_C(   373961032), -INT32_C(   341506897), -INT32_C(  1660933611), -INT32_C(  1384372087), -INT32_C(   593020318),
        -INT32_C(   490996685),  INT32_C(  1992807418), -INT32_C(   751392229),  INT32_C(   666692472),  INT32_C(    68379375),  INT32_C(   362877836), -INT32_C(  1631445444), -INT32_C(  1954911656) },
      {  INT32_C(  1563235206),  INT32_C(   862606453),  INT32_C(  1514588742), -INT32_C(   451346769), -INT32_C(   584684475), -INT32_C(   341506897), -INT32_C(   926786420), -INT32_C(  1660933611),
         INT32_C(  1513832407), -INT32_C(   490996685),  INT32_C(   950646374),  INT32_C(  1992807418), -INT32_C(  1135615952),  INT32_C(    68379375),  INT32_C(   360976700),  INT32_C(   362877836) } },
    { {  INT32_C(  1634547302),  INT32_C(   618083593),  INT32_C(  1475874271), -INT32_C(   411061000), -INT32_C(  1561619946), -INT32_C(   507998811),  INT32_C(    58751659),  INT32_C(  1267661540),
         INT32_C(   984415024),  INT32_C(   257852208), -INT32_C(  2006493552),  INT32_C(   560981515),  INT32_C(   499407480), -INT32_C(  1828750105), -INT32_C(   610959370), -INT32_C(  1440341127) },
      UINT16_C(53791),
      {  INT32_C(  1112887268), -INT32_C(   962992801), -INT32_C(   592665491), -INT32_C(  1992940347),  INT32_C(  1074077249),  INT32_C(  1186987184), -INT32_C(    43435561), -INT32_C(   942700317),
         INT32_C(   923346136),  INT32_C(  1996333577),  INT32_C(   206743878),  INT32_C(   244680909),  INT32_C(  1464834982),  INT32_C(  1855786647),  INT32_C(   711657031),  INT32_C(  1743862415) },
      {  INT32_C(  1738472286), -INT32_C(   455238755),  INT32_C(   300953412),  INT32_C(  1579124151), -INT32_C(  1212846560), -INT32_C(  1004187011), -INT32_C(   403730344),  INT32_C(   676257994),
         INT32_C(  2039475419), -INT32_C(   883069817),  INT32_C(  1406946715), -INT32_C(   206439214), -INT32_C(   408263062),  INT32_C(   279761080),  INT32_C(   737712992),  INT32_C(  1465075323) },
      {  INT32_C(  1112887268),  INT32_C(  1738472286), -INT32_C(   962992801), -INT32_C(   455238755),  INT32_C(  1074077249), -INT32_C(   507998811),  INT32_C(    58751659),  INT32_C(  1267661540),
         INT32_C(   984415024),  INT32_C(  2039475419), -INT32_C(  2006493552),  INT32_C(   560981515),  INT32_C(  1464834982), -INT32_C(  1828750105),  INT32_C(  1855786647),  INT32_C(   279761080) } },
    { { -INT32_C(  1160715469), -INT32_C(   343528113),  INT32_C(  1279156858), -INT32_C(   918556834),  INT32_C(   229698133),  INT32_C(   438131898),  INT32_C(  1933907447), -INT32_C(  1882547876),
        -INT32_C(   884368772),  INT32_C(  1102499783), -INT32_C(  1869745102),  INT32_C(   945409507),  INT32_C(  1900350135),  INT32_C(  1586193254), -INT32_C(   724446856), -INT32_C(   429679766) },
      UINT16_C(44341),
      {  INT32_C(  1753021617), -INT32_C(   899895747), -INT32_C(  1734918081), -INT32_C(  1096659336),  INT32_C(  1260456383),  INT32_C(   941398375), -INT32_C(   774666642),  INT32_C(   494798956),
         INT32_C(  1099299588), -INT32_C(   401874263), -INT32_C(  1702780126), -INT32_C(  1319623695), -INT32_C(  1812170452), -INT32_C(  2117396461),  INT32_C(   173186718), -INT32_C(  1440231002) },
      {  INT32_C(  1978379724), -INT32_C(  1319176305), -INT32_C(  1957961830),  INT32_C(   792503298),  INT32_C(   818034717), -INT32_C(   290353584), -INT32_C(   738720724), -INT32_C(  1585635115),
         INT32_C(  1544972749), -INT32_C(    99781536),  INT32_C(  1451579475),  INT32_C(   444973820),  INT32_C(  1263159290),  INT32_C(    37354709), -INT32_C(   707448320),  INT32_C(   527848018) },
      {  INT32_C(  1753021617), -INT32_C(   343528113), -INT32_C(   899895747), -INT32_C(   918556834),  INT32_C(  1260456383),  INT32_C(   818034717),  INT32_C(  1933907447), -INT32_C(  1882547876),
         INT32_C(  1099299588),  INT32_C(  1102499783), -INT32_C(   401874263), -INT32_C(    99781536),  INT32_C(  1900350135),  INT32_C(  1263159290), -INT32_C(   724446856),  INT32_C(    37354709) } },
    { {  INT32_C(   461081787),  INT32_C(  1410697217), -INT32_C(   576021536),  INT32_C(  1475817309),  INT32_C(  1285702007),  INT32_C(  1028578365),  INT32_C(  1611801358),  INT32_C(   830441590),
         INT32_C(   374209045),  INT32_C(  1651139202),  INT32_C(  1514083837), -INT32_C(  1145948604), -INT32_C(  1257745288),  INT32_C(  1056134704), -INT32_C(   258079366), -INT32_C(  1558110834) },
      UINT16_C(28183),
      {  INT32_C(   600938937),  INT32_C(   993578748), -INT32_C(   613253847),  INT32_C(  1076881976), -INT32_C(  1835573089),  INT32_C(  1033376158),  INT32_C(   576333313), -INT32_C(  2104397111),
         INT32_C(   128279051),  INT32_C(  1497620016), -INT32_C(  1825262245),  INT32_C(  1054106783),  INT32_C(  1657891780),  INT32_C(  2107599228),  INT32_C(  1486879375),  INT32_C(  2010787948) },
      { -INT32_C(  1015054446), -INT32_C(  1206074787),  INT32_C(   374100343),  INT32_C(  2035556533),  INT32_C(   131802507),  INT32_C(   495221646), -INT32_C(   512416907), -INT32_C(   430420140),
         INT32_C(   749328335),  INT32_C(   283494041), -INT32_C(   869912297), -INT32_C(   599426223),  INT32_C(   803414176),  INT32_C(   273442715), -INT32_C(   554581366), -INT32_C(   523941359) },
      {  INT32_C(   600938937), -INT32_C(  1015054446),  INT32_C(   993578748),  INT32_C(  1475817309), -INT32_C(  1835573089),  INT32_C(  1028578365),  INT32_C(  1611801358),  INT32_C(   830441590),
         INT32_C(   374209045),  INT32_C(   749328335),  INT32_C(  1497620016),  INT32_C(   283494041), -INT32_C(  1257745288),  INT32_C(   803414176),  INT32_C(  2107599228), -INT32_C(  1558110834) } },
    { { -INT32_C(  1156747743),  INT32_C(  1271657012),  INT32_C(  1947726371),  INT32_C(   223370349),  INT32_C(   406598525),  INT32_C(   606701978),  INT32_C(  1543707211), -INT32_C(  2042771356),
         INT32_C(  1799440950),  INT32_C(  1605766204),  INT32_C(  1809043198), -INT32_C(  1485233366), -INT32_C(   255806122), -INT32_C(  1995118274),  INT32_C(  1759909635),  INT32_C(   384705503) },
      UINT16_C(12141),
      {  INT32_C(   926656897), -INT32_C(   620414456),  INT32_C(   519975077), -INT32_C(  1747692329),  INT32_C(  1484788292), -INT32_C(  2106555236), -INT32_C(   626700308), -INT32_C(   435613083),
        -INT32_C(  1021426501),  INT32_C(   614343550),  INT32_C(   725785683),  INT32_C(   885135088), -INT32_C(   980663511), -INT32_C(  1287127865), -INT32_C(  1316098996), -INT32_C(  1181182210) },
      {  INT32_C(  1501345498),  INT32_C(   763173593), -INT32_C(  1504133194), -INT32_C(     2483498),  INT32_C(   616851037), -INT32_C(  1344861341), -INT32_C(   178232073), -INT32_C(   709953286),
        -INT32_C(  2010240338), -INT32_C(    88757436),  INT32_C(  1084231018), -INT32_C(  2059437529),  INT32_C(  1135150048),  INT32_C(    99778830), -INT32_C(   520465435), -INT32_C(    88758197) },
      {  INT32_C(   926656897),  INT32_C(  1271657012), -INT32_C(   620414456),  INT32_C(   763173593),  INT32_C(   406598525),  INT32_C(   616851037), -INT32_C(  2106555236), -INT32_C(  2042771356),
        -INT32_C(  1021426501), -INT32_C(  2010240338),  INT32_C(   614343550), -INT32_C(    88757436), -INT32_C(   255806122),  INT32_C(  1135150048),  INT32_C(  1759909635),  INT32_C(   384705503) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i src = simde_mm512_loadu_epi32(test_vec[i].src);
    simde__m512i a = simde_mm512_loadu_epi32(test_vec[i].a);
    simde__m512i b = simde_mm512_loadu_epi32(test_vec[i].b);
    simde__m512i r = simde_mm512_mask_unpacklo_epi32(src, test_vec[i].k, a, b);
    simde_test_x86_assert_equal_i32x16(r, simde_mm512_loadu_epi32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m512i src = simde_test_x86_random_i32x16();
    simde__mmask16 k = simde_test_x86_random_mmask16();
    simde__m512i a = simde_test_x86_random_i32x16();
    simde__m512i b = simde_test_x86_random_i32x16();
    simde__m512i r = simde_mm512_mask_unpacklo_epi32(src, k, a, b);

    simde_test_x86_write_i32x16(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask16(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x16(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_maskz_unpacklo_epi32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask16 k;
    const int32_t a[16];
    const int32_t b[16];
    const int32_t r[16];
  } test_vec[] = {
    { UINT16_C(47712),
      { -INT32_C(   581944344),  INT32_C(  2130127341), -INT32_C(  1400399223), -INT32_C(  1162656147),  INT32_C(   549691884),  INT32_C(   971634479), -INT32_C(  1036856418),  INT32_C(   293376809),
        -INT32_C(  1141977906),  INT32_C(  2134500854), -INT32_C(   315899520), -INT32_C(   207102201), -INT32_C(  1357616256),  INT32_C(    15334754), -INT32_C(   104653872),  INT32_C(  2097823662) },
      {  INT32_C(    37287948),  INT32_C(  1568764637),  INT32_C(   978038067),  INT32_C(   204337804), -INT32_C(  1078247075),  INT32_C(   247505982),  INT32_C(  1845986240), -INT32_C(   823455294),
        -INT32_C(   405789687), -INT32_C(   918269290), -INT32_C(  1962700801), -INT32_C(   543739774), -INT32_C(  1331735950), -INT32_C(  1212194825), -INT32_C(  1541028126), -INT32_C(   512552488) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(  1078247075),  INT32_C(   971634479),  INT32_C(           0),
         INT32_C(           0), -INT32_C(   405789687),  INT32_C(           0), -INT32_C(   918269290), -INT32_C(  1357616256), -INT32_C(  1331735950),  INT32_C(           0), -INT32_C(  1212194825) } },
    { UINT16_C(17205),
      {  INT32_C(   227920840), -INT32_C(  1751346028), -INT32_C(  1228464609), -INT32_C(  1660339714), -INT32_C(  1443102486), -INT32_C(   596648265), -INT32_C(   168999038), -INT32_C(   247913943),
        -INT32_C(  2114007315), -INT32_C(  2112316573), -INT32_C(  1220943687),  INT32_C(    55853593), -INT32_C(   106147774), -INT32_C(  1311433682), -INT32_C(  1935228061), -INT32_C(   746659867) },
      {  INT32_C(   290749614), -INT32_C(   778867433),  INT32_C(  1720241229),  INT32_C(  1349180686),  INT32_C(  1548293677), -INT32_C(  1777524942), -INT32_C(   954027038),  INT32_C(  1100652691),
         INT32_C(   877850397), -INT32_C(  1459231396), -INT32_C(  1072722254), -INT32_C(  1743685269), -INT32_C(  1024173424),  INT32_C(  1532494201),  INT32_C(  1210284981),  INT32_C(   948550939) },
      {  INT32_C(   227920840),  INT32_C(           0), -INT32_C(  1751346028),  INT32_C(           0), -INT32_C(  1443102486),  INT32_C(  1548293677),  INT32_C(           0),  INT32_C(           0),
        -INT32_C(  2114007315),  INT32_C(   877850397),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(  1311433682),  INT32_C(           0) } },
    { UINT16_C(56236),
      {  INT32_C(  1925187693), -INT32_C(  1056935247),  INT32_C(  1144679219), -INT32_C(   123811324), -INT32_C(   436594547), -INT32_C(  1772048525), -INT32_C(  2141946633),  INT32_C(   559612084),
        -INT32_C(  1164698871), -INT32_C(  1048865650),  INT32_C(    67483136),  INT32_C(   234660736),  INT32_C(   804517563), -INT32_C(  1664789595), -INT32_C(  2078533169),  INT32_C(   598046490) },
      {  INT32_C(   568146323), -INT32_C(   824026674), -INT32_C(  1882003697),  INT32_C(  1184747146),  INT32_C(  1786089669), -INT32_C(  1291371805),  INT32_C(  1849107284),  INT32_C(   781311131),
        -INT32_C(   464556522), -INT32_C(   692964921), -INT32_C(  1570339816),  INT32_C(   401081170),  INT32_C(  1988255123), -INT32_C(   332822120),  INT32_C(  1197105324),  INT32_C(  1400236861) },
      {  INT32_C(           0),  INT32_C(           0), -INT32_C(  1056935247), -INT32_C(   824026674),  INT32_C(           0),  INT32_C(  1786089669),  INT32_C(           0), -INT32_C(  1291371805),
        -INT32_C(  1164698871), -INT32_C(   464556522),  INT32_C(           0), -INT32_C(   692964921),  INT32_C(   804517563),  INT32_C(           0), -INT32_C(  1664789595), -INT32_C(   332822120) } },
    { UINT16_C(50265),
      { -INT32_C(   369811145),  INT32_C(  1567428087), -INT32_C(  1738489936),  INT32_C(  1509356503), -INT32_C(  1813868950), -INT32_C(   722170246),  INT32_C(  1270821334), -INT32_C(  1156573052),
         INT32_C(   832832825), -INT32_C(  1014099693), -INT32_C(  1487147056),  INT32_C(  1275089378),  INT32_C(  1507910367),  INT32_C(  1194185841), -INT32_C(  1986860027),  INT32_C(  1044685317) },
      { -INT32_C(  1150293848), -INT32_C(   914424071), -INT32_C(   814622227),  INT32_C(   169636139), -INT32_C(   983237548), -INT32_C(   720596528), -INT32_C(  2090951042), -INT32_C(   373185983),
        -INT32_C(  2086391414),  INT32_C(   474751535),  INT32_C(   652983803), -INT32_C(  2093938897), -INT32_C(   750217981), -INT32_C(  1532472282),  INT32_C(   858195698),  INT32_C(   840755624) },
      { -INT32_C(   369811145),  INT32_C(           0),  INT32_C(           0), -INT32_C(   914424071), -INT32_C(  1813868950),  INT32_C(           0), -INT32_C(   722170246),  INT32_C(           0),
         INT32_C(           0),  INT32_C(           0), -INT32_C(  1014099693),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(  1194185841), -INT32_C(  1532472282) } },
    { UINT16_C(49178),
      {  INT32_C(    48384437),  INT32_C(  1354751589),  INT32_C(   895020548), -INT32_C(  1177920655), -INT32_C(   686952145), -INT32_C(  1109524331),  INT32_C(  1353090611),  INT32_C(  1846591673),
         INT32_C(  1852896009), -INT32_C(   708955951), -INT32_C(  1878321634), -INT32_C(  1588996750),  INT32_C(  1551390662), -INT32_C(  1978050985), -INT32_C(  1764048931), -INT32_C(  2012943489) },
      { -INT32_C(  1342802466), -INT32_C(  1014713179),  INT32_C(  1028886475),  INT32_C(   736009573),  INT32_C(  1267160820), -INT32_C(  1965711187), -INT32_C(   568283041),  INT32_C(  2036737179),
         INT32_C(  1042832537), -INT32_C(   603804655), -INT32_C(  1592175300), -INT32_C(   422774798), -INT32_C(    97430451),  INT32_C(  1417938932),  INT32_C(  1379050679),  INT32_C(  1657510345) },
      {  INT32_C(           0), -INT32_C(  1342802466),  INT32_C(           0), -INT32_C(  1014713179), -INT32_C(   686952145),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
         INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(  1978050985),  INT32_C(  1417938932) } },
    { UINT16_C(62453),
      { -INT32_C(  1549859167), -INT32_C(    67576862),  INT32_C(  1240656764),  INT32_C(    60637393), -INT32_C(  1089826502),  INT32_C(   409190885), -INT32_C(   558814189),  INT32_C(   819046031),
        -INT32_C(  1881968467), -INT32_C(   930362548), -INT32_C(  2012119626), -INT32_C(   125063491),  INT32_C(   632788288),  INT32_C(  1765612118), -INT32_C(   699929017),  INT32_C(  1107695765) },
      { -INT32_C(   724444792),  INT32_C(  1537039524), -INT32_C(  1746686246), -INT32_C(  1651544483),  INT32_C(  1505904131), -INT32_C(  1463680927), -INT32_C(  2088891922), -INT32_C(  1446673375),
         INT32_C(    25073501), -INT32_C(   849601549),  INT32_C(   644169673), -INT32_C(  1329335123), -INT32_C(  1677097413),  INT32_C(  1950665606), -INT32_C(   168246572), -INT32_C(  1549812410) },
      { -INT32_C(  1549859167),  INT32_C(           0), -INT32_C(    67576862),  INT32_C(           0), -INT32_C(  1089826502),  INT32_C(  1505904131),  INT32_C(   409190885), -INT32_C(  1463680927),
        -INT32_C(  1881968467),  INT32_C(    25073501),  INT32_C(           0),  INT32_C(           0),  INT32_C(   632788288), -INT32_C(  1677097413),  INT32_C(  1765612118),  INT32_C(  1950665606) } },
    { UINT16_C( 7508),
      {  INT32_C(    20465828),  INT32_C(  2051014933), -INT32_C(   344986072), -INT32_C(  1468945762), -INT32_C(  1972111546),  INT32_C(  1682720876), -INT32_C(   601779651), -INT32_C(   637962699),
        -INT32_C(   740675138),  INT32_C(  1531845427), -INT32_C(  1488536311), -INT32_C(  1387284377),  INT32_C(   456639407),  INT32_C(  1216316171),  INT32_C(  1243980053), -INT32_C(   719118825) },
      { -INT32_C(  2086076848),  INT32_C(   585037337),  INT32_C(   449389747), -INT32_C(  1933108772), -INT32_C(   408420644), -INT32_C(  1775294591), -INT32_C(   538946360), -INT32_C(  1011612557),
         INT32_C(   457595906),  INT32_C(   104670291),  INT32_C(   622921288), -INT32_C(    72226785),  INT32_C(  1759664359),  INT32_C(  1207898751), -INT32_C(   651763866), -INT32_C(   442705181) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(  2051014933),  INT32_C(           0), -INT32_C(  1972111546),  INT32_C(           0),  INT32_C(  1682720876),  INT32_C(           0),
        -INT32_C(   740675138),  INT32_C(           0),  INT32_C(  1531845427),  INT32_C(   104670291),  INT32_C(   456639407),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
    { UINT16_C(57911),
      {  INT32_C(  1023838720), -INT32_C(  1320923248),  INT32_C(   630874996),  INT32_C(  1098744159), -INT32_C(   397148695),  INT32_C(  1808316996),  INT32_C(   809872275), -INT32_C(  1861059439),
        -INT32_C(  1748035322), -INT32_C(   599256216), -INT32_C(   721296778),  INT32_C(  1293385315), -INT32_C(  1070241157), -INT32_C(  1205076700),  INT32_C(   988311721), -INT32_C(   204735763) },
      {  INT32_C(  2072680979),  INT32_C(   609735597),  INT32_C(   435771573),  INT32_C(  1382420695), -INT32_C(  1626170501),  INT32_C(  1113013657), -INT32_C(  1686356050),  INT32_C(  1301169978),
        -INT32_C(  1882646046), -INT32_C(  1582096148),  INT32_C(  1354411385),  INT32_C(   950149309),  INT32_C(  1440265660), -INT32_C(  1600704526), -INT32_C(  1455746193),  INT32_C(  1022806618) },
      {  INT32_C(  1023838720),  INT32_C(  2072680979), -INT32_C(  1320923248),  INT32_C(           0), -INT32_C(   397148695), -INT32_C(  1626170501),  INT32_C(           0),  INT32_C(           0),
         INT32_C(           0), -INT32_C(  1882646046),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(  1440265660), -INT32_C(  1205076700), -INT32_C(  1600704526) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i a = simde_mm512_loadu_epi32(test_vec[i].a);
    simde__m512i b = simde_mm512_loadu_epi32(test_vec[i].b);
    simde__m512i r = simde_mm512_maskz_unpacklo_epi32(test_vec[i].k, a, b);
    simde_test_x86_assert_equal_i32x16(r, simde_mm512_loadu_epi32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask16 k = simde_test_x86_random_mmask16();
    simde__m512i a = simde_test_x86_random_i32x16();
    simde__m512i b = simde_test_x86_random_i32x16();
    simde__m512i r = simde_mm512_maskz_unpacklo_epi32(k, a, b);

    simde_test_x86_write_mmask16(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x16(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_mask_unpacklo_epi32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int32_t src[8];
    const simde__mmask8 k;
    const int32_t a[8];
    const int32_t b[8];
    const int32_t r[8];
  } test_vec[] = {
    { {  INT32_C(    12388951), -INT32_C(  1298552375), -INT32_C(  1684421387),  INT32_C(  2016179035),  INT32_C(  1020917509), -INT32_C(  1539474872), -INT32_C(  1556313156), -INT32_C(     9267033) },
      UINT8_C(163),
      { -INT32_C(   647168208),  INT32_C(  1557012120),  INT32_C(   733440695), -INT32_C(  1926221930), -INT32_C(  2099942392),  INT32_C(   893352617),  INT32_C(  1339876022), -INT32_C(  2064458924) },
      {  INT32_C(  1935564506),  INT32_C(   885992573),  INT32_C(   744458134), -INT32_C(  1078292554), -INT32_C(  1522429957), -INT32_C(  1059422199), -INT32_C(  1223707038),  INT32_C(  1815806354) },
      { -INT32_C(   647168208),  INT32_C(  1935564506), -INT32_C(  1684421387),  INT32_C(  2016179035),  INT32_C(  1020917509), -INT32_C(  1522429957), -INT32_C(  1556313156), -INT32_C(  1059422199) } },
    { { -INT32_C(   589325985),  INT32_C(  1544662982), -INT32_C(   326537162), -INT32_C(    72662272), -INT32_C(   593433134), -INT32_C(   795051411), -INT32_C(  1014518991),  INT32_C(   187679404) },
      UINT8_C( 92),
      { -INT32_C(  1105008625),  INT32_C(  1777630969),  INT32_C(  1248452615),  INT32_C(  2031969676), -INT32_C(  2132346619),  INT32_C(  1085388437),  INT32_C(    15496253), -INT32_C(  1302530141) },
      { -INT32_C(   663716129),  INT32_C(    71460092), -INT32_C(   783373499),  INT32_C(   373975824), -INT32_C(   107597724),  INT32_C(   607733735),  INT32_C(  1579427259), -INT32_C(    65961955) },
      { -INT32_C(   589325985),  INT32_C(  1544662982),  INT32_C(  1777630969),  INT32_C(    71460092), -INT32_C(  2132346619), -INT32_C(   795051411),  INT32_C(  1085388437),  INT32_C(   187679404) } },
    { { -INT32_C(    69893634),  INT32_C(   738138086), -INT32_C(   738439742),  INT32_C(   501827257),  INT32_C(  1561821046), -INT32_C(  2122166074), -INT32_C(  1814059402),  INT32_C(   630190119) },
      UINT8_C(114),
      {  INT32_C(  2069373028),  INT32_C(  1832813343), -INT32_C(   987360897),  INT32_C(  2033927162), -INT32_C(  1421895334), -INT32_C(  1054752741), -INT32_C(  1863797601), -INT32_C(  1476260285) },
      {  INT32_C(  1310939694),  INT32_C(  1555784157),  INT32_C(  1814159730),  INT32_C(  2145737764),  INT32_C(   271197429), -INT32_C(  2066592796),  INT32_C(  1108654847), -INT32_C(   135653688) },
      { -INT32_C(    69893634),  INT32_C(  1310939694), -INT32_C(   738439742),  INT32_C(   501827257), -INT32_C(  1421895334),  INT32_C(   271197429), -INT32_C(  1054752741),  INT32_C(   630190119) } },
    { {  INT32_C(  1296371312), -INT32_C(   492240785),  INT32_C(    89049825),  INT32_C(   478426150),  INT32_C(  1026338392), -INT32_C(   121504007), -INT32_C(  2126785095),  INT32_C(  1534600683) },
      UINT8_C( 51),
      { -INT32_C(  1113347907),  INT32_C(   463373649),  INT32_C(   121742547), -INT32_C(   681550552), -INT32_C(  1999594102),  INT32_C(   859949406),  INT32_C(   689881860), -INT32_C(   111314629) },
      {  INT32_C(  1924530209),  INT32_C(  1485657477),  INT32_C(   559992569), -INT32_C(  1225211860), -INT32_C(  1153513123), -INT32_C(  1762754414),  INT32_C(  2126449731), -INT32_C(  1502143355) },
      { -INT32_C(  1113347907),  INT32_C(  1924530209),  INT32_C(    89049825),  INT32_C(   478426150), -INT32_C(  1999594102), -INT32_C(  1153513123), -INT32_C(  2126785095),  INT32_C(  1534600683) } },
    { { -INT32_C(  1592250852),  INT32_C(  2096801155), -INT32_C(  1617077645),  INT32_C(  2002097690), -INT32_C(   248343457),  INT32_C(  1468473364), -INT32_C(  1311422932),  INT32_C(  2136427875) },
      UINT8_C(123),
      {  INT32_C(   352199023),  INT32_C(  1971812891), -INT32_C(  1383127273),  INT32_C(   269223548),  INT32_C(  1478819128), -INT32_C(   880510076), -INT32_C(  1641138863), -INT32_C(    82203252) },
      { -INT32_C(   384886834), -INT32_C(  1470196079),  INT32_C(   978775485),  INT32_C(   726295283), -INT32_C(   461148320),  INT32_C(  1001326570), -INT32_C(   925246148),  INT32_C(  1506013835) },
      {  INT32_C(   352199023), -INT32_C(   384886834), -INT32_C(  1617077645), -INT32_C(  1470196079),  INT32_C(  1478819128), -INT32_C(   461148320), -INT32_C(   880510076),  INT32_C(  2136427875) } },
    { { -INT32_C(  1706831351),  INT32_C(   641966441), -INT32_C(  2107598449),  INT32_C(  1538173947),  INT32_C(    71315738),  INT32_C(  1967189817),  INT32_C(  1480464845),  INT32_C(   363921676) },
      UINT8_C(212),
      { -INT32_C(  1774341900), -INT32_C(  1943706637),  INT32_C(  1871161284), -INT32_C(  2021006507),  INT32_C(   314608931), -INT32_C(   404802099),  INT32_C(  1978873715), -INT32_C(   582416151) },
      { -INT32_C(  1418492232), -INT32_C(  1388865303), -INT32_C(  1793278144), -INT32_C(   987978334),  INT32_C(    14146611), -INT32_C(  2048411886), -INT32_C(   671425810), -INT32_C(  1682619421) },
      { -INT32_C(  1706831351),  INT32_C(   641966441), -INT32_C(  1943706637),  INT32_C(  1538173947),  INT32_C(   314608931),  INT32_C(  1967189817), -INT32_C(   404802099), -INT32_C(  2048411886) } },
    { { -INT32_C(  1287182135),  INT32_C(    23101121), -INT32_C(   543785667),  INT32_C(  1436857122), -INT32_C(  1588167537),  INT32_C(   556219699), -INT32_C(    67559144),  INT32_C(   781626981) },
      UINT8_C(214),
      {  INT32_C(  1553457629), -INT32_C(  1080453054), -INT32_C(   488539857), -INT32_C(  1720633571), -INT32_C(   892595315),  INT32_C(  1541598778), -INT32_C(  1782522393),  INT32_C(  1366028148) },
      {  INT32_C(   313328592), -INT32_C(   892254309), -INT32_C(   575884352),  INT32_C(  2004295402),  INT32_C(  1799439153),  INT32_C(   415638577),  INT32_C(  1974306561),  INT32_C(  1187453302) },
      { -INT32_C(  1287182135),  INT32_C(   313328592), -INT32_C(  1080453054),  INT32_C(  1436857122), -INT32_C(   892595315),  INT32_C(   556219699),  INT32_C(  1541598778),  INT32_C(   415638577) } },
    { { -INT32_C(  1218874340),  INT32_C(  2072128187), -INT32_C(   950456611),  INT32_C(  2101268556),  INT32_C(  1172865043), -INT32_C(  1520586844), -INT32_C(  1407513802),  INT32_C(  1089659428) },
      UINT8_C( 86),
      {  INT32_C(  1980954443), -INT32_C(  1470919303), -INT32_C(  1225516058), -INT32_C(   641043879),  INT32_C(   159190874),  INT32_C(  2000626540),  INT32_C(   547089214),  INT32_C(   695655390) },
      {  INT32_C(  1285523667), -INT32_C(    51055850),  INT32_C(  1739843854), -INT32_C(  1253999269), -INT32_C(   121651572),  INT32_C(   527498977), -INT32_C(   935392278), -INT32_C(  1158564121) },
      { -INT32_C(  1218874340),  INT32_C(  1285523667), -INT32_C(  1470919303),  INT32_C(  2101268556),  INT32_C(   159190874), -INT32_C(  1520586844),  INT32_C(  2000626540),  INT32_C(  1089659428) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256i src = simde_x_mm256_loadu_epi32(test_vec[i].src);
    simde__mmask8 k = test_vec[i].k;
    simde__m256i a = simde_x_mm256_loadu_epi32(test_vec[i].a);
    simde__m256i b = simde_x_mm256_loadu_epi32(test_vec[i].b);
    simde__m256i r = simde_mm256_mask_unpacklo_epi32(src, k, a, b);
    simde_test_x86_assert_equal_i32x8(r, simde_x_mm256_loadu_epi32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m256i src = simde_test_x86_random_i32x8();
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m256i a = simde_test_x86_random_i32x8();
    simde__m256i b = simde_test_x86_random_i32x8();
    simde__m256i r = simde_mm256_mask_unpacklo_epi32(src, k, a, b);

    simde_test_x86_write_i32x8(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_maskz_unpacklo_epi32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k;
    const int32_t a[8];
    const int32_t b[8];
    const int32_t r[8];
  } test_vec[] = {
    { UINT8_C(194),
      {  INT32_C(  1755533778),  INT32_C(  2066770464), -INT32_C(  1225087903),  INT32_C(   207576966), -INT32_C(   186308732),  INT32_C(   469145129),  INT32_C(  1813180898),  INT32_C(  1563413387) },
      {  INT32_C(  1036440092), -INT32_C(  1632045508),  INT32_C(   542421914), -INT32_C(  1775455214),  INT32_C(    76222939), -INT32_C(  1994423897), -INT32_C(    34197134),  INT32_C(   408626684) },
      {  INT32_C(           0),  INT32_C(  1036440092),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(   469145129), -INT32_C(  1994423897) } },
    { UINT8_C(247),
      {  INT32_C(   389240097), -INT32_C(  1045245682), -INT32_C(   623652314),  INT32_C(   280324607),  INT32_C(  1991817716),  INT32_C(   166216152),  INT32_C(  1543890487),  INT32_C(  1649614145) },
      { -INT32_C(  2122741901),  INT32_C(  2118265688), -INT32_C(    44558850),  INT32_C(  1930235262), -INT32_C(  1628846650),  INT32_C(  1051185415), -INT32_C(   124015433),  INT32_C(  1029369546) },
      {  INT32_C(   389240097), -INT32_C(  2122741901), -INT32_C(  1045245682),  INT32_C(           0),  INT32_C(  1991817716), -INT32_C(  1628846650),  INT32_C(   166216152),  INT32_C(  1051185415) } },
    { UINT8_C(117),
      { -INT32_C(     3227948),  INT32_C(   368921600), -INT32_C(  1298924891), -INT32_C(   847706616), -INT32_C(  1043064849),  INT32_C(  1803031487), -INT32_C(  1674219090), -INT32_C(  1626180917) },
      {  INT32_C(   815783984), -INT32_C(   783967188), -INT32_C(  1618683497), -INT32_C(   814940705), -INT32_C(   745520876),  INT32_C(    37685332),  INT32_C(  1168012409),  INT32_C(   400863463) },
      { -INT32_C(     3227948),  INT32_C(           0),  INT32_C(   368921600),  INT32_C(           0), -INT32_C(  1043064849), -INT32_C(   745520876),  INT32_C(  1803031487),  INT32_C(           0) } },
    { UINT8_C(144),
      {  INT32_C(   549275779),  INT32_C(  1723305613),  INT32_C(   256267794),  INT32_C(    52696514), -INT32_C(  1386743899), -INT32_C(  1423484618), -INT32_C(  1466798856), -INT32_C(   734418608) },
      {  INT32_C(  2146760433), -INT32_C(  1746556028), -INT32_C(  1012520191), -INT32_C(   439891392), -INT32_C(   124576062),  INT32_C(  1889778296),  INT32_C(  1981297958), -INT32_C(   800435745) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(  1386743899),  INT32_C(           0),  INT32_C(           0),  INT32_C(  1889778296) } },
    { UINT8_C( 71),
      { -INT32_C(   372486338),  INT32_C(  1625973557), -INT32_C(   727601655), -INT32_C(  1818851723), -INT32_C(   754217447),  INT32_C(  1744403250), -INT32_C(   448368492), -INT32_C(   114485318) },
      { -INT32_C(  1679623834),  INT32_C(  1711066460), -INT32_C(   264659589),  INT32_C(  1032048419), -INT32_C(  1877962914), -INT32_C(  1627977206),  INT32_C(   881081978), -INT32_C(  1154633387) },
      { -INT32_C(   372486338), -INT32_C(  1679623834),  INT32_C(  1625973557),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(  1744403250),  INT32_C(           0) } },
    { UINT8_C(170),
      { -INT32_C(   586787056), -INT32_C(   262640813),  INT32_C(  1947420837),  INT32_C(  1523732683),  INT32_C(  1801806433), -INT32_C(  1729821862),  INT32_C(   955062663),  INT32_C(  1474472007) },
      {  INT32_C(  1379199231), -INT32_C(   113079212), -INT32_C(  1620224300),  INT32_C(   133841062), -INT32_C(    59613278), -INT32_C(   359377054), -INT32_C(  1205698191),  INT32_C(   688850218) },
      {  INT32_C(           0),  INT32_C(  1379199231),  INT32_C(           0), -INT32_C(   113079212),  INT32_C(           0), -INT32_C(    59613278),  INT32_C(           0), -INT32_C(   359377054) } },
    { UINT8_C(237),
      { -INT32_C(   817791933),  INT32_C(   346241726), -INT32_C(   390380888), -INT32_C(  1685405124), -INT32_C(  1929476299), -INT32_C(  1644304357),  INT32_C(   264746250),  INT32_C(   134082756) },
      {  INT32_C(   735460972),  INT32_C(   557807993), -INT32_C(   133563716), -INT32_C(   225143875),  INT32_C(   914264602), -INT32_C(  2066514822), -INT32_C(   158033359), -INT32_C(   134377078) },
      { -INT32_C(   817791933),  INT32_C(           0),  INT32_C(   346241726),  INT32_C(   557807993),  INT32_C(           0),  INT32_C(   914264602), -INT32_C(  1644304357), -INT32_C(  2066514822) } },
    { UINT8_C(207),
      {  INT32_C(  1296573140),  INT32_C(  1544120673),  INT32_C(   102302322),  INT32_C(   673188758),  INT32_C(    94525065), -INT32_C(  1019795927),  INT32_C(  1263414714), -INT32_C(    31767254) },
      { -INT32_C(   934517913),  INT32_C(  1059345869), -INT32_C(   314229417), -INT32_C(   770349496), -INT32_C(   422070340), -INT32_C(  1733751074),  INT32_C(  1726281531), -INT32_C(  1553662148) },
      {  INT32_C(  1296573140), -INT32_C(   934517913),  INT32_C(  1544120673),  INT32_C(  1059345869),  INT32_C(           0),  INT32_C(           0), -INT32_C(  1019795927), -INT32_C(  1733751074) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__mmask8 k = test_vec[i].k;
    simde__m256i a = simde_x_mm256_loadu_epi32(test_vec[i].a);
    simde__m256i b = simde_x_mm256_loadu_epi32(test_vec[i].b);
    simde__m256i r = simde_mm256_maskz_unpacklo_epi32(k, a, b);
    simde_test_x86_assert_equal_i32x8(r, simde_x_mm256_loadu_epi32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m256i a = simde_test_x86_random_i32x8();
    simde__m256i b = simde_test_x86_random_i32x8();
    simde__m256i r = simde_mm256_maskz_unpacklo_epi32(k, a, b);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_mask_unpacklo_epi32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int32_t src[4];
    const simde__mmask8 k;
    const int32_t a[4];
    const int32_t b[4];
    const int32_t r[4];
  } test_vec[] = {
    { {  INT32_C(   899040477),  INT32_C(  1511846736),  INT32_C(   553284298),  INT32_C(   924901100) },
      UINT8_C(109),
      { -INT32_C(  1103591918),  INT32_C(  1905712195),  INT32_C(  1190807458), -INT32_C(  1121753223) },
      { -INT32_C(   250783235), -INT32_C(   390371211),  INT32_C(  1104468834),  INT32_C(   246287612) },
      { -INT32_C(  1103591918),  INT32_C(  1511846736),  INT32_C(  1905712195), -INT32_C(   390371211) } },
    { { -INT32_C(   707991918),  INT32_C(  1699177155),  INT32_C(   598491561), -INT32_C(  1495216216) },
      UINT8_C( 40),
      {  INT32_C(  1453234158),  INT32_C(   783844946),  INT32_C(  1714092378), -INT32_C(  1896335192) },
      {  INT32_C(  1716637188),  INT32_C(  1443936021),  INT32_C(   855585635),  INT32_C(    22783251) },
      { -INT32_C(   707991918),  INT32_C(  1699177155),  INT32_C(   598491561),  INT32_C(  1443936021) } },
    { { -INT32_C(  1906837188), -INT32_C(   641986433), -INT32_C(  1321146871),  INT32_C(   574634014) },
      UINT8_C(  6),
      {  INT32_C(  1209764241), -INT32_C(   861179239),  INT32_C(   383770225),  INT32_C(   844292409) },
      {  INT32_C(  1219616824), -INT32_C(  2091742563),  INT32_C(    60949450), -INT32_C(   720780221) },
      { -INT32_C(  1906837188),  INT32_C(  1219616824), -INT32_C(   861179239),  INT32_C(   574634014) } },
    { { -INT32_C(   434297523),  INT32_C(   145934743), -INT32_C(   534867289), -INT32_C(  1424854925) },
      UINT8_C( 80),
      {  INT32_C(  1307440323),  INT32_C(  1226338630), -INT32_C(   678618349),  INT32_C(  1227186724) },
      {  INT32_C(  1222642559),  INT32_C(  1357899966),  INT32_C(  1992544006), -INT32_C(  1530433823) },
      { -INT32_C(   434297523),  INT32_C(   145934743), -INT32_C(   534867289), -INT32_C(  1424854925) } },
    { { -INT32_C(  1460489118),  INT32_C(   955386405),  INT32_C(  1225817893),  INT32_C(  1620260321) },
      UINT8_C( 64),
      {  INT32_C(  1560193395),  INT32_C(  1751273112), -INT32_C(  2142643951),  INT32_C(  1424158368) },
      { -INT32_C(   361067552), -INT32_C(    66080131), -INT32_C(   136488766),  INT32_C(  1597521387) },
      { -INT32_C(  1460489118),  INT32_C(   955386405),  INT32_C(  1225817893),  INT32_C(  1620260321) } },
    { {  INT32_C(  2142975718), -INT32_C(  1763238523), -INT32_C(  1776930570), -INT32_C(    18089698) },
      UINT8_C(132),
      {  INT32_C(   386000997),  INT32_C(  1356529143),  INT32_C(   389796314),  INT32_C(  1090427401) },
      {  INT32_C(  1942322517), -INT32_C(  1805034652),  INT32_C(  1806893170),  INT32_C(  1357885931) },
      {  INT32_C(  2142975718), -INT32_C(  1763238523),  INT32_C(  1356529143), -INT32_C(    18089698) } },
    { { -INT32_C(  1855459174), -INT32_C(   941538835),  INT32_C(   484318483),  INT32_C(   224189623) },
      UINT8_C( 89),
      {  INT32_C(  2109571105), -INT32_C(   370191639), -INT32_C(  1227597307),  INT32_C(   961553481) },
      { -INT32_C(   853089652), -INT32_C(   522129981), -INT32_C(  1466368565),  INT32_C(  2063705433) },
      {  INT32_C(  2109571105), -INT32_C(   941538835),  INT32_C(   484318483), -INT32_C(   522129981) } },
    { {  INT32_C(   251182885),  INT32_C(   385410833), -INT32_C(  1966289855),  INT32_C(  2109939185) },
         UINT8_MAX,
      { -INT32_C(   691909911),  INT32_C(   681681707), -INT32_C(   528398021),  INT32_C(   168164427) },
      { -INT32_C(   618982412), -INT32_C(   669241077),  INT32_C(   449423101),  INT32_C(  1377388137) },
      { -INT32_C(   691909911), -INT32_C(   618982412),  INT32_C(   681681707), -INT32_C(   669241077) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i src = simde_x_mm_loadu_epi32(test_vec[i].src);
    simde__m128i a = simde_x_mm_loadu_epi32(test_vec[i].a);
    simde__m128i b = simde_x_mm_loadu_epi32(test_vec[i].b);
    simde__m128i r = simde_mm_mask_unpacklo_epi32(src, test_vec[i].k, a, b);
    simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i src = simde_test_x86_random_i32x4();
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m128i a = simde_test_x86_random_i32x4();
    simde__m128i b = simde_test_x86_random_i32x4();
    simde__m128i r = simde_mm_mask_unpacklo_epi32(src, k, a, b);

    simde_test_x86_write_i32x4(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_maskz_unpacklo_epi32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k;
    const int32_t a[4];
    const int32_t b[4];
    const int32_t r[4];
  } test_vec[] = {
    { UINT8_C(114),
      { -INT32_C(   431612970), -INT32_C(   198702228), -INT32_C(  1076077297), -INT32_C(   561540392) },
      {  INT32_C(  1307826319), -INT32_C(  1357481851),  INT32_C(  1473891128), -INT32_C(  1379217449) },
      {  INT32_C(           0),  INT32_C(  1307826319),  INT32_C(           0),  INT32_C(           0) } },
    { UINT8_C(235),
      {  INT32_C(   458724368),  INT32_C(   422268092), -INT32_C(  1141708248),  INT32_C(  1246417010) },
      {  INT32_C(  1020303299),  INT32_C(  2037677997),  INT32_C(   659606616), -INT32_C(  1508704618) },
      {  INT32_C(   458724368),  INT32_C(  1020303299),  INT32_C(           0),  INT32_C(  2037677997) } },
    { UINT8_C(146),
      { -INT32_C(  1236352662), -INT32_C(   673290260),  INT32_C(   692689241),  INT32_C(  2079167460) },
      { -INT32_C(   500618909),  INT32_C(  1765450397), -INT32_C(   251698446), -INT32_C(   561863308) },
      {  INT32_C(           0), -INT32_C(   500618909),  INT32_C(           0),  INT32_C(           0) } },
    { UINT8_C(103),
      {  INT32_C(   945001680),  INT32_C(   210840179),  INT32_C(   133217139), -INT32_C(   781554520) },
      {  INT32_C(   929975701), -INT32_C(   383133561),  INT32_C(  2103319255),  INT32_C(  1843674268) },
      {  INT32_C(   945001680),  INT32_C(   929975701),  INT32_C(   210840179),  INT32_C(           0) } },
    { UINT8_C(209),
      {  INT32_C(  1648665911), -INT32_C(   237678538), -INT32_C(  1382425535), -INT32_C(  1807586745) },
      { -INT32_C(  1323599399), -INT32_C(  1131936350), -INT32_C(  1621555869),  INT32_C(   561039081) },
      {  INT32_C(  1648665911),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
    { UINT8_C(107),
      {  INT32_C(    94471092),  INT32_C(   893817688), -INT32_C(  1753418964), -INT32_C(  1368387531) },
      {  INT32_C(   810557739), -INT32_C(  1349317207),  INT32_C(   748172134),  INT32_C(  1486338467) },
      {  INT32_C(    94471092),  INT32_C(   810557739),  INT32_C(           0), -INT32_C(  1349317207) } },
    { UINT8_C( 60),
      { -INT32_C(   879403720), -INT32_C(  1762080093),  INT32_C(  1456181062),  INT32_C(   545356287) },
      { -INT32_C(   691424567),  INT32_C(  2017228869), -INT32_C(   904108015),  INT32_C(   940012799) },
      {  INT32_C(           0),  INT32_C(           0), -INT32_C(  1762080093),  INT32_C(  2017228869) } },
    { UINT8_C(209),
      {  INT32_C(  1718879132), -INT32_C(  1968436485),  INT32_C(  1317602005),  INT32_C(   890743171) },
      { -INT32_C(   344199565), -INT32_C(  1812139222), -INT32_C(  2087532785),  INT32_C(  1783941838) },
      {  INT32_C(  1718879132),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_x_mm_loadu_epi32(test_vec[i].a);
    simde__m128i b = simde_x_mm_loadu_epi32(test_vec[i].b);
    simde__m128i r = simde_mm_maskz_unpacklo_epi32(test_vec[i].k, a, b);
    simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m128i a = simde_test_x86_random_i32x4();
    simde__m128i b = simde_test_x86_random_i32x4();
    simde__m128i r = simde_mm_maskz_unpacklo_epi32(k, a, b);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x4(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
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
test_simde_mm512_mask_unpacklo_epi64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int64_t src[8];
    const simde__mmask8 k;
    const int64_t a[8];
    const int64_t b[8];
    const int64_t r[8];
  } test_vec[] = {
    { {  INT64_C( 1990976127771707154),  INT64_C( 6818482592690236278), -INT64_C( 1161026019682441753),  INT64_C( 7316852212137329831),
         INT64_C( 8903153592332560181),  INT64_C( 1148390591408048838), -INT64_C( 6739500522084448627), -INT64_C( 2938811367090228352) },
      UINT8_C(229),
      { -INT64_C( 2084490598329726223),  INT64_C( 6350667637118968493),  INT64_C( 1634513246231964595), -INT64_C( 6211431761726373463),
        -INT64_C( 3849443961668782375),  INT64_C( 7895797208570634154), -INT64_C( 8906348907284666836), -INT64_C( 8778298880301523253) },
      { -INT64_C( 3110636961674091794), -INT64_C( 2264567668502744213),  INT64_C( 4893607913952652937),  INT64_C( 8856314976508728756),
         INT64_C( 6202681449435700758),  INT64_C( 5774193916907299725), -INT64_C( 7136060362243878340), -INT64_C( 4036662664959771149) },
      { -INT64_C( 2084490598329726223),  INT64_C( 6818482592690236278),  INT64_C( 1634513246231964595),  INT64_C( 7316852212137329831),
         INT64_C( 8903153592332560181),  INT64_C( 6202681449435700758), -INT64_C( 8906348907284666836), -INT64_C( 7136060362243878340) } },
    { {  INT64_C( 7368764038106808066),  INT64_C(  600608003429219902), -INT64_C( 7160807348297266661), -INT64_C( 8941590845583483791),
         INT64_C( 5320355396503793814),  INT64_C( 7009469392137124977),  INT64_C( 2878368293023187885), -INT64_C( 4997814555715760479) },
      UINT8_C( 34),
      {  INT64_C( 8879260076484667668), -INT64_C( 4605455372021303355),  INT64_C( 7795060658968947847),  INT64_C(  521656639339712232),
        -INT64_C( 6346125060514813323),  INT64_C( 6484381722876096383), -INT64_C(  405867043839708013), -INT64_C( 5810960483719188639) },
      { -INT64_C( 5673109246504129860),  INT64_C( 1075493327030080961),  INT64_C( 5002477621343212127), -INT64_C( 8126756713704881843),
         INT64_C( 3171504367864732191),  INT64_C( 4274387583380746695), -INT64_C(  240914338998824578),  INT64_C( 6268090623832899994) },
      {  INT64_C( 7368764038106808066), -INT64_C( 5673109246504129860), -INT64_C( 7160807348297266661), -INT64_C( 8941590845583483791),
         INT64_C( 5320355396503793814),  INT64_C( 3171504367864732191),  INT64_C( 2878368293023187885), -INT64_C( 4997814555715760479) } },
    { {  INT64_C( 7254643263425489429), -INT64_C( 7586885213231813475),  INT64_C( 1582629872914227786),  INT64_C( 5363644447747898082),
         INT64_C( 6893172380945487784), -INT64_C( 7884802078464716572),  INT64_C( 1117035839177395440),  INT64_C( 2989149354526769916) },
      UINT8_C(174),
      {  INT64_C( 7467478457538145861), -INT64_C( 4888866095627264599),  INT64_C( 1462817836050780878),  INT64_C( 4424715134389550369),
         INT64_C( 5956744608443193388),  INT64_C( 7576938704146159929),  INT64_C( 3056542305473859396), -INT64_C( 1533393491153715070) },
      { -INT64_C( 8710287895854992861), -INT64_C( 7046701462710081488),  INT64_C( 8599728990828424998), -INT64_C( 6266853962969695393),
         INT64_C( 4337409594448229468),  INT64_C( 6788117851598758204), -INT64_C( 1758403281647032276), -INT64_C( 8120258187157468896) },
      {  INT64_C( 7254643263425489429), -INT64_C( 8710287895854992861),  INT64_C( 1462817836050780878),  INT64_C( 8599728990828424998),
         INT64_C( 6893172380945487784),  INT64_C( 4337409594448229468),  INT64_C( 1117035839177395440), -INT64_C( 1758403281647032276) } },
    { { -INT64_C( 7743822631795047359), -INT64_C(  422952647865495413), -INT64_C( 5478994452471370106),  INT64_C( 5260108739206904637),
         INT64_C( 3267957064564291694),  INT64_C( 7527224591164474542), -INT64_C( 9077166379421429056),  INT64_C( 8698967707396235624) },
      UINT8_C( 41),
      {  INT64_C( 2024642465525087821), -INT64_C( 7080389737969707798),  INT64_C( 8697406456114319582),  INT64_C( 2842611229778977367),
         INT64_C( 2445360279418191418),  INT64_C( 3668140477072141631), -INT64_C( 8756352076323370517),  INT64_C( 3698935207425998419) },
      { -INT64_C( 3397977387654781057), -INT64_C( 5014474720605964830),  INT64_C( 7673913965687990219),  INT64_C( 1108991136792858166),
         INT64_C( 4627058695929752020),  INT64_C( 2097799270403362962),  INT64_C( 5137083328470899144), -INT64_C( 6663960964054392092) },
      {  INT64_C( 2024642465525087821), -INT64_C(  422952647865495413), -INT64_C( 5478994452471370106),  INT64_C( 7673913965687990219),
         INT64_C( 3267957064564291694),  INT64_C( 4627058695929752020), -INT64_C( 9077166379421429056),  INT64_C( 8698967707396235624) } },
    { {  INT64_C( 8854427506947148355),  INT64_C(  215882763941468559), -INT64_C( 8130356689319684910), -INT64_C( 4647847320086142451),
         INT64_C( 6139323038805559505), -INT64_C( 2749953314233380966), -INT64_C( 1044016097852016567), -INT64_C( 2322365314495576438) },
      UINT8_C(213),
      { -INT64_C( 2737641242562422747),  INT64_C( 7252409123917124903), -INT64_C( 6779544598822283144), -INT64_C( 2726773764440264698),
        -INT64_C( 2537143194689158363), -INT64_C( 2366679641433265129), -INT64_C( 5966942231632843147), -INT64_C( 7806945501974044647) },
      {  INT64_C( 4718732454566029547),  INT64_C(  450407866135000314), -INT64_C( 4472698229945303143),  INT64_C(  119687428814400936),
         INT64_C( 8397556866244226079),  INT64_C( 6010077588697222865),  INT64_C( 8141806398365499284), -INT64_C( 2052181538408854418) },
      { -INT64_C( 2737641242562422747),  INT64_C(  215882763941468559), -INT64_C( 6779544598822283144), -INT64_C( 4647847320086142451),
        -INT64_C( 2537143194689158363), -INT64_C( 2749953314233380966), -INT64_C( 5966942231632843147),  INT64_C( 8141806398365499284) } },
    { {  INT64_C( 1462464005995767388), -INT64_C( 3867784802162302907), -INT64_C( 3092279255224556066),  INT64_C( 2898029854406057361),
         INT64_C( 6943224731554243588), -INT64_C( 8256310123985645206),  INT64_C(  563594778289336983),  INT64_C(  998834887242558439) },
      UINT8_C(247),
      { -INT64_C( 9182993919106722597),  INT64_C(  944557022499582162),  INT64_C( 1594991060474599665), -INT64_C( 8326542520773192217),
        -INT64_C( 3840935002247166846), -INT64_C( 8063297526002949519),  INT64_C( 1045940292064877697),  INT64_C( 5909281058813748163) },
      {  INT64_C( 7224115696589124223),  INT64_C( 8739386778234949400), -INT64_C( 4297444490095488218),  INT64_C( 6858764395438728460),
         INT64_C(   91224185704461292),  INT64_C( 7212515072184726694),  INT64_C( 8347718120704704020),  INT64_C( 3977380285037613554) },
      { -INT64_C( 9182993919106722597),  INT64_C( 7224115696589124223),  INT64_C( 1594991060474599665),  INT64_C( 2898029854406057361),
        -INT64_C( 3840935002247166846),  INT64_C(   91224185704461292),  INT64_C( 1045940292064877697),  INT64_C( 8347718120704704020) } },
    { { -INT64_C( 4171641535905527759), -INT64_C( 1679422835247426545),  INT64_C( 7085805369070281339),  INT64_C( 6082787647597946088),
        -INT64_C( 1560907545228378001), -INT64_C( 5540579588474160290), -INT64_C( 2945940265882019510),  INT64_C( 2884120952265396878) },
      UINT8_C(245),
      { -INT64_C( 3936504450691057547), -INT64_C( 4241347769584741903),  INT64_C( 5602914421957844553), -INT64_C( 1296985595271810153),
         INT64_C( 8916365897450246374), -INT64_C( 4949886507107959076),  INT64_C( 2854913347695805270), -INT64_C( 5077188650250099677) },
      { -INT64_C( 6986934859232086269),  INT64_C( 3195154224269254185),  INT64_C( 1815262868358907514), -INT64_C( 7328975523374865217),
        -INT64_C( 8351588631165994826),  INT64_C( 3716174172010332560), -INT64_C( 1597248263495544890),  INT64_C( 9152657811589204691) },
      { -INT64_C( 3936504450691057547), -INT64_C( 1679422835247426545),  INT64_C( 5602914421957844553),  INT64_C( 6082787647597946088),
         INT64_C( 8916365897450246374), -INT64_C( 8351588631165994826),  INT64_C( 2854913347695805270), -INT64_C( 1597248263495544890) } },
    { { -INT64_C( 1176545202866147907),  INT64_C( 1963542315022013779), -INT64_C( 4753077805844562698),  INT64_C(  395803608796922678),
        -INT64_C( 2474496506281494694), -INT64_C( 2731669685016068697), -INT64_C( 3436805503244898652), -INT64_C(   84357122756741242) },
      UINT8_C(197),
      {  INT64_C( 6661715964260694010),  INT64_C( 8422041941998333716),  INT64_C( 3935546561698623764),  INT64_C( 4305397546682576045),
         INT64_C( 5641455872460131983), -INT64_C( 5124133597027333399),  INT64_C( 8994372144268833244),  INT64_C( 1537194793119428057) },
      { -INT64_C( 4626517509065712572), -INT64_C( 7046706519224723752),  INT64_C( 5426006813327361282),  INT64_C( 4491421411875144889),
         INT64_C( 9128382641471182616), -INT64_C( 1135979204576551715),  INT64_C( 4391871119746037301),  INT64_C( 3173858050666355155) },
      {  INT64_C( 6661715964260694010),  INT64_C( 1963542315022013779),  INT64_C( 3935546561698623764),  INT64_C(  395803608796922678),
        -INT64_C( 2474496506281494694), -INT64_C( 2731669685016068697),  INT64_C( 8994372144268833244),  INT64_C( 4391871119746037301) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i src = simde_mm512_loadu_epi64(test_vec[i].src);
    simde__m512i a = simde_mm512_loadu_epi64(test_vec[i].a);
    simde__m512i b = simde_mm512_loadu_epi64(test_vec[i].b);
    simde__m512i r = simde_mm512_mask_unpacklo_epi64(src, test_vec[i].k, a, b);
    simde_test_x86_assert_equal_i64x8(r, simde_mm512_loadu_epi64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m512i src = simde_test_x86_random_i64x8();
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m512i a = simde_test_x86_random_i64x8();
    simde__m512i b = simde_test_x86_random_i64x8();
    simde__m512i r = simde_mm512_mask_unpacklo_epi64(src, k, a, b);

    simde_test_x86_write_i64x8(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_maskz_unpacklo_epi64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k;
    const int64_t a[8];
    const int64_t b[8];
    const int64_t r[8];
  } test_vec[] = {
    { UINT8_C(135),
      {  INT64_C( 5997346146907478552),  INT64_C( 2075635314867612939), -INT64_C( 7444306986998658330),  INT64_C( 2361377173615619820),
         INT64_C( 2703834445151551398),  INT64_C( 9155620791566366369),  INT64_C( 8839678273339788503), -INT64_C( 5679744969104376058) },
      {  INT64_C( 8934132149442045629), -INT64_C( 6991980501285307681), -INT64_C(  174692644684750966), -INT64_C( 8657826372048434404),
         INT64_C(  320981692105800735), -INT64_C( 1568813561894083883),  INT64_C( 7388320431310367891), -INT64_C( 1499022696723409951) },
      {  INT64_C( 5997346146907478552),  INT64_C( 8934132149442045629), -INT64_C( 7444306986998658330),  INT64_C(                   0),
         INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C( 7388320431310367891) } },
    { UINT8_C( 35),
      {  INT64_C( 4233750169004860560), -INT64_C( 8876166501655421495),  INT64_C( 8646968339413687432),  INT64_C( 7875159525303823297),
        -INT64_C( 6222537758966443245),  INT64_C( 5662072317344694391),  INT64_C( 6156541177205973268), -INT64_C(  692771610771475432) },
      {  INT64_C( 5612619647999392602), -INT64_C( 7539887230469485753),  INT64_C( 5637099594363947345), -INT64_C( 2698037159314343756),
         INT64_C( 4504717792948580449),  INT64_C( 2440292185590784195),  INT64_C( 2446933911755189617),  INT64_C( 4491013369485670649) },
      {  INT64_C( 4233750169004860560),  INT64_C( 5612619647999392602),  INT64_C(                   0),  INT64_C(                   0),
         INT64_C(                   0),  INT64_C( 4504717792948580449),  INT64_C(                   0),  INT64_C(                   0) } },
    { UINT8_C( 56),
      { -INT64_C( 2872331223799204505), -INT64_C( 5417046093354997063), -INT64_C( 6482013098656826928),  INT64_C( 4502687957286946044),
        -INT64_C( 3312184112485323977),  INT64_C( 5343528080863703340), -INT64_C( 8532800063991428736),  INT64_C( 1369176594447145451) },
      { -INT64_C( 8223208564378591243), -INT64_C( 7223448228899842564),  INT64_C( 8036426716132547954), -INT64_C( 7771468448178023112),
        -INT64_C( 5638642294671054383),  INT64_C( 6507959746726248345),  INT64_C( 3601719689418955271),  INT64_C( 3488155970725752117) },
      {  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C( 8036426716132547954),
        -INT64_C( 3312184112485323977), -INT64_C( 5638642294671054383),  INT64_C(                   0),  INT64_C(                   0) } },
    { UINT8_C(212),
      { -INT64_C( 2294518994817162741),  INT64_C(  528366109259783523),  INT64_C(  689105565477036411), -INT64_C( 2831188785026800523),
        -INT64_C( 2450925247371198726),  INT64_C( 7107102319668020333),  INT64_C( 5135877990436938080),  INT64_C( 4779969878635884465) },
      { -INT64_C( 5011845245556638437),  INT64_C( 8964403084001582110),  INT64_C( 2499216805302183062), -INT64_C( 3442731757544155217),
         INT64_C(  989059018966537906), -INT64_C( 7490479028326757005),  INT64_C( 8372384968160101789),  INT64_C( 8578129982758047879) },
      {  INT64_C(                   0),  INT64_C(                   0),  INT64_C(  689105565477036411),  INT64_C(                   0),
        -INT64_C( 2450925247371198726),  INT64_C(                   0),  INT64_C( 5135877990436938080),  INT64_C( 8372384968160101789) } },
    { UINT8_C( 57),
      {  INT64_C( 4376151039605831280),  INT64_C( 2044869898940598857),  INT64_C( 8001865881076461270), -INT64_C( 4278794221303609151),
         INT64_C( 5083656870666422049),  INT64_C( 8539785456068971025),  INT64_C( 8999609031617897943), -INT64_C( 1916423733394794160) },
      {  INT64_C( 5371036482300900165), -INT64_C( 3197214907570154869), -INT64_C(  733752877137683046),  INT64_C( 8570913247226016328),
         INT64_C( 8500336393077729395),  INT64_C( 8764922824543480277),  INT64_C( 7239993920322465247), -INT64_C( 8865225840113151662) },
      {  INT64_C( 4376151039605831280),  INT64_C(                   0),  INT64_C(                   0), -INT64_C(  733752877137683046),
         INT64_C( 5083656870666422049),  INT64_C( 8500336393077729395),  INT64_C(                   0),  INT64_C(                   0) } },
    { UINT8_C(140),
      { -INT64_C( 3329872987842858575),  INT64_C( 3074876891496159627), -INT64_C( 4978260267717218057),  INT64_C( 1516675567104846620),
        -INT64_C(  613947035048377983),  INT64_C( 5319719085192522348), -INT64_C( 2376834337726260832), -INT64_C( 6796376999899181259) },
      { -INT64_C(  697840744248133395),  INT64_C( 2633324319507158255),  INT64_C( 7651176191217200267), -INT64_C( 1873019185881969088),
         INT64_C(  138361525134904426), -INT64_C( 8625571975105639773),  INT64_C( 7627697168938678331), -INT64_C(  399471744726212972) },
      {  INT64_C(                   0),  INT64_C(                   0), -INT64_C( 4978260267717218057),  INT64_C( 7651176191217200267),
         INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C( 7627697168938678331) } },
    { UINT8_C( 23),
      {  INT64_C( 7270545765354303411),  INT64_C( 1331071358890741358), -INT64_C( 6747618455916386111),  INT64_C( 1174926431171570029),
         INT64_C( 1178318724102584092),  INT64_C( 7472533526199254088), -INT64_C(   66557207911600467), -INT64_C( 8151087122397837965) },
      { -INT64_C( 5282758171666664195),  INT64_C( 7973636064912407707), -INT64_C( 3058803541807212550),  INT64_C( 4988166808459985720),
         INT64_C( 4026380365813038523),  INT64_C( 4521369128194816143), -INT64_C( 3949561690910449928),  INT64_C( 1776578095104644633) },
      {  INT64_C( 7270545765354303411), -INT64_C( 5282758171666664195), -INT64_C( 6747618455916386111),  INT64_C(                   0),
         INT64_C( 1178318724102584092),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0) } },
    { UINT8_C(106),
      {  INT64_C( 6606567498941088396),  INT64_C( 6760146852414226358),  INT64_C( 3465721514713557672), -INT64_C( 5962301767381321174),
         INT64_C( 4352584475747370984), -INT64_C( 8315927617549957509),  INT64_C( 7393118643641025806), -INT64_C( 5338033517634968036) },
      { -INT64_C( 5726565295615592250), -INT64_C( 8314065483596129490), -INT64_C( 1753995051207940090),  INT64_C( 3041637721696495284),
         INT64_C( 5525632102390232777),  INT64_C( 2279943021076060312), -INT64_C( 2605603796580984796), -INT64_C( 2918734922541892369) },
      {  INT64_C(                   0), -INT64_C( 5726565295615592250),  INT64_C(                   0), -INT64_C( 1753995051207940090),
         INT64_C(                   0),  INT64_C( 5525632102390232777),  INT64_C( 7393118643641025806),  INT64_C(                   0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i a = simde_mm512_loadu_epi64(test_vec[i].a);
    simde__m512i b = simde_mm512_loadu_epi64(test_vec[i].b);
    simde__m512i r = simde_mm512_maskz_unpacklo_epi64(test_vec[i].k, a, b);
    simde_test_x86_assert_equal_i64x8(r, simde_mm512_loadu_epi64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m512i a = simde_test_x86_random_i64x8();
    simde__m512i b = simde_test_x86_random_i64x8();
    simde__m512i r = simde_mm512_maskz_unpacklo_epi64(k, a, b);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i64x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_mask_unpacklo_epi64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int64_t src[4];
    const simde__mmask8 k;
    const int64_t a[4];
    const int64_t b[4];
    const int64_t r[4];
  } test_vec[] = {
    { { -INT64_C( 2874760965420983185), -INT64_C( 3097497724342175480),  INT64_C( 4860183446693141791), -INT64_C( 8804493193375540556) },
      UINT8_C(132),
      { -INT64_C( 6228056413476317507), -INT64_C( 7991433351831178881),  INT64_C( 5811029689680610073), -INT64_C( 1217120671769402770) },
      { -INT64_C( 4622090421253127807), -INT64_C( 7926105024693223494),  INT64_C(  295873729119103252), -INT64_C( 1248704988744875639) },
      { -INT64_C( 2874760965420983185), -INT64_C( 3097497724342175480),  INT64_C( 5811029689680610073), -INT64_C( 8804493193375540556) } },
    { { -INT64_C( 1695610560917265289),  INT64_C( 1569036079046471610), -INT64_C(  388723056339629824),  INT64_C( 7050211403243074684) },
      UINT8_C(133),
      { -INT64_C( 4634877398939920137), -INT64_C( 1204479089671413519), -INT64_C( 6040916475795939660), -INT64_C( 2091930911295270128) },
      {  INT64_C( 3917711961404844560), -INT64_C( 6415158926345626014), -INT64_C( 4410853957076428636),  INT64_C( 7449001438450311059) },
      { -INT64_C( 4634877398939920137),  INT64_C( 1569036079046471610), -INT64_C( 6040916475795939660),  INT64_C( 7050211403243074684) } },
    { {  INT64_C( 1896127280213013973),  INT64_C( 4187252082277076867), -INT64_C( 8941580468871597708),  INT64_C( 2106948265646824831) },
      UINT8_C(151),
      {  INT64_C( 6209172542625625923),  INT64_C( 3322291746123850124),  INT64_C( 5195924903288521340),  INT64_C( 8186890110802915747) },
      { -INT64_C( 2179103036522435356),  INT64_C( 5823617026350427878),  INT64_C( 3844112080884789478),  INT64_C( 8834048808485382648) },
      {  INT64_C( 6209172542625625923), -INT64_C( 2179103036522435356),  INT64_C( 5195924903288521340),  INT64_C( 2106948265646824831) } },
    { { -INT64_C( 2379404773378641212),  INT64_C(  899122498984051285),  INT64_C( 7352819560029709891), -INT64_C( 2202500882156927649) },
      UINT8_C(215),
      {  INT64_C( 8598124806817118805),  INT64_C( 6684655718342949678), -INT64_C( 1613079613837502009),  INT64_C( 6321338651070862269) },
      {  INT64_C( 7083782009781520610),  INT64_C( 6733910126641802017),  INT64_C( 3156240958494555456), -INT64_C( 7051010032148818997) },
      {  INT64_C( 8598124806817118805),  INT64_C( 7083782009781520610), -INT64_C( 1613079613837502009), -INT64_C( 2202500882156927649) } },
    { {  INT64_C( 4748697397225683279), -INT64_C( 5647008770407478866),  INT64_C( 4656830267029535752), -INT64_C( 4283148138957590986) },
      UINT8_C(173),
      { -INT64_C(  615289808812751100), -INT64_C( 7550256895841748379), -INT64_C(  268162854139744593), -INT64_C( 3658552611802367655) },
      {  INT64_C( 8764297433717147261), -INT64_C( 3263172239500375612),  INT64_C( 7483622544397025936), -INT64_C(    1919188202140316) },
      { -INT64_C(  615289808812751100), -INT64_C( 5647008770407478866), -INT64_C(  268162854139744593),  INT64_C( 7483622544397025936) } },
    { {  INT64_C( 6756045508435414580), -INT64_C( 2357015042853147563), -INT64_C( 4870192918742290955), -INT64_C( 4582163532444246554) },
      UINT8_C(112),
      {  INT64_C( 3941607118226393106), -INT64_C( 6770488635763119134), -INT64_C( 3124733470853886686), -INT64_C( 8722593472300774496) },
      {  INT64_C( 4983680913899846696),  INT64_C( 3808186088830971586),  INT64_C( 3223611467679913074),  INT64_C( 7176102530339773596) },
      {  INT64_C( 6756045508435414580), -INT64_C( 2357015042853147563), -INT64_C( 4870192918742290955), -INT64_C( 4582163532444246554) } },
    { { -INT64_C( 3222467297329907041),  INT64_C( 8679530522840047917), -INT64_C( 8038892399899876680),  INT64_C( 7122503023806390329) },
      UINT8_C(176),
      {  INT64_C( 5609959750918825006), -INT64_C( 1208428646141584994),  INT64_C( 1046088480752631341),  INT64_C(   70708292662458644) },
      { -INT64_C( 1184015344395764584), -INT64_C( 2513664243821058911), -INT64_C( 8708083219147784151), -INT64_C( 4290016004168025947) },
      { -INT64_C( 3222467297329907041),  INT64_C( 8679530522840047917), -INT64_C( 8038892399899876680),  INT64_C( 7122503023806390329) } },
    { {  INT64_C( 5605461653887394953),  INT64_C( 1156467323012070270), -INT64_C( 8821619421393439592), -INT64_C( 4884309709840227001) },
      UINT8_C(150),
      { -INT64_C( 7181113434694314432), -INT64_C( 4162289697579366901),  INT64_C( 4706872780348868796),  INT64_C( 4336456253140354342) },
      {  INT64_C(  847359527305507014), -INT64_C( 7688793718833396237),  INT64_C( 4850361526019748146), -INT64_C( 5120580738804366665) },
      {  INT64_C( 5605461653887394953),  INT64_C(  847359527305507014),  INT64_C( 4706872780348868796), -INT64_C( 4884309709840227001) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256i src = simde_x_mm256_loadu_epi64(test_vec[i].src);
    simde__mmask8 k = test_vec[i].k;
    simde__m256i a = simde_x_mm256_loadu_epi64(test_vec[i].a);
    simde__m256i b = simde_x_mm256_loadu_epi64(test_vec[i].b);
    simde__m256i r = simde_mm256_mask_unpacklo_epi64(src, k, a, b);
    simde_test_x86_assert_equal_i64x4(r, simde_x_mm256_loadu_epi64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m256i src = simde_test_x86_random_i64x4();
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m256i a = simde_test_x86_random_i64x4();
    simde__m256i b = simde_test_x86_random_i64x4();
    simde__m256i r = simde_mm256_mask_unpacklo_epi64(src, k, a, b);

    simde_test_x86_write_i64x4(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x4(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_maskz_unpacklo_epi64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k;
    const int64_t a[4];
    const int64_t b[4];
    const int64_t r[4];
  } test_vec[] = {
    { UINT8_C( 40),
      { -INT64_C( 2929564760872836804), -INT64_C( 3581338366491876349), -INT64_C( 4526248881376556495), -INT64_C( 6409847766137472861) },
      { -INT64_C( 3099293686278604602),  INT64_C( 8990623343704065084),  INT64_C( 8865134480933343142),  INT64_C( 9210540427648570304) },
      {  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C( 8865134480933343142) } },
    { UINT8_C( 33),
      {  INT64_C( 7415113713443841426), -INT64_C( 1055761361307312746), -INT64_C( 5021438098055520441), -INT64_C( 2364968916092814430) },
      {  INT64_C( 8907962717777239958), -INT64_C( 4115577026391420594), -INT64_C( 7959929891999864025), -INT64_C( 8985585139222512864) },
      {  INT64_C( 7415113713443841426),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0) } },
    { UINT8_C(232),
      { -INT64_C( 6011098946254029610),  INT64_C( 1308279645739386231),  INT64_C( 8722789127109604679), -INT64_C( 7070395469408142802) },
      {  INT64_C( 7974882042433482404),  INT64_C( 1186300244064655613),  INT64_C( 3999488978003523466),  INT64_C( 8424001585502218116) },
      {  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C( 3999488978003523466) } },
    { UINT8_C(190),
      { -INT64_C(  558126257318562612), -INT64_C( 7876283259238046319),  INT64_C( 2476647999596116431),  INT64_C( 6832072312778500354) },
      {  INT64_C( 4247707713462765017),  INT64_C( 6211890535286748296), -INT64_C( 6617882825881235253),  INT64_C( 6352193682832496951) },
      {  INT64_C(                   0),  INT64_C( 4247707713462765017),  INT64_C( 2476647999596116431), -INT64_C( 6617882825881235253) } },
    { UINT8_C( 11),
      { -INT64_C(  489504476458888503), -INT64_C( 2581733513208211634),  INT64_C( 8272025483239960839), -INT64_C( 8688487403868809510) },
      {  INT64_C( 6691056084506058908),  INT64_C( 4118796062452112191), -INT64_C( 6492893464671377640), -INT64_C( 4866859440352668367) },
      { -INT64_C(  489504476458888503),  INT64_C( 6691056084506058908),  INT64_C(                   0), -INT64_C( 6492893464671377640) } },
    { UINT8_C(145),
      { -INT64_C( 3147738546910028375),  INT64_C( 7834082769348500664), -INT64_C( 2028066726650369522), -INT64_C( 1736771806879823390) },
      {  INT64_C( 4154932948920468572), -INT64_C(  137480805061906459),  INT64_C(  985587018042396347), -INT64_C( 3787169466293374901) },
      { -INT64_C( 3147738546910028375),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0) } },
    { UINT8_C(202),
      { -INT64_C(  461474609258389399), -INT64_C( 6293245730338880932), -INT64_C( 3432903862614002802), -INT64_C( 4661214251887631296) },
      {  INT64_C( 8857746070662388395),  INT64_C( 5353956133451650636),  INT64_C( 4716875199119237253),  INT64_C( 7615050128764155034) },
      {  INT64_C(                   0),  INT64_C( 8857746070662388395),  INT64_C(                   0),  INT64_C( 4716875199119237253) } },
    { UINT8_C(177),
      {  INT64_C( 2410914862211227168), -INT64_C( 8554261586768946254),  INT64_C( 1716656935480716931), -INT64_C( 8045048031242435951) },
      {  INT64_C( 2741055498097404317), -INT64_C( 7765274406855972790),  INT64_C( 2422267617680868642),  INT64_C( 5792232425489331041) },
      {  INT64_C( 2410914862211227168),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__mmask8 k = test_vec[i].k;
    simde__m256i a = simde_x_mm256_loadu_epi64(test_vec[i].a);
    simde__m256i b = simde_x_mm256_loadu_epi64(test_vec[i].b);
    simde__m256i r = simde_mm256_maskz_unpacklo_epi64(k, a, b);
    simde_test_x86_assert_equal_i64x4(r, simde_x_mm256_loadu_epi64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m256i a = simde_test_x86_random_i64x4();
    simde__m256i b = simde_test_x86_random_i64x4();
    simde__m256i r = simde_mm256_maskz_unpacklo_epi64(k, a, b);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i64x4(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_mask_unpacklo_epi64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int64_t src[2];
    const simde__mmask8 k;
    const int64_t a[2];
    const int64_t b[2];
    const int64_t r[2];
  } test_vec[] = {
    { {  INT64_C( 7630625246850963604),  INT64_C(  879855107171579827) },
      UINT8_C(188),
      { -INT64_C(  183838987819045596),  INT64_C( 6364983206234078235) },
      {  INT64_C( 7261488069337090212),  INT64_C(  819373552564416963) },
      {  INT64_C( 7630625246850963604),  INT64_C(  879855107171579827) } },
    { { -INT64_C( 8785219491770430547), -INT64_C( 7550677353043133091) },
      UINT8_C(162),
      {  INT64_C( 2272616243600075210),  INT64_C( 1626945753178320103) },
      { -INT64_C( 4882174950326031551),  INT64_C( 2200368322937101645) },
      { -INT64_C( 8785219491770430547), -INT64_C( 4882174950326031551) } },
    { { -INT64_C(  757046679351059984), -INT64_C( 2937912016739990374) },
      UINT8_C( 27),
      {  INT64_C( 1589656292456905147), -INT64_C( 7386034778120980921) },
      { -INT64_C( 2272737414790783379), -INT64_C( 8141014075028563591) },
      {  INT64_C( 1589656292456905147), -INT64_C( 2272737414790783379) } },
    { { -INT64_C( 4677162519954792440),  INT64_C( 8606886908855747160) },
      UINT8_C(172),
      {  INT64_C( 7003071890034545177), -INT64_C(   20613507930842785) },
      {  INT64_C( 5823215678113953558),  INT64_C( 3674886827172145285) },
      { -INT64_C( 4677162519954792440),  INT64_C( 8606886908855747160) } },
    { {  INT64_C( 5714250925248874277),  INT64_C( 6724071362546991665) },
      UINT8_C(106),
      {  INT64_C( 5585740783874069959), -INT64_C( 2387864550639151132) },
      { -INT64_C( 7436817277236885374),  INT64_C( 3691048907160099867) },
      {  INT64_C( 5714250925248874277), -INT64_C( 7436817277236885374) } },
    { { -INT64_C( 2304234437791813102), -INT64_C( 8627925989817095027) },
      UINT8_C( 60),
      {  INT64_C(  669887274016711185), -INT64_C( 4172117405709559094) },
      {  INT64_C( 4836482096589623771), -INT64_C( 2888547034740456646) },
      { -INT64_C( 2304234437791813102), -INT64_C( 8627925989817095027) } },
    { { -INT64_C( 1086966033118970893), -INT64_C( 1980158827098054548) },
      UINT8_C(226),
      {  INT64_C( 1595677880224412999), -INT64_C(  717280999983230650) },
      {  INT64_C( 3925182663712631995),  INT64_C(  429570113750906883) },
      { -INT64_C( 1086966033118970893),  INT64_C( 3925182663712631995) } },
    { { -INT64_C( 1062264936191774824), -INT64_C( 8172321574661578779) },
      UINT8_C(  0),
      {  INT64_C( 5531279150110120883),  INT64_C( 8937411935050848076) },
      { -INT64_C( 7568271174582979329), -INT64_C( 2218313988579944414) },
      { -INT64_C( 1062264936191774824), -INT64_C( 8172321574661578779) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i src = simde_x_mm_loadu_epi64(test_vec[i].src);
    simde__m128i a = simde_x_mm_loadu_epi64(test_vec[i].a);
    simde__m128i b = simde_x_mm_loadu_epi64(test_vec[i].b);
    simde__m128i r = simde_mm_mask_unpacklo_epi64(src, test_vec[i].k, a, b);
    simde_test_x86_assert_equal_i64x2(r, simde_x_mm_loadu_epi64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i src = simde_test_x86_random_i64x2();
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m128i a = simde_test_x86_random_i64x2();
    simde__m128i b = simde_test_x86_random_i64x2();
    simde__m128i r = simde_mm_mask_unpacklo_epi64(src, k, a, b);

    simde_test_x86_write_i64x2(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x2(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_maskz_unpacklo_epi64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k;
    const int64_t a[2];
    const int64_t b[2];
    const int64_t r[2];
  } test_vec[] = {
    { UINT8_C(196),
      {  INT64_C( 3359871471059061983),  INT64_C(  581932871609493621) },
      {  INT64_C( 7767966097551690145), -INT64_C( 3694629630959767388) },
      {  INT64_C(                   0),  INT64_C(                   0) } },
    { UINT8_C(214),
      { -INT64_C( 4014306370929819860), -INT64_C(  662964360751785542) },
      { -INT64_C( 6231182014297855099),  INT64_C( 7153230473871064422) },
      {  INT64_C(                   0), -INT64_C( 6231182014297855099) } },
    { UINT8_C( 96),
      { -INT64_C( 2561201824275089303), -INT64_C( 7592999242511573139) },
      { -INT64_C( 8862460606585863624),  INT64_C( 2346129902018589389) },
      {  INT64_C(                   0),  INT64_C(                   0) } },
    { UINT8_C( 89),
      { -INT64_C( 1241666045843088497),  INT64_C(   34040322729827840) },
      { -INT64_C( 8538105711068375682), -INT64_C( 3475264608124423861) },
      { -INT64_C( 1241666045843088497),  INT64_C(                   0) } },
    { UINT8_C( 60),
      { -INT64_C( 4010320321246910816),  INT64_C( 2756562588543719636) },
      {  INT64_C( 3038460224865171280), -INT64_C(  241442465244342776) },
      {  INT64_C(                   0),  INT64_C(                   0) } },
    { UINT8_C( 95),
      {  INT64_C( 5008023318470153266),  INT64_C( 9003114043452834905) },
      { -INT64_C( 7960076081099779911), -INT64_C( 3880721236049988981) },
      {  INT64_C( 5008023318470153266), -INT64_C( 7960076081099779911) } },
    { UINT8_C( 60),
      {  INT64_C( 4312248283745056365),  INT64_C( 4231480850379733380) },
      { -INT64_C( 5413672263642498509),  INT64_C( 3807537056508060594) },
      {  INT64_C(                   0),  INT64_C(                   0) } },
    { UINT8_C(141),
      {  INT64_C(  392586729552655552),  INT64_C( 7345275522574676607) },
      { -INT64_C( 4299288232225913890), -INT64_C( 8661336021343145943) },
      {  INT64_C(  392586729552655552),  INT64_C(                   0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_x_mm_loadu_epi64(test_vec[i].a);
    simde__m128i b = simde_x_mm_loadu_epi64(test_vec[i].b);
    simde__m128i r = simde_mm_maskz_unpacklo_epi64(test_vec[i].k, a, b);
    simde_test_x86_assert_equal_i64x2(r, simde_x_mm_loadu_epi64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m128i a = simde_test_x86_random_i64x2();
    simde__m128i b = simde_test_x86_random_i64x2();
    simde__m128i r = simde_mm_maskz_unpacklo_epi64(k, a, b);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i64x2(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
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
test_simde_mm512_mask_unpacklo_ps (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde_float32 src[16];
    const simde__mmask8 k;
    const simde_float32 a[16];
    const simde_float32 b[16];
    const simde_float32 r[16];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(  -184.68), SIMDE_FLOAT32_C(   672.46), SIMDE_FLOAT32_C(    34.79), SIMDE_FLOAT32_C(    13.38),
        SIMDE_FLOAT32_C(   362.18), SIMDE_FLOAT32_C(   311.20), SIMDE_FLOAT32_C(   109.82), SIMDE_FLOAT32_C(   193.47),
        SIMDE_FLOAT32_C(  -290.40), SIMDE_FLOAT32_C(   750.43), SIMDE_FLOAT32_C(  -691.59), SIMDE_FLOAT32_C(   148.09),
        SIMDE_FLOAT32_C(  -621.83), SIMDE_FLOAT32_C(  -297.97), SIMDE_FLOAT32_C(     2.37), SIMDE_FLOAT32_C(   541.99) },
      UINT8_C( 13),
      { SIMDE_FLOAT32_C(  -799.86), SIMDE_FLOAT32_C(   958.72), SIMDE_FLOAT32_C(   891.56), SIMDE_FLOAT32_C(  -764.72),
        SIMDE_FLOAT32_C(   184.63), SIMDE_FLOAT32_C(  -801.34), SIMDE_FLOAT32_C(  -996.88), SIMDE_FLOAT32_C(    50.74),
        SIMDE_FLOAT32_C(  -401.68), SIMDE_FLOAT32_C(   774.70), SIMDE_FLOAT32_C(  -758.39), SIMDE_FLOAT32_C(  -326.35),
        SIMDE_FLOAT32_C(  -297.06), SIMDE_FLOAT32_C(   153.97), SIMDE_FLOAT32_C(   488.97), SIMDE_FLOAT32_C(  -624.60) },
      { SIMDE_FLOAT32_C(  -811.24), SIMDE_FLOAT32_C(  -497.65), SIMDE_FLOAT32_C(   737.58), SIMDE_FLOAT32_C(   499.96),
        SIMDE_FLOAT32_C(   612.17), SIMDE_FLOAT32_C(   -68.95), SIMDE_FLOAT32_C(  -790.45), SIMDE_FLOAT32_C(   362.60),
        SIMDE_FLOAT32_C(   239.45), SIMDE_FLOAT32_C(   357.64), SIMDE_FLOAT32_C(   740.77), SIMDE_FLOAT32_C(   941.48),
        SIMDE_FLOAT32_C(  -639.99), SIMDE_FLOAT32_C(   282.76), SIMDE_FLOAT32_C(  -688.06), SIMDE_FLOAT32_C(  -439.85) },
      { SIMDE_FLOAT32_C(  -799.86), SIMDE_FLOAT32_C(   672.46), SIMDE_FLOAT32_C(   958.72), SIMDE_FLOAT32_C(  -497.65),
        SIMDE_FLOAT32_C(   362.18), SIMDE_FLOAT32_C(   311.20), SIMDE_FLOAT32_C(   109.82), SIMDE_FLOAT32_C(   193.47),
        SIMDE_FLOAT32_C(  -290.40), SIMDE_FLOAT32_C(   750.43), SIMDE_FLOAT32_C(  -691.59), SIMDE_FLOAT32_C(   148.09),
        SIMDE_FLOAT32_C(  -621.83), SIMDE_FLOAT32_C(  -297.97), SIMDE_FLOAT32_C(     2.37), SIMDE_FLOAT32_C(   541.99) } },
    { { SIMDE_FLOAT32_C(   241.49), SIMDE_FLOAT32_C(  -796.50), SIMDE_FLOAT32_C(  -204.57), SIMDE_FLOAT32_C(  -573.89),
        SIMDE_FLOAT32_C(  -597.84), SIMDE_FLOAT32_C(  -201.46), SIMDE_FLOAT32_C(   476.86), SIMDE_FLOAT32_C(     0.48),
        SIMDE_FLOAT32_C(  -426.75), SIMDE_FLOAT32_C(   718.47), SIMDE_FLOAT32_C(   674.13), SIMDE_FLOAT32_C(   276.19),
        SIMDE_FLOAT32_C(  -127.56), SIMDE_FLOAT32_C(   163.10), SIMDE_FLOAT32_C(   651.59), SIMDE_FLOAT32_C(    61.20) },
      UINT8_C(184),
      { SIMDE_FLOAT32_C(   389.18), SIMDE_FLOAT32_C(  -438.85), SIMDE_FLOAT32_C(   277.61), SIMDE_FLOAT32_C(  -679.78),
        SIMDE_FLOAT32_C(  -229.29), SIMDE_FLOAT32_C(  -359.79), SIMDE_FLOAT32_C(   559.67), SIMDE_FLOAT32_C(  -871.65),
        SIMDE_FLOAT32_C(  -619.01), SIMDE_FLOAT32_C(   501.15), SIMDE_FLOAT32_C(  -511.64), SIMDE_FLOAT32_C(   663.75),
        SIMDE_FLOAT32_C(   813.10), SIMDE_FLOAT32_C(    48.50), SIMDE_FLOAT32_C(   -94.76), SIMDE_FLOAT32_C(  -983.40) },
      { SIMDE_FLOAT32_C(   843.93), SIMDE_FLOAT32_C(   331.35), SIMDE_FLOAT32_C(  -581.24), SIMDE_FLOAT32_C(  -357.52),
        SIMDE_FLOAT32_C(  -191.79), SIMDE_FLOAT32_C(   419.24), SIMDE_FLOAT32_C(   215.72), SIMDE_FLOAT32_C(  -473.33),
        SIMDE_FLOAT32_C(    93.37), SIMDE_FLOAT32_C(  -508.09), SIMDE_FLOAT32_C(   399.11), SIMDE_FLOAT32_C(  -743.53),
        SIMDE_FLOAT32_C(  -856.49), SIMDE_FLOAT32_C(  -539.69), SIMDE_FLOAT32_C(   921.92), SIMDE_FLOAT32_C(   532.68) },
      { SIMDE_FLOAT32_C(   241.49), SIMDE_FLOAT32_C(  -796.50), SIMDE_FLOAT32_C(  -204.57), SIMDE_FLOAT32_C(   331.35),
        SIMDE_FLOAT32_C(  -229.29), SIMDE_FLOAT32_C(  -191.79), SIMDE_FLOAT32_C(   476.86), SIMDE_FLOAT32_C(   419.24),
        SIMDE_FLOAT32_C(  -426.75), SIMDE_FLOAT32_C(   718.47), SIMDE_FLOAT32_C(   674.13), SIMDE_FLOAT32_C(   276.19),
        SIMDE_FLOAT32_C(  -127.56), SIMDE_FLOAT32_C(   163.10), SIMDE_FLOAT32_C(   651.59), SIMDE_FLOAT32_C(    61.20) } },
    { { SIMDE_FLOAT32_C(    21.46), SIMDE_FLOAT32_C(   199.53), SIMDE_FLOAT32_C(   852.90), SIMDE_FLOAT32_C(   792.17),
        SIMDE_FLOAT32_C(   839.75), SIMDE_FLOAT32_C(   412.58), SIMDE_FLOAT32_C(   920.52), SIMDE_FLOAT32_C(  -779.27),
        SIMDE_FLOAT32_C(   -86.27), SIMDE_FLOAT32_C(  -591.13), SIMDE_FLOAT32_C(   884.48), SIMDE_FLOAT32_C(  -273.17),
        SIMDE_FLOAT32_C(   457.38), SIMDE_FLOAT32_C(  -210.28), SIMDE_FLOAT32_C(  -256.57), SIMDE_FLOAT32_C(   301.31) },
      UINT8_C( 37),
      { SIMDE_FLOAT32_C(   162.19), SIMDE_FLOAT32_C(   943.78), SIMDE_FLOAT32_C(   -70.73), SIMDE_FLOAT32_C(  -418.58),
        SIMDE_FLOAT32_C(   159.50), SIMDE_FLOAT32_C(   455.95), SIMDE_FLOAT32_C(   674.79), SIMDE_FLOAT32_C(   651.42),
        SIMDE_FLOAT32_C(  -144.94), SIMDE_FLOAT32_C(   931.26), SIMDE_FLOAT32_C(   794.92), SIMDE_FLOAT32_C(   315.37),
        SIMDE_FLOAT32_C(   853.18), SIMDE_FLOAT32_C(   327.61), SIMDE_FLOAT32_C(  -663.16), SIMDE_FLOAT32_C(    52.71) },
      { SIMDE_FLOAT32_C(   180.51), SIMDE_FLOAT32_C(  -871.00), SIMDE_FLOAT32_C(  -107.54), SIMDE_FLOAT32_C(  -406.91),
        SIMDE_FLOAT32_C(  -950.48), SIMDE_FLOAT32_C(   113.19), SIMDE_FLOAT32_C(   506.82), SIMDE_FLOAT32_C(  -541.60),
        SIMDE_FLOAT32_C(    -2.33), SIMDE_FLOAT32_C(  -766.35), SIMDE_FLOAT32_C(   915.77), SIMDE_FLOAT32_C(   787.39),
        SIMDE_FLOAT32_C(   -22.92), SIMDE_FLOAT32_C(   217.08), SIMDE_FLOAT32_C(   908.46), SIMDE_FLOAT32_C(  -860.73) },
      { SIMDE_FLOAT32_C(   162.19), SIMDE_FLOAT32_C(   199.53), SIMDE_FLOAT32_C(   943.78), SIMDE_FLOAT32_C(   792.17),
        SIMDE_FLOAT32_C(   839.75), SIMDE_FLOAT32_C(  -950.48), SIMDE_FLOAT32_C(   920.52), SIMDE_FLOAT32_C(  -779.27),
        SIMDE_FLOAT32_C(   -86.27), SIMDE_FLOAT32_C(  -591.13), SIMDE_FLOAT32_C(   884.48), SIMDE_FLOAT32_C(  -273.17),
        SIMDE_FLOAT32_C(   457.38), SIMDE_FLOAT32_C(  -210.28), SIMDE_FLOAT32_C(  -256.57), SIMDE_FLOAT32_C(   301.31) } },
    { { SIMDE_FLOAT32_C(   160.86), SIMDE_FLOAT32_C(  -162.27), SIMDE_FLOAT32_C(  -279.31), SIMDE_FLOAT32_C(  -679.63),
        SIMDE_FLOAT32_C(  -706.32), SIMDE_FLOAT32_C(  -604.52), SIMDE_FLOAT32_C(   971.78), SIMDE_FLOAT32_C(   148.74),
        SIMDE_FLOAT32_C(  -673.26), SIMDE_FLOAT32_C(   766.71), SIMDE_FLOAT32_C(  -535.89), SIMDE_FLOAT32_C(  -820.08),
        SIMDE_FLOAT32_C(    94.31), SIMDE_FLOAT32_C(  -199.05), SIMDE_FLOAT32_C(   232.64), SIMDE_FLOAT32_C(  -725.18) },
      UINT8_C( 36),
      { SIMDE_FLOAT32_C(  -874.90), SIMDE_FLOAT32_C(  -132.09), SIMDE_FLOAT32_C(   -20.52), SIMDE_FLOAT32_C(   238.29),
        SIMDE_FLOAT32_C(  -625.26), SIMDE_FLOAT32_C(   437.87), SIMDE_FLOAT32_C(  -764.04), SIMDE_FLOAT32_C(  -391.61),
        SIMDE_FLOAT32_C(   353.64), SIMDE_FLOAT32_C(  -976.65), SIMDE_FLOAT32_C(   585.47), SIMDE_FLOAT32_C(  -429.27),
        SIMDE_FLOAT32_C(   931.81), SIMDE_FLOAT32_C(   724.74), SIMDE_FLOAT32_C(   731.59), SIMDE_FLOAT32_C(  -230.46) },
      { SIMDE_FLOAT32_C(  -554.57), SIMDE_FLOAT32_C(  -948.04), SIMDE_FLOAT32_C(    63.22), SIMDE_FLOAT32_C(  -159.09),
        SIMDE_FLOAT32_C(  -976.26), SIMDE_FLOAT32_C(  -788.04), SIMDE_FLOAT32_C(   167.66), SIMDE_FLOAT32_C(   790.45),
        SIMDE_FLOAT32_C(  -323.92), SIMDE_FLOAT32_C(   347.58), SIMDE_FLOAT32_C(  -115.24), SIMDE_FLOAT32_C(   477.02),
        SIMDE_FLOAT32_C(  -419.78), SIMDE_FLOAT32_C(   159.59), SIMDE_FLOAT32_C(  -593.02), SIMDE_FLOAT32_C(  -294.68) },
      { SIMDE_FLOAT32_C(   160.86), SIMDE_FLOAT32_C(  -162.27), SIMDE_FLOAT32_C(  -132.09), SIMDE_FLOAT32_C(  -679.63),
        SIMDE_FLOAT32_C(  -706.32), SIMDE_FLOAT32_C(  -976.26), SIMDE_FLOAT32_C(   971.78), SIMDE_FLOAT32_C(   148.74),
        SIMDE_FLOAT32_C(  -673.26), SIMDE_FLOAT32_C(   766.71), SIMDE_FLOAT32_C(  -535.89), SIMDE_FLOAT32_C(  -820.08),
        SIMDE_FLOAT32_C(    94.31), SIMDE_FLOAT32_C(  -199.05), SIMDE_FLOAT32_C(   232.64), SIMDE_FLOAT32_C(  -725.18) } },
    { { SIMDE_FLOAT32_C(  -972.50), SIMDE_FLOAT32_C(   386.45), SIMDE_FLOAT32_C(   943.60), SIMDE_FLOAT32_C(  -597.76),
        SIMDE_FLOAT32_C(  -175.67), SIMDE_FLOAT32_C(  -820.43), SIMDE_FLOAT32_C(    10.63), SIMDE_FLOAT32_C(  -822.03),
        SIMDE_FLOAT32_C(  -797.08), SIMDE_FLOAT32_C(  -403.90), SIMDE_FLOAT32_C(  -251.30), SIMDE_FLOAT32_C(  -865.27),
        SIMDE_FLOAT32_C(  -679.16), SIMDE_FLOAT32_C(  -519.72), SIMDE_FLOAT32_C(   -95.73), SIMDE_FLOAT32_C(  -233.73) },
      UINT8_C( 40),
      { SIMDE_FLOAT32_C(   967.49), SIMDE_FLOAT32_C(   607.18), SIMDE_FLOAT32_C(  -444.02), SIMDE_FLOAT32_C(  -820.55),
        SIMDE_FLOAT32_C(  -225.17), SIMDE_FLOAT32_C(  -653.57), SIMDE_FLOAT32_C(  -144.47), SIMDE_FLOAT32_C(  -877.59),
        SIMDE_FLOAT32_C(   231.19), SIMDE_FLOAT32_C(  -667.45), SIMDE_FLOAT32_C(  -297.37), SIMDE_FLOAT32_C(  -609.22),
        SIMDE_FLOAT32_C(  -260.47), SIMDE_FLOAT32_C(   407.95), SIMDE_FLOAT32_C(  -581.72), SIMDE_FLOAT32_C(  -874.02) },
      { SIMDE_FLOAT32_C(   351.55), SIMDE_FLOAT32_C(  -179.48), SIMDE_FLOAT32_C(   -49.69), SIMDE_FLOAT32_C(   531.12),
        SIMDE_FLOAT32_C(   831.15), SIMDE_FLOAT32_C(   128.28), SIMDE_FLOAT32_C(   734.04), SIMDE_FLOAT32_C(  -572.75),
        SIMDE_FLOAT32_C(   876.97), SIMDE_FLOAT32_C(   868.77), SIMDE_FLOAT32_C(  -251.91), SIMDE_FLOAT32_C(  -642.74),
        SIMDE_FLOAT32_C(  -226.97), SIMDE_FLOAT32_C(   514.36), SIMDE_FLOAT32_C(  -110.50), SIMDE_FLOAT32_C(  -259.48) },
      { SIMDE_FLOAT32_C(  -972.50), SIMDE_FLOAT32_C(   386.45), SIMDE_FLOAT32_C(   943.60), SIMDE_FLOAT32_C(  -179.48),
        SIMDE_FLOAT32_C(  -175.67), SIMDE_FLOAT32_C(   831.15), SIMDE_FLOAT32_C(    10.63), SIMDE_FLOAT32_C(  -822.03),
        SIMDE_FLOAT32_C(  -797.08), SIMDE_FLOAT32_C(  -403.90), SIMDE_FLOAT32_C(  -251.30), SIMDE_FLOAT32_C(  -865.27),
        SIMDE_FLOAT32_C(  -679.16), SIMDE_FLOAT32_C(  -519.72), SIMDE_FLOAT32_C(   -95.73), SIMDE_FLOAT32_C(  -233.73) } },
    { { SIMDE_FLOAT32_C(   121.54), SIMDE_FLOAT32_C(   445.48), SIMDE_FLOAT32_C(   -80.02), SIMDE_FLOAT32_C(   896.37),
        SIMDE_FLOAT32_C(   791.91), SIMDE_FLOAT32_C(   775.51), SIMDE_FLOAT32_C(  -981.22), SIMDE_FLOAT32_C(    23.11),
        SIMDE_FLOAT32_C(  -891.94), SIMDE_FLOAT32_C(  -278.58), SIMDE_FLOAT32_C(   413.89), SIMDE_FLOAT32_C(  -152.41),
        SIMDE_FLOAT32_C(  -870.63), SIMDE_FLOAT32_C(   832.17), SIMDE_FLOAT32_C(   -26.42), SIMDE_FLOAT32_C(   480.92) },
      UINT8_C( 95),
      { SIMDE_FLOAT32_C(   923.89), SIMDE_FLOAT32_C(    12.04), SIMDE_FLOAT32_C(  -516.16), SIMDE_FLOAT32_C(    52.17),
        SIMDE_FLOAT32_C(  -253.92), SIMDE_FLOAT32_C(   -88.91), SIMDE_FLOAT32_C(   -70.86), SIMDE_FLOAT32_C(  -385.15),
        SIMDE_FLOAT32_C(   659.18), SIMDE_FLOAT32_C(   286.40), SIMDE_FLOAT32_C(   387.88), SIMDE_FLOAT32_C(   173.53),
        SIMDE_FLOAT32_C(  -824.10), SIMDE_FLOAT32_C(  -871.59), SIMDE_FLOAT32_C(  -704.93), SIMDE_FLOAT32_C(   621.38) },
      { SIMDE_FLOAT32_C(    48.38), SIMDE_FLOAT32_C(  -808.56), SIMDE_FLOAT32_C(   413.30), SIMDE_FLOAT32_C(  -176.11),
        SIMDE_FLOAT32_C(  -789.78), SIMDE_FLOAT32_C(  -563.60), SIMDE_FLOAT32_C(   -68.05), SIMDE_FLOAT32_C(   -68.36),
        SIMDE_FLOAT32_C(   850.29), SIMDE_FLOAT32_C(   779.54), SIMDE_FLOAT32_C(    61.01), SIMDE_FLOAT32_C(   682.46),
        SIMDE_FLOAT32_C(  -246.88), SIMDE_FLOAT32_C(  -458.07), SIMDE_FLOAT32_C(  -664.85), SIMDE_FLOAT32_C(  -323.00) },
      { SIMDE_FLOAT32_C(   923.89), SIMDE_FLOAT32_C(    48.38), SIMDE_FLOAT32_C(    12.04), SIMDE_FLOAT32_C(  -808.56),
        SIMDE_FLOAT32_C(  -253.92), SIMDE_FLOAT32_C(   775.51), SIMDE_FLOAT32_C(   -88.91), SIMDE_FLOAT32_C(    23.11),
        SIMDE_FLOAT32_C(  -891.94), SIMDE_FLOAT32_C(  -278.58), SIMDE_FLOAT32_C(   413.89), SIMDE_FLOAT32_C(  -152.41),
        SIMDE_FLOAT32_C(  -870.63), SIMDE_FLOAT32_C(   832.17), SIMDE_FLOAT32_C(   -26.42), SIMDE_FLOAT32_C(   480.92) } },
    { { SIMDE_FLOAT32_C(   553.98), SIMDE_FLOAT32_C(  -181.01), SIMDE_FLOAT32_C(   729.17), SIMDE_FLOAT32_C(  -699.94),
        SIMDE_FLOAT32_C(   730.08), SIMDE_FLOAT32_C(  -341.69), SIMDE_FLOAT32_C(   -85.09), SIMDE_FLOAT32_C(   389.26),
        SIMDE_FLOAT32_C(   944.71), SIMDE_FLOAT32_C(  -697.21), SIMDE_FLOAT32_C(  -437.21), SIMDE_FLOAT32_C(  -879.39),
        SIMDE_FLOAT32_C(  -568.80), SIMDE_FLOAT32_C(  -142.14), SIMDE_FLOAT32_C(   741.99), SIMDE_FLOAT32_C(   479.58) },
      UINT8_C(108),
      { SIMDE_FLOAT32_C(   155.29), SIMDE_FLOAT32_C(  -696.53), SIMDE_FLOAT32_C(   259.52), SIMDE_FLOAT32_C(   591.69),
        SIMDE_FLOAT32_C(   235.42), SIMDE_FLOAT32_C(  -808.83), SIMDE_FLOAT32_C(   441.98), SIMDE_FLOAT32_C(    14.97),
        SIMDE_FLOAT32_C(   252.18), SIMDE_FLOAT32_C(   124.44), SIMDE_FLOAT32_C(   768.09), SIMDE_FLOAT32_C(   794.11),
        SIMDE_FLOAT32_C(   459.60), SIMDE_FLOAT32_C(  -554.91), SIMDE_FLOAT32_C(   348.09), SIMDE_FLOAT32_C(  -721.41) },
      { SIMDE_FLOAT32_C(  -825.74), SIMDE_FLOAT32_C(   648.15), SIMDE_FLOAT32_C(  -991.33), SIMDE_FLOAT32_C(  -167.43),
        SIMDE_FLOAT32_C(  -436.95), SIMDE_FLOAT32_C(   397.92), SIMDE_FLOAT32_C(  -222.72), SIMDE_FLOAT32_C(  -134.16),
        SIMDE_FLOAT32_C(   960.72), SIMDE_FLOAT32_C(  -102.11), SIMDE_FLOAT32_C(   297.04), SIMDE_FLOAT32_C(  -181.42),
        SIMDE_FLOAT32_C(  -360.12), SIMDE_FLOAT32_C(  -223.38), SIMDE_FLOAT32_C(   867.88), SIMDE_FLOAT32_C(   795.17) },
      { SIMDE_FLOAT32_C(   553.98), SIMDE_FLOAT32_C(  -181.01), SIMDE_FLOAT32_C(  -696.53), SIMDE_FLOAT32_C(   648.15),
        SIMDE_FLOAT32_C(   730.08), SIMDE_FLOAT32_C(  -436.95), SIMDE_FLOAT32_C(  -808.83), SIMDE_FLOAT32_C(   389.26),
        SIMDE_FLOAT32_C(   944.71), SIMDE_FLOAT32_C(  -697.21), SIMDE_FLOAT32_C(  -437.21), SIMDE_FLOAT32_C(  -879.39),
        SIMDE_FLOAT32_C(  -568.80), SIMDE_FLOAT32_C(  -142.14), SIMDE_FLOAT32_C(   741.99), SIMDE_FLOAT32_C(   479.58) } },
    { { SIMDE_FLOAT32_C(    80.09), SIMDE_FLOAT32_C(   127.40), SIMDE_FLOAT32_C(   386.86), SIMDE_FLOAT32_C(  -684.48),
        SIMDE_FLOAT32_C(   318.57), SIMDE_FLOAT32_C(  -171.16), SIMDE_FLOAT32_C(   330.48), SIMDE_FLOAT32_C(  -429.25),
        SIMDE_FLOAT32_C(   953.28), SIMDE_FLOAT32_C(    98.57), SIMDE_FLOAT32_C(  -635.14), SIMDE_FLOAT32_C(   412.88),
        SIMDE_FLOAT32_C(   543.66), SIMDE_FLOAT32_C(   712.95), SIMDE_FLOAT32_C(   691.47), SIMDE_FLOAT32_C(   717.93) },
      UINT8_C( 60),
      { SIMDE_FLOAT32_C(   700.14), SIMDE_FLOAT32_C(  -449.50), SIMDE_FLOAT32_C(   924.15), SIMDE_FLOAT32_C(    98.06),
        SIMDE_FLOAT32_C(   327.78), SIMDE_FLOAT32_C(  -210.01), SIMDE_FLOAT32_C(    58.78), SIMDE_FLOAT32_C(  -774.33),
        SIMDE_FLOAT32_C(  -912.97), SIMDE_FLOAT32_C(   877.35), SIMDE_FLOAT32_C(  -134.45), SIMDE_FLOAT32_C(  -136.36),
        SIMDE_FLOAT32_C(   745.23), SIMDE_FLOAT32_C(  -339.28), SIMDE_FLOAT32_C(   943.74), SIMDE_FLOAT32_C(  -127.37) },
      { SIMDE_FLOAT32_C(  -952.43), SIMDE_FLOAT32_C(  -740.75), SIMDE_FLOAT32_C(  -808.80), SIMDE_FLOAT32_C(  -123.59),
        SIMDE_FLOAT32_C(   589.74), SIMDE_FLOAT32_C(  -238.05), SIMDE_FLOAT32_C(  -170.31), SIMDE_FLOAT32_C(  -311.69),
        SIMDE_FLOAT32_C(   126.81), SIMDE_FLOAT32_C(  -757.43), SIMDE_FLOAT32_C(  -768.03), SIMDE_FLOAT32_C(  -160.24),
        SIMDE_FLOAT32_C(   934.04), SIMDE_FLOAT32_C(   949.90), SIMDE_FLOAT32_C(  -799.15), SIMDE_FLOAT32_C(   634.18) },
      { SIMDE_FLOAT32_C(    80.09), SIMDE_FLOAT32_C(   127.40), SIMDE_FLOAT32_C(  -449.50), SIMDE_FLOAT32_C(  -740.75),
        SIMDE_FLOAT32_C(   327.78), SIMDE_FLOAT32_C(   589.74), SIMDE_FLOAT32_C(   330.48), SIMDE_FLOAT32_C(  -429.25),
        SIMDE_FLOAT32_C(   953.28), SIMDE_FLOAT32_C(    98.57), SIMDE_FLOAT32_C(  -635.14), SIMDE_FLOAT32_C(   412.88),
        SIMDE_FLOAT32_C(   543.66), SIMDE_FLOAT32_C(   712.95), SIMDE_FLOAT32_C(   691.47), SIMDE_FLOAT32_C(   717.93) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512 src = simde_mm512_loadu_ps(test_vec[i].src);
    simde__m512 a = simde_mm512_loadu_ps(test_vec[i].a);
    simde__m512 b = simde_mm512_loadu_ps(test_vec[i].b);
    simde__m512 r = simde_mm512_mask_unpacklo_ps(src, test_vec[i].k, a, b);
    simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m512 src = simde_test_x86_random_f32x16(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m512 a = simde_test_x86_random_f32x16(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
    simde__m512 b = simde_test_x86_random_f32x16(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
    simde__m512 r = simde_mm512_mask_unpacklo_ps(src, k, a, b);

    simde_test_x86_write_f32x16(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x16(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_maskz_unpacklo_ps (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask16 k;
    const simde_float32 a[16];
    const simde_float32 b[16];
    const simde_float32 r[16];
  } test_vec[] = {
    { UINT16_C(53587),
      { SIMDE_FLOAT32_C(  -554.77), SIMDE_FLOAT32_C(  -632.67), SIMDE_FLOAT32_C(   -49.79), SIMDE_FLOAT32_C(   387.31),
        SIMDE_FLOAT32_C(   858.73), SIMDE_FLOAT32_C(    20.20), SIMDE_FLOAT32_C(   530.42), SIMDE_FLOAT32_C(  -376.65),
        SIMDE_FLOAT32_C(   -64.83), SIMDE_FLOAT32_C(  -339.56), SIMDE_FLOAT32_C(   226.67), SIMDE_FLOAT32_C(   438.66),
        SIMDE_FLOAT32_C(   352.87), SIMDE_FLOAT32_C(   627.81), SIMDE_FLOAT32_C(   464.16), SIMDE_FLOAT32_C(   -11.16) },
      { SIMDE_FLOAT32_C(   223.98), SIMDE_FLOAT32_C(  -621.83), SIMDE_FLOAT32_C(  -865.80), SIMDE_FLOAT32_C(   909.33),
        SIMDE_FLOAT32_C(  -771.84), SIMDE_FLOAT32_C(   400.64), SIMDE_FLOAT32_C(  -250.14), SIMDE_FLOAT32_C(   698.14),
        SIMDE_FLOAT32_C(   865.33), SIMDE_FLOAT32_C(   253.06), SIMDE_FLOAT32_C(   850.97), SIMDE_FLOAT32_C(  -569.68),
        SIMDE_FLOAT32_C(   274.87), SIMDE_FLOAT32_C(  -459.57), SIMDE_FLOAT32_C(  -771.91), SIMDE_FLOAT32_C(   720.10) },
      { SIMDE_FLOAT32_C(  -554.77), SIMDE_FLOAT32_C(   223.98), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(   858.73), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(    20.20), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(   -64.83), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(   352.87), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   627.81), SIMDE_FLOAT32_C(  -459.57) } },
    { UINT16_C(33366),
      { SIMDE_FLOAT32_C(   107.40), SIMDE_FLOAT32_C(  -233.50), SIMDE_FLOAT32_C(  -801.49), SIMDE_FLOAT32_C(  -362.17),
        SIMDE_FLOAT32_C(   389.85), SIMDE_FLOAT32_C(   133.68), SIMDE_FLOAT32_C(   298.26), SIMDE_FLOAT32_C(  -383.48),
        SIMDE_FLOAT32_C(  -427.65), SIMDE_FLOAT32_C(  -348.86), SIMDE_FLOAT32_C(  -755.67), SIMDE_FLOAT32_C(  -963.50),
        SIMDE_FLOAT32_C(   639.98), SIMDE_FLOAT32_C(   468.30), SIMDE_FLOAT32_C(  -585.33), SIMDE_FLOAT32_C(   774.18) },
      { SIMDE_FLOAT32_C(   377.63), SIMDE_FLOAT32_C(  -357.17), SIMDE_FLOAT32_C(   174.82), SIMDE_FLOAT32_C(  -872.51),
        SIMDE_FLOAT32_C(  -659.04), SIMDE_FLOAT32_C(    40.15), SIMDE_FLOAT32_C(   380.55), SIMDE_FLOAT32_C(  -808.07),
        SIMDE_FLOAT32_C(   470.47), SIMDE_FLOAT32_C(  -344.58), SIMDE_FLOAT32_C(  -267.64), SIMDE_FLOAT32_C(   698.56),
        SIMDE_FLOAT32_C(  -624.49), SIMDE_FLOAT32_C(   640.13), SIMDE_FLOAT32_C(  -123.13), SIMDE_FLOAT32_C(   482.92) },
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   377.63), SIMDE_FLOAT32_C(  -233.50), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(   389.85), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   133.68), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   470.47), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   640.13) } },
    { UINT16_C( 4464),
      { SIMDE_FLOAT32_C(  -879.26), SIMDE_FLOAT32_C(   796.47), SIMDE_FLOAT32_C(  -790.94), SIMDE_FLOAT32_C(   419.01),
        SIMDE_FLOAT32_C(  -587.01), SIMDE_FLOAT32_C(  -218.59), SIMDE_FLOAT32_C(  -929.86), SIMDE_FLOAT32_C(  -342.69),
        SIMDE_FLOAT32_C(  -182.09), SIMDE_FLOAT32_C(   710.12), SIMDE_FLOAT32_C(  -874.38), SIMDE_FLOAT32_C(   232.58),
        SIMDE_FLOAT32_C(   484.30), SIMDE_FLOAT32_C(   503.25), SIMDE_FLOAT32_C(   875.41), SIMDE_FLOAT32_C(  -340.88) },
      { SIMDE_FLOAT32_C(   630.74), SIMDE_FLOAT32_C(  -783.63), SIMDE_FLOAT32_C(   699.28), SIMDE_FLOAT32_C(    11.29),
        SIMDE_FLOAT32_C(  -591.70), SIMDE_FLOAT32_C(   169.75), SIMDE_FLOAT32_C(   666.71), SIMDE_FLOAT32_C(   140.66),
        SIMDE_FLOAT32_C(  -131.69), SIMDE_FLOAT32_C(  -957.78), SIMDE_FLOAT32_C(  -219.21), SIMDE_FLOAT32_C(   745.18),
        SIMDE_FLOAT32_C(   525.14), SIMDE_FLOAT32_C(   187.41), SIMDE_FLOAT32_C(  -179.44), SIMDE_FLOAT32_C(   645.88) },
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(  -587.01), SIMDE_FLOAT32_C(  -591.70), SIMDE_FLOAT32_C(  -218.59), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(  -182.09), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(   484.30), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
    { UINT16_C(52815),
      { SIMDE_FLOAT32_C(    64.88), SIMDE_FLOAT32_C(   396.86), SIMDE_FLOAT32_C(   811.03), SIMDE_FLOAT32_C(   135.03),
        SIMDE_FLOAT32_C(  -945.83), SIMDE_FLOAT32_C(  -371.06), SIMDE_FLOAT32_C(  -154.85), SIMDE_FLOAT32_C(  -820.21),
        SIMDE_FLOAT32_C(   861.52), SIMDE_FLOAT32_C(  -670.55), SIMDE_FLOAT32_C(   683.04), SIMDE_FLOAT32_C(   736.93),
        SIMDE_FLOAT32_C(   -11.43), SIMDE_FLOAT32_C(   313.78), SIMDE_FLOAT32_C(   953.30), SIMDE_FLOAT32_C(  -312.15) },
      { SIMDE_FLOAT32_C(  -674.93), SIMDE_FLOAT32_C(  -638.40), SIMDE_FLOAT32_C(   857.60), SIMDE_FLOAT32_C(   991.77),
        SIMDE_FLOAT32_C(   502.26), SIMDE_FLOAT32_C(  -274.09), SIMDE_FLOAT32_C(  -966.01), SIMDE_FLOAT32_C(  -716.95),
        SIMDE_FLOAT32_C(  -528.91), SIMDE_FLOAT32_C(   559.13), SIMDE_FLOAT32_C(   470.46), SIMDE_FLOAT32_C(   291.65),
        SIMDE_FLOAT32_C(   205.01), SIMDE_FLOAT32_C(  -545.67), SIMDE_FLOAT32_C(  -678.73), SIMDE_FLOAT32_C(  -730.11) },
      { SIMDE_FLOAT32_C(    64.88), SIMDE_FLOAT32_C(  -674.93), SIMDE_FLOAT32_C(   396.86), SIMDE_FLOAT32_C(  -638.40),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -371.06), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -528.91), SIMDE_FLOAT32_C(  -670.55), SIMDE_FLOAT32_C(   559.13),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   313.78), SIMDE_FLOAT32_C(  -545.67) } },
    { UINT16_C(62411),
      { SIMDE_FLOAT32_C(   404.92), SIMDE_FLOAT32_C(   905.37), SIMDE_FLOAT32_C(  -238.76), SIMDE_FLOAT32_C(  -749.93),
        SIMDE_FLOAT32_C(  -914.85), SIMDE_FLOAT32_C(  -377.23), SIMDE_FLOAT32_C(  -420.49), SIMDE_FLOAT32_C(   768.19),
        SIMDE_FLOAT32_C(  -640.30), SIMDE_FLOAT32_C(   568.09), SIMDE_FLOAT32_C(    81.97), SIMDE_FLOAT32_C(  -687.00),
        SIMDE_FLOAT32_C(  -744.06), SIMDE_FLOAT32_C(   407.03), SIMDE_FLOAT32_C(  -325.40), SIMDE_FLOAT32_C(  -886.47) },
      { SIMDE_FLOAT32_C(   398.81), SIMDE_FLOAT32_C(  -823.14), SIMDE_FLOAT32_C(  -160.56), SIMDE_FLOAT32_C(   432.80),
        SIMDE_FLOAT32_C(  -540.09), SIMDE_FLOAT32_C(   310.53), SIMDE_FLOAT32_C(    -8.07), SIMDE_FLOAT32_C(   930.37),
        SIMDE_FLOAT32_C(  -397.82), SIMDE_FLOAT32_C(  -803.07), SIMDE_FLOAT32_C(  -615.30), SIMDE_FLOAT32_C(   -76.55),
        SIMDE_FLOAT32_C(  -533.18), SIMDE_FLOAT32_C(  -764.11), SIMDE_FLOAT32_C(    55.75), SIMDE_FLOAT32_C(   871.74) },
      { SIMDE_FLOAT32_C(   404.92), SIMDE_FLOAT32_C(   398.81), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -823.14),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -377.23), SIMDE_FLOAT32_C(   310.53),
        SIMDE_FLOAT32_C(  -640.30), SIMDE_FLOAT32_C(  -397.82), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(  -744.06), SIMDE_FLOAT32_C(  -533.18), SIMDE_FLOAT32_C(   407.03), SIMDE_FLOAT32_C(  -764.11) } },
    { UINT16_C(49195),
      { SIMDE_FLOAT32_C(  -878.20), SIMDE_FLOAT32_C(  -773.58), SIMDE_FLOAT32_C(  -560.24), SIMDE_FLOAT32_C(  -298.68),
        SIMDE_FLOAT32_C(   994.61), SIMDE_FLOAT32_C(  -200.54), SIMDE_FLOAT32_C(  -730.59), SIMDE_FLOAT32_C(    76.57),
        SIMDE_FLOAT32_C(   112.46), SIMDE_FLOAT32_C(  -474.66), SIMDE_FLOAT32_C(  -516.39), SIMDE_FLOAT32_C(   787.06),
        SIMDE_FLOAT32_C(  -361.13), SIMDE_FLOAT32_C(   882.41), SIMDE_FLOAT32_C(   963.93), SIMDE_FLOAT32_C(   478.31) },
      { SIMDE_FLOAT32_C(   315.21), SIMDE_FLOAT32_C(  -576.16), SIMDE_FLOAT32_C(  -211.16), SIMDE_FLOAT32_C(  -692.86),
        SIMDE_FLOAT32_C(  -645.79), SIMDE_FLOAT32_C(   391.02), SIMDE_FLOAT32_C(  -495.93), SIMDE_FLOAT32_C(  -261.09),
        SIMDE_FLOAT32_C(  -685.53), SIMDE_FLOAT32_C(   -29.11), SIMDE_FLOAT32_C(   -25.20), SIMDE_FLOAT32_C(   370.22),
        SIMDE_FLOAT32_C(  -157.37), SIMDE_FLOAT32_C(   116.07), SIMDE_FLOAT32_C(   187.22), SIMDE_FLOAT32_C(   -35.56) },
      { SIMDE_FLOAT32_C(  -878.20), SIMDE_FLOAT32_C(   315.21), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -576.16),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -645.79), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   882.41), SIMDE_FLOAT32_C(   116.07) } },
    { UINT16_C(11895),
      { SIMDE_FLOAT32_C(   665.76), SIMDE_FLOAT32_C(   337.09), SIMDE_FLOAT32_C(  -573.55), SIMDE_FLOAT32_C(   935.16),
        SIMDE_FLOAT32_C(  -586.34), SIMDE_FLOAT32_C(   538.91), SIMDE_FLOAT32_C(  -539.50), SIMDE_FLOAT32_C(  -102.73),
        SIMDE_FLOAT32_C(   325.97), SIMDE_FLOAT32_C(    99.38), SIMDE_FLOAT32_C(  -220.31), SIMDE_FLOAT32_C(   289.90),
        SIMDE_FLOAT32_C(  -422.31), SIMDE_FLOAT32_C(  -905.10), SIMDE_FLOAT32_C(   713.74), SIMDE_FLOAT32_C(   366.54) },
      { SIMDE_FLOAT32_C(  -597.96), SIMDE_FLOAT32_C(  -932.05), SIMDE_FLOAT32_C(  -242.44), SIMDE_FLOAT32_C(   -93.89),
        SIMDE_FLOAT32_C(  -193.14), SIMDE_FLOAT32_C(    72.03), SIMDE_FLOAT32_C(   877.01), SIMDE_FLOAT32_C(   781.66),
        SIMDE_FLOAT32_C(  -557.75), SIMDE_FLOAT32_C(  -280.36), SIMDE_FLOAT32_C(  -102.27), SIMDE_FLOAT32_C(   629.47),
        SIMDE_FLOAT32_C(   684.08), SIMDE_FLOAT32_C(  -759.79), SIMDE_FLOAT32_C(   256.46), SIMDE_FLOAT32_C(   349.84) },
      { SIMDE_FLOAT32_C(   665.76), SIMDE_FLOAT32_C(  -597.96), SIMDE_FLOAT32_C(   337.09), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(  -586.34), SIMDE_FLOAT32_C(  -193.14), SIMDE_FLOAT32_C(   538.91), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -557.75), SIMDE_FLOAT32_C(    99.38), SIMDE_FLOAT32_C(  -280.36),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   684.08), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
    { UINT16_C(12848),
      { SIMDE_FLOAT32_C(   285.00), SIMDE_FLOAT32_C(   990.96), SIMDE_FLOAT32_C(   221.82), SIMDE_FLOAT32_C(   745.50),
        SIMDE_FLOAT32_C(  -111.76), SIMDE_FLOAT32_C(  -452.21), SIMDE_FLOAT32_C(  -155.12), SIMDE_FLOAT32_C(   667.92),
        SIMDE_FLOAT32_C(   837.69), SIMDE_FLOAT32_C(   422.57), SIMDE_FLOAT32_C(   762.83), SIMDE_FLOAT32_C(   551.43),
        SIMDE_FLOAT32_C(  -210.89), SIMDE_FLOAT32_C(  -835.13), SIMDE_FLOAT32_C(   619.38), SIMDE_FLOAT32_C(   546.67) },
      { SIMDE_FLOAT32_C(    70.98), SIMDE_FLOAT32_C(  -573.77), SIMDE_FLOAT32_C(  -381.30), SIMDE_FLOAT32_C(   -52.01),
        SIMDE_FLOAT32_C(  -792.11), SIMDE_FLOAT32_C(    60.95), SIMDE_FLOAT32_C(   667.63), SIMDE_FLOAT32_C(   105.62),
        SIMDE_FLOAT32_C(  -309.57), SIMDE_FLOAT32_C(   351.71), SIMDE_FLOAT32_C(   345.82), SIMDE_FLOAT32_C(   946.89),
        SIMDE_FLOAT32_C(  -298.45), SIMDE_FLOAT32_C(   -76.88), SIMDE_FLOAT32_C(   629.79), SIMDE_FLOAT32_C(   986.55) },
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(  -111.76), SIMDE_FLOAT32_C(  -792.11), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -309.57), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(  -210.89), SIMDE_FLOAT32_C(  -298.45), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512 a = simde_mm512_loadu_ps(test_vec[i].a);
    simde__m512 b = simde_mm512_loadu_ps(test_vec[i].b);
    simde__m512 r = simde_mm512_maskz_unpacklo_ps(test_vec[i].k, a, b);
    simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask16 k = simde_test_x86_random_mmask16();
    simde__m512 a = simde_test_x86_random_f32x16(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
    simde__m512 b = simde_test_x86_random_f32x16(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
    simde__m512 r = simde_mm512_maskz_unpacklo_ps(k, a, b);

    simde_test_x86_write_mmask16(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f32x16(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_mask_unpacklo_ps (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde_float32 src[8];
    const simde__mmask8 k;
    const simde_float32 a[8];
    const simde_float32 b[8];
    const simde_float32 r[8];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(  -317.36), SIMDE_FLOAT32_C(  -256.27), SIMDE_FLOAT32_C(  -127.97), SIMDE_FLOAT32_C(   621.38),
        SIMDE_FLOAT32_C(   696.57), SIMDE_FLOAT32_C(  -436.55), SIMDE_FLOAT32_C(   575.47), SIMDE_FLOAT32_C(  -732.34) },
      UINT8_C(174),
      { SIMDE_FLOAT32_C(   310.56), SIMDE_FLOAT32_C(  -356.20), SIMDE_FLOAT32_C(  -896.55), SIMDE_FLOAT32_C(  -437.07),
        SIMDE_FLOAT32_C(   -55.01), SIMDE_FLOAT32_C(  -607.88), SIMDE_FLOAT32_C(  -282.17), SIMDE_FLOAT32_C(  -635.29) },
      { SIMDE_FLOAT32_C(   149.03), SIMDE_FLOAT32_C(  -769.16), SIMDE_FLOAT32_C(  -782.25), SIMDE_FLOAT32_C(   802.56),
        SIMDE_FLOAT32_C(    83.76), SIMDE_FLOAT32_C(  -587.98), SIMDE_FLOAT32_C(   788.58), SIMDE_FLOAT32_C(   406.85) },
      { SIMDE_FLOAT32_C(  -317.36), SIMDE_FLOAT32_C(   149.03), SIMDE_FLOAT32_C(  -356.20), SIMDE_FLOAT32_C(  -769.16),
        SIMDE_FLOAT32_C(   696.57), SIMDE_FLOAT32_C(    83.76), SIMDE_FLOAT32_C(   575.47), SIMDE_FLOAT32_C(  -587.98) } },
    { { SIMDE_FLOAT32_C(  -311.07), SIMDE_FLOAT32_C(  -640.64), SIMDE_FLOAT32_C(  -990.88), SIMDE_FLOAT32_C(   308.04),
        SIMDE_FLOAT32_C(   180.51), SIMDE_FLOAT32_C(   870.16), SIMDE_FLOAT32_C(   990.68), SIMDE_FLOAT32_C(   924.24) },
      UINT8_C(  8),
      { SIMDE_FLOAT32_C(   612.07), SIMDE_FLOAT32_C(   620.81), SIMDE_FLOAT32_C(   305.64), SIMDE_FLOAT32_C(   187.53),
        SIMDE_FLOAT32_C(   888.48), SIMDE_FLOAT32_C(    95.63), SIMDE_FLOAT32_C(  -501.91), SIMDE_FLOAT32_C(  -467.73) },
      { SIMDE_FLOAT32_C(   199.08), SIMDE_FLOAT32_C(    61.02), SIMDE_FLOAT32_C(   477.27), SIMDE_FLOAT32_C(   591.20),
        SIMDE_FLOAT32_C(   778.86), SIMDE_FLOAT32_C(   841.97), SIMDE_FLOAT32_C(  -259.77), SIMDE_FLOAT32_C(  -990.30) },
      { SIMDE_FLOAT32_C(  -311.07), SIMDE_FLOAT32_C(  -640.64), SIMDE_FLOAT32_C(  -990.88), SIMDE_FLOAT32_C(    61.02),
        SIMDE_FLOAT32_C(   180.51), SIMDE_FLOAT32_C(   870.16), SIMDE_FLOAT32_C(   990.68), SIMDE_FLOAT32_C(   924.24) } },
    { { SIMDE_FLOAT32_C(  -940.28), SIMDE_FLOAT32_C(  -457.20), SIMDE_FLOAT32_C(    93.46), SIMDE_FLOAT32_C(  -528.25),
        SIMDE_FLOAT32_C(  -668.62), SIMDE_FLOAT32_C(  -499.69), SIMDE_FLOAT32_C(   160.68), SIMDE_FLOAT32_C(  -309.26) },
      UINT8_C( 14),
      { SIMDE_FLOAT32_C(  -531.28), SIMDE_FLOAT32_C(   871.25), SIMDE_FLOAT32_C(  -620.41), SIMDE_FLOAT32_C(  -540.60),
        SIMDE_FLOAT32_C(   795.50), SIMDE_FLOAT32_C(   121.78), SIMDE_FLOAT32_C(  -928.53), SIMDE_FLOAT32_C(   416.31) },
      { SIMDE_FLOAT32_C(  -572.58), SIMDE_FLOAT32_C(   259.00), SIMDE_FLOAT32_C(   304.79), SIMDE_FLOAT32_C(   523.05),
        SIMDE_FLOAT32_C(   757.09), SIMDE_FLOAT32_C(   837.06), SIMDE_FLOAT32_C(  -277.87), SIMDE_FLOAT32_C(  -181.89) },
      { SIMDE_FLOAT32_C(  -940.28), SIMDE_FLOAT32_C(  -572.58), SIMDE_FLOAT32_C(   871.25), SIMDE_FLOAT32_C(   259.00),
        SIMDE_FLOAT32_C(  -668.62), SIMDE_FLOAT32_C(  -499.69), SIMDE_FLOAT32_C(   160.68), SIMDE_FLOAT32_C(  -309.26) } },
    { { SIMDE_FLOAT32_C(   314.33), SIMDE_FLOAT32_C(  -686.66), SIMDE_FLOAT32_C(  -403.04), SIMDE_FLOAT32_C(   156.31),
        SIMDE_FLOAT32_C(    53.57), SIMDE_FLOAT32_C(  -393.34), SIMDE_FLOAT32_C(   216.03), SIMDE_FLOAT32_C(   596.37) },
      UINT8_C(178),
      { SIMDE_FLOAT32_C(   687.77), SIMDE_FLOAT32_C(   927.75), SIMDE_FLOAT32_C(  -799.57), SIMDE_FLOAT32_C(  -151.55),
        SIMDE_FLOAT32_C(  -381.51), SIMDE_FLOAT32_C(  -290.14), SIMDE_FLOAT32_C(   317.16), SIMDE_FLOAT32_C(  -510.26) },
      { SIMDE_FLOAT32_C(    89.45), SIMDE_FLOAT32_C(   776.56), SIMDE_FLOAT32_C(  -714.77), SIMDE_FLOAT32_C(  -788.77),
        SIMDE_FLOAT32_C(   848.03), SIMDE_FLOAT32_C(   701.54), SIMDE_FLOAT32_C(  -361.34), SIMDE_FLOAT32_C(   107.03) },
      { SIMDE_FLOAT32_C(   314.33), SIMDE_FLOAT32_C(    89.45), SIMDE_FLOAT32_C(  -403.04), SIMDE_FLOAT32_C(   156.31),
        SIMDE_FLOAT32_C(  -381.51), SIMDE_FLOAT32_C(   848.03), SIMDE_FLOAT32_C(   216.03), SIMDE_FLOAT32_C(   701.54) } },
    { { SIMDE_FLOAT32_C(     6.33), SIMDE_FLOAT32_C(  -838.29), SIMDE_FLOAT32_C(  -135.88), SIMDE_FLOAT32_C(  -156.61),
        SIMDE_FLOAT32_C(  -116.16), SIMDE_FLOAT32_C(   682.23), SIMDE_FLOAT32_C(  -842.28), SIMDE_FLOAT32_C(   197.18) },
      UINT8_C(210),
      { SIMDE_FLOAT32_C(   314.03), SIMDE_FLOAT32_C(  -749.25), SIMDE_FLOAT32_C(  -114.15), SIMDE_FLOAT32_C(  -469.95),
        SIMDE_FLOAT32_C(   847.12), SIMDE_FLOAT32_C(  -414.03), SIMDE_FLOAT32_C(  -782.17), SIMDE_FLOAT32_C(   774.87) },
      { SIMDE_FLOAT32_C(  -213.60), SIMDE_FLOAT32_C(    66.28), SIMDE_FLOAT32_C(  -606.65), SIMDE_FLOAT32_C(   496.26),
        SIMDE_FLOAT32_C(  -616.56), SIMDE_FLOAT32_C(  -116.91), SIMDE_FLOAT32_C(  -414.29), SIMDE_FLOAT32_C(  -840.00) },
      { SIMDE_FLOAT32_C(     6.33), SIMDE_FLOAT32_C(  -213.60), SIMDE_FLOAT32_C(  -135.88), SIMDE_FLOAT32_C(  -156.61),
        SIMDE_FLOAT32_C(   847.12), SIMDE_FLOAT32_C(   682.23), SIMDE_FLOAT32_C(  -414.03), SIMDE_FLOAT32_C(  -116.91) } },
    { { SIMDE_FLOAT32_C(   168.32), SIMDE_FLOAT32_C(  -203.06), SIMDE_FLOAT32_C(  -991.97), SIMDE_FLOAT32_C(  -130.14),
        SIMDE_FLOAT32_C(   435.60), SIMDE_FLOAT32_C(   115.06), SIMDE_FLOAT32_C(   876.19), SIMDE_FLOAT32_C(   597.31) },
      UINT8_C(128),
      { SIMDE_FLOAT32_C(  -280.42), SIMDE_FLOAT32_C(  -518.85), SIMDE_FLOAT32_C(   661.40), SIMDE_FLOAT32_C(  -122.70),
        SIMDE_FLOAT32_C(   678.33), SIMDE_FLOAT32_C(   940.60), SIMDE_FLOAT32_C(  -808.67), SIMDE_FLOAT32_C(   929.08) },
      { SIMDE_FLOAT32_C(  -173.55), SIMDE_FLOAT32_C(  -278.62), SIMDE_FLOAT32_C(   776.20), SIMDE_FLOAT32_C(   412.42),
        SIMDE_FLOAT32_C(   -60.80), SIMDE_FLOAT32_C(   551.07), SIMDE_FLOAT32_C(  -801.18), SIMDE_FLOAT32_C(  -994.52) },
      { SIMDE_FLOAT32_C(   168.32), SIMDE_FLOAT32_C(  -203.06), SIMDE_FLOAT32_C(  -991.97), SIMDE_FLOAT32_C(  -130.14),
        SIMDE_FLOAT32_C(   435.60), SIMDE_FLOAT32_C(   115.06), SIMDE_FLOAT32_C(   876.19), SIMDE_FLOAT32_C(   551.07) } },
    { { SIMDE_FLOAT32_C(   944.42), SIMDE_FLOAT32_C(   695.08), SIMDE_FLOAT32_C(  -611.08), SIMDE_FLOAT32_C(  -172.49),
        SIMDE_FLOAT32_C(  -719.21), SIMDE_FLOAT32_C(  -451.08), SIMDE_FLOAT32_C(   995.83), SIMDE_FLOAT32_C(    77.73) },
      UINT8_C(110),
      { SIMDE_FLOAT32_C(  -134.30), SIMDE_FLOAT32_C(  -486.68), SIMDE_FLOAT32_C(   672.01), SIMDE_FLOAT32_C(  -258.11),
        SIMDE_FLOAT32_C(  -889.37), SIMDE_FLOAT32_C(   651.19), SIMDE_FLOAT32_C(   461.47), SIMDE_FLOAT32_C(  -408.22) },
      { SIMDE_FLOAT32_C(   312.59), SIMDE_FLOAT32_C(  -661.23), SIMDE_FLOAT32_C(  -729.89), SIMDE_FLOAT32_C(   253.19),
        SIMDE_FLOAT32_C(  -469.91), SIMDE_FLOAT32_C(  -800.81), SIMDE_FLOAT32_C(  -920.36), SIMDE_FLOAT32_C(   251.47) },
      { SIMDE_FLOAT32_C(   944.42), SIMDE_FLOAT32_C(   312.59), SIMDE_FLOAT32_C(  -486.68), SIMDE_FLOAT32_C(  -661.23),
        SIMDE_FLOAT32_C(  -719.21), SIMDE_FLOAT32_C(  -469.91), SIMDE_FLOAT32_C(   651.19), SIMDE_FLOAT32_C(    77.73) } },
    { { SIMDE_FLOAT32_C(   975.39), SIMDE_FLOAT32_C(   492.07), SIMDE_FLOAT32_C(  -809.32), SIMDE_FLOAT32_C(   526.46),
        SIMDE_FLOAT32_C(   690.89), SIMDE_FLOAT32_C(  -803.84), SIMDE_FLOAT32_C(   470.88), SIMDE_FLOAT32_C(   385.97) },
      UINT8_C(230),
      { SIMDE_FLOAT32_C(  -701.61), SIMDE_FLOAT32_C(   666.76), SIMDE_FLOAT32_C(   134.00), SIMDE_FLOAT32_C(  -705.77),
        SIMDE_FLOAT32_C(  -255.51), SIMDE_FLOAT32_C(   690.95), SIMDE_FLOAT32_C(   159.92), SIMDE_FLOAT32_C(   257.81) },
      { SIMDE_FLOAT32_C(   362.96), SIMDE_FLOAT32_C(   901.81), SIMDE_FLOAT32_C(   368.45), SIMDE_FLOAT32_C(    14.15),
        SIMDE_FLOAT32_C(   363.28), SIMDE_FLOAT32_C(   960.23), SIMDE_FLOAT32_C(  -673.25), SIMDE_FLOAT32_C(   702.04) },
      { SIMDE_FLOAT32_C(   975.39), SIMDE_FLOAT32_C(   362.96), SIMDE_FLOAT32_C(   666.76), SIMDE_FLOAT32_C(   526.46),
        SIMDE_FLOAT32_C(   690.89), SIMDE_FLOAT32_C(   363.28), SIMDE_FLOAT32_C(   690.95), SIMDE_FLOAT32_C(   960.23) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256 src = simde_mm256_loadu_ps(test_vec[i].src);
    simde__mmask8 k = test_vec[i].k;
    simde__m256 a = simde_mm256_loadu_ps(test_vec[i].a);
    simde__m256 b = simde_mm256_loadu_ps(test_vec[i].b);
    simde__m256 r = simde_mm256_mask_unpacklo_ps(src, k, a, b);
    simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m256 src = simde_test_x86_random_f32x8(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m256 a = simde_test_x86_random_f32x8(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
    simde__m256 b = simde_test_x86_random_f32x8(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
    simde__m256 r = simde_mm256_mask_unpacklo_ps(src, k, a, b);

    simde_test_x86_write_f32x8(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_maskz_unpacklo_ps (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k;
    const simde_float32 a[8];
    const simde_float32 b[8];
    const simde_float32 r[8];
  } test_vec[] = {
    { UINT8_C(215),
      { SIMDE_FLOAT32_C(    55.97), SIMDE_FLOAT32_C(  -643.69), SIMDE_FLOAT32_C(   448.27), SIMDE_FLOAT32_C(   675.73),
        SIMDE_FLOAT32_C(   722.15), SIMDE_FLOAT32_C(   955.98), SIMDE_FLOAT32_C(   -94.72), SIMDE_FLOAT32_C(  -998.57) },
      { SIMDE_FLOAT32_C(  -378.27), SIMDE_FLOAT32_C(   -22.48), SIMDE_FLOAT32_C(  -550.11), SIMDE_FLOAT32_C(  -480.99),
        SIMDE_FLOAT32_C(  -865.82), SIMDE_FLOAT32_C(    30.18), SIMDE_FLOAT32_C(    96.42), SIMDE_FLOAT32_C(  -254.71) },
      { SIMDE_FLOAT32_C(    55.97), SIMDE_FLOAT32_C(  -378.27), SIMDE_FLOAT32_C(  -643.69), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(   722.15), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   955.98), SIMDE_FLOAT32_C(    30.18) } },
    { UINT8_C(246),
      { SIMDE_FLOAT32_C(  -674.66), SIMDE_FLOAT32_C(   401.96), SIMDE_FLOAT32_C(  -920.67), SIMDE_FLOAT32_C(   276.90),
        SIMDE_FLOAT32_C(  -336.72), SIMDE_FLOAT32_C(   397.08), SIMDE_FLOAT32_C(    49.54), SIMDE_FLOAT32_C(  -899.02) },
      { SIMDE_FLOAT32_C(   903.38), SIMDE_FLOAT32_C(  -502.34), SIMDE_FLOAT32_C(  -778.73), SIMDE_FLOAT32_C(   805.01),
        SIMDE_FLOAT32_C(  -318.04), SIMDE_FLOAT32_C(  -425.06), SIMDE_FLOAT32_C(  -139.01), SIMDE_FLOAT32_C(    38.27) },
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   903.38), SIMDE_FLOAT32_C(   401.96), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(  -336.72), SIMDE_FLOAT32_C(  -318.04), SIMDE_FLOAT32_C(   397.08), SIMDE_FLOAT32_C(  -425.06) } },
    { UINT8_C(197),
      { SIMDE_FLOAT32_C(  -463.29), SIMDE_FLOAT32_C(  -239.59), SIMDE_FLOAT32_C(   979.19), SIMDE_FLOAT32_C(   441.99),
        SIMDE_FLOAT32_C(  -238.15), SIMDE_FLOAT32_C(  -399.08), SIMDE_FLOAT32_C(  -580.49), SIMDE_FLOAT32_C(   211.74) },
      { SIMDE_FLOAT32_C(   119.93), SIMDE_FLOAT32_C(  -446.31), SIMDE_FLOAT32_C(  -758.07), SIMDE_FLOAT32_C(  -783.65),
        SIMDE_FLOAT32_C(   298.98), SIMDE_FLOAT32_C(   827.68), SIMDE_FLOAT32_C(  -458.30), SIMDE_FLOAT32_C(  -299.06) },
      { SIMDE_FLOAT32_C(  -463.29), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -239.59), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -399.08), SIMDE_FLOAT32_C(   827.68) } },
    { UINT8_C(228),
      { SIMDE_FLOAT32_C(   818.59), SIMDE_FLOAT32_C(   364.22), SIMDE_FLOAT32_C(   304.09), SIMDE_FLOAT32_C(  -131.87),
        SIMDE_FLOAT32_C(   465.20), SIMDE_FLOAT32_C(   207.47), SIMDE_FLOAT32_C(   365.79), SIMDE_FLOAT32_C(   686.47) },
      { SIMDE_FLOAT32_C(    12.48), SIMDE_FLOAT32_C(  -952.25), SIMDE_FLOAT32_C(  -738.59), SIMDE_FLOAT32_C(   873.47),
        SIMDE_FLOAT32_C(    86.02), SIMDE_FLOAT32_C(  -715.38), SIMDE_FLOAT32_C(  -589.82), SIMDE_FLOAT32_C(   846.43) },
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   364.22), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(    86.02), SIMDE_FLOAT32_C(   207.47), SIMDE_FLOAT32_C(  -715.38) } },
    { UINT8_C(146),
      { SIMDE_FLOAT32_C(   852.18), SIMDE_FLOAT32_C(  -391.72), SIMDE_FLOAT32_C(  -135.27), SIMDE_FLOAT32_C(  -728.31),
        SIMDE_FLOAT32_C(   820.02), SIMDE_FLOAT32_C(   984.67), SIMDE_FLOAT32_C(  -174.61), SIMDE_FLOAT32_C(  -938.05) },
      { SIMDE_FLOAT32_C(  -798.98), SIMDE_FLOAT32_C(  -875.63), SIMDE_FLOAT32_C(   889.63), SIMDE_FLOAT32_C(  -257.28),
        SIMDE_FLOAT32_C(  -174.69), SIMDE_FLOAT32_C(   796.64), SIMDE_FLOAT32_C(  -438.69), SIMDE_FLOAT32_C(  -810.47) },
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -798.98), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(   820.02), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   796.64) } },
    { UINT8_C( 99),
      { SIMDE_FLOAT32_C(   429.44), SIMDE_FLOAT32_C(   654.73), SIMDE_FLOAT32_C(  -691.80), SIMDE_FLOAT32_C(  -204.76),
        SIMDE_FLOAT32_C(   341.20), SIMDE_FLOAT32_C(   320.69), SIMDE_FLOAT32_C(  -157.01), SIMDE_FLOAT32_C(   602.62) },
      { SIMDE_FLOAT32_C(   194.16), SIMDE_FLOAT32_C(   929.01), SIMDE_FLOAT32_C(   887.24), SIMDE_FLOAT32_C(   604.34),
        SIMDE_FLOAT32_C(   775.44), SIMDE_FLOAT32_C(  -848.95), SIMDE_FLOAT32_C(   456.52), SIMDE_FLOAT32_C(  -616.27) },
      { SIMDE_FLOAT32_C(   429.44), SIMDE_FLOAT32_C(   194.16), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   775.44), SIMDE_FLOAT32_C(   320.69), SIMDE_FLOAT32_C(     0.00) } },
    { UINT8_C( 61),
      { SIMDE_FLOAT32_C(   728.21), SIMDE_FLOAT32_C(  -796.25), SIMDE_FLOAT32_C(     0.45), SIMDE_FLOAT32_C(  -446.41),
        SIMDE_FLOAT32_C(  -734.30), SIMDE_FLOAT32_C(   201.47), SIMDE_FLOAT32_C(  -322.04), SIMDE_FLOAT32_C(  -844.67) },
      { SIMDE_FLOAT32_C(   944.19), SIMDE_FLOAT32_C(   503.27), SIMDE_FLOAT32_C(   951.97), SIMDE_FLOAT32_C(  -494.50),
        SIMDE_FLOAT32_C(   692.79), SIMDE_FLOAT32_C(    52.71), SIMDE_FLOAT32_C(   934.94), SIMDE_FLOAT32_C(   347.52) },
      { SIMDE_FLOAT32_C(   728.21), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -796.25), SIMDE_FLOAT32_C(   503.27),
        SIMDE_FLOAT32_C(  -734.30), SIMDE_FLOAT32_C(   692.79), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
    { UINT8_C(199),
      { SIMDE_FLOAT32_C(  -269.82), SIMDE_FLOAT32_C(  -311.27), SIMDE_FLOAT32_C(  -318.40), SIMDE_FLOAT32_C(   573.17),
        SIMDE_FLOAT32_C(  -708.65), SIMDE_FLOAT32_C(   875.76), SIMDE_FLOAT32_C(   502.18), SIMDE_FLOAT32_C(  -821.41) },
      { SIMDE_FLOAT32_C(   480.10), SIMDE_FLOAT32_C(   277.62), SIMDE_FLOAT32_C(  -670.36), SIMDE_FLOAT32_C(   -63.38),
        SIMDE_FLOAT32_C(   661.35), SIMDE_FLOAT32_C(   345.43), SIMDE_FLOAT32_C(  -335.17), SIMDE_FLOAT32_C(   865.10) },
      { SIMDE_FLOAT32_C(  -269.82), SIMDE_FLOAT32_C(   480.10), SIMDE_FLOAT32_C(  -311.27), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   875.76), SIMDE_FLOAT32_C(   345.43) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__mmask8 k = test_vec[i].k;
    simde__m256 a = simde_mm256_loadu_ps(test_vec[i].a);
    simde__m256 b = simde_mm256_loadu_ps(test_vec[i].b);
    simde__m256 r = simde_mm256_maskz_unpacklo_ps(k, a, b);
    simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m256 a = simde_test_x86_random_f32x8(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
    simde__m256 b = simde_test_x86_random_f32x8(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
    simde__m256 r = simde_mm256_maskz_unpacklo_ps(k, a, b);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f32x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_mask_unpacklo_ps (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde_float32 src[4];
    const simde__mmask8 k;
    const simde_float32 a[4];
    const simde_float32 b[4];
    const simde_float32 r[4];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(   481.74), SIMDE_FLOAT32_C(  -740.46), SIMDE_FLOAT32_C(  -580.80), SIMDE_FLOAT32_C(   123.76) },
      UINT8_C(213),
      { SIMDE_FLOAT32_C(  -192.18), SIMDE_FLOAT32_C(  -702.93), SIMDE_FLOAT32_C(  -916.94), SIMDE_FLOAT32_C(   992.20) },
      { SIMDE_FLOAT32_C(   213.42), SIMDE_FLOAT32_C(    -9.38), SIMDE_FLOAT32_C(   823.66), SIMDE_FLOAT32_C(   854.35) },
      { SIMDE_FLOAT32_C(  -192.18), SIMDE_FLOAT32_C(  -740.46), SIMDE_FLOAT32_C(  -702.93), SIMDE_FLOAT32_C(   123.76) } },
    { { SIMDE_FLOAT32_C(  -333.97), SIMDE_FLOAT32_C(   947.67), SIMDE_FLOAT32_C(  -992.55), SIMDE_FLOAT32_C(   804.12) },
      UINT8_C(185),
      { SIMDE_FLOAT32_C(   758.71), SIMDE_FLOAT32_C(   616.56), SIMDE_FLOAT32_C(   300.22), SIMDE_FLOAT32_C(   -97.01) },
      { SIMDE_FLOAT32_C(   486.32), SIMDE_FLOAT32_C(   596.93), SIMDE_FLOAT32_C(  -182.14), SIMDE_FLOAT32_C(  -701.94) },
      { SIMDE_FLOAT32_C(   758.71), SIMDE_FLOAT32_C(   947.67), SIMDE_FLOAT32_C(  -992.55), SIMDE_FLOAT32_C(   596.93) } },
    { { SIMDE_FLOAT32_C(   -94.59), SIMDE_FLOAT32_C(  -258.00), SIMDE_FLOAT32_C(  -356.86), SIMDE_FLOAT32_C(   241.36) },
      UINT8_C( 16),
      { SIMDE_FLOAT32_C(  -875.12), SIMDE_FLOAT32_C(   500.90), SIMDE_FLOAT32_C(  -110.37), SIMDE_FLOAT32_C(   248.65) },
      { SIMDE_FLOAT32_C(  -716.94), SIMDE_FLOAT32_C(   697.45), SIMDE_FLOAT32_C(   545.71), SIMDE_FLOAT32_C(  -633.87) },
      { SIMDE_FLOAT32_C(   -94.59), SIMDE_FLOAT32_C(  -258.00), SIMDE_FLOAT32_C(  -356.86), SIMDE_FLOAT32_C(   241.36) } },
    { { SIMDE_FLOAT32_C(   689.65), SIMDE_FLOAT32_C(  -240.87), SIMDE_FLOAT32_C(   356.75), SIMDE_FLOAT32_C(   513.31) },
      UINT8_C( 15),
      { SIMDE_FLOAT32_C(  -977.23), SIMDE_FLOAT32_C(   460.98), SIMDE_FLOAT32_C(  -379.07), SIMDE_FLOAT32_C(   826.89) },
      { SIMDE_FLOAT32_C(   555.23), SIMDE_FLOAT32_C(  -620.36), SIMDE_FLOAT32_C(   443.45), SIMDE_FLOAT32_C(  -144.55) },
      { SIMDE_FLOAT32_C(  -977.23), SIMDE_FLOAT32_C(   555.23), SIMDE_FLOAT32_C(   460.98), SIMDE_FLOAT32_C(  -620.36) } },
    { { SIMDE_FLOAT32_C(   282.63), SIMDE_FLOAT32_C(   -70.23), SIMDE_FLOAT32_C(  -547.62), SIMDE_FLOAT32_C(  -899.50) },
      UINT8_C(208),
      { SIMDE_FLOAT32_C(   357.80), SIMDE_FLOAT32_C(  -157.51), SIMDE_FLOAT32_C(   870.97), SIMDE_FLOAT32_C(  -400.85) },
      { SIMDE_FLOAT32_C(   312.92), SIMDE_FLOAT32_C(   995.85), SIMDE_FLOAT32_C(  -899.95), SIMDE_FLOAT32_C(  -797.44) },
      { SIMDE_FLOAT32_C(   282.63), SIMDE_FLOAT32_C(   -70.23), SIMDE_FLOAT32_C(  -547.62), SIMDE_FLOAT32_C(  -899.50) } },
    { { SIMDE_FLOAT32_C(   244.50), SIMDE_FLOAT32_C(  -616.88), SIMDE_FLOAT32_C(   900.01), SIMDE_FLOAT32_C(  -209.79) },
      UINT8_C(224),
      { SIMDE_FLOAT32_C(   589.66), SIMDE_FLOAT32_C(   549.34), SIMDE_FLOAT32_C(  -894.01), SIMDE_FLOAT32_C(   102.97) },
      { SIMDE_FLOAT32_C(  -837.18), SIMDE_FLOAT32_C(  -871.24), SIMDE_FLOAT32_C(  -436.05), SIMDE_FLOAT32_C(  -216.25) },
      { SIMDE_FLOAT32_C(   244.50), SIMDE_FLOAT32_C(  -616.88), SIMDE_FLOAT32_C(   900.01), SIMDE_FLOAT32_C(  -209.79) } },
    { { SIMDE_FLOAT32_C(   955.65), SIMDE_FLOAT32_C(  -880.82), SIMDE_FLOAT32_C(   163.39), SIMDE_FLOAT32_C(   399.10) },
      UINT8_C(250),
      { SIMDE_FLOAT32_C(  -553.97), SIMDE_FLOAT32_C(  -671.12), SIMDE_FLOAT32_C(   427.02), SIMDE_FLOAT32_C(  -453.48) },
      { SIMDE_FLOAT32_C(   556.71), SIMDE_FLOAT32_C(  -215.18), SIMDE_FLOAT32_C(   389.01), SIMDE_FLOAT32_C(   427.68) },
      { SIMDE_FLOAT32_C(   955.65), SIMDE_FLOAT32_C(   556.71), SIMDE_FLOAT32_C(   163.39), SIMDE_FLOAT32_C(  -215.18) } },
    { { SIMDE_FLOAT32_C(   383.97), SIMDE_FLOAT32_C(  -298.06), SIMDE_FLOAT32_C(   423.53), SIMDE_FLOAT32_C(   484.03) },
      UINT8_C(191),
      { SIMDE_FLOAT32_C(  -331.97), SIMDE_FLOAT32_C(   867.14), SIMDE_FLOAT32_C(  -195.50), SIMDE_FLOAT32_C(   458.24) },
      { SIMDE_FLOAT32_C(  -383.62), SIMDE_FLOAT32_C(  -605.84), SIMDE_FLOAT32_C(     7.58), SIMDE_FLOAT32_C(  -277.63) },
      { SIMDE_FLOAT32_C(  -331.97), SIMDE_FLOAT32_C(  -383.62), SIMDE_FLOAT32_C(   867.14), SIMDE_FLOAT32_C(  -605.84) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128 src = simde_mm_loadu_ps(test_vec[i].src);
    simde__mmask8 k = test_vec[i].k;
    simde__m128 a = simde_mm_loadu_ps(test_vec[i].a);
    simde__m128 b = simde_mm_loadu_ps(test_vec[i].b);
    simde__m128 r = simde_mm_mask_unpacklo_ps(src, k, a, b);
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
    simde__m128 r = simde_mm_mask_unpacklo_ps(src, k, a, b);

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
test_simde_mm_maskz_unpacklo_ps (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k;
    const simde_float32 a[4];
    const simde_float32 b[4];
    const simde_float32 r[4];
  } test_vec[] = {
    { UINT8_C(145),
      { SIMDE_FLOAT32_C(   320.48), SIMDE_FLOAT32_C(   373.96), SIMDE_FLOAT32_C(   864.99), SIMDE_FLOAT32_C(   508.59) },
      { SIMDE_FLOAT32_C(  -345.59), SIMDE_FLOAT32_C(   388.78), SIMDE_FLOAT32_C(  -639.98), SIMDE_FLOAT32_C(  -843.70) },
      { SIMDE_FLOAT32_C(   320.48), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
    { UINT8_C(193),
      { SIMDE_FLOAT32_C(   413.09), SIMDE_FLOAT32_C(  -213.77), SIMDE_FLOAT32_C(  -694.86), SIMDE_FLOAT32_C(    28.71) },
      { SIMDE_FLOAT32_C(   649.96), SIMDE_FLOAT32_C(  -956.83), SIMDE_FLOAT32_C(   698.28), SIMDE_FLOAT32_C(  -972.18) },
      { SIMDE_FLOAT32_C(   413.09), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
    { UINT8_C(188),
      { SIMDE_FLOAT32_C(  -354.80), SIMDE_FLOAT32_C(   747.95), SIMDE_FLOAT32_C(  -343.94), SIMDE_FLOAT32_C(  -457.21) },
      { SIMDE_FLOAT32_C(  -498.95), SIMDE_FLOAT32_C(  -612.98), SIMDE_FLOAT32_C(  -211.32), SIMDE_FLOAT32_C(   814.42) },
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   747.95), SIMDE_FLOAT32_C(  -612.98) } },
    { UINT8_C( 64),
      { SIMDE_FLOAT32_C(  -808.94), SIMDE_FLOAT32_C(  -990.39), SIMDE_FLOAT32_C(  -161.66), SIMDE_FLOAT32_C(  -559.04) },
      { SIMDE_FLOAT32_C(   330.09), SIMDE_FLOAT32_C(  -787.70), SIMDE_FLOAT32_C(  -694.06), SIMDE_FLOAT32_C(  -161.32) },
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
    { UINT8_C( 58),
      { SIMDE_FLOAT32_C(   694.72), SIMDE_FLOAT32_C(   198.69), SIMDE_FLOAT32_C(    23.01), SIMDE_FLOAT32_C(  -187.07) },
      { SIMDE_FLOAT32_C(  -388.22), SIMDE_FLOAT32_C(   809.24), SIMDE_FLOAT32_C(   118.06), SIMDE_FLOAT32_C(   640.49) },
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -388.22), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   809.24) } },
    { UINT8_C(230),
      { SIMDE_FLOAT32_C(   161.24), SIMDE_FLOAT32_C(   338.77), SIMDE_FLOAT32_C(   487.02), SIMDE_FLOAT32_C(  -351.79) },
      { SIMDE_FLOAT32_C(   983.97), SIMDE_FLOAT32_C(   234.97), SIMDE_FLOAT32_C(   304.27), SIMDE_FLOAT32_C(  -473.24) },
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   983.97), SIMDE_FLOAT32_C(   338.77), SIMDE_FLOAT32_C(     0.00) } },
    { UINT8_C( 45),
      { SIMDE_FLOAT32_C(   691.29), SIMDE_FLOAT32_C(   315.44), SIMDE_FLOAT32_C(   550.44), SIMDE_FLOAT32_C(  -184.02) },
      { SIMDE_FLOAT32_C(   506.49), SIMDE_FLOAT32_C(   560.04), SIMDE_FLOAT32_C(   654.31), SIMDE_FLOAT32_C(   947.45) },
      { SIMDE_FLOAT32_C(   691.29), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   315.44), SIMDE_FLOAT32_C(   560.04) } },
    { UINT8_C(240),
      { SIMDE_FLOAT32_C(   866.61), SIMDE_FLOAT32_C(  -746.61), SIMDE_FLOAT32_C(   728.80), SIMDE_FLOAT32_C(  -266.68) },
      { SIMDE_FLOAT32_C(   948.12), SIMDE_FLOAT32_C(   -72.50), SIMDE_FLOAT32_C(   756.34), SIMDE_FLOAT32_C(  -238.96) },
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__mmask8 k = test_vec[i].k;
    simde__m128 a = simde_mm_loadu_ps(test_vec[i].a);
    simde__m128 b = simde_mm_loadu_ps(test_vec[i].b);
    simde__m128 r = simde_mm_maskz_unpacklo_ps(k, a, b);
    simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m128 a = simde_test_x86_random_f32x4(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
    simde__m128 b = simde_test_x86_random_f32x4(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
    simde__m128 r = simde_mm_maskz_unpacklo_ps(k, a, b);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f32x4(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
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

static int
test_simde_mm512_mask_unpacklo_pd (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde_float64 src[8];
    const simde__mmask8 k;
    const simde_float64 a[8];
    const simde_float64 b[8];
    const simde_float64 r[8];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(   341.30), SIMDE_FLOAT64_C(  -301.08), SIMDE_FLOAT64_C(  -706.25), SIMDE_FLOAT64_C(    -5.43),
        SIMDE_FLOAT64_C(   414.74), SIMDE_FLOAT64_C(   551.51), SIMDE_FLOAT64_C(  -470.65), SIMDE_FLOAT64_C(  -727.63) },
      UINT8_C( 63),
      { SIMDE_FLOAT64_C(  -975.63), SIMDE_FLOAT64_C(   823.33), SIMDE_FLOAT64_C(   158.51), SIMDE_FLOAT64_C(  -629.51),
        SIMDE_FLOAT64_C(    42.74), SIMDE_FLOAT64_C(  -246.28), SIMDE_FLOAT64_C(  -783.15), SIMDE_FLOAT64_C(   777.70) },
      { SIMDE_FLOAT64_C(   984.72), SIMDE_FLOAT64_C(   -59.12), SIMDE_FLOAT64_C(   265.33), SIMDE_FLOAT64_C(  -604.84),
        SIMDE_FLOAT64_C(   754.62), SIMDE_FLOAT64_C(   377.71), SIMDE_FLOAT64_C(   870.87), SIMDE_FLOAT64_C(  -301.79) },
      { SIMDE_FLOAT64_C(  -975.63), SIMDE_FLOAT64_C(   984.72), SIMDE_FLOAT64_C(   158.51), SIMDE_FLOAT64_C(   265.33),
        SIMDE_FLOAT64_C(    42.74), SIMDE_FLOAT64_C(   754.62), SIMDE_FLOAT64_C(  -470.65), SIMDE_FLOAT64_C(  -727.63) } },
    { { SIMDE_FLOAT64_C(  -267.45), SIMDE_FLOAT64_C(  -155.94), SIMDE_FLOAT64_C(  -323.10), SIMDE_FLOAT64_C(   865.32),
        SIMDE_FLOAT64_C(   145.65), SIMDE_FLOAT64_C(   731.62), SIMDE_FLOAT64_C(   206.62), SIMDE_FLOAT64_C(   844.57) },
      UINT8_C(211),
      { SIMDE_FLOAT64_C(  -798.81), SIMDE_FLOAT64_C(   259.31), SIMDE_FLOAT64_C(   576.88), SIMDE_FLOAT64_C(  -269.46),
        SIMDE_FLOAT64_C(   531.68), SIMDE_FLOAT64_C(  -222.39), SIMDE_FLOAT64_C(  -245.08), SIMDE_FLOAT64_C(   355.01) },
      { SIMDE_FLOAT64_C(   936.12), SIMDE_FLOAT64_C(   125.41), SIMDE_FLOAT64_C(  -602.25), SIMDE_FLOAT64_C(  -310.15),
        SIMDE_FLOAT64_C(   342.26), SIMDE_FLOAT64_C(  -824.56), SIMDE_FLOAT64_C(  -325.44), SIMDE_FLOAT64_C(  -716.86) },
      { SIMDE_FLOAT64_C(  -798.81), SIMDE_FLOAT64_C(   936.12), SIMDE_FLOAT64_C(  -323.10), SIMDE_FLOAT64_C(   865.32),
        SIMDE_FLOAT64_C(   531.68), SIMDE_FLOAT64_C(   731.62), SIMDE_FLOAT64_C(  -245.08), SIMDE_FLOAT64_C(  -325.44) } },
    { { SIMDE_FLOAT64_C(   440.78), SIMDE_FLOAT64_C(    69.72), SIMDE_FLOAT64_C(  -962.24), SIMDE_FLOAT64_C(  -181.51),
        SIMDE_FLOAT64_C(   -59.41), SIMDE_FLOAT64_C(  -264.03), SIMDE_FLOAT64_C(   551.04), SIMDE_FLOAT64_C(   784.66) },
      UINT8_C( 28),
      { SIMDE_FLOAT64_C(   416.36), SIMDE_FLOAT64_C(   -69.69), SIMDE_FLOAT64_C(   144.49), SIMDE_FLOAT64_C(  -377.01),
        SIMDE_FLOAT64_C(  -225.12), SIMDE_FLOAT64_C(   169.86), SIMDE_FLOAT64_C(  -175.82), SIMDE_FLOAT64_C(  -965.81) },
      { SIMDE_FLOAT64_C(  -253.27), SIMDE_FLOAT64_C(   554.72), SIMDE_FLOAT64_C(   565.87), SIMDE_FLOAT64_C(   524.35),
        SIMDE_FLOAT64_C(  -690.36), SIMDE_FLOAT64_C(   -79.12), SIMDE_FLOAT64_C(   460.47), SIMDE_FLOAT64_C(   435.04) },
      { SIMDE_FLOAT64_C(   440.78), SIMDE_FLOAT64_C(    69.72), SIMDE_FLOAT64_C(   144.49), SIMDE_FLOAT64_C(   565.87),
        SIMDE_FLOAT64_C(  -225.12), SIMDE_FLOAT64_C(  -264.03), SIMDE_FLOAT64_C(   551.04), SIMDE_FLOAT64_C(   784.66) } },
    { { SIMDE_FLOAT64_C(   318.63), SIMDE_FLOAT64_C(  -849.68), SIMDE_FLOAT64_C(  -222.70), SIMDE_FLOAT64_C(   494.07),
        SIMDE_FLOAT64_C(  -175.12), SIMDE_FLOAT64_C(    60.43), SIMDE_FLOAT64_C(   -65.15), SIMDE_FLOAT64_C(   894.60) },
      UINT8_C( 76),
      { SIMDE_FLOAT64_C(   753.34), SIMDE_FLOAT64_C(  -164.81), SIMDE_FLOAT64_C(   834.17), SIMDE_FLOAT64_C(   304.38),
        SIMDE_FLOAT64_C(  -380.15), SIMDE_FLOAT64_C(   247.04), SIMDE_FLOAT64_C(  -279.25), SIMDE_FLOAT64_C(   550.16) },
      { SIMDE_FLOAT64_C(  -608.47), SIMDE_FLOAT64_C(   343.73), SIMDE_FLOAT64_C(  -674.96), SIMDE_FLOAT64_C(   561.39),
        SIMDE_FLOAT64_C(  -832.09), SIMDE_FLOAT64_C(  -640.78), SIMDE_FLOAT64_C(  -691.88), SIMDE_FLOAT64_C(   722.63) },
      { SIMDE_FLOAT64_C(   318.63), SIMDE_FLOAT64_C(  -849.68), SIMDE_FLOAT64_C(   834.17), SIMDE_FLOAT64_C(  -674.96),
        SIMDE_FLOAT64_C(  -175.12), SIMDE_FLOAT64_C(    60.43), SIMDE_FLOAT64_C(  -279.25), SIMDE_FLOAT64_C(   894.60) } },
    { { SIMDE_FLOAT64_C(   925.10), SIMDE_FLOAT64_C(   832.47), SIMDE_FLOAT64_C(  -967.74), SIMDE_FLOAT64_C(  -154.02),
        SIMDE_FLOAT64_C(   292.94), SIMDE_FLOAT64_C(   467.30), SIMDE_FLOAT64_C(  -835.40), SIMDE_FLOAT64_C(   443.26) },
      UINT8_C(129),
      { SIMDE_FLOAT64_C(   658.68), SIMDE_FLOAT64_C(  -731.86), SIMDE_FLOAT64_C(   305.04), SIMDE_FLOAT64_C(  -406.47),
        SIMDE_FLOAT64_C(  -837.26), SIMDE_FLOAT64_C(  -596.77), SIMDE_FLOAT64_C(  -653.13), SIMDE_FLOAT64_C(    -2.07) },
      { SIMDE_FLOAT64_C(  -762.60), SIMDE_FLOAT64_C(   651.25), SIMDE_FLOAT64_C(   617.79), SIMDE_FLOAT64_C(   484.43),
        SIMDE_FLOAT64_C(  -628.00), SIMDE_FLOAT64_C(   167.95), SIMDE_FLOAT64_C(   875.96), SIMDE_FLOAT64_C(   715.73) },
      { SIMDE_FLOAT64_C(   658.68), SIMDE_FLOAT64_C(   832.47), SIMDE_FLOAT64_C(  -967.74), SIMDE_FLOAT64_C(  -154.02),
        SIMDE_FLOAT64_C(   292.94), SIMDE_FLOAT64_C(   467.30), SIMDE_FLOAT64_C(  -835.40), SIMDE_FLOAT64_C(   875.96) } },
    { { SIMDE_FLOAT64_C(   492.98), SIMDE_FLOAT64_C(   437.35), SIMDE_FLOAT64_C(   883.64), SIMDE_FLOAT64_C(   852.21),
        SIMDE_FLOAT64_C(   745.47), SIMDE_FLOAT64_C(   606.27), SIMDE_FLOAT64_C(   777.30), SIMDE_FLOAT64_C(   577.93) },
      UINT8_C( 36),
      { SIMDE_FLOAT64_C(  -376.72), SIMDE_FLOAT64_C(  -129.12), SIMDE_FLOAT64_C(   105.83), SIMDE_FLOAT64_C(  -212.12),
        SIMDE_FLOAT64_C(  -685.87), SIMDE_FLOAT64_C(   350.43), SIMDE_FLOAT64_C(  -553.44), SIMDE_FLOAT64_C(  -417.73) },
      { SIMDE_FLOAT64_C(  -344.53), SIMDE_FLOAT64_C(    40.09), SIMDE_FLOAT64_C(  -254.99), SIMDE_FLOAT64_C(    58.70),
        SIMDE_FLOAT64_C(   386.95), SIMDE_FLOAT64_C(   742.94), SIMDE_FLOAT64_C(   296.10), SIMDE_FLOAT64_C(    38.21) },
      { SIMDE_FLOAT64_C(   492.98), SIMDE_FLOAT64_C(   437.35), SIMDE_FLOAT64_C(   105.83), SIMDE_FLOAT64_C(   852.21),
        SIMDE_FLOAT64_C(   745.47), SIMDE_FLOAT64_C(   386.95), SIMDE_FLOAT64_C(   777.30), SIMDE_FLOAT64_C(   577.93) } },
    { { SIMDE_FLOAT64_C(   360.73), SIMDE_FLOAT64_C(  -219.47), SIMDE_FLOAT64_C(   410.21), SIMDE_FLOAT64_C(  -471.32),
        SIMDE_FLOAT64_C(  -343.51), SIMDE_FLOAT64_C(   125.94), SIMDE_FLOAT64_C(  -978.34), SIMDE_FLOAT64_C(  -906.16) },
      UINT8_C(234),
      { SIMDE_FLOAT64_C(   873.87), SIMDE_FLOAT64_C(   839.30), SIMDE_FLOAT64_C(  -384.16), SIMDE_FLOAT64_C(   651.17),
        SIMDE_FLOAT64_C(   417.24), SIMDE_FLOAT64_C(  -745.63), SIMDE_FLOAT64_C(  -725.55), SIMDE_FLOAT64_C(  -711.89) },
      { SIMDE_FLOAT64_C(   360.20), SIMDE_FLOAT64_C(    62.33), SIMDE_FLOAT64_C(  -397.75), SIMDE_FLOAT64_C(  -289.37),
        SIMDE_FLOAT64_C(   508.90), SIMDE_FLOAT64_C(   184.52), SIMDE_FLOAT64_C(   366.10), SIMDE_FLOAT64_C(  -451.02) },
      { SIMDE_FLOAT64_C(   360.73), SIMDE_FLOAT64_C(   360.20), SIMDE_FLOAT64_C(   410.21), SIMDE_FLOAT64_C(  -397.75),
        SIMDE_FLOAT64_C(  -343.51), SIMDE_FLOAT64_C(   508.90), SIMDE_FLOAT64_C(  -725.55), SIMDE_FLOAT64_C(   366.10) } },
    { { SIMDE_FLOAT64_C(   929.53), SIMDE_FLOAT64_C(  -575.20), SIMDE_FLOAT64_C(   935.94), SIMDE_FLOAT64_C(   672.48),
        SIMDE_FLOAT64_C(   720.90), SIMDE_FLOAT64_C(   -25.86), SIMDE_FLOAT64_C(    33.21), SIMDE_FLOAT64_C(  -498.57) },
      UINT8_C(116),
      { SIMDE_FLOAT64_C(   561.89), SIMDE_FLOAT64_C(   157.92), SIMDE_FLOAT64_C(   510.29), SIMDE_FLOAT64_C(   583.55),
        SIMDE_FLOAT64_C(   251.76), SIMDE_FLOAT64_C(  -480.13), SIMDE_FLOAT64_C(   457.41), SIMDE_FLOAT64_C(    91.06) },
      { SIMDE_FLOAT64_C(   135.71), SIMDE_FLOAT64_C(   108.58), SIMDE_FLOAT64_C(  -491.70), SIMDE_FLOAT64_C(   390.08),
        SIMDE_FLOAT64_C(   383.03), SIMDE_FLOAT64_C(  -203.59), SIMDE_FLOAT64_C(  -249.72), SIMDE_FLOAT64_C(  -554.63) },
      { SIMDE_FLOAT64_C(   929.53), SIMDE_FLOAT64_C(  -575.20), SIMDE_FLOAT64_C(   510.29), SIMDE_FLOAT64_C(   672.48),
        SIMDE_FLOAT64_C(   251.76), SIMDE_FLOAT64_C(   383.03), SIMDE_FLOAT64_C(   457.41), SIMDE_FLOAT64_C(  -498.57) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512d src = simde_mm512_loadu_pd(test_vec[i].src);
    simde__m512d a = simde_mm512_loadu_pd(test_vec[i].a);
    simde__m512d b = simde_mm512_loadu_pd(test_vec[i].b);
    simde__m512d r = simde_mm512_mask_unpacklo_pd(src, test_vec[i].k, a, b);
    simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m512d src = simde_test_x86_random_f64x8(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m512d a = simde_test_x86_random_f64x8(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde__m512d b = simde_test_x86_random_f64x8(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde__m512d r = simde_mm512_mask_unpacklo_pd(src, k, a, b);

    simde_test_x86_write_f64x8(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_maskz_unpacklo_pd (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k;
    const simde_float64 a[8];
    const simde_float64 b[8];
    const simde_float64 r[8];
  } test_vec[] = {
    { UINT8_C( 47),
      { SIMDE_FLOAT64_C(   663.78), SIMDE_FLOAT64_C(   181.43), SIMDE_FLOAT64_C(   970.05), SIMDE_FLOAT64_C(  -665.34),
        SIMDE_FLOAT64_C(   452.85), SIMDE_FLOAT64_C(  -117.43), SIMDE_FLOAT64_C(  -730.91), SIMDE_FLOAT64_C(   823.72) },
      { SIMDE_FLOAT64_C(  -250.78), SIMDE_FLOAT64_C(   702.27), SIMDE_FLOAT64_C(   859.32), SIMDE_FLOAT64_C(   175.55),
        SIMDE_FLOAT64_C(   507.44), SIMDE_FLOAT64_C(   912.97), SIMDE_FLOAT64_C(  -728.79), SIMDE_FLOAT64_C(  -673.11) },
      { SIMDE_FLOAT64_C(   663.78), SIMDE_FLOAT64_C(  -250.78), SIMDE_FLOAT64_C(   970.05), SIMDE_FLOAT64_C(   859.32),
        SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(   507.44), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00) } },
    { UINT8_C(  0),
      { SIMDE_FLOAT64_C(   967.80), SIMDE_FLOAT64_C(  -220.28), SIMDE_FLOAT64_C(   437.57), SIMDE_FLOAT64_C(    -5.70),
        SIMDE_FLOAT64_C(  -131.53), SIMDE_FLOAT64_C(  -633.09), SIMDE_FLOAT64_C(  -264.17), SIMDE_FLOAT64_C(   843.57) },
      { SIMDE_FLOAT64_C(   434.77), SIMDE_FLOAT64_C(   443.48), SIMDE_FLOAT64_C(   425.60), SIMDE_FLOAT64_C(   817.73),
        SIMDE_FLOAT64_C(  -852.22), SIMDE_FLOAT64_C(   267.55), SIMDE_FLOAT64_C(   481.51), SIMDE_FLOAT64_C(   329.22) },
      { SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00),
        SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00) } },
    { UINT8_C( 47),
      { SIMDE_FLOAT64_C(   816.17), SIMDE_FLOAT64_C(  -217.93), SIMDE_FLOAT64_C(  -879.83), SIMDE_FLOAT64_C(  -914.74),
        SIMDE_FLOAT64_C(  -394.21), SIMDE_FLOAT64_C(  -130.61), SIMDE_FLOAT64_C(   787.53), SIMDE_FLOAT64_C(  -534.89) },
      { SIMDE_FLOAT64_C(  -955.06), SIMDE_FLOAT64_C(   294.97), SIMDE_FLOAT64_C(  -621.92), SIMDE_FLOAT64_C(  -683.84),
        SIMDE_FLOAT64_C(   621.86), SIMDE_FLOAT64_C(  -261.95), SIMDE_FLOAT64_C(  -716.04), SIMDE_FLOAT64_C(  -598.42) },
      { SIMDE_FLOAT64_C(   816.17), SIMDE_FLOAT64_C(  -955.06), SIMDE_FLOAT64_C(  -879.83), SIMDE_FLOAT64_C(  -621.92),
        SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(   621.86), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00) } },
    { UINT8_C(244),
      { SIMDE_FLOAT64_C(   278.26), SIMDE_FLOAT64_C(   270.05), SIMDE_FLOAT64_C(  -457.46), SIMDE_FLOAT64_C(  -985.90),
        SIMDE_FLOAT64_C(   113.62), SIMDE_FLOAT64_C(   977.31), SIMDE_FLOAT64_C(   457.58), SIMDE_FLOAT64_C(  -460.78) },
      { SIMDE_FLOAT64_C(   795.03), SIMDE_FLOAT64_C(   605.36), SIMDE_FLOAT64_C(   806.78), SIMDE_FLOAT64_C(   276.54),
        SIMDE_FLOAT64_C(   -65.42), SIMDE_FLOAT64_C(    44.38), SIMDE_FLOAT64_C(    92.71), SIMDE_FLOAT64_C(   716.65) },
      { SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(  -457.46), SIMDE_FLOAT64_C(     0.00),
        SIMDE_FLOAT64_C(   113.62), SIMDE_FLOAT64_C(   -65.42), SIMDE_FLOAT64_C(   457.58), SIMDE_FLOAT64_C(    92.71) } },
    { UINT8_C( 37),
      { SIMDE_FLOAT64_C(   177.98), SIMDE_FLOAT64_C(  -677.57), SIMDE_FLOAT64_C(  -966.06), SIMDE_FLOAT64_C(   -34.49),
        SIMDE_FLOAT64_C(  -212.46), SIMDE_FLOAT64_C(  -921.12), SIMDE_FLOAT64_C(  -739.53), SIMDE_FLOAT64_C(   165.62) },
      { SIMDE_FLOAT64_C(  -604.96), SIMDE_FLOAT64_C(   882.34), SIMDE_FLOAT64_C(   903.68), SIMDE_FLOAT64_C(  -321.00),
        SIMDE_FLOAT64_C(  -716.08), SIMDE_FLOAT64_C(  -920.70), SIMDE_FLOAT64_C(   957.26), SIMDE_FLOAT64_C(   553.97) },
      { SIMDE_FLOAT64_C(   177.98), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(  -966.06), SIMDE_FLOAT64_C(     0.00),
        SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(  -716.08), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00) } },
    { UINT8_C( 23),
      { SIMDE_FLOAT64_C(   971.36), SIMDE_FLOAT64_C(  -332.41), SIMDE_FLOAT64_C(  -400.85), SIMDE_FLOAT64_C(   428.94),
        SIMDE_FLOAT64_C(   206.81), SIMDE_FLOAT64_C(  -605.82), SIMDE_FLOAT64_C(    34.30), SIMDE_FLOAT64_C(    13.59) },
      { SIMDE_FLOAT64_C(   670.72), SIMDE_FLOAT64_C(   968.88), SIMDE_FLOAT64_C(  -942.04), SIMDE_FLOAT64_C(  -236.56),
        SIMDE_FLOAT64_C(   685.53), SIMDE_FLOAT64_C(   222.51), SIMDE_FLOAT64_C(   941.41), SIMDE_FLOAT64_C(  -992.04) },
      { SIMDE_FLOAT64_C(   971.36), SIMDE_FLOAT64_C(   670.72), SIMDE_FLOAT64_C(  -400.85), SIMDE_FLOAT64_C(     0.00),
        SIMDE_FLOAT64_C(   206.81), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00) } },
    { UINT8_C( 33),
      { SIMDE_FLOAT64_C(   -93.08), SIMDE_FLOAT64_C(  -204.50), SIMDE_FLOAT64_C(   335.34), SIMDE_FLOAT64_C(   167.39),
        SIMDE_FLOAT64_C(   961.12), SIMDE_FLOAT64_C(   730.38), SIMDE_FLOAT64_C(    49.73), SIMDE_FLOAT64_C(   864.80) },
      { SIMDE_FLOAT64_C(  -590.62), SIMDE_FLOAT64_C(   333.65), SIMDE_FLOAT64_C(   944.10), SIMDE_FLOAT64_C(  -633.35),
        SIMDE_FLOAT64_C(  -112.39), SIMDE_FLOAT64_C(  -434.06), SIMDE_FLOAT64_C(  -661.99), SIMDE_FLOAT64_C(   555.20) },
      { SIMDE_FLOAT64_C(   -93.08), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00),
        SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(  -112.39), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00) } },
    { UINT8_C( 76),
      { SIMDE_FLOAT64_C(   766.95), SIMDE_FLOAT64_C(  -237.99), SIMDE_FLOAT64_C(   559.27), SIMDE_FLOAT64_C(  -198.75),
        SIMDE_FLOAT64_C(   775.60), SIMDE_FLOAT64_C(   229.99), SIMDE_FLOAT64_C(  -229.87), SIMDE_FLOAT64_C(   833.56) },
      { SIMDE_FLOAT64_C(   993.43), SIMDE_FLOAT64_C(  -544.34), SIMDE_FLOAT64_C(    56.07), SIMDE_FLOAT64_C(   934.84),
        SIMDE_FLOAT64_C(  -536.38), SIMDE_FLOAT64_C(  -687.47), SIMDE_FLOAT64_C(  -158.25), SIMDE_FLOAT64_C(   259.12) },
      { SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(   559.27), SIMDE_FLOAT64_C(    56.07),
        SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(  -229.87), SIMDE_FLOAT64_C(     0.00) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512d a = simde_mm512_loadu_pd(test_vec[i].a);
    simde__m512d b = simde_mm512_loadu_pd(test_vec[i].b);
    simde__m512d r = simde_mm512_maskz_unpacklo_pd(test_vec[i].k, a, b);
    simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m512d a = simde_test_x86_random_f64x8(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde__m512d b = simde_test_x86_random_f64x8(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde__m512d r = simde_mm512_maskz_unpacklo_pd(k, a, b);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f64x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_mask_unpacklo_pd (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde_float64 src[4];
    const simde__mmask8 k;
    const simde_float64 a[4];
    const simde_float64 b[4];
    const simde_float64 r[4];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(  -636.25), SIMDE_FLOAT64_C(   726.84), SIMDE_FLOAT64_C(  -981.22), SIMDE_FLOAT64_C(  -335.19) },
      UINT8_C(220),
      { SIMDE_FLOAT64_C(  -435.26), SIMDE_FLOAT64_C(   912.28), SIMDE_FLOAT64_C(   773.75), SIMDE_FLOAT64_C(   648.52) },
      { SIMDE_FLOAT64_C(  -325.04), SIMDE_FLOAT64_C(   513.78), SIMDE_FLOAT64_C(  -461.68), SIMDE_FLOAT64_C(  -107.64) },
      { SIMDE_FLOAT64_C(  -636.25), SIMDE_FLOAT64_C(   726.84), SIMDE_FLOAT64_C(   773.75), SIMDE_FLOAT64_C(  -461.68) } },
    { { SIMDE_FLOAT64_C(  -417.97), SIMDE_FLOAT64_C(  -330.37), SIMDE_FLOAT64_C(  -484.68), SIMDE_FLOAT64_C(  -330.10) },
      UINT8_C( 18),
      { SIMDE_FLOAT64_C(   154.23), SIMDE_FLOAT64_C(   864.15), SIMDE_FLOAT64_C(  -249.13), SIMDE_FLOAT64_C(  -345.14) },
      { SIMDE_FLOAT64_C(   813.32), SIMDE_FLOAT64_C(   798.15), SIMDE_FLOAT64_C(   373.50), SIMDE_FLOAT64_C(  -480.44) },
      { SIMDE_FLOAT64_C(  -417.97), SIMDE_FLOAT64_C(   813.32), SIMDE_FLOAT64_C(  -484.68), SIMDE_FLOAT64_C(  -330.10) } },
    { { SIMDE_FLOAT64_C(  -149.90), SIMDE_FLOAT64_C(   571.52), SIMDE_FLOAT64_C(   147.46), SIMDE_FLOAT64_C(   765.34) },
      UINT8_C(150),
      { SIMDE_FLOAT64_C(   511.21), SIMDE_FLOAT64_C(   492.18), SIMDE_FLOAT64_C(   145.49), SIMDE_FLOAT64_C(  -823.98) },
      { SIMDE_FLOAT64_C(   472.16), SIMDE_FLOAT64_C(   710.23), SIMDE_FLOAT64_C(  -911.70), SIMDE_FLOAT64_C(   245.91) },
      { SIMDE_FLOAT64_C(  -149.90), SIMDE_FLOAT64_C(   472.16), SIMDE_FLOAT64_C(   145.49), SIMDE_FLOAT64_C(   765.34) } },
    { { SIMDE_FLOAT64_C(   358.75), SIMDE_FLOAT64_C(  -236.74), SIMDE_FLOAT64_C(  -240.32), SIMDE_FLOAT64_C(   897.06) },
      UINT8_C(228),
      { SIMDE_FLOAT64_C(   341.71), SIMDE_FLOAT64_C(  -433.31), SIMDE_FLOAT64_C(  -829.06), SIMDE_FLOAT64_C(  -988.39) },
      { SIMDE_FLOAT64_C(  -636.37), SIMDE_FLOAT64_C(   325.17), SIMDE_FLOAT64_C(   875.77), SIMDE_FLOAT64_C(   114.50) },
      { SIMDE_FLOAT64_C(   358.75), SIMDE_FLOAT64_C(  -236.74), SIMDE_FLOAT64_C(  -829.06), SIMDE_FLOAT64_C(   897.06) } },
    { { SIMDE_FLOAT64_C(   980.02), SIMDE_FLOAT64_C(   689.08), SIMDE_FLOAT64_C(   -87.35), SIMDE_FLOAT64_C(   353.53) },
      UINT8_C( 99),
      { SIMDE_FLOAT64_C(   762.75), SIMDE_FLOAT64_C(   -74.95), SIMDE_FLOAT64_C(   356.11), SIMDE_FLOAT64_C(   528.09) },
      { SIMDE_FLOAT64_C(  -948.23), SIMDE_FLOAT64_C(  -132.68), SIMDE_FLOAT64_C(    20.27), SIMDE_FLOAT64_C(   197.26) },
      { SIMDE_FLOAT64_C(   762.75), SIMDE_FLOAT64_C(  -948.23), SIMDE_FLOAT64_C(   -87.35), SIMDE_FLOAT64_C(   353.53) } },
    { { SIMDE_FLOAT64_C(    43.33), SIMDE_FLOAT64_C(  -507.57), SIMDE_FLOAT64_C(   -92.51), SIMDE_FLOAT64_C(   131.63) },
      UINT8_C(242),
      { SIMDE_FLOAT64_C(  -733.76), SIMDE_FLOAT64_C(   894.89), SIMDE_FLOAT64_C(  -501.98), SIMDE_FLOAT64_C(  -836.70) },
      { SIMDE_FLOAT64_C(   550.51), SIMDE_FLOAT64_C(   839.73), SIMDE_FLOAT64_C(  -270.00), SIMDE_FLOAT64_C(   721.45) },
      { SIMDE_FLOAT64_C(    43.33), SIMDE_FLOAT64_C(   550.51), SIMDE_FLOAT64_C(   -92.51), SIMDE_FLOAT64_C(   131.63) } },
    { { SIMDE_FLOAT64_C(   851.34), SIMDE_FLOAT64_C(    93.62), SIMDE_FLOAT64_C(    46.62), SIMDE_FLOAT64_C(   727.11) },
      UINT8_C(212),
      { SIMDE_FLOAT64_C(    26.64), SIMDE_FLOAT64_C(   416.19), SIMDE_FLOAT64_C(   120.76), SIMDE_FLOAT64_C(  -619.83) },
      { SIMDE_FLOAT64_C(   624.84), SIMDE_FLOAT64_C(  -116.49), SIMDE_FLOAT64_C(   305.22), SIMDE_FLOAT64_C(   -19.06) },
      { SIMDE_FLOAT64_C(   851.34), SIMDE_FLOAT64_C(    93.62), SIMDE_FLOAT64_C(   120.76), SIMDE_FLOAT64_C(   727.11) } },
    { { SIMDE_FLOAT64_C(  -588.40), SIMDE_FLOAT64_C(   356.98), SIMDE_FLOAT64_C(   848.26), SIMDE_FLOAT64_C(   431.87) },
      UINT8_C( 31),
      { SIMDE_FLOAT64_C(  -108.41), SIMDE_FLOAT64_C(   924.30), SIMDE_FLOAT64_C(   461.74), SIMDE_FLOAT64_C(  -976.78) },
      { SIMDE_FLOAT64_C(   662.63), SIMDE_FLOAT64_C(   727.98), SIMDE_FLOAT64_C(   918.11), SIMDE_FLOAT64_C(  -839.35) },
      { SIMDE_FLOAT64_C(  -108.41), SIMDE_FLOAT64_C(   662.63), SIMDE_FLOAT64_C(   461.74), SIMDE_FLOAT64_C(   918.11) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256d src = simde_mm256_loadu_pd(test_vec[i].src);
    simde__mmask8 k = test_vec[i].k;
    simde__m256d a = simde_mm256_loadu_pd(test_vec[i].a);
    simde__m256d b = simde_mm256_loadu_pd(test_vec[i].b);
    simde__m256d r = simde_mm256_mask_unpacklo_pd(src, k, a, b);
    simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m256d src = simde_test_x86_random_f64x4(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m256d a = simde_test_x86_random_f64x4(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde__m256d b = simde_test_x86_random_f64x4(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde__m256d r = simde_mm256_mask_unpacklo_pd(src, k, a, b);

    simde_test_x86_write_f64x4(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x4(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_maskz_unpacklo_pd (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k;
    const simde_float64 a[4];
    const simde_float64 b[4];
    const simde_float64 r[4];
  } test_vec[] = {
    { UINT8_C(154),
      { SIMDE_FLOAT64_C(   222.18), SIMDE_FLOAT64_C(   929.82), SIMDE_FLOAT64_C(  -386.10), SIMDE_FLOAT64_C(   482.05) },
      { SIMDE_FLOAT64_C(  -823.14), SIMDE_FLOAT64_C(  -434.17), SIMDE_FLOAT64_C(   246.75), SIMDE_FLOAT64_C(  -387.28) },
      { SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(  -823.14), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(   246.75) } },
    { UINT8_C(249),
      { SIMDE_FLOAT64_C(  -576.08), SIMDE_FLOAT64_C(  -815.16), SIMDE_FLOAT64_C(   709.08), SIMDE_FLOAT64_C(   156.32) },
      { SIMDE_FLOAT64_C(  -740.82), SIMDE_FLOAT64_C(  -242.80), SIMDE_FLOAT64_C(   259.59), SIMDE_FLOAT64_C(   863.10) },
      { SIMDE_FLOAT64_C(  -576.08), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(   259.59) } },
    { UINT8_C( 90),
      { SIMDE_FLOAT64_C(   -83.37), SIMDE_FLOAT64_C(  -175.51), SIMDE_FLOAT64_C(  -385.59), SIMDE_FLOAT64_C(   824.69) },
      { SIMDE_FLOAT64_C(    -9.82), SIMDE_FLOAT64_C(  -712.80), SIMDE_FLOAT64_C(  -856.44), SIMDE_FLOAT64_C(     4.21) },
      { SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(    -9.82), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(  -856.44) } },
    { UINT8_C(228),
      { SIMDE_FLOAT64_C(  -446.90), SIMDE_FLOAT64_C(    56.90), SIMDE_FLOAT64_C(   135.85), SIMDE_FLOAT64_C(   165.96) },
      { SIMDE_FLOAT64_C(  -720.92), SIMDE_FLOAT64_C(    65.66), SIMDE_FLOAT64_C(   779.86), SIMDE_FLOAT64_C(   761.13) },
      { SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(   135.85), SIMDE_FLOAT64_C(     0.00) } },
    { UINT8_C(154),
      { SIMDE_FLOAT64_C(  -654.31), SIMDE_FLOAT64_C(     7.88), SIMDE_FLOAT64_C(   855.24), SIMDE_FLOAT64_C(   976.36) },
      { SIMDE_FLOAT64_C(   431.80), SIMDE_FLOAT64_C(  -959.93), SIMDE_FLOAT64_C(   685.44), SIMDE_FLOAT64_C(  -411.88) },
      { SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(   431.80), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(   685.44) } },
    { UINT8_C( 22),
      { SIMDE_FLOAT64_C(  -557.36), SIMDE_FLOAT64_C(   847.71), SIMDE_FLOAT64_C(  -837.65), SIMDE_FLOAT64_C(  -390.21) },
      { SIMDE_FLOAT64_C(  -235.66), SIMDE_FLOAT64_C(   -13.16), SIMDE_FLOAT64_C(   224.20), SIMDE_FLOAT64_C(  -410.97) },
      { SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(  -235.66), SIMDE_FLOAT64_C(  -837.65), SIMDE_FLOAT64_C(     0.00) } },
    { UINT8_C( 78),
      { SIMDE_FLOAT64_C(   511.40), SIMDE_FLOAT64_C(  -267.41), SIMDE_FLOAT64_C(   -18.77), SIMDE_FLOAT64_C(  -966.13) },
      { SIMDE_FLOAT64_C(   285.69), SIMDE_FLOAT64_C(  -961.87), SIMDE_FLOAT64_C(   169.72), SIMDE_FLOAT64_C(  -548.35) },
      { SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(   285.69), SIMDE_FLOAT64_C(   -18.77), SIMDE_FLOAT64_C(   169.72) } },
    { UINT8_C(200),
      { SIMDE_FLOAT64_C(  -764.62), SIMDE_FLOAT64_C(  -768.49), SIMDE_FLOAT64_C(  -921.65), SIMDE_FLOAT64_C(   477.91) },
      { SIMDE_FLOAT64_C(  -422.80), SIMDE_FLOAT64_C(    86.22), SIMDE_FLOAT64_C(   333.14), SIMDE_FLOAT64_C(  -446.44) },
      { SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(   333.14) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__mmask8 k = test_vec[i].k;
    simde__m256d a = simde_mm256_loadu_pd(test_vec[i].a);
    simde__m256d b = simde_mm256_loadu_pd(test_vec[i].b);
    simde__m256d r = simde_mm256_maskz_unpacklo_pd(k, a, b);
    simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m256d a = simde_test_x86_random_f64x4(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde__m256d b = simde_test_x86_random_f64x4(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde__m256d r = simde_mm256_maskz_unpacklo_pd(k, a, b);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f64x4(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_mask_unpacklo_pd (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde_float64 src[2];
    const simde__mmask8 k;
    const simde_float64 a[2];
    const simde_float64 b[2];
    const simde_float64 r[2];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(  -298.07), SIMDE_FLOAT64_C(  -893.24) },
      UINT8_C(150),
      { SIMDE_FLOAT64_C(  -929.11), SIMDE_FLOAT64_C(  -480.27) },
      { SIMDE_FLOAT64_C(  -158.58), SIMDE_FLOAT64_C(  -251.50) },
      { SIMDE_FLOAT64_C(  -298.07), SIMDE_FLOAT64_C(  -158.58) } },
    { { SIMDE_FLOAT64_C(   607.37), SIMDE_FLOAT64_C(  -943.10) },
      UINT8_C(170),
      { SIMDE_FLOAT64_C(  -980.17), SIMDE_FLOAT64_C(   861.52) },
      { SIMDE_FLOAT64_C(   -44.65), SIMDE_FLOAT64_C(  -642.63) },
      { SIMDE_FLOAT64_C(   607.37), SIMDE_FLOAT64_C(   -44.65) } },
    { { SIMDE_FLOAT64_C(  -729.66), SIMDE_FLOAT64_C(    28.15) },
      UINT8_C( 41),
      { SIMDE_FLOAT64_C(  -604.73), SIMDE_FLOAT64_C(  -322.83) },
      { SIMDE_FLOAT64_C(   -27.72), SIMDE_FLOAT64_C(  -993.62) },
      { SIMDE_FLOAT64_C(  -604.73), SIMDE_FLOAT64_C(    28.15) } },
    { { SIMDE_FLOAT64_C(     1.03), SIMDE_FLOAT64_C(  -786.64) },
      UINT8_C( 41),
      { SIMDE_FLOAT64_C(  -519.63), SIMDE_FLOAT64_C(   914.42) },
      { SIMDE_FLOAT64_C(  -622.31), SIMDE_FLOAT64_C(  -180.83) },
      { SIMDE_FLOAT64_C(  -519.63), SIMDE_FLOAT64_C(  -786.64) } },
    { { SIMDE_FLOAT64_C(   415.45), SIMDE_FLOAT64_C(  -374.96) },
      UINT8_C( 59),
      { SIMDE_FLOAT64_C(  -882.62), SIMDE_FLOAT64_C(  -268.19) },
      { SIMDE_FLOAT64_C(  -352.35), SIMDE_FLOAT64_C(  -811.72) },
      { SIMDE_FLOAT64_C(  -882.62), SIMDE_FLOAT64_C(  -352.35) } },
    { { SIMDE_FLOAT64_C(   251.54), SIMDE_FLOAT64_C(   489.07) },
      UINT8_C( 64),
      { SIMDE_FLOAT64_C(  -141.09), SIMDE_FLOAT64_C(   545.97) },
      { SIMDE_FLOAT64_C(   428.25), SIMDE_FLOAT64_C(  -121.26) },
      { SIMDE_FLOAT64_C(   251.54), SIMDE_FLOAT64_C(   489.07) } },
    { { SIMDE_FLOAT64_C(   407.49), SIMDE_FLOAT64_C(  -616.40) },
      UINT8_C( 25),
      { SIMDE_FLOAT64_C(   677.83), SIMDE_FLOAT64_C(   411.75) },
      { SIMDE_FLOAT64_C(  -152.19), SIMDE_FLOAT64_C(  -926.90) },
      { SIMDE_FLOAT64_C(   677.83), SIMDE_FLOAT64_C(  -616.40) } },
    { { SIMDE_FLOAT64_C(  -911.08), SIMDE_FLOAT64_C(   820.09) },
      UINT8_C(234),
      { SIMDE_FLOAT64_C(    89.95), SIMDE_FLOAT64_C(  -966.55) },
      { SIMDE_FLOAT64_C(   323.60), SIMDE_FLOAT64_C(   570.32) },
      { SIMDE_FLOAT64_C(  -911.08), SIMDE_FLOAT64_C(   323.60) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128d src = simde_mm_loadu_pd(test_vec[i].src);
    simde__mmask8 k = test_vec[i].k;
    simde__m128d a = simde_mm_loadu_pd(test_vec[i].a);
    simde__m128d b = simde_mm_loadu_pd(test_vec[i].b);
    simde__m128d r = simde_mm_mask_unpacklo_pd(src, k, a, b);
    simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128d src = simde_test_x86_random_f64x2(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m128d a = simde_test_x86_random_f64x2(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde__m128d b = simde_test_x86_random_f64x2(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde__m128d r = simde_mm_mask_unpacklo_pd(src, k, a, b);

    simde_test_x86_write_f64x2(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x2(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_maskz_unpacklo_pd (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k;
    const simde_float64 a[2];
    const simde_float64 b[2];
    const simde_float64 r[2];
  } test_vec[] = {
    { UINT8_C(204),
      { SIMDE_FLOAT64_C(   177.36), SIMDE_FLOAT64_C(  -227.27) },
      { SIMDE_FLOAT64_C(   213.92), SIMDE_FLOAT64_C(  -651.37) },
      { SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00) } },
    { UINT8_C(127),
      { SIMDE_FLOAT64_C(  -671.72), SIMDE_FLOAT64_C(   555.16) },
      { SIMDE_FLOAT64_C(  -623.93), SIMDE_FLOAT64_C(  -100.52) },
      { SIMDE_FLOAT64_C(  -671.72), SIMDE_FLOAT64_C(  -623.93) } },
    { UINT8_C(124),
      { SIMDE_FLOAT64_C(    -5.33), SIMDE_FLOAT64_C(  -925.85) },
      { SIMDE_FLOAT64_C(   253.66), SIMDE_FLOAT64_C(  -660.63) },
      { SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00) } },
    { UINT8_C(158),
      { SIMDE_FLOAT64_C(  -721.20), SIMDE_FLOAT64_C(  -282.78) },
      { SIMDE_FLOAT64_C(  -651.90), SIMDE_FLOAT64_C(  -700.50) },
      { SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(  -651.90) } },
    { UINT8_C(125),
      { SIMDE_FLOAT64_C(  -124.82), SIMDE_FLOAT64_C(   559.98) },
      { SIMDE_FLOAT64_C(  -687.53), SIMDE_FLOAT64_C(  -105.69) },
      { SIMDE_FLOAT64_C(  -124.82), SIMDE_FLOAT64_C(     0.00) } },
    { UINT8_C(127),
      { SIMDE_FLOAT64_C(  -965.84), SIMDE_FLOAT64_C(  -294.38) },
      { SIMDE_FLOAT64_C(  -500.22), SIMDE_FLOAT64_C(  -502.08) },
      { SIMDE_FLOAT64_C(  -965.84), SIMDE_FLOAT64_C(  -500.22) } },
    { UINT8_C(155),
      { SIMDE_FLOAT64_C(   -63.64), SIMDE_FLOAT64_C(   675.28) },
      { SIMDE_FLOAT64_C(  -394.92), SIMDE_FLOAT64_C(  -849.72) },
      { SIMDE_FLOAT64_C(   -63.64), SIMDE_FLOAT64_C(  -394.92) } },
    { UINT8_C( 51),
      { SIMDE_FLOAT64_C(   727.00), SIMDE_FLOAT64_C(  -521.44) },
      { SIMDE_FLOAT64_C(   579.07), SIMDE_FLOAT64_C(  -896.93) },
      { SIMDE_FLOAT64_C(   727.00), SIMDE_FLOAT64_C(   579.07) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__mmask8 k = test_vec[i].k;
    simde__m128d a = simde_mm_loadu_pd(test_vec[i].a);
    simde__m128d b = simde_mm_loadu_pd(test_vec[i].b);
    simde__m128d r = simde_mm_maskz_unpacklo_pd(k, a, b);
    simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m128d a = simde_test_x86_random_f64x2(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde__m128d b = simde_test_x86_random_f64x2(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde__m128d r = simde_mm_maskz_unpacklo_pd(k, a, b);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f64x2(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_unpacklo_epi8)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_unpacklo_epi8)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_maskz_unpacklo_epi8)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_mask_unpacklo_epi8)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_maskz_unpacklo_epi8)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_mask_unpacklo_epi8)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_maskz_unpacklo_epi8)

  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_unpacklo_epi16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_unpacklo_epi16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_maskz_unpacklo_epi16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_mask_unpacklo_epi16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_maskz_unpacklo_epi16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_mask_unpacklo_epi16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_maskz_unpacklo_epi16)

  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_unpacklo_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_unpacklo_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_maskz_unpacklo_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_mask_unpacklo_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_maskz_unpacklo_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_mask_unpacklo_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_maskz_unpacklo_epi32)

  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_unpacklo_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_unpacklo_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_maskz_unpacklo_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_mask_unpacklo_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_maskz_unpacklo_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_mask_unpacklo_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_maskz_unpacklo_epi64)

  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_unpacklo_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_unpacklo_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_maskz_unpacklo_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_mask_unpacklo_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_maskz_unpacklo_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_mask_unpacklo_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_maskz_unpacklo_ps)

  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_unpacklo_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_unpacklo_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_maskz_unpacklo_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_mask_unpacklo_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_maskz_unpacklo_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_mask_unpacklo_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_maskz_unpacklo_pd)
SIMDE_TEST_FUNC_LIST_END

#include <test/x86/avx512/test-avx512-footer.h>
