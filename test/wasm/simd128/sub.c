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

#define SIMDE_TEST_WASM_SIMD128_INSN sub
#include "../../../simde/wasm/simd128.h"
#include "test-simd128.h"

static int
test_simde_wasm_i8x16_sub(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      int8_t a[sizeof(simde_v128_t) / sizeof(int8_t)];
      int8_t b[sizeof(simde_v128_t) / sizeof(int8_t)];
      int8_t r[sizeof(simde_v128_t) / sizeof(int8_t)];
    } test_vec[] = {
      { {  INT8_C(  14), -INT8_C(  71), -INT8_C(  97), -INT8_C(  72),  INT8_C(  62), -INT8_C(  79), -INT8_C(  95),  INT8_C( 110),
           INT8_C( 126), -INT8_C(  14), -INT8_C(  48), -INT8_C(  58),  INT8_C(  18), -INT8_C( 127),  INT8_C(   1), -INT8_C(   2) },
        {  INT8_C(  44), -INT8_C(  22), -INT8_C(  39), -INT8_C(  50),  INT8_C(  88), -INT8_C(  98), -INT8_C(  62),  INT8_C(  32),
          -INT8_C( 125), -INT8_C( 113), -INT8_C(   3),  INT8_C(  79),  INT8_C(  99), -INT8_C(  98), -INT8_C(  64), -INT8_C(  67) },
        { -INT8_C(  30), -INT8_C(  49), -INT8_C(  58), -INT8_C(  22), -INT8_C(  26),  INT8_C(  19), -INT8_C(  33),  INT8_C(  78),
          -INT8_C(   5),  INT8_C(  99), -INT8_C(  45),  INT8_C( 119), -INT8_C(  81), -INT8_C(  29),  INT8_C(  65),  INT8_C(  65) } },
      { {  INT8_C(  22),  INT8_C(  28), -INT8_C(  38),  INT8_C(  74),  INT8_C(  55),  INT8_C( 121),  INT8_C( 111),  INT8_C(  18),
          -INT8_C(  75), -INT8_C(  17), -INT8_C(  36), -INT8_C(  15),  INT8_C(  17), -INT8_C(  79), -INT8_C( 109), -INT8_C( 105) },
        {  INT8_C(  35), -INT8_C( 123), -INT8_C(  85), -INT8_C(  37),  INT8_C(  42), -INT8_C(  66), -INT8_C(  55),  INT8_C(  29),
          -INT8_C( 116), -INT8_C(  22), -INT8_C(  26), -INT8_C(  24),  INT8_C(   3), -INT8_C(  91), -INT8_C(  12),  INT8_C(  76) },
        { -INT8_C(  13), -INT8_C( 105),  INT8_C(  47),  INT8_C( 111),  INT8_C(  13), -INT8_C(  69), -INT8_C(  90), -INT8_C(  11),
           INT8_C(  41),  INT8_C(   5), -INT8_C(  10),  INT8_C(   9),  INT8_C(  14),  INT8_C(  12), -INT8_C(  97),  INT8_C(  75) } },
      { {  INT8_C(  34), -INT8_C(  37), -INT8_C(  38), -INT8_C(  24), -INT8_C(  40),  INT8_C(  60), -INT8_C(  56),  INT8_C( 123),
          -INT8_C(  77), -INT8_C(  81),  INT8_C(  53), -INT8_C(  20),  INT8_C(  61), -INT8_C(  60),  INT8_C(  81), -INT8_C(  62) },
        {  INT8_C( 118), -INT8_C(   3),  INT8_C(  37),  INT8_C(  30),  INT8_C(  75),  INT8_C(  34),  INT8_C( 116),  INT8_C(  16),
          -INT8_C(  99), -INT8_C(  36), -INT8_C(  77), -INT8_C(  64),  INT8_C(  32),  INT8_C(  28), -INT8_C(   8), -INT8_C(  53) },
        { -INT8_C(  84), -INT8_C(  34), -INT8_C(  75), -INT8_C(  54), -INT8_C( 115),  INT8_C(  26),  INT8_C(  84),  INT8_C( 107),
           INT8_C(  22), -INT8_C(  45), -INT8_C( 126),  INT8_C(  44),  INT8_C(  29), -INT8_C(  88),  INT8_C(  89), -INT8_C(   9) } },
      { { -INT8_C( 106),  INT8_C(  99),  INT8_C( 125), -INT8_C(  23), -INT8_C(  48), -INT8_C(  94), -INT8_C(  24), -INT8_C( 109),
           INT8_C(  94),  INT8_C(  29),  INT8_C(  95),  INT8_C( 116),  INT8_C(  79),  INT8_C(  70), -INT8_C( 117),  INT8_C( 125) },
        { -INT8_C( 114), -INT8_C(  60), -INT8_C(   8),  INT8_C(  93),  INT8_C(  51), -INT8_C(  74), -INT8_C( 107), -INT8_C(   7),
           INT8_C(  52), -INT8_C(  65),  INT8_C(  72), -INT8_C(  42), -INT8_C( 102),  INT8_C(   9),  INT8_C( 121), -INT8_C( 101) },
        {  INT8_C(   8), -INT8_C(  97), -INT8_C( 123), -INT8_C( 116), -INT8_C(  99), -INT8_C(  20),  INT8_C(  83), -INT8_C( 102),
           INT8_C(  42),  INT8_C(  94),  INT8_C(  23), -INT8_C(  98), -INT8_C(  75),  INT8_C(  61),  INT8_C(  18), -INT8_C(  30) } },
      { { -INT8_C(  10),  INT8_C( 123),  INT8_C(  43),  INT8_C(   9), -INT8_C(  56), -INT8_C( 125),  INT8_C(  80), -INT8_C(  79),
           INT8_C(  68), -INT8_C(  55), -INT8_C(  95), -INT8_C( 118), -INT8_C( 114),  INT8_C(  88), -INT8_C(   5), -INT8_C( 120) },
        { -INT8_C(  39),  INT8_C(  49),  INT8_C(  99),  INT8_C(  59), -INT8_C(  44), -INT8_C(  41), -INT8_C(  93),  INT8_C(  50),
           INT8_C(  19),  INT8_C(  14), -INT8_C( 126),  INT8_C(  87),  INT8_C(  16),  INT8_C(  56),  INT8_C(  26),  INT8_C(  72) },
        {  INT8_C(  29),  INT8_C(  74), -INT8_C(  56), -INT8_C(  50), -INT8_C(  12), -INT8_C(  84), -INT8_C(  83),      INT8_MAX,
           INT8_C(  49), -INT8_C(  69),  INT8_C(  31),  INT8_C(  51),  INT8_C( 126),  INT8_C(  32), -INT8_C(  31),  INT8_C(  64) } },
      { {  INT8_C(  26),  INT8_C(  57),  INT8_C(  71),  INT8_C(  50), -INT8_C(  60),  INT8_C(  75), -INT8_C(  29),  INT8_C(  82),
           INT8_C(  47), -INT8_C(  66), -INT8_C(  49),  INT8_C(  30), -INT8_C( 109), -INT8_C(  10),  INT8_C(  58),  INT8_C(  14) },
        { -INT8_C(  58),  INT8_C(  54),  INT8_C(  99), -INT8_C(  65), -INT8_C(  66),  INT8_C( 124), -INT8_C( 110), -INT8_C(  17),
          -INT8_C( 111), -INT8_C(   8), -INT8_C(  63),  INT8_C(   5),  INT8_C(  99),  INT8_C(  71), -INT8_C(  85), -INT8_C(  32) },
        {  INT8_C(  84),  INT8_C(   3), -INT8_C(  28),  INT8_C( 115),  INT8_C(   6), -INT8_C(  49),  INT8_C(  81),  INT8_C(  99),
          -INT8_C(  98), -INT8_C(  58),  INT8_C(  14),  INT8_C(  25),  INT8_C(  48), -INT8_C(  81), -INT8_C( 113),  INT8_C(  46) } },
      { { -INT8_C(  30),  INT8_C( 121),  INT8_C(  20), -INT8_C(  47),  INT8_C(   8), -INT8_C(  26),  INT8_C( 125),  INT8_C(  96),
           INT8_C(  55), -INT8_C(  42), -INT8_C( 105),  INT8_C(  67), -INT8_C( 118), -INT8_C(  65), -INT8_C(  64), -INT8_C(  68) },
        {  INT8_C(  47), -INT8_C( 102),  INT8_C(  93),  INT8_C( 109), -INT8_C(  61), -INT8_C(  35),  INT8_C(  44),  INT8_C(  61),
           INT8_C( 110),  INT8_C( 121), -INT8_C(  14),  INT8_C(  43), -INT8_C(  66),  INT8_C(  41), -INT8_C(  22), -INT8_C(  41) },
        { -INT8_C(  77), -INT8_C(  33), -INT8_C(  73),  INT8_C( 100),  INT8_C(  69),  INT8_C(   9),  INT8_C(  81),  INT8_C(  35),
          -INT8_C(  55),  INT8_C(  93), -INT8_C(  91),  INT8_C(  24), -INT8_C(  52), -INT8_C( 106), -INT8_C(  42), -INT8_C(  27) } },
      { {  INT8_C( 100), -INT8_C(  41),  INT8_C(  34), -INT8_C(  96),  INT8_C( 125),  INT8_C(  35),  INT8_C(  14), -INT8_C(  21),
           INT8_C(  88), -INT8_C( 109),  INT8_C(  76), -INT8_C(  40), -INT8_C(   9),  INT8_C(  59),  INT8_C(  93),  INT8_C(  99) },
        {  INT8_C(  86), -INT8_C(  85),  INT8_C(  72), -INT8_C(  51),  INT8_C(  25), -INT8_C( 102), -INT8_C(  16),      INT8_MIN,
           INT8_C(  37), -INT8_C(  16),  INT8_C(  30),  INT8_C(  11),  INT8_C(  16),  INT8_C(  45), -INT8_C(  71),  INT8_C( 101) },
        {  INT8_C(  14),  INT8_C(  44), -INT8_C(  38), -INT8_C(  45),  INT8_C( 100), -INT8_C( 119),  INT8_C(  30),  INT8_C( 107),
           INT8_C(  51), -INT8_C(  93),  INT8_C(  46), -INT8_C(  51), -INT8_C(  25),  INT8_C(  14), -INT8_C(  92), -INT8_C(   2) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t b = simde_wasm_v128_load(test_vec[i].b);
      simde_v128_t r = simde_wasm_i8x16_sub(a, b);
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

      r = simde_wasm_i8x16_sub(a, b);

      simde_test_wasm_i8x16_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_i8x16_write(3, b, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_wasm_i8x16_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_i16x8_sub(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      int16_t a[sizeof(simde_v128_t) / sizeof(int16_t)];
      int16_t b[sizeof(simde_v128_t) / sizeof(int16_t)];
      int16_t r[sizeof(simde_v128_t) / sizeof(int16_t)];
    } test_vec[] = {
      { {  INT16_C(  9125), -INT16_C(  1733), -INT16_C( 25714),  INT16_C( 27705),  INT16_C( 30594), -INT16_C( 17619), -INT16_C( 23045),  INT16_C(  6453) },
        {  INT16_C( 30800),  INT16_C( 32090),  INT16_C( 24827),  INT16_C( 30059),  INT16_C( 13760), -INT16_C( 12942), -INT16_C( 30698),  INT16_C( 25563) },
        { -INT16_C( 21675),  INT16_C( 31713),  INT16_C( 14995), -INT16_C(  2354),  INT16_C( 16834), -INT16_C(  4677),  INT16_C(  7653), -INT16_C( 19110) } },
      { {  INT16_C( 23497), -INT16_C( 23349),  INT16_C(  6545), -INT16_C( 32659), -INT16_C(  9939),  INT16_C( 31030),  INT16_C( 11280), -INT16_C( 11461) },
        { -INT16_C( 29957), -INT16_C( 16591),  INT16_C(  4818), -INT16_C( 21997),  INT16_C( 13610), -INT16_C(  5431),  INT16_C( 23518), -INT16_C( 21200) },
        { -INT16_C( 12082), -INT16_C(  6758),  INT16_C(  1727), -INT16_C( 10662), -INT16_C( 23549), -INT16_C( 29075), -INT16_C( 12238),  INT16_C(  9739) } },
      { {  INT16_C(  7877),  INT16_C(  8909), -INT16_C( 32088),  INT16_C( 11132),  INT16_C( 15725),  INT16_C( 31078), -INT16_C( 16045), -INT16_C( 30424) },
        {  INT16_C(  5745), -INT16_C( 29825),  INT16_C( 28882), -INT16_C( 30814),  INT16_C(   516),  INT16_C(  9146),  INT16_C( 14021), -INT16_C(   658) },
        {  INT16_C(  2132), -INT16_C( 26802),  INT16_C(  4566), -INT16_C( 23590),  INT16_C( 15209),  INT16_C( 21932), -INT16_C( 30066), -INT16_C( 29766) } },
      { { -INT16_C( 23147), -INT16_C( 32204),  INT16_C( 15139), -INT16_C( 27457),  INT16_C( 11140), -INT16_C( 21106),  INT16_C( 23110), -INT16_C( 11266) },
        { -INT16_C( 18437),  INT16_C(  6964),  INT16_C( 15647), -INT16_C( 15119),  INT16_C( 28405), -INT16_C(  5599),  INT16_C(  9469),  INT16_C( 20318) },
        { -INT16_C(  4710),  INT16_C( 26368), -INT16_C(   508), -INT16_C( 12338), -INT16_C( 17265), -INT16_C( 15507),  INT16_C( 13641), -INT16_C( 31584) } },
      { {  INT16_C( 15340), -INT16_C( 21031),  INT16_C(  3940),  INT16_C( 18087), -INT16_C( 31245), -INT16_C( 15975), -INT16_C( 17906),  INT16_C(  1788) },
        { -INT16_C( 22909), -INT16_C(  1749), -INT16_C(  6287),  INT16_C( 27986),  INT16_C(  8832),  INT16_C( 20778),  INT16_C( 12947), -INT16_C( 17260) },
        { -INT16_C( 27287), -INT16_C( 19282),  INT16_C( 10227), -INT16_C(  9899),  INT16_C( 25459),  INT16_C( 28783), -INT16_C( 30853),  INT16_C( 19048) } },
      { {  INT16_C( 13673),  INT16_C( 14051), -INT16_C( 26559), -INT16_C(  4641),  INT16_C( 24850), -INT16_C( 13225), -INT16_C( 19141), -INT16_C( 10470) },
        {  INT16_C( 28299), -INT16_C( 27821), -INT16_C( 21193),  INT16_C( 24688),  INT16_C( 13652),  INT16_C( 32223),  INT16_C( 29421), -INT16_C(  9299) },
        { -INT16_C( 14626), -INT16_C( 23664), -INT16_C(  5366), -INT16_C( 29329),  INT16_C( 11198),  INT16_C( 20088),  INT16_C( 16974), -INT16_C(  1171) } },
      { {  INT16_C( 25417), -INT16_C( 23116),  INT16_C(  9448), -INT16_C( 26396),  INT16_C( 23326),  INT16_C( 31947), -INT16_C(   501),  INT16_C( 30473) },
        {  INT16_C(  9880),  INT16_C( 17499),  INT16_C( 18230),  INT16_C( 19105),  INT16_C( 16674), -INT16_C( 28628), -INT16_C( 31283), -INT16_C( 24823) },
        {  INT16_C( 15537),  INT16_C( 24921), -INT16_C(  8782),  INT16_C( 20035),  INT16_C(  6652), -INT16_C(  4961),  INT16_C( 30782), -INT16_C( 10240) } },
      { {  INT16_C(  3739),  INT16_C( 20051),  INT16_C(  7746),  INT16_C( 29986),  INT16_C( 29391), -INT16_C( 15118),  INT16_C( 26153),  INT16_C( 13479) },
        {  INT16_C(  9774), -INT16_C(  6435),  INT16_C(  2995),  INT16_C( 10955), -INT16_C(   531),  INT16_C(  7795), -INT16_C( 24103), -INT16_C( 18682) },
        { -INT16_C(  6035),  INT16_C( 26486),  INT16_C(  4751),  INT16_C( 19031),  INT16_C( 29922), -INT16_C( 22913), -INT16_C( 15280),  INT16_C( 32161) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t b = simde_wasm_v128_load(test_vec[i].b);
      simde_v128_t r = simde_wasm_i16x8_sub(a, b);
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

      r = simde_wasm_i16x8_sub(a, b);

      simde_test_wasm_i16x8_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_i16x8_write(3, b, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_wasm_i16x8_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_i32x4_sub(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      int32_t a[sizeof(simde_v128_t) / sizeof(int32_t)];
      int32_t b[sizeof(simde_v128_t) / sizeof(int32_t)];
      int32_t r[sizeof(simde_v128_t) / sizeof(int32_t)];
    } test_vec[] = {
      { { -INT32_C(  1755878415),  INT32_C(   311096534),  INT32_C(   269638250), -INT32_C(  1811895564) },
        { -INT32_C(   469221827),  INT32_C(  1287034896),  INT32_C(   345002209),  INT32_C(  1824200858) },
        { -INT32_C(  1286656588), -INT32_C(   975938362), -INT32_C(    75363959),  INT32_C(   658870874) } },
      { { -INT32_C(   833383017),  INT32_C(   431324203), -INT32_C(   259959724), -INT32_C(    70995137) },
        { -INT32_C(  1026724331), -INT32_C(   873531150),  INT32_C(   795339937),  INT32_C(    20013056) },
        {  INT32_C(   193341314),  INT32_C(  1304855353), -INT32_C(  1055299661), -INT32_C(    91008193) } },
      { {  INT32_C(  1975516735), -INT32_C(  1803951956),  INT32_C(  1207207973), -INT32_C(  1035573864) },
        {  INT32_C(   847715804), -INT32_C(  1910879004), -INT32_C(   386899170), -INT32_C(  1876715420) },
        {  INT32_C(  1127800931),  INT32_C(   106927048),  INT32_C(  1594107143),  INT32_C(   841141556) } },
      { {  INT32_C(   275083325), -INT32_C(  1492910069), -INT32_C(    45623236), -INT32_C(   554246395) },
        { -INT32_C(  1624583812), -INT32_C(   942018954), -INT32_C(   541147159),  INT32_C(  1798607630) },
        {  INT32_C(  1899667137), -INT32_C(   550891115),  INT32_C(   495523923),  INT32_C(  1942113271) } },
      { {  INT32_C(  1984722994), -INT32_C(   763733212),  INT32_C(   734608335), -INT32_C(   161921969) },
        {  INT32_C(  1072259100), -INT32_C(   216392217), -INT32_C(   787572987), -INT32_C(    39102412) },
        {  INT32_C(   912463894), -INT32_C(   547340995),  INT32_C(  1522181322), -INT32_C(   122819557) } },
      { { -INT32_C(  1591580604), -INT32_C(  1324320674), -INT32_C(   905473918),  INT32_C(   210241211) },
        { -INT32_C(  1570262514),  INT32_C(  1509695043),  INT32_C(    22063417),  INT32_C(   582103679) },
        { -INT32_C(    21318090),  INT32_C(  1460951579), -INT32_C(   927537335), -INT32_C(   371862468) } },
      { { -INT32_C(   131676466),  INT32_C(   899991442), -INT32_C(   451414153), -INT32_C(  1809143977) },
        { -INT32_C(  1101141180),  INT32_C(   170191365),  INT32_C(   741601000),  INT32_C(   235613711) },
        {  INT32_C(   969464714),  INT32_C(   729800077), -INT32_C(  1193015153), -INT32_C(  2044757688) } },
      { {  INT32_C(   597051287),  INT32_C(  1826165097),  INT32_C(  1164159459),  INT32_C(   384631734) },
        {  INT32_C(  2143694659),  INT32_C(  1553682496), -INT32_C(   181390498), -INT32_C(  1504761602) },
        { -INT32_C(  1546643372),  INT32_C(   272482601),  INT32_C(  1345549957),  INT32_C(  1889393336) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t b = simde_wasm_v128_load(test_vec[i].b);
      simde_v128_t r = simde_wasm_i32x4_sub(a, b);
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

      r = simde_wasm_i32x4_sub(a, b);

      simde_test_wasm_i32x4_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_i32x4_write(3, b, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_wasm_i32x4_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_i64x2_sub(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      int64_t a[sizeof(simde_v128_t) / sizeof(int64_t)];
      int64_t b[sizeof(simde_v128_t) / sizeof(int64_t)];
      int64_t r[sizeof(simde_v128_t) / sizeof(int64_t)];
    } test_vec[] = {
      { { -INT64_C( 5209445112599918977),  INT64_C( 5657673659120504095) },
        { -INT64_C( 1285604808924017002),  INT64_C( 7253137771388416165) },
        { -INT64_C( 3923840303675901975), -INT64_C( 1595464112267912070) } },
      { { -INT64_C( 8019158734919910984), -INT64_C( 4026698805523918786) },
        {  INT64_C( 2462559267718365377), -INT64_C( 5689112007374463780) },
        {  INT64_C( 7965026071071275255),  INT64_C( 1662413201850544994) } },
      { { -INT64_C( 4290266974481831051),  INT64_C(  316711147957763099) },
        {  INT64_C( 2520334621405552563), -INT64_C( 4037685659854845438) },
        { -INT64_C( 6810601595887383614),  INT64_C( 4354396807812608537) } },
      { {  INT64_C( 4015944209538690333),  INT64_C( 1222955501585895411) },
        {  INT64_C( 6536716613803399098),  INT64_C( 1272210822684162131) },
        { -INT64_C( 2520772404264708765), -INT64_C(   49255321098266720) } },
      { {  INT64_C( 2169592518765237763), -INT64_C( 6240739788851867281) },
        {  INT64_C( 8696660381767492599),  INT64_C(  493601628807016208) },
        { -INT64_C( 6527067863002254836), -INT64_C( 6734341417658883489) } },
      { { -INT64_C( 4605934033818176621), -INT64_C( 2764404330071085758) },
        { -INT64_C( 1353312292757520562), -INT64_C( 8286351568382700836) },
        { -INT64_C( 3252621741060656059),  INT64_C( 5521947238311615078) } },
      { { -INT64_C( 5286011289018778106),  INT64_C( 1805425782566733362) },
        { -INT64_C( 1584978591545563939), -INT64_C( 2954061750102967673) },
        { -INT64_C( 3701032697473214167),  INT64_C( 4759487532669701035) } },
      { { -INT64_C( 6239324875922547815), -INT64_C( 1304076530637794897) },
        { -INT64_C( 2235295758905442836), -INT64_C( 4435714263299585432) },
        { -INT64_C( 4004029117017104979),  INT64_C( 3131637732661790535) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t b = simde_wasm_v128_load(test_vec[i].b);
      simde_v128_t r = simde_wasm_i64x2_sub(a, b);
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

      r = simde_wasm_i64x2_sub(a, b);

      simde_test_wasm_i64x2_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_i64x2_write(3, b, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_wasm_i64x2_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_f32x4_sub(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      simde_float32 a[sizeof(simde_v128_t) / sizeof(simde_float32)];
      simde_float32 b[sizeof(simde_v128_t) / sizeof(simde_float32)];
      simde_float32 r[sizeof(simde_v128_t) / sizeof(simde_float32)];
    } test_vec[] = {
      #if !defined(SIMDE_FAST_MATH)
      { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -547.51),            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -687.45) },
        { SIMDE_FLOAT32_C(  -307.36),            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -687.45) },
        {            SIMDE_MATH_NANF,            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(     0.00) } },
      #endif
      { { SIMDE_FLOAT32_C(    30.67), SIMDE_FLOAT32_C(  -820.46), SIMDE_FLOAT32_C(   899.06), SIMDE_FLOAT32_C(  -703.72) },
        { SIMDE_FLOAT32_C(   715.69), SIMDE_FLOAT32_C(  -315.43), SIMDE_FLOAT32_C(  -199.30), SIMDE_FLOAT32_C(  -646.32) },
        { SIMDE_FLOAT32_C(  -685.02), SIMDE_FLOAT32_C(  -505.03), SIMDE_FLOAT32_C(  1098.36), SIMDE_FLOAT32_C(   -57.40) } },
      { { SIMDE_FLOAT32_C(  -852.85), SIMDE_FLOAT32_C(  -790.85), SIMDE_FLOAT32_C(  -516.78), SIMDE_FLOAT32_C(   764.55) },
        { SIMDE_FLOAT32_C(  -268.85), SIMDE_FLOAT32_C(  -215.03), SIMDE_FLOAT32_C(   775.07), SIMDE_FLOAT32_C(  -244.18) },
        { SIMDE_FLOAT32_C(  -584.00), SIMDE_FLOAT32_C(  -575.82), SIMDE_FLOAT32_C( -1291.85), SIMDE_FLOAT32_C(  1008.73) } },
      { { SIMDE_FLOAT32_C(   167.69), SIMDE_FLOAT32_C(  -992.85), SIMDE_FLOAT32_C(   762.09), SIMDE_FLOAT32_C(   677.00) },
        { SIMDE_FLOAT32_C(  -917.76), SIMDE_FLOAT32_C(  -597.84), SIMDE_FLOAT32_C(   567.12), SIMDE_FLOAT32_C(  -558.44) },
        { SIMDE_FLOAT32_C(  1085.45), SIMDE_FLOAT32_C(  -395.01), SIMDE_FLOAT32_C(   194.97), SIMDE_FLOAT32_C(  1235.44) } },
      { { SIMDE_FLOAT32_C(   873.92), SIMDE_FLOAT32_C(   -36.94), SIMDE_FLOAT32_C(  -262.23), SIMDE_FLOAT32_C(  -684.69) },
        { SIMDE_FLOAT32_C(  -757.90), SIMDE_FLOAT32_C(  -828.14), SIMDE_FLOAT32_C(  -131.84), SIMDE_FLOAT32_C(   664.87) },
        { SIMDE_FLOAT32_C(  1631.82), SIMDE_FLOAT32_C(   791.20), SIMDE_FLOAT32_C(  -130.39), SIMDE_FLOAT32_C( -1349.56) } },
      { { SIMDE_FLOAT32_C(  -504.90), SIMDE_FLOAT32_C(  -760.29), SIMDE_FLOAT32_C(   987.53), SIMDE_FLOAT32_C(  -938.78) },
        { SIMDE_FLOAT32_C(  -885.44), SIMDE_FLOAT32_C(   760.27), SIMDE_FLOAT32_C(   870.98), SIMDE_FLOAT32_C(    59.33) },
        { SIMDE_FLOAT32_C(   380.54), SIMDE_FLOAT32_C( -1520.56), SIMDE_FLOAT32_C(   116.55), SIMDE_FLOAT32_C(  -998.11) } },
      { { SIMDE_FLOAT32_C(   485.38), SIMDE_FLOAT32_C(   327.90), SIMDE_FLOAT32_C(   744.88), SIMDE_FLOAT32_C(   374.00) },
        { SIMDE_FLOAT32_C(   936.06), SIMDE_FLOAT32_C(   189.44), SIMDE_FLOAT32_C(   640.02), SIMDE_FLOAT32_C(  -558.82) },
        { SIMDE_FLOAT32_C(  -450.68), SIMDE_FLOAT32_C(   138.46), SIMDE_FLOAT32_C(   104.86), SIMDE_FLOAT32_C(   932.82) } },
      { { SIMDE_FLOAT32_C(  -251.58), SIMDE_FLOAT32_C(   381.88), SIMDE_FLOAT32_C(  -889.17), SIMDE_FLOAT32_C(   712.61) },
        { SIMDE_FLOAT32_C(  -732.55), SIMDE_FLOAT32_C(  -399.30), SIMDE_FLOAT32_C(  -771.16), SIMDE_FLOAT32_C(   113.29) },
        { SIMDE_FLOAT32_C(   480.97), SIMDE_FLOAT32_C(   781.18), SIMDE_FLOAT32_C(  -118.01), SIMDE_FLOAT32_C(   599.32) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t b = simde_wasm_v128_load(test_vec[i].b);
      simde_v128_t r = simde_wasm_f32x4_sub(a, b);
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

      r = simde_wasm_f32x4_sub(a, b);

      simde_test_wasm_f32x4_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_f32x4_write(3, b, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_wasm_f32x4_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_f64x2_sub(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      simde_float64 a[sizeof(simde_v128_t) / sizeof(simde_float64)];
      simde_float64 b[sizeof(simde_v128_t) / sizeof(simde_float64)];
      simde_float64 r[sizeof(simde_v128_t) / sizeof(simde_float64)];
    } test_vec[] = {
      #if !defined(SIMDE_FAST_MATH)
      { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   -18.71) },
        { SIMDE_FLOAT64_C(   672.42),             SIMDE_MATH_NAN },
        {             SIMDE_MATH_NAN,             SIMDE_MATH_NAN } },
      { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   -94.70) },
        {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(    66.70) },
        {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -161.40) } },
      #endif
      { { SIMDE_FLOAT64_C(   330.65), SIMDE_FLOAT64_C(  -349.96) },
        { SIMDE_FLOAT64_C(   941.11), SIMDE_FLOAT64_C(   387.33) },
        { SIMDE_FLOAT64_C(  -610.46), SIMDE_FLOAT64_C(  -737.29) } },
      { { SIMDE_FLOAT64_C(   445.49), SIMDE_FLOAT64_C(   219.49) },
        { SIMDE_FLOAT64_C(   468.04), SIMDE_FLOAT64_C(  -566.03) },
        { SIMDE_FLOAT64_C(   -22.55), SIMDE_FLOAT64_C(   785.52) } },
      { { SIMDE_FLOAT64_C(  -654.80), SIMDE_FLOAT64_C(  -329.12) },
        { SIMDE_FLOAT64_C(   228.37), SIMDE_FLOAT64_C(   280.71) },
        { SIMDE_FLOAT64_C(  -883.17), SIMDE_FLOAT64_C(  -609.83) } },
      { { SIMDE_FLOAT64_C(   238.61), SIMDE_FLOAT64_C(  -631.87) },
        { SIMDE_FLOAT64_C(   747.68), SIMDE_FLOAT64_C(    58.66) },
        { SIMDE_FLOAT64_C(  -509.07), SIMDE_FLOAT64_C(  -690.53) } },
      { { SIMDE_FLOAT64_C(     1.11), SIMDE_FLOAT64_C(   441.37) },
        { SIMDE_FLOAT64_C(   963.71), SIMDE_FLOAT64_C(  -829.28) },
        { SIMDE_FLOAT64_C(  -962.60), SIMDE_FLOAT64_C(  1270.65) } },
      { { SIMDE_FLOAT64_C(  -760.68), SIMDE_FLOAT64_C(   226.70) },
        { SIMDE_FLOAT64_C(   858.39), SIMDE_FLOAT64_C(   156.54) },
        { SIMDE_FLOAT64_C( -1619.07), SIMDE_FLOAT64_C(    70.16) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t b = simde_wasm_v128_load(test_vec[i].b);
      simde_v128_t r = simde_wasm_f64x2_sub(a, b);
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

      r = simde_wasm_f64x2_sub(a, b);

      simde_test_wasm_f64x2_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_f64x2_write(3, b, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_wasm_f64x2_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_i8x16_sub)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_i16x8_sub)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_i32x4_sub)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_i64x2_sub)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_f32x4_sub)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_f64x2_sub)
SIMDE_TEST_FUNC_LIST_END

#include "test-simd128-footer.h"
