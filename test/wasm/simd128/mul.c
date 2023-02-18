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

#define SIMDE_TEST_WASM_SIMD128_INSN mul
#include "../../../simde/wasm/simd128.h"
#include "test-simd128.h"

static int
test_simde_wasm_i16x8_mul(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      int16_t a[sizeof(simde_v128_t) / sizeof(int16_t)];
      int16_t b[sizeof(simde_v128_t) / sizeof(int16_t)];
      int16_t r[sizeof(simde_v128_t) / sizeof(int16_t)];
    } test_vec[] = {
      { {  INT16_C( 13646),  INT16_C( 26964), -INT16_C(  8154),  INT16_C(  5288),  INT16_C( 10460),  INT16_C( 10609), -INT16_C( 15125), -INT16_C( 11716) },
        { -INT16_C(  1518), -INT16_C( 19138),  INT16_C( 10031), -INT16_C( 22856), -INT16_C( 12570),  INT16_C(  7715),  INT16_C( 17555), -INT16_C( 21563) },
        { -INT16_C(  5252), -INT16_C(  6568), -INT16_C(  3846), -INT16_C( 14144), -INT16_C( 16984), -INT16_C(  6029),  INT16_C( 32497), -INT16_C(  9172) } },
      { { -INT16_C( 15354), -INT16_C( 20669), -INT16_C(  9379),  INT16_C( 15885),  INT16_C( 27933),  INT16_C( 28872),  INT16_C( 13373), -INT16_C( 31974) },
        {  INT16_C(  2798), -INT16_C( 31947), -INT16_C(  6776),  INT16_C(  4154), -INT16_C( 30695), -INT16_C(  9503), -INT16_C(  6092),  INT16_C( 27741) },
        {  INT16_C( 31124), -INT16_C( 28193), -INT16_C( 17816), -INT16_C(  8462),  INT16_C(  4053),  INT16_C( 28616), -INT16_C(  7068), -INT16_C( 26510) } },
      { { -INT16_C( 29667),  INT16_C(  4504),  INT16_C(  8861),  INT16_C( 24825),  INT16_C( 24113), -INT16_C( 24270), -INT16_C( 16622), -INT16_C( 32346) },
        { -INT16_C( 18614), -INT16_C(  1022),  INT16_C( 11264), -INT16_C( 20927), -INT16_C(   600), -INT16_C( 29553), -INT16_C( 10128), -INT16_C( 19965) },
        {  INT16_C( 15202), -INT16_C( 15568), -INT16_C(  1024), -INT16_C(  8903),  INT16_C( 15656),  INT16_C( 25326), -INT16_C( 14368), -INT16_C(  3854) } },
      { { -INT16_C( 14340), -INT16_C(  8126),  INT16_C( 21359),  INT16_C( 32277), -INT16_C(  9922), -INT16_C( 15808), -INT16_C( 23078), -INT16_C(  6169) },
        {  INT16_C( 15638),  INT16_C( 17109),  INT16_C( 14304),  INT16_C( 12404),  INT16_C( 29334),  INT16_C( 11629), -INT16_C(  4742), -INT16_C(  3703) },
        {  INT16_C( 15272), -INT16_C( 25878), -INT16_C(  9696),  INT16_C(  4484), -INT16_C(  6572), -INT16_C(  2752), -INT16_C(  9244), -INT16_C( 28257) } },
      { {  INT16_C(  3072), -INT16_C( 16592), -INT16_C( 30494),  INT16_C( 29696),  INT16_C( 30979), -INT16_C( 13798), -INT16_C( 20726), -INT16_C(  9809) },
        {  INT16_C(  5875), -INT16_C(  7861),  INT16_C( 29426), -INT16_C( 12079), -INT16_C(   978),  INT16_C( 29490),  INT16_C( 28281),  INT16_C(   613) },
        {  INT16_C( 25600),  INT16_C( 13072),  INT16_C(  2468), -INT16_C( 19456), -INT16_C( 19830),  INT16_C( 10004),  INT16_C(  1978),  INT16_C( 16395) } },
      { {  INT16_C( 27869),  INT16_C( 14603),  INT16_C(  9311), -INT16_C( 17416),  INT16_C(  6170), -INT16_C( 25826),  INT16_C( 24536), -INT16_C( 24277) },
        { -INT16_C( 11422),  INT16_C(  9707),  INT16_C(  2071), -INT16_C( 10970), -INT16_C( 18677), -INT16_C( 31634),  INT16_C(   508),  INT16_C(  2560) },
        { -INT16_C( 11366), -INT16_C(  3047),  INT16_C( 15497),  INT16_C( 16080), -INT16_C( 24802),  INT16_C(  7908),  INT16_C( 12448), -INT16_C( 20992) } },
      { {  INT16_C(  3972), -INT16_C( 11654),  INT16_C(  7172), -INT16_C( 22000), -INT16_C( 14397),  INT16_C( 27910), -INT16_C( 26518),  INT16_C( 22002) },
        {  INT16_C( 30561), -INT16_C(  4568), -INT16_C(  4771), -INT16_C( 26890), -INT16_C( 31070),  INT16_C( 11111),  INT16_C(  4594), -INT16_C( 10108) },
        {  INT16_C( 15620),  INT16_C( 20240), -INT16_C(  7820), -INT16_C( 13472),  INT16_C( 31590), -INT16_C(  8342),  INT16_C(  7732), -INT16_C( 32568) } },
      { {  INT16_C( 19087), -INT16_C( 26148), -INT16_C( 15497),  INT16_C( 14556),  INT16_C( 18728), -INT16_C( 14211), -INT16_C( 13931), -INT16_C(  1899) },
        {  INT16_C( 20636),  INT16_C(   477),  INT16_C( 26520), -INT16_C(   528),  INT16_C( 19528), -INT16_C( 30599), -INT16_C( 17375), -INT16_C( 12758) },
        {  INT16_C(  7972), -INT16_C( 20756), -INT16_C(  4184), -INT16_C( 17856),  INT16_C( 29504),  INT16_C( 11029),  INT16_C( 26677), -INT16_C( 20878) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t b = simde_wasm_v128_load(test_vec[i].b);
      simde_v128_t r = simde_wasm_i16x8_mul(a, b);
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

      r = simde_wasm_i16x8_mul(a, b);

      simde_test_wasm_i16x8_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_i16x8_write(3, b, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_wasm_i16x8_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_i32x4_mul(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      int32_t a[sizeof(simde_v128_t) / sizeof(int32_t)];
      int32_t b[sizeof(simde_v128_t) / sizeof(int32_t)];
      int32_t r[sizeof(simde_v128_t) / sizeof(int32_t)];
    } test_vec[] = {
      { { -INT32_C(  1480703527), -INT32_C(  1207033899),  INT32_C(  1391378561), -INT32_C(   771091943) },
        {  INT32_C(  1277080700), -INT32_C(  1169003022),  INT32_C(  1227077962),  INT32_C(   605436234) },
        {  INT32_C(   702707996), -INT32_C(   182335398), -INT32_C(  1664885174),  INT32_C(   118934586) } },
      { {  INT32_C(  1355535482),  INT32_C(  1963514356), -INT32_C(  1295518055), -INT32_C(  2071670520) },
        {  INT32_C(  2027004549),  INT32_C(  1496457999),  INT32_C(   664950236),  INT32_C(   155957647) },
        { -INT32_C(  1644914846),  INT32_C(  1996038476),  INT32_C(  1686812796), -INT32_C(  2036888712) } },
      { { -INT32_C(  2124867955), -INT32_C(  1980341777),  INT32_C(  1614528088),  INT32_C(   367378575) },
        {  INT32_C(  1921889890), -INT32_C(  1244938279), -INT32_C(  1545834988), -INT32_C(  1263720665) },
        {  INT32_C(   265019386),  INT32_C(  1752126615), -INT32_C(   871059744),  INT32_C(    49880777) } },
      { {  INT32_C(   758515261), -INT32_C(  1061802904),  INT32_C(  2048979434),  INT32_C(   344917425) },
        { -INT32_C(  1803150149), -INT32_C(   280342053), -INT32_C(   426563905), -INT32_C(  1952759730) },
        {  INT32_C(  1997748879),  INT32_C(  1844765944),  INT32_C(   668678550), -INT32_C(  1842676754) } },
      { { -INT32_C(  1363619514), -INT32_C(   395415811),  INT32_C(   291671904),  INT32_C(  1344663956) },
        { -INT32_C(   387667187), -INT32_C(  1126748419), -INT32_C(  1549571499), -INT32_C(   248627542) },
        {  INT32_C(   629432974), -INT32_C(  1886378487), -INT32_C(    13149472),  INT32_C(   642532424) } },
      { {  INT32_C(   211805967), -INT32_C(  1242296747),  INT32_C(   835147421),  INT32_C(  1417800775) },
        { -INT32_C(  1791203688), -INT32_C(   380562284),  INT32_C(   697103486),  INT32_C(  1092270898) },
        {  INT32_C(   394603240),  INT32_C(   672918820),  INT32_C(    25576774),  INT32_C(  1865286366) } },
      { { -INT32_C(   145835614),  INT32_C(  1689076423), -INT32_C(   527010663), -INT32_C(   130738336) },
        {  INT32_C(   311259517),  INT32_C(    83615621),  INT32_C(   103647443), -INT32_C(   448313533) },
        {  INT32_C(   597370394), -INT32_C(   800322973),  INT32_C(   517497371),  INT32_C(   184598048) } },
      { { -INT32_C(   925068032),  INT32_C(  1898744280),  INT32_C(  1582416637),  INT32_C(  1465288410) },
        {  INT32_C(  2104091896), -INT32_C(  1769904701),  INT32_C(   815574765), -INT32_C(   166337291) },
        {  INT32_C(   660887552), -INT32_C(   853067896),  INT32_C(   644184633),  INT32_C(   835401378) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t b = simde_wasm_v128_load(test_vec[i].b);
      simde_v128_t r = simde_wasm_i32x4_mul(a, b);
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

      r = simde_wasm_i32x4_mul(a, b);

      simde_test_wasm_i32x4_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_i32x4_write(3, b, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_wasm_i32x4_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_i64x2_mul(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      int64_t a[sizeof(simde_v128_t) / sizeof(int64_t)];
      int64_t b[sizeof(simde_v128_t) / sizeof(int64_t)];
      int64_t r[sizeof(simde_v128_t) / sizeof(int64_t)];
    } test_vec[] = {
      { {  INT64_C( 8701775245406564729), -INT64_C( 7863797757615139667) },
        { -INT64_C( 7319878068564113391),  INT64_C( 7218109029104092992) },
        { -INT64_C( 3948472860558225143), -INT64_C(   40585877820807616) } },
      { { -INT64_C( 9096012494182880816), -INT64_C( 2829977147797890420) },
        { -INT64_C( 7244858742260578002), -INT64_C( 1194021120239452386) },
        { -INT64_C( 8886856116865969312),  INT64_C( 3783866764086644840) } },
      { {  INT64_C( 2898909259242284005),  INT64_C( 6285064828286354073) },
        {  INT64_C( 1929978241371858386),  INT64_C( 8860147911160469992) },
        { -INT64_C( 3053217821704303910), -INT64_C(  838942209636250712) } },
      { { -INT64_C( 4073103242786754380), -INT64_C( 6615398823694382927) },
        { -INT64_C(  766286979820067770), -INT64_C( 4160498042753285837) },
        {  INT64_C( 8818642344350818616), -INT64_C( 3260399464698074045) } },
      { { -INT64_C( 7631471729007167967), -INT64_C( 1815335890504892584) },
        {  INT64_C( 7784620635114282758),  INT64_C( 1576391759875015432) },
        { -INT64_C(  454601471460883514),  INT64_C(   45100439877714624) } },
      { { -INT64_C( 2276432688843458579), -INT64_C( 9204838143343535941) },
        { -INT64_C(  424011323239339145), -INT64_C( 5284705016126090594) },
        { -INT64_C( 8039252896340160981),  INT64_C( 7683012102285011306) } },
      { {  INT64_C( 4923544390297259500), -INT64_C( 5925363590811918902) },
        { -INT64_C( 8054551653193459892),  INT64_C( 3192432288644418765) },
        { -INT64_C( 6389317198584523248), -INT64_C( 5883859156404530494) } },
      { { -INT64_C( 7951118579403794727),  INT64_C( 8373204531551749969) },
        { -INT64_C( 2705561605760708112),  INT64_C( 4369545393582741046) },
        { -INT64_C( 7626845000615308176),  INT64_C( 6111467790039220502) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t b = simde_wasm_v128_load(test_vec[i].b);
      simde_v128_t r = simde_wasm_i64x2_mul(a, b);
      simde_test_wasm_i64x2_assert_equal(r, simde_wasm_v128_load(test_vec[i].r));
    }
    return 0;
  #else
    fputc('\n', stdout);
    for (int i = 0 ; i < 8 ; i++) {
      simde_v128_t
        a = simde_test_wasm_i64x2_random(),
        b = simde_test_wasm_i64x2_random(),
        r;

      r = simde_wasm_i64x2_mul(a, b);

      simde_test_wasm_i64x2_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_i64x2_write(3, b, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_wasm_i64x2_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_f32x4_mul(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      simde_float32 a[sizeof(simde_v128_t) / sizeof(simde_float32)];
      simde_float32 b[sizeof(simde_v128_t) / sizeof(simde_float32)];
      simde_float32 r[sizeof(simde_v128_t) / sizeof(simde_float32)];
    } test_vec[] = {
      #if !defined(SIMDE_FAST_MATH)
      { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   169.34),            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -186.51) },
        { SIMDE_FLOAT32_C(  -447.49),            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -186.51) },
        {            SIMDE_MATH_NANF,            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C( 34785.98) } },
      #endif
      { { SIMDE_FLOAT32_C(  -886.04), SIMDE_FLOAT32_C(   381.13), SIMDE_FLOAT32_C(  -966.94), SIMDE_FLOAT32_C(  -786.23) },
        { SIMDE_FLOAT32_C(   749.38), SIMDE_FLOAT32_C(  -563.44), SIMDE_FLOAT32_C(  -119.23), SIMDE_FLOAT32_C(   323.86) },
        { SIMDE_FLOAT32_C(-663980.62), SIMDE_FLOAT32_C(-214743.89), SIMDE_FLOAT32_C(115288.26), SIMDE_FLOAT32_C(-254628.44) } },
      { { SIMDE_FLOAT32_C(  -542.43), SIMDE_FLOAT32_C(   534.49), SIMDE_FLOAT32_C(   821.37), SIMDE_FLOAT32_C(   948.82) },
        { SIMDE_FLOAT32_C(  -538.78), SIMDE_FLOAT32_C(   245.78), SIMDE_FLOAT32_C(   189.61), SIMDE_FLOAT32_C(  -366.25) },
        { SIMDE_FLOAT32_C(292250.44), SIMDE_FLOAT32_C(131366.95), SIMDE_FLOAT32_C(155739.97), SIMDE_FLOAT32_C(-347505.31) } },
      { { SIMDE_FLOAT32_C(   828.70), SIMDE_FLOAT32_C(   373.71), SIMDE_FLOAT32_C(  -461.67), SIMDE_FLOAT32_C(  -927.31) },
        { SIMDE_FLOAT32_C(  -177.25), SIMDE_FLOAT32_C(   161.65), SIMDE_FLOAT32_C(   124.87), SIMDE_FLOAT32_C(  -459.47) },
        { SIMDE_FLOAT32_C(-146887.08), SIMDE_FLOAT32_C( 60410.22), SIMDE_FLOAT32_C(-57648.73), SIMDE_FLOAT32_C(426071.12) } },
      { { SIMDE_FLOAT32_C(  -669.02), SIMDE_FLOAT32_C(   507.24), SIMDE_FLOAT32_C(   831.02), SIMDE_FLOAT32_C(  -116.51) },
        { SIMDE_FLOAT32_C(   154.53), SIMDE_FLOAT32_C(  -241.53), SIMDE_FLOAT32_C(   929.54), SIMDE_FLOAT32_C(   268.49) },
        { SIMDE_FLOAT32_C(-103383.66), SIMDE_FLOAT32_C(-122513.67), SIMDE_FLOAT32_C(772466.31), SIMDE_FLOAT32_C(-31281.77) } },
      { { SIMDE_FLOAT32_C(  -860.39), SIMDE_FLOAT32_C(   962.60), SIMDE_FLOAT32_C(   482.26), SIMDE_FLOAT32_C(   888.98) },
        { SIMDE_FLOAT32_C(  -600.84), SIMDE_FLOAT32_C(  -636.97), SIMDE_FLOAT32_C(   212.84), SIMDE_FLOAT32_C(  -143.27) },
        { SIMDE_FLOAT32_C(516956.75), SIMDE_FLOAT32_C(-613147.25), SIMDE_FLOAT32_C(102644.22), SIMDE_FLOAT32_C(-127364.16) } },
      { { SIMDE_FLOAT32_C(   897.53), SIMDE_FLOAT32_C(    34.21), SIMDE_FLOAT32_C(  -194.45), SIMDE_FLOAT32_C(  -641.25) },
        { SIMDE_FLOAT32_C(  -720.01), SIMDE_FLOAT32_C(   995.16), SIMDE_FLOAT32_C(    -7.50), SIMDE_FLOAT32_C(  -891.31) },
        { SIMDE_FLOAT32_C(-646230.62), SIMDE_FLOAT32_C( 34044.42), SIMDE_FLOAT32_C(  1458.38), SIMDE_FLOAT32_C(571552.56) } },
      { { SIMDE_FLOAT32_C(   368.86), SIMDE_FLOAT32_C(   530.83), SIMDE_FLOAT32_C(  -818.62), SIMDE_FLOAT32_C(  -808.39) },
        { SIMDE_FLOAT32_C(  -307.52), SIMDE_FLOAT32_C(   306.26), SIMDE_FLOAT32_C(  -267.85), SIMDE_FLOAT32_C(    23.46) },
        { SIMDE_FLOAT32_C(-113431.82), SIMDE_FLOAT32_C(162572.00), SIMDE_FLOAT32_C(219267.38), SIMDE_FLOAT32_C(-18964.83) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t b = simde_wasm_v128_load(test_vec[i].b);
      simde_v128_t r = simde_wasm_f32x4_mul(a, b);
      simde_test_wasm_f32x4_assert_equal(r, simde_wasm_v128_load(test_vec[i].r), 1);
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

      r = simde_wasm_f32x4_mul(a, b);

      simde_test_wasm_f32x4_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_f32x4_write(3, b, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_wasm_f32x4_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_f64x2_mul(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      simde_float64 a[sizeof(simde_v128_t) / sizeof(simde_float64)];
      simde_float64 b[sizeof(simde_v128_t) / sizeof(simde_float64)];
      simde_float64 r[sizeof(simde_v128_t) / sizeof(simde_float64)];
    } test_vec[] = {
      #if !defined(SIMDE_FAST_MATH)
      { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   906.95) },
        { SIMDE_FLOAT64_C(   968.02),             SIMDE_MATH_NAN },
        {             SIMDE_MATH_NAN,             SIMDE_MATH_NAN } },
      { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   236.51) },
        {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   799.08) },
        {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(188990.41) } },
      #endif
      { { SIMDE_FLOAT64_C(  -281.23), SIMDE_FLOAT64_C(   350.23) },
        { SIMDE_FLOAT64_C(  -801.76), SIMDE_FLOAT64_C(    81.81) },
        { SIMDE_FLOAT64_C(225478.96), SIMDE_FLOAT64_C( 28652.32) } },
      { { SIMDE_FLOAT64_C(  -436.93), SIMDE_FLOAT64_C(    54.97) },
        { SIMDE_FLOAT64_C(   -20.67), SIMDE_FLOAT64_C(   597.28) },
        { SIMDE_FLOAT64_C(  9031.34), SIMDE_FLOAT64_C( 32832.48) } },
      { { SIMDE_FLOAT64_C(   860.52), SIMDE_FLOAT64_C(   338.09) },
        { SIMDE_FLOAT64_C(   877.26), SIMDE_FLOAT64_C(   855.68) },
        { SIMDE_FLOAT64_C(754899.78), SIMDE_FLOAT64_C(289296.85) } },
      { { SIMDE_FLOAT64_C(  -669.42), SIMDE_FLOAT64_C(   985.95) },
        { SIMDE_FLOAT64_C(   224.54), SIMDE_FLOAT64_C(   861.42) },
        { SIMDE_FLOAT64_C(-150311.57), SIMDE_FLOAT64_C(849317.05) } },
      { { SIMDE_FLOAT64_C(  -832.67), SIMDE_FLOAT64_C(   416.15) },
        { SIMDE_FLOAT64_C(  -446.10), SIMDE_FLOAT64_C(   473.59) },
        { SIMDE_FLOAT64_C(371454.09), SIMDE_FLOAT64_C(197084.48) } },
      { { SIMDE_FLOAT64_C(  -851.70), SIMDE_FLOAT64_C(   577.36) },
        { SIMDE_FLOAT64_C(  -712.92), SIMDE_FLOAT64_C(  -288.53) },
        { SIMDE_FLOAT64_C(607193.96), SIMDE_FLOAT64_C(-166585.68) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t b = simde_wasm_v128_load(test_vec[i].b);
      simde_v128_t r = simde_wasm_f64x2_mul(a, b);
      simde_test_wasm_f64x2_assert_equal(r, simde_wasm_v128_load(test_vec[i].r), 1);
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

      r = simde_wasm_f64x2_mul(a, b);

      simde_test_wasm_f64x2_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_f64x2_write(3, b, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_wasm_f64x2_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_i16x8_mul)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_i32x4_mul)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_i64x2_mul)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_f32x4_mul)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_f64x2_mul)
SIMDE_TEST_FUNC_LIST_END

#include "test-simd128-footer.h"
