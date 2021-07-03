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

#define SIMDE_TEST_WASM_SIMD128_INSN replace_lane
#include "../../../simde/wasm/simd128.h"
#include "test-simd128.h"

static int
test_simde_wasm_i8x16_replace_lane(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      int8_t a[sizeof(simde_v128_t) / sizeof(int8_t)];
      int8_t value;
      int8_t r[sizeof(simde_v128_t) / sizeof(int8_t)];
    } test_vec[8] = {
      { { -INT8_C( 107), -INT8_C(  78),  INT8_C(  52), -INT8_C(  41),  INT8_C(  28),  INT8_C(  59),  INT8_C(  76), -INT8_C(  45),
           INT8_C(  80), -INT8_C(  79), -INT8_C(  75),  INT8_C( 115), -INT8_C(  52),  INT8_C(   0), -INT8_C(  23), -INT8_C(  69) },
        -INT8_C(  99),
        { -INT8_C( 107), -INT8_C(  78),  INT8_C(  52), -INT8_C(  99),  INT8_C(  28),  INT8_C(  59),  INT8_C(  76), -INT8_C(  45),
           INT8_C(  80), -INT8_C(  79), -INT8_C(  75),  INT8_C( 115), -INT8_C(  52),  INT8_C(   0), -INT8_C(  23), -INT8_C(  69) } },
      { {  INT8_C(  92),      INT8_MAX,  INT8_C(  53),  INT8_C(  65),  INT8_C(  54),  INT8_C( 119),  INT8_C(  94), -INT8_C(  13),
          -INT8_C(  80), -INT8_C(   4),  INT8_C(  95), -INT8_C( 115),  INT8_C(  58),  INT8_C(  33), -INT8_C( 126),  INT8_C(  25) },
         INT8_C(   2),
        {  INT8_C(  92),      INT8_MAX,  INT8_C(  53),  INT8_C(   2),  INT8_C(  54),  INT8_C( 119),  INT8_C(  94), -INT8_C(  13),
          -INT8_C(  80), -INT8_C(   4),  INT8_C(  95), -INT8_C( 115),  INT8_C(  58),  INT8_C(  33), -INT8_C( 126),  INT8_C(  25) } },
      { {  INT8_C(  40),  INT8_C(   3), -INT8_C(  91),  INT8_C( 115),  INT8_C( 105), -INT8_C(  95),  INT8_C(  56), -INT8_C(  70),
          -INT8_C(  96), -INT8_C( 115), -INT8_C( 109),  INT8_C(  37), -INT8_C(  10), -INT8_C(  68), -INT8_C(  63), -INT8_C(   7) },
        -INT8_C(  79),
        {  INT8_C(  40),  INT8_C(   3), -INT8_C(  91), -INT8_C(  79),  INT8_C( 105), -INT8_C(  95),  INT8_C(  56), -INT8_C(  70),
          -INT8_C(  96), -INT8_C( 115), -INT8_C( 109),  INT8_C(  37), -INT8_C(  10), -INT8_C(  68), -INT8_C(  63), -INT8_C(   7) } },
      { {  INT8_C( 109),  INT8_C(  28),  INT8_C(  58), -INT8_C(  41),  INT8_C(  87),  INT8_C(  62),  INT8_C(  38), -INT8_C(  32),
          -INT8_C(  93),  INT8_C(  65),  INT8_C(  94),  INT8_C(  81),  INT8_C(  85), -INT8_C(  70),  INT8_C(  58), -INT8_C(  79) },
        -INT8_C(  33),
        {  INT8_C( 109),  INT8_C(  28),  INT8_C(  58), -INT8_C(  33),  INT8_C(  87),  INT8_C(  62),  INT8_C(  38), -INT8_C(  32),
          -INT8_C(  93),  INT8_C(  65),  INT8_C(  94),  INT8_C(  81),  INT8_C(  85), -INT8_C(  70),  INT8_C(  58), -INT8_C(  79) } },
      { {  INT8_C(  80), -INT8_C(  76), -INT8_C(  68),  INT8_C(  84), -INT8_C(  96), -INT8_C( 125), -INT8_C(  40), -INT8_C(  50),
          -INT8_C(  70),  INT8_C(  87),  INT8_C(  58),  INT8_C(  12),  INT8_C( 113),  INT8_C( 102),  INT8_C(  99), -INT8_C(  18) },
         INT8_C(  35),
        {  INT8_C(  80), -INT8_C(  76), -INT8_C(  68),  INT8_C(  35), -INT8_C(  96), -INT8_C( 125), -INT8_C(  40), -INT8_C(  50),
          -INT8_C(  70),  INT8_C(  87),  INT8_C(  58),  INT8_C(  12),  INT8_C( 113),  INT8_C( 102),  INT8_C(  99), -INT8_C(  18) } },
      { { -INT8_C( 102), -INT8_C( 102),  INT8_C(  10), -INT8_C(   4), -INT8_C(  79), -INT8_C(  67),  INT8_C(  82), -INT8_C( 104),
           INT8_C(   3), -INT8_C(  27),  INT8_C(   9),  INT8_C(  46), -INT8_C(  65), -INT8_C(  25),  INT8_C( 109),  INT8_C(  41) },
        -INT8_C(  67),
        { -INT8_C( 102), -INT8_C( 102),  INT8_C(  10), -INT8_C(  67), -INT8_C(  79), -INT8_C(  67),  INT8_C(  82), -INT8_C( 104),
           INT8_C(   3), -INT8_C(  27),  INT8_C(   9),  INT8_C(  46), -INT8_C(  65), -INT8_C(  25),  INT8_C( 109),  INT8_C(  41) } },
      { { -INT8_C(  75),  INT8_C(  16), -INT8_C(  17), -INT8_C(  84),  INT8_C( 124),  INT8_C(   5), -INT8_C( 118),  INT8_C(  33),
          -INT8_C( 124),  INT8_C(  64), -INT8_C(  37), -INT8_C(  80), -INT8_C(  95),  INT8_C(  51), -INT8_C(  64), -INT8_C(  13) },
        -INT8_C(  35),
        { -INT8_C(  75),  INT8_C(  16), -INT8_C(  17), -INT8_C(  35),  INT8_C( 124),  INT8_C(   5), -INT8_C( 118),  INT8_C(  33),
          -INT8_C( 124),  INT8_C(  64), -INT8_C(  37), -INT8_C(  80), -INT8_C(  95),  INT8_C(  51), -INT8_C(  64), -INT8_C(  13) } },
      { {  INT8_C(  69),  INT8_C(  10), -INT8_C( 102),  INT8_C(  59),  INT8_C(  62),  INT8_C(  60), -INT8_C(  95),  INT8_C(  98),
           INT8_C(  36), -INT8_C( 127),  INT8_C(  63),  INT8_C(  63),  INT8_C(  14),  INT8_C(  45), -INT8_C(  35),  INT8_C(  59) },
        -INT8_C(   9),
        {  INT8_C(  69),  INT8_C(  10), -INT8_C( 102), -INT8_C(   9),  INT8_C(  62),  INT8_C(  60), -INT8_C(  95),  INT8_C(  98),
           INT8_C(  36), -INT8_C( 127),  INT8_C(  63),  INT8_C(  63),  INT8_C(  14),  INT8_C(  45), -INT8_C(  35),  INT8_C(  59) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t r = simde_wasm_i8x16_replace_lane(a, 3, test_vec[i].value);

      simde_test_wasm_i8x16_assert_equal(r, simde_wasm_v128_load(test_vec[i].r));
    }
    return 0;
  #else
    fputc('\n', stdout);
    for (int i = 0 ; i < 8 ; i++) {
      simde_v128_t a = simde_test_wasm_i8x16_random();
      int8_t value = simde_test_codegen_random_i8();
      simde_v128_t r = simde_wasm_i8x16_replace_lane(a, 3, value);

      simde_test_wasm_i8x16_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_codegen_write_i8(3, HEDLEY_STATIC_CAST(int8_t, value), SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_wasm_i8x16_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_i16x8_replace_lane(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      int16_t a[sizeof(simde_v128_t) / sizeof(int16_t)];
      int16_t value;
      int16_t r[sizeof(simde_v128_t) / sizeof(int16_t)];
    } test_vec[8] = {
      { {  INT16_C( 23234), -INT16_C( 31278),  INT16_C( 12166), -INT16_C( 28465), -INT16_C( 31682),  INT16_C( 30901),  INT16_C( 12959), -INT16_C( 16110) },
        -INT16_C( 15060),
        {  INT16_C( 23234), -INT16_C( 31278),  INT16_C( 12166), -INT16_C( 28465), -INT16_C( 31682),  INT16_C( 30901), -INT16_C( 15060), -INT16_C( 16110) } },
      { {  INT16_C(  2154), -INT16_C(  5793), -INT16_C( 29973), -INT16_C( 24097), -INT16_C( 12613),  INT16_C( 31165), -INT16_C( 25149), -INT16_C( 21906) },
        -INT16_C( 25837),
        {  INT16_C(  2154), -INT16_C(  5793), -INT16_C( 29973), -INT16_C( 24097), -INT16_C( 12613),  INT16_C( 31165), -INT16_C( 25837), -INT16_C( 21906) } },
      { { -INT16_C( 12800), -INT16_C(  6553), -INT16_C( 32639), -INT16_C(  4429), -INT16_C(  8756), -INT16_C( 20247),  INT16_C(   685), -INT16_C( 23041) },
        -INT16_C( 28530),
        { -INT16_C( 12800), -INT16_C(  6553), -INT16_C( 32639), -INT16_C(  4429), -INT16_C(  8756), -INT16_C( 20247), -INT16_C( 28530), -INT16_C( 23041) } },
      { { -INT16_C( 17364), -INT16_C( 30653), -INT16_C(    11),  INT16_C( 25929),  INT16_C(  2973),  INT16_C( 21650),  INT16_C( 18382),  INT16_C( 10368) },
         INT16_C( 31358),
        { -INT16_C( 17364), -INT16_C( 30653), -INT16_C(    11),  INT16_C( 25929),  INT16_C(  2973),  INT16_C( 21650),  INT16_C( 31358),  INT16_C( 10368) } },
      { { -INT16_C( 12219),  INT16_C(  2717), -INT16_C( 32004), -INT16_C( 24048), -INT16_C( 30085), -INT16_C(  3940), -INT16_C( 32007), -INT16_C(  6717) },
         INT16_C( 16433),
        { -INT16_C( 12219),  INT16_C(  2717), -INT16_C( 32004), -INT16_C( 24048), -INT16_C( 30085), -INT16_C(  3940),  INT16_C( 16433), -INT16_C(  6717) } },
      { { -INT16_C( 13107), -INT16_C( 20450), -INT16_C( 13459), -INT16_C( 18888), -INT16_C( 11693),  INT16_C( 30367),  INT16_C( 27765),  INT16_C( 23829) },
         INT16_C( 12783),
        { -INT16_C( 13107), -INT16_C( 20450), -INT16_C( 13459), -INT16_C( 18888), -INT16_C( 11693),  INT16_C( 30367),  INT16_C( 12783),  INT16_C( 23829) } },
      { {  INT16_C( 14255), -INT16_C( 16976),  INT16_C( 19931), -INT16_C( 14658), -INT16_C( 22702),  INT16_C( 15017),  INT16_C( 21250), -INT16_C(  2447) },
         INT16_C( 30845),
        {  INT16_C( 14255), -INT16_C( 16976),  INT16_C( 19931), -INT16_C( 14658), -INT16_C( 22702),  INT16_C( 15017),  INT16_C( 30845), -INT16_C(  2447) } },
      { { -INT16_C( 26939),  INT16_C( 23318),  INT16_C(  2767), -INT16_C( 21925), -INT16_C( 28487), -INT16_C( 19452), -INT16_C(  3968),  INT16_C( 22101) },
         INT16_C( 27797),
        { -INT16_C( 26939),  INT16_C( 23318),  INT16_C(  2767), -INT16_C( 21925), -INT16_C( 28487), -INT16_C( 19452),  INT16_C( 27797),  INT16_C( 22101) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t r = simde_wasm_i16x8_replace_lane(a, 6, test_vec[i].value);

      simde_test_wasm_i16x8_assert_equal(r, simde_wasm_v128_load(test_vec[i].r));
    }
    return 0;
  #else
    fputc('\n', stdout);
    for (int i = 0 ; i < 8 ; i++) {
      simde_v128_t a = simde_test_wasm_i16x8_random();
      int16_t value = simde_test_codegen_random_i16();
      simde_v128_t r = simde_wasm_i16x8_replace_lane(a, 6, value);

      simde_test_wasm_i16x8_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_codegen_write_i16(3, HEDLEY_STATIC_CAST(int16_t, value), SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_wasm_i16x8_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_i32x4_replace_lane(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      int32_t a[sizeof(simde_v128_t) / sizeof(int32_t)];
      int32_t value;
      int32_t r[sizeof(simde_v128_t) / sizeof(int32_t)];
    } test_vec[8] = {
      { {  INT32_C(  1811392718), -INT32_C(  2062798284),  INT32_C(   934953162), -INT32_C(   857472329) },
        -INT32_C(   581302919),
        {  INT32_C(  1811392718), -INT32_C(  2062798284), -INT32_C(   581302919), -INT32_C(   857472329) } },
      { { -INT32_C(  1961980491),  INT32_C(   383253223), -INT32_C(   973021466),  INT32_C(   994203356) },
        -INT32_C(  1402248270),
        { -INT32_C(  1961980491),  INT32_C(   383253223), -INT32_C(  1402248270),  INT32_C(   994203356) } },
      { { -INT32_C(   115419555), -INT32_C(   971374995),  INT32_C(   397259510), -INT32_C(  1606952230) },
         INT32_C(  1646196257),
        { -INT32_C(   115419555), -INT32_C(   971374995),  INT32_C(  1646196257), -INT32_C(  1606952230) } },
      { {  INT32_C(   294799206), -INT32_C(   905908642), -INT32_C(   184900110), -INT32_C(  1985206259) },
         INT32_C(   957442149),
        {  INT32_C(   294799206), -INT32_C(   905908642),  INT32_C(   957442149), -INT32_C(  1985206259) } },
      { {  INT32_C(   298479969), -INT32_C(   294980735),  INT32_C(  1868635192), -INT32_C(   585491691) },
        -INT32_C(  2124763917),
        {  INT32_C(   298479969), -INT32_C(   294980735), -INT32_C(  2124763917), -INT32_C(   585491691) } },
      { {  INT32_C(   457562035), -INT32_C(  1935607075), -INT32_C(   359556668),  INT32_C(  1133620468) },
         INT32_C(   282505203),
        {  INT32_C(   457562035), -INT32_C(  1935607075),  INT32_C(   282505203),  INT32_C(  1133620468) } },
      { { -INT32_C(  2086939803), -INT32_C(  1180839318), -INT32_C(  1518383531), -INT32_C(   727904836) },
         INT32_C(  1692563710),
        { -INT32_C(  2086939803), -INT32_C(  1180839318),  INT32_C(  1692563710), -INT32_C(   727904836) } },
      { { -INT32_C(  1434983519), -INT32_C(   230125435),  INT32_C(  2107873055),  INT32_C(    33431623) },
        -INT32_C(  1650768362),
        { -INT32_C(  1434983519), -INT32_C(   230125435), -INT32_C(  1650768362),  INT32_C(    33431623) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t r = simde_wasm_i32x4_replace_lane(a, 2, test_vec[i].value);

      simde_test_wasm_i32x4_assert_equal(r, simde_wasm_v128_load(test_vec[i].r));
    }
    return 0;
  #else
    fputc('\n', stdout);
    for (int i = 0 ; i < 8 ; i++) {
      simde_v128_t a = simde_test_wasm_i32x4_random();
      int32_t value = simde_test_codegen_random_i32();
      simde_v128_t r = simde_wasm_i32x4_replace_lane(a, 2, value);

      simde_test_wasm_i32x4_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_codegen_write_i32(3, HEDLEY_STATIC_CAST(int32_t, value), SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_wasm_i32x4_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_i64x2_replace_lane(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      int64_t a[sizeof(simde_v128_t) / sizeof(int64_t)];
      int64_t value;
      int64_t r[sizeof(simde_v128_t) / sizeof(int64_t)];
    } test_vec[8] = {
      { { -INT64_C( 5128361027457271068), -INT64_C( 1763441547244327171) },
        -INT64_C(  894813564968289699),
        { -INT64_C( 5128361027457271068), -INT64_C(  894813564968289699) } },
      { {  INT64_C( 2620333538372173648),  INT64_C( 4181109108593626405) },
         INT64_C( 5702841898314310841),
        {  INT64_C( 2620333538372173648),  INT64_C( 5702841898314310841) } },
      { { -INT64_C( 4487417419720414331), -INT64_C( 5632697144368591242) },
        -INT64_C( 7240731775566591236),
        { -INT64_C( 4487417419720414331), -INT64_C( 7240731775566591236) } },
      { {  INT64_C( 5921496085276238420), -INT64_C( 7220881583634218936) },
        -INT64_C( 8662211999842106855),
        {  INT64_C( 5921496085276238420), -INT64_C( 8662211999842106855) } },
      { {  INT64_C( 7984039841203167383),  INT64_C( 9146396469244088028) },
         INT64_C( 8742993520985224035),
        {  INT64_C( 7984039841203167383),  INT64_C( 8742993520985224035) } },
      { {  INT64_C( 5445828532663782335), -INT64_C( 1267345109488357785) },
        -INT64_C( 1724154444128323186),
        {  INT64_C( 5445828532663782335), -INT64_C( 1724154444128323186) } },
      { { -INT64_C( 6452914029563326131), -INT64_C( 4386274785913808439) },
         INT64_C( 3914483883429769580),
        { -INT64_C( 6452914029563326131),  INT64_C( 3914483883429769580) } },
      { {  INT64_C( 4426343906667636105), -INT64_C( 4756980401638739391) },
        -INT64_C( 6087272353343722790),
        {  INT64_C( 4426343906667636105), -INT64_C( 6087272353343722790) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t r = simde_wasm_i64x2_replace_lane(a, 1, test_vec[i].value);

      simde_test_wasm_i64x2_assert_equal(r, simde_wasm_v128_load(test_vec[i].r));
    }
    return 0;
  #else
    fputc('\n', stdout);
    for (int i = 0 ; i < 8 ; i++) {
      simde_v128_t a = simde_test_wasm_i64x2_random();
      int64_t value = simde_test_codegen_random_i64();
      simde_v128_t r = simde_wasm_i64x2_replace_lane(a, 1, value);

      simde_test_wasm_i64x2_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_codegen_write_i64(3, HEDLEY_STATIC_CAST(int64_t, value), SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_wasm_i64x2_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_f32x4_replace_lane(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      simde_float32 a[sizeof(simde_v128_t) / sizeof(simde_float32)];
      simde_float32 value;
      simde_float32 r[sizeof(simde_v128_t) / sizeof(simde_float32)];
    } test_vec[8] = {
      { { SIMDE_FLOAT32_C(  -534.96), SIMDE_FLOAT32_C(  -328.94), SIMDE_FLOAT32_C(   638.89), SIMDE_FLOAT32_C(   375.81) },
        SIMDE_FLOAT32_C(   100.82),
        { SIMDE_FLOAT32_C(  -534.96), SIMDE_FLOAT32_C(  -328.94), SIMDE_FLOAT32_C(   638.89), SIMDE_FLOAT32_C(   100.82) } },
      { { SIMDE_FLOAT32_C(   980.77), SIMDE_FLOAT32_C(  -660.40), SIMDE_FLOAT32_C(   985.61), SIMDE_FLOAT32_C(  -906.13) },
        SIMDE_FLOAT32_C(  -544.06),
        { SIMDE_FLOAT32_C(   980.77), SIMDE_FLOAT32_C(  -660.40), SIMDE_FLOAT32_C(   985.61), SIMDE_FLOAT32_C(  -544.06) } },
      { { SIMDE_FLOAT32_C(   315.05), SIMDE_FLOAT32_C(   265.41), SIMDE_FLOAT32_C(  -497.60), SIMDE_FLOAT32_C(  -803.01) },
        SIMDE_FLOAT32_C(  -691.60),
        { SIMDE_FLOAT32_C(   315.05), SIMDE_FLOAT32_C(   265.41), SIMDE_FLOAT32_C(  -497.60), SIMDE_FLOAT32_C(  -691.60) } },
      { { SIMDE_FLOAT32_C(  -744.34), SIMDE_FLOAT32_C(   589.30), SIMDE_FLOAT32_C(   980.23), SIMDE_FLOAT32_C(   913.64) },
        SIMDE_FLOAT32_C(   745.54),
        { SIMDE_FLOAT32_C(  -744.34), SIMDE_FLOAT32_C(   589.30), SIMDE_FLOAT32_C(   980.23), SIMDE_FLOAT32_C(   745.54) } },
      { { SIMDE_FLOAT32_C(  -691.93), SIMDE_FLOAT32_C(   755.59), SIMDE_FLOAT32_C(   134.65), SIMDE_FLOAT32_C(  -598.02) },
        SIMDE_FLOAT32_C(   257.09),
        { SIMDE_FLOAT32_C(  -691.93), SIMDE_FLOAT32_C(   755.59), SIMDE_FLOAT32_C(   134.65), SIMDE_FLOAT32_C(   257.09) } },
      { { SIMDE_FLOAT32_C(   376.40), SIMDE_FLOAT32_C(   818.62), SIMDE_FLOAT32_C(  -297.76), SIMDE_FLOAT32_C(  -630.63) },
        SIMDE_FLOAT32_C(   924.94),
        { SIMDE_FLOAT32_C(   376.40), SIMDE_FLOAT32_C(   818.62), SIMDE_FLOAT32_C(  -297.76), SIMDE_FLOAT32_C(   924.94) } },
      { { SIMDE_FLOAT32_C(  -163.27), SIMDE_FLOAT32_C(  -751.26), SIMDE_FLOAT32_C(  -312.45), SIMDE_FLOAT32_C(  -423.38) },
        SIMDE_FLOAT32_C(   107.88),
        { SIMDE_FLOAT32_C(  -163.27), SIMDE_FLOAT32_C(  -751.26), SIMDE_FLOAT32_C(  -312.45), SIMDE_FLOAT32_C(   107.88) } },
      { { SIMDE_FLOAT32_C(  -158.34), SIMDE_FLOAT32_C(  -518.39), SIMDE_FLOAT32_C(  -864.37), SIMDE_FLOAT32_C(   994.23) },
        SIMDE_FLOAT32_C(  -476.48),
        { SIMDE_FLOAT32_C(  -158.34), SIMDE_FLOAT32_C(  -518.39), SIMDE_FLOAT32_C(  -864.37), SIMDE_FLOAT32_C(  -476.48) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t r = simde_wasm_f32x4_replace_lane(a, 3, test_vec[i].value);

      simde_test_wasm_f32x4_assert_equal(r, simde_wasm_v128_load(test_vec[i].r), INT_MAX);
    }
    return 0;
  #else
    fputc('\n', stdout);
    for (int i = 0 ; i < 8 ; i++) {
      simde_v128_t a = simde_test_wasm_f32x4_random(-SIMDE_FLOAT32_C(1000.0), SIMDE_FLOAT32_C(1000.0));
      simde_float32 value = simde_test_codegen_random_f32(-SIMDE_FLOAT32_C(1000.0), SIMDE_FLOAT32_C(1000.0));
      simde_v128_t r = simde_wasm_f32x4_replace_lane(a, 3, value);

      simde_test_wasm_f32x4_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_codegen_write_f32(3, HEDLEY_STATIC_CAST(simde_float32, value), SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_wasm_f32x4_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_f64x2_replace_lane(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      simde_float64 a[sizeof(simde_v128_t) / sizeof(simde_float64)];
      simde_float64 value;
      simde_float64 r[sizeof(simde_v128_t) / sizeof(simde_float64)];
    } test_vec[8] = {
      { { SIMDE_FLOAT64_C(  -709.30), SIMDE_FLOAT64_C(  -978.34) },
        SIMDE_FLOAT64_C(    65.21),
        { SIMDE_FLOAT64_C(    65.21), SIMDE_FLOAT64_C(  -978.34) } },
      { { SIMDE_FLOAT64_C(  -278.16), SIMDE_FLOAT64_C(   314.54) },
        SIMDE_FLOAT64_C(   695.84),
        { SIMDE_FLOAT64_C(   695.84), SIMDE_FLOAT64_C(   314.54) } },
      { { SIMDE_FLOAT64_C(  -901.05), SIMDE_FLOAT64_C(  -421.26) },
        SIMDE_FLOAT64_C(   401.19),
        { SIMDE_FLOAT64_C(   401.19), SIMDE_FLOAT64_C(  -421.26) } },
      { { SIMDE_FLOAT64_C(   327.37), SIMDE_FLOAT64_C(   743.57) },
        SIMDE_FLOAT64_C(  -457.20),
        { SIMDE_FLOAT64_C(  -457.20), SIMDE_FLOAT64_C(   743.57) } },
      { { SIMDE_FLOAT64_C(   423.08), SIMDE_FLOAT64_C(  -308.59) },
        SIMDE_FLOAT64_C(   495.46),
        { SIMDE_FLOAT64_C(   495.46), SIMDE_FLOAT64_C(  -308.59) } },
      { { SIMDE_FLOAT64_C(  -816.94), SIMDE_FLOAT64_C(  -606.96) },
        SIMDE_FLOAT64_C(   117.08),
        { SIMDE_FLOAT64_C(   117.08), SIMDE_FLOAT64_C(  -606.96) } },
      { { SIMDE_FLOAT64_C(   264.46), SIMDE_FLOAT64_C(   986.34) },
        SIMDE_FLOAT64_C(  -961.97),
        { SIMDE_FLOAT64_C(  -961.97), SIMDE_FLOAT64_C(   986.34) } },
      { { SIMDE_FLOAT64_C(  -589.82), SIMDE_FLOAT64_C(  -735.34) },
        SIMDE_FLOAT64_C(   144.71),
        { SIMDE_FLOAT64_C(   144.71), SIMDE_FLOAT64_C(  -735.34) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t r = simde_wasm_f64x2_replace_lane(a, 0, test_vec[i].value);

      simde_test_wasm_f64x2_assert_equal(r, simde_wasm_v128_load(test_vec[i].r), INT_MAX);
    }
    return 0;
  #else
    fputc('\n', stdout);
    for (int i = 0 ; i < 8 ; i++) {
      simde_v128_t a = simde_test_wasm_f64x2_random(-SIMDE_FLOAT64_C(1000.0), SIMDE_FLOAT64_C(1000.0));
      simde_float64 value = simde_test_codegen_random_f64(-SIMDE_FLOAT64_C(1000.0), SIMDE_FLOAT64_C(1000.0));
      simde_v128_t r = simde_wasm_f64x2_replace_lane(a, 0, value);

      simde_test_wasm_f64x2_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_codegen_write_f64(3, HEDLEY_STATIC_CAST(simde_float64, value), SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_wasm_f64x2_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_i8x16_replace_lane)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_i16x8_replace_lane)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_i32x4_replace_lane)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_i64x2_replace_lane)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_f32x4_replace_lane)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_f64x2_replace_lane)
SIMDE_TEST_FUNC_LIST_END

#include "test-simd128-footer.h"
