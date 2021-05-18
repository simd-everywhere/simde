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

#define SIMDE_TEST_X86_AVX512_INSN unpackhi

#include <test/x86/avx512/test-avx512.h>
#include <simde/x86/avx512/set.h>
#include <simde/x86/avx512/unpackhi.h>

static int
test_simde_mm512_unpackhi_epi8 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const int8_t a[64];
    const int8_t b[64];
    const int8_t r[64];
  } test_vec[] = {
    { { -INT8_C(  38), -INT8_C( 108),  INT8_C(  78), -INT8_C(  75),  INT8_C(  17), -INT8_C( 126), -INT8_C(  86), -INT8_C( 124),
        -INT8_C(   8),  INT8_C(  83), -INT8_C( 101), -INT8_C(   3),  INT8_C(   9),  INT8_C( 117),  INT8_C(  11),  INT8_C(  58),
        -INT8_C(  88),  INT8_C(  72), -INT8_C( 104), -INT8_C(   2),  INT8_C(  22),  INT8_C(  10), -INT8_C(  57), -INT8_C(  70),
         INT8_C( 115), -INT8_C(   6), -INT8_C(  90), -INT8_C( 111), -INT8_C(  44),  INT8_C(  11), -INT8_C(  33), -INT8_C(  82),
        -INT8_C(  97),  INT8_C(  45),  INT8_C(  99), -INT8_C(  80), -INT8_C(  80),  INT8_C(  13),  INT8_C(  52), -INT8_C(  88),
         INT8_C(  96), -INT8_C(  49), -INT8_C(  91),  INT8_C( 105),  INT8_C(  68), -INT8_C(  80), -INT8_C(  92), -INT8_C(  19),
        -INT8_C(   8),  INT8_C(  60), -INT8_C(  21),  INT8_C(  14),  INT8_C(  70), -INT8_C(  78), -INT8_C(  56), -INT8_C(  70),
        -INT8_C(  84),  INT8_C( 111),  INT8_C(  75),      INT8_MIN,  INT8_C( 122),  INT8_C(  42),  INT8_C(  46),  INT8_C(  25) },
      {  INT8_C(  88), -INT8_C( 111), -INT8_C(  55),  INT8_C(   8), -INT8_C(  97), -INT8_C(   3), -INT8_C(  80), -INT8_C(   1),
        -INT8_C(  52),  INT8_C(  85),  INT8_C( 105),  INT8_C(  16),  INT8_C(   6),  INT8_C(  13), -INT8_C(   3), -INT8_C(   2),
         INT8_C(  73), -INT8_C(  24),  INT8_C(  13), -INT8_C( 112), -INT8_C( 102), -INT8_C(  43),  INT8_C(  74),  INT8_C(  70),
         INT8_C(  68), -INT8_C( 107), -INT8_C(  58), -INT8_C(  66), -INT8_C(  64), -INT8_C(  12), -INT8_C(  41),  INT8_C(  24),
        -INT8_C( 122), -INT8_C(  96),  INT8_C(  32),  INT8_C(  37), -INT8_C(  99), -INT8_C(  48),  INT8_C(  36),  INT8_C( 105),
         INT8_C(  37), -INT8_C( 115),  INT8_C( 122),  INT8_C(  43), -INT8_C( 102),  INT8_C( 119),  INT8_C(  42), -INT8_C(  28),
         INT8_C(  96),  INT8_C(  55),  INT8_C( 116), -INT8_C(   6),  INT8_C(  12), -INT8_C(  66),  INT8_C(  65),  INT8_C(  81),
         INT8_C(  83),  INT8_C(   7),  INT8_C(  15),  INT8_C(  19), -INT8_C(   4), -INT8_C(  25),  INT8_C(  43), -INT8_C( 126) },
      { -INT8_C(   8), -INT8_C(  52),  INT8_C(  83),  INT8_C(  85), -INT8_C( 101),  INT8_C( 105), -INT8_C(   3),  INT8_C(  16),
         INT8_C(   9),  INT8_C(   6),  INT8_C( 117),  INT8_C(  13),  INT8_C(  11), -INT8_C(   3),  INT8_C(  58), -INT8_C(   2),
         INT8_C( 115),  INT8_C(  68), -INT8_C(   6), -INT8_C( 107), -INT8_C(  90), -INT8_C(  58), -INT8_C( 111), -INT8_C(  66),
        -INT8_C(  44), -INT8_C(  64),  INT8_C(  11), -INT8_C(  12), -INT8_C(  33), -INT8_C(  41), -INT8_C(  82),  INT8_C(  24),
         INT8_C(  96),  INT8_C(  37), -INT8_C(  49), -INT8_C( 115), -INT8_C(  91),  INT8_C( 122),  INT8_C( 105),  INT8_C(  43),
         INT8_C(  68), -INT8_C( 102), -INT8_C(  80),  INT8_C( 119), -INT8_C(  92),  INT8_C(  42), -INT8_C(  19), -INT8_C(  28),
        -INT8_C(  84),  INT8_C(  83),  INT8_C( 111),  INT8_C(   7),  INT8_C(  75),  INT8_C(  15),      INT8_MIN,  INT8_C(  19),
         INT8_C( 122), -INT8_C(   4),  INT8_C(  42), -INT8_C(  25),  INT8_C(  46),  INT8_C(  43),  INT8_C(  25), -INT8_C( 126) } },
    { { -INT8_C( 121),  INT8_C(  75), -INT8_C(  89),  INT8_C(  37),  INT8_C(  27), -INT8_C(  53), -INT8_C( 114),  INT8_C(  65),
         INT8_C(  89),  INT8_C(   8),  INT8_C( 108), -INT8_C(  13),      INT8_MIN, -INT8_C( 106), -INT8_C(  41), -INT8_C(  32),
        -INT8_C(  51),  INT8_C(  75), -INT8_C(  38), -INT8_C(  38),  INT8_C(   9),  INT8_C(  27),  INT8_C(  43),  INT8_C(  93),
         INT8_C(  35),  INT8_C(  58),  INT8_C( 112),  INT8_C(  31),  INT8_C(  33), -INT8_C( 100), -INT8_C(  95), -INT8_C(  87),
        -INT8_C(  25),  INT8_C(  72), -INT8_C(  50),  INT8_C(   3),  INT8_C(  19),  INT8_C(  92),  INT8_C(  68),  INT8_C( 108),
         INT8_C( 101), -INT8_C(  80),  INT8_C(  96), -INT8_C(  27),  INT8_C(  71),  INT8_C(  55), -INT8_C(  59),  INT8_C(  20),
        -INT8_C( 125), -INT8_C(  97), -INT8_C(  18), -INT8_C( 116), -INT8_C(  69),  INT8_C(  25), -INT8_C(  23), -INT8_C(  34),
         INT8_C(  84),  INT8_C(  90), -INT8_C(   3),  INT8_C( 117), -INT8_C(  10), -INT8_C(  98),  INT8_C(  30), -INT8_C(  35) },
      { -INT8_C(  26), -INT8_C(  20), -INT8_C(  32), -INT8_C(   7),  INT8_C(  73),  INT8_C(  36),  INT8_C( 102), -INT8_C(  82),
        -INT8_C(  43), -INT8_C(  58), -INT8_C( 109),  INT8_C(  28), -INT8_C(   3),  INT8_C(  88),  INT8_C(  48),      INT8_MIN,
        -INT8_C(   9),  INT8_C(  31),  INT8_C(  13), -INT8_C(  78),  INT8_C(  56), -INT8_C(  10), -INT8_C( 112), -INT8_C( 116),
         INT8_C(  80), -INT8_C( 115),  INT8_C(   2),  INT8_C(  70),  INT8_C(  43),  INT8_C(  32),  INT8_C(  36),  INT8_C(  17),
         INT8_C(  13),  INT8_C(   4),  INT8_C(  11),  INT8_C(  86),  INT8_C(  41),  INT8_C( 113),  INT8_C(   4), -INT8_C(   2),
         INT8_C(  55), -INT8_C( 105),  INT8_C(  26),  INT8_C(  52), -INT8_C(  17),  INT8_C(  74), -INT8_C(  75), -INT8_C(  26),
         INT8_C( 105), -INT8_C(  62), -INT8_C( 103), -INT8_C(  94), -INT8_C(  72),  INT8_C(  41),  INT8_C(  46),  INT8_C(   9),
        -INT8_C(  73),  INT8_C(  48),  INT8_C(  79), -INT8_C(  30),  INT8_C(  81),  INT8_C( 115), -INT8_C(  12),  INT8_C(  94) },
      {  INT8_C(  89), -INT8_C(  43),  INT8_C(   8), -INT8_C(  58),  INT8_C( 108), -INT8_C( 109), -INT8_C(  13),  INT8_C(  28),
             INT8_MIN, -INT8_C(   3), -INT8_C( 106),  INT8_C(  88), -INT8_C(  41),  INT8_C(  48), -INT8_C(  32),      INT8_MIN,
         INT8_C(  35),  INT8_C(  80),  INT8_C(  58), -INT8_C( 115),  INT8_C( 112),  INT8_C(   2),  INT8_C(  31),  INT8_C(  70),
         INT8_C(  33),  INT8_C(  43), -INT8_C( 100),  INT8_C(  32), -INT8_C(  95),  INT8_C(  36), -INT8_C(  87),  INT8_C(  17),
         INT8_C( 101),  INT8_C(  55), -INT8_C(  80), -INT8_C( 105),  INT8_C(  96),  INT8_C(  26), -INT8_C(  27),  INT8_C(  52),
         INT8_C(  71), -INT8_C(  17),  INT8_C(  55),  INT8_C(  74), -INT8_C(  59), -INT8_C(  75),  INT8_C(  20), -INT8_C(  26),
         INT8_C(  84), -INT8_C(  73),  INT8_C(  90),  INT8_C(  48), -INT8_C(   3),  INT8_C(  79),  INT8_C( 117), -INT8_C(  30),
        -INT8_C(  10),  INT8_C(  81), -INT8_C(  98),  INT8_C( 115),  INT8_C(  30), -INT8_C(  12), -INT8_C(  35),  INT8_C(  94) } },
    { {  INT8_C( 120), -INT8_C(   1), -INT8_C(  76), -INT8_C(  95),  INT8_C( 112), -INT8_C(  72), -INT8_C(  97), -INT8_C(  89),
         INT8_C(  79), -INT8_C(  71), -INT8_C(  37),  INT8_C(  62),  INT8_C(   3), -INT8_C( 112),  INT8_C(  36),  INT8_C( 109),
         INT8_C(  82), -INT8_C(  67),  INT8_C(  15),  INT8_C(  11), -INT8_C(  25),  INT8_C(  61),  INT8_C(  20), -INT8_C(  98),
         INT8_C( 110),  INT8_C(  99),      INT8_MIN, -INT8_C(  65), -INT8_C(  41),  INT8_C( 116),  INT8_C(  29),  INT8_C(  79),
         INT8_C( 115), -INT8_C(  47), -INT8_C(  16), -INT8_C(  29), -INT8_C( 119), -INT8_C( 113), -INT8_C( 118), -INT8_C(  40),
         INT8_C(  72),  INT8_C( 102),  INT8_C(  22),  INT8_C(  75), -INT8_C(  10),  INT8_C(  58), -INT8_C(  72),  INT8_C(  73),
        -INT8_C(   8), -INT8_C(  57),  INT8_C(  84), -INT8_C(  33),  INT8_C(   5),  INT8_C( 104),  INT8_C( 125),  INT8_C( 115),
        -INT8_C(  53), -INT8_C(   3),  INT8_C(  50), -INT8_C(  94),  INT8_C( 114),  INT8_C(  79), -INT8_C(  15), -INT8_C(  27) },
      {  INT8_C(  32), -INT8_C(  31), -INT8_C(  55), -INT8_C(  87),  INT8_C( 112),  INT8_C(  83), -INT8_C( 127), -INT8_C(  72),
        -INT8_C(  71), -INT8_C( 105),  INT8_C(   4), -INT8_C(  80), -INT8_C(  47), -INT8_C(  68), -INT8_C(   7), -INT8_C(  55),
        -INT8_C( 124),  INT8_C(  77), -INT8_C(  88), -INT8_C( 119), -INT8_C(  75),  INT8_C(  37), -INT8_C(   4),      INT8_MIN,
         INT8_C(  35),  INT8_C(  46),  INT8_C(  35), -INT8_C( 107),  INT8_C( 125),  INT8_C(  20),  INT8_C( 122), -INT8_C(  99),
        -INT8_C(  10),  INT8_C(  67),  INT8_C(  70),  INT8_C( 102), -INT8_C( 105), -INT8_C(  57),  INT8_C(  31),  INT8_C(  80),
         INT8_C(  94),  INT8_C(  35),  INT8_C(   0),  INT8_C(  47), -INT8_C(  33), -INT8_C(   7), -INT8_C(   7),  INT8_C(  99),
         INT8_C(  70), -INT8_C(  95), -INT8_C(  20), -INT8_C(   5), -INT8_C(  57), -INT8_C(  24),  INT8_C( 124), -INT8_C(  22),
         INT8_C(  22), -INT8_C(  97),      INT8_MAX, -INT8_C( 109), -INT8_C(  77), -INT8_C(   7),  INT8_C(  48), -INT8_C(  87) },
      {  INT8_C(  79), -INT8_C(  71), -INT8_C(  71), -INT8_C( 105), -INT8_C(  37),  INT8_C(   4),  INT8_C(  62), -INT8_C(  80),
         INT8_C(   3), -INT8_C(  47), -INT8_C( 112), -INT8_C(  68),  INT8_C(  36), -INT8_C(   7),  INT8_C( 109), -INT8_C(  55),
         INT8_C( 110),  INT8_C(  35),  INT8_C(  99),  INT8_C(  46),      INT8_MIN,  INT8_C(  35), -INT8_C(  65), -INT8_C( 107),
        -INT8_C(  41),  INT8_C( 125),  INT8_C( 116),  INT8_C(  20),  INT8_C(  29),  INT8_C( 122),  INT8_C(  79), -INT8_C(  99),
         INT8_C(  72),  INT8_C(  94),  INT8_C( 102),  INT8_C(  35),  INT8_C(  22),  INT8_C(   0),  INT8_C(  75),  INT8_C(  47),
        -INT8_C(  10), -INT8_C(  33),  INT8_C(  58), -INT8_C(   7), -INT8_C(  72), -INT8_C(   7),  INT8_C(  73),  INT8_C(  99),
        -INT8_C(  53),  INT8_C(  22), -INT8_C(   3), -INT8_C(  97),  INT8_C(  50),      INT8_MAX, -INT8_C(  94), -INT8_C( 109),
         INT8_C( 114), -INT8_C(  77),  INT8_C(  79), -INT8_C(   7), -INT8_C(  15),  INT8_C(  48), -INT8_C(  27), -INT8_C(  87) } },
    { {  INT8_C(  61),  INT8_C( 118),  INT8_C(  16), -INT8_C(  44),  INT8_C(  61),  INT8_C(  47),  INT8_C(  36), -INT8_C( 101),
         INT8_C(  82),  INT8_C(  37), -INT8_C(  53),  INT8_C(  49),  INT8_C(  30), -INT8_C(  60), -INT8_C( 107),  INT8_C( 101),
         INT8_C( 101), -INT8_C( 127),  INT8_C(  96),  INT8_C(  44),  INT8_C( 106), -INT8_C(  36),  INT8_C(  22),      INT8_MIN,
         INT8_C( 123), -INT8_C( 107),  INT8_C(  20),  INT8_C(  47), -INT8_C( 113),  INT8_C(  68), -INT8_C(  40), -INT8_C(  52),
        -INT8_C(  69), -INT8_C(  24), -INT8_C(  96), -INT8_C(   8),  INT8_C(  23), -INT8_C(  60), -INT8_C( 108),  INT8_C( 105),
        -INT8_C(  23),  INT8_C(  95), -INT8_C( 101),  INT8_C(   8),  INT8_C(  35),  INT8_C(  48),  INT8_C( 109), -INT8_C( 120),
        -INT8_C(  79), -INT8_C(  51), -INT8_C(  75),  INT8_C(  27), -INT8_C(  86), -INT8_C(  53), -INT8_C( 100),  INT8_C(  37),
         INT8_C(  97), -INT8_C(  80),  INT8_C(  84), -INT8_C(  16), -INT8_C(  12),  INT8_C(  45), -INT8_C(  68), -INT8_C(  81) },
      {  INT8_C(  21),  INT8_C(  92), -INT8_C(  88),  INT8_C(  45),  INT8_C(  32),  INT8_C(  60), -INT8_C( 106),  INT8_C(  10),
        -INT8_C( 101),  INT8_C(  49),  INT8_C(  18), -INT8_C(  66),  INT8_C(  97),      INT8_MAX,  INT8_C(  70),  INT8_C(  19),
         INT8_C(  76), -INT8_C(   5),  INT8_C(  46), -INT8_C(  10), -INT8_C(  57), -INT8_C(  54),  INT8_C(  28),  INT8_C(  40),
         INT8_C( 122),  INT8_C( 112),  INT8_C(  24),  INT8_C( 111), -INT8_C(  99), -INT8_C(  44),  INT8_C(  30), -INT8_C(  77),
         INT8_C(  48), -INT8_C(  58), -INT8_C(  32),  INT8_C(  80),  INT8_C(   2),  INT8_C( 118),  INT8_C(  90), -INT8_C(  99),
        -INT8_C(  88),  INT8_C( 108),  INT8_C(  91),  INT8_C(   9), -INT8_C(  21), -INT8_C(  94),  INT8_C(  28),  INT8_C(  56),
        -INT8_C(  99),  INT8_C(  75),  INT8_C(  46),  INT8_C( 100),  INT8_C(  21),  INT8_C(  74), -INT8_C( 116), -INT8_C( 112),
        -INT8_C(  69), -INT8_C(  92), -INT8_C(   1),  INT8_C(  88),  INT8_C( 120),  INT8_C(  29),  INT8_C(  11), -INT8_C(  88) },
      {  INT8_C(  82), -INT8_C( 101),  INT8_C(  37),  INT8_C(  49), -INT8_C(  53),  INT8_C(  18),  INT8_C(  49), -INT8_C(  66),
         INT8_C(  30),  INT8_C(  97), -INT8_C(  60),      INT8_MAX, -INT8_C( 107),  INT8_C(  70),  INT8_C( 101),  INT8_C(  19),
         INT8_C( 123),  INT8_C( 122), -INT8_C( 107),  INT8_C( 112),  INT8_C(  20),  INT8_C(  24),  INT8_C(  47),  INT8_C( 111),
        -INT8_C( 113), -INT8_C(  99),  INT8_C(  68), -INT8_C(  44), -INT8_C(  40),  INT8_C(  30), -INT8_C(  52), -INT8_C(  77),
        -INT8_C(  23), -INT8_C(  88),  INT8_C(  95),  INT8_C( 108), -INT8_C( 101),  INT8_C(  91),  INT8_C(   8),  INT8_C(   9),
         INT8_C(  35), -INT8_C(  21),  INT8_C(  48), -INT8_C(  94),  INT8_C( 109),  INT8_C(  28), -INT8_C( 120),  INT8_C(  56),
         INT8_C(  97), -INT8_C(  69), -INT8_C(  80), -INT8_C(  92),  INT8_C(  84), -INT8_C(   1), -INT8_C(  16),  INT8_C(  88),
        -INT8_C(  12),  INT8_C( 120),  INT8_C(  45),  INT8_C(  29), -INT8_C(  68),  INT8_C(  11), -INT8_C(  81), -INT8_C(  88) } },
    { { -INT8_C(  28), -INT8_C(  21), -INT8_C(   7), -INT8_C(  26),  INT8_C(  98),  INT8_C(  83), -INT8_C( 124),  INT8_C(  10),
        -INT8_C(  64), -INT8_C(  33),  INT8_C(  19), -INT8_C(  85), -INT8_C( 127),  INT8_C(  48), -INT8_C(  29),  INT8_C(  31),
         INT8_C( 123),  INT8_C(  18), -INT8_C( 125), -INT8_C( 112),  INT8_C(  92),  INT8_C(  16),  INT8_C(  32),  INT8_C(  23),
        -INT8_C(  76),  INT8_C(  31),  INT8_C( 112),  INT8_C(  45),  INT8_C(  61),  INT8_C( 123), -INT8_C(  43),  INT8_C(  33),
         INT8_C( 103), -INT8_C(  50),  INT8_C(   7), -INT8_C(  55),  INT8_C(  34), -INT8_C( 117), -INT8_C(  45), -INT8_C(  30),
         INT8_C( 107), -INT8_C(  26), -INT8_C( 115), -INT8_C(  20),  INT8_C(  22),  INT8_C( 113),  INT8_C(  11), -INT8_C( 111),
        -INT8_C( 125), -INT8_C( 113),  INT8_C(  34), -INT8_C(  33), -INT8_C(  97),  INT8_C(  66), -INT8_C(   9),  INT8_C(  83),
         INT8_C(  98),  INT8_C( 103),      INT8_MIN, -INT8_C(  97), -INT8_C(  30),  INT8_C(  86), -INT8_C(  64),  INT8_C(  73) },
      {  INT8_C(  36), -INT8_C(  57),  INT8_C(  18),  INT8_C(  70),  INT8_C(  83), -INT8_C(  27),  INT8_C(  40), -INT8_C(  66),
        -INT8_C(  52), -INT8_C(  74), -INT8_C(  86), -INT8_C(  30),  INT8_C(  39), -INT8_C(  74),  INT8_C( 116), -INT8_C(  86),
         INT8_C(  69), -INT8_C( 106), -INT8_C( 119), -INT8_C(  28), -INT8_C(  40),      INT8_MIN,  INT8_C(  55),  INT8_C(  58),
        -INT8_C(  25), -INT8_C(  72), -INT8_C(  39), -INT8_C(  54),  INT8_C(  14), -INT8_C( 103),  INT8_C(  19),  INT8_C(  50),
         INT8_C(  97),  INT8_C(  38),  INT8_C( 121), -INT8_C(  76),  INT8_C(  11), -INT8_C(  95),  INT8_C( 114), -INT8_C(  41),
         INT8_C(  87),  INT8_C(  28), -INT8_C(  70),  INT8_C( 126), -INT8_C(  46),  INT8_C(  46),  INT8_C(  40),  INT8_C(  23),
        -INT8_C(  60), -INT8_C(  78), -INT8_C(   5), -INT8_C( 100),  INT8_C(  50),  INT8_C(  51), -INT8_C(  41),  INT8_C(  26),
        -INT8_C(  21), -INT8_C(  80), -INT8_C(  28), -INT8_C(   7),  INT8_C(  74), -INT8_C(   9),  INT8_C(  43), -INT8_C(  85) },
      { -INT8_C(  64), -INT8_C(  52), -INT8_C(  33), -INT8_C(  74),  INT8_C(  19), -INT8_C(  86), -INT8_C(  85), -INT8_C(  30),
        -INT8_C( 127),  INT8_C(  39),  INT8_C(  48), -INT8_C(  74), -INT8_C(  29),  INT8_C( 116),  INT8_C(  31), -INT8_C(  86),
        -INT8_C(  76), -INT8_C(  25),  INT8_C(  31), -INT8_C(  72),  INT8_C( 112), -INT8_C(  39),  INT8_C(  45), -INT8_C(  54),
         INT8_C(  61),  INT8_C(  14),  INT8_C( 123), -INT8_C( 103), -INT8_C(  43),  INT8_C(  19),  INT8_C(  33),  INT8_C(  50),
         INT8_C( 107),  INT8_C(  87), -INT8_C(  26),  INT8_C(  28), -INT8_C( 115), -INT8_C(  70), -INT8_C(  20),  INT8_C( 126),
         INT8_C(  22), -INT8_C(  46),  INT8_C( 113),  INT8_C(  46),  INT8_C(  11),  INT8_C(  40), -INT8_C( 111),  INT8_C(  23),
         INT8_C(  98), -INT8_C(  21),  INT8_C( 103), -INT8_C(  80),      INT8_MIN, -INT8_C(  28), -INT8_C(  97), -INT8_C(   7),
        -INT8_C(  30),  INT8_C(  74),  INT8_C(  86), -INT8_C(   9), -INT8_C(  64),  INT8_C(  43),  INT8_C(  73), -INT8_C(  85) } },
    { {  INT8_C(  29), -INT8_C(  92),  INT8_C(  95),  INT8_C(  41),  INT8_C(  70), -INT8_C(  47),  INT8_C(   0), -INT8_C(  99),
        -INT8_C(  19), -INT8_C(  70),  INT8_C(  28), -INT8_C(  64), -INT8_C(  24),  INT8_C(  68), -INT8_C(  41), -INT8_C(  84),
        -INT8_C(  10), -INT8_C(  45),  INT8_C(  73),  INT8_C(  41),  INT8_C(   6),  INT8_C(  32),  INT8_C(  67), -INT8_C(  15),
        -INT8_C(  48),  INT8_C(  39), -INT8_C(  22),  INT8_C(  26),  INT8_C(  30),  INT8_C(  21), -INT8_C(  59),  INT8_C(  60),
        -INT8_C(  70),  INT8_C(  36),  INT8_C( 101),  INT8_C(   0), -INT8_C(  11),  INT8_C( 101), -INT8_C(  99), -INT8_C(  29),
         INT8_C(  32), -INT8_C(  71), -INT8_C(  93),  INT8_C(   8), -INT8_C(   2),  INT8_C( 122), -INT8_C(  75), -INT8_C(  12),
         INT8_C(  77), -INT8_C(   2),  INT8_C(  29),  INT8_C(  83),  INT8_C(  30),  INT8_C(  96),  INT8_C(  68), -INT8_C(  18),
        -INT8_C( 121),  INT8_C(  46),  INT8_C(   9), -INT8_C(  90),  INT8_C(  68), -INT8_C(  50), -INT8_C(  30), -INT8_C(   2) },
      { -INT8_C(  13),  INT8_C(  71), -INT8_C(   2), -INT8_C(  24), -INT8_C(  84), -INT8_C( 101), -INT8_C(  53), -INT8_C(  52),
         INT8_C(  85),  INT8_C( 110), -INT8_C(  43),  INT8_C(  83), -INT8_C(  23), -INT8_C( 118),  INT8_C(  71),  INT8_C(  54),
        -INT8_C( 120),  INT8_C( 101), -INT8_C( 118), -INT8_C(  90), -INT8_C(  59), -INT8_C(  50), -INT8_C( 108),  INT8_C(  77),
        -INT8_C(   3), -INT8_C(  99), -INT8_C(  13),  INT8_C(  65),  INT8_C( 108), -INT8_C(  43),  INT8_C(  63),  INT8_C(  95),
         INT8_C(  28),  INT8_C(  61),  INT8_C(  71), -INT8_C(  56), -INT8_C(  40),  INT8_C(  19), -INT8_C( 107),  INT8_C(  45),
        -INT8_C( 127),  INT8_C( 106),      INT8_MIN,  INT8_C( 106), -INT8_C(  12), -INT8_C(  56), -INT8_C(  95),  INT8_C( 124),
         INT8_C(  45),  INT8_C(  43),  INT8_C(  34), -INT8_C(  14), -INT8_C(   7), -INT8_C(  74),  INT8_C(  63), -INT8_C(  10),
         INT8_C(  84),  INT8_C(  50),  INT8_C(  55), -INT8_C(  64),  INT8_C(   7),  INT8_C( 118),  INT8_C(  31),  INT8_C(  35) },
      { -INT8_C(  19),  INT8_C(  85), -INT8_C(  70),  INT8_C( 110),  INT8_C(  28), -INT8_C(  43), -INT8_C(  64),  INT8_C(  83),
        -INT8_C(  24), -INT8_C(  23),  INT8_C(  68), -INT8_C( 118), -INT8_C(  41),  INT8_C(  71), -INT8_C(  84),  INT8_C(  54),
        -INT8_C(  48), -INT8_C(   3),  INT8_C(  39), -INT8_C(  99), -INT8_C(  22), -INT8_C(  13),  INT8_C(  26),  INT8_C(  65),
         INT8_C(  30),  INT8_C( 108),  INT8_C(  21), -INT8_C(  43), -INT8_C(  59),  INT8_C(  63),  INT8_C(  60),  INT8_C(  95),
         INT8_C(  32), -INT8_C( 127), -INT8_C(  71),  INT8_C( 106), -INT8_C(  93),      INT8_MIN,  INT8_C(   8),  INT8_C( 106),
        -INT8_C(   2), -INT8_C(  12),  INT8_C( 122), -INT8_C(  56), -INT8_C(  75), -INT8_C(  95), -INT8_C(  12),  INT8_C( 124),
        -INT8_C( 121),  INT8_C(  84),  INT8_C(  46),  INT8_C(  50),  INT8_C(   9),  INT8_C(  55), -INT8_C(  90), -INT8_C(  64),
         INT8_C(  68),  INT8_C(   7), -INT8_C(  50),  INT8_C( 118), -INT8_C(  30),  INT8_C(  31), -INT8_C(   2),  INT8_C(  35) } },
    { { -INT8_C(  77),  INT8_C( 102), -INT8_C(  20), -INT8_C( 116),  INT8_C( 121), -INT8_C( 127), -INT8_C(  71), -INT8_C(   5),
        -INT8_C(  21),  INT8_C(  58),  INT8_C( 101), -INT8_C(  33),  INT8_C(   2),  INT8_C(   6),  INT8_C(  91),  INT8_C(  47),
         INT8_C(  49),  INT8_C( 125),  INT8_C(  33),  INT8_C(  43),  INT8_C(  51),  INT8_C(  97),  INT8_C(  33), -INT8_C( 121),
        -INT8_C( 109),  INT8_C(  89),  INT8_C(  71), -INT8_C( 101), -INT8_C(  49),  INT8_C( 102), -INT8_C(  66), -INT8_C( 125),
        -INT8_C(  51), -INT8_C(  86),  INT8_C(  15),  INT8_C(  70),  INT8_C(  43), -INT8_C(  56),  INT8_C(  65),  INT8_C(  22),
         INT8_C(   2), -INT8_C(  89), -INT8_C(  11),  INT8_C(   4), -INT8_C(  83),  INT8_C(  80),  INT8_C(  51), -INT8_C(  33),
        -INT8_C(  51),  INT8_C(  85),  INT8_C(  10),  INT8_C(   1), -INT8_C(  74),  INT8_C(  43), -INT8_C( 120),  INT8_C(  73),
        -INT8_C( 124), -INT8_C(  48), -INT8_C(  28),  INT8_C(  84),  INT8_C(  54), -INT8_C(  93), -INT8_C(  41),  INT8_C(   3) },
      {  INT8_C(  77), -INT8_C(  26),  INT8_C(  74),  INT8_C( 121), -INT8_C(  82), -INT8_C( 117), -INT8_C( 113), -INT8_C(  79),
         INT8_C(  50), -INT8_C( 123), -INT8_C(  75), -INT8_C(  32), -INT8_C(  43), -INT8_C(  23), -INT8_C(  65), -INT8_C(  93),
         INT8_C(  62), -INT8_C(  55), -INT8_C(  92), -INT8_C(  12), -INT8_C(  12),  INT8_C(  44),  INT8_C(  61),  INT8_C( 121),
        -INT8_C(   4),  INT8_C(  34), -INT8_C(  51),  INT8_C(  51), -INT8_C(  59), -INT8_C(  92),  INT8_C(  54),  INT8_C(  18),
        -INT8_C( 118),      INT8_MIN, -INT8_C( 117),  INT8_C(  56),  INT8_C(  12),  INT8_C(  27), -INT8_C(  23),  INT8_C(  62),
        -INT8_C(  96), -INT8_C(  97),  INT8_C(  30),  INT8_C( 117), -INT8_C( 120), -INT8_C(  35),  INT8_C(  24), -INT8_C(  58),
        -INT8_C(  90), -INT8_C(  68), -INT8_C(  70), -INT8_C( 101), -INT8_C(  23), -INT8_C(   9),  INT8_C(  20), -INT8_C(  27),
         INT8_C(  25), -INT8_C(  31),  INT8_C(  24), -INT8_C(  34), -INT8_C( 123),  INT8_C(  79), -INT8_C(  15),  INT8_C(  15) },
      { -INT8_C(  21),  INT8_C(  50),  INT8_C(  58), -INT8_C( 123),  INT8_C( 101), -INT8_C(  75), -INT8_C(  33), -INT8_C(  32),
         INT8_C(   2), -INT8_C(  43),  INT8_C(   6), -INT8_C(  23),  INT8_C(  91), -INT8_C(  65),  INT8_C(  47), -INT8_C(  93),
        -INT8_C( 109), -INT8_C(   4),  INT8_C(  89),  INT8_C(  34),  INT8_C(  71), -INT8_C(  51), -INT8_C( 101),  INT8_C(  51),
        -INT8_C(  49), -INT8_C(  59),  INT8_C( 102), -INT8_C(  92), -INT8_C(  66),  INT8_C(  54), -INT8_C( 125),  INT8_C(  18),
         INT8_C(   2), -INT8_C(  96), -INT8_C(  89), -INT8_C(  97), -INT8_C(  11),  INT8_C(  30),  INT8_C(   4),  INT8_C( 117),
        -INT8_C(  83), -INT8_C( 120),  INT8_C(  80), -INT8_C(  35),  INT8_C(  51),  INT8_C(  24), -INT8_C(  33), -INT8_C(  58),
        -INT8_C( 124),  INT8_C(  25), -INT8_C(  48), -INT8_C(  31), -INT8_C(  28),  INT8_C(  24),  INT8_C(  84), -INT8_C(  34),
         INT8_C(  54), -INT8_C( 123), -INT8_C(  93),  INT8_C(  79), -INT8_C(  41), -INT8_C(  15),  INT8_C(   3),  INT8_C(  15) } },
    { { -INT8_C(  49),  INT8_C( 124),  INT8_C(  71), -INT8_C(  37), -INT8_C( 105),  INT8_C(  49),  INT8_C(  26),  INT8_C(  55),
        -INT8_C(  48),  INT8_C(  56), -INT8_C(  83),  INT8_C(  88),  INT8_C(  22), -INT8_C(  59),  INT8_C(  30), -INT8_C(  68),
        -INT8_C( 126), -INT8_C(  40),  INT8_C(  87),  INT8_C( 107), -INT8_C(  49),  INT8_C( 107),  INT8_C(  80), -INT8_C(  23),
         INT8_C(  76),  INT8_C( 105), -INT8_C(  57), -INT8_C(  47), -INT8_C(  72), -INT8_C(  72), -INT8_C(  32), -INT8_C( 121),
         INT8_C(  53),  INT8_C(  40),  INT8_C(  99), -INT8_C(  52),  INT8_C(  89),  INT8_C( 125),  INT8_C(   4),  INT8_C(  41),
        -INT8_C(  75), -INT8_C(  79), -INT8_C( 127), -INT8_C(  53),  INT8_C( 118), -INT8_C(  97), -INT8_C( 120), -INT8_C(   8),
         INT8_C( 119), -INT8_C(  33),  INT8_C(  99),  INT8_C(  70),  INT8_C(  75), -INT8_C(  76),  INT8_C(  47), -INT8_C( 105),
         INT8_C(  29), -INT8_C(   9),  INT8_C( 105), -INT8_C(  43), -INT8_C(  81),  INT8_C(  73),  INT8_C(  92), -INT8_C(  28) },
      {  INT8_C( 113), -INT8_C(  65), -INT8_C(  79), -INT8_C(  54),  INT8_C(  60), -INT8_C(  75), -INT8_C(  13), -INT8_C(  14),
         INT8_C( 102),  INT8_C( 116), -INT8_C(  67), -INT8_C(  36),  INT8_C(  19),  INT8_C(  69), -INT8_C(  43), -INT8_C( 118),
         INT8_C(  37),  INT8_C(  56), -INT8_C(  47),  INT8_C( 112), -INT8_C(  20),  INT8_C(   0),  INT8_C(   7),  INT8_C(   9),
        -INT8_C(   9),  INT8_C( 112), -INT8_C(  34), -INT8_C(  89), -INT8_C(  70),  INT8_C(  59), -INT8_C( 117),  INT8_C(  43),
        -INT8_C(   6),  INT8_C(  60), -INT8_C(  10),  INT8_C(  55), -INT8_C(  15), -INT8_C(  23),  INT8_C(  41),  INT8_C(  87),
         INT8_C(  94), -INT8_C(  26),  INT8_C(  52),  INT8_C( 113),  INT8_C(  44),  INT8_C(   9), -INT8_C(   4),  INT8_C(  81),
         INT8_C(  65), -INT8_C(  51), -INT8_C(  63),  INT8_C(  46), -INT8_C(  51), -INT8_C(  56),  INT8_C(  55), -INT8_C(  59),
         INT8_C(  57),  INT8_C(  22),  INT8_C( 108), -INT8_C(  13),  INT8_C(  81), -INT8_C(   9),  INT8_C(  30),  INT8_C(  75) },
      { -INT8_C(  48),  INT8_C( 102),  INT8_C(  56),  INT8_C( 116), -INT8_C(  83), -INT8_C(  67),  INT8_C(  88), -INT8_C(  36),
         INT8_C(  22),  INT8_C(  19), -INT8_C(  59),  INT8_C(  69),  INT8_C(  30), -INT8_C(  43), -INT8_C(  68), -INT8_C( 118),
         INT8_C(  76), -INT8_C(   9),  INT8_C( 105),  INT8_C( 112), -INT8_C(  57), -INT8_C(  34), -INT8_C(  47), -INT8_C(  89),
        -INT8_C(  72), -INT8_C(  70), -INT8_C(  72),  INT8_C(  59), -INT8_C(  32), -INT8_C( 117), -INT8_C( 121),  INT8_C(  43),
        -INT8_C(  75),  INT8_C(  94), -INT8_C(  79), -INT8_C(  26), -INT8_C( 127),  INT8_C(  52), -INT8_C(  53),  INT8_C( 113),
         INT8_C( 118),  INT8_C(  44), -INT8_C(  97),  INT8_C(   9), -INT8_C( 120), -INT8_C(   4), -INT8_C(   8),  INT8_C(  81),
         INT8_C(  29),  INT8_C(  57), -INT8_C(   9),  INT8_C(  22),  INT8_C( 105),  INT8_C( 108), -INT8_C(  43), -INT8_C(  13),
        -INT8_C(  81),  INT8_C(  81),  INT8_C(  73), -INT8_C(   9),  INT8_C(  92),  INT8_C(  30), -INT8_C(  28),  INT8_C(  75) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i a = simde_mm512_loadu_epi8(test_vec[i].a);
    simde__m512i b = simde_mm512_loadu_epi8(test_vec[i].b);
    simde__m512i r = simde_mm512_unpackhi_epi8(a, b);
    simde_test_x86_assert_equal_i8x64(r, simde_mm512_loadu_epi8(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_mm512_mask_unpackhi_epi8 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const int8_t src[64];
    const simde__mmask64 k;
    const int8_t a[64];
    const int8_t b[64];
    const int8_t r[64];
  } test_vec[] = {
    { { -INT8_C( 106), -INT8_C( 100),  INT8_C(  33), -INT8_C(  32), -INT8_C(  88), -INT8_C(  74), -INT8_C(  39), -INT8_C( 122),
         INT8_C( 117), -INT8_C(   7), -INT8_C(  83),  INT8_C(  69), -INT8_C(  23), -INT8_C(  53), -INT8_C(   6),  INT8_C(  78),
        -INT8_C(  78),  INT8_C(  43), -INT8_C(  27), -INT8_C( 111), -INT8_C( 112),  INT8_C(   0), -INT8_C( 107),  INT8_C(  42),
        -INT8_C(  99), -INT8_C(   2),  INT8_C(  93),  INT8_C(   2),  INT8_C( 121), -INT8_C(  15),  INT8_C(  68), -INT8_C( 112),
        -INT8_C(   9), -INT8_C(  93),  INT8_C(  60), -INT8_C(  87), -INT8_C(  69), -INT8_C(  81), -INT8_C(  55),  INT8_C(  72),
        -INT8_C( 107), -INT8_C(  87), -INT8_C(  93),  INT8_C(  61),  INT8_C(  51), -INT8_C( 103),  INT8_C(  13), -INT8_C(  35),
        -INT8_C(  15), -INT8_C(   3), -INT8_C(   3), -INT8_C(  79),  INT8_C(   0),  INT8_C(  54),  INT8_C(  42),  INT8_C(  31),
         INT8_C(  98),  INT8_C(  29), -INT8_C( 117),  INT8_C(  53),  INT8_C(  47),  INT8_C(  23),  INT8_C(  76), -INT8_C(  12) },
      UINT64_C(15624862570805900888),
      {  INT8_C(  30), -INT8_C(   5),  INT8_C( 117),  INT8_C(  77), -INT8_C( 126), -INT8_C(  33), -INT8_C(  26), -INT8_C(  81),
         INT8_C(   7), -INT8_C(  96), -INT8_C(  38),  INT8_C(  33), -INT8_C(  39),  INT8_C(  47),  INT8_C(  94), -INT8_C(  45),
         INT8_C(   0),  INT8_C(  79),  INT8_C(  78), -INT8_C(  47),  INT8_C( 102), -INT8_C(   3),  INT8_C(  33), -INT8_C(  89),
        -INT8_C( 103),  INT8_C( 103), -INT8_C(  31), -INT8_C(  12), -INT8_C(  97),  INT8_C(  72), -INT8_C(  59), -INT8_C( 105),
        -INT8_C(  58),  INT8_C(  77),  INT8_C(  31),  INT8_C(  42),  INT8_C(  29), -INT8_C(  67),  INT8_C( 120),  INT8_C( 114),
         INT8_C(  81), -INT8_C(  91), -INT8_C(  50),  INT8_C(  76), -INT8_C( 107), -INT8_C(  99), -INT8_C( 105),  INT8_C(  51),
         INT8_C( 113), -INT8_C(  68),  INT8_C(  32),  INT8_C(  12), -INT8_C( 106),  INT8_C(  42),  INT8_C(   5), -INT8_C(   2),
        -INT8_C(  76),  INT8_C(  39), -INT8_C( 124), -INT8_C( 100),  INT8_C(  99), -INT8_C(  71), -INT8_C(  14), -INT8_C(  46) },
      { -INT8_C(  74),  INT8_C(  38),  INT8_C(  81),  INT8_C(  18), -INT8_C(  32),  INT8_C(   5), -INT8_C(  64),  INT8_C(  28),
        -INT8_C(  35),  INT8_C(   6),  INT8_C(  41),  INT8_C( 101),  INT8_C(  71), -INT8_C( 120),  INT8_C( 104),  INT8_C(   1),
        -INT8_C(  35),  INT8_C(   0), -INT8_C(  21),  INT8_C(  41), -INT8_C(  99), -INT8_C(  25), -INT8_C(  85), -INT8_C(  94),
         INT8_C( 107),  INT8_C( 125),  INT8_C(  58),  INT8_C(  88),  INT8_C(  88),  INT8_C(  93),  INT8_C(  70),  INT8_C(  24),
        -INT8_C( 126), -INT8_C(  99),  INT8_C(   8),  INT8_C(  47), -INT8_C( 114), -INT8_C(  79),  INT8_C(  82),  INT8_C(   8),
        -INT8_C( 122), -INT8_C(  63), -INT8_C(  54), -INT8_C(  81), -INT8_C(  69),  INT8_C(  37), -INT8_C( 117),  INT8_C( 124),
        -INT8_C(  28),  INT8_C( 111),  INT8_C(  74), -INT8_C( 123), -INT8_C(  45), -INT8_C(  69),  INT8_C(  54), -INT8_C( 102),
        -INT8_C(  11), -INT8_C(  44), -INT8_C(  72), -INT8_C( 104),  INT8_C(  88),  INT8_C(  45),  INT8_C(  75),  INT8_C( 118) },
      { -INT8_C( 106), -INT8_C( 100),  INT8_C(  33),  INT8_C(   6), -INT8_C(  38), -INT8_C(  74),  INT8_C(  33), -INT8_C( 122),
         INT8_C( 117),  INT8_C(  71),  INT8_C(  47),  INT8_C(  69),  INT8_C(  94),  INT8_C( 104), -INT8_C(   6),  INT8_C(   1),
        -INT8_C(  78),  INT8_C( 107),  INT8_C( 103),  INT8_C( 125), -INT8_C( 112),  INT8_C(  58), -INT8_C( 107),  INT8_C(  42),
        -INT8_C(  97), -INT8_C(   2),  INT8_C(  72),  INT8_C(  93), -INT8_C(  59), -INT8_C(  15), -INT8_C( 105), -INT8_C( 112),
         INT8_C(  81), -INT8_C(  93),  INT8_C(  60), -INT8_C(  63), -INT8_C(  50), -INT8_C(  54), -INT8_C(  55), -INT8_C(  81),
        -INT8_C( 107), -INT8_C(  87), -INT8_C(  93),  INT8_C(  37),  INT8_C(  51), -INT8_C( 117),  INT8_C(  13),  INT8_C( 124),
        -INT8_C(  15), -INT8_C(  11),  INT8_C(  39), -INT8_C(  79), -INT8_C( 124),  INT8_C(  54), -INT8_C( 100), -INT8_C( 104),
         INT8_C(  98),  INT8_C(  29), -INT8_C( 117),  INT8_C(  45), -INT8_C(  14),  INT8_C(  23), -INT8_C(  46),  INT8_C( 118) } },
    { {  INT8_C(  46), -INT8_C(  20),  INT8_C(   7),  INT8_C(  75), -INT8_C(  99), -INT8_C(  90), -INT8_C(  83), -INT8_C(  45),
         INT8_C(  17), -INT8_C(   2), -INT8_C( 126), -INT8_C( 107),  INT8_C( 107),  INT8_C(  96), -INT8_C(  29), -INT8_C(  44),
         INT8_C(  11), -INT8_C(  50), -INT8_C(  59), -INT8_C(  64), -INT8_C(  62),  INT8_C(  41), -INT8_C(  84), -INT8_C( 104),
         INT8_C(  76),  INT8_C(  87), -INT8_C(  90),  INT8_C(  34),  INT8_C(  86),  INT8_C(  54),  INT8_C(  40), -INT8_C(  41),
         INT8_C(  23), -INT8_C(  34),  INT8_C( 104),  INT8_C( 120),  INT8_C(  60),  INT8_C(  90),  INT8_C(  69),  INT8_C(  99),
         INT8_C(  27), -INT8_C(  72),  INT8_C(  24), -INT8_C( 117),  INT8_C(  20), -INT8_C(  18),  INT8_C(  28), -INT8_C( 108),
         INT8_C(  70),  INT8_C(  42), -INT8_C(  34), -INT8_C(  53), -INT8_C( 115),  INT8_C(  60),  INT8_C(  87), -INT8_C(  53),
        -INT8_C(  50), -INT8_C(   4), -INT8_C(  99),  INT8_C(  15), -INT8_C( 103),  INT8_C( 124),  INT8_C(  16), -INT8_C(  50) },
      UINT64_C(11122572813131943228),
      { -INT8_C(  61), -INT8_C(  92),  INT8_C(  99),  INT8_C(   1), -INT8_C(  86),  INT8_C(  87), -INT8_C(  83),      INT8_MAX,
         INT8_C( 121), -INT8_C( 102),  INT8_C(  94),  INT8_C(  71), -INT8_C(  84),  INT8_C(  52), -INT8_C(  49), -INT8_C(  81),
        -INT8_C(  60),  INT8_C(  32),  INT8_C(  47), -INT8_C( 126), -INT8_C(  10), -INT8_C(  86), -INT8_C(  86),  INT8_C(  68),
         INT8_C(  59), -INT8_C( 120),  INT8_C(  47),  INT8_C(  89),  INT8_C(  69), -INT8_C( 100),  INT8_C(  95),  INT8_C(  47),
        -INT8_C(   3), -INT8_C(  91), -INT8_C( 108),  INT8_C(  97), -INT8_C( 104), -INT8_C( 123), -INT8_C(  34),  INT8_C(  79),
        -INT8_C(  26), -INT8_C(  38),  INT8_C(  80),  INT8_C(  23),  INT8_C(  52),  INT8_C(  86),  INT8_C( 124), -INT8_C(  73),
         INT8_C(  41),  INT8_C(  30), -INT8_C(  39),  INT8_C(  33),  INT8_C(  89), -INT8_C(  99), -INT8_C(  59), -INT8_C( 107),
        -INT8_C(  35), -INT8_C( 100), -INT8_C(  22),  INT8_C(  55), -INT8_C(  36),  INT8_C(  78),  INT8_C(   6),  INT8_C(  70) },
      { -INT8_C( 104), -INT8_C(  73),  INT8_C(  61),  INT8_C(  62),  INT8_C(   2),  INT8_C(  25), -INT8_C( 112),  INT8_C(  26),
        -INT8_C(  28), -INT8_C(  32),  INT8_C( 106),  INT8_C( 106),  INT8_C(  53), -INT8_C(  87), -INT8_C(   8),  INT8_C(  40),
        -INT8_C(  72),  INT8_C( 112),  INT8_C(  40),  INT8_C(  53),  INT8_C(  15), -INT8_C( 103),  INT8_C(  80), -INT8_C(  22),
        -INT8_C(  34), -INT8_C(  21), -INT8_C(  19), -INT8_C(  98), -INT8_C(  13), -INT8_C(  93),  INT8_C(  53), -INT8_C( 112),
        -INT8_C(  69),  INT8_C(  80),  INT8_C(  77), -INT8_C(  12),  INT8_C(  30),  INT8_C(  79), -INT8_C(   9),  INT8_C( 119),
         INT8_C(  54), -INT8_C( 111),  INT8_C( 113), -INT8_C(  99), -INT8_C( 118),  INT8_C(  39), -INT8_C( 101),  INT8_C(   8),
         INT8_C(  18), -INT8_C(  90), -INT8_C(  43), -INT8_C( 107), -INT8_C( 113), -INT8_C(  15), -INT8_C( 117), -INT8_C(  61),
        -INT8_C(  87), -INT8_C(  56), -INT8_C(  70),  INT8_C(  55),  INT8_C(  80),  INT8_C( 119), -INT8_C(  84),  INT8_C(  61) },
      {  INT8_C(  46), -INT8_C(  20), -INT8_C( 102), -INT8_C(  32),  INT8_C(  94),  INT8_C( 106), -INT8_C(  83), -INT8_C(  45),
        -INT8_C(  84), -INT8_C(   2),  INT8_C(  52), -INT8_C(  87),  INT8_C( 107),  INT8_C(  96), -INT8_C(  29),  INT8_C(  40),
         INT8_C(  59), -INT8_C(  50), -INT8_C( 120), -INT8_C(  64), -INT8_C(  62), -INT8_C(  19), -INT8_C(  84), -INT8_C( 104),
         INT8_C(  69), -INT8_C(  13), -INT8_C(  90), -INT8_C(  93),  INT8_C(  86),  INT8_C(  53),  INT8_C(  40), -INT8_C(  41),
        -INT8_C(  26),  INT8_C(  54),  INT8_C( 104), -INT8_C( 111),  INT8_C(  60),  INT8_C(  90),  INT8_C(  69),  INT8_C(  99),
         INT8_C(  52), -INT8_C(  72),  INT8_C(  24), -INT8_C( 117),  INT8_C( 124), -INT8_C(  18), -INT8_C(  73), -INT8_C( 108),
        -INT8_C(  35), -INT8_C(  87), -INT8_C(  34), -INT8_C(  56), -INT8_C(  22),  INT8_C(  60),  INT8_C(  55), -INT8_C(  53),
        -INT8_C(  50),  INT8_C(  80), -INT8_C(  99),  INT8_C( 119),  INT8_C(   6),  INT8_C( 124),  INT8_C(  16),  INT8_C(  61) } },
    { {  INT8_C(  57),  INT8_C(  66),  INT8_C(   7), -INT8_C(  33),  INT8_C(  19),  INT8_C(  42), -INT8_C(  34), -INT8_C( 120),
         INT8_C(  31), -INT8_C( 107), -INT8_C(  91), -INT8_C(  52), -INT8_C( 123),  INT8_C(   9), -INT8_C(  10), -INT8_C( 125),
         INT8_C(  59), -INT8_C(  90), -INT8_C( 126), -INT8_C(  74),  INT8_C(  18),  INT8_C( 118), -INT8_C(  15), -INT8_C(  37),
        -INT8_C( 108), -INT8_C(  83), -INT8_C(  88), -INT8_C(  82),  INT8_C(  10),  INT8_C(  74), -INT8_C(  99), -INT8_C(  71),
        -INT8_C(  85),  INT8_C( 125), -INT8_C(  66),  INT8_C(  72), -INT8_C(  79), -INT8_C( 111),  INT8_C( 117), -INT8_C(  58),
        -INT8_C( 109),  INT8_C(  99), -INT8_C( 116), -INT8_C( 114), -INT8_C(  21), -INT8_C(  36),  INT8_C(  26), -INT8_C(  28),
        -INT8_C(  80), -INT8_C(  29), -INT8_C(  80),  INT8_C(  51), -INT8_C( 106),  INT8_C(  21), -INT8_C(  67),  INT8_C(  85),
         INT8_C( 124),  INT8_C( 114), -INT8_C(  34), -INT8_C(  16),  INT8_C(  17),  INT8_C( 107),  INT8_C( 125),  INT8_C(  65) },
      UINT64_C( 4070353243830355645),
      { -INT8_C(  52), -INT8_C( 103),  INT8_C(  13), -INT8_C(  64),  INT8_C( 105), -INT8_C(  43),  INT8_C( 104),  INT8_C(  57),
         INT8_C(  85),  INT8_C(  44), -INT8_C( 108),  INT8_C(  23),  INT8_C(   1),  INT8_C(  82), -INT8_C(  12),  INT8_C( 126),
        -INT8_C(  73), -INT8_C(  87), -INT8_C(  18), -INT8_C(  37),  INT8_C(  29),  INT8_C(  12), -INT8_C(  88), -INT8_C(  60),
        -INT8_C(  10), -INT8_C(  33), -INT8_C(  62),  INT8_C(  50),  INT8_C( 108),  INT8_C(  35),  INT8_C(   6), -INT8_C(  69),
        -INT8_C(  83),  INT8_C(  42),  INT8_C( 108), -INT8_C(   2),  INT8_C(  89),  INT8_C(  93), -INT8_C(  99), -INT8_C(  42),
        -INT8_C(  44),  INT8_C(  28), -INT8_C(  26),  INT8_C( 113),  INT8_C(  49),  INT8_C( 106), -INT8_C(  10),  INT8_C(  60),
         INT8_C(  30),      INT8_MIN,  INT8_C(  79), -INT8_C( 101),  INT8_C(  46), -INT8_C(  45),  INT8_C(  35), -INT8_C(  83),
        -INT8_C(  80),  INT8_C(  25),  INT8_C(  22),  INT8_C(  92), -INT8_C(  89),  INT8_C(  24), -INT8_C(  64), -INT8_C(  71) },
      {  INT8_C( 121), -INT8_C(   3), -INT8_C(  12),  INT8_C(  68),  INT8_C(  56),  INT8_C( 101),  INT8_C(  44),  INT8_C(   0),
         INT8_C( 109), -INT8_C(  56),  INT8_C(  67),  INT8_C( 125), -INT8_C(  23),  INT8_C(  13),  INT8_C(  34), -INT8_C(  41),
         INT8_C(  25),  INT8_C(  32), -INT8_C(  92), -INT8_C(  31), -INT8_C(  62),  INT8_C(  80),  INT8_C(  27),  INT8_C(  77),
         INT8_C(   3), -INT8_C(  70), -INT8_C(  41),  INT8_C(  38),  INT8_C(  36), -INT8_C(  38), -INT8_C(   3), -INT8_C(  33),
        -INT8_C(  93),  INT8_C(   3),  INT8_C(   4), -INT8_C( 100),  INT8_C(  19),      INT8_MAX, -INT8_C(  43),  INT8_C( 113),
         INT8_C(  20),  INT8_C( 108), -INT8_C(  34), -INT8_C(  47),  INT8_C(  81), -INT8_C( 116),  INT8_C(  24),  INT8_C(   1),
        -INT8_C(  33), -INT8_C(  93), -INT8_C(  37), -INT8_C(  97),  INT8_C(  54),  INT8_C(  35), -INT8_C( 108),  INT8_C( 101),
         INT8_C(  93),  INT8_C(  30),  INT8_C(  76),  INT8_C(   8),  INT8_C(  56),  INT8_C( 111), -INT8_C( 125), -INT8_C( 111) },
      {  INT8_C(  85),  INT8_C(  66),  INT8_C(  44), -INT8_C(  56), -INT8_C( 108),  INT8_C(  67), -INT8_C(  34),  INT8_C( 125),
         INT8_C(  31), -INT8_C(  23),  INT8_C(  82), -INT8_C(  52), -INT8_C( 123),  INT8_C(   9), -INT8_C(  10), -INT8_C( 125),
         INT8_C(  59),  INT8_C(   3), -INT8_C(  33), -INT8_C(  70), -INT8_C(  62),  INT8_C( 118),  INT8_C(  50),  INT8_C(  38),
        -INT8_C( 108), -INT8_C(  83), -INT8_C(  88), -INT8_C(  38),  INT8_C(  10), -INT8_C(   3), -INT8_C(  99), -INT8_C(  33),
        -INT8_C(  44),  INT8_C( 125),  INT8_C(  28),  INT8_C(  72), -INT8_C(  26), -INT8_C(  34),  INT8_C( 117), -INT8_C(  47),
        -INT8_C( 109),  INT8_C(  99),  INT8_C( 106), -INT8_C( 116), -INT8_C(  21), -INT8_C(  36),  INT8_C(  60),  INT8_C(   1),
        -INT8_C(  80), -INT8_C(  29),  INT8_C(  25),  INT8_C(  30),  INT8_C(  22),  INT8_C(  76),  INT8_C(  92),  INT8_C(  85),
         INT8_C( 124),  INT8_C( 114), -INT8_C(  34),  INT8_C( 111), -INT8_C(  64), -INT8_C( 125),  INT8_C( 125),  INT8_C(  65) } },
    { { -INT8_C(  78), -INT8_C(  78),  INT8_C(  92), -INT8_C(   8),  INT8_C(  88),  INT8_C(  74),  INT8_C(  77),  INT8_C(  10),
        -INT8_C( 126),  INT8_C(  59), -INT8_C(  38), -INT8_C( 120), -INT8_C( 111),  INT8_C(  21),  INT8_C( 113),  INT8_C(  88),
        -INT8_C(  25), -INT8_C( 110),  INT8_C(  95), -INT8_C(  64), -INT8_C(  23),  INT8_C( 123),  INT8_C(  73),  INT8_C(   9),
        -INT8_C(  22),  INT8_C( 105),  INT8_C(   0), -INT8_C( 110),  INT8_C(  81), -INT8_C(  55),  INT8_C( 115), -INT8_C( 125),
         INT8_C( 102),  INT8_C(  55),  INT8_C(  81), -INT8_C(  62), -INT8_C(  34), -INT8_C( 115),  INT8_C(  49), -INT8_C(  44),
         INT8_C(  49),  INT8_C(  38), -INT8_C(  88), -INT8_C(   4), -INT8_C(  34),  INT8_C(  95),  INT8_C(   7), -INT8_C(  38),
         INT8_C(  78), -INT8_C(  13),  INT8_C(  60), -INT8_C(  37), -INT8_C(  71),  INT8_C(  26),  INT8_C(  33),  INT8_C(  17),
         INT8_C(  68), -INT8_C(  74), -INT8_C(  19),  INT8_C( 100),  INT8_C(   2),      INT8_MIN,  INT8_C(  62), -INT8_C(  16) },
      UINT64_C(16768031963675583631),
      { -INT8_C(  80), -INT8_C(   6), -INT8_C(  75),  INT8_C(  96), -INT8_C(  72),  INT8_C(  35), -INT8_C(   6), -INT8_C(  47),
        -INT8_C( 121), -INT8_C(  44),      INT8_MIN,  INT8_C(  39), -INT8_C( 126), -INT8_C( 112), -INT8_C( 106),  INT8_C( 107),
         INT8_C(  87), -INT8_C(  10), -INT8_C(  43), -INT8_C( 107),  INT8_C(   6), -INT8_C(   2), -INT8_C(  18), -INT8_C(   1),
         INT8_C(  10), -INT8_C(  59),  INT8_C(  42), -INT8_C(  82),  INT8_C(  49),  INT8_C( 114),  INT8_C(  34),  INT8_C(  61),
        -INT8_C(   5), -INT8_C(   6),  INT8_C(  97), -INT8_C(   1),  INT8_C(  61), -INT8_C(  33),  INT8_C(  42),  INT8_C(  55),
        -INT8_C( 101), -INT8_C( 103), -INT8_C( 100), -INT8_C(  71), -INT8_C(  83),  INT8_C(   3),  INT8_C(  95),  INT8_C(  56),
        -INT8_C(  75),  INT8_C( 108),  INT8_C(   5),  INT8_C(  58),  INT8_C(  12),  INT8_C( 116),  INT8_C(  39), -INT8_C(  19),
         INT8_C(  13), -INT8_C(  21),  INT8_C( 124),  INT8_C(  70),  INT8_C(  42),  INT8_C(  90), -INT8_C(  77),  INT8_C( 116) },
      {  INT8_C(   5), -INT8_C(  57),  INT8_C(  73),  INT8_C(  26), -INT8_C(  34), -INT8_C(  20),  INT8_C(  30),  INT8_C(  39),
         INT8_C(   4), -INT8_C(  63),  INT8_C( 110),  INT8_C(  63),  INT8_C(  51),  INT8_C(  92),  INT8_C(  87),      INT8_MIN,
         INT8_C( 117),  INT8_C( 121),  INT8_C(  31),  INT8_C(   9),  INT8_C(  66),  INT8_C(  88), -INT8_C(   3), -INT8_C(  89),
         INT8_C(  31),  INT8_C(  42), -INT8_C(  85),  INT8_C(  48),  INT8_C(  32), -INT8_C(   9),  INT8_C(  41),  INT8_C(  53),
         INT8_C( 100),  INT8_C(  50), -INT8_C(   8), -INT8_C(  87),  INT8_C(   3), -INT8_C( 116),  INT8_C(  56), -INT8_C(  45),
         INT8_C( 110), -INT8_C(  10),  INT8_C(  27),  INT8_C(  10), -INT8_C(  52),      INT8_MAX, -INT8_C(  91),  INT8_C( 126),
         INT8_C( 112), -INT8_C(  40),  INT8_C(  99), -INT8_C(  19),  INT8_C( 103), -INT8_C( 118), -INT8_C(  19), -INT8_C(  99),
         INT8_C( 115),  INT8_C(  73),  INT8_C(  18),  INT8_C(  45),  INT8_C(  80), -INT8_C(  46),  INT8_C(  26),  INT8_C(  67) },
      { -INT8_C( 121),  INT8_C(   4), -INT8_C(  44), -INT8_C(  63),  INT8_C(  88),  INT8_C(  74),  INT8_C(  77),  INT8_C(  63),
        -INT8_C( 126),  INT8_C(  59), -INT8_C( 112), -INT8_C( 120), -INT8_C( 111),  INT8_C(  87),  INT8_C( 107),  INT8_C(  88),
         INT8_C(  10),  INT8_C(  31), -INT8_C(  59), -INT8_C(  64), -INT8_C(  23),  INT8_C( 123), -INT8_C(  82),  INT8_C(   9),
         INT8_C(  49),  INT8_C( 105),  INT8_C(   0), -INT8_C(   9),  INT8_C(  81),  INT8_C(  41),  INT8_C(  61),  INT8_C(  53),
         INT8_C( 102),  INT8_C( 110),  INT8_C(  81), -INT8_C(  10), -INT8_C( 100),  INT8_C(  27),  INT8_C(  49), -INT8_C(  44),
         INT8_C(  49),  INT8_C(  38),  INT8_C(   3), -INT8_C(   4), -INT8_C(  34),  INT8_C(  95),  INT8_C(   7), -INT8_C(  38),
         INT8_C(  78), -INT8_C(  13), -INT8_C(  21), -INT8_C(  37),  INT8_C( 124),  INT8_C(  18),  INT8_C(  33),  INT8_C(  45),
         INT8_C(  68), -INT8_C(  74), -INT8_C(  19), -INT8_C(  46),  INT8_C(   2),  INT8_C(  26),  INT8_C( 116),  INT8_C(  67) } },
    { { -INT8_C(   6),  INT8_C(  99),  INT8_C(  69), -INT8_C(  11),  INT8_C(  48),  INT8_C(  50),  INT8_C(  13),  INT8_C( 118),
        -INT8_C(  37), -INT8_C(  93),  INT8_C(  79), -INT8_C(  88),  INT8_C( 103), -INT8_C( 120),  INT8_C(  11),  INT8_C(  63),
         INT8_C(  61),  INT8_C(  53),      INT8_MIN, -INT8_C(  13),  INT8_C( 114),  INT8_C(   7), -INT8_C(  35), -INT8_C(  21),
         INT8_C( 109), -INT8_C(  36), -INT8_C(  54), -INT8_C( 122),  INT8_C(  45),  INT8_C(  53), -INT8_C(  79), -INT8_C(  74),
         INT8_C(  15), -INT8_C(  36),  INT8_C( 104),  INT8_C(  74),  INT8_C(  44),  INT8_C(  10),  INT8_C(  47), -INT8_C( 114),
        -INT8_C(  92),  INT8_C(  51), -INT8_C(  68), -INT8_C(  41),  INT8_C(   9),  INT8_C(   7),  INT8_C( 126),  INT8_C(  13),
         INT8_C(  20),  INT8_C(  75), -INT8_C(  74), -INT8_C(  66), -INT8_C(  70), -INT8_C(  29), -INT8_C( 110), -INT8_C(  92),
        -INT8_C(  31),  INT8_C(   1), -INT8_C(  21),  INT8_C( 109),  INT8_C(  13), -INT8_C(  10),  INT8_C( 107),  INT8_C(  88) },
      UINT64_C(13330734482189192426),
      { -INT8_C(  73), -INT8_C(  14),  INT8_C(  61),  INT8_C(  24), -INT8_C(  21), -INT8_C(  22), -INT8_C(  37),  INT8_C(   0),
        -INT8_C(  20),  INT8_C(  40),  INT8_C( 124), -INT8_C(  65), -INT8_C(  26),  INT8_C(  67),  INT8_C(  25),  INT8_C(  89),
        -INT8_C(  71),  INT8_C(  28),  INT8_C( 110),  INT8_C( 105), -INT8_C(  45), -INT8_C(   4), -INT8_C(  55),  INT8_C(  66),
         INT8_C(  67), -INT8_C(  99), -INT8_C(  87), -INT8_C(  63), -INT8_C(  99),  INT8_C(  44),  INT8_C(   5),  INT8_C(  54),
         INT8_C( 118), -INT8_C(  35), -INT8_C(  54),  INT8_C(  86),  INT8_C( 104), -INT8_C( 106), -INT8_C(  43), -INT8_C(  38),
        -INT8_C(   6), -INT8_C(  80),  INT8_C(  37), -INT8_C( 102),  INT8_C( 103),  INT8_C(  20), -INT8_C(  62), -INT8_C(  23),
        -INT8_C(  79),  INT8_C(  12), -INT8_C(  14), -INT8_C(  23),  INT8_C(  29),  INT8_C(  40),  INT8_C(  47),  INT8_C(  89),
        -INT8_C(  44), -INT8_C(  21), -INT8_C(  67), -INT8_C(   8), -INT8_C(  33), -INT8_C(  40), -INT8_C(  58), -INT8_C(  41) },
      {  INT8_C( 108), -INT8_C(  40),  INT8_C(  19), -INT8_C(  19), -INT8_C(  67), -INT8_C(  39),  INT8_C(  59),  INT8_C( 125),
        -INT8_C(  40), -INT8_C( 127), -INT8_C(  91), -INT8_C(  96), -INT8_C(  49),  INT8_C(  79), -INT8_C(  76), -INT8_C(  26),
         INT8_C(  71),  INT8_C(  86), -INT8_C(  83), -INT8_C(  32),  INT8_C(  37),  INT8_C(  76),  INT8_C(  40), -INT8_C( 125),
        -INT8_C(  91), -INT8_C( 116),  INT8_C(  43), -INT8_C(  35), -INT8_C( 102), -INT8_C(   6),  INT8_C( 105),  INT8_C(  19),
        -INT8_C(   2),  INT8_C(  36),  INT8_C( 119),  INT8_C(   5), -INT8_C(  53),  INT8_C(  84),  INT8_C( 126), -INT8_C(  50),
         INT8_C(  38),  INT8_C(   9),  INT8_C(  62), -INT8_C(  13),  INT8_C(   2),  INT8_C(  62),  INT8_C(  48), -INT8_C( 101),
        -INT8_C(  30), -INT8_C( 120), -INT8_C( 107), -INT8_C(  72), -INT8_C(  75),  INT8_C(  93), -INT8_C(  13), -INT8_C(  48),
        -INT8_C(  32),  INT8_C(  33), -INT8_C(  72), -INT8_C(  78),      INT8_MAX,  INT8_C(  49), -INT8_C(  57), -INT8_C( 117) },
      { -INT8_C(   6), -INT8_C(  40),  INT8_C(  69), -INT8_C( 127),  INT8_C(  48), -INT8_C(  91), -INT8_C(  65), -INT8_C(  96),
        -INT8_C(  37), -INT8_C(  93),  INT8_C(  67),  INT8_C(  79),  INT8_C( 103), -INT8_C( 120),  INT8_C(  11),  INT8_C(  63),
         INT8_C(  61),  INT8_C(  53),      INT8_MIN, -INT8_C(  13), -INT8_C(  87),  INT8_C(  43), -INT8_C(  63), -INT8_C(  35),
        -INT8_C(  99), -INT8_C(  36),  INT8_C(  44), -INT8_C(   6),  INT8_C(   5),  INT8_C(  53),  INT8_C(  54),  INT8_C(  19),
        -INT8_C(   6), -INT8_C(  36),  INT8_C( 104),  INT8_C(  74),  INT8_C(  44),  INT8_C(  62), -INT8_C( 102), -INT8_C( 114),
        -INT8_C(  92),  INT8_C(  51), -INT8_C(  68),  INT8_C(  62),  INT8_C(   9),  INT8_C(   7), -INT8_C(  23),  INT8_C(  13),
         INT8_C(  20),  INT8_C(  75), -INT8_C(  74), -INT8_C(  66), -INT8_C(  70), -INT8_C(  29), -INT8_C( 110), -INT8_C(  92),
        -INT8_C(  33),  INT8_C(   1), -INT8_C(  21),  INT8_C(  49), -INT8_C(  58), -INT8_C(  57),  INT8_C( 107), -INT8_C( 117) } },
    { { -INT8_C(  98),  INT8_C(  16), -INT8_C(  91), -INT8_C(  65), -INT8_C(  53), -INT8_C(  32), -INT8_C(   3), -INT8_C(  20),
         INT8_C(  40),  INT8_C( 116), -INT8_C(  14),  INT8_C( 122), -INT8_C(  42), -INT8_C(  14),  INT8_C( 126),  INT8_C(  87),
        -INT8_C(  95), -INT8_C(  19),  INT8_C(  15),  INT8_C(  44), -INT8_C( 119),  INT8_C(  28),  INT8_C(  34), -INT8_C(  14),
        -INT8_C(  81), -INT8_C( 117), -INT8_C(  78),  INT8_C(  30),  INT8_C(  59), -INT8_C(  34),  INT8_C(  27), -INT8_C(  49),
         INT8_C( 109),  INT8_C(  45), -INT8_C( 105),  INT8_C(  15),  INT8_C(  63), -INT8_C( 106),  INT8_C(  73), -INT8_C(  59),
         INT8_C( 116), -INT8_C(  67),  INT8_C(  55), -INT8_C(  98), -INT8_C( 120), -INT8_C(  42), -INT8_C(  23),  INT8_C(  92),
        -INT8_C(  22), -INT8_C(  88),  INT8_C( 117),  INT8_C(  55), -INT8_C(  85),  INT8_C(  61), -INT8_C(  96), -INT8_C(  77),
         INT8_C(   9),  INT8_C(  60), -INT8_C(  42),  INT8_C(  46), -INT8_C(  84),  INT8_C(  11), -INT8_C(  75),  INT8_C(  97) },
      UINT64_C( 9673742337990292340),
      { -INT8_C( 113), -INT8_C(  54), -INT8_C(  59), -INT8_C(  15),  INT8_C(   6), -INT8_C(  37),  INT8_C( 124),  INT8_C( 117),
         INT8_C(  92), -INT8_C(  50),  INT8_C(  88),  INT8_C(  41), -INT8_C(  60), -INT8_C(  15), -INT8_C(  35), -INT8_C( 112),
        -INT8_C(  88), -INT8_C(  94),  INT8_C(  20), -INT8_C( 109),  INT8_C(  95),  INT8_C(  28),  INT8_C(  30), -INT8_C( 113),
         INT8_C(   1),  INT8_C( 120), -INT8_C(  73),  INT8_C(  16), -INT8_C( 100), -INT8_C(  68),  INT8_C( 117),  INT8_C( 120),
         INT8_C( 105),  INT8_C(  70),  INT8_C( 110), -INT8_C( 118),  INT8_C(  61),  INT8_C(  81),  INT8_C(   8), -INT8_C(  53),
         INT8_C(  39), -INT8_C(  49),  INT8_C( 123),  INT8_C(   7),  INT8_C(  12),  INT8_C(  78),  INT8_C(  89),  INT8_C( 101),
         INT8_C(  81),  INT8_C(  38), -INT8_C(  68),  INT8_C( 108), -INT8_C(   2), -INT8_C(  89), -INT8_C(  48), -INT8_C(  46),
        -INT8_C(  15), -INT8_C(  13), -INT8_C(  11),  INT8_C(  91),  INT8_C(  52),  INT8_C(  31),  INT8_C( 117),  INT8_C(  64) },
      {  INT8_C( 104),  INT8_C(  77), -INT8_C(   2),  INT8_C(  73), -INT8_C(   7), -INT8_C(  76), -INT8_C(  99),  INT8_C(  17),
        -INT8_C( 117),  INT8_C(  50),  INT8_C(   6), -INT8_C(  29), -INT8_C( 104), -INT8_C(  83), -INT8_C(  39), -INT8_C( 104),
         INT8_C(  42),  INT8_C(  31),  INT8_C(  17),  INT8_C(   5), -INT8_C( 116),  INT8_C( 124),  INT8_C(  66),  INT8_C(  59),
         INT8_C( 126),  INT8_C(  89), -INT8_C(  27),  INT8_C(  62), -INT8_C( 125), -INT8_C(  87),  INT8_C( 124),  INT8_C( 108),
        -INT8_C( 120),  INT8_C(  47),  INT8_C(   9),  INT8_C(  23), -INT8_C( 107),  INT8_C(  93), -INT8_C(  64), -INT8_C(  36),
        -INT8_C( 119), -INT8_C(  35), -INT8_C( 114), -INT8_C(  75), -INT8_C(  50),  INT8_C(  41), -INT8_C(  70),  INT8_C(  98),
         INT8_C(  72),  INT8_C( 115),  INT8_C(  21),  INT8_C(   8), -INT8_C(  16), -INT8_C( 108), -INT8_C(  25), -INT8_C(  92),
        -INT8_C(  14),  INT8_C(  73), -INT8_C(  23),  INT8_C(   8),  INT8_C(  53), -INT8_C(  75), -INT8_C(   5), -INT8_C(  69) },
      { -INT8_C(  98),  INT8_C(  16), -INT8_C(  50), -INT8_C(  65),  INT8_C(  88),  INT8_C(   6),  INT8_C(  41), -INT8_C(  20),
        -INT8_C(  60), -INT8_C( 104), -INT8_C(  14),  INT8_C( 122), -INT8_C(  35), -INT8_C(  39), -INT8_C( 112),  INT8_C(  87),
         INT8_C(   1), -INT8_C(  19),  INT8_C(  15),  INT8_C(  44), -INT8_C(  73),  INT8_C(  28),  INT8_C(  34),  INT8_C(  62),
        -INT8_C(  81), -INT8_C( 117), -INT8_C(  78), -INT8_C(  87),  INT8_C( 117), -INT8_C(  34),  INT8_C(  27), -INT8_C(  49),
         INT8_C(  39), -INT8_C( 119), -INT8_C(  49),  INT8_C(  15),  INT8_C(  63), -INT8_C( 114),  INT8_C(   7), -INT8_C(  59),
         INT8_C(  12), -INT8_C(  67),  INT8_C(  55),  INT8_C(  41), -INT8_C( 120), -INT8_C(  42), -INT8_C(  23),  INT8_C(  92),
        -INT8_C(  22), -INT8_C(  88),  INT8_C( 117),  INT8_C(  55), -INT8_C(  85),  INT8_C(  61),  INT8_C(  91), -INT8_C(  77),
         INT8_C(   9),  INT8_C(  53),  INT8_C(  31),  INT8_C(  46), -INT8_C(  84),  INT8_C(  11), -INT8_C(  75), -INT8_C(  69) } },
    { {  INT8_C( 112),      INT8_MAX,  INT8_C(  23),  INT8_C( 112), -INT8_C(  17),  INT8_C(  98),  INT8_C(  83), -INT8_C(  35),
        -INT8_C(  82),  INT8_C(  91), -INT8_C(   2),  INT8_C(  65), -INT8_C(  84), -INT8_C(  88), -INT8_C(  89), -INT8_C( 115),
         INT8_C(  48),  INT8_C( 117), -INT8_C( 105), -INT8_C(  59),  INT8_C( 116), -INT8_C(  18), -INT8_C(  72),  INT8_C(  98),
        -INT8_C(  97),  INT8_C(  27), -INT8_C(  73), -INT8_C(  75),  INT8_C( 115),  INT8_C(  43), -INT8_C(  12),  INT8_C(  47),
         INT8_C(  49),  INT8_C( 120),  INT8_C( 103), -INT8_C(  56),  INT8_C(  36),  INT8_C(  44), -INT8_C(  20),  INT8_C( 119),
         INT8_C(  60), -INT8_C(   6),  INT8_C(  98),  INT8_C(   9),  INT8_C(  97),  INT8_C(   6),  INT8_C(   2),  INT8_C(  41),
        -INT8_C(  69),  INT8_C(  27),  INT8_C( 106), -INT8_C(  44), -INT8_C(  37),  INT8_C(  16), -INT8_C(  33), -INT8_C(  36),
        -INT8_C( 105),  INT8_C(  73),  INT8_C(  41),  INT8_C(  11),  INT8_C(   0),  INT8_C(  34), -INT8_C( 112), -INT8_C(  42) },
      UINT64_C(16524310519058897855),
      {  INT8_C(   1),  INT8_C(  78),  INT8_C(  89),  INT8_C(  46),  INT8_C(  92),  INT8_C(  88),  INT8_C(  32), -INT8_C(  22),
         INT8_C(  24),  INT8_C(  63), -INT8_C( 117), -INT8_C(  71), -INT8_C(  82),  INT8_C(  84), -INT8_C(  58),  INT8_C(  89),
         INT8_C(  85), -INT8_C(  34),  INT8_C( 116),  INT8_C(  29), -INT8_C(  16),  INT8_C(  57), -INT8_C( 107), -INT8_C(   5),
        -INT8_C( 112),  INT8_C( 106), -INT8_C( 117), -INT8_C(  88),  INT8_C(  75), -INT8_C(  68), -INT8_C(  14), -INT8_C(  27),
        -INT8_C(  18), -INT8_C(  76),  INT8_C(  77), -INT8_C(   3),  INT8_C(  31),  INT8_C(  95),  INT8_C(  44), -INT8_C(   6),
        -INT8_C(  17), -INT8_C(  28),  INT8_C( 105), -INT8_C(  66),  INT8_C(  65),  INT8_C( 108),  INT8_C(  29), -INT8_C(  62),
        -INT8_C(  13),  INT8_C(  54),  INT8_C(  89),  INT8_C(  34), -INT8_C( 102),  INT8_C( 104), -INT8_C(  95),  INT8_C(  15),
         INT8_C(  72),  INT8_C(  49),  INT8_C(  44), -INT8_C(  88), -INT8_C(  81),  INT8_C(  69), -INT8_C(  99), -INT8_C( 122) },
      { -INT8_C(  72),  INT8_C( 123), -INT8_C(  12), -INT8_C(  11), -INT8_C(  54), -INT8_C(  52), -INT8_C( 119), -INT8_C(  19),
        -INT8_C(  56),  INT8_C(  99),  INT8_C(  45), -INT8_C(  17),  INT8_C(  71), -INT8_C( 106), -INT8_C(  15),  INT8_C( 107),
         INT8_C(  87), -INT8_C(  53),  INT8_C(  77),  INT8_C( 123), -INT8_C(  99), -INT8_C(  21), -INT8_C(  71), -INT8_C(  66),
         INT8_C(  90),  INT8_C(  39), -INT8_C( 115), -INT8_C( 114),  INT8_C(  58), -INT8_C(  80), -INT8_C(  92),  INT8_C( 109),
        -INT8_C(  50), -INT8_C(  35), -INT8_C(  55), -INT8_C(  93),  INT8_C(  71), -INT8_C( 120),  INT8_C(   2), -INT8_C(  84),
         INT8_C( 108),  INT8_C(   9), -INT8_C( 114), -INT8_C(  43),  INT8_C(  87), -INT8_C( 101), -INT8_C(  18),  INT8_C(  71),
         INT8_C(  47), -INT8_C( 105),  INT8_C(  20),  INT8_C(   6), -INT8_C(  42), -INT8_C(  89), -INT8_C( 112),  INT8_C( 121),
         INT8_C(  65),  INT8_C(  31), -INT8_C(  23), -INT8_C(  91),  INT8_C(  97),  INT8_C(   0), -INT8_C(  16), -INT8_C(  98) },
      {  INT8_C(  24), -INT8_C(  56),  INT8_C(  63),  INT8_C(  99), -INT8_C( 117),  INT8_C(  45),  INT8_C(  83), -INT8_C(  17),
        -INT8_C(  82),  INT8_C(  71), -INT8_C(   2), -INT8_C( 106), -INT8_C(  58), -INT8_C(  88), -INT8_C(  89),  INT8_C( 107),
        -INT8_C( 112),  INT8_C( 117), -INT8_C( 105), -INT8_C(  59),  INT8_C( 116), -INT8_C(  18), -INT8_C(  88), -INT8_C( 114),
        -INT8_C(  97),  INT8_C(  58), -INT8_C(  68), -INT8_C(  75), -INT8_C(  14),  INT8_C(  43), -INT8_C(  12),  INT8_C(  47),
         INT8_C(  49),  INT8_C( 108), -INT8_C(  28),  INT8_C(   9),  INT8_C( 105),  INT8_C(  44), -INT8_C(  66), -INT8_C(  43),
         INT8_C(  60), -INT8_C(   6),  INT8_C( 108),  INT8_C(   9),  INT8_C(  97), -INT8_C(  18),  INT8_C(   2),  INT8_C(  41),
        -INT8_C(  69),  INT8_C(  65),  INT8_C( 106), -INT8_C(  44),  INT8_C(  44),  INT8_C(  16), -INT8_C(  88), -INT8_C(  36),
        -INT8_C(  81),  INT8_C(  73),  INT8_C(  69),  INT8_C(  11),  INT8_C(   0), -INT8_C(  16), -INT8_C( 122), -INT8_C(  98) } },
    { {  INT8_C(   9),  INT8_C( 116),  INT8_C(   8), -INT8_C( 105),  INT8_C(  30),  INT8_C(   1),  INT8_C(  40),  INT8_C(  77),
         INT8_C(   3),  INT8_C(   4),  INT8_C(  74), -INT8_C(  58),  INT8_C(  94),  INT8_C( 104),  INT8_C(  78),  INT8_C(   1),
        -INT8_C(  22), -INT8_C(  16), -INT8_C(  36), -INT8_C( 125), -INT8_C(  22),  INT8_C(  46),  INT8_C(  40),  INT8_C(  53),
        -INT8_C(  36),  INT8_C( 111),  INT8_C( 103),  INT8_C(  17), -INT8_C(  81),  INT8_C(  93), -INT8_C( 122), -INT8_C( 106),
         INT8_C( 118),  INT8_C(  95),  INT8_C(  68), -INT8_C(  44), -INT8_C(  50), -INT8_C(  72), -INT8_C(  67),  INT8_C(   4),
         INT8_C(  11),  INT8_C(   8),  INT8_C(  18), -INT8_C(  28),  INT8_C(  40),  INT8_C(  26),  INT8_C( 121),  INT8_C(  71),
         INT8_C( 124), -INT8_C(  10), -INT8_C(  92),  INT8_C(  66),  INT8_C( 104), -INT8_C(  85),  INT8_C(  75), -INT8_C(  52),
         INT8_C(   7),  INT8_C(  92), -INT8_C(  26), -INT8_C(  93),  INT8_C(  82), -INT8_C(  77),  INT8_C(  63), -INT8_C(  77) },
      UINT64_C( 6731250091584344763),
      {  INT8_C(  80), -INT8_C( 111), -INT8_C(  69), -INT8_C(   9), -INT8_C( 117),  INT8_C(  48), -INT8_C(  14), -INT8_C(  27),
        -INT8_C( 124),  INT8_C(  23),  INT8_C(  77), -INT8_C(  97), -INT8_C( 114), -INT8_C( 109),  INT8_C(  45),  INT8_C(  66),
         INT8_C(  28),  INT8_C(  58),  INT8_C(  72), -INT8_C(  32),  INT8_C(  48), -INT8_C(  77),  INT8_C(  98),  INT8_C( 111),
         INT8_C(  97),  INT8_C(   4), -INT8_C( 106),  INT8_C(  30),  INT8_C(  41),  INT8_C( 103),  INT8_C(  12), -INT8_C(  31),
        -INT8_C(  79),  INT8_C(  75), -INT8_C(  80),  INT8_C(  11),  INT8_C(  87), -INT8_C(  89),  INT8_C(  34), -INT8_C(  73),
        -INT8_C(  59),  INT8_C( 122), -INT8_C( 104),  INT8_C( 110), -INT8_C( 117),  INT8_C( 124), -INT8_C(   2),  INT8_C(  47),
        -INT8_C(  44), -INT8_C(  33),  INT8_C(  38),  INT8_C(  32),  INT8_C( 115), -INT8_C(  15), -INT8_C(  99), -INT8_C(  67),
         INT8_C(  52),  INT8_C(  97), -INT8_C(  93), -INT8_C(  91),  INT8_C(  76), -INT8_C(  59), -INT8_C(  39),  INT8_C(  40) },
      {  INT8_C(  95),  INT8_C( 113),  INT8_C(  52), -INT8_C(  58),  INT8_C( 111), -INT8_C(  46),  INT8_C( 105), -INT8_C( 119),
         INT8_C( 101), -INT8_C(  65),  INT8_C( 108),  INT8_C( 106),  INT8_C(  42), -INT8_C(  69), -INT8_C(  66), -INT8_C( 124),
         INT8_C( 108), -INT8_C(   9), -INT8_C(  31), -INT8_C(  68), -INT8_C(  50),  INT8_C(  40), -INT8_C( 117), -INT8_C(  27),
        -INT8_C(  23),  INT8_C(   3), -INT8_C(  50), -INT8_C(  70),  INT8_C( 115),  INT8_C(  47), -INT8_C(  61),  INT8_C( 105),
        -INT8_C(  86), -INT8_C(  73), -INT8_C(  59),  INT8_C(  63), -INT8_C( 105), -INT8_C( 104),  INT8_C(  60),  INT8_C( 117),
         INT8_C(  20),  INT8_C(  28),  INT8_C(  93), -INT8_C(   7),  INT8_C(  75), -INT8_C(  94), -INT8_C(  21),  INT8_C( 124),
         INT8_C(  83), -INT8_C(  41),  INT8_C(  58), -INT8_C( 114), -INT8_C( 124), -INT8_C( 123),  INT8_C( 111),  INT8_C(  11),
         INT8_C(  27),  INT8_C(   1),  INT8_C( 114),  INT8_C(  14),  INT8_C(  11), -INT8_C(  61), -INT8_C( 115),  INT8_C(   5) },
      { -INT8_C( 124),  INT8_C( 101),  INT8_C(   8), -INT8_C(  65),  INT8_C(  77),  INT8_C( 108),  INT8_C(  40),  INT8_C( 106),
         INT8_C(   3),  INT8_C(  42),  INT8_C(  74), -INT8_C(  58),  INT8_C(  45),  INT8_C( 104),  INT8_C(  66),  INT8_C(   1),
         INT8_C(  97), -INT8_C(  23), -INT8_C(  36), -INT8_C( 125), -INT8_C( 106), -INT8_C(  50),  INT8_C(  40),  INT8_C(  53),
         INT8_C(  41),  INT8_C( 115),  INT8_C( 103),  INT8_C(  47), -INT8_C(  81), -INT8_C(  61), -INT8_C(  31), -INT8_C( 106),
        -INT8_C(  59),  INT8_C(  20),  INT8_C(  68),  INT8_C(  28), -INT8_C(  50), -INT8_C(  72),  INT8_C( 110),  INT8_C(   4),
         INT8_C(  11),  INT8_C(   8),  INT8_C( 124), -INT8_C(  28), -INT8_C(   2), -INT8_C(  21),  INT8_C( 121),  INT8_C(  71),
         INT8_C( 124),  INT8_C(  27), -INT8_C(  92),  INT8_C(   1),  INT8_C( 104),  INT8_C( 114), -INT8_C(  91), -INT8_C(  52),
         INT8_C(  76),  INT8_C(  92), -INT8_C(  59), -INT8_C(  61), -INT8_C(  39), -INT8_C(  77),  INT8_C(  40), -INT8_C(  77) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i src = simde_mm512_loadu_epi8(test_vec[i].src);
    simde__m512i a = simde_mm512_loadu_epi8(test_vec[i].a);
    simde__m512i b = simde_mm512_loadu_epi8(test_vec[i].b);
    simde__m512i r = simde_mm512_mask_unpackhi_epi8(src, test_vec[i].k, a, b);
    simde_test_x86_assert_equal_i8x64(r, simde_mm512_loadu_epi8(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_mm512_maskz_unpackhi_epi8 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const simde__mmask64 k;
    const int8_t a[64];
    const int8_t b[64];
    const int8_t r[64];
  } test_vec[] = {
{ UINT64_C( 1842617825699503392),
      { -INT8_C(  16),  INT8_C(  31), -INT8_C(  45),  INT8_C(  14),  INT8_C(  73),  INT8_C( 111),  INT8_C(  28),  INT8_C(   3),
        -INT8_C( 127),  INT8_C(  39), -INT8_C(  33), -INT8_C(  80),  INT8_C( 106),  INT8_C( 116), -INT8_C(  49),  INT8_C(  40),
         INT8_C(  63), -INT8_C(  74), -INT8_C(  44),  INT8_C(  32), -INT8_C(  92),  INT8_C(   8),  INT8_C(  21), -INT8_C(  80),
         INT8_C( 101), -INT8_C(  14),  INT8_C( 103),  INT8_C( 103), -INT8_C(  62), -INT8_C(  85), -INT8_C(  85), -INT8_C( 101),
         INT8_C(  74),  INT8_C(  34),  INT8_C(  59), -INT8_C(  50),  INT8_C(  89), -INT8_C(  61), -INT8_C( 117),  INT8_C( 110),
         INT8_C(  88),  INT8_C(  31), -INT8_C( 103),  INT8_C(  62), -INT8_C( 118), -INT8_C(  14),  INT8_C(  63), -INT8_C(  35),
         INT8_C(  93), -INT8_C(  60),  INT8_C( 115), -INT8_C(  92),  INT8_C( 125), -INT8_C(  64),  INT8_C(  21), -INT8_C(  19),
        -INT8_C( 103), -INT8_C(  62),  INT8_C( 103),  INT8_C(  61),  INT8_C(  92), -INT8_C(  11), -INT8_C( 124), -INT8_C(  29) },
      { -INT8_C(  90),  INT8_C(  83),  INT8_C(  65),  INT8_C( 112), -INT8_C( 103),  INT8_C( 105),  INT8_C(  54), -INT8_C( 107),
        -INT8_C(  59),  INT8_C( 107),  INT8_C(  94),  INT8_C( 125),  INT8_C( 117),  INT8_C( 102), -INT8_C(  66), -INT8_C(  98),
        -INT8_C(  75),  INT8_C(  37), -INT8_C(  46), -INT8_C(  38), -INT8_C(  16), -INT8_C(  17), -INT8_C(  12), -INT8_C(  63),
        -INT8_C( 110), -INT8_C(  38),  INT8_C( 103), -INT8_C(  38), -INT8_C(  74), -INT8_C(  98),  INT8_C(  38), -INT8_C(  39),
        -INT8_C( 119), -INT8_C(  37), -INT8_C(  25), -INT8_C(  43), -INT8_C(  63),  INT8_C(   4),  INT8_C( 125), -INT8_C( 114),
        -INT8_C( 124), -INT8_C(  61),  INT8_C(  81), -INT8_C( 109),  INT8_C(  72),  INT8_C(  89),  INT8_C(  72), -INT8_C(   3),
         INT8_C(  38), -INT8_C( 125),  INT8_C(  75), -INT8_C(  25),  INT8_C(   9), -INT8_C(  89), -INT8_C(  53), -INT8_C(   5),
        -INT8_C(   1),  INT8_C(  99),  INT8_C( 104), -INT8_C(  86), -INT8_C(  57),  INT8_C(  51),  INT8_C( 121),  INT8_C( 117) },
      {  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(  94),  INT8_C(   0),  INT8_C(   0),
         INT8_C( 106),  INT8_C(   0),  INT8_C( 116),  INT8_C( 102), -INT8_C(  49),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
         INT8_C( 101), -INT8_C( 110), -INT8_C(  14), -INT8_C(  38),  INT8_C( 103),  INT8_C(   0),  INT8_C(   0), -INT8_C(  38),
        -INT8_C(  62),  INT8_C(   0), -INT8_C(  85), -INT8_C(  98), -INT8_C(  85),  INT8_C(   0), -INT8_C( 101),  INT8_C(   0),
         INT8_C(   0), -INT8_C( 124),  INT8_C(  31),  INT8_C(   0),  INT8_C(   0),  INT8_C(  81),  INT8_C(   0),  INT8_C(   0),
        -INT8_C( 118),  INT8_C(  72),  INT8_C(   0),  INT8_C(  89),  INT8_C(   0),  INT8_C(   0), -INT8_C(  35),  INT8_C(   0),
         INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C( 103),  INT8_C(   0),  INT8_C(   0), -INT8_C(  86),
         INT8_C(  92),  INT8_C(   0),  INT8_C(   0),  INT8_C(  51), -INT8_C( 124),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0) } },
    { UINT64_C( 9399397783548227804),
      {  INT8_C( 121),  INT8_C(  36), -INT8_C( 115),  INT8_C(   4), -INT8_C(  20), -INT8_C(   8), -INT8_C( 107),  INT8_C(  19),
         INT8_C( 100), -INT8_C(  39),  INT8_C(  31), -INT8_C(  78),  INT8_C(  28),  INT8_C(  82),  INT8_C( 122), -INT8_C(  47),
         INT8_C(  68), -INT8_C(  88), -INT8_C(  46), -INT8_C(  13), -INT8_C(  79), -INT8_C(  83),  INT8_C( 120),  INT8_C(   1),
         INT8_C(  79), -INT8_C( 109),  INT8_C(  44),  INT8_C(   5), -INT8_C(  81),  INT8_C(  95),  INT8_C(  39), -INT8_C(  87),
         INT8_C(  65),  INT8_C( 108), -INT8_C(  27),  INT8_C(  62), -INT8_C(  53),  INT8_C(  83),  INT8_C(  66), -INT8_C(  76),
        -INT8_C(  58),  INT8_C( 117),  INT8_C(  91),  INT8_C( 116),  INT8_C( 107), -INT8_C(  88), -INT8_C(   2),  INT8_C(  93),
        -INT8_C( 103),  INT8_C(  46),  INT8_C( 111),  INT8_C(  35), -INT8_C(  51), -INT8_C(  50), -INT8_C( 127), -INT8_C(  91),
        -INT8_C(  52), -INT8_C(  51),  INT8_C(  50),  INT8_C(  22), -INT8_C(  67),  INT8_C( 126), -INT8_C(  41), -INT8_C(  17) },
      {  INT8_C(   1),  INT8_C(  54),  INT8_C(  70),  INT8_C(   4), -INT8_C(  68), -INT8_C(  34), -INT8_C(  87),  INT8_C( 122),
         INT8_C(  49),  INT8_C(  28),  INT8_C( 102), -INT8_C(  15),  INT8_C(   5),  INT8_C(  57),  INT8_C(   2), -INT8_C(  58),
        -INT8_C(  67),  INT8_C(  86),  INT8_C( 112), -INT8_C(  90),  INT8_C(  99), -INT8_C(  45),  INT8_C(  62), -INT8_C(  69),
        -INT8_C(  84),  INT8_C(   6), -INT8_C( 111),  INT8_C( 102),  INT8_C(  81),  INT8_C(  62), -INT8_C(  75), -INT8_C(  43),
        -INT8_C(  55),  INT8_C( 122), -INT8_C(  49),  INT8_C(  97), -INT8_C(  64),  INT8_C( 107), -INT8_C(  31), -INT8_C(  41),
         INT8_C( 101), -INT8_C( 124), -INT8_C(  60), -INT8_C(  13),  INT8_C(  48),  INT8_C(  19),  INT8_C(   6), -INT8_C(  80),
         INT8_C(  17), -INT8_C(   9),  INT8_C(  45),  INT8_C(  80), -INT8_C( 117), -INT8_C(   3),  INT8_C(  68),  INT8_C(  61),
        -INT8_C(   4),  INT8_C(  32),  INT8_C(  92),  INT8_C(  74), -INT8_C(  21), -INT8_C(  68),  INT8_C(  74),  INT8_C( 108) },
      {  INT8_C(   0),  INT8_C(   0), -INT8_C(  39),  INT8_C(  28),  INT8_C(  31),  INT8_C(   0), -INT8_C(  78), -INT8_C(  15),
         INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C( 122),  INT8_C(   2), -INT8_C(  47),  INT8_C(   0),
         INT8_C(   0),  INT8_C(   0), -INT8_C( 109),  INT8_C(   6),  INT8_C(  44), -INT8_C( 111),  INT8_C(   5),  INT8_C( 102),
         INT8_C(   0),  INT8_C(  81),  INT8_C(  95),  INT8_C(   0),  INT8_C(   0), -INT8_C(  75), -INT8_C(  87), -INT8_C(  43),
        -INT8_C(  58),  INT8_C( 101),  INT8_C(   0), -INT8_C( 124),  INT8_C(  91), -INT8_C(  60),  INT8_C( 116),  INT8_C(   0),
         INT8_C(   0),  INT8_C(  48), -INT8_C(  88),  INT8_C(  19), -INT8_C(   2),  INT8_C(   0),  INT8_C(  93),  INT8_C(   0),
        -INT8_C(  52),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(  50),  INT8_C(  92),  INT8_C(  22),  INT8_C(   0),
         INT8_C(   0), -INT8_C(  21),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C( 108) } },
    { UINT64_C(12562662648533992732),
      {  INT8_C( 117), -INT8_C(   7), -INT8_C(  90), -INT8_C( 108),  INT8_C( 118), -INT8_C( 119),  INT8_C(  45), -INT8_C(  36),
         INT8_C(   8), -INT8_C(  87), -INT8_C(  41),  INT8_C(  85), -INT8_C(  69), -INT8_C( 124), -INT8_C( 119),  INT8_C(  10),
         INT8_C(  96),  INT8_C( 103),  INT8_C(  52),  INT8_C(  24),  INT8_C(  34),  INT8_C( 121),  INT8_C( 109), -INT8_C(  67),
        -INT8_C(  60), -INT8_C( 125),  INT8_C(  22), -INT8_C(  22), -INT8_C(  48),  INT8_C( 115),  INT8_C(  64), -INT8_C(  79),
         INT8_C(  75), -INT8_C( 117),  INT8_C(  13),  INT8_C( 113),  INT8_C(  51), -INT8_C( 109),  INT8_C(  62),  INT8_C(  51),
        -INT8_C(  60),  INT8_C( 112),  INT8_C(  60),  INT8_C(   8),  INT8_C(  33), -INT8_C(  50),  INT8_C(  45),  INT8_C(  44),
         INT8_C(  40), -INT8_C(  18), -INT8_C(  58),  INT8_C(  75), -INT8_C(  66),  INT8_C( 104), -INT8_C(  81), -INT8_C( 102),
        -INT8_C(  95), -INT8_C(   4), -INT8_C(  98),  INT8_C(  24),  INT8_C(  21), -INT8_C(   5),  INT8_C( 115),  INT8_C(  62) },
      { -INT8_C(  55),  INT8_C(  57), -INT8_C(  64), -INT8_C(  65),  INT8_C( 123),  INT8_C( 124), -INT8_C(  54),  INT8_C(   1),
        -INT8_C( 105),  INT8_C(  97), -INT8_C(  53), -INT8_C(  16), -INT8_C(  83),  INT8_C(  51), -INT8_C( 122), -INT8_C(  36),
         INT8_C(  89), -INT8_C(  83),  INT8_C(  30), -INT8_C(  91),  INT8_C(  30), -INT8_C(  23),  INT8_C( 115), -INT8_C(  19),
         INT8_C(  88), -INT8_C(  90), -INT8_C(  70),  INT8_C(  21), -INT8_C(  61), -INT8_C(  87), -INT8_C(   7), -INT8_C(  70),
        -INT8_C(  75), -INT8_C(  27), -INT8_C( 107), -INT8_C(  39),  INT8_C(  39),  INT8_C(  66),  INT8_C(  33), -INT8_C(  54),
        -INT8_C(  86), -INT8_C(  33), -INT8_C(  74),  INT8_C( 111),  INT8_C( 123), -INT8_C(  37), -INT8_C( 110),  INT8_C(  96),
        -INT8_C(  13), -INT8_C(  72), -INT8_C(  69), -INT8_C(   6), -INT8_C(  31),  INT8_C(  32), -INT8_C(  74), -INT8_C( 103),
         INT8_C(  71),  INT8_C( 114),  INT8_C(  48), -INT8_C(  72), -INT8_C(  80),  INT8_C( 119),  INT8_C( 119), -INT8_C(  80) },
      {  INT8_C(   0),  INT8_C(   0), -INT8_C(  87),  INT8_C(  97), -INT8_C(  41),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
        -INT8_C(  69),  INT8_C(   0), -INT8_C( 124),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(  10), -INT8_C(  36),
        -INT8_C(  60),  INT8_C(  88), -INT8_C( 125), -INT8_C(  90),  INT8_C(   0), -INT8_C(  70), -INT8_C(  22),  INT8_C(  21),
         INT8_C(   0), -INT8_C(  61),  INT8_C( 115),  INT8_C(   0),  INT8_C(  64), -INT8_C(   7), -INT8_C(  79),  INT8_C(   0),
         INT8_C(   0), -INT8_C(  86),  INT8_C( 112), -INT8_C(  33),  INT8_C(  60),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
         INT8_C(  33),  INT8_C( 123),  INT8_C(   0), -INT8_C(  37),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(  96),
        -INT8_C(  95),  INT8_C(  71), -INT8_C(   4),  INT8_C(   0), -INT8_C(  98),  INT8_C(   0),  INT8_C(  24),  INT8_C(   0),
         INT8_C(   0), -INT8_C(  80), -INT8_C(   5),  INT8_C( 119),  INT8_C(   0),  INT8_C( 119),  INT8_C(   0), -INT8_C(  80) } },
    { UINT64_C(17893169858524891965),
      {  INT8_C(  11), -INT8_C(  64), -INT8_C(  26), -INT8_C( 121), -INT8_C(  23),  INT8_C(  47),  INT8_C(  50),  INT8_C(   8),
        -INT8_C( 102), -INT8_C( 109), -INT8_C(   3),  INT8_C(   1),  INT8_C(  93), -INT8_C( 108), -INT8_C( 124),  INT8_C(  97),
        -INT8_C(  72), -INT8_C(  91),  INT8_C(  30), -INT8_C( 109), -INT8_C(   9), -INT8_C(  50), -INT8_C(  45),  INT8_C(  32),
        -INT8_C(  74),  INT8_C(   8), -INT8_C( 125),  INT8_C(  71), -INT8_C(  64), -INT8_C( 104),  INT8_C(  73), -INT8_C(  41),
         INT8_C(  54),  INT8_C(  97),  INT8_C(  18),  INT8_C(   0),  INT8_C( 104), -INT8_C(  98), -INT8_C(  96),  INT8_C(  54),
         INT8_C(  76), -INT8_C(  63), -INT8_C(  35), -INT8_C(  89), -INT8_C(  50),  INT8_C(  28), -INT8_C(  40),  INT8_C( 119),
        -INT8_C(  94),  INT8_C( 126), -INT8_C(  63), -INT8_C(  42), -INT8_C(  70), -INT8_C(  72), -INT8_C(   1),  INT8_C(  82),
         INT8_C(   2), -INT8_C(   2), -INT8_C(  29),  INT8_C(  24), -INT8_C( 101), -INT8_C(  98),  INT8_C(  12), -INT8_C(  64) },
      { -INT8_C(  35), -INT8_C(  37), -INT8_C( 113), -INT8_C(   1), -INT8_C(   8),  INT8_C(  10),  INT8_C(  83),  INT8_C(  14),
        -INT8_C(  33),  INT8_C(  57), -INT8_C(  47), -INT8_C(  91),  INT8_C(  57),  INT8_C( 122), -INT8_C( 116), -INT8_C(  21),
        -INT8_C(   9),  INT8_C(  13), -INT8_C(   4),  INT8_C(   1), -INT8_C(  81), -INT8_C(  27),  INT8_C( 113),  INT8_C(   9),
        -INT8_C(  94), -INT8_C(  98), -INT8_C( 101),  INT8_C(  52), -INT8_C(  73),  INT8_C(  30), -INT8_C(  68), -INT8_C( 120),
        -INT8_C(  62),  INT8_C(  54),  INT8_C(  51), -INT8_C( 100),  INT8_C(  88), -INT8_C(  81), -INT8_C(  47),  INT8_C(  16),
        -INT8_C(  66),  INT8_C( 126),  INT8_C(  78), -INT8_C(  79),  INT8_C(  51),  INT8_C( 109), -INT8_C(   6), -INT8_C( 110),
             INT8_MAX, -INT8_C(  22),  INT8_C(  75),  INT8_C(  52),  INT8_C(   9),  INT8_C(  66),  INT8_C(  45), -INT8_C( 114),
         INT8_C(  30),  INT8_C(   4), -INT8_C(  24), -INT8_C(   4),  INT8_C(  27), -INT8_C( 117),  INT8_C(   2),  INT8_C( 111) },
      { -INT8_C( 102),  INT8_C(   0), -INT8_C( 109),  INT8_C(  57), -INT8_C(   3), -INT8_C(  47),  INT8_C(   0),  INT8_C(   0),
         INT8_C(  93),  INT8_C(  57),  INT8_C(   0),  INT8_C( 122),  INT8_C(   0),  INT8_C(   0),  INT8_C(  97),  INT8_C(   0),
         INT8_C(   0), -INT8_C(  94),  INT8_C(   0), -INT8_C(  98), -INT8_C( 125),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
        -INT8_C(  64), -INT8_C(  73),  INT8_C(   0),  INT8_C(  30),  INT8_C(   0), -INT8_C(  68),  INT8_C(   0),  INT8_C(   0),
         INT8_C(  76), -INT8_C(  66), -INT8_C(  63),  INT8_C( 126),  INT8_C(   0),  INT8_C(  78),  INT8_C(   0),  INT8_C(   0),
        -INT8_C(  50),  INT8_C(  51),  INT8_C(  28),  INT8_C( 109),  INT8_C(   0),  INT8_C(   0),  INT8_C( 119),  INT8_C(   0),
         INT8_C(   2),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  29),  INT8_C(   0),  INT8_C(  24),  INT8_C(   0),
         INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C( 117),  INT8_C(  12),  INT8_C(   2), -INT8_C(  64),  INT8_C( 111) } },
    { UINT64_C(11620352878424023674),
      {  INT8_C(  64),  INT8_C(  41),  INT8_C(  40), -INT8_C(  58), -INT8_C(  31),  INT8_C( 106), -INT8_C(  76), -INT8_C(  77),
        -INT8_C(  10),  INT8_C(  26), -INT8_C( 102),  INT8_C(  13),  INT8_C(   4), -INT8_C(  65), -INT8_C(  31),  INT8_C(  69),
         INT8_C(  38),  INT8_C(  70),  INT8_C(  44),  INT8_C(  27), -INT8_C(  44),  INT8_C(   7), -INT8_C( 106), -INT8_C(  27),
         INT8_C(  57), -INT8_C(  78), -INT8_C( 126), -INT8_C(  15),  INT8_C(  63),  INT8_C(  71),  INT8_C( 104), -INT8_C(  30),
        -INT8_C( 122),  INT8_C(  82),      INT8_MIN,  INT8_C( 117),  INT8_C(  32),  INT8_C(  74),  INT8_C( 116),  INT8_C(  76),
         INT8_C( 117), -INT8_C(  60),  INT8_C(  63), -INT8_C( 106),  INT8_C(   3), -INT8_C( 125),  INT8_C(  54), -INT8_C(   5),
         INT8_C(  73),  INT8_C(  65),  INT8_C(  98), -INT8_C(  74),  INT8_C( 105),  INT8_C(  56),  INT8_C(  92),  INT8_C(  81),
         INT8_C(  66), -INT8_C(  48), -INT8_C(   9), -INT8_C(  93), -INT8_C(  28), -INT8_C( 117),  INT8_C(  55), -INT8_C(  21) },
      { -INT8_C(  79),  INT8_C(  68), -INT8_C(  97),  INT8_C( 102), -INT8_C(  67), -INT8_C(  34), -INT8_C( 117), -INT8_C(  93),
         INT8_C(  58), -INT8_C(  11),      INT8_MIN,  INT8_C(  34),  INT8_C( 105), -INT8_C(  83), -INT8_C( 105),  INT8_C(  84),
         INT8_C(  37), -INT8_C( 127), -INT8_C(  90),  INT8_C(  41),  INT8_C(  57), -INT8_C(  49),  INT8_C(  94), -INT8_C(  19),
         INT8_C( 101), -INT8_C(  66), -INT8_C(  69),  INT8_C( 118), -INT8_C(  22),  INT8_C(  90), -INT8_C(  79),  INT8_C(   7),
        -INT8_C(  95),  INT8_C(   0), -INT8_C( 116),  INT8_C(   5), -INT8_C(  84), -INT8_C( 106), -INT8_C(  11), -INT8_C(  29),
        -INT8_C(  68),  INT8_C(  64), -INT8_C(  56),  INT8_C(  11),  INT8_C(  46),  INT8_C(  28), -INT8_C(  36), -INT8_C(  15),
         INT8_C(   1),  INT8_C(  44), -INT8_C(  81),  INT8_C(  26), -INT8_C( 103),  INT8_C(  27), -INT8_C(  85), -INT8_C(  77),
        -INT8_C( 119), -INT8_C(   9), -INT8_C(  75), -INT8_C(  79),  INT8_C(  76),  INT8_C(   1), -INT8_C(  90),  INT8_C(   2) },
      {  INT8_C(   0),  INT8_C(  58),  INT8_C(   0), -INT8_C(  11), -INT8_C( 102),      INT8_MIN,  INT8_C(  13),  INT8_C(   0),
         INT8_C(   0),  INT8_C( 105),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C( 105),  INT8_C(  69),  INT8_C(  84),
         INT8_C(   0),  INT8_C( 101), -INT8_C(  78),  INT8_C(   0),  INT8_C(   0), -INT8_C(  69),  INT8_C(   0),  INT8_C(   0),
         INT8_C(  63), -INT8_C(  22),  INT8_C(   0),  INT8_C(  90),  INT8_C(   0), -INT8_C(  79),  INT8_C(   0),  INT8_C(   0),
         INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  56), -INT8_C( 106),  INT8_C(   0),
         INT8_C(   3),  INT8_C(   0),  INT8_C(   0),  INT8_C(  28),  INT8_C(   0),  INT8_C(   0), -INT8_C(   5), -INT8_C(  15),
         INT8_C(  66), -INT8_C( 119),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  93),  INT8_C(   0),
        -INT8_C(  28),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  90),  INT8_C(   0),  INT8_C(   2) } },
    { UINT64_C(14978542943581159871),
      {  INT8_C( 107), -INT8_C(  44), -INT8_C(  17), -INT8_C(  46),  INT8_C(  75),  INT8_C(  81), -INT8_C( 125), -INT8_C(  44),
         INT8_C(   4),  INT8_C(  98), -INT8_C(  33), -INT8_C(  19), -INT8_C(  67),  INT8_C(  81), -INT8_C(  50), -INT8_C(  23),
        -INT8_C(  54), -INT8_C(  37),  INT8_C(  54), -INT8_C(  47),  INT8_C( 124),  INT8_C(  66),  INT8_C( 109),  INT8_C(  54),
        -INT8_C(  35), -INT8_C(  12), -INT8_C(  72), -INT8_C(  64),  INT8_C(  47), -INT8_C( 107),  INT8_C(  54),  INT8_C(  48),
         INT8_C( 120),  INT8_C(  50),  INT8_C(  57), -INT8_C(  20),  INT8_C(  76),  INT8_C( 118),      INT8_MAX, -INT8_C(  15),
         INT8_C(  49), -INT8_C(  68), -INT8_C(  59), -INT8_C(  37),  INT8_C(  87), -INT8_C(  57), -INT8_C( 121),  INT8_C(  60),
        -INT8_C(  89), -INT8_C(   3),  INT8_C(  61),  INT8_C(  29), -INT8_C(   3), -INT8_C(  71),  INT8_C(  57),  INT8_C(  63),
        -INT8_C( 111), -INT8_C( 100), -INT8_C(  37),  INT8_C(  89),  INT8_C(  91),  INT8_C( 112), -INT8_C(   1), -INT8_C(  25) },
      {  INT8_C(  70), -INT8_C(  37), -INT8_C( 125),  INT8_C(  91),  INT8_C(  80),  INT8_C( 112),  INT8_C(  38),  INT8_C( 101),
        -INT8_C(  75), -INT8_C(  56), -INT8_C(  18), -INT8_C(  82), -INT8_C(  77),  INT8_C(  18), -INT8_C(  97),  INT8_C( 115),
        -INT8_C(  11), -INT8_C( 124),  INT8_C(  88),  INT8_C(  31), -INT8_C(  92), -INT8_C(  68), -INT8_C(  40),  INT8_C(  64),
        -INT8_C(  16), -INT8_C( 125),  INT8_C(  49),  INT8_C(  76), -INT8_C(  55), -INT8_C(   5),  INT8_C(  43), -INT8_C(  35),
        -INT8_C(  17),  INT8_C(  26),  INT8_C(  33), -INT8_C( 113),  INT8_C(  17),  INT8_C(  75),  INT8_C(  45),  INT8_C( 108),
        -INT8_C(  75), -INT8_C(  26), -INT8_C(  40), -INT8_C( 127),  INT8_C(  25), -INT8_C(  16), -INT8_C(  93), -INT8_C(  59),
        -INT8_C(  89),  INT8_C(  21), -INT8_C(  46),  INT8_C( 111), -INT8_C(   6),      INT8_MIN, -INT8_C(  17), -INT8_C( 124),
         INT8_C(  41),  INT8_C(  69), -INT8_C(  92),  INT8_C( 123), -INT8_C(  44),  INT8_C(  41),  INT8_C(  61),  INT8_C(   4) },
      {  INT8_C(   4), -INT8_C(  75),  INT8_C(  98), -INT8_C(  56), -INT8_C(  33), -INT8_C(  18),  INT8_C(   0), -INT8_C(  82),
        -INT8_C(  67),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  23),  INT8_C( 115),
         INT8_C(   0), -INT8_C(  16), -INT8_C(  12),  INT8_C(   0), -INT8_C(  72),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
         INT8_C(  47),  INT8_C(   0), -INT8_C( 107), -INT8_C(   5),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  35),
         INT8_C(   0), -INT8_C(  75),  INT8_C(   0),  INT8_C(   0), -INT8_C(  59), -INT8_C(  40), -INT8_C(  37),  INT8_C(   0),
         INT8_C(  87),  INT8_C(   0),  INT8_C(   0), -INT8_C(  16), -INT8_C( 121), -INT8_C(  93),  INT8_C(  60),  INT8_C(   0),
         INT8_C(   0),  INT8_C(  41), -INT8_C( 100),  INT8_C(  69), -INT8_C(  37),  INT8_C(   0),  INT8_C(  89),  INT8_C( 123),
         INT8_C(  91), -INT8_C(  44),  INT8_C( 112),  INT8_C(  41),  INT8_C(   0),  INT8_C(   0), -INT8_C(  25),  INT8_C(   4) } },
    { UINT64_C( 4647964056426211003),
      {  INT8_C(  83), -INT8_C( 114), -INT8_C(  31), -INT8_C( 103),  INT8_C(  23),  INT8_C(  85),  INT8_C(  19), -INT8_C( 122),
        -INT8_C(  98), -INT8_C(  92),  INT8_C( 117),  INT8_C(   7), -INT8_C(  97), -INT8_C(  54),  INT8_C(  87), -INT8_C(  38),
         INT8_C(  59),  INT8_C(  32),  INT8_C(  46), -INT8_C(  57),  INT8_C(  27),  INT8_C(  50),  INT8_C(  96), -INT8_C(  70),
        -INT8_C(  86), -INT8_C(  71), -INT8_C(  19), -INT8_C(  73), -INT8_C(  58),  INT8_C(  25),      INT8_MAX,  INT8_C( 102),
         INT8_C( 118), -INT8_C( 126),  INT8_C(  36),  INT8_C(  36), -INT8_C( 108), -INT8_C(   3),  INT8_C(  26),  INT8_C(  71),
         INT8_C( 111), -INT8_C(  19), -INT8_C(  39), -INT8_C(  41),  INT8_C(  43), -INT8_C(  82),  INT8_C(   8), -INT8_C(  91),
         INT8_C(  91),  INT8_C( 109), -INT8_C(  47), -INT8_C(  32), -INT8_C( 113), -INT8_C(   9),  INT8_C(  17),  INT8_C(  19),
         INT8_C(  95), -INT8_C(  94), -INT8_C(  55),  INT8_C(  92),  INT8_C(  10), -INT8_C(  13), -INT8_C(  51), -INT8_C( 114) },
      { -INT8_C(  80), -INT8_C(  39),  INT8_C(  24), -INT8_C(  29),  INT8_C(  36),  INT8_C( 124), -INT8_C(  91),  INT8_C( 119),
         INT8_C(   2), -INT8_C(  66),  INT8_C(  51),  INT8_C(  31),  INT8_C( 106), -INT8_C(  20),  INT8_C( 113),  INT8_C(  47),
        -INT8_C( 126), -INT8_C( 119), -INT8_C(  94),  INT8_C(   1),  INT8_C(  32),  INT8_C(   1),  INT8_C(  75),  INT8_C(  88),
         INT8_C(  38),  INT8_C( 108),  INT8_C(   0),  INT8_C( 118), -INT8_C(  24),  INT8_C( 108), -INT8_C(  36), -INT8_C( 117),
         INT8_C(   3), -INT8_C( 126),  INT8_C(   2),  INT8_C(  63), -INT8_C( 124),  INT8_C(  86),  INT8_C( 112), -INT8_C(  92),
         INT8_C( 114), -INT8_C(  77), -INT8_C(  10),  INT8_C(  45), -INT8_C(   4), -INT8_C( 108),  INT8_C(  34),  INT8_C(  88),
         INT8_C( 114), -INT8_C(  62), -INT8_C(  35), -INT8_C(  72), -INT8_C(  67), -INT8_C(   4), -INT8_C(  11), -INT8_C(  28),
         INT8_C(  62), -INT8_C(   4), -INT8_C(  41),  INT8_C(  22), -INT8_C(  92),  INT8_C(   2), -INT8_C( 125), -INT8_C( 114) },
      { -INT8_C(  98),  INT8_C(   2),  INT8_C(   0), -INT8_C(  66),  INT8_C( 117),  INT8_C(  51),  INT8_C(   0),  INT8_C(  31),
         INT8_C(   0),  INT8_C( 106), -INT8_C(  54),  INT8_C(   0),  INT8_C(   0),  INT8_C( 113), -INT8_C(  38),  INT8_C(   0),
        -INT8_C(  86),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  19),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
         INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),      INT8_MAX, -INT8_C(  36),  INT8_C( 102), -INT8_C( 117),
         INT8_C(   0),  INT8_C( 114), -INT8_C(  19), -INT8_C(  77),  INT8_C(   0), -INT8_C(  10),  INT8_C(   0),  INT8_C(  45),
         INT8_C(   0), -INT8_C(   4),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(  34), -INT8_C(  91),  INT8_C(  88),
         INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(  22),
         INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C( 114),  INT8_C(   0) } },
    { UINT64_C(15681621470748660046),
      {  INT8_C(  84), -INT8_C(   3),  INT8_C(  39),  INT8_C(  86),  INT8_C(  42),  INT8_C( 106),  INT8_C(  77),  INT8_C( 121),
         INT8_C(  59), -INT8_C(  11),  INT8_C(  40), -INT8_C(  25),  INT8_C(  76),  INT8_C( 122),  INT8_C(  37), -INT8_C(  82),
        -INT8_C(   2),  INT8_C(   9), -INT8_C( 118), -INT8_C(  40),  INT8_C( 100),  INT8_C( 118), -INT8_C(  96), -INT8_C(  29),
         INT8_C( 126), -INT8_C(  75), -INT8_C(  94),  INT8_C(  60), -INT8_C(  31), -INT8_C(  88),  INT8_C(  90), -INT8_C( 125),
         INT8_C(  53), -INT8_C(  71),  INT8_C( 124), -INT8_C( 104), -INT8_C(  32), -INT8_C( 111), -INT8_C(  22), -INT8_C( 110),
        -INT8_C(  87),  INT8_C(  81),  INT8_C(  94),  INT8_C( 107), -INT8_C(  58), -INT8_C(  57),  INT8_C(  55),  INT8_C(  46),
        -INT8_C(  57),  INT8_C(  85), -INT8_C(  96),  INT8_C(  72), -INT8_C(  18), -INT8_C(  54), -INT8_C( 116), -INT8_C( 123),
         INT8_C(  46), -INT8_C(  78), -INT8_C(  79),  INT8_C(  99),  INT8_C(   2), -INT8_C(  21), -INT8_C(  79),  INT8_C(  34) },
      { -INT8_C( 109),  INT8_C( 105),  INT8_C(  43),  INT8_C( 103),  INT8_C( 110), -INT8_C( 105), -INT8_C( 108), -INT8_C(  33),
        -INT8_C( 106),  INT8_C(  47), -INT8_C(   6),  INT8_C(  58), -INT8_C(  52),  INT8_C(  85), -INT8_C(  43),  INT8_C(  89),
        -INT8_C(  29),  INT8_C(  88), -INT8_C( 127),  INT8_C(  31), -INT8_C(  22), -INT8_C(  85),  INT8_C( 100), -INT8_C(  24),
         INT8_C( 111),  INT8_C(   8),  INT8_C( 125), -INT8_C(  72),  INT8_C(  37), -INT8_C(  25),  INT8_C(  51), -INT8_C(  49),
         INT8_C(   5), -INT8_C(  54), -INT8_C(  61), -INT8_C(  86),  INT8_C(  43), -INT8_C(  61),  INT8_C( 108),  INT8_C(  66),
        -INT8_C(   9), -INT8_C(  16), -INT8_C( 107), -INT8_C( 110),  INT8_C(  12),  INT8_C(  63), -INT8_C(  45),  INT8_C(  86),
         INT8_C(  66),  INT8_C(  19),  INT8_C(  73),  INT8_C(  43), -INT8_C( 125), -INT8_C(  75),  INT8_C(  50), -INT8_C(  63),
         INT8_C(   6),  INT8_C(  47), -INT8_C(   3),  INT8_C( 114),  INT8_C(  70), -INT8_C( 116),  INT8_C(  15), -INT8_C(  26) },
      {  INT8_C(   0), -INT8_C( 106), -INT8_C(  11),  INT8_C(  47),  INT8_C(   0),  INT8_C(   0), -INT8_C(  25),  INT8_C(   0),
         INT8_C(  76),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(  37),  INT8_C(   0), -INT8_C(  82),  INT8_C(  89),
         INT8_C(   0),  INT8_C(   0), -INT8_C(  75),  INT8_C(   8), -INT8_C(  94),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
         INT8_C(   0),  INT8_C(  37),  INT8_C(   0),  INT8_C(   0),  INT8_C(  90),  INT8_C(   0),  INT8_C(   0), -INT8_C(  49),
         INT8_C(   0),  INT8_C(   0),  INT8_C(  81),  INT8_C(   0),  INT8_C(   0), -INT8_C( 107),  INT8_C(   0), -INT8_C( 110),
        -INT8_C(  58),  INT8_C(  12), -INT8_C(  57),  INT8_C(  63),  INT8_C(   0),  INT8_C(   0),  INT8_C(  46),  INT8_C(   0),
         INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   3),  INT8_C(   0),  INT8_C( 114),
         INT8_C(   2),  INT8_C(   0),  INT8_C(   0), -INT8_C( 116), -INT8_C(  79),  INT8_C(   0),  INT8_C(  34), -INT8_C(  26) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i a = simde_mm512_loadu_epi8(test_vec[i].a);
    simde__m512i b = simde_mm512_loadu_epi8(test_vec[i].b);
    simde__m512i r = simde_mm512_maskz_unpackhi_epi8(test_vec[i].k, a, b);
    simde_test_x86_assert_equal_i8x64(r, simde_mm512_loadu_epi8(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_mm256_mask_unpackhi_epi8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int8_t src[32];
    const simde__mmask32 k;
    const int8_t a[32];
    const int8_t b[32];
    const int8_t r[32];
  } test_vec[] = {
    { {  INT8_C(  90), -INT8_C(  66), -INT8_C( 106), -INT8_C( 105), -INT8_C(  94), -INT8_C(  44), -INT8_C(  50), -INT8_C(  18),
        -INT8_C(  78), -INT8_C(  66),  INT8_C(  22),  INT8_C(  67), -INT8_C(  29),  INT8_C(  87),  INT8_C( 119),      INT8_MAX,
         INT8_C(  37),  INT8_C(  94),  INT8_C(  12),  INT8_C(  75),  INT8_C(  54), -INT8_C(  68), -INT8_C(  31),  INT8_C( 125),
         INT8_C(  70), -INT8_C(  22),  INT8_C(   1),  INT8_C(  10),  INT8_C(  60),  INT8_C(  58), -INT8_C(  44), -INT8_C( 105) },
      UINT32_C(2603510521),
      {  INT8_C(  62), -INT8_C(   4), -INT8_C( 118), -INT8_C(  15), -INT8_C(  69), -INT8_C(  96),  INT8_C(  52), -INT8_C(  98),
        -INT8_C(   9), -INT8_C(  85),  INT8_C(  29),  INT8_C(  29),  INT8_C(   9),  INT8_C(  41),  INT8_C( 104),  INT8_C(  63),
        -INT8_C(  27),  INT8_C(  74), -INT8_C(  68),  INT8_C(  43),  INT8_C(  52), -INT8_C(  66),  INT8_C(  53),  INT8_C( 113),
        -INT8_C(   8),  INT8_C(   9),  INT8_C(   8), -INT8_C(  15),  INT8_C( 115),  INT8_C(  54), -INT8_C( 115), -INT8_C(  79) },
      {  INT8_C(  50),  INT8_C(  23), -INT8_C(  94), -INT8_C(  19), -INT8_C(  73), -INT8_C(  42), -INT8_C( 117), -INT8_C(  82),
        -INT8_C( 127), -INT8_C(  88), -INT8_C(  53), -INT8_C( 118), -INT8_C(  47),  INT8_C(  52), -INT8_C(  54), -INT8_C(  74),
         INT8_C( 126), -INT8_C( 122), -INT8_C(  31), -INT8_C(  78),  INT8_C(  68),  INT8_C(  22),  INT8_C(  35),  INT8_C(  61),
         INT8_C(  31),  INT8_C(  43),  INT8_C(  46), -INT8_C( 110),  INT8_C(  97), -INT8_C(  69),  INT8_C(  68), -INT8_C( 108) },
      { -INT8_C(   9), -INT8_C(  66), -INT8_C( 106), -INT8_C(  88),  INT8_C(  29), -INT8_C(  53),  INT8_C(  29), -INT8_C( 118),
        -INT8_C(  78), -INT8_C(  47),  INT8_C(  22),  INT8_C(  52), -INT8_C(  29), -INT8_C(  54),  INT8_C(  63),      INT8_MAX,
         INT8_C(  37),  INT8_C(  31),  INT8_C(   9),  INT8_C(  43),  INT8_C(  54),  INT8_C(  46), -INT8_C(  31),  INT8_C( 125),
         INT8_C( 115),  INT8_C(  97),  INT8_C(   1), -INT8_C(  69), -INT8_C( 115),  INT8_C(  58), -INT8_C(  44), -INT8_C( 108) } },
    { { -INT8_C(  46), -INT8_C(  26), -INT8_C( 127), -INT8_C( 119), -INT8_C(  67),  INT8_C(  13),  INT8_C(  56),  INT8_C(  62),
        -INT8_C(  75),  INT8_C(   3), -INT8_C(  55), -INT8_C( 121),  INT8_C(  55), -INT8_C( 109),  INT8_C(  61), -INT8_C(  75),
         INT8_C(  25),  INT8_C(  31),  INT8_C( 104),  INT8_C(  94),  INT8_C(  53), -INT8_C( 117), -INT8_C( 101),  INT8_C(  85),
        -INT8_C(  73), -INT8_C(  55), -INT8_C(  25),  INT8_C(  24), -INT8_C( 123),  INT8_C(  43), -INT8_C(  84),  INT8_C(  87) },
      UINT32_C(3487641106),
      {  INT8_C(  59),  INT8_C(  25),  INT8_C(  13), -INT8_C(  16),  INT8_C(  28), -INT8_C(  42),  INT8_C( 119),  INT8_C(  84),
         INT8_C( 105), -INT8_C(  75),  INT8_C(   9), -INT8_C( 125), -INT8_C(  44),  INT8_C( 113), -INT8_C(  31),  INT8_C(   9),
        -INT8_C(   3),  INT8_C( 124),  INT8_C(  94), -INT8_C(  76),  INT8_C(  69),  INT8_C(  70), -INT8_C(  52), -INT8_C(  54),
         INT8_C( 113),  INT8_C( 121),  INT8_C(  34), -INT8_C( 125), -INT8_C(  89),  INT8_C(   3),  INT8_C(  82), -INT8_C(  30) },
      {  INT8_C(  28),  INT8_C(  96), -INT8_C(  46),  INT8_C(  56),  INT8_C(  54),  INT8_C(  74), -INT8_C( 116), -INT8_C(  96),
        -INT8_C(   1), -INT8_C( 106),  INT8_C(  35), -INT8_C(  45),  INT8_C(   7),  INT8_C(   4), -INT8_C(  36),  INT8_C(   4),
             INT8_MIN,  INT8_C(  59), -INT8_C(  72), -INT8_C(  59), -INT8_C( 127), -INT8_C( 123), -INT8_C( 112), -INT8_C(  14),
        -INT8_C(   2), -INT8_C(  78),  INT8_C( 118), -INT8_C(  91), -INT8_C(  75), -INT8_C(  56), -INT8_C( 121), -INT8_C(  47) },
      { -INT8_C(  46), -INT8_C(   1), -INT8_C( 127), -INT8_C( 119),  INT8_C(   9),  INT8_C(  13),  INT8_C(  56),  INT8_C(  62),
        -INT8_C(  75),  INT8_C(   7),  INT8_C( 113),  INT8_C(   4),  INT8_C(  55), -INT8_C(  36),  INT8_C(  61), -INT8_C(  75),
         INT8_C( 113),  INT8_C(  31),  INT8_C( 104),  INT8_C(  94),  INT8_C(  53),  INT8_C( 118), -INT8_C( 125), -INT8_C(  91),
        -INT8_C(  89), -INT8_C(  75),  INT8_C(   3), -INT8_C(  56), -INT8_C( 123),  INT8_C(  43), -INT8_C(  30), -INT8_C(  47) } },
    { {  INT8_C(  40),  INT8_C(  89),  INT8_C(   9),  INT8_C(  95), -INT8_C(  93), -INT8_C( 106), -INT8_C(   1), -INT8_C(  94),
         INT8_C(  44),  INT8_C(  34),  INT8_C( 117),  INT8_C(  51),  INT8_C(  38),  INT8_C(  82),  INT8_C(  56), -INT8_C(  90),
        -INT8_C( 115), -INT8_C(  16),  INT8_C( 107),  INT8_C(  14),  INT8_C( 117), -INT8_C(   5),  INT8_C(   0),  INT8_C( 115),
        -INT8_C(  83),  INT8_C( 118),  INT8_C(  24),  INT8_C(  98),  INT8_C(  63), -INT8_C(  97),  INT8_C(  51),  INT8_C( 103) },
      UINT32_C(2630237689),
      { -INT8_C(  45), -INT8_C(  59),  INT8_C(  63), -INT8_C(   1), -INT8_C(  25), -INT8_C(  76),  INT8_C(  50),  INT8_C(  13),
         INT8_C(   6),  INT8_C( 106), -INT8_C(  77), -INT8_C( 109),  INT8_C(  91),  INT8_C(  31), -INT8_C(  95), -INT8_C(  48),
         INT8_C(  26), -INT8_C(  94),  INT8_C(  68), -INT8_C(  56),  INT8_C(  24),  INT8_C(  92),  INT8_C(  42),  INT8_C(  87),
        -INT8_C(   4),  INT8_C(  94), -INT8_C(  65), -INT8_C(  11), -INT8_C( 101), -INT8_C( 123), -INT8_C( 111),  INT8_C( 110) },
      {  INT8_C(  75), -INT8_C(  48),  INT8_C( 109),  INT8_C(  50), -INT8_C( 123), -INT8_C(  97),  INT8_C(  64), -INT8_C( 117),
         INT8_C(  10), -INT8_C(  13),  INT8_C(  31),  INT8_C( 101),  INT8_C(  18), -INT8_C(  64),  INT8_C(  53),  INT8_C(  45),
         INT8_C(  98),  INT8_C( 121), -INT8_C(  11),  INT8_C( 123), -INT8_C(  42),  INT8_C(  31), -INT8_C(  46), -INT8_C(  46),
         INT8_C( 125), -INT8_C( 111), -INT8_C(  57),  INT8_C(  24),  INT8_C(  23),  INT8_C(  88), -INT8_C( 122),  INT8_C(  98) },
      {  INT8_C(   6),  INT8_C(  89),  INT8_C(   9), -INT8_C(  13), -INT8_C(  77),  INT8_C(  31), -INT8_C( 109),  INT8_C( 101),
         INT8_C(  91),  INT8_C(  34),  INT8_C(  31), -INT8_C(  64), -INT8_C(  95),  INT8_C(  53),  INT8_C(  56), -INT8_C(  90),
        -INT8_C( 115),  INT8_C( 125),  INT8_C(  94),  INT8_C(  14),  INT8_C( 117), -INT8_C(   5), -INT8_C(  11),  INT8_C(  24),
        -INT8_C(  83),  INT8_C( 118), -INT8_C( 123),  INT8_C(  88), -INT8_C( 111), -INT8_C(  97),  INT8_C(  51),  INT8_C(  98) } },
    { {  INT8_C(  41), -INT8_C(  13), -INT8_C( 108), -INT8_C(  82), -INT8_C( 109), -INT8_C(  44),  INT8_C(  57), -INT8_C(  99),
        -INT8_C(  56),  INT8_C(  88),  INT8_C(   2), -INT8_C(  38),  INT8_C(  25),  INT8_C(  55),  INT8_C(   7),  INT8_C( 123),
        -INT8_C(  79), -INT8_C(   4), -INT8_C(  10), -INT8_C( 121),  INT8_C(  28), -INT8_C(  55),  INT8_C(  89), -INT8_C( 103),
         INT8_C(  90),  INT8_C(  32), -INT8_C(  78),  INT8_C( 113),  INT8_C( 120),  INT8_C(  56), -INT8_C(  45), -INT8_C(  95) },
      UINT32_C(3209652268),
      {  INT8_C(  60), -INT8_C( 119),  INT8_C(  92),  INT8_C(   4), -INT8_C(  31),  INT8_C(  94), -INT8_C(  33), -INT8_C(   6),
        -INT8_C( 107), -INT8_C(  26),  INT8_C( 118),  INT8_C(  70), -INT8_C(  29),  INT8_C( 108), -INT8_C(  51), -INT8_C(   1),
         INT8_C(  53),  INT8_C(  38), -INT8_C( 104), -INT8_C( 112),  INT8_C(  70),  INT8_C(  74),  INT8_C(   1), -INT8_C(  65),
        -INT8_C( 125), -INT8_C(  43),  INT8_C(  96), -INT8_C(  81),  INT8_C(  61), -INT8_C(  80),  INT8_C( 110),  INT8_C( 121) },
      {  INT8_C(  57), -INT8_C(  54),  INT8_C( 126),  INT8_C(  26),  INT8_C(  40),  INT8_C(  93),  INT8_C(  21), -INT8_C(  67),
         INT8_C(  67), -INT8_C( 117),  INT8_C(   4),  INT8_C(  38), -INT8_C(   9), -INT8_C(  47),  INT8_C(  37),  INT8_C(  45),
        -INT8_C(   8), -INT8_C(  66), -INT8_C(  67),  INT8_C(  62),  INT8_C(   8), -INT8_C(  66), -INT8_C(   3), -INT8_C( 117),
        -INT8_C( 109),  INT8_C(  94),  INT8_C(  58), -INT8_C(  48),  INT8_C(  14), -INT8_C(  88),  INT8_C(  74),  INT8_C(  71) },
      {  INT8_C(  41), -INT8_C(  13), -INT8_C(  26), -INT8_C( 117), -INT8_C( 109),  INT8_C(   4),  INT8_C(  57), -INT8_C(  99),
        -INT8_C(  56),  INT8_C(  88),  INT8_C(   2), -INT8_C(  47),  INT8_C(  25),  INT8_C(  37), -INT8_C(   1),  INT8_C( 123),
        -INT8_C( 125), -INT8_C( 109), -INT8_C(  43),  INT8_C(  94),  INT8_C(  28), -INT8_C(  55), -INT8_C(  81), -INT8_C( 103),
         INT8_C(  61),  INT8_C(  14), -INT8_C(  80), -INT8_C(  88),  INT8_C( 110),  INT8_C(  74), -INT8_C(  45),  INT8_C(  71) } },
    { {  INT8_C( 114), -INT8_C(  56),  INT8_C(  97), -INT8_C( 102),  INT8_C(  37),  INT8_C( 118),  INT8_C(  88),  INT8_C( 104),
         INT8_C(   1),  INT8_C(  92), -INT8_C( 113), -INT8_C(   7),  INT8_C(  45), -INT8_C(  76),  INT8_C(  38),  INT8_C(  37),
         INT8_C( 114), -INT8_C(  29),  INT8_C( 100),  INT8_C( 123), -INT8_C(  95),  INT8_C(  97),  INT8_C(   6),  INT8_C(  53),
        -INT8_C(  65),  INT8_C(  65),  INT8_C(   5), -INT8_C(  51), -INT8_C(  23),  INT8_C(  79),  INT8_C(  20),  INT8_C(  92) },
      UINT32_C(1022785047),
      { -INT8_C(  20),  INT8_C(  78), -INT8_C(  91), -INT8_C(  18), -INT8_C(  86),  INT8_C(  52), -INT8_C(  25), -INT8_C(  40),
        -INT8_C(  24),  INT8_C(  13), -INT8_C(   3),  INT8_C(  91), -INT8_C(  16),  INT8_C(  97), -INT8_C(  42), -INT8_C( 111),
        -INT8_C(  61), -INT8_C(  36), -INT8_C(  58), -INT8_C( 126),  INT8_C(  29), -INT8_C(  52),  INT8_C(  80),  INT8_C(   7),
         INT8_C(  27),  INT8_C( 100),  INT8_C(  99),  INT8_C(  51), -INT8_C(  38),  INT8_C(  89),  INT8_C( 111), -INT8_C(  57) },
      { -INT8_C(  88),  INT8_C(  20), -INT8_C(  75),  INT8_C(  82),  INT8_C(  72), -INT8_C( 100),  INT8_C(  42),  INT8_C(  49),
        -INT8_C(  87),  INT8_C(  40), -INT8_C( 116), -INT8_C( 103), -INT8_C( 119),  INT8_C(  98),  INT8_C(  42),  INT8_C(  76),
         INT8_C(  62), -INT8_C(  15), -INT8_C(  49),  INT8_C(  92), -INT8_C(  67),  INT8_C(  31),  INT8_C(  99), -INT8_C(  40),
        -INT8_C( 125), -INT8_C(  58),  INT8_C(  11),  INT8_C(  94),  INT8_C(  31),  INT8_C( 123),  INT8_C(  37), -INT8_C(  57) },
      { -INT8_C(  24), -INT8_C(  87),  INT8_C(  13), -INT8_C( 102), -INT8_C(   3),  INT8_C( 118),  INT8_C(  88),  INT8_C( 104),
         INT8_C(   1), -INT8_C( 119),  INT8_C(  97), -INT8_C(   7), -INT8_C(  42),  INT8_C(  42), -INT8_C( 111),  INT8_C(  37),
         INT8_C( 114), -INT8_C( 125),  INT8_C( 100),  INT8_C( 123),  INT8_C(  99),  INT8_C(  11),  INT8_C(  51),  INT8_C(  94),
        -INT8_C(  65),  INT8_C(  65),  INT8_C(  89),  INT8_C( 123),  INT8_C( 111),  INT8_C(  37),  INT8_C(  20),  INT8_C(  92) } },
    { { -INT8_C( 113), -INT8_C(  38),  INT8_C(  26), -INT8_C(  40),  INT8_C( 118),  INT8_C(  68),  INT8_C(   9),  INT8_C(  31),
         INT8_C( 108), -INT8_C( 107), -INT8_C(  72), -INT8_C(  10), -INT8_C(   9), -INT8_C(  30),  INT8_C(  66),  INT8_C(  53),
        -INT8_C(  45),  INT8_C(  17), -INT8_C( 111), -INT8_C( 112),  INT8_C(  48), -INT8_C(  12),  INT8_C( 105), -INT8_C(  76),
        -INT8_C(  70),  INT8_C( 116),  INT8_C(  18), -INT8_C(  38), -INT8_C(  17),  INT8_C(  55), -INT8_C(  95),      INT8_MAX },
      UINT32_C(2270673681),
      {  INT8_C(   0),  INT8_C(  96), -INT8_C(  90),  INT8_C( 108), -INT8_C(  11),  INT8_C(  94),  INT8_C(  98), -INT8_C(  20),
         INT8_C(  64), -INT8_C(  91),  INT8_C(  33),  INT8_C(  20), -INT8_C(  74), -INT8_C(  77), -INT8_C(  92), -INT8_C(  25),
        -INT8_C(  89),  INT8_C(  13), -INT8_C( 101),  INT8_C(  98), -INT8_C( 126), -INT8_C(  83),  INT8_C(  60),  INT8_C( 113),
        -INT8_C(  28), -INT8_C(  35), -INT8_C(  16), -INT8_C(  11), -INT8_C( 103),  INT8_C(  71),  INT8_C( 124), -INT8_C( 103) },
      { -INT8_C(  89),  INT8_C(  34),  INT8_C(   5), -INT8_C( 100),      INT8_MIN,  INT8_C( 104), -INT8_C( 120), -INT8_C(  64),
         INT8_C(  13), -INT8_C(  86), -INT8_C(  44), -INT8_C(  61),  INT8_C(  93),  INT8_C( 121), -INT8_C(  86),  INT8_C(   4),
        -INT8_C( 122),  INT8_C(  69),  INT8_C( 102),  INT8_C(   8), -INT8_C(  14), -INT8_C(  94),  INT8_C( 122), -INT8_C(  42),
             INT8_MIN,  INT8_C( 106), -INT8_C(  53),  INT8_C(  25), -INT8_C(  78),  INT8_C(  71), -INT8_C(  78),  INT8_C(  89) },
      {  INT8_C(  64), -INT8_C(  38),  INT8_C(  26), -INT8_C(  40),  INT8_C(  33),  INT8_C(  68),  INT8_C(   9),  INT8_C(  31),
        -INT8_C(  74),  INT8_C(  93), -INT8_C(  72),  INT8_C( 121), -INT8_C(  92), -INT8_C(  86),  INT8_C(  66),  INT8_C(   4),
        -INT8_C(  28),      INT8_MIN, -INT8_C(  35), -INT8_C( 112), -INT8_C(  16), -INT8_C(  12), -INT8_C(  11), -INT8_C(  76),
        -INT8_C( 103), -INT8_C(  78),  INT8_C(  71), -INT8_C(  38), -INT8_C(  17),  INT8_C(  55), -INT8_C(  95),  INT8_C(  89) } },
    { {  INT8_C( 105), -INT8_C(  73), -INT8_C(  10), -INT8_C(  23),  INT8_C(  31),  INT8_C( 126), -INT8_C(  86),  INT8_C(  44),
         INT8_C(  40),  INT8_C( 126), -INT8_C(  16), -INT8_C( 123), -INT8_C(   9), -INT8_C( 102), -INT8_C( 118),  INT8_C( 126),
        -INT8_C(  32), -INT8_C(  16), -INT8_C( 122), -INT8_C(  46), -INT8_C( 109),  INT8_C(   0), -INT8_C(  87),  INT8_C(  19),
         INT8_C( 107),  INT8_C( 116),  INT8_C(  44),  INT8_C(  29), -INT8_C(  68), -INT8_C(  34),  INT8_C( 118),  INT8_C(  37) },
      UINT32_C(3037686933),
      { -INT8_C(  21), -INT8_C(  71), -INT8_C(  31),  INT8_C(  19),  INT8_C(  55), -INT8_C(  47), -INT8_C( 103),  INT8_C(  47),
         INT8_C( 108),  INT8_C(  35), -INT8_C(  83),  INT8_C(  76),  INT8_C(  19),  INT8_C(  51),  INT8_C(  30), -INT8_C(  90),
         INT8_C(  52), -INT8_C(  57), -INT8_C(  71), -INT8_C(  97),  INT8_C(  60), -INT8_C(  27), -INT8_C(  68), -INT8_C(   8),
        -INT8_C(  61),  INT8_C(  50),  INT8_C(  29),  INT8_C(  89), -INT8_C(  97),  INT8_C(  44),  INT8_C(  14), -INT8_C( 118) },
      { -INT8_C(  27), -INT8_C(  17), -INT8_C(  99),  INT8_C(  29), -INT8_C(  63),  INT8_C(  54),  INT8_C(  76),  INT8_C(  45),
         INT8_C(  89), -INT8_C(   7),  INT8_C( 121),  INT8_C( 109),  INT8_C(  44), -INT8_C( 105),  INT8_C(  19),  INT8_C(  96),
         INT8_C(  95), -INT8_C(  51), -INT8_C(   1), -INT8_C( 101), -INT8_C(  78), -INT8_C(  69), -INT8_C( 109),  INT8_C( 118),
        -INT8_C(  18), -INT8_C(  80), -INT8_C(  49), -INT8_C( 115), -INT8_C(  35), -INT8_C(  35),  INT8_C(  23), -INT8_C(  62) },
      {  INT8_C( 108), -INT8_C(  73),  INT8_C(  35), -INT8_C(  23), -INT8_C(  83),  INT8_C( 126), -INT8_C(  86),  INT8_C( 109),
         INT8_C(  40),  INT8_C( 126),  INT8_C(  51), -INT8_C( 105), -INT8_C(   9),  INT8_C(  19), -INT8_C(  90),  INT8_C( 126),
        -INT8_C(  61), -INT8_C(  18),  INT8_C(  50), -INT8_C(  80), -INT8_C( 109),  INT8_C(   0), -INT8_C(  87),  INT8_C(  19),
        -INT8_C(  97),  INT8_C( 116),  INT8_C(  44),  INT8_C(  29),  INT8_C(  14),  INT8_C(  23),  INT8_C( 118), -INT8_C(  62) } },
    { { -INT8_C(  52), -INT8_C(  76), -INT8_C(  33), -INT8_C( 115), -INT8_C(  21),  INT8_C(  43), -INT8_C(  70),  INT8_C(  68),
         INT8_C(  36),  INT8_C(  51), -INT8_C(  79),  INT8_C(  81), -INT8_C(  53), -INT8_C(  59), -INT8_C(  79),  INT8_C(  42),
        -INT8_C( 110), -INT8_C(  79), -INT8_C(  59),  INT8_C(  68),  INT8_C( 108),  INT8_C(  88), -INT8_C(  70),  INT8_C(  90),
         INT8_C(   8), -INT8_C( 119), -INT8_C(  25), -INT8_C(  27),  INT8_C( 102), -INT8_C(   2), -INT8_C(  88),  INT8_C(  51) },
      UINT32_C(2663417779),
      { -INT8_C(  77),  INT8_C( 123), -INT8_C(  30), -INT8_C(  41), -INT8_C(  82), -INT8_C( 108),  INT8_C(  40),  INT8_C( 121),
         INT8_C(  89), -INT8_C(  38), -INT8_C(  93), -INT8_C(  21), -INT8_C( 117),  INT8_C( 104),  INT8_C(  47), -INT8_C(   9),
        -INT8_C(  64), -INT8_C(  22),  INT8_C(  82), -INT8_C(  55),  INT8_C( 115),  INT8_C(  57), -INT8_C(  82), -INT8_C(  38),
         INT8_C(  56),  INT8_C(  86),  INT8_C(  13), -INT8_C(  21), -INT8_C(  34), -INT8_C(  51), -INT8_C( 119), -INT8_C( 111) },
      {  INT8_C(  72),  INT8_C( 107),  INT8_C( 104), -INT8_C(   9), -INT8_C(   1), -INT8_C( 111),  INT8_C( 112),  INT8_C(  88),
         INT8_C( 107),  INT8_C(  20),  INT8_C(  67), -INT8_C(  10),  INT8_C( 124),  INT8_C( 115), -INT8_C(  19),  INT8_C(  61),
         INT8_C(  93),  INT8_C(  63),  INT8_C(   6), -INT8_C(  48),  INT8_C( 121), -INT8_C(  76), -INT8_C(  86), -INT8_C(  79),
         INT8_C(  11), -INT8_C(  73), -INT8_C( 100), -INT8_C(  23), -INT8_C( 123),  INT8_C(  37),  INT8_C( 122), -INT8_C(  51) },
      {  INT8_C(  89),  INT8_C( 107), -INT8_C(  33), -INT8_C( 115), -INT8_C(  93),  INT8_C(  67), -INT8_C(  70), -INT8_C(  10),
        -INT8_C( 117),  INT8_C( 124),  INT8_C( 104),  INT8_C(  81), -INT8_C(  53), -INT8_C(  59), -INT8_C(  79),  INT8_C(  61),
        -INT8_C( 110), -INT8_C(  79), -INT8_C(  59),  INT8_C(  68),  INT8_C( 108),  INT8_C(  88), -INT8_C(  21), -INT8_C(  23),
         INT8_C(   8), -INT8_C( 123), -INT8_C(  51),  INT8_C(  37), -INT8_C( 119), -INT8_C(   2), -INT8_C(  88), -INT8_C(  51) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256i src = simde_x_mm256_loadu_epi8(test_vec[i].src);
    simde__m256i a = simde_x_mm256_loadu_epi8(test_vec[i].a);
    simde__m256i b = simde_x_mm256_loadu_epi8(test_vec[i].b);
    simde__m256i r = simde_mm256_mask_unpackhi_epi8(src, test_vec[i].k, a, b);
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
    simde__m256i r = simde_mm256_mask_unpackhi_epi8(src, k, a, b);

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
test_simde_mm256_maskz_unpackhi_epi8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask32 k;
    const int8_t a[32];
    const int8_t b[32];
    const int8_t r[32];
  } test_vec[] = {
    { UINT32_C(2261391651),
      { -INT8_C(  49), -INT8_C(  72),  INT8_C( 110), -INT8_C( 113), -INT8_C(  70),  INT8_C( 126), -INT8_C(  11),  INT8_C(  95),
         INT8_C(  16),  INT8_C(  27),  INT8_C(  82),  INT8_C(  55), -INT8_C(  51),  INT8_C(  63),  INT8_C(  66),  INT8_C(  49),
        -INT8_C(  62), -INT8_C(   8), -INT8_C(  60),  INT8_C( 110), -INT8_C( 122), -INT8_C(  80),  INT8_C(  48), -INT8_C(  25),
        -INT8_C(  50), -INT8_C(  89),  INT8_C( 113), -INT8_C(  14), -INT8_C(  64),  INT8_C(  59),  INT8_C( 120), -INT8_C( 113) },
      { -INT8_C(  13), -INT8_C(  25),  INT8_C(  30), -INT8_C(  83),  INT8_C( 101),  INT8_C(  20),  INT8_C(  13),  INT8_C( 118),
         INT8_C(  47),  INT8_C(  95), -INT8_C(  83), -INT8_C(   4), -INT8_C(  98), -INT8_C(  17),  INT8_C(  45),  INT8_C(  96),
        -INT8_C(  25), -INT8_C(  15), -INT8_C(  50),  INT8_C( 110), -INT8_C(  95), -INT8_C(   2),  INT8_C(  85),  INT8_C( 112),
        -INT8_C(  91), -INT8_C(  58),  INT8_C(  98),  INT8_C( 102),  INT8_C(   1), -INT8_C(  38), -INT8_C(  11), -INT8_C(  11) },
      {  INT8_C(  16),  INT8_C(  47),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  83),  INT8_C(   0),  INT8_C(   0),
        -INT8_C(  51),  INT8_C(   0),  INT8_C(   0), -INT8_C(  17),  INT8_C(  66),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
         INT8_C(   0), -INT8_C(  91),  INT8_C(   0), -INT8_C(  58),  INT8_C(   0),  INT8_C(   0), -INT8_C(  14),  INT8_C( 102),
         INT8_C(   0),  INT8_C(   1),  INT8_C(  59),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  11) } },
    { UINT32_C( 664933569),
      {  INT8_C(  40), -INT8_C(  81), -INT8_C(  99),  INT8_C(  87),  INT8_C(  14),  INT8_C(  74),  INT8_C(  83), -INT8_C(  83),
         INT8_C(  58), -INT8_C( 127),  INT8_C(  13),  INT8_C(  33),  INT8_C( 114), -INT8_C(  36), -INT8_C( 113),  INT8_C(  20),
        -INT8_C(  38), -INT8_C(  28), -INT8_C( 124),      INT8_MIN, -INT8_C(  86), -INT8_C(  26), -INT8_C(  26), -INT8_C(  84),
        -INT8_C(  64), -INT8_C(  37), -INT8_C(  95), -INT8_C( 126), -INT8_C(  17),  INT8_C(  67), -INT8_C(  87),  INT8_C(  23) },
      { -INT8_C(  13),  INT8_C(  70),  INT8_C( 110),  INT8_C(   1), -INT8_C( 112), -INT8_C(  62), -INT8_C(  82), -INT8_C(  54),
         INT8_C(  67), -INT8_C(  68), -INT8_C(  20), -INT8_C(  75), -INT8_C( 104),  INT8_C( 123), -INT8_C(  55),  INT8_C( 114),
         INT8_C(  96),  INT8_C(  77), -INT8_C(  14),  INT8_C(  10),  INT8_C(  51), -INT8_C(  40), -INT8_C(  74), -INT8_C(  12),
        -INT8_C(  76),  INT8_C(  87),  INT8_C( 118), -INT8_C(  93), -INT8_C( 101),  INT8_C(  31), -INT8_C(  69), -INT8_C( 114) },
      {  INT8_C(  58),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(  33), -INT8_C(  75),
         INT8_C(   0),  INT8_C(   0), -INT8_C(  36),  INT8_C(   0), -INT8_C( 113),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
         INT8_C(   0), -INT8_C(  76),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C( 118),  INT8_C(   0), -INT8_C(  93),
        -INT8_C(  17), -INT8_C( 101),  INT8_C(  67),  INT8_C(   0),  INT8_C(   0), -INT8_C(  69),  INT8_C(   0),  INT8_C(   0) } },
    { UINT32_C(4119800165),
      { -INT8_C(  21),  INT8_C(  62), -INT8_C(  64),  INT8_C(  46), -INT8_C(   6), -INT8_C(  84), -INT8_C(  28), -INT8_C( 110),
         INT8_C(  39), -INT8_C(  83),  INT8_C(   4), -INT8_C( 121), -INT8_C(   5), -INT8_C(   9), -INT8_C( 110),  INT8_C(  46),
        -INT8_C(  49),  INT8_C(  72),  INT8_C(  34), -INT8_C( 125), -INT8_C(  96), -INT8_C( 104),  INT8_C(  39),  INT8_C(  59),
        -INT8_C(  73), -INT8_C(  30), -INT8_C(  55),  INT8_C(  28),  INT8_C(  11),  INT8_C(  88),  INT8_C(  18), -INT8_C(   9) },
      { -INT8_C( 106), -INT8_C(  46),  INT8_C(  37), -INT8_C( 112),  INT8_C( 126),  INT8_C(   9),  INT8_C(  34), -INT8_C(  91),
        -INT8_C(  73),  INT8_C(  39),  INT8_C(  45), -INT8_C(  78),  INT8_C(  30), -INT8_C(  65), -INT8_C(  32), -INT8_C(  19),
         INT8_C(   7),  INT8_C(   3),  INT8_C( 113), -INT8_C(  89), -INT8_C( 101), -INT8_C( 104), -INT8_C(  30),  INT8_C(  83),
         INT8_C( 122), -INT8_C(  85),  INT8_C( 111), -INT8_C( 123),  INT8_C(   4), -INT8_C( 127),  INT8_C( 124), -INT8_C( 102) },
      {  INT8_C(  39),  INT8_C(   0), -INT8_C(  83),  INT8_C(   0),  INT8_C(   0),  INT8_C(  45), -INT8_C( 121),  INT8_C(   0),
        -INT8_C(   5),  INT8_C(   0),  INT8_C(   0), -INT8_C(  65),  INT8_C(   0), -INT8_C(  32),  INT8_C(   0),  INT8_C(   0),
        -INT8_C(  73),  INT8_C( 122), -INT8_C(  30), -INT8_C(  85),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C( 123),
         INT8_C(  11),  INT8_C(   0),  INT8_C(  88),  INT8_C(   0),  INT8_C(  18),  INT8_C( 124), -INT8_C(   9), -INT8_C( 102) } },
    { UINT32_C(3509297747),
      { -INT8_C(  85),  INT8_C(  77),  INT8_C( 119),  INT8_C(  98),  INT8_C( 116), -INT8_C(  92),  INT8_C(  20), -INT8_C( 110),
         INT8_C(  99), -INT8_C(  11),      INT8_MIN,  INT8_C( 106), -INT8_C(   8), -INT8_C(  15),  INT8_C(  18), -INT8_C( 109),
        -INT8_C( 119), -INT8_C(  12), -INT8_C(  26),  INT8_C(   3), -INT8_C(  96),  INT8_C(  86), -INT8_C( 120), -INT8_C(  92),
        -INT8_C(  41),  INT8_C(   5),  INT8_C(  62),  INT8_C(  43), -INT8_C(  89),  INT8_C( 105), -INT8_C(   4),  INT8_C(  82) },
      { -INT8_C(  73),  INT8_C( 115), -INT8_C(  75),  INT8_C(  43),  INT8_C(  23), -INT8_C(  55), -INT8_C(  66),  INT8_C( 122),
        -INT8_C(  66),  INT8_C(  62), -INT8_C(  27), -INT8_C(  74),  INT8_C(  47), -INT8_C(   9),  INT8_C(  74), -INT8_C(  72),
        -INT8_C(  21),  INT8_C(  48), -INT8_C(  69), -INT8_C( 117), -INT8_C( 122),  INT8_C(  67),  INT8_C(  47),  INT8_C(  94),
         INT8_C(  72),  INT8_C( 110), -INT8_C( 119), -INT8_C(  17), -INT8_C(  41), -INT8_C( 123),  INT8_C(  66), -INT8_C( 114) },
      {  INT8_C(  99), -INT8_C(  66),  INT8_C(   0),  INT8_C(   0),      INT8_MIN,  INT8_C(   0),  INT8_C( 106),  INT8_C(   0),
         INT8_C(   0),  INT8_C(  47),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(  74),  INT8_C(   0), -INT8_C(  72),
        -INT8_C(  41),  INT8_C(  72),  INT8_C(   0),  INT8_C( 110),  INT8_C(   0), -INT8_C( 119),  INT8_C(   0),  INT8_C(   0),
        -INT8_C(  89),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   4),  INT8_C(   0),  INT8_C(  82), -INT8_C( 114) } },
    { UINT32_C( 280688633),
      { -INT8_C(  64),  INT8_C( 120), -INT8_C( 117),      INT8_MAX, -INT8_C(  74),  INT8_C( 112),  INT8_C(  53), -INT8_C(  27),
         INT8_C( 103),      INT8_MAX, -INT8_C(  99),  INT8_C(  82), -INT8_C(  80),  INT8_C(  88), -INT8_C(  34),  INT8_C(  54),
        -INT8_C( 101),  INT8_C(  13), -INT8_C( 108), -INT8_C(  28),  INT8_C( 123),  INT8_C(  29), -INT8_C(  45),  INT8_C(  83),
        -INT8_C(  93),  INT8_C(  21), -INT8_C(  31), -INT8_C( 100),  INT8_C(  12), -INT8_C( 101), -INT8_C(  84), -INT8_C(  51) },
      {  INT8_C(  19),  INT8_C(  55),  INT8_C(  76), -INT8_C(  55), -INT8_C(  89), -INT8_C( 127), -INT8_C(  82),  INT8_C(  14),
         INT8_C(   1),  INT8_C(  75),  INT8_C(  97), -INT8_C(  79), -INT8_C(  93),  INT8_C(  63), -INT8_C(  25),  INT8_C(  63),
         INT8_C(  76),  INT8_C( 124),  INT8_C(  35), -INT8_C(  56), -INT8_C( 103), -INT8_C(  10),  INT8_C(  27),  INT8_C(  60),
         INT8_C(  12), -INT8_C(   4), -INT8_C(  40),  INT8_C(  24), -INT8_C( 104), -INT8_C( 123), -INT8_C(  27), -INT8_C(  85) },
      {  INT8_C( 103),  INT8_C(   0),  INT8_C(   0),  INT8_C(  75), -INT8_C(  99),  INT8_C(  97),  INT8_C(  82), -INT8_C(  79),
        -INT8_C(  80), -INT8_C(  93),  INT8_C(  88),  INT8_C(   0), -INT8_C(  34), -INT8_C(  25),  INT8_C(  54),  INT8_C(  63),
         INT8_C(   0),  INT8_C(  12),  INT8_C(   0), -INT8_C(   4), -INT8_C(  31), -INT8_C(  40),  INT8_C(   0),  INT8_C(  24),
         INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  84),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0) } },
    { UINT32_C(1685402044),
      { -INT8_C(  77),  INT8_C(  35),  INT8_C( 114), -INT8_C(  76),  INT8_C( 111), -INT8_C(  45),  INT8_C( 101),  INT8_C(  18),
         INT8_C(  18),  INT8_C(  76),  INT8_C(  81),  INT8_C(  95), -INT8_C(  56),  INT8_C( 116),  INT8_C(  39),  INT8_C(  98),
         INT8_C( 107),  INT8_C(  66), -INT8_C(  98),  INT8_C( 119),  INT8_C(  62),  INT8_C( 119), -INT8_C( 113), -INT8_C(  42),
        -INT8_C(   4),  INT8_C( 117), -INT8_C( 126), -INT8_C(  72), -INT8_C(  90), -INT8_C(   9),  INT8_C(  28),  INT8_C(  89) },
      {  INT8_C(  26), -INT8_C( 113),  INT8_C(  13), -INT8_C( 119),  INT8_C(  98),  INT8_C( 114), -INT8_C( 100),  INT8_C( 117),
        -INT8_C(  65), -INT8_C(  19), -INT8_C(  44), -INT8_C( 121),  INT8_C(  98), -INT8_C(   5), -INT8_C(  23), -INT8_C(  51),
         INT8_C(  61), -INT8_C( 120),  INT8_C(  68),  INT8_C( 123), -INT8_C(   1), -INT8_C(  45),  INT8_C(  82), -INT8_C(   5),
         INT8_C(  72), -INT8_C(  44), -INT8_C(  77), -INT8_C(  17), -INT8_C(  53), -INT8_C(  48),  INT8_C(  72), -INT8_C(  27) },
      {  INT8_C(   0),  INT8_C(   0),  INT8_C(  76), -INT8_C(  19),  INT8_C(  81), -INT8_C(  44),  INT8_C(   0), -INT8_C( 121),
        -INT8_C(  56),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(  39), -INT8_C(  23),  INT8_C(   0),  INT8_C(   0),
        -INT8_C(   4),  INT8_C(   0),  INT8_C( 117),  INT8_C(   0), -INT8_C( 126), -INT8_C(  77), -INT8_C(  72),  INT8_C(   0),
         INT8_C(   0),  INT8_C(   0), -INT8_C(   9),  INT8_C(   0),  INT8_C(   0),  INT8_C(  72),  INT8_C(  89),  INT8_C(   0) } },
    { UINT32_C(3245299295),
      { -INT8_C(  56),  INT8_C(  11),  INT8_C(  54), -INT8_C( 121), -INT8_C(   8),  INT8_C(  10),  INT8_C(  15),  INT8_C(  90),
         INT8_C(   5), -INT8_C(   8),  INT8_C(  39),  INT8_C(  66),      INT8_MIN,  INT8_C( 107), -INT8_C(  66),      INT8_MAX,
         INT8_C(  63),  INT8_C(  16),  INT8_C( 122), -INT8_C( 121), -INT8_C(  28),  INT8_C(  46),  INT8_C( 118), -INT8_C(  81),
        -INT8_C(   2), -INT8_C(  65), -INT8_C( 108),  INT8_C(  93),  INT8_C(  21),  INT8_C(   3),  INT8_C(  30), -INT8_C(  35) },
      {  INT8_C(  14),  INT8_C(  85),  INT8_C( 101),  INT8_C(   7),  INT8_C(  95),  INT8_C( 116),  INT8_C(  97),  INT8_C( 101),
         INT8_C( 108), -INT8_C( 119), -INT8_C(  89), -INT8_C(  19), -INT8_C(  12),  INT8_C( 101),  INT8_C( 108),  INT8_C(  51),
         INT8_C( 117), -INT8_C(  25), -INT8_C(  69),  INT8_C(  89),  INT8_C(  21),  INT8_C(  49),  INT8_C(   8),  INT8_C(  19),
        -INT8_C(  16), -INT8_C(  99),  INT8_C( 112),  INT8_C(   5), -INT8_C(  96), -INT8_C( 114), -INT8_C(  29), -INT8_C(  81) },
      {  INT8_C(   5),  INT8_C( 108), -INT8_C(   8), -INT8_C( 119),  INT8_C(  39),  INT8_C(   0),  INT8_C(  66),  INT8_C(   0),
         INT8_C(   0), -INT8_C(  12),  INT8_C( 107),  INT8_C(   0), -INT8_C(  66),  INT8_C(   0),      INT8_MAX,  INT8_C(   0),
        -INT8_C(   2), -INT8_C(  16), -INT8_C(  65), -INT8_C(  99),  INT8_C(   0),  INT8_C( 112),  INT8_C(  93),  INT8_C(   0),
         INT8_C(  21),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  35), -INT8_C(  81) } },
    { UINT32_C(1136019683),
      { -INT8_C(  68),  INT8_C(  23), -INT8_C(  88),  INT8_C(  40), -INT8_C(  96),  INT8_C(  79),  INT8_C(  21), -INT8_C( 107),
        -INT8_C(  75), -INT8_C( 126), -INT8_C(  56),  INT8_C(  42),  INT8_C( 105), -INT8_C( 125), -INT8_C( 124),  INT8_C( 126),
        -INT8_C(  75), -INT8_C( 116), -INT8_C( 111), -INT8_C(  91),  INT8_C(  41),  INT8_C(   1), -INT8_C(  85), -INT8_C(  54),
        -INT8_C( 113), -INT8_C( 114),  INT8_C( 121),  INT8_C( 115), -INT8_C(  42),  INT8_C(  47), -INT8_C(  74), -INT8_C( 110) },
      {  INT8_C(  70),  INT8_C(  94), -INT8_C(  70), -INT8_C(  25), -INT8_C(  83), -INT8_C(  48),  INT8_C( 124),  INT8_C(  98),
         INT8_C(  82),  INT8_C(  68), -INT8_C( 115), -INT8_C(  69), -INT8_C(  56),  INT8_C(  17),  INT8_C(  57),  INT8_C( 125),
        -INT8_C(  99), -INT8_C(  54),  INT8_C(  34), -INT8_C(  57), -INT8_C(  53), -INT8_C(  51), -INT8_C( 111),  INT8_C(  90),
         INT8_C(  91),  INT8_C(  10), -INT8_C(  51),  INT8_C(  49),  INT8_C(  57), -INT8_C( 125), -INT8_C(  61),      INT8_MAX },
      { -INT8_C(  75),  INT8_C(  82),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C( 115),  INT8_C(  42), -INT8_C(  69),
         INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(  17),  INT8_C(   0),  INT8_C(   0),  INT8_C( 126),  INT8_C(   0),
         INT8_C(   0),  INT8_C(  91), -INT8_C( 114),  INT8_C(   0),  INT8_C( 121), -INT8_C(  51),  INT8_C(   0),  INT8_C(  49),
        -INT8_C(  42),  INT8_C(  57),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C( 110),  INT8_C(   0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256i a = simde_x_mm256_loadu_epi8(test_vec[i].a);
    simde__m256i b = simde_x_mm256_loadu_epi8(test_vec[i].b);
    simde__m256i r = simde_mm256_maskz_unpackhi_epi8(test_vec[i].k, a, b);
    simde_test_x86_assert_equal_i8x32(r, simde_x_mm256_loadu_epi8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask32 k = simde_test_x86_random_mmask32();
    simde__m256i a = simde_test_x86_random_i8x32();
    simde__m256i b = simde_test_x86_random_i8x32();
    simde__m256i r = simde_mm256_maskz_unpackhi_epi8(k, a, b);

    simde_test_x86_write_mmask32(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i8x32(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i8x32(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i8x32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_mask_unpackhi_epi8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int8_t src[16];
    const simde__mmask16 k;
    const int8_t a[16];
    const int8_t b[16];
    const int8_t r[16];
  } test_vec[] = {
    { { -INT8_C( 117),  INT8_C(  90),  INT8_C(  17), -INT8_C(  75),  INT8_C( 119),  INT8_C(  97),  INT8_C(   6), -INT8_C( 107),
         INT8_C(  38),  INT8_C( 116),  INT8_C(  88), -INT8_C(  66), -INT8_C(   4), -INT8_C(  70), -INT8_C(   9),  INT8_C(  28) },
      UINT16_C(21300),
      { -INT8_C(  88),  INT8_C(  45),  INT8_C(  20), -INT8_C(   8),  INT8_C( 114), -INT8_C(  22),      INT8_MIN, -INT8_C(  36),
        -INT8_C(   4), -INT8_C( 114),  INT8_C(  40), -INT8_C(  65),  INT8_C(  49), -INT8_C(  76),  INT8_C(  25),  INT8_C(  66) },
      {  INT8_C( 105), -INT8_C( 112), -INT8_C(  92),  INT8_C( 112),  INT8_C(  38), -INT8_C(  54), -INT8_C(  28),  INT8_C( 126),
        -INT8_C( 119), -INT8_C(  32),  INT8_C(  56),      INT8_MIN, -INT8_C(   4),  INT8_C( 109), -INT8_C(  45), -INT8_C(  91) },
      { -INT8_C( 117),  INT8_C(  90), -INT8_C( 114), -INT8_C(  75),  INT8_C(  40),  INT8_C(  56),  INT8_C(   6), -INT8_C( 107),
         INT8_C(  49), -INT8_C(   4),  INT8_C(  88), -INT8_C(  66),  INT8_C(  25), -INT8_C(  70),  INT8_C(  66),  INT8_C(  28) } },
    { { -INT8_C( 102), -INT8_C(  25), -INT8_C(  99),  INT8_C(  12), -INT8_C(  47),  INT8_C(  30), -INT8_C(  23), -INT8_C(  51),
        -INT8_C(  84),  INT8_C(  17), -INT8_C( 116), -INT8_C(  35), -INT8_C(  59), -INT8_C(  90),  INT8_C(  32),  INT8_C(  47) },
      UINT16_C(50230),
      { -INT8_C(  97),  INT8_C(  92), -INT8_C( 114), -INT8_C( 125), -INT8_C(  38),  INT8_C(  23),  INT8_C(  99),  INT8_C(  19),
        -INT8_C( 105),  INT8_C(  95),      INT8_MIN,  INT8_C( 107),  INT8_C(   4),  INT8_C(  26),  INT8_C(  82), -INT8_C(  94) },
      {  INT8_C(  39),  INT8_C(  36), -INT8_C(  64),  INT8_C(  16), -INT8_C(  15),  INT8_C( 108),  INT8_C(  33),  INT8_C( 126),
         INT8_C(  73), -INT8_C(  25),  INT8_C(  36),  INT8_C( 105),  INT8_C(  22),  INT8_C(  90),  INT8_C(  45), -INT8_C(  75) },
      { -INT8_C( 102),  INT8_C(  73),  INT8_C(  95),  INT8_C(  12),      INT8_MIN,  INT8_C(  36), -INT8_C(  23), -INT8_C(  51),
        -INT8_C(  84),  INT8_C(  17),  INT8_C(  26), -INT8_C(  35), -INT8_C(  59), -INT8_C(  90), -INT8_C(  94), -INT8_C(  75) } },
    { { -INT8_C(  73), -INT8_C(  68),  INT8_C(  56), -INT8_C( 111), -INT8_C(  45), -INT8_C( 101), -INT8_C(  92),  INT8_C( 107),
        -INT8_C(   6),  INT8_C(  36), -INT8_C(  42), -INT8_C(   1),  INT8_C(  63),  INT8_C(  40), -INT8_C(  95),  INT8_C( 102) },
      UINT16_C(24908),
      {  INT8_C( 118),  INT8_C(  62), -INT8_C(  51), -INT8_C( 105), -INT8_C(  68),  INT8_C(  22),  INT8_C( 126), -INT8_C(  32),
             INT8_MIN, -INT8_C( 108),  INT8_C(  58), -INT8_C(  83),  INT8_C(  73), -INT8_C(  15),  INT8_C( 105), -INT8_C( 127) },
      { -INT8_C( 125),  INT8_C(  61),  INT8_C(  28),  INT8_C(  39), -INT8_C(  88),  INT8_C(  23),  INT8_C(  76),  INT8_C( 126),
         INT8_C(  22), -INT8_C( 117), -INT8_C(  90), -INT8_C(  73), -INT8_C(  15), -INT8_C(  13),  INT8_C(  24),  INT8_C( 103) },
      { -INT8_C(  73), -INT8_C(  68), -INT8_C( 108), -INT8_C( 117), -INT8_C(  45), -INT8_C( 101), -INT8_C(  83),  INT8_C( 107),
         INT8_C(  73),  INT8_C(  36), -INT8_C(  42), -INT8_C(   1),  INT8_C(  63),  INT8_C(  24), -INT8_C( 127),  INT8_C( 102) } },
    { {  INT8_C(  49), -INT8_C(  27), -INT8_C(   2), -INT8_C(  19), -INT8_C(   5),  INT8_C( 125), -INT8_C(  51),  INT8_C( 123),
         INT8_C(  17),  INT8_C(   7),  INT8_C(  41),  INT8_C(  91), -INT8_C(   7), -INT8_C( 110), -INT8_C(  36),  INT8_C( 124) },
      UINT16_C(63951),
      { -INT8_C(  93),  INT8_C( 119),  INT8_C(  16), -INT8_C(  17), -INT8_C(  11),  INT8_C(  38),  INT8_C( 122), -INT8_C( 100),
        -INT8_C(  35),  INT8_C( 107), -INT8_C( 113), -INT8_C(  11), -INT8_C(  46), -INT8_C(  64), -INT8_C(  38), -INT8_C(  47) },
      { -INT8_C(  83), -INT8_C(  43),  INT8_C(  78),  INT8_C( 122),  INT8_C(  81),  INT8_C(  95), -INT8_C( 127),  INT8_C( 122),
        -INT8_C(  70),  INT8_C( 122),  INT8_C(  12), -INT8_C( 105), -INT8_C(  10), -INT8_C(  36), -INT8_C( 112), -INT8_C( 102) },
      { -INT8_C(  35), -INT8_C(  70),  INT8_C( 107),  INT8_C( 122), -INT8_C(   5),  INT8_C( 125), -INT8_C(  11), -INT8_C( 105),
        -INT8_C(  46),  INT8_C(   7),  INT8_C(  41), -INT8_C(  36), -INT8_C(  38), -INT8_C( 112), -INT8_C(  47), -INT8_C( 102) } },
    { {  INT8_C(  83), -INT8_C(  96), -INT8_C( 119),  INT8_C(  73), -INT8_C(  58),  INT8_C(   4), -INT8_C(  27), -INT8_C(  93),
         INT8_C( 111),  INT8_C( 116), -INT8_C( 104),  INT8_C(  66),  INT8_C(  52),  INT8_C( 114),  INT8_C(  19), -INT8_C(  31) },
      UINT16_C(24903),
      {  INT8_C(  91), -INT8_C( 104), -INT8_C(  64), -INT8_C(  36),  INT8_C(  18),  INT8_C( 123),  INT8_C(  87),  INT8_C(  31),
         INT8_C(  18),  INT8_C(  77), -INT8_C(   5), -INT8_C(  94), -INT8_C(  25),  INT8_C(  78),  INT8_C(  66),  INT8_C( 113) },
      { -INT8_C( 105),  INT8_C(   8),  INT8_C( 117),  INT8_C( 124), -INT8_C(  85), -INT8_C(  28), -INT8_C(  16),  INT8_C(  67),
         INT8_C(  38),  INT8_C(  36), -INT8_C(  75),  INT8_C(  57),  INT8_C(   5), -INT8_C(   4), -INT8_C( 102),  INT8_C(  96) },
      {  INT8_C(  18),  INT8_C(  38),  INT8_C(  77),  INT8_C(  73), -INT8_C(  58),  INT8_C(   4), -INT8_C(  94), -INT8_C(  93),
        -INT8_C(  25),  INT8_C( 116), -INT8_C( 104),  INT8_C(  66),  INT8_C(  52), -INT8_C( 102),  INT8_C( 113), -INT8_C(  31) } },
    { { -INT8_C( 107),  INT8_C(  91),  INT8_C(  61), -INT8_C(  89), -INT8_C(  42), -INT8_C( 108), -INT8_C(  58), -INT8_C(  24),
        -INT8_C(  31), -INT8_C(  63), -INT8_C( 118), -INT8_C(  55),  INT8_C(  16), -INT8_C(  52),  INT8_C(  58), -INT8_C(  89) },
      UINT16_C(45012),
      {  INT8_C(  36),      INT8_MAX, -INT8_C( 109),  INT8_C(  20), -INT8_C(  62), -INT8_C(  70),  INT8_C(  57),  INT8_C( 119),
        -INT8_C(  13),  INT8_C(  62),  INT8_C( 115), -INT8_C( 114), -INT8_C(  97),  INT8_C(   8), -INT8_C(  23), -INT8_C(  36) },
      { -INT8_C(  80), -INT8_C(  65),  INT8_C( 112),  INT8_C( 118), -INT8_C(  89),  INT8_C(  81),  INT8_C(  56),  INT8_C(  49),
         INT8_C(  26),  INT8_C(  72), -INT8_C(   3),  INT8_C(  84), -INT8_C(  17), -INT8_C(  47),  INT8_C(   3),  INT8_C(  19) },
      { -INT8_C( 107),  INT8_C(  91),  INT8_C(  62), -INT8_C(  89),  INT8_C( 115), -INT8_C( 108), -INT8_C( 114),  INT8_C(  84),
        -INT8_C(  97), -INT8_C(  17),  INT8_C(   8), -INT8_C(  47),  INT8_C(  16),  INT8_C(   3),  INT8_C(  58),  INT8_C(  19) } },
    { {  INT8_C(  80), -INT8_C( 105),  INT8_C(  40),  INT8_C(  18),  INT8_C(  81),  INT8_C(  97), -INT8_C( 119),  INT8_C(  68),
        -INT8_C(  97), -INT8_C(   4), -INT8_C(  46),  INT8_C(  62),  INT8_C(   5), -INT8_C(  69),  INT8_C(  26), -INT8_C(  75) },
      UINT16_C(35450),
      {  INT8_C(  43),  INT8_C(  33), -INT8_C(  36),  INT8_C(  99),  INT8_C(  82), -INT8_C(  10), -INT8_C(  85),  INT8_C(  79),
         INT8_C(  75), -INT8_C( 101),  INT8_C(  32),  INT8_C(  78), -INT8_C(  82),  INT8_C( 112), -INT8_C(  27), -INT8_C(  42) },
      { -INT8_C( 126),  INT8_C(  54),  INT8_C(  55),  INT8_C(  11),  INT8_C( 123), -INT8_C(  41),  INT8_C(   8),  INT8_C(  77),
         INT8_C(  21),  INT8_C(  13),  INT8_C(   9),  INT8_C(  48), -INT8_C(  62), -INT8_C( 125), -INT8_C(  70), -INT8_C(  19) },
      {  INT8_C(  80),  INT8_C(  21),  INT8_C(  40),  INT8_C(  13),  INT8_C(  32),  INT8_C(   9),  INT8_C(  78),  INT8_C(  68),
        -INT8_C(  97), -INT8_C(  62), -INT8_C(  46), -INT8_C( 125),  INT8_C(   5), -INT8_C(  69),  INT8_C(  26), -INT8_C(  19) } },
    { { -INT8_C(  91), -INT8_C( 106),  INT8_C(  81), -INT8_C(   9), -INT8_C( 115), -INT8_C(   4),  INT8_C(  71), -INT8_C(  40),
        -INT8_C( 105),  INT8_C( 103),  INT8_C(  38),  INT8_C(  70), -INT8_C(  40),  INT8_C(  12),  INT8_C(  28),  INT8_C(  90) },
      UINT16_C(21570),
      {  INT8_C( 102), -INT8_C(  67),  INT8_C(  43),  INT8_C( 110),  INT8_C(  11),  INT8_C(  64),  INT8_C( 123),  INT8_C(  20),
         INT8_C( 112),  INT8_C(  61), -INT8_C( 105),  INT8_C(  43),  INT8_C(  42),  INT8_C(  60), -INT8_C(  63),  INT8_C( 123) },
      {  INT8_C(  52),  INT8_C(  78),  INT8_C( 120),  INT8_C( 123),  INT8_C(  38),  INT8_C(  15), -INT8_C(  30),  INT8_C(  77),
         INT8_C(  85), -INT8_C(  70),  INT8_C(  89),  INT8_C( 114),  INT8_C(  21), -INT8_C( 101), -INT8_C(  58),  INT8_C( 123) },
      { -INT8_C(  91),  INT8_C(  85),  INT8_C(  81), -INT8_C(   9), -INT8_C( 115), -INT8_C(   4),  INT8_C(  43), -INT8_C(  40),
        -INT8_C( 105),  INT8_C( 103),  INT8_C(  60),  INT8_C(  70), -INT8_C(  63),  INT8_C(  12),  INT8_C( 123),  INT8_C(  90) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i src = simde_mm_loadu_epi8(test_vec[i].src);
    simde__m128i a = simde_mm_loadu_epi8(test_vec[i].a);
    simde__m128i b = simde_mm_loadu_epi8(test_vec[i].b);
    simde__m128i r = simde_mm_mask_unpackhi_epi8(src, test_vec[i].k, a, b);
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
    simde__m128i r = simde_mm_mask_unpackhi_epi8(src, k, a, b);

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
test_simde_mm512_unpackhi_epi16 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const int16_t a[32];
    const int16_t b[32];
    const int16_t r[32];
  } test_vec[] = {
    { { -INT16_C( 31862), -INT16_C( 28008), -INT16_C( 17358), -INT16_C(  9367), -INT16_C(  8035),  INT16_C( 28789),  INT16_C(  9734),  INT16_C( 32189),
        -INT16_C( 29888),  INT16_C( 14371),  INT16_C( 13788), -INT16_C( 27397),  INT16_C( 24497), -INT16_C(  8132), -INT16_C( 27140), -INT16_C( 30909),
        -INT16_C(  9447),  INT16_C( 19225), -INT16_C( 32105),  INT16_C( 13350), -INT16_C( 25502),  INT16_C( 26788),  INT16_C( 25026),  INT16_C(   741),
         INT16_C(  2541), -INT16_C( 14021),  INT16_C( 13886), -INT16_C(  4003), -INT16_C( 26219), -INT16_C( 28208),  INT16_C(  5167),  INT16_C( 18456) },
      {  INT16_C( 12783), -INT16_C( 30829), -INT16_C( 17997),  INT16_C(  5563),  INT16_C( 24661),  INT16_C(  6270),  INT16_C( 25537), -INT16_C( 20966),
         INT16_C( 21868), -INT16_C( 21641), -INT16_C( 10869),  INT16_C(  8347),  INT16_C( 27502), -INT16_C( 25166), -INT16_C( 13697),  INT16_C( 28645),
         INT16_C( 30972), -INT16_C( 20490), -INT16_C( 20174), -INT16_C( 30779),  INT16_C( 17169), -INT16_C( 11361), -INT16_C( 17754),  INT16_C(  4993),
        -INT16_C(  1777), -INT16_C( 25666),  INT16_C( 22990),  INT16_C( 15547),  INT16_C( 28100),  INT16_C( 17626), -INT16_C( 16584),  INT16_C( 13491) },
      { -INT16_C(  8035),  INT16_C( 24661),  INT16_C( 28789),  INT16_C(  6270),  INT16_C(  9734),  INT16_C( 25537),  INT16_C( 32189), -INT16_C( 20966),
         INT16_C( 24497),  INT16_C( 27502), -INT16_C(  8132), -INT16_C( 25166), -INT16_C( 27140), -INT16_C( 13697), -INT16_C( 30909),  INT16_C( 28645),
        -INT16_C( 25502),  INT16_C( 17169),  INT16_C( 26788), -INT16_C( 11361),  INT16_C( 25026), -INT16_C( 17754),  INT16_C(   741),  INT16_C(  4993),
        -INT16_C( 26219),  INT16_C( 28100), -INT16_C( 28208),  INT16_C( 17626),  INT16_C(  5167), -INT16_C( 16584),  INT16_C( 18456),  INT16_C( 13491) } },
    { { -INT16_C( 22216),  INT16_C( 27363), -INT16_C( 22438),  INT16_C( 27889), -INT16_C( 28181), -INT16_C( 28097), -INT16_C( 16309),  INT16_C( 23205),
         INT16_C( 25529), -INT16_C( 30731), -INT16_C( 20036), -INT16_C( 32572), -INT16_C( 25058),  INT16_C( 22212),  INT16_C( 30557), -INT16_C( 27254),
         INT16_C( 28192),  INT16_C( 31743), -INT16_C(  3818),  INT16_C(   743),  INT16_C(  9858), -INT16_C( 12908),  INT16_C( 14822), -INT16_C( 24537),
         INT16_C(  7580),  INT16_C( 22567), -INT16_C(  5170), -INT16_C(  4904), -INT16_C( 25207), -INT16_C(  6333), -INT16_C( 13036),  INT16_C( 13692) },
      {  INT16_C( 31803),  INT16_C( 21168), -INT16_C( 26771), -INT16_C(  4268), -INT16_C(  5955), -INT16_C( 23620), -INT16_C(  7391), -INT16_C( 17085),
         INT16_C( 27392), -INT16_C( 12779), -INT16_C(  4778), -INT16_C(  8005), -INT16_C(   374), -INT16_C( 24633),  INT16_C( 17355),  INT16_C(  2004),
        -INT16_C( 31553),  INT16_C( 11353), -INT16_C( 21221), -INT16_C( 10213), -INT16_C( 10347), -INT16_C( 18821), -INT16_C( 16453), -INT16_C( 17549),
        -INT16_C( 30678), -INT16_C( 32630),  INT16_C( 17781),  INT16_C(    96),  INT16_C( 10051),  INT16_C(  3743),  INT16_C( 29547),  INT16_C( 10773) },
      { -INT16_C( 28181), -INT16_C(  5955), -INT16_C( 28097), -INT16_C( 23620), -INT16_C( 16309), -INT16_C(  7391),  INT16_C( 23205), -INT16_C( 17085),
        -INT16_C( 25058), -INT16_C(   374),  INT16_C( 22212), -INT16_C( 24633),  INT16_C( 30557),  INT16_C( 17355), -INT16_C( 27254),  INT16_C(  2004),
         INT16_C(  9858), -INT16_C( 10347), -INT16_C( 12908), -INT16_C( 18821),  INT16_C( 14822), -INT16_C( 16453), -INT16_C( 24537), -INT16_C( 17549),
        -INT16_C( 25207),  INT16_C( 10051), -INT16_C(  6333),  INT16_C(  3743), -INT16_C( 13036),  INT16_C( 29547),  INT16_C( 13692),  INT16_C( 10773) } },
    { {  INT16_C( 28407),  INT16_C(  4695),  INT16_C( 29211), -INT16_C( 20246),  INT16_C( 25930),  INT16_C(  1382), -INT16_C(  9948),  INT16_C( 20160),
         INT16_C( 19041), -INT16_C( 10289),  INT16_C( 12175), -INT16_C( 11561),  INT16_C( 30295), -INT16_C( 15647), -INT16_C(  2327), -INT16_C(  7956),
         INT16_C( 17253), -INT16_C( 32526), -INT16_C(  9034),  INT16_C(    49), -INT16_C( 26815),  INT16_C( 26117), -INT16_C( 14991), -INT16_C( 11596),
        -INT16_C( 31984), -INT16_C( 24663), -INT16_C( 32589),  INT16_C(  2674),  INT16_C( 21494), -INT16_C(  8244), -INT16_C( 18359), -INT16_C( 20801) },
      { -INT16_C( 19972), -INT16_C( 19921),  INT16_C( 24717), -INT16_C( 12366), -INT16_C( 18441),  INT16_C( 26677), -INT16_C(  5764), -INT16_C( 29637),
        -INT16_C(  7059),  INT16_C(  8236), -INT16_C( 24987),  INT16_C( 23338), -INT16_C(  2319),  INT16_C( 14907), -INT16_C(  1362), -INT16_C( 21783),
         INT16_C(  6316),  INT16_C( 14684),  INT16_C(  3704),  INT16_C( 28424),  INT16_C( 15813),  INT16_C( 17112),  INT16_C(  4903), -INT16_C( 27442),
        -INT16_C(  1289),  INT16_C( 23732), -INT16_C(  8552), -INT16_C( 30280), -INT16_C(  3116), -INT16_C( 32060), -INT16_C( 21011), -INT16_C( 26323) },
      {  INT16_C( 25930), -INT16_C( 18441),  INT16_C(  1382),  INT16_C( 26677), -INT16_C(  9948), -INT16_C(  5764),  INT16_C( 20160), -INT16_C( 29637),
         INT16_C( 30295), -INT16_C(  2319), -INT16_C( 15647),  INT16_C( 14907), -INT16_C(  2327), -INT16_C(  1362), -INT16_C(  7956), -INT16_C( 21783),
        -INT16_C( 26815),  INT16_C( 15813),  INT16_C( 26117),  INT16_C( 17112), -INT16_C( 14991),  INT16_C(  4903), -INT16_C( 11596), -INT16_C( 27442),
         INT16_C( 21494), -INT16_C(  3116), -INT16_C(  8244), -INT16_C( 32060), -INT16_C( 18359), -INT16_C( 21011), -INT16_C( 20801), -INT16_C( 26323) } },
    { { -INT16_C( 30267),  INT16_C( 15827), -INT16_C(  9320),  INT16_C( 23980), -INT16_C( 31719),  INT16_C( 16543),  INT16_C( 28311), -INT16_C( 28716),
        -INT16_C( 30616),  INT16_C(   491), -INT16_C( 23706),  INT16_C( 14986),  INT16_C( 20118), -INT16_C( 31556), -INT16_C(  5637), -INT16_C( 16355),
        -INT16_C(  3981),  INT16_C(  3069), -INT16_C( 21812), -INT16_C(  6808),  INT16_C(  2094), -INT16_C( 14811), -INT16_C(  1674), -INT16_C(  8619),
         INT16_C( 16513), -INT16_C(  6177),  INT16_C( 27364),  INT16_C( 31265), -INT16_C(  8776), -INT16_C( 19202),  INT16_C(  7367),  INT16_C( 14964) },
      {  INT16_C( 29196), -INT16_C( 10171), -INT16_C( 21220),  INT16_C( 19133), -INT16_C(  7499),  INT16_C( 11024),  INT16_C( 26075),  INT16_C( 23562),
        -INT16_C(  5722), -INT16_C( 30141),  INT16_C( 25683),  INT16_C(  3076),  INT16_C(   834),  INT16_C(  2496),  INT16_C( 13343),  INT16_C( 11075),
        -INT16_C( 30554), -INT16_C( 15868), -INT16_C( 16075), -INT16_C(  5363),  INT16_C(  7588),  INT16_C( 32534),  INT16_C(  8323),  INT16_C( 10716),
         INT16_C(  7946),  INT16_C( 23987), -INT16_C( 18556), -INT16_C( 14743),  INT16_C( 10682), -INT16_C(  9777),  INT16_C(  4702),  INT16_C(  1029) },
      { -INT16_C( 31719), -INT16_C(  7499),  INT16_C( 16543),  INT16_C( 11024),  INT16_C( 28311),  INT16_C( 26075), -INT16_C( 28716),  INT16_C( 23562),
         INT16_C( 20118),  INT16_C(   834), -INT16_C( 31556),  INT16_C(  2496), -INT16_C(  5637),  INT16_C( 13343), -INT16_C( 16355),  INT16_C( 11075),
         INT16_C(  2094),  INT16_C(  7588), -INT16_C( 14811),  INT16_C( 32534), -INT16_C(  1674),  INT16_C(  8323), -INT16_C(  8619),  INT16_C( 10716),
        -INT16_C(  8776),  INT16_C( 10682), -INT16_C( 19202), -INT16_C(  9777),  INT16_C(  7367),  INT16_C(  4702),  INT16_C( 14964),  INT16_C(  1029) } },
    { {  INT16_C(  2458), -INT16_C( 12345), -INT16_C( 11062),  INT16_C( 28346), -INT16_C( 11791),  INT16_C( 29934), -INT16_C( 13583), -INT16_C(  1123),
         INT16_C( 20713),  INT16_C( 27993), -INT16_C( 15864), -INT16_C( 15821),  INT16_C(   748),  INT16_C( 19100), -INT16_C( 24300), -INT16_C( 20914),
         INT16_C(  5546),  INT16_C( 29822),  INT16_C( 14569), -INT16_C(  9245), -INT16_C( 12023), -INT16_C(  1201), -INT16_C(  4709), -INT16_C( 31498),
         INT16_C( 20285),  INT16_C( 17906),  INT16_C(  9490), -INT16_C(   504), -INT16_C( 23512),  INT16_C( 15432), -INT16_C( 27067), -INT16_C(  4117) },
      {  INT16_C( 27052), -INT16_C( 27293),  INT16_C( 18081), -INT16_C( 21648), -INT16_C( 16361), -INT16_C( 19802), -INT16_C( 25427), -INT16_C(  5577),
         INT16_C( 10732), -INT16_C(   464),  INT16_C( 14414),  INT16_C( 30460),  INT16_C( 17628),  INT16_C(  8627), -INT16_C( 24870), -INT16_C( 31216),
         INT16_C( 29447), -INT16_C( 22500), -INT16_C( 29510), -INT16_C( 11949), -INT16_C(  1716), -INT16_C(  1660), -INT16_C( 17514), -INT16_C( 32028),
         INT16_C(  5348),  INT16_C( 12928),  INT16_C( 31820),  INT16_C( 10409),  INT16_C( 23744), -INT16_C( 26039),  INT16_C( 23034),  INT16_C(   289) },
      { -INT16_C( 11791), -INT16_C( 16361),  INT16_C( 29934), -INT16_C( 19802), -INT16_C( 13583), -INT16_C( 25427), -INT16_C(  1123), -INT16_C(  5577),
         INT16_C(   748),  INT16_C( 17628),  INT16_C( 19100),  INT16_C(  8627), -INT16_C( 24300), -INT16_C( 24870), -INT16_C( 20914), -INT16_C( 31216),
        -INT16_C( 12023), -INT16_C(  1716), -INT16_C(  1201), -INT16_C(  1660), -INT16_C(  4709), -INT16_C( 17514), -INT16_C( 31498), -INT16_C( 32028),
        -INT16_C( 23512),  INT16_C( 23744),  INT16_C( 15432), -INT16_C( 26039), -INT16_C( 27067),  INT16_C( 23034), -INT16_C(  4117),  INT16_C(   289) } },
    { {  INT16_C( 15820), -INT16_C( 31063), -INT16_C(   567),  INT16_C(  5720), -INT16_C(  8970), -INT16_C( 29681), -INT16_C(  3177),  INT16_C( 31502),
        -INT16_C( 29177),  INT16_C( 21421),  INT16_C( 22026), -INT16_C( 13701), -INT16_C( 15182), -INT16_C( 21403), -INT16_C( 31203), -INT16_C(  5459),
         INT16_C( 22467), -INT16_C( 29584), -INT16_C( 14252),  INT16_C( 19106), -INT16_C( 19804),  INT16_C( 15319), -INT16_C(  6747), -INT16_C( 21066),
         INT16_C( 25716),  INT16_C( 32256),  INT16_C( 31930),  INT16_C( 27977), -INT16_C( 20928),  INT16_C( 24089), -INT16_C( 14540), -INT16_C(  2232) },
      { -INT16_C( 18402),  INT16_C( 29315),  INT16_C(  9857),  INT16_C(  9660), -INT16_C( 27688),  INT16_C( 32097),  INT16_C(  6009), -INT16_C(  4822),
         INT16_C( 11131),  INT16_C( 13931), -INT16_C( 19289), -INT16_C(  6237), -INT16_C( 17310), -INT16_C( 27067), -INT16_C( 29309), -INT16_C( 24179),
         INT16_C(  4422), -INT16_C( 14573), -INT16_C( 12233),  INT16_C(  4076),  INT16_C( 19811), -INT16_C(  9076), -INT16_C( 18587), -INT16_C(  7991),
         INT16_C( 13794), -INT16_C( 30442), -INT16_C( 17943),  INT16_C( 19568), -INT16_C( 18826), -INT16_C(  1566),  INT16_C( 28739), -INT16_C( 30309) },
      { -INT16_C(  8970), -INT16_C( 27688), -INT16_C( 29681),  INT16_C( 32097), -INT16_C(  3177),  INT16_C(  6009),  INT16_C( 31502), -INT16_C(  4822),
        -INT16_C( 15182), -INT16_C( 17310), -INT16_C( 21403), -INT16_C( 27067), -INT16_C( 31203), -INT16_C( 29309), -INT16_C(  5459), -INT16_C( 24179),
        -INT16_C( 19804),  INT16_C( 19811),  INT16_C( 15319), -INT16_C(  9076), -INT16_C(  6747), -INT16_C( 18587), -INT16_C( 21066), -INT16_C(  7991),
        -INT16_C( 20928), -INT16_C( 18826),  INT16_C( 24089), -INT16_C(  1566), -INT16_C( 14540),  INT16_C( 28739), -INT16_C(  2232), -INT16_C( 30309) } },
    { { -INT16_C( 20863), -INT16_C( 18352),  INT16_C( 15742), -INT16_C(  7481),  INT16_C( 21386), -INT16_C(  4162), -INT16_C( 30710), -INT16_C(  4912),
        -INT16_C(  6467), -INT16_C( 22923), -INT16_C(  6496),  INT16_C(  5874), -INT16_C( 10852), -INT16_C(  8433), -INT16_C( 21947), -INT16_C( 14743),
        -INT16_C( 18087), -INT16_C( 10370),  INT16_C( 17910), -INT16_C( 32327),  INT16_C( 30872), -INT16_C( 23696),  INT16_C( 16384), -INT16_C( 17009),
         INT16_C(  1319), -INT16_C( 14493),  INT16_C( 22251), -INT16_C( 30755), -INT16_C(  5077),  INT16_C( 28774), -INT16_C( 12393), -INT16_C(  4042) },
      { -INT16_C( 19319),  INT16_C( 32711), -INT16_C( 32263), -INT16_C( 28416),  INT16_C( 29177), -INT16_C(  1740), -INT16_C( 15183), -INT16_C( 10058),
         INT16_C(  6601), -INT16_C( 19297),  INT16_C( 31855), -INT16_C( 26053), -INT16_C( 24215),  INT16_C(    10),  INT16_C( 16497), -INT16_C(  1296),
        -INT16_C( 18444), -INT16_C(  4743),  INT16_C( 31288),  INT16_C( 12671), -INT16_C( 19477), -INT16_C( 25558), -INT16_C(  8073),  INT16_C( 16501),
         INT16_C(  5370),  INT16_C( 27124),  INT16_C( 12177), -INT16_C(  1532),  INT16_C(  3793),  INT16_C( 17146), -INT16_C(  5553),  INT16_C( 17212) },
      {  INT16_C( 21386),  INT16_C( 29177), -INT16_C(  4162), -INT16_C(  1740), -INT16_C( 30710), -INT16_C( 15183), -INT16_C(  4912), -INT16_C( 10058),
        -INT16_C( 10852), -INT16_C( 24215), -INT16_C(  8433),  INT16_C(    10), -INT16_C( 21947),  INT16_C( 16497), -INT16_C( 14743), -INT16_C(  1296),
         INT16_C( 30872), -INT16_C( 19477), -INT16_C( 23696), -INT16_C( 25558),  INT16_C( 16384), -INT16_C(  8073), -INT16_C( 17009),  INT16_C( 16501),
        -INT16_C(  5077),  INT16_C(  3793),  INT16_C( 28774),  INT16_C( 17146), -INT16_C( 12393), -INT16_C(  5553), -INT16_C(  4042),  INT16_C( 17212) } },
    { { -INT16_C( 19039), -INT16_C(  9679), -INT16_C( 20433),  INT16_C(  6667),  INT16_C( 13923), -INT16_C(  9289),  INT16_C( 11286),  INT16_C(  4123),
         INT16_C(  4160), -INT16_C( 11910),  INT16_C( 32319),  INT16_C(  4299), -INT16_C( 14964), -INT16_C(  9390), -INT16_C( 29009),  INT16_C( 20767),
         INT16_C( 20548),  INT16_C( 29483),  INT16_C( 13824),  INT16_C( 25486),  INT16_C( 17772), -INT16_C( 31938),  INT16_C( 23153), -INT16_C( 20077),
         INT16_C(  3434), -INT16_C( 22141),  INT16_C( 20107),  INT16_C(  6330),  INT16_C(  3092), -INT16_C( 15373),  INT16_C(  4763), -INT16_C(  8428) },
      {  INT16_C( 16226),  INT16_C( 25170), -INT16_C(  8074), -INT16_C(  7482),  INT16_C(  1061), -INT16_C( 27035), -INT16_C(  1698), -INT16_C( 14264),
        -INT16_C( 13562), -INT16_C( 28046),  INT16_C( 11289),  INT16_C( 11690), -INT16_C( 25288), -INT16_C( 11279),  INT16_C(  1456),  INT16_C(  4786),
         INT16_C(  1349), -INT16_C( 17547),  INT16_C( 15333),  INT16_C(  2973),  INT16_C(   831), -INT16_C( 24927), -INT16_C(  5636),  INT16_C(   614),
        -INT16_C( 10060), -INT16_C( 12652),  INT16_C( 15876),  INT16_C( 15867), -INT16_C(  4900), -INT16_C( 29680), -INT16_C( 15374),  INT16_C( 14238) },
      {  INT16_C( 13923),  INT16_C(  1061), -INT16_C(  9289), -INT16_C( 27035),  INT16_C( 11286), -INT16_C(  1698),  INT16_C(  4123), -INT16_C( 14264),
        -INT16_C( 14964), -INT16_C( 25288), -INT16_C(  9390), -INT16_C( 11279), -INT16_C( 29009),  INT16_C(  1456),  INT16_C( 20767),  INT16_C(  4786),
         INT16_C( 17772),  INT16_C(   831), -INT16_C( 31938), -INT16_C( 24927),  INT16_C( 23153), -INT16_C(  5636), -INT16_C( 20077),  INT16_C(   614),
         INT16_C(  3092), -INT16_C(  4900), -INT16_C( 15373), -INT16_C( 29680),  INT16_C(  4763), -INT16_C( 15374), -INT16_C(  8428),  INT16_C( 14238) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i a = simde_mm512_loadu_epi16(test_vec[i].a);
    simde__m512i b = simde_mm512_loadu_epi16(test_vec[i].b);
    simde__m512i r = simde_mm512_unpackhi_epi16(a, b);
    simde_test_x86_assert_equal_i16x32(r, simde_mm512_loadu_epi16(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_mm_maskz_unpackhi_epi8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask16 k;
    const int8_t a[16];
    const int8_t b[16];
    const int8_t r[16];
  } test_vec[] = {
    { UINT16_C( 6928),
      {  INT8_C(  83),  INT8_C(  38),  INT8_C(  15), -INT8_C(   8), -INT8_C(  33),  INT8_C( 112), -INT8_C( 118), -INT8_C(  47),
         INT8_C(  60), -INT8_C(  37),  INT8_C(  22),  INT8_C(  58),  INT8_C(  89),  INT8_C(  60), -INT8_C( 110),  INT8_C(   1) },
      { -INT8_C( 124),  INT8_C( 114),  INT8_C(  83), -INT8_C(  25), -INT8_C(  98), -INT8_C(  72),  INT8_C(  64), -INT8_C(  42),
         INT8_C(  62), -INT8_C(  22),  INT8_C(  98),  INT8_C(  18), -INT8_C(  20),  INT8_C( 115),  INT8_C(  46),  INT8_C(  63) },
      {  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(  22),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
         INT8_C(  89), -INT8_C(  20),  INT8_C(   0),  INT8_C( 115), -INT8_C( 110),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0) } },
    { UINT16_C(15769),
      {  INT8_C(  55),  INT8_C( 120), -INT8_C(  83), -INT8_C(  63),  INT8_C(  73), -INT8_C(  23), -INT8_C( 100),  INT8_C(  95),
         INT8_C(  35), -INT8_C(  11), -INT8_C( 101), -INT8_C(  75), -INT8_C(  10),  INT8_C(  32),  INT8_C(  39),  INT8_C(  73) },
      {  INT8_C(   7), -INT8_C(  59),  INT8_C(   2),  INT8_C(  71), -INT8_C( 101),  INT8_C(  64),  INT8_C(  50), -INT8_C(   2),
         INT8_C(  83),  INT8_C(  30),  INT8_C( 113), -INT8_C( 127),  INT8_C(  93),  INT8_C(  10), -INT8_C(  66), -INT8_C( 108) },
      {  INT8_C(  35),  INT8_C(   0),  INT8_C(   0),  INT8_C(  30), -INT8_C( 101),  INT8_C(   0),  INT8_C(   0), -INT8_C( 127),
        -INT8_C(  10),  INT8_C(   0),  INT8_C(  32),  INT8_C(  10),  INT8_C(  39), -INT8_C(  66),  INT8_C(   0),  INT8_C(   0) } },
    { UINT16_C(27522),
      {  INT8_C(  85), -INT8_C(  53),  INT8_C(  84), -INT8_C(  15),  INT8_C(  42),  INT8_C( 119), -INT8_C(  26), -INT8_C(  58),
         INT8_C(  44), -INT8_C(  35), -INT8_C(  26),  INT8_C(  83),  INT8_C(  38), -INT8_C(  19),  INT8_C(  25),  INT8_C(  40) },
      {  INT8_C(  52), -INT8_C(  76),  INT8_C( 105),  INT8_C( 102), -INT8_C(  78), -INT8_C(  68), -INT8_C( 124),  INT8_C(  35),
         INT8_C(  61), -INT8_C(  31),  INT8_C(  45), -INT8_C(   5),  INT8_C( 117), -INT8_C(  81),  INT8_C( 102), -INT8_C(  54) },
      {  INT8_C(   0),  INT8_C(  61),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   5),
         INT8_C(  38),  INT8_C( 117),  INT8_C(   0), -INT8_C(  81),  INT8_C(   0),  INT8_C( 102),  INT8_C(  40),  INT8_C(   0) } },
    { UINT16_C(47738),
      { -INT8_C(  69), -INT8_C(  91),  INT8_C(  49), -INT8_C(  94),  INT8_C( 107),  INT8_C(  93),      INT8_MAX,  INT8_C(  81),
        -INT8_C(  80), -INT8_C(  91),  INT8_C(  62), -INT8_C(  55), -INT8_C(  50),  INT8_C( 114),  INT8_C( 126),  INT8_C(  55) },
      { -INT8_C(  39),  INT8_C(  48), -INT8_C(  13),  INT8_C(  93),  INT8_C(  84),  INT8_C(  48),  INT8_C(  63), -INT8_C( 127),
         INT8_C(  43), -INT8_C(  76),  INT8_C(  49), -INT8_C( 111),      INT8_MAX, -INT8_C(  85),  INT8_C(  75),  INT8_C(  58) },
      {  INT8_C(   0),  INT8_C(  43),  INT8_C(   0), -INT8_C(  76),  INT8_C(  62),  INT8_C(  49), -INT8_C(  55),  INT8_C(   0),
         INT8_C(   0),      INT8_MAX,  INT8_C(   0), -INT8_C(  85),  INT8_C( 126),  INT8_C(  75),  INT8_C(   0),  INT8_C(  58) } },
    { UINT16_C(31824),
      { -INT8_C(  36), -INT8_C(  69), -INT8_C(  39),  INT8_C(  91),  INT8_C(  12), -INT8_C( 119),  INT8_C(   1),  INT8_C(  74),
         INT8_C(  83), -INT8_C(  49), -INT8_C(  67), -INT8_C(  47),  INT8_C(   6), -INT8_C( 106),  INT8_C(   1), -INT8_C(   7) },
      { -INT8_C(  13),  INT8_C(  85),  INT8_C(  41),  INT8_C(  50), -INT8_C(  41),  INT8_C(  84), -INT8_C(  25),  INT8_C(   8),
        -INT8_C(  27),  INT8_C( 102), -INT8_C(  77),  INT8_C(  48), -INT8_C(  96),  INT8_C(   4), -INT8_C(  84),  INT8_C( 125) },
      {  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  67),  INT8_C(   0), -INT8_C(  47),  INT8_C(   0),
         INT8_C(   0),  INT8_C(   0), -INT8_C( 106),  INT8_C(   4),  INT8_C(   1), -INT8_C(  84), -INT8_C(   7),  INT8_C(   0) } },
    { UINT16_C(34239),
      { -INT8_C(  40), -INT8_C(  52),  INT8_C(  14), -INT8_C(  39),  INT8_C(  22),  INT8_C(  97), -INT8_C(  88), -INT8_C(  45),
         INT8_C(  50), -INT8_C(  82),  INT8_C( 105),  INT8_C(  52), -INT8_C(  89),  INT8_C(  93), -INT8_C( 119), -INT8_C(  48) },
      { -INT8_C( 113),  INT8_C(  96),  INT8_C(  36),  INT8_C( 118),  INT8_C( 104),  INT8_C(   9), -INT8_C(  36),  INT8_C(  28),
         INT8_C(  57),  INT8_C( 125),  INT8_C(  32), -INT8_C(  27), -INT8_C(   6), -INT8_C(  33),  INT8_C( 106), -INT8_C(  46) },
      {  INT8_C(  50),  INT8_C(  57), -INT8_C(  82),  INT8_C( 125),  INT8_C( 105),  INT8_C(  32),  INT8_C(   0), -INT8_C(  27),
        -INT8_C(  89),  INT8_C(   0),  INT8_C(  93),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  46) } },
    { UINT16_C(31147),
      { -INT8_C(  84), -INT8_C(  62), -INT8_C(  38),  INT8_C(  84), -INT8_C( 107),  INT8_C(  13),  INT8_C(   3), -INT8_C(   1),
         INT8_C(  65), -INT8_C(  86),  INT8_C(  92), -INT8_C(  54),  INT8_C( 123), -INT8_C(  21),  INT8_C(  43), -INT8_C(  97) },
      {  INT8_C(  98), -INT8_C( 109), -INT8_C(  87),  INT8_C(  62), -INT8_C(  81), -INT8_C(  30), -INT8_C(  69), -INT8_C(  49),
        -INT8_C(  56), -INT8_C(  75), -INT8_C(  81),  INT8_C(  50), -INT8_C( 120),  INT8_C(  90), -INT8_C(  85),  INT8_C(  52) },
      {  INT8_C(  65), -INT8_C(  56),  INT8_C(   0), -INT8_C(  75),  INT8_C(   0), -INT8_C(  81),  INT8_C(   0),  INT8_C(  50),
         INT8_C( 123),  INT8_C(   0),  INT8_C(   0),  INT8_C(  90),  INT8_C(  43), -INT8_C(  85), -INT8_C(  97),  INT8_C(   0) } },
    { UINT16_C(34332),
      { -INT8_C( 120), -INT8_C(  78), -INT8_C( 109), -INT8_C( 117), -INT8_C(  79), -INT8_C(  44),  INT8_C(  54),  INT8_C(  13),
        -INT8_C(  98), -INT8_C(  79), -INT8_C(   8), -INT8_C(  55),  INT8_C(  80),  INT8_C(  90),  INT8_C(  93), -INT8_C(   7) },
      { -INT8_C( 103),  INT8_C(  12), -INT8_C(  36),  INT8_C(  84), -INT8_C(  36), -INT8_C(  92),  INT8_C(  10), -INT8_C( 117),
        -INT8_C(  42), -INT8_C( 110), -INT8_C(  27), -INT8_C( 126), -INT8_C(  58),  INT8_C(   2),  INT8_C(   8),  INT8_C(  78) },
      {  INT8_C(   0),  INT8_C(   0), -INT8_C(  79), -INT8_C( 110), -INT8_C(   8),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
         INT8_C(   0), -INT8_C(  58),  INT8_C(  90),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(  78) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_x_mm_loadu_epi8(test_vec[i].a);
    simde__m128i b = simde_x_mm_loadu_epi8(test_vec[i].b);
    simde__m128i r = simde_mm_maskz_unpackhi_epi8(test_vec[i].k, a, b);
    simde_test_x86_assert_equal_i8x16(r, simde_x_mm_loadu_epi8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask16 k = simde_test_x86_random_mmask16();
    simde__m128i a = simde_test_x86_random_i8x16();
    simde__m128i b = simde_test_x86_random_i8x16();
    simde__m128i r = simde_mm_maskz_unpackhi_epi8(k, a, b);

    simde_test_x86_write_mmask16(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i8x16(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i8x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i8x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_mask_unpackhi_epi16 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const int16_t src[32];
    const simde__mmask32 k;
    const int16_t a[32];
    const int16_t b[32];
    const int16_t r[32];
  } test_vec[] = {
    { {  INT16_C( 27404),  INT16_C( 14898),  INT16_C(   956),  INT16_C(  8286), -INT16_C(  9167), -INT16_C( 28939), -INT16_C( 23261), -INT16_C( 21730),
        -INT16_C( 18437), -INT16_C( 23643), -INT16_C(  7882), -INT16_C( 22201), -INT16_C(  1304),  INT16_C(  6099),  INT16_C(  6423),  INT16_C( 26613),
        -INT16_C( 15814), -INT16_C(   495), -INT16_C( 30970),  INT16_C( 11012),  INT16_C( 10310), -INT16_C( 12798),  INT16_C( 25997),  INT16_C(   828),
         INT16_C( 17628),  INT16_C( 16888),  INT16_C( 20782), -INT16_C(  1807), -INT16_C( 19919),  INT16_C( 23316),  INT16_C( 20982),  INT16_C(  9513) },
      UINT32_C(3281474170),
      { -INT16_C( 10999),  INT16_C( 15076),  INT16_C(  4558), -INT16_C( 25737),  INT16_C(  3094), -INT16_C( 11382),  INT16_C( 21395), -INT16_C( 12020),
         INT16_C( 22329), -INT16_C( 18273),  INT16_C( 28988),  INT16_C(  3093),  INT16_C( 10978),  INT16_C( 30531),  INT16_C( 14987), -INT16_C(   908),
         INT16_C(  1833), -INT16_C( 21846),  INT16_C(  7965), -INT16_C( 32241), -INT16_C( 28677),  INT16_C( 11658), -INT16_C( 12230),  INT16_C( 25269),
        -INT16_C( 15334),  INT16_C( 23931), -INT16_C( 21628), -INT16_C(  5755), -INT16_C( 32735), -INT16_C( 16868), -INT16_C(  5159), -INT16_C( 26551) },
      { -INT16_C(  3747), -INT16_C( 32059), -INT16_C(  3828),  INT16_C( 17090), -INT16_C(  2562), -INT16_C( 26588),  INT16_C( 28868), -INT16_C(  1972),
         INT16_C( 11937),  INT16_C(   152),  INT16_C( 16414),  INT16_C(  2506),  INT16_C( 23138),  INT16_C(  2357),  INT16_C(  3285),  INT16_C( 12967),
        -INT16_C(  6594),  INT16_C( 20879), -INT16_C( 10456), -INT16_C(  1442),  INT16_C( 13928),  INT16_C( 32675),  INT16_C( 19165),  INT16_C(  2402),
        -INT16_C(  1724),  INT16_C( 31131), -INT16_C( 31019), -INT16_C( 21839),  INT16_C( 23239), -INT16_C( 15538), -INT16_C( 21852),  INT16_C( 20575) },
      {  INT16_C( 27404), -INT16_C(  2562),  INT16_C(   956), -INT16_C( 26588),  INT16_C( 21395),  INT16_C( 28868), -INT16_C( 12020), -INT16_C( 21730),
        -INT16_C( 18437),  INT16_C( 23138), -INT16_C(  7882), -INT16_C( 22201),  INT16_C( 14987),  INT16_C(  6099), -INT16_C(   908),  INT16_C( 26613),
        -INT16_C( 28677),  INT16_C( 13928),  INT16_C( 11658),  INT16_C( 11012), -INT16_C( 12230), -INT16_C( 12798),  INT16_C( 25997),  INT16_C(  2402),
        -INT16_C( 32735),  INT16_C( 23239),  INT16_C( 20782), -INT16_C(  1807), -INT16_C( 19919),  INT16_C( 23316), -INT16_C( 26551),  INT16_C( 20575) } },
    { { -INT16_C( 24230), -INT16_C( 25235), -INT16_C( 22849), -INT16_C( 17737),  INT16_C( 12370),  INT16_C( 20871), -INT16_C( 21136),  INT16_C( 23210),
        -INT16_C(  6012), -INT16_C( 28647), -INT16_C( 25235), -INT16_C( 23120), -INT16_C( 21717),  INT16_C( 24492), -INT16_C(  1920),  INT16_C(  8052),
         INT16_C( 12436),  INT16_C(  9523),  INT16_C( 18908),  INT16_C(  9488),  INT16_C(  6234), -INT16_C( 25047),  INT16_C( 17782),  INT16_C( 15752),
         INT16_C( 32414), -INT16_C( 14616),  INT16_C(  8792), -INT16_C( 17733), -INT16_C( 15138), -INT16_C( 26221), -INT16_C(  8581), -INT16_C( 17166) },
      UINT32_C(2849954152),
      {  INT16_C( 30818),  INT16_C( 12844), -INT16_C( 24923),  INT16_C( 18976),  INT16_C( 16041), -INT16_C( 11355), -INT16_C( 14591),  INT16_C( 16007),
         INT16_C( 28203),  INT16_C(  3255), -INT16_C( 21685), -INT16_C(  5841), -INT16_C( 18691), -INT16_C(  3930),  INT16_C(  7153), -INT16_C( 21391),
        -INT16_C( 26493),  INT16_C( 16267),  INT16_C(  5044), -INT16_C( 22293),  INT16_C( 29810), -INT16_C(  2382), -INT16_C( 14482), -INT16_C(  3920),
         INT16_C( 31923),  INT16_C( 22111), -INT16_C( 14985), -INT16_C( 32306), -INT16_C( 21470),  INT16_C(  2866), -INT16_C(  7062), -INT16_C(  8230) },
      {  INT16_C( 24965), -INT16_C( 16372), -INT16_C( 11253),  INT16_C(  3907), -INT16_C( 10867),  INT16_C(  6102),  INT16_C( 31893), -INT16_C(  1152),
        -INT16_C( 16188),  INT16_C( 17787), -INT16_C( 11616),  INT16_C( 16599),  INT16_C( 15974),  INT16_C( 16313), -INT16_C( 16172), -INT16_C( 21916),
        -INT16_C( 28521),  INT16_C(   649),  INT16_C( 22744),  INT16_C( 16863), -INT16_C( 28302),  INT16_C( 10253),  INT16_C( 28528), -INT16_C( 18657),
        -INT16_C( 17549), -INT16_C( 22343),  INT16_C( 25721), -INT16_C( 12195), -INT16_C( 23631), -INT16_C( 15610),  INT16_C(  5371),  INT16_C( 18855) },
      { -INT16_C( 24230), -INT16_C( 25235), -INT16_C( 22849),  INT16_C(  6102),  INT16_C( 12370),  INT16_C( 31893),  INT16_C( 16007),  INT16_C( 23210),
        -INT16_C( 18691), -INT16_C( 28647), -INT16_C( 25235),  INT16_C( 16313),  INT16_C(  7153),  INT16_C( 24492), -INT16_C( 21391), -INT16_C( 21916),
         INT16_C( 12436), -INT16_C( 28302), -INT16_C(  2382),  INT16_C( 10253), -INT16_C( 14482), -INT16_C( 25047), -INT16_C(  3920), -INT16_C( 18657),
        -INT16_C( 21470), -INT16_C( 14616),  INT16_C(  8792), -INT16_C( 15610), -INT16_C( 15138),  INT16_C(  5371), -INT16_C(  8581),  INT16_C( 18855) } },
    { { -INT16_C(  8359), -INT16_C( 30047), -INT16_C( 28292), -INT16_C(  6980), -INT16_C( 10294), -INT16_C( 22686),  INT16_C( 10785),  INT16_C( 22251),
         INT16_C( 30350), -INT16_C(   845),  INT16_C( 11361),  INT16_C( 28292), -INT16_C( 29332), -INT16_C(  2188),  INT16_C( 31028), -INT16_C( 28185),
        -INT16_C( 28936), -INT16_C( 25956), -INT16_C( 11312),  INT16_C( 25754), -INT16_C( 16760),  INT16_C( 10190),  INT16_C(  5161), -INT16_C( 13729),
        -INT16_C(  4141),  INT16_C( 10413), -INT16_C(   315),  INT16_C(  7941), -INT16_C(  8026),  INT16_C(  3476),  INT16_C( 24408), -INT16_C(  8315) },
      UINT32_C(2477708793),
      { -INT16_C( 23908), -INT16_C( 16752),  INT16_C( 18317), -INT16_C( 12565), -INT16_C( 21776), -INT16_C( 19159),  INT16_C( 18487), -INT16_C( 19919),
         INT16_C( 26763), -INT16_C( 29351),  INT16_C(  8841), -INT16_C( 13846), -INT16_C( 16520), -INT16_C( 10625), -INT16_C(  3418),  INT16_C( 12584),
         INT16_C( 20641), -INT16_C( 17565), -INT16_C( 10745),  INT16_C( 16522), -INT16_C( 13515),  INT16_C(  3233),  INT16_C( 32025), -INT16_C(  2625),
         INT16_C(  2319),  INT16_C( 15384), -INT16_C( 19012), -INT16_C( 11938),  INT16_C(  3220), -INT16_C( 15552), -INT16_C(  2812), -INT16_C(  3672) },
      { -INT16_C(  8644), -INT16_C(  3932), -INT16_C( 29702), -INT16_C( 32484), -INT16_C(  7171),  INT16_C( 24408), -INT16_C(  3264), -INT16_C( 32013),
         INT16_C( 11313), -INT16_C( 11678),  INT16_C( 30398),  INT16_C( 11431),  INT16_C(  9304), -INT16_C(  6903), -INT16_C( 20628), -INT16_C(  3802),
         INT16_C(   528), -INT16_C( 28485), -INT16_C(  2619), -INT16_C( 17710), -INT16_C( 23889),  INT16_C( 29661), -INT16_C( 21325),  INT16_C(  5869),
         INT16_C( 16688),  INT16_C( 31068), -INT16_C( 22030),  INT16_C( 24313), -INT16_C(  2086),  INT16_C( 26287), -INT16_C( 10861), -INT16_C( 26197) },
      { -INT16_C( 21776), -INT16_C( 30047), -INT16_C( 28292),  INT16_C( 24408),  INT16_C( 18487), -INT16_C(  3264), -INT16_C( 19919), -INT16_C( 32013),
        -INT16_C( 16520), -INT16_C(   845), -INT16_C( 10625),  INT16_C( 28292), -INT16_C(  3418), -INT16_C(  2188),  INT16_C( 12584), -INT16_C(  3802),
        -INT16_C( 28936), -INT16_C( 23889),  INT16_C(  3233),  INT16_C( 29661), -INT16_C( 16760), -INT16_C( 21325),  INT16_C(  5161),  INT16_C(  5869),
         INT16_C(  3220), -INT16_C(  2086), -INT16_C(   315),  INT16_C(  7941), -INT16_C(  2812),  INT16_C(  3476),  INT16_C( 24408), -INT16_C( 26197) } },
    { {  INT16_C(  2339), -INT16_C(  3730), -INT16_C(  2095), -INT16_C(  2880),  INT16_C( 13424),  INT16_C( 25522), -INT16_C( 28156),  INT16_C(  2159),
         INT16_C( 18419),  INT16_C(  2222),  INT16_C(  8093), -INT16_C( 27361), -INT16_C( 19874), -INT16_C( 21784),  INT16_C( 25037), -INT16_C( 27374),
        -INT16_C( 21444),  INT16_C(  1472), -INT16_C( 30798),  INT16_C( 16440), -INT16_C(   901), -INT16_C(  2601),  INT16_C(  5056), -INT16_C(  8224),
         INT16_C( 31617),  INT16_C( 30620),  INT16_C( 16500), -INT16_C( 31288), -INT16_C( 15169),  INT16_C( 15332),  INT16_C( 30235), -INT16_C(    11) },
      UINT32_C(4066153294),
      { -INT16_C( 29379), -INT16_C( 15697), -INT16_C( 22433),  INT16_C(  3492), -INT16_C( 32064),  INT16_C(  4085),  INT16_C( 29009),  INT16_C(  7647),
         INT16_C(  4718), -INT16_C( 22770), -INT16_C( 27249), -INT16_C( 18787),  INT16_C( 10179),  INT16_C( 12735), -INT16_C(  4464),  INT16_C( 17191),
         INT16_C( 30180), -INT16_C( 25832),  INT16_C(  7862), -INT16_C( 26743), -INT16_C( 19714), -INT16_C( 32650),  INT16_C(  3214),  INT16_C( 15516),
         INT16_C( 25593), -INT16_C(  8304), -INT16_C( 25382),  INT16_C( 27607),  INT16_C( 11867), -INT16_C(   448),  INT16_C( 19993),  INT16_C( 26374) },
      {  INT16_C( 18929), -INT16_C( 24781),  INT16_C( 16785),  INT16_C( 28792),  INT16_C( 19031),  INT16_C(  8368),  INT16_C( 18256), -INT16_C( 11996),
        -INT16_C(  6969), -INT16_C( 19821),  INT16_C( 15775),  INT16_C( 22128), -INT16_C( 18885), -INT16_C(  9277),  INT16_C( 15013), -INT16_C(  2507),
        -INT16_C( 12366), -INT16_C(  3651),  INT16_C( 26471),  INT16_C( 25183),  INT16_C(  2806),  INT16_C( 21581),  INT16_C( 25029), -INT16_C( 25129),
        -INT16_C(  3278), -INT16_C( 12421),  INT16_C(  3308),  INT16_C(  9521), -INT16_C( 10772), -INT16_C( 21126),  INT16_C( 13313), -INT16_C(  7247) },
      {  INT16_C(  2339),  INT16_C( 19031),  INT16_C(  4085),  INT16_C(  8368),  INT16_C( 13424),  INT16_C( 25522),  INT16_C(  7647),  INT16_C(  2159),
         INT16_C( 10179), -INT16_C( 18885),  INT16_C(  8093), -INT16_C( 27361), -INT16_C(  4464), -INT16_C( 21784),  INT16_C( 25037), -INT16_C(  2507),
        -INT16_C( 21444),  INT16_C(  1472), -INT16_C( 32650),  INT16_C( 21581),  INT16_C(  3214), -INT16_C(  2601),  INT16_C( 15516), -INT16_C(  8224),
         INT16_C( 31617), -INT16_C( 10772),  INT16_C( 16500), -INT16_C( 31288),  INT16_C( 19993),  INT16_C( 13313),  INT16_C( 26374), -INT16_C(  7247) } },
    { { -INT16_C( 29581), -INT16_C( 23827), -INT16_C( 26970),  INT16_C(  7499),  INT16_C( 12876),  INT16_C( 13829), -INT16_C( 17581), -INT16_C( 31540),
         INT16_C(  9315),  INT16_C(  5411), -INT16_C(  8990), -INT16_C( 12609),  INT16_C( 26785), -INT16_C( 15610), -INT16_C(  2863),  INT16_C( 29552),
         INT16_C( 10013), -INT16_C( 24346), -INT16_C(  7304),  INT16_C( 31671),  INT16_C( 19291), -INT16_C(  1156), -INT16_C(  6562),  INT16_C( 24620),
         INT16_C( 21867), -INT16_C( 31118), -INT16_C( 10260), -INT16_C( 21379),  INT16_C( 21627), -INT16_C( 19538),  INT16_C( 19717), -INT16_C( 29048) },
      UINT32_C(2775428591),
      {  INT16_C( 14869),  INT16_C( 26177),  INT16_C( 24970),  INT16_C( 14240),  INT16_C( 30897), -INT16_C( 24567), -INT16_C(  2061), -INT16_C(   285),
         INT16_C( 32651),  INT16_C( 29071), -INT16_C( 22083),  INT16_C( 31401),  INT16_C(  9639), -INT16_C( 27443), -INT16_C(  4834),  INT16_C( 10547),
        -INT16_C( 18378), -INT16_C(  8629), -INT16_C( 26472), -INT16_C(  8609), -INT16_C( 11971), -INT16_C( 17018), -INT16_C( 18011), -INT16_C( 32331),
        -INT16_C( 29042), -INT16_C(  6714), -INT16_C( 14445),  INT16_C( 27618), -INT16_C( 11596),  INT16_C( 14483), -INT16_C( 11545), -INT16_C( 21711) },
      {  INT16_C( 10897),  INT16_C( 22009),  INT16_C( 32250),  INT16_C( 31919), -INT16_C( 24691), -INT16_C( 29314),  INT16_C( 15358), -INT16_C( 16122),
         INT16_C( 30957), -INT16_C( 26897), -INT16_C( 26794),  INT16_C( 15455), -INT16_C( 30086),  INT16_C( 30444),  INT16_C( 18498),  INT16_C( 23540),
         INT16_C( 13714), -INT16_C(  2546), -INT16_C( 31755),  INT16_C( 11608), -INT16_C( 26841),  INT16_C( 20209), -INT16_C( 17101),  INT16_C(  4879),
         INT16_C( 27530), -INT16_C( 31433),  INT16_C( 12389), -INT16_C(  2043),  INT16_C( 16944),  INT16_C( 19678), -INT16_C( 16909), -INT16_C( 27839) },
      {  INT16_C( 30897), -INT16_C( 24691), -INT16_C( 24567), -INT16_C( 29314),  INT16_C( 12876),  INT16_C( 15358), -INT16_C(   285), -INT16_C( 16122),
         INT16_C(  9639),  INT16_C(  5411), -INT16_C( 27443),  INT16_C( 30444),  INT16_C( 26785),  INT16_C( 18498), -INT16_C(  2863),  INT16_C( 23540),
        -INT16_C( 11971), -INT16_C( 24346), -INT16_C( 17018),  INT16_C( 20209),  INT16_C( 19291), -INT16_C( 17101), -INT16_C( 32331),  INT16_C( 24620),
        -INT16_C( 11596), -INT16_C( 31118),  INT16_C( 14483), -INT16_C( 21379),  INT16_C( 21627), -INT16_C( 16909),  INT16_C( 19717), -INT16_C( 27839) } },
    { {  INT16_C( 29748),  INT16_C(  6882),  INT16_C( 21770),  INT16_C( 23585),  INT16_C( 19519), -INT16_C(  6274), -INT16_C(  2156), -INT16_C( 27355),
         INT16_C( 28989), -INT16_C( 21844),  INT16_C( 11238),  INT16_C(   261),  INT16_C( 29367), -INT16_C( 32231),  INT16_C(    93), -INT16_C( 15466),
        -INT16_C(  2026),  INT16_C(  2614), -INT16_C(  4337),  INT16_C( 25261),  INT16_C( 23732), -INT16_C(  6375),  INT16_C( 11133),  INT16_C( 15341),
        -INT16_C( 15677),  INT16_C( 24101),  INT16_C( 17867), -INT16_C( 27503),  INT16_C( 21790), -INT16_C( 23705), -INT16_C(  1777), -INT16_C( 20179) },
      UINT32_C(1340282387),
      {  INT16_C(  1264),  INT16_C( 19542),  INT16_C(  2084),  INT16_C( 20074), -INT16_C( 24161),  INT16_C( 26966), -INT16_C( 30376), -INT16_C(  8095),
         INT16_C( 29142),  INT16_C( 15463),  INT16_C(  5793),  INT16_C( 20708),  INT16_C( 18639), -INT16_C(  3555), -INT16_C( 24855), -INT16_C( 11775),
         INT16_C( 22356),  INT16_C( 30867), -INT16_C( 25918), -INT16_C( 13445), -INT16_C( 16336),  INT16_C( 20246),  INT16_C( 10082), -INT16_C( 23619),
         INT16_C(  9828),  INT16_C( 27450), -INT16_C( 21718),  INT16_C( 22832), -INT16_C( 29575),  INT16_C( 27182), -INT16_C(  6615),  INT16_C( 15412) },
      {  INT16_C( 15650),  INT16_C( 15480), -INT16_C(  6166), -INT16_C( 15856), -INT16_C( 29977),  INT16_C( 18773),  INT16_C(  5402), -INT16_C( 15078),
         INT16_C(  4395),  INT16_C( 32337), -INT16_C( 16386),  INT16_C( 23840), -INT16_C( 29836), -INT16_C( 29495),  INT16_C( 19749),  INT16_C( 19625),
         INT16_C( 23497), -INT16_C( 22002), -INT16_C( 15042),  INT16_C( 21054),  INT16_C( 15485),  INT16_C( 28416),  INT16_C( 12403),  INT16_C( 25440),
        -INT16_C( 27314), -INT16_C( 26108), -INT16_C( 25836),  INT16_C(  3350), -INT16_C( 16632), -INT16_C( 21393), -INT16_C( 22833),  INT16_C( 20506) },
      { -INT16_C( 24161), -INT16_C( 29977),  INT16_C( 21770),  INT16_C( 23585), -INT16_C( 30376), -INT16_C(  6274), -INT16_C(  2156), -INT16_C( 27355),
         INT16_C( 28989), -INT16_C( 29836), -INT16_C(  3555),  INT16_C(   261), -INT16_C( 24855), -INT16_C( 32231),  INT16_C(    93), -INT16_C( 15466),
        -INT16_C( 16336),  INT16_C( 15485), -INT16_C(  4337),  INT16_C( 25261),  INT16_C( 23732),  INT16_C( 12403), -INT16_C( 23619),  INT16_C( 25440),
        -INT16_C( 29575), -INT16_C( 16632),  INT16_C( 27182), -INT16_C( 21393),  INT16_C( 21790), -INT16_C( 23705),  INT16_C( 15412), -INT16_C( 20179) } },
    { { -INT16_C(  8200),  INT16_C(  7627),  INT16_C( 14415),  INT16_C( 28823), -INT16_C( 26145),  INT16_C( 31619),  INT16_C(  5373), -INT16_C(  7776),
        -INT16_C(  7221),  INT16_C(  4552), -INT16_C( 15205),  INT16_C( 26952),  INT16_C(  1141),  INT16_C(  2516), -INT16_C( 32052),  INT16_C( 25973),
         INT16_C( 26326), -INT16_C( 10505), -INT16_C(  4938),  INT16_C( 32521), -INT16_C(  3759), -INT16_C( 25166), -INT16_C( 20803), -INT16_C( 24534),
        -INT16_C( 30623),  INT16_C(   949),  INT16_C( 10548),  INT16_C( 10924),  INT16_C( 14178), -INT16_C( 31045), -INT16_C( 24906),  INT16_C(  6122) },
      UINT32_C(3928995989),
      {  INT16_C( 12610),  INT16_C( 23899),  INT16_C( 23145), -INT16_C( 31816),  INT16_C(  4410), -INT16_C( 13862),  INT16_C(  3653),  INT16_C( 13101),
        -INT16_C( 31324),  INT16_C( 22071), -INT16_C( 14205), -INT16_C( 26962),  INT16_C(  4142),  INT16_C(  6793),  INT16_C( 11541),  INT16_C( 14781),
         INT16_C( 21984),  INT16_C( 16940),  INT16_C( 23416),  INT16_C(  3744), -INT16_C( 20266), -INT16_C( 23140),  INT16_C( 16081),  INT16_C( 17494),
        -INT16_C( 16623), -INT16_C(   138), -INT16_C( 19484),  INT16_C(  6584), -INT16_C(   751),  INT16_C( 23181),  INT16_C( 18927), -INT16_C(  3545) },
      { -INT16_C(  7842),  INT16_C( 11554),  INT16_C(   795), -INT16_C( 21871),  INT16_C(  6798), -INT16_C( 30861), -INT16_C(  8461), -INT16_C( 15264),
         INT16_C(  4397), -INT16_C(  7119), -INT16_C(   836),  INT16_C( 13296),  INT16_C( 24827), -INT16_C( 31668),  INT16_C( 12714),  INT16_C( 25970),
        -INT16_C( 27486), -INT16_C( 22471),  INT16_C( 18128), -INT16_C(  5212), -INT16_C( 12935),  INT16_C(  2848), -INT16_C( 19750), -INT16_C( 16551),
        -INT16_C( 20456),  INT16_C(  6500),  INT16_C( 17407),  INT16_C(  5189), -INT16_C( 23069), -INT16_C( 14499), -INT16_C( 29111),  INT16_C( 22692) },
      {  INT16_C(  4410),  INT16_C(  7627), -INT16_C( 13862),  INT16_C( 28823),  INT16_C(  3653),  INT16_C( 31619),  INT16_C(  5373), -INT16_C( 15264),
        -INT16_C(  7221),  INT16_C(  4552), -INT16_C( 15205), -INT16_C( 31668),  INT16_C( 11541),  INT16_C( 12714), -INT16_C( 32052),  INT16_C( 25970),
        -INT16_C( 20266), -INT16_C( 12935), -INT16_C( 23140),  INT16_C(  2848), -INT16_C(  3759), -INT16_C( 19750), -INT16_C( 20803), -INT16_C( 24534),
        -INT16_C( 30623), -INT16_C( 23069),  INT16_C( 10548), -INT16_C( 14499),  INT16_C( 14178), -INT16_C( 29111), -INT16_C(  3545),  INT16_C( 22692) } },
    { {  INT16_C( 24111),  INT16_C( 18895),  INT16_C( 29112), -INT16_C( 20943), -INT16_C( 25302),  INT16_C( 30083), -INT16_C( 20197), -INT16_C( 14464),
         INT16_C(  5444),  INT16_C( 11860),  INT16_C( 13339),  INT16_C( 10750), -INT16_C(  4538),  INT16_C( 30577),  INT16_C(  4039), -INT16_C( 30598),
         INT16_C( 21399),  INT16_C(   263),  INT16_C( 14517), -INT16_C(   583), -INT16_C(  9112), -INT16_C( 21884), -INT16_C(    85),  INT16_C(   692),
         INT16_C( 29968),  INT16_C( 30809), -INT16_C(  2432), -INT16_C(   163), -INT16_C(  9975),  INT16_C( 10666), -INT16_C( 21228), -INT16_C( 20122) },
      UINT32_C(1303004863),
      { -INT16_C(  5605), -INT16_C( 25661), -INT16_C( 30067),  INT16_C( 19149), -INT16_C( 15934), -INT16_C( 28138), -INT16_C( 30757), -INT16_C(  3057),
         INT16_C( 25047),  INT16_C(  2921), -INT16_C(  1076),  INT16_C( 19118),  INT16_C( 12231),  INT16_C( 16015), -INT16_C( 27113),  INT16_C( 12252),
         INT16_C( 16740), -INT16_C(  6319),  INT16_C(  9362), -INT16_C(  9743),  INT16_C( 12426), -INT16_C( 15290), -INT16_C(  1684), -INT16_C( 30138),
         INT16_C( 22557),  INT16_C(  8406), -INT16_C( 26406),  INT16_C( 29196),  INT16_C( 28663), -INT16_C( 25873),  INT16_C( 29464), -INT16_C( 29841) },
      { -INT16_C( 18976), -INT16_C(  2946),  INT16_C( 24777),  INT16_C(  7548), -INT16_C(  9637), -INT16_C( 15498), -INT16_C( 20265), -INT16_C( 12535),
        -INT16_C( 28114), -INT16_C( 13322),  INT16_C( 24489),  INT16_C( 25709),  INT16_C(  6527),  INT16_C(  4917), -INT16_C(  7806), -INT16_C( 28795),
         INT16_C( 11369), -INT16_C( 22810), -INT16_C( 22990),  INT16_C( 19993), -INT16_C( 26169),  INT16_C(  4116), -INT16_C(   492),  INT16_C( 26923),
         INT16_C( 22644),  INT16_C( 23617),  INT16_C( 29621), -INT16_C(  7937), -INT16_C(  4740),  INT16_C( 16787),  INT16_C(  9956),  INT16_C(  2215) },
      { -INT16_C( 15934), -INT16_C(  9637), -INT16_C( 28138), -INT16_C( 15498), -INT16_C( 30757), -INT16_C( 20265), -INT16_C( 20197), -INT16_C( 12535),
         INT16_C(  5444),  INT16_C(  6527),  INT16_C( 16015),  INT16_C( 10750), -INT16_C(  4538),  INT16_C( 30577),  INT16_C( 12252), -INT16_C( 30598),
         INT16_C( 21399), -INT16_C( 26169),  INT16_C( 14517),  INT16_C(  4116), -INT16_C(  9112), -INT16_C(   492), -INT16_C(    85),  INT16_C( 26923),
         INT16_C( 28663),  INT16_C( 30809), -INT16_C( 25873),  INT16_C( 16787), -INT16_C(  9975),  INT16_C( 10666), -INT16_C( 29841), -INT16_C( 20122) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i src = simde_mm512_loadu_epi16(test_vec[i].src);
    simde__m512i a = simde_mm512_loadu_epi16(test_vec[i].a);
    simde__m512i b = simde_mm512_loadu_epi16(test_vec[i].b);
    simde__m512i r = simde_mm512_mask_unpackhi_epi16(src, test_vec[i].k, a, b);
    simde_test_x86_assert_equal_i16x32(r, simde_mm512_loadu_epi16(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_mm512_maskz_unpackhi_epi16 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const simde__mmask32 k;
    const int16_t a[32];
    const int16_t b[32];
    const int16_t r[32];
  } test_vec[] = {
 { UINT32_C(1239030295),
      {  INT16_C( 18650), -INT16_C( 27490),  INT16_C( 19500),  INT16_C( 28558), -INT16_C( 10413),  INT16_C( 27919),  INT16_C( 29877),  INT16_C(  3112),
        -INT16_C( 10096),  INT16_C(  3591), -INT16_C( 28859), -INT16_C( 17191),  INT16_C( 29106), -INT16_C(  8568), -INT16_C( 14808),  INT16_C(  2221),
         INT16_C(  9590), -INT16_C( 18732),  INT16_C( 16210), -INT16_C(  2398), -INT16_C( 24718),  INT16_C( 31150), -INT16_C(  2282), -INT16_C( 22376),
         INT16_C(  9645), -INT16_C( 14167), -INT16_C( 17121), -INT16_C( 28178),  INT16_C( 29165), -INT16_C( 13923),  INT16_C( 30269),  INT16_C(  8518) },
      { -INT16_C( 17641),  INT16_C( 28773), -INT16_C( 18662), -INT16_C( 19754),  INT16_C( 16072),  INT16_C( 13954),  INT16_C( 23812),  INT16_C( 28020),
        -INT16_C( 16551),  INT16_C( 28718),  INT16_C(  5555), -INT16_C( 23903), -INT16_C( 32004), -INT16_C( 27079),  INT16_C( 32220), -INT16_C( 27353),
         INT16_C( 16085), -INT16_C( 28131),  INT16_C( 20981),  INT16_C( 18839), -INT16_C( 27457), -INT16_C( 10586),  INT16_C( 30781),  INT16_C( 11499),
        -INT16_C(  5601),  INT16_C( 23348),  INT16_C(  5237), -INT16_C( 23168), -INT16_C( 30030), -INT16_C(  4840), -INT16_C(  1249), -INT16_C( 15536) },
      { -INT16_C( 10413),  INT16_C( 16072),  INT16_C( 27919),  INT16_C(     0),  INT16_C( 29877),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
         INT16_C(     0), -INT16_C( 32004),  INT16_C(     0), -INT16_C( 27079), -INT16_C( 14808),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
         INT16_C(     0), -INT16_C( 27457),  INT16_C(     0), -INT16_C( 10586), -INT16_C(  2282),  INT16_C(     0), -INT16_C( 22376),  INT16_C( 11499),
         INT16_C( 29165),  INT16_C(     0),  INT16_C(     0), -INT16_C(  4840),  INT16_C(     0),  INT16_C(     0),  INT16_C(  8518),  INT16_C(     0) } },
    { UINT32_C(2476879138),
      { -INT16_C( 13928),  INT16_C( 22709), -INT16_C( 20415),  INT16_C( 29135), -INT16_C( 28928),  INT16_C( 10196),  INT16_C(  4989), -INT16_C( 22951),
         INT16_C(  4945), -INT16_C( 19359), -INT16_C( 16149),  INT16_C( 26981),  INT16_C( 14101), -INT16_C( 22358),  INT16_C(  8981),  INT16_C( 27845),
        -INT16_C( 20866),  INT16_C( 22410), -INT16_C( 19029), -INT16_C(  9503),  INT16_C( 26583), -INT16_C( 12089),  INT16_C( 13822), -INT16_C( 26202),
         INT16_C( 23351), -INT16_C( 26141),  INT16_C( 16546), -INT16_C( 10629),  INT16_C(  8563),  INT16_C( 15874), -INT16_C(  3643),  INT16_C( 26061) },
      {  INT16_C(  1430),  INT16_C( 30905), -INT16_C( 29800), -INT16_C( 23380), -INT16_C( 16086),  INT16_C( 10258), -INT16_C( 13793),  INT16_C(  9766),
        -INT16_C( 32436), -INT16_C( 13109), -INT16_C( 13828), -INT16_C(  1383), -INT16_C(  5989), -INT16_C( 18296),  INT16_C(  3062), -INT16_C( 20793),
        -INT16_C( 27179),  INT16_C( 26186), -INT16_C(  8999), -INT16_C( 32469),  INT16_C(  5156), -INT16_C( 27072),  INT16_C( 19904), -INT16_C( 20378),
        -INT16_C( 24107), -INT16_C( 30185),  INT16_C( 23120), -INT16_C( 30483),  INT16_C(  5694), -INT16_C( 30196), -INT16_C(  4996), -INT16_C(  3634) },
      {  INT16_C(     0), -INT16_C( 16086),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C( 13793),  INT16_C(     0),  INT16_C(     0),
         INT16_C( 14101),  INT16_C(     0), -INT16_C( 22358), -INT16_C( 18296),  INT16_C(     0),  INT16_C(  3062),  INT16_C(     0),  INT16_C(     0),
         INT16_C(     0),  INT16_C(  5156),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C( 19904),  INT16_C(     0), -INT16_C( 20378),
         INT16_C(  8563),  INT16_C(  5694),  INT16_C(     0),  INT16_C(     0), -INT16_C(  3643),  INT16_C(     0),  INT16_C(     0), -INT16_C(  3634) } },
    { UINT32_C(2616854452),
      { -INT16_C(  6224), -INT16_C(  6044),  INT16_C( 20957),  INT16_C( 30709),  INT16_C( 24442), -INT16_C( 22992),  INT16_C(  6688),  INT16_C( 17993),
        -INT16_C(  7188), -INT16_C( 19183),  INT16_C(  7974), -INT16_C( 15587),  INT16_C( 13787),  INT16_C( 31010),  INT16_C( 18629),  INT16_C( 31791),
        -INT16_C( 22719), -INT16_C( 29132),  INT16_C(  6533),  INT16_C( 31298), -INT16_C( 23353),  INT16_C( 19020),  INT16_C( 27128), -INT16_C(  7177),
         INT16_C( 11098), -INT16_C( 16155), -INT16_C(  9163), -INT16_C(  6902),  INT16_C( 30564),  INT16_C( 30453), -INT16_C( 13157),  INT16_C( 24892) },
      { -INT16_C( 13209),  INT16_C( 17095),  INT16_C( 21391),  INT16_C(  1180),  INT16_C(    52), -INT16_C( 31351),  INT16_C( 32165), -INT16_C( 27346),
         INT16_C( 29682),  INT16_C(  2942),  INT16_C( 22791), -INT16_C(  3600),  INT16_C(  6355),  INT16_C( 27390), -INT16_C( 19855),  INT16_C( 26669),
        -INT16_C( 20165), -INT16_C(  4615), -INT16_C(  1951), -INT16_C( 24895),  INT16_C( 22661), -INT16_C( 27645),  INT16_C( 17725),  INT16_C( 10606),
        -INT16_C( 17849), -INT16_C( 25352), -INT16_C( 20940),  INT16_C( 15978), -INT16_C(  3211),  INT16_C( 22645), -INT16_C( 14905), -INT16_C(  2048) },
      {  INT16_C(     0),  INT16_C(     0), -INT16_C( 22992),  INT16_C(     0),  INT16_C(  6688),  INT16_C( 32165),  INT16_C(     0), -INT16_C( 27346),
         INT16_C( 13787),  INT16_C(  6355),  INT16_C( 31010),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
         INT16_C(     0),  INT16_C( 22661),  INT16_C(     0), -INT16_C( 27645),  INT16_C( 27128),  INT16_C( 17725), -INT16_C(  7177),  INT16_C( 10606),
         INT16_C( 30564), -INT16_C(  3211),  INT16_C(     0),  INT16_C( 22645), -INT16_C( 13157),  INT16_C(     0),  INT16_C(     0), -INT16_C(  2048) } },
    { UINT32_C(1125662070),
      { -INT16_C(   412), -INT16_C(  5067), -INT16_C( 18848),  INT16_C( 16441),  INT16_C( 30688),  INT16_C(  2036), -INT16_C( 14512),  INT16_C( 28922),
        -INT16_C( 10547),  INT16_C(  5608), -INT16_C(  7725),  INT16_C( 17161), -INT16_C(  6765), -INT16_C( 29831),  INT16_C(  1640),  INT16_C( 26806),
         INT16_C(    22),  INT16_C(  8972),  INT16_C(  2241), -INT16_C( 13548),  INT16_C(  9690), -INT16_C(  1001), -INT16_C( 12679), -INT16_C( 17557),
        -INT16_C( 32063),  INT16_C(  2739), -INT16_C( 25982),  INT16_C( 11081), -INT16_C(  1493),  INT16_C( 21446), -INT16_C( 15362),  INT16_C( 17298) },
      { -INT16_C( 26320),  INT16_C(    57),  INT16_C( 26068), -INT16_C( 12152), -INT16_C( 18814),  INT16_C(  2112), -INT16_C( 27559),  INT16_C( 16733),
         INT16_C( 12148), -INT16_C(  3954),  INT16_C( 19441), -INT16_C( 29400), -INT16_C( 25953),  INT16_C(  8028),  INT16_C(  8534),  INT16_C( 23644),
         INT16_C(  3071), -INT16_C( 23791), -INT16_C( 32560), -INT16_C(  4881),  INT16_C( 24814), -INT16_C( 16893),  INT16_C( 12500), -INT16_C( 29674),
        -INT16_C( 24798),  INT16_C( 10955),  INT16_C( 28778),  INT16_C( 18077), -INT16_C( 10207), -INT16_C( 17224),  INT16_C( 22407),  INT16_C( 28033) },
      {  INT16_C(     0), -INT16_C( 18814),  INT16_C(  2036),  INT16_C(     0), -INT16_C( 14512), -INT16_C( 27559),  INT16_C( 28922),  INT16_C(     0),
        -INT16_C(  6765),  INT16_C(     0), -INT16_C( 29831),  INT16_C(  8028),  INT16_C(  1640),  INT16_C(  8534),  INT16_C(     0),  INT16_C(     0),
         INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C( 16893), -INT16_C( 12679),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
        -INT16_C(  1493), -INT16_C( 10207),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C( 17298),  INT16_C(     0) } },
    { UINT32_C(1175988243),
      { -INT16_C(  9005), -INT16_C(  7450),  INT16_C( 28818),  INT16_C( 14716), -INT16_C(   680), -INT16_C( 11928), -INT16_C( 21347),  INT16_C( 17832),
         INT16_C(  2261), -INT16_C(  4821), -INT16_C( 27107), -INT16_C( 14943),  INT16_C(  3268), -INT16_C(  2897), -INT16_C( 21863), -INT16_C( 21633),
         INT16_C( 10018),  INT16_C(  3736), -INT16_C( 30650),  INT16_C(  1389),  INT16_C(  7485), -INT16_C( 27070),  INT16_C(  5612),  INT16_C( 23158),
         INT16_C( 20757),  INT16_C(  2285), -INT16_C(  9096),  INT16_C( 19496),  INT16_C(  7748),  INT16_C(  1378),  INT16_C(  6746), -INT16_C( 13405) },
      {  INT16_C( 11234),  INT16_C(  5178), -INT16_C(  1805),  INT16_C( 17722), -INT16_C(  7606), -INT16_C(  2186),  INT16_C( 14976),  INT16_C( 17712),
        -INT16_C( 13492),  INT16_C( 19417),  INT16_C( 28099), -INT16_C( 16208), -INT16_C( 19743),  INT16_C( 27100), -INT16_C( 27893),  INT16_C( 22652),
         INT16_C( 27564),  INT16_C( 24472), -INT16_C(  1796), -INT16_C(  8192),  INT16_C( 28360), -INT16_C( 21536), -INT16_C(  2280), -INT16_C(  4441),
         INT16_C( 32616), -INT16_C( 23765),  INT16_C( 21903), -INT16_C( 18635), -INT16_C( 16578),  INT16_C( 17190), -INT16_C(  9068), -INT16_C(  1634) },
      { -INT16_C(   680), -INT16_C(  7606),  INT16_C(     0),  INT16_C(     0), -INT16_C( 21347),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
         INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C( 27100),  INT16_C(     0), -INT16_C( 27893),  INT16_C(     0),  INT16_C(     0),
         INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C( 21536),  INT16_C(  5612),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
         INT16_C(     0), -INT16_C( 16578),  INT16_C(  1378),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C( 13405),  INT16_C(     0) } },
    { UINT32_C( 492850220),
      { -INT16_C(  6421),  INT16_C(  9651), -INT16_C( 15038), -INT16_C( 16043),  INT16_C( 14467),  INT16_C(  1397), -INT16_C( 13665),  INT16_C(  3847),
        -INT16_C( 15670),  INT16_C( 27446), -INT16_C(  9279),  INT16_C( 18896),  INT16_C( 15069),  INT16_C( 26093), -INT16_C(  4977), -INT16_C(  9289),
         INT16_C(  3171),  INT16_C( 18546),  INT16_C( 17619), -INT16_C( 15106),  INT16_C( 22524), -INT16_C(  9283),  INT16_C( 17567),  INT16_C(  5881),
        -INT16_C(  3092),  INT16_C( 23893), -INT16_C( 11481),  INT16_C(  6826),  INT16_C( 22622), -INT16_C( 26035),  INT16_C(  4149),  INT16_C( 27942) },
      {  INT16_C(  9952),  INT16_C( 14905),  INT16_C( 17708),  INT16_C( 21677),  INT16_C( 14033), -INT16_C(  1371), -INT16_C(  1973), -INT16_C( 12936),
        -INT16_C( 10402),  INT16_C( 10957),  INT16_C( 22312), -INT16_C( 15335), -INT16_C( 29213),  INT16_C( 10775),  INT16_C( 31022),  INT16_C(  9040),
         INT16_C(   941), -INT16_C( 12366),  INT16_C( 11995), -INT16_C( 29745), -INT16_C( 23005),  INT16_C( 18614), -INT16_C( 27596),  INT16_C( 28981),
        -INT16_C( 31805),  INT16_C( 14931), -INT16_C( 16637), -INT16_C( 18756), -INT16_C(  6770),  INT16_C( 15929),  INT16_C(  1340), -INT16_C(  1642) },
      {  INT16_C(     0),  INT16_C(     0),  INT16_C(  1397), -INT16_C(  1371),  INT16_C(     0), -INT16_C(  1973),  INT16_C(     0),  INT16_C(     0),
         INT16_C(     0),  INT16_C(     0),  INT16_C( 26093),  INT16_C( 10775),  INT16_C(     0),  INT16_C(     0), -INT16_C(  9289),  INT16_C(     0),
         INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C( 27596),  INT16_C(  5881),  INT16_C(     0),
         INT16_C( 22622),  INT16_C(     0), -INT16_C( 26035),  INT16_C( 15929),  INT16_C(  4149),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
    { UINT32_C(2267271795),
      { -INT16_C( 12085), -INT16_C(  8585),  INT16_C( 30855),  INT16_C( 24874),  INT16_C(  3232),  INT16_C( 29238), -INT16_C(  1435), -INT16_C( 19292),
        -INT16_C(  5792),  INT16_C( 29321),  INT16_C( 11320), -INT16_C( 29834),  INT16_C( 30002),  INT16_C( 32669),  INT16_C(  9406), -INT16_C( 13005),
         INT16_C(  1258), -INT16_C(  6299),  INT16_C( 30417),  INT16_C( 31259), -INT16_C( 25277),  INT16_C(  7318), -INT16_C(  5367), -INT16_C(  1708),
         INT16_C(  2786),  INT16_C( 27534),  INT16_C( 17718), -INT16_C( 26828),  INT16_C( 20354), -INT16_C( 21621), -INT16_C( 17029),  INT16_C( 16184) },
      { -INT16_C(  4953), -INT16_C(  8159), -INT16_C( 28527),  INT16_C( 16284), -INT16_C(  2163), -INT16_C(  9830),  INT16_C(  1701),  INT16_C( 14221),
        -INT16_C(  2244),  INT16_C( 20579),  INT16_C( 27833),  INT16_C( 19485),  INT16_C( 24228), -INT16_C( 19404), -INT16_C( 20424), -INT16_C( 13747),
         INT16_C( 11076),  INT16_C( 26566),  INT16_C( 26136), -INT16_C( 32462), -INT16_C(  1965),  INT16_C( 31311),  INT16_C( 12201),  INT16_C( 17170),
         INT16_C(  4679),  INT16_C( 17945),  INT16_C(  6933), -INT16_C(  8928),  INT16_C( 28785),  INT16_C(   794),  INT16_C( 12209), -INT16_C( 20596) },
      {  INT16_C(  3232), -INT16_C(  2163),  INT16_C(     0),  INT16_C(     0), -INT16_C(  1435),  INT16_C(  1701), -INT16_C( 19292),  INT16_C(     0),
         INT16_C(     0),  INT16_C( 24228),  INT16_C(     0),  INT16_C(     0),  INT16_C(  9406),  INT16_C(     0), -INT16_C( 13005), -INT16_C( 13747),
        -INT16_C( 25277), -INT16_C(  1965),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C( 12201),  INT16_C(     0),  INT16_C(     0),
         INT16_C( 20354),  INT16_C( 28785), -INT16_C( 21621),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C( 20596) } },
    { UINT32_C(2249471327),
      { -INT16_C( 10567), -INT16_C( 17382), -INT16_C( 26866),  INT16_C( 15773), -INT16_C( 21880), -INT16_C( 14047), -INT16_C( 20550),  INT16_C(  7462),
        -INT16_C(  7264), -INT16_C( 19719),  INT16_C( 28970), -INT16_C( 30391), -INT16_C( 23447), -INT16_C(  2532), -INT16_C( 24664),  INT16_C( 10752),
         INT16_C(  2467), -INT16_C( 24149), -INT16_C( 16391),  INT16_C( 22573),  INT16_C(  1849), -INT16_C( 11064),  INT16_C(  4072),  INT16_C( 27994),
        -INT16_C( 10634),  INT16_C( 27220),  INT16_C( 31793), -INT16_C(  8341),  INT16_C( 30308),  INT16_C(  4744),  INT16_C( 16730), -INT16_C(  7411) },
      {  INT16_C( 24565), -INT16_C(  5672),  INT16_C(  2698),  INT16_C( 21398),  INT16_C( 19145),  INT16_C( 10654),  INT16_C( 10041), -INT16_C( 30578),
         INT16_C( 32656),  INT16_C( 21473), -INT16_C( 29332), -INT16_C(  2363), -INT16_C(  7007), -INT16_C(  6653),  INT16_C(  3737),  INT16_C( 12134),
         INT16_C(  4630), -INT16_C(  4063),  INT16_C( 29774),  INT16_C(  2575),  INT16_C( 21057), -INT16_C(  1641), -INT16_C(  2609), -INT16_C(  2207),
        -INT16_C(  2444), -INT16_C( 11782),  INT16_C( 25268),  INT16_C(  2644), -INT16_C( 27399), -INT16_C( 26284), -INT16_C( 20468), -INT16_C( 26930) },
      { -INT16_C( 21880),  INT16_C( 19145), -INT16_C( 14047),  INT16_C( 10654), -INT16_C( 20550),  INT16_C(     0),  INT16_C(  7462),  INT16_C(     0),
        -INT16_C( 23447),  INT16_C(     0), -INT16_C(  2532),  INT16_C(     0), -INT16_C( 24664),  INT16_C(  3737),  INT16_C(     0),  INT16_C(     0),
         INT16_C(     0),  INT16_C(     0), -INT16_C( 11064),  INT16_C(     0),  INT16_C(  4072),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
         INT16_C(     0), -INT16_C( 27399),  INT16_C(  4744),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C( 26930) } },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i a = simde_mm512_loadu_epi16(test_vec[i].a);
    simde__m512i b = simde_mm512_loadu_epi16(test_vec[i].b);
    simde__m512i r = simde_mm512_maskz_unpackhi_epi16(test_vec[i].k, a, b);
    simde_test_x86_assert_equal_i16x32(r, simde_mm512_loadu_epi16(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_mm256_mask_unpackhi_epi16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int16_t src[16];
    const simde__mmask16 k;
    const int16_t a[16];
    const int16_t b[16];
    const int16_t r[16];
  } test_vec[] = {
    { { -INT16_C( 11981), -INT16_C( 21722), -INT16_C( 14480),  INT16_C( 26877), -INT16_C( 29786), -INT16_C(  7904), -INT16_C( 23123), -INT16_C(  8819),
         INT16_C( 16456),  INT16_C( 29943),  INT16_C( 17414), -INT16_C( 27726), -INT16_C(  7932), -INT16_C(  7200), -INT16_C(  7745), -INT16_C(  3076) },
      UINT16_C( 9139),
      {  INT16_C(  9118), -INT16_C( 25622), -INT16_C( 28533), -INT16_C( 21722), -INT16_C( 11407), -INT16_C(   176), -INT16_C( 26448), -INT16_C( 22465),
         INT16_C( 17933), -INT16_C( 16404), -INT16_C(  3623), -INT16_C( 18016),  INT16_C( 24788), -INT16_C( 11878),  INT16_C( 19795), -INT16_C(  3596) },
      { -INT16_C(  8591), -INT16_C(   884), -INT16_C( 19858), -INT16_C(  8024), -INT16_C(  1915),  INT16_C( 14047),  INT16_C(  7825), -INT16_C( 24866),
        -INT16_C( 13724),  INT16_C( 15709), -INT16_C(   581), -INT16_C( 28426), -INT16_C( 28323), -INT16_C( 20383),  INT16_C( 21982),  INT16_C( 20385) },
      { -INT16_C( 11407), -INT16_C(  1915), -INT16_C( 14480),  INT16_C( 26877), -INT16_C( 26448),  INT16_C(  7825), -INT16_C( 23123), -INT16_C( 24866),
         INT16_C( 24788), -INT16_C( 28323),  INT16_C( 17414), -INT16_C( 27726), -INT16_C(  7932),  INT16_C( 21982), -INT16_C(  7745), -INT16_C(  3076) } },
    { {  INT16_C( 11571), -INT16_C( 24244), -INT16_C(  2849),  INT16_C( 25985),  INT16_C( 24812),  INT16_C( 32155),  INT16_C( 31103), -INT16_C(  7397),
         INT16_C( 30787), -INT16_C(   223),  INT16_C(  6006), -INT16_C( 11377), -INT16_C(  3928), -INT16_C( 30844),  INT16_C(  9541),  INT16_C( 30934) },
      UINT16_C( 8787),
      {  INT16_C( 12825), -INT16_C( 25834),  INT16_C(   919),  INT16_C( 13051),  INT16_C( 31360), -INT16_C( 25429), -INT16_C(  4258),  INT16_C( 32532),
        -INT16_C( 29970),  INT16_C( 32150),  INT16_C( 16222), -INT16_C(  7571), -INT16_C( 19770), -INT16_C( 25593),  INT16_C( 23082),  INT16_C( 17343) },
      { -INT16_C( 10867),  INT16_C(  9438), -INT16_C(  9512),  INT16_C( 22871),  INT16_C(   596), -INT16_C( 19723),  INT16_C(  2545), -INT16_C(  8399),
        -INT16_C( 14188), -INT16_C(  3492), -INT16_C( 14073), -INT16_C( 12844), -INT16_C(  9349), -INT16_C( 23191),  INT16_C( 10294), -INT16_C( 15383) },
      {  INT16_C( 31360),  INT16_C(   596), -INT16_C(  2849),  INT16_C( 25985), -INT16_C(  4258),  INT16_C( 32155),  INT16_C( 32532), -INT16_C(  7397),
         INT16_C( 30787), -INT16_C(  9349),  INT16_C(  6006), -INT16_C( 11377), -INT16_C(  3928),  INT16_C( 10294),  INT16_C(  9541),  INT16_C( 30934) } },
    { { -INT16_C( 14338), -INT16_C( 10521),  INT16_C( 16033), -INT16_C(  2513),  INT16_C(  9281),  INT16_C( 12968), -INT16_C(  9682), -INT16_C( 15854),
         INT16_C( 28322), -INT16_C( 22092), -INT16_C( 30664), -INT16_C( 19594), -INT16_C(  8349), -INT16_C( 26279),  INT16_C( 16904),  INT16_C(  1628) },
      UINT16_C(17417),
      { -INT16_C( 21540),  INT16_C(  3202), -INT16_C( 15455),  INT16_C( 18736),  INT16_C( 24310),  INT16_C(  2083), -INT16_C( 15072), -INT16_C( 11146),
        -INT16_C( 20882), -INT16_C(  7076), -INT16_C( 16286), -INT16_C( 17468), -INT16_C( 13223), -INT16_C( 18691),  INT16_C(  1746), -INT16_C( 20742) },
      {  INT16_C( 31921),  INT16_C( 21178), -INT16_C(  5312),  INT16_C( 13980), -INT16_C( 16567),  INT16_C( 27198), -INT16_C( 19323), -INT16_C(  3266),
        -INT16_C( 25757), -INT16_C( 14888), -INT16_C( 25509), -INT16_C( 19328),  INT16_C( 32104),  INT16_C( 14954),  INT16_C( 25731),  INT16_C( 13800) },
      {  INT16_C( 24310), -INT16_C( 10521),  INT16_C( 16033),  INT16_C( 27198),  INT16_C(  9281),  INT16_C( 12968), -INT16_C(  9682), -INT16_C( 15854),
         INT16_C( 28322), -INT16_C( 22092), -INT16_C( 18691), -INT16_C( 19594), -INT16_C(  8349), -INT16_C( 26279), -INT16_C( 20742),  INT16_C(  1628) } },
    { { -INT16_C( 23583),  INT16_C(  8583),  INT16_C(  9102), -INT16_C( 10409), -INT16_C( 27165),  INT16_C( 26689), -INT16_C( 32695), -INT16_C( 21413),
         INT16_C( 13083),  INT16_C( 30321), -INT16_C(  3633),  INT16_C( 14122), -INT16_C( 27282), -INT16_C(  3471),  INT16_C( 23289), -INT16_C(  9689) },
      UINT16_C(44797),
      { -INT16_C( 29701),  INT16_C( 21202), -INT16_C( 19102), -INT16_C( 23321),  INT16_C( 12573),  INT16_C( 30756),  INT16_C( 16349),  INT16_C( 20396),
         INT16_C( 31669), -INT16_C(  8384), -INT16_C( 20557),  INT16_C(  9332),  INT16_C( 28321), -INT16_C( 14210),  INT16_C( 31560),  INT16_C( 17526) },
      {  INT16_C( 18438),  INT16_C( 27030),  INT16_C( 32509),  INT16_C(  6669),  INT16_C( 12719), -INT16_C( 29549),  INT16_C( 16240),  INT16_C(  9691),
         INT16_C(  7354),  INT16_C( 27908),  INT16_C( 31179),  INT16_C( 27794),  INT16_C(  4327),  INT16_C( 12084), -INT16_C( 21876), -INT16_C( 28045) },
      {  INT16_C( 12573),  INT16_C(  8583),  INT16_C( 30756), -INT16_C( 29549),  INT16_C( 16349),  INT16_C( 16240),  INT16_C( 20396),  INT16_C(  9691),
         INT16_C( 13083),  INT16_C(  4327), -INT16_C( 14210),  INT16_C( 12084), -INT16_C( 27282), -INT16_C( 21876),  INT16_C( 23289), -INT16_C( 28045) } },
    { {  INT16_C(  2803), -INT16_C(  3845),  INT16_C(  2184),  INT16_C( 14091), -INT16_C( 25031), -INT16_C( 22077), -INT16_C( 24611), -INT16_C( 26674),
        -INT16_C( 11333), -INT16_C( 31227), -INT16_C( 26804),  INT16_C( 13298),  INT16_C(  9895),  INT16_C( 13154), -INT16_C( 10544), -INT16_C( 15418) },
      UINT16_C(49632),
      {  INT16_C( 26804), -INT16_C( 16438),  INT16_C(   927),  INT16_C( 25181),  INT16_C( 15021),  INT16_C( 31489), -INT16_C( 17199), -INT16_C( 10674),
        -INT16_C( 26046),  INT16_C( 13421),  INT16_C(  5581),  INT16_C( 12378),  INT16_C( 11080),  INT16_C(  3590), -INT16_C(  6418), -INT16_C( 23856) },
      { -INT16_C( 26034), -INT16_C(  4767), -INT16_C( 16739),  INT16_C( 19023),  INT16_C( 20984), -INT16_C( 13626),  INT16_C(  5133),  INT16_C( 20640),
         INT16_C(  3759),  INT16_C( 31876), -INT16_C(  8413),  INT16_C( 27564), -INT16_C( 19958), -INT16_C(  1926),  INT16_C( 19096), -INT16_C(  6501) },
      {  INT16_C(  2803), -INT16_C(  3845),  INT16_C(  2184),  INT16_C( 14091), -INT16_C( 25031),  INT16_C(  5133), -INT16_C( 10674),  INT16_C( 20640),
         INT16_C( 11080), -INT16_C( 31227), -INT16_C( 26804),  INT16_C( 13298),  INT16_C(  9895),  INT16_C( 13154), -INT16_C( 23856), -INT16_C(  6501) } },
    { { -INT16_C(   796), -INT16_C( 32301),  INT16_C(  9147), -INT16_C( 19508), -INT16_C( 28044), -INT16_C( 32387),  INT16_C(  7846),  INT16_C( 21969),
         INT16_C( 22060),  INT16_C( 20434),  INT16_C( 32309),  INT16_C( 16314),  INT16_C( 13361), -INT16_C( 14025), -INT16_C( 11650),  INT16_C( 25264) },
      UINT16_C(33743),
      { -INT16_C( 29980), -INT16_C( 20314),  INT16_C(  6717), -INT16_C( 17598), -INT16_C(  5988),  INT16_C( 28121),  INT16_C(  1342),  INT16_C(  4291),
        -INT16_C(  1964),  INT16_C(  3726), -INT16_C( 16585),  INT16_C( 28483), -INT16_C( 15991),  INT16_C( 14657),  INT16_C(  4132),  INT16_C(  2236) },
      {  INT16_C( 25498), -INT16_C( 10056), -INT16_C(  1411),  INT16_C(  6547),  INT16_C( 27874),  INT16_C(  8327),  INT16_C( 19057), -INT16_C( 15056),
        -INT16_C( 16573),  INT16_C( 31443),  INT16_C(  5758),  INT16_C(  2025),  INT16_C( 11224), -INT16_C(   960), -INT16_C(   709), -INT16_C( 10748) },
      { -INT16_C(  5988),  INT16_C( 27874),  INT16_C( 28121),  INT16_C(  8327), -INT16_C( 28044), -INT16_C( 32387),  INT16_C(  4291), -INT16_C( 15056),
        -INT16_C( 15991),  INT16_C( 11224),  INT16_C( 32309),  INT16_C( 16314),  INT16_C( 13361), -INT16_C( 14025), -INT16_C( 11650), -INT16_C( 10748) } },
    { { -INT16_C( 17312), -INT16_C(  8786),  INT16_C( 16822), -INT16_C( 26377),  INT16_C( 32429),  INT16_C(  7865), -INT16_C(  5688),  INT16_C(  3043),
        -INT16_C( 18776),  INT16_C( 10118),  INT16_C( 28621), -INT16_C( 23250),  INT16_C( 28570), -INT16_C( 10591), -INT16_C( 23188), -INT16_C( 13140) },
      UINT16_C(23137),
      {  INT16_C(  6057), -INT16_C( 24421),  INT16_C( 18607),  INT16_C( 26654), -INT16_C(  6298),  INT16_C( 18770), -INT16_C(  1294),  INT16_C( 30975),
        -INT16_C( 13279),  INT16_C( 20712), -INT16_C( 32143),  INT16_C(  4799),  INT16_C( 11096),  INT16_C(  1207),  INT16_C(  6391), -INT16_C( 24482) },
      { -INT16_C(  1745), -INT16_C(  8383),  INT16_C( 24385), -INT16_C( 22713), -INT16_C( 26298),  INT16_C( 14832), -INT16_C(  3948), -INT16_C( 19023),
        -INT16_C( 26180),  INT16_C( 11781), -INT16_C( 15332),  INT16_C( 29760), -INT16_C(  1809), -INT16_C(  6535), -INT16_C( 10480),  INT16_C( 16519) },
      { -INT16_C(  6298), -INT16_C(  8786),  INT16_C( 16822), -INT16_C( 26377),  INT16_C( 32429), -INT16_C(  3948),  INT16_C( 30975),  INT16_C(  3043),
        -INT16_C( 18776), -INT16_C(  1809),  INT16_C( 28621), -INT16_C(  6535),  INT16_C(  6391), -INT16_C( 10591), -INT16_C( 24482), -INT16_C( 13140) } },
    { { -INT16_C( 14127),  INT16_C(  4639),  INT16_C( 26151),  INT16_C( 28346), -INT16_C( 22016), -INT16_C( 27481),  INT16_C( 22682),  INT16_C( 22345),
         INT16_C( 20466),  INT16_C(  3717), -INT16_C( 15085),  INT16_C(   898), -INT16_C(  1091), -INT16_C( 12567),  INT16_C( 28883), -INT16_C( 23538) },
      UINT16_C(11576),
      {  INT16_C( 24758),  INT16_C( 28819), -INT16_C( 27698),  INT16_C( 29979), -INT16_C( 19161),  INT16_C( 29133), -INT16_C( 16628), -INT16_C( 28224),
        -INT16_C( 11315),  INT16_C( 20567),  INT16_C(  5334), -INT16_C( 16309),  INT16_C(  7906), -INT16_C(  4048),  INT16_C( 27074),  INT16_C( 31005) },
      { -INT16_C( 20023), -INT16_C( 26647),  INT16_C(  1092),  INT16_C( 27660), -INT16_C(  9798), -INT16_C( 14627), -INT16_C( 25191),  INT16_C( 26200),
        -INT16_C( 20624),  INT16_C( 18358),  INT16_C(   707), -INT16_C( 23033),  INT16_C( 14112), -INT16_C(  7274), -INT16_C( 19296),  INT16_C( 26972) },
      { -INT16_C( 14127),  INT16_C(  4639),  INT16_C( 26151), -INT16_C( 14627), -INT16_C( 16628), -INT16_C( 25191),  INT16_C( 22682),  INT16_C( 22345),
         INT16_C(  7906),  INT16_C(  3717), -INT16_C(  4048), -INT16_C(  7274), -INT16_C(  1091), -INT16_C( 19296),  INT16_C( 28883), -INT16_C( 23538) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256i src = simde_x_mm256_loadu_epi16(test_vec[i].src);
    simde__m256i a = simde_x_mm256_loadu_epi16(test_vec[i].a);
    simde__m256i b = simde_x_mm256_loadu_epi16(test_vec[i].b);
    simde__m256i r = simde_mm256_mask_unpackhi_epi16(src, test_vec[i].k, a, b);
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
    simde__m256i r = simde_mm256_mask_unpackhi_epi16(src, k, a, b);

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
test_simde_mm256_maskz_unpackhi_epi16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask16 k;
    const int16_t a[16];
    const int16_t b[16];
    const int16_t r[16];
  } test_vec[] = {
    { UINT16_C(45548),
      { -INT16_C(  1377), -INT16_C( 18059),  INT16_C( 31267),  INT16_C( 25478),  INT16_C(  7176),  INT16_C(  1040), -INT16_C( 18075), -INT16_C(  1694),
         INT16_C( 13717),  INT16_C( 11054), -INT16_C( 24361), -INT16_C( 19426), -INT16_C(  9319), -INT16_C( 18571),  INT16_C( 25011),  INT16_C( 21096) },
      { -INT16_C(  8612),  INT16_C( 32523), -INT16_C( 28072),  INT16_C( 24803), -INT16_C(  3154),  INT16_C(  4965), -INT16_C( 14420),  INT16_C( 16652),
         INT16_C( 15100), -INT16_C( 11155), -INT16_C( 29734),  INT16_C( 29576), -INT16_C(   665),  INT16_C(  6698), -INT16_C( 27809), -INT16_C( 17555) },
      {  INT16_C(     0),  INT16_C(     0),  INT16_C(  1040),  INT16_C(  4965),  INT16_C(     0), -INT16_C( 14420), -INT16_C(  1694),  INT16_C( 16652),
        -INT16_C(  9319),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C( 25011), -INT16_C( 27809),  INT16_C(     0), -INT16_C( 17555) } },
    { UINT16_C(30833),
      { -INT16_C( 14022),  INT16_C(  7434), -INT16_C( 18391), -INT16_C( 29167), -INT16_C( 16949), -INT16_C( 10410),  INT16_C( 21247),  INT16_C( 27665),
        -INT16_C(  5338), -INT16_C( 20745),  INT16_C( 24158), -INT16_C( 30292),  INT16_C(  2937), -INT16_C(  6628), -INT16_C( 29242),  INT16_C(    94) },
      {  INT16_C( 26966),  INT16_C( 32542),  INT16_C( 12065), -INT16_C(  4850),  INT16_C( 25836), -INT16_C(  5180), -INT16_C( 10570), -INT16_C(  8873),
         INT16_C( 20417),  INT16_C(  8331),  INT16_C( 14253),  INT16_C(  9897), -INT16_C( 15038),  INT16_C(  2060),  INT16_C( 27474), -INT16_C( 22519) },
      { -INT16_C( 16949),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C( 21247), -INT16_C( 10570),  INT16_C( 27665),  INT16_C(     0),
         INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(  2060), -INT16_C( 29242),  INT16_C( 27474),  INT16_C(    94),  INT16_C(     0) } },
    { UINT16_C(10196),
      { -INT16_C(  2777),  INT16_C( 13654),  INT16_C( 17122), -INT16_C( 22631),  INT16_C( 20526), -INT16_C( 31363),  INT16_C( 15917), -INT16_C( 18220),
        -INT16_C( 32162),  INT16_C(  2032),  INT16_C( 12968), -INT16_C( 18996),  INT16_C(  7739),  INT16_C( 17440), -INT16_C(  2874), -INT16_C(  4501) },
      { -INT16_C( 15895), -INT16_C( 13277), -INT16_C( 17149),  INT16_C( 12659), -INT16_C(  4083),  INT16_C( 15031), -INT16_C( 29906), -INT16_C( 29198),
        -INT16_C(  7667), -INT16_C( 18796),  INT16_C( 24853),  INT16_C( 20587), -INT16_C( 29825),  INT16_C( 18068), -INT16_C(   129),  INT16_C( 26676) },
      {  INT16_C(     0),  INT16_C(     0), -INT16_C( 31363),  INT16_C(     0),  INT16_C( 15917),  INT16_C(     0), -INT16_C( 18220), -INT16_C( 29198),
         INT16_C(  7739), -INT16_C( 29825),  INT16_C( 17440),  INT16_C(     0),  INT16_C(     0), -INT16_C(   129),  INT16_C(     0),  INT16_C(     0) } },
    { UINT16_C(22464),
      { -INT16_C( 15564), -INT16_C( 22764),  INT16_C(  8693), -INT16_C( 21353), -INT16_C( 14757),  INT16_C( 20023),  INT16_C( 17747), -INT16_C(  6352),
         INT16_C( 17915),  INT16_C( 26184), -INT16_C( 14187),  INT16_C( 10737),  INT16_C( 28686),  INT16_C( 16936), -INT16_C(  5928),  INT16_C(  3481) },
      { -INT16_C( 20820), -INT16_C( 24140),  INT16_C( 19663),  INT16_C( 11085), -INT16_C( 31726),  INT16_C( 25977), -INT16_C( 22071), -INT16_C( 15284),
        -INT16_C( 27153), -INT16_C( 31702),  INT16_C(  7005),  INT16_C( 27566), -INT16_C( 10613),  INT16_C( 25773),  INT16_C( 18111),  INT16_C( 27505) },
      {  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(  6352), -INT16_C( 15284),
         INT16_C( 28686), -INT16_C( 10613),  INT16_C( 16936),  INT16_C(     0), -INT16_C(  5928),  INT16_C(     0),  INT16_C(  3481),  INT16_C(     0) } },
    { UINT16_C( 9716),
      { -INT16_C( 15348),  INT16_C( 22897), -INT16_C( 31761),  INT16_C( 26845), -INT16_C( 22552),  INT16_C( 13585),  INT16_C(   107), -INT16_C( 26934),
         INT16_C( 10117),  INT16_C( 13233),  INT16_C( 15762),  INT16_C( 16137), -INT16_C( 14175),  INT16_C(  4741),  INT16_C( 31283),  INT16_C( 16183) },
      { -INT16_C( 22210),  INT16_C( 11672),  INT16_C( 30252),  INT16_C(  5525), -INT16_C( 23011), -INT16_C( 30646),  INT16_C(  5287),  INT16_C( 11294),
        -INT16_C( 12229), -INT16_C( 12961),  INT16_C( 26637), -INT16_C( 20980), -INT16_C( 28367),  INT16_C( 25792), -INT16_C(  2293),  INT16_C( 18852) },
      {  INT16_C(     0),  INT16_C(     0),  INT16_C( 13585),  INT16_C(     0),  INT16_C(   107),  INT16_C(  5287), -INT16_C( 26934),  INT16_C( 11294),
        -INT16_C( 14175),  INT16_C(     0),  INT16_C(  4741),  INT16_C(     0),  INT16_C(     0), -INT16_C(  2293),  INT16_C(     0),  INT16_C(     0) } },
    { UINT16_C(15520),
      { -INT16_C( 12938),  INT16_C(  2994), -INT16_C( 12318),  INT16_C( 11442),  INT16_C( 22872),  INT16_C( 30272),  INT16_C( 31621), -INT16_C(  7098),
         INT16_C( 21320),  INT16_C( 21580),  INT16_C( 32001), -INT16_C( 15899), -INT16_C(  3614), -INT16_C( 31047),  INT16_C( 22842), -INT16_C( 20030) },
      {  INT16_C( 29990),  INT16_C(  2236),  INT16_C( 28228), -INT16_C( 25548),  INT16_C( 29895),  INT16_C( 19475),  INT16_C( 23023),  INT16_C( 14128),
         INT16_C( 32173), -INT16_C( 20853),  INT16_C( 29178), -INT16_C(  9104),  INT16_C( 10594), -INT16_C( 25502),  INT16_C(  9602), -INT16_C( 22195) },
      {  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C( 23023),  INT16_C(     0),  INT16_C( 14128),
         INT16_C(     0),  INT16_C(     0), -INT16_C( 31047), -INT16_C( 25502),  INT16_C( 22842),  INT16_C(  9602),  INT16_C(     0),  INT16_C(     0) } },
    { UINT16_C( 2714),
      { -INT16_C(  8527), -INT16_C(  6536),  INT16_C( 16507), -INT16_C( 29094),  INT16_C( 19084), -INT16_C( 16921), -INT16_C( 27519),  INT16_C(  3386),
         INT16_C( 13379), -INT16_C( 19586), -INT16_C(  8175),  INT16_C( 29660),  INT16_C( 24188), -INT16_C( 13672),  INT16_C( 12807), -INT16_C( 17964) },
      {  INT16_C( 19473), -INT16_C( 29537), -INT16_C(  1652),  INT16_C(  6426),  INT16_C(   323), -INT16_C( 14890),  INT16_C(  4246), -INT16_C(  9774),
         INT16_C( 20548),  INT16_C( 21900),  INT16_C( 26672), -INT16_C( 21303),  INT16_C( 25030), -INT16_C( 12682),  INT16_C( 19092), -INT16_C( 23161) },
      {  INT16_C(     0),  INT16_C(   323),  INT16_C(     0), -INT16_C( 14890), -INT16_C( 27519),  INT16_C(     0),  INT16_C(     0), -INT16_C(  9774),
         INT16_C(     0),  INT16_C( 25030),  INT16_C(     0), -INT16_C( 12682),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
    { UINT16_C( 9879),
      {  INT16_C(  9009),  INT16_C( 19231),  INT16_C( 25404),  INT16_C(  4684), -INT16_C(  7640), -INT16_C(  1502),  INT16_C( 26555),  INT16_C( 18250),
         INT16_C( 31420), -INT16_C( 31313),  INT16_C( 30246), -INT16_C( 25113),  INT16_C( 31556), -INT16_C( 13337),  INT16_C( 32288),  INT16_C( 20977) },
      {  INT16_C(  4258), -INT16_C(  8548), -INT16_C(  6029), -INT16_C( 25615),  INT16_C(  5067), -INT16_C( 31083), -INT16_C(  8326),  INT16_C( 14286),
         INT16_C( 32089), -INT16_C( 32580), -INT16_C( 23565),  INT16_C( 14109),  INT16_C(  1054),  INT16_C( 15874), -INT16_C(  3197),  INT16_C(  9615) },
      { -INT16_C(  7640),  INT16_C(  5067), -INT16_C(  1502),  INT16_C(     0),  INT16_C( 26555),  INT16_C(     0),  INT16_C(     0),  INT16_C( 14286),
         INT16_C(     0),  INT16_C(  1054), -INT16_C( 13337),  INT16_C(     0),  INT16_C(     0), -INT16_C(  3197),  INT16_C(     0),  INT16_C(     0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256i a = simde_x_mm256_loadu_epi16(test_vec[i].a);
    simde__m256i b = simde_x_mm256_loadu_epi16(test_vec[i].b);
    simde__m256i r = simde_mm256_maskz_unpackhi_epi16(test_vec[i].k, a, b);
    simde_test_x86_assert_equal_i16x16(r, simde_x_mm256_loadu_epi16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask16 k = simde_test_x86_random_mmask16();
    simde__m256i a = simde_test_x86_random_i16x16();
    simde__m256i b = simde_test_x86_random_i16x16();
    simde__m256i r = simde_mm256_maskz_unpackhi_epi16(k, a, b);

    simde_test_x86_write_mmask16(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i16x16(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_mask_unpackhi_epi16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int16_t src[8];
    const simde__mmask8 k;
    const int16_t a[8];
    const int16_t b[8];
    const int16_t r[8];
  } test_vec[] = {
    { { -INT16_C(  6787), -INT16_C( 29099), -INT16_C( 24931), -INT16_C( 25143),  INT16_C( 21963), -INT16_C( 15407), -INT16_C( 23190),  INT16_C( 20649) },
      UINT8_C(241),
      { -INT16_C( 10579),  INT16_C( 28765),  INT16_C( 23030),  INT16_C( 12199),  INT16_C(  5114), -INT16_C(    32),  INT16_C( 29380), -INT16_C( 22148) },
      {  INT16_C(  3015),  INT16_C( 25926), -INT16_C(  7212),  INT16_C( 10800), -INT16_C(  2891),  INT16_C( 23188), -INT16_C(  7011),  INT16_C( 19276) },
      {  INT16_C(  5114), -INT16_C( 29099), -INT16_C( 24931), -INT16_C( 25143),  INT16_C( 29380), -INT16_C(  7011), -INT16_C( 22148),  INT16_C( 19276) } },
    { { -INT16_C( 22086), -INT16_C( 20293),  INT16_C( 25090), -INT16_C(   801), -INT16_C( 16523),  INT16_C( 14844),  INT16_C( 30769), -INT16_C(  1822) },
      UINT8_C(131),
      {  INT16_C( 23848),  INT16_C(  3160), -INT16_C( 32114), -INT16_C( 32063),  INT16_C(  6934), -INT16_C(  1505),  INT16_C( 27239),  INT16_C(  4277) },
      {  INT16_C( 25893), -INT16_C( 30957),  INT16_C(  3909),  INT16_C(  1277),  INT16_C( 13835), -INT16_C( 31690),  INT16_C( 11801),  INT16_C( 16647) },
      {  INT16_C(  6934),  INT16_C( 13835),  INT16_C( 25090), -INT16_C(   801), -INT16_C( 16523),  INT16_C( 14844),  INT16_C( 30769),  INT16_C( 16647) } },
    { {  INT16_C( 24460),  INT16_C(  6733),  INT16_C(  3809), -INT16_C(  2148), -INT16_C( 17622), -INT16_C( 28174), -INT16_C( 22746),  INT16_C( 19362) },
      UINT8_C( 12),
      { -INT16_C( 11339), -INT16_C( 15279),  INT16_C( 22224),  INT16_C(  1744),  INT16_C( 21644), -INT16_C( 17889),  INT16_C( 24923), -INT16_C( 17594) },
      {  INT16_C( 24750), -INT16_C( 16996), -INT16_C( 27396), -INT16_C( 18201),  INT16_C( 30854),  INT16_C( 11742),  INT16_C( 10522), -INT16_C( 12487) },
      {  INT16_C( 24460),  INT16_C(  6733), -INT16_C( 17889),  INT16_C( 11742), -INT16_C( 17622), -INT16_C( 28174), -INT16_C( 22746),  INT16_C( 19362) } },
    { { -INT16_C( 29700), -INT16_C( 13164),  INT16_C( 25825),  INT16_C( 28115), -INT16_C(  3400),  INT16_C(  4903),  INT16_C( 28243),  INT16_C(   718) },
      UINT8_C(206),
      { -INT16_C( 16533), -INT16_C(    53), -INT16_C( 31834),  INT16_C(  7813), -INT16_C( 19871), -INT16_C( 30151),  INT16_C(  2283),  INT16_C( 30343) },
      {  INT16_C( 21404),  INT16_C(    87), -INT16_C( 15322),  INT16_C(  6584), -INT16_C( 13076),  INT16_C( 23148),  INT16_C( 28314),  INT16_C(  1320) },
      { -INT16_C( 29700), -INT16_C( 13076), -INT16_C( 30151),  INT16_C( 23148), -INT16_C(  3400),  INT16_C(  4903),  INT16_C( 30343),  INT16_C(  1320) } },
    { { -INT16_C(  3283), -INT16_C( 11516), -INT16_C( 30346), -INT16_C( 10254),  INT16_C( 11067),  INT16_C( 10082), -INT16_C(  5837), -INT16_C( 12131) },
      UINT8_C( 60),
      { -INT16_C( 12043), -INT16_C( 18077),  INT16_C( 31881),  INT16_C( 21925), -INT16_C(    24),  INT16_C( 22511), -INT16_C(  2776),  INT16_C(  7044) },
      {  INT16_C( 22777), -INT16_C( 31854),  INT16_C( 26954),  INT16_C( 30142), -INT16_C(  6709), -INT16_C( 19288),  INT16_C( 30851),  INT16_C( 30961) },
      { -INT16_C(  3283), -INT16_C( 11516),  INT16_C( 22511), -INT16_C( 19288), -INT16_C(  2776),  INT16_C( 30851), -INT16_C(  5837), -INT16_C( 12131) } },
    { {  INT16_C( 21577), -INT16_C( 11727), -INT16_C( 10288), -INT16_C( 18393),  INT16_C(  5846), -INT16_C(   497), -INT16_C( 27637),  INT16_C(  1306) },
      UINT8_C(236),
      { -INT16_C( 30548),  INT16_C(  5430), -INT16_C( 21690),  INT16_C( 11489), -INT16_C( 27309), -INT16_C( 13137),  INT16_C( 10118), -INT16_C(  9707) },
      { -INT16_C(  6312),  INT16_C( 12202),  INT16_C( 25358),  INT16_C(  9222),  INT16_C(  1138),  INT16_C(  1584),  INT16_C( 13598), -INT16_C( 13582) },
      {  INT16_C( 21577), -INT16_C( 11727), -INT16_C( 13137),  INT16_C(  1584),  INT16_C(  5846),  INT16_C( 13598), -INT16_C(  9707), -INT16_C( 13582) } },
    { {  INT16_C( 10429),  INT16_C(   992), -INT16_C( 15917),  INT16_C( 10031), -INT16_C(  8618), -INT16_C(  8717),  INT16_C(  2053),  INT16_C( 24247) },
      UINT8_C(239),
      { -INT16_C( 29342), -INT16_C( 14851),  INT16_C(  8595), -INT16_C( 26569),  INT16_C( 15953), -INT16_C( 31050), -INT16_C( 32464),  INT16_C( 22851) },
      {  INT16_C( 18273),  INT16_C(  8748),  INT16_C( 21366),  INT16_C( 21880),  INT16_C( 21830),  INT16_C( 20058), -INT16_C( 18419),  INT16_C( 28477) },
      {  INT16_C( 15953),  INT16_C( 21830), -INT16_C( 31050),  INT16_C( 20058), -INT16_C(  8618), -INT16_C( 18419),  INT16_C( 22851),  INT16_C( 28477) } },
    { {  INT16_C( 14918), -INT16_C(  9932),  INT16_C( 27484), -INT16_C( 21135),  INT16_C( 10409), -INT16_C(  9676),  INT16_C( 30633),  INT16_C(  2611) },
      UINT8_C(190),
      {  INT16_C( 11359), -INT16_C( 19659), -INT16_C( 30044), -INT16_C(  1287),  INT16_C( 18660), -INT16_C( 25337),  INT16_C( 30341), -INT16_C( 16157) },
      { -INT16_C( 17238),  INT16_C(  5404), -INT16_C( 14034),  INT16_C( 22207), -INT16_C( 26115),  INT16_C( 30207),  INT16_C(  2508),  INT16_C( 11059) },
      {  INT16_C( 14918), -INT16_C( 26115), -INT16_C( 25337),  INT16_C( 30207),  INT16_C( 30341),  INT16_C(  2508),  INT16_C( 30633),  INT16_C( 11059) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i src = simde_mm_loadu_epi16(test_vec[i].src);
    simde__m128i a = simde_mm_loadu_epi16(test_vec[i].a);
    simde__m128i b = simde_mm_loadu_epi16(test_vec[i].b);
    simde__m128i r = simde_mm_mask_unpackhi_epi16(src, test_vec[i].k, a, b);
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
    simde__m128i r = simde_mm_mask_unpackhi_epi16(src, k, a, b);

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
test_simde_mm_maskz_unpackhi_epi16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k;
    const int16_t a[8];
    const int16_t b[8];
    const int16_t r[8];
  } test_vec[] = {
    { UINT8_C(160),
      { -INT16_C( 13078),  INT16_C( 17682),  INT16_C( 14218), -INT16_C(  9595),  INT16_C( 24818),  INT16_C( 29161),  INT16_C(  1979), -INT16_C( 26997) },
      { -INT16_C( 27910),  INT16_C( 28890), -INT16_C( 12036), -INT16_C( 16083),  INT16_C(  1049), -INT16_C(  8334), -INT16_C(  1010), -INT16_C(  1921) },
      {  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(  1010),  INT16_C(     0), -INT16_C(  1921) } },
    { UINT8_C(200),
      {  INT16_C( 16017), -INT16_C( 14254),  INT16_C( 11715),  INT16_C(  9146),  INT16_C( 11286),  INT16_C(  7647),  INT16_C( 30135),  INT16_C( 18711) },
      { -INT16_C( 30641),  INT16_C(  8005),  INT16_C(  1717), -INT16_C( 18119),  INT16_C(  6264),  INT16_C( 30151), -INT16_C( 16488),  INT16_C( 10557) },
      {  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C( 30151),  INT16_C(     0),  INT16_C(     0),  INT16_C( 18711),  INT16_C( 10557) } },
    { UINT8_C(253),
      { -INT16_C(  3440), -INT16_C( 16959), -INT16_C(  6996), -INT16_C( 10029), -INT16_C(  3645),  INT16_C( 14479), -INT16_C( 10232), -INT16_C( 28536) },
      { -INT16_C( 22755),  INT16_C(  9285), -INT16_C(   288), -INT16_C(  1636),  INT16_C(  4549), -INT16_C( 31343), -INT16_C( 17841), -INT16_C(  8318) },
      { -INT16_C(  3645),  INT16_C(     0),  INT16_C( 14479), -INT16_C( 31343), -INT16_C( 10232), -INT16_C( 17841), -INT16_C( 28536), -INT16_C(  8318) } },
    { UINT8_C(172),
      { -INT16_C( 25533),  INT16_C( 10329),  INT16_C( 12655),  INT16_C( 24811),  INT16_C(  9409), -INT16_C( 26263), -INT16_C(  1620),  INT16_C( 21431) },
      { -INT16_C(  9409),  INT16_C( 15668),  INT16_C( 11639), -INT16_C( 30461), -INT16_C( 30530),  INT16_C( 30936), -INT16_C( 18678),  INT16_C( 20005) },
      {  INT16_C(     0),  INT16_C(     0), -INT16_C( 26263),  INT16_C( 30936),  INT16_C(     0), -INT16_C( 18678),  INT16_C(     0),  INT16_C( 20005) } },
    { UINT8_C( 83),
      {  INT16_C( 30334), -INT16_C( 20542),  INT16_C(  9057), -INT16_C( 31376),  INT16_C(  2700), -INT16_C( 31439), -INT16_C( 31295), -INT16_C( 25404) },
      {  INT16_C(   697), -INT16_C(  6637), -INT16_C( 25595), -INT16_C( 29276),  INT16_C(  7284),  INT16_C( 11159), -INT16_C(  6847), -INT16_C( 16514) },
      {  INT16_C(  2700),  INT16_C(  7284),  INT16_C(     0),  INT16_C(     0), -INT16_C( 31295),  INT16_C(     0), -INT16_C( 25404),  INT16_C(     0) } },
    { UINT8_C( 91),
      {  INT16_C( 28481),  INT16_C( 25789),  INT16_C( 17119), -INT16_C(  5648),  INT16_C( 30068), -INT16_C(  1622),  INT16_C( 17978),  INT16_C( 15538) },
      { -INT16_C( 26534), -INT16_C(  2495), -INT16_C( 12740),  INT16_C( 22635), -INT16_C( 27035),  INT16_C( 19354),  INT16_C( 22805),  INT16_C( 22182) },
      {  INT16_C( 30068), -INT16_C( 27035),  INT16_C(     0),  INT16_C( 19354),  INT16_C( 17978),  INT16_C(     0),  INT16_C( 15538),  INT16_C(     0) } },
    { UINT8_C(200),
      { -INT16_C( 17821), -INT16_C( 22872), -INT16_C( 28246),  INT16_C(  7962),  INT16_C(  4924), -INT16_C( 32167), -INT16_C( 27195),  INT16_C( 24028) },
      { -INT16_C( 11306), -INT16_C( 23399), -INT16_C(  3778), -INT16_C( 11254),  INT16_C( 21899), -INT16_C(  6679),  INT16_C( 16379),  INT16_C( 24493) },
      {  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(  6679),  INT16_C(     0),  INT16_C(     0),  INT16_C( 24028),  INT16_C( 24493) } },
    { UINT8_C(249),
      {  INT16_C(  1365), -INT16_C(  6237), -INT16_C( 15585),  INT16_C( 12835), -INT16_C( 23268), -INT16_C( 19721),  INT16_C( 21634),  INT16_C( 21896) },
      {  INT16_C( 11757), -INT16_C(  8557),  INT16_C( 26423), -INT16_C( 29590),  INT16_C( 20305), -INT16_C( 28537), -INT16_C(  6404),  INT16_C( 21130) },
      { -INT16_C( 23268),  INT16_C(     0),  INT16_C(     0), -INT16_C( 28537),  INT16_C( 21634), -INT16_C(  6404),  INT16_C( 21896),  INT16_C( 21130) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_x_mm_loadu_epi16(test_vec[i].a);
    simde__m128i b = simde_x_mm_loadu_epi16(test_vec[i].b);
    simde__m128i r = simde_mm_maskz_unpackhi_epi16(test_vec[i].k, a, b);
    simde_test_x86_assert_equal_i16x8(r, simde_x_mm_loadu_epi16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m128i a = simde_test_x86_random_i16x8();
    simde__m128i b = simde_test_x86_random_i16x8();
    simde__m128i r = simde_mm_maskz_unpackhi_epi16(k, a, b);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i16x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_unpackhi_epi32 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const int32_t a[16];
    const int32_t b[16];
    const int32_t r[16];
  } test_vec[] = {
    { { -INT32_C(  2071539538), -INT32_C(  1292562566), -INT32_C(   411127984), -INT32_C(  1435371435),  INT32_C(   903717735), -INT32_C(  1003795278), -INT32_C(   469164256), -INT32_C(   618004435),
         INT32_C(  1247785168),  INT32_C(   285038015),  INT32_C(  1509391108), -INT32_C(   637245069), -INT32_C(  1106255604),  INT32_C(  1300380205), -INT32_C(  2043573415),  INT32_C(  1533107083) },
      { -INT32_C(   878264308),  INT32_C(   450601749), -INT32_C(  1854680290),  INT32_C(  1215002428), -INT32_C(  2063173032),  INT32_C(   231901364), -INT32_C(  1617755373),  INT32_C(  1811608671),
        -INT32_C(   902389580),  INT32_C(  1642336835),  INT32_C(   569530341),  INT32_C(   661216719), -INT32_C(  1951567913),  INT32_C(   177766391), -INT32_C(   492229757), -INT32_C(   733109217) },
      { -INT32_C(   411127984), -INT32_C(  1854680290), -INT32_C(  1435371435),  INT32_C(  1215002428), -INT32_C(   469164256), -INT32_C(  1617755373), -INT32_C(   618004435),  INT32_C(  1811608671),
         INT32_C(  1509391108),  INT32_C(   569530341), -INT32_C(   637245069),  INT32_C(   661216719), -INT32_C(  2043573415), -INT32_C(   492229757),  INT32_C(  1533107083), -INT32_C(   733109217) } },
    { { -INT32_C(  2002877628),  INT32_C(  2062123669), -INT32_C(  1466180391),  INT32_C(   298845241),  INT32_C(  1788640627),  INT32_C(  2138387964), -INT32_C(  2141118880),  INT32_C(   122990274),
        -INT32_C(   946867662),  INT32_C(  1296201844), -INT32_C(  1896424108),  INT32_C(  1436534498),  INT32_C(  1069562691), -INT32_C(   775998096),  INT32_C(   374415443),  INT32_C(    18720207) },
      {  INT32_C(   197700759),  INT32_C(  2035812900), -INT32_C(   905490712),  INT32_C(  1461691924),  INT32_C(  1385684961),  INT32_C(  1747146260),  INT32_C(  1165915254), -INT32_C(  1337550055),
         INT32_C(  1807421255),  INT32_C(    31724313),  INT32_C(  1993075554),  INT32_C(  1942940561), -INT32_C(   540711478),  INT32_C(   826796219),  INT32_C(  1970783580), -INT32_C(  1490698912) },
      { -INT32_C(  1466180391), -INT32_C(   905490712),  INT32_C(   298845241),  INT32_C(  1461691924), -INT32_C(  2141118880),  INT32_C(  1165915254),  INT32_C(   122990274), -INT32_C(  1337550055),
        -INT32_C(  1896424108),  INT32_C(  1993075554),  INT32_C(  1436534498),  INT32_C(  1942940561),  INT32_C(   374415443),  INT32_C(  1970783580),  INT32_C(    18720207), -INT32_C(  1490698912) } },
    { { -INT32_C(   434970420),  INT32_C(  1441265651),  INT32_C(  1959572450),  INT32_C(  1760008862), -INT32_C(  1169707777), -INT32_C(   252997996), -INT32_C(  1285201325), -INT32_C(   329610720),
         INT32_C(  1574071658),  INT32_C(  1186183780),  INT32_C(   196771693),  INT32_C(   410231065), -INT32_C(   506283187), -INT32_C(  1647198903),  INT32_C(  1078998560),  INT32_C(   707570624) },
      {  INT32_C(  2089352984),  INT32_C(   650263481), -INT32_C(   751731270),  INT32_C(  1827382302), -INT32_C(  1454523041), -INT32_C(  1706680454),  INT32_C(   383424085),  INT32_C(  1497368385),
        -INT32_C(  1076508666), -INT32_C(  1109026813),  INT32_C(   865080853),  INT32_C(   446659514), -INT32_C(  1279005384),  INT32_C(  1632438540), -INT32_C(   512284513),  INT32_C(   893040687) },
      {  INT32_C(  1959572450), -INT32_C(   751731270),  INT32_C(  1760008862),  INT32_C(  1827382302), -INT32_C(  1285201325),  INT32_C(   383424085), -INT32_C(   329610720),  INT32_C(  1497368385),
         INT32_C(   196771693),  INT32_C(   865080853),  INT32_C(   410231065),  INT32_C(   446659514),  INT32_C(  1078998560), -INT32_C(   512284513),  INT32_C(   707570624),  INT32_C(   893040687) } },
    { { -INT32_C(  2064379776), -INT32_C(  1119757912), -INT32_C(  1443835153), -INT32_C(  2034003891), -INT32_C(  1992718723),  INT32_C(   803899023), -INT32_C(   586128722), -INT32_C(  1710077414),
         INT32_C(    35522138), -INT32_C(   826318625),  INT32_C(  2138615858), -INT32_C(  1123730624),  INT32_C(  1363558082),  INT32_C(  1937780933), -INT32_C(  1403940718),  INT32_C(   893871067) },
      {  INT32_C(  1228432746), -INT32_C(   149358651), -INT32_C(   411594585), -INT32_C(  1918599989), -INT32_C(  2132809029), -INT32_C(  1376559333), -INT32_C(   883276560),  INT32_C(   302031272),
        -INT32_C(   866437114), -INT32_C(   675056848), -INT32_C(   809551357),  INT32_C(  1918657463),  INT32_C(  1777482574), -INT32_C(  1961433701), -INT32_C(   766087126),  INT32_C(   417617425) },
      { -INT32_C(  1443835153), -INT32_C(   411594585), -INT32_C(  2034003891), -INT32_C(  1918599989), -INT32_C(   586128722), -INT32_C(   883276560), -INT32_C(  1710077414),  INT32_C(   302031272),
         INT32_C(  2138615858), -INT32_C(   809551357), -INT32_C(  1123730624),  INT32_C(  1918657463), -INT32_C(  1403940718), -INT32_C(   766087126),  INT32_C(   893871067),  INT32_C(   417617425) } },
    { { -INT32_C(  1075560561), -INT32_C(  1231640653), -INT32_C(  1719314974),  INT32_C(   118219449), -INT32_C(  1200554723),  INT32_C(   205752034),  INT32_C(   148806135),  INT32_C(  2132853488),
        -INT32_C(  1254226942), -INT32_C(  1905535828), -INT32_C(   483921622), -INT32_C(   253087021),  INT32_C(   296311343), -INT32_C(   685839136),  INT32_C(  1994456198), -INT32_C(  1040908097) },
      { -INT32_C(  1317653755),  INT32_C(   826269959), -INT32_C(  1525389614), -INT32_C(   946405736),  INT32_C(   970473304), -INT32_C(  1324288469), -INT32_C(  1306005261), -INT32_C(   160228111),
         INT32_C(  1470622031), -INT32_C(  1651972406), -INT32_C(   465396404), -INT32_C(   190064485),  INT32_C(  1127056151),  INT32_C(  1844723066),  INT32_C(   522132526), -INT32_C(  2011852232) },
      { -INT32_C(  1719314974), -INT32_C(  1525389614),  INT32_C(   118219449), -INT32_C(   946405736),  INT32_C(   148806135), -INT32_C(  1306005261),  INT32_C(  2132853488), -INT32_C(   160228111),
        -INT32_C(   483921622), -INT32_C(   465396404), -INT32_C(   253087021), -INT32_C(   190064485),  INT32_C(  1994456198),  INT32_C(   522132526), -INT32_C(  1040908097), -INT32_C(  2011852232) } },
    { {  INT32_C(  1172290683), -INT32_C(   287152222), -INT32_C(  1596840700),  INT32_C(   362053117),  INT32_C(  2052636928),  INT32_C(   753356030), -INT32_C(  1588918680),  INT32_C(   321478808),
        -INT32_C(  1101461476),  INT32_C(  1957444463),  INT32_C(  1578401376), -INT32_C(    59528965),  INT32_C(  1735838569), -INT32_C(  2137760233), -INT32_C(    48111772),  INT32_C(  1544571456) },
      { -INT32_C(  1055168174),  INT32_C(    87410597),  INT32_C(  1097025862),  INT32_C(  1514002161), -INT32_C(  1178422111),  INT32_C(  1983469074),  INT32_C(  1970494005), -INT32_C(   153975644),
        -INT32_C(  1833439763), -INT32_C(    90640972),  INT32_C(   675085110),  INT32_C(  1937930706),  INT32_C(  1059865645), -INT32_C(   793352806),  INT32_C(  1665477055), -INT32_C(  1688660051) },
      { -INT32_C(  1596840700),  INT32_C(  1097025862),  INT32_C(   362053117),  INT32_C(  1514002161), -INT32_C(  1588918680),  INT32_C(  1970494005),  INT32_C(   321478808), -INT32_C(   153975644),
         INT32_C(  1578401376),  INT32_C(   675085110), -INT32_C(    59528965),  INT32_C(  1937930706), -INT32_C(    48111772),  INT32_C(  1665477055),  INT32_C(  1544571456), -INT32_C(  1688660051) } },
    { { -INT32_C(  1188228860),  INT32_C(   884196862), -INT32_C(  1822625855), -INT32_C(  1777934487), -INT32_C(  1093258461),  INT32_C(  1485737112),  INT32_C(  1673253813), -INT32_C(   268560917),
         INT32_C(   615000870), -INT32_C(  1302831887), -INT32_C(  1270500021), -INT32_C(  1219802220),  INT32_C(   393552254),  INT32_C(  1651442605), -INT32_C(  1027265833),  INT32_C(  1706148671) },
      { -INT32_C(   527869201),  INT32_C(    26403510),  INT32_C(   733403031), -INT32_C(  1579024094), -INT32_C(   810002398),  INT32_C(   842082139), -INT32_C(  1846216879), -INT32_C(  1443453254),
        -INT32_C(  1232502784), -INT32_C(   105440414),  INT32_C(   354708978), -INT32_C(  1867118994), -INT32_C(  1168150946), -INT32_C(   420703851),  INT32_C(  1115152776), -INT32_C(  2014548345) },
      { -INT32_C(  1822625855),  INT32_C(   733403031), -INT32_C(  1777934487), -INT32_C(  1579024094),  INT32_C(  1673253813), -INT32_C(  1846216879), -INT32_C(   268560917), -INT32_C(  1443453254),
        -INT32_C(  1270500021),  INT32_C(   354708978), -INT32_C(  1219802220), -INT32_C(  1867118994), -INT32_C(  1027265833),  INT32_C(  1115152776),  INT32_C(  1706148671), -INT32_C(  2014548345) } },
    { {  INT32_C(  1346205166), -INT32_C(  2092305263), -INT32_C(   795316894), -INT32_C(   765374861),  INT32_C(  1368178876), -INT32_C(   650610607), -INT32_C(   534991015),  INT32_C(   191301661),
         INT32_C(   240886909), -INT32_C(    74275687), -INT32_C(  2050282991),  INT32_C(   894905465),  INT32_C(  1049093101), -INT32_C(  1256669349), -INT32_C(  1936378770), -INT32_C(  1181221572) },
      {  INT32_C(   986248097), -INT32_C(  1456121193), -INT32_C(    47316604),  INT32_C(   439584045), -INT32_C(  1017529752), -INT32_C(   411537031), -INT32_C(   512553307), -INT32_C(  1399190773),
        -INT32_C(  1779997954),  INT32_C(  1094589628),  INT32_C(  1262382109),  INT32_C(  1499820529), -INT32_C(  1541554645), -INT32_C(   728984273), -INT32_C(  1363804253),  INT32_C(   140201994) },
      { -INT32_C(   795316894), -INT32_C(    47316604), -INT32_C(   765374861),  INT32_C(   439584045), -INT32_C(   534991015), -INT32_C(   512553307),  INT32_C(   191301661), -INT32_C(  1399190773),
        -INT32_C(  2050282991),  INT32_C(  1262382109),  INT32_C(   894905465),  INT32_C(  1499820529), -INT32_C(  1936378770), -INT32_C(  1363804253), -INT32_C(  1181221572),  INT32_C(   140201994) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i a = simde_mm512_loadu_epi32(test_vec[i].a);
    simde__m512i b = simde_mm512_loadu_epi32(test_vec[i].b);
    simde__m512i r = simde_mm512_unpackhi_epi32(a, b);
    simde_test_x86_assert_equal_i32x16(r, simde_mm512_loadu_epi32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_mm512_mask_unpackhi_epi32 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const int32_t src[16];
    const simde__mmask16 k;
    const int32_t a[16];
    const int32_t b[16];
    const int32_t r[16];
  } test_vec[] = {
    { { -INT32_C(   845938351),  INT32_C(   181822741), -INT32_C(   904073692),  INT32_C(  1797241754), -INT32_C(  1981644741), -INT32_C(   725414939), -INT32_C(   676171526), -INT32_C(  1255219612),
        -INT32_C(   192757025),  INT32_C(  1291737128), -INT32_C(   518579385),  INT32_C(   306984662), -INT32_C(  1667551562),  INT32_C(   863002169),  INT32_C(   839525070), -INT32_C(   538494976) },
      UINT16_C(27131),
      { -INT32_C(   759028780), -INT32_C(  2031285905),  INT32_C(   918406378),  INT32_C(  1902408662), -INT32_C(  2133877489), -INT32_C(   626876976), -INT32_C(  1240226865),  INT32_C(  1444875906),
        -INT32_C(  1607868111), -INT32_C(   735635734), -INT32_C(  1341463334),  INT32_C(  1730244183), -INT32_C(   605556725),  INT32_C(  1555466637), -INT32_C(  1357723348),  INT32_C(   134558423) },
      { -INT32_C(    22532589),  INT32_C(   533909317),  INT32_C(   198237619),  INT32_C(  1467150667),  INT32_C(  1865570786),  INT32_C(   265087202), -INT32_C(  2000757071),  INT32_C(   613466896),
         INT32_C(   924989938), -INT32_C(  1135152120),  INT32_C(   499590865), -INT32_C(    93046504),  INT32_C(  1953080978),  INT32_C(  1082340751),  INT32_C(   617169172), -INT32_C(   146253563) },
      {  INT32_C(   918406378),  INT32_C(   198237619), -INT32_C(   904073692),  INT32_C(  1467150667), -INT32_C(  1240226865), -INT32_C(  2000757071),  INT32_C(  1444875906),  INT32_C(   613466896),
        -INT32_C(  1341463334),  INT32_C(  1291737128), -INT32_C(   518579385), -INT32_C(    93046504), -INT32_C(  1667551562),  INT32_C(   617169172),  INT32_C(   134558423), -INT32_C(   538494976) } },
    { { -INT32_C(  1691456878),  INT32_C(   811041887), -INT32_C(  1018356053), -INT32_C(   373440169), -INT32_C(   144890264),  INT32_C(  1882710364),  INT32_C(   664010786), -INT32_C(   333521574),
        -INT32_C(  1501082553),  INT32_C(  2094522065),  INT32_C(  1396647164),  INT32_C(  1312619750),  INT32_C(  2118490658), -INT32_C(  1645314949), -INT32_C(   674921603), -INT32_C(  1480334496) },
      UINT16_C(19248),
      {  INT32_C(   623444302), -INT32_C(  1136056707), -INT32_C(  1229443207), -INT32_C(  1034888579),  INT32_C(  1195363161),  INT32_C(   768261224),  INT32_C(  1443965587),  INT32_C(   547439058),
        -INT32_C(  1085945022),  INT32_C(  1786482417),  INT32_C(   991966142),  INT32_C(  1727950861), -INT32_C(  1532084933), -INT32_C(  1932429063),  INT32_C(  1977803427),  INT32_C(  1704297507) },
      {  INT32_C(  1076157007),  INT32_C(   648716136), -INT32_C(   530396206),  INT32_C(  2001100859), -INT32_C(  1776552803),  INT32_C(   270724205), -INT32_C(   226163505), -INT32_C(   682091896),
         INT32_C(  1545043188), -INT32_C(   293354980), -INT32_C(   925964915), -INT32_C(   499182267),  INT32_C(  1987598857),  INT32_C(   377920071),  INT32_C(   654838686),  INT32_C(   436101157) },
      { -INT32_C(  1691456878),  INT32_C(   811041887), -INT32_C(  1018356053), -INT32_C(   373440169),  INT32_C(  1443965587), -INT32_C(   226163505),  INT32_C(   664010786), -INT32_C(   333521574),
         INT32_C(   991966142), -INT32_C(   925964915),  INT32_C(  1396647164), -INT32_C(   499182267),  INT32_C(  2118490658), -INT32_C(  1645314949),  INT32_C(  1704297507), -INT32_C(  1480334496) } },
    { { -INT32_C(   109701411),  INT32_C(  1709701592),  INT32_C(   590198494), -INT32_C(   737841717),  INT32_C(   239828423), -INT32_C(  1255878377),  INT32_C(    47984093),  INT32_C(  1780276109),
        -INT32_C(   916221199),  INT32_C(  1764641675), -INT32_C(   863216895), -INT32_C(  1868525112),  INT32_C(   631171854), -INT32_C(  1696939075),  INT32_C(  2107422704), -INT32_C(  2081900398) },
      UINT16_C(19274),
      {  INT32_C(  2056705356), -INT32_C(   891971778),  INT32_C(    73113187), -INT32_C(   856725202),  INT32_C(  1771023502), -INT32_C(   484409530), -INT32_C(   442780931), -INT32_C(  2127501771),
        -INT32_C(    84162629), -INT32_C(  1027288994), -INT32_C(  1664737170),  INT32_C(   409580937), -INT32_C(  1467877278),  INT32_C(  1972085112), -INT32_C(  2007357613), -INT32_C(   938898931) },
      { -INT32_C(  1329462191),  INT32_C(  1131579348),  INT32_C(   819935399),  INT32_C(  1330137325), -INT32_C(  1174877887), -INT32_C(  1121025174), -INT32_C(  1220179798),  INT32_C(  1686130194),
         INT32_C(   655639122),  INT32_C(  1886029513), -INT32_C(  1415493186), -INT32_C(   738465390),  INT32_C(   495776691),  INT32_C(   568048246),  INT32_C(  1423450178), -INT32_C(  1044883345) },
      { -INT32_C(   109701411),  INT32_C(   819935399),  INT32_C(   590198494),  INT32_C(  1330137325),  INT32_C(   239828423), -INT32_C(  1255878377), -INT32_C(  2127501771),  INT32_C(  1780276109),
        -INT32_C(  1664737170), -INT32_C(  1415493186), -INT32_C(   863216895), -INT32_C(   738465390),  INT32_C(   631171854), -INT32_C(  1696939075), -INT32_C(   938898931), -INT32_C(  2081900398) } },
    { {  INT32_C(  1692978331),  INT32_C(   282415698),  INT32_C(   784103068),  INT32_C(   302102367),  INT32_C(   540052906), -INT32_C(  1992225977), -INT32_C(  1696785877),  INT32_C(   224171634),
        -INT32_C(  1250802590),  INT32_C(   868566935),  INT32_C(   476152253), -INT32_C(   500211144),  INT32_C(   906190831), -INT32_C(  1782627222), -INT32_C(   785343394), -INT32_C(  1780577230) },
      UINT16_C(20688),
      {  INT32_C(   261580618), -INT32_C(    74361702), -INT32_C(  1604466319), -INT32_C(  1342223188),  INT32_C(  1106471298),  INT32_C(   786322174),  INT32_C(    28971043), -INT32_C(   279802971),
        -INT32_C(  1912608270), -INT32_C(  1350004674),  INT32_C(    89122393), -INT32_C(  1246474702), -INT32_C(  1242126153),  INT32_C(   501535994), -INT32_C(  1977704731),  INT32_C(   477786153) },
      { -INT32_C(  1733723814),  INT32_C(  1648832777),  INT32_C(  1248368151), -INT32_C(  1677779740), -INT32_C(  1101990460), -INT32_C(  1344588598), -INT32_C(    63309101), -INT32_C(  1005014166),
         INT32_C(   895271212),  INT32_C(   177775603),  INT32_C(   492044345), -INT32_C(   508013796),  INT32_C(   329189705),  INT32_C(   281180989), -INT32_C(   552731787), -INT32_C(   609999441) },
      {  INT32_C(  1692978331),  INT32_C(   282415698),  INT32_C(   784103068),  INT32_C(   302102367),  INT32_C(    28971043), -INT32_C(  1992225977), -INT32_C(   279802971), -INT32_C(  1005014166),
        -INT32_C(  1250802590),  INT32_C(   868566935),  INT32_C(   476152253), -INT32_C(   500211144), -INT32_C(  1977704731), -INT32_C(  1782627222),  INT32_C(   477786153), -INT32_C(  1780577230) } },
    { { -INT32_C(   636419865), -INT32_C(   572216924), -INT32_C(   973391447), -INT32_C(   710495348), -INT32_C(    85440836),  INT32_C(   906668737),  INT32_C(  1427445670),  INT32_C(   607172925),
         INT32_C(  1593721274), -INT32_C(  1824791830), -INT32_C(  1470548453), -INT32_C(  1501691926),  INT32_C(   111175237), -INT32_C(  1237538032), -INT32_C(    16035134), -INT32_C(   987546613) },
      UINT16_C( 8573),
      {  INT32_C(  1594124323),  INT32_C(  1419059195),  INT32_C(  1163165639), -INT32_C(   961832666), -INT32_C(   596526176),  INT32_C(  2100180082),  INT32_C(  1471756851),  INT32_C(   595081215),
        -INT32_C(  1702724449),  INT32_C(  1676613532), -INT32_C(  1113046121),  INT32_C(  2088981468), -INT32_C(  2124810993),  INT32_C(  1560184617), -INT32_C(  1045186367), -INT32_C(  1897648913) },
      {  INT32_C(  1143498408),  INT32_C(   346560381),  INT32_C(   936464474), -INT32_C(  1280092764),  INT32_C(  1932790858),  INT32_C(  1439642260), -INT32_C(   652835862),  INT32_C(  1466432175),
        -INT32_C(   560164768),  INT32_C(    49431719),  INT32_C(   943309972),  INT32_C(  1676405785), -INT32_C(  1915346951),  INT32_C(  1021486418), -INT32_C(   686360280),  INT32_C(  1412398579) },
      {  INT32_C(  1163165639), -INT32_C(   572216924), -INT32_C(   961832666), -INT32_C(  1280092764),  INT32_C(  1471756851), -INT32_C(   652835862),  INT32_C(   595081215),  INT32_C(   607172925),
        -INT32_C(  1113046121), -INT32_C(  1824791830), -INT32_C(  1470548453), -INT32_C(  1501691926),  INT32_C(   111175237), -INT32_C(   686360280), -INT32_C(    16035134), -INT32_C(   987546613) } },
    { { -INT32_C(  1254962419), -INT32_C(  1548278769),  INT32_C(    31256808), -INT32_C(   714815524),  INT32_C(   962738919),  INT32_C(   141903328),  INT32_C(   836799294),  INT32_C(   377818889),
        -INT32_C(   372525094), -INT32_C(   997424420),  INT32_C(  1338402930),  INT32_C(   388246064),  INT32_C(  1162905445),  INT32_C(   172869068),  INT32_C(  1513827665),  INT32_C(   376488252) },
      UINT16_C(15480),
      { -INT32_C(  1933683457), -INT32_C(   537644775), -INT32_C(  1542904704), -INT32_C(  1960088005),  INT32_C(    22149043),  INT32_C(  1026466305),  INT32_C(  1828613116), -INT32_C(  2119666047),
        -INT32_C(   468883509),  INT32_C(   415433112),  INT32_C(  1639762982), -INT32_C(   286398405), -INT32_C(   504414497), -INT32_C(   602005792),  INT32_C(   172498057),  INT32_C(  1569452434) },
      { -INT32_C(   264136616), -INT32_C(  1073216358),  INT32_C(   203539665), -INT32_C(  1929769300),  INT32_C(   745400908), -INT32_C(  1861711096),  INT32_C(   966480295), -INT32_C(  1701370046),
         INT32_C(  1502271679), -INT32_C(  1374055715),  INT32_C(    62536534), -INT32_C(  1768967095), -INT32_C(  1497170786),  INT32_C(   775408519),  INT32_C(  1583862556), -INT32_C(  1174864134) },
      { -INT32_C(  1254962419), -INT32_C(  1548278769),  INT32_C(    31256808), -INT32_C(  1929769300),  INT32_C(  1828613116),  INT32_C(   966480295), -INT32_C(  2119666047),  INT32_C(   377818889),
        -INT32_C(   372525094), -INT32_C(   997424420), -INT32_C(   286398405), -INT32_C(  1768967095),  INT32_C(   172498057),  INT32_C(  1583862556),  INT32_C(  1513827665),  INT32_C(   376488252) } },
    { { -INT32_C(  1273789737),  INT32_C(  1784818708), -INT32_C(  1318249369),  INT32_C(  1866988752),  INT32_C(  2132085240), -INT32_C(   257077804),  INT32_C(   441324832), -INT32_C(   355252717),
        -INT32_C(   593566008),  INT32_C(  2051473427), -INT32_C(   315902948), -INT32_C(  1453559119),  INT32_C(  1344893308), -INT32_C(   566110530), -INT32_C(      487445), -INT32_C(  1628844842) },
      UINT16_C(34994),
      { -INT32_C(  1031223941),  INT32_C(  1802937664), -INT32_C(   287430766), -INT32_C(    94414127), -INT32_C(   338682198), -INT32_C(   176440068), -INT32_C(  1530834501),  INT32_C(  1781298159),
         INT32_C(  2032973113), -INT32_C(   320560294), -INT32_C(  1680162102), -INT32_C(   946521828),  INT32_C(  1420977751), -INT32_C(   582406878),  INT32_C(  1853950590), -INT32_C(  1227313539) },
      { -INT32_C(  1120991901),  INT32_C(  1923683496), -INT32_C(   217152554),  INT32_C(   347775932),  INT32_C(   728263689),  INT32_C(   403222938),  INT32_C(   948341435), -INT32_C(  1678811336),
         INT32_C(   207101540),  INT32_C(   159252786),  INT32_C(  1090292868),  INT32_C(   961852976), -INT32_C(  1134183390),  INT32_C(   685075821),  INT32_C(   794909687),  INT32_C(   516575418) },
      { -INT32_C(  1273789737), -INT32_C(   217152554), -INT32_C(  1318249369),  INT32_C(  1866988752), -INT32_C(  1530834501),  INT32_C(   948341435),  INT32_C(   441324832), -INT32_C(  1678811336),
        -INT32_C(   593566008),  INT32_C(  2051473427), -INT32_C(   315902948),  INT32_C(   961852976),  INT32_C(  1344893308), -INT32_C(   566110530), -INT32_C(      487445),  INT32_C(   516575418) } },
    { { -INT32_C(  1591074194), -INT32_C(  1481987805),  INT32_C(  1709745717),  INT32_C(  2124364892),  INT32_C(  1715143929),  INT32_C(  1770983537),  INT32_C(   647557227), -INT32_C(  1371249856),
        -INT32_C(  1454411899),  INT32_C(  1297152280), -INT32_C(    72140641),  INT32_C(  1853510261), -INT32_C(   942361258),  INT32_C(   808477637), -INT32_C(  1823028909), -INT32_C(  1321034964) },
      UINT16_C(37130),
      { -INT32_C(  1416945062),  INT32_C(   585312879), -INT32_C(  1602987994), -INT32_C(  1688876346), -INT32_C(  1023534446), -INT32_C(  1584704950),  INT32_C(   658290661), -INT32_C(  1011267991),
        -INT32_C(   680639384), -INT32_C(  1795534226),  INT32_C(  1899261610), -INT32_C(   888370887), -INT32_C(   292746589),  INT32_C(  1116674396),  INT32_C(   963234768),  INT32_C(  2046632465) },
      { -INT32_C(   716149914),  INT32_C(  1751730877), -INT32_C(   220619079), -INT32_C(   876747481),  INT32_C(  1287211759),  INT32_C(   881739875),  INT32_C(   611186451), -INT32_C(  2137167334),
        -INT32_C(  1823085098), -INT32_C(   235159752), -INT32_C(  2065443747), -INT32_C(  1454399303),  INT32_C(  1324681450),  INT32_C(  1669497680), -INT32_C(  1803030662),  INT32_C(   806691930) },
      { -INT32_C(  1591074194), -INT32_C(   220619079),  INT32_C(  1709745717), -INT32_C(   876747481),  INT32_C(  1715143929),  INT32_C(  1770983537),  INT32_C(   647557227), -INT32_C(  1371249856),
         INT32_C(  1899261610),  INT32_C(  1297152280), -INT32_C(    72140641),  INT32_C(  1853510261),  INT32_C(   963234768),  INT32_C(   808477637), -INT32_C(  1823028909),  INT32_C(   806691930) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i src = simde_mm512_loadu_epi32(test_vec[i].src);
    simde__m512i a = simde_mm512_loadu_epi32(test_vec[i].a);
    simde__m512i b = simde_mm512_loadu_epi32(test_vec[i].b);
    simde__m512i r = simde_mm512_mask_unpackhi_epi32(src, test_vec[i].k, a, b);
    simde_test_x86_assert_equal_i32x16(r, simde_mm512_loadu_epi32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_mm512_maskz_unpackhi_epi32 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const simde__mmask16 k;
    const int32_t a[16];
    const int32_t b[16];
    const int32_t r[16];
  } test_vec[] = {
    { UINT16_C(51483),
      {  INT32_C(  1016400561),  INT32_C(   499657637),  INT32_C(   914546290),  INT32_C(   167035570),  INT32_C(  2082096633),  INT32_C(  1908618834), -INT32_C(  2117789817),  INT32_C(  2001461702),
        -INT32_C(  1850482453),  INT32_C(  2108586763),  INT32_C(   196292697), -INT32_C(   350902286),  INT32_C(  1063727085), -INT32_C(   307221915),  INT32_C(   141456962),  INT32_C(  1115732311) },
      { -INT32_C(  1529662567),  INT32_C(   136413615), -INT32_C(  1542138446),  INT32_C(  1771055484), -INT32_C(  1112934568),  INT32_C(  1688885538),  INT32_C(   644618703),  INT32_C(  1818881234),
        -INT32_C(   821019616),  INT32_C(  1893151422), -INT32_C(  2095781113),  INT32_C(  1827513364), -INT32_C(  1104505188), -INT32_C(  1088236305), -INT32_C(  1058697491), -INT32_C(  1691595141) },
      {  INT32_C(   914546290), -INT32_C(  1542138446),  INT32_C(           0),  INT32_C(  1771055484), -INT32_C(  2117789817),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
         INT32_C(   196292697),  INT32_C(           0),  INT32_C(           0),  INT32_C(  1827513364),  INT32_C(           0),  INT32_C(           0),  INT32_C(  1115732311), -INT32_C(  1691595141) } },
    { UINT16_C(15499),
      {  INT32_C(  1097746794), -INT32_C(   852658759), -INT32_C(   428719623), -INT32_C(   662958418), -INT32_C(   290690100),  INT32_C(   276601386), -INT32_C(  2040596646), -INT32_C(    54335086),
        -INT32_C(   348245710), -INT32_C(  1615238234),  INT32_C(  1518676908),  INT32_C(    87163193), -INT32_C(  1745625235), -INT32_C(   744001671), -INT32_C(   111606169),  INT32_C(   586554351) },
      { -INT32_C(   217238452),  INT32_C(  1267910303),  INT32_C(   715528433), -INT32_C(  2043684839),  INT32_C(   807281335), -INT32_C(   117193326), -INT32_C(  1141744437), -INT32_C(   992089992),
        -INT32_C(  1145574884), -INT32_C(  1576580431),  INT32_C(  2077076834),  INT32_C(  1023605893), -INT32_C(  1318248417), -INT32_C(  1314229787),  INT32_C(  1164745933), -INT32_C(  1593161339) },
      { -INT32_C(   428719623),  INT32_C(   715528433),  INT32_C(           0), -INT32_C(  2043684839),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(   992089992),
         INT32_C(           0),  INT32_C(           0),  INT32_C(    87163193),  INT32_C(  1023605893), -INT32_C(   111606169),  INT32_C(  1164745933),  INT32_C(           0),  INT32_C(           0) } },
    { UINT16_C(49459),
      {  INT32_C(  1678500957),  INT32_C(  1410428295), -INT32_C(   347040023),  INT32_C(  1091268563), -INT32_C(   894242784),  INT32_C(   224886689), -INT32_C(   816386875), -INT32_C(   359626099),
        -INT32_C(   179397522), -INT32_C(   230072567), -INT32_C(   908223754),  INT32_C(   705357833),  INT32_C(  2062859481),  INT32_C(    25713468), -INT32_C(   707731897), -INT32_C(   675323800) },
      {  INT32_C(   114036476),  INT32_C(  1677203053), -INT32_C(  1188178256), -INT32_C(  1746716738),  INT32_C(   806541556),  INT32_C(  2066848307), -INT32_C(   514850440),  INT32_C(  1589120865),
        -INT32_C(  1956346851),  INT32_C(  1257135258), -INT32_C(   251389134),  INT32_C(  1200154451), -INT32_C(   210265409), -INT32_C(  1385256908),  INT32_C(   177127081), -INT32_C(   345487667) },
      { -INT32_C(   347040023), -INT32_C(  1188178256),  INT32_C(           0),  INT32_C(           0), -INT32_C(   816386875), -INT32_C(   514850440),  INT32_C(           0),  INT32_C(           0),
        -INT32_C(   908223754),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(   675323800), -INT32_C(   345487667) } },
    { UINT16_C(52426),
      {  INT32_C(  1680434550), -INT32_C(  1283433553), -INT32_C(   711208116), -INT32_C(  1854973414), -INT32_C(  1153850291), -INT32_C(   545660335),  INT32_C(  1428506604), -INT32_C(  1474171086),
         INT32_C(    67914324), -INT32_C(   222851930),  INT32_C(  2043105887), -INT32_C(    99993683),  INT32_C(   750142427),  INT32_C(   302722853), -INT32_C(  1469632394),  INT32_C(  1951434783) },
      {  INT32_C(  2037931475),  INT32_C(  1231761385),  INT32_C(   801256322),  INT32_C(  1160367466),  INT32_C(   913432336), -INT32_C(  2058847217), -INT32_C(   886132820),  INT32_C(   171933239),
        -INT32_C(   981223461),  INT32_C(  1762586599), -INT32_C(  1936142302), -INT32_C(  1361985123), -INT32_C(  1327218015),  INT32_C(  1781869758),  INT32_C(   305488859), -INT32_C(  1122142750) },
      {  INT32_C(           0),  INT32_C(   801256322),  INT32_C(           0),  INT32_C(  1160367466),  INT32_C(           0),  INT32_C(           0), -INT32_C(  1474171086),  INT32_C(   171933239),
         INT32_C(           0),  INT32_C(           0), -INT32_C(    99993683), -INT32_C(  1361985123),  INT32_C(           0),  INT32_C(           0),  INT32_C(  1951434783), -INT32_C(  1122142750) } },
    { UINT16_C(41004),
      { -INT32_C(  1869671550),  INT32_C(   341946748),  INT32_C(   248970813), -INT32_C(  1873774676),  INT32_C(  1555828263), -INT32_C(  1363110024), -INT32_C(   953965910), -INT32_C(   496545953),
        -INT32_C(   546113693), -INT32_C(   420162648),  INT32_C(  2129971922),  INT32_C(  1745831233), -INT32_C(   859518125),  INT32_C(   226133091), -INT32_C(  2032886490),  INT32_C(  1332231148) },
      { -INT32_C(   617620942), -INT32_C(  2134826066),  INT32_C(   788444653),  INT32_C(  1318456826),  INT32_C(  1008360153),  INT32_C(    88708319),  INT32_C(   495656241), -INT32_C(  1955728552),
         INT32_C(  2087099598), -INT32_C(  1392760897), -INT32_C(   673514788), -INT32_C(   517640184), -INT32_C(  1457700918),  INT32_C(    78603987), -INT32_C(   618579325), -INT32_C(    60387794) },
      {  INT32_C(           0),  INT32_C(           0), -INT32_C(  1873774676),  INT32_C(  1318456826),  INT32_C(           0),  INT32_C(   495656241),  INT32_C(           0),  INT32_C(           0),
         INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(   618579325),  INT32_C(           0), -INT32_C(    60387794) } },
    { UINT16_C(52266),
      {  INT32_C(  1962142072),  INT32_C(  1869533333), -INT32_C(   857770329),  INT32_C(  1946921559),  INT32_C(    47898195),  INT32_C(    54353378), -INT32_C(  1617794247), -INT32_C(   546522009),
         INT32_C(   995319718), -INT32_C(   693386961), -INT32_C(  1885173192), -INT32_C(  2012959436),  INT32_C(  1837817483),  INT32_C(  1970390844), -INT32_C(  1726741710),  INT32_C(  1702396095) },
      {  INT32_C(   262261728), -INT32_C(   974762867),  INT32_C(   190089430), -INT32_C(  1047308234),  INT32_C(  1932467511),  INT32_C(   401121509),  INT32_C(  1655831715),  INT32_C(  1573398909),
        -INT32_C(  2106824203), -INT32_C(  1958260043),  INT32_C(   295082971),  INT32_C(   735193588),  INT32_C(   748552519),  INT32_C(  1145276065), -INT32_C(     5770110),  INT32_C(   324824862) },
      {  INT32_C(           0),  INT32_C(   190089430),  INT32_C(           0), -INT32_C(  1047308234),  INT32_C(           0),  INT32_C(  1655831715),  INT32_C(           0),  INT32_C(           0),
         INT32_C(           0),  INT32_C(           0), -INT32_C(  2012959436),  INT32_C(   735193588),  INT32_C(           0),  INT32_C(           0),  INT32_C(  1702396095),  INT32_C(   324824862) } },
    { UINT16_C(51672),
      { -INT32_C(   602174059), -INT32_C(  1351092712), -INT32_C(   623351033),  INT32_C(   886775702), -INT32_C(  1883603637),  INT32_C(  1753431489), -INT32_C(  1713921732),  INT32_C(  1231204276),
         INT32_C(  1428520252),  INT32_C(  2063900020), -INT32_C(  1621763064),  INT32_C(  1205023228),  INT32_C(  1876332206),  INT32_C(   131619531), -INT32_C(  1331646469), -INT32_C(  1678179745) },
      { -INT32_C(   185589888), -INT32_C(   999295812), -INT32_C(   849099311), -INT32_C(  1542178826), -INT32_C(  1877742651),  INT32_C(  1083697989), -INT32_C(    84920165), -INT32_C(  1164580294),
        -INT32_C(   978418167),  INT32_C(  1267277434), -INT32_C(   652677661), -INT32_C(   377672412),  INT32_C(  1568247832),  INT32_C(   396169340), -INT32_C(  2096001464), -INT32_C(  2126666120) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(  1542178826), -INT32_C(  1713921732),  INT32_C(           0),  INT32_C(  1231204276), -INT32_C(  1164580294),
        -INT32_C(  1621763064),  INT32_C(           0),  INT32_C(           0), -INT32_C(   377672412),  INT32_C(           0),  INT32_C(           0), -INT32_C(  1678179745), -INT32_C(  2126666120) } },
    { UINT16_C(60460),
      { -INT32_C(   821385402),  INT32_C(   196931058),  INT32_C(  1127801030),  INT32_C(  1121145033),  INT32_C(  1246973869),  INT32_C(  2010684262),  INT32_C(  1545490462),  INT32_C(   390613713),
        -INT32_C(   454601999),  INT32_C(    99590975),  INT32_C(  1296574340),  INT32_C(   613423991), -INT32_C(   781261973), -INT32_C(  1656141954),  INT32_C(  1777952663), -INT32_C(  1551875663) },
      { -INT32_C(   762878061), -INT32_C(  1881704949),  INT32_C(   349970333), -INT32_C(  1523028934), -INT32_C(   831019441), -INT32_C(  2056535827), -INT32_C(   655465433),  INT32_C(   947613349),
        -INT32_C(   519437610),  INT32_C(   359719288),  INT32_C(   975784960),  INT32_C(   148922809), -INT32_C(   170502392),  INT32_C(  1048199447),  INT32_C(  1242982565), -INT32_C(  1383951657) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(  1121145033), -INT32_C(  1523028934),  INT32_C(           0), -INT32_C(   655465433),  INT32_C(           0),  INT32_C(           0),
         INT32_C(           0),  INT32_C(           0),  INT32_C(   613423991),  INT32_C(   148922809),  INT32_C(           0),  INT32_C(  1242982565), -INT32_C(  1551875663), -INT32_C(  1383951657) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i a = simde_mm512_loadu_epi32(test_vec[i].a);
    simde__m512i b = simde_mm512_loadu_epi32(test_vec[i].b);
    simde__m512i r = simde_mm512_maskz_unpackhi_epi32(test_vec[i].k, a, b);
    simde_test_x86_assert_equal_i32x16(r, simde_mm512_loadu_epi32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_mm256_mask_unpackhi_epi32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int32_t src[8];
    const simde__mmask8 k;
    const int32_t a[8];
    const int32_t b[8];
    const int32_t r[8];
  } test_vec[] = {
    { {  INT32_C(  1057846302), -INT32_C(   458303865), -INT32_C(  1780677330),  INT32_C(  1466357485),  INT32_C(  1894013962),  INT32_C(   934153169), -INT32_C(  1633917278), -INT32_C(  1972433044) },
      UINT8_C(132),
      {  INT32_C(  1393281661),  INT32_C(  2122444664), -INT32_C(  1553262644), -INT32_C(   642923907), -INT32_C(  1297474138),  INT32_C(   844423628), -INT32_C(  1918897539), -INT32_C(   569300639) },
      {  INT32_C(  1815158003), -INT32_C(   655707381),  INT32_C(  1199265226), -INT32_C(  1105188840),  INT32_C(   292604485),  INT32_C(   692372652),  INT32_C(   414639030),  INT32_C(    16172812) },
      {  INT32_C(  1057846302), -INT32_C(   458303865), -INT32_C(   642923907),  INT32_C(  1466357485),  INT32_C(  1894013962),  INT32_C(   934153169), -INT32_C(  1633917278),  INT32_C(    16172812) } },
    { { -INT32_C(   278124317), -INT32_C(  1513662757), -INT32_C(  1007926613), -INT32_C(  1350431638), -INT32_C(  2101218602),  INT32_C(  1839990199), -INT32_C(   192584984),  INT32_C(   234126378) },
      UINT8_C(164),
      { -INT32_C(  1233126304),  INT32_C(    90318019),  INT32_C(   477046032), -INT32_C(  1695408217), -INT32_C(   447646240), -INT32_C(  2083668447), -INT32_C(  1062354620),  INT32_C(   375700406) },
      {  INT32_C(  2077090743),  INT32_C(   394276615), -INT32_C(    63705004), -INT32_C(   275372785), -INT32_C(  1143674982), -INT32_C(   381705819),  INT32_C(   413789282),  INT32_C(  1596919207) },
      { -INT32_C(   278124317), -INT32_C(  1513662757), -INT32_C(  1695408217), -INT32_C(  1350431638), -INT32_C(  2101218602),  INT32_C(   413789282), -INT32_C(   192584984),  INT32_C(  1596919207) } },
    { { -INT32_C(   136643344),  INT32_C(  2131647019),  INT32_C(  1501249866),  INT32_C(    21500263), -INT32_C(  1631773448),  INT32_C(   545782973), -INT32_C(  1875365400),  INT32_C(   804218686) },
      UINT8_C( 99),
      {  INT32_C(   596518601),  INT32_C(  1986924085), -INT32_C(  1679964279),  INT32_C(   747888400), -INT32_C(  1729482340), -INT32_C(   360707399), -INT32_C(  1440214974), -INT32_C(   938649601) },
      { -INT32_C(  1276339074),  INT32_C(   858348202),  INT32_C(   835585825), -INT32_C(  2107743514),  INT32_C(  1276790931), -INT32_C(  1808360878), -INT32_C(  1438752853),  INT32_C(   879971510) },
      { -INT32_C(  1679964279),  INT32_C(   835585825),  INT32_C(  1501249866),  INT32_C(    21500263), -INT32_C(  1631773448), -INT32_C(  1438752853), -INT32_C(   938649601),  INT32_C(   804218686) } },
    { { -INT32_C(  1830330392), -INT32_C(   624619079), -INT32_C(    32730088), -INT32_C(  1988072714),  INT32_C(    81173170), -INT32_C(   543683532),  INT32_C(   579524459),  INT32_C(   190250275) },
      UINT8_C( 92),
      {  INT32_C(  1326816574), -INT32_C(   160960670),  INT32_C(  1709991419),  INT32_C(  2132244197),  INT32_C(  1488132940), -INT32_C(  1950051404),  INT32_C(   447669789),  INT32_C(  2054601020) },
      { -INT32_C(  1194751146),  INT32_C(  1991192698),  INT32_C(  2061212565),  INT32_C(  1576661777), -INT32_C(  1028215538),  INT32_C(  1565358656), -INT32_C(  1669858464),  INT32_C(   169340340) },
      { -INT32_C(  1830330392), -INT32_C(   624619079),  INT32_C(  2132244197),  INT32_C(  1576661777),  INT32_C(   447669789), -INT32_C(   543683532),  INT32_C(  2054601020),  INT32_C(   190250275) } },
    { { -INT32_C(   222044040), -INT32_C(  1503104495),  INT32_C(   522273805),  INT32_C(  1165761079),  INT32_C(   117977799),  INT32_C(   207902124),  INT32_C(    95017809),  INT32_C(  1074839752) },
      UINT8_C(160),
      {  INT32_C(  1169241043), -INT32_C(   548251493), -INT32_C(  1827245703),  INT32_C(   542858478), -INT32_C(  1177722268), -INT32_C(  1576347193),  INT32_C(  1114312834), -INT32_C(   203183328) },
      {  INT32_C(  2050528478),  INT32_C(  1700367084), -INT32_C(   352751364),  INT32_C(   805983436),  INT32_C(  2112477110),  INT32_C(   857797809),  INT32_C(   611748612),  INT32_C(   353851702) },
      { -INT32_C(   222044040), -INT32_C(  1503104495),  INT32_C(   522273805),  INT32_C(  1165761079),  INT32_C(   117977799),  INT32_C(   611748612),  INT32_C(    95017809),  INT32_C(   353851702) } },
    { { -INT32_C(   628142099), -INT32_C(   717231911),  INT32_C(   616511576),  INT32_C(  1129630348),  INT32_C(  1388330657),  INT32_C(   914808882), -INT32_C(  1571095445),  INT32_C(  1119318357) },
      UINT8_C(192),
      {  INT32_C(   781786182), -INT32_C(  1803063460), -INT32_C(   132011218),  INT32_C(  1050305536),  INT32_C(    91286564),  INT32_C(  1852876402),  INT32_C(  1908609536),  INT32_C(   254871241) },
      {  INT32_C(  2118044194),  INT32_C(  1746126137),  INT32_C(  1885353072), -INT32_C(  1129383272),  INT32_C(  1505828583), -INT32_C(   993512764),  INT32_C(   238390084), -INT32_C(  1273141615) },
      { -INT32_C(   628142099), -INT32_C(   717231911),  INT32_C(   616511576),  INT32_C(  1129630348),  INT32_C(  1388330657),  INT32_C(   914808882),  INT32_C(   254871241), -INT32_C(  1273141615) } },
    { {  INT32_C(  1781685041), -INT32_C(  1848490720),  INT32_C(   285291385),  INT32_C(   349089837), -INT32_C(  1821470770),  INT32_C(   106378945),  INT32_C(  1393855937),  INT32_C(   604451315) },
      UINT8_C(141),
      {  INT32_C(  2142080825), -INT32_C(  1795670431), -INT32_C(   255718848),  INT32_C(  1740560088),  INT32_C(  2049528132),  INT32_C(   909914025),  INT32_C(  1948880707), -INT32_C(   821997930) },
      {  INT32_C(  1045344221),  INT32_C(   768821229),  INT32_C(   689804625), -INT32_C(  1332683669), -INT32_C(   701843155),  INT32_C(   722233064), -INT32_C(  1952434443),  INT32_C(  1633395076) },
      { -INT32_C(   255718848), -INT32_C(  1848490720),  INT32_C(  1740560088), -INT32_C(  1332683669), -INT32_C(  1821470770),  INT32_C(   106378945),  INT32_C(  1393855937),  INT32_C(  1633395076) } },
    { {  INT32_C(  1050650960),  INT32_C(  1097560816),  INT32_C(  1936361735), -INT32_C(  1843135643), -INT32_C(  1654043212), -INT32_C(  1446480460),  INT32_C(   792029355),  INT32_C(  1519423498) },
      UINT8_C( 57),
      { -INT32_C(  1574266832), -INT32_C(  1918211324), -INT32_C(   772661802), -INT32_C(  1920629696),  INT32_C(  1665213165),  INT32_C(  1393486827), -INT32_C(  1336066528), -INT32_C(    18237234) },
      {  INT32_C(  1419842384),  INT32_C(  1440828287), -INT32_C(  1473850520),  INT32_C(  1161145176), -INT32_C(  1180141618), -INT32_C(  2113095838), -INT32_C(  1020105995),  INT32_C(  1925323554) },
      { -INT32_C(   772661802),  INT32_C(  1097560816),  INT32_C(  1936361735),  INT32_C(  1161145176), -INT32_C(  1336066528), -INT32_C(  1020105995),  INT32_C(   792029355),  INT32_C(  1519423498) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256i src = simde_x_mm256_loadu_epi32(test_vec[i].src);
    simde__mmask8 k = test_vec[i].k;
    simde__m256i a = simde_x_mm256_loadu_epi32(test_vec[i].a);
    simde__m256i b = simde_x_mm256_loadu_epi32(test_vec[i].b);
    simde__m256i r = simde_mm256_mask_unpackhi_epi32(src, k, a, b);
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
    simde__m256i r = simde_mm256_mask_unpackhi_epi32(src, k, a, b);

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
test_simde_mm256_maskz_unpackhi_epi32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k;
    const int32_t a[8];
    const int32_t b[8];
    const int32_t r[8];
  } test_vec[] = {
    { UINT8_C(234),
      { -INT32_C(  1536475350),  INT32_C(   248691133),  INT32_C(  2011030200),  INT32_C(   806987582),  INT32_C(   163466220), -INT32_C(   721015445),  INT32_C(   907267441), -INT32_C(  1876920986) },
      {  INT32_C(  1916046260), -INT32_C(    41941436),  INT32_C(   661937640), -INT32_C(   262697724),  INT32_C(  1140397528), -INT32_C(  1273495486),  INT32_C(   870984909),  INT32_C(  1438911137) },
      {  INT32_C(           0),  INT32_C(   661937640),  INT32_C(           0), -INT32_C(   262697724),  INT32_C(           0),  INT32_C(   870984909), -INT32_C(  1876920986),  INT32_C(  1438911137) } },
    { UINT8_C(150),
      { -INT32_C(     2439176), -INT32_C(  1528309945), -INT32_C(   660074933),  INT32_C(  2075170917), -INT32_C(  1833045102),  INT32_C(   945778956),  INT32_C(  1725534811),  INT32_C(  1341926998) },
      {  INT32_C(  1028577014), -INT32_C(   102615634), -INT32_C(  1445819836), -INT32_C(  1255898589), -INT32_C(  2109218186), -INT32_C(  1346722221), -INT32_C(  1894411464), -INT32_C(  1210183231) },
      {  INT32_C(           0), -INT32_C(  1445819836),  INT32_C(  2075170917),  INT32_C(           0),  INT32_C(  1725534811),  INT32_C(           0),  INT32_C(           0), -INT32_C(  1210183231) } },
    { UINT8_C(231),
      {  INT32_C(  1637217580),  INT32_C(  1638240215), -INT32_C(   477868191),  INT32_C(  1431910771),  INT32_C(   648665984),  INT32_C(   677337237),  INT32_C(  2129325677), -INT32_C(   127557172) },
      {  INT32_C(  1834613654), -INT32_C(   338690166), -INT32_C(  1043442866),  INT32_C(   219621517), -INT32_C(  1724596221), -INT32_C(  2050911464),  INT32_C(  1292086145), -INT32_C(   481990579) },
      { -INT32_C(   477868191), -INT32_C(  1043442866),  INT32_C(  1431910771),  INT32_C(           0),  INT32_C(           0),  INT32_C(  1292086145), -INT32_C(   127557172), -INT32_C(   481990579) } },
    { UINT8_C( 99),
      { -INT32_C(  1645391458),  INT32_C(  1944836128), -INT32_C(   822039129), -INT32_C(  2066608444), -INT32_C(   711169214), -INT32_C(   665444051), -INT32_C(  1943690460), -INT32_C(  2031089176) },
      {  INT32_C(  2049236314),  INT32_C(  1575817142), -INT32_C(  2144538948),  INT32_C(  1040514812), -INT32_C(  1760321430), -INT32_C(   445683263), -INT32_C(   193817332), -INT32_C(   126197090) },
      { -INT32_C(   822039129), -INT32_C(  2144538948),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(   193817332), -INT32_C(  2031089176),  INT32_C(           0) } },
    { UINT8_C( 63),
      { -INT32_C(  1359646050),  INT32_C(  1298813535),  INT32_C(  2101996414), -INT32_C(  1863874577),  INT32_C(    55672474), -INT32_C(  2112931859),  INT32_C(   186647465),  INT32_C(   474617982) },
      { -INT32_C(   355843958),  INT32_C(   288830866),  INT32_C(   260997408), -INT32_C(  1549830904), -INT32_C(   525929997), -INT32_C(   781994456),  INT32_C(   937198521),  INT32_C(   643049116) },
      {  INT32_C(  2101996414),  INT32_C(   260997408), -INT32_C(  1863874577), -INT32_C(  1549830904),  INT32_C(   186647465),  INT32_C(   937198521),  INT32_C(           0),  INT32_C(           0) } },
    { UINT8_C(102),
      {  INT32_C(  1408831518), -INT32_C(   915207608),  INT32_C(   231834520),  INT32_C(   318796834), -INT32_C(   784605157), -INT32_C(   947254205),  INT32_C(   258196200),  INT32_C(   880118038) },
      { -INT32_C(   494375270),  INT32_C(   279706488), -INT32_C(  1591903106),  INT32_C(   213130737),  INT32_C(  1105064190), -INT32_C(   452433924),  INT32_C(  1072982825), -INT32_C(  1888196107) },
      {  INT32_C(           0), -INT32_C(  1591903106),  INT32_C(   318796834),  INT32_C(           0),  INT32_C(           0),  INT32_C(  1072982825),  INT32_C(   880118038),  INT32_C(           0) } },
    { UINT8_C(216),
      { -INT32_C(   145722884), -INT32_C(  1737072356), -INT32_C(  1668737154), -INT32_C(  1147497013), -INT32_C(   625419406),  INT32_C(  1325637092), -INT32_C(    96189551), -INT32_C(  1278028873) },
      {  INT32_C(  1621762884),  INT32_C(    49881220),  INT32_C(    60719671), -INT32_C(  1967245288), -INT32_C(   127633900), -INT32_C(  1538824173),  INT32_C(  1654623403), -INT32_C(  1542098593) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(  1967245288), -INT32_C(    96189551),  INT32_C(           0), -INT32_C(  1278028873), -INT32_C(  1542098593) } },
    { UINT8_C(148),
      { -INT32_C(   535296833), -INT32_C(  2145969155), -INT32_C(   224912711),  INT32_C(  1325802201), -INT32_C(   278659449), -INT32_C(   778434747),  INT32_C(   405929126), -INT32_C(   793979631) },
      { -INT32_C(   676280871), -INT32_C(  1722300192), -INT32_C(  1148456990), -INT32_C(  1744072431), -INT32_C(   712544625),  INT32_C(   480649589),  INT32_C(   775214877), -INT32_C(  2030051156) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(  1325802201),  INT32_C(           0),  INT32_C(   405929126),  INT32_C(           0),  INT32_C(           0), -INT32_C(  2030051156) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__mmask8 k = test_vec[i].k;
    simde__m256i a = simde_x_mm256_loadu_epi32(test_vec[i].a);
    simde__m256i b = simde_x_mm256_loadu_epi32(test_vec[i].b);
    simde__m256i r = simde_mm256_maskz_unpackhi_epi32(k, a, b);
    simde_test_x86_assert_equal_i32x8(r, simde_x_mm256_loadu_epi32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m256i a = simde_test_x86_random_i32x8();
    simde__m256i b = simde_test_x86_random_i32x8();
    simde__m256i r = simde_mm256_maskz_unpackhi_epi32(k, a, b);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_mask_unpackhi_epi32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int32_t src[4];
    const simde__mmask8 k;
    const int32_t a[4];
    const int32_t b[4];
    const int32_t r[4];
  } test_vec[] = {
    { {  INT32_C(   165122029),  INT32_C(   134105046),  INT32_C(   476704106), -INT32_C(  1406132584) },
      UINT8_C(135),
      { -INT32_C(   146213671), -INT32_C(  2118263006), -INT32_C(  1783865743), -INT32_C(  1232948953) },
      { -INT32_C(   812872568),  INT32_C(  2017039242),  INT32_C(   437278460),  INT32_C(  1604435078) },
      { -INT32_C(  1783865743),  INT32_C(   437278460), -INT32_C(  1232948953), -INT32_C(  1406132584) } },
    { { -INT32_C(   749278799),  INT32_C(   978588872), -INT32_C(  1714487182),  INT32_C(   978277041) },
      UINT8_C(222),
      {  INT32_C(  1852312027), -INT32_C(  1721049021), -INT32_C(  1390443280),  INT32_C(   241073701) },
      { -INT32_C(   388550188), -INT32_C(  2057629307),  INT32_C(   842462432),  INT32_C(   521171012) },
      { -INT32_C(   749278799),  INT32_C(   842462432),  INT32_C(   241073701),  INT32_C(   521171012) } },
    { { -INT32_C(  1114736262),  INT32_C(  1247213657), -INT32_C(  1560840835), -INT32_C(   944679437) },
      UINT8_C(134),
      { -INT32_C(  1727287160), -INT32_C(     8810485),  INT32_C(   927182022),  INT32_C(   900817852) },
      { -INT32_C(   376475919),  INT32_C(   963041732),  INT32_C(   623643088),  INT32_C(  1118565306) },
      { -INT32_C(  1114736262),  INT32_C(   623643088),  INT32_C(   900817852), -INT32_C(   944679437) } },
    { { -INT32_C(  1361332573),  INT32_C(   212751430), -INT32_C(  1119620864),  INT32_C(  1173550164) },
      UINT8_C( 98),
      {  INT32_C(  1512451969), -INT32_C(  1641390187),  INT32_C(  2136493963), -INT32_C(  1339909382) },
      { -INT32_C(   889794187),  INT32_C(  1892287359),  INT32_C(  1002800966), -INT32_C(    73594246) },
      { -INT32_C(  1361332573),  INT32_C(  1002800966), -INT32_C(  1119620864),  INT32_C(  1173550164) } },
    { { -INT32_C(   816397255), -INT32_C(  1351778269), -INT32_C(   902904112), -INT32_C(   696561568) },
      UINT8_C( 33),
      {  INT32_C(  1956683889), -INT32_C(   222621334), -INT32_C(   529729834),  INT32_C(  1461348243) },
      {  INT32_C(  1048308157),  INT32_C(   470690390), -INT32_C(  1468147624), -INT32_C(   976596141) },
      { -INT32_C(   529729834), -INT32_C(  1351778269), -INT32_C(   902904112), -INT32_C(   696561568) } },
    { {  INT32_C(  1564044019),  INT32_C(  1364194427),  INT32_C(  2117254122), -INT32_C(   522892253) },
      UINT8_C( 53),
      {  INT32_C(  2055937616),  INT32_C(    97691692),  INT32_C(  2019064613), -INT32_C(  1351934651) },
      {  INT32_C(  1261160535), -INT32_C(   751404008), -INT32_C(    84495186), -INT32_C(   634398839) },
      {  INT32_C(  2019064613),  INT32_C(  1364194427), -INT32_C(  1351934651), -INT32_C(   522892253) } },
    { {  INT32_C(   575978485), -INT32_C(  2010699933), -INT32_C(   419397726), -INT32_C(   191468643) },
      UINT8_C( 51),
      {  INT32_C(  1045118913),  INT32_C(   703340405), -INT32_C(   323754219), -INT32_C(   773681898) },
      {  INT32_C(   137626849), -INT32_C(  1431651285),  INT32_C(   659001788), -INT32_C(   379897048) },
      { -INT32_C(   323754219),  INT32_C(   659001788), -INT32_C(   419397726), -INT32_C(   191468643) } },
    { { -INT32_C(   265836933), -INT32_C(   619047739),  INT32_C(   298307067),  INT32_C(  1004775770) },
      UINT8_C(173),
      { -INT32_C(   724024297), -INT32_C(  2138012690),  INT32_C(   111720650), -INT32_C(  1182691053) },
      { -INT32_C(   847285831),  INT32_C(  1489525387), -INT32_C(   877471455), -INT32_C(   730272068) },
      {  INT32_C(   111720650), -INT32_C(   619047739), -INT32_C(  1182691053), -INT32_C(   730272068) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i src = simde_x_mm_loadu_epi32(test_vec[i].src);
    simde__m128i a = simde_x_mm_loadu_epi32(test_vec[i].a);
    simde__m128i b = simde_x_mm_loadu_epi32(test_vec[i].b);
    simde__m128i r = simde_mm_mask_unpackhi_epi32(src, test_vec[i].k, a, b);
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
    simde__m128i r = simde_mm_mask_unpackhi_epi32(src, k, a, b);

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
test_simde_mm_maskz_unpackhi_epi32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k;
    const int32_t a[4];
    const int32_t b[4];
    const int32_t r[4];
  } test_vec[] = {
    { UINT8_C(108),
      { -INT32_C(  1342915750),  INT32_C(   689487629),  INT32_C(  1391828275), -INT32_C(  1550823693) },
      {  INT32_C(  1294550156), -INT32_C(   570082962), -INT32_C(   582483149),  INT32_C(   541720006) },
      {  INT32_C(           0),  INT32_C(           0), -INT32_C(  1550823693),  INT32_C(   541720006) } },
    { UINT8_C(184),
      { -INT32_C(    37368002), -INT32_C(  2060324888),  INT32_C(   846824420),  INT32_C(  1488919572) },
      {  INT32_C(  2126908485),  INT32_C(   347251729), -INT32_C(   354775059),  INT32_C(   396557017) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(   396557017) } },
    { UINT8_C(202),
      {  INT32_C(  1454511207), -INT32_C(   918866107), -INT32_C(   857903696),  INT32_C(   940717356) },
      { -INT32_C(  1605725956), -INT32_C(   762487230),  INT32_C(   866875193), -INT32_C(  2114076135) },
      {  INT32_C(           0),  INT32_C(   866875193),  INT32_C(           0), -INT32_C(  2114076135) } },
    { UINT8_C(214),
      { -INT32_C(   417540177), -INT32_C(  2137529070), -INT32_C(   139696958),  INT32_C(   116647286) },
      { -INT32_C(  1924557777), -INT32_C(  1715070175), -INT32_C(  2001536314), -INT32_C(  1486998537) },
      {  INT32_C(           0), -INT32_C(  2001536314),  INT32_C(   116647286),  INT32_C(           0) } },
    { UINT8_C( 11),
      {  INT32_C(  1595772538), -INT32_C(  1994285787),  INT32_C(   805247306), -INT32_C(  1604450804) },
      {  INT32_C(  1791159119), -INT32_C(  1406116942),  INT32_C(  1101248525), -INT32_C(  1857271274) },
      {  INT32_C(   805247306),  INT32_C(  1101248525),  INT32_C(           0), -INT32_C(  1857271274) } },
    { UINT8_C(216),
      {  INT32_C(   134148201),  INT32_C(   726763282), -INT32_C(  1925742457), -INT32_C(   908273442) },
      { -INT32_C(   176470374),  INT32_C(   771893110),  INT32_C(   356795339), -INT32_C(   101788273) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(   101788273) } },
    { UINT8_C(198),
      {  INT32_C(  1943535852), -INT32_C(   772144303),  INT32_C(   313493306), -INT32_C(  1448314781) },
      {  INT32_C(   455057908), -INT32_C(   404337244),  INT32_C(  1735916690), -INT32_C(   701665046) },
      {  INT32_C(           0),  INT32_C(  1735916690), -INT32_C(  1448314781),  INT32_C(           0) } },
    { UINT8_C(112),
      {  INT32_C(   146884869), -INT32_C(   884764092), -INT32_C(  1188080319), -INT32_C(  1548888062) },
      {  INT32_C(  1162332664), -INT32_C(  1411960913),  INT32_C(   378879910),  INT32_C(  1921411948) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_x_mm_loadu_epi32(test_vec[i].a);
    simde__m128i b = simde_x_mm_loadu_epi32(test_vec[i].b);
    simde__m128i r = simde_mm_maskz_unpackhi_epi32(test_vec[i].k, a, b);
    simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m128i a = simde_test_x86_random_i32x4();
    simde__m128i b = simde_test_x86_random_i32x4();
    simde__m128i r = simde_mm_maskz_unpackhi_epi32(k, a, b);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x4(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_unpackhi_epi64 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const int64_t a[8];
    const int64_t b[8];
    const int64_t r[8];
  } test_vec[] = {
    { {  INT64_C( 5674973837736279222),  INT64_C( 1704843706748687788), -INT64_C( 2673855454977685508),  INT64_C( 7390821164380328012),
        -INT64_C( 5519861701786044300), -INT64_C( 8880554723753151143), -INT64_C( 1373376201226907275),  INT64_C( 3598748551275955674) },
      { -INT64_C( 8104881503415520309),  INT64_C( 3417945947432930147), -INT64_C(  605674648809090292),  INT64_C( 8604534647075985787),
        -INT64_C( 4401197301858979547),  INT64_C( 3207437185291396506),  INT64_C( 8899798961286072686), -INT64_C( 7139017439677512502) },
      {  INT64_C( 1704843706748687788),  INT64_C( 3417945947432930147),  INT64_C( 7390821164380328012),  INT64_C( 8604534647075985787),
        -INT64_C( 8880554723753151143),  INT64_C( 3207437185291396506),  INT64_C( 3598748551275955674), -INT64_C( 7139017439677512502) } },
    { { -INT64_C( 6993840614198987057),  INT64_C( 2762244475499748360),  INT64_C( 7546683454867451199),  INT64_C( 6578294010817703736),
         INT64_C( 3360944426133832193),  INT64_C( 5544964737207866902),  INT64_C( 1287825918278739417), -INT64_C( 8530650538818159179) },
      { -INT64_C( 5286887723346483380),  INT64_C( 9016900953806534857), -INT64_C( 6267087682875839204),  INT64_C( 2063926056140392082),
         INT64_C( 3388730460615947184),  INT64_C( 2254375981441977128), -INT64_C( 6525123138314551595), -INT64_C( 7508235156986044703) },
      {  INT64_C( 2762244475499748360),  INT64_C( 9016900953806534857),  INT64_C( 6578294010817703736),  INT64_C( 2063926056140392082),
         INT64_C( 5544964737207866902),  INT64_C( 2254375981441977128), -INT64_C( 8530650538818159179), -INT64_C( 7508235156986044703) } },
    { { -INT64_C( 5463729958601401194),  INT64_C( 3358500432824512889), -INT64_C( 6070735980921901304),  INT64_C( 8810495403391484103),
        -INT64_C( 7653970804518539898),  INT64_C( 1899300861932292308), -INT64_C( 8948099700948053413), -INT64_C( 2390154280872890762) },
      { -INT64_C( 4515780095567115612),  INT64_C( 7867024461783786753), -INT64_C( 3397574104711994469),  INT64_C( 2795044881987931026),
         INT64_C( 8428269494163847753), -INT64_C( 3954524210633120353), -INT64_C( 6321935581393735400), -INT64_C( 5355805335178023676) },
      {  INT64_C( 3358500432824512889),  INT64_C( 7867024461783786753),  INT64_C( 8810495403391484103),  INT64_C( 2795044881987931026),
         INT64_C( 1899300861932292308), -INT64_C( 3954524210633120353), -INT64_C( 2390154280872890762), -INT64_C( 5355805335178023676) } },
    { {  INT64_C( 7781906569962950934),  INT64_C( 6034324575617844679), -INT64_C( 2690891062124880405), -INT64_C( 6010321335520052362),
         INT64_C( 3158206844560114334),  INT64_C( 1533438474208735417), -INT64_C( 8400130205098308421),  INT64_C( 8591747521593593337) },
      {  INT64_C( 6923639730661847686), -INT64_C( 3537969947851082330), -INT64_C( 5456166221627982681),  INT64_C( 4533858979574756506),
         INT64_C( 2880401063509806323), -INT64_C( 8046561543942812302),  INT64_C( 1965984521606968538),  INT64_C(   17867119812119624) },
      {  INT64_C( 6034324575617844679), -INT64_C( 3537969947851082330), -INT64_C( 6010321335520052362),  INT64_C( 4533858979574756506),
         INT64_C( 1533438474208735417), -INT64_C( 8046561543942812302),  INT64_C( 8591747521593593337),  INT64_C(   17867119812119624) } },
    { {  INT64_C( 1796817116571723846), -INT64_C( 6964269516958341152), -INT64_C( 9060261440426629722), -INT64_C( 7920210737626885624),
         INT64_C( 2515339843687001898),  INT64_C( 2131122330677249327),  INT64_C( 5450911646426122218),  INT64_C( 1528821352979572825) },
      {  INT64_C(  687588226762117413), -INT64_C( 6564117700413655725),  INT64_C(  929550991278680920), -INT64_C( 2047191976181086315),
        -INT64_C( 7179347720035140742),  INT64_C( 4875232268415031882),  INT64_C( 8230545872734023800),  INT64_C( 5669620523642120716) },
      { -INT64_C( 6964269516958341152), -INT64_C( 6564117700413655725), -INT64_C( 7920210737626885624), -INT64_C( 2047191976181086315),
         INT64_C( 2131122330677249327),  INT64_C( 4875232268415031882),  INT64_C( 1528821352979572825),  INT64_C( 5669620523642120716) } },
    { {  INT64_C( 1795247188014725380),  INT64_C( 1551707346594254681),  INT64_C( 4072793568706586421),  INT64_C(  397637285874727010),
         INT64_C( 9119855377055426218), -INT64_C( 6323814244269445748),  INT64_C( 6419671222899670707),  INT64_C( 8484240513725045432) },
      { -INT64_C( 2676125203499773639), -INT64_C( 6969530513325121493), -INT64_C(  428522275801791810), -INT64_C( 1661421789014418256),
        -INT64_C( 8598740181978784125), -INT64_C( 6102819577427219005),  INT64_C( 1273231586017463407),  INT64_C( 6026518686306491914) },
      {  INT64_C( 1551707346594254681), -INT64_C( 6969530513325121493),  INT64_C(  397637285874727010), -INT64_C( 1661421789014418256),
        -INT64_C( 6323814244269445748), -INT64_C( 6102819577427219005),  INT64_C( 8484240513725045432),  INT64_C( 6026518686306491914) } },
    { { -INT64_C( 3584356179152410532),  INT64_C( 4906051486565099388), -INT64_C( 1366101536430197353),  INT64_C( 8224496603040749312),
        -INT64_C( 7923120276673706191), -INT64_C( 1446479750494385965), -INT64_C( 8910389985721130105),  INT64_C( 8578925485341605510) },
      {  INT64_C( 8676113926111639998), -INT64_C(  178157761981226169), -INT64_C( 2163206275760428047), -INT64_C( 8900366555989324099),
         INT64_C( 3882596483972280260),  INT64_C(  114375668867858979),  INT64_C( 8790870050429468099), -INT64_C( 3815965023055020865) },
      {  INT64_C( 4906051486565099388), -INT64_C(  178157761981226169),  INT64_C( 8224496603040749312), -INT64_C( 8900366555989324099),
        -INT64_C( 1446479750494385965),  INT64_C(  114375668867858979),  INT64_C( 8578925485341605510), -INT64_C( 3815965023055020865) } },
    { {  INT64_C( 5064883971355337511),  INT64_C( 3975118758575282968), -INT64_C( 3339045211638226573),  INT64_C( 5017679719933880016),
         INT64_C(  229020489171523268), -INT64_C(  762702069681615424), -INT64_C( 2028082101023817737),  INT64_C( 6221543192684802548) },
      {  INT64_C( 1522616162351690034), -INT64_C( 7282123080597942920), -INT64_C( 2924385492342205069), -INT64_C( 5505579620542896977),
        -INT64_C( 5089926017148922127), -INT64_C( 3783407034755209920),  INT64_C( 5724845474327962296), -INT64_C( 8352723087043503136) },
      {  INT64_C( 3975118758575282968), -INT64_C( 7282123080597942920),  INT64_C( 5017679719933880016), -INT64_C( 5505579620542896977),
        -INT64_C(  762702069681615424), -INT64_C( 3783407034755209920),  INT64_C( 6221543192684802548), -INT64_C( 8352723087043503136) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i a = simde_mm512_loadu_epi64(test_vec[i].a);
    simde__m512i b = simde_mm512_loadu_epi64(test_vec[i].b);
    simde__m512i r = simde_mm512_unpackhi_epi64(a, b);
    simde_test_x86_assert_equal_i64x8(r, simde_mm512_loadu_epi64(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_mm512_mask_unpackhi_epi64 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const int64_t src[8];
    const simde__mmask8 k;
    const int64_t a[8];
    const int64_t b[8];
    const int64_t r[8];
  } test_vec[] = {
    { {  INT64_C( 7069803644757198776), -INT64_C( 4615162892095733676), -INT64_C(  592481269516063786), -INT64_C( 1951860547106282793),
        -INT64_C( 4776033971357979552),  INT64_C( 5002361671084263902), -INT64_C( 4358438887271442656),  INT64_C( 2173316391371875352) },
      UINT8_C(151),
      { -INT64_C(  709390414091619285),  INT64_C( 1573069356133635006),  INT64_C(  606233209243590810),  INT64_C(  128886772494413063),
         INT64_C( 5007284282810091865),  INT64_C( 2853255272115790405),  INT64_C( 7429215763538876973),  INT64_C( 2190546868698210446) },
      {  INT64_C( 7491494037575544876), -INT64_C( 1605388421232398332), -INT64_C( 6997445859961327587),  INT64_C(  925324662345530868),
        -INT64_C( 6655275033583256551),  INT64_C( 3336302082892533414),  INT64_C( 5678071947195074077),  INT64_C( 5907279296854478606) },
      {  INT64_C( 1573069356133635006), -INT64_C( 1605388421232398332),  INT64_C(  128886772494413063), -INT64_C( 1951860547106282793),
         INT64_C( 2853255272115790405),  INT64_C( 5002361671084263902), -INT64_C( 4358438887271442656),  INT64_C( 5907279296854478606) } },
    { {  INT64_C( 1485397804821887067), -INT64_C( 2594421111010111041),  INT64_C( 5310541361681377801), -INT64_C(  851970217608758620),
        -INT64_C( 6094342348518540311), -INT64_C( 5694949449454066851),  INT64_C( 8766475294402150436), -INT64_C(  500319502935400576) },
      UINT8_C( 61),
      { -INT64_C( 6780779749143129604), -INT64_C(  581535033743376305), -INT64_C( 3219152390828831732),  INT64_C( 8600428855462947994),
        -INT64_C( 6301129233037032402), -INT64_C( 2750750709133486620), -INT64_C( 9191284002811764566),  INT64_C( 6799862801798878315) },
      {  INT64_C( 2629214055428676731), -INT64_C(  768756215722218067),  INT64_C( 7771248126770479220), -INT64_C( 1592112153495505320),
        -INT64_C( 5229179405259165430), -INT64_C( 5231346292924190938),  INT64_C( 6192989337208027527), -INT64_C(  380336530459311520) },
      { -INT64_C(  581535033743376305), -INT64_C( 2594421111010111041),  INT64_C( 8600428855462947994), -INT64_C( 1592112153495505320),
        -INT64_C( 2750750709133486620), -INT64_C( 5231346292924190938),  INT64_C( 8766475294402150436), -INT64_C(  500319502935400576) } },
    { { -INT64_C( 3046769058687715850), -INT64_C(  712503947079194334),  INT64_C( 8645343478219091111), -INT64_C( 7810088800309880655),
        -INT64_C( 5334713237796298637), -INT64_C( 7811151688720826829),  INT64_C( 3958718521792730723), -INT64_C( 6468731249084647927) },
      UINT8_C( 84),
      { -INT64_C(  122831116445431603), -INT64_C( 7038706715525976393), -INT64_C( 1013211252603499851), -INT64_C( 6991614324525197775),
         INT64_C( 3770077475849560211),  INT64_C( 8004712632414256368), -INT64_C( 4257513995879761346),  INT64_C( 7875214485939097308) },
      { -INT64_C(  940388094190813119), -INT64_C( 4073364536899791537), -INT64_C( 1219725549161624134),  INT64_C( 2233757779520879544),
         INT64_C( 2439491752443101158),  INT64_C( 9166411585423033573),  INT64_C( 6373121923404920175), -INT64_C( 2785500613664174757) },
      { -INT64_C( 3046769058687715850), -INT64_C(  712503947079194334), -INT64_C( 6991614324525197775), -INT64_C( 7810088800309880655),
         INT64_C( 8004712632414256368), -INT64_C( 7811151688720826829),  INT64_C( 7875214485939097308), -INT64_C( 6468731249084647927) } },
    { { -INT64_C( 1613524498428840792), -INT64_C( 2943791305104767519),  INT64_C( 3349213380578243459), -INT64_C(  674204802864421672),
        -INT64_C( 1954830502096509198),  INT64_C( 5192843631966959569),  INT64_C(  911105038106651042), -INT64_C( 4932148811623101623) },
      UINT8_C(226),
      { -INT64_C( 3973360625745808899), -INT64_C( 8239945592549338029), -INT64_C( 3859920510259160257), -INT64_C( 8141295836826761818),
         INT64_C(  529019795796519679), -INT64_C(  488165872602782584),  INT64_C( 8093966657315011530),  INT64_C( 3725204992451339920) },
      {  INT64_C( 5132725608845101952), -INT64_C( 4633873112000936449), -INT64_C( 1485453012652994776),  INT64_C(  858709281465037954),
        -INT64_C( 4102644257746080502),  INT64_C( 6373210507922310079), -INT64_C( 2790634902909175040),  INT64_C( 2104723718819304352) },
      { -INT64_C( 1613524498428840792), -INT64_C( 4633873112000936449),  INT64_C( 3349213380578243459), -INT64_C(  674204802864421672),
        -INT64_C( 1954830502096509198),  INT64_C( 6373210507922310079),  INT64_C( 3725204992451339920),  INT64_C( 2104723718819304352) } },
    { { -INT64_C( 5928997778794056664),  INT64_C( 7530813971257964538),  INT64_C( 1783153292805852302), -INT64_C(  897772364895137957),
         INT64_C( 7100377162194317805),  INT64_C( 5521993398515264210), -INT64_C( 4076337739640773412),  INT64_C( 1584632822595170368) },
      UINT8_C( 48),
      {  INT64_C( 7227990955471204833), -INT64_C( 8182076068310447992), -INT64_C( 1887076183540250465), -INT64_C( 5123086641714570505),
         INT64_C(  284433193656156180),  INT64_C( 2360746577768354570),  INT64_C( 8714605466890518230),  INT64_C( 3812602887049051481) },
      { -INT64_C( 6191124988141888106), -INT64_C( 7824543943707611192), -INT64_C( 1127994923696646048),  INT64_C( 3810056961364428683),
         INT64_C( 2265972895572730663),  INT64_C( 6006062423011250441),  INT64_C( 1257221751015995370), -INT64_C( 4258543097014807789) },
      { -INT64_C( 5928997778794056664),  INT64_C( 7530813971257964538),  INT64_C( 1783153292805852302), -INT64_C(  897772364895137957),
         INT64_C( 2360746577768354570),  INT64_C( 6006062423011250441), -INT64_C( 4076337739640773412),  INT64_C( 1584632822595170368) } },
    { { -INT64_C( 8018660757471482816), -INT64_C( 2623996657626898353),  INT64_C( 7511669188945889447), -INT64_C( 2755077514440606878),
        -INT64_C( 7187137741158527189), -INT64_C( 1146883776033417144), -INT64_C( 6631450114154204612),  INT64_C( 4451638983883100758) },
      UINT8_C(181),
      { -INT64_C( 3915423366592073928),  INT64_C( 7722832208524927870), -INT64_C( 3976589726295671265), -INT64_C( 4751834691028730125),
         INT64_C( 3386928682753790214),  INT64_C( 3679808221115060908),  INT64_C(  111320118149889548), -INT64_C( 9043112067202390724) },
      {  INT64_C( 1538746084056735866), -INT64_C( 3092621876665812020),  INT64_C( 8906468869616943498), -INT64_C( 2844659382430600057),
        -INT64_C( 4261426724832330147), -INT64_C( 1335396026422093863), -INT64_C( 5173475773515493766), -INT64_C( 8338061567367286508) },
      {  INT64_C( 7722832208524927870), -INT64_C( 2623996657626898353), -INT64_C( 4751834691028730125), -INT64_C( 2755077514440606878),
         INT64_C( 3679808221115060908), -INT64_C( 1335396026422093863), -INT64_C( 6631450114154204612), -INT64_C( 8338061567367286508) } },
    { { -INT64_C( 8918201848107479680),  INT64_C( 1375178542360748229), -INT64_C( 3560939127798195285),  INT64_C( 1309291379511284081),
         INT64_C( 8216191539417349846),  INT64_C( 8382237705590418343), -INT64_C( 8010525915789385909),  INT64_C( 8420424661542573110) },
      UINT8_C(217),
      {  INT64_C( 2797852451683038566), -INT64_C( 8823286804088155246),  INT64_C( 8849349408075322035), -INT64_C( 2695249943931086748),
        -INT64_C( 6367005662361805439), -INT64_C( 6279857409327787283),  INT64_C( 1650870196476411400),  INT64_C( 1150508682674766249) },
      { -INT64_C( 4231361816949948789), -INT64_C( 5881996165970841408),  INT64_C( 6501517465147514737),  INT64_C(  623026708646661896),
         INT64_C( 2236863357412454509), -INT64_C( 8614485485033282529), -INT64_C( 6855070614581177902),  INT64_C( 3493346093460509941) },
      { -INT64_C( 8823286804088155246),  INT64_C( 1375178542360748229), -INT64_C( 3560939127798195285),  INT64_C(  623026708646661896),
        -INT64_C( 6279857409327787283),  INT64_C( 8382237705590418343),  INT64_C( 1150508682674766249),  INT64_C( 3493346093460509941) } },
    { {  INT64_C( 3497748872912249356),  INT64_C( 7296790800698269604), -INT64_C( 3948876406478803207),  INT64_C( 5768466005105535001),
        -INT64_C( 6406294586842709033),  INT64_C( 8042484957435792805),  INT64_C( 7147267899479065747), -INT64_C(  635204218856117349) },
      UINT8_C(208),
      {  INT64_C(  348038273292296170),  INT64_C( 3248759616153717980),  INT64_C( 1781131515178417385), -INT64_C( 5821130368954558951),
         INT64_C( 7065219299381480208),  INT64_C( 6382999729258858175), -INT64_C(  127741380596069515), -INT64_C( 5461286742673493055) },
      { -INT64_C( 8750555892677929817), -INT64_C( 2299788635459980723),  INT64_C( 8534106568873118093),  INT64_C( 1731689519062570160),
        -INT64_C( 2840693246252432570), -INT64_C( 8029168252790406841), -INT64_C( 9196506772007709645), -INT64_C( 3039968717940958139) },
      {  INT64_C( 3497748872912249356),  INT64_C( 7296790800698269604), -INT64_C( 3948876406478803207),  INT64_C( 5768466005105535001),
         INT64_C( 6382999729258858175),  INT64_C( 8042484957435792805), -INT64_C( 5461286742673493055), -INT64_C( 3039968717940958139) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i src = simde_mm512_loadu_epi64(test_vec[i].src);
    simde__m512i a = simde_mm512_loadu_epi64(test_vec[i].a);
    simde__m512i b = simde_mm512_loadu_epi64(test_vec[i].b);
    simde__m512i r = simde_mm512_mask_unpackhi_epi64(src, test_vec[i].k, a, b);
    simde_test_x86_assert_equal_i64x8(r, simde_mm512_loadu_epi64(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_mm512_maskz_unpackhi_epi64 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const simde__mmask8 k;
    const int64_t a[8];
    const int64_t b[8];
    const int64_t r[8];
  } test_vec[] = {
    { UINT8_C(153),
      { -INT64_C( 8112061316095643358),  INT64_C( 6935063002730107714), -INT64_C( 8212087054093038310), -INT64_C( 2607746116477873009),
         INT64_C( 3144832950630399454), -INT64_C( 5137730184067198396),  INT64_C( 4921647922986935914), -INT64_C( 8765048687182594872) },
      { -INT64_C( 7702493116525469689), -INT64_C( 9014066700485133679),  INT64_C( 1259476586114192513),  INT64_C( 5114663378355418315),
         INT64_C( 7382897138880386447),  INT64_C( 8711789030675930443), -INT64_C( 8941289340094502767), -INT64_C(  314705051237516003) },
      {  INT64_C( 6935063002730107714),  INT64_C(                   0),  INT64_C(                   0),  INT64_C( 5114663378355418315),
        -INT64_C( 5137730184067198396),  INT64_C(                   0),  INT64_C(                   0), -INT64_C(  314705051237516003) } },
    { UINT8_C(135),
      { -INT64_C( 5875859059498033961), -INT64_C( 1917092265710921897), -INT64_C( 6480081549246251315), -INT64_C( 1761174571067478505),
         INT64_C(  281901227435879401),  INT64_C( 8934645429188398939), -INT64_C( 3293675335527130245),  INT64_C( 6045918023986601201) },
      { -INT64_C( 3096937802851485867), -INT64_C( 7768449762043438073),  INT64_C( 1446924468239245447), -INT64_C( 5937155702654636322),
        -INT64_C( 6394068444791232269), -INT64_C( 6611974618886688368), -INT64_C( 3070053105838688980),  INT64_C( 7633521611942754793) },
      { -INT64_C( 1917092265710921897), -INT64_C( 7768449762043438073), -INT64_C( 1761174571067478505),  INT64_C(                   0),
         INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C( 7633521611942754793) } },
    { UINT8_C(224),
      {  INT64_C( 5540033489920907166),  INT64_C( 4556251704725245059),  INT64_C( 7626860197896948725), -INT64_C( 6359002367070889431),
        -INT64_C( 1546745235567460320), -INT64_C(  761050062070877593), -INT64_C( 2658604054839187776),  INT64_C( 7171837558290971095) },
      { -INT64_C( 4391248934469730115), -INT64_C(  140064324810700776), -INT64_C( 8603624947397496053), -INT64_C( 8185309017209743934),
         INT64_C( 5012719882948773489), -INT64_C(  862882530471279158),  INT64_C( 4582777096366109792),  INT64_C( 7205948465858413216) },
      {  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
         INT64_C(                   0), -INT64_C(  862882530471279158),  INT64_C( 7171837558290971095),  INT64_C( 7205948465858413216) } },
    { UINT8_C(177),
      {  INT64_C( 5061802720489189811),  INT64_C(  165828678393022336), -INT64_C(  377810925094215978), -INT64_C( 1847230989765627135),
        -INT64_C( 2410944925150790782), -INT64_C( 5390499936422085918),  INT64_C( 8099610054905737334),  INT64_C( 2874557315520681163) },
      { -INT64_C( 4904149681540743243),  INT64_C( 5278813408176356271),  INT64_C( 8983307628280486349), -INT64_C(  630400309860317069),
         INT64_C( 5706899244913896349),  INT64_C(  491489641323306421),  INT64_C( 1974245321395571000), -INT64_C( 2671070819006554187) },
      {  INT64_C(  165828678393022336),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
        -INT64_C( 5390499936422085918),  INT64_C(  491489641323306421),  INT64_C(                   0), -INT64_C( 2671070819006554187) } },
    { UINT8_C( 30),
      { -INT64_C( 6942565444498861832), -INT64_C( 8340139830770323222),  INT64_C( 7981591915461356065), -INT64_C( 6767355895724917629),
        -INT64_C( 3749461226211191851), -INT64_C( 3315751378116882324),  INT64_C(  233243253361619007),  INT64_C( 4732736115633153889) },
      { -INT64_C( 1473080054470065438), -INT64_C( 5268272069701115295), -INT64_C( 3960141369283656825), -INT64_C(  840903116746062937),
        -INT64_C( 2292537272392225083),  INT64_C( 7481840039537838503), -INT64_C( 4626753622671206248), -INT64_C( 1693030055064461445) },
      {  INT64_C(                   0), -INT64_C( 5268272069701115295), -INT64_C( 6767355895724917629), -INT64_C(  840903116746062937),
        -INT64_C( 3315751378116882324),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0) } },
    { UINT8_C( 20),
      { -INT64_C( 2007351597602755528),  INT64_C( 7985773938750014054),  INT64_C( 4507335351563900057), -INT64_C( 3147372254168278505),
        -INT64_C( 4560890390205241739),  INT64_C( 4485249486166915513),  INT64_C( 2414171336890893475), -INT64_C( 6960398803146907145) },
      { -INT64_C( 1607182324373407336),  INT64_C( 2197746152424123805), -INT64_C( 6708426467054661701), -INT64_C( 8030870343051295038),
        -INT64_C( 4796557763825959850), -INT64_C( 2775486076469499679),  INT64_C( 9195090110878505805), -INT64_C( 4299820068894879541) },
      {  INT64_C(                   0),  INT64_C(                   0), -INT64_C( 3147372254168278505),  INT64_C(                   0),
         INT64_C( 4485249486166915513),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0) } },
    { UINT8_C(244),
      { -INT64_C( 2095632079641097515), -INT64_C( 7089832664592529712), -INT64_C(   15524902365195400), -INT64_C( 5534588735990232252),
        -INT64_C( 1794783307867863429),  INT64_C( 7659445327702071277), -INT64_C( 4426703642843175580), -INT64_C( 6247284131365912901) },
      { -INT64_C( 7100499098819753354), -INT64_C( 2348460646870504691), -INT64_C( 4937067789841936324),  INT64_C( 2511218222881405697),
        -INT64_C( 4973339936969148243),  INT64_C( 1957695701676279760), -INT64_C( 6724628912605389327),  INT64_C( 5951978209226654412) },
      {  INT64_C(                   0),  INT64_C(                   0), -INT64_C( 5534588735990232252),  INT64_C(                   0),
         INT64_C( 7659445327702071277),  INT64_C( 1957695701676279760), -INT64_C( 6247284131365912901),  INT64_C( 5951978209226654412) } },
    { UINT8_C(100),
      { -INT64_C(  990848356323315639),  INT64_C( 6095881269656193925),  INT64_C( 4169656188011907520),  INT64_C( 4069620111938311530),
        -INT64_C( 2486296676270633759), -INT64_C(  397131255520211342),  INT64_C( 8436624239100720037),  INT64_C(  388723695290217278) },
      {  INT64_C( 7261790460150090898),  INT64_C(  833741416274152285), -INT64_C( 4107569250562498946),  INT64_C( 2528587095903275758),
         INT64_C( 1566080278840911972), -INT64_C( 3345543044703434720),  INT64_C( 7145622119506409948), -INT64_C( 2767306435414581789) },
      {  INT64_C(                   0),  INT64_C(                   0),  INT64_C( 4069620111938311530),  INT64_C(                   0),
         INT64_C(                   0), -INT64_C( 3345543044703434720),  INT64_C(  388723695290217278),  INT64_C(                   0) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i a = simde_mm512_loadu_epi64(test_vec[i].a);
    simde__m512i b = simde_mm512_loadu_epi64(test_vec[i].b);
    simde__m512i r = simde_mm512_maskz_unpackhi_epi64(test_vec[i].k, a, b);
    simde_test_x86_assert_equal_i64x8(r, simde_mm512_loadu_epi64(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_mm256_mask_unpackhi_epi64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int64_t src[4];
    const simde__mmask8 k;
    const int64_t a[4];
    const int64_t b[4];
    const int64_t r[4];
  } test_vec[] = {
    { {  INT64_C( 7646469454795260300), -INT64_C( 7535955763067342699),  INT64_C( 3193170217332895039),  INT64_C( 5507707457393293509) },
      UINT8_C(143),
      {  INT64_C( 8119547300260553569),  INT64_C( 3018872162273055166), -INT64_C( 5918932548073888597),  INT64_C(  669551624656337004) },
      {  INT64_C( 8758604877378244060),  INT64_C(  146090284036335265), -INT64_C( 4914565947700242967), -INT64_C( 3540743062152660948) },
      {  INT64_C( 3018872162273055166),  INT64_C(  146090284036335265),  INT64_C(  669551624656337004), -INT64_C( 3540743062152660948) } },
    { {  INT64_C( 8088878135751933453),  INT64_C( 5689546501102854301),  INT64_C( 3383389702738153193),  INT64_C( 3976359794595424879) },
      UINT8_C(220),
      { -INT64_C( 6760717497199296487),  INT64_C( 2640891787648376936),  INT64_C( 4424598428292931521),  INT64_C( 1085542290457872213) },
      {  INT64_C( 4504387800587549598), -INT64_C( 6978711498147526164), -INT64_C(  679482104188810111),  INT64_C( 3875973748853700805) },
      {  INT64_C( 8088878135751933453),  INT64_C( 5689546501102854301),  INT64_C( 1085542290457872213),  INT64_C( 3875973748853700805) } },
    { {  INT64_C( 2452657729359407604),  INT64_C( 2854520919423190048), -INT64_C(  635557087577164649), -INT64_C( 8804399207173368060) },
      UINT8_C(231),
      {  INT64_C( 6745334895949402341),  INT64_C( 7729631853594057315),  INT64_C(  268127643002305959),  INT64_C(  624902089727038279) },
      {  INT64_C( 7647147384975444073), -INT64_C(  694577644593208134), -INT64_C( 3059806111832278565), -INT64_C( 6854401427186770507) },
      {  INT64_C( 7729631853594057315), -INT64_C(  694577644593208134),  INT64_C(  624902089727038279), -INT64_C( 8804399207173368060) } },
    { {  INT64_C( 4503462755711542286), -INT64_C( 3391901055826552921), -INT64_C( 5843736106124273788), -INT64_C( 3038409372120743683) },
      UINT8_C(202),
      {  INT64_C(   99796531792505400), -INT64_C( 2536997439224260421),  INT64_C( 4826314824186452765),  INT64_C( 4339743826572291849) },
      { -INT64_C( 3588145064113109048),  INT64_C( 1068442667430718129),  INT64_C( 3944596012240972218),  INT64_C( 7959232342183495476) },
      {  INT64_C( 4503462755711542286),  INT64_C( 1068442667430718129), -INT64_C( 5843736106124273788),  INT64_C( 7959232342183495476) } },
    { {  INT64_C( 8523296235134675814), -INT64_C(  721068264151753217),  INT64_C( 4849303735835363817),  INT64_C( 3966528675615863287) },
      UINT8_C( 91),
      {  INT64_C( 6232866407644705195),  INT64_C( 8515611373782331139), -INT64_C( 9214145419909250055),  INT64_C( 8398800748528385347) },
      {  INT64_C( 5154777985252109881), -INT64_C( 7222163420159992862),  INT64_C( 6055904512458377723),  INT64_C( 2080405619374250914) },
      {  INT64_C( 8515611373782331139), -INT64_C( 7222163420159992862),  INT64_C( 4849303735835363817),  INT64_C( 2080405619374250914) } },
    { {  INT64_C( 2905059554952729540), -INT64_C( 8200706841899443213),  INT64_C( 9073102721507718533),  INT64_C( 5440004784187273598) },
      UINT8_C(154),
      {  INT64_C( 9122050544194573261),  INT64_C( 6071027526909635967),  INT64_C( 3699895942962403255),  INT64_C(  356916005772638611) },
      {  INT64_C( 6591653421997741144), -INT64_C( 2080285707232441233), -INT64_C( 8132913805274558418),  INT64_C( 4182400262031924430) },
      {  INT64_C( 2905059554952729540), -INT64_C( 2080285707232441233),  INT64_C( 9073102721507718533),  INT64_C( 4182400262031924430) } },
    { {  INT64_C( 7271819117059290290), -INT64_C( 8769824210203573956), -INT64_C( 1500094372871075677), -INT64_C( 6300257748035496076) },
      UINT8_C(176),
      {  INT64_C( 2500353356961494982),  INT64_C( 7940691008478124860),  INT64_C( 1694046152460849782),  INT64_C( 3320478285238753384) },
      { -INT64_C(   58449200384984596),  INT64_C( 2398099369943345779), -INT64_C( 5716280376734788972),  INT64_C( 6422458996285028490) },
      {  INT64_C( 7271819117059290290), -INT64_C( 8769824210203573956), -INT64_C( 1500094372871075677), -INT64_C( 6300257748035496076) } },
    { { -INT64_C( 7951783409172887838), -INT64_C( 8498941247691803583),  INT64_C( 8682036209110629507), -INT64_C( 7257115693828894590) },
      UINT8_C( 81),
      {  INT64_C( 1839721432526831792), -INT64_C( 4639101782066236054),  INT64_C( 8503682193353960119), -INT64_C( 1482587822103727473) },
      {  INT64_C( 5119110484057054219),  INT64_C( 7669913511692212528), -INT64_C( 3186316238436753813), -INT64_C( 3744643304697956383) },
      { -INT64_C( 4639101782066236054), -INT64_C( 8498941247691803583),  INT64_C( 8682036209110629507), -INT64_C( 7257115693828894590) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256i src = simde_x_mm256_loadu_epi64(test_vec[i].src);
    simde__mmask8 k = test_vec[i].k;
    simde__m256i a = simde_x_mm256_loadu_epi64(test_vec[i].a);
    simde__m256i b = simde_x_mm256_loadu_epi64(test_vec[i].b);
    simde__m256i r = simde_mm256_mask_unpackhi_epi64(src, k, a, b);
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
    simde__m256i r = simde_mm256_mask_unpackhi_epi64(src, k, a, b);

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
test_simde_mm256_maskz_unpackhi_epi64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k;
    const int64_t a[4];
    const int64_t b[4];
    const int64_t r[4];
  } test_vec[] = {
    { UINT8_C( 18),
      {  INT64_C( 7672659715659684548), -INT64_C(  895928894756625205), -INT64_C( 5500093481825810569), -INT64_C( 7956867899439643474) },
      {  INT64_C( 8766025426082720736),  INT64_C( 2985833443465473298),  INT64_C( 3487840560681698198), -INT64_C(   23006051952388016) },
      {  INT64_C(                   0),  INT64_C( 2985833443465473298),  INT64_C(                   0),  INT64_C(                   0) } },
    { UINT8_C( 48),
      { -INT64_C( 8025316801596474271),  INT64_C( 5763318394577362069), -INT64_C( 5789376121198760180), -INT64_C( 3159612190608144974) },
      { -INT64_C(  973618242509404919),  INT64_C( 4033626763775426336),  INT64_C( 9135614293357677313),  INT64_C( 7802094255873562366) },
      {  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0) } },
    { UINT8_C(160),
      { -INT64_C( 7652476866288330583),  INT64_C( 4511190048342833223),  INT64_C( 1278610508815709063),  INT64_C( 2178300165477380094) },
      {  INT64_C( 7972381959383627576), -INT64_C( 2107506115997113585),  INT64_C( 5900102899930942037),  INT64_C( 7864170283981821327) },
      {  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0) } },
    { UINT8_C( 92),
      { -INT64_C( 9109108458367190034), -INT64_C( 6705368536919042054), -INT64_C(  626203058833604256),  INT64_C( 7400427354837505074) },
      {  INT64_C( 2645163473921390357), -INT64_C( 5831122137745682023), -INT64_C( 9148008971218515854), -INT64_C( 1877564742309497069) },
      {  INT64_C(                   0),  INT64_C(                   0),  INT64_C( 7400427354837505074), -INT64_C( 1877564742309497069) } },
    { UINT8_C(195),
      {  INT64_C( 6915578280891193822), -INT64_C( 8722243784665044271),  INT64_C( 5376549271595452620), -INT64_C(  540713315452901329) },
      {  INT64_C( 5712342782855113753),  INT64_C( 2143649999816422588),  INT64_C( 1958298296693331407),  INT64_C( 7097767882269345902) },
      { -INT64_C( 8722243784665044271),  INT64_C( 2143649999816422588),  INT64_C(                   0),  INT64_C(                   0) } },
    { UINT8_C(194),
      { -INT64_C( 8870524942194554408),  INT64_C( 8356415769102655330),  INT64_C( 5714921725932591771),  INT64_C( 3416817422199936850) },
      { -INT64_C( 7109145060111242429), -INT64_C( 4850450323220386467), -INT64_C( 2599161334107140457), -INT64_C( 4518818525711465277) },
      {  INT64_C(                   0), -INT64_C( 4850450323220386467),  INT64_C(                   0),  INT64_C(                   0) } },
    { UINT8_C(153),
      {  INT64_C( 1818735082430829730),  INT64_C( 3930224276279031862), -INT64_C( 7330563776795694956),  INT64_C( 5378944645744582174) },
      {  INT64_C( 2409821531819112813),  INT64_C( 3908455569879772127), -INT64_C( 5298490906411336505), -INT64_C( 3077251124462186663) },
      {  INT64_C( 3930224276279031862),  INT64_C(                   0),  INT64_C(                   0), -INT64_C( 3077251124462186663) } },
    { UINT8_C(225),
      {  INT64_C( 5385159050311511413), -INT64_C(  258918497261927935),  INT64_C( 5416785527172187609), -INT64_C( 1345018862764872436) },
      {  INT64_C( 1197822322502345141), -INT64_C( 8700082918343537849),  INT64_C( 3198830207273981533),  INT64_C( 6132483906632423348) },
      { -INT64_C(  258918497261927935),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__mmask8 k = test_vec[i].k;
    simde__m256i a = simde_x_mm256_loadu_epi64(test_vec[i].a);
    simde__m256i b = simde_x_mm256_loadu_epi64(test_vec[i].b);
    simde__m256i r = simde_mm256_maskz_unpackhi_epi64(k, a, b);
    simde_test_x86_assert_equal_i64x4(r, simde_x_mm256_loadu_epi64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m256i a = simde_test_x86_random_i64x4();
    simde__m256i b = simde_test_x86_random_i64x4();
    simde__m256i r = simde_mm256_maskz_unpackhi_epi64(k, a, b);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i64x4(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_mask_unpackhi_epi64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int64_t src[2];
    const simde__mmask8 k;
    const int64_t a[2];
    const int64_t b[2];
    const int64_t r[2];
  } test_vec[] = {
    { { -INT64_C( 5141746319706645371), -INT64_C(  203515909701093709) },
      UINT8_C(246),
      {  INT64_C( 7584404248950483637), -INT64_C(  510064146778037178) },
      { -INT64_C( 6546642386201687143), -INT64_C( 4056056532926667321) },
      { -INT64_C( 5141746319706645371), -INT64_C( 4056056532926667321) } },
    { { -INT64_C( 2662459067363336920),  INT64_C( 3117384373909958383) },
      UINT8_C(247),
      { -INT64_C( 6296018248053383886),  INT64_C( 8157005268882447884) },
      { -INT64_C( 7906383724973467829),  INT64_C(  524476758698005027) },
      {  INT64_C( 8157005268882447884),  INT64_C(  524476758698005027) } },
    { { -INT64_C( 4154429121224462867), -INT64_C( 2422088240626396449) },
      UINT8_C(218),
      {  INT64_C( 1039858158257714537), -INT64_C( 5569849908394738315) },
      { -INT64_C( 3662779191425014837), -INT64_C( 1522147950189339390) },
      { -INT64_C( 4154429121224462867), -INT64_C( 1522147950189339390) } },
    { {  INT64_C( 7349491892837785204), -INT64_C( 7487271985539784351) },
      UINT8_C( 64),
      {  INT64_C( 3221982553216640131),  INT64_C( 4241151271621213224) },
      { -INT64_C( 6137685246802736179), -INT64_C( 3254115371233888327) },
      {  INT64_C( 7349491892837785204), -INT64_C( 7487271985539784351) } },
    { { -INT64_C( 4310440057375370253),  INT64_C( 4742016030433074425) },
      UINT8_C(209),
      { -INT64_C( 4881263710097984775), -INT64_C( 8953756732768921157) },
      { -INT64_C( 3847793792583221405), -INT64_C(  583919847436571122) },
      { -INT64_C( 8953756732768921157),  INT64_C( 4742016030433074425) } },
    { {  INT64_C( 9183616735998148402), -INT64_C( 4697527801932579429) },
      UINT8_C(198),
      {  INT64_C( 2801097100382985966),  INT64_C( 6300004643785470908) },
      {  INT64_C( 1511408025357395100),  INT64_C(  121646753499792611) },
      {  INT64_C( 9183616735998148402),  INT64_C(  121646753499792611) } },
    { { -INT64_C( 6869482690872973941), -INT64_C( 8731552881563611484) },
      UINT8_C(110),
      {  INT64_C( 2479824083576284398),  INT64_C( 7656461339177866377) },
      {  INT64_C( 4422514423240705289), -INT64_C( 7096917995818525495) },
      { -INT64_C( 6869482690872973941), -INT64_C( 7096917995818525495) } },
    { {  INT64_C( 3067672219726743443),  INT64_C(  599861657906235620) },
      UINT8_C(231),
      { -INT64_C(   47407490142911584),  INT64_C( 8429978660088212411) },
      { -INT64_C( 3970978602688287375), -INT64_C( 4527578737884541663) },
      {  INT64_C( 8429978660088212411), -INT64_C( 4527578737884541663) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i src = simde_x_mm_loadu_epi64(test_vec[i].src);
    simde__m128i a = simde_x_mm_loadu_epi64(test_vec[i].a);
    simde__m128i b = simde_x_mm_loadu_epi64(test_vec[i].b);
    simde__m128i r = simde_mm_mask_unpackhi_epi64(src, test_vec[i].k, a, b);
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
    simde__m128i r = simde_mm_mask_unpackhi_epi64(src, k, a, b);

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
test_simde_mm512_unpackhi_ps (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const simde_float32 a[16];
    const simde_float32 b[16];
    const simde_float32 r[16];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(   501.25), SIMDE_FLOAT32_C(   354.44), SIMDE_FLOAT32_C(  -760.98), SIMDE_FLOAT32_C(   367.33),
        SIMDE_FLOAT32_C(   563.03), SIMDE_FLOAT32_C(   427.95), SIMDE_FLOAT32_C(   773.44), SIMDE_FLOAT32_C(   713.02),
        SIMDE_FLOAT32_C(   119.86), SIMDE_FLOAT32_C(   -12.94), SIMDE_FLOAT32_C(   867.61), SIMDE_FLOAT32_C(  -313.75),
        SIMDE_FLOAT32_C(   147.55), SIMDE_FLOAT32_C(  -416.41), SIMDE_FLOAT32_C(  -877.86), SIMDE_FLOAT32_C(  -808.32) },
      { SIMDE_FLOAT32_C(  -972.10), SIMDE_FLOAT32_C(   298.29), SIMDE_FLOAT32_C(   288.84), SIMDE_FLOAT32_C(   810.71),
        SIMDE_FLOAT32_C(   626.39), SIMDE_FLOAT32_C(  -563.97), SIMDE_FLOAT32_C(   -14.08), SIMDE_FLOAT32_C(  -444.31),
        SIMDE_FLOAT32_C(   614.59), SIMDE_FLOAT32_C(    98.84), SIMDE_FLOAT32_C(   586.04), SIMDE_FLOAT32_C(   326.60),
        SIMDE_FLOAT32_C(  -948.81), SIMDE_FLOAT32_C(  -681.79), SIMDE_FLOAT32_C(   949.12), SIMDE_FLOAT32_C(   552.44) },
      { SIMDE_FLOAT32_C(  -760.98), SIMDE_FLOAT32_C(   288.84), SIMDE_FLOAT32_C(   367.33), SIMDE_FLOAT32_C(   810.71),
        SIMDE_FLOAT32_C(   773.44), SIMDE_FLOAT32_C(   -14.08), SIMDE_FLOAT32_C(   713.02), SIMDE_FLOAT32_C(  -444.31),
        SIMDE_FLOAT32_C(   867.61), SIMDE_FLOAT32_C(   586.04), SIMDE_FLOAT32_C(  -313.75), SIMDE_FLOAT32_C(   326.60),
        SIMDE_FLOAT32_C(  -877.86), SIMDE_FLOAT32_C(   949.12), SIMDE_FLOAT32_C(  -808.32), SIMDE_FLOAT32_C(   552.44) } },
    { { SIMDE_FLOAT32_C(   672.66), SIMDE_FLOAT32_C(  -811.86), SIMDE_FLOAT32_C(   -80.22), SIMDE_FLOAT32_C(   235.69),
        SIMDE_FLOAT32_C(   616.10), SIMDE_FLOAT32_C(  -306.79), SIMDE_FLOAT32_C(   -51.30), SIMDE_FLOAT32_C(  -264.04),
        SIMDE_FLOAT32_C(   680.27), SIMDE_FLOAT32_C(  -183.69), SIMDE_FLOAT32_C(   422.21), SIMDE_FLOAT32_C(  -172.18),
        SIMDE_FLOAT32_C(   399.90), SIMDE_FLOAT32_C(   544.35), SIMDE_FLOAT32_C(    19.50), SIMDE_FLOAT32_C(   427.80) },
      { SIMDE_FLOAT32_C(  -157.35), SIMDE_FLOAT32_C(  -691.65), SIMDE_FLOAT32_C(   238.51), SIMDE_FLOAT32_C(  -530.97),
        SIMDE_FLOAT32_C(  -255.62), SIMDE_FLOAT32_C(  -775.57), SIMDE_FLOAT32_C(    24.72), SIMDE_FLOAT32_C(  -641.03),
        SIMDE_FLOAT32_C(   323.27), SIMDE_FLOAT32_C(  -389.24), SIMDE_FLOAT32_C(   685.56), SIMDE_FLOAT32_C(   374.47),
        SIMDE_FLOAT32_C(   -71.03), SIMDE_FLOAT32_C(   634.69), SIMDE_FLOAT32_C(   -73.09), SIMDE_FLOAT32_C(  -398.37) },
      { SIMDE_FLOAT32_C(   -80.22), SIMDE_FLOAT32_C(   238.51), SIMDE_FLOAT32_C(   235.69), SIMDE_FLOAT32_C(  -530.97),
        SIMDE_FLOAT32_C(   -51.30), SIMDE_FLOAT32_C(    24.72), SIMDE_FLOAT32_C(  -264.04), SIMDE_FLOAT32_C(  -641.03),
        SIMDE_FLOAT32_C(   422.21), SIMDE_FLOAT32_C(   685.56), SIMDE_FLOAT32_C(  -172.18), SIMDE_FLOAT32_C(   374.47),
        SIMDE_FLOAT32_C(    19.50), SIMDE_FLOAT32_C(   -73.09), SIMDE_FLOAT32_C(   427.80), SIMDE_FLOAT32_C(  -398.37) } },
    { { SIMDE_FLOAT32_C(   822.83), SIMDE_FLOAT32_C(   846.69), SIMDE_FLOAT32_C(   837.31), SIMDE_FLOAT32_C(   438.93),
        SIMDE_FLOAT32_C(  -460.10), SIMDE_FLOAT32_C(  -213.99), SIMDE_FLOAT32_C(  -825.11), SIMDE_FLOAT32_C(  -779.83),
        SIMDE_FLOAT32_C(   602.32), SIMDE_FLOAT32_C(   597.10), SIMDE_FLOAT32_C(    47.99), SIMDE_FLOAT32_C(     2.23),
        SIMDE_FLOAT32_C(   141.46), SIMDE_FLOAT32_C(  -932.50), SIMDE_FLOAT32_C(  -569.97), SIMDE_FLOAT32_C(   984.10) },
      { SIMDE_FLOAT32_C(  -624.16), SIMDE_FLOAT32_C(   668.54), SIMDE_FLOAT32_C(  -546.86), SIMDE_FLOAT32_C(   120.22),
        SIMDE_FLOAT32_C(   892.97), SIMDE_FLOAT32_C(   477.86), SIMDE_FLOAT32_C(   479.19), SIMDE_FLOAT32_C(   216.25),
        SIMDE_FLOAT32_C(  -911.39), SIMDE_FLOAT32_C(   164.75), SIMDE_FLOAT32_C(  -409.28), SIMDE_FLOAT32_C(    17.58),
        SIMDE_FLOAT32_C(  -200.56), SIMDE_FLOAT32_C(   517.63), SIMDE_FLOAT32_C(   619.21), SIMDE_FLOAT32_C(  -377.73) },
      { SIMDE_FLOAT32_C(   837.31), SIMDE_FLOAT32_C(  -546.86), SIMDE_FLOAT32_C(   438.93), SIMDE_FLOAT32_C(   120.22),
        SIMDE_FLOAT32_C(  -825.11), SIMDE_FLOAT32_C(   479.19), SIMDE_FLOAT32_C(  -779.83), SIMDE_FLOAT32_C(   216.25),
        SIMDE_FLOAT32_C(    47.99), SIMDE_FLOAT32_C(  -409.28), SIMDE_FLOAT32_C(     2.23), SIMDE_FLOAT32_C(    17.58),
        SIMDE_FLOAT32_C(  -569.97), SIMDE_FLOAT32_C(   619.21), SIMDE_FLOAT32_C(   984.10), SIMDE_FLOAT32_C(  -377.73) } },
    { { SIMDE_FLOAT32_C(   364.32), SIMDE_FLOAT32_C(   456.52), SIMDE_FLOAT32_C(  -938.80), SIMDE_FLOAT32_C(   904.22),
        SIMDE_FLOAT32_C(  -757.47), SIMDE_FLOAT32_C(  -763.91), SIMDE_FLOAT32_C(  -875.61), SIMDE_FLOAT32_C(   844.86),
        SIMDE_FLOAT32_C(   833.20), SIMDE_FLOAT32_C(   172.39), SIMDE_FLOAT32_C(  -152.92), SIMDE_FLOAT32_C(   -25.35),
        SIMDE_FLOAT32_C(   239.88), SIMDE_FLOAT32_C(   277.11), SIMDE_FLOAT32_C(   -41.24), SIMDE_FLOAT32_C(   615.73) },
      { SIMDE_FLOAT32_C(   -54.35), SIMDE_FLOAT32_C(   411.89), SIMDE_FLOAT32_C(  -264.06), SIMDE_FLOAT32_C(  -161.38),
        SIMDE_FLOAT32_C(  -110.25), SIMDE_FLOAT32_C(  -784.87), SIMDE_FLOAT32_C(  -945.13), SIMDE_FLOAT32_C(   -21.64),
        SIMDE_FLOAT32_C(   379.88), SIMDE_FLOAT32_C(  -354.42), SIMDE_FLOAT32_C(   995.95), SIMDE_FLOAT32_C(  -820.68),
        SIMDE_FLOAT32_C(  -836.79), SIMDE_FLOAT32_C(   615.15), SIMDE_FLOAT32_C(  -198.41), SIMDE_FLOAT32_C(   527.53) },
      { SIMDE_FLOAT32_C(  -938.80), SIMDE_FLOAT32_C(  -264.06), SIMDE_FLOAT32_C(   904.22), SIMDE_FLOAT32_C(  -161.38),
        SIMDE_FLOAT32_C(  -875.61), SIMDE_FLOAT32_C(  -945.13), SIMDE_FLOAT32_C(   844.86), SIMDE_FLOAT32_C(   -21.64),
        SIMDE_FLOAT32_C(  -152.92), SIMDE_FLOAT32_C(   995.95), SIMDE_FLOAT32_C(   -25.35), SIMDE_FLOAT32_C(  -820.68),
        SIMDE_FLOAT32_C(   -41.24), SIMDE_FLOAT32_C(  -198.41), SIMDE_FLOAT32_C(   615.73), SIMDE_FLOAT32_C(   527.53) } },
    { { SIMDE_FLOAT32_C(    71.67), SIMDE_FLOAT32_C(  -137.20), SIMDE_FLOAT32_C(   431.75), SIMDE_FLOAT32_C(   314.20),
        SIMDE_FLOAT32_C(    98.89), SIMDE_FLOAT32_C(   556.14), SIMDE_FLOAT32_C(   159.06), SIMDE_FLOAT32_C(   -67.91),
        SIMDE_FLOAT32_C(  -271.47), SIMDE_FLOAT32_C(  -993.86), SIMDE_FLOAT32_C(   906.74), SIMDE_FLOAT32_C(   968.41),
        SIMDE_FLOAT32_C(   283.25), SIMDE_FLOAT32_C(  -134.50), SIMDE_FLOAT32_C(   584.13), SIMDE_FLOAT32_C(  -771.10) },
      { SIMDE_FLOAT32_C(  -722.60), SIMDE_FLOAT32_C(  -679.92), SIMDE_FLOAT32_C(    67.52), SIMDE_FLOAT32_C(   167.15),
        SIMDE_FLOAT32_C(  -464.79), SIMDE_FLOAT32_C(   122.39), SIMDE_FLOAT32_C(  -854.49), SIMDE_FLOAT32_C(   915.09),
        SIMDE_FLOAT32_C(   767.97), SIMDE_FLOAT32_C(  -858.54), SIMDE_FLOAT32_C(  -905.59), SIMDE_FLOAT32_C(   931.19),
        SIMDE_FLOAT32_C(   756.61), SIMDE_FLOAT32_C(  -104.00), SIMDE_FLOAT32_C(   458.72), SIMDE_FLOAT32_C(  -171.72) },
      { SIMDE_FLOAT32_C(   431.75), SIMDE_FLOAT32_C(    67.52), SIMDE_FLOAT32_C(   314.20), SIMDE_FLOAT32_C(   167.15),
        SIMDE_FLOAT32_C(   159.06), SIMDE_FLOAT32_C(  -854.49), SIMDE_FLOAT32_C(   -67.91), SIMDE_FLOAT32_C(   915.09),
        SIMDE_FLOAT32_C(   906.74), SIMDE_FLOAT32_C(  -905.59), SIMDE_FLOAT32_C(   968.41), SIMDE_FLOAT32_C(   931.19),
        SIMDE_FLOAT32_C(   584.13), SIMDE_FLOAT32_C(   458.72), SIMDE_FLOAT32_C(  -771.10), SIMDE_FLOAT32_C(  -171.72) } },
    { { SIMDE_FLOAT32_C(   758.80), SIMDE_FLOAT32_C(  -109.54), SIMDE_FLOAT32_C(  -857.52), SIMDE_FLOAT32_C(  -142.31),
        SIMDE_FLOAT32_C(  -553.40), SIMDE_FLOAT32_C(   301.54), SIMDE_FLOAT32_C(   789.78), SIMDE_FLOAT32_C(   175.13),
        SIMDE_FLOAT32_C(   307.68), SIMDE_FLOAT32_C(   696.52), SIMDE_FLOAT32_C(   143.54), SIMDE_FLOAT32_C(  -409.06),
        SIMDE_FLOAT32_C(  -437.98), SIMDE_FLOAT32_C(  -272.33), SIMDE_FLOAT32_C(  -180.16), SIMDE_FLOAT32_C(  -160.59) },
      { SIMDE_FLOAT32_C(    47.75), SIMDE_FLOAT32_C(   887.36), SIMDE_FLOAT32_C(  -993.44), SIMDE_FLOAT32_C(   582.95),
        SIMDE_FLOAT32_C(     9.75), SIMDE_FLOAT32_C(  -847.93), SIMDE_FLOAT32_C(   498.04), SIMDE_FLOAT32_C(  -222.27),
        SIMDE_FLOAT32_C(  -706.47), SIMDE_FLOAT32_C(   592.44), SIMDE_FLOAT32_C(  -291.09), SIMDE_FLOAT32_C(  -949.86),
        SIMDE_FLOAT32_C(  -511.56), SIMDE_FLOAT32_C(  -832.37), SIMDE_FLOAT32_C(  -121.58), SIMDE_FLOAT32_C(  -752.76) },
      { SIMDE_FLOAT32_C(  -857.52), SIMDE_FLOAT32_C(  -993.44), SIMDE_FLOAT32_C(  -142.31), SIMDE_FLOAT32_C(   582.95),
        SIMDE_FLOAT32_C(   789.78), SIMDE_FLOAT32_C(   498.04), SIMDE_FLOAT32_C(   175.13), SIMDE_FLOAT32_C(  -222.27),
        SIMDE_FLOAT32_C(   143.54), SIMDE_FLOAT32_C(  -291.09), SIMDE_FLOAT32_C(  -409.06), SIMDE_FLOAT32_C(  -949.86),
        SIMDE_FLOAT32_C(  -180.16), SIMDE_FLOAT32_C(  -121.58), SIMDE_FLOAT32_C(  -160.59), SIMDE_FLOAT32_C(  -752.76) } },
    { { SIMDE_FLOAT32_C(    58.09), SIMDE_FLOAT32_C(    20.91), SIMDE_FLOAT32_C(   104.93), SIMDE_FLOAT32_C(   504.70),
        SIMDE_FLOAT32_C(  -677.55), SIMDE_FLOAT32_C(  -105.30), SIMDE_FLOAT32_C(  -320.17), SIMDE_FLOAT32_C(   630.13),
        SIMDE_FLOAT32_C(  -408.78), SIMDE_FLOAT32_C(   823.36), SIMDE_FLOAT32_C(  -778.93), SIMDE_FLOAT32_C(   153.24),
        SIMDE_FLOAT32_C(  -448.97), SIMDE_FLOAT32_C(    40.91), SIMDE_FLOAT32_C(   992.65), SIMDE_FLOAT32_C(   598.78) },
      { SIMDE_FLOAT32_C(   -71.73), SIMDE_FLOAT32_C(   999.22), SIMDE_FLOAT32_C(   181.73), SIMDE_FLOAT32_C(   938.02),
        SIMDE_FLOAT32_C(  -848.71), SIMDE_FLOAT32_C(  -320.23), SIMDE_FLOAT32_C(  -284.25), SIMDE_FLOAT32_C(  -555.18),
        SIMDE_FLOAT32_C(  -727.79), SIMDE_FLOAT32_C(   424.66), SIMDE_FLOAT32_C(  -505.04), SIMDE_FLOAT32_C(  -239.35),
        SIMDE_FLOAT32_C(   592.29), SIMDE_FLOAT32_C(   373.38), SIMDE_FLOAT32_C(     7.89), SIMDE_FLOAT32_C(  -349.61) },
      { SIMDE_FLOAT32_C(   104.93), SIMDE_FLOAT32_C(   181.73), SIMDE_FLOAT32_C(   504.70), SIMDE_FLOAT32_C(   938.02),
        SIMDE_FLOAT32_C(  -320.17), SIMDE_FLOAT32_C(  -284.25), SIMDE_FLOAT32_C(   630.13), SIMDE_FLOAT32_C(  -555.18),
        SIMDE_FLOAT32_C(  -778.93), SIMDE_FLOAT32_C(  -505.04), SIMDE_FLOAT32_C(   153.24), SIMDE_FLOAT32_C(  -239.35),
        SIMDE_FLOAT32_C(   992.65), SIMDE_FLOAT32_C(     7.89), SIMDE_FLOAT32_C(   598.78), SIMDE_FLOAT32_C(  -349.61) } },
    { { SIMDE_FLOAT32_C(  -605.71), SIMDE_FLOAT32_C(  -887.18), SIMDE_FLOAT32_C(  -844.92), SIMDE_FLOAT32_C(  -283.26),
        SIMDE_FLOAT32_C(     7.52), SIMDE_FLOAT32_C(  -165.09), SIMDE_FLOAT32_C(  -653.13), SIMDE_FLOAT32_C(   598.74),
        SIMDE_FLOAT32_C(  -341.73), SIMDE_FLOAT32_C(  -432.06), SIMDE_FLOAT32_C(  -248.02), SIMDE_FLOAT32_C(   209.30),
        SIMDE_FLOAT32_C(   608.85), SIMDE_FLOAT32_C(  -255.36), SIMDE_FLOAT32_C(  -191.92), SIMDE_FLOAT32_C(  -462.88) },
      { SIMDE_FLOAT32_C(  -256.15), SIMDE_FLOAT32_C(   989.81), SIMDE_FLOAT32_C(  -524.85), SIMDE_FLOAT32_C(  -104.86),
        SIMDE_FLOAT32_C(  -330.42), SIMDE_FLOAT32_C(   190.90), SIMDE_FLOAT32_C(   339.96), SIMDE_FLOAT32_C(   -58.21),
        SIMDE_FLOAT32_C(  -384.44), SIMDE_FLOAT32_C(   834.93), SIMDE_FLOAT32_C(   702.44), SIMDE_FLOAT32_C(  -792.14),
        SIMDE_FLOAT32_C(   208.31), SIMDE_FLOAT32_C(  -289.67), SIMDE_FLOAT32_C(  -141.76), SIMDE_FLOAT32_C(   602.60) },
      { SIMDE_FLOAT32_C(  -844.92), SIMDE_FLOAT32_C(  -524.85), SIMDE_FLOAT32_C(  -283.26), SIMDE_FLOAT32_C(  -104.86),
        SIMDE_FLOAT32_C(  -653.13), SIMDE_FLOAT32_C(   339.96), SIMDE_FLOAT32_C(   598.74), SIMDE_FLOAT32_C(   -58.21),
        SIMDE_FLOAT32_C(  -248.02), SIMDE_FLOAT32_C(   702.44), SIMDE_FLOAT32_C(   209.30), SIMDE_FLOAT32_C(  -792.14),
        SIMDE_FLOAT32_C(  -191.92), SIMDE_FLOAT32_C(  -141.76), SIMDE_FLOAT32_C(  -462.88), SIMDE_FLOAT32_C(   602.60) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512 a = simde_mm512_loadu_ps(test_vec[i].a);
    simde__m512 b = simde_mm512_loadu_ps(test_vec[i].b);
    simde__m512 r = simde_mm512_unpackhi_ps(a, b);
    simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[i].r), 1);
  }

  return 0;
}

static int
test_simde_mm512_mask_unpackhi_ps (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const simde_float32 src[16];
    const simde__mmask8 k;
    const simde_float32 a[16];
    const simde_float32 b[16];
    const simde_float32 r[16];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(  -291.23), SIMDE_FLOAT32_C(  -139.21), SIMDE_FLOAT32_C(  -441.81), SIMDE_FLOAT32_C(   845.97),
        SIMDE_FLOAT32_C(   226.47), SIMDE_FLOAT32_C(   261.10), SIMDE_FLOAT32_C(  -120.23), SIMDE_FLOAT32_C(  -359.39),
        SIMDE_FLOAT32_C(   746.86), SIMDE_FLOAT32_C(   235.27), SIMDE_FLOAT32_C(  -137.88), SIMDE_FLOAT32_C(  -417.19),
        SIMDE_FLOAT32_C(  -188.37), SIMDE_FLOAT32_C(  -129.27), SIMDE_FLOAT32_C(   402.91), SIMDE_FLOAT32_C(   826.61) },
      UINT8_C(205),
      { SIMDE_FLOAT32_C(   236.89), SIMDE_FLOAT32_C(  -388.23), SIMDE_FLOAT32_C(   941.34), SIMDE_FLOAT32_C(  -208.36),
        SIMDE_FLOAT32_C(  -307.76), SIMDE_FLOAT32_C(  -934.29), SIMDE_FLOAT32_C(  -828.65), SIMDE_FLOAT32_C(  -292.89),
        SIMDE_FLOAT32_C(   823.73), SIMDE_FLOAT32_C(  -702.66), SIMDE_FLOAT32_C(  -158.41), SIMDE_FLOAT32_C(  -940.13),
        SIMDE_FLOAT32_C(   882.43), SIMDE_FLOAT32_C(   -63.81), SIMDE_FLOAT32_C(  -231.36), SIMDE_FLOAT32_C(  -256.78) },
      { SIMDE_FLOAT32_C(   494.38), SIMDE_FLOAT32_C(  -385.40), SIMDE_FLOAT32_C(   969.69), SIMDE_FLOAT32_C(  -244.52),
        SIMDE_FLOAT32_C(   494.37), SIMDE_FLOAT32_C(  -389.71), SIMDE_FLOAT32_C(  -497.66), SIMDE_FLOAT32_C(  -270.36),
        SIMDE_FLOAT32_C(   472.42), SIMDE_FLOAT32_C(    85.15), SIMDE_FLOAT32_C(   541.28), SIMDE_FLOAT32_C(  -656.85),
        SIMDE_FLOAT32_C(  -511.95), SIMDE_FLOAT32_C(   367.89), SIMDE_FLOAT32_C(   -73.71), SIMDE_FLOAT32_C(   724.95) },
      { SIMDE_FLOAT32_C(   941.34), SIMDE_FLOAT32_C(  -139.21), SIMDE_FLOAT32_C(  -208.36), SIMDE_FLOAT32_C(  -244.52),
        SIMDE_FLOAT32_C(   226.47), SIMDE_FLOAT32_C(   261.10), SIMDE_FLOAT32_C(  -292.89), SIMDE_FLOAT32_C(  -270.36),
        SIMDE_FLOAT32_C(   746.86), SIMDE_FLOAT32_C(   235.27), SIMDE_FLOAT32_C(  -137.88), SIMDE_FLOAT32_C(  -417.19),
        SIMDE_FLOAT32_C(  -188.37), SIMDE_FLOAT32_C(  -129.27), SIMDE_FLOAT32_C(   402.91), SIMDE_FLOAT32_C(   826.61) } },
    { { SIMDE_FLOAT32_C(   979.66), SIMDE_FLOAT32_C(  -132.37), SIMDE_FLOAT32_C(  -483.42), SIMDE_FLOAT32_C(  -328.09),
        SIMDE_FLOAT32_C(   -66.66), SIMDE_FLOAT32_C(  -312.07), SIMDE_FLOAT32_C(   379.02), SIMDE_FLOAT32_C(  -242.93),
        SIMDE_FLOAT32_C(   -14.73), SIMDE_FLOAT32_C(  -779.39), SIMDE_FLOAT32_C(  -183.06), SIMDE_FLOAT32_C(  -132.30),
        SIMDE_FLOAT32_C(   156.80), SIMDE_FLOAT32_C(   585.58), SIMDE_FLOAT32_C(   610.92), SIMDE_FLOAT32_C(  -348.82) },
      UINT8_C(248),
      { SIMDE_FLOAT32_C(   580.60), SIMDE_FLOAT32_C(   406.66), SIMDE_FLOAT32_C(   694.56), SIMDE_FLOAT32_C(  -809.10),
        SIMDE_FLOAT32_C(   908.99), SIMDE_FLOAT32_C(  -575.80), SIMDE_FLOAT32_C(   663.32), SIMDE_FLOAT32_C(    -5.86),
        SIMDE_FLOAT32_C(   965.47), SIMDE_FLOAT32_C(  -993.54), SIMDE_FLOAT32_C(   482.19), SIMDE_FLOAT32_C(   333.36),
        SIMDE_FLOAT32_C(   -67.24), SIMDE_FLOAT32_C(   207.14), SIMDE_FLOAT32_C(   313.03), SIMDE_FLOAT32_C(   800.39) },
      { SIMDE_FLOAT32_C(   723.72), SIMDE_FLOAT32_C(   984.93), SIMDE_FLOAT32_C(  -266.27), SIMDE_FLOAT32_C(  -588.35),
        SIMDE_FLOAT32_C(   363.95), SIMDE_FLOAT32_C(   490.80), SIMDE_FLOAT32_C(   396.93), SIMDE_FLOAT32_C(   584.57),
        SIMDE_FLOAT32_C(  -692.25), SIMDE_FLOAT32_C(  -735.37), SIMDE_FLOAT32_C(  -258.63), SIMDE_FLOAT32_C(   893.33),
        SIMDE_FLOAT32_C(   875.54), SIMDE_FLOAT32_C(   392.54), SIMDE_FLOAT32_C(  -906.49), SIMDE_FLOAT32_C(   456.15) },
      { SIMDE_FLOAT32_C(   979.66), SIMDE_FLOAT32_C(  -132.37), SIMDE_FLOAT32_C(  -483.42), SIMDE_FLOAT32_C(  -588.35),
        SIMDE_FLOAT32_C(   663.32), SIMDE_FLOAT32_C(   396.93), SIMDE_FLOAT32_C(    -5.86), SIMDE_FLOAT32_C(   584.57),
        SIMDE_FLOAT32_C(   -14.73), SIMDE_FLOAT32_C(  -779.39), SIMDE_FLOAT32_C(  -183.06), SIMDE_FLOAT32_C(  -132.30),
        SIMDE_FLOAT32_C(   156.80), SIMDE_FLOAT32_C(   585.58), SIMDE_FLOAT32_C(   610.92), SIMDE_FLOAT32_C(  -348.82) } },
    { { SIMDE_FLOAT32_C(  -200.80), SIMDE_FLOAT32_C(   788.07), SIMDE_FLOAT32_C(   647.05), SIMDE_FLOAT32_C(  -291.81),
        SIMDE_FLOAT32_C(  -787.73), SIMDE_FLOAT32_C(   310.36), SIMDE_FLOAT32_C(   702.33), SIMDE_FLOAT32_C(  -822.26),
        SIMDE_FLOAT32_C(   316.83), SIMDE_FLOAT32_C(   184.52), SIMDE_FLOAT32_C(   511.11), SIMDE_FLOAT32_C(  -750.41),
        SIMDE_FLOAT32_C(  -608.34), SIMDE_FLOAT32_C(  -175.86), SIMDE_FLOAT32_C(  -950.03), SIMDE_FLOAT32_C(  -884.62) },
      UINT8_C(108),
      { SIMDE_FLOAT32_C(  -216.30), SIMDE_FLOAT32_C(  -472.96), SIMDE_FLOAT32_C(  -826.97), SIMDE_FLOAT32_C(  -725.50),
        SIMDE_FLOAT32_C(   923.97), SIMDE_FLOAT32_C(   757.59), SIMDE_FLOAT32_C(  -417.75), SIMDE_FLOAT32_C(  -811.41),
        SIMDE_FLOAT32_C(  -501.04), SIMDE_FLOAT32_C(  -524.42), SIMDE_FLOAT32_C(  -935.86), SIMDE_FLOAT32_C(   891.50),
        SIMDE_FLOAT32_C(  -430.91), SIMDE_FLOAT32_C(   520.29), SIMDE_FLOAT32_C(  -309.30), SIMDE_FLOAT32_C(  -642.84) },
      { SIMDE_FLOAT32_C(   167.33), SIMDE_FLOAT32_C(   398.89), SIMDE_FLOAT32_C(  -430.57), SIMDE_FLOAT32_C(  -522.30),
        SIMDE_FLOAT32_C(   101.22), SIMDE_FLOAT32_C(  -252.83), SIMDE_FLOAT32_C(   794.53), SIMDE_FLOAT32_C(  -714.26),
        SIMDE_FLOAT32_C(  -741.72), SIMDE_FLOAT32_C(  -955.89), SIMDE_FLOAT32_C(  -322.60), SIMDE_FLOAT32_C(    82.42),
        SIMDE_FLOAT32_C(  -905.92), SIMDE_FLOAT32_C(  -207.21), SIMDE_FLOAT32_C(   891.49), SIMDE_FLOAT32_C(  -122.21) },
      { SIMDE_FLOAT32_C(  -200.80), SIMDE_FLOAT32_C(   788.07), SIMDE_FLOAT32_C(  -725.50), SIMDE_FLOAT32_C(  -522.30),
        SIMDE_FLOAT32_C(  -787.73), SIMDE_FLOAT32_C(   794.53), SIMDE_FLOAT32_C(  -811.41), SIMDE_FLOAT32_C(  -822.26),
        SIMDE_FLOAT32_C(   316.83), SIMDE_FLOAT32_C(   184.52), SIMDE_FLOAT32_C(   511.11), SIMDE_FLOAT32_C(  -750.41),
        SIMDE_FLOAT32_C(  -608.34), SIMDE_FLOAT32_C(  -175.86), SIMDE_FLOAT32_C(  -950.03), SIMDE_FLOAT32_C(  -884.62) } },
    { { SIMDE_FLOAT32_C(   319.83), SIMDE_FLOAT32_C(  -935.48), SIMDE_FLOAT32_C(   152.29), SIMDE_FLOAT32_C(   243.79),
        SIMDE_FLOAT32_C(   822.11), SIMDE_FLOAT32_C(   734.54), SIMDE_FLOAT32_C(   432.39), SIMDE_FLOAT32_C(  -678.93),
        SIMDE_FLOAT32_C(  -789.89), SIMDE_FLOAT32_C(   496.52), SIMDE_FLOAT32_C(  -787.43), SIMDE_FLOAT32_C(  -220.80),
        SIMDE_FLOAT32_C(    16.81), SIMDE_FLOAT32_C(   -96.74), SIMDE_FLOAT32_C(   136.36), SIMDE_FLOAT32_C(  -815.85) },
      UINT8_C(254),
      { SIMDE_FLOAT32_C(   705.79), SIMDE_FLOAT32_C(  -338.16), SIMDE_FLOAT32_C(   403.37), SIMDE_FLOAT32_C(  -547.04),
        SIMDE_FLOAT32_C(  -543.63), SIMDE_FLOAT32_C(   689.11), SIMDE_FLOAT32_C(  -288.75), SIMDE_FLOAT32_C(  -499.52),
        SIMDE_FLOAT32_C(  -633.49), SIMDE_FLOAT32_C(   793.66), SIMDE_FLOAT32_C(  -405.44), SIMDE_FLOAT32_C(   159.30),
        SIMDE_FLOAT32_C(   685.15), SIMDE_FLOAT32_C(   472.35), SIMDE_FLOAT32_C(  -520.87), SIMDE_FLOAT32_C(   749.67) },
      { SIMDE_FLOAT32_C(  -375.36), SIMDE_FLOAT32_C(   722.92), SIMDE_FLOAT32_C(   571.78), SIMDE_FLOAT32_C(  -640.83),
        SIMDE_FLOAT32_C(   155.31), SIMDE_FLOAT32_C(   892.85), SIMDE_FLOAT32_C(  -430.72), SIMDE_FLOAT32_C(  -348.16),
        SIMDE_FLOAT32_C(  -894.59), SIMDE_FLOAT32_C(   348.48), SIMDE_FLOAT32_C(   668.65), SIMDE_FLOAT32_C(     8.68),
        SIMDE_FLOAT32_C(  -515.16), SIMDE_FLOAT32_C(   852.79), SIMDE_FLOAT32_C(   310.83), SIMDE_FLOAT32_C(  -809.37) },
      { SIMDE_FLOAT32_C(   319.83), SIMDE_FLOAT32_C(   571.78), SIMDE_FLOAT32_C(  -547.04), SIMDE_FLOAT32_C(  -640.83),
        SIMDE_FLOAT32_C(  -288.75), SIMDE_FLOAT32_C(  -430.72), SIMDE_FLOAT32_C(  -499.52), SIMDE_FLOAT32_C(  -348.16),
        SIMDE_FLOAT32_C(  -789.89), SIMDE_FLOAT32_C(   496.52), SIMDE_FLOAT32_C(  -787.43), SIMDE_FLOAT32_C(  -220.80),
        SIMDE_FLOAT32_C(    16.81), SIMDE_FLOAT32_C(   -96.74), SIMDE_FLOAT32_C(   136.36), SIMDE_FLOAT32_C(  -815.85) } },
    { { SIMDE_FLOAT32_C(  -485.36), SIMDE_FLOAT32_C(  -285.81), SIMDE_FLOAT32_C(  -356.40), SIMDE_FLOAT32_C(   -29.00),
        SIMDE_FLOAT32_C(  -596.70), SIMDE_FLOAT32_C(   354.84), SIMDE_FLOAT32_C(   471.48), SIMDE_FLOAT32_C(  -230.19),
        SIMDE_FLOAT32_C(   148.51), SIMDE_FLOAT32_C(  -933.96), SIMDE_FLOAT32_C(   929.12), SIMDE_FLOAT32_C(  -166.34),
        SIMDE_FLOAT32_C(   538.39), SIMDE_FLOAT32_C(  -591.75), SIMDE_FLOAT32_C(  -416.67), SIMDE_FLOAT32_C(  -836.97) },
      UINT8_C(155),
      { SIMDE_FLOAT32_C(  -844.89), SIMDE_FLOAT32_C(  -477.80), SIMDE_FLOAT32_C(   286.48), SIMDE_FLOAT32_C(  -952.04),
        SIMDE_FLOAT32_C(    91.48), SIMDE_FLOAT32_C(   938.32), SIMDE_FLOAT32_C(  -846.63), SIMDE_FLOAT32_C(  -560.04),
        SIMDE_FLOAT32_C(   606.97), SIMDE_FLOAT32_C(   162.05), SIMDE_FLOAT32_C(   -75.19), SIMDE_FLOAT32_C(   459.76),
        SIMDE_FLOAT32_C(  -527.12), SIMDE_FLOAT32_C(   115.44), SIMDE_FLOAT32_C(   974.40), SIMDE_FLOAT32_C(   187.07) },
      { SIMDE_FLOAT32_C(   759.04), SIMDE_FLOAT32_C(   -54.60), SIMDE_FLOAT32_C(   590.37), SIMDE_FLOAT32_C(   113.88),
        SIMDE_FLOAT32_C(  -583.12), SIMDE_FLOAT32_C(  -639.81), SIMDE_FLOAT32_C(  -737.62), SIMDE_FLOAT32_C(  -517.08),
        SIMDE_FLOAT32_C(  -710.70), SIMDE_FLOAT32_C(    96.05), SIMDE_FLOAT32_C(  -978.69), SIMDE_FLOAT32_C(  -302.45),
        SIMDE_FLOAT32_C(   679.38), SIMDE_FLOAT32_C(  -815.66), SIMDE_FLOAT32_C(  -171.28), SIMDE_FLOAT32_C(   834.49) },
      { SIMDE_FLOAT32_C(   286.48), SIMDE_FLOAT32_C(   590.37), SIMDE_FLOAT32_C(  -356.40), SIMDE_FLOAT32_C(   113.88),
        SIMDE_FLOAT32_C(  -846.63), SIMDE_FLOAT32_C(   354.84), SIMDE_FLOAT32_C(   471.48), SIMDE_FLOAT32_C(  -517.08),
        SIMDE_FLOAT32_C(   148.51), SIMDE_FLOAT32_C(  -933.96), SIMDE_FLOAT32_C(   929.12), SIMDE_FLOAT32_C(  -166.34),
        SIMDE_FLOAT32_C(   538.39), SIMDE_FLOAT32_C(  -591.75), SIMDE_FLOAT32_C(  -416.67), SIMDE_FLOAT32_C(  -836.97) } },
    { { SIMDE_FLOAT32_C(  -293.47), SIMDE_FLOAT32_C(  -884.79), SIMDE_FLOAT32_C(   882.45), SIMDE_FLOAT32_C(   798.01),
        SIMDE_FLOAT32_C(  -946.47), SIMDE_FLOAT32_C(  -964.17), SIMDE_FLOAT32_C(  -762.02), SIMDE_FLOAT32_C(   660.49),
        SIMDE_FLOAT32_C(   197.88), SIMDE_FLOAT32_C(   162.78), SIMDE_FLOAT32_C(   120.25), SIMDE_FLOAT32_C(   670.75),
        SIMDE_FLOAT32_C(  -721.78), SIMDE_FLOAT32_C(    94.65), SIMDE_FLOAT32_C(  -142.18), SIMDE_FLOAT32_C(  -962.74) },
      UINT8_C(128),
      { SIMDE_FLOAT32_C(  -551.81), SIMDE_FLOAT32_C(   151.14), SIMDE_FLOAT32_C(  -543.07), SIMDE_FLOAT32_C(  -191.62),
        SIMDE_FLOAT32_C(   413.52), SIMDE_FLOAT32_C(   -60.15), SIMDE_FLOAT32_C(    97.68), SIMDE_FLOAT32_C(  -490.43),
        SIMDE_FLOAT32_C(   -38.84), SIMDE_FLOAT32_C(   795.24), SIMDE_FLOAT32_C(  -811.05), SIMDE_FLOAT32_C(   145.50),
        SIMDE_FLOAT32_C(  -376.04), SIMDE_FLOAT32_C(  -976.56), SIMDE_FLOAT32_C(   852.03), SIMDE_FLOAT32_C(  -260.84) },
      { SIMDE_FLOAT32_C(   905.89), SIMDE_FLOAT32_C(   650.04), SIMDE_FLOAT32_C(  -207.31), SIMDE_FLOAT32_C(   941.71),
        SIMDE_FLOAT32_C(   888.02), SIMDE_FLOAT32_C(  -546.82), SIMDE_FLOAT32_C(   139.59), SIMDE_FLOAT32_C(    50.80),
        SIMDE_FLOAT32_C(   573.44), SIMDE_FLOAT32_C(  -189.66), SIMDE_FLOAT32_C(   329.03), SIMDE_FLOAT32_C(  -331.91),
        SIMDE_FLOAT32_C(   668.17), SIMDE_FLOAT32_C(   366.29), SIMDE_FLOAT32_C(  -291.87), SIMDE_FLOAT32_C(  -883.64) },
      { SIMDE_FLOAT32_C(  -293.47), SIMDE_FLOAT32_C(  -884.79), SIMDE_FLOAT32_C(   882.45), SIMDE_FLOAT32_C(   798.01),
        SIMDE_FLOAT32_C(  -946.47), SIMDE_FLOAT32_C(  -964.17), SIMDE_FLOAT32_C(  -762.02), SIMDE_FLOAT32_C(    50.80),
        SIMDE_FLOAT32_C(   197.88), SIMDE_FLOAT32_C(   162.78), SIMDE_FLOAT32_C(   120.25), SIMDE_FLOAT32_C(   670.75),
        SIMDE_FLOAT32_C(  -721.78), SIMDE_FLOAT32_C(    94.65), SIMDE_FLOAT32_C(  -142.18), SIMDE_FLOAT32_C(  -962.74) } },
    { { SIMDE_FLOAT32_C(  -482.57), SIMDE_FLOAT32_C(   165.06), SIMDE_FLOAT32_C(   -75.26), SIMDE_FLOAT32_C(   930.95),
        SIMDE_FLOAT32_C(  -895.09), SIMDE_FLOAT32_C(  -977.57), SIMDE_FLOAT32_C(  -559.48), SIMDE_FLOAT32_C(    66.06),
        SIMDE_FLOAT32_C(   817.66), SIMDE_FLOAT32_C(  -370.53), SIMDE_FLOAT32_C(  -788.44), SIMDE_FLOAT32_C(  -558.38),
        SIMDE_FLOAT32_C(  -347.09), SIMDE_FLOAT32_C(  -936.41), SIMDE_FLOAT32_C(   180.79), SIMDE_FLOAT32_C(  -441.20) },
      UINT8_C(109),
      { SIMDE_FLOAT32_C(   973.48), SIMDE_FLOAT32_C(  -499.49), SIMDE_FLOAT32_C(   601.65), SIMDE_FLOAT32_C(  -573.34),
        SIMDE_FLOAT32_C(   640.10), SIMDE_FLOAT32_C(  -347.55), SIMDE_FLOAT32_C(  -999.90), SIMDE_FLOAT32_C(  -549.55),
        SIMDE_FLOAT32_C(   981.48), SIMDE_FLOAT32_C(  -331.82), SIMDE_FLOAT32_C(  -881.39), SIMDE_FLOAT32_C(   347.77),
        SIMDE_FLOAT32_C(   376.32), SIMDE_FLOAT32_C(  -765.03), SIMDE_FLOAT32_C(   865.20), SIMDE_FLOAT32_C(  -458.63) },
      { SIMDE_FLOAT32_C(   159.72), SIMDE_FLOAT32_C(   796.15), SIMDE_FLOAT32_C(  -353.72), SIMDE_FLOAT32_C(   182.14),
        SIMDE_FLOAT32_C(  -763.33), SIMDE_FLOAT32_C(   712.34), SIMDE_FLOAT32_C(    -0.19), SIMDE_FLOAT32_C(  -133.87),
        SIMDE_FLOAT32_C(   923.90), SIMDE_FLOAT32_C(   441.43), SIMDE_FLOAT32_C(   519.04), SIMDE_FLOAT32_C(   987.49),
        SIMDE_FLOAT32_C(  -377.78), SIMDE_FLOAT32_C(  -922.16), SIMDE_FLOAT32_C(   701.12), SIMDE_FLOAT32_C(  -404.31) },
      { SIMDE_FLOAT32_C(   601.65), SIMDE_FLOAT32_C(   165.06), SIMDE_FLOAT32_C(  -573.34), SIMDE_FLOAT32_C(   182.14),
        SIMDE_FLOAT32_C(  -895.09), SIMDE_FLOAT32_C(    -0.19), SIMDE_FLOAT32_C(  -549.55), SIMDE_FLOAT32_C(    66.06),
        SIMDE_FLOAT32_C(   817.66), SIMDE_FLOAT32_C(  -370.53), SIMDE_FLOAT32_C(  -788.44), SIMDE_FLOAT32_C(  -558.38),
        SIMDE_FLOAT32_C(  -347.09), SIMDE_FLOAT32_C(  -936.41), SIMDE_FLOAT32_C(   180.79), SIMDE_FLOAT32_C(  -441.20) } },
    { { SIMDE_FLOAT32_C(  -421.65), SIMDE_FLOAT32_C(   302.77), SIMDE_FLOAT32_C(    22.35), SIMDE_FLOAT32_C(  -781.55),
        SIMDE_FLOAT32_C(   955.22), SIMDE_FLOAT32_C(    22.45), SIMDE_FLOAT32_C(  -331.11), SIMDE_FLOAT32_C(   936.70),
        SIMDE_FLOAT32_C(   690.63), SIMDE_FLOAT32_C(  -212.49), SIMDE_FLOAT32_C(   284.46), SIMDE_FLOAT32_C(    66.95),
        SIMDE_FLOAT32_C(    22.48), SIMDE_FLOAT32_C(   149.66), SIMDE_FLOAT32_C(   608.33), SIMDE_FLOAT32_C(  -817.80) },
      UINT8_C(168),
      { SIMDE_FLOAT32_C(  -745.39), SIMDE_FLOAT32_C(   364.34), SIMDE_FLOAT32_C(   182.47), SIMDE_FLOAT32_C(   966.95),
        SIMDE_FLOAT32_C(  -635.85), SIMDE_FLOAT32_C(  -951.39), SIMDE_FLOAT32_C(   890.85), SIMDE_FLOAT32_C(   805.58),
        SIMDE_FLOAT32_C(   567.65), SIMDE_FLOAT32_C(   878.34), SIMDE_FLOAT32_C(  -572.21), SIMDE_FLOAT32_C(   645.49),
        SIMDE_FLOAT32_C(   579.46), SIMDE_FLOAT32_C(    23.49), SIMDE_FLOAT32_C(  -776.17), SIMDE_FLOAT32_C(  -117.78) },
      { SIMDE_FLOAT32_C(  -954.16), SIMDE_FLOAT32_C(  -557.72), SIMDE_FLOAT32_C(  -162.56), SIMDE_FLOAT32_C(    68.29),
        SIMDE_FLOAT32_C(   111.17), SIMDE_FLOAT32_C(  -225.86), SIMDE_FLOAT32_C(  -241.07), SIMDE_FLOAT32_C(   898.68),
        SIMDE_FLOAT32_C(  -941.40), SIMDE_FLOAT32_C(   825.88), SIMDE_FLOAT32_C(   -78.84), SIMDE_FLOAT32_C(   208.26),
        SIMDE_FLOAT32_C(   434.20), SIMDE_FLOAT32_C(   103.36), SIMDE_FLOAT32_C(  -845.93), SIMDE_FLOAT32_C(   688.81) },
      { SIMDE_FLOAT32_C(  -421.65), SIMDE_FLOAT32_C(   302.77), SIMDE_FLOAT32_C(    22.35), SIMDE_FLOAT32_C(    68.29),
        SIMDE_FLOAT32_C(   955.22), SIMDE_FLOAT32_C(  -241.07), SIMDE_FLOAT32_C(  -331.11), SIMDE_FLOAT32_C(   898.68),
        SIMDE_FLOAT32_C(   690.63), SIMDE_FLOAT32_C(  -212.49), SIMDE_FLOAT32_C(   284.46), SIMDE_FLOAT32_C(    66.95),
        SIMDE_FLOAT32_C(    22.48), SIMDE_FLOAT32_C(   149.66), SIMDE_FLOAT32_C(   608.33), SIMDE_FLOAT32_C(  -817.80) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512 src = simde_mm512_loadu_ps(test_vec[i].src);
    simde__m512 a = simde_mm512_loadu_ps(test_vec[i].a);
    simde__m512 b = simde_mm512_loadu_ps(test_vec[i].b);
    simde__m512 r = simde_mm512_mask_unpackhi_ps(src, test_vec[i].k, a, b);
    simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[i].r), 1);
  }

  return 0;
}

static int
test_simde_mm_maskz_unpackhi_epi64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k;
    const int64_t a[2];
    const int64_t b[2];
    const int64_t r[2];
  } test_vec[] = {
    { UINT8_C( 20),
      {  INT64_C(   39624422618607421),  INT64_C( 8910540124335571998) },
      {  INT64_C( 2024502869291601124),  INT64_C( 1696909119302399997) },
      {  INT64_C(                   0),  INT64_C(                   0) } },
    { UINT8_C( 81),
      {  INT64_C( 8722774794862651689), -INT64_C( 5411359553973223320) },
      {  INT64_C( 1681939568621127903), -INT64_C( 8896850776485146730) },
      { -INT64_C( 5411359553973223320),  INT64_C(                   0) } },
    { UINT8_C(242),
      {  INT64_C(  214731878876869645), -INT64_C( 1567006506939122589) },
      { -INT64_C( 4594196148569597387),  INT64_C(  797032672321566227) },
      {  INT64_C(                   0),  INT64_C(  797032672321566227) } },
    { UINT8_C( 20),
      { -INT64_C( 7729136179897590409), -INT64_C(  588176746068173374) },
      {  INT64_C( 3720158824274362218),  INT64_C( 4789646147477224644) },
      {  INT64_C(                   0),  INT64_C(                   0) } },
    { UINT8_C(219),
      {  INT64_C( 8387680904020204301),  INT64_C( 6721562927915141245) },
      {  INT64_C( 3467295024756806833),  INT64_C(  547538076369191552) },
      {  INT64_C( 6721562927915141245),  INT64_C(  547538076369191552) } },
    { UINT8_C(217),
      {  INT64_C( 1986267837503679500), -INT64_C( 8579260858461688458) },
      { -INT64_C( 1566921267393836430), -INT64_C( 6610742638680932567) },
      { -INT64_C( 8579260858461688458),  INT64_C(                   0) } },
    { UINT8_C(152),
      { -INT64_C( 5436751542006007951),  INT64_C(  471736371877891009) },
      { -INT64_C( 8267384549064946450),  INT64_C( 6828243100698585917) },
      {  INT64_C(                   0),  INT64_C(                   0) } },
    { UINT8_C(130),
      { -INT64_C( 3749389625395153810), -INT64_C( 1673495610541076249) },
      { -INT64_C( 3345889589293817349), -INT64_C( 1479965199753692375) },
      {  INT64_C(                   0), -INT64_C( 1479965199753692375) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_x_mm_loadu_epi64(test_vec[i].a);
    simde__m128i b = simde_x_mm_loadu_epi64(test_vec[i].b);
    simde__m128i r = simde_mm_maskz_unpackhi_epi64(test_vec[i].k, a, b);
    simde_test_x86_assert_equal_i64x2(r, simde_x_mm_loadu_epi64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m128i a = simde_test_x86_random_i64x2();
    simde__m128i b = simde_test_x86_random_i64x2();
    simde__m128i r = simde_mm_maskz_unpackhi_epi64(k, a, b);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i64x2(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_maskz_unpackhi_ps (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const simde__mmask16 k;
    const simde_float32 a[16];
    const simde_float32 b[16];
    const simde_float32 r[16];
  } test_vec[] = {
    { UINT16_C(52453),
      { SIMDE_FLOAT32_C(  -753.67), SIMDE_FLOAT32_C(  -929.72), SIMDE_FLOAT32_C(   958.55), SIMDE_FLOAT32_C(  -635.03),
        SIMDE_FLOAT32_C(   813.44), SIMDE_FLOAT32_C(  -572.90), SIMDE_FLOAT32_C(  -350.63), SIMDE_FLOAT32_C(  -428.42),
        SIMDE_FLOAT32_C(  -919.26), SIMDE_FLOAT32_C(  -171.52), SIMDE_FLOAT32_C(   935.83), SIMDE_FLOAT32_C(   125.81),
        SIMDE_FLOAT32_C(   572.34), SIMDE_FLOAT32_C(  -746.26), SIMDE_FLOAT32_C(   391.38), SIMDE_FLOAT32_C(  -448.91) },
      { SIMDE_FLOAT32_C(   293.95), SIMDE_FLOAT32_C(  -500.41), SIMDE_FLOAT32_C(  -983.39), SIMDE_FLOAT32_C(   919.70),
        SIMDE_FLOAT32_C(  -282.02), SIMDE_FLOAT32_C(   527.32), SIMDE_FLOAT32_C(   354.40), SIMDE_FLOAT32_C(   182.05),
        SIMDE_FLOAT32_C(  -816.83), SIMDE_FLOAT32_C(  -162.74), SIMDE_FLOAT32_C(   223.66), SIMDE_FLOAT32_C(   371.74),
        SIMDE_FLOAT32_C(  -962.96), SIMDE_FLOAT32_C(  -571.14), SIMDE_FLOAT32_C(  -839.06), SIMDE_FLOAT32_C(  -716.63) },
      { SIMDE_FLOAT32_C(   958.55), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -635.03), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   354.40), SIMDE_FLOAT32_C(  -428.42), SIMDE_FLOAT32_C(   182.05),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   125.81), SIMDE_FLOAT32_C(   371.74),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -448.91), SIMDE_FLOAT32_C(  -716.63) } },
    { UINT16_C(19907),
      { SIMDE_FLOAT32_C(  -351.66), SIMDE_FLOAT32_C(  -687.42), SIMDE_FLOAT32_C(  -453.41), SIMDE_FLOAT32_C(   297.70),
        SIMDE_FLOAT32_C(  -115.84), SIMDE_FLOAT32_C(  -372.67), SIMDE_FLOAT32_C(  -873.82), SIMDE_FLOAT32_C(  -180.01),
        SIMDE_FLOAT32_C(   753.15), SIMDE_FLOAT32_C(   698.52), SIMDE_FLOAT32_C(    73.73), SIMDE_FLOAT32_C(   144.52),
        SIMDE_FLOAT32_C(  -750.38), SIMDE_FLOAT32_C(  -632.32), SIMDE_FLOAT32_C(   644.11), SIMDE_FLOAT32_C(  -733.77) },
      { SIMDE_FLOAT32_C(  -712.62), SIMDE_FLOAT32_C(  -637.91), SIMDE_FLOAT32_C(   793.55), SIMDE_FLOAT32_C(   641.79),
        SIMDE_FLOAT32_C(   544.14), SIMDE_FLOAT32_C(   976.71), SIMDE_FLOAT32_C(  -520.96), SIMDE_FLOAT32_C(  -232.20),
        SIMDE_FLOAT32_C(   348.45), SIMDE_FLOAT32_C(  -483.91), SIMDE_FLOAT32_C(   196.65), SIMDE_FLOAT32_C(   509.39),
        SIMDE_FLOAT32_C(  -200.54), SIMDE_FLOAT32_C(   695.80), SIMDE_FLOAT32_C(   628.88), SIMDE_FLOAT32_C(   447.80) },
      { SIMDE_FLOAT32_C(  -453.41), SIMDE_FLOAT32_C(   793.55), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -180.01), SIMDE_FLOAT32_C(  -232.20),
        SIMDE_FLOAT32_C(    73.73), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   144.52), SIMDE_FLOAT32_C(   509.39),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -733.77), SIMDE_FLOAT32_C(     0.00) } },
    { UINT16_C(11533),
      { SIMDE_FLOAT32_C(  -254.50), SIMDE_FLOAT32_C(  -107.46), SIMDE_FLOAT32_C(  -197.20), SIMDE_FLOAT32_C(  -128.31),
        SIMDE_FLOAT32_C(   712.53), SIMDE_FLOAT32_C(  -444.05), SIMDE_FLOAT32_C(  -429.79), SIMDE_FLOAT32_C(  -213.73),
        SIMDE_FLOAT32_C(   700.47), SIMDE_FLOAT32_C(  -180.18), SIMDE_FLOAT32_C(   153.95), SIMDE_FLOAT32_C(   344.58),
        SIMDE_FLOAT32_C(    86.05), SIMDE_FLOAT32_C(   441.33), SIMDE_FLOAT32_C(   706.67), SIMDE_FLOAT32_C(  -120.40) },
      { SIMDE_FLOAT32_C(    83.12), SIMDE_FLOAT32_C(   250.82), SIMDE_FLOAT32_C(  -143.69), SIMDE_FLOAT32_C(   562.16),
        SIMDE_FLOAT32_C(  -981.39), SIMDE_FLOAT32_C(  -795.24), SIMDE_FLOAT32_C(  -921.75), SIMDE_FLOAT32_C(   215.27),
        SIMDE_FLOAT32_C(   714.16), SIMDE_FLOAT32_C(  -122.29), SIMDE_FLOAT32_C(   -88.94), SIMDE_FLOAT32_C(   343.04),
        SIMDE_FLOAT32_C(  -674.50), SIMDE_FLOAT32_C(   -80.56), SIMDE_FLOAT32_C(   518.51), SIMDE_FLOAT32_C(    71.00) },
      { SIMDE_FLOAT32_C(  -197.20), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -128.31), SIMDE_FLOAT32_C(   562.16),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(   153.95), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   344.58), SIMDE_FLOAT32_C(   343.04),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   518.51), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
    { UINT16_C(60827),
      { SIMDE_FLOAT32_C(   942.69), SIMDE_FLOAT32_C(   524.51), SIMDE_FLOAT32_C(  -122.74), SIMDE_FLOAT32_C(  -487.10),
        SIMDE_FLOAT32_C(  -689.22), SIMDE_FLOAT32_C(  -422.26), SIMDE_FLOAT32_C(   332.72), SIMDE_FLOAT32_C(   464.73),
        SIMDE_FLOAT32_C(   922.32), SIMDE_FLOAT32_C(  -581.23), SIMDE_FLOAT32_C(   -93.94), SIMDE_FLOAT32_C(   629.00),
        SIMDE_FLOAT32_C(   298.37), SIMDE_FLOAT32_C(   989.17), SIMDE_FLOAT32_C(  -120.19), SIMDE_FLOAT32_C(  -845.32) },
      { SIMDE_FLOAT32_C(   551.34), SIMDE_FLOAT32_C(  -101.58), SIMDE_FLOAT32_C(  -640.56), SIMDE_FLOAT32_C(   629.58),
        SIMDE_FLOAT32_C(  -886.31), SIMDE_FLOAT32_C(  -926.40), SIMDE_FLOAT32_C(  -492.71), SIMDE_FLOAT32_C(    24.75),
        SIMDE_FLOAT32_C(   416.64), SIMDE_FLOAT32_C(  -167.21), SIMDE_FLOAT32_C(   944.19), SIMDE_FLOAT32_C(   -64.86),
        SIMDE_FLOAT32_C(   903.79), SIMDE_FLOAT32_C(   756.16), SIMDE_FLOAT32_C(   256.46), SIMDE_FLOAT32_C(   846.48) },
      { SIMDE_FLOAT32_C(  -122.74), SIMDE_FLOAT32_C(  -640.56), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   629.58),
        SIMDE_FLOAT32_C(   332.72), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(    24.75),
        SIMDE_FLOAT32_C(   -93.94), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   629.00), SIMDE_FLOAT32_C(   -64.86),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   256.46), SIMDE_FLOAT32_C(  -845.32), SIMDE_FLOAT32_C(   846.48) } },
    { UINT16_C( 9611),
      { SIMDE_FLOAT32_C(  -640.62), SIMDE_FLOAT32_C(   591.45), SIMDE_FLOAT32_C(  -288.54), SIMDE_FLOAT32_C(   692.10),
        SIMDE_FLOAT32_C(    56.18), SIMDE_FLOAT32_C(  -366.22), SIMDE_FLOAT32_C(  -889.14), SIMDE_FLOAT32_C(   962.24),
        SIMDE_FLOAT32_C(  -737.23), SIMDE_FLOAT32_C(   409.23), SIMDE_FLOAT32_C(   951.41), SIMDE_FLOAT32_C(   142.58),
        SIMDE_FLOAT32_C(   563.90), SIMDE_FLOAT32_C(   502.75), SIMDE_FLOAT32_C(  -959.00), SIMDE_FLOAT32_C(   923.35) },
      { SIMDE_FLOAT32_C(   132.33), SIMDE_FLOAT32_C(  -845.31), SIMDE_FLOAT32_C(   996.94), SIMDE_FLOAT32_C(   639.62),
        SIMDE_FLOAT32_C(   179.44), SIMDE_FLOAT32_C(   413.58), SIMDE_FLOAT32_C(  -527.59), SIMDE_FLOAT32_C(   123.63),
        SIMDE_FLOAT32_C(  -651.28), SIMDE_FLOAT32_C(  -623.79), SIMDE_FLOAT32_C(  -120.21), SIMDE_FLOAT32_C(   605.18),
        SIMDE_FLOAT32_C(  -777.31), SIMDE_FLOAT32_C(  -839.53), SIMDE_FLOAT32_C(   738.90), SIMDE_FLOAT32_C(  -417.93) },
      { SIMDE_FLOAT32_C(  -288.54), SIMDE_FLOAT32_C(   996.94), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   639.62),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   123.63),
        SIMDE_FLOAT32_C(   951.41), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   142.58), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   738.90), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
    { UINT16_C(47427),
      { SIMDE_FLOAT32_C(  -725.84), SIMDE_FLOAT32_C(  -191.90), SIMDE_FLOAT32_C(    84.13), SIMDE_FLOAT32_C(  -614.97),
        SIMDE_FLOAT32_C(  -229.66), SIMDE_FLOAT32_C(   346.90), SIMDE_FLOAT32_C(   794.26), SIMDE_FLOAT32_C(  -278.25),
        SIMDE_FLOAT32_C(  -510.51), SIMDE_FLOAT32_C(   358.16), SIMDE_FLOAT32_C(  -775.50), SIMDE_FLOAT32_C(  -469.51),
        SIMDE_FLOAT32_C(   281.51), SIMDE_FLOAT32_C(   356.83), SIMDE_FLOAT32_C(  -314.82), SIMDE_FLOAT32_C(   278.45) },
      { SIMDE_FLOAT32_C(    -3.55), SIMDE_FLOAT32_C(   864.62), SIMDE_FLOAT32_C(  -307.97), SIMDE_FLOAT32_C(   468.87),
        SIMDE_FLOAT32_C(   -11.75), SIMDE_FLOAT32_C(    40.75), SIMDE_FLOAT32_C(   845.07), SIMDE_FLOAT32_C(   868.04),
        SIMDE_FLOAT32_C(  -354.07), SIMDE_FLOAT32_C(  -932.24), SIMDE_FLOAT32_C(  -971.49), SIMDE_FLOAT32_C(  -615.17),
        SIMDE_FLOAT32_C(  -350.17), SIMDE_FLOAT32_C(   780.43), SIMDE_FLOAT32_C(  -164.81), SIMDE_FLOAT32_C(   -76.00) },
      { SIMDE_FLOAT32_C(    84.13), SIMDE_FLOAT32_C(  -307.97), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -278.25), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(  -775.50), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -615.17),
        SIMDE_FLOAT32_C(  -314.82), SIMDE_FLOAT32_C(  -164.81), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   -76.00) } },
    { UINT16_C(61115),
      { SIMDE_FLOAT32_C(   309.02), SIMDE_FLOAT32_C(   358.87), SIMDE_FLOAT32_C(   266.23), SIMDE_FLOAT32_C(   103.28),
        SIMDE_FLOAT32_C(  -919.38), SIMDE_FLOAT32_C(   755.71), SIMDE_FLOAT32_C(  -538.56), SIMDE_FLOAT32_C(  -694.88),
        SIMDE_FLOAT32_C(  -713.79), SIMDE_FLOAT32_C(   742.95), SIMDE_FLOAT32_C(   661.95), SIMDE_FLOAT32_C(   -28.61),
        SIMDE_FLOAT32_C(    21.40), SIMDE_FLOAT32_C(  -341.60), SIMDE_FLOAT32_C(  -163.99), SIMDE_FLOAT32_C(   713.43) },
      { SIMDE_FLOAT32_C(  -872.73), SIMDE_FLOAT32_C(   824.26), SIMDE_FLOAT32_C(  -245.82), SIMDE_FLOAT32_C(   972.34),
        SIMDE_FLOAT32_C(   692.31), SIMDE_FLOAT32_C(   400.12), SIMDE_FLOAT32_C(  -959.90), SIMDE_FLOAT32_C(   720.81),
        SIMDE_FLOAT32_C(   784.95), SIMDE_FLOAT32_C(  -310.06), SIMDE_FLOAT32_C(   501.24), SIMDE_FLOAT32_C(  -379.86),
        SIMDE_FLOAT32_C(   613.93), SIMDE_FLOAT32_C(  -910.23), SIMDE_FLOAT32_C(  -460.54), SIMDE_FLOAT32_C(   -77.04) },
      { SIMDE_FLOAT32_C(   266.23), SIMDE_FLOAT32_C(  -245.82), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   972.34),
        SIMDE_FLOAT32_C(  -538.56), SIMDE_FLOAT32_C(  -959.90), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   720.81),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   501.24), SIMDE_FLOAT32_C(   -28.61), SIMDE_FLOAT32_C(  -379.86),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -460.54), SIMDE_FLOAT32_C(   713.43), SIMDE_FLOAT32_C(   -77.04) } },
    { UINT16_C(43528),
      { SIMDE_FLOAT32_C(  -973.76), SIMDE_FLOAT32_C(   529.26), SIMDE_FLOAT32_C(   561.40), SIMDE_FLOAT32_C(  -512.32),
        SIMDE_FLOAT32_C(   834.38), SIMDE_FLOAT32_C(   847.61), SIMDE_FLOAT32_C(  -769.38), SIMDE_FLOAT32_C(   496.33),
        SIMDE_FLOAT32_C(  -181.01), SIMDE_FLOAT32_C(   252.02), SIMDE_FLOAT32_C(  -845.27), SIMDE_FLOAT32_C(   655.01),
        SIMDE_FLOAT32_C(   -34.55), SIMDE_FLOAT32_C(  -718.00), SIMDE_FLOAT32_C(   479.27), SIMDE_FLOAT32_C(   719.63) },
      { SIMDE_FLOAT32_C(  -745.66), SIMDE_FLOAT32_C(   171.58), SIMDE_FLOAT32_C(   119.74), SIMDE_FLOAT32_C(  -705.55),
        SIMDE_FLOAT32_C(  -107.61), SIMDE_FLOAT32_C(   -95.31), SIMDE_FLOAT32_C(   -15.62), SIMDE_FLOAT32_C(  -606.37),
        SIMDE_FLOAT32_C(   524.83), SIMDE_FLOAT32_C(  -401.68), SIMDE_FLOAT32_C(  -516.59), SIMDE_FLOAT32_C(  -935.71),
        SIMDE_FLOAT32_C(   521.28), SIMDE_FLOAT32_C(   932.05), SIMDE_FLOAT32_C(   869.98), SIMDE_FLOAT32_C(   547.51) },
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -705.55),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -516.59), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -935.71),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   869.98), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   547.51) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512 a = simde_mm512_loadu_ps(test_vec[i].a);
    simde__m512 b = simde_mm512_loadu_ps(test_vec[i].b);
    simde__m512 r = simde_mm512_maskz_unpackhi_ps(test_vec[i].k, a, b);
    simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[i].r), 1);
  }

  return 0;
}

static int
test_simde_mm256_mask_unpackhi_ps (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde_float32 src[8];
    const simde__mmask8 k;
    const simde_float32 a[8];
    const simde_float32 b[8];
    const simde_float32 r[8];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(  -609.06), SIMDE_FLOAT32_C(  -517.72), SIMDE_FLOAT32_C(    52.37), SIMDE_FLOAT32_C(   -94.90),
        SIMDE_FLOAT32_C(  -166.92), SIMDE_FLOAT32_C(   142.16), SIMDE_FLOAT32_C(   366.27), SIMDE_FLOAT32_C(   280.27) },
      UINT8_C(175),
      { SIMDE_FLOAT32_C(   816.50), SIMDE_FLOAT32_C(   931.79), SIMDE_FLOAT32_C(  -218.05), SIMDE_FLOAT32_C(   741.32),
        SIMDE_FLOAT32_C(   316.79), SIMDE_FLOAT32_C(  -866.65), SIMDE_FLOAT32_C(   108.34), SIMDE_FLOAT32_C(   319.03) },
      { SIMDE_FLOAT32_C(   335.50), SIMDE_FLOAT32_C(   -14.82), SIMDE_FLOAT32_C(  -702.39), SIMDE_FLOAT32_C(   404.47),
        SIMDE_FLOAT32_C(  -756.92), SIMDE_FLOAT32_C(   902.57), SIMDE_FLOAT32_C(    -7.46), SIMDE_FLOAT32_C(   563.11) },
      { SIMDE_FLOAT32_C(  -218.05), SIMDE_FLOAT32_C(  -702.39), SIMDE_FLOAT32_C(   741.32), SIMDE_FLOAT32_C(   404.47),
        SIMDE_FLOAT32_C(  -166.92), SIMDE_FLOAT32_C(    -7.46), SIMDE_FLOAT32_C(   366.27), SIMDE_FLOAT32_C(   563.11) } },
    { { SIMDE_FLOAT32_C(  -610.55), SIMDE_FLOAT32_C(  -111.00), SIMDE_FLOAT32_C(  -321.17), SIMDE_FLOAT32_C(  -646.68),
        SIMDE_FLOAT32_C(   128.38), SIMDE_FLOAT32_C(   975.91), SIMDE_FLOAT32_C(  -255.74), SIMDE_FLOAT32_C(   610.66) },
      UINT8_C( 14),
      { SIMDE_FLOAT32_C(   649.36), SIMDE_FLOAT32_C(  -556.27), SIMDE_FLOAT32_C(  -829.57), SIMDE_FLOAT32_C(    15.63),
        SIMDE_FLOAT32_C(   724.01), SIMDE_FLOAT32_C(   453.23), SIMDE_FLOAT32_C(  -167.87), SIMDE_FLOAT32_C(   655.80) },
      { SIMDE_FLOAT32_C(  -764.82), SIMDE_FLOAT32_C(  -426.55), SIMDE_FLOAT32_C(   -27.41), SIMDE_FLOAT32_C(  -631.47),
        SIMDE_FLOAT32_C(   681.79), SIMDE_FLOAT32_C(  -708.39), SIMDE_FLOAT32_C(   704.02), SIMDE_FLOAT32_C(  -333.03) },
      { SIMDE_FLOAT32_C(  -610.55), SIMDE_FLOAT32_C(   -27.41), SIMDE_FLOAT32_C(    15.63), SIMDE_FLOAT32_C(  -631.47),
        SIMDE_FLOAT32_C(   128.38), SIMDE_FLOAT32_C(   975.91), SIMDE_FLOAT32_C(  -255.74), SIMDE_FLOAT32_C(   610.66) } },
    { { SIMDE_FLOAT32_C(  -410.78), SIMDE_FLOAT32_C(   108.50), SIMDE_FLOAT32_C(   -89.95), SIMDE_FLOAT32_C(  -508.21),
        SIMDE_FLOAT32_C(  -898.96), SIMDE_FLOAT32_C(  -526.84), SIMDE_FLOAT32_C(  -118.75), SIMDE_FLOAT32_C(    -9.96) },
      UINT8_C(169),
      { SIMDE_FLOAT32_C(   234.56), SIMDE_FLOAT32_C(  -881.58), SIMDE_FLOAT32_C(   127.90), SIMDE_FLOAT32_C(   978.82),
        SIMDE_FLOAT32_C(   729.08), SIMDE_FLOAT32_C(  -843.83), SIMDE_FLOAT32_C(   628.18), SIMDE_FLOAT32_C(  -827.18) },
      { SIMDE_FLOAT32_C(  -673.39), SIMDE_FLOAT32_C(  -356.19), SIMDE_FLOAT32_C(   896.82), SIMDE_FLOAT32_C(   779.83),
        SIMDE_FLOAT32_C(   475.93), SIMDE_FLOAT32_C(   552.62), SIMDE_FLOAT32_C(  -984.99), SIMDE_FLOAT32_C(  -950.62) },
      { SIMDE_FLOAT32_C(   127.90), SIMDE_FLOAT32_C(   108.50), SIMDE_FLOAT32_C(   -89.95), SIMDE_FLOAT32_C(   779.83),
        SIMDE_FLOAT32_C(  -898.96), SIMDE_FLOAT32_C(  -984.99), SIMDE_FLOAT32_C(  -118.75), SIMDE_FLOAT32_C(  -950.62) } },
    { { SIMDE_FLOAT32_C(  -474.79), SIMDE_FLOAT32_C(  -616.46), SIMDE_FLOAT32_C(   731.17), SIMDE_FLOAT32_C(  -183.17),
        SIMDE_FLOAT32_C(  -912.43), SIMDE_FLOAT32_C(  -601.86), SIMDE_FLOAT32_C(   406.05), SIMDE_FLOAT32_C(   196.06) },
      UINT8_C(189),
      { SIMDE_FLOAT32_C(   897.84), SIMDE_FLOAT32_C(   297.10), SIMDE_FLOAT32_C(   781.34), SIMDE_FLOAT32_C(  -220.91),
        SIMDE_FLOAT32_C(  -712.86), SIMDE_FLOAT32_C(   -66.67), SIMDE_FLOAT32_C(  -986.35), SIMDE_FLOAT32_C(  -594.44) },
      { SIMDE_FLOAT32_C(  -938.78), SIMDE_FLOAT32_C(   992.47), SIMDE_FLOAT32_C(  -865.36), SIMDE_FLOAT32_C(  -782.60),
        SIMDE_FLOAT32_C(   620.65), SIMDE_FLOAT32_C(  -692.54), SIMDE_FLOAT32_C(  -456.00), SIMDE_FLOAT32_C(  -735.54) },
      { SIMDE_FLOAT32_C(   781.34), SIMDE_FLOAT32_C(  -616.46), SIMDE_FLOAT32_C(  -220.91), SIMDE_FLOAT32_C(  -782.60),
        SIMDE_FLOAT32_C(  -986.35), SIMDE_FLOAT32_C(  -456.00), SIMDE_FLOAT32_C(   406.05), SIMDE_FLOAT32_C(  -735.54) } },
    { { SIMDE_FLOAT32_C(  -795.72), SIMDE_FLOAT32_C(  -676.16), SIMDE_FLOAT32_C(   740.39), SIMDE_FLOAT32_C(   756.91),
        SIMDE_FLOAT32_C(  -661.15), SIMDE_FLOAT32_C(   789.77), SIMDE_FLOAT32_C(  -717.88), SIMDE_FLOAT32_C(  -277.60) },
      UINT8_C(184),
      { SIMDE_FLOAT32_C(    98.95), SIMDE_FLOAT32_C(  -190.04), SIMDE_FLOAT32_C(   919.07), SIMDE_FLOAT32_C(  -495.00),
        SIMDE_FLOAT32_C(  -993.97), SIMDE_FLOAT32_C(   227.26), SIMDE_FLOAT32_C(  -597.16), SIMDE_FLOAT32_C(   303.13) },
      { SIMDE_FLOAT32_C(     8.59), SIMDE_FLOAT32_C(   181.93), SIMDE_FLOAT32_C(   590.27), SIMDE_FLOAT32_C(   941.92),
        SIMDE_FLOAT32_C(   195.58), SIMDE_FLOAT32_C(   995.83), SIMDE_FLOAT32_C(  -996.85), SIMDE_FLOAT32_C(   188.06) },
      { SIMDE_FLOAT32_C(  -795.72), SIMDE_FLOAT32_C(  -676.16), SIMDE_FLOAT32_C(   740.39), SIMDE_FLOAT32_C(   941.92),
        SIMDE_FLOAT32_C(  -597.16), SIMDE_FLOAT32_C(  -996.85), SIMDE_FLOAT32_C(  -717.88), SIMDE_FLOAT32_C(   188.06) } },
    { { SIMDE_FLOAT32_C(  -869.52), SIMDE_FLOAT32_C(  -779.46), SIMDE_FLOAT32_C(  -191.29), SIMDE_FLOAT32_C(  -562.06),
        SIMDE_FLOAT32_C(  -235.45), SIMDE_FLOAT32_C(    73.16), SIMDE_FLOAT32_C(  -357.78), SIMDE_FLOAT32_C(    88.38) },
      UINT8_C(131),
      { SIMDE_FLOAT32_C(  -600.87), SIMDE_FLOAT32_C(   427.24), SIMDE_FLOAT32_C(  -396.67), SIMDE_FLOAT32_C(  -318.75),
        SIMDE_FLOAT32_C(  -850.37), SIMDE_FLOAT32_C(  -875.73), SIMDE_FLOAT32_C(   780.20), SIMDE_FLOAT32_C(   -40.40) },
      { SIMDE_FLOAT32_C(  -956.66), SIMDE_FLOAT32_C(  -714.81), SIMDE_FLOAT32_C(   -34.38), SIMDE_FLOAT32_C(   270.60),
        SIMDE_FLOAT32_C(  -311.97), SIMDE_FLOAT32_C(  -731.25), SIMDE_FLOAT32_C(  -720.81), SIMDE_FLOAT32_C(   869.96) },
      { SIMDE_FLOAT32_C(  -396.67), SIMDE_FLOAT32_C(   -34.38), SIMDE_FLOAT32_C(  -191.29), SIMDE_FLOAT32_C(  -562.06),
        SIMDE_FLOAT32_C(  -235.45), SIMDE_FLOAT32_C(    73.16), SIMDE_FLOAT32_C(  -357.78), SIMDE_FLOAT32_C(   869.96) } },
    { { SIMDE_FLOAT32_C(   859.02), SIMDE_FLOAT32_C(  -778.89), SIMDE_FLOAT32_C(    65.55), SIMDE_FLOAT32_C(   854.86),
        SIMDE_FLOAT32_C(  -775.74), SIMDE_FLOAT32_C(  -746.40), SIMDE_FLOAT32_C(   985.33), SIMDE_FLOAT32_C(  -555.20) },
      UINT8_C(217),
      { SIMDE_FLOAT32_C(  -576.73), SIMDE_FLOAT32_C(   209.35), SIMDE_FLOAT32_C(  -864.53), SIMDE_FLOAT32_C(    65.49),
        SIMDE_FLOAT32_C(  -702.27), SIMDE_FLOAT32_C(   -50.97), SIMDE_FLOAT32_C(   464.62), SIMDE_FLOAT32_C(   724.97) },
      { SIMDE_FLOAT32_C(   552.36), SIMDE_FLOAT32_C(  -854.13), SIMDE_FLOAT32_C(   874.60), SIMDE_FLOAT32_C(   676.63),
        SIMDE_FLOAT32_C(   926.07), SIMDE_FLOAT32_C(  -165.80), SIMDE_FLOAT32_C(   719.97), SIMDE_FLOAT32_C(  -788.74) },
      { SIMDE_FLOAT32_C(  -864.53), SIMDE_FLOAT32_C(  -778.89), SIMDE_FLOAT32_C(    65.55), SIMDE_FLOAT32_C(   676.63),
        SIMDE_FLOAT32_C(   464.62), SIMDE_FLOAT32_C(  -746.40), SIMDE_FLOAT32_C(   724.97), SIMDE_FLOAT32_C(  -788.74) } },
    { { SIMDE_FLOAT32_C(   799.82), SIMDE_FLOAT32_C(    -9.43), SIMDE_FLOAT32_C(  -100.71), SIMDE_FLOAT32_C(  -931.43),
        SIMDE_FLOAT32_C(   269.76), SIMDE_FLOAT32_C(  -230.75), SIMDE_FLOAT32_C(   927.59), SIMDE_FLOAT32_C(   490.88) },
      UINT8_C(  5),
      { SIMDE_FLOAT32_C(   782.45), SIMDE_FLOAT32_C(   715.14), SIMDE_FLOAT32_C(  -911.60), SIMDE_FLOAT32_C(   767.78),
        SIMDE_FLOAT32_C(  -840.06), SIMDE_FLOAT32_C(   150.71), SIMDE_FLOAT32_C(  -808.94), SIMDE_FLOAT32_C(   369.28) },
      { SIMDE_FLOAT32_C(   286.18), SIMDE_FLOAT32_C(   256.55), SIMDE_FLOAT32_C(   667.01), SIMDE_FLOAT32_C(  -764.78),
        SIMDE_FLOAT32_C(  -278.83), SIMDE_FLOAT32_C(   391.98), SIMDE_FLOAT32_C(   787.58), SIMDE_FLOAT32_C(  -132.95) },
      { SIMDE_FLOAT32_C(  -911.60), SIMDE_FLOAT32_C(    -9.43), SIMDE_FLOAT32_C(   767.78), SIMDE_FLOAT32_C(  -931.43),
        SIMDE_FLOAT32_C(   269.76), SIMDE_FLOAT32_C(  -230.75), SIMDE_FLOAT32_C(   927.59), SIMDE_FLOAT32_C(   490.88) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256 src = simde_mm256_loadu_ps(test_vec[i].src);
    simde__mmask8 k = test_vec[i].k;
    simde__m256 a = simde_mm256_loadu_ps(test_vec[i].a);
    simde__m256 b = simde_mm256_loadu_ps(test_vec[i].b);
    simde__m256 r = simde_mm256_mask_unpackhi_ps(src, k, a, b);
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
    simde__m256 r = simde_mm256_mask_unpackhi_ps(src, k, a, b);

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
test_simde_mm256_maskz_unpackhi_ps (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k;
    const simde_float32 a[8];
    const simde_float32 b[8];
    const simde_float32 r[8];
  } test_vec[] = {
    { UINT8_C(196),
      { SIMDE_FLOAT32_C(   655.34), SIMDE_FLOAT32_C(   919.48), SIMDE_FLOAT32_C(   718.32), SIMDE_FLOAT32_C(  -876.29),
        SIMDE_FLOAT32_C(  -543.16), SIMDE_FLOAT32_C(   -96.55), SIMDE_FLOAT32_C(   799.15), SIMDE_FLOAT32_C(  -748.40) },
      { SIMDE_FLOAT32_C(  -286.05), SIMDE_FLOAT32_C(  -240.79), SIMDE_FLOAT32_C(  -289.17), SIMDE_FLOAT32_C(   484.88),
        SIMDE_FLOAT32_C(   228.39), SIMDE_FLOAT32_C(  -464.19), SIMDE_FLOAT32_C(  -646.47), SIMDE_FLOAT32_C(   731.51) },
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -876.29), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -748.40), SIMDE_FLOAT32_C(   731.51) } },
    { UINT8_C( 56),
      { SIMDE_FLOAT32_C(   -30.30), SIMDE_FLOAT32_C(   765.63), SIMDE_FLOAT32_C(   915.68), SIMDE_FLOAT32_C(  -212.96),
        SIMDE_FLOAT32_C(  -833.05), SIMDE_FLOAT32_C(   245.31), SIMDE_FLOAT32_C(  -344.94), SIMDE_FLOAT32_C(   262.97) },
      { SIMDE_FLOAT32_C(   100.31), SIMDE_FLOAT32_C(   533.22), SIMDE_FLOAT32_C(   214.69), SIMDE_FLOAT32_C(   744.91),
        SIMDE_FLOAT32_C(   -55.13), SIMDE_FLOAT32_C(   604.78), SIMDE_FLOAT32_C(   400.25), SIMDE_FLOAT32_C(  -135.65) },
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   744.91),
        SIMDE_FLOAT32_C(  -344.94), SIMDE_FLOAT32_C(   400.25), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
    { UINT8_C( 18),
      { SIMDE_FLOAT32_C(   523.96), SIMDE_FLOAT32_C(   321.19), SIMDE_FLOAT32_C(  -773.45), SIMDE_FLOAT32_C(   323.11),
        SIMDE_FLOAT32_C(   572.79), SIMDE_FLOAT32_C(   -59.50), SIMDE_FLOAT32_C(  -917.68), SIMDE_FLOAT32_C(  -716.38) },
      { SIMDE_FLOAT32_C(  -574.62), SIMDE_FLOAT32_C(   310.70), SIMDE_FLOAT32_C(  -180.57), SIMDE_FLOAT32_C(  -221.09),
        SIMDE_FLOAT32_C(    42.21), SIMDE_FLOAT32_C(  -186.39), SIMDE_FLOAT32_C(   748.61), SIMDE_FLOAT32_C(  -192.16) },
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -180.57), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(  -917.68), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
    { UINT8_C(163),
      { SIMDE_FLOAT32_C(  -464.34), SIMDE_FLOAT32_C(   -25.20), SIMDE_FLOAT32_C(   974.59), SIMDE_FLOAT32_C(   190.71),
        SIMDE_FLOAT32_C(  -762.23), SIMDE_FLOAT32_C(    74.90), SIMDE_FLOAT32_C(  -276.07), SIMDE_FLOAT32_C(   452.46) },
      { SIMDE_FLOAT32_C(  -180.19), SIMDE_FLOAT32_C(   668.80), SIMDE_FLOAT32_C(    57.24), SIMDE_FLOAT32_C(  -779.95),
        SIMDE_FLOAT32_C(  -466.85), SIMDE_FLOAT32_C(  -619.66), SIMDE_FLOAT32_C(   744.01), SIMDE_FLOAT32_C(   854.34) },
      { SIMDE_FLOAT32_C(   974.59), SIMDE_FLOAT32_C(    57.24), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   744.01), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   854.34) } },
    { UINT8_C( 73),
      { SIMDE_FLOAT32_C(    67.12), SIMDE_FLOAT32_C(   427.12), SIMDE_FLOAT32_C(   547.39), SIMDE_FLOAT32_C(   149.44),
        SIMDE_FLOAT32_C(   710.74), SIMDE_FLOAT32_C(   972.77), SIMDE_FLOAT32_C(  -539.86), SIMDE_FLOAT32_C(  -469.83) },
      { SIMDE_FLOAT32_C(  -248.32), SIMDE_FLOAT32_C(   502.35), SIMDE_FLOAT32_C(   343.78), SIMDE_FLOAT32_C(  -499.71),
        SIMDE_FLOAT32_C(  -689.80), SIMDE_FLOAT32_C(  -926.93), SIMDE_FLOAT32_C(    35.95), SIMDE_FLOAT32_C(   285.00) },
      { SIMDE_FLOAT32_C(   547.39), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -499.71),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -469.83), SIMDE_FLOAT32_C(     0.00) } },
    { UINT8_C(215),
      { SIMDE_FLOAT32_C(  -773.34), SIMDE_FLOAT32_C(   522.76), SIMDE_FLOAT32_C(   122.56), SIMDE_FLOAT32_C(   -49.41),
        SIMDE_FLOAT32_C(   -24.78), SIMDE_FLOAT32_C(   942.36), SIMDE_FLOAT32_C(  -380.61), SIMDE_FLOAT32_C(  -967.54) },
      { SIMDE_FLOAT32_C(  -837.58), SIMDE_FLOAT32_C(   152.54), SIMDE_FLOAT32_C(  -587.20), SIMDE_FLOAT32_C(   906.43),
        SIMDE_FLOAT32_C(     6.87), SIMDE_FLOAT32_C(    19.70), SIMDE_FLOAT32_C(   -26.45), SIMDE_FLOAT32_C(  -566.00) },
      { SIMDE_FLOAT32_C(   122.56), SIMDE_FLOAT32_C(  -587.20), SIMDE_FLOAT32_C(   -49.41), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(  -380.61), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -967.54), SIMDE_FLOAT32_C(  -566.00) } },
    { UINT8_C( 79),
      { SIMDE_FLOAT32_C(  -877.01), SIMDE_FLOAT32_C(  -855.26), SIMDE_FLOAT32_C(  -460.15), SIMDE_FLOAT32_C(  -416.87),
        SIMDE_FLOAT32_C(  -325.09), SIMDE_FLOAT32_C(   291.54), SIMDE_FLOAT32_C(  -914.51), SIMDE_FLOAT32_C(  -981.31) },
      { SIMDE_FLOAT32_C(   791.83), SIMDE_FLOAT32_C(  -604.32), SIMDE_FLOAT32_C(  -908.24), SIMDE_FLOAT32_C(  -172.22),
        SIMDE_FLOAT32_C(   680.68), SIMDE_FLOAT32_C(  -860.58), SIMDE_FLOAT32_C(    54.44), SIMDE_FLOAT32_C(   203.45) },
      { SIMDE_FLOAT32_C(  -460.15), SIMDE_FLOAT32_C(  -908.24), SIMDE_FLOAT32_C(  -416.87), SIMDE_FLOAT32_C(  -172.22),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -981.31), SIMDE_FLOAT32_C(     0.00) } },
    { UINT8_C(106),
      { SIMDE_FLOAT32_C(  -994.97), SIMDE_FLOAT32_C(  -821.33), SIMDE_FLOAT32_C(   204.34), SIMDE_FLOAT32_C(  -375.59),
        SIMDE_FLOAT32_C(  -788.87), SIMDE_FLOAT32_C(   366.75), SIMDE_FLOAT32_C(   776.95), SIMDE_FLOAT32_C(  -376.06) },
      { SIMDE_FLOAT32_C(   273.18), SIMDE_FLOAT32_C(  -216.17), SIMDE_FLOAT32_C(   643.63), SIMDE_FLOAT32_C(  -753.27),
        SIMDE_FLOAT32_C(   217.82), SIMDE_FLOAT32_C(  -789.28), SIMDE_FLOAT32_C(  -630.28), SIMDE_FLOAT32_C(   362.56) },
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   643.63), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -753.27),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -630.28), SIMDE_FLOAT32_C(  -376.06), SIMDE_FLOAT32_C(     0.00) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__mmask8 k = test_vec[i].k;
    simde__m256 a = simde_mm256_loadu_ps(test_vec[i].a);
    simde__m256 b = simde_mm256_loadu_ps(test_vec[i].b);
    simde__m256 r = simde_mm256_maskz_unpackhi_ps(k, a, b);
    simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m256 a = simde_test_x86_random_f32x8(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
    simde__m256 b = simde_test_x86_random_f32x8(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
    simde__m256 r = simde_mm256_maskz_unpackhi_ps(k, a, b);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f32x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_mask_unpackhi_ps (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde_float32 src[4];
    const simde__mmask8 k;
    const simde_float32 a[4];
    const simde_float32 b[4];
    const simde_float32 r[4];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(  -314.15), SIMDE_FLOAT32_C(    38.64), SIMDE_FLOAT32_C(  -308.73), SIMDE_FLOAT32_C(   378.68) },
      UINT8_C( 32),
      { SIMDE_FLOAT32_C(   880.89), SIMDE_FLOAT32_C(  -126.77), SIMDE_FLOAT32_C(  -716.44), SIMDE_FLOAT32_C(   652.86) },
      { SIMDE_FLOAT32_C(   979.47), SIMDE_FLOAT32_C(   247.18), SIMDE_FLOAT32_C(  -177.35), SIMDE_FLOAT32_C(   470.01) },
      { SIMDE_FLOAT32_C(  -314.15), SIMDE_FLOAT32_C(    38.64), SIMDE_FLOAT32_C(  -308.73), SIMDE_FLOAT32_C(   378.68) } },
    { { SIMDE_FLOAT32_C(  -118.23), SIMDE_FLOAT32_C(    49.73), SIMDE_FLOAT32_C(   344.97), SIMDE_FLOAT32_C(   468.04) },
      UINT8_C( 59),
      { SIMDE_FLOAT32_C(   656.55), SIMDE_FLOAT32_C(  -281.17), SIMDE_FLOAT32_C(   351.04), SIMDE_FLOAT32_C(  -156.44) },
      { SIMDE_FLOAT32_C(   592.25), SIMDE_FLOAT32_C(   204.70), SIMDE_FLOAT32_C(   218.11), SIMDE_FLOAT32_C(  -190.20) },
      { SIMDE_FLOAT32_C(   351.04), SIMDE_FLOAT32_C(   218.11), SIMDE_FLOAT32_C(   344.97), SIMDE_FLOAT32_C(  -190.20) } },
    { { SIMDE_FLOAT32_C(   501.79), SIMDE_FLOAT32_C(   936.51), SIMDE_FLOAT32_C(   -91.19), SIMDE_FLOAT32_C(   232.75) },
      UINT8_C(102),
      { SIMDE_FLOAT32_C(   594.66), SIMDE_FLOAT32_C(  -728.60), SIMDE_FLOAT32_C(   995.72), SIMDE_FLOAT32_C(   -26.66) },
      { SIMDE_FLOAT32_C(   627.16), SIMDE_FLOAT32_C(   876.61), SIMDE_FLOAT32_C(   846.57), SIMDE_FLOAT32_C(   910.72) },
      { SIMDE_FLOAT32_C(   501.79), SIMDE_FLOAT32_C(   846.57), SIMDE_FLOAT32_C(   -26.66), SIMDE_FLOAT32_C(   232.75) } },
    { { SIMDE_FLOAT32_C(   529.48), SIMDE_FLOAT32_C(   826.05), SIMDE_FLOAT32_C(   157.89), SIMDE_FLOAT32_C(  -647.87) },
      UINT8_C( 85),
      { SIMDE_FLOAT32_C(  -960.33), SIMDE_FLOAT32_C(   401.86), SIMDE_FLOAT32_C(  -358.97), SIMDE_FLOAT32_C(   507.70) },
      { SIMDE_FLOAT32_C(  -148.50), SIMDE_FLOAT32_C(  -702.42), SIMDE_FLOAT32_C(  -773.46), SIMDE_FLOAT32_C(  -797.47) },
      { SIMDE_FLOAT32_C(  -358.97), SIMDE_FLOAT32_C(   826.05), SIMDE_FLOAT32_C(   507.70), SIMDE_FLOAT32_C(  -647.87) } },
    { { SIMDE_FLOAT32_C(   141.14), SIMDE_FLOAT32_C(   818.79), SIMDE_FLOAT32_C(   407.23), SIMDE_FLOAT32_C(  -640.75) },
      UINT8_C(  7),
      { SIMDE_FLOAT32_C(   -90.98), SIMDE_FLOAT32_C(  -704.24), SIMDE_FLOAT32_C(   537.40), SIMDE_FLOAT32_C(  -858.22) },
      { SIMDE_FLOAT32_C(   600.21), SIMDE_FLOAT32_C(   132.06), SIMDE_FLOAT32_C(  -586.83), SIMDE_FLOAT32_C(   595.94) },
      { SIMDE_FLOAT32_C(   537.40), SIMDE_FLOAT32_C(  -586.83), SIMDE_FLOAT32_C(  -858.22), SIMDE_FLOAT32_C(  -640.75) } },
    { { SIMDE_FLOAT32_C(  -894.60), SIMDE_FLOAT32_C(  -959.67), SIMDE_FLOAT32_C(   472.55), SIMDE_FLOAT32_C(   951.98) },
      UINT8_C(100),
      { SIMDE_FLOAT32_C(     2.03), SIMDE_FLOAT32_C(   778.03), SIMDE_FLOAT32_C(   108.95), SIMDE_FLOAT32_C(   354.16) },
      { SIMDE_FLOAT32_C(    74.08), SIMDE_FLOAT32_C(   148.61), SIMDE_FLOAT32_C(  -243.98), SIMDE_FLOAT32_C(   715.11) },
      { SIMDE_FLOAT32_C(  -894.60), SIMDE_FLOAT32_C(  -959.67), SIMDE_FLOAT32_C(   354.16), SIMDE_FLOAT32_C(   951.98) } },
    { { SIMDE_FLOAT32_C(  -343.68), SIMDE_FLOAT32_C(   607.51), SIMDE_FLOAT32_C(  -987.31), SIMDE_FLOAT32_C(  -117.14) },
      UINT8_C(109),
      { SIMDE_FLOAT32_C(   153.83), SIMDE_FLOAT32_C(  -298.35), SIMDE_FLOAT32_C(   217.28), SIMDE_FLOAT32_C(   513.08) },
      { SIMDE_FLOAT32_C(   330.24), SIMDE_FLOAT32_C(  -873.69), SIMDE_FLOAT32_C(   808.84), SIMDE_FLOAT32_C(  -132.36) },
      { SIMDE_FLOAT32_C(   217.28), SIMDE_FLOAT32_C(   607.51), SIMDE_FLOAT32_C(   513.08), SIMDE_FLOAT32_C(  -132.36) } },
    { { SIMDE_FLOAT32_C(  -731.92), SIMDE_FLOAT32_C(   409.05), SIMDE_FLOAT32_C(   999.71), SIMDE_FLOAT32_C(  -318.75) },
      UINT8_C(151),
      { SIMDE_FLOAT32_C(  -894.89), SIMDE_FLOAT32_C(  -278.41), SIMDE_FLOAT32_C(  -522.46), SIMDE_FLOAT32_C(  -942.92) },
      { SIMDE_FLOAT32_C(  -327.36), SIMDE_FLOAT32_C(   479.56), SIMDE_FLOAT32_C(   835.11), SIMDE_FLOAT32_C(   781.59) },
      { SIMDE_FLOAT32_C(  -522.46), SIMDE_FLOAT32_C(   835.11), SIMDE_FLOAT32_C(  -942.92), SIMDE_FLOAT32_C(  -318.75) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128 src = simde_mm_loadu_ps(test_vec[i].src);
    simde__mmask8 k = test_vec[i].k;
    simde__m128 a = simde_mm_loadu_ps(test_vec[i].a);
    simde__m128 b = simde_mm_loadu_ps(test_vec[i].b);
    simde__m128 r = simde_mm_mask_unpackhi_ps(src, k, a, b);
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
    simde__m128 r = simde_mm_mask_unpackhi_ps(src, k, a, b);

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
test_simde_mm_maskz_unpackhi_ps (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k;
    const simde_float32 a[4];
    const simde_float32 b[4];
    const simde_float32 r[4];
  } test_vec[] = {
    { UINT8_C(206),
      { SIMDE_FLOAT32_C(    -5.88), SIMDE_FLOAT32_C(   317.80), SIMDE_FLOAT32_C(  -881.57), SIMDE_FLOAT32_C(   587.05) },
      { SIMDE_FLOAT32_C(  -297.21), SIMDE_FLOAT32_C(   -47.33), SIMDE_FLOAT32_C(  -401.14), SIMDE_FLOAT32_C(   172.18) },
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -401.14), SIMDE_FLOAT32_C(   587.05), SIMDE_FLOAT32_C(   172.18) } },
    { UINT8_C(252),
      { SIMDE_FLOAT32_C(  -103.39), SIMDE_FLOAT32_C(  -683.19), SIMDE_FLOAT32_C(   410.51), SIMDE_FLOAT32_C(   744.73) },
      { SIMDE_FLOAT32_C(   646.86), SIMDE_FLOAT32_C(  -611.29), SIMDE_FLOAT32_C(   291.92), SIMDE_FLOAT32_C(  -937.78) },
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   744.73), SIMDE_FLOAT32_C(  -937.78) } },
    { UINT8_C(224),
      { SIMDE_FLOAT32_C(   698.72), SIMDE_FLOAT32_C(  -742.61), SIMDE_FLOAT32_C(   848.95), SIMDE_FLOAT32_C(  -579.86) },
      { SIMDE_FLOAT32_C(  -492.97), SIMDE_FLOAT32_C(   988.25), SIMDE_FLOAT32_C(  -895.12), SIMDE_FLOAT32_C(   363.75) },
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
    { UINT8_C(232),
      { SIMDE_FLOAT32_C(  -554.91), SIMDE_FLOAT32_C(  -313.79), SIMDE_FLOAT32_C(  -534.05), SIMDE_FLOAT32_C(   838.24) },
      { SIMDE_FLOAT32_C(   680.33), SIMDE_FLOAT32_C(   783.75), SIMDE_FLOAT32_C(   956.66), SIMDE_FLOAT32_C(   267.37) },
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   267.37) } },
    { UINT8_C(218),
      { SIMDE_FLOAT32_C(   -90.67), SIMDE_FLOAT32_C(   866.23), SIMDE_FLOAT32_C(   658.72), SIMDE_FLOAT32_C(   264.35) },
      { SIMDE_FLOAT32_C(  -237.15), SIMDE_FLOAT32_C(   975.53), SIMDE_FLOAT32_C(  -325.14), SIMDE_FLOAT32_C(  -492.43) },
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -325.14), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -492.43) } },
    { UINT8_C(  2),
      { SIMDE_FLOAT32_C(    63.58), SIMDE_FLOAT32_C(   799.49), SIMDE_FLOAT32_C(   684.61), SIMDE_FLOAT32_C(  -376.56) },
      { SIMDE_FLOAT32_C(   498.21), SIMDE_FLOAT32_C(   942.00), SIMDE_FLOAT32_C(  -527.61), SIMDE_FLOAT32_C(   918.35) },
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -527.61), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
    { UINT8_C(176),
      { SIMDE_FLOAT32_C(  -539.35), SIMDE_FLOAT32_C(  -976.76), SIMDE_FLOAT32_C(   812.78), SIMDE_FLOAT32_C(   -15.76) },
      { SIMDE_FLOAT32_C(  -531.67), SIMDE_FLOAT32_C(  -501.01), SIMDE_FLOAT32_C(   450.19), SIMDE_FLOAT32_C(  -693.43) },
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
    { UINT8_C(180),
      { SIMDE_FLOAT32_C(   233.95), SIMDE_FLOAT32_C(  -736.77), SIMDE_FLOAT32_C(   446.70), SIMDE_FLOAT32_C(   720.49) },
      { SIMDE_FLOAT32_C(   172.56), SIMDE_FLOAT32_C(   312.93), SIMDE_FLOAT32_C(   379.21), SIMDE_FLOAT32_C(  -563.10) },
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   720.49), SIMDE_FLOAT32_C(     0.00) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__mmask8 k = test_vec[i].k;
    simde__m128 a = simde_mm_loadu_ps(test_vec[i].a);
    simde__m128 b = simde_mm_loadu_ps(test_vec[i].b);
    simde__m128 r = simde_mm_maskz_unpackhi_ps(k, a, b);
    simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m128 a = simde_test_x86_random_f32x4(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
    simde__m128 b = simde_test_x86_random_f32x4(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
    simde__m128 r = simde_mm_maskz_unpackhi_ps(k, a, b);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f32x4(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_unpackhi_pd (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const simde_float64 a[8];
    const simde_float64 b[8];
    const simde_float64 r[8];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(  -303.04), SIMDE_FLOAT64_C(   484.86), SIMDE_FLOAT64_C(  -578.12), SIMDE_FLOAT64_C(   269.18),
        SIMDE_FLOAT64_C(  -655.06), SIMDE_FLOAT64_C(  -192.80), SIMDE_FLOAT64_C(  -504.95), SIMDE_FLOAT64_C(   -13.86) },
      { SIMDE_FLOAT64_C(  -659.88), SIMDE_FLOAT64_C(  -876.52), SIMDE_FLOAT64_C(   331.70), SIMDE_FLOAT64_C(   855.30),
        SIMDE_FLOAT64_C(  -350.13), SIMDE_FLOAT64_C(  -147.74), SIMDE_FLOAT64_C(   998.52), SIMDE_FLOAT64_C(   390.85) },
      { SIMDE_FLOAT64_C(   484.86), SIMDE_FLOAT64_C(  -876.52), SIMDE_FLOAT64_C(   269.18), SIMDE_FLOAT64_C(   855.30),
        SIMDE_FLOAT64_C(  -192.80), SIMDE_FLOAT64_C(  -147.74), SIMDE_FLOAT64_C(   -13.86), SIMDE_FLOAT64_C(   390.85) } },
    { { SIMDE_FLOAT64_C(   -87.98), SIMDE_FLOAT64_C(   370.18), SIMDE_FLOAT64_C(  -919.77), SIMDE_FLOAT64_C(   771.23),
        SIMDE_FLOAT64_C(    18.30), SIMDE_FLOAT64_C(   191.55), SIMDE_FLOAT64_C(  -358.05), SIMDE_FLOAT64_C(   800.62) },
      { SIMDE_FLOAT64_C(   678.98), SIMDE_FLOAT64_C(   604.48), SIMDE_FLOAT64_C(  -562.21), SIMDE_FLOAT64_C(  -868.39),
        SIMDE_FLOAT64_C(   766.01), SIMDE_FLOAT64_C(  -121.09), SIMDE_FLOAT64_C(   212.43), SIMDE_FLOAT64_C(  -537.02) },
      { SIMDE_FLOAT64_C(   370.18), SIMDE_FLOAT64_C(   604.48), SIMDE_FLOAT64_C(   771.23), SIMDE_FLOAT64_C(  -868.39),
        SIMDE_FLOAT64_C(   191.55), SIMDE_FLOAT64_C(  -121.09), SIMDE_FLOAT64_C(   800.62), SIMDE_FLOAT64_C(  -537.02) } },
    { { SIMDE_FLOAT64_C(  -636.22), SIMDE_FLOAT64_C(   634.32), SIMDE_FLOAT64_C(   732.16), SIMDE_FLOAT64_C(  -291.28),
        SIMDE_FLOAT64_C(  -558.48), SIMDE_FLOAT64_C(  -772.79), SIMDE_FLOAT64_C(   694.86), SIMDE_FLOAT64_C(  -218.36) },
      { SIMDE_FLOAT64_C(  -649.31), SIMDE_FLOAT64_C(    26.55), SIMDE_FLOAT64_C(  -363.06), SIMDE_FLOAT64_C(     0.56),
        SIMDE_FLOAT64_C(   878.82), SIMDE_FLOAT64_C(  -364.54), SIMDE_FLOAT64_C(  -608.59), SIMDE_FLOAT64_C(  -209.17) },
      { SIMDE_FLOAT64_C(   634.32), SIMDE_FLOAT64_C(    26.55), SIMDE_FLOAT64_C(  -291.28), SIMDE_FLOAT64_C(     0.56),
        SIMDE_FLOAT64_C(  -772.79), SIMDE_FLOAT64_C(  -364.54), SIMDE_FLOAT64_C(  -218.36), SIMDE_FLOAT64_C(  -209.17) } },
    { { SIMDE_FLOAT64_C(  -994.36), SIMDE_FLOAT64_C(  -528.36), SIMDE_FLOAT64_C(  -437.93), SIMDE_FLOAT64_C(    23.94),
        SIMDE_FLOAT64_C(   663.19), SIMDE_FLOAT64_C(   204.02), SIMDE_FLOAT64_C(  -175.44), SIMDE_FLOAT64_C(   342.17) },
      { SIMDE_FLOAT64_C(  -191.50), SIMDE_FLOAT64_C(   262.35), SIMDE_FLOAT64_C(   473.78), SIMDE_FLOAT64_C(  -425.48),
        SIMDE_FLOAT64_C(  -858.74), SIMDE_FLOAT64_C(  -313.78), SIMDE_FLOAT64_C(    37.50), SIMDE_FLOAT64_C(  -494.96) },
      { SIMDE_FLOAT64_C(  -528.36), SIMDE_FLOAT64_C(   262.35), SIMDE_FLOAT64_C(    23.94), SIMDE_FLOAT64_C(  -425.48),
        SIMDE_FLOAT64_C(   204.02), SIMDE_FLOAT64_C(  -313.78), SIMDE_FLOAT64_C(   342.17), SIMDE_FLOAT64_C(  -494.96) } },
    { { SIMDE_FLOAT64_C(  -679.47), SIMDE_FLOAT64_C(  -230.35), SIMDE_FLOAT64_C(   213.75), SIMDE_FLOAT64_C(  -237.95),
        SIMDE_FLOAT64_C(    -3.14), SIMDE_FLOAT64_C(   -91.39), SIMDE_FLOAT64_C(   543.69), SIMDE_FLOAT64_C(   347.54) },
      { SIMDE_FLOAT64_C(   935.16), SIMDE_FLOAT64_C(  -819.37), SIMDE_FLOAT64_C(  -651.90), SIMDE_FLOAT64_C(   813.98),
        SIMDE_FLOAT64_C(  -183.91), SIMDE_FLOAT64_C(  -260.49), SIMDE_FLOAT64_C(  -395.18), SIMDE_FLOAT64_C(  -178.27) },
      { SIMDE_FLOAT64_C(  -230.35), SIMDE_FLOAT64_C(  -819.37), SIMDE_FLOAT64_C(  -237.95), SIMDE_FLOAT64_C(   813.98),
        SIMDE_FLOAT64_C(   -91.39), SIMDE_FLOAT64_C(  -260.49), SIMDE_FLOAT64_C(   347.54), SIMDE_FLOAT64_C(  -178.27) } },
    { { SIMDE_FLOAT64_C(   211.15), SIMDE_FLOAT64_C(   166.89), SIMDE_FLOAT64_C(   845.67), SIMDE_FLOAT64_C(  -125.66),
        SIMDE_FLOAT64_C(  -629.09), SIMDE_FLOAT64_C(  -329.77), SIMDE_FLOAT64_C(  -783.49), SIMDE_FLOAT64_C(   179.41) },
      { SIMDE_FLOAT64_C(   932.58), SIMDE_FLOAT64_C(   690.29), SIMDE_FLOAT64_C(   753.93), SIMDE_FLOAT64_C(  -926.16),
        SIMDE_FLOAT64_C(  -623.49), SIMDE_FLOAT64_C(  -208.57), SIMDE_FLOAT64_C(  -421.12), SIMDE_FLOAT64_C(  -302.96) },
      { SIMDE_FLOAT64_C(   166.89), SIMDE_FLOAT64_C(   690.29), SIMDE_FLOAT64_C(  -125.66), SIMDE_FLOAT64_C(  -926.16),
        SIMDE_FLOAT64_C(  -329.77), SIMDE_FLOAT64_C(  -208.57), SIMDE_FLOAT64_C(   179.41), SIMDE_FLOAT64_C(  -302.96) } },
    { { SIMDE_FLOAT64_C(   561.08), SIMDE_FLOAT64_C(   792.63), SIMDE_FLOAT64_C(   459.09), SIMDE_FLOAT64_C(  -442.06),
        SIMDE_FLOAT64_C(  -298.76), SIMDE_FLOAT64_C(     2.78), SIMDE_FLOAT64_C(   905.48), SIMDE_FLOAT64_C(  -363.60) },
      { SIMDE_FLOAT64_C(   183.42), SIMDE_FLOAT64_C(  -746.41), SIMDE_FLOAT64_C(  -549.61), SIMDE_FLOAT64_C(   999.50),
        SIMDE_FLOAT64_C(    -6.90), SIMDE_FLOAT64_C(    55.20), SIMDE_FLOAT64_C(  -178.77), SIMDE_FLOAT64_C(  -795.75) },
      { SIMDE_FLOAT64_C(   792.63), SIMDE_FLOAT64_C(  -746.41), SIMDE_FLOAT64_C(  -442.06), SIMDE_FLOAT64_C(   999.50),
        SIMDE_FLOAT64_C(     2.78), SIMDE_FLOAT64_C(    55.20), SIMDE_FLOAT64_C(  -363.60), SIMDE_FLOAT64_C(  -795.75) } },
    { { SIMDE_FLOAT64_C(  -777.91), SIMDE_FLOAT64_C(  -333.10), SIMDE_FLOAT64_C(    78.59), SIMDE_FLOAT64_C(  -407.00),
        SIMDE_FLOAT64_C(   337.13), SIMDE_FLOAT64_C(   295.09), SIMDE_FLOAT64_C(   772.42), SIMDE_FLOAT64_C(   269.71) },
      { SIMDE_FLOAT64_C(   -14.62), SIMDE_FLOAT64_C(   526.35), SIMDE_FLOAT64_C(   343.55), SIMDE_FLOAT64_C(   361.89),
        SIMDE_FLOAT64_C(  -682.22), SIMDE_FLOAT64_C(   922.43), SIMDE_FLOAT64_C(  -941.07), SIMDE_FLOAT64_C(   878.86) },
      { SIMDE_FLOAT64_C(  -333.10), SIMDE_FLOAT64_C(   526.35), SIMDE_FLOAT64_C(  -407.00), SIMDE_FLOAT64_C(   361.89),
        SIMDE_FLOAT64_C(   295.09), SIMDE_FLOAT64_C(   922.43), SIMDE_FLOAT64_C(   269.71), SIMDE_FLOAT64_C(   878.86) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512d a = simde_mm512_loadu_pd(test_vec[i].a);
    simde__m512d b = simde_mm512_loadu_pd(test_vec[i].b);
    simde__m512d r = simde_mm512_unpackhi_pd(a, b);
    simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[i].r), 1);
  }

  return 0;
}

static int
test_simde_mm512_mask_unpackhi_pd (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const simde_float64 src[8];
    const simde__mmask8 k;
    const simde_float64 a[8];
    const simde_float64 b[8];
    const simde_float64 r[8];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(   622.29), SIMDE_FLOAT64_C(  -234.57), SIMDE_FLOAT64_C(   242.01), SIMDE_FLOAT64_C(   603.16),
        SIMDE_FLOAT64_C(  -763.13), SIMDE_FLOAT64_C(  -189.71), SIMDE_FLOAT64_C(  -905.64), SIMDE_FLOAT64_C(  -228.31) },
      UINT8_C(111),
      { SIMDE_FLOAT64_C(  -284.33), SIMDE_FLOAT64_C(    76.05), SIMDE_FLOAT64_C(   485.40), SIMDE_FLOAT64_C(   792.35),
        SIMDE_FLOAT64_C(   520.35), SIMDE_FLOAT64_C(  -375.72), SIMDE_FLOAT64_C(   317.52), SIMDE_FLOAT64_C(  -414.64) },
      { SIMDE_FLOAT64_C(  -632.01), SIMDE_FLOAT64_C(  -915.99), SIMDE_FLOAT64_C(    85.58), SIMDE_FLOAT64_C(  -240.99),
        SIMDE_FLOAT64_C(    54.79), SIMDE_FLOAT64_C(   838.88), SIMDE_FLOAT64_C(   324.71), SIMDE_FLOAT64_C(   651.03) },
      { SIMDE_FLOAT64_C(    76.05), SIMDE_FLOAT64_C(  -915.99), SIMDE_FLOAT64_C(   792.35), SIMDE_FLOAT64_C(  -240.99),
        SIMDE_FLOAT64_C(  -763.13), SIMDE_FLOAT64_C(   838.88), SIMDE_FLOAT64_C(  -414.64), SIMDE_FLOAT64_C(  -228.31) } },
    { { SIMDE_FLOAT64_C(   707.10), SIMDE_FLOAT64_C(   330.16), SIMDE_FLOAT64_C(  -750.77), SIMDE_FLOAT64_C(  -538.69),
        SIMDE_FLOAT64_C(   746.68), SIMDE_FLOAT64_C(   -52.02), SIMDE_FLOAT64_C(  -916.39), SIMDE_FLOAT64_C(  -487.89) },
      UINT8_C(246),
      { SIMDE_FLOAT64_C(   686.77), SIMDE_FLOAT64_C(  -251.02), SIMDE_FLOAT64_C(     0.28), SIMDE_FLOAT64_C(   781.13),
        SIMDE_FLOAT64_C(   520.67), SIMDE_FLOAT64_C(  -181.67), SIMDE_FLOAT64_C(  -503.21), SIMDE_FLOAT64_C(  -403.28) },
      { SIMDE_FLOAT64_C(  -696.27), SIMDE_FLOAT64_C(  -710.85), SIMDE_FLOAT64_C(  -882.93), SIMDE_FLOAT64_C(   -71.98),
        SIMDE_FLOAT64_C(   606.67), SIMDE_FLOAT64_C(  -297.57), SIMDE_FLOAT64_C(   296.01), SIMDE_FLOAT64_C(   690.68) },
      { SIMDE_FLOAT64_C(   707.10), SIMDE_FLOAT64_C(  -710.85), SIMDE_FLOAT64_C(   781.13), SIMDE_FLOAT64_C(  -538.69),
        SIMDE_FLOAT64_C(  -181.67), SIMDE_FLOAT64_C(  -297.57), SIMDE_FLOAT64_C(  -403.28), SIMDE_FLOAT64_C(   690.68) } },
    { { SIMDE_FLOAT64_C(   788.01), SIMDE_FLOAT64_C(  -944.98), SIMDE_FLOAT64_C(  -254.53), SIMDE_FLOAT64_C(   626.89),
        SIMDE_FLOAT64_C(   379.74), SIMDE_FLOAT64_C(  -603.50), SIMDE_FLOAT64_C(   333.99), SIMDE_FLOAT64_C(  -290.11) },
      UINT8_C( 94),
      { SIMDE_FLOAT64_C(   795.30), SIMDE_FLOAT64_C(  -543.43), SIMDE_FLOAT64_C(   593.70), SIMDE_FLOAT64_C(   878.91),
        SIMDE_FLOAT64_C(   -31.32), SIMDE_FLOAT64_C(   783.69), SIMDE_FLOAT64_C(   565.68), SIMDE_FLOAT64_C(   717.66) },
      { SIMDE_FLOAT64_C(  -216.03), SIMDE_FLOAT64_C(   346.80), SIMDE_FLOAT64_C(   238.33), SIMDE_FLOAT64_C(   602.30),
        SIMDE_FLOAT64_C(   843.60), SIMDE_FLOAT64_C(   835.06), SIMDE_FLOAT64_C(   906.03), SIMDE_FLOAT64_C(  -867.26) },
      { SIMDE_FLOAT64_C(   788.01), SIMDE_FLOAT64_C(   346.80), SIMDE_FLOAT64_C(   878.91), SIMDE_FLOAT64_C(   602.30),
        SIMDE_FLOAT64_C(   783.69), SIMDE_FLOAT64_C(  -603.50), SIMDE_FLOAT64_C(   717.66), SIMDE_FLOAT64_C(  -290.11) } },
    { { SIMDE_FLOAT64_C(   952.12), SIMDE_FLOAT64_C(  -165.95), SIMDE_FLOAT64_C(   739.41), SIMDE_FLOAT64_C(  -345.45),
        SIMDE_FLOAT64_C(  -869.94), SIMDE_FLOAT64_C(   430.09), SIMDE_FLOAT64_C(  -557.44), SIMDE_FLOAT64_C(  -814.92) },
      UINT8_C(172),
      { SIMDE_FLOAT64_C(  -930.55), SIMDE_FLOAT64_C(   564.82), SIMDE_FLOAT64_C(  -427.95), SIMDE_FLOAT64_C(   403.44),
        SIMDE_FLOAT64_C(  -725.29), SIMDE_FLOAT64_C(   217.77), SIMDE_FLOAT64_C(   198.74), SIMDE_FLOAT64_C(  -268.72) },
      { SIMDE_FLOAT64_C(  -188.52), SIMDE_FLOAT64_C(    77.65), SIMDE_FLOAT64_C(   699.95), SIMDE_FLOAT64_C(  -404.83),
        SIMDE_FLOAT64_C(  -356.67), SIMDE_FLOAT64_C(   417.61), SIMDE_FLOAT64_C(   379.14), SIMDE_FLOAT64_C(   990.13) },
      { SIMDE_FLOAT64_C(   952.12), SIMDE_FLOAT64_C(  -165.95), SIMDE_FLOAT64_C(   403.44), SIMDE_FLOAT64_C(  -404.83),
        SIMDE_FLOAT64_C(  -869.94), SIMDE_FLOAT64_C(   417.61), SIMDE_FLOAT64_C(  -557.44), SIMDE_FLOAT64_C(   990.13) } },
    { { SIMDE_FLOAT64_C(  -344.05), SIMDE_FLOAT64_C(   -18.56), SIMDE_FLOAT64_C(   833.73), SIMDE_FLOAT64_C(  -509.00),
        SIMDE_FLOAT64_C(  -112.53), SIMDE_FLOAT64_C(   966.47), SIMDE_FLOAT64_C(  -556.87), SIMDE_FLOAT64_C(   721.52) },
      UINT8_C(219),
      { SIMDE_FLOAT64_C(    97.68), SIMDE_FLOAT64_C(   851.58), SIMDE_FLOAT64_C(   135.98), SIMDE_FLOAT64_C(   540.24),
        SIMDE_FLOAT64_C(  -963.34), SIMDE_FLOAT64_C(   311.54), SIMDE_FLOAT64_C(   609.69), SIMDE_FLOAT64_C(   601.48) },
      { SIMDE_FLOAT64_C(   883.59), SIMDE_FLOAT64_C(    13.12), SIMDE_FLOAT64_C(   876.19), SIMDE_FLOAT64_C(   101.36),
        SIMDE_FLOAT64_C(  -788.13), SIMDE_FLOAT64_C(  -392.54), SIMDE_FLOAT64_C(   912.84), SIMDE_FLOAT64_C(   289.52) },
      { SIMDE_FLOAT64_C(   851.58), SIMDE_FLOAT64_C(    13.12), SIMDE_FLOAT64_C(   833.73), SIMDE_FLOAT64_C(   101.36),
        SIMDE_FLOAT64_C(   311.54), SIMDE_FLOAT64_C(   966.47), SIMDE_FLOAT64_C(   601.48), SIMDE_FLOAT64_C(   289.52) } },
    { { SIMDE_FLOAT64_C(  -692.58), SIMDE_FLOAT64_C(  -491.99), SIMDE_FLOAT64_C(   932.85), SIMDE_FLOAT64_C(   725.03),
        SIMDE_FLOAT64_C(   887.14), SIMDE_FLOAT64_C(   922.98), SIMDE_FLOAT64_C(  -619.02), SIMDE_FLOAT64_C(  -131.42) },
      UINT8_C(109),
      { SIMDE_FLOAT64_C(  -128.02), SIMDE_FLOAT64_C(   756.05), SIMDE_FLOAT64_C(   723.19), SIMDE_FLOAT64_C(   315.11),
        SIMDE_FLOAT64_C(   477.57), SIMDE_FLOAT64_C(   429.08), SIMDE_FLOAT64_C(  -587.21), SIMDE_FLOAT64_C(   329.15) },
      { SIMDE_FLOAT64_C(  -434.95), SIMDE_FLOAT64_C(   953.03), SIMDE_FLOAT64_C(   365.82), SIMDE_FLOAT64_C(   876.59),
        SIMDE_FLOAT64_C(   562.71), SIMDE_FLOAT64_C(   -32.71), SIMDE_FLOAT64_C(   760.18), SIMDE_FLOAT64_C(  -424.16) },
      { SIMDE_FLOAT64_C(   756.05), SIMDE_FLOAT64_C(  -491.99), SIMDE_FLOAT64_C(   315.11), SIMDE_FLOAT64_C(   876.59),
        SIMDE_FLOAT64_C(   887.14), SIMDE_FLOAT64_C(   -32.71), SIMDE_FLOAT64_C(   329.15), SIMDE_FLOAT64_C(  -131.42) } },
    { { SIMDE_FLOAT64_C(  -156.52), SIMDE_FLOAT64_C(  -138.46), SIMDE_FLOAT64_C(  -212.30), SIMDE_FLOAT64_C(   450.94),
        SIMDE_FLOAT64_C(  -225.62), SIMDE_FLOAT64_C(  -922.78), SIMDE_FLOAT64_C(   758.36), SIMDE_FLOAT64_C(   282.39) },
      UINT8_C(216),
      { SIMDE_FLOAT64_C(   483.39), SIMDE_FLOAT64_C(   169.53), SIMDE_FLOAT64_C(   933.05), SIMDE_FLOAT64_C(   864.37),
        SIMDE_FLOAT64_C(  -961.89), SIMDE_FLOAT64_C(   689.77), SIMDE_FLOAT64_C(  -263.65), SIMDE_FLOAT64_C(   794.16) },
      { SIMDE_FLOAT64_C(   412.95), SIMDE_FLOAT64_C(  -948.54), SIMDE_FLOAT64_C(   271.73), SIMDE_FLOAT64_C(  -157.97),
        SIMDE_FLOAT64_C(  -535.75), SIMDE_FLOAT64_C(  -399.12), SIMDE_FLOAT64_C(   407.08), SIMDE_FLOAT64_C(  -582.72) },
      { SIMDE_FLOAT64_C(  -156.52), SIMDE_FLOAT64_C(  -138.46), SIMDE_FLOAT64_C(  -212.30), SIMDE_FLOAT64_C(  -157.97),
        SIMDE_FLOAT64_C(   689.77), SIMDE_FLOAT64_C(  -922.78), SIMDE_FLOAT64_C(   794.16), SIMDE_FLOAT64_C(  -582.72) } },
    { { SIMDE_FLOAT64_C(   966.70), SIMDE_FLOAT64_C(   283.67), SIMDE_FLOAT64_C(   979.99), SIMDE_FLOAT64_C(   -66.01),
        SIMDE_FLOAT64_C(    43.85), SIMDE_FLOAT64_C(  -444.18), SIMDE_FLOAT64_C(   777.47), SIMDE_FLOAT64_C(   905.40) },
      UINT8_C( 28),
      { SIMDE_FLOAT64_C(   228.41), SIMDE_FLOAT64_C(  -320.22), SIMDE_FLOAT64_C(   420.75), SIMDE_FLOAT64_C(   -13.23),
        SIMDE_FLOAT64_C(   962.17), SIMDE_FLOAT64_C(   430.81), SIMDE_FLOAT64_C(  -529.84), SIMDE_FLOAT64_C(   131.70) },
      { SIMDE_FLOAT64_C(   363.87), SIMDE_FLOAT64_C(  -665.47), SIMDE_FLOAT64_C(   169.81), SIMDE_FLOAT64_C(    53.63),
        SIMDE_FLOAT64_C(    70.89), SIMDE_FLOAT64_C(   -36.03), SIMDE_FLOAT64_C(  -533.41), SIMDE_FLOAT64_C(   122.35) },
      { SIMDE_FLOAT64_C(   966.70), SIMDE_FLOAT64_C(   283.67), SIMDE_FLOAT64_C(   -13.23), SIMDE_FLOAT64_C(    53.63),
        SIMDE_FLOAT64_C(   430.81), SIMDE_FLOAT64_C(  -444.18), SIMDE_FLOAT64_C(   777.47), SIMDE_FLOAT64_C(   905.40) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512d src = simde_mm512_loadu_pd(test_vec[i].src);
    simde__m512d a = simde_mm512_loadu_pd(test_vec[i].a);
    simde__m512d b = simde_mm512_loadu_pd(test_vec[i].b);
    simde__m512d r = simde_mm512_mask_unpackhi_pd(src, test_vec[i].k, a, b);
    simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[i].r), 1);
  }

  return 0;
}

static int
test_simde_mm512_maskz_unpackhi_pd (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const simde__mmask8 k;
    const simde_float64 a[8];
    const simde_float64 b[8];
    const simde_float64 r[8];
  } test_vec[] = {
    { UINT8_C(242),
      { SIMDE_FLOAT64_C(  -414.51), SIMDE_FLOAT64_C(   -12.29), SIMDE_FLOAT64_C(   160.05), SIMDE_FLOAT64_C(   653.04),
        SIMDE_FLOAT64_C(   -28.81), SIMDE_FLOAT64_C(  -415.64), SIMDE_FLOAT64_C(   403.48), SIMDE_FLOAT64_C(   868.73) },
      { SIMDE_FLOAT64_C(  -715.00), SIMDE_FLOAT64_C(  -297.46), SIMDE_FLOAT64_C(  -191.42), SIMDE_FLOAT64_C(   464.99),
        SIMDE_FLOAT64_C(    12.91), SIMDE_FLOAT64_C(   240.45), SIMDE_FLOAT64_C(   671.85), SIMDE_FLOAT64_C(   163.80) },
      { SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(  -297.46), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00),
        SIMDE_FLOAT64_C(  -415.64), SIMDE_FLOAT64_C(   240.45), SIMDE_FLOAT64_C(   868.73), SIMDE_FLOAT64_C(   163.80) } },
    { UINT8_C( 85),
      { SIMDE_FLOAT64_C(   676.07), SIMDE_FLOAT64_C(   842.78), SIMDE_FLOAT64_C(  -171.45), SIMDE_FLOAT64_C(   899.43),
        SIMDE_FLOAT64_C(  -868.32), SIMDE_FLOAT64_C(   497.70), SIMDE_FLOAT64_C(  -644.76), SIMDE_FLOAT64_C(   -32.60) },
      { SIMDE_FLOAT64_C(  -827.94), SIMDE_FLOAT64_C(  -663.55), SIMDE_FLOAT64_C(   469.25), SIMDE_FLOAT64_C(   386.02),
        SIMDE_FLOAT64_C(  -683.55), SIMDE_FLOAT64_C(    95.06), SIMDE_FLOAT64_C(   971.52), SIMDE_FLOAT64_C(   304.16) },
      { SIMDE_FLOAT64_C(   842.78), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(   899.43), SIMDE_FLOAT64_C(     0.00),
        SIMDE_FLOAT64_C(   497.70), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(   -32.60), SIMDE_FLOAT64_C(     0.00) } },
    { UINT8_C(113),
      { SIMDE_FLOAT64_C(   624.56), SIMDE_FLOAT64_C(  -724.64), SIMDE_FLOAT64_C(  -160.53), SIMDE_FLOAT64_C(    28.03),
        SIMDE_FLOAT64_C(  -855.91), SIMDE_FLOAT64_C(   124.47), SIMDE_FLOAT64_C(   730.57), SIMDE_FLOAT64_C(   -47.33) },
      { SIMDE_FLOAT64_C(  -410.54), SIMDE_FLOAT64_C(  -256.52), SIMDE_FLOAT64_C(  -806.88), SIMDE_FLOAT64_C(  -738.68),
        SIMDE_FLOAT64_C(   907.28), SIMDE_FLOAT64_C(  -267.36), SIMDE_FLOAT64_C(   937.39), SIMDE_FLOAT64_C(   750.06) },
      { SIMDE_FLOAT64_C(  -724.64), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00),
        SIMDE_FLOAT64_C(   124.47), SIMDE_FLOAT64_C(  -267.36), SIMDE_FLOAT64_C(   -47.33), SIMDE_FLOAT64_C(     0.00) } },
    { UINT8_C(176),
      { SIMDE_FLOAT64_C(   836.82), SIMDE_FLOAT64_C(   881.74), SIMDE_FLOAT64_C(    58.89), SIMDE_FLOAT64_C(  -807.94),
        SIMDE_FLOAT64_C(  -150.85), SIMDE_FLOAT64_C(   230.95), SIMDE_FLOAT64_C(  -471.49), SIMDE_FLOAT64_C(  -681.61) },
      { SIMDE_FLOAT64_C(  -383.03), SIMDE_FLOAT64_C(  -155.04), SIMDE_FLOAT64_C(   413.45), SIMDE_FLOAT64_C(  -411.51),
        SIMDE_FLOAT64_C(  -850.88), SIMDE_FLOAT64_C(   668.57), SIMDE_FLOAT64_C(  -786.95), SIMDE_FLOAT64_C(  -575.52) },
      { SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00),
        SIMDE_FLOAT64_C(   230.95), SIMDE_FLOAT64_C(   668.57), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(  -575.52) } },
    { UINT8_C(127),
      { SIMDE_FLOAT64_C(   241.08), SIMDE_FLOAT64_C(  -431.43), SIMDE_FLOAT64_C(   632.51), SIMDE_FLOAT64_C(   -28.35),
        SIMDE_FLOAT64_C(   521.24), SIMDE_FLOAT64_C(  -778.03), SIMDE_FLOAT64_C(   715.13), SIMDE_FLOAT64_C(   714.36) },
      { SIMDE_FLOAT64_C(  -516.71), SIMDE_FLOAT64_C(   622.41), SIMDE_FLOAT64_C(  -553.00), SIMDE_FLOAT64_C(  -579.33),
        SIMDE_FLOAT64_C(   372.48), SIMDE_FLOAT64_C(  -991.81), SIMDE_FLOAT64_C(  -742.51), SIMDE_FLOAT64_C(   254.22) },
      { SIMDE_FLOAT64_C(  -431.43), SIMDE_FLOAT64_C(   622.41), SIMDE_FLOAT64_C(   -28.35), SIMDE_FLOAT64_C(  -579.33),
        SIMDE_FLOAT64_C(  -778.03), SIMDE_FLOAT64_C(  -991.81), SIMDE_FLOAT64_C(   714.36), SIMDE_FLOAT64_C(     0.00) } },
    { UINT8_C(235),
      { SIMDE_FLOAT64_C(  -550.44), SIMDE_FLOAT64_C(  -896.63), SIMDE_FLOAT64_C(  -701.96), SIMDE_FLOAT64_C(   -21.93),
        SIMDE_FLOAT64_C(  -578.24), SIMDE_FLOAT64_C(   -84.99), SIMDE_FLOAT64_C(   823.02), SIMDE_FLOAT64_C(   835.22) },
      { SIMDE_FLOAT64_C(   503.50), SIMDE_FLOAT64_C(   972.15), SIMDE_FLOAT64_C(   503.78), SIMDE_FLOAT64_C(   716.55),
        SIMDE_FLOAT64_C(  -603.37), SIMDE_FLOAT64_C(  -988.18), SIMDE_FLOAT64_C(   -42.37), SIMDE_FLOAT64_C(   -34.81) },
      { SIMDE_FLOAT64_C(  -896.63), SIMDE_FLOAT64_C(   972.15), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(   716.55),
        SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(  -988.18), SIMDE_FLOAT64_C(   835.22), SIMDE_FLOAT64_C(   -34.81) } },
    { UINT8_C( 35),
      { SIMDE_FLOAT64_C(   929.28), SIMDE_FLOAT64_C(  -513.57), SIMDE_FLOAT64_C(   866.30), SIMDE_FLOAT64_C(   644.41),
        SIMDE_FLOAT64_C(  -799.21), SIMDE_FLOAT64_C(  -650.41), SIMDE_FLOAT64_C(   266.82), SIMDE_FLOAT64_C(  -352.22) },
      { SIMDE_FLOAT64_C(  -229.74), SIMDE_FLOAT64_C(  -360.70), SIMDE_FLOAT64_C(  -344.02), SIMDE_FLOAT64_C(    27.76),
        SIMDE_FLOAT64_C(   893.52), SIMDE_FLOAT64_C(   723.06), SIMDE_FLOAT64_C(   477.32), SIMDE_FLOAT64_C(   996.89) },
      { SIMDE_FLOAT64_C(  -513.57), SIMDE_FLOAT64_C(  -360.70), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00),
        SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(   723.06), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00) } },
    { UINT8_C(169),
      { SIMDE_FLOAT64_C(  -544.62), SIMDE_FLOAT64_C(  -581.34), SIMDE_FLOAT64_C(   -63.90), SIMDE_FLOAT64_C(  -721.59),
        SIMDE_FLOAT64_C(  -746.13), SIMDE_FLOAT64_C(  -560.39), SIMDE_FLOAT64_C(  -749.45), SIMDE_FLOAT64_C(   757.66) },
      { SIMDE_FLOAT64_C(  -843.85), SIMDE_FLOAT64_C(  -352.82), SIMDE_FLOAT64_C(   769.48), SIMDE_FLOAT64_C(   113.78),
        SIMDE_FLOAT64_C(   612.37), SIMDE_FLOAT64_C(   413.81), SIMDE_FLOAT64_C(    43.06), SIMDE_FLOAT64_C(  -901.20) },
      { SIMDE_FLOAT64_C(  -581.34), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(   113.78),
        SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(   413.81), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(  -901.20) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512d a = simde_mm512_loadu_pd(test_vec[i].a);
    simde__m512d b = simde_mm512_loadu_pd(test_vec[i].b);
    simde__m512d r = simde_mm512_maskz_unpackhi_pd(test_vec[i].k, a, b);
    simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[i].r), 1);
  }

  return 0;
}

static int
test_simde_mm256_mask_unpackhi_pd (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde_float64 src[4];
    const simde__mmask8 k;
    const simde_float64 a[4];
    const simde_float64 b[4];
    const simde_float64 r[4];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(   744.70), SIMDE_FLOAT64_C(  -360.92), SIMDE_FLOAT64_C(  -715.50), SIMDE_FLOAT64_C(  -924.91) },
      UINT8_C( 53),
      { SIMDE_FLOAT64_C(  -236.39), SIMDE_FLOAT64_C(   274.12), SIMDE_FLOAT64_C(  -951.31), SIMDE_FLOAT64_C(  -927.34) },
      { SIMDE_FLOAT64_C(   399.00), SIMDE_FLOAT64_C(   693.52), SIMDE_FLOAT64_C(   762.68), SIMDE_FLOAT64_C(   627.03) },
      { SIMDE_FLOAT64_C(   274.12), SIMDE_FLOAT64_C(  -360.92), SIMDE_FLOAT64_C(  -927.34), SIMDE_FLOAT64_C(  -924.91) } },
    { { SIMDE_FLOAT64_C(  -245.44), SIMDE_FLOAT64_C(  -877.31), SIMDE_FLOAT64_C(  -898.92), SIMDE_FLOAT64_C(   853.63) },
      UINT8_C(179),
      { SIMDE_FLOAT64_C(  -876.15), SIMDE_FLOAT64_C(   332.59), SIMDE_FLOAT64_C(  -228.24), SIMDE_FLOAT64_C(     6.72) },
      { SIMDE_FLOAT64_C(  -173.12), SIMDE_FLOAT64_C(   542.57), SIMDE_FLOAT64_C(   167.63), SIMDE_FLOAT64_C(  -336.25) },
      { SIMDE_FLOAT64_C(   332.59), SIMDE_FLOAT64_C(   542.57), SIMDE_FLOAT64_C(  -898.92), SIMDE_FLOAT64_C(   853.63) } },
    { { SIMDE_FLOAT64_C(   -10.71), SIMDE_FLOAT64_C(  -533.41), SIMDE_FLOAT64_C(   920.83), SIMDE_FLOAT64_C(   709.63) },
      UINT8_C(138),
      { SIMDE_FLOAT64_C(   665.52), SIMDE_FLOAT64_C(  -651.30), SIMDE_FLOAT64_C(   367.03), SIMDE_FLOAT64_C(   740.62) },
      { SIMDE_FLOAT64_C(   597.74), SIMDE_FLOAT64_C(  -869.36), SIMDE_FLOAT64_C(    14.74), SIMDE_FLOAT64_C(   646.43) },
      { SIMDE_FLOAT64_C(   -10.71), SIMDE_FLOAT64_C(  -869.36), SIMDE_FLOAT64_C(   920.83), SIMDE_FLOAT64_C(   646.43) } },
    { { SIMDE_FLOAT64_C(  -796.70), SIMDE_FLOAT64_C(  -586.26), SIMDE_FLOAT64_C(   339.95), SIMDE_FLOAT64_C(   965.98) },
      UINT8_C( 38),
      { SIMDE_FLOAT64_C(  -905.49), SIMDE_FLOAT64_C(  -911.33), SIMDE_FLOAT64_C(  -858.15), SIMDE_FLOAT64_C(   948.14) },
      { SIMDE_FLOAT64_C(   102.62), SIMDE_FLOAT64_C(  -734.30), SIMDE_FLOAT64_C(   280.73), SIMDE_FLOAT64_C(   874.38) },
      { SIMDE_FLOAT64_C(  -796.70), SIMDE_FLOAT64_C(  -734.30), SIMDE_FLOAT64_C(   948.14), SIMDE_FLOAT64_C(   965.98) } },
    { { SIMDE_FLOAT64_C(   272.42), SIMDE_FLOAT64_C(  -892.39), SIMDE_FLOAT64_C(   416.95), SIMDE_FLOAT64_C(  -559.95) },
      UINT8_C( 80),
      { SIMDE_FLOAT64_C(  -593.76), SIMDE_FLOAT64_C(   -93.36), SIMDE_FLOAT64_C(  -307.81), SIMDE_FLOAT64_C(  -884.13) },
      { SIMDE_FLOAT64_C(   989.16), SIMDE_FLOAT64_C(  -642.29), SIMDE_FLOAT64_C(  -535.43), SIMDE_FLOAT64_C(   356.19) },
      { SIMDE_FLOAT64_C(   272.42), SIMDE_FLOAT64_C(  -892.39), SIMDE_FLOAT64_C(   416.95), SIMDE_FLOAT64_C(  -559.95) } },
    { { SIMDE_FLOAT64_C(  -901.67), SIMDE_FLOAT64_C(  -937.69), SIMDE_FLOAT64_C(   486.83), SIMDE_FLOAT64_C(   113.07) },
      UINT8_C(169),
      { SIMDE_FLOAT64_C(   690.13), SIMDE_FLOAT64_C(   526.81), SIMDE_FLOAT64_C(    48.69), SIMDE_FLOAT64_C(   656.11) },
      { SIMDE_FLOAT64_C(   567.59), SIMDE_FLOAT64_C(   143.21), SIMDE_FLOAT64_C(   744.78), SIMDE_FLOAT64_C(   709.44) },
      { SIMDE_FLOAT64_C(   526.81), SIMDE_FLOAT64_C(  -937.69), SIMDE_FLOAT64_C(   486.83), SIMDE_FLOAT64_C(   709.44) } },
    { { SIMDE_FLOAT64_C(    91.35), SIMDE_FLOAT64_C(  -152.60), SIMDE_FLOAT64_C(   975.14), SIMDE_FLOAT64_C(  -627.93) },
      UINT8_C(130),
      { SIMDE_FLOAT64_C(   247.56), SIMDE_FLOAT64_C(  -520.31), SIMDE_FLOAT64_C(  -861.26), SIMDE_FLOAT64_C(   687.61) },
      { SIMDE_FLOAT64_C(   251.05), SIMDE_FLOAT64_C(  -455.02), SIMDE_FLOAT64_C(  -405.75), SIMDE_FLOAT64_C(   943.24) },
      { SIMDE_FLOAT64_C(    91.35), SIMDE_FLOAT64_C(  -455.02), SIMDE_FLOAT64_C(   975.14), SIMDE_FLOAT64_C(  -627.93) } },
    { { SIMDE_FLOAT64_C(  -339.16), SIMDE_FLOAT64_C(  -416.59), SIMDE_FLOAT64_C(  -699.05), SIMDE_FLOAT64_C(   125.41) },
      UINT8_C(171),
      { SIMDE_FLOAT64_C(  -600.72), SIMDE_FLOAT64_C(   187.72), SIMDE_FLOAT64_C(   426.43), SIMDE_FLOAT64_C(   512.35) },
      { SIMDE_FLOAT64_C(  -103.54), SIMDE_FLOAT64_C(   116.56), SIMDE_FLOAT64_C(    39.16), SIMDE_FLOAT64_C(   945.15) },
      { SIMDE_FLOAT64_C(   187.72), SIMDE_FLOAT64_C(   116.56), SIMDE_FLOAT64_C(  -699.05), SIMDE_FLOAT64_C(   945.15) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256d src = simde_mm256_loadu_pd(test_vec[i].src);
    simde__mmask8 k = test_vec[i].k;
    simde__m256d a = simde_mm256_loadu_pd(test_vec[i].a);
    simde__m256d b = simde_mm256_loadu_pd(test_vec[i].b);
    simde__m256d r = simde_mm256_mask_unpackhi_pd(src, k, a, b);
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
    simde__m256d r = simde_mm256_mask_unpackhi_pd(src, k, a, b);

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
test_simde_mm256_maskz_unpackhi_pd (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k;
    const simde_float64 a[4];
    const simde_float64 b[4];
    const simde_float64 r[4];
  } test_vec[] = {
    { UINT8_C(148),
      { SIMDE_FLOAT64_C(    22.21), SIMDE_FLOAT64_C(  -110.23), SIMDE_FLOAT64_C(  -794.32), SIMDE_FLOAT64_C(   216.89) },
      { SIMDE_FLOAT64_C(   487.08), SIMDE_FLOAT64_C(  -838.02), SIMDE_FLOAT64_C(   523.96), SIMDE_FLOAT64_C(   326.32) },
      { SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(   216.89), SIMDE_FLOAT64_C(     0.00) } },
    { UINT8_C( 16),
      { SIMDE_FLOAT64_C(   428.60), SIMDE_FLOAT64_C(  -950.01), SIMDE_FLOAT64_C(  -673.87), SIMDE_FLOAT64_C(   893.58) },
      { SIMDE_FLOAT64_C(  -865.85), SIMDE_FLOAT64_C(   431.55), SIMDE_FLOAT64_C(   933.59), SIMDE_FLOAT64_C(   123.06) },
      { SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00) } },
    { UINT8_C(185),
      { SIMDE_FLOAT64_C(  -767.62), SIMDE_FLOAT64_C(  -995.03), SIMDE_FLOAT64_C(   432.92), SIMDE_FLOAT64_C(  -574.60) },
      { SIMDE_FLOAT64_C(  -679.27), SIMDE_FLOAT64_C(   -92.08), SIMDE_FLOAT64_C(  -198.00), SIMDE_FLOAT64_C(   268.04) },
      { SIMDE_FLOAT64_C(  -995.03), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(   268.04) } },
    { UINT8_C( 84),
      { SIMDE_FLOAT64_C(  -973.95), SIMDE_FLOAT64_C(   885.00), SIMDE_FLOAT64_C(   784.39), SIMDE_FLOAT64_C(   584.10) },
      { SIMDE_FLOAT64_C(   -92.79), SIMDE_FLOAT64_C(  -325.84), SIMDE_FLOAT64_C(   789.78), SIMDE_FLOAT64_C(  -875.90) },
      { SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(   584.10), SIMDE_FLOAT64_C(     0.00) } },
    { UINT8_C(216),
      { SIMDE_FLOAT64_C(   951.76), SIMDE_FLOAT64_C(   648.06), SIMDE_FLOAT64_C(   487.56), SIMDE_FLOAT64_C(   452.48) },
      { SIMDE_FLOAT64_C(    76.66), SIMDE_FLOAT64_C(   537.55), SIMDE_FLOAT64_C(   778.61), SIMDE_FLOAT64_C(   -29.76) },
      { SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(   -29.76) } },
    { UINT8_C(175),
      { SIMDE_FLOAT64_C(   210.16), SIMDE_FLOAT64_C(   -96.17), SIMDE_FLOAT64_C(  -205.24), SIMDE_FLOAT64_C(  -689.26) },
      { SIMDE_FLOAT64_C(   136.21), SIMDE_FLOAT64_C(  -200.28), SIMDE_FLOAT64_C(   743.65), SIMDE_FLOAT64_C(   561.61) },
      { SIMDE_FLOAT64_C(   -96.17), SIMDE_FLOAT64_C(  -200.28), SIMDE_FLOAT64_C(  -689.26), SIMDE_FLOAT64_C(   561.61) } },
    { UINT8_C(199),
      { SIMDE_FLOAT64_C(  -348.43), SIMDE_FLOAT64_C(  -636.40), SIMDE_FLOAT64_C(  -611.50), SIMDE_FLOAT64_C(   -82.37) },
      { SIMDE_FLOAT64_C(  -610.34), SIMDE_FLOAT64_C(  -726.51), SIMDE_FLOAT64_C(  -297.98), SIMDE_FLOAT64_C(   973.76) },
      { SIMDE_FLOAT64_C(  -636.40), SIMDE_FLOAT64_C(  -726.51), SIMDE_FLOAT64_C(   -82.37), SIMDE_FLOAT64_C(     0.00) } },
    { UINT8_C(115),
      { SIMDE_FLOAT64_C(   376.18), SIMDE_FLOAT64_C(   763.54), SIMDE_FLOAT64_C(   304.81), SIMDE_FLOAT64_C(   537.43) },
      { SIMDE_FLOAT64_C(   715.31), SIMDE_FLOAT64_C(   -47.13), SIMDE_FLOAT64_C(    24.99), SIMDE_FLOAT64_C(   167.79) },
      { SIMDE_FLOAT64_C(   763.54), SIMDE_FLOAT64_C(   -47.13), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__mmask8 k = test_vec[i].k;
    simde__m256d a = simde_mm256_loadu_pd(test_vec[i].a);
    simde__m256d b = simde_mm256_loadu_pd(test_vec[i].b);
    simde__m256d r = simde_mm256_maskz_unpackhi_pd(k, a, b);
    simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m256d a = simde_test_x86_random_f64x4(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde__m256d b = simde_test_x86_random_f64x4(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde__m256d r = simde_mm256_maskz_unpackhi_pd(k, a, b);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f64x4(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_mask_unpackhi_pd (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde_float64 src[2];
    const simde__mmask8 k;
    const simde_float64 a[2];
    const simde_float64 b[2];
    const simde_float64 r[2];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(   -91.91), SIMDE_FLOAT64_C(  -786.98) },
      UINT8_C(219),
      { SIMDE_FLOAT64_C(   449.25), SIMDE_FLOAT64_C(  -796.70) },
      { SIMDE_FLOAT64_C(   318.50), SIMDE_FLOAT64_C(  -649.30) },
      { SIMDE_FLOAT64_C(  -796.70), SIMDE_FLOAT64_C(  -649.30) } },
    { { SIMDE_FLOAT64_C(  -375.64), SIMDE_FLOAT64_C(   706.15) },
      UINT8_C(173),
      { SIMDE_FLOAT64_C(   616.71), SIMDE_FLOAT64_C(   502.81) },
      { SIMDE_FLOAT64_C(   238.72), SIMDE_FLOAT64_C(  -456.54) },
      { SIMDE_FLOAT64_C(   502.81), SIMDE_FLOAT64_C(   706.15) } },
    { { SIMDE_FLOAT64_C(   486.65), SIMDE_FLOAT64_C(   585.30) },
      UINT8_C(129),
      { SIMDE_FLOAT64_C(  -402.33), SIMDE_FLOAT64_C(  -221.29) },
      { SIMDE_FLOAT64_C(  -928.43), SIMDE_FLOAT64_C(   700.21) },
      { SIMDE_FLOAT64_C(  -221.29), SIMDE_FLOAT64_C(   585.30) } },
    { { SIMDE_FLOAT64_C(   880.20), SIMDE_FLOAT64_C(  -740.13) },
      UINT8_C(  2),
      { SIMDE_FLOAT64_C(  -351.11), SIMDE_FLOAT64_C(   940.62) },
      { SIMDE_FLOAT64_C(   866.34), SIMDE_FLOAT64_C(   401.18) },
      { SIMDE_FLOAT64_C(   880.20), SIMDE_FLOAT64_C(   401.18) } },
    { { SIMDE_FLOAT64_C(   188.02), SIMDE_FLOAT64_C(   370.10) },
      UINT8_C( 59),
      { SIMDE_FLOAT64_C(  -903.89), SIMDE_FLOAT64_C(   583.12) },
      { SIMDE_FLOAT64_C(  -161.53), SIMDE_FLOAT64_C(   545.36) },
      { SIMDE_FLOAT64_C(   583.12), SIMDE_FLOAT64_C(   545.36) } },
    { { SIMDE_FLOAT64_C(   786.42), SIMDE_FLOAT64_C(  -843.03) },
      UINT8_C(215),
      { SIMDE_FLOAT64_C(  -589.22), SIMDE_FLOAT64_C(   863.13) },
      { SIMDE_FLOAT64_C(  -262.93), SIMDE_FLOAT64_C(  -972.51) },
      { SIMDE_FLOAT64_C(   863.13), SIMDE_FLOAT64_C(  -972.51) } },
    { { SIMDE_FLOAT64_C(   365.93), SIMDE_FLOAT64_C(   975.79) },
      UINT8_C(180),
      { SIMDE_FLOAT64_C(  -147.41), SIMDE_FLOAT64_C(   561.09) },
      { SIMDE_FLOAT64_C(   955.58), SIMDE_FLOAT64_C(   450.26) },
      { SIMDE_FLOAT64_C(   365.93), SIMDE_FLOAT64_C(   975.79) } },
    { { SIMDE_FLOAT64_C(  -660.20), SIMDE_FLOAT64_C(  -972.86) },
      UINT8_C(150),
      { SIMDE_FLOAT64_C(  -780.00), SIMDE_FLOAT64_C(  -712.98) },
      { SIMDE_FLOAT64_C(  -995.42), SIMDE_FLOAT64_C(  -131.11) },
      { SIMDE_FLOAT64_C(  -660.20), SIMDE_FLOAT64_C(  -131.11) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128d src = simde_mm_loadu_pd(test_vec[i].src);
    simde__mmask8 k = test_vec[i].k;
    simde__m128d a = simde_mm_loadu_pd(test_vec[i].a);
    simde__m128d b = simde_mm_loadu_pd(test_vec[i].b);
    simde__m128d r = simde_mm_mask_unpackhi_pd(src, k, a, b);
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
    simde__m128d r = simde_mm_mask_unpackhi_pd(src, k, a, b);

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
test_simde_mm_maskz_unpackhi_pd (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k;
    const simde_float64 a[2];
    const simde_float64 b[2];
    const simde_float64 r[2];
  } test_vec[] = {
    { UINT8_C(187),
      { SIMDE_FLOAT64_C(  -163.14), SIMDE_FLOAT64_C(   906.60) },
      { SIMDE_FLOAT64_C(   278.62), SIMDE_FLOAT64_C(   756.76) },
      { SIMDE_FLOAT64_C(   906.60), SIMDE_FLOAT64_C(   756.76) } },
    { UINT8_C(110),
      { SIMDE_FLOAT64_C(   571.26), SIMDE_FLOAT64_C(   632.37) },
      { SIMDE_FLOAT64_C(  -965.41), SIMDE_FLOAT64_C(  -546.83) },
      { SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(  -546.83) } },
    { UINT8_C( 72),
      { SIMDE_FLOAT64_C(   582.85), SIMDE_FLOAT64_C(   380.08) },
      { SIMDE_FLOAT64_C(  -120.40), SIMDE_FLOAT64_C(  -589.78) },
      { SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00) } },
    { UINT8_C(213),
      { SIMDE_FLOAT64_C(  -562.33), SIMDE_FLOAT64_C(   189.86) },
      { SIMDE_FLOAT64_C(   -77.14), SIMDE_FLOAT64_C(   720.71) },
      { SIMDE_FLOAT64_C(   189.86), SIMDE_FLOAT64_C(     0.00) } },
    { UINT8_C(152),
      { SIMDE_FLOAT64_C(  -319.42), SIMDE_FLOAT64_C(   -11.39) },
      { SIMDE_FLOAT64_C(  -748.46), SIMDE_FLOAT64_C(  -412.59) },
      { SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00) } },
    { UINT8_C(153),
      { SIMDE_FLOAT64_C(    92.52), SIMDE_FLOAT64_C(  -728.06) },
      { SIMDE_FLOAT64_C(   628.60), SIMDE_FLOAT64_C(    -0.84) },
      { SIMDE_FLOAT64_C(  -728.06), SIMDE_FLOAT64_C(     0.00) } },
    { UINT8_C(125),
      { SIMDE_FLOAT64_C(   702.56), SIMDE_FLOAT64_C(   836.02) },
      { SIMDE_FLOAT64_C(   899.19), SIMDE_FLOAT64_C(   -18.82) },
      { SIMDE_FLOAT64_C(   836.02), SIMDE_FLOAT64_C(     0.00) } },
    { UINT8_C(156),
      { SIMDE_FLOAT64_C(    36.88), SIMDE_FLOAT64_C(  -447.56) },
      { SIMDE_FLOAT64_C(   225.14), SIMDE_FLOAT64_C(    71.47) },
      { SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__mmask8 k = test_vec[i].k;
    simde__m128d a = simde_mm_loadu_pd(test_vec[i].a);
    simde__m128d b = simde_mm_loadu_pd(test_vec[i].b);
    simde__m128d r = simde_mm_maskz_unpackhi_pd(k, a, b);
    simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m128d a = simde_test_x86_random_f64x2(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde__m128d b = simde_test_x86_random_f64x2(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde__m128d r = simde_mm_maskz_unpackhi_pd(k, a, b);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f64x2(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_unpackhi_epi8)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_unpackhi_epi8)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_maskz_unpackhi_epi8)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_mask_unpackhi_epi8)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_maskz_unpackhi_epi8)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_mask_unpackhi_epi8)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_maskz_unpackhi_epi8)

  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_unpackhi_epi16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_unpackhi_epi16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_maskz_unpackhi_epi16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_mask_unpackhi_epi16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_maskz_unpackhi_epi16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_mask_unpackhi_epi16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_maskz_unpackhi_epi16)

  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_unpackhi_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_unpackhi_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_maskz_unpackhi_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_mask_unpackhi_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_maskz_unpackhi_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_mask_unpackhi_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_maskz_unpackhi_epi32)

  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_unpackhi_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_unpackhi_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_maskz_unpackhi_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_mask_unpackhi_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_maskz_unpackhi_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_mask_unpackhi_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_maskz_unpackhi_epi64)

  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_unpackhi_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_unpackhi_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_maskz_unpackhi_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_mask_unpackhi_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_maskz_unpackhi_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_mask_unpackhi_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_maskz_unpackhi_ps)

  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_unpackhi_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_unpackhi_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_maskz_unpackhi_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_mask_unpackhi_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_maskz_unpackhi_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_mask_unpackhi_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_maskz_unpackhi_pd)
SIMDE_TEST_FUNC_LIST_END

#include <test/x86/avx512/test-avx512-footer.h>
