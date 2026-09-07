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
 *   2018-2020 Evan Nemerson <evan@nemerson.com>
 *   2021      Atharva Nimbalkar <atharvakn@gmail.com>
 *   2023      Yi-Yen Chung <eric681@andestech.com> (Copyright owned by Andes Technology)
 *   2023      Cuda-Chen <clh960524@gmail.com>
 */

#define SIMDE_TEST_ARM_NEON_INSN add

#include "test-neon.h"
#include <simde/arm/neon/add.h>

static int
test_simde_vadd_p8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_poly8_t a[8];
    simde_poly8_t b[8];
    simde_poly8_t r[8];
  } test_vec[] = {
    { {  SIMDE_POLY8_C(    33),  SIMDE_POLY8_C(    89),  SIMDE_POLY8_C(    65),   SIMDE_POLY8_C(UINT8_MAX),
         SIMDE_POLY8_C(   235),  SIMDE_POLY8_C(   192),  SIMDE_POLY8_C(     0),  SIMDE_POLY8_C(    73) },
      {  SIMDE_POLY8_C(    25),  SIMDE_POLY8_C(    94),  SIMDE_POLY8_C(   232),  SIMDE_POLY8_C(   201),
         SIMDE_POLY8_C(   180),  SIMDE_POLY8_C(    81),  SIMDE_POLY8_C(   101),  SIMDE_POLY8_C(    20) },
      {  SIMDE_POLY8_C(    56),  SIMDE_POLY8_C(     7),  SIMDE_POLY8_C(   169),  SIMDE_POLY8_C(    54),
         SIMDE_POLY8_C(    95),  SIMDE_POLY8_C(   145),  SIMDE_POLY8_C(   101),  SIMDE_POLY8_C(    93) } },
    { {  SIMDE_POLY8_C(   203),  SIMDE_POLY8_C(    54),  SIMDE_POLY8_C(    37),  SIMDE_POLY8_C(   215),
         SIMDE_POLY8_C(    48),  SIMDE_POLY8_C(    49),  SIMDE_POLY8_C(   215),  SIMDE_POLY8_C(   125) },
      {  SIMDE_POLY8_C(    86),  SIMDE_POLY8_C(    18),  SIMDE_POLY8_C(   157),  SIMDE_POLY8_C(   162),
         SIMDE_POLY8_C(   142),  SIMDE_POLY8_C(   137),  SIMDE_POLY8_C(    65),  SIMDE_POLY8_C(    82) },
      {  SIMDE_POLY8_C(   157),  SIMDE_POLY8_C(    36),  SIMDE_POLY8_C(   184),  SIMDE_POLY8_C(   117),
         SIMDE_POLY8_C(   190),  SIMDE_POLY8_C(   184),  SIMDE_POLY8_C(   150),  SIMDE_POLY8_C(    47) } },
    { {  SIMDE_POLY8_C(    21),  SIMDE_POLY8_C(   187),  SIMDE_POLY8_C(    38),  SIMDE_POLY8_C(    44),
         SIMDE_POLY8_C(   244),  SIMDE_POLY8_C(   227),  SIMDE_POLY8_C(    41),  SIMDE_POLY8_C(   143) },
      {  SIMDE_POLY8_C(    26),  SIMDE_POLY8_C(    49),  SIMDE_POLY8_C(    21),  SIMDE_POLY8_C(    51),
         SIMDE_POLY8_C(    62),  SIMDE_POLY8_C(    89),  SIMDE_POLY8_C(   239),  SIMDE_POLY8_C(   245) },
      {  SIMDE_POLY8_C(    15),  SIMDE_POLY8_C(   138),  SIMDE_POLY8_C(    51),  SIMDE_POLY8_C(    31),
         SIMDE_POLY8_C(   202),  SIMDE_POLY8_C(   186),  SIMDE_POLY8_C(   198),  SIMDE_POLY8_C(   122) } },
    { {  SIMDE_POLY8_C(   220),  SIMDE_POLY8_C(    69),  SIMDE_POLY8_C(   146),  SIMDE_POLY8_C(    98),
         SIMDE_POLY8_C(    93),  SIMDE_POLY8_C(   157),  SIMDE_POLY8_C(    43),  SIMDE_POLY8_C(     3) },
      {  SIMDE_POLY8_C(    15),  SIMDE_POLY8_C(   164),  SIMDE_POLY8_C(   145),  SIMDE_POLY8_C(    17),
         SIMDE_POLY8_C(    79),  SIMDE_POLY8_C(   184),  SIMDE_POLY8_C(   183),  SIMDE_POLY8_C(   248) },
      {  SIMDE_POLY8_C(   211),  SIMDE_POLY8_C(   225),  SIMDE_POLY8_C(     3),  SIMDE_POLY8_C(   115),
         SIMDE_POLY8_C(    18),  SIMDE_POLY8_C(    37),  SIMDE_POLY8_C(   156),  SIMDE_POLY8_C(   251) } },
    { {  SIMDE_POLY8_C(   242),  SIMDE_POLY8_C(   176),  SIMDE_POLY8_C(    43),  SIMDE_POLY8_C(   252),
         SIMDE_POLY8_C(    83),  SIMDE_POLY8_C(   192),  SIMDE_POLY8_C(    10),  SIMDE_POLY8_C(    94) },
      {  SIMDE_POLY8_C(   164),  SIMDE_POLY8_C(    37),  SIMDE_POLY8_C(    28),  SIMDE_POLY8_C(   125),
         SIMDE_POLY8_C(    83),  SIMDE_POLY8_C(   113),  SIMDE_POLY8_C(    53),  SIMDE_POLY8_C(   107) },
      {  SIMDE_POLY8_C(    86),  SIMDE_POLY8_C(   149),  SIMDE_POLY8_C(    55),  SIMDE_POLY8_C(   129),
         SIMDE_POLY8_C(     0),  SIMDE_POLY8_C(   177),  SIMDE_POLY8_C(    63),  SIMDE_POLY8_C(    53) } },
    { {  SIMDE_POLY8_C(   160),  SIMDE_POLY8_C(    56),  SIMDE_POLY8_C(     3),  SIMDE_POLY8_C(   140),
         SIMDE_POLY8_C(   203),  SIMDE_POLY8_C(   118),  SIMDE_POLY8_C(    12),  SIMDE_POLY8_C(   161) },
      {  SIMDE_POLY8_C(   143),  SIMDE_POLY8_C(   147),  SIMDE_POLY8_C(    86),  SIMDE_POLY8_C(    58),
         SIMDE_POLY8_C(    18),  SIMDE_POLY8_C(    43),  SIMDE_POLY8_C(   207),  SIMDE_POLY8_C(    59) },
      {  SIMDE_POLY8_C(    47),  SIMDE_POLY8_C(   171),  SIMDE_POLY8_C(    85),  SIMDE_POLY8_C(   182),
         SIMDE_POLY8_C(   217),  SIMDE_POLY8_C(    93),  SIMDE_POLY8_C(   195),  SIMDE_POLY8_C(   154) } },
    { {  SIMDE_POLY8_C(   254),  SIMDE_POLY8_C(   216),  SIMDE_POLY8_C(    73),  SIMDE_POLY8_C(    92),
         SIMDE_POLY8_C(    97),  SIMDE_POLY8_C(   150),  SIMDE_POLY8_C(    94),  SIMDE_POLY8_C(    23) },
      {  SIMDE_POLY8_C(   163),  SIMDE_POLY8_C(   109),  SIMDE_POLY8_C(    74),  SIMDE_POLY8_C(    17),
         SIMDE_POLY8_C(   191),  SIMDE_POLY8_C(    61),  SIMDE_POLY8_C(   103),  SIMDE_POLY8_C(   222) },
      {  SIMDE_POLY8_C(    93),  SIMDE_POLY8_C(   181),  SIMDE_POLY8_C(     3),  SIMDE_POLY8_C(    77),
         SIMDE_POLY8_C(   222),  SIMDE_POLY8_C(   171),  SIMDE_POLY8_C(    57),  SIMDE_POLY8_C(   201) } },
    { {  SIMDE_POLY8_C(   123),  SIMDE_POLY8_C(   246),  SIMDE_POLY8_C(   196),  SIMDE_POLY8_C(   141),
         SIMDE_POLY8_C(    19),  SIMDE_POLY8_C(   187),  SIMDE_POLY8_C(    73),  SIMDE_POLY8_C(    60) },
      {  SIMDE_POLY8_C(   198),  SIMDE_POLY8_C(    47),  SIMDE_POLY8_C(   111),  SIMDE_POLY8_C(   219),
         SIMDE_POLY8_C(    25),  SIMDE_POLY8_C(    76),  SIMDE_POLY8_C(   209),  SIMDE_POLY8_C(   241) },
      {  SIMDE_POLY8_C(   189),  SIMDE_POLY8_C(   217),  SIMDE_POLY8_C(   171),  SIMDE_POLY8_C(    86),
         SIMDE_POLY8_C(    10),  SIMDE_POLY8_C(   247),  SIMDE_POLY8_C(   152),  SIMDE_POLY8_C(   205) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_poly8x8_t a = simde_vld1_p8(test_vec[i].a);
    simde_poly8x8_t b = simde_vld1_p8(test_vec[i].b);
    simde_poly8x8_t r = simde_vadd_p8(a, b);

    simde_test_arm_neon_assert_equal_p8x8(r, simde_vld1_p8(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_poly8x8_t a = simde_test_arm_neon_random_p8x8();
    simde_poly8x8_t b = simde_test_arm_neon_random_p8x8();
    simde_poly8x8_t r = simde_vadd_p8(a, b);

    simde_test_arm_neon_write_p8x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_p8x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_p8x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vadd_p16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_poly16_t a[4];
    simde_poly16_t b[4];
    simde_poly16_t r[4];
  } test_vec[] = {
    { {  SIMDE_POLY16_C(   44848),  SIMDE_POLY16_C(   25263),  SIMDE_POLY16_C(   56185),  SIMDE_POLY16_C(   46842) },
      {  SIMDE_POLY16_C(   44027),  SIMDE_POLY16_C(   18055),  SIMDE_POLY16_C(   46799),  SIMDE_POLY16_C(   11694) },
      {  SIMDE_POLY16_C(    1227),  SIMDE_POLY16_C(    9256),  SIMDE_POLY16_C(   28086),  SIMDE_POLY16_C(   39764) } },
    { {  SIMDE_POLY16_C(    8719),  SIMDE_POLY16_C(   48304),  SIMDE_POLY16_C(   50563),  SIMDE_POLY16_C(   33590) },
      {  SIMDE_POLY16_C(   60253),  SIMDE_POLY16_C(    9950),  SIMDE_POLY16_C(    7334),  SIMDE_POLY16_C(    1265) },
      {  SIMDE_POLY16_C(   51538),  SIMDE_POLY16_C(   39534),  SIMDE_POLY16_C(   55589),  SIMDE_POLY16_C(   34759) } },
    { {  SIMDE_POLY16_C(    2519),  SIMDE_POLY16_C(   32880),  SIMDE_POLY16_C(   38511),  SIMDE_POLY16_C(   13749) },
      {  SIMDE_POLY16_C(    5160),  SIMDE_POLY16_C(    5666),  SIMDE_POLY16_C(   41636),  SIMDE_POLY16_C(   48481) },
      {  SIMDE_POLY16_C(    7679),  SIMDE_POLY16_C(   38482),  SIMDE_POLY16_C(   13515),  SIMDE_POLY16_C(   35028) } },
    { {  SIMDE_POLY16_C(   50014),  SIMDE_POLY16_C(   24511),  SIMDE_POLY16_C(   50497),  SIMDE_POLY16_C(    7370) },
      {  SIMDE_POLY16_C(   38152),  SIMDE_POLY16_C(   23612),  SIMDE_POLY16_C(    5758),  SIMDE_POLY16_C(   53290) },
      {  SIMDE_POLY16_C(   22102),  SIMDE_POLY16_C(     899),  SIMDE_POLY16_C(   54079),  SIMDE_POLY16_C(   52448) } },
    { {  SIMDE_POLY16_C(   18670),  SIMDE_POLY16_C(   22782),  SIMDE_POLY16_C(   17120),  SIMDE_POLY16_C(     154) },
      {  SIMDE_POLY16_C(   22181),  SIMDE_POLY16_C(   26233),  SIMDE_POLY16_C(   26407),  SIMDE_POLY16_C(   43106) },
      {  SIMDE_POLY16_C(    7755),  SIMDE_POLY16_C(   16007),  SIMDE_POLY16_C(    9671),  SIMDE_POLY16_C(   43256) } },
    { {  SIMDE_POLY16_C(   59179),  SIMDE_POLY16_C(   13001),  SIMDE_POLY16_C(   20645),  SIMDE_POLY16_C(   16746) },
      {  SIMDE_POLY16_C(   51036),  SIMDE_POLY16_C(    1807),  SIMDE_POLY16_C(   20983),  SIMDE_POLY16_C(   12864) },
      {  SIMDE_POLY16_C(    8311),  SIMDE_POLY16_C(   13766),  SIMDE_POLY16_C(     338),  SIMDE_POLY16_C(   29482) } },
    { {  SIMDE_POLY16_C(   31092),  SIMDE_POLY16_C(    3280),  SIMDE_POLY16_C(   57691),  SIMDE_POLY16_C(   47474) },
      {  SIMDE_POLY16_C(   10673),  SIMDE_POLY16_C(   45266),  SIMDE_POLY16_C(   22429),  SIMDE_POLY16_C(     982) },
      {  SIMDE_POLY16_C(   20677),  SIMDE_POLY16_C(   48130),  SIMDE_POLY16_C(   46790),  SIMDE_POLY16_C(   47780) } },
    { {  SIMDE_POLY16_C(    4312),  SIMDE_POLY16_C(   27352),  SIMDE_POLY16_C(   38240),  SIMDE_POLY16_C(   43915) },
      {  SIMDE_POLY16_C(   33894),  SIMDE_POLY16_C(   36255),  SIMDE_POLY16_C(   63975),  SIMDE_POLY16_C(   29690) },
      {  SIMDE_POLY16_C(   38078),  SIMDE_POLY16_C(   59207),  SIMDE_POLY16_C(   27783),  SIMDE_POLY16_C(   55409) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_poly16x4_t a = simde_vld1_p16(test_vec[i].a);
    simde_poly16x4_t b = simde_vld1_p16(test_vec[i].b);
    simde_poly16x4_t r = simde_vadd_p16(a, b);

    simde_test_arm_neon_assert_equal_p16x4(r, simde_vld1_p16(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_poly16x4_t a = simde_test_arm_neon_random_p16x4();
    simde_poly16x4_t b = simde_test_arm_neon_random_p16x4();
    simde_poly16x4_t r = simde_vadd_p16(a, b);

    simde_test_arm_neon_write_p16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_p16x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_p16x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vaddq_p8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_poly8_t a[16];
    simde_poly8_t b[16];
    simde_poly8_t r[16];
  } test_vec[] = {
    { {  SIMDE_POLY8_C(   183),  SIMDE_POLY8_C(   135),  SIMDE_POLY8_C(   110),  SIMDE_POLY8_C(   124),
         SIMDE_POLY8_C(   225),  SIMDE_POLY8_C(     5),  SIMDE_POLY8_C(   160),  SIMDE_POLY8_C(   204),
         SIMDE_POLY8_C(   245),  SIMDE_POLY8_C(   117),  SIMDE_POLY8_C(   197),  SIMDE_POLY8_C(   253),
         SIMDE_POLY8_C(   126),  SIMDE_POLY8_C(   228),  SIMDE_POLY8_C(    66),  SIMDE_POLY8_C(   129) },
      {  SIMDE_POLY8_C(   114),  SIMDE_POLY8_C(   189),  SIMDE_POLY8_C(    15),  SIMDE_POLY8_C(   245),
         SIMDE_POLY8_C(   224),  SIMDE_POLY8_C(    15),  SIMDE_POLY8_C(    78),  SIMDE_POLY8_C(   192),
         SIMDE_POLY8_C(   225),  SIMDE_POLY8_C(   118),  SIMDE_POLY8_C(   151),  SIMDE_POLY8_C(   125),
         SIMDE_POLY8_C(    89),  SIMDE_POLY8_C(   102),  SIMDE_POLY8_C(   211),  SIMDE_POLY8_C(   139) },
      {  SIMDE_POLY8_C(   197),  SIMDE_POLY8_C(    58),  SIMDE_POLY8_C(    97),  SIMDE_POLY8_C(   137),
         SIMDE_POLY8_C(     1),  SIMDE_POLY8_C(    10),  SIMDE_POLY8_C(   238),  SIMDE_POLY8_C(    12),
         SIMDE_POLY8_C(    20),  SIMDE_POLY8_C(     3),  SIMDE_POLY8_C(    82),  SIMDE_POLY8_C(   128),
         SIMDE_POLY8_C(    39),  SIMDE_POLY8_C(   130),  SIMDE_POLY8_C(   145),  SIMDE_POLY8_C(    10) } },
    { {  SIMDE_POLY8_C(   134),  SIMDE_POLY8_C(    58),  SIMDE_POLY8_C(   144),  SIMDE_POLY8_C(    25),
         SIMDE_POLY8_C(     2),  SIMDE_POLY8_C(   121),  SIMDE_POLY8_C(    33),  SIMDE_POLY8_C(   156),
         SIMDE_POLY8_C(   174),  SIMDE_POLY8_C(   122),  SIMDE_POLY8_C(   136),  SIMDE_POLY8_C(   115),
         SIMDE_POLY8_C(   193),  SIMDE_POLY8_C(   100),  SIMDE_POLY8_C(   111),  SIMDE_POLY8_C(   242) },
      {  SIMDE_POLY8_C(   119),  SIMDE_POLY8_C(    31),  SIMDE_POLY8_C(    72),  SIMDE_POLY8_C(    61),
         SIMDE_POLY8_C(   214),  SIMDE_POLY8_C(    42),  SIMDE_POLY8_C(   121),  SIMDE_POLY8_C(   230),
         SIMDE_POLY8_C(    81),  SIMDE_POLY8_C(   108),  SIMDE_POLY8_C(    95),  SIMDE_POLY8_C(    51),
         SIMDE_POLY8_C(   169),  SIMDE_POLY8_C(   238),  SIMDE_POLY8_C(    74),  SIMDE_POLY8_C(     2) },
      {  SIMDE_POLY8_C(   241),  SIMDE_POLY8_C(    37),  SIMDE_POLY8_C(   216),  SIMDE_POLY8_C(    36),
         SIMDE_POLY8_C(   212),  SIMDE_POLY8_C(    83),  SIMDE_POLY8_C(    88),  SIMDE_POLY8_C(   122),
          SIMDE_POLY8_C(UINT8_MAX),  SIMDE_POLY8_C(    22),  SIMDE_POLY8_C(   215),  SIMDE_POLY8_C(    64),
         SIMDE_POLY8_C(   104),  SIMDE_POLY8_C(   138),  SIMDE_POLY8_C(    37),  SIMDE_POLY8_C(   240) } },
    { {  SIMDE_POLY8_C(   226),  SIMDE_POLY8_C(   177),  SIMDE_POLY8_C(   249),  SIMDE_POLY8_C(   120),
         SIMDE_POLY8_C(   247),  SIMDE_POLY8_C(    21),  SIMDE_POLY8_C(   122),  SIMDE_POLY8_C(   178),
         SIMDE_POLY8_C(    88),  SIMDE_POLY8_C(   123),  SIMDE_POLY8_C(   170),  SIMDE_POLY8_C(   163),
         SIMDE_POLY8_C(    52),  SIMDE_POLY8_C(   202),  SIMDE_POLY8_C(    64),  SIMDE_POLY8_C(    89) },
      {  SIMDE_POLY8_C(   150),  SIMDE_POLY8_C(   155),  SIMDE_POLY8_C(   150),  SIMDE_POLY8_C(   164),
         SIMDE_POLY8_C(   195),  SIMDE_POLY8_C(   220),  SIMDE_POLY8_C(   131),  SIMDE_POLY8_C(   166),
         SIMDE_POLY8_C(   103),  SIMDE_POLY8_C(    60),  SIMDE_POLY8_C(    53),  SIMDE_POLY8_C(   207),
         SIMDE_POLY8_C(   154),  SIMDE_POLY8_C(    86),  SIMDE_POLY8_C(   136),  SIMDE_POLY8_C(   165) },
      {  SIMDE_POLY8_C(   116),  SIMDE_POLY8_C(    42),  SIMDE_POLY8_C(   111),  SIMDE_POLY8_C(   220),
         SIMDE_POLY8_C(    52),  SIMDE_POLY8_C(   201),  SIMDE_POLY8_C(   249),  SIMDE_POLY8_C(    20),
         SIMDE_POLY8_C(    63),  SIMDE_POLY8_C(    71),  SIMDE_POLY8_C(   159),  SIMDE_POLY8_C(   108),
         SIMDE_POLY8_C(   174),  SIMDE_POLY8_C(   156),  SIMDE_POLY8_C(   200),  SIMDE_POLY8_C(   252) } },
    { {  SIMDE_POLY8_C(   152),  SIMDE_POLY8_C(    82),  SIMDE_POLY8_C(   253),  SIMDE_POLY8_C(    41),
         SIMDE_POLY8_C(   184),  SIMDE_POLY8_C(    68),  SIMDE_POLY8_C(   145),  SIMDE_POLY8_C(    63),
         SIMDE_POLY8_C(   227),  SIMDE_POLY8_C(   104),  SIMDE_POLY8_C(    58),  SIMDE_POLY8_C(    82),
         SIMDE_POLY8_C(   151),  SIMDE_POLY8_C(    47),  SIMDE_POLY8_C(   253),  SIMDE_POLY8_C(   159) },
      {  SIMDE_POLY8_C(   139),  SIMDE_POLY8_C(   114),  SIMDE_POLY8_C(   164),  SIMDE_POLY8_C(   224),
         SIMDE_POLY8_C(    14),  SIMDE_POLY8_C(    94),  SIMDE_POLY8_C(   190),  SIMDE_POLY8_C(   125),
         SIMDE_POLY8_C(    56),  SIMDE_POLY8_C(   102),  SIMDE_POLY8_C(   251),  SIMDE_POLY8_C(   198),
         SIMDE_POLY8_C(   206),  SIMDE_POLY8_C(   147),  SIMDE_POLY8_C(   232),  SIMDE_POLY8_C(    30) },
      {  SIMDE_POLY8_C(    19),  SIMDE_POLY8_C(    32),  SIMDE_POLY8_C(    89),  SIMDE_POLY8_C(   201),
         SIMDE_POLY8_C(   182),  SIMDE_POLY8_C(    26),  SIMDE_POLY8_C(    47),  SIMDE_POLY8_C(    66),
         SIMDE_POLY8_C(   219),  SIMDE_POLY8_C(    14),  SIMDE_POLY8_C(   193),  SIMDE_POLY8_C(   148),
         SIMDE_POLY8_C(    89),  SIMDE_POLY8_C(   188),  SIMDE_POLY8_C(    21),  SIMDE_POLY8_C(   129) } },
    { {  SIMDE_POLY8_C(    76),  SIMDE_POLY8_C(    14),  SIMDE_POLY8_C(   145),  SIMDE_POLY8_C(    56),
         SIMDE_POLY8_C(   227),  SIMDE_POLY8_C(   143),  SIMDE_POLY8_C(   170),  SIMDE_POLY8_C(   207),
         SIMDE_POLY8_C(   100),  SIMDE_POLY8_C(   181),  SIMDE_POLY8_C(   157),  SIMDE_POLY8_C(   196),
         SIMDE_POLY8_C(   243),  SIMDE_POLY8_C(   196),  SIMDE_POLY8_C(   232),  SIMDE_POLY8_C(    24) },
      {  SIMDE_POLY8_C(    17),  SIMDE_POLY8_C(   179),  SIMDE_POLY8_C(    80),  SIMDE_POLY8_C(    20),
         SIMDE_POLY8_C(    75),  SIMDE_POLY8_C(    83),  SIMDE_POLY8_C(    86),  SIMDE_POLY8_C(   177),
         SIMDE_POLY8_C(   156),  SIMDE_POLY8_C(   204),  SIMDE_POLY8_C(   101),  SIMDE_POLY8_C(    83),
         SIMDE_POLY8_C(   253),  SIMDE_POLY8_C(   159),  SIMDE_POLY8_C(   207),  SIMDE_POLY8_C(   194) },
      {  SIMDE_POLY8_C(    93),  SIMDE_POLY8_C(   189),  SIMDE_POLY8_C(   193),  SIMDE_POLY8_C(    44),
         SIMDE_POLY8_C(   168),  SIMDE_POLY8_C(   220),  SIMDE_POLY8_C(   252),  SIMDE_POLY8_C(   126),
         SIMDE_POLY8_C(   248),  SIMDE_POLY8_C(   121),  SIMDE_POLY8_C(   248),  SIMDE_POLY8_C(   151),
         SIMDE_POLY8_C(    14),  SIMDE_POLY8_C(    91),  SIMDE_POLY8_C(    39),  SIMDE_POLY8_C(   218) } },
    { {  SIMDE_POLY8_C(    67),  SIMDE_POLY8_C(   237),  SIMDE_POLY8_C(   135),  SIMDE_POLY8_C(   108),
         SIMDE_POLY8_C(   113),  SIMDE_POLY8_C(   245),  SIMDE_POLY8_C(    81),  SIMDE_POLY8_C(   167),
         SIMDE_POLY8_C(    51),  SIMDE_POLY8_C(    62),  SIMDE_POLY8_C(   120),  SIMDE_POLY8_C(    93),
         SIMDE_POLY8_C(   209),  SIMDE_POLY8_C(   219),  SIMDE_POLY8_C(   165),  SIMDE_POLY8_C(   180) },
      {  SIMDE_POLY8_C(   126),  SIMDE_POLY8_C(   180),  SIMDE_POLY8_C(   202),  SIMDE_POLY8_C(    28),
         SIMDE_POLY8_C(   150),  SIMDE_POLY8_C(    60),  SIMDE_POLY8_C(   141),  SIMDE_POLY8_C(   131),
         SIMDE_POLY8_C(   219),  SIMDE_POLY8_C(     8),  SIMDE_POLY8_C(   187),  SIMDE_POLY8_C(   217),
         SIMDE_POLY8_C(   139),  SIMDE_POLY8_C(   209),  SIMDE_POLY8_C(   210),  SIMDE_POLY8_C(   129) },
      {  SIMDE_POLY8_C(    61),  SIMDE_POLY8_C(    89),  SIMDE_POLY8_C(    77),  SIMDE_POLY8_C(   112),
         SIMDE_POLY8_C(   231),  SIMDE_POLY8_C(   201),  SIMDE_POLY8_C(   220),  SIMDE_POLY8_C(    36),
         SIMDE_POLY8_C(   232),  SIMDE_POLY8_C(    54),  SIMDE_POLY8_C(   195),  SIMDE_POLY8_C(   132),
         SIMDE_POLY8_C(    90),  SIMDE_POLY8_C(    10),  SIMDE_POLY8_C(   119),  SIMDE_POLY8_C(    53) } },
    { {  SIMDE_POLY8_C(   107),  SIMDE_POLY8_C(   204),  SIMDE_POLY8_C(   116),  SIMDE_POLY8_C(   184),
         SIMDE_POLY8_C(   201),  SIMDE_POLY8_C(    38),  SIMDE_POLY8_C(    48),  SIMDE_POLY8_C(    21),
         SIMDE_POLY8_C(   249),  SIMDE_POLY8_C(    40),  SIMDE_POLY8_C(    15),  SIMDE_POLY8_C(    40),
         SIMDE_POLY8_C(   194),  SIMDE_POLY8_C(    98),  SIMDE_POLY8_C(    66),  SIMDE_POLY8_C(    87) },
      {  SIMDE_POLY8_C(   116),  SIMDE_POLY8_C(   160),  SIMDE_POLY8_C(   184),  SIMDE_POLY8_C(   140),
         SIMDE_POLY8_C(   245),  SIMDE_POLY8_C(   116),  SIMDE_POLY8_C(   248),  SIMDE_POLY8_C(    28),
         SIMDE_POLY8_C(   229),  SIMDE_POLY8_C(   103),  SIMDE_POLY8_C(   171),  SIMDE_POLY8_C(    21),
         SIMDE_POLY8_C(   155),  SIMDE_POLY8_C(     8),  SIMDE_POLY8_C(    20),  SIMDE_POLY8_C(    78) },
      {  SIMDE_POLY8_C(    31),  SIMDE_POLY8_C(   108),  SIMDE_POLY8_C(   204),  SIMDE_POLY8_C(    52),
         SIMDE_POLY8_C(    60),  SIMDE_POLY8_C(    82),  SIMDE_POLY8_C(   200),  SIMDE_POLY8_C(     9),
         SIMDE_POLY8_C(    28),  SIMDE_POLY8_C(    79),  SIMDE_POLY8_C(   164),  SIMDE_POLY8_C(    61),
         SIMDE_POLY8_C(    89),  SIMDE_POLY8_C(   106),  SIMDE_POLY8_C(    86),  SIMDE_POLY8_C(    25) } },
    { {  SIMDE_POLY8_C(   232),  SIMDE_POLY8_C(   223),  SIMDE_POLY8_C(   159),  SIMDE_POLY8_C(   209),
         SIMDE_POLY8_C(     5),  SIMDE_POLY8_C(   217),  SIMDE_POLY8_C(   123),  SIMDE_POLY8_C(   236),
         SIMDE_POLY8_C(   111),  SIMDE_POLY8_C(    90),  SIMDE_POLY8_C(   147),  SIMDE_POLY8_C(   137),
         SIMDE_POLY8_C(   213),  SIMDE_POLY8_C(   252),  SIMDE_POLY8_C(    94),  SIMDE_POLY8_C(    55) },
      {  SIMDE_POLY8_C(   104),  SIMDE_POLY8_C(   232),  SIMDE_POLY8_C(    62),  SIMDE_POLY8_C(   153),
         SIMDE_POLY8_C(   211),  SIMDE_POLY8_C(   147),  SIMDE_POLY8_C(   128),  SIMDE_POLY8_C(    39),
         SIMDE_POLY8_C(   118),  SIMDE_POLY8_C(   183),  SIMDE_POLY8_C(   196),  SIMDE_POLY8_C(   140),
         SIMDE_POLY8_C(   213),  SIMDE_POLY8_C(   180),  SIMDE_POLY8_C(   247),  SIMDE_POLY8_C(   120) },
      {  SIMDE_POLY8_C(   128),  SIMDE_POLY8_C(    55),  SIMDE_POLY8_C(   161),  SIMDE_POLY8_C(    72),
         SIMDE_POLY8_C(   214),  SIMDE_POLY8_C(    74),  SIMDE_POLY8_C(   251),  SIMDE_POLY8_C(   203),
         SIMDE_POLY8_C(    25),  SIMDE_POLY8_C(   237),  SIMDE_POLY8_C(    87),  SIMDE_POLY8_C(     5),
         SIMDE_POLY8_C(     0),  SIMDE_POLY8_C(    72),  SIMDE_POLY8_C(   169),  SIMDE_POLY8_C(    79) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_poly8x16_t a = simde_vld1q_p8(test_vec[i].a);
    simde_poly8x16_t b = simde_vld1q_p8(test_vec[i].b);
    simde_poly8x16_t r = simde_vaddq_p8(a, b);

    simde_test_arm_neon_assert_equal_p8x16(r, simde_vld1q_p8(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_poly8x16_t a = simde_test_arm_neon_random_p8x16();
    simde_poly8x16_t b = simde_test_arm_neon_random_p8x16();
    simde_poly8x16_t r = simde_vaddq_p8(a, b);

    simde_test_arm_neon_write_p8x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_p8x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_p8x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vaddq_p16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_poly16_t a[8];
    simde_poly16_t b[8];
    simde_poly16_t r[8];
  } test_vec[] = {
    { {  SIMDE_POLY16_C(   17947),  SIMDE_POLY16_C(   59627),  SIMDE_POLY16_C(   13747),  SIMDE_POLY16_C(   60214),
         SIMDE_POLY16_C(   25527),  SIMDE_POLY16_C(   22465),  SIMDE_POLY16_C(   31008),  SIMDE_POLY16_C(   55276) },
      {  SIMDE_POLY16_C(   12643),  SIMDE_POLY16_C(   57634),  SIMDE_POLY16_C(   10112),  SIMDE_POLY16_C(   31417),
         SIMDE_POLY16_C(   43720),  SIMDE_POLY16_C(   57721),  SIMDE_POLY16_C(    6164),  SIMDE_POLY16_C(    3722) },
      {  SIMDE_POLY16_C(   30584),  SIMDE_POLY16_C(    2505),  SIMDE_POLY16_C(    4659),  SIMDE_POLY16_C(   37263),
         SIMDE_POLY16_C(   51583),  SIMDE_POLY16_C(   46776),  SIMDE_POLY16_C(   24884),  SIMDE_POLY16_C(   55654) } },
    { {  SIMDE_POLY16_C(   25610),  SIMDE_POLY16_C(   33945),  SIMDE_POLY16_C(   65012),  SIMDE_POLY16_C(   27880),
         SIMDE_POLY16_C(   48429),  SIMDE_POLY16_C(   44309),  SIMDE_POLY16_C(    7727),  SIMDE_POLY16_C(   18394) },
      {  SIMDE_POLY16_C(    4010),  SIMDE_POLY16_C(   19605),  SIMDE_POLY16_C(     646),  SIMDE_POLY16_C(    6945),
         SIMDE_POLY16_C(   24159),  SIMDE_POLY16_C(    5559),  SIMDE_POLY16_C(   15091),  SIMDE_POLY16_C(    4641) },
      {  SIMDE_POLY16_C(   27552),  SIMDE_POLY16_C(   51212),  SIMDE_POLY16_C(   65394),  SIMDE_POLY16_C(   30665),
         SIMDE_POLY16_C(   58226),  SIMDE_POLY16_C(   47266),  SIMDE_POLY16_C(    9436),  SIMDE_POLY16_C(   22011) } },
    { {  SIMDE_POLY16_C(   60692),  SIMDE_POLY16_C(   33785),  SIMDE_POLY16_C(   19384),  SIMDE_POLY16_C(   14821),
         SIMDE_POLY16_C(   40380),  SIMDE_POLY16_C(   19087),  SIMDE_POLY16_C(    8114),  SIMDE_POLY16_C(   36709) },
      {  SIMDE_POLY16_C(   36514),  SIMDE_POLY16_C(   33408),  SIMDE_POLY16_C(   63224),  SIMDE_POLY16_C(   29645),
         SIMDE_POLY16_C(   15041),  SIMDE_POLY16_C(   36757),  SIMDE_POLY16_C(   42027),  SIMDE_POLY16_C(   36016) },
      {  SIMDE_POLY16_C(   25526),  SIMDE_POLY16_C(     377),  SIMDE_POLY16_C(   48448),  SIMDE_POLY16_C(   18984),
         SIMDE_POLY16_C(   42877),  SIMDE_POLY16_C(   50458),  SIMDE_POLY16_C(   48025),  SIMDE_POLY16_C(     981) } },
    { {  SIMDE_POLY16_C(   18141),  SIMDE_POLY16_C(   45065),  SIMDE_POLY16_C(   60606),  SIMDE_POLY16_C(   11849),
         SIMDE_POLY16_C(   46718),  SIMDE_POLY16_C(    3530),  SIMDE_POLY16_C(   42939),  SIMDE_POLY16_C(   55698) },
      {  SIMDE_POLY16_C(   44681),  SIMDE_POLY16_C(   12139),  SIMDE_POLY16_C(   52114),  SIMDE_POLY16_C(   21680),
         SIMDE_POLY16_C(   44059),  SIMDE_POLY16_C(   27972),  SIMDE_POLY16_C(    7574),  SIMDE_POLY16_C(   15409) },
      {  SIMDE_POLY16_C(   59476),  SIMDE_POLY16_C(   40802),  SIMDE_POLY16_C(   10028),  SIMDE_POLY16_C(   31481),
         SIMDE_POLY16_C(    6757),  SIMDE_POLY16_C(   24718),  SIMDE_POLY16_C(   47661),  SIMDE_POLY16_C(   58787) } },
    { {  SIMDE_POLY16_C(   57331),  SIMDE_POLY16_C(   62493),  SIMDE_POLY16_C(    2414),  SIMDE_POLY16_C(   51609),
         SIMDE_POLY16_C(   56885),  SIMDE_POLY16_C(   15440),  SIMDE_POLY16_C(   30921),  SIMDE_POLY16_C(   57628) },
      {  SIMDE_POLY16_C(   55460),  SIMDE_POLY16_C(   62933),  SIMDE_POLY16_C(   30562),  SIMDE_POLY16_C(   64038),
         SIMDE_POLY16_C(   17558),  SIMDE_POLY16_C(    4700),  SIMDE_POLY16_C(    4199),  SIMDE_POLY16_C(   48364) },
      {  SIMDE_POLY16_C(    1879),  SIMDE_POLY16_C(     456),  SIMDE_POLY16_C(   32268),  SIMDE_POLY16_C(   13247),
         SIMDE_POLY16_C(   39587),  SIMDE_POLY16_C(   11788),  SIMDE_POLY16_C(   26798),  SIMDE_POLY16_C(   24048) } },
    { {  SIMDE_POLY16_C(    1786),  SIMDE_POLY16_C(   24136),  SIMDE_POLY16_C(   32584),  SIMDE_POLY16_C(   43856),
         SIMDE_POLY16_C(   38344),  SIMDE_POLY16_C(   50712),  SIMDE_POLY16_C(   34231),  SIMDE_POLY16_C(   25688) },
      {  SIMDE_POLY16_C(   49017),  SIMDE_POLY16_C(    9948),  SIMDE_POLY16_C(   18165),  SIMDE_POLY16_C(   13402),
         SIMDE_POLY16_C(   58881),  SIMDE_POLY16_C(    3005),  SIMDE_POLY16_C(   11265),  SIMDE_POLY16_C(   52715) },
      {  SIMDE_POLY16_C(   47491),  SIMDE_POLY16_C(   30868),  SIMDE_POLY16_C(   14781),  SIMDE_POLY16_C(   40714),
         SIMDE_POLY16_C(   29641),  SIMDE_POLY16_C(   52645),  SIMDE_POLY16_C(   43446),  SIMDE_POLY16_C(   43443) } },
    { {  SIMDE_POLY16_C(   36514),  SIMDE_POLY16_C(   40641),  SIMDE_POLY16_C(   48435),  SIMDE_POLY16_C(   64823),
         SIMDE_POLY16_C(   28799),  SIMDE_POLY16_C(   23113),  SIMDE_POLY16_C(   15829),  SIMDE_POLY16_C(   57863) },
      {  SIMDE_POLY16_C(   57839),  SIMDE_POLY16_C(   56275),  SIMDE_POLY16_C(   27049),  SIMDE_POLY16_C(   15419),
         SIMDE_POLY16_C(    6369),  SIMDE_POLY16_C(   64017),  SIMDE_POLY16_C(   14409),  SIMDE_POLY16_C(   65103) },
      {  SIMDE_POLY16_C(   28493),  SIMDE_POLY16_C(   17682),  SIMDE_POLY16_C(   54426),  SIMDE_POLY16_C(   49420),
         SIMDE_POLY16_C(   26782),  SIMDE_POLY16_C(   41048),  SIMDE_POLY16_C(    1436),  SIMDE_POLY16_C(    7240) } },
    { {  SIMDE_POLY16_C(   37116),  SIMDE_POLY16_C(   54232),  SIMDE_POLY16_C(    8172),  SIMDE_POLY16_C(   65515),
         SIMDE_POLY16_C(   19328),  SIMDE_POLY16_C(   45577),  SIMDE_POLY16_C(   49944),  SIMDE_POLY16_C(   63864) },
      {  SIMDE_POLY16_C(   31664),  SIMDE_POLY16_C(   53471),  SIMDE_POLY16_C(   46798),  SIMDE_POLY16_C(   32140),
         SIMDE_POLY16_C(   22511),  SIMDE_POLY16_C(   18434),  SIMDE_POLY16_C(   35100),  SIMDE_POLY16_C(   22561) },
      {  SIMDE_POLY16_C(   60236),  SIMDE_POLY16_C(     775),  SIMDE_POLY16_C(   43298),  SIMDE_POLY16_C(   33383),
         SIMDE_POLY16_C(    7279),  SIMDE_POLY16_C(   64011),  SIMDE_POLY16_C(   18948),  SIMDE_POLY16_C(   41305) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_poly16x8_t a = simde_vld1q_p16(test_vec[i].a);
    simde_poly16x8_t b = simde_vld1q_p16(test_vec[i].b);
    simde_poly16x8_t r = simde_vaddq_p16(a, b);

    simde_test_arm_neon_assert_equal_p16x8(r, simde_vld1q_p16(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_poly16x8_t a = simde_test_arm_neon_random_p16x8();
    simde_poly16x8_t b = simde_test_arm_neon_random_p16x8();
    simde_poly16x8_t r = simde_vaddq_p16(a, b);

    simde_test_arm_neon_write_p16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_p16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_p16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vadd_p8)
SIMDE_TEST_FUNC_LIST_ENTRY(vadd_p16)
SIMDE_TEST_FUNC_LIST_ENTRY(vaddq_p8)
SIMDE_TEST_FUNC_LIST_ENTRY(vaddq_p16)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
