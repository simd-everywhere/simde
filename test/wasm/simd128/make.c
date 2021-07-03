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

#define SIMDE_TEST_WASM_SIMD128_INSN make
#include "../../../simde/wasm/simd128.h"
#include "test-simd128.h"

static int
test_simde_wasm_i8x16_make(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      int8_t a[sizeof(simde_v128_t) / sizeof(int8_t)];
      int8_t r[sizeof(simde_v128_t) / sizeof(int8_t)];
    } test_vec[8] = {
      { { -INT8_C( 107),  INT8_C( 107), -INT8_C(  58), -INT8_C( 126), -INT8_C(  98), -INT8_C(  65),  INT8_C(  19), -INT8_C(  67),
          -INT8_C(  67), -INT8_C( 114), -INT8_C(  37), -INT8_C( 123), -INT8_C(  98),  INT8_C(  78), -INT8_C(  65), -INT8_C(  80) },
        { -INT8_C( 107),  INT8_C( 107), -INT8_C(  58), -INT8_C( 126), -INT8_C(  98), -INT8_C(  65),  INT8_C(  19), -INT8_C(  67),
          -INT8_C(  67), -INT8_C( 114), -INT8_C(  37), -INT8_C( 123), -INT8_C(  98),  INT8_C(  78), -INT8_C(  65), -INT8_C(  80) } },
      { {  INT8_C(  29),  INT8_C(  90),  INT8_C(  26),  INT8_C(  88), -INT8_C(  38), -INT8_C(  55),  INT8_C(   3), -INT8_C( 126),
           INT8_C( 113), -INT8_C(   3),  INT8_C(  55),  INT8_C(  65), -INT8_C(  12), -INT8_C( 124), -INT8_C(  62), -INT8_C(  82) },
        {  INT8_C(  29),  INT8_C(  90),  INT8_C(  26),  INT8_C(  88), -INT8_C(  38), -INT8_C(  55),  INT8_C(   3), -INT8_C( 126),
           INT8_C( 113), -INT8_C(   3),  INT8_C(  55),  INT8_C(  65), -INT8_C(  12), -INT8_C( 124), -INT8_C(  62), -INT8_C(  82) } },
      { {  INT8_C(  53), -INT8_C(  50), -INT8_C( 115), -INT8_C(  54), -INT8_C( 115), -INT8_C(  33), -INT8_C(   3),  INT8_C(  86),
          -INT8_C(  60),  INT8_C(  84), -INT8_C(  25), -INT8_C(  42), -INT8_C(  35),  INT8_C(  87), -INT8_C(   8),  INT8_C(  46) },
        {  INT8_C(  53), -INT8_C(  50), -INT8_C( 115), -INT8_C(  54), -INT8_C( 115), -INT8_C(  33), -INT8_C(   3),  INT8_C(  86),
          -INT8_C(  60),  INT8_C(  84), -INT8_C(  25), -INT8_C(  42), -INT8_C(  35),  INT8_C(  87), -INT8_C(   8),  INT8_C(  46) } },
      { { -INT8_C(  59),  INT8_C(  20),  INT8_C(  20), -INT8_C( 118),  INT8_C( 122), -INT8_C(  42),  INT8_C(  73),  INT8_C(  18),
          -INT8_C( 117), -INT8_C(   4),  INT8_C(  42), -INT8_C(  90),  INT8_C(  20),  INT8_C( 120),  INT8_C(  89),  INT8_C(  23) },
        { -INT8_C(  59),  INT8_C(  20),  INT8_C(  20), -INT8_C( 118),  INT8_C( 122), -INT8_C(  42),  INT8_C(  73),  INT8_C(  18),
          -INT8_C( 117), -INT8_C(   4),  INT8_C(  42), -INT8_C(  90),  INT8_C(  20),  INT8_C( 120),  INT8_C(  89),  INT8_C(  23) } },
      { {  INT8_C(  82),  INT8_C(  30), -INT8_C( 127), -INT8_C(  30),  INT8_C(  91), -INT8_C(  12),  INT8_C(  33),  INT8_C( 103),
          -INT8_C(  81),  INT8_C(  91),  INT8_C(  21), -INT8_C(  66),  INT8_C( 116), -INT8_C(  76),  INT8_C( 105),  INT8_C( 101) },
        {  INT8_C(  82),  INT8_C(  30), -INT8_C( 127), -INT8_C(  30),  INT8_C(  91), -INT8_C(  12),  INT8_C(  33),  INT8_C( 103),
          -INT8_C(  81),  INT8_C(  91),  INT8_C(  21), -INT8_C(  66),  INT8_C( 116), -INT8_C(  76),  INT8_C( 105),  INT8_C( 101) } },
      { { -INT8_C(  27),  INT8_C( 109),  INT8_C(  27),  INT8_C(  30), -INT8_C(   1),  INT8_C( 122),  INT8_C(  34),  INT8_C(  84),
           INT8_C(  42), -INT8_C(  83),  INT8_C(  44), -INT8_C(  56), -INT8_C(  41),  INT8_C(  94), -INT8_C(  44), -INT8_C( 111) },
        { -INT8_C(  27),  INT8_C( 109),  INT8_C(  27),  INT8_C(  30), -INT8_C(   1),  INT8_C( 122),  INT8_C(  34),  INT8_C(  84),
           INT8_C(  42), -INT8_C(  83),  INT8_C(  44), -INT8_C(  56), -INT8_C(  41),  INT8_C(  94), -INT8_C(  44), -INT8_C( 111) } },
      { {  INT8_C( 104), -INT8_C(  60), -INT8_C(  98), -INT8_C(  15),  INT8_C(  65), -INT8_C(  49),  INT8_C( 124),  INT8_C( 112),
           INT8_C(  39),  INT8_C( 103),  INT8_C(  36), -INT8_C(  79), -INT8_C( 124),  INT8_C(  23), -INT8_C( 106), -INT8_C( 110) },
        {  INT8_C( 104), -INT8_C(  60), -INT8_C(  98), -INT8_C(  15),  INT8_C(  65), -INT8_C(  49),  INT8_C( 124),  INT8_C( 112),
           INT8_C(  39),  INT8_C( 103),  INT8_C(  36), -INT8_C(  79), -INT8_C( 124),  INT8_C(  23), -INT8_C( 106), -INT8_C( 110) } },
      { { -INT8_C(   7),  INT8_C(  16),  INT8_C(  28),  INT8_C(  58),  INT8_C(  81), -INT8_C(  53),  INT8_C( 109),  INT8_C( 119),
          -INT8_C(  32), -INT8_C( 114),  INT8_C(  77),  INT8_C( 123), -INT8_C(  71),  INT8_C( 118),  INT8_C(  42), -INT8_C(  26) },
        { -INT8_C(   7),  INT8_C(  16),  INT8_C(  28),  INT8_C(  58),  INT8_C(  81), -INT8_C(  53),  INT8_C( 109),  INT8_C( 119),
          -INT8_C(  32), -INT8_C( 114),  INT8_C(  77),  INT8_C( 123), -INT8_C(  71),  INT8_C( 118),  INT8_C(  42), -INT8_C(  26) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      const int8_t* a = test_vec[i].a;
      simde_v128_t r =
        simde_wasm_i8x16_make(
            a[0], a[1], a[ 2], a[ 3], a[ 4], a[ 5], a[ 6], a[ 7],
            a[8], a[9], a[10], a[11], a[12], a[13], a[14], a[15]);
      simde_test_wasm_i8x16_assert_equal(r, simde_wasm_v128_load(test_vec[i].r));
    }
    return 0;
  #else
    fputc('\n', stdout);
    for (int i = 0 ; i < 8 ; i++) {
      int8_t a[sizeof(simde_v128_t) / sizeof(int8_t)];
      simde_v128_t r;

      simde_test_codegen_random_memory(sizeof(a), HEDLEY_REINTERPRET_CAST(uint8_t*, a));

      r = simde_wasm_i8x16_make(
          a[0], a[1], a[ 2], a[ 3], a[ 4], a[ 5], a[ 6], a[ 7],
          a[8], a[9], a[10], a[11], a[12], a[13], a[14], a[15]);

      simde_test_codegen_write_vi8(3, sizeof(a) / sizeof(a[0]), a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_i8x16_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_i16x8_make(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      int16_t a[sizeof(simde_v128_t) / sizeof(int16_t)];
      int16_t r[sizeof(simde_v128_t) / sizeof(int16_t)];
    } test_vec[8] = {
      { {  INT16_C( 25276), -INT16_C( 21335),  INT16_C(  9881), -INT16_C( 22928),  INT16_C( 17610),  INT16_C( 25892), -INT16_C( 25524), -INT16_C( 25058) },
        {  INT16_C( 25276), -INT16_C( 21335),  INT16_C(  9881), -INT16_C( 22928),  INT16_C( 17610),  INT16_C( 25892), -INT16_C( 25524), -INT16_C( 25058) } },
      { {  INT16_C( 27009), -INT16_C( 14548),  INT16_C( 26207),  INT16_C( 31892), -INT16_C(  8887),  INT16_C( 25313),  INT16_C( 30268),  INT16_C( 32129) },
        {  INT16_C( 27009), -INT16_C( 14548),  INT16_C( 26207),  INT16_C( 31892), -INT16_C(  8887),  INT16_C( 25313),  INT16_C( 30268),  INT16_C( 32129) } },
      { {  INT16_C( 10968),  INT16_C( 23946),  INT16_C( 31163), -INT16_C( 11458), -INT16_C(  9405), -INT16_C( 11083), -INT16_C(   240), -INT16_C(  3905) },
        {  INT16_C( 10968),  INT16_C( 23946),  INT16_C( 31163), -INT16_C( 11458), -INT16_C(  9405), -INT16_C( 11083), -INT16_C(   240), -INT16_C(  3905) } },
      { {  INT16_C(  8561), -INT16_C( 13615), -INT16_C( 18924), -INT16_C( 30133), -INT16_C( 17435),  INT16_C(   448), -INT16_C( 11652),  INT16_C(  3750) },
        {  INT16_C(  8561), -INT16_C( 13615), -INT16_C( 18924), -INT16_C( 30133), -INT16_C( 17435),  INT16_C(   448), -INT16_C( 11652),  INT16_C(  3750) } },
      { {  INT16_C( 10059), -INT16_C( 19151), -INT16_C( 30928), -INT16_C(   586), -INT16_C(  3987),  INT16_C( 17896),  INT16_C( 30462), -INT16_C( 24335) },
        {  INT16_C( 10059), -INT16_C( 19151), -INT16_C( 30928), -INT16_C(   586), -INT16_C(  3987),  INT16_C( 17896),  INT16_C( 30462), -INT16_C( 24335) } },
      { { -INT16_C(  6214), -INT16_C( 27229), -INT16_C( 24158),  INT16_C( 22638), -INT16_C( 11044), -INT16_C(  6549), -INT16_C( 29906), -INT16_C( 20303) },
        { -INT16_C(  6214), -INT16_C( 27229), -INT16_C( 24158),  INT16_C( 22638), -INT16_C( 11044), -INT16_C(  6549), -INT16_C( 29906), -INT16_C( 20303) } },
      { {  INT16_C( 11305), -INT16_C( 19001), -INT16_C(  4764),  INT16_C( 16052),  INT16_C( 10294),  INT16_C(  9319),  INT16_C( 20218),  INT16_C( 13074) },
        {  INT16_C( 11305), -INT16_C( 19001), -INT16_C(  4764),  INT16_C( 16052),  INT16_C( 10294),  INT16_C(  9319),  INT16_C( 20218),  INT16_C( 13074) } },
      { {  INT16_C( 29737),  INT16_C( 12400), -INT16_C( 24056),  INT16_C( 23962), -INT16_C( 23877),  INT16_C(  1490),  INT16_C(  7748),  INT16_C( 22250) },
        {  INT16_C( 29737),  INT16_C( 12400), -INT16_C( 24056),  INT16_C( 23962), -INT16_C( 23877),  INT16_C(  1490),  INT16_C(  7748),  INT16_C( 22250) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      const int16_t* a = test_vec[i].a;
      simde_v128_t r = simde_wasm_i16x8_make(a[0], a[1], a[ 2], a[ 3], a[ 4], a[ 5], a[ 6], a[ 7]);
      simde_test_wasm_i16x8_assert_equal(r, simde_wasm_v128_load(test_vec[i].r));
    }
    return 0;
  #else
    fputc('\n', stdout);
    for (int i = 0 ; i < 8 ; i++) {
      int16_t a[sizeof(simde_v128_t) / sizeof(int16_t)];
      simde_v128_t r;

      simde_test_codegen_random_memory(sizeof(a), HEDLEY_REINTERPRET_CAST(uint8_t*, a));

      r = simde_wasm_i16x8_make(
          a[0], a[1], a[ 2], a[ 3], a[ 4], a[ 5], a[ 6], a[ 7]);

      simde_test_codegen_write_vi16(3, sizeof(a) / sizeof(a[0]), a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_i16x8_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_i32x4_make(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      int32_t a[sizeof(simde_v128_t) / sizeof(int32_t)];
      int32_t r[sizeof(simde_v128_t) / sizeof(int32_t)];
    } test_vec[8] = {
      { {  INT32_C(   695075960),  INT32_C(  1003529442), -INT32_C(  1443479584), -INT32_C(  1440912186) },
        {  INT32_C(   695075960),  INT32_C(  1003529442), -INT32_C(  1443479584), -INT32_C(  1440912186) } },
      { {  INT32_C(   880505601),  INT32_C(   710643276),  INT32_C(  1076441165),  INT32_C(   843386822) },
        {  INT32_C(   880505601),  INT32_C(   710643276),  INT32_C(  1076441165),  INT32_C(   843386822) } },
      { { -INT32_C(  1059723883), -INT32_C(   586628182), -INT32_C(   963040743), -INT32_C(  1022298580) },
        { -INT32_C(  1059723883), -INT32_C(   586628182), -INT32_C(   963040743), -INT32_C(  1022298580) } },
      { { -INT32_C(   431686935), -INT32_C(  1520335465),  INT32_C(  1050402888), -INT32_C(   751240342) },
        { -INT32_C(   431686935), -INT32_C(  1520335465),  INT32_C(  1050402888), -INT32_C(   751240342) } },
      { { -INT32_C(   303617944),  INT32_C(        3995), -INT32_C(  1098262535),  INT32_C(   640209351) },
        { -INT32_C(   303617944),  INT32_C(        3995), -INT32_C(  1098262535),  INT32_C(   640209351) } },
      { {  INT32_C(  2027168138), -INT32_C(    56054172),  INT32_C(  1621230607),  INT32_C(  1551648147) },
        {  INT32_C(  2027168138), -INT32_C(    56054172),  INT32_C(  1621230607),  INT32_C(  1551648147) } },
      { {  INT32_C(   631271218), -INT32_C(   660470701),  INT32_C(  1855345560), -INT32_C(  1818340747) },
        {  INT32_C(   631271218), -INT32_C(   660470701),  INT32_C(  1855345560), -INT32_C(  1818340747) } },
      { {  INT32_C(   508548470),  INT32_C(  2044910564),  INT32_C(   842708574), -INT32_C(  1898864311) },
        {  INT32_C(   508548470),  INT32_C(  2044910564),  INT32_C(   842708574), -INT32_C(  1898864311) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      const int32_t* a = test_vec[i].a;
      simde_v128_t r = simde_wasm_i32x4_make(a[0], a[1], a[2], a[3]);
      simde_test_wasm_i32x4_assert_equal(r, simde_wasm_v128_load(test_vec[i].r));
    }
    return 0;
  #else
    fputc('\n', stdout);
    for (int i = 0 ; i < 8 ; i++) {
      int32_t a[sizeof(simde_v128_t) / sizeof(int32_t)];
      simde_v128_t r;

      simde_test_codegen_random_memory(sizeof(a), HEDLEY_REINTERPRET_CAST(uint8_t*, a));

      r = simde_wasm_i32x4_make(a[0], a[1], a[2], a[3]);

      simde_test_codegen_write_vi32(3, sizeof(a) / sizeof(a[0]), a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_i32x4_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_i64x2_make(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      int64_t a[sizeof(simde_v128_t) / sizeof(int64_t)];
      int64_t r[sizeof(simde_v128_t) / sizeof(int64_t)];
    } test_vec[8] = {
      { {  INT64_C( 3706780716330511204), -INT64_C( 1056131380118931910) },
        {  INT64_C( 3706780716330511204), -INT64_C( 1056131380118931910) } },
      { {  INT64_C( 5808093934263827513),  INT64_C(  796694773045360021) },
        {  INT64_C( 5808093934263827513),  INT64_C(  796694773045360021) } },
      { { -INT64_C(  620641701573354864), -INT64_C( 6332908652456362593) },
        { -INT64_C(  620641701573354864), -INT64_C( 6332908652456362593) } },
      { { -INT64_C( 2825842138208504311),  INT64_C( 8727546400882524358) },
        { -INT64_C( 2825842138208504311),  INT64_C( 8727546400882524358) } },
      { {  INT64_C( 2466900102307772640), -INT64_C( 8981627329841242156) },
        {  INT64_C( 2466900102307772640), -INT64_C( 8981627329841242156) } },
      { {  INT64_C( 5976583528864353534),  INT64_C( 2340547445206133582) },
        {  INT64_C( 5976583528864353534),  INT64_C( 2340547445206133582) } },
      { {  INT64_C( 5001808799695288836),  INT64_C( 1033089374524368263) },
        {  INT64_C( 5001808799695288836),  INT64_C( 1033089374524368263) } },
      { {  INT64_C( 2505067071927086274),  INT64_C(  660034086012828132) },
        {  INT64_C( 2505067071927086274),  INT64_C(  660034086012828132) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      const int64_t* a = test_vec[i].a;
      simde_v128_t r = simde_wasm_i64x2_make(a[0], a[1]);
      simde_test_wasm_i64x2_assert_equal(r, simde_wasm_v128_load(test_vec[i].r));
    }
    return 0;
  #else
    fputc('\n', stdout);
    for (int i = 0 ; i < 8 ; i++) {
      int64_t a[sizeof(simde_v128_t) / sizeof(int64_t)];
      simde_v128_t r;

      simde_test_codegen_random_memory(sizeof(a), HEDLEY_REINTERPRET_CAST(uint8_t*, a));

      r = simde_wasm_i64x2_make(a[0], a[1]);

      simde_test_codegen_write_vi64(3, sizeof(a) / sizeof(a[0]), a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_i64x2_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_f32x4_make(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      simde_float32 a[sizeof(simde_v128_t) / sizeof(simde_float32)];
      simde_float32 r[sizeof(simde_v128_t) / sizeof(simde_float32)];
    } test_vec[8] = {
      { { SIMDE_FLOAT32_C(  -591.06), SIMDE_FLOAT32_C(  -843.73), SIMDE_FLOAT32_C(   664.08), SIMDE_FLOAT32_C(  -354.19) },
        { SIMDE_FLOAT32_C(  -591.06), SIMDE_FLOAT32_C(  -843.73), SIMDE_FLOAT32_C(   664.08), SIMDE_FLOAT32_C(  -354.19) } },
      { { SIMDE_FLOAT32_C(  -257.96), SIMDE_FLOAT32_C(  -389.78), SIMDE_FLOAT32_C(  -814.91), SIMDE_FLOAT32_C(   348.16) },
        { SIMDE_FLOAT32_C(  -257.96), SIMDE_FLOAT32_C(  -389.78), SIMDE_FLOAT32_C(  -814.91), SIMDE_FLOAT32_C(   348.16) } },
      { { SIMDE_FLOAT32_C(  -599.02), SIMDE_FLOAT32_C(   786.02), SIMDE_FLOAT32_C(  -783.49), SIMDE_FLOAT32_C(  -830.91) },
        { SIMDE_FLOAT32_C(  -599.02), SIMDE_FLOAT32_C(   786.02), SIMDE_FLOAT32_C(  -783.49), SIMDE_FLOAT32_C(  -830.91) } },
      { { SIMDE_FLOAT32_C(  -437.22), SIMDE_FLOAT32_C(  -522.93), SIMDE_FLOAT32_C(   494.10), SIMDE_FLOAT32_C(  -978.90) },
        { SIMDE_FLOAT32_C(  -437.22), SIMDE_FLOAT32_C(  -522.93), SIMDE_FLOAT32_C(   494.10), SIMDE_FLOAT32_C(  -978.90) } },
      { { SIMDE_FLOAT32_C(   161.42), SIMDE_FLOAT32_C(   238.20), SIMDE_FLOAT32_C(   569.29), SIMDE_FLOAT32_C(    42.14) },
        { SIMDE_FLOAT32_C(   161.42), SIMDE_FLOAT32_C(   238.20), SIMDE_FLOAT32_C(   569.29), SIMDE_FLOAT32_C(    42.14) } },
      { { SIMDE_FLOAT32_C(   469.46), SIMDE_FLOAT32_C(   258.39), SIMDE_FLOAT32_C(   977.69), SIMDE_FLOAT32_C(  -720.50) },
        { SIMDE_FLOAT32_C(   469.46), SIMDE_FLOAT32_C(   258.39), SIMDE_FLOAT32_C(   977.69), SIMDE_FLOAT32_C(  -720.50) } },
      { { SIMDE_FLOAT32_C(  -450.95), SIMDE_FLOAT32_C(  -358.31), SIMDE_FLOAT32_C(   417.53), SIMDE_FLOAT32_C(  -526.21) },
        { SIMDE_FLOAT32_C(  -450.95), SIMDE_FLOAT32_C(  -358.31), SIMDE_FLOAT32_C(   417.53), SIMDE_FLOAT32_C(  -526.21) } },
      { { SIMDE_FLOAT32_C(   659.89), SIMDE_FLOAT32_C(  -270.01), SIMDE_FLOAT32_C(   814.76), SIMDE_FLOAT32_C(  -764.06) },
        { SIMDE_FLOAT32_C(   659.89), SIMDE_FLOAT32_C(  -270.01), SIMDE_FLOAT32_C(   814.76), SIMDE_FLOAT32_C(  -764.06) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      const simde_float32* a = test_vec[i].a;
      simde_v128_t r = simde_wasm_f32x4_make(a[0], a[1], a[2], a[3]);
      simde_test_wasm_i32x4_assert_equal(r, simde_wasm_v128_load(test_vec[i].r));
    }
    return 0;
  #else
    fputc('\n', stdout);
    for (int i = 0 ; i < 8 ; i++) {
      simde_float32 a[sizeof(simde_v128_t) / sizeof(simde_float32)];
      simde_v128_t r;

      simde_test_codegen_random_vf32(sizeof(a) / sizeof(a[0]), a, -SIMDE_FLOAT32_C(1000.0), SIMDE_FLOAT32_C(1000.0));

      r = simde_wasm_f32x4_make(a[0], a[1], a[2], a[3]);

      simde_test_codegen_write_vf32(3, sizeof(a) / sizeof(a[0]), a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_f32x4_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_f64x2_make(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      simde_float64 a[sizeof(simde_v128_t) / sizeof(simde_float64)];
      simde_float64 r[sizeof(simde_v128_t) / sizeof(simde_float64)];
    } test_vec[8] = {
      { { SIMDE_FLOAT64_C(   639.11), SIMDE_FLOAT64_C(  -669.03) },
        { SIMDE_FLOAT64_C(   639.11), SIMDE_FLOAT64_C(  -669.03) } },
      { { SIMDE_FLOAT64_C(  -961.87), SIMDE_FLOAT64_C(  -484.03) },
        { SIMDE_FLOAT64_C(  -961.87), SIMDE_FLOAT64_C(  -484.03) } },
      { { SIMDE_FLOAT64_C(  -709.43), SIMDE_FLOAT64_C(  -546.13) },
        { SIMDE_FLOAT64_C(  -709.43), SIMDE_FLOAT64_C(  -546.13) } },
      { { SIMDE_FLOAT64_C(  -223.36), SIMDE_FLOAT64_C(  -698.92) },
        { SIMDE_FLOAT64_C(  -223.36), SIMDE_FLOAT64_C(  -698.92) } },
      { { SIMDE_FLOAT64_C(   616.46), SIMDE_FLOAT64_C(   -91.93) },
        { SIMDE_FLOAT64_C(   616.46), SIMDE_FLOAT64_C(   -91.93) } },
      { { SIMDE_FLOAT64_C(   779.18), SIMDE_FLOAT64_C(   137.61) },
        { SIMDE_FLOAT64_C(   779.18), SIMDE_FLOAT64_C(   137.61) } },
      { { SIMDE_FLOAT64_C(  -932.66), SIMDE_FLOAT64_C(   871.28) },
        { SIMDE_FLOAT64_C(  -932.66), SIMDE_FLOAT64_C(   871.28) } },
      { { SIMDE_FLOAT64_C(   895.78), SIMDE_FLOAT64_C(  -537.98) },
        { SIMDE_FLOAT64_C(   895.78), SIMDE_FLOAT64_C(  -537.98) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      const simde_float64* a = test_vec[i].a;
      simde_v128_t r = simde_wasm_f64x2_make(a[0], a[1]);
      simde_test_wasm_i32x4_assert_equal(r, simde_wasm_v128_load(test_vec[i].r));
    }
    return 0;
  #else
    fputc('\n', stdout);
    for (int i = 0 ; i < 8 ; i++) {
      simde_float64 a[sizeof(simde_v128_t) / sizeof(simde_float64)];
      simde_v128_t r;

      simde_test_codegen_random_vf64(sizeof(a) / sizeof(a[0]), a, -SIMDE_FLOAT64_C(1000.0), SIMDE_FLOAT64_C(1000.0));

      r = simde_wasm_f64x2_make(a[0], a[1]);

      simde_test_codegen_write_vf64(3, sizeof(a) / sizeof(a[0]), a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_f64x2_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_i8x16_make)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_i16x8_make)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_i32x4_make)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_i64x2_make)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_f32x4_make)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_f64x2_make)
SIMDE_TEST_FUNC_LIST_END

#include "test-simd128-footer.h"
