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

#define SIMDE_TEST_WASM_SIMD128_INSN load_lane
#include "../../../simde/wasm/simd128.h"
#include "test-simd128.h"

static int
test_simde_wasm_v128_load8_lane(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      int8_t a;
      int32_t l;
      int8_t v[sizeof(simde_v128_t) / sizeof(int8_t)];
      int8_t r[sizeof(simde_v128_t) / sizeof(int8_t)];
    } test_vec[] = {
      { -INT8_C( 117),
         INT32_C(           2),
        { -INT8_C( 101), -INT8_C(  31), -INT8_C( 110), -INT8_C(  59), -INT8_C(  19),  INT8_C(  78), -INT8_C(  13),  INT8_C(  99),
          -INT8_C(  84),  INT8_C( 102), -INT8_C(  70), -INT8_C( 102), -INT8_C(  78), -INT8_C(   4),  INT8_C(  52), -INT8_C( 102) },
        { -INT8_C( 101), -INT8_C(  31), -INT8_C( 117), -INT8_C(  59), -INT8_C(  19),  INT8_C(  78), -INT8_C(  13),  INT8_C(  99),
          -INT8_C(  84),  INT8_C( 102), -INT8_C(  70), -INT8_C( 102), -INT8_C(  78), -INT8_C(   4),  INT8_C(  52), -INT8_C( 102) } },
      {  INT8_C(  83),
         INT32_C(           1),
        { -INT8_C(  37), -INT8_C(  75), -INT8_C(  85),  INT8_C(   8),  INT8_C( 110), -INT8_C(  27),  INT8_C( 100),  INT8_C( 109),
          -INT8_C( 123), -INT8_C(  20), -INT8_C(  90),  INT8_C(   0),  INT8_C(  33),      INT8_MIN,  INT8_C(  42), -INT8_C(   7) },
        { -INT8_C(  37),  INT8_C(  83), -INT8_C(  85),  INT8_C(   8),  INT8_C( 110), -INT8_C(  27),  INT8_C( 100),  INT8_C( 109),
          -INT8_C( 123), -INT8_C(  20), -INT8_C(  90),  INT8_C(   0),  INT8_C(  33),      INT8_MIN,  INT8_C(  42), -INT8_C(   7) } },
      {  INT8_C(  71),
         INT32_C(           3),
        {  INT8_C(  86),  INT8_C(  93),  INT8_C( 109),  INT8_C(  68), -INT8_C(   7),  INT8_C(  73),  INT8_C( 111), -INT8_C(  47),
           INT8_C(  79), -INT8_C(  62),  INT8_C( 102), -INT8_C(  95), -INT8_C( 101),  INT8_C(  56), -INT8_C( 110),  INT8_C(  33) },
        {  INT8_C(  86),  INT8_C(  93),  INT8_C( 109),  INT8_C(  71), -INT8_C(   7),  INT8_C(  73),  INT8_C( 111), -INT8_C(  47),
           INT8_C(  79), -INT8_C(  62),  INT8_C( 102), -INT8_C(  95), -INT8_C( 101),  INT8_C(  56), -INT8_C( 110),  INT8_C(  33) } },
      {  INT8_C(  82),
         INT32_C(          13),
        { -INT8_C(  79), -INT8_C( 106),  INT8_C(   4), -INT8_C(  53),  INT8_C(  52), -INT8_C(   4), -INT8_C(  24), -INT8_C(  51),
           INT8_C(   2),  INT8_C( 104),  INT8_C(  20), -INT8_C(  33),  INT8_C(  97),  INT8_C(  92), -INT8_C(  29), -INT8_C( 120) },
        { -INT8_C(  79), -INT8_C( 106),  INT8_C(   4), -INT8_C(  53),  INT8_C(  52), -INT8_C(   4), -INT8_C(  24), -INT8_C(  51),
           INT8_C(   2),  INT8_C( 104),  INT8_C(  20), -INT8_C(  33),  INT8_C(  97),  INT8_C(  82), -INT8_C(  29), -INT8_C( 120) } },
      {  INT8_C(  95),
         INT32_C(          15),
        { -INT8_C( 115), -INT8_C( 124),  INT8_C(  74),  INT8_C(  55), -INT8_C( 118), -INT8_C(  34), -INT8_C( 112), -INT8_C(  20),
          -INT8_C(  34), -INT8_C( 120),  INT8_C( 120), -INT8_C(  99), -INT8_C(  72),  INT8_C(  97),  INT8_C(  90),  INT8_C(   1) },
        { -INT8_C( 115), -INT8_C( 124),  INT8_C(  74),  INT8_C(  55), -INT8_C( 118), -INT8_C(  34), -INT8_C( 112), -INT8_C(  20),
          -INT8_C(  34), -INT8_C( 120),  INT8_C( 120), -INT8_C(  99), -INT8_C(  72),  INT8_C(  97),  INT8_C(  90),  INT8_C(  95) } },
      { -INT8_C( 115),
         INT32_C(           5),
        {  INT8_C( 111), -INT8_C(  93), -INT8_C( 122), -INT8_C( 123), -INT8_C(  89), -INT8_C( 125), -INT8_C(  87), -INT8_C(  32),
           INT8_C(   4), -INT8_C(  59),  INT8_C( 121),  INT8_C(   8),  INT8_C(  10),  INT8_C( 123), -INT8_C(  33),  INT8_C(  77) },
        {  INT8_C( 111), -INT8_C(  93), -INT8_C( 122), -INT8_C( 123), -INT8_C(  89), -INT8_C( 115), -INT8_C(  87), -INT8_C(  32),
           INT8_C(   4), -INT8_C(  59),  INT8_C( 121),  INT8_C(   8),  INT8_C(  10),  INT8_C( 123), -INT8_C(  33),  INT8_C(  77) } },
      {  INT8_C(  17),
         INT32_C(          15),
        { -INT8_C( 114), -INT8_C(  94),  INT8_C( 110), -INT8_C(  49),  INT8_C(  60),  INT8_C( 123),  INT8_C( 125), -INT8_C(  29),
          -INT8_C(  27), -INT8_C(  21),  INT8_C(  38), -INT8_C(  91),  INT8_C(  20),  INT8_C(   6),  INT8_C(   9),  INT8_C( 114) },
        { -INT8_C( 114), -INT8_C(  94),  INT8_C( 110), -INT8_C(  49),  INT8_C(  60),  INT8_C( 123),  INT8_C( 125), -INT8_C(  29),
          -INT8_C(  27), -INT8_C(  21),  INT8_C(  38), -INT8_C(  91),  INT8_C(  20),  INT8_C(   6),  INT8_C(   9),  INT8_C(  17) } },
      {  INT8_C(  28),
         INT32_C(           0),
        { -INT8_C(  15), -INT8_C(  57), -INT8_C(  53), -INT8_C(  46), -INT8_C( 101), -INT8_C( 115), -INT8_C(  26),  INT8_C( 123),
          -INT8_C(  25), -INT8_C(  67), -INT8_C(  80),  INT8_C(  42),  INT8_C(  45), -INT8_C( 126), -INT8_C(  95), -INT8_C( 118) },
        {  INT8_C(  28), -INT8_C(  57), -INT8_C(  53), -INT8_C(  46), -INT8_C( 101), -INT8_C( 115), -INT8_C(  26),  INT8_C( 123),
          -INT8_C(  25), -INT8_C(  67), -INT8_C(  80),  INT8_C(  42),  INT8_C(  45), -INT8_C( 126), -INT8_C(  95), -INT8_C( 118) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t
        v = simde_wasm_v128_load(test_vec[i].v),
        r;
      SIMDE_CONSTIFY_16_(simde_wasm_v128_load8_lane, r, (HEDLEY_UNREACHABLE(), v), test_vec[i].l, &(test_vec[i].a), v);
      simde_test_wasm_i32x4_assert_equal(r, simde_wasm_v128_load(test_vec[i].r));
    }
    return 0;
  #else
    fputc('\n', stdout);
    for (int i = 0 ; i < 8 ; i++) {
      int8_t a = simde_test_codegen_random_i8();
      int32_t l = simde_test_codegen_random_i8() & 15;
      simde_v128_t
        v = simde_test_wasm_i8x16_random(),
        r;

      SIMDE_CONSTIFY_16_(simde_wasm_v128_load8_lane, r, (HEDLEY_UNREACHABLE(), v), l, &a, v);

      simde_test_codegen_write_i8(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_codegen_write_i32(3, l, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_wasm_i8x16_write(3, v, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_wasm_i8x16_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_v128_load16_lane(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      int16_t a;
      int32_t l;
      int16_t v[sizeof(simde_v128_t) / sizeof(int16_t)];
      int16_t r[sizeof(simde_v128_t) / sizeof(int16_t)];
    } test_vec[] = {
      { -INT16_C( 21111),
         INT32_C(           4),
        {  INT16_C( 31202), -INT16_C( 17343),  INT16_C( 13054), -INT16_C( 10223),  INT16_C( 28144), -INT16_C( 10432), -INT16_C( 32657),  INT16_C( 17137) },
        {  INT16_C( 31202), -INT16_C( 17343),  INT16_C( 13054), -INT16_C( 10223), -INT16_C( 21111), -INT16_C( 10432), -INT16_C( 32657),  INT16_C( 17137) } },
      {  INT16_C(  3307),
         INT32_C(           6),
        {  INT16_C( 11227), -INT16_C( 27281),  INT16_C(  3976),  INT16_C(  1649), -INT16_C( 16625), -INT16_C( 20484), -INT16_C( 16676), -INT16_C( 29001) },
        {  INT16_C( 11227), -INT16_C( 27281),  INT16_C(  3976),  INT16_C(  1649), -INT16_C( 16625), -INT16_C( 20484),  INT16_C(  3307), -INT16_C( 29001) } },
      { -INT16_C( 28505),
         INT32_C(           0),
        {  INT16_C(   134),  INT16_C( 16895), -INT16_C(  6035), -INT16_C(  6380), -INT16_C( 21876),  INT16_C(  8821),  INT16_C( 27938),  INT16_C( 12441) },
        { -INT16_C( 28505),  INT16_C( 16895), -INT16_C(  6035), -INT16_C(  6380), -INT16_C( 21876),  INT16_C(  8821),  INT16_C( 27938),  INT16_C( 12441) } },
      { -INT16_C( 22920),
         INT32_C(           7),
        {  INT16_C(  2015), -INT16_C( 28433), -INT16_C( 15824),  INT16_C( 16577), -INT16_C( 13110),  INT16_C(  2468), -INT16_C( 27428),  INT16_C( 10027) },
        {  INT16_C(  2015), -INT16_C( 28433), -INT16_C( 15824),  INT16_C( 16577), -INT16_C( 13110),  INT16_C(  2468), -INT16_C( 27428), -INT16_C( 22920) } },
      {  INT16_C(  2318),
         INT32_C(           7),
        {  INT16_C(   541),  INT16_C(  3960), -INT16_C( 23908),  INT16_C(  3349), -INT16_C( 31594), -INT16_C( 13647), -INT16_C( 23978), -INT16_C( 16232) },
        {  INT16_C(   541),  INT16_C(  3960), -INT16_C( 23908),  INT16_C(  3349), -INT16_C( 31594), -INT16_C( 13647), -INT16_C( 23978),  INT16_C(  2318) } },
      { -INT16_C( 28460),
         INT32_C(           3),
        {  INT16_C(   247),  INT16_C(  5288), -INT16_C(  3486),  INT16_C( 20360),  INT16_C( 10249),  INT16_C( 22703),  INT16_C( 15550),  INT16_C(  1394) },
        {  INT16_C(   247),  INT16_C(  5288), -INT16_C(  3486), -INT16_C( 28460),  INT16_C( 10249),  INT16_C( 22703),  INT16_C( 15550),  INT16_C(  1394) } },
      {  INT16_C(  2581),
         INT32_C(           3),
        { -INT16_C(  6965), -INT16_C( 19210),  INT16_C(  1542), -INT16_C(   657), -INT16_C(  5838), -INT16_C( 13470),  INT16_C( 14510), -INT16_C(  3741) },
        { -INT16_C(  6965), -INT16_C( 19210),  INT16_C(  1542),  INT16_C(  2581), -INT16_C(  5838), -INT16_C( 13470),  INT16_C( 14510), -INT16_C(  3741) } },
      {  INT16_C( 22804),
         INT32_C(           2),
        {  INT16_C( 11322), -INT16_C( 32671),  INT16_C( 23600),  INT16_C( 13573),  INT16_C( 22317), -INT16_C( 13787), -INT16_C( 11604),  INT16_C( 27348) },
        {  INT16_C( 11322), -INT16_C( 32671),  INT16_C( 22804),  INT16_C( 13573),  INT16_C( 22317), -INT16_C( 13787), -INT16_C( 11604),  INT16_C( 27348) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t
        v = simde_wasm_v128_load(test_vec[i].v),
        r;
      SIMDE_CONSTIFY_8_(simde_wasm_v128_load16_lane, r, (HEDLEY_UNREACHABLE(), v), test_vec[i].l, &(test_vec[i].a), v);
      simde_test_wasm_i32x4_assert_equal(r, simde_wasm_v128_load(test_vec[i].r));
    }
    return 0;
  #else
    fputc('\n', stdout);
    for (int i = 0 ; i < 8 ; i++) {
      int16_t a = simde_test_codegen_random_i16();
      int32_t l = simde_test_codegen_random_i16() & 7;
      simde_v128_t
        v = simde_test_wasm_i16x8_random(),
        r;

      SIMDE_CONSTIFY_8_(simde_wasm_v128_load16_lane, r, (HEDLEY_UNREACHABLE(), v), l, &a, v);

      simde_test_codegen_write_i16(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_codegen_write_i32(3, l, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_wasm_i16x8_write(3, v, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_wasm_i16x8_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_v128_load32_lane(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      int32_t a;
      int32_t l;
      int32_t v[sizeof(simde_v128_t) / sizeof(int32_t)];
      int32_t r[sizeof(simde_v128_t) / sizeof(int32_t)];
    } test_vec[] = {
      { -INT32_C(  1349844360),
         INT32_C(           0),
        {  INT32_C(  1446171402),  INT32_C(  1741001107),  INT32_C(  1913283885),  INT32_C(   733653194) },
        { -INT32_C(  1349844360),  INT32_C(  1741001107),  INT32_C(  1913283885),  INT32_C(   733653194) } },
      { -INT32_C(  1370568255),
         INT32_C(           3),
        { -INT32_C(   683986823),  INT32_C(   279267282), -INT32_C(   270705947),  INT32_C(  1465546171) },
        { -INT32_C(   683986823),  INT32_C(   279267282), -INT32_C(   270705947), -INT32_C(  1370568255) } },
      { -INT32_C(  1813005022),
         INT32_C(           2),
        { -INT32_C(  2081437486),  INT32_C(  1757796757), -INT32_C(  2077296160),  INT32_C(  1439553689) },
        { -INT32_C(  2081437486),  INT32_C(  1757796757), -INT32_C(  1813005022),  INT32_C(  1439553689) } },
      {  INT32_C(   782162814),
         INT32_C(           3),
        { -INT32_C(  1693681771),  INT32_C(   831670277),  INT32_C(  1144062696),  INT32_C(  1513340961) },
        { -INT32_C(  1693681771),  INT32_C(   831670277),  INT32_C(  1144062696),  INT32_C(   782162814) } },
      { -INT32_C(   972551214),
         INT32_C(           1),
        { -INT32_C(  1633957982),  INT32_C(  1451277738),  INT32_C(  1299737671), -INT32_C(  1684780814) },
        { -INT32_C(  1633957982), -INT32_C(   972551214),  INT32_C(  1299737671), -INT32_C(  1684780814) } },
      { -INT32_C(  1061617410),
         INT32_C(           0),
        {  INT32_C(   579426186),  INT32_C(    50311201), -INT32_C(  1209513132),  INT32_C(    67440290) },
        { -INT32_C(  1061617410),  INT32_C(    50311201), -INT32_C(  1209513132),  INT32_C(    67440290) } },
      { -INT32_C(  1404845375),
         INT32_C(           1),
        {  INT32_C(   761678312),  INT32_C(  2088588879), -INT32_C(  2094561117), -INT32_C(   845690644) },
        {  INT32_C(   761678312), -INT32_C(  1404845375), -INT32_C(  2094561117), -INT32_C(   845690644) } },
      {  INT32_C(   839068144),
         INT32_C(           1),
        { -INT32_C(  1462556321),  INT32_C(  1195658889),  INT32_C(   983036983), -INT32_C(  1317395945) },
        { -INT32_C(  1462556321),  INT32_C(   839068144),  INT32_C(   983036983), -INT32_C(  1317395945) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t
        v = simde_wasm_v128_load(test_vec[i].v),
        r;
      SIMDE_CONSTIFY_4_(simde_wasm_v128_load32_lane, r, (HEDLEY_UNREACHABLE(), v), test_vec[i].l, &(test_vec[i].a), v);
      simde_test_wasm_i32x4_assert_equal(r, simde_wasm_v128_load(test_vec[i].r));
    }
    return 0;
  #else
    fputc('\n', stdout);
    for (int i = 0 ; i < 8 ; i++) {
      int32_t a = simde_test_codegen_random_i32();
      int32_t l = simde_test_codegen_random_i32() & 3;
      simde_v128_t
        v = simde_test_wasm_i32x4_random(),
        r;

      SIMDE_CONSTIFY_4_(simde_wasm_v128_load32_lane, r, (HEDLEY_UNREACHABLE(), v), l, &a, v);

      simde_test_codegen_write_i32(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_codegen_write_i32(3, l, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_wasm_i32x4_write(3, v, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_wasm_i32x4_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_v128_load64_lane(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      int64_t a;
      int32_t l;
      int64_t v[sizeof(simde_v128_t) / sizeof(int64_t)];
      int64_t r[sizeof(simde_v128_t) / sizeof(int64_t)];
    } test_vec[] = {
      {  INT64_C( 3917445613527106523),
         INT32_C(           0),
        { -INT64_C(  823198238226736939),  INT64_C( 7133494661903141794) },
        {  INT64_C( 3917445613527106523),  INT64_C( 7133494661903141794) } },
      { -INT64_C(   42368343995556515),
         INT32_C(           1),
        { -INT64_C( 6700691502126103499),  INT64_C( 5005708019981672944) },
        { -INT64_C( 6700691502126103499), -INT64_C(   42368343995556515) } },
      { -INT64_C(  695047883615938171),
         INT32_C(           1),
        { -INT64_C( 6597311283403580296),  INT64_C( 4263488688638964055) },
        { -INT64_C( 6597311283403580296), -INT64_C(  695047883615938171) } },
      {  INT64_C( 2370092441912435755),
         INT32_C(           1),
        { -INT64_C( 7318552376233359227), -INT64_C( 8254558467209252244) },
        { -INT64_C( 7318552376233359227),  INT64_C( 2370092441912435755) } },
      {  INT64_C( 6405463856056208742),
         INT32_C(           1),
        { -INT64_C( 2303519759852954186), -INT64_C( 5665503591607731067) },
        { -INT64_C( 2303519759852954186),  INT64_C( 6405463856056208742) } },
      {  INT64_C( 8496487078814089685),
         INT32_C(           1),
        {  INT64_C( 8004418922505543905), -INT64_C( 8072937146156229984) },
        {  INT64_C( 8004418922505543905),  INT64_C( 8496487078814089685) } },
      { -INT64_C( 1636948523542509466),
         INT32_C(           0),
        {  INT64_C( 4469787296310655710),  INT64_C( 4743407747226430157) },
        { -INT64_C( 1636948523542509466),  INT64_C( 4743407747226430157) } },
      { -INT64_C( 1754302406060966499),
         INT32_C(           0),
        {  INT64_C( 2683858454614898575),  INT64_C( 6510441786941060624) },
        { -INT64_C( 1754302406060966499),  INT64_C( 6510441786941060624) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t
        v = simde_wasm_v128_load(test_vec[i].v),
        r;
      SIMDE_CONSTIFY_2_(simde_wasm_v128_load64_lane, r, (HEDLEY_UNREACHABLE(), v), test_vec[i].l, &(test_vec[i].a), v);
      simde_test_wasm_i32x4_assert_equal(r, simde_wasm_v128_load(test_vec[i].r));
    }
    return 0;
  #else
    fputc('\n', stdout);
    for (int i = 0 ; i < 8 ; i++) {
      int64_t a = simde_test_codegen_random_i64();
      int32_t l = simde_test_codegen_random_i64() & 1;
      simde_v128_t
        v = simde_test_wasm_i64x2_random(),
        r;

      SIMDE_CONSTIFY_2_(simde_wasm_v128_load64_lane, r, (HEDLEY_UNREACHABLE(), v), l, &a, v);

      simde_test_codegen_write_i64(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_codegen_write_i32(3, l, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_wasm_i64x2_write(3, v, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_wasm_i64x2_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_v128_load8_lane)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_v128_load16_lane)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_v128_load32_lane)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_v128_load64_lane)
SIMDE_TEST_FUNC_LIST_END

#include "test-simd128-footer.h"
