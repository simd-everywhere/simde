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

#define SIMDE_TEST_WASM_SIMD128_INSN shl
#include "../../../simde/wasm/simd128.h"
#include "test-simd128.h"

static int
test_simde_wasm_i8x16_shl(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      int8_t a[sizeof(simde_v128_t) / sizeof(int8_t)];
      uint32_t count;
      int8_t r[sizeof(simde_v128_t) / sizeof(int8_t)];
    } test_vec[] = {
      { { -INT8_C(  59),  INT8_C(  50),  INT8_C(   5), -INT8_C( 114),  INT8_C(  72), -INT8_C(  61),  INT8_C( 116), -INT8_C(  72),
           INT8_C( 119),  INT8_C(  75), -INT8_C( 109), -INT8_C(  50),  INT8_C(  34),  INT8_C(   9), -INT8_C(  17),  INT8_C(  18) },
        UINT32_C(           5),
        { -INT8_C(  96),  INT8_C(  64), -INT8_C(  96), -INT8_C(  64),  INT8_C(   0),  INT8_C(  96),      INT8_MIN,  INT8_C(   0),
          -INT8_C(  32),  INT8_C(  96),  INT8_C(  96), -INT8_C(  64),  INT8_C(  64),  INT8_C(  32), -INT8_C(  32),  INT8_C(  64) } },
      { {  INT8_C( 122), -INT8_C( 119),  INT8_C(  76),  INT8_C(  86), -INT8_C( 122), -INT8_C(  92),  INT8_C(  57),  INT8_C(  87),
           INT8_C(  37), -INT8_C(  33),  INT8_C(  98), -INT8_C(  39), -INT8_C(  24),  INT8_C(  59), -INT8_C(  35), -INT8_C( 119) },
        UINT32_C(           4),
        { -INT8_C(  96), -INT8_C( 112), -INT8_C(  64),  INT8_C(  96),  INT8_C(  96),  INT8_C(  64), -INT8_C( 112),  INT8_C( 112),
           INT8_C(  80), -INT8_C(  16),  INT8_C(  32), -INT8_C( 112),      INT8_MIN, -INT8_C(  80), -INT8_C(  48), -INT8_C( 112) } },
      { {  INT8_C(  10),  INT8_C(  61),  INT8_C(  71),  INT8_C(  41),  INT8_C( 125),  INT8_C( 122),  INT8_C(   9),  INT8_C(  51),
           INT8_C(  85),  INT8_C(  37), -INT8_C( 119),  INT8_C(  90), -INT8_C(   7),  INT8_C(  23), -INT8_C( 113),  INT8_C(  68) },
        UINT32_C(           3),
        {  INT8_C(  80), -INT8_C(  24),  INT8_C(  56),  INT8_C(  72), -INT8_C(  24), -INT8_C(  48),  INT8_C(  72), -INT8_C( 104),
          -INT8_C(  88),  INT8_C(  40),  INT8_C(  72), -INT8_C(  48), -INT8_C(  56), -INT8_C(  72),  INT8_C( 120),  INT8_C(  32) } },
      { {  INT8_C(  83), -INT8_C(  44),  INT8_C(  38), -INT8_C(  15), -INT8_C(  75),  INT8_C( 121),  INT8_C(  55), -INT8_C( 123),
           INT8_C( 115), -INT8_C(  25), -INT8_C(  44),  INT8_C(  61),  INT8_C(  71),  INT8_C(  72), -INT8_C( 116),  INT8_C(  37) },
        UINT32_C(           0),
        {  INT8_C(  83), -INT8_C(  44),  INT8_C(  38), -INT8_C(  15), -INT8_C(  75),  INT8_C( 121),  INT8_C(  55), -INT8_C( 123),
           INT8_C( 115), -INT8_C(  25), -INT8_C(  44),  INT8_C(  61),  INT8_C(  71),  INT8_C(  72), -INT8_C( 116),  INT8_C(  37) } },
      { {  INT8_C( 101),  INT8_C(  28),  INT8_C(  49),  INT8_C(  78),  INT8_C( 125),  INT8_C(   0),  INT8_C(  61),  INT8_C(  72),
           INT8_C( 110),  INT8_C(   0),  INT8_C(  97),  INT8_C(  93),  INT8_C(  68), -INT8_C(  24), -INT8_C( 110),  INT8_C( 104) },
        UINT32_C(           5),
        { -INT8_C(  96),      INT8_MIN,  INT8_C(  32), -INT8_C(  64), -INT8_C(  96),  INT8_C(   0), -INT8_C(  96),  INT8_C(   0),
          -INT8_C(  64),  INT8_C(   0),  INT8_C(  32), -INT8_C(  96),      INT8_MIN,  INT8_C(   0),  INT8_C(  64),  INT8_C(   0) } },
      { { -INT8_C(   6),  INT8_C(   4),  INT8_C(  12),  INT8_C(  40),  INT8_C(  37), -INT8_C(  69),  INT8_C(  35),  INT8_C(  34),
          -INT8_C(  57), -INT8_C(  81),  INT8_C(  30), -INT8_C(  59),  INT8_C( 123), -INT8_C(  77),  INT8_C(  24), -INT8_C(  46) },
        UINT32_C(           3),
        { -INT8_C(  48),  INT8_C(  32),  INT8_C(  96),  INT8_C(  64),  INT8_C(  40), -INT8_C(  40),  INT8_C(  24),  INT8_C(  16),
           INT8_C(  56),  INT8_C( 120), -INT8_C(  16),  INT8_C(  40), -INT8_C(  40), -INT8_C( 104), -INT8_C(  64), -INT8_C( 112) } },
      { { -INT8_C(  67),  INT8_C(  27), -INT8_C(  27),  INT8_C(   1),  INT8_C(  80), -INT8_C(  36),  INT8_C( 124),  INT8_C( 126),
           INT8_C(  15),  INT8_C(  58),  INT8_C( 126), -INT8_C(  61), -INT8_C(  50),  INT8_C( 117),  INT8_C(   8),  INT8_C(  51) },
        UINT32_C(           2),
        { -INT8_C(  12),  INT8_C( 108), -INT8_C( 108),  INT8_C(   4),  INT8_C(  64),  INT8_C( 112), -INT8_C(  16), -INT8_C(   8),
           INT8_C(  60), -INT8_C(  24), -INT8_C(   8),  INT8_C(  12),  INT8_C(  56), -INT8_C(  44),  INT8_C(  32), -INT8_C(  52) } },
      { {  INT8_C(  78),  INT8_C(  32),  INT8_C(  89),  INT8_C( 118),  INT8_C(  58),  INT8_C(   7), -INT8_C(  51),  INT8_C( 101),
           INT8_C(  72), -INT8_C(  69),  INT8_C(  68),  INT8_C(  10), -INT8_C(  30), -INT8_C(   6),  INT8_C(  37), -INT8_C( 119) },
        UINT32_C(           6),
        {      INT8_MIN,  INT8_C(   0),  INT8_C(  64),      INT8_MIN,      INT8_MIN, -INT8_C(  64),  INT8_C(  64),  INT8_C(  64),
           INT8_C(   0), -INT8_C(  64),  INT8_C(   0),      INT8_MIN,      INT8_MIN,      INT8_MIN,  INT8_C(  64),  INT8_C(  64) } },
      { { -INT8_C(  59),  INT8_C(  50),  INT8_C(   5), -INT8_C( 114),  INT8_C(  72), -INT8_C(  61),  INT8_C( 116), -INT8_C(  72),
           INT8_C( 119),  INT8_C(  75), -INT8_C( 109), -INT8_C(  50),  INT8_C(  34),  INT8_C(   9), -INT8_C(  17),  INT8_C(  18) },
        UINT32_C(           8),
        { -INT8_C(  59),  INT8_C(  50),  INT8_C(   5), -INT8_C( 114),  INT8_C(  72), -INT8_C(  61),  INT8_C( 116), -INT8_C(  72),
           INT8_C( 119),  INT8_C(  75), -INT8_C( 109), -INT8_C(  50),  INT8_C(  34),  INT8_C(   9), -INT8_C(  17),  INT8_C(  18) }, },
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t r = simde_wasm_i8x16_shl(a, test_vec[i].count);
      simde_test_wasm_i8x16_assert_equal(r, simde_wasm_v128_load(test_vec[i].r));
    }
    return 0;
  #else
    fputc('\n', stdout);
    for (int i = 0 ; i < 8 ; i++) {
      simde_v128_t a = simde_test_wasm_i8x16_random();
      uint32_t count = simde_test_codegen_random_u32() & 7;
      simde_v128_t r;

      r = simde_wasm_i8x16_shl(a, count);

      simde_test_wasm_i8x16_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_codegen_write_u32(3, count, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_wasm_i8x16_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_i16x8_shl(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      int16_t a[sizeof(simde_v128_t) / sizeof(int16_t)];
      uint32_t count;
      int16_t r[sizeof(simde_v128_t) / sizeof(int16_t)];
    } test_vec[] = {
      { {  INT16_C( 12935), -INT16_C( 20932), -INT16_C( 25536),  INT16_C( 11174),  INT16_C( 17985), -INT16_C(   571),  INT16_C( 11647), -INT16_C( 22878) },
        UINT32_C(           5),
        {  INT16_C( 20704), -INT16_C( 14464), -INT16_C( 30720),  INT16_C( 29888), -INT16_C( 14304), -INT16_C( 18272), -INT16_C( 20512), -INT16_C( 11200) } },
      { {  INT16_C( 20304), -INT16_C( 15899), -INT16_C(  4225),  INT16_C(  4722),  INT16_C( 32679), -INT16_C( 23613), -INT16_C(  1627),  INT16_C( 20154) },
        UINT32_C(           7),
        { -INT16_C( 22528), -INT16_C(  3456), -INT16_C( 16512),  INT16_C( 14592), -INT16_C( 11392), -INT16_C(  7808), -INT16_C( 11648),  INT16_C( 23808) } },
      { { -INT16_C( 30429), -INT16_C(  9573),  INT16_C( 12738), -INT16_C( 22550),  INT16_C(  6338), -INT16_C( 21031), -INT16_C( 12055),  INT16_C( 15090) },
        UINT32_C(          12),
        {  INT16_C( 12288), -INT16_C( 20480),  INT16_C(  8192), -INT16_C( 24576),  INT16_C(  8192), -INT16_C( 28672), -INT16_C( 28672),  INT16_C(  8192) } },
      { { -INT16_C( 17384),  INT16_C( 18565), -INT16_C( 11232), -INT16_C( 18208),  INT16_C( 20247), -INT16_C(  2561), -INT16_C(    47), -INT16_C( 10070) },
        UINT32_C(           4),
        { -INT16_C( 16000), -INT16_C( 30640),  INT16_C( 16896), -INT16_C( 29184), -INT16_C(  3728),  INT16_C( 24560), -INT16_C(   752), -INT16_C( 30048) } },
      { {  INT16_C( 17678),  INT16_C( 26533),  INT16_C( 13003), -INT16_C(  2104), -INT16_C( 24425),  INT16_C(  7170), -INT16_C( 15432),  INT16_C( 14531) },
        UINT32_C(           0),
        {  INT16_C( 17678),  INT16_C( 26533),  INT16_C( 13003), -INT16_C(  2104), -INT16_C( 24425),  INT16_C(  7170), -INT16_C( 15432),  INT16_C( 14531) } },
      { {  INT16_C( 30845),  INT16_C( 20978), -INT16_C( 12630), -INT16_C(  4864), -INT16_C( 27602),  INT16_C( 18652),  INT16_C( 16558),  INT16_C(  5444) },
        UINT32_C(          11),
        { -INT16_C(  6144), -INT16_C( 28672),  INT16_C( 20480),  INT16_C(     0),  INT16_C( 28672), -INT16_C(  8192),  INT16_C( 28672),  INT16_C(  8192) } },
      { { -INT16_C(  5737), -INT16_C( 32645), -INT16_C( 13143),  INT16_C( 17070), -INT16_C(  9779),  INT16_C(  3133),  INT16_C(  7432), -INT16_C(  4374) },
        UINT32_C(          12),
        {  INT16_C( 28672), -INT16_C( 20480), -INT16_C( 28672), -INT16_C(  8192), -INT16_C( 12288), -INT16_C( 12288),       INT16_MIN, -INT16_C( 24576) } },
      { { -INT16_C(  5020), -INT16_C( 22433), -INT16_C(  6540), -INT16_C( 10021),  INT16_C( 24210), -INT16_C( 31872),  INT16_C( 20096),  INT16_C( 18754) },
        UINT32_C(          11),
        {  INT16_C(  8192), -INT16_C(  2048), -INT16_C( 24576), -INT16_C( 10240), -INT16_C( 28672),  INT16_C(     0),  INT16_C(     0),  INT16_C(  4096) } },
      { { -INT16_C(  5020), -INT16_C( 22433), -INT16_C(  6540), -INT16_C( 10021),  INT16_C( 24210), -INT16_C( 31872),  INT16_C( 20096),  INT16_C( 18754) },
        UINT32_C(          16),
        { -INT16_C(  5020), -INT16_C( 22433), -INT16_C(  6540), -INT16_C( 10021),  INT16_C( 24210), -INT16_C( 31872),  INT16_C( 20096),  INT16_C( 18754) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t r = simde_wasm_i16x8_shl(a, test_vec[i].count);
      simde_test_wasm_i16x8_assert_equal(r, simde_wasm_v128_load(test_vec[i].r));
    }
    return 0;
  #else
    fputc('\n', stdout);
    for (int i = 0 ; i < 8 ; i++) {
      simde_v128_t a = simde_test_wasm_i16x8_random();
      uint32_t count = simde_test_codegen_random_u32() & 15;
      simde_v128_t r;

      r = simde_wasm_i16x8_shl(a, count);

      simde_test_wasm_i16x8_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_codegen_write_u32(3, count, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_wasm_i16x8_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_i32x4_shl(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      int32_t a[sizeof(simde_v128_t) / sizeof(int32_t)];
      uint32_t count;
      int32_t r[sizeof(simde_v128_t) / sizeof(int32_t)];
    } test_vec[] = {
      { {  INT32_C(  1062686501),  INT32_C(  1109664763),  INT32_C(  1178000478),  INT32_C(  1464498185) },
        UINT32_C(           0),
        {  INT32_C(  1062686501),  INT32_C(  1109664763),  INT32_C(  1178000478),  INT32_C(  1464498185) } },
      { { -INT32_C(   196388868),  INT32_C(   415160423), -INT32_C(   454941570),  INT32_C(   762781520) },
        UINT32_C(          28),
        { -INT32_C(  1073741824),  INT32_C(  1879048192), -INT32_C(   536870912),  INT32_C(           0) } },
      { { -INT32_C(   336455778), -INT32_C(  1146436972),  INT32_C(   576800660), -INT32_C(  1440179267) },
        UINT32_C(           3),
        {  INT32_C(  1603321072), -INT32_C(   581561184),  INT32_C(   319437984),  INT32_C(  1363467752) } },
      { { -INT32_C(  1733640825),  INT32_C(   576150322), -INT32_C(   169647170), -INT32_C(  1979641671) },
        UINT32_C(           2),
        {  INT32_C(  1655371292), -INT32_C(  1990366008), -INT32_C(   678588680),  INT32_C(   671367908) } },
      { { -INT32_C(  2075563607), -INT32_C(    16413004),  INT32_C(   851515553),  INT32_C(   509131507) },
        UINT32_C(          26),
        { -INT32_C(  1543503872), -INT32_C(   805306368), -INT32_C(  2080374784), -INT32_C(   872415232) } },
      { { -INT32_C(   240814661), -INT32_C(   399186326), -INT32_C(  1085420040), -INT32_C(  1959513602) },
        UINT32_C(          28),
        { -INT32_C(  1342177280), -INT32_C(  1610612736),            INT32_MIN, -INT32_C(   536870912) } },
      { {  INT32_C(  1524803863),  INT32_C(   987600665),  INT32_C(   256512380),  INT32_C(   421078273) },
        UINT32_C(          30),
        { -INT32_C(  1073741824),  INT32_C(  1073741824),  INT32_C(           0),  INT32_C(  1073741824) } },
      { {  INT32_C(  1808363558), -INT32_C(  1942637457),  INT32_C(   910256529), -INT32_C(   557645770) },
        UINT32_C(          29),
        { -INT32_C(  1073741824), -INT32_C(   536870912),  INT32_C(   536870912), -INT32_C(  1073741824) } },
      { {  INT32_C(  1808363558), -INT32_C(  1942637457),  INT32_C(   910256529), -INT32_C(   557645770) },
        UINT32_C(          32),
        {  INT32_C(  1808363558), -INT32_C(  1942637457),  INT32_C(   910256529), -INT32_C(   557645770) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t r = simde_wasm_i32x4_shl(a, test_vec[i].count);
      simde_test_wasm_i32x4_assert_equal(r, simde_wasm_v128_load(test_vec[i].r));
    }
    return 0;
  #else
    fputc('\n', stdout);
    for (int i = 0 ; i < 8 ; i++) {
      simde_v128_t a = simde_test_wasm_i32x4_random();
      uint32_t count = simde_test_codegen_random_u32() & 31;
      simde_v128_t r;

      r = simde_wasm_i32x4_shl(a, count);

      simde_test_wasm_i32x4_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_codegen_write_u32(3, count, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_wasm_i32x4_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_i64x2_shl(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      int64_t a[sizeof(simde_v128_t) / sizeof(int64_t)];
      uint32_t count;
      int64_t r[sizeof(simde_v128_t) / sizeof(int64_t)];
    } test_vec[] = {
      { {  INT64_C( 5701856251717593857), -INT64_C( 2025804900168465017) },
        UINT32_C(           3),
        {  INT64_C( 8721361866321647624),  INT64_C( 2240304872361831480) } },
      { { -INT64_C( 3163294674161874349), -INT64_C( 5031187540013540910) },
        UINT32_C(          49),
        { -INT64_C( 7735495309962248192),  INT64_C( 3721099192114872320) } },
      { { -INT64_C( 4041574126402939247), -INT64_C( 4702081226727265338) },
        UINT32_C(          21),
        {  INT64_C( 4024189445671485440),  INT64_C( 4696969008501489664) } },
      { { -INT64_C( 3779350334443232800), -INT64_C( 6946378759942985897) },
        UINT32_C(          62),
        {  INT64_C(                   0), -INT64_C( 4611686018427387904) } },
      { {  INT64_C( 6190996765399022293),  INT64_C( 5707925930680274158) },
        UINT32_C(           7),
        { -INT64_C(  762409198435865984), -INT64_C( 7255243821306972416) } },
      { {  INT64_C(  179926688668206086), -INT64_C( 7352925779578745557) },
        UINT32_C(          57),
        {  INT64_C(  864691128455135232),  INT64_C( 6196953087261802496) } },
      { {  INT64_C( 3392166910737353545), -INT64_C(  778967838405646893) },
        UINT32_C(          29),
        { -INT64_C( 6437137652306149376),  INT64_C( 1840869138394775552) } },
      { { -INT64_C( 6198146708162311554), -INT64_C( 6606809925307964581) },
        UINT32_C(          38),
        { -INT64_C( 8168791401992028160), -INT64_C( 2334880286669537280) } },
      { { -INT64_C( 6198146708162311554), -INT64_C( 6606809925307964581) },
        UINT32_C(          64),
        { -INT64_C( 6198146708162311554), -INT64_C( 6606809925307964581) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t r = simde_wasm_i64x2_shl(a, test_vec[i].count);
      simde_test_wasm_i64x2_assert_equal(r, simde_wasm_v128_load(test_vec[i].r));
    }
    return 0;
  #else
    fputc('\n', stdout);
    for (int i = 0 ; i < 8 ; i++) {
      simde_v128_t a = simde_test_wasm_i64x2_random();
      uint32_t count = simde_test_codegen_random_u32() & 63;
      simde_v128_t r;

      r = simde_wasm_i64x2_shl(a, count);

      simde_test_wasm_i64x2_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_codegen_write_u32(3, count, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_wasm_i64x2_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_i8x16_shl)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_i16x8_shl)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_i32x4_shl)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_i64x2_shl)
SIMDE_TEST_FUNC_LIST_END

#include "test-simd128-footer.h"
