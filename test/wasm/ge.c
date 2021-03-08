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
test_simde_wasm_i8x16_ge(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      int8_t a[sizeof(simde_v128_t) / sizeof(int8_t)];
      int8_t b[sizeof(simde_v128_t) / sizeof(int8_t)];
      int8_t r[sizeof(simde_v128_t) / sizeof(int8_t)];
    } test_vec[8] = {
      { { -INT8_C( 114),  INT8_C( 120),  INT8_C( 102), -INT8_C( 106), -INT8_C(  53),  INT8_C(  20), -INT8_C(  28),  INT8_C(  40),
           INT8_C(  60), -INT8_C(  79), -INT8_C(  46),  INT8_C(  61),  INT8_C(   7), -INT8_C(  44), -INT8_C(  88),  INT8_C(  82) },
        { -INT8_C( 112),  INT8_C( 120),  INT8_C(  12), -INT8_C( 104), -INT8_C(  53),  INT8_C( 114), -INT8_C(  54),  INT8_C(  40),
          -INT8_C(   2), -INT8_C(  38),      INT8_MAX, -INT8_C(  25),  INT8_C(  98),  INT8_C( 126),  INT8_C(  49),  INT8_C(   1) },
        {  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
          -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1) } },
      { {  INT8_C(  84), -INT8_C(  65),  INT8_C( 106), -INT8_C(  21),  INT8_C(  94),  INT8_C(   8),  INT8_C(   6), -INT8_C(  56),
          -INT8_C(  20), -INT8_C(  63),  INT8_C( 122),  INT8_C(  79),  INT8_C(  37),  INT8_C(  79), -INT8_C(   9),  INT8_C(  88) },
        {  INT8_C(  84), -INT8_C(  92),  INT8_C(  89), -INT8_C(  21),  INT8_C(  94),  INT8_C(   8),  INT8_C(   6), -INT8_C(  56),
          -INT8_C(  20), -INT8_C(  63),      INT8_MAX,  INT8_C(  79),  INT8_C(  20),  INT8_C(  66),  INT8_C(   7),  INT8_C(  61) },
        { -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
          -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1) } },
      { { -INT8_C(  96),  INT8_C(  24),  INT8_C(  87),  INT8_C(  74), -INT8_C( 115), -INT8_C( 108),  INT8_C(  94), -INT8_C(  92),
           INT8_C(  25), -INT8_C(  33), -INT8_C( 125), -INT8_C( 124), -INT8_C( 127),  INT8_C(  79),  INT8_C( 105), -INT8_C(  99) },
        { -INT8_C( 101),  INT8_C(  24),  INT8_C(  87),  INT8_C(  73), -INT8_C( 115), -INT8_C( 109),  INT8_C(  61),  INT8_C( 123),
           INT8_C(  25), -INT8_C(  50),  INT8_C(  21),  INT8_C(  89), -INT8_C( 127),  INT8_C(  13),  INT8_C(  11), -INT8_C(   1) },
        { -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
          -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0) } },
      { {  INT8_C(  29), -INT8_C( 110), -INT8_C(  71), -INT8_C(  14), -INT8_C(  77), -INT8_C( 121), -INT8_C(  67),  INT8_C(  84),
           INT8_C( 126), -INT8_C(  54), -INT8_C(  62), -INT8_C( 100),  INT8_C(  80),  INT8_C(  90), -INT8_C(  26),  INT8_C(  14) },
        {  INT8_C(  29), -INT8_C(  42),  INT8_C(  52),  INT8_C( 122),  INT8_C(  64), -INT8_C( 121), -INT8_C(  14),  INT8_C(  84),
          -INT8_C(  40), -INT8_C( 127), -INT8_C( 123), -INT8_C( 100),  INT8_C( 112),  INT8_C(  75), -INT8_C(   9),  INT8_C(  14) },
        { -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
          -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1) } },
      { {  INT8_C( 114), -INT8_C(   7),  INT8_C(  69), -INT8_C(  67),  INT8_C( 116), -INT8_C(  75),  INT8_C(  47),  INT8_C(  53),
           INT8_C(  37),  INT8_C(  52), -INT8_C(   5),  INT8_C(  59), -INT8_C(  93), -INT8_C(  94),  INT8_C(  34), -INT8_C(  84) },
        {  INT8_C( 114),  INT8_C( 109), -INT8_C(  46),  INT8_C(  63),  INT8_C( 116), -INT8_C(  17),  INT8_C(  79), -INT8_C(  69),
           INT8_C(  28), -INT8_C(  74),  INT8_C(  60), -INT8_C(  97),  INT8_C(  39), -INT8_C(  94),  INT8_C( 121),  INT8_C(  27) },
        { -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
          -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0) } },
      { { -INT8_C(  77),  INT8_C(  96),  INT8_C(  88), -INT8_C(  21),  INT8_C( 120),  INT8_C( 103),  INT8_C(  39), -INT8_C(  84),
          -INT8_C(  50),  INT8_C(  84),  INT8_C( 100),  INT8_C(  34),  INT8_C( 104), -INT8_C( 110), -INT8_C( 110), -INT8_C(  52) },
        { -INT8_C(  77), -INT8_C(  41),  INT8_C(  88),  INT8_C(   2),  INT8_C(  40),  INT8_C( 106),      INT8_MAX,  INT8_C(  25),
          -INT8_C(  50),  INT8_C(  84),  INT8_C( 100),  INT8_C( 125),  INT8_C( 107), -INT8_C( 126), -INT8_C(  89), -INT8_C(  52) },
        { -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
          -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1) } },
      { { -INT8_C(  15), -INT8_C(  20), -INT8_C(  54), -INT8_C( 101),  INT8_C(  28),  INT8_C( 108), -INT8_C(  41),  INT8_C( 126),
           INT8_C(  53), -INT8_C( 119),  INT8_C(  42), -INT8_C(  15),  INT8_C(  29), -INT8_C(  62),  INT8_C(  80),  INT8_C(  65) },
        {  INT8_C( 101),  INT8_C(  74), -INT8_C(  54), -INT8_C(  14),  INT8_C( 102),  INT8_C( 108),  INT8_C(  89),  INT8_C( 126),
           INT8_C(  92), -INT8_C(  89), -INT8_C( 120),  INT8_C(   2), -INT8_C(  39), -INT8_C( 124), -INT8_C(  42), -INT8_C(  35) },
        {  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
           INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1) } },
      { {  INT8_C( 105),  INT8_C( 108), -INT8_C( 126), -INT8_C( 123), -INT8_C(  87),  INT8_C(  77),  INT8_C(  53), -INT8_C(  69),
          -INT8_C(  79),  INT8_C( 123), -INT8_C( 116), -INT8_C(  53), -INT8_C(  45), -INT8_C(  45),  INT8_C( 113), -INT8_C(  54) },
        {  INT8_C( 105),  INT8_C( 108), -INT8_C( 126), -INT8_C(  58),  INT8_C(  26),  INT8_C(  77),  INT8_C(  53),  INT8_C(  78),
          -INT8_C( 104),  INT8_C( 115),  INT8_C(  18), -INT8_C(  78), -INT8_C( 119), -INT8_C( 105),  INT8_C( 110), -INT8_C(  48) },
        { -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
          -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t b = simde_wasm_v128_load(test_vec[i].b);
      simde_v128_t r = simde_wasm_i8x16_ge(a, b);
      simde_test_wasm_i8x16_assert_equal(r, simde_wasm_v128_load(test_vec[i].r));
    }
    return 0;
  #else
    fputc('\n', stdout);
    for (int i = 0 ; i < 8 ; i++) {
      int8_t a_[sizeof(simde_v128_t) / sizeof(int8_t)];
      int8_t b_[sizeof(simde_v128_t) / sizeof(int8_t)];
      simde_v128_t a, b, r;

      simde_test_codegen_random_memory(sizeof(a_), HEDLEY_REINTERPRET_CAST(uint8_t*, a_));
      simde_test_codegen_random_memory(sizeof(b_), HEDLEY_REINTERPRET_CAST(uint8_t*, b_));
      for (size_t j = 0 ; j < (sizeof(a_) / sizeof(a_[0])) ; j++)
        if ((simde_test_codegen_random_i8() & 3) == 0)
          b_[j] = a_[j];

      a = simde_wasm_v128_load(a_);
      b = simde_wasm_v128_load(b_);
      r = simde_wasm_i8x16_ge(a, b);

      simde_test_wasm_i8x16_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_i8x16_write(3, b, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_wasm_i8x16_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_i16x8_ge(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      int16_t a[sizeof(simde_v128_t) / sizeof(int16_t)];
      int16_t b[sizeof(simde_v128_t) / sizeof(int16_t)];
      int16_t r[sizeof(simde_v128_t) / sizeof(int16_t)];
    } test_vec[8] = {
      { {  INT16_C( 11725),  INT16_C( 24936),  INT16_C( 12934), -INT16_C( 16336),  INT16_C( 19129), -INT16_C( 32508), -INT16_C( 23076),  INT16_C( 25154) },
        { -INT16_C( 12420), -INT16_C( 17783),  INT16_C( 12934), -INT16_C( 16336), -INT16_C( 19995),  INT16_C( 20793),  INT16_C(  2227),  INT16_C(  9508) },
        { -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1) } },
      { { -INT16_C( 16881),  INT16_C(  2723),  INT16_C(  8366),  INT16_C( 23065), -INT16_C( 25809), -INT16_C( 30443), -INT16_C(  8728), -INT16_C( 10607) },
        {  INT16_C( 14271), -INT16_C( 22283),  INT16_C(  8366), -INT16_C(  7430),  INT16_C(  4864),  INT16_C( 17421),  INT16_C( 31339), -INT16_C( 30487) },
        {  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1) } },
      { { -INT16_C(  4445),  INT16_C( 32294), -INT16_C( 15147),  INT16_C( 25392),  INT16_C(  5667),  INT16_C( 17960), -INT16_C( 10533),  INT16_C( 16981) },
        {  INT16_C( 10248),  INT16_C( 32294), -INT16_C( 15147),  INT16_C( 25392),  INT16_C( 25580),  INT16_C(  9846), -INT16_C( 10533),  INT16_C( 30297) },
        {  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0) } },
      { { -INT16_C(    41),  INT16_C( 14441), -INT16_C(  2471), -INT16_C( 29029),  INT16_C(  2449),  INT16_C( 15261), -INT16_C( 32419),  INT16_C( 21567) },
        {  INT16_C( 21699), -INT16_C(   668),  INT16_C( 30234), -INT16_C( 31879),  INT16_C(  2449), -INT16_C( 30557), -INT16_C( 10849), -INT16_C( 32511) },
        {  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1) } },
      { {  INT16_C(  4437),  INT16_C( 14136),  INT16_C( 17648),  INT16_C( 11230),  INT16_C( 19884),  INT16_C( 27619),  INT16_C( 14819),  INT16_C( 30807) },
        {  INT16_C( 30329), -INT16_C( 26168), -INT16_C( 25047), -INT16_C( 15698),  INT16_C( 31742),  INT16_C( 30382),  INT16_C( 27986), -INT16_C(  9962) },
        {  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1) } },
      { { -INT16_C( 22915),  INT16_C(  1502), -INT16_C( 14469), -INT16_C(  4908), -INT16_C( 16514), -INT16_C(  8169),  INT16_C(  6326), -INT16_C( 28573) },
        { -INT16_C( 30438),  INT16_C(  3012),  INT16_C( 28916),  INT16_C( 19108), -INT16_C( 24006),  INT16_C(  6555),  INT16_C(  6326),  INT16_C( 26077) },
        { -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0) } },
      { { -INT16_C( 19715),  INT16_C(  5131), -INT16_C( 23403), -INT16_C( 20400),  INT16_C(   403),  INT16_C( 23035),  INT16_C( 25580), -INT16_C( 16743) },
        {  INT16_C( 30223),  INT16_C(  5131), -INT16_C(  7711), -INT16_C( 29168),  INT16_C(   403),  INT16_C( 12205),  INT16_C( 13631), -INT16_C(  3279) },
        {  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0) } },
      { { -INT16_C(  8568),  INT16_C(  7575),  INT16_C( 18390),  INT16_C(   337),  INT16_C( 11525), -INT16_C( 28694),  INT16_C(  8394), -INT16_C( 27161) },
        { -INT16_C( 18497),  INT16_C( 17659), -INT16_C( 25142),  INT16_C( 21520),  INT16_C( 11525),  INT16_C( 32629),  INT16_C( 13897), -INT16_C( 27161) },
        { -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t b = simde_wasm_v128_load(test_vec[i].b);
      simde_v128_t r = simde_wasm_i16x8_ge(a, b);
      simde_test_wasm_i16x8_assert_equal(r, simde_wasm_v128_load(test_vec[i].r));
    }
    return 0;
  #else
    fputc('\n', stdout);
    for (int i = 0 ; i < 8 ; i++) {
      int16_t a_[sizeof(simde_v128_t) / sizeof(int16_t)];
      int16_t b_[sizeof(simde_v128_t) / sizeof(int16_t)];
      simde_v128_t a, b, r;

      simde_test_codegen_random_memory(sizeof(a_), HEDLEY_REINTERPRET_CAST(uint8_t*, a_));
      simde_test_codegen_random_memory(sizeof(b_), HEDLEY_REINTERPRET_CAST(uint8_t*, b_));
      for (size_t j = 0 ; j < (sizeof(a_) / sizeof(a_[0])) ; j++)
        if ((simde_test_codegen_random_i8() & 3) == 0)
          b_[j] = a_[j];

      a = simde_wasm_v128_load(a_);
      b = simde_wasm_v128_load(b_);
      r = simde_wasm_i16x8_ge(a, b);

      simde_test_wasm_i16x8_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_i16x8_write(3, b, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_wasm_i16x8_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_i32x4_ge(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      int32_t a[sizeof(simde_v128_t) / sizeof(int32_t)];
      int32_t b[sizeof(simde_v128_t) / sizeof(int32_t)];
      int32_t r[sizeof(simde_v128_t) / sizeof(int32_t)];
    } test_vec[8] = {
      { {  INT32_C(  1563764367), -INT32_C(   192680974), -INT32_C(   433890534), -INT32_C(  2116344322) },
        {  INT32_C(  1737277470), -INT32_C(  2085583342), -INT32_C(   558584023), -INT32_C(  2116344322) },
        {  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1) } },
      { { -INT32_C(    87913420),  INT32_C(   100678571), -INT32_C(   711238276), -INT32_C(  1330224250) },
        {  INT32_C(  1915520494),  INT32_C(   100678571), -INT32_C(   711238276), -INT32_C(  1490675883) },
        {  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1) } },
      { { -INT32_C(  1704628141),  INT32_C(   139384757), -INT32_C(  1767733950),  INT32_C(   571682331) },
        { -INT32_C(  1807120306),  INT32_C(  1405575992),  INT32_C(   186580124),  INT32_C(  1643453553) },
        { -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
      { {  INT32_C(  1246138047), -INT32_C(  1705324134), -INT32_C(  1918755975),  INT32_C(   416416741) },
        {  INT32_C(  1246138047),  INT32_C(   314189068),  INT32_C(   840027258),  INT32_C(   507946016) },
        { -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
      { { -INT32_C(   744756779), -INT32_C(   457653829),  INT32_C(  1172977109), -INT32_C(   386971850) },
        { -INT32_C(   794259015), -INT32_C(  2069079791),  INT32_C(  1585631834),  INT32_C(  1241017900) },
        { -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0) } },
      { {  INT32_C(   169883923), -INT32_C(  1442593172), -INT32_C(   219011721), -INT32_C(  1419959011) },
        {  INT32_C(  1488703365),  INT32_C(   170957844), -INT32_C(   219011721),  INT32_C(  1488183274) },
        {  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0) } },
      { {  INT32_C(   259333132),  INT32_C(   256533463),  INT32_C(  1747680799),  INT32_C(  1838665018) },
        {  INT32_C(  2089143102),  INT32_C(  1626932846),  INT32_C(  1368558445),  INT32_C(   769144822) },
        {  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1) } },
      { { -INT32_C(   636983005), -INT32_C(  1244379765),  INT32_C(  1963461661),  INT32_C(   435840283) },
        { -INT32_C(   546852663), -INT32_C(  1244379765),  INT32_C(  1963461661), -INT32_C(  1863015538) },
        {  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t b = simde_wasm_v128_load(test_vec[i].b);
      simde_v128_t r = simde_wasm_i32x4_ge(a, b);
      simde_test_wasm_i32x4_assert_equal(r, simde_wasm_v128_load(test_vec[i].r));
    }
    return 0;
  #else
    fputc('\n', stdout);
    for (int i = 0 ; i < 8 ; i++) {
      int32_t a_[sizeof(simde_v128_t) / sizeof(int32_t)];
      int32_t b_[sizeof(simde_v128_t) / sizeof(int32_t)];
      simde_v128_t a, b, r;

      simde_test_codegen_random_memory(sizeof(a_), HEDLEY_REINTERPRET_CAST(uint8_t*, a_));
      simde_test_codegen_random_memory(sizeof(b_), HEDLEY_REINTERPRET_CAST(uint8_t*, b_));
      for (size_t j = 0 ; j < (sizeof(a_) / sizeof(a_[0])) ; j++)
        if ((simde_test_codegen_random_i8() & 3) == 0)
          b_[j] = a_[j];

      a = simde_wasm_v128_load(a_);
      b = simde_wasm_v128_load(b_);
      r = simde_wasm_i32x4_ge(a, b);

      simde_test_wasm_i32x4_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_i32x4_write(3, b, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_wasm_i32x4_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_f32x4_ge(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      simde_float32 a[sizeof(simde_v128_t) / sizeof(simde_float32)];
      simde_float32 b[sizeof(simde_v128_t) / sizeof(simde_float32)];
      int32_t r[sizeof(simde_v128_t) / sizeof(simde_float32)];
    } test_vec[8] = {
      { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -472.04),            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -298.74) },
        { SIMDE_FLOAT32_C(   307.33),            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -298.74) },
        {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1) } },
      { { SIMDE_FLOAT32_C(   316.26), SIMDE_FLOAT32_C(   191.98), SIMDE_FLOAT32_C(  -821.53), SIMDE_FLOAT32_C(   -50.33) },
        { SIMDE_FLOAT32_C(   -58.08), SIMDE_FLOAT32_C(  -337.81), SIMDE_FLOAT32_C(  -541.78), SIMDE_FLOAT32_C(   633.09) },
        { -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0) } },
      { { SIMDE_FLOAT32_C(   146.40), SIMDE_FLOAT32_C(  -718.10), SIMDE_FLOAT32_C(  -374.92), SIMDE_FLOAT32_C(    87.85) },
        { SIMDE_FLOAT32_C(    36.98), SIMDE_FLOAT32_C(   631.02), SIMDE_FLOAT32_C(  -805.77), SIMDE_FLOAT32_C(   332.34) },
        { -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0) } },
      { { SIMDE_FLOAT32_C(   526.88), SIMDE_FLOAT32_C(  -255.87), SIMDE_FLOAT32_C(   821.84), SIMDE_FLOAT32_C(  -485.42) },
        { SIMDE_FLOAT32_C(   387.40), SIMDE_FLOAT32_C(  -820.18), SIMDE_FLOAT32_C(  -905.02), SIMDE_FLOAT32_C(   838.59) },
        { -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0) } },
      { { SIMDE_FLOAT32_C(  -564.46), SIMDE_FLOAT32_C(   312.48), SIMDE_FLOAT32_C(   525.02), SIMDE_FLOAT32_C(    16.27) },
        { SIMDE_FLOAT32_C(    23.74), SIMDE_FLOAT32_C(   455.29), SIMDE_FLOAT32_C(   126.16), SIMDE_FLOAT32_C(     0.70) },
        {  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1) } },
      { { SIMDE_FLOAT32_C(   997.91), SIMDE_FLOAT32_C(  -862.78), SIMDE_FLOAT32_C(   493.18), SIMDE_FLOAT32_C(  -535.26) },
        { SIMDE_FLOAT32_C(   739.57), SIMDE_FLOAT32_C(    19.93), SIMDE_FLOAT32_C(   214.79), SIMDE_FLOAT32_C(   578.47) },
        { -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0) } },
      { { SIMDE_FLOAT32_C(   -49.40), SIMDE_FLOAT32_C(  -613.17), SIMDE_FLOAT32_C(  -140.14), SIMDE_FLOAT32_C(   657.85) },
        { SIMDE_FLOAT32_C(   141.72), SIMDE_FLOAT32_C(   269.53), SIMDE_FLOAT32_C(   661.43), SIMDE_FLOAT32_C(  -741.14) },
        {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1) } },
      { { SIMDE_FLOAT32_C(   441.43), SIMDE_FLOAT32_C(   740.42), SIMDE_FLOAT32_C(  -418.55), SIMDE_FLOAT32_C(  -900.41) },
        { SIMDE_FLOAT32_C(  -909.70), SIMDE_FLOAT32_C(  -396.99), SIMDE_FLOAT32_C(  -345.32), SIMDE_FLOAT32_C(   444.46) },
        { -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t b = simde_wasm_v128_load(test_vec[i].b);
      simde_v128_t r = simde_wasm_f32x4_ge(a, b);
      simde_test_wasm_i32x4_assert_equal(r, simde_wasm_v128_load(test_vec[i].r));
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

      r = simde_wasm_f32x4_ge(a, b);

      simde_test_wasm_f32x4_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_f32x4_write(3, b, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_wasm_i32x4_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_f64x2_ge(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      simde_float64 a[sizeof(simde_v128_t) / sizeof(simde_float64)];
      simde_float64 b[sizeof(simde_v128_t) / sizeof(simde_float64)];
      int64_t r[sizeof(simde_v128_t) / sizeof(simde_float64)];
    } test_vec[8] = {
      { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(    -9.99) },
        { SIMDE_FLOAT64_C(   -55.80),             SIMDE_MATH_NAN },
        {  INT64_C(                   0),  INT64_C(                   0) } },
      { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   911.84) },
        {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   911.84) },
        {  INT64_C(                   0), -INT64_C(                   1) } },
      { { SIMDE_FLOAT64_C(   955.90), SIMDE_FLOAT64_C(   268.88) },
        { SIMDE_FLOAT64_C(  -111.23), SIMDE_FLOAT64_C(   776.00) },
        { -INT64_C(                   1),  INT64_C(                   0) } },
      { { SIMDE_FLOAT64_C(  -192.32), SIMDE_FLOAT64_C(   677.67) },
        { SIMDE_FLOAT64_C(   762.32), SIMDE_FLOAT64_C(   481.24) },
        {  INT64_C(                   0), -INT64_C(                   1) } },
      { { SIMDE_FLOAT64_C(   844.97), SIMDE_FLOAT64_C(   343.65) },
        { SIMDE_FLOAT64_C(  -295.41), SIMDE_FLOAT64_C(   118.41) },
        { -INT64_C(                   1), -INT64_C(                   1) } },
      { { SIMDE_FLOAT64_C(   239.07), SIMDE_FLOAT64_C(   142.88) },
        { SIMDE_FLOAT64_C(  -605.13), SIMDE_FLOAT64_C(  -550.67) },
        { -INT64_C(                   1), -INT64_C(                   1) } },
      { { SIMDE_FLOAT64_C(   457.66), SIMDE_FLOAT64_C(  -706.31) },
        { SIMDE_FLOAT64_C(   434.02), SIMDE_FLOAT64_C(  -320.66) },
        { -INT64_C(                   1),  INT64_C(                   0) } },
      { { SIMDE_FLOAT64_C(   466.57), SIMDE_FLOAT64_C(   500.06) },
        { SIMDE_FLOAT64_C(   934.99), SIMDE_FLOAT64_C(    21.12) },
        {  INT64_C(                   0), -INT64_C(                   1) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t b = simde_wasm_v128_load(test_vec[i].b);
      simde_v128_t r = simde_wasm_f64x2_ge(a, b);
      simde_test_wasm_i64x2_assert_equal(r, simde_wasm_v128_load(test_vec[i].r));
    }
    return 0;
  #else
    fputc('\n', stdout);
    simde_float64 inputs[8 * 2 * (sizeof(simde_v128_t) / sizeof(simde_float64))];
    simde_test_wasm_f64x2_random_full(8, 2, inputs, -SIMDE_FLOAT64_C(1000.0), SIMDE_FLOAT64_C(1000.0), HEDLEY_STATIC_CAST(SimdeTestVecFloatType, SIMDE_TEST_VEC_FLOAT_NAN | SIMDE_TEST_VEC_FLOAT_EQUAL));
    for (size_t i = 0 ; i < 8 ; i++) {
      simde_v128_t
        a = simde_test_wasm_f64x2_random_full_extract(2, inputs, i, 0),
        b = simde_test_wasm_f64x2_random_full_extract(2, inputs, i, 1),
        r;

      r = simde_wasm_f64x2_ge(a, b);

      simde_test_wasm_f64x2_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_f64x2_write(3, b, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_wasm_i64x2_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_i8x16_ge)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_i16x8_ge)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_i32x4_ge)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_f32x4_ge)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_f64x2_ge)
SIMDE_TEST_FUNC_LIST_END

#include <test/x86/test-x86-footer.h>
