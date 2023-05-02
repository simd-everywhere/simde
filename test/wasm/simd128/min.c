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

#define SIMDE_TEST_WASM_SIMD128_INSN min
#include "../../../simde/wasm/simd128.h"
#include "test-simd128.h"

static int
test_simde_wasm_i8x16_min(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      int8_t a[sizeof(simde_v128_t) / sizeof(int8_t)];
      int8_t b[sizeof(simde_v128_t) / sizeof(int8_t)];
      int8_t r[sizeof(simde_v128_t) / sizeof(int8_t)];
    } test_vec[] = {
      { { -INT8_C(  37), -INT8_C(  51), -INT8_C( 121), -INT8_C(   3),  INT8_C(  60),  INT8_C(  71), -INT8_C(  90),  INT8_C(  39),
           INT8_C(  36), -INT8_C(  32), -INT8_C(  39),  INT8_C(  93), -INT8_C( 107), -INT8_C(  79),  INT8_C(  49), -INT8_C(  10) },
        { -INT8_C(  62), -INT8_C(  97), -INT8_C(  19),  INT8_C(  64), -INT8_C(  95),  INT8_C( 123), -INT8_C(  45),  INT8_C(  22),
           INT8_C(  70), -INT8_C(  44), -INT8_C( 123),  INT8_C(  55), -INT8_C(  54), -INT8_C(  51), -INT8_C(  52), -INT8_C(  95) },
        { -INT8_C(  62), -INT8_C(  97), -INT8_C( 121), -INT8_C(   3), -INT8_C(  95),  INT8_C(  71), -INT8_C(  90),  INT8_C(  22),
           INT8_C(  36), -INT8_C(  44), -INT8_C( 123),  INT8_C(  55), -INT8_C( 107), -INT8_C(  79), -INT8_C(  52), -INT8_C(  95) } },
      { {  INT8_C( 115), -INT8_C(  21),  INT8_C(  47), -INT8_C(  16),  INT8_C(  54), -INT8_C( 104),  INT8_C(  54), -INT8_C(  40),
           INT8_C(  71),  INT8_C( 111), -INT8_C(  90), -INT8_C(  77),  INT8_C( 118), -INT8_C(  28),  INT8_C( 116),  INT8_C(  75) },
        { -INT8_C(  18), -INT8_C( 115),  INT8_C( 106), -INT8_C( 107),  INT8_C(  17), -INT8_C(  50), -INT8_C(  73), -INT8_C(  77),
          -INT8_C(  56),  INT8_C( 106),      INT8_MIN, -INT8_C( 122),  INT8_C(  69),  INT8_C( 106),  INT8_C(  97),      INT8_MAX },
        { -INT8_C(  18), -INT8_C( 115),  INT8_C(  47), -INT8_C( 107),  INT8_C(  17), -INT8_C( 104), -INT8_C(  73), -INT8_C(  77),
          -INT8_C(  56),  INT8_C( 106),      INT8_MIN, -INT8_C( 122),  INT8_C(  69), -INT8_C(  28),  INT8_C(  97),  INT8_C(  75) } },
      { {  INT8_C(  49), -INT8_C(  17), -INT8_C(  74),  INT8_C(  49), -INT8_C(  26), -INT8_C(  85),  INT8_C(  54),  INT8_C(  10),
           INT8_C(  21), -INT8_C( 109),  INT8_C(  54), -INT8_C( 118), -INT8_C( 120),  INT8_C(  61), -INT8_C(  40),  INT8_C(  74) },
        { -INT8_C( 100), -INT8_C( 117),  INT8_C( 111), -INT8_C(  43),  INT8_C( 122),  INT8_C(  44),  INT8_C(  79), -INT8_C(  91),
          -INT8_C(  53), -INT8_C(  88), -INT8_C(  46), -INT8_C(  69), -INT8_C(  99),  INT8_C(  16), -INT8_C(  51),  INT8_C( 113) },
        { -INT8_C( 100), -INT8_C( 117), -INT8_C(  74), -INT8_C(  43), -INT8_C(  26), -INT8_C(  85),  INT8_C(  54), -INT8_C(  91),
          -INT8_C(  53), -INT8_C( 109), -INT8_C(  46), -INT8_C( 118), -INT8_C( 120),  INT8_C(  16), -INT8_C(  51),  INT8_C(  74) } },
      { {  INT8_C(  45),  INT8_C(   6),  INT8_C(  84), -INT8_C(  13),  INT8_C(  81),  INT8_C(  82),  INT8_C(  57), -INT8_C(  85),
           INT8_C(   8), -INT8_C( 104), -INT8_C(  53), -INT8_C(  49),  INT8_C(  65),  INT8_C(   6),  INT8_C( 106),  INT8_C(  11) },
        {  INT8_C(  14),  INT8_C( 112), -INT8_C(  28),  INT8_C(   9),  INT8_C(  14), -INT8_C(  83),  INT8_C(  88), -INT8_C(  54),
          -INT8_C(  73), -INT8_C( 101), -INT8_C( 106), -INT8_C(  53),  INT8_C(  92),  INT8_C(  21),  INT8_C(   0),  INT8_C(  17) },
        {  INT8_C(  14),  INT8_C(   6), -INT8_C(  28), -INT8_C(  13),  INT8_C(  14), -INT8_C(  83),  INT8_C(  57), -INT8_C(  85),
          -INT8_C(  73), -INT8_C( 104), -INT8_C( 106), -INT8_C(  53),  INT8_C(  65),  INT8_C(   6),  INT8_C(   0),  INT8_C(  11) } },
      { { -INT8_C(   3),  INT8_C(  28),  INT8_C( 125),  INT8_C(  19),  INT8_C(  10),  INT8_C( 112), -INT8_C(  21),  INT8_C(   9),
           INT8_C( 112), -INT8_C(  83), -INT8_C(  62),  INT8_C(  53), -INT8_C(  56), -INT8_C(  98), -INT8_C(  36),  INT8_C(  91) },
        {  INT8_C(   7), -INT8_C( 106), -INT8_C(  53),  INT8_C(  82), -INT8_C(  90),  INT8_C( 118),  INT8_C(  98), -INT8_C(  52),
           INT8_C( 116), -INT8_C(  26),  INT8_C(  14),  INT8_C(  77), -INT8_C( 123), -INT8_C(  52),  INT8_C( 124), -INT8_C( 122) },
        { -INT8_C(   3), -INT8_C( 106), -INT8_C(  53),  INT8_C(  19), -INT8_C(  90),  INT8_C( 112), -INT8_C(  21), -INT8_C(  52),
           INT8_C( 112), -INT8_C(  83), -INT8_C(  62),  INT8_C(  53), -INT8_C( 123), -INT8_C(  98), -INT8_C(  36), -INT8_C( 122) } },
      { {  INT8_C(  28),  INT8_C(  63), -INT8_C(   9), -INT8_C(  41), -INT8_C(  56), -INT8_C(  48), -INT8_C(  35), -INT8_C( 127),
           INT8_C(  52),  INT8_C(  45),  INT8_C(  18), -INT8_C(  45), -INT8_C(  23),  INT8_C(  44), -INT8_C(  75),  INT8_C(  79) },
        { -INT8_C(  15), -INT8_C(   4),  INT8_C(  26),  INT8_C( 105),  INT8_C(  25),  INT8_C(  77),  INT8_C(  80), -INT8_C( 122),
          -INT8_C(   8), -INT8_C(  53), -INT8_C(  29), -INT8_C(  35),  INT8_C(  70), -INT8_C(   1),  INT8_C(  54), -INT8_C(  42) },
        { -INT8_C(  15), -INT8_C(   4), -INT8_C(   9), -INT8_C(  41), -INT8_C(  56), -INT8_C(  48), -INT8_C(  35), -INT8_C( 127),
          -INT8_C(   8), -INT8_C(  53), -INT8_C(  29), -INT8_C(  45), -INT8_C(  23), -INT8_C(   1), -INT8_C(  75), -INT8_C(  42) } },
      { { -INT8_C(  56), -INT8_C( 118),  INT8_C( 124),  INT8_C(  43),  INT8_C( 116),  INT8_C( 124), -INT8_C(  51), -INT8_C(  82),
           INT8_C(  21),  INT8_C(  96),  INT8_C(  69),  INT8_C(  64), -INT8_C( 125), -INT8_C(  40), -INT8_C(   8),  INT8_C(  82) },
        {  INT8_C( 122), -INT8_C(  17),  INT8_C(  20), -INT8_C(  98),  INT8_C(  11), -INT8_C(  76),  INT8_C( 112), -INT8_C(   2),
           INT8_C(  65), -INT8_C(  82), -INT8_C(  33), -INT8_C(   6),  INT8_C(  45), -INT8_C(  29),  INT8_C(  11), -INT8_C(  76) },
        { -INT8_C(  56), -INT8_C( 118),  INT8_C(  20), -INT8_C(  98),  INT8_C(  11), -INT8_C(  76), -INT8_C(  51), -INT8_C(  82),
           INT8_C(  21), -INT8_C(  82), -INT8_C(  33), -INT8_C(   6), -INT8_C( 125), -INT8_C(  40), -INT8_C(   8), -INT8_C(  76) } },
      { {  INT8_C( 106), -INT8_C( 120), -INT8_C(  47),  INT8_C(  98), -INT8_C(  62), -INT8_C( 108),  INT8_C( 118),  INT8_C(  23),
           INT8_C( 114), -INT8_C(  56), -INT8_C(  11),  INT8_C(  56),      INT8_MAX, -INT8_C( 126),  INT8_C(  82), -INT8_C(  77) },
        { -INT8_C(  68),  INT8_C(  52),  INT8_C(  37),  INT8_C(  85),  INT8_C(  66),      INT8_MIN, -INT8_C(   6), -INT8_C(  53),
          -INT8_C(  34),  INT8_C(  31),  INT8_C(  40),  INT8_C(  99), -INT8_C(  37), -INT8_C( 112), -INT8_C(  94), -INT8_C(  49) },
        { -INT8_C(  68), -INT8_C( 120), -INT8_C(  47),  INT8_C(  85), -INT8_C(  62),      INT8_MIN, -INT8_C(   6), -INT8_C(  53),
          -INT8_C(  34), -INT8_C(  56), -INT8_C(  11),  INT8_C(  56), -INT8_C(  37), -INT8_C( 126), -INT8_C(  94), -INT8_C(  77) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t b = simde_wasm_v128_load(test_vec[i].b);
      simde_v128_t r = simde_wasm_i8x16_min(a, b);
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

      r = simde_wasm_i8x16_min(a, b);

      simde_test_wasm_i8x16_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_i8x16_write(3, b, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_wasm_i8x16_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_i16x8_min(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      int16_t a[sizeof(simde_v128_t) / sizeof(int16_t)];
      int16_t b[sizeof(simde_v128_t) / sizeof(int16_t)];
      int16_t r[sizeof(simde_v128_t) / sizeof(int16_t)];
    } test_vec[] = {
      { {  INT16_C(  8053),  INT16_C( 29791), -INT16_C( 23489),  INT16_C( 25045), -INT16_C(  6262), -INT16_C( 18238), -INT16_C(  1983), -INT16_C( 18748) },
        { -INT16_C( 21537),  INT16_C(  2622), -INT16_C(  5256),  INT16_C(  2341),  INT16_C( 25072), -INT16_C(  2053), -INT16_C(  1995), -INT16_C( 23585) },
        { -INT16_C( 21537),  INT16_C(  2622), -INT16_C( 23489),  INT16_C(  2341), -INT16_C(  6262), -INT16_C( 18238), -INT16_C(  1995), -INT16_C( 23585) } },
      { { -INT16_C(  2867), -INT16_C( 17579),  INT16_C( 31976), -INT16_C(  1286), -INT16_C( 32448), -INT16_C( 25901), -INT16_C( 20578),  INT16_C(  8652) },
        {  INT16_C( 30520), -INT16_C( 13649),  INT16_C( 12464), -INT16_C( 14933),  INT16_C( 28589),  INT16_C(  6374),  INT16_C( 24345), -INT16_C( 14904) },
        { -INT16_C(  2867), -INT16_C( 17579),  INT16_C( 12464), -INT16_C( 14933), -INT16_C( 32448), -INT16_C( 25901), -INT16_C( 20578), -INT16_C( 14904) } },
      { {  INT16_C( 21414),  INT16_C( 14651), -INT16_C( 30407),  INT16_C( 19533),  INT16_C( 27229), -INT16_C( 17714), -INT16_C(  2487),  INT16_C( 19476) },
        { -INT16_C( 22286),  INT16_C( 13696), -INT16_C( 24057), -INT16_C(  3626), -INT16_C( 31134), -INT16_C( 32379),  INT16_C( 20625), -INT16_C( 19469) },
        { -INT16_C( 22286),  INT16_C( 13696), -INT16_C( 30407), -INT16_C(  3626), -INT16_C( 31134), -INT16_C( 32379), -INT16_C(  2487), -INT16_C( 19469) } },
      { { -INT16_C( 26905),  INT16_C( 19986), -INT16_C( 22843),  INT16_C( 26974), -INT16_C( 13997), -INT16_C( 28589), -INT16_C( 19506), -INT16_C( 20327) },
        {  INT16_C( 23342), -INT16_C(   687),  INT16_C( 15623), -INT16_C( 13554),  INT16_C( 10487), -INT16_C( 20549),  INT16_C(  5508),  INT16_C(  9329) },
        { -INT16_C( 26905), -INT16_C(   687), -INT16_C( 22843), -INT16_C( 13554), -INT16_C( 13997), -INT16_C( 28589), -INT16_C( 19506), -INT16_C( 20327) } },
      { {  INT16_C(  3092), -INT16_C(   786),  INT16_C( 31554),  INT16_C( 15150), -INT16_C(  8318),  INT16_C( 21495), -INT16_C( 27393), -INT16_C(  2984) },
        {  INT16_C( 27558), -INT16_C(  6734), -INT16_C( 14470), -INT16_C( 11041), -INT16_C( 22541), -INT16_C( 18065), -INT16_C( 19988), -INT16_C( 10698) },
        {  INT16_C(  3092), -INT16_C(  6734), -INT16_C( 14470), -INT16_C( 11041), -INT16_C( 22541), -INT16_C( 18065), -INT16_C( 27393), -INT16_C( 10698) } },
      { {  INT16_C( 24741), -INT16_C( 23024),  INT16_C( 19491),  INT16_C( 13561),  INT16_C( 20217), -INT16_C( 27967), -INT16_C( 13848), -INT16_C( 32133) },
        { -INT16_C( 29234),  INT16_C( 16380),  INT16_C( 23999),  INT16_C( 15241),  INT16_C( 10749), -INT16_C( 19515),  INT16_C( 20357), -INT16_C(  8952) },
        { -INT16_C( 29234), -INT16_C( 23024),  INT16_C( 19491),  INT16_C( 13561),  INT16_C( 10749), -INT16_C( 27967), -INT16_C( 13848), -INT16_C( 32133) } },
      { { -INT16_C( 32522),  INT16_C( 20098),  INT16_C( 22696),  INT16_C( 31362), -INT16_C(  6984),  INT16_C( 23585),  INT16_C( 15427), -INT16_C( 29186) },
        {  INT16_C(   381), -INT16_C(  4689), -INT16_C( 28772), -INT16_C( 13562),  INT16_C( 13025), -INT16_C( 29990),  INT16_C( 17412),  INT16_C( 29930) },
        { -INT16_C( 32522), -INT16_C(  4689), -INT16_C( 28772), -INT16_C( 13562), -INT16_C(  6984), -INT16_C( 29990),  INT16_C( 15427), -INT16_C( 29186) } },
      { {  INT16_C(  1183),  INT16_C( 21811), -INT16_C( 22415), -INT16_C( 25889), -INT16_C(  9355), -INT16_C( 10384),  INT16_C( 17774), -INT16_C( 22303) },
        { -INT16_C( 19958), -INT16_C(  9138), -INT16_C(  1650),  INT16_C( 23961), -INT16_C( 22767),  INT16_C( 26367),  INT16_C( 31689),  INT16_C( 18432) },
        { -INT16_C( 19958), -INT16_C(  9138), -INT16_C( 22415), -INT16_C( 25889), -INT16_C( 22767), -INT16_C( 10384),  INT16_C( 17774), -INT16_C( 22303) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t b = simde_wasm_v128_load(test_vec[i].b);
      simde_v128_t r = simde_wasm_i16x8_min(a, b);
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

      r = simde_wasm_i16x8_min(a, b);

      simde_test_wasm_i16x8_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_i16x8_write(3, b, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_wasm_i16x8_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_i32x4_min(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      int32_t a[sizeof(simde_v128_t) / sizeof(int32_t)];
      int32_t b[sizeof(simde_v128_t) / sizeof(int32_t)];
      int32_t r[sizeof(simde_v128_t) / sizeof(int32_t)];
    } test_vec[] = {
      { { -INT32_C(  1215556258), -INT32_C(  1245483889),  INT32_C(  1642505953), -INT32_C(   791747371) },
        {  INT32_C(   179757297), -INT32_C(   992455518), -INT32_C(  2072749655),  INT32_C(  1258713872) },
        { -INT32_C(  1215556258), -INT32_C(  1245483889), -INT32_C(  2072749655), -INT32_C(   791747371) } },
      { { -INT32_C(   845753225),  INT32_C(   759811868),  INT32_C(   857355620), -INT32_C(    12093967) },
        { -INT32_C(    50575625),  INT32_C(  1077154754), -INT32_C(  1633482253),  INT32_C(     3061669) },
        { -INT32_C(   845753225),  INT32_C(   759811868), -INT32_C(  1633482253), -INT32_C(    12093967) } },
      { { -INT32_C(  1920319079), -INT32_C(   650293431),  INT32_C(  2063056233),  INT32_C(   911207345) },
        { -INT32_C(   993540916),  INT32_C(  1762293387), -INT32_C(  1076170136),  INT32_C(  1284951321) },
        { -INT32_C(  1920319079), -INT32_C(   650293431), -INT32_C(  1076170136),  INT32_C(   911207345) } },
      { {  INT32_C(  1173594942), -INT32_C(  1326672140), -INT32_C(    96600551),  INT32_C(   295010673) },
        {  INT32_C(  2133491758), -INT32_C(  1607982175), -INT32_C(  1417032909), -INT32_C(  1003702927) },
        {  INT32_C(  1173594942), -INT32_C(  1607982175), -INT32_C(  1417032909), -INT32_C(  1003702927) } },
      { { -INT32_C(   582653040), -INT32_C(   143995974),  INT32_C(   779750562), -INT32_C(   769525393) },
        {  INT32_C(  1325634444), -INT32_C(    52741249), -INT32_C(  1191684552),  INT32_C(  2098978142) },
        { -INT32_C(   582653040), -INT32_C(   143995974), -INT32_C(  1191684552), -INT32_C(   769525393) } },
      { { -INT32_C(  1778670900), -INT32_C(   195006581), -INT32_C(   511601411), -INT32_C(   193049670) },
        { -INT32_C(   489673686), -INT32_C(  1115949620),  INT32_C(   847797649),  INT32_C(  1521981676) },
        { -INT32_C(  1778670900), -INT32_C(  1115949620), -INT32_C(   511601411), -INT32_C(   193049670) } },
      { {  INT32_C(  1160759334),  INT32_C(   475444153),  INT32_C(  1399628584),  INT32_C(   929358247) },
        {  INT32_C(  1762605763),  INT32_C(   930328367),  INT32_C(   912802709), -INT32_C(   605546826) },
        {  INT32_C(  1160759334),  INT32_C(   475444153),  INT32_C(   912802709), -INT32_C(   605546826) } },
      { {  INT32_C(   448414505), -INT32_C(  1099019374), -INT32_C(   686690062),  INT32_C(   769871557) },
        {  INT32_C(   488148907),  INT32_C(  1137478558),  INT32_C(   299172442),  INT32_C(  1796462490) },
        {  INT32_C(   448414505), -INT32_C(  1099019374), -INT32_C(   686690062),  INT32_C(   769871557) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t b = simde_wasm_v128_load(test_vec[i].b);
      simde_v128_t r = simde_wasm_i32x4_min(a, b);
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

      r = simde_wasm_i32x4_min(a, b);

      simde_test_wasm_i32x4_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_i32x4_write(3, b, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_wasm_i32x4_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_u8x16_min(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      uint8_t a[sizeof(simde_v128_t) / sizeof(uint8_t)];
      uint8_t b[sizeof(simde_v128_t) / sizeof(uint8_t)];
      uint8_t r[sizeof(simde_v128_t) / sizeof(uint8_t)];
    } test_vec[] = {
      { { UINT8_C(234), UINT8_C( 90), UINT8_C( 18), UINT8_C(141), UINT8_C( 10), UINT8_C( 67), UINT8_C( 39), UINT8_C(102),
          UINT8_C(116), UINT8_C( 38), UINT8_C(217), UINT8_C( 10), UINT8_C( 49), UINT8_C(108), UINT8_C(148), UINT8_C( 77) },
        { UINT8_C(156), UINT8_C(109), UINT8_C(230), UINT8_C(220), UINT8_C( 86), UINT8_C(183), UINT8_C(250), UINT8_C( 36),
          UINT8_C( 64), UINT8_C( 37), UINT8_C( 26), UINT8_C( 92), UINT8_C(133), UINT8_C( 55), UINT8_C(  2), UINT8_C( 84) },
        { UINT8_C(156), UINT8_C( 90), UINT8_C( 18), UINT8_C(141), UINT8_C( 10), UINT8_C( 67), UINT8_C( 39), UINT8_C( 36),
          UINT8_C( 64), UINT8_C( 37), UINT8_C( 26), UINT8_C( 10), UINT8_C( 49), UINT8_C( 55), UINT8_C(  2), UINT8_C( 77) } },
      { { UINT8_C(143), UINT8_C(206), UINT8_C(125), UINT8_C(121),    UINT8_MAX, UINT8_C( 11), UINT8_C( 53), UINT8_C( 68),
          UINT8_C( 96), UINT8_C( 92), UINT8_C( 87), UINT8_C(126), UINT8_C( 52), UINT8_C(204), UINT8_C( 26), UINT8_C(242) },
        { UINT8_C(232), UINT8_C( 59), UINT8_C(218), UINT8_C( 82), UINT8_C( 55), UINT8_C(234), UINT8_C( 41), UINT8_C( 42),
          UINT8_C(116), UINT8_C( 53), UINT8_C( 49), UINT8_C( 79), UINT8_C(156), UINT8_C(108), UINT8_C(122), UINT8_C(187) },
        { UINT8_C(143), UINT8_C( 59), UINT8_C(125), UINT8_C( 82), UINT8_C( 55), UINT8_C( 11), UINT8_C( 41), UINT8_C( 42),
          UINT8_C( 96), UINT8_C( 53), UINT8_C( 49), UINT8_C( 79), UINT8_C( 52), UINT8_C(108), UINT8_C( 26), UINT8_C(187) } },
      { { UINT8_C(121), UINT8_C( 77), UINT8_C(192), UINT8_C( 84), UINT8_C(161), UINT8_C(209), UINT8_C(204), UINT8_C(107),
          UINT8_C( 76), UINT8_C(  2), UINT8_C( 35), UINT8_C(243), UINT8_C( 73), UINT8_C( 75), UINT8_C(116), UINT8_C(210) },
        { UINT8_C(160), UINT8_C(236), UINT8_C(130), UINT8_C( 43), UINT8_C( 23), UINT8_C(207), UINT8_C(178), UINT8_C(152),
          UINT8_C(221), UINT8_C(216), UINT8_C(130), UINT8_C( 58), UINT8_C(201), UINT8_C(244), UINT8_C(164), UINT8_C(  7) },
        { UINT8_C(121), UINT8_C( 77), UINT8_C(130), UINT8_C( 43), UINT8_C( 23), UINT8_C(207), UINT8_C(178), UINT8_C(107),
          UINT8_C( 76), UINT8_C(  2), UINT8_C( 35), UINT8_C( 58), UINT8_C( 73), UINT8_C( 75), UINT8_C(116), UINT8_C(  7) } },
      { { UINT8_C( 48), UINT8_C(  3), UINT8_C( 35), UINT8_C(191), UINT8_C(120), UINT8_C(229), UINT8_C( 36), UINT8_C( 31),
          UINT8_C( 21), UINT8_C(125), UINT8_C(156), UINT8_C(136), UINT8_C( 77), UINT8_C( 13), UINT8_C(120), UINT8_C(224) },
        { UINT8_C( 14), UINT8_C(250), UINT8_C( 67), UINT8_C(228), UINT8_C(233), UINT8_C(148), UINT8_C(242), UINT8_C(199),
          UINT8_C(  9), UINT8_C(217), UINT8_C( 83), UINT8_C(179), UINT8_C(114), UINT8_C(  7), UINT8_C( 33), UINT8_C(226) },
        { UINT8_C( 14), UINT8_C(  3), UINT8_C( 35), UINT8_C(191), UINT8_C(120), UINT8_C(148), UINT8_C( 36), UINT8_C( 31),
          UINT8_C(  9), UINT8_C(125), UINT8_C( 83), UINT8_C(136), UINT8_C( 77), UINT8_C(  7), UINT8_C( 33), UINT8_C(224) } },
      { { UINT8_C(217), UINT8_C(123), UINT8_C( 87), UINT8_C(188), UINT8_C( 25), UINT8_C(  9), UINT8_C(106), UINT8_C( 60),
          UINT8_C( 11), UINT8_C( 99), UINT8_C(213), UINT8_C( 76), UINT8_C(220), UINT8_C( 43), UINT8_C(119), UINT8_C(197) },
        { UINT8_C( 62), UINT8_C(247), UINT8_C(184), UINT8_C( 86), UINT8_C(  6), UINT8_C(117), UINT8_C(  4), UINT8_C( 58),
          UINT8_C( 14), UINT8_C( 36), UINT8_C(219), UINT8_C(236), UINT8_C(  3), UINT8_C(151), UINT8_C( 71), UINT8_C(239) },
        { UINT8_C( 62), UINT8_C(123), UINT8_C( 87), UINT8_C( 86), UINT8_C(  6), UINT8_C(  9), UINT8_C(  4), UINT8_C( 58),
          UINT8_C( 11), UINT8_C( 36), UINT8_C(213), UINT8_C( 76), UINT8_C(  3), UINT8_C( 43), UINT8_C( 71), UINT8_C(197) } },
      { { UINT8_C( 96), UINT8_C(119), UINT8_C(243), UINT8_C(253), UINT8_C(185), UINT8_C(  3), UINT8_C( 51), UINT8_C(192),
          UINT8_C(249), UINT8_C(179), UINT8_C(243), UINT8_C(238), UINT8_C(195), UINT8_C(154), UINT8_C(144), UINT8_C(201) },
        { UINT8_C(229), UINT8_C( 46), UINT8_C(242), UINT8_C(194), UINT8_C(134), UINT8_C(  1), UINT8_C(238), UINT8_C(231),
          UINT8_C( 78), UINT8_C(191), UINT8_C( 99), UINT8_C( 33), UINT8_C( 41), UINT8_C(250), UINT8_C( 48), UINT8_C(111) },
        { UINT8_C( 96), UINT8_C( 46), UINT8_C(242), UINT8_C(194), UINT8_C(134), UINT8_C(  1), UINT8_C( 51), UINT8_C(192),
          UINT8_C( 78), UINT8_C(179), UINT8_C( 99), UINT8_C( 33), UINT8_C( 41), UINT8_C(154), UINT8_C( 48), UINT8_C(111) } },
      { { UINT8_C( 29), UINT8_C( 81), UINT8_C(112), UINT8_C(184), UINT8_C( 69), UINT8_C(160), UINT8_C( 99), UINT8_C(201),
          UINT8_C(175), UINT8_C(151), UINT8_C( 11), UINT8_C(244), UINT8_C(251), UINT8_C(155), UINT8_C(124), UINT8_C( 47) },
        { UINT8_C(199), UINT8_C(186), UINT8_C( 54), UINT8_C(104), UINT8_C( 16), UINT8_C(231), UINT8_C( 83), UINT8_C(248),
          UINT8_C(196), UINT8_C( 66), UINT8_C(227), UINT8_C(143), UINT8_C(133), UINT8_C( 19), UINT8_C( 72), UINT8_C( 99) },
        { UINT8_C( 29), UINT8_C( 81), UINT8_C( 54), UINT8_C(104), UINT8_C( 16), UINT8_C(160), UINT8_C( 83), UINT8_C(201),
          UINT8_C(175), UINT8_C( 66), UINT8_C( 11), UINT8_C(143), UINT8_C(133), UINT8_C( 19), UINT8_C( 72), UINT8_C( 47) } },
      { { UINT8_C(250), UINT8_C(205), UINT8_C(173), UINT8_C(251), UINT8_C(249), UINT8_C( 67), UINT8_C(164), UINT8_C( 26),
          UINT8_C(  2), UINT8_C(151), UINT8_C(127), UINT8_C(109), UINT8_C( 28), UINT8_C(160), UINT8_C(222), UINT8_C( 30) },
        { UINT8_C(161), UINT8_C( 36), UINT8_C( 58), UINT8_C(154), UINT8_C( 60), UINT8_C( 66), UINT8_C(158), UINT8_C( 12),
          UINT8_C(199), UINT8_C(215), UINT8_C( 35), UINT8_C(226), UINT8_C(230), UINT8_C(  2), UINT8_C( 95), UINT8_C( 48) },
        { UINT8_C(161), UINT8_C( 36), UINT8_C( 58), UINT8_C(154), UINT8_C( 60), UINT8_C( 66), UINT8_C(158), UINT8_C( 12),
          UINT8_C(  2), UINT8_C(151), UINT8_C( 35), UINT8_C(109), UINT8_C( 28), UINT8_C(  2), UINT8_C( 95), UINT8_C( 30) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t b = simde_wasm_v128_load(test_vec[i].b);
      simde_v128_t r = simde_wasm_u8x16_min(a, b);
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

      r = simde_wasm_u8x16_min(a, b);

      simde_test_wasm_u8x16_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_u8x16_write(3, b, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_wasm_u8x16_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_u16x8_min(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      uint16_t a[sizeof(simde_v128_t) / sizeof(uint16_t)];
      uint16_t b[sizeof(simde_v128_t) / sizeof(uint16_t)];
      uint16_t r[sizeof(simde_v128_t) / sizeof(uint16_t)];
    } test_vec[] = {
      { { UINT16_C(32286), UINT16_C(33003), UINT16_C(62072), UINT16_C( 8273), UINT16_C(23131), UINT16_C( 8932), UINT16_C(48728), UINT16_C(  276) },
        { UINT16_C(31883), UINT16_C(19690), UINT16_C(25695), UINT16_C(64179), UINT16_C(45392), UINT16_C(11865), UINT16_C(18685), UINT16_C(49203) },
        { UINT16_C(31883), UINT16_C(19690), UINT16_C(25695), UINT16_C( 8273), UINT16_C(23131), UINT16_C( 8932), UINT16_C(18685), UINT16_C(  276) } },
      { { UINT16_C(39184), UINT16_C(64844), UINT16_C(56163), UINT16_C(29412), UINT16_C(57273), UINT16_C(19032), UINT16_C(37103), UINT16_C(27524) },
        { UINT16_C(62692), UINT16_C(11168), UINT16_C( 7401), UINT16_C( 6432), UINT16_C( 2501), UINT16_C(23365), UINT16_C(30871), UINT16_C(10372) },
        { UINT16_C(39184), UINT16_C(11168), UINT16_C( 7401), UINT16_C( 6432), UINT16_C( 2501), UINT16_C(19032), UINT16_C(30871), UINT16_C(10372) } },
      { { UINT16_C(21856), UINT16_C(63701), UINT16_C(25966), UINT16_C(54247), UINT16_C(14136), UINT16_C(49256), UINT16_C(43815), UINT16_C(31082) },
        { UINT16_C(65207), UINT16_C(12008), UINT16_C(35385), UINT16_C(64969), UINT16_C(38717), UINT16_C( 8408), UINT16_C(24658), UINT16_C(50848) },
        { UINT16_C(21856), UINT16_C(12008), UINT16_C(25966), UINT16_C(54247), UINT16_C(14136), UINT16_C( 8408), UINT16_C(24658), UINT16_C(31082) } },
      { { UINT16_C(50125), UINT16_C( 7655), UINT16_C(47610), UINT16_C(47460), UINT16_C(49947), UINT16_C(45165), UINT16_C(32963), UINT16_C(46888) },
        { UINT16_C(58018), UINT16_C(43196), UINT16_C(25335), UINT16_C(48662), UINT16_C(37190), UINT16_C(28233), UINT16_C(46036), UINT16_C(60274) },
        { UINT16_C(50125), UINT16_C( 7655), UINT16_C(25335), UINT16_C(47460), UINT16_C(37190), UINT16_C(28233), UINT16_C(32963), UINT16_C(46888) } },
      { { UINT16_C(10988), UINT16_C( 3142), UINT16_C(51497), UINT16_C(19922), UINT16_C(59728), UINT16_C(53095), UINT16_C(53245), UINT16_C(33049) },
        { UINT16_C(56637), UINT16_C(56388), UINT16_C(47590), UINT16_C(47017), UINT16_C( 8241), UINT16_C(27068), UINT16_C(13445), UINT16_C(63508) },
        { UINT16_C(10988), UINT16_C( 3142), UINT16_C(47590), UINT16_C(19922), UINT16_C( 8241), UINT16_C(27068), UINT16_C(13445), UINT16_C(33049) } },
      { { UINT16_C(58194), UINT16_C(45455), UINT16_C(57975), UINT16_C(61827), UINT16_C(22137), UINT16_C( 3427), UINT16_C(35829), UINT16_C(59095) },
        { UINT16_C(47871), UINT16_C( 4632), UINT16_C(21823), UINT16_C(52866), UINT16_C(25043), UINT16_C(55900), UINT16_C(25793), UINT16_C(  985) },
        { UINT16_C(47871), UINT16_C( 4632), UINT16_C(21823), UINT16_C(52866), UINT16_C(22137), UINT16_C( 3427), UINT16_C(25793), UINT16_C(  985) } },
      { { UINT16_C(45877), UINT16_C( 4927), UINT16_C(45776), UINT16_C(16278), UINT16_C(46705), UINT16_C(50773), UINT16_C(19122), UINT16_C( 3347) },
        { UINT16_C(61354), UINT16_C( 9975), UINT16_C(29063), UINT16_C(13497), UINT16_C(56784), UINT16_C( 7679), UINT16_C(43410), UINT16_C(64738) },
        { UINT16_C(45877), UINT16_C( 4927), UINT16_C(29063), UINT16_C(13497), UINT16_C(46705), UINT16_C( 7679), UINT16_C(19122), UINT16_C( 3347) } },
      { { UINT16_C(42650), UINT16_C(43055), UINT16_C(54567), UINT16_C(36196), UINT16_C(60759), UINT16_C(30328), UINT16_C(11664), UINT16_C( 5600) },
        { UINT16_C(13357), UINT16_C(40465), UINT16_C( 3047), UINT16_C(42918), UINT16_C(33888), UINT16_C(39998), UINT16_C(64487), UINT16_C(19494) },
        { UINT16_C(13357), UINT16_C(40465), UINT16_C( 3047), UINT16_C(36196), UINT16_C(33888), UINT16_C(30328), UINT16_C(11664), UINT16_C( 5600) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t b = simde_wasm_v128_load(test_vec[i].b);
      simde_v128_t r = simde_wasm_u16x8_min(a, b);
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

      r = simde_wasm_u16x8_min(a, b);

      simde_test_wasm_u16x8_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_u16x8_write(3, b, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_wasm_u16x8_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_u32x4_min(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      uint32_t a[sizeof(simde_v128_t) / sizeof(uint32_t)];
      uint32_t b[sizeof(simde_v128_t) / sizeof(uint32_t)];
      uint32_t r[sizeof(simde_v128_t) / sizeof(uint32_t)];
    } test_vec[] = {
      { { UINT32_C( 730884854), UINT32_C(4101103758), UINT32_C(4012889103), UINT32_C(2088783935) },
        { UINT32_C(1035772942), UINT32_C( 949137408), UINT32_C(3139119255), UINT32_C(4211609421) },
        { UINT32_C( 730884854), UINT32_C( 949137408), UINT32_C(3139119255), UINT32_C(2088783935) } },
      { { UINT32_C(3949865559), UINT32_C(3470322638), UINT32_C( 106985295), UINT32_C(4273515571) },
        { UINT32_C( 314135120), UINT32_C(2363934533), UINT32_C(1327135021), UINT32_C(1415643423) },
        { UINT32_C( 314135120), UINT32_C(2363934533), UINT32_C( 106985295), UINT32_C(1415643423) } },
      { { UINT32_C(2679040271), UINT32_C(3124468601), UINT32_C(3411593505), UINT32_C(4204432032) },
        { UINT32_C( 317745112), UINT32_C(2681952463), UINT32_C(2431025347), UINT32_C(  51610437) },
        { UINT32_C( 317745112), UINT32_C(2681952463), UINT32_C(2431025347), UINT32_C(  51610437) } },
      { { UINT32_C(3129827283), UINT32_C( 573878662), UINT32_C( 992339437), UINT32_C(1440312814) },
        { UINT32_C( 615694169), UINT32_C( 145186489), UINT32_C(2339149737), UINT32_C(3188883303) },
        { UINT32_C( 615694169), UINT32_C( 145186489), UINT32_C( 992339437), UINT32_C(1440312814) } },
      { { UINT32_C(1067339882), UINT32_C(1010962791), UINT32_C(1903871488), UINT32_C(3734206386) },
        { UINT32_C(3111452343), UINT32_C(3140324081), UINT32_C( 377088553), UINT32_C(1694125731) },
        { UINT32_C(1067339882), UINT32_C(1010962791), UINT32_C( 377088553), UINT32_C(1694125731) } },
      { { UINT32_C( 273312207), UINT32_C(2335789214), UINT32_C(1510638737), UINT32_C( 748903460) },
        { UINT32_C(3692180205), UINT32_C(1294767509), UINT32_C(1155426890), UINT32_C(2719635912) },
        { UINT32_C( 273312207), UINT32_C(1294767509), UINT32_C(1155426890), UINT32_C( 748903460) } },
      { { UINT32_C(3352206810), UINT32_C(3845176536), UINT32_C(3949399627), UINT32_C( 158385941) },
        { UINT32_C(3347900793), UINT32_C(3086026434), UINT32_C(1443451163), UINT32_C( 319047433) },
        { UINT32_C(3347900793), UINT32_C(3086026434), UINT32_C(1443451163), UINT32_C( 158385941) } },
      { { UINT32_C(  45874534), UINT32_C(4142983293), UINT32_C(3462750801), UINT32_C(1295665512) },
        { UINT32_C(4098149693), UINT32_C(2524873205), UINT32_C( 774444662), UINT32_C(3885739319) },
        { UINT32_C(  45874534), UINT32_C(2524873205), UINT32_C( 774444662), UINT32_C(1295665512) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t b = simde_wasm_v128_load(test_vec[i].b);
      simde_v128_t r = simde_wasm_u32x4_min(a, b);
      simde_test_wasm_u32x4_assert_equal(r, simde_wasm_v128_load(test_vec[i].r));
    }
    return 0;
  #else
    fputc('\n', stdout);
    for (int i = 0 ; i < 8 ; i++) {
      simde_v128_t
        a = simde_test_wasm_u32x4_random(),
        b = simde_test_wasm_u32x4_random(),
        r;

      r = simde_wasm_u32x4_min(a, b);

      simde_test_wasm_u32x4_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_u32x4_write(3, b, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_wasm_u32x4_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_f32x4_min(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      simde_float32 a[sizeof(simde_v128_t) / sizeof(simde_float32)];
      simde_float32 b[sizeof(simde_v128_t) / sizeof(simde_float32)];
      simde_float32 r[sizeof(simde_v128_t) / sizeof(simde_float32)];
    } test_vec[] = {
      #if !defined(SIMDE_FAST_MATH)
      { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -390.25),            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -196.34) },
        { SIMDE_FLOAT32_C(   205.16),            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -196.34) },
        {            SIMDE_MATH_NANF,            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -196.34) } },
      { { SIMDE_FLOAT32_C(    -0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(    -0.00), SIMDE_FLOAT32_C(     0.00) },
        { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(    -0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(    -0.00) },
        { SIMDE_FLOAT32_C(    -0.00), SIMDE_FLOAT32_C(    -0.00), SIMDE_FLOAT32_C(    -0.00), SIMDE_FLOAT32_C(    -0.00) } },
      #endif
      { { SIMDE_FLOAT32_C(  -384.73), SIMDE_FLOAT32_C(  -820.97), SIMDE_FLOAT32_C(   258.75), SIMDE_FLOAT32_C(   -90.51) },
        { SIMDE_FLOAT32_C(   635.11), SIMDE_FLOAT32_C(   -21.53), SIMDE_FLOAT32_C(  -197.11), SIMDE_FLOAT32_C(   959.39) },
        { SIMDE_FLOAT32_C(  -384.73), SIMDE_FLOAT32_C(  -820.97), SIMDE_FLOAT32_C(  -197.11), SIMDE_FLOAT32_C(   -90.51) } },
      { { SIMDE_FLOAT32_C(   756.93), SIMDE_FLOAT32_C(  -403.83), SIMDE_FLOAT32_C(  -535.40), SIMDE_FLOAT32_C(   581.16) },
        { SIMDE_FLOAT32_C(   575.10), SIMDE_FLOAT32_C(  -784.62), SIMDE_FLOAT32_C(   826.27), SIMDE_FLOAT32_C(  -290.44) },
        { SIMDE_FLOAT32_C(   575.10), SIMDE_FLOAT32_C(  -784.62), SIMDE_FLOAT32_C(  -535.40), SIMDE_FLOAT32_C(  -290.44) } },
      { { SIMDE_FLOAT32_C(  -580.63), SIMDE_FLOAT32_C(   400.60), SIMDE_FLOAT32_C(  -825.33), SIMDE_FLOAT32_C(   395.98) },
        { SIMDE_FLOAT32_C(   903.08), SIMDE_FLOAT32_C(   523.68), SIMDE_FLOAT32_C(  -270.81), SIMDE_FLOAT32_C(  -996.64) },
        { SIMDE_FLOAT32_C(  -580.63), SIMDE_FLOAT32_C(   400.60), SIMDE_FLOAT32_C(  -825.33), SIMDE_FLOAT32_C(  -996.64) } },
      { { SIMDE_FLOAT32_C(  -450.06), SIMDE_FLOAT32_C(  -799.96), SIMDE_FLOAT32_C(    54.34), SIMDE_FLOAT32_C(   646.36) },
        { SIMDE_FLOAT32_C(  -396.89), SIMDE_FLOAT32_C(   -93.21), SIMDE_FLOAT32_C(  -282.13), SIMDE_FLOAT32_C(  -348.89) },
        { SIMDE_FLOAT32_C(  -450.06), SIMDE_FLOAT32_C(  -799.96), SIMDE_FLOAT32_C(  -282.13), SIMDE_FLOAT32_C(  -348.89) } },
      { { SIMDE_FLOAT32_C(   449.36), SIMDE_FLOAT32_C(  -932.70), SIMDE_FLOAT32_C(   504.25), SIMDE_FLOAT32_C(   630.70) },
        { SIMDE_FLOAT32_C(     6.05), SIMDE_FLOAT32_C(   284.22), SIMDE_FLOAT32_C(  -492.84), SIMDE_FLOAT32_C(  -857.28) },
        { SIMDE_FLOAT32_C(     6.05), SIMDE_FLOAT32_C(  -932.70), SIMDE_FLOAT32_C(  -492.84), SIMDE_FLOAT32_C(  -857.28) } },
      { { SIMDE_FLOAT32_C(  -734.85), SIMDE_FLOAT32_C(   291.38), SIMDE_FLOAT32_C(   910.86), SIMDE_FLOAT32_C(  -655.45) },
        { SIMDE_FLOAT32_C(   848.95), SIMDE_FLOAT32_C(  -550.13), SIMDE_FLOAT32_C(    91.62), SIMDE_FLOAT32_C(    71.10) },
        { SIMDE_FLOAT32_C(  -734.85), SIMDE_FLOAT32_C(  -550.13), SIMDE_FLOAT32_C(    91.62), SIMDE_FLOAT32_C(  -655.45) } },
      { { SIMDE_FLOAT32_C(   983.19), SIMDE_FLOAT32_C(   944.04), SIMDE_FLOAT32_C(  -663.05), SIMDE_FLOAT32_C(   678.96) },
        { SIMDE_FLOAT32_C(  -656.24), SIMDE_FLOAT32_C(  -618.32), SIMDE_FLOAT32_C(   677.11), SIMDE_FLOAT32_C(  -741.86) },
        { SIMDE_FLOAT32_C(  -656.24), SIMDE_FLOAT32_C(  -618.32), SIMDE_FLOAT32_C(  -663.05), SIMDE_FLOAT32_C(  -741.86) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t b = simde_wasm_v128_load(test_vec[i].b);
      simde_v128_t r = simde_wasm_f32x4_min(a, b);
      simde_test_wasm_f32x4_assert_equal(r, simde_wasm_v128_load(test_vec[i].r), INT_MAX);
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

      r = simde_wasm_f32x4_min(a, b);

      simde_test_wasm_f32x4_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_f32x4_write(3, b, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_wasm_f32x4_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_f64x2_min(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      simde_float64 a[sizeof(simde_v128_t) / sizeof(simde_float64)];
      simde_float64 b[sizeof(simde_v128_t) / sizeof(simde_float64)];
      simde_float64 r[sizeof(simde_v128_t) / sizeof(simde_float64)];
    } test_vec[] = {
      #if !defined(SIMDE_FAST_MATH)
      { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   370.36) },
        { SIMDE_FLOAT64_C(   297.68),             SIMDE_MATH_NAN },
        {             SIMDE_MATH_NAN,             SIMDE_MATH_NAN } },
      { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -518.63) },
        {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   303.06) },
        {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -518.63) } },
      { { SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(    -0.00) },
        { SIMDE_FLOAT64_C(    -0.00), SIMDE_FLOAT64_C(     0.00) },
        { SIMDE_FLOAT64_C(    -0.00), SIMDE_FLOAT64_C(    -0.00) } },
      #endif
      { { SIMDE_FLOAT64_C(   -79.92), SIMDE_FLOAT64_C(   907.35) },
        { SIMDE_FLOAT64_C(  -343.94), SIMDE_FLOAT64_C(   358.40) },
        { SIMDE_FLOAT64_C(  -343.94), SIMDE_FLOAT64_C(   358.40) } },
      { { SIMDE_FLOAT64_C(   906.87), SIMDE_FLOAT64_C(   964.34) },
        { SIMDE_FLOAT64_C(   672.12), SIMDE_FLOAT64_C(    69.90) },
        { SIMDE_FLOAT64_C(   672.12), SIMDE_FLOAT64_C(    69.90) } },
      { { SIMDE_FLOAT64_C(   891.24), SIMDE_FLOAT64_C(    43.61) },
        { SIMDE_FLOAT64_C(   586.69), SIMDE_FLOAT64_C(   866.82) },
        { SIMDE_FLOAT64_C(   586.69), SIMDE_FLOAT64_C(    43.61) } },
      { { SIMDE_FLOAT64_C(   147.11), SIMDE_FLOAT64_C(  -721.67) },
        { SIMDE_FLOAT64_C(    40.13), SIMDE_FLOAT64_C(   931.62) },
        { SIMDE_FLOAT64_C(    40.13), SIMDE_FLOAT64_C(  -721.67) } },
      { { SIMDE_FLOAT64_C(   114.93), SIMDE_FLOAT64_C(  -695.95) },
        { SIMDE_FLOAT64_C(  -532.17), SIMDE_FLOAT64_C(  -145.28) },
        { SIMDE_FLOAT64_C(  -532.17), SIMDE_FLOAT64_C(  -695.95) } },
      { { SIMDE_FLOAT64_C(   230.71), SIMDE_FLOAT64_C(  -792.59) },
        { SIMDE_FLOAT64_C(   541.02), SIMDE_FLOAT64_C(   155.01) },
        { SIMDE_FLOAT64_C(   230.71), SIMDE_FLOAT64_C(  -792.59) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t b = simde_wasm_v128_load(test_vec[i].b);
      simde_v128_t r = simde_wasm_f64x2_min(a, b);
      simde_test_wasm_f64x2_assert_equal(r, simde_wasm_v128_load(test_vec[i].r), INT_MAX);
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

      r = simde_wasm_f64x2_min(a, b);

      simde_test_wasm_f64x2_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_f64x2_write(3, b, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_wasm_f64x2_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_i8x16_min)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_i16x8_min)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_i32x4_min)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_u8x16_min)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_u16x8_min)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_u32x4_min)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_f32x4_min)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_f64x2_min)
SIMDE_TEST_FUNC_LIST_END

#include "test-simd128-footer.h"
