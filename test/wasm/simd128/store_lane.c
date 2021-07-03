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

#define SIMDE_TEST_WASM_SIMD128_INSN store_lane
#include "../../../simde/wasm/simd128.h"
#include "test-simd128.h"

static int
test_simde_wasm_v128_store8_lane(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      int8_t v[sizeof(simde_v128_t) / sizeof(int8_t)];
      int32_t l;
      int8_t a;
    } test_vec[] = {
     { { -INT8_C(  73), -INT8_C( 100),  INT8_C(  49), -INT8_C(  91),  INT8_C(  29), -INT8_C(  74),  INT8_C( 117), -INT8_C( 113),
           INT8_C(  30), -INT8_C(   2),  INT8_C(  27),  INT8_C(  35),      INT8_MIN,  INT8_C(  42),  INT8_C(  36),  INT8_C(  80) },
         INT32_C(          12),
             INT8_MIN },
      { { -INT8_C(  49),  INT8_C(  45),  INT8_C(  94), -INT8_C(  94), -INT8_C( 102),  INT8_C(  82),  INT8_C(  48), -INT8_C(  79),
           INT8_C(  88),  INT8_C( 118),  INT8_C(  75),  INT8_C(  18),  INT8_C(  64),  INT8_C(  38), -INT8_C(  67),  INT8_C(  93) },
         INT32_C(           2),
         INT8_C(  94) },
      { { -INT8_C(  63), -INT8_C(  50),  INT8_C(  21), -INT8_C( 103), -INT8_C(  69),  INT8_C(  49), -INT8_C(  14), -INT8_C(  44),
          -INT8_C( 108), -INT8_C(  93), -INT8_C(  36), -INT8_C( 119),  INT8_C( 118), -INT8_C(  67),  INT8_C( 113),  INT8_C( 118) },
         INT32_C(           2),
         INT8_C(  21) },
      { { -INT8_C(  54), -INT8_C(  63),  INT8_C(  26),  INT8_C(  76),  INT8_C(  21),  INT8_C(  72),  INT8_C(  62), -INT8_C(   3),
           INT8_C(  75),  INT8_C(  48),  INT8_C(   0),  INT8_C(  18),  INT8_C( 123),  INT8_C(  16),  INT8_C(  74),  INT8_C(  69) },
         INT32_C(           2),
         INT8_C(  26) },
      { {  INT8_C(  57),  INT8_C(  18),  INT8_C(  74), -INT8_C( 111),  INT8_C(  17),  INT8_C( 102),  INT8_C(  16),  INT8_C(  48),
           INT8_C(  26), -INT8_C(  86),  INT8_C(  59), -INT8_C(   8), -INT8_C( 102),  INT8_C( 110),  INT8_C(   2), -INT8_C(  19) },
         INT32_C(          12),
        -INT8_C( 102) },
      { { -INT8_C(  43), -INT8_C( 120), -INT8_C(  53), -INT8_C( 108), -INT8_C(  61), -INT8_C(  35), -INT8_C(  92), -INT8_C(  18),
           INT8_C(   3), -INT8_C(  30), -INT8_C(  79),  INT8_C(  31), -INT8_C( 127),  INT8_C(  11),  INT8_C(  25), -INT8_C( 107) },
         INT32_C(           0),
        -INT8_C(  43) },
      { { -INT8_C(  70),  INT8_C(  84),  INT8_C(  95), -INT8_C(   8), -INT8_C(  33), -INT8_C( 105), -INT8_C( 112),  INT8_C(  37),
           INT8_C(  79), -INT8_C(  55),  INT8_C(   4), -INT8_C(  22),  INT8_C(  43),  INT8_C(  40), -INT8_C( 106), -INT8_C( 115) },
         INT32_C(           0),
        -INT8_C(  70) },
      { {  INT8_C(  96), -INT8_C( 125), -INT8_C(  50), -INT8_C(   6), -INT8_C(  24),  INT8_C(  18),  INT8_C(  75),  INT8_C( 120),
           INT8_C(  53),  INT8_C(  60),  INT8_C(  79), -INT8_C(  75),  INT8_C(  48),  INT8_C(  39), -INT8_C(  17), -INT8_C( 104) },
         INT32_C(          10),
         INT8_C(  79) }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t v = simde_wasm_v128_load(test_vec[i].v);
      int8_t a;
      SIMDE_CONSTIFY_16_NO_RESULT_(simde_wasm_v128_store8_lane, (HEDLEY_UNREACHABLE(), HEDLEY_STATIC_CAST(void, 0)), test_vec[i].l, &a, v);
      simde_assert_equal_i8(a, test_vec[i].a);
    }
    return 0;
  #else
    fputc('\n', stdout);
    for (int i = 0 ; i < 8 ; i++) {
      int8_t a;
      int32_t l = simde_test_codegen_random_i8() & 15;
      simde_v128_t
        v = simde_test_wasm_i8x16_random();

      SIMDE_CONSTIFY_16_NO_RESULT_(simde_wasm_v128_store8_lane, (HEDLEY_UNREACHABLE(), HEDLEY_STATIC_CAST(void, 0)), l, &a, v);

      simde_test_wasm_i8x16_write(3, v, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_codegen_write_i32(3, l, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_codegen_write_i8(3, a, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_v128_store16_lane(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      int16_t v[sizeof(simde_v128_t) / sizeof(int16_t)];
      int32_t l;
      int16_t a;
    } test_vec[] = {
      { { -INT16_C(  3165),  INT16_C( 18091), -INT16_C(   366),  INT16_C(  1657), -INT16_C( 10231),  INT16_C(  8128),  INT16_C( 15989), -INT16_C( 20421) },
         INT32_C(           3),
         INT32_C(        1657) },
      { {  INT16_C( 29379), -INT16_C( 15182), -INT16_C(  6275),  INT16_C( 12773),  INT16_C(  3801), -INT16_C(  1294), -INT16_C( 27121), -INT16_C(  1082) },
         INT32_C(           4),
         INT32_C(        3801) },
      { {  INT16_C( 18088),  INT16_C( 15624), -INT16_C(   894), -INT16_C( 22905), -INT16_C( 23745),  INT16_C(  2253),  INT16_C(  5134), -INT16_C( 11474) },
         INT32_C(           7),
        -INT32_C(       11474) },
      { {  INT16_C( 20997),  INT16_C(  1911), -INT16_C(  6701), -INT16_C( 11700),  INT16_C( 12479), -INT16_C( 12226),  INT16_C( 15670), -INT16_C( 17182) },
         INT32_C(           3),
        -INT32_C(       11700) },
      { { -INT16_C(  6508),  INT16_C( 26432),  INT16_C( 28442),  INT16_C(  5718), -INT16_C(  1192), -INT16_C( 11379),  INT16_C( 26073),  INT16_C( 13438) },
         INT32_C(           4),
        -INT32_C(        1192) },
      { { -INT16_C( 20764),  INT16_C( 22268), -INT16_C( 31801),  INT16_C( 29970), -INT16_C( 22337), -INT16_C( 11410),  INT16_C(  3538),  INT16_C(  8850) },
         INT32_C(           5),
        -INT32_C(       11410) },
      { { -INT16_C(  5275), -INT16_C( 14863),  INT16_C(  1201), -INT16_C(  5055), -INT16_C(   498), -INT16_C( 20763), -INT16_C( 12043), -INT16_C(  9993) },
         INT32_C(           6),
        -INT32_C(       12043) },
      { { -INT16_C(  6409), -INT16_C(   548),  INT16_C( 21654),  INT16_C(  7667), -INT16_C( 21366), -INT16_C( 24578), -INT16_C(  2107), -INT16_C( 24562) },
         INT32_C(           2),
         INT32_C(       21654) }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t v = simde_wasm_v128_load(test_vec[i].v);
      int16_t a;
      SIMDE_CONSTIFY_8_NO_RESULT_(simde_wasm_v128_store16_lane, (HEDLEY_UNREACHABLE(), HEDLEY_STATIC_CAST(void, 0)), test_vec[i].l, &a, v);
      simde_assert_equal_i16(a, test_vec[i].a);
    }
    return 0;
  #else
    fputc('\n', stdout);
    for (int i = 0 ; i < 8 ; i++) {
      int16_t a;
      int32_t l = simde_test_codegen_random_i16() & 7;
      simde_v128_t
        v = simde_test_wasm_i16x8_random();

      SIMDE_CONSTIFY_8_NO_RESULT_(simde_wasm_v128_store16_lane, (HEDLEY_UNREACHABLE(), HEDLEY_STATIC_CAST(void, 0)), l, &a, v);

      simde_test_wasm_i16x8_write(3, v, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_codegen_write_i32(3, l, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_codegen_write_i16(3, a, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_v128_store32_lane(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      int32_t v[sizeof(simde_v128_t) / sizeof(int32_t)];
      int32_t l;
      int32_t a;
    } test_vec[] = {
      { {  INT32_C(  2138470531),  INT32_C(  1160640758),  INT32_C(  1827171799), -INT32_C(   612042150) },
         INT32_C(           1),
         INT32_C(  1160640758) },
      { { -INT32_C(  1873859609), -INT32_C(  1552174528), -INT32_C(   333470808),  INT32_C(   550009210) },
         INT32_C(           3),
         INT32_C(   550009210) },
      { {  INT32_C(  1200309925),  INT32_C(   355929792),  INT32_C(  1936757152),  INT32_C(  1177469226) },
         INT32_C(           2),
         INT32_C(  1936757152) },
      { { -INT32_C(  1458667269),  INT32_C(   780586327),  INT32_C(   648232594),  INT32_C(   899895017) },
         INT32_C(           3),
         INT32_C(   899895017) },
      { {  INT32_C(   239715384),  INT32_C(   834448132),  INT32_C(  2071014937),  INT32_C(  1559388937) },
         INT32_C(           3),
         INT32_C(  1559388937) },
      { { -INT32_C(  1067211760), -INT32_C(  2111112451),  INT32_C(   977807750),  INT32_C(   582417746) },
         INT32_C(           3),
         INT32_C(   582417746) },
      { { -INT32_C(  1481215805), -INT32_C(  1421131598), -INT32_C(   371900839), -INT32_C(  1902189575) },
         INT32_C(           0),
        -INT32_C(  1481215805) },
      { {  INT32_C(   504339854), -INT32_C(   401529672), -INT32_C(   503846253), -INT32_C(   571054688) },
         INT32_C(           2),
        -INT32_C(   503846253) }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t v = simde_wasm_v128_load(test_vec[i].v);
      int32_t a;
      SIMDE_CONSTIFY_4_NO_RESULT_(simde_wasm_v128_store32_lane, (HEDLEY_UNREACHABLE(), HEDLEY_STATIC_CAST(void, 0)), test_vec[i].l, &a, v);
      simde_assert_equal_i32(a, test_vec[i].a);
    }
    return 0;
  #else
    fputc('\n', stdout);
    for (int i = 0 ; i < 8 ; i++) {
      int32_t a;
      int32_t l = simde_test_codegen_random_i32() & 3;
      simde_v128_t
        v = simde_test_wasm_i32x4_random();

      SIMDE_CONSTIFY_4_NO_RESULT_(simde_wasm_v128_store32_lane, (HEDLEY_UNREACHABLE(), HEDLEY_STATIC_CAST(void, 0)), l, &a, v);

      simde_test_wasm_i32x4_write(3, v, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_codegen_write_i32(3, l, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_codegen_write_i32(3, a, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_v128_store64_lane(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      int64_t v[sizeof(simde_v128_t) / sizeof(int64_t)];
      int32_t l;
      int64_t a;
    } test_vec[] = {
      { { -INT64_C( 4137192990872523685), -INT64_C( 7091598216866580829) },
         INT32_C(           1),
        -INT64_C( 7091598216866580829) },
      { {  INT64_C(   61724595482950107),  INT64_C( 1776818501744792754) },
         INT32_C(           1),
         INT64_C( 1776818501744792754) },
      { {  INT64_C( 6494485681108733354), -INT64_C( 6312818018763299675) },
         INT32_C(           0),
         INT64_C( 6494485681108733354) },
      { {  INT64_C( 5939382018905088258), -INT64_C( 5361483153353905789) },
         INT32_C(           1),
        -INT64_C( 5361483153353905789) },
      { { -INT64_C( 7293036291305502208),  INT64_C( 7049958261353686344) },
         INT32_C(           1),
         INT64_C( 7049958261353686344) },
      { { -INT64_C( 4707420992470558921),  INT64_C( 3343752369585555945) },
         INT32_C(           1),
         INT64_C( 3343752369585555945) },
      { {  INT64_C( 2570312175576797749), -INT64_C( 7745465661716581333) },
         INT32_C(           0),
         INT64_C( 2570312175576797749) },
      { { -INT64_C( 8543718416742523674),  INT64_C( 2495108704307671423) },
         INT32_C(           1),
         INT64_C( 2495108704307671423) }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t v = simde_wasm_v128_load(test_vec[i].v);
      int64_t a;
      SIMDE_CONSTIFY_2_NO_RESULT_(simde_wasm_v128_store64_lane, (HEDLEY_UNREACHABLE(), HEDLEY_STATIC_CAST(void, 0)), test_vec[i].l, &a, v);
      simde_assert_equal_i64(a, test_vec[i].a);
    }
    return 0;
  #else
    fputc('\n', stdout);
    for (int i = 0 ; i < 8 ; i++) {
      int64_t a;
      int32_t l = simde_test_codegen_random_i64() & 1;
      simde_v128_t
        v = simde_test_wasm_i64x2_random();

      SIMDE_CONSTIFY_2_NO_RESULT_(simde_wasm_v128_store64_lane, (HEDLEY_UNREACHABLE(), HEDLEY_STATIC_CAST(void, 0)), l, &a, v);

      simde_test_wasm_i64x2_write(3, v, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_codegen_write_i32(3, l, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_codegen_write_i64(3, a, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_v128_store8_lane)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_v128_store16_lane)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_v128_store32_lane)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_v128_store64_lane)
SIMDE_TEST_FUNC_LIST_END

#include "test-simd128-footer.h"
