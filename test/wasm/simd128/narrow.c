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

#define SIMDE_TEST_WASM_SIMD128_INSN narrow
#include "../../../simde/wasm/simd128.h"
#include "test-simd128.h"

static int
test_simde_wasm_i8x16_narrow_i16x8(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      int16_t a[sizeof(simde_v128_t) / sizeof(int16_t)];
      int16_t b[sizeof(simde_v128_t) / sizeof(int16_t)];
      int8_t r[sizeof(simde_v128_t) / sizeof(int8_t)];
    } test_vec[] = {
      { {  INT16_C(   116),  INT16_C(   133), -INT16_C(   241), -INT16_C(   223),  INT16_C(   235), -INT16_C(   224),  INT16_C(   239), -INT16_C(    52) },
        {  INT16_C(   128), -INT16_C(    85), -INT16_C(   176), -INT16_C(    85), -INT16_C(   219),  INT16_C(    95),  INT16_C(    75), -INT16_C(   195) },
        {  INT8_C( 116),      INT8_MAX,      INT8_MIN,      INT8_MIN,      INT8_MAX,      INT8_MIN,      INT8_MAX, -INT8_C(  52),
               INT8_MAX, -INT8_C(  85),      INT8_MIN, -INT8_C(  85),      INT8_MIN,  INT8_C(  95),  INT8_C(  75),      INT8_MIN } },
      { {  INT16_C(   193),  INT16_C(   211),  INT16_C(   124), -INT16_C(    67),  INT16_C(   114), -INT16_C(   198), -INT16_C(   137), -INT16_C(    95) },
        {  INT16_C(    19),  INT16_C(   242),  INT16_C(    13),  INT16_C(   136),  INT16_C(    37), -INT16_C(   218), -INT16_C(   145), -INT16_C(   174) },
        {      INT8_MAX,      INT8_MAX,  INT8_C( 124), -INT8_C(  67),  INT8_C( 114),      INT8_MIN,      INT8_MIN, -INT8_C(  95),
           INT8_C(  19),      INT8_MAX,  INT8_C(  13),      INT8_MAX,  INT8_C(  37),      INT8_MIN,      INT8_MIN,      INT8_MIN } },
      { { -INT16_C(     6), -INT16_C(     8), -INT16_C(    38),  INT16_C(   139), -INT16_C(   116),  INT16_C(   127), -INT16_C(   222), -INT16_C(   123) },
        {  INT16_C(   124), -INT16_C(   138), -INT16_C(   149), -INT16_C(    43), -INT16_C(   235),  INT16_C(   150), -INT16_C(    31),  INT16_C(   225) },
        { -INT8_C(   6), -INT8_C(   8), -INT8_C(  38),      INT8_MAX, -INT8_C( 116),      INT8_MAX,      INT8_MIN, -INT8_C( 123),
           INT8_C( 124),      INT8_MIN,      INT8_MIN, -INT8_C(  43),      INT8_MIN,      INT8_MAX, -INT8_C(  31),      INT8_MAX } },
      { {  INT16_C(    73), -INT16_C(    51), -INT16_C(   206),  INT16_C(   208), -INT16_C(   217), -INT16_C(    46), -INT16_C(   200),  INT16_C(    18) },
        {  INT16_C(    13),  INT16_C(   253),  INT16_C(   221),  INT16_C(    70), -INT16_C(    65),  INT16_C(   247), -INT16_C(   160), -INT16_C(   222) },
        {  INT8_C(  73), -INT8_C(  51),      INT8_MIN,      INT8_MAX,      INT8_MIN, -INT8_C(  46),      INT8_MIN,  INT8_C(  18),
           INT8_C(  13),      INT8_MAX,      INT8_MAX,  INT8_C(  70), -INT8_C(  65),      INT8_MAX,      INT8_MIN,      INT8_MIN } },
      { {  INT16_C(    18),  INT16_C(    27), -INT16_C(   126), -INT16_C(    50), -INT16_C(    51),  INT16_C(   111), -INT16_C(   241),  INT16_C(   175) },
        { -INT16_C(   240),  INT16_C(    91),  INT16_C(   245), -INT16_C(   102), -INT16_C(   195),  INT16_C(   220), -INT16_C(    38),  INT16_C(     6) },
        {  INT8_C(  18),  INT8_C(  27), -INT8_C( 126), -INT8_C(  50), -INT8_C(  51),  INT8_C( 111),      INT8_MIN,      INT8_MAX,
               INT8_MIN,  INT8_C(  91),      INT8_MAX, -INT8_C( 102),      INT8_MIN,      INT8_MAX, -INT8_C(  38),  INT8_C(   6) } },
      { { -INT16_C(   192),  INT16_C(   174),  INT16_C(   230),  INT16_C(   152),  INT16_C(   198), -INT16_C(   102),  INT16_C(     8), -INT16_C(   225) },
        {  INT16_C(   164), -INT16_C(   246), -INT16_C(   220), -INT16_C(     9),  INT16_C(   127),  INT16_C(   117),  INT16_C(   220), -INT16_C(   168) },
        {      INT8_MIN,      INT8_MAX,      INT8_MAX,      INT8_MAX,      INT8_MAX, -INT8_C( 102),  INT8_C(   8),      INT8_MIN,
               INT8_MAX,      INT8_MIN,      INT8_MIN, -INT8_C(   9),      INT8_MAX,  INT8_C( 117),      INT8_MAX,      INT8_MIN } },
      { { -INT16_C(   108),  INT16_C(    71), -INT16_C(    57),  INT16_C(   250),  INT16_C(    25), -INT16_C(   146),  INT16_C(   113),  INT16_C(    49) },
        {  INT16_C(   132), -INT16_C(   107),  INT16_C(    94),  INT16_C(    68), -INT16_C(    25), -INT16_C(    78), -INT16_C(    10),  INT16_C(   204) },
        { -INT8_C( 108),  INT8_C(  71), -INT8_C(  57),      INT8_MAX,  INT8_C(  25),      INT8_MIN,  INT8_C( 113),  INT8_C(  49),
               INT8_MAX, -INT8_C( 107),  INT8_C(  94),  INT8_C(  68), -INT8_C(  25), -INT8_C(  78), -INT8_C(  10),      INT8_MAX } },
      { { -INT16_C(     5),  INT16_C(   153), -INT16_C(   239), -INT16_C(   172), -INT16_C(   100),  INT16_C(   143), -INT16_C(   131), -INT16_C(   172) },
        { -INT16_C(    40), -INT16_C(   232),  INT16_C(   203), -INT16_C(   116), -INT16_C(    57), -INT16_C(   103),  INT16_C(    51), -INT16_C(   203) },
        { -INT8_C(   5),      INT8_MAX,      INT8_MIN,      INT8_MIN, -INT8_C( 100),      INT8_MAX,      INT8_MIN,      INT8_MIN,
          -INT8_C(  40),      INT8_MIN,      INT8_MAX, -INT8_C( 116), -INT8_C(  57), -INT8_C( 103),  INT8_C(  51),      INT8_MIN } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t b = simde_wasm_v128_load(test_vec[i].b);
      simde_v128_t r = simde_wasm_i8x16_narrow_i16x8(a, b);
      simde_test_wasm_i8x16_assert_equal(r, simde_wasm_v128_load(test_vec[i].r));
    }
    return 0;
  #else
    fputc('\n', stdout);
    for (int i = 0 ; i < 8 ; i++) {
      simde_v128_t
        a = simde_test_wasm_i16x8_random(),
        b = simde_test_wasm_i16x8_random(),
        r;

      a = simde_wasm_i16x8_shr(a, 7);
      b = simde_wasm_i16x8_shr(b, 7);
      r = simde_wasm_i8x16_narrow_i16x8(a, b);

      simde_test_wasm_i16x8_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_i16x8_write(3, b, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_wasm_i8x16_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_i16x8_narrow_i32x4(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      int32_t a[sizeof(simde_v128_t) / sizeof(int32_t)];
      int32_t b[sizeof(simde_v128_t) / sizeof(int32_t)];
      int16_t r[sizeof(simde_v128_t) / sizeof(int16_t)];
    } test_vec[] = {
      { { -INT32_C(       45502), -INT32_C(       35793),  INT32_C(       59913), -INT32_C(       50624) },
        { -INT32_C(       13889), -INT32_C(       41254),  INT32_C(       29817),  INT32_C(       35350) },
        {       INT16_MIN,       INT16_MIN,       INT16_MAX,       INT16_MIN, -INT16_C( 13889),       INT16_MIN,  INT16_C( 29817),       INT16_MAX } },
      { { -INT32_C(         477),  INT32_C(       30424), -INT32_C(       34428), -INT32_C(       36373) },
        {  INT32_C(       26474), -INT32_C(       57504), -INT32_C(       59574), -INT32_C(       59903) },
        { -INT16_C(   477),  INT16_C( 30424),       INT16_MIN,       INT16_MIN,  INT16_C( 26474),       INT16_MIN,       INT16_MIN,       INT16_MIN } },
      { { -INT32_C(       51519), -INT32_C(       22179),  INT32_C(       63923), -INT32_C(       64543) },
        {  INT32_C(       50166),  INT32_C(       29946), -INT32_C(       58420), -INT32_C(       29140) },
        {       INT16_MIN, -INT16_C( 22179),       INT16_MAX,       INT16_MIN,       INT16_MAX,  INT16_C( 29946),       INT16_MIN, -INT16_C( 29140) } },
      { {  INT32_C(       27529),  INT32_C(       25233), -INT32_C(       20166),  INT32_C(        6470) },
        { -INT32_C(       51153),  INT32_C(       41405),  INT32_C(        7844),  INT32_C(       12736) },
        {  INT16_C( 27529),  INT16_C( 25233), -INT16_C( 20166),  INT16_C(  6470),       INT16_MIN,       INT16_MAX,  INT16_C(  7844),  INT16_C( 12736) } },
      { {  INT32_C(       65271),  INT32_C(       57830),  INT32_C(        9276),  INT32_C(       36250) },
        { -INT32_C(       53007),  INT32_C(       55036),  INT32_C(         843),  INT32_C(       58187) },
        {       INT16_MAX,       INT16_MAX,  INT16_C(  9276),       INT16_MAX,       INT16_MIN,       INT16_MAX,  INT16_C(   843),       INT16_MAX } },
      { {  INT32_C(       16213),  INT32_C(       11140),  INT32_C(       56774), -INT32_C(       26224) },
        {  INT32_C(       39768), -INT32_C(       22281),  INT32_C(        8963),  INT32_C(       21272) },
        {  INT16_C( 16213),  INT16_C( 11140),       INT16_MAX, -INT16_C( 26224),       INT16_MAX, -INT16_C( 22281),  INT16_C(  8963),  INT16_C( 21272) } },
      { {  INT32_C(       23143),  INT32_C(       60768), -INT32_C(       57776),  INT32_C(       25315) },
        {  INT32_C(       27137), -INT32_C(       43172), -INT32_C(       25395),  INT32_C(        3207) },
        {  INT16_C( 23143),       INT16_MAX,       INT16_MIN,  INT16_C( 25315),  INT16_C( 27137),       INT16_MIN, -INT16_C( 25395),  INT16_C(  3207) } },
      { {  INT32_C(       27685), -INT32_C(       42675),  INT32_C(       45345), -INT32_C(       22230) },
        {  INT32_C(        7473), -INT32_C(       52503),  INT32_C(       35935), -INT32_C(       23455) },
        {  INT16_C( 27685),       INT16_MIN,       INT16_MAX, -INT16_C( 22230),  INT16_C(  7473),       INT16_MIN,       INT16_MAX, -INT16_C( 23455) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t b = simde_wasm_v128_load(test_vec[i].b);
      simde_v128_t r = simde_wasm_i16x8_narrow_i32x4(a, b);
      simde_test_wasm_i16x8_assert_equal(r, simde_wasm_v128_load(test_vec[i].r));
    }
    return 0;
  #else
    fputc('\n', stdout);
    for (int i = 0 ; i < 8 ; i++) {
      simde_v128_t
        a = simde_test_wasm_i32x4_random(),
        b = simde_test_wasm_i32x4_random(),
        r;

      a = simde_wasm_i32x4_shr(a, 15);
      b = simde_wasm_i32x4_shr(b, 15);
      r = simde_wasm_i16x8_narrow_i32x4(a, b);

      simde_test_wasm_i32x4_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_i32x4_write(3, b, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_wasm_i16x8_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_u8x16_narrow_i16x8(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      int16_t a[sizeof(simde_v128_t) / sizeof(int16_t)];
      int16_t b[sizeof(simde_v128_t) / sizeof(int16_t)];
      uint8_t r[sizeof(simde_v128_t) / sizeof(int8_t)];
    } test_vec[] = {
      { {  INT16_C(   311), -INT16_C(   392), -INT16_C(    33), -INT16_C(   332), -INT16_C(   404), -INT16_C(    44), -INT16_C(     7),  INT16_C(    71) },
        { -INT16_C(   386),  INT16_C(   397),  INT16_C(   506), -INT16_C(   408), -INT16_C(   181), -INT16_C(   118),  INT16_C(    47), -INT16_C(   273) },
        {    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C( 71),
          UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C( 47), UINT8_C(  0) } },
      { {  INT16_C(   132), -INT16_C(   316),  INT16_C(   399),  INT16_C(   217), -INT16_C(   498), -INT16_C(   238), -INT16_C(   486),  INT16_C(   171) },
        {  INT16_C(   187), -INT16_C(    33), -INT16_C(   440), -INT16_C(   234),  INT16_C(   403),  INT16_C(    92),  INT16_C(   217), -INT16_C(   245) },
        { UINT8_C(132), UINT8_C(  0),    UINT8_MAX, UINT8_C(217), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(171),
          UINT8_C(187), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C( 92), UINT8_C(217), UINT8_C(  0) } },
      { {  INT16_C(   340),  INT16_C(    74), -INT16_C(   266),  INT16_C(   308), -INT16_C(   180),  INT16_C(    94),  INT16_C(   291),  INT16_C(   267) },
        {  INT16_C(    35), -INT16_C(   178), -INT16_C(    26),  INT16_C(    45), -INT16_C(   249),  INT16_C(   242),  INT16_C(   374), -INT16_C(    99) },
        {    UINT8_MAX, UINT8_C( 74), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C( 94),    UINT8_MAX,    UINT8_MAX,
          UINT8_C( 35), UINT8_C(  0), UINT8_C(  0), UINT8_C( 45), UINT8_C(  0), UINT8_C(242),    UINT8_MAX, UINT8_C(  0) } },
      { {  INT16_C(   156), -INT16_C(   158), -INT16_C(   368), -INT16_C(   406),  INT16_C(   281), -INT16_C(   210), -INT16_C(   360), -INT16_C(     3) },
        { -INT16_C(    21),  INT16_C(   219),  INT16_C(    75),  INT16_C(   340),  INT16_C(   367),  INT16_C(    27), -INT16_C(   506),  INT16_C(   454) },
        { UINT8_C(156), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
          UINT8_C(  0), UINT8_C(219), UINT8_C( 75),    UINT8_MAX,    UINT8_MAX, UINT8_C( 27), UINT8_C(  0),    UINT8_MAX } },
      { {  INT16_C(    50), -INT16_C(   507), -INT16_C(   512),  INT16_C(   435),  INT16_C(   226),  INT16_C(   396),  INT16_C(   120), -INT16_C(   245) },
        {  INT16_C(   436), -INT16_C(   370), -INT16_C(   228),  INT16_C(   195), -INT16_C(   148),  INT16_C(   418), -INT16_C(   330),  INT16_C(    39) },
        { UINT8_C( 50), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(226),    UINT8_MAX, UINT8_C(120), UINT8_C(  0),
             UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(195), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C( 39) } },
      { { -INT16_C(   135),  INT16_C(    63),  INT16_C(   384),  INT16_C(    79),  INT16_C(   198), -INT16_C(   455), -INT16_C(   477),  INT16_C(   370) },
        {  INT16_C(   357), -INT16_C(   235),  INT16_C(   137), -INT16_C(   121),  INT16_C(   427), -INT16_C(   202), -INT16_C(    57),  INT16_C(   200) },
        { UINT8_C(  0), UINT8_C( 63),    UINT8_MAX, UINT8_C( 79), UINT8_C(198), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,
             UINT8_MAX, UINT8_C(  0), UINT8_C(137), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(200) } },
      { { -INT16_C(   475), -INT16_C(   325),  INT16_C(   327), -INT16_C(   325), -INT16_C(    66),  INT16_C(   164), -INT16_C(   208),  INT16_C(   251) },
        { -INT16_C(   359), -INT16_C(   192),  INT16_C(   430), -INT16_C(    38),  INT16_C(   511), -INT16_C(   112), -INT16_C(   125),  INT16_C(   231) },
        { UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(164), UINT8_C(  0), UINT8_C(251),
          UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(231) } },
      { {  INT16_C(   201), -INT16_C(   170),  INT16_C(   245),  INT16_C(   507), -INT16_C(    54), -INT16_C(   256),  INT16_C(   136),  INT16_C(   181) },
        {  INT16_C(   128),  INT16_C(   421), -INT16_C(   241),  INT16_C(   368),  INT16_C(   151), -INT16_C(   152), -INT16_C(   490), -INT16_C(   346) },
        { UINT8_C(201), UINT8_C(  0), UINT8_C(245),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(136), UINT8_C(181),
          UINT8_C(128),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(151), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t b = simde_wasm_v128_load(test_vec[i].b);
      simde_v128_t r = simde_wasm_u8x16_narrow_i16x8(a, b);
      simde_test_wasm_u8x16_assert_equal(r, simde_wasm_v128_load(test_vec[i].r));
    }
    return 0;
  #else
    fputc('\n', stdout);
    for (int i = 0 ; i < 8 ; i++) {
      simde_v128_t
        a = simde_test_wasm_i16x8_random(),
        b = simde_test_wasm_i16x8_random(),
        r;

      a = simde_wasm_i16x8_shr(a, 6);
      b = simde_wasm_i16x8_shr(b, 6);
      r = simde_wasm_u8x16_narrow_i16x8(a, b);

      simde_test_wasm_i16x8_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_i16x8_write(3, b, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_wasm_u8x16_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_u16x8_narrow_i32x4(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      int32_t a[sizeof(simde_v128_t) / sizeof(int32_t)];
      int32_t b[sizeof(simde_v128_t) / sizeof(int32_t)];
      uint16_t r[sizeof(simde_v128_t) / sizeof(int16_t)];
    } test_vec[] = {
      { { -INT32_C(       18757), -INT32_C(       67527), -INT32_C(      108538),  INT32_C(      121671) },
        {  INT32_C(        3463), -INT32_C(       19911),  INT32_C(       38807),  INT32_C(       61775) },
        { UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),      UINT16_MAX, UINT16_C( 3463), UINT16_C(    0), UINT16_C(38807), UINT16_C(61775) } },
      { {  INT32_C(      113334), -INT32_C(       15674),  INT32_C(       35649), -INT32_C(       98091) },
        { -INT32_C(       58412), -INT32_C(      124646), -INT32_C(       63794),  INT32_C(       85211) },
        {      UINT16_MAX, UINT16_C(    0), UINT16_C(35649), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),      UINT16_MAX } },
      { { -INT32_C(      123522), -INT32_C(       77501),  INT32_C(       24629), -INT32_C(       98808) },
        { -INT32_C(       15033), -INT32_C(       98185), -INT32_C(        8036), -INT32_C(       28632) },
        { UINT16_C(    0), UINT16_C(    0), UINT16_C(24629), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) } },
      { {  INT32_C(       65892),  INT32_C(       25331), -INT32_C(       26070), -INT32_C(      120912) },
        { -INT32_C(       70654),  INT32_C(       88287), -INT32_C(       98231), -INT32_C(       18033) },
        {      UINT16_MAX, UINT16_C(25331), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),      UINT16_MAX, UINT16_C(    0), UINT16_C(    0) } },
      { {  INT32_C(       25658),  INT32_C(      113784), -INT32_C(       68341), -INT32_C(       58573) },
        { -INT32_C(       71945),  INT32_C(        3981), -INT32_C(       30509),  INT32_C(      114913) },
        { UINT16_C(25658),      UINT16_MAX, UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C( 3981), UINT16_C(    0),      UINT16_MAX } },
      { {  INT32_C(       52573), -INT32_C(       99853),  INT32_C(       14110), -INT32_C(       61428) },
        { -INT32_C(       64749),  INT32_C(       82798),  INT32_C(      124351), -INT32_C(       44001) },
        { UINT16_C(52573), UINT16_C(    0), UINT16_C(14110), UINT16_C(    0), UINT16_C(    0),      UINT16_MAX,      UINT16_MAX, UINT16_C(    0) } },
      { { -INT32_C(       14822), -INT32_C(        8506), -INT32_C(      113448),  INT32_C(       44883) },
        {  INT32_C(       73344), -INT32_C(       57352),  INT32_C(      127436), -INT32_C(       17972) },
        { UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(44883),      UINT16_MAX, UINT16_C(    0),      UINT16_MAX, UINT16_C(    0) } },
      { {  INT32_C(       24525), -INT32_C(      127031), -INT32_C(       56704), -INT32_C(      115436) },
        {  INT32_C(       76270), -INT32_C(       21925), -INT32_C(      104518),  INT32_C(       98690) },
        { UINT16_C(24525), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),      UINT16_MAX, UINT16_C(    0), UINT16_C(    0),      UINT16_MAX } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t b = simde_wasm_v128_load(test_vec[i].b);
      simde_v128_t r = simde_wasm_u16x8_narrow_i32x4(a, b);
      simde_test_wasm_u16x8_assert_equal(r, simde_wasm_v128_load(test_vec[i].r));
    }
    return 0;
  #else
    fputc('\n', stdout);
    for (int i = 0 ; i < 8 ; i++) {
      simde_v128_t
        a = simde_test_wasm_i32x4_random(),
        b = simde_test_wasm_i32x4_random(),
        r;

      a = simde_wasm_i32x4_shr(a, 14);
      b = simde_wasm_i32x4_shr(b, 14);
      r = simde_wasm_u16x8_narrow_i32x4(a, b);

      simde_test_wasm_i32x4_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_i32x4_write(3, b, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_wasm_u16x8_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_i8x16_narrow_i16x8)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_i16x8_narrow_i32x4)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_u8x16_narrow_i16x8)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_u16x8_narrow_i32x4)
SIMDE_TEST_FUNC_LIST_END

#include "test-simd128-footer.h"
