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

#define SIMDE_TEST_WASM_SIMD128_INSN shuffle
#include "../../../simde/wasm/simd128.h"
#include "test-simd128.h"

static int
test_simde_wasm_i8x16_shuffle(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    simde_v128_t a, b, r;
    // int8_t v[sizeof(simde_v128_t) / sizeof(int8_t)];
    simde_v128_t e;

    a = simde_wasm_i8x16_const(-113,   78,   92,  -55,  -88,   65,  -81,  -53,   82,   82,  -62,  -29, -122,  109,   42,   28);
    b = simde_wasm_i8x16_const( -11,  -42,    7,  -95,   28,   18,   30,   99,  -27,  -27,   97,  -43,    6,   56,   51,  125);
    r = simde_wasm_i8x16_shuffle(a, b, 23, 18, 11, 29, 11,  1,  6, 28, 26,  8, 22,  8, 10, 29, 18, 16);
    e = simde_wasm_i8x16_const(  99,    7,  -29,   56,  -29,   78,  -81,    6,   97,   82,   30,   82,  -62,   56,    7,  -11);
    simde_test_wasm_i8x16_assert_equal(r, e);

    a = simde_wasm_i8x16_const(  82,  -24,  -76,  110,  -63,    1,   90,  -26,   83,   83,   -5,  -15,  105,  -24,   12,  -87);
    b = simde_wasm_i8x16_const( -37,  -91,   93,  -54, -123,   98,   49,  -89,  -82,  -82,    3,  -42,   33,  -11,   98, -111);
    r = simde_wasm_i8x16_shuffle(a, b, 16, 20,  1,  8, 17, 16,  1, 16, 28,  1, 12,  6,  8, 28, 31, 22);
    e = simde_wasm_i8x16_const( -37, -123,  -24,   83,  -91,  -37,  -24,  -37,   33,  -24,  105,   90,   83,   33, -111,   49);
    simde_test_wasm_i8x16_assert_equal(r, e);

    a = simde_wasm_i8x16_const(  26,  -91, -121, -115,  127,  -74,  -84,  -17, -116, -116,   43,  -15,  -86,  -35,  -17,   70);
    b = simde_wasm_i8x16_const(  -3,   15,  -81,  119, -100, -119,  -42,  106, -127, -127,   56,  106, -103,   56,  -52,  109);
    r = simde_wasm_i8x16_shuffle(a, b, 22,  5, 29, 19, 16, 19,  8,  4, 21,  7, 23, 13,  9,  4,  8, 22);
    e = simde_wasm_i8x16_const( -42,  -74,   56,  119,   -3,  119, -116,  127, -119,  -17,  106,  -35, -116,  127, -116,  -42);
    simde_test_wasm_i8x16_assert_equal(r, e);

    a = simde_wasm_i8x16_const(-124,  -29, -128, -110,  112,  -79,  -84,   63,  111,  111,  127, -113,  -38,  -15,  122,   25);
    b = simde_wasm_i8x16_const( -92,  -82,  -70, -111,  126,  -27,    3,  110,  -67,  -67,  -32, -116,  -51,  -49,    6,  -86);
    r = simde_wasm_i8x16_shuffle(a, b, 25, 16,  3, 22, 23, 31, 31,  7, 11, 18,  3,  4, 15, 27,  4, 16);
    e = simde_wasm_i8x16_const( -67,  -92, -110,    3,  110,  -86,  -86,   63, -113,  -70, -110,  112,   25, -116,  112,  -92);
    simde_test_wasm_i8x16_assert_equal(r, e);

    a = simde_wasm_i8x16_const(  29,   98,  -53,  -31, -106,  -33,   91,  -38,  -39,  -39,   17,   23,  -23, -115,  -57,   96);
    b = simde_wasm_i8x16_const( -85,  -45,  -38,  -64,  118,  -54,  -23,   19,    8,    8,  -20,   76,  -28,   -5,   90,  -63);
    r = simde_wasm_i8x16_shuffle(a, b, 10,  1, 16, 31, 18, 20, 10,  0, 17, 29, 18, 25, 25, 10,  7, 18);
    e = simde_wasm_i8x16_const(  17,   98,  -85,  -63,  -38,  118,   17,   29,  -45,   -5,  -38,    8,    8,   17,  -38,  -38);
    simde_test_wasm_i8x16_assert_equal(r, e);

    a = simde_wasm_i8x16_const( -78,  -23,  -32,  -83,  -87,  -95, -103,  -39,   77,   77,   19,  120,  -85,   -1, -111, -101);
    b = simde_wasm_i8x16_const(  52,  -53,   73,  -66,   84,   34,   -6,   84,   43,   43,   79,  123, -101,  -95,   83,    1);
    r = simde_wasm_i8x16_shuffle(a, b, 29, 12, 16, 18,  7, 27,  9, 27, 13, 10,  7,  7, 26, 14, 27, 29);
    e = simde_wasm_i8x16_const( -95,  -85,   52,   73,  -39,  123,   77,  123,   -1,   19,  -39,  -39,   79, -111,  123,  -95);
    simde_test_wasm_i8x16_assert_equal(r, e);

    a = simde_wasm_i8x16_const(  85,   65,   55,  -88,    6,  107,  -33,   11,  -98,  -98,  -69,  -36,  -76,   48,  -31,  -95);
    b = simde_wasm_i8x16_const( -94,   -2,  -50,  -11,  -32,   72,   58,  118,  -19,  -19,   20,  123,  -24,  123,   64,   -4);
    r = simde_wasm_i8x16_shuffle(a, b,  3, 12,  8, 26, 27,  7,  8, 12, 29,  8, 27, 19,  9, 12,  9,  5);
    e = simde_wasm_i8x16_const( -88,  -76,  -98,   20,  123,   11,  -98,  -76,  123,  -98,  123,  -11,  -98,  -76,  -98,  107);
    simde_test_wasm_i8x16_assert_equal(r, e);

    a = simde_wasm_i8x16_const( -83,   37,  106,   12,  -74,  -86,   68,   75, -101, -101,   73,   89,   18,   88,  -42,   49);
    b = simde_wasm_i8x16_const(  68,  122,   91,   -8,  -22,  -75,   92,  -11,  106,  106,   46,  -95,    3,  -45,   90,  -25);
    r = simde_wasm_i8x16_shuffle(a, b, 16, 20, 12, 21,  6,  3, 17, 11, 24,  3,  2,  1, 20, 10, 19,  3);
    e = simde_wasm_i8x16_const(  68,  -22,   18,  -75,   68,   12,  122,   89,  106,   12,  106,   37,  -22,   73,   -8,   12);
    simde_test_wasm_i8x16_assert_equal(r, e);

    return 0;
  #else
    fputc('\n', stdout);
    for (int i = 0 ; i < 8 ; i++) {
      int8_t a[sizeof(simde_v128_t) / sizeof(int8_t)];
      int8_t b[sizeof(simde_v128_t) / sizeof(int8_t)];

      simde_test_codegen_random_memory(sizeof(a), HEDLEY_REINTERPRET_CAST(uint8_t*, a));
      simde_test_codegen_random_memory(sizeof(b), HEDLEY_REINTERPRET_CAST(uint8_t*, b));

      printf("    a = simde_wasm_i8x16_const(%4" PRId8 ", %4" PRId8 ", %4" PRId8 ", %4" PRId8 ", %4" PRId8 ", %4" PRId8 ", %4" PRId8 ", %4" PRId8 ", %4" PRId8 ", %4" PRId8 ", %4" PRId8 ", %4" PRId8 ", %4" PRId8 ", %4" PRId8 ", %4" PRId8 ", %4" PRId8 ");\n",
             a[0], a[1], a[ 2], a[ 3], a[ 4], a[ 5], a[ 6], a[ 7],
             a[8], a[8], a[10], a[11], a[12], a[13], a[14], a[15]);
      printf("    b = simde_wasm_i8x16_const(%4" PRId8 ", %4" PRId8 ", %4" PRId8 ", %4" PRId8 ", %4" PRId8 ", %4" PRId8 ", %4" PRId8 ", %4" PRId8 ", %4" PRId8 ", %4" PRId8 ", %4" PRId8 ", %4" PRId8 ", %4" PRId8 ", %4" PRId8 ", %4" PRId8 ", %4" PRId8 ");\n",
             b[0], b[1], b[ 2], b[ 3], b[ 4], b[ 5], b[ 6], b[ 7],
             b[8], b[8], b[10], b[11], b[12], b[13], b[14], b[15]);
      printf("    r = simde_wasm_i8x16_shuffle(a, b, %2d, %2d, %2d, %2d, %2d, %2d, %2d, %2d, %2d, %2d, %2d, %2d, %2d, %2d, %2d, %2d);\n",
             simde_test_codegen_random_i8() & 31,
             simde_test_codegen_random_i8() & 31,
             simde_test_codegen_random_i8() & 31,
             simde_test_codegen_random_i8() & 31,
             simde_test_codegen_random_i8() & 31,
             simde_test_codegen_random_i8() & 31,
             simde_test_codegen_random_i8() & 31,
             simde_test_codegen_random_i8() & 31,
             simde_test_codegen_random_i8() & 31,
             simde_test_codegen_random_i8() & 31,
             simde_test_codegen_random_i8() & 31,
             simde_test_codegen_random_i8() & 31,
             simde_test_codegen_random_i8() & 31,
             simde_test_codegen_random_i8() & 31,
             simde_test_codegen_random_i8() & 31,
             simde_test_codegen_random_i8() & 31);
      printf("    \n");
      printf("    simde_wasm_v128_store(v, r);\n");
      printf("    printf(\"    e = simde_wasm_i8x16_const(%%4" PRId8 ", %%4" PRId8 ", %%4" PRId8 ", %%4" PRId8 ", %%4" PRId8 ", %%4" PRId8 ", %%4" PRId8 ", %%4" PRId8 ", %%4" PRId8 ", %%4" PRId8 ", %%4" PRId8 ", %%4" PRId8 ", %%4" PRId8 ", %%4" PRId8 ", %%4" PRId8 ", %%4" PRId8 ");\\n\",\n"
             "           v[0], v[1], v[2], v[3], v[4], v[5], v[6], v[7], v[8], v[9], v[10], v[11], v[12], v[13], v[14], v[15]);\n");
      printf("    // simde_test_wasm_i8x16_assert_equal(r, e);\n");
    }
    return 1;
  #endif
}

