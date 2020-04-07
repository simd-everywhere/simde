/* Copyright (c) 2017 Evan Nemerson <evan@nemerson.com>
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

#define SIMDE_TESTS_CURRENT_ISAX mmx
#include <test/x86/test-mmx.h>

#if defined(SIMDE_MMX_NATIVE) || defined(SIMDE_NO_NATIVE) || defined(SIMDE_ALWAYS_BUILD_NATIVE_TESTS)

static MunitResult
test_simde_mm_set1_pi8(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    int8_t a;
    simde__m64 r;
  } test_vec[8] = {
    { INT8_C( -16),
      simde_mm_set_pi8(INT8_C( -16), INT8_C( -16), INT8_C( -16), INT8_C( -16),
                       INT8_C( -16), INT8_C( -16), INT8_C( -16), INT8_C( -16)) },
    { INT8_C(-120),
      simde_mm_set_pi8(INT8_C(-120), INT8_C(-120), INT8_C(-120), INT8_C(-120),
                       INT8_C(-120), INT8_C(-120), INT8_C(-120), INT8_C(-120)) },
    { INT8_C(  86),
      simde_mm_set_pi8(INT8_C(  86), INT8_C(  86), INT8_C(  86), INT8_C(  86),
                       INT8_C(  86), INT8_C(  86), INT8_C(  86), INT8_C(  86)) },
    { INT8_C( -12),
      simde_mm_set_pi8(INT8_C( -12), INT8_C( -12), INT8_C( -12), INT8_C( -12),
                       INT8_C( -12), INT8_C( -12), INT8_C( -12), INT8_C( -12)) },
    { INT8_C(   3),
      simde_mm_set_pi8(INT8_C(   3), INT8_C(   3), INT8_C(   3), INT8_C(   3),
                       INT8_C(   3), INT8_C(   3), INT8_C(   3), INT8_C(   3)) },
    { INT8_C(  25),
      simde_mm_set_pi8(INT8_C(  25), INT8_C(  25), INT8_C(  25), INT8_C(  25),
                       INT8_C(  25), INT8_C(  25), INT8_C(  25), INT8_C(  25)) },
    { INT8_C(  40),
      simde_mm_set_pi8(INT8_C(  40), INT8_C(  40), INT8_C(  40), INT8_C(  40),
                       INT8_C(  40), INT8_C(  40), INT8_C(  40), INT8_C(  40)) },
    { INT8_C( -12),
      simde_mm_set_pi8(INT8_C( -12), INT8_C( -12), INT8_C( -12), INT8_C( -12),
                       INT8_C( -12), INT8_C( -12), INT8_C( -12), INT8_C( -12)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m64 r = simde_mm_set1_pi8(test_vec[i].a);
    simde_assert_m64_i8(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_set1_pi16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  int16_t v = HEDLEY_STATIC_CAST(int16_t, munit_rand_int_range(SHRT_MIN, SHRT_MAX));

  simde__m64 x = simde_mm_set1_pi16(v);
  int16_t* r = HEDLEY_REINTERPRET_CAST(int16_t*, &x);

  simde_mm_empty();

  munit_assert_int16(r[0], ==, v);
  munit_assert_int16(r[1], ==, v);
  munit_assert_int16(r[2], ==, v);
  munit_assert_int16(r[3], ==, v);

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_set1_pi32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  int32_t v = HEDLEY_STATIC_CAST(int32_t, munit_rand_int_range(INT32_MIN, INT32_MAX));

  simde__m64 x = simde_mm_set1_pi32(v);
  int32_t* r = HEDLEY_REINTERPRET_CAST(int32_t*, &x);

  simde_mm_empty();

  munit_assert_int32(r[0], ==, v);
  munit_assert_int32(r[1], ==, v);

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_setr_pi8(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  int8_t d[8 / sizeof(int8_t)];
  munit_rand_memory(sizeof(d), HEDLEY_REINTERPRET_CAST(uint8_t*, d));

  simde__m64 x = simde_mm_setr_pi8(d[0], d[1], d[2], d[3], d[4], d[5], d[6], d[7]);
  int8_t* c = HEDLEY_REINTERPRET_CAST(int8_t*, &x);

  simde_mm_empty();

  munit_assert_int8(c[0], ==, d[0]);
  munit_assert_int8(c[1], ==, d[1]);
  munit_assert_int8(c[2], ==, d[2]);
  munit_assert_int8(c[3], ==, d[3]);
  munit_assert_int8(c[4], ==, d[4]);
  munit_assert_int8(c[5], ==, d[5]);
  munit_assert_int8(c[6], ==, d[6]);
  munit_assert_int8(c[7], ==, d[7]);

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_setr_pi16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  int16_t d[8 / sizeof(int16_t)];
  munit_rand_memory(sizeof(d), HEDLEY_REINTERPRET_CAST(uint8_t*, d));

  simde__m64 x = simde_mm_setr_pi16(d[0], d[1], d[2], d[3]);
  int16_t* s = HEDLEY_REINTERPRET_CAST(int16_t*, &x);

  simde_mm_empty();

  munit_assert_int16(s[0], ==, d[0]);
  munit_assert_int16(s[1], ==, d[1]);
  munit_assert_int16(s[2], ==, d[2]);
  munit_assert_int16(s[3], ==, d[3]);

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_setr_pi32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  int32_t d[8 / sizeof(int32_t)];
  munit_rand_memory(sizeof(d), HEDLEY_REINTERPRET_CAST(uint8_t*, d));

  simde__m64 x = simde_mm_setr_pi32(d[0], d[1]);
  int32_t* i = HEDLEY_REINTERPRET_CAST(int32_t*, &x);

  simde_mm_empty();

  munit_assert_int32(i[0], ==, d[0]);
  munit_assert_int32(i[1], ==, d[1]);

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_add_pi8(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m64 a;
    simde__m64 b;
    simde__m64 r;
  } test_vec[8] = {
    { simde_mm_set_pi8(INT8_C(  25), INT8_C(-106), INT8_C(  93), INT8_C(  86), INT8_C( -56), INT8_C( 101), INT8_C(  79), INT8_C(  83)),
      simde_mm_set_pi8(INT8_C( -38), INT8_C(  -6), INT8_C(  47), INT8_C(  59), INT8_C( -67), INT8_C( -36), INT8_C( 127), INT8_C( 104)),
      simde_mm_set_pi8(INT8_C( -13), INT8_C(-112), INT8_C(-116), INT8_C(-111), INT8_C(-123), INT8_C(  65), INT8_C( -50), INT8_C( -69)) },
    { simde_mm_set_pi8(INT8_C(-105), INT8_C( 113), INT8_C(  22), INT8_C( -91), INT8_C(  59), INT8_C(  -4), INT8_C(  67), INT8_C(  43)),
      simde_mm_set_pi8(INT8_C( -13), INT8_C(  93), INT8_C(  81), INT8_C( 108), INT8_C(-104), INT8_C( 123), INT8_C( 105), INT8_C( 119)),
      simde_mm_set_pi8(INT8_C(-118), INT8_C( -50), INT8_C( 103), INT8_C(  17), INT8_C( -45), INT8_C( 119), INT8_C( -84), INT8_C( -94)) },
    { simde_mm_set_pi8(INT8_C(  -8), INT8_C(  52), INT8_C(  92), INT8_C( 121), INT8_C(  58), INT8_C(-104), INT8_C(  27), INT8_C( -80)),
      simde_mm_set_pi8(INT8_C(  62), INT8_C(-100), INT8_C(   5), INT8_C( -95), INT8_C( -16), INT8_C( 109), INT8_C( 127), INT8_C(  62)),
      simde_mm_set_pi8(INT8_C(  54), INT8_C( -48), INT8_C(  97), INT8_C(  26), INT8_C(  42), INT8_C(   5), INT8_C(-102), INT8_C( -18)) },
    { simde_mm_set_pi8(INT8_C(  32), INT8_C( 124), INT8_C( 115), INT8_C(   3), INT8_C( 104), INT8_C(  27), INT8_C(  43), INT8_C( -11)),
      simde_mm_set_pi8(INT8_C( -22), INT8_C(  27), INT8_C( -47), INT8_C(  45), INT8_C( -96), INT8_C( -49), INT8_C( -74), INT8_C( -34)),
      simde_mm_set_pi8(INT8_C(  10), INT8_C(-105), INT8_C(  68), INT8_C(  48), INT8_C(   8), INT8_C( -22), INT8_C( -31), INT8_C( -45)) },
    { simde_mm_set_pi8(INT8_C( -14), INT8_C( -79), INT8_C( -38), INT8_C( -93), INT8_C( -55), INT8_C(  83), INT8_C(  78), INT8_C( -90)),
      simde_mm_set_pi8(INT8_C(  91), INT8_C( -61), INT8_C(-124), INT8_C( -64), INT8_C(  76), INT8_C( -15), INT8_C(-117), INT8_C(  11)),
      simde_mm_set_pi8(INT8_C(  77), INT8_C( 116), INT8_C(  94), INT8_C(  99), INT8_C(  21), INT8_C(  68), INT8_C( -39), INT8_C( -79)) },
    { simde_mm_set_pi8(INT8_C(-119), INT8_C(  33), INT8_C( -57), INT8_C(  54), INT8_C( -18), INT8_C(  79), INT8_C(  86), INT8_C( -25)),
      simde_mm_set_pi8(INT8_C(-115), INT8_C(-114), INT8_C(  72), INT8_C(-126), INT8_C( -80), INT8_C( 114), INT8_C(-126), INT8_C(  42)),
      simde_mm_set_pi8(INT8_C(  22), INT8_C( -81), INT8_C(  15), INT8_C( -72), INT8_C( -98), INT8_C( -63), INT8_C( -40), INT8_C(  17)) },
    { simde_mm_set_pi8(INT8_C(  60), INT8_C( 109), INT8_C(  93), INT8_C( -45), INT8_C( -62), INT8_C(-104), INT8_C( -41), INT8_C(  72)),
      simde_mm_set_pi8(INT8_C(  72), INT8_C( -86), INT8_C(  21), INT8_C(  79), INT8_C(  43), INT8_C(  23), INT8_C( -74), INT8_C( -62)),
      simde_mm_set_pi8(INT8_C(-124), INT8_C(  23), INT8_C( 114), INT8_C(  34), INT8_C( -19), INT8_C( -81), INT8_C(-115), INT8_C(  10)) },
    { simde_mm_set_pi8(INT8_C( 110), INT8_C( 106), INT8_C( -94), INT8_C( 102), INT8_C( -82), INT8_C( 108), INT8_C( -12), INT8_C( -48)),
      simde_mm_set_pi8(INT8_C( 108), INT8_C(   3), INT8_C( -91), INT8_C(  65), INT8_C(  30), INT8_C( 106), INT8_C(  -1), INT8_C( 100)),
      simde_mm_set_pi8(INT8_C( -38), INT8_C( 109), INT8_C(  71), INT8_C( -89), INT8_C( -52), INT8_C( -42), INT8_C( -13), INT8_C(  52)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m64 r = simde_mm_add_pi8(test_vec[i].a, test_vec[i].b);
    simde_mm_empty();
    simde_assert_m64_i8(r, ==, test_vec[i].r);
  }

  simde_mm_empty();
  return MUNIT_OK;
}

static MunitResult
test_simde_mm_add_pi16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m64 a;
    simde__m64 b;
    simde__m64 r;
  } test_vec[8] = {
    { simde_mm_set_pi16(INT16_C( -13258), INT16_C(  -8776), INT16_C(  32365), INT16_C(  -3887)),
      simde_mm_set_pi16(INT16_C(  20018), INT16_C(  23417), INT16_C(   -774), INT16_C(   5810)),
      simde_mm_set_pi16(INT16_C(   6760), INT16_C(  14641), INT16_C(  31591), INT16_C(   1923)) },
    { simde_mm_set_pi16(INT16_C(  11335), INT16_C(  29732), INT16_C(  26059), INT16_C( -15004)),
      simde_mm_set_pi16(INT16_C( -13772), INT16_C( -20922), INT16_C(   1993), INT16_C( -30395)),
      simde_mm_set_pi16(INT16_C(  -2437), INT16_C(   8810), INT16_C(  28052), INT16_C(  20137)) },
    { simde_mm_set_pi16(INT16_C(    159), INT16_C(  23628), INT16_C( -17224), INT16_C( -23288)),
      simde_mm_set_pi16(INT16_C( -18303), INT16_C(   7699), INT16_C(  22351), INT16_C( -16238)),
      simde_mm_set_pi16(INT16_C( -18144), INT16_C(  31327), INT16_C(   5127), INT16_C(  26010)) },
    { simde_mm_set_pi16(INT16_C(   9097), INT16_C(  -5982), INT16_C(  28191), INT16_C( -32707)),
      simde_mm_set_pi16(INT16_C( -16920), INT16_C( -18039), INT16_C( -32259), INT16_C(  10405)),
      simde_mm_set_pi16(INT16_C(  -7823), INT16_C( -24021), INT16_C(  -4068), INT16_C( -22302)) },
    { simde_mm_set_pi16(INT16_C(   2097), INT16_C(  24451), INT16_C(  25533), INT16_C( -14205)),
      simde_mm_set_pi16(INT16_C( -28269), INT16_C(   4484), INT16_C( -22223), INT16_C(  17945)),
      simde_mm_set_pi16(INT16_C( -26172), INT16_C(  28935), INT16_C(   3310), INT16_C(   3740)) },
    { simde_mm_set_pi16(INT16_C( -17654), INT16_C(  12451), INT16_C(  12325), INT16_C(   5198)),
      simde_mm_set_pi16(INT16_C( -26590), INT16_C(  31889), INT16_C( -14656), INT16_C(   6378)),
      simde_mm_set_pi16(INT16_C(  21292), INT16_C( -21196), INT16_C(  -2331), INT16_C(  11576)) },
    { simde_mm_set_pi16(INT16_C(  31498), INT16_C( -18726), INT16_C(  -9720), INT16_C( -17042)),
      simde_mm_set_pi16(INT16_C(  17025), INT16_C(  13186), INT16_C( -25923), INT16_C(  15017)),
      simde_mm_set_pi16(INT16_C( -17013), INT16_C(  -5540), INT16_C(  29893), INT16_C(  -2025)) },
    { simde_mm_set_pi16(INT16_C(   9904), INT16_C( -28061), INT16_C( -32123), INT16_C(  -1285)),
      simde_mm_set_pi16(INT16_C(  -7190), INT16_C(  -1918), INT16_C(  26654), INT16_C( -31449)),
      simde_mm_set_pi16(INT16_C(   2714), INT16_C( -29979), INT16_C(  -5469), INT16_C( -32734)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m64 r = simde_mm_add_pi16(test_vec[i].a, test_vec[i].b);
    simde_mm_empty();
    simde_assert_m64_i16(r, ==, test_vec[i].r);
  }

  simde_mm_empty();
  return MUNIT_OK;
}

static MunitResult
test_simde_mm_add_pi32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m64 a;
    simde__m64 b;
    simde__m64 r;
  } test_vec[8] = {
    { simde_mm_set_pi32(INT32_C( -1528799955), INT32_C( -1825996932)),
      simde_mm_set_pi32(INT32_C( -1229665745), INT32_C(   989894561)),
      simde_mm_set_pi32(INT32_C(  1536501596), INT32_C(  -836102371)) },
    { simde_mm_set_pi32(INT32_C(  1936809596), INT32_C(  1331021923)),
      simde_mm_set_pi32(INT32_C(  -505769092), INT32_C(  1471336810)),
      simde_mm_set_pi32(INT32_C(  1431040504), INT32_C( -1492608563)) },
    { simde_mm_set_pi32(INT32_C(   783830780), INT32_C(  1923113282)),
      simde_mm_set_pi32(INT32_C(  1700161106), INT32_C(  -175473923)),
      simde_mm_set_pi32(INT32_C( -1810975410), INT32_C(  1747639359)) },
    { simde_mm_set_pi32(INT32_C(  1195975755), INT32_C(  1329173130)),
      simde_mm_set_pi32(INT32_C(  -611537759), INT32_C(   787308680)),
      simde_mm_set_pi32(INT32_C(   584437996), INT32_C(  2116481810)) },
    { simde_mm_set_pi32(INT32_C(   950103059), INT32_C(   570905377)),
      simde_mm_set_pi32(INT32_C(  1696944201), INT32_C( -1762697792)),
      simde_mm_set_pi32(INT32_C( -1647920036), INT32_C( -1191792415)) },
    { simde_mm_set_pi32(INT32_C(    40870864), INT32_C(   149169565)),
      simde_mm_set_pi32(INT32_C(  1633277631), INT32_C(  -224026523)),
      simde_mm_set_pi32(INT32_C(  1674148495), INT32_C(   -74856958)) },
    { simde_mm_set_pi32(INT32_C(  -718937511), INT32_C(  1453252371)),
      simde_mm_set_pi32(INT32_C(    56683182), INT32_C(  -594741944)),
      simde_mm_set_pi32(INT32_C(  -662254329), INT32_C(   858510427)) },
    { simde_mm_set_pi32(INT32_C(  -950411567), INT32_C(    -1493828)),
      simde_mm_set_pi32(INT32_C( -1680249611), INT32_C(   321011369)),
      simde_mm_set_pi32(INT32_C(  1664306118), INT32_C(   319517541)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m64 r = simde_mm_add_pi32(test_vec[i].a, test_vec[i].b);
    simde_mm_empty();
    simde_assert_m64_i32(r, ==, test_vec[i].r);
  }

  simde_mm_empty();
  return MUNIT_OK;
}

static MunitResult
test_simde_mm_adds_pi8(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m64 a;
    simde__m64 b;
    simde__m64 r;
  } test_vec[8] = {
    { simde_mm_set_pi8(  99,   16,  -73,  -73,   34,   32,   87,   42),
      simde_mm_set_pi8( -29,  -82,  -26,  -38,   66,  -51,   82,   53),
      simde_mm_set_pi8(  70,  -66,  -99, -111,  100,  -19,  127,   95) },
    { simde_mm_set_pi8( -63, -116,  -41,  -11,  -99,  -60,  -36,  -15),
      simde_mm_set_pi8(  84, -113,  107,   81,  -28,  -25,  -90, -115),
      simde_mm_set_pi8(  21, -128,   66,   70, -127,  -85, -126, -128) },
    { simde_mm_set_pi8( -79, -104,  -10,  -65,   84,  -40, -102,   75),
      simde_mm_set_pi8(  30,   54,  127,   16,   -7,  -31,  -83,  -89),
      simde_mm_set_pi8( -49,  -50,  117,  -49,   77,  -71, -128,  -14) },
    { simde_mm_set_pi8(-115,  -50,  111,  104,  -19,  -48,  122,   59),
      simde_mm_set_pi8( -74,  -15,   43,    9,   94,  -81,  -68,   15),
      simde_mm_set_pi8(-128,  -65,  127,  113,   75, -128,   54,   74) },
    { simde_mm_set_pi8(  18,  -79,    5,   80,   99,  108,   39,  -27),
      simde_mm_set_pi8( 127,   44,   22,  -80,  -86,  -11,  108,  -95),
      simde_mm_set_pi8( 127,  -35,   27,    0,   13,   97,  127, -122) },
    { simde_mm_set_pi8( -35,   62,  102,  -79,  117,  108,   56,  -21),
      simde_mm_set_pi8(  68,  119,  -10,   17,   40, -124,  -75,  -39),
      simde_mm_set_pi8(  33,  127,   92,  -62,  127,  -16,  -19,  -60) },
    { simde_mm_set_pi8(  45,   -5,  -10,   -4,  -23,  -76, -111,  -38),
      simde_mm_set_pi8(  24,  -15,   -2,   75,   11, -108,   -5,  124),
      simde_mm_set_pi8(  69,  -20,  -12,   71,  -12, -128, -116,   86) },
    { simde_mm_set_pi8( 116,   38,   87,    5,  -25, -119,  117,  -12),
      simde_mm_set_pi8( -51,   25, -122,   40, -111,  -50,  -55, -109),
      simde_mm_set_pi8(  65,   63,  -35,   45, -128, -128,   62, -121) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m64 r = simde_mm_adds_pi8(test_vec[i].a, test_vec[i].b);
    simde_mm_empty();
    simde_assert_m64_i8(r, ==, test_vec[i].r);
  }

  simde_mm_empty();
  return MUNIT_OK;
}

static MunitResult
test_simde_mm_adds_pu8(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m64 a;
    simde__m64 b;
    simde__m64 r;
  } test_vec[8] = {
    { simde_x_mm_set_pu8(UINT8_C(  81), UINT8_C(  21), UINT8_C( 204), UINT8_C( 252),
                               UINT8_C( 129), UINT8_C( 215), UINT8_C( 184), UINT8_C(  80)),
      simde_x_mm_set_pu8(UINT8_C(  23), UINT8_C( 216), UINT8_C( 110), UINT8_C( 125),
                               UINT8_C( 171), UINT8_C( 145), UINT8_C(  61), UINT8_C( 141)),
      simde_x_mm_set_pu8(UINT8_C( 104), UINT8_C( 237), UINT8_C( 255), UINT8_C( 255),
                               UINT8_C( 255), UINT8_C( 255), UINT8_C( 245), UINT8_C( 221)) },
    { simde_x_mm_set_pu8(UINT8_C( 239), UINT8_C( 124), UINT8_C( 164), UINT8_C( 178),
                               UINT8_C(  97), UINT8_C( 133), UINT8_C(  53), UINT8_C(   7)),
      simde_x_mm_set_pu8(UINT8_C(  55), UINT8_C(  60), UINT8_C(  93), UINT8_C( 144),
                               UINT8_C(  87), UINT8_C(  38), UINT8_C(  29), UINT8_C( 227)),
      simde_x_mm_set_pu8(UINT8_C( 255), UINT8_C( 184), UINT8_C( 255), UINT8_C( 255),
                               UINT8_C( 184), UINT8_C( 171), UINT8_C(  82), UINT8_C( 234)) },
    { simde_x_mm_set_pu8(UINT8_C(   2), UINT8_C( 239), UINT8_C( 120), UINT8_C( 239),
                               UINT8_C(  57), UINT8_C( 159), UINT8_C( 235), UINT8_C(  22)),
      simde_x_mm_set_pu8(UINT8_C( 220), UINT8_C(   9), UINT8_C( 135), UINT8_C(  55),
                               UINT8_C(  21), UINT8_C(   1), UINT8_C( 123), UINT8_C( 167)),
      simde_x_mm_set_pu8(UINT8_C( 222), UINT8_C( 248), UINT8_C( 255), UINT8_C( 255),
                               UINT8_C(  78), UINT8_C( 160), UINT8_C( 255), UINT8_C( 189)) },
    { simde_x_mm_set_pu8(UINT8_C( 169), UINT8_C( 122), UINT8_C( 209), UINT8_C( 107),
                               UINT8_C(  53), UINT8_C( 194), UINT8_C( 157), UINT8_C( 250)),
      simde_x_mm_set_pu8(UINT8_C( 190), UINT8_C( 161), UINT8_C(  50), UINT8_C(   2),
                               UINT8_C( 227), UINT8_C( 196), UINT8_C(  34), UINT8_C( 128)),
      simde_x_mm_set_pu8(UINT8_C( 255), UINT8_C( 255), UINT8_C( 255), UINT8_C( 109),
                               UINT8_C( 255), UINT8_C( 255), UINT8_C( 191), UINT8_C( 255)) },
    { simde_x_mm_set_pu8(UINT8_C( 127), UINT8_C( 206), UINT8_C(  75), UINT8_C( 228),
                               UINT8_C(  24), UINT8_C( 253), UINT8_C( 247), UINT8_C( 227)),
      simde_x_mm_set_pu8(UINT8_C( 199), UINT8_C( 181), UINT8_C( 197), UINT8_C(  15),
                               UINT8_C( 201), UINT8_C( 118), UINT8_C( 220), UINT8_C(  22)),
      simde_x_mm_set_pu8(UINT8_C( 255), UINT8_C( 255), UINT8_C( 255), UINT8_C( 243),
                               UINT8_C( 225), UINT8_C( 255), UINT8_C( 255), UINT8_C( 249)) },
    { simde_x_mm_set_pu8(UINT8_C( 160), UINT8_C(  45), UINT8_C( 121), UINT8_C( 199),
                               UINT8_C( 155), UINT8_C( 201), UINT8_C(  54), UINT8_C(  92)),
      simde_x_mm_set_pu8(UINT8_C(  29), UINT8_C( 158), UINT8_C(  69), UINT8_C(  12),
                               UINT8_C( 220), UINT8_C( 133), UINT8_C(  37), UINT8_C(  27)),
      simde_x_mm_set_pu8(UINT8_C( 189), UINT8_C( 203), UINT8_C( 190), UINT8_C( 211),
                               UINT8_C( 255), UINT8_C( 255), UINT8_C(  91), UINT8_C( 119)) },
    { simde_x_mm_set_pu8(UINT8_C( 173), UINT8_C( 130), UINT8_C(  79), UINT8_C( 240),
                               UINT8_C( 183), UINT8_C( 112), UINT8_C(  65), UINT8_C(  13)),
      simde_x_mm_set_pu8(UINT8_C(  24), UINT8_C( 152), UINT8_C( 239), UINT8_C( 128),
                               UINT8_C(  83), UINT8_C(  69), UINT8_C( 122), UINT8_C( 121)),
      simde_x_mm_set_pu8(UINT8_C( 197), UINT8_C( 255), UINT8_C( 255), UINT8_C( 255),
                               UINT8_C( 255), UINT8_C( 181), UINT8_C( 187), UINT8_C( 134)) },
    { simde_x_mm_set_pu8(UINT8_C( 242), UINT8_C( 255), UINT8_C( 149), UINT8_C( 159),
                               UINT8_C(  60), UINT8_C( 134), UINT8_C(  24), UINT8_C( 232)),
      simde_x_mm_set_pu8(UINT8_C( 209), UINT8_C( 150), UINT8_C(   4), UINT8_C(  97),
                               UINT8_C( 136), UINT8_C(  88), UINT8_C(  70), UINT8_C( 193)),
      simde_x_mm_set_pu8(UINT8_C( 255), UINT8_C( 255), UINT8_C( 153), UINT8_C( 255),
                               UINT8_C( 196), UINT8_C( 222), UINT8_C(  94), UINT8_C( 255)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m64 r = simde_mm_adds_pu8(test_vec[i].a, test_vec[i].b);
    simde_assert_m64_u8(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_adds_pi16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m64 a;
    simde__m64 b;
    simde__m64 r;
  } test_vec[8] = {
    { simde_mm_set_pi16(INT16_C( -31309), INT16_C(  -5581), INT16_C( -13514), INT16_C( -24682)),
      simde_mm_set_pi16(INT16_C(  19892), INT16_C( -12160), INT16_C(   3266), INT16_C(   9002)),
      simde_mm_set_pi16(INT16_C( -11417), INT16_C( -17741), INT16_C( -10248), INT16_C( -15680)) },
    { simde_mm_set_pi16(INT16_C(  20564), INT16_C( -25554), INT16_C(  18522), INT16_C(   -107)),
      simde_mm_set_pi16(INT16_C(  12328), INT16_C(  12883), INT16_C(   2251), INT16_C( -19119)),
      simde_mm_set_pi16(INT16_C(  32767), INT16_C( -12671), INT16_C(  20773), INT16_C( -19226)) },
    { simde_mm_set_pi16(INT16_C(  20106), INT16_C( -15513), INT16_C( -25552), INT16_C( -23751)),
      simde_mm_set_pi16(INT16_C(  11380), INT16_C(   4698), INT16_C(  16886), INT16_C(  11304)),
      simde_mm_set_pi16(INT16_C(  31486), INT16_C( -10815), INT16_C(  -8666), INT16_C( -12447)) },
    { simde_mm_set_pi16(INT16_C( -30807), INT16_C( -12488), INT16_C(  12150), INT16_C(    344)),
      simde_mm_set_pi16(INT16_C( -21735), INT16_C(  11424), INT16_C(  19342), INT16_C( -22640)),
      simde_mm_set_pi16(INT16_C( -32768), INT16_C(  -1064), INT16_C(  31492), INT16_C( -22296)) },
    { simde_mm_set_pi16(INT16_C(  23188), INT16_C( -20941), INT16_C(  26991), INT16_C( -11383)),
      simde_mm_set_pi16(INT16_C(  20582), INT16_C(   6628), INT16_C(  32097), INT16_C(  23397)),
      simde_mm_set_pi16(INT16_C(  32767), INT16_C( -14313), INT16_C(  32767), INT16_C(  12014)) },
    { simde_mm_set_pi16(INT16_C(   1789), INT16_C(  28566), INT16_C(  18995), INT16_C( -32500)),
      simde_mm_set_pi16(INT16_C( -32609), INT16_C( -30393), INT16_C(   1798), INT16_C(  28485)),
      simde_mm_set_pi16(INT16_C( -30820), INT16_C(  -1827), INT16_C(  20793), INT16_C(  -4015)) },
    { simde_mm_set_pi16(INT16_C(  18491), INT16_C( -11781), INT16_C( -27491), INT16_C(    337)),
      simde_mm_set_pi16(INT16_C(    420), INT16_C(  28774), INT16_C( -31111), INT16_C(  15256)),
      simde_mm_set_pi16(INT16_C(  18911), INT16_C(  16993), INT16_C( -32768), INT16_C(  15593)) },
    { simde_mm_set_pi16(INT16_C( -15687), INT16_C(  25487), INT16_C(  23048), INT16_C(  -8478)),
      simde_mm_set_pi16(INT16_C(   9271), INT16_C(  -4756), INT16_C( -12087), INT16_C( -15383)),
      simde_mm_set_pi16(INT16_C(  -6416), INT16_C(  20731), INT16_C(  10961), INT16_C( -23861)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m64 r = simde_mm_adds_pi16(test_vec[i].a, test_vec[i].b);
    simde_mm_empty();
    simde_assert_m64_i16(r, ==, test_vec[i].r);
  }

  simde_mm_empty();
  return MUNIT_OK;
}

static MunitResult
test_simde_mm_adds_pu16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m64 a;
    simde__m64 b;
    simde__m64 r;
  } test_vec[8] = {
    { simde_x_mm_set_pu16(UINT16_C(43150), UINT16_C( 5470), UINT16_C(60072), UINT16_C(50068)),
      simde_x_mm_set_pu16(UINT16_C( 7332), UINT16_C( 4270), UINT16_C(46463), UINT16_C( 9473)),
      simde_x_mm_set_pu16(UINT16_C(50482), UINT16_C( 9740), UINT16_C(65535), UINT16_C(59541)) },
    { simde_x_mm_set_pu16(UINT16_C( 2434), UINT16_C(31906), UINT16_C( 3723), UINT16_C(47234)),
      simde_x_mm_set_pu16(UINT16_C(58902), UINT16_C(62845), UINT16_C(51771), UINT16_C(64034)),
      simde_x_mm_set_pu16(UINT16_C(61336), UINT16_C(65535), UINT16_C(55494), UINT16_C(65535)) },
    { simde_x_mm_set_pu16(UINT16_C(  129), UINT16_C(16274), UINT16_C( 9343), UINT16_C(27425)),
      simde_x_mm_set_pu16(UINT16_C(21184), UINT16_C(38810), UINT16_C(32910), UINT16_C(34144)),
      simde_x_mm_set_pu16(UINT16_C(21313), UINT16_C(55084), UINT16_C(42253), UINT16_C(61569)) },
    { simde_x_mm_set_pu16(UINT16_C(64726), UINT16_C(55325), UINT16_C( 5040), UINT16_C(34690)),
      simde_x_mm_set_pu16(UINT16_C(18928), UINT16_C(15762), UINT16_C(23760), UINT16_C(30303)),
      simde_x_mm_set_pu16(UINT16_C(65535), UINT16_C(65535), UINT16_C(28800), UINT16_C(64993)) },
    { simde_x_mm_set_pu16(UINT16_C(12447), UINT16_C(56063), UINT16_C(19893), UINT16_C(38115)),
      simde_x_mm_set_pu16(UINT16_C(53854), UINT16_C( 9599), UINT16_C(53148), UINT16_C(47295)),
      simde_x_mm_set_pu16(UINT16_C(65535), UINT16_C(65535), UINT16_C(65535), UINT16_C(65535)) },
    { simde_x_mm_set_pu16(UINT16_C(30591), UINT16_C(42550), UINT16_C(36715), UINT16_C(13411)),
      simde_x_mm_set_pu16(UINT16_C(46515), UINT16_C(57187), UINT16_C(46870), UINT16_C(44207)),
      simde_x_mm_set_pu16(UINT16_C(65535), UINT16_C(65535), UINT16_C(65535), UINT16_C(57618)) },
    { simde_x_mm_set_pu16(UINT16_C(12664), UINT16_C(64378), UINT16_C(29354), UINT16_C(42615)),
      simde_x_mm_set_pu16(UINT16_C(62249), UINT16_C(64644), UINT16_C(45128), UINT16_C(47328)),
      simde_x_mm_set_pu16(UINT16_C(65535), UINT16_C(65535), UINT16_C(65535), UINT16_C(65535)) },
    { simde_x_mm_set_pu16(UINT16_C(65124), UINT16_C( 3867), UINT16_C(20702), UINT16_C(63422)),
      simde_x_mm_set_pu16(UINT16_C(51381), UINT16_C(37432), UINT16_C(48951), UINT16_C(45184)),
      simde_x_mm_set_pu16(UINT16_C(65535), UINT16_C(41299), UINT16_C(65535), UINT16_C(65535)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m64 r = simde_mm_adds_pu16(test_vec[i].a, test_vec[i].b);
    simde_assert_m64_i16(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_and_si64(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m64 a;
    simde__m64 b;
    simde__m64 r;
  } test_vec[8] = {
    { simde_mm_set_pi32(INT32_C(   340534654), INT32_C(   867835838)),
      simde_mm_set_pi32(INT32_C( -1715051141), INT32_C(   327376215)),
      simde_mm_set_pi32(INT32_C(   272901498), INT32_C(   327294230)) },
    { simde_mm_set_pi32(INT32_C(   364465166), INT32_C( -1853449223)),
      simde_mm_set_pi32(INT32_C(   425932704), INT32_C(  -538031667)),
      simde_mm_set_pi32(INT32_C(   287376384), INT32_C( -1853486647)) },
    { simde_mm_set_pi32(INT32_C(  1222276268), INT32_C( -1950390417)),
      simde_mm_set_pi32(INT32_C(   104967923), INT32_C(   339992254)),
      simde_mm_set_pi32(INT32_C(     4203680), INT32_C(      214574)) },
    { simde_mm_set_pi32(INT32_C(   678635361), INT32_C(  1353498548)),
      simde_mm_set_pi32(INT32_C(  1051418126), INT32_C( -1022663537)),
      simde_mm_set_pi32(INT32_C(   673383936), INT32_C(  1074275460)) },
    { simde_mm_set_pi32(INT32_C(  1823492970), INT32_C( -1726291925)),
      simde_mm_set_pi32(INT32_C(  1139854805), INT32_C(   874111018)),
      simde_mm_set_pi32(INT32_C(  1085294912), INT32_C(   270065706)) },
    { simde_mm_set_pi32(INT32_C(   188716107), INT32_C(   919243794)),
      simde_mm_set_pi32(INT32_C(  -505381577), INT32_C( -1684778331)),
      simde_mm_set_pi32(INT32_C(    18879491), INT32_C(   310378496)) },
    { simde_mm_set_pi32(INT32_C( -1486610662), INT32_C(   307692640)),
      simde_mm_set_pi32(INT32_C( -1793851837), INT32_C(  1963802755)),
      simde_mm_set_pi32(INT32_C( -2063589886), INT32_C(   268763136)) },
    { simde_mm_set_pi32(INT32_C(  -630259527), INT32_C(   -82339396)),
      simde_mm_set_pi32(INT32_C(  1607040389), INT32_C(   867785548)),
      simde_mm_set_pi32(INT32_C(  1514733697), INT32_C(   856758540)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m64 r = simde_mm_and_si64(test_vec[i].a, test_vec[i].b);
    simde_mm_empty();
    simde_assert_m64_i32(r, ==, test_vec[i].r);
  }

  simde_mm_empty();
  return MUNIT_OK;
}

static MunitResult
test_simde_mm_andnot_si64(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m64 a;
    simde__m64 b;
    simde__m64 r;
  } test_vec[8] = {
    { simde_mm_set_pi32(INT32_C(   874898289), INT32_C(  -802292997)),
      simde_mm_set_pi32(INT32_C(   329777422), INT32_C(   479831177)),
      simde_mm_set_pi32(INT32_C(    59244558), INT32_C(   210764800)) },
    { simde_mm_set_pi32(INT32_C(  -944824913), INT32_C(  1953730462)),
      simde_mm_set_pi32(INT32_C(  -914930437), INT32_C(  -556614726)),
      simde_mm_set_pi32(INT32_C(   139477072), INT32_C( -1971310560)) },
    { simde_mm_set_pi32(INT32_C(  -253535493), INT32_C(  1477705121)),
      simde_mm_set_pi32(INT32_C( -1581892884), INT32_C( -1606801005)),
      simde_mm_set_pi32(INT32_C(    18096132), INT32_C( -1607991278)) },
    { simde_mm_set_pi32(INT32_C(  -585861604), INT32_C(   825554783)),
      simde_mm_set_pi32(INT32_C( -1758500210), INT32_C(  -643533489)),
      simde_mm_set_pi32(INT32_C(    36374658), INT32_C(  -931135488)) },
    { simde_mm_set_pi32(INT32_C(    -5443449), INT32_C(   694842285)),
      simde_mm_set_pi32(INT32_C( -1613805192), INT32_C(   215848721)),
      simde_mm_set_pi32(INT32_C(     4393336), INT32_C(    76907536)) },
    { simde_mm_set_pi32(INT32_C(  1431251288), INT32_C(  1009645294)),
      simde_mm_set_pi32(INT32_C( -1668167014), INT32_C(  -733286899)),
      simde_mm_set_pi32(INT32_C( -2003778942), INT32_C( -1069414399)) },
    { simde_mm_set_pi32(INT32_C(  1707128575), INT32_C( -1462185330)),
      simde_mm_set_pi32(INT32_C( -1016415616), INT32_C( -1881637541)),
      simde_mm_set_pi32(INT32_C( -2111174656), INT32_C(   117452113)) },
    { simde_mm_set_pi32(INT32_C(   336066190), INT32_C( -2007360384)),
      simde_mm_set_pi32(INT32_C( -1959332116), INT32_C(  -820920813)),
      simde_mm_set_pi32(INT32_C( -1959788448), INT32_C(  1191289363)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m64 r = simde_mm_andnot_si64(test_vec[i].a, test_vec[i].b);
    simde_assert_m64_i32(r, ==, test_vec[i].r);
  }

  simde_mm_empty();
  return MUNIT_OK;
}

static MunitResult
test_simde_mm_cmpeq_pi8(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m64 a;
    simde__m64 b;
    simde__m64 r;
  } test_vec[8] = {
    { simde_mm_set_pi8(INT8_C(  61), INT8_C(-117), INT8_C(-117), INT8_C( -23), INT8_C( -19), INT8_C(   6), INT8_C( -24), INT8_C(  89)),
      simde_mm_set_pi8(INT8_C(  47), INT8_C(  71), INT8_C(-105), INT8_C(  13), INT8_C( -26), INT8_C(  93), INT8_C( 118), INT8_C( -58)),
      simde_mm_set_pi8(INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0)) },
    { simde_mm_set_pi8(INT8_C(  78), INT8_C(  11), INT8_C(  -2), INT8_C(  86), INT8_C( -50), INT8_C( -49), INT8_C(  -1), INT8_C(  92)),
      simde_mm_set_pi8(INT8_C( -85), INT8_C( -99), INT8_C( -41), INT8_C( 116), INT8_C(  74), INT8_C( 114), INT8_C(  -3), INT8_C( -98)),
      simde_mm_set_pi8(INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0)) },
    { simde_mm_set_pi8(INT8_C(  60), INT8_C(  10), INT8_C( -34), INT8_C(  30), INT8_C(  48), INT8_C( -13), INT8_C(-106), INT8_C( 105)),
      simde_mm_set_pi8(INT8_C(  81), INT8_C( 108), INT8_C( -65), INT8_C( -58), INT8_C( -30), INT8_C( -90), INT8_C(  42), INT8_C(   0)),
      simde_mm_set_pi8(INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0)) },
    { simde_mm_set_pi8(INT8_C(-113), INT8_C( -67), INT8_C( -55), INT8_C(  84), INT8_C( -92), INT8_C( -66), INT8_C(   7), INT8_C(  21)),
      simde_mm_set_pi8(INT8_C(-113), INT8_C( -67), INT8_C( -55), INT8_C(  84), INT8_C( -92), INT8_C( -66), INT8_C(   7), INT8_C(  21)),
      simde_mm_set_pi8(INT8_C(  -1), INT8_C(  -1), INT8_C(  -1), INT8_C(  -1), INT8_C(  -1), INT8_C(  -1), INT8_C(  -1), INT8_C(  -1)) },
    { simde_mm_set_pi8(INT8_C( -72), INT8_C( -56), INT8_C(-104), INT8_C(  -6), INT8_C(  37), INT8_C(-114), INT8_C(  84), INT8_C(  21)),
      simde_mm_set_pi8(INT8_C(  77), INT8_C( -25), INT8_C(-104), INT8_C(   0), INT8_C( -39), INT8_C(  38), INT8_C( -54), INT8_C( -90)),
      simde_mm_set_pi8(INT8_C(   0), INT8_C(   0), INT8_C(  -1), INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0)) },
    { simde_mm_set_pi8(INT8_C(  46), INT8_C( 120), INT8_C( -13), INT8_C(-125), INT8_C(  50), INT8_C(  10), INT8_C( 120), INT8_C( -10)),
      simde_mm_set_pi8(INT8_C(  85), INT8_C(  89), INT8_C(   9), INT8_C(  65), INT8_C( -82), INT8_C( -80), INT8_C(  65), INT8_C( -65)),
      simde_mm_set_pi8(INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0)) },
    { simde_mm_set_pi8(INT8_C( -12), INT8_C( -41), INT8_C( -54), INT8_C(  92), INT8_C( -87), INT8_C( -82), INT8_C(-120), INT8_C(  37)),
      simde_mm_set_pi8(INT8_C(  94), INT8_C( -21), INT8_C(  36), INT8_C(-121), INT8_C( -62), INT8_C(  -4), INT8_C(  42), INT8_C(-119)),
      simde_mm_set_pi8(INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0)) },
    { simde_mm_set_pi8(INT8_C(  -8), INT8_C( -60), INT8_C(  35), INT8_C( -31), INT8_C(-103), INT8_C(  -7), INT8_C( -39), INT8_C(  47)),
      simde_mm_set_pi8(INT8_C(  13), INT8_C( -84), INT8_C(-126), INT8_C(-127), INT8_C( -82), INT8_C(  37), INT8_C(  60), INT8_C(  30)),
      simde_mm_set_pi8(INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m64 r = simde_mm_cmpeq_pi8(test_vec[i].a, test_vec[i].b);
    simde_mm_empty();
    simde_assert_m64_i8(r, ==, test_vec[i].r);
  }

  simde_mm_empty();
  return MUNIT_OK;
}

static MunitResult
test_simde_mm_cmpeq_pi16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m64 a;
    simde__m64 b;
    simde__m64 r;
  } test_vec[8] = {
    { simde_mm_set_pi16(INT16_C( -13903), INT16_C( -28259), INT16_C(  10786), INT16_C(  24518)),
      simde_mm_set_pi16(INT16_C(   5267), INT16_C(   1924), INT16_C(  13281), INT16_C( -25055)),
      simde_mm_set_pi16(INT16_C(      0), INT16_C(      0), INT16_C(      0), INT16_C(      0)) },
    { simde_mm_set_pi16(INT16_C( -21949), INT16_C( -13483), INT16_C(   -390), INT16_C(   6377)),
      simde_mm_set_pi16(INT16_C(  -9583), INT16_C(   6876), INT16_C(  23768), INT16_C(   6209)),
      simde_mm_set_pi16(INT16_C(      0), INT16_C(      0), INT16_C(      0), INT16_C(      0)) },
    { simde_mm_set_pi16(INT16_C(  11364), INT16_C(  28383), INT16_C(  13353), INT16_C(  14261)),
      simde_mm_set_pi16(INT16_C(  13422), INT16_C(  32033), INT16_C(   4055), INT16_C(   5623)),
      simde_mm_set_pi16(INT16_C(      0), INT16_C(      0), INT16_C(      0), INT16_C(      0)) },
    { simde_mm_set_pi16(INT16_C(    206), INT16_C(  -1567), INT16_C( -17153), INT16_C(  18166)),
      simde_mm_set_pi16(INT16_C(  30519), INT16_C(  30643), INT16_C(  32735), INT16_C(  -4195)),
      simde_mm_set_pi16(INT16_C(      0), INT16_C(      0), INT16_C(      0), INT16_C(      0)) },
    { simde_mm_set_pi16(INT16_C(  25406), INT16_C( -18343), INT16_C( -15870), INT16_C( -15505)),
      simde_mm_set_pi16(INT16_C(  25406), INT16_C( -18343), INT16_C( -15870), INT16_C( -15505)),
      simde_mm_set_pi16(INT16_C(     -1), INT16_C(     -1), INT16_C(     -1), INT16_C(     -1)) },
    { simde_mm_set_pi16(INT16_C(  21393), INT16_C(  22815), INT16_C(    322), INT16_C(   9608)),
      simde_mm_set_pi16(INT16_C(  23953), INT16_C( -31672), INT16_C(  -7546), INT16_C(  31996)),
      simde_mm_set_pi16(INT16_C(      0), INT16_C(      0), INT16_C(      0), INT16_C(      0)) },
    { simde_mm_set_pi16(INT16_C( -16506), INT16_C(   -921), INT16_C( -32189), INT16_C(  18444)),
      simde_mm_set_pi16(INT16_C( -10340), INT16_C( -28110), INT16_C(  24057), INT16_C(  -7047)),
      simde_mm_set_pi16(INT16_C(      0), INT16_C(      0), INT16_C(      0), INT16_C(      0)) },
    { simde_mm_set_pi16(INT16_C(  -1173), INT16_C( -25844), INT16_C( -10729), INT16_C(  22121)),
      simde_mm_set_pi16(INT16_C(  25970), INT16_C(  12718), INT16_C(  25424), INT16_C(  11867)),
      simde_mm_set_pi16(INT16_C(      0), INT16_C(      0), INT16_C(      0), INT16_C(      0)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m64 r = simde_mm_cmpeq_pi16(test_vec[i].a, test_vec[i].b);
    simde_mm_empty();
    simde_assert_m64_u16(r, ==, test_vec[i].r);
  }

  simde_mm_empty();
  return MUNIT_OK;
}

static MunitResult
test_simde_mm_cmpeq_pi32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m64 a;
    simde__m64 b;
    simde__m64 r;
  } test_vec[8] = {
    { simde_mm_set_pi32(INT32_C(  -883578301), INT32_C(   417988218)),
      simde_mm_set_pi32(INT32_C(   450681489), INT32_C(   406936792)),
      simde_mm_set_pi32(INT32_C(           0), INT32_C(           0)) },
    { simde_mm_set_pi32(INT32_C(  1860119652), INT32_C(   934622249)),
      simde_mm_set_pi32(INT32_C(  2099328110), INT32_C(   368512983)),
      simde_mm_set_pi32(INT32_C(           0), INT32_C(           0)) },
    { simde_mm_set_pi32(INT32_C(  -102694706), INT32_C(  1190575359)),
      simde_mm_set_pi32(INT32_C(  2008250167), INT32_C(  -274890785)),
      simde_mm_set_pi32(INT32_C(           0), INT32_C(           0)) },
    { simde_mm_set_pi32(INT32_C(   126096531), INT32_C( -1641991199)),
      simde_mm_set_pi32(INT32_C(   126096531), INT32_C( -1641991199)),
      simde_mm_set_pi32(INT32_C(          -1), INT32_C(          -1)) },
    { simde_mm_set_pi32(INT32_C( -1202101442), INT32_C( -1016086014)),
      simde_mm_set_pi32(INT32_C( -1034786090), INT32_C(  -993100857)),
      simde_mm_set_pi32(INT32_C(           0), INT32_C(           0)) },
    { simde_mm_set_pi32(INT32_C(  1495225233), INT32_C(   629670210)),
      simde_mm_set_pi32(INT32_C( -2075632239), INT32_C(  2096947846)),
      simde_mm_set_pi32(INT32_C(           0), INT32_C(           0)) },
    { simde_mm_set_pi32(INT32_C(   -60309626), INT32_C(  1208779331)),
      simde_mm_set_pi32(INT32_C( -1842161764), INT32_C(  -461808135)),
      simde_mm_set_pi32(INT32_C(           0), INT32_C(           0)) },
    { simde_mm_set_pi32(INT32_C( -1693648021), INT32_C(  1449776663)),
      simde_mm_set_pi32(INT32_C(   833512818), INT32_C(   777741136)),
      simde_mm_set_pi32(INT32_C(           0), INT32_C(           0)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m64 r = simde_mm_cmpeq_pi32(test_vec[i].a, test_vec[i].b);
    simde_mm_empty();
    simde_assert_m64_i32(r, ==, test_vec[i].r);
  }

  simde_mm_empty();
  return MUNIT_OK;
}

static MunitResult
test_simde_mm_cmpgt_pi8(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m64 a;
    simde__m64 b;
    simde__m64 r;
  } test_vec[8] = {
    { simde_mm_set_pi8(INT8_C( -77), INT8_C(  29), INT8_C( -34), INT8_C(-110), INT8_C( -78), INT8_C(  -8), INT8_C(  92), INT8_C(  44)),
      simde_mm_set_pi8(INT8_C( -57), INT8_C(  99), INT8_C( -10), INT8_C(  28), INT8_C(  46), INT8_C(  79), INT8_C( -76), INT8_C(  59)),
      simde_mm_set_pi8(INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(  -1), INT8_C(   0)) },
    { simde_mm_set_pi8(INT8_C(  96), INT8_C(  -9), INT8_C( -61), INT8_C(  46), INT8_C( 104), INT8_C(-105), INT8_C(  89), INT8_C(  48)),
      simde_mm_set_pi8(INT8_C( 109), INT8_C(  70), INT8_C(  13), INT8_C(  90), INT8_C(-116), INT8_C( -23), INT8_C(  10), INT8_C( -96)),
      simde_mm_set_pi8(INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(  -1), INT8_C(   0), INT8_C(  -1), INT8_C(  -1)) },
    { simde_mm_set_pi8(INT8_C( -24), INT8_C(  -2), INT8_C(  73), INT8_C(  36), INT8_C( -29), INT8_C( -70), INT8_C(  73), INT8_C(-121)),
      simde_mm_set_pi8(INT8_C(  17), INT8_C( -17), INT8_C(  77), INT8_C(  -2), INT8_C( 111), INT8_C(-111), INT8_C( -66), INT8_C( -30)),
      simde_mm_set_pi8(INT8_C(   0), INT8_C(  -1), INT8_C(   0), INT8_C(  -1), INT8_C(   0), INT8_C(  -1), INT8_C(  -1), INT8_C(   0)) },
    { simde_mm_set_pi8(INT8_C(  72), INT8_C(-102), INT8_C(-121), INT8_C(  41), INT8_C( -29), INT8_C(-100), INT8_C( -70), INT8_C(  82)),
      simde_mm_set_pi8(INT8_C( 101), INT8_C( 118), INT8_C(-110), INT8_C( -74), INT8_C( -57), INT8_C(  -2), INT8_C(  89), INT8_C( -16)),
      simde_mm_set_pi8(INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(  -1), INT8_C(  -1), INT8_C(   0), INT8_C(   0), INT8_C(  -1)) },
    { simde_mm_set_pi8(INT8_C(  64), INT8_C(   2), INT8_C(-118), INT8_C(  23), INT8_C( -88), INT8_C(-120), INT8_C(  61), INT8_C( 114)),
      simde_mm_set_pi8(INT8_C(  60), INT8_C(  91), INT8_C(  96), INT8_C( -22), INT8_C(  38), INT8_C(  49), INT8_C(  80), INT8_C( -29)),
      simde_mm_set_pi8(INT8_C(  -1), INT8_C(   0), INT8_C(   0), INT8_C(  -1), INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(  -1)) },
    { simde_mm_set_pi8(INT8_C(  31), INT8_C( -32), INT8_C(-121), INT8_C(   9), INT8_C(  80), INT8_C( 108), INT8_C(  29), INT8_C(   2)),
      simde_mm_set_pi8(INT8_C(-119), INT8_C(  33), INT8_C(   9), INT8_C( 101), INT8_C( 101), INT8_C(  79), INT8_C(  41), INT8_C(  87)),
      simde_mm_set_pi8(INT8_C(  -1), INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(  -1), INT8_C(   0), INT8_C(   0)) },
    { simde_mm_set_pi8(INT8_C(  96), INT8_C( -75), INT8_C(-121), INT8_C(-101), INT8_C(  10), INT8_C(-126), INT8_C(  58), INT8_C(  60)),
      simde_mm_set_pi8(INT8_C( 101), INT8_C( -73), INT8_C( 126), INT8_C( 105), INT8_C( -48), INT8_C(-119), INT8_C( -97), INT8_C( -90)),
      simde_mm_set_pi8(INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(  -1), INT8_C(   0), INT8_C(  -1), INT8_C(  -1)) },
    { simde_mm_set_pi8(INT8_C( 118), INT8_C( 118), INT8_C( -21), INT8_C( -49), INT8_C(  85), INT8_C(  69), INT8_C(  84), INT8_C( 111)),
      simde_mm_set_pi8(INT8_C( -96), INT8_C( 121), INT8_C(-110), INT8_C( -87), INT8_C( -73), INT8_C(  37), INT8_C(  45), INT8_C(-120)),
      simde_mm_set_pi8(INT8_C(  -1), INT8_C(   0), INT8_C(  -1), INT8_C(  -1), INT8_C(  -1), INT8_C(  -1), INT8_C(  -1), INT8_C(  -1)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m64 r = simde_mm_cmpgt_pi8(test_vec[i].a, test_vec[i].b);
    simde_mm_empty();
    simde_assert_m64_i8(r, ==, test_vec[i].r);
  }

  simde_mm_empty();
  return MUNIT_OK;
}

static MunitResult
test_simde_mm_cmpgt_pi16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m64 a;
    simde__m64 b;
    simde__m64 r;
  } test_vec[8] = {
    { simde_mm_set_pi16(INT16_C(  27287), INT16_C( -17445), INT16_C(   7868), INT16_C(  17731)),
      simde_mm_set_pi16(INT16_C( -32130), INT16_C( -12389), INT16_C( -15721), INT16_C( -10529)),
      simde_mm_set_pi16(INT16_C(     -1), INT16_C(      0), INT16_C(     -1), INT16_C(     -1)) },
    { simde_mm_set_pi16(INT16_C( -23331), INT16_C(  19282), INT16_C(  27710), INT16_C(   4608)),
      simde_mm_set_pi16(INT16_C( -32646), INT16_C(  -2319), INT16_C(  19710), INT16_C(  25425)),
      simde_mm_set_pi16(INT16_C(     -1), INT16_C(     -1), INT16_C(     -1), INT16_C(      0)) },
    { simde_mm_set_pi16(INT16_C(  29350), INT16_C( -12356), INT16_C( -18117), INT16_C( -29182)),
      simde_mm_set_pi16(INT16_C(  10015), INT16_C(  -4879), INT16_C(  30741), INT16_C(  -4144)),
      simde_mm_set_pi16(INT16_C(     -1), INT16_C(      0), INT16_C(      0), INT16_C(      0)) },
    { simde_mm_set_pi16(INT16_C(  30697), INT16_C(  -4215), INT16_C(  31556), INT16_C(  11913)),
      simde_mm_set_pi16(INT16_C( -27176), INT16_C(  17667), INT16_C( -30447), INT16_C(  -2179)),
      simde_mm_set_pi16(INT16_C(     -1), INT16_C(      0), INT16_C(     -1), INT16_C(     -1)) },
    { simde_mm_set_pi16(INT16_C(   9207), INT16_C(   4793), INT16_C( -24596), INT16_C(  10085)),
      simde_mm_set_pi16(INT16_C( -18727), INT16_C(   -929), INT16_C(   7051), INT16_C(   8853)),
      simde_mm_set_pi16(INT16_C(     -1), INT16_C(     -1), INT16_C(      0), INT16_C(     -1)) },
    { simde_mm_set_pi16(INT16_C(  22734), INT16_C(   5890), INT16_C(  -3490), INT16_C( -24930)),
      simde_mm_set_pi16(INT16_C(  23656), INT16_C(  14548), INT16_C(  31806), INT16_C( -18379)),
      simde_mm_set_pi16(INT16_C(      0), INT16_C(      0), INT16_C(      0), INT16_C(      0)) },
    { simde_mm_set_pi16(INT16_C( -28756), INT16_C(   2211), INT16_C( -15605), INT16_C( -32010)),
      simde_mm_set_pi16(INT16_C( -12192), INT16_C( -10879), INT16_C(  28731), INT16_C(   7911)),
      simde_mm_set_pi16(INT16_C(      0), INT16_C(     -1), INT16_C(      0), INT16_C(      0)) },
    { simde_mm_set_pi16(INT16_C(  -9646), INT16_C(  -8544), INT16_C(   -843), INT16_C(  12140)),
      simde_mm_set_pi16(INT16_C(   4324), INT16_C(  29706), INT16_C(  13667), INT16_C(  -9123)),
      simde_mm_set_pi16(INT16_C(      0), INT16_C(      0), INT16_C(      0), INT16_C(     -1)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m64 r = simde_mm_cmpgt_pi16(test_vec[i].a, test_vec[i].b);
    simde_mm_empty();
    simde_assert_m64_i16(r, ==, test_vec[i].r);
  }

  simde_mm_empty();
  return MUNIT_OK;
}

static MunitResult
test_simde_mm_cmpgt_pi32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m64 a;
    simde__m64 b;
    simde__m64 r;
  } test_vec[8] = {
    { simde_mm_set_pi32(INT32_C( -1143248233), INT32_C(  1162026684)),
      simde_mm_set_pi32(INT32_C(  -811892098), INT32_C(  -689978729)),
      simde_mm_set_pi32(INT32_C(           0), INT32_C(          -1)) },
    { simde_mm_set_pi32(INT32_C(  1263707357), INT32_C(   302017598)),
      simde_mm_set_pi32(INT32_C(  -151945094), INT32_C(  1666272510)),
      simde_mm_set_pi32(INT32_C(          -1), INT32_C(           0)) },
    { simde_mm_set_pi32(INT32_C(  -809733466), INT32_C( -1912424133)),
      simde_mm_set_pi32(INT32_C(  -319740129), INT32_C(  -271550443)),
      simde_mm_set_pi32(INT32_C(           0), INT32_C(           0)) },
    { simde_mm_set_pi32(INT32_C(  -276203543), INT32_C(   780761924)),
      simde_mm_set_pi32(INT32_C(  1157862872), INT32_C(  -142767855)),
      simde_mm_set_pi32(INT32_C(           0), INT32_C(          -1)) },
    { simde_mm_set_pi32(INT32_C(   314123255), INT32_C(   660971500)),
      simde_mm_set_pi32(INT32_C(   -60836135), INT32_C(   580197259)),
      simde_mm_set_pi32(INT32_C(          -1), INT32_C(          -1)) },
    { simde_mm_set_pi32(INT32_C(   386029774), INT32_C( -1633750434)),
      simde_mm_set_pi32(INT32_C(   953441384), INT32_C( -1204454338)),
      simde_mm_set_pi32(INT32_C(           0), INT32_C(           0)) },
    { simde_mm_set_pi32(INT32_C(   144936876), INT32_C( -2097757429)),
      simde_mm_set_pi32(INT32_C(  -712912800), INT32_C(   518484027)),
      simde_mm_set_pi32(INT32_C(          -1), INT32_C(           0)) },
    { simde_mm_set_pi32(INT32_C(  -559883694), INT32_C(   795671733)),
      simde_mm_set_pi32(INT32_C(  1946816740), INT32_C(  -597871261)),
      simde_mm_set_pi32(INT32_C(           0), INT32_C(          -1)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m64 r = simde_mm_cmpgt_pi32(test_vec[i].a, test_vec[i].b);
    simde_mm_empty();
    simde_assert_m64_i32(r, ==, test_vec[i].r);
  }

  simde_mm_empty();
  return MUNIT_OK;
}

static MunitResult
test_simde_mm_cvtm64_si64(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m64 a;
    int64_t r;
  } test_vec[8] = {
    { simde_x_mm_set_pi64(INT64_C( 2133233461862191637)),
      INT64_C( 2133233461862191637) },
    { simde_x_mm_set_pi64(INT64_C(-1973285463394951226)),
      INT64_C(-1973285463394951226) },
    { simde_x_mm_set_pi64(INT64_C(-5080660655112358315)),
      INT64_C(-5080660655112358315) },
    { simde_x_mm_set_pi64(INT64_C(-2729804181976621239)),
      INT64_C(-2729804181976621239) },
    { simde_x_mm_set_pi64(INT64_C( 2995193706671491592)),
      INT64_C( 2995193706671491592) },
    { simde_x_mm_set_pi64(INT64_C( 5468114770221852232)),
      INT64_C( 5468114770221852232) },
    { simde_x_mm_set_pi64(INT64_C( 8741870191125799000)),
      INT64_C( 8741870191125799000) },
    { simde_x_mm_set_pi64(INT64_C(-2719280269483103979)),
      INT64_C(-2719280269483103979) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    int64_t r = simde_mm_cvtm64_si64(test_vec[i].a);
    munit_assert_int64(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_cvtsi32_si64(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    int32_t a;
    simde__m64 r;
  } test_vec[8] = {
    { INT32_C( -1348583717), simde_mm_set_pi32(INT32_C(           0), INT32_C( -1348583717)) },
    { INT32_C(  -756715702), simde_mm_set_pi32(INT32_C(           0), INT32_C(  -756715702)) },
    { INT32_C( -1433924355), simde_mm_set_pi32(INT32_C(           0), INT32_C( -1433924355)) },
    { INT32_C( -1317069830), simde_mm_set_pi32(INT32_C(           0), INT32_C( -1317069830)) },
    { INT32_C(  1132090539), simde_mm_set_pi32(INT32_C(           0), INT32_C(  1132090539)) },
    { INT32_C( -1685122075), simde_mm_set_pi32(INT32_C(           0), INT32_C( -1685122075)) },
    { INT32_C(  -782778794), simde_mm_set_pi32(INT32_C(           0), INT32_C(  -782778794)) },
    { INT32_C( -1603608856), simde_mm_set_pi32(INT32_C(           0), INT32_C( -1603608856)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m64 r = simde_mm_cvtsi32_si64(test_vec[i].a);
    simde_mm_empty();
    simde_assert_m64_i32(r, ==, test_vec[i].r);
  }

  simde_mm_empty();
  return MUNIT_OK;
}

static MunitResult
test_simde_mm_cvtsi64_m64(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    int64_t a;
    simde__m64 r;
  } test_vec[8] = {
    { INT64_C( 2448316468135826021),
      simde_x_mm_set_pi64(INT64_C( 2448316468135826021)) },
    { INT64_C(-5945835882033612295),
      simde_x_mm_set_pi64(INT64_C(-5945835882033612295)) },
    { INT64_C( 5992090895212857513),
      simde_x_mm_set_pi64(INT64_C( 5992090895212857513)) },
    { INT64_C(-6796228402041923924),
      simde_x_mm_set_pi64(INT64_C(-6796228402041923924)) },
    { INT64_C(-8511645703056027592),
      simde_x_mm_set_pi64(INT64_C(-8511645703056027592)) },
    { INT64_C(-8723546203794185453),
      simde_x_mm_set_pi64(INT64_C(-8723546203794185453)) },
    { INT64_C( 4345402151036158873),
      simde_x_mm_set_pi64(INT64_C( 4345402151036158873)) },
    { INT64_C(-6661466122659936384),
      simde_x_mm_set_pi64(INT64_C(-6661466122659936384)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m64 r = simde_mm_cvtsi64_m64(test_vec[i].a);
    simde_mm_empty();
    simde_assert_m64_i32(r, ==, test_vec[i].r);
  }

  simde_mm_empty();
  return MUNIT_OK;
}

static MunitResult
test_simde_mm_cvtsi64_si32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m64 a;
    int32_t r;
  } test_vec[8] = {
    { simde_mm_set_pi32(INT32_C(  1382271190), INT32_C(   -17653840)), INT32_C(   -17653840), },
    { simde_mm_set_pi32(INT32_C(  2132466748), INT32_C( -1483731059)), INT32_C( -1483731059), },
    { simde_mm_set_pi32(INT32_C(  -822228698), INT32_C(  1004225555)), INT32_C(  1004225555), },
    { simde_mm_set_pi32(INT32_C(   558984757), INT32_C( -1886991323)), INT32_C( -1886991323), },
    { simde_mm_set_pi32(INT32_C(   927499451), INT32_C(  1754078566)), INT32_C(  1754078566), },
    { simde_mm_set_pi32(INT32_C( -1298862100), INT32_C( -1081030334)), INT32_C( -1081030334), },
    { simde_mm_set_pi32(INT32_C( -2034437538), INT32_C(  1272751087)), INT32_C(  1272751087), },
    { simde_mm_set_pi32(INT32_C( -1114400737), INT32_C(  1318901980)), INT32_C(  1318901980), }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    int32_t r = simde_mm_cvtsi64_si32(test_vec[i].a);
    simde_mm_empty();
    munit_assert_int32(r, ==, test_vec[i].r);
  }

  simde_mm_empty();
  return MUNIT_OK;
}

static MunitResult
test_simde_mm_madd_pi16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m64 a;
    simde__m64 b;
    simde__m64 r;
  } test_vec[8] = {
    { simde_mm_set_pi16(INT16_C( -30343), INT16_C( -26392), INT16_C(  12299), INT16_C(   4601)),
      simde_mm_set_pi16(INT16_C(   1486), INT16_C(  26809), INT16_C(   7836), INT16_C( -25805)),
      simde_mm_set_pi32(INT32_C(  -752632826), INT32_C(   -22353841)) },
    { simde_mm_set_pi16(INT16_C(   1890), INT16_C(  31305), INT16_C( -30077), INT16_C(   2552)),
      simde_mm_set_pi16(INT16_C( -26920), INT16_C( -29540), INT16_C(  15300), INT16_C(  26578)),
      simde_mm_set_pi32(INT32_C(  -975628500), INT32_C(  -392351044)) },
    { simde_mm_set_pi16(INT16_C(  22384), INT16_C(    696), INT16_C(  25907), INT16_C( -24876)),
      simde_mm_set_pi16(INT16_C( -11857), INT16_C(  27254), INT16_C( -31966), INT16_C(   7796)),
      simde_mm_set_pi32(INT32_C(  -246438304), INT32_C( -1022076458)) },
    { simde_mm_set_pi16(INT16_C(  29956), INT16_C(  -2269), INT16_C(   6641), INT16_C( -23007)),
      simde_mm_set_pi16(INT16_C(   8143), INT16_C(  30485), INT16_C(  15411), INT16_C( -14515)),
      simde_mm_set_pi32(INT32_C(   174761243), INT32_C(   436291056)) },
    { simde_mm_set_pi16(INT16_C(   7615), INT16_C(  20384), INT16_C(   5326), INT16_C( -12172)),
      simde_mm_set_pi16(INT16_C(  26893), INT16_C(  19452), INT16_C(   1570), INT16_C( -21018)),
      simde_mm_set_pi32(INT32_C(   601299763), INT32_C(   264192916)) },
    { simde_mm_set_pi16(INT16_C(  21548), INT16_C(   8299), INT16_C( -27943), INT16_C( -19629)),
      simde_mm_set_pi16(INT16_C(  -7799), INT16_C( -19736), INT16_C( -28205), INT16_C(  18816)),
      simde_mm_set_pi32(INT32_C(  -331841916), INT32_C(   418793051)) },
    { simde_mm_set_pi16(INT16_C( -14814), INT16_C( -21565), INT16_C(   4061), INT16_C(  32148)),
      simde_mm_set_pi16(INT16_C(  26150), INT16_C(  16339), INT16_C( -29106), INT16_C(   3765)),
      simde_mm_set_pi32(INT32_C(  -739736635), INT32_C(     2837754)) },
    { simde_mm_set_pi16(INT16_C( -14349), INT16_C(  29040), INT16_C(  10943), INT16_C( -14909)),
      simde_mm_set_pi16(INT16_C(   4672), INT16_C(  28858), INT16_C(   1393), INT16_C(   4521)),
      simde_mm_set_pi32(INT32_C(   770997792), INT32_C(   -52159990)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m64 r = simde_mm_madd_pi16(test_vec[i].a, test_vec[i].b);
    simde_mm_empty();
    simde_assert_m64_i32(r, ==, test_vec[i].r);
  }

  simde_mm_empty();
  return MUNIT_OK;
}

static MunitResult
test_simde_mm_mulhi_pi16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m64 a;
    simde__m64 b;
    simde__m64 r;
  } test_vec[8] = {
    { simde_mm_set_pi16(INT16_C(   8979), INT16_C(   5154), INT16_C( -16978), INT16_C(  30928)),
      simde_mm_set_pi16(INT16_C(    131), INT16_C( -26526), INT16_C( -28508), INT16_C(   3156)),
      simde_mm_set_pi16(INT16_C(     17), INT16_C(  -2087), INT16_C(   7385), INT16_C(   1489)) },
    { simde_mm_set_pi16(INT16_C( -20724), INT16_C( -32562), INT16_C(  -4287), INT16_C( -11994)),
      simde_mm_set_pi16(INT16_C(  -1407), INT16_C( -20477), INT16_C(   2350), INT16_C(  -5112)),
      simde_mm_set_pi16(INT16_C(    444), INT16_C(  10174), INT16_C(   -154), INT16_C(    935)) },
    { simde_mm_set_pi16(INT16_C( -19242), INT16_C( -20442), INT16_C( -24803), INT16_C(  26694)),
      simde_mm_set_pi16(INT16_C(  13233), INT16_C(  -6736), INT16_C(    457), INT16_C(  16731)),
      simde_mm_set_pi16(INT16_C(  -3886), INT16_C(   2101), INT16_C(   -173), INT16_C(   6814)) },
    { simde_mm_set_pi16(INT16_C(  -7830), INT16_C(  18993), INT16_C(   2047), INT16_C(  32735)),
      simde_mm_set_pi16(INT16_C(  17045), INT16_C( -23188), INT16_C( -16247), INT16_C(  -6369)),
      simde_mm_set_pi16(INT16_C(  -2037), INT16_C(  -6721), INT16_C(   -508), INT16_C(  -3182)) },
    { simde_mm_set_pi16(INT16_C( -20331), INT16_C(  -1771), INT16_C(   7319), INT16_C(  -2172)),
      simde_mm_set_pi16(INT16_C(  27473), INT16_C(   3736), INT16_C(  26635), INT16_C( -24632)),
      simde_mm_set_pi16(INT16_C(  -8523), INT16_C(   -101), INT16_C(   2974), INT16_C(    816)) },
    { simde_mm_set_pi16(INT16_C(  18863), INT16_C(  29355), INT16_C(  22063), INT16_C(  24992)),
      simde_mm_set_pi16(INT16_C(  31646), INT16_C(  10850), INT16_C(  -1174), INT16_C(   6386)),
      simde_mm_set_pi16(INT16_C(   9108), INT16_C(   4859), INT16_C(   -396), INT16_C(   2435)) },
    { simde_mm_set_pi16(INT16_C(  12919), INT16_C(  27836), INT16_C( -15473), INT16_C(  31227)),
      simde_mm_set_pi16(INT16_C(  -2051), INT16_C(   6265), INT16_C( -13839), INT16_C(  14795)),
      simde_mm_set_pi16(INT16_C(   -405), INT16_C(   2661), INT16_C(   3267), INT16_C(   7049)) },
    { simde_mm_set_pi16(INT16_C( -20265), INT16_C(  -2387), INT16_C(   1893), INT16_C(  16606)),
      simde_mm_set_pi16(INT16_C(  31589), INT16_C(  -8123), INT16_C(  26642), INT16_C(   6982)),
      simde_mm_set_pi16(INT16_C(  -9768), INT16_C(    295), INT16_C(    769), INT16_C(   1769)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m64 r = simde_mm_mulhi_pi16(test_vec[i].a, test_vec[i].b);
    simde_mm_empty();
    simde_assert_m64_i16(r, ==, test_vec[i].r);
  }

  simde_mm_empty();
  return MUNIT_OK;
}

static MunitResult
test_simde_mm_mullo_pi16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m64 a;
    simde__m64 b;
    simde__m64 r;
  } test_vec[8] = {
    { simde_mm_set_pi16(INT16_C(   1243), INT16_C(  20416), INT16_C(  15667), INT16_C(   4430)),
      simde_mm_set_pi16(INT16_C(  -5775), INT16_C(  26694), INT16_C(  17028), INT16_C(  23537)),
      simde_mm_set_pi16(INT16_C(  30635), INT16_C( -12672), INT16_C( -19380), INT16_C(   1134)) },
    { simde_mm_set_pi16(INT16_C(  -5230), INT16_C( -20726), INT16_C( -32301), INT16_C(   4324)),
      simde_mm_set_pi16(INT16_C(  31416), INT16_C( -24870), INT16_C(  28490), INT16_C( -28474)),
      simde_mm_set_pi16(INT16_C(  -6928), INT16_C(  14980), INT16_C(   1022), INT16_C(  20568)) },
    { simde_mm_set_pi16(INT16_C(    359), INT16_C(  28315), INT16_C(  30109), INT16_C(  30370)),
      simde_mm_set_pi16(INT16_C(  11362), INT16_C( -24534), INT16_C(  -7779), INT16_C( -31174)),
      simde_mm_set_pi16(INT16_C(  15726), INT16_C(   1390), INT16_C(   7753), INT16_C( -21324)) },
    { simde_mm_set_pi16(INT16_C(  -7682), INT16_C( -17472), INT16_C(   1125), INT16_C( -30733)),
      simde_mm_set_pi16(INT16_C(  27323), INT16_C(  21286), INT16_C(  28332), INT16_C( -26848)),
      simde_mm_set_pi16(INT16_C(  16522), INT16_C(   7808), INT16_C(  23004), INT16_C(  21344)) },
    { simde_mm_set_pi16(INT16_C(  28468), INT16_C(  -4021), INT16_C(  23325), INT16_C( -24525)),
      simde_mm_set_pi16(INT16_C(  29242), INT16_C(  -5135), INT16_C(  12241), INT16_C(  -5671)),
      simde_mm_set_pi16(INT16_C(  22984), INT16_C(   3995), INT16_C( -19027), INT16_C(  13883)) },
    { simde_mm_set_pi16(INT16_C( -11233), INT16_C(  -9235), INT16_C( -23340), INT16_C(    -55)),
      simde_mm_set_pi16(INT16_C( -21567), INT16_C( -13689), INT16_C(  21540), INT16_C(  32686)),
      simde_mm_set_pi16(INT16_C( -24481), INT16_C(  -1029), INT16_C( -16944), INT16_C( -28258)) },
    { simde_mm_set_pi16(INT16_C(  24703), INT16_C( -27133), INT16_C(  13289), INT16_C(  20833)),
      simde_mm_set_pi16(INT16_C( -32748), INT16_C(  15704), INT16_C(  10635), INT16_C( -13911)),
      simde_mm_set_pi16(INT16_C(   2540), INT16_C(  18440), INT16_C( -32637), INT16_C(  -7671)) },
    { simde_mm_set_pi16(INT16_C( -20397), INT16_C( -17293), INT16_C(  -2038), INT16_C( -24305)),
      simde_mm_set_pi16(INT16_C( -25280), INT16_C(   2678), INT16_C( -17798), INT16_C(  10227)),
      simde_mm_set_pi16(INT16_C(  -1088), INT16_C(  23298), INT16_C(  30916), INT16_C(  10813)), }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m64 r = simde_mm_mullo_pi16(test_vec[i].a, test_vec[i].b);
    simde_mm_empty();
    simde_assert_m64_i16(r, ==, test_vec[i].r);
  }

  simde_mm_empty();
  return MUNIT_OK;
}

static MunitResult
test_simde_mm_or_si64(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m64 a;
    simde__m64 b;
    simde__m64 r;
  } test_vec[8] = {
    { simde_mm_set_pi32(INT32_C( -891509218), INT32_C(-1564843089)),
      simde_mm_set_pi32(INT32_C( -653544563), INT32_C(-1696113634)),
      simde_mm_set_pi32(INT32_C(  332862867), INT32_C(  945635249)) },
    { simde_mm_set_pi32(INT32_C(  534518332), INT32_C(  469703625)),
      simde_mm_set_pi32(INT32_C( 1926733937), INT32_C(-1778281838)),
      simde_mm_set_pi32(INT32_C( 1829485133), INT32_C(-1912698533)) },
    { simde_mm_set_pi32(INT32_C( 1838379192), INT32_C(-1012991609)),
      simde_mm_set_pi32(INT32_C(  513007439), INT32_C( -965007092)),
      simde_mm_set_pi32(INT32_C( 1929424887), INT32_C(   98947211)) },
    { simde_mm_set_pi32(INT32_C( -467260595), INT32_C( 1936608780)),
      simde_mm_set_pi32(INT32_C(-1713951633), INT32_C(-1838143667)),
      simde_mm_set_pi32(INT32_C( 2112948002), INT32_C( -518100671)) },
    { simde_mm_set_pi32(INT32_C(   -1074911), INT32_C( 1257024473)),
      simde_mm_set_pi32(INT32_C(  690851199), INT32_C( -673662530)),
      simde_mm_set_pi32(INT32_C( -691923874), INT32_C(-1657531801)) },
    { simde_mm_set_pi32(INT32_C( -124691463), INT32_C( -802403954)),
      simde_mm_set_pi32(INT32_C(-1515822997), INT32_C(-1488861756)),
      simde_mm_set_pi32(INT32_C( 1563900818), INT32_C( 2003668042)) },
    { simde_mm_set_pi32(INT32_C(  -30677319), INT32_C( -381566895)),
      simde_mm_set_pi32(INT32_C( 1588726708), INT32_C(  607880991)),
      simde_mm_set_pi32(INT32_C(-1600525043), INT32_C( -847624370)) },
    { simde_mm_set_pi32(INT32_C(  289587202), INT32_C(-1908682429)),
      simde_mm_set_pi32(INT32_C(  291676112), INT32_C(-1617544418)),
      simde_mm_set_pi32(INT32_C(    2121682), INT32_C(  296610397)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m64 r = simde_mm_xor_si64(test_vec[i].a, test_vec[i].b);
    simde_assert_m64_i32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_packs_pi16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m64 a;
    simde__m64 b;
    simde__m64 r;
  } test_vec[8] = {
    { simde_mm_set_pi16(INT16_C( -17383), INT16_C( -12181), INT16_C(  -2968), INT16_C(  26626)),
      simde_mm_set_pi16(INT16_C( -10040), INT16_C(  13688), INT16_C( -30953), INT16_C(  -4037)),
      simde_mm_set_pi8 (INT8_C(-128), INT8_C( 127), INT8_C(-128), INT8_C(-128),
                        INT8_C(-128), INT8_C(-128), INT8_C(-128), INT8_C( 127)) },
    { simde_mm_set_pi16(INT16_C( -20194), INT16_C(  12331), INT16_C( -23109), INT16_C(  25162)),
      simde_mm_set_pi16(INT16_C(  -1071), INT16_C(  20521), INT16_C(    860), INT16_C(   5875)),
      simde_mm_set_pi8 (INT8_C(-128), INT8_C( 127), INT8_C( 127), INT8_C( 127),
                        INT8_C(-128), INT8_C( 127), INT8_C(-128), INT8_C( 127)) },
    { simde_mm_set_pi16(INT16_C( -12255), INT16_C(  13277), INT16_C( -28950), INT16_C(   5253)),
      simde_mm_set_pi16(INT16_C(  25343), INT16_C(  -1252), INT16_C(   3561), INT16_C(   7538)),
      simde_mm_set_pi8 (INT8_C( 127), INT8_C(-128), INT8_C( 127), INT8_C( 127),
                        INT8_C(-128), INT8_C( 127), INT8_C(-128), INT8_C( 127)) },
    { simde_mm_set_pi16(INT16_C( -11251), INT16_C( -21118), INT16_C(  -2077), INT16_C( -20336)),
      simde_mm_set_pi16(INT16_C(  23412), INT16_C(   7898), INT16_C(  -3571), INT16_C(   9242)),
      simde_mm_set_pi8 (INT8_C( 127), INT8_C( 127), INT8_C(-128), INT8_C( 127),
                        INT8_C(-128), INT8_C(-128), INT8_C(-128), INT8_C(-128)) },
    { simde_mm_set_pi16(INT16_C(  28180), INT16_C(  25339), INT16_C(  20328), INT16_C(   3051)),
      simde_mm_set_pi16(INT16_C(  31135), INT16_C(   3581), INT16_C(  11552), INT16_C(  25034)),
      simde_mm_set_pi8 (INT8_C( 127), INT8_C( 127), INT8_C( 127), INT8_C( 127),
                        INT8_C( 127), INT8_C( 127), INT8_C( 127), INT8_C( 127)) },
    { simde_mm_set_pi16(INT16_C(  14129), INT16_C(  -2982), INT16_C( -13260), INT16_C( -12225)),
      simde_mm_set_pi16(INT16_C(   -557), INT16_C( -14564), INT16_C( -28065), INT16_C(  25636)),
      simde_mm_set_pi8 (INT8_C(-128), INT8_C(-128), INT8_C(-128), INT8_C( 127),
                        INT8_C( 127), INT8_C(-128), INT8_C(-128), INT8_C(-128)) },
    { simde_mm_set_pi16(INT16_C(  31333), INT16_C(  20796), INT16_C(  16795), INT16_C(  -5127)),
      simde_mm_set_pi16(INT16_C(  22060), INT16_C(  10681), INT16_C(  28763), INT16_C(   2847)),
      simde_mm_set_pi8 (INT8_C( 127), INT8_C( 127), INT8_C( 127), INT8_C( 127),
                        INT8_C( 127), INT8_C( 127), INT8_C( 127), INT8_C(-128)) },
    { simde_mm_set_pi16(INT16_C(    167), INT16_C(    233), INT16_C(    115), INT16_C(    126)),
      simde_mm_set_pi16(INT16_C(     10), INT16_C(     94), INT16_C(    181), INT16_C(    233)),
      simde_mm_set_pi8 (INT8_C(  10), INT8_C(  94), INT8_C( 127), INT8_C( 127),
                        INT8_C( 127), INT8_C( 127), INT8_C( 115), INT8_C( 126)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m64 r = simde_mm_packs_pi16(test_vec[i].a, test_vec[i].b);
    simde_mm_empty();
    simde_assert_m64_i8(r, ==, test_vec[i].r);
  }

  simde_mm_empty();
  return MUNIT_OK;
}

static MunitResult
test_simde_mm_packs_pi32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m64 a;
    simde__m64 b;
    simde__m64 r;
  } test_vec[8] = {
    { simde_mm_set_pi32(INT32_C(    -2875748), INT32_C(          -4)),
      simde_mm_set_pi32(INT32_C(         -53), INT32_C(      934884)),
      simde_mm_set_pi16(INT16_C(    -53), INT16_C(  32767), INT16_C( -32768), INT16_C(     -4)) },
    { simde_mm_set_pi32(INT32_C(           1), INT32_C(  -216790321)),
      simde_mm_set_pi32(INT32_C(         120), INT32_C(     -379925)),
      simde_mm_set_pi16(INT16_C(    120), INT16_C( -32768), INT16_C(      1), INT16_C( -32768)) },
    { simde_mm_set_pi32(INT32_C(         -18), INT32_C(         281)),
      simde_mm_set_pi32(INT32_C(      -33064), INT32_C(         130)),
      simde_mm_set_pi16(INT16_C( -32768), INT16_C(    130), INT16_C(    -18), INT16_C(    281)) },
    { simde_mm_set_pi32(INT32_C(      -51729), INT32_C(          14)),
      simde_mm_set_pi32(INT32_C(        6852), INT32_C(         -36)),
      simde_mm_set_pi16(INT16_C(   6852), INT16_C(    -36), INT16_C( -32768), INT16_C(     14)) },
    { simde_mm_set_pi32(INT32_C(          -1), INT32_C(        -210)),
      simde_mm_set_pi32(INT32_C(     3024991), INT32_C(    30957735)),
      simde_mm_set_pi16(INT16_C(  32767), INT16_C(  32767), INT16_C(     -1), INT16_C(   -210)) },
    { simde_mm_set_pi32(INT32_C(          28), INT32_C(         890)),
      simde_mm_set_pi32(INT32_C(    -2031601), INT32_C(       -5309)),
      simde_mm_set_pi16(INT16_C( -32768), INT16_C(  -5309), INT16_C(     28), INT16_C(    890)) },
    { simde_mm_set_pi32(INT32_C(         -80), INT32_C(     4267394)),
      simde_mm_set_pi32(INT32_C(    34757305), INT32_C(      127105)),
      simde_mm_set_pi16(INT16_C(  32767), INT16_C(  32767), INT16_C(    -80), INT16_C(  32767)) },
    { simde_mm_set_pi32(INT32_C(    -2773123), INT32_C(         -42)),
      simde_mm_set_pi32(INT32_C(          33), INT32_C(     3534549)),
      simde_mm_set_pi16(INT16_C(     33), INT16_C(  32767), INT16_C( -32768), INT16_C(    -42)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m64 r = simde_mm_packs_pi32(test_vec[i].a, test_vec[i].b);
    simde_mm_empty();
    simde_assert_m64_i16(r, ==, test_vec[i].r);
  }

  simde_mm_empty();
  return MUNIT_OK;
}

static MunitResult
test_simde_mm_packs_pu16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m64 a;
    simde__m64 b;
    simde__m64 r;
  } test_vec[8] = {
    { simde_mm_set_pi16(INT16_C(     -2), INT16_C(    113), INT16_C(     49), INT16_C(   -647)),
      simde_mm_set_pi16(INT16_C(     56), INT16_C(      5), INT16_C(      1), INT16_C(    -54)),
      simde_mm_set_pi8 (INT8_C(  56), INT8_C(   5), INT8_C(   1), INT8_C(   0),
                        INT8_C(   0), INT8_C( 113), INT8_C(  49), INT8_C(   0)) },
    { simde_mm_set_pi16(INT16_C(     -1), INT16_C(   -206), INT16_C(  -1650), INT16_C(   -109)),
      simde_mm_set_pi16(INT16_C(  -3828), INT16_C(      2), INT16_C(    471), INT16_C(      2)),
      simde_mm_set_pi8 (INT8_C(   0), INT8_C(   2), INT8_C(  -1), INT8_C(   2),
                        INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0)) },
    { simde_mm_set_pi16(INT16_C(      3), INT16_C(     -2), INT16_C(    500), INT16_C(   -100)),
      simde_mm_set_pi16(INT16_C(  -1574), INT16_C(     -1), INT16_C(     -1), INT16_C(      2)),
      simde_mm_set_pi8 (INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   2),
                        INT8_C(   3), INT8_C(   0), INT8_C(  -1), INT8_C(   0)) },
    { simde_mm_set_pi16(INT16_C(    -13), INT16_C(   -217), INT16_C(   3305), INT16_C(    -10)),
      simde_mm_set_pi16(INT16_C(   -370), INT16_C(    181), INT16_C(      1), INT16_C(  -1434)),
      simde_mm_set_pi8 (INT8_C(   0), INT8_C( -75), INT8_C(   1), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(  -1), INT8_C(   0)) },
    { simde_mm_set_pi16(INT16_C(    867), INT16_C(    -63), INT16_C(  -1003), INT16_C(     13)),
      simde_mm_set_pi16(INT16_C( -29854), INT16_C(     -6), INT16_C(     33), INT16_C(      5)),
      simde_mm_set_pi8 (INT8_C(   0), INT8_C(   0), INT8_C(  33), INT8_C(   5),
                        INT8_C(  -1), INT8_C(   0), INT8_C(   0), INT8_C(  13)) },
    { simde_mm_set_pi16(INT16_C(    771), INT16_C(     -1), INT16_C(    -13), INT16_C(     -2)),
      simde_mm_set_pi16(INT16_C(    -65), INT16_C(     55), INT16_C(    295), INT16_C(  17510)),
      simde_mm_set_pi8 (INT8_C(   0), INT8_C(  55), INT8_C(  -1), INT8_C(  -1),
                        INT8_C(  -1), INT8_C(   0), INT8_C(   0), INT8_C(   0)) },
    { simde_mm_set_pi16(INT16_C(     50), INT16_C(  32337), INT16_C(     13), INT16_C(  20449)),
      simde_mm_set_pi16(INT16_C(   -897), INT16_C(   -113), INT16_C(  -3866), INT16_C( -15759)),
      simde_mm_set_pi8 (INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(  50), INT8_C(  -1), INT8_C(  13), INT8_C(  -1)) },
    { simde_mm_set_pi16(INT16_C(      0), INT16_C(   4501), INT16_C(    202), INT16_C(   9748)),
      simde_mm_set_pi16(INT16_C(     -2), INT16_C(     -1), INT16_C( -16348), INT16_C(  -6302)),
      simde_mm_set_pi8 (INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(  -1), INT8_C( -54), INT8_C(  -1)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m64 r = simde_mm_packs_pu16(test_vec[i].a, test_vec[i].b);
    simde_mm_empty();
    simde_assert_m64_u8(r, ==, test_vec[i].r);
  }

  simde_mm_empty();
  return MUNIT_OK;
}

static MunitResult
test_simde_mm_sll_pi16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m64 a;
    simde__m64 count;
    simde__m64 r;
  } test_vec[8] = {
    { simde_mm_set_pi16(INT16_C(  -2612), INT16_C(  -7275), INT16_C(  24980), INT16_C(  12744)),
      simde_mm_cvtsi64_m64(15),
      simde_mm_set_pi16(INT16_C(      0), INT16_C( -32768), INT16_C(      0), INT16_C(      0)) },
    { simde_mm_set_pi16(INT16_C(  17143), INT16_C( -12000), INT16_C(  32255), INT16_C(   5448)),
      simde_mm_cvtsi64_m64(10),
      simde_mm_set_pi16(INT16_C(  -9216), INT16_C( -32768), INT16_C(  -1024), INT16_C(   8192)) },
    { simde_mm_set_pi16(INT16_C(   1219), INT16_C( -18409), INT16_C(  24763), INT16_C(  13023)),
      simde_mm_cvtsi64_m64(3),
      simde_mm_set_pi16(INT16_C(   9752), INT16_C( -16200), INT16_C(   1496), INT16_C( -26888)) },
    { simde_mm_set_pi16(INT16_C( -30853), INT16_C(   -438), INT16_C( -13150), INT16_C(  -2468)),
      simde_mm_cvtsi64_m64(10),
      simde_mm_set_pi16(INT16_C(  -5120), INT16_C(  10240), INT16_C( -30720), INT16_C(  28672)) },
    { simde_mm_set_pi16(INT16_C( -20343), INT16_C(  30713), INT16_C(  26566), INT16_C(   9213)),
      simde_mm_cvtsi64_m64(7),
      simde_mm_set_pi16(INT16_C(  17536), INT16_C(   -896), INT16_C(  -7424), INT16_C(   -384)) },
    { simde_mm_set_pi16(INT16_C( -14337), INT16_C(  -4898), INT16_C(  32658), INT16_C(  -4944)),
      simde_mm_cvtsi64_m64(5),
      simde_mm_set_pi16(INT16_C(    -32), INT16_C( -25664), INT16_C(  -3520), INT16_C( -27136)) },
    { simde_mm_set_pi16(INT16_C(  21648), INT16_C(  25416), INT16_C(  19921), INT16_C( -16738)),
      simde_mm_cvtsi64_m64(0),
      simde_mm_set_pi16(INT16_C(  21648), INT16_C(  25416), INT16_C(  19921), INT16_C( -16738)) },
    { simde_mm_set_pi16(INT16_C( -10368), INT16_C( -19483), INT16_C( -15412), INT16_C( -29979)),
      simde_mm_cvtsi64_m64(9),
      simde_mm_set_pi16(INT16_C(      0), INT16_C( -13824), INT16_C( -26624), INT16_C( -13824)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m64 r = simde_mm_sll_pi16(test_vec[i].a, test_vec[i].count);
    simde_mm_empty();
    simde_assert_m64_i8(r, ==, test_vec[i].r);
  }

  simde_mm_empty();
  return MUNIT_OK;
}

static MunitResult
test_simde_mm_sll_pi32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m64 a;
    simde__m64 count;
    simde__m64 r;
  } test_vec[8] = {
    { simde_mm_set_pi32(INT32_C(  2135609954), INT32_C( -1662756041)),
      simde_mm_cvtsi64_m64(10),
      simde_mm_set_pi32(INT32_C(   726239232), INT32_C( -1855136768)) },
    { simde_mm_set_pi32(INT32_C(  1984991847), INT32_C(   -75949890)),
      simde_mm_cvtsi64_m64(14),
      simde_mm_set_pi32(INT32_C(   614055936), INT32_C(  1177518080)) },
    { simde_mm_set_pi32(INT32_C( -1315562518), INT32_C( -1717142831)),
      simde_mm_cvtsi64_m64(22),
      simde_mm_set_pi32(INT32_C(   -92274688), INT32_C( -1270874112)) },
    { simde_mm_set_pi32(INT32_C(  -814215595), INT32_C(   805054469)),
      simde_mm_cvtsi64_m64(9),
      simde_mm_set_pi32(INT32_C(  -266556928), INT32_C(  -128972288)) },
    { simde_mm_set_pi32(INT32_C( -1588862908), INT32_C(  2132697891)),
      simde_mm_cvtsi64_m64(1),
      simde_mm_set_pi32(INT32_C(  1117241480), INT32_C(   -29571514)) },
    { simde_mm_set_pi32(INT32_C(   782274620), INT32_C( -2120419106)),
      simde_mm_cvtsi64_m64(16),
      simde_mm_set_pi32(INT32_C( -1875116032), INT32_C(  -119668736)) },
    { simde_mm_set_pi32(INT32_C( -1687581332), INT32_C( -1263634481)),
      simde_mm_cvtsi64_m64(16),
      simde_mm_set_pi32(INT32_C( -1922301952), INT32_C(  2010054656)) },
    { simde_mm_set_pi32(INT32_C( -1258319564), INT32_C(   975343739)),
      simde_mm_cvtsi64_m64(5),
      simde_mm_set_pi32(INT32_C( -1611520384), INT32_C(  1146228576)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m64 r = simde_mm_sll_pi32(test_vec[i].a, test_vec[i].count);
    simde_mm_empty();
    simde_assert_m64_i8(r, ==, test_vec[i].r);
  }

  simde_mm_empty();
  return MUNIT_OK;
}

static MunitResult
test_simde_mm_sll_si64(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m64 a;
    simde__m64 count;
    simde__m64 r;
  } test_vec[8] = {
    { simde_mm_cvtsi64_m64(INT64_C(   3171924675130206313)),
      simde_mm_cvtsi64_m64(26),
      simde_mm_cvtsi64_m64(INT64_C(  -4688886433618853888)) },
    { simde_mm_cvtsi64_m64(INT64_C(   8810857393431583130)),
      simde_mm_cvtsi64_m64(35),
      simde_mm_cvtsi64_m64(INT64_C(   8135977920570064896)) },
    { simde_mm_cvtsi64_m64(INT64_C(   8253138385445189600)),
      simde_mm_cvtsi64_m64(60),
      simde_mm_cvtsi64_m64(INT64_C(                     0)) },
    { simde_mm_cvtsi64_m64(INT64_C(   -109691783123384247)),
      simde_mm_cvtsi64_m64(35),
      simde_mm_cvtsi64_m64(INT64_C(   4699016138212769792)) },
    { simde_mm_cvtsi64_m64(INT64_C(    797909880260215132)),
      simde_mm_cvtsi64_m64(19),
      simde_mm_cvtsi64_m64(INT64_C(   -686801717540421632)) },
    { simde_mm_cvtsi64_m64(INT64_C(  -2366434973696685665)),
      simde_mm_cvtsi64_m64(28),
      simde_mm_cvtsi64_m64(INT64_C(  -2410559835486552064)) },
    { simde_mm_cvtsi64_m64(INT64_C(   3032641446696114060)),
      simde_mm_cvtsi64_m64(28),
      simde_mm_cvtsi64_m64(INT64_C(   4618209939532283904)) },
    { simde_mm_cvtsi64_m64(INT64_C(   5741540145978860560)),
      simde_mm_cvtsi64_m64(44),
      simde_mm_cvtsi64_m64(INT64_C(   7944631217658265600)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m64 r = simde_mm_sll_si64(test_vec[i].a, test_vec[i].count);
    simde_mm_empty();
    simde_assert_m64_i8(r, ==, test_vec[i].r);
  }

  simde_mm_empty();
  return MUNIT_OK;
}

static MunitResult
test_simde_mm_slli_pi16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m64 a;
    int count;
    simde__m64 r;
  } test_vec[8] = {
    { simde_mm_set_pi16(INT16_C( -13543), INT16_C(   6360), INT16_C(  -1306), INT16_C(  -5948)),
      6,
      simde_mm_set_pi16(INT16_C( -14784), INT16_C(  13824), INT16_C( -18048), INT16_C(  12544)) },
    { simde_mm_set_pi16(INT16_C(   6506), INT16_C( -28533), INT16_C(   3988), INT16_C( -31210)),
      10,
      simde_mm_set_pi16(INT16_C( -22528), INT16_C(  11264), INT16_C(  20480), INT16_C(  22528)) },
    { simde_mm_set_pi16(INT16_C(  19388), INT16_C(  -4520), INT16_C(   9582), INT16_C(  11067)),
      9,
      simde_mm_set_pi16(INT16_C(  30720), INT16_C( -20480), INT16_C(  -9216), INT16_C(  30208)) },
    { simde_mm_set_pi16(INT16_C(  12000), INT16_C(  28876), INT16_C(  29834), INT16_C( -13742)),
      13,
      simde_mm_set_pi16(INT16_C(      0), INT16_C( -32768), INT16_C(  16384), INT16_C(  16384)) },
    { simde_mm_set_pi16(INT16_C(   4648), INT16_C(  -2151), INT16_C( -26641), INT16_C( -27659)),
      13,
      simde_mm_set_pi16(INT16_C(      0), INT16_C(   8192), INT16_C(  -8192), INT16_C( -24576)) },
    { simde_mm_set_pi16(INT16_C(  -2353), INT16_C(  20317), INT16_C(   7426), INT16_C(  24788)),
      8,
      simde_mm_set_pi16(INT16_C( -12544), INT16_C(  23808), INT16_C(    512), INT16_C( -11264)) },
    { simde_mm_set_pi16(INT16_C(  -6174), INT16_C(  31492), INT16_C(  28575), INT16_C( -20383)),
      1,
      simde_mm_set_pi16(INT16_C( -12348), INT16_C(  -2552), INT16_C(  -8386), INT16_C(  24770)) },
    { simde_mm_set_pi16(INT16_C( -30371), INT16_C(  17334), INT16_C(   2428), INT16_C(  -4558)),
      5,
      simde_mm_set_pi16(INT16_C(  11168), INT16_C(  30400), INT16_C(  12160), INT16_C( -14784)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m64 r = simde_mm_slli_pi16(test_vec[i].a, test_vec[i].count);
    simde_mm_empty();
    simde_assert_m64_i16(r, ==, test_vec[i].r);
  }

  simde_mm_empty();
  return MUNIT_OK;
}

static MunitResult
test_simde_mm_slli_pi32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m64 a;
    int count;
    simde__m64 r;
  } test_vec[8] = {
    { simde_mm_set_pi32(INT32_C(    83881529), INT32_C(  1357951601)),
      27,
      simde_mm_set_pi32(INT32_C(  -939524096), INT32_C( -2013265920)) },
    { simde_mm_set_pi32(INT32_C( -2138298674), INT32_C( -2019079679)),
      21,
      simde_mm_set_pi32(INT32_C(  -641728512), INT32_C(  1075838976)) },
    { simde_mm_set_pi32(INT32_C(  -281448798), INT32_C( -1557273316)),
      27,
      simde_mm_set_pi32(INT32_C(   268435456), INT32_C(  -536870912)) },
    { simde_mm_set_pi32(INT32_C( -1207542290), INT32_C(  -694741539)),
      7,
      simde_mm_set_pi32(INT32_C(    53409536), INT32_C(  1267396224)) },
    { simde_mm_set_pi32(INT32_C(   902716495), INT32_C(   943182057)),
      20,
      simde_mm_set_pi32(INT32_C(  -990904320), INT32_C(   244318208)) },
    { simde_mm_set_pi32(INT32_C(     7423865), INT32_C( -1974692036)),
      5,
      simde_mm_set_pi32(INT32_C(   237563680), INT32_C(  1234364288)) },
    { simde_mm_set_pi32(INT32_C(   174727032), INT32_C(  -891064659)),
      23,
      simde_mm_set_pi32(INT32_C( -1140850688), INT32_C(  1451229184)) },
    { simde_mm_set_pi32(INT32_C(   134754342), INT32_C( -1894000042)),
      27,
      simde_mm_set_pi32(INT32_C(   805306368), INT32_C( -1342177280)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m64 r = simde_mm_slli_pi32(test_vec[i].a, test_vec[i].count);
    simde_mm_empty();
    simde_assert_m64_i32(r, ==, test_vec[i].r);
  }

  simde_mm_empty();
  return MUNIT_OK;
}

static MunitResult
test_simde_mm_slli_si64(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m64 a;
    int count;
    simde__m64 r;
  } test_vec[8] = {
    { simde_mm_cvtsi64_m64(INT64_C(  -3655983719573882447)),
      37,
      simde_mm_cvtsi64_m64(INT64_C(   5043809618745098240)) },
    { simde_mm_cvtsi64_m64(INT64_C(   5373634195600553823)),
      49,
      simde_mm_cvtsi64_m64(INT64_C(   7979815589747097600)) },
    { simde_mm_cvtsi64_m64(INT64_C(    955832682335824267)),
      11,
      simde_mm_cvtsi64_m64(INT64_C(   2190461610555627520)) },
    { simde_mm_cvtsi64_m64(INT64_C(   4435237962953354472)),
      32,
      simde_mm_cvtsi64_m64(INT64_C(  -6041177681452597248)) },
    { simde_mm_cvtsi64_m64(INT64_C(    509713568463920999)),
      0,
      simde_mm_cvtsi64_m64(INT64_C(    509713568463920999)) },
    { simde_mm_cvtsi64_m64(INT64_C(   3092984209993521199)),
      24,
      simde_mm_cvtsi64_m64(INT64_C(  -4581130211545841664)) },
    { simde_mm_cvtsi64_m64(INT64_C(  -9034725437056781767)),
      38,
      simde_mm_cvtsi64_m64(INT64_C(   4817882106908639232)) },
    { simde_mm_cvtsi64_m64(INT64_C(   8352260709189542260)),
      34,
      simde_mm_cvtsi64_m64(INT64_C(  -8446635447710384128)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m64 r = simde_mm_slli_si64(test_vec[i].a, test_vec[i].count);
    simde_mm_empty();
    simde_assert_m64_i64(r, ==, test_vec[i].r);
  }

  simde_mm_empty();
  return MUNIT_OK;
}

static MunitResult
test_simde_mm_srl_pi16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m64 a;
    simde__m64 count;
    simde__m64 r;
  } test_vec[8] = {
    { simde_mm_set_pi16(INT16_C(  -3979), INT16_C( -30013), INT16_C(  22836), INT16_C(   7438)),
      simde_mm_cvtsi64_m64(5),
      simde_mm_set_pi16(INT16_C(   1923), INT16_C(   1110), INT16_C(    713), INT16_C(    232)) },
    { simde_mm_set_pi16(INT16_C( -17889), INT16_C( -31199), INT16_C(   2233), INT16_C(  29176)),
      simde_mm_cvtsi64_m64(9),
      simde_mm_set_pi16(INT16_C(     93), INT16_C(     67), INT16_C(      4), INT16_C(     56)) },
    { simde_mm_set_pi16(INT16_C( -14320), INT16_C( -29349), INT16_C(  -4712), INT16_C(   3031)),
      simde_mm_cvtsi64_m64(6),
      simde_mm_set_pi16(INT16_C(    800), INT16_C(    565), INT16_C(    950), INT16_C(     47)) },
    { simde_mm_set_pi16(INT16_C(  28706), INT16_C( -15113), INT16_C(  -3287), INT16_C( -13609)),
      simde_mm_cvtsi64_m64(13),
      simde_mm_set_pi16(INT16_C(      3), INT16_C(      6), INT16_C(      7), INT16_C(      6)) },
    { simde_mm_set_pi16(INT16_C(  -4348), INT16_C(  14324), INT16_C(  12491), INT16_C( -32763)),
      simde_mm_cvtsi64_m64(2),
      simde_mm_set_pi16(INT16_C(  15297), INT16_C(   3581), INT16_C(   3122), INT16_C(   8193)) },
    { simde_mm_set_pi16(INT16_C(  -1454), INT16_C(  -3136), INT16_C(  16900), INT16_C( -26266)),
      simde_mm_cvtsi64_m64(11),
      simde_mm_set_pi16(INT16_C(     31), INT16_C(     30), INT16_C(      8), INT16_C(     19)) },
    { simde_mm_set_pi16(INT16_C(  23032), INT16_C(  21033), INT16_C(   2074), INT16_C( -30320)),
      simde_mm_cvtsi64_m64(9),
      simde_mm_set_pi16(INT16_C(     44), INT16_C(     41), INT16_C(      4), INT16_C(     68)) },
    { simde_mm_set_pi16(INT16_C(   2403), INT16_C(   6070), INT16_C( -16381), INT16_C(  15198)),
      simde_mm_cvtsi64_m64(10),
      simde_mm_set_pi16(INT16_C(      2), INT16_C(      5), INT16_C(     48), INT16_C(     14)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m64 r = simde_mm_srl_pi16(test_vec[i].a, test_vec[i].count);
    simde_mm_empty();
    simde_assert_m64_i16(r, ==, test_vec[i].r);
  }

  simde_mm_empty();
  return MUNIT_OK;
}

static MunitResult
test_simde_mm_srl_pi32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m64 a;
    simde__m64 count;
    simde__m64 r;
  } test_vec[8] = {
    { simde_mm_set_pi32(INT32_C(  1162874425), INT32_C(   701403552)),
      simde_mm_cvtsi64_m64(12),
      simde_mm_set_pi32(INT32_C(      283904), INT32_C(      171241)) },
    { simde_mm_set_pi32(INT32_C( -1730008971), INT32_C(  1480718473)),
      simde_mm_cvtsi64_m64(7),
      simde_mm_set_pi32(INT32_C(    20038736), INT32_C(    11568113)) },
    { simde_mm_set_pi32(INT32_C( -2020652937), INT32_C(   -14094139)),
      simde_mm_cvtsi64_m64(9),
      simde_mm_set_pi32(INT32_C(     4442020), INT32_C(     8361080)) },
    { simde_mm_set_pi32(INT32_C(  1211264864), INT32_C(  -549692031)),
      simde_mm_cvtsi64_m64(13),
      simde_mm_set_pi32(INT32_C(      147859), INT32_C(      457186)) },
    { simde_mm_set_pi32(INT32_C(   526771625), INT32_C( -1372326605)),
      simde_mm_cvtsi64_m64(6),
      simde_mm_set_pi32(INT32_C(     8230806), INT32_C(    45666260)) },
    { simde_mm_set_pi32(INT32_C(   257774375), INT32_C(  1425803958)),
      simde_mm_cvtsi64_m64(0),
      simde_mm_set_pi32(INT32_C(   257774375), INT32_C(  1425803958)) },
    { simde_mm_set_pi32(INT32_C(   751075720), INT32_C( -1937798467)),
      simde_mm_cvtsi64_m64(6),
      simde_mm_set_pi32(INT32_C(    11735558), INT32_C(    36830762)) },
    { simde_mm_set_pi32(INT32_C(  -703624712), INT32_C(  1484883517)),
      simde_mm_cvtsi64_m64(14),
      simde_mm_set_pi32(INT32_C(      219198), INT32_C(       90630)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m64 r = simde_mm_srl_pi32(test_vec[i].a, test_vec[i].count);
    simde_mm_empty();
    simde_assert_m64_i32(r, ==, test_vec[i].r);
  }

  simde_mm_empty();
  return MUNIT_OK;
}

static MunitResult
test_simde_mm_srl_si64(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m64 a;
    simde__m64 count;
    simde__m64 r;
  } test_vec[8] = {
    { simde_mm_cvtsi64_m64(INT64_C(  -1550745422537000797)),
      simde_mm_cvtsi64_m64(27),
      simde_mm_cvtsi64_m64(INT64_C(          125884999716)) },
    { simde_mm_cvtsi64_m64(INT64_C(  -4905487896917789484)),
      simde_mm_cvtsi64_m64(51),
      simde_mm_cvtsi64_m64(INT64_C(                  6013)) },
    { simde_mm_cvtsi64_m64(INT64_C(    784798283774789910)),
      simde_mm_cvtsi64_m64(61),
      simde_mm_cvtsi64_m64(INT64_C(                     0)) },
    { simde_mm_cvtsi64_m64(INT64_C(  -7160969444731528566)),
      simde_mm_cvtsi64_m64(36),
      simde_mm_cvtsi64_m64(INT64_C(             164229635)) },
    { simde_mm_cvtsi64_m64(INT64_C(   -123534753035910002)),
      simde_mm_cvtsi64_m64(20),
      simde_mm_cvtsi64_m64(INT64_C(        17474374123262)) },
    { simde_mm_cvtsi64_m64(INT64_C(   5720385725637272506)),
      simde_mm_cvtsi64_m64(33),
      simde_mm_cvtsi64_m64(INT64_C(             665940545)) },
    { simde_mm_cvtsi64_m64(INT64_C(  -3398235017645277558)),
      simde_mm_cvtsi64_m64(63),
      simde_mm_cvtsi64_m64(INT64_C(                     1)) },
    { simde_mm_cvtsi64_m64(INT64_C(  -5355948413550293775)),
      simde_mm_cvtsi64_m64(7),
      simde_mm_cvtsi64_m64(INT64_C(    102271841094994201)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m64 r = simde_mm_srl_si64(test_vec[i].a, test_vec[i].count);
    simde_mm_empty();
    simde_assert_m64_i64(r, ==, test_vec[i].r);
  }

  simde_mm_empty();
  return MUNIT_OK;
}

static MunitResult
test_simde_mm_srli_pi16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m64 a;
    int count;
    simde__m64 r;
  } test_vec[8] = {
    { simde_mm_set_pi16(INT16_C( -15698), INT16_C( -32310), INT16_C(    339), INT16_C(   3496)),
      10,
      simde_mm_set_pi16(INT16_C(     48), INT16_C(     32), INT16_C(      0), INT16_C(      3)) },
    { simde_mm_set_pi16(INT16_C( -27263), INT16_C( -18160), INT16_C( -20487), INT16_C( -21173)),
      6,
      simde_mm_set_pi16(INT16_C(    598), INT16_C(    740), INT16_C(    703), INT16_C(    693)) },
    { simde_mm_set_pi16(INT16_C(  23805), INT16_C( -14941), INT16_C(   6558), INT16_C( -23896)),
      6,
      simde_mm_set_pi16(INT16_C(    371), INT16_C(    790), INT16_C(    102), INT16_C(    650)) },
    { simde_mm_set_pi16(INT16_C(  22534), INT16_C( -27358), INT16_C(  -9489), INT16_C( -15972)),
      7,
      simde_mm_set_pi16(INT16_C(    176), INT16_C(    298), INT16_C(    437), INT16_C(    387)) },
    { simde_mm_set_pi16(INT16_C(   2212), INT16_C( -29223), INT16_C( -19783), INT16_C(  -4105)),
      0,
      simde_mm_set_pi16(INT16_C(   2212), INT16_C( -29223), INT16_C( -19783), INT16_C(  -4105)) },
    { simde_mm_set_pi16(INT16_C(  24559), INT16_C( -21850), INT16_C( -30646), INT16_C(  21423)),
      14,
      simde_mm_set_pi16(INT16_C(      1), INT16_C(      2), INT16_C(      2), INT16_C(      1)) },
    { simde_mm_set_pi16(INT16_C(  -3241), INT16_C( -31506), INT16_C(   3662), INT16_C(  16805)),
      5,
      simde_mm_set_pi16(INT16_C(   1946), INT16_C(   1063), INT16_C(    114), INT16_C(    525)) },
    { simde_mm_set_pi16(INT16_C( -13677), INT16_C(   7117), INT16_C( -15559), INT16_C(  -8368)),
      14,
      simde_mm_set_pi16(INT16_C(      3), INT16_C(      0), INT16_C(      3), INT16_C(      3)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m64 r = simde_mm_srli_pi16(test_vec[i].a, test_vec[i].count);
    simde_mm_empty();
    simde_assert_m64_i16(r, ==, test_vec[i].r);
  }

  simde_mm_empty();
  return MUNIT_OK;
}

static MunitResult
test_simde_mm_srli_pi32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m64 a;
    int count;
    simde__m64 r;
  } test_vec[8] = {
    { simde_mm_set_pi32(INT32_C(   116105102), INT32_C(  -612588364)),
      14,
      simde_mm_set_pi32(INT32_C(        7086), INT32_C(      224754)) },
    { simde_mm_set_pi32(INT32_C(  -569249998), INT32_C(  1055993616)),
      8,
      simde_mm_set_pi32(INT32_C(    14553583), INT32_C(     4124975)) },
    { simde_mm_set_pi32(INT32_C(   851549428), INT32_C( -1334511981)),
      15,
      simde_mm_set_pi32(INT32_C(       25987), INT32_C(       90345)) },
    { simde_mm_set_pi32(INT32_C( -1526427094), INT32_C(   130645372)),
      14,
      simde_mm_set_pi32(INT32_C(      168978), INT32_C(        7973)) },
    { simde_mm_set_pi32(INT32_C( -1832776933), INT32_C(   -28796512)),
      0,
      simde_mm_set_pi32(INT32_C( -1832776933), INT32_C(   -28796512)) },
    { simde_mm_set_pi32(INT32_C( -1521422315), INT32_C(   230241179)),
      4,
      simde_mm_set_pi32(INT32_C(   173346561), INT32_C(    14390073)) },
    { simde_mm_set_pi32(INT32_C(   981909051), INT32_C(  -764766890)),
      15,
      simde_mm_set_pi32(INT32_C(       29965), INT32_C(      107733)) },
    { simde_mm_set_pi32(INT32_C( -1889202569), INT32_C(  1472716773)),
      10,
      simde_mm_set_pi32(INT32_C(     2349379), INT32_C(     1438199)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m64 r = simde_mm_srli_pi32(test_vec[i].a, test_vec[i].count);
    simde_mm_empty();
    simde_assert_m64_i32(r, ==, test_vec[i].r);
  }

  simde_mm_empty();
  return MUNIT_OK;
}

static MunitResult
test_simde_mm_srli_si64(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m64 a;
    int count;
    simde__m64 r;
  } test_vec[8] = {
    { simde_mm_cvtsi64_m64(INT64_C(  -8294501885901195762)),
      62,
      simde_mm_cvtsi64_m64(INT64_C(                     2)) },
    { simde_mm_cvtsi64_m64(INT64_C(   7027314223871146181)),
      7,
      simde_mm_cvtsi64_m64(INT64_C(     54900892373993329)) },
    { simde_mm_cvtsi64_m64(INT64_C(   2649805052949317833)),
      19,
      simde_mm_cvtsi64_m64(INT64_C(         5054102044962)) },
    { simde_mm_cvtsi64_m64(INT64_C(    778555941675423413)),
      12,
      simde_mm_cvtsi64_m64(INT64_C(       190077134198101)) },
    { simde_mm_cvtsi64_m64(INT64_C(   1453695186595163432)),
      17,
      simde_mm_cvtsi64_m64(INT64_C(        11090814106713)) },
    { simde_mm_cvtsi64_m64(INT64_C(    834539484136231083)),
      22,
      simde_mm_cvtsi64_m64(INT64_C(          198969718011)) },
    { simde_mm_cvtsi64_m64(INT64_C(   1883775849744838333)),
      12,
      simde_mm_cvtsi64_m64(INT64_C(       459906213316610)) },
    { simde_mm_cvtsi64_m64(INT64_C(   7946503469684399228)),
      61,
      simde_mm_cvtsi64_m64(INT64_C(                     3)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m64 r = simde_mm_srli_si64(test_vec[i].a, test_vec[i].count);
    simde_mm_empty();
    simde_assert_m64_i64(r, ==, test_vec[i].r);
  }

  simde_mm_empty();
  return MUNIT_OK;
}

static MunitResult
test_simde_mm_srai_pi16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m64 a;
    int count;
    simde__m64 r;
  } test_vec[8] = {
    { simde_mm_set_pi16(INT16_C( -32259), INT16_C( -10390), INT16_C(  28627), INT16_C(  18747)),
      6,
      simde_mm_set_pi16(INT16_C(   -505), INT16_C(   -163), INT16_C(    447), INT16_C(    292)) },
    { simde_mm_set_pi16(INT16_C(   -300), INT16_C(  -3262), INT16_C(  -2861), INT16_C( -11389)),
      15,
      simde_mm_set_pi16(INT16_C(     -1), INT16_C(     -1), INT16_C(     -1), INT16_C(     -1)) },
    { simde_mm_set_pi16(INT16_C(   6480), INT16_C( -15684), INT16_C(   3587), INT16_C(   7844)),
      2,
      simde_mm_set_pi16(INT16_C(   1620), INT16_C(  -3921), INT16_C(    896), INT16_C(   1961)) },
    { simde_mm_set_pi16(INT16_C(  -6044), INT16_C( -15946), INT16_C(   1721), INT16_C( -30273)),
      5,
      simde_mm_set_pi16(INT16_C(   -189), INT16_C(   -499), INT16_C(     53), INT16_C(   -947)) },
    { simde_mm_set_pi16(INT16_C(  24609), INT16_C(  14431), INT16_C(   1917), INT16_C( -13176)),
      13,
      simde_mm_set_pi16(INT16_C(      3), INT16_C(      1), INT16_C(      0), INT16_C(     -2)) },
    { simde_mm_set_pi16(INT16_C(  13575), INT16_C(  32610), INT16_C(  -4763), INT16_C(  10748)),
      12,
      simde_mm_set_pi16(INT16_C(      3), INT16_C(      7), INT16_C(     -2), INT16_C(      2)) },
    { simde_mm_set_pi16(INT16_C(  -2824), INT16_C(  28483), INT16_C( -23495), INT16_C( -17241)),
      11,
      simde_mm_set_pi16(INT16_C(     -2), INT16_C(     13), INT16_C(    -12), INT16_C(     -9)) },
    { simde_mm_set_pi16(INT16_C(  -5294), INT16_C(  29284), INT16_C(  -3542), INT16_C(  21806)),
      10,
      simde_mm_set_pi16(INT16_C(     -6), INT16_C(     28), INT16_C(     -4), INT16_C(     21)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m64 r = simde_mm_srai_pi16(test_vec[i].a, test_vec[i].count);
    simde_mm_empty();
    simde_assert_m64_i16(r, ==, test_vec[i].r);
  }

  simde_mm_empty();
  return MUNIT_OK;
}

static MunitResult
test_simde_mm_srai_pi32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m64 a;
    int count;
    simde__m64 r;
  } test_vec[8] = {
    { simde_mm_set_pi32(INT32_C( -2114070678), INT32_C(  1876117819)),
      6,
      simde_mm_set_pi32(INT32_C(   -33032355), INT32_C(    29314340)) },
    { simde_mm_set_pi32(INT32_C(   -19598526), INT32_C(  -187444349)),
      15,
      simde_mm_set_pi32(INT32_C(        -599), INT32_C(       -5721)) },
    { simde_mm_set_pi32(INT32_C(   424723132), INT32_C(   235085476)),
      2,
      simde_mm_set_pi32(INT32_C(   106180783), INT32_C(    58771369)) },
    { simde_mm_set_pi32(INT32_C(  -396049994), INT32_C(   112822719)),
      5,
      simde_mm_set_pi32(INT32_C(   -12376563), INT32_C(     3525709)) },
    { simde_mm_set_pi32(INT32_C(  1612789855), INT32_C(   125684872)),
      13,
      simde_mm_set_pi32(INT32_C(      196873), INT32_C(       15342)) },
    { simde_mm_set_pi32(INT32_C(   889683810), INT32_C(  -312137220)),
      12,
      simde_mm_set_pi32(INT32_C(      217207), INT32_C(      -76206)) },
    { simde_mm_set_pi32(INT32_C(  -185045181), INT32_C( -1539720025)),
      11,
      simde_mm_set_pi32(INT32_C(      -90355), INT32_C(     -751817)) },
    { simde_mm_set_pi32(INT32_C(  -346918300), INT32_C(  -232106706)),
      10,
      simde_mm_set_pi32(INT32_C(     -338788), INT32_C(     -226667)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m64 r = simde_mm_srai_pi32(test_vec[i].a, test_vec[i].count);
    simde_mm_empty();
    simde_assert_m64_i32(r, ==, test_vec[i].r);
  }

  simde_mm_empty();
  return MUNIT_OK;
}

static MunitResult
test_simde_mm_sra_pi16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m64 a;
    simde__m64 count;
    simde__m64 r;
  } test_vec[8] = {
    { simde_mm_set_pi16(INT16_C(  17561), INT16_C(  10489), INT16_C( -28823), INT16_C( -32541)),
      simde_mm_cvtsi64_m64(11),
      simde_mm_set_pi16(INT16_C(      8), INT16_C(      5), INT16_C(    -15), INT16_C(    -16)) },
    { simde_mm_set_pi16(INT16_C( -23916), INT16_C(  22319), INT16_C( -24731), INT16_C( -24948)),
      simde_mm_cvtsi64_m64(6),
      simde_mm_set_pi16(INT16_C(   -374), INT16_C(    348), INT16_C(   -387), INT16_C(   -390)) },
    { simde_mm_set_pi16(INT16_C(  10305), INT16_C( -29863), INT16_C( -25929), INT16_C(  26582)),
      simde_mm_cvtsi64_m64(4),
      simde_mm_set_pi16(INT16_C(    644), INT16_C(  -1867), INT16_C(  -1621), INT16_C(   1661)) },
    { simde_mm_set_pi16(INT16_C( -11917), INT16_C(   7165), INT16_C(    860), INT16_C(  -7108)),
      simde_mm_cvtsi64_m64(3),
      simde_mm_set_pi16(INT16_C(  -1490), INT16_C(    895), INT16_C(    107), INT16_C(   -889)) },
    { simde_mm_set_pi16(INT16_C(  30600), INT16_C(   3146), INT16_C( -22841), INT16_C( -27601)),
      simde_mm_cvtsi64_m64(0),
      simde_mm_set_pi16(INT16_C(  30600), INT16_C(   3146), INT16_C( -22841), INT16_C( -27601)) },
    { simde_mm_set_pi16(INT16_C(   7952), INT16_C(   8542), INT16_C( -27736), INT16_C(  20289)),
      simde_mm_cvtsi64_m64(1),
      simde_mm_set_pi16(INT16_C(   3976), INT16_C(   4271), INT16_C( -13868), INT16_C(  10144)) },
    { simde_mm_set_pi16(INT16_C( -24594), INT16_C(  -8796), INT16_C( -25195), INT16_C(    300)),
      simde_mm_cvtsi64_m64(10),
      simde_mm_set_pi16(INT16_C(    -25), INT16_C(     -9), INT16_C(    -25), INT16_C(      0)) },
    { simde_mm_set_pi16(INT16_C(   9552), INT16_C(  20569), INT16_C(   1838), INT16_C(  26385)),
      simde_mm_cvtsi64_m64(9),
      simde_mm_set_pi16(INT16_C(     18), INT16_C(     40), INT16_C(      3), INT16_C(     51)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m64 r = simde_mm_sra_pi16(test_vec[i].a, test_vec[i].count);
    simde_mm_empty();
    simde_assert_m64_i16(r, ==, test_vec[i].r);
  }

  simde_mm_empty();
  return MUNIT_OK;
}

static MunitResult
test_simde_mm_sra_pi32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m64 a;
    simde__m64 count;
    simde__m64 r;
  } test_vec[8] = {
    { simde_mm_set_pi32(INT32_C( -1917317013), INT32_C( -1383526879)),
      simde_mm_cvtsi64_m64(15),
      simde_mm_set_pi32(INT32_C(      -58512), INT32_C(      -42222)) },
    { simde_mm_set_pi32(INT32_C(  -736945287), INT32_C(   858975517)),
      simde_mm_cvtsi64_m64(18),
      simde_mm_set_pi32(INT32_C(       -2812), INT32_C(        3276)) },
    { simde_mm_set_pi32(INT32_C(  1016725733), INT32_C( -1716419270)),
      simde_mm_cvtsi64_m64(20),
      simde_mm_set_pi32(INT32_C(         969), INT32_C(       -1637)) },
    { simde_mm_set_pi32(INT32_C(   884929023), INT32_C( -2109726169)),
      simde_mm_cvtsi64_m64(17),
      simde_mm_set_pi32(INT32_C(        6751), INT32_C(      -16096)) },
    { simde_mm_set_pi32(INT32_C(  1766981669), INT32_C(  1505895116)),
      simde_mm_cvtsi64_m64(8),
      simde_mm_set_pi32(INT32_C(     6902272), INT32_C(     5882402)) },
    { simde_mm_set_pi32(INT32_C(  1732469741), INT32_C( -2109399559)),
      simde_mm_cvtsi64_m64(22),
      simde_mm_set_pi32(INT32_C(         413), INT32_C(        -503)) },
    { simde_mm_set_pi32(INT32_C( -1207208411), INT32_C(   962459192)),
      simde_mm_cvtsi64_m64(24),
      simde_mm_set_pi32(INT32_C(         -72), INT32_C(          57)) },
    { simde_mm_set_pi32(INT32_C(   519578965), INT32_C(  1181576220)),
      simde_mm_cvtsi64_m64(2),
      simde_mm_set_pi32(INT32_C(   129894741), INT32_C(   295394055)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m64 r = simde_mm_sra_pi32(test_vec[i].a, test_vec[i].count);
    simde_mm_empty();
    simde_assert_m64_i32(r, ==, test_vec[i].r);
  }

  simde_mm_empty();
  return MUNIT_OK;
}

static MunitResult
test_simde_mm_sub_pi8(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m64 a;
    simde__m64 b;
    simde__m64 r;
  } test_vec[8] = {
    { simde_mm_set_pi8(INT8_C( -68), INT8_C(-128), INT8_C(-110), INT8_C( -46), INT8_C(  64), INT8_C( -87), INT8_C( 123), INT8_C(  83)),
      simde_mm_set_pi8(INT8_C( -44), INT8_C( -27), INT8_C(-126), INT8_C(  47), INT8_C(  -5), INT8_C( 124), INT8_C(-111), INT8_C(  88)),
      simde_mm_set_pi8(INT8_C( -24), INT8_C(-101), INT8_C(  16), INT8_C( -93), INT8_C(  69), INT8_C(  45), INT8_C( -22), INT8_C(  -5)) },
    { simde_mm_set_pi8(INT8_C(   7), INT8_C(  68), INT8_C( -53), INT8_C( -82), INT8_C(  50), INT8_C(-107), INT8_C( 109), INT8_C(  33)),
      simde_mm_set_pi8(INT8_C( 121), INT8_C(  50), INT8_C(  31), INT8_C(  80), INT8_C( 118), INT8_C(   8), INT8_C( -73), INT8_C(  38)),
      simde_mm_set_pi8(INT8_C(-114), INT8_C(  18), INT8_C( -84), INT8_C(  94), INT8_C( -68), INT8_C(-115), INT8_C( -74), INT8_C(  -5)) },
    { simde_mm_set_pi8(INT8_C(  60), INT8_C(   5), INT8_C(   4), INT8_C( -85), INT8_C( -61), INT8_C(  71), INT8_C( -19), INT8_C( -92)),
      simde_mm_set_pi8(INT8_C( -51), INT8_C( 118), INT8_C(  99), INT8_C(  14), INT8_C( 124), INT8_C(-115), INT8_C(  49), INT8_C(  19)),
      simde_mm_set_pi8(INT8_C( 111), INT8_C(-113), INT8_C( -95), INT8_C( -99), INT8_C(  71), INT8_C( -70), INT8_C( -68), INT8_C(-111)) },
    { simde_mm_set_pi8(INT8_C(  80), INT8_C(  47), INT8_C(  46), INT8_C( -13), INT8_C(  94), INT8_C( -69), INT8_C( -72), INT8_C( -28)),
      simde_mm_set_pi8(INT8_C(  45), INT8_C(  99), INT8_C(  14), INT8_C(   4), INT8_C(  89), INT8_C( -77), INT8_C(  -4), INT8_C( 109)),
      simde_mm_set_pi8(INT8_C(  35), INT8_C( -52), INT8_C(  32), INT8_C( -17), INT8_C(   5), INT8_C(   8), INT8_C( -68), INT8_C( 119)) },
    { simde_mm_set_pi8(INT8_C( 117), INT8_C(-101), INT8_C( -54), INT8_C( -50), INT8_C(  55), INT8_C( -97), INT8_C( -74), INT8_C(  79)),
      simde_mm_set_pi8(INT8_C( 116), INT8_C(  19), INT8_C(  84), INT8_C(  90), INT8_C( -15), INT8_C( -49), INT8_C(  34), INT8_C(-124)),
      simde_mm_set_pi8(INT8_C(   1), INT8_C(-120), INT8_C( 118), INT8_C( 116), INT8_C(  70), INT8_C( -48), INT8_C(-108), INT8_C( -53)) },
    { simde_mm_set_pi8(INT8_C(  43), INT8_C( -88), INT8_C(   7), INT8_C( -31), INT8_C( -45), INT8_C(  -6), INT8_C( -61), INT8_C( -47)),
      simde_mm_set_pi8(INT8_C(-110), INT8_C(  87), INT8_C(-102), INT8_C( -63), INT8_C( -35), INT8_C(  78), INT8_C(  96), INT8_C(  51)),
      simde_mm_set_pi8(INT8_C(-103), INT8_C(  81), INT8_C( 109), INT8_C(  32), INT8_C( -10), INT8_C( -84), INT8_C(  99), INT8_C( -98)) },
    { simde_mm_set_pi8(INT8_C(-113), INT8_C( -62), INT8_C(-117), INT8_C(  34), INT8_C( -40), INT8_C(  24), INT8_C( -20), INT8_C(  52)),
      simde_mm_set_pi8(INT8_C(  53), INT8_C( -16), INT8_C(  75), INT8_C(  38), INT8_C(   2), INT8_C( -75), INT8_C( -51), INT8_C(  92)),
      simde_mm_set_pi8(INT8_C(  90), INT8_C( -46), INT8_C(  64), INT8_C(  -4), INT8_C( -42), INT8_C(  99), INT8_C(  31), INT8_C( -40)) },
    { simde_mm_set_pi8(INT8_C( -94), INT8_C(  -1), INT8_C( -70), INT8_C(  90), INT8_C(-105), INT8_C( -20), INT8_C( -71), INT8_C( -95)),
      simde_mm_set_pi8(INT8_C( -97), INT8_C(  49), INT8_C(  71), INT8_C(  69), INT8_C( -48), INT8_C(  31), INT8_C( -19), INT8_C(  28)),
      simde_mm_set_pi8(INT8_C(   3), INT8_C( -50), INT8_C( 115), INT8_C(  21), INT8_C( -57), INT8_C( -51), INT8_C( -52), INT8_C(-123)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m64 r = simde_mm_sub_pi8(test_vec[i].a, test_vec[i].b);
    simde_mm_empty();
    simde_assert_m64_i8(r, ==, test_vec[i].r);
  }

  simde_mm_empty();
  return MUNIT_OK;
}

static MunitResult
test_simde_mm_sub_pi16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m64 a;
    simde__m64 b;
    simde__m64 r;
  } test_vec[8] = {
    { simde_mm_set_pi16(INT16_C( -19579), INT16_C(  12561), INT16_C(  18345), INT16_C(  16319)),
      simde_mm_set_pi16(INT16_C( -28282), INT16_C(  12811), INT16_C( -17042), INT16_C(  32694)),
      simde_mm_set_pi16(INT16_C(   8703), INT16_C(   -250), INT16_C( -30149), INT16_C( -16375)) },
    { simde_mm_set_pi16(INT16_C(  26389), INT16_C( -16440), INT16_C(  31193), INT16_C(  17420)),
      simde_mm_set_pi16(INT16_C( -16772), INT16_C( -30407), INT16_C(  13204), INT16_C(  -3950)),
      simde_mm_set_pi16(INT16_C( -22375), INT16_C(  13967), INT16_C(  17989), INT16_C(  21370)) },
    { simde_mm_set_pi16(INT16_C(  27021), INT16_C( -21341), INT16_C( -29765), INT16_C( -27825)),
      simde_mm_set_pi16(INT16_C(  32255), INT16_C( -11881), INT16_C( -17239), INT16_C(  17727)),
      simde_mm_set_pi16(INT16_C(  -5234), INT16_C(  -9460), INT16_C( -12526), INT16_C(  19984)) },
    { simde_mm_set_pi16(INT16_C(  -1061), INT16_C(  10691), INT16_C(   5402), INT16_C( -29779)),
      simde_mm_set_pi16(INT16_C(  -3105), INT16_C(  17443), INT16_C(  29683), INT16_C(  -4669)),
      simde_mm_set_pi16(INT16_C(   2044), INT16_C(  -6752), INT16_C( -24281), INT16_C( -25110)) },
    { simde_mm_set_pi16(INT16_C( -27429), INT16_C( -24038), INT16_C( -27170), INT16_C(  23974)),
      simde_mm_set_pi16(INT16_C(  26527), INT16_C( -23757), INT16_C(  12822), INT16_C(  25106)),
      simde_mm_set_pi16(INT16_C(  11580), INT16_C(   -281), INT16_C(  25544), INT16_C(  -1132)) },
    { simde_mm_set_pi16(INT16_C( -22000), INT16_C(  31301), INT16_C(   3019), INT16_C(   5319)),
      simde_mm_set_pi16(INT16_C(  17233), INT16_C(  -4995), INT16_C( -32364), INT16_C(  13233)),
      simde_mm_set_pi16(INT16_C(  26303), INT16_C( -29240), INT16_C( -30153), INT16_C(  -7914)) },
    { simde_mm_set_pi16(INT16_C(  -3486), INT16_C(  -1801), INT16_C(   6573), INT16_C(  -2443)),
      simde_mm_set_pi16(INT16_C(  12310), INT16_C(     34), INT16_C( -20082), INT16_C( -25128)),
      simde_mm_set_pi16(INT16_C( -15796), INT16_C(  -1835), INT16_C(  26655), INT16_C(  22685)) },
    { simde_mm_set_pi16(INT16_C(  -4220), INT16_C(  17506), INT16_C(   6973), INT16_C(  -8771)),
      simde_mm_set_pi16(INT16_C( -28953), INT16_C(  20334), INT16_C(  30681), INT16_C(  -3329)),
      simde_mm_set_pi16(INT16_C(  24733), INT16_C(  -2828), INT16_C( -23708), INT16_C(  -5442)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m64 r = simde_mm_sub_pi16(test_vec[i].a, test_vec[i].b);
    simde_mm_empty();
    simde_assert_m64_i16(r, ==, test_vec[i].r);
  }

  simde_mm_empty();
  return MUNIT_OK;
}

static MunitResult
test_simde_mm_sub_pi32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m64 a;
    simde__m64 b;
    simde__m64 r;
  } test_vec[8] = {
    { simde_mm_set_pi32(INT32_C(  1529386227), INT32_C(  -668097316)),
      simde_mm_set_pi32(INT32_C(   473233841), INT32_C(   -90529672)),
      simde_mm_set_pi32(INT32_C(  1056152386), INT32_C(  -577567644)) },
    { simde_mm_set_pi32(INT32_C( -1931729107), INT32_C(  -722204778)),
      simde_mm_set_pi32(INT32_C( -1308867233), INT32_C(  -379543807)),
      simde_mm_set_pi32(INT32_C(  -622861874), INT32_C(  -342660971)) },
    { simde_mm_set_pi32(INT32_C(  -291860960), INT32_C(  -190367090)),
      simde_mm_set_pi32(INT32_C(   135041259), INT32_C(  1788100299)),
      simde_mm_set_pi32(INT32_C(  -426902219), INT32_C( -1978467389)) },
    { simde_mm_set_pi32(INT32_C(  1883589163), INT32_C(   323765200)),
      simde_mm_set_pi32(INT32_C(   645555820), INT32_C(   651498122)),
      simde_mm_set_pi32(INT32_C(  1238033343), INT32_C(  -327732922)) },
    { simde_mm_set_pi32(INT32_C(  1636190981), INT32_C( -1768384078)),
      simde_mm_set_pi32(INT32_C(   292739084), INT32_C(   -81452554)),
      simde_mm_set_pi32(INT32_C(  1343451897), INT32_C( -1686931524)) },
    { simde_mm_set_pi32(INT32_C( -1203362066), INT32_C(  1430164168)),
      simde_mm_set_pi32(INT32_C(  1181972217), INT32_C( -1859714213)),
      simde_mm_set_pi32(INT32_C(  1909633013), INT32_C( -1005088915)) },
    { simde_mm_set_pi32(INT32_C(   -81132926), INT32_C(   156813953)),
      simde_mm_set_pi32(INT32_C(  1408689560), INT32_C( -1315494890)),
      simde_mm_set_pi32(INT32_C( -1489822486), INT32_C(  1472308843)) },
    { simde_mm_set_pi32(INT32_C(   -99259746), INT32_C( -1543487401)),
      simde_mm_set_pi32(INT32_C(  1211860803), INT32_C(   322815885)),
      simde_mm_set_pi32(INT32_C( -1311120549), INT32_C( -1866303286)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m64 r = simde_mm_sub_pi32(test_vec[i].a, test_vec[i].b);
    simde_mm_empty();
    simde_assert_m64_i32(r, ==, test_vec[i].r);
  }

  simde_mm_empty();
  return MUNIT_OK;
}

static MunitResult
test_simde_mm_subs_pi8(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m64 a;
    simde__m64 b;
    simde__m64 r;
  } test_vec[8] = {
    { simde_mm_set_pi8(INT8_C(  47), INT8_C( -51), INT8_C(  -9), INT8_C(  46), INT8_C(  37), INT8_C( 125), INT8_C(-121), INT8_C(  88)),
      simde_mm_set_pi8(INT8_C( -37), INT8_C( -59), INT8_C( -18), INT8_C( -39), INT8_C( -68), INT8_C( 127), INT8_C( -66), INT8_C( -14)),
      simde_mm_set_pi8(INT8_C(  84), INT8_C(   8), INT8_C(   9), INT8_C(  85), INT8_C( 105), INT8_C(  -2), INT8_C( -55), INT8_C( 102)) },
    { simde_mm_set_pi8(INT8_C( -68), INT8_C( 111), INT8_C(  54), INT8_C(  -2), INT8_C( -96), INT8_C( -30), INT8_C(   7), INT8_C(  -1)),
      simde_mm_set_pi8(INT8_C(  71), INT8_C( 109), INT8_C(  43), INT8_C( -28), INT8_C(-128), INT8_C( -98), INT8_C(  65), INT8_C( -86)),
      simde_mm_set_pi8(INT8_C(-128), INT8_C(   2), INT8_C(  11), INT8_C(  26), INT8_C(  32), INT8_C(  68), INT8_C( -58), INT8_C(  85)) },
    { simde_mm_set_pi8(INT8_C(-124), INT8_C(-105), INT8_C(  39), INT8_C(  68), INT8_C( -44), INT8_C( -60), INT8_C( -44), INT8_C( -99)),
      simde_mm_set_pi8(INT8_C(  -9), INT8_C(-127), INT8_C(  77), INT8_C( -14), INT8_C( -70), INT8_C( -39), INT8_C( -18), INT8_C( -40)),
      simde_mm_set_pi8(INT8_C(-115), INT8_C(  22), INT8_C( -38), INT8_C(  82), INT8_C(  26), INT8_C( -21), INT8_C( -26), INT8_C( -59)) },
    { simde_mm_set_pi8(INT8_C(  52), INT8_C(  33), INT8_C(  97), INT8_C(  39), INT8_C(-126), INT8_C( -11), INT8_C(  17), INT8_C( 108)),
      simde_mm_set_pi8(INT8_C(  65), INT8_C( 112), INT8_C( 108), INT8_C(  33), INT8_C(  68), INT8_C(-103), INT8_C( -45), INT8_C(   7)),
      simde_mm_set_pi8(INT8_C( -13), INT8_C( -79), INT8_C( -11), INT8_C(   6), INT8_C(-128), INT8_C(  92), INT8_C(  62), INT8_C( 101)) },
    { simde_mm_set_pi8(INT8_C(-105), INT8_C(  75), INT8_C( 127), INT8_C( -57), INT8_C(  88), INT8_C( -25), INT8_C( -75), INT8_C( -74)),
      simde_mm_set_pi8(INT8_C(-125), INT8_C( -81), INT8_C(  60), INT8_C(-108), INT8_C(  78), INT8_C( -60), INT8_C(  88), INT8_C(  30)),
      simde_mm_set_pi8(INT8_C(  20), INT8_C( 127), INT8_C(  67), INT8_C(  51), INT8_C(  10), INT8_C(  35), INT8_C(-128), INT8_C(-104)) },
    { simde_mm_set_pi8(INT8_C( -28), INT8_C( -97), INT8_C(  80), INT8_C( -43), INT8_C( -70), INT8_C(  45), INT8_C(  10), INT8_C( -67)),
      simde_mm_set_pi8(INT8_C(-109), INT8_C(  97), INT8_C(  25), INT8_C(  63), INT8_C( -65), INT8_C( -95), INT8_C(-111), INT8_C( -39)),
      simde_mm_set_pi8(INT8_C(  81), INT8_C(-128), INT8_C(  55), INT8_C(-106), INT8_C(  -5), INT8_C( 127), INT8_C( 121), INT8_C( -28)) },
    { simde_mm_set_pi8(INT8_C(  52), INT8_C( -18), INT8_C( -86), INT8_C( -29), INT8_C(  69), INT8_C(  92), INT8_C(  89), INT8_C( -66)),
      simde_mm_set_pi8(INT8_C(  16), INT8_C(   0), INT8_C(  95), INT8_C(  95), INT8_C( 115), INT8_C( -53), INT8_C(  55), INT8_C(  75)),
      simde_mm_set_pi8(INT8_C(  36), INT8_C( -18), INT8_C(-128), INT8_C(-124), INT8_C( -46), INT8_C( 127), INT8_C(  34), INT8_C(-128)) },
    { simde_mm_set_pi8(INT8_C(  99), INT8_C( -48), INT8_C(  16), INT8_C( 126), INT8_C(-110), INT8_C(-111), INT8_C( -66), INT8_C(  83)),
      simde_mm_set_pi8(INT8_C(-118), INT8_C( 118), INT8_C( 100), INT8_C(-121), INT8_C( -17), INT8_C(  74), INT8_C( -47), INT8_C( -77)),
      simde_mm_set_pi8(INT8_C( 127), INT8_C(-128), INT8_C( -84), INT8_C( 127), INT8_C( -93), INT8_C(-128), INT8_C( -19), INT8_C( 127)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m64 r = simde_mm_subs_pi8(test_vec[i].a, test_vec[i].b);
    simde_mm_empty();
    simde_assert_m64_i8(r, ==, test_vec[i].r);
  }

  simde_mm_empty();
  return MUNIT_OK;
}

static MunitResult
test_simde_mm_subs_pu8(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m64 a;
    simde__m64 b;
    simde__m64 r;
  } test_vec[8] = {
    { simde_mm_set_pi8(INT8_C( 108), INT8_C(-104), INT8_C( 106), INT8_C(  91), INT8_C(  54), INT8_C(  95), INT8_C( -86), INT8_C( -68)),
      simde_mm_set_pi8(INT8_C( -73), INT8_C( -12), INT8_C(  13), INT8_C(  -7), INT8_C(-102), INT8_C( -27), INT8_C( -93), INT8_C(  -1)),
      simde_mm_set_pi8(INT8_C(   0), INT8_C(   0), INT8_C(  93), INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   7), INT8_C(   0)) },
    { simde_mm_set_pi8(INT8_C(  -3), INT8_C(-122), INT8_C(-110), INT8_C( -87), INT8_C( -28), INT8_C( -38), INT8_C(  30), INT8_C( -22)),
      simde_mm_set_pi8(INT8_C( -24), INT8_C(  92), INT8_C( -83), INT8_C( -90), INT8_C(-108), INT8_C(-117), INT8_C( 101), INT8_C( -58)),
      simde_mm_set_pi8(INT8_C(  21), INT8_C(  42), INT8_C(   0), INT8_C(   3), INT8_C(  80), INT8_C(  79), INT8_C(   0), INT8_C(  36)) },
    { simde_mm_set_pi8(INT8_C( -50), INT8_C(  51), INT8_C(  -7), INT8_C( -68), INT8_C(  -7), INT8_C(  11), INT8_C(  15), INT8_C(   2)),
      simde_mm_set_pi8(INT8_C(  -4), INT8_C(-101), INT8_C(-106), INT8_C( -43), INT8_C(-124), INT8_C(   1), INT8_C( -19), INT8_C(  18)),
      simde_mm_set_pi8(INT8_C(   0), INT8_C(   0), INT8_C(  99), INT8_C(   0), INT8_C( 117), INT8_C(  10), INT8_C(   0), INT8_C(   0)) },
    { simde_mm_set_pi8(INT8_C(  20), INT8_C( -33), INT8_C( -99), INT8_C(  -4), INT8_C(-119), INT8_C(  72), INT8_C( 104), INT8_C( -43)),
      simde_mm_set_pi8(INT8_C( -27), INT8_C( 116), INT8_C( 127), INT8_C(  71), INT8_C( 110), INT8_C(  47), INT8_C(  56), INT8_C( -18)),
      simde_mm_set_pi8(INT8_C(   0), INT8_C( 107), INT8_C(  30), INT8_C( -75), INT8_C(  27), INT8_C(  25), INT8_C(  48), INT8_C(   0)) },
    { simde_mm_set_pi8(INT8_C(  24), INT8_C(  44), INT8_C( 126), INT8_C( -16), INT8_C(  48), INT8_C( 119), INT8_C( 122), INT8_C(  92)),
      simde_mm_set_pi8(INT8_C( -53), INT8_C(  93), INT8_C( 123), INT8_C(  43), INT8_C(  -1), INT8_C( -86), INT8_C(  12), INT8_C( -40)),
      simde_mm_set_pi8(INT8_C(   0), INT8_C(   0), INT8_C(   3), INT8_C( -59), INT8_C(   0), INT8_C(   0), INT8_C( 110), INT8_C(   0)) },
    { simde_mm_set_pi8(INT8_C(  43), INT8_C( -29), INT8_C(  72), INT8_C( -16), INT8_C(  73), INT8_C(  36), INT8_C(  38), INT8_C(-122)),
      simde_mm_set_pi8(INT8_C(  68), INT8_C(  17), INT8_C(-105), INT8_C( 112), INT8_C( 123), INT8_C(-118), INT8_C(  37), INT8_C(  35)),
      simde_mm_set_pi8(INT8_C(   0), INT8_C( -46), INT8_C(   0), INT8_C(-128), INT8_C(   0), INT8_C(   0), INT8_C(   1), INT8_C(  99)) },
    { simde_mm_set_pi8(INT8_C(  78), INT8_C(  25), INT8_C(-123), INT8_C(-114), INT8_C(  56), INT8_C(  33), INT8_C( -54), INT8_C(  46)),
      simde_mm_set_pi8(INT8_C( -71), INT8_C( 113), INT8_C( -52), INT8_C( -21), INT8_C(-112), INT8_C( -45), INT8_C( 117), INT8_C( -91)),
      simde_mm_set_pi8(INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(  85), INT8_C(   0)) },
    { simde_mm_set_pi8(INT8_C(  35), INT8_C(  56), INT8_C( 106), INT8_C( 118), INT8_C( -12), INT8_C( -92), INT8_C( -24), INT8_C(  93)),
      simde_mm_set_pi8(INT8_C(-118), INT8_C( -26), INT8_C( -47), INT8_C(  86), INT8_C( -69), INT8_C(  43), INT8_C( 117), INT8_C( 101)),
      simde_mm_set_pi8(INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(  32), INT8_C(  57), INT8_C( 121), INT8_C( 115), INT8_C(   0)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m64 r = simde_mm_subs_pu8(test_vec[i].a, test_vec[i].b);
    simde_mm_empty();
    simde_assert_m64_i8(r, ==, test_vec[i].r);
  }

  simde_mm_empty();
  return MUNIT_OK;
}

static MunitResult
test_simde_mm_subs_pi16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m64 a;
    simde__m64 b;
    simde__m64 r;
  } test_vec[8] = {
    { simde_mm_set_pi16(INT16_C(    997), INT16_C(  -2676), INT16_C( -29256), INT16_C( -21534)),
      simde_mm_set_pi16(INT16_C(  25057), INT16_C(  -8634), INT16_C(  14564), INT16_C(  23460)),
      simde_mm_set_pi16(INT16_C( -24060), INT16_C(   5958), INT16_C( -32768), INT16_C( -32768)) },
    { simde_mm_set_pi16(INT16_C(  17773), INT16_C( -21379), INT16_C( -10016), INT16_C( -25057)),
      simde_mm_set_pi16(INT16_C( -17494), INT16_C(  -5727), INT16_C( -23865), INT16_C( -12297)),
      simde_mm_set_pi16(INT16_C(  32767), INT16_C( -15652), INT16_C(  13849), INT16_C( -12760)) },
    { simde_mm_set_pi16(INT16_C( -18595), INT16_C( -25519), INT16_C(  25647), INT16_C(  18081)),
      simde_mm_set_pi16(INT16_C( -16730), INT16_C(   8578), INT16_C( -24195), INT16_C( -23138)),
      simde_mm_set_pi16(INT16_C(  -1865), INT16_C( -32768), INT16_C(  32767), INT16_C(  32767)) },
    { simde_mm_set_pi16(INT16_C(  30835), INT16_C(  -1900), INT16_C( -12465), INT16_C( -32273)),
      simde_mm_set_pi16(INT16_C(  22212), INT16_C(  29314), INT16_C(  30369), INT16_C(  -7474)),
      simde_mm_set_pi16(INT16_C(   8623), INT16_C( -31214), INT16_C( -32768), INT16_C( -24799)) },
    { simde_mm_set_pi16(INT16_C(  -4511), INT16_C( -11707), INT16_C(   -456), INT16_C(   4939)),
      simde_mm_set_pi16(INT16_C(   9564), INT16_C(  -6551), INT16_C(  15884), INT16_C(  25916)),
      simde_mm_set_pi16(INT16_C( -14075), INT16_C(  -5156), INT16_C( -16340), INT16_C( -20977)) },
    { simde_mm_set_pi16(INT16_C(  16747), INT16_C(  26115), INT16_C(  28725), INT16_C(  -9489)),
      simde_mm_set_pi16(INT16_C(  18589), INT16_C(  10790), INT16_C(  16046), INT16_C(   7670)),
      simde_mm_set_pi16(INT16_C(  -1842), INT16_C(  15325), INT16_C(  12679), INT16_C( -17159)) },
    { simde_mm_set_pi16(INT16_C(  12230), INT16_C(  31818), INT16_C( -20400), INT16_C(  29194)),
      simde_mm_set_pi16(INT16_C(  13624), INT16_C( -27762), INT16_C(  -3717), INT16_C(   9357)),
      simde_mm_set_pi16(INT16_C(  -1394), INT16_C(  32767), INT16_C( -16683), INT16_C(  19837)) },
    { simde_mm_set_pi16(INT16_C(   4223), INT16_C(  22129), INT16_C(  27682), INT16_C(   6112)),
      simde_mm_set_pi16(INT16_C(  25462), INT16_C(   1497), INT16_C( -20195), INT16_C( -31363)),
      simde_mm_set_pi16(INT16_C( -21239), INT16_C(  20632), INT16_C(  32767), INT16_C(  32767)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m64 r = simde_mm_subs_pi16(test_vec[i].a, test_vec[i].b);
    simde_mm_empty();
    simde_assert_m64_i16(r, ==, test_vec[i].r);
  }

  simde_mm_empty();
  return MUNIT_OK;
}

static MunitResult
test_simde_mm_subs_pu16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m64 a;
    simde__m64 b;
    simde__m64 r;
  } test_vec[8] = {
    { simde_mm_set_pi16(INT16_C( -14933), INT16_C(    874), INT16_C( -12812), INT16_C( -23674)),
      simde_mm_set_pi16(INT16_C(  10199), INT16_C( -21634), INT16_C( -16349), INT16_C(  -2233)),
      simde_mm_set_pi16(INT16_C( -25132), INT16_C(      0), INT16_C(   3537), INT16_C(      0)) },
    { simde_mm_set_pi16(INT16_C( -30411), INT16_C(  14403), INT16_C(  16019), INT16_C(  -7235)),
      simde_mm_set_pi16(INT16_C(  20809), INT16_C(  30553), INT16_C( -13348), INT16_C(  -9019)),
      simde_mm_set_pi16(INT16_C(  14316), INT16_C(      0), INT16_C(      0), INT16_C(   1784)) },
    { simde_mm_set_pi16(INT16_C(  -3263), INT16_C(  17129), INT16_C(   7120), INT16_C(  17541)),
      simde_mm_set_pi16(INT16_C(  17758), INT16_C( -24273), INT16_C( -16817), INT16_C( -26381)),
      simde_mm_set_pi16(INT16_C( -21021), INT16_C(      0), INT16_C(      0), INT16_C(      0)) },
    { simde_mm_set_pi16(INT16_C(  28253), INT16_C( -27429), INT16_C(  -2971), INT16_C( -25455)),
      simde_mm_set_pi16(INT16_C( -28858), INT16_C(  23971), INT16_C(  30194), INT16_C(  29959)),
      simde_mm_set_pi16(INT16_C(      0), INT16_C(  14136), INT16_C(  32371), INT16_C(  10122)) },
    { simde_mm_set_pi16(INT16_C(  -5264), INT16_C(  -5469), INT16_C(   2876), INT16_C(  12913)),
      simde_mm_set_pi16(INT16_C( -25438), INT16_C( -13476), INT16_C( -20493), INT16_C(   9684)),
      simde_mm_set_pi16(INT16_C(  20174), INT16_C(   8007), INT16_C(      0), INT16_C(   3229)) },
    { simde_mm_set_pi16(INT16_C(  -6406), INT16_C(  29502), INT16_C( -32502), INT16_C(  29440)),
      simde_mm_set_pi16(INT16_C(  24669), INT16_C(  29936), INT16_C( -12635), INT16_C( -28492)),
      simde_mm_set_pi16(INT16_C( -31075), INT16_C(      0), INT16_C(      0), INT16_C(      0)) },
    { simde_mm_set_pi16(INT16_C(   1295), INT16_C(  17975), INT16_C( -25873), INT16_C(  -8332)),
      simde_mm_set_pi16(INT16_C( -30157), INT16_C(    122), INT16_C( -20762), INT16_C(  12983)),
      simde_mm_set_pi16(INT16_C(      0), INT16_C(  17853), INT16_C(      0), INT16_C( -21315)) },
    { simde_mm_set_pi16(INT16_C( -17654), INT16_C( -28720), INT16_C( -25036), INT16_C(  -2408)),
      simde_mm_set_pi16(INT16_C(  32575), INT16_C(  13887), INT16_C(  23741), INT16_C( -32273)),
      simde_mm_set_pi16(INT16_C(  15307), INT16_C(  22929), INT16_C(  16759), INT16_C(  29865)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m64 r = simde_mm_subs_pu16(test_vec[i].a, test_vec[i].b);
    simde_mm_empty();
    simde_assert_m64_i16(r, ==, test_vec[i].r);
  }

  simde_mm_empty();
  return MUNIT_OK;
}

static MunitResult
test_simde_mm_unpackhi_pi8(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m64 a;
    simde__m64 b;
    simde__m64 r;
  } test_vec[8] = {
    { simde_mm_set_pi8(INT8_C(-127), INT8_C(  48), INT8_C(  42), INT8_C( 115), INT8_C( -77), INT8_C(   4), INT8_C(  25), INT8_C( -42)),
      simde_mm_set_pi8(INT8_C(  57), INT8_C(  92), INT8_C( -39), INT8_C( -42), INT8_C(  73), INT8_C(   4), INT8_C(  41), INT8_C( 118)),
      simde_mm_set_pi8(INT8_C(  57), INT8_C(-127), INT8_C(  92), INT8_C(  48), INT8_C( -39), INT8_C(  42), INT8_C( -42), INT8_C( 115)) },
    { simde_mm_set_pi8(INT8_C( -16), INT8_C( 120), INT8_C(  16), INT8_C( 116), INT8_C( -35), INT8_C(-100), INT8_C(   0), INT8_C( -39)),
      simde_mm_set_pi8(INT8_C(  63), INT8_C( -73), INT8_C(  48), INT8_C( -66), INT8_C( -33), INT8_C(-102), INT8_C( -62), INT8_C( 118)),
      simde_mm_set_pi8(INT8_C(  63), INT8_C( -16), INT8_C( -73), INT8_C( 120), INT8_C(  48), INT8_C(  16), INT8_C( -66), INT8_C( 116)) },
    { simde_mm_set_pi8(INT8_C( -24), INT8_C( -49), INT8_C(  20), INT8_C(  34), INT8_C(  -1), INT8_C(  63), INT8_C(  11), INT8_C( -36)),
      simde_mm_set_pi8(INT8_C( -97), INT8_C(  52), INT8_C(  62), INT8_C( -48), INT8_C( -15), INT8_C(  24), INT8_C(  18), INT8_C( -28)),
      simde_mm_set_pi8(INT8_C( -97), INT8_C( -24), INT8_C(  52), INT8_C( -49), INT8_C(  62), INT8_C(  20), INT8_C( -48), INT8_C(  34)) },
    { simde_mm_set_pi8(INT8_C(  34), INT8_C( -74), INT8_C( -88), INT8_C( -68), INT8_C(  80), INT8_C(  80), INT8_C( -27), INT8_C(-109)),
      simde_mm_set_pi8(INT8_C( -14), INT8_C(  17), INT8_C( -50), INT8_C(  50), INT8_C( -72), INT8_C(-111), INT8_C( -32), INT8_C(-114)),
      simde_mm_set_pi8(INT8_C( -14), INT8_C(  34), INT8_C(  17), INT8_C( -74), INT8_C( -50), INT8_C( -88), INT8_C(  50), INT8_C( -68)) },
    { simde_mm_set_pi8(INT8_C( -82), INT8_C(  34), INT8_C(  79), INT8_C(  75), INT8_C( -45), INT8_C(  43), INT8_C( -97), INT8_C(  55)),
      simde_mm_set_pi8(INT8_C( 126), INT8_C( 126), INT8_C( 113), INT8_C( 122), INT8_C(   7), INT8_C(  69), INT8_C(  31), INT8_C(  83)),
      simde_mm_set_pi8(INT8_C( 126), INT8_C( -82), INT8_C( 126), INT8_C(  34), INT8_C( 113), INT8_C(  79), INT8_C( 122), INT8_C(  75)) },
    { simde_mm_set_pi8(INT8_C(  -4), INT8_C( -98), INT8_C(   7), INT8_C(  88), INT8_C( -93), INT8_C(  56), INT8_C( -38), INT8_C( -15)),
      simde_mm_set_pi8(INT8_C(  75), INT8_C(  97), INT8_C(  76), INT8_C(  26), INT8_C(-119), INT8_C( -96), INT8_C( -74), INT8_C( -24)),
      simde_mm_set_pi8(INT8_C(  75), INT8_C(  -4), INT8_C(  97), INT8_C( -98), INT8_C(  76), INT8_C(   7), INT8_C(  26), INT8_C(  88)) },
    { simde_mm_set_pi8(INT8_C( 124), INT8_C(  71), INT8_C( -14), INT8_C(  19), INT8_C( -69), INT8_C( -31), INT8_C(  35), INT8_C( -82)),
      simde_mm_set_pi8(INT8_C( -31), INT8_C( 125), INT8_C(  35), INT8_C(  84), INT8_C( 105), INT8_C(-115), INT8_C(  11), INT8_C( -12)),
      simde_mm_set_pi8(INT8_C( -31), INT8_C( 124), INT8_C( 125), INT8_C(  71), INT8_C(  35), INT8_C( -14), INT8_C(  84), INT8_C(  19)) },
    { simde_mm_set_pi8(INT8_C(  45), INT8_C( -51), INT8_C( -71), INT8_C( -47), INT8_C( -27), INT8_C(  20), INT8_C(-117), INT8_C(  -5)),
      simde_mm_set_pi8(INT8_C( -92), INT8_C( -74), INT8_C(  58), INT8_C( 117), INT8_C( -53), INT8_C(  43), INT8_C(  66), INT8_C( -55)),
      simde_mm_set_pi8(INT8_C( -92), INT8_C(  45), INT8_C( -74), INT8_C( -51), INT8_C(  58), INT8_C( -71), INT8_C( 117), INT8_C( -47)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m64 r = simde_mm_unpackhi_pi8(test_vec[i].a, test_vec[i].b);
    simde_mm_empty();
    simde_assert_m64_i8(r, ==, test_vec[i].r);
  }

  simde_mm_empty();
  return MUNIT_OK;
}

static MunitResult
test_simde_mm_unpackhi_pi16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m64 a;
    simde__m64 b;
    simde__m64 r;
  } test_vec[8] = {
    { simde_mm_set_pi16(INT16_C( -14965), INT16_C(  28080), INT16_C( -15604), INT16_C( -10099)),
      simde_mm_set_pi16(INT16_C(  16538), INT16_C( -18813), INT16_C(   -254), INT16_C( -23207)),
      simde_mm_set_pi16(INT16_C(  16538), INT16_C( -14965), INT16_C( -18813), INT16_C(  28080)) },
    { simde_mm_set_pi16(INT16_C(  -4346), INT16_C( -29603), INT16_C(   1361), INT16_C(  16092)),
      simde_mm_set_pi16(INT16_C(  -4428), INT16_C( -25960), INT16_C(   7111), INT16_C(  29823)),
      simde_mm_set_pi16(INT16_C(  -4428), INT16_C(  -4346), INT16_C( -25960), INT16_C( -29603)) },
    { simde_mm_set_pi16(INT16_C( -22197), INT16_C( -13478), INT16_C(  29243), INT16_C(  -7146)),
      simde_mm_set_pi16(INT16_C(  -6022), INT16_C( -10408), INT16_C(  -5121), INT16_C( -15640)),
      simde_mm_set_pi16(INT16_C(  -6022), INT16_C( -22197), INT16_C( -10408), INT16_C( -13478)) },
    { simde_mm_set_pi16(INT16_C( -21336), INT16_C(  14878), INT16_C(  14164), INT16_C(   2727)),
      simde_mm_set_pi16(INT16_C(  12579), INT16_C( -20797), INT16_C(  18011), INT16_C(   5438)),
      simde_mm_set_pi16(INT16_C(  12579), INT16_C( -21336), INT16_C( -20797), INT16_C(  14878)) },
    { simde_mm_set_pi16(INT16_C( -20790), INT16_C( -21719), INT16_C( -12256), INT16_C( -17410)),
      simde_mm_set_pi16(INT16_C(   4576), INT16_C(   6842), INT16_C( -12668), INT16_C( -11854)),
      simde_mm_set_pi16(INT16_C(   4576), INT16_C( -20790), INT16_C(   6842), INT16_C( -21719)) },
    { simde_mm_set_pi16(INT16_C( -12751), INT16_C(  22951), INT16_C( -11466), INT16_C( -26387)),
      simde_mm_set_pi16(INT16_C( -27771), INT16_C( -31462), INT16_C(  14453), INT16_C(  -2204)),
      simde_mm_set_pi16(INT16_C( -27771), INT16_C( -12751), INT16_C( -31462), INT16_C(  22951)) },
    { simde_mm_set_pi16(INT16_C( -15685), INT16_C(  13196), INT16_C(  17198), INT16_C(  29713)),
      simde_mm_set_pi16(INT16_C(  29600), INT16_C( -21832), INT16_C(  -7500), INT16_C(  31712)),
      simde_mm_set_pi16(INT16_C(  29600), INT16_C( -15685), INT16_C( -21832), INT16_C(  13196)) },
    { simde_mm_set_pi16(INT16_C( -16681), INT16_C( -16529), INT16_C(  32728), INT16_C(  31459)),
      simde_mm_set_pi16(INT16_C(  20407), INT16_C( -12854), INT16_C(  18433), INT16_C(   3119)),
      simde_mm_set_pi16(INT16_C(  20407), INT16_C( -16681), INT16_C( -12854), INT16_C( -16529)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m64 r = simde_mm_unpackhi_pi16(test_vec[i].a, test_vec[i].b);
    simde_mm_empty();
    simde_assert_m64_i16(r, ==, test_vec[i].r);
  }

  simde_mm_empty();
  return MUNIT_OK;
}

static MunitResult
test_simde_mm_unpackhi_pi32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m64 a;
    simde__m64 b;
    simde__m64 r;
  } test_vec[8] = {
    { simde_mm_set_pi32(INT32_C( -1658263771), INT32_C( -1249023590)),
      simde_mm_set_pi32(INT32_C( -1692091894), INT32_C(   429039047)),
      simde_mm_set_pi32(INT32_C( -1692091894), INT32_C( -1658263771)) },
    { simde_mm_set_pi32(INT32_C(   900819254), INT32_C( -1069899126)),
      simde_mm_set_pi32(INT32_C(  -400543833), INT32_C( -2013963668)),
      simde_mm_set_pi32(INT32_C(  -400543833), INT32_C(   900819254)) },
    { simde_mm_set_pi32(INT32_C( -1005749657), INT32_C(  -188276900)),
      simde_mm_set_pi32(INT32_C(   810155385), INT32_C(  -436942778)),
      simde_mm_set_pi32(INT32_C(   810155385), INT32_C( -1005749657)) },
    { simde_mm_set_pi32(INT32_C(    43596265), INT32_C( -1556778284)),
      simde_mm_set_pi32(INT32_C( -1634766739), INT32_C(  -297104207)),
      simde_mm_set_pi32(INT32_C( -1634766739), INT32_C(    43596265)) },
    { simde_mm_set_pi32(INT32_C(   820557065), INT32_C(        2171)),
      simde_mm_set_pi32(INT32_C(  1748389432), INT32_C(  1779087168)),
      simde_mm_set_pi32(INT32_C(  1748389432), INT32_C(   820557065)) },
    { simde_mm_set_pi32(INT32_C(  -106826552), INT32_C(  -791842435)),
      simde_mm_set_pi32(INT32_C(  2006847448), INT32_C(   484681450)),
      simde_mm_set_pi32(INT32_C(  2006847448), INT32_C(  -106826552)) },
    { simde_mm_set_pi32(INT32_C(  1892029634), INT32_C(  -899748289)),
      simde_mm_set_pi32(INT32_C(  1496471605), INT32_C(   840905121)),
      simde_mm_set_pi32(INT32_C(  1496471605), INT32_C(  1892029634)) },
    { simde_mm_set_pi32(INT32_C(  1293223526), INT32_C(  -574905244)),
      simde_mm_set_pi32(INT32_C(    57909389), INT32_C(   -70830945)),
      simde_mm_set_pi32(INT32_C(    57909389), INT32_C(  1293223526)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m64 r = simde_mm_unpackhi_pi32(test_vec[i].a, test_vec[i].b);
    simde_mm_empty();
    simde_assert_m64_i32(r, ==, test_vec[i].r);
  }

  simde_mm_empty();
  return MUNIT_OK;
}

static MunitResult
test_simde_mm_unpacklo_pi8(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m64 a;
    simde__m64 b;
    simde__m64 r;
  } test_vec[8] = {
    { simde_mm_set_pi8(INT8_C( -15), INT8_C( -27), INT8_C( -29), INT8_C(   2), INT8_C(  11), INT8_C( 105), INT8_C( -49), INT8_C(  15)),
      simde_mm_set_pi8(INT8_C( -90), INT8_C(  43), INT8_C(  55), INT8_C(  50), INT8_C(-102), INT8_C(  25), INT8_C( -40), INT8_C(  47)),
      simde_mm_set_pi8(INT8_C(-102), INT8_C(  11), INT8_C(  25), INT8_C( 105), INT8_C( -40), INT8_C( -49), INT8_C(  47), INT8_C(  15)) },
    { simde_mm_set_pi8(INT8_C(   1), INT8_C(  83), INT8_C(-101), INT8_C( 117), INT8_C( -52), INT8_C( -74), INT8_C( -59), INT8_C( 121)),
      simde_mm_set_pi8(INT8_C(-102), INT8_C(  12), INT8_C( -28), INT8_C(  82), INT8_C(-122), INT8_C(  94), INT8_C( 127), INT8_C( -48)),
      simde_mm_set_pi8(INT8_C(-122), INT8_C( -52), INT8_C(  94), INT8_C( -74), INT8_C( 127), INT8_C( -59), INT8_C( -48), INT8_C( 121)) },
    { simde_mm_set_pi8(INT8_C(  13), INT8_C(  67), INT8_C( -73), INT8_C( -36), INT8_C( -93), INT8_C( 101), INT8_C(-107), INT8_C( 118)),
      simde_mm_set_pi8(INT8_C(  46), INT8_C( -72), INT8_C( -50), INT8_C(  34), INT8_C(-111), INT8_C( -17), INT8_C(-128), INT8_C(-126)),
      simde_mm_set_pi8(INT8_C(-111), INT8_C( -93), INT8_C( -17), INT8_C( 101), INT8_C(-128), INT8_C(-107), INT8_C(-126), INT8_C( 118)) },
    { simde_mm_set_pi8(INT8_C(   4), INT8_C( -40), INT8_C( -73), INT8_C( 122), INT8_C(  85), INT8_C(   7), INT8_C( -54), INT8_C(-119)),
      simde_mm_set_pi8(INT8_C( -37), INT8_C( -80), INT8_C(-128), INT8_C(  69), INT8_C( 112), INT8_C(  50), INT8_C(  44), INT8_C( -11)),
      simde_mm_set_pi8(INT8_C( 112), INT8_C(  85), INT8_C(  50), INT8_C(   7), INT8_C(  44), INT8_C( -54), INT8_C( -11), INT8_C(-119)) },
    { simde_mm_set_pi8(INT8_C(-113), INT8_C(  30), INT8_C(  68), INT8_C(  96), INT8_C( -94), INT8_C( -13), INT8_C( -38), INT8_C( -63)),
      simde_mm_set_pi8(INT8_C(  -9), INT8_C(  29), INT8_C(   5), INT8_C( -22), INT8_C(  66), INT8_C(  94), INT8_C( -79), INT8_C(  -1)),
      simde_mm_set_pi8(INT8_C(  66), INT8_C( -94), INT8_C(  94), INT8_C( -13), INT8_C( -79), INT8_C( -38), INT8_C(  -1), INT8_C( -63)) },
    { simde_mm_set_pi8(INT8_C( -42), INT8_C( -42), INT8_C(  41), INT8_C( -13), INT8_C( -41), INT8_C( -33), INT8_C( -24), INT8_C(  -5)),
      simde_mm_set_pi8(INT8_C(  85), INT8_C(  79), INT8_C(  19), INT8_C( -95), INT8_C(  42), INT8_C(-124), INT8_C( -96), INT8_C(-122)),
      simde_mm_set_pi8(INT8_C(  42), INT8_C( -41), INT8_C(-124), INT8_C( -33), INT8_C( -96), INT8_C( -24), INT8_C(-122), INT8_C(  -5)) },
    { simde_mm_set_pi8(INT8_C(  28), INT8_C(  99), INT8_C( -57), INT8_C(  79), INT8_C(  40), INT8_C( -97), INT8_C( -80), INT8_C(  16)),
      simde_mm_set_pi8(INT8_C(  60), INT8_C(   0), INT8_C( -13), INT8_C( -90), INT8_C(  17), INT8_C(  14), INT8_C(-115), INT8_C( 116)),
      simde_mm_set_pi8(INT8_C(  17), INT8_C(  40), INT8_C(  14), INT8_C( -97), INT8_C(-115), INT8_C( -80), INT8_C( 116), INT8_C(  16)) },
    { simde_mm_set_pi8(INT8_C( -26), INT8_C( -43), INT8_C( -21), INT8_C(  73), INT8_C(  83), INT8_C(  33), INT8_C( 105), INT8_C(  57)),
      simde_mm_set_pi8(INT8_C( -29), INT8_C(  84), INT8_C(  15), INT8_C( -83), INT8_C( -51), INT8_C(  60), INT8_C( -18), INT8_C(  19)),
      simde_mm_set_pi8(INT8_C( -51), INT8_C(  83), INT8_C(  60), INT8_C(  33), INT8_C( -18), INT8_C( 105), INT8_C(  19), INT8_C(  57)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m64 r = simde_mm_unpacklo_pi8(test_vec[i].a, test_vec[i].b);
    simde_mm_empty();
    simde_assert_m64_i8(r, ==, test_vec[i].r);
  }

  simde_mm_empty();
  return MUNIT_OK;
}

static MunitResult
test_simde_mm_unpacklo_pi16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m64 a;
    simde__m64 b;
    simde__m64 r;
  } test_vec[8] = {
    { simde_mm_set_pi16(INT16_C(  14920), INT16_C( -14108), INT16_C( -18371), INT16_C(   4165)),
      simde_mm_set_pi16(INT16_C(  24125), INT16_C(  29535), INT16_C(  14450), INT16_C(    764)),
      simde_mm_set_pi16(INT16_C(  14450), INT16_C( -18371), INT16_C(    764), INT16_C(   4165)) },
    { simde_mm_set_pi16(INT16_C( -29305), INT16_C( -20968), INT16_C( -31863), INT16_C(   1945)),
      simde_mm_set_pi16(INT16_C(  22380), INT16_C(  -9274), INT16_C( -14525), INT16_C(  28073)),
      simde_mm_set_pi16(INT16_C( -14525), INT16_C( -31863), INT16_C(  28073), INT16_C(   1945)) },
    { simde_mm_set_pi16(INT16_C(  29396), INT16_C(  -4481), INT16_C(  16009), INT16_C(  -7692)),
      simde_mm_set_pi16(INT16_C(  19262), INT16_C( -10592), INT16_C(   1200), INT16_C( -22541)),
      simde_mm_set_pi16(INT16_C(   1200), INT16_C(  16009), INT16_C( -22541), INT16_C(  -7692)) },
    { simde_mm_set_pi16(INT16_C(  10778), INT16_C( -30276), INT16_C(  31580), INT16_C(   4144)),
      simde_mm_set_pi16(INT16_C( -15899), INT16_C(  20583), INT16_C( -12863), INT16_C(  13808)),
      simde_mm_set_pi16(INT16_C( -12863), INT16_C(  31580), INT16_C(  13808), INT16_C(   4144)) },
    { simde_mm_set_pi16(INT16_C( -30267), INT16_C( -14054), INT16_C(  22036), INT16_C(  -6987)),
      simde_mm_set_pi16(INT16_C( -22296), INT16_C(  22035), INT16_C( -11029), INT16_C(   3882)),
      simde_mm_set_pi16(INT16_C( -11029), INT16_C(  22036), INT16_C(   3882), INT16_C(  -6987)) },
    { simde_mm_set_pi16(INT16_C(   1373), INT16_C(  25788), INT16_C( -14639), INT16_C(  18996)),
      simde_mm_set_pi16(INT16_C(   6580), INT16_C(  13730), INT16_C( -12979), INT16_C( -26646)),
      simde_mm_set_pi16(INT16_C( -12979), INT16_C( -14639), INT16_C( -26646), INT16_C(  18996)) },
    { simde_mm_set_pi16(INT16_C(  27110), INT16_C(  18497), INT16_C( -15879), INT16_C( -18233)),
      simde_mm_set_pi16(INT16_C( -26068), INT16_C( -29214), INT16_C(  32362), INT16_C( -26103)),
      simde_mm_set_pi16(INT16_C(  32362), INT16_C( -15879), INT16_C( -26103), INT16_C( -18233)) },
    { simde_mm_set_pi16(INT16_C(  -3448), INT16_C(  28151), INT16_C(  21394), INT16_C(   2546)),
      simde_mm_set_pi16(INT16_C(  30183), INT16_C(  -1624), INT16_C(  11589), INT16_C(  23080)),
      simde_mm_set_pi16(INT16_C(  11589), INT16_C(  21394), INT16_C(  23080), INT16_C(   2546)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m64 r = simde_mm_unpacklo_pi16(test_vec[i].a, test_vec[i].b);
    simde_mm_empty();
    simde_assert_m64_i16(r, ==, test_vec[i].r);
  }

  simde_mm_empty();
  return MUNIT_OK;
}

static MunitResult
test_simde_mm_unpacklo_pi32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m64 a;
    simde__m64 b;
    simde__m64 r;
  } test_vec[8] = {
    { simde_mm_set_pi32(INT32_C(  -996466818), INT32_C(    42237187)),
      simde_mm_set_pi32(INT32_C(   -37002499), INT32_C( -1170856260)),
      simde_mm_set_pi32(INT32_C( -1170856260), INT32_C(    42237187)) },
    { simde_mm_set_pi32(INT32_C(  2063937130), INT32_C(   491318053)),
      simde_mm_set_pi32(INT32_C( -1702472225), INT32_C(   404431239)),
      simde_mm_set_pi32(INT32_C(   404431239), INT32_C(   491318053)) },
    { simde_mm_set_pi32(INT32_C(   482157619), INT32_C(  2096228641)),
      simde_mm_set_pi32(INT32_C(  1577000773), INT32_C( -1308575062)),
      simde_mm_set_pi32(INT32_C( -1308575062), INT32_C(  2096228641)) },
    { simde_mm_set_pi32(INT32_C(  -296283078), INT32_C( -1136099560)),
      simde_mm_set_pi32(INT32_C(   813050106), INT32_C(   140703223)),
      simde_mm_set_pi32(INT32_C(   140703223), INT32_C( -1136099560)) },
    { simde_mm_set_pi32(INT32_C( -1874282519), INT32_C(  1046328641)),
      simde_mm_set_pi32(INT32_C(  1711474246), INT32_C(   663714514)),
      simde_mm_set_pi32(INT32_C(   663714514), INT32_C(  1046328641)) },
    { simde_mm_set_pi32(INT32_C(   414254548), INT32_C( -1137400610)),
      simde_mm_set_pi32(INT32_C(  1336205549), INT32_C( -1985285725)),
      simde_mm_set_pi32(INT32_C( -1985285725), INT32_C( -1137400610)) },
    { simde_mm_set_pi32(INT32_C( -1928184284), INT32_C(   711404402)),
      simde_mm_set_pi32(INT32_C(   894723783), INT32_C(  -331643442)),
      simde_mm_set_pi32(INT32_C(  -331643442), INT32_C(   711404402)) },
    { simde_mm_set_pi32(INT32_C( -1171624194), INT32_C(  -943645737)),
      simde_mm_set_pi32(INT32_C( -1212436628), INT32_C( -1787000320)),
      simde_mm_set_pi32(INT32_C( -1787000320), INT32_C(  -943645737)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m64 r = simde_mm_unpacklo_pi32(test_vec[i].a, test_vec[i].b);
    simde_mm_empty();
    simde_assert_m64_i32(r, ==, test_vec[i].r);
  }

  simde_mm_empty();
  return MUNIT_OK;
}

static MunitResult
test_simde_mm_xor_si64(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m64 a;
    simde__m64 b;
    simde__m64 r;
  } test_vec[8] = {
    { simde_mm_cvtsi64_m64(INT64_C(   3540462192578516470)),
      simde_mm_cvtsi64_m64(INT64_C(   7953957601195225655)),
      simde_mm_cvtsi64_m64(INT64_C(   6863518614534072257)) },
    { simde_mm_cvtsi64_m64(INT64_C(   3280097856998777041)),
      simde_mm_cvtsi64_m64(INT64_C(   7227524436289590224)),
      simde_mm_cvtsi64_m64(INT64_C(   5316618871007982337)) },
    { simde_mm_cvtsi64_m64(INT64_C(    -73768962290391525)),
      simde_mm_cvtsi64_m64(INT64_C(  -8786938381172726443)),
      simde_mm_cvtsi64_m64(INT64_C(   8716556128933069646)) },
    { simde_mm_cvtsi64_m64(INT64_C(  -3834999859910724293)),
      simde_mm_cvtsi64_m64(INT64_C(   1473106142712794056)),
      simde_mm_cvtsi64_m64(INT64_C(  -2398499088890937613)) },
    { simde_mm_cvtsi64_m64(INT64_C(  -2129742113263669437)),
      simde_mm_cvtsi64_m64(INT64_C(   8747348426473787001)),
      simde_mm_cvtsi64_m64(INT64_C(  -7271780848289947334)) },
    { simde_mm_cvtsi64_m64(INT64_C(   3415454954475332549)),
      simde_mm_cvtsi64_m64(INT64_C(  -4751919769270097997)),
      simde_mm_cvtsi64_m64(INT64_C(  -7968019982084324234)) },
    { simde_mm_cvtsi64_m64(INT64_C(   2939655727369393330)),
      simde_mm_cvtsi64_m64(INT64_C(   -201574666518844870)),
      simde_mm_cvtsi64_m64(INT64_C(  -3028638143195201912)) },
    { simde_mm_cvtsi64_m64(INT64_C(   2745915445215058834)),
      simde_mm_cvtsi64_m64(INT64_C(   3063327936426889284)),
      simde_mm_cvtsi64_m64(INT64_C(    907566634544925654)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m64 r = simde_mm_xor_si64(test_vec[i].a, test_vec[i].b);
    simde_mm_empty();
    simde_assert_m64_i64(r, ==, test_vec[i].r);
  }

  simde_mm_empty();
  return MUNIT_OK;
}

static MunitResult
test_simde_m_to_int(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m64 a;
    int32_t r;
  } test_vec[8] = {
    { simde_mm_set_pi32(INT32_C(   187717888), INT32_C(   752961943)), INT32_C(   752961943) },
    { simde_mm_set_pi32(INT32_C(  1573710578), INT32_C(   101880394)), INT32_C(   101880394) },
    { simde_mm_set_pi32(INT32_C(  1011596849), INT32_C(   885891666)), INT32_C(   885891666) },
    { simde_mm_set_pi32(INT32_C( -1107434699), INT32_C(  -838173825)), INT32_C(  -838173825) },
    { simde_mm_set_pi32(INT32_C(  1945069486), INT32_C(   466583902)), INT32_C(   466583902) },
    { simde_mm_set_pi32(INT32_C(   458761181), INT32_C(   257379889)), INT32_C(   257379889) },
    { simde_mm_set_pi32(INT32_C(   848486959), INT32_C( -1415343346)), INT32_C( -1415343346) },
    { simde_mm_set_pi32(INT32_C( -1452285617), INT32_C( -1697816479)), INT32_C( -1697816479) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    int32_t r = simde_m_to_int(test_vec[i].a);
    simde_mm_empty();
    munit_assert_int32(r, ==, test_vec[i].r);
  }

  simde_mm_empty();
  return MUNIT_OK;
}

static MunitResult
test_simde_m_to_int64(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m64 a;
    int64_t r;
  } test_vec[8] = {
    { simde_mm_cvtsi64_m64(INT64_C(  -2003895301208818234)), INT64_C(  -2003895301208818234) },
    { simde_mm_cvtsi64_m64(INT64_C(   -372926738147273591)), INT64_C(   -372926738147273591) },
    { simde_mm_cvtsi64_m64(INT64_C(  -3656592147926155100)), INT64_C(  -3656592147926155100) },
    { simde_mm_cvtsi64_m64(INT64_C(   5100863564862776395)), INT64_C(   5100863564862776395) },
    { simde_mm_cvtsi64_m64(INT64_C(   -214027610699488575)), INT64_C(   -214027610699488575) },
    { simde_mm_cvtsi64_m64(INT64_C(  -7630939822071486777)), INT64_C(  -7630939822071486777) },
    { simde_mm_cvtsi64_m64(INT64_C(   9123236376678660233)), INT64_C(   9123236376678660233) },
    { simde_mm_cvtsi64_m64(INT64_C(   3260252501062812952)), INT64_C(   3260252501062812952) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    int64_t r = simde_m_to_int64(test_vec[i].a);
    simde_mm_empty();
    munit_assert_int64(r, ==, test_vec[i].r);
  }

  simde_mm_empty();
  return MUNIT_OK;
}

#endif /* defined(SIMDE_MMX_NATIVE) || defined(SIMDE_NO_NATIVE) || defined(SIMDE_ALWAYS_BUILD_NATIVE_TESTS) */

