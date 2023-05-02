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

#define SIMDE_TEST_WASM_SIMD128_INSN max
#include "../../../simde/wasm/simd128.h"
#include "test-simd128.h"

static int
test_simde_wasm_i8x16_max(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      int8_t a[sizeof(simde_v128_t) / sizeof(int8_t)];
      int8_t b[sizeof(simde_v128_t) / sizeof(int8_t)];
      int8_t r[sizeof(simde_v128_t) / sizeof(int8_t)];
    } test_vec[] = {
      { {  INT8_C(  12),  INT8_C(  73), -INT8_C( 126),  INT8_C(  38), -INT8_C(  42), -INT8_C(  69),  INT8_C( 115),  INT8_C(  83),
          -INT8_C(  59), -INT8_C( 106), -INT8_C(  88), -INT8_C(  12), -INT8_C(  55),  INT8_C(  70),  INT8_C( 124),  INT8_C(  32) },
        { -INT8_C(  48), -INT8_C(  56), -INT8_C(  36),  INT8_C( 124), -INT8_C(  62), -INT8_C(   8),  INT8_C(  62), -INT8_C(  26),
           INT8_C(  56),  INT8_C( 112),  INT8_C(  32), -INT8_C(   1),  INT8_C(  79), -INT8_C( 111),  INT8_C(  79),  INT8_C(  64) },
        {  INT8_C(  12),  INT8_C(  73), -INT8_C(  36),  INT8_C( 124), -INT8_C(  42), -INT8_C(   8),  INT8_C( 115),  INT8_C(  83),
           INT8_C(  56),  INT8_C( 112),  INT8_C(  32), -INT8_C(   1),  INT8_C(  79),  INT8_C(  70),  INT8_C( 124),  INT8_C(  64) } },
      { { -INT8_C(   9),  INT8_C(  41), -INT8_C(  53), -INT8_C(  79), -INT8_C(  65),  INT8_C(  18), -INT8_C(   3), -INT8_C(  14),
           INT8_C(  99),  INT8_C( 117), -INT8_C(  83),  INT8_C( 123),  INT8_C(  23),  INT8_C(  66), -INT8_C(  30), -INT8_C(  15) },
        { -INT8_C( 108), -INT8_C(  64),  INT8_C(  82), -INT8_C(  16),  INT8_C(  41),  INT8_C( 113),  INT8_C(  41), -INT8_C( 105),
           INT8_C( 115),  INT8_C(  68), -INT8_C( 106),  INT8_C( 120), -INT8_C(  96), -INT8_C(  93), -INT8_C( 121), -INT8_C(  49) },
        { -INT8_C(   9),  INT8_C(  41),  INT8_C(  82), -INT8_C(  16),  INT8_C(  41),  INT8_C( 113),  INT8_C(  41), -INT8_C(  14),
           INT8_C( 115),  INT8_C( 117), -INT8_C(  83),  INT8_C( 123),  INT8_C(  23),  INT8_C(  66), -INT8_C(  30), -INT8_C(  15) } },
      { {  INT8_C(  93),  INT8_C(  67),  INT8_C( 114), -INT8_C( 113),  INT8_C(  52),  INT8_C(  14),  INT8_C(  95),  INT8_C(  29),
          -INT8_C(  34),  INT8_C(  11), -INT8_C(   7), -INT8_C(  50), -INT8_C( 101), -INT8_C(  62), -INT8_C(  48),  INT8_C(  47) },
        {  INT8_C(  40),  INT8_C(   6),  INT8_C(  18),  INT8_C( 116),  INT8_C(  39),  INT8_C(  58), -INT8_C(  30),  INT8_C( 126),
           INT8_C( 123), -INT8_C(   2), -INT8_C(  57), -INT8_C(  48),  INT8_C( 109),  INT8_C( 101),  INT8_C(  86),  INT8_C( 118) },
        {  INT8_C(  93),  INT8_C(  67),  INT8_C( 114),  INT8_C( 116),  INT8_C(  52),  INT8_C(  58),  INT8_C(  95),  INT8_C( 126),
           INT8_C( 123),  INT8_C(  11), -INT8_C(   7), -INT8_C(  48),  INT8_C( 109),  INT8_C( 101),  INT8_C(  86),  INT8_C( 118) } },
      { {  INT8_C(   0), -INT8_C( 102),  INT8_C(  99),  INT8_C(   5), -INT8_C( 107), -INT8_C(  96),  INT8_C(   5),  INT8_C( 110),
          -INT8_C(  16), -INT8_C(   5), -INT8_C(   4),  INT8_C(  86),  INT8_C( 123), -INT8_C(   6),  INT8_C(  34), -INT8_C(  94) },
        {  INT8_C(  83),  INT8_C(  72),  INT8_C(  90),  INT8_C(  35),  INT8_C(   9), -INT8_C(   3), -INT8_C(   8),  INT8_C(  66),
          -INT8_C(   6), -INT8_C(  64), -INT8_C(  88), -INT8_C( 112), -INT8_C( 102),  INT8_C(   4),  INT8_C(  66),  INT8_C( 122) },
        {  INT8_C(  83),  INT8_C(  72),  INT8_C(  99),  INT8_C(  35),  INT8_C(   9), -INT8_C(   3),  INT8_C(   5),  INT8_C( 110),
          -INT8_C(   6), -INT8_C(   5), -INT8_C(   4),  INT8_C(  86),  INT8_C( 123),  INT8_C(   4),  INT8_C(  66),  INT8_C( 122) } },
      { { -INT8_C(  81), -INT8_C(  22), -INT8_C(  98), -INT8_C(  73), -INT8_C(  89),  INT8_C(  38),  INT8_C( 124),  INT8_C(  79),
           INT8_C(   9),  INT8_C(  65),  INT8_C(  55),  INT8_C(  42),  INT8_C(  63), -INT8_C( 122), -INT8_C(   5), -INT8_C(  12) },
        { -INT8_C(  99), -INT8_C(  94), -INT8_C( 118),  INT8_C(  80),  INT8_C(  74), -INT8_C(  69), -INT8_C(   2),  INT8_C(  50),
          -INT8_C(  77), -INT8_C(  89),      INT8_MAX,  INT8_C(  62), -INT8_C(  27), -INT8_C(  18),  INT8_C(  46),  INT8_C(  69) },
        { -INT8_C(  81), -INT8_C(  22), -INT8_C(  98),  INT8_C(  80),  INT8_C(  74),  INT8_C(  38),  INT8_C( 124),  INT8_C(  79),
           INT8_C(   9),  INT8_C(  65),      INT8_MAX,  INT8_C(  62),  INT8_C(  63), -INT8_C(  18),  INT8_C(  46),  INT8_C(  69) } },
      { {  INT8_C(  10), -INT8_C(  15), -INT8_C(  79),  INT8_C(  68), -INT8_C( 116),  INT8_C(  34), -INT8_C( 104), -INT8_C( 120),
           INT8_C( 121),  INT8_C(  88),  INT8_C(  23), -INT8_C( 111),  INT8_C(  34), -INT8_C(   5),  INT8_C(  81),  INT8_C(  29) },
        { -INT8_C(  51), -INT8_C(  88),  INT8_C(  98), -INT8_C(  20),  INT8_C(  78),  INT8_C(  64),  INT8_C( 120), -INT8_C( 108),
           INT8_C( 105), -INT8_C(  75),  INT8_C( 118), -INT8_C(  94), -INT8_C(   6),  INT8_C(  38), -INT8_C(  93), -INT8_C( 105) },
        {  INT8_C(  10), -INT8_C(  15),  INT8_C(  98),  INT8_C(  68),  INT8_C(  78),  INT8_C(  64),  INT8_C( 120), -INT8_C( 108),
           INT8_C( 121),  INT8_C(  88),  INT8_C( 118), -INT8_C(  94),  INT8_C(  34),  INT8_C(  38),  INT8_C(  81),  INT8_C(  29) } },
      { { -INT8_C(  63),  INT8_C(  56), -INT8_C(  70),  INT8_C( 101),  INT8_C(  50),  INT8_C( 106),  INT8_C(  40),  INT8_C(  81),
           INT8_C(  13), -INT8_C(  31),  INT8_C(  79),  INT8_C(   2), -INT8_C(  27),  INT8_C(   1), -INT8_C(  11),  INT8_C(  81) },
        { -INT8_C(  16), -INT8_C(  27), -INT8_C(  72),  INT8_C(  99), -INT8_C( 116),  INT8_C(  29),  INT8_C(  69),  INT8_C( 115),
           INT8_C(  60),  INT8_C(  53), -INT8_C(  66), -INT8_C( 127),  INT8_C(   6),  INT8_C(  30), -INT8_C(  97),  INT8_C(  54) },
        { -INT8_C(  16),  INT8_C(  56), -INT8_C(  70),  INT8_C( 101),  INT8_C(  50),  INT8_C( 106),  INT8_C(  69),  INT8_C( 115),
           INT8_C(  60),  INT8_C(  53),  INT8_C(  79),  INT8_C(   2),  INT8_C(   6),  INT8_C(  30), -INT8_C(  11),  INT8_C(  81) } },
      { {  INT8_C(  91),  INT8_C(  83), -INT8_C(  39), -INT8_C( 113),  INT8_C(  73), -INT8_C(  24),  INT8_C(  23), -INT8_C(  37),
           INT8_C(  52), -INT8_C(  54), -INT8_C(  77), -INT8_C(  95),  INT8_C(  34), -INT8_C(  22),  INT8_C(  31),  INT8_C( 115) },
        { -INT8_C(  41), -INT8_C(  19), -INT8_C(  72), -INT8_C(   9),  INT8_C(  73),  INT8_C(  31), -INT8_C( 117), -INT8_C(  17),
          -INT8_C( 109), -INT8_C(  93),  INT8_C(  37), -INT8_C(  34), -INT8_C(  58),  INT8_C(  14), -INT8_C(  40),  INT8_C(  28) },
        {  INT8_C(  91),  INT8_C(  83), -INT8_C(  39), -INT8_C(   9),  INT8_C(  73),  INT8_C(  31),  INT8_C(  23), -INT8_C(  17),
           INT8_C(  52), -INT8_C(  54),  INT8_C(  37), -INT8_C(  34),  INT8_C(  34),  INT8_C(  14),  INT8_C(  31),  INT8_C( 115) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t b = simde_wasm_v128_load(test_vec[i].b);
      simde_v128_t r = simde_wasm_i8x16_max(a, b);
      simde_test_wasm_i8x16_assert_equal(r, simde_wasm_v128_load(test_vec[i].r));
    }
    return 0;
  #else
    fputc('\n', stdout);
    for (int i = 0 ; i < 8 ; i++) {
      simde_v128_t
        a = simde_test_wasm_i8x16_random(),
        b = simde_test_wasm_i8x16_random(),
        r;

      r = simde_wasm_i8x16_max(a, b);

      simde_test_wasm_i8x16_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_i8x16_write(3, b, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_wasm_i8x16_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_i16x8_max(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      int16_t a[sizeof(simde_v128_t) / sizeof(int16_t)];
      int16_t b[sizeof(simde_v128_t) / sizeof(int16_t)];
      int16_t r[sizeof(simde_v128_t) / sizeof(int16_t)];
    } test_vec[] = {
      { { -INT16_C( 19848),  INT16_C(  3123), -INT16_C( 13899),  INT16_C( 26398), -INT16_C(  2141),  INT16_C( 16273), -INT16_C( 14558),  INT16_C(   123) },
        { -INT16_C(  9441), -INT16_C( 22628),  INT16_C( 17861),  INT16_C(  2337),  INT16_C(  5498), -INT16_C( 18636), -INT16_C( 14817),  INT16_C(  9873) },
        { -INT16_C(  9441),  INT16_C(  3123),  INT16_C( 17861),  INT16_C( 26398),  INT16_C(  5498),  INT16_C( 16273), -INT16_C( 14558),  INT16_C(  9873) } },
      { { -INT16_C(  8302), -INT16_C( 23705),  INT16_C( 14720), -INT16_C( 12818),  INT16_C( 26743), -INT16_C( 10094),  INT16_C(   554),  INT16_C( 32691) },
        {  INT16_C( 23218), -INT16_C( 31000),  INT16_C( 14065), -INT16_C(  2181),  INT16_C(  7304),  INT16_C( 18374),  INT16_C(  3633),  INT16_C( 17118) },
        {  INT16_C( 23218), -INT16_C( 23705),  INT16_C( 14720), -INT16_C(  2181),  INT16_C( 26743),  INT16_C( 18374),  INT16_C(  3633),  INT16_C( 32691) } },
      { {  INT16_C( 19266), -INT16_C( 20596), -INT16_C( 26033), -INT16_C( 27689), -INT16_C(  8744), -INT16_C( 28145),  INT16_C( 29270),  INT16_C( 29559) },
        {  INT16_C( 13001), -INT16_C( 25051),  INT16_C( 14753), -INT16_C(  4335),  INT16_C( 13119), -INT16_C( 16087),  INT16_C( 30180),  INT16_C(  8303) },
        {  INT16_C( 19266), -INT16_C( 20596),  INT16_C( 14753), -INT16_C(  4335),  INT16_C( 13119), -INT16_C( 16087),  INT16_C( 30180),  INT16_C( 29559) } },
      { { -INT16_C( 28413), -INT16_C( 15956),  INT16_C( 14418),  INT16_C( 29944),  INT16_C(   284),  INT16_C( 16621), -INT16_C(  2843), -INT16_C( 15091) },
        {  INT16_C( 17776),  INT16_C( 20763), -INT16_C( 20929),  INT16_C( 30545), -INT16_C( 24590), -INT16_C( 27724), -INT16_C( 22014),  INT16_C( 25057) },
        {  INT16_C( 17776),  INT16_C( 20763),  INT16_C( 14418),  INT16_C( 30545),  INT16_C(   284),  INT16_C( 16621), -INT16_C(  2843),  INT16_C( 25057) } },
      { {  INT16_C( 16499), -INT16_C( 16450), -INT16_C( 32070),  INT16_C( 29927),  INT16_C(  4204),  INT16_C( 23293), -INT16_C( 32499), -INT16_C( 18599) },
        {  INT16_C(  8074),  INT16_C( 12688),  INT16_C(   513),  INT16_C( 13573), -INT16_C(  9433),  INT16_C(  8674),  INT16_C( 22214),  INT16_C( 17025) },
        {  INT16_C( 16499),  INT16_C( 12688),  INT16_C(   513),  INT16_C( 29927),  INT16_C(  4204),  INT16_C( 23293),  INT16_C( 22214),  INT16_C( 17025) } },
      { {  INT16_C(  8218), -INT16_C( 31712), -INT16_C( 16212),  INT16_C( 28379), -INT16_C(   542), -INT16_C( 32306), -INT16_C( 14765),  INT16_C( 20838) },
        { -INT16_C(  2221),  INT16_C( 26491),  INT16_C(  9877),  INT16_C( 15935),  INT16_C( 31864),  INT16_C(  2547),  INT16_C( 28913), -INT16_C( 11617) },
        {  INT16_C(  8218),  INT16_C( 26491),  INT16_C(  9877),  INT16_C( 28379),  INT16_C( 31864),  INT16_C(  2547),  INT16_C( 28913),  INT16_C( 20838) } },
      { { -INT16_C(  1112), -INT16_C(   617),  INT16_C( 19632),  INT16_C(  9309),  INT16_C(  6195),  INT16_C( 32017),  INT16_C( 14937),  INT16_C( 20600) },
        {  INT16_C( 14689), -INT16_C( 28983), -INT16_C( 30372), -INT16_C(  7483), -INT16_C( 26119), -INT16_C(  8706),  INT16_C(  5211), -INT16_C( 26287) },
        {  INT16_C( 14689), -INT16_C(   617),  INT16_C( 19632),  INT16_C(  9309),  INT16_C(  6195),  INT16_C( 32017),  INT16_C( 14937),  INT16_C( 20600) } },
      { { -INT16_C(  7748), -INT16_C( 13886),  INT16_C( 18346), -INT16_C( 13462),  INT16_C( 14795), -INT16_C( 17296), -INT16_C( 18894), -INT16_C( 26993) },
        { -INT16_C( 29397),  INT16_C(  4239), -INT16_C( 29416), -INT16_C(     6), -INT16_C( 19942),  INT16_C( 26003), -INT16_C(  8952), -INT16_C( 12347) },
        { -INT16_C(  7748),  INT16_C(  4239),  INT16_C( 18346), -INT16_C(     6),  INT16_C( 14795),  INT16_C( 26003), -INT16_C(  8952), -INT16_C( 12347) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t b = simde_wasm_v128_load(test_vec[i].b);
      simde_v128_t r = simde_wasm_i16x8_max(a, b);
      simde_test_wasm_i16x8_assert_equal(r, simde_wasm_v128_load(test_vec[i].r));
    }
    return 0;
  #else
    fputc('\n', stdout);
    for (int i = 0 ; i < 8 ; i++) {
      simde_v128_t
        a = simde_test_wasm_i16x8_random(),
        b = simde_test_wasm_i16x8_random(),
        r;

      r = simde_wasm_i16x8_max(a, b);

      simde_test_wasm_i16x8_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_i16x8_write(3, b, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_wasm_i16x8_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_i32x4_max(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      int32_t a[sizeof(simde_v128_t) / sizeof(int32_t)];
      int32_t b[sizeof(simde_v128_t) / sizeof(int32_t)];
      int32_t r[sizeof(simde_v128_t) / sizeof(int32_t)];
    } test_vec[] = {
      { {  INT32_C(  1461580068),  INT32_C(   472305735),  INT32_C(  1340498804),  INT32_C(   460818998) },
        {  INT32_C(   197877001), -INT32_C(   817136608),  INT32_C(  1574180872),  INT32_C(    67745720) },
        {  INT32_C(  1461580068),  INT32_C(   472305735),  INT32_C(  1574180872),  INT32_C(   460818998) } },
      { { -INT32_C(  1988648285), -INT32_C(   469517067),  INT32_C(  1839328634),  INT32_C(  1431377494) },
        { -INT32_C(  1449338184),  INT32_C(   890897171), -INT32_C(  1257254251),  INT32_C(  1414740992) },
        { -INT32_C(  1449338184),  INT32_C(   890897171),  INT32_C(  1839328634),  INT32_C(  1431377494) } },
      { { -INT32_C(   840072142),  INT32_C(   292343122),  INT32_C(  1851140171),  INT32_C(   798941419) },
        {  INT32_C(   100567134), -INT32_C(  1943656691),  INT32_C(  1322845331),  INT32_C(   332629461) },
        {  INT32_C(   100567134),  INT32_C(   292343122),  INT32_C(  1851140171),  INT32_C(   798941419) } },
      { { -INT32_C(  1066823997),  INT32_C(  1106340130),  INT32_C(  1277331353),  INT32_C(  1942826253) },
        { -INT32_C(  2046476022), -INT32_C(    75711401),  INT32_C(   984341185), -INT32_C(    34109786) },
        { -INT32_C(  1066823997),  INT32_C(  1106340130),  INT32_C(  1277331353),  INT32_C(  1942826253) } },
      { {  INT32_C(  1268310404), -INT32_C(   722219070), -INT32_C(  1562360573), -INT32_C(  1153428122) },
        { -INT32_C(  1046954309),  INT32_C(  1054497692),  INT32_C(  2096752676), -INT32_C(   432348438) },
        {  INT32_C(  1268310404),  INT32_C(  1054497692),  INT32_C(  2096752676), -INT32_C(   432348438) } },
      { {  INT32_C(  1147801252),  INT32_C(  2009977366),  INT32_C(   721915187), -INT32_C(   522380159) },
        { -INT32_C(   743596576), -INT32_C(   157098854),  INT32_C(  1205082609), -INT32_C(   412138953) },
        {  INT32_C(  1147801252),  INT32_C(  2009977366),  INT32_C(  1205082609), -INT32_C(   412138953) } },
      { { -INT32_C(  1928798060),  INT32_C(   897452549), -INT32_C(  1090248576), -INT32_C(   401193055) },
        {  INT32_C(  1208018779),  INT32_C(  2084522328), -INT32_C(  1141042961),  INT32_C(   243937234) },
        {  INT32_C(  1208018779),  INT32_C(  2084522328), -INT32_C(  1090248576),  INT32_C(   243937234) } },
      { { -INT32_C(  1353473079),  INT32_C(   131699298), -INT32_C(   703234538),  INT32_C(  1970582802) },
        {  INT32_C(  1901336838),  INT32_C(   739465943),  INT32_C(   612700245), -INT32_C(  1880332862) },
        {  INT32_C(  1901336838),  INT32_C(   739465943),  INT32_C(   612700245),  INT32_C(  1970582802) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t b = simde_wasm_v128_load(test_vec[i].b);
      simde_v128_t r = simde_wasm_i32x4_max(a, b);
      simde_test_wasm_i32x4_assert_equal(r, simde_wasm_v128_load(test_vec[i].r));
    }
    return 0;
  #else
    fputc('\n', stdout);
    for (int i = 0 ; i < 8 ; i++) {
      simde_v128_t
        a = simde_test_wasm_i32x4_random(),
        b = simde_test_wasm_i32x4_random(),
        r;

      r = simde_wasm_i32x4_max(a, b);

      simde_test_wasm_i32x4_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_i32x4_write(3, b, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_wasm_i32x4_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_u8x16_max(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      uint8_t a[sizeof(simde_v128_t) / sizeof(uint8_t)];
      uint8_t b[sizeof(simde_v128_t) / sizeof(uint8_t)];
      uint8_t r[sizeof(simde_v128_t) / sizeof(uint8_t)];
    } test_vec[] = {
      { { UINT8_C(  2), UINT8_C(231), UINT8_C(219), UINT8_C(254), UINT8_C(102), UINT8_C( 59), UINT8_C( 43), UINT8_C(224),
          UINT8_C(150), UINT8_C(136), UINT8_C(165), UINT8_C(131), UINT8_C(253), UINT8_C(183), UINT8_C(163), UINT8_C(182) },
        { UINT8_C(183), UINT8_C(172), UINT8_C( 41), UINT8_C( 76), UINT8_C( 68), UINT8_C(101), UINT8_C(225), UINT8_C( 53),
          UINT8_C( 52), UINT8_C(102), UINT8_C(231), UINT8_C(188), UINT8_C(103), UINT8_C(172), UINT8_C( 47), UINT8_C(110) },
        { UINT8_C(183), UINT8_C(231), UINT8_C(219), UINT8_C(254), UINT8_C(102), UINT8_C(101), UINT8_C(225), UINT8_C(224),
          UINT8_C(150), UINT8_C(136), UINT8_C(231), UINT8_C(188), UINT8_C(253), UINT8_C(183), UINT8_C(163), UINT8_C(182) } },
      { { UINT8_C(  9), UINT8_C(205), UINT8_C( 96), UINT8_C( 53), UINT8_C(163), UINT8_C( 66), UINT8_C(104), UINT8_C( 62),
          UINT8_C( 54), UINT8_C(175), UINT8_C( 36), UINT8_C(245), UINT8_C(186), UINT8_C( 99), UINT8_C(253), UINT8_C(211) },
        { UINT8_C(188), UINT8_C( 24), UINT8_C(250), UINT8_C(218), UINT8_C(174), UINT8_C(222), UINT8_C(185), UINT8_C(233),
          UINT8_C( 86), UINT8_C( 77), UINT8_C(161), UINT8_C(233), UINT8_C(135), UINT8_C( 48), UINT8_C(109), UINT8_C(180) },
        { UINT8_C(188), UINT8_C(205), UINT8_C(250), UINT8_C(218), UINT8_C(174), UINT8_C(222), UINT8_C(185), UINT8_C(233),
          UINT8_C( 86), UINT8_C(175), UINT8_C(161), UINT8_C(245), UINT8_C(186), UINT8_C( 99), UINT8_C(253), UINT8_C(211) } },
      { { UINT8_C(247), UINT8_C(199), UINT8_C(200), UINT8_C(151), UINT8_C(112), UINT8_C(139), UINT8_C(213), UINT8_C( 60),
          UINT8_C(108), UINT8_C(147), UINT8_C(102), UINT8_C(119), UINT8_C(166), UINT8_C(175), UINT8_C(146), UINT8_C(223) },
        { UINT8_C(232), UINT8_C( 94), UINT8_C(246), UINT8_C(  5), UINT8_C( 54), UINT8_C( 69), UINT8_C( 97), UINT8_C(139),
          UINT8_C(161), UINT8_C( 86), UINT8_C( 83), UINT8_C(249), UINT8_C(230), UINT8_C( 86), UINT8_C( 19), UINT8_C( 25) },
        { UINT8_C(247), UINT8_C(199), UINT8_C(246), UINT8_C(151), UINT8_C(112), UINT8_C(139), UINT8_C(213), UINT8_C(139),
          UINT8_C(161), UINT8_C(147), UINT8_C(102), UINT8_C(249), UINT8_C(230), UINT8_C(175), UINT8_C(146), UINT8_C(223) } },
      { { UINT8_C(246), UINT8_C(230), UINT8_C(152), UINT8_C(140), UINT8_C(229), UINT8_C( 83), UINT8_C( 53), UINT8_C( 25),
          UINT8_C(  8), UINT8_C( 47), UINT8_C(125), UINT8_C(236), UINT8_C(111), UINT8_C(  5), UINT8_C(185), UINT8_C( 69) },
        { UINT8_C( 14), UINT8_C( 13), UINT8_C( 59), UINT8_C(253), UINT8_C(197), UINT8_C(163), UINT8_C( 67), UINT8_C(159),
          UINT8_C(251), UINT8_C( 79), UINT8_C( 86), UINT8_C(100), UINT8_C( 87), UINT8_C( 20), UINT8_C( 34), UINT8_C( 54) },
        { UINT8_C(246), UINT8_C(230), UINT8_C(152), UINT8_C(253), UINT8_C(229), UINT8_C(163), UINT8_C( 67), UINT8_C(159),
          UINT8_C(251), UINT8_C( 79), UINT8_C(125), UINT8_C(236), UINT8_C(111), UINT8_C( 20), UINT8_C(185), UINT8_C( 69) } },
      { { UINT8_C(131), UINT8_C(156), UINT8_C(249), UINT8_C(193), UINT8_C( 72), UINT8_C(107), UINT8_C(114), UINT8_C( 79),
          UINT8_C(221), UINT8_C(126), UINT8_C( 17), UINT8_C(208), UINT8_C(240), UINT8_C( 94), UINT8_C( 22), UINT8_C(182) },
        { UINT8_C(  7), UINT8_C(206), UINT8_C(149), UINT8_C( 20), UINT8_C( 60), UINT8_C(127), UINT8_C(212), UINT8_C(183),
          UINT8_C(172), UINT8_C(171), UINT8_C(216), UINT8_C(138), UINT8_C( 78), UINT8_C(201), UINT8_C(  3), UINT8_C( 51) },
        { UINT8_C(131), UINT8_C(206), UINT8_C(249), UINT8_C(193), UINT8_C( 72), UINT8_C(127), UINT8_C(212), UINT8_C(183),
          UINT8_C(221), UINT8_C(171), UINT8_C(216), UINT8_C(208), UINT8_C(240), UINT8_C(201), UINT8_C( 22), UINT8_C(182) } },
      { { UINT8_C( 53), UINT8_C(  5), UINT8_C( 38), UINT8_C(200), UINT8_C(  2), UINT8_C(238), UINT8_C(201), UINT8_C( 30),
          UINT8_C(228), UINT8_C(163), UINT8_C( 62), UINT8_C(183), UINT8_C(125), UINT8_C(210), UINT8_C( 38), UINT8_C(157) },
        { UINT8_C( 55), UINT8_C( 98), UINT8_C(180), UINT8_C( 33), UINT8_C( 41), UINT8_C( 85), UINT8_C(131), UINT8_C(196),
          UINT8_C( 67), UINT8_C(101), UINT8_C(123), UINT8_C(243), UINT8_C(245), UINT8_C(145), UINT8_C(204), UINT8_C(245) },
        { UINT8_C( 55), UINT8_C( 98), UINT8_C(180), UINT8_C(200), UINT8_C( 41), UINT8_C(238), UINT8_C(201), UINT8_C(196),
          UINT8_C(228), UINT8_C(163), UINT8_C(123), UINT8_C(243), UINT8_C(245), UINT8_C(210), UINT8_C(204), UINT8_C(245) } },
      { { UINT8_C(253), UINT8_C(175), UINT8_C(113), UINT8_C( 52), UINT8_C( 18), UINT8_C(119), UINT8_C(117), UINT8_C(155),
          UINT8_C(218), UINT8_C(143), UINT8_C(239), UINT8_C( 76), UINT8_C(186), UINT8_C(184), UINT8_C( 74), UINT8_C(  7) },
        { UINT8_C(140), UINT8_C( 51), UINT8_C(232), UINT8_C( 93), UINT8_C(248), UINT8_C(142), UINT8_C( 35), UINT8_C(229),
          UINT8_C(247), UINT8_C(110), UINT8_C(105), UINT8_C( 13), UINT8_C(190), UINT8_C( 30), UINT8_C( 13), UINT8_C(208) },
        { UINT8_C(253), UINT8_C(175), UINT8_C(232), UINT8_C( 93), UINT8_C(248), UINT8_C(142), UINT8_C(117), UINT8_C(229),
          UINT8_C(247), UINT8_C(143), UINT8_C(239), UINT8_C( 76), UINT8_C(190), UINT8_C(184), UINT8_C( 74), UINT8_C(208) } },
      { { UINT8_C(231), UINT8_C(221), UINT8_C(185), UINT8_C( 60),    UINT8_MAX, UINT8_C(218), UINT8_C(218), UINT8_C( 66),
          UINT8_C(104), UINT8_C( 42), UINT8_C(182), UINT8_C(208), UINT8_C(236), UINT8_C( 53), UINT8_C( 86), UINT8_C( 24) },
        { UINT8_C(  4), UINT8_C( 82), UINT8_C( 94), UINT8_C(195), UINT8_C(169), UINT8_C(243), UINT8_C(210), UINT8_C(179),
          UINT8_C(140), UINT8_C(142), UINT8_C(244), UINT8_C(105), UINT8_C(117), UINT8_C( 16), UINT8_C( 28), UINT8_C(179) },
        { UINT8_C(231), UINT8_C(221), UINT8_C(185), UINT8_C(195),    UINT8_MAX, UINT8_C(243), UINT8_C(218), UINT8_C(179),
          UINT8_C(140), UINT8_C(142), UINT8_C(244), UINT8_C(208), UINT8_C(236), UINT8_C( 53), UINT8_C( 86), UINT8_C(179) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t b = simde_wasm_v128_load(test_vec[i].b);
      simde_v128_t r = simde_wasm_u8x16_max(a, b);
      simde_test_wasm_u8x16_assert_equal(r, simde_wasm_v128_load(test_vec[i].r));
    }
    return 0;
  #else
    fputc('\n', stdout);
    for (int i = 0 ; i < 8 ; i++) {
      simde_v128_t
        a = simde_test_wasm_u8x16_random(),
        b = simde_test_wasm_u8x16_random(),
        r;

      r = simde_wasm_u8x16_max(a, b);

      simde_test_wasm_u8x16_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_u8x16_write(3, b, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_wasm_u8x16_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_u16x8_max(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      uint16_t a[sizeof(simde_v128_t) / sizeof(uint16_t)];
      uint16_t b[sizeof(simde_v128_t) / sizeof(uint16_t)];
      uint16_t r[sizeof(simde_v128_t) / sizeof(uint16_t)];
    } test_vec[] = {
      { { UINT16_C(21603), UINT16_C(54889), UINT16_C(22094), UINT16_C(  303), UINT16_C(62915), UINT16_C( 5675), UINT16_C(22987), UINT16_C(63124) },
        { UINT16_C( 1967), UINT16_C(61145), UINT16_C(43777), UINT16_C( 5740), UINT16_C(52402), UINT16_C(32944), UINT16_C(52438), UINT16_C(55261) },
        { UINT16_C(21603), UINT16_C(61145), UINT16_C(43777), UINT16_C( 5740), UINT16_C(62915), UINT16_C(32944), UINT16_C(52438), UINT16_C(63124) } },
      { { UINT16_C(39937), UINT16_C(23020), UINT16_C(21361), UINT16_C(51370), UINT16_C(14547), UINT16_C( 2501), UINT16_C(45275), UINT16_C(14933) },
        { UINT16_C(53040), UINT16_C(30961), UINT16_C(44093), UINT16_C(35948), UINT16_C(22764), UINT16_C(60173), UINT16_C(52893), UINT16_C(61714) },
        { UINT16_C(53040), UINT16_C(30961), UINT16_C(44093), UINT16_C(51370), UINT16_C(22764), UINT16_C(60173), UINT16_C(52893), UINT16_C(61714) } },
      { { UINT16_C(52155), UINT16_C(39855), UINT16_C(38205), UINT16_C(39468), UINT16_C(42191), UINT16_C(41781), UINT16_C(24629), UINT16_C(57598) },
        { UINT16_C(59845), UINT16_C(56262), UINT16_C(46148), UINT16_C(   97), UINT16_C(61172), UINT16_C(10099), UINT16_C(34586), UINT16_C(56865) },
        { UINT16_C(59845), UINT16_C(56262), UINT16_C(46148), UINT16_C(39468), UINT16_C(61172), UINT16_C(41781), UINT16_C(34586), UINT16_C(57598) } },
      { { UINT16_C(52401), UINT16_C(37019), UINT16_C(62681), UINT16_C( 7272), UINT16_C(31592), UINT16_C(28992), UINT16_C(47844), UINT16_C(45962) },
        { UINT16_C(23749), UINT16_C(52293), UINT16_C(49759), UINT16_C( 5073), UINT16_C(49560), UINT16_C(53725), UINT16_C(45380), UINT16_C(53857) },
        { UINT16_C(52401), UINT16_C(52293), UINT16_C(62681), UINT16_C( 7272), UINT16_C(49560), UINT16_C(53725), UINT16_C(47844), UINT16_C(53857) } },
      { { UINT16_C( 8562), UINT16_C(26634), UINT16_C(36920), UINT16_C(41363), UINT16_C(14950), UINT16_C(37149), UINT16_C(21681), UINT16_C(15518) },
        { UINT16_C(31654), UINT16_C( 8153), UINT16_C( 2403), UINT16_C(61097), UINT16_C(57123), UINT16_C(26356), UINT16_C( 9292), UINT16_C( 3302) },
        { UINT16_C(31654), UINT16_C(26634), UINT16_C(36920), UINT16_C(61097), UINT16_C(57123), UINT16_C(37149), UINT16_C(21681), UINT16_C(15518) } },
      { { UINT16_C(13243), UINT16_C(12618), UINT16_C(36101), UINT16_C(48269), UINT16_C(47822), UINT16_C(12365), UINT16_C(41082), UINT16_C(14095) },
        { UINT16_C(61821), UINT16_C( 8366), UINT16_C(26992), UINT16_C(37157), UINT16_C( 6205), UINT16_C(34215), UINT16_C(12210), UINT16_C(64714) },
        { UINT16_C(61821), UINT16_C(12618), UINT16_C(36101), UINT16_C(48269), UINT16_C(47822), UINT16_C(34215), UINT16_C(41082), UINT16_C(64714) } },
      { { UINT16_C( 3773), UINT16_C(61844), UINT16_C(18458), UINT16_C(19594), UINT16_C(56453), UINT16_C(36087), UINT16_C(  515), UINT16_C(31473) },
        { UINT16_C(17158), UINT16_C(31336), UINT16_C(26646), UINT16_C(41278), UINT16_C(26958), UINT16_C(42829), UINT16_C(29395), UINT16_C(64251) },
        { UINT16_C(17158), UINT16_C(61844), UINT16_C(26646), UINT16_C(41278), UINT16_C(56453), UINT16_C(42829), UINT16_C(29395), UINT16_C(64251) } },
      { { UINT16_C(46045), UINT16_C(19078), UINT16_C( 3186), UINT16_C( 3649), UINT16_C(45168), UINT16_C(27844), UINT16_C(26186), UINT16_C(26395) },
        { UINT16_C(55841), UINT16_C(36448), UINT16_C(42518), UINT16_C(46738), UINT16_C(56421), UINT16_C(25911), UINT16_C(11520), UINT16_C(29057) },
        { UINT16_C(55841), UINT16_C(36448), UINT16_C(42518), UINT16_C(46738), UINT16_C(56421), UINT16_C(27844), UINT16_C(26186), UINT16_C(29057) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t b = simde_wasm_v128_load(test_vec[i].b);
      simde_v128_t r = simde_wasm_u16x8_max(a, b);
      simde_test_wasm_u16x8_assert_equal(r, simde_wasm_v128_load(test_vec[i].r));
    }
    return 0;
  #else
    fputc('\n', stdout);
    for (int i = 0 ; i < 8 ; i++) {
      simde_v128_t
        a = simde_test_wasm_u16x8_random(),
        b = simde_test_wasm_u16x8_random(),
        r;

      r = simde_wasm_u16x8_max(a, b);

      simde_test_wasm_u16x8_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_u16x8_write(3, b, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_wasm_u16x8_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_u32x4_max(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      uint32_t a[sizeof(simde_v128_t) / sizeof(uint32_t)];
      uint32_t b[sizeof(simde_v128_t) / sizeof(uint32_t)];
      uint32_t r[sizeof(simde_v128_t) / sizeof(uint32_t)];
    } test_vec[] = {
      { { UINT32_C(2518800120), UINT32_C(2895334298), UINT32_C( 674764826), UINT32_C(3762051672) },
        { UINT32_C(1465682906), UINT32_C( 768726666), UINT32_C( 886306450), UINT32_C(2437816083) },
        { UINT32_C(2518800120), UINT32_C(2895334298), UINT32_C( 886306450), UINT32_C(3762051672) } },
      { { UINT32_C(2269129257), UINT32_C(1236752040), UINT32_C( 579924953), UINT32_C(2891752601) },
        { UINT32_C(3318585577), UINT32_C(1973760670), UINT32_C(2722274005), UINT32_C(2038946683) },
        { UINT32_C(3318585577), UINT32_C(1973760670), UINT32_C(2722274005), UINT32_C(2891752601) } },
      { { UINT32_C(1217931270), UINT32_C(2464780459), UINT32_C(3340354154), UINT32_C(1894602407) },
        { UINT32_C(2743681206), UINT32_C(3710154433), UINT32_C( 460746870), UINT32_C(3947797205) },
        { UINT32_C(2743681206), UINT32_C(3710154433), UINT32_C(3340354154), UINT32_C(3947797205) } },
      { { UINT32_C( 388911978), UINT32_C(1318071198), UINT32_C( 202297371), UINT32_C( 374761894) },
        { UINT32_C(3976642269), UINT32_C(3853604184), UINT32_C( 550162670), UINT32_C(2047908094) },
        { UINT32_C(3976642269), UINT32_C(3853604184), UINT32_C( 550162670), UINT32_C(2047908094) } },
      { { UINT32_C(1733820594), UINT32_C(1793677790), UINT32_C(1928583275), UINT32_C(3288060687) },
        { UINT32_C(3054752814), UINT32_C( 242249970), UINT32_C( 220209738), UINT32_C( 877456034) },
        { UINT32_C(3054752814), UINT32_C(1793677790), UINT32_C(1928583275), UINT32_C(3288060687) } },
      { { UINT32_C(2184225156), UINT32_C(2335573273), UINT32_C(2154703915), UINT32_C(1086987018) },
        { UINT32_C(2199442229), UINT32_C( 623627259), UINT32_C(1417333772), UINT32_C(3672167254) },
        { UINT32_C(2199442229), UINT32_C(2335573273), UINT32_C(2154703915), UINT32_C(3672167254) } },
      { { UINT32_C(2727773966), UINT32_C( 493293250), UINT32_C(3248708901), UINT32_C(3980752186) },
        { UINT32_C( 751574326), UINT32_C( 364956395), UINT32_C(1024824462), UINT32_C(2278922789) },
        { UINT32_C(2727773966), UINT32_C( 493293250), UINT32_C(3248708901), UINT32_C(3980752186) } },
      { { UINT32_C(2477336783), UINT32_C(3712219145), UINT32_C(1259430718), UINT32_C( 755848214) },
        { UINT32_C( 997274551), UINT32_C( 890085634), UINT32_C( 654805990), UINT32_C(3802850980) },
        { UINT32_C(2477336783), UINT32_C(3712219145), UINT32_C(1259430718), UINT32_C(3802850980) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t b = simde_wasm_v128_load(test_vec[i].b);
      simde_v128_t r = simde_wasm_u32x4_max(a, b);
      simde_test_wasm_u32x4_assert_equal(r, simde_wasm_v128_load(test_vec[i].r));
    }
    return 0;
  #else
    fputc('\n', stdout);
    for (int i = 0 ; i < 8 ; i++) {
      simde_v128_t
        a = simde_test_wasm_u32x4_random(),
        b = simde_test_wasm_u32x4_random(),
        r;

      r = simde_wasm_u32x4_max(a, b);

      simde_test_wasm_u32x4_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_u32x4_write(3, b, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_wasm_u32x4_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_f32x4_max(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      simde_float32 a[sizeof(simde_v128_t) / sizeof(simde_float32)];
      simde_float32 b[sizeof(simde_v128_t) / sizeof(simde_float32)];
      simde_float32 r[sizeof(simde_v128_t) / sizeof(simde_float32)];
    } test_vec[] = {
      #if !defined(SIMDE_FAST_MATH)
      { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   354.79),            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   338.79) },
        { SIMDE_FLOAT32_C(   864.37),            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   338.79) },
        {            SIMDE_MATH_NANF,            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   338.79) } },
      { { SIMDE_FLOAT32_C(    -0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(    -0.00), SIMDE_FLOAT32_C(     0.00) },
        { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(    -0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(    -0.00) },
        { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
      #endif
      { { SIMDE_FLOAT32_C(  -920.07), SIMDE_FLOAT32_C(   830.32), SIMDE_FLOAT32_C(  -196.85), SIMDE_FLOAT32_C(   291.81) },
        { SIMDE_FLOAT32_C(  -289.04), SIMDE_FLOAT32_C(    49.93), SIMDE_FLOAT32_C(  -928.55), SIMDE_FLOAT32_C(    69.77) },
        { SIMDE_FLOAT32_C(  -289.04), SIMDE_FLOAT32_C(   830.32), SIMDE_FLOAT32_C(  -196.85), SIMDE_FLOAT32_C(   291.81) } },
      { { SIMDE_FLOAT32_C(  -679.01), SIMDE_FLOAT32_C(   273.37), SIMDE_FLOAT32_C(  -532.77), SIMDE_FLOAT32_C(   127.55) },
        { SIMDE_FLOAT32_C(   100.92), SIMDE_FLOAT32_C(  -536.72), SIMDE_FLOAT32_C(  -535.51), SIMDE_FLOAT32_C(  -444.83) },
        { SIMDE_FLOAT32_C(   100.92), SIMDE_FLOAT32_C(   273.37), SIMDE_FLOAT32_C(  -532.77), SIMDE_FLOAT32_C(   127.55) } },
      { { SIMDE_FLOAT32_C(  -370.35), SIMDE_FLOAT32_C(   910.66), SIMDE_FLOAT32_C(  -449.76), SIMDE_FLOAT32_C(   756.97) },
        { SIMDE_FLOAT32_C(  -168.50), SIMDE_FLOAT32_C(   242.88), SIMDE_FLOAT32_C(  -696.72), SIMDE_FLOAT32_C(   663.79) },
        { SIMDE_FLOAT32_C(  -168.50), SIMDE_FLOAT32_C(   910.66), SIMDE_FLOAT32_C(  -449.76), SIMDE_FLOAT32_C(   756.97) } },
      { { SIMDE_FLOAT32_C(  -777.21), SIMDE_FLOAT32_C(  -561.66), SIMDE_FLOAT32_C(   225.28), SIMDE_FLOAT32_C(    30.10) },
        { SIMDE_FLOAT32_C(  -535.78), SIMDE_FLOAT32_C(  -546.75), SIMDE_FLOAT32_C(   345.48), SIMDE_FLOAT32_C(   708.52) },
        { SIMDE_FLOAT32_C(  -535.78), SIMDE_FLOAT32_C(  -546.75), SIMDE_FLOAT32_C(   345.48), SIMDE_FLOAT32_C(   708.52) } },
      { { SIMDE_FLOAT32_C(   940.56), SIMDE_FLOAT32_C(   303.87), SIMDE_FLOAT32_C(   810.53), SIMDE_FLOAT32_C(  -526.94) },
        { SIMDE_FLOAT32_C(   611.43), SIMDE_FLOAT32_C(   797.37), SIMDE_FLOAT32_C(   432.36), SIMDE_FLOAT32_C(   709.89) },
        { SIMDE_FLOAT32_C(   940.56), SIMDE_FLOAT32_C(   797.37), SIMDE_FLOAT32_C(   810.53), SIMDE_FLOAT32_C(   709.89) } },
      { { SIMDE_FLOAT32_C(  -157.18), SIMDE_FLOAT32_C(  -402.78), SIMDE_FLOAT32_C(  -362.67), SIMDE_FLOAT32_C(  -944.01) },
        { SIMDE_FLOAT32_C(   106.70), SIMDE_FLOAT32_C(  -208.07), SIMDE_FLOAT32_C(   277.04), SIMDE_FLOAT32_C(   374.11) },
        { SIMDE_FLOAT32_C(   106.70), SIMDE_FLOAT32_C(  -208.07), SIMDE_FLOAT32_C(   277.04), SIMDE_FLOAT32_C(   374.11) } },
      { { SIMDE_FLOAT32_C(  -402.16), SIMDE_FLOAT32_C(   227.84), SIMDE_FLOAT32_C(  -493.53), SIMDE_FLOAT32_C(   869.48) },
        { SIMDE_FLOAT32_C(   903.71), SIMDE_FLOAT32_C(  -712.51), SIMDE_FLOAT32_C(  -864.99), SIMDE_FLOAT32_C(  -151.96) },
        { SIMDE_FLOAT32_C(   903.71), SIMDE_FLOAT32_C(   227.84), SIMDE_FLOAT32_C(  -493.53), SIMDE_FLOAT32_C(   869.48) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t b = simde_wasm_v128_load(test_vec[i].b);
      simde_v128_t r = simde_wasm_f32x4_max(a, b);
      simde_test_wasm_f32x4_assert_equal(r, simde_wasm_v128_load(test_vec[i].r), INT_MAX);
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

      r = simde_wasm_f32x4_max(a, b);

      simde_test_wasm_f32x4_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_f32x4_write(3, b, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_wasm_f32x4_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_f64x2_max(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      simde_float64 a[sizeof(simde_v128_t) / sizeof(simde_float64)];
      simde_float64 b[sizeof(simde_v128_t) / sizeof(simde_float64)];
      simde_float64 r[sizeof(simde_v128_t) / sizeof(simde_float64)];
    } test_vec[] = {
      #if !defined(SIMDE_FAST_MATH)
      { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -874.45) },
        { SIMDE_FLOAT64_C(  -467.85),             SIMDE_MATH_NAN },
        {             SIMDE_MATH_NAN,             SIMDE_MATH_NAN } },
      { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   450.40) },
        {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   652.50) },
        {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   652.50) } },
      { { SIMDE_FLOAT64_C(    -0.00), SIMDE_FLOAT64_C(     0.00) },
        { SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(    -0.00) },
        { SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00) } },
      #endif
      { { SIMDE_FLOAT64_C(   523.06), SIMDE_FLOAT64_C(  -600.30) },
        { SIMDE_FLOAT64_C(   212.57), SIMDE_FLOAT64_C(  -725.13) },
        { SIMDE_FLOAT64_C(   523.06), SIMDE_FLOAT64_C(  -600.30) } },
      { { SIMDE_FLOAT64_C(   630.42), SIMDE_FLOAT64_C(  -507.35) },
        { SIMDE_FLOAT64_C(    28.88), SIMDE_FLOAT64_C(  -240.00) },
        { SIMDE_FLOAT64_C(   630.42), SIMDE_FLOAT64_C(  -240.00) } },
      { { SIMDE_FLOAT64_C(   373.65), SIMDE_FLOAT64_C(   213.86) },
        { SIMDE_FLOAT64_C(  -611.53), SIMDE_FLOAT64_C(   707.90) },
        { SIMDE_FLOAT64_C(   373.65), SIMDE_FLOAT64_C(   707.90) } },
      { { SIMDE_FLOAT64_C(   339.86), SIMDE_FLOAT64_C(  -860.05) },
        { SIMDE_FLOAT64_C(   213.55), SIMDE_FLOAT64_C(  -405.72) },
        { SIMDE_FLOAT64_C(   339.86), SIMDE_FLOAT64_C(  -405.72) } },
      { { SIMDE_FLOAT64_C(  -478.66), SIMDE_FLOAT64_C(  -629.72) },
        { SIMDE_FLOAT64_C(   841.82), SIMDE_FLOAT64_C(   793.27) },
        { SIMDE_FLOAT64_C(   841.82), SIMDE_FLOAT64_C(   793.27) } },
      { { SIMDE_FLOAT64_C(  -262.99), SIMDE_FLOAT64_C(   802.55) },
        { SIMDE_FLOAT64_C(  -938.61), SIMDE_FLOAT64_C(   323.51) },
        { SIMDE_FLOAT64_C(  -262.99), SIMDE_FLOAT64_C(   802.55) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t b = simde_wasm_v128_load(test_vec[i].b);
      simde_v128_t r = simde_wasm_f64x2_max(a, b);
      simde_test_wasm_f64x2_assert_equal(r, simde_wasm_v128_load(test_vec[i].r), INT_MAX);
    }
    return 0;
  #else
    fputc('\n', stdout);
    simde_float64 inputs[8 * 2 * (sizeof(simde_v128_t) / sizeof(simde_float64))];
    simde_test_wasm_f64x2_random_full(8, 2, inputs, -SIMDE_FLOAT64_C(1000.0), SIMDE_FLOAT64_C(1000.0), HEDLEY_STATIC_CAST(SimdeTestVecFloatType, SIMDE_TEST_VEC_FLOAT_NAN));
    for (size_t i = 0 ; i < 8 ; i++) {
      simde_v128_t
        a = simde_test_wasm_f64x2_random_full_extract(2, inputs, i, 0),
        b = simde_test_wasm_f64x2_random_full_extract(2, inputs, i, 1),
        r;

      r = simde_wasm_f64x2_max(a, b);

      simde_test_wasm_f64x2_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_f64x2_write(3, b, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_wasm_f64x2_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_i8x16_max)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_i16x8_max)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_i32x4_max)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_u8x16_max)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_u16x8_max)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_u32x4_max)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_f32x4_max)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_f64x2_max)
SIMDE_TEST_FUNC_LIST_END

#include "test-simd128-footer.h"