static int
test_simde_wasm_i16x8_shuffle(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    simde_v128_t a, b, r;
    // int16_t v[sizeof(simde_v128_t) / sizeof(int16_t)];
    simde_v128_t e;

    a = simde_wasm_i16x8_const(   8837,   32072,  -22063,  -30417,   31216,   28063,  -31614,   23960);
    b = simde_wasm_i16x8_const(   6872,  -28440,  -32577,  -14000,    6506,   23302,    3278,   21382);
    r = simde_wasm_i16x8_shuffle(a, b, 14,  0,  7,  9,  9,  5, 12,  8);
    e = simde_wasm_i16x8_const(   3278,    8837,   23960,  -28440,  -28440,   28063,    6506,    6872);
    simde_test_wasm_i16x8_assert_equal(r, e);

    a = simde_wasm_i16x8_const(  16519,   17941,   26048,   11024,    5759,   19846,    3106,   20640);
    b = simde_wasm_i16x8_const(  29147,   21072,   -9871,   -5446,  -28927,  -21018,   16124,  -31694);
    r = simde_wasm_i16x8_shuffle(a, b, 15, 10, 13, 10,  0,  9, 13,  3);
    e = simde_wasm_i16x8_const( -31694,   -9871,  -21018,   -9871,   16519,   21072,  -21018,   11024);
    simde_test_wasm_i16x8_assert_equal(r, e);

    a = simde_wasm_i16x8_const( -19574,   -1238,   -6772,  -29210,  -13196,   28986,   27914,  -30219);
    b = simde_wasm_i16x8_const( -16460,   25033,   13210,  -30067,    1572,    8605,      32,  -21767);
    r = simde_wasm_i16x8_shuffle(a, b,  3,  6,  8, 12,  8, 14,  3, 12);
    e = simde_wasm_i16x8_const( -29210,   27914,  -16460,    1572,  -16460,      32,  -29210,    1572);
    simde_test_wasm_i16x8_assert_equal(r, e);

    a = simde_wasm_i16x8_const( -19038,   15497,    6120,    3271,   25629,   15661,    9828,    6120);
    b = simde_wasm_i16x8_const( -29110,   21078,    8730,   29391,  -17112,  -25388,  -16224,   17348);
    r = simde_wasm_i16x8_shuffle(a, b,  5, 15,  4, 10, 10, 15, 14,  5);
    e = simde_wasm_i16x8_const(  15661,   17348,   25629,    8730,    8730,   17348,  -16224,   15661);
    simde_test_wasm_i16x8_assert_equal(r, e);

    a = simde_wasm_i16x8_const(  31541,   20315,   10909,  -14655,  -26904,  -30622,    9814,  -13109);
    b = simde_wasm_i16x8_const(  19315,  -10198,  -27503,   15450,    6444,   -5302,   28865,   -2317);
    r = simde_wasm_i16x8_shuffle(a, b, 11,  6,  9, 15, 13,  9,  7,  0);
    e = simde_wasm_i16x8_const(  15450,    9814,  -10198,   -2317,   -5302,  -10198,  -13109,   31541);
    simde_test_wasm_i16x8_assert_equal(r, e);

    a = simde_wasm_i16x8_const(  -5632,  -28382,   31870,  -21555,    6294,   22422,  -30328,   29517);
    b = simde_wasm_i16x8_const( -27688,   20988,   19355,   14514,  -25604,  -11476,   -5040,   20510);
    r = simde_wasm_i16x8_shuffle(a, b,  6,  2, 13,  0,  7, 10, 15,  3);
    e = simde_wasm_i16x8_const( -30328,   31870,  -11476,   -5632,   29517,   19355,   20510,  -21555);
    simde_test_wasm_i16x8_assert_equal(r, e);

    a = simde_wasm_i16x8_const( -16501,    9800,   -1525,    1886,  -29802,   -6437,   -1673,   20023);
    b = simde_wasm_i16x8_const(   6457,   -2397,  -23608,  -28599,   -3271,   22751,  -23829,   30288);
    r = simde_wasm_i16x8_shuffle(a, b,  2, 12,  3,  4,  5, 15,  8, 11);
    e = simde_wasm_i16x8_const(  -1525,   -3271,    1886,  -29802,   -6437,   30288,    6457,  -28599);
    simde_test_wasm_i16x8_assert_equal(r, e);

    a = simde_wasm_i16x8_const(  -4513,   10360,  -15727,  -13640,  -26699,  -24542,   29242,  -25578);
    b = simde_wasm_i16x8_const( -19957,  -25079,   32173,   12999,  -10547,    5423,   31261,   31895);
    r = simde_wasm_i16x8_shuffle(a, b,  8,  4,  2,  3,  4,  8,  8, 10);
    e = simde_wasm_i16x8_const( -19957,  -26699,  -15727,  -13640,  -26699,  -19957,  -19957,   32173);
    simde_test_wasm_i16x8_assert_equal(r, e);

    return 0;
  #else
    fputc('\n', stdout);
    for (int i = 0 ; i < 8 ; i++) {
      int16_t a[sizeof(simde_v128_t) / sizeof(int16_t)];
      int16_t b[sizeof(simde_v128_t) / sizeof(int16_t)];

      simde_test_codegen_random_memory(sizeof(a), HEDLEY_REINTERPRET_CAST(uint8_t*, a));
      simde_test_codegen_random_memory(sizeof(b), HEDLEY_REINTERPRET_CAST(uint8_t*, b));

      printf("    a = simde_wasm_i16x8_const(%7" PRId16 ", %7" PRId16 ", %7" PRId16 ", %7" PRId16 ", %7" PRId16 ", %7" PRId16 ", %7" PRId16 ", %7" PRId16 ");\n",
             a[0], a[1], a[ 2], a[ 3], a[ 4], a[ 5], a[ 6], a[ 7]);
      printf("    b = simde_wasm_i16x8_const(%7" PRId16 ", %7" PRId16 ", %7" PRId16 ", %7" PRId16 ", %7" PRId16 ", %7" PRId16 ", %7" PRId16 ", %7" PRId16 ");\n",
             b[0], b[1], b[ 2], b[ 3], b[ 4], b[ 5], b[ 6], b[ 7]);
      printf("    r = simde_wasm_i16x8_shuffle(a, b, %2d, %2d, %2d, %2d, %2d, %2d, %2d, %2d);\n",
             simde_test_codegen_random_i16() & 15,
             simde_test_codegen_random_i16() & 15,
             simde_test_codegen_random_i16() & 15,
             simde_test_codegen_random_i16() & 15,
             simde_test_codegen_random_i16() & 15,
             simde_test_codegen_random_i16() & 15,
             simde_test_codegen_random_i16() & 15,
             simde_test_codegen_random_i16() & 15);
      printf("    \n");
      printf("    simde_wasm_v128_store(v, r);\n");
      printf("    printf(\"    e = simde_wasm_i16x8_const(%%7" PRId16 ", %%7" PRId16 ", %%7" PRId16 ", %%7" PRId16 ", %%7" PRId16 ", %%7" PRId16 ", %%7" PRId16 ", %%7" PRId16 ");\\n\", "
                         "v[0], v[1], v[2], v[3], v[4], v[5], v[6], v[7]);\n");
      printf("    // simde_test_wasm_i16x8_assert_equal(r, e);\n\n");
    }
    return 1;
  #endif
}

