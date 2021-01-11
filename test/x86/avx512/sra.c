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

#define SIMDE_TEST_X86_AVX512_INSN sra

#include <test/x86/avx512/test-avx512.h>
#include <simde/x86/avx512/sra.h>

static int
test_simde_mm512_sra_epi16 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const int16_t a[32];
    const int64_t b[2];
    const int16_t r[32];
  } test_vec[] = {
    { {  INT16_C( 11061),  INT16_C(  2909),  INT16_C(  7771), -INT16_C( 15451),  INT16_C( 10536),  INT16_C( 16880),  INT16_C(  9564),  INT16_C(  7363),
         INT16_C( 22530), -INT16_C(  8028),  INT16_C(  1724), -INT16_C( 32593), -INT16_C( 10410),  INT16_C(  1671),  INT16_C( 28692),  INT16_C( 18993),
        -INT16_C( 29029), -INT16_C(  2475), -INT16_C(  1107), -INT16_C( 10822), -INT16_C( 21980), -INT16_C( 32490), -INT16_C(  9777), -INT16_C( 11619),
         INT16_C( 16689), -INT16_C(  4686),  INT16_C( 25159), -INT16_C( 25235), -INT16_C(  2759),  INT16_C( 19876), -INT16_C( 10907),  INT16_C(   407) },
      {  INT64_C(                   0),  INT64_C(                   0) },
      {  INT16_C( 11061),  INT16_C(  2909),  INT16_C(  7771), -INT16_C( 15451),  INT16_C( 10536),  INT16_C( 16880),  INT16_C(  9564),  INT16_C(  7363),
         INT16_C( 22530), -INT16_C(  8028),  INT16_C(  1724), -INT16_C( 32593), -INT16_C( 10410),  INT16_C(  1671),  INT16_C( 28692),  INT16_C( 18993),
        -INT16_C( 29029), -INT16_C(  2475), -INT16_C(  1107), -INT16_C( 10822), -INT16_C( 21980), -INT16_C( 32490), -INT16_C(  9777), -INT16_C( 11619),
         INT16_C( 16689), -INT16_C(  4686),  INT16_C( 25159), -INT16_C( 25235), -INT16_C(  2759),  INT16_C( 19876), -INT16_C( 10907),  INT16_C(   407) } },
    { { -INT16_C( 20629), -INT16_C( 19467),  INT16_C( 25361),  INT16_C( 19024), -INT16_C(  2984), -INT16_C( 17000),  INT16_C( 12234),  INT16_C( 11966),
        -INT16_C( 18916),  INT16_C(  1087),  INT16_C(  9575), -INT16_C( 15599), -INT16_C( 25054), -INT16_C(  1554), -INT16_C(  5175),  INT16_C( 13313),
        -INT16_C(  2406), -INT16_C( 21273),  INT16_C( 14425), -INT16_C( 19978), -INT16_C( 29140), -INT16_C(  2449),  INT16_C( 11710), -INT16_C(  9692),
         INT16_C( 25571),  INT16_C( 19423), -INT16_C(  3959), -INT16_C( 21746), -INT16_C(   882),  INT16_C( 22436), -INT16_C( 23065), -INT16_C( 32372) },
      {  INT64_C(                  13),  INT64_C(                   2) },
      { -INT16_C(     3), -INT16_C(     3),  INT16_C(     3),  INT16_C(     2), -INT16_C(     1), -INT16_C(     3),  INT16_C(     1),  INT16_C(     1),
        -INT16_C(     3),  INT16_C(     0),  INT16_C(     1), -INT16_C(     2), -INT16_C(     4), -INT16_C(     1), -INT16_C(     1),  INT16_C(     1),
        -INT16_C(     1), -INT16_C(     3),  INT16_C(     1), -INT16_C(     3), -INT16_C(     4), -INT16_C(     1),  INT16_C(     1), -INT16_C(     2),
         INT16_C(     3),  INT16_C(     2), -INT16_C(     1), -INT16_C(     3), -INT16_C(     1),  INT16_C(     2), -INT16_C(     3), -INT16_C(     4) } },
    { {  INT16_C( 10838), -INT16_C(  8334), -INT16_C( 32742), -INT16_C( 22389),  INT16_C( 12156),  INT16_C( 25344), -INT16_C( 29483),  INT16_C( 29156),
         INT16_C(  4863), -INT16_C( 21658),  INT16_C(  3382), -INT16_C(  6013),  INT16_C( 20771),  INT16_C( 26457), -INT16_C( 23484), -INT16_C( 25714),
         INT16_C(   206), -INT16_C(  6022),  INT16_C(  1408), -INT16_C(   880), -INT16_C( 28619),  INT16_C(  2655),  INT16_C( 17180),  INT16_C(  7291),
        -INT16_C(  7851), -INT16_C( 29753),  INT16_C( 19183),  INT16_C(  4724), -INT16_C( 12901), -INT16_C(  8071),  INT16_C(  1905),  INT16_C( 16251) },
      {  INT64_C(                   3),  INT64_C(                   7) },
      {  INT16_C(  1354), -INT16_C(  1042), -INT16_C(  4093), -INT16_C(  2799),  INT16_C(  1519),  INT16_C(  3168), -INT16_C(  3686),  INT16_C(  3644),
         INT16_C(   607), -INT16_C(  2708),  INT16_C(   422), -INT16_C(   752),  INT16_C(  2596),  INT16_C(  3307), -INT16_C(  2936), -INT16_C(  3215),
         INT16_C(    25), -INT16_C(   753),  INT16_C(   176), -INT16_C(   110), -INT16_C(  3578),  INT16_C(   331),  INT16_C(  2147),  INT16_C(   911),
        -INT16_C(   982), -INT16_C(  3720),  INT16_C(  2397),  INT16_C(   590), -INT16_C(  1613), -INT16_C(  1009),  INT16_C(   238),  INT16_C(  2031) } },
    { {  INT16_C( 18326), -INT16_C( 31481),  INT16_C( 31633),  INT16_C( 11672),  INT16_C(  4424), -INT16_C( 18163), -INT16_C( 30695),  INT16_C(  8440),
         INT16_C(  8061),  INT16_C( 30888),  INT16_C( 11222),  INT16_C(  7848), -INT16_C(  7666),  INT16_C( 13443),  INT16_C(   919),  INT16_C( 11951),
        -INT16_C( 18869), -INT16_C(  9037),  INT16_C( 19249),  INT16_C( 30985),  INT16_C(  5725),  INT16_C( 30258),  INT16_C( 10910),  INT16_C(  7318),
         INT16_C( 15945),  INT16_C(  8340),  INT16_C( 15722),  INT16_C( 30782), -INT16_C( 16097), -INT16_C( 18516),  INT16_C( 23493),  INT16_C(  4325) },
      {  INT64_C(                   4),  INT64_C(                   6) },
      {  INT16_C(  1145), -INT16_C(  1968),  INT16_C(  1977),  INT16_C(   729),  INT16_C(   276), -INT16_C(  1136), -INT16_C(  1919),  INT16_C(   527),
         INT16_C(   503),  INT16_C(  1930),  INT16_C(   701),  INT16_C(   490), -INT16_C(   480),  INT16_C(   840),  INT16_C(    57),  INT16_C(   746),
        -INT16_C(  1180), -INT16_C(   565),  INT16_C(  1203),  INT16_C(  1936),  INT16_C(   357),  INT16_C(  1891),  INT16_C(   681),  INT16_C(   457),
         INT16_C(   996),  INT16_C(   521),  INT16_C(   982),  INT16_C(  1923), -INT16_C(  1007), -INT16_C(  1158),  INT16_C(  1468),  INT16_C(   270) } },
    { {  INT16_C( 23436), -INT16_C(  2429), -INT16_C( 15720), -INT16_C( 18322),  INT16_C(  6787),  INT16_C( 18543),  INT16_C( 21621), -INT16_C( 30888),
         INT16_C( 17900), -INT16_C( 12085), -INT16_C( 30661),  INT16_C( 18193), -INT16_C( 14217), -INT16_C( 28174), -INT16_C( 18154), -INT16_C( 23819),
         INT16_C( 30741), -INT16_C( 21096),  INT16_C(  1594), -INT16_C( 16795), -INT16_C( 11232), -INT16_C( 27386),  INT16_C( 24360),  INT16_C(  5405),
        -INT16_C(  5980), -INT16_C(  8219), -INT16_C(  2192), -INT16_C(  6362),  INT16_C(  6591), -INT16_C( 10887),  INT16_C( 28370), -INT16_C(  6281) },
      {  INT64_C(                   3),  INT64_C(                  14) },
      {  INT16_C(  2929), -INT16_C(   304), -INT16_C(  1965), -INT16_C(  2291),  INT16_C(   848),  INT16_C(  2317),  INT16_C(  2702), -INT16_C(  3861),
         INT16_C(  2237), -INT16_C(  1511), -INT16_C(  3833),  INT16_C(  2274), -INT16_C(  1778), -INT16_C(  3522), -INT16_C(  2270), -INT16_C(  2978),
         INT16_C(  3842), -INT16_C(  2637),  INT16_C(   199), -INT16_C(  2100), -INT16_C(  1404), -INT16_C(  3424),  INT16_C(  3045),  INT16_C(   675),
        -INT16_C(   748), -INT16_C(  1028), -INT16_C(   274), -INT16_C(   796),  INT16_C(   823), -INT16_C(  1361),  INT16_C(  3546), -INT16_C(   786) } },
    { { -INT16_C(  3376),  INT16_C( 16583), -INT16_C(  4375), -INT16_C( 22489), -INT16_C( 24569), -INT16_C(  9858), -INT16_C(  2802), -INT16_C(  2623),
         INT16_C( 22021),  INT16_C(  6678), -INT16_C(  2736),  INT16_C(  8016),  INT16_C(  7130),  INT16_C(  7959),  INT16_C(  8963), -INT16_C( 11513),
        -INT16_C( 12523), -INT16_C(   493),  INT16_C( 15037), -INT16_C( 15193),  INT16_C(  9691), -INT16_C(  5731),  INT16_C( 24090),  INT16_C(  8158),
        -INT16_C(  2892),  INT16_C(  1338), -INT16_C( 29975), -INT16_C( 15324),  INT16_C( 15269), -INT16_C( 22301), -INT16_C(  5537),  INT16_C( 29819) },
      {  INT64_C(                  10),  INT64_C(                  14) },
      { -INT16_C(     4),  INT16_C(    16), -INT16_C(     5), -INT16_C(    22), -INT16_C(    24), -INT16_C(    10), -INT16_C(     3), -INT16_C(     3),
         INT16_C(    21),  INT16_C(     6), -INT16_C(     3),  INT16_C(     7),  INT16_C(     6),  INT16_C(     7),  INT16_C(     8), -INT16_C(    12),
        -INT16_C(    13), -INT16_C(     1),  INT16_C(    14), -INT16_C(    15),  INT16_C(     9), -INT16_C(     6),  INT16_C(    23),  INT16_C(     7),
        -INT16_C(     3),  INT16_C(     1), -INT16_C(    30), -INT16_C(    15),  INT16_C(    14), -INT16_C(    22), -INT16_C(     6),  INT16_C(    29) } },
    { { -INT16_C( 19616),  INT16_C( 18928),  INT16_C(  5181), -INT16_C(  7667), -INT16_C(  4016), -INT16_C( 20598),  INT16_C(  1499), -INT16_C( 27613),
        -INT16_C( 26989),  INT16_C( 23307),  INT16_C( 17840), -INT16_C(  4097), -INT16_C( 29667),  INT16_C( 21577), -INT16_C( 15625),  INT16_C( 22335),
         INT16_C( 12149), -INT16_C( 19807), -INT16_C( 20925), -INT16_C( 27756),  INT16_C(  7839),  INT16_C( 31298),  INT16_C( 26147), -INT16_C( 18930),
         INT16_C(  6652), -INT16_C( 21231),  INT16_C(  4191),  INT16_C( 31900), -INT16_C(  6756), -INT16_C( 27440),  INT16_C(  4007),  INT16_C(  7403) },
      {  INT64_C(                  13),  INT64_C(                  11) },
      { -INT16_C(     3),  INT16_C(     2),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     3),  INT16_C(     0), -INT16_C(     4),
        -INT16_C(     4),  INT16_C(     2),  INT16_C(     2), -INT16_C(     1), -INT16_C(     4),  INT16_C(     2), -INT16_C(     2),  INT16_C(     2),
         INT16_C(     1), -INT16_C(     3), -INT16_C(     3), -INT16_C(     4),  INT16_C(     0),  INT16_C(     3),  INT16_C(     3), -INT16_C(     3),
         INT16_C(     0), -INT16_C(     3),  INT16_C(     0),  INT16_C(     3), -INT16_C(     1), -INT16_C(     4),  INT16_C(     0),  INT16_C(     0) } },
    { {  INT16_C( 27516), -INT16_C(  9369),  INT16_C(  1147),  INT16_C(  6231),  INT16_C( 10473), -INT16_C( 28244), -INT16_C( 26825),  INT16_C( 30381),
         INT16_C( 31780),  INT16_C( 24568),  INT16_C(  3550),  INT16_C( 24377), -INT16_C( 29339),  INT16_C(  8962),  INT16_C( 23791),  INT16_C( 27614),
         INT16_C( 17863),  INT16_C( 16966), -INT16_C( 25015),  INT16_C( 13146),  INT16_C(  1734), -INT16_C(   572),  INT16_C( 29086), -INT16_C( 15757),
         INT16_C( 27629), -INT16_C( 13279),  INT16_C( 23161), -INT16_C(  8661),  INT16_C( 11751), -INT16_C( 10750), -INT16_C(  8055),  INT16_C( 20546) },
      {  INT64_C(                  14),  INT64_C(                  12) },
      {  INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     2), -INT16_C(     2),  INT16_C(     1),
         INT16_C(     1),  INT16_C(     1),  INT16_C(     0),  INT16_C(     1), -INT16_C(     2),  INT16_C(     0),  INT16_C(     1),  INT16_C(     1),
         INT16_C(     1),  INT16_C(     1), -INT16_C(     2),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     1), -INT16_C(     1),
         INT16_C(     1), -INT16_C(     1),  INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     1) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i a = simde_mm512_loadu_epi16(test_vec[i].a);
    simde__m128i b = simde_x_mm_loadu_epi64(test_vec[i].b);
    simde__m512i r = simde_mm512_sra_epi16(a, b);
    simde_test_x86_assert_equal_i16x32(r, simde_mm512_loadu_epi16(test_vec[i].r));
  }

  return 0;
}

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_sra_epi16)
SIMDE_TEST_FUNC_LIST_END

#include <test/x86/avx512/test-avx512-footer.h>
