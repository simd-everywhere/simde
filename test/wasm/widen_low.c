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

#define SIMDE_TESTS_CURRENT_ISAX simd128
#include <simde/wasm/simd128.h>
#include <test/wasm/test-simd128.h>

static int
test_simde_wasm_i16x8_widen_low_i8x16(SIMDE_MUNIT_TEST_ARGS) {
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
      simde_v128_t r = simde_wasm_i16x8_widen_low_i8x16(a);
      simde_test_wasm_i16x8_assert_equal(r, simde_wasm_v128_load(test_vec[i].r));
    }
    return 0;
  #else
    fputc('\n', stdout);
    for (int i = 0 ; i < 8 ; i++) {
      simde_v128_t
        a = simde_test_wasm_i8x16_random(),
        r;

      r = simde_wasm_i16x8_widen_low_i8x16(a);

      simde_test_wasm_i8x16_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_i16x8_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_i32x4_widen_low_i16x8(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      int16_t a[sizeof(simde_v128_t) / sizeof(int8_t)];
      int32_t r[sizeof(simde_v128_t) / sizeof(int8_t)];
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
      simde_v128_t r = simde_wasm_i32x4_widen_low_i16x8(a);
      simde_test_wasm_i32x4_assert_equal(r, simde_wasm_v128_load(test_vec[i].r));
    }
    return 0;
  #else
    fputc('\n', stdout);
    for (int i = 0 ; i < 8 ; i++) {
      simde_v128_t
        a = simde_test_wasm_i8x16_random(),
        r;

      r = simde_wasm_i32x4_widen_low_i16x8(a);

      simde_test_wasm_i16x8_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_i32x4_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_i16x8_widen_low_u8x16(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      uint8_t a[sizeof(simde_v128_t) / sizeof(int8_t)];
      int16_t r[sizeof(simde_v128_t) / sizeof(int8_t)];
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
      simde_v128_t r = simde_wasm_i16x8_widen_low_u8x16(a);
      simde_test_wasm_i16x8_assert_equal(r, simde_wasm_v128_load(test_vec[i].r));
    }
    return 0;
  #else
    fputc('\n', stdout);
    for (int i = 0 ; i < 8 ; i++) {
      simde_v128_t
        a = simde_test_wasm_u8x16_random(),
        r;

      r = simde_wasm_i16x8_widen_low_u8x16(a);

      simde_test_wasm_u8x16_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_i16x8_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_i32x4_widen_low_u16x8(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      uint16_t a[sizeof(simde_v128_t) / sizeof(int8_t)];
      int32_t r[sizeof(simde_v128_t) / sizeof(int8_t)];
    } test_vec[] = {
      { { UINT16_C(30058), UINT16_C(33255), UINT16_C(54838), UINT16_C(38939), UINT16_C(53467), UINT16_C( 4085), UINT16_C(57512), UINT16_C(26364) },
        {  INT32_C(       30058),  INT32_C(       33255),  INT32_C(       54838),  INT32_C(       38939) } },
      { { UINT16_C(16960), UINT16_C(53761), UINT16_C(39423), UINT16_C(22336), UINT16_C(46155), UINT16_C(21871), UINT16_C(  748), UINT16_C(47443) },
        {  INT32_C(       16960),  INT32_C(       53761),  INT32_C(       39423),  INT32_C(       22336) } },
      { { UINT16_C(21202), UINT16_C(16776), UINT16_C(34071), UINT16_C(63335), UINT16_C(29886), UINT16_C(54129), UINT16_C(34547), UINT16_C(10578) },
        {  INT32_C(       21202),  INT32_C(       16776),  INT32_C(       34071),  INT32_C(       63335) } },
      { { UINT16_C(15383), UINT16_C(23861), UINT16_C(62357), UINT16_C(47256), UINT16_C(22079), UINT16_C(27412), UINT16_C(30888), UINT16_C(25437) },
        {  INT32_C(       15383),  INT32_C(       23861),  INT32_C(       62357),  INT32_C(       47256) } },
      { { UINT16_C(42341), UINT16_C(44085), UINT16_C(20322), UINT16_C(27806), UINT16_C(10505), UINT16_C(63658), UINT16_C( 8284), UINT16_C(  328) },
        {  INT32_C(       42341),  INT32_C(       44085),  INT32_C(       20322),  INT32_C(       27806) } },
      { { UINT16_C(37464), UINT16_C(18849), UINT16_C(40418), UINT16_C(24135), UINT16_C(35052), UINT16_C(53118), UINT16_C( 7007), UINT16_C(33494) },
        {  INT32_C(       37464),  INT32_C(       18849),  INT32_C(       40418),  INT32_C(       24135) } },
      { { UINT16_C(63374), UINT16_C(43115), UINT16_C(35150), UINT16_C(47362), UINT16_C( 2616), UINT16_C(10713), UINT16_C(51704), UINT16_C(34387) },
        {  INT32_C(       63374),  INT32_C(       43115),  INT32_C(       35150),  INT32_C(       47362) } },
      { { UINT16_C(62638), UINT16_C(  850), UINT16_C(37691), UINT16_C(64858), UINT16_C(62144), UINT16_C(61119), UINT16_C(38743), UINT16_C(54481) },
        {  INT32_C(       62638),  INT32_C(         850),  INT32_C(       37691),  INT32_C(       64858) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t r = simde_wasm_i32x4_widen_low_u16x8(a);
      simde_test_wasm_i32x4_assert_equal(r, simde_wasm_v128_load(test_vec[i].r));
    }
    return 0;
  #else
    fputc('\n', stdout);
    for (int i = 0 ; i < 8 ; i++) {
      simde_v128_t
        a = simde_test_wasm_u8x16_random(),
        r;

      r = simde_wasm_i32x4_widen_low_u16x8(a);

      simde_test_wasm_u16x8_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_i32x4_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_i16x8_widen_low_i8x16)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_i32x4_widen_low_i16x8)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_i16x8_widen_low_u8x16)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_i32x4_widen_low_u16x8)
SIMDE_TEST_FUNC_LIST_END

#include <test/x86/test-x86-footer.h>
