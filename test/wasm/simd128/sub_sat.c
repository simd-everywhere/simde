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

#define SIMDE_TEST_WASM_SIMD128_INSN sub_sat
#include "../../../simde/wasm/simd128.h"
#include "test-simd128.h"

static int
test_simde_wasm_i8x16_sub_sat(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      int8_t a[sizeof(simde_v128_t) / sizeof(int8_t)];
      int8_t b[sizeof(simde_v128_t) / sizeof(int8_t)];
      int8_t r[sizeof(simde_v128_t) / sizeof(int8_t)];
    } test_vec[] = {
      { { -INT8_C(  14), -INT8_C(  81),  INT8_C(  80), -INT8_C(  96),  INT8_C(  31),  INT8_C(  53),  INT8_C(  17), -INT8_C(   7),
          -INT8_C(  96),  INT8_C(   3),  INT8_C(  16), -INT8_C(   4), -INT8_C(  70), -INT8_C(   9),  INT8_C( 106), -INT8_C(  43) },
        { -INT8_C(  67),      INT8_MIN,  INT8_C(  53),  INT8_C(  97), -INT8_C(   5), -INT8_C(  77),  INT8_C(  63),  INT8_C( 107),
           INT8_C(  16), -INT8_C(  50),  INT8_C(  66), -INT8_C( 109),  INT8_C(   4),  INT8_C(  61),  INT8_C( 105), -INT8_C(  29) },
        {  INT8_C(  53),  INT8_C(  47),  INT8_C(  27),      INT8_MIN,  INT8_C(  36),      INT8_MAX, -INT8_C(  46), -INT8_C( 114),
          -INT8_C( 112),  INT8_C(  53), -INT8_C(  50),  INT8_C( 105), -INT8_C(  74), -INT8_C(  70),  INT8_C(   1), -INT8_C(  14) } },
      { { -INT8_C(  72), -INT8_C(  29),  INT8_C( 100),  INT8_C(  96),  INT8_C(  65),  INT8_C(  18), -INT8_C(  49),  INT8_C(  50),
           INT8_C(  16), -INT8_C(  85),  INT8_C(  55), -INT8_C(  21),  INT8_C(   3),  INT8_C( 124), -INT8_C( 111),  INT8_C(  70) },
        {  INT8_C( 115),  INT8_C(  14),  INT8_C(  16), -INT8_C(  38),  INT8_C(  50),  INT8_C(  47),  INT8_C(  83),  INT8_C(  10),
          -INT8_C(  97), -INT8_C(   4),  INT8_C(  28),  INT8_C( 109), -INT8_C(  23),  INT8_C( 120), -INT8_C(  78),  INT8_C(  19) },
        {      INT8_MIN, -INT8_C(  43),  INT8_C(  84),      INT8_MAX,  INT8_C(  15), -INT8_C(  29),      INT8_MIN,  INT8_C(  40),
           INT8_C( 113), -INT8_C(  81),  INT8_C(  27),      INT8_MIN,  INT8_C(  26),  INT8_C(   4), -INT8_C(  33),  INT8_C(  51) } },
      { { -INT8_C(  95),  INT8_C(   5),  INT8_C(  18),  INT8_C(  80),  INT8_C(  33), -INT8_C(  17),  INT8_C(  74), -INT8_C(  38),
          -INT8_C(  67), -INT8_C(  16), -INT8_C( 105), -INT8_C(   9),  INT8_C(  17), -INT8_C( 121),  INT8_C(  29),  INT8_C(  48) },
        {  INT8_C(  11), -INT8_C( 126), -INT8_C(  61),  INT8_C(  24),  INT8_C(  40), -INT8_C(  76), -INT8_C( 117),  INT8_C( 110),
          -INT8_C(   9), -INT8_C(  77), -INT8_C(  79), -INT8_C(  62), -INT8_C(   9),  INT8_C(  52),  INT8_C(  85), -INT8_C(  32) },
        { -INT8_C( 106),      INT8_MAX,  INT8_C(  79),  INT8_C(  56), -INT8_C(   7),  INT8_C(  59),      INT8_MAX,      INT8_MIN,
          -INT8_C(  58),  INT8_C(  61), -INT8_C(  26),  INT8_C(  53),  INT8_C(  26),      INT8_MIN, -INT8_C(  56),  INT8_C(  80) } },
      { {  INT8_C(  21),  INT8_C(  69),  INT8_C(  80),  INT8_C( 125), -INT8_C(  55),  INT8_C(  10), -INT8_C(  89), -INT8_C(  82),
           INT8_C(  70), -INT8_C(  75),  INT8_C(   3), -INT8_C( 101), -INT8_C(  25), -INT8_C(  35),  INT8_C( 109),  INT8_C( 121) },
        {  INT8_C(  85),  INT8_C(  62),  INT8_C(  34), -INT8_C(  15),  INT8_C(  17),  INT8_C(  27), -INT8_C(  99), -INT8_C(  73),
          -INT8_C(  59), -INT8_C( 101), -INT8_C(  89), -INT8_C(  27), -INT8_C(  22), -INT8_C(  46), -INT8_C( 121), -INT8_C(  61) },
        { -INT8_C(  64),  INT8_C(   7),  INT8_C(  46),      INT8_MAX, -INT8_C(  72), -INT8_C(  17),  INT8_C(  10), -INT8_C(   9),
               INT8_MAX,  INT8_C(  26),  INT8_C(  92), -INT8_C(  74), -INT8_C(   3),  INT8_C(  11),      INT8_MAX,      INT8_MAX } },
      { { -INT8_C(  57),  INT8_C(  24), -INT8_C(  62), -INT8_C(  64), -INT8_C(  91),  INT8_C(  86), -INT8_C( 120),  INT8_C( 103),
          -INT8_C(  65),  INT8_C(  66),  INT8_C( 120), -INT8_C(  17),  INT8_C(  97),  INT8_C( 113), -INT8_C(   1), -INT8_C( 109) },
        {  INT8_C(  23), -INT8_C(  99), -INT8_C(  61), -INT8_C(  27),  INT8_C(  79), -INT8_C(  32), -INT8_C(  96), -INT8_C(  40),
          -INT8_C( 115),  INT8_C( 102),  INT8_C(  12),  INT8_C(  19), -INT8_C(  42), -INT8_C(  66), -INT8_C(  75),  INT8_C(   4) },
        { -INT8_C(  80),  INT8_C( 123), -INT8_C(   1), -INT8_C(  37),      INT8_MIN,  INT8_C( 118), -INT8_C(  24),      INT8_MAX,
           INT8_C(  50), -INT8_C(  36),  INT8_C( 108), -INT8_C(  36),      INT8_MAX,      INT8_MAX,  INT8_C(  74), -INT8_C( 113) } },
      { {  INT8_C( 118),      INT8_MIN,  INT8_C(  59),  INT8_C(  88),  INT8_C( 121),  INT8_C(  55),  INT8_C(  52),  INT8_C(  70),
          -INT8_C(  44),  INT8_C( 105), -INT8_C(   3),  INT8_C(  37), -INT8_C( 118), -INT8_C(   3),  INT8_C(   1), -INT8_C(  20) },
        { -INT8_C( 106), -INT8_C(   4),  INT8_C(  52),  INT8_C( 123),  INT8_C(  36), -INT8_C( 101), -INT8_C(   8), -INT8_C(  26),
          -INT8_C( 115), -INT8_C(  78), -INT8_C(  13), -INT8_C(  77),  INT8_C(  52), -INT8_C(  57), -INT8_C(  49), -INT8_C(  16) },
        {      INT8_MAX, -INT8_C( 124),  INT8_C(   7), -INT8_C(  35),  INT8_C(  85),      INT8_MAX,  INT8_C(  60),  INT8_C(  96),
           INT8_C(  71),      INT8_MAX,  INT8_C(  10),  INT8_C( 114),      INT8_MIN,  INT8_C(  54),  INT8_C(  50), -INT8_C(   4) } },
      { {  INT8_C(  45), -INT8_C(  41), -INT8_C(  76),  INT8_C(  10), -INT8_C(  45), -INT8_C(  78),  INT8_C(  70),  INT8_C(  41),
           INT8_C( 110),  INT8_C(  47), -INT8_C(   8), -INT8_C( 116),  INT8_C( 115),  INT8_C(  28),  INT8_C(  90), -INT8_C(  39) },
        { -INT8_C( 104),  INT8_C(  64), -INT8_C(  71),  INT8_C(  32), -INT8_C(  25), -INT8_C(  17), -INT8_C(  65), -INT8_C(  22),
           INT8_C(  32),  INT8_C( 115), -INT8_C( 114),  INT8_C(  26),  INT8_C( 126), -INT8_C(   9),  INT8_C(  20), -INT8_C( 125) },
        {      INT8_MAX, -INT8_C( 105), -INT8_C(   5), -INT8_C(  22), -INT8_C(  20), -INT8_C(  61),      INT8_MAX,  INT8_C(  63),
           INT8_C(  78), -INT8_C(  68),  INT8_C( 106),      INT8_MIN, -INT8_C(  11),  INT8_C(  37),  INT8_C(  70),  INT8_C(  86) } },
      { {  INT8_C(  12),  INT8_C(  15), -INT8_C(  55), -INT8_C(  60), -INT8_C(   3),  INT8_C(  43), -INT8_C(  45),  INT8_C(  20),
          -INT8_C(  47), -INT8_C(  13),  INT8_C(  15),  INT8_C(  11),      INT8_MIN, -INT8_C(  36),  INT8_C(  50),  INT8_C(   9) },
        { -INT8_C(  28), -INT8_C(  35), -INT8_C( 125), -INT8_C( 120), -INT8_C(  77),  INT8_C(  10), -INT8_C(  78),  INT8_C(  42),
          -INT8_C(  98), -INT8_C(  35), -INT8_C(  51), -INT8_C(  60),  INT8_C(  56), -INT8_C(  24),  INT8_C(  91), -INT8_C( 103) },
        {  INT8_C(  40),  INT8_C(  50),  INT8_C(  70),  INT8_C(  60),  INT8_C(  74),  INT8_C(  33),  INT8_C(  33), -INT8_C(  22),
           INT8_C(  51),  INT8_C(  22),  INT8_C(  66),  INT8_C(  71),      INT8_MIN, -INT8_C(  12), -INT8_C(  41),  INT8_C( 112) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t b = simde_wasm_v128_load(test_vec[i].b);
      simde_v128_t r = simde_wasm_i8x16_sub_sat(a, b);
      simde_test_wasm_i8x16_assert_equal(r, simde_wasm_v128_load(test_vec[i].r));
    }
    return 0;
  #else
    fputc('\n', stdout);
    for (int i = 0 ; i < 8 ; i++) {
      simde_v128_t
        a = simde_test_wasm_i8x16_random(),
        b = simde_test_wasm_i8x16_random(),
        r;

      r = simde_wasm_i8x16_sub_sat(a, b);

      simde_test_wasm_i8x16_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_i8x16_write(3, b, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_wasm_i8x16_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_i16x8_sub_sat(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      int16_t a[sizeof(simde_v128_t) / sizeof(int16_t)];
      int16_t b[sizeof(simde_v128_t) / sizeof(int16_t)];
      int16_t r[sizeof(simde_v128_t) / sizeof(int16_t)];
    } test_vec[] = {
      { {  INT16_C( 32643), -INT16_C( 18764), -INT16_C( 27279),  INT16_C( 17691),  INT16_C(  5190),  INT16_C(  9087), -INT16_C( 10178),  INT16_C( 29442) },
        {  INT16_C( 24136), -INT16_C( 30349), -INT16_C( 26978), -INT16_C(   868), -INT16_C( 14908),  INT16_C(  5232), -INT16_C( 25716), -INT16_C( 24864) },
        {  INT16_C(  8507),  INT16_C( 11585), -INT16_C(   301),  INT16_C( 18559),  INT16_C( 20098),  INT16_C(  3855),  INT16_C( 15538),       INT16_MAX } },
      { {  INT16_C( 10269), -INT16_C(  2361),  INT16_C( 12494), -INT16_C( 16466),  INT16_C(  6710),  INT16_C( 27639), -INT16_C( 12106), -INT16_C( 15333) },
        {  INT16_C( 26907),  INT16_C( 32588),  INT16_C( 13417),  INT16_C(  5951), -INT16_C( 29546), -INT16_C( 26963), -INT16_C( 11688), -INT16_C( 16756) },
        { -INT16_C( 16638),       INT16_MIN, -INT16_C(   923), -INT16_C( 22417),       INT16_MAX,       INT16_MAX, -INT16_C(   418),  INT16_C(  1423) } },
      { {  INT16_C( 31423), -INT16_C( 25499), -INT16_C( 17851),  INT16_C( 23835),  INT16_C( 22741), -INT16_C( 27658), -INT16_C( 17857),  INT16_C( 20402) },
        {  INT16_C( 19518),  INT16_C( 10098),  INT16_C( 28853),  INT16_C( 23744), -INT16_C( 31042), -INT16_C( 17342), -INT16_C(  7230), -INT16_C( 29244) },
        {  INT16_C( 11905),       INT16_MIN,       INT16_MIN,  INT16_C(    91),       INT16_MAX, -INT16_C( 10316), -INT16_C( 10627),       INT16_MAX } },
      { { -INT16_C( 25239),  INT16_C( 24964),  INT16_C( 11154),  INT16_C( 23833),  INT16_C(  6975), -INT16_C(  8541),  INT16_C( 25555),  INT16_C( 31086) },
        { -INT16_C(   603), -INT16_C(   473),  INT16_C( 14518),  INT16_C( 10645), -INT16_C(  8332),  INT16_C(  7190),  INT16_C(  4682),  INT16_C( 16562) },
        { -INT16_C( 24636),  INT16_C( 25437), -INT16_C(  3364),  INT16_C( 13188),  INT16_C( 15307), -INT16_C( 15731),  INT16_C( 20873),  INT16_C( 14524) } },
      { {  INT16_C( 14975), -INT16_C( 15968), -INT16_C(  6291),  INT16_C( 28980),  INT16_C( 18461),  INT16_C(  9513),  INT16_C( 32223), -INT16_C( 20625) },
        { -INT16_C( 22957),  INT16_C(  9538), -INT16_C( 10652),  INT16_C( 10731),  INT16_C(   476),  INT16_C( 12881),  INT16_C( 26207),  INT16_C( 21518) },
        {       INT16_MAX, -INT16_C( 25506),  INT16_C(  4361),  INT16_C( 18249),  INT16_C( 17985), -INT16_C(  3368),  INT16_C(  6016),       INT16_MIN } },
      { { -INT16_C( 16761), -INT16_C( 26822),  INT16_C( 31358),  INT16_C( 20470), -INT16_C( 29493),  INT16_C( 22164),  INT16_C( 14743), -INT16_C( 12839) },
        { -INT16_C( 21792), -INT16_C( 17811),  INT16_C( 25904), -INT16_C( 24430), -INT16_C( 32018), -INT16_C( 25610),  INT16_C(   370), -INT16_C( 15762) },
        {  INT16_C(  5031), -INT16_C(  9011),  INT16_C(  5454),       INT16_MAX,  INT16_C(  2525),       INT16_MAX,  INT16_C( 14373),  INT16_C(  2923) } },
      { {  INT16_C(  8811),  INT16_C( 15571), -INT16_C( 13366), -INT16_C( 17004), -INT16_C(  1291),  INT16_C( 28456),  INT16_C( 24780),  INT16_C(  4836) },
        {  INT16_C( 11132), -INT16_C( 17954), -INT16_C( 14537),  INT16_C( 15213), -INT16_C( 32298), -INT16_C(  9983), -INT16_C(  1658), -INT16_C( 21748) },
        { -INT16_C(  2321),       INT16_MAX,  INT16_C(  1171), -INT16_C( 32217),  INT16_C( 31007),       INT16_MAX,  INT16_C( 26438),  INT16_C( 26584) } },
      { {  INT16_C( 13378),  INT16_C( 10342), -INT16_C( 10575),  INT16_C(  9237),  INT16_C( 15038),  INT16_C(   574), -INT16_C(  6340), -INT16_C( 29088) },
        {  INT16_C(  4979),  INT16_C( 23701),  INT16_C(  7667),  INT16_C( 24918), -INT16_C( 27176), -INT16_C( 29950), -INT16_C( 22201), -INT16_C( 30957) },
        {  INT16_C(  8399), -INT16_C( 13359), -INT16_C( 18242), -INT16_C( 15681),       INT16_MAX,  INT16_C( 30524),  INT16_C( 15861),  INT16_C(  1869) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t b = simde_wasm_v128_load(test_vec[i].b);
      simde_v128_t r = simde_wasm_i16x8_sub_sat(a, b);
      simde_test_wasm_i16x8_assert_equal(r, simde_wasm_v128_load(test_vec[i].r));
    }
    return 0;
  #else
    fputc('\n', stdout);
    for (int i = 0 ; i < 8 ; i++) {
      simde_v128_t
        a = simde_test_wasm_i16x8_random(),
        b = simde_test_wasm_i16x8_random(),
        r;

      r = simde_wasm_i16x8_sub_sat(a, b);

      simde_test_wasm_i16x8_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_i16x8_write(3, b, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_wasm_i16x8_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_u8x16_sub_sat(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      uint8_t a[sizeof(simde_v128_t) / sizeof(uint8_t)];
      uint8_t b[sizeof(simde_v128_t) / sizeof(uint8_t)];
      uint8_t r[sizeof(simde_v128_t) / sizeof(uint8_t)];
    } test_vec[] = {
      { { UINT8_C(181), UINT8_C(133), UINT8_C(118), UINT8_C(247), UINT8_C(  7), UINT8_C(205), UINT8_C(138), UINT8_C(185),
          UINT8_C( 29), UINT8_C( 18), UINT8_C( 96), UINT8_C(212), UINT8_C( 26), UINT8_C(227), UINT8_C( 25), UINT8_C(203) },
        { UINT8_C( 48), UINT8_C(228), UINT8_C( 65), UINT8_C( 82), UINT8_C(113), UINT8_C(200), UINT8_C( 82), UINT8_C(169),
          UINT8_C( 66), UINT8_C(153), UINT8_C(159), UINT8_C(184), UINT8_C(130), UINT8_C(135), UINT8_C(250), UINT8_C( 66) },
        { UINT8_C(133), UINT8_C(  0), UINT8_C( 53), UINT8_C(165), UINT8_C(  0), UINT8_C(  5), UINT8_C( 56), UINT8_C( 16),
          UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C( 28), UINT8_C(  0), UINT8_C( 92), UINT8_C(  0), UINT8_C(137) } },
      { { UINT8_C(234), UINT8_C( 36), UINT8_C( 76), UINT8_C(246), UINT8_C(244), UINT8_C(174), UINT8_C( 29), UINT8_C( 45),
          UINT8_C( 66), UINT8_C( 98), UINT8_C( 53), UINT8_C(229), UINT8_C( 63), UINT8_C( 21), UINT8_C(234), UINT8_C( 44) },
        { UINT8_C(249), UINT8_C(249), UINT8_C(104), UINT8_C(177), UINT8_C(115), UINT8_C(130), UINT8_C( 15), UINT8_C( 54),
          UINT8_C(  6), UINT8_C(244), UINT8_C(173), UINT8_C( 18), UINT8_C(181), UINT8_C(158), UINT8_C( 11), UINT8_C( 13) },
        { UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C( 69), UINT8_C(129), UINT8_C( 44), UINT8_C( 14), UINT8_C(  0),
          UINT8_C( 60), UINT8_C(  0), UINT8_C(  0), UINT8_C(211), UINT8_C(  0), UINT8_C(  0), UINT8_C(223), UINT8_C( 31) } },
      { { UINT8_C( 57), UINT8_C(122), UINT8_C(101), UINT8_C(195), UINT8_C( 93), UINT8_C(150), UINT8_C(113), UINT8_C( 66),
          UINT8_C( 72), UINT8_C(234), UINT8_C(196), UINT8_C(154), UINT8_C(  0), UINT8_C(133), UINT8_C( 62), UINT8_C(115) },
        { UINT8_C( 78), UINT8_C(109), UINT8_C(205), UINT8_C(101), UINT8_C( 13), UINT8_C(197), UINT8_C( 11), UINT8_C(106),
          UINT8_C( 32), UINT8_C( 15), UINT8_C(247), UINT8_C(185), UINT8_C( 17), UINT8_C( 10), UINT8_C(246), UINT8_C(159) },
        { UINT8_C(  0), UINT8_C( 13), UINT8_C(  0), UINT8_C( 94), UINT8_C( 80), UINT8_C(  0), UINT8_C(102), UINT8_C(  0),
          UINT8_C( 40), UINT8_C(219), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(123), UINT8_C(  0), UINT8_C(  0) } },
      { { UINT8_C( 40), UINT8_C( 36), UINT8_C(151), UINT8_C(151), UINT8_C(  8), UINT8_C( 33), UINT8_C(205), UINT8_C(138),
          UINT8_C(230), UINT8_C(216), UINT8_C(186), UINT8_C(202), UINT8_C(122), UINT8_C(250), UINT8_C( 27), UINT8_C( 10) },
        { UINT8_C(148), UINT8_C(103), UINT8_C( 78), UINT8_C(175), UINT8_C(174), UINT8_C(141), UINT8_C( 82), UINT8_C(  5),
          UINT8_C(202), UINT8_C(160), UINT8_C(243), UINT8_C(  1), UINT8_C( 87), UINT8_C( 15), UINT8_C(138), UINT8_C( 77) },
        { UINT8_C(  0), UINT8_C(  0), UINT8_C( 73), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(123), UINT8_C(133),
          UINT8_C( 28), UINT8_C( 56), UINT8_C(  0), UINT8_C(201), UINT8_C( 35), UINT8_C(235), UINT8_C(  0), UINT8_C(  0) } },
      { { UINT8_C( 78), UINT8_C(237), UINT8_C( 51), UINT8_C( 30), UINT8_C(199), UINT8_C(192), UINT8_C(185), UINT8_C(172),
          UINT8_C(193), UINT8_C( 61), UINT8_C( 29), UINT8_C( 31), UINT8_C(225), UINT8_C(128), UINT8_C(170), UINT8_C(227) },
        { UINT8_C( 22), UINT8_C(223), UINT8_C(207), UINT8_C(246), UINT8_C(121), UINT8_C( 65), UINT8_C( 82), UINT8_C( 62),
          UINT8_C( 44), UINT8_C( 84), UINT8_C(171), UINT8_C(171), UINT8_C( 46), UINT8_C( 61), UINT8_C(143), UINT8_C( 73) },
        { UINT8_C( 56), UINT8_C( 14), UINT8_C(  0), UINT8_C(  0), UINT8_C( 78), UINT8_C(127), UINT8_C(103), UINT8_C(110),
          UINT8_C(149), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(179), UINT8_C( 67), UINT8_C( 27), UINT8_C(154) } },
      { { UINT8_C( 83), UINT8_C(239), UINT8_C(126), UINT8_C(177), UINT8_C( 39), UINT8_C(197), UINT8_C(162), UINT8_C(  9),
          UINT8_C(203), UINT8_C( 13), UINT8_C( 29), UINT8_C( 37), UINT8_C(135), UINT8_C( 86), UINT8_C( 63), UINT8_C(  0) },
        { UINT8_C(184), UINT8_C(122), UINT8_C(113), UINT8_C(180), UINT8_C(176), UINT8_C(130), UINT8_C( 61), UINT8_C( 40),
          UINT8_C(117), UINT8_C(135), UINT8_C( 74), UINT8_C(184), UINT8_C(246), UINT8_C( 26), UINT8_C(131), UINT8_C(232) },
        { UINT8_C(  0), UINT8_C(117), UINT8_C( 13), UINT8_C(  0), UINT8_C(  0), UINT8_C( 67), UINT8_C(101), UINT8_C(  0),
          UINT8_C( 86), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C( 60), UINT8_C(  0), UINT8_C(  0) } },
      { { UINT8_C(106), UINT8_C( 51), UINT8_C(161), UINT8_C( 13), UINT8_C(155), UINT8_C(241), UINT8_C(248), UINT8_C(226),
          UINT8_C( 23), UINT8_C(159), UINT8_C(102), UINT8_C(232), UINT8_C(107), UINT8_C( 88), UINT8_C(214), UINT8_C(123) },
        { UINT8_C( 56), UINT8_C(234), UINT8_C( 66), UINT8_C(244), UINT8_C(160), UINT8_C(119), UINT8_C(237), UINT8_C(159),
          UINT8_C(118), UINT8_C(135), UINT8_C( 52), UINT8_C(195), UINT8_C( 17), UINT8_C( 87), UINT8_C(227), UINT8_C(105) },
        { UINT8_C( 50), UINT8_C(  0), UINT8_C( 95), UINT8_C(  0), UINT8_C(  0), UINT8_C(122), UINT8_C( 11), UINT8_C( 67),
          UINT8_C(  0), UINT8_C( 24), UINT8_C( 50), UINT8_C( 37), UINT8_C( 90), UINT8_C(  1), UINT8_C(  0), UINT8_C( 18) } },
      { { UINT8_C( 75), UINT8_C(206), UINT8_C( 30), UINT8_C(137), UINT8_C( 35), UINT8_C(134), UINT8_C(215), UINT8_C(  3),
          UINT8_C( 59), UINT8_C(167), UINT8_C(247), UINT8_C(  8), UINT8_C( 67), UINT8_C(245), UINT8_C( 29), UINT8_C( 12) },
        { UINT8_C(231), UINT8_C(208), UINT8_C(116), UINT8_C( 73), UINT8_C( 10), UINT8_C(161), UINT8_C( 70), UINT8_C(167),
          UINT8_C(192), UINT8_C( 82), UINT8_C(150), UINT8_C(214), UINT8_C(170), UINT8_C(123), UINT8_C(235), UINT8_C( 63) },
        { UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C( 64), UINT8_C( 25), UINT8_C(  0), UINT8_C(145), UINT8_C(  0),
          UINT8_C(  0), UINT8_C( 85), UINT8_C( 97), UINT8_C(  0), UINT8_C(  0), UINT8_C(122), UINT8_C(  0), UINT8_C(  0) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t b = simde_wasm_v128_load(test_vec[i].b);
      simde_v128_t r = simde_wasm_u8x16_sub_sat(a, b);
      simde_test_wasm_u8x16_assert_equal(r, simde_wasm_v128_load(test_vec[i].r));
    }
    return 0;
  #else
    fputc('\n', stdout);
    for (int i = 0 ; i < 8 ; i++) {
      simde_v128_t
        a = simde_test_wasm_u8x16_random(),
        b = simde_test_wasm_u8x16_random(),
        r;

      r = simde_wasm_u8x16_sub_sat(a, b);

      simde_test_wasm_u8x16_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_u8x16_write(3, b, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_wasm_u8x16_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_u16x8_sub_sat(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      uint16_t a[sizeof(simde_v128_t) / sizeof(uint16_t)];
      uint16_t b[sizeof(simde_v128_t) / sizeof(uint16_t)];
      uint16_t r[sizeof(simde_v128_t) / sizeof(uint16_t)];
    } test_vec[] = {
      { { UINT16_C(46319), UINT16_C(34642), UINT16_C(42208), UINT16_C( 2470), UINT16_C(15950), UINT16_C(43214), UINT16_C(24330), UINT16_C(34523) },
        { UINT16_C( 6666), UINT16_C(33370), UINT16_C( 2150), UINT16_C(10779), UINT16_C( 3569), UINT16_C(24565), UINT16_C(26451), UINT16_C(21503) },
        { UINT16_C(39653), UINT16_C( 1272), UINT16_C(40058), UINT16_C(    0), UINT16_C(12381), UINT16_C(18649), UINT16_C(    0), UINT16_C(13020) } },
      { { UINT16_C(15317), UINT16_C(47909), UINT16_C(22763), UINT16_C(35978), UINT16_C(50048), UINT16_C(51021), UINT16_C(36352), UINT16_C( 1479) },
        { UINT16_C(33860), UINT16_C( 9086), UINT16_C(54848), UINT16_C(52021), UINT16_C(49156), UINT16_C(27653), UINT16_C( 2712), UINT16_C( 5089) },
        { UINT16_C(    0), UINT16_C(38823), UINT16_C(    0), UINT16_C(    0), UINT16_C(  892), UINT16_C(23368), UINT16_C(33640), UINT16_C(    0) } },
      { { UINT16_C(11553), UINT16_C(  560), UINT16_C(46429), UINT16_C( 6760), UINT16_C(62452), UINT16_C(22591), UINT16_C(18987), UINT16_C(51573) },
        { UINT16_C(59361), UINT16_C(64968), UINT16_C(51873), UINT16_C(14279), UINT16_C(18305), UINT16_C(29239), UINT16_C(25527), UINT16_C( 6400) },
        { UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(44147), UINT16_C(    0), UINT16_C(    0), UINT16_C(45173) } },
      { { UINT16_C(64181), UINT16_C(46973), UINT16_C(41899), UINT16_C(61208), UINT16_C(24265), UINT16_C(22606), UINT16_C(41942), UINT16_C(46194) },
        { UINT16_C(28495), UINT16_C(47042), UINT16_C(27981), UINT16_C(45342), UINT16_C(  652), UINT16_C( 7038), UINT16_C(49483), UINT16_C(61725) },
        { UINT16_C(35686), UINT16_C(    0), UINT16_C(13918), UINT16_C(15866), UINT16_C(23613), UINT16_C(15568), UINT16_C(    0), UINT16_C(    0) } },
      { { UINT16_C(44768), UINT16_C(59896), UINT16_C(19213), UINT16_C(44779), UINT16_C(54480), UINT16_C(29106), UINT16_C( 9696), UINT16_C( 2011) },
        { UINT16_C( 8646), UINT16_C(22476), UINT16_C(31170), UINT16_C( 1611), UINT16_C(48640), UINT16_C(54148), UINT16_C(55072), UINT16_C( 4105) },
        { UINT16_C(36122), UINT16_C(37420), UINT16_C(    0), UINT16_C(43168), UINT16_C( 5840), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) } },
      { { UINT16_C(19575), UINT16_C(36281), UINT16_C(56262), UINT16_C(33955), UINT16_C(39933), UINT16_C( 2272), UINT16_C(33117), UINT16_C(24251) },
        { UINT16_C(61723), UINT16_C(11307), UINT16_C(25401), UINT16_C(27359), UINT16_C(43175), UINT16_C(39954), UINT16_C( 7576), UINT16_C(39614) },
        { UINT16_C(    0), UINT16_C(24974), UINT16_C(30861), UINT16_C( 6596), UINT16_C(    0), UINT16_C(    0), UINT16_C(25541), UINT16_C(    0) } },
      { { UINT16_C(41571), UINT16_C(10961), UINT16_C(53731), UINT16_C(50923), UINT16_C( 9819), UINT16_C(52659), UINT16_C(46008), UINT16_C(13281) },
        { UINT16_C(23825), UINT16_C(16526), UINT16_C(24612), UINT16_C(56100), UINT16_C(51179), UINT16_C(23041), UINT16_C(48531), UINT16_C(40186) },
        { UINT16_C(17746), UINT16_C(    0), UINT16_C(29119), UINT16_C(    0), UINT16_C(    0), UINT16_C(29618), UINT16_C(    0), UINT16_C(    0) } },
      { { UINT16_C(41400), UINT16_C( 2451), UINT16_C(48768), UINT16_C( 4443), UINT16_C(19841), UINT16_C(51737), UINT16_C(43352), UINT16_C(55361) },
        { UINT16_C(32815), UINT16_C(18207), UINT16_C(61753), UINT16_C(64216), UINT16_C(61960), UINT16_C(41117), UINT16_C(62920), UINT16_C(53341) },
        { UINT16_C( 8585), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(10620), UINT16_C(    0), UINT16_C( 2020) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t b = simde_wasm_v128_load(test_vec[i].b);
      simde_v128_t r = simde_wasm_u16x8_sub_sat(a, b);
      simde_test_wasm_u16x8_assert_equal(r, simde_wasm_v128_load(test_vec[i].r));
    }
    return 0;
  #else
    fputc('\n', stdout);
    for (int i = 0 ; i < 8 ; i++) {
      simde_v128_t
        a = simde_test_wasm_u16x8_random(),
        b = simde_test_wasm_u16x8_random(),
        r;

      r = simde_wasm_u16x8_sub_sat(a, b);

      simde_test_wasm_u16x8_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_u16x8_write(3, b, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_wasm_u16x8_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_i8x16_sub_sat)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_i16x8_sub_sat)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_u8x16_sub_sat)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_u16x8_sub_sat)
SIMDE_TEST_FUNC_LIST_END

#include "test-simd128-footer.h"