HEDLEY_DIAGNOSTIC_PUSH
HEDLEY_DIAGNOSTIC_DISABLE_CAST_QUAL

static MunitTest test_suite_tests[] = {
#if defined(SIMDE_MMX_NATIVE) || defined(SIMDE_NO_NATIVE) || defined(SIMDE_ALWAYS_BUILD_NATIVE_TESTS)
  SIMDE_TESTS_DEFINE_TEST(mm_set1_pi8),
  SIMDE_TESTS_DEFINE_TEST(mm_set1_pi16),
  SIMDE_TESTS_DEFINE_TEST(mm_set1_pi32),
  SIMDE_TESTS_DEFINE_TEST(mm_setr_pi8),
  SIMDE_TESTS_DEFINE_TEST(mm_setr_pi16),
  SIMDE_TESTS_DEFINE_TEST(mm_setr_pi32),
  SIMDE_TESTS_DEFINE_TEST(mm_add_pi8),
  SIMDE_TESTS_DEFINE_TEST(mm_add_pi16),
  SIMDE_TESTS_DEFINE_TEST(mm_add_pi32),
  SIMDE_TESTS_DEFINE_TEST(mm_adds_pi8),
  SIMDE_TESTS_DEFINE_TEST(mm_adds_pi16),
  SIMDE_TESTS_DEFINE_TEST(mm_adds_pu8),
  SIMDE_TESTS_DEFINE_TEST(mm_adds_pu16),
  SIMDE_TESTS_DEFINE_TEST(mm_and_si64),
  SIMDE_TESTS_DEFINE_TEST(mm_andnot_si64),
  SIMDE_TESTS_DEFINE_TEST(mm_cmpeq_pi8),
  SIMDE_TESTS_DEFINE_TEST(mm_cmpeq_pi16),
  SIMDE_TESTS_DEFINE_TEST(mm_cmpeq_pi32),
  SIMDE_TESTS_DEFINE_TEST(mm_cmpgt_pi8),
  SIMDE_TESTS_DEFINE_TEST(mm_cmpgt_pi16),
  SIMDE_TESTS_DEFINE_TEST(mm_cmpgt_pi32),
  SIMDE_TESTS_DEFINE_TEST(mm_cvtm64_si64),
  SIMDE_TESTS_DEFINE_TEST(mm_cvtsi32_si64),
  SIMDE_TESTS_DEFINE_TEST(mm_cvtsi64_m64),
  SIMDE_TESTS_DEFINE_TEST(mm_cvtsi64_si32),
  SIMDE_TESTS_DEFINE_TEST(mm_madd_pi16),
  SIMDE_TESTS_DEFINE_TEST(mm_mulhi_pi16),
  SIMDE_TESTS_DEFINE_TEST(mm_mullo_pi16),
  SIMDE_TESTS_DEFINE_TEST(mm_or_si64),
  SIMDE_TESTS_DEFINE_TEST(mm_packs_pi16),
  SIMDE_TESTS_DEFINE_TEST(mm_packs_pi32),
  SIMDE_TESTS_DEFINE_TEST(mm_packs_pu16),
  SIMDE_TESTS_DEFINE_TEST(mm_sll_pi16),
  SIMDE_TESTS_DEFINE_TEST(mm_sll_pi32),
  SIMDE_TESTS_DEFINE_TEST(mm_sll_si64),
  SIMDE_TESTS_DEFINE_TEST(mm_slli_pi16),
  SIMDE_TESTS_DEFINE_TEST(mm_slli_pi32),
  SIMDE_TESTS_DEFINE_TEST(mm_slli_si64),
  SIMDE_TESTS_DEFINE_TEST(mm_srl_pi16),
  SIMDE_TESTS_DEFINE_TEST(mm_srl_pi32),
  SIMDE_TESTS_DEFINE_TEST(mm_srl_si64),
  SIMDE_TESTS_DEFINE_TEST(mm_srli_pi16),
  SIMDE_TESTS_DEFINE_TEST(mm_srli_pi32),
  SIMDE_TESTS_DEFINE_TEST(mm_srli_si64),
  SIMDE_TESTS_DEFINE_TEST(mm_srai_pi16),
  SIMDE_TESTS_DEFINE_TEST(mm_srai_pi32),
  SIMDE_TESTS_DEFINE_TEST(mm_sra_pi16),
  SIMDE_TESTS_DEFINE_TEST(mm_sra_pi32),
  SIMDE_TESTS_DEFINE_TEST(mm_sub_pi8),
  SIMDE_TESTS_DEFINE_TEST(mm_sub_pi16),
  SIMDE_TESTS_DEFINE_TEST(mm_sub_pi32),
  SIMDE_TESTS_DEFINE_TEST(mm_subs_pi8),
  SIMDE_TESTS_DEFINE_TEST(mm_subs_pi16),
  SIMDE_TESTS_DEFINE_TEST(mm_subs_pu8),
  SIMDE_TESTS_DEFINE_TEST(mm_subs_pu16),
  SIMDE_TESTS_DEFINE_TEST(mm_unpackhi_pi8),
  SIMDE_TESTS_DEFINE_TEST(mm_unpackhi_pi16),
  SIMDE_TESTS_DEFINE_TEST(mm_unpackhi_pi32),
  SIMDE_TESTS_DEFINE_TEST(mm_unpacklo_pi8),
  SIMDE_TESTS_DEFINE_TEST(mm_unpacklo_pi16),
  SIMDE_TESTS_DEFINE_TEST(mm_unpacklo_pi32),
  SIMDE_TESTS_DEFINE_TEST(mm_xor_si64),
  SIMDE_TESTS_DEFINE_TEST(m_to_int),
  SIMDE_TESTS_DEFINE_TEST(m_to_int64),
#endif /* defined(SIMDE_MMX_NATIVE) || defined(SIMDE_NO_NATIVE) || defined(SIMDE_ALWAYS_BUILD_NATIVE_TESTS) */

  { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};

HEDLEY_C_DECL MunitSuite* SIMDE_TESTS_GENERATE_SYMBOL(suite)(void) {
  static MunitSuite suite = { (char*) "/" HEDLEY_STRINGIFY(SIMDE_TESTS_CURRENT_ISAX), test_suite_tests, NULL, 1, MUNIT_SUITE_OPTION_NONE };

  return &suite;
}

#if defined(SIMDE_TESTS_SINGLE_ISAX)
int main(int argc, char* argv[HEDLEY_ARRAY_PARAM(argc + 1)]) {
  static MunitSuite suite = { "", test_suite_tests, NULL, 1, MUNIT_SUITE_OPTION_NONE };

  return munit_suite_main(&suite, NULL, argc, argv);
}
#endif /* defined(SIMDE_TESTS_SINGLE_ISAX) */

HEDLEY_DIAGNOSTIC_POP