static int
test_simde_wasm_i32x4_shuffle(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    simde_v128_t a, b, r;
    // int32_t v[sizeof(simde_v128_t) / sizeof(int32_t)];
    simde_v128_t e;

    a = simde_wasm_i32x4_const(  720762535,  1889980452,  -350468572, -2046105980);
    b = simde_wasm_i32x4_const(-1395134100,  -569286895,   491332620,   -48826688);
    r = simde_wasm_i32x4_shuffle(a, b,  6,  6,  4,  0);
    e = simde_wasm_i32x4_const(  491332620,   491332620, -1395134100,   720762535);
    simde_test_wasm_i32x4_assert_equal(r, e);

    a = simde_wasm_i32x4_const(  505801296, -1225630671, -2103037400, -1548428339);
    b = simde_wasm_i32x4_const( -834943444, -1935106672,   452993959,   519567587);
    r = simde_wasm_i32x4_shuffle(a, b,  5,  1,  2,  2);
    e = simde_wasm_i32x4_const(-1935106672, -1225630671, -2103037400, -2103037400);
    simde_test_wasm_i32x4_assert_equal(r, e);

    a = simde_wasm_i32x4_const(  924214448,  -115483774, -1148629010, -2086937703);
    b = simde_wasm_i32x4_const(-1594090129,  1430889961,  1070285208, -2147093706);
    r = simde_wasm_i32x4_shuffle(a, b,  4,  3,  5,  7);
    e = simde_wasm_i32x4_const(-1594090129, -2086937703,  1430889961, -2147093706);
    simde_test_wasm_i32x4_assert_equal(r, e);

    a = simde_wasm_i32x4_const(-1150259672, -1894044334, -1379642048, -2031893106);
    b = simde_wasm_i32x4_const( -479387984, -2017204575,  2019242413,  1007384207);
    r = simde_wasm_i32x4_shuffle(a, b,  5,  4,  7,  6);
    e = simde_wasm_i32x4_const(-2017204575,  -479387984,  1007384207,  2019242413);
    simde_test_wasm_i32x4_assert_equal(r, e);

    a = simde_wasm_i32x4_const( -872747698, -1708886816,   569355486,   -56685693);
    b = simde_wasm_i32x4_const(-1498172428,  1655524122,   345111178,  -535541304);
    r = simde_wasm_i32x4_shuffle(a, b,  1,  0,  0,  6);
    e = simde_wasm_i32x4_const(-1708886816,  -872747698,  -872747698,   345111178);
    simde_test_wasm_i32x4_assert_equal(r, e);

    a = simde_wasm_i32x4_const(-1810866377,  1681909997, -1634495063,  -401800665);
    b = simde_wasm_i32x4_const( 1217677927,  1660104709,  -697672100,  1844124820);
    r = simde_wasm_i32x4_shuffle(a, b,  5,  1,  1,  5);
    e = simde_wasm_i32x4_const( 1660104709,  1681909997,  1681909997,  1660104709);
    simde_test_wasm_i32x4_assert_equal(r, e);

    a = simde_wasm_i32x4_const( 1990531373,   289768840,   768253155,  -486287444);
    b = simde_wasm_i32x4_const(  -94661423,  1699526036,  1388057378,  -617062445);
    r = simde_wasm_i32x4_shuffle(a, b,  6,  0,  4,  6);
    e = simde_wasm_i32x4_const( 1388057378,  1990531373,   -94661423,  1388057378);
    simde_test_wasm_i32x4_assert_equal(r, e);

    a = simde_wasm_i32x4_const(-1470460360,   684600462,  1353633807, -2063095571);
    b = simde_wasm_i32x4_const(  759091309,   589692128,  -197182180, -1025522971);
    r = simde_wasm_i32x4_shuffle(a, b,  7,  6,  3,  5);
    e = simde_wasm_i32x4_const(-1025522971,  -197182180, -2063095571,   589692128);
    simde_test_wasm_i32x4_assert_equal(r, e);

    return 0;
  #else
    fputc('\n', stdout);
    for (int i = 0 ; i < 8 ; i++) {
      int32_t a[sizeof(simde_v128_t) / sizeof(int32_t)];
      int32_t b[sizeof(simde_v128_t) / sizeof(int32_t)];

      simde_test_codegen_random_memory(sizeof(a), HEDLEY_REINTERPRET_CAST(uint8_t*, a));
      simde_test_codegen_random_memory(sizeof(b), HEDLEY_REINTERPRET_CAST(uint8_t*, b));

      printf("    a = simde_wasm_i32x4_const(%11" PRId32 ", %11" PRId32 ", %11" PRId32 ", %11" PRId32 ");\n",
             a[0], a[1], a[ 2], a[ 3]);
      printf("    b = simde_wasm_i32x4_const(%11" PRId32 ", %11" PRId32 ", %11" PRId32 ", %11" PRId32 ");\n",
             b[0], b[1], b[ 2], b[ 3]);
      printf("    r = simde_wasm_i32x4_shuffle(a, b, %2d, %2d, %2d, %2d);\n",
             simde_test_codegen_random_i32() & 7,
             simde_test_codegen_random_i32() & 7,
             simde_test_codegen_random_i32() & 7,
             simde_test_codegen_random_i32() & 7);
      printf("    \n");
      printf("    simde_wasm_v128_store(v, r);\n");
      printf("    printf(\"    e = simde_wasm_i32x4_const(%%11" PRId32 ", %%11" PRId32 ", %%11" PRId32 ", %%11" PRId32 ");\\n\", "
                         "v[0], v[1], v[2], v[3]);\n");
      printf("    // simde_test_wasm_i32x4_assert_equal(r, e);\n\n");
    }
    return 1;
  #endif
}

