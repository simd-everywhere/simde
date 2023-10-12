/* Copyright (c) 2023 Michael R. Crusoe <crusoe@debian.org>
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

#define SIMDE_TEST_WASM_SIMD128_INSN make_const
#include "../../../simde/wasm/simd128.h"
#include "test-simd128.h"

static int
test_simde_wasm_i8x16_const(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS int8_t test_vec[8][sizeof(simde_v128_t) / sizeof(int8_t)] = {
      {  INT8_C(  81), -INT8_C(  79),  INT8_C(  36),  INT8_C(  93), -INT8_C(  88),  INT8_C(  37), -INT8_C(  56),  INT8_C(  87),
        -INT8_C(  55), -INT8_C(  94), -INT8_C(  99), -INT8_C(  86), -INT8_C(  70),  INT8_C(  96), -INT8_C( 104), -INT8_C(  71) },
      {  INT8_C(  61), -INT8_C( 127),  INT8_C( 123), -INT8_C(  73),  INT8_C(  11), -INT8_C(  54), -INT8_C( 123), -INT8_C(  37),
        -INT8_C( 101), -INT8_C( 111), -INT8_C(  29),  INT8_C(  68), -INT8_C(  35), -INT8_C(  78), -INT8_C(   4), -INT8_C( 107) },
      {  INT8_C(  81),  INT8_C(  68), -INT8_C(  58),  INT8_C(  28), -INT8_C(  44), -INT8_C(  20), -INT8_C(  12), -INT8_C(  16),
        -INT8_C( 109), -INT8_C(   1),  INT8_C(   3), -INT8_C(  63), -INT8_C(  41), -INT8_C(  64), -INT8_C(  83),  INT8_C(  71) },
      {  INT8_C(   1),  INT8_C(  93),  INT8_C(  67), -INT8_C(  46), -INT8_C(   4), -INT8_C(  13),  INT8_C(  77), -INT8_C( 125),
         INT8_C(  94), -INT8_C( 114), -INT8_C(  22),  INT8_C(  50),  INT8_C(  83), -INT8_C(  15),  INT8_C(  91),  INT8_C( 111) },
      {  INT8_C(  75),  INT8_C(  93), -INT8_C(  60), -INT8_C(  56), -INT8_C(  69),  INT8_C(  24), -INT8_C( 119), -INT8_C(  26),
         INT8_C( 114),  INT8_C(  63), -INT8_C(  86), -INT8_C( 109),  INT8_C( 102), -INT8_C(  12), -INT8_C( 114), -INT8_C( 115) },
      { -INT8_C(  29), -INT8_C(  60),  INT8_C( 121), -INT8_C(  58), -INT8_C(  24),  INT8_C(  47),  INT8_C(  80), -INT8_C(  83),
        -INT8_C(  55),  INT8_C( 113),  INT8_C(  83),  INT8_C(  73),  INT8_C(  61), -INT8_C(  70), -INT8_C(  52), -INT8_C( 101) },
      { -INT8_C(  17),  INT8_C(  45),  INT8_C(  71),  INT8_C(  35),  INT8_C(  92), -INT8_C(  76), -INT8_C(  58), -INT8_C(  13),
         INT8_C(   2),  INT8_C(  10),  INT8_C(  29), -INT8_C(  16), -INT8_C( 117),  INT8_C( 104),  INT8_C( 112), -INT8_C(  27) },
      { -INT8_C(  41),  INT8_C(  76),  INT8_C(  31), -INT8_C( 116), -INT8_C(  57), -INT8_C( 118), -INT8_C(  59), -INT8_C( 109),
         INT8_C(  71),  INT8_C(  57),  INT8_C(  83), -INT8_C(   7),  INT8_C(  41), -INT8_C(  42), -INT8_C(  96),  INT8_C( 126) },
    };
    simde_v128_t a;

    a = simde_wasm_i8x16_const(  81,  -79,   36,   93,  -88,   37,  -56,   87,  -55,  -94,  -99,  -86,  -70,   96, -104,  -71);
    simde_test_wasm_i8x16_assert_equal(a, simde_wasm_v128_load(test_vec[0]));
    a = simde_wasm_i8x16_const(  61, -127,  123,  -73,   11,  -54, -123,  -37, -101, -111,  -29,   68,  -35,  -78,   -4, -107);
    simde_test_wasm_i8x16_assert_equal(a, simde_wasm_v128_load(test_vec[1]));
    a = simde_wasm_i8x16_const(  81,   68,  -58,   28,  -44,  -20,  -12,  -16, -109,   -1,    3,  -63,  -41,  -64,  -83,   71);
    simde_test_wasm_i8x16_assert_equal(a, simde_wasm_v128_load(test_vec[2]));
    a = simde_wasm_i8x16_const(   1,   93,   67,  -46,   -4,  -13,   77, -125,   94, -114,  -22,   50,   83,  -15,   91,  111);
    simde_test_wasm_i8x16_assert_equal(a, simde_wasm_v128_load(test_vec[3]));
    a = simde_wasm_i8x16_const(  75,   93,  -60,  -56,  -69,   24, -119,  -26,  114,   63,  -86, -109,  102,  -12, -114, -115);
    simde_test_wasm_i8x16_assert_equal(a, simde_wasm_v128_load(test_vec[4]));
    a = simde_wasm_i8x16_const( -29,  -60,  121,  -58,  -24,   47,   80,  -83,  -55,  113,   83,   73,   61,  -70,  -52, -101);
    simde_test_wasm_i8x16_assert_equal(a, simde_wasm_v128_load(test_vec[5]));
    a = simde_wasm_i8x16_const( -17,   45,   71,   35,   92,  -76,  -58,  -13,    2,   10,   29,  -16, -117,  104,  112,  -27);
    simde_test_wasm_i8x16_assert_equal(a, simde_wasm_v128_load(test_vec[6]));
    a = simde_wasm_i8x16_const( -41,   76,   31, -116,  -57, -118,  -59, -109,   71,   57,   83,   -7,   41,  -42,  -96,  126);
    simde_test_wasm_i8x16_assert_equal(a, simde_wasm_v128_load(test_vec[7]));

    return 0;
  #else
    simde_v128_t test_vec[8];
    fputc('\n', stdout);

    for (int i = 0 ; i < 8 ; i++) {
      int8_t a[sizeof(simde_v128_t) / sizeof(int8_t)];

      simde_test_codegen_random_memory(sizeof(a), HEDLEY_REINTERPRET_CAST(uint8_t*, a));
      test_vec[i] = simde_wasm_i8x16_make(
          a[0], a[1], a[ 2], a[ 3], a[ 4], a[ 5], a[ 6], a[ 7],
          a[8], a[9], a[10], a[11], a[12], a[13], a[14], a[15]) ;

      fprintf(SIMDE_CODEGEN_FP, "    a = simde_wasm_i8x16_const(%4" PRId8 ", %4" PRId8 ", %4" PRId8 ", %4" PRId8 ", %4" PRId8 ", %4" PRId8 ", %4" PRId8 ", %4" PRId8 ", %4" PRId8 ", %4" PRId8 ", %4" PRId8 ", %4" PRId8 ", %4" PRId8 ", %4" PRId8 ", %4" PRId8 ", %4" PRId8 ");\n",
             a[0], a[1], a[ 2], a[ 3], a[ 4], a[ 5], a[ 6], a[ 7],
             a[8], a[9], a[10], a[11], a[12], a[13], a[14], a[15]);
      fprintf(SIMDE_CODEGEN_FP, "    simde_test_wasm_i8x16_assert_equal(a, simde_wasm_v128_load(test_vec[%1" PRId8 "]));\n", i);
    }
    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_test_wasm_i8x16_write(2, test_vec[i], SIMDE_TEST_VEC_POS_MIDDLE);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_u8x16_const(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS uint8_t test_vec[8][sizeof(simde_v128_t) / sizeof(int8_t)] = {
      { UINT8_C(227), UINT8_C(134), UINT8_C(206), UINT8_C(114), UINT8_C( 70), UINT8_C(113), UINT8_C(173), UINT8_C(251),
        UINT8_C(  1), UINT8_C( 67), UINT8_C(230), UINT8_C( 63), UINT8_C(170), UINT8_C(205), UINT8_C(172), UINT8_C( 12) },
      { UINT8_C(155), UINT8_C( 47), UINT8_C( 91), UINT8_C(105), UINT8_C(130), UINT8_C( 10), UINT8_C( 37), UINT8_C( 61),
        UINT8_C( 69), UINT8_C(164), UINT8_C(161), UINT8_C(105), UINT8_C( 64), UINT8_C(139), UINT8_C( 53), UINT8_C( 76) },
      { UINT8_C(186), UINT8_C(210), UINT8_C(231), UINT8_C(106), UINT8_C(129), UINT8_C(175), UINT8_C( 47), UINT8_C( 98),
        UINT8_C(188), UINT8_C(254), UINT8_C(168), UINT8_C( 76), UINT8_C( 58), UINT8_C(192), UINT8_C(  0), UINT8_C(152) },
      { UINT8_C(125), UINT8_C( 41), UINT8_C( 12), UINT8_C( 63), UINT8_C(160), UINT8_C(155), UINT8_C(108), UINT8_C( 60),
        UINT8_C(111), UINT8_C(220), UINT8_C( 92), UINT8_C( 14), UINT8_C( 35), UINT8_C( 92), UINT8_C( 90), UINT8_C( 15) },
      { UINT8_C( 62), UINT8_C(246), UINT8_C(185), UINT8_C(141), UINT8_C(169), UINT8_C(186), UINT8_C( 56), UINT8_C( 41),
        UINT8_C(176), UINT8_C(223), UINT8_C(243), UINT8_C(252), UINT8_C( 53), UINT8_C( 26), UINT8_C( 92), UINT8_C(123) },
      { UINT8_C(210), UINT8_C(233), UINT8_C(134), UINT8_C(151), UINT8_C(214), UINT8_C(201), UINT8_C( 81), UINT8_C( 90),
        UINT8_C(249), UINT8_C(231), UINT8_C( 97), UINT8_C(219), UINT8_C(205), UINT8_C( 35), UINT8_C(145), UINT8_C(212) },
      { UINT8_C(199), UINT8_C(127), UINT8_C( 24), UINT8_C(128), UINT8_C(146), UINT8_C(216), UINT8_C(105), UINT8_C(237),
        UINT8_C(105), UINT8_C( 19), UINT8_C( 22), UINT8_C(116), UINT8_C( 88), UINT8_C(209), UINT8_C( 81), UINT8_C( 84) },
      { UINT8_C(  8), UINT8_C(115), UINT8_C( 13), UINT8_C(132), UINT8_C(126), UINT8_C(176), UINT8_C( 34), UINT8_C( 93),
        UINT8_C(101), UINT8_C(253), UINT8_C(  1), UINT8_C(217), UINT8_C( 75), UINT8_C( 30), UINT8_C( 71), UINT8_C(161) }
    };
    simde_v128_t a;

    a = simde_wasm_u8x16_const( 227,  134,  206,  114,   70,  113,  173,  251,    1,   67,  230,   63,  170,  205,  172,   12);
    simde_test_wasm_u8x16_assert_equal(a, simde_wasm_v128_load(test_vec[0]));
    a = simde_wasm_u8x16_const( 155,   47,   91,  105,  130,   10,   37,   61,   69,  164,  161,  105,   64,  139,   53,   76);
    simde_test_wasm_u8x16_assert_equal(a, simde_wasm_v128_load(test_vec[1]));
    a = simde_wasm_u8x16_const( 186,  210,  231,  106,  129,  175,   47,   98,  188,  254,  168,   76,   58,  192,    0,  152);
    simde_test_wasm_u8x16_assert_equal(a, simde_wasm_v128_load(test_vec[2]));
    a = simde_wasm_u8x16_const( 125,   41,   12,   63,  160,  155,  108,   60,  111,  220,   92,   14,   35,   92,   90,   15);
    simde_test_wasm_u8x16_assert_equal(a, simde_wasm_v128_load(test_vec[3]));
    a = simde_wasm_u8x16_const(  62,  246,  185,  141,  169,  186,   56,   41,  176,  223,  243,  252,   53,   26,   92,  123);
    simde_test_wasm_u8x16_assert_equal(a, simde_wasm_v128_load(test_vec[4]));
    a = simde_wasm_u8x16_const( 210,  233,  134,  151,  214,  201,   81,   90,  249,  231,   97,  219,  205,   35,  145,  212);
    simde_test_wasm_u8x16_assert_equal(a, simde_wasm_v128_load(test_vec[5]));
    a = simde_wasm_u8x16_const( 199,  127,   24,  128,  146,  216,  105,  237,  105,   19,   22,  116,   88,  209,   81,   84);
    simde_test_wasm_u8x16_assert_equal(a, simde_wasm_v128_load(test_vec[6]));
    a = simde_wasm_u8x16_const(   8,  115,   13,  132,  126,  176,   34,   93,  101,  253,    1,  217,   75,   30,   71,  161);
    simde_test_wasm_u8x16_assert_equal(a, simde_wasm_v128_load(test_vec[7]));

    return 0;
  #else
    simde_v128_t test_vec[8];
    fputc('\n', stdout);

    for (int i = 0 ; i < 8 ; i++) {
      uint8_t a[sizeof(simde_v128_t) / sizeof(uint8_t)];

      simde_test_codegen_random_memory(sizeof(a), HEDLEY_REINTERPRET_CAST(uint8_t*, a));
      test_vec[i] = simde_wasm_u8x16_make(
          a[0], a[1], a[ 2], a[ 3], a[ 4], a[ 5], a[ 6], a[ 7],
          a[8], a[9], a[10], a[11], a[12], a[13], a[14], a[15]) ;

      fprintf(SIMDE_CODEGEN_FP, "    a = simde_wasm_u8x16_const(%4" PRIu8 ", %4" PRIu8 ", %4" PRIu8 ", %4" PRIu8 ", %4" PRIu8 ", %4" PRIu8 ", %4" PRIu8 ", %4" PRIu8 ", %4" PRIu8 ", %4" PRIu8 ", %4" PRIu8 ", %4" PRIu8 ", %4" PRIu8 ", %4" PRIu8 ", %4" PRIu8 ", %4" PRIu8 ");\n",
             a[0], a[1], a[ 2], a[ 3], a[ 4], a[ 5], a[ 6], a[ 7],
             a[8], a[9], a[10], a[11], a[12], a[13], a[14], a[15]);
      fprintf(SIMDE_CODEGEN_FP, "    simde_test_wasm_u8x16_assert_equal(a, simde_wasm_v128_load(test_vec[%1" PRId8 "]));\n", i);
    }
    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_test_wasm_u8x16_write(2, test_vec[i], SIMDE_TEST_VEC_POS_MIDDLE);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_i16x8_const(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS int16_t test_vec[8][sizeof(simde_v128_t) / sizeof(int16_t)] = {
      {  INT16_C(  9810), -INT16_C( 23557), -INT16_C( 22740), -INT16_C( 14337), -INT16_C( 17462), -INT16_C(  9114),  INT16_C( 11912), -INT16_C( 28507) },
      { -INT16_C( 24562),  INT16_C( 17406),  INT16_C( 20254), -INT16_C( 31299),  INT16_C( 11086),  INT16_C( 14081), -INT16_C( 28208), -INT16_C(  1144) },
      { -INT16_C( 31477),  INT16_C( 19024), -INT16_C( 28800), -INT16_C( 23139),  INT16_C(   624), -INT16_C(  1802), -INT16_C( 27223),  INT16_C( 11270) },
      { -INT16_C( 25711),  INT16_C( 10867), -INT16_C( 21730), -INT16_C( 21219),  INT16_C(  9615), -INT16_C( 27373),  INT16_C( 21320),  INT16_C( 26223) },
      {  INT16_C( 21332),  INT16_C( 27493), -INT16_C( 23519),  INT16_C( 14492), -INT16_C( 16485),  INT16_C( 15321), -INT16_C( 11530), -INT16_C(  2248) },
      { -INT16_C( 10298),  INT16_C(  7779), -INT16_C( 31235), -INT16_C(  4243), -INT16_C( 22040), -INT16_C( 10022), -INT16_C( 10124),  INT16_C( 27669) },
      {  INT16_C(  8521), -INT16_C( 10818),  INT16_C(  5928),  INT16_C( 20442), -INT16_C( 29801),  INT16_C( 21983), -INT16_C(  7718),  INT16_C( 21700) },
      { -INT16_C( 28234), -INT16_C( 31685),  INT16_C( 31242), -INT16_C( 13678),  INT16_C( 21288), -INT16_C( 31900), -INT16_C( 18309),  INT16_C(  7424) }
    };
    simde_v128_t a;

    a = simde_wasm_i16x8_const(9810, -23557, -22740, -14337, -17462, -9114, 11912, -28507);
    simde_test_wasm_i16x8_assert_equal(a, simde_wasm_v128_load(test_vec[0]));
    a = simde_wasm_i16x8_const(-24562, 17406, 20254, -31299, 11086, 14081, -28208, -1144);
    simde_test_wasm_i16x8_assert_equal(a, simde_wasm_v128_load(test_vec[1]));
    a = simde_wasm_i16x8_const(-31477, 19024, -28800, -23139,  624, -1802, -27223, 11270);
    simde_test_wasm_i16x8_assert_equal(a, simde_wasm_v128_load(test_vec[2]));
    a = simde_wasm_i16x8_const(-25711, 10867, -21730, -21219, 9615, -27373, 21320, 26223);
    simde_test_wasm_i16x8_assert_equal(a, simde_wasm_v128_load(test_vec[3]));
    a = simde_wasm_i16x8_const(21332, 27493, -23519, 14492, -16485, 15321, -11530, -2248);
    simde_test_wasm_i16x8_assert_equal(a, simde_wasm_v128_load(test_vec[4]));
    a = simde_wasm_i16x8_const(-10298, 7779, -31235, -4243, -22040, -10022, -10124, 27669);
    simde_test_wasm_i16x8_assert_equal(a, simde_wasm_v128_load(test_vec[5]));
    a = simde_wasm_i16x8_const(8521, -10818, 5928, 20442, -29801, 21983, -7718, 21700);
    simde_test_wasm_i16x8_assert_equal(a, simde_wasm_v128_load(test_vec[6]));
    a = simde_wasm_i16x8_const(-28234, -31685, 31242, -13678, 21288, -31900, -18309, 7424);
    simde_test_wasm_i16x8_assert_equal(a, simde_wasm_v128_load(test_vec[7]));

    return 0;
  #else
    simde_v128_t test_vec[8];
    fputc('\n', stdout);

    for (int i = 0 ; i < 8 ; i++) {
      int16_t a[sizeof(simde_v128_t) / sizeof(int16_t)];

      simde_test_codegen_random_memory(sizeof(a), HEDLEY_REINTERPRET_CAST(uint8_t*, a));
      test_vec[i] = simde_wasm_i16x8_make(
          a[0], a[1], a[ 2], a[ 3], a[ 4], a[ 5], a[ 6], a[ 7]) ;

      fprintf(SIMDE_CODEGEN_FP, "    a = simde_wasm_i16x8_const(%4" PRId16 ", %4" PRId16 ", %4" PRId16 ", %4" PRId16 ", %4" PRId16 ", %4" PRId16 ", %4" PRId16 ", %4" PRId16 ");\n",
             a[0], a[1], a[ 2], a[ 3], a[ 4], a[ 5], a[ 6], a[ 7]);
      fprintf(SIMDE_CODEGEN_FP, "    simde_test_wasm_i16x8_assert_equal(a, simde_wasm_v128_load(test_vec[%1" PRId8 "]));\n", i);
    }
    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_test_wasm_i16x8_write(2, test_vec[i], SIMDE_TEST_VEC_POS_MIDDLE);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_u16x8_const(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS uint16_t test_vec[8][sizeof(simde_v128_t) / sizeof(uint16_t)] = {
      { UINT16_C(38093), UINT16_C(57469), UINT16_C( 8106), UINT16_C(48650), UINT16_C(24224), UINT16_C(19159), UINT16_C(15426), UINT16_C(33063) },
      { UINT16_C(50940), UINT16_C(46085), UINT16_C(46236), UINT16_C(48961), UINT16_C(64978), UINT16_C(33071), UINT16_C(49929), UINT16_C( 4624) },
      { UINT16_C( 8202), UINT16_C(42041), UINT16_C(26028), UINT16_C(48514), UINT16_C(43592), UINT16_C( 1354), UINT16_C(43128), UINT16_C(21891) },
      { UINT16_C(44564), UINT16_C(61184), UINT16_C( 5318), UINT16_C(31109), UINT16_C(38724), UINT16_C(32929), UINT16_C(33244), UINT16_C(62448) },
      { UINT16_C(17276), UINT16_C(42338), UINT16_C(60829), UINT16_C(53898), UINT16_C(62564), UINT16_C(27327), UINT16_C(30585), UINT16_C(34760) },
      { UINT16_C(47902), UINT16_C(53187), UINT16_C(56977), UINT16_C(28119), UINT16_C(33887), UINT16_C(48654), UINT16_C(18148), UINT16_C(30726) },
      { UINT16_C(16248), UINT16_C( 3870), UINT16_C(33357), UINT16_C(11309), UINT16_C(62315), UINT16_C(59507), UINT16_C(24525), UINT16_C(28779) },
      { UINT16_C( 3876), UINT16_C(15067), UINT16_C(57776), UINT16_C(  166), UINT16_C(30126), UINT16_C(24882), UINT16_C(47574), UINT16_C(59871) }
    };
    simde_v128_t a;

    a = simde_wasm_u16x8_const(38093, 57469, 8106, 48650, 24224, 19159, 15426, 33063);
    simde_test_wasm_u16x8_assert_equal(a, simde_wasm_v128_load(test_vec[0]));
    a = simde_wasm_u16x8_const(50940, 46085, 46236, 48961, 64978, 33071, 49929, 4624);
    simde_test_wasm_u16x8_assert_equal(a, simde_wasm_v128_load(test_vec[1]));
    a = simde_wasm_u16x8_const(8202, 42041, 26028, 48514, 43592, 1354, 43128, 21891);
    simde_test_wasm_u16x8_assert_equal(a, simde_wasm_v128_load(test_vec[2]));
    a = simde_wasm_u16x8_const(44564, 61184, 5318, 31109, 38724, 32929, 33244, 62448);
    simde_test_wasm_u16x8_assert_equal(a, simde_wasm_v128_load(test_vec[3]));
    a = simde_wasm_u16x8_const(17276, 42338, 60829, 53898, 62564, 27327, 30585, 34760);
    simde_test_wasm_u16x8_assert_equal(a, simde_wasm_v128_load(test_vec[4]));
    a = simde_wasm_u16x8_const(47902, 53187, 56977, 28119, 33887, 48654, 18148, 30726);
    simde_test_wasm_u16x8_assert_equal(a, simde_wasm_v128_load(test_vec[5]));
    a = simde_wasm_u16x8_const(16248, 3870, 33357, 11309, 62315, 59507, 24525, 28779);
    simde_test_wasm_u16x8_assert_equal(a, simde_wasm_v128_load(test_vec[6]));
    a = simde_wasm_u16x8_const(3876, 15067, 57776,  166, 30126, 24882, 47574, 59871);
    simde_test_wasm_u16x8_assert_equal(a, simde_wasm_v128_load(test_vec[7]));

    return 0;
  #else
    simde_v128_t test_vec[8];
    fputc('\n', stdout);

    for (int i = 0 ; i < 8 ; i++) {
      uint16_t a[sizeof(simde_v128_t) / sizeof(uint16_t)];

      simde_test_codegen_random_memory(sizeof(a), HEDLEY_REINTERPRET_CAST(uint8_t*, a));
      test_vec[i] = simde_wasm_u16x8_make(
          a[0], a[1], a[ 2], a[ 3], a[ 4], a[ 5], a[ 6], a[ 7]) ;

      fprintf(SIMDE_CODEGEN_FP, "    a = simde_wasm_u16x8_const(%4" PRIu16 ", %4" PRIu16 ", %4" PRIu16 ", %4" PRIu16 ", %4" PRIu16 ", %4" PRIu16 ", %4" PRIu16 ", %4" PRIu16 ");\n",
             a[0], a[1], a[ 2], a[ 3], a[ 4], a[ 5], a[ 6], a[ 7]);
      fprintf(SIMDE_CODEGEN_FP, "    simde_test_wasm_u16x8_assert_equal(a, simde_wasm_v128_load(test_vec[%1" PRId8 "]));\n", i);
    }
    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_test_wasm_u16x8_write(2, test_vec[i], SIMDE_TEST_VEC_POS_MIDDLE);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_i32x4_const(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS int32_t test_vec[8][sizeof(simde_v128_t) / sizeof(int32_t)] = {
      {  INT32_C(  1638487602), -INT32_C(  1937529758), -INT32_C(  1918818205),  INT32_C(  1267645659) },
      { -INT32_C(   689210396),  INT32_C(   644424890),  INT32_C(  1160888587),  INT32_C(   639753794) },
      { -INT32_C(  1540192956), -INT32_C(  1534596015), -INT32_C(  1690699706), -INT32_C(    38511165) },
      { -INT32_C(    45615081), -INT32_C(  1993338144),  INT32_C(  1410941640),  INT32_C(   704029741) },
      {  INT32_C(   524140725), -INT32_C(    27262509), -INT32_C(  1759294487),  INT32_C(  1425003442) },
      {  INT32_C(   773366325),  INT32_C(   699343649),  INT32_C(  1440527447),  INT32_C(   100724517) },
      { -INT32_C(  2038453375),  INT32_C(  1496578013), -INT32_C(   520183197), -INT32_C(   863356994) },
      {  INT32_C(    33174463), -INT32_C(  2100361721),  INT32_C(  1104381806),  INT32_C(  1925456090) }
    };
    simde_v128_t a;

    a = simde_wasm_i32x4_const(1638487602, -1937529758, -1918818205, 1267645659);
    simde_test_wasm_i32x4_assert_equal(a, simde_wasm_v128_load(test_vec[0]));
    a = simde_wasm_i32x4_const(-689210396, 644424890, 1160888587, 639753794);
    simde_test_wasm_i32x4_assert_equal(a, simde_wasm_v128_load(test_vec[1]));
    a = simde_wasm_i32x4_const(-1540192956, -1534596015, -1690699706, -38511165);
    simde_test_wasm_i32x4_assert_equal(a, simde_wasm_v128_load(test_vec[2]));
    a = simde_wasm_i32x4_const(-45615081, -1993338144, 1410941640, 704029741);
    simde_test_wasm_i32x4_assert_equal(a, simde_wasm_v128_load(test_vec[3]));
    a = simde_wasm_i32x4_const(524140725, -27262509, -1759294487, 1425003442);
    simde_test_wasm_i32x4_assert_equal(a, simde_wasm_v128_load(test_vec[4]));
    a = simde_wasm_i32x4_const(773366325, 699343649, 1440527447, 100724517);
    simde_test_wasm_i32x4_assert_equal(a, simde_wasm_v128_load(test_vec[5]));
    a = simde_wasm_i32x4_const(-2038453375, 1496578013, -520183197, -863356994);
    simde_test_wasm_i32x4_assert_equal(a, simde_wasm_v128_load(test_vec[6]));
    a = simde_wasm_i32x4_const(33174463, -2100361721, 1104381806, 1925456090);
    simde_test_wasm_i32x4_assert_equal(a, simde_wasm_v128_load(test_vec[7]));

    return 0;
  #else
    simde_v128_t test_vec[8];
    fputc('\n', stdout);

    for (int i = 0 ; i < 8 ; i++) {
      int32_t a[sizeof(simde_v128_t) / sizeof(int32_t)];

      simde_test_codegen_random_memory(sizeof(a), HEDLEY_REINTERPRET_CAST(uint8_t*, a));
      test_vec[i] = simde_wasm_i32x4_make(
          a[0], a[1], a[ 2], a[ 3]) ;

      fprintf(SIMDE_CODEGEN_FP, "    a = simde_wasm_i32x4_const(%4" PRId32 ", %4" PRId32 ", %4" PRId32 ", %4" PRId32 ");\n",
             a[0], a[1], a[ 2], a[ 3]);
      fprintf(SIMDE_CODEGEN_FP, "    simde_test_wasm_i32x4_assert_equal(a, simde_wasm_v128_load(test_vec[%1" PRId8 "]));\n", i);
    }
    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_test_wasm_i32x4_write(2, test_vec[i], SIMDE_TEST_VEC_POS_MIDDLE);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_u32x4_const(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS uint32_t test_vec[8][sizeof(simde_v128_t) / sizeof(uint32_t)] = {
      { UINT32_C(2990593695), UINT32_C(2490450969), UINT32_C(3193747699), UINT32_C(3527440183) },
      { UINT32_C(2568421379), UINT32_C( 717050584), UINT32_C( 381502383), UINT32_C(3248301619) },
      { UINT32_C(3459807367), UINT32_C( 161949914), UINT32_C(4169504360), UINT32_C(2246451843) },
      { UINT32_C(2597024358), UINT32_C(4219054161), UINT32_C( 708468433), UINT32_C(1847919338) },
      { UINT32_C( 300788028), UINT32_C(2009830291), UINT32_C(3887412491), UINT32_C(4237996658) },
      { UINT32_C(2562850601), UINT32_C(2950981340), UINT32_C(4224685893), UINT32_C( 489347227) },
      { UINT32_C(3918864336), UINT32_C(1611504337), UINT32_C( 131634430), UINT32_C( 108287508) },
      { UINT32_C( 194095795), UINT32_C( 139513668), UINT32_C(2288046941), UINT32_C( 437942115) }
    };
    simde_v128_t a;

    a = simde_wasm_u32x4_const(2990593695, 2490450969, 3193747699, 3527440183);
    simde_test_wasm_u32x4_assert_equal(a, simde_wasm_v128_load(test_vec[0]));
    a = simde_wasm_u32x4_const(2568421379, 717050584, 381502383, 3248301619);
    simde_test_wasm_u32x4_assert_equal(a, simde_wasm_v128_load(test_vec[1]));
    a = simde_wasm_u32x4_const(3459807367, 161949914, 4169504360, 2246451843);
    simde_test_wasm_u32x4_assert_equal(a, simde_wasm_v128_load(test_vec[2]));
    a = simde_wasm_u32x4_const(2597024358, 4219054161, 708468433, 1847919338);
    simde_test_wasm_u32x4_assert_equal(a, simde_wasm_v128_load(test_vec[3]));
    a = simde_wasm_u32x4_const(300788028, 2009830291, 3887412491, 4237996658);
    simde_test_wasm_u32x4_assert_equal(a, simde_wasm_v128_load(test_vec[4]));
    a = simde_wasm_u32x4_const(2562850601, 2950981340, 4224685893, 489347227);
    simde_test_wasm_u32x4_assert_equal(a, simde_wasm_v128_load(test_vec[5]));
    a = simde_wasm_u32x4_const(3918864336, 1611504337, 131634430, 108287508);
    simde_test_wasm_u32x4_assert_equal(a, simde_wasm_v128_load(test_vec[6]));
    a = simde_wasm_u32x4_const(194095795, 139513668, 2288046941, 437942115);
    simde_test_wasm_u32x4_assert_equal(a, simde_wasm_v128_load(test_vec[7]));

    return 0;
  #else
    simde_v128_t test_vec[8];
    fputc('\n', stdout);

    for (int i = 0 ; i < 8 ; i++) {
      uint32_t a[sizeof(simde_v128_t) / sizeof(uint32_t)];

      simde_test_codegen_random_memory(sizeof(a), HEDLEY_REINTERPRET_CAST(uint8_t*, a));
      test_vec[i] = simde_wasm_u32x4_make(
          a[0], a[1], a[ 2], a[ 3]) ;

      fprintf(SIMDE_CODEGEN_FP, "    a = simde_wasm_u32x4_const(%4" PRIu32 ", %4" PRIu32 ", %4" PRIu32 ", %4" PRIu32 ");\n",
             a[0], a[1], a[ 2], a[ 3]);
      fprintf(SIMDE_CODEGEN_FP, "    simde_test_wasm_u32x4_assert_equal(a, simde_wasm_v128_load(test_vec[%1" PRId8 "]));\n", i);
    }
    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_test_wasm_u32x4_write(2, test_vec[i], SIMDE_TEST_VEC_POS_MIDDLE);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_i64x2_const(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS int64_t test_vec[8][sizeof(simde_v128_t) / sizeof(int64_t)] = {
      { -INT64_C( 1430358319906461586),  INT64_C( 8049127797954466860) },
      {  INT64_C( 8183518753680522323),  INT64_C( 7130153617536153843) },
      {  INT64_C( 5919523007599387869), -INT64_C( 4291532896501508949) },
      {  INT64_C( 2488131728690805642),  INT64_C( 2355775262575314579) },
      { -INT64_C( 5565429007222390390), -INT64_C( 7869783713455747421) },
      { -INT64_C( 4670088175240434732), -INT64_C( 5315216180009454819) },
      { -INT64_C( 9211876366893238512),  INT64_C( 3281632195185830839) },
      { -INT64_C( 8990902038405019670),  INT64_C( 4241488893781657582) }
    };
    simde_v128_t a;

    a = simde_wasm_i64x2_const(-1430358319906461586, 8049127797954466860);
    simde_test_wasm_i64x2_assert_equal(a, simde_wasm_v128_load(test_vec[0]));
    a = simde_wasm_i64x2_const(8183518753680522323, 7130153617536153843);
    simde_test_wasm_i64x2_assert_equal(a, simde_wasm_v128_load(test_vec[1]));
    a = simde_wasm_i64x2_const(5919523007599387869, -4291532896501508949);
    simde_test_wasm_i64x2_assert_equal(a, simde_wasm_v128_load(test_vec[2]));
    a = simde_wasm_i64x2_const(2488131728690805642, 2355775262575314579);
    simde_test_wasm_i64x2_assert_equal(a, simde_wasm_v128_load(test_vec[3]));
    a = simde_wasm_i64x2_const(-5565429007222390390, -7869783713455747421);
    simde_test_wasm_i64x2_assert_equal(a, simde_wasm_v128_load(test_vec[4]));
    a = simde_wasm_i64x2_const(-4670088175240434732, -5315216180009454819);
    simde_test_wasm_i64x2_assert_equal(a, simde_wasm_v128_load(test_vec[5]));
    a = simde_wasm_i64x2_const(-9211876366893238512, 3281632195185830839);
    simde_test_wasm_i64x2_assert_equal(a, simde_wasm_v128_load(test_vec[6]));
    a = simde_wasm_i64x2_const(-8990902038405019670, 4241488893781657582);
    simde_test_wasm_i64x2_assert_equal(a, simde_wasm_v128_load(test_vec[7]));

    return 0;
  #else
    simde_v128_t test_vec[8];
    fputc('\n', stdout);

    for (int i = 0 ; i < 8 ; i++) {
      int64_t a[sizeof(simde_v128_t) / sizeof(int64_t)];

      simde_test_codegen_random_memory(sizeof(a), HEDLEY_REINTERPRET_CAST(uint8_t*, a));
      test_vec[i] = simde_wasm_i64x2_make(
          a[0], a[1]) ;

      fprintf(SIMDE_CODEGEN_FP, "    a = simde_wasm_i64x2_const(%4" PRId64 ", %4" PRId64 ");\n",
             a[0], a[1]);
      fprintf(SIMDE_CODEGEN_FP, "    simde_test_wasm_i64x2_assert_equal(a, simde_wasm_v128_load(test_vec[%1" PRId8 "]));\n", i);
    }
    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_test_wasm_i64x2_write(2, test_vec[i], SIMDE_TEST_VEC_POS_MIDDLE);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_u64x2_const(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS uint64_t test_vec[8][sizeof(simde_v128_t) / sizeof(uint64_t)] = {
      { UINT64_C( 8695826832778371234), UINT64_C( 1009371111174596241) },
      { UINT64_C( 5486143349099483814), UINT64_C( 6420274701089511671) },
      { UINT64_C( 7304997411725805900), UINT64_C(14807585266053360361) },
      { UINT64_C( 3868854925187994044), UINT64_C( 6027551375026117307) },
      { UINT64_C( 5427991744971193115), UINT64_C( 1913838352194814696) },
      { UINT64_C(15074309786091588449), UINT64_C(12347910930813565020) },
      { UINT64_C(11902320771049894625), UINT64_C( 6653414154723180806) },
      { UINT64_C( 9415881128792558302), UINT64_C(10794488662514399326) }
    };
    simde_v128_t a;

    a = simde_wasm_u64x2_const(UINT64_C(8695826832778371234), UINT64_C(1009371111174596241));
    simde_test_wasm_u64x2_assert_equal(a, simde_wasm_v128_load(test_vec[0]));
    a = simde_wasm_u64x2_const(UINT64_C(5486143349099483814), UINT64_C(6420274701089511671));
    simde_test_wasm_u64x2_assert_equal(a, simde_wasm_v128_load(test_vec[1]));
    a = simde_wasm_u64x2_const(UINT64_C(7304997411725805900), UINT64_C(14807585266053360361));
    simde_test_wasm_u64x2_assert_equal(a, simde_wasm_v128_load(test_vec[2]));
    a = simde_wasm_u64x2_const(UINT64_C(3868854925187994044), UINT64_C(6027551375026117307));
    simde_test_wasm_u64x2_assert_equal(a, simde_wasm_v128_load(test_vec[3]));
    a = simde_wasm_u64x2_const(UINT64_C(5427991744971193115), UINT64_C(1913838352194814696));
    simde_test_wasm_u64x2_assert_equal(a, simde_wasm_v128_load(test_vec[4]));
    a = simde_wasm_u64x2_const(UINT64_C(15074309786091588449), UINT64_C(12347910930813565020));
    simde_test_wasm_u64x2_assert_equal(a, simde_wasm_v128_load(test_vec[5]));
    a = simde_wasm_u64x2_const(UINT64_C(11902320771049894625), UINT64_C(6653414154723180806));
    simde_test_wasm_u64x2_assert_equal(a, simde_wasm_v128_load(test_vec[6]));
    a = simde_wasm_u64x2_const(UINT64_C(9415881128792558302), UINT64_C(10794488662514399326));
    simde_test_wasm_u64x2_assert_equal(a, simde_wasm_v128_load(test_vec[7]));

    return 0;
  #else
    simde_v128_t test_vec[8];
    fputc('\n', stdout);

    for (int i = 0 ; i < 8 ; i++) {
      uint64_t a[sizeof(simde_v128_t) / sizeof(uint64_t)];

      simde_test_codegen_random_memory(sizeof(a), HEDLEY_REINTERPRET_CAST(uint8_t*, a));
      test_vec[i] = simde_wasm_u64x2_make(
          a[0], a[1]) ;

      fprintf(SIMDE_CODEGEN_FP, SIMDE_CODEGEN_FP, "    a = simde_wasm_u64x2_const(UINT64_C(%4" PRIu64 "), UINT64_C(%4" PRIu64 "));\n",
             a[0], a[1]);
      fprintf(SIMDE_CODEGEN_FP, "    simde_test_wasm_u64x2_assert_equal(a, simde_wasm_v128_load(test_vec[%1" PRId8 "]));\n", i);
    }
    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_test_wasm_u64x2_write(2, test_vec[i], SIMDE_TEST_VEC_POS_MIDDLE);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_f32x4_const(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS simde_float32 test_vec[8][sizeof(simde_v128_t) / sizeof(simde_float32)] = {
      { SIMDE_FLOAT32_C(  -503.56), SIMDE_FLOAT32_C(  -779.53), SIMDE_FLOAT32_C(   169.44), SIMDE_FLOAT32_C(  -759.92) },
      { SIMDE_FLOAT32_C(   460.41), SIMDE_FLOAT32_C(    25.79), SIMDE_FLOAT32_C(   265.80), SIMDE_FLOAT32_C(   979.01) },
      { SIMDE_FLOAT32_C(  -135.97), SIMDE_FLOAT32_C(  -745.97), SIMDE_FLOAT32_C(  -462.58), SIMDE_FLOAT32_C(   953.57) },
      { SIMDE_FLOAT32_C(   818.79), SIMDE_FLOAT32_C(  -259.19), SIMDE_FLOAT32_C(   864.52), SIMDE_FLOAT32_C(  -229.15) },
      { SIMDE_FLOAT32_C(    15.80), SIMDE_FLOAT32_C(  -103.02), SIMDE_FLOAT32_C(   637.40), SIMDE_FLOAT32_C(  -552.43) },
      { SIMDE_FLOAT32_C(   923.68), SIMDE_FLOAT32_C(   518.55), SIMDE_FLOAT32_C(   739.08), SIMDE_FLOAT32_C(  -178.48) },
      { SIMDE_FLOAT32_C(  -358.63), SIMDE_FLOAT32_C(  -122.90), SIMDE_FLOAT32_C(   745.93), SIMDE_FLOAT32_C(   362.62) },
      { SIMDE_FLOAT32_C(  -871.24), SIMDE_FLOAT32_C(   285.53), SIMDE_FLOAT32_C(   805.96), SIMDE_FLOAT32_C(   218.02) }
    };
    simde_v128_t a;

    a = simde_wasm_f32x4_const(SIMDE_FLOAT32_C(  -503.56), SIMDE_FLOAT32_C(  -779.53), SIMDE_FLOAT32_C(   169.44), SIMDE_FLOAT32_C(  -759.92));
    simde_test_wasm_f32x4_assert_equal(a, simde_wasm_v128_load(test_vec[0]), 1);
    a = simde_wasm_f32x4_const(SIMDE_FLOAT32_C(   460.41), SIMDE_FLOAT32_C(    25.79), SIMDE_FLOAT32_C(   265.80), SIMDE_FLOAT32_C(   979.01));
    simde_test_wasm_f32x4_assert_equal(a, simde_wasm_v128_load(test_vec[1]), 1);
    a = simde_wasm_f32x4_const(SIMDE_FLOAT32_C(  -135.97), SIMDE_FLOAT32_C(  -745.97), SIMDE_FLOAT32_C(  -462.58), SIMDE_FLOAT32_C(   953.57));
    simde_test_wasm_f32x4_assert_equal(a, simde_wasm_v128_load(test_vec[2]), 1);
    a = simde_wasm_f32x4_const(SIMDE_FLOAT32_C(   818.79), SIMDE_FLOAT32_C(  -259.19), SIMDE_FLOAT32_C(   864.52), SIMDE_FLOAT32_C(  -229.15));
    simde_test_wasm_f32x4_assert_equal(a, simde_wasm_v128_load(test_vec[3]), 1);
    a = simde_wasm_f32x4_const(SIMDE_FLOAT32_C(    15.80), SIMDE_FLOAT32_C(  -103.02), SIMDE_FLOAT32_C(   637.40), SIMDE_FLOAT32_C(  -552.43));
    simde_test_wasm_f32x4_assert_equal(a, simde_wasm_v128_load(test_vec[4]), 1);
    a = simde_wasm_f32x4_const(SIMDE_FLOAT32_C(   923.68), SIMDE_FLOAT32_C(   518.55), SIMDE_FLOAT32_C(   739.08), SIMDE_FLOAT32_C(  -178.48));
    simde_test_wasm_f32x4_assert_equal(a, simde_wasm_v128_load(test_vec[5]), 1);
    a = simde_wasm_f32x4_const(SIMDE_FLOAT32_C(  -358.63), SIMDE_FLOAT32_C(  -122.90), SIMDE_FLOAT32_C(   745.93), SIMDE_FLOAT32_C(   362.62));
    simde_test_wasm_f32x4_assert_equal(a, simde_wasm_v128_load(test_vec[6]), 1);
    a = simde_wasm_f32x4_const(SIMDE_FLOAT32_C(  -871.24), SIMDE_FLOAT32_C(   285.53), SIMDE_FLOAT32_C(   805.96), SIMDE_FLOAT32_C(   218.02));
    simde_test_wasm_f32x4_assert_equal(a, simde_wasm_v128_load(test_vec[7]), 1);

    return 0;
  #else
    simde_v128_t test_vec[8];
    fputc('\n', stdout);

    for (int i = 0 ; i < 8 ; i++) {
      simde_float32 a[sizeof(simde_v128_t) / sizeof(simde_float32)];

      test_vec[i] = simde_test_wasm_f32x4_random(-SIMDE_FLOAT32_C(1000.0), SIMDE_FLOAT32_C(1000.0));
      a[0] = simde_wasm_f32x4_extract_lane(test_vec[i], 0);
      a[1] = simde_wasm_f32x4_extract_lane(test_vec[i], 1);
      a[2] = simde_wasm_f32x4_extract_lane(test_vec[i], 2);
      a[3] = simde_wasm_f32x4_extract_lane(test_vec[i], 3);

      fprintf(SIMDE_CODEGEN_FP, "    a = simde_wasm_f32x4_const(SIMDE_FLOAT32_C(%9.2f), SIMDE_FLOAT32_C(%9.2f), SIMDE_FLOAT32_C(%9.2f), SIMDE_FLOAT32_C(%9.2f));\n",
             HEDLEY_STATIC_CAST(double, a[0]), HEDLEY_STATIC_CAST(double, a[1]), HEDLEY_STATIC_CAST(double, a[ 2]), HEDLEY_STATIC_CAST(double, a[ 3]));
      fprintf(SIMDE_CODEGEN_FP, "    simde_test_wasm_f32x4_assert_equal(a, simde_wasm_v128_load(test_vec[%1" PRId8 "]), 1);\n", i);
    }
    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_test_wasm_f32x4_write(2, test_vec[i], SIMDE_TEST_VEC_POS_MIDDLE);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_f64x2_const(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS simde_float64 test_vec[8][sizeof(simde_v128_t) / sizeof(simde_float64)] = {
      { SIMDE_FLOAT64_C(  -404.27), SIMDE_FLOAT64_C(   744.17) },
      { SIMDE_FLOAT64_C(  -796.31), SIMDE_FLOAT64_C(  -631.57) },
      { SIMDE_FLOAT64_C(   109.35), SIMDE_FLOAT64_C(   907.86) },
      { SIMDE_FLOAT64_C(  -796.44), SIMDE_FLOAT64_C(    17.86) },
      { SIMDE_FLOAT64_C(    -9.08), SIMDE_FLOAT64_C(  -411.51) },
      { SIMDE_FLOAT64_C(  -241.29), SIMDE_FLOAT64_C(   839.64) },
      { SIMDE_FLOAT64_C(   -35.03), SIMDE_FLOAT64_C(  -131.07) },
      { SIMDE_FLOAT64_C(  -934.16), SIMDE_FLOAT64_C(  -953.38) }
    };
    simde_v128_t a;

    a = simde_wasm_f64x2_const(SIMDE_FLOAT64_C(  -404.27), SIMDE_FLOAT64_C(   744.17));
    simde_test_wasm_f64x2_assert_equal(a, simde_wasm_v128_load(test_vec[0]), 1);
    a = simde_wasm_f64x2_const(SIMDE_FLOAT64_C(  -796.31), SIMDE_FLOAT64_C(  -631.57));
    simde_test_wasm_f64x2_assert_equal(a, simde_wasm_v128_load(test_vec[1]), 1);
    a = simde_wasm_f64x2_const(SIMDE_FLOAT64_C(   109.35), SIMDE_FLOAT64_C(   907.86));
    simde_test_wasm_f64x2_assert_equal(a, simde_wasm_v128_load(test_vec[2]), 1);
    a = simde_wasm_f64x2_const(SIMDE_FLOAT64_C(  -796.44), SIMDE_FLOAT64_C(    17.86));
    simde_test_wasm_f64x2_assert_equal(a, simde_wasm_v128_load(test_vec[3]), 1);
    a = simde_wasm_f64x2_const(SIMDE_FLOAT64_C(    -9.08), SIMDE_FLOAT64_C(  -411.51));
    simde_test_wasm_f64x2_assert_equal(a, simde_wasm_v128_load(test_vec[4]), 1);
    a = simde_wasm_f64x2_const(SIMDE_FLOAT64_C(  -241.29), SIMDE_FLOAT64_C(   839.64));
    simde_test_wasm_f64x2_assert_equal(a, simde_wasm_v128_load(test_vec[5]), 1);
    a = simde_wasm_f64x2_const(SIMDE_FLOAT64_C(   -35.03), SIMDE_FLOAT64_C(  -131.07));
    simde_test_wasm_f64x2_assert_equal(a, simde_wasm_v128_load(test_vec[6]), 1);
    a = simde_wasm_f64x2_const(SIMDE_FLOAT64_C(  -934.16), SIMDE_FLOAT64_C(  -953.38));
    simde_test_wasm_f64x2_assert_equal(a, simde_wasm_v128_load(test_vec[7]), 1);

    return 0;
  #else
    simde_v128_t test_vec[8];
    fputc('\n', stdout);

    for (int i = 0 ; i < 8 ; i++) {
      simde_float64 a[sizeof(simde_v128_t) / sizeof(simde_float64)];

      test_vec[i] = simde_test_wasm_f64x2_random(-SIMDE_FLOAT64_C(1000.0), SIMDE_FLOAT64_C(1000.0));
      a[0] = simde_wasm_f64x2_extract_lane(test_vec[i], 0);
      a[1] = simde_wasm_f64x2_extract_lane(test_vec[i], 1);

      fprintf(SIMDE_CODEGEN_FP,"    a = simde_wasm_f64x2_const(SIMDE_FLOAT64_C(%9.2f), SIMDE_FLOAT64_C(%9.2f));\n",
             a[0], a[1]);
      fprintf(SIMDE_CODEGEN_FP, "    simde_test_wasm_f64x2_assert_equal(a, simde_wasm_v128_load(test_vec[%1" PRId8 "]), 1);\n", i);
    }
    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_test_wasm_f64x2_write(2, test_vec[i], SIMDE_TEST_VEC_POS_MIDDLE);
    }
    return 1;
  #endif
}


SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_i8x16_const)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_u8x16_const)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_i16x8_const)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_u16x8_const)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_i32x4_const)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_u32x4_const)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_i64x2_const)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_u64x2_const)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_f32x4_const)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_f64x2_const)
SIMDE_TEST_FUNC_LIST_END

#include "test-simd128-footer.h"
