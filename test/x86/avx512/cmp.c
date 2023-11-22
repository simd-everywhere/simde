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
 *   2020      Himanshi Mathur <himanshi18037@iiitd.ac.in>
 */

#define SIMDE_TEST_X86_AVX512_INSN cmp

#include <test/x86/avx512/test-avx512.h>
#include <simde/x86/avx512/set.h>
#include <simde/x86/avx512/cmp.h>
#include <simde/x86/avx512/mov.h>
#include <simde/x86/avx512/set1.h>

static int
test_simde_mm512_cmp_epi8_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int8_t a[64];
    const int8_t b[64];
    const simde__mmask64 r;
  } test_vec[] = {
    { {  INT8_C(  96),  INT8_C(  22), -INT8_C(  32), -INT8_C( 126),  INT8_C(  42), -INT8_C( 102),  INT8_C(  45), -INT8_C(  95),
         INT8_C(  48),  INT8_C(  62),  INT8_C(   2),  INT8_C(  19),  INT8_C(   6), -INT8_C(  95),  INT8_C(  87),  INT8_C(  19),
         INT8_C(  78), -INT8_C(  21),  INT8_C( 122),  INT8_C(  10), -INT8_C(  75), -INT8_C(  57), -INT8_C(  98), -INT8_C( 101),
         INT8_C(  24), -INT8_C( 106),  INT8_C(  66),  INT8_C( 113), -INT8_C(  76), -INT8_C(  67),  INT8_C(  58),  INT8_C(  20),
        -INT8_C(  45),  INT8_C(  26), -INT8_C( 105), -INT8_C(   3), -INT8_C(  76), -INT8_C(  60), -INT8_C(  98), -INT8_C(  28),
         INT8_C(   2), -INT8_C(  95), -INT8_C(   8),  INT8_C(   9),  INT8_C(  66),  INT8_C(  79),  INT8_C(  28), -INT8_C( 112),
         INT8_C(  58), -INT8_C( 106), -INT8_C( 102), -INT8_C(  16),  INT8_C(  94),  INT8_C(  56), -INT8_C( 117),  INT8_C( 118),
        -INT8_C(  50), -INT8_C(  51), -INT8_C(  24), -INT8_C( 126), -INT8_C( 118),  INT8_C(  34), -INT8_C( 105),  INT8_C(  93) },
      {  INT8_C(  60),  INT8_C(  46),  INT8_C(  90), -INT8_C(  16),  INT8_C(  42), -INT8_C( 102),  INT8_C(  45), -INT8_C(  95),
         INT8_C(  48), -INT8_C(  52),  INT8_C(   2), -INT8_C(  36),  INT8_C(  27), -INT8_C(  95),  INT8_C(  87),  INT8_C(  19),
         INT8_C(  78), -INT8_C(  21),  INT8_C( 122),  INT8_C(  10), -INT8_C(  75), -INT8_C(  57), -INT8_C(  98), -INT8_C( 101),
         INT8_C(  24), -INT8_C( 106),  INT8_C(  66),  INT8_C( 113), -INT8_C(  76), -INT8_C(  67),  INT8_C(  58),  INT8_C(  20),
        -INT8_C(  45),  INT8_C(  26), -INT8_C( 105), -INT8_C(   3), -INT8_C(  76), -INT8_C(  60), -INT8_C(  98), -INT8_C(  28),
         INT8_C(   2), -INT8_C(  95), -INT8_C(   8),  INT8_C(   9),  INT8_C(  66),  INT8_C(  79),  INT8_C(  28), -INT8_C( 112),
         INT8_C(  58), -INT8_C( 106), -INT8_C( 102), -INT8_C(  16),  INT8_C(  94),  INT8_C(  56), -INT8_C( 117),  INT8_C( 118),
        -INT8_C(  50), -INT8_C(  51), -INT8_C(  24), -INT8_C( 126), -INT8_C( 118),  INT8_C(  34), -INT8_C( 105),  INT8_C(  93) },
      UINT64_C(18446744073709544944) },
    { {  INT8_C( 105), -INT8_C(  25), -INT8_C(  87), -INT8_C(  91),  INT8_C(  90),  INT8_C(   5), -INT8_C(  33), -INT8_C(  87),
         INT8_C( 125),  INT8_C(  51),  INT8_C( 101),  INT8_C(  74),  INT8_C(  56),  INT8_C(  40),  INT8_C(  94),  INT8_C(  75),
         INT8_C(  44),  INT8_C(  66), -INT8_C(  29),  INT8_C(  62), -INT8_C(  59), -INT8_C(  24), -INT8_C(  31),  INT8_C( 111),
         INT8_C( 124), -INT8_C(  84), -INT8_C(  97), -INT8_C(  37), -INT8_C(  51), -INT8_C(  82), -INT8_C(  11),  INT8_C(  54),
        -INT8_C( 107), -INT8_C(  98), -INT8_C(  37), -INT8_C(  17), -INT8_C(  92), -INT8_C(  69), -INT8_C( 104),  INT8_C(  33),
        -INT8_C(  18), -INT8_C(   3),  INT8_C( 107),  INT8_C(  38),  INT8_C(  38), -INT8_C(  55),  INT8_C( 113),  INT8_C(  82),
         INT8_C(  12),  INT8_C(  84), -INT8_C( 112), -INT8_C(  47),  INT8_C(  60),  INT8_C( 113),  INT8_C(  64), -INT8_C(  72),
         INT8_C(  29), -INT8_C(  33), -INT8_C( 109), -INT8_C(  22), -INT8_C( 115), -INT8_C( 120),  INT8_C(  32),  INT8_C(  35) },
      {  INT8_C(  39), -INT8_C(   5), -INT8_C(  87), -INT8_C(  53), -INT8_C(  74),  INT8_C(   5), -INT8_C(  20), -INT8_C(  91),
         INT8_C( 125),  INT8_C(  51),  INT8_C( 101), -INT8_C(  50),  INT8_C(  56),  INT8_C(  61),  INT8_C(  94),  INT8_C(  45),
        -INT8_C( 111), -INT8_C(  80), -INT8_C(   2), -INT8_C(  50),  INT8_C(  33),  INT8_C(  62), -INT8_C( 122),  INT8_C(  62),
         INT8_C(  30),  INT8_C(  26),  INT8_C(  40), -INT8_C(  85), -INT8_C(  94),  INT8_C(  72), -INT8_C(  50), -INT8_C(  55),
         INT8_C(  68), -INT8_C(  31), -INT8_C( 108), -INT8_C(   6), -INT8_C( 116),      INT8_MIN, -INT8_C(  97),  INT8_C(  52),
        -INT8_C(  40),  INT8_C( 107),  INT8_C(   3), -INT8_C(   7), -INT8_C(  88),  INT8_C(  35),  INT8_C(  38),  INT8_C(  57),
        -INT8_C(  44),  INT8_C(  36),  INT8_C(   7), -INT8_C(  11),  INT8_C(  98), -INT8_C( 114),  INT8_C(  52),      INT8_MIN,
        -INT8_C(  88),  INT8_C(  92),  INT8_C(  44),  INT8_C(  74), -INT8_C(  91), -INT8_C(   6),  INT8_C(  20), -INT8_C(  23) },
      UINT64_C( 4475490385614086218) },
    { { -INT8_C(  29),  INT8_C( 103),  INT8_C(  41), -INT8_C( 125), -INT8_C( 100),  INT8_C(   1), -INT8_C(  18), -INT8_C(  97),
        -INT8_C(   6), -INT8_C( 106), -INT8_C(  62),  INT8_C(  32), -INT8_C(  49), -INT8_C( 106),  INT8_C(  68), -INT8_C(  41),
        -INT8_C( 116), -INT8_C(  90),  INT8_C( 101), -INT8_C(  64),  INT8_C(  39),  INT8_C(  13),  INT8_C(  28),  INT8_C(  83),
         INT8_C(  87), -INT8_C(  63),  INT8_C(  77),  INT8_C( 107), -INT8_C(  86),  INT8_C(  41),  INT8_C(  20), -INT8_C( 114),
        -INT8_C( 112),  INT8_C(  61),  INT8_C(  17),  INT8_C(  44),  INT8_C(  62), -INT8_C(   1), -INT8_C(  53),  INT8_C(  56),
        -INT8_C( 107), -INT8_C( 114),  INT8_C(  88),  INT8_C( 100),  INT8_C(  36), -INT8_C( 100),  INT8_C(  59), -INT8_C(  80),
         INT8_C(  66), -INT8_C(  96),  INT8_C( 112),  INT8_C( 105), -INT8_C(  83), -INT8_C( 115), -INT8_C(  68),  INT8_C(   5),
         INT8_C(  78),  INT8_C(  10),  INT8_C( 112), -INT8_C(   7),  INT8_C(  51), -INT8_C( 124), -INT8_C( 121), -INT8_C(  61) },
      { -INT8_C(  63),  INT8_C( 103),  INT8_C(  41), -INT8_C(   1), -INT8_C( 100), -INT8_C(  69), -INT8_C(  18), -INT8_C(  97),
         INT8_C(  73), -INT8_C( 106), -INT8_C( 112),  INT8_C(  32),  INT8_C(  43), -INT8_C( 106),  INT8_C(  68),  INT8_C( 110),
         INT8_C( 108), -INT8_C( 113), -INT8_C(  41),  INT8_C(  26),  INT8_C(  28), -INT8_C( 108),  INT8_C(  31),  INT8_C( 106),
        -INT8_C(  98), -INT8_C( 113),  INT8_C(  99), -INT8_C(  47),  INT8_C(  20), -INT8_C(  22), -INT8_C( 108), -INT8_C(  43),
        -INT8_C( 126), -INT8_C( 124), -INT8_C(  43),  INT8_C(  25),  INT8_C(  64),  INT8_C(  12),  INT8_C(  69), -INT8_C( 119),
        -INT8_C( 100), -INT8_C(  42), -INT8_C(   9), -INT8_C(  57), -INT8_C(  94),  INT8_C(  22),  INT8_C(  53),  INT8_C(  14),
        -INT8_C(  91),  INT8_C(  13),  INT8_C(  40), -INT8_C(  63), -INT8_C(  95),  INT8_C(  71),  INT8_C(  43),  INT8_C(  63),
        -INT8_C(  41), -INT8_C( 113),  INT8_C(  16), -INT8_C(  21),  INT8_C( 121), -INT8_C(  92), -INT8_C(  64), -INT8_C(   4) },
      UINT64_C(17357615617767242718) },
    { {  INT8_C(  21),  INT8_C( 105), -INT8_C(  94),  INT8_C(  91), -INT8_C(  14),  INT8_C(  62),  INT8_C(  49), -INT8_C(  22),
         INT8_C(   5), -INT8_C(  45),  INT8_C(   0),  INT8_C(  59), -INT8_C(  31), -INT8_C(  91),  INT8_C(  72),  INT8_C(  10),
         INT8_C( 102), -INT8_C(  23),  INT8_C(  81), -INT8_C( 111),  INT8_C(  40),  INT8_C(  40),  INT8_C(  32),  INT8_C(  56),
         INT8_C(  19), -INT8_C( 102), -INT8_C(  36), -INT8_C(  44), -INT8_C( 106),  INT8_C(   5),  INT8_C( 105), -INT8_C(  85),
         INT8_C( 110),  INT8_C(  11),  INT8_C(   6),  INT8_C(  97),  INT8_C(  73),  INT8_C(  55),  INT8_C(  75),  INT8_C(  79),
         INT8_C(  10),  INT8_C(  75), -INT8_C( 118), -INT8_C(  20), -INT8_C(  16), -INT8_C(  46), -INT8_C(  10),  INT8_C(  86),
        -INT8_C(  69),  INT8_C(  71), -INT8_C(  25), -INT8_C(  29),  INT8_C( 112),  INT8_C(   8),  INT8_C(  27), -INT8_C( 125),
        -INT8_C(  94), -INT8_C(   9),  INT8_C(  87),  INT8_C(  56), -INT8_C(   3), -INT8_C(  63), -INT8_C(  29),  INT8_C( 107) },
      {  INT8_C(  21), -INT8_C(  22), -INT8_C(  52),  INT8_C(  22), -INT8_C(  14),  INT8_C(  62),  INT8_C(  49), -INT8_C(  22),
         INT8_C(  98), -INT8_C(  17),  INT8_C(   0),  INT8_C(  82), -INT8_C(  31), -INT8_C(  91),  INT8_C(  72),  INT8_C( 124),
         INT8_C(  85), -INT8_C( 112),  INT8_C(  95), -INT8_C(  59), -INT8_C( 104),  INT8_C( 122),  INT8_C(  73),  INT8_C(  58),
         INT8_C( 113), -INT8_C(  96),  INT8_C( 114),  INT8_C( 110),  INT8_C(  97),  INT8_C(  85), -INT8_C(  38),  INT8_C(  46),
         INT8_C(  63), -INT8_C(  90),  INT8_C(  68),  INT8_C(  97), -INT8_C(  66), -INT8_C(  87), -INT8_C( 115),  INT8_C(  32),
        -INT8_C( 104), -INT8_C(  91),  INT8_C( 115),  INT8_C(  89), -INT8_C(  77),  INT8_C(  27), -INT8_C(  43),  INT8_C(   8),
        -INT8_C(  85),  INT8_C(  52), -INT8_C(  50),  INT8_C(  67), -INT8_C(  82),  INT8_C(  23),  INT8_C( 125),  INT8_C(  31),
        -INT8_C(  73), -INT8_C(  17), -INT8_C( 114),  INT8_C(  25),  INT8_C(  69),  INT8_C( 104),  INT8_C(  71), -INT8_C( 124) },
      UINT64_C(                   0) },
    { { -INT8_C(  27), -INT8_C(  52),  INT8_C(  52),  INT8_C( 114), -INT8_C(  19), -INT8_C(  52),  INT8_C(  23),  INT8_C(  96),
         INT8_C(  37), -INT8_C(  54),  INT8_C( 123), -INT8_C(   6), -INT8_C(  45),  INT8_C(  39),  INT8_C(  46), -INT8_C(  95),
         INT8_C( 106), -INT8_C(  36), -INT8_C(  72), -INT8_C(  24), -INT8_C(   5),  INT8_C( 111), -INT8_C(  41), -INT8_C( 119),
        -INT8_C( 120),  INT8_C(  28), -INT8_C(  15), -INT8_C(  49), -INT8_C(  95),  INT8_C(   0),  INT8_C(  90), -INT8_C( 122),
        -INT8_C(  52), -INT8_C( 114), -INT8_C(   7), -INT8_C(  71),  INT8_C(  90),  INT8_C(  16),  INT8_C(  25),      INT8_MAX,
        -INT8_C(  37), -INT8_C( 107),  INT8_C( 121), -INT8_C(  82), -INT8_C(  68), -INT8_C(  89),  INT8_C(  79),  INT8_C(  38),
        -INT8_C( 125),  INT8_C(   7),  INT8_C(  14),      INT8_MAX,  INT8_C( 118), -INT8_C(  26),  INT8_C(   8), -INT8_C(   1),
         INT8_C(   2), -INT8_C(   6), -INT8_C(  50), -INT8_C(  93), -INT8_C(   6),  INT8_C(  41),  INT8_C(  42), -INT8_C(  58) },
      { -INT8_C(  73), -INT8_C(  52),  INT8_C(  52),  INT8_C(  18),  INT8_C(  51), -INT8_C(  52),  INT8_C(  23),  INT8_C(  96),
         INT8_C(  37), -INT8_C(  54), -INT8_C(  68), -INT8_C(  22), -INT8_C(  78),  INT8_C(  11),  INT8_C(  17), -INT8_C(  95),
         INT8_C( 106), -INT8_C(  36), -INT8_C(  72), -INT8_C(  24), -INT8_C(   5),  INT8_C( 111), -INT8_C(  41), -INT8_C( 119),
        -INT8_C( 120),  INT8_C(  28), -INT8_C(  15), -INT8_C(  49), -INT8_C(  95),  INT8_C(   0),  INT8_C(  90), -INT8_C( 122),
        -INT8_C(  52), -INT8_C( 114), -INT8_C(   7), -INT8_C(  71),  INT8_C(  90),  INT8_C(  16),  INT8_C(  25),      INT8_MAX,
        -INT8_C(  37), -INT8_C( 107),  INT8_C( 121), -INT8_C(  82), -INT8_C(  68), -INT8_C(  89),  INT8_C(  79),  INT8_C(  38),
        -INT8_C( 125),  INT8_C(   7),  INT8_C(  14),      INT8_MAX,  INT8_C( 118), -INT8_C(  26),  INT8_C(   8), -INT8_C(   1),
         INT8_C(   2), -INT8_C(   6), -INT8_C(  50), -INT8_C(  93), -INT8_C(   6),  INT8_C(  41),  INT8_C(  42), -INT8_C(  58) },
      UINT64_C(               31769) },
    { { -INT8_C( 114), -INT8_C(  85),  INT8_C(  86), -INT8_C(  56),  INT8_C( 107),  INT8_C(  60), -INT8_C(  65),  INT8_C(  21),
        -INT8_C(  44), -INT8_C(  62), -INT8_C(  47), -INT8_C(  94), -INT8_C(  41), -INT8_C(  84),  INT8_C(  37),  INT8_C( 117),
        -INT8_C( 116),  INT8_C( 101), -INT8_C( 101),  INT8_C( 117),  INT8_C(  93),  INT8_C(  23),  INT8_C(   9),  INT8_C(   7),
         INT8_C(  19),  INT8_C( 114),  INT8_C(  40),  INT8_C(  70), -INT8_C(  44),  INT8_C(  66), -INT8_C(  62),  INT8_C(  98),
        -INT8_C(  19),  INT8_C(  25),  INT8_C(  43),  INT8_C(  88),  INT8_C(  85), -INT8_C(  22),  INT8_C( 109),  INT8_C(  41),
        -INT8_C(  84),  INT8_C(  62), -INT8_C(  53), -INT8_C( 125), -INT8_C(  22), -INT8_C(  16), -INT8_C(   8),  INT8_C( 119),
         INT8_C(  85), -INT8_C( 109), -INT8_C(  20), -INT8_C(  77), -INT8_C(  85), -INT8_C(  11), -INT8_C(  70), -INT8_C(  66),
         INT8_C( 103), -INT8_C(  30),  INT8_C(   5),  INT8_C(  60),  INT8_C(  36), -INT8_C(  57), -INT8_C(  98),  INT8_C(  17) },
      { -INT8_C( 114), -INT8_C(  55),  INT8_C( 105),  INT8_C(  53), -INT8_C(  76), -INT8_C(  41), -INT8_C(  65),  INT8_C(  96),
        -INT8_C(  44), -INT8_C(  62), -INT8_C(  28), -INT8_C(  94), -INT8_C(  41), -INT8_C(  36),  INT8_C( 119),  INT8_C( 117),
        -INT8_C( 116),  INT8_C( 101), -INT8_C( 101),  INT8_C( 117),  INT8_C(  93),  INT8_C(  23),  INT8_C(   9),  INT8_C(   7),
         INT8_C(  19),  INT8_C( 114),  INT8_C(  40),  INT8_C(  70), -INT8_C(  44),  INT8_C(  66), -INT8_C(  62),  INT8_C(  98),
        -INT8_C(  19),  INT8_C(  25),  INT8_C(  43),  INT8_C(  88),  INT8_C(  85), -INT8_C(  22),  INT8_C( 109),  INT8_C(  41),
        -INT8_C(  84),  INT8_C(  62), -INT8_C(  53), -INT8_C( 125), -INT8_C(  22), -INT8_C(  16), -INT8_C(   8),  INT8_C( 119),
         INT8_C(  85), -INT8_C( 109), -INT8_C(  20), -INT8_C(  77), -INT8_C(  85), -INT8_C(  11), -INT8_C(  70), -INT8_C(  66),
         INT8_C( 103), -INT8_C(  30),  INT8_C(   5),  INT8_C(  60),  INT8_C(  36), -INT8_C(  57), -INT8_C(  98),  INT8_C(  17) },
      UINT64_C(18446744073709525873) },
    { {  INT8_C(  76), -INT8_C(  13),  INT8_C( 126), -INT8_C(  60),  INT8_C(  62), -INT8_C(  62),  INT8_C(  32), -INT8_C( 120),
         INT8_C(  32),  INT8_C(  89),  INT8_C(  74), -INT8_C(  20),  INT8_C(   1),  INT8_C( 110), -INT8_C(  37), -INT8_C(  59),
        -INT8_C(  21), -INT8_C(  91),  INT8_C(  98),  INT8_C(  39),  INT8_C(  46), -INT8_C(  35),  INT8_C(  94), -INT8_C( 102),
        -INT8_C(   1),  INT8_C(  48), -INT8_C(   5), -INT8_C(  89),  INT8_C( 101), -INT8_C(  71),  INT8_C(  11), -INT8_C(  79),
        -INT8_C(  83), -INT8_C( 119),  INT8_C( 118), -INT8_C(  21),  INT8_C(  76), -INT8_C( 106),  INT8_C( 115),  INT8_C( 108),
        -INT8_C(  17), -INT8_C(  67),  INT8_C(  88), -INT8_C(  15),  INT8_C(  44),  INT8_C(  51), -INT8_C(  74),  INT8_C(  23),
        -INT8_C(  39),  INT8_C(  24),  INT8_C(  62),  INT8_C(   7), -INT8_C(  11), -INT8_C( 100), -INT8_C(  94), -INT8_C(  12),
        -INT8_C(  52), -INT8_C(  99), -INT8_C( 101),  INT8_C(  49),  INT8_C(  86), -INT8_C(  90), -INT8_C(  29),  INT8_C(   3) },
      {  INT8_C(  48), -INT8_C(  13),  INT8_C( 126), -INT8_C(  60), -INT8_C(  17),  INT8_C(  98), -INT8_C(  24), -INT8_C(  33),
         INT8_C(  32),  INT8_C(  64),  INT8_C(  74), -INT8_C(  20),  INT8_C( 116), -INT8_C( 122), -INT8_C(  37),  INT8_C(  77),
        -INT8_C(  98), -INT8_C(  96),  INT8_C(  84), -INT8_C( 109),  INT8_C(  61), -INT8_C(  10), -INT8_C( 120),  INT8_C(   9),
        -INT8_C( 109),  INT8_C(  35),  INT8_C(  59), -INT8_C(  22), -INT8_C(  54),  INT8_C(  30), -INT8_C(  19), -INT8_C(   6),
         INT8_C( 119), -INT8_C(  36),  INT8_C( 118),  INT8_C( 102),  INT8_C(  62),  INT8_C(  94),  INT8_C(  69),  INT8_C(  93),
        -INT8_C(  98),  INT8_C(  21), -INT8_C(  87),  INT8_C(  18), -INT8_C( 101),  INT8_C(  11),  INT8_C(  95),  INT8_C(  57),
        -INT8_C(  84), -INT8_C(  76), -INT8_C(  51), -INT8_C(  23), -INT8_C(  86),  INT8_C(  85), -INT8_C(  14),  INT8_C(  62),
         INT8_C( 120),  INT8_C(  45),  INT8_C(  40),  INT8_C(  66),  INT8_C(  75),  INT8_C(  21),  INT8_C(  60), -INT8_C(  62) },
      UINT64_C(10385078434606817873) },
    { {  INT8_C(  41),  INT8_C(  47),  INT8_C(  16),  INT8_C( 110), -INT8_C( 115), -INT8_C(  81), -INT8_C( 124),  INT8_C(  54),
        -INT8_C(  63),  INT8_C(  31),  INT8_C(  65),  INT8_C(  33),  INT8_C(  89), -INT8_C(  19), -INT8_C(  43),  INT8_C(  38),
        -INT8_C(  42),      INT8_MAX,  INT8_C( 123), -INT8_C(  55), -INT8_C(  67), -INT8_C(  13), -INT8_C(  10), -INT8_C(  27),
         INT8_C(  54),  INT8_C(  66), -INT8_C(   5),  INT8_C( 114),  INT8_C(   4), -INT8_C(  20),  INT8_C(  37),  INT8_C(  45),
         INT8_C(  28),  INT8_C(  53), -INT8_C( 100), -INT8_C(  87), -INT8_C(  28),  INT8_C(  32), -INT8_C(  33), -INT8_C(  90),
         INT8_C(  63),  INT8_C(  32), -INT8_C(  57), -INT8_C( 104),  INT8_C(  14), -INT8_C( 100), -INT8_C(  66), -INT8_C(  28),
         INT8_C(  27),  INT8_C(  57), -INT8_C(  83), -INT8_C(  39),  INT8_C(  45), -INT8_C(  92), -INT8_C(  66),  INT8_C(  99),
        -INT8_C(  26), -INT8_C(  71), -INT8_C(  43), -INT8_C(  22), -INT8_C(  90), -INT8_C(   6),  INT8_C(  24), -INT8_C(  62) },
      {  INT8_C(  41), -INT8_C(  76),  INT8_C( 107),  INT8_C( 110), -INT8_C( 115), -INT8_C(  81), -INT8_C(  70),  INT8_C(  19),
        -INT8_C(  63),  INT8_C(  31), -INT8_C(  84),  INT8_C( 120),  INT8_C(  29),  INT8_C( 106),  INT8_C(  93),  INT8_C(  38),
        -INT8_C(  42),      INT8_MAX,  INT8_C( 123), -INT8_C(  55), -INT8_C(  67), -INT8_C(  13), -INT8_C(  10), -INT8_C(  27),
         INT8_C(  54),  INT8_C(  66), -INT8_C(   5),  INT8_C( 114),  INT8_C(   4), -INT8_C(  20),  INT8_C(  37),  INT8_C(  45),
         INT8_C(  28),  INT8_C(  53), -INT8_C( 100), -INT8_C(  87), -INT8_C(  28),  INT8_C(  32), -INT8_C(  33), -INT8_C(  90),
         INT8_C(  63),  INT8_C(  32), -INT8_C(  57), -INT8_C( 104),  INT8_C(  14), -INT8_C( 100), -INT8_C(  66), -INT8_C(  28),
         INT8_C(  27),  INT8_C(  57), -INT8_C(  83), -INT8_C(  39),  INT8_C(  45), -INT8_C(  92), -INT8_C(  66),  INT8_C(  99),
        -INT8_C(  26), -INT8_C(  71), -INT8_C(  43), -INT8_C(  22), -INT8_C(  90), -INT8_C(   6),  INT8_C(  24), -INT8_C(  62) },
                          UINT64_MAX },
  };

  simde__m512i a, b;
  simde__mmask64 r;

  a = simde_mm512_loadu_si512(test_vec[0].a);
  b = simde_mm512_loadu_si512(test_vec[0].b);
  r = simde_mm512_cmp_epi8_mask(a, b, SIMDE_MM_CMPINT_EQ);
  simde_assert_equal_mmask64(r, test_vec[0].r);

  a = simde_mm512_loadu_si512(test_vec[1].a);
  b = simde_mm512_loadu_si512(test_vec[1].b);
  r = simde_mm512_cmp_epi8_mask(a, b, SIMDE_MM_CMPINT_LT);
  simde_assert_equal_mmask64(r, test_vec[1].r);

  a = simde_mm512_loadu_si512(test_vec[2].a);
  b = simde_mm512_loadu_si512(test_vec[2].b);
  r = simde_mm512_cmp_epi8_mask(a, b, SIMDE_MM_CMPINT_LE);
  simde_assert_equal_mmask64(r, test_vec[2].r);

  a = simde_mm512_loadu_si512(test_vec[3].a);
  b = simde_mm512_loadu_si512(test_vec[3].b);
  r = simde_mm512_cmp_epi8_mask(a, b, SIMDE_MM_CMPINT_FALSE);
  simde_assert_equal_mmask64(r, test_vec[3].r);

  a = simde_mm512_loadu_si512(test_vec[4].a);
  b = simde_mm512_loadu_si512(test_vec[4].b);
  r = simde_mm512_cmp_epi8_mask(a, b, SIMDE_MM_CMPINT_NE);
  simde_assert_equal_mmask64(r, test_vec[4].r);

  a = simde_mm512_loadu_si512(test_vec[5].a);
  b = simde_mm512_loadu_si512(test_vec[5].b);
  r = simde_mm512_cmp_epi8_mask(a, b, SIMDE_MM_CMPINT_NLT);
  simde_assert_equal_mmask64(r, test_vec[5].r);

  a = simde_mm512_loadu_si512(test_vec[6].a);
  b = simde_mm512_loadu_si512(test_vec[6].b);
  r = simde_mm512_cmp_epi8_mask(a, b, SIMDE_MM_CMPINT_NLE);
  simde_assert_equal_mmask64(r, test_vec[6].r);

  a = simde_mm512_loadu_si512(test_vec[7].a);
  b = simde_mm512_loadu_si512(test_vec[7].b);
  r = simde_mm512_cmp_epi8_mask(a, b, SIMDE_MM_CMPINT_TRUE);
  simde_assert_equal_mmask64(r, test_vec[7].r);

  return 0;
#else
  fputc('\n', stdout);

  simde__m512i a, b;
  simde__mmask64 r;

  a = simde_test_x86_random_i8x64();
  b = simde_test_x86_random_i8x64();
  b = simde_mm512_mask_mov_epi8(a, HEDLEY_STATIC_CAST(simde__mmask64, simde_test_codegen_random_i16()), b);
  r = simde_mm512_cmp_epi8_mask(a, b, SIMDE_MM_CMPINT_EQ);
  simde_test_x86_write_i8x64(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_i8x64(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask64(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_i8x64();
  b = simde_test_x86_random_i8x64();
  b = simde_mm512_mask_mov_epi8(a, HEDLEY_STATIC_CAST(simde__mmask64, simde_test_codegen_random_i16()), b);
  r = simde_mm512_cmp_epi8_mask(a, b, SIMDE_MM_CMPINT_LT);
  simde_test_x86_write_i8x64(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_i8x64(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask64(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_i8x64();
  b = simde_test_x86_random_i8x64();
  b = simde_mm512_mask_mov_epi8(a, HEDLEY_STATIC_CAST(simde__mmask64, simde_test_codegen_random_i16()), b);
  r = simde_mm512_cmp_epi8_mask(a, b, SIMDE_MM_CMPINT_LE);
  simde_test_x86_write_i8x64(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_i8x64(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask64(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_i8x64();
  b = simde_test_x86_random_i8x64();
  b = simde_mm512_mask_mov_epi8(a, HEDLEY_STATIC_CAST(simde__mmask64, simde_test_codegen_random_i16()), b);
  r = simde_mm512_cmp_epi8_mask(a, b, SIMDE_MM_CMPINT_FALSE);
  simde_test_x86_write_i8x64(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_i8x64(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask64(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_i8x64();
  b = simde_test_x86_random_i8x64();
  b = simde_mm512_mask_mov_epi8(a, HEDLEY_STATIC_CAST(simde__mmask64, simde_test_codegen_random_i16()), b);
  r = simde_mm512_cmp_epi8_mask(a, b, SIMDE_MM_CMPINT_NE);
  simde_test_x86_write_i8x64(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_i8x64(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask64(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_i8x64();
  b = simde_test_x86_random_i8x64();
  b = simde_mm512_mask_mov_epi8(a, HEDLEY_STATIC_CAST(simde__mmask64, simde_test_codegen_random_i16()), b);
  r = simde_mm512_cmp_epi8_mask(a, b, SIMDE_MM_CMPINT_NLT);
  simde_test_x86_write_i8x64(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_i8x64(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask64(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_i8x64();
  b = simde_test_x86_random_i8x64();
  b = simde_mm512_mask_mov_epi8(a, HEDLEY_STATIC_CAST(simde__mmask64, simde_test_codegen_random_i16()), b);
  r = simde_mm512_cmp_epi8_mask(a, b, SIMDE_MM_CMPINT_NLE);
  simde_test_x86_write_i8x64(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_i8x64(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask64(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_i8x64();
  b = simde_test_x86_random_i8x64();
  b = simde_mm512_mask_mov_epi8(a, HEDLEY_STATIC_CAST(simde__mmask64, simde_test_codegen_random_i16()), b);
  r = simde_mm512_cmp_epi8_mask(a, b, SIMDE_MM_CMPINT_TRUE);
  simde_test_x86_write_i8x64(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_i8x64(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask64(2, r, SIMDE_TEST_VEC_POS_LAST);

  return 1;
#endif
}

static int
test_simde_mm256_cmp_epi32_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int32_t a[8];
    const int32_t b[8];
    const simde__mmask8 r;
  } test_vec[] = {
    { {  INT32_C(  1197724236), -INT32_C(   743418976),  INT32_C(   710305116), -INT32_C(   339927959),  INT32_C(  1781551841),  INT32_C(    32889350),  INT32_C(  1166200694), -INT32_C(  1505432998) },
      {  INT32_C(  1197724236),  INT32_C(  1462738427),  INT32_C(   710305116), -INT32_C(  2074657118),  INT32_C(  1781551841),  INT32_C(    32889350),  INT32_C(  1166200694), -INT32_C(  1505432998) },
      UINT8_C(245) },
    { {  INT32_C(  1063013693),  INT32_C(  1990974931), -INT32_C(  1376124388), -INT32_C(   331028342),  INT32_C(  2126830795), -INT32_C(    74784010),  INT32_C(  1337802053),  INT32_C(   425057244) },
      { -INT32_C(    61230808), -INT32_C(  1418591089), -INT32_C(  1856476153),  INT32_C(   528325716),  INT32_C(  1855799672),  INT32_C(  1768564772),  INT32_C(  1337802053),  INT32_C(   710610178) },
      UINT8_C(168) },
    { { -INT32_C(  1732751834),  INT32_C(  1359265785), -INT32_C(   840083376),  INT32_C(   353330552),  INT32_C(  1027421139),  INT32_C(  1415881372),  INT32_C(  1063413476), -INT32_C(  1208802927) },
      { -INT32_C(  1732751834),  INT32_C(  1359265785),  INT32_C(   629778093), -INT32_C(   566585333),  INT32_C(  1729919179),  INT32_C(  1415881372),  INT32_C(  2017271271), -INT32_C(  1389416386) },
      UINT8_C(119) },
    { { -INT32_C(   824948971), -INT32_C(  1955299070), -INT32_C(   534544474),  INT32_C(  2052648542),  INT32_C(   301626197), -INT32_C(  1355882127), -INT32_C(  1981846183),  INT32_C(   805878554) },
      { -INT32_C(   824948971),  INT32_C(    59798365),  INT32_C(  1357165810), -INT32_C(   120963934),  INT32_C(   301626197),  INT32_C(    13645734), -INT32_C(  1081495644),  INT32_C(   805878554) },
      UINT8_C(  0) },
    { {  INT32_C(    56675186), -INT32_C(  1279831089),  INT32_C(  1861179811),  INT32_C(  1513332561), -INT32_C(  1869424192),  INT32_C(  1648309977), -INT32_C(   453727499), -INT32_C(  1965923816) },
      { -INT32_C(    57855443), -INT32_C(  1279831089),  INT32_C(  1861179811),  INT32_C(  1513332561),  INT32_C(  2106514595),  INT32_C(   148884754), -INT32_C(  1863527560),  INT32_C(  1662697013) },
      UINT8_C(241) },
    { {  INT32_C(   267155039),  INT32_C(   917408415), -INT32_C(  1006572422),  INT32_C(  2023793898),  INT32_C(     4567585), -INT32_C(  1479230022),  INT32_C(  1751451981), -INT32_C(   871344532) },
      {  INT32_C(   267155039),  INT32_C(   917408415),  INT32_C(  1606787957),  INT32_C(  1758946631), -INT32_C(   764863465), -INT32_C(  1479230022),  INT32_C(  1751451981),  INT32_C(    41918261) },
      UINT8_C(123) },
    { {  INT32_C(   300098414), -INT32_C(   373991388), -INT32_C(  1907426121), -INT32_C(   827693723), -INT32_C(  1341422537),  INT32_C(   999248300), -INT32_C(  2082749436),  INT32_C(   886929350) },
      { -INT32_C(  1102659430), -INT32_C(   373991388),  INT32_C(  1549661687), -INT32_C(  1842739110), -INT32_C(  1341422537), -INT32_C(  1955278457), -INT32_C(  2082749436),  INT32_C(  1620110534) },
      UINT8_C( 41) },
    { { -INT32_C(   976108258), -INT32_C(   222639979),  INT32_C(  1341789221), -INT32_C(   377124954),  INT32_C(   867830975), -INT32_C(  1501409129),  INT32_C(   999508139), -INT32_C(   971947864) },
      { -INT32_C(  1702108667), -INT32_C(   796047957),  INT32_C(     2066266), -INT32_C(   823548914),  INT32_C(   867830975), -INT32_C(  1501409129),  INT32_C(  1977319884), -INT32_C(   952374079) },
         UINT8_MAX },
  };

  simde__m256i a, b;
  simde__mmask8 r;

  a = simde_mm256_loadu_epi32(test_vec[0].a);
  b = simde_mm256_loadu_epi32(test_vec[0].b);
  r = simde_mm256_cmp_epi32_mask(a, b, SIMDE_MM_CMPINT_EQ);
  simde_assert_equal_mmask8(r, test_vec[0].r);

  a = simde_mm256_loadu_epi32(test_vec[1].a);
  b = simde_mm256_loadu_epi32(test_vec[1].b);
  r = simde_mm256_cmp_epi32_mask(a, b, SIMDE_MM_CMPINT_LT);
  simde_assert_equal_mmask8(r, test_vec[1].r);

  a = simde_mm256_loadu_epi32(test_vec[2].a);
  b = simde_mm256_loadu_epi32(test_vec[2].b);
  r = simde_mm256_cmp_epi32_mask(a, b, SIMDE_MM_CMPINT_LE);
  simde_assert_equal_mmask8(r, test_vec[2].r);

  a = simde_mm256_loadu_epi32(test_vec[3].a);
  b = simde_mm256_loadu_epi32(test_vec[3].b);
  r = simde_mm256_cmp_epi32_mask(a, b, SIMDE_MM_CMPINT_FALSE);
  simde_assert_equal_mmask8(r, test_vec[3].r);

  a = simde_mm256_loadu_epi32(test_vec[4].a);
  b = simde_mm256_loadu_epi32(test_vec[4].b);
  r = simde_mm256_cmp_epi32_mask(a, b, SIMDE_MM_CMPINT_NE);
  simde_assert_equal_mmask8(r, test_vec[4].r);

  a = simde_mm256_loadu_epi32(test_vec[5].a);
  b = simde_mm256_loadu_epi32(test_vec[5].b);
  r = simde_mm256_cmp_epi32_mask(a, b, SIMDE_MM_CMPINT_NLT);
  simde_assert_equal_mmask8(r, test_vec[5].r);

  a = simde_mm256_loadu_epi32(test_vec[6].a);
  b = simde_mm256_loadu_epi32(test_vec[6].b);
  r = simde_mm256_cmp_epi32_mask(a, b, SIMDE_MM_CMPINT_NLE);
  simde_assert_equal_mmask8(r, test_vec[6].r);

  a = simde_mm256_loadu_epi32(test_vec[7].a);
  b = simde_mm256_loadu_epi32(test_vec[7].b);
  r = simde_mm256_cmp_epi32_mask(a, b, SIMDE_MM_CMPINT_TRUE);
  simde_assert_equal_mmask8(r, test_vec[7].r);

  return 0;
#else
  fputc('\n', stdout);

  simde__m256i a, b;
  simde__mmask8 r;

  a = simde_test_x86_random_i32x8();
  b = simde_test_x86_random_i32x8();
  b = simde_mm256_mask_mov_epi32(a, HEDLEY_STATIC_CAST(simde__mmask8, simde_test_codegen_random_i32()), b);
  r = simde_mm256_cmp_epi32_mask(a, b, SIMDE_MM_CMPINT_EQ);
  simde_test_x86_write_i32x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_i32x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask8(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_i32x8();
  b = simde_test_x86_random_i32x8();
  b = simde_mm256_mask_mov_epi32(a, HEDLEY_STATIC_CAST(simde__mmask8, simde_test_codegen_random_i16()), b);
  r = simde_mm256_cmp_epi32_mask(a, b, SIMDE_MM_CMPINT_LT);
  simde_test_x86_write_i32x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_i32x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask8(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_i32x8();
  b = simde_test_x86_random_i32x8();
  b = simde_mm256_mask_mov_epi32(a, HEDLEY_STATIC_CAST(simde__mmask8, simde_test_codegen_random_i16()), b);
  r = simde_mm256_cmp_epi32_mask(a, b, SIMDE_MM_CMPINT_LE);
  simde_test_x86_write_i32x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_i32x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask8(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_i32x8();
  b = simde_test_x86_random_i32x8();
  b = simde_mm256_mask_mov_epi32(a, HEDLEY_STATIC_CAST(simde__mmask8, simde_test_codegen_random_i16()), b);
  r = simde_mm256_cmp_epi32_mask(a, b, SIMDE_MM_CMPINT_FALSE);
  simde_test_x86_write_i32x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_i32x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask8(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_i32x8();
  b = simde_test_x86_random_i32x8();
  b = simde_mm256_mask_mov_epi32(a, HEDLEY_STATIC_CAST(simde__mmask8, simde_test_codegen_random_i16()), b);
  r = simde_mm256_cmp_epi32_mask(a, b, SIMDE_MM_CMPINT_NE);
  simde_test_x86_write_i32x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_i32x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask8(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_i32x8();
  b = simde_test_x86_random_i32x8();
  b = simde_mm256_mask_mov_epi32(a, HEDLEY_STATIC_CAST(simde__mmask8, simde_test_codegen_random_i16()), b);
  r = simde_mm256_cmp_epi32_mask(a, b, SIMDE_MM_CMPINT_NLT);
  simde_test_x86_write_i32x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_i32x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask8(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_i32x8();
  b = simde_test_x86_random_i32x8();
  b = simde_mm256_mask_mov_epi32(a, HEDLEY_STATIC_CAST(simde__mmask8, simde_test_codegen_random_i16()), b);
  r = simde_mm256_cmp_epi32_mask(a, b, SIMDE_MM_CMPINT_NLE);
  simde_test_x86_write_i32x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_i32x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask8(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_i32x8();
  b = simde_test_x86_random_i32x8();
  b = simde_mm256_mask_mov_epi32(a, HEDLEY_STATIC_CAST(simde__mmask8, simde_test_codegen_random_i16()), b);
  r = simde_mm256_cmp_epi32_mask(a, b, SIMDE_MM_CMPINT_TRUE);
  simde_test_x86_write_i32x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_i32x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask8(2, r, SIMDE_TEST_VEC_POS_LAST);

  return 1;
#endif
}

static int
test_simde_mm512_cmp_epi16_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int16_t a[32];
    const int16_t b[32];
    const simde__mmask32 r;
  } test_vec[] = {
    { { -INT16_C( 17055),  INT16_C(  9100), -INT16_C(  5472),  INT16_C( 29936),  INT16_C( 22231), -INT16_C( 23035), -INT16_C(  7257), -INT16_C( 15461),
         INT16_C( 14879), -INT16_C( 31143),  INT16_C( 14570), -INT16_C( 21714), -INT16_C( 13436),  INT16_C(  1926),  INT16_C( 10783), -INT16_C( 32657),
        -INT16_C(  1049), -INT16_C( 30813), -INT16_C( 27675), -INT16_C( 16900),  INT16_C(   489), -INT16_C( 28573), -INT16_C(   283),  INT16_C(  1108),
        -INT16_C( 21191),  INT16_C(  9099), -INT16_C( 17946),  INT16_C( 27343),  INT16_C( 21892), -INT16_C( 23695), -INT16_C(  7809),  INT16_C( 26403) },
      { -INT16_C( 17055), -INT16_C( 15634), -INT16_C(  5472),  INT16_C( 17535), -INT16_C(  7444), -INT16_C( 11820),  INT16_C( 10464), -INT16_C( 15461),
         INT16_C( 14879), -INT16_C( 17347),  INT16_C(  3097), -INT16_C( 25050), -INT16_C( 26527), -INT16_C(  8127),  INT16_C( 25977),  INT16_C( 21831),
         INT16_C( 13868), -INT16_C( 31209), -INT16_C( 27104),  INT16_C(  3274), -INT16_C( 24712),  INT16_C( 23005), -INT16_C( 19513), -INT16_C( 25230),
        -INT16_C( 20717),  INT16_C( 11609), -INT16_C( 32581),  INT16_C(  7371),  INT16_C(  3096), -INT16_C( 28163),  INT16_C( 17521), -INT16_C( 25114) },
      UINT32_C(       389) },
    { { -INT16_C( 25820), -INT16_C(  4460),  INT16_C(  3495), -INT16_C( 31347),  INT16_C( 21862), -INT16_C( 10184),  INT16_C( 19442),  INT16_C( 19592),
         INT16_C( 17272),  INT16_C( 17356), -INT16_C(  7072),  INT16_C( 23888), -INT16_C( 16011),  INT16_C( 23457),  INT16_C(  7263), -INT16_C( 31911),
        -INT16_C(  4425),  INT16_C( 24177), -INT16_C(     5),  INT16_C( 25059),  INT16_C(  6996),  INT16_C( 17977), -INT16_C( 16025), -INT16_C(  8302),
         INT16_C( 24069),  INT16_C( 25891),  INT16_C( 29506), -INT16_C( 18494),  INT16_C( 25396), -INT16_C( 27885),  INT16_C( 27775),  INT16_C( 13846) },
      { -INT16_C( 25820), -INT16_C(  4460),  INT16_C(  3495), -INT16_C(  9290),  INT16_C( 21862), -INT16_C( 10184), -INT16_C( 19279), -INT16_C( 18726),
         INT16_C( 17272),  INT16_C( 17356), -INT16_C(  7072),  INT16_C( 23888),  INT16_C(  8001),  INT16_C( 23457),  INT16_C( 20364), -INT16_C( 31911),
        -INT16_C(  4425),  INT16_C( 24177), -INT16_C(     5),  INT16_C( 25059),  INT16_C(  6996),  INT16_C( 17977), -INT16_C( 16025), -INT16_C(  8302),
         INT16_C( 24069),  INT16_C( 25891),  INT16_C( 29506), -INT16_C( 18494),  INT16_C( 25396), -INT16_C( 27885),  INT16_C( 27775),  INT16_C( 13846) },
      UINT32_C(     20488) },
    { { -INT16_C( 13251),  INT16_C( 30275),  INT16_C(  9573), -INT16_C(  1839), -INT16_C(  8263),  INT16_C(  1126), -INT16_C( 11776),  INT16_C( 30314),
        -INT16_C( 21074),  INT16_C( 12281), -INT16_C( 25806),  INT16_C( 30696), -INT16_C(  3639), -INT16_C(  8781),  INT16_C( 31696),  INT16_C(  3630),
         INT16_C( 28999), -INT16_C( 21372),  INT16_C( 21910),  INT16_C( 20645),  INT16_C(  2869),  INT16_C( 13652), -INT16_C( 16675), -INT16_C( 29780),
        -INT16_C( 23189), -INT16_C( 25158), -INT16_C( 23744),  INT16_C(  2324), -INT16_C( 14444),  INT16_C( 25830),  INT16_C(  5186), -INT16_C( 30094) },
      { -INT16_C(  2171),  INT16_C( 30275),  INT16_C(  9573), -INT16_C(  1839), -INT16_C(  8263),  INT16_C(  1126),  INT16_C( 25470),  INT16_C( 30314),
         INT16_C(  2568),  INT16_C( 18567), -INT16_C( 25806),  INT16_C( 16721),  INT16_C( 14179), -INT16_C(  8781),  INT16_C(  6220), -INT16_C( 11985),
         INT16_C( 26127),  INT16_C( 23789),  INT16_C( 22849),  INT16_C( 10461), -INT16_C( 27623), -INT16_C( 26643),  INT16_C( 15863), -INT16_C(   127),
         INT16_C(  2119), -INT16_C(  2745), -INT16_C( 26461),  INT16_C(  1590), -INT16_C(  9008),  INT16_C(  7340), -INT16_C(  9227),  INT16_C(  1261) },
      UINT32_C(2479241215) },
    { { -INT16_C( 31904),  INT16_C( 15924),  INT16_C( 20139), -INT16_C( 26414), -INT16_C( 13595),  INT16_C( 26325),  INT16_C(  7625),  INT16_C(  4462),
         INT16_C(  4626),  INT16_C( 18601),  INT16_C( 31000), -INT16_C( 15323),  INT16_C(  6805), -INT16_C( 31840), -INT16_C(  7906),  INT16_C( 32606),
        -INT16_C( 28060),  INT16_C(  4285), -INT16_C( 28704), -INT16_C( 14680),  INT16_C( 32345),  INT16_C(  9004), -INT16_C( 25701), -INT16_C( 21196),
        -INT16_C(  8787), -INT16_C( 14859),  INT16_C(  6743), -INT16_C(  4982),  INT16_C( 10804),  INT16_C( 21359), -INT16_C( 13045),  INT16_C( 28882) },
      { -INT16_C( 28832),  INT16_C( 16512),  INT16_C( 10270),  INT16_C( 30726), -INT16_C( 13595),  INT16_C( 16795),  INT16_C(  7625),  INT16_C( 31726),
         INT16_C(  4626),  INT16_C(   832), -INT16_C( 13570),  INT16_C( 13296),  INT16_C(  6805),  INT16_C(   134),  INT16_C( 22573),  INT16_C( 32606),
        -INT16_C( 28060),  INT16_C(  4285), -INT16_C( 28704), -INT16_C( 14680),  INT16_C( 32345),  INT16_C(  9004), -INT16_C( 25701), -INT16_C( 21196),
        -INT16_C(  8787), -INT16_C( 14859),  INT16_C(  6743), -INT16_C(  4982),  INT16_C( 10804),  INT16_C( 21359), -INT16_C( 13045),  INT16_C( 28882) },
      UINT32_C(         0) },
    { { -INT16_C( 14129),  INT16_C( 19522),  INT16_C( 18823), -INT16_C( 30875),  INT16_C( 19486),  INT16_C( 28278),  INT16_C( 18912),  INT16_C( 30975),
         INT16_C( 23067),  INT16_C(  8191), -INT16_C(  6487), -INT16_C(  1622), -INT16_C( 29446), -INT16_C( 25672),  INT16_C( 26710),  INT16_C(  9482),
         INT16_C( 19504), -INT16_C( 18575), -INT16_C( 10602), -INT16_C( 19394), -INT16_C( 19165),  INT16_C(   803),  INT16_C(  8958),  INT16_C(  6523),
         INT16_C( 31612),  INT16_C(  9529), -INT16_C(  7327),  INT16_C( 23582), -INT16_C( 10385), -INT16_C( 14857),  INT16_C(   319),  INT16_C( 28650) },
      { -INT16_C( 14129), -INT16_C(  7130),  INT16_C( 18823), -INT16_C( 30875), -INT16_C( 17639),  INT16_C(  6233), -INT16_C( 11043),  INT16_C( 30975),
         INT16_C( 23067), -INT16_C( 20097), -INT16_C(  6487), -INT16_C(  1622), -INT16_C( 29446), -INT16_C( 19582),  INT16_C( 26710),  INT16_C(  9482),
         INT16_C( 19504), -INT16_C( 18575), -INT16_C( 10602), -INT16_C( 19394), -INT16_C( 19165),  INT16_C(   803),  INT16_C(  8958),  INT16_C(  6523),
         INT16_C( 31612),  INT16_C(  9529), -INT16_C(  7327),  INT16_C( 23582), -INT16_C( 10385), -INT16_C( 14857),  INT16_C(   319),  INT16_C( 28650) },
      UINT32_C(      8818) },
    { {  INT16_C(  7993), -INT16_C( 29965),  INT16_C( 32742), -INT16_C( 15308), -INT16_C( 19736), -INT16_C( 21548),  INT16_C( 20352), -INT16_C(    19),
        -INT16_C( 13033), -INT16_C( 25461),  INT16_C(  7201),  INT16_C( 10403),  INT16_C(  6322), -INT16_C( 25262), -INT16_C( 15019), -INT16_C( 28993),
        -INT16_C( 19740), -INT16_C( 13800),  INT16_C( 19505),  INT16_C(  6799),  INT16_C( 25599),  INT16_C( 32709), -INT16_C( 19534), -INT16_C( 13953),
         INT16_C(  2688), -INT16_C( 24219),  INT16_C(  2342), -INT16_C(  9783),  INT16_C(  7201),  INT16_C( 30326),  INT16_C( 13793), -INT16_C( 15099) },
      {  INT16_C(  7993),  INT16_C(  6544),  INT16_C(  8042),  INT16_C( 26931), -INT16_C( 19736), -INT16_C( 21548),  INT16_C( 20352), -INT16_C(    19),
        -INT16_C( 13033), -INT16_C( 26419), -INT16_C( 27027), -INT16_C( 29071),  INT16_C(  6322), -INT16_C( 27900),  INT16_C(  2333),  INT16_C(  1369),
        -INT16_C(  5849), -INT16_C( 28386),  INT16_C( 21000), -INT16_C( 29958), -INT16_C(  7605), -INT16_C(  2113), -INT16_C( 16822), -INT16_C( 17373),
        -INT16_C(  4062), -INT16_C( 28844), -INT16_C( 14714),  INT16_C( 14621),  INT16_C(  8621), -INT16_C( 13620),  INT16_C(  9515),  INT16_C( 21199) },
      UINT32_C(1740259317) },
    { {  INT16_C(  5859), -INT16_C(  8896), -INT16_C( 29791),  INT16_C( 24767),  INT16_C(  2434), -INT16_C( 23266),  INT16_C( 16581),  INT16_C(  6805),
         INT16_C(  7119), -INT16_C(  4896), -INT16_C( 29356),  INT16_C(  8462),  INT16_C( 14680),  INT16_C( 10054),  INT16_C( 21899),  INT16_C( 28181),
         INT16_C( 21867),  INT16_C(  3147),  INT16_C(  2784),  INT16_C( 25197), -INT16_C( 29932), -INT16_C(  9977), -INT16_C( 25396), -INT16_C( 25613),
        -INT16_C( 11336),  INT16_C(  3208), -INT16_C( 27039), -INT16_C( 18131),  INT16_C( 29903),  INT16_C( 23264), -INT16_C(  2359),  INT16_C( 13512) },
      {  INT16_C(  5859),  INT16_C( 11329), -INT16_C( 20963),  INT16_C( 12686), -INT16_C( 27079),  INT16_C(  1291), -INT16_C(   462), -INT16_C(  5471),
         INT16_C( 10706),  INT16_C( 13303), -INT16_C( 29356),  INT16_C(  8462),  INT16_C( 14680),  INT16_C( 25064), -INT16_C( 20286),  INT16_C(  3734),
        -INT16_C( 10301), -INT16_C(  8134), -INT16_C( 14203), -INT16_C( 16878),  INT16_C(  7518), -INT16_C( 28220),  INT16_C( 25883), -INT16_C(  4741),
         INT16_C( 29326),  INT16_C( 19744),  INT16_C(  3223),  INT16_C( 12251), -INT16_C( 15399), -INT16_C( 25711),  INT16_C( 10099),  INT16_C( 13993) },
      UINT32_C( 808435928) },
    { { -INT16_C( 31978),  INT16_C( 10412),  INT16_C(  2625),  INT16_C(  1349),  INT16_C( 24987),  INT16_C(  5994), -INT16_C(  1970),  INT16_C( 28553),
         INT16_C(  8261),  INT16_C(  8315),  INT16_C( 21584), -INT16_C(  7709),  INT16_C( 22256), -INT16_C( 26360),  INT16_C(  1676), -INT16_C( 23683),
         INT16_C( 10633), -INT16_C( 13621),  INT16_C(  4403), -INT16_C( 12336),  INT16_C( 14962), -INT16_C( 16154),  INT16_C( 28467),  INT16_C( 30767),
        -INT16_C( 21616), -INT16_C(  8039),  INT16_C( 31999), -INT16_C(  4159), -INT16_C( 13869),  INT16_C( 24457),  INT16_C(  1743),  INT16_C( 22530) },
      { -INT16_C( 12753),  INT16_C( 10412), -INT16_C(  3361),  INT16_C(  1349),  INT16_C(  5933),  INT16_C(  5994),  INT16_C( 16775),  INT16_C(  6104),
         INT16_C(  8261),  INT16_C(  8315),  INT16_C( 21584), -INT16_C( 15909),  INT16_C( 22256), -INT16_C( 26360),  INT16_C(  1676), -INT16_C( 26200),
        -INT16_C( 13583), -INT16_C( 12037),  INT16_C( 11709), -INT16_C(  5599),  INT16_C( 12868), -INT16_C( 13494),  INT16_C(  8819),  INT16_C( 24546),
        -INT16_C(  9836), -INT16_C( 32181),  INT16_C(  9873),  INT16_C(  4675),  INT16_C( 25482), -INT16_C(  2974),  INT16_C(  2694),  INT16_C( 30605) },
                UINT32_MAX },
  };

  simde__m512i a, b;
  simde__mmask32 r;

  a = simde_mm512_loadu_si512(test_vec[0].a);
  b = simde_mm512_loadu_si512(test_vec[0].b);
  r = simde_mm512_cmp_epi16_mask(a, b, SIMDE_MM_CMPINT_EQ);
  simde_assert_equal_mmask32(r, test_vec[0].r);

  a = simde_mm512_loadu_si512(test_vec[1].a);
  b = simde_mm512_loadu_si512(test_vec[1].b);
  r = simde_mm512_cmp_epi16_mask(a, b, SIMDE_MM_CMPINT_LT);
  simde_assert_equal_mmask32(r, test_vec[1].r);

  a = simde_mm512_loadu_si512(test_vec[2].a);
  b = simde_mm512_loadu_si512(test_vec[2].b);
  r = simde_mm512_cmp_epi16_mask(a, b, SIMDE_MM_CMPINT_LE);
  simde_assert_equal_mmask32(r, test_vec[2].r);

  a = simde_mm512_loadu_si512(test_vec[3].a);
  b = simde_mm512_loadu_si512(test_vec[3].b);
  r = simde_mm512_cmp_epi16_mask(a, b, SIMDE_MM_CMPINT_FALSE);
  simde_assert_equal_mmask32(r, test_vec[3].r);

  a = simde_mm512_loadu_si512(test_vec[4].a);
  b = simde_mm512_loadu_si512(test_vec[4].b);
  r = simde_mm512_cmp_epi16_mask(a, b, SIMDE_MM_CMPINT_NE);
  simde_assert_equal_mmask32(r, test_vec[4].r);

  a = simde_mm512_loadu_si512(test_vec[5].a);
  b = simde_mm512_loadu_si512(test_vec[5].b);
  r = simde_mm512_cmp_epi16_mask(a, b, SIMDE_MM_CMPINT_NLT);
  simde_assert_equal_mmask32(r, test_vec[5].r);

  a = simde_mm512_loadu_si512(test_vec[6].a);
  b = simde_mm512_loadu_si512(test_vec[6].b);
  r = simde_mm512_cmp_epi16_mask(a, b, SIMDE_MM_CMPINT_NLE);
  simde_assert_equal_mmask32(r, test_vec[6].r);

  a = simde_mm512_loadu_si512(test_vec[7].a);
  b = simde_mm512_loadu_si512(test_vec[7].b);
  r = simde_mm512_cmp_epi16_mask(a, b, SIMDE_MM_CMPINT_TRUE);
  simde_assert_equal_mmask32(r, test_vec[7].r);

  return 0;
#else
  fputc('\n', stdout);

  simde__m512i a, b;
  simde__mmask32 r;

  a = simde_test_x86_random_i16x32();
  b = simde_test_x86_random_i16x32();
  b = simde_mm512_mask_mov_epi16(a, HEDLEY_STATIC_CAST(simde__mmask32, simde_test_codegen_random_i16()), b);
  r = simde_mm512_cmp_epi16_mask(a, b, SIMDE_MM_CMPINT_EQ);
  simde_test_x86_write_i16x32(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_i16x32(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask32(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_i16x32();
  b = simde_test_x86_random_i16x32();
  b = simde_mm512_mask_mov_epi16(a, HEDLEY_STATIC_CAST(simde__mmask32, simde_test_codegen_random_i16()), b);
  r = simde_mm512_cmp_epi16_mask(a, b, SIMDE_MM_CMPINT_LT);
  simde_test_x86_write_i16x32(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_i16x32(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask32(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_i16x32();
  b = simde_test_x86_random_i16x32();
  b = simde_mm512_mask_mov_epi16(a, HEDLEY_STATIC_CAST(simde__mmask32, simde_test_codegen_random_i16()), b);
  r = simde_mm512_cmp_epi16_mask(a, b, SIMDE_MM_CMPINT_LE);
  simde_test_x86_write_i16x32(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_i16x32(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask32(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_i16x32();
  b = simde_test_x86_random_i16x32();
  b = simde_mm512_mask_mov_epi16(a, HEDLEY_STATIC_CAST(simde__mmask32, simde_test_codegen_random_i16()), b);
  r = simde_mm512_cmp_epi16_mask(a, b, SIMDE_MM_CMPINT_FALSE);
  simde_test_x86_write_i16x32(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_i16x32(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask32(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_i16x32();
  b = simde_test_x86_random_i16x32();
  b = simde_mm512_mask_mov_epi16(a, HEDLEY_STATIC_CAST(simde__mmask32, simde_test_codegen_random_i16()), b);
  r = simde_mm512_cmp_epi16_mask(a, b, SIMDE_MM_CMPINT_NE);
  simde_test_x86_write_i16x32(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_i16x32(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask32(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_i16x32();
  b = simde_test_x86_random_i16x32();
  b = simde_mm512_mask_mov_epi16(a, HEDLEY_STATIC_CAST(simde__mmask32, simde_test_codegen_random_i16()), b);
  r = simde_mm512_cmp_epi16_mask(a, b, SIMDE_MM_CMPINT_NLT);
  simde_test_x86_write_i16x32(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_i16x32(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask32(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_i16x32();
  b = simde_test_x86_random_i16x32();
  b = simde_mm512_mask_mov_epi16(a, HEDLEY_STATIC_CAST(simde__mmask32, simde_test_codegen_random_i16()), b);
  r = simde_mm512_cmp_epi16_mask(a, b, SIMDE_MM_CMPINT_NLE);
  simde_test_x86_write_i16x32(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_i16x32(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask32(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_i16x32();
  b = simde_test_x86_random_i16x32();
  b = simde_mm512_mask_mov_epi16(a, HEDLEY_STATIC_CAST(simde__mmask32, simde_test_codegen_random_i16()), b);
  r = simde_mm512_cmp_epi16_mask(a, b, SIMDE_MM_CMPINT_TRUE);
  simde_test_x86_write_i16x32(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_i16x32(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask32(2, r, SIMDE_TEST_VEC_POS_LAST);

  return 1;
#endif
}

static int
test_simde_mm512_mask_cmp_epi16_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask32 k1;
    const int16_t a[32];
    const int16_t b[32];
    const simde__mmask32 r;
  } test_vec[] = {
    { UINT32_C(3623225928),
      {  INT16_C( 19410),  INT16_C( 25691),  INT16_C( 16998), -INT16_C( 25485), -INT16_C( 16818), -INT16_C( 26994),  INT16_C( 18870),  INT16_C(  5546),
        -INT16_C( 17619), -INT16_C( 22696), -INT16_C(   543),  INT16_C( 20702), -INT16_C( 22900), -INT16_C( 11069), -INT16_C( 17999), -INT16_C( 31829),
         INT16_C(  1540),  INT16_C( 27624),  INT16_C( 23368), -INT16_C( 26873), -INT16_C( 27366), -INT16_C( 12243), -INT16_C( 10274),  INT16_C(  3301),
         INT16_C( 16019),  INT16_C( 29875), -INT16_C( 28357), -INT16_C( 14396), -INT16_C( 30664), -INT16_C(  5732),  INT16_C( 18241),  INT16_C( 18028) },
      {  INT16_C( 19410),  INT16_C( 25691),  INT16_C( 16998), -INT16_C( 13779),  INT16_C( 23118), -INT16_C( 26994), -INT16_C( 32718),  INT16_C(  5546),
        -INT16_C( 17619), -INT16_C(  1735), -INT16_C(   387),  INT16_C( 20702), -INT16_C( 22900), -INT16_C( 14434),  INT16_C(  2980), -INT16_C(  3571),
        -INT16_C( 16801),  INT16_C(  3976), -INT16_C( 18825), -INT16_C( 14887),  INT16_C( 29712),  INT16_C( 17137),  INT16_C( 10996), -INT16_C( 19961),
         INT16_C( 16662), -INT16_C( 27733),  INT16_C( 27455), -INT16_C( 15031), -INT16_C(  6200),  INT16_C( 27788), -INT16_C( 25870),  INT16_C( 21086) },
      UINT32_C(      2048) },
    { UINT32_C(1000132449),
      { -INT16_C( 21100), -INT16_C( 31057), -INT16_C( 23569), -INT16_C(  2128), -INT16_C( 14763),  INT16_C(    56),  INT16_C( 30553), -INT16_C( 23957),
         INT16_C( 13116), -INT16_C( 14198),  INT16_C( 31903), -INT16_C(   670), -INT16_C( 17458),  INT16_C( 12516), -INT16_C( 32630),  INT16_C(  8043),
         INT16_C(  6701),  INT16_C(  7589),  INT16_C( 21949),  INT16_C(  4628),  INT16_C( 19483),  INT16_C( 29714),  INT16_C( 32195), -INT16_C(   233),
        -INT16_C( 24143),  INT16_C( 20679),  INT16_C( 10781), -INT16_C(  5042),  INT16_C( 13029),  INT16_C( 28444), -INT16_C( 30798), -INT16_C(  8050) },
      { -INT16_C( 21100),  INT16_C( 24317),  INT16_C(  4488), -INT16_C(  2128), -INT16_C( 14763),  INT16_C(    56),  INT16_C( 12287), -INT16_C( 23957),
         INT16_C( 13116), -INT16_C( 14198),  INT16_C( 20240), -INT16_C(  2599), -INT16_C(  2687),  INT16_C( 13157), -INT16_C( 32630),  INT16_C(  8043),
         INT16_C(  6701),  INT16_C(  7589),  INT16_C( 21949),  INT16_C(  4628),  INT16_C( 19483),  INT16_C( 29714),  INT16_C( 32195), -INT16_C(   233),
        -INT16_C( 24143),  INT16_C( 20679),  INT16_C( 10781), -INT16_C(  5042),  INT16_C( 13029),  INT16_C( 28444), -INT16_C( 30798), -INT16_C(  8050) },
      UINT32_C(         0) },
    { UINT32_C( 740779993),
      { -INT16_C( 27162), -INT16_C( 31593),  INT16_C( 12546),  INT16_C(  8002), -INT16_C(  6501), -INT16_C(  3522), -INT16_C( 21606),  INT16_C( 17443),
         INT16_C( 19098), -INT16_C( 17325),  INT16_C( 22253), -INT16_C( 21007),  INT16_C( 14207),  INT16_C( 22761),  INT16_C(  4511), -INT16_C( 31356),
         INT16_C(  7078), -INT16_C( 22519),  INT16_C( 19276), -INT16_C(  6201),  INT16_C(  1329), -INT16_C( 13094), -INT16_C(   591),  INT16_C( 19216),
         INT16_C( 25671),  INT16_C( 13319), -INT16_C(  1862),  INT16_C( 14818), -INT16_C( 13520), -INT16_C( 12398),  INT16_C(  5852), -INT16_C( 32172) },
      { -INT16_C( 27162),  INT16_C( 32298), -INT16_C(  3415),  INT16_C(  8002), -INT16_C(  6501), -INT16_C(  3522), -INT16_C( 21606), -INT16_C( 31245),
        -INT16_C(  1509), -INT16_C( 10823),  INT16_C( 22253),  INT16_C(  8974),  INT16_C( 14207),  INT16_C( 17394),  INT16_C(  4511), -INT16_C( 31356),
         INT16_C(  7078), -INT16_C( 22519),  INT16_C( 19276), -INT16_C(  6201),  INT16_C(  1329), -INT16_C( 13094), -INT16_C(   591),  INT16_C( 19216),
         INT16_C( 25671),  INT16_C( 13319), -INT16_C(  1862),  INT16_C( 14818), -INT16_C( 13520), -INT16_C( 12398),  INT16_C(  5852), -INT16_C( 32172) },
      UINT32_C( 740771417) },
    { UINT32_C(3589826734),
      {  INT16_C(  1602), -INT16_C( 14941),  INT16_C( 10065),  INT16_C(  8507), -INT16_C( 21561),  INT16_C( 15274), -INT16_C( 12529), -INT16_C( 27202),
        -INT16_C(  7589),  INT16_C( 11022), -INT16_C( 13124), -INT16_C( 32576),  INT16_C( 17966), -INT16_C(  8789), -INT16_C( 23633), -INT16_C(  3662),
         INT16_C( 21929), -INT16_C(  1354), -INT16_C(  3715),  INT16_C( 17435), -INT16_C( 14691), -INT16_C( 21377),  INT16_C( 16021), -INT16_C(  3775),
         INT16_C( 20256), -INT16_C(  9188), -INT16_C(  9188),  INT16_C( 19036),  INT16_C(  1827), -INT16_C( 11737), -INT16_C(  9557),  INT16_C( 21699) },
      {  INT16_C(  1602), -INT16_C( 21425),  INT16_C( 10065),  INT16_C(  2288), -INT16_C( 21561),  INT16_C( 15274), -INT16_C(  2386), -INT16_C( 27202),
        -INT16_C( 11451),  INT16_C( 25002), -INT16_C( 13124), -INT16_C( 11604), -INT16_C( 11506), -INT16_C( 18012), -INT16_C( 23633), -INT16_C(  3662),
         INT16_C( 21929), -INT16_C(  1354), -INT16_C(  3715),  INT16_C( 17435), -INT16_C( 14691), -INT16_C( 21377),  INT16_C( 16021), -INT16_C(  3775),
         INT16_C( 20256), -INT16_C(  9188), -INT16_C(  9188),  INT16_C( 19036),  INT16_C(  1827), -INT16_C( 11737), -INT16_C(  9557),  INT16_C( 21699) },
      UINT32_C(         0) },
    { UINT32_C(1555370502),
      { -INT16_C( 24822), -INT16_C( 14234),  INT16_C( 26423), -INT16_C( 25283), -INT16_C( 31315),  INT16_C( 21677), -INT16_C( 14980),  INT16_C( 18088),
        -INT16_C( 12309), -INT16_C( 13643), -INT16_C( 29789),  INT16_C( 21944),  INT16_C(   580),  INT16_C( 19088),  INT16_C( 17684),  INT16_C(  7846),
         INT16_C(  3300),  INT16_C(  7142),  INT16_C(  9075),  INT16_C(  8376),  INT16_C( 26024),  INT16_C(  9589),  INT16_C(  7466),  INT16_C(  5483),
         INT16_C(  8428), -INT16_C( 28704), -INT16_C( 26452), -INT16_C(  3868),  INT16_C( 29850), -INT16_C( 20678), -INT16_C(  8007), -INT16_C( 25139) },
      { -INT16_C( 19220),  INT16_C( 24760),  INT16_C( 28887), -INT16_C( 25283), -INT16_C(  2602),  INT16_C(   165),  INT16_C(  4114),  INT16_C( 18088),
        -INT16_C( 12309), -INT16_C(  8818),  INT16_C( 29326),  INT16_C( 21944),  INT16_C(  2023), -INT16_C( 24361),  INT16_C( 17684),  INT16_C(  7846),
         INT16_C(  3300),  INT16_C(  7142),  INT16_C(  9075),  INT16_C(  8376),  INT16_C( 26024),  INT16_C(  9589),  INT16_C(  7466),  INT16_C(  5483),
         INT16_C(  8428), -INT16_C( 28704), -INT16_C( 26452), -INT16_C(  3868),  INT16_C( 29850), -INT16_C( 20678), -INT16_C(  8007), -INT16_C( 25139) },
      UINT32_C(      4614) },
    { UINT32_C(3068845574),
      { -INT16_C( 27877),  INT16_C( 22540),  INT16_C( 29263),  INT16_C(  2732), -INT16_C(  2807),  INT16_C( 32082),  INT16_C(  3533), -INT16_C( 12866),
         INT16_C(  1711), -INT16_C(  3420),  INT16_C(  8501),  INT16_C( 14194), -INT16_C(  5642), -INT16_C(   915),  INT16_C( 22471), -INT16_C(  7501),
        -INT16_C( 16405),  INT16_C( 14907), -INT16_C(  6351),  INT16_C( 14916), -INT16_C( 26660), -INT16_C( 22089),  INT16_C( 30116),  INT16_C( 21622),
         INT16_C(  7035), -INT16_C( 20410), -INT16_C( 18372),  INT16_C( 13031),  INT16_C( 21922),  INT16_C( 26927), -INT16_C(  7508), -INT16_C( 26804) },
      { -INT16_C( 27877),  INT16_C( 22540),  INT16_C(  5742),  INT16_C(  2732), -INT16_C(  2807),  INT16_C( 21236),  INT16_C( 27192), -INT16_C( 12866),
        -INT16_C(  4987), -INT16_C( 16029),  INT16_C(  8501),  INT16_C( 18164),  INT16_C(  9119), -INT16_C(   915),  INT16_C( 22471), -INT16_C(  7501),
        -INT16_C( 16405),  INT16_C( 14907), -INT16_C(  6351),  INT16_C( 14916), -INT16_C( 26660), -INT16_C( 22089),  INT16_C( 30116),  INT16_C( 21622),
         INT16_C(  7035), -INT16_C( 20410), -INT16_C( 18372),  INT16_C( 13031),  INT16_C( 21922),  INT16_C( 26927), -INT16_C(  7508), -INT16_C( 26804) },
      UINT32_C(3068839430) },
    { UINT32_C(2761896040),
      { -INT16_C(  6487),  INT16_C( 30163),  INT16_C( 28005), -INT16_C( 26650),  INT16_C( 17549),  INT16_C( 28204),  INT16_C(  2886), -INT16_C( 29117),
         INT16_C( 15242),  INT16_C( 21895),  INT16_C( 31544), -INT16_C(  9468),  INT16_C( 26867),  INT16_C( 23542), -INT16_C( 27240),  INT16_C( 16895),
        -INT16_C( 11397), -INT16_C(  8010), -INT16_C( 25280), -INT16_C( 12937), -INT16_C( 23583),  INT16_C( 10043),  INT16_C( 32430),  INT16_C( 14773),
         INT16_C( 15545), -INT16_C(  3698), -INT16_C( 27976), -INT16_C( 21556), -INT16_C( 15622), -INT16_C( 28154),  INT16_C(  1623), -INT16_C( 11564) },
      { -INT16_C( 29991),  INT16_C(  6578),  INT16_C( 10535), -INT16_C( 26650),  INT16_C(  8908),  INT16_C( 31535),  INT16_C(  2886),  INT16_C( 23220),
         INT16_C( 15242), -INT16_C(  9908),  INT16_C(  6357), -INT16_C( 12412),  INT16_C( 26867),  INT16_C( 23542), -INT16_C( 27240),  INT16_C( 27141),
        -INT16_C( 18496), -INT16_C(  6013),  INT16_C( 27361), -INT16_C( 21008),  INT16_C(  8333),  INT16_C( 11816), -INT16_C(  9211),  INT16_C(  9864),
        -INT16_C( 11233), -INT16_C(  3072), -INT16_C( 31507), -INT16_C( 14141),  INT16_C(  9487), -INT16_C( 24326), -INT16_C(   165),  INT16_C(  7178) },
      UINT32_C(  76087296) },
    { UINT32_C(4109932548),
      { -INT16_C( 31419),  INT16_C( 28180),  INT16_C(  6579),  INT16_C( 15434),  INT16_C( 26944),  INT16_C( 16400), -INT16_C(   675),  INT16_C(  8644),
        -INT16_C( 11067), -INT16_C( 16314), -INT16_C( 23948),  INT16_C( 32703),  INT16_C( 30398), -INT16_C( 15859),  INT16_C(  1294),  INT16_C( 21686),
        -INT16_C( 13429),  INT16_C( 16066),  INT16_C(  3300),  INT16_C(  9338), -INT16_C( 29834), -INT16_C( 11420),  INT16_C( 10632),  INT16_C( 20212),
         INT16_C( 15357),  INT16_C( 28942), -INT16_C( 12835), -INT16_C( 25616), -INT16_C(   700),  INT16_C( 21085),  INT16_C(  4867), -INT16_C( 29018) },
      {  INT16_C( 26846),  INT16_C( 28180),  INT16_C(  6579),  INT16_C( 15434),  INT16_C( 26944),  INT16_C( 16400), -INT16_C(   675),  INT16_C( 29352),
        -INT16_C( 11067), -INT16_C( 16314), -INT16_C( 23948),  INT16_C( 32703),  INT16_C( 30398), -INT16_C( 11238), -INT16_C( 15914), -INT16_C( 19102),
         INT16_C( 12073), -INT16_C( 24968),  INT16_C( 24438),  INT16_C( 18569),  INT16_C( 18603),  INT16_C(  8354),  INT16_C( 19451), -INT16_C(  5742),
         INT16_C( 30209), -INT16_C( 31308),  INT16_C(  6730),  INT16_C(  6989),  INT16_C( 26845), -INT16_C( 19472),  INT16_C( 21033),  INT16_C( 21096) },
      UINT32_C(4109932548) },
  };

  simde__m512i a, b;
  simde__mmask32 r;

  a = simde_mm512_loadu_si512(test_vec[0].a);
  b = simde_mm512_loadu_si512(test_vec[0].b);
  r = simde_mm512_mask_cmp_epi16_mask(test_vec[0].k1, a, b, SIMDE_MM_CMPINT_EQ);
  simde_assert_equal_mmask32(r, test_vec[0].r);

  a = simde_mm512_loadu_si512(test_vec[1].a);
  b = simde_mm512_loadu_si512(test_vec[1].b);
  r = simde_mm512_mask_cmp_epi16_mask(test_vec[1].k1, a, b, SIMDE_MM_CMPINT_LT);
  simde_assert_equal_mmask32(r, test_vec[1].r);

  a = simde_mm512_loadu_si512(test_vec[2].a);
  b = simde_mm512_loadu_si512(test_vec[2].b);
  r = simde_mm512_mask_cmp_epi16_mask(test_vec[2].k1, a, b, SIMDE_MM_CMPINT_LE);
  simde_assert_equal_mmask32(r, test_vec[2].r);

  a = simde_mm512_loadu_si512(test_vec[3].a);
  b = simde_mm512_loadu_si512(test_vec[3].b);
  r = simde_mm512_mask_cmp_epi16_mask(test_vec[3].k1, a, b, SIMDE_MM_CMPINT_FALSE);
  simde_assert_equal_mmask32(r, test_vec[3].r);

  a = simde_mm512_loadu_si512(test_vec[4].a);
  b = simde_mm512_loadu_si512(test_vec[4].b);
  r = simde_mm512_mask_cmp_epi16_mask(test_vec[4].k1, a, b, SIMDE_MM_CMPINT_NE);
  simde_assert_equal_mmask32(r, test_vec[4].r);

  a = simde_mm512_loadu_si512(test_vec[5].a);
  b = simde_mm512_loadu_si512(test_vec[5].b);
  r = simde_mm512_mask_cmp_epi16_mask(test_vec[5].k1, a, b, SIMDE_MM_CMPINT_NLT);
  simde_assert_equal_mmask32(r, test_vec[5].r);

  a = simde_mm512_loadu_si512(test_vec[6].a);
  b = simde_mm512_loadu_si512(test_vec[6].b);
  r = simde_mm512_mask_cmp_epi16_mask(test_vec[6].k1, a, b, SIMDE_MM_CMPINT_NLE);
  simde_assert_equal_mmask32(r, test_vec[6].r);

  a = simde_mm512_loadu_si512(test_vec[7].a);
  b = simde_mm512_loadu_si512(test_vec[7].b);
  r = simde_mm512_mask_cmp_epi16_mask(test_vec[7].k1, a, b, SIMDE_MM_CMPINT_TRUE);
  simde_assert_equal_mmask32(r, test_vec[7].r);

  return 0;
#else
  fputc('\n', stdout);

  simde__m512i a, b;
  simde__mmask32 r, k1;

  k1 = simde_test_x86_random_mmask32();
  a = simde_test_x86_random_i16x32();
  b = simde_test_x86_random_i16x32();
  b = simde_mm512_mask_mov_epi16(a, HEDLEY_STATIC_CAST(simde__mmask32, simde_test_codegen_random_i16()), b);
  r = simde_mm512_mask_cmp_epi16_mask(k1, a, b, SIMDE_MM_CMPINT_EQ);
  simde_test_x86_write_mmask32(2, k1, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_i16x32(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_i16x32(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask32(2, r, SIMDE_TEST_VEC_POS_LAST);

  k1 = simde_test_x86_random_mmask32();
  a = simde_test_x86_random_i16x32();
  b = simde_test_x86_random_i16x32();
  b = simde_mm512_mask_mov_epi16(a, HEDLEY_STATIC_CAST(simde__mmask32, simde_test_codegen_random_i16()), b);
  r = simde_mm512_mask_cmp_epi16_mask(k1, a, b, SIMDE_MM_CMPINT_LT);
  simde_test_x86_write_mmask32(2, k1, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_i16x32(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_i16x32(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask32(2, r, SIMDE_TEST_VEC_POS_LAST);

  k1 = simde_test_x86_random_mmask32();
  a = simde_test_x86_random_i16x32();
  b = simde_test_x86_random_i16x32();
  b = simde_mm512_mask_mov_epi16(a, HEDLEY_STATIC_CAST(simde__mmask32, simde_test_codegen_random_i16()), b);
  r = simde_mm512_mask_cmp_epi16_mask(k1, a, b, SIMDE_MM_CMPINT_LE);
  simde_test_x86_write_mmask32(2, k1, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_i16x32(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_i16x32(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask32(2, r, SIMDE_TEST_VEC_POS_LAST);

  k1 = simde_test_x86_random_mmask32();
  a = simde_test_x86_random_i16x32();
  b = simde_test_x86_random_i16x32();
  b = simde_mm512_mask_mov_epi16(a, HEDLEY_STATIC_CAST(simde__mmask32, simde_test_codegen_random_i16()), b);
  r = simde_mm512_mask_cmp_epi16_mask(k1, a, b, SIMDE_MM_CMPINT_FALSE);
  simde_test_x86_write_mmask32(2, k1, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_i16x32(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_i16x32(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask32(2, r, SIMDE_TEST_VEC_POS_LAST);

  k1 = simde_test_x86_random_mmask32();
  a = simde_test_x86_random_i16x32();
  b = simde_test_x86_random_i16x32();
  b = simde_mm512_mask_mov_epi16(a, HEDLEY_STATIC_CAST(simde__mmask32, simde_test_codegen_random_i16()), b);
  r = simde_mm512_mask_cmp_epi16_mask(k1, a, b, SIMDE_MM_CMPINT_NE);
  simde_test_x86_write_mmask32(2, k1, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_i16x32(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_i16x32(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask32(2, r, SIMDE_TEST_VEC_POS_LAST);

  k1 = simde_test_x86_random_mmask32();
  a = simde_test_x86_random_i16x32();
  b = simde_test_x86_random_i16x32();
  b = simde_mm512_mask_mov_epi16(a, HEDLEY_STATIC_CAST(simde__mmask32, simde_test_codegen_random_i16()), b);
  r = simde_mm512_mask_cmp_epi16_mask(k1, a, b, SIMDE_MM_CMPINT_NLT);
  simde_test_x86_write_mmask32(2, k1, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_i16x32(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_i16x32(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask32(2, r, SIMDE_TEST_VEC_POS_LAST);

  k1 = simde_test_x86_random_mmask32();
  a = simde_test_x86_random_i16x32();
  b = simde_test_x86_random_i16x32();
  b = simde_mm512_mask_mov_epi16(a, HEDLEY_STATIC_CAST(simde__mmask32, simde_test_codegen_random_i16()), b);
  r = simde_mm512_mask_cmp_epi16_mask(k1, a, b, SIMDE_MM_CMPINT_NLE);
  simde_test_x86_write_mmask32(2, k1, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_i16x32(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_i16x32(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask32(2, r, SIMDE_TEST_VEC_POS_LAST);

  k1 = simde_test_x86_random_mmask32();
  a = simde_test_x86_random_i16x32();
  b = simde_test_x86_random_i16x32();
  b = simde_mm512_mask_mov_epi16(a, HEDLEY_STATIC_CAST(simde__mmask32, simde_test_codegen_random_i16()), b);
  r = simde_mm512_mask_cmp_epi16_mask(k1, a, b, SIMDE_MM_CMPINT_TRUE);
  simde_test_x86_write_mmask32(2, k1, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_i16x32(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_i16x32(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask32(2, r, SIMDE_TEST_VEC_POS_LAST);

  return 1;
#endif
}

static int
test_simde_mm512_cmp_epi32_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int32_t a[32];
    const int32_t b[32];
    const simde__mmask16 r;
  } test_vec[] = {
    { { -INT32_C(    71108873), -INT32_C(   384603242),  INT32_C(   279826827),  INT32_C(   369345092),  INT32_C(   395253818),  INT32_C(  1365217812),  INT32_C(   940189840),  INT32_C(  1510779746),
         INT32_C(   945147553), -INT32_C(  1004443591),  INT32_C(  2111098425), -INT32_C(   879503215),  INT32_C(    98706160),  INT32_C(  1146503604), -INT32_C(   864198550), -INT32_C(  1389983477) },
      { -INT32_C(    71108873), -INT32_C(   384603242),  INT32_C(  1721379285),  INT32_C(   369345092),  INT32_C(   395253818),  INT32_C(  1365217812),  INT32_C(   940189840),  INT32_C(  1510779746),
         INT32_C(   945147553), -INT32_C(  1004443591), -INT32_C(  1232287563), -INT32_C(   879503215),  INT32_C(    98706160),  INT32_C(  1146503604), -INT32_C(   864198550),  INT32_C(  1397668133) },
      UINT16_C(31739) },
    { { -INT32_C(   981691632),  INT32_C(  1350240347), -INT32_C(  1734990650), -INT32_C(  1329536829), -INT32_C(   867522701),  INT32_C(  1064607002),  INT32_C(  1519632982),  INT32_C(  1454372934),
        -INT32_C(   434426997), -INT32_C(    97085644),  INT32_C(  2123615419),  INT32_C(   523129772),  INT32_C(   350976250),  INT32_C(  1800625941),  INT32_C(  1757799969),  INT32_C(  1774089694) },
      { -INT32_C(   981691632),  INT32_C(   751797873), -INT32_C(  1734990650), -INT32_C(  1329536829), -INT32_C(   867522701), -INT32_C(  1949165975),  INT32_C(  1519632982), -INT32_C(  1387941619),
        -INT32_C(    58551157),  INT32_C(  1831358746),  INT32_C(  2123615419), -INT32_C(    48788820),  INT32_C(   350976250),  INT32_C(  1800625941),  INT32_C(  1757799969),  INT32_C(  1774089694) },
      UINT16_C(  768) },
    { { -INT32_C(   564347467), -INT32_C(  1766781142), -INT32_C(  1910481545), -INT32_C(  1083656870),  INT32_C(  1022777779),  INT32_C(   263767366),  INT32_C(   706602401),  INT32_C(  1412874398),
        -INT32_C(  1489857923),  INT32_C(   423486370), -INT32_C(  1700242112), -INT32_C(   984018926), -INT32_C(  1342091415), -INT32_C(  1245726444),  INT32_C(  1038146975),  INT32_C(   445716125) },
      {  INT32_C(  1254212520), -INT32_C(  1766781142), -INT32_C(  1910481545), -INT32_C(  1083656870),  INT32_C(  1043739946), -INT32_C(  1913326098),  INT32_C(   706602401),  INT32_C(  1412874398),
        -INT32_C(  1489857923), -INT32_C(  1532149432), -INT32_C(  1700242112), -INT32_C(   984018926),  INT32_C(  1769022842), -INT32_C(  1245726444),  INT32_C(  1038146975),  INT32_C(  1052108318) },
      UINT16_C(64991) },
    { { -INT32_C(  1311540988),  INT32_C(   803151901),  INT32_C(  2037770378), -INT32_C(  1952452838),  INT32_C(  1341176408),  INT32_C(    68168103),  INT32_C(    48967244),  INT32_C(  1905532012),
        -INT32_C(  1289590635),  INT32_C(   316801672),  INT32_C(    76306410), -INT32_C(  1617941689), -INT32_C(  1930526491), -INT32_C(   158203990), -INT32_C(  1694991315),  INT32_C(   755731864) },
      {  INT32_C(  2111843829),  INT32_C(   803151901),  INT32_C(  2037770378), -INT32_C(  1952452838),  INT32_C(  1341176408),  INT32_C(    68168103),  INT32_C(    48967244),  INT32_C(  1905532012),
        -INT32_C(  1289590635),  INT32_C(  1228363566), -INT32_C(  1163242125), -INT32_C(  1617941689), -INT32_C(  1930526491), -INT32_C(   158203990), -INT32_C(  1694991315),  INT32_C(   755731864) },
      UINT16_C(    0) },
    { {  INT32_C(  1616719913),  INT32_C(   599183481),  INT32_C(  1892661642), -INT32_C(   166827285), -INT32_C(  1714424077), -INT32_C(  1342934876), -INT32_C(  1522200218),  INT32_C(  1168852508),
        -INT32_C(   274397066),  INT32_C(  1645435864),  INT32_C(    13820437),  INT32_C(  1073143884),  INT32_C(  2077804247), -INT32_C(  1674916554), -INT32_C(    96374818),  INT32_C(   742386869) },
      {  INT32_C(  1616719913),  INT32_C(   599183481),  INT32_C(  1892661642), -INT32_C(   166827285),  INT32_C(  1211331602),  INT32_C(   535125313), -INT32_C(  2129058100),  INT32_C(   128800787),
        -INT32_C(   274397066),  INT32_C(  1645435864),  INT32_C(    13820437), -INT32_C(  2053373837),  INT32_C(  2077804247), -INT32_C(  1674916554), -INT32_C(   327553063), -INT32_C(  2047596728) },
      UINT16_C(51440) },
    { { -INT32_C(   724900094),  INT32_C(  1425788399),  INT32_C(  1297379249), -INT32_C(  1038300684),  INT32_C(  1450526848), -INT32_C(  1169862848),  INT32_C(   803310907),  INT32_C(   351785234),
        -INT32_C(  1461140808),  INT32_C(  1107092623),  INT32_C(  1200509011), -INT32_C(  1710576870),  INT32_C(   888176627),  INT32_C(   183383502), -INT32_C(   717631549),  INT32_C(  1491743136) },
      { -INT32_C(   724900094),  INT32_C(  1425788399),  INT32_C(  1733382733), -INT32_C(  1038300684),  INT32_C(  1450526848), -INT32_C(   374140378), -INT32_C(  2118128415),  INT32_C(   282765597),
         INT32_C(   848550523),  INT32_C(   607868631),  INT32_C(  1200509011), -INT32_C(  1030320921),  INT32_C(   888176627),  INT32_C(   183383502),  INT32_C(   674253834),  INT32_C(  1882721013) },
      UINT16_C(14043) },
    { { -INT32_C(   568149086),  INT32_C(  1785383647),  INT32_C(   116806256),  INT32_C(  2143318804), -INT32_C(  1533178601),  INT32_C(  1827710780),  INT32_C(   142009807), -INT32_C(   120366507),
        -INT32_C(   170461930),  INT32_C(   811614400), -INT32_C(  1506388334), -INT32_C(   517605686), -INT32_C(  1064975740),  INT32_C(   959214954), -INT32_C(  1354653094),  INT32_C(   312940028) },
      { -INT32_C(   905413366),  INT32_C(  1358588094),  INT32_C(   116806256),  INT32_C(  2143318804),  INT32_C(  1231810271), -INT32_C(  1115515037),  INT32_C(   142009807), -INT32_C(   481815335),
         INT32_C(  1353601170),  INT32_C(   811614400),  INT32_C(    16750553), -INT32_C(  1817483084), -INT32_C(  1064975740),  INT32_C(   959214954), -INT32_C(  1354653094), -INT32_C(  1948294151) },
      UINT16_C(34979) },
    { {  INT32_C(  2083875803), -INT32_C(   518844702), -INT32_C(  1186347250),  INT32_C(   919576666), -INT32_C(   745178021),  INT32_C(  2126034786), -INT32_C(  1830702669),  INT32_C(   404723005),
        -INT32_C(   493595648),  INT32_C(  1908648035), -INT32_C(   903148177),  INT32_C(   134281901), -INT32_C(   639920777),  INT32_C(     5739341), -INT32_C(  2104346299), -INT32_C(   828722738) },
      {  INT32_C(  1756442373),  INT32_C(  1188721879), -INT32_C(  1186347250),  INT32_C(  1983320575), -INT32_C(   745178021), -INT32_C(   336353370), -INT32_C(  1830702669),  INT32_C(   404723005),
        -INT32_C(   493595648),  INT32_C(  1908648035), -INT32_C(   903148177),  INT32_C(   134281901), -INT32_C(   639920777), -INT32_C(   785447951), -INT32_C(  2104346299), -INT32_C(   587465307) },
           UINT16_MAX },
  };

  simde__m512i a, b;
  simde__mmask16 r;

  a = simde_mm512_loadu_si512(test_vec[0].a);
  b = simde_mm512_loadu_si512(test_vec[0].b);
  r = simde_mm512_cmp_epi32_mask(a, b, SIMDE_MM_CMPINT_EQ);
  simde_assert_equal_mmask16(r, test_vec[0].r);

  a = simde_mm512_loadu_si512(test_vec[1].a);
  b = simde_mm512_loadu_si512(test_vec[1].b);
  r = simde_mm512_cmp_epi32_mask(a, b, SIMDE_MM_CMPINT_LT);
  simde_assert_equal_mmask16(r, test_vec[1].r);

  a = simde_mm512_loadu_si512(test_vec[2].a);
  b = simde_mm512_loadu_si512(test_vec[2].b);
  r = simde_mm512_cmp_epi32_mask(a, b, SIMDE_MM_CMPINT_LE);
  simde_assert_equal_mmask16(r, test_vec[2].r);

  a = simde_mm512_loadu_si512(test_vec[3].a);
  b = simde_mm512_loadu_si512(test_vec[3].b);
  r = simde_mm512_cmp_epi32_mask(a, b, SIMDE_MM_CMPINT_FALSE);
  simde_assert_equal_mmask16(r, test_vec[3].r);

  a = simde_mm512_loadu_si512(test_vec[4].a);
  b = simde_mm512_loadu_si512(test_vec[4].b);
  r = simde_mm512_cmp_epi32_mask(a, b, SIMDE_MM_CMPINT_NE);
  simde_assert_equal_mmask16(r, test_vec[4].r);

  a = simde_mm512_loadu_si512(test_vec[5].a);
  b = simde_mm512_loadu_si512(test_vec[5].b);
  r = simde_mm512_cmp_epi32_mask(a, b, SIMDE_MM_CMPINT_NLT);
  simde_assert_equal_mmask16(r, test_vec[5].r);

  a = simde_mm512_loadu_si512(test_vec[6].a);
  b = simde_mm512_loadu_si512(test_vec[6].b);
  r = simde_mm512_cmp_epi32_mask(a, b, SIMDE_MM_CMPINT_NLE);
  simde_assert_equal_mmask16(r, test_vec[6].r);

  a = simde_mm512_loadu_si512(test_vec[7].a);
  b = simde_mm512_loadu_si512(test_vec[7].b);
  r = simde_mm512_cmp_epi32_mask(a, b, SIMDE_MM_CMPINT_TRUE);
  simde_assert_equal_mmask16(r, test_vec[7].r);

  return 0;
#else
  fputc('\n', stdout);

  simde__m512i a, b;
  simde__mmask16 r;

  a = simde_test_x86_random_i32x16();
  b = simde_test_x86_random_i32x16();
  b = simde_mm512_mask_mov_epi32(a, HEDLEY_STATIC_CAST(simde__mmask16, simde_test_codegen_random_i32()), b);
  r = simde_mm512_cmp_epi32_mask(a, b, SIMDE_MM_CMPINT_EQ);
  simde_test_x86_write_i32x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_i32x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask16(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_i32x16();
  b = simde_test_x86_random_i32x16();
  b = simde_mm512_mask_mov_epi32(a, HEDLEY_STATIC_CAST(simde__mmask16, simde_test_codegen_random_i16()), b);
  r = simde_mm512_cmp_epi32_mask(a, b, SIMDE_MM_CMPINT_LT);
  simde_test_x86_write_i32x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_i32x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask16(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_i32x16();
  b = simde_test_x86_random_i32x16();
  b = simde_mm512_mask_mov_epi32(a, HEDLEY_STATIC_CAST(simde__mmask16, simde_test_codegen_random_i16()), b);
  r = simde_mm512_cmp_epi32_mask(a, b, SIMDE_MM_CMPINT_LE);
  simde_test_x86_write_i32x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_i32x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask16(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_i32x16();
  b = simde_test_x86_random_i32x16();
  b = simde_mm512_mask_mov_epi32(a, HEDLEY_STATIC_CAST(simde__mmask16, simde_test_codegen_random_i16()), b);
  r = simde_mm512_cmp_epi32_mask(a, b, SIMDE_MM_CMPINT_FALSE);
  simde_test_x86_write_i32x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_i32x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask16(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_i32x16();
  b = simde_test_x86_random_i32x16();
  b = simde_mm512_mask_mov_epi32(a, HEDLEY_STATIC_CAST(simde__mmask16, simde_test_codegen_random_i16()), b);
  r = simde_mm512_cmp_epi32_mask(a, b, SIMDE_MM_CMPINT_NE);
  simde_test_x86_write_i32x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_i32x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask16(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_i32x16();
  b = simde_test_x86_random_i32x16();
  b = simde_mm512_mask_mov_epi32(a, HEDLEY_STATIC_CAST(simde__mmask16, simde_test_codegen_random_i16()), b);
  r = simde_mm512_cmp_epi32_mask(a, b, SIMDE_MM_CMPINT_NLT);
  simde_test_x86_write_i32x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_i32x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask16(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_i32x16();
  b = simde_test_x86_random_i32x16();
  b = simde_mm512_mask_mov_epi32(a, HEDLEY_STATIC_CAST(simde__mmask16, simde_test_codegen_random_i16()), b);
  r = simde_mm512_cmp_epi32_mask(a, b, SIMDE_MM_CMPINT_NLE);
  simde_test_x86_write_i32x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_i32x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask16(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_i32x16();
  b = simde_test_x86_random_i32x16();
  b = simde_mm512_mask_mov_epi32(a, HEDLEY_STATIC_CAST(simde__mmask16, simde_test_codegen_random_i16()), b);
  r = simde_mm512_cmp_epi32_mask(a, b, SIMDE_MM_CMPINT_TRUE);
  simde_test_x86_write_i32x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_i32x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask16(2, r, SIMDE_TEST_VEC_POS_LAST);

  return 1;
#endif
}

static int
test_simde_mm512_cmp_epi64_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int64_t a[32];
    const int64_t b[32];
    const simde__mmask16 r;
  } test_vec[] = {
    { { -INT64_C( 8353491240906079368),  INT64_C( 7682228253551144618), -INT64_C( 7293374997100514869), -INT64_C( 1418852191168396141),
        -INT64_C( 2485532672843332612),  INT64_C( 8113923732475863884),  INT64_C(  203291381571302691), -INT64_C( 6476063382954348095) },
      { -INT64_C( 7693804812468770006), -INT64_C( 6623282666541871360), -INT64_C( 8681057964559398636),  INT64_C( 3274640312936144160),
        -INT64_C( 2485532672843332612), -INT64_C( 7063080687564215596), -INT64_C( 6432081977228011921), -INT64_C( 2632949559819405500) },
      UINT16_C(   16) },
    { { -INT64_C( 4184666232567098940),  INT64_C( 4872195225703081977),  INT64_C( 2645401686682196266), -INT64_C( 1277145246681060547),
        -INT64_C( 7513001852254385476), -INT64_C( 3648586803570532517), -INT64_C( 2383264425634478345),  INT64_C( 5995787089575865372) },
      { -INT64_C( 4184666232567098940), -INT64_C( 6587355934540623834), -INT64_C( 2321788389211451064), -INT64_C( 1277145246681060547),
        -INT64_C( 6425645457326376681), -INT64_C( 4402545187567470443), -INT64_C(  975183604874455851),  INT64_C( 5995787089575865372) },
      UINT16_C(   80) },
    { {  INT64_C(  910560130051929943), -INT64_C( 8397833559149044680), -INT64_C( 2192615216053870210), -INT64_C(  942566672007525460),
         INT64_C( 8788140537688181579),  INT64_C( 7729881125133813468),  INT64_C( 3756832805718410286), -INT64_C( 6914097086354620290) },
      { -INT64_C( 4307833880967566980), -INT64_C( 8397833559149044680), -INT64_C( 5636413046125609206), -INT64_C(  942566672007525460),
        -INT64_C(  816085636796124929), -INT64_C(  330656194678543233),  INT64_C( 3756832805718410286),  INT64_C(  601728666054898273) },
      UINT16_C(  202) },
    { { -INT64_C( 9166797655559428880),  INT64_C( 4862842742692493915), -INT64_C( 7162418590718057217), -INT64_C( 7367300021741313639),
        -INT64_C( 7289922348856753861), -INT64_C( 2111664984699201096), -INT64_C( 2496997208532366721),  INT64_C(  920583497151658371) },
      { -INT64_C( 9166797655559428880),  INT64_C( 7391484405507755214),  INT64_C( 4701330019113425949),  INT64_C( 8147070678708653363),
         INT64_C( 8421785888669069361), -INT64_C( 2111664984699201096),  INT64_C( 6454661185216359572),  INT64_C( 7542805034918806173) },
      UINT16_C(    0) },
    { {  INT64_C( 2051002565488968597), -INT64_C( 8072306248871818301), -INT64_C( 3003692622756765766), -INT64_C( 8874304653051525127),
        -INT64_C( 7081504854807856475), -INT64_C( 5654580532744581445),  INT64_C( 6652748363290617348),  INT64_C( 6866541073288828886) },
      {  INT64_C( 2051002565488968597),  INT64_C( 6983935528029026115),  INT64_C( 1103716409178712722), -INT64_C( 8874304653051525127),
        -INT64_C( 7081504854807856475), -INT64_C( 5654580532744581445),  INT64_C( 6652748363290617348),  INT64_C( 6866541073288828886) },
      UINT16_C(    6) },
    { {  INT64_C( 9008780825367910551), -INT64_C( 6633137853440664784),  INT64_C(  335333156428444282), -INT64_C( 2330555319040686199),
        -INT64_C( 2397885682074120243),  INT64_C(  559277091183472859), -INT64_C(  674320119158204954), -INT64_C( 3151221184168340964) },
      {  INT64_C( 1817421520256843437), -INT64_C( 6633137853440664784),  INT64_C(  335333156428444282), -INT64_C( 2330555319040686199),
        -INT64_C( 2397885682074120243),  INT64_C(  559277091183472859), -INT64_C(  768113550325877986), -INT64_C( 3151221184168340964) },
      UINT16_C(  255) },
    { {  INT64_C( 5342414784812883226),  INT64_C( 1652906191597027517), -INT64_C( 2902367991919100934), -INT64_C( 2896863780107161022),
         INT64_C( 3215005458819079522),  INT64_C( 1495644886796979262), -INT64_C( 1307136071982189740), -INT64_C( 8708490372563672944) },
      {  INT64_C( 4337661324031623063),  INT64_C( 1652906191597027517), -INT64_C( 2902367991919100934), -INT64_C( 2896863780107161022),
        -INT64_C( 4020961825939386633),  INT64_C( 6828466124693510535), -INT64_C( 1307136071982189740), -INT64_C( 6211410903474194052) },
      UINT16_C(   17) },
    { {  INT64_C( 2660072669544855198), -INT64_C( 5780610870891926412),  INT64_C( 3253293001044721542),  INT64_C( 2265453004319676509),
         INT64_C( 5826209709454025399),  INT64_C( 4629506600372573318),  INT64_C( 2971201252537255758),  INT64_C( 4849464806065965995) },
      {  INT64_C( 2660072669544855198), -INT64_C( 5780610870891926412), -INT64_C( 8203377214578487502),  INT64_C( 7032659149338606282),
        -INT64_C( 3389886259250687166), -INT64_C( 4743323348481466227),  INT64_C( 2971201252537255758), -INT64_C( 2883383938903994786) },
      UINT16_C(  255) },
  };

  simde__m512i a, b;
  simde__mmask16 r;

  a = simde_mm512_loadu_si512(test_vec[0].a);
  b = simde_mm512_loadu_si512(test_vec[0].b);
  r = simde_mm512_cmp_epi64_mask(a, b, SIMDE_MM_CMPINT_EQ);
  simde_assert_equal_mmask16(r, test_vec[0].r);

  a = simde_mm512_loadu_si512(test_vec[1].a);
  b = simde_mm512_loadu_si512(test_vec[1].b);
  r = simde_mm512_cmp_epi64_mask(a, b, SIMDE_MM_CMPINT_LT);
  simde_assert_equal_mmask16(r, test_vec[1].r);

  a = simde_mm512_loadu_si512(test_vec[2].a);
  b = simde_mm512_loadu_si512(test_vec[2].b);
  r = simde_mm512_cmp_epi64_mask(a, b, SIMDE_MM_CMPINT_LE);
  simde_assert_equal_mmask16(r, test_vec[2].r);

  a = simde_mm512_loadu_si512(test_vec[3].a);
  b = simde_mm512_loadu_si512(test_vec[3].b);
  r = simde_mm512_cmp_epi64_mask(a, b, SIMDE_MM_CMPINT_FALSE);
  simde_assert_equal_mmask16(r, test_vec[3].r);

  a = simde_mm512_loadu_si512(test_vec[4].a);
  b = simde_mm512_loadu_si512(test_vec[4].b);
  r = simde_mm512_cmp_epi64_mask(a, b, SIMDE_MM_CMPINT_NE);
  simde_assert_equal_mmask16(r, test_vec[4].r);

  a = simde_mm512_loadu_si512(test_vec[5].a);
  b = simde_mm512_loadu_si512(test_vec[5].b);
  r = simde_mm512_cmp_epi64_mask(a, b, SIMDE_MM_CMPINT_NLT);
  simde_assert_equal_mmask16(r, test_vec[5].r);

  a = simde_mm512_loadu_si512(test_vec[6].a);
  b = simde_mm512_loadu_si512(test_vec[6].b);
  r = simde_mm512_cmp_epi64_mask(a, b, SIMDE_MM_CMPINT_NLE);
  simde_assert_equal_mmask16(r, test_vec[6].r);

  a = simde_mm512_loadu_si512(test_vec[7].a);
  b = simde_mm512_loadu_si512(test_vec[7].b);
  r = simde_mm512_cmp_epi64_mask(a, b, SIMDE_MM_CMPINT_TRUE);
  simde_assert_equal_mmask16(r, test_vec[7].r);

  return 0;
#else
  fputc('\n', stdout);

  simde__m512i a, b;
  simde__mmask16 r;

  a = simde_test_x86_random_i64x8();
  b = simde_test_x86_random_i64x8();
  b = simde_mm512_mask_mov_epi64(a, HEDLEY_STATIC_CAST(simde__mmask16, simde_test_codegen_random_i32()), b);
  r = simde_mm512_cmp_epi64_mask(a, b, SIMDE_MM_CMPINT_EQ);
  simde_test_x86_write_i64x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_i64x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask16(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_i64x8();
  b = simde_test_x86_random_i64x8();
  b = simde_mm512_mask_mov_epi64(a, HEDLEY_STATIC_CAST(simde__mmask16, simde_test_codegen_random_i16()), b);
  r = simde_mm512_cmp_epi64_mask(a, b, SIMDE_MM_CMPINT_LT);
  simde_test_x86_write_i64x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_i64x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask16(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_i64x8();
  b = simde_test_x86_random_i64x8();
  b = simde_mm512_mask_mov_epi64(a, HEDLEY_STATIC_CAST(simde__mmask16, simde_test_codegen_random_i16()), b);
  r = simde_mm512_cmp_epi64_mask(a, b, SIMDE_MM_CMPINT_LE);
  simde_test_x86_write_i64x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_i64x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask16(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_i64x8();
  b = simde_test_x86_random_i64x8();
  b = simde_mm512_mask_mov_epi64(a, HEDLEY_STATIC_CAST(simde__mmask16, simde_test_codegen_random_i16()), b);
  r = simde_mm512_cmp_epi64_mask(a, b, SIMDE_MM_CMPINT_FALSE);
  simde_test_x86_write_i64x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_i64x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask16(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_i64x8();
  b = simde_test_x86_random_i64x8();
  b = simde_mm512_mask_mov_epi64(a, HEDLEY_STATIC_CAST(simde__mmask16, simde_test_codegen_random_i16()), b);
  r = simde_mm512_cmp_epi64_mask(a, b, SIMDE_MM_CMPINT_NE);
  simde_test_x86_write_i64x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_i64x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask16(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_i64x8();
  b = simde_test_x86_random_i64x8();
  b = simde_mm512_mask_mov_epi64(a, HEDLEY_STATIC_CAST(simde__mmask16, simde_test_codegen_random_i16()), b);
  r = simde_mm512_cmp_epi64_mask(a, b, SIMDE_MM_CMPINT_NLT);
  simde_test_x86_write_i64x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_i64x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask16(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_i64x8();
  b = simde_test_x86_random_i64x8();
  b = simde_mm512_mask_mov_epi64(a, HEDLEY_STATIC_CAST(simde__mmask16, simde_test_codegen_random_i16()), b);
  r = simde_mm512_cmp_epi64_mask(a, b, SIMDE_MM_CMPINT_NLE);
  simde_test_x86_write_i64x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_i64x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask16(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_i64x8();
  b = simde_test_x86_random_i64x8();
  b = simde_mm512_mask_mov_epi64(a, HEDLEY_STATIC_CAST(simde__mmask16, simde_test_codegen_random_i16()), b);
  r = simde_mm512_cmp_epi64_mask(a, b, SIMDE_MM_CMPINT_TRUE);
  simde_test_x86_write_i64x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_i64x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask16(2, r, SIMDE_TEST_VEC_POS_LAST);

  return 1;
#endif
}

#if !defined(SIMDE_FAST_MATH)
// TODO: SIMDE_FAST_MATH can be tested, but only for tests cases with no
// NAN in the parameters or results

static int
test_simde_mm512_cmp_epu16_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const uint16_t a[32];
    const uint16_t b[32];
    const simde__mmask32 r;
  } test_vec[] = {
    { { UINT16_C(19065), UINT16_C( 6990), UINT16_C(18172), UINT16_C(18778), UINT16_C(52035), UINT16_C(15647), UINT16_C(45508), UINT16_C( 2342),
        UINT16_C(25212), UINT16_C(40188), UINT16_C( 3875), UINT16_C(43536), UINT16_C( 7646), UINT16_C(63920), UINT16_C( 2924), UINT16_C(58829),
        UINT16_C( 7253), UINT16_C(20736), UINT16_C(23394), UINT16_C(42394), UINT16_C(47398), UINT16_C(60130), UINT16_C( 2154), UINT16_C(59379),
        UINT16_C(61546), UINT16_C(36227), UINT16_C(38143), UINT16_C(56888), UINT16_C(59569), UINT16_C( 7895), UINT16_C(42227), UINT16_C(18435) },
      { UINT16_C( 1216), UINT16_C( 8858), UINT16_C(13407), UINT16_C(34247), UINT16_C(43502), UINT16_C(22639), UINT16_C(25521), UINT16_C( 2342),
        UINT16_C(50003), UINT16_C(40188), UINT16_C( 3875), UINT16_C( 2096), UINT16_C( 7646), UINT16_C(48166), UINT16_C(10924), UINT16_C(58829),
        UINT16_C( 7253), UINT16_C(20736), UINT16_C(23394), UINT16_C(42394), UINT16_C(47398), UINT16_C(60130), UINT16_C( 2154), UINT16_C(59379),
        UINT16_C(61546), UINT16_C(36227), UINT16_C(38143), UINT16_C(56888), UINT16_C(59569), UINT16_C( 7895), UINT16_C(42227), UINT16_C(18435) },
      UINT32_C(4294940288) },
    { { UINT16_C(21127), UINT16_C(39360), UINT16_C(49171), UINT16_C(11290), UINT16_C(65393), UINT16_C(16005), UINT16_C(41270), UINT16_C(49332),
        UINT16_C( 2836), UINT16_C(36987), UINT16_C(15659), UINT16_C( 1842), UINT16_C(65195), UINT16_C(34280), UINT16_C(26616), UINT16_C(32751),
        UINT16_C(44985), UINT16_C(52248), UINT16_C(12911), UINT16_C(57592), UINT16_C(32305), UINT16_C(26655), UINT16_C(54047), UINT16_C(13352),
        UINT16_C(41951), UINT16_C( 2756), UINT16_C(63200), UINT16_C(35602), UINT16_C(64244), UINT16_C(60433), UINT16_C(   97), UINT16_C( 6763) },
      { UINT16_C(21127), UINT16_C(39360), UINT16_C(49171), UINT16_C(11290), UINT16_C(65393), UINT16_C(31823), UINT16_C(30705), UINT16_C(53424),
        UINT16_C( 2836), UINT16_C(36987), UINT16_C(60522), UINT16_C( 1842), UINT16_C(39142), UINT16_C(34280), UINT16_C(26616), UINT16_C(32751),
        UINT16_C(44985), UINT16_C(52248), UINT16_C(12911), UINT16_C(57592), UINT16_C(32305), UINT16_C(26655), UINT16_C(54047), UINT16_C(13352),
        UINT16_C(41951), UINT16_C( 2756), UINT16_C(63200), UINT16_C(35602), UINT16_C(64244), UINT16_C(60433), UINT16_C(   97), UINT16_C( 6763) },
      UINT32_C(      1184) },
    { { UINT16_C( 1551), UINT16_C(58232), UINT16_C(63880), UINT16_C(34567), UINT16_C(41579), UINT16_C(44341), UINT16_C(22616), UINT16_C( 2505),
        UINT16_C(53988), UINT16_C(53058), UINT16_C( 4802), UINT16_C(63747), UINT16_C(60795), UINT16_C(10897), UINT16_C(28942), UINT16_C( 7487),
        UINT16_C(46967), UINT16_C(    1), UINT16_C( 2224), UINT16_C( 7047), UINT16_C(48298), UINT16_C(  712), UINT16_C(37140), UINT16_C(63755),
        UINT16_C(19812), UINT16_C( 9928), UINT16_C(52064), UINT16_C(56095), UINT16_C(45240), UINT16_C(50949), UINT16_C(17442), UINT16_C(39396) },
      { UINT16_C(58875), UINT16_C(43929), UINT16_C(63880), UINT16_C(34567), UINT16_C(41579), UINT16_C(61849), UINT16_C(22616), UINT16_C(34026),
        UINT16_C(45810), UINT16_C(53058), UINT16_C( 4802), UINT16_C(13869), UINT16_C(13177), UINT16_C(39933), UINT16_C(28942), UINT16_C( 7487),
        UINT16_C(46967), UINT16_C(    1), UINT16_C( 2224), UINT16_C( 7047), UINT16_C(48298), UINT16_C(  712), UINT16_C(37140), UINT16_C(63755),
        UINT16_C(19812), UINT16_C( 9928), UINT16_C(52064), UINT16_C(56095), UINT16_C(45240), UINT16_C(50949), UINT16_C(17442), UINT16_C(39396) },
      UINT32_C(4294960893) },
    { { UINT16_C(37483), UINT16_C(46878), UINT16_C(37470), UINT16_C( 7069), UINT16_C(10277), UINT16_C(15811), UINT16_C( 7846), UINT16_C(30462),
        UINT16_C(35318), UINT16_C( 1395), UINT16_C(42125), UINT16_C(11282), UINT16_C(   76), UINT16_C(26369), UINT16_C(42166), UINT16_C( 8608),
        UINT16_C(48950), UINT16_C(38105), UINT16_C(30289), UINT16_C(30383), UINT16_C(29599), UINT16_C(17843), UINT16_C(45713), UINT16_C(34747),
        UINT16_C(11835), UINT16_C(51341), UINT16_C(40914), UINT16_C( 7924), UINT16_C(62879), UINT16_C(22149), UINT16_C( 9881), UINT16_C(53111) },
      { UINT16_C(20709), UINT16_C(46878), UINT16_C(37470), UINT16_C( 7069), UINT16_C(10277), UINT16_C( 6059), UINT16_C( 7846), UINT16_C(19870),
        UINT16_C(11156), UINT16_C( 1395), UINT16_C( 2506), UINT16_C(11282), UINT16_C(   76), UINT16_C(39104), UINT16_C(14129), UINT16_C( 5736),
        UINT16_C(52104), UINT16_C(20300), UINT16_C(63710), UINT16_C(25781), UINT16_C(24664), UINT16_C(27259), UINT16_C( 6854), UINT16_C(23223),
        UINT16_C(52293), UINT16_C( 4289), UINT16_C(18390), UINT16_C(54650), UINT16_C(14930), UINT16_C(33645), UINT16_C(54641), UINT16_C(63897) },
      UINT32_C(         0) },
    { { UINT16_C(32584), UINT16_C(64989), UINT16_C(14052), UINT16_C(24413), UINT16_C( 9120), UINT16_C(22649), UINT16_C(49022), UINT16_C(16164),
        UINT16_C(64207), UINT16_C(18822), UINT16_C(55503), UINT16_C(15747), UINT16_C(62555), UINT16_C(62482), UINT16_C(46062), UINT16_C(14041),
        UINT16_C(46899), UINT16_C( 5940), UINT16_C(37357), UINT16_C(36214), UINT16_C(61621), UINT16_C(13285), UINT16_C( 2735), UINT16_C(32370),
        UINT16_C(63748), UINT16_C(54471), UINT16_C(19153), UINT16_C(11537), UINT16_C( 9022), UINT16_C(11297), UINT16_C(64471), UINT16_C( 2659) },
      { UINT16_C(38834), UINT16_C(40737), UINT16_C(14052), UINT16_C(56620), UINT16_C( 4743), UINT16_C(13840), UINT16_C(49022), UINT16_C( 8372),
        UINT16_C(64207), UINT16_C(18822), UINT16_C( 1477), UINT16_C( 1146), UINT16_C(62555), UINT16_C(   48), UINT16_C(37783), UINT16_C(14041),
        UINT16_C(46899), UINT16_C( 5940), UINT16_C(37357), UINT16_C(36214), UINT16_C(61621), UINT16_C(13285), UINT16_C( 2735), UINT16_C(32370),
        UINT16_C(63748), UINT16_C(54471), UINT16_C(19153), UINT16_C(11537), UINT16_C( 9022), UINT16_C(11297), UINT16_C(64471), UINT16_C( 2659) },
      UINT32_C(     27835) },
    { { UINT16_C(32187), UINT16_C(60544), UINT16_C(42951), UINT16_C(18477), UINT16_C(61929), UINT16_C(19581), UINT16_C(11569), UINT16_C(48804),
        UINT16_C(  419), UINT16_C( 7622), UINT16_C(27271), UINT16_C( 3528), UINT16_C( 1701), UINT16_C(10653), UINT16_C(22638), UINT16_C(10901),
        UINT16_C( 5845), UINT16_C(40214), UINT16_C(17341), UINT16_C(42725), UINT16_C(25140), UINT16_C(26099), UINT16_C(38799), UINT16_C(13091),
        UINT16_C(60056), UINT16_C( 8016), UINT16_C( 6228), UINT16_C(64044), UINT16_C(51486), UINT16_C(36131), UINT16_C(47393), UINT16_C(63159) },
      { UINT16_C(32187), UINT16_C(35987), UINT16_C(30736), UINT16_C(17458), UINT16_C( 9690), UINT16_C(27305), UINT16_C(11569), UINT16_C(48804),
        UINT16_C(  419), UINT16_C( 7622), UINT16_C(40710), UINT16_C( 9221), UINT16_C(10344), UINT16_C(35249), UINT16_C(22638), UINT16_C(45184),
        UINT16_C( 4917), UINT16_C(17724), UINT16_C(28556), UINT16_C(26249), UINT16_C(12948), UINT16_C(20944), UINT16_C(28159), UINT16_C(46501),
        UINT16_C( 6491), UINT16_C(25024), UINT16_C(50616), UINT16_C( 8581), UINT16_C(14318), UINT16_C(53162), UINT16_C(10911), UINT16_C(54656) },
      UINT32_C(3648734175) },
    { { UINT16_C(51738), UINT16_C(42027), UINT16_C(49200), UINT16_C(  470), UINT16_C(54545), UINT16_C(46702), UINT16_C(51595), UINT16_C(19407),
        UINT16_C(34858), UINT16_C(45073), UINT16_C(65449), UINT16_C(21479), UINT16_C(34510), UINT16_C(20094), UINT16_C(48219), UINT16_C(30219),
        UINT16_C(13958), UINT16_C(46618), UINT16_C(61686), UINT16_C( 1975), UINT16_C( 9926), UINT16_C(20926), UINT16_C(36335), UINT16_C( 6812),
        UINT16_C(44309), UINT16_C(48842), UINT16_C(45484), UINT16_C(31506), UINT16_C(36919), UINT16_C(37833), UINT16_C(54348), UINT16_C(53769) },
      { UINT16_C(51738), UINT16_C(  392), UINT16_C(49200), UINT16_C(  470), UINT16_C(51046), UINT16_C(21802), UINT16_C(51028), UINT16_C(19407),
        UINT16_C(34858), UINT16_C(45073), UINT16_C(15082), UINT16_C( 8860), UINT16_C(26058), UINT16_C(20094), UINT16_C(48219), UINT16_C(30219),
        UINT16_C(13958), UINT16_C(46618), UINT16_C(61686), UINT16_C( 1975), UINT16_C( 9926), UINT16_C(20926), UINT16_C(36335), UINT16_C( 6812),
        UINT16_C(44309), UINT16_C(48842), UINT16_C(45484), UINT16_C(31506), UINT16_C(36919), UINT16_C(37833), UINT16_C(54348), UINT16_C(53769) },
      UINT32_C(      7282) },
    { { UINT16_C( 9066), UINT16_C(14443), UINT16_C(33338), UINT16_C(42801), UINT16_C(61677), UINT16_C(49795), UINT16_C(38948), UINT16_C(31167),
        UINT16_C(63384), UINT16_C(47722), UINT16_C(49658), UINT16_C( 5009), UINT16_C( 9809), UINT16_C(10004), UINT16_C(34716), UINT16_C( 1859),
        UINT16_C(44714), UINT16_C(58687), UINT16_C(28720), UINT16_C( 7564), UINT16_C( 3937), UINT16_C(34271), UINT16_C(40871), UINT16_C(16639),
        UINT16_C(27030), UINT16_C(37114), UINT16_C(35882), UINT16_C(31907), UINT16_C(47282), UINT16_C(20387), UINT16_C(58943), UINT16_C(59734) },
      { UINT16_C(38292), UINT16_C(50638), UINT16_C(33338), UINT16_C(26594), UINT16_C(49769), UINT16_C( 4588), UINT16_C(60257), UINT16_C(31167),
        UINT16_C(19285), UINT16_C(32648), UINT16_C(49658), UINT16_C( 5009), UINT16_C(40675), UINT16_C( 8921), UINT16_C(12164), UINT16_C( 6412),
        UINT16_C(56004), UINT16_C(51934), UINT16_C(49205), UINT16_C(40497), UINT16_C( 7810), UINT16_C(58287), UINT16_C(    9), UINT16_C(24283),
        UINT16_C(25420), UINT16_C( 9182), UINT16_C(55694), UINT16_C(29357), UINT16_C(34424), UINT16_C(64660), UINT16_C(41141), UINT16_C(31253) },
                UINT32_MAX },
  };

  simde__m512i a, b;
  simde__mmask32 r;

  a = simde_mm512_loadu_si512(test_vec[0].a);
  b = simde_mm512_loadu_si512(test_vec[0].b);
  r = simde_mm512_cmp_epu16_mask(a, b, SIMDE_MM_CMPINT_EQ);
  simde_assert_equal_mmask32(r, test_vec[0].r);

  a = simde_mm512_loadu_si512(test_vec[1].a);
  b = simde_mm512_loadu_si512(test_vec[1].b);
  r = simde_mm512_cmp_epu16_mask(a, b, SIMDE_MM_CMPINT_LT);
  simde_assert_equal_mmask32(r, test_vec[1].r);

  a = simde_mm512_loadu_si512(test_vec[2].a);
  b = simde_mm512_loadu_si512(test_vec[2].b);
  r = simde_mm512_cmp_epu16_mask(a, b, SIMDE_MM_CMPINT_LE);
  simde_assert_equal_mmask32(r, test_vec[2].r);

  a = simde_mm512_loadu_si512(test_vec[3].a);
  b = simde_mm512_loadu_si512(test_vec[3].b);
  r = simde_mm512_cmp_epu16_mask(a, b, SIMDE_MM_CMPINT_FALSE);
  simde_assert_equal_mmask32(r, test_vec[3].r);

  a = simde_mm512_loadu_si512(test_vec[4].a);
  b = simde_mm512_loadu_si512(test_vec[4].b);
  r = simde_mm512_cmp_epu16_mask(a, b, SIMDE_MM_CMPINT_NE);
  simde_assert_equal_mmask32(r, test_vec[4].r);

  a = simde_mm512_loadu_si512(test_vec[5].a);
  b = simde_mm512_loadu_si512(test_vec[5].b);
  r = simde_mm512_cmp_epu16_mask(a, b, SIMDE_MM_CMPINT_NLT);
  simde_assert_equal_mmask32(r, test_vec[5].r);

  a = simde_mm512_loadu_si512(test_vec[6].a);
  b = simde_mm512_loadu_si512(test_vec[6].b);
  r = simde_mm512_cmp_epu16_mask(a, b, SIMDE_MM_CMPINT_NLE);
  simde_assert_equal_mmask32(r, test_vec[6].r);

  a = simde_mm512_loadu_si512(test_vec[7].a);
  b = simde_mm512_loadu_si512(test_vec[7].b);
  r = simde_mm512_cmp_epu16_mask(a, b, SIMDE_MM_CMPINT_TRUE);
  simde_assert_equal_mmask32(r, test_vec[7].r);

  return 0;
#else
  fputc('\n', stdout);

  simde__m512i a, b;
  simde__mmask32 r;

  a = simde_test_x86_random_i16x32();
  b = simde_test_x86_random_i16x32();
  b = simde_mm512_mask_mov_epi16(a, HEDLEY_STATIC_CAST(simde__mmask32, simde_test_codegen_random_i16()), b);
  r = simde_mm512_cmp_epu16_mask(a, b, SIMDE_MM_CMPINT_EQ);
  simde_test_x86_write_u16x32(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_u16x32(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask32(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_i16x32();
  b = simde_test_x86_random_i16x32();
  b = simde_mm512_mask_mov_epi16(a, HEDLEY_STATIC_CAST(simde__mmask32, simde_test_codegen_random_i16()), b);
  r = simde_mm512_cmp_epu16_mask(a, b, SIMDE_MM_CMPINT_LT);
  simde_test_x86_write_u16x32(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_u16x32(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask32(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_i16x32();
  b = simde_test_x86_random_i16x32();
  b = simde_mm512_mask_mov_epi16(a, HEDLEY_STATIC_CAST(simde__mmask32, simde_test_codegen_random_i16()), b);
  r = simde_mm512_cmp_epu16_mask(a, b, SIMDE_MM_CMPINT_LE);
  simde_test_x86_write_u16x32(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_u16x32(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask32(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_i16x32();
  b = simde_test_x86_random_i16x32();
  b = simde_mm512_mask_mov_epi16(a, HEDLEY_STATIC_CAST(simde__mmask32, simde_test_codegen_random_i16()), b);
  r = simde_mm512_cmp_epu16_mask(a, b, SIMDE_MM_CMPINT_FALSE);
  simde_test_x86_write_u16x32(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_u16x32(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask32(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_i16x32();
  b = simde_test_x86_random_i16x32();
  b = simde_mm512_mask_mov_epi16(a, HEDLEY_STATIC_CAST(simde__mmask32, simde_test_codegen_random_i16()), b);
  r = simde_mm512_cmp_epu16_mask(a, b, SIMDE_MM_CMPINT_NE);
  simde_test_x86_write_u16x32(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_u16x32(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask32(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_i16x32();
  b = simde_test_x86_random_i16x32();
  b = simde_mm512_mask_mov_epi16(a, HEDLEY_STATIC_CAST(simde__mmask32, simde_test_codegen_random_i16()), b);
  r = simde_mm512_cmp_epu16_mask(a, b, SIMDE_MM_CMPINT_NLT);
  simde_test_x86_write_u16x32(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_u16x32(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask32(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_i16x32();
  b = simde_test_x86_random_i16x32();
  b = simde_mm512_mask_mov_epi16(a, HEDLEY_STATIC_CAST(simde__mmask32, simde_test_codegen_random_i16()), b);
  r = simde_mm512_cmp_epu16_mask(a, b, SIMDE_MM_CMPINT_NLE);
  simde_test_x86_write_u16x32(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_u16x32(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask32(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_i16x32();
  b = simde_test_x86_random_i16x32();
  b = simde_mm512_mask_mov_epi16(a, HEDLEY_STATIC_CAST(simde__mmask32, simde_test_codegen_random_i16()), b);
  r = simde_mm512_cmp_epu16_mask(a, b, SIMDE_MM_CMPINT_TRUE);
  simde_test_x86_write_u16x32(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_u16x32(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask32(2, r, SIMDE_TEST_VEC_POS_LAST);

  return 1;
#endif
}

static int
test_simde_mm512_mask_cmp_epu16_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask32 k1;
    const uint16_t a[32];
    const uint16_t b[32];
    const simde__mmask32 r;
  } test_vec[] = {
    { UINT32_C(2942811224),
      { UINT16_C(57010), UINT16_C(26098), UINT16_C( 9731), UINT16_C(21293), UINT16_C(10159), UINT16_C(22220), UINT16_C(21818), UINT16_C(34232),
        UINT16_C(16167), UINT16_C(43958), UINT16_C(29019), UINT16_C(18972), UINT16_C(42940), UINT16_C( 5510), UINT16_C(60771), UINT16_C( 5572),
        UINT16_C(47051), UINT16_C(53114), UINT16_C(43229), UINT16_C(36130), UINT16_C(61135), UINT16_C( 2531), UINT16_C(40004), UINT16_C(27534),
        UINT16_C(17883), UINT16_C(13846), UINT16_C(12982), UINT16_C(29568), UINT16_C( 1753), UINT16_C(15496), UINT16_C(19699), UINT16_C(48977) },
      { UINT16_C(52227), UINT16_C(26098), UINT16_C(45172), UINT16_C(21293), UINT16_C(20895), UINT16_C(58188), UINT16_C(56301), UINT16_C(51278),
        UINT16_C(16167), UINT16_C(43958), UINT16_C(32663), UINT16_C(28745), UINT16_C(53638), UINT16_C(31149), UINT16_C(65054), UINT16_C( 8504),
        UINT16_C(50890), UINT16_C(15874), UINT16_C(28791), UINT16_C( 5761), UINT16_C(52930), UINT16_C(45049), UINT16_C(18345), UINT16_C(51576),
        UINT16_C(30635), UINT16_C(17055), UINT16_C(59894), UINT16_C(31923), UINT16_C(24762), UINT16_C(55542), UINT16_C(11870), UINT16_C(10746) },
      UINT32_C(         8) },
    { UINT32_C(3916262503),
      { UINT16_C(12162), UINT16_C(31671), UINT16_C(24798), UINT16_C(22210), UINT16_C(27945), UINT16_C(51405), UINT16_C(50352), UINT16_C(25521),
        UINT16_C(27712), UINT16_C(14019), UINT16_C( 8516), UINT16_C(15973), UINT16_C(23114), UINT16_C(45627), UINT16_C(43206), UINT16_C(18587),
        UINT16_C(21207), UINT16_C(46531), UINT16_C(34226), UINT16_C(56076), UINT16_C(55794), UINT16_C(41635), UINT16_C(21917), UINT16_C(56837),
        UINT16_C(51393), UINT16_C( 1300), UINT16_C(31210), UINT16_C(13380), UINT16_C(32723), UINT16_C(39398), UINT16_C(33063), UINT16_C(65249) },
      { UINT16_C(42195), UINT16_C(31671), UINT16_C(48937), UINT16_C(22210), UINT16_C( 1177), UINT16_C(14014), UINT16_C(50265), UINT16_C(25521),
        UINT16_C(27712), UINT16_C(30239), UINT16_C( 8516), UINT16_C(15973), UINT16_C(23114), UINT16_C(45627), UINT16_C(43206), UINT16_C(18587),
        UINT16_C(21207), UINT16_C(46531), UINT16_C(34226), UINT16_C(56076), UINT16_C(55794), UINT16_C(41635), UINT16_C(21917), UINT16_C(56837),
        UINT16_C(51393), UINT16_C( 1300), UINT16_C(31210), UINT16_C(13380), UINT16_C(32723), UINT16_C(39398), UINT16_C(33063), UINT16_C(65249) },
      UINT32_C(         5) },
    { UINT32_C(3503288309),
      { UINT16_C(40707), UINT16_C(19817), UINT16_C(51145), UINT16_C( 3243), UINT16_C(13233), UINT16_C( 4463), UINT16_C(13917), UINT16_C(64797),
        UINT16_C(47839), UINT16_C(37292), UINT16_C(19818), UINT16_C(   75), UINT16_C(49283), UINT16_C(30723), UINT16_C(53936), UINT16_C(45896),
        UINT16_C(45425), UINT16_C(14848), UINT16_C(43896), UINT16_C(10567), UINT16_C(46814), UINT16_C(15163), UINT16_C(22764), UINT16_C(52024),
        UINT16_C(58642), UINT16_C(31837), UINT16_C(43058), UINT16_C(46460), UINT16_C(32617), UINT16_C( 6445), UINT16_C(30033), UINT16_C(50124) },
      { UINT16_C(40707), UINT16_C(19817), UINT16_C(51145), UINT16_C( 3243), UINT16_C( 1019), UINT16_C(59281), UINT16_C(51803), UINT16_C(28083),
        UINT16_C(47839), UINT16_C(37292), UINT16_C(19818), UINT16_C( 8598), UINT16_C(50149), UINT16_C(14138), UINT16_C( 1592), UINT16_C(45896),
        UINT16_C(45425), UINT16_C(14848), UINT16_C(43896), UINT16_C(10567), UINT16_C(46814), UINT16_C(15163), UINT16_C(22764), UINT16_C(52024),
        UINT16_C(58642), UINT16_C(31837), UINT16_C(43058), UINT16_C(46460), UINT16_C(32617), UINT16_C( 6445), UINT16_C(30033), UINT16_C(50124) },
      UINT32_C(3503263589) },
    { UINT32_C(3107859481),
      { UINT16_C( 2147), UINT16_C(33258), UINT16_C(58925), UINT16_C(48979), UINT16_C(13456), UINT16_C( 7227), UINT16_C( 7630), UINT16_C(35389),
        UINT16_C( 8933), UINT16_C(58240), UINT16_C(31806), UINT16_C(47580), UINT16_C(52299), UINT16_C(25650), UINT16_C(28920), UINT16_C(23325),
        UINT16_C( 2168), UINT16_C(42460), UINT16_C(12270), UINT16_C(32357), UINT16_C(41060), UINT16_C(12954), UINT16_C(55486), UINT16_C(41916),
        UINT16_C(15610), UINT16_C(14470), UINT16_C(25273), UINT16_C( 1266), UINT16_C( 9262), UINT16_C( 9833), UINT16_C(34452), UINT16_C( 3457) },
      { UINT16_C( 2147), UINT16_C(31922), UINT16_C( 6029), UINT16_C(61947), UINT16_C(13456), UINT16_C( 7227), UINT16_C(57453), UINT16_C(26393),
        UINT16_C( 8933), UINT16_C(54944), UINT16_C(31806), UINT16_C(47580), UINT16_C(52299), UINT16_C(25650), UINT16_C(55498), UINT16_C(22615),
        UINT16_C( 2614), UINT16_C(50389), UINT16_C(53281), UINT16_C(55733), UINT16_C(55653), UINT16_C(54095), UINT16_C(26810), UINT16_C(55098),
        UINT16_C(55816), UINT16_C( 2733), UINT16_C(34668), UINT16_C( 8762), UINT16_C(37323), UINT16_C(38253), UINT16_C(50282), UINT16_C(41197) },
      UINT32_C(         0) },
    { UINT32_C( 445837412),
      { UINT16_C(63689), UINT16_C( 6643), UINT16_C(44491), UINT16_C( 1409), UINT16_C(35204), UINT16_C(12768), UINT16_C(19603), UINT16_C(52921),
        UINT16_C(33903), UINT16_C(56415), UINT16_C(51481), UINT16_C( 1696), UINT16_C(28522), UINT16_C(52937), UINT16_C(23391), UINT16_C(10472),
        UINT16_C(56403), UINT16_C( 7745), UINT16_C(50057), UINT16_C( 3620), UINT16_C( 1100), UINT16_C(57407), UINT16_C(63568), UINT16_C(49070),
        UINT16_C( 3452), UINT16_C(38299), UINT16_C(15575), UINT16_C(16796), UINT16_C(26027), UINT16_C( 2575), UINT16_C(63680), UINT16_C( 5170) },
      { UINT16_C(29908), UINT16_C(23858), UINT16_C(22071), UINT16_C( 1409), UINT16_C(35204), UINT16_C(12768), UINT16_C( 4515), UINT16_C( 8298),
        UINT16_C(33903), UINT16_C(56415), UINT16_C(51481), UINT16_C( 1696), UINT16_C(28522), UINT16_C(30711), UINT16_C(23391), UINT16_C(10472),
        UINT16_C(56403), UINT16_C( 7745), UINT16_C(50057), UINT16_C( 3620), UINT16_C( 1100), UINT16_C(57407), UINT16_C(63568), UINT16_C(49070),
        UINT16_C( 3452), UINT16_C(38299), UINT16_C(15575), UINT16_C(16796), UINT16_C(26027), UINT16_C( 2575), UINT16_C(63680), UINT16_C( 5170) },
      UINT32_C(      8260) },
    { UINT32_C(2751257419),
      { UINT16_C(33353), UINT16_C(25439), UINT16_C(11436), UINT16_C(63207), UINT16_C(28952), UINT16_C(64246), UINT16_C(18237), UINT16_C(62995),
        UINT16_C(29262), UINT16_C(52646), UINT16_C(32528), UINT16_C(49622), UINT16_C(40438), UINT16_C(17121), UINT16_C(56696), UINT16_C(49893),
        UINT16_C(17504), UINT16_C( 3109), UINT16_C( 3184), UINT16_C(34819), UINT16_C(63869), UINT16_C(47746), UINT16_C(38208), UINT16_C(36528),
        UINT16_C(22024), UINT16_C( 6235), UINT16_C(13013), UINT16_C(52441), UINT16_C(48079), UINT16_C(18446), UINT16_C(62360), UINT16_C(63498) },
      { UINT16_C(33353), UINT16_C(43013), UINT16_C( 2107), UINT16_C(47153), UINT16_C(45825), UINT16_C(64246), UINT16_C( 8777), UINT16_C(20943),
        UINT16_C(29262), UINT16_C(52646), UINT16_C(17245), UINT16_C(49622), UINT16_C(40438), UINT16_C(38516), UINT16_C(56696), UINT16_C(21391),
        UINT16_C(38061), UINT16_C(59643), UINT16_C(11420), UINT16_C(40352), UINT16_C( 4832), UINT16_C(10718), UINT16_C(44340), UINT16_C(44154),
        UINT16_C(58328), UINT16_C(13818), UINT16_C( 4902), UINT16_C( 9314), UINT16_C(54843), UINT16_C(22203), UINT16_C(19029), UINT16_C(  681) },
      UINT32_C(2150685513) },
    { UINT32_C(2345761515),
      { UINT16_C(45335), UINT16_C(62878), UINT16_C(53978), UINT16_C(21666), UINT16_C(31615), UINT16_C(31031), UINT16_C(24240), UINT16_C( 4748),
        UINT16_C(51074), UINT16_C(15849), UINT16_C(15901), UINT16_C(50823), UINT16_C(25920), UINT16_C(11115), UINT16_C(15583), UINT16_C(63159),
        UINT16_C(21997), UINT16_C(51179), UINT16_C(36391), UINT16_C(42523), UINT16_C(21001), UINT16_C(47391), UINT16_C(44208), UINT16_C(13260),
        UINT16_C(46451), UINT16_C(37232), UINT16_C(63731), UINT16_C(13143), UINT16_C(49757), UINT16_C(15711), UINT16_C( 5886), UINT16_C(60211) },
      { UINT16_C(45335), UINT16_C(37554), UINT16_C(53978), UINT16_C(21666), UINT16_C(22560), UINT16_C(31031), UINT16_C(24240), UINT16_C( 4748),
        UINT16_C(51074), UINT16_C(15849), UINT16_C(24684), UINT16_C(50823), UINT16_C(30243), UINT16_C(11115), UINT16_C(14988), UINT16_C(63245),
        UINT16_C(48985), UINT16_C( 1673), UINT16_C(49805), UINT16_C(44476), UINT16_C(11035), UINT16_C( 8061), UINT16_C(33127), UINT16_C(22423),
        UINT16_C(41205), UINT16_C(24891), UINT16_C(20993), UINT16_C( 9258), UINT16_C(12744), UINT16_C(21573), UINT16_C(21099), UINT16_C(50251) },
      UINT32_C(2337292290) },
    { UINT32_C(2258083786),
      { UINT16_C(45644), UINT16_C(51633), UINT16_C( 6353), UINT16_C(26954), UINT16_C(16240), UINT16_C(43785), UINT16_C( 2720), UINT16_C(52221),
        UINT16_C(50478), UINT16_C(29948), UINT16_C(26393), UINT16_C(25798), UINT16_C(55339), UINT16_C(62776), UINT16_C(53111), UINT16_C(50043),
        UINT16_C(11393), UINT16_C(21389), UINT16_C(55109), UINT16_C(46524), UINT16_C(50455), UINT16_C(46944), UINT16_C(24016), UINT16_C(65154),
        UINT16_C(32290), UINT16_C(15218), UINT16_C(14821), UINT16_C( 4255), UINT16_C(55057), UINT16_C(35077), UINT16_C(32935), UINT16_C(10316) },
      { UINT16_C(45644), UINT16_C(51633), UINT16_C(14257), UINT16_C(26954), UINT16_C( 2045), UINT16_C(52607), UINT16_C(  612), UINT16_C(34507),
        UINT16_C(50478), UINT16_C(29948), UINT16_C(24695), UINT16_C(34934), UINT16_C(55339), UINT16_C(62776), UINT16_C(24316), UINT16_C(50043),
        UINT16_C(11393), UINT16_C(21389), UINT16_C(55109), UINT16_C(46524), UINT16_C(50455), UINT16_C(46944), UINT16_C(24016), UINT16_C(65154),
        UINT16_C(32290), UINT16_C(15218), UINT16_C(14821), UINT16_C( 4255), UINT16_C(55057), UINT16_C(35077), UINT16_C(32935), UINT16_C(10316) },
      UINT32_C(2258083786) },
  };

  simde__m512i a, b;
  simde__mmask32 r;

  a = simde_mm512_loadu_si512(test_vec[0].a);
  b = simde_mm512_loadu_si512(test_vec[0].b);
  r = simde_mm512_mask_cmp_epu16_mask(test_vec[0].k1, a, b, SIMDE_MM_CMPINT_EQ);
  simde_assert_equal_mmask32(r, test_vec[0].r);

  a = simde_mm512_loadu_si512(test_vec[1].a);
  b = simde_mm512_loadu_si512(test_vec[1].b);
  r = simde_mm512_mask_cmp_epu16_mask(test_vec[1].k1, a, b, SIMDE_MM_CMPINT_LT);
  simde_assert_equal_mmask32(r, test_vec[1].r);

  a = simde_mm512_loadu_si512(test_vec[2].a);
  b = simde_mm512_loadu_si512(test_vec[2].b);
  r = simde_mm512_mask_cmp_epu16_mask(test_vec[2].k1, a, b, SIMDE_MM_CMPINT_LE);
  simde_assert_equal_mmask32(r, test_vec[2].r);

  a = simde_mm512_loadu_si512(test_vec[3].a);
  b = simde_mm512_loadu_si512(test_vec[3].b);
  r = simde_mm512_mask_cmp_epu16_mask(test_vec[3].k1, a, b, SIMDE_MM_CMPINT_FALSE);
  simde_assert_equal_mmask32(r, test_vec[3].r);

  a = simde_mm512_loadu_si512(test_vec[4].a);
  b = simde_mm512_loadu_si512(test_vec[4].b);
  r = simde_mm512_mask_cmp_epu16_mask(test_vec[4].k1, a, b, SIMDE_MM_CMPINT_NE);
  simde_assert_equal_mmask32(r, test_vec[4].r);

  a = simde_mm512_loadu_si512(test_vec[5].a);
  b = simde_mm512_loadu_si512(test_vec[5].b);
  r = simde_mm512_mask_cmp_epu16_mask(test_vec[5].k1, a, b, SIMDE_MM_CMPINT_NLT);
  simde_assert_equal_mmask32(r, test_vec[5].r);

  a = simde_mm512_loadu_si512(test_vec[6].a);
  b = simde_mm512_loadu_si512(test_vec[6].b);
  r = simde_mm512_mask_cmp_epu16_mask(test_vec[6].k1, a, b, SIMDE_MM_CMPINT_NLE);
  simde_assert_equal_mmask32(r, test_vec[6].r);

  a = simde_mm512_loadu_si512(test_vec[7].a);
  b = simde_mm512_loadu_si512(test_vec[7].b);
  r = simde_mm512_mask_cmp_epu16_mask(test_vec[7].k1, a, b, SIMDE_MM_CMPINT_TRUE);
  simde_assert_equal_mmask32(r, test_vec[7].r);

  return 0;
#else
  fputc('\n', stdout);

  simde__m512i a, b;
  simde__mmask32 r, k1;

  k1 = simde_test_x86_random_mmask32();
  a = simde_test_x86_random_i16x32();
  b = simde_test_x86_random_i16x32();
  b = simde_mm512_mask_mov_epi16(a, HEDLEY_STATIC_CAST(simde__mmask32, simde_test_codegen_random_i16()), b);
  r = simde_mm512_mask_cmp_epu16_mask(k1, a, b, SIMDE_MM_CMPINT_EQ);
  simde_test_x86_write_mmask32(2, k1, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_u16x32(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_u16x32(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask32(2, r, SIMDE_TEST_VEC_POS_LAST);

  k1 = simde_test_x86_random_mmask32();
  a = simde_test_x86_random_i16x32();
  b = simde_test_x86_random_i16x32();
  b = simde_mm512_mask_mov_epi16(a, HEDLEY_STATIC_CAST(simde__mmask32, simde_test_codegen_random_i16()), b);
  r = simde_mm512_mask_cmp_epu16_mask(k1, a, b, SIMDE_MM_CMPINT_LT);
  simde_test_x86_write_mmask32(2, k1, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_u16x32(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_u16x32(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask32(2, r, SIMDE_TEST_VEC_POS_LAST);

  k1 = simde_test_x86_random_mmask32();
  a = simde_test_x86_random_i16x32();
  b = simde_test_x86_random_i16x32();
  b = simde_mm512_mask_mov_epi16(a, HEDLEY_STATIC_CAST(simde__mmask32, simde_test_codegen_random_i16()), b);
  r = simde_mm512_mask_cmp_epu16_mask(k1, a, b, SIMDE_MM_CMPINT_LE);
  simde_test_x86_write_mmask32(2, k1, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_u16x32(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_u16x32(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask32(2, r, SIMDE_TEST_VEC_POS_LAST);

  k1 = simde_test_x86_random_mmask32();
  a = simde_test_x86_random_i16x32();
  b = simde_test_x86_random_i16x32();
  b = simde_mm512_mask_mov_epi16(a, HEDLEY_STATIC_CAST(simde__mmask32, simde_test_codegen_random_i16()), b);
  r = simde_mm512_mask_cmp_epu16_mask(k1, a, b, SIMDE_MM_CMPINT_FALSE);
  simde_test_x86_write_mmask32(2, k1, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_u16x32(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_u16x32(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask32(2, r, SIMDE_TEST_VEC_POS_LAST);

  k1 = simde_test_x86_random_mmask32();
  a = simde_test_x86_random_i16x32();
  b = simde_test_x86_random_i16x32();
  b = simde_mm512_mask_mov_epi16(a, HEDLEY_STATIC_CAST(simde__mmask32, simde_test_codegen_random_i16()), b);
  r = simde_mm512_mask_cmp_epu16_mask(k1, a, b, SIMDE_MM_CMPINT_NE);
  simde_test_x86_write_mmask32(2, k1, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_u16x32(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_u16x32(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask32(2, r, SIMDE_TEST_VEC_POS_LAST);

  k1 = simde_test_x86_random_mmask32();
  a = simde_test_x86_random_i16x32();
  b = simde_test_x86_random_i16x32();
  b = simde_mm512_mask_mov_epi16(a, HEDLEY_STATIC_CAST(simde__mmask32, simde_test_codegen_random_i16()), b);
  r = simde_mm512_mask_cmp_epu16_mask(k1, a, b, SIMDE_MM_CMPINT_NLT);
  simde_test_x86_write_mmask32(2, k1, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_u16x32(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_u16x32(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask32(2, r, SIMDE_TEST_VEC_POS_LAST);

  k1 = simde_test_x86_random_mmask32();
  a = simde_test_x86_random_i16x32();
  b = simde_test_x86_random_i16x32();
  b = simde_mm512_mask_mov_epi16(a, HEDLEY_STATIC_CAST(simde__mmask32, simde_test_codegen_random_i16()), b);
  r = simde_mm512_mask_cmp_epu16_mask(k1, a, b, SIMDE_MM_CMPINT_NLE);
  simde_test_x86_write_mmask32(2, k1, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_u16x32(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_u16x32(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask32(2, r, SIMDE_TEST_VEC_POS_LAST);

  k1 = simde_test_x86_random_mmask32();
  a = simde_test_x86_random_i16x32();
  b = simde_test_x86_random_i16x32();
  b = simde_mm512_mask_mov_epi16(a, HEDLEY_STATIC_CAST(simde__mmask32, simde_test_codegen_random_i16()), b);
  r = simde_mm512_mask_cmp_epu16_mask(k1, a, b, SIMDE_MM_CMPINT_TRUE);
  simde_test_x86_write_mmask32(2, k1, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_u16x32(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_u16x32(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask32(2, r, SIMDE_TEST_VEC_POS_LAST);

  return 1;
#endif
}

static int
test_simde_mm256_cmp_epu32_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const uint32_t a[16];
    const uint32_t b[16];
    const simde__mmask8 r;
  } test_vec[] = {
    { { UINT32_C(1011172546), UINT32_C(3928345671), UINT32_C(1653069821), UINT32_C(1525565774), UINT32_C(1691221629), UINT32_C( 550340398), UINT32_C(1767416998), UINT32_C(3603681556) },
      { UINT32_C(1011172546), UINT32_C(3678850119), UINT32_C(1564331535), UINT32_C(2495097879), UINT32_C(1691221629), UINT32_C( 550340398), UINT32_C(1767416998), UINT32_C(3603681556) },
      UINT8_C(241) },
    { { UINT32_C(1520490003), UINT32_C(3995643825), UINT32_C(3306831629), UINT32_C(3410642131), UINT32_C( 345069212), UINT32_C( 635829001), UINT32_C(3440150137), UINT32_C(1362429245) },
      { UINT32_C(1520489947), UINT32_C(2440745860), UINT32_C(3306831629), UINT32_C(1991263443), UINT32_C( 345069212), UINT32_C( 635829001), UINT32_C(3440150137), UINT32_C(1362429245) },
      UINT8_C(  0) },
    { { UINT32_C( 402788765), UINT32_C(4188869795), UINT32_C(2862253817), UINT32_C(2280362492), UINT32_C(3069585553), UINT32_C(1625812189), UINT32_C(2753044000), UINT32_C(3453265199) },
      { UINT32_C(1524961693), UINT32_C(3830682347), UINT32_C( 361662201), UINT32_C( 261913214), UINT32_C(3069585553), UINT32_C(1625812189), UINT32_C(2753044000), UINT32_C(3453265199) },
      UINT8_C(241) },
    { { UINT32_C(  37673391), UINT32_C(1290819517), UINT32_C( 147222124), UINT32_C(1134192766), UINT32_C(3354401255), UINT32_C(4240489400), UINT32_C(2098421430), UINT32_C(1646920115) },
      { UINT32_C(2556746159), UINT32_C(1290818751), UINT32_C(1093905091), UINT32_C(4186230290), UINT32_C(3354401255), UINT32_C(4240489400), UINT32_C(2098421430), UINT32_C(1646920115) },
      UINT8_C(  0) },
    { { UINT32_C( 128824867), UINT32_C( 363950305), UINT32_C( 904119217), UINT32_C(2125122237), UINT32_C( 117431146), UINT32_C( 632741569), UINT32_C(1689479024), UINT32_C( 381463282) },
      { UINT32_C( 128824867), UINT32_C( 363974617), UINT32_C(1338033073), UINT32_C(1858980541), UINT32_C( 117431146), UINT32_C( 632741569), UINT32_C(1689479024), UINT32_C( 381463282) },
      UINT8_C( 14) },
    { { UINT32_C(2189917739), UINT32_C(3367704840), UINT32_C( 909361001), UINT32_C(2734913582), UINT32_C(2899225983), UINT32_C(1183604936), UINT32_C(2139166436), UINT32_C( 725034496) },
      { UINT32_C(2189917739), UINT32_C(3367704840), UINT32_C( 909361001), UINT32_C(2700703790), UINT32_C(2899225983), UINT32_C(1183604936), UINT32_C(2139166436), UINT32_C( 725034496) },
         UINT8_MAX },
    { { UINT32_C(2737854254), UINT32_C( 256596120), UINT32_C(2827578287), UINT32_C(1467002891), UINT32_C(3593443232), UINT32_C( 781000099), UINT32_C( 636513035), UINT32_C( 451703020) },
      { UINT32_C(2737854254), UINT32_C( 594479220), UINT32_C(2827614324), UINT32_C(1466973352), UINT32_C(3593443232), UINT32_C( 781000099), UINT32_C( 636513035), UINT32_C( 451703020) },
      UINT8_C(  8) },
    { { UINT32_C(2649018670), UINT32_C(3231013108), UINT32_C(2935766743), UINT32_C(2780156038), UINT32_C(3964787015), UINT32_C(1568827400), UINT32_C(2308802923), UINT32_C(2254830167) },
      { UINT32_C(3206795566), UINT32_C(2021702049), UINT32_C(2099739895), UINT32_C(2780159052), UINT32_C(3964787015), UINT32_C(1568827400), UINT32_C(2308802923), UINT32_C(2254830167) },
         UINT8_MAX },
  };

  simde__m256i a, b;
  simde__mmask8 r;

  a = simde_mm256_loadu_epi32(test_vec[0].a);
  b = simde_mm256_loadu_epi32(test_vec[0].b);
  r = simde_mm256_cmp_epu32_mask(a, b, SIMDE_MM_CMPINT_EQ);
  simde_assert_equal_mmask8(r, test_vec[0].r);

  a = simde_mm256_loadu_epi32(test_vec[1].a);
  b = simde_mm256_loadu_epi32(test_vec[1].b);
  r = simde_mm256_cmp_epu32_mask(a, b, SIMDE_MM_CMPINT_LT);
  simde_assert_equal_mmask8(r, test_vec[1].r);

  a = simde_mm256_loadu_epi32(test_vec[2].a);
  b = simde_mm256_loadu_epi32(test_vec[2].b);
  r = simde_mm256_cmp_epu32_mask(a, b, SIMDE_MM_CMPINT_LE);
  simde_assert_equal_mmask8(r, test_vec[2].r);

  a = simde_mm256_loadu_epi32(test_vec[3].a);
  b = simde_mm256_loadu_epi32(test_vec[3].b);
  r = simde_mm256_cmp_epu32_mask(a, b, SIMDE_MM_CMPINT_FALSE);
  simde_assert_equal_mmask8(r, test_vec[3].r);

  a = simde_mm256_loadu_epi32(test_vec[4].a);
  b = simde_mm256_loadu_epi32(test_vec[4].b);
  r = simde_mm256_cmp_epu32_mask(a, b, SIMDE_MM_CMPINT_NE);
  simde_assert_equal_mmask8(r, test_vec[4].r);

  a = simde_mm256_loadu_epi32(test_vec[5].a);
  b = simde_mm256_loadu_epi32(test_vec[5].b);
  r = simde_mm256_cmp_epu32_mask(a, b, SIMDE_MM_CMPINT_NLT);
  simde_assert_equal_mmask8(r, test_vec[5].r);

  a = simde_mm256_loadu_epi32(test_vec[6].a);
  b = simde_mm256_loadu_epi32(test_vec[6].b);
  r = simde_mm256_cmp_epu32_mask(a, b, SIMDE_MM_CMPINT_NLE);
  simde_assert_equal_mmask8(r, test_vec[6].r);

  a = simde_mm256_loadu_epi32(test_vec[7].a);
  b = simde_mm256_loadu_epi32(test_vec[7].b);
  r = simde_mm256_cmp_epu32_mask(a, b, SIMDE_MM_CMPINT_TRUE);
  simde_assert_equal_mmask8(r, test_vec[7].r);

  return 0;
#else
  fputc('\n', stdout);

  simde__m256i a, b;
  simde__mmask8 r;

  a = simde_test_x86_random_i32x8();
  b = simde_test_x86_random_i32x8();
  b = simde_mm256_mask_mov_epi16(a, HEDLEY_STATIC_CAST(simde__mmask8, simde_test_codegen_random_i16()), b);
  r = simde_mm256_cmp_epu32_mask(a, b, SIMDE_MM_CMPINT_EQ);
  simde_test_x86_write_u32x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_u32x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask8(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_i32x8();
  b = simde_test_x86_random_i32x8();
  b = simde_mm256_mask_mov_epi16(a, HEDLEY_STATIC_CAST(simde__mmask8, simde_test_codegen_random_i16()), b);
  r = simde_mm256_cmp_epu32_mask(a, b, SIMDE_MM_CMPINT_LT);
  simde_test_x86_write_u32x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_u32x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask8(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_i32x8();
  b = simde_test_x86_random_i32x8();
  b = simde_mm256_mask_mov_epi16(a, HEDLEY_STATIC_CAST(simde__mmask8, simde_test_codegen_random_i16()), b);
  r = simde_mm256_cmp_epu32_mask(a, b, SIMDE_MM_CMPINT_LE);
  simde_test_x86_write_u32x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_u32x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask8(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_i32x8();
  b = simde_test_x86_random_i32x8();
  b = simde_mm256_mask_mov_epi16(a, HEDLEY_STATIC_CAST(simde__mmask8, simde_test_codegen_random_i16()), b);
  r = simde_mm256_cmp_epu32_mask(a, b, SIMDE_MM_CMPINT_FALSE);
  simde_test_x86_write_u32x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_u32x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask8(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_i32x8();
  b = simde_test_x86_random_i32x8();
  b = simde_mm256_mask_mov_epi16(a, HEDLEY_STATIC_CAST(simde__mmask8, simde_test_codegen_random_i16()), b);
  r = simde_mm256_cmp_epu32_mask(a, b, SIMDE_MM_CMPINT_NE);
  simde_test_x86_write_u32x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_u32x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask8(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_i32x8();
  b = simde_test_x86_random_i32x8();
  b = simde_mm256_mask_mov_epi16(a, HEDLEY_STATIC_CAST(simde__mmask8, simde_test_codegen_random_i16()), b);
  r = simde_mm256_cmp_epu32_mask(a, b, SIMDE_MM_CMPINT_NLT);
  simde_test_x86_write_u32x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_u32x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask8(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_i32x8();
  b = simde_test_x86_random_i32x8();
  b = simde_mm256_mask_mov_epi16(a, HEDLEY_STATIC_CAST(simde__mmask8, simde_test_codegen_random_i16()), b);
  r = simde_mm256_cmp_epu32_mask(a, b, SIMDE_MM_CMPINT_NLE);
  simde_test_x86_write_u32x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_u32x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask8(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_i32x8();
  b = simde_test_x86_random_i32x8();
  b = simde_mm256_mask_mov_epi16(a, HEDLEY_STATIC_CAST(simde__mmask8, simde_test_codegen_random_i16()), b);
  r = simde_mm256_cmp_epu32_mask(a, b, SIMDE_MM_CMPINT_TRUE);
  simde_test_x86_write_u32x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_u32x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask8(2, r, SIMDE_TEST_VEC_POS_LAST);

  return 1;
#endif
}

static int
test_simde_mm512_cmp_epu32_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const uint32_t a[32];
    const uint32_t b[32];
    const simde__mmask32 r;
  } test_vec[] = {
    { { UINT32_C(1396893166), UINT32_C(1551587682), UINT32_C(1764601514), UINT32_C( 805253566), UINT32_C( 446295792), UINT32_C( 624917319), UINT32_C(2489772367), UINT32_C(3003472324),
        UINT32_C(2684766014), UINT32_C(1258127776), UINT32_C(4004719151), UINT32_C(1277014620), UINT32_C(3882333856), UINT32_C(2148312625), UINT32_C(1410691728), UINT32_C( 168237771) },
      { UINT32_C(1396837729), UINT32_C(3192609122), UINT32_C( 783089362), UINT32_C( 805292464), UINT32_C( 446292351), UINT32_C( 405830471), UINT32_C(2489772367), UINT32_C(3230299231),
        UINT32_C( 281097601), UINT32_C(2932739292), UINT32_C(3135011338), UINT32_C(3255457603), UINT32_C(3228713272), UINT32_C( 970498692), UINT32_C(1203389928), UINT32_C( 973620409) },
      UINT32_C(        64) },
    { { UINT32_C( 416699978), UINT32_C(3784499204), UINT32_C(2771965339), UINT32_C( 166162583), UINT32_C( 162294577), UINT32_C(1598985381), UINT32_C(3819112411), UINT32_C(2360155458),
        UINT32_C(2007335795), UINT32_C(4267194211), UINT32_C(2762248205), UINT32_C( 850299649), UINT32_C(2604358390), UINT32_C(3388639982), UINT32_C(3551370897), UINT32_C( 778066619) },
      { UINT32_C( 416679389), UINT32_C(3784506940), UINT32_C(2771968910), UINT32_C( 166173806), UINT32_C(3825270262), UINT32_C( 414028965), UINT32_C(3819133592), UINT32_C(2360167604),
        UINT32_C(2007335795), UINT32_C(4267194211), UINT32_C(2762248205), UINT32_C( 850299649), UINT32_C(2604358390), UINT32_C(3388639982), UINT32_C(3551370897), UINT32_C( 778066619) },
      UINT32_C(       222) },
    { { UINT32_C(2389473975), UINT32_C(1901289518), UINT32_C(2289415362), UINT32_C(1179612939), UINT32_C(2687439103), UINT32_C( 372077161), UINT32_C(4064609897), UINT32_C(3897399856),
        UINT32_C(1131854101), UINT32_C(3686058521), UINT32_C(2321820030), UINT32_C(2698032032), UINT32_C( 742457283), UINT32_C(3678629489), UINT32_C(2781710452), UINT32_C( 931994402) },
      { UINT32_C(2389473975), UINT32_C(1288265774), UINT32_C(4174785880), UINT32_C(2744678155), UINT32_C( 399563174), UINT32_C(3153204039), UINT32_C(4064657563), UINT32_C(3897399856),
        UINT32_C(1131854101), UINT32_C(3686058521), UINT32_C(2321820030), UINT32_C(2698032032), UINT32_C( 742457283), UINT32_C(3678629489), UINT32_C(2781710452), UINT32_C( 931994402) },
      UINT32_C(     65517) },
    { { UINT32_C(1787188832), UINT32_C( 994777676), UINT32_C(2831340175), UINT32_C(1133519615), UINT32_C( 729451721), UINT32_C(1995338018), UINT32_C(3317669699), UINT32_C(2699327552),
        UINT32_C( 453733070), UINT32_C( 341202564), UINT32_C( 666638376), UINT32_C(  57297978), UINT32_C(4214154712), UINT32_C(2591104342), UINT32_C(4234097084), UINT32_C(2006795177) },
      { UINT32_C( 831673952), UINT32_C( 642062924), UINT32_C(2831340175), UINT32_C(1133519615), UINT32_C( 729451721), UINT32_C(1995338018), UINT32_C(3317689540), UINT32_C(3705986607),
        UINT32_C(2215475078), UINT32_C(1621775199), UINT32_C(2728064852), UINT32_C(1271519407), UINT32_C(3443452484), UINT32_C(1091750781), UINT32_C(3870184375), UINT32_C(3099759410) },
      UINT32_C(         0) },
    { { UINT32_C(3877857597), UINT32_C(1692366793), UINT32_C(3812396570), UINT32_C( 416121049), UINT32_C(1608731469), UINT32_C(1001560972), UINT32_C(1154409601), UINT32_C(3658799261),
        UINT32_C( 197211969), UINT32_C(3362758830), UINT32_C( 145468206), UINT32_C(2015394091), UINT32_C(1356268484), UINT32_C( 546015646), UINT32_C( 191125870), UINT32_C(1944418353) },
      { UINT32_C(1568565565), UINT32_C(1965455305), UINT32_C(3279785498), UINT32_C( 238787914), UINT32_C(1608716961), UINT32_C( 157260684), UINT32_C(1964303489), UINT32_C(3941136699),
        UINT32_C(3880281760), UINT32_C(3948703315), UINT32_C(2326714943), UINT32_C( 412674423), UINT32_C(2539190267), UINT32_C( 648067042), UINT32_C(3063657851), UINT32_C(1319208110) },
      UINT32_C(     65535) },
    { { UINT32_C(2455191093), UINT32_C(3630994985), UINT32_C(3116491552), UINT32_C(1420869116), UINT32_C(4094399060), UINT32_C(1420396216), UINT32_C(3738720317), UINT32_C(3704079014),
        UINT32_C( 711859712), UINT32_C(3573734068), UINT32_C(3113141181), UINT32_C(3557637760), UINT32_C(2311657937), UINT32_C(3705500319), UINT32_C(1908061642), UINT32_C(2018345336) },
      { UINT32_C(1419951007), UINT32_C(1378460821), UINT32_C(3893147496), UINT32_C(1420827125), UINT32_C(3528492594), UINT32_C(1420373496), UINT32_C(1530161635), UINT32_C(2329133734),
        UINT32_C(3521017404), UINT32_C(2183333658), UINT32_C(3010146238), UINT32_C(2071603273), UINT32_C(2790116014), UINT32_C(3664379127), UINT32_C(1328913765), UINT32_C(1524173086) },
      UINT32_C(     61179) },
    { { UINT32_C(1337891115), UINT32_C(2273213468), UINT32_C(2863646512), UINT32_C(2423545155), UINT32_C(1837918979), UINT32_C(2064314694), UINT32_C( 444868929), UINT32_C(2949776259),
        UINT32_C(3120468125), UINT32_C(1027636237), UINT32_C(2280124228), UINT32_C(1326930764), UINT32_C( 213689542), UINT32_C(3599288213), UINT32_C(1945177328), UINT32_C(2904736528) },
      { UINT32_C(1337891115), UINT32_C(3785194524), UINT32_C(2863629461), UINT32_C(2788187459), UINT32_C(3115477763), UINT32_C(2760850100), UINT32_C(1461157959), UINT32_C(2949790275),
        UINT32_C(3120468125), UINT32_C(1027636237), UINT32_C(2280124228), UINT32_C(1326930764), UINT32_C( 213689542), UINT32_C(3599288213), UINT32_C(1945177328), UINT32_C(2904736528) },
      UINT32_C(         4) },
    { { UINT32_C(1997777055), UINT32_C(3552062797), UINT32_C(3314120742), UINT32_C(4162202971), UINT32_C(2149884548), UINT32_C(2677264501), UINT32_C(1204674752), UINT32_C( 650536327),
        UINT32_C(1520359693), UINT32_C( 741168646), UINT32_C( 703707086), UINT32_C(1746995428), UINT32_C( 552093098), UINT32_C(3602873110), UINT32_C(3810430299), UINT32_C(    648434) },
      { UINT32_C(3294275517), UINT32_C(3421515085), UINT32_C( 603316799), UINT32_C(4162197226), UINT32_C(1924428892), UINT32_C(1263039727), UINT32_C(1204674752), UINT32_C( 650524490),
        UINT32_C(1520359693), UINT32_C( 741168646), UINT32_C( 703707086), UINT32_C(1746995428), UINT32_C( 552093098), UINT32_C(3602873110), UINT32_C(3810430299), UINT32_C(    648434) },
      UINT32_C(     65535) },
  };

  simde__m512i a, b;
  simde__mmask16 r;

  a = simde_mm512_loadu_si512(test_vec[0].a);
  b = simde_mm512_loadu_si512(test_vec[0].b);
  r = simde_mm512_cmp_epu32_mask(a, b, SIMDE_MM_CMPINT_EQ);
  simde_assert_equal_mmask32(r, test_vec[0].r);

  a = simde_mm512_loadu_si512(test_vec[1].a);
  b = simde_mm512_loadu_si512(test_vec[1].b);
  r = simde_mm512_cmp_epu32_mask(a, b, SIMDE_MM_CMPINT_LT);
  simde_assert_equal_mmask32(r, test_vec[1].r);

  a = simde_mm512_loadu_si512(test_vec[2].a);
  b = simde_mm512_loadu_si512(test_vec[2].b);
  r = simde_mm512_cmp_epu32_mask(a, b, SIMDE_MM_CMPINT_LE);
  simde_assert_equal_mmask32(r, test_vec[2].r);

  a = simde_mm512_loadu_si512(test_vec[3].a);
  b = simde_mm512_loadu_si512(test_vec[3].b);
  r = simde_mm512_cmp_epu32_mask(a, b, SIMDE_MM_CMPINT_FALSE);
  simde_assert_equal_mmask32(r, test_vec[3].r);

  a = simde_mm512_loadu_si512(test_vec[4].a);
  b = simde_mm512_loadu_si512(test_vec[4].b);
  r = simde_mm512_cmp_epu32_mask(a, b, SIMDE_MM_CMPINT_NE);
  simde_assert_equal_mmask32(r, test_vec[4].r);

  a = simde_mm512_loadu_si512(test_vec[5].a);
  b = simde_mm512_loadu_si512(test_vec[5].b);
  r = simde_mm512_cmp_epu32_mask(a, b, SIMDE_MM_CMPINT_NLT);
  simde_assert_equal_mmask32(r, test_vec[5].r);

  a = simde_mm512_loadu_si512(test_vec[6].a);
  b = simde_mm512_loadu_si512(test_vec[6].b);
  r = simde_mm512_cmp_epu32_mask(a, b, SIMDE_MM_CMPINT_NLE);
  simde_assert_equal_mmask32(r, test_vec[6].r);

  a = simde_mm512_loadu_si512(test_vec[7].a);
  b = simde_mm512_loadu_si512(test_vec[7].b);
  r = simde_mm512_cmp_epu32_mask(a, b, SIMDE_MM_CMPINT_TRUE);
  simde_assert_equal_mmask32(r, test_vec[7].r);

  return 0;
#else
  fputc('\n', stdout);

  simde__m512i a, b;
  simde__mmask16 r;

  a = simde_test_x86_random_i32x16();
  b = simde_test_x86_random_i32x16();
  b = simde_mm512_mask_mov_epi16(a, HEDLEY_STATIC_CAST(simde__mmask32, simde_test_codegen_random_i16()), b);
  r = simde_mm512_cmp_epu32_mask(a, b, SIMDE_MM_CMPINT_EQ);
  simde_test_x86_write_u32x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_u32x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask32(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_i32x16();
  b = simde_test_x86_random_i32x16();
  b = simde_mm512_mask_mov_epi16(a, HEDLEY_STATIC_CAST(simde__mmask32, simde_test_codegen_random_i16()), b);
  r = simde_mm512_cmp_epu32_mask(a, b, SIMDE_MM_CMPINT_LT);
  simde_test_x86_write_u32x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_u32x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask32(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_i32x16();
  b = simde_test_x86_random_i32x16();
  b = simde_mm512_mask_mov_epi16(a, HEDLEY_STATIC_CAST(simde__mmask32, simde_test_codegen_random_i16()), b);
  r = simde_mm512_cmp_epu32_mask(a, b, SIMDE_MM_CMPINT_LE);
  simde_test_x86_write_u32x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_u32x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask32(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_i32x16();
  b = simde_test_x86_random_i32x16();
  b = simde_mm512_mask_mov_epi16(a, HEDLEY_STATIC_CAST(simde__mmask32, simde_test_codegen_random_i16()), b);
  r = simde_mm512_cmp_epu32_mask(a, b, SIMDE_MM_CMPINT_FALSE);
  simde_test_x86_write_u32x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_u32x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask32(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_i32x16();
  b = simde_test_x86_random_i32x16();
  b = simde_mm512_mask_mov_epi16(a, HEDLEY_STATIC_CAST(simde__mmask32, simde_test_codegen_random_i16()), b);
  r = simde_mm512_cmp_epu32_mask(a, b, SIMDE_MM_CMPINT_NE);
  simde_test_x86_write_u32x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_u32x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask32(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_i32x16();
  b = simde_test_x86_random_i32x16();
  b = simde_mm512_mask_mov_epi16(a, HEDLEY_STATIC_CAST(simde__mmask32, simde_test_codegen_random_i16()), b);
  r = simde_mm512_cmp_epu32_mask(a, b, SIMDE_MM_CMPINT_NLT);
  simde_test_x86_write_u32x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_u32x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask32(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_i32x16();
  b = simde_test_x86_random_i32x16();
  b = simde_mm512_mask_mov_epi16(a, HEDLEY_STATIC_CAST(simde__mmask32, simde_test_codegen_random_i16()), b);
  r = simde_mm512_cmp_epu32_mask(a, b, SIMDE_MM_CMPINT_NLE);
  simde_test_x86_write_u32x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_u32x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask32(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_i32x16();
  b = simde_test_x86_random_i32x16();
  b = simde_mm512_mask_mov_epi16(a, HEDLEY_STATIC_CAST(simde__mmask32, simde_test_codegen_random_i16()), b);
  r = simde_mm512_cmp_epu32_mask(a, b, SIMDE_MM_CMPINT_TRUE);
  simde_test_x86_write_u32x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_u32x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask32(2, r, SIMDE_TEST_VEC_POS_LAST);

  return 1;
#endif
}

static int
test_simde_mm512_mask_cmp_epu32_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask32 k1;
    const uint32_t a[32];
    const uint32_t b[32];
    const simde__mmask32 r;
  } test_vec[] = {
    { UINT32_C(2306925599),
      { UINT32_C(1471999550), UINT32_C( 192467222), UINT32_C(2545396868), UINT32_C(3416176940), UINT32_C(2420118174), UINT32_C(4152073003), UINT32_C(1060302112), UINT32_C( 281654226),
        UINT32_C(3077014945), UINT32_C(3670204246), UINT32_C(3077667467), UINT32_C(3515027507), UINT32_C(1298318114), UINT32_C(2135219551), UINT32_C(2629793738), UINT32_C(3417081898) },
      { UINT32_C(1471943437), UINT32_C( 192431603), UINT32_C(2545396868), UINT32_C(3787766060), UINT32_C(3677300348), UINT32_C(3445332779), UINT32_C( 342498026), UINT32_C(2950738898),
        UINT32_C( 487744298), UINT32_C(1755009192), UINT32_C(3210400000), UINT32_C( 127999626), UINT32_C(1206046788), UINT32_C( 773143875), UINT32_C(4181884759), UINT32_C(3215467157) },
      UINT32_C(         4) },
    { UINT32_C(2013998812),
      { UINT32_C(4031318934), UINT32_C(1812976843), UINT32_C(3174847451), UINT32_C(2969272219), UINT32_C(4029633197), UINT32_C(4094870604), UINT32_C(1622120580), UINT32_C(1557707718),
        UINT32_C(2437685958), UINT32_C(3523042294), UINT32_C(1250834863), UINT32_C(1727695289), UINT32_C( 676735452), UINT32_C(1897687533), UINT32_C(3352480769), UINT32_C(1294183047) },
      { UINT32_C(4031318934), UINT32_C(1812978891), UINT32_C(3485750235), UINT32_C(2969272219), UINT32_C(3568274663), UINT32_C(4094870604), UINT32_C(1622087832), UINT32_C(2406277314),
        UINT32_C( 441535311), UINT32_C(1049945384), UINT32_C(2987218951), UINT32_C(4248453654), UINT32_C(3285379534), UINT32_C(1303976117), UINT32_C(4067194416), UINT32_C(2793527638) },
      UINT32_C(      3204) },
    { UINT32_C(1438141632),
      { UINT32_C(2544746378), UINT32_C(2883241073), UINT32_C(2476058817), UINT32_C( 631982700), UINT32_C(  77388696), UINT32_C(1339945678), UINT32_C(1495401112), UINT32_C(3652115022),
        UINT32_C( 191912857), UINT32_C(3786820127), UINT32_C(1601457139), UINT32_C( 780411030), UINT32_C(3375505659), UINT32_C(2870546451), UINT32_C(1610890002), UINT32_C(2939793942) },
      { UINT32_C( 767213450), UINT32_C(2883219956), UINT32_C(1380362433), UINT32_C(2659207788), UINT32_C(  77378539), UINT32_C(1339916739), UINT32_C(3526733500), UINT32_C(1870846542),
        UINT32_C( 228342809), UINT32_C(1794485165), UINT32_C(3518774062), UINT32_C(4067376390), UINT32_C(3018905584), UINT32_C( 361273944), UINT32_C(2867313993), UINT32_C(1159293228) },
      UINT32_C(     19520) },
    { UINT32_C(1214272339),
      { UINT32_C(2055442109), UINT32_C(3484912223), UINT32_C(1822861180), UINT32_C(3792174938), UINT32_C(4221521940), UINT32_C( 325438714), UINT32_C(1690831633), UINT32_C( 481044830),
        UINT32_C( 395718839), UINT32_C( 921062842), UINT32_C(1319275764), UINT32_C(2670766475), UINT32_C(4087074809), UINT32_C(2902851739), UINT32_C(1762774795), UINT32_C(2944777976) },
      { UINT32_C(2055442109), UINT32_C(1558088287), UINT32_C(3299508281), UINT32_C( 593812010), UINT32_C(1159155732), UINT32_C( 183639551), UINT32_C(1690831633), UINT32_C( 481044830),
        UINT32_C( 395718839), UINT32_C( 921062842), UINT32_C(1319275764), UINT32_C(2670766475), UINT32_C(4087074809), UINT32_C(2902851739), UINT32_C(1762774795), UINT32_C(2944777976) },
      UINT32_C(         0) },
    { UINT32_C(1212481390),
      { UINT32_C(1137507135), UINT32_C(3752602331), UINT32_C(2180649779), UINT32_C(3938530170), UINT32_C(1640891992), UINT32_C(3288312588), UINT32_C( 198309789), UINT32_C( 894637814),
        UINT32_C(3967295249), UINT32_C(2110530634), UINT32_C(3003041336), UINT32_C(1369227257), UINT32_C(3534973893), UINT32_C(3012932118), UINT32_C(2680121001), UINT32_C(2379485820) },
      { UINT32_C(1137507135), UINT32_C(3752602331), UINT32_C( 106690316), UINT32_C(3938530170), UINT32_C(2035157602), UINT32_C(1697440700), UINT32_C( 198306633), UINT32_C( 894687486),
        UINT32_C(3967295249), UINT32_C(2110530634), UINT32_C(3003041336), UINT32_C(1369227257), UINT32_C(3534973893), UINT32_C(3012932118), UINT32_C(2680121001), UINT32_C(2379485820) },
      UINT32_C(       100) },
    { UINT32_C(2164540226),
      { UINT32_C(2300289123), UINT32_C(3238505714), UINT32_C( 232624032), UINT32_C(2108153299), UINT32_C( 892087334), UINT32_C(1654109103), UINT32_C(2713831263), UINT32_C(1847772427),
        UINT32_C(1475886437), UINT32_C(2316894185), UINT32_C(1637349006), UINT32_C(4192157395), UINT32_C( 422447978), UINT32_C( 494650814), UINT32_C(2562604173), UINT32_C(1711726593) },
      { UINT32_C(2300313117), UINT32_C(2341525245), UINT32_C( 232624032), UINT32_C(3516451942), UINT32_C(2515151910), UINT32_C(1654089356), UINT32_C(2763092130), UINT32_C(1829422347),
        UINT32_C(3010709686), UINT32_C(1799292063), UINT32_C(2450205740), UINT32_C(3479413752), UINT32_C(4133768810), UINT32_C(1443829428), UINT32_C(3606757510), UINT32_C( 759367031) },
      UINT32_C(       514) },
    { UINT32_C( 549088481),
      { UINT32_C(3813467864), UINT32_C(3699786873), UINT32_C(1999302675), UINT32_C(4119715558), UINT32_C( 800396085), UINT32_C( 741617129), UINT32_C(1004667482), UINT32_C(1180409198),
        UINT32_C(4230588291), UINT32_C(4275679467), UINT32_C(2272592800), UINT32_C( 394003170), UINT32_C(4266013205), UINT32_C(3106569055), UINT32_C(3958705533), UINT32_C( 758272170) },
      { UINT32_C(3813432312), UINT32_C(2900493067), UINT32_C(3895678726), UINT32_C(4119715558), UINT32_C(1080955701), UINT32_C(1056610497), UINT32_C(1328087642), UINT32_C( 930962239),
        UINT32_C(3256592311), UINT32_C(2960063914), UINT32_C(2929303892), UINT32_C( 840865873), UINT32_C(2675150046), UINT32_C(3403509028), UINT32_C(2602108764), UINT32_C( 433296994) },
      UINT32_C(     16513) },
    { UINT32_C(1256974300),
      { UINT32_C( 837566360), UINT32_C( 214515182), UINT32_C(3801655407), UINT32_C( 625982535), UINT32_C(2687282054), UINT32_C( 439782983), UINT32_C(2215146664), UINT32_C(4090426203),
        UINT32_C( 539277874), UINT32_C(1730998007), UINT32_C(3712599190), UINT32_C( 117610881), UINT32_C(2342989380), UINT32_C(1705369277), UINT32_C(2917772626), UINT32_C(3550590880) },
      { UINT32_C( 837600626), UINT32_C(1238384110), UINT32_C(3801655407), UINT32_C( 625982535), UINT32_C(2687243352), UINT32_C(1148856562), UINT32_C(2215146664), UINT32_C(2353656667),
        UINT32_C( 217464152), UINT32_C(1096140381), UINT32_C(2477227232), UINT32_C(4270527654), UINT32_C( 454233640), UINT32_C( 207588662), UINT32_C( 176378352), UINT32_C(1033358564) },
      UINT32_C(     59356) },
  };

  simde__m512i a, b;
  simde__mmask32 r;

  a = simde_mm512_loadu_si512(test_vec[0].a);
  b = simde_mm512_loadu_si512(test_vec[0].b);
  r = simde_mm512_mask_cmp_epu32_mask(test_vec[0].k1, a, b, SIMDE_MM_CMPINT_EQ);
  simde_assert_equal_mmask32(r, test_vec[0].r);

  a = simde_mm512_loadu_si512(test_vec[1].a);
  b = simde_mm512_loadu_si512(test_vec[1].b);
  r = simde_mm512_mask_cmp_epu32_mask(test_vec[1].k1, a, b, SIMDE_MM_CMPINT_LT);
  simde_assert_equal_mmask32(r, test_vec[1].r);

  a = simde_mm512_loadu_si512(test_vec[2].a);
  b = simde_mm512_loadu_si512(test_vec[2].b);
  r = simde_mm512_mask_cmp_epu32_mask(test_vec[2].k1, a, b, SIMDE_MM_CMPINT_LE);
  simde_assert_equal_mmask32(r, test_vec[2].r);

  a = simde_mm512_loadu_si512(test_vec[3].a);
  b = simde_mm512_loadu_si512(test_vec[3].b);
  r = simde_mm512_mask_cmp_epu32_mask(test_vec[3].k1, a, b, SIMDE_MM_CMPINT_FALSE);
  simde_assert_equal_mmask32(r, test_vec[3].r);

  a = simde_mm512_loadu_si512(test_vec[4].a);
  b = simde_mm512_loadu_si512(test_vec[4].b);
  r = simde_mm512_mask_cmp_epu32_mask(test_vec[4].k1, a, b, SIMDE_MM_CMPINT_NE);
  simde_assert_equal_mmask32(r, test_vec[4].r);

  a = simde_mm512_loadu_si512(test_vec[5].a);
  b = simde_mm512_loadu_si512(test_vec[5].b);
  r = simde_mm512_mask_cmp_epu32_mask(test_vec[5].k1, a, b, SIMDE_MM_CMPINT_NLT);
  simde_assert_equal_mmask32(r, test_vec[5].r);

  a = simde_mm512_loadu_si512(test_vec[6].a);
  b = simde_mm512_loadu_si512(test_vec[6].b);
  r = simde_mm512_mask_cmp_epu32_mask(test_vec[6].k1, a, b, SIMDE_MM_CMPINT_NLE);
  simde_assert_equal_mmask32(r, test_vec[6].r);

  a = simde_mm512_loadu_si512(test_vec[7].a);
  b = simde_mm512_loadu_si512(test_vec[7].b);
  r = simde_mm512_mask_cmp_epu32_mask(test_vec[7].k1, a, b, SIMDE_MM_CMPINT_TRUE);
  simde_assert_equal_mmask32(r, test_vec[7].r);

  return 0;
#else
  fputc('\n', stdout);

  simde__m512i a, b;
  simde__mmask32 r, k1;

  k1 = simde_test_x86_random_mmask32();
  a = simde_test_x86_random_i16x32();
  b = simde_test_x86_random_i32x16();
  b = simde_mm512_mask_mov_epi16(a, HEDLEY_STATIC_CAST(simde__mmask32, simde_test_codegen_random_i16()), b);
  r = simde_mm512_mask_cmp_epu32_mask(k1, a, b, SIMDE_MM_CMPINT_EQ);
  simde_test_x86_write_mmask32(2, k1, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_u32x16(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_u32x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask32(2, r, SIMDE_TEST_VEC_POS_LAST);

  k1 = simde_test_x86_random_mmask32();
  a = simde_test_x86_random_i32x16();
  b = simde_test_x86_random_i32x16();
  b = simde_mm512_mask_mov_epi16(a, HEDLEY_STATIC_CAST(simde__mmask32, simde_test_codegen_random_i16()), b);
  r = simde_mm512_mask_cmp_epu32_mask(k1, a, b, SIMDE_MM_CMPINT_LT);
  simde_test_x86_write_mmask32(2, k1, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_u32x16(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_u32x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask32(2, r, SIMDE_TEST_VEC_POS_LAST);

  k1 = simde_test_x86_random_mmask32();
  a = simde_test_x86_random_i32x16();
  b = simde_test_x86_random_i32x16();
  b = simde_mm512_mask_mov_epi16(a, HEDLEY_STATIC_CAST(simde__mmask32, simde_test_codegen_random_i16()), b);
  r = simde_mm512_mask_cmp_epu32_mask(k1, a, b, SIMDE_MM_CMPINT_LE);
  simde_test_x86_write_mmask32(2, k1, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_u32x16(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_u32x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask32(2, r, SIMDE_TEST_VEC_POS_LAST);

  k1 = simde_test_x86_random_mmask32();
  a = simde_test_x86_random_i32x16();
  b = simde_test_x86_random_i32x16();
  b = simde_mm512_mask_mov_epi16(a, HEDLEY_STATIC_CAST(simde__mmask32, simde_test_codegen_random_i16()), b);
  r = simde_mm512_mask_cmp_epu32_mask(k1, a, b, SIMDE_MM_CMPINT_FALSE);
  simde_test_x86_write_mmask32(2, k1, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_u32x16(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_u32x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask32(2, r, SIMDE_TEST_VEC_POS_LAST);

  k1 = simde_test_x86_random_mmask32();
  a = simde_test_x86_random_i32x16();
  b = simde_test_x86_random_i32x16();
  b = simde_mm512_mask_mov_epi16(a, HEDLEY_STATIC_CAST(simde__mmask32, simde_test_codegen_random_i16()), b);
  r = simde_mm512_mask_cmp_epu32_mask(k1, a, b, SIMDE_MM_CMPINT_NE);
  simde_test_x86_write_mmask32(2, k1, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_u32x16(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_u32x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask32(2, r, SIMDE_TEST_VEC_POS_LAST);

  k1 = simde_test_x86_random_mmask32();
  a = simde_test_x86_random_i32x16();
  b = simde_test_x86_random_i32x16();
  b = simde_mm512_mask_mov_epi16(a, HEDLEY_STATIC_CAST(simde__mmask32, simde_test_codegen_random_i16()), b);
  r = simde_mm512_mask_cmp_epu32_mask(k1, a, b, SIMDE_MM_CMPINT_NLT);
  simde_test_x86_write_mmask32(2, k1, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_u32x16(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_u32x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask32(2, r, SIMDE_TEST_VEC_POS_LAST);

  k1 = simde_test_x86_random_mmask32();
  a = simde_test_x86_random_i32x16();
  b = simde_test_x86_random_i32x16();
  b = simde_mm512_mask_mov_epi16(a, HEDLEY_STATIC_CAST(simde__mmask32, simde_test_codegen_random_i16()), b);
  r = simde_mm512_mask_cmp_epu32_mask(k1, a, b, SIMDE_MM_CMPINT_NLE);
  simde_test_x86_write_mmask32(2, k1, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_u32x16(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_u32x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask32(2, r, SIMDE_TEST_VEC_POS_LAST);

  k1 = simde_test_x86_random_mmask32();
  a = simde_test_x86_random_i32x16();
  b = simde_test_x86_random_i32x16();
  b = simde_mm512_mask_mov_epi16(a, HEDLEY_STATIC_CAST(simde__mmask32, simde_test_codegen_random_i16()), b);
  r = simde_mm512_mask_cmp_epu32_mask(k1, a, b, SIMDE_MM_CMPINT_TRUE);
  simde_test_x86_write_mmask32(2, k1, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_u32x16(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_u32x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask32(2, r, SIMDE_TEST_VEC_POS_LAST);

  return 1;
#endif
}

static int
test_simde_mm512_cmp_epu64_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const uint64_t a[32];
    const uint64_t b[32];
    const simde__mmask8 r;
  } test_vec[] = {
    { { UINT64_C( 6396730226032349969), UINT64_C( 1757517732396804556), UINT64_C( 4909145296243001891), UINT64_C(11349460891159154380),
        UINT64_C(13226001091946818549), UINT64_C(11277849612957090650), UINT64_C( 8136837548186655235), UINT64_C(18217442054199944616) },
      { UINT64_C( 6396730226032328070), UINT64_C(13354497492561346112), UINT64_C( 4909145296243001891), UINT64_C(11349460891159154380),
        UINT64_C(13226001091946818549), UINT64_C(11277849612957090650), UINT64_C( 8136837548186655235), UINT64_C(18217442054199944616) },
      UINT8_C(252) },
    { { UINT64_C(12710413606752138017), UINT64_C( 9045793002015904736), UINT64_C(15019389415779555393), UINT64_C( 9294952847453814072),
        UINT64_C( 1479166622733876994), UINT64_C(14100385063885104737), UINT64_C( 5468258434941549562), UINT64_C(12719430533465989286) },
      { UINT64_C(12710300804918588193), UINT64_C( 9045900135680136160), UINT64_C(15019389415779555393), UINT64_C( 9294952847453814072),
        UINT64_C( 1479166622733876994), UINT64_C(14100385063885104737), UINT64_C( 5468258434941549562), UINT64_C(12719430533465989286) },
      UINT8_C(  2) },
    { { UINT64_C(13388903476080921424), UINT64_C( 4313197271575032405), UINT64_C( 8982172829688394577), UINT64_C( 3190680334677886148),
        UINT64_C( 6331254043730776669), UINT64_C( 2693194170256475668), UINT64_C(17810931905759878424), UINT64_C( 7706013060019485416) },
      { UINT64_C( 8912325446474648400), UINT64_C( 3938679475891401301), UINT64_C( 8982172829688394577), UINT64_C( 3190680334677886148),
        UINT64_C( 6331254043730776669), UINT64_C( 2693194170256475668), UINT64_C(17810931905759878424), UINT64_C( 7706013060019485416) },
      UINT8_C(252) },
    { { UINT64_C(14332397483589821733), UINT64_C( 9660964912995932378), UINT64_C( 4317993180259497970), UINT64_C(  216587155383799493),
        UINT64_C(15399812617760936797), UINT64_C(17268185244110379447), UINT64_C(17170059517575205409), UINT64_C(12501352995469514908) },
      { UINT64_C(10132630585837020453), UINT64_C( 9339144425108567470), UINT64_C( 4317993180259497970), UINT64_C(  216587155383799493),
        UINT64_C(15399812617760936797), UINT64_C(17268185244110379447), UINT64_C(17170059517575205409), UINT64_C(12501352995469514908) },
      UINT8_C(  0) },
    { { UINT64_C(16405172983641643792), UINT64_C( 5102873512083299158), UINT64_C( 4315182043653221612), UINT64_C(11879626741962895242),
        UINT64_C(16091739187055536004), UINT64_C(14097953309992995570), UINT64_C(16400239957441625385), UINT64_C(17546993298455234122) },
      { UINT64_C(16405121987759938320), UINT64_C(15210921400863337597), UINT64_C( 4315182043653221612), UINT64_C(11879626741962895242),
        UINT64_C(16091739187055536004), UINT64_C(14097953309992995570), UINT64_C(16400239957441625385), UINT64_C(17546993298455234122) },
      UINT8_C(  3) },
    { { UINT64_C( 6671480053374025001), UINT64_C(18293709715157136618), UINT64_C(15879081983660507006), UINT64_C( 8288369653592256451),
        UINT64_C( 4742566760654732465), UINT64_C(12447085350374792623), UINT64_C(13220578336688775085), UINT64_C(15787656748967458396) },
      { UINT64_C( 6671480052952039299), UINT64_C(14327819688231840509), UINT64_C(15879081983660507006), UINT64_C( 8288369653592256451),
        UINT64_C( 4742566760654732465), UINT64_C(12447085350374792623), UINT64_C(13220578336688775085), UINT64_C(15787656748967458396) },
         UINT8_MAX },
    { { UINT64_C(16487031140270159811), UINT64_C( 7003324791183043299), UINT64_C( 6661903992142258633), UINT64_C(   91794096597492412),
        UINT64_C( 8697052956724748886), UINT64_C( 8014579565476304910), UINT64_C( 3576234640792592099), UINT64_C( 4645481614833994808) },
      { UINT64_C(18446659928976248562), UINT64_C(13019926113161859226), UINT64_C( 6661903992142258633), UINT64_C(   91794096597492412),
        UINT64_C( 8697052956724748886), UINT64_C( 8014579565476304910), UINT64_C( 3576234640792592099), UINT64_C( 4645481614833994808) },
      UINT8_C(  0) },
    { { UINT64_C(10761804693641649634), UINT64_C(  673571250861380197), UINT64_C(12401209010327219050), UINT64_C( 4788735288325590308),
        UINT64_C( 1967314059396389470), UINT64_C( 4315952372460146528), UINT64_C(16668184800513807042), UINT64_C(13202536889998923670) },
      { UINT64_C(10761804693641649634), UINT64_C(  673571250861424267), UINT64_C(12401209010327219050), UINT64_C( 4788735288325590308),
        UINT64_C( 1967314059396389470), UINT64_C( 4315952372460146528), UINT64_C(16668184800513807042), UINT64_C(13202536889998923670) },
         UINT8_MAX },
  };

  simde__m512i a, b;
  simde__mmask8 r;

  a = simde_mm512_loadu_si512(test_vec[0].a);
  b = simde_mm512_loadu_si512(test_vec[0].b);
  r = simde_mm512_cmp_epu64_mask(a, b, SIMDE_MM_CMPINT_EQ);
  simde_assert_equal_mmask8(r, test_vec[0].r);

  a = simde_mm512_loadu_si512(test_vec[1].a);
  b = simde_mm512_loadu_si512(test_vec[1].b);
  r = simde_mm512_cmp_epu64_mask(a, b, SIMDE_MM_CMPINT_LT);
  simde_assert_equal_mmask8(r, test_vec[1].r);

  a = simde_mm512_loadu_si512(test_vec[2].a);
  b = simde_mm512_loadu_si512(test_vec[2].b);
  r = simde_mm512_cmp_epu64_mask(a, b, SIMDE_MM_CMPINT_LE);
  simde_assert_equal_mmask8(r, test_vec[2].r);

  a = simde_mm512_loadu_si512(test_vec[3].a);
  b = simde_mm512_loadu_si512(test_vec[3].b);
  r = simde_mm512_cmp_epu64_mask(a, b, SIMDE_MM_CMPINT_FALSE);
  simde_assert_equal_mmask8(r, test_vec[3].r);

  a = simde_mm512_loadu_si512(test_vec[4].a);
  b = simde_mm512_loadu_si512(test_vec[4].b);
  r = simde_mm512_cmp_epu64_mask(a, b, SIMDE_MM_CMPINT_NE);
  simde_assert_equal_mmask8(r, test_vec[4].r);

  a = simde_mm512_loadu_si512(test_vec[5].a);
  b = simde_mm512_loadu_si512(test_vec[5].b);
  r = simde_mm512_cmp_epu64_mask(a, b, SIMDE_MM_CMPINT_NLT);
  simde_assert_equal_mmask8(r, test_vec[5].r);

  a = simde_mm512_loadu_si512(test_vec[6].a);
  b = simde_mm512_loadu_si512(test_vec[6].b);
  r = simde_mm512_cmp_epu64_mask(a, b, SIMDE_MM_CMPINT_NLE);
  simde_assert_equal_mmask8(r, test_vec[6].r);

  a = simde_mm512_loadu_si512(test_vec[7].a);
  b = simde_mm512_loadu_si512(test_vec[7].b);
  r = simde_mm512_cmp_epu64_mask(a, b, SIMDE_MM_CMPINT_TRUE);
  simde_assert_equal_mmask8(r, test_vec[7].r);

  return 0;
#else
  fputc('\n', stdout);

  simde__m512i a, b;
  simde__mmask8 r;

  a = simde_test_x86_random_i64x8();
  b = simde_test_x86_random_i64x8();
  b = simde_mm512_mask_mov_epi16(a, HEDLEY_STATIC_CAST(simde__mmask8, simde_test_codegen_random_i16()), b);
  r = simde_mm512_cmp_epu64_mask(a, b, SIMDE_MM_CMPINT_EQ);
  simde_test_x86_write_u64x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_u64x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask8(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_i64x8();
  b = simde_test_x86_random_i64x8();
  b = simde_mm512_mask_mov_epi16(a, HEDLEY_STATIC_CAST(simde__mmask8, simde_test_codegen_random_i16()), b);
  r = simde_mm512_cmp_epu64_mask(a, b, SIMDE_MM_CMPINT_LT);
  simde_test_x86_write_u64x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_u64x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask8(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_i64x8();
  b = simde_test_x86_random_i64x8();
  b = simde_mm512_mask_mov_epi16(a, HEDLEY_STATIC_CAST(simde__mmask8, simde_test_codegen_random_i16()), b);
  r = simde_mm512_cmp_epu64_mask(a, b, SIMDE_MM_CMPINT_LE);
  simde_test_x86_write_u64x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_u64x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask8(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_i64x8();
  b = simde_test_x86_random_i64x8();
  b = simde_mm512_mask_mov_epi16(a, HEDLEY_STATIC_CAST(simde__mmask8, simde_test_codegen_random_i16()), b);
  r = simde_mm512_cmp_epu64_mask(a, b, SIMDE_MM_CMPINT_FALSE);
  simde_test_x86_write_u64x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_u64x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask8(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_i64x8();
  b = simde_test_x86_random_i64x8();
  b = simde_mm512_mask_mov_epi16(a, HEDLEY_STATIC_CAST(simde__mmask8, simde_test_codegen_random_i16()), b);
  r = simde_mm512_cmp_epu64_mask(a, b, SIMDE_MM_CMPINT_NE);
  simde_test_x86_write_u64x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_u64x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask8(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_i64x8();
  b = simde_test_x86_random_i64x8();
  b = simde_mm512_mask_mov_epi16(a, HEDLEY_STATIC_CAST(simde__mmask8, simde_test_codegen_random_i16()), b);
  r = simde_mm512_cmp_epu64_mask(a, b, SIMDE_MM_CMPINT_NLT);
  simde_test_x86_write_u64x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_u64x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask8(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_i64x8();
  b = simde_test_x86_random_i64x8();
  b = simde_mm512_mask_mov_epi16(a, HEDLEY_STATIC_CAST(simde__mmask8, simde_test_codegen_random_i16()), b);
  r = simde_mm512_cmp_epu64_mask(a, b, SIMDE_MM_CMPINT_NLE);
  simde_test_x86_write_u64x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_u64x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask8(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_i64x8();
  b = simde_test_x86_random_i64x8();
  b = simde_mm512_mask_mov_epi16(a, HEDLEY_STATIC_CAST(simde__mmask8, simde_test_codegen_random_i16()), b);
  r = simde_mm512_cmp_epu64_mask(a, b, SIMDE_MM_CMPINT_TRUE);
  simde_test_x86_write_u64x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_u64x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask8(2, r, SIMDE_TEST_VEC_POS_LAST);

  return 1;
#endif
}

static int
test_simde_mm512_mask_cmp_epu64_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k1;
    const uint64_t a[32];
    const uint64_t b[32];
    const simde__mmask8 r;
  } test_vec[] = {
    { UINT8_C(245),
      { UINT64_C(13798969128577952951), UINT64_C(  865592770080694436), UINT64_C(16616338527109355382), UINT64_C( 7544960603920249307),
        UINT64_C(11281480747520568961), UINT64_C(  600222926371315263), UINT64_C( 4954822061910872323), UINT64_C( 6186743934749097666) },
      { UINT64_C(13798969128577940200), UINT64_C( 5957475098119169043), UINT64_C(16616338527109355382), UINT64_C( 7544960603920249307),
        UINT64_C(11281480747520568961), UINT64_C(  600222926371315263), UINT64_C( 4954822061910872323), UINT64_C( 6186743934749097666) },
      UINT8_C(244) },
    { UINT8_C( 52),
      { UINT64_C( 3791948458041289831), UINT64_C( 8323883551664815163), UINT64_C( 8729866539121046783), UINT64_C(17267476657442314195),
        UINT64_C(13317073165057247123), UINT64_C(16207123419207074171), UINT64_C( 6128932361258257208), UINT64_C( 4225896695868899374) },
      { UINT64_C( 3791948460082932839), UINT64_C( 8323886197364669499), UINT64_C( 8729866539121046783), UINT64_C(17267476657442314195),
        UINT64_C(13317073165057247123), UINT64_C(16207123419207074171), UINT64_C( 6128932361258257208), UINT64_C( 4225896695868899374) },
      UINT8_C(  0) },
    { UINT8_C(112),
      { UINT64_C( 2895090240516764959), UINT64_C(12234713576009506953), UINT64_C( 8832462160686007916), UINT64_C(18319822910187281825),
        UINT64_C(16586562114070573258), UINT64_C(13638168854306283886), UINT64_C(16090300709696178248), UINT64_C(17489142188564353752) },
      { UINT64_C(10529178589855340251), UINT64_C(12234713576009506953), UINT64_C( 8832462160686007916), UINT64_C(18319822910187281825),
        UINT64_C(16586562114070573258), UINT64_C(13638168854306283886), UINT64_C(16090300709696178248), UINT64_C(17489142188564353752) },
      UINT8_C(112) },
    { UINT8_C( 52),
      { UINT64_C( 2569861659191498526), UINT64_C(13829149809373098599), UINT64_C( 4964789348749222253), UINT64_C( 4290501205781057116),
        UINT64_C(17218979391673043779), UINT64_C(13801324290282049357), UINT64_C( 3830120000072146760), UINT64_C( 5672025390479777375) },
      { UINT64_C( 2569861658925160222), UINT64_C(13829149811168268391), UINT64_C( 4964789348749222253), UINT64_C( 4290501205781057116),
        UINT64_C(17218979391673043779), UINT64_C(13801324290282049357), UINT64_C( 3830120000072146760), UINT64_C( 5672025390479777375) },
      UINT8_C(  0) },
    { UINT8_C(171),
      { UINT64_C( 1379093814738447531), UINT64_C( 5479562598387102592), UINT64_C( 9456375183746312458), UINT64_C(16824911916000611416),
        UINT64_C(17301590000419531396), UINT64_C(15509752587861261515), UINT64_C( 7278586713927139934), UINT64_C( 1365072883192723145) },
      { UINT64_C( 1379005273987640491), UINT64_C( 5479746465937075121), UINT64_C( 9456375183746312458), UINT64_C(16824911916000611416),
        UINT64_C(17301590000419531396), UINT64_C(15509752587861261515), UINT64_C( 7278586713927139934), UINT64_C( 1365072883192723145) },
      UINT8_C(  3) },
    { UINT8_C( 20),
      { UINT64_C(  730091871238666232), UINT64_C(15645921031949076993), UINT64_C(12243622487237493264), UINT64_C( 1957428815798390713),
        UINT64_C(10205591666533449446), UINT64_C( 5690047707322500309), UINT64_C(10020954277279350175), UINT64_C(17051414368067114851) },
      { UINT64_C(  729903743081122697), UINT64_C( 6518250485991426561), UINT64_C(12243622487237493264), UINT64_C( 1957428815798390713),
        UINT64_C(10205591666533449446), UINT64_C( 5690047707322500309), UINT64_C(10020954277279350175), UINT64_C(17051414368067114851) },
      UINT8_C( 20) },
    { UINT8_C(184),
      { UINT64_C(10691787335189989094), UINT64_C(11558015695599052081), UINT64_C(11532763299499189477), UINT64_C( 2284853577014022950),
        UINT64_C(14337367285527722612), UINT64_C(14005615251350522548), UINT64_C( 7949679383485328532), UINT64_C(16850816641492780675) },
      { UINT64_C( 5491371840054298342), UINT64_C(11558039497896214479), UINT64_C(11532763299499189477), UINT64_C( 2284853577014022950),
        UINT64_C(14337367285527722612), UINT64_C(14005615251350522548), UINT64_C( 7949679383485328532), UINT64_C(16850816641492780675) },
      UINT8_C(  0) },
    { UINT8_C(184),
      { UINT64_C(16682269420512417211), UINT64_C(16285269311380761612), UINT64_C(10201885801900601514), UINT64_C( 5633853134090803130),
        UINT64_C(10311725284618350733), UINT64_C( 1680237851392312903), UINT64_C(14914347552942109528), UINT64_C( 3702367525800259199) },
      { UINT64_C( 6608280001309997475), UINT64_C(16285046508263972103), UINT64_C(10201885801900601514), UINT64_C( 5633853134090803130),
        UINT64_C(10311725284618350733), UINT64_C( 1680237851392312903), UINT64_C(14914347552942109528), UINT64_C( 3702367525800259199) },
      UINT8_C(184) },
  };

  simde__m512i a, b;
  simde__mmask8 r;

  a = simde_mm512_loadu_si512(test_vec[0].a);
  b = simde_mm512_loadu_si512(test_vec[0].b);
  r = simde_mm512_mask_cmp_epu64_mask(test_vec[0].k1, a, b, SIMDE_MM_CMPINT_EQ);
  simde_assert_equal_mmask8(r, test_vec[0].r);

  a = simde_mm512_loadu_si512(test_vec[1].a);
  b = simde_mm512_loadu_si512(test_vec[1].b);
  r = simde_mm512_mask_cmp_epu64_mask(test_vec[1].k1, a, b, SIMDE_MM_CMPINT_LT);
  simde_assert_equal_mmask8(r, test_vec[1].r);

  a = simde_mm512_loadu_si512(test_vec[2].a);
  b = simde_mm512_loadu_si512(test_vec[2].b);
  r = simde_mm512_mask_cmp_epu64_mask(test_vec[2].k1, a, b, SIMDE_MM_CMPINT_LE);
  simde_assert_equal_mmask8(r, test_vec[2].r);

  a = simde_mm512_loadu_si512(test_vec[3].a);
  b = simde_mm512_loadu_si512(test_vec[3].b);
  r = simde_mm512_mask_cmp_epu64_mask(test_vec[3].k1, a, b, SIMDE_MM_CMPINT_FALSE);
  simde_assert_equal_mmask8(r, test_vec[3].r);

  a = simde_mm512_loadu_si512(test_vec[4].a);
  b = simde_mm512_loadu_si512(test_vec[4].b);
  r = simde_mm512_mask_cmp_epu64_mask(test_vec[4].k1, a, b, SIMDE_MM_CMPINT_NE);
  simde_assert_equal_mmask8(r, test_vec[4].r);

  a = simde_mm512_loadu_si512(test_vec[5].a);
  b = simde_mm512_loadu_si512(test_vec[5].b);
  r = simde_mm512_mask_cmp_epu64_mask(test_vec[5].k1, a, b, SIMDE_MM_CMPINT_NLT);
  simde_assert_equal_mmask8(r, test_vec[5].r);

  a = simde_mm512_loadu_si512(test_vec[6].a);
  b = simde_mm512_loadu_si512(test_vec[6].b);
  r = simde_mm512_mask_cmp_epu64_mask(test_vec[6].k1, a, b, SIMDE_MM_CMPINT_NLE);
  simde_assert_equal_mmask8(r, test_vec[6].r);

  a = simde_mm512_loadu_si512(test_vec[7].a);
  b = simde_mm512_loadu_si512(test_vec[7].b);
  r = simde_mm512_mask_cmp_epu64_mask(test_vec[7].k1, a, b, SIMDE_MM_CMPINT_TRUE);
  simde_assert_equal_mmask8(r, test_vec[7].r);

  return 0;
#else
  fputc('\n', stdout);

  simde__m512i a, b;
  simde__mmask8 r, k1;

  k1 = simde_test_x86_random_mmask8();
  a = simde_test_x86_random_i16x32();
  b = simde_test_x86_random_i64x8();
  b = simde_mm512_mask_mov_epi16(a, HEDLEY_STATIC_CAST(simde__mmask8, simde_test_codegen_random_i16()), b);
  r = simde_mm512_mask_cmp_epu64_mask(k1, a, b, SIMDE_MM_CMPINT_EQ);
  simde_test_x86_write_mmask8(2, k1, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_u64x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_u64x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask8(2, r, SIMDE_TEST_VEC_POS_LAST);

  k1 = simde_test_x86_random_mmask8();
  a = simde_test_x86_random_i64x8();
  b = simde_test_x86_random_i64x8();
  b = simde_mm512_mask_mov_epi16(a, HEDLEY_STATIC_CAST(simde__mmask8, simde_test_codegen_random_i16()), b);
  r = simde_mm512_mask_cmp_epu64_mask(k1, a, b, SIMDE_MM_CMPINT_LT);
  simde_test_x86_write_mmask8(2, k1, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_u64x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_u64x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask8(2, r, SIMDE_TEST_VEC_POS_LAST);

  k1 = simde_test_x86_random_mmask8();
  a = simde_test_x86_random_i64x8();
  b = simde_test_x86_random_i64x8();
  b = simde_mm512_mask_mov_epi16(a, HEDLEY_STATIC_CAST(simde__mmask8, simde_test_codegen_random_i16()), b);
  r = simde_mm512_mask_cmp_epu64_mask(k1, a, b, SIMDE_MM_CMPINT_LE);
  simde_test_x86_write_mmask8(2, k1, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_u64x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_u64x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask8(2, r, SIMDE_TEST_VEC_POS_LAST);

  k1 = simde_test_x86_random_mmask8();
  a = simde_test_x86_random_i64x8();
  b = simde_test_x86_random_i64x8();
  b = simde_mm512_mask_mov_epi16(a, HEDLEY_STATIC_CAST(simde__mmask8, simde_test_codegen_random_i16()), b);
  r = simde_mm512_mask_cmp_epu64_mask(k1, a, b, SIMDE_MM_CMPINT_FALSE);
  simde_test_x86_write_mmask8(2, k1, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_u64x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_u64x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask8(2, r, SIMDE_TEST_VEC_POS_LAST);

  k1 = simde_test_x86_random_mmask8();
  a = simde_test_x86_random_i64x8();
  b = simde_test_x86_random_i64x8();
  b = simde_mm512_mask_mov_epi16(a, HEDLEY_STATIC_CAST(simde__mmask8, simde_test_codegen_random_i16()), b);
  r = simde_mm512_mask_cmp_epu64_mask(k1, a, b, SIMDE_MM_CMPINT_NE);
  simde_test_x86_write_mmask8(2, k1, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_u64x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_u64x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask8(2, r, SIMDE_TEST_VEC_POS_LAST);

  k1 = simde_test_x86_random_mmask8();
  a = simde_test_x86_random_i64x8();
  b = simde_test_x86_random_i64x8();
  b = simde_mm512_mask_mov_epi16(a, HEDLEY_STATIC_CAST(simde__mmask8, simde_test_codegen_random_i16()), b);
  r = simde_mm512_mask_cmp_epu64_mask(k1, a, b, SIMDE_MM_CMPINT_NLT);
  simde_test_x86_write_mmask8(2, k1, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_u64x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_u64x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask8(2, r, SIMDE_TEST_VEC_POS_LAST);

  k1 = simde_test_x86_random_mmask8();
  a = simde_test_x86_random_i64x8();
  b = simde_test_x86_random_i64x8();
  b = simde_mm512_mask_mov_epi16(a, HEDLEY_STATIC_CAST(simde__mmask8, simde_test_codegen_random_i16()), b);
  r = simde_mm512_mask_cmp_epu64_mask(k1, a, b, SIMDE_MM_CMPINT_NLE);
  simde_test_x86_write_mmask8(2, k1, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_u64x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_u64x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask8(2, r, SIMDE_TEST_VEC_POS_LAST);

  k1 = simde_test_x86_random_mmask8();
  a = simde_test_x86_random_i64x8();
  b = simde_test_x86_random_i64x8();
  b = simde_mm512_mask_mov_epi16(a, HEDLEY_STATIC_CAST(simde__mmask8, simde_test_codegen_random_i16()), b);
  r = simde_mm512_mask_cmp_epu64_mask(k1, a, b, SIMDE_MM_CMPINT_TRUE);
  simde_test_x86_write_mmask8(2, k1, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_u64x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_u64x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask8(2, r, SIMDE_TEST_VEC_POS_LAST);

  return 1;
#endif
}

#if !defined(SIMDE_NATIVE_ALIASES_TESTING)
static int
test_simde_mm512_cmp_ps_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde_float32 a[16];
    const simde_float32 b[16];
    const simde__mmask16 r;
  } test_vec[] = {
    { {            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -492.75), SIMDE_FLOAT32_C(  -438.29),
        SIMDE_FLOAT32_C(  -582.04), SIMDE_FLOAT32_C(   854.65), SIMDE_FLOAT32_C(   155.54), SIMDE_FLOAT32_C(   896.11),
        SIMDE_FLOAT32_C(  -984.17), SIMDE_FLOAT32_C(  -151.52), SIMDE_FLOAT32_C(  -333.42), SIMDE_FLOAT32_C(  -650.38),
        SIMDE_FLOAT32_C(   -87.56), SIMDE_FLOAT32_C(  -583.12), SIMDE_FLOAT32_C(  -508.18), SIMDE_FLOAT32_C(    10.09) },
      { SIMDE_FLOAT32_C(  -433.49),            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   431.70),
        SIMDE_FLOAT32_C(  -582.04), SIMDE_FLOAT32_C(  -629.54), SIMDE_FLOAT32_C(  -116.35), SIMDE_FLOAT32_C(  -824.24),
        SIMDE_FLOAT32_C(  -984.17), SIMDE_FLOAT32_C(  -139.40), SIMDE_FLOAT32_C(  -333.42), SIMDE_FLOAT32_C(   866.10),
        SIMDE_FLOAT32_C(   -87.56), SIMDE_FLOAT32_C(  -583.12), SIMDE_FLOAT32_C(  -722.62), SIMDE_FLOAT32_C(    10.09) },
      UINT16_C(46352) },
    { {            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -360.72), SIMDE_FLOAT32_C(   883.16),
        SIMDE_FLOAT32_C(  -175.11), SIMDE_FLOAT32_C(  -344.89), SIMDE_FLOAT32_C(  -268.35), SIMDE_FLOAT32_C(   491.46),
        SIMDE_FLOAT32_C(     4.73), SIMDE_FLOAT32_C(   644.09), SIMDE_FLOAT32_C(   908.34), SIMDE_FLOAT32_C(   496.55),
        SIMDE_FLOAT32_C(  -345.82), SIMDE_FLOAT32_C(  -412.75), SIMDE_FLOAT32_C(   601.72), SIMDE_FLOAT32_C(  -536.93) },
      { SIMDE_FLOAT32_C(  -981.05),            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   -97.40),
        SIMDE_FLOAT32_C(  -175.11), SIMDE_FLOAT32_C(  -920.53), SIMDE_FLOAT32_C(  -268.35), SIMDE_FLOAT32_C(   491.46),
        SIMDE_FLOAT32_C(     4.73), SIMDE_FLOAT32_C(   644.09), SIMDE_FLOAT32_C(   908.34), SIMDE_FLOAT32_C(  -777.04),
        SIMDE_FLOAT32_C(   528.52), SIMDE_FLOAT32_C(   439.99), SIMDE_FLOAT32_C(   601.72), SIMDE_FLOAT32_C(  -536.93) },
      UINT16_C(12288) },
    { {            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -698.03), SIMDE_FLOAT32_C(  -129.05),
        SIMDE_FLOAT32_C(  -314.88), SIMDE_FLOAT32_C(   306.70), SIMDE_FLOAT32_C(  -484.96), SIMDE_FLOAT32_C(  -406.54),
        SIMDE_FLOAT32_C(  -196.75), SIMDE_FLOAT32_C(   169.22), SIMDE_FLOAT32_C(   180.71), SIMDE_FLOAT32_C(  -595.03),
        SIMDE_FLOAT32_C(   632.29), SIMDE_FLOAT32_C(   199.66), SIMDE_FLOAT32_C(   321.33), SIMDE_FLOAT32_C(  -534.18) },
      { SIMDE_FLOAT32_C(  -860.70),            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -129.05),
        SIMDE_FLOAT32_C(  -314.88), SIMDE_FLOAT32_C(   306.70), SIMDE_FLOAT32_C(   228.07), SIMDE_FLOAT32_C(    91.07),
        SIMDE_FLOAT32_C(  -286.18), SIMDE_FLOAT32_C(   169.22), SIMDE_FLOAT32_C(   180.71), SIMDE_FLOAT32_C(  -595.03),
        SIMDE_FLOAT32_C(    12.74), SIMDE_FLOAT32_C(   199.66), SIMDE_FLOAT32_C(   321.33), SIMDE_FLOAT32_C(   152.04) },
      UINT16_C(61176) },
    { {            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   -23.06), SIMDE_FLOAT32_C(  -461.97),
        SIMDE_FLOAT32_C(   372.08), SIMDE_FLOAT32_C(   780.19), SIMDE_FLOAT32_C(   707.25), SIMDE_FLOAT32_C(  -447.21),
        SIMDE_FLOAT32_C(  -814.84), SIMDE_FLOAT32_C(   339.53), SIMDE_FLOAT32_C(   752.45), SIMDE_FLOAT32_C(   506.49),
        SIMDE_FLOAT32_C(   805.35), SIMDE_FLOAT32_C(   854.71), SIMDE_FLOAT32_C(   919.95), SIMDE_FLOAT32_C(  -649.37) },
      { SIMDE_FLOAT32_C(  -977.01),            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -461.97),
        SIMDE_FLOAT32_C(   372.08), SIMDE_FLOAT32_C(   780.19), SIMDE_FLOAT32_C(   704.84), SIMDE_FLOAT32_C(   703.98),
        SIMDE_FLOAT32_C(   276.72), SIMDE_FLOAT32_C(   339.53), SIMDE_FLOAT32_C(   752.45), SIMDE_FLOAT32_C(   506.49),
        SIMDE_FLOAT32_C(   869.62), SIMDE_FLOAT32_C(  -302.69), SIMDE_FLOAT32_C(   919.95), SIMDE_FLOAT32_C(   892.61) },
      UINT16_C(    7) },
    { {            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(    72.37), SIMDE_FLOAT32_C(  -862.11),
        SIMDE_FLOAT32_C(   400.81), SIMDE_FLOAT32_C(   257.54), SIMDE_FLOAT32_C(   477.42), SIMDE_FLOAT32_C(   153.26),
        SIMDE_FLOAT32_C(  -235.97), SIMDE_FLOAT32_C(   282.77), SIMDE_FLOAT32_C(     7.97), SIMDE_FLOAT32_C(  -316.02),
        SIMDE_FLOAT32_C(   633.40), SIMDE_FLOAT32_C(  -271.85), SIMDE_FLOAT32_C(  -234.18), SIMDE_FLOAT32_C(  -525.10) },
      { SIMDE_FLOAT32_C(  -569.36),            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -862.11),
        SIMDE_FLOAT32_C(   642.71), SIMDE_FLOAT32_C(   257.54), SIMDE_FLOAT32_C(  -901.18), SIMDE_FLOAT32_C(  -753.48),
        SIMDE_FLOAT32_C(   951.92), SIMDE_FLOAT32_C(   968.44), SIMDE_FLOAT32_C(   -56.17), SIMDE_FLOAT32_C(  -316.02),
        SIMDE_FLOAT32_C(   633.40), SIMDE_FLOAT32_C(  -580.24), SIMDE_FLOAT32_C(   559.34), SIMDE_FLOAT32_C(  -525.10) },
      UINT16_C(26583) },
    { {            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   889.25), SIMDE_FLOAT32_C(   907.00),
        SIMDE_FLOAT32_C(   821.84), SIMDE_FLOAT32_C(  -346.72), SIMDE_FLOAT32_C(   189.77), SIMDE_FLOAT32_C(  -170.19),
        SIMDE_FLOAT32_C(   337.26), SIMDE_FLOAT32_C(  -176.83), SIMDE_FLOAT32_C(   557.96), SIMDE_FLOAT32_C(  -896.92),
        SIMDE_FLOAT32_C(   298.07), SIMDE_FLOAT32_C(   234.35), SIMDE_FLOAT32_C(  -958.19), SIMDE_FLOAT32_C(   328.27) },
      { SIMDE_FLOAT32_C(  -570.42),            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -285.59),
        SIMDE_FLOAT32_C(   931.04), SIMDE_FLOAT32_C(  -412.88), SIMDE_FLOAT32_C(  -317.16), SIMDE_FLOAT32_C(  -170.19),
        SIMDE_FLOAT32_C(   337.26), SIMDE_FLOAT32_C(  -456.11), SIMDE_FLOAT32_C(   557.96), SIMDE_FLOAT32_C(  -586.38),
        SIMDE_FLOAT32_C(   298.07), SIMDE_FLOAT32_C(   234.35), SIMDE_FLOAT32_C(  -958.19), SIMDE_FLOAT32_C(   328.27) },
      UINT16_C(63471) },
    { {            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   587.85), SIMDE_FLOAT32_C(  -638.08),
        SIMDE_FLOAT32_C(   882.64), SIMDE_FLOAT32_C(   -74.89), SIMDE_FLOAT32_C(   185.09), SIMDE_FLOAT32_C(   440.60),
        SIMDE_FLOAT32_C(    28.19), SIMDE_FLOAT32_C(  -516.84), SIMDE_FLOAT32_C(  -325.05), SIMDE_FLOAT32_C(    69.99),
        SIMDE_FLOAT32_C(   811.43), SIMDE_FLOAT32_C(   290.54), SIMDE_FLOAT32_C(  -245.49), SIMDE_FLOAT32_C(  -553.37) },
      { SIMDE_FLOAT32_C(   172.16),            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -312.22),
        SIMDE_FLOAT32_C(   882.64), SIMDE_FLOAT32_C(   -74.89), SIMDE_FLOAT32_C(   231.67), SIMDE_FLOAT32_C(   440.60),
        SIMDE_FLOAT32_C(  -698.35), SIMDE_FLOAT32_C(  -932.75), SIMDE_FLOAT32_C(  -325.05), SIMDE_FLOAT32_C(   346.97),
        SIMDE_FLOAT32_C(   332.41), SIMDE_FLOAT32_C(  -351.53), SIMDE_FLOAT32_C(  -245.49), SIMDE_FLOAT32_C(  -495.43) },
      UINT16_C(13063) },
    { {            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -205.49), SIMDE_FLOAT32_C(  -948.42),
        SIMDE_FLOAT32_C(    24.54), SIMDE_FLOAT32_C(   822.70), SIMDE_FLOAT32_C(  -465.26), SIMDE_FLOAT32_C(   699.49),
        SIMDE_FLOAT32_C(  -107.31), SIMDE_FLOAT32_C(  -653.83), SIMDE_FLOAT32_C(    -9.98), SIMDE_FLOAT32_C(   647.21),
        SIMDE_FLOAT32_C(  -207.19), SIMDE_FLOAT32_C(    -5.03), SIMDE_FLOAT32_C(  -667.24), SIMDE_FLOAT32_C(   826.56) },
      { SIMDE_FLOAT32_C(  -133.51),            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   -85.57),
        SIMDE_FLOAT32_C(    24.54), SIMDE_FLOAT32_C(  -983.76), SIMDE_FLOAT32_C(   -18.32), SIMDE_FLOAT32_C(   699.49),
        SIMDE_FLOAT32_C(   363.22), SIMDE_FLOAT32_C(  -653.83), SIMDE_FLOAT32_C(  -185.79), SIMDE_FLOAT32_C(   647.21),
        SIMDE_FLOAT32_C(  -181.34), SIMDE_FLOAT32_C(  -484.49), SIMDE_FLOAT32_C(   514.17), SIMDE_FLOAT32_C(   685.14) },
      UINT16_C(65528) },
    { {            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -868.62), SIMDE_FLOAT32_C(  -728.54),
        SIMDE_FLOAT32_C(  -176.52), SIMDE_FLOAT32_C(    24.08), SIMDE_FLOAT32_C(  -382.37), SIMDE_FLOAT32_C(   813.50),
        SIMDE_FLOAT32_C(  -328.72), SIMDE_FLOAT32_C(   410.44), SIMDE_FLOAT32_C(  -191.53), SIMDE_FLOAT32_C(     4.04),
        SIMDE_FLOAT32_C(   237.00), SIMDE_FLOAT32_C(  -508.78), SIMDE_FLOAT32_C(  -102.77), SIMDE_FLOAT32_C(   -48.41) },
      { SIMDE_FLOAT32_C(   736.73),            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -612.67),
        SIMDE_FLOAT32_C(  -176.52), SIMDE_FLOAT32_C(  -668.95), SIMDE_FLOAT32_C(  -382.37), SIMDE_FLOAT32_C(   813.50),
        SIMDE_FLOAT32_C(   975.82), SIMDE_FLOAT32_C(   410.44), SIMDE_FLOAT32_C(  -191.53), SIMDE_FLOAT32_C(     4.04),
        SIMDE_FLOAT32_C(   237.00), SIMDE_FLOAT32_C(  -508.78), SIMDE_FLOAT32_C(  -102.77), SIMDE_FLOAT32_C(   -48.41) },
      UINT16_C(65239) },
    { {            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   -45.88), SIMDE_FLOAT32_C(   831.04),
        SIMDE_FLOAT32_C(     1.37), SIMDE_FLOAT32_C(   625.40), SIMDE_FLOAT32_C(   241.48), SIMDE_FLOAT32_C(   809.84),
        SIMDE_FLOAT32_C(  -370.55), SIMDE_FLOAT32_C(  -521.52), SIMDE_FLOAT32_C(  -698.94), SIMDE_FLOAT32_C(   526.68),
        SIMDE_FLOAT32_C(   430.07), SIMDE_FLOAT32_C(   706.71), SIMDE_FLOAT32_C(   172.17), SIMDE_FLOAT32_C(  -602.09) },
      { SIMDE_FLOAT32_C(   213.41),            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -204.55),
        SIMDE_FLOAT32_C(     1.37), SIMDE_FLOAT32_C(  -295.23), SIMDE_FLOAT32_C(   241.48), SIMDE_FLOAT32_C(  -250.22),
        SIMDE_FLOAT32_C(  -805.24), SIMDE_FLOAT32_C(   520.74), SIMDE_FLOAT32_C(  -698.94), SIMDE_FLOAT32_C(   993.42),
        SIMDE_FLOAT32_C(  -537.32), SIMDE_FLOAT32_C(  -645.42), SIMDE_FLOAT32_C(   172.17), SIMDE_FLOAT32_C(  -602.09) },
      UINT16_C( 2567) },
    { {            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -497.00), SIMDE_FLOAT32_C(  -251.40),
        SIMDE_FLOAT32_C(  -646.33), SIMDE_FLOAT32_C(   132.44), SIMDE_FLOAT32_C(   227.08), SIMDE_FLOAT32_C(  -345.27),
        SIMDE_FLOAT32_C(  -340.88), SIMDE_FLOAT32_C(  -342.84), SIMDE_FLOAT32_C(  -638.56), SIMDE_FLOAT32_C(   831.28),
        SIMDE_FLOAT32_C(    55.07), SIMDE_FLOAT32_C(  -544.52), SIMDE_FLOAT32_C(  -185.32), SIMDE_FLOAT32_C(   784.02) },
      { SIMDE_FLOAT32_C(   250.93),            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -251.40),
        SIMDE_FLOAT32_C(  -646.33), SIMDE_FLOAT32_C(  -316.44), SIMDE_FLOAT32_C(    87.19), SIMDE_FLOAT32_C(  -345.27),
        SIMDE_FLOAT32_C(  -323.02), SIMDE_FLOAT32_C(   549.87), SIMDE_FLOAT32_C(  -638.56), SIMDE_FLOAT32_C(   831.28),
        SIMDE_FLOAT32_C(    55.07), SIMDE_FLOAT32_C(  -544.52), SIMDE_FLOAT32_C(  -185.32), SIMDE_FLOAT32_C(   784.02) },
      UINT16_C(65439) },
    { {            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   113.48), SIMDE_FLOAT32_C(  -291.23),
        SIMDE_FLOAT32_C(  -387.26), SIMDE_FLOAT32_C(   772.60), SIMDE_FLOAT32_C(   365.92), SIMDE_FLOAT32_C(   -25.82),
        SIMDE_FLOAT32_C(   603.89), SIMDE_FLOAT32_C(  -579.01), SIMDE_FLOAT32_C(   429.66), SIMDE_FLOAT32_C(  -581.44),
        SIMDE_FLOAT32_C(  -794.99), SIMDE_FLOAT32_C(  -319.41), SIMDE_FLOAT32_C(  -157.93), SIMDE_FLOAT32_C(  -306.19) },
      { SIMDE_FLOAT32_C(   481.68),            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -291.23),
        SIMDE_FLOAT32_C(  -387.26), SIMDE_FLOAT32_C(  -945.65), SIMDE_FLOAT32_C(  -115.91), SIMDE_FLOAT32_C(   -25.82),
        SIMDE_FLOAT32_C(  -345.20), SIMDE_FLOAT32_C(  -579.01), SIMDE_FLOAT32_C(   757.39), SIMDE_FLOAT32_C(  -867.15),
        SIMDE_FLOAT32_C(  -156.87), SIMDE_FLOAT32_C(   361.73), SIMDE_FLOAT32_C(  -886.11), SIMDE_FLOAT32_C(  -306.19) },
      UINT16_C(    0) },
    { {            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(    -0.03), SIMDE_FLOAT32_C(  -600.50),
        SIMDE_FLOAT32_C(   -93.35), SIMDE_FLOAT32_C(  -396.14), SIMDE_FLOAT32_C(  -179.51), SIMDE_FLOAT32_C(  -663.69),
        SIMDE_FLOAT32_C(    22.42), SIMDE_FLOAT32_C(    25.50), SIMDE_FLOAT32_C(    16.90), SIMDE_FLOAT32_C(   864.49),
        SIMDE_FLOAT32_C(   719.32), SIMDE_FLOAT32_C(   263.94), SIMDE_FLOAT32_C(   879.85), SIMDE_FLOAT32_C(    96.69) },
      { SIMDE_FLOAT32_C(    33.57),            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -600.50),
        SIMDE_FLOAT32_C(   755.57), SIMDE_FLOAT32_C(   805.84), SIMDE_FLOAT32_C(   592.31), SIMDE_FLOAT32_C(  -663.69),
        SIMDE_FLOAT32_C(   938.69), SIMDE_FLOAT32_C(  -564.57), SIMDE_FLOAT32_C(    16.90), SIMDE_FLOAT32_C(  -947.42),
        SIMDE_FLOAT32_C(  -239.76), SIMDE_FLOAT32_C(   263.94), SIMDE_FLOAT32_C(   279.95), SIMDE_FLOAT32_C(   793.82) },
      UINT16_C(56176) },
    { {            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -116.23), SIMDE_FLOAT32_C(    13.81),
        SIMDE_FLOAT32_C(   369.86), SIMDE_FLOAT32_C(   906.19), SIMDE_FLOAT32_C(  -960.69), SIMDE_FLOAT32_C(  -613.24),
        SIMDE_FLOAT32_C(   770.68), SIMDE_FLOAT32_C(   758.63), SIMDE_FLOAT32_C(   650.70), SIMDE_FLOAT32_C(   650.54),
        SIMDE_FLOAT32_C(  -144.69), SIMDE_FLOAT32_C(  -751.14), SIMDE_FLOAT32_C(  -290.78), SIMDE_FLOAT32_C(  -993.65) },
      { SIMDE_FLOAT32_C(  -806.68),            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   323.43),
        SIMDE_FLOAT32_C(   369.86), SIMDE_FLOAT32_C(   750.88), SIMDE_FLOAT32_C(   758.87), SIMDE_FLOAT32_C(  -613.24),
        SIMDE_FLOAT32_C(   803.46), SIMDE_FLOAT32_C(   758.63), SIMDE_FLOAT32_C(    46.88), SIMDE_FLOAT32_C(    83.41),
        SIMDE_FLOAT32_C(  -687.07), SIMDE_FLOAT32_C(   173.78), SIMDE_FLOAT32_C(   363.33), SIMDE_FLOAT32_C(  -493.76) },
      UINT16_C( 7856) },
    { {            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -846.71), SIMDE_FLOAT32_C(   559.36),
        SIMDE_FLOAT32_C(   963.95), SIMDE_FLOAT32_C(   923.98), SIMDE_FLOAT32_C(   317.98), SIMDE_FLOAT32_C(   614.64),
        SIMDE_FLOAT32_C(   574.51), SIMDE_FLOAT32_C(  -826.70), SIMDE_FLOAT32_C(   863.51), SIMDE_FLOAT32_C(  -716.26),
        SIMDE_FLOAT32_C(  -820.36), SIMDE_FLOAT32_C(   594.63), SIMDE_FLOAT32_C(  -251.47), SIMDE_FLOAT32_C(   991.84) },
      { SIMDE_FLOAT32_C(   -81.93),            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -323.06),
        SIMDE_FLOAT32_C(   578.75), SIMDE_FLOAT32_C(   923.98), SIMDE_FLOAT32_C(   196.05), SIMDE_FLOAT32_C(  -374.36),
        SIMDE_FLOAT32_C(  -370.41), SIMDE_FLOAT32_C(   508.97), SIMDE_FLOAT32_C(   863.51), SIMDE_FLOAT32_C(   992.91),
        SIMDE_FLOAT32_C(  -820.36), SIMDE_FLOAT32_C(   594.63), SIMDE_FLOAT32_C(  -251.47), SIMDE_FLOAT32_C(   991.84) },
      UINT16_C(  472) },
    { {            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -682.72), SIMDE_FLOAT32_C(  -587.39),
        SIMDE_FLOAT32_C(   162.51), SIMDE_FLOAT32_C(   891.79), SIMDE_FLOAT32_C(  -414.09), SIMDE_FLOAT32_C(    26.02),
        SIMDE_FLOAT32_C(  -824.47), SIMDE_FLOAT32_C(  -234.45), SIMDE_FLOAT32_C(  -379.34), SIMDE_FLOAT32_C(   -75.94),
        SIMDE_FLOAT32_C(  -242.61), SIMDE_FLOAT32_C(   538.73), SIMDE_FLOAT32_C(   650.36), SIMDE_FLOAT32_C(  -499.89) },
      { SIMDE_FLOAT32_C(    94.63),            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   411.71),
        SIMDE_FLOAT32_C(   854.75), SIMDE_FLOAT32_C(  -324.13), SIMDE_FLOAT32_C(  -414.09), SIMDE_FLOAT32_C(   654.16),
        SIMDE_FLOAT32_C(  -331.22), SIMDE_FLOAT32_C(   -64.10), SIMDE_FLOAT32_C(  -379.34), SIMDE_FLOAT32_C(   -91.21),
        SIMDE_FLOAT32_C(  -528.83), SIMDE_FLOAT32_C(   538.73), SIMDE_FLOAT32_C(   302.10), SIMDE_FLOAT32_C(   565.79) },
           UINT16_MAX },
    { {            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   511.17), SIMDE_FLOAT32_C(  -435.69),
        SIMDE_FLOAT32_C(   -18.77), SIMDE_FLOAT32_C(   686.70), SIMDE_FLOAT32_C(   329.86), SIMDE_FLOAT32_C(   601.89),
        SIMDE_FLOAT32_C(  -389.24), SIMDE_FLOAT32_C(  -912.75), SIMDE_FLOAT32_C(   140.62), SIMDE_FLOAT32_C(  -738.88),
        SIMDE_FLOAT32_C(  -412.65), SIMDE_FLOAT32_C(   356.28), SIMDE_FLOAT32_C(   490.24), SIMDE_FLOAT32_C(  -366.36) },
      { SIMDE_FLOAT32_C(   978.40),            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -435.69),
        SIMDE_FLOAT32_C(    -0.85), SIMDE_FLOAT32_C(   686.70), SIMDE_FLOAT32_C(  -375.43), SIMDE_FLOAT32_C(  -339.95),
        SIMDE_FLOAT32_C(  -389.24), SIMDE_FLOAT32_C(  -912.75), SIMDE_FLOAT32_C(   904.88), SIMDE_FLOAT32_C(  -738.88),
        SIMDE_FLOAT32_C(  -338.47), SIMDE_FLOAT32_C(   356.28), SIMDE_FLOAT32_C(   490.24), SIMDE_FLOAT32_C(  -366.36) },
      UINT16_C(60200) },
    { {            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(     6.43), SIMDE_FLOAT32_C(  -465.89),
        SIMDE_FLOAT32_C(   235.91), SIMDE_FLOAT32_C(   617.19), SIMDE_FLOAT32_C(  -378.65), SIMDE_FLOAT32_C(  -623.48),
        SIMDE_FLOAT32_C(   878.32), SIMDE_FLOAT32_C(   208.71), SIMDE_FLOAT32_C(   732.80), SIMDE_FLOAT32_C(   368.55),
        SIMDE_FLOAT32_C(   842.35), SIMDE_FLOAT32_C(  -499.21), SIMDE_FLOAT32_C(  -286.46), SIMDE_FLOAT32_C(   151.86) },
      { SIMDE_FLOAT32_C(  -810.55),            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -185.98),
        SIMDE_FLOAT32_C(   235.91), SIMDE_FLOAT32_C(   617.19), SIMDE_FLOAT32_C(   909.76), SIMDE_FLOAT32_C(  -623.48),
        SIMDE_FLOAT32_C(  -793.58), SIMDE_FLOAT32_C(   208.71), SIMDE_FLOAT32_C(   732.80), SIMDE_FLOAT32_C(  -985.03),
        SIMDE_FLOAT32_C(   842.35), SIMDE_FLOAT32_C(  -499.21), SIMDE_FLOAT32_C(  -286.46), SIMDE_FLOAT32_C(  -584.53) },
      UINT16_C(   72) },
    { {            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   958.32), SIMDE_FLOAT32_C(   570.93),
        SIMDE_FLOAT32_C(  -125.57), SIMDE_FLOAT32_C(   836.63), SIMDE_FLOAT32_C(  -220.36), SIMDE_FLOAT32_C(  -392.77),
        SIMDE_FLOAT32_C(   205.19), SIMDE_FLOAT32_C(  -378.01), SIMDE_FLOAT32_C(   108.02), SIMDE_FLOAT32_C(   918.73),
        SIMDE_FLOAT32_C(   773.85), SIMDE_FLOAT32_C(   297.47), SIMDE_FLOAT32_C(   631.42), SIMDE_FLOAT32_C(   -96.00) },
      { SIMDE_FLOAT32_C(  -888.51),            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   570.93),
        SIMDE_FLOAT32_C(  -125.57), SIMDE_FLOAT32_C(   127.66), SIMDE_FLOAT32_C(  -407.46), SIMDE_FLOAT32_C(  -392.77),
        SIMDE_FLOAT32_C(   205.19), SIMDE_FLOAT32_C(  -378.01), SIMDE_FLOAT32_C(  -115.05), SIMDE_FLOAT32_C(   918.73),
        SIMDE_FLOAT32_C(   773.85), SIMDE_FLOAT32_C(   297.47), SIMDE_FLOAT32_C(   631.42), SIMDE_FLOAT32_C(   168.81) },
      UINT16_C(64408) },
    { {            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -386.59), SIMDE_FLOAT32_C(   519.38),
        SIMDE_FLOAT32_C(  -873.48), SIMDE_FLOAT32_C(   818.60), SIMDE_FLOAT32_C(  -858.63), SIMDE_FLOAT32_C(   234.54),
        SIMDE_FLOAT32_C(   737.33), SIMDE_FLOAT32_C(   915.22), SIMDE_FLOAT32_C(  -467.99), SIMDE_FLOAT32_C(   368.74),
        SIMDE_FLOAT32_C(  -180.78), SIMDE_FLOAT32_C(  -356.50), SIMDE_FLOAT32_C(   372.90), SIMDE_FLOAT32_C(   740.45) },
      { SIMDE_FLOAT32_C(  -335.25),            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   257.29),
        SIMDE_FLOAT32_C(  -873.48), SIMDE_FLOAT32_C(   818.60), SIMDE_FLOAT32_C(  -858.63), SIMDE_FLOAT32_C(   796.60),
        SIMDE_FLOAT32_C(  -511.93), SIMDE_FLOAT32_C(   280.28), SIMDE_FLOAT32_C(   943.55), SIMDE_FLOAT32_C(   368.74),
        SIMDE_FLOAT32_C(  -180.78), SIMDE_FLOAT32_C(  -356.50), SIMDE_FLOAT32_C(   372.90), SIMDE_FLOAT32_C(   188.83) },
      UINT16_C(    7) },
    { {            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -484.68), SIMDE_FLOAT32_C(  -150.43),
        SIMDE_FLOAT32_C(   468.75), SIMDE_FLOAT32_C(  -747.35), SIMDE_FLOAT32_C(  -235.22), SIMDE_FLOAT32_C(  -999.25),
        SIMDE_FLOAT32_C(   621.39), SIMDE_FLOAT32_C(   584.00), SIMDE_FLOAT32_C(  -355.74), SIMDE_FLOAT32_C(    -5.71),
        SIMDE_FLOAT32_C(   324.45), SIMDE_FLOAT32_C(   309.01), SIMDE_FLOAT32_C(  -351.04), SIMDE_FLOAT32_C(  -807.44) },
      { SIMDE_FLOAT32_C(  -291.80),            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -150.43),
        SIMDE_FLOAT32_C(   357.20), SIMDE_FLOAT32_C(  -747.35), SIMDE_FLOAT32_C(  -235.22), SIMDE_FLOAT32_C(   300.75),
        SIMDE_FLOAT32_C(   997.90), SIMDE_FLOAT32_C(   356.72), SIMDE_FLOAT32_C(   889.15), SIMDE_FLOAT32_C(    -5.71),
        SIMDE_FLOAT32_C(   324.45), SIMDE_FLOAT32_C(   996.84), SIMDE_FLOAT32_C(  -351.04), SIMDE_FLOAT32_C(  -807.44) },
      UINT16_C(10135) },
    { {            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   545.90), SIMDE_FLOAT32_C(  -131.90),
        SIMDE_FLOAT32_C(   700.55), SIMDE_FLOAT32_C(   167.29), SIMDE_FLOAT32_C(  -547.90), SIMDE_FLOAT32_C(  -655.19),
        SIMDE_FLOAT32_C(  -838.42), SIMDE_FLOAT32_C(   776.56), SIMDE_FLOAT32_C(   653.81), SIMDE_FLOAT32_C(  -189.46),
        SIMDE_FLOAT32_C(   969.12), SIMDE_FLOAT32_C(  -779.89), SIMDE_FLOAT32_C(  -628.85), SIMDE_FLOAT32_C(  -827.58) },
      { SIMDE_FLOAT32_C(  -896.68),            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -131.90),
        SIMDE_FLOAT32_C(    29.10), SIMDE_FLOAT32_C(   167.29), SIMDE_FLOAT32_C(  -547.90), SIMDE_FLOAT32_C(   -81.75),
        SIMDE_FLOAT32_C(  -838.42), SIMDE_FLOAT32_C(  -342.64), SIMDE_FLOAT32_C(   -84.91), SIMDE_FLOAT32_C(  -189.46),
        SIMDE_FLOAT32_C(   969.12), SIMDE_FLOAT32_C(   146.14), SIMDE_FLOAT32_C(    14.11), SIMDE_FLOAT32_C(  -985.57) },
      UINT16_C(40831) },
    { {            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   727.30), SIMDE_FLOAT32_C(   334.64),
        SIMDE_FLOAT32_C(  -108.71), SIMDE_FLOAT32_C(   888.88), SIMDE_FLOAT32_C(   111.20), SIMDE_FLOAT32_C(  -454.90),
        SIMDE_FLOAT32_C(  -300.58), SIMDE_FLOAT32_C(    80.32), SIMDE_FLOAT32_C(  -234.78), SIMDE_FLOAT32_C(    70.57),
        SIMDE_FLOAT32_C(   252.74), SIMDE_FLOAT32_C(  -387.32), SIMDE_FLOAT32_C(  -201.08), SIMDE_FLOAT32_C(  -883.47) },
      { SIMDE_FLOAT32_C(   367.78),            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   479.60),
        SIMDE_FLOAT32_C(  -253.73), SIMDE_FLOAT32_C(   888.88), SIMDE_FLOAT32_C(   111.20), SIMDE_FLOAT32_C(  -454.90),
        SIMDE_FLOAT32_C(  -300.58), SIMDE_FLOAT32_C(  -951.92), SIMDE_FLOAT32_C(  -192.50), SIMDE_FLOAT32_C(  -343.90),
        SIMDE_FLOAT32_C(   252.74), SIMDE_FLOAT32_C(  -387.32), SIMDE_FLOAT32_C(  -201.08), SIMDE_FLOAT32_C(  -883.47) },
      UINT16_C( 2583) },
    { {            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -167.70), SIMDE_FLOAT32_C(   390.88),
        SIMDE_FLOAT32_C(   636.32), SIMDE_FLOAT32_C(   531.72), SIMDE_FLOAT32_C(  -528.80), SIMDE_FLOAT32_C(  -598.46),
        SIMDE_FLOAT32_C(  -397.71), SIMDE_FLOAT32_C(   723.94), SIMDE_FLOAT32_C(    14.22), SIMDE_FLOAT32_C(   401.21),
        SIMDE_FLOAT32_C(   840.47), SIMDE_FLOAT32_C(  -618.00), SIMDE_FLOAT32_C(   229.23), SIMDE_FLOAT32_C(  -181.30) },
      { SIMDE_FLOAT32_C(   861.60),            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   998.57),
        SIMDE_FLOAT32_C(   636.86), SIMDE_FLOAT32_C(   531.72), SIMDE_FLOAT32_C(  -528.80), SIMDE_FLOAT32_C(  -555.63),
        SIMDE_FLOAT32_C(  -397.71), SIMDE_FLOAT32_C(  -890.85), SIMDE_FLOAT32_C(  -902.19), SIMDE_FLOAT32_C(  -745.95),
        SIMDE_FLOAT32_C(   840.47), SIMDE_FLOAT32_C(  -702.27), SIMDE_FLOAT32_C(   229.23), SIMDE_FLOAT32_C(  -181.30) },
      UINT16_C(65528) },
    { {            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   561.47), SIMDE_FLOAT32_C(   195.97),
        SIMDE_FLOAT32_C(   426.80), SIMDE_FLOAT32_C(  -836.24), SIMDE_FLOAT32_C(   -80.09), SIMDE_FLOAT32_C(  -558.97),
        SIMDE_FLOAT32_C(   564.97), SIMDE_FLOAT32_C(  -239.62), SIMDE_FLOAT32_C(  -176.97), SIMDE_FLOAT32_C(  -205.81),
        SIMDE_FLOAT32_C(   579.08), SIMDE_FLOAT32_C(  -315.37), SIMDE_FLOAT32_C(  -230.31), SIMDE_FLOAT32_C(  -681.08) },
      { SIMDE_FLOAT32_C(  -316.80),            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -270.16),
        SIMDE_FLOAT32_C(  -149.08), SIMDE_FLOAT32_C(  -836.24), SIMDE_FLOAT32_C(  -161.00), SIMDE_FLOAT32_C(   -51.27),
        SIMDE_FLOAT32_C(   992.75), SIMDE_FLOAT32_C(  -239.62), SIMDE_FLOAT32_C(  -176.97), SIMDE_FLOAT32_C(  -205.81),
        SIMDE_FLOAT32_C(   579.08), SIMDE_FLOAT32_C(  -364.60), SIMDE_FLOAT32_C(  -230.31), SIMDE_FLOAT32_C(  -681.08) },
      UINT16_C(56871) },
    { {            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   -54.80), SIMDE_FLOAT32_C(  -932.26),
        SIMDE_FLOAT32_C(   528.50), SIMDE_FLOAT32_C(  -489.84), SIMDE_FLOAT32_C(  -171.88), SIMDE_FLOAT32_C(  -648.48),
        SIMDE_FLOAT32_C(   304.36), SIMDE_FLOAT32_C(  -592.80), SIMDE_FLOAT32_C(    36.16), SIMDE_FLOAT32_C(  -925.95),
        SIMDE_FLOAT32_C(  -273.88), SIMDE_FLOAT32_C(   719.36), SIMDE_FLOAT32_C(  -519.40), SIMDE_FLOAT32_C(   426.88) },
      { SIMDE_FLOAT32_C(  -550.80),            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -932.26),
        SIMDE_FLOAT32_C(   528.50), SIMDE_FLOAT32_C(  -489.84), SIMDE_FLOAT32_C(   181.40), SIMDE_FLOAT32_C(   526.71),
        SIMDE_FLOAT32_C(  -651.46), SIMDE_FLOAT32_C(  -592.80), SIMDE_FLOAT32_C(  -837.89), SIMDE_FLOAT32_C(   568.50),
        SIMDE_FLOAT32_C(  -273.88), SIMDE_FLOAT32_C(   822.78), SIMDE_FLOAT32_C(  -650.06), SIMDE_FLOAT32_C(   508.17) },
      UINT16_C(43207) },
    { {            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   805.30), SIMDE_FLOAT32_C(  -595.98),
        SIMDE_FLOAT32_C(  -209.73), SIMDE_FLOAT32_C(   109.66), SIMDE_FLOAT32_C(  -188.79), SIMDE_FLOAT32_C(   826.42),
        SIMDE_FLOAT32_C(   183.71), SIMDE_FLOAT32_C(   537.34), SIMDE_FLOAT32_C(   545.78), SIMDE_FLOAT32_C(   664.31),
        SIMDE_FLOAT32_C(   -35.78), SIMDE_FLOAT32_C(   994.98), SIMDE_FLOAT32_C(    -4.17), SIMDE_FLOAT32_C(  -870.20) },
      { SIMDE_FLOAT32_C(   575.90),            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -595.98),
        SIMDE_FLOAT32_C(  -209.73), SIMDE_FLOAT32_C(   109.66), SIMDE_FLOAT32_C(  -188.79), SIMDE_FLOAT32_C(   826.42),
        SIMDE_FLOAT32_C(   183.71), SIMDE_FLOAT32_C(   537.34), SIMDE_FLOAT32_C(   545.78), SIMDE_FLOAT32_C(   555.11),
        SIMDE_FLOAT32_C(  -258.43), SIMDE_FLOAT32_C(   697.92), SIMDE_FLOAT32_C(    -4.17), SIMDE_FLOAT32_C(  -682.53) },
      UINT16_C(51199) },
    { {            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   765.20), SIMDE_FLOAT32_C(   532.70),
        SIMDE_FLOAT32_C(  -246.65), SIMDE_FLOAT32_C(   -51.09), SIMDE_FLOAT32_C(    70.04), SIMDE_FLOAT32_C(  -700.87),
        SIMDE_FLOAT32_C(  -386.79), SIMDE_FLOAT32_C(  -965.74), SIMDE_FLOAT32_C(  -705.88), SIMDE_FLOAT32_C(   609.04),
        SIMDE_FLOAT32_C(  -835.94), SIMDE_FLOAT32_C(   577.30), SIMDE_FLOAT32_C(  -114.88), SIMDE_FLOAT32_C(   452.19) },
      { SIMDE_FLOAT32_C(  -958.12),            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   -85.05),
        SIMDE_FLOAT32_C(  -347.19), SIMDE_FLOAT32_C(   -51.09), SIMDE_FLOAT32_C(    70.04), SIMDE_FLOAT32_C(   440.48),
        SIMDE_FLOAT32_C(  -386.79), SIMDE_FLOAT32_C(  -110.08), SIMDE_FLOAT32_C(   138.40), SIMDE_FLOAT32_C(  -300.61),
        SIMDE_FLOAT32_C(   207.39), SIMDE_FLOAT32_C(   275.06), SIMDE_FLOAT32_C(  -114.88), SIMDE_FLOAT32_C(   452.19) },
      UINT16_C(    0) },
    { {            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -930.96), SIMDE_FLOAT32_C(  -468.38),
        SIMDE_FLOAT32_C(   254.48), SIMDE_FLOAT32_C(  -317.74), SIMDE_FLOAT32_C(  -434.12), SIMDE_FLOAT32_C(   548.60),
        SIMDE_FLOAT32_C(  -708.70), SIMDE_FLOAT32_C(  -270.06), SIMDE_FLOAT32_C(   125.90), SIMDE_FLOAT32_C(   176.42),
        SIMDE_FLOAT32_C(  -817.87), SIMDE_FLOAT32_C(   167.78), SIMDE_FLOAT32_C(  -135.67), SIMDE_FLOAT32_C(   271.00) },
      { SIMDE_FLOAT32_C(   461.58),            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -468.38),
        SIMDE_FLOAT32_C(   -42.38), SIMDE_FLOAT32_C(   414.18), SIMDE_FLOAT32_C(   121.01), SIMDE_FLOAT32_C(   548.60),
        SIMDE_FLOAT32_C(  -886.43), SIMDE_FLOAT32_C(  -671.60), SIMDE_FLOAT32_C(   371.08), SIMDE_FLOAT32_C(   468.51),
        SIMDE_FLOAT32_C(  -742.72), SIMDE_FLOAT32_C(   573.07), SIMDE_FLOAT32_C(  -135.67), SIMDE_FLOAT32_C(   718.86) },
      UINT16_C(49008) },
    { {            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   339.94), SIMDE_FLOAT32_C(  -183.64),
        SIMDE_FLOAT32_C(   331.50), SIMDE_FLOAT32_C(   631.24), SIMDE_FLOAT32_C(   546.30), SIMDE_FLOAT32_C(  -542.60),
        SIMDE_FLOAT32_C(  -192.33), SIMDE_FLOAT32_C(   728.44), SIMDE_FLOAT32_C(   625.18), SIMDE_FLOAT32_C(   672.00),
        SIMDE_FLOAT32_C(    -0.57), SIMDE_FLOAT32_C(   707.92), SIMDE_FLOAT32_C(   189.14), SIMDE_FLOAT32_C(  -435.53) },
      { SIMDE_FLOAT32_C(  -749.52),            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(    60.01),
        SIMDE_FLOAT32_C(   331.50), SIMDE_FLOAT32_C(   631.24), SIMDE_FLOAT32_C(   388.41), SIMDE_FLOAT32_C(  -542.60),
        SIMDE_FLOAT32_C(   560.74), SIMDE_FLOAT32_C(   728.44), SIMDE_FLOAT32_C(   186.93), SIMDE_FLOAT32_C(   672.00),
        SIMDE_FLOAT32_C(   364.55), SIMDE_FLOAT32_C(   707.92), SIMDE_FLOAT32_C(   189.14), SIMDE_FLOAT32_C(   615.03) },
      UINT16_C(28400) },
    { {            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   778.26), SIMDE_FLOAT32_C(   977.70),
        SIMDE_FLOAT32_C(   287.15), SIMDE_FLOAT32_C(  -414.08), SIMDE_FLOAT32_C(   706.14), SIMDE_FLOAT32_C(   -87.67),
        SIMDE_FLOAT32_C(  -742.08), SIMDE_FLOAT32_C(  -294.43), SIMDE_FLOAT32_C(  -379.75), SIMDE_FLOAT32_C(   447.06),
        SIMDE_FLOAT32_C(   270.04), SIMDE_FLOAT32_C(  -440.75), SIMDE_FLOAT32_C(   593.82), SIMDE_FLOAT32_C(   248.70) },
      { SIMDE_FLOAT32_C(   619.26),            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   977.70),
        SIMDE_FLOAT32_C(   450.45), SIMDE_FLOAT32_C(  -414.08), SIMDE_FLOAT32_C(   706.14), SIMDE_FLOAT32_C(   -87.67),
        SIMDE_FLOAT32_C(  -742.08), SIMDE_FLOAT32_C(  -294.43), SIMDE_FLOAT32_C(  -647.28), SIMDE_FLOAT32_C(   858.12),
        SIMDE_FLOAT32_C(   270.04), SIMDE_FLOAT32_C(   850.97), SIMDE_FLOAT32_C(   593.82), SIMDE_FLOAT32_C(   248.70) },
      UINT16_C( 1024) },
    { {            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -630.69), SIMDE_FLOAT32_C(   748.16),
        SIMDE_FLOAT32_C(  -119.80), SIMDE_FLOAT32_C(  -372.76), SIMDE_FLOAT32_C(  -546.27), SIMDE_FLOAT32_C(   500.45),
        SIMDE_FLOAT32_C(  -925.71), SIMDE_FLOAT32_C(   723.77), SIMDE_FLOAT32_C(  -940.30), SIMDE_FLOAT32_C(   668.11),
        SIMDE_FLOAT32_C(   -27.53), SIMDE_FLOAT32_C(   678.96), SIMDE_FLOAT32_C(   504.70), SIMDE_FLOAT32_C(  -686.60) },
      { SIMDE_FLOAT32_C(  -313.38),            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   748.16),
        SIMDE_FLOAT32_C(  -119.80), SIMDE_FLOAT32_C(  -733.89), SIMDE_FLOAT32_C(  -546.27), SIMDE_FLOAT32_C(   945.25),
        SIMDE_FLOAT32_C(  -875.77), SIMDE_FLOAT32_C(    -9.20), SIMDE_FLOAT32_C(   796.22), SIMDE_FLOAT32_C(  -870.63),
        SIMDE_FLOAT32_C(    55.13), SIMDE_FLOAT32_C(   678.96), SIMDE_FLOAT32_C(   912.76), SIMDE_FLOAT32_C(  -686.60) },
           UINT16_MAX }
  };

  simde__m512 a, b;
  simde__mmask16 r;

  a = simde_mm512_loadu_ps(test_vec[0].a);
  b = simde_mm512_loadu_ps(test_vec[0].b);
  r = simde_mm512_cmp_ps_mask(a, b, SIMDE_CMP_EQ_OQ);
  simde_assert_equal_mmask16(r, test_vec[0].r);

  a = simde_mm512_loadu_ps(test_vec[1].a);
  b = simde_mm512_loadu_ps(test_vec[1].b);
  r = simde_mm512_cmp_ps_mask(a, b, SIMDE_CMP_LT_OS);
  simde_assert_equal_mmask16(r, test_vec[1].r);

  a = simde_mm512_loadu_ps(test_vec[2].a);
  b = simde_mm512_loadu_ps(test_vec[2].b);
  r = simde_mm512_cmp_ps_mask(a, b, SIMDE_CMP_LE_OS);
  simde_assert_equal_mmask16(r, test_vec[2].r);

  a = simde_mm512_loadu_ps(test_vec[3].a);
  b = simde_mm512_loadu_ps(test_vec[3].b);
  r = simde_mm512_cmp_ps_mask(a, b, SIMDE_CMP_UNORD_Q);
  simde_assert_equal_mmask16(r, test_vec[3].r);

  a = simde_mm512_loadu_ps(test_vec[4].a);
  b = simde_mm512_loadu_ps(test_vec[4].b);
  r = simde_mm512_cmp_ps_mask(a, b, SIMDE_CMP_NEQ_UQ);
  simde_assert_equal_mmask16(r, test_vec[4].r);

  a = simde_mm512_loadu_ps(test_vec[5].a);
  b = simde_mm512_loadu_ps(test_vec[5].b);
  r = simde_mm512_cmp_ps_mask(a, b, SIMDE_CMP_NLT_US);
  simde_assert_equal_mmask16(r, test_vec[5].r);

  a = simde_mm512_loadu_ps(test_vec[6].a);
  b = simde_mm512_loadu_ps(test_vec[6].b);
  r = simde_mm512_cmp_ps_mask(a, b, SIMDE_CMP_NLE_US);
  simde_assert_equal_mmask16(r, test_vec[6].r);

  a = simde_mm512_loadu_ps(test_vec[7].a);
  b = simde_mm512_loadu_ps(test_vec[7].b);
  r = simde_mm512_cmp_ps_mask(a, b, SIMDE_CMP_ORD_Q);
  simde_assert_equal_mmask16(r, test_vec[7].r);

  a = simde_mm512_loadu_ps(test_vec[8].a);
  b = simde_mm512_loadu_ps(test_vec[8].b);
  r = simde_mm512_cmp_ps_mask(a, b, SIMDE_CMP_EQ_UQ);
  simde_assert_equal_mmask16(r, test_vec[8].r);

  a = simde_mm512_loadu_ps(test_vec[9].a);
  b = simde_mm512_loadu_ps(test_vec[9].b);
  r = simde_mm512_cmp_ps_mask(a, b, SIMDE_CMP_NGE_US);
  simde_assert_equal_mmask16(r, test_vec[9].r);

  a = simde_mm512_loadu_ps(test_vec[10].a);
  b = simde_mm512_loadu_ps(test_vec[10].b);
  r = simde_mm512_cmp_ps_mask(a, b, SIMDE_CMP_NGT_US);
  simde_assert_equal_mmask16(r, test_vec[10].r);

  a = simde_mm512_loadu_ps(test_vec[11].a);
  b = simde_mm512_loadu_ps(test_vec[11].b);
  r = simde_mm512_cmp_ps_mask(a, b, SIMDE_CMP_FALSE_OQ);
  simde_assert_equal_mmask16(r, test_vec[11].r);

  a = simde_mm512_loadu_ps(test_vec[12].a);
  b = simde_mm512_loadu_ps(test_vec[12].b);
  r = simde_mm512_cmp_ps_mask(a, b, SIMDE_CMP_NEQ_OQ);
  simde_assert_equal_mmask16(r, test_vec[12].r);

  a = simde_mm512_loadu_ps(test_vec[13].a);
  b = simde_mm512_loadu_ps(test_vec[13].b);
  r = simde_mm512_cmp_ps_mask(a, b, SIMDE_CMP_GE_OS);
  simde_assert_equal_mmask16(r, test_vec[13].r);

  a = simde_mm512_loadu_ps(test_vec[14].a);
  b = simde_mm512_loadu_ps(test_vec[14].b);
  r = simde_mm512_cmp_ps_mask(a, b, SIMDE_CMP_GT_OS);
  simde_assert_equal_mmask16(r, test_vec[14].r);

  a = simde_mm512_loadu_ps(test_vec[15].a);
  b = simde_mm512_loadu_ps(test_vec[15].b);
  r = simde_mm512_cmp_ps_mask(a, b, SIMDE_CMP_TRUE_UQ);
  simde_assert_equal_mmask16(r, test_vec[15].r);

  a = simde_mm512_loadu_ps(test_vec[16].a);
  b = simde_mm512_loadu_ps(test_vec[16].b);
  r = simde_mm512_cmp_ps_mask(a, b, SIMDE_CMP_EQ_OS);
  simde_assert_equal_mmask16(r, test_vec[16].r);

  a = simde_mm512_loadu_ps(test_vec[17].a);
  b = simde_mm512_loadu_ps(test_vec[17].b);
  r = simde_mm512_cmp_ps_mask(a, b, SIMDE_CMP_LT_OQ);
  simde_assert_equal_mmask16(r, test_vec[17].r);

  a = simde_mm512_loadu_ps(test_vec[18].a);
  b = simde_mm512_loadu_ps(test_vec[18].b);
  r = simde_mm512_cmp_ps_mask(a, b, SIMDE_CMP_LE_OQ);
  simde_assert_equal_mmask16(r, test_vec[18].r);

  a = simde_mm512_loadu_ps(test_vec[19].a);
  b = simde_mm512_loadu_ps(test_vec[19].b);
  r = simde_mm512_cmp_ps_mask(a, b, SIMDE_CMP_UNORD_S);
  simde_assert_equal_mmask16(r, test_vec[19].r);

  a = simde_mm512_loadu_ps(test_vec[20].a);
  b = simde_mm512_loadu_ps(test_vec[20].b);
  r = simde_mm512_cmp_ps_mask(a, b, SIMDE_CMP_NEQ_US);
  simde_assert_equal_mmask16(r, test_vec[20].r);

  a = simde_mm512_loadu_ps(test_vec[21].a);
  b = simde_mm512_loadu_ps(test_vec[21].b);
  r = simde_mm512_cmp_ps_mask(a, b, SIMDE_CMP_NLT_UQ);
  simde_assert_equal_mmask16(r, test_vec[21].r);

  a = simde_mm512_loadu_ps(test_vec[22].a);
  b = simde_mm512_loadu_ps(test_vec[22].b);
  r = simde_mm512_cmp_ps_mask(a, b, SIMDE_CMP_NLE_UQ);
  simde_assert_equal_mmask16(r, test_vec[22].r);

  a = simde_mm512_loadu_ps(test_vec[23].a);
  b = simde_mm512_loadu_ps(test_vec[23].b);
  r = simde_mm512_cmp_ps_mask(a, b, SIMDE_CMP_ORD_S);
  simde_assert_equal_mmask16(r, test_vec[23].r);

  a = simde_mm512_loadu_ps(test_vec[24].a);
  b = simde_mm512_loadu_ps(test_vec[24].b);
  r = simde_mm512_cmp_ps_mask(a, b, SIMDE_CMP_EQ_US);
  simde_assert_equal_mmask16(r, test_vec[24].r);

  a = simde_mm512_loadu_ps(test_vec[25].a);
  b = simde_mm512_loadu_ps(test_vec[25].b);
  r = simde_mm512_cmp_ps_mask(a, b, SIMDE_CMP_NGE_UQ);
  simde_assert_equal_mmask16(r, test_vec[25].r);

  a = simde_mm512_loadu_ps(test_vec[26].a);
  b = simde_mm512_loadu_ps(test_vec[26].b);
  r = simde_mm512_cmp_ps_mask(a, b, SIMDE_CMP_NGT_UQ);
  simde_assert_equal_mmask16(r, test_vec[26].r);

  a = simde_mm512_loadu_ps(test_vec[27].a);
  b = simde_mm512_loadu_ps(test_vec[27].b);
  r = simde_mm512_cmp_ps_mask(a, b, SIMDE_CMP_FALSE_OS);
  simde_assert_equal_mmask16(r, test_vec[27].r);

  a = simde_mm512_loadu_ps(test_vec[28].a);
  b = simde_mm512_loadu_ps(test_vec[28].b);
  r = simde_mm512_cmp_ps_mask(a, b, SIMDE_CMP_NEQ_OS);
  simde_assert_equal_mmask16(r, test_vec[28].r);

  a = simde_mm512_loadu_ps(test_vec[29].a);
  b = simde_mm512_loadu_ps(test_vec[29].b);
  r = simde_mm512_cmp_ps_mask(a, b, SIMDE_CMP_GE_OQ);
  simde_assert_equal_mmask16(r, test_vec[29].r);

  a = simde_mm512_loadu_ps(test_vec[30].a);
  b = simde_mm512_loadu_ps(test_vec[30].b);
  r = simde_mm512_cmp_ps_mask(a, b, SIMDE_CMP_GT_OQ);
  simde_assert_equal_mmask16(r, test_vec[30].r);

  a = simde_mm512_loadu_ps(test_vec[31].a);
  b = simde_mm512_loadu_ps(test_vec[31].b);
  r = simde_mm512_cmp_ps_mask(a, b, SIMDE_CMP_TRUE_US);
  simde_assert_equal_mmask16(r, test_vec[31].r);

  return 0;
#else
  fputc('\n', stdout);

  const simde__m512 nanv = simde_mm512_set1_ps(SIMDE_MATH_NANF);

  simde__m512 a, b;
  simde__mmask16 r;

  a = simde_test_x86_random_f32x16(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
  b = simde_test_x86_random_f32x16(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
  b = simde_mm512_mask_mov_ps(a, HEDLEY_STATIC_CAST(simde__mmask16, simde_test_codegen_random_i16()), b);
  a = simde_mm512_mask_mov_ps(a, HEDLEY_STATIC_CAST(simde__mmask16, 3), nanv);
  b = simde_mm512_mask_mov_ps(b, HEDLEY_STATIC_CAST(simde__mmask16, 6), nanv);
  r = simde_mm512_cmp_ps_mask(a, b, SIMDE_CMP_EQ_OQ);
  simde_test_x86_write_f32x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_f32x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask16(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_f32x16(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
  b = simde_test_x86_random_f32x16(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
  b = simde_mm512_mask_mov_ps(a, HEDLEY_STATIC_CAST(simde__mmask16, simde_test_codegen_random_i16()), b);
  a = simde_mm512_mask_mov_ps(a, HEDLEY_STATIC_CAST(simde__mmask16, 3), nanv);
  b = simde_mm512_mask_mov_ps(b, HEDLEY_STATIC_CAST(simde__mmask16, 6), nanv);
  r = simde_mm512_cmp_ps_mask(a, b, SIMDE_CMP_LT_OS);
  simde_test_x86_write_f32x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_f32x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask16(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_f32x16(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
  b = simde_test_x86_random_f32x16(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
  b = simde_mm512_mask_mov_ps(a, HEDLEY_STATIC_CAST(simde__mmask16, simde_test_codegen_random_i16()), b);
  a = simde_mm512_mask_mov_ps(a, HEDLEY_STATIC_CAST(simde__mmask16, 3), nanv);
  b = simde_mm512_mask_mov_ps(b, HEDLEY_STATIC_CAST(simde__mmask16, 6), nanv);
  r = simde_mm512_cmp_ps_mask(a, b, SIMDE_CMP_LE_OS);
  simde_test_x86_write_f32x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_f32x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask16(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_f32x16(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
  b = simde_test_x86_random_f32x16(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
  b = simde_mm512_mask_mov_ps(a, HEDLEY_STATIC_CAST(simde__mmask16, simde_test_codegen_random_i16()), b);
  a = simde_mm512_mask_mov_ps(a, HEDLEY_STATIC_CAST(simde__mmask16, 3), nanv);
  b = simde_mm512_mask_mov_ps(b, HEDLEY_STATIC_CAST(simde__mmask16, 6), nanv);
  r = simde_mm512_cmp_ps_mask(a, b, SIMDE_CMP_UNORD_Q);
  simde_test_x86_write_f32x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_f32x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask16(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_f32x16(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
  b = simde_test_x86_random_f32x16(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
  b = simde_mm512_mask_mov_ps(a, HEDLEY_STATIC_CAST(simde__mmask16, simde_test_codegen_random_i16()), b);
  a = simde_mm512_mask_mov_ps(a, HEDLEY_STATIC_CAST(simde__mmask16, 3), nanv);
  b = simde_mm512_mask_mov_ps(b, HEDLEY_STATIC_CAST(simde__mmask16, 6), nanv);
  r = simde_mm512_cmp_ps_mask(a, b, SIMDE_CMP_NEQ_UQ);
  simde_test_x86_write_f32x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_f32x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask16(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_f32x16(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
  b = simde_test_x86_random_f32x16(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
  b = simde_mm512_mask_mov_ps(a, HEDLEY_STATIC_CAST(simde__mmask16, simde_test_codegen_random_i16()), b);
  a = simde_mm512_mask_mov_ps(a, HEDLEY_STATIC_CAST(simde__mmask16, 3), nanv);
  b = simde_mm512_mask_mov_ps(b, HEDLEY_STATIC_CAST(simde__mmask16, 6), nanv);
  r = simde_mm512_cmp_ps_mask(a, b, SIMDE_CMP_NLT_US);
  simde_test_x86_write_f32x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_f32x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask16(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_f32x16(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
  b = simde_test_x86_random_f32x16(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
  b = simde_mm512_mask_mov_ps(a, HEDLEY_STATIC_CAST(simde__mmask16, simde_test_codegen_random_i16()), b);
  a = simde_mm512_mask_mov_ps(a, HEDLEY_STATIC_CAST(simde__mmask16, 3), nanv);
  b = simde_mm512_mask_mov_ps(b, HEDLEY_STATIC_CAST(simde__mmask16, 6), nanv);
  r = simde_mm512_cmp_ps_mask(a, b, SIMDE_CMP_NLE_US);
  simde_test_x86_write_f32x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_f32x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask16(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_f32x16(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
  b = simde_test_x86_random_f32x16(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
  b = simde_mm512_mask_mov_ps(a, HEDLEY_STATIC_CAST(simde__mmask16, simde_test_codegen_random_i16()), b);
  a = simde_mm512_mask_mov_ps(a, HEDLEY_STATIC_CAST(simde__mmask16, 3), nanv);
  b = simde_mm512_mask_mov_ps(b, HEDLEY_STATIC_CAST(simde__mmask16, 6), nanv);
  r = simde_mm512_cmp_ps_mask(a, b, SIMDE_CMP_ORD_Q);
  simde_test_x86_write_f32x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_f32x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask16(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_f32x16(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
  b = simde_test_x86_random_f32x16(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
  b = simde_mm512_mask_mov_ps(a, HEDLEY_STATIC_CAST(simde__mmask16, simde_test_codegen_random_i16()), b);
  a = simde_mm512_mask_mov_ps(a, HEDLEY_STATIC_CAST(simde__mmask16, 3), nanv);
  b = simde_mm512_mask_mov_ps(b, HEDLEY_STATIC_CAST(simde__mmask16, 6), nanv);
  r = simde_mm512_cmp_ps_mask(a, b, SIMDE_CMP_EQ_UQ);
  simde_test_x86_write_f32x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_f32x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask16(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_f32x16(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
  b = simde_test_x86_random_f32x16(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
  b = simde_mm512_mask_mov_ps(a, HEDLEY_STATIC_CAST(simde__mmask16, simde_test_codegen_random_i16()), b);
  a = simde_mm512_mask_mov_ps(a, HEDLEY_STATIC_CAST(simde__mmask16, 3), nanv);
  b = simde_mm512_mask_mov_ps(b, HEDLEY_STATIC_CAST(simde__mmask16, 6), nanv);
  r = simde_mm512_cmp_ps_mask(a, b, SIMDE_CMP_NGE_US);
  simde_test_x86_write_f32x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_f32x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask16(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_f32x16(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
  b = simde_test_x86_random_f32x16(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
  b = simde_mm512_mask_mov_ps(a, HEDLEY_STATIC_CAST(simde__mmask16, simde_test_codegen_random_i16()), b);
  a = simde_mm512_mask_mov_ps(a, HEDLEY_STATIC_CAST(simde__mmask16, 3), nanv);
  b = simde_mm512_mask_mov_ps(b, HEDLEY_STATIC_CAST(simde__mmask16, 6), nanv);
  r = simde_mm512_cmp_ps_mask(a, b, SIMDE_CMP_NGT_US);
  simde_test_x86_write_f32x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_f32x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask16(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_f32x16(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
  b = simde_test_x86_random_f32x16(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
  b = simde_mm512_mask_mov_ps(a, HEDLEY_STATIC_CAST(simde__mmask16, simde_test_codegen_random_i16()), b);
  a = simde_mm512_mask_mov_ps(a, HEDLEY_STATIC_CAST(simde__mmask16, 3), nanv);
  b = simde_mm512_mask_mov_ps(b, HEDLEY_STATIC_CAST(simde__mmask16, 6), nanv);
  r = simde_mm512_cmp_ps_mask(a, b, SIMDE_CMP_FALSE_OQ);
  simde_test_x86_write_f32x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_f32x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask16(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_f32x16(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
  b = simde_test_x86_random_f32x16(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
  b = simde_mm512_mask_mov_ps(a, HEDLEY_STATIC_CAST(simde__mmask16, simde_test_codegen_random_i16()), b);
  a = simde_mm512_mask_mov_ps(a, HEDLEY_STATIC_CAST(simde__mmask16, 3), nanv);
  b = simde_mm512_mask_mov_ps(b, HEDLEY_STATIC_CAST(simde__mmask16, 6), nanv);
  r = simde_mm512_cmp_ps_mask(a, b, SIMDE_CMP_NEQ_OQ);
  simde_test_x86_write_f32x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_f32x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask16(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_f32x16(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
  b = simde_test_x86_random_f32x16(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
  b = simde_mm512_mask_mov_ps(a, HEDLEY_STATIC_CAST(simde__mmask16, simde_test_codegen_random_i16()), b);
  a = simde_mm512_mask_mov_ps(a, HEDLEY_STATIC_CAST(simde__mmask16, 3), nanv);
  b = simde_mm512_mask_mov_ps(b, HEDLEY_STATIC_CAST(simde__mmask16, 6), nanv);
  r = simde_mm512_cmp_ps_mask(a, b, SIMDE_CMP_GE_OS);
  simde_test_x86_write_f32x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_f32x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask16(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_f32x16(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
  b = simde_test_x86_random_f32x16(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
  b = simde_mm512_mask_mov_ps(a, HEDLEY_STATIC_CAST(simde__mmask16, simde_test_codegen_random_i16()), b);
  a = simde_mm512_mask_mov_ps(a, HEDLEY_STATIC_CAST(simde__mmask16, 3), nanv);
  b = simde_mm512_mask_mov_ps(b, HEDLEY_STATIC_CAST(simde__mmask16, 6), nanv);
  r = simde_mm512_cmp_ps_mask(a, b, SIMDE_CMP_GT_OS);
  simde_test_x86_write_f32x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_f32x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask16(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_f32x16(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
  b = simde_test_x86_random_f32x16(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
  b = simde_mm512_mask_mov_ps(a, HEDLEY_STATIC_CAST(simde__mmask16, simde_test_codegen_random_i16()), b);
  a = simde_mm512_mask_mov_ps(a, HEDLEY_STATIC_CAST(simde__mmask16, 3), nanv);
  b = simde_mm512_mask_mov_ps(b, HEDLEY_STATIC_CAST(simde__mmask16, 6), nanv);
  r = simde_mm512_cmp_ps_mask(a, b, SIMDE_CMP_TRUE_UQ);
  simde_test_x86_write_f32x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_f32x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask16(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_f32x16(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
  b = simde_test_x86_random_f32x16(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
  b = simde_mm512_mask_mov_ps(a, HEDLEY_STATIC_CAST(simde__mmask16, simde_test_codegen_random_i16()), b);
  a = simde_mm512_mask_mov_ps(a, HEDLEY_STATIC_CAST(simde__mmask16, 3), nanv);
  b = simde_mm512_mask_mov_ps(b, HEDLEY_STATIC_CAST(simde__mmask16, 6), nanv);
  r = simde_mm512_cmp_ps_mask(a, b, SIMDE_CMP_EQ_OS);
  simde_test_x86_write_f32x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_f32x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask16(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_f32x16(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
  b = simde_test_x86_random_f32x16(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
  b = simde_mm512_mask_mov_ps(a, HEDLEY_STATIC_CAST(simde__mmask16, simde_test_codegen_random_i16()), b);
  a = simde_mm512_mask_mov_ps(a, HEDLEY_STATIC_CAST(simde__mmask16, 3), nanv);
  b = simde_mm512_mask_mov_ps(b, HEDLEY_STATIC_CAST(simde__mmask16, 6), nanv);
  r = simde_mm512_cmp_ps_mask(a, b, SIMDE_CMP_LT_OQ);
  simde_test_x86_write_f32x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_f32x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask16(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_f32x16(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
  b = simde_test_x86_random_f32x16(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
  b = simde_mm512_mask_mov_ps(a, HEDLEY_STATIC_CAST(simde__mmask16, simde_test_codegen_random_i16()), b);
  a = simde_mm512_mask_mov_ps(a, HEDLEY_STATIC_CAST(simde__mmask16, 3), nanv);
  b = simde_mm512_mask_mov_ps(b, HEDLEY_STATIC_CAST(simde__mmask16, 6), nanv);
  r = simde_mm512_cmp_ps_mask(a, b, SIMDE_CMP_LE_OQ);
  simde_test_x86_write_f32x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_f32x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask16(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_f32x16(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
  b = simde_test_x86_random_f32x16(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
  b = simde_mm512_mask_mov_ps(a, HEDLEY_STATIC_CAST(simde__mmask16, simde_test_codegen_random_i16()), b);
  a = simde_mm512_mask_mov_ps(a, HEDLEY_STATIC_CAST(simde__mmask16, 3), nanv);
  b = simde_mm512_mask_mov_ps(b, HEDLEY_STATIC_CAST(simde__mmask16, 6), nanv);
  r = simde_mm512_cmp_ps_mask(a, b, SIMDE_CMP_UNORD_S);
  simde_test_x86_write_f32x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_f32x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask16(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_f32x16(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
  b = simde_test_x86_random_f32x16(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
  b = simde_mm512_mask_mov_ps(a, HEDLEY_STATIC_CAST(simde__mmask16, simde_test_codegen_random_i16()), b);
  a = simde_mm512_mask_mov_ps(a, HEDLEY_STATIC_CAST(simde__mmask16, 3), nanv);
  b = simde_mm512_mask_mov_ps(b, HEDLEY_STATIC_CAST(simde__mmask16, 6), nanv);
  r = simde_mm512_cmp_ps_mask(a, b, SIMDE_CMP_NEQ_US);
  simde_test_x86_write_f32x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_f32x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask16(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_f32x16(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
  b = simde_test_x86_random_f32x16(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
  b = simde_mm512_mask_mov_ps(a, HEDLEY_STATIC_CAST(simde__mmask16, simde_test_codegen_random_i16()), b);
  a = simde_mm512_mask_mov_ps(a, HEDLEY_STATIC_CAST(simde__mmask16, 3), nanv);
  b = simde_mm512_mask_mov_ps(b, HEDLEY_STATIC_CAST(simde__mmask16, 6), nanv);
  r = simde_mm512_cmp_ps_mask(a, b, SIMDE_CMP_NLT_UQ);
  simde_test_x86_write_f32x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_f32x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask16(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_f32x16(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
  b = simde_test_x86_random_f32x16(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
  b = simde_mm512_mask_mov_ps(a, HEDLEY_STATIC_CAST(simde__mmask16, simde_test_codegen_random_i16()), b);
  a = simde_mm512_mask_mov_ps(a, HEDLEY_STATIC_CAST(simde__mmask16, 3), nanv);
  b = simde_mm512_mask_mov_ps(b, HEDLEY_STATIC_CAST(simde__mmask16, 6), nanv);
  r = simde_mm512_cmp_ps_mask(a, b, SIMDE_CMP_NLE_UQ);
  simde_test_x86_write_f32x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_f32x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask16(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_f32x16(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
  b = simde_test_x86_random_f32x16(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
  b = simde_mm512_mask_mov_ps(a, HEDLEY_STATIC_CAST(simde__mmask16, simde_test_codegen_random_i16()), b);
  a = simde_mm512_mask_mov_ps(a, HEDLEY_STATIC_CAST(simde__mmask16, 3), nanv);
  b = simde_mm512_mask_mov_ps(b, HEDLEY_STATIC_CAST(simde__mmask16, 6), nanv);
  r = simde_mm512_cmp_ps_mask(a, b, SIMDE_CMP_ORD_S);
  simde_test_x86_write_f32x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_f32x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask16(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_f32x16(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
  b = simde_test_x86_random_f32x16(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
  b = simde_mm512_mask_mov_ps(a, HEDLEY_STATIC_CAST(simde__mmask16, simde_test_codegen_random_i16()), b);
  a = simde_mm512_mask_mov_ps(a, HEDLEY_STATIC_CAST(simde__mmask16, 3), nanv);
  b = simde_mm512_mask_mov_ps(b, HEDLEY_STATIC_CAST(simde__mmask16, 6), nanv);
  r = simde_mm512_cmp_ps_mask(a, b, SIMDE_CMP_EQ_US);
  simde_test_x86_write_f32x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_f32x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask16(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_f32x16(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
  b = simde_test_x86_random_f32x16(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
  b = simde_mm512_mask_mov_ps(a, HEDLEY_STATIC_CAST(simde__mmask16, simde_test_codegen_random_i16()), b);
  a = simde_mm512_mask_mov_ps(a, HEDLEY_STATIC_CAST(simde__mmask16, 3), nanv);
  b = simde_mm512_mask_mov_ps(b, HEDLEY_STATIC_CAST(simde__mmask16, 6), nanv);
  r = simde_mm512_cmp_ps_mask(a, b, SIMDE_CMP_NGE_UQ);
  simde_test_x86_write_f32x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_f32x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask16(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_f32x16(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
  b = simde_test_x86_random_f32x16(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
  b = simde_mm512_mask_mov_ps(a, HEDLEY_STATIC_CAST(simde__mmask16, simde_test_codegen_random_i16()), b);
  a = simde_mm512_mask_mov_ps(a, HEDLEY_STATIC_CAST(simde__mmask16, 3), nanv);
  b = simde_mm512_mask_mov_ps(b, HEDLEY_STATIC_CAST(simde__mmask16, 6), nanv);
  r = simde_mm512_cmp_ps_mask(a, b, SIMDE_CMP_NGT_UQ);
  simde_test_x86_write_f32x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_f32x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask16(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_f32x16(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
  b = simde_test_x86_random_f32x16(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
  b = simde_mm512_mask_mov_ps(a, HEDLEY_STATIC_CAST(simde__mmask16, simde_test_codegen_random_i16()), b);
  a = simde_mm512_mask_mov_ps(a, HEDLEY_STATIC_CAST(simde__mmask16, 3), nanv);
  b = simde_mm512_mask_mov_ps(b, HEDLEY_STATIC_CAST(simde__mmask16, 6), nanv);
  r = simde_mm512_cmp_ps_mask(a, b, SIMDE_CMP_FALSE_OS);
  simde_test_x86_write_f32x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_f32x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask16(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_f32x16(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
  b = simde_test_x86_random_f32x16(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
  b = simde_mm512_mask_mov_ps(a, HEDLEY_STATIC_CAST(simde__mmask16, simde_test_codegen_random_i16()), b);
  a = simde_mm512_mask_mov_ps(a, HEDLEY_STATIC_CAST(simde__mmask16, 3), nanv);
  b = simde_mm512_mask_mov_ps(b, HEDLEY_STATIC_CAST(simde__mmask16, 6), nanv);
  r = simde_mm512_cmp_ps_mask(a, b, SIMDE_CMP_NEQ_OS);
  simde_test_x86_write_f32x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_f32x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask16(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_f32x16(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
  b = simde_test_x86_random_f32x16(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
  b = simde_mm512_mask_mov_ps(a, HEDLEY_STATIC_CAST(simde__mmask16, simde_test_codegen_random_i16()), b);
  a = simde_mm512_mask_mov_ps(a, HEDLEY_STATIC_CAST(simde__mmask16, 3), nanv);
  b = simde_mm512_mask_mov_ps(b, HEDLEY_STATIC_CAST(simde__mmask16, 6), nanv);
  r = simde_mm512_cmp_ps_mask(a, b, SIMDE_CMP_GE_OQ);
  simde_test_x86_write_f32x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_f32x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask16(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_f32x16(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
  b = simde_test_x86_random_f32x16(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
  b = simde_mm512_mask_mov_ps(a, HEDLEY_STATIC_CAST(simde__mmask16, simde_test_codegen_random_i16()), b);
  a = simde_mm512_mask_mov_ps(a, HEDLEY_STATIC_CAST(simde__mmask16, 3), nanv);
  b = simde_mm512_mask_mov_ps(b, HEDLEY_STATIC_CAST(simde__mmask16, 6), nanv);
  r = simde_mm512_cmp_ps_mask(a, b, SIMDE_CMP_GT_OQ);
  simde_test_x86_write_f32x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_f32x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask16(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_f32x16(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
  b = simde_test_x86_random_f32x16(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
  b = simde_mm512_mask_mov_ps(a, HEDLEY_STATIC_CAST(simde__mmask16, simde_test_codegen_random_i16()), b);
  a = simde_mm512_mask_mov_ps(a, HEDLEY_STATIC_CAST(simde__mmask16, 3), nanv);
  b = simde_mm512_mask_mov_ps(b, HEDLEY_STATIC_CAST(simde__mmask16, 6), nanv);
  r = simde_mm512_cmp_ps_mask(a, b, SIMDE_CMP_TRUE_US);
  simde_test_x86_write_f32x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_f32x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask16(2, r, SIMDE_TEST_VEC_POS_LAST);

  return 1;
#endif
}

static int
test_simde_mm256_cmp_ps_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  simde__m256 a, b;
  simde__mmask8 e, r;

  a = simde_mm256_set_ps(SIMDE_FLOAT32_C(  -521.70), SIMDE_FLOAT32_C(   208.95), SIMDE_FLOAT32_C(  -892.52), SIMDE_FLOAT32_C(   822.05),
                         SIMDE_FLOAT32_C(  -914.87), SIMDE_FLOAT32_C(   926.51), SIMDE_FLOAT32_C(  -568.65), SIMDE_FLOAT32_C(  -377.10));
  b = simde_mm256_set_ps(SIMDE_FLOAT32_C(   846.31), SIMDE_FLOAT32_C(  -287.77), SIMDE_FLOAT32_C(  -505.72), SIMDE_FLOAT32_C(  -231.66),
                         SIMDE_FLOAT32_C(   589.02), SIMDE_FLOAT32_C(  -703.08), SIMDE_FLOAT32_C(  -955.43), SIMDE_FLOAT32_C(   989.02));
  e = UINT8_C(  0);
  r = simde_mm256_cmp_ps_mask(a, b, SIMDE_CMP_EQ_OQ);
  simde_assert_equal_mmask8(r, e);

  a = simde_mm256_set_ps(SIMDE_FLOAT32_C(  -285.67), SIMDE_FLOAT32_C(  -694.44), SIMDE_FLOAT32_C(  -819.49), SIMDE_FLOAT32_C(   958.85),
                         SIMDE_FLOAT32_C(  -277.57), SIMDE_FLOAT32_C(   148.21), SIMDE_FLOAT32_C(   209.64), SIMDE_FLOAT32_C(  -545.40));
  b = simde_mm256_set_ps(SIMDE_FLOAT32_C(   646.39), SIMDE_FLOAT32_C(   361.60), SIMDE_FLOAT32_C(   -15.47), SIMDE_FLOAT32_C(    23.49),
                         SIMDE_FLOAT32_C(    66.16), SIMDE_FLOAT32_C(   788.78), SIMDE_FLOAT32_C(   421.77), SIMDE_FLOAT32_C(  -189.56));
  e = UINT8_C(239);
  r = simde_mm256_cmp_ps_mask(a, b, SIMDE_CMP_LT_OS);
  simde_assert_equal_mmask8(r, e);

  a = simde_mm256_set_ps(SIMDE_FLOAT32_C(   384.60), SIMDE_FLOAT32_C(   716.23), SIMDE_FLOAT32_C(   -59.52), SIMDE_FLOAT32_C(   395.59),
                         SIMDE_FLOAT32_C(   237.94), SIMDE_FLOAT32_C(   731.52), SIMDE_FLOAT32_C(   288.10), SIMDE_FLOAT32_C(   415.88));
  b = simde_mm256_set_ps(SIMDE_FLOAT32_C(   -37.96), SIMDE_FLOAT32_C(   599.69), SIMDE_FLOAT32_C(   685.85), SIMDE_FLOAT32_C(  -492.56),
                         SIMDE_FLOAT32_C(   753.39), SIMDE_FLOAT32_C(   -26.38), SIMDE_FLOAT32_C(  -986.84), SIMDE_FLOAT32_C(   -14.96));
  e = UINT8_C( 40);
  r = simde_mm256_cmp_ps_mask(a, b, SIMDE_CMP_LE_OS);
  simde_assert_equal_mmask8(r, e);

  a = simde_mm256_set_ps(SIMDE_FLOAT32_C(   738.86), SIMDE_FLOAT32_C(   568.67), SIMDE_FLOAT32_C(   990.03), SIMDE_FLOAT32_C(   -71.58),
                         SIMDE_FLOAT32_C(  -145.66), SIMDE_FLOAT32_C(   684.47), SIMDE_FLOAT32_C(  -252.09), SIMDE_FLOAT32_C(  -104.51));
  b = simde_mm256_set_ps(SIMDE_FLOAT32_C(   757.87), SIMDE_FLOAT32_C(  -918.31), SIMDE_FLOAT32_C(  -833.39), SIMDE_FLOAT32_C(  -658.02),
                         SIMDE_FLOAT32_C(  -564.70), SIMDE_FLOAT32_C(  -194.98), SIMDE_FLOAT32_C(   357.45), SIMDE_FLOAT32_C(   411.80));
  e = UINT8_C(  0);
  r = simde_mm256_cmp_ps_mask(a, b, SIMDE_CMP_UNORD_Q);
  simde_assert_equal_mmask8(r, e);

  a = simde_mm256_set_ps(SIMDE_FLOAT32_C(   738.73), SIMDE_FLOAT32_C(  -765.09), SIMDE_FLOAT32_C(  -287.96), SIMDE_FLOAT32_C(  -246.32),
                         SIMDE_FLOAT32_C(  -149.69), SIMDE_FLOAT32_C(    -4.20), SIMDE_FLOAT32_C(   813.21), SIMDE_FLOAT32_C(   454.72));
  b = simde_mm256_set_ps(SIMDE_FLOAT32_C(   789.87), SIMDE_FLOAT32_C(  -805.33), SIMDE_FLOAT32_C(    91.81), SIMDE_FLOAT32_C(  -105.62),
                         SIMDE_FLOAT32_C(   232.63), SIMDE_FLOAT32_C(   492.12), SIMDE_FLOAT32_C(   208.53), SIMDE_FLOAT32_C(  -274.80));
  e = UINT8_MAX;
  r = simde_mm256_cmp_ps_mask(a, b, SIMDE_CMP_NEQ_UQ);
  simde_assert_equal_mmask8(r, e);

  a = simde_mm256_set_ps(SIMDE_FLOAT32_C(   280.98), SIMDE_FLOAT32_C(  -493.00), SIMDE_FLOAT32_C(  -787.12), SIMDE_FLOAT32_C(   869.18),
                         SIMDE_FLOAT32_C(  -231.86), SIMDE_FLOAT32_C(  -355.79), SIMDE_FLOAT32_C(   879.15), SIMDE_FLOAT32_C(   839.72));
  b = simde_mm256_set_ps(SIMDE_FLOAT32_C(   -66.65), SIMDE_FLOAT32_C(   670.17), SIMDE_FLOAT32_C(   797.96), SIMDE_FLOAT32_C(   478.63),
                         SIMDE_FLOAT32_C(   912.31), SIMDE_FLOAT32_C(   716.28), SIMDE_FLOAT32_C(   312.02), SIMDE_FLOAT32_C(   570.33));
  e = UINT8_C(147);
  r = simde_mm256_cmp_ps_mask(a, b, SIMDE_CMP_NLT_US);
  simde_assert_equal_mmask8(r, e);

  a = simde_mm256_set_ps(SIMDE_FLOAT32_C(  -896.79), SIMDE_FLOAT32_C(  -896.41), SIMDE_FLOAT32_C(  -981.44), SIMDE_FLOAT32_C(   378.01),
                         SIMDE_FLOAT32_C(  -635.14), SIMDE_FLOAT32_C(   783.65), SIMDE_FLOAT32_C(  -334.02), SIMDE_FLOAT32_C(   611.17));
  b = simde_mm256_set_ps(SIMDE_FLOAT32_C(  -472.77), SIMDE_FLOAT32_C(   911.34), SIMDE_FLOAT32_C(   530.52), SIMDE_FLOAT32_C(  -312.49),
                         SIMDE_FLOAT32_C(  -878.53), SIMDE_FLOAT32_C(   335.84), SIMDE_FLOAT32_C(   595.70), SIMDE_FLOAT32_C(   227.09));
  e = UINT8_C( 29);
  r = simde_mm256_cmp_ps_mask(a, b, SIMDE_CMP_NLE_US);
  simde_assert_equal_mmask8(r, e);

  a = simde_mm256_set_ps(SIMDE_FLOAT32_C(  -661.25), SIMDE_FLOAT32_C(  -440.17), SIMDE_FLOAT32_C(   802.38), SIMDE_FLOAT32_C(  -231.58),
                         SIMDE_FLOAT32_C(   278.84), SIMDE_FLOAT32_C(   295.37), SIMDE_FLOAT32_C(  -444.45), SIMDE_FLOAT32_C(   409.66));
  b = simde_mm256_set_ps(SIMDE_FLOAT32_C(   685.24), SIMDE_FLOAT32_C(   526.37), SIMDE_FLOAT32_C(   921.23), SIMDE_FLOAT32_C(  -925.93),
                         SIMDE_FLOAT32_C(  -406.98), SIMDE_FLOAT32_C(  -748.94), SIMDE_FLOAT32_C(  -723.90), SIMDE_FLOAT32_C(   114.39));
  e = UINT8_MAX;
  r = simde_mm256_cmp_ps_mask(a, b, SIMDE_CMP_ORD_Q);
  simde_assert_equal_mmask8(r, e);

  a = simde_mm256_set_ps(SIMDE_FLOAT32_C(  -444.32), SIMDE_FLOAT32_C(  -931.57), SIMDE_FLOAT32_C(  -846.31), SIMDE_FLOAT32_C(   328.59),
                         SIMDE_FLOAT32_C(   965.22), SIMDE_FLOAT32_C(  -949.90), SIMDE_FLOAT32_C(   310.02), SIMDE_FLOAT32_C(  -412.80));
  b = simde_mm256_set_ps(SIMDE_FLOAT32_C(  -655.55), SIMDE_FLOAT32_C(   -35.87), SIMDE_FLOAT32_C(  -411.51), SIMDE_FLOAT32_C(   -65.21),
                         SIMDE_FLOAT32_C(  -563.10), SIMDE_FLOAT32_C(  -322.85), SIMDE_FLOAT32_C(   404.27), SIMDE_FLOAT32_C(   749.39));
  e = UINT8_C(  0);
  r = simde_mm256_cmp_ps_mask(a, b, SIMDE_CMP_EQ_UQ);
  simde_assert_equal_mmask8(r, e);

  a = simde_mm256_set_ps(SIMDE_FLOAT32_C(   176.28), SIMDE_FLOAT32_C(  -748.79), SIMDE_FLOAT32_C(  -816.88), SIMDE_FLOAT32_C(  -938.12),
                         SIMDE_FLOAT32_C(   912.46), SIMDE_FLOAT32_C(   623.29), SIMDE_FLOAT32_C(  -740.49), SIMDE_FLOAT32_C(   144.04));
  b = simde_mm256_set_ps(SIMDE_FLOAT32_C(    10.70), SIMDE_FLOAT32_C(  -781.47), SIMDE_FLOAT32_C(   295.67), SIMDE_FLOAT32_C(  -576.51),
                         SIMDE_FLOAT32_C(  -466.71), SIMDE_FLOAT32_C(   769.30), SIMDE_FLOAT32_C(  -497.74), SIMDE_FLOAT32_C(  -540.78));
  e = UINT8_C( 54);
  r = simde_mm256_cmp_ps_mask(a, b, SIMDE_CMP_NGE_US);
  simde_assert_equal_mmask8(r, e);

  a = simde_mm256_set_ps(SIMDE_FLOAT32_C(  -828.30), SIMDE_FLOAT32_C(  -510.04), SIMDE_FLOAT32_C(    44.34), SIMDE_FLOAT32_C(  -577.69),
                         SIMDE_FLOAT32_C(   934.28), SIMDE_FLOAT32_C(   -24.09), SIMDE_FLOAT32_C(  -731.37), SIMDE_FLOAT32_C(  -394.31));
  b = simde_mm256_set_ps(SIMDE_FLOAT32_C(  -100.36), SIMDE_FLOAT32_C(   727.85), SIMDE_FLOAT32_C(   572.74), SIMDE_FLOAT32_C(   755.60),
                         SIMDE_FLOAT32_C(   383.39), SIMDE_FLOAT32_C(  -391.40), SIMDE_FLOAT32_C(   167.11), SIMDE_FLOAT32_C(  -551.39));
  e = UINT8_C(242);
  r = simde_mm256_cmp_ps_mask(a, b, SIMDE_CMP_NGT_US);
  simde_assert_equal_mmask8(r, e);

  a = simde_mm256_set_ps(SIMDE_FLOAT32_C(   993.48), SIMDE_FLOAT32_C(    70.41), SIMDE_FLOAT32_C(    63.31), SIMDE_FLOAT32_C(   534.26),
                         SIMDE_FLOAT32_C(   894.13), SIMDE_FLOAT32_C(  -187.90), SIMDE_FLOAT32_C(   351.14), SIMDE_FLOAT32_C(   832.25));
  b = simde_mm256_set_ps(SIMDE_FLOAT32_C(  -258.93), SIMDE_FLOAT32_C(    -0.24), SIMDE_FLOAT32_C(  -254.70), SIMDE_FLOAT32_C(  -864.62),
                         SIMDE_FLOAT32_C(   989.07), SIMDE_FLOAT32_C(  -473.23), SIMDE_FLOAT32_C(  -160.29), SIMDE_FLOAT32_C(   565.58));
  e = UINT8_C(  0);
  r = simde_mm256_cmp_ps_mask(a, b, SIMDE_CMP_FALSE_OQ);
  simde_assert_equal_mmask8(r, e);

  a = simde_mm256_set_ps(SIMDE_FLOAT32_C(   468.62), SIMDE_FLOAT32_C(   607.95), SIMDE_FLOAT32_C(   165.31), SIMDE_FLOAT32_C(    20.01),
                         SIMDE_FLOAT32_C(   436.25), SIMDE_FLOAT32_C(  -324.65), SIMDE_FLOAT32_C(   975.68), SIMDE_FLOAT32_C(    13.93));
  b = simde_mm256_set_ps(SIMDE_FLOAT32_C(   621.54), SIMDE_FLOAT32_C(   -12.34), SIMDE_FLOAT32_C(  -420.14), SIMDE_FLOAT32_C(   789.29),
                         SIMDE_FLOAT32_C(  -911.98), SIMDE_FLOAT32_C(  -147.98), SIMDE_FLOAT32_C(  -783.45), SIMDE_FLOAT32_C(  -667.58));
  e = UINT8_MAX;
  r = simde_mm256_cmp_ps_mask(a, b, SIMDE_CMP_NEQ_OQ);
  simde_assert_equal_mmask8(r, e);

  a = simde_mm256_set_ps(SIMDE_FLOAT32_C(  -571.34), SIMDE_FLOAT32_C(   458.74), SIMDE_FLOAT32_C(  -413.92), SIMDE_FLOAT32_C(  -136.92),
                         SIMDE_FLOAT32_C(   465.26), SIMDE_FLOAT32_C(   515.67), SIMDE_FLOAT32_C(   799.77), SIMDE_FLOAT32_C(   931.00));
  b = simde_mm256_set_ps(SIMDE_FLOAT32_C(   744.75), SIMDE_FLOAT32_C(  -697.77), SIMDE_FLOAT32_C(   417.49), SIMDE_FLOAT32_C(  -269.18),
                         SIMDE_FLOAT32_C(   561.16), SIMDE_FLOAT32_C(  -582.28), SIMDE_FLOAT32_C(   985.51), SIMDE_FLOAT32_C(   425.78));
  e = UINT8_C( 85);
  r = simde_mm256_cmp_ps_mask(a, b, SIMDE_CMP_GE_OS);
  simde_assert_equal_mmask8(r, e);

  a = simde_mm256_set_ps(SIMDE_FLOAT32_C(  -524.68), SIMDE_FLOAT32_C(   881.80), SIMDE_FLOAT32_C(  -211.06), SIMDE_FLOAT32_C(  -857.10),
                         SIMDE_FLOAT32_C(  -586.82), SIMDE_FLOAT32_C(   180.99), SIMDE_FLOAT32_C(   -22.41), SIMDE_FLOAT32_C(   393.17));
  b = simde_mm256_set_ps(SIMDE_FLOAT32_C(   244.68), SIMDE_FLOAT32_C(  -583.68), SIMDE_FLOAT32_C(   551.01), SIMDE_FLOAT32_C(   313.68),
                         SIMDE_FLOAT32_C(  -205.22), SIMDE_FLOAT32_C(  -436.66), SIMDE_FLOAT32_C(  -266.18), SIMDE_FLOAT32_C(     5.49));
  e = UINT8_C( 71);
  r = simde_mm256_cmp_ps_mask(a, b, SIMDE_CMP_GT_OS);
  simde_assert_equal_mmask8(r, e);

  a = simde_mm256_set_ps(SIMDE_FLOAT32_C(   943.85), SIMDE_FLOAT32_C(  -357.49), SIMDE_FLOAT32_C(  -831.32), SIMDE_FLOAT32_C(  -481.93),
                         SIMDE_FLOAT32_C(  -786.15), SIMDE_FLOAT32_C(  -290.06), SIMDE_FLOAT32_C(   931.99), SIMDE_FLOAT32_C(   350.78));
  b = simde_mm256_set_ps(SIMDE_FLOAT32_C(   870.89), SIMDE_FLOAT32_C(  -370.24), SIMDE_FLOAT32_C(   807.25), SIMDE_FLOAT32_C(  -522.28),
                         SIMDE_FLOAT32_C(  -114.99), SIMDE_FLOAT32_C(   505.02), SIMDE_FLOAT32_C(    60.23), SIMDE_FLOAT32_C(  -845.81));
  e = UINT8_MAX;
  r = simde_mm256_cmp_ps_mask(a, b, SIMDE_CMP_TRUE_UQ);
  simde_assert_equal_mmask8(r, e);

  a = simde_mm256_set_ps(SIMDE_FLOAT32_C(   605.19), SIMDE_FLOAT32_C(   403.06), SIMDE_FLOAT32_C(  -834.13), SIMDE_FLOAT32_C(  -400.31),
                         SIMDE_FLOAT32_C(   -72.27), SIMDE_FLOAT32_C(  -715.93), SIMDE_FLOAT32_C(   810.75), SIMDE_FLOAT32_C(  -215.16));
  b = simde_mm256_set_ps(SIMDE_FLOAT32_C(  -131.82), SIMDE_FLOAT32_C(   458.04), SIMDE_FLOAT32_C(  -183.71), SIMDE_FLOAT32_C(   517.41),
                         SIMDE_FLOAT32_C(  -786.64), SIMDE_FLOAT32_C(  -600.03), SIMDE_FLOAT32_C(   966.40), SIMDE_FLOAT32_C(  -100.31));
  e = UINT8_C(  0);
  r = simde_mm256_cmp_ps_mask(a, b, SIMDE_CMP_EQ_OS);
  simde_assert_equal_mmask8(r, e);

  a = simde_mm256_set_ps(SIMDE_FLOAT32_C(  -509.15), SIMDE_FLOAT32_C(   210.20), SIMDE_FLOAT32_C(   724.55), SIMDE_FLOAT32_C(  -663.34),
                         SIMDE_FLOAT32_C(   266.35), SIMDE_FLOAT32_C(    82.04), SIMDE_FLOAT32_C(  -832.02), SIMDE_FLOAT32_C(  -251.72));
  b = simde_mm256_set_ps(SIMDE_FLOAT32_C(   307.30), SIMDE_FLOAT32_C(   133.40), SIMDE_FLOAT32_C(  -994.38), SIMDE_FLOAT32_C(  -477.53),
                         SIMDE_FLOAT32_C(   262.51), SIMDE_FLOAT32_C(   375.86), SIMDE_FLOAT32_C(  -284.78), SIMDE_FLOAT32_C(  -215.22));
  e = UINT8_C(151);
  r = simde_mm256_cmp_ps_mask(a, b, SIMDE_CMP_LT_OQ);
  simde_assert_equal_mmask8(r, e);

  a = simde_mm256_set_ps(SIMDE_FLOAT32_C(  -516.98), SIMDE_FLOAT32_C(  -978.75), SIMDE_FLOAT32_C(   638.09), SIMDE_FLOAT32_C(   583.33),
                         SIMDE_FLOAT32_C(  -583.93), SIMDE_FLOAT32_C(  -764.96), SIMDE_FLOAT32_C(   417.47), SIMDE_FLOAT32_C(   816.37));
  b = simde_mm256_set_ps(SIMDE_FLOAT32_C(   985.79), SIMDE_FLOAT32_C(   990.09), SIMDE_FLOAT32_C(  -845.58), SIMDE_FLOAT32_C(   237.51),
                         SIMDE_FLOAT32_C(   121.90), SIMDE_FLOAT32_C(  -303.62), SIMDE_FLOAT32_C(  -578.78), SIMDE_FLOAT32_C(   604.49));
  e = UINT8_C(204);
  r = simde_mm256_cmp_ps_mask(a, b, SIMDE_CMP_LE_OQ);
  simde_assert_equal_mmask8(r, e);

  a = simde_mm256_set_ps(SIMDE_FLOAT32_C(   581.46), SIMDE_FLOAT32_C(   149.92), SIMDE_FLOAT32_C(  -537.65), SIMDE_FLOAT32_C(  -203.32),
                         SIMDE_FLOAT32_C(  -340.94), SIMDE_FLOAT32_C(   252.14), SIMDE_FLOAT32_C(    72.13), SIMDE_FLOAT32_C(  -677.60));
  b = simde_mm256_set_ps(SIMDE_FLOAT32_C(  -652.22), SIMDE_FLOAT32_C(     7.34), SIMDE_FLOAT32_C(   977.37), SIMDE_FLOAT32_C(  -468.59),
                         SIMDE_FLOAT32_C(   700.03), SIMDE_FLOAT32_C(  -156.03), SIMDE_FLOAT32_C(  -474.22), SIMDE_FLOAT32_C(   177.57));
  e = UINT8_C(  0);
  r = simde_mm256_cmp_ps_mask(a, b, SIMDE_CMP_UNORD_S);
  simde_assert_equal_mmask8(r, e);

  a = simde_mm256_set_ps(SIMDE_FLOAT32_C(  -515.03), SIMDE_FLOAT32_C(   461.19), SIMDE_FLOAT32_C(  -214.90), SIMDE_FLOAT32_C(  -119.53),
                         SIMDE_FLOAT32_C(   -21.83), SIMDE_FLOAT32_C(  -236.15), SIMDE_FLOAT32_C(   242.38), SIMDE_FLOAT32_C(   394.83));
  b = simde_mm256_set_ps(SIMDE_FLOAT32_C(  -365.60), SIMDE_FLOAT32_C(  -570.38), SIMDE_FLOAT32_C(   596.96), SIMDE_FLOAT32_C(  -688.00),
                         SIMDE_FLOAT32_C(  -556.17), SIMDE_FLOAT32_C(   606.87), SIMDE_FLOAT32_C(  -842.43), SIMDE_FLOAT32_C(   206.32));
  e = UINT8_MAX;
  r = simde_mm256_cmp_ps_mask(a, b, SIMDE_CMP_NEQ_US);
  simde_assert_equal_mmask8(r, e);

  a = simde_mm256_set_ps(SIMDE_FLOAT32_C(   321.68), SIMDE_FLOAT32_C(    47.23), SIMDE_FLOAT32_C(  -556.61), SIMDE_FLOAT32_C(  -855.88),
                         SIMDE_FLOAT32_C(   465.77), SIMDE_FLOAT32_C(   293.47), SIMDE_FLOAT32_C(   681.77), SIMDE_FLOAT32_C(  -330.91));
  b = simde_mm256_set_ps(SIMDE_FLOAT32_C(   263.40), SIMDE_FLOAT32_C(   848.36), SIMDE_FLOAT32_C(  -970.94), SIMDE_FLOAT32_C(   868.56),
                         SIMDE_FLOAT32_C(   500.58), SIMDE_FLOAT32_C(    21.72), SIMDE_FLOAT32_C(   891.20), SIMDE_FLOAT32_C(   -30.83));
  e = UINT8_C(164);
  r = simde_mm256_cmp_ps_mask(a, b, SIMDE_CMP_NLT_UQ);
  simde_assert_equal_mmask8(r, e);

  a = simde_mm256_set_ps(SIMDE_FLOAT32_C(  -396.38), SIMDE_FLOAT32_C(  -363.13), SIMDE_FLOAT32_C(   702.76), SIMDE_FLOAT32_C(   397.30),
                         SIMDE_FLOAT32_C(  -848.09), SIMDE_FLOAT32_C(  -758.43), SIMDE_FLOAT32_C(  -387.80), SIMDE_FLOAT32_C(   271.43));
  b = simde_mm256_set_ps(SIMDE_FLOAT32_C(  -490.21), SIMDE_FLOAT32_C(  -193.27), SIMDE_FLOAT32_C(   477.07), SIMDE_FLOAT32_C(   840.70),
                         SIMDE_FLOAT32_C(  -827.67), SIMDE_FLOAT32_C(    47.45), SIMDE_FLOAT32_C(  -756.26), SIMDE_FLOAT32_C(   860.33));
  e = UINT8_C(162);
  r = simde_mm256_cmp_ps_mask(a, b, SIMDE_CMP_NLE_UQ);
  simde_assert_equal_mmask8(r, e);

  a = simde_mm256_set_ps(SIMDE_FLOAT32_C(   512.75), SIMDE_FLOAT32_C(  -375.36), SIMDE_FLOAT32_C(    22.78), SIMDE_FLOAT32_C(  -456.42),
                         SIMDE_FLOAT32_C(   302.96), SIMDE_FLOAT32_C(   975.56), SIMDE_FLOAT32_C(  -899.81), SIMDE_FLOAT32_C(   158.84));
  b = simde_mm256_set_ps(SIMDE_FLOAT32_C(   -53.14), SIMDE_FLOAT32_C(  -954.06), SIMDE_FLOAT32_C(  -138.32), SIMDE_FLOAT32_C(   675.42),
                         SIMDE_FLOAT32_C(  -217.45), SIMDE_FLOAT32_C(    13.33), SIMDE_FLOAT32_C(   646.36), SIMDE_FLOAT32_C(   -86.02));
  e = UINT8_MAX;
  r = simde_mm256_cmp_ps_mask(a, b, SIMDE_CMP_ORD_S);
  simde_assert_equal_mmask8(r, e);

  a = simde_mm256_set_ps(SIMDE_FLOAT32_C(   850.60), SIMDE_FLOAT32_C(   474.80), SIMDE_FLOAT32_C(   735.64), SIMDE_FLOAT32_C(   990.27),
                         SIMDE_FLOAT32_C(  -128.82), SIMDE_FLOAT32_C(    98.76), SIMDE_FLOAT32_C(  -712.49), SIMDE_FLOAT32_C(   473.88));
  b = simde_mm256_set_ps(SIMDE_FLOAT32_C(   158.16), SIMDE_FLOAT32_C(  -670.12), SIMDE_FLOAT32_C(  -170.35), SIMDE_FLOAT32_C(   999.32),
                         SIMDE_FLOAT32_C(   820.08), SIMDE_FLOAT32_C(  -977.08), SIMDE_FLOAT32_C(  -477.75), SIMDE_FLOAT32_C(   979.38));
  e = UINT8_C(  0);
  r = simde_mm256_cmp_ps_mask(a, b, SIMDE_CMP_EQ_US);
  simde_assert_equal_mmask8(r, e);

  a = simde_mm256_set_ps(SIMDE_FLOAT32_C(  -757.80), SIMDE_FLOAT32_C(   -13.83), SIMDE_FLOAT32_C(    85.77), SIMDE_FLOAT32_C(   328.22),
                         SIMDE_FLOAT32_C(   473.42), SIMDE_FLOAT32_C(  -538.88), SIMDE_FLOAT32_C(  -694.57), SIMDE_FLOAT32_C(   -70.16));
  b = simde_mm256_set_ps(SIMDE_FLOAT32_C(  -664.94), SIMDE_FLOAT32_C(   354.41), SIMDE_FLOAT32_C(    70.69), SIMDE_FLOAT32_C(  -138.82),
                         SIMDE_FLOAT32_C(  -592.45), SIMDE_FLOAT32_C(    24.74), SIMDE_FLOAT32_C(   999.49), SIMDE_FLOAT32_C(  -267.87));
  e = UINT8_C(198);
  r = simde_mm256_cmp_ps_mask(a, b, SIMDE_CMP_NGE_UQ);
  simde_assert_equal_mmask8(r, e);

  a = simde_mm256_set_ps(SIMDE_FLOAT32_C(  -831.82), SIMDE_FLOAT32_C(   199.06), SIMDE_FLOAT32_C(  -318.95), SIMDE_FLOAT32_C(  -811.20),
                         SIMDE_FLOAT32_C(   348.47), SIMDE_FLOAT32_C(   206.24), SIMDE_FLOAT32_C(  -546.83), SIMDE_FLOAT32_C(   358.20));
  b = simde_mm256_set_ps(SIMDE_FLOAT32_C(   -18.53), SIMDE_FLOAT32_C(  -639.22), SIMDE_FLOAT32_C(  -681.86), SIMDE_FLOAT32_C(  -948.37),
                         SIMDE_FLOAT32_C(   202.62), SIMDE_FLOAT32_C(   988.27), SIMDE_FLOAT32_C(   221.98), SIMDE_FLOAT32_C(   203.30));
  e = UINT8_C(134);
  r = simde_mm256_cmp_ps_mask(a, b, SIMDE_CMP_NGT_UQ);
  simde_assert_equal_mmask8(r, e);

  a = simde_mm256_set_ps(SIMDE_FLOAT32_C(  -360.20), SIMDE_FLOAT32_C(  -806.01), SIMDE_FLOAT32_C(   441.06), SIMDE_FLOAT32_C(   907.67),
                         SIMDE_FLOAT32_C(   951.79), SIMDE_FLOAT32_C(  -545.11), SIMDE_FLOAT32_C(  -178.10), SIMDE_FLOAT32_C(  -376.43));
  b = simde_mm256_set_ps(SIMDE_FLOAT32_C(   647.62), SIMDE_FLOAT32_C(  -363.20), SIMDE_FLOAT32_C(  -598.24), SIMDE_FLOAT32_C(  -710.58),
                         SIMDE_FLOAT32_C(  -698.26), SIMDE_FLOAT32_C(    47.35), SIMDE_FLOAT32_C(   218.73), SIMDE_FLOAT32_C(   440.56));
  e = UINT8_C(  0);
  r = simde_mm256_cmp_ps_mask(a, b, SIMDE_CMP_FALSE_OS);
  simde_assert_equal_mmask8(r, e);

  a = simde_mm256_set_ps(SIMDE_FLOAT32_C(   727.38), SIMDE_FLOAT32_C(   211.91), SIMDE_FLOAT32_C(  -804.86), SIMDE_FLOAT32_C(  -475.91),
                         SIMDE_FLOAT32_C(    43.73), SIMDE_FLOAT32_C(    -3.92), SIMDE_FLOAT32_C(   843.04), SIMDE_FLOAT32_C(  -145.07));
  b = simde_mm256_set_ps(SIMDE_FLOAT32_C(  -858.11), SIMDE_FLOAT32_C(  -549.77), SIMDE_FLOAT32_C(   290.78), SIMDE_FLOAT32_C(   518.32),
                         SIMDE_FLOAT32_C(   468.76), SIMDE_FLOAT32_C(   -70.00), SIMDE_FLOAT32_C(   200.18), SIMDE_FLOAT32_C(   417.13));
  e = UINT8_MAX;
  r = simde_mm256_cmp_ps_mask(a, b, SIMDE_CMP_NEQ_OS);
  simde_assert_equal_mmask8(r, e);

  a = simde_mm256_set_ps(SIMDE_FLOAT32_C(   786.75), SIMDE_FLOAT32_C(  -339.84), SIMDE_FLOAT32_C(  -712.33), SIMDE_FLOAT32_C(  -653.81),
                         SIMDE_FLOAT32_C(  -979.64), SIMDE_FLOAT32_C(  -906.32), SIMDE_FLOAT32_C(   -94.88), SIMDE_FLOAT32_C(  -887.31));
  b = simde_mm256_set_ps(SIMDE_FLOAT32_C(   -35.80), SIMDE_FLOAT32_C(   443.44), SIMDE_FLOAT32_C(  -274.72), SIMDE_FLOAT32_C(  -890.73),
                         SIMDE_FLOAT32_C(   795.82), SIMDE_FLOAT32_C(  -911.52), SIMDE_FLOAT32_C(   707.51), SIMDE_FLOAT32_C(   506.40));
  e = UINT8_C(148);
  r = simde_mm256_cmp_ps_mask(a, b, SIMDE_CMP_GE_OQ);
  simde_assert_equal_mmask8(r, e);

  a = simde_mm256_set_ps(SIMDE_FLOAT32_C(  -948.21), SIMDE_FLOAT32_C(  -180.21), SIMDE_FLOAT32_C(   219.84), SIMDE_FLOAT32_C(  -365.33),
                         SIMDE_FLOAT32_C(    92.40), SIMDE_FLOAT32_C(  -992.07), SIMDE_FLOAT32_C(  -560.48), SIMDE_FLOAT32_C(  -431.68));
  b = simde_mm256_set_ps(SIMDE_FLOAT32_C(   153.26), SIMDE_FLOAT32_C(  -919.77), SIMDE_FLOAT32_C(   970.78), SIMDE_FLOAT32_C(    40.57),
                         SIMDE_FLOAT32_C(   938.34), SIMDE_FLOAT32_C(   520.55), SIMDE_FLOAT32_C(   749.79), SIMDE_FLOAT32_C(  -579.98));
  e = UINT8_C( 65);
  r = simde_mm256_cmp_ps_mask(a, b, SIMDE_CMP_GT_OQ);
  simde_assert_equal_mmask8(r, e);

  a = simde_mm256_set_ps(SIMDE_FLOAT32_C(   967.99), SIMDE_FLOAT32_C(     8.83), SIMDE_FLOAT32_C(   833.78), SIMDE_FLOAT32_C(  -538.41),
                         SIMDE_FLOAT32_C(   222.09), SIMDE_FLOAT32_C(   173.62), SIMDE_FLOAT32_C(  -826.08), SIMDE_FLOAT32_C(  -124.10));
  b = simde_mm256_set_ps(SIMDE_FLOAT32_C(  -609.09), SIMDE_FLOAT32_C(  -385.23), SIMDE_FLOAT32_C(   207.26), SIMDE_FLOAT32_C(   822.59),
                         SIMDE_FLOAT32_C(   650.57), SIMDE_FLOAT32_C(   763.82), SIMDE_FLOAT32_C(    97.31), SIMDE_FLOAT32_C(   541.30));
  e = UINT8_MAX;
  r = simde_mm256_cmp_ps_mask(a, b, SIMDE_CMP_TRUE_US);
  simde_assert_equal_mmask8(r, e);

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 32 ; i++) {
    simde__m256 a = simde_test_x86_random_f32x8(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
    simde__m256 b = simde_test_x86_random_f32x8(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
    int imm8 = i;
    simde__mmask8 r;
    SIMDE_CONSTIFY_32_(simde_mm256_cmp_ps_mask, r, (HEDLEY_UNREACHABLE(), 0), imm8, a, b);

    simde_test_x86_write_f32x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f32x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_cmp_ps_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  simde__m128 a, b;
  simde__mmask8 e, r;

  a = simde_mm_set_ps(SIMDE_FLOAT32_C(   609.48), SIMDE_FLOAT32_C(   744.95), SIMDE_FLOAT32_C(  -768.13), SIMDE_FLOAT32_C(   -64.79));
  b = simde_mm_set_ps(SIMDE_FLOAT32_C(   772.67), SIMDE_FLOAT32_C(   132.73), SIMDE_FLOAT32_C(  -998.15), SIMDE_FLOAT32_C(   759.27));
  e = UINT8_C(  0);
  r = simde_mm_cmp_ps_mask(a, b, SIMDE_CMP_EQ_OQ);
  simde_assert_equal_mmask8(r, e);

  a = simde_mm_set_ps(SIMDE_FLOAT32_C(   248.79), SIMDE_FLOAT32_C(   147.05), SIMDE_FLOAT32_C(   -94.71), SIMDE_FLOAT32_C(  -435.42));
  b = simde_mm_set_ps(SIMDE_FLOAT32_C(  -898.17), SIMDE_FLOAT32_C(  -302.87), SIMDE_FLOAT32_C(   621.93), SIMDE_FLOAT32_C(   462.90));
  e = UINT8_C(  3);
  r = simde_mm_cmp_ps_mask(a, b, SIMDE_CMP_LT_OS);
  simde_assert_equal_mmask8(r, e);

  a = simde_mm_set_ps(SIMDE_FLOAT32_C(   805.59), SIMDE_FLOAT32_C(   659.02), SIMDE_FLOAT32_C(   192.48), SIMDE_FLOAT32_C(  -313.67));
  b = simde_mm_set_ps(SIMDE_FLOAT32_C(  -516.88), SIMDE_FLOAT32_C(   851.69), SIMDE_FLOAT32_C(   929.84), SIMDE_FLOAT32_C(   859.03));
  e = UINT8_C(  7);
  r = simde_mm_cmp_ps_mask(a, b, SIMDE_CMP_LE_OS);
  simde_assert_equal_mmask8(r, e);

  a = simde_mm_set_ps(SIMDE_FLOAT32_C(   671.23), SIMDE_FLOAT32_C(   440.78), SIMDE_FLOAT32_C(   396.17), SIMDE_FLOAT32_C(  -933.28));
  b = simde_mm_set_ps(SIMDE_FLOAT32_C(   -73.11), SIMDE_FLOAT32_C(  -829.33), SIMDE_FLOAT32_C(  -379.83), SIMDE_FLOAT32_C(   991.67));
  e = UINT8_C(  0);
  r = simde_mm_cmp_ps_mask(a, b, SIMDE_CMP_UNORD_Q);
  simde_assert_equal_mmask8(r, e);

  a = simde_mm_set_ps(SIMDE_FLOAT32_C(  -388.69), SIMDE_FLOAT32_C(  -463.63), SIMDE_FLOAT32_C(   915.63), SIMDE_FLOAT32_C(  -147.97));
  b = simde_mm_set_ps(SIMDE_FLOAT32_C(  -517.95), SIMDE_FLOAT32_C(  -616.02), SIMDE_FLOAT32_C(   669.10), SIMDE_FLOAT32_C(   917.47));
  e = UINT8_C( 15);
  r = simde_mm_cmp_ps_mask(a, b, SIMDE_CMP_NEQ_UQ);
  simde_assert_equal_mmask8(r, e);

  a = simde_mm_set_ps(SIMDE_FLOAT32_C(  -962.71), SIMDE_FLOAT32_C(   730.84), SIMDE_FLOAT32_C(   531.03), SIMDE_FLOAT32_C(  -425.61));
  b = simde_mm_set_ps(SIMDE_FLOAT32_C(   839.29), SIMDE_FLOAT32_C(  -860.88), SIMDE_FLOAT32_C(  -572.03), SIMDE_FLOAT32_C(   152.96));
  e = UINT8_C(  6);
  r = simde_mm_cmp_ps_mask(a, b, SIMDE_CMP_NLT_US);
  simde_assert_equal_mmask8(r, e);

  a = simde_mm_set_ps(SIMDE_FLOAT32_C(   479.48), SIMDE_FLOAT32_C(   644.89), SIMDE_FLOAT32_C(   798.14), SIMDE_FLOAT32_C(   620.45));
  b = simde_mm_set_ps(SIMDE_FLOAT32_C(   794.70), SIMDE_FLOAT32_C(   962.60), SIMDE_FLOAT32_C(   496.58), SIMDE_FLOAT32_C(   727.97));
  e = UINT8_C(  2);
  r = simde_mm_cmp_ps_mask(a, b, SIMDE_CMP_NLE_US);
  simde_assert_equal_mmask8(r, e);

  a = simde_mm_set_ps(SIMDE_FLOAT32_C(  -115.58), SIMDE_FLOAT32_C(   465.93), SIMDE_FLOAT32_C(   403.39), SIMDE_FLOAT32_C(  -107.25));
  b = simde_mm_set_ps(SIMDE_FLOAT32_C(  -124.42), SIMDE_FLOAT32_C(   811.31), SIMDE_FLOAT32_C(   636.61), SIMDE_FLOAT32_C(  -976.45));
  e = UINT8_C( 15);
  r = simde_mm_cmp_ps_mask(a, b, SIMDE_CMP_ORD_Q);
  simde_assert_equal_mmask8(r, e);

  a = simde_mm_set_ps(SIMDE_FLOAT32_C(   469.70), SIMDE_FLOAT32_C(   486.89), SIMDE_FLOAT32_C(  -652.32), SIMDE_FLOAT32_C(   552.23));
  b = simde_mm_set_ps(SIMDE_FLOAT32_C(  -408.83), SIMDE_FLOAT32_C(   951.75), SIMDE_FLOAT32_C(   870.87), SIMDE_FLOAT32_C(  -983.22));
  e = UINT8_C(  0);
  r = simde_mm_cmp_ps_mask(a, b, SIMDE_CMP_EQ_UQ);
  simde_assert_equal_mmask8(r, e);

  a = simde_mm_set_ps(SIMDE_FLOAT32_C(  -445.14), SIMDE_FLOAT32_C(  -371.55), SIMDE_FLOAT32_C(   682.59), SIMDE_FLOAT32_C(   401.90));
  b = simde_mm_set_ps(SIMDE_FLOAT32_C(   731.01), SIMDE_FLOAT32_C(  -605.85), SIMDE_FLOAT32_C(  -232.43), SIMDE_FLOAT32_C(  -889.44));
  e = UINT8_C(  8);
  r = simde_mm_cmp_ps_mask(a, b, SIMDE_CMP_NGE_US);
  simde_assert_equal_mmask8(r, e);

  a = simde_mm_set_ps(SIMDE_FLOAT32_C(  -706.31), SIMDE_FLOAT32_C(   210.49), SIMDE_FLOAT32_C(  -960.96), SIMDE_FLOAT32_C(  -434.29));
  b = simde_mm_set_ps(SIMDE_FLOAT32_C(  -571.64), SIMDE_FLOAT32_C(  -911.62), SIMDE_FLOAT32_C(   173.09), SIMDE_FLOAT32_C(   535.62));
  e = UINT8_C( 11);
  r = simde_mm_cmp_ps_mask(a, b, SIMDE_CMP_NGT_US);
  simde_assert_equal_mmask8(r, e);

  a = simde_mm_set_ps(SIMDE_FLOAT32_C(  -399.97), SIMDE_FLOAT32_C(   312.78), SIMDE_FLOAT32_C(   554.32), SIMDE_FLOAT32_C(  -423.52));
  b = simde_mm_set_ps(SIMDE_FLOAT32_C(  -256.85), SIMDE_FLOAT32_C(   475.61), SIMDE_FLOAT32_C(   124.09), SIMDE_FLOAT32_C(   190.92));
  e = UINT8_C(  0);
  r = simde_mm_cmp_ps_mask(a, b, SIMDE_CMP_FALSE_OQ);
  simde_assert_equal_mmask8(r, e);

  a = simde_mm_set_ps(SIMDE_FLOAT32_C(   488.55), SIMDE_FLOAT32_C(  -787.14), SIMDE_FLOAT32_C(   -37.50), SIMDE_FLOAT32_C(   471.77));
  b = simde_mm_set_ps(SIMDE_FLOAT32_C(  -764.73), SIMDE_FLOAT32_C(  -920.29), SIMDE_FLOAT32_C(  -835.39), SIMDE_FLOAT32_C(  -166.63));
  e = UINT8_C( 15);
  r = simde_mm_cmp_ps_mask(a, b, SIMDE_CMP_NEQ_OQ);
  simde_assert_equal_mmask8(r, e);

  a = simde_mm_set_ps(SIMDE_FLOAT32_C(   957.77), SIMDE_FLOAT32_C(  -209.87), SIMDE_FLOAT32_C(  -291.83), SIMDE_FLOAT32_C(   847.21));
  b = simde_mm_set_ps(SIMDE_FLOAT32_C(  -958.55), SIMDE_FLOAT32_C(   688.78), SIMDE_FLOAT32_C(   184.29), SIMDE_FLOAT32_C(   475.74));
  e = UINT8_C(  9);
  r = simde_mm_cmp_ps_mask(a, b, SIMDE_CMP_GE_OS);
  simde_assert_equal_mmask8(r, e);

  a = simde_mm_set_ps(SIMDE_FLOAT32_C(  -241.05), SIMDE_FLOAT32_C(  -664.86), SIMDE_FLOAT32_C(  -100.72), SIMDE_FLOAT32_C(   223.33));
  b = simde_mm_set_ps(SIMDE_FLOAT32_C(  -351.15), SIMDE_FLOAT32_C(   187.31), SIMDE_FLOAT32_C(  -576.47), SIMDE_FLOAT32_C(  -927.63));
  e = UINT8_C( 11);
  r = simde_mm_cmp_ps_mask(a, b, SIMDE_CMP_GT_OS);
  simde_assert_equal_mmask8(r, e);

  a = simde_mm_set_ps(SIMDE_FLOAT32_C(   168.76), SIMDE_FLOAT32_C(   248.88), SIMDE_FLOAT32_C(  -499.91), SIMDE_FLOAT32_C(   977.84));
  b = simde_mm_set_ps(SIMDE_FLOAT32_C(    95.95), SIMDE_FLOAT32_C(   911.92), SIMDE_FLOAT32_C(  -275.50), SIMDE_FLOAT32_C(   624.18));
  e = UINT8_C( 15);
  r = simde_mm_cmp_ps_mask(a, b, SIMDE_CMP_TRUE_UQ);
  simde_assert_equal_mmask8(r, e);

  a = simde_mm_set_ps(SIMDE_FLOAT32_C(  -479.63), SIMDE_FLOAT32_C(  -415.51), SIMDE_FLOAT32_C(  -875.22), SIMDE_FLOAT32_C(   687.00));
  b = simde_mm_set_ps(SIMDE_FLOAT32_C(  -863.41), SIMDE_FLOAT32_C(  -244.36), SIMDE_FLOAT32_C(  -335.79), SIMDE_FLOAT32_C(  -710.61));
  e = UINT8_C(  0);
  r = simde_mm_cmp_ps_mask(a, b, SIMDE_CMP_EQ_OS);
  simde_assert_equal_mmask8(r, e);

  a = simde_mm_set_ps(SIMDE_FLOAT32_C(  -151.88), SIMDE_FLOAT32_C(  -905.64), SIMDE_FLOAT32_C(   545.78), SIMDE_FLOAT32_C(   372.38));
  b = simde_mm_set_ps(SIMDE_FLOAT32_C(   953.40), SIMDE_FLOAT32_C(  -110.43), SIMDE_FLOAT32_C(   783.15), SIMDE_FLOAT32_C(  -269.93));
  e = UINT8_C( 14);
  r = simde_mm_cmp_ps_mask(a, b, SIMDE_CMP_LT_OQ);
  simde_assert_equal_mmask8(r, e);

  a = simde_mm_set_ps(SIMDE_FLOAT32_C(  -245.20), SIMDE_FLOAT32_C(  -287.66), SIMDE_FLOAT32_C(   224.71), SIMDE_FLOAT32_C(  -317.58));
  b = simde_mm_set_ps(SIMDE_FLOAT32_C(   626.08), SIMDE_FLOAT32_C(   403.65), SIMDE_FLOAT32_C(   899.65), SIMDE_FLOAT32_C(   648.24));
  e = UINT8_C( 15);
  r = simde_mm_cmp_ps_mask(a, b, SIMDE_CMP_LE_OQ);
  simde_assert_equal_mmask8(r, e);

  a = simde_mm_set_ps(SIMDE_FLOAT32_C(  -976.07), SIMDE_FLOAT32_C(  -205.16), SIMDE_FLOAT32_C(  -347.47), SIMDE_FLOAT32_C(  -600.25));
  b = simde_mm_set_ps(SIMDE_FLOAT32_C(    64.03), SIMDE_FLOAT32_C(   119.88), SIMDE_FLOAT32_C(  -293.24), SIMDE_FLOAT32_C(   377.03));
  e = UINT8_C(  0);
  r = simde_mm_cmp_ps_mask(a, b, SIMDE_CMP_UNORD_S);
  simde_assert_equal_mmask8(r, e);

  a = simde_mm_set_ps(SIMDE_FLOAT32_C(   120.92), SIMDE_FLOAT32_C(   584.40), SIMDE_FLOAT32_C(   704.37), SIMDE_FLOAT32_C(  -168.46));
  b = simde_mm_set_ps(SIMDE_FLOAT32_C(   740.95), SIMDE_FLOAT32_C(   257.52), SIMDE_FLOAT32_C(  -659.95), SIMDE_FLOAT32_C(  -631.42));
  e = UINT8_C( 15);
  r = simde_mm_cmp_ps_mask(a, b, SIMDE_CMP_NEQ_US);
  simde_assert_equal_mmask8(r, e);

  a = simde_mm_set_ps(SIMDE_FLOAT32_C(  -384.11), SIMDE_FLOAT32_C(  -410.93), SIMDE_FLOAT32_C(   351.88), SIMDE_FLOAT32_C(   885.83));
  b = simde_mm_set_ps(SIMDE_FLOAT32_C(   817.45), SIMDE_FLOAT32_C(  -430.71), SIMDE_FLOAT32_C(   478.64), SIMDE_FLOAT32_C(   135.03));
  e = UINT8_C(  5);
  r = simde_mm_cmp_ps_mask(a, b, SIMDE_CMP_NLT_UQ);
  simde_assert_equal_mmask8(r, e);

  a = simde_mm_set_ps(SIMDE_FLOAT32_C(  -648.41), SIMDE_FLOAT32_C(  -427.75), SIMDE_FLOAT32_C(   281.63), SIMDE_FLOAT32_C(  -296.65));
  b = simde_mm_set_ps(SIMDE_FLOAT32_C(   581.03), SIMDE_FLOAT32_C(   977.67), SIMDE_FLOAT32_C(   975.90), SIMDE_FLOAT32_C(   181.29));
  e = UINT8_C(  0);
  r = simde_mm_cmp_ps_mask(a, b, SIMDE_CMP_NLE_UQ);
  simde_assert_equal_mmask8(r, e);

  a = simde_mm_set_ps(SIMDE_FLOAT32_C(  -994.54), SIMDE_FLOAT32_C(   604.96), SIMDE_FLOAT32_C(  -227.48), SIMDE_FLOAT32_C(  -371.57));
  b = simde_mm_set_ps(SIMDE_FLOAT32_C(  -689.19), SIMDE_FLOAT32_C(    69.49), SIMDE_FLOAT32_C(  -275.17), SIMDE_FLOAT32_C(   479.28));
  e = UINT8_C( 15);
  r = simde_mm_cmp_ps_mask(a, b, SIMDE_CMP_ORD_S);
  simde_assert_equal_mmask8(r, e);

  a = simde_mm_set_ps(SIMDE_FLOAT32_C(  -202.22), SIMDE_FLOAT32_C(   431.74), SIMDE_FLOAT32_C(  -346.11), SIMDE_FLOAT32_C(  -570.80));
  b = simde_mm_set_ps(SIMDE_FLOAT32_C(  -120.23), SIMDE_FLOAT32_C(  -461.27), SIMDE_FLOAT32_C(  -310.75), SIMDE_FLOAT32_C(    -6.06));
  e = UINT8_C(  0);
  r = simde_mm_cmp_ps_mask(a, b, SIMDE_CMP_EQ_US);
  simde_assert_equal_mmask8(r, e);

  a = simde_mm_set_ps(SIMDE_FLOAT32_C(   176.16), SIMDE_FLOAT32_C(   495.66), SIMDE_FLOAT32_C(   127.80), SIMDE_FLOAT32_C(  -958.87));
  b = simde_mm_set_ps(SIMDE_FLOAT32_C(   309.80), SIMDE_FLOAT32_C(    -6.39), SIMDE_FLOAT32_C(  -935.05), SIMDE_FLOAT32_C(  -393.55));
  e = UINT8_C(  9);
  r = simde_mm_cmp_ps_mask(a, b, SIMDE_CMP_NGE_UQ);
  simde_assert_equal_mmask8(r, e);

  a = simde_mm_set_ps(SIMDE_FLOAT32_C(  -472.13), SIMDE_FLOAT32_C(   661.39), SIMDE_FLOAT32_C(   565.86), SIMDE_FLOAT32_C(   346.58));
  b = simde_mm_set_ps(SIMDE_FLOAT32_C(  -829.81), SIMDE_FLOAT32_C(  -891.10), SIMDE_FLOAT32_C(   639.07), SIMDE_FLOAT32_C(   541.76));
  e = UINT8_C(  3);
  r = simde_mm_cmp_ps_mask(a, b, SIMDE_CMP_NGT_UQ);
  simde_assert_equal_mmask8(r, e);

  a = simde_mm_set_ps(SIMDE_FLOAT32_C(   890.86), SIMDE_FLOAT32_C(  -824.36), SIMDE_FLOAT32_C(   713.86), SIMDE_FLOAT32_C(  -588.42));
  b = simde_mm_set_ps(SIMDE_FLOAT32_C(  -132.11), SIMDE_FLOAT32_C(  -798.33), SIMDE_FLOAT32_C(   245.13), SIMDE_FLOAT32_C(  -561.31));
  e = UINT8_C(  0);
  r = simde_mm_cmp_ps_mask(a, b, SIMDE_CMP_FALSE_OS);
  simde_assert_equal_mmask8(r, e);

  a = simde_mm_set_ps(SIMDE_FLOAT32_C(  -107.03), SIMDE_FLOAT32_C(   665.67), SIMDE_FLOAT32_C(   633.41), SIMDE_FLOAT32_C(   899.03));
  b = simde_mm_set_ps(SIMDE_FLOAT32_C(  -636.20), SIMDE_FLOAT32_C(   772.74), SIMDE_FLOAT32_C(  -795.59), SIMDE_FLOAT32_C(  -677.34));
  e = UINT8_C( 15);
  r = simde_mm_cmp_ps_mask(a, b, SIMDE_CMP_NEQ_OS);
  simde_assert_equal_mmask8(r, e);

  a = simde_mm_set_ps(SIMDE_FLOAT32_C(   938.66), SIMDE_FLOAT32_C(   539.96), SIMDE_FLOAT32_C(   268.40), SIMDE_FLOAT32_C(   332.21));
  b = simde_mm_set_ps(SIMDE_FLOAT32_C(  -320.07), SIMDE_FLOAT32_C(   248.46), SIMDE_FLOAT32_C(  -466.43), SIMDE_FLOAT32_C(   333.35));
  e = UINT8_C( 14);
  r = simde_mm_cmp_ps_mask(a, b, SIMDE_CMP_GE_OQ);
  simde_assert_equal_mmask8(r, e);

  a = simde_mm_set_ps(SIMDE_FLOAT32_C(   641.18), SIMDE_FLOAT32_C(   207.80), SIMDE_FLOAT32_C(   -90.15), SIMDE_FLOAT32_C(  -900.57));
  b = simde_mm_set_ps(SIMDE_FLOAT32_C(   -39.50), SIMDE_FLOAT32_C(   811.37), SIMDE_FLOAT32_C(   316.69), SIMDE_FLOAT32_C(  -451.08));
  e = UINT8_C(  8);
  r = simde_mm_cmp_ps_mask(a, b, SIMDE_CMP_GT_OQ);
  simde_assert_equal_mmask8(r, e);

  a = simde_mm_set_ps(SIMDE_FLOAT32_C(   469.24), SIMDE_FLOAT32_C(  -148.64), SIMDE_FLOAT32_C(   987.01), SIMDE_FLOAT32_C(    30.55));
  b = simde_mm_set_ps(SIMDE_FLOAT32_C(   131.18), SIMDE_FLOAT32_C(  -662.87), SIMDE_FLOAT32_C(    53.03), SIMDE_FLOAT32_C(   232.15));
  e = UINT8_C( 15);
  r = simde_mm_cmp_ps_mask(a, b, SIMDE_CMP_TRUE_US);
  simde_assert_equal_mmask8(r, e);

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 32 ; i++) {
    simde__m128 a = simde_test_x86_random_f32x4(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
    simde__m128 b = simde_test_x86_random_f32x4(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
    int imm8 = i;
    simde__mmask8 r;
    SIMDE_CONSTIFY_32_(simde_mm_cmp_ps_mask, r, (HEDLEY_UNREACHABLE(), 0), imm8, a, b);

    simde_test_x86_write_f32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_cmp_pd_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde_float64 a[8];
    const simde_float64 b[8];
    const simde__mmask8 r;
  } test_vec[] = {
    { {             SIMDE_MATH_NAN,             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   971.38), SIMDE_FLOAT64_C(   318.70),
        SIMDE_FLOAT64_C(   169.28), SIMDE_FLOAT64_C(  -796.15), SIMDE_FLOAT64_C(   451.06), SIMDE_FLOAT64_C(  -435.12) },
      { SIMDE_FLOAT64_C(   683.13),             SIMDE_MATH_NAN,             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   318.70),
        SIMDE_FLOAT64_C(  -564.36), SIMDE_FLOAT64_C(   733.28), SIMDE_FLOAT64_C(   451.06), SIMDE_FLOAT64_C(  -435.12) },
      UINT8_C(200) },
    { {             SIMDE_MATH_NAN,             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -305.32), SIMDE_FLOAT64_C(   832.38),
        SIMDE_FLOAT64_C(   981.02), SIMDE_FLOAT64_C(  -160.50), SIMDE_FLOAT64_C(  -949.28), SIMDE_FLOAT64_C(  -629.24) },
      { SIMDE_FLOAT64_C(  -115.84),             SIMDE_MATH_NAN,             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   832.38),
        SIMDE_FLOAT64_C(   981.02), SIMDE_FLOAT64_C(  -160.50), SIMDE_FLOAT64_C(   494.24), SIMDE_FLOAT64_C(   465.62) },
      UINT8_C(192) },
    { {             SIMDE_MATH_NAN,             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   909.54), SIMDE_FLOAT64_C(  -736.00),
        SIMDE_FLOAT64_C(   199.77), SIMDE_FLOAT64_C(    25.69), SIMDE_FLOAT64_C(  -918.86), SIMDE_FLOAT64_C(   445.08) },
      { SIMDE_FLOAT64_C(    18.15),             SIMDE_MATH_NAN,             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -736.00),
        SIMDE_FLOAT64_C(   199.77), SIMDE_FLOAT64_C(    25.69), SIMDE_FLOAT64_C(   414.09), SIMDE_FLOAT64_C(  -168.83) },
      UINT8_C(120) },
    { {             SIMDE_MATH_NAN,             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   115.76), SIMDE_FLOAT64_C(   297.19),
        SIMDE_FLOAT64_C(   182.95), SIMDE_FLOAT64_C(   999.92), SIMDE_FLOAT64_C(  -793.92), SIMDE_FLOAT64_C(   244.87) },
      { SIMDE_FLOAT64_C(   246.47),             SIMDE_MATH_NAN,             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   297.19),
        SIMDE_FLOAT64_C(   182.95), SIMDE_FLOAT64_C(   999.92), SIMDE_FLOAT64_C(  -793.92), SIMDE_FLOAT64_C(   244.87) },
      UINT8_C(  7) },
    { {             SIMDE_MATH_NAN,             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   620.11), SIMDE_FLOAT64_C(  -536.66),
        SIMDE_FLOAT64_C(   379.23), SIMDE_FLOAT64_C(  -361.74), SIMDE_FLOAT64_C(   -19.88), SIMDE_FLOAT64_C(  -442.41) },
      { SIMDE_FLOAT64_C(  -617.80),             SIMDE_MATH_NAN,             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   546.32),
        SIMDE_FLOAT64_C(  -710.33), SIMDE_FLOAT64_C(  -361.74), SIMDE_FLOAT64_C(  -207.21), SIMDE_FLOAT64_C(   101.87) },
      UINT8_C(223) },
    { {             SIMDE_MATH_NAN,             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   531.11), SIMDE_FLOAT64_C(  -703.94),
        SIMDE_FLOAT64_C(   529.69), SIMDE_FLOAT64_C(   342.14), SIMDE_FLOAT64_C(   -70.08), SIMDE_FLOAT64_C(  -491.13) },
      { SIMDE_FLOAT64_C(  -910.02),             SIMDE_MATH_NAN,             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -234.39),
        SIMDE_FLOAT64_C(   763.77), SIMDE_FLOAT64_C(   342.14), SIMDE_FLOAT64_C(   147.82), SIMDE_FLOAT64_C(   697.92) },
      UINT8_C( 39) },
    { {             SIMDE_MATH_NAN,             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -953.47), SIMDE_FLOAT64_C(  -408.73),
        SIMDE_FLOAT64_C(   634.74), SIMDE_FLOAT64_C(  -821.24), SIMDE_FLOAT64_C(  -950.23), SIMDE_FLOAT64_C(   773.91) },
      { SIMDE_FLOAT64_C(   611.16),             SIMDE_MATH_NAN,             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -408.73),
        SIMDE_FLOAT64_C(   634.74), SIMDE_FLOAT64_C(   720.53), SIMDE_FLOAT64_C(  -392.15), SIMDE_FLOAT64_C(   726.12) },
      UINT8_C(135) },
    { {             SIMDE_MATH_NAN,             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -406.22), SIMDE_FLOAT64_C(   833.83),
        SIMDE_FLOAT64_C(   764.68), SIMDE_FLOAT64_C(   241.19), SIMDE_FLOAT64_C(  -136.78), SIMDE_FLOAT64_C(   -41.57) },
      { SIMDE_FLOAT64_C(   -96.09),             SIMDE_MATH_NAN,             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   833.83),
        SIMDE_FLOAT64_C(   764.68), SIMDE_FLOAT64_C(   241.19), SIMDE_FLOAT64_C(  -136.78), SIMDE_FLOAT64_C(   -41.57) },
      UINT8_C(248) },
    { {             SIMDE_MATH_NAN,             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -619.84), SIMDE_FLOAT64_C(   406.81),
        SIMDE_FLOAT64_C(  -189.28), SIMDE_FLOAT64_C(  -894.75), SIMDE_FLOAT64_C(   746.25), SIMDE_FLOAT64_C(     0.07) },
      { SIMDE_FLOAT64_C(   357.05),             SIMDE_MATH_NAN,             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   230.97),
        SIMDE_FLOAT64_C(   -86.33), SIMDE_FLOAT64_C(  -894.75), SIMDE_FLOAT64_C(  -865.12), SIMDE_FLOAT64_C(     0.07) },
      UINT8_C(167) },
    { {             SIMDE_MATH_NAN,             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   807.21), SIMDE_FLOAT64_C(  -168.08),
        SIMDE_FLOAT64_C(  -107.40), SIMDE_FLOAT64_C(   814.01), SIMDE_FLOAT64_C(   458.92), SIMDE_FLOAT64_C(   639.19) },
      { SIMDE_FLOAT64_C(   968.70),             SIMDE_MATH_NAN,             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -168.08),
        SIMDE_FLOAT64_C(   185.90), SIMDE_FLOAT64_C(   814.01), SIMDE_FLOAT64_C(   458.92), SIMDE_FLOAT64_C(  -777.29) },
      UINT8_C( 23) },
    { {             SIMDE_MATH_NAN,             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -519.12), SIMDE_FLOAT64_C(  -755.49),
        SIMDE_FLOAT64_C(  -966.51), SIMDE_FLOAT64_C(   103.99), SIMDE_FLOAT64_C(   432.06), SIMDE_FLOAT64_C(  -245.91) },
      { SIMDE_FLOAT64_C(  -501.73),             SIMDE_MATH_NAN,             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -530.16),
        SIMDE_FLOAT64_C(  -484.78), SIMDE_FLOAT64_C(   103.99), SIMDE_FLOAT64_C(   432.06), SIMDE_FLOAT64_C(  -245.91) },
         UINT8_MAX },
    { {             SIMDE_MATH_NAN,             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   -86.42), SIMDE_FLOAT64_C(  -270.62),
        SIMDE_FLOAT64_C(   -18.83), SIMDE_FLOAT64_C(   882.21), SIMDE_FLOAT64_C(  -486.79), SIMDE_FLOAT64_C(  -224.76) },
      { SIMDE_FLOAT64_C(   270.46),             SIMDE_MATH_NAN,             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -291.93),
        SIMDE_FLOAT64_C(   921.81), SIMDE_FLOAT64_C(   146.33), SIMDE_FLOAT64_C(   206.33), SIMDE_FLOAT64_C(   -44.76) },
      UINT8_C(  0) },
    { {             SIMDE_MATH_NAN,             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -268.80), SIMDE_FLOAT64_C(  -117.09),
        SIMDE_FLOAT64_C(   742.83), SIMDE_FLOAT64_C(    66.16), SIMDE_FLOAT64_C(   228.64), SIMDE_FLOAT64_C(  -530.84) },
      { SIMDE_FLOAT64_C(   450.85),             SIMDE_MATH_NAN,             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -117.09),
        SIMDE_FLOAT64_C(  -806.76), SIMDE_FLOAT64_C(    66.16), SIMDE_FLOAT64_C(   228.64), SIMDE_FLOAT64_C(  -530.84) },
      UINT8_C( 16) },
    { {             SIMDE_MATH_NAN,             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   656.88), SIMDE_FLOAT64_C(  -512.41),
        SIMDE_FLOAT64_C(   291.63), SIMDE_FLOAT64_C(   273.49), SIMDE_FLOAT64_C(  -813.30), SIMDE_FLOAT64_C(  -937.66) },
      { SIMDE_FLOAT64_C(   974.38),             SIMDE_MATH_NAN,             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -512.41),
        SIMDE_FLOAT64_C(    63.76), SIMDE_FLOAT64_C(   273.49), SIMDE_FLOAT64_C(  -813.30), SIMDE_FLOAT64_C(  -937.66) },
      UINT8_C(248) },
    { {             SIMDE_MATH_NAN,             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -366.75), SIMDE_FLOAT64_C(  -249.71),
        SIMDE_FLOAT64_C(  -735.51), SIMDE_FLOAT64_C(  -830.75), SIMDE_FLOAT64_C(  -505.85), SIMDE_FLOAT64_C(  -973.99) },
      { SIMDE_FLOAT64_C(   521.64),             SIMDE_MATH_NAN,             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -249.71),
        SIMDE_FLOAT64_C(  -777.38), SIMDE_FLOAT64_C(  -830.75), SIMDE_FLOAT64_C(  -505.85), SIMDE_FLOAT64_C(  -973.99) },
      UINT8_C( 16) },
    { {             SIMDE_MATH_NAN,             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   592.13), SIMDE_FLOAT64_C(  -962.54),
        SIMDE_FLOAT64_C(  -907.01), SIMDE_FLOAT64_C(   573.68), SIMDE_FLOAT64_C(  -854.03), SIMDE_FLOAT64_C(   301.66) },
      { SIMDE_FLOAT64_C(   850.76),             SIMDE_MATH_NAN,             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -962.54),
        SIMDE_FLOAT64_C(  -907.01), SIMDE_FLOAT64_C(   704.63), SIMDE_FLOAT64_C(  -854.03), SIMDE_FLOAT64_C(    57.54) },
         UINT8_MAX },
    { {             SIMDE_MATH_NAN,             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -492.87), SIMDE_FLOAT64_C(  -833.61),
        SIMDE_FLOAT64_C(   348.03), SIMDE_FLOAT64_C(  -349.08), SIMDE_FLOAT64_C(  -146.21), SIMDE_FLOAT64_C(  -764.87) },
      { SIMDE_FLOAT64_C(   672.24),             SIMDE_MATH_NAN,             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   402.87),
        SIMDE_FLOAT64_C(   348.03), SIMDE_FLOAT64_C(  -349.08), SIMDE_FLOAT64_C(  -146.21), SIMDE_FLOAT64_C(   846.07) },
      UINT8_C(112) },
    { {             SIMDE_MATH_NAN,             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -618.67), SIMDE_FLOAT64_C(   437.06),
        SIMDE_FLOAT64_C(   240.71), SIMDE_FLOAT64_C(   142.91), SIMDE_FLOAT64_C(  -353.22), SIMDE_FLOAT64_C(   378.25) },
      { SIMDE_FLOAT64_C(  -456.78),             SIMDE_MATH_NAN,             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   437.06),
        SIMDE_FLOAT64_C(   -33.46), SIMDE_FLOAT64_C(   142.91), SIMDE_FLOAT64_C(  -353.22), SIMDE_FLOAT64_C(  -711.43) },
      UINT8_C(  0) },
    { {             SIMDE_MATH_NAN,             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -421.19), SIMDE_FLOAT64_C(  -842.41),
        SIMDE_FLOAT64_C(   871.73), SIMDE_FLOAT64_C(  -381.48), SIMDE_FLOAT64_C(   233.99), SIMDE_FLOAT64_C(  -231.39) },
      { SIMDE_FLOAT64_C(  -978.61),             SIMDE_MATH_NAN,             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -842.41),
        SIMDE_FLOAT64_C(   871.73), SIMDE_FLOAT64_C(  -208.21), SIMDE_FLOAT64_C(   233.99), SIMDE_FLOAT64_C(  -165.46) },
      UINT8_C(248) },
    { {             SIMDE_MATH_NAN,             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -683.97), SIMDE_FLOAT64_C(  -350.05),
        SIMDE_FLOAT64_C(   453.51), SIMDE_FLOAT64_C(  -140.76), SIMDE_FLOAT64_C(  -441.05), SIMDE_FLOAT64_C(  -463.61) },
      { SIMDE_FLOAT64_C(  -996.84),             SIMDE_MATH_NAN,             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -350.05),
        SIMDE_FLOAT64_C(   453.51), SIMDE_FLOAT64_C(   885.04), SIMDE_FLOAT64_C(  -441.05), SIMDE_FLOAT64_C(  -463.61) },
      UINT8_C(  7) },
    { {             SIMDE_MATH_NAN,             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(    82.37), SIMDE_FLOAT64_C(  -842.79),
        SIMDE_FLOAT64_C(  -909.01), SIMDE_FLOAT64_C(   103.76), SIMDE_FLOAT64_C(   206.62), SIMDE_FLOAT64_C(  -924.87) },
      { SIMDE_FLOAT64_C(   -76.79),             SIMDE_MATH_NAN,             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -842.79),
        SIMDE_FLOAT64_C(   -63.35), SIMDE_FLOAT64_C(  -959.96), SIMDE_FLOAT64_C(   -51.94), SIMDE_FLOAT64_C(    11.90) },
      UINT8_C(247) },
    { {             SIMDE_MATH_NAN,             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   215.31), SIMDE_FLOAT64_C(  -843.05),
        SIMDE_FLOAT64_C(     1.80), SIMDE_FLOAT64_C(   539.72), SIMDE_FLOAT64_C(   682.44), SIMDE_FLOAT64_C(   -41.04) },
      { SIMDE_FLOAT64_C(     1.54),             SIMDE_MATH_NAN,             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -843.05),
        SIMDE_FLOAT64_C(   -52.86), SIMDE_FLOAT64_C(   307.85), SIMDE_FLOAT64_C(  -309.63), SIMDE_FLOAT64_C(   -41.04) },
         UINT8_MAX },
    { {             SIMDE_MATH_NAN,             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   493.99), SIMDE_FLOAT64_C(  -945.81),
        SIMDE_FLOAT64_C(  -564.35), SIMDE_FLOAT64_C(   872.77), SIMDE_FLOAT64_C(  -843.70), SIMDE_FLOAT64_C(   302.56) },
      { SIMDE_FLOAT64_C(  -152.43),             SIMDE_MATH_NAN,             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -945.81),
        SIMDE_FLOAT64_C(  -564.35), SIMDE_FLOAT64_C(   698.66), SIMDE_FLOAT64_C(  -843.70), SIMDE_FLOAT64_C(  -429.75) },
      UINT8_C(167) },
    { {             SIMDE_MATH_NAN,             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -546.31), SIMDE_FLOAT64_C(   203.11),
        SIMDE_FLOAT64_C(  -468.99), SIMDE_FLOAT64_C(   455.23), SIMDE_FLOAT64_C(  -300.40), SIMDE_FLOAT64_C(   375.01) },
      { SIMDE_FLOAT64_C(   520.68),             SIMDE_MATH_NAN,             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   203.11),
        SIMDE_FLOAT64_C(   916.26), SIMDE_FLOAT64_C(    73.09), SIMDE_FLOAT64_C(  -300.40), SIMDE_FLOAT64_C(  -723.22) },
      UINT8_C(248) },
    { {             SIMDE_MATH_NAN,             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -560.14), SIMDE_FLOAT64_C(   -29.18),
        SIMDE_FLOAT64_C(  -985.01), SIMDE_FLOAT64_C(   257.53), SIMDE_FLOAT64_C(  -936.23), SIMDE_FLOAT64_C(   357.59) },
      { SIMDE_FLOAT64_C(  -185.48),             SIMDE_MATH_NAN,             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -613.02),
        SIMDE_FLOAT64_C(  -985.01), SIMDE_FLOAT64_C(   970.22), SIMDE_FLOAT64_C(   907.65), SIMDE_FLOAT64_C(   357.59) },
      UINT8_C(151) },
    { {             SIMDE_MATH_NAN,             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   879.14), SIMDE_FLOAT64_C(   810.37),
        SIMDE_FLOAT64_C(  -783.06), SIMDE_FLOAT64_C(   101.52), SIMDE_FLOAT64_C(   457.11), SIMDE_FLOAT64_C(  -100.19) },
      { SIMDE_FLOAT64_C(    14.28),             SIMDE_MATH_NAN,             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   774.61),
        SIMDE_FLOAT64_C(   650.15), SIMDE_FLOAT64_C(   101.52), SIMDE_FLOAT64_C(   457.11), SIMDE_FLOAT64_C(  -100.19) },
      UINT8_C( 23) },
    { {             SIMDE_MATH_NAN,             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -762.63), SIMDE_FLOAT64_C(   623.72),
        SIMDE_FLOAT64_C(   735.15), SIMDE_FLOAT64_C(   260.62), SIMDE_FLOAT64_C(   792.33), SIMDE_FLOAT64_C(  -208.60) },
      { SIMDE_FLOAT64_C(   559.95),             SIMDE_MATH_NAN,             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   623.72),
        SIMDE_FLOAT64_C(  -157.88), SIMDE_FLOAT64_C(   260.62), SIMDE_FLOAT64_C(   792.33), SIMDE_FLOAT64_C(  -208.60) },
      UINT8_C(239) },
    { {             SIMDE_MATH_NAN,             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -833.81), SIMDE_FLOAT64_C(   933.49),
        SIMDE_FLOAT64_C(  -199.20), SIMDE_FLOAT64_C(   180.47), SIMDE_FLOAT64_C(   306.86), SIMDE_FLOAT64_C(  -226.30) },
      { SIMDE_FLOAT64_C(   -44.92),             SIMDE_MATH_NAN,             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   933.49),
        SIMDE_FLOAT64_C(   319.59), SIMDE_FLOAT64_C(  -706.47), SIMDE_FLOAT64_C(   306.86), SIMDE_FLOAT64_C(   697.16) },
      UINT8_C(  0) },
    { {             SIMDE_MATH_NAN,             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   791.52), SIMDE_FLOAT64_C(  -479.80),
        SIMDE_FLOAT64_C(  -776.29), SIMDE_FLOAT64_C(   439.12), SIMDE_FLOAT64_C(    51.40), SIMDE_FLOAT64_C(   -14.66) },
      { SIMDE_FLOAT64_C(    -5.64),             SIMDE_MATH_NAN,             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   660.38),
        SIMDE_FLOAT64_C(  -776.29), SIMDE_FLOAT64_C(   235.54), SIMDE_FLOAT64_C(  -863.24), SIMDE_FLOAT64_C(   -14.66) },
      UINT8_C(104) },
    { {             SIMDE_MATH_NAN,             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -417.79), SIMDE_FLOAT64_C(   377.11),
        SIMDE_FLOAT64_C(    53.06), SIMDE_FLOAT64_C(   537.28), SIMDE_FLOAT64_C(  -665.88), SIMDE_FLOAT64_C(  -633.25) },
      { SIMDE_FLOAT64_C(    81.49),             SIMDE_MATH_NAN,             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   377.11),
        SIMDE_FLOAT64_C(    53.06), SIMDE_FLOAT64_C(   537.28), SIMDE_FLOAT64_C(  -665.88), SIMDE_FLOAT64_C(  -633.25) },
      UINT8_C(248) },
    { {             SIMDE_MATH_NAN,             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -578.18), SIMDE_FLOAT64_C(  -514.88),
        SIMDE_FLOAT64_C(   992.23), SIMDE_FLOAT64_C(   416.19), SIMDE_FLOAT64_C(  -621.37), SIMDE_FLOAT64_C(  -836.90) },
      { SIMDE_FLOAT64_C(   433.72),             SIMDE_MATH_NAN,             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   213.32),
        SIMDE_FLOAT64_C(   434.75), SIMDE_FLOAT64_C(   416.19), SIMDE_FLOAT64_C(  -621.37), SIMDE_FLOAT64_C(  -836.90) },
      UINT8_C( 16) },
    { {             SIMDE_MATH_NAN,             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   -80.13), SIMDE_FLOAT64_C(    -5.20),
        SIMDE_FLOAT64_C(   133.92), SIMDE_FLOAT64_C(  -998.64), SIMDE_FLOAT64_C(  -351.49), SIMDE_FLOAT64_C(   794.21) },
      { SIMDE_FLOAT64_C(  -813.00),             SIMDE_MATH_NAN,             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(    -5.20),
        SIMDE_FLOAT64_C(  -217.42), SIMDE_FLOAT64_C(   968.11), SIMDE_FLOAT64_C(  -465.77), SIMDE_FLOAT64_C(   789.48) },
         UINT8_MAX }
  };

  simde__m512d a, b;
  simde__mmask8 r;

  a = simde_mm512_loadu_pd(test_vec[0].a);
  b = simde_mm512_loadu_pd(test_vec[0].b);
  r = simde_mm512_cmp_pd_mask(a, b, SIMDE_CMP_EQ_OQ);
  simde_assert_equal_mmask8(r, test_vec[0].r);

  a = simde_mm512_loadu_pd(test_vec[1].a);
  b = simde_mm512_loadu_pd(test_vec[1].b);
  r = simde_mm512_cmp_pd_mask(a, b, SIMDE_CMP_LT_OS);
  simde_assert_equal_mmask8(r, test_vec[1].r);

  a = simde_mm512_loadu_pd(test_vec[2].a);
  b = simde_mm512_loadu_pd(test_vec[2].b);
  r = simde_mm512_cmp_pd_mask(a, b, SIMDE_CMP_LE_OS);
  simde_assert_equal_mmask8(r, test_vec[2].r);

  a = simde_mm512_loadu_pd(test_vec[3].a);
  b = simde_mm512_loadu_pd(test_vec[3].b);
  r = simde_mm512_cmp_pd_mask(a, b, SIMDE_CMP_UNORD_Q);
  simde_assert_equal_mmask8(r, test_vec[3].r);

  a = simde_mm512_loadu_pd(test_vec[4].a);
  b = simde_mm512_loadu_pd(test_vec[4].b);
  r = simde_mm512_cmp_pd_mask(a, b, SIMDE_CMP_NEQ_UQ);
  simde_assert_equal_mmask8(r, test_vec[4].r);

  a = simde_mm512_loadu_pd(test_vec[5].a);
  b = simde_mm512_loadu_pd(test_vec[5].b);
  r = simde_mm512_cmp_pd_mask(a, b, SIMDE_CMP_NLT_US);
  simde_assert_equal_mmask8(r, test_vec[5].r);

  a = simde_mm512_loadu_pd(test_vec[6].a);
  b = simde_mm512_loadu_pd(test_vec[6].b);
  r = simde_mm512_cmp_pd_mask(a, b, SIMDE_CMP_NLE_US);
  simde_assert_equal_mmask8(r, test_vec[6].r);

  a = simde_mm512_loadu_pd(test_vec[7].a);
  b = simde_mm512_loadu_pd(test_vec[7].b);
  r = simde_mm512_cmp_pd_mask(a, b, SIMDE_CMP_ORD_Q);
  simde_assert_equal_mmask8(r, test_vec[7].r);

  a = simde_mm512_loadu_pd(test_vec[8].a);
  b = simde_mm512_loadu_pd(test_vec[8].b);
  r = simde_mm512_cmp_pd_mask(a, b, SIMDE_CMP_EQ_UQ);
  simde_assert_equal_mmask8(r, test_vec[8].r);

  a = simde_mm512_loadu_pd(test_vec[9].a);
  b = simde_mm512_loadu_pd(test_vec[9].b);
  r = simde_mm512_cmp_pd_mask(a, b, SIMDE_CMP_NGE_US);
  simde_assert_equal_mmask8(r, test_vec[9].r);

  a = simde_mm512_loadu_pd(test_vec[10].a);
  b = simde_mm512_loadu_pd(test_vec[10].b);
  r = simde_mm512_cmp_pd_mask(a, b, SIMDE_CMP_NGT_US);
  simde_assert_equal_mmask8(r, test_vec[10].r);

  a = simde_mm512_loadu_pd(test_vec[11].a);
  b = simde_mm512_loadu_pd(test_vec[11].b);
  r = simde_mm512_cmp_pd_mask(a, b, SIMDE_CMP_FALSE_OQ);
  simde_assert_equal_mmask8(r, test_vec[11].r);

  a = simde_mm512_loadu_pd(test_vec[12].a);
  b = simde_mm512_loadu_pd(test_vec[12].b);
  r = simde_mm512_cmp_pd_mask(a, b, SIMDE_CMP_NEQ_OQ);
  simde_assert_equal_mmask8(r, test_vec[12].r);

  a = simde_mm512_loadu_pd(test_vec[13].a);
  b = simde_mm512_loadu_pd(test_vec[13].b);
  r = simde_mm512_cmp_pd_mask(a, b, SIMDE_CMP_GE_OS);
  simde_assert_equal_mmask8(r, test_vec[13].r);

  a = simde_mm512_loadu_pd(test_vec[14].a);
  b = simde_mm512_loadu_pd(test_vec[14].b);
  r = simde_mm512_cmp_pd_mask(a, b, SIMDE_CMP_GT_OS);
  simde_assert_equal_mmask8(r, test_vec[14].r);

  a = simde_mm512_loadu_pd(test_vec[15].a);
  b = simde_mm512_loadu_pd(test_vec[15].b);
  r = simde_mm512_cmp_pd_mask(a, b, SIMDE_CMP_TRUE_UQ);
  simde_assert_equal_mmask8(r, test_vec[15].r);

  a = simde_mm512_loadu_pd(test_vec[16].a);
  b = simde_mm512_loadu_pd(test_vec[16].b);
  r = simde_mm512_cmp_pd_mask(a, b, SIMDE_CMP_EQ_OS);
  simde_assert_equal_mmask8(r, test_vec[16].r);

  a = simde_mm512_loadu_pd(test_vec[17].a);
  b = simde_mm512_loadu_pd(test_vec[17].b);
  r = simde_mm512_cmp_pd_mask(a, b, SIMDE_CMP_LT_OQ);
  simde_assert_equal_mmask8(r, test_vec[17].r);

  a = simde_mm512_loadu_pd(test_vec[18].a);
  b = simde_mm512_loadu_pd(test_vec[18].b);
  r = simde_mm512_cmp_pd_mask(a, b, SIMDE_CMP_LE_OQ);
  simde_assert_equal_mmask8(r, test_vec[18].r);

  a = simde_mm512_loadu_pd(test_vec[19].a);
  b = simde_mm512_loadu_pd(test_vec[19].b);
  r = simde_mm512_cmp_pd_mask(a, b, SIMDE_CMP_UNORD_S);
  simde_assert_equal_mmask8(r, test_vec[19].r);

  a = simde_mm512_loadu_pd(test_vec[20].a);
  b = simde_mm512_loadu_pd(test_vec[20].b);
  r = simde_mm512_cmp_pd_mask(a, b, SIMDE_CMP_NEQ_US);
  simde_assert_equal_mmask8(r, test_vec[20].r);

  a = simde_mm512_loadu_pd(test_vec[21].a);
  b = simde_mm512_loadu_pd(test_vec[21].b);
  r = simde_mm512_cmp_pd_mask(a, b, SIMDE_CMP_NLT_UQ);
  simde_assert_equal_mmask8(r, test_vec[21].r);

  a = simde_mm512_loadu_pd(test_vec[22].a);
  b = simde_mm512_loadu_pd(test_vec[22].b);
  r = simde_mm512_cmp_pd_mask(a, b, SIMDE_CMP_NLE_UQ);
  simde_assert_equal_mmask8(r, test_vec[22].r);

  a = simde_mm512_loadu_pd(test_vec[23].a);
  b = simde_mm512_loadu_pd(test_vec[23].b);
  r = simde_mm512_cmp_pd_mask(a, b, SIMDE_CMP_ORD_S);
  simde_assert_equal_mmask8(r, test_vec[23].r);

  a = simde_mm512_loadu_pd(test_vec[24].a);
  b = simde_mm512_loadu_pd(test_vec[24].b);
  r = simde_mm512_cmp_pd_mask(a, b, SIMDE_CMP_EQ_US);
  simde_assert_equal_mmask8(r, test_vec[24].r);

  a = simde_mm512_loadu_pd(test_vec[25].a);
  b = simde_mm512_loadu_pd(test_vec[25].b);
  r = simde_mm512_cmp_pd_mask(a, b, SIMDE_CMP_NGE_UQ);
  simde_assert_equal_mmask8(r, test_vec[25].r);

  a = simde_mm512_loadu_pd(test_vec[26].a);
  b = simde_mm512_loadu_pd(test_vec[26].b);
  r = simde_mm512_cmp_pd_mask(a, b, SIMDE_CMP_NGT_UQ);
  simde_assert_equal_mmask8(r, test_vec[26].r);

  a = simde_mm512_loadu_pd(test_vec[27].a);
  b = simde_mm512_loadu_pd(test_vec[27].b);
  r = simde_mm512_cmp_pd_mask(a, b, SIMDE_CMP_FALSE_OS);
  simde_assert_equal_mmask8(r, test_vec[27].r);

  a = simde_mm512_loadu_pd(test_vec[28].a);
  b = simde_mm512_loadu_pd(test_vec[28].b);
  r = simde_mm512_cmp_pd_mask(a, b, SIMDE_CMP_NEQ_OS);
  simde_assert_equal_mmask8(r, test_vec[28].r);

  a = simde_mm512_loadu_pd(test_vec[29].a);
  b = simde_mm512_loadu_pd(test_vec[29].b);
  r = simde_mm512_cmp_pd_mask(a, b, SIMDE_CMP_GE_OQ);
  simde_assert_equal_mmask8(r, test_vec[29].r);

  a = simde_mm512_loadu_pd(test_vec[30].a);
  b = simde_mm512_loadu_pd(test_vec[30].b);
  r = simde_mm512_cmp_pd_mask(a, b, SIMDE_CMP_GT_OQ);
  simde_assert_equal_mmask8(r, test_vec[30].r);

  a = simde_mm512_loadu_pd(test_vec[31].a);
  b = simde_mm512_loadu_pd(test_vec[31].b);
  r = simde_mm512_cmp_pd_mask(a, b, SIMDE_CMP_TRUE_US);
  simde_assert_equal_mmask8(r, test_vec[31].r);

  return 0;
#else
  fputc('\n', stdout);

  const simde__m512d nanv = simde_mm512_set1_pd(SIMDE_MATH_NAN);

  simde__m512d a, b;
  simde__mmask8 r;

  a = simde_test_x86_random_f64x8(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
  b = simde_test_x86_random_f64x8(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
  b = simde_mm512_mask_mov_pd(a, HEDLEY_STATIC_CAST(simde__mmask8, simde_test_codegen_random_i8()), b);
  a = simde_mm512_mask_mov_pd(a, HEDLEY_STATIC_CAST(simde__mmask8, 3), nanv);
  b = simde_mm512_mask_mov_pd(b, HEDLEY_STATIC_CAST(simde__mmask8, 6), nanv);
  r = simde_mm512_cmp_pd_mask(a, b, SIMDE_CMP_EQ_OQ);
  simde_test_x86_write_f64x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_f64x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask8(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_f64x8(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
  b = simde_test_x86_random_f64x8(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
  b = simde_mm512_mask_mov_pd(a, HEDLEY_STATIC_CAST(simde__mmask8, simde_test_codegen_random_i8()), b);
  a = simde_mm512_mask_mov_pd(a, HEDLEY_STATIC_CAST(simde__mmask8, 3), nanv);
  b = simde_mm512_mask_mov_pd(b, HEDLEY_STATIC_CAST(simde__mmask8, 6), nanv);
  r = simde_mm512_cmp_pd_mask(a, b, SIMDE_CMP_LT_OS);
  simde_test_x86_write_f64x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_f64x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask8(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_f64x8(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
  b = simde_test_x86_random_f64x8(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
  b = simde_mm512_mask_mov_pd(a, HEDLEY_STATIC_CAST(simde__mmask8, simde_test_codegen_random_i8()), b);
  a = simde_mm512_mask_mov_pd(a, HEDLEY_STATIC_CAST(simde__mmask8, 3), nanv);
  b = simde_mm512_mask_mov_pd(b, HEDLEY_STATIC_CAST(simde__mmask8, 6), nanv);
  r = simde_mm512_cmp_pd_mask(a, b, SIMDE_CMP_LE_OS);
  simde_test_x86_write_f64x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_f64x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask8(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_f64x8(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
  b = simde_test_x86_random_f64x8(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
  b = simde_mm512_mask_mov_pd(a, HEDLEY_STATIC_CAST(simde__mmask8, simde_test_codegen_random_i8()), b);
  a = simde_mm512_mask_mov_pd(a, HEDLEY_STATIC_CAST(simde__mmask8, 3), nanv);
  b = simde_mm512_mask_mov_pd(b, HEDLEY_STATIC_CAST(simde__mmask8, 6), nanv);
  r = simde_mm512_cmp_pd_mask(a, b, SIMDE_CMP_UNORD_Q);
  simde_test_x86_write_f64x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_f64x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask8(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_f64x8(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
  b = simde_test_x86_random_f64x8(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
  b = simde_mm512_mask_mov_pd(a, HEDLEY_STATIC_CAST(simde__mmask8, simde_test_codegen_random_i8()), b);
  a = simde_mm512_mask_mov_pd(a, HEDLEY_STATIC_CAST(simde__mmask8, 3), nanv);
  b = simde_mm512_mask_mov_pd(b, HEDLEY_STATIC_CAST(simde__mmask8, 6), nanv);
  r = simde_mm512_cmp_pd_mask(a, b, SIMDE_CMP_NEQ_UQ);
  simde_test_x86_write_f64x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_f64x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask8(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_f64x8(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
  b = simde_test_x86_random_f64x8(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
  b = simde_mm512_mask_mov_pd(a, HEDLEY_STATIC_CAST(simde__mmask8, simde_test_codegen_random_i8()), b);
  a = simde_mm512_mask_mov_pd(a, HEDLEY_STATIC_CAST(simde__mmask8, 3), nanv);
  b = simde_mm512_mask_mov_pd(b, HEDLEY_STATIC_CAST(simde__mmask8, 6), nanv);
  r = simde_mm512_cmp_pd_mask(a, b, SIMDE_CMP_NLT_US);
  simde_test_x86_write_f64x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_f64x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask8(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_f64x8(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
  b = simde_test_x86_random_f64x8(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
  b = simde_mm512_mask_mov_pd(a, HEDLEY_STATIC_CAST(simde__mmask8, simde_test_codegen_random_i8()), b);
  a = simde_mm512_mask_mov_pd(a, HEDLEY_STATIC_CAST(simde__mmask8, 3), nanv);
  b = simde_mm512_mask_mov_pd(b, HEDLEY_STATIC_CAST(simde__mmask8, 6), nanv);
  r = simde_mm512_cmp_pd_mask(a, b, SIMDE_CMP_NLE_US);
  simde_test_x86_write_f64x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_f64x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask8(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_f64x8(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
  b = simde_test_x86_random_f64x8(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
  b = simde_mm512_mask_mov_pd(a, HEDLEY_STATIC_CAST(simde__mmask8, simde_test_codegen_random_i8()), b);
  a = simde_mm512_mask_mov_pd(a, HEDLEY_STATIC_CAST(simde__mmask8, 3), nanv);
  b = simde_mm512_mask_mov_pd(b, HEDLEY_STATIC_CAST(simde__mmask8, 6), nanv);
  r = simde_mm512_cmp_pd_mask(a, b, SIMDE_CMP_ORD_Q);
  simde_test_x86_write_f64x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_f64x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask8(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_f64x8(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
  b = simde_test_x86_random_f64x8(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
  b = simde_mm512_mask_mov_pd(a, HEDLEY_STATIC_CAST(simde__mmask8, simde_test_codegen_random_i8()), b);
  a = simde_mm512_mask_mov_pd(a, HEDLEY_STATIC_CAST(simde__mmask8, 3), nanv);
  b = simde_mm512_mask_mov_pd(b, HEDLEY_STATIC_CAST(simde__mmask8, 6), nanv);
  r = simde_mm512_cmp_pd_mask(a, b, SIMDE_CMP_EQ_UQ);
  simde_test_x86_write_f64x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_f64x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask8(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_f64x8(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
  b = simde_test_x86_random_f64x8(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
  b = simde_mm512_mask_mov_pd(a, HEDLEY_STATIC_CAST(simde__mmask8, simde_test_codegen_random_i8()), b);
  a = simde_mm512_mask_mov_pd(a, HEDLEY_STATIC_CAST(simde__mmask8, 3), nanv);
  b = simde_mm512_mask_mov_pd(b, HEDLEY_STATIC_CAST(simde__mmask8, 6), nanv);
  r = simde_mm512_cmp_pd_mask(a, b, SIMDE_CMP_NGE_US);
  simde_test_x86_write_f64x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_f64x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask8(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_f64x8(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
  b = simde_test_x86_random_f64x8(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
  b = simde_mm512_mask_mov_pd(a, HEDLEY_STATIC_CAST(simde__mmask8, simde_test_codegen_random_i8()), b);
  a = simde_mm512_mask_mov_pd(a, HEDLEY_STATIC_CAST(simde__mmask8, 3), nanv);
  b = simde_mm512_mask_mov_pd(b, HEDLEY_STATIC_CAST(simde__mmask8, 6), nanv);
  r = simde_mm512_cmp_pd_mask(a, b, SIMDE_CMP_NGT_US);
  simde_test_x86_write_f64x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_f64x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask8(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_f64x8(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
  b = simde_test_x86_random_f64x8(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
  b = simde_mm512_mask_mov_pd(a, HEDLEY_STATIC_CAST(simde__mmask8, simde_test_codegen_random_i8()), b);
  a = simde_mm512_mask_mov_pd(a, HEDLEY_STATIC_CAST(simde__mmask8, 3), nanv);
  b = simde_mm512_mask_mov_pd(b, HEDLEY_STATIC_CAST(simde__mmask8, 6), nanv);
  r = simde_mm512_cmp_pd_mask(a, b, SIMDE_CMP_FALSE_OQ);
  simde_test_x86_write_f64x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_f64x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask8(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_f64x8(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
  b = simde_test_x86_random_f64x8(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
  b = simde_mm512_mask_mov_pd(a, HEDLEY_STATIC_CAST(simde__mmask8, simde_test_codegen_random_i8()), b);
  a = simde_mm512_mask_mov_pd(a, HEDLEY_STATIC_CAST(simde__mmask8, 3), nanv);
  b = simde_mm512_mask_mov_pd(b, HEDLEY_STATIC_CAST(simde__mmask8, 6), nanv);
  r = simde_mm512_cmp_pd_mask(a, b, SIMDE_CMP_NEQ_OQ);
  simde_test_x86_write_f64x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_f64x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask8(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_f64x8(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
  b = simde_test_x86_random_f64x8(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
  b = simde_mm512_mask_mov_pd(a, HEDLEY_STATIC_CAST(simde__mmask8, simde_test_codegen_random_i8()), b);
  a = simde_mm512_mask_mov_pd(a, HEDLEY_STATIC_CAST(simde__mmask8, 3), nanv);
  b = simde_mm512_mask_mov_pd(b, HEDLEY_STATIC_CAST(simde__mmask8, 6), nanv);
  r = simde_mm512_cmp_pd_mask(a, b, SIMDE_CMP_GE_OS);
  simde_test_x86_write_f64x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_f64x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask8(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_f64x8(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
  b = simde_test_x86_random_f64x8(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
  b = simde_mm512_mask_mov_pd(a, HEDLEY_STATIC_CAST(simde__mmask8, simde_test_codegen_random_i8()), b);
  a = simde_mm512_mask_mov_pd(a, HEDLEY_STATIC_CAST(simde__mmask8, 3), nanv);
  b = simde_mm512_mask_mov_pd(b, HEDLEY_STATIC_CAST(simde__mmask8, 6), nanv);
  r = simde_mm512_cmp_pd_mask(a, b, SIMDE_CMP_GT_OS);
  simde_test_x86_write_f64x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_f64x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask8(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_f64x8(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
  b = simde_test_x86_random_f64x8(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
  b = simde_mm512_mask_mov_pd(a, HEDLEY_STATIC_CAST(simde__mmask8, simde_test_codegen_random_i8()), b);
  a = simde_mm512_mask_mov_pd(a, HEDLEY_STATIC_CAST(simde__mmask8, 3), nanv);
  b = simde_mm512_mask_mov_pd(b, HEDLEY_STATIC_CAST(simde__mmask8, 6), nanv);
  r = simde_mm512_cmp_pd_mask(a, b, SIMDE_CMP_TRUE_UQ);
  simde_test_x86_write_f64x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_f64x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask8(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_f64x8(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
  b = simde_test_x86_random_f64x8(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
  b = simde_mm512_mask_mov_pd(a, HEDLEY_STATIC_CAST(simde__mmask8, simde_test_codegen_random_i8()), b);
  a = simde_mm512_mask_mov_pd(a, HEDLEY_STATIC_CAST(simde__mmask8, 3), nanv);
  b = simde_mm512_mask_mov_pd(b, HEDLEY_STATIC_CAST(simde__mmask8, 6), nanv);
  r = simde_mm512_cmp_pd_mask(a, b, SIMDE_CMP_EQ_OS);
  simde_test_x86_write_f64x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_f64x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask8(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_f64x8(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
  b = simde_test_x86_random_f64x8(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
  b = simde_mm512_mask_mov_pd(a, HEDLEY_STATIC_CAST(simde__mmask8, simde_test_codegen_random_i8()), b);
  a = simde_mm512_mask_mov_pd(a, HEDLEY_STATIC_CAST(simde__mmask8, 3), nanv);
  b = simde_mm512_mask_mov_pd(b, HEDLEY_STATIC_CAST(simde__mmask8, 6), nanv);
  r = simde_mm512_cmp_pd_mask(a, b, SIMDE_CMP_LT_OQ);
  simde_test_x86_write_f64x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_f64x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask8(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_f64x8(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
  b = simde_test_x86_random_f64x8(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
  b = simde_mm512_mask_mov_pd(a, HEDLEY_STATIC_CAST(simde__mmask8, simde_test_codegen_random_i8()), b);
  a = simde_mm512_mask_mov_pd(a, HEDLEY_STATIC_CAST(simde__mmask8, 3), nanv);
  b = simde_mm512_mask_mov_pd(b, HEDLEY_STATIC_CAST(simde__mmask8, 6), nanv);
  r = simde_mm512_cmp_pd_mask(a, b, SIMDE_CMP_LE_OQ);
  simde_test_x86_write_f64x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_f64x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask8(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_f64x8(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
  b = simde_test_x86_random_f64x8(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
  b = simde_mm512_mask_mov_pd(a, HEDLEY_STATIC_CAST(simde__mmask8, simde_test_codegen_random_i8()), b);
  a = simde_mm512_mask_mov_pd(a, HEDLEY_STATIC_CAST(simde__mmask8, 3), nanv);
  b = simde_mm512_mask_mov_pd(b, HEDLEY_STATIC_CAST(simde__mmask8, 6), nanv);
  r = simde_mm512_cmp_pd_mask(a, b, SIMDE_CMP_UNORD_S);
  simde_test_x86_write_f64x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_f64x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask8(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_f64x8(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
  b = simde_test_x86_random_f64x8(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
  b = simde_mm512_mask_mov_pd(a, HEDLEY_STATIC_CAST(simde__mmask8, simde_test_codegen_random_i8()), b);
  a = simde_mm512_mask_mov_pd(a, HEDLEY_STATIC_CAST(simde__mmask8, 3), nanv);
  b = simde_mm512_mask_mov_pd(b, HEDLEY_STATIC_CAST(simde__mmask8, 6), nanv);
  r = simde_mm512_cmp_pd_mask(a, b, SIMDE_CMP_NEQ_US);
  simde_test_x86_write_f64x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_f64x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask8(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_f64x8(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
  b = simde_test_x86_random_f64x8(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
  b = simde_mm512_mask_mov_pd(a, HEDLEY_STATIC_CAST(simde__mmask8, simde_test_codegen_random_i8()), b);
  a = simde_mm512_mask_mov_pd(a, HEDLEY_STATIC_CAST(simde__mmask8, 3), nanv);
  b = simde_mm512_mask_mov_pd(b, HEDLEY_STATIC_CAST(simde__mmask8, 6), nanv);
  r = simde_mm512_cmp_pd_mask(a, b, SIMDE_CMP_NLT_UQ);
  simde_test_x86_write_f64x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_f64x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask8(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_f64x8(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
  b = simde_test_x86_random_f64x8(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
  b = simde_mm512_mask_mov_pd(a, HEDLEY_STATIC_CAST(simde__mmask8, simde_test_codegen_random_i8()), b);
  a = simde_mm512_mask_mov_pd(a, HEDLEY_STATIC_CAST(simde__mmask8, 3), nanv);
  b = simde_mm512_mask_mov_pd(b, HEDLEY_STATIC_CAST(simde__mmask8, 6), nanv);
  r = simde_mm512_cmp_pd_mask(a, b, SIMDE_CMP_NLE_UQ);
  simde_test_x86_write_f64x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_f64x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask8(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_f64x8(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
  b = simde_test_x86_random_f64x8(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
  b = simde_mm512_mask_mov_pd(a, HEDLEY_STATIC_CAST(simde__mmask8, simde_test_codegen_random_i8()), b);
  a = simde_mm512_mask_mov_pd(a, HEDLEY_STATIC_CAST(simde__mmask8, 3), nanv);
  b = simde_mm512_mask_mov_pd(b, HEDLEY_STATIC_CAST(simde__mmask8, 6), nanv);
  r = simde_mm512_cmp_pd_mask(a, b, SIMDE_CMP_ORD_S);
  simde_test_x86_write_f64x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_f64x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask8(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_f64x8(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
  b = simde_test_x86_random_f64x8(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
  b = simde_mm512_mask_mov_pd(a, HEDLEY_STATIC_CAST(simde__mmask8, simde_test_codegen_random_i8()), b);
  a = simde_mm512_mask_mov_pd(a, HEDLEY_STATIC_CAST(simde__mmask8, 3), nanv);
  b = simde_mm512_mask_mov_pd(b, HEDLEY_STATIC_CAST(simde__mmask8, 6), nanv);
  r = simde_mm512_cmp_pd_mask(a, b, SIMDE_CMP_EQ_US);
  simde_test_x86_write_f64x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_f64x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask8(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_f64x8(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
  b = simde_test_x86_random_f64x8(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
  b = simde_mm512_mask_mov_pd(a, HEDLEY_STATIC_CAST(simde__mmask8, simde_test_codegen_random_i8()), b);
  a = simde_mm512_mask_mov_pd(a, HEDLEY_STATIC_CAST(simde__mmask8, 3), nanv);
  b = simde_mm512_mask_mov_pd(b, HEDLEY_STATIC_CAST(simde__mmask8, 6), nanv);
  r = simde_mm512_cmp_pd_mask(a, b, SIMDE_CMP_NGE_UQ);
  simde_test_x86_write_f64x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_f64x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask8(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_f64x8(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
  b = simde_test_x86_random_f64x8(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
  b = simde_mm512_mask_mov_pd(a, HEDLEY_STATIC_CAST(simde__mmask8, simde_test_codegen_random_i8()), b);
  a = simde_mm512_mask_mov_pd(a, HEDLEY_STATIC_CAST(simde__mmask8, 3), nanv);
  b = simde_mm512_mask_mov_pd(b, HEDLEY_STATIC_CAST(simde__mmask8, 6), nanv);
  r = simde_mm512_cmp_pd_mask(a, b, SIMDE_CMP_NGT_UQ);
  simde_test_x86_write_f64x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_f64x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask8(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_f64x8(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
  b = simde_test_x86_random_f64x8(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
  b = simde_mm512_mask_mov_pd(a, HEDLEY_STATIC_CAST(simde__mmask8, simde_test_codegen_random_i8()), b);
  a = simde_mm512_mask_mov_pd(a, HEDLEY_STATIC_CAST(simde__mmask8, 3), nanv);
  b = simde_mm512_mask_mov_pd(b, HEDLEY_STATIC_CAST(simde__mmask8, 6), nanv);
  r = simde_mm512_cmp_pd_mask(a, b, SIMDE_CMP_FALSE_OS);
  simde_test_x86_write_f64x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_f64x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask8(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_f64x8(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
  b = simde_test_x86_random_f64x8(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
  b = simde_mm512_mask_mov_pd(a, HEDLEY_STATIC_CAST(simde__mmask8, simde_test_codegen_random_i8()), b);
  a = simde_mm512_mask_mov_pd(a, HEDLEY_STATIC_CAST(simde__mmask8, 3), nanv);
  b = simde_mm512_mask_mov_pd(b, HEDLEY_STATIC_CAST(simde__mmask8, 6), nanv);
  r = simde_mm512_cmp_pd_mask(a, b, SIMDE_CMP_NEQ_OS);
  simde_test_x86_write_f64x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_f64x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask8(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_f64x8(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
  b = simde_test_x86_random_f64x8(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
  b = simde_mm512_mask_mov_pd(a, HEDLEY_STATIC_CAST(simde__mmask8, simde_test_codegen_random_i8()), b);
  a = simde_mm512_mask_mov_pd(a, HEDLEY_STATIC_CAST(simde__mmask8, 3), nanv);
  b = simde_mm512_mask_mov_pd(b, HEDLEY_STATIC_CAST(simde__mmask8, 6), nanv);
  r = simde_mm512_cmp_pd_mask(a, b, SIMDE_CMP_GE_OQ);
  simde_test_x86_write_f64x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_f64x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask8(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_f64x8(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
  b = simde_test_x86_random_f64x8(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
  b = simde_mm512_mask_mov_pd(a, HEDLEY_STATIC_CAST(simde__mmask8, simde_test_codegen_random_i8()), b);
  a = simde_mm512_mask_mov_pd(a, HEDLEY_STATIC_CAST(simde__mmask8, 3), nanv);
  b = simde_mm512_mask_mov_pd(b, HEDLEY_STATIC_CAST(simde__mmask8, 6), nanv);
  r = simde_mm512_cmp_pd_mask(a, b, SIMDE_CMP_GT_OQ);
  simde_test_x86_write_f64x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_f64x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask8(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_f64x8(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
  b = simde_test_x86_random_f64x8(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
  b = simde_mm512_mask_mov_pd(a, HEDLEY_STATIC_CAST(simde__mmask8, simde_test_codegen_random_i8()), b);
  a = simde_mm512_mask_mov_pd(a, HEDLEY_STATIC_CAST(simde__mmask8, 3), nanv);
  b = simde_mm512_mask_mov_pd(b, HEDLEY_STATIC_CAST(simde__mmask8, 6), nanv);
  r = simde_mm512_cmp_pd_mask(a, b, SIMDE_CMP_TRUE_US);
  simde_test_x86_write_f64x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_f64x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask8(2, r, SIMDE_TEST_VEC_POS_LAST);

  return 1;
#endif
}

static int
test_simde_mm256_cmp_pd_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  simde__m256d a, b;
  simde__mmask8 e, r;

  a = simde_mm256_set_pd(SIMDE_FLOAT64_C(  -361.78), SIMDE_FLOAT64_C(  -782.43), SIMDE_FLOAT64_C(   565.22), SIMDE_FLOAT64_C(  -605.46));
  b = simde_mm256_set_pd(SIMDE_FLOAT64_C(  -817.89), SIMDE_FLOAT64_C(   388.46), SIMDE_FLOAT64_C(   192.48), SIMDE_FLOAT64_C(  -823.37));
  e = UINT8_C(  0);
  r = simde_mm256_cmp_pd_mask(a, b, SIMDE_CMP_EQ_OQ);
  simde_assert_equal_mmask8(r, e);

  a = simde_mm256_set_pd(SIMDE_FLOAT64_C(   449.02), SIMDE_FLOAT64_C(   932.44), SIMDE_FLOAT64_C(  -896.45), SIMDE_FLOAT64_C(  -692.22));
  b = simde_mm256_set_pd(SIMDE_FLOAT64_C(    84.76), SIMDE_FLOAT64_C(   721.33), SIMDE_FLOAT64_C(  -362.73), SIMDE_FLOAT64_C(    95.31));
  e = UINT8_C(  3);
  r = simde_mm256_cmp_pd_mask(a, b, SIMDE_CMP_LT_OS);
  simde_assert_equal_mmask8(r, e);

  a = simde_mm256_set_pd(SIMDE_FLOAT64_C(  -934.37), SIMDE_FLOAT64_C(  -274.54), SIMDE_FLOAT64_C(  -432.69), SIMDE_FLOAT64_C(    16.07));
  b = simde_mm256_set_pd(SIMDE_FLOAT64_C(   189.77), SIMDE_FLOAT64_C(   111.61), SIMDE_FLOAT64_C(  -686.48), SIMDE_FLOAT64_C(  -806.43));
  e = UINT8_C( 12);
  r = simde_mm256_cmp_pd_mask(a, b, SIMDE_CMP_LE_OS);
  simde_assert_equal_mmask8(r, e);

  a = simde_mm256_set_pd(SIMDE_FLOAT64_C(   800.99), SIMDE_FLOAT64_C(  -702.50), SIMDE_FLOAT64_C(  -566.68), SIMDE_FLOAT64_C(   451.34));
  b = simde_mm256_set_pd(SIMDE_FLOAT64_C(   871.85), SIMDE_FLOAT64_C(   216.92), SIMDE_FLOAT64_C(  -251.00), SIMDE_FLOAT64_C(   477.31));
  e = UINT8_C(  0);
  r = simde_mm256_cmp_pd_mask(a, b, SIMDE_CMP_UNORD_Q);
  simde_assert_equal_mmask8(r, e);

  a = simde_mm256_set_pd(SIMDE_FLOAT64_C(  -509.15), SIMDE_FLOAT64_C(  -489.92), SIMDE_FLOAT64_C(   434.49), SIMDE_FLOAT64_C(  -685.79));
  b = simde_mm256_set_pd(SIMDE_FLOAT64_C(   -65.25), SIMDE_FLOAT64_C(  -327.04), SIMDE_FLOAT64_C(   898.54), SIMDE_FLOAT64_C(  -373.03));
  e = UINT8_C( 15);
  r = simde_mm256_cmp_pd_mask(a, b, SIMDE_CMP_NEQ_UQ);
  simde_assert_equal_mmask8(r, e);

  a = simde_mm256_set_pd(SIMDE_FLOAT64_C(    97.40), SIMDE_FLOAT64_C(  -616.22), SIMDE_FLOAT64_C(  -394.60), SIMDE_FLOAT64_C(  -997.91));
  b = simde_mm256_set_pd(SIMDE_FLOAT64_C(  -741.26), SIMDE_FLOAT64_C(  -817.83), SIMDE_FLOAT64_C(  -894.89), SIMDE_FLOAT64_C(   242.67));
  e = UINT8_C( 14);
  r = simde_mm256_cmp_pd_mask(a, b, SIMDE_CMP_NLT_US);
  simde_assert_equal_mmask8(r, e);

  a = simde_mm256_set_pd(SIMDE_FLOAT64_C(  -134.02), SIMDE_FLOAT64_C(  -675.63), SIMDE_FLOAT64_C(   -92.37), SIMDE_FLOAT64_C(  -327.58));
  b = simde_mm256_set_pd(SIMDE_FLOAT64_C(  -327.52), SIMDE_FLOAT64_C(  -944.25), SIMDE_FLOAT64_C(   435.98), SIMDE_FLOAT64_C(   221.14));
  e = UINT8_C( 12);
  r = simde_mm256_cmp_pd_mask(a, b, SIMDE_CMP_NLE_US);
  simde_assert_equal_mmask8(r, e);

  a = simde_mm256_set_pd(SIMDE_FLOAT64_C(   346.61), SIMDE_FLOAT64_C(  -526.53), SIMDE_FLOAT64_C(  -646.75), SIMDE_FLOAT64_C(   869.29));
  b = simde_mm256_set_pd(SIMDE_FLOAT64_C(   416.47), SIMDE_FLOAT64_C(   218.46), SIMDE_FLOAT64_C(   690.39), SIMDE_FLOAT64_C(   102.25));
  e = UINT8_C( 15);
  r = simde_mm256_cmp_pd_mask(a, b, SIMDE_CMP_ORD_Q);
  simde_assert_equal_mmask8(r, e);

  a = simde_mm256_set_pd(SIMDE_FLOAT64_C(   751.86), SIMDE_FLOAT64_C(   907.32), SIMDE_FLOAT64_C(   728.54), SIMDE_FLOAT64_C(   124.89));
  b = simde_mm256_set_pd(SIMDE_FLOAT64_C(   629.16), SIMDE_FLOAT64_C(  -313.39), SIMDE_FLOAT64_C(  -419.73), SIMDE_FLOAT64_C(   627.08));
  e = UINT8_C(  0);
  r = simde_mm256_cmp_pd_mask(a, b, SIMDE_CMP_EQ_UQ);
  simde_assert_equal_mmask8(r, e);

  a = simde_mm256_set_pd(SIMDE_FLOAT64_C(  -571.66), SIMDE_FLOAT64_C(  -273.43), SIMDE_FLOAT64_C(    70.39), SIMDE_FLOAT64_C(   185.67));
  b = simde_mm256_set_pd(SIMDE_FLOAT64_C(   847.91), SIMDE_FLOAT64_C(  -312.92), SIMDE_FLOAT64_C(   -91.27), SIMDE_FLOAT64_C(   175.49));
  e = UINT8_C(  8);
  r = simde_mm256_cmp_pd_mask(a, b, SIMDE_CMP_NGE_US);
  simde_assert_equal_mmask8(r, e);

  a = simde_mm256_set_pd(SIMDE_FLOAT64_C(    37.50), SIMDE_FLOAT64_C(  -286.11), SIMDE_FLOAT64_C(    11.45), SIMDE_FLOAT64_C(   816.36));
  b = simde_mm256_set_pd(SIMDE_FLOAT64_C(  -683.28), SIMDE_FLOAT64_C(   709.98), SIMDE_FLOAT64_C(  -230.35), SIMDE_FLOAT64_C(  -552.58));
  e = UINT8_C(  4);
  r = simde_mm256_cmp_pd_mask(a, b, SIMDE_CMP_NGT_US);
  simde_assert_equal_mmask8(r, e);

  a = simde_mm256_set_pd(SIMDE_FLOAT64_C(  -774.85), SIMDE_FLOAT64_C(   663.33), SIMDE_FLOAT64_C(  -816.55), SIMDE_FLOAT64_C(   122.90));
  b = simde_mm256_set_pd(SIMDE_FLOAT64_C(    -1.27), SIMDE_FLOAT64_C(   641.62), SIMDE_FLOAT64_C(  -118.21), SIMDE_FLOAT64_C(   873.85));
  e = UINT8_C(  0);
  r = simde_mm256_cmp_pd_mask(a, b, SIMDE_CMP_FALSE_OQ);
  simde_assert_equal_mmask8(r, e);

  a = simde_mm256_set_pd(SIMDE_FLOAT64_C(  -762.59), SIMDE_FLOAT64_C(  -249.41), SIMDE_FLOAT64_C(   548.94), SIMDE_FLOAT64_C(  -389.67));
  b = simde_mm256_set_pd(SIMDE_FLOAT64_C(   314.88), SIMDE_FLOAT64_C(   866.57), SIMDE_FLOAT64_C(   437.20), SIMDE_FLOAT64_C(  -870.79));
  e = UINT8_C( 15);
  r = simde_mm256_cmp_pd_mask(a, b, SIMDE_CMP_NEQ_OQ);
  simde_assert_equal_mmask8(r, e);

  a = simde_mm256_set_pd(SIMDE_FLOAT64_C(   683.08), SIMDE_FLOAT64_C(   743.22), SIMDE_FLOAT64_C(  -406.86), SIMDE_FLOAT64_C(  -492.41));
  b = simde_mm256_set_pd(SIMDE_FLOAT64_C(   318.23), SIMDE_FLOAT64_C(   530.99), SIMDE_FLOAT64_C(  -569.70), SIMDE_FLOAT64_C(   501.87));
  e = UINT8_C( 14);
  r = simde_mm256_cmp_pd_mask(a, b, SIMDE_CMP_GE_OS);
  simde_assert_equal_mmask8(r, e);

  a = simde_mm256_set_pd(SIMDE_FLOAT64_C(   889.17), SIMDE_FLOAT64_C(  -644.27), SIMDE_FLOAT64_C(  -755.12), SIMDE_FLOAT64_C(   441.75));
  b = simde_mm256_set_pd(SIMDE_FLOAT64_C(  -862.57), SIMDE_FLOAT64_C(  -794.11), SIMDE_FLOAT64_C(  -934.28), SIMDE_FLOAT64_C(    14.53));
  e = UINT8_C( 15);
  r = simde_mm256_cmp_pd_mask(a, b, SIMDE_CMP_GT_OS);
  simde_assert_equal_mmask8(r, e);

  a = simde_mm256_set_pd(SIMDE_FLOAT64_C(  -876.98), SIMDE_FLOAT64_C(  -637.41), SIMDE_FLOAT64_C(   869.21), SIMDE_FLOAT64_C(  -750.83));
  b = simde_mm256_set_pd(SIMDE_FLOAT64_C(   361.33), SIMDE_FLOAT64_C(   121.75), SIMDE_FLOAT64_C(  -995.79), SIMDE_FLOAT64_C(  -249.00));
  e = UINT8_C( 15);
  r = simde_mm256_cmp_pd_mask(a, b, SIMDE_CMP_TRUE_UQ);
  simde_assert_equal_mmask8(r, e);

  a = simde_mm256_set_pd(SIMDE_FLOAT64_C(   682.35), SIMDE_FLOAT64_C(   598.74), SIMDE_FLOAT64_C(   872.34), SIMDE_FLOAT64_C(   553.14));
  b = simde_mm256_set_pd(SIMDE_FLOAT64_C(   817.13), SIMDE_FLOAT64_C(    -2.77), SIMDE_FLOAT64_C(   465.31), SIMDE_FLOAT64_C(   309.54));
  e = UINT8_C(  0);
  r = simde_mm256_cmp_pd_mask(a, b, SIMDE_CMP_EQ_OS);
  simde_assert_equal_mmask8(r, e);

  a = simde_mm256_set_pd(SIMDE_FLOAT64_C(   560.32), SIMDE_FLOAT64_C(   500.20), SIMDE_FLOAT64_C(  -259.55), SIMDE_FLOAT64_C(  -941.55));
  b = simde_mm256_set_pd(SIMDE_FLOAT64_C(  -387.50), SIMDE_FLOAT64_C(  -121.45), SIMDE_FLOAT64_C(    31.19), SIMDE_FLOAT64_C(   170.76));
  e = UINT8_C(  3);
  r = simde_mm256_cmp_pd_mask(a, b, SIMDE_CMP_LT_OQ);
  simde_assert_equal_mmask8(r, e);

  a = simde_mm256_set_pd(SIMDE_FLOAT64_C(  -709.40), SIMDE_FLOAT64_C(  -498.32), SIMDE_FLOAT64_C(   234.28), SIMDE_FLOAT64_C(   276.07));
  b = simde_mm256_set_pd(SIMDE_FLOAT64_C(   549.17), SIMDE_FLOAT64_C(  -571.97), SIMDE_FLOAT64_C(  -292.44), SIMDE_FLOAT64_C(   300.00));
  e = UINT8_C(  9);
  r = simde_mm256_cmp_pd_mask(a, b, SIMDE_CMP_LE_OQ);
  simde_assert_equal_mmask8(r, e);

  a = simde_mm256_set_pd(SIMDE_FLOAT64_C(   327.78), SIMDE_FLOAT64_C(   672.18), SIMDE_FLOAT64_C(  -209.38), SIMDE_FLOAT64_C(  -423.22));
  b = simde_mm256_set_pd(SIMDE_FLOAT64_C(  -652.03), SIMDE_FLOAT64_C(  -310.88), SIMDE_FLOAT64_C(  -206.06), SIMDE_FLOAT64_C(  -205.17));
  e = UINT8_C(  0);
  r = simde_mm256_cmp_pd_mask(a, b, SIMDE_CMP_UNORD_S);
  simde_assert_equal_mmask8(r, e);

  a = simde_mm256_set_pd(SIMDE_FLOAT64_C(   975.82), SIMDE_FLOAT64_C(  -969.67), SIMDE_FLOAT64_C(  -712.14), SIMDE_FLOAT64_C(  -333.72));
  b = simde_mm256_set_pd(SIMDE_FLOAT64_C(   811.62), SIMDE_FLOAT64_C(   792.94), SIMDE_FLOAT64_C(    27.56), SIMDE_FLOAT64_C(   753.17));
  e = UINT8_C( 15);
  r = simde_mm256_cmp_pd_mask(a, b, SIMDE_CMP_NEQ_US);
  simde_assert_equal_mmask8(r, e);

  a = simde_mm256_set_pd(SIMDE_FLOAT64_C(   -61.23), SIMDE_FLOAT64_C(   371.94), SIMDE_FLOAT64_C(   293.15), SIMDE_FLOAT64_C(   768.01));
  b = simde_mm256_set_pd(SIMDE_FLOAT64_C(   600.41), SIMDE_FLOAT64_C(   551.28), SIMDE_FLOAT64_C(  -749.51), SIMDE_FLOAT64_C(  -675.66));
  e = UINT8_C(  3);
  r = simde_mm256_cmp_pd_mask(a, b, SIMDE_CMP_NLT_UQ);
  simde_assert_equal_mmask8(r, e);

  a = simde_mm256_set_pd(SIMDE_FLOAT64_C(  -215.23), SIMDE_FLOAT64_C(   891.02), SIMDE_FLOAT64_C(  -947.05), SIMDE_FLOAT64_C(   484.78));
  b = simde_mm256_set_pd(SIMDE_FLOAT64_C(   337.30), SIMDE_FLOAT64_C(  -666.06), SIMDE_FLOAT64_C(  -680.95), SIMDE_FLOAT64_C(  -239.48));
  e = UINT8_C(  5);
  r = simde_mm256_cmp_pd_mask(a, b, SIMDE_CMP_NLE_UQ);
  simde_assert_equal_mmask8(r, e);

  a = simde_mm256_set_pd(SIMDE_FLOAT64_C(   904.50), SIMDE_FLOAT64_C(  -334.92), SIMDE_FLOAT64_C(  -993.88), SIMDE_FLOAT64_C(   109.67));
  b = simde_mm256_set_pd(SIMDE_FLOAT64_C(   466.34), SIMDE_FLOAT64_C(  -747.53), SIMDE_FLOAT64_C(   354.20), SIMDE_FLOAT64_C(  -199.94));
  e = UINT8_C( 15);
  r = simde_mm256_cmp_pd_mask(a, b, SIMDE_CMP_ORD_S);
  simde_assert_equal_mmask8(r, e);

  a = simde_mm256_set_pd(SIMDE_FLOAT64_C(   395.23), SIMDE_FLOAT64_C(   442.16), SIMDE_FLOAT64_C(  -717.20), SIMDE_FLOAT64_C(   642.06));
  b = simde_mm256_set_pd(SIMDE_FLOAT64_C(    78.37), SIMDE_FLOAT64_C(   206.85), SIMDE_FLOAT64_C(   235.10), SIMDE_FLOAT64_C(   310.36));
  e = UINT8_C(  0);
  r = simde_mm256_cmp_pd_mask(a, b, SIMDE_CMP_EQ_US);
  simde_assert_equal_mmask8(r, e);

  a = simde_mm256_set_pd(SIMDE_FLOAT64_C(  -147.41), SIMDE_FLOAT64_C(  -982.86), SIMDE_FLOAT64_C(  -421.21), SIMDE_FLOAT64_C(  -471.75));
  b = simde_mm256_set_pd(SIMDE_FLOAT64_C(  -685.94), SIMDE_FLOAT64_C(  -547.00), SIMDE_FLOAT64_C(   568.42), SIMDE_FLOAT64_C(  -170.72));
  e = UINT8_C(  7);
  r = simde_mm256_cmp_pd_mask(a, b, SIMDE_CMP_NGE_UQ);
  simde_assert_equal_mmask8(r, e);

  a = simde_mm256_set_pd(SIMDE_FLOAT64_C(  -618.11), SIMDE_FLOAT64_C(    98.83), SIMDE_FLOAT64_C(  -655.98), SIMDE_FLOAT64_C(   621.37));
  b = simde_mm256_set_pd(SIMDE_FLOAT64_C(   772.73), SIMDE_FLOAT64_C(   719.18), SIMDE_FLOAT64_C(   432.77), SIMDE_FLOAT64_C(  -336.93));
  e = UINT8_C( 14);
  r = simde_mm256_cmp_pd_mask(a, b, SIMDE_CMP_NGT_UQ);
  simde_assert_equal_mmask8(r, e);

  a = simde_mm256_set_pd(SIMDE_FLOAT64_C(  -761.04), SIMDE_FLOAT64_C(   677.23), SIMDE_FLOAT64_C(  -615.74), SIMDE_FLOAT64_C(   438.90));
  b = simde_mm256_set_pd(SIMDE_FLOAT64_C(   380.52), SIMDE_FLOAT64_C(   705.30), SIMDE_FLOAT64_C(   929.70), SIMDE_FLOAT64_C(   738.46));
  e = UINT8_C(  0);
  r = simde_mm256_cmp_pd_mask(a, b, SIMDE_CMP_FALSE_OS);
  simde_assert_equal_mmask8(r, e);

  a = simde_mm256_set_pd(SIMDE_FLOAT64_C(   522.86), SIMDE_FLOAT64_C(  -224.25), SIMDE_FLOAT64_C(   147.45), SIMDE_FLOAT64_C(  -787.50));
  b = simde_mm256_set_pd(SIMDE_FLOAT64_C(   -89.20), SIMDE_FLOAT64_C(  -398.77), SIMDE_FLOAT64_C(   982.60), SIMDE_FLOAT64_C(  -617.45));
  e = UINT8_C( 15);
  r = simde_mm256_cmp_pd_mask(a, b, SIMDE_CMP_NEQ_OS);
  simde_assert_equal_mmask8(r, e);

  a = simde_mm256_set_pd(SIMDE_FLOAT64_C(   390.67), SIMDE_FLOAT64_C(   763.39), SIMDE_FLOAT64_C(  -381.63), SIMDE_FLOAT64_C(  -438.61));
  b = simde_mm256_set_pd(SIMDE_FLOAT64_C(   808.16), SIMDE_FLOAT64_C(   704.73), SIMDE_FLOAT64_C(  -783.61), SIMDE_FLOAT64_C(  -813.21));
  e = UINT8_C(  7);
  r = simde_mm256_cmp_pd_mask(a, b, SIMDE_CMP_GE_OQ);
  simde_assert_equal_mmask8(r, e);

  a = simde_mm256_set_pd(SIMDE_FLOAT64_C(   223.47), SIMDE_FLOAT64_C(  -809.95), SIMDE_FLOAT64_C(  -196.44), SIMDE_FLOAT64_C(  -439.59));
  b = simde_mm256_set_pd(SIMDE_FLOAT64_C(   675.23), SIMDE_FLOAT64_C(    -3.79), SIMDE_FLOAT64_C(   909.23), SIMDE_FLOAT64_C(  -763.67));
  e = UINT8_C(  1);
  r = simde_mm256_cmp_pd_mask(a, b, SIMDE_CMP_GT_OQ);
  simde_assert_equal_mmask8(r, e);

  a = simde_mm256_set_pd(SIMDE_FLOAT64_C(   745.29), SIMDE_FLOAT64_C(   -67.43), SIMDE_FLOAT64_C(   881.20), SIMDE_FLOAT64_C(  -400.21));
  b = simde_mm256_set_pd(SIMDE_FLOAT64_C(  -531.86), SIMDE_FLOAT64_C(   270.12), SIMDE_FLOAT64_C(  -338.86), SIMDE_FLOAT64_C(  -396.43));
  e = UINT8_C( 15);
  r = simde_mm256_cmp_pd_mask(a, b, SIMDE_CMP_TRUE_US);
  simde_assert_equal_mmask8(r, e);

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 32 ; i++) {
    simde__m256d a = simde_test_x86_random_f64x4(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde__m256d b = simde_test_x86_random_f64x4(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    int imm8 = i;
    simde__mmask8 r;
    SIMDE_CONSTIFY_32_(simde_mm256_cmp_pd_mask, r, (HEDLEY_UNREACHABLE(), 0), imm8, a, b);

    simde_test_x86_write_f64x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f64x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_cmp_pd_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  simde__m128d a, b;
  simde__mmask8 e, r;

  a = simde_mm_set_pd(SIMDE_FLOAT64_C(  -268.92), SIMDE_FLOAT64_C(   479.50));
  b = simde_mm_set_pd(SIMDE_FLOAT64_C(   858.92), SIMDE_FLOAT64_C(   796.74));
  e = UINT8_C(  0);
  r = simde_mm_cmp_pd_mask(a, b, SIMDE_CMP_EQ_OQ);
  simde_assert_equal_mmask8(r, e);

  a = simde_mm_set_pd(SIMDE_FLOAT64_C(   179.01), SIMDE_FLOAT64_C(   424.90));
  b = simde_mm_set_pd(SIMDE_FLOAT64_C(   764.21), SIMDE_FLOAT64_C(   456.52));
  e = UINT8_C(  3);
  r = simde_mm_cmp_pd_mask(a, b, SIMDE_CMP_LT_OS);
  simde_assert_equal_mmask8(r, e);

  a = simde_mm_set_pd(SIMDE_FLOAT64_C(   527.46), SIMDE_FLOAT64_C(   265.30));
  b = simde_mm_set_pd(SIMDE_FLOAT64_C(   962.27), SIMDE_FLOAT64_C(   934.34));
  e = UINT8_C(  3);
  r = simde_mm_cmp_pd_mask(a, b, SIMDE_CMP_LE_OS);
  simde_assert_equal_mmask8(r, e);

  a = simde_mm_set_pd(SIMDE_FLOAT64_C(  -837.53), SIMDE_FLOAT64_C(   652.18));
  b = simde_mm_set_pd(SIMDE_FLOAT64_C(  -597.24), SIMDE_FLOAT64_C(  -275.58));
  e = UINT8_C(  0);
  r = simde_mm_cmp_pd_mask(a, b, SIMDE_CMP_UNORD_Q);
  simde_assert_equal_mmask8(r, e);

  a = simde_mm_set_pd(SIMDE_FLOAT64_C(  -812.88), SIMDE_FLOAT64_C(   580.18));
  b = simde_mm_set_pd(SIMDE_FLOAT64_C(   -89.82), SIMDE_FLOAT64_C(  -178.32));
  e = UINT8_C(  3);
  r = simde_mm_cmp_pd_mask(a, b, SIMDE_CMP_NEQ_UQ);
  simde_assert_equal_mmask8(r, e);

  a = simde_mm_set_pd(SIMDE_FLOAT64_C(  -714.89), SIMDE_FLOAT64_C(   539.45));
  b = simde_mm_set_pd(SIMDE_FLOAT64_C(  -165.89), SIMDE_FLOAT64_C(   628.17));
  e = UINT8_C(  0);
  r = simde_mm_cmp_pd_mask(a, b, SIMDE_CMP_NLT_US);
  simde_assert_equal_mmask8(r, e);

  a = simde_mm_set_pd(SIMDE_FLOAT64_C(   -58.11), SIMDE_FLOAT64_C(  -458.02));
  b = simde_mm_set_pd(SIMDE_FLOAT64_C(   947.44), SIMDE_FLOAT64_C(  -465.97));
  e = UINT8_C(  1);
  r = simde_mm_cmp_pd_mask(a, b, SIMDE_CMP_NLE_US);
  simde_assert_equal_mmask8(r, e);

  a = simde_mm_set_pd(SIMDE_FLOAT64_C(   343.16), SIMDE_FLOAT64_C(  -778.20));
  b = simde_mm_set_pd(SIMDE_FLOAT64_C(   701.30), SIMDE_FLOAT64_C(  -788.98));
  e = UINT8_C(  3);
  r = simde_mm_cmp_pd_mask(a, b, SIMDE_CMP_ORD_Q);
  simde_assert_equal_mmask8(r, e);

  a = simde_mm_set_pd(SIMDE_FLOAT64_C(  -992.25), SIMDE_FLOAT64_C(  -925.76));
  b = simde_mm_set_pd(SIMDE_FLOAT64_C(   499.14), SIMDE_FLOAT64_C(   560.22));
  e = UINT8_C(  0);
  r = simde_mm_cmp_pd_mask(a, b, SIMDE_CMP_EQ_UQ);
  simde_assert_equal_mmask8(r, e);

  a = simde_mm_set_pd(SIMDE_FLOAT64_C(    16.74), SIMDE_FLOAT64_C(   186.76));
  b = simde_mm_set_pd(SIMDE_FLOAT64_C(  -547.94), SIMDE_FLOAT64_C(   263.35));
  e = UINT8_C(  1);
  r = simde_mm_cmp_pd_mask(a, b, SIMDE_CMP_NGE_US);
  simde_assert_equal_mmask8(r, e);

  a = simde_mm_set_pd(SIMDE_FLOAT64_C(   197.69), SIMDE_FLOAT64_C(  -455.80));
  b = simde_mm_set_pd(SIMDE_FLOAT64_C(  -803.62), SIMDE_FLOAT64_C(  -585.67));
  e = UINT8_C(  0);
  r = simde_mm_cmp_pd_mask(a, b, SIMDE_CMP_NGT_US);
  simde_assert_equal_mmask8(r, e);

  a = simde_mm_set_pd(SIMDE_FLOAT64_C(   138.75), SIMDE_FLOAT64_C(   360.16));
  b = simde_mm_set_pd(SIMDE_FLOAT64_C(   -59.66), SIMDE_FLOAT64_C(  -400.86));
  e = UINT8_C(  0);
  r = simde_mm_cmp_pd_mask(a, b, SIMDE_CMP_FALSE_OQ);
  simde_assert_equal_mmask8(r, e);

  a = simde_mm_set_pd(SIMDE_FLOAT64_C(   420.82), SIMDE_FLOAT64_C(   325.87));
  b = simde_mm_set_pd(SIMDE_FLOAT64_C(  -134.67), SIMDE_FLOAT64_C(   850.52));
  e = UINT8_C(  3);
  r = simde_mm_cmp_pd_mask(a, b, SIMDE_CMP_NEQ_OQ);
  simde_assert_equal_mmask8(r, e);

  a = simde_mm_set_pd(SIMDE_FLOAT64_C(   478.68), SIMDE_FLOAT64_C(   705.93));
  b = simde_mm_set_pd(SIMDE_FLOAT64_C(  -752.09), SIMDE_FLOAT64_C(   699.44));
  e = UINT8_C(  3);
  r = simde_mm_cmp_pd_mask(a, b, SIMDE_CMP_GE_OS);
  simde_assert_equal_mmask8(r, e);

  a = simde_mm_set_pd(SIMDE_FLOAT64_C(  -766.53), SIMDE_FLOAT64_C(  -579.43));
  b = simde_mm_set_pd(SIMDE_FLOAT64_C(  -357.63), SIMDE_FLOAT64_C(  -804.65));
  e = UINT8_C(  1);
  r = simde_mm_cmp_pd_mask(a, b, SIMDE_CMP_GT_OS);
  simde_assert_equal_mmask8(r, e);

  a = simde_mm_set_pd(SIMDE_FLOAT64_C(  -593.64), SIMDE_FLOAT64_C(   576.63));
  b = simde_mm_set_pd(SIMDE_FLOAT64_C(   650.88), SIMDE_FLOAT64_C(  -656.34));
  e = UINT8_C(  3);
  r = simde_mm_cmp_pd_mask(a, b, SIMDE_CMP_TRUE_UQ);
  simde_assert_equal_mmask8(r, e);

  a = simde_mm_set_pd(SIMDE_FLOAT64_C(   903.88), SIMDE_FLOAT64_C(  -585.88));
  b = simde_mm_set_pd(SIMDE_FLOAT64_C(   600.88), SIMDE_FLOAT64_C(   150.01));
  e = UINT8_C(  0);
  r = simde_mm_cmp_pd_mask(a, b, SIMDE_CMP_EQ_OS);
  simde_assert_equal_mmask8(r, e);

  a = simde_mm_set_pd(SIMDE_FLOAT64_C(  -586.64), SIMDE_FLOAT64_C(   -79.38));
  b = simde_mm_set_pd(SIMDE_FLOAT64_C(   464.82), SIMDE_FLOAT64_C(  -947.06));
  e = UINT8_C(  2);
  r = simde_mm_cmp_pd_mask(a, b, SIMDE_CMP_LT_OQ);
  simde_assert_equal_mmask8(r, e);

  a = simde_mm_set_pd(SIMDE_FLOAT64_C(  -532.73), SIMDE_FLOAT64_C(   611.05));
  b = simde_mm_set_pd(SIMDE_FLOAT64_C(   -28.79), SIMDE_FLOAT64_C(   661.20));
  e = UINT8_C(  3);
  r = simde_mm_cmp_pd_mask(a, b, SIMDE_CMP_LE_OQ);
  simde_assert_equal_mmask8(r, e);

  a = simde_mm_set_pd(SIMDE_FLOAT64_C(  -739.66), SIMDE_FLOAT64_C(   606.02));
  b = simde_mm_set_pd(SIMDE_FLOAT64_C(   -68.11), SIMDE_FLOAT64_C(   911.55));
  e = UINT8_C(  0);
  r = simde_mm_cmp_pd_mask(a, b, SIMDE_CMP_UNORD_S);
  simde_assert_equal_mmask8(r, e);

  a = simde_mm_set_pd(SIMDE_FLOAT64_C(   762.06), SIMDE_FLOAT64_C(   681.16));
  b = simde_mm_set_pd(SIMDE_FLOAT64_C(   387.09), SIMDE_FLOAT64_C(   797.22));
  e = UINT8_C(  3);
  r = simde_mm_cmp_pd_mask(a, b, SIMDE_CMP_NEQ_US);
  simde_assert_equal_mmask8(r, e);

  a = simde_mm_set_pd(SIMDE_FLOAT64_C(   496.66), SIMDE_FLOAT64_C(   240.75));
  b = simde_mm_set_pd(SIMDE_FLOAT64_C(   661.32), SIMDE_FLOAT64_C(   635.00));
  e = UINT8_C(  0);
  r = simde_mm_cmp_pd_mask(a, b, SIMDE_CMP_NLT_UQ);
  simde_assert_equal_mmask8(r, e);

  a = simde_mm_set_pd(SIMDE_FLOAT64_C(   830.35), SIMDE_FLOAT64_C(   730.12));
  b = simde_mm_set_pd(SIMDE_FLOAT64_C(   306.75), SIMDE_FLOAT64_C(  -696.31));
  e = UINT8_C(  3);
  r = simde_mm_cmp_pd_mask(a, b, SIMDE_CMP_NLE_UQ);
  simde_assert_equal_mmask8(r, e);

  a = simde_mm_set_pd(SIMDE_FLOAT64_C(  -352.65), SIMDE_FLOAT64_C(  -763.29));
  b = simde_mm_set_pd(SIMDE_FLOAT64_C(  -349.17), SIMDE_FLOAT64_C(   -42.37));
  e = UINT8_C(  3);
  r = simde_mm_cmp_pd_mask(a, b, SIMDE_CMP_ORD_S);
  simde_assert_equal_mmask8(r, e);

  a = simde_mm_set_pd(SIMDE_FLOAT64_C(  -892.36), SIMDE_FLOAT64_C(  -448.77));
  b = simde_mm_set_pd(SIMDE_FLOAT64_C(   471.85), SIMDE_FLOAT64_C(  -748.29));
  e = UINT8_C(  0);
  r = simde_mm_cmp_pd_mask(a, b, SIMDE_CMP_EQ_US);
  simde_assert_equal_mmask8(r, e);

  a = simde_mm_set_pd(SIMDE_FLOAT64_C(  -695.35), SIMDE_FLOAT64_C(  -478.99));
  b = simde_mm_set_pd(SIMDE_FLOAT64_C(  -867.94), SIMDE_FLOAT64_C(   -63.32));
  e = UINT8_C(  1);
  r = simde_mm_cmp_pd_mask(a, b, SIMDE_CMP_NGE_UQ);
  simde_assert_equal_mmask8(r, e);

  a = simde_mm_set_pd(SIMDE_FLOAT64_C(  -402.12), SIMDE_FLOAT64_C(  -228.09));
  b = simde_mm_set_pd(SIMDE_FLOAT64_C(  -622.07), SIMDE_FLOAT64_C(   103.27));
  e = UINT8_C(  1);
  r = simde_mm_cmp_pd_mask(a, b, SIMDE_CMP_NGT_UQ);
  simde_assert_equal_mmask8(r, e);

  a = simde_mm_set_pd(SIMDE_FLOAT64_C(    14.82), SIMDE_FLOAT64_C(  -141.78));
  b = simde_mm_set_pd(SIMDE_FLOAT64_C(  -460.62), SIMDE_FLOAT64_C(   309.83));
  e = UINT8_C(  0);
  r = simde_mm_cmp_pd_mask(a, b, SIMDE_CMP_FALSE_OS);
  simde_assert_equal_mmask8(r, e);

  a = simde_mm_set_pd(SIMDE_FLOAT64_C(   107.05), SIMDE_FLOAT64_C(  -223.11));
  b = simde_mm_set_pd(SIMDE_FLOAT64_C(  -982.36), SIMDE_FLOAT64_C(   926.47));
  e = UINT8_C(  3);
  r = simde_mm_cmp_pd_mask(a, b, SIMDE_CMP_NEQ_OS);
  simde_assert_equal_mmask8(r, e);

  a = simde_mm_set_pd(SIMDE_FLOAT64_C(   561.47), SIMDE_FLOAT64_C(  -396.30));
  b = simde_mm_set_pd(SIMDE_FLOAT64_C(  -666.17), SIMDE_FLOAT64_C(   678.95));
  e = UINT8_C(  2);
  r = simde_mm_cmp_pd_mask(a, b, SIMDE_CMP_GE_OQ);
  simde_assert_equal_mmask8(r, e);

  a = simde_mm_set_pd(SIMDE_FLOAT64_C(   982.64), SIMDE_FLOAT64_C(   391.81));
  b = simde_mm_set_pd(SIMDE_FLOAT64_C(   628.52), SIMDE_FLOAT64_C(   640.58));
  e = UINT8_C(  2);
  r = simde_mm_cmp_pd_mask(a, b, SIMDE_CMP_GT_OQ);
  simde_assert_equal_mmask8(r, e);

  a = simde_mm_set_pd(SIMDE_FLOAT64_C(  -401.79), SIMDE_FLOAT64_C(  -370.01));
  b = simde_mm_set_pd(SIMDE_FLOAT64_C(   181.22), SIMDE_FLOAT64_C(  -720.65));
  e = UINT8_C(  3);
  r = simde_mm_cmp_pd_mask(a, b, SIMDE_CMP_TRUE_US);
  simde_assert_equal_mmask8(r, e);

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 32 ; i++) {
    simde__m128d a = simde_test_x86_random_f64x2(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde__m128d b = simde_test_x86_random_f64x2(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    int imm8 = i;
    simde__mmask8 r;
    SIMDE_CONSTIFY_32_(simde_mm_cmp_pd_mask, r, (HEDLEY_UNREACHABLE(), 0), imm8, a, b);

    simde_test_x86_write_f64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

#if defined(SIMDE_FLOAT16_IS_SCALAR)
static int
test_simde_mm512_cmp_ph_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde_float16 a[32];
    const simde_float16 b[32];
    const simde__mmask32 r;
  } test_vec[] = {
    { {            SIMDE_NANHF,            SIMDE_NANHF, SIMDE_FLOAT16_VALUE(   958.00), SIMDE_FLOAT16_VALUE(  -929.50),
        SIMDE_FLOAT16_VALUE(   497.25), SIMDE_FLOAT16_VALUE(   361.75), SIMDE_FLOAT16_VALUE(   951.00), SIMDE_FLOAT16_VALUE(   215.88),
        SIMDE_FLOAT16_VALUE(  -457.75), SIMDE_FLOAT16_VALUE(   611.00), SIMDE_FLOAT16_VALUE(   870.50), SIMDE_FLOAT16_VALUE(    35.00),
        SIMDE_FLOAT16_VALUE(  -753.50), SIMDE_FLOAT16_VALUE(  -835.50), SIMDE_FLOAT16_VALUE(    -0.45), SIMDE_FLOAT16_VALUE(   626.00),
        SIMDE_FLOAT16_VALUE(  -525.50), SIMDE_FLOAT16_VALUE(   528.00), SIMDE_FLOAT16_VALUE(   559.00), SIMDE_FLOAT16_VALUE(   802.00),
        SIMDE_FLOAT16_VALUE(   345.25), SIMDE_FLOAT16_VALUE(  -396.75), SIMDE_FLOAT16_VALUE(    18.52), SIMDE_FLOAT16_VALUE(   999.00),
        SIMDE_FLOAT16_VALUE(   153.75), SIMDE_FLOAT16_VALUE(  -827.50), SIMDE_FLOAT16_VALUE(  -366.25), SIMDE_FLOAT16_VALUE(  -885.50),
        SIMDE_FLOAT16_VALUE(  -116.69), SIMDE_FLOAT16_VALUE(  -129.12), SIMDE_FLOAT16_VALUE(   316.25), SIMDE_FLOAT16_VALUE(  -509.25) },
      { SIMDE_FLOAT16_VALUE(   607.50),            SIMDE_NANHF,            SIMDE_NANHF, SIMDE_FLOAT16_VALUE(  -381.00),
        SIMDE_FLOAT16_VALUE(  -363.75), SIMDE_FLOAT16_VALUE(  -487.75), SIMDE_FLOAT16_VALUE(   835.00), SIMDE_FLOAT16_VALUE(   215.88),
        SIMDE_FLOAT16_VALUE(  -457.75), SIMDE_FLOAT16_VALUE(   611.00), SIMDE_FLOAT16_VALUE(   870.50), SIMDE_FLOAT16_VALUE(    35.00),
        SIMDE_FLOAT16_VALUE(  -753.50), SIMDE_FLOAT16_VALUE(  -835.50), SIMDE_FLOAT16_VALUE(    -0.45), SIMDE_FLOAT16_VALUE(   626.00),
        SIMDE_FLOAT16_VALUE(  -525.50), SIMDE_FLOAT16_VALUE(   528.00), SIMDE_FLOAT16_VALUE(   559.00), SIMDE_FLOAT16_VALUE(   802.00),
        SIMDE_FLOAT16_VALUE(   345.25), SIMDE_FLOAT16_VALUE(  -396.75), SIMDE_FLOAT16_VALUE(    18.52), SIMDE_FLOAT16_VALUE(   999.00),
        SIMDE_FLOAT16_VALUE(   153.75), SIMDE_FLOAT16_VALUE(  -827.50), SIMDE_FLOAT16_VALUE(  -366.25), SIMDE_FLOAT16_VALUE(  -885.50),
        SIMDE_FLOAT16_VALUE(  -116.69), SIMDE_FLOAT16_VALUE(  -129.12), SIMDE_FLOAT16_VALUE(   316.25), SIMDE_FLOAT16_VALUE(  -509.25) },
      UINT32_C(4294967168) },
    { {            SIMDE_NANHF,            SIMDE_NANHF, SIMDE_FLOAT16_VALUE(  -347.00), SIMDE_FLOAT16_VALUE(   784.50),
        SIMDE_FLOAT16_VALUE(   164.88), SIMDE_FLOAT16_VALUE(   831.00), SIMDE_FLOAT16_VALUE(   908.00), SIMDE_FLOAT16_VALUE(  -129.88),
        SIMDE_FLOAT16_VALUE(  -955.50), SIMDE_FLOAT16_VALUE(  -722.00), SIMDE_FLOAT16_VALUE(  -260.25), SIMDE_FLOAT16_VALUE(   257.50),
        SIMDE_FLOAT16_VALUE(  -726.00), SIMDE_FLOAT16_VALUE(    83.69), SIMDE_FLOAT16_VALUE(   998.50), SIMDE_FLOAT16_VALUE(   829.00),
        SIMDE_FLOAT16_VALUE(   229.88), SIMDE_FLOAT16_VALUE(  -915.50), SIMDE_FLOAT16_VALUE(   987.00), SIMDE_FLOAT16_VALUE(  -605.50),
        SIMDE_FLOAT16_VALUE(  -831.00), SIMDE_FLOAT16_VALUE(   299.00), SIMDE_FLOAT16_VALUE(   731.50), SIMDE_FLOAT16_VALUE(  -112.50),
        SIMDE_FLOAT16_VALUE(  -274.75), SIMDE_FLOAT16_VALUE(   952.00), SIMDE_FLOAT16_VALUE(  -523.00), SIMDE_FLOAT16_VALUE(   467.50),
        SIMDE_FLOAT16_VALUE(  -337.00), SIMDE_FLOAT16_VALUE(   187.88), SIMDE_FLOAT16_VALUE(   484.25), SIMDE_FLOAT16_VALUE(   935.50) },
      { SIMDE_FLOAT16_VALUE(   272.25),            SIMDE_NANHF,            SIMDE_NANHF, SIMDE_FLOAT16_VALUE(   784.50),
        SIMDE_FLOAT16_VALUE(   164.88), SIMDE_FLOAT16_VALUE(   628.00), SIMDE_FLOAT16_VALUE(  -447.00), SIMDE_FLOAT16_VALUE(  -129.88),
        SIMDE_FLOAT16_VALUE(  -955.50), SIMDE_FLOAT16_VALUE(  -722.00), SIMDE_FLOAT16_VALUE(  -260.25), SIMDE_FLOAT16_VALUE(   257.50),
        SIMDE_FLOAT16_VALUE(  -726.00), SIMDE_FLOAT16_VALUE(    83.69), SIMDE_FLOAT16_VALUE(   998.50), SIMDE_FLOAT16_VALUE(   829.00),
        SIMDE_FLOAT16_VALUE(   229.88), SIMDE_FLOAT16_VALUE(  -915.50), SIMDE_FLOAT16_VALUE(   987.00), SIMDE_FLOAT16_VALUE(  -605.50),
        SIMDE_FLOAT16_VALUE(  -831.00), SIMDE_FLOAT16_VALUE(   299.00), SIMDE_FLOAT16_VALUE(   731.50), SIMDE_FLOAT16_VALUE(  -112.50),
        SIMDE_FLOAT16_VALUE(  -274.75), SIMDE_FLOAT16_VALUE(   952.00), SIMDE_FLOAT16_VALUE(  -523.00), SIMDE_FLOAT16_VALUE(   467.50),
        SIMDE_FLOAT16_VALUE(  -337.00), SIMDE_FLOAT16_VALUE(   187.88), SIMDE_FLOAT16_VALUE(   484.25), SIMDE_FLOAT16_VALUE(   935.50) },
      UINT32_C(         0) },
    { {            SIMDE_NANHF,            SIMDE_NANHF, SIMDE_FLOAT16_VALUE(    78.12), SIMDE_FLOAT16_VALUE(   630.50),
        SIMDE_FLOAT16_VALUE(  -171.75), SIMDE_FLOAT16_VALUE(    91.12), SIMDE_FLOAT16_VALUE(   537.00), SIMDE_FLOAT16_VALUE(  -879.00),
        SIMDE_FLOAT16_VALUE(  -638.50), SIMDE_FLOAT16_VALUE(   717.00), SIMDE_FLOAT16_VALUE(  -502.50), SIMDE_FLOAT16_VALUE(   630.50),
        SIMDE_FLOAT16_VALUE(   726.00), SIMDE_FLOAT16_VALUE(  -896.50), SIMDE_FLOAT16_VALUE(   -16.52), SIMDE_FLOAT16_VALUE(   722.50),
        SIMDE_FLOAT16_VALUE(  -895.50), SIMDE_FLOAT16_VALUE(  -494.50), SIMDE_FLOAT16_VALUE(    17.92), SIMDE_FLOAT16_VALUE(   837.00),
        SIMDE_FLOAT16_VALUE(   -84.75), SIMDE_FLOAT16_VALUE(    38.50), SIMDE_FLOAT16_VALUE(   522.00), SIMDE_FLOAT16_VALUE(   801.50),
        SIMDE_FLOAT16_VALUE(  -473.25), SIMDE_FLOAT16_VALUE(   869.50), SIMDE_FLOAT16_VALUE(   876.00), SIMDE_FLOAT16_VALUE(   499.25),
        SIMDE_FLOAT16_VALUE(  -847.50), SIMDE_FLOAT16_VALUE(  -531.50), SIMDE_FLOAT16_VALUE(  -391.25), SIMDE_FLOAT16_VALUE(  -844.50) },
      { SIMDE_FLOAT16_VALUE(  -256.50),            SIMDE_NANHF,            SIMDE_NANHF, SIMDE_FLOAT16_VALUE(   572.00),
        SIMDE_FLOAT16_VALUE(  -171.75), SIMDE_FLOAT16_VALUE(    91.12), SIMDE_FLOAT16_VALUE(   537.00), SIMDE_FLOAT16_VALUE(  -879.00),
        SIMDE_FLOAT16_VALUE(  -638.50), SIMDE_FLOAT16_VALUE(   717.00), SIMDE_FLOAT16_VALUE(  -502.50), SIMDE_FLOAT16_VALUE(   630.50),
        SIMDE_FLOAT16_VALUE(   726.00), SIMDE_FLOAT16_VALUE(  -896.50), SIMDE_FLOAT16_VALUE(   -16.52), SIMDE_FLOAT16_VALUE(   722.50),
        SIMDE_FLOAT16_VALUE(  -895.50), SIMDE_FLOAT16_VALUE(  -494.50), SIMDE_FLOAT16_VALUE(    17.92), SIMDE_FLOAT16_VALUE(   837.00),
        SIMDE_FLOAT16_VALUE(   -84.75), SIMDE_FLOAT16_VALUE(    38.50), SIMDE_FLOAT16_VALUE(   522.00), SIMDE_FLOAT16_VALUE(   801.50),
        SIMDE_FLOAT16_VALUE(  -473.25), SIMDE_FLOAT16_VALUE(   869.50), SIMDE_FLOAT16_VALUE(   876.00), SIMDE_FLOAT16_VALUE(   499.25),
        SIMDE_FLOAT16_VALUE(  -847.50), SIMDE_FLOAT16_VALUE(  -531.50), SIMDE_FLOAT16_VALUE(  -391.25), SIMDE_FLOAT16_VALUE(  -844.50) },
      UINT32_C(4294967280) },
    { {            SIMDE_NANHF,            SIMDE_NANHF, SIMDE_FLOAT16_VALUE(   644.50), SIMDE_FLOAT16_VALUE(    44.16),
        SIMDE_FLOAT16_VALUE(   328.75), SIMDE_FLOAT16_VALUE(  -215.62), SIMDE_FLOAT16_VALUE(  -916.00), SIMDE_FLOAT16_VALUE(   519.00),
        SIMDE_FLOAT16_VALUE(   554.50), SIMDE_FLOAT16_VALUE(  -150.12), SIMDE_FLOAT16_VALUE(   813.00), SIMDE_FLOAT16_VALUE(   308.25),
        SIMDE_FLOAT16_VALUE(   338.25), SIMDE_FLOAT16_VALUE(  -789.00), SIMDE_FLOAT16_VALUE(   567.50), SIMDE_FLOAT16_VALUE(  -155.38),
        SIMDE_FLOAT16_VALUE(  -553.00), SIMDE_FLOAT16_VALUE(  -258.00), SIMDE_FLOAT16_VALUE(   389.50), SIMDE_FLOAT16_VALUE(  -795.50),
        SIMDE_FLOAT16_VALUE(   718.50), SIMDE_FLOAT16_VALUE(  -539.00), SIMDE_FLOAT16_VALUE(   831.50), SIMDE_FLOAT16_VALUE(  -429.50),
        SIMDE_FLOAT16_VALUE(    31.48), SIMDE_FLOAT16_VALUE(   611.00), SIMDE_FLOAT16_VALUE(   891.00), SIMDE_FLOAT16_VALUE(  -789.00),
        SIMDE_FLOAT16_VALUE(   546.00), SIMDE_FLOAT16_VALUE(   955.00), SIMDE_FLOAT16_VALUE(    77.44), SIMDE_FLOAT16_VALUE(   267.25) },
      { SIMDE_FLOAT16_VALUE(   590.50),            SIMDE_NANHF,            SIMDE_NANHF, SIMDE_FLOAT16_VALUE(   -80.56),
        SIMDE_FLOAT16_VALUE(   506.50), SIMDE_FLOAT16_VALUE(  -604.50), SIMDE_FLOAT16_VALUE(  -561.50), SIMDE_FLOAT16_VALUE(   519.00),
        SIMDE_FLOAT16_VALUE(   554.50), SIMDE_FLOAT16_VALUE(  -150.12), SIMDE_FLOAT16_VALUE(   813.00), SIMDE_FLOAT16_VALUE(   308.25),
        SIMDE_FLOAT16_VALUE(   338.25), SIMDE_FLOAT16_VALUE(  -789.00), SIMDE_FLOAT16_VALUE(   567.50), SIMDE_FLOAT16_VALUE(  -155.38),
        SIMDE_FLOAT16_VALUE(  -553.00), SIMDE_FLOAT16_VALUE(  -258.00), SIMDE_FLOAT16_VALUE(   389.50), SIMDE_FLOAT16_VALUE(  -795.50),
        SIMDE_FLOAT16_VALUE(   718.50), SIMDE_FLOAT16_VALUE(  -539.00), SIMDE_FLOAT16_VALUE(   831.50), SIMDE_FLOAT16_VALUE(  -429.50),
        SIMDE_FLOAT16_VALUE(    31.48), SIMDE_FLOAT16_VALUE(   611.00), SIMDE_FLOAT16_VALUE(   891.00), SIMDE_FLOAT16_VALUE(  -789.00),
        SIMDE_FLOAT16_VALUE(   546.00), SIMDE_FLOAT16_VALUE(   955.00), SIMDE_FLOAT16_VALUE(    77.44), SIMDE_FLOAT16_VALUE(   267.25) },
      UINT32_C(         7) },
    { {            SIMDE_NANHF,            SIMDE_NANHF, SIMDE_FLOAT16_VALUE(   827.00), SIMDE_FLOAT16_VALUE(  -924.00),
        SIMDE_FLOAT16_VALUE(   761.50), SIMDE_FLOAT16_VALUE(  -112.25), SIMDE_FLOAT16_VALUE(   321.25), SIMDE_FLOAT16_VALUE(  -987.00),
        SIMDE_FLOAT16_VALUE(   257.00), SIMDE_FLOAT16_VALUE(   905.00), SIMDE_FLOAT16_VALUE(  -524.50), SIMDE_FLOAT16_VALUE(   193.75),
        SIMDE_FLOAT16_VALUE(   333.25), SIMDE_FLOAT16_VALUE(   384.50), SIMDE_FLOAT16_VALUE(   872.50), SIMDE_FLOAT16_VALUE(  -849.50),
        SIMDE_FLOAT16_VALUE(  -502.00), SIMDE_FLOAT16_VALUE(  -730.50), SIMDE_FLOAT16_VALUE(   429.00), SIMDE_FLOAT16_VALUE(   442.75),
        SIMDE_FLOAT16_VALUE(   237.12), SIMDE_FLOAT16_VALUE(   739.00), SIMDE_FLOAT16_VALUE(   998.50), SIMDE_FLOAT16_VALUE(  -904.50),
        SIMDE_FLOAT16_VALUE(  -740.00), SIMDE_FLOAT16_VALUE(  -899.50), SIMDE_FLOAT16_VALUE(   -91.25), SIMDE_FLOAT16_VALUE(   858.00),
        SIMDE_FLOAT16_VALUE(   469.75), SIMDE_FLOAT16_VALUE(   312.75), SIMDE_FLOAT16_VALUE(  -821.50), SIMDE_FLOAT16_VALUE(   150.25) },
      { SIMDE_FLOAT16_VALUE(   680.50),            SIMDE_NANHF,            SIMDE_NANHF, SIMDE_FLOAT16_VALUE(  -602.00),
        SIMDE_FLOAT16_VALUE(   761.50), SIMDE_FLOAT16_VALUE(  -112.25), SIMDE_FLOAT16_VALUE(  -589.50), SIMDE_FLOAT16_VALUE(  -850.00),
        SIMDE_FLOAT16_VALUE(  -547.50), SIMDE_FLOAT16_VALUE(  -114.00), SIMDE_FLOAT16_VALUE(   343.75), SIMDE_FLOAT16_VALUE(   786.00),
        SIMDE_FLOAT16_VALUE(  -729.50), SIMDE_FLOAT16_VALUE(   216.25), SIMDE_FLOAT16_VALUE(   936.50), SIMDE_FLOAT16_VALUE(  -231.38),
        SIMDE_FLOAT16_VALUE(   486.00), SIMDE_FLOAT16_VALUE(   365.50), SIMDE_FLOAT16_VALUE(  -788.50), SIMDE_FLOAT16_VALUE(  -276.75),
        SIMDE_FLOAT16_VALUE(   104.50), SIMDE_FLOAT16_VALUE(  -790.00), SIMDE_FLOAT16_VALUE(  -181.38), SIMDE_FLOAT16_VALUE(   364.50),
        SIMDE_FLOAT16_VALUE(  -689.50), SIMDE_FLOAT16_VALUE(   727.50), SIMDE_FLOAT16_VALUE(   222.62), SIMDE_FLOAT16_VALUE(   780.50),
        SIMDE_FLOAT16_VALUE(    40.16), SIMDE_FLOAT16_VALUE(   401.25), SIMDE_FLOAT16_VALUE(   -69.44), SIMDE_FLOAT16_VALUE(   676.50) },
      UINT32_C(4294967247) },
    { {            SIMDE_NANHF,            SIMDE_NANHF, SIMDE_FLOAT16_VALUE(  -700.50), SIMDE_FLOAT16_VALUE(  -295.50),
        SIMDE_FLOAT16_VALUE(  -515.00), SIMDE_FLOAT16_VALUE(  -550.50), SIMDE_FLOAT16_VALUE(   157.25), SIMDE_FLOAT16_VALUE(   370.75),
        SIMDE_FLOAT16_VALUE(   793.50), SIMDE_FLOAT16_VALUE(   -56.97), SIMDE_FLOAT16_VALUE(   641.50), SIMDE_FLOAT16_VALUE(     9.69),
        SIMDE_FLOAT16_VALUE(  -120.50), SIMDE_FLOAT16_VALUE(  -590.00), SIMDE_FLOAT16_VALUE(  -504.25), SIMDE_FLOAT16_VALUE(  -755.00),
        SIMDE_FLOAT16_VALUE(  -378.50), SIMDE_FLOAT16_VALUE(   218.75), SIMDE_FLOAT16_VALUE(   349.50), SIMDE_FLOAT16_VALUE(  -168.38),
        SIMDE_FLOAT16_VALUE(  -962.50), SIMDE_FLOAT16_VALUE(  -286.00), SIMDE_FLOAT16_VALUE(   142.25), SIMDE_FLOAT16_VALUE(   765.00),
        SIMDE_FLOAT16_VALUE(   936.50), SIMDE_FLOAT16_VALUE(   -77.44), SIMDE_FLOAT16_VALUE(  -194.88), SIMDE_FLOAT16_VALUE(   337.75),
        SIMDE_FLOAT16_VALUE(   853.00), SIMDE_FLOAT16_VALUE(  -518.50), SIMDE_FLOAT16_VALUE(  -255.75), SIMDE_FLOAT16_VALUE(  -990.00) },
      { SIMDE_FLOAT16_VALUE(  -843.00),            SIMDE_NANHF,            SIMDE_NANHF, SIMDE_FLOAT16_VALUE(  -295.50),
        SIMDE_FLOAT16_VALUE(   493.50), SIMDE_FLOAT16_VALUE(  -550.50), SIMDE_FLOAT16_VALUE(   157.25), SIMDE_FLOAT16_VALUE(   286.75),
        SIMDE_FLOAT16_VALUE(  -185.12), SIMDE_FLOAT16_VALUE(  -947.50), SIMDE_FLOAT16_VALUE(  -703.50), SIMDE_FLOAT16_VALUE(   694.50),
        SIMDE_FLOAT16_VALUE(  -537.50), SIMDE_FLOAT16_VALUE(  -207.88), SIMDE_FLOAT16_VALUE(   939.50), SIMDE_FLOAT16_VALUE(    84.12),
        SIMDE_FLOAT16_VALUE(  -989.00), SIMDE_FLOAT16_VALUE(   289.00), SIMDE_FLOAT16_VALUE(   915.50), SIMDE_FLOAT16_VALUE(  -951.50),
        SIMDE_FLOAT16_VALUE(  -997.00), SIMDE_FLOAT16_VALUE(    57.97), SIMDE_FLOAT16_VALUE(   813.50), SIMDE_FLOAT16_VALUE(   939.50),
        SIMDE_FLOAT16_VALUE(   980.50), SIMDE_FLOAT16_VALUE(  -381.50), SIMDE_FLOAT16_VALUE(   277.25), SIMDE_FLOAT16_VALUE(   833.50),
        SIMDE_FLOAT16_VALUE(    99.88), SIMDE_FLOAT16_VALUE(  -978.50), SIMDE_FLOAT16_VALUE(   844.00), SIMDE_FLOAT16_VALUE(   655.50) },
      UINT32_C( 840505327) },
    { {            SIMDE_NANHF,            SIMDE_NANHF, SIMDE_FLOAT16_VALUE(  -441.25), SIMDE_FLOAT16_VALUE(  -569.50),
        SIMDE_FLOAT16_VALUE(   106.88), SIMDE_FLOAT16_VALUE(   845.50), SIMDE_FLOAT16_VALUE(   245.25), SIMDE_FLOAT16_VALUE(   159.50),
        SIMDE_FLOAT16_VALUE(  -858.00), SIMDE_FLOAT16_VALUE(   -60.41), SIMDE_FLOAT16_VALUE(   622.00), SIMDE_FLOAT16_VALUE(   -65.75),
        SIMDE_FLOAT16_VALUE(  -121.00), SIMDE_FLOAT16_VALUE(  -293.75), SIMDE_FLOAT16_VALUE(   -54.75), SIMDE_FLOAT16_VALUE(  -832.00),
        SIMDE_FLOAT16_VALUE(  -378.00), SIMDE_FLOAT16_VALUE(    -6.27), SIMDE_FLOAT16_VALUE(  -829.00), SIMDE_FLOAT16_VALUE(   680.00),
        SIMDE_FLOAT16_VALUE(  -192.88), SIMDE_FLOAT16_VALUE(  -889.50), SIMDE_FLOAT16_VALUE(   660.50), SIMDE_FLOAT16_VALUE(   425.75),
        SIMDE_FLOAT16_VALUE(   387.50), SIMDE_FLOAT16_VALUE(   494.00), SIMDE_FLOAT16_VALUE(  -474.50), SIMDE_FLOAT16_VALUE(   409.00),
        SIMDE_FLOAT16_VALUE(   337.75), SIMDE_FLOAT16_VALUE(  -819.00), SIMDE_FLOAT16_VALUE(  -525.50), SIMDE_FLOAT16_VALUE(   896.50) },
      { SIMDE_FLOAT16_VALUE(  -123.31),            SIMDE_NANHF,            SIMDE_NANHF, SIMDE_FLOAT16_VALUE(  -569.50),
        SIMDE_FLOAT16_VALUE(   106.88), SIMDE_FLOAT16_VALUE(   572.00), SIMDE_FLOAT16_VALUE(   143.00), SIMDE_FLOAT16_VALUE(   159.50),
        SIMDE_FLOAT16_VALUE(  -858.00), SIMDE_FLOAT16_VALUE(   -60.41), SIMDE_FLOAT16_VALUE(   622.00), SIMDE_FLOAT16_VALUE(   -65.75),
        SIMDE_FLOAT16_VALUE(  -121.00), SIMDE_FLOAT16_VALUE(  -293.75), SIMDE_FLOAT16_VALUE(   -54.75), SIMDE_FLOAT16_VALUE(  -832.00),
        SIMDE_FLOAT16_VALUE(  -378.00), SIMDE_FLOAT16_VALUE(    -6.27), SIMDE_FLOAT16_VALUE(  -829.00), SIMDE_FLOAT16_VALUE(   680.00),
        SIMDE_FLOAT16_VALUE(  -192.88), SIMDE_FLOAT16_VALUE(  -889.50), SIMDE_FLOAT16_VALUE(   660.50), SIMDE_FLOAT16_VALUE(   425.75),
        SIMDE_FLOAT16_VALUE(   387.50), SIMDE_FLOAT16_VALUE(   494.00), SIMDE_FLOAT16_VALUE(  -474.50), SIMDE_FLOAT16_VALUE(   409.00),
        SIMDE_FLOAT16_VALUE(   337.75), SIMDE_FLOAT16_VALUE(  -819.00), SIMDE_FLOAT16_VALUE(  -525.50), SIMDE_FLOAT16_VALUE(   896.50) },
      UINT32_C(       103) },
    { {            SIMDE_NANHF,            SIMDE_NANHF, SIMDE_FLOAT16_VALUE(    22.09), SIMDE_FLOAT16_VALUE(  -940.00),
        SIMDE_FLOAT16_VALUE(  -163.50), SIMDE_FLOAT16_VALUE(  -957.00), SIMDE_FLOAT16_VALUE(  -428.50), SIMDE_FLOAT16_VALUE(   601.50),
        SIMDE_FLOAT16_VALUE(   997.50), SIMDE_FLOAT16_VALUE(   962.00), SIMDE_FLOAT16_VALUE(    72.75), SIMDE_FLOAT16_VALUE(  -102.06),
        SIMDE_FLOAT16_VALUE(   520.00), SIMDE_FLOAT16_VALUE(   165.88), SIMDE_FLOAT16_VALUE(  -208.12), SIMDE_FLOAT16_VALUE(   249.38),
        SIMDE_FLOAT16_VALUE(   -61.12), SIMDE_FLOAT16_VALUE(   493.00), SIMDE_FLOAT16_VALUE(    88.94), SIMDE_FLOAT16_VALUE(  -627.50),
        SIMDE_FLOAT16_VALUE(   619.50), SIMDE_FLOAT16_VALUE(  -684.00), SIMDE_FLOAT16_VALUE(   299.75), SIMDE_FLOAT16_VALUE(  -728.00),
        SIMDE_FLOAT16_VALUE(   -47.75), SIMDE_FLOAT16_VALUE(   565.00), SIMDE_FLOAT16_VALUE(   105.38), SIMDE_FLOAT16_VALUE(  -937.50),
        SIMDE_FLOAT16_VALUE(   727.00), SIMDE_FLOAT16_VALUE(  -184.62), SIMDE_FLOAT16_VALUE(  -794.00), SIMDE_FLOAT16_VALUE(  -785.00) },
      { SIMDE_FLOAT16_VALUE(  -511.75),            SIMDE_NANHF,            SIMDE_NANHF, SIMDE_FLOAT16_VALUE(   345.25),
        SIMDE_FLOAT16_VALUE(  -163.50), SIMDE_FLOAT16_VALUE(  -153.50), SIMDE_FLOAT16_VALUE(  -428.50), SIMDE_FLOAT16_VALUE(   601.50),
        SIMDE_FLOAT16_VALUE(   997.50), SIMDE_FLOAT16_VALUE(   962.00), SIMDE_FLOAT16_VALUE(    72.75), SIMDE_FLOAT16_VALUE(  -102.06),
        SIMDE_FLOAT16_VALUE(   520.00), SIMDE_FLOAT16_VALUE(   165.88), SIMDE_FLOAT16_VALUE(  -208.12), SIMDE_FLOAT16_VALUE(   249.38),
        SIMDE_FLOAT16_VALUE(   -61.12), SIMDE_FLOAT16_VALUE(   493.00), SIMDE_FLOAT16_VALUE(    88.94), SIMDE_FLOAT16_VALUE(  -627.50),
        SIMDE_FLOAT16_VALUE(   619.50), SIMDE_FLOAT16_VALUE(  -684.00), SIMDE_FLOAT16_VALUE(   299.75), SIMDE_FLOAT16_VALUE(  -728.00),
        SIMDE_FLOAT16_VALUE(   -47.75), SIMDE_FLOAT16_VALUE(   565.00), SIMDE_FLOAT16_VALUE(   105.38), SIMDE_FLOAT16_VALUE(  -937.50),
        SIMDE_FLOAT16_VALUE(   727.00), SIMDE_FLOAT16_VALUE(  -184.62), SIMDE_FLOAT16_VALUE(  -794.00), SIMDE_FLOAT16_VALUE(  -785.00) },
      UINT32_C(4294967288) },
    { {            SIMDE_NANHF,            SIMDE_NANHF, SIMDE_FLOAT16_VALUE(  -296.75), SIMDE_FLOAT16_VALUE(  -575.00),
        SIMDE_FLOAT16_VALUE(    65.25), SIMDE_FLOAT16_VALUE(   972.00), SIMDE_FLOAT16_VALUE(   233.25), SIMDE_FLOAT16_VALUE(    84.88),
        SIMDE_FLOAT16_VALUE(  -861.50), SIMDE_FLOAT16_VALUE(   561.50), SIMDE_FLOAT16_VALUE(  -729.50), SIMDE_FLOAT16_VALUE(    97.31),
        SIMDE_FLOAT16_VALUE(   139.25), SIMDE_FLOAT16_VALUE(  -605.00), SIMDE_FLOAT16_VALUE(   549.00), SIMDE_FLOAT16_VALUE(   806.00),
        SIMDE_FLOAT16_VALUE(  -108.50), SIMDE_FLOAT16_VALUE(   620.00), SIMDE_FLOAT16_VALUE(  -211.62), SIMDE_FLOAT16_VALUE(  -312.00),
        SIMDE_FLOAT16_VALUE(   963.50), SIMDE_FLOAT16_VALUE(  -276.75), SIMDE_FLOAT16_VALUE(  -950.50), SIMDE_FLOAT16_VALUE(   412.25),
        SIMDE_FLOAT16_VALUE(  -279.25), SIMDE_FLOAT16_VALUE(   138.00), SIMDE_FLOAT16_VALUE(   676.50), SIMDE_FLOAT16_VALUE(   -75.31),
        SIMDE_FLOAT16_VALUE(  -558.50), SIMDE_FLOAT16_VALUE(  -550.50), SIMDE_FLOAT16_VALUE(  -643.00), SIMDE_FLOAT16_VALUE(  -980.00) },
      { SIMDE_FLOAT16_VALUE(   578.50),            SIMDE_NANHF,            SIMDE_NANHF, SIMDE_FLOAT16_VALUE(   633.00),
        SIMDE_FLOAT16_VALUE(    65.25), SIMDE_FLOAT16_VALUE(   678.00), SIMDE_FLOAT16_VALUE(   233.25), SIMDE_FLOAT16_VALUE(    84.88),
        SIMDE_FLOAT16_VALUE(  -861.50), SIMDE_FLOAT16_VALUE(   561.50), SIMDE_FLOAT16_VALUE(  -729.50), SIMDE_FLOAT16_VALUE(    97.31),
        SIMDE_FLOAT16_VALUE(   139.25), SIMDE_FLOAT16_VALUE(  -605.00), SIMDE_FLOAT16_VALUE(   549.00), SIMDE_FLOAT16_VALUE(   806.00),
        SIMDE_FLOAT16_VALUE(  -108.50), SIMDE_FLOAT16_VALUE(   620.00), SIMDE_FLOAT16_VALUE(  -211.62), SIMDE_FLOAT16_VALUE(  -312.00),
        SIMDE_FLOAT16_VALUE(   963.50), SIMDE_FLOAT16_VALUE(  -276.75), SIMDE_FLOAT16_VALUE(  -950.50), SIMDE_FLOAT16_VALUE(   412.25),
        SIMDE_FLOAT16_VALUE(  -279.25), SIMDE_FLOAT16_VALUE(   138.00), SIMDE_FLOAT16_VALUE(   676.50), SIMDE_FLOAT16_VALUE(   -75.31),
        SIMDE_FLOAT16_VALUE(  -558.50), SIMDE_FLOAT16_VALUE(  -550.50), SIMDE_FLOAT16_VALUE(  -643.00), SIMDE_FLOAT16_VALUE(  -980.00) },
      UINT32_C(4294967255) },
    { {            SIMDE_NANHF,            SIMDE_NANHF, SIMDE_FLOAT16_VALUE(   790.50), SIMDE_FLOAT16_VALUE(  -265.25),
        SIMDE_FLOAT16_VALUE(   858.00), SIMDE_FLOAT16_VALUE(   -38.69), SIMDE_FLOAT16_VALUE(   974.50), SIMDE_FLOAT16_VALUE(  -153.88),
        SIMDE_FLOAT16_VALUE(   229.38), SIMDE_FLOAT16_VALUE(  -647.00), SIMDE_FLOAT16_VALUE(  -770.50), SIMDE_FLOAT16_VALUE(    46.31),
        SIMDE_FLOAT16_VALUE(  -462.00), SIMDE_FLOAT16_VALUE(  -496.00), SIMDE_FLOAT16_VALUE(  -516.50), SIMDE_FLOAT16_VALUE(   511.00),
        SIMDE_FLOAT16_VALUE(   466.50), SIMDE_FLOAT16_VALUE(   884.00), SIMDE_FLOAT16_VALUE(   207.25), SIMDE_FLOAT16_VALUE(  -521.50),
        SIMDE_FLOAT16_VALUE(  -302.75), SIMDE_FLOAT16_VALUE(   624.50), SIMDE_FLOAT16_VALUE(  -371.25), SIMDE_FLOAT16_VALUE(   186.62),
        SIMDE_FLOAT16_VALUE(   -33.75), SIMDE_FLOAT16_VALUE(   220.38), SIMDE_FLOAT16_VALUE(  -874.50), SIMDE_FLOAT16_VALUE(  -335.25),
        SIMDE_FLOAT16_VALUE(   832.00), SIMDE_FLOAT16_VALUE(   632.50), SIMDE_FLOAT16_VALUE(   423.50), SIMDE_FLOAT16_VALUE(  -111.50) },
      { SIMDE_FLOAT16_VALUE(    56.50),            SIMDE_NANHF,            SIMDE_NANHF, SIMDE_FLOAT16_VALUE(  -370.00),
        SIMDE_FLOAT16_VALUE(  -824.50), SIMDE_FLOAT16_VALUE(   -38.69), SIMDE_FLOAT16_VALUE(   476.25), SIMDE_FLOAT16_VALUE(  -153.88),
        SIMDE_FLOAT16_VALUE(   229.38), SIMDE_FLOAT16_VALUE(  -647.00), SIMDE_FLOAT16_VALUE(  -770.50), SIMDE_FLOAT16_VALUE(    46.31),
        SIMDE_FLOAT16_VALUE(  -462.00), SIMDE_FLOAT16_VALUE(  -496.00), SIMDE_FLOAT16_VALUE(  -516.50), SIMDE_FLOAT16_VALUE(   511.00),
        SIMDE_FLOAT16_VALUE(   466.50), SIMDE_FLOAT16_VALUE(   884.00), SIMDE_FLOAT16_VALUE(   207.25), SIMDE_FLOAT16_VALUE(  -521.50),
        SIMDE_FLOAT16_VALUE(  -302.75), SIMDE_FLOAT16_VALUE(   624.50), SIMDE_FLOAT16_VALUE(  -371.25), SIMDE_FLOAT16_VALUE(   186.62),
        SIMDE_FLOAT16_VALUE(   -33.75), SIMDE_FLOAT16_VALUE(   220.38), SIMDE_FLOAT16_VALUE(  -874.50), SIMDE_FLOAT16_VALUE(  -335.25),
        SIMDE_FLOAT16_VALUE(   832.00), SIMDE_FLOAT16_VALUE(   632.50), SIMDE_FLOAT16_VALUE(   423.50), SIMDE_FLOAT16_VALUE(  -111.50) },
      UINT32_C(         7) },
    { {            SIMDE_NANHF,            SIMDE_NANHF, SIMDE_FLOAT16_VALUE(   275.25), SIMDE_FLOAT16_VALUE(   945.00),
        SIMDE_FLOAT16_VALUE(   339.25), SIMDE_FLOAT16_VALUE(  -320.00), SIMDE_FLOAT16_VALUE(   896.00), SIMDE_FLOAT16_VALUE(    44.78),
        SIMDE_FLOAT16_VALUE(   131.00), SIMDE_FLOAT16_VALUE(  -615.50), SIMDE_FLOAT16_VALUE(   254.25), SIMDE_FLOAT16_VALUE(  -934.50),
        SIMDE_FLOAT16_VALUE(  -615.50), SIMDE_FLOAT16_VALUE(   -69.69), SIMDE_FLOAT16_VALUE(  -115.88), SIMDE_FLOAT16_VALUE(   591.00),
        SIMDE_FLOAT16_VALUE(    85.00), SIMDE_FLOAT16_VALUE(  -600.00), SIMDE_FLOAT16_VALUE(  -577.50), SIMDE_FLOAT16_VALUE(   868.50),
        SIMDE_FLOAT16_VALUE(   102.44), SIMDE_FLOAT16_VALUE(  -780.00), SIMDE_FLOAT16_VALUE(   872.50), SIMDE_FLOAT16_VALUE(   930.50),
        SIMDE_FLOAT16_VALUE(  -317.50), SIMDE_FLOAT16_VALUE(   708.50), SIMDE_FLOAT16_VALUE(  -609.00), SIMDE_FLOAT16_VALUE(  -431.75),
        SIMDE_FLOAT16_VALUE(  -567.00), SIMDE_FLOAT16_VALUE(   624.00), SIMDE_FLOAT16_VALUE(   668.00), SIMDE_FLOAT16_VALUE(  -219.12) },
      { SIMDE_FLOAT16_VALUE(   487.00),            SIMDE_NANHF,            SIMDE_NANHF, SIMDE_FLOAT16_VALUE(  -173.62),
        SIMDE_FLOAT16_VALUE(   623.00), SIMDE_FLOAT16_VALUE(  -320.00), SIMDE_FLOAT16_VALUE(   896.00), SIMDE_FLOAT16_VALUE(    44.78),
        SIMDE_FLOAT16_VALUE(   131.00), SIMDE_FLOAT16_VALUE(  -615.50), SIMDE_FLOAT16_VALUE(   254.25), SIMDE_FLOAT16_VALUE(  -934.50),
        SIMDE_FLOAT16_VALUE(  -615.50), SIMDE_FLOAT16_VALUE(   -69.69), SIMDE_FLOAT16_VALUE(  -115.88), SIMDE_FLOAT16_VALUE(   591.00),
        SIMDE_FLOAT16_VALUE(    85.00), SIMDE_FLOAT16_VALUE(  -600.00), SIMDE_FLOAT16_VALUE(  -577.50), SIMDE_FLOAT16_VALUE(   868.50),
        SIMDE_FLOAT16_VALUE(   102.44), SIMDE_FLOAT16_VALUE(  -780.00), SIMDE_FLOAT16_VALUE(   872.50), SIMDE_FLOAT16_VALUE(   930.50),
        SIMDE_FLOAT16_VALUE(  -317.50), SIMDE_FLOAT16_VALUE(   708.50), SIMDE_FLOAT16_VALUE(  -609.00), SIMDE_FLOAT16_VALUE(  -431.75),
        SIMDE_FLOAT16_VALUE(  -567.00), SIMDE_FLOAT16_VALUE(   624.00), SIMDE_FLOAT16_VALUE(   668.00), SIMDE_FLOAT16_VALUE(  -219.12) },
      UINT32_C(4294967287) },
    { {            SIMDE_NANHF,            SIMDE_NANHF, SIMDE_FLOAT16_VALUE(   109.88), SIMDE_FLOAT16_VALUE(   152.50),
        SIMDE_FLOAT16_VALUE(   336.50), SIMDE_FLOAT16_VALUE(   864.00), SIMDE_FLOAT16_VALUE(  -841.00), SIMDE_FLOAT16_VALUE(  -538.00),
        SIMDE_FLOAT16_VALUE(  -316.25), SIMDE_FLOAT16_VALUE(   550.00), SIMDE_FLOAT16_VALUE(  -482.50), SIMDE_FLOAT16_VALUE(  -612.50),
        SIMDE_FLOAT16_VALUE(  -467.75), SIMDE_FLOAT16_VALUE(   658.50), SIMDE_FLOAT16_VALUE(  -508.75), SIMDE_FLOAT16_VALUE(   936.50),
        SIMDE_FLOAT16_VALUE(  -332.25), SIMDE_FLOAT16_VALUE(   697.50), SIMDE_FLOAT16_VALUE(   561.50), SIMDE_FLOAT16_VALUE(   549.50),
        SIMDE_FLOAT16_VALUE(  -165.75), SIMDE_FLOAT16_VALUE(   868.50), SIMDE_FLOAT16_VALUE(  -860.00), SIMDE_FLOAT16_VALUE(  -638.00),
        SIMDE_FLOAT16_VALUE(  -256.50), SIMDE_FLOAT16_VALUE(   164.00), SIMDE_FLOAT16_VALUE(   514.00), SIMDE_FLOAT16_VALUE(   286.75),
        SIMDE_FLOAT16_VALUE(   -31.47), SIMDE_FLOAT16_VALUE(  -847.00), SIMDE_FLOAT16_VALUE(  -226.50), SIMDE_FLOAT16_VALUE(   499.00) },
      { SIMDE_FLOAT16_VALUE(   618.00),            SIMDE_NANHF,            SIMDE_NANHF, SIMDE_FLOAT16_VALUE(   -45.34),
        SIMDE_FLOAT16_VALUE(   747.50), SIMDE_FLOAT16_VALUE(   864.00), SIMDE_FLOAT16_VALUE(  -841.00), SIMDE_FLOAT16_VALUE(  -568.50),
        SIMDE_FLOAT16_VALUE(  -639.00), SIMDE_FLOAT16_VALUE(   934.00), SIMDE_FLOAT16_VALUE(  -181.00), SIMDE_FLOAT16_VALUE(  -106.88),
        SIMDE_FLOAT16_VALUE(   592.50), SIMDE_FLOAT16_VALUE(   310.25), SIMDE_FLOAT16_VALUE(  -170.12), SIMDE_FLOAT16_VALUE(  -740.00),
        SIMDE_FLOAT16_VALUE(     7.86), SIMDE_FLOAT16_VALUE(  -609.00), SIMDE_FLOAT16_VALUE(   809.50), SIMDE_FLOAT16_VALUE(   842.00),
        SIMDE_FLOAT16_VALUE(  -740.50), SIMDE_FLOAT16_VALUE(   950.00), SIMDE_FLOAT16_VALUE(  -796.00), SIMDE_FLOAT16_VALUE(     2.89),
        SIMDE_FLOAT16_VALUE(   113.81), SIMDE_FLOAT16_VALUE(   718.00), SIMDE_FLOAT16_VALUE(  -710.00), SIMDE_FLOAT16_VALUE(  -917.50),
        SIMDE_FLOAT16_VALUE(   871.00), SIMDE_FLOAT16_VALUE(    63.28), SIMDE_FLOAT16_VALUE(   581.50), SIMDE_FLOAT16_VALUE(   489.25) },
      UINT32_C(         0) },
    { {            SIMDE_NANHF,            SIMDE_NANHF, SIMDE_FLOAT16_VALUE(  -305.75), SIMDE_FLOAT16_VALUE(    43.97),
        SIMDE_FLOAT16_VALUE(   860.50), SIMDE_FLOAT16_VALUE(   125.56), SIMDE_FLOAT16_VALUE(   405.00), SIMDE_FLOAT16_VALUE(   794.50),
        SIMDE_FLOAT16_VALUE(   944.50), SIMDE_FLOAT16_VALUE(  -702.00), SIMDE_FLOAT16_VALUE(   386.75), SIMDE_FLOAT16_VALUE(   254.88),
        SIMDE_FLOAT16_VALUE(   127.81), SIMDE_FLOAT16_VALUE(   647.00), SIMDE_FLOAT16_VALUE(  -737.50), SIMDE_FLOAT16_VALUE(   519.00),
        SIMDE_FLOAT16_VALUE(   456.50), SIMDE_FLOAT16_VALUE(  -895.00), SIMDE_FLOAT16_VALUE(   778.50), SIMDE_FLOAT16_VALUE(   406.25),
        SIMDE_FLOAT16_VALUE(  -691.00), SIMDE_FLOAT16_VALUE(  -218.75), SIMDE_FLOAT16_VALUE(  -480.00), SIMDE_FLOAT16_VALUE(  -973.00),
        SIMDE_FLOAT16_VALUE(    70.94), SIMDE_FLOAT16_VALUE(  -397.50), SIMDE_FLOAT16_VALUE(   898.00), SIMDE_FLOAT16_VALUE(  -866.00),
        SIMDE_FLOAT16_VALUE(  -816.00), SIMDE_FLOAT16_VALUE(   387.00), SIMDE_FLOAT16_VALUE(    80.94), SIMDE_FLOAT16_VALUE(  -583.00) },
      { SIMDE_FLOAT16_VALUE(  -767.00),            SIMDE_NANHF,            SIMDE_NANHF, SIMDE_FLOAT16_VALUE(   691.00),
        SIMDE_FLOAT16_VALUE(   -99.31), SIMDE_FLOAT16_VALUE(   125.56), SIMDE_FLOAT16_VALUE(   405.00), SIMDE_FLOAT16_VALUE(   794.50),
        SIMDE_FLOAT16_VALUE(   944.50), SIMDE_FLOAT16_VALUE(  -702.00), SIMDE_FLOAT16_VALUE(   386.75), SIMDE_FLOAT16_VALUE(   254.88),
        SIMDE_FLOAT16_VALUE(   127.81), SIMDE_FLOAT16_VALUE(   647.00), SIMDE_FLOAT16_VALUE(  -737.50), SIMDE_FLOAT16_VALUE(   519.00),
        SIMDE_FLOAT16_VALUE(   456.50), SIMDE_FLOAT16_VALUE(  -895.00), SIMDE_FLOAT16_VALUE(   778.50), SIMDE_FLOAT16_VALUE(   406.25),
        SIMDE_FLOAT16_VALUE(  -691.00), SIMDE_FLOAT16_VALUE(  -218.75), SIMDE_FLOAT16_VALUE(  -480.00), SIMDE_FLOAT16_VALUE(  -973.00),
        SIMDE_FLOAT16_VALUE(    70.94), SIMDE_FLOAT16_VALUE(  -397.50), SIMDE_FLOAT16_VALUE(   898.00), SIMDE_FLOAT16_VALUE(  -866.00),
        SIMDE_FLOAT16_VALUE(  -816.00), SIMDE_FLOAT16_VALUE(   387.00), SIMDE_FLOAT16_VALUE(    80.94), SIMDE_FLOAT16_VALUE(  -583.00) },
      UINT32_C(        24) },
    { {            SIMDE_NANHF,            SIMDE_NANHF, SIMDE_FLOAT16_VALUE(   332.00), SIMDE_FLOAT16_VALUE(   432.25),
        SIMDE_FLOAT16_VALUE(    95.88), SIMDE_FLOAT16_VALUE(  -822.50), SIMDE_FLOAT16_VALUE(  -404.00), SIMDE_FLOAT16_VALUE(   968.50),
        SIMDE_FLOAT16_VALUE(  -722.50), SIMDE_FLOAT16_VALUE(  -112.19), SIMDE_FLOAT16_VALUE(  -512.50), SIMDE_FLOAT16_VALUE(  -359.75),
        SIMDE_FLOAT16_VALUE(  -301.50), SIMDE_FLOAT16_VALUE(  -536.50), SIMDE_FLOAT16_VALUE(   107.81), SIMDE_FLOAT16_VALUE(  -712.50),
        SIMDE_FLOAT16_VALUE(   845.50), SIMDE_FLOAT16_VALUE(   884.50), SIMDE_FLOAT16_VALUE(  -342.50), SIMDE_FLOAT16_VALUE(   747.50),
        SIMDE_FLOAT16_VALUE(  -312.25), SIMDE_FLOAT16_VALUE(  -901.50), SIMDE_FLOAT16_VALUE(  -747.50), SIMDE_FLOAT16_VALUE(   389.00),
        SIMDE_FLOAT16_VALUE(   674.00), SIMDE_FLOAT16_VALUE(   -59.12), SIMDE_FLOAT16_VALUE(   477.50), SIMDE_FLOAT16_VALUE(  -669.50),
        SIMDE_FLOAT16_VALUE(  -953.50), SIMDE_FLOAT16_VALUE(   396.50), SIMDE_FLOAT16_VALUE(  -238.25), SIMDE_FLOAT16_VALUE(  -387.25) },
      { SIMDE_FLOAT16_VALUE(  -433.50),            SIMDE_NANHF,            SIMDE_NANHF, SIMDE_FLOAT16_VALUE(  -897.50),
        SIMDE_FLOAT16_VALUE(    95.88), SIMDE_FLOAT16_VALUE(  -359.00), SIMDE_FLOAT16_VALUE(  -404.00), SIMDE_FLOAT16_VALUE(  -451.50),
        SIMDE_FLOAT16_VALUE(   529.00), SIMDE_FLOAT16_VALUE(  -441.50), SIMDE_FLOAT16_VALUE(   188.62), SIMDE_FLOAT16_VALUE(  -772.50),
        SIMDE_FLOAT16_VALUE(    21.92), SIMDE_FLOAT16_VALUE(  -703.50), SIMDE_FLOAT16_VALUE(  -485.25), SIMDE_FLOAT16_VALUE(  -132.62),
        SIMDE_FLOAT16_VALUE(  -819.50), SIMDE_FLOAT16_VALUE(   172.50), SIMDE_FLOAT16_VALUE(  -385.00), SIMDE_FLOAT16_VALUE(  -131.50),
        SIMDE_FLOAT16_VALUE(   271.25), SIMDE_FLOAT16_VALUE(  -132.50), SIMDE_FLOAT16_VALUE(  -742.50), SIMDE_FLOAT16_VALUE(   -54.75),
        SIMDE_FLOAT16_VALUE(   808.50), SIMDE_FLOAT16_VALUE(   735.00), SIMDE_FLOAT16_VALUE(   275.50), SIMDE_FLOAT16_VALUE(   854.50),
        SIMDE_FLOAT16_VALUE(   131.62), SIMDE_FLOAT16_VALUE(  -962.50), SIMDE_FLOAT16_VALUE(  -532.50), SIMDE_FLOAT16_VALUE(  -861.50) },
      UINT32_C(3834604248) },
    { {            SIMDE_NANHF,            SIMDE_NANHF, SIMDE_FLOAT16_VALUE(  -598.00), SIMDE_FLOAT16_VALUE(   153.50),
        SIMDE_FLOAT16_VALUE(  -688.00), SIMDE_FLOAT16_VALUE(   -49.47), SIMDE_FLOAT16_VALUE(  -317.50), SIMDE_FLOAT16_VALUE(  -129.38),
        SIMDE_FLOAT16_VALUE(  -861.00), SIMDE_FLOAT16_VALUE(   -90.19), SIMDE_FLOAT16_VALUE(   892.50), SIMDE_FLOAT16_VALUE(  -564.50),
        SIMDE_FLOAT16_VALUE(   424.75), SIMDE_FLOAT16_VALUE(  -240.00), SIMDE_FLOAT16_VALUE(  -383.75), SIMDE_FLOAT16_VALUE(  -403.00),
        SIMDE_FLOAT16_VALUE(   375.00), SIMDE_FLOAT16_VALUE(   484.75), SIMDE_FLOAT16_VALUE(   868.00), SIMDE_FLOAT16_VALUE(  -757.50),
        SIMDE_FLOAT16_VALUE(   742.50), SIMDE_FLOAT16_VALUE(  -186.50), SIMDE_FLOAT16_VALUE(  -949.00), SIMDE_FLOAT16_VALUE(   477.50),
        SIMDE_FLOAT16_VALUE(  -911.00), SIMDE_FLOAT16_VALUE(   905.50), SIMDE_FLOAT16_VALUE(  -390.75), SIMDE_FLOAT16_VALUE(  -873.50),
        SIMDE_FLOAT16_VALUE(  -627.00), SIMDE_FLOAT16_VALUE(  -252.38), SIMDE_FLOAT16_VALUE(  -742.50), SIMDE_FLOAT16_VALUE(  -114.69) },
      { SIMDE_FLOAT16_VALUE(   -11.27),            SIMDE_NANHF,            SIMDE_NANHF, SIMDE_FLOAT16_VALUE(   300.75),
        SIMDE_FLOAT16_VALUE(   610.00), SIMDE_FLOAT16_VALUE(  -278.75), SIMDE_FLOAT16_VALUE(  -317.50), SIMDE_FLOAT16_VALUE(   749.00),
        SIMDE_FLOAT16_VALUE(   631.00), SIMDE_FLOAT16_VALUE(  -936.00), SIMDE_FLOAT16_VALUE(  -815.00), SIMDE_FLOAT16_VALUE(    55.59),
        SIMDE_FLOAT16_VALUE(  -176.00), SIMDE_FLOAT16_VALUE(  -199.00), SIMDE_FLOAT16_VALUE(   652.50), SIMDE_FLOAT16_VALUE(  -801.00),
        SIMDE_FLOAT16_VALUE(  -714.00), SIMDE_FLOAT16_VALUE(   521.00), SIMDE_FLOAT16_VALUE(  -558.50), SIMDE_FLOAT16_VALUE(  -971.50),
        SIMDE_FLOAT16_VALUE(  -665.50), SIMDE_FLOAT16_VALUE(  -507.50), SIMDE_FLOAT16_VALUE(   505.75), SIMDE_FLOAT16_VALUE(  -576.50),
        SIMDE_FLOAT16_VALUE(  -602.00), SIMDE_FLOAT16_VALUE(  -885.00), SIMDE_FLOAT16_VALUE(  -450.25), SIMDE_FLOAT16_VALUE(  -229.12),
        SIMDE_FLOAT16_VALUE(  -137.50), SIMDE_FLOAT16_VALUE(  -192.75), SIMDE_FLOAT16_VALUE(   656.00), SIMDE_FLOAT16_VALUE(   851.00) },
      UINT32_C( 113088032) },
    { {            SIMDE_NANHF,            SIMDE_NANHF, SIMDE_FLOAT16_VALUE(    76.94), SIMDE_FLOAT16_VALUE(  -584.00),
        SIMDE_FLOAT16_VALUE(   323.50), SIMDE_FLOAT16_VALUE(  -173.88), SIMDE_FLOAT16_VALUE(  -953.00), SIMDE_FLOAT16_VALUE(   387.75),
        SIMDE_FLOAT16_VALUE(    10.90), SIMDE_FLOAT16_VALUE(   102.69), SIMDE_FLOAT16_VALUE(  -788.50), SIMDE_FLOAT16_VALUE(   812.00),
        SIMDE_FLOAT16_VALUE(  -244.62), SIMDE_FLOAT16_VALUE(  -589.00), SIMDE_FLOAT16_VALUE(  -902.00), SIMDE_FLOAT16_VALUE(  -723.50),
        SIMDE_FLOAT16_VALUE(  -147.62), SIMDE_FLOAT16_VALUE(  -874.00), SIMDE_FLOAT16_VALUE(  -389.25), SIMDE_FLOAT16_VALUE(   345.00),
        SIMDE_FLOAT16_VALUE(   632.00), SIMDE_FLOAT16_VALUE(    34.09), SIMDE_FLOAT16_VALUE(   743.00), SIMDE_FLOAT16_VALUE(   747.00),
        SIMDE_FLOAT16_VALUE(   584.00), SIMDE_FLOAT16_VALUE(  -486.25), SIMDE_FLOAT16_VALUE(  -390.75), SIMDE_FLOAT16_VALUE(  -609.00),
        SIMDE_FLOAT16_VALUE(  -830.00), SIMDE_FLOAT16_VALUE(  -539.50), SIMDE_FLOAT16_VALUE(   858.00), SIMDE_FLOAT16_VALUE(   865.00) },
      { SIMDE_FLOAT16_VALUE(   612.50),            SIMDE_NANHF,            SIMDE_NANHF, SIMDE_FLOAT16_VALUE(  -584.00),
        SIMDE_FLOAT16_VALUE(   761.00), SIMDE_FLOAT16_VALUE(  -173.88), SIMDE_FLOAT16_VALUE(  -676.00), SIMDE_FLOAT16_VALUE(   387.75),
        SIMDE_FLOAT16_VALUE(    10.90), SIMDE_FLOAT16_VALUE(   102.69), SIMDE_FLOAT16_VALUE(  -788.50), SIMDE_FLOAT16_VALUE(   812.00),
        SIMDE_FLOAT16_VALUE(  -244.62), SIMDE_FLOAT16_VALUE(  -589.00), SIMDE_FLOAT16_VALUE(  -902.00), SIMDE_FLOAT16_VALUE(  -723.50),
        SIMDE_FLOAT16_VALUE(  -147.62), SIMDE_FLOAT16_VALUE(  -874.00), SIMDE_FLOAT16_VALUE(  -389.25), SIMDE_FLOAT16_VALUE(   345.00),
        SIMDE_FLOAT16_VALUE(   632.00), SIMDE_FLOAT16_VALUE(    34.09), SIMDE_FLOAT16_VALUE(   743.00), SIMDE_FLOAT16_VALUE(   747.00),
        SIMDE_FLOAT16_VALUE(   584.00), SIMDE_FLOAT16_VALUE(  -486.25), SIMDE_FLOAT16_VALUE(  -390.75), SIMDE_FLOAT16_VALUE(  -609.00),
        SIMDE_FLOAT16_VALUE(  -830.00), SIMDE_FLOAT16_VALUE(  -539.50), SIMDE_FLOAT16_VALUE(   858.00), SIMDE_FLOAT16_VALUE(   865.00) },
                UINT32_MAX },
    { {            SIMDE_NANHF,            SIMDE_NANHF, SIMDE_FLOAT16_VALUE(  -363.75), SIMDE_FLOAT16_VALUE(  -955.00),
        SIMDE_FLOAT16_VALUE(  -871.50), SIMDE_FLOAT16_VALUE(   408.00), SIMDE_FLOAT16_VALUE(   475.75), SIMDE_FLOAT16_VALUE(  -336.00),
        SIMDE_FLOAT16_VALUE(   992.00), SIMDE_FLOAT16_VALUE(   662.00), SIMDE_FLOAT16_VALUE(   610.50), SIMDE_FLOAT16_VALUE(  -326.50),
        SIMDE_FLOAT16_VALUE(  -875.50), SIMDE_FLOAT16_VALUE(   409.00), SIMDE_FLOAT16_VALUE(   481.25), SIMDE_FLOAT16_VALUE(   197.88),
        SIMDE_FLOAT16_VALUE(  -447.50), SIMDE_FLOAT16_VALUE(   920.50), SIMDE_FLOAT16_VALUE(   305.00), SIMDE_FLOAT16_VALUE(   438.75),
        SIMDE_FLOAT16_VALUE(  -893.00), SIMDE_FLOAT16_VALUE(    -3.70), SIMDE_FLOAT16_VALUE(  -160.88), SIMDE_FLOAT16_VALUE(   -97.44),
        SIMDE_FLOAT16_VALUE(    78.62), SIMDE_FLOAT16_VALUE(  -590.50), SIMDE_FLOAT16_VALUE(  -841.50), SIMDE_FLOAT16_VALUE(    18.92),
        SIMDE_FLOAT16_VALUE(   845.00), SIMDE_FLOAT16_VALUE(    27.38), SIMDE_FLOAT16_VALUE(   894.00), SIMDE_FLOAT16_VALUE(   561.50) },
      { SIMDE_FLOAT16_VALUE(  -167.75),            SIMDE_NANHF,            SIMDE_NANHF, SIMDE_FLOAT16_VALUE(  -955.00),
        SIMDE_FLOAT16_VALUE(   938.50), SIMDE_FLOAT16_VALUE(   408.00), SIMDE_FLOAT16_VALUE(   475.75), SIMDE_FLOAT16_VALUE(   930.00),
        SIMDE_FLOAT16_VALUE(  -256.25), SIMDE_FLOAT16_VALUE(   235.25), SIMDE_FLOAT16_VALUE(  -396.25), SIMDE_FLOAT16_VALUE(  -131.62),
        SIMDE_FLOAT16_VALUE(  -355.75), SIMDE_FLOAT16_VALUE(  -915.00), SIMDE_FLOAT16_VALUE(  -934.00), SIMDE_FLOAT16_VALUE(   196.62),
        SIMDE_FLOAT16_VALUE(  -994.50), SIMDE_FLOAT16_VALUE(   371.25), SIMDE_FLOAT16_VALUE(  -364.50), SIMDE_FLOAT16_VALUE(  -887.50),
        SIMDE_FLOAT16_VALUE(  -632.50), SIMDE_FLOAT16_VALUE(   474.50), SIMDE_FLOAT16_VALUE(    15.05), SIMDE_FLOAT16_VALUE(   446.25),
        SIMDE_FLOAT16_VALUE(   884.00), SIMDE_FLOAT16_VALUE(   173.75), SIMDE_FLOAT16_VALUE(  -535.00), SIMDE_FLOAT16_VALUE(   729.00),
        SIMDE_FLOAT16_VALUE(  -799.00), SIMDE_FLOAT16_VALUE(  -641.00), SIMDE_FLOAT16_VALUE(   290.00), SIMDE_FLOAT16_VALUE(    33.31) },
      UINT32_C(       104) },
    { {            SIMDE_NANHF,            SIMDE_NANHF, SIMDE_FLOAT16_VALUE(  -172.25), SIMDE_FLOAT16_VALUE(   978.00),
        SIMDE_FLOAT16_VALUE(   619.00), SIMDE_FLOAT16_VALUE(  -242.12), SIMDE_FLOAT16_VALUE(  -278.50), SIMDE_FLOAT16_VALUE(  -145.62),
        SIMDE_FLOAT16_VALUE(   361.50), SIMDE_FLOAT16_VALUE(   590.00), SIMDE_FLOAT16_VALUE(   498.50), SIMDE_FLOAT16_VALUE(   446.50),
        SIMDE_FLOAT16_VALUE(   656.00), SIMDE_FLOAT16_VALUE(  -305.00), SIMDE_FLOAT16_VALUE(   452.00), SIMDE_FLOAT16_VALUE(    27.39),
        SIMDE_FLOAT16_VALUE(   330.50), SIMDE_FLOAT16_VALUE(   564.50), SIMDE_FLOAT16_VALUE(   395.00), SIMDE_FLOAT16_VALUE(  -194.88),
        SIMDE_FLOAT16_VALUE(  -420.50), SIMDE_FLOAT16_VALUE(  -158.75), SIMDE_FLOAT16_VALUE(  -311.00), SIMDE_FLOAT16_VALUE(   753.00),
        SIMDE_FLOAT16_VALUE(   306.25), SIMDE_FLOAT16_VALUE(  -582.00), SIMDE_FLOAT16_VALUE(   954.50), SIMDE_FLOAT16_VALUE(   665.50),
        SIMDE_FLOAT16_VALUE(   708.00), SIMDE_FLOAT16_VALUE(   -12.36), SIMDE_FLOAT16_VALUE(  -445.00), SIMDE_FLOAT16_VALUE(  -396.00) },
      { SIMDE_FLOAT16_VALUE(  -103.94),            SIMDE_NANHF,            SIMDE_NANHF, SIMDE_FLOAT16_VALUE(  -399.00),
        SIMDE_FLOAT16_VALUE(   619.00), SIMDE_FLOAT16_VALUE(   303.25), SIMDE_FLOAT16_VALUE(  -278.50), SIMDE_FLOAT16_VALUE(   502.25),
        SIMDE_FLOAT16_VALUE(  -106.81), SIMDE_FLOAT16_VALUE(   -46.12), SIMDE_FLOAT16_VALUE(   -51.25), SIMDE_FLOAT16_VALUE(  -450.75),
        SIMDE_FLOAT16_VALUE(   649.00), SIMDE_FLOAT16_VALUE(  -599.50), SIMDE_FLOAT16_VALUE(   576.50), SIMDE_FLOAT16_VALUE(   -20.53),
        SIMDE_FLOAT16_VALUE(   965.00), SIMDE_FLOAT16_VALUE(   -28.34), SIMDE_FLOAT16_VALUE(   784.50), SIMDE_FLOAT16_VALUE(  -455.25),
        SIMDE_FLOAT16_VALUE(   813.00), SIMDE_FLOAT16_VALUE(  -526.50), SIMDE_FLOAT16_VALUE(  -702.00), SIMDE_FLOAT16_VALUE(   119.19),
        SIMDE_FLOAT16_VALUE(  -108.50), SIMDE_FLOAT16_VALUE(  -748.00), SIMDE_FLOAT16_VALUE(  -215.25), SIMDE_FLOAT16_VALUE(  -400.75),
        SIMDE_FLOAT16_VALUE(   239.75), SIMDE_FLOAT16_VALUE(   339.75), SIMDE_FLOAT16_VALUE(   203.25), SIMDE_FLOAT16_VALUE(  -778.50) },
      UINT32_C(1612005536) },
    { {            SIMDE_NANHF,            SIMDE_NANHF, SIMDE_FLOAT16_VALUE(  -136.75), SIMDE_FLOAT16_VALUE(    88.31),
        SIMDE_FLOAT16_VALUE(  -722.00), SIMDE_FLOAT16_VALUE(  -634.50), SIMDE_FLOAT16_VALUE(   981.50), SIMDE_FLOAT16_VALUE(   231.75),
        SIMDE_FLOAT16_VALUE(   314.25), SIMDE_FLOAT16_VALUE(  -469.25), SIMDE_FLOAT16_VALUE(  -119.25), SIMDE_FLOAT16_VALUE(   715.00),
        SIMDE_FLOAT16_VALUE(  -892.50), SIMDE_FLOAT16_VALUE(   860.00), SIMDE_FLOAT16_VALUE(   680.00), SIMDE_FLOAT16_VALUE(    79.06),
        SIMDE_FLOAT16_VALUE(   645.00), SIMDE_FLOAT16_VALUE(  -775.00), SIMDE_FLOAT16_VALUE(  -108.06), SIMDE_FLOAT16_VALUE(  -881.50),
        SIMDE_FLOAT16_VALUE(  -477.50), SIMDE_FLOAT16_VALUE(  -989.00), SIMDE_FLOAT16_VALUE(     9.85), SIMDE_FLOAT16_VALUE(  -225.25),
        SIMDE_FLOAT16_VALUE(  -204.12), SIMDE_FLOAT16_VALUE(   609.00), SIMDE_FLOAT16_VALUE(  -985.50), SIMDE_FLOAT16_VALUE(  -864.50),
        SIMDE_FLOAT16_VALUE(  -187.50), SIMDE_FLOAT16_VALUE(  -764.00), SIMDE_FLOAT16_VALUE(  -141.75), SIMDE_FLOAT16_VALUE(  -402.50) },
      { SIMDE_FLOAT16_VALUE(   785.00),            SIMDE_NANHF,            SIMDE_NANHF, SIMDE_FLOAT16_VALUE(   336.75),
        SIMDE_FLOAT16_VALUE(  -722.00), SIMDE_FLOAT16_VALUE(  -634.50), SIMDE_FLOAT16_VALUE(  -431.50), SIMDE_FLOAT16_VALUE(   401.25),
        SIMDE_FLOAT16_VALUE(  -802.00), SIMDE_FLOAT16_VALUE(   449.25), SIMDE_FLOAT16_VALUE(   116.25), SIMDE_FLOAT16_VALUE(  -694.50),
        SIMDE_FLOAT16_VALUE(   309.50), SIMDE_FLOAT16_VALUE(  -203.62), SIMDE_FLOAT16_VALUE(   384.50), SIMDE_FLOAT16_VALUE(   -45.75),
        SIMDE_FLOAT16_VALUE(    21.19), SIMDE_FLOAT16_VALUE(  -723.50), SIMDE_FLOAT16_VALUE(    72.62), SIMDE_FLOAT16_VALUE(   544.00),
        SIMDE_FLOAT16_VALUE(  -712.50), SIMDE_FLOAT16_VALUE(  -917.50), SIMDE_FLOAT16_VALUE(  -681.50), SIMDE_FLOAT16_VALUE(    83.56),
        SIMDE_FLOAT16_VALUE(   691.50), SIMDE_FLOAT16_VALUE(  -667.00), SIMDE_FLOAT16_VALUE(   219.25), SIMDE_FLOAT16_VALUE(  -495.75),
        SIMDE_FLOAT16_VALUE(  -430.75), SIMDE_FLOAT16_VALUE(  -922.50), SIMDE_FLOAT16_VALUE(   101.69), SIMDE_FLOAT16_VALUE(   628.00) },
      UINT32_C(3450738360) },
    { {            SIMDE_NANHF,            SIMDE_NANHF, SIMDE_FLOAT16_VALUE(   886.00), SIMDE_FLOAT16_VALUE(  -545.00),
        SIMDE_FLOAT16_VALUE(   533.50), SIMDE_FLOAT16_VALUE(   287.25), SIMDE_FLOAT16_VALUE(  -347.25), SIMDE_FLOAT16_VALUE(   -17.33),
        SIMDE_FLOAT16_VALUE(  -596.50), SIMDE_FLOAT16_VALUE(   -41.75), SIMDE_FLOAT16_VALUE(  -708.00), SIMDE_FLOAT16_VALUE(   199.88),
        SIMDE_FLOAT16_VALUE(  -657.00), SIMDE_FLOAT16_VALUE(   246.38), SIMDE_FLOAT16_VALUE(  -779.00), SIMDE_FLOAT16_VALUE(  -380.75),
        SIMDE_FLOAT16_VALUE(  -681.00), SIMDE_FLOAT16_VALUE(   765.00), SIMDE_FLOAT16_VALUE(   -93.06), SIMDE_FLOAT16_VALUE(  -598.50),
        SIMDE_FLOAT16_VALUE(  -916.50), SIMDE_FLOAT16_VALUE(   990.50), SIMDE_FLOAT16_VALUE(  -907.00), SIMDE_FLOAT16_VALUE(  -583.50),
        SIMDE_FLOAT16_VALUE(   209.62), SIMDE_FLOAT16_VALUE(  -402.50), SIMDE_FLOAT16_VALUE(   -14.16), SIMDE_FLOAT16_VALUE(   287.00),
        SIMDE_FLOAT16_VALUE(   699.00), SIMDE_FLOAT16_VALUE(  -386.00), SIMDE_FLOAT16_VALUE(    85.94), SIMDE_FLOAT16_VALUE(  -513.50) },
      { SIMDE_FLOAT16_VALUE(  -212.50),            SIMDE_NANHF,            SIMDE_NANHF, SIMDE_FLOAT16_VALUE(   112.25),
        SIMDE_FLOAT16_VALUE(   533.50), SIMDE_FLOAT16_VALUE(   594.00), SIMDE_FLOAT16_VALUE(  -347.25), SIMDE_FLOAT16_VALUE(   -17.33),
        SIMDE_FLOAT16_VALUE(  -596.50), SIMDE_FLOAT16_VALUE(   -41.75), SIMDE_FLOAT16_VALUE(  -708.00), SIMDE_FLOAT16_VALUE(   199.88),
        SIMDE_FLOAT16_VALUE(  -657.00), SIMDE_FLOAT16_VALUE(   246.38), SIMDE_FLOAT16_VALUE(  -779.00), SIMDE_FLOAT16_VALUE(  -380.75),
        SIMDE_FLOAT16_VALUE(  -681.00), SIMDE_FLOAT16_VALUE(   765.00), SIMDE_FLOAT16_VALUE(   -93.06), SIMDE_FLOAT16_VALUE(  -598.50),
        SIMDE_FLOAT16_VALUE(  -916.50), SIMDE_FLOAT16_VALUE(   990.50), SIMDE_FLOAT16_VALUE(  -907.00), SIMDE_FLOAT16_VALUE(  -583.50),
        SIMDE_FLOAT16_VALUE(   209.62), SIMDE_FLOAT16_VALUE(  -402.50), SIMDE_FLOAT16_VALUE(   -14.16), SIMDE_FLOAT16_VALUE(   287.00),
        SIMDE_FLOAT16_VALUE(   699.00), SIMDE_FLOAT16_VALUE(  -386.00), SIMDE_FLOAT16_VALUE(    85.94), SIMDE_FLOAT16_VALUE(  -513.50) },
      UINT32_C(         7) },
    { {            SIMDE_NANHF,            SIMDE_NANHF, SIMDE_FLOAT16_VALUE(   225.25), SIMDE_FLOAT16_VALUE(   766.00),
        SIMDE_FLOAT16_VALUE(  -266.50), SIMDE_FLOAT16_VALUE(   887.50), SIMDE_FLOAT16_VALUE(  -682.00), SIMDE_FLOAT16_VALUE(   120.69),
        SIMDE_FLOAT16_VALUE(   749.50), SIMDE_FLOAT16_VALUE(   213.38), SIMDE_FLOAT16_VALUE(  -245.88), SIMDE_FLOAT16_VALUE(   833.00),
        SIMDE_FLOAT16_VALUE(  -272.00), SIMDE_FLOAT16_VALUE(  -293.25), SIMDE_FLOAT16_VALUE(   681.00), SIMDE_FLOAT16_VALUE(   149.25),
        SIMDE_FLOAT16_VALUE(    60.69), SIMDE_FLOAT16_VALUE(   612.00), SIMDE_FLOAT16_VALUE(   561.00), SIMDE_FLOAT16_VALUE(   508.00),
        SIMDE_FLOAT16_VALUE(   960.00), SIMDE_FLOAT16_VALUE(   182.75), SIMDE_FLOAT16_VALUE(  -447.50), SIMDE_FLOAT16_VALUE(   293.50),
        SIMDE_FLOAT16_VALUE(  -908.50), SIMDE_FLOAT16_VALUE(   296.50), SIMDE_FLOAT16_VALUE(   241.12), SIMDE_FLOAT16_VALUE(  -914.00),
        SIMDE_FLOAT16_VALUE(  -473.25), SIMDE_FLOAT16_VALUE(  -232.50), SIMDE_FLOAT16_VALUE(    52.41), SIMDE_FLOAT16_VALUE(  -301.50) },
      { SIMDE_FLOAT16_VALUE(   406.25),            SIMDE_NANHF,            SIMDE_NANHF, SIMDE_FLOAT16_VALUE(   766.00),
        SIMDE_FLOAT16_VALUE(  -834.50), SIMDE_FLOAT16_VALUE(  -217.50), SIMDE_FLOAT16_VALUE(  -682.00), SIMDE_FLOAT16_VALUE(   120.69),
        SIMDE_FLOAT16_VALUE(   749.50), SIMDE_FLOAT16_VALUE(   213.38), SIMDE_FLOAT16_VALUE(  -245.88), SIMDE_FLOAT16_VALUE(   833.00),
        SIMDE_FLOAT16_VALUE(  -272.00), SIMDE_FLOAT16_VALUE(  -293.25), SIMDE_FLOAT16_VALUE(   681.00), SIMDE_FLOAT16_VALUE(   149.25),
        SIMDE_FLOAT16_VALUE(    60.69), SIMDE_FLOAT16_VALUE(   612.00), SIMDE_FLOAT16_VALUE(   561.00), SIMDE_FLOAT16_VALUE(   508.00),
        SIMDE_FLOAT16_VALUE(   960.00), SIMDE_FLOAT16_VALUE(   182.75), SIMDE_FLOAT16_VALUE(  -447.50), SIMDE_FLOAT16_VALUE(   293.50),
        SIMDE_FLOAT16_VALUE(  -908.50), SIMDE_FLOAT16_VALUE(   296.50), SIMDE_FLOAT16_VALUE(   241.12), SIMDE_FLOAT16_VALUE(  -914.00),
        SIMDE_FLOAT16_VALUE(  -473.25), SIMDE_FLOAT16_VALUE(  -232.50), SIMDE_FLOAT16_VALUE(    52.41), SIMDE_FLOAT16_VALUE(  -301.50) },
      UINT32_C(        55) },
    { {            SIMDE_NANHF,            SIMDE_NANHF, SIMDE_FLOAT16_VALUE(  -710.00), SIMDE_FLOAT16_VALUE(   611.00),
        SIMDE_FLOAT16_VALUE(   109.38), SIMDE_FLOAT16_VALUE(  -795.00), SIMDE_FLOAT16_VALUE(   607.00), SIMDE_FLOAT16_VALUE(   124.00),
        SIMDE_FLOAT16_VALUE(   952.50), SIMDE_FLOAT16_VALUE(  -669.00), SIMDE_FLOAT16_VALUE(   845.50), SIMDE_FLOAT16_VALUE(   381.50),
        SIMDE_FLOAT16_VALUE(  -796.00), SIMDE_FLOAT16_VALUE(   627.50), SIMDE_FLOAT16_VALUE(  -578.00), SIMDE_FLOAT16_VALUE(   638.00),
        SIMDE_FLOAT16_VALUE(   -82.81), SIMDE_FLOAT16_VALUE(   422.75), SIMDE_FLOAT16_VALUE(  -744.50), SIMDE_FLOAT16_VALUE(  -240.25),
        SIMDE_FLOAT16_VALUE(   717.00), SIMDE_FLOAT16_VALUE(   -36.16), SIMDE_FLOAT16_VALUE(   898.50), SIMDE_FLOAT16_VALUE(   252.25),
        SIMDE_FLOAT16_VALUE(   758.50), SIMDE_FLOAT16_VALUE(   564.50), SIMDE_FLOAT16_VALUE(   555.00), SIMDE_FLOAT16_VALUE(   605.50),
        SIMDE_FLOAT16_VALUE(   928.50), SIMDE_FLOAT16_VALUE(   264.00), SIMDE_FLOAT16_VALUE(   730.00), SIMDE_FLOAT16_VALUE(  -243.00) },
      { SIMDE_FLOAT16_VALUE(   112.94),            SIMDE_NANHF,            SIMDE_NANHF, SIMDE_FLOAT16_VALUE(   611.00),
        SIMDE_FLOAT16_VALUE(  -775.50), SIMDE_FLOAT16_VALUE(  -795.00), SIMDE_FLOAT16_VALUE(   607.00), SIMDE_FLOAT16_VALUE(  -822.50),
        SIMDE_FLOAT16_VALUE(  -694.00), SIMDE_FLOAT16_VALUE(   191.62), SIMDE_FLOAT16_VALUE(   559.00), SIMDE_FLOAT16_VALUE(  -490.25),
        SIMDE_FLOAT16_VALUE(  -181.00), SIMDE_FLOAT16_VALUE(   981.00), SIMDE_FLOAT16_VALUE(  -852.00), SIMDE_FLOAT16_VALUE(   736.00),
        SIMDE_FLOAT16_VALUE(   403.75), SIMDE_FLOAT16_VALUE(  -596.50), SIMDE_FLOAT16_VALUE(  -504.00), SIMDE_FLOAT16_VALUE(   120.81),
        SIMDE_FLOAT16_VALUE(   367.25), SIMDE_FLOAT16_VALUE(  -605.50), SIMDE_FLOAT16_VALUE(  -627.00), SIMDE_FLOAT16_VALUE(   125.56),
        SIMDE_FLOAT16_VALUE(   959.00), SIMDE_FLOAT16_VALUE(   928.00), SIMDE_FLOAT16_VALUE(  -269.00), SIMDE_FLOAT16_VALUE(   887.50),
        SIMDE_FLOAT16_VALUE(   192.12), SIMDE_FLOAT16_VALUE(  -539.00), SIMDE_FLOAT16_VALUE(  -355.75), SIMDE_FLOAT16_VALUE(  -695.00) },
      UINT32_C(4109520383) },
    { {            SIMDE_NANHF,            SIMDE_NANHF, SIMDE_FLOAT16_VALUE(  -294.50), SIMDE_FLOAT16_VALUE(   -12.61),
        SIMDE_FLOAT16_VALUE(   873.50), SIMDE_FLOAT16_VALUE(  -117.06), SIMDE_FLOAT16_VALUE(   293.25), SIMDE_FLOAT16_VALUE(    65.38),
        SIMDE_FLOAT16_VALUE(  -558.00), SIMDE_FLOAT16_VALUE(   803.00), SIMDE_FLOAT16_VALUE(   884.50), SIMDE_FLOAT16_VALUE(  -577.00),
        SIMDE_FLOAT16_VALUE(   951.00), SIMDE_FLOAT16_VALUE(   620.50), SIMDE_FLOAT16_VALUE(   826.50), SIMDE_FLOAT16_VALUE(  -645.50),
        SIMDE_FLOAT16_VALUE(  -883.50), SIMDE_FLOAT16_VALUE(   -52.47), SIMDE_FLOAT16_VALUE(   721.50), SIMDE_FLOAT16_VALUE(  -489.00),
        SIMDE_FLOAT16_VALUE(   320.50), SIMDE_FLOAT16_VALUE(  -153.00), SIMDE_FLOAT16_VALUE(  -530.00), SIMDE_FLOAT16_VALUE(   248.62),
        SIMDE_FLOAT16_VALUE(   578.00), SIMDE_FLOAT16_VALUE(  -643.00), SIMDE_FLOAT16_VALUE(  -559.50), SIMDE_FLOAT16_VALUE(  -961.00),
        SIMDE_FLOAT16_VALUE(     1.58), SIMDE_FLOAT16_VALUE(  -254.38), SIMDE_FLOAT16_VALUE(  -480.50), SIMDE_FLOAT16_VALUE(  -986.00) },
      { SIMDE_FLOAT16_VALUE(   273.00),            SIMDE_NANHF,            SIMDE_NANHF, SIMDE_FLOAT16_VALUE(   -12.61),
        SIMDE_FLOAT16_VALUE(  -892.00), SIMDE_FLOAT16_VALUE(  -117.06), SIMDE_FLOAT16_VALUE(   293.25), SIMDE_FLOAT16_VALUE(  -450.25),
        SIMDE_FLOAT16_VALUE(  -902.50), SIMDE_FLOAT16_VALUE(  -903.50), SIMDE_FLOAT16_VALUE(   -27.42), SIMDE_FLOAT16_VALUE(  -951.50),
        SIMDE_FLOAT16_VALUE(   717.00), SIMDE_FLOAT16_VALUE(  -200.75), SIMDE_FLOAT16_VALUE(  -597.50), SIMDE_FLOAT16_VALUE(   833.00),
        SIMDE_FLOAT16_VALUE(   747.00), SIMDE_FLOAT16_VALUE(  -876.00), SIMDE_FLOAT16_VALUE(  -656.00), SIMDE_FLOAT16_VALUE(    67.38),
        SIMDE_FLOAT16_VALUE(   -28.84), SIMDE_FLOAT16_VALUE(  -186.00), SIMDE_FLOAT16_VALUE(  -684.00), SIMDE_FLOAT16_VALUE(  -451.00),
        SIMDE_FLOAT16_VALUE(   171.12), SIMDE_FLOAT16_VALUE(  -243.38), SIMDE_FLOAT16_VALUE(  -412.25), SIMDE_FLOAT16_VALUE(  -827.00),
        SIMDE_FLOAT16_VALUE(   502.25), SIMDE_FLOAT16_VALUE(   107.31), SIMDE_FLOAT16_VALUE(  -813.50), SIMDE_FLOAT16_VALUE(  -224.75) },
      UINT32_C(1106673559) },
    { {            SIMDE_NANHF,            SIMDE_NANHF, SIMDE_FLOAT16_VALUE(  -560.00), SIMDE_FLOAT16_VALUE(   482.75),
        SIMDE_FLOAT16_VALUE(  -866.00), SIMDE_FLOAT16_VALUE(   -10.07), SIMDE_FLOAT16_VALUE(   580.00), SIMDE_FLOAT16_VALUE(  -769.50),
        SIMDE_FLOAT16_VALUE(   962.50), SIMDE_FLOAT16_VALUE(   628.50), SIMDE_FLOAT16_VALUE(   947.00), SIMDE_FLOAT16_VALUE(  -238.25),
        SIMDE_FLOAT16_VALUE(  -968.50), SIMDE_FLOAT16_VALUE(   780.50), SIMDE_FLOAT16_VALUE(  -491.25), SIMDE_FLOAT16_VALUE(  -844.50),
        SIMDE_FLOAT16_VALUE(  -875.50), SIMDE_FLOAT16_VALUE(   576.00), SIMDE_FLOAT16_VALUE(   126.69), SIMDE_FLOAT16_VALUE(   -61.44),
        SIMDE_FLOAT16_VALUE(   892.00), SIMDE_FLOAT16_VALUE(   675.50), SIMDE_FLOAT16_VALUE(  -890.50), SIMDE_FLOAT16_VALUE(  -351.50),
        SIMDE_FLOAT16_VALUE(  -736.50), SIMDE_FLOAT16_VALUE(  -717.50), SIMDE_FLOAT16_VALUE(  -849.00), SIMDE_FLOAT16_VALUE(   371.00),
        SIMDE_FLOAT16_VALUE(  -531.00), SIMDE_FLOAT16_VALUE(   -73.94), SIMDE_FLOAT16_VALUE(   703.00), SIMDE_FLOAT16_VALUE(   657.50) },
      { SIMDE_FLOAT16_VALUE(   188.12),            SIMDE_NANHF,            SIMDE_NANHF, SIMDE_FLOAT16_VALUE(   -17.95),
        SIMDE_FLOAT16_VALUE(  -866.00), SIMDE_FLOAT16_VALUE(   -10.07), SIMDE_FLOAT16_VALUE(   580.00), SIMDE_FLOAT16_VALUE(  -769.50),
        SIMDE_FLOAT16_VALUE(   962.50), SIMDE_FLOAT16_VALUE(   628.50), SIMDE_FLOAT16_VALUE(   947.00), SIMDE_FLOAT16_VALUE(  -238.25),
        SIMDE_FLOAT16_VALUE(  -968.50), SIMDE_FLOAT16_VALUE(   780.50), SIMDE_FLOAT16_VALUE(  -491.25), SIMDE_FLOAT16_VALUE(  -844.50),
        SIMDE_FLOAT16_VALUE(  -875.50), SIMDE_FLOAT16_VALUE(   576.00), SIMDE_FLOAT16_VALUE(   126.69), SIMDE_FLOAT16_VALUE(   -61.44),
        SIMDE_FLOAT16_VALUE(   892.00), SIMDE_FLOAT16_VALUE(   675.50), SIMDE_FLOAT16_VALUE(  -890.50), SIMDE_FLOAT16_VALUE(  -351.50),
        SIMDE_FLOAT16_VALUE(  -736.50), SIMDE_FLOAT16_VALUE(  -717.50), SIMDE_FLOAT16_VALUE(  -849.00), SIMDE_FLOAT16_VALUE(   371.00),
        SIMDE_FLOAT16_VALUE(  -531.00), SIMDE_FLOAT16_VALUE(   -73.94), SIMDE_FLOAT16_VALUE(   703.00), SIMDE_FLOAT16_VALUE(   657.50) },
      UINT32_C(4294967288) },
    { {            SIMDE_NANHF,            SIMDE_NANHF, SIMDE_FLOAT16_VALUE(   952.50), SIMDE_FLOAT16_VALUE(  -618.00),
        SIMDE_FLOAT16_VALUE(  -397.75), SIMDE_FLOAT16_VALUE(    48.28), SIMDE_FLOAT16_VALUE(  -269.25), SIMDE_FLOAT16_VALUE(   762.00),
        SIMDE_FLOAT16_VALUE(   -94.00), SIMDE_FLOAT16_VALUE(   110.88), SIMDE_FLOAT16_VALUE(  -298.00), SIMDE_FLOAT16_VALUE(   272.25),
        SIMDE_FLOAT16_VALUE(   646.50), SIMDE_FLOAT16_VALUE(   766.50), SIMDE_FLOAT16_VALUE(   214.62), SIMDE_FLOAT16_VALUE(   308.75),
        SIMDE_FLOAT16_VALUE(   770.00), SIMDE_FLOAT16_VALUE(    48.91), SIMDE_FLOAT16_VALUE(  -353.25), SIMDE_FLOAT16_VALUE(   882.50),
        SIMDE_FLOAT16_VALUE(   532.00), SIMDE_FLOAT16_VALUE(  -752.00), SIMDE_FLOAT16_VALUE(  -722.00), SIMDE_FLOAT16_VALUE(  -834.50),
        SIMDE_FLOAT16_VALUE(   220.62), SIMDE_FLOAT16_VALUE(   142.88), SIMDE_FLOAT16_VALUE(   725.00), SIMDE_FLOAT16_VALUE(   896.00),
        SIMDE_FLOAT16_VALUE(   665.00), SIMDE_FLOAT16_VALUE(  -867.00), SIMDE_FLOAT16_VALUE(  -284.75), SIMDE_FLOAT16_VALUE(   326.75) },
      { SIMDE_FLOAT16_VALUE(   662.00),            SIMDE_NANHF,            SIMDE_NANHF, SIMDE_FLOAT16_VALUE(  -875.00),
        SIMDE_FLOAT16_VALUE(   716.00), SIMDE_FLOAT16_VALUE(    48.28), SIMDE_FLOAT16_VALUE(   887.00), SIMDE_FLOAT16_VALUE(   762.00),
        SIMDE_FLOAT16_VALUE(   -94.00), SIMDE_FLOAT16_VALUE(   110.88), SIMDE_FLOAT16_VALUE(  -298.00), SIMDE_FLOAT16_VALUE(   272.25),
        SIMDE_FLOAT16_VALUE(   646.50), SIMDE_FLOAT16_VALUE(   766.50), SIMDE_FLOAT16_VALUE(   214.62), SIMDE_FLOAT16_VALUE(   308.75),
        SIMDE_FLOAT16_VALUE(   770.00), SIMDE_FLOAT16_VALUE(    48.91), SIMDE_FLOAT16_VALUE(  -353.25), SIMDE_FLOAT16_VALUE(   882.50),
        SIMDE_FLOAT16_VALUE(   532.00), SIMDE_FLOAT16_VALUE(  -752.00), SIMDE_FLOAT16_VALUE(  -722.00), SIMDE_FLOAT16_VALUE(  -834.50),
        SIMDE_FLOAT16_VALUE(   220.62), SIMDE_FLOAT16_VALUE(   142.88), SIMDE_FLOAT16_VALUE(   725.00), SIMDE_FLOAT16_VALUE(   896.00),
        SIMDE_FLOAT16_VALUE(   665.00), SIMDE_FLOAT16_VALUE(  -867.00), SIMDE_FLOAT16_VALUE(  -284.75), SIMDE_FLOAT16_VALUE(   326.75) },
      UINT32_C(4294967207) },
    { {            SIMDE_NANHF,            SIMDE_NANHF, SIMDE_FLOAT16_VALUE(   616.50), SIMDE_FLOAT16_VALUE(  -430.50),
        SIMDE_FLOAT16_VALUE(   248.12), SIMDE_FLOAT16_VALUE(  -761.50), SIMDE_FLOAT16_VALUE(  -880.00), SIMDE_FLOAT16_VALUE(   837.00),
        SIMDE_FLOAT16_VALUE(  -867.00), SIMDE_FLOAT16_VALUE(   317.25), SIMDE_FLOAT16_VALUE(  -807.50), SIMDE_FLOAT16_VALUE(   241.75),
        SIMDE_FLOAT16_VALUE(   823.00), SIMDE_FLOAT16_VALUE(  -682.00), SIMDE_FLOAT16_VALUE(   399.75), SIMDE_FLOAT16_VALUE(   -24.41),
        SIMDE_FLOAT16_VALUE(  -674.00), SIMDE_FLOAT16_VALUE(    89.25), SIMDE_FLOAT16_VALUE(  -623.50), SIMDE_FLOAT16_VALUE(  -388.00),
        SIMDE_FLOAT16_VALUE(   -55.75), SIMDE_FLOAT16_VALUE(    -2.46), SIMDE_FLOAT16_VALUE(  -959.00), SIMDE_FLOAT16_VALUE(  -475.50),
        SIMDE_FLOAT16_VALUE(   515.00), SIMDE_FLOAT16_VALUE(   135.12), SIMDE_FLOAT16_VALUE(  -762.50), SIMDE_FLOAT16_VALUE(  -252.12),
        SIMDE_FLOAT16_VALUE(   556.00), SIMDE_FLOAT16_VALUE(   473.75), SIMDE_FLOAT16_VALUE(  -351.50), SIMDE_FLOAT16_VALUE(   685.50) },
      { SIMDE_FLOAT16_VALUE(  -870.00),            SIMDE_NANHF,            SIMDE_NANHF, SIMDE_FLOAT16_VALUE(  -917.00),
        SIMDE_FLOAT16_VALUE(  -496.50), SIMDE_FLOAT16_VALUE(  -761.50), SIMDE_FLOAT16_VALUE(  -880.00), SIMDE_FLOAT16_VALUE(   837.00),
        SIMDE_FLOAT16_VALUE(  -867.00), SIMDE_FLOAT16_VALUE(   317.25), SIMDE_FLOAT16_VALUE(  -807.50), SIMDE_FLOAT16_VALUE(   241.75),
        SIMDE_FLOAT16_VALUE(   823.00), SIMDE_FLOAT16_VALUE(  -682.00), SIMDE_FLOAT16_VALUE(   399.75), SIMDE_FLOAT16_VALUE(   -24.41),
        SIMDE_FLOAT16_VALUE(  -674.00), SIMDE_FLOAT16_VALUE(    89.25), SIMDE_FLOAT16_VALUE(  -623.50), SIMDE_FLOAT16_VALUE(  -388.00),
        SIMDE_FLOAT16_VALUE(   -55.75), SIMDE_FLOAT16_VALUE(    -2.46), SIMDE_FLOAT16_VALUE(  -959.00), SIMDE_FLOAT16_VALUE(  -475.50),
        SIMDE_FLOAT16_VALUE(   515.00), SIMDE_FLOAT16_VALUE(   135.12), SIMDE_FLOAT16_VALUE(  -762.50), SIMDE_FLOAT16_VALUE(  -252.12),
        SIMDE_FLOAT16_VALUE(   556.00), SIMDE_FLOAT16_VALUE(   473.75), SIMDE_FLOAT16_VALUE(  -351.50), SIMDE_FLOAT16_VALUE(   685.50) },
      UINT32_C(         7) },
    { {            SIMDE_NANHF,            SIMDE_NANHF, SIMDE_FLOAT16_VALUE(   545.00), SIMDE_FLOAT16_VALUE(  -583.00),
        SIMDE_FLOAT16_VALUE(  -615.00), SIMDE_FLOAT16_VALUE(  -818.50), SIMDE_FLOAT16_VALUE(  -890.50), SIMDE_FLOAT16_VALUE(  -502.25),
        SIMDE_FLOAT16_VALUE(  -940.50), SIMDE_FLOAT16_VALUE(   625.00), SIMDE_FLOAT16_VALUE(   -71.62), SIMDE_FLOAT16_VALUE(   337.50),
        SIMDE_FLOAT16_VALUE(  -883.50), SIMDE_FLOAT16_VALUE(   685.00), SIMDE_FLOAT16_VALUE(   704.50), SIMDE_FLOAT16_VALUE(   -15.94),
        SIMDE_FLOAT16_VALUE(    53.25), SIMDE_FLOAT16_VALUE(    15.79), SIMDE_FLOAT16_VALUE(  -150.88), SIMDE_FLOAT16_VALUE(  -537.00),
        SIMDE_FLOAT16_VALUE(  -148.50), SIMDE_FLOAT16_VALUE(  -770.50), SIMDE_FLOAT16_VALUE(     7.54), SIMDE_FLOAT16_VALUE(   -75.12),
        SIMDE_FLOAT16_VALUE(  -642.50), SIMDE_FLOAT16_VALUE(   108.12), SIMDE_FLOAT16_VALUE(  -528.00), SIMDE_FLOAT16_VALUE(   133.88),
        SIMDE_FLOAT16_VALUE(  -105.62), SIMDE_FLOAT16_VALUE(  -146.00), SIMDE_FLOAT16_VALUE(  -824.50), SIMDE_FLOAT16_VALUE(   -64.19) },
      { SIMDE_FLOAT16_VALUE(   319.00),            SIMDE_NANHF,            SIMDE_NANHF, SIMDE_FLOAT16_VALUE(   704.00),
        SIMDE_FLOAT16_VALUE(   902.00), SIMDE_FLOAT16_VALUE(   462.00), SIMDE_FLOAT16_VALUE(  -890.50), SIMDE_FLOAT16_VALUE(   961.50),
        SIMDE_FLOAT16_VALUE(    87.06), SIMDE_FLOAT16_VALUE(   130.38), SIMDE_FLOAT16_VALUE(   299.00), SIMDE_FLOAT16_VALUE(   203.50),
        SIMDE_FLOAT16_VALUE(  -184.88), SIMDE_FLOAT16_VALUE(     3.52), SIMDE_FLOAT16_VALUE(  -812.50), SIMDE_FLOAT16_VALUE(   868.50),
        SIMDE_FLOAT16_VALUE(  -980.50), SIMDE_FLOAT16_VALUE(    36.78), SIMDE_FLOAT16_VALUE(  -669.00), SIMDE_FLOAT16_VALUE(  -129.12),
        SIMDE_FLOAT16_VALUE(   266.25), SIMDE_FLOAT16_VALUE(   338.75), SIMDE_FLOAT16_VALUE(   795.50), SIMDE_FLOAT16_VALUE(   623.50),
        SIMDE_FLOAT16_VALUE(  -553.00), SIMDE_FLOAT16_VALUE(  -732.50), SIMDE_FLOAT16_VALUE(  -242.50), SIMDE_FLOAT16_VALUE(   341.25),
        SIMDE_FLOAT16_VALUE(   121.62), SIMDE_FLOAT16_VALUE(   -67.12), SIMDE_FLOAT16_VALUE(  -723.00), SIMDE_FLOAT16_VALUE(  -559.50) },
      UINT32_C(2113574399) },
    { {            SIMDE_NANHF,            SIMDE_NANHF, SIMDE_FLOAT16_VALUE(  -444.75), SIMDE_FLOAT16_VALUE(    91.56),
        SIMDE_FLOAT16_VALUE(  -653.50), SIMDE_FLOAT16_VALUE(  -483.25), SIMDE_FLOAT16_VALUE(  -821.50), SIMDE_FLOAT16_VALUE(   477.00),
        SIMDE_FLOAT16_VALUE(   816.00), SIMDE_FLOAT16_VALUE(   382.25), SIMDE_FLOAT16_VALUE(  -708.00), SIMDE_FLOAT16_VALUE(  -180.62),
        SIMDE_FLOAT16_VALUE(   570.00), SIMDE_FLOAT16_VALUE(  -839.50), SIMDE_FLOAT16_VALUE(  -161.38), SIMDE_FLOAT16_VALUE(  -393.50),
        SIMDE_FLOAT16_VALUE(  -508.25), SIMDE_FLOAT16_VALUE(   709.50), SIMDE_FLOAT16_VALUE(   872.50), SIMDE_FLOAT16_VALUE(   830.50),
        SIMDE_FLOAT16_VALUE(   505.25), SIMDE_FLOAT16_VALUE(   496.25), SIMDE_FLOAT16_VALUE(  -722.50), SIMDE_FLOAT16_VALUE(   773.00),
        SIMDE_FLOAT16_VALUE(  -746.00), SIMDE_FLOAT16_VALUE(   619.00), SIMDE_FLOAT16_VALUE(  -105.44), SIMDE_FLOAT16_VALUE(   186.62),
        SIMDE_FLOAT16_VALUE(   896.00), SIMDE_FLOAT16_VALUE(   335.25), SIMDE_FLOAT16_VALUE(   840.00), SIMDE_FLOAT16_VALUE(   525.50) },
      { SIMDE_FLOAT16_VALUE(   480.00),            SIMDE_NANHF,            SIMDE_NANHF, SIMDE_FLOAT16_VALUE(   826.50),
        SIMDE_FLOAT16_VALUE(  -653.50), SIMDE_FLOAT16_VALUE(  -204.38), SIMDE_FLOAT16_VALUE(  -821.50), SIMDE_FLOAT16_VALUE(  -272.25),
        SIMDE_FLOAT16_VALUE(  -822.00), SIMDE_FLOAT16_VALUE(   595.50), SIMDE_FLOAT16_VALUE(   547.00), SIMDE_FLOAT16_VALUE(   747.50),
        SIMDE_FLOAT16_VALUE(   756.00), SIMDE_FLOAT16_VALUE(  -614.00), SIMDE_FLOAT16_VALUE(  -646.00), SIMDE_FLOAT16_VALUE(  -752.00),
        SIMDE_FLOAT16_VALUE(  -904.50), SIMDE_FLOAT16_VALUE(  -773.00), SIMDE_FLOAT16_VALUE(  -921.50), SIMDE_FLOAT16_VALUE(   600.50),
        SIMDE_FLOAT16_VALUE(   723.00), SIMDE_FLOAT16_VALUE(  -644.00), SIMDE_FLOAT16_VALUE(   373.25), SIMDE_FLOAT16_VALUE(   977.00),
        SIMDE_FLOAT16_VALUE(   975.00), SIMDE_FLOAT16_VALUE(  -732.00), SIMDE_FLOAT16_VALUE(   163.50), SIMDE_FLOAT16_VALUE(   870.50),
        SIMDE_FLOAT16_VALUE(   603.00), SIMDE_FLOAT16_VALUE(     3.54), SIMDE_FLOAT16_VALUE(   396.00), SIMDE_FLOAT16_VALUE(    82.94) },
      UINT32_C(         0) },
    { {            SIMDE_NANHF,            SIMDE_NANHF, SIMDE_FLOAT16_VALUE(  -689.00), SIMDE_FLOAT16_VALUE(  -191.25),
        SIMDE_FLOAT16_VALUE(  -787.00), SIMDE_FLOAT16_VALUE(    38.69), SIMDE_FLOAT16_VALUE(   -13.35), SIMDE_FLOAT16_VALUE(   808.50),
        SIMDE_FLOAT16_VALUE(  -414.25), SIMDE_FLOAT16_VALUE(  -265.75), SIMDE_FLOAT16_VALUE(   565.00), SIMDE_FLOAT16_VALUE(   -28.34),
        SIMDE_FLOAT16_VALUE(    88.44), SIMDE_FLOAT16_VALUE(   813.00), SIMDE_FLOAT16_VALUE(    66.94), SIMDE_FLOAT16_VALUE(   315.25),
        SIMDE_FLOAT16_VALUE(   891.50), SIMDE_FLOAT16_VALUE(  -332.50), SIMDE_FLOAT16_VALUE(    38.41), SIMDE_FLOAT16_VALUE(  -752.50),
        SIMDE_FLOAT16_VALUE(  -959.00), SIMDE_FLOAT16_VALUE(    15.27), SIMDE_FLOAT16_VALUE(  -777.50), SIMDE_FLOAT16_VALUE(  -691.50),
        SIMDE_FLOAT16_VALUE(  -821.00), SIMDE_FLOAT16_VALUE(  -907.00), SIMDE_FLOAT16_VALUE(   912.00), SIMDE_FLOAT16_VALUE(   182.38),
        SIMDE_FLOAT16_VALUE(   489.00), SIMDE_FLOAT16_VALUE(    -5.32), SIMDE_FLOAT16_VALUE(  -418.75), SIMDE_FLOAT16_VALUE(   502.25) },
      { SIMDE_FLOAT16_VALUE(   904.00),            SIMDE_NANHF,            SIMDE_NANHF, SIMDE_FLOAT16_VALUE(  -191.25),
        SIMDE_FLOAT16_VALUE(   930.50), SIMDE_FLOAT16_VALUE(    38.69), SIMDE_FLOAT16_VALUE(   926.00), SIMDE_FLOAT16_VALUE(  -483.50),
        SIMDE_FLOAT16_VALUE(  -968.00), SIMDE_FLOAT16_VALUE(   490.75), SIMDE_FLOAT16_VALUE(   488.25), SIMDE_FLOAT16_VALUE(   120.44),
        SIMDE_FLOAT16_VALUE(   303.75), SIMDE_FLOAT16_VALUE(  -445.00), SIMDE_FLOAT16_VALUE(  -564.50), SIMDE_FLOAT16_VALUE(   195.25),
        SIMDE_FLOAT16_VALUE(   222.50), SIMDE_FLOAT16_VALUE(   474.00), SIMDE_FLOAT16_VALUE(   442.75), SIMDE_FLOAT16_VALUE(   263.25),
        SIMDE_FLOAT16_VALUE(  -510.50), SIMDE_FLOAT16_VALUE(   665.00), SIMDE_FLOAT16_VALUE(   572.00), SIMDE_FLOAT16_VALUE(  -331.75),
        SIMDE_FLOAT16_VALUE(   758.00), SIMDE_FLOAT16_VALUE(   483.75), SIMDE_FLOAT16_VALUE(   850.50), SIMDE_FLOAT16_VALUE(   247.12),
        SIMDE_FLOAT16_VALUE(  -521.50), SIMDE_FLOAT16_VALUE(  -568.50), SIMDE_FLOAT16_VALUE(  -250.50), SIMDE_FLOAT16_VALUE(  -617.50) },
      UINT32_C(4294967248) },
    { {            SIMDE_NANHF,            SIMDE_NANHF, SIMDE_FLOAT16_VALUE(   254.38), SIMDE_FLOAT16_VALUE(  -641.50),
        SIMDE_FLOAT16_VALUE(  -574.50), SIMDE_FLOAT16_VALUE(   771.00), SIMDE_FLOAT16_VALUE(  -609.50), SIMDE_FLOAT16_VALUE(   916.50),
        SIMDE_FLOAT16_VALUE(   259.00), SIMDE_FLOAT16_VALUE(   510.75), SIMDE_FLOAT16_VALUE(   220.25), SIMDE_FLOAT16_VALUE(   814.00),
        SIMDE_FLOAT16_VALUE(   946.50), SIMDE_FLOAT16_VALUE(  -584.50), SIMDE_FLOAT16_VALUE(    36.62), SIMDE_FLOAT16_VALUE(   420.50),
        SIMDE_FLOAT16_VALUE(   858.00), SIMDE_FLOAT16_VALUE(  -700.00), SIMDE_FLOAT16_VALUE(   910.00), SIMDE_FLOAT16_VALUE(   523.00),
        SIMDE_FLOAT16_VALUE(   872.00), SIMDE_FLOAT16_VALUE(  -422.00), SIMDE_FLOAT16_VALUE(   281.25), SIMDE_FLOAT16_VALUE(   355.50),
        SIMDE_FLOAT16_VALUE(  -571.50), SIMDE_FLOAT16_VALUE(  -471.50), SIMDE_FLOAT16_VALUE(   834.00), SIMDE_FLOAT16_VALUE(  -139.62),
        SIMDE_FLOAT16_VALUE(   277.75), SIMDE_FLOAT16_VALUE(  -783.50), SIMDE_FLOAT16_VALUE(  -816.00), SIMDE_FLOAT16_VALUE(  -661.50) },
      { SIMDE_FLOAT16_VALUE(    60.53),            SIMDE_NANHF,            SIMDE_NANHF, SIMDE_FLOAT16_VALUE(  -641.50),
        SIMDE_FLOAT16_VALUE(   209.12), SIMDE_FLOAT16_VALUE(   771.00), SIMDE_FLOAT16_VALUE(    58.47), SIMDE_FLOAT16_VALUE(   916.50),
        SIMDE_FLOAT16_VALUE(   259.00), SIMDE_FLOAT16_VALUE(   510.75), SIMDE_FLOAT16_VALUE(   220.25), SIMDE_FLOAT16_VALUE(   814.00),
        SIMDE_FLOAT16_VALUE(   946.50), SIMDE_FLOAT16_VALUE(  -584.50), SIMDE_FLOAT16_VALUE(    36.62), SIMDE_FLOAT16_VALUE(   420.50),
        SIMDE_FLOAT16_VALUE(   858.00), SIMDE_FLOAT16_VALUE(  -700.00), SIMDE_FLOAT16_VALUE(   910.00), SIMDE_FLOAT16_VALUE(   523.00),
        SIMDE_FLOAT16_VALUE(   872.00), SIMDE_FLOAT16_VALUE(  -422.00), SIMDE_FLOAT16_VALUE(   281.25), SIMDE_FLOAT16_VALUE(   355.50),
        SIMDE_FLOAT16_VALUE(  -571.50), SIMDE_FLOAT16_VALUE(  -471.50), SIMDE_FLOAT16_VALUE(   834.00), SIMDE_FLOAT16_VALUE(  -139.62),
        SIMDE_FLOAT16_VALUE(   277.75), SIMDE_FLOAT16_VALUE(  -783.50), SIMDE_FLOAT16_VALUE(  -816.00), SIMDE_FLOAT16_VALUE(  -661.50) },
      UINT32_C(4294967208) },
    { {            SIMDE_NANHF,            SIMDE_NANHF, SIMDE_FLOAT16_VALUE(  -427.00), SIMDE_FLOAT16_VALUE(   284.75),
        SIMDE_FLOAT16_VALUE(   814.00), SIMDE_FLOAT16_VALUE(    41.06), SIMDE_FLOAT16_VALUE(   882.50), SIMDE_FLOAT16_VALUE(  -907.50),
        SIMDE_FLOAT16_VALUE(   323.25), SIMDE_FLOAT16_VALUE(  -573.50), SIMDE_FLOAT16_VALUE(  -213.50), SIMDE_FLOAT16_VALUE(  -357.75),
        SIMDE_FLOAT16_VALUE(  -609.00), SIMDE_FLOAT16_VALUE(   338.75), SIMDE_FLOAT16_VALUE(  -739.00), SIMDE_FLOAT16_VALUE(  -735.00),
        SIMDE_FLOAT16_VALUE(   414.00), SIMDE_FLOAT16_VALUE(   752.00), SIMDE_FLOAT16_VALUE(  -282.25), SIMDE_FLOAT16_VALUE(  -229.38),
        SIMDE_FLOAT16_VALUE(  -401.75), SIMDE_FLOAT16_VALUE(   599.00), SIMDE_FLOAT16_VALUE(  -344.50), SIMDE_FLOAT16_VALUE(   278.50),
        SIMDE_FLOAT16_VALUE(   340.25), SIMDE_FLOAT16_VALUE(   818.50), SIMDE_FLOAT16_VALUE(  -824.50), SIMDE_FLOAT16_VALUE(   265.75),
        SIMDE_FLOAT16_VALUE(   319.50), SIMDE_FLOAT16_VALUE(   789.00), SIMDE_FLOAT16_VALUE(  -370.50), SIMDE_FLOAT16_VALUE(   517.50) },
      { SIMDE_FLOAT16_VALUE(  -802.00),            SIMDE_NANHF,            SIMDE_NANHF, SIMDE_FLOAT16_VALUE(  -642.00),
        SIMDE_FLOAT16_VALUE(   814.00), SIMDE_FLOAT16_VALUE(    41.06), SIMDE_FLOAT16_VALUE(   882.50), SIMDE_FLOAT16_VALUE(   567.00),
        SIMDE_FLOAT16_VALUE(   110.56), SIMDE_FLOAT16_VALUE(   237.12), SIMDE_FLOAT16_VALUE(  -791.00), SIMDE_FLOAT16_VALUE(   501.25),
        SIMDE_FLOAT16_VALUE(  -424.25), SIMDE_FLOAT16_VALUE(  -530.00), SIMDE_FLOAT16_VALUE(   766.50), SIMDE_FLOAT16_VALUE(   990.00),
        SIMDE_FLOAT16_VALUE(  -778.00), SIMDE_FLOAT16_VALUE(  -516.00), SIMDE_FLOAT16_VALUE(  -239.62), SIMDE_FLOAT16_VALUE(  -179.75),
        SIMDE_FLOAT16_VALUE(  -917.00), SIMDE_FLOAT16_VALUE(   416.00), SIMDE_FLOAT16_VALUE(  -901.00), SIMDE_FLOAT16_VALUE(   423.25),
        SIMDE_FLOAT16_VALUE(   234.25), SIMDE_FLOAT16_VALUE(  -725.50), SIMDE_FLOAT16_VALUE(  -311.00), SIMDE_FLOAT16_VALUE(  -446.25),
        SIMDE_FLOAT16_VALUE(  -936.50), SIMDE_FLOAT16_VALUE(   318.25), SIMDE_FLOAT16_VALUE(  -929.00), SIMDE_FLOAT16_VALUE(  -392.25) },
      UINT32_C(4218627336) },
    { {            SIMDE_NANHF,            SIMDE_NANHF, SIMDE_FLOAT16_VALUE(  -235.88), SIMDE_FLOAT16_VALUE(   557.50),
        SIMDE_FLOAT16_VALUE(   416.25), SIMDE_FLOAT16_VALUE(  -669.00), SIMDE_FLOAT16_VALUE(  -332.00), SIMDE_FLOAT16_VALUE(  -346.50),
        SIMDE_FLOAT16_VALUE(  -460.00), SIMDE_FLOAT16_VALUE(  -830.50), SIMDE_FLOAT16_VALUE(   229.12), SIMDE_FLOAT16_VALUE(    10.01),
        SIMDE_FLOAT16_VALUE(   936.00), SIMDE_FLOAT16_VALUE(   218.88), SIMDE_FLOAT16_VALUE(   232.00), SIMDE_FLOAT16_VALUE(  -580.00),
        SIMDE_FLOAT16_VALUE(   979.50), SIMDE_FLOAT16_VALUE(  -948.00), SIMDE_FLOAT16_VALUE(  -497.00), SIMDE_FLOAT16_VALUE(   395.25),
        SIMDE_FLOAT16_VALUE(  -849.00), SIMDE_FLOAT16_VALUE(   926.00), SIMDE_FLOAT16_VALUE(  -370.50), SIMDE_FLOAT16_VALUE(  -574.50),
        SIMDE_FLOAT16_VALUE(  -385.00), SIMDE_FLOAT16_VALUE(   183.38), SIMDE_FLOAT16_VALUE(  -511.25), SIMDE_FLOAT16_VALUE(   933.50),
        SIMDE_FLOAT16_VALUE(   254.50), SIMDE_FLOAT16_VALUE(    96.50), SIMDE_FLOAT16_VALUE(  -546.00), SIMDE_FLOAT16_VALUE(  -872.50) },
      { SIMDE_FLOAT16_VALUE(  -126.88),            SIMDE_NANHF,            SIMDE_NANHF, SIMDE_FLOAT16_VALUE(   478.50),
        SIMDE_FLOAT16_VALUE(   416.25), SIMDE_FLOAT16_VALUE(  -647.00), SIMDE_FLOAT16_VALUE(  -868.00), SIMDE_FLOAT16_VALUE(  -346.50),
        SIMDE_FLOAT16_VALUE(  -460.00), SIMDE_FLOAT16_VALUE(  -830.50), SIMDE_FLOAT16_VALUE(   229.12), SIMDE_FLOAT16_VALUE(    10.01),
        SIMDE_FLOAT16_VALUE(   936.00), SIMDE_FLOAT16_VALUE(   218.88), SIMDE_FLOAT16_VALUE(   232.00), SIMDE_FLOAT16_VALUE(  -580.00),
        SIMDE_FLOAT16_VALUE(   979.50), SIMDE_FLOAT16_VALUE(  -948.00), SIMDE_FLOAT16_VALUE(  -497.00), SIMDE_FLOAT16_VALUE(   395.25),
        SIMDE_FLOAT16_VALUE(  -849.00), SIMDE_FLOAT16_VALUE(   926.00), SIMDE_FLOAT16_VALUE(  -370.50), SIMDE_FLOAT16_VALUE(  -574.50),
        SIMDE_FLOAT16_VALUE(  -385.00), SIMDE_FLOAT16_VALUE(   183.38), SIMDE_FLOAT16_VALUE(  -511.25), SIMDE_FLOAT16_VALUE(   933.50),
        SIMDE_FLOAT16_VALUE(   254.50), SIMDE_FLOAT16_VALUE(    96.50), SIMDE_FLOAT16_VALUE(  -546.00), SIMDE_FLOAT16_VALUE(  -872.50) },
                UINT32_MAX }
  };

  simde__m512h a, b;
  simde__mmask32 r;

  a = simde_mm512_loadu_ph(test_vec[0].a);
  b = simde_mm512_loadu_ph(test_vec[0].b);
  r = simde_mm512_cmp_ph_mask(a, b, SIMDE_CMP_EQ_OQ);
  simde_assert_equal_mmask32(r, test_vec[0].r);

  a = simde_mm512_loadu_ph(test_vec[1].a);
  b = simde_mm512_loadu_ph(test_vec[1].b);
  r = simde_mm512_cmp_ph_mask(a, b, SIMDE_CMP_LT_OS);
  simde_assert_equal_mmask32(r, test_vec[1].r);

  a = simde_mm512_loadu_ph(test_vec[2].a);
  b = simde_mm512_loadu_ph(test_vec[2].b);
  r = simde_mm512_cmp_ph_mask(a, b, SIMDE_CMP_LE_OS);
  simde_assert_equal_mmask32(r, test_vec[2].r);

  a = simde_mm512_loadu_ph(test_vec[3].a);
  b = simde_mm512_loadu_ph(test_vec[3].b);
  r = simde_mm512_cmp_ph_mask(a, b, SIMDE_CMP_UNORD_Q);
  simde_assert_equal_mmask32(r, test_vec[3].r);

  a = simde_mm512_loadu_ph(test_vec[4].a);
  b = simde_mm512_loadu_ph(test_vec[4].b);
  r = simde_mm512_cmp_ph_mask(a, b, SIMDE_CMP_NEQ_UQ);
  simde_assert_equal_mmask32(r, test_vec[4].r);

  a = simde_mm512_loadu_ph(test_vec[5].a);
  b = simde_mm512_loadu_ph(test_vec[5].b);
  r = simde_mm512_cmp_ph_mask(a, b, SIMDE_CMP_NLT_US);
  simde_assert_equal_mmask32(r, test_vec[5].r);

  a = simde_mm512_loadu_ph(test_vec[6].a);
  b = simde_mm512_loadu_ph(test_vec[6].b);
  r = simde_mm512_cmp_ph_mask(a, b, SIMDE_CMP_NLE_US);
  simde_assert_equal_mmask32(r, test_vec[6].r);

  a = simde_mm512_loadu_ph(test_vec[7].a);
  b = simde_mm512_loadu_ph(test_vec[7].b);
  r = simde_mm512_cmp_ph_mask(a, b, SIMDE_CMP_ORD_Q);
  simde_assert_equal_mmask32(r, test_vec[7].r);

  a = simde_mm512_loadu_ph(test_vec[8].a);
  b = simde_mm512_loadu_ph(test_vec[8].b);
  r = simde_mm512_cmp_ph_mask(a, b, SIMDE_CMP_EQ_UQ);
  simde_assert_equal_mmask32(r, test_vec[8].r);

  a = simde_mm512_loadu_ph(test_vec[9].a);
  b = simde_mm512_loadu_ph(test_vec[9].b);
  r = simde_mm512_cmp_ph_mask(a, b, SIMDE_CMP_NGE_US);
  simde_assert_equal_mmask32(r, test_vec[9].r);

  a = simde_mm512_loadu_ph(test_vec[10].a);
  b = simde_mm512_loadu_ph(test_vec[10].b);
  r = simde_mm512_cmp_ph_mask(a, b, SIMDE_CMP_NGT_US);
  simde_assert_equal_mmask32(r, test_vec[10].r);

  a = simde_mm512_loadu_ph(test_vec[11].a);
  b = simde_mm512_loadu_ph(test_vec[11].b);
  r = simde_mm512_cmp_ph_mask(a, b, SIMDE_CMP_FALSE_OQ);
  simde_assert_equal_mmask32(r, test_vec[11].r);

  a = simde_mm512_loadu_ph(test_vec[12].a);
  b = simde_mm512_loadu_ph(test_vec[12].b);
  r = simde_mm512_cmp_ph_mask(a, b, SIMDE_CMP_NEQ_OQ);
  simde_assert_equal_mmask32(r, test_vec[12].r);

  a = simde_mm512_loadu_ph(test_vec[13].a);
  b = simde_mm512_loadu_ph(test_vec[13].b);
  r = simde_mm512_cmp_ph_mask(a, b, SIMDE_CMP_GE_OS);
  simde_assert_equal_mmask32(r, test_vec[13].r);

  a = simde_mm512_loadu_ph(test_vec[14].a);
  b = simde_mm512_loadu_ph(test_vec[14].b);
  r = simde_mm512_cmp_ph_mask(a, b, SIMDE_CMP_GT_OS);
  simde_assert_equal_mmask32(r, test_vec[14].r);

  a = simde_mm512_loadu_ph(test_vec[15].a);
  b = simde_mm512_loadu_ph(test_vec[15].b);
  r = simde_mm512_cmp_ph_mask(a, b, SIMDE_CMP_TRUE_UQ);
  simde_assert_equal_mmask32(r, test_vec[15].r);

  a = simde_mm512_loadu_ph(test_vec[16].a);
  b = simde_mm512_loadu_ph(test_vec[16].b);
  r = simde_mm512_cmp_ph_mask(a, b, SIMDE_CMP_EQ_OS);
  simde_assert_equal_mmask32(r, test_vec[16].r);

  a = simde_mm512_loadu_ph(test_vec[17].a);
  b = simde_mm512_loadu_ph(test_vec[17].b);
  r = simde_mm512_cmp_ph_mask(a, b, SIMDE_CMP_LT_OQ);
  simde_assert_equal_mmask32(r, test_vec[17].r);

  a = simde_mm512_loadu_ph(test_vec[18].a);
  b = simde_mm512_loadu_ph(test_vec[18].b);
  r = simde_mm512_cmp_ph_mask(a, b, SIMDE_CMP_LE_OQ);
  simde_assert_equal_mmask32(r, test_vec[18].r);

  a = simde_mm512_loadu_ph(test_vec[19].a);
  b = simde_mm512_loadu_ph(test_vec[19].b);
  r = simde_mm512_cmp_ph_mask(a, b, SIMDE_CMP_UNORD_S);
  simde_assert_equal_mmask32(r, test_vec[19].r);

  a = simde_mm512_loadu_ph(test_vec[20].a);
  b = simde_mm512_loadu_ph(test_vec[20].b);
  r = simde_mm512_cmp_ph_mask(a, b, SIMDE_CMP_NEQ_US);
  simde_assert_equal_mmask32(r, test_vec[20].r);

  a = simde_mm512_loadu_ph(test_vec[21].a);
  b = simde_mm512_loadu_ph(test_vec[21].b);
  r = simde_mm512_cmp_ph_mask(a, b, SIMDE_CMP_NLT_UQ);
  simde_assert_equal_mmask32(r, test_vec[21].r);

  a = simde_mm512_loadu_ph(test_vec[22].a);
  b = simde_mm512_loadu_ph(test_vec[22].b);
  r = simde_mm512_cmp_ph_mask(a, b, SIMDE_CMP_NLE_UQ);
  simde_assert_equal_mmask32(r, test_vec[22].r);

  a = simde_mm512_loadu_ph(test_vec[23].a);
  b = simde_mm512_loadu_ph(test_vec[23].b);
  r = simde_mm512_cmp_ph_mask(a, b, SIMDE_CMP_ORD_S);
  simde_assert_equal_mmask32(r, test_vec[23].r);

  a = simde_mm512_loadu_ph(test_vec[24].a);
  b = simde_mm512_loadu_ph(test_vec[24].b);
  r = simde_mm512_cmp_ph_mask(a, b, SIMDE_CMP_EQ_US);
  simde_assert_equal_mmask32(r, test_vec[24].r);

  a = simde_mm512_loadu_ph(test_vec[25].a);
  b = simde_mm512_loadu_ph(test_vec[25].b);
  r = simde_mm512_cmp_ph_mask(a, b, SIMDE_CMP_NGE_UQ);
  simde_assert_equal_mmask32(r, test_vec[25].r);

  a = simde_mm512_loadu_ph(test_vec[26].a);
  b = simde_mm512_loadu_ph(test_vec[26].b);
  r = simde_mm512_cmp_ph_mask(a, b, SIMDE_CMP_NGT_UQ);
  simde_assert_equal_mmask32(r, test_vec[26].r);

  a = simde_mm512_loadu_ph(test_vec[27].a);
  b = simde_mm512_loadu_ph(test_vec[27].b);
  r = simde_mm512_cmp_ph_mask(a, b, SIMDE_CMP_FALSE_OS);
  simde_assert_equal_mmask32(r, test_vec[27].r);

  a = simde_mm512_loadu_ph(test_vec[28].a);
  b = simde_mm512_loadu_ph(test_vec[28].b);
  r = simde_mm512_cmp_ph_mask(a, b, SIMDE_CMP_NEQ_OS);
  simde_assert_equal_mmask32(r, test_vec[28].r);

  a = simde_mm512_loadu_ph(test_vec[29].a);
  b = simde_mm512_loadu_ph(test_vec[29].b);
  r = simde_mm512_cmp_ph_mask(a, b, SIMDE_CMP_GE_OQ);
  simde_assert_equal_mmask32(r, test_vec[29].r);

  a = simde_mm512_loadu_ph(test_vec[30].a);
  b = simde_mm512_loadu_ph(test_vec[30].b);
  r = simde_mm512_cmp_ph_mask(a, b, SIMDE_CMP_GT_OQ);
  simde_assert_equal_mmask32(r, test_vec[30].r);

  a = simde_mm512_loadu_ph(test_vec[31].a);
  b = simde_mm512_loadu_ph(test_vec[31].b);
  r = simde_mm512_cmp_ph_mask(a, b, SIMDE_CMP_TRUE_US);
  simde_assert_equal_mmask32(r, test_vec[31].r);

  return 0;
#else
  fputc('\n', stdout);

  const simde__m512h nanv = simde_mm512_set1_ph(SIMDE_NANHF);

  simde__m512h a, b;
  simde__mmask32 r;

  a = simde_test_x86_random_f16x32(SIMDE_FLOAT16_VALUE(-1000.0), SIMDE_FLOAT16_VALUE(1000.0));
  b = simde_test_x86_random_f16x32(SIMDE_FLOAT16_VALUE(-1000.0), SIMDE_FLOAT16_VALUE(1000.0));
  b = simde_x_mm512_mask_mov_ph(a, HEDLEY_STATIC_CAST(simde__mmask32, simde_test_codegen_random_i8()), b);
  a = simde_x_mm512_mask_mov_ph(a, HEDLEY_STATIC_CAST(simde__mmask32, 3), nanv);
  b = simde_x_mm512_mask_mov_ph(b, HEDLEY_STATIC_CAST(simde__mmask32, 6), nanv);
  r = simde_mm512_cmp_ph_mask(a, b, SIMDE_CMP_EQ_OQ);
  simde_test_x86_write_f16x32(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_f16x32(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask32(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_f16x32(SIMDE_FLOAT16_VALUE(-1000.0), SIMDE_FLOAT16_VALUE(1000.0));
  b = simde_test_x86_random_f16x32(SIMDE_FLOAT16_VALUE(-1000.0), SIMDE_FLOAT16_VALUE(1000.0));
  b = simde_x_mm512_mask_mov_ph(a, HEDLEY_STATIC_CAST(simde__mmask32, simde_test_codegen_random_i8()), b);
  a = simde_x_mm512_mask_mov_ph(a, HEDLEY_STATIC_CAST(simde__mmask32, 3), nanv);
  b = simde_x_mm512_mask_mov_ph(b, HEDLEY_STATIC_CAST(simde__mmask32, 6), nanv);
  r = simde_mm512_cmp_ph_mask(a, b, SIMDE_CMP_LT_OS);
  simde_test_x86_write_f16x32(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_f16x32(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask32(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_f16x32(SIMDE_FLOAT16_VALUE(-1000.0), SIMDE_FLOAT16_VALUE(1000.0));
  b = simde_test_x86_random_f16x32(SIMDE_FLOAT16_VALUE(-1000.0), SIMDE_FLOAT16_VALUE(1000.0));
  b = simde_x_mm512_mask_mov_ph(a, HEDLEY_STATIC_CAST(simde__mmask32, simde_test_codegen_random_i8()), b);
  a = simde_x_mm512_mask_mov_ph(a, HEDLEY_STATIC_CAST(simde__mmask32, 3), nanv);
  b = simde_x_mm512_mask_mov_ph(b, HEDLEY_STATIC_CAST(simde__mmask32, 6), nanv);
  r = simde_mm512_cmp_ph_mask(a, b, SIMDE_CMP_LE_OS);
  simde_test_x86_write_f16x32(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_f16x32(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask32(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_f16x32(SIMDE_FLOAT16_VALUE(-1000.0), SIMDE_FLOAT16_VALUE(1000.0));
  b = simde_test_x86_random_f16x32(SIMDE_FLOAT16_VALUE(-1000.0), SIMDE_FLOAT16_VALUE(1000.0));
  b = simde_x_mm512_mask_mov_ph(a, HEDLEY_STATIC_CAST(simde__mmask32, simde_test_codegen_random_i8()), b);
  a = simde_x_mm512_mask_mov_ph(a, HEDLEY_STATIC_CAST(simde__mmask32, 3), nanv);
  b = simde_x_mm512_mask_mov_ph(b, HEDLEY_STATIC_CAST(simde__mmask32, 6), nanv);
  r = simde_mm512_cmp_ph_mask(a, b, SIMDE_CMP_UNORD_Q);
  simde_test_x86_write_f16x32(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_f16x32(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask32(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_f16x32(SIMDE_FLOAT16_VALUE(-1000.0), SIMDE_FLOAT16_VALUE(1000.0));
  b = simde_test_x86_random_f16x32(SIMDE_FLOAT16_VALUE(-1000.0), SIMDE_FLOAT16_VALUE(1000.0));
  b = simde_x_mm512_mask_mov_ph(a, HEDLEY_STATIC_CAST(simde__mmask32, simde_test_codegen_random_i8()), b);
  a = simde_x_mm512_mask_mov_ph(a, HEDLEY_STATIC_CAST(simde__mmask32, 3), nanv);
  b = simde_x_mm512_mask_mov_ph(b, HEDLEY_STATIC_CAST(simde__mmask32, 6), nanv);
  r = simde_mm512_cmp_ph_mask(a, b, SIMDE_CMP_NEQ_UQ);
  simde_test_x86_write_f16x32(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_f16x32(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask32(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_f16x32(SIMDE_FLOAT16_VALUE(-1000.0), SIMDE_FLOAT16_VALUE(1000.0));
  b = simde_test_x86_random_f16x32(SIMDE_FLOAT16_VALUE(-1000.0), SIMDE_FLOAT16_VALUE(1000.0));
  b = simde_x_mm512_mask_mov_ph(a, HEDLEY_STATIC_CAST(simde__mmask32, simde_test_codegen_random_i8()), b);
  a = simde_x_mm512_mask_mov_ph(a, HEDLEY_STATIC_CAST(simde__mmask32, 3), nanv);
  b = simde_x_mm512_mask_mov_ph(b, HEDLEY_STATIC_CAST(simde__mmask32, 6), nanv);
  r = simde_mm512_cmp_ph_mask(a, b, SIMDE_CMP_NLT_US);
  simde_test_x86_write_f16x32(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_f16x32(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask32(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_f16x32(SIMDE_FLOAT16_VALUE(-1000.0), SIMDE_FLOAT16_VALUE(1000.0));
  b = simde_test_x86_random_f16x32(SIMDE_FLOAT16_VALUE(-1000.0), SIMDE_FLOAT16_VALUE(1000.0));
  b = simde_x_mm512_mask_mov_ph(a, HEDLEY_STATIC_CAST(simde__mmask32, simde_test_codegen_random_i8()), b);
  a = simde_x_mm512_mask_mov_ph(a, HEDLEY_STATIC_CAST(simde__mmask32, 3), nanv);
  b = simde_x_mm512_mask_mov_ph(b, HEDLEY_STATIC_CAST(simde__mmask32, 6), nanv);
  r = simde_mm512_cmp_ph_mask(a, b, SIMDE_CMP_NLE_US);
  simde_test_x86_write_f16x32(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_f16x32(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask32(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_f16x32(SIMDE_FLOAT16_VALUE(-1000.0), SIMDE_FLOAT16_VALUE(1000.0));
  b = simde_test_x86_random_f16x32(SIMDE_FLOAT16_VALUE(-1000.0), SIMDE_FLOAT16_VALUE(1000.0));
  b = simde_x_mm512_mask_mov_ph(a, HEDLEY_STATIC_CAST(simde__mmask32, simde_test_codegen_random_i8()), b);
  a = simde_x_mm512_mask_mov_ph(a, HEDLEY_STATIC_CAST(simde__mmask32, 3), nanv);
  b = simde_x_mm512_mask_mov_ph(b, HEDLEY_STATIC_CAST(simde__mmask32, 6), nanv);
  r = simde_mm512_cmp_ph_mask(a, b, SIMDE_CMP_ORD_Q);
  simde_test_x86_write_f16x32(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_f16x32(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask32(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_f16x32(SIMDE_FLOAT16_VALUE(-1000.0), SIMDE_FLOAT16_VALUE(1000.0));
  b = simde_test_x86_random_f16x32(SIMDE_FLOAT16_VALUE(-1000.0), SIMDE_FLOAT16_VALUE(1000.0));
  b = simde_x_mm512_mask_mov_ph(a, HEDLEY_STATIC_CAST(simde__mmask32, simde_test_codegen_random_i8()), b);
  a = simde_x_mm512_mask_mov_ph(a, HEDLEY_STATIC_CAST(simde__mmask32, 3), nanv);
  b = simde_x_mm512_mask_mov_ph(b, HEDLEY_STATIC_CAST(simde__mmask32, 6), nanv);
  r = simde_mm512_cmp_ph_mask(a, b, SIMDE_CMP_EQ_UQ);
  simde_test_x86_write_f16x32(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_f16x32(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask32(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_f16x32(SIMDE_FLOAT16_VALUE(-1000.0), SIMDE_FLOAT16_VALUE(1000.0));
  b = simde_test_x86_random_f16x32(SIMDE_FLOAT16_VALUE(-1000.0), SIMDE_FLOAT16_VALUE(1000.0));
  b = simde_x_mm512_mask_mov_ph(a, HEDLEY_STATIC_CAST(simde__mmask32, simde_test_codegen_random_i8()), b);
  a = simde_x_mm512_mask_mov_ph(a, HEDLEY_STATIC_CAST(simde__mmask32, 3), nanv);
  b = simde_x_mm512_mask_mov_ph(b, HEDLEY_STATIC_CAST(simde__mmask32, 6), nanv);
  r = simde_mm512_cmp_ph_mask(a, b, SIMDE_CMP_NGE_US);
  simde_test_x86_write_f16x32(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_f16x32(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask32(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_f16x32(SIMDE_FLOAT16_VALUE(-1000.0), SIMDE_FLOAT16_VALUE(1000.0));
  b = simde_test_x86_random_f16x32(SIMDE_FLOAT16_VALUE(-1000.0), SIMDE_FLOAT16_VALUE(1000.0));
  b = simde_x_mm512_mask_mov_ph(a, HEDLEY_STATIC_CAST(simde__mmask32, simde_test_codegen_random_i8()), b);
  a = simde_x_mm512_mask_mov_ph(a, HEDLEY_STATIC_CAST(simde__mmask32, 3), nanv);
  b = simde_x_mm512_mask_mov_ph(b, HEDLEY_STATIC_CAST(simde__mmask32, 6), nanv);
  r = simde_mm512_cmp_ph_mask(a, b, SIMDE_CMP_NGT_US);
  simde_test_x86_write_f16x32(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_f16x32(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask32(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_f16x32(SIMDE_FLOAT16_VALUE(-1000.0), SIMDE_FLOAT16_VALUE(1000.0));
  b = simde_test_x86_random_f16x32(SIMDE_FLOAT16_VALUE(-1000.0), SIMDE_FLOAT16_VALUE(1000.0));
  b = simde_x_mm512_mask_mov_ph(a, HEDLEY_STATIC_CAST(simde__mmask32, simde_test_codegen_random_i8()), b);
  a = simde_x_mm512_mask_mov_ph(a, HEDLEY_STATIC_CAST(simde__mmask32, 3), nanv);
  b = simde_x_mm512_mask_mov_ph(b, HEDLEY_STATIC_CAST(simde__mmask32, 6), nanv);
  r = simde_mm512_cmp_ph_mask(a, b, SIMDE_CMP_FALSE_OQ);
  simde_test_x86_write_f16x32(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_f16x32(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask32(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_f16x32(SIMDE_FLOAT16_VALUE(-1000.0), SIMDE_FLOAT16_VALUE(1000.0));
  b = simde_test_x86_random_f16x32(SIMDE_FLOAT16_VALUE(-1000.0), SIMDE_FLOAT16_VALUE(1000.0));
  b = simde_x_mm512_mask_mov_ph(a, HEDLEY_STATIC_CAST(simde__mmask32, simde_test_codegen_random_i8()), b);
  a = simde_x_mm512_mask_mov_ph(a, HEDLEY_STATIC_CAST(simde__mmask32, 3), nanv);
  b = simde_x_mm512_mask_mov_ph(b, HEDLEY_STATIC_CAST(simde__mmask32, 6), nanv);
  r = simde_mm512_cmp_ph_mask(a, b, SIMDE_CMP_NEQ_OQ);
  simde_test_x86_write_f16x32(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_f16x32(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask32(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_f16x32(SIMDE_FLOAT16_VALUE(-1000.0), SIMDE_FLOAT16_VALUE(1000.0));
  b = simde_test_x86_random_f16x32(SIMDE_FLOAT16_VALUE(-1000.0), SIMDE_FLOAT16_VALUE(1000.0));
  b = simde_x_mm512_mask_mov_ph(a, HEDLEY_STATIC_CAST(simde__mmask32, simde_test_codegen_random_i8()), b);
  a = simde_x_mm512_mask_mov_ph(a, HEDLEY_STATIC_CAST(simde__mmask32, 3), nanv);
  b = simde_x_mm512_mask_mov_ph(b, HEDLEY_STATIC_CAST(simde__mmask32, 6), nanv);
  r = simde_mm512_cmp_ph_mask(a, b, SIMDE_CMP_GE_OS);
  simde_test_x86_write_f16x32(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_f16x32(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask32(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_f16x32(SIMDE_FLOAT16_VALUE(-1000.0), SIMDE_FLOAT16_VALUE(1000.0));
  b = simde_test_x86_random_f16x32(SIMDE_FLOAT16_VALUE(-1000.0), SIMDE_FLOAT16_VALUE(1000.0));
  b = simde_x_mm512_mask_mov_ph(a, HEDLEY_STATIC_CAST(simde__mmask32, simde_test_codegen_random_i8()), b);
  a = simde_x_mm512_mask_mov_ph(a, HEDLEY_STATIC_CAST(simde__mmask32, 3), nanv);
  b = simde_x_mm512_mask_mov_ph(b, HEDLEY_STATIC_CAST(simde__mmask32, 6), nanv);
  r = simde_mm512_cmp_ph_mask(a, b, SIMDE_CMP_GT_OS);
  simde_test_x86_write_f16x32(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_f16x32(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask32(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_f16x32(SIMDE_FLOAT16_VALUE(-1000.0), SIMDE_FLOAT16_VALUE(1000.0));
  b = simde_test_x86_random_f16x32(SIMDE_FLOAT16_VALUE(-1000.0), SIMDE_FLOAT16_VALUE(1000.0));
  b = simde_x_mm512_mask_mov_ph(a, HEDLEY_STATIC_CAST(simde__mmask32, simde_test_codegen_random_i8()), b);
  a = simde_x_mm512_mask_mov_ph(a, HEDLEY_STATIC_CAST(simde__mmask32, 3), nanv);
  b = simde_x_mm512_mask_mov_ph(b, HEDLEY_STATIC_CAST(simde__mmask32, 6), nanv);
  r = simde_mm512_cmp_ph_mask(a, b, SIMDE_CMP_TRUE_UQ);
  simde_test_x86_write_f16x32(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_f16x32(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask32(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_f16x32(SIMDE_FLOAT16_VALUE(-1000.0), SIMDE_FLOAT16_VALUE(1000.0));
  b = simde_test_x86_random_f16x32(SIMDE_FLOAT16_VALUE(-1000.0), SIMDE_FLOAT16_VALUE(1000.0));
  b = simde_x_mm512_mask_mov_ph(a, HEDLEY_STATIC_CAST(simde__mmask32, simde_test_codegen_random_i8()), b);
  a = simde_x_mm512_mask_mov_ph(a, HEDLEY_STATIC_CAST(simde__mmask32, 3), nanv);
  b = simde_x_mm512_mask_mov_ph(b, HEDLEY_STATIC_CAST(simde__mmask32, 6), nanv);
  r = simde_mm512_cmp_ph_mask(a, b, SIMDE_CMP_EQ_OS);
  simde_test_x86_write_f16x32(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_f16x32(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask32(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_f16x32(SIMDE_FLOAT16_VALUE(-1000.0), SIMDE_FLOAT16_VALUE(1000.0));
  b = simde_test_x86_random_f16x32(SIMDE_FLOAT16_VALUE(-1000.0), SIMDE_FLOAT16_VALUE(1000.0));
  b = simde_x_mm512_mask_mov_ph(a, HEDLEY_STATIC_CAST(simde__mmask32, simde_test_codegen_random_i8()), b);
  a = simde_x_mm512_mask_mov_ph(a, HEDLEY_STATIC_CAST(simde__mmask32, 3), nanv);
  b = simde_x_mm512_mask_mov_ph(b, HEDLEY_STATIC_CAST(simde__mmask32, 6), nanv);
  r = simde_mm512_cmp_ph_mask(a, b, SIMDE_CMP_LT_OQ);
  simde_test_x86_write_f16x32(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_f16x32(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask32(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_f16x32(SIMDE_FLOAT16_VALUE(-1000.0), SIMDE_FLOAT16_VALUE(1000.0));
  b = simde_test_x86_random_f16x32(SIMDE_FLOAT16_VALUE(-1000.0), SIMDE_FLOAT16_VALUE(1000.0));
  b = simde_x_mm512_mask_mov_ph(a, HEDLEY_STATIC_CAST(simde__mmask32, simde_test_codegen_random_i8()), b);
  a = simde_x_mm512_mask_mov_ph(a, HEDLEY_STATIC_CAST(simde__mmask32, 3), nanv);
  b = simde_x_mm512_mask_mov_ph(b, HEDLEY_STATIC_CAST(simde__mmask32, 6), nanv);
  r = simde_mm512_cmp_ph_mask(a, b, SIMDE_CMP_LE_OQ);
  simde_test_x86_write_f16x32(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_f16x32(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask32(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_f16x32(SIMDE_FLOAT16_VALUE(-1000.0), SIMDE_FLOAT16_VALUE(1000.0));
  b = simde_test_x86_random_f16x32(SIMDE_FLOAT16_VALUE(-1000.0), SIMDE_FLOAT16_VALUE(1000.0));
  b = simde_x_mm512_mask_mov_ph(a, HEDLEY_STATIC_CAST(simde__mmask32, simde_test_codegen_random_i8()), b);
  a = simde_x_mm512_mask_mov_ph(a, HEDLEY_STATIC_CAST(simde__mmask32, 3), nanv);
  b = simde_x_mm512_mask_mov_ph(b, HEDLEY_STATIC_CAST(simde__mmask32, 6), nanv);
  r = simde_mm512_cmp_ph_mask(a, b, SIMDE_CMP_UNORD_S);
  simde_test_x86_write_f16x32(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_f16x32(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask32(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_f16x32(SIMDE_FLOAT16_VALUE(-1000.0), SIMDE_FLOAT16_VALUE(1000.0));
  b = simde_test_x86_random_f16x32(SIMDE_FLOAT16_VALUE(-1000.0), SIMDE_FLOAT16_VALUE(1000.0));
  b = simde_x_mm512_mask_mov_ph(a, HEDLEY_STATIC_CAST(simde__mmask32, simde_test_codegen_random_i8()), b);
  a = simde_x_mm512_mask_mov_ph(a, HEDLEY_STATIC_CAST(simde__mmask32, 3), nanv);
  b = simde_x_mm512_mask_mov_ph(b, HEDLEY_STATIC_CAST(simde__mmask32, 6), nanv);
  r = simde_mm512_cmp_ph_mask(a, b, SIMDE_CMP_NEQ_US);
  simde_test_x86_write_f16x32(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_f16x32(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask32(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_f16x32(SIMDE_FLOAT16_VALUE(-1000.0), SIMDE_FLOAT16_VALUE(1000.0));
  b = simde_test_x86_random_f16x32(SIMDE_FLOAT16_VALUE(-1000.0), SIMDE_FLOAT16_VALUE(1000.0));
  b = simde_x_mm512_mask_mov_ph(a, HEDLEY_STATIC_CAST(simde__mmask32, simde_test_codegen_random_i8()), b);
  a = simde_x_mm512_mask_mov_ph(a, HEDLEY_STATIC_CAST(simde__mmask32, 3), nanv);
  b = simde_x_mm512_mask_mov_ph(b, HEDLEY_STATIC_CAST(simde__mmask32, 6), nanv);
  r = simde_mm512_cmp_ph_mask(a, b, SIMDE_CMP_NLT_UQ);
  simde_test_x86_write_f16x32(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_f16x32(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask32(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_f16x32(SIMDE_FLOAT16_VALUE(-1000.0), SIMDE_FLOAT16_VALUE(1000.0));
  b = simde_test_x86_random_f16x32(SIMDE_FLOAT16_VALUE(-1000.0), SIMDE_FLOAT16_VALUE(1000.0));
  b = simde_x_mm512_mask_mov_ph(a, HEDLEY_STATIC_CAST(simde__mmask32, simde_test_codegen_random_i8()), b);
  a = simde_x_mm512_mask_mov_ph(a, HEDLEY_STATIC_CAST(simde__mmask32, 3), nanv);
  b = simde_x_mm512_mask_mov_ph(b, HEDLEY_STATIC_CAST(simde__mmask32, 6), nanv);
  r = simde_mm512_cmp_ph_mask(a, b, SIMDE_CMP_NLE_UQ);
  simde_test_x86_write_f16x32(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_f16x32(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask32(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_f16x32(SIMDE_FLOAT16_VALUE(-1000.0), SIMDE_FLOAT16_VALUE(1000.0));
  b = simde_test_x86_random_f16x32(SIMDE_FLOAT16_VALUE(-1000.0), SIMDE_FLOAT16_VALUE(1000.0));
  b = simde_x_mm512_mask_mov_ph(a, HEDLEY_STATIC_CAST(simde__mmask32, simde_test_codegen_random_i8()), b);
  a = simde_x_mm512_mask_mov_ph(a, HEDLEY_STATIC_CAST(simde__mmask32, 3), nanv);
  b = simde_x_mm512_mask_mov_ph(b, HEDLEY_STATIC_CAST(simde__mmask32, 6), nanv);
  r = simde_mm512_cmp_ph_mask(a, b, SIMDE_CMP_ORD_S);
  simde_test_x86_write_f16x32(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_f16x32(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask32(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_f16x32(SIMDE_FLOAT16_VALUE(-1000.0), SIMDE_FLOAT16_VALUE(1000.0));
  b = simde_test_x86_random_f16x32(SIMDE_FLOAT16_VALUE(-1000.0), SIMDE_FLOAT16_VALUE(1000.0));
  b = simde_x_mm512_mask_mov_ph(a, HEDLEY_STATIC_CAST(simde__mmask32, simde_test_codegen_random_i8()), b);
  a = simde_x_mm512_mask_mov_ph(a, HEDLEY_STATIC_CAST(simde__mmask32, 3), nanv);
  b = simde_x_mm512_mask_mov_ph(b, HEDLEY_STATIC_CAST(simde__mmask32, 6), nanv);
  r = simde_mm512_cmp_ph_mask(a, b, SIMDE_CMP_EQ_US);
  simde_test_x86_write_f16x32(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_f16x32(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask32(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_f16x32(SIMDE_FLOAT16_VALUE(-1000.0), SIMDE_FLOAT16_VALUE(1000.0));
  b = simde_test_x86_random_f16x32(SIMDE_FLOAT16_VALUE(-1000.0), SIMDE_FLOAT16_VALUE(1000.0));
  b = simde_x_mm512_mask_mov_ph(a, HEDLEY_STATIC_CAST(simde__mmask32, simde_test_codegen_random_i8()), b);
  a = simde_x_mm512_mask_mov_ph(a, HEDLEY_STATIC_CAST(simde__mmask32, 3), nanv);
  b = simde_x_mm512_mask_mov_ph(b, HEDLEY_STATIC_CAST(simde__mmask32, 6), nanv);
  r = simde_mm512_cmp_ph_mask(a, b, SIMDE_CMP_NGE_UQ);
  simde_test_x86_write_f16x32(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_f16x32(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask32(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_f16x32(SIMDE_FLOAT16_VALUE(-1000.0), SIMDE_FLOAT16_VALUE(1000.0));
  b = simde_test_x86_random_f16x32(SIMDE_FLOAT16_VALUE(-1000.0), SIMDE_FLOAT16_VALUE(1000.0));
  b = simde_x_mm512_mask_mov_ph(a, HEDLEY_STATIC_CAST(simde__mmask32, simde_test_codegen_random_i8()), b);
  a = simde_x_mm512_mask_mov_ph(a, HEDLEY_STATIC_CAST(simde__mmask32, 3), nanv);
  b = simde_x_mm512_mask_mov_ph(b, HEDLEY_STATIC_CAST(simde__mmask32, 6), nanv);
  r = simde_mm512_cmp_ph_mask(a, b, SIMDE_CMP_NGT_UQ);
  simde_test_x86_write_f16x32(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_f16x32(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask32(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_f16x32(SIMDE_FLOAT16_VALUE(-1000.0), SIMDE_FLOAT16_VALUE(1000.0));
  b = simde_test_x86_random_f16x32(SIMDE_FLOAT16_VALUE(-1000.0), SIMDE_FLOAT16_VALUE(1000.0));
  b = simde_x_mm512_mask_mov_ph(a, HEDLEY_STATIC_CAST(simde__mmask32, simde_test_codegen_random_i8()), b);
  a = simde_x_mm512_mask_mov_ph(a, HEDLEY_STATIC_CAST(simde__mmask32, 3), nanv);
  b = simde_x_mm512_mask_mov_ph(b, HEDLEY_STATIC_CAST(simde__mmask32, 6), nanv);
  r = simde_mm512_cmp_ph_mask(a, b, SIMDE_CMP_FALSE_OS);
  simde_test_x86_write_f16x32(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_f16x32(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask32(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_f16x32(SIMDE_FLOAT16_VALUE(-1000.0), SIMDE_FLOAT16_VALUE(1000.0));
  b = simde_test_x86_random_f16x32(SIMDE_FLOAT16_VALUE(-1000.0), SIMDE_FLOAT16_VALUE(1000.0));
  b = simde_x_mm512_mask_mov_ph(a, HEDLEY_STATIC_CAST(simde__mmask32, simde_test_codegen_random_i8()), b);
  a = simde_x_mm512_mask_mov_ph(a, HEDLEY_STATIC_CAST(simde__mmask32, 3), nanv);
  b = simde_x_mm512_mask_mov_ph(b, HEDLEY_STATIC_CAST(simde__mmask32, 6), nanv);
  r = simde_mm512_cmp_ph_mask(a, b, SIMDE_CMP_NEQ_OS);
  simde_test_x86_write_f16x32(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_f16x32(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask32(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_f16x32(SIMDE_FLOAT16_VALUE(-1000.0), SIMDE_FLOAT16_VALUE(1000.0));
  b = simde_test_x86_random_f16x32(SIMDE_FLOAT16_VALUE(-1000.0), SIMDE_FLOAT16_VALUE(1000.0));
  b = simde_x_mm512_mask_mov_ph(a, HEDLEY_STATIC_CAST(simde__mmask32, simde_test_codegen_random_i8()), b);
  a = simde_x_mm512_mask_mov_ph(a, HEDLEY_STATIC_CAST(simde__mmask32, 3), nanv);
  b = simde_x_mm512_mask_mov_ph(b, HEDLEY_STATIC_CAST(simde__mmask32, 6), nanv);
  r = simde_mm512_cmp_ph_mask(a, b, SIMDE_CMP_GE_OQ);
  simde_test_x86_write_f16x32(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_f16x32(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask32(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_f16x32(SIMDE_FLOAT16_VALUE(-1000.0), SIMDE_FLOAT16_VALUE(1000.0));
  b = simde_test_x86_random_f16x32(SIMDE_FLOAT16_VALUE(-1000.0), SIMDE_FLOAT16_VALUE(1000.0));
  b = simde_x_mm512_mask_mov_ph(a, HEDLEY_STATIC_CAST(simde__mmask32, simde_test_codegen_random_i8()), b);
  a = simde_x_mm512_mask_mov_ph(a, HEDLEY_STATIC_CAST(simde__mmask32, 3), nanv);
  b = simde_x_mm512_mask_mov_ph(b, HEDLEY_STATIC_CAST(simde__mmask32, 6), nanv);
  r = simde_mm512_cmp_ph_mask(a, b, SIMDE_CMP_GT_OQ);
  simde_test_x86_write_f16x32(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_f16x32(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask32(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_f16x32(SIMDE_FLOAT16_VALUE(-1000.0), SIMDE_FLOAT16_VALUE(1000.0));
  b = simde_test_x86_random_f16x32(SIMDE_FLOAT16_VALUE(-1000.0), SIMDE_FLOAT16_VALUE(1000.0));
  b = simde_x_mm512_mask_mov_ph(a, HEDLEY_STATIC_CAST(simde__mmask32, simde_test_codegen_random_i8()), b);
  a = simde_x_mm512_mask_mov_ph(a, HEDLEY_STATIC_CAST(simde__mmask32, 3), nanv);
  b = simde_x_mm512_mask_mov_ph(b, HEDLEY_STATIC_CAST(simde__mmask32, 6), nanv);
  r = simde_mm512_cmp_ph_mask(a, b, SIMDE_CMP_TRUE_US);
  simde_test_x86_write_f16x32(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_f16x32(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_mmask32(2, r, SIMDE_TEST_VEC_POS_LAST);

  return 1;
#endif
}
#endif /* SIMDE_FLOAT16_IS_SCALAR */

#endif /* !defined(SIMDE_NATIVE_ALIASES_TESTING */

#endif /* !defined(SIMDE_FAST_MATH) */

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_cmp_epi32_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_cmp_epi8_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_cmp_epi16_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_cmp_epi16_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_cmp_epi32_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_cmp_epi64_mask)
  #if !defined(SIMDE_FAST_MATH)
    SIMDE_TEST_FUNC_LIST_ENTRY(mm512_cmp_epu16_mask)
    SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_cmp_epu16_mask)
    SIMDE_TEST_FUNC_LIST_ENTRY(mm256_cmp_epu32_mask)
    SIMDE_TEST_FUNC_LIST_ENTRY(mm512_cmp_epu32_mask)
    SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_cmp_epu32_mask)
    SIMDE_TEST_FUNC_LIST_ENTRY(mm512_cmp_epu64_mask)
    SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_cmp_epu64_mask)
    #if !defined(SIMDE_NATIVE_ALIASES_TESTING)
      SIMDE_TEST_FUNC_LIST_ENTRY(mm512_cmp_ps_mask)
      SIMDE_TEST_FUNC_LIST_ENTRY(mm256_cmp_ps_mask)
      SIMDE_TEST_FUNC_LIST_ENTRY(mm_cmp_ps_mask)
      SIMDE_TEST_FUNC_LIST_ENTRY(mm512_cmp_pd_mask)
      SIMDE_TEST_FUNC_LIST_ENTRY(mm256_cmp_pd_mask)
      SIMDE_TEST_FUNC_LIST_ENTRY(mm_cmp_pd_mask)
      #if defined(SIMDE_FLOAT16_IS_SCALAR)
        SIMDE_TEST_FUNC_LIST_ENTRY(mm512_cmp_ph_mask)
      #endif
    #endif
  #endif
SIMDE_TEST_FUNC_LIST_END

#include <test/x86/avx512/test-avx512-footer.h>
