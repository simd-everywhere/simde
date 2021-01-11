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

#define SIMDE_TEST_X86_AVX512_INSN srav

#include <test/x86/avx512/test-avx512.h>
#include <simde/x86/avx512/srav.h>

static int
test_simde_mm512_srav_epi16 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const int16_t a[32];
    const int16_t b[32];
    const int16_t r[32];
  } test_vec[] = {
    { { -INT16_C( 26126),  INT16_C(  9315),  INT16_C( 20615), -INT16_C( 25676),  INT16_C( 25129), -INT16_C( 13781), -INT16_C( 22935), -INT16_C( 22311),
        -INT16_C(   968),  INT16_C( 28073), -INT16_C(  1215),  INT16_C(  1561), -INT16_C(  5797),  INT16_C( 15623), -INT16_C( 24120), -INT16_C( 17815),
        -INT16_C( 13254), -INT16_C( 15649), -INT16_C( 27875),  INT16_C( 18013), -INT16_C( 30475),  INT16_C( 24080), -INT16_C(  5841),  INT16_C( 26374),
        -INT16_C( 20250),  INT16_C( 10196), -INT16_C(  4693),  INT16_C(  1581),  INT16_C( 13782), -INT16_C( 24765), -INT16_C( 21290),  INT16_C(  4185) },
      {  INT16_C(     3),  INT16_C(     9),  INT16_C(     2),  INT16_C(    12),  INT16_C(    14),  INT16_C(    14),  INT16_C(     2),  INT16_C(    11),
         INT16_C(     2),  INT16_C(     8),  INT16_C(     0),  INT16_C(    14),  INT16_C(    12),  INT16_C(     1),  INT16_C(    13),  INT16_C(    14),
         INT16_C(    15),  INT16_C(    14),  INT16_C(     5),  INT16_C(    14),  INT16_C(    12),  INT16_C(     2),  INT16_C(     1),  INT16_C(    12),
         INT16_C(    11),  INT16_C(     4),  INT16_C(    12),  INT16_C(     1),  INT16_C(    11),  INT16_C(     0),  INT16_C(     5),  INT16_C(    11) },
      { -INT16_C(  3266),  INT16_C(    18),  INT16_C(  5153), -INT16_C(     7),  INT16_C(     1), -INT16_C(     1), -INT16_C(  5734), -INT16_C(    11),
        -INT16_C(   242),  INT16_C(   109), -INT16_C(  1215),  INT16_C(     0), -INT16_C(     2),  INT16_C(  7811), -INT16_C(     3), -INT16_C(     2),
        -INT16_C(     1), -INT16_C(     1), -INT16_C(   872),  INT16_C(     1), -INT16_C(     8),  INT16_C(  6020), -INT16_C(  2921),  INT16_C(     6),
        -INT16_C(    10),  INT16_C(   637), -INT16_C(     2),  INT16_C(   790),  INT16_C(     6), -INT16_C( 24765), -INT16_C(   666),  INT16_C(     2) } },
    { {  INT16_C( 31316), -INT16_C( 32362),  INT16_C( 15066),  INT16_C(  9574),  INT16_C( 13054), -INT16_C(  6075),  INT16_C(  8268), -INT16_C( 30040),
        -INT16_C(  5667), -INT16_C( 22056),  INT16_C(  3505),  INT16_C( 17338), -INT16_C(  6456),  INT16_C( 25163),  INT16_C( 16956), -INT16_C( 28651),
        -INT16_C( 21572), -INT16_C( 27119),  INT16_C( 30693), -INT16_C(  6981),  INT16_C(   169), -INT16_C(  2356),  INT16_C( 29984), -INT16_C(   640),
         INT16_C( 22622),  INT16_C(  4263),  INT16_C( 24933),  INT16_C( 11603), -INT16_C( 24761), -INT16_C( 31601), -INT16_C( 23327), -INT16_C( 25324) },
      {  INT16_C(     2),  INT16_C(     3),  INT16_C(    14),  INT16_C(     4),  INT16_C(    14),  INT16_C(     1),  INT16_C(    11),  INT16_C(    11),
         INT16_C(    11),  INT16_C(     7),  INT16_C(     1),  INT16_C(     5),  INT16_C(     3),  INT16_C(     9),  INT16_C(    15),  INT16_C(     2),
         INT16_C(     6),  INT16_C(    11),  INT16_C(     7),  INT16_C(     4),  INT16_C(     3),  INT16_C(    11),  INT16_C(     6),  INT16_C(     1),
         INT16_C(     3),  INT16_C(     3),  INT16_C(     3),  INT16_C(     1),  INT16_C(     7),  INT16_C(     4),  INT16_C(    14),  INT16_C(     8) },
      {  INT16_C(  7829), -INT16_C(  4046),  INT16_C(     0),  INT16_C(   598),  INT16_C(     0), -INT16_C(  3038),  INT16_C(     4), -INT16_C(    15),
        -INT16_C(     3), -INT16_C(   173),  INT16_C(  1752),  INT16_C(   541), -INT16_C(   807),  INT16_C(    49),  INT16_C(     0), -INT16_C(  7163),
        -INT16_C(   338), -INT16_C(    14),  INT16_C(   239), -INT16_C(   437),  INT16_C(    21), -INT16_C(     2),  INT16_C(   468), -INT16_C(   320),
         INT16_C(  2827),  INT16_C(   532),  INT16_C(  3116),  INT16_C(  5801), -INT16_C(   194), -INT16_C(  1976), -INT16_C(     2), -INT16_C(    99) } },
    { { -INT16_C( 13225), -INT16_C( 19388),  INT16_C( 17733), -INT16_C( 23806),  INT16_C( 24707),  INT16_C( 32347), -INT16_C( 12852), -INT16_C(  4722),
         INT16_C(  6151),  INT16_C( 24100), -INT16_C( 17847), -INT16_C( 20111),  INT16_C(  8241), -INT16_C( 24589),  INT16_C( 24585),  INT16_C( 24618),
         INT16_C( 28205),  INT16_C( 29204),  INT16_C(  5812),  INT16_C( 14101),  INT16_C( 28790),  INT16_C( 17078),  INT16_C( 17469),  INT16_C( 17711),
         INT16_C( 21597), -INT16_C( 22877),  INT16_C(  5134),  INT16_C( 16215),  INT16_C( 19252),  INT16_C( 15839),  INT16_C(  2475), -INT16_C( 10083) },
      {  INT16_C(    11),  INT16_C(     2),  INT16_C(     5),  INT16_C(     3),  INT16_C(     1),  INT16_C(     0),  INT16_C(    11),  INT16_C(    11),
         INT16_C(    15),  INT16_C(     1),  INT16_C(    11),  INT16_C(     3),  INT16_C(     3),  INT16_C(    10),  INT16_C(     1),  INT16_C(    11),
         INT16_C(    13),  INT16_C(     9),  INT16_C(     4),  INT16_C(     0),  INT16_C(     5),  INT16_C(    11),  INT16_C(     6),  INT16_C(     0),
         INT16_C(    13),  INT16_C(     6),  INT16_C(     7),  INT16_C(     8),  INT16_C(     1),  INT16_C(    13),  INT16_C(    12),  INT16_C(     0) },
      { -INT16_C(     7), -INT16_C(  4847),  INT16_C(   554), -INT16_C(  2976),  INT16_C( 12353),  INT16_C( 32347), -INT16_C(     7), -INT16_C(     3),
         INT16_C(     0),  INT16_C( 12050), -INT16_C(     9), -INT16_C(  2514),  INT16_C(  1030), -INT16_C(    25),  INT16_C( 12292),  INT16_C(    12),
         INT16_C(     3),  INT16_C(    57),  INT16_C(   363),  INT16_C( 14101),  INT16_C(   899),  INT16_C(     8),  INT16_C(   272),  INT16_C( 17711),
         INT16_C(     2), -INT16_C(   358),  INT16_C(    40),  INT16_C(    63),  INT16_C(  9626),  INT16_C(     1),  INT16_C(     0), -INT16_C( 10083) } },
    { {  INT16_C( 27799), -INT16_C( 14184),  INT16_C( 27564),  INT16_C(  1738), -INT16_C(  9792), -INT16_C( 14659),  INT16_C( 11834), -INT16_C( 27951),
        -INT16_C(  4351), -INT16_C( 29452), -INT16_C( 27296),  INT16_C(   538),  INT16_C( 22706), -INT16_C(  5410),  INT16_C( 27933), -INT16_C( 19219),
        -INT16_C( 31271), -INT16_C( 31364),  INT16_C( 18161), -INT16_C( 20085),  INT16_C( 18463),  INT16_C( 23160),  INT16_C( 18807),  INT16_C( 30956),
        -INT16_C(  8135), -INT16_C( 26364),  INT16_C(  7797),  INT16_C( 10139),  INT16_C( 31094), -INT16_C( 27887), -INT16_C(    26), -INT16_C( 16569) },
      {  INT16_C(    12),  INT16_C(     7),  INT16_C(    13),  INT16_C(     2),  INT16_C(     9),  INT16_C(     9),  INT16_C(     7),  INT16_C(     2),
         INT16_C(     0),  INT16_C(    12),  INT16_C(     5),  INT16_C(    10),  INT16_C(    15),  INT16_C(    11),  INT16_C(     7),  INT16_C(     8),
         INT16_C(    11),  INT16_C(     4),  INT16_C(     1),  INT16_C(    10),  INT16_C(    15),  INT16_C(    10),  INT16_C(     3),  INT16_C(    11),
         INT16_C(     8),  INT16_C(     7),  INT16_C(     6),  INT16_C(    10),  INT16_C(     4),  INT16_C(     6),  INT16_C(    13),  INT16_C(     0) },
      {  INT16_C(     6), -INT16_C(   111),  INT16_C(     3),  INT16_C(   434), -INT16_C(    20), -INT16_C(    29),  INT16_C(    92), -INT16_C(  6988),
        -INT16_C(  4351), -INT16_C(     8), -INT16_C(   853),  INT16_C(     0),  INT16_C(     0), -INT16_C(     3),  INT16_C(   218), -INT16_C(    76),
        -INT16_C(    16), -INT16_C(  1961),  INT16_C(  9080), -INT16_C(    20),  INT16_C(     0),  INT16_C(    22),  INT16_C(  2350),  INT16_C(    15),
        -INT16_C(    32), -INT16_C(   206),  INT16_C(   121),  INT16_C(     9),  INT16_C(  1943), -INT16_C(   436), -INT16_C(     1), -INT16_C( 16569) } },
    { { -INT16_C(  8822),  INT16_C(  5454), -INT16_C( 15621), -INT16_C( 18248), -INT16_C(  4933),  INT16_C(  9054),  INT16_C(  9511),  INT16_C( 28636),
         INT16_C( 22950),  INT16_C( 32225), -INT16_C(  2877),  INT16_C( 11043),  INT16_C( 32571), -INT16_C(   112),  INT16_C( 30543), -INT16_C(  9726),
         INT16_C( 20564),  INT16_C( 20719), -INT16_C( 22765), -INT16_C( 12792),  INT16_C( 26259), -INT16_C( 17423), -INT16_C( 12917),  INT16_C( 12842),
         INT16_C(  2855), -INT16_C(  5457), -INT16_C( 11265),  INT16_C( 14870), -INT16_C( 22958), -INT16_C( 24263),  INT16_C( 15389),  INT16_C( 29307) },
      {  INT16_C(     6),  INT16_C(     9),  INT16_C(    12),  INT16_C(    10),  INT16_C(     5),  INT16_C(    11),  INT16_C(     8),  INT16_C(     5),
         INT16_C(     9),  INT16_C(     9),  INT16_C(     5),  INT16_C(    12),  INT16_C(     0),  INT16_C(     1),  INT16_C(    14),  INT16_C(    13),
         INT16_C(     4),  INT16_C(     5),  INT16_C(    13),  INT16_C(     4),  INT16_C(     6),  INT16_C(     6),  INT16_C(    15),  INT16_C(     8),
         INT16_C(    15),  INT16_C(     0),  INT16_C(    14),  INT16_C(     4),  INT16_C(     2),  INT16_C(     3),  INT16_C(    14),  INT16_C(     5) },
      { -INT16_C(   138),  INT16_C(    10), -INT16_C(     4), -INT16_C(    18), -INT16_C(   155),  INT16_C(     4),  INT16_C(    37),  INT16_C(   894),
         INT16_C(    44),  INT16_C(    62), -INT16_C(    90),  INT16_C(     2),  INT16_C( 32571), -INT16_C(    56),  INT16_C(     1), -INT16_C(     2),
         INT16_C(  1285),  INT16_C(   647), -INT16_C(     3), -INT16_C(   800),  INT16_C(   410), -INT16_C(   273), -INT16_C(     1),  INT16_C(    50),
         INT16_C(     0), -INT16_C(  5457), -INT16_C(     1),  INT16_C(   929), -INT16_C(  5740), -INT16_C(  3033),  INT16_C(     0),  INT16_C(   915) } },
    { {  INT16_C( 29751),  INT16_C( 20144), -INT16_C( 19886), -INT16_C( 28779), -INT16_C( 26348),  INT16_C(   505), -INT16_C( 18804),  INT16_C(  7300),
        -INT16_C( 25679),  INT16_C(    30), -INT16_C(  7551),  INT16_C( 28489), -INT16_C( 21749),  INT16_C(  5282), -INT16_C( 22890), -INT16_C( 12696),
         INT16_C(  6171),  INT16_C( 27932), -INT16_C( 20022), -INT16_C(  8451), -INT16_C(  2485), -INT16_C( 10272),  INT16_C( 25772),  INT16_C( 24051),
         INT16_C(  4607), -INT16_C( 32675), -INT16_C( 22796), -INT16_C(    17), -INT16_C( 28079), -INT16_C(  6124),  INT16_C( 31800),  INT16_C( 21430) },
      {  INT16_C(    13),  INT16_C(     5),  INT16_C(    11),  INT16_C(    12),  INT16_C(     1),  INT16_C(     6),  INT16_C(     9),  INT16_C(     7),
         INT16_C(     1),  INT16_C(     9),  INT16_C(    14),  INT16_C(     1),  INT16_C(    11),  INT16_C(    11),  INT16_C(    11),  INT16_C(    12),
         INT16_C(    12),  INT16_C(     0),  INT16_C(     5),  INT16_C(     4),  INT16_C(     7),  INT16_C(    15),  INT16_C(     5),  INT16_C(    11),
         INT16_C(     7),  INT16_C(     3),  INT16_C(    15),  INT16_C(    14),  INT16_C(     4),  INT16_C(    13),  INT16_C(    10),  INT16_C(     7) },
      {  INT16_C(     3),  INT16_C(   629), -INT16_C(    10), -INT16_C(     8), -INT16_C( 13174),  INT16_C(     7), -INT16_C(    37),  INT16_C(    57),
        -INT16_C( 12840),  INT16_C(     0), -INT16_C(     1),  INT16_C( 14244), -INT16_C(    11),  INT16_C(     2), -INT16_C(    12), -INT16_C(     4),
         INT16_C(     1),  INT16_C( 27932), -INT16_C(   626), -INT16_C(   529), -INT16_C(    20), -INT16_C(     1),  INT16_C(   805),  INT16_C(    11),
         INT16_C(    35), -INT16_C(  4085), -INT16_C(     1), -INT16_C(     1), -INT16_C(  1755), -INT16_C(     1),  INT16_C(    31),  INT16_C(   167) } },
    { { -INT16_C( 17539),  INT16_C(  2427),  INT16_C( 20248), -INT16_C( 28343), -INT16_C(  5688), -INT16_C(  9334),  INT16_C(   838), -INT16_C( 17000),
        -INT16_C(  3204), -INT16_C(  7180),  INT16_C( 16109), -INT16_C( 26420),  INT16_C( 28289),  INT16_C( 30066),  INT16_C(  3357), -INT16_C( 25878),
         INT16_C( 26057), -INT16_C(  7773), -INT16_C(  4940),  INT16_C( 32114), -INT16_C(   811),  INT16_C(  7000), -INT16_C(  4096),  INT16_C( 31960),
        -INT16_C( 13085), -INT16_C( 12193),  INT16_C( 11018), -INT16_C( 29591), -INT16_C(  9319), -INT16_C( 18943), -INT16_C(  5144), -INT16_C( 20144) },
      {  INT16_C(    15),  INT16_C(     0),  INT16_C(     0),  INT16_C(    11),  INT16_C(    13),  INT16_C(     0),  INT16_C(    10),  INT16_C(    10),
         INT16_C(    13),  INT16_C(     7),  INT16_C(    14),  INT16_C(    10),  INT16_C(     0),  INT16_C(    10),  INT16_C(    10),  INT16_C(     4),
         INT16_C(    14),  INT16_C(     7),  INT16_C(    13),  INT16_C(    15),  INT16_C(    15),  INT16_C(     7),  INT16_C(     7),  INT16_C(     1),
         INT16_C(    10),  INT16_C(     5),  INT16_C(    10),  INT16_C(     4),  INT16_C(     5),  INT16_C(    10),  INT16_C(     5),  INT16_C(     9) },
      { -INT16_C(     1),  INT16_C(  2427),  INT16_C( 20248), -INT16_C(    14), -INT16_C(     1), -INT16_C(  9334),  INT16_C(     0), -INT16_C(    17),
        -INT16_C(     1), -INT16_C(    57),  INT16_C(     0), -INT16_C(    26),  INT16_C( 28289),  INT16_C(    29),  INT16_C(     3), -INT16_C(  1618),
         INT16_C(     1), -INT16_C(    61), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(    54), -INT16_C(    32),  INT16_C( 15980),
        -INT16_C(    13), -INT16_C(   382),  INT16_C(    10), -INT16_C(  1850), -INT16_C(   292), -INT16_C(    19), -INT16_C(   161), -INT16_C(    40) } },
    { {  INT16_C( 15426),  INT16_C( 13584),  INT16_C( 16396), -INT16_C( 18902),  INT16_C(  8000), -INT16_C(  6357),  INT16_C( 20114), -INT16_C(  7934),
        -INT16_C( 25616),  INT16_C( 31032),  INT16_C( 12351), -INT16_C(  4156), -INT16_C( 17535),  INT16_C( 31381), -INT16_C( 31730),  INT16_C( 20495),
         INT16_C(  8128), -INT16_C( 13179), -INT16_C( 20640), -INT16_C( 24446), -INT16_C( 20785),  INT16_C( 24967), -INT16_C( 30212), -INT16_C(  5054),
         INT16_C( 31268),  INT16_C( 25701),  INT16_C( 10922),  INT16_C( 11091), -INT16_C(  5915), -INT16_C(  3163), -INT16_C( 19348),  INT16_C( 11331) },
      {  INT16_C(    12),  INT16_C(     3),  INT16_C(     7),  INT16_C(     4),  INT16_C(     5),  INT16_C(     2),  INT16_C(    14),  INT16_C(     0),
         INT16_C(     7),  INT16_C(     0),  INT16_C(    11),  INT16_C(     8),  INT16_C(    13),  INT16_C(     1),  INT16_C(    11),  INT16_C(     6),
         INT16_C(     3),  INT16_C(    15),  INT16_C(     7),  INT16_C(    13),  INT16_C(    14),  INT16_C(    10),  INT16_C(     1),  INT16_C(     3),
         INT16_C(     2),  INT16_C(     2),  INT16_C(     8),  INT16_C(     8),  INT16_C(     2),  INT16_C(    15),  INT16_C(    14),  INT16_C(     6) },
      {  INT16_C(     3),  INT16_C(  1698),  INT16_C(   128), -INT16_C(  1182),  INT16_C(   250), -INT16_C(  1590),  INT16_C(     1), -INT16_C(  7934),
        -INT16_C(   201),  INT16_C( 31032),  INT16_C(     6), -INT16_C(    17), -INT16_C(     3),  INT16_C( 15690), -INT16_C(    16),  INT16_C(   320),
         INT16_C(  1016), -INT16_C(     1), -INT16_C(   162), -INT16_C(     3), -INT16_C(     2),  INT16_C(    24), -INT16_C( 15106), -INT16_C(   632),
         INT16_C(  7817),  INT16_C(  6425),  INT16_C(    42),  INT16_C(    43), -INT16_C(  1479), -INT16_C(     1), -INT16_C(     2),  INT16_C(   177) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i a = simde_mm512_loadu_epi16(test_vec[i].a);
    simde__m512i b = simde_mm512_loadu_epi16(test_vec[i].b);
    simde__m512i r = simde_mm512_srav_epi16(a, b);
    simde_test_x86_assert_equal_i16x32(r, simde_mm512_loadu_epi16(test_vec[i].r));
  }

  return 0;
}

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_srav_epi16)
SIMDE_TEST_FUNC_LIST_END

#include <test/x86/avx512/test-avx512-footer.h>
