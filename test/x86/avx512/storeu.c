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

#define SIMDE_TEST_X86_AVX512_INSN storeu

#include <test/x86/avx512/test-avx512.h>
#include <simde/x86/avx512/storeu.h>

static int
test_simde_mm256_storeu_epi8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int8_t a[32];
    const int8_t r[32];
  } test_vec[] = {
    { {  INT8_C(  75),  INT8_C(  44),  INT8_C( 120), -INT8_C(  77), -INT8_C(  11), -INT8_C(  54), -INT8_C( 120), -INT8_C(  90),
         INT8_C(  76), -INT8_C( 120),  INT8_C(  18),  INT8_C( 102), -INT8_C(  27),  INT8_C( 105), -INT8_C(  91), -INT8_C(  67),
        -INT8_C( 127), -INT8_C(  90), -INT8_C(  52), -INT8_C(   1), -INT8_C( 106),  INT8_C(  47), -INT8_C( 109), -INT8_C( 117),
        -INT8_C(  83), -INT8_C(  57),  INT8_C(   1),  INT8_C( 120), -INT8_C(  46),  INT8_C(  84), -INT8_C(  19),  INT8_C(  30) },
      {  INT8_C(  75),  INT8_C(  44),  INT8_C( 120), -INT8_C(  77), -INT8_C(  11), -INT8_C(  54), -INT8_C( 120), -INT8_C(  90),
         INT8_C(  76), -INT8_C( 120),  INT8_C(  18),  INT8_C( 102), -INT8_C(  27),  INT8_C( 105), -INT8_C(  91), -INT8_C(  67),
        -INT8_C( 127), -INT8_C(  90), -INT8_C(  52), -INT8_C(   1), -INT8_C( 106),  INT8_C(  47), -INT8_C( 109), -INT8_C( 117),
        -INT8_C(  83), -INT8_C(  57),  INT8_C(   1),  INT8_C( 120), -INT8_C(  46),  INT8_C(  84), -INT8_C(  19),  INT8_C(  30) } },
    { {      INT8_MIN,  INT8_C( 101), -INT8_C(  47),  INT8_C( 117),  INT8_C(  47),  INT8_C(  90),  INT8_C(  28),  INT8_C( 124),
        -INT8_C(  30),  INT8_C(  46), -INT8_C(  30), -INT8_C(  57), -INT8_C( 105), -INT8_C( 121), -INT8_C( 124),  INT8_C(  25),
         INT8_C(  45),  INT8_C(  80),  INT8_C(  24), -INT8_C(  61),      INT8_MAX, -INT8_C(  85),  INT8_C(  79),  INT8_C(  44),
         INT8_C( 114),  INT8_C(  80), -INT8_C(  92),  INT8_C(  69), -INT8_C(  91), -INT8_C( 110),  INT8_C(  99),  INT8_C(  37) },
      {      INT8_MIN,  INT8_C( 101), -INT8_C(  47),  INT8_C( 117),  INT8_C(  47),  INT8_C(  90),  INT8_C(  28),  INT8_C( 124),
        -INT8_C(  30),  INT8_C(  46), -INT8_C(  30), -INT8_C(  57), -INT8_C( 105), -INT8_C( 121), -INT8_C( 124),  INT8_C(  25),
         INT8_C(  45),  INT8_C(  80),  INT8_C(  24), -INT8_C(  61),      INT8_MAX, -INT8_C(  85),  INT8_C(  79),  INT8_C(  44),
         INT8_C( 114),  INT8_C(  80), -INT8_C(  92),  INT8_C(  69), -INT8_C(  91), -INT8_C( 110),  INT8_C(  99),  INT8_C(  37) } },
    { { -INT8_C(   9),  INT8_C(  52), -INT8_C( 101),  INT8_C(  39), -INT8_C( 114), -INT8_C(  73), -INT8_C(  93),  INT8_C( 113),
        -INT8_C(  27), -INT8_C( 123),  INT8_C(  56),  INT8_C( 124),  INT8_C(  13), -INT8_C(  67), -INT8_C( 107),  INT8_C(  58),
         INT8_C(  13), -INT8_C(  82), -INT8_C(   2), -INT8_C( 115),  INT8_C(  89),  INT8_C(  77), -INT8_C(  71), -INT8_C(  52),
        -INT8_C(  99),  INT8_C(  94),  INT8_C(  17),  INT8_C(  66), -INT8_C(  16),  INT8_C( 116),  INT8_C( 104), -INT8_C(  25) },
      { -INT8_C(   9),  INT8_C(  52), -INT8_C( 101),  INT8_C(  39), -INT8_C( 114), -INT8_C(  73), -INT8_C(  93),  INT8_C( 113),
        -INT8_C(  27), -INT8_C( 123),  INT8_C(  56),  INT8_C( 124),  INT8_C(  13), -INT8_C(  67), -INT8_C( 107),  INT8_C(  58),
         INT8_C(  13), -INT8_C(  82), -INT8_C(   2), -INT8_C( 115),  INT8_C(  89),  INT8_C(  77), -INT8_C(  71), -INT8_C(  52),
        -INT8_C(  99),  INT8_C(  94),  INT8_C(  17),  INT8_C(  66), -INT8_C(  16),  INT8_C( 116),  INT8_C( 104), -INT8_C(  25) } },
    { { -INT8_C(  88),  INT8_C(   3),  INT8_C(  14),  INT8_C(  55), -INT8_C(  70), -INT8_C(  79), -INT8_C(  88), -INT8_C(  97),
         INT8_C(  55), -INT8_C(  32),  INT8_C(  27),  INT8_C(  68), -INT8_C(  99), -INT8_C(  79),  INT8_C( 126), -INT8_C(  85),
         INT8_C(  95),  INT8_C( 124),  INT8_C(  56), -INT8_C(  72), -INT8_C(  55), -INT8_C(  15), -INT8_C( 124),  INT8_C( 103),
         INT8_C(  79), -INT8_C( 107), -INT8_C(  87),  INT8_C(  63),  INT8_C(   9),  INT8_C(  17),  INT8_C(  39), -INT8_C(  78) },
      { -INT8_C(  88),  INT8_C(   3),  INT8_C(  14),  INT8_C(  55), -INT8_C(  70), -INT8_C(  79), -INT8_C(  88), -INT8_C(  97),
         INT8_C(  55), -INT8_C(  32),  INT8_C(  27),  INT8_C(  68), -INT8_C(  99), -INT8_C(  79),  INT8_C( 126), -INT8_C(  85),
         INT8_C(  95),  INT8_C( 124),  INT8_C(  56), -INT8_C(  72), -INT8_C(  55), -INT8_C(  15), -INT8_C( 124),  INT8_C( 103),
         INT8_C(  79), -INT8_C( 107), -INT8_C(  87),  INT8_C(  63),  INT8_C(   9),  INT8_C(  17),  INT8_C(  39), -INT8_C(  78) } },
    { {  INT8_C(  20),  INT8_C(  53), -INT8_C(  23), -INT8_C(  50), -INT8_C(  25), -INT8_C( 111),  INT8_C( 109),  INT8_C(  30),
         INT8_C( 113), -INT8_C( 119),  INT8_C(  98),  INT8_C(  15),  INT8_C(  58), -INT8_C(  32), -INT8_C(  70), -INT8_C( 103),
         INT8_C(  93), -INT8_C(  14),  INT8_C(  81),  INT8_C(  38), -INT8_C(  29), -INT8_C(  42), -INT8_C( 115),  INT8_C(  51),
         INT8_C( 107),  INT8_C(  55),  INT8_C( 114),  INT8_C( 117),  INT8_C(  72), -INT8_C( 103),  INT8_C(  39),  INT8_C(  93) },
      {  INT8_C(  20),  INT8_C(  53), -INT8_C(  23), -INT8_C(  50), -INT8_C(  25), -INT8_C( 111),  INT8_C( 109),  INT8_C(  30),
         INT8_C( 113), -INT8_C( 119),  INT8_C(  98),  INT8_C(  15),  INT8_C(  58), -INT8_C(  32), -INT8_C(  70), -INT8_C( 103),
         INT8_C(  93), -INT8_C(  14),  INT8_C(  81),  INT8_C(  38), -INT8_C(  29), -INT8_C(  42), -INT8_C( 115),  INT8_C(  51),
         INT8_C( 107),  INT8_C(  55),  INT8_C( 114),  INT8_C( 117),  INT8_C(  72), -INT8_C( 103),  INT8_C(  39),  INT8_C(  93) } },
    { { -INT8_C(  49),  INT8_C(  16),  INT8_C(  43), -INT8_C(  74), -INT8_C(  95), -INT8_C( 103), -INT8_C(  44),  INT8_C(  18),
         INT8_C(  34),  INT8_C(  54),  INT8_C(  33),  INT8_C(  92),  INT8_C(  22), -INT8_C(  37), -INT8_C(  11),  INT8_C( 115),
        -INT8_C(  51),  INT8_C(  70), -INT8_C( 102), -INT8_C(  79),  INT8_C(  28),  INT8_C(  39), -INT8_C(  28), -INT8_C( 120),
         INT8_C(  94),  INT8_C(  86), -INT8_C(   3), -INT8_C(  89), -INT8_C(  16),  INT8_C(  36),  INT8_C(   4), -INT8_C(  65) },
      { -INT8_C(  49),  INT8_C(  16),  INT8_C(  43), -INT8_C(  74), -INT8_C(  95), -INT8_C( 103), -INT8_C(  44),  INT8_C(  18),
         INT8_C(  34),  INT8_C(  54),  INT8_C(  33),  INT8_C(  92),  INT8_C(  22), -INT8_C(  37), -INT8_C(  11),  INT8_C( 115),
        -INT8_C(  51),  INT8_C(  70), -INT8_C( 102), -INT8_C(  79),  INT8_C(  28),  INT8_C(  39), -INT8_C(  28), -INT8_C( 120),
         INT8_C(  94),  INT8_C(  86), -INT8_C(   3), -INT8_C(  89), -INT8_C(  16),  INT8_C(  36),  INT8_C(   4), -INT8_C(  65) } },
    { {  INT8_C(  52),  INT8_C(  47),  INT8_C( 117), -INT8_C(  43), -INT8_C(  56),  INT8_C(  73), -INT8_C(  25), -INT8_C(  22),
             INT8_MAX,  INT8_C(   9),  INT8_C(  70), -INT8_C( 107), -INT8_C(  28),  INT8_C(  59),  INT8_C(   9), -INT8_C(  78),
        -INT8_C( 126), -INT8_C(  93),  INT8_C(  99), -INT8_C(  98), -INT8_C(  54),  INT8_C(  71),  INT8_C(  38),  INT8_C(  41),
        -INT8_C(  99),  INT8_C(  35), -INT8_C(  48), -INT8_C( 115),  INT8_C(  71), -INT8_C(  44),  INT8_C(  76),  INT8_C( 123) },
      {  INT8_C(  52),  INT8_C(  47),  INT8_C( 117), -INT8_C(  43), -INT8_C(  56),  INT8_C(  73), -INT8_C(  25), -INT8_C(  22),
             INT8_MAX,  INT8_C(   9),  INT8_C(  70), -INT8_C( 107), -INT8_C(  28),  INT8_C(  59),  INT8_C(   9), -INT8_C(  78),
        -INT8_C( 126), -INT8_C(  93),  INT8_C(  99), -INT8_C(  98), -INT8_C(  54),  INT8_C(  71),  INT8_C(  38),  INT8_C(  41),
        -INT8_C(  99),  INT8_C(  35), -INT8_C(  48), -INT8_C( 115),  INT8_C(  71), -INT8_C(  44),  INT8_C(  76),  INT8_C( 123) } },
    { {  INT8_C(   3), -INT8_C(  63),  INT8_C(  80), -INT8_C(  52),  INT8_C(  10),  INT8_C(  56), -INT8_C(  74), -INT8_C( 119),
         INT8_C(  65), -INT8_C(   3),  INT8_C(  31),  INT8_C(  37),  INT8_C(  56),  INT8_C(  40), -INT8_C(  41), -INT8_C(  70),
        -INT8_C(  53),  INT8_C(  58),  INT8_C(  89), -INT8_C( 107), -INT8_C( 127),      INT8_MAX, -INT8_C(  66),  INT8_C(  31),
        -INT8_C(  93), -INT8_C( 114), -INT8_C(  84), -INT8_C(  22),  INT8_C(  98), -INT8_C(   7),  INT8_C( 102),  INT8_C( 102) },
      {  INT8_C(   3), -INT8_C(  63),  INT8_C(  80), -INT8_C(  52),  INT8_C(  10),  INT8_C(  56), -INT8_C(  74), -INT8_C( 119),
         INT8_C(  65), -INT8_C(   3),  INT8_C(  31),  INT8_C(  37),  INT8_C(  56),  INT8_C(  40), -INT8_C(  41), -INT8_C(  70),
        -INT8_C(  53),  INT8_C(  58),  INT8_C(  89), -INT8_C( 107), -INT8_C( 127),      INT8_MAX, -INT8_C(  66),  INT8_C(  31),
        -INT8_C(  93), -INT8_C( 114), -INT8_C(  84), -INT8_C(  22),  INT8_C(  98), -INT8_C(   7),  INT8_C( 102),  INT8_C( 102) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256i a = simde_mm256_loadu_epi8(test_vec[i].a);
    int8_t r[sizeof(simde__m256i) / sizeof(int8_t)] = {0};
    simde_mm256_storeu_epi8(r, a);
    simde_assert_equal_vi8(sizeof(r) / sizeof(r[0]), r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m256i a = simde_test_x86_random_i8x32();
    int8_t r[sizeof(simde__m256i) / sizeof(int8_t)] = {0};
    simde_mm256_storeu_epi8(r, a);

    simde_test_x86_write_i8x32(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_vi8(2, sizeof(r) / sizeof(r[0]), r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_storeu_epi16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int16_t a[16];
    const int16_t r[16];
  } test_vec[] = {
    { {  INT16_C( 27201), -INT16_C( 10931),  INT16_C( 26543), -INT16_C( 17697), -INT16_C(  5170), -INT16_C(  2379),  INT16_C( 24504), -INT16_C( 22914),
         INT16_C(  3457), -INT16_C( 18629), -INT16_C(  4523),  INT16_C(  1253), -INT16_C(  9921),  INT16_C( 31191),  INT16_C(  9211),  INT16_C( 15721) },
      {  INT16_C( 27201), -INT16_C( 10931),  INT16_C( 26543), -INT16_C( 17697), -INT16_C(  5170), -INT16_C(  2379),  INT16_C( 24504), -INT16_C( 22914),
         INT16_C(  3457), -INT16_C( 18629), -INT16_C(  4523),  INT16_C(  1253), -INT16_C(  9921),  INT16_C( 31191),  INT16_C(  9211),  INT16_C( 15721) } },
    { { -INT16_C( 18803),  INT16_C( 15634), -INT16_C(  3810), -INT16_C(  4873), -INT16_C( 21283), -INT16_C( 27166),  INT16_C( 24587), -INT16_C( 29381),
         INT16_C( 30573), -INT16_C( 15804),  INT16_C( 10597), -INT16_C( 23097), -INT16_C( 25086), -INT16_C(   482), -INT16_C( 30782),  INT16_C( 20283) },
      { -INT16_C( 18803),  INT16_C( 15634), -INT16_C(  3810), -INT16_C(  4873), -INT16_C( 21283), -INT16_C( 27166),  INT16_C( 24587), -INT16_C( 29381),
         INT16_C( 30573), -INT16_C( 15804),  INT16_C( 10597), -INT16_C( 23097), -INT16_C( 25086), -INT16_C(   482), -INT16_C( 30782),  INT16_C( 20283) } },
    { {  INT16_C( 19773),  INT16_C( 23436), -INT16_C( 31938),  INT16_C(  6983),  INT16_C( 10544),  INT16_C( 15281), -INT16_C(  4982), -INT16_C(  2104),
         INT16_C(  3171), -INT16_C( 13894), -INT16_C( 32458),  INT16_C( 14446), -INT16_C( 29665), -INT16_C(  7882),  INT16_C( 28947),  INT16_C( 20529) },
      {  INT16_C( 19773),  INT16_C( 23436), -INT16_C( 31938),  INT16_C(  6983),  INT16_C( 10544),  INT16_C( 15281), -INT16_C(  4982), -INT16_C(  2104),
         INT16_C(  3171), -INT16_C( 13894), -INT16_C( 32458),  INT16_C( 14446), -INT16_C( 29665), -INT16_C(  7882),  INT16_C( 28947),  INT16_C( 20529) } },
    { { -INT16_C( 16962), -INT16_C(   596), -INT16_C(  3263),  INT16_C( 28952), -INT16_C( 14051), -INT16_C( 22612),  INT16_C( 30134),  INT16_C(  6558),
         INT16_C( 22657), -INT16_C( 18462),  INT16_C( 20697), -INT16_C(  1552),  INT16_C(  9948), -INT16_C(  4134),  INT16_C(  2968),  INT16_C( 22080) },
      { -INT16_C( 16962), -INT16_C(   596), -INT16_C(  3263),  INT16_C( 28952), -INT16_C( 14051), -INT16_C( 22612),  INT16_C( 30134),  INT16_C(  6558),
         INT16_C( 22657), -INT16_C( 18462),  INT16_C( 20697), -INT16_C(  1552),  INT16_C(  9948), -INT16_C(  4134),  INT16_C(  2968),  INT16_C( 22080) } },
    { { -INT16_C(  4919),  INT16_C(  2643),  INT16_C( 27871), -INT16_C(   901),  INT16_C( 10037), -INT16_C(  5213),  INT16_C( 17052),  INT16_C(  7685),
        -INT16_C(  6246),  INT16_C( 29909), -INT16_C( 15048),  INT16_C(  5229),  INT16_C( 18412), -INT16_C( 31740),  INT16_C( 17491),  INT16_C(  7386) },
      { -INT16_C(  4919),  INT16_C(  2643),  INT16_C( 27871), -INT16_C(   901),  INT16_C( 10037), -INT16_C(  5213),  INT16_C( 17052),  INT16_C(  7685),
        -INT16_C(  6246),  INT16_C( 29909), -INT16_C( 15048),  INT16_C(  5229),  INT16_C( 18412), -INT16_C( 31740),  INT16_C( 17491),  INT16_C(  7386) } },
    { {  INT16_C( 11824),  INT16_C(  3878), -INT16_C( 24166), -INT16_C( 12532), -INT16_C( 20536),  INT16_C( 26043), -INT16_C( 16143), -INT16_C( 29565),
         INT16_C( 22695), -INT16_C(  8448),  INT16_C( 27934),  INT16_C(  2804), -INT16_C(  1868),  INT16_C(  1934),  INT16_C( 26684),  INT16_C( 27683) },
      {  INT16_C( 11824),  INT16_C(  3878), -INT16_C( 24166), -INT16_C( 12532), -INT16_C( 20536),  INT16_C( 26043), -INT16_C( 16143), -INT16_C( 29565),
         INT16_C( 22695), -INT16_C(  8448),  INT16_C( 27934),  INT16_C(  2804), -INT16_C(  1868),  INT16_C(  1934),  INT16_C( 26684),  INT16_C( 27683) } },
    { {  INT16_C( 18838),  INT16_C( 12411), -INT16_C( 30742), -INT16_C( 19712), -INT16_C( 17609),  INT16_C( 10264), -INT16_C( 25733),  INT16_C(  8884),
        -INT16_C( 19213),  INT16_C(  4354), -INT16_C(  2527), -INT16_C( 10725), -INT16_C( 22034),  INT16_C( 10973),  INT16_C(   274), -INT16_C( 22378) },
      {  INT16_C( 18838),  INT16_C( 12411), -INT16_C( 30742), -INT16_C( 19712), -INT16_C( 17609),  INT16_C( 10264), -INT16_C( 25733),  INT16_C(  8884),
        -INT16_C( 19213),  INT16_C(  4354), -INT16_C(  2527), -INT16_C( 10725), -INT16_C( 22034),  INT16_C( 10973),  INT16_C(   274), -INT16_C( 22378) } },
    { {  INT16_C(  4426),  INT16_C( 13785), -INT16_C(  9831), -INT16_C( 12056),  INT16_C(   148),  INT16_C(  4088), -INT16_C( 21093), -INT16_C( 29135),
         INT16_C( 13153), -INT16_C( 31840), -INT16_C( 17623),  INT16_C(  5977),  INT16_C( 13925),  INT16_C( 30529), -INT16_C( 10441), -INT16_C( 32225) },
      {  INT16_C(  4426),  INT16_C( 13785), -INT16_C(  9831), -INT16_C( 12056),  INT16_C(   148),  INT16_C(  4088), -INT16_C( 21093), -INT16_C( 29135),
         INT16_C( 13153), -INT16_C( 31840), -INT16_C( 17623),  INT16_C(  5977),  INT16_C( 13925),  INT16_C( 30529), -INT16_C( 10441), -INT16_C( 32225) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256i a = simde_mm256_loadu_epi16(test_vec[i].a);
    int16_t r[sizeof(simde__m256i) / sizeof(int16_t)] = {0};
    simde_mm256_storeu_epi16(r, a);
    simde_assert_equal_vi16(sizeof(r) / sizeof(r[0]), r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m256i a = simde_test_x86_random_i16x16();
    int16_t r[sizeof(simde__m256i) / sizeof(int16_t)] = {0};
    simde_mm256_storeu_epi16(r, a);

    simde_test_x86_write_i16x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_vi16(2, sizeof(r) / sizeof(r[0]), r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_mask_storeu_epi16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask16 k;
    const int16_t a[16];
    const int16_t r[16];
  } test_vec[] = {
    { UINT16_C(28210),
      { -INT16_C( 30445),  INT16_C( 24637), -INT16_C( 23832), -INT16_C(  6664),  INT16_C( 24593),  INT16_C(  7346), -INT16_C( 18995), -INT16_C( 14219),
         INT16_C(  2046),  INT16_C(    78),  INT16_C( 21593),  INT16_C( 29794), -INT16_C(  1520), -INT16_C( 25702), -INT16_C( 13160), -INT16_C( 21750) },
      {  INT16_C(     0),  INT16_C( 24637),  INT16_C(     0),  INT16_C(     0),  INT16_C( 24593),  INT16_C(  7346),  INT16_C(     0),  INT16_C(     0),
         INT16_C(     0),  INT16_C(    78),  INT16_C( 21593),  INT16_C( 29794),  INT16_C(     0), -INT16_C( 25702), -INT16_C( 13160),  INT16_C(     0) } },
    { UINT16_C(18261),
      {  INT16_C( 15628),  INT16_C(  1257), -INT16_C(  1502), -INT16_C( 11164),  INT16_C( 12822), -INT16_C( 29559), -INT16_C( 30726),  INT16_C( 18579),
        -INT16_C(  4984), -INT16_C(  5476), -INT16_C( 21408), -INT16_C(  1307),  INT16_C( 32072),  INT16_C( 21190),  INT16_C(  6953),  INT16_C( 13721) },
      {  INT16_C( 15628),  INT16_C(     0), -INT16_C(  1502),  INT16_C(     0),  INT16_C( 12822),  INT16_C(     0), -INT16_C( 30726),  INT16_C(     0),
        -INT16_C(  4984), -INT16_C(  5476), -INT16_C( 21408),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(  6953),  INT16_C(     0) } },
    { UINT16_C(33368),
      {  INT16_C( 31545), -INT16_C( 24964), -INT16_C( 28081), -INT16_C(  9776), -INT16_C( 13794), -INT16_C( 20128), -INT16_C(  6126), -INT16_C( 20835),
        -INT16_C(   557), -INT16_C( 18341), -INT16_C( 23561), -INT16_C( 17099),  INT16_C( 24309), -INT16_C( 28968),  INT16_C( 12691), -INT16_C( 13040) },
      {  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(  9776), -INT16_C( 13794),  INT16_C(     0), -INT16_C(  6126),  INT16_C(     0),
         INT16_C(     0), -INT16_C( 18341),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C( 13040) } },
    { UINT16_C(36012),
      { -INT16_C(  1173),  INT16_C( 15134),  INT16_C( 15828),  INT16_C( 13573),  INT16_C(  6126), -INT16_C( 29667), -INT16_C(  3899),  INT16_C(  8329),
        -INT16_C( 32344), -INT16_C(  8509), -INT16_C( 18370),  INT16_C(  5948), -INT16_C( 12218),  INT16_C( 22088), -INT16_C(  2915),  INT16_C(  2274) },
      {  INT16_C(     0),  INT16_C(     0),  INT16_C( 15828),  INT16_C( 13573),  INT16_C(     0), -INT16_C( 29667),  INT16_C(     0),  INT16_C(  8329),
         INT16_C(     0),  INT16_C(     0), -INT16_C( 18370),  INT16_C(  5948),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(  2274) } },
    { UINT16_C(  495),
      { -INT16_C( 15293),  INT16_C( 18494),  INT16_C( 11513),  INT16_C(  5727),  INT16_C(  9400),  INT16_C( 16903), -INT16_C( 20667),  INT16_C(  2243),
         INT16_C(   397), -INT16_C( 13631),  INT16_C(  1816),  INT16_C( 24730),  INT16_C( 14174),  INT16_C( 16468),  INT16_C( 17471), -INT16_C( 32191) },
      { -INT16_C( 15293),  INT16_C( 18494),  INT16_C( 11513),  INT16_C(  5727),  INT16_C(     0),  INT16_C( 16903), -INT16_C( 20667),  INT16_C(  2243),
         INT16_C(   397),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
    { UINT16_C(32520),
      {  INT16_C(   458),  INT16_C( 10668),  INT16_C( 25623),  INT16_C(  7757), -INT16_C( 27994),  INT16_C( 27086),  INT16_C( 23451),  INT16_C( 23659),
        -INT16_C( 31963), -INT16_C( 16541), -INT16_C( 15900),  INT16_C( 14582),  INT16_C( 13570),  INT16_C( 17276), -INT16_C( 31561), -INT16_C( 32317) },
      {  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(  7757),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
        -INT16_C( 31963), -INT16_C( 16541), -INT16_C( 15900),  INT16_C( 14582),  INT16_C( 13570),  INT16_C( 17276), -INT16_C( 31561),  INT16_C(     0) } },
    { UINT16_C(28549),
      { -INT16_C( 25174), -INT16_C(  1837),  INT16_C( 31419), -INT16_C( 30326),  INT16_C(  9699),  INT16_C( 20197),  INT16_C(  2689), -INT16_C(  6702),
        -INT16_C( 18742), -INT16_C( 16218), -INT16_C( 22290),  INT16_C( 27638), -INT16_C( 21012), -INT16_C( 20497),  INT16_C( 29999), -INT16_C(  9954) },
      { -INT16_C( 25174),  INT16_C(     0),  INT16_C( 31419),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(  6702),
        -INT16_C( 18742), -INT16_C( 16218), -INT16_C( 22290),  INT16_C( 27638),  INT16_C(     0), -INT16_C( 20497),  INT16_C( 29999),  INT16_C(     0) } },
    { UINT16_C(61714),
      { -INT16_C( 12847),  INT16_C( 23659),  INT16_C( 20311),  INT16_C( 15489),  INT16_C(   925),  INT16_C( 28486),  INT16_C(  4328), -INT16_C( 29147),
         INT16_C(  5329), -INT16_C( 14537),  INT16_C(  9087),  INT16_C( 28276), -INT16_C( 23598), -INT16_C(  3869), -INT16_C(  2691),  INT16_C( 20193) },
      {  INT16_C(     0),  INT16_C( 23659),  INT16_C(     0),  INT16_C(     0),  INT16_C(   925),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
         INT16_C(  5329),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C( 23598), -INT16_C(  3869), -INT16_C(  2691),  INT16_C( 20193) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256i a = simde_mm256_loadu_epi16(test_vec[i].a);
    int16_t r[sizeof(simde__m256i) / sizeof(int16_t)] = {0};
    simde_mm256_mask_storeu_epi16(r, test_vec[i].k, a);
    simde_assert_equal_vi16(sizeof(r) / sizeof(r[0]), r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask16 k = simde_test_x86_random_mmask16();
    simde__m256i a = simde_test_x86_random_i16x16();
    int16_t r[sizeof(simde__m256i) / sizeof(int16_t)] = {0};
    simde_mm256_mask_storeu_epi16(r, k, a);

    simde_test_x86_write_mmask16(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i16x16(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_vi16(2, sizeof(r) / sizeof(r[0]), r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_storeu_epi32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int32_t a[8];
    const int32_t r[8];
  } test_vec[] = {
    { { -INT32_C(  2101872407),  INT32_C(  1699913681),  INT32_C(   980699807),  INT32_C(  1506322167),  INT32_C(    64776409), -INT32_C(  1994771164), -INT32_C(  1560257429),  INT32_C(   472194867) },
      { -INT32_C(  2101872407),  INT32_C(  1699913681),  INT32_C(   980699807),  INT32_C(  1506322167),  INT32_C(    64776409), -INT32_C(  1994771164), -INT32_C(  1560257429),  INT32_C(   472194867) } },
    { { -INT32_C(   375464936),  INT32_C(   441446523),  INT32_C(   844415803),  INT32_C(  1133190249), -INT32_C(  1455003771),  INT32_C(   137519260), -INT32_C(   257215812),  INT32_C(  1762447441) },
      { -INT32_C(   375464936),  INT32_C(   441446523),  INT32_C(   844415803),  INT32_C(  1133190249), -INT32_C(  1455003771),  INT32_C(   137519260), -INT32_C(   257215812),  INT32_C(  1762447441) } },
    { {  INT32_C(   659794860), -INT32_C(   700341605), -INT32_C(   821455515),  INT32_C(   907187377), -INT32_C(  1730193156),  INT32_C(  1973424568), -INT32_C(  1788523709), -INT32_C(   939626213) },
      {  INT32_C(   659794860), -INT32_C(   700341605), -INT32_C(   821455515),  INT32_C(   907187377), -INT32_C(  1730193156),  INT32_C(  1973424568), -INT32_C(  1788523709), -INT32_C(   939626213) } },
    { { -INT32_C(  1192341220),  INT32_C(  1502490611),  INT32_C(  1982371780),  INT32_C(   682375724),  INT32_C(  1254132882), -INT32_C(   507551331), -INT32_C(   931781460), -INT32_C(  1299221354) },
      { -INT32_C(  1192341220),  INT32_C(  1502490611),  INT32_C(  1982371780),  INT32_C(   682375724),  INT32_C(  1254132882), -INT32_C(   507551331), -INT32_C(   931781460), -INT32_C(  1299221354) } },
    { { -INT32_C(  1184203066),  INT32_C(  1913846189), -INT32_C(  1125631344),  INT32_C(   115643508), -INT32_C(  1101945568), -INT32_C(  1298198522), -INT32_C(   881191627),  INT32_C(  1333594761) },
      { -INT32_C(  1184203066),  INT32_C(  1913846189), -INT32_C(  1125631344),  INT32_C(   115643508), -INT32_C(  1101945568), -INT32_C(  1298198522), -INT32_C(   881191627),  INT32_C(  1333594761) } },
    { {  INT32_C(   889841800),  INT32_C(  1906777057), -INT32_C(   902918314),  INT32_C(  1154552356), -INT32_C(  1123933513),  INT32_C(  1735434546),  INT32_C(  1077078710),  INT32_C(  2089791732) },
      {  INT32_C(   889841800),  INT32_C(  1906777057), -INT32_C(   902918314),  INT32_C(  1154552356), -INT32_C(  1123933513),  INT32_C(  1735434546),  INT32_C(  1077078710),  INT32_C(  2089791732) } },
    { {  INT32_C(  2041747608),  INT32_C(   183130548),  INT32_C(   232003817), -INT32_C(   497965781), -INT32_C(    90155833), -INT32_C(  1402924811), -INT32_C(   269708038), -INT32_C(   596935868) },
      {  INT32_C(  2041747608),  INT32_C(   183130548),  INT32_C(   232003817), -INT32_C(   497965781), -INT32_C(    90155833), -INT32_C(  1402924811), -INT32_C(   269708038), -INT32_C(   596935868) } },
    { { -INT32_C(   933946092),  INT32_C(  1624391543), -INT32_C(  2089965992),  INT32_C(   325434956),  INT32_C(   135070994),  INT32_C(   280260373),  INT32_C(  1207934979),  INT32_C(   790850075) },
      { -INT32_C(   933946092),  INT32_C(  1624391543), -INT32_C(  2089965992),  INT32_C(   325434956),  INT32_C(   135070994),  INT32_C(   280260373),  INT32_C(  1207934979),  INT32_C(   790850075) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256i a = simde_mm256_loadu_epi32(test_vec[i].a);
    int32_t r[sizeof(simde__m256i) / sizeof(int32_t)] = {0};
    simde_mm256_storeu_epi32(r, a);
    simde_assert_equal_vi32(sizeof(r) / sizeof(r[0]), r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m256i a = simde_test_x86_random_i32x8();
    int32_t r[sizeof(simde__m256i) / sizeof(int32_t)] = {0};
    simde_mm256_storeu_epi32(r, a);

    simde_test_x86_write_i32x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_vi32(2, sizeof(r) / sizeof(r[0]), r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_storeu_epi64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int64_t a[4];
    const int64_t r[4];
  } test_vec[] = {
    { { -INT64_C( 8520414791212126978),  INT64_C( 6470760737637609380),  INT64_C( 7372765298930470642),  INT64_C( 9137132392545280597) },
      { -INT64_C( 8520414791212126978),  INT64_C( 6470760737637609380),  INT64_C( 7372765298930470642),  INT64_C( 9137132392545280597) } },
    { { -INT64_C( 6181695135723249974),  INT64_C( 6582275189149771364),  INT64_C( 1378027538322451646), -INT64_C( 1793282446973829346) },
      { -INT64_C( 6181695135723249974),  INT64_C( 6582275189149771364),  INT64_C( 1378027538322451646), -INT64_C( 1793282446973829346) } },
    { {  INT64_C( 3047472147532648602),  INT64_C( 1960335077399948657),  INT64_C( 8772998174208204782), -INT64_C( 9045984628089229966) },
      {  INT64_C( 3047472147532648602),  INT64_C( 1960335077399948657),  INT64_C( 8772998174208204782), -INT64_C( 9045984628089229966) } },
    { {  INT64_C( 5166874341197089733),  INT64_C( 5643948629755485914), -INT64_C( 8302182390395426828), -INT64_C( 2733242877560954714) },
      {  INT64_C( 5166874341197089733),  INT64_C( 5643948629755485914), -INT64_C( 8302182390395426828), -INT64_C( 2733242877560954714) } },
    { {  INT64_C( 8843408995216798621),  INT64_C( 2640521362198879223), -INT64_C(   84940192658251989),  INT64_C( 2164997219794349596) },
      {  INT64_C( 8843408995216798621),  INT64_C( 2640521362198879223), -INT64_C(   84940192658251989),  INT64_C( 2164997219794349596) } },
    { {  INT64_C( 9217545211248472017), -INT64_C( 3712237534943208409),  INT64_C( 5003750052667256346),  INT64_C( 7741830259258359250) },
      {  INT64_C( 9217545211248472017), -INT64_C( 3712237534943208409),  INT64_C( 5003750052667256346),  INT64_C( 7741830259258359250) } },
    { {  INT64_C( 8501044911504360177),  INT64_C( 7336723655508676452), -INT64_C( 7375690268599065803), -INT64_C( 8265410862250190267) },
      {  INT64_C( 8501044911504360177),  INT64_C( 7336723655508676452), -INT64_C( 7375690268599065803), -INT64_C( 8265410862250190267) } },
    { {  INT64_C( 5990350384227821662),  INT64_C( 7601841099293388239), -INT64_C( 1914473353548638451),  INT64_C( 1562487073980897926) },
      {  INT64_C( 5990350384227821662),  INT64_C( 7601841099293388239), -INT64_C( 1914473353548638451),  INT64_C( 1562487073980897926) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256i a = simde_mm256_loadu_epi64(test_vec[i].a);
    int64_t r[sizeof(simde__m256i) / sizeof(int64_t)] = {0};
    simde_mm256_storeu_epi64(r, a);
    simde_assert_equal_vi64(sizeof(r) / sizeof(r[0]), r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m256i a = simde_test_x86_random_i64x4();
    int64_t r[sizeof(simde__m256i) / sizeof(int64_t)] = {0};
    simde_mm256_storeu_epi64(r, a);

    simde_test_x86_write_i64x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_vi64(2, sizeof(r) / sizeof(r[0]), r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_mask_storeu_epi16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask32 k;
    const int16_t a[32];
    const int16_t r[32];
  } test_vec[] = {
   { UINT32_C(3161047277),
      {  INT16_C( 31302), -INT16_C(  9255), -INT16_C( 26754),  INT16_C(  6282), -INT16_C(  5995), -INT16_C( 32261),  INT16_C( 26193), -INT16_C( 16077),
         INT16_C( 16306), -INT16_C( 19025),  INT16_C( 24681), -INT16_C( 27311), -INT16_C( 26783),  INT16_C( 20344), -INT16_C(  7592), -INT16_C( 25077),
        -INT16_C(  7076), -INT16_C(  9606),  INT16_C(  1148),  INT16_C(  4594), -INT16_C(  4628),  INT16_C( 15762), -INT16_C( 15020),  INT16_C(  1790),
        -INT16_C( 21243),  INT16_C( 28347),  INT16_C(  3341),  INT16_C( 28419),  INT16_C( 31652), -INT16_C(   834), -INT16_C( 13987), -INT16_C( 18021) },
      {  INT16_C( 31302),  INT16_C(     0), -INT16_C( 26754),  INT16_C(  6282),  INT16_C(     0), -INT16_C( 32261),  INT16_C( 26193), -INT16_C( 16077),
         INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(  7592), -INT16_C( 25077),
        -INT16_C(  7076),  INT16_C(     0),  INT16_C(     0),  INT16_C(  4594),  INT16_C(     0),  INT16_C( 15762), -INT16_C( 15020),  INT16_C(     0),
         INT16_C(     0),  INT16_C(     0),  INT16_C(  3341),  INT16_C( 28419),  INT16_C( 31652), -INT16_C(   834),  INT16_C(     0), -INT16_C( 18021) } },
    { UINT32_C( 714347950),
      { -INT16_C( 31207),  INT16_C(  1339), -INT16_C( 12940), -INT16_C( 14269),  INT16_C( 16786), -INT16_C( 26674), -INT16_C( 30225), -INT16_C(  1019),
         INT16_C(  2198),  INT16_C( 15211),  INT16_C( 10628), -INT16_C(  7881), -INT16_C( 11533), -INT16_C( 24165),  INT16_C( 12263),  INT16_C(   203),
         INT16_C(  1717),  INT16_C( 10502),  INT16_C( 18899),  INT16_C( 26097), -INT16_C( 16502),  INT16_C( 31229),  INT16_C(   585), -INT16_C(  8330),
        -INT16_C(  7925), -INT16_C( 28902),  INT16_C( 21003), -INT16_C(   400),  INT16_C(  2852),  INT16_C(  3231),  INT16_C( 27194), -INT16_C(  4084) },
      {  INT16_C(     0),  INT16_C(  1339), -INT16_C( 12940), -INT16_C( 14269),  INT16_C(     0), -INT16_C( 26674),  INT16_C(     0), -INT16_C(  1019),
         INT16_C(  2198),  INT16_C(     0),  INT16_C( 10628),  INT16_C(     0), -INT16_C( 11533),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
         INT16_C(     0),  INT16_C(     0),  INT16_C( 18899),  INT16_C(     0), -INT16_C( 16502),  INT16_C(     0),  INT16_C(     0), -INT16_C(  8330),
         INT16_C(     0), -INT16_C( 28902),  INT16_C(     0), -INT16_C(   400),  INT16_C(     0),  INT16_C(  3231),  INT16_C(     0),  INT16_C(     0) } },
    { UINT32_C(1125716592),
      {  INT16_C(  2907), -INT16_C(  6488), -INT16_C( 23094),  INT16_C(  4959), -INT16_C( 10840), -INT16_C( 19469),  INT16_C(  3511), -INT16_C( 15806),
        -INT16_C( 19873), -INT16_C( 31552),  INT16_C( 24510), -INT16_C(  1904), -INT16_C( 25399),  INT16_C( 14824),  INT16_C(   687),  INT16_C(  2684),
         INT16_C(  9229), -INT16_C( 10256),  INT16_C( 20682),  INT16_C( 29419), -INT16_C(  8667), -INT16_C(  9179),  INT16_C( 26603),  INT16_C( 19358),
         INT16_C( 24089), -INT16_C( 10289),  INT16_C( 24509), -INT16_C( 31024), -INT16_C( 18181), -INT16_C( 21825),  INT16_C( 15290), -INT16_C( 14411) },
      {  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C( 10840), -INT16_C( 19469),  INT16_C(  3511),  INT16_C(     0),
         INT16_C(     0), -INT16_C( 31552),  INT16_C(     0),  INT16_C(     0), -INT16_C( 25399),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
         INT16_C(  9229),  INT16_C(     0),  INT16_C(     0),  INT16_C( 29419), -INT16_C(  8667),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
         INT16_C( 24089), -INT16_C( 10289),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C( 15290),  INT16_C(     0) } },
    { UINT32_C( 715105632),
      { -INT16_C( 29963),  INT16_C(  7068), -INT16_C( 16024),  INT16_C( 21495), -INT16_C( 27096),  INT16_C( 16798),  INT16_C( 28148), -INT16_C( 19943),
        -INT16_C(  5684), -INT16_C( 14280), -INT16_C(  1887),  INT16_C( 23666),  INT16_C( 10035), -INT16_C( 27869), -INT16_C( 15667), -INT16_C( 15683),
         INT16_C( 22860), -INT16_C( 19235), -INT16_C( 10982),  INT16_C( 16904), -INT16_C( 22933),  INT16_C( 24452), -INT16_C( 25324), -INT16_C(  8175),
         INT16_C( 19078),  INT16_C( 10152),  INT16_C(  6978),  INT16_C( 30083), -INT16_C( 22718),  INT16_C(  3849), -INT16_C( 14743), -INT16_C( 18734) },
      {  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C( 16798),  INT16_C( 28148),  INT16_C(     0),
        -INT16_C(  5684),  INT16_C(     0), -INT16_C(  1887),  INT16_C(     0),  INT16_C(     0), -INT16_C( 27869),  INT16_C(     0), -INT16_C( 15683),
         INT16_C( 22860), -INT16_C( 19235), -INT16_C( 10982),  INT16_C( 16904), -INT16_C( 22933),  INT16_C(     0),  INT16_C(     0), -INT16_C(  8175),
         INT16_C(     0),  INT16_C( 10152),  INT16_C(     0),  INT16_C( 30083),  INT16_C(     0),  INT16_C(  3849),  INT16_C(     0),  INT16_C(     0) } },
    { UINT32_C( 980070176),
      {  INT16_C( 29316), -INT16_C(  4227),  INT16_C(   281),  INT16_C( 11599),  INT16_C( 24734),  INT16_C(  9229), -INT16_C( 18774), -INT16_C(  5045),
        -INT16_C( 12335),  INT16_C(  4962),  INT16_C( 27510), -INT16_C(  8413), -INT16_C(  2767),  INT16_C( 20885),  INT16_C(   164),  INT16_C( 10636),
         INT16_C(  2418), -INT16_C( 29928),  INT16_C( 26378), -INT16_C( 22344), -INT16_C( 14648),  INT16_C( 29388),  INT16_C(  6012),  INT16_C( 19807),
        -INT16_C( 15898),  INT16_C( 23648), -INT16_C( 31956),  INT16_C( 23868), -INT16_C( 11912),  INT16_C(  7599),  INT16_C( 15313),  INT16_C( 17478) },
      {  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(  9229),  INT16_C(     0),  INT16_C(     0),
        -INT16_C( 12335),  INT16_C(  4962),  INT16_C( 27510), -INT16_C(  8413),  INT16_C(     0),  INT16_C( 20885),  INT16_C(     0),  INT16_C( 10636),
         INT16_C(     0), -INT16_C( 29928),  INT16_C(     0), -INT16_C( 22344),  INT16_C(     0),  INT16_C( 29388),  INT16_C(  6012),  INT16_C(     0),
         INT16_C(     0),  INT16_C( 23648),  INT16_C(     0),  INT16_C( 23868), -INT16_C( 11912),  INT16_C(  7599),  INT16_C(     0),  INT16_C(     0) } },
    { UINT32_C(1322212932),
      { -INT16_C( 30522), -INT16_C( 28938), -INT16_C( 15794), -INT16_C( 13824),  INT16_C( 24537), -INT16_C( 16361),  INT16_C( 30496),  INT16_C( 19484),
         INT16_C( 22779),  INT16_C( 29610),  INT16_C( 22826), -INT16_C(  1136), -INT16_C( 10604), -INT16_C( 10177),  INT16_C(  3893), -INT16_C(  1242),
         INT16_C(  7319), -INT16_C(  6775), -INT16_C( 30242), -INT16_C( 18513), -INT16_C( 14615),  INT16_C(  2423), -INT16_C( 27587),  INT16_C( 14422),
         INT16_C(   236),  INT16_C(  5804),  INT16_C( 15449), -INT16_C(  4846),  INT16_C( 20755),  INT16_C( 18629), -INT16_C(  5280), -INT16_C(  2237) },
      {  INT16_C(     0),  INT16_C(     0), -INT16_C( 15794),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C( 30496),  INT16_C(     0),
         INT16_C(     0),  INT16_C( 29610),  INT16_C( 22826), -INT16_C(  1136), -INT16_C( 10604),  INT16_C(     0),  INT16_C(  3893),  INT16_C(     0),
         INT16_C(  7319), -INT16_C(  6775), -INT16_C( 30242), -INT16_C( 18513),  INT16_C(     0),  INT16_C(     0), -INT16_C( 27587),  INT16_C( 14422),
         INT16_C(     0),  INT16_C(  5804),  INT16_C( 15449), -INT16_C(  4846),  INT16_C(     0),  INT16_C(     0), -INT16_C(  5280),  INT16_C(     0) } },
    { UINT32_C(3856452615),
      { -INT16_C( 29867),  INT16_C( 16028),  INT16_C(  5201), -INT16_C( 28856), -INT16_C( 24920), -INT16_C( 27449),  INT16_C( 29598), -INT16_C(  2133),
        -INT16_C( 16976), -INT16_C( 15388), -INT16_C( 22258),  INT16_C( 28427),  INT16_C( 20116), -INT16_C( 25754),  INT16_C( 17178),  INT16_C( 28544),
         INT16_C(  7374),  INT16_C(  8366), -INT16_C(  2512), -INT16_C( 10065),  INT16_C( 30356),  INT16_C( 12909),  INT16_C(  6378), -INT16_C( 26071),
         INT16_C(  3541), -INT16_C(  7331),  INT16_C( 26806),  INT16_C( 19026), -INT16_C( 17994), -INT16_C( 12059),  INT16_C( 26108), -INT16_C( 13761) },
      { -INT16_C( 29867),  INT16_C( 16028),  INT16_C(  5201),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
         INT16_C(     0),  INT16_C(     0), -INT16_C( 22258),  INT16_C( 28427),  INT16_C(     0),  INT16_C(     0),  INT16_C( 17178),  INT16_C( 28544),
         INT16_C(     0),  INT16_C(     0), -INT16_C(  2512), -INT16_C( 10065),  INT16_C( 30356),  INT16_C(     0),  INT16_C(  6378), -INT16_C( 26071),
         INT16_C(  3541),  INT16_C(     0),  INT16_C( 26806),  INT16_C(     0),  INT16_C(     0), -INT16_C( 12059),  INT16_C( 26108), -INT16_C( 13761) } },
    { UINT32_C(3001740673),
      { -INT16_C( 26141),  INT16_C( 30602), -INT16_C(  2288), -INT16_C(  1367), -INT16_C( 11761), -INT16_C(  7020), -INT16_C(  3617), -INT16_C( 27192),
         INT16_C(  6745),  INT16_C(  4063), -INT16_C( 15149), -INT16_C( 12321),  INT16_C(  7721), -INT16_C( 21606), -INT16_C( 31732), -INT16_C(  4259),
        -INT16_C(  6370),  INT16_C( 11879),  INT16_C(  4319), -INT16_C(  4568), -INT16_C( 17181), -INT16_C( 15661), -INT16_C( 25683),  INT16_C(  1624),
         INT16_C( 14261), -INT16_C( 30443), -INT16_C(  2820),  INT16_C(  9560), -INT16_C(  3566),  INT16_C(  7888),  INT16_C( 11639), -INT16_C( 27378) },
      { -INT16_C( 26141),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C( 27192),
         INT16_C(  6745),  INT16_C(     0), -INT16_C( 15149), -INT16_C( 12321),  INT16_C(     0), -INT16_C( 21606), -INT16_C( 31732), -INT16_C(  4259),
         INT16_C(     0),  INT16_C( 11879),  INT16_C(     0), -INT16_C(  4568),  INT16_C(     0), -INT16_C( 15661), -INT16_C( 25683),  INT16_C(  1624),
         INT16_C(     0), -INT16_C( 30443),  INT16_C(     0),  INT16_C(     0), -INT16_C(  3566),  INT16_C(  7888),  INT16_C(     0), -INT16_C( 27378) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i a = simde_mm512_loadu_epi16(test_vec[i].a);
    int16_t r[sizeof(simde__m512i) / sizeof(int16_t)] = {0};
    simde_mm512_mask_storeu_epi16(r, test_vec[i].k, a);
    simde_assert_equal_vi16(sizeof(r) / sizeof(r[0]), r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask32 k = simde_test_x86_random_mmask32();
    simde__m512i a = simde_test_x86_random_i16x32();
    int16_t r[sizeof(simde__m512i) / sizeof(int16_t)] = {0};
    simde_mm512_mask_storeu_epi16(r, k, a);

    simde_test_x86_write_mmask32(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i16x32(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_vi16(2, sizeof(r) / sizeof(r[0]), r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_storeu_ps (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde_float32 a[16];
    const simde_float32 r[16];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(   397.85), SIMDE_FLOAT32_C(   280.50), SIMDE_FLOAT32_C(  -482.10), SIMDE_FLOAT32_C(  -764.38),
        SIMDE_FLOAT32_C(   375.26), SIMDE_FLOAT32_C(  -613.57), SIMDE_FLOAT32_C(    56.03), SIMDE_FLOAT32_C(   417.16),
        SIMDE_FLOAT32_C(  -424.36), SIMDE_FLOAT32_C(    64.48), SIMDE_FLOAT32_C(     0.84), SIMDE_FLOAT32_C(   101.24),
        SIMDE_FLOAT32_C(  -965.83), SIMDE_FLOAT32_C(   916.49), SIMDE_FLOAT32_C(   799.09), SIMDE_FLOAT32_C(   628.08) },
      { SIMDE_FLOAT32_C(   397.85), SIMDE_FLOAT32_C(   280.50), SIMDE_FLOAT32_C(  -482.10), SIMDE_FLOAT32_C(  -764.38),
        SIMDE_FLOAT32_C(   375.26), SIMDE_FLOAT32_C(  -613.57), SIMDE_FLOAT32_C(    56.03), SIMDE_FLOAT32_C(   417.16),
        SIMDE_FLOAT32_C(  -424.36), SIMDE_FLOAT32_C(    64.48), SIMDE_FLOAT32_C(     0.84), SIMDE_FLOAT32_C(   101.24),
        SIMDE_FLOAT32_C(  -965.83), SIMDE_FLOAT32_C(   916.49), SIMDE_FLOAT32_C(   799.09), SIMDE_FLOAT32_C(   628.08) } },
    { { SIMDE_FLOAT32_C(  -588.70), SIMDE_FLOAT32_C(   688.61), SIMDE_FLOAT32_C(   202.01), SIMDE_FLOAT32_C(  -610.64),
        SIMDE_FLOAT32_C(   838.07), SIMDE_FLOAT32_C(  -733.40), SIMDE_FLOAT32_C(  -127.00), SIMDE_FLOAT32_C(   993.35),
        SIMDE_FLOAT32_C(  -249.66), SIMDE_FLOAT32_C(   -45.23), SIMDE_FLOAT32_C(   849.71), SIMDE_FLOAT32_C(   -85.52),
        SIMDE_FLOAT32_C(   193.59), SIMDE_FLOAT32_C(  -257.46), SIMDE_FLOAT32_C(   827.23), SIMDE_FLOAT32_C(  -408.56) },
      { SIMDE_FLOAT32_C(  -588.70), SIMDE_FLOAT32_C(   688.61), SIMDE_FLOAT32_C(   202.01), SIMDE_FLOAT32_C(  -610.64),
        SIMDE_FLOAT32_C(   838.07), SIMDE_FLOAT32_C(  -733.40), SIMDE_FLOAT32_C(  -127.00), SIMDE_FLOAT32_C(   993.35),
        SIMDE_FLOAT32_C(  -249.66), SIMDE_FLOAT32_C(   -45.23), SIMDE_FLOAT32_C(   849.71), SIMDE_FLOAT32_C(   -85.52),
        SIMDE_FLOAT32_C(   193.59), SIMDE_FLOAT32_C(  -257.46), SIMDE_FLOAT32_C(   827.23), SIMDE_FLOAT32_C(  -408.56) } },
    { { SIMDE_FLOAT32_C(  -976.96), SIMDE_FLOAT32_C(  -654.87), SIMDE_FLOAT32_C(  -172.94), SIMDE_FLOAT32_C(   398.29),
        SIMDE_FLOAT32_C(  -268.45), SIMDE_FLOAT32_C(   883.09), SIMDE_FLOAT32_C(  -184.55), SIMDE_FLOAT32_C(   307.20),
        SIMDE_FLOAT32_C(   -52.43), SIMDE_FLOAT32_C(   816.29), SIMDE_FLOAT32_C(  -591.56), SIMDE_FLOAT32_C(   -18.26),
        SIMDE_FLOAT32_C(   732.78), SIMDE_FLOAT32_C(  -792.48), SIMDE_FLOAT32_C(  -390.18), SIMDE_FLOAT32_C(  -855.92) },
      { SIMDE_FLOAT32_C(  -976.96), SIMDE_FLOAT32_C(  -654.87), SIMDE_FLOAT32_C(  -172.94), SIMDE_FLOAT32_C(   398.29),
        SIMDE_FLOAT32_C(  -268.45), SIMDE_FLOAT32_C(   883.09), SIMDE_FLOAT32_C(  -184.55), SIMDE_FLOAT32_C(   307.20),
        SIMDE_FLOAT32_C(   -52.43), SIMDE_FLOAT32_C(   816.29), SIMDE_FLOAT32_C(  -591.56), SIMDE_FLOAT32_C(   -18.26),
        SIMDE_FLOAT32_C(   732.78), SIMDE_FLOAT32_C(  -792.48), SIMDE_FLOAT32_C(  -390.18), SIMDE_FLOAT32_C(  -855.92) } },
    { { SIMDE_FLOAT32_C(   896.13), SIMDE_FLOAT32_C(   811.83), SIMDE_FLOAT32_C(  -466.56), SIMDE_FLOAT32_C(   734.20),
        SIMDE_FLOAT32_C(  -921.57), SIMDE_FLOAT32_C(   406.44), SIMDE_FLOAT32_C(   727.55), SIMDE_FLOAT32_C(  -171.23),
        SIMDE_FLOAT32_C(  -638.79), SIMDE_FLOAT32_C(   577.26), SIMDE_FLOAT32_C(   743.25), SIMDE_FLOAT32_C(   554.80),
        SIMDE_FLOAT32_C(  -680.21), SIMDE_FLOAT32_C(   570.48), SIMDE_FLOAT32_C(  -853.75), SIMDE_FLOAT32_C(  -657.17) },
      { SIMDE_FLOAT32_C(   896.13), SIMDE_FLOAT32_C(   811.83), SIMDE_FLOAT32_C(  -466.56), SIMDE_FLOAT32_C(   734.20),
        SIMDE_FLOAT32_C(  -921.57), SIMDE_FLOAT32_C(   406.44), SIMDE_FLOAT32_C(   727.55), SIMDE_FLOAT32_C(  -171.23),
        SIMDE_FLOAT32_C(  -638.79), SIMDE_FLOAT32_C(   577.26), SIMDE_FLOAT32_C(   743.25), SIMDE_FLOAT32_C(   554.80),
        SIMDE_FLOAT32_C(  -680.21), SIMDE_FLOAT32_C(   570.48), SIMDE_FLOAT32_C(  -853.75), SIMDE_FLOAT32_C(  -657.17) } },
    { { SIMDE_FLOAT32_C(   915.61), SIMDE_FLOAT32_C(   -26.70), SIMDE_FLOAT32_C(   741.12), SIMDE_FLOAT32_C(  -352.84),
        SIMDE_FLOAT32_C(  -143.61), SIMDE_FLOAT32_C(  -443.43), SIMDE_FLOAT32_C(   954.36), SIMDE_FLOAT32_C(   803.96),
        SIMDE_FLOAT32_C(  -627.14), SIMDE_FLOAT32_C(  -637.21), SIMDE_FLOAT32_C(  -214.30), SIMDE_FLOAT32_C(  -894.36),
        SIMDE_FLOAT32_C(  -429.68), SIMDE_FLOAT32_C(   395.52), SIMDE_FLOAT32_C(  -750.28), SIMDE_FLOAT32_C(  -533.55) },
      { SIMDE_FLOAT32_C(   915.61), SIMDE_FLOAT32_C(   -26.70), SIMDE_FLOAT32_C(   741.12), SIMDE_FLOAT32_C(  -352.84),
        SIMDE_FLOAT32_C(  -143.61), SIMDE_FLOAT32_C(  -443.43), SIMDE_FLOAT32_C(   954.36), SIMDE_FLOAT32_C(   803.96),
        SIMDE_FLOAT32_C(  -627.14), SIMDE_FLOAT32_C(  -637.21), SIMDE_FLOAT32_C(  -214.30), SIMDE_FLOAT32_C(  -894.36),
        SIMDE_FLOAT32_C(  -429.68), SIMDE_FLOAT32_C(   395.52), SIMDE_FLOAT32_C(  -750.28), SIMDE_FLOAT32_C(  -533.55) } },
    { { SIMDE_FLOAT32_C(   207.35), SIMDE_FLOAT32_C(  -216.84), SIMDE_FLOAT32_C(  -799.36), SIMDE_FLOAT32_C(   285.78),
        SIMDE_FLOAT32_C(  -810.40), SIMDE_FLOAT32_C(   928.19), SIMDE_FLOAT32_C(  -885.45), SIMDE_FLOAT32_C(  -449.19),
        SIMDE_FLOAT32_C(   505.45), SIMDE_FLOAT32_C(   857.81), SIMDE_FLOAT32_C(  -894.39), SIMDE_FLOAT32_C(   825.24),
        SIMDE_FLOAT32_C(   428.29), SIMDE_FLOAT32_C(  -748.14), SIMDE_FLOAT32_C(  -831.93), SIMDE_FLOAT32_C(   343.89) },
      { SIMDE_FLOAT32_C(   207.35), SIMDE_FLOAT32_C(  -216.84), SIMDE_FLOAT32_C(  -799.36), SIMDE_FLOAT32_C(   285.78),
        SIMDE_FLOAT32_C(  -810.40), SIMDE_FLOAT32_C(   928.19), SIMDE_FLOAT32_C(  -885.45), SIMDE_FLOAT32_C(  -449.19),
        SIMDE_FLOAT32_C(   505.45), SIMDE_FLOAT32_C(   857.81), SIMDE_FLOAT32_C(  -894.39), SIMDE_FLOAT32_C(   825.24),
        SIMDE_FLOAT32_C(   428.29), SIMDE_FLOAT32_C(  -748.14), SIMDE_FLOAT32_C(  -831.93), SIMDE_FLOAT32_C(   343.89) } },
    { { SIMDE_FLOAT32_C(   225.16), SIMDE_FLOAT32_C(   909.19), SIMDE_FLOAT32_C(   991.05), SIMDE_FLOAT32_C(  -918.45),
        SIMDE_FLOAT32_C(  -534.23), SIMDE_FLOAT32_C(   945.41), SIMDE_FLOAT32_C(   885.51), SIMDE_FLOAT32_C(  -161.37),
        SIMDE_FLOAT32_C(  -691.80), SIMDE_FLOAT32_C(  -328.80), SIMDE_FLOAT32_C(   -55.73), SIMDE_FLOAT32_C(  -121.48),
        SIMDE_FLOAT32_C(  -933.28), SIMDE_FLOAT32_C(   193.99), SIMDE_FLOAT32_C(   344.96), SIMDE_FLOAT32_C(   274.08) },
      { SIMDE_FLOAT32_C(   225.16), SIMDE_FLOAT32_C(   909.19), SIMDE_FLOAT32_C(   991.05), SIMDE_FLOAT32_C(  -918.45),
        SIMDE_FLOAT32_C(  -534.23), SIMDE_FLOAT32_C(   945.41), SIMDE_FLOAT32_C(   885.51), SIMDE_FLOAT32_C(  -161.37),
        SIMDE_FLOAT32_C(  -691.80), SIMDE_FLOAT32_C(  -328.80), SIMDE_FLOAT32_C(   -55.73), SIMDE_FLOAT32_C(  -121.48),
        SIMDE_FLOAT32_C(  -933.28), SIMDE_FLOAT32_C(   193.99), SIMDE_FLOAT32_C(   344.96), SIMDE_FLOAT32_C(   274.08) } },
    { { SIMDE_FLOAT32_C(   977.14), SIMDE_FLOAT32_C(   545.61), SIMDE_FLOAT32_C(  -440.14), SIMDE_FLOAT32_C(  -833.26),
        SIMDE_FLOAT32_C(   473.80), SIMDE_FLOAT32_C(  -325.59), SIMDE_FLOAT32_C(  -282.45), SIMDE_FLOAT32_C(   -20.75),
        SIMDE_FLOAT32_C(  -467.78), SIMDE_FLOAT32_C(  -176.84), SIMDE_FLOAT32_C(  -195.51), SIMDE_FLOAT32_C(   960.51),
        SIMDE_FLOAT32_C(    75.02), SIMDE_FLOAT32_C(   -27.44), SIMDE_FLOAT32_C(   304.40), SIMDE_FLOAT32_C(  -699.82) },
      { SIMDE_FLOAT32_C(   977.14), SIMDE_FLOAT32_C(   545.61), SIMDE_FLOAT32_C(  -440.14), SIMDE_FLOAT32_C(  -833.26),
        SIMDE_FLOAT32_C(   473.80), SIMDE_FLOAT32_C(  -325.59), SIMDE_FLOAT32_C(  -282.45), SIMDE_FLOAT32_C(   -20.75),
        SIMDE_FLOAT32_C(  -467.78), SIMDE_FLOAT32_C(  -176.84), SIMDE_FLOAT32_C(  -195.51), SIMDE_FLOAT32_C(   960.51),
        SIMDE_FLOAT32_C(    75.02), SIMDE_FLOAT32_C(   -27.44), SIMDE_FLOAT32_C(   304.40), SIMDE_FLOAT32_C(  -699.82) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512 a = simde_mm512_loadu_ps(test_vec[i].a);
    simde_float32 r[sizeof(simde__m512) / sizeof(simde_float32)] = {0};
    simde_mm512_storeu_ps(r, a);
    simde_assert_equal_vf32(sizeof(r) / sizeof(r[0]), r, test_vec[i].r, 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m512 a = simde_test_x86_random_f32x16(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
    simde_float32 r[sizeof(simde__m512) / sizeof(simde_float32)] = {0};
    simde_mm512_storeu_ps(r, a);

    simde_test_x86_write_f32x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_vf32(2, sizeof(r) / sizeof(r[0]), r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_mask_storeu_ps (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask16 k;
    const simde_float32 a[16];
    const simde_float32 r[16];
  } test_vec[] = {
    { UINT32_C(      7865),
      { SIMDE_FLOAT32_C(  -286.88), SIMDE_FLOAT32_C(  -712.57), SIMDE_FLOAT32_C(   535.33), SIMDE_FLOAT32_C(  -422.10),
        SIMDE_FLOAT32_C(   535.50), SIMDE_FLOAT32_C(   -31.61), SIMDE_FLOAT32_C(   662.71), SIMDE_FLOAT32_C(   715.73),
        SIMDE_FLOAT32_C(   -24.31), SIMDE_FLOAT32_C(   499.53), SIMDE_FLOAT32_C(   480.56), SIMDE_FLOAT32_C(  -172.05),
        SIMDE_FLOAT32_C(   947.38), SIMDE_FLOAT32_C(  -179.67), SIMDE_FLOAT32_C(  -314.08), SIMDE_FLOAT32_C(  -467.39) },
      { SIMDE_FLOAT32_C(  -286.88), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -422.10),
        SIMDE_FLOAT32_C(   535.50), SIMDE_FLOAT32_C(   -31.61), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   715.73),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   499.53), SIMDE_FLOAT32_C(   480.56), SIMDE_FLOAT32_C(  -172.05),
        SIMDE_FLOAT32_C(   947.38), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
    { UINT32_C(     13393),
      { SIMDE_FLOAT32_C(  -376.40), SIMDE_FLOAT32_C(   155.39), SIMDE_FLOAT32_C(   746.47), SIMDE_FLOAT32_C(   426.83),
        SIMDE_FLOAT32_C(  -220.63), SIMDE_FLOAT32_C(    72.51), SIMDE_FLOAT32_C(  -599.14), SIMDE_FLOAT32_C(  -398.66),
        SIMDE_FLOAT32_C(   715.40), SIMDE_FLOAT32_C(   828.16), SIMDE_FLOAT32_C(  -864.09), SIMDE_FLOAT32_C(    74.53),
        SIMDE_FLOAT32_C(   206.13), SIMDE_FLOAT32_C(  -150.97), SIMDE_FLOAT32_C(   361.96), SIMDE_FLOAT32_C(  -258.54) },
      { SIMDE_FLOAT32_C(  -376.40), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(  -220.63), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -599.14), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -864.09), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(   206.13), SIMDE_FLOAT32_C(  -150.97), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
    { UINT32_C(     29383),
      { SIMDE_FLOAT32_C(   709.85), SIMDE_FLOAT32_C(    89.64), SIMDE_FLOAT32_C(  -386.81), SIMDE_FLOAT32_C(  -314.46),
        SIMDE_FLOAT32_C(  -410.82), SIMDE_FLOAT32_C(  -906.25), SIMDE_FLOAT32_C(   513.48), SIMDE_FLOAT32_C(  -463.44),
        SIMDE_FLOAT32_C(   -85.92), SIMDE_FLOAT32_C(  -800.59), SIMDE_FLOAT32_C(    69.17), SIMDE_FLOAT32_C(  -147.43),
        SIMDE_FLOAT32_C(  -254.83), SIMDE_FLOAT32_C(   692.76), SIMDE_FLOAT32_C(  -992.04), SIMDE_FLOAT32_C(  -508.36) },
      { SIMDE_FLOAT32_C(   709.85), SIMDE_FLOAT32_C(    89.64), SIMDE_FLOAT32_C(  -386.81), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   513.48), SIMDE_FLOAT32_C(  -463.44),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -800.59), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(  -254.83), SIMDE_FLOAT32_C(   692.76), SIMDE_FLOAT32_C(  -992.04), SIMDE_FLOAT32_C(     0.00) } },
    { UINT32_C(     58153),
      { SIMDE_FLOAT32_C(   564.15), SIMDE_FLOAT32_C(   520.45), SIMDE_FLOAT32_C(   388.67), SIMDE_FLOAT32_C(   279.56),
        SIMDE_FLOAT32_C(   348.62), SIMDE_FLOAT32_C(   524.58), SIMDE_FLOAT32_C(  -645.91), SIMDE_FLOAT32_C(  -445.25),
        SIMDE_FLOAT32_C(  -626.39), SIMDE_FLOAT32_C(   716.05), SIMDE_FLOAT32_C(   296.21), SIMDE_FLOAT32_C(   800.54),
        SIMDE_FLOAT32_C(  -386.50), SIMDE_FLOAT32_C(     6.06), SIMDE_FLOAT32_C(  -109.82), SIMDE_FLOAT32_C(   226.69) },
      { SIMDE_FLOAT32_C(   564.15), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   279.56),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   524.58), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(  -626.39), SIMDE_FLOAT32_C(   716.05), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     6.06), SIMDE_FLOAT32_C(  -109.82), SIMDE_FLOAT32_C(   226.69) } },
    { UINT32_C(     54955),
      { SIMDE_FLOAT32_C(   320.44), SIMDE_FLOAT32_C(   205.08), SIMDE_FLOAT32_C(  -984.08), SIMDE_FLOAT32_C(  -765.48),
        SIMDE_FLOAT32_C(   404.49), SIMDE_FLOAT32_C(    85.08), SIMDE_FLOAT32_C(    87.10), SIMDE_FLOAT32_C(  -850.34),
        SIMDE_FLOAT32_C(  -222.15), SIMDE_FLOAT32_C(    95.06), SIMDE_FLOAT32_C(  -358.70), SIMDE_FLOAT32_C(   897.44),
        SIMDE_FLOAT32_C(   882.39), SIMDE_FLOAT32_C(  -794.55), SIMDE_FLOAT32_C(   417.89), SIMDE_FLOAT32_C(   271.06) },
      { SIMDE_FLOAT32_C(   320.44), SIMDE_FLOAT32_C(   205.08), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -765.48),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(    85.08), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -850.34),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(    95.06), SIMDE_FLOAT32_C(  -358.70), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(   882.39), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   417.89), SIMDE_FLOAT32_C(   271.06) } },
    { UINT32_C(     19422),
      { SIMDE_FLOAT32_C(  -204.36), SIMDE_FLOAT32_C(   839.09), SIMDE_FLOAT32_C(   321.26), SIMDE_FLOAT32_C(   169.25),
        SIMDE_FLOAT32_C(   555.14), SIMDE_FLOAT32_C(  -382.52), SIMDE_FLOAT32_C(   -30.21), SIMDE_FLOAT32_C(  -831.36),
        SIMDE_FLOAT32_C(   623.54), SIMDE_FLOAT32_C(   859.97), SIMDE_FLOAT32_C(   395.33), SIMDE_FLOAT32_C(   315.14),
        SIMDE_FLOAT32_C(   339.33), SIMDE_FLOAT32_C(  -284.22), SIMDE_FLOAT32_C(  -479.78), SIMDE_FLOAT32_C(   355.24) },
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   839.09), SIMDE_FLOAT32_C(   321.26), SIMDE_FLOAT32_C(   169.25),
        SIMDE_FLOAT32_C(   555.14), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   -30.21), SIMDE_FLOAT32_C(  -831.36),
        SIMDE_FLOAT32_C(   623.54), SIMDE_FLOAT32_C(   859.97), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   315.14),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -479.78), SIMDE_FLOAT32_C(     0.00) } },
    { UINT32_C(     34841),
      { SIMDE_FLOAT32_C(  -559.67), SIMDE_FLOAT32_C(  -962.60), SIMDE_FLOAT32_C(  -925.63), SIMDE_FLOAT32_C(   218.17),
        SIMDE_FLOAT32_C(   132.45), SIMDE_FLOAT32_C(  -284.34), SIMDE_FLOAT32_C(   115.61), SIMDE_FLOAT32_C(    14.84),
        SIMDE_FLOAT32_C(   -78.89), SIMDE_FLOAT32_C(  -466.49), SIMDE_FLOAT32_C(  -714.10), SIMDE_FLOAT32_C(  -593.88),
        SIMDE_FLOAT32_C(   300.02), SIMDE_FLOAT32_C(    81.54), SIMDE_FLOAT32_C(  -754.79), SIMDE_FLOAT32_C(  -378.72) },
      { SIMDE_FLOAT32_C(  -559.67), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   218.17),
        SIMDE_FLOAT32_C(   132.45), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -593.88),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -378.72) } },
    { UINT32_C(     16183),
      { SIMDE_FLOAT32_C(   238.76), SIMDE_FLOAT32_C(   220.58), SIMDE_FLOAT32_C(   968.99), SIMDE_FLOAT32_C(  -137.70),
        SIMDE_FLOAT32_C(    80.55), SIMDE_FLOAT32_C(   364.32), SIMDE_FLOAT32_C(  -822.56), SIMDE_FLOAT32_C(  -580.12),
        SIMDE_FLOAT32_C(  -919.90), SIMDE_FLOAT32_C(  -302.34), SIMDE_FLOAT32_C(   775.12), SIMDE_FLOAT32_C(    30.40),
        SIMDE_FLOAT32_C(  -377.63), SIMDE_FLOAT32_C(  -784.55), SIMDE_FLOAT32_C(    67.80), SIMDE_FLOAT32_C(  -303.26) },
      { SIMDE_FLOAT32_C(   238.76), SIMDE_FLOAT32_C(   220.58), SIMDE_FLOAT32_C(   968.99), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(    80.55), SIMDE_FLOAT32_C(   364.32), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(  -919.90), SIMDE_FLOAT32_C(  -302.34), SIMDE_FLOAT32_C(   775.12), SIMDE_FLOAT32_C(    30.40),
        SIMDE_FLOAT32_C(  -377.63), SIMDE_FLOAT32_C(  -784.55), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512 a = simde_mm512_loadu_ps(test_vec[i].a);
    simde_float32 r[sizeof(simde__m512) / sizeof(simde_float32)] = {0};
    simde_mm512_mask_storeu_ps(r, test_vec[i].k, a);
    simde_assert_equal_vf32(sizeof(r) / sizeof(r[0]), r, test_vec[i].r, 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask16 k = simde_test_x86_random_mmask16();
    simde__m512 a = simde_test_x86_random_f32x16(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
    simde_float32 r[sizeof(simde__m512) / sizeof(simde_float32)] = {0};
    simde_mm512_mask_storeu_ps(r, k, a);

    simde_test_x86_write_mmask32(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f32x16(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_vf32(2, sizeof(r) / sizeof(r[0]), r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}
SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_storeu_epi8)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_storeu_epi16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_mask_storeu_epi16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_storeu_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_storeu_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_storeu_epi16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_storeu_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_storeu_ps)
SIMDE_TEST_FUNC_LIST_END

#include <test/x86/avx512/test-avx512-footer.h>
