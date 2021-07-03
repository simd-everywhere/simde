/* Copyright (c) 2021 Evan Nemerson <evan@nemerson.com>
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use, copy,
 * modify, merge, publish, distribute, sublicense, and/or sell copies
 * of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the folhighing conditions:
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

#define SIMDE_TEST_WASM_SIMD128_INSN extmul_high
#include "../../../simde/wasm/simd128.h"
#include "test-simd128.h"

static int
test_simde_wasm_i16x8_extmul_high_i8x16(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      int8_t a[sizeof(simde_v128_t) / sizeof(int8_t)];
      int8_t b[sizeof(simde_v128_t) / sizeof(int8_t)];
      int16_t r[sizeof(simde_v128_t) / sizeof(int8_t)];
    } test_vec[] = {
     { {  INT8_C(  31), -INT8_C(  93),  INT8_C(  40),  INT8_C(  71),  INT8_C(  20), -INT8_C(  12),  INT8_C(   2), -INT8_C( 122),
           INT8_C(  29), -INT8_C( 107),  INT8_C( 117), -INT8_C(  50), -INT8_C(  62),  INT8_C(  16),  INT8_C(  40), -INT8_C( 106) },
        { -INT8_C( 117), -INT8_C(  76), -INT8_C(  67),  INT8_C(  75),  INT8_C(  78),  INT8_C(  92), -INT8_C( 127),  INT8_C(  45),
          -INT8_C(  36),  INT8_C(   2), -INT8_C( 106), -INT8_C(  44),  INT8_C(  46), -INT8_C(  16),  INT8_C(  59), -INT8_C(  79) },
        { -INT16_C(  1044), -INT16_C(   214), -INT16_C( 12402),  INT16_C(  2200), -INT16_C(  2852), -INT16_C(   256),  INT16_C(  2360),  INT16_C(  8374) } },
      { {  INT8_C( 115), -INT8_C(  81),  INT8_C(  29), -INT8_C( 108),  INT8_C(  57),  INT8_C(  72),      INT8_MAX, -INT8_C(  80),
           INT8_C(  10),  INT8_C( 118),  INT8_C(   8), -INT8_C( 110),  INT8_C(  50), -INT8_C(  99),  INT8_C(  69), -INT8_C(  23) },
        { -INT8_C(  50), -INT8_C(  87),  INT8_C(  50), -INT8_C(  75), -INT8_C(  74),  INT8_C(  75),  INT8_C(  61),  INT8_C(  74),
          -INT8_C(  14),  INT8_C(  60),  INT8_C(  11), -INT8_C(  84), -INT8_C( 114),  INT8_C(  25),  INT8_C(  13),  INT8_C( 111) },
        { -INT16_C(   140),  INT16_C(  7080),  INT16_C(    88),  INT16_C(  9240), -INT16_C(  5700), -INT16_C(  2475),  INT16_C(   897), -INT16_C(  2553) } },
      { { -INT8_C(  28), -INT8_C(   9), -INT8_C(  58),  INT8_C(  58), -INT8_C(  74), -INT8_C(  30),  INT8_C(  90),  INT8_C(  31),
          -INT8_C( 103), -INT8_C(  52), -INT8_C( 109),  INT8_C(  57), -INT8_C(  64),  INT8_C(  40), -INT8_C( 101), -INT8_C(   4) },
        { -INT8_C(  24),  INT8_C(  64),  INT8_C( 106), -INT8_C(  93), -INT8_C(  76), -INT8_C(  40), -INT8_C(  16), -INT8_C(  75),
           INT8_C(  27), -INT8_C(  77),  INT8_C( 106), -INT8_C(  76), -INT8_C(  34), -INT8_C( 126), -INT8_C(  75), -INT8_C(  83) },
        { -INT16_C(  2781),  INT16_C(  4004), -INT16_C( 11554), -INT16_C(  4332),  INT16_C(  2176), -INT16_C(  5040),  INT16_C(  7575),  INT16_C(   332) } },
      { {  INT8_C( 118),  INT8_C(  31),  INT8_C(  47),  INT8_C(  39),  INT8_C(  85),  INT8_C(  29), -INT8_C(  44),  INT8_C(  23),
          -INT8_C(  97), -INT8_C(  30), -INT8_C(  48),  INT8_C( 118),  INT8_C( 112),  INT8_C(  61),  INT8_C(  68),  INT8_C(  80) },
        {  INT8_C(  91), -INT8_C(  13), -INT8_C(  97), -INT8_C(  58), -INT8_C(  54), -INT8_C(  88),      INT8_MAX,  INT8_C(  38),
           INT8_C(  90), -INT8_C(  48),  INT8_C(  49),  INT8_C(  63), -INT8_C(  79), -INT8_C(   9),  INT8_C(  28), -INT8_C(  99) },
        { -INT16_C(  8730),  INT16_C(  1440), -INT16_C(  2352),  INT16_C(  7434), -INT16_C(  8848), -INT16_C(   549),  INT16_C(  1904), -INT16_C(  7920) } },
      { {  INT8_C(  54),  INT8_C(  66),  INT8_C( 125),  INT8_C(  42),  INT8_C( 100), -INT8_C(  49),  INT8_C(  24), -INT8_C(  98),
           INT8_C(  46),  INT8_C(   4),  INT8_C(  83),  INT8_C(  82), -INT8_C(  47),  INT8_C(  66), -INT8_C(  80), -INT8_C(  33) },
        {  INT8_C( 115),  INT8_C(  59), -INT8_C(  57), -INT8_C(  41), -INT8_C(  37), -INT8_C( 102),  INT8_C(  43),  INT8_C(  62),
           INT8_C(  94),  INT8_C( 114), -INT8_C( 117), -INT8_C( 106), -INT8_C(  86), -INT8_C(  54),  INT8_C(  37), -INT8_C( 121) },
        {  INT16_C(  4324),  INT16_C(   456), -INT16_C(  9711), -INT16_C(  8692),  INT16_C(  4042), -INT16_C(  3564), -INT16_C(  2960),  INT16_C(  3993) } },
      { {  INT8_C(  24), -INT8_C(  37), -INT8_C( 119),  INT8_C(  40), -INT8_C(  50), -INT8_C(  95), -INT8_C( 127), -INT8_C(  84),
          -INT8_C(  43),  INT8_C(  66), -INT8_C( 121),  INT8_C(  79),  INT8_C( 105), -INT8_C(  75),  INT8_C(  81),  INT8_C(  49) },
        { -INT8_C(  24),  INT8_C(  47), -INT8_C(  24), -INT8_C( 102), -INT8_C(   6), -INT8_C(  40), -INT8_C(  97),  INT8_C( 121),
          -INT8_C( 121),  INT8_C( 109),  INT8_C(   5), -INT8_C(  37), -INT8_C(  80), -INT8_C(  50),  INT8_C(  28), -INT8_C( 109) },
        {  INT16_C(  5203),  INT16_C(  7194), -INT16_C(   605), -INT16_C(  2923), -INT16_C(  8400),  INT16_C(  3750),  INT16_C(  2268), -INT16_C(  5341) } },
      { {  INT8_C(  93),  INT8_C(  44), -INT8_C(   3), -INT8_C(  28), -INT8_C(  90), -INT8_C(  26),  INT8_C( 106), -INT8_C(  36),
           INT8_C( 102), -INT8_C(  72),  INT8_C(  43),  INT8_C(   4), -INT8_C(  84), -INT8_C(  34), -INT8_C(  57), -INT8_C(  31) },
        { -INT8_C(   3), -INT8_C(  78), -INT8_C(  13),  INT8_C(  95), -INT8_C(  62),  INT8_C( 115),  INT8_C( 120), -INT8_C( 102),
           INT8_C( 106), -INT8_C( 108), -INT8_C(  52),  INT8_C(  97), -INT8_C(  94), -INT8_C(  49), -INT8_C(  99),  INT8_C(  24) },
        {  INT16_C( 10812),  INT16_C(  7776), -INT16_C(  2236),  INT16_C(   388),  INT16_C(  7896),  INT16_C(  1666),  INT16_C(  5643), -INT16_C(   744) } },
      { {  INT8_C( 120),  INT8_C(  34), -INT8_C(  21),  INT8_C(  58),  INT8_C(  65), -INT8_C(  13),  INT8_C( 120), -INT8_C( 105),
           INT8_C(  54),  INT8_C(  84),  INT8_C(  74),  INT8_C(  62),  INT8_C( 110),  INT8_C(   8), -INT8_C( 121), -INT8_C(  72) },
        {  INT8_C(  42),  INT8_C(  24),  INT8_C(  37), -INT8_C(   3),  INT8_C(  37),  INT8_C( 120),  INT8_C(  83), -INT8_C( 100),
          -INT8_C(  50),  INT8_C(  67),  INT8_C( 105), -INT8_C( 107), -INT8_C( 124), -INT8_C( 123),  INT8_C(   4),  INT8_C( 111) },
        { -INT16_C(  2700),  INT16_C(  5628),  INT16_C(  7770), -INT16_C(  6634), -INT16_C( 13640), -INT16_C(   984), -INT16_C(   484), -INT16_C(  7992) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t b = simde_wasm_v128_load(test_vec[i].b);
      simde_v128_t r = simde_wasm_i16x8_extmul_high_i8x16(a, b);
      simde_test_wasm_i16x8_assert_equal(r, simde_wasm_v128_load(test_vec[i].r));
    }
    return 0;
  #else
    fputc('\n', stdout);
    for (int i = 0 ; i < 8 ; i++) {
      simde_v128_t
        a = simde_test_wasm_i8x16_random(),
        b = simde_test_wasm_i8x16_random(),
        r;

      r = simde_wasm_i16x8_extmul_high_i8x16(a, b);

      simde_test_wasm_i8x16_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_i8x16_write(3, b, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_wasm_i16x8_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_i32x4_extmul_high_i16x8(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      int16_t a[sizeof(simde_v128_t) / sizeof(int8_t)];
      int16_t b[sizeof(simde_v128_t) / sizeof(int8_t)];
      int32_t r[sizeof(simde_v128_t) / sizeof(int8_t)];
    } test_vec[] = {
      { {  INT16_C( 11556),  INT16_C( 18972), -INT16_C( 25692), -INT16_C( 29986),  INT16_C( 30896),  INT16_C(  6863), -INT16_C( 17921),  INT16_C(  2775) },
        { -INT16_C( 18974), -INT16_C( 21652), -INT16_C(  7396),  INT16_C( 17596),  INT16_C( 13868), -INT16_C( 18540),  INT16_C(  7252), -INT16_C( 13064) },
        {  INT32_C(   428465728), -INT32_C(   127240020), -INT32_C(   129963092), -INT32_C(    36252600) } },
      { {  INT16_C( 23996),  INT16_C(  7469), -INT16_C(     3),  INT16_C( 11222), -INT16_C(  3905), -INT16_C( 32373),  INT16_C( 22658), -INT16_C( 29729) },
        { -INT16_C(  5322), -INT16_C(  1234),  INT16_C( 30821), -INT16_C( 19409), -INT16_C( 12799), -INT16_C(  8783),  INT16_C(  1354), -INT16_C( 11420) },
        {  INT32_C(    49980095),  INT32_C(   284332059),  INT32_C(    30678932),  INT32_C(   339505180) } },
      { {  INT16_C(  7866),  INT16_C( 11089), -INT16_C( 25579), -INT16_C( 23189), -INT16_C(  9760), -INT16_C( 27292), -INT16_C( 11004),  INT16_C( 10099) },
        {  INT16_C( 21152),  INT16_C( 17380), -INT16_C( 24701),  INT16_C( 14121), -INT16_C(   651),  INT16_C(  4904),  INT16_C( 21874), -INT16_C(  1738) },
        {  INT32_C(     6353760), -INT32_C(   133839968), -INT32_C(   240701496), -INT32_C(    17552062) } },
      { {  INT16_C( 19383),  INT16_C( 17327),  INT16_C( 19788),  INT16_C( 14307), -INT16_C(  1771), -INT16_C(  1576), -INT16_C(  5456),  INT16_C( 19352) },
        { -INT16_C( 24124),  INT16_C( 24876), -INT16_C( 16255), -INT16_C( 29211), -INT16_C( 20184), -INT16_C( 30771), -INT16_C( 26172), -INT16_C( 29818) },
        {  INT32_C(    35745864),  INT32_C(    48495096),  INT32_C(   142794432), -INT32_C(   577037936) } },
      { {  INT16_C( 22917),  INT16_C( 29047), -INT16_C( 26282), -INT16_C( 13112),  INT16_C( 25141),  INT16_C( 23912),  INT16_C(  6727),  INT16_C( 10123) },
        {  INT16_C(  7859),  INT16_C( 24665),  INT16_C( 16817),  INT16_C( 10243),  INT16_C( 17848),  INT16_C(  4499), -INT16_C( 23630),  INT16_C( 20530) },
        {  INT32_C(   448716568),  INT32_C(   107580088), -INT32_C(   158959010),  INT32_C(   207825190) } },
      { { -INT16_C( 23937),  INT16_C( 16920), -INT16_C( 20215),  INT16_C( 27140),  INT16_C(  5415),  INT16_C(  7594),  INT16_C(  3524),  INT16_C( 32444) },
        { -INT16_C( 22261),  INT16_C( 32096),  INT16_C( 15930),  INT16_C( 23903), -INT16_C(  3646), -INT16_C( 25769), -INT16_C( 22388),  INT16_C(  7581) },
        { -INT32_C(    19743090), -INT32_C(   195689786), -INT32_C(    78895312),  INT32_C(   245957964) } },
      { {  INT16_C( 12391), -INT16_C( 31253), -INT16_C(  4960),  INT16_C(  9858),  INT16_C( 13976),  INT16_C( 25814),  INT16_C( 27272), -INT16_C(  1202) },
        {  INT16_C( 18310), -INT16_C( 21173), -INT16_C( 15075),  INT16_C(  7545), -INT16_C( 20912), -INT16_C(   976), -INT16_C( 10645), -INT16_C(  6165) },
        { -INT32_C(   292266112), -INT32_C(    25194464), -INT32_C(   290310440),  INT32_C(     7410330) } },
      { {  INT16_C(  1719), -INT16_C( 28059), -INT16_C( 17024), -INT16_C( 27063), -INT16_C( 20433), -INT16_C( 11049),  INT16_C( 13053),  INT16_C(  1305) },
        {  INT16_C( 12054), -INT16_C( 26334), -INT16_C( 28230),  INT16_C(  8780), -INT16_C( 23338),  INT16_C( 25663),  INT16_C( 30870),  INT16_C( 23492) },
        {  INT32_C(   476865354), -INT32_C(   283550487),  INT32_C(   402946110),  INT32_C(    30657060) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t b = simde_wasm_v128_load(test_vec[i].b);
      simde_v128_t r = simde_wasm_i32x4_extmul_high_i16x8(a, b);
      simde_test_wasm_i32x4_assert_equal(r, simde_wasm_v128_load(test_vec[i].r));
    }
    return 0;
  #else
    fputc('\n', stdout);
    for (int i = 0 ; i < 8 ; i++) {
      simde_v128_t
        a = simde_test_wasm_i8x16_random(),
        b = simde_test_wasm_i8x16_random(),
        r;

      r = simde_wasm_i32x4_extmul_high_i16x8(a, b);

      simde_test_wasm_i16x8_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_i16x8_write(3, b, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_wasm_i32x4_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_i64x2_extmul_high_i32x4(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      int32_t a[sizeof(simde_v128_t) / sizeof(int32_t)];
      int32_t b[sizeof(simde_v128_t) / sizeof(int32_t)];
      int64_t r[sizeof(simde_v128_t) / sizeof(int64_t)];
    } test_vec[] = {
      { { -INT32_C(  1147524132),  INT32_C(  1438575212), -INT32_C(   635185330), -INT32_C(   889945413) },
        { -INT32_C(  1557745228), -INT32_C(  1211521038), -INT32_C(  1860285217), -INT32_C(  1981732157) },
        {  INT64_C( 1181625879454266610),  INT64_C( 1763633442916745841) } },
      { {  INT32_C(   838477086), -INT32_C(  1759944233), -INT32_C(   306673737), -INT32_C(  1371896602) },
        {  INT32_C(   163759166), -INT32_C(  1395273018),  INT32_C(  1227408505), -INT32_C(  1134152278) },
        { -INT64_C(  376413953053933185),  INT64_C( 1555939656338759356) } },
      { {  INT32_C(   431180173),  INT32_C(  1067999139),  INT32_C(  1673041639), -INT32_C(   891300251) },
        { -INT32_C(  1386109345), -INT32_C(   337920482),  INT32_C(  1729059267), -INT32_C(   332563941) },
        {  INT64_C( 2892788149989818613),  INT64_C(  296414324086849191) } },
      { { -INT32_C(   916748791),  INT32_C(    51496400), -INT32_C(   335208167), -INT32_C(   380952652) },
        {  INT32_C(   807341863), -INT32_C(    13247403),  INT32_C(  1770828639), -INT32_C(   956331818) },
        { -INT64_C(  593596222150294713),  INT64_C(  364317142259081336) } },
      { { -INT32_C(  1579978114), -INT32_C(  2011457057), -INT32_C(  1608250887), -INT32_C(  1314982636) },
        { -INT32_C(   766330629), -INT32_C(  1790510646),  INT32_C(  2119946136), -INT32_C(  1262991414) },
        { -INT64_C( 3409405253614222632),  INT64_C( 1660811778827087304) } },
      { { -INT32_C(  1710923695),  INT32_C(   576835244), -INT32_C(   186551053), -INT32_C(   918484158) },
        { -INT32_C(   854968393), -INT32_C(    85474453),  INT32_C(  1084307561), -INT32_C(  1080761457) },
        { -INT64_C(  202278717280411733),  INT64_C(  992662276831498206) } },
      { {  INT32_C(  1579614017),  INT32_C(   444240579),  INT32_C(   795854067),  INT32_C(  2012667820) },
        {  INT32_C(   554654041),  INT32_C(   626907352), -INT32_C(   574306558), -INT32_C(   201575591) },
        { -INT64_C(  457064209889071386), -INT64_C(  405704705303181620) } },
      { { -INT32_C(   646679341),  INT32_C(  1924011065),  INT32_C(  1493374384), -INT32_C(   999957459) },
        { -INT32_C(   362675931),  INT32_C(   868240879), -INT32_C(   741287726),  INT32_C(  1104914035) },
        { -INT64_C( 1107020101182010784), -INT64_C( 1104867030852037065) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t b = simde_wasm_v128_load(test_vec[i].b);
      simde_v128_t r = simde_wasm_i64x2_extmul_high_i32x4(a, b);
      simde_test_wasm_i64x2_assert_equal(r, simde_wasm_v128_load(test_vec[i].r));
    }
    return 0;
  #else
    fputc('\n', stdout);
    for (int i = 0 ; i < 8 ; i++) {
      simde_v128_t
        a = simde_test_wasm_i32x4_random(),
        b = simde_test_wasm_i32x4_random(),
        r;

      r = simde_wasm_i64x2_extmul_high_i32x4(a, b);

      simde_test_wasm_i32x4_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_i32x4_write(3, b, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_wasm_i64x2_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_u16x8_extmul_high_u8x16(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      uint8_t a[sizeof(simde_v128_t) / sizeof(int8_t)];
      uint8_t b[sizeof(simde_v128_t) / sizeof(int8_t)];
      uint16_t r[sizeof(simde_v128_t) / sizeof(int8_t)];
    } test_vec[] = {
      { { UINT8_C(187), UINT8_C(161), UINT8_C( 11), UINT8_C(132), UINT8_C(  1), UINT8_C(168), UINT8_C(173), UINT8_C(231),
          UINT8_C(177), UINT8_C(122), UINT8_C(215), UINT8_C(135), UINT8_C( 95), UINT8_C(197), UINT8_C( 94), UINT8_C(247) },
        { UINT8_C(160), UINT8_C(214), UINT8_C(189), UINT8_C(176), UINT8_C( 61), UINT8_C( 50), UINT8_C( 59), UINT8_C( 35),
          UINT8_C( 70), UINT8_C( 71), UINT8_C( 93), UINT8_C( 22), UINT8_C(130), UINT8_C( 86), UINT8_C(118), UINT8_C( 11) },
        { UINT16_C(12390), UINT16_C( 8662), UINT16_C(19995), UINT16_C( 2970), UINT16_C(12350), UINT16_C(16942), UINT16_C(11092), UINT16_C( 2717) } },
      { { UINT8_C( 99), UINT8_C(134), UINT8_C( 10), UINT8_C( 94), UINT8_C( 21), UINT8_C( 99), UINT8_C(222), UINT8_C(226),
          UINT8_C( 85), UINT8_C(144), UINT8_C(210), UINT8_C(182), UINT8_C(159), UINT8_C( 18), UINT8_C(242), UINT8_C(206) },
        { UINT8_C( 82), UINT8_C( 64), UINT8_C(103), UINT8_C( 46), UINT8_C( 28), UINT8_C(238), UINT8_C(222), UINT8_C(207),
          UINT8_C(150), UINT8_C(135), UINT8_C(159), UINT8_C(139), UINT8_C(248), UINT8_C(214), UINT8_C(197), UINT8_C( 78) },
        { UINT16_C(12750), UINT16_C(19440), UINT16_C(33390), UINT16_C(25298), UINT16_C(39432), UINT16_C( 3852), UINT16_C(47674), UINT16_C(16068) } },
      { { UINT8_C(118), UINT8_C(101), UINT8_C(124), UINT8_C(137), UINT8_C(165), UINT8_C( 61), UINT8_C(  8), UINT8_C( 15),
          UINT8_C(108), UINT8_C(159), UINT8_C( 82), UINT8_C( 71), UINT8_C( 34), UINT8_C(146), UINT8_C(178), UINT8_C( 95) },
        { UINT8_C(203), UINT8_C(248), UINT8_C(160), UINT8_C(168), UINT8_C( 32), UINT8_C( 16), UINT8_C(118), UINT8_C( 12),
             UINT8_MAX, UINT8_C(178),    UINT8_MAX, UINT8_C( 26), UINT8_C(253), UINT8_C( 37), UINT8_C( 37), UINT8_C(179) },
        { UINT16_C(27540), UINT16_C(28302), UINT16_C(20910), UINT16_C( 1846), UINT16_C( 8602), UINT16_C( 5402), UINT16_C( 6586), UINT16_C(17005) } },
      { { UINT8_C(169), UINT8_C(240), UINT8_C(127), UINT8_C( 79), UINT8_C( 10), UINT8_C(118), UINT8_C(213), UINT8_C(189),
          UINT8_C( 88), UINT8_C( 93), UINT8_C(136), UINT8_C( 23), UINT8_C(  5), UINT8_C( 92), UINT8_C( 77), UINT8_C( 66) },
        { UINT8_C(229), UINT8_C(138), UINT8_C(103), UINT8_C(178), UINT8_C(  2), UINT8_C(176), UINT8_C(187), UINT8_C(  8),
          UINT8_C(235), UINT8_C( 33), UINT8_C( 77), UINT8_C(124), UINT8_C(120), UINT8_C(135), UINT8_C(  5), UINT8_C(127) },
        { UINT16_C(20680), UINT16_C( 3069), UINT16_C(10472), UINT16_C( 2852), UINT16_C(  600), UINT16_C(12420), UINT16_C(  385), UINT16_C( 8382) } },
      { { UINT8_C( 44), UINT8_C( 21), UINT8_C(184), UINT8_C( 10), UINT8_C( 96), UINT8_C( 97), UINT8_C(123), UINT8_C(176),
          UINT8_C( 27), UINT8_C(191), UINT8_C(190), UINT8_C(110), UINT8_C(212), UINT8_C( 55), UINT8_C(249), UINT8_C(216) },
        { UINT8_C( 16), UINT8_C(191), UINT8_C(252), UINT8_C( 88), UINT8_C(243), UINT8_C(173), UINT8_C(  1), UINT8_C( 71),
          UINT8_C( 48), UINT8_C( 87), UINT8_C( 87), UINT8_C(167), UINT8_C( 37), UINT8_C(144), UINT8_C(153), UINT8_C( 12) },
        { UINT16_C( 1296), UINT16_C(16617), UINT16_C(16530), UINT16_C(18370), UINT16_C( 7844), UINT16_C( 7920), UINT16_C(38097), UINT16_C( 2592) } },
      { { UINT8_C( 70), UINT8_C(222), UINT8_C( 34), UINT8_C(212), UINT8_C( 74), UINT8_C(169), UINT8_C( 56), UINT8_C(192),
          UINT8_C( 74), UINT8_C(184), UINT8_C(128), UINT8_C(137), UINT8_C(177), UINT8_C(194), UINT8_C( 78), UINT8_C(198) },
        { UINT8_C(169), UINT8_C( 53), UINT8_C(102), UINT8_C(141), UINT8_C( 27), UINT8_C(179), UINT8_C(112), UINT8_C(254),
          UINT8_C(192), UINT8_C(128), UINT8_C(210), UINT8_C( 35), UINT8_C(115), UINT8_C( 20), UINT8_C(117), UINT8_C( 13) },
        { UINT16_C(14208), UINT16_C(23552), UINT16_C(26880), UINT16_C( 4795), UINT16_C(20355), UINT16_C( 3880), UINT16_C( 9126), UINT16_C( 2574) } },
      { { UINT8_C( 96), UINT8_C(193), UINT8_C( 85), UINT8_C(181), UINT8_C( 55), UINT8_C( 29), UINT8_C( 78), UINT8_C(250),
          UINT8_C(128), UINT8_C(105), UINT8_C( 71), UINT8_C(170), UINT8_C(243), UINT8_C( 27), UINT8_C(163), UINT8_C(251) },
        { UINT8_C(203), UINT8_C(116), UINT8_C(130), UINT8_C( 25), UINT8_C(158), UINT8_C(195), UINT8_C(193), UINT8_C(246),
          UINT8_C(220), UINT8_C( 98), UINT8_C(199), UINT8_C(212), UINT8_C(236), UINT8_C(133), UINT8_C(170), UINT8_C( 75) },
        { UINT16_C(28160), UINT16_C(10290), UINT16_C(14129), UINT16_C(36040), UINT16_C(57348), UINT16_C( 3591), UINT16_C(27710), UINT16_C(18825) } },
      { { UINT8_C(154), UINT8_C(124), UINT8_C( 86), UINT8_C( 79), UINT8_C( 34), UINT8_C(242), UINT8_C(126), UINT8_C( 59),
          UINT8_C( 81), UINT8_C(218), UINT8_C(166), UINT8_C(170), UINT8_C( 78), UINT8_C(  6), UINT8_C(233), UINT8_C( 43) },
        { UINT8_C(163), UINT8_C(130), UINT8_C(142), UINT8_C(  8), UINT8_C( 33), UINT8_C( 56), UINT8_C(124), UINT8_C(233),
          UINT8_C(198), UINT8_C(214), UINT8_C(125), UINT8_C( 72), UINT8_C( 20), UINT8_C(225), UINT8_C( 94), UINT8_C(229) },
        { UINT16_C(16038), UINT16_C(46652), UINT16_C(20750), UINT16_C(12240), UINT16_C( 1560), UINT16_C( 1350), UINT16_C(21902), UINT16_C( 9847) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t b = simde_wasm_v128_load(test_vec[i].b);
      simde_v128_t r = simde_wasm_u16x8_extmul_high_u8x16(a, b);
      simde_test_wasm_u16x8_assert_equal(r, simde_wasm_v128_load(test_vec[i].r));
    }
    return 0;
  #else
    fputc('\n', stdout);
    for (int i = 0 ; i < 8 ; i++) {
      simde_v128_t
        a = simde_test_wasm_u8x16_random(),
        b = simde_test_wasm_u8x16_random(),
        r;

      r = simde_wasm_u16x8_extmul_high_u8x16(a, b);

      simde_test_wasm_u8x16_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_u8x16_write(3, b, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_wasm_u16x8_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_u32x4_extmul_high_u16x8(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      uint16_t a[sizeof(simde_v128_t) / sizeof(int8_t)];
      uint16_t b[sizeof(simde_v128_t) / sizeof(int8_t)];
      uint32_t r[sizeof(simde_v128_t) / sizeof(int8_t)];
    } test_vec[] = {
      { { UINT16_C(60274), UINT16_C(12236), UINT16_C( 6634), UINT16_C(46798), UINT16_C(40078), UINT16_C(51984), UINT16_C(64186), UINT16_C( 3670) },
        { UINT16_C( 8153), UINT16_C(38179), UINT16_C(47417), UINT16_C(53410), UINT16_C(35113), UINT16_C(42443), UINT16_C( 1450), UINT16_C(56431) },
        { UINT32_C(1407258814), UINT32_C(2206356912), UINT32_C(  93069700), UINT32_C( 207101770) } },
      { { UINT16_C(29229), UINT16_C(27635), UINT16_C(64320), UINT16_C(60951), UINT16_C(30664), UINT16_C(40170), UINT16_C(53048), UINT16_C( 3816) },
        { UINT16_C(55619), UINT16_C(26093), UINT16_C(24596), UINT16_C(18311), UINT16_C(  761), UINT16_C(52545), UINT16_C(32595), UINT16_C(  693) },
        { UINT32_C(  23335304), UINT32_C(2110732650), UINT32_C(1729099560), UINT32_C(   2644488) } },
      { { UINT16_C(51875), UINT16_C( 9829), UINT16_C(39038), UINT16_C(19771), UINT16_C(  700), UINT16_C(17241), UINT16_C(22959), UINT16_C(12840) },
        { UINT16_C(54749), UINT16_C( 3134), UINT16_C(46363), UINT16_C(12765), UINT16_C(22596), UINT16_C(55825), UINT16_C(39825), UINT16_C(44740) },
        { UINT32_C(  15817200), UINT32_C( 962478825), UINT32_C( 914342175), UINT32_C( 574461600) } },
      { { UINT16_C(34345), UINT16_C( 2187), UINT16_C(37678), UINT16_C(14855), UINT16_C(52689), UINT16_C(56225), UINT16_C(18687), UINT16_C(14044) },
        { UINT16_C( 8394), UINT16_C(58728), UINT16_C(61325), UINT16_C(32867), UINT16_C(32766), UINT16_C(55461), UINT16_C(26064), UINT16_C(29077) },
        { UINT32_C(1726407774), UINT32_C(3118294725), UINT32_C( 487057968), UINT32_C( 408357388) } },
      { { UINT16_C(40378), UINT16_C(38791), UINT16_C(42298), UINT16_C(33761), UINT16_C(23336), UINT16_C(19343), UINT16_C(10024), UINT16_C(50872) },
        { UINT16_C(32790), UINT16_C( 1265), UINT16_C(42016), UINT16_C( 8323), UINT16_C( 8773), UINT16_C(27163), UINT16_C(33245), UINT16_C(20439) },
        { UINT32_C( 204726728), UINT32_C( 525413909), UINT32_C( 333247880), UINT32_C(1039772808) } },
      { { UINT16_C(61910), UINT16_C(52101), UINT16_C( 3188), UINT16_C(25924), UINT16_C(33752), UINT16_C(49454), UINT16_C(45619), UINT16_C(27724) },
        { UINT16_C(44874), UINT16_C(35746), UINT16_C(64069), UINT16_C(49038), UINT16_C(48472), UINT16_C( 1462), UINT16_C(13716), UINT16_C(28558) },
        { UINT32_C(1636026944), UINT32_C(  72301748), UINT32_C( 625710204), UINT32_C( 791741992) } },
      { { UINT16_C(18394), UINT16_C( 9617), UINT16_C(32676), UINT16_C( 3786), UINT16_C(20649), UINT16_C(42998), UINT16_C(41882), UINT16_C(61786) },
        { UINT16_C( 8335), UINT16_C(33309), UINT16_C(20988), UINT16_C( 3973), UINT16_C(16150), UINT16_C(42449), UINT16_C(   11), UINT16_C(14903) },
        { UINT32_C( 333481350), UINT32_C(1825222102), UINT32_C(    460702), UINT32_C( 920796758) } },
      { { UINT16_C(53213), UINT16_C(19431), UINT16_C(38671), UINT16_C(43434), UINT16_C(23888), UINT16_C( 6787), UINT16_C(65079), UINT16_C(19398) },
        { UINT16_C(15167), UINT16_C(12271), UINT16_C(30486), UINT16_C(37975), UINT16_C(10488), UINT16_C( 1620), UINT16_C(41530), UINT16_C( 2160) },
        { UINT32_C( 250537344), UINT32_C(  10994940), UINT32_C(2702730870), UINT32_C(  41899680) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t b = simde_wasm_v128_load(test_vec[i].b);
      simde_v128_t r = simde_wasm_u32x4_extmul_high_u16x8(a, b);
      simde_test_wasm_u32x4_assert_equal(r, simde_wasm_v128_load(test_vec[i].r));
    }
    return 0;
  #else
    fputc('\n', stdout);
    for (int i = 0 ; i < 8 ; i++) {
      simde_v128_t
        a = simde_test_wasm_u8x16_random(),
        b = simde_test_wasm_u8x16_random(),
        r;

      r = simde_wasm_u32x4_extmul_high_u16x8(a, b);

      simde_test_wasm_u16x8_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_u16x8_write(3, b, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_wasm_u32x4_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_u64x2_extmul_high_u32x4(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      uint32_t a[sizeof(simde_v128_t) / sizeof(uint32_t)];
      uint32_t b[sizeof(simde_v128_t) / sizeof(uint32_t)];
      uint64_t r[sizeof(simde_v128_t) / sizeof(uint64_t)];
    } test_vec[] = {
      { { UINT32_C(1282470454), UINT32_C( 640013568), UINT32_C(2968860272), UINT32_C( 573247804) },
        { UINT32_C( 842628432), UINT32_C(1861205742), UINT32_C( 508693003), UINT32_C(3831934771) },
        { UINT64_C( 1510238447251076816), UINT64_C( 2196648192546992884) } },
      { { UINT32_C(3785809068), UINT32_C(4019285441), UINT32_C(2606702930), UINT32_C(2389529259) },
        { UINT32_C(1182950945), UINT32_C(3489519104), UINT32_C(3988354986), UINT32_C(1131589746) },
        { UINT64_C(10396456627886308980), UINT64_C( 2703966807251378214) } },
      { { UINT32_C(3152304238), UINT32_C(2237848626), UINT32_C( 473825045), UINT32_C( 820045786) },
        { UINT32_C(2279471520), UINT32_C(  19028570), UINT32_C(3560206590), UINT32_C(1362846853) },
        { UINT64_C( 1686915047716046550), UINT64_C( 1117596818766011458) } },
      { { UINT32_C(2382196760), UINT32_C(1735479533), UINT32_C(3339295067), UINT32_C(2187245422) },
        { UINT32_C(3156210099), UINT32_C(3827742160), UINT32_C(2131933361), UINT32_C(1975175600) },
        { UINT64_C( 7119154555560030187), UINT64_C( 4320193788746103200) } },
      { { UINT32_C(2852694154), UINT32_C( 389247943), UINT32_C( 786324085), UINT32_C(4042519688) },
        { UINT32_C(3914458832), UINT32_C(2404713197), UINT32_C(3869195852), UINT32_C(3950152991) },
        { UINT64_C( 3042441888009695420), UINT64_C(15968571236729586808) } },
      { { UINT32_C(2568887892), UINT32_C(3798348965), UINT32_C(3642017191), UINT32_C(4251534719) },
        { UINT32_C(2670338330), UINT32_C(3588921737), UINT32_C(4270349119), UINT32_C(2797337182) },
        { UINT64_C(15552684902969704729), UINT64_C(11892976150022621858) } },
      { { UINT32_C( 697836186), UINT32_C( 574559703), UINT32_C(3110041071), UINT32_C(3848105234) },
        { UINT32_C(3474390800), UINT32_C(1207965408), UINT32_C(4038166889), UINT32_C(2996329552) },
        { UINT64_C(12558864876342298119), UINT64_C(11530191431840075168) } },
      { { UINT32_C(  47207036), UINT32_C(4279956205), UINT32_C( 426808142), UINT32_C(3234430755) },
        { UINT32_C( 497927598), UINT32_C(3087198250), UINT32_C(3315572766), UINT32_C( 486601380) },
        { UINT64_C( 1415113451922260772), UINT64_C( 1573878468897441900) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t b = simde_wasm_v128_load(test_vec[i].b);
      simde_v128_t r = simde_wasm_u64x2_extmul_high_u32x4(a, b);
      simde_test_wasm_u64x2_assert_equal(r, simde_wasm_v128_load(test_vec[i].r));
    }
    return 0;
  #else
    fputc('\n', stdout);
    for (int i = 0 ; i < 8 ; i++) {
      simde_v128_t
        a = simde_test_wasm_u32x4_random(),
        b = simde_test_wasm_u32x4_random(),
        r;

      r = simde_wasm_u64x2_extmul_high_u32x4(a, b);

      simde_test_wasm_u32x4_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_u32x4_write(3, b, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_wasm_u64x2_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_i16x8_extmul_high_i8x16)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_i32x4_extmul_high_i16x8)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_i64x2_extmul_high_i32x4)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_u16x8_extmul_high_u8x16)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_u32x4_extmul_high_u16x8)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_u64x2_extmul_high_u32x4)
SIMDE_TEST_FUNC_LIST_END

#include "test-simd128-footer.h"
