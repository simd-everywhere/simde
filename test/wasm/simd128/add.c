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

#define SIMDE_TEST_WASM_SIMD128_INSN add
#include "../../../simde/wasm/simd128.h"
#include "test-simd128.h"

static int
test_simde_wasm_i8x16_add(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      int8_t a[sizeof(simde_v128_t) / sizeof(int8_t)];
      int8_t b[sizeof(simde_v128_t) / sizeof(int8_t)];
      int8_t r[sizeof(simde_v128_t) / sizeof(int8_t)];
    } test_vec[] = {
      { { -INT8_C(  68), -INT8_C(  74),  INT8_C(  97),  INT8_C(  96),  INT8_C(  73), -INT8_C(  11), -INT8_C(  81), -INT8_C( 104),
               INT8_MAX, -INT8_C(  80), -INT8_C(  19),  INT8_C(  99), -INT8_C(  19), -INT8_C(  23), -INT8_C(  44), -INT8_C( 125) },
        { -INT8_C(  71), -INT8_C(  90), -INT8_C(  94),  INT8_C( 108),  INT8_C(  56),  INT8_C(  46), -INT8_C( 127),  INT8_C(  74),
           INT8_C(   9),  INT8_C(  63), -INT8_C(  11),  INT8_C(  39), -INT8_C(  57), -INT8_C(  73),  INT8_C(  27), -INT8_C( 117) },
        {  INT8_C( 117),  INT8_C(  92),  INT8_C(   3), -INT8_C(  52), -INT8_C( 127),  INT8_C(  35),  INT8_C(  48), -INT8_C(  30),
          -INT8_C( 120), -INT8_C(  17), -INT8_C(  30), -INT8_C( 118), -INT8_C(  76), -INT8_C(  96), -INT8_C(  17),  INT8_C(  14) } },
      { {  INT8_C(  39), -INT8_C(  22), -INT8_C(  28), -INT8_C(  72), -INT8_C(  15), -INT8_C(  22), -INT8_C( 114), -INT8_C(  45),
          -INT8_C(  91), -INT8_C(  99),  INT8_C(  86), -INT8_C( 125),  INT8_C(  36),  INT8_C(  87), -INT8_C( 101), -INT8_C(  61) },
        {  INT8_C(  47), -INT8_C(  55),  INT8_C(  31), -INT8_C(  65), -INT8_C(  76),  INT8_C(  33), -INT8_C(  56),  INT8_C( 116),
          -INT8_C(  71),  INT8_C(  70),  INT8_C(  34),  INT8_C(  45),  INT8_C(  41), -INT8_C(  14), -INT8_C(  97), -INT8_C(  16) },
        {  INT8_C(  86), -INT8_C(  77),  INT8_C(   3),  INT8_C( 119), -INT8_C(  91),  INT8_C(  11),  INT8_C(  86),  INT8_C(  71),
           INT8_C(  94), -INT8_C(  29),  INT8_C( 120), -INT8_C(  80),  INT8_C(  77),  INT8_C(  73),  INT8_C(  58), -INT8_C(  77) } },
      { {  INT8_C(  96), -INT8_C(  12),  INT8_C(  49),  INT8_C(  78), -INT8_C( 107), -INT8_C(  11),  INT8_C(  31),  INT8_C( 116),
           INT8_C(  54), -INT8_C( 110), -INT8_C(  11),  INT8_C(  46), -INT8_C(  64),  INT8_C( 125), -INT8_C(  73),  INT8_C(  22) },
        {  INT8_C( 117),  INT8_C(  71),  INT8_C(  59), -INT8_C(  50),  INT8_C( 114), -INT8_C( 115),  INT8_C( 126),  INT8_C(  72),
           INT8_C(  10),  INT8_C(  31), -INT8_C(  83),  INT8_C(  37),  INT8_C( 100), -INT8_C(  86), -INT8_C(  65), -INT8_C( 122) },
        { -INT8_C(  43),  INT8_C(  59),  INT8_C( 108),  INT8_C(  28),  INT8_C(   7), -INT8_C( 126), -INT8_C(  99), -INT8_C(  68),
           INT8_C(  64), -INT8_C(  79), -INT8_C(  94),  INT8_C(  83),  INT8_C(  36),  INT8_C(  39),  INT8_C( 118), -INT8_C( 100) } },
      { { -INT8_C(  52), -INT8_C(  72),  INT8_C(  22),  INT8_C(  96), -INT8_C(  19), -INT8_C(   9),  INT8_C(  65),  INT8_C( 118),
          -INT8_C(  11),  INT8_C(  36), -INT8_C(   7),  INT8_C(  42), -INT8_C(  89), -INT8_C(  90),  INT8_C(  39),  INT8_C( 121) },
        {  INT8_C(   0), -INT8_C(  13),  INT8_C(  91),  INT8_C( 100), -INT8_C(  25), -INT8_C(  95), -INT8_C(  99), -INT8_C(  64),
           INT8_C(  70),  INT8_C(  53),  INT8_C(  62), -INT8_C(  51),  INT8_C(   5),  INT8_C(  33), -INT8_C(  34), -INT8_C(  93) },
        { -INT8_C(  52), -INT8_C(  85),  INT8_C( 113), -INT8_C(  60), -INT8_C(  44), -INT8_C( 104), -INT8_C(  34),  INT8_C(  54),
           INT8_C(  59),  INT8_C(  89),  INT8_C(  55), -INT8_C(   9), -INT8_C(  84), -INT8_C(  57),  INT8_C(   5),  INT8_C(  28) } },
      { {  INT8_C(  40),  INT8_C(  35), -INT8_C( 126), -INT8_C(  45),  INT8_C(   8), -INT8_C(  40), -INT8_C( 122),  INT8_C(   2),
          -INT8_C(   4), -INT8_C(  10),  INT8_C(  79), -INT8_C(  75),  INT8_C( 126),  INT8_C(  41), -INT8_C( 120),  INT8_C(  65) },
        {  INT8_C(  56),  INT8_C( 110), -INT8_C( 105),  INT8_C(   3), -INT8_C(  55), -INT8_C(  43),  INT8_C( 126),  INT8_C(  84),
          -INT8_C(  47),  INT8_C(  59),  INT8_C( 126),  INT8_C(  92),  INT8_C( 114),  INT8_C(  80),  INT8_C(  87),  INT8_C(  48) },
        {  INT8_C(  96), -INT8_C( 111),  INT8_C(  25), -INT8_C(  42), -INT8_C(  47), -INT8_C(  83),  INT8_C(   4),  INT8_C(  86),
          -INT8_C(  51),  INT8_C(  49), -INT8_C(  51),  INT8_C(  17), -INT8_C(  16),  INT8_C( 121), -INT8_C(  33),  INT8_C( 113) } },
      { {  INT8_C(  20), -INT8_C( 103),  INT8_C(   5),  INT8_C(  59), -INT8_C( 124), -INT8_C(  29), -INT8_C(  24), -INT8_C(  24),
          -INT8_C(  89),  INT8_C(  16), -INT8_C( 126),  INT8_C( 106),  INT8_C(  70), -INT8_C(  94),  INT8_C(  39),  INT8_C( 116) },
        { -INT8_C(  70),  INT8_C(  92), -INT8_C(   7), -INT8_C(  78),  INT8_C(  14),  INT8_C(   4),  INT8_C(  71),  INT8_C(  43),
          -INT8_C(  38),  INT8_C(  60), -INT8_C(  77),  INT8_C(  42),  INT8_C(  77), -INT8_C(  23),  INT8_C(  75), -INT8_C(  57) },
        { -INT8_C(  50), -INT8_C(  11), -INT8_C(   2), -INT8_C(  19), -INT8_C( 110), -INT8_C(  25),  INT8_C(  47),  INT8_C(  19),
          -INT8_C( 127),  INT8_C(  76),  INT8_C(  53), -INT8_C( 108), -INT8_C( 109), -INT8_C( 117),  INT8_C( 114),  INT8_C(  59) } },
      { {  INT8_C(  32), -INT8_C(  25), -INT8_C(  42),  INT8_C(  99),  INT8_C(  76), -INT8_C(  84), -INT8_C(   7), -INT8_C( 103),
          -INT8_C(   1), -INT8_C(  90),  INT8_C(  31), -INT8_C(  90),  INT8_C( 118), -INT8_C(  71), -INT8_C( 112), -INT8_C(  95) },
        {  INT8_C(  42),  INT8_C(  15),  INT8_C(  69),  INT8_C(  66),  INT8_C(  98),  INT8_C(  13), -INT8_C(  29), -INT8_C(  37),
          -INT8_C( 127),  INT8_C(  43), -INT8_C(  21), -INT8_C(  43),  INT8_C(  71), -INT8_C(  42), -INT8_C(   8),  INT8_C(  65) },
        {  INT8_C(  74), -INT8_C(  10),  INT8_C(  27), -INT8_C(  91), -INT8_C(  82), -INT8_C(  71), -INT8_C(  36),  INT8_C( 116),
               INT8_MIN, -INT8_C(  47),  INT8_C(  10),  INT8_C( 123), -INT8_C(  67), -INT8_C( 113), -INT8_C( 120), -INT8_C(  30) } },
      { {  INT8_C(  84), -INT8_C(  80),  INT8_C(  86),  INT8_C(  82), -INT8_C(  49),  INT8_C( 103), -INT8_C( 103), -INT8_C( 103),
          -INT8_C(  89),  INT8_C( 106), -INT8_C( 102),  INT8_C( 115), -INT8_C( 107),  INT8_C(  92), -INT8_C(  88),  INT8_C(  51) },
        {  INT8_C( 120), -INT8_C(  72),  INT8_C(  57),  INT8_C(  20),  INT8_C(  37), -INT8_C(  14),  INT8_C( 115), -INT8_C( 108),
          -INT8_C( 125), -INT8_C(  16), -INT8_C( 103), -INT8_C(  21), -INT8_C( 124),  INT8_C(  58), -INT8_C( 115), -INT8_C(  44) },
        { -INT8_C(  52),  INT8_C( 104), -INT8_C( 113),  INT8_C( 102), -INT8_C(  12),  INT8_C(  89),  INT8_C(  12),  INT8_C(  45),
           INT8_C(  42),  INT8_C(  90),  INT8_C(  51),  INT8_C(  94),  INT8_C(  25), -INT8_C( 106),  INT8_C(  53),  INT8_C(   7) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t b = simde_wasm_v128_load(test_vec[i].b);
      simde_v128_t r = simde_wasm_i8x16_add(a, b);
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

      r = simde_wasm_i8x16_add(a, b);

      simde_test_wasm_i8x16_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_i8x16_write(3, b, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_wasm_i8x16_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_i16x8_add(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      int16_t a[sizeof(simde_v128_t) / sizeof(int16_t)];
      int16_t b[sizeof(simde_v128_t) / sizeof(int16_t)];
      int16_t r[sizeof(simde_v128_t) / sizeof(int16_t)];
    } test_vec[] = {
      { {  INT16_C( 24126), -INT16_C( 10736), -INT16_C( 13381),  INT16_C( 30501),  INT16_C( 24131), -INT16_C(  4944),  INT16_C( 32084),  INT16_C( 20537) },
        {  INT16_C(  4785),  INT16_C( 24912),  INT16_C( 30951), -INT16_C(  7361), -INT16_C(  1944),  INT16_C(  4283), -INT16_C(  5779), -INT16_C( 22923) },
        {  INT16_C( 28911),  INT16_C( 14176),  INT16_C( 17570),  INT16_C( 23140),  INT16_C( 22187), -INT16_C(   661),  INT16_C( 26305), -INT16_C(  2386) } },
      { { -INT16_C( 29062), -INT16_C( 31425),  INT16_C( 29247),  INT16_C( 18223),  INT16_C(  8039),  INT16_C(  9800),  INT16_C( 22319),  INT16_C(  9481) },
        { -INT16_C( 26300),  INT16_C(     5),  INT16_C( 17504), -INT16_C(  7635),  INT16_C( 16939), -INT16_C( 24196),  INT16_C( 28433), -INT16_C(  6602) },
        {  INT16_C( 10174), -INT16_C( 31420), -INT16_C( 18785),  INT16_C( 10588),  INT16_C( 24978), -INT16_C( 14396), -INT16_C( 14784),  INT16_C(  2879) } },
      { { -INT16_C(    64),  INT16_C( 18897), -INT16_C( 19268), -INT16_C( 26965), -INT16_C( 19456), -INT16_C( 27174),  INT16_C(  9854), -INT16_C( 14484) },
        {  INT16_C( 12244), -INT16_C( 20329),  INT16_C( 31724), -INT16_C(  4176), -INT16_C(  3228), -INT16_C(  7336), -INT16_C( 29442),  INT16_C( 25528) },
        {  INT16_C( 12180), -INT16_C(  1432),  INT16_C( 12456), -INT16_C( 31141), -INT16_C( 22684),  INT16_C( 31026), -INT16_C( 19588),  INT16_C( 11044) } },
      { {  INT16_C(  1901),  INT16_C( 26086),  INT16_C(  2824), -INT16_C(  6742), -INT16_C(  8130), -INT16_C(  2738),  INT16_C( 27419), -INT16_C( 31399) },
        {  INT16_C( 21626), -INT16_C(  9908), -INT16_C(  7801), -INT16_C(  6595),  INT16_C( 24823), -INT16_C( 23620),  INT16_C( 12700), -INT16_C( 24287) },
        {  INT16_C( 23527),  INT16_C( 16178), -INT16_C(  4977), -INT16_C( 13337),  INT16_C( 16693), -INT16_C( 26358), -INT16_C( 25417),  INT16_C(  9850) } },
      { {  INT16_C( 31373), -INT16_C(   808), -INT16_C(  4828), -INT16_C( 26493), -INT16_C(  4351), -INT16_C( 20895), -INT16_C( 22411), -INT16_C( 16392) },
        { -INT16_C( 12646), -INT16_C(  9678),  INT16_C( 31048), -INT16_C( 10433), -INT16_C( 24772),  INT16_C( 24366),  INT16_C(   264),  INT16_C( 28963) },
        {  INT16_C( 18727), -INT16_C( 10486),  INT16_C( 26220),  INT16_C( 28610), -INT16_C( 29123),  INT16_C(  3471), -INT16_C( 22147),  INT16_C( 12571) } },
      { {  INT16_C(  7530),  INT16_C(  6590),  INT16_C( 11899),  INT16_C( 30351),  INT16_C(  1477), -INT16_C( 16504), -INT16_C( 24020),  INT16_C( 16057) },
        { -INT16_C(  8666), -INT16_C( 13212), -INT16_C( 24486),  INT16_C( 15497), -INT16_C( 27221), -INT16_C(  4117),  INT16_C( 20592),  INT16_C(  3026) },
        { -INT16_C(  1136), -INT16_C(  6622), -INT16_C( 12587), -INT16_C( 19688), -INT16_C( 25744), -INT16_C( 20621), -INT16_C(  3428),  INT16_C( 19083) } },
      { { -INT16_C( 26989),  INT16_C( 13416), -INT16_C(  7784), -INT16_C( 25513), -INT16_C(  5112),  INT16_C(  8787),  INT16_C(  6961),  INT16_C(  3048) },
        { -INT16_C(  5780), -INT16_C( 13873), -INT16_C( 19846), -INT16_C( 20409), -INT16_C( 30971), -INT16_C( 21746), -INT16_C( 23828), -INT16_C( 24332) },
        {       INT16_MAX, -INT16_C(   457), -INT16_C( 27630),  INT16_C( 19614),  INT16_C( 29453), -INT16_C( 12959), -INT16_C( 16867), -INT16_C( 21284) } },
      { { -INT16_C( 10391),  INT16_C( 15083), -INT16_C( 20122), -INT16_C(  3766),  INT16_C( 26684), -INT16_C( 19376),  INT16_C(  6236), -INT16_C( 14404) },
        { -INT16_C( 21405), -INT16_C( 19090),  INT16_C(  9454),  INT16_C( 10612),  INT16_C( 10244),  INT16_C(  3631), -INT16_C( 22053),  INT16_C( 30167) },
        { -INT16_C( 31796), -INT16_C(  4007), -INT16_C( 10668),  INT16_C(  6846), -INT16_C( 28608), -INT16_C( 15745), -INT16_C( 15817),  INT16_C( 15763) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t b = simde_wasm_v128_load(test_vec[i].b);
      simde_v128_t r = simde_wasm_i16x8_add(a, b);
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

      r = simde_wasm_i16x8_add(a, b);

      simde_test_wasm_i16x8_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_i16x8_write(3, b, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_wasm_i16x8_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_i32x4_add(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      int32_t a[sizeof(simde_v128_t) / sizeof(int32_t)];
      int32_t b[sizeof(simde_v128_t) / sizeof(int32_t)];
      int32_t r[sizeof(simde_v128_t) / sizeof(int32_t)];
    } test_vec[] = {
      { {  INT32_C(   396235817),  INT32_C(   619431656), -INT32_C(  1653866966),  INT32_C(  2129435017) },
        { -INT32_C(  2129270414), -INT32_C(  1446238458), -INT32_C(   443799680),  INT32_C(  1973601724) },
        { -INT32_C(  1733034597), -INT32_C(   826806802), -INT32_C(  2097666646), -INT32_C(   191930555) } },
      { { -INT32_C(  1197463175),  INT32_C(   512368503),  INT32_C(   903367397),  INT32_C(    96853554) },
        { -INT32_C(   139487554),  INT32_C(  2067776272), -INT32_C(   274448609),  INT32_C(  1344734092) },
        { -INT32_C(  1336950729), -INT32_C(  1714822521),  INT32_C(   628918788),  INT32_C(  1441587646) } },
      { { -INT32_C(  1814392977), -INT32_C(   143362697),  INT32_C(  1836043055), -INT32_C(   894099316) },
        {  INT32_C(      166900), -INT32_C(   370968360),  INT32_C(   106940027),  INT32_C(   188455837) },
        { -INT32_C(  1814226077), -INT32_C(   514331057),  INT32_C(  1942983082), -INT32_C(   705643479) } },
      { { -INT32_C(  1283339743),  INT32_C(  1957075098), -INT32_C(  1282330265),  INT32_C(   761910558) },
        {  INT32_C(  1744090003),  INT32_C(  1835556513), -INT32_C(   927679534),  INT32_C(   428077557) },
        {  INT32_C(   460750260), -INT32_C(   502335685),  INT32_C(  2084957497),  INT32_C(  1189988115) } },
      { {  INT32_C(   941250989), -INT32_C(   100642669),  INT32_C(  1552756725),  INT32_C(  1532260067) },
        {  INT32_C(   592100027),  INT32_C(  1913373346), -INT32_C(  1128048849), -INT32_C(   204861402) },
        {  INT32_C(  1533351016),  INT32_C(  1812730677),  INT32_C(   424707876),  INT32_C(  1327398665) } },
      { {  INT32_C(  1644044738),  INT32_C(    33077081), -INT32_C(  1937455312), -INT32_C(  1613851429) },
        {  INT32_C(   552680561), -INT32_C(  2130032644), -INT32_C(   108979694),  INT32_C(   785690538) },
        { -INT32_C(  2098241997), -INT32_C(  2096955563), -INT32_C(  2046435006), -INT32_C(   828160891) } },
      { {  INT32_C(   391864242),  INT32_C(   365895643), -INT32_C(  1748690225),  INT32_C(  1067312946) },
        { -INT32_C(  2118421648),  INT32_C(     9667387),  INT32_C(  1322605473),  INT32_C(   330345408) },
        { -INT32_C(  1726557406),  INT32_C(   375563030), -INT32_C(   426084752),  INT32_C(  1397658354) } },
      { { -INT32_C(   306636811),  INT32_C(  1111583549), -INT32_C(   256394545), -INT32_C(   871546161) },
        {  INT32_C(  1839491700),  INT32_C(  1681727310), -INT32_C(   381724849), -INT32_C(  1265825853) },
        {  INT32_C(  1532854889), -INT32_C(  1501656437), -INT32_C(   638119394), -INT32_C(  2137372014) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t b = simde_wasm_v128_load(test_vec[i].b);
      simde_v128_t r = simde_wasm_i32x4_add(a, b);
      simde_test_wasm_i32x4_assert_equal(r, simde_wasm_v128_load(test_vec[i].r));
    }
    return 0;
  #else
    fputc('\n', stdout);
    for (int i = 0 ; i < 8 ; i++) {
      simde_v128_t
        a = simde_test_wasm_i32x4_random(),
        b = simde_test_wasm_i32x4_random(),
        r;

      r = simde_wasm_i32x4_add(a, b);

      simde_test_wasm_i32x4_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_i32x4_write(3, b, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_wasm_i32x4_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_i64x2_add(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      int64_t a[sizeof(simde_v128_t) / sizeof(int64_t)];
      int64_t b[sizeof(simde_v128_t) / sizeof(int64_t)];
      int64_t r[sizeof(simde_v128_t) / sizeof(int64_t)];
    } test_vec[] = {
      { {  INT64_C( 1421432795418002488), -INT64_C(   35059613854632990) },
        { -INT64_C( 1587670591327459842), -INT64_C( 8643977751088873466) },
        { -INT64_C(  166237795909457354), -INT64_C( 8679037364943506456) } },
      { {  INT64_C(  362216712560641258),  INT64_C( 1121249418286047064) },
        { -INT64_C( 3712736312517765206),  INT64_C( 8722111527191366614) },
        { -INT64_C( 3350519599957123948), -INT64_C( 8603383128232137938) } },
      { {  INT64_C( 9190716711900612416), -INT64_C( 8827805768999373942) },
        { -INT64_C(  198590232969736721), -INT64_C( 8859230087935049444) },
        {  INT64_C( 8992126478930875695),  INT64_C(  759708216775128230) } },
      { {  INT64_C( 5472790330650362825), -INT64_C( 7679432859515302203) },
        {  INT64_C( 6553271854914461553), -INT64_C( 3606092178419610833) },
        { -INT64_C( 6420681888144727238),  INT64_C( 7161219035774638580) } },
      { { -INT64_C( 8618061954933170573), -INT64_C(  728987321275315531) },
        {  INT64_C( 7232883759995296972),  INT64_C( 3631608069055628429) },
        { -INT64_C( 1385178194937873601),  INT64_C( 2902620747780312898) } },
      { {  INT64_C( 2898302643666509078),  INT64_C( 3879138311199737427) },
        {  INT64_C( 8715733422227619545),  INT64_C( 7464705151146903681) },
        { -INT64_C( 6832708007815422993), -INT64_C( 7102900611362910508) } },
      { { -INT64_C( 2440500578436507774), -INT64_C( 7760976302905639864) },
        { -INT64_C( 9033970310584020352), -INT64_C( 8241801871109701550) },
        {  INT64_C( 6972273184689023490),  INT64_C( 2443965899694210202) } },
      { { -INT64_C( 6923260011562639095),  INT64_C( 6297317522825775587) },
        {  INT64_C( 4202739471024861184),  INT64_C( 5065979630868804332) },
        { -INT64_C( 2720520540537777911), -INT64_C( 7083446920014971697) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t b = simde_wasm_v128_load(test_vec[i].b);
      simde_v128_t r = simde_wasm_i64x2_add(a, b);
      simde_test_wasm_i64x2_assert_equal(r, simde_wasm_v128_load(test_vec[i].r));
    }
    return 0;
  #else
    fputc('\n', stdout);
    for (int i = 0 ; i < 8 ; i++) {
      simde_v128_t
        a = simde_test_wasm_i64x2_random(),
        b = simde_test_wasm_i64x2_random(),
        r;

      r = simde_wasm_i64x2_add(a, b);

      simde_test_wasm_i64x2_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_i64x2_write(3, b, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_wasm_i64x2_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_f32x4_add(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      simde_float32 a[sizeof(simde_v128_t) / sizeof(simde_float32)];
      simde_float32 b[sizeof(simde_v128_t) / sizeof(simde_float32)];
      simde_float32 r[sizeof(simde_v128_t) / sizeof(simde_float32)];
    } test_vec[] = {
      #if !defined(SIMDE_FAST_MATH)
      { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   993.46),            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -477.08) },
        { SIMDE_FLOAT32_C(     0.59),            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -477.08) },
        {            SIMDE_MATH_NANF,            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -954.16) } },
      #endif
      { { SIMDE_FLOAT32_C(  -518.32), SIMDE_FLOAT32_C(   215.67), SIMDE_FLOAT32_C(   503.08), SIMDE_FLOAT32_C(  -767.36) },
        { SIMDE_FLOAT32_C(   971.43), SIMDE_FLOAT32_C(   966.48), SIMDE_FLOAT32_C(    -6.84), SIMDE_FLOAT32_C(  -689.91) },
        { SIMDE_FLOAT32_C(   453.11), SIMDE_FLOAT32_C(  1182.15), SIMDE_FLOAT32_C(   496.24), SIMDE_FLOAT32_C( -1457.27) } },
      { { SIMDE_FLOAT32_C(   855.86), SIMDE_FLOAT32_C(  -378.89), SIMDE_FLOAT32_C(  -567.83), SIMDE_FLOAT32_C(  -365.81) },
        { SIMDE_FLOAT32_C(   389.10), SIMDE_FLOAT32_C(   623.57), SIMDE_FLOAT32_C(   629.23), SIMDE_FLOAT32_C(    -7.13) },
        { SIMDE_FLOAT32_C(  1244.96), SIMDE_FLOAT32_C(   244.68), SIMDE_FLOAT32_C(    61.40), SIMDE_FLOAT32_C(  -372.94) } },
      { { SIMDE_FLOAT32_C(   814.88), SIMDE_FLOAT32_C(  -333.75), SIMDE_FLOAT32_C(   -59.20), SIMDE_FLOAT32_C(  -829.05) },
        { SIMDE_FLOAT32_C(   295.61), SIMDE_FLOAT32_C(   530.94), SIMDE_FLOAT32_C(  -725.82), SIMDE_FLOAT32_C(    29.97) },
        { SIMDE_FLOAT32_C(  1110.49), SIMDE_FLOAT32_C(   197.19), SIMDE_FLOAT32_C(  -785.02), SIMDE_FLOAT32_C(  -799.08) } },
      { { SIMDE_FLOAT32_C(  -502.99), SIMDE_FLOAT32_C(   538.99), SIMDE_FLOAT32_C(  -576.55), SIMDE_FLOAT32_C(  -624.40) },
        { SIMDE_FLOAT32_C(  -724.75), SIMDE_FLOAT32_C(  -586.37), SIMDE_FLOAT32_C(   898.20), SIMDE_FLOAT32_C(  -104.73) },
        { SIMDE_FLOAT32_C( -1227.74), SIMDE_FLOAT32_C(   -47.38), SIMDE_FLOAT32_C(   321.65), SIMDE_FLOAT32_C(  -729.13) } },
      { { SIMDE_FLOAT32_C(  -139.75), SIMDE_FLOAT32_C(   908.56), SIMDE_FLOAT32_C(  -109.46), SIMDE_FLOAT32_C(  -557.20) },
        { SIMDE_FLOAT32_C(  -704.36), SIMDE_FLOAT32_C(   -80.47), SIMDE_FLOAT32_C(   159.89), SIMDE_FLOAT32_C(   847.65) },
        { SIMDE_FLOAT32_C(  -844.11), SIMDE_FLOAT32_C(   828.09), SIMDE_FLOAT32_C(    50.43), SIMDE_FLOAT32_C(   290.45) } },
      { { SIMDE_FLOAT32_C(   901.23), SIMDE_FLOAT32_C(  -334.46), SIMDE_FLOAT32_C(   340.10), SIMDE_FLOAT32_C(  -832.57) },
        { SIMDE_FLOAT32_C(  -645.51), SIMDE_FLOAT32_C(  -690.61), SIMDE_FLOAT32_C(    31.67), SIMDE_FLOAT32_C(   425.41) },
        { SIMDE_FLOAT32_C(   255.72), SIMDE_FLOAT32_C( -1025.07), SIMDE_FLOAT32_C(   371.77), SIMDE_FLOAT32_C(  -407.16) } },
      { { SIMDE_FLOAT32_C(   836.67), SIMDE_FLOAT32_C(   488.81), SIMDE_FLOAT32_C(  -988.34), SIMDE_FLOAT32_C(  -242.63) },
        { SIMDE_FLOAT32_C(  -798.93), SIMDE_FLOAT32_C(   -42.42), SIMDE_FLOAT32_C(  -763.68), SIMDE_FLOAT32_C(   877.24) },
        { SIMDE_FLOAT32_C(    37.74), SIMDE_FLOAT32_C(   446.39), SIMDE_FLOAT32_C( -1752.02), SIMDE_FLOAT32_C(   634.61) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t b = simde_wasm_v128_load(test_vec[i].b);
      simde_v128_t r = simde_wasm_f32x4_add(a, b);
      simde_test_wasm_f32x4_assert_equal(r, simde_wasm_v128_load(test_vec[i].r), 1);
    }
    return 0;
  #else
    fputc('\n', stdout);
    simde_float32 inputs[8 * 2 * (sizeof(simde_v128_t) / sizeof(simde_float32))];
    simde_test_wasm_f32x4_random_full(8, 2, inputs, -SIMDE_FLOAT32_C(1000.0), SIMDE_FLOAT32_C(1000.0), HEDLEY_STATIC_CAST(SimdeTestVecFloatType, SIMDE_TEST_VEC_FLOAT_NAN | SIMDE_TEST_VEC_FLOAT_EQUAL));
    for (size_t i = 0 ; i < 8 ; i++) {
      simde_v128_t
        a = simde_test_wasm_f32x4_random_full_extract(2, inputs, i, 0),
        b = simde_test_wasm_f32x4_random_full_extract(2, inputs, i, 1),
        r;

      r = simde_wasm_f32x4_add(a, b);

      simde_test_wasm_f32x4_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_f32x4_write(3, b, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_wasm_f32x4_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_f64x2_add(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      simde_float64 a[sizeof(simde_v128_t) / sizeof(simde_float64)];
      simde_float64 b[sizeof(simde_v128_t) / sizeof(simde_float64)];
      simde_float64 r[sizeof(simde_v128_t) / sizeof(simde_float64)];
    } test_vec[] = {
      #if !defined(SIMDE_FAST_MATH)
      { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   814.01) },
        { SIMDE_FLOAT64_C(  -481.60),             SIMDE_MATH_NAN },
        {             SIMDE_MATH_NAN,             SIMDE_MATH_NAN } },
      { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -506.87) },
        {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(    47.77) },
        {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -459.10) } },
      #endif
      { { SIMDE_FLOAT64_C(  -994.04), SIMDE_FLOAT64_C(  -826.02) },
        { SIMDE_FLOAT64_C(  -342.96), SIMDE_FLOAT64_C(   578.45) },
        { SIMDE_FLOAT64_C( -1337.00), SIMDE_FLOAT64_C(  -247.57) } },
      { { SIMDE_FLOAT64_C(  -126.68), SIMDE_FLOAT64_C(  -955.81) },
        { SIMDE_FLOAT64_C(  -935.86), SIMDE_FLOAT64_C(  -172.68) },
        { SIMDE_FLOAT64_C( -1062.54), SIMDE_FLOAT64_C( -1128.49) } },
      { { SIMDE_FLOAT64_C(  -562.76), SIMDE_FLOAT64_C(  -324.44) },
        { SIMDE_FLOAT64_C(   400.77), SIMDE_FLOAT64_C(  -883.22) },
        { SIMDE_FLOAT64_C(  -161.99), SIMDE_FLOAT64_C( -1207.66) } },
      { { SIMDE_FLOAT64_C(   417.63), SIMDE_FLOAT64_C(    45.66) },
        { SIMDE_FLOAT64_C(  -587.78), SIMDE_FLOAT64_C(   942.86) },
        { SIMDE_FLOAT64_C(  -170.15), SIMDE_FLOAT64_C(   988.52) } },
      { { SIMDE_FLOAT64_C(  -299.96), SIMDE_FLOAT64_C(  -839.59) },
        { SIMDE_FLOAT64_C(  -146.77), SIMDE_FLOAT64_C(  -338.73) },
        { SIMDE_FLOAT64_C(  -446.73), SIMDE_FLOAT64_C( -1178.32) } },
      { { SIMDE_FLOAT64_C(   732.95), SIMDE_FLOAT64_C(   938.78) },
        { SIMDE_FLOAT64_C(  -352.55), SIMDE_FLOAT64_C(   492.68) },
        { SIMDE_FLOAT64_C(   380.40), SIMDE_FLOAT64_C(  1431.46) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t b = simde_wasm_v128_load(test_vec[i].b);
      simde_v128_t r = simde_wasm_f64x2_add(a, b);
      simde_test_wasm_f64x2_assert_equal(r, simde_wasm_v128_load(test_vec[i].r), 1);
    }
    return 0;
  #else
    fputc('\n', stdout);
    simde_float64 inputs[8 * 2 * (sizeof(simde_v128_t) / sizeof(simde_float64))];
    simde_test_wasm_f64x2_random_full(8, 2, inputs, -SIMDE_FLOAT64_C(1000.0), SIMDE_FLOAT64_C(1000.0), HEDLEY_STATIC_CAST(SimdeTestVecFloatType, SIMDE_TEST_VEC_FLOAT_NAN));
    for (size_t i = 0 ; i < 8 ; i++) {
      simde_v128_t
        a = simde_test_wasm_f64x2_random_full_extract(2, inputs, i, 0),
        b = simde_test_wasm_f64x2_random_full_extract(2, inputs, i, 1),
        r;

      r = simde_wasm_f64x2_add(a, b);

      simde_test_wasm_f64x2_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_f64x2_write(3, b, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_wasm_f64x2_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_i8x16_add)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_i16x8_add)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_i32x4_add)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_i64x2_add)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_i64x2_add)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_f32x4_add)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_f64x2_add)
SIMDE_TEST_FUNC_LIST_END

#include "test-simd128-footer.h"
