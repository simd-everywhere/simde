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

#define SIMDE_TEST_WASM_SIMD128_INSN extend_low
#include "../../../simde/wasm/simd128.h"
#include "test-simd128.h"

static int
test_simde_wasm_i16x8_extend_low_i8x16(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      int8_t a[sizeof(simde_v128_t) / sizeof(int8_t)];
      int16_t r[sizeof(simde_v128_t) / sizeof(int8_t)];
    } test_vec[] = {
      { {  INT8_C(  68), -INT8_C(  14), -INT8_C(  60), -INT8_C(  87), -INT8_C(  23),  INT8_C(  40),  INT8_C(  25),  INT8_C( 124),
          -INT8_C(  34), -INT8_C( 112), -INT8_C(  39), -INT8_C( 125),  INT8_C(  16), -INT8_C(  98),  INT8_C(  65),  INT8_C(  84) },
        {  INT16_C(    68), -INT16_C(    14), -INT16_C(    60), -INT16_C(    87), -INT16_C(    23),  INT16_C(    40),  INT16_C(    25),  INT16_C(   124) } },
      { {  INT8_C(  18), -INT8_C(   2), -INT8_C( 119), -INT8_C( 112), -INT8_C(  16), -INT8_C( 117),  INT8_C( 110),  INT8_C(  49),
           INT8_C(  61),  INT8_C(  20),  INT8_C( 124),  INT8_C( 101),  INT8_C(  43), -INT8_C(  25), -INT8_C( 127), -INT8_C(  81) },
        {  INT16_C(    18), -INT16_C(     2), -INT16_C(   119), -INT16_C(   112), -INT16_C(    16), -INT16_C(   117),  INT16_C(   110),  INT16_C(    49) } },
      { { -INT8_C(   4),  INT8_C(   3),  INT8_C(  64), -INT8_C(  35),  INT8_C(  26),  INT8_C(  99), -INT8_C(  27),  INT8_C(  92),
          -INT8_C(  36), -INT8_C( 103),  INT8_C(   1),  INT8_C(  36), -INT8_C(  63),  INT8_C(  52),  INT8_C(  88), -INT8_C(  24) },
        { -INT16_C(     4),  INT16_C(     3),  INT16_C(    64), -INT16_C(    35),  INT16_C(    26),  INT16_C(    99), -INT16_C(    27),  INT16_C(    92) } },
      { {  INT8_C(  54), -INT8_C(  64),  INT8_C(  28),  INT8_C(  63),  INT8_C(  73),  INT8_C( 107),  INT8_C( 119), -INT8_C(   9),
          -INT8_C(  44), -INT8_C(  87),  INT8_C(   4), -INT8_C( 104),  INT8_C(   4),  INT8_C(  62),  INT8_C( 103),  INT8_C(  43) },
        {  INT16_C(    54), -INT16_C(    64),  INT16_C(    28),  INT16_C(    63),  INT16_C(    73),  INT16_C(   107),  INT16_C(   119), -INT16_C(     9) } },
      { { -INT8_C(  36), -INT8_C( 103), -INT8_C(  42),  INT8_C( 100), -INT8_C(  26), -INT8_C(  61), -INT8_C(  31), -INT8_C( 118),
           INT8_C(  86), -INT8_C(  95), -INT8_C(  82),  INT8_C(  51),  INT8_C(  43),  INT8_C(  31), -INT8_C(  75), -INT8_C(  76) },
        { -INT16_C(    36), -INT16_C(   103), -INT16_C(    42),  INT16_C(   100), -INT16_C(    26), -INT16_C(    61), -INT16_C(    31), -INT16_C(   118) } },
      { {  INT8_C( 124), -INT8_C(  15), -INT8_C(  22),  INT8_C(  75), -INT8_C(  19), -INT8_C( 120), -INT8_C(  50), -INT8_C(  81),
          -INT8_C(  14), -INT8_C(  55),  INT8_C(  57), -INT8_C(  53),  INT8_C(  20), -INT8_C(  44), -INT8_C( 114), -INT8_C( 120) },
        {  INT16_C(   124), -INT16_C(    15), -INT16_C(    22),  INT16_C(    75), -INT16_C(    19), -INT16_C(   120), -INT16_C(    50), -INT16_C(    81) } },
      { { -INT8_C(  29),  INT8_C( 115),  INT8_C(  67), -INT8_C(   8),  INT8_C(  21), -INT8_C(  87),  INT8_C(  72),  INT8_C(  86),
          -INT8_C(  53),  INT8_C(  32), -INT8_C(  89), -INT8_C( 120), -INT8_C(  49), -INT8_C(  48),  INT8_C( 109), -INT8_C( 105) },
        { -INT16_C(    29),  INT16_C(   115),  INT16_C(    67), -INT16_C(     8),  INT16_C(    21), -INT16_C(    87),  INT16_C(    72),  INT16_C(    86) } },
      { { -INT8_C(  83), -INT8_C(  70), -INT8_C(  47), -INT8_C(  15), -INT8_C( 107), -INT8_C( 119), -INT8_C(   7),  INT8_C(  51),
           INT8_C(  84),  INT8_C(  76),  INT8_C(  29),  INT8_C(  95), -INT8_C( 123),  INT8_C(  11),  INT8_C( 113), -INT8_C(  34) },
        { -INT16_C(    83), -INT16_C(    70), -INT16_C(    47), -INT16_C(    15), -INT16_C(   107), -INT16_C(   119), -INT16_C(     7),  INT16_C(    51) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t r = simde_wasm_i16x8_extend_low_i8x16(a);
      simde_test_wasm_i16x8_assert_equal(r, simde_wasm_v128_load(test_vec[i].r));
    }
    return 0;
  #else
    fputc('\n', stdout);
    for (int i = 0 ; i < 8 ; i++) {
      simde_v128_t
        a = simde_test_wasm_i8x16_random(),
        r;

      r = simde_wasm_i16x8_extend_low_i8x16(a);

      simde_test_wasm_i8x16_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_i16x8_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_i32x4_extend_low_i16x8(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      int16_t a[sizeof(simde_v128_t) / sizeof(int16_t)];
      int32_t r[sizeof(simde_v128_t) / sizeof(int32_t)];
    } test_vec[] = {
      { {  INT16_C(  8389),  INT16_C(  1607),  INT16_C( 26232),  INT16_C( 26243), -INT16_C( 26031),  INT16_C( 22916), -INT16_C( 24632), -INT16_C( 22659) },
        {  INT32_C(        8389),  INT32_C(        1607),  INT32_C(       26232),  INT32_C(       26243) } },
      { { -INT16_C( 21539), -INT16_C(  7023), -INT16_C( 30945), -INT16_C( 28532), -INT16_C( 16962), -INT16_C(  3518),  INT16_C( 28675),  INT16_C( 22962) },
        { -INT32_C(       21539), -INT32_C(        7023), -INT32_C(       30945), -INT32_C(       28532) } },
      { {  INT16_C(  5891),  INT16_C( 13777), -INT16_C(  8367),  INT16_C(  2188), -INT16_C(  9786), -INT16_C( 26511), -INT16_C(  9728), -INT16_C( 28384) },
        {  INT32_C(        5891),  INT32_C(       13777), -INT32_C(        8367),  INT32_C(        2188) } },
      { { -INT16_C( 25630),  INT16_C( 22089),  INT16_C( 27669),  INT16_C( 10526), -INT16_C(  8186),  INT16_C(  5653),  INT16_C( 18469), -INT16_C( 19505) },
        { -INT32_C(       25630),  INT32_C(       22089),  INT32_C(       27669),  INT32_C(       10526) } },
      { { -INT16_C(  1260),  INT16_C(  3019), -INT16_C( 17202), -INT16_C( 29189),  INT16_C( 25744), -INT16_C( 24242), -INT16_C( 13738),  INT16_C( 23233) },
        { -INT32_C(        1260),  INT32_C(        3019), -INT32_C(       17202), -INT32_C(       29189) } },
      { { -INT16_C( 11579),  INT16_C( 31798),  INT16_C( 18573), -INT16_C( 11179), -INT16_C( 10194),  INT16_C(   142), -INT16_C( 28964), -INT16_C(   390) },
        { -INT32_C(       11579),  INT32_C(       31798),  INT32_C(       18573), -INT32_C(       11179) } },
      { {  INT16_C(  9336), -INT16_C(  4032),  INT16_C( 29292), -INT16_C( 31394), -INT16_C( 11647),  INT16_C( 10968), -INT16_C( 16377),  INT16_C( 27759) },
        {  INT32_C(        9336), -INT32_C(        4032),  INT32_C(       29292), -INT32_C(       31394) } },
      { { -INT16_C( 18338), -INT16_C( 19953), -INT16_C( 20645), -INT16_C( 31863), -INT16_C(  9601), -INT16_C(  7535),  INT16_C( 21772), -INT16_C( 26392) },
        { -INT32_C(       18338), -INT32_C(       19953), -INT32_C(       20645), -INT32_C(       31863) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t r = simde_wasm_i32x4_extend_low_i16x8(a);
      simde_test_wasm_i32x4_assert_equal(r, simde_wasm_v128_load(test_vec[i].r));
    }
    return 0;
  #else
    fputc('\n', stdout);
    for (int i = 0 ; i < 8 ; i++) {
      simde_v128_t
        a = simde_test_wasm_i8x16_random(),
        r;

      r = simde_wasm_i32x4_extend_low_i16x8(a);

      simde_test_wasm_i16x8_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_i32x4_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_i64x2_extend_low_i32x4(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      int32_t a[sizeof(simde_v128_t) / sizeof(int32_t)];
      int64_t r[sizeof(simde_v128_t) / sizeof(int64_t)];
    } test_vec[] = {
      { { -INT32_C(   507804972),  INT32_C(   704648766), -INT32_C(  1617250246),  INT32_C(   184858722) },
        { -INT64_C(           507804972),  INT64_C(           704648766) } },
      { {  INT32_C(  1137474837), -INT32_C(   245340237),  INT32_C(  1338060841),  INT32_C(  1484738740) },
        {  INT64_C(          1137474837), -INT64_C(           245340237) } },
      { { -INT32_C(   532124662),  INT32_C(  1872605754),  INT32_C(  1745087161),  INT32_C(  1241460220) },
        { -INT64_C(           532124662),  INT64_C(          1872605754) } },
      { { -INT32_C(  1494018971), -INT32_C(   348390244), -INT32_C(  1218214522), -INT32_C(  1862120421) },
        { -INT64_C(          1494018971), -INT64_C(           348390244) } },
      { { -INT32_C(   506034934),  INT32_C(   741975567), -INT32_C(  1879742045),  INT32_C(   380127845) },
        { -INT64_C(           506034934),  INT64_C(           741975567) } },
      { {  INT32_C(    82290058), -INT32_C(   759481411), -INT32_C(   339127647), -INT32_C(  1806326560) },
        {  INT64_C(            82290058), -INT64_C(           759481411) } },
      { {  INT32_C(    75667462),  INT32_C(   553714471), -INT32_C(   396982097),  INT32_C(  2135132949) },
        {  INT64_C(            75667462),  INT64_C(           553714471) } },
      { { -INT32_C(   768039944), -INT32_C(   721292869),  INT32_C(   638272872), -INT32_C(  1600797988) },
        { -INT64_C(           768039944), -INT64_C(           721292869) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t r = simde_wasm_i64x2_extend_low_i32x4(a);
      simde_test_wasm_i64x2_assert_equal(r, simde_wasm_v128_load(test_vec[i].r));
    }
    return 0;
  #else
    fputc('\n', stdout);
    for (int i = 0 ; i < 8 ; i++) {
      simde_v128_t
        a = simde_test_wasm_i8x16_random(),
        r;

      r = simde_wasm_i64x2_extend_low_i32x4(a);

      simde_test_wasm_i32x4_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_i64x2_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_u16x8_extend_low_u8x16(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      uint8_t a[sizeof(simde_v128_t) / sizeof(int8_t)];
      int16_t r[sizeof(simde_v128_t) / sizeof(int16_t)];
    } test_vec[] = {
      { {    UINT8_MAX, UINT8_C( 79), UINT8_C( 34), UINT8_C(150), UINT8_C( 81), UINT8_C( 61), UINT8_C(159), UINT8_C(182),
          UINT8_C(130), UINT8_C(198), UINT8_C(242), UINT8_C( 45), UINT8_C(184), UINT8_C( 27), UINT8_C( 63), UINT8_C( 98) },
        {  INT16_C(   255),  INT16_C(    79),  INT16_C(    34),  INT16_C(   150),  INT16_C(    81),  INT16_C(    61),  INT16_C(   159),  INT16_C(   182) } },
      { { UINT8_C(183), UINT8_C(225), UINT8_C(170), UINT8_C( 20), UINT8_C( 19), UINT8_C(198), UINT8_C( 85), UINT8_C( 17),
          UINT8_C(109), UINT8_C( 49), UINT8_C(152), UINT8_C(154), UINT8_C(213), UINT8_C( 81), UINT8_C(183), UINT8_C(106) },
        {  INT16_C(   183),  INT16_C(   225),  INT16_C(   170),  INT16_C(    20),  INT16_C(    19),  INT16_C(   198),  INT16_C(    85),  INT16_C(    17) } },
      { { UINT8_C(238), UINT8_C( 46), UINT8_C(170), UINT8_C(251), UINT8_C( 72), UINT8_C(137), UINT8_C(249), UINT8_C(103),
          UINT8_C(  5), UINT8_C( 58), UINT8_C(137), UINT8_C(122), UINT8_C(194), UINT8_C( 82), UINT8_C(253), UINT8_C(107) },
        {  INT16_C(   238),  INT16_C(    46),  INT16_C(   170),  INT16_C(   251),  INT16_C(    72),  INT16_C(   137),  INT16_C(   249),  INT16_C(   103) } },
      { { UINT8_C( 45), UINT8_C( 38), UINT8_C( 95), UINT8_C(200), UINT8_C(227), UINT8_C(192), UINT8_C( 68), UINT8_C(190),
          UINT8_C(  3), UINT8_C(172), UINT8_C(109), UINT8_C(112), UINT8_C(  8), UINT8_C(180), UINT8_C(165), UINT8_C(185) },
        {  INT16_C(    45),  INT16_C(    38),  INT16_C(    95),  INT16_C(   200),  INT16_C(   227),  INT16_C(   192),  INT16_C(    68),  INT16_C(   190) } },
      { { UINT8_C(252), UINT8_C(174), UINT8_C(150), UINT8_C( 74), UINT8_C(206), UINT8_C(219), UINT8_C(243), UINT8_C(101),
          UINT8_C( 60), UINT8_C(109), UINT8_C(201), UINT8_C( 95), UINT8_C(129), UINT8_C(144), UINT8_C(248), UINT8_C(176) },
        {  INT16_C(   252),  INT16_C(   174),  INT16_C(   150),  INT16_C(    74),  INT16_C(   206),  INT16_C(   219),  INT16_C(   243),  INT16_C(   101) } },
      { { UINT8_C( 89), UINT8_C( 76), UINT8_C( 49), UINT8_C( 20), UINT8_C( 33), UINT8_C( 78), UINT8_C( 16), UINT8_C(161),
          UINT8_C(143), UINT8_C( 16), UINT8_C(207), UINT8_C(185), UINT8_C(130), UINT8_C(231), UINT8_C(131), UINT8_C(120) },
        {  INT16_C(    89),  INT16_C(    76),  INT16_C(    49),  INT16_C(    20),  INT16_C(    33),  INT16_C(    78),  INT16_C(    16),  INT16_C(   161) } },
      { { UINT8_C(  4), UINT8_C(250), UINT8_C( 38), UINT8_C( 16), UINT8_C( 15), UINT8_C(244), UINT8_C(170), UINT8_C(234),
          UINT8_C(100), UINT8_C( 89), UINT8_C(107), UINT8_C(183), UINT8_C( 99), UINT8_C(105), UINT8_C(198), UINT8_C( 22) },
        {  INT16_C(     4),  INT16_C(   250),  INT16_C(    38),  INT16_C(    16),  INT16_C(    15),  INT16_C(   244),  INT16_C(   170),  INT16_C(   234) } },
      { { UINT8_C( 24), UINT8_C(191), UINT8_C(131), UINT8_C(186), UINT8_C(250), UINT8_C(143), UINT8_C( 85), UINT8_C( 47),
          UINT8_C( 65), UINT8_C( 60), UINT8_C( 28), UINT8_C(251), UINT8_C(  1), UINT8_C(  7), UINT8_C(122), UINT8_C( 60) },
        {  INT16_C(    24),  INT16_C(   191),  INT16_C(   131),  INT16_C(   186),  INT16_C(   250),  INT16_C(   143),  INT16_C(    85),  INT16_C(    47) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t r = simde_wasm_u16x8_extend_low_u8x16(a);
      simde_test_wasm_i16x8_assert_equal(r, simde_wasm_v128_load(test_vec[i].r));
    }
    return 0;
  #else
    fputc('\n', stdout);
    for (int i = 0 ; i < 8 ; i++) {
      simde_v128_t
        a = simde_test_wasm_u8x16_random(),
        r;

      r = simde_wasm_u16x8_extend_low_u8x16(a);

      simde_test_wasm_u8x16_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_i16x8_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_u32x4_extend_low_u16x8(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      uint16_t a[sizeof(simde_v128_t) / sizeof(int16_t)];
      uint32_t r[sizeof(simde_v128_t) / sizeof(uint32_t)];
    } test_vec[] = {
      { { UINT16_C(64864), UINT16_C(30841), UINT16_C(21049), UINT16_C(28226), UINT16_C(52160), UINT16_C(31342), UINT16_C( 1459), UINT16_C(62548) },
        { UINT32_C(     64864), UINT32_C(     30841), UINT32_C(     21049), UINT32_C(     28226) } },
      { { UINT16_C( 1755), UINT16_C(21130), UINT16_C(54370), UINT16_C(31848), UINT16_C(42403), UINT16_C(35925), UINT16_C(35104), UINT16_C(17385) },
        { UINT32_C(      1755), UINT32_C(     21130), UINT32_C(     54370), UINT32_C(     31848) } },
      { { UINT16_C(29209), UINT16_C(57692), UINT16_C(21600), UINT16_C(27641), UINT16_C(38826), UINT16_C(50864), UINT16_C(65164), UINT16_C(64912) },
        { UINT32_C(     29209), UINT32_C(     57692), UINT32_C(     21600), UINT32_C(     27641) } },
      { { UINT16_C(56899), UINT16_C(49586), UINT16_C(  386), UINT16_C(18134), UINT16_C(49030), UINT16_C(11629), UINT16_C(44084), UINT16_C(53044) },
        { UINT32_C(     56899), UINT32_C(     49586), UINT32_C(       386), UINT32_C(     18134) } },
      { { UINT16_C(23994), UINT16_C(15136), UINT16_C(17591), UINT16_C(  489), UINT16_C(23938), UINT16_C(36597), UINT16_C( 4241), UINT16_C(30035) },
        { UINT32_C(     23994), UINT32_C(     15136), UINT32_C(     17591), UINT32_C(       489) } },
      { { UINT16_C(25035), UINT16_C(63325), UINT16_C(65099), UINT16_C(47758), UINT16_C(54457), UINT16_C(36534), UINT16_C(37585), UINT16_C(21064) },
        { UINT32_C(     25035), UINT32_C(     63325), UINT32_C(     65099), UINT32_C(     47758) } },
      { { UINT16_C(42174), UINT16_C(18290), UINT16_C(36982), UINT16_C(31789), UINT16_C(19303), UINT16_C( 6728), UINT16_C(50642), UINT16_C(15764) },
        { UINT32_C(     42174), UINT32_C(     18290), UINT32_C(     36982), UINT32_C(     31789) } },
      { { UINT16_C(30667), UINT16_C(38197), UINT16_C(13091), UINT16_C(  136), UINT16_C(35813), UINT16_C(44718), UINT16_C(46110), UINT16_C( 3993) },
        { UINT32_C(     30667), UINT32_C(     38197), UINT32_C(     13091), UINT32_C(       136) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t r = simde_wasm_u32x4_extend_low_u16x8(a);
      simde_test_wasm_i32x4_assert_equal(r, simde_wasm_v128_load(test_vec[i].r));
    }
    return 0;
  #else
    fputc('\n', stdout);
    for (int i = 0 ; i < 8 ; i++) {
      simde_v128_t
        a = simde_test_wasm_u8x16_random(),
        r;

      r = simde_wasm_u32x4_extend_low_u16x8(a);

      simde_test_wasm_u16x8_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_u32x4_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_u64x2_extend_low_u32x4(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      uint32_t a[sizeof(simde_v128_t) / sizeof(uint32_t)];
      uint64_t r[sizeof(simde_v128_t) / sizeof(uint64_t)];
    } test_vec[] = {
      { { UINT32_C( 949779057), UINT32_C(2065062506), UINT32_C(2872992032), UINT32_C(3150513840) },
        { UINT64_C(           949779057), UINT64_C(          2065062506) } },
      { { UINT32_C(2259027420), UINT32_C( 691988536), UINT32_C(3302307506), UINT32_C(1092849081) },
        { UINT64_C(          2259027420), UINT64_C(           691988536) } },
      { { UINT32_C(1333127901), UINT32_C(1212188779), UINT32_C(2964843667), UINT32_C(1853198698) },
        { UINT64_C(          1333127901), UINT64_C(          1212188779) } },
      { { UINT32_C(3602527511), UINT32_C(2952526324), UINT32_C(2534214597), UINT32_C(1871411414) },
        { UINT64_C(          3602527511), UINT64_C(          2952526324) } },
      { { UINT32_C(2104478493), UINT32_C(3704175810), UINT32_C(1007368766), UINT32_C(3764908461) },
        { UINT64_C(          2104478493), UINT64_C(          3704175810) } },
      { { UINT32_C( 588839320), UINT32_C(1611029680), UINT32_C(2715336186), UINT32_C(1645877310) },
        { UINT64_C(           588839320), UINT64_C(          1611029680) } },
      { { UINT32_C(4054102937), UINT32_C(2257699835), UINT32_C(3452066532), UINT32_C( 927458491) },
        { UINT64_C(          4054102937), UINT64_C(          2257699835) } },
      { { UINT32_C(4133554568), UINT32_C(3166545334), UINT32_C( 760164146), UINT32_C(1424515906) },
        { UINT64_C(          4133554568), UINT64_C(          3166545334) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t r = simde_wasm_u64x2_extend_low_u32x4(a);
      simde_test_wasm_u64x2_assert_equal(r, simde_wasm_v128_load(test_vec[i].r));
    }
    return 0;
  #else
    fputc('\n', stdout);
    for (int i = 0 ; i < 8 ; i++) {
      simde_v128_t
        a = simde_test_wasm_u8x16_random(),
        r;

      r = simde_wasm_u64x2_extend_low_u32x4(a);

      simde_test_wasm_u32x4_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_u64x2_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_i16x8_extend_low_i8x16)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_i32x4_extend_low_i16x8)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_i64x2_extend_low_i32x4)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_u16x8_extend_low_u8x16)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_u32x4_extend_low_u16x8)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_u64x2_extend_low_u32x4)
SIMDE_TEST_FUNC_LIST_END

#include "test-simd128-footer.h"
