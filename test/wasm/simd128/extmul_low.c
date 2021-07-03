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

#define SIMDE_TEST_WASM_SIMD128_INSN extmul_low
#include "../../../simde/wasm/simd128.h"
#include "test-simd128.h"

static int
test_simde_wasm_i16x8_extmul_low_i8x16(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      int8_t a[sizeof(simde_v128_t) / sizeof(int8_t)];
      int8_t b[sizeof(simde_v128_t) / sizeof(int8_t)];
      int16_t r[sizeof(simde_v128_t) / sizeof(int16_t)];
    } test_vec[] = {
      { {  INT8_C(   7),  INT8_C(  94), -INT8_C( 106), -INT8_C( 121),  INT8_C( 119),  INT8_C(  80),  INT8_C( 116), -INT8_C(  59),
          -INT8_C(  32),  INT8_C(  69),  INT8_C(  47),  INT8_C(  32), -INT8_C( 126),  INT8_C(   1),  INT8_C(  48), -INT8_C( 125) },
        { -INT8_C(  10), -INT8_C( 115),  INT8_C(  33),  INT8_C(  11),  INT8_C(  33),  INT8_C(  91), -INT8_C(  90),  INT8_C(  48),
          -INT8_C( 103), -INT8_C(  45), -INT8_C(  18),  INT8_C( 115),  INT8_C( 115),  INT8_C( 112),  INT8_C(  79), -INT8_C(  11) },
        { -INT16_C(    70), -INT16_C( 10810), -INT16_C(  3498), -INT16_C(  1331),  INT16_C(  3927),  INT16_C(  7280), -INT16_C( 10440), -INT16_C(  2832) } },
      { {  INT8_C(  31),  INT8_C(  13), -INT8_C( 127), -INT8_C(  84),  INT8_C(  23), -INT8_C(  16),  INT8_C(  52),  INT8_C(  41),
           INT8_C(   5), -INT8_C(   6),  INT8_C( 102),  INT8_C(  26),  INT8_C(  58),  INT8_C( 125), -INT8_C(  73),  INT8_C(  79) },
        { -INT8_C(   6), -INT8_C(  45), -INT8_C( 118),  INT8_C( 123), -INT8_C(  18), -INT8_C( 102), -INT8_C(  42), -INT8_C(  98),
          -INT8_C(  24),  INT8_C( 108),  INT8_C( 107),  INT8_C(  21),  INT8_C(  26), -INT8_C(  53),  INT8_C( 100), -INT8_C( 121) },
        { -INT16_C(   186), -INT16_C(   585),  INT16_C( 14986), -INT16_C( 10332), -INT16_C(   414),  INT16_C(  1632), -INT16_C(  2184), -INT16_C(  4018) } },
      { { -INT8_C( 125), -INT8_C(  60), -INT8_C(  15),  INT8_C(  55), -INT8_C(  73),  INT8_C(  94),  INT8_C(  54),      INT8_MIN,
           INT8_C(  75), -INT8_C(  16),      INT8_MIN,  INT8_C(  50),  INT8_C( 109),  INT8_C(  62),  INT8_C( 119),  INT8_C(  83) },
        {  INT8_C(  53),  INT8_C(  39),  INT8_C(  84),  INT8_C(   3),  INT8_C(   4), -INT8_C(  17), -INT8_C(  33), -INT8_C(  23),
          -INT8_C(  96), -INT8_C( 108),  INT8_C( 107), -INT8_C( 102),  INT8_C( 118), -INT8_C(  25), -INT8_C(  36), -INT8_C( 106) },
        { -INT16_C(  6625), -INT16_C(  2340), -INT16_C(  1260),  INT16_C(   165), -INT16_C(   292), -INT16_C(  1598), -INT16_C(  1782),  INT16_C(  2944) } },
      { { -INT8_C(  87),  INT8_C( 119), -INT8_C(  56), -INT8_C(  89), -INT8_C(  31),  INT8_C(  36),  INT8_C(   2), -INT8_C(  85),
           INT8_C(  45), -INT8_C(   3),  INT8_C(  31), -INT8_C(  84), -INT8_C(  32), -INT8_C(  29), -INT8_C(  94), -INT8_C(   9) },
        {  INT8_C(  69),  INT8_C(  18),  INT8_C( 111), -INT8_C(  26),  INT8_C(  70),  INT8_C(  43), -INT8_C(  83), -INT8_C(  42),
           INT8_C(  96),  INT8_C(  88),  INT8_C(  93), -INT8_C(  91), -INT8_C( 125), -INT8_C(  65),  INT8_C( 102),  INT8_C(  43) },
        { -INT16_C(  6003),  INT16_C(  2142), -INT16_C(  6216),  INT16_C(  2314), -INT16_C(  2170),  INT16_C(  1548), -INT16_C(   166),  INT16_C(  3570) } },
      { {  INT8_C( 126),  INT8_C(  71), -INT8_C( 112),  INT8_C(  87),  INT8_C( 125), -INT8_C(   7), -INT8_C(  32), -INT8_C(  90),
           INT8_C( 104),  INT8_C(  99), -INT8_C(  90), -INT8_C( 103), -INT8_C(  50), -INT8_C(  42),  INT8_C( 118),  INT8_C( 110) },
        {  INT8_C(  52),  INT8_C(  65), -INT8_C(  67),  INT8_C(  93), -INT8_C(   1),  INT8_C( 122),  INT8_C(  14),  INT8_C(  95),
          -INT8_C(  83),  INT8_C(  25), -INT8_C(  18),  INT8_C(  55),  INT8_C( 115),  INT8_C(  50),  INT8_C(  14), -INT8_C(  93) },
        {  INT16_C(  6552),  INT16_C(  4615),  INT16_C(  7504),  INT16_C(  8091), -INT16_C(   125), -INT16_C(   854), -INT16_C(   448), -INT16_C(  8550) } },
      { { -INT8_C(  90),  INT8_C(  80),  INT8_C( 115), -INT8_C( 102),  INT8_C(  72), -INT8_C(   4), -INT8_C( 125), -INT8_C( 101),
          -INT8_C(  98),  INT8_C( 122), -INT8_C( 108), -INT8_C(  38), -INT8_C(  64),  INT8_C(  98),  INT8_C(  65), -INT8_C(  87) },
        {  INT8_C( 116),  INT8_C(  13), -INT8_C(  49),  INT8_C( 125),  INT8_C(  27),  INT8_C(  91),  INT8_C(  39),      INT8_MIN,
           INT8_C(  80), -INT8_C(  16),  INT8_C(  38),  INT8_C( 109),  INT8_C(  58), -INT8_C(  38),  INT8_C(   8),  INT8_C(  91) },
        { -INT16_C( 10440),  INT16_C(  1040), -INT16_C(  5635), -INT16_C( 12750),  INT16_C(  1944), -INT16_C(   364), -INT16_C(  4875),  INT16_C( 12928) } },
      { {  INT8_C(  64), -INT8_C(  24), -INT8_C(  71),  INT8_C(  90), -INT8_C(  59),  INT8_C( 106),  INT8_C(  55),  INT8_C( 110),
           INT8_C( 120), -INT8_C(  43),  INT8_C(  96), -INT8_C( 104), -INT8_C(  34),  INT8_C(  70), -INT8_C(  16), -INT8_C(  63) },
        {  INT8_C(  98),      INT8_MAX,  INT8_C(  34), -INT8_C( 113), -INT8_C(  46),  INT8_C(  23),  INT8_C(  85), -INT8_C( 118),
           INT8_C(  59), -INT8_C( 107),  INT8_C(   0), -INT8_C(  66), -INT8_C(  88),  INT8_C( 101), -INT8_C(   5), -INT8_C(  26) },
        {  INT16_C(  6272), -INT16_C(  3048), -INT16_C(  2414), -INT16_C( 10170),  INT16_C(  2714),  INT16_C(  2438),  INT16_C(  4675), -INT16_C( 12980) } },
      { {  INT8_C(  44),  INT8_C( 108), -INT8_C(  64),  INT8_C(  56), -INT8_C(  77), -INT8_C(  45), -INT8_C( 120), -INT8_C(  51),
           INT8_C(  77), -INT8_C(  21), -INT8_C(  46),  INT8_C(  73), -INT8_C(  60), -INT8_C(  43),  INT8_C(  23), -INT8_C(  22) },
        {  INT8_C(  78), -INT8_C(  39), -INT8_C(  43), -INT8_C(  13), -INT8_C(  29), -INT8_C(  76), -INT8_C(  99), -INT8_C(  20),
          -INT8_C(  16), -INT8_C(  60), -INT8_C( 119), -INT8_C(  66), -INT8_C(   7),  INT8_C( 107), -INT8_C(  52), -INT8_C(  75) },
        {  INT16_C(  3432), -INT16_C(  4212),  INT16_C(  2752), -INT16_C(   728),  INT16_C(  2233),  INT16_C(  3420),  INT16_C( 11880),  INT16_C(  1020) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t b = simde_wasm_v128_load(test_vec[i].b);
      simde_v128_t r = simde_wasm_i16x8_extmul_low_i8x16(a, b);
      simde_test_wasm_i16x8_assert_equal(r, simde_wasm_v128_load(test_vec[i].r));
    }
    return 0;
  #else
    fputc('\n', stdout);
    for (int i = 0 ; i < 8 ; i++) {
      simde_v128_t
        a = simde_test_wasm_i8x16_random(),
        b = simde_test_wasm_i8x16_random(),
        r;

      r = simde_wasm_i16x8_extmul_low_i8x16(a, b);

      simde_test_wasm_i8x16_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_i8x16_write(3, b, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_wasm_i16x8_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_i32x4_extmul_low_i16x8(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      int16_t a[sizeof(simde_v128_t) / sizeof(int16_t)];
      int16_t b[sizeof(simde_v128_t) / sizeof(int16_t)];
      int32_t r[sizeof(simde_v128_t) / sizeof(int32_t)];
    } test_vec[] = {
      { { -INT16_C( 31543),  INT16_C( 11640), -INT16_C( 10756), -INT16_C( 16785),  INT16_C( 14656),  INT16_C( 11487), -INT16_C( 32047), -INT16_C(  8065) },
        { -INT16_C( 26119), -INT16_C( 32024),  INT16_C( 29506), -INT16_C( 30825),  INT16_C( 10589),  INT16_C( 22647), -INT16_C( 14873),  INT16_C( 19177) },
        {  INT32_C(   823871617), -INT32_C(   372759360), -INT32_C(   317366536),  INT32_C(   517397625) } },
      { { -INT16_C(  5318), -INT16_C( 22944),  INT16_C( 20009), -INT16_C( 19969), -INT16_C(  3866),  INT16_C( 18438), -INT16_C(     2), -INT16_C( 10194) },
        {  INT16_C(  2460),  INT16_C( 25846), -INT16_C( 16308),  INT16_C( 31706), -INT16_C( 16057), -INT16_C( 28858),  INT16_C( 25151), -INT16_C(  6379) },
        { -INT32_C(    13082280), -INT32_C(   593010624), -INT32_C(   326306772), -INT32_C(   633137114) } },
      { { -INT16_C( 19155),  INT16_C(  8958),  INT16_C(  5976),  INT16_C(  2954),  INT16_C(  5991), -INT16_C(  4824), -INT16_C( 11982), -INT16_C(  5388) },
        {  INT16_C( 15205),  INT16_C( 30833), -INT16_C( 20871),  INT16_C( 30433), -INT16_C( 14556), -INT16_C( 16686), -INT16_C( 23822), -INT16_C( 17742) },
        { -INT32_C(   291251775),  INT32_C(   276202014), -INT32_C(   124725096),  INT32_C(    89899082) } },
      { {  INT16_C(  6423),  INT16_C( 21981),  INT16_C( 15276),  INT16_C( 13906),  INT16_C( 13093), -INT16_C( 19998),  INT16_C( 26382),  INT16_C(  2424) },
        { -INT16_C( 26749),  INT16_C( 12122), -INT16_C(  5228), -INT16_C( 31361),  INT16_C(  5767),  INT16_C( 22132),  INT16_C( 10921), -INT16_C( 28535) },
        { -INT32_C(   171808827),  INT32_C(   266453682), -INT32_C(    79862928), -INT32_C(   436106066) } },
      { { -INT16_C( 19716), -INT16_C( 15100), -INT16_C( 21952),  INT16_C( 12979),  INT16_C( 28890), -INT16_C(  3986), -INT16_C( 19896),  INT16_C( 26556) },
        { -INT16_C(  7519), -INT16_C(  5505),  INT16_C( 14695),  INT16_C( 24257),  INT16_C(  4859),  INT16_C(  7834),  INT16_C( 15578),  INT16_C(   539) },
        {  INT32_C(   148244604),  INT32_C(    83125500), -INT32_C(   322584640),  INT32_C(   314831603) } },
      { {  INT16_C( 19632), -INT16_C(  6153),  INT16_C( 29852), -INT16_C( 23351),  INT16_C( 17469), -INT16_C( 13575),  INT16_C( 15225),  INT16_C( 27952) },
        { -INT16_C( 15636), -INT16_C(  8908),  INT16_C( 25587),  INT16_C( 13664),  INT16_C(  3949), -INT16_C(  4122), -INT16_C( 29096),  INT16_C(  9066) },
        { -INT32_C(   306965952),  INT32_C(    54810924),  INT32_C(   763823124), -INT32_C(   319068064) } },
      { {  INT16_C( 10906), -INT16_C( 15575),  INT16_C( 32422),  INT16_C( 24995), -INT16_C( 25561), -INT16_C( 23684), -INT16_C( 17807),  INT16_C(  9528) },
        { -INT16_C( 15210),  INT16_C( 26768), -INT16_C( 18655),  INT16_C(  2473),  INT16_C( 14857), -INT16_C(  2108), -INT16_C( 24474), -INT16_C( 20417) },
        { -INT32_C(   165880260), -INT32_C(   416911600), -INT32_C(   604832410),  INT32_C(    61812635) } },
      { { -INT16_C( 13831),  INT16_C(  3075), -INT16_C( 17642), -INT16_C( 31770),  INT16_C( 31794),  INT16_C(  8479),  INT16_C( 11790),  INT16_C( 11322) },
        { -INT16_C(  5414), -INT16_C(   730), -INT16_C(  1803),  INT16_C( 28648), -INT16_C(  1119),  INT16_C( 30345), -INT16_C( 27316), -INT16_C( 15875) },
        {  INT32_C(    74881034), -INT32_C(     2244750),  INT32_C(    31808526), -INT32_C(   910146960) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t b = simde_wasm_v128_load(test_vec[i].b);
      simde_v128_t r = simde_wasm_i32x4_extmul_low_i16x8(a, b);
      simde_test_wasm_i32x4_assert_equal(r, simde_wasm_v128_load(test_vec[i].r));
    }
    return 0;
  #else
    fputc('\n', stdout);
    for (int i = 0 ; i < 8 ; i++) {
      simde_v128_t
        a = simde_test_wasm_i16x8_random(),
        b = simde_test_wasm_i16x8_random(),
        r;

      r = simde_wasm_i32x4_extmul_low_i16x8(a, b);

      simde_test_wasm_i16x8_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_i16x8_write(3, b, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_wasm_i32x4_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_i64x2_extmul_low_i32x4(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      int32_t a[sizeof(simde_v128_t) / sizeof(int32_t)];
      int32_t b[sizeof(simde_v128_t) / sizeof(int32_t)];
      int64_t r[sizeof(simde_v128_t) / sizeof(int64_t)];
    } test_vec[] = {
      { {  INT32_C(   545782374),  INT32_C(  1211874699), -INT32_C(  1602773958),  INT32_C(   827205498) },
        { -INT32_C(   604994177),  INT32_C(   289431046), -INT32_C(   392775302), -INT32_C(   503978804) },
        { -INT64_C(  330195158179236198),  INT64_C(  350754161752505154) } },
      { {  INT32_C(  2107072792),  INT32_C(    74837434), -INT32_C(  1030453913),  INT32_C(  1225125627) },
        {  INT32_C(    66946286),  INT32_C(    57466244), -INT32_C(     8997671),  INT32_C(   383789713) },
        {  INT64_C(  141060697756050512),  INT64_C(    4300626242577896) } },
      { { -INT32_C(  1535137686), -INT32_C(  1605160316), -INT32_C(   540780182), -INT32_C(   800132803) },
        { -INT32_C(   536716104),  INT32_C(  1408863263),  INT32_C(  1521033863), -INT32_C(  1256710523) },
        {  INT64_C(  823933117933495344), -INT64_C( 2261451400437871108) } },
      { { -INT32_C(   571720410), -INT32_C(   747754052),  INT32_C(  1981767824),  INT32_C(  2064641510) },
        { -INT32_C(  1713453459),  INT32_C(   634093487),  INT32_C(   681215120), -INT32_C(  1979970576) },
        {  INT64_C(  979616314095398190), -INT64_C(  474145974251059324) } },
      { {  INT32_C(  1656241725), -INT32_C(   677012764),  INT32_C(  1270834706),  INT32_C(   284060377) },
        {  INT32_C(   509562025), -INT32_C(   375504203),  INT32_C(   429978749), -INT32_C(  1569434881) },
        {  INT64_C(  843957887280493125),  INT64_C(  254221138366647092) } },
      { { -INT32_C(   422994454), -INT32_C(   542709632), -INT32_C(  1023819624), -INT32_C(  1388432661) },
        {  INT32_C(  1691759345), -INT32_C(  1940510100),  INT32_C(  2130569366),  INT32_C(  1704830525) },
        { -INT64_C(  715604820437672630),  INT64_C( 1053133522263283200) } },
      { { -INT32_C(  1889154730), -INT32_C(      307736), -INT32_C(  1088693954), -INT32_C(  1620096487) },
        {  INT32_C(   607706392),  INT32_C(   650327390), -INT32_C(   430474071),  INT32_C(   418495876) },
        { -INT64_C( 1148051404898034160), -INT64_C(     200129149689040) } },
      { {  INT32_C(  2031473593), -INT32_C(  1651417187),  INT32_C(   144782099), -INT32_C(  1410111177) },
        {  INT32_C(   431404837),  INT32_C(   703879031),  INT32_C(  1119108167), -INT32_C(   185169299) },
        {  INT64_C(  876387534257969341), -INT64_C( 1162397929362305797) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t b = simde_wasm_v128_load(test_vec[i].b);
      simde_v128_t r = simde_wasm_i64x2_extmul_low_i32x4(a, b);
      simde_test_wasm_i64x2_assert_equal(r, simde_wasm_v128_load(test_vec[i].r));
    }
    return 0;
  #else
    fputc('\n', stdout);
    for (int i = 0 ; i < 8 ; i++) {
      simde_v128_t
        a = simde_test_wasm_i32x4_random(),
        b = simde_test_wasm_i32x4_random(),
        r;

      r = simde_wasm_i64x2_extmul_low_i32x4(a, b);

      simde_test_wasm_i32x4_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_i32x4_write(3, b, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_wasm_i64x2_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_u16x8_extmul_low_u8x16(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      uint8_t a[sizeof(simde_v128_t) / sizeof(uint8_t)];
      uint8_t b[sizeof(simde_v128_t) / sizeof(uint8_t)];
      uint16_t r[sizeof(simde_v128_t) / sizeof(uint16_t)];
    } test_vec[] = {
      { { UINT8_C(164), UINT8_C( 44), UINT8_C( 82), UINT8_C(199), UINT8_C(106), UINT8_C(223),    UINT8_MAX, UINT8_C(242),
          UINT8_C(224), UINT8_C( 44), UINT8_C( 12), UINT8_C(174), UINT8_C(136), UINT8_C(116), UINT8_C( 37), UINT8_C( 30) },
        { UINT8_C(126), UINT8_C(168), UINT8_C( 67), UINT8_C(120), UINT8_C( 66), UINT8_C(220), UINT8_C( 81), UINT8_C(231),
          UINT8_C(143), UINT8_C(225), UINT8_C( 13), UINT8_C(253), UINT8_C(106), UINT8_C(136), UINT8_C(229), UINT8_C(242) },
        { UINT16_C(20664), UINT16_C( 7392), UINT16_C( 5494), UINT16_C(23880), UINT16_C( 6996), UINT16_C(49060), UINT16_C(20655), UINT16_C(55902) } },
      { { UINT8_C( 79), UINT8_C(159), UINT8_C( 78), UINT8_C(100), UINT8_C( 86), UINT8_C(155), UINT8_C(201), UINT8_C(119),
          UINT8_C( 59), UINT8_C(219), UINT8_C(206), UINT8_C(114), UINT8_C( 72), UINT8_C( 91), UINT8_C(129), UINT8_C(136) },
        { UINT8_C(212), UINT8_C(116), UINT8_C(163), UINT8_C(  4), UINT8_C(219), UINT8_C(253), UINT8_C(114), UINT8_C(167),
          UINT8_C( 23), UINT8_C(  6), UINT8_C(197), UINT8_C( 44), UINT8_C(201), UINT8_C(101), UINT8_C(231), UINT8_C( 27) },
        { UINT16_C(16748), UINT16_C(18444), UINT16_C(12714), UINT16_C(  400), UINT16_C(18834), UINT16_C(39215), UINT16_C(22914), UINT16_C(19873) } },
      { { UINT8_C( 77), UINT8_C(  0), UINT8_C( 11), UINT8_C( 93), UINT8_C(185), UINT8_C( 81), UINT8_C(186), UINT8_C( 74),
          UINT8_C(251), UINT8_C(200), UINT8_C( 43), UINT8_C(214), UINT8_C( 60), UINT8_C( 63), UINT8_C(246), UINT8_C( 84) },
        { UINT8_C( 65), UINT8_C(199), UINT8_C(179), UINT8_C(118), UINT8_C( 73), UINT8_C( 81), UINT8_C( 21), UINT8_C(236),
          UINT8_C( 75), UINT8_C(248), UINT8_C( 94), UINT8_C(245), UINT8_C( 46), UINT8_C( 62), UINT8_C(231), UINT8_C(118) },
        { UINT16_C( 5005), UINT16_C(    0), UINT16_C( 1969), UINT16_C(10974), UINT16_C(13505), UINT16_C( 6561), UINT16_C( 3906), UINT16_C(17464) } },
      { { UINT8_C(213), UINT8_C(136), UINT8_C(123), UINT8_C( 91), UINT8_C( 19), UINT8_C( 76), UINT8_C(142), UINT8_C( 33),
          UINT8_C( 37), UINT8_C(233), UINT8_C(127), UINT8_C(130), UINT8_C(169), UINT8_C( 31), UINT8_C( 90), UINT8_C(187) },
        { UINT8_C( 61), UINT8_C(169), UINT8_C( 72), UINT8_C( 47), UINT8_C(252), UINT8_C( 36), UINT8_C(178), UINT8_C(201),
          UINT8_C(110), UINT8_C( 30), UINT8_C(219), UINT8_C( 85), UINT8_C(177), UINT8_C( 35), UINT8_C(141), UINT8_C( 86) },
        { UINT16_C(12993), UINT16_C(22984), UINT16_C( 8856), UINT16_C( 4277), UINT16_C( 4788), UINT16_C( 2736), UINT16_C(25276), UINT16_C( 6633) } },
      { { UINT8_C(193), UINT8_C( 12), UINT8_C(229), UINT8_C(206), UINT8_C(112), UINT8_C(117), UINT8_C(113), UINT8_C(190),
          UINT8_C( 49), UINT8_C( 17), UINT8_C(152), UINT8_C(218), UINT8_C(123), UINT8_C( 50), UINT8_C( 56), UINT8_C(177) },
        { UINT8_C(216), UINT8_C(178), UINT8_C(220), UINT8_C(120), UINT8_C(252), UINT8_C(140), UINT8_C( 85), UINT8_C(115),
          UINT8_C(214), UINT8_C(161), UINT8_C( 43), UINT8_C(152), UINT8_C(204), UINT8_C(120), UINT8_C(142), UINT8_C( 77) },
        { UINT16_C(41688), UINT16_C( 2136), UINT16_C(50380), UINT16_C(24720), UINT16_C(28224), UINT16_C(16380), UINT16_C( 9605), UINT16_C(21850) } },
      { { UINT8_C(215), UINT8_C(203), UINT8_C(226), UINT8_C( 15), UINT8_C(227), UINT8_C(142), UINT8_C(172), UINT8_C(254),
          UINT8_C(173), UINT8_C(151), UINT8_C( 15), UINT8_C(  1), UINT8_C( 29), UINT8_C(  0), UINT8_C(225), UINT8_C(215) },
        { UINT8_C(186), UINT8_C(151), UINT8_C( 69), UINT8_C( 98), UINT8_C( 35), UINT8_C( 99), UINT8_C( 13), UINT8_C( 20),
          UINT8_C( 80), UINT8_C(208), UINT8_C( 72), UINT8_C( 22), UINT8_C(236), UINT8_C(207), UINT8_C(117), UINT8_C(229) },
        { UINT16_C(39990), UINT16_C(30653), UINT16_C(15594), UINT16_C( 1470), UINT16_C( 7945), UINT16_C(14058), UINT16_C( 2236), UINT16_C( 5080) } },
      { { UINT8_C(131), UINT8_C(176), UINT8_C(217), UINT8_C(  1), UINT8_C(117), UINT8_C(227), UINT8_C(206), UINT8_C(108),
          UINT8_C( 94), UINT8_C(127), UINT8_C( 38), UINT8_C( 84), UINT8_C(200), UINT8_C(249), UINT8_C(240), UINT8_C(232) },
        { UINT8_C(170), UINT8_C( 44), UINT8_C(245), UINT8_C( 39), UINT8_C(198), UINT8_C(186), UINT8_C(213), UINT8_C( 24),
          UINT8_C(  4), UINT8_C( 12), UINT8_C(209), UINT8_C(114), UINT8_C(140), UINT8_C( 58), UINT8_C(243), UINT8_C(199) },
        { UINT16_C(22270), UINT16_C( 7744), UINT16_C(53165), UINT16_C(   39), UINT16_C(23166), UINT16_C(42222), UINT16_C(43878), UINT16_C( 2592) } },
      { { UINT8_C( 38), UINT8_C( 27), UINT8_C(244), UINT8_C( 44), UINT8_C(154), UINT8_C(137), UINT8_C( 88), UINT8_C( 73),
          UINT8_C(229), UINT8_C( 29), UINT8_C( 30), UINT8_C(107), UINT8_C( 89), UINT8_C(137), UINT8_C( 91), UINT8_C(169) },
        { UINT8_C(142), UINT8_C(238), UINT8_C(180), UINT8_C(  7), UINT8_C(241), UINT8_C(210),    UINT8_MAX, UINT8_C(253),
          UINT8_C(212), UINT8_C( 42), UINT8_C( 35), UINT8_C( 89), UINT8_C(191), UINT8_C( 40), UINT8_C(165), UINT8_C(110) },
        { UINT16_C( 5396), UINT16_C( 6426), UINT16_C(43920), UINT16_C(  308), UINT16_C(37114), UINT16_C(28770), UINT16_C(22440), UINT16_C(18469) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t b = simde_wasm_v128_load(test_vec[i].b);
      simde_v128_t r = simde_wasm_u16x8_extmul_low_u8x16(a, b);
      simde_test_wasm_u16x8_assert_equal(r, simde_wasm_v128_load(test_vec[i].r));
    }
    return 0;
  #else
    fputc('\n', stdout);
    for (int i = 0 ; i < 8 ; i++) {
      simde_v128_t
        a = simde_test_wasm_u8x16_random(),
        b = simde_test_wasm_u8x16_random(),
        r;

      r = simde_wasm_u16x8_extmul_low_u8x16(a, b);

      simde_test_wasm_u8x16_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_u8x16_write(3, b, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_wasm_u16x8_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_u32x4_extmul_low_u16x8(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      uint16_t a[sizeof(simde_v128_t) / sizeof(int16_t)];
      uint16_t b[sizeof(simde_v128_t) / sizeof(int16_t)];
      uint32_t r[sizeof(simde_v128_t) / sizeof(int32_t)];
    } test_vec[] = {
      { { UINT16_C(10701), UINT16_C(24485), UINT16_C( 3615), UINT16_C( 8937), UINT16_C(16865), UINT16_C(38936), UINT16_C(46497), UINT16_C(22266) },
        { UINT16_C( 2798), UINT16_C(42967), UINT16_C(38166), UINT16_C(40990), UINT16_C(23364), UINT16_C(49655), UINT16_C(46922), UINT16_C(21857) },
        { UINT32_C(  29941398), UINT32_C(1052046995), UINT32_C( 137970090), UINT32_C( 366327630) } },
      { { UINT16_C(30845), UINT16_C(52374), UINT16_C(46247), UINT16_C(55780), UINT16_C(55955), UINT16_C(58987), UINT16_C(11324), UINT16_C(38293) },
        { UINT16_C(58107), UINT16_C(61441), UINT16_C(35390), UINT16_C( 3957), UINT16_C(38874), UINT16_C(43388), UINT16_C(36403), UINT16_C(42755) },
        { UINT32_C(1792310415), UINT32_C(3217910934), UINT32_C(1636681330), UINT32_C( 220721460) } },
      { { UINT16_C(28912), UINT16_C(44078), UINT16_C( 9105), UINT16_C(15012), UINT16_C( 8191), UINT16_C(38533), UINT16_C(57311), UINT16_C(57452) },
        { UINT16_C( 5899), UINT16_C(28503), UINT16_C(19906), UINT16_C(54238), UINT16_C(32514), UINT16_C(22256), UINT16_C(12500), UINT16_C(27315) },
        { UINT32_C( 170551888), UINT32_C(1256355234), UINT32_C( 181244130), UINT32_C( 814220856) } },
      { { UINT16_C( 3036), UINT16_C(22917), UINT16_C(43640), UINT16_C(  797), UINT16_C(13968), UINT16_C( 9020), UINT16_C( 7727), UINT16_C(31045) },
        { UINT16_C( 3491), UINT16_C(13124), UINT16_C(34422), UINT16_C(50741), UINT16_C(50543), UINT16_C( 5567), UINT16_C(55665), UINT16_C(14005) },
        { UINT32_C(  10598676), UINT32_C( 300762708), UINT32_C(1502176080), UINT32_C(  40440577) } },
      { { UINT16_C( 6580), UINT16_C(61153), UINT16_C(59675), UINT16_C(31247), UINT16_C(22845), UINT16_C(47542), UINT16_C( 9490), UINT16_C(54772) },
        { UINT16_C(62453), UINT16_C(11945), UINT16_C(24932), UINT16_C(23878), UINT16_C( 5891), UINT16_C(30233), UINT16_C(53575), UINT16_C(23219) },
        { UINT32_C( 410940740), UINT32_C( 730472585), UINT32_C(1487817100), UINT32_C( 746115866) } },
      { { UINT16_C( 3052), UINT16_C(27314), UINT16_C( 5337), UINT16_C(30892), UINT16_C(33064), UINT16_C(15799), UINT16_C(15490), UINT16_C(35945) },
        { UINT16_C(19175), UINT16_C( 4516), UINT16_C(34041), UINT16_C(30773), UINT16_C(32812), UINT16_C( 3602), UINT16_C(17444), UINT16_C(37764) },
        { UINT32_C(  58522100), UINT32_C( 123350024), UINT32_C( 181676817), UINT32_C( 950639516) } },
      { { UINT16_C(13755), UINT16_C(18702), UINT16_C(41115), UINT16_C(63429), UINT16_C(35013), UINT16_C(50566), UINT16_C(18915), UINT16_C(51768) },
        { UINT16_C(61075), UINT16_C(44480), UINT16_C(34237), UINT16_C(45163), UINT16_C(21962), UINT16_C(46904), UINT16_C(39027), UINT16_C(14460) },
        { UINT32_C( 840086625), UINT32_C( 831864960), UINT32_C(1407654255), UINT32_C(2864643927) } },
      { { UINT16_C(39517), UINT16_C(42920), UINT16_C(33617), UINT16_C( 9591), UINT16_C(54138), UINT16_C(40003), UINT16_C(59602), UINT16_C(15783) },
        { UINT16_C(39497), UINT16_C(53431), UINT16_C(57984), UINT16_C(11009), UINT16_C(38547), UINT16_C(19124), UINT16_C(18136), UINT16_C(59446) },
        { UINT32_C(1560802949), UINT32_C(2293258520), UINT32_C(1949248128), UINT32_C( 105587319) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t b = simde_wasm_v128_load(test_vec[i].b);
      simde_v128_t r = simde_wasm_u32x4_extmul_low_u16x8(a, b);
      simde_test_wasm_u32x4_assert_equal(r, simde_wasm_v128_load(test_vec[i].r));
    }
    return 0;
  #else
    fputc('\n', stdout);
    for (int i = 0 ; i < 8 ; i++) {
      simde_v128_t
        a = simde_test_wasm_u8x16_random(),
        b = simde_test_wasm_u8x16_random(),
        r;

      r = simde_wasm_u32x4_extmul_low_u16x8(a, b);

      simde_test_wasm_u16x8_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_u16x8_write(3, b, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_wasm_u32x4_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_u64x2_extmul_low_u32x4(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      uint32_t a[sizeof(simde_v128_t) / sizeof(uint32_t)];
      uint32_t b[sizeof(simde_v128_t) / sizeof(uint32_t)];
      uint64_t r[sizeof(simde_v128_t) / sizeof(uint64_t)];
    } test_vec[] = {
      { { UINT32_C(2969181183), UINT32_C(1674062360), UINT32_C( 519696413), UINT32_C(3786206498) },
        { UINT32_C(3269105844), UINT32_C( 284973204), UINT32_C(2146722701), UINT32_C(3009737801) },
        { UINT64_C( 9706567557240133452), UINT64_C(  477062914425001440) } },
      { { UINT32_C(3014290668), UINT32_C(2835007267), UINT32_C(2729761759), UINT32_C(3923071865) },
        { UINT32_C(2636034261), UINT32_C(2369661596), UINT32_C(2831919973), UINT32_C(2664762768) },
        { UINT64_C( 7945773473460576348), UINT64_C( 6718007844990818132) } },
      { { UINT32_C(1905176761), UINT32_C(1736930468), UINT32_C( 810150745), UINT32_C(3513790411) },
        { UINT32_C(3926648438), UINT32_C( 993770767), UINT32_C(2185268550), UINT32_C( 502057429) },
        { UINT64_C( 7480959352694549318), UINT64_C( 1726110723410028956) } },
      { { UINT32_C(3400862528), UINT32_C(2774674426), UINT32_C(3226291852), UINT32_C(1580114507) },
        { UINT32_C(3906193731), UINT32_C(3386529818), UINT32_C(2946763643), UINT32_C(3322163767) },
        { UINT64_C(13284427886866411968), UINT64_C( 9396517678891034468) } },
      { { UINT32_C(2335804310), UINT32_C(1763424198), UINT32_C(2217471358), UINT32_C(3688648706) },
        { UINT32_C(2490166790), UINT32_C(2922738219), UINT32_C(1242495461), UINT32_C(3965199704) },
        { UINT64_C( 5816542320700864900), UINT64_C( 5154027299804023362) } },
      { { UINT32_C(4044573493), UINT32_C( 577129797), UINT32_C(1231320763), UINT32_C(1733155207) },
        { UINT32_C(3878281104), UINT32_C(1373700865), UINT32_C( 139902523), UINT32_C(2913764302) },
        { UINT64_C(15685992951641176272), UINT64_C(  792803701356174405) } },
      { { UINT32_C(2725845147), UINT32_C(2653921824), UINT32_C(1380573016), UINT32_C(3284586282) },
        { UINT32_C(2564389397), UINT32_C(3233702468), UINT32_C(3566445523), UINT32_C(2189421587) },
        { UINT64_C( 6990128392830706359), UINT64_C( 8581993552147861632) } },
      { { UINT32_C( 884383342), UINT32_C(1947894719), UINT32_C(3140710776), UINT32_C(2783325871) },
        { UINT32_C(1482481174), UINT32_C(3627915666), UINT32_C(4044460767), UINT32_C(1353709054) },
        { UINT64_C( 1311081655114203508), UINT64_C( 7066797766778767854) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t b = simde_wasm_v128_load(test_vec[i].b);
      simde_v128_t r = simde_wasm_u64x2_extmul_low_u32x4(a, b);
      simde_test_wasm_u64x2_assert_equal(r, simde_wasm_v128_load(test_vec[i].r));
    }
    return 0;
  #else
    fputc('\n', stdout);
    for (int i = 0 ; i < 8 ; i++) {
      simde_v128_t
        a = simde_test_wasm_u32x4_random(),
        b = simde_test_wasm_u32x4_random(),
        r;

      r = simde_wasm_u64x2_extmul_low_u32x4(a, b);

      simde_test_wasm_u32x4_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_u32x4_write(3, b, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_wasm_u64x2_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_i16x8_extmul_low_i8x16)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_i32x4_extmul_low_i16x8)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_i64x2_extmul_low_i32x4)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_u16x8_extmul_low_u8x16)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_u32x4_extmul_low_u16x8)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_u64x2_extmul_low_u32x4)
SIMDE_TEST_FUNC_LIST_END

#include "test-simd128-footer.h"
