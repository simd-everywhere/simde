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

#define SIMDE_TEST_WASM_SIMD128_INSN add_sat
#include "../../../simde/wasm/simd128.h"
#include "test-simd128.h"

static int
test_simde_wasm_i8x16_add_sat(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      int8_t a[sizeof(simde_v128_t) / sizeof(int8_t)];
      int8_t b[sizeof(simde_v128_t) / sizeof(int8_t)];
      int8_t r[sizeof(simde_v128_t) / sizeof(int8_t)];
    } test_vec[] = {
      { {  INT8_C(  67),  INT8_C(  12),  INT8_C(  47), -INT8_C(  90), -INT8_C(  17),  INT8_C(  66),  INT8_C( 109),  INT8_C( 119),
           INT8_C(  53), -INT8_C(  61),  INT8_C(   2),  INT8_C(  84), -INT8_C(   2),  INT8_C(  53),  INT8_C(  34),  INT8_C(  57) },
        { -INT8_C(   4),  INT8_C( 126), -INT8_C(  98), -INT8_C(  65),  INT8_C(  33), -INT8_C(  68),      INT8_MAX,  INT8_C( 126),
           INT8_C(  82), -INT8_C(  48),  INT8_C(  51), -INT8_C( 110),      INT8_MAX,  INT8_C(  34), -INT8_C(  97),  INT8_C(  39) },
        {  INT8_C(  63),      INT8_MAX, -INT8_C(  51),      INT8_MIN,  INT8_C(  16), -INT8_C(   2),      INT8_MAX,      INT8_MAX,
               INT8_MAX, -INT8_C( 109),  INT8_C(  53), -INT8_C(  26),  INT8_C( 125),  INT8_C(  87), -INT8_C(  63),  INT8_C(  96) } },
      { { -INT8_C(  81),  INT8_C(  17), -INT8_C(  26), -INT8_C(  74), -INT8_C( 117), -INT8_C( 113),  INT8_C(  79),  INT8_C(   4),
          -INT8_C(  34),  INT8_C(  98), -INT8_C(  88),  INT8_C(  77),  INT8_C(   8), -INT8_C( 114), -INT8_C( 125), -INT8_C(  22) },
        { -INT8_C( 123),  INT8_C(  29), -INT8_C(  94),  INT8_C(  27), -INT8_C(  27),  INT8_C(   4), -INT8_C(  91),  INT8_C(  86),
          -INT8_C(  96), -INT8_C(  35), -INT8_C(  92), -INT8_C( 100), -INT8_C(  75), -INT8_C( 102),  INT8_C(  98),  INT8_C(  66) },
        {      INT8_MIN,  INT8_C(  46), -INT8_C( 120), -INT8_C(  47),      INT8_MIN, -INT8_C( 109), -INT8_C(  12),  INT8_C(  90),
               INT8_MIN,  INT8_C(  63),      INT8_MIN, -INT8_C(  23), -INT8_C(  67),      INT8_MIN, -INT8_C(  27),  INT8_C(  44) } },
      { {  INT8_C(  63),  INT8_C(  31),  INT8_C( 100), -INT8_C(  40), -INT8_C(  76), -INT8_C( 106),  INT8_C(   2), -INT8_C(  59),
           INT8_C(  69),  INT8_C(  78), -INT8_C(  49), -INT8_C(  26), -INT8_C(  34), -INT8_C(  31), -INT8_C(  98), -INT8_C(  53) },
        {  INT8_C(  75),  INT8_C(   8), -INT8_C(  21),  INT8_C(   8), -INT8_C(  55), -INT8_C(   2),  INT8_C(   2),  INT8_C(  67),
           INT8_C(  28),  INT8_C(  48),  INT8_C(  84),  INT8_C(   1), -INT8_C( 127),  INT8_C( 106),  INT8_C(  96), -INT8_C(  35) },
        {      INT8_MAX,  INT8_C(  39),  INT8_C(  79), -INT8_C(  32),      INT8_MIN, -INT8_C( 108),  INT8_C(   4),  INT8_C(   8),
           INT8_C(  97),  INT8_C( 126),  INT8_C(  35), -INT8_C(  25),      INT8_MIN,  INT8_C(  75), -INT8_C(   2), -INT8_C(  88) } },
      { { -INT8_C( 100),  INT8_C(  82), -INT8_C( 112),  INT8_C(  72), -INT8_C(  25), -INT8_C(  22),  INT8_C(  76),  INT8_C(  96),
           INT8_C( 107), -INT8_C(  72), -INT8_C(   4), -INT8_C( 109), -INT8_C( 126),  INT8_C(   7), -INT8_C(  21), -INT8_C( 120) },
        { -INT8_C(  59),  INT8_C( 105),  INT8_C( 101),  INT8_C(   3),  INT8_C(  12), -INT8_C(  25), -INT8_C(  98),  INT8_C(  37),
          -INT8_C(  74),  INT8_C(  56), -INT8_C(  75),  INT8_C(  52),  INT8_C(  98), -INT8_C(  93), -INT8_C(  67),  INT8_C(  46) },
        {      INT8_MIN,      INT8_MAX, -INT8_C(  11),  INT8_C(  75), -INT8_C(  13), -INT8_C(  47), -INT8_C(  22),      INT8_MAX,
           INT8_C(  33), -INT8_C(  16), -INT8_C(  79), -INT8_C(  57), -INT8_C(  28), -INT8_C(  86), -INT8_C(  88), -INT8_C(  74) } },
      { { -INT8_C(  34), -INT8_C(  33), -INT8_C( 112),  INT8_C(  68), -INT8_C(  24), -INT8_C(  16),  INT8_C( 114),  INT8_C(  77),
          -INT8_C(  99),  INT8_C(   5),  INT8_C(  23), -INT8_C(  56), -INT8_C(  52), -INT8_C(   2),  INT8_C(  17),  INT8_C(  62) },
        { -INT8_C(  81), -INT8_C(  16),  INT8_C(  85), -INT8_C( 127), -INT8_C(  19),  INT8_C(  53), -INT8_C(  78),  INT8_C(  95),
          -INT8_C(  73),  INT8_C( 120),  INT8_C(  93), -INT8_C( 103), -INT8_C( 107),  INT8_C(  87),  INT8_C(  45), -INT8_C( 125) },
        { -INT8_C( 115), -INT8_C(  49), -INT8_C(  27), -INT8_C(  59), -INT8_C(  43),  INT8_C(  37),  INT8_C(  36),      INT8_MAX,
               INT8_MIN,  INT8_C( 125),  INT8_C( 116),      INT8_MIN,      INT8_MIN,  INT8_C(  85),  INT8_C(  62), -INT8_C(  63) } },
      { { -INT8_C(  97), -INT8_C(  46),  INT8_C(  92), -INT8_C(  29), -INT8_C( 110), -INT8_C( 119),  INT8_C(   4),  INT8_C(  30),
          -INT8_C(  13),  INT8_C( 112),  INT8_C(  86), -INT8_C(  77), -INT8_C( 104),      INT8_MAX,  INT8_C(  13), -INT8_C(  94) },
        { -INT8_C(  22),  INT8_C(  86), -INT8_C(  86), -INT8_C( 114),  INT8_C(  52),  INT8_C(   3),  INT8_C(  50), -INT8_C(  29),
           INT8_C(   1), -INT8_C(  22), -INT8_C(  61), -INT8_C(   9), -INT8_C(   1), -INT8_C(  27), -INT8_C(  34),  INT8_C(  34) },
        { -INT8_C( 119),  INT8_C(  40),  INT8_C(   6),      INT8_MIN, -INT8_C(  58), -INT8_C( 116),  INT8_C(  54),  INT8_C(   1),
          -INT8_C(  12),  INT8_C(  90),  INT8_C(  25), -INT8_C(  86), -INT8_C( 105),  INT8_C( 100), -INT8_C(  21), -INT8_C(  60) } },
      { { -INT8_C( 101),  INT8_C(  81), -INT8_C(  47),  INT8_C( 105),  INT8_C(  30),  INT8_C(  71),  INT8_C(  29),  INT8_C(  70),
           INT8_C(  69),  INT8_C(  37), -INT8_C(  71),  INT8_C( 115),  INT8_C( 110),  INT8_C(   6), -INT8_C(  44), -INT8_C(  90) },
        { -INT8_C(  45),  INT8_C(  90), -INT8_C(  44), -INT8_C(  34),  INT8_C(  60),  INT8_C(   3), -INT8_C(  48), -INT8_C(  74),
          -INT8_C(  59), -INT8_C(  42),  INT8_C( 107),  INT8_C( 115), -INT8_C( 104), -INT8_C(  52), -INT8_C(  45), -INT8_C(  76) },
        {      INT8_MIN,      INT8_MAX, -INT8_C(  91),  INT8_C(  71),  INT8_C(  90),  INT8_C(  74), -INT8_C(  19), -INT8_C(   4),
           INT8_C(  10), -INT8_C(   5),  INT8_C(  36),      INT8_MAX,  INT8_C(   6), -INT8_C(  46), -INT8_C(  89),      INT8_MIN } },
      { { -INT8_C(  53),  INT8_C(  85),  INT8_C(  68),  INT8_C(  32), -INT8_C(  19),  INT8_C(  23),  INT8_C(  35),  INT8_C(  96),
          -INT8_C(  85), -INT8_C(  28), -INT8_C(  10), -INT8_C(  48), -INT8_C(  78),  INT8_C(  99),  INT8_C( 114), -INT8_C(  92) },
        {  INT8_C(  36),  INT8_C(  67),  INT8_C(  18),  INT8_C( 103), -INT8_C( 126), -INT8_C(  21),  INT8_C( 121), -INT8_C(   5),
          -INT8_C(  64),  INT8_C(  57), -INT8_C( 101),  INT8_C(   3),  INT8_C(  86), -INT8_C(  12), -INT8_C(  51),  INT8_C(  43) },
        { -INT8_C(  17),      INT8_MAX,  INT8_C(  86),      INT8_MAX,      INT8_MIN,  INT8_C(   2),      INT8_MAX,  INT8_C(  91),
               INT8_MIN,  INT8_C(  29), -INT8_C( 111), -INT8_C(  45),  INT8_C(   8),  INT8_C(  87),  INT8_C(  63), -INT8_C(  49) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t b = simde_wasm_v128_load(test_vec[i].b);
      simde_v128_t r = simde_wasm_i8x16_add_sat(a, b);
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

      r = simde_wasm_i8x16_add_sat(a, b);

      simde_test_wasm_i8x16_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_i8x16_write(3, b, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_wasm_i8x16_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_i16x8_add_sat(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      int16_t a[sizeof(simde_v128_t) / sizeof(int16_t)];
      int16_t b[sizeof(simde_v128_t) / sizeof(int16_t)];
      int16_t r[sizeof(simde_v128_t) / sizeof(int16_t)];
    } test_vec[] = {
      { { -INT16_C(  4356), -INT16_C( 20330),  INT16_C( 29657), -INT16_C(  3059),  INT16_C(  7287),  INT16_C( 28401), -INT16_C( 12985),  INT16_C(   436) },
        { -INT16_C(  9912),  INT16_C( 30539),  INT16_C( 25772),  INT16_C( 29791), -INT16_C( 24841),  INT16_C( 27023), -INT16_C( 32102),  INT16_C( 10667) },
        { -INT16_C( 14268),  INT16_C( 10209),       INT16_MAX,  INT16_C( 26732), -INT16_C( 17554),       INT16_MAX,       INT16_MIN,  INT16_C( 11103) } },
      { {  INT16_C(   496), -INT16_C(  2876),  INT16_C(  4600), -INT16_C( 15832), -INT16_C( 29266), -INT16_C( 30549),  INT16_C( 27844),  INT16_C( 21828) },
        { -INT16_C(  5319),  INT16_C( 19801),  INT16_C( 31510), -INT16_C( 29321), -INT16_C( 32530), -INT16_C( 22995),  INT16_C(  9494), -INT16_C(  6323) },
        { -INT16_C(  4823),  INT16_C( 16925),       INT16_MAX,       INT16_MIN,       INT16_MIN,       INT16_MIN,       INT16_MAX,  INT16_C( 15505) } },
      { { -INT16_C( 31503),  INT16_C( 21247),  INT16_C(  3822), -INT16_C( 31148),  INT16_C( 26118),  INT16_C(  9913),  INT16_C( 26646),  INT16_C(  4946) },
        {  INT16_C( 18654),  INT16_C( 11749), -INT16_C( 29476), -INT16_C(  7040),  INT16_C( 10857), -INT16_C(  2509), -INT16_C(  6848), -INT16_C( 25351) },
        { -INT16_C( 12849),       INT16_MAX, -INT16_C( 25654),       INT16_MIN,       INT16_MAX,  INT16_C(  7404),  INT16_C( 19798), -INT16_C( 20405) } },
      { {  INT16_C( 16630), -INT16_C( 27846), -INT16_C( 23373),  INT16_C( 16332), -INT16_C(  7331), -INT16_C( 11726),  INT16_C( 32432), -INT16_C( 20303) },
        {  INT16_C( 17375), -INT16_C(  1869), -INT16_C( 18585),  INT16_C( 19843),  INT16_C(  4772),  INT16_C( 17136),  INT16_C( 29747),  INT16_C( 25403) },
        {       INT16_MAX, -INT16_C( 29715),       INT16_MIN,       INT16_MAX, -INT16_C(  2559),  INT16_C(  5410),       INT16_MAX,  INT16_C(  5100) } },
      { {  INT16_C(  4148),  INT16_C( 14400),  INT16_C( 20962), -INT16_C(  1943),  INT16_C( 28089), -INT16_C( 11480),  INT16_C(  1846),  INT16_C( 18561) },
        { -INT16_C( 20983),  INT16_C( 17785), -INT16_C( 13962),  INT16_C( 22998), -INT16_C( 17397),  INT16_C(  6515), -INT16_C(  1756), -INT16_C( 23220) },
        { -INT16_C( 16835),  INT16_C( 32185),  INT16_C(  7000),  INT16_C( 21055),  INT16_C( 10692), -INT16_C(  4965),  INT16_C(    90), -INT16_C(  4659) } },
      { { -INT16_C( 25023),  INT16_C( 20548), -INT16_C( 28801),  INT16_C(  2912),  INT16_C( 15295), -INT16_C(  8044), -INT16_C( 29531), -INT16_C( 14005) },
        {  INT16_C( 23328), -INT16_C(  3026), -INT16_C( 20825),  INT16_C( 24737),  INT16_C(  6010),  INT16_C( 10303),  INT16_C( 25157), -INT16_C(   527) },
        { -INT16_C(  1695),  INT16_C( 17522),       INT16_MIN,  INT16_C( 27649),  INT16_C( 21305),  INT16_C(  2259), -INT16_C(  4374), -INT16_C( 14532) } },
      { { -INT16_C( 23126), -INT16_C( 10758), -INT16_C(  1975), -INT16_C(  4213),  INT16_C( 27824),  INT16_C( 22993), -INT16_C( 11008), -INT16_C( 27222) },
        {  INT16_C(  7232),  INT16_C( 18916),  INT16_C( 24712),  INT16_C(  2015),  INT16_C( 24054),  INT16_C( 12673),  INT16_C( 13364), -INT16_C( 24607) },
        { -INT16_C( 15894),  INT16_C(  8158),  INT16_C( 22737), -INT16_C(  2198),       INT16_MAX,       INT16_MAX,  INT16_C(  2356),       INT16_MIN } },
      { { -INT16_C( 21745),  INT16_C( 31266),  INT16_C(   382),  INT16_C( 30762), -INT16_C( 21278), -INT16_C(   888),  INT16_C( 30075), -INT16_C( 21145) },
        {  INT16_C( 16054), -INT16_C( 32238),  INT16_C( 22044),  INT16_C( 17380),  INT16_C( 28904),  INT16_C( 32701), -INT16_C( 10778),  INT16_C( 17061) },
        { -INT16_C(  5691), -INT16_C(   972),  INT16_C( 22426),       INT16_MAX,  INT16_C(  7626),  INT16_C( 31813),  INT16_C( 19297), -INT16_C(  4084) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t b = simde_wasm_v128_load(test_vec[i].b);
      simde_v128_t r = simde_wasm_i16x8_add_sat(a, b);
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

      r = simde_wasm_i16x8_add_sat(a, b);

      simde_test_wasm_i16x8_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_i16x8_write(3, b, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_wasm_i16x8_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_u8x16_add_sat(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      uint8_t a[sizeof(simde_v128_t) / sizeof(uint8_t)];
      uint8_t b[sizeof(simde_v128_t) / sizeof(uint8_t)];
      uint8_t r[sizeof(simde_v128_t) / sizeof(uint8_t)];
    } test_vec[] = {
      { { UINT8_C(199), UINT8_C(179), UINT8_C( 47), UINT8_C(167), UINT8_C( 94), UINT8_C( 89), UINT8_C(119), UINT8_C( 74),
          UINT8_C( 36), UINT8_C(244), UINT8_C( 16), UINT8_C( 40), UINT8_C( 63), UINT8_C(155), UINT8_C(180), UINT8_C(130) },
        { UINT8_C( 82), UINT8_C( 69), UINT8_C(236), UINT8_C( 98), UINT8_C( 47), UINT8_C( 55), UINT8_C(211), UINT8_C( 64),
          UINT8_C(129), UINT8_C(153), UINT8_C(238), UINT8_C(238), UINT8_C( 97), UINT8_C(237), UINT8_C(238), UINT8_C( 40) },
        {    UINT8_MAX, UINT8_C(248),    UINT8_MAX,    UINT8_MAX, UINT8_C(141), UINT8_C(144),    UINT8_MAX, UINT8_C(138),
          UINT8_C(165),    UINT8_MAX, UINT8_C(254),    UINT8_MAX, UINT8_C(160),    UINT8_MAX,    UINT8_MAX, UINT8_C(170) } },
      { { UINT8_C(140), UINT8_C( 32), UINT8_C( 86), UINT8_C(134), UINT8_C(196), UINT8_C(162), UINT8_C( 92), UINT8_C(169),
          UINT8_C( 31), UINT8_C(127), UINT8_C(247), UINT8_C(247), UINT8_C( 75), UINT8_C(153), UINT8_C(122), UINT8_C(244) },
        { UINT8_C(247), UINT8_C(199), UINT8_C(170), UINT8_C( 69), UINT8_C(156), UINT8_C(139), UINT8_C(122), UINT8_C(102),
          UINT8_C(187), UINT8_C(109), UINT8_C( 87), UINT8_C( 27), UINT8_C(207), UINT8_C( 72), UINT8_C(132), UINT8_C( 74) },
        {    UINT8_MAX, UINT8_C(231),    UINT8_MAX, UINT8_C(203),    UINT8_MAX,    UINT8_MAX, UINT8_C(214),    UINT8_MAX,
          UINT8_C(218), UINT8_C(236),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(225), UINT8_C(254),    UINT8_MAX } },
      { { UINT8_C( 54), UINT8_C( 69), UINT8_C(173), UINT8_C(115), UINT8_C( 66), UINT8_C(103), UINT8_C(240), UINT8_C(231),
          UINT8_C( 43), UINT8_C(142), UINT8_C(243), UINT8_C( 68), UINT8_C(227), UINT8_C(105), UINT8_C(166), UINT8_C(139) },
        { UINT8_C( 85), UINT8_C(210), UINT8_C(175), UINT8_C(226), UINT8_C(179), UINT8_C(155), UINT8_C( 49), UINT8_C( 58),
          UINT8_C(136), UINT8_C( 97), UINT8_C( 97), UINT8_C(174), UINT8_C(169), UINT8_C(222), UINT8_C( 76), UINT8_C(124) },
        { UINT8_C(139),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(245),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
          UINT8_C(179), UINT8_C(239),    UINT8_MAX, UINT8_C(242),    UINT8_MAX,    UINT8_MAX, UINT8_C(242),    UINT8_MAX } },
      { { UINT8_C( 65), UINT8_C(243), UINT8_C(201), UINT8_C(105), UINT8_C(107), UINT8_C( 78), UINT8_C( 56), UINT8_C(173),
          UINT8_C( 92), UINT8_C(237), UINT8_C(188), UINT8_C(154), UINT8_C(211), UINT8_C(205), UINT8_C(100), UINT8_C(  3) },
        {    UINT8_MAX, UINT8_C(157), UINT8_C(180), UINT8_C( 25), UINT8_C(120), UINT8_C( 17), UINT8_C(110), UINT8_C(125),
          UINT8_C( 55), UINT8_C(172), UINT8_C(230), UINT8_C(231), UINT8_C(216), UINT8_C(  6), UINT8_C(210), UINT8_C(164) },
        {    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(130), UINT8_C(227), UINT8_C( 95), UINT8_C(166),    UINT8_MAX,
          UINT8_C(147),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(211),    UINT8_MAX, UINT8_C(167) } },
      { { UINT8_C( 12), UINT8_C(207), UINT8_C(204), UINT8_C( 38), UINT8_C( 53), UINT8_C(231), UINT8_C( 10), UINT8_C( 14),
          UINT8_C( 72), UINT8_C(188), UINT8_C(168), UINT8_C( 32), UINT8_C(127), UINT8_C(142), UINT8_C( 42), UINT8_C( 89) },
        { UINT8_C(131), UINT8_C( 49), UINT8_C(182), UINT8_C(243), UINT8_C(  9), UINT8_C( 49), UINT8_C(134), UINT8_C( 58),
          UINT8_C( 99), UINT8_C(200), UINT8_C( 65), UINT8_C(119), UINT8_C( 64), UINT8_C(195), UINT8_C( 46), UINT8_C( 49) },
        { UINT8_C(143),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C( 62),    UINT8_MAX, UINT8_C(144), UINT8_C( 72),
          UINT8_C(171),    UINT8_MAX, UINT8_C(233), UINT8_C(151), UINT8_C(191),    UINT8_MAX, UINT8_C( 88), UINT8_C(138) } },
      { { UINT8_C(106), UINT8_C( 44), UINT8_C( 46), UINT8_C(218), UINT8_C(199), UINT8_C(239), UINT8_C(137), UINT8_C( 37),
          UINT8_C(254), UINT8_C( 45), UINT8_C(212), UINT8_C( 41),    UINT8_MAX, UINT8_C(161), UINT8_C(150), UINT8_C( 66) },
        { UINT8_C(192),    UINT8_MAX, UINT8_C(125), UINT8_C( 19), UINT8_C( 33), UINT8_C(226), UINT8_C(231), UINT8_C( 36),
          UINT8_C(169), UINT8_C(231), UINT8_C( 59), UINT8_C(213), UINT8_C(155), UINT8_C(165), UINT8_C(154), UINT8_C( 96) },
        {    UINT8_MAX,    UINT8_MAX, UINT8_C(171), UINT8_C(237), UINT8_C(232),    UINT8_MAX,    UINT8_MAX, UINT8_C( 73),
             UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(254),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(162) } },
      { { UINT8_C(186), UINT8_C( 93), UINT8_C( 13), UINT8_C( 88), UINT8_C(178), UINT8_C( 21), UINT8_C( 29), UINT8_C( 51),
          UINT8_C(118), UINT8_C(177), UINT8_C(204), UINT8_C( 65), UINT8_C(204), UINT8_C(204), UINT8_C(199), UINT8_C( 47) },
        { UINT8_C(184), UINT8_C(246), UINT8_C(173), UINT8_C(168), UINT8_C( 28), UINT8_C( 50), UINT8_C(213), UINT8_C(116),
          UINT8_C(217), UINT8_C(236), UINT8_C(115), UINT8_C(  7), UINT8_C(227), UINT8_C( 50), UINT8_C(147), UINT8_C(247) },
        {    UINT8_MAX,    UINT8_MAX, UINT8_C(186),    UINT8_MAX, UINT8_C(206), UINT8_C( 71), UINT8_C(242), UINT8_C(167),
             UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C( 72),    UINT8_MAX, UINT8_C(254),    UINT8_MAX,    UINT8_MAX } },
      { { UINT8_C(116), UINT8_C(145), UINT8_C(243), UINT8_C(197), UINT8_C(187), UINT8_C( 72), UINT8_C(244), UINT8_C( 64),
          UINT8_C(131), UINT8_C(186), UINT8_C(189), UINT8_C(186), UINT8_C(215), UINT8_C(207), UINT8_C( 59), UINT8_C(204) },
        { UINT8_C(226), UINT8_C( 25), UINT8_C( 74), UINT8_C(215), UINT8_C(118), UINT8_C( 95), UINT8_C(165), UINT8_C( 71),
          UINT8_C(170), UINT8_C(226), UINT8_C( 73), UINT8_C(242), UINT8_C( 47), UINT8_C(206), UINT8_C(108), UINT8_C(133) },
        {    UINT8_MAX, UINT8_C(170),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(167),    UINT8_MAX, UINT8_C(135),
             UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(167),    UINT8_MAX } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t b = simde_wasm_v128_load(test_vec[i].b);
      simde_v128_t r = simde_wasm_u8x16_add_sat(a, b);
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

      r = simde_wasm_u8x16_add_sat(a, b);

      simde_test_wasm_u8x16_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_u8x16_write(3, b, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_wasm_u8x16_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_u16x8_add_sat(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      uint16_t a[sizeof(simde_v128_t) / sizeof(uint16_t)];
      uint16_t b[sizeof(simde_v128_t) / sizeof(uint16_t)];
      uint16_t r[sizeof(simde_v128_t) / sizeof(uint16_t)];
    } test_vec[] = {
      { { UINT16_C(10563), UINT16_C(49955), UINT16_C(30234), UINT16_C(14582), UINT16_C(59724), UINT16_C(49945), UINT16_C( 2616), UINT16_C(64807) },
        { UINT16_C(39420), UINT16_C(44746), UINT16_C(23509), UINT16_C(32883), UINT16_C(61675), UINT16_C(11596), UINT16_C( 8219), UINT16_C( 8819) },
        { UINT16_C(49983),      UINT16_MAX, UINT16_C(53743), UINT16_C(47465),      UINT16_MAX, UINT16_C(61541), UINT16_C(10835),      UINT16_MAX } },
      { { UINT16_C(35473), UINT16_C(10341), UINT16_C(55872), UINT16_C(35910), UINT16_C(51767), UINT16_C(61380), UINT16_C(42566), UINT16_C(23379) },
        { UINT16_C(26978), UINT16_C(37273), UINT16_C(55429), UINT16_C( 9316), UINT16_C(54327), UINT16_C(19748), UINT16_C(64423), UINT16_C(44418) },
        { UINT16_C(62451), UINT16_C(47614),      UINT16_MAX, UINT16_C(45226),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX } },
      { { UINT16_C(31645), UINT16_C( 8784), UINT16_C(48663), UINT16_C(20026), UINT16_C( 2401), UINT16_C(17858), UINT16_C(14659), UINT16_C(14965) },
        { UINT16_C(23007), UINT16_C(10794), UINT16_C(52096), UINT16_C(15967), UINT16_C(55083), UINT16_C(45817), UINT16_C(49822), UINT16_C(35362) },
        { UINT16_C(54652), UINT16_C(19578),      UINT16_MAX, UINT16_C(35993), UINT16_C(57484), UINT16_C(63675), UINT16_C(64481), UINT16_C(50327) } },
      { { UINT16_C(63505), UINT16_C(61972), UINT16_C(50119), UINT16_C(54740), UINT16_C(11153), UINT16_C(54623), UINT16_C(61050), UINT16_C( 8462) },
        { UINT16_C(42748), UINT16_C(55167), UINT16_C(30188), UINT16_C(13635), UINT16_C(17683), UINT16_C(55909), UINT16_C(21363), UINT16_C(58145) },
        {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(28836),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX } },
      { { UINT16_C(35086), UINT16_C( 4294), UINT16_C(43768), UINT16_C(55234), UINT16_C(49576), UINT16_C(49371), UINT16_C(12259), UINT16_C(52160) },
        { UINT16_C( 6874), UINT16_C(39732), UINT16_C(59429), UINT16_C(46504), UINT16_C(25892), UINT16_C(12505), UINT16_C(27818), UINT16_C(26542) },
        { UINT16_C(41960), UINT16_C(44026),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(61876), UINT16_C(40077),      UINT16_MAX } },
      { { UINT16_C( 7623), UINT16_C(58158), UINT16_C(39575), UINT16_C( 2519), UINT16_C( 9623), UINT16_C(51603), UINT16_C(51013), UINT16_C(43567) },
        { UINT16_C(39808), UINT16_C(35339), UINT16_C( 4152), UINT16_C( 2073), UINT16_C(60967), UINT16_C(21899), UINT16_C(37050), UINT16_C(34807) },
        { UINT16_C(47431),      UINT16_MAX, UINT16_C(43727), UINT16_C( 4592),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX } },
      { { UINT16_C(22925), UINT16_C(59658), UINT16_C(58646), UINT16_C(16385), UINT16_C(43985), UINT16_C(26800), UINT16_C(36061), UINT16_C(57176) },
        { UINT16_C(18352), UINT16_C(47606), UINT16_C(15085), UINT16_C(62668), UINT16_C(  436), UINT16_C(63456), UINT16_C(29292), UINT16_C(13887) },
        { UINT16_C(41277),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(44421),      UINT16_MAX, UINT16_C(65353),      UINT16_MAX } },
      { { UINT16_C(30568), UINT16_C(27619), UINT16_C(21297), UINT16_C( 4302), UINT16_C(23357), UINT16_C(21327), UINT16_C(34684), UINT16_C(49005) },
        { UINT16_C( 2362), UINT16_C(44963), UINT16_C( 6213), UINT16_C( 8673), UINT16_C(40415), UINT16_C( 7000), UINT16_C(55747), UINT16_C(10878) },
        { UINT16_C(32930),      UINT16_MAX, UINT16_C(27510), UINT16_C(12975), UINT16_C(63772), UINT16_C(28327),      UINT16_MAX, UINT16_C(59883) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t b = simde_wasm_v128_load(test_vec[i].b);
      simde_v128_t r = simde_wasm_u16x8_add_sat(a, b);
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

      r = simde_wasm_u16x8_add_sat(a, b);

      simde_test_wasm_u16x8_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_u16x8_write(3, b, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_wasm_u16x8_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_i8x16_add_sat)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_i16x8_add_sat)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_u8x16_add_sat)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_u16x8_add_sat)
SIMDE_TEST_FUNC_LIST_END

#include "test-simd128-footer.h"