static int
test_simde_wasm_i64x2_shuffle(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    simde_v128_t a, b, r;
    // int64_t v[sizeof(simde_v128_t) / sizeof(int64_t)];
    simde_v128_t e;

    a = simde_wasm_i64x2_const(INT64_C( -3859415996448151424), INT64_C(  1923158520439403530));
    b = simde_wasm_i64x2_const(INT64_C( -6850238942974762025), INT64_C( -8609973005655155804));
    r = simde_wasm_i64x2_shuffle(a, b,  0,  3);
    e = simde_wasm_i64x2_const(INT64_C( -3859415996448151424), INT64_C( -8609973005655155804));
    simde_test_wasm_i64x2_assert_equal(r, e);

    a = simde_wasm_i64x2_const(INT64_C( -3756516919476796844), INT64_C( -1773846315017577980));
    b = simde_wasm_i64x2_const(INT64_C( -5456604717196592988), INT64_C( -5537630548919180928));
    r = simde_wasm_i64x2_shuffle(a, b,  3,  3);
    e = simde_wasm_i64x2_const(INT64_C( -5537630548919180928), INT64_C( -5537630548919180928));
    simde_test_wasm_i64x2_assert_equal(r, e);

    a = simde_wasm_i64x2_const(INT64_C( -2216179373244491479), INT64_C( -4486076416121803358));
    b = simde_wasm_i64x2_const(INT64_C(  2300243042995960776), INT64_C(  4115698399006848568));
    r = simde_wasm_i64x2_shuffle(a, b,  3,  3);
    e = simde_wasm_i64x2_const(INT64_C(  4115698399006848568), INT64_C(  4115698399006848568));
    simde_test_wasm_i64x2_assert_equal(r, e);

    a = simde_wasm_i64x2_const(INT64_C(  1805187520454176258), INT64_C( -6302922432939121330));
    b = simde_wasm_i64x2_const(INT64_C(  3388640413479497126), INT64_C(  5012530914674513588));
    r = simde_wasm_i64x2_shuffle(a, b,  3,  2);
    e = simde_wasm_i64x2_const(INT64_C(  5012530914674513588), INT64_C(  3388640413479497126));
    simde_test_wasm_i64x2_assert_equal(r, e);

    a = simde_wasm_i64x2_const(INT64_C( -8775806410524602447), INT64_C( -2664058908303067861));
    b = simde_wasm_i64x2_const(INT64_C( -2536243805978628899), INT64_C(  4436151059107595363));
    r = simde_wasm_i64x2_shuffle(a, b,  3,  0);
    e = simde_wasm_i64x2_const(INT64_C(  4436151059107595363), INT64_C( -8775806410524602447));
    simde_test_wasm_i64x2_assert_equal(r, e);

    a = simde_wasm_i64x2_const(INT64_C(  -961396371461309853), INT64_C(  7740502473077594264));
    b = simde_wasm_i64x2_const(INT64_C( -8440434636814826600), INT64_C(  5798310046170063410));
    r = simde_wasm_i64x2_shuffle(a, b,  0,  0);
    e = simde_wasm_i64x2_const(INT64_C(  -961396371461309853), INT64_C(  -961396371461309853));
    simde_test_wasm_i64x2_assert_equal(r, e);

    a = simde_wasm_i64x2_const(INT64_C(  9182199379776659629), INT64_C( -3145587607851875478));
    b = simde_wasm_i64x2_const(INT64_C( -4337315030765452975), INT64_C( -3174430087688911379));
    r = simde_wasm_i64x2_shuffle(a, b,  0,  0);
    e = simde_wasm_i64x2_const(INT64_C(  9182199379776659629), INT64_C(  9182199379776659629));
    simde_test_wasm_i64x2_assert_equal(r, e);

    a = simde_wasm_i64x2_const(INT64_C(  4353630142266642986), INT64_C(   551681478863627752));
    b = simde_wasm_i64x2_const(INT64_C( -6565612563093738293), INT64_C(  8893207348925896126));
    r = simde_wasm_i64x2_shuffle(a, b,  3,  2);
    e = simde_wasm_i64x2_const(INT64_C(  8893207348925896126), INT64_C( -6565612563093738293));
    simde_test_wasm_i64x2_assert_equal(r, e);

    return 0;
  #else
    fputc('\n', stdout);
    for (int i = 0 ; i < 8 ; i++) {
      int64_t a[sizeof(simde_v128_t) / sizeof(int64_t)];
      int64_t b[sizeof(simde_v128_t) / sizeof(int64_t)];

      simde_test_codegen_random_memory(sizeof(a), HEDLEY_REINTERPRET_CAST(uint8_t*, a));
      simde_test_codegen_random_memory(sizeof(b), HEDLEY_REINTERPRET_CAST(uint8_t*, b));

      printf("    a = simde_wasm_i64x2_const(INT64_C(%21" PRId64 "), INT64_C(%21" PRId64 "));\n",
             a[0], a[1]);
      printf("    b = simde_wasm_i64x2_const(INT64_C(%21" PRId64 "), INT64_C(%21" PRId64 "));\n",
             b[0], b[1]);
      printf("    r = simde_wasm_i64x2_shuffle(a, b, %2d, %2d);\n",
             simde_test_codegen_random_i32() & 3,
             simde_test_codegen_random_i32() & 3);
      printf("    \n");
      printf("    simde_wasm_v128_store(v, r);\n");
      printf("    printf(\"    e = simde_wasm_i64x2_const(INT64_C(%%21" PRId64 "), INT64_C(%%21" PRId64 "));\\n\", "
                         "v[0], v[1]);\n");
      printf("    // simde_test_wasm_i64x2_assert_equal(r, e);\n\n");
    }
    return 1;
  #endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_i8x16_shuffle)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_i16x8_shuffle)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_i32x4_shuffle)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_i64x2_shuffle)
SIMDE_TEST_FUNC_LIST_END

#include "test-simd128-footer.h"
