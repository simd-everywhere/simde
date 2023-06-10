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

#define SIMDE_TEST_X86_AVX512_INSN srai

#include <test/x86/avx512/test-avx512.h>
#include <simde/x86/avx512/srai.h>

static int
test_simde_mm512_srai_epi16 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const int16_t a[32];
    const int16_t r0[32];
    const int16_t r3[32];
    const int16_t r7[32];
    const int16_t r13[32];
    const int16_t r24[32];
  } test_vec[] = {
    { { -INT16_C(  2725),  INT16_C(  6711),  INT16_C(  7327),  INT16_C( 11963),  INT16_C( 28148),  INT16_C(  5058),  INT16_C( 21695), -INT16_C( 19668),
        -INT16_C( 11147),  INT16_C( 27930), -INT16_C(  5129), -INT16_C( 26938), -INT16_C( 23608),  INT16_C( 22277),  INT16_C( 10373), -INT16_C(  8091),
        -INT16_C( 25571), -INT16_C( 17158), -INT16_C( 19015), -INT16_C( 21013), -INT16_C( 21214), -INT16_C(  7488), -INT16_C(  5119),  INT16_C( 30357),
        -INT16_C( 20543), -INT16_C( 18205), -INT16_C( 21861),  INT16_C( 25422),  INT16_C( 21325), -INT16_C( 11590),  INT16_C(  8315), -INT16_C( 26446) },
      { -INT16_C(  2725),  INT16_C(  6711),  INT16_C(  7327),  INT16_C( 11963),  INT16_C( 28148),  INT16_C(  5058),  INT16_C( 21695), -INT16_C( 19668),
        -INT16_C( 11147),  INT16_C( 27930), -INT16_C(  5129), -INT16_C( 26938), -INT16_C( 23608),  INT16_C( 22277),  INT16_C( 10373), -INT16_C(  8091),
        -INT16_C( 25571), -INT16_C( 17158), -INT16_C( 19015), -INT16_C( 21013), -INT16_C( 21214), -INT16_C(  7488), -INT16_C(  5119),  INT16_C( 30357),
        -INT16_C( 20543), -INT16_C( 18205), -INT16_C( 21861),  INT16_C( 25422),  INT16_C( 21325), -INT16_C( 11590),  INT16_C(  8315), -INT16_C( 26446) },
      { -INT16_C(   341),  INT16_C(   838),  INT16_C(   915),  INT16_C(  1495),  INT16_C(  3518),  INT16_C(   632),  INT16_C(  2711), -INT16_C(  2459),
        -INT16_C(  1394),  INT16_C(  3491), -INT16_C(   642), -INT16_C(  3368), -INT16_C(  2951),  INT16_C(  2784),  INT16_C(  1296), -INT16_C(  1012),
        -INT16_C(  3197), -INT16_C(  2145), -INT16_C(  2377), -INT16_C(  2627), -INT16_C(  2652), -INT16_C(   936), -INT16_C(   640),  INT16_C(  3794),
        -INT16_C(  2568), -INT16_C(  2276), -INT16_C(  2733),  INT16_C(  3177),  INT16_C(  2665), -INT16_C(  1449),  INT16_C(  1039), -INT16_C(  3306) },
      { -INT16_C(    22),  INT16_C(    52),  INT16_C(    57),  INT16_C(    93),  INT16_C(   219),  INT16_C(    39),  INT16_C(   169), -INT16_C(   154),
        -INT16_C(    88),  INT16_C(   218), -INT16_C(    41), -INT16_C(   211), -INT16_C(   185),  INT16_C(   174),  INT16_C(    81), -INT16_C(    64),
        -INT16_C(   200), -INT16_C(   135), -INT16_C(   149), -INT16_C(   165), -INT16_C(   166), -INT16_C(    59), -INT16_C(    40),  INT16_C(   237),
        -INT16_C(   161), -INT16_C(   143), -INT16_C(   171),  INT16_C(   198),  INT16_C(   166), -INT16_C(    91),  INT16_C(    64), -INT16_C(   207) },
      { -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     1),  INT16_C(     3),  INT16_C(     0),  INT16_C(     2), -INT16_C(     3),
        -INT16_C(     2),  INT16_C(     3), -INT16_C(     1), -INT16_C(     4), -INT16_C(     3),  INT16_C(     2),  INT16_C(     1), -INT16_C(     1),
        -INT16_C(     4), -INT16_C(     3), -INT16_C(     3), -INT16_C(     3), -INT16_C(     3), -INT16_C(     1), -INT16_C(     1),  INT16_C(     3),
        -INT16_C(     3), -INT16_C(     3), -INT16_C(     3),  INT16_C(     3),  INT16_C(     2), -INT16_C(     2),  INT16_C(     1), -INT16_C(     4) },
      { -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
        -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
        -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
        -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1) } },
    { { -INT16_C( 21316),  INT16_C( 30036),  INT16_C( 16225), -INT16_C( 31710), -INT16_C(  7444), -INT16_C(  4762), -INT16_C(  1073), -INT16_C( 28572),
         INT16_C( 18347),  INT16_C( 17992), -INT16_C( 26895),  INT16_C( 16041),  INT16_C( 25833),  INT16_C( 25616), -INT16_C( 15740),  INT16_C( 16636),
         INT16_C( 20590), -INT16_C( 12106), -INT16_C( 10096),  INT16_C( 31828), -INT16_C( 17733), -INT16_C( 30102), -INT16_C( 12619),  INT16_C( 24602),
         INT16_C( 25109),  INT16_C(  1958),  INT16_C( 20728), -INT16_C(  7867),  INT16_C( 22196),  INT16_C( 14405),  INT16_C( 16664), -INT16_C( 30856) },
      { -INT16_C( 21316),  INT16_C( 30036),  INT16_C( 16225), -INT16_C( 31710), -INT16_C(  7444), -INT16_C(  4762), -INT16_C(  1073), -INT16_C( 28572),
         INT16_C( 18347),  INT16_C( 17992), -INT16_C( 26895),  INT16_C( 16041),  INT16_C( 25833),  INT16_C( 25616), -INT16_C( 15740),  INT16_C( 16636),
         INT16_C( 20590), -INT16_C( 12106), -INT16_C( 10096),  INT16_C( 31828), -INT16_C( 17733), -INT16_C( 30102), -INT16_C( 12619),  INT16_C( 24602),
         INT16_C( 25109),  INT16_C(  1958),  INT16_C( 20728), -INT16_C(  7867),  INT16_C( 22196),  INT16_C( 14405),  INT16_C( 16664), -INT16_C( 30856) },
      { -INT16_C(  2665),  INT16_C(  3754),  INT16_C(  2028), -INT16_C(  3964), -INT16_C(   931), -INT16_C(   596), -INT16_C(   135), -INT16_C(  3572),
         INT16_C(  2293),  INT16_C(  2249), -INT16_C(  3362),  INT16_C(  2005),  INT16_C(  3229),  INT16_C(  3202), -INT16_C(  1968),  INT16_C(  2079),
         INT16_C(  2573), -INT16_C(  1514), -INT16_C(  1262),  INT16_C(  3978), -INT16_C(  2217), -INT16_C(  3763), -INT16_C(  1578),  INT16_C(  3075),
         INT16_C(  3138),  INT16_C(   244),  INT16_C(  2591), -INT16_C(   984),  INT16_C(  2774),  INT16_C(  1800),  INT16_C(  2083), -INT16_C(  3857) },
      { -INT16_C(   167),  INT16_C(   234),  INT16_C(   126), -INT16_C(   248), -INT16_C(    59), -INT16_C(    38), -INT16_C(     9), -INT16_C(   224),
         INT16_C(   143),  INT16_C(   140), -INT16_C(   211),  INT16_C(   125),  INT16_C(   201),  INT16_C(   200), -INT16_C(   123),  INT16_C(   129),
         INT16_C(   160), -INT16_C(    95), -INT16_C(    79),  INT16_C(   248), -INT16_C(   139), -INT16_C(   236), -INT16_C(    99),  INT16_C(   192),
         INT16_C(   196),  INT16_C(    15),  INT16_C(   161), -INT16_C(    62),  INT16_C(   173),  INT16_C(   112),  INT16_C(   130), -INT16_C(   242) },
      { -INT16_C(     3),  INT16_C(     3),  INT16_C(     1), -INT16_C(     4), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     4),
         INT16_C(     2),  INT16_C(     2), -INT16_C(     4),  INT16_C(     1),  INT16_C(     3),  INT16_C(     3), -INT16_C(     2),  INT16_C(     2),
         INT16_C(     2), -INT16_C(     2), -INT16_C(     2),  INT16_C(     3), -INT16_C(     3), -INT16_C(     4), -INT16_C(     2),  INT16_C(     3),
         INT16_C(     3),  INT16_C(     0),  INT16_C(     2), -INT16_C(     1),  INT16_C(     2),  INT16_C(     1),  INT16_C(     2), -INT16_C(     4) },
      { -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),
         INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
         INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
         INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1) } },
    { {  INT16_C( 11921),  INT16_C(  8535), -INT16_C( 21753), -INT16_C( 15714),  INT16_C(  2149),  INT16_C(  6732),  INT16_C( 26326), -INT16_C(  5253),
         INT16_C(  8648), -INT16_C( 16142),  INT16_C( 14449),  INT16_C(  9633), -INT16_C(  6514), -INT16_C( 22947), -INT16_C( 10713), -INT16_C( 18387),
        -INT16_C( 31740),  INT16_C(  3034),  INT16_C( 30767), -INT16_C( 27443),  INT16_C(  6528),  INT16_C( 22191),  INT16_C( 10879),  INT16_C( 18241),
         INT16_C( 13387), -INT16_C( 17145), -INT16_C( 22420), -INT16_C(  1310),  INT16_C( 16526), -INT16_C( 19040), -INT16_C( 12778),  INT16_C(  6766) },
      {  INT16_C( 11921),  INT16_C(  8535), -INT16_C( 21753), -INT16_C( 15714),  INT16_C(  2149),  INT16_C(  6732),  INT16_C( 26326), -INT16_C(  5253),
         INT16_C(  8648), -INT16_C( 16142),  INT16_C( 14449),  INT16_C(  9633), -INT16_C(  6514), -INT16_C( 22947), -INT16_C( 10713), -INT16_C( 18387),
        -INT16_C( 31740),  INT16_C(  3034),  INT16_C( 30767), -INT16_C( 27443),  INT16_C(  6528),  INT16_C( 22191),  INT16_C( 10879),  INT16_C( 18241),
         INT16_C( 13387), -INT16_C( 17145), -INT16_C( 22420), -INT16_C(  1310),  INT16_C( 16526), -INT16_C( 19040), -INT16_C( 12778),  INT16_C(  6766) },
      {  INT16_C(  1490),  INT16_C(  1066), -INT16_C(  2720), -INT16_C(  1965),  INT16_C(   268),  INT16_C(   841),  INT16_C(  3290), -INT16_C(   657),
         INT16_C(  1081), -INT16_C(  2018),  INT16_C(  1806),  INT16_C(  1204), -INT16_C(   815), -INT16_C(  2869), -INT16_C(  1340), -INT16_C(  2299),
        -INT16_C(  3968),  INT16_C(   379),  INT16_C(  3845), -INT16_C(  3431),  INT16_C(   816),  INT16_C(  2773),  INT16_C(  1359),  INT16_C(  2280),
         INT16_C(  1673), -INT16_C(  2144), -INT16_C(  2803), -INT16_C(   164),  INT16_C(  2065), -INT16_C(  2380), -INT16_C(  1598),  INT16_C(   845) },
      {  INT16_C(    93),  INT16_C(    66), -INT16_C(   170), -INT16_C(   123),  INT16_C(    16),  INT16_C(    52),  INT16_C(   205), -INT16_C(    42),
         INT16_C(    67), -INT16_C(   127),  INT16_C(   112),  INT16_C(    75), -INT16_C(    51), -INT16_C(   180), -INT16_C(    84), -INT16_C(   144),
        -INT16_C(   248),  INT16_C(    23),  INT16_C(   240), -INT16_C(   215),  INT16_C(    51),  INT16_C(   173),  INT16_C(    84),  INT16_C(   142),
         INT16_C(   104), -INT16_C(   134), -INT16_C(   176), -INT16_C(    11),  INT16_C(   129), -INT16_C(   149), -INT16_C(   100),  INT16_C(    52) },
      {  INT16_C(     1),  INT16_C(     1), -INT16_C(     3), -INT16_C(     2),  INT16_C(     0),  INT16_C(     0),  INT16_C(     3), -INT16_C(     1),
         INT16_C(     1), -INT16_C(     2),  INT16_C(     1),  INT16_C(     1), -INT16_C(     1), -INT16_C(     3), -INT16_C(     2), -INT16_C(     3),
        -INT16_C(     4),  INT16_C(     0),  INT16_C(     3), -INT16_C(     4),  INT16_C(     0),  INT16_C(     2),  INT16_C(     1),  INT16_C(     2),
         INT16_C(     1), -INT16_C(     3), -INT16_C(     3), -INT16_C(     1),  INT16_C(     2), -INT16_C(     3), -INT16_C(     2),  INT16_C(     0) },
      {  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
         INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),
        -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
         INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0) } },
    { {  INT16_C( 18514), -INT16_C( 32218), -INT16_C(  3136),  INT16_C( 16406), -INT16_C( 15091), -INT16_C( 29546), -INT16_C( 10257),  INT16_C( 15316),
        -INT16_C(  9461),  INT16_C( 30712), -INT16_C(  9596),  INT16_C(  4721),  INT16_C(  4634),  INT16_C( 12488),  INT16_C( 14048),  INT16_C( 12875),
         INT16_C( 29054),  INT16_C( 16052), -INT16_C( 13468),  INT16_C( 29054),  INT16_C(  5264), -INT16_C( 32514), -INT16_C( 11541), -INT16_C(  2117),
        -INT16_C( 19539),  INT16_C( 12654), -INT16_C(  8051), -INT16_C( 22460),  INT16_C(  3314), -INT16_C( 11560),  INT16_C(  9026), -INT16_C( 16380) },
      {  INT16_C( 18514), -INT16_C( 32218), -INT16_C(  3136),  INT16_C( 16406), -INT16_C( 15091), -INT16_C( 29546), -INT16_C( 10257),  INT16_C( 15316),
        -INT16_C(  9461),  INT16_C( 30712), -INT16_C(  9596),  INT16_C(  4721),  INT16_C(  4634),  INT16_C( 12488),  INT16_C( 14048),  INT16_C( 12875),
         INT16_C( 29054),  INT16_C( 16052), -INT16_C( 13468),  INT16_C( 29054),  INT16_C(  5264), -INT16_C( 32514), -INT16_C( 11541), -INT16_C(  2117),
        -INT16_C( 19539),  INT16_C( 12654), -INT16_C(  8051), -INT16_C( 22460),  INT16_C(  3314), -INT16_C( 11560),  INT16_C(  9026), -INT16_C( 16380) },
      {  INT16_C(  2314), -INT16_C(  4028), -INT16_C(   392),  INT16_C(  2050), -INT16_C(  1887), -INT16_C(  3694), -INT16_C(  1283),  INT16_C(  1914),
        -INT16_C(  1183),  INT16_C(  3839), -INT16_C(  1200),  INT16_C(   590),  INT16_C(   579),  INT16_C(  1561),  INT16_C(  1756),  INT16_C(  1609),
         INT16_C(  3631),  INT16_C(  2006), -INT16_C(  1684),  INT16_C(  3631),  INT16_C(   658), -INT16_C(  4065), -INT16_C(  1443), -INT16_C(   265),
        -INT16_C(  2443),  INT16_C(  1581), -INT16_C(  1007), -INT16_C(  2808),  INT16_C(   414), -INT16_C(  1445),  INT16_C(  1128), -INT16_C(  2048) },
      {  INT16_C(   144), -INT16_C(   252), -INT16_C(    25),  INT16_C(   128), -INT16_C(   118), -INT16_C(   231), -INT16_C(    81),  INT16_C(   119),
        -INT16_C(    74),  INT16_C(   239), -INT16_C(    75),  INT16_C(    36),  INT16_C(    36),  INT16_C(    97),  INT16_C(   109),  INT16_C(   100),
         INT16_C(   226),  INT16_C(   125), -INT16_C(   106),  INT16_C(   226),  INT16_C(    41), -INT16_C(   255), -INT16_C(    91), -INT16_C(    17),
        -INT16_C(   153),  INT16_C(    98), -INT16_C(    63), -INT16_C(   176),  INT16_C(    25), -INT16_C(    91),  INT16_C(    70), -INT16_C(   128) },
      {  INT16_C(     2), -INT16_C(     4), -INT16_C(     1),  INT16_C(     2), -INT16_C(     2), -INT16_C(     4), -INT16_C(     2),  INT16_C(     1),
        -INT16_C(     2),  INT16_C(     3), -INT16_C(     2),  INT16_C(     0),  INT16_C(     0),  INT16_C(     1),  INT16_C(     1),  INT16_C(     1),
         INT16_C(     3),  INT16_C(     1), -INT16_C(     2),  INT16_C(     3),  INT16_C(     0), -INT16_C(     4), -INT16_C(     2), -INT16_C(     1),
        -INT16_C(     3),  INT16_C(     1), -INT16_C(     1), -INT16_C(     3),  INT16_C(     0), -INT16_C(     2),  INT16_C(     1), -INT16_C(     2) },
      {  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
        -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
         INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),
        -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1) } },
    { { -INT16_C( 18028), -INT16_C(  1538),  INT16_C( 31876),  INT16_C(  5226),  INT16_C( 26768),  INT16_C( 31636),  INT16_C( 20282), -INT16_C(  6030),
        -INT16_C(  7934), -INT16_C( 28647),  INT16_C( 24001), -INT16_C( 19656),  INT16_C(  4201), -INT16_C( 21627), -INT16_C( 30412), -INT16_C( 14229),
         INT16_C( 26946), -INT16_C( 14655),  INT16_C( 11493),  INT16_C( 30171),  INT16_C( 28564), -INT16_C( 12303),  INT16_C( 25535), -INT16_C( 15945),
        -INT16_C( 12220),  INT16_C(  1361), -INT16_C( 30418), -INT16_C( 26696),  INT16_C( 15770), -INT16_C( 12733), -INT16_C( 20793),  INT16_C(  2454) },
      { -INT16_C( 18028), -INT16_C(  1538),  INT16_C( 31876),  INT16_C(  5226),  INT16_C( 26768),  INT16_C( 31636),  INT16_C( 20282), -INT16_C(  6030),
        -INT16_C(  7934), -INT16_C( 28647),  INT16_C( 24001), -INT16_C( 19656),  INT16_C(  4201), -INT16_C( 21627), -INT16_C( 30412), -INT16_C( 14229),
         INT16_C( 26946), -INT16_C( 14655),  INT16_C( 11493),  INT16_C( 30171),  INT16_C( 28564), -INT16_C( 12303),  INT16_C( 25535), -INT16_C( 15945),
        -INT16_C( 12220),  INT16_C(  1361), -INT16_C( 30418), -INT16_C( 26696),  INT16_C( 15770), -INT16_C( 12733), -INT16_C( 20793),  INT16_C(  2454) },
      { -INT16_C(  2254), -INT16_C(   193),  INT16_C(  3984),  INT16_C(   653),  INT16_C(  3346),  INT16_C(  3954),  INT16_C(  2535), -INT16_C(   754),
        -INT16_C(   992), -INT16_C(  3581),  INT16_C(  3000), -INT16_C(  2457),  INT16_C(   525), -INT16_C(  2704), -INT16_C(  3802), -INT16_C(  1779),
         INT16_C(  3368), -INT16_C(  1832),  INT16_C(  1436),  INT16_C(  3771),  INT16_C(  3570), -INT16_C(  1538),  INT16_C(  3191), -INT16_C(  1994),
        -INT16_C(  1528),  INT16_C(   170), -INT16_C(  3803), -INT16_C(  3337),  INT16_C(  1971), -INT16_C(  1592), -INT16_C(  2600),  INT16_C(   306) },
      { -INT16_C(   141), -INT16_C(    13),  INT16_C(   249),  INT16_C(    40),  INT16_C(   209),  INT16_C(   247),  INT16_C(   158), -INT16_C(    48),
        -INT16_C(    62), -INT16_C(   224),  INT16_C(   187), -INT16_C(   154),  INT16_C(    32), -INT16_C(   169), -INT16_C(   238), -INT16_C(   112),
         INT16_C(   210), -INT16_C(   115),  INT16_C(    89),  INT16_C(   235),  INT16_C(   223), -INT16_C(    97),  INT16_C(   199), -INT16_C(   125),
        -INT16_C(    96),  INT16_C(    10), -INT16_C(   238), -INT16_C(   209),  INT16_C(   123), -INT16_C(   100), -INT16_C(   163),  INT16_C(    19) },
      { -INT16_C(     3), -INT16_C(     1),  INT16_C(     3),  INT16_C(     0),  INT16_C(     3),  INT16_C(     3),  INT16_C(     2), -INT16_C(     1),
        -INT16_C(     1), -INT16_C(     4),  INT16_C(     2), -INT16_C(     3),  INT16_C(     0), -INT16_C(     3), -INT16_C(     4), -INT16_C(     2),
         INT16_C(     3), -INT16_C(     2),  INT16_C(     1),  INT16_C(     3),  INT16_C(     3), -INT16_C(     2),  INT16_C(     3), -INT16_C(     2),
        -INT16_C(     2),  INT16_C(     0), -INT16_C(     4), -INT16_C(     4),  INT16_C(     1), -INT16_C(     2), -INT16_C(     3),  INT16_C(     0) },
      { -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
        -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),
         INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
        -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0) } },
    { {  INT16_C( 22552), -INT16_C(   560), -INT16_C( 21628),  INT16_C(  6259),  INT16_C( 25626), -INT16_C(  9753), -INT16_C( 24889),  INT16_C(  3227),
        -INT16_C(  5009), -INT16_C( 25327), -INT16_C( 13706),  INT16_C(  4148),  INT16_C( 30471), -INT16_C( 12578),  INT16_C( 29734),  INT16_C( 16088),
        -INT16_C( 22324),  INT16_C( 20539), -INT16_C( 20909),  INT16_C( 28009),  INT16_C( 20498), -INT16_C(  9657), -INT16_C(  7441),  INT16_C( 24294),
        -INT16_C(  2098),  INT16_C( 17659),  INT16_C( 12225), -INT16_C( 13996),  INT16_C( 12967), -INT16_C( 12905),  INT16_C( 28583),  INT16_C( 29451) },
      {  INT16_C( 22552), -INT16_C(   560), -INT16_C( 21628),  INT16_C(  6259),  INT16_C( 25626), -INT16_C(  9753), -INT16_C( 24889),  INT16_C(  3227),
        -INT16_C(  5009), -INT16_C( 25327), -INT16_C( 13706),  INT16_C(  4148),  INT16_C( 30471), -INT16_C( 12578),  INT16_C( 29734),  INT16_C( 16088),
        -INT16_C( 22324),  INT16_C( 20539), -INT16_C( 20909),  INT16_C( 28009),  INT16_C( 20498), -INT16_C(  9657), -INT16_C(  7441),  INT16_C( 24294),
        -INT16_C(  2098),  INT16_C( 17659),  INT16_C( 12225), -INT16_C( 13996),  INT16_C( 12967), -INT16_C( 12905),  INT16_C( 28583),  INT16_C( 29451) },
      {  INT16_C(  2819), -INT16_C(    70), -INT16_C(  2704),  INT16_C(   782),  INT16_C(  3203), -INT16_C(  1220), -INT16_C(  3112),  INT16_C(   403),
        -INT16_C(   627), -INT16_C(  3166), -INT16_C(  1714),  INT16_C(   518),  INT16_C(  3808), -INT16_C(  1573),  INT16_C(  3716),  INT16_C(  2011),
        -INT16_C(  2791),  INT16_C(  2567), -INT16_C(  2614),  INT16_C(  3501),  INT16_C(  2562), -INT16_C(  1208), -INT16_C(   931),  INT16_C(  3036),
        -INT16_C(   263),  INT16_C(  2207),  INT16_C(  1528), -INT16_C(  1750),  INT16_C(  1620), -INT16_C(  1614),  INT16_C(  3572),  INT16_C(  3681) },
      {  INT16_C(   176), -INT16_C(     5), -INT16_C(   169),  INT16_C(    48),  INT16_C(   200), -INT16_C(    77), -INT16_C(   195),  INT16_C(    25),
        -INT16_C(    40), -INT16_C(   198), -INT16_C(   108),  INT16_C(    32),  INT16_C(   238), -INT16_C(    99),  INT16_C(   232),  INT16_C(   125),
        -INT16_C(   175),  INT16_C(   160), -INT16_C(   164),  INT16_C(   218),  INT16_C(   160), -INT16_C(    76), -INT16_C(    59),  INT16_C(   189),
        -INT16_C(    17),  INT16_C(   137),  INT16_C(    95), -INT16_C(   110),  INT16_C(   101), -INT16_C(   101),  INT16_C(   223),  INT16_C(   230) },
      {  INT16_C(     2), -INT16_C(     1), -INT16_C(     3),  INT16_C(     0),  INT16_C(     3), -INT16_C(     2), -INT16_C(     4),  INT16_C(     0),
        -INT16_C(     1), -INT16_C(     4), -INT16_C(     2),  INT16_C(     0),  INT16_C(     3), -INT16_C(     2),  INT16_C(     3),  INT16_C(     1),
        -INT16_C(     3),  INT16_C(     2), -INT16_C(     3),  INT16_C(     3),  INT16_C(     2), -INT16_C(     2), -INT16_C(     1),  INT16_C(     2),
        -INT16_C(     1),  INT16_C(     2),  INT16_C(     1), -INT16_C(     2),  INT16_C(     1), -INT16_C(     2),  INT16_C(     3),  INT16_C(     3) },
      {  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
        -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
        -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
        -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0) } },
    { {  INT16_C( 17943),  INT16_C( 27332),  INT16_C( 11765),  INT16_C(  2008),  INT16_C(  8061),  INT16_C( 27873), -INT16_C( 14591), -INT16_C( 12342),
        -INT16_C( 14913), -INT16_C( 32748),  INT16_C( 26869), -INT16_C( 25527), -INT16_C(  7781),  INT16_C( 17001),  INT16_C( 29776),  INT16_C( 26805),
         INT16_C( 31162), -INT16_C( 20526), -INT16_C( 21850),  INT16_C(  9399), -INT16_C( 26423), -INT16_C( 13680),  INT16_C( 23392),  INT16_C(  8090),
        -INT16_C( 20960),  INT16_C(  5535), -INT16_C(  5866), -INT16_C( 20047),  INT16_C(  6858),  INT16_C(  6899), -INT16_C( 22130),  INT16_C( 18818) },
      {  INT16_C( 17943),  INT16_C( 27332),  INT16_C( 11765),  INT16_C(  2008),  INT16_C(  8061),  INT16_C( 27873), -INT16_C( 14591), -INT16_C( 12342),
        -INT16_C( 14913), -INT16_C( 32748),  INT16_C( 26869), -INT16_C( 25527), -INT16_C(  7781),  INT16_C( 17001),  INT16_C( 29776),  INT16_C( 26805),
         INT16_C( 31162), -INT16_C( 20526), -INT16_C( 21850),  INT16_C(  9399), -INT16_C( 26423), -INT16_C( 13680),  INT16_C( 23392),  INT16_C(  8090),
        -INT16_C( 20960),  INT16_C(  5535), -INT16_C(  5866), -INT16_C( 20047),  INT16_C(  6858),  INT16_C(  6899), -INT16_C( 22130),  INT16_C( 18818) },
      {  INT16_C(  2242),  INT16_C(  3416),  INT16_C(  1470),  INT16_C(   251),  INT16_C(  1007),  INT16_C(  3484), -INT16_C(  1824), -INT16_C(  1543),
        -INT16_C(  1865), -INT16_C(  4094),  INT16_C(  3358), -INT16_C(  3191), -INT16_C(   973),  INT16_C(  2125),  INT16_C(  3722),  INT16_C(  3350),
         INT16_C(  3895), -INT16_C(  2566), -INT16_C(  2732),  INT16_C(  1174), -INT16_C(  3303), -INT16_C(  1710),  INT16_C(  2924),  INT16_C(  1011),
        -INT16_C(  2620),  INT16_C(   691), -INT16_C(   734), -INT16_C(  2506),  INT16_C(   857),  INT16_C(   862), -INT16_C(  2767),  INT16_C(  2352) },
      {  INT16_C(   140),  INT16_C(   213),  INT16_C(    91),  INT16_C(    15),  INT16_C(    62),  INT16_C(   217), -INT16_C(   114), -INT16_C(    97),
        -INT16_C(   117), -INT16_C(   256),  INT16_C(   209), -INT16_C(   200), -INT16_C(    61),  INT16_C(   132),  INT16_C(   232),  INT16_C(   209),
         INT16_C(   243), -INT16_C(   161), -INT16_C(   171),  INT16_C(    73), -INT16_C(   207), -INT16_C(   107),  INT16_C(   182),  INT16_C(    63),
        -INT16_C(   164),  INT16_C(    43), -INT16_C(    46), -INT16_C(   157),  INT16_C(    53),  INT16_C(    53), -INT16_C(   173),  INT16_C(   147) },
      {  INT16_C(     2),  INT16_C(     3),  INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     3), -INT16_C(     2), -INT16_C(     2),
        -INT16_C(     2), -INT16_C(     4),  INT16_C(     3), -INT16_C(     4), -INT16_C(     1),  INT16_C(     2),  INT16_C(     3),  INT16_C(     3),
         INT16_C(     3), -INT16_C(     3), -INT16_C(     3),  INT16_C(     1), -INT16_C(     4), -INT16_C(     2),  INT16_C(     2),  INT16_C(     0),
        -INT16_C(     3),  INT16_C(     0), -INT16_C(     1), -INT16_C(     3),  INT16_C(     0),  INT16_C(     0), -INT16_C(     3),  INT16_C(     2) },
      {  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),
        -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
         INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
        -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0) } },
    { {  INT16_C( 21794), -INT16_C( 13832), -INT16_C( 20481), -INT16_C( 13843),  INT16_C( 32072), -INT16_C( 22381),  INT16_C( 11736), -INT16_C(  1593),
         INT16_C( 26331), -INT16_C(  3570), -INT16_C( 16305),  INT16_C(  6563), -INT16_C( 26662),  INT16_C( 26932), -INT16_C( 18880),  INT16_C( 25266),
        -INT16_C( 22005),  INT16_C(  2859),  INT16_C(  6234), -INT16_C( 23852),  INT16_C( 26518),  INT16_C( 28234),  INT16_C(  4501),  INT16_C( 28775),
         INT16_C( 30327), -INT16_C( 14494),  INT16_C(  1590),  INT16_C(  4320),  INT16_C(  5277), -INT16_C(  8839),  INT16_C( 11211), -INT16_C( 10689) },
      {  INT16_C( 21794), -INT16_C( 13832), -INT16_C( 20481), -INT16_C( 13843),  INT16_C( 32072), -INT16_C( 22381),  INT16_C( 11736), -INT16_C(  1593),
         INT16_C( 26331), -INT16_C(  3570), -INT16_C( 16305),  INT16_C(  6563), -INT16_C( 26662),  INT16_C( 26932), -INT16_C( 18880),  INT16_C( 25266),
        -INT16_C( 22005),  INT16_C(  2859),  INT16_C(  6234), -INT16_C( 23852),  INT16_C( 26518),  INT16_C( 28234),  INT16_C(  4501),  INT16_C( 28775),
         INT16_C( 30327), -INT16_C( 14494),  INT16_C(  1590),  INT16_C(  4320),  INT16_C(  5277), -INT16_C(  8839),  INT16_C( 11211), -INT16_C( 10689) },
      {  INT16_C(  2724), -INT16_C(  1729), -INT16_C(  2561), -INT16_C(  1731),  INT16_C(  4009), -INT16_C(  2798),  INT16_C(  1467), -INT16_C(   200),
         INT16_C(  3291), -INT16_C(   447), -INT16_C(  2039),  INT16_C(   820), -INT16_C(  3333),  INT16_C(  3366), -INT16_C(  2360),  INT16_C(  3158),
        -INT16_C(  2751),  INT16_C(   357),  INT16_C(   779), -INT16_C(  2982),  INT16_C(  3314),  INT16_C(  3529),  INT16_C(   562),  INT16_C(  3596),
         INT16_C(  3790), -INT16_C(  1812),  INT16_C(   198),  INT16_C(   540),  INT16_C(   659), -INT16_C(  1105),  INT16_C(  1401), -INT16_C(  1337) },
      {  INT16_C(   170), -INT16_C(   109), -INT16_C(   161), -INT16_C(   109),  INT16_C(   250), -INT16_C(   175),  INT16_C(    91), -INT16_C(    13),
         INT16_C(   205), -INT16_C(    28), -INT16_C(   128),  INT16_C(    51), -INT16_C(   209),  INT16_C(   210), -INT16_C(   148),  INT16_C(   197),
        -INT16_C(   172),  INT16_C(    22),  INT16_C(    48), -INT16_C(   187),  INT16_C(   207),  INT16_C(   220),  INT16_C(    35),  INT16_C(   224),
         INT16_C(   236), -INT16_C(   114),  INT16_C(    12),  INT16_C(    33),  INT16_C(    41), -INT16_C(    70),  INT16_C(    87), -INT16_C(    84) },
      {  INT16_C(     2), -INT16_C(     2), -INT16_C(     3), -INT16_C(     2),  INT16_C(     3), -INT16_C(     3),  INT16_C(     1), -INT16_C(     1),
         INT16_C(     3), -INT16_C(     1), -INT16_C(     2),  INT16_C(     0), -INT16_C(     4),  INT16_C(     3), -INT16_C(     3),  INT16_C(     3),
        -INT16_C(     3),  INT16_C(     0),  INT16_C(     0), -INT16_C(     3),  INT16_C(     3),  INT16_C(     3),  INT16_C(     0),  INT16_C(     3),
         INT16_C(     3), -INT16_C(     2),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     2),  INT16_C(     1), -INT16_C(     2) },
      {  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
         INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
        -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
         INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i a = simde_mm512_loadu_epi16(test_vec[i].a);
    simde__m512i r0 = simde_mm512_srai_epi16(a, 0);
    simde__m512i r3 = simde_mm512_srai_epi16(a, 3);
    simde__m512i r7 = simde_mm512_srai_epi16(a, 7);
    simde__m512i r13 = simde_mm512_srai_epi16(a, 13);
    simde__m512i r24 = simde_mm512_srai_epi16(a, 24);
    simde_test_x86_assert_equal_i16x32(r0, simde_mm512_loadu_epi16(test_vec[i].r0));
    simde_test_x86_assert_equal_i16x32(r3, simde_mm512_loadu_epi16(test_vec[i].r3));
    simde_test_x86_assert_equal_i16x32(r7, simde_mm512_loadu_epi16(test_vec[i].r7));
    simde_test_x86_assert_equal_i16x32(r13, simde_mm512_loadu_epi16(test_vec[i].r13));
    simde_test_x86_assert_equal_i16x32(r24, simde_mm512_loadu_epi16(test_vec[i].r24));
  }

  return 0;
}

