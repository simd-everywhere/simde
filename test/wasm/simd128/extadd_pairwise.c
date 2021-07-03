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

#define SIMDE_TEST_WASM_SIMD128_INSN extadd_pairwise
#include "../../../simde/wasm/simd128.h"
#include "test-simd128.h"

static int
test_simde_wasm_i16x8_extadd_pairwise_i8x16(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      int8_t a[sizeof(simde_v128_t) / sizeof(int8_t)];
      int16_t r[sizeof(simde_v128_t) / sizeof(int8_t)];
    } test_vec[] = {
      { { -INT8_C(  84),  INT8_C(  21),  INT8_C(  92), -INT8_C(  72), -INT8_C(  77), -INT8_C(  10), -INT8_C(   1),  INT8_C(  66),
               INT8_MIN, -INT8_C(  10),  INT8_C(  70),  INT8_C(  24),  INT8_C(  65), -INT8_C(  69),  INT8_C( 101),  INT8_C(  71) },
        { -INT16_C(    63),  INT16_C(    20), -INT16_C(    87),  INT16_C(    65), -INT16_C(   138),  INT16_C(    94), -INT16_C(     4),  INT16_C(   172) } },
      { {  INT8_C(   4), -INT8_C( 107),  INT8_C(  28), -INT8_C(   9),  INT8_C( 120),  INT8_C( 120), -INT8_C(  77), -INT8_C(  61),
          -INT8_C(  56), -INT8_C(  83), -INT8_C(  51),  INT8_C(  49),  INT8_C(  80),  INT8_C(  53),  INT8_C(  43),  INT8_C(   1) },
        { -INT16_C(   103),  INT16_C(    19),  INT16_C(   240), -INT16_C(   138), -INT16_C(   139), -INT16_C(     2),  INT16_C(   133),  INT16_C(    44) } },
      { { -INT8_C(  56), -INT8_C(  34),  INT8_C(  55),  INT8_C(  48),  INT8_C(  50), -INT8_C(  69),  INT8_C(  99), -INT8_C(  67),
          -INT8_C( 103),  INT8_C(  45), -INT8_C( 101), -INT8_C(  19), -INT8_C(   1), -INT8_C(  47),  INT8_C(   5),  INT8_C(  52) },
        { -INT16_C(    90),  INT16_C(   103), -INT16_C(    19),  INT16_C(    32), -INT16_C(    58), -INT16_C(   120), -INT16_C(    48),  INT16_C(    57) } },
      { { -INT8_C(  17),  INT8_C( 105),  INT8_C(  77), -INT8_C(  67), -INT8_C( 106), -INT8_C(  54),  INT8_C(  69), -INT8_C(  61),
           INT8_C(  60),  INT8_C(  91), -INT8_C(  66),  INT8_C(  51),  INT8_C(   2),  INT8_C(   6),  INT8_C(  23), -INT8_C(  91) },
        {  INT16_C(    88),  INT16_C(    10), -INT16_C(   160),  INT16_C(     8),  INT16_C(   151), -INT16_C(    15),  INT16_C(     8), -INT16_C(    68) } },
      { {  INT8_C(  10),  INT8_C(  45), -INT8_C(  26),  INT8_C(  16),  INT8_C( 117),  INT8_C( 122),  INT8_C(  18), -INT8_C(  23),
          -INT8_C(  95), -INT8_C(  72), -INT8_C(  20),  INT8_C(  94),  INT8_C(   1), -INT8_C(  99), -INT8_C(  44), -INT8_C(  27) },
        {  INT16_C(    55), -INT16_C(    10),  INT16_C(   239), -INT16_C(     5), -INT16_C(   167),  INT16_C(    74), -INT16_C(    98), -INT16_C(    71) } },
      { {  INT8_C(  83), -INT8_C(  37), -INT8_C(  65),  INT8_C(  78), -INT8_C(  35), -INT8_C( 108), -INT8_C( 107),  INT8_C(  13),
          -INT8_C(  60),  INT8_C(  79),  INT8_C(  83), -INT8_C(  52),  INT8_C(   4), -INT8_C(  68),  INT8_C( 116),  INT8_C(  48) },
        {  INT16_C(    46),  INT16_C(    13), -INT16_C(   143), -INT16_C(    94),  INT16_C(    19),  INT16_C(    31), -INT16_C(    64),  INT16_C(   164) } },
      { {  INT8_C(  76), -INT8_C(  35), -INT8_C(  19),  INT8_C(  36), -INT8_C(  85),  INT8_C(  35), -INT8_C(  14), -INT8_C(  77),
           INT8_C( 117),  INT8_C(  37), -INT8_C(  19),  INT8_C(  87),  INT8_C(  25), -INT8_C(  38), -INT8_C(  31), -INT8_C(  90) },
        {  INT16_C(    41),  INT16_C(    17), -INT16_C(    50), -INT16_C(    91),  INT16_C(   154),  INT16_C(    68), -INT16_C(    13), -INT16_C(   121) } },
      { { -INT8_C( 117), -INT8_C( 100),  INT8_C(  75),  INT8_C(  78),  INT8_C(  42),  INT8_C( 103),  INT8_C(  13), -INT8_C(  10),
          -INT8_C(   9), -INT8_C(  76), -INT8_C(  23),  INT8_C(  73), -INT8_C(  66),  INT8_C(  14), -INT8_C( 121),  INT8_C(  93) },
        { -INT16_C(   217),  INT16_C(   153),  INT16_C(   145),  INT16_C(     3), -INT16_C(    85),  INT16_C(    50), -INT16_C(    52), -INT16_C(    28) } },
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t r = simde_wasm_i16x8_extadd_pairwise_i8x16(a);
      simde_test_wasm_i16x8_assert_equal(r, simde_wasm_v128_load(test_vec[i].r));
    }
    return 0;
  #else
    fputc('\n', stdout);
    for (int i = 0 ; i < 8 ; i++) {
      simde_v128_t
        a = simde_test_wasm_i8x16_random(),
        r;

      r = simde_wasm_i16x8_extadd_pairwise_i8x16(a);

      simde_test_wasm_i8x16_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_i16x8_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_i32x4_extadd_pairwise_i16x8(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      int16_t a[sizeof(simde_v128_t) / sizeof(int8_t)];
      int32_t r[sizeof(simde_v128_t) / sizeof(int8_t)];
    } test_vec[] = {
      { { -INT16_C(  9469),  INT16_C(  4261),  INT16_C( 14840), -INT16_C( 18135), -INT16_C( 18231), -INT16_C( 10260),  INT16_C( 30377), -INT16_C(  8184) },
        { -INT32_C(        5208), -INT32_C(        3295), -INT32_C(       28491),  INT32_C(       22193) } },
      { {  INT16_C( 26316),  INT16_C( 16194),  INT16_C( 22503),  INT16_C(  1120),  INT16_C( 23631),  INT16_C( 11598), -INT16_C( 31350),  INT16_C(  7091) },
        {  INT32_C(       42510),  INT32_C(       23623),  INT32_C(       35229), -INT32_C(       24259) } },
      { { -INT16_C( 32471), -INT16_C(  9988), -INT16_C( 17883), -INT16_C( 13561),  INT16_C( 16247), -INT16_C( 16322), -INT16_C( 31198),  INT16_C( 31312) },
        { -INT32_C(       42459), -INT32_C(       31444), -INT32_C(          75),  INT32_C(         114) } },
      { {  INT16_C( 14687), -INT16_C(  6162),  INT16_C( 18635),  INT16_C(  8958), -INT16_C( 29384), -INT16_C( 17854),  INT16_C( 10582), -INT16_C( 20904) },
        {  INT32_C(        8525),  INT32_C(       27593), -INT32_C(       47238), -INT32_C(       10322) } },
      { {  INT16_C( 15078), -INT16_C(  4202), -INT16_C( 22154), -INT16_C( 21116),  INT16_C( 18084),  INT16_C( 31908),  INT16_C( 17730), -INT16_C(  6490) },
        {  INT32_C(       10876), -INT32_C(       43270),  INT32_C(       49992),  INT32_C(       11240) } },
      { {  INT16_C(  4783), -INT16_C( 19785), -INT16_C( 25157),  INT16_C( 16559),  INT16_C(  9430),  INT16_C( 25523),  INT16_C( 17021),  INT16_C( 26371) },
        { -INT32_C(       15002), -INT32_C(        8598),  INT32_C(       34953),  INT32_C(       43392) } },
      { { -INT16_C( 25057), -INT16_C( 11194),  INT16_C( 26272),  INT16_C( 19043),  INT16_C( 28490),  INT16_C( 11211),  INT16_C( 22563), -INT16_C( 23067) },
        { -INT32_C(       36251),  INT32_C(       45315),  INT32_C(       39701), -INT32_C(         504) } },
      { {  INT16_C( 10019), -INT16_C(  9479), -INT16_C( 18279),  INT16_C( 30782),  INT16_C( 17946),  INT16_C( 28601),  INT16_C(  6445),  INT16_C( 21219) },
        {  INT32_C(         540),  INT32_C(       12503),  INT32_C(       46547),  INT32_C(       27664) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t r = simde_wasm_i32x4_extadd_pairwise_i16x8(a);
      simde_test_wasm_i32x4_assert_equal(r, simde_wasm_v128_load(test_vec[i].r));
    }
    return 0;
  #else
    fputc('\n', stdout);
    for (int i = 0 ; i < 8 ; i++) {
      simde_v128_t
        a = simde_test_wasm_i8x16_random(),
        r;

      r = simde_wasm_i32x4_extadd_pairwise_i16x8(a);

      simde_test_wasm_i16x8_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_i32x4_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_u16x8_extadd_pairwise_u8x16(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      uint8_t a[sizeof(simde_v128_t) / sizeof(int8_t)];
      int16_t r[sizeof(simde_v128_t) / sizeof(int8_t)];
    } test_vec[] = {
      { { UINT8_C(183), UINT8_C( 37), UINT8_C( 65), UINT8_C(216), UINT8_C( 18), UINT8_C(213), UINT8_C( 33), UINT8_C( 58),
          UINT8_C(247), UINT8_C(129), UINT8_C( 60), UINT8_C(  3), UINT8_C(109), UINT8_C(166), UINT8_C( 83), UINT8_C(127) },
        {  INT16_C(   220),  INT16_C(   281),  INT16_C(   231),  INT16_C(    91),  INT16_C(   376),  INT16_C(    63),  INT16_C(   275),  INT16_C(   210) } },
      { { UINT8_C(100), UINT8_C(252), UINT8_C( 86), UINT8_C(148), UINT8_C(169), UINT8_C( 49), UINT8_C( 77), UINT8_C( 52),
          UINT8_C(136), UINT8_C(214), UINT8_C( 21), UINT8_C( 44), UINT8_C( 77), UINT8_C(101), UINT8_C( 14), UINT8_C(199) },
        {  INT16_C(   352),  INT16_C(   234),  INT16_C(   218),  INT16_C(   129),  INT16_C(   350),  INT16_C(    65),  INT16_C(   178),  INT16_C(   213) } },
      { { UINT8_C( 62), UINT8_C(224), UINT8_C(150), UINT8_C(229), UINT8_C( 14), UINT8_C(226), UINT8_C( 86), UINT8_C( 90),
          UINT8_C(144), UINT8_C(  9), UINT8_C(139), UINT8_C(239), UINT8_C(160), UINT8_C( 55), UINT8_C(  3), UINT8_C(185) },
        {  INT16_C(   286),  INT16_C(   379),  INT16_C(   240),  INT16_C(   176),  INT16_C(   153),  INT16_C(   378),  INT16_C(   215),  INT16_C(   188) } },
      { { UINT8_C(236), UINT8_C(118), UINT8_C(214), UINT8_C(  1), UINT8_C(229), UINT8_C(126), UINT8_C( 72), UINT8_C(215),
          UINT8_C(243), UINT8_C(186), UINT8_C( 33), UINT8_C(150), UINT8_C(202), UINT8_C( 76), UINT8_C(151), UINT8_C(108) },
        {  INT16_C(   354),  INT16_C(   215),  INT16_C(   355),  INT16_C(   287),  INT16_C(   429),  INT16_C(   183),  INT16_C(   278),  INT16_C(   259) } },
      { { UINT8_C( 54), UINT8_C( 81), UINT8_C(223), UINT8_C( 64), UINT8_C(247), UINT8_C( 40), UINT8_C( 21), UINT8_C(180),
          UINT8_C(248), UINT8_C(209), UINT8_C(229), UINT8_C(181), UINT8_C(111), UINT8_C( 52), UINT8_C( 43), UINT8_C(162) },
        {  INT16_C(   135),  INT16_C(   287),  INT16_C(   287),  INT16_C(   201),  INT16_C(   457),  INT16_C(   410),  INT16_C(   163),  INT16_C(   205) } },
      { { UINT8_C(238), UINT8_C(155), UINT8_C(175), UINT8_C(169), UINT8_C(  3), UINT8_C( 11), UINT8_C(203), UINT8_C( 73),
          UINT8_C(237), UINT8_C( 80), UINT8_C( 73), UINT8_C(219), UINT8_C(106), UINT8_C( 52), UINT8_C(204), UINT8_C(144) },
        {  INT16_C(   393),  INT16_C(   344),  INT16_C(    14),  INT16_C(   276),  INT16_C(   317),  INT16_C(   292),  INT16_C(   158),  INT16_C(   348) } },
      { { UINT8_C( 47), UINT8_C(128), UINT8_C(191), UINT8_C( 33), UINT8_C(183), UINT8_C(234), UINT8_C(158), UINT8_C(178),
          UINT8_C(222), UINT8_C(172), UINT8_C(178), UINT8_C(161), UINT8_C(170), UINT8_C(110), UINT8_C(132), UINT8_C( 98) },
        {  INT16_C(   175),  INT16_C(   224),  INT16_C(   417),  INT16_C(   336),  INT16_C(   394),  INT16_C(   339),  INT16_C(   280),  INT16_C(   230) } },
      { { UINT8_C( 98), UINT8_C(199), UINT8_C(198), UINT8_C(189), UINT8_C( 91), UINT8_C( 67), UINT8_C( 90), UINT8_C(202),
          UINT8_C(204), UINT8_C( 13), UINT8_C( 73), UINT8_C(163), UINT8_C(131), UINT8_C(100), UINT8_C(197), UINT8_C( 12) },
        {  INT16_C(   297),  INT16_C(   387),  INT16_C(   158),  INT16_C(   292),  INT16_C(   217),  INT16_C(   236),  INT16_C(   231),  INT16_C(   209) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t r = simde_wasm_u16x8_extadd_pairwise_u8x16(a);
      simde_test_wasm_i16x8_assert_equal(r, simde_wasm_v128_load(test_vec[i].r));
    }
    return 0;
  #else
    fputc('\n', stdout);
    for (int i = 0 ; i < 8 ; i++) {
      simde_v128_t
        a = simde_test_wasm_u8x16_random(),
        r;

      r = simde_wasm_u16x8_extadd_pairwise_u8x16(a);

      simde_test_wasm_u8x16_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_i16x8_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_u32x4_extadd_pairwise_u16x8(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      uint16_t a[sizeof(simde_v128_t) / sizeof(int8_t)];
      int32_t r[sizeof(simde_v128_t) / sizeof(int8_t)];
    } test_vec[] = {
      { { UINT16_C( 9627), UINT16_C(50039), UINT16_C(36001), UINT16_C(11434), UINT16_C( 4357), UINT16_C(57484), UINT16_C(20461), UINT16_C(55922) },
        {  INT32_C(       59666),  INT32_C(       47435),  INT32_C(       61841),  INT32_C(       76383) } },
      { { UINT16_C(49848), UINT16_C(50368), UINT16_C(  305), UINT16_C(47045), UINT16_C(30455), UINT16_C(64282), UINT16_C(50477), UINT16_C(19721) },
        {  INT32_C(      100216),  INT32_C(       47350),  INT32_C(       94737),  INT32_C(       70198) } },
      { { UINT16_C(31701), UINT16_C(27140), UINT16_C(37207), UINT16_C( 8181), UINT16_C(19232), UINT16_C(59196), UINT16_C(17263), UINT16_C(47975) },
        {  INT32_C(       58841),  INT32_C(       45388),  INT32_C(       78428),  INT32_C(       65238) } },
      { { UINT16_C(21136), UINT16_C(25045), UINT16_C(21605), UINT16_C(65142), UINT16_C( 2948), UINT16_C(31661), UINT16_C(65233), UINT16_C(12720) },
        {  INT32_C(       46181),  INT32_C(       86747),  INT32_C(       34609),  INT32_C(       77953) } },
      { { UINT16_C(39063), UINT16_C(61359), UINT16_C( 9024), UINT16_C(60484), UINT16_C(12337), UINT16_C(24870), UINT16_C(38482), UINT16_C( 9421) },
        {  INT32_C(      100422),  INT32_C(       69508),  INT32_C(       37207),  INT32_C(       47903) } },
      { { UINT16_C(19970), UINT16_C(42793), UINT16_C(49568), UINT16_C( 7729), UINT16_C(49496), UINT16_C(63773), UINT16_C( 6205), UINT16_C(24078) },
        {  INT32_C(       62763),  INT32_C(       57297),  INT32_C(      113269),  INT32_C(       30283) } },
      { { UINT16_C(14850), UINT16_C(52523), UINT16_C( 5494), UINT16_C( 3821), UINT16_C(20073), UINT16_C(38475), UINT16_C(55666), UINT16_C(47979) },
        {  INT32_C(       67373),  INT32_C(        9315),  INT32_C(       58548),  INT32_C(      103645) } },
      { { UINT16_C(12885), UINT16_C(56223), UINT16_C( 1543), UINT16_C(41310), UINT16_C(61127), UINT16_C(44139), UINT16_C(42285), UINT16_C( 8665) },
        {  INT32_C(       69108),  INT32_C(       42853),  INT32_C(      105266),  INT32_C(       50950) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t r = simde_wasm_u32x4_extadd_pairwise_u16x8(a);
      simde_test_wasm_i32x4_assert_equal(r, simde_wasm_v128_load(test_vec[i].r));
    }
    return 0;
  #else
    fputc('\n', stdout);
    for (int i = 0 ; i < 8 ; i++) {
      simde_v128_t
        a = simde_test_wasm_u8x16_random(),
        r;

      r = simde_wasm_u32x4_extadd_pairwise_u16x8(a);

      simde_test_wasm_u16x8_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_i32x4_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_i16x8_extadd_pairwise_i8x16)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_i32x4_extadd_pairwise_i16x8)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_u16x8_extadd_pairwise_u8x16)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_u32x4_extadd_pairwise_u16x8)
SIMDE_TEST_FUNC_LIST_END

#include "test-simd128-footer.h"
