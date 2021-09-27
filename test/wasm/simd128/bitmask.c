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

#define SIMDE_TEST_WASM_SIMD128_INSN bitmask
#include "../../../simde/wasm/simd128.h"
#include "test-simd128.h"

static int
test_simde_wasm_i8x16_bitmask(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      int8_t a[sizeof(simde_v128_t) / sizeof(int8_t)];
      uint32_t r;
    } test_vec[] = {
      { { -INT8_C( 124), -INT8_C(  41), -INT8_C(  71),  INT8_C(  86),  INT8_C(  79),  INT8_C( 119), -INT8_C(  79), -INT8_C(  44),
           INT8_C(  47),  INT8_C(  41), -INT8_C( 123),  INT8_C(  30), -INT8_C(  16),  INT8_C(   8),  INT8_C( 114),  INT8_C( 113) },
        UINT32_C(        5319) },
      { {  INT8_C(  24), -INT8_C( 126),  INT8_C( 115),  INT8_C(   9), -INT8_C(  90), -INT8_C(  63),  INT8_C(  61),  INT8_C(  17),
          -INT8_C( 114), -INT8_C( 113),  INT8_C(  35),  INT8_C(  47), -INT8_C(  39),      INT8_MIN, -INT8_C( 119),  INT8_C(   7) },
        UINT32_C(       29490) },
      { { -INT8_C(  11),  INT8_C(  87),  INT8_C(  15), -INT8_C(  56),  INT8_C(  57),  INT8_C( 120), -INT8_C( 102),  INT8_C( 118),
          -INT8_C(  29), -INT8_C(  12),  INT8_C( 100),  INT8_C( 104),  INT8_C( 126),  INT8_C(   1),  INT8_C(  98), -INT8_C(  78) },
        UINT32_C(       33609) },
      { {  INT8_C(   0), -INT8_C( 126),  INT8_C(  62),  INT8_C( 122),  INT8_C(  97),  INT8_C(  87), -INT8_C(  22), -INT8_C(  66),
           INT8_C(  89), -INT8_C(  67),  INT8_C(  59),  INT8_C(  80), -INT8_C(  92),  INT8_C(  65), -INT8_C(  23),  INT8_C(   8) },
        UINT32_C(       21186) },
      { {  INT8_C(  62), -INT8_C(  79), -INT8_C(  94), -INT8_C(  14),  INT8_C( 110),  INT8_C(  94),  INT8_C( 126), -INT8_C(  94),
           INT8_C(  25), -INT8_C(  98), -INT8_C(  41), -INT8_C(  62), -INT8_C(  96), -INT8_C(  64),  INT8_C( 106), -INT8_C(  37) },
        UINT32_C(       48782) },
      { {  INT8_C(  16),  INT8_C(  66),  INT8_C(  30), -INT8_C(  33),  INT8_C(  40),  INT8_C( 102), -INT8_C( 119),  INT8_C(  42),
          -INT8_C(  81),  INT8_C(  93),  INT8_C(  25),  INT8_C(  16), -INT8_C(  81), -INT8_C(  29), -INT8_C( 100),  INT8_C(  30) },
        UINT32_C(       29000) },
      { {  INT8_C(  29),  INT8_C( 111), -INT8_C(  49), -INT8_C(  12),  INT8_C( 105), -INT8_C(  99), -INT8_C(  27), -INT8_C(   1),
          -INT8_C(  31),  INT8_C(  69),  INT8_C( 106),  INT8_C(   1),  INT8_C(  43), -INT8_C(  88),  INT8_C( 113), -INT8_C( 112) },
        UINT32_C(       41452) },
      { {  INT8_C( 120), -INT8_C(   7),  INT8_C(  41), -INT8_C(  76),  INT8_C(  70),  INT8_C(  91),  INT8_C(  76),  INT8_C(  91),
           INT8_C( 126), -INT8_C(  27), -INT8_C( 126),  INT8_C(  85),  INT8_C(  17),  INT8_C( 124),  INT8_C(  44), -INT8_C(  61) },
        UINT32_C(       34314) }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      uint32_t r = simde_wasm_i8x16_bitmask(a);
      simde_assert_equal_u32(r, test_vec[i].r);
    }
    return 0;
  #else
    fputc('\n', stdout);
    for (int i = 0 ; i < 8 ; i++) {
      simde_v128_t a = simde_test_wasm_i8x16_random();
      uint32_t r;

      r = simde_wasm_i8x16_bitmask(a);

      simde_test_wasm_i8x16_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_codegen_write_u32(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_i16x8_bitmask(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      int16_t a[sizeof(simde_v128_t) / sizeof(int16_t)];
      uint32_t r;
    } test_vec[] = {
      { { -INT16_C( 17048),  INT16_C(  6858),  INT16_C( 21634), -INT16_C( 23079), -INT16_C(  2752), -INT16_C(  8593), -INT16_C( 27056),  INT16_C( 15193) },
        UINT32_C(         121) },
      { { -INT16_C( 26108),  INT16_C( 25044), -INT16_C(  2186),  INT16_C( 29035), -INT16_C( 19130),  INT16_C( 30111),  INT16_C( 31689), -INT16_C( 14404) },
        UINT32_C(         149) },
      { {  INT16_C(  8049), -INT16_C( 18238),  INT16_C(   233),  INT16_C(  6534),  INT16_C( 14347), -INT16_C( 30259),  INT16_C( 15390),  INT16_C( 26201) },
        UINT32_C(          34) },
      { { -INT16_C( 32142),  INT16_C(  7676),  INT16_C( 23283), -INT16_C( 27801),  INT16_C( 30120),  INT16_C(  9114), -INT16_C( 15653), -INT16_C( 31385) },
        UINT32_C(         201) },
      { {  INT16_C( 17290), -INT16_C(  1746), -INT16_C(  5041),  INT16_C(  5875), -INT16_C( 26201), -INT16_C( 19514),  INT16_C( 31869), -INT16_C(  7133) },
        UINT32_C(         182) },
      { { -INT16_C( 11556), -INT16_C( 24162),  INT16_C( 22433),  INT16_C( 24334),  INT16_C( 30649),  INT16_C( 23350), -INT16_C( 24580), -INT16_C( 15166) },
        UINT32_C(         195) },
      { {  INT16_C( 10887), -INT16_C( 14394),  INT16_C(  4134),  INT16_C( 11270), -INT16_C( 21074), -INT16_C(  8965),  INT16_C( 28805),  INT16_C(  7491) },
        UINT32_C(          50) },
      { { -INT16_C(  8930),  INT16_C( 19871),  INT16_C( 16729), -INT16_C( 30554),  INT16_C(   314), -INT16_C( 20783),  INT16_C( 11495),  INT16_C( 23191) },
        UINT32_C(          41) }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      uint32_t r = simde_wasm_i16x8_bitmask(a);
      simde_assert_equal_u32(r, test_vec[i].r);
    }
    return 0;
  #else
    fputc('\n', stdout);
    for (int i = 0 ; i < 8 ; i++) {
      simde_v128_t a = simde_test_wasm_i16x8_random();
      uint32_t r;

      r = simde_wasm_i16x8_bitmask(a);

      simde_test_wasm_i16x8_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_codegen_write_u32(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_i32x4_bitmask(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      int32_t a[sizeof(simde_v128_t) / sizeof(int32_t)];
      uint32_t r;
    } test_vec[] = {
      { {  INT32_C(  1907870838), -INT32_C(    72888232),  INT32_C(   545751970), -INT32_C(   499536542) },
        UINT32_C(          10) },
      { { -INT32_C(    83220541), -INT32_C(  1545789812), -INT32_C(  1541286671), -INT32_C(   782763309) },
        UINT32_C(          15) },
      { {  INT32_C(  2017837346), -INT32_C(  1314570723),  INT32_C(   266627657),  INT32_C(   326549594) },
        UINT32_C(           2) },
      { { -INT32_C(   321820819),  INT32_C(  1021400590), -INT32_C(  1380816796),  INT32_C(    32393230) },
        UINT32_C(           5) },
      { { -INT32_C(   222453437),  INT32_C(  1141039312),  INT32_C(    40891131), -INT32_C(   798182949) },
        UINT32_C(           9) },
      { {  INT32_C(   540724212),  INT32_C(  1810575977),  INT32_C(  1554896597), -INT32_C(   449841264) },
        UINT32_C(           8) },
      { { -INT32_C(  1748618727), -INT32_C(  1042093629),  INT32_C(  1135868495), -INT32_C(   217540158) },
        UINT32_C(          11) },
      { {  INT32_C(  1199091821),  INT32_C(   469609861),  INT32_C(  1752170971),  INT32_C(  1855873025) },
        UINT32_C(           0) }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      uint32_t r = simde_wasm_i32x4_bitmask(a);
      simde_assert_equal_u32(r, test_vec[i].r);
    }
    return 0;
  #else
    fputc('\n', stdout);
    for (int i = 0 ; i < 8 ; i++) {
      simde_v128_t a = simde_test_wasm_i32x4_random();
      uint32_t r;

      r = simde_wasm_i32x4_bitmask(a);

      simde_test_wasm_i32x4_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_codegen_write_u32(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_i64x2_bitmask(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      int64_t a[sizeof(simde_v128_t) / sizeof(int64_t)];
      uint32_t r;
    } test_vec[] = {
      { {  INT64_C( 8836572669575184210), -INT64_C( 4432738403002501128) },
        UINT32_C(           2) },
      { { -INT64_C(   36495156102163050), -INT64_C( 1918723101027422185) },
        UINT32_C(           3) },
      { { -INT64_C( 1471882778410569247), -INT64_C( 6028346820910141185) },
        UINT32_C(           3) },
      { {  INT64_C( 3583067804223239273),  INT64_C( 8077266208464651812) },
        UINT32_C(           0) },
      { {  INT64_C( 1384571000388200524), -INT64_C( 8563671645520907918) },
        UINT32_C(           2) },
      { {  INT64_C( 5608546015207888687),  INT64_C(  811406555234301713) },
        UINT32_C(           0) },
      { {  INT64_C( 6123680649836499076),  INT64_C( 6597256145916020378) },
        UINT32_C(           0) },
      { {  INT64_C( 1608387220675293715),  INT64_C(  724467462433047628) },
        UINT32_C(           0) }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      uint32_t r = simde_wasm_i64x2_bitmask(a);
      simde_assert_equal_u32(r, test_vec[i].r);
    }
    return 0;
  #else
    fputc('\n', stdout);
    for (int i = 0 ; i < 8 ; i++) {
      simde_v128_t a = simde_test_wasm_i64x2_random();
      uint32_t r;

      r = simde_wasm_i64x2_bitmask(a);

      simde_test_wasm_i64x2_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_codegen_write_u32(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_i8x16_bitmask)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_i16x8_bitmask)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_i32x4_bitmask)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_i64x2_bitmask)
SIMDE_TEST_FUNC_LIST_END

#include "test-simd128-footer.h"
