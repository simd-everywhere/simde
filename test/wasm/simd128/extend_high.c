/* Copyright (c) 2021 Evan Nemerson <evan@nemerson.com>
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
 */

#define SIMDE_TEST_WASM_SIMD128_INSN extend_high
#include "../../../simde/wasm/simd128.h"
#include "test-simd128.h"

static int
test_simde_wasm_i16x8_extend_high_i8x16(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      int8_t a[sizeof(simde_v128_t) / sizeof(int8_t)];
      int16_t r[sizeof(simde_v128_t) / sizeof(int8_t)];
    } test_vec[] = {
      { { -INT8_C(  18), -INT8_C(  57), -INT8_C( 102), -INT8_C(  18),  INT8_C(  67), -INT8_C(  80), -INT8_C(  77), -INT8_C( 122),
          -INT8_C(  31), -INT8_C(  69), -INT8_C(  80),  INT8_C(  45),  INT8_C( 108), -INT8_C(  57),  INT8_C(  76), -INT8_C(  68) },
        { -INT16_C(    31), -INT16_C(    69), -INT16_C(    80),  INT16_C(    45),  INT16_C(   108), -INT16_C(    57),  INT16_C(    76), -INT16_C(    68) } },
      { {  INT8_C(  42), -INT8_C(  83), -INT8_C(  41), -INT8_C( 102), -INT8_C(  54), -INT8_C(  32),  INT8_C(  10), -INT8_C(  63),
           INT8_C(  86),  INT8_C(  32), -INT8_C(  74),  INT8_C(  65),  INT8_C( 105),  INT8_C(  16),  INT8_C(  23),  INT8_C(  39) },
        {  INT16_C(    86),  INT16_C(    32), -INT16_C(    74),  INT16_C(    65),  INT16_C(   105),  INT16_C(    16),  INT16_C(    23),  INT16_C(    39) } },
      { { -INT8_C(  18), -INT8_C(  92),  INT8_C(  28), -INT8_C(  50),  INT8_C(  41),  INT8_C(  91), -INT8_C(  75),  INT8_C(  85),
           INT8_C(  93),  INT8_C( 101), -INT8_C(  19), -INT8_C( 117),  INT8_C(   2),  INT8_C( 123), -INT8_C( 115), -INT8_C( 125) },
        {  INT16_C(    93),  INT16_C(   101), -INT16_C(    19), -INT16_C(   117),  INT16_C(     2),  INT16_C(   123), -INT16_C(   115), -INT16_C(   125) } },
      { {  INT8_C(   5), -INT8_C(  18),  INT8_C(  93),  INT8_C(  83), -INT8_C(  52),  INT8_C(  75), -INT8_C(  76),  INT8_C(   8),
          -INT8_C(  68), -INT8_C(  91), -INT8_C(  91), -INT8_C(  90),  INT8_C(  95),  INT8_C(  68), -INT8_C(  69),  INT8_C( 124) },
        { -INT16_C(    68), -INT16_C(    91), -INT16_C(    91), -INT16_C(    90),  INT16_C(    95),  INT16_C(    68), -INT16_C(    69),  INT16_C(   124) } },
      { {  INT8_C(  52),  INT8_C( 121), -INT8_C(  86), -INT8_C(  38),  INT8_C(  79),  INT8_C( 122),  INT8_C( 123),  INT8_C(  68),
           INT8_C(  61),  INT8_C(   1), -INT8_C( 123),  INT8_C(  86), -INT8_C(  38),  INT8_C(  68), -INT8_C(  76), -INT8_C(  62) },
        {  INT16_C(    61),  INT16_C(     1), -INT16_C(   123),  INT16_C(    86), -INT16_C(    38),  INT16_C(    68), -INT16_C(    76), -INT16_C(    62) } },
      { {  INT8_C(  43),  INT8_C(  79),  INT8_C(  35), -INT8_C(  93), -INT8_C(   3), -INT8_C(  62), -INT8_C(  24),  INT8_C( 118),
           INT8_C(   7),  INT8_C( 116), -INT8_C(  91), -INT8_C(  21),  INT8_C(  22),  INT8_C(  49),  INT8_C(  86),  INT8_C(  27) },
        {  INT16_C(     7),  INT16_C(   116), -INT16_C(    91), -INT16_C(    21),  INT16_C(    22),  INT16_C(    49),  INT16_C(    86),  INT16_C(    27) } },
      { { -INT8_C(  95), -INT8_C(  78), -INT8_C( 123),  INT8_C( 125), -INT8_C(  54), -INT8_C(   6),  INT8_C(  48), -INT8_C(  73),
          -INT8_C(  37),  INT8_C(  28), -INT8_C(  26), -INT8_C(  69),  INT8_C(  70),  INT8_C(  40), -INT8_C(  67),  INT8_C( 124) },
        { -INT16_C(    37),  INT16_C(    28), -INT16_C(    26), -INT16_C(    69),  INT16_C(    70),  INT16_C(    40), -INT16_C(    67),  INT16_C(   124) } },
      { {  INT8_C(  18),  INT8_C( 103), -INT8_C(  60), -INT8_C(  91),  INT8_C(  90), -INT8_C(   5),  INT8_C(  60),  INT8_C(  45),
          -INT8_C(  75),  INT8_C( 101),  INT8_C(  54),  INT8_C(  73),  INT8_C(  76),  INT8_C(   4), -INT8_C(  17), -INT8_C( 103) },
        { -INT16_C(    75),  INT16_C(   101),  INT16_C(    54),  INT16_C(    73),  INT16_C(    76),  INT16_C(     4), -INT16_C(    17), -INT16_C(   103) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t r = simde_wasm_i16x8_extend_high_i8x16(a);
      simde_test_wasm_i16x8_assert_equal(r, simde_wasm_v128_load(test_vec[i].r));
    }
    return 0;
  #else
    fputc('\n', stdout);
    for (int i = 0 ; i < 8 ; i++) {
      simde_v128_t
        a = simde_test_wasm_i8x16_random(),
        r;

      r = simde_wasm_i16x8_extend_high_i8x16(a);

      simde_test_wasm_i8x16_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_i16x8_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_i32x4_extend_high_i16x8(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      int16_t a[sizeof(simde_v128_t) / sizeof(int8_t)];
      int32_t r[sizeof(simde_v128_t) / sizeof(int8_t)];
    } test_vec[] = {
      { { -INT16_C( 21082),  INT16_C(   322),  INT16_C( 12431), -INT16_C( 20993), -INT16_C( 21422),  INT16_C( 31516),  INT16_C(  1812),  INT16_C( 28477) },
        { -INT32_C(       21422),  INT32_C(       31516),  INT32_C(        1812),  INT32_C(       28477) } },
      { {  INT16_C( 26041),  INT16_C( 16669),  INT16_C( 12818),  INT16_C(  5960), -INT16_C( 12764),  INT16_C( 30490),  INT16_C( 20664),  INT16_C( 23772) },
        { -INT32_C(       12764),  INT32_C(       30490),  INT32_C(       20664),  INT32_C(       23772) } },
      { { -INT16_C(  6514),  INT16_C( 20491), -INT16_C(  2189), -INT16_C(  2176),  INT16_C(  8226), -INT16_C( 25741), -INT16_C( 25620),  INT16_C(  8751) },
        {  INT32_C(        8226), -INT32_C(       25741), -INT32_C(       25620),  INT32_C(        8751) } },
      { { -INT16_C(    88), -INT16_C( 19116),  INT16_C(  1853), -INT16_C(  9246),  INT16_C( 22530),  INT16_C(  4276), -INT16_C( 11479),  INT16_C( 29778) },
        {  INT32_C(       22530),  INT32_C(        4276), -INT32_C(       11479),  INT32_C(       29778) } },
      { { -INT16_C( 21947),  INT16_C( 16223),  INT16_C( 19361), -INT16_C(  4178), -INT16_C(  5538), -INT16_C( 31328), -INT16_C(  3287),  INT16_C( 32331) },
        { -INT32_C(        5538), -INT32_C(       31328), -INT32_C(        3287),  INT32_C(       32331) } },
      { { -INT16_C(  6780), -INT16_C( 24747), -INT16_C(  9191),  INT16_C( 21961),  INT16_C( 18228),  INT16_C( 31468), -INT16_C( 20451), -INT16_C(  4738) },
        {  INT32_C(       18228),  INT32_C(       31468), -INT32_C(       20451), -INT32_C(        4738) } },
      { {  INT16_C( 17322),  INT16_C( 21337),  INT16_C( 28058), -INT16_C( 19621), -INT16_C( 27049), -INT16_C( 19367),  INT16_C( 30515), -INT16_C(  5163) },
        { -INT32_C(       27049), -INT32_C(       19367),  INT32_C(       30515), -INT32_C(        5163) } },
      { { -INT16_C( 22763),  INT16_C( 32473), -INT16_C( 18489), -INT16_C( 28964),  INT16_C( 20289),  INT16_C( 19349),  INT16_C( 13021), -INT16_C( 21738) },
        {  INT32_C(       20289),  INT32_C(       19349),  INT32_C(       13021), -INT32_C(       21738) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t r = simde_wasm_i32x4_extend_high_i16x8(a);
      simde_test_wasm_i32x4_assert_equal(r, simde_wasm_v128_load(test_vec[i].r));
    }
    return 0;
  #else
    fputc('\n', stdout);
    for (int i = 0 ; i < 8 ; i++) {
      simde_v128_t
        a = simde_test_wasm_i8x16_random(),
        r;

      r = simde_wasm_i32x4_extend_high_i16x8(a);

      simde_test_wasm_i16x8_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_i32x4_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_i64x2_extend_high_i32x4(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      int32_t a[sizeof(simde_v128_t) / sizeof(int32_t)];
      int64_t r[sizeof(simde_v128_t) / sizeof(int64_t)];
    } test_vec[] = {
      { {  INT32_C(   238395344),  INT32_C(  1701299054),  INT32_C(  1175317166), -INT32_C(   331494218) },
        {  INT64_C(          1175317166), -INT64_C(           331494218) } },
      { { -INT32_C(  1753245830),  INT32_C(   622664055), -INT32_C(    63978864), -INT32_C(    79065234) },
        { -INT64_C(            63978864), -INT64_C(            79065234) } },
      { { -INT32_C(  1459892042), -INT32_C(  1492886193), -INT32_C(   640501768),  INT32_C(   165128003) },
        { -INT64_C(           640501768),  INT64_C(           165128003) } },
      { {  INT32_C(  1794077097), -INT32_C(   104599170), -INT32_C(   432453771),  INT32_C(  1979562042) },
        { -INT64_C(           432453771),  INT64_C(          1979562042) } },
      { {  INT32_C(  1128872225),  INT32_C(   347280191), -INT32_C(  1114439508),  INT32_C(  1513398275) },
        { -INT64_C(          1114439508),  INT64_C(          1513398275) } },
      { { -INT32_C(   973826002),  INT32_C(   348344884),  INT32_C(   836543455),  INT32_C(   673913493) },
        {  INT64_C(           836543455),  INT64_C(           673913493) } },
      { {  INT32_C(  1763720822), -INT32_C(  1541551179), -INT32_C(  2140770574),  INT32_C(  1244392986) },
        { -INT64_C(          2140770574),  INT64_C(          1244392986) } },
      { { -INT32_C(  1527480883),  INT32_C(   673819203), -INT32_C(  1449718419),  INT32_C(   780937665) },
        { -INT64_C(          1449718419),  INT64_C(           780937665) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t r = simde_wasm_i64x2_extend_high_i32x4(a);
      simde_test_wasm_i64x2_assert_equal(r, simde_wasm_v128_load(test_vec[i].r));
    }
    return 0;
  #else
    fputc('\n', stdout);
    for (int i = 0 ; i < 8 ; i++) {
      simde_v128_t
        a = simde_test_wasm_i8x16_random(),
        r;

      r = simde_wasm_i64x2_extend_high_i32x4(a);

      simde_test_wasm_i32x4_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_i64x2_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_u16x8_extend_high_u8x16(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      uint8_t a[sizeof(simde_v128_t) / sizeof(int8_t)];
      int16_t r[sizeof(simde_v128_t) / sizeof(int8_t)];
    } test_vec[] = {
      { { UINT8_C( 82), UINT8_C(169), UINT8_C(113), UINT8_C( 10), UINT8_C(172), UINT8_C(128), UINT8_C( 33), UINT8_C(212),
          UINT8_C(201), UINT8_C( 82), UINT8_C(130), UINT8_C(214), UINT8_C( 92), UINT8_C( 99), UINT8_C(246), UINT8_C(223) },
        {  INT16_C(   201),  INT16_C(    82),  INT16_C(   130),  INT16_C(   214),  INT16_C(    92),  INT16_C(    99),  INT16_C(   246),  INT16_C(   223) } },
      { { UINT8_C(212), UINT8_C( 47), UINT8_C(233), UINT8_C(190), UINT8_C(128), UINT8_C(160), UINT8_C(207), UINT8_C( 49),
          UINT8_C( 66), UINT8_C(222), UINT8_C( 74), UINT8_C( 52), UINT8_C( 26), UINT8_C(  8), UINT8_C(103), UINT8_C(189) },
        {  INT16_C(    66),  INT16_C(   222),  INT16_C(    74),  INT16_C(    52),  INT16_C(    26),  INT16_C(     8),  INT16_C(   103),  INT16_C(   189) } },
      { { UINT8_C(218), UINT8_C(176), UINT8_C(193), UINT8_C(159), UINT8_C(237), UINT8_C(167), UINT8_C(214), UINT8_C(150),
          UINT8_C(128), UINT8_C(  2), UINT8_C(204), UINT8_C(119), UINT8_C( 59), UINT8_C(202), UINT8_C(138), UINT8_C(248) },
        {  INT16_C(   128),  INT16_C(     2),  INT16_C(   204),  INT16_C(   119),  INT16_C(    59),  INT16_C(   202),  INT16_C(   138),  INT16_C(   248) } },
      { { UINT8_C(243), UINT8_C(167), UINT8_C(223), UINT8_C( 61), UINT8_C( 89), UINT8_C(126), UINT8_C( 87), UINT8_C(133),
          UINT8_C( 69), UINT8_C(240), UINT8_C(218), UINT8_C(103), UINT8_C(  6), UINT8_C(  4), UINT8_C(239), UINT8_C( 57) },
        {  INT16_C(    69),  INT16_C(   240),  INT16_C(   218),  INT16_C(   103),  INT16_C(     6),  INT16_C(     4),  INT16_C(   239),  INT16_C(    57) } },
      { { UINT8_C(173), UINT8_C(181), UINT8_C(197), UINT8_C( 84), UINT8_C(186), UINT8_C(165), UINT8_C(128), UINT8_C(158),
          UINT8_C(138), UINT8_C(202), UINT8_C(214), UINT8_C( 39), UINT8_C(132), UINT8_C( 16), UINT8_C(117), UINT8_C(150) },
        {  INT16_C(   138),  INT16_C(   202),  INT16_C(   214),  INT16_C(    39),  INT16_C(   132),  INT16_C(    16),  INT16_C(   117),  INT16_C(   150) } },
      { { UINT8_C(233), UINT8_C(237), UINT8_C(234), UINT8_C( 83), UINT8_C(116), UINT8_C(119), UINT8_C(228), UINT8_C(225),
          UINT8_C( 62), UINT8_C( 87), UINT8_C( 32), UINT8_C(122), UINT8_C(240), UINT8_C( 95), UINT8_C(110), UINT8_C(140) },
        {  INT16_C(    62),  INT16_C(    87),  INT16_C(    32),  INT16_C(   122),  INT16_C(   240),  INT16_C(    95),  INT16_C(   110),  INT16_C(   140) } },
      { { UINT8_C( 83), UINT8_C(210), UINT8_C(159), UINT8_C( 56), UINT8_C(174), UINT8_C(253), UINT8_C(197), UINT8_C( 51),
          UINT8_C(221), UINT8_C( 35), UINT8_C(214), UINT8_C( 32), UINT8_C(103), UINT8_C(237), UINT8_C(116), UINT8_C(237) },
        {  INT16_C(   221),  INT16_C(    35),  INT16_C(   214),  INT16_C(    32),  INT16_C(   103),  INT16_C(   237),  INT16_C(   116),  INT16_C(   237) } },
      { { UINT8_C(128), UINT8_C(128), UINT8_C( 16), UINT8_C( 86), UINT8_C(194), UINT8_C(210), UINT8_C(210), UINT8_C(163),
          UINT8_C(114), UINT8_C(148), UINT8_C(112), UINT8_C(212), UINT8_C( 95), UINT8_C(113), UINT8_C(117), UINT8_C( 87) },
        {  INT16_C(   114),  INT16_C(   148),  INT16_C(   112),  INT16_C(   212),  INT16_C(    95),  INT16_C(   113),  INT16_C(   117),  INT16_C(    87) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t r = simde_wasm_u16x8_extend_high_u8x16(a);
      simde_test_wasm_i16x8_assert_equal(r, simde_wasm_v128_load(test_vec[i].r));
    }
    return 0;
  #else
    fputc('\n', stdout);
    for (int i = 0 ; i < 8 ; i++) {
      simde_v128_t
        a = simde_test_wasm_u8x16_random(),
        r;

      r = simde_wasm_u16x8_extend_high_u8x16(a);

      simde_test_wasm_u8x16_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_i16x8_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_u32x4_extend_high_u16x8(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      uint16_t a[sizeof(simde_v128_t) / sizeof(int8_t)];
      int32_t r[sizeof(simde_v128_t) / sizeof(int8_t)];
    } test_vec[] = {
      { { UINT16_C(34872), UINT16_C(27867), UINT16_C(36895), UINT16_C(60129), UINT16_C(25987), UINT16_C(27572), UINT16_C(60007), UINT16_C(41076) },
        {  INT32_C(       25987),  INT32_C(       27572),  INT32_C(       60007),  INT32_C(       41076) } },
      { { UINT16_C(61788), UINT16_C(42421), UINT16_C(20798), UINT16_C(43289), UINT16_C( 7005), UINT16_C(36469), UINT16_C(62379), UINT16_C(50303) },
        {  INT32_C(        7005),  INT32_C(       36469),  INT32_C(       62379),  INT32_C(       50303) } },
      { { UINT16_C(61691), UINT16_C(61106), UINT16_C(47383), UINT16_C(59159), UINT16_C(55369), UINT16_C(36532), UINT16_C(25531), UINT16_C(54369) },
        {  INT32_C(       55369),  INT32_C(       36532),  INT32_C(       25531),  INT32_C(       54369) } },
      { { UINT16_C(52487), UINT16_C(11671), UINT16_C( 5026), UINT16_C(18820), UINT16_C(10788), UINT16_C(57234), UINT16_C(49180), UINT16_C(23679) },
        {  INT32_C(       10788),  INT32_C(       57234),  INT32_C(       49180),  INT32_C(       23679) } },
      { { UINT16_C(27957), UINT16_C(56268), UINT16_C(62418), UINT16_C(36262), UINT16_C(17123), UINT16_C(43926), UINT16_C(   32), UINT16_C(52602) },
        {  INT32_C(       17123),  INT32_C(       43926),  INT32_C(          32),  INT32_C(       52602) } },
      { { UINT16_C( 5246), UINT16_C(29016), UINT16_C(62120), UINT16_C(49762), UINT16_C( 5752), UINT16_C(  459), UINT16_C( 4736), UINT16_C(24823) },
        {  INT32_C(        5752),  INT32_C(         459),  INT32_C(        4736),  INT32_C(       24823) } },
      { { UINT16_C(54216), UINT16_C(15747), UINT16_C(61879), UINT16_C(47417), UINT16_C(63901), UINT16_C(11063), UINT16_C(47934), UINT16_C(64807) },
        {  INT32_C(       63901),  INT32_C(       11063),  INT32_C(       47934),  INT32_C(       64807) } },
      { { UINT16_C( 8504), UINT16_C( 3709), UINT16_C(26051), UINT16_C(15544), UINT16_C( 6153), UINT16_C(38690), UINT16_C(16204), UINT16_C(40326) },
        {  INT32_C(        6153),  INT32_C(       38690),  INT32_C(       16204),  INT32_C(       40326) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t r = simde_wasm_u32x4_extend_high_u16x8(a);
      simde_test_wasm_i32x4_assert_equal(r, simde_wasm_v128_load(test_vec[i].r));
    }
    return 0;
  #else
    fputc('\n', stdout);
    for (int i = 0 ; i < 8 ; i++) {
      simde_v128_t
        a = simde_test_wasm_u8x16_random(),
        r;

      r = simde_wasm_u32x4_extend_high_u16x8(a);

      simde_test_wasm_u16x8_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_i32x4_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_u64x2_extend_high_u32x4(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      uint32_t a[sizeof(simde_v128_t) / sizeof(uint32_t)];
      uint64_t r[sizeof(simde_v128_t) / sizeof(uint64_t)];
    } test_vec[] = {
      { { UINT32_C(3492816261), UINT32_C( 374371223), UINT32_C(1280354564), UINT32_C(1353897448) },
        { UINT64_C(          1280354564), UINT64_C(          1353897448) } },
      { { UINT32_C(1832597250), UINT32_C( 135696588), UINT32_C(2843782158), UINT32_C(3021846826) },
        { UINT64_C(          2843782158), UINT64_C(          3021846826) } },
      { { UINT32_C( 925107204), UINT32_C(  67085352), UINT32_C( 762288779), UINT32_C(1526899656) },
        { UINT64_C(           762288779), UINT64_C(          1526899656) } },
      { { UINT32_C(2450076471), UINT32_C(2025923338), UINT32_C( 489529369), UINT32_C( 720941550) },
        { UINT64_C(           489529369), UINT64_C(           720941550) } },
      { { UINT32_C(3430164863), UINT32_C(1950594664), UINT32_C(3501210740), UINT32_C(3392219484) },
        { UINT64_C(          3501210740), UINT64_C(          3392219484) } },
      { { UINT32_C(3055574141), UINT32_C(2297617789), UINT32_C( 103387622), UINT32_C(4240133605) },
        { UINT64_C(           103387622), UINT64_C(          4240133605) } },
      { { UINT32_C( 279971799), UINT32_C(4040646144), UINT32_C(3438863429), UINT32_C(3763845971) },
        { UINT64_C(          3438863429), UINT64_C(          3763845971) } },
      { { UINT32_C(1356056511), UINT32_C(1627911311), UINT32_C(2145367778), UINT32_C(3193885735) },
        { UINT64_C(          2145367778), UINT64_C(          3193885735) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t r = simde_wasm_u64x2_extend_high_u32x4(a);
      simde_test_wasm_u64x2_assert_equal(r, simde_wasm_v128_load(test_vec[i].r));
    }
    return 0;
  #else
    fputc('\n', stdout);
    for (int i = 0 ; i < 8 ; i++) {
      simde_v128_t
        a = simde_test_wasm_u8x16_random(),
        r;

      r = simde_wasm_u64x2_extend_high_u32x4(a);

      simde_test_wasm_u32x4_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_u64x2_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_i16x8_extend_high_i8x16)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_i32x4_extend_high_i16x8)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_i64x2_extend_high_i32x4)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_u16x8_extend_high_u8x16)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_u32x4_extend_high_u16x8)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_u64x2_extend_high_u32x4)
SIMDE_TEST_FUNC_LIST_END

#include "test-simd128-footer.h"
