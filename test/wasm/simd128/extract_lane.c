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

#define SIMDE_TEST_WASM_SIMD128_INSN extract_lane
#include "../../../simde/wasm/simd128.h"
#include "test-simd128.h"

static int
test_simde_wasm_i8x16_extract_lane(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      int8_t a[sizeof(simde_v128_t) / sizeof(int8_t)];
      int lane;
      int8_t r;
    } test_vec[] = {
      { {  INT8_C(  28),  INT8_C(  34),  INT8_C(  28), -INT8_C( 125),  INT8_C(  27), -INT8_C( 110), -INT8_C(  10), -INT8_C(  15),
           INT8_C(  85),  INT8_C(  97), -INT8_C(  77), -INT8_C( 116),  INT8_C(  28), -INT8_C(  94), -INT8_C(  52),  INT8_C( 123) },
         INT8_C(   4),
         INT8_C(  27) },
      { { -INT8_C(  42),  INT8_C(  58), -INT8_C(  62), -INT8_C(   8), -INT8_C(   9), -INT8_C(  77), -INT8_C(   8), -INT8_C( 116),
          -INT8_C(  51), -INT8_C(  26), -INT8_C( 101), -INT8_C(  27), -INT8_C(  31), -INT8_C(  43), -INT8_C( 121),  INT8_C(   5) },
         INT8_C(   6),
        -INT8_C(   8) },
      { { -INT8_C(  93), -INT8_C(  98),  INT8_C(  27),  INT8_C(   7),  INT8_C( 121), -INT8_C(  74),  INT8_C(  21),  INT8_C(  56),
          -INT8_C(  99),  INT8_C( 122),  INT8_C(  40),  INT8_C(  67),  INT8_C(  48),  INT8_C(   5),  INT8_C(  24),  INT8_C(   3) },
         INT8_C(   2),
         INT8_C(  27) },
      { {  INT8_C(  58),  INT8_C(  65),  INT8_C(  66),  INT8_C(  31),  INT8_C(  74),  INT8_C(  56), -INT8_C(  88),  INT8_C(  13),
           INT8_C(  93), -INT8_C(  26),  INT8_C(  64), -INT8_C(   6), -INT8_C(  98),  INT8_C(  39), -INT8_C(  44), -INT8_C( 111) },
         INT8_C(  13),
         INT8_C(  39) },
      { {  INT8_C(  98), -INT8_C( 106),  INT8_C(  49), -INT8_C(  80), -INT8_C(  81), -INT8_C(  65), -INT8_C(  93),  INT8_C( 108),
           INT8_C(  61),  INT8_C(  27), -INT8_C( 111), -INT8_C(  57),  INT8_C(  54),  INT8_C(  90),  INT8_C( 108), -INT8_C(  66) },
         INT8_C(   5),
        -INT8_C(  65) },
      { { -INT8_C(  23), -INT8_C(  87),  INT8_C(  41),  INT8_C(  72),  INT8_C(  91), -INT8_C(  82), -INT8_C(  38),  INT8_C( 113),
           INT8_C(  53), -INT8_C(   7), -INT8_C(  25),  INT8_C(  34),  INT8_C(  21),  INT8_C( 125), -INT8_C( 112),  INT8_C( 104) },
         INT8_C(   2),
         INT8_C(  41) },
      { { -INT8_C(  28), -INT8_C( 126), -INT8_C(   6), -INT8_C( 119),  INT8_C(  53),  INT8_C(  75),  INT8_C(  77),  INT8_C(  17),
           INT8_C(  68),  INT8_C(  42), -INT8_C(  65),  INT8_C( 107), -INT8_C(  28),  INT8_C(  27), -INT8_C( 115),  INT8_C(  74) },
         INT8_C(   2),
        -INT8_C(   6) },
      { { -INT8_C(  53), -INT8_C(  27),  INT8_C(  78),  INT8_C(  98), -INT8_C(   8),  INT8_C(  72), -INT8_C( 111),  INT8_C( 113),
           INT8_C( 115), -INT8_C( 102),  INT8_C( 101),  INT8_C(  11), -INT8_C( 112),  INT8_C(  95),  INT8_C(  18),  INT8_C( 104) },
         INT8_C(  14),
         INT8_C(  18) }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      #if defined(SIMDE_NATIVE_ALIASES_TESTING)
        int r;
      #else
        int8_t r;
      #endif

      SIMDE_CONSTIFY_16_(simde_wasm_i8x16_extract_lane, r, (HEDLEY_UNREACHABLE(), -1), test_vec[i].lane, a);

      simde_assert_equal_i8(HEDLEY_STATIC_CAST(int8_t, r), test_vec[i].r);
    }
    return 0;
  #else
    fputc('\n', stdout);
    for (int i = 0 ; i < 8 ; i++) {
      simde_v128_t a = simde_test_wasm_i8x16_random();
      int lane = simde_test_codegen_random_i8() & 15;
      int8_t r;

      SIMDE_CONSTIFY_16_(simde_wasm_i8x16_extract_lane, r, (HEDLEY_UNREACHABLE(), -1), lane, a);

      simde_test_wasm_i8x16_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_codegen_write_i8(3, HEDLEY_STATIC_CAST(int8_t, lane), SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_codegen_write_i8(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_i16x8_extract_lane(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      int16_t a[sizeof(simde_v128_t) / sizeof(int16_t)];
      int lane;
      int16_t r;
    } test_vec[] = {
      { { -INT16_C(   906),  INT16_C(  7169),  INT16_C( 30944), -INT16_C( 11643),  INT16_C( 14181), -INT16_C( 20168), -INT16_C( 23087),  INT16_C(  2933) },
         INT8_C(   0),
        -INT16_C(   906) },
      { {  INT16_C(  6721), -INT16_C( 28758), -INT16_C(  8054),  INT16_C( 24686),  INT16_C(  5717), -INT16_C( 24515), -INT16_C( 26388), -INT16_C( 29302) },
         INT8_C(   0),
         INT16_C(  6721) },
      { {  INT16_C( 22761), -INT16_C( 27375), -INT16_C( 15625),  INT16_C(   937), -INT16_C( 16977),  INT16_C( 22963), -INT16_C( 29398), -INT16_C( 24433) },
         INT8_C(   0),
         INT16_C( 22761) },
      { {  INT16_C(  6325), -INT16_C(   861),  INT16_C(   504),  INT16_C( 22625), -INT16_C(  7301), -INT16_C( 30160), -INT16_C(  2431),  INT16_C(  6546) },
         INT8_C(   5),
        -INT16_C( 30160) },
      { { -INT16_C( 32398),  INT16_C(  4739), -INT16_C( 18872), -INT16_C( 17809),  INT16_C( 27976), -INT16_C(  4048),  INT16_C(  3678), -INT16_C( 31220) },
         INT8_C(   3),
        -INT16_C( 17809) },
      { { -INT16_C( 24814), -INT16_C( 20183), -INT16_C( 27951), -INT16_C( 15201), -INT16_C(  8360), -INT16_C( 26861), -INT16_C( 20794),  INT16_C( 12959) },
         INT8_C(   3),
        -INT16_C( 15201) },
      { {  INT16_C( 12421), -INT16_C( 25616), -INT16_C( 29763),  INT16_C( 15601), -INT16_C( 19693),  INT16_C( 26077),  INT16_C( 15426),  INT16_C( 25301) },
         INT8_C(   6),
         INT16_C( 15426) },
      { { -INT16_C(  7727), -INT16_C( 10125), -INT16_C(  9377),  INT16_C( 18105),  INT16_C( 19667), -INT16_C( 19053),  INT16_C(  7455), -INT16_C( 21105) },
         INT8_C(   4),
         INT16_C( 19667) }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      #if defined(SIMDE_NATIVE_ALIASES_TESTING)
        int r;
      #else
        int16_t r;
      #endif

      SIMDE_CONSTIFY_8_(simde_wasm_i16x8_extract_lane, r, (HEDLEY_UNREACHABLE(), -1), test_vec[i].lane, a);

      simde_assert_equal_i16(HEDLEY_STATIC_CAST(int16_t, r), test_vec[i].r);
    }
    return 0;
  #else
    fputc('\n', stdout);
    for (int i = 0 ; i < 8 ; i++) {
      simde_v128_t a = simde_test_wasm_i16x8_random();
      int lane = simde_test_codegen_random_i8() & 7;
      int16_t r;

      SIMDE_CONSTIFY_16_(simde_wasm_i16x8_extract_lane, r, (HEDLEY_UNREACHABLE(), -1), lane, a);

      simde_test_wasm_i16x8_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_codegen_write_i8(3, HEDLEY_STATIC_CAST(int8_t, lane), SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_codegen_write_i16(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_i32x4_extract_lane(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      int32_t a[sizeof(simde_v128_t) / sizeof(int32_t)];
      int lane;
      int32_t r;
    } test_vec[] = {
     { {  INT32_C(   756792865), -INT32_C(  1368706792), -INT32_C(   645137662),  INT32_C(  1746011407) },
         INT8_C(   3),
         INT32_C(  1746011407) },
      { { -INT32_C(  1411521474),  INT32_C(  2054961627),  INT32_C(  1529870027),  INT32_C(   628652433) },
         INT8_C(   1),
         INT32_C(  2054961627) },
      { { -INT32_C(   347128718),  INT32_C(   933465529),  INT32_C(  1449178511), -INT32_C(   808491874) },
         INT8_C(   0),
        -INT32_C(   347128718) },
      { { -INT32_C(  1738636808),  INT32_C(   997204268),  INT32_C(   809022736), -INT32_C(  1082686520) },
         INT8_C(   1),
         INT32_C(   997204268) },
      { { -INT32_C(   758913801),  INT32_C(  1806739278),  INT32_C(   488383444),  INT32_C(   459299671) },
         INT8_C(   1),
         INT32_C(  1806739278) },
      { {  INT32_C(  1848165987),  INT32_C(  1469260163), -INT32_C(   252682573),  INT32_C(  1614037463) },
         INT8_C(   1),
         INT32_C(  1469260163) },
      { { -INT32_C(  1701424272), -INT32_C(  1287042666),  INT32_C(   718744031),  INT32_C(  1916898100) },
         INT8_C(   1),
        -INT32_C(  1287042666) },
      { {  INT32_C(  1600573205), -INT32_C(   822013122),  INT32_C(   502711265),  INT32_C(   490696602) },
         INT8_C(   2),
         INT32_C(   502711265) }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      int32_t r;

      SIMDE_CONSTIFY_8_(simde_wasm_i32x4_extract_lane, r, (HEDLEY_UNREACHABLE(), -1), test_vec[i].lane, a);

      simde_assert_equal_i32(r, test_vec[i].r);
    }
    return 0;
  #else
    fputc('\n', stdout);
    for (int i = 0 ; i < 8 ; i++) {
      simde_v128_t a = simde_test_wasm_i32x4_random();
      int lane = simde_test_codegen_random_i8() & 3;
      int32_t r;

      SIMDE_CONSTIFY_4_(simde_wasm_i32x4_extract_lane, r, (HEDLEY_UNREACHABLE(), -1), lane, a);

      simde_test_wasm_i32x4_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_codegen_write_i8(3, HEDLEY_STATIC_CAST(int8_t, lane), SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_codegen_write_i32(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_i64x2_extract_lane(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      int64_t a[sizeof(simde_v128_t) / sizeof(int64_t)];
      int lane;
      int64_t r;
    } test_vec[] = {
      { {  INT64_C( 2636843521551915334), -INT64_C( 5351161131954626523) },
         INT8_C(   0),
         INT64_C( 2636843521551915334) },
      { {  INT64_C( 6197032444768048498),  INT64_C( 6188100746267396771) },
         INT8_C(   1),
         INT64_C( 6188100746267396771) },
      { {  INT64_C( 6255738156472081343),  INT64_C(  969497047977179313) },
         INT8_C(   0),
         INT64_C( 6255738156472081343) },
      { {  INT64_C( 3225528773830292933),  INT64_C( 1846649344250055198) },
         INT8_C(   0),
         INT64_C( 3225528773830292933) },
      { { -INT64_C( 2426477185094134914),  INT64_C( 7626931911041156383) },
         INT8_C(   1),
         INT64_C( 7626931911041156383) },
      { { -INT64_C(   84432777694957247), -INT64_C( 7029151975626636838) },
         INT8_C(   1),
        -INT64_C( 7029151975626636838) },
      { { -INT64_C( 1316427033033697993),  INT64_C(  107927807876100589) },
         INT8_C(   1),
         INT64_C(  107927807876100589) },
      { {  INT64_C( 8778074077377114071), -INT64_C( 7802952219404414833) },
         INT8_C(   0),
         INT64_C( 8778074077377114071) }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      int64_t r;

      SIMDE_CONSTIFY_8_(simde_wasm_i64x2_extract_lane, r, (HEDLEY_UNREACHABLE(), -1), test_vec[i].lane, a);

      simde_assert_equal_i64(r, test_vec[i].r);
    }
    return 0;
  #else
    fputc('\n', stdout);
    for (int i = 0 ; i < 8 ; i++) {
      simde_v128_t a = simde_test_wasm_i64x2_random();
      int lane = simde_test_codegen_random_i8() & 1;
      int64_t r;

      SIMDE_CONSTIFY_2_(simde_wasm_i64x2_extract_lane, r, (HEDLEY_UNREACHABLE(), -1), lane, a);

      simde_test_wasm_i64x2_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_codegen_write_i8(3, HEDLEY_STATIC_CAST(int8_t, lane), SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_codegen_write_i64(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_u8x16_extract_lane(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      uint8_t a[sizeof(simde_v128_t) / sizeof(int8_t)];
      int lane;
      uint8_t r;
    } test_vec[] = {
      { { UINT8_C(227), UINT8_C(213), UINT8_C(130), UINT8_C(214), UINT8_C( 49), UINT8_C( 21), UINT8_C( 79), UINT8_C(182),
          UINT8_C( 18), UINT8_C(250), UINT8_C( 43), UINT8_C(203), UINT8_C(126), UINT8_C(209), UINT8_C( 43), UINT8_C( 39) },
         INT8_C(  12),
        UINT8_C(126) },
      { { UINT8_C(102), UINT8_C(143), UINT8_C(217), UINT8_C( 34), UINT8_C(180), UINT8_C(190), UINT8_C( 33), UINT8_C(230),
          UINT8_C( 81), UINT8_C(202), UINT8_C(184), UINT8_C(145), UINT8_C( 49), UINT8_C( 35), UINT8_C( 27), UINT8_C( 52) },
         INT8_C(  12),
        UINT8_C( 49) },
      { { UINT8_C(250), UINT8_C(223), UINT8_C( 39), UINT8_C(106), UINT8_C(217), UINT8_C( 37), UINT8_C(125), UINT8_C(110),
          UINT8_C(154), UINT8_C(166), UINT8_C( 15), UINT8_C(  3), UINT8_C( 79), UINT8_C(130), UINT8_C(144), UINT8_C(161) },
         INT8_C(  14),
        UINT8_C(144) },
      { { UINT8_C(244), UINT8_C(117), UINT8_C(250), UINT8_C(222), UINT8_C( 20), UINT8_C(  8), UINT8_C(170), UINT8_C( 62),
          UINT8_C(206), UINT8_C(151), UINT8_C(253), UINT8_C(171), UINT8_C( 11),    UINT8_MAX, UINT8_C(109), UINT8_C(129) },
         INT8_C(  14),
        UINT8_C(109) },
      { { UINT8_C( 28), UINT8_C( 48), UINT8_C(190), UINT8_C(213), UINT8_C( 61), UINT8_C(219), UINT8_C(247), UINT8_C( 96),
          UINT8_C( 37), UINT8_C(179), UINT8_C(120), UINT8_C(120), UINT8_C(180), UINT8_C(152), UINT8_C(142), UINT8_C(199) },
         INT8_C(   9),
        UINT8_C(179) },
      { { UINT8_C(139), UINT8_C(116), UINT8_C( 10), UINT8_C(237), UINT8_C( 57), UINT8_C(215), UINT8_C(217), UINT8_C(224),
             UINT8_MAX, UINT8_C(213), UINT8_C( 66), UINT8_C(227), UINT8_C(237), UINT8_C( 33), UINT8_C(126), UINT8_C(  2) },
         INT8_C(   2),
        UINT8_C( 10) },
      { { UINT8_C(184), UINT8_C(138), UINT8_C(195), UINT8_C(135), UINT8_C( 69), UINT8_C( 18), UINT8_C(228), UINT8_C( 31),
          UINT8_C(131), UINT8_C( 78), UINT8_C(210), UINT8_C(140), UINT8_C(180), UINT8_C(176), UINT8_C(127), UINT8_C( 17) },
         INT8_C(  12),
        UINT8_C(180) },
      { { UINT8_C(181), UINT8_C(150), UINT8_C(  2), UINT8_C( 81), UINT8_C(131), UINT8_C(144), UINT8_C(240), UINT8_C( 79),
          UINT8_C( 59), UINT8_C( 87), UINT8_C( 73), UINT8_C(116), UINT8_C(186), UINT8_C( 68), UINT8_C(121), UINT8_C(245) },
         INT8_C(  12),
        UINT8_C(186) }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      #if defined(SIMDE_NATIVE_ALIASES_TESTING)
        int r;
      #else
        uint8_t r;
      #endif

      SIMDE_CONSTIFY_16_(simde_wasm_u8x16_extract_lane, r, (HEDLEY_UNREACHABLE(), UINT8_C(0)), test_vec[i].lane, a);

      simde_assert_equal_u8(HEDLEY_STATIC_CAST(uint8_t, r), test_vec[i].r);
    }
    return 0;
  #else
    fputc('\n', stdout);
    for (int i = 0 ; i < 8 ; i++) {
      simde_v128_t a = simde_test_wasm_u8x16_random();
      int lane = simde_test_codegen_random_u8() & 15;
      uint8_t r;

      SIMDE_CONSTIFY_16_(simde_wasm_u8x16_extract_lane, r, (HEDLEY_UNREACHABLE(), UINT8_C(0)), lane, a);

      simde_test_wasm_u8x16_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_codegen_write_i8(3, HEDLEY_STATIC_CAST(int8_t, lane), SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_codegen_write_u8(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_u16x8_extract_lane(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      uint16_t a[sizeof(simde_v128_t) / sizeof(int16_t)];
      int lane;
      uint16_t r;
    } test_vec[] = {
      { { UINT16_C(39131), UINT16_C(16207), UINT16_C(53190), UINT16_C(50614), UINT16_C( 5665), UINT16_C(42969), UINT16_C(41690), UINT16_C(64959) },
         INT8_C(   7),
        UINT16_C(64959) },
      { { UINT16_C(17639), UINT16_C(47390), UINT16_C(12711), UINT16_C(29628), UINT16_C(51698), UINT16_C(  147), UINT16_C(11966), UINT16_C(19738) },
         INT8_C(   6),
        UINT16_C(11966) },
      { { UINT16_C(43684), UINT16_C(40619), UINT16_C( 6317), UINT16_C(57260), UINT16_C(29897), UINT16_C( 9662), UINT16_C(25283), UINT16_C(51270) },
         INT8_C(   2),
        UINT16_C( 6317) },
      { { UINT16_C(13107), UINT16_C(46312), UINT16_C(14487), UINT16_C(49241), UINT16_C(47589), UINT16_C(11475), UINT16_C( 2031), UINT16_C( 7583) },
         INT8_C(   6),
        UINT16_C( 2031) },
      { { UINT16_C(18297), UINT16_C(33222), UINT16_C(56154), UINT16_C(25025), UINT16_C(16702), UINT16_C(57340), UINT16_C( 6676), UINT16_C(37910) },
         INT8_C(   4),
        UINT16_C(16702) },
      { { UINT16_C(23465), UINT16_C(21744), UINT16_C(27364), UINT16_C(37238), UINT16_C(56877), UINT16_C(50047), UINT16_C(54279), UINT16_C(10989) },
         INT8_C(   1),
        UINT16_C(21744) },
      { { UINT16_C(15637), UINT16_C( 1650), UINT16_C(27982), UINT16_C(50425), UINT16_C(20136), UINT16_C( 1663), UINT16_C(62860), UINT16_C(58084) },
         INT8_C(   4),
        UINT16_C(20136) },
      { { UINT16_C(27900), UINT16_C(59763), UINT16_C(  747), UINT16_C(59056), UINT16_C(12115), UINT16_C(43248), UINT16_C(27373), UINT16_C(53046) },
         INT8_C(   5),
        UINT16_C(43248) }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      #if defined(SIMDE_NATIVE_ALIASES_TESTING)
        int r;
      #else
        uint16_t r;
      #endif

      SIMDE_CONSTIFY_8_(simde_wasm_u16x8_extract_lane, r, (HEDLEY_UNREACHABLE(), UINT16_C(0)), test_vec[i].lane, a);

      simde_assert_equal_u16(HEDLEY_STATIC_CAST(uint16_t, r), test_vec[i].r);
    }
    return 0;
  #else
    fputc('\n', stdout);
    for (int i = 0 ; i < 8 ; i++) {
      simde_v128_t a = simde_test_wasm_u16x8_random();
      int lane = simde_test_codegen_random_u8() & 7;
      uint16_t r;

      SIMDE_CONSTIFY_16_(simde_wasm_u16x8_extract_lane, r, (HEDLEY_UNREACHABLE(), UINT16_C(0)), lane, a);

      simde_test_wasm_u16x8_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_codegen_write_i8(3, HEDLEY_STATIC_CAST(int8_t, lane), SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_codegen_write_u16(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_f32x4_extract_lane(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      simde_float32 a[sizeof(simde_v128_t) / sizeof(simde_float32)];
      int lane;
      simde_float32 r;
    } test_vec[] = {
      { { SIMDE_FLOAT32_C(  -153.98), SIMDE_FLOAT32_C(  -339.99), SIMDE_FLOAT32_C(  -635.79), SIMDE_FLOAT32_C(   412.76) },
         INT8_C(   1),
        SIMDE_FLOAT32_C(  -339.99) },
      { { SIMDE_FLOAT32_C(   176.22), SIMDE_FLOAT32_C(   411.81), SIMDE_FLOAT32_C(  -260.55), SIMDE_FLOAT32_C(   369.44) },
         INT8_C(   0),
        SIMDE_FLOAT32_C(   176.22) },
      { { SIMDE_FLOAT32_C(  -181.68), SIMDE_FLOAT32_C(  -537.82), SIMDE_FLOAT32_C(   418.71), SIMDE_FLOAT32_C(  -726.54) },
         INT8_C(   3),
        SIMDE_FLOAT32_C(  -726.54) },
      { { SIMDE_FLOAT32_C(   512.24), SIMDE_FLOAT32_C(   376.99), SIMDE_FLOAT32_C(   912.22), SIMDE_FLOAT32_C(   585.66) },
         INT8_C(   2),
        SIMDE_FLOAT32_C(   912.22) },
      { { SIMDE_FLOAT32_C(   147.94), SIMDE_FLOAT32_C(   421.81), SIMDE_FLOAT32_C(   299.53), SIMDE_FLOAT32_C(   -99.96) },
         INT8_C(   1),
        SIMDE_FLOAT32_C(   421.81) },
      { { SIMDE_FLOAT32_C(  -804.14), SIMDE_FLOAT32_C(    43.52), SIMDE_FLOAT32_C(   421.77), SIMDE_FLOAT32_C(  -234.73) },
         INT8_C(   0),
        SIMDE_FLOAT32_C(  -804.14) },
      { { SIMDE_FLOAT32_C(   -27.12), SIMDE_FLOAT32_C(  -404.30), SIMDE_FLOAT32_C(    25.82), SIMDE_FLOAT32_C(   686.03) },
         INT8_C(   1),
        SIMDE_FLOAT32_C(  -404.30) },
      { { SIMDE_FLOAT32_C(  -768.04), SIMDE_FLOAT32_C(  -468.43), SIMDE_FLOAT32_C(   -13.50), SIMDE_FLOAT32_C(  -267.75) },
         INT8_C(   2),
        SIMDE_FLOAT32_C(   -13.50) }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_float32 r;

      SIMDE_CONSTIFY_8_(simde_wasm_f32x4_extract_lane, r, (HEDLEY_UNREACHABLE(), SIMDE_FLOAT32_C(-1.0)), test_vec[i].lane, a);

      simde_assert_equal_f32(r, test_vec[i].r, 1);
    }
    return 0;
  #else
    fputc('\n', stdout);
    for (int i = 0 ; i < 8 ; i++) {
      simde_v128_t a = simde_test_wasm_f32x4_random(-SIMDE_FLOAT32_C(1000.0), SIMDE_FLOAT32_C(1000.0));
      int lane = simde_test_codegen_random_i8() & 3;
      simde_float32 r;

      SIMDE_CONSTIFY_4_(simde_wasm_f32x4_extract_lane, r, (HEDLEY_UNREACHABLE(), -1), lane, a);

      simde_test_wasm_f32x4_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_codegen_write_i8(3, HEDLEY_STATIC_CAST(int8_t, lane), SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_codegen_write_f32(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_f64x2_extract_lane(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      simde_float64 a[sizeof(simde_v128_t) / sizeof(simde_float64)];
      int lane;
      simde_float64 r;
    } test_vec[] = {
      { { SIMDE_FLOAT64_C(  -404.66), SIMDE_FLOAT64_C(  -551.97) },
         INT8_C(   1),
        SIMDE_FLOAT64_C(  -551.97) },
      { { SIMDE_FLOAT64_C(   177.62), SIMDE_FLOAT64_C(   349.36) },
         INT8_C(   0),
        SIMDE_FLOAT64_C(   177.62) },
      { { SIMDE_FLOAT64_C(   805.75), SIMDE_FLOAT64_C(   599.55) },
         INT8_C(   0),
        SIMDE_FLOAT64_C(   805.75) },
      { { SIMDE_FLOAT64_C(   970.77), SIMDE_FLOAT64_C(   992.99) },
         INT8_C(   0),
        SIMDE_FLOAT64_C(   970.77) },
      { { SIMDE_FLOAT64_C(  -605.25), SIMDE_FLOAT64_C(  -702.40) },
         INT8_C(   0),
        SIMDE_FLOAT64_C(  -605.25) },
      { { SIMDE_FLOAT64_C(     4.63), SIMDE_FLOAT64_C(  -309.89) },
         INT8_C(   0),
        SIMDE_FLOAT64_C(     4.63) },
      { { SIMDE_FLOAT64_C(   188.34), SIMDE_FLOAT64_C(  -777.46) },
         INT8_C(   0),
        SIMDE_FLOAT64_C(   188.34) },
      { { SIMDE_FLOAT64_C(    91.45), SIMDE_FLOAT64_C(   754.28) },
         INT8_C(   0),
        SIMDE_FLOAT64_C(    91.45) }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_float64 r;

      SIMDE_CONSTIFY_8_(simde_wasm_f64x2_extract_lane, r, (HEDLEY_UNREACHABLE(), -1), test_vec[i].lane, a);

      simde_assert_equal_f64(r, test_vec[i].r, 1);
    }
    return 0;
  #else
    fputc('\n', stdout);
    for (int i = 0 ; i < 8 ; i++) {
      simde_v128_t a = simde_test_wasm_f64x2_random(-SIMDE_FLOAT64_C(1000.0), SIMDE_FLOAT64_C(1000.0));
      int lane = simde_test_codegen_random_i8() & 1;
      simde_float64 r;

      SIMDE_CONSTIFY_2_(simde_wasm_f64x2_extract_lane, r, (HEDLEY_UNREACHABLE(), -1), lane, a);

      simde_test_wasm_f64x2_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_codegen_write_i8(3, HEDLEY_STATIC_CAST(int8_t, lane), SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_codegen_write_f64(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_i8x16_extract_lane)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_i16x8_extract_lane)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_i32x4_extract_lane)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_i64x2_extract_lane)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_u8x16_extract_lane)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_u16x8_extract_lane)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_f32x4_extract_lane)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_f64x2_extract_lane)
SIMDE_TEST_FUNC_LIST_END

#include "test-simd128-footer.h"
