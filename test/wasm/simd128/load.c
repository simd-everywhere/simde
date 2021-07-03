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

#define SIMDE_TEST_WASM_SIMD128_INSN load
#include "../../../simde/wasm/simd128.h"
#include "test-simd128.h"

static int
test_simde_wasm_i16x8_load8x8(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      int8_t a[8];
      int16_t r[sizeof(simde_v128_t) / sizeof(int16_t)];
    } test_vec[] = {
      { { -INT8_C(  95), -INT8_C( 114),  INT8_C( 115),  INT8_C(  55),  INT8_C(  42), -INT8_C(   9), -INT8_C( 113), -INT8_C( 102) },
        { -INT16_C(    95), -INT16_C(   114),  INT16_C(   115),  INT16_C(    55),  INT16_C(    42), -INT16_C(     9), -INT16_C(   113), -INT16_C(   102) } },
      { {  INT8_C( 125),  INT8_C(  54), -INT8_C(  46), -INT8_C(  39), -INT8_C(  87),  INT8_C(  72),  INT8_C(  86),  INT8_C(   1) },
        {  INT16_C(   125),  INT16_C(    54), -INT16_C(    46), -INT16_C(    39), -INT16_C(    87),  INT16_C(    72),  INT16_C(    86),  INT16_C(     1) } },
      { {  INT8_C(  67),  INT8_C( 111), -INT8_C(   9),  INT8_C(  29), -INT8_C(  36), -INT8_C(  28), -INT8_C(  57), -INT8_C(  29) },
        {  INT16_C(    67),  INT16_C(   111), -INT16_C(     9),  INT16_C(    29), -INT16_C(    36), -INT16_C(    28), -INT16_C(    57), -INT16_C(    29) } },
      { { -INT8_C( 124),  INT8_C(  37),  INT8_C(  37),  INT8_C(  46),  INT8_C(  74),  INT8_C(  71),  INT8_C(  92), -INT8_C(  24) },
        { -INT16_C(   124),  INT16_C(    37),  INT16_C(    37),  INT16_C(    46),  INT16_C(    74),  INT16_C(    71),  INT16_C(    92), -INT16_C(    24) } },
      { {  INT8_C( 103), -INT8_C(  64),  INT8_C( 107),  INT8_C(   6), -INT8_C(  91),  INT8_C( 105), -INT8_C( 100),  INT8_C(  64) },
        {  INT16_C(   103), -INT16_C(    64),  INT16_C(   107),  INT16_C(     6), -INT16_C(    91),  INT16_C(   105), -INT16_C(   100),  INT16_C(    64) } },
      { {  INT8_C( 105),  INT8_C( 111),  INT8_C(  22),  INT8_C(  85), -INT8_C(  77), -INT8_C(  98),  INT8_C( 126), -INT8_C(  79) },
        {  INT16_C(   105),  INT16_C(   111),  INT16_C(    22),  INT16_C(    85), -INT16_C(    77), -INT16_C(    98),  INT16_C(   126), -INT16_C(    79) } },
      { { -INT8_C(  41), -INT8_C( 103), -INT8_C(  21), -INT8_C(  36), -INT8_C(   3),  INT8_C(  97),  INT8_C( 107), -INT8_C( 112) },
        { -INT16_C(    41), -INT16_C(   103), -INT16_C(    21), -INT16_C(    36), -INT16_C(     3),  INT16_C(    97),  INT16_C(   107), -INT16_C(   112) } },
      { {  INT8_C(  52),  INT8_C(  71), -INT8_C(  65),  INT8_C(  29),  INT8_C(   9), -INT8_C(  45), -INT8_C(  78), -INT8_C(  36) },
        {  INT16_C(    52),  INT16_C(    71), -INT16_C(    65),  INT16_C(    29),  INT16_C(     9), -INT16_C(    45), -INT16_C(    78), -INT16_C(    36) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t r = simde_wasm_i16x8_load8x8(&(test_vec[i].a));
      simde_test_wasm_i16x8_assert_equal(r, simde_wasm_v128_load(test_vec[i].r));
    }
    return 0;
  #else
    fputc('\n', stdout);
    for (int i = 0 ; i < 8 ; i++) {
      int8_t a[8];
      simde_v128_t r;

      simde_test_codegen_random_memory(sizeof(a), HEDLEY_REINTERPRET_CAST(uint8_t*, a));
      r = simde_wasm_i16x8_load8x8(a);

      simde_test_codegen_write_vi8(3, sizeof(a) / sizeof(a[0]), a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_i16x8_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_i32x4_load16x4(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      int16_t a[4];
      int32_t r[sizeof(simde_v128_t) / sizeof(int32_t)];
    } test_vec[] = {
      { { -INT16_C( 31264), -INT16_C( 28286), -INT16_C( 26142), -INT16_C(  5726) },
        { -INT32_C(       31264), -INT32_C(       28286), -INT32_C(       26142), -INT32_C(        5726) } },
      { {  INT16_C( 30293), -INT16_C( 12630),  INT16_C( 21443),  INT16_C(  1196) },
        {  INT32_C(       30293), -INT32_C(       12630),  INT32_C(       21443),  INT32_C(        1196) } },
      { {  INT16_C( 32610), -INT16_C(  7050), -INT16_C( 26940),  INT16_C(  3156) },
        {  INT32_C(       32610), -INT32_C(        7050), -INT32_C(       26940),  INT32_C(        3156) } },
      { { -INT16_C(   564),  INT16_C(  1612), -INT16_C( 30099),  INT16_C( 30839) },
        { -INT32_C(         564),  INT32_C(        1612), -INT32_C(       30099),  INT32_C(       30839) } },
      { {  INT16_C( 11924),  INT16_C( 15908),  INT16_C( 14389),  INT16_C( 17266) },
        {  INT32_C(       11924),  INT32_C(       15908),  INT32_C(       14389),  INT32_C(       17266) } },
      { { -INT16_C( 15297),  INT16_C( 12075), -INT16_C( 29243), -INT16_C( 17112) },
        { -INT32_C(       15297),  INT32_C(       12075), -INT32_C(       29243), -INT32_C(       17112) } },
      { {  INT16_C(  2261), -INT16_C( 16095),  INT16_C( 31094),  INT16_C( 24715) },
        {  INT32_C(        2261), -INT32_C(       16095),  INT32_C(       31094),  INT32_C(       24715) } },
      { { -INT16_C( 19354), -INT16_C( 22397), -INT16_C( 14085), -INT16_C( 31404) },
        { -INT32_C(       19354), -INT32_C(       22397), -INT32_C(       14085), -INT32_C(       31404) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t r = simde_wasm_i32x4_load16x4(&(test_vec[i].a));
      simde_test_wasm_i32x4_assert_equal(r, simde_wasm_v128_load(test_vec[i].r));
    }
    return 0;
  #else
    fputc('\n', stdout);
    for (int i = 0 ; i < 8 ; i++) {
      int16_t a[4];
      simde_v128_t r;

      simde_test_codegen_random_memory(sizeof(a), HEDLEY_REINTERPRET_CAST(uint8_t*, a));
      r = simde_wasm_i32x4_load16x4(a);

      simde_test_codegen_write_vi16(3, sizeof(a) / sizeof(a[0]), a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_i32x4_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_i64x2_load32x2(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      int32_t a[2];
      int64_t r[sizeof(simde_v128_t) / sizeof(int64_t)];
    } test_vec[] = {
      { { -INT32_C(  1931121591), -INT32_C(  1023014746) },
        { -INT64_C(          1931121591), -INT64_C(          1023014746) } },
      { { -INT32_C(  1990935904), -INT32_C(  2067868927) },
        { -INT64_C(          1990935904), -INT64_C(          2067868927) } },
      { { -INT32_C(  1730594775),  INT32_C(  1705613290) },
        { -INT64_C(          1730594775),  INT64_C(          1705613290) } },
      { {  INT32_C(  1186564496), -INT32_C(  1370363479) },
        {  INT64_C(          1186564496), -INT64_C(          1370363479) } },
      { {  INT32_C(   273847312),  INT32_C(   762006253) },
        {  INT64_C(           273847312),  INT64_C(           762006253) } },
      { { -INT32_C(  1914481043), -INT32_C(  1977865753) },
        { -INT64_C(          1914481043), -INT64_C(          1977865753) } },
      { { -INT32_C(  2047965519),  INT32_C(   436452664) },
        { -INT64_C(          2047965519),  INT64_C(           436452664) } },
      { { -INT32_C(   986113138),  INT32_C(   182339743) },
        { -INT64_C(           986113138),  INT64_C(           182339743) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t r = simde_wasm_i64x2_load32x2(&(test_vec[i].a));
      simde_test_wasm_i64x2_assert_equal(r, simde_wasm_v128_load(test_vec[i].r));
    }
    return 0;
  #else
    fputc('\n', stdout);
    for (int i = 0 ; i < 8 ; i++) {
      int32_t a[2];
      simde_v128_t r;

      simde_test_codegen_random_memory(sizeof(a), HEDLEY_REINTERPRET_CAST(uint8_t*, a));
      r = simde_wasm_i64x2_load32x2(a);

      simde_test_codegen_write_vi32(3, sizeof(a) / sizeof(a[0]), a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_i64x2_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_u16x8_load8x8(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      uint8_t a[8];
      uint16_t r[sizeof(simde_v128_t) / sizeof(uint16_t)];
    } test_vec[] = {
      { { UINT8_C(176), UINT8_C(138), UINT8_C( 83), UINT8_C(251), UINT8_C(247), UINT8_C(103), UINT8_C(246), UINT8_C(122) },
        { UINT16_C(  176), UINT16_C(  138), UINT16_C(   83), UINT16_C(  251), UINT16_C(  247), UINT16_C(  103), UINT16_C(  246), UINT16_C(  122) } },
      { { UINT8_C( 28), UINT8_C(244), UINT8_C( 52), UINT8_C(104), UINT8_C(210), UINT8_C( 70), UINT8_C(220), UINT8_C(  4) },
        { UINT16_C(   28), UINT16_C(  244), UINT16_C(   52), UINT16_C(  104), UINT16_C(  210), UINT16_C(   70), UINT16_C(  220), UINT16_C(    4) } },
      { { UINT8_C(220), UINT8_C(202), UINT8_C( 21), UINT8_C(229), UINT8_C(162), UINT8_C(112), UINT8_C(179), UINT8_C(234) },
        { UINT16_C(  220), UINT16_C(  202), UINT16_C(   21), UINT16_C(  229), UINT16_C(  162), UINT16_C(  112), UINT16_C(  179), UINT16_C(  234) } },
      { { UINT8_C(122), UINT8_C( 18), UINT8_C(171), UINT8_C(243), UINT8_C(108), UINT8_C(225), UINT8_C(242), UINT8_C(140) },
        { UINT16_C(  122), UINT16_C(   18), UINT16_C(  171), UINT16_C(  243), UINT16_C(  108), UINT16_C(  225), UINT16_C(  242), UINT16_C(  140) } },
      { { UINT8_C( 81), UINT8_C(239), UINT8_C(189), UINT8_C( 81), UINT8_C( 92), UINT8_C(132), UINT8_C(239), UINT8_C( 11) },
        { UINT16_C(   81), UINT16_C(  239), UINT16_C(  189), UINT16_C(   81), UINT16_C(   92), UINT16_C(  132), UINT16_C(  239), UINT16_C(   11) } },
      { { UINT8_C( 89), UINT8_C( 93), UINT8_C(127), UINT8_C( 10), UINT8_C( 33), UINT8_C( 28), UINT8_C(222), UINT8_C(234) },
        { UINT16_C(   89), UINT16_C(   93), UINT16_C(  127), UINT16_C(   10), UINT16_C(   33), UINT16_C(   28), UINT16_C(  222), UINT16_C(  234) } },
      { { UINT8_C(102), UINT8_C( 20), UINT8_C( 57), UINT8_C(220), UINT8_C(163), UINT8_C(237), UINT8_C(144), UINT8_C( 52) },
        { UINT16_C(  102), UINT16_C(   20), UINT16_C(   57), UINT16_C(  220), UINT16_C(  163), UINT16_C(  237), UINT16_C(  144), UINT16_C(   52) } },
      { { UINT8_C(196), UINT8_C(106), UINT8_C(211), UINT8_C(171), UINT8_C(124), UINT8_C(170), UINT8_C(138), UINT8_C( 23) },
        { UINT16_C(  196), UINT16_C(  106), UINT16_C(  211), UINT16_C(  171), UINT16_C(  124), UINT16_C(  170), UINT16_C(  138), UINT16_C(   23) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t r = simde_wasm_u16x8_load8x8(&(test_vec[i].a));
      simde_test_wasm_u16x8_assert_equal(r, simde_wasm_v128_load(test_vec[i].r));
    }
    return 0;
  #else
    fputc('\n', stdout);
    for (int i = 0 ; i < 8 ; i++) {
      uint8_t a[8];
      simde_v128_t r;

      simde_test_codegen_random_memory(sizeof(a), HEDLEY_REINTERPRET_CAST(uint8_t*, a));
      r = simde_wasm_u16x8_load8x8(a);

      simde_test_codegen_write_vu8(3, sizeof(a) / sizeof(a[0]), a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_u16x8_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_u32x4_load16x4(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      uint16_t a[4];
      uint32_t r[sizeof(simde_v128_t) / sizeof(uint32_t)];
    } test_vec[] = {
      { { UINT16_C(21981), UINT16_C(10723), UINT16_C(32834), UINT16_C(19694) },
        { UINT32_C(     21981), UINT32_C(     10723), UINT32_C(     32834), UINT32_C(     19694) } },
      { { UINT16_C( 5251), UINT16_C(14245), UINT16_C(28602), UINT16_C(63141) },
        { UINT32_C(      5251), UINT32_C(     14245), UINT32_C(     28602), UINT32_C(     63141) } },
      { { UINT16_C(32336), UINT16_C(56365), UINT16_C(42450), UINT16_C( 6139) },
        { UINT32_C(     32336), UINT32_C(     56365), UINT32_C(     42450), UINT32_C(      6139) } },
      { { UINT16_C(10876), UINT16_C( 8448), UINT16_C(46123), UINT16_C( 1739) },
        { UINT32_C(     10876), UINT32_C(      8448), UINT32_C(     46123), UINT32_C(      1739) } },
      { { UINT16_C( 9559), UINT16_C(25904), UINT16_C( 8670), UINT16_C(46663) },
        { UINT32_C(      9559), UINT32_C(     25904), UINT32_C(      8670), UINT32_C(     46663) } },
      { { UINT16_C(19843), UINT16_C(15060), UINT16_C(59894), UINT16_C( 3890) },
        { UINT32_C(     19843), UINT32_C(     15060), UINT32_C(     59894), UINT32_C(      3890) } },
      { { UINT16_C(41705), UINT16_C( 9913), UINT16_C(11297), UINT16_C(56134) },
        { UINT32_C(     41705), UINT32_C(      9913), UINT32_C(     11297), UINT32_C(     56134) } },
      { { UINT16_C(28720), UINT16_C( 3842), UINT16_C(27318), UINT16_C(17011) },
        { UINT32_C(     28720), UINT32_C(      3842), UINT32_C(     27318), UINT32_C(     17011) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t r = simde_wasm_u32x4_load16x4(&(test_vec[i].a));
      simde_test_wasm_u32x4_assert_equal(r, simde_wasm_v128_load(test_vec[i].r));
    }
    return 0;
  #else
    fputc('\n', stdout);
    for (int i = 0 ; i < 8 ; i++) {
      uint16_t a[4];
      simde_v128_t r;

      simde_test_codegen_random_memory(sizeof(a), HEDLEY_REINTERPRET_CAST(uint8_t*, a));
      r = simde_wasm_u32x4_load16x4(a);

      simde_test_codegen_write_vu16(3, sizeof(a) / sizeof(a[0]), a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_u32x4_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_u64x2_load32x2(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      uint32_t a[2];
      uint64_t r[sizeof(simde_v128_t) / sizeof(uint64_t)];
    } test_vec[] = {
      { { UINT32_C(1865511555), UINT32_C( 862536039) },
        { UINT64_C(          1865511555), UINT64_C(           862536039) } },
      { { UINT32_C(3726145838), UINT32_C(1322698873) },
        { UINT64_C(          3726145838), UINT64_C(          1322698873) } },
      { { UINT32_C(3389096840), UINT32_C(2341160074) },
        { UINT64_C(          3389096840), UINT64_C(          2341160074) } },
      { { UINT32_C(2721223055), UINT32_C(3987937690) },
        { UINT64_C(          2721223055), UINT64_C(          3987937690) } },
      { { UINT32_C( 618782557), UINT32_C( 656171014) },
        { UINT64_C(           618782557), UINT64_C(           656171014) } },
      { { UINT32_C(3029439383), UINT32_C(1734071546) },
        { UINT64_C(          3029439383), UINT64_C(          1734071546) } },
      { { UINT32_C(1217348041), UINT32_C(3450681018) },
        { UINT64_C(          1217348041), UINT64_C(          3450681018) } },
      { { UINT32_C(2153652615), UINT32_C(2366941209) },
        { UINT64_C(          2153652615), UINT64_C(          2366941209) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t r = simde_wasm_u64x2_load32x2(&(test_vec[i].a));
      simde_test_wasm_u64x2_assert_equal(r, simde_wasm_v128_load(test_vec[i].r));
    }
    return 0;
  #else
    fputc('\n', stdout);
    for (int i = 0 ; i < 8 ; i++) {
      uint32_t a[2];
      simde_v128_t r;

      simde_test_codegen_random_memory(sizeof(a), HEDLEY_REINTERPRET_CAST(uint8_t*, a));
      r = simde_wasm_u64x2_load32x2(a);

      simde_test_codegen_write_vu32(3, sizeof(a) / sizeof(a[0]), a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_u64x2_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_i16x8_load8x8)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_i32x4_load16x4)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_i64x2_load32x2)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_u16x8_load8x8)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_u32x4_load16x4)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_u64x2_load32x2)
SIMDE_TEST_FUNC_LIST_END

#include "test-simd128-footer.h"