static int
test_simde_mm512_srai_epi32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int32_t a[16];
    const int32_t r0[16];
    const int32_t r3[16];
    const int32_t r7[16];
    const int32_t r13[16];
    const int32_t r24[16];
  } test_vec[] = {
    { {  INT32_C(    60427838), -INT32_C(   250573213),  INT32_C(   845732724),  INT32_C(  1550216741), -INT32_C(  1660388006),  INT32_C(  1551569461), -INT32_C(  1480297343),  INT32_C(   830423283),
        -INT32_C(  1321985458),  INT32_C(   480461992),  INT32_C(  1162808095), -INT32_C(   727599750),  INT32_C(  1735502386),  INT32_C(  1053093308),  INT32_C(  1424328801),  INT32_C(   377841096) },
      {  INT32_C(    60427838), -INT32_C(   250573213),  INT32_C(   845732724),  INT32_C(  1550216741), -INT32_C(  1660388006),  INT32_C(  1551569461), -INT32_C(  1480297343),  INT32_C(   830423283),
        -INT32_C(  1321985458),  INT32_C(   480461992),  INT32_C(  1162808095), -INT32_C(   727599750),  INT32_C(  1735502386),  INT32_C(  1053093308),  INT32_C(  1424328801),  INT32_C(   377841096) },
      {  INT32_C(     7553479), -INT32_C(    31321652),  INT32_C(   105716590),  INT32_C(   193777092), -INT32_C(   207548501),  INT32_C(   193946182), -INT32_C(   185037168),  INT32_C(   103802910),
        -INT32_C(   165248183),  INT32_C(    60057749),  INT32_C(   145351011), -INT32_C(    90949969),  INT32_C(   216937798),  INT32_C(   131636663),  INT32_C(   178041100),  INT32_C(    47230137) },
      {  INT32_C(      472092), -INT32_C(     1957604),  INT32_C(     6607286),  INT32_C(    12111068), -INT32_C(    12971782),  INT32_C(    12121636), -INT32_C(    11564823),  INT32_C(     6487681),
        -INT32_C(    10328012),  INT32_C(     3753609),  INT32_C(     9084438), -INT32_C(     5684374),  INT32_C(    13558612),  INT32_C(     8227291),  INT32_C(    11127568),  INT32_C(     2951883) },
      {  INT32_C(        7376), -INT32_C(       30588),  INT32_C(      103238),  INT32_C(      189235), -INT32_C(      202685),  INT32_C(      189400), -INT32_C(      180701),  INT32_C(      101370),
        -INT32_C(      161376),  INT32_C(       58650),  INT32_C(      141944), -INT32_C(       88819),  INT32_C(      211853),  INT32_C(      128551),  INT32_C(      173868),  INT32_C(       46123) },
      {  INT32_C(           3), -INT32_C(          15),  INT32_C(          50),  INT32_C(          92), -INT32_C(          99),  INT32_C(          92), -INT32_C(          89),  INT32_C(          49),
        -INT32_C(          79),  INT32_C(          28),  INT32_C(          69), -INT32_C(          44),  INT32_C(         103),  INT32_C(          62),  INT32_C(          84),  INT32_C(          22) } },
    { {  INT32_C(   667466111),  INT32_C(   490957822), -INT32_C(   261975434),  INT32_C(  2059666503),  INT32_C(  1793144494), -INT32_C(  2069322461), -INT32_C(   153579986),  INT32_C(  1913478643),
         INT32_C(   345625878), -INT32_C(  1238180800), -INT32_C(  1230531473),  INT32_C(  1177578392), -INT32_C(   995028319), -INT32_C(   448243273), -INT32_C(   623107865), -INT32_C(  1806898819) },
      {  INT32_C(   667466111),  INT32_C(   490957822), -INT32_C(   261975434),  INT32_C(  2059666503),  INT32_C(  1793144494), -INT32_C(  2069322461), -INT32_C(   153579986),  INT32_C(  1913478643),
         INT32_C(   345625878), -INT32_C(  1238180800), -INT32_C(  1230531473),  INT32_C(  1177578392), -INT32_C(   995028319), -INT32_C(   448243273), -INT32_C(   623107865), -INT32_C(  1806898819) },
      {  INT32_C(    83433263),  INT32_C(    61369727), -INT32_C(    32746930),  INT32_C(   257458312),  INT32_C(   224143061), -INT32_C(   258665308), -INT32_C(    19197499),  INT32_C(   239184830),
         INT32_C(    43203234), -INT32_C(   154772600), -INT32_C(   153816435),  INT32_C(   147197299), -INT32_C(   124378540), -INT32_C(    56030410), -INT32_C(    77888484), -INT32_C(   225862353) },
      {  INT32_C(     5214578),  INT32_C(     3835607), -INT32_C(     2046684),  INT32_C(    16091144),  INT32_C(    14008941), -INT32_C(    16166582), -INT32_C(     1199844),  INT32_C(    14949051),
         INT32_C(     2700202), -INT32_C(     9673288), -INT32_C(     9613528),  INT32_C(     9199831), -INT32_C(     7773659), -INT32_C(     3501901), -INT32_C(     4868031), -INT32_C(    14116398) },
      {  INT32_C(       81477),  INT32_C(       59931), -INT32_C(       31980),  INT32_C(      251424),  INT32_C(      218889), -INT32_C(      252603), -INT32_C(       18748),  INT32_C(      233578),
         INT32_C(       42190), -INT32_C(      151146), -INT32_C(      150212),  INT32_C(      143747), -INT32_C(      121464), -INT32_C(       54718), -INT32_C(       76063), -INT32_C(      220569) },
      {  INT32_C(          39),  INT32_C(          29), -INT32_C(          16),  INT32_C(         122),  INT32_C(         106), -INT32_C(         124), -INT32_C(          10),  INT32_C(         114),
         INT32_C(          20), -INT32_C(          74), -INT32_C(          74),  INT32_C(          70), -INT32_C(          60), -INT32_C(          27), -INT32_C(          38), -INT32_C(         108) } },
    { { -INT32_C(    22485570),  INT32_C(   833936066),  INT32_C(   132602735),  INT32_C(  1749948615), -INT32_C(   517079254),  INT32_C(  1086813528),  INT32_C(   320512918),  INT32_C(  1252485004),
         INT32_C(   239620172), -INT32_C(  1723859926),  INT32_C(   530655064),  INT32_C(  1770516287),  INT32_C(  1179301102), -INT32_C(  1064955606),  INT32_C(  1087611316),  INT32_C(  1418361608) },
      { -INT32_C(    22485570),  INT32_C(   833936066),  INT32_C(   132602735),  INT32_C(  1749948615), -INT32_C(   517079254),  INT32_C(  1086813528),  INT32_C(   320512918),  INT32_C(  1252485004),
         INT32_C(   239620172), -INT32_C(  1723859926),  INT32_C(   530655064),  INT32_C(  1770516287),  INT32_C(  1179301102), -INT32_C(  1064955606),  INT32_C(  1087611316),  INT32_C(  1418361608) },
      { -INT32_C(     2810697),  INT32_C(   104242008),  INT32_C(    16575341),  INT32_C(   218743576), -INT32_C(    64634907),  INT32_C(   135851691),  INT32_C(    40064114),  INT32_C(   156560625),
         INT32_C(    29952521), -INT32_C(   215482491),  INT32_C(    66331883),  INT32_C(   221314535),  INT32_C(   147412637), -INT32_C(   133119451),  INT32_C(   135951414),  INT32_C(   177295201) },
      { -INT32_C(      175669),  INT32_C(     6515125),  INT32_C(     1035958),  INT32_C(    13671473), -INT32_C(     4039682),  INT32_C(     8490730),  INT32_C(     2504007),  INT32_C(     9785039),
         INT32_C(     1872032), -INT32_C(    13467656),  INT32_C(     4145742),  INT32_C(    13832158),  INT32_C(     9213289), -INT32_C(     8319966),  INT32_C(     8496963),  INT32_C(    11080950) },
      { -INT32_C(        2745),  INT32_C(      101798),  INT32_C(       16186),  INT32_C(      213616), -INT32_C(       63121),  INT32_C(      132667),  INT32_C(       39125),  INT32_C(      152891),
         INT32_C(       29250), -INT32_C(      210433),  INT32_C(       64777),  INT32_C(      216127),  INT32_C(      143957), -INT32_C(      130000),  INT32_C(      132765),  INT32_C(      173139) },
      { -INT32_C(           2),  INT32_C(          49),  INT32_C(           7),  INT32_C(         104), -INT32_C(          31),  INT32_C(          64),  INT32_C(          19),  INT32_C(          74),
         INT32_C(          14), -INT32_C(         103),  INT32_C(          31),  INT32_C(         105),  INT32_C(          70), -INT32_C(          64),  INT32_C(          64),  INT32_C(          84) } },
    { { -INT32_C(   178007349),  INT32_C(   663724751),  INT32_C(   138817737),  INT32_C(   225561887), -INT32_C(  1403798398), -INT32_C(  2106795315), -INT32_C(  2084421765), -INT32_C(  2049487430),
        -INT32_C(   293914081), -INT32_C(  1508570403),  INT32_C(  1504664378), -INT32_C(  1419370455), -INT32_C(  1437091364),  INT32_C(   237814675), -INT32_C(  1114509822),  INT32_C(  1531078971) },
      { -INT32_C(   178007349),  INT32_C(   663724751),  INT32_C(   138817737),  INT32_C(   225561887), -INT32_C(  1403798398), -INT32_C(  2106795315), -INT32_C(  2084421765), -INT32_C(  2049487430),
        -INT32_C(   293914081), -INT32_C(  1508570403),  INT32_C(  1504664378), -INT32_C(  1419370455), -INT32_C(  1437091364),  INT32_C(   237814675), -INT32_C(  1114509822),  INT32_C(  1531078971) },
      { -INT32_C(    22250919),  INT32_C(    82965593),  INT32_C(    17352217),  INT32_C(    28195235), -INT32_C(   175474800), -INT32_C(   263349415), -INT32_C(   260552721), -INT32_C(   256185929),
        -INT32_C(    36739261), -INT32_C(   188571301),  INT32_C(   188083047), -INT32_C(   177421307), -INT32_C(   179636421),  INT32_C(    29726834), -INT32_C(   139313728),  INT32_C(   191384871) },
      { -INT32_C(     1390683),  INT32_C(     5185349),  INT32_C(     1084513),  INT32_C(     1762202), -INT32_C(    10967175), -INT32_C(    16459339), -INT32_C(    16284546), -INT32_C(    16011621),
        -INT32_C(     2296204), -INT32_C(    11785707),  INT32_C(    11755190), -INT32_C(    11088832), -INT32_C(    11227277),  INT32_C(     1857927), -INT32_C(     8707108),  INT32_C(    11961554) },
      { -INT32_C(       21730),  INT32_C(       81021),  INT32_C(       16945),  INT32_C(       27534), -INT32_C(      171363), -INT32_C(      257178), -INT32_C(      254447), -INT32_C(      250182),
        -INT32_C(       35879), -INT32_C(      184152),  INT32_C(      183674), -INT32_C(      173263), -INT32_C(      175427),  INT32_C(       29030), -INT32_C(      136049),  INT32_C(      186899) },
      { -INT32_C(          11),  INT32_C(          39),  INT32_C(           8),  INT32_C(          13), -INT32_C(          84), -INT32_C(         126), -INT32_C(         125), -INT32_C(         123),
        -INT32_C(          18), -INT32_C(          90),  INT32_C(          89), -INT32_C(          85), -INT32_C(          86),  INT32_C(          14), -INT32_C(          67),  INT32_C(          91) } },
    { { -INT32_C(  2142650973),  INT32_C(    19357639), -INT32_C(   480586054), -INT32_C(   745619210),  INT32_C(   226354554), -INT32_C(  1424184920), -INT32_C(   748114537), -INT32_C(  1171346922),
         INT32_C(   792360808), -INT32_C(  1859034666),  INT32_C(   779389751), -INT32_C(   973012148), -INT32_C(  1848410392), -INT32_C(  1103302873), -INT32_C(  1282300771), -INT32_C(  1234321586) },
      { -INT32_C(  2142650973),  INT32_C(    19357639), -INT32_C(   480586054), -INT32_C(   745619210),  INT32_C(   226354554), -INT32_C(  1424184920), -INT32_C(   748114537), -INT32_C(  1171346922),
         INT32_C(   792360808), -INT32_C(  1859034666),  INT32_C(   779389751), -INT32_C(   973012148), -INT32_C(  1848410392), -INT32_C(  1103302873), -INT32_C(  1282300771), -INT32_C(  1234321586) },
      { -INT32_C(   267831372),  INT32_C(     2419704), -INT32_C(    60073257), -INT32_C(    93202402),  INT32_C(    28294319), -INT32_C(   178023115), -INT32_C(    93514318), -INT32_C(   146418366),
         INT32_C(    99045101), -INT32_C(   232379334),  INT32_C(    97423718), -INT32_C(   121626519), -INT32_C(   231051299), -INT32_C(   137912860), -INT32_C(   160287597), -INT32_C(   154290199) },
      { -INT32_C(    16739461),  INT32_C(      151231), -INT32_C(     3754579), -INT32_C(     5825151),  INT32_C(     1768394), -INT32_C(    11126445), -INT32_C(     5844645), -INT32_C(     9151148),
         INT32_C(     6190318), -INT32_C(    14523709),  INT32_C(     6088982), -INT32_C(     7601658), -INT32_C(    14440707), -INT32_C(     8619554), -INT32_C(    10017975), -INT32_C(     9643138) },
      { -INT32_C(      261555),  INT32_C(        2362), -INT32_C(       58666), -INT32_C(       91018),  INT32_C(       27631), -INT32_C(      173851), -INT32_C(       91323), -INT32_C(      142987),
         INT32_C(       96723), -INT32_C(      226933),  INT32_C(       95140), -INT32_C(      118776), -INT32_C(      225637), -INT32_C(      134681), -INT32_C(      156531), -INT32_C(      150675) },
      { -INT32_C(         128),  INT32_C(           1), -INT32_C(          29), -INT32_C(          45),  INT32_C(          13), -INT32_C(          85), -INT32_C(          45), -INT32_C(          70),
         INT32_C(          47), -INT32_C(         111),  INT32_C(          46), -INT32_C(          58), -INT32_C(         111), -INT32_C(          66), -INT32_C(          77), -INT32_C(          74) } },
    { {  INT32_C(   233220151),  INT32_C(  1100879625), -INT32_C(   294710366), -INT32_C(    21729258),  INT32_C(   361728238),  INT32_C(   349424503), -INT32_C(  1094163089),  INT32_C(  1534342436),
        -INT32_C(   412525859),  INT32_C(   338167665),  INT32_C(   805476122), -INT32_C(   181422329), -INT32_C(  1240809921), -INT32_C(   104079990),  INT32_C(  1740084034), -INT32_C(  1497223992) },
      {  INT32_C(   233220151),  INT32_C(  1100879625), -INT32_C(   294710366), -INT32_C(    21729258),  INT32_C(   361728238),  INT32_C(   349424503), -INT32_C(  1094163089),  INT32_C(  1534342436),
        -INT32_C(   412525859),  INT32_C(   338167665),  INT32_C(   805476122), -INT32_C(   181422329), -INT32_C(  1240809921), -INT32_C(   104079990),  INT32_C(  1740084034), -INT32_C(  1497223992) },
      {  INT32_C(    29152518),  INT32_C(   137609953), -INT32_C(    36838796), -INT32_C(     2716158),  INT32_C(    45216029),  INT32_C(    43678062), -INT32_C(   136770387),  INT32_C(   191792804),
        -INT32_C(    51565733),  INT32_C(    42270958),  INT32_C(   100684515), -INT32_C(    22677792), -INT32_C(   155101241), -INT32_C(    13009999),  INT32_C(   217510504), -INT32_C(   187152999) },
      {  INT32_C(     1822032),  INT32_C(     8600622), -INT32_C(     2302425), -INT32_C(      169760),  INT32_C(     2826001),  INT32_C(     2729878), -INT32_C(     8548150),  INT32_C(    11987050),
        -INT32_C(     3222859),  INT32_C(     2641934),  INT32_C(     6292782), -INT32_C(     1417362), -INT32_C(     9693828), -INT32_C(      813125),  INT32_C(    13594406), -INT32_C(    11697063) },
      {  INT32_C(       28469),  INT32_C(      134384), -INT32_C(       35976), -INT32_C(        2653),  INT32_C(       44156),  INT32_C(       42654), -INT32_C(      133565),  INT32_C(      187297),
        -INT32_C(       50358),  INT32_C(       41280),  INT32_C(       98324), -INT32_C(       22147), -INT32_C(      151467), -INT32_C(       12706),  INT32_C(      212412), -INT32_C(      182767) },
      {  INT32_C(          13),  INT32_C(          65), -INT32_C(          18), -INT32_C(           2),  INT32_C(          21),  INT32_C(          20), -INT32_C(          66),  INT32_C(          91),
        -INT32_C(          25),  INT32_C(          20),  INT32_C(          48), -INT32_C(          11), -INT32_C(          74), -INT32_C(           7),  INT32_C(         103), -INT32_C(          90) } },
    { { -INT32_C(   124966010),  INT32_C(  1292678451),  INT32_C(  1400770124),  INT32_C(    71871941), -INT32_C(   172273045),  INT32_C(  1928300079), -INT32_C(   505829863),  INT32_C(  1502059474),
        -INT32_C(    95349561),  INT32_C(   356998601),  INT32_C(   828949867), -INT32_C(   566906766),  INT32_C(   852750338), -INT32_C(  1885027722),  INT32_C(   997293417), -INT32_C(   543885288) },
      { -INT32_C(   124966010),  INT32_C(  1292678451),  INT32_C(  1400770124),  INT32_C(    71871941), -INT32_C(   172273045),  INT32_C(  1928300079), -INT32_C(   505829863),  INT32_C(  1502059474),
        -INT32_C(    95349561),  INT32_C(   356998601),  INT32_C(   828949867), -INT32_C(   566906766),  INT32_C(   852750338), -INT32_C(  1885027722),  INT32_C(   997293417), -INT32_C(   543885288) },
      { -INT32_C(    15620752),  INT32_C(   161584806),  INT32_C(   175096265),  INT32_C(     8983992), -INT32_C(    21534131),  INT32_C(   241037509), -INT32_C(    63228733),  INT32_C(   187757434),
        -INT32_C(    11918696),  INT32_C(    44624825),  INT32_C(   103618733), -INT32_C(    70863346),  INT32_C(   106593792), -INT32_C(   235628466),  INT32_C(   124661677), -INT32_C(    67985661) },
      { -INT32_C(      976297),  INT32_C(    10099050),  INT32_C(    10943516),  INT32_C(      561499), -INT32_C(     1345884),  INT32_C(    15064844), -INT32_C(     3951796),  INT32_C(    11734839),
        -INT32_C(      744919),  INT32_C(     2789051),  INT32_C(     6476170), -INT32_C(     4428960),  INT32_C(     6662112), -INT32_C(    14726780),  INT32_C(     7791354), -INT32_C(     4249104) },
      { -INT32_C(       15255),  INT32_C(      157797),  INT32_C(      170992),  INT32_C(        8773), -INT32_C(       21030),  INT32_C(      235388), -INT32_C(       61747),  INT32_C(      183356),
        -INT32_C(       11640),  INT32_C(       43578),  INT32_C(      101190), -INT32_C(       69203),  INT32_C(      104095), -INT32_C(      230106),  INT32_C(      121739), -INT32_C(       66393) },
      { -INT32_C(           8),  INT32_C(          77),  INT32_C(          83),  INT32_C(           4), -INT32_C(          11),  INT32_C(         114), -INT32_C(          31),  INT32_C(          89),
        -INT32_C(           6),  INT32_C(          21),  INT32_C(          49), -INT32_C(          34),  INT32_C(          50), -INT32_C(         113),  INT32_C(          59), -INT32_C(          33) } },
    { { -INT32_C(   690363123), -INT32_C(  1360256702),  INT32_C(  1507808486),  INT32_C(   121050117),  INT32_C(  2067335685),  INT32_C(   906747341),  INT32_C(  1936817242), -INT32_C(  2125330828),
         INT32_C(   777530603),  INT32_C(   870073421), -INT32_C(  1651721320), -INT32_C(   727333937), -INT32_C(  1689198898),  INT32_C(   382819260),  INT32_C(  1267286743),  INT32_C(   885906504) },
      { -INT32_C(   690363123), -INT32_C(  1360256702),  INT32_C(  1507808486),  INT32_C(   121050117),  INT32_C(  2067335685),  INT32_C(   906747341),  INT32_C(  1936817242), -INT32_C(  2125330828),
         INT32_C(   777530603),  INT32_C(   870073421), -INT32_C(  1651721320), -INT32_C(   727333937), -INT32_C(  1689198898),  INT32_C(   382819260),  INT32_C(  1267286743),  INT32_C(   885906504) },
      { -INT32_C(    86295391), -INT32_C(   170032088),  INT32_C(   188476060),  INT32_C(    15131264),  INT32_C(   258416960),  INT32_C(   113343417),  INT32_C(   242102155), -INT32_C(   265666354),
         INT32_C(    97191325),  INT32_C(   108759177), -INT32_C(   206465165), -INT32_C(    90916743), -INT32_C(   211149863),  INT32_C(    47852407),  INT32_C(   158410842),  INT32_C(   110738313) },
      { -INT32_C(     5393462), -INT32_C(    10627006),  INT32_C(    11779753),  INT32_C(      945704),  INT32_C(    16151060),  INT32_C(     7083963),  INT32_C(    15131384), -INT32_C(    16604148),
         INT32_C(     6074457),  INT32_C(     6797448), -INT32_C(    12904073), -INT32_C(     5682297), -INT32_C(    13196867),  INT32_C(     2990775),  INT32_C(     9900677),  INT32_C(     6921144) },
      { -INT32_C(       84273), -INT32_C(      166047),  INT32_C(      184058),  INT32_C(       14776),  INT32_C(      252360),  INT32_C(      110686),  INT32_C(      236427), -INT32_C(      259440),
         INT32_C(       94913),  INT32_C(      106210), -INT32_C(      201627), -INT32_C(       88786), -INT32_C(      206202),  INT32_C(       46730),  INT32_C(      154698),  INT32_C(      108142) },
      { -INT32_C(          42), -INT32_C(          82),  INT32_C(          89),  INT32_C(           7),  INT32_C(         123),  INT32_C(          54),  INT32_C(         115), -INT32_C(         127),
         INT32_C(          46),  INT32_C(          51), -INT32_C(          99), -INT32_C(          44), -INT32_C(         101),  INT32_C(          22),  INT32_C(          75),  INT32_C(          52) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i a = simde_mm512_loadu_epi32(test_vec[i].a);
    simde__m512i r0 = simde_mm512_srai_epi32(a, 0);
    simde__m512i r3 = simde_mm512_srai_epi32(a, 3);
    simde__m512i r7 = simde_mm512_srai_epi32(a, 7);
    simde__m512i r13 = simde_mm512_srai_epi32(a, 13);
    simde__m512i r24 = simde_mm512_srai_epi32(a, 24);
    simde_test_x86_assert_equal_i32x16(r0, simde_mm512_loadu_epi32(test_vec[i].r0));
    simde_test_x86_assert_equal_i32x16(r3, simde_mm512_loadu_epi32(test_vec[i].r3));
    simde_test_x86_assert_equal_i32x16(r7, simde_mm512_loadu_epi32(test_vec[i].r7));
    simde_test_x86_assert_equal_i32x16(r13, simde_mm512_loadu_epi32(test_vec[i].r13));
    simde_test_x86_assert_equal_i32x16(r24, simde_mm512_loadu_epi32(test_vec[i].r24));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m512i a = simde_test_x86_random_i32x16();
    simde__m512i r0 = simde_mm512_srai_epi32(a, 0);
    simde__m512i r3 = simde_mm512_srai_epi32(a, 3);
    simde__m512i r7 = simde_mm512_srai_epi32(a, 7);
    simde__m512i r13 = simde_mm512_srai_epi32(a, 13);
    simde__m512i r24 = simde_mm512_srai_epi32(a, 24);

    simde_test_x86_write_i32x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x16(2, r0, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x16(2, r3, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x16(2, r7, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x16(2, r13, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x16(2, r24, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_srai_epi16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_srai_epi32)
SIMDE_TEST_FUNC_LIST_END

#include <test/x86/avx512/test-avx512-footer.h>
