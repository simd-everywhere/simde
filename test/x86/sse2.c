/* Copyright (c) 2017, 2019 Evan Nemerson <evan@nemerson.com>
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

#define SIMDE_TESTS_CURRENT_ISAX sse2
#include <test/x86/test-x86-internal.h>
#include <simde/x86/sse2.h>

static MunitResult
test_simde_mm_add_epi8(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi8(INT8_C( -94), INT8_C( 118), INT8_C( -57), INT8_C( -76),
                        INT8_C( -37), INT8_C( -69), INT8_C(  35), INT8_C( 108),
                        INT8_C( 107), INT8_C( -44), INT8_C(  45), INT8_C( -10),
                        INT8_C( -48), INT8_C(  62), INT8_C( -17), INT8_C( -90)),
      simde_mm_set_epi8(INT8_C( -30), INT8_C(  -7), INT8_C(  -5), INT8_C( -37),
                        INT8_C(  34), INT8_C( 102), INT8_C(  22), INT8_C(-119),
                        INT8_C(  90), INT8_C(  -5), INT8_C(  35), INT8_C( -48),
                        INT8_C( -74), INT8_C( 118), INT8_C( 127), INT8_C(  21)),
      simde_mm_set_epi8(INT8_C(-124), INT8_C( 111), INT8_C( -62), INT8_C(-113),
                        INT8_C(  -3), INT8_C(  33), INT8_C(  57), INT8_C( -11),
                        INT8_C( -59), INT8_C( -49), INT8_C(  80), INT8_C( -58),
                        INT8_C(-122), INT8_C( -76), INT8_C( 110), INT8_C( -69)) },
    { simde_mm_set_epi8(INT8_C( -67), INT8_C(-117), INT8_C(  44), INT8_C( -42),
                        INT8_C( -51), INT8_C( -10), INT8_C( -92), INT8_C( -82),
                        INT8_C(  66), INT8_C( -81), INT8_C(  76), INT8_C( -46),
                        INT8_C(  40), INT8_C( -32), INT8_C( -97), INT8_C(  30)),
      simde_mm_set_epi8(INT8_C(  -3), INT8_C( -92), INT8_C( -27), INT8_C(-109),
                        INT8_C(  90), INT8_C( -78), INT8_C( -47), INT8_C(-124),
                        INT8_C( 126), INT8_C(-112), INT8_C(  46), INT8_C(-118),
                        INT8_C( -65), INT8_C( -38), INT8_C(  53), INT8_C(-115)),
      simde_mm_set_epi8(INT8_C( -70), INT8_C(  47), INT8_C(  17), INT8_C( 105),
                        INT8_C(  39), INT8_C( -88), INT8_C( 117), INT8_C(  50),
                        INT8_C( -64), INT8_C(  63), INT8_C( 122), INT8_C(  92),
                        INT8_C( -25), INT8_C( -70), INT8_C( -44), INT8_C( -85)) },
    { simde_mm_set_epi8(INT8_C( -58), INT8_C( 111), INT8_C( -57), INT8_C( 102),
                        INT8_C( 104), INT8_C(  31), INT8_C(  84), INT8_C( -73),
                        INT8_C( -47), INT8_C(-121), INT8_C( -64), INT8_C( -74),
                        INT8_C(  15), INT8_C( -32), INT8_C( -70), INT8_C( -29)),
      simde_mm_set_epi8(INT8_C( -12), INT8_C( -29), INT8_C(-108), INT8_C( -82),
                        INT8_C( -43), INT8_C( -80), INT8_C( -92), INT8_C(  86),
                        INT8_C(-105), INT8_C(  99), INT8_C( -46), INT8_C( -82),
                        INT8_C(  -6), INT8_C( -37), INT8_C(  69), INT8_C(  62)),
      simde_mm_set_epi8(INT8_C( -70), INT8_C(  82), INT8_C(  91), INT8_C(  20),
                        INT8_C(  61), INT8_C( -49), INT8_C(  -8), INT8_C(  13),
                        INT8_C( 104), INT8_C( -22), INT8_C(-110), INT8_C( 100),
                        INT8_C(   9), INT8_C( -69), INT8_C(  -1), INT8_C(  33)) },
    { simde_mm_set_epi8(INT8_C( 104), INT8_C(-111), INT8_C( -24), INT8_C( -75),
                        INT8_C(  20), INT8_C(  35), INT8_C(  98), INT8_C( -61),
                        INT8_C(  71), INT8_C(  56), INT8_C(   2), INT8_C( -19),
                        INT8_C(  14), INT8_C(  53), INT8_C( 103), INT8_C( -57)),
      simde_mm_set_epi8(INT8_C( 126), INT8_C( -33), INT8_C(  39), INT8_C( -83),
                        INT8_C( -78), INT8_C(  96), INT8_C( 111), INT8_C(-105),
                        INT8_C( 109), INT8_C( -28), INT8_C( 103), INT8_C( -87),
                        INT8_C(-121), INT8_C(-111), INT8_C(  51), INT8_C(-112)),
      simde_mm_set_epi8(INT8_C( -26), INT8_C( 112), INT8_C(  15), INT8_C(  98),
                        INT8_C( -58), INT8_C(-125), INT8_C( -47), INT8_C(  90),
                        INT8_C( -76), INT8_C(  28), INT8_C( 105), INT8_C(-106),
                        INT8_C(-107), INT8_C( -58), INT8_C(-102), INT8_C(  87)) },
    { simde_mm_set_epi8(INT8_C(  -3), INT8_C( -20), INT8_C(  66), INT8_C(  69),
                        INT8_C( -80), INT8_C(  -4), INT8_C( -23), INT8_C( -73),
                        INT8_C(  88), INT8_C(  83), INT8_C(  61), INT8_C(  32),
                        INT8_C(-126), INT8_C(  85), INT8_C(  14), INT8_C( 107)),
      simde_mm_set_epi8(INT8_C(  65), INT8_C( 112), INT8_C( -18), INT8_C(  34),
                        INT8_C(  38), INT8_C(  -6), INT8_C(   1), INT8_C(  23),
                        INT8_C( -33), INT8_C(-102), INT8_C(  26), INT8_C( 117),
                        INT8_C(  36), INT8_C(  13), INT8_C( 125), INT8_C(  -9)),
      simde_mm_set_epi8(INT8_C(  62), INT8_C(  92), INT8_C(  48), INT8_C( 103),
                        INT8_C( -42), INT8_C( -10), INT8_C( -22), INT8_C( -50),
                        INT8_C(  55), INT8_C( -19), INT8_C(  87), INT8_C(-107),
                        INT8_C( -90), INT8_C(  98), INT8_C(-117), INT8_C(  98)) },
    { simde_mm_set_epi8(INT8_C( 117), INT8_C(  -3), INT8_C( -41), INT8_C( -94),
                        INT8_C( 119), INT8_C(  81), INT8_C(  65), INT8_C( -99),
                        INT8_C(  94), INT8_C( -99), INT8_C(  -4), INT8_C(  95),
                        INT8_C(  53), INT8_C( -73), INT8_C( -50), INT8_C( -66)),
      simde_mm_set_epi8(INT8_C(  22), INT8_C( 124), INT8_C(  59), INT8_C(  14),
                        INT8_C( 125), INT8_C(  30), INT8_C( -12), INT8_C( -34),
                        INT8_C( 100), INT8_C( -51), INT8_C( 125), INT8_C(  91),
                        INT8_C( -79), INT8_C(  62), INT8_C( -56), INT8_C( -17)),
      simde_mm_set_epi8(INT8_C(-117), INT8_C( 121), INT8_C(  18), INT8_C( -80),
                        INT8_C( -12), INT8_C( 111), INT8_C(  53), INT8_C( 123),
                        INT8_C( -62), INT8_C( 106), INT8_C( 121), INT8_C( -70),
                        INT8_C( -26), INT8_C( -11), INT8_C(-106), INT8_C( -83)) },
    { simde_mm_set_epi8(INT8_C(  26), INT8_C(   1), INT8_C( -71), INT8_C(   9),
                        INT8_C(-116), INT8_C(-123), INT8_C( -61), INT8_C( -65),
                        INT8_C(   9), INT8_C(-100), INT8_C(-125), INT8_C( -71),
                        INT8_C( 111), INT8_C( -31), INT8_C(  96), INT8_C( 100)),
      simde_mm_set_epi8(INT8_C(  42), INT8_C(  47), INT8_C(  70), INT8_C(  -2),
                        INT8_C(  25), INT8_C(-116), INT8_C( -38), INT8_C(-118),
                        INT8_C(-107), INT8_C( -26), INT8_C( 100), INT8_C(  -2),
                        INT8_C( -49), INT8_C(  59), INT8_C( -57), INT8_C(  32)),
      simde_mm_set_epi8(INT8_C(  68), INT8_C(  48), INT8_C(  -1), INT8_C(   7),
                        INT8_C( -91), INT8_C(  17), INT8_C( -99), INT8_C(  73),
                        INT8_C( -98), INT8_C(-126), INT8_C( -25), INT8_C( -73),
                        INT8_C(  62), INT8_C(  28), INT8_C(  39), INT8_C(-124)) },
    { simde_mm_set_epi8(INT8_C(-106), INT8_C(  60), INT8_C(  30), INT8_C( -61),
                        INT8_C(  51), INT8_C(-128), INT8_C(  39), INT8_C(  42),
                        INT8_C( 122), INT8_C(  28), INT8_C(  -7), INT8_C( -39),
                        INT8_C( -27), INT8_C( -54), INT8_C(  60), INT8_C( -87)),
      simde_mm_set_epi8(INT8_C( -84), INT8_C( -49), INT8_C(  21), INT8_C( 107),
                        INT8_C(  93), INT8_C(  59), INT8_C( -95), INT8_C( 110),
                        INT8_C( -17), INT8_C(   9), INT8_C( -71), INT8_C( 125),
                        INT8_C(-115), INT8_C(  71), INT8_C(  80), INT8_C( -92)),
      simde_mm_set_epi8(INT8_C(  66), INT8_C(  11), INT8_C(  51), INT8_C(  46),
                        INT8_C(-112), INT8_C( -69), INT8_C( -56), INT8_C(-104),
                        INT8_C( 105), INT8_C(  37), INT8_C( -78), INT8_C(  86),
                        INT8_C( 114), INT8_C(  17), INT8_C(-116), INT8_C(  77)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_add_epi8(test_vec[i].a, test_vec[i].b);
    simde_assert_m128i_i8(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_add_epi16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi16(    94,  18436,  -5798,  19570,   6902,  28083, -22092,  11564),
      simde_mm_set_epi16( -9100, -28423,  29678,  -7883,  16415,  29183,  -8344, -22247),
      simde_mm_set_epi16( -9006,  -9987,  23880,  11687,  23317,  -8270, -30436, -10683) },
    { simde_mm_set_epi16(-22746,  -1215,  -8186,  30686, -17058,  21266,  22576,  14851),
      simde_mm_set_epi16( 25056, -28938,  -4695, -16392,   2641, -22638,  17857,  22359),
      simde_mm_set_epi16(  2310, -30153, -12881,  14294, -14417,  -1372, -25103, -28326) },
    { simde_mm_set_epi16(-14746,  32152, -23823, -27084,  28858,   1852, -14327,  15382),
      simde_mm_set_epi16( 25798, -32052,  -2912,  24060, -16842,  10227,  27380, -21884),
      simde_mm_set_epi16( 11052,    100, -26735,  -3024,  12016,  12079,  13053,  -6502) },
    { simde_mm_set_epi16(  1289, -21265,  -9795,   -149, -19971, -25799,  20500, -27231),
      simde_mm_set_epi16(-17641,  16666,   7579,    741,  31983, -10687, -10744,  17233),
      simde_mm_set_epi16(-16352,  -4599,  -2216,    592,  12012,  29050,   9756,  -9998) },
    { simde_mm_set_epi16( 13217,  32652,  -7503, -31892,   2544,  13612,  17549,  -8418),
      simde_mm_set_epi16(  6218, -18067, -12120,  -3451, -17506,  -8198,   -976,  18365),
      simde_mm_set_epi16( 19435,  14585, -19623,  30193, -14962,   5414,  16573,   9947) },
    { simde_mm_set_epi16(-27664, -18531, -12856,  10685, -12380,  -6882,  14795, -30722),
      simde_mm_set_epi16( -6097,  20924,  24045,  30044,    238,    263, -20759, -21064),
      simde_mm_set_epi16( 31775,   2393,  11189, -24807, -12142,  -6619,  -5964,  13750) },
    { simde_mm_set_epi16(  3365, -27764, -32703,   -569,  15639,  14836,  18330, -24160),
      simde_mm_set_epi16(-10670,  -7702, -13209,   1248,  -4667,   9775,  -3668,   4536),
      simde_mm_set_epi16( -7305,  30070,  19624,    679,  10972,  24611,  14662, -19624) },
    { simde_mm_set_epi16( 29615,   5623,  -1376, -30346, -11514, -10826,   3491,  27257),
      simde_mm_set_epi16(-14385,  12800, -22205,   6979,  26232,  21363, -14818,   6370),
      simde_mm_set_epi16( 15230,  18423, -23581, -23367,  14718,  10537, -11327, -31909) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_add_epi16(test_vec[i].a, test_vec[i].b);
    simde_assert_m128i_i16(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_add_epi32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi32(  121350502,  -944441568, -1915439895, -1111455064),
      simde_mm_set_epi32(  718169493,  -452314964, -2118639844,  1882776661),
      simde_mm_set_epi32(  839519995, -1396756532,   260887557,   771321597) },
    { simde_mm_set_epi32( -127793460, -1127636068,  -629452409,  -239892354),
      simde_mm_set_epi32( 1646207859,   412860111,   551544705,  -631201379),
      simde_mm_set_epi32( 1518414399,  -714775957,   -77907704,  -871093733) },
    { simde_mm_set_epi32( -822740758,  -191997349, -1412946633,  1194544990),
      simde_mm_set_epi32(-1141581032,   700185896,  1461654699, -1858741413),
      simde_mm_set_epi32(-1964321790,   508188547,    48708066,  -664196423) },
    { simde_mm_set_epi32( -793084053, -1595435464,  -679215928,  1425631589),
      simde_mm_set_epi32(  479677672,  1178867999,   -51277213,   511301156),
      simde_mm_set_epi32( -313406381,  -416567465,  -730493141,  1936932745) },
    { simde_mm_set_epi32(-1735464240,  1784119885,   661377304,  1698610062),
      simde_mm_set_epi32(   15110255,   707778190, -1752521514,   459417024),
      simde_mm_set_epi32(-1720353985, -1803069221, -1091144210, -2136940210) },
    { simde_mm_set_epi32( 1748486053,   678510205,  2049909508,   749130856),
      simde_mm_set_epi32( -431754827, -2028973544,  -856439981, -2059688549),
      simde_mm_set_epi32( 1316731226, -1350463339,  1193469527, -1310557693) },
    { simde_mm_set_epi32( -550799344,  -409720803,  -851866570,  -112829026),
      simde_mm_set_epi32(-1602361493, -1384917548,  1779971895, -1237242425),
      simde_mm_set_epi32( 2141806459, -1794638351,   928105325, -1350071451) },
    { simde_mm_set_epi32( -114470009,  2126468368, -1460046247, -1429897229),
      simde_mm_set_epi32(-1674154367,  1265314239,  1120742803, -1381423245),
      simde_mm_set_epi32(-1788624376,  -903184689,  -339303444,  1483646822) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_add_epi32(test_vec[i].a, test_vec[i].b);
    simde_assert_m128i_i32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_add_epi64(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi64x(INT64_C( 5302906957046332539), INT64_C( 6896761003579441006)),
      simde_mm_set_epi64x(INT64_C( 8080483180981769846), INT64_C( -532551505374559044)),
      simde_mm_set_epi64x(INT64_C(-5063353935681449231), INT64_C( 6364209498204881962)) },
    { simde_mm_set_epi64x(INT64_C(  244760848479017871), INT64_C(-8308084306078226664)),
      simde_mm_set_epi64x(INT64_C(-3779773313499286364), INT64_C( 6113767891784897906)),
      simde_mm_set_epi64x(INT64_C(-3535012465020268493), INT64_C(-2194316414293328758)) },
    { simde_mm_set_epi64x(INT64_C(-6850824349794960557), INT64_C(-5605962976784798391)),
      simde_mm_set_epi64x(INT64_C(-2244363788590884551), INT64_C(-6273588010625182382)),
      simde_mm_set_epi64x(INT64_C(-9095188138385845108), INT64_C( 6567193086299570843)) },
    { simde_mm_set_epi64x(INT64_C( 6565436457151053906), INT64_C( 5511764898961433032)),
      simde_mm_set_epi64x(INT64_C( 1077726064250254320), INT64_C( -263844214123199019)),
      simde_mm_set_epi64x(INT64_C( 7643162521401308226), INT64_C( 5247920684838234013)) },
    { simde_mm_set_epi64x(INT64_C(-5813163364316205654), INT64_C( 4814776107221586548)),
      simde_mm_set_epi64x(INT64_C(-2933269790578797014), INT64_C(   74425625609844147)),
      simde_mm_set_epi64x(INT64_C(-8746433154895002668), INT64_C( 4889201732831430695)) },
    { simde_mm_set_epi64x(INT64_C(-2444264382048445434), INT64_C( 3369516233586132041)),
      simde_mm_set_epi64x(INT64_C(-4296115714310543830), INT64_C( 3847771998301827374)),
      simde_mm_set_epi64x(INT64_C(-6740380096358989264), INT64_C( 7217288231887959415)) },
    { simde_mm_set_epi64x(INT64_C(-6266932275253634982), INT64_C( 6725635524324655769)),
      simde_mm_set_epi64x(INT64_C( 4821822804079289890), INT64_C(-7857845909588692827)),
      simde_mm_set_epi64x(INT64_C(-1445109471174345092), INT64_C(-1132210385264037058)) },
    { simde_mm_set_epi64x(INT64_C( 4307059302838028733), INT64_C(-5215917355058769847)),
      simde_mm_set_epi64x(INT64_C( 4398479129145449653), INT64_C( 2472056074162910166)),
      simde_mm_set_epi64x(INT64_C( 8705538431983478386), INT64_C(-2743861280895859681)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_add_epi64(test_vec[i].a, test_vec[i].b);
    simde_assert_m128i_i64(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_add_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128d a;
    simde__m128d b;
    simde__m128d r;
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  692.94), SIMDE_FLOAT64_C(  -54.00)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  808.70), SIMDE_FLOAT64_C( -119.61)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( 1501.64), SIMDE_FLOAT64_C( -173.61)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  522.72), SIMDE_FLOAT64_C( -185.63)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  421.40), SIMDE_FLOAT64_C( -110.04)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  944.11), SIMDE_FLOAT64_C( -295.67)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  882.82), SIMDE_FLOAT64_C( -926.59)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   18.43), SIMDE_FLOAT64_C(  439.06)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  901.25), SIMDE_FLOAT64_C( -487.53)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -812.39), SIMDE_FLOAT64_C( -968.80)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -611.22), SIMDE_FLOAT64_C( -994.53)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(-1423.61), SIMDE_FLOAT64_C(-1963.33)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  799.36), SIMDE_FLOAT64_C(  503.15)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -287.21), SIMDE_FLOAT64_C( -449.06)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  512.15), SIMDE_FLOAT64_C(   54.08)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -439.71), SIMDE_FLOAT64_C( -625.83)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -779.95), SIMDE_FLOAT64_C(   52.26)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(-1219.66), SIMDE_FLOAT64_C( -573.57)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  -20.82), SIMDE_FLOAT64_C( -138.96)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -136.01), SIMDE_FLOAT64_C( -829.13)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -156.83), SIMDE_FLOAT64_C( -968.09)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -846.81), SIMDE_FLOAT64_C(  763.26)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  303.68), SIMDE_FLOAT64_C(  274.55)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -543.14), SIMDE_FLOAT64_C( 1037.81)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_add_pd(test_vec[i].a, test_vec[i].b);
    simde_assert_m128d_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_add_sd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128d a;
    simde__m128d b;
    simde__m128d r;
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -348.09), SIMDE_FLOAT64_C( -603.87)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   42.81), SIMDE_FLOAT64_C( -955.64)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -348.09), SIMDE_FLOAT64_C(-1559.51)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  600.30), SIMDE_FLOAT64_C(  362.82)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -245.13), SIMDE_FLOAT64_C( -144.52)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  600.30), SIMDE_FLOAT64_C(  218.30)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -909.82), SIMDE_FLOAT64_C(  -28.51)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -141.49), SIMDE_FLOAT64_C(  174.41)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -909.82), SIMDE_FLOAT64_C(  145.90)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -402.79), SIMDE_FLOAT64_C( -225.69)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -114.28), SIMDE_FLOAT64_C(  118.74)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -402.79), SIMDE_FLOAT64_C( -106.95)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  476.58), SIMDE_FLOAT64_C(  189.13)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  158.24), SIMDE_FLOAT64_C(  133.22)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  476.58), SIMDE_FLOAT64_C(  322.35)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -902.16), SIMDE_FLOAT64_C( -720.35)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -496.01), SIMDE_FLOAT64_C(  563.52)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -902.16), SIMDE_FLOAT64_C( -156.83)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(   32.48), SIMDE_FLOAT64_C( -172.74)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  435.61), SIMDE_FLOAT64_C(  209.72)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   32.48), SIMDE_FLOAT64_C(   36.98)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  322.78), SIMDE_FLOAT64_C( -415.13)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -49.82), SIMDE_FLOAT64_C( -195.58)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  322.78), SIMDE_FLOAT64_C( -610.71)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_add_sd(test_vec[i].a, test_vec[i].b);
    simde_assert_m128d_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_add_si64(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m64 a;
    simde__m64 b;
    simde__m64 r;
  } test_vec[8] = {
    { simde_mm_cvtsi64_m64(INT64_C(  793111073070173174)),
      simde_mm_cvtsi64_m64(INT64_C( 2108668061446341817)),
      simde_mm_cvtsi64_m64(INT64_C( 2901779134516514991)), },
    { simde_mm_cvtsi64_m64(INT64_C( 8875506276833571865)),
      simde_mm_cvtsi64_m64(INT64_C(-8625831155966083456)),
      simde_mm_cvtsi64_m64(INT64_C(  249675120867488409)), },
    { simde_mm_cvtsi64_m64(INT64_C( 2916092148231541839)),
      simde_mm_cvtsi64_m64(INT64_C( 7640479428881902755)),
      simde_mm_cvtsi64_m64(INT64_C(-7890172496596107022)), },
    { simde_mm_cvtsi64_m64(INT64_C(-3448012693901819300)),
      simde_mm_cvtsi64_m64(INT64_C(-9198379985559078668)),
      simde_mm_cvtsi64_m64(INT64_C( 5800351394248653648)), },
    { simde_mm_cvtsi64_m64(INT64_C( 3628113225825158935)),
      simde_mm_cvtsi64_m64(INT64_C(-1333669735654572042)),
      simde_mm_cvtsi64_m64(INT64_C( 2294443490170586893)), },
    { simde_mm_cvtsi64_m64(INT64_C( 5048798289215441413)),
      simde_mm_cvtsi64_m64(INT64_C( -388036903570542302)),
      simde_mm_cvtsi64_m64(INT64_C( 4660761385644899111)), },
    { simde_mm_cvtsi64_m64(INT64_C( 6446512717337269554)),
      simde_mm_cvtsi64_m64(INT64_C(-7669829270527021775)),
      simde_mm_cvtsi64_m64(INT64_C(-1223316553189752221)), },
    { simde_mm_cvtsi64_m64(INT64_C( 6296531259101832881)),
      simde_mm_cvtsi64_m64(INT64_C( 5834912758815977701)),
      simde_mm_cvtsi64_m64(INT64_C(-6315300055791741034)), }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m64 r = simde_mm_add_si64(test_vec[i].a, test_vec[i].b);
    simde_assert_m64_i64(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_adds_epi8(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi8(INT8_C( 100), INT8_C(  33), INT8_C(  67), INT8_C(  67), INT8_C( 104), INT8_C(-123), INT8_C( -86), INT8_C(  74),
                        INT8_C( -93), INT8_C(  -4), INT8_C( -12), INT8_C(  28), INT8_C(   9), INT8_C(  39), INT8_C(  83), INT8_C( -52)),
      simde_mm_set_epi8(INT8_C(  40), INT8_C( -64), INT8_C( -19), INT8_C( -17), INT8_C(  67), INT8_C( -93), INT8_C( -22), INT8_C(  98),
                        INT8_C( -73), INT8_C( -83), INT8_C( 107), INT8_C(  95), INT8_C(  59), INT8_C(  84), INT8_C( -72), INT8_C(-115)),
      simde_mm_set_epi8(INT8_C( 127), INT8_C( -31), INT8_C(  48), INT8_C(  50), INT8_C( 127), INT8_C(-128), INT8_C(-108), INT8_C( 127),
                        INT8_C(-128), INT8_C( -87), INT8_C(  95), INT8_C( 123), INT8_C(  68), INT8_C( 123), INT8_C(  11), INT8_C(-128)) },
    { simde_mm_set_epi8(INT8_C(  76), INT8_C( 121), INT8_C(  98), INT8_C(  52), INT8_C(  50), INT8_C( -16), INT8_C(  53), INT8_C(   3),
                        INT8_C( -57), INT8_C( -76), INT8_C( -42), INT8_C(  70), INT8_C(-122), INT8_C(  71), INT8_C( -56), INT8_C( -15)),
      simde_mm_set_epi8(INT8_C( 100), INT8_C( 124), INT8_C(  99), INT8_C(  11), INT8_C(  -8), INT8_C(   5), INT8_C(   6), INT8_C( -54),
                        INT8_C(  42), INT8_C( -99), INT8_C(  23), INT8_C(-128), INT8_C(  77), INT8_C(  14), INT8_C(  94), INT8_C(  53)),
      simde_mm_set_epi8(INT8_C( 127), INT8_C( 127), INT8_C( 127), INT8_C(  63), INT8_C(  42), INT8_C( -11), INT8_C(  59), INT8_C( -51),
                        INT8_C( -15), INT8_C(-128), INT8_C( -19), INT8_C( -58), INT8_C( -45), INT8_C(  85), INT8_C(  38), INT8_C(  38)) },
    { simde_mm_set_epi8(INT8_C( -13), INT8_C(  29), INT8_C(  30), INT8_C(  13), INT8_C(  51), INT8_C(  11), INT8_C( -27), INT8_C( -12),
                        INT8_C(  97), INT8_C(  87), INT8_C(  67), INT8_C(  70), INT8_C(   2), INT8_C( -40), INT8_C(  49), INT8_C( 116)),
      simde_mm_set_epi8(INT8_C(  42), INT8_C( -17), INT8_C( -77), INT8_C( 126), INT8_C(-125), INT8_C( -42), INT8_C(  45), INT8_C( -79),
                        INT8_C( -23), INT8_C( 110), INT8_C( 117), INT8_C( -44), INT8_C( -92), INT8_C( -20), INT8_C(-121), INT8_C( 102)),
      simde_mm_set_epi8(INT8_C(  29), INT8_C(  12), INT8_C( -47), INT8_C( 127), INT8_C( -74), INT8_C( -31), INT8_C(  18), INT8_C( -91),
                        INT8_C(  74), INT8_C( 127), INT8_C( 127), INT8_C(  26), INT8_C( -90), INT8_C( -60), INT8_C( -72), INT8_C( 127)) },
    { simde_mm_set_epi8(INT8_C(  55), INT8_C(-106), INT8_C( -49), INT8_C( -49), INT8_C( -85), INT8_C( -58), INT8_C( -56), INT8_C( -25),
                        INT8_C(  78), INT8_C(  18), INT8_C(  71), INT8_C( -12), INT8_C(  86), INT8_C( -84), INT8_C( -77), INT8_C(-116)),
      simde_mm_set_epi8(INT8_C(-103), INT8_C( 107), INT8_C(  33), INT8_C( -17), INT8_C( 106), INT8_C(   4), INT8_C( -98), INT8_C(-128),
                        INT8_C(  53), INT8_C(   4), INT8_C( 120), INT8_C( -44), INT8_C( -99), INT8_C( 120), INT8_C( -27), INT8_C(  45)),
      simde_mm_set_epi8(INT8_C( -48), INT8_C(   1), INT8_C( -16), INT8_C( -66), INT8_C(  21), INT8_C( -54), INT8_C(-128), INT8_C(-128),
                        INT8_C( 127), INT8_C(  22), INT8_C( 127), INT8_C( -56), INT8_C( -13), INT8_C(  36), INT8_C(-104), INT8_C( -71)) },
    { simde_mm_set_epi8(INT8_C(  47), INT8_C(  15), INT8_C( 126), INT8_C(-115), INT8_C( -77), INT8_C( -27), INT8_C( -38), INT8_C(  32),
                        INT8_C( -21), INT8_C( -80), INT8_C( 112), INT8_C(  75), INT8_C( -15), INT8_C( -92), INT8_C(  43), INT8_C( -22)),
      simde_mm_set_epi8(INT8_C( -33), INT8_C( 127), INT8_C( 123), INT8_C(  65), INT8_C(  63), INT8_C(  85), INT8_C(  75), INT8_C(  99),
                        INT8_C(  -2), INT8_C(  13), INT8_C( -46), INT8_C(  -8), INT8_C( 127), INT8_C(-115), INT8_C(-109), INT8_C(  14)),
      simde_mm_set_epi8(INT8_C(  14), INT8_C( 127), INT8_C( 127), INT8_C( -50), INT8_C( -14), INT8_C(  58), INT8_C(  37), INT8_C( 127),
                        INT8_C( -23), INT8_C( -67), INT8_C(  66), INT8_C(  67), INT8_C( 112), INT8_C(-128), INT8_C( -66), INT8_C(  -8)) },
    { simde_mm_set_epi8(INT8_C(  18), INT8_C(  75), INT8_C(  10), INT8_C(  29), INT8_C(  27), INT8_C( 101), INT8_C(  -1), INT8_C(  78),
                        INT8_C( -78), INT8_C( 110), INT8_C(  18), INT8_C(  82), INT8_C( -41), INT8_C(  85), INT8_C(-113), INT8_C( 126)),
      simde_mm_set_epi8(INT8_C( -90), INT8_C(  80), INT8_C(-103), INT8_C(-111), INT8_C(  86), INT8_C(  65), INT8_C(  89), INT8_C(  88),
                        INT8_C( -83), INT8_C(-121), INT8_C(  -2), INT8_C(  40), INT8_C( -96), INT8_C( -36), INT8_C(  64), INT8_C( -15)),
      simde_mm_set_epi8(INT8_C( -72), INT8_C( 127), INT8_C( -93), INT8_C( -82), INT8_C( 113), INT8_C( 127), INT8_C(  88), INT8_C( 127),
                        INT8_C(-128), INT8_C( -11), INT8_C(  16), INT8_C( 122), INT8_C(-128), INT8_C(  49), INT8_C( -49), INT8_C( 111)) },
    { simde_mm_set_epi8(INT8_C( -90), INT8_C(  48), INT8_C( -43), INT8_C(  22), INT8_C(  78), INT8_C( -17), INT8_C( -78), INT8_C( -64),
                        INT8_C( -97), INT8_C( -80), INT8_C( -51), INT8_C(  72), INT8_C( 114), INT8_C( -11), INT8_C( -89), INT8_C( -93)),
      simde_mm_set_epi8(INT8_C(   8), INT8_C(  57), INT8_C(  66), INT8_C(-119), INT8_C(  79), INT8_C( -29), INT8_C( -49), INT8_C(  26),
                        INT8_C( -12), INT8_C( -99), INT8_C(-101), INT8_C( 121), INT8_C(-112), INT8_C(  -5), INT8_C( -19), INT8_C( -27)),
      simde_mm_set_epi8(INT8_C( -82), INT8_C( 105), INT8_C(  23), INT8_C( -97), INT8_C( 127), INT8_C( -46), INT8_C(-127), INT8_C( -38),
                        INT8_C(-109), INT8_C(-128), INT8_C(-128), INT8_C( 127), INT8_C(   2), INT8_C( -16), INT8_C(-108), INT8_C(-120)) },
    { simde_mm_set_epi8(INT8_C(  26), INT8_C( -15), INT8_C(  12), INT8_C( -66), INT8_C(  -7), INT8_C(-115), INT8_C( -21), INT8_C(  27),
                        INT8_C( 111), INT8_C(-126), INT8_C( -43), INT8_C( -94), INT8_C( -97), INT8_C( -34), INT8_C( -47), INT8_C( -79)),
      simde_mm_set_epi8(INT8_C(-124), INT8_C( -47), INT8_C(-123), INT8_C(-115), INT8_C( -15), INT8_C( -87), INT8_C(-121), INT8_C( -50),
                        INT8_C( 103), INT8_C(  85), INT8_C(  34), INT8_C( -85), INT8_C(-124), INT8_C(  70), INT8_C(  14), INT8_C( -44)),
      simde_mm_set_epi8(INT8_C( -98), INT8_C( -62), INT8_C(-111), INT8_C(-128), INT8_C( -22), INT8_C(-128), INT8_C(-128), INT8_C( -23),
                        INT8_C( 127), INT8_C( -41), INT8_C(  -9), INT8_C(-128), INT8_C(-128), INT8_C(  36), INT8_C( -33), INT8_C(-123)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_adds_epi8(test_vec[i].a, test_vec[i].b);
    simde_assert_m128i_i8(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_adds_epi16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi16( -9187,  11150, -25711,  30917,   5637,  27391,  20667, -25552),
      simde_mm_set_epi16( 15244, -26000, -24422, -28473,  -7393,  32134,   -161,  -2948),
      simde_mm_set_epi16(  6057, -14850, -32768,   2444,  -1756,  32767,  20506, -28500) },
    { simde_mm_set_epi16(-27976,   8581,  17714, -15964, -24791,  29014,  -8950, -19859),
      simde_mm_set_epi16(-20491, -23795,   5770, -28365,  -4266, -14588,  21498,  13063),
      simde_mm_set_epi16(-32768, -15214,  23484, -32768, -29057,  14426,  12548,  -6796) },
    { simde_mm_set_epi16(-24285, -16974,  21513,  30869, -30698,   2555, -20742, -26329),
      simde_mm_set_epi16( 19660, -27596,  16650,  30694,  14408,   7632,  15232,  -7024),
      simde_mm_set_epi16( -4625, -32768,  32767,  32767, -16290,  10187,  -5510, -32768) },
    { simde_mm_set_epi16( -6143,   5190,   -240, -14301,  12856,  32740, -13308,  31639),
      simde_mm_set_epi16( 21047, -20544, -28076, -30442,  28180, -18015,  12870,  12342),
      simde_mm_set_epi16( 14904, -15354, -28316, -32768,  32767,  14725,   -438,  32767) },
    { simde_mm_set_epi16( 21004,  26590,   -387,   5458,  28558,  -1691,  13843,  -2265),
      simde_mm_set_epi16( 24548, -19288,   1056,   5037,   9790,  12391,  -2983,   8158),
      simde_mm_set_epi16( 32767,   7302,    669,  10495,  32767,  10700,  10860,   5893) },
    { simde_mm_set_epi16( 23035,  14493,  11060, -15265, -25751, -17380, -20209, -22539),
      simde_mm_set_epi16(-10338,  26220,  -6324,  16083, -20758,  28594, -27719, -21423),
      simde_mm_set_epi16( 12697,  32767,   4736,    818, -32768,  11214, -32768, -32768) },
    { simde_mm_set_epi16(  1437,  -1148,  -7704,  -3845,   5523,  32157,  -3057,  -2194),
      simde_mm_set_epi16( 20255,  16313,  26265,  -5377,  31904,   3795,  20716, -30035),
      simde_mm_set_epi16( 21692,  15165,  18561,  -9222,  32767,  32767,  17659, -32229) },
    { simde_mm_set_epi16(   856,  13772, -17603, -26424,   9957, -11801,   3067, -26950),
      simde_mm_set_epi16(-26495, -22337, -30714,  24988, -24287,  11170, -20015,  26834),
      simde_mm_set_epi16(-25639,  -8565, -32768,  -1436, -14330,   -631, -16948,   -116) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_adds_epi16(test_vec[i].a, test_vec[i].b);
    simde_assert_m128i_i16(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_adds_epu8(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_x_mm_set_epu8(243, 185, 175,  84, 114, 173, 219, 130,
                           80,  12,   6, 121,  58, 223,  94, 203),
      simde_x_mm_set_epu8( 46, 142,  32,  64, 239,  92, 213, 158,
                           92,  20,  62, 216,   2, 162,   3, 226),
      simde_x_mm_set_epu8(255, 255, 207, 148, 255, 255, 255, 255,
                          172,  32,  68, 255,  60, 255,  97, 255) },
    { simde_x_mm_set_epu8(200, 115,  63, 101, 233, 139, 164, 230,
                            4, 147,   7, 233, 110, 206, 178, 233),
      simde_x_mm_set_epu8( 87,  74,  19, 102, 136, 119, 164, 198,
                          113, 170, 154,   7, 191, 195, 220, 182),
      simde_x_mm_set_epu8(255, 189,  82, 203, 255, 255, 255, 255,
                          117, 255, 161, 240, 255, 255, 255, 255) },
    { simde_x_mm_set_epu8( 35,  38, 142, 165, 104,  97, 151,   1,
                           79,  16, 160, 140,  19, 109, 210, 120),
      simde_x_mm_set_epu8(  2, 202, 138, 112, 199, 233, 201,  65,
                          233,  49, 101, 216,  62,  35, 235, 214),
      simde_x_mm_set_epu8( 37, 240, 255, 255, 255, 255, 255,  66,
                          255,  65, 255, 255,  81, 144, 255, 255) },
    { simde_x_mm_set_epu8( 98,  74, 253, 101, 187,  74, 205,  52,
                          154, 226, 198, 148, 241, 174, 125,  62),
      simde_x_mm_set_epu8(163, 110,   1, 166, 233, 185, 220, 101,
                          190,  92, 121, 253, 238,  73,  61,  34),
      simde_x_mm_set_epu8(255, 184, 254, 255, 255, 255, 255, 153,
                          255, 255, 255, 255, 255, 247, 186,  96) },
    { simde_x_mm_set_epu8( 91,  28,  52,  18, 175,  61,  49,  67,
                           76,  39, 238, 247, 137,  91, 133,   4),
      simde_x_mm_set_epu8(142, 255, 123,  14,  70,  48,  62, 186,
                          134,  31, 154,  34,   3,  30,  40, 184),
      simde_x_mm_set_epu8(233, 255, 175,  32, 245, 109, 111, 253,
                          210,  70, 255, 255, 140, 121, 173, 188) },
    { simde_x_mm_set_epu8( 32, 230,  94,  17, 123, 186,  43,  67,
                           13,  45, 219, 214, 133,  19,  25, 150),
      simde_x_mm_set_epu8(114,  27, 244, 244,  84,   0, 108, 198,
                          239, 228, 225, 158,   4,  27,  84, 116),
      simde_x_mm_set_epu8(146, 255, 255, 255, 207, 186, 151, 255,
                          252, 255, 255, 255, 137,  46, 109, 255) },
    { simde_x_mm_set_epu8( 66, 152,   8,  32,   7, 222,  46,  10,
                          116, 185,  69, 186, 194, 134,  55, 214),
      simde_x_mm_set_epu8(185,  11, 114, 201, 179, 122,  77, 244,
                          221, 175, 219,  12, 207, 104,  91, 252),
      simde_x_mm_set_epu8(251, 163, 122, 233, 186, 255, 123, 254,
                          255, 255, 255, 198, 255, 238, 146, 255) },
    { simde_x_mm_set_epu8(149,  71,  22, 119,  62,  37, 103,  26,
                          193,  60, 234, 165,  97, 233, 187,  76),
      simde_x_mm_set_epu8(169,   9, 188,  18, 251, 187,  96, 167,
                          158, 238, 176, 160,  74,  18, 253, 103),
      simde_x_mm_set_epu8(255,  80, 210, 137, 255, 224, 199, 193,
                          255, 255, 255, 255, 171, 251, 255, 179) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_adds_epu8(test_vec[i].a, test_vec[i].b);
    simde_assert_m128i_u8(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_adds_epu16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_x_mm_set_epu16(52397,  2628, 46614, 35162, 54536, 36456, 24004, 11160),
      simde_x_mm_set_epu16(41921, 12035, 29903, 58497,  1695, 15558, 14248, 61659),
      simde_x_mm_set_epu16(65535, 14663, 65535, 65535, 56231, 52014, 38252, 65535) },
    { simde_x_mm_set_epu16(57345,  6650,  8556, 25986, 61163, 19076, 40550, 40920),
      simde_x_mm_set_epu16(62607, 15369, 35325, 28241, 54252,  5722, 23748, 36984),
      simde_x_mm_set_epu16(65535, 22019, 43881, 54227, 65535, 24798, 64298, 65535) },
    { simde_x_mm_set_epu16(19370, 64323,  5781, 65431, 30915, 24348, 65190, 30074),
      simde_x_mm_set_epu16(34245, 57703, 60540, 40683, 24154, 18750, 32124, 33828),
      simde_x_mm_set_epu16(53615, 65535, 65535, 65535, 55069, 43098, 65535, 63902) },
    { simde_x_mm_set_epu16( 1083, 62410, 53296,    45, 57969, 54778, 42038, 36216),
      simde_x_mm_set_epu16(47446, 36131, 44258, 13796, 53696, 55457, 27279, 19924),
      simde_x_mm_set_epu16(48529, 65535, 65535, 13841, 65535, 65535, 65535, 56140) },
    { simde_x_mm_set_epu16(53022, 40173, 23284, 53830, 27939, 30100, 61471,   602),
      simde_x_mm_set_epu16(42952, 36449, 22644,  6670,   537,  5689,    73,  2247),
      simde_x_mm_set_epu16(65535, 65535, 45928, 60500, 28476, 35789, 61544,  2849) },
    { simde_x_mm_set_epu16( 8441, 24815, 22801, 35056, 30653,  5655, 39135, 32848),
      simde_x_mm_set_epu16( 7115, 32196, 31449, 51212, 54481,  9348, 63499, 54202),
      simde_x_mm_set_epu16(15556, 57011, 54250, 65535, 65535, 15003, 65535, 65535) },
    { simde_x_mm_set_epu16( 5059, 20924,  5143, 29698, 39512, 42596, 50907, 48157),
      simde_x_mm_set_epu16(55259, 30633, 10948, 60956, 47288, 59136, 49334, 11432),
      simde_x_mm_set_epu16(60318, 51557, 16091, 65535, 65535, 65535, 65535, 59589) },
    { simde_x_mm_set_epu16(53397,  1584, 56368, 64962, 35166, 11367, 24855, 22370),
      simde_x_mm_set_epu16( 5862,  9719, 15493, 14762, 25151, 48370, 30737, 29969),
      simde_x_mm_set_epu16(59259, 11303, 65535, 65535, 60317, 59737, 55592, 52339) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_adds_epu16(test_vec[i].a, test_vec[i].b);
    simde_assert_m128i_u16(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_and_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128d a;
    simde__m128d b;
    simde__m128d r;
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -606.22), SIMDE_FLOAT64_C(  874.08)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  807.60), SIMDE_FLOAT64_C(  -11.56)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  518.10), SIMDE_FLOAT64_C(    2.38)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  352.03), SIMDE_FLOAT64_C(  588.38)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  590.34), SIMDE_FLOAT64_C( -688.03)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    2.25), SIMDE_FLOAT64_C(  512.01)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  365.91), SIMDE_FLOAT64_C( -165.12)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -877.33), SIMDE_FLOAT64_C(  611.63)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    2.29), SIMDE_FLOAT64_C(    2.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -616.20), SIMDE_FLOAT64_C(  109.60)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -193.05), SIMDE_FLOAT64_C(  975.05)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   -2.00), SIMDE_FLOAT64_C(    3.30)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -450.67), SIMDE_FLOAT64_C( -722.66)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -984.89), SIMDE_FLOAT64_C(  333.54)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   -3.50), SIMDE_FLOAT64_C(    2.57)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  420.85), SIMDE_FLOAT64_C( -200.82)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.89), SIMDE_FLOAT64_C( -772.92)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(   -3.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -866.17), SIMDE_FLOAT64_C(  206.85)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -904.55), SIMDE_FLOAT64_C(  635.86)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -768.03), SIMDE_FLOAT64_C(    2.23)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  108.59), SIMDE_FLOAT64_C( -506.28)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -260.87), SIMDE_FLOAT64_C(  698.96)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   64.09), SIMDE_FLOAT64_C(    2.69)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_and_pd(test_vec[i].a, test_vec[i].b);
    simde_assert_m128d_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_and_si128(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi32(INT32_C( 1143386005), INT32_C(  255040004), INT32_C(  778825143), INT32_C( 1160880262)),
      simde_mm_set_epi32(INT32_C(-1598010564), INT32_C(  882577136), INT32_C( 1895747884), INT32_C(   78458499)),
      simde_mm_set_epi32(INT32_C(       2836), INT32_C(   68356608), INT32_C(  543867172), INT32_C(   69279874)) },
    { simde_mm_set_epi32(INT32_C(  929630839), INT32_C( 1332223012), INT32_C( -595247247), INT32_C( 1607004091)),
      simde_mm_set_epi32(INT32_C(  -96984995), INT32_C( -496201158), INT32_C( 1667897198), INT32_C(  329068048)),
      simde_mm_set_epi32(INT32_C(  841482325), INT32_C( 1114116128), INT32_C( 1073747808), INT32_C(  327691792)) },
    { simde_mm_set_epi32(INT32_C( 1507410371), INT32_C(-1202228125), INT32_C(  213174798), INT32_C( 1712466479)),
      simde_mm_set_epi32(INT32_C( -416935364), INT32_C(   76821686), INT32_C( -895281725), INT32_C(  640856929)),
      simde_mm_set_epi32(INT32_C( 1090519040), INT32_C(    1324066), INT32_C(  144703490), INT32_C(  638722593)) },
    { simde_mm_set_epi32(INT32_C(-1967400648), INT32_C( -398277023), INT32_C( 1276094966), INT32_C(-1580835262)),
      simde_mm_set_epi32(INT32_C(  185492863), INT32_C( 1265367516), INT32_C( -384438464), INT32_C( 1008626379)),
      simde_mm_set_epi32(INT32_C(  168444216), INT32_C( 1212334144), INT32_C( 1208330560), INT32_C(  537283138)) },
    { simde_mm_set_epi32(INT32_C( 1287640091), INT32_C( -654000828), INT32_C(  597524546), INT32_C(  182360913)),
      simde_mm_set_epi32(INT32_C( 1236330411), INT32_C( 1010510657), INT32_C(-1874705697), INT32_C( -544222805)),
      simde_mm_set_epi32(INT32_C( 1219544075), INT32_C(  402663744), INT32_C(         66), INT32_C(  177115393)) },
    { simde_mm_set_epi32(INT32_C( -783740762), INT32_C( 1592969400), INT32_C(-1896275639), INT32_C( 1398555518)),
      simde_mm_set_epi32(INT32_C(  618146080), INT32_C( -972493969), INT32_C( -440292799), INT32_C(  888342397)),
      simde_mm_set_epi32(INT32_C(    4718624), INT32_C( 1174456360), INT32_C(-2067718079), INT32_C(  273679228)) },
    { simde_mm_set_epi32(INT32_C(  975551520), INT32_C(  223749592), INT32_C(-1022254731), INT32_C( -845311996)),
      simde_mm_set_epi32(INT32_C( 1522650069), INT32_C( 1767255815), INT32_C( 1217271913), INT32_C(-1365644996)),
      simde_mm_set_epi32(INT32_C(  436307968), INT32_C(  156640512), INT32_C( 1073741921), INT32_C(-1936097276)) },
    { simde_mm_set_epi32(INT32_C(-1607852092), INT32_C( -146112938), INT32_C(  112326370), INT32_C(  971940993)),
      simde_mm_set_epi32(INT32_C( 1129446249), INT32_C( -367605030), INT32_C( 2031327443), INT32_C( -763011289)),
      simde_mm_set_epi32(INT32_C(       6976), INT32_C( -503166382), INT32_C(    1151170), INT32_C(  277087233)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_and_si128(test_vec[i].a, test_vec[i].b);
    simde_assert_m128i_i8(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_andnot_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128d a;
    simde__m128d b;
    simde__m128d r;
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -174.15), SIMDE_FLOAT64_C( -191.62)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -621.38), SIMDE_FLOAT64_C(  807.23)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -514.25), SIMDE_FLOAT64_C(  644.41)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  127.18), SIMDE_FLOAT64_C(  977.52)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -636.38), SIMDE_FLOAT64_C(  670.84)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  954.09), SIMDE_FLOAT64_C(  244.99)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  314.94), SIMDE_FLOAT64_C( -888.21)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -355.85), SIMDE_FLOAT64_C(  580.14)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   -0.00), SIMDE_FLOAT64_C(    0.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  658.98), SIMDE_FLOAT64_C(   47.30)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -65.64), SIMDE_FLOAT64_C(  790.40)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   -0.00), SIMDE_FLOAT64_C(    0.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  963.63), SIMDE_FLOAT64_C( -102.98)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  833.56), SIMDE_FLOAT64_C(  345.51)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  590.50), SIMDE_FLOAT64_C(  508.59)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  551.21), SIMDE_FLOAT64_C( -654.02)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(   -0.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  172.90), SIMDE_FLOAT64_C( -248.58)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  199.86), SIMDE_FLOAT64_C( -719.44)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_andnot_pd(test_vec[i].a, test_vec[i].b);
    simde_assert_m128d_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_andnot_si128(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi32(INT32_C( -560808079), INT32_C( -229809400), INT32_C(-1262424809), INT32_C(   39478984)),
      simde_mm_set_epi32(INT32_C(-2116907800), INT32_C( -478633369), INT32_C( -758500702), INT32_C(  774827765)),
      simde_mm_set_epi32(INT32_C(   20971656), INT32_C(   19955815), INT32_C( 1107956384), INT32_C(  740591669)) },
    { simde_mm_set_epi32(INT32_C( -390101732), INT32_C( -878593643), INT32_C(  -87858932), INT32_C( 1872700566)),
      simde_mm_set_epi32(INT32_C(  794830631), INT32_C( 1201718915), INT32_C( 1477008088), INT32_C( -178127418)),
      simde_mm_set_epi32(INT32_C(  121643555), INT32_C(   67126786), INT32_C(     531152), INT32_C(-1872701120)) },
    { simde_mm_set_epi32(INT32_C( -969785513), INT32_C(  743154241), INT32_C( -944974936), INT32_C(-1136592248)),
      simde_mm_set_epi32(INT32_C( -909998602), INT32_C(  431643866), INT32_C( -708589890), INT32_C( -556429363)),
      simde_mm_set_epi32(INT32_C(  163610784), INT32_C(  296770714), INT32_C(  272827414), INT32_C( 1117062469)) },
    { simde_mm_set_epi32(INT32_C( 1619650408), INT32_C(  861525694), INT32_C(-2058207417), INT32_C(  228720218)),
      simde_mm_set_epi32(INT32_C( 1416821078), INT32_C( 2107001565), INT32_C(-1248448269), INT32_C(-1204471361)),
      simde_mm_set_epi32(INT32_C(  343021590), INT32_C( 1283852353), INT32_C(  813957296), INT32_C(-1340866139)) },
    { simde_mm_set_epi32(INT32_C( -343490394), INT32_C( 1846187115), INT32_C( -847771260), INT32_C(   97935165)),
      simde_mm_set_epi32(INT32_C(  -69489865), INT32_C(-1109591795), INT32_C(  169478308), INT32_C( 1662522631)),
      simde_mm_set_epi32(INT32_C(  274279185), INT32_C(-1848350460), INT32_C(   33685536), INT32_C( 1644691458)) },
    { simde_mm_set_epi32(INT32_C(  608096731), INT32_C( -775399847), INT32_C(  -52780990), INT32_C(  459462722)),
      simde_mm_set_epi32(INT32_C(-1928888486), INT32_C(-1926941714), INT32_C(-1218438233), INT32_C(  195273416)),
      simde_mm_set_epi32(INT32_C(-1996411392), INT32_C(  203760038), INT32_C(   52435877), INT32_C(    8462984)) },
    { simde_mm_set_epi32(INT32_C( 1829801526), INT32_C( 1678890728), INT32_C(-1629742565), INT32_C(  902941266)),
      simde_mm_set_epi32(INT32_C(  110066513), INT32_C( -591553870), INT32_C( -950259417), INT32_C(  810403185)),
      simde_mm_set_epi32(INT32_C(   42955073), INT32_C(-1733556206), INT32_C( 1090527524), INT32_C(     787745)) },
    { simde_mm_set_epi32(INT32_C(  321441431), INT32_C(-1200267660), INT32_C( -313751420), INT32_C(  515761953)),
      simde_mm_set_epi32(INT32_C( -687838781), INT32_C( 1420638186), INT32_C(-1442242179), INT32_C( 1996838037)),
      simde_mm_set_epi32(INT32_C(-1006624448), INT32_C( 1149772170), INT32_C(   33628537), INT32_C( 1627394196)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_andnot_si128(test_vec[i].a, test_vec[i].b);
    simde_assert_m128i_i8(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_avg_epu8(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_x_mm_set_epu8( 22, 218, 216,  66,  82, 156,  47,  52,
                          255,   1, 136, 174, 147, 136, 106, 178),
      simde_x_mm_set_epu8( 66, 241, 223, 129,  96,  67,   0,  68,
                          242,  71, 233, 224, 227, 252, 191,  92),
      simde_x_mm_set_epu8( 44, 230, 220,  98,  89, 112,  24,  60,
                          249,  36, 185, 199, 187, 194, 149, 135) },
    { simde_x_mm_set_epu8(219, 214,  26,  72,  63,  56, 200, 118,
                          196, 107,  88, 110, 187,   3,  64, 214),
      simde_x_mm_set_epu8( 44, 175, 103,  82,  87, 192, 180,  37,
                            0, 200,  53, 214,  25,  17,  19, 149),
      simde_x_mm_set_epu8(132, 195,  65,  77,  75, 124, 190,  78,
                           98, 154,  71, 162, 106,  10,  42, 182) },
    { simde_x_mm_set_epu8(221,   9, 162, 208,  84,  84,  50, 140,
                          230,  69, 178,  12,  34, 173,  44,  58),
      simde_x_mm_set_epu8(  4, 110,  65, 218, 252, 108, 241, 136,
                           36, 109,  68,   2, 121,  10, 120, 101),
      simde_x_mm_set_epu8(113,  60, 114, 213, 168,  96, 146, 138,
                          133,  89, 123,   7,  78,  92,  82,  80) },
    { simde_x_mm_set_epu8(173,  38,  26, 251,  66, 136, 168, 132,
                          170, 244, 145,  27,  76, 168,  97, 129),
      simde_x_mm_set_epu8(211,  66,  29,  93, 231,  30, 149, 218,
                           72,  12, 231, 238, 124,   3, 127,  55),
      simde_x_mm_set_epu8(192,  52,  28, 172, 149,  83, 159, 175,
                          121, 128, 188, 133, 100,  86, 112,  92) },
    { simde_x_mm_set_epu8( 33, 120,  41,   4, 226,  71, 169,  72,
                           92, 211,  80,  53,  22, 250, 136,  31),
      simde_x_mm_set_epu8(163, 237, 214, 178,  29, 194, 137, 109,
                          134, 197,  40, 228, 174, 101, 114, 162),
      simde_x_mm_set_epu8( 98, 179, 128,  91, 128, 133, 153,  91,
                          113, 204,  60, 141,  98, 176, 125,  97) },
    { simde_x_mm_set_epu8(151, 241,  42,  96,  21, 167,  26, 188,
                          124, 136, 158, 144, 227, 152,   4, 152),
      simde_x_mm_set_epu8( 43, 216,  77, 147, 105, 127,  87,  93,
                          160, 103,  68,  85,  77,  41,  67, 189),
      simde_x_mm_set_epu8( 97, 229,  60, 122,  63, 147,  57, 141,
                          142, 120, 113, 115, 152,  97,  36, 171) },
    { simde_x_mm_set_epu8(229, 241,   5, 141,  89,  37, 175, 184,
                          139, 113,  20, 221, 179, 130,  61,  16),
      simde_x_mm_set_epu8( 74,  70, 240, 235, 217, 244,  23, 139,
                          224,  48, 224, 137, 221, 180, 178,  80),
      simde_x_mm_set_epu8(152, 156, 123, 188, 153, 141,  99, 162,
                          182,  81, 122, 179, 200, 155, 120,  48) },
    { simde_x_mm_set_epu8( 30,  40, 139,  23, 169,  60,  77, 114,
                           84,  55,  70, 122,  10,  27,  47, 237),
      simde_x_mm_set_epu8(133, 159, 246, 175, 239, 136, 111, 216,
                          173,  32, 117,  64, 231, 128, 162, 145),
      simde_x_mm_set_epu8( 82, 100, 193,  99, 204,  98,  94, 165,
                          129,  44,  94,  93, 121,  78, 105, 191) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_avg_epu8(test_vec[i].a, test_vec[i].b);
    simde_assert_m128i_u8(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_avg_epu16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_x_mm_set_epu16( 5850, 55362, 21148, 12084, 65281, 34990, 37768, 27314),
      simde_x_mm_set_epu16(17137, 57217, 24643,    68, 62023, 59872, 58364, 48988),
      simde_x_mm_set_epu16(11494, 56290, 22896,  6076, 63652, 47431, 48066, 38151) },
    { simde_x_mm_set_epu16(56278,  6728, 16184, 51318, 50283, 22638, 47875, 16598),
      simde_x_mm_set_epu16(11439, 26450, 22464, 46117,   200, 13782,  6417,  5013),
      simde_x_mm_set_epu16(33859, 16589, 19324, 48718, 25242, 18210, 27146, 10806) },
    { simde_x_mm_set_epu16(56585, 41680, 21588, 12940, 58949, 45580,  8877, 11322),
      simde_x_mm_set_epu16( 1134, 16858, 64620, 61832,  9325, 17410, 30986, 30821),
      simde_x_mm_set_epu16(28860, 29269, 43104, 37386, 34137, 31495, 19932, 21072) },
    { simde_x_mm_set_epu16(44326,  6907, 17032, 43140, 43764, 37147, 19624, 24961),
      simde_x_mm_set_epu16(54082,  7517, 59166, 38362, 18444, 59374, 31747, 32567),
      simde_x_mm_set_epu16(49204,  7212, 38099, 40751, 31104, 48261, 25686, 28764) },
    { simde_x_mm_set_epu16( 8568, 10500, 57927, 43336, 23763, 20533,  5882, 34847),
      simde_x_mm_set_epu16(41965, 54962,  7618, 35181, 34501, 10468, 44645, 29346),
      simde_x_mm_set_epu16(25267, 32731, 32773, 39259, 29132, 15501, 25264, 32097) },
    { simde_x_mm_set_epu16(38897, 10848,  5543,  6844, 31880, 40592, 58264,  1176),
      simde_x_mm_set_epu16(11224, 19859, 27007, 22365, 41063, 17493, 19753, 17341),
      simde_x_mm_set_epu16(25061, 15354, 16275, 14605, 36472, 29043, 39009,  9259) },
    { simde_x_mm_set_epu16(58865,  1421, 22821, 44984, 35697,  5341, 45954, 15632),
      simde_x_mm_set_epu16(19014, 61675, 55796,  6027, 57392, 57481, 56756, 45648),
      simde_x_mm_set_epu16(38940, 31548, 39309, 25506, 46545, 31411, 51355, 30640) },
    { simde_x_mm_set_epu16( 7720, 35607, 43324, 19826, 21559, 18042,  2587, 12269),
      simde_x_mm_set_epu16(34207, 63151, 61320, 28632, 44320, 30016, 59264, 41617),
      simde_x_mm_set_epu16(20964, 49379, 52322, 24229, 32940, 24029, 30926, 26943) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_avg_epu16(test_vec[i].a, test_vec[i].b);
    simde_assert_m128i_u16(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_bslli_si128(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi64x(INT64_C(   6496650946798703471), INT64_C(   -396287401796263749)),
      simde_mm_set_epi64x(INT64_C(  -6605813106740644566), INT64_C(   -531219147355324416)) },
    { simde_mm_set_epi64x(INT64_C(   7107988146685607340), INT64_C(   2868510571032249934)),
      simde_mm_set_epi64x(INT64_C(   3068310919445479424), INT64_C(                     0)) },
    { simde_mm_set_epi64x(INT64_C(  -3567252402734959588), INT64_C(   6215759433932240554)),
      simde_mm_set_epi64x(INT64_C(  -3245938274613574196), INT64_C(  -3425363549591961600)) },
    { simde_mm_set_epi64x(INT64_C(  -9146050869496979067), INT64_C(  -5222825253597677177)),
      simde_mm_set_epi64x(INT64_C(   1910475092740014080), INT64_C(                     0)) },
    { simde_mm_set_epi64x(INT64_C(   3265799540779315855), INT64_C(  -8268657106645401588)),
      simde_mm_set_epi64x(INT64_C(  -3966950484935955532), INT64_C(  -1999585040412966912)) },
    { simde_mm_set_epi64x(INT64_C(   9038922453000221107), INT64_C(   5313242577573663941)),
      simde_mm_set_epi64x(INT64_C(   -488145415254835200), INT64_C(                     0)) },
    { simde_mm_set_epi64x(INT64_C(  -8778700548414484854), INT64_C(  -1298326344240861309)),
      simde_mm_set_epi64x(INT64_C(   4201448257113231768), INT64_C(   -148756226656698368)) },
    { simde_mm_set_epi64x(INT64_C(   3699409253586544874), INT64_C(  -4047911497723317548)),
      simde_mm_set_epi64x(INT64_C(  -1114645912149295104), INT64_C(                     0)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r;
    if (i % 2) {
      r = simde_mm_bslli_si128(test_vec[i].a, 11);
    } else {
      r = simde_mm_bslli_si128(test_vec[i].a, 5);
    }
    simde_assert_m128i_u64(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_bsrli_si128(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m128i r;
  } test_vec[16] = {
    { simde_mm_set_epi32(INT32_C(-2052173146), INT32_C(-1831463179), INT32_C( 1877888905), INT32_C( 1936033553)),
      simde_mm_set_epi32(INT32_C(          0), INT32_C(        133), INT32_C(-1370315118), INT32_C( -703138449)) },
    { simde_mm_set_epi32(INT32_C(  505541153), INT32_C(  280882166), INT32_C( -394255632), INT32_C(-1969073013)),
      simde_mm_set_epi32(INT32_C(          0), INT32_C(         30), INT32_C(  569516304), INT32_C(-1108609304)) },
    { simde_mm_set_epi32(INT32_C( -179250461), INT32_C( -340750836), INT32_C(-1275060765), INT32_C( -964595468)),
      simde_mm_set_epi32(INT32_C(          0), INT32_C(        245), INT32_C( 1356522475), INT32_C(-1332867916)) },
    { simde_mm_set_epi32(INT32_C( 1644665271), INT32_C(  540136542), INT32_C(  552223295), INT32_C( 1843061112)),
      simde_mm_set_epi32(INT32_C(          0), INT32_C(         98), INT32_C(  127514400), INT32_C(  836001312)) },
    { simde_mm_set_epi32(INT32_C( -368608329), INT32_C( 1255917842), INT32_C(   62834927), INT32_C( 1687455259)),
      simde_mm_set_epi32(INT32_C(          0), INT32_C(        234), INT32_C(  125548362), INT32_C( -607579645)) },
    { simde_mm_set_epi32(INT32_C(  794365191), INT32_C( -245663916), INT32_C( 1917959506), INT32_C(-1870120498)),
      simde_mm_set_epi32(INT32_C(          0), INT32_C(         47), INT32_C( 1494026225), INT32_C( 1534547058)) },
    { simde_mm_set_epi32(INT32_C( -775328425), INT32_C( -555627957), INT32_C(  552851244), INT32_C( -120838437)),
      simde_mm_set_epi32(INT32_C(          0), INT32_C(        209), INT32_C( -915580962), INT32_C( -506836192)) },
    { simde_mm_set_epi32(INT32_C( 1533066525), INT32_C(-1199922930), INT32_C( -546808549), INT32_C( -333790033)),
      simde_mm_set_epi32(INT32_C(          0), INT32_C(         91), INT32_C( 1623006648), INT32_C( 2057375455)) },

    { simde_mm_set_epi32(INT32_C( -187651174), INT32_C(  508437374), INT32_C(-1241260344), INT32_C(-2114721520)),
      simde_mm_set_epi32(INT32_C(          0), INT32_C(          0), INT32_C(          0), INT32_C( -187651174)) },
    { simde_mm_set_epi32(INT32_C(  697934755), INT32_C(-1316386876), INT32_C( 1066791688), INT32_C(-1334951385)),
      simde_mm_set_epi32(INT32_C(          0), INT32_C(          0), INT32_C(          0), INT32_C(  697934755)) },
    { simde_mm_set_epi32(INT32_C( 1479327103), INT32_C( 1948741625), INT32_C(  416655356), INT32_C(   32167335)),
      simde_mm_set_epi32(INT32_C(          0), INT32_C(          0), INT32_C(          0), INT32_C( 1479327103)) },
    { simde_mm_set_epi32(INT32_C(-1536299250), INT32_C( 1725038222), INT32_C( 1504364552), INT32_C( 1323768486)),
      simde_mm_set_epi32(INT32_C(          0), INT32_C(          0), INT32_C(          0), INT32_C(-1536299250)) },
    { simde_mm_set_epi32(INT32_C(-1232216892), INT32_C( 1186058354), INT32_C( 1957110000), INT32_C(   84660370)),
      simde_mm_set_epi32(INT32_C(          0), INT32_C(          0), INT32_C(          0), INT32_C(-1232216892)) },
    { simde_mm_set_epi32(INT32_C(  509795109), INT32_C(-1492196071), INT32_C( 1382299002), INT32_C(  479140151)),
      simde_mm_set_epi32(INT32_C(          0), INT32_C(          0), INT32_C(          0), INT32_C(  509795109)) },
    { simde_mm_set_epi32(INT32_C(-1066701601), INT32_C(  123253969), INT32_C(  599780728), INT32_C( -376342677)),
      simde_mm_set_epi32(INT32_C(          0), INT32_C(          0), INT32_C(          0), INT32_C(-1066701601)) },
    { simde_mm_set_epi32(INT32_C(-1270858236), INT32_C(-1886678926), INT32_C( 1543333152), INT32_C( 1202281164)),
      simde_mm_set_epi32(INT32_C(          0), INT32_C(          0), INT32_C(          0), INT32_C(-1270858236)) }
  };

  for (size_t i = 0 ; i < ((sizeof(test_vec) / sizeof(test_vec[0])) / 2) ; i++) {
    simde__m128i r = simde_mm_bsrli_si128(test_vec[i].a, 7);
    simde_assert_m128i_i64(r, ==, test_vec[i].r);
  }

  for (size_t i = ((sizeof(test_vec) / sizeof(test_vec[0])) / 2) ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i r = simde_mm_bsrli_si128(test_vec[i].a, 12);
    simde_assert_m128i_i32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_castpd_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128d a;
    simde__m128 r;
  } test_vec[8] = {
    { simde_mm_castps_pd(simde_mm_set_ps(SIMDE_FLOAT32_C( 499.48), SIMDE_FLOAT32_C(  72.83), SIMDE_FLOAT32_C(-420.10), SIMDE_FLOAT32_C( -361.15))),
      simde_mm_set_ps(SIMDE_FLOAT32_C( 499.48), SIMDE_FLOAT32_C(  72.83), SIMDE_FLOAT32_C(-420.10), SIMDE_FLOAT32_C( -361.15)) },
    { simde_mm_castps_pd(simde_mm_set_ps(SIMDE_FLOAT32_C(-412.40), SIMDE_FLOAT32_C(-314.35), SIMDE_FLOAT32_C(-851.03), SIMDE_FLOAT32_C(  128.01))),
      simde_mm_set_ps(SIMDE_FLOAT32_C(-412.40), SIMDE_FLOAT32_C(-314.35), SIMDE_FLOAT32_C(-851.03), SIMDE_FLOAT32_C(  128.01)) },
    { simde_mm_castps_pd(simde_mm_set_ps(SIMDE_FLOAT32_C(-411.93), SIMDE_FLOAT32_C( 780.67), SIMDE_FLOAT32_C(-928.22), SIMDE_FLOAT32_C(  762.24))),
      simde_mm_set_ps(SIMDE_FLOAT32_C(-411.93), SIMDE_FLOAT32_C( 780.67), SIMDE_FLOAT32_C(-928.22), SIMDE_FLOAT32_C(  762.24)) },
    { simde_mm_castps_pd(simde_mm_set_ps(SIMDE_FLOAT32_C(-614.18), SIMDE_FLOAT32_C( 644.19), SIMDE_FLOAT32_C( -41.15), SIMDE_FLOAT32_C(  871.68))),
      simde_mm_set_ps(SIMDE_FLOAT32_C(-614.18), SIMDE_FLOAT32_C( 644.19), SIMDE_FLOAT32_C( -41.15), SIMDE_FLOAT32_C(  871.68)) },
    { simde_mm_castps_pd(simde_mm_set_ps(SIMDE_FLOAT32_C( 795.82), SIMDE_FLOAT32_C( 486.26), SIMDE_FLOAT32_C(-686.59), SIMDE_FLOAT32_C(  277.69))),
      simde_mm_set_ps(SIMDE_FLOAT32_C( 795.82), SIMDE_FLOAT32_C( 486.26), SIMDE_FLOAT32_C(-686.59), SIMDE_FLOAT32_C(  277.69)) },
    { simde_mm_castps_pd(simde_mm_set_ps(SIMDE_FLOAT32_C( 221.74), SIMDE_FLOAT32_C(-655.22), SIMDE_FLOAT32_C(-366.90), SIMDE_FLOAT32_C( -245.25))),
      simde_mm_set_ps(SIMDE_FLOAT32_C( 221.74), SIMDE_FLOAT32_C(-655.22), SIMDE_FLOAT32_C(-366.90), SIMDE_FLOAT32_C( -245.25)) },
    { simde_mm_castps_pd(simde_mm_set_ps(SIMDE_FLOAT32_C( -83.75), SIMDE_FLOAT32_C( 862.26), SIMDE_FLOAT32_C(  55.37), SIMDE_FLOAT32_C(  -26.83))),
      simde_mm_set_ps(SIMDE_FLOAT32_C( -83.75), SIMDE_FLOAT32_C( 862.26), SIMDE_FLOAT32_C(  55.37), SIMDE_FLOAT32_C(  -26.83)) },
    { simde_mm_castps_pd(simde_mm_set_ps(SIMDE_FLOAT32_C(-557.26), SIMDE_FLOAT32_C(-554.56), SIMDE_FLOAT32_C(-507.07), SIMDE_FLOAT32_C(  395.47))),
      simde_mm_set_ps(SIMDE_FLOAT32_C(-557.26), SIMDE_FLOAT32_C(-554.56), SIMDE_FLOAT32_C(-507.07), SIMDE_FLOAT32_C(  395.47)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128 r = simde_mm_castpd_ps(test_vec[i].a);
    simde_assert_m128_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_castsi128_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  simde__m128i test_vec[8] = {
    simde_mm_set_epi32(INT32_C(-1784593785), INT32_C( 1037253725), INT32_C(  225827038), INT32_C(-2070942389)),
    simde_mm_set_epi32(INT32_C( 2006039830), INT32_C(  831495128), INT32_C( 1875760759), INT32_C(  315081037)),
    simde_mm_set_epi32(INT32_C( -305750616), INT32_C(  602617399), INT32_C( 1569354160), INT32_C(-1091905770)),
    simde_mm_set_epi32(INT32_C(-1852218105), INT32_C(-1464694454), INT32_C(-1287612023), INT32_C( 1418106957)),
    simde_mm_set_epi32(INT32_C( 1382189486), INT32_C(  561466363), INT32_C( -455563445), INT32_C(  733917325)),
    simde_mm_set_epi32(INT32_C( -187102213), INT32_C( -373894547), INT32_C(  335417846), INT32_C(  400855569)),
    simde_mm_set_epi32(INT32_C( 1405293845), INT32_C( -164981292), INT32_C(  180491437), INT32_C( 1551867928)),
    simde_mm_set_epi32(INT32_C(  458893421), INT32_C(-1960480477), INT32_C( 1264329759), INT32_C( 1663854158))
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_castpd_si128(simde_mm_castsi128_pd(test_vec[i]));
    simde_assert_m128i_equal(r, test_vec[i]);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_castsi128_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  simde__m128i test_vec[8] = {
    simde_mm_set_epi32(INT32_C(-1036963898), INT32_C( 1847069037), INT32_C(  740321504), INT32_C(  778754840)),
    simde_mm_set_epi32(INT32_C(  975137998), INT32_C( -252397546), INT32_C( 1504697866), INT32_C(-1327032545)),
    simde_mm_set_epi32(INT32_C(-1494981423), INT32_C( -175189577), INT32_C( 2056595322), INT32_C( 1080531273)),
    simde_mm_set_epi32(INT32_C(-1391843620), INT32_C(  424327107), INT32_C(  948927709), INT32_C( -666077781)),
    simde_mm_set_epi32(INT32_C(  951847201), INT32_C( -299846327), INT32_C(  575809604), INT32_C(-1150359231)),
    simde_mm_set_epi32(INT32_C(  837564377), INT32_C( -933128035), INT32_C( -581372672), INT32_C( -490866291)),
    simde_mm_set_epi32(INT32_C( -169157316), INT32_C( 1521943175), INT32_C(  841770394), INT32_C( -192049832)),
    simde_mm_set_epi32(INT32_C( -848324384), INT32_C(-1699878899), INT32_C( -332340467), INT32_C(  934012294))
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_castps_si128(simde_mm_castsi128_ps(test_vec[i]));
    simde_assert_m128i_i64(r, ==, test_vec[i]);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_cmpeq_epi8(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi8(INT8_C(  48), INT8_C( -17), INT8_C(  87), INT8_C(  -4),
                        INT8_C(   4), INT8_C( -44), INT8_C( 121), INT8_C(  68),
                        INT8_C(  49), INT8_C(-108), INT8_C(  49), INT8_C( -79),
                        INT8_C(  51), INT8_C( -82), INT8_C(  23), INT8_C( -58)),
      simde_mm_set_epi8(INT8_C(  87), INT8_C( -42), INT8_C(  33), INT8_C( 126),
                        INT8_C(  91), INT8_C( 115), INT8_C( -90), INT8_C(  48),
                        INT8_C( -49), INT8_C(-119), INT8_C(  23), INT8_C(  50),
                        INT8_C( -10), INT8_C( -15), INT8_C( -16), INT8_C( -58)),
      simde_mm_set_epi8(INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(  -1)) },
    { simde_mm_set_epi8(INT8_C(  90), INT8_C( -93), INT8_C( 121), INT8_C( 114),
                        INT8_C(  21), INT8_C( -52), INT8_C( -45), INT8_C( -83),
                        INT8_C(-123), INT8_C(-119), INT8_C( -53), INT8_C(-117),
                        INT8_C( -60), INT8_C( -20), INT8_C(-100), INT8_C(  26)),
      simde_mm_set_epi8(INT8_C(  67), INT8_C( -34), INT8_C(-110), INT8_C( -79),
                        INT8_C( -72), INT8_C( -43), INT8_C(  64), INT8_C( -74),
                        INT8_C(  64), INT8_C(  85), INT8_C( -71), INT8_C(  89),
                        INT8_C(  35), INT8_C(  81), INT8_C( 104), INT8_C( 111)),
      simde_mm_set_epi8(INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0)) },
    { simde_mm_set_epi8(INT8_C(  33), INT8_C(  56), INT8_C( -20), INT8_C(  49),
                        INT8_C( -77), INT8_C(-123), INT8_C( -77), INT8_C(-109),
                        INT8_C( -13), INT8_C(  91), INT8_C( 105), INT8_C(  29),
                        INT8_C(  35), INT8_C( -62), INT8_C(  39), INT8_C( -24)),
      simde_mm_set_epi8(INT8_C( -80), INT8_C( -37), INT8_C(  43), INT8_C( 121),
                        INT8_C(-104), INT8_C( -93), INT8_C(-100), INT8_C(  55),
                        INT8_C( -82), INT8_C( -92), INT8_C(  -6), INT8_C(   2),
                        INT8_C( -33), INT8_C( 114), INT8_C( -94), INT8_C(  58)),
      simde_mm_set_epi8(INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0)) },
    { simde_mm_set_epi8(INT8_C( -50), INT8_C(  20), INT8_C(  99), INT8_C(   4),
                        INT8_C(  66), INT8_C( -69), INT8_C(-117), INT8_C(  25),
                        INT8_C( -96), INT8_C( -11), INT8_C( -75), INT8_C( -79),
                        INT8_C(  88), INT8_C(-123), INT8_C( -55), INT8_C(  22)),
      simde_mm_set_epi8(INT8_C(  68), INT8_C(-117), INT8_C(-113), INT8_C(  30),
                        INT8_C(   0), INT8_C(  65), INT8_C( -61), INT8_C( -31),
                        INT8_C( -53), INT8_C(  -2), INT8_C( -47), INT8_C(  20),
                        INT8_C( -79), INT8_C(-126), INT8_C(  40), INT8_C(  81)),
      simde_mm_set_epi8(INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0)) },
    { simde_mm_set_epi8(INT8_C( 100), INT8_C( -54), INT8_C( -62), INT8_C( -41),
                        INT8_C(-110), INT8_C(  -3), INT8_C(-102), INT8_C(  -2),
                        INT8_C(  26), INT8_C( -67), INT8_C( -67), INT8_C( -73),
                        INT8_C(  18), INT8_C( 123), INT8_C( 122), INT8_C( 106)),
      simde_mm_set_epi8(INT8_C(  -5), INT8_C(   2), INT8_C( 119), INT8_C(  28),
                        INT8_C( -24), INT8_C(  12), INT8_C( 106), INT8_C( -55),
                        INT8_C( 124), INT8_C(  69), INT8_C(  31), INT8_C(-126),
                        INT8_C( -80), INT8_C( -78), INT8_C( -93), INT8_C( -23)),
      simde_mm_set_epi8(INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0)) },
    { simde_mm_set_epi8(INT8_C(  48), INT8_C( -25), INT8_C( -80), INT8_C(  17),
                        INT8_C( -70), INT8_C( -40), INT8_C(  83), INT8_C(  37),
                        INT8_C(  22), INT8_C( -91), INT8_C( -79), INT8_C(   8),
                        INT8_C(   9), INT8_C( -21), INT8_C( -51), INT8_C( -21)),
      simde_mm_set_epi8(INT8_C(  55), INT8_C( 114), INT8_C( -79), INT8_C( -59),
                        INT8_C(  15), INT8_C( -50), INT8_C( -69), INT8_C(   7),
                        INT8_C(-113), INT8_C( -95), INT8_C( 112), INT8_C(   5),
                        INT8_C( -30), INT8_C( -68), INT8_C( -27), INT8_C( -43)),
      simde_mm_set_epi8(INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0)) },
    { simde_mm_set_epi8(INT8_C(  34), INT8_C( 111), INT8_C(  52), INT8_C(  93),
                        INT8_C( -12), INT8_C(  98), INT8_C( -88), INT8_C(  63),
                        INT8_C(  64), INT8_C( -98), INT8_C(  18), INT8_C(  40),
                        INT8_C( 119), INT8_C(  68), INT8_C( -90), INT8_C( -37)),
      simde_mm_set_epi8(INT8_C(  35), INT8_C(  97), INT8_C(   3), INT8_C(  88),
                        INT8_C( -70), INT8_C( -12), INT8_C( -13), INT8_C(  52),
                        INT8_C( 127), INT8_C(  -5), INT8_C( -24), INT8_C( -10),
                        INT8_C( -21), INT8_C(-112), INT8_C( -81), INT8_C(  86)),
      simde_mm_set_epi8(INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0)) },
    { simde_mm_set_epi8(INT8_C( -25), INT8_C(-100), INT8_C( -66), INT8_C( 103),
                        INT8_C(-103), INT8_C( 116), INT8_C( -97), INT8_C( -43),
                        INT8_C( 123), INT8_C( -33), INT8_C( -71), INT8_C(-122),
                        INT8_C( 100), INT8_C( 116), INT8_C(  67), INT8_C(-119)),
      simde_mm_set_epi8(INT8_C( 103), INT8_C( -84), INT8_C( 102), INT8_C( -67),
                        INT8_C( -82), INT8_C(  14), INT8_C( -17), INT8_C( -71),
                        INT8_C( -31), INT8_C(-109), INT8_C( -84), INT8_C( -22),
                        INT8_C(  78), INT8_C(-120), INT8_C( -77), INT8_C(  -6)),
      simde_mm_set_epi8(INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_cmpeq_epi8(test_vec[i].a, test_vec[i].b);
    simde_assert_m128i_i8(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_cmpeq_epi16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi16(  5875, -30240,   4973, -24835,  -2682,  25733,   1837,  -8035),
      simde_mm_set_epi16(  5875, -30240,   9332, -24835,  -8998,  25733,   1837, -18483),
      simde_mm_set_epi16(    -1,     -1,      0,     -1,      0,     -1,     -1,      0) },
    { simde_mm_set_epi16( -1458,  12290,    394,   6014,  25725,  16049,   -659,  13250),
      simde_mm_set_epi16( -1458,  12290,    394,   6014,  25725, -30312,   -659,  20372),
      simde_mm_set_epi16(    -1,     -1,     -1,     -1,     -1,      0,     -1,      0) },
    { simde_mm_set_epi16( -4375,   1648,  -8256,  10030,  20444,  -7330,  -7889,  23879),
      simde_mm_set_epi16(  -644,   1648,  -8256,  10030,   4813,  -7330, -10599, -13677),
      simde_mm_set_epi16(     0,     -1,     -1,     -1,      0,     -1,      0,      0) },
    { simde_mm_set_epi16(-20962, -30592, -23740,  -1360,   6756,  10080,  31194, -10248),
      simde_mm_set_epi16(-20962, -19403,  31222,  12369,  10909,  10080,  31194, -10248),
      simde_mm_set_epi16(    -1,      0,      0,      0,      0,     -1,     -1,     -1) },
    { simde_mm_set_epi16( -5540, -14756, -15994,   1795,  18849,  15779,   5314, -13448),
      simde_mm_set_epi16( -5540,  14083, -16603,   1795,  28557, -32040,   5314,  -4887),
      simde_mm_set_epi16(    -1,      0,      0,     -1,      0,      0,     -1,      0) },
    { simde_mm_set_epi16(-18621,   6869, -16161, -24568, -10576,  20065,  -8241, -21658),
      simde_mm_set_epi16(-18621,   6869, -10830, -24568, -10576,  20065,  -8094, -21658),
      simde_mm_set_epi16(    -1,     -1,      0,     -1,     -1,     -1,      0,     -1) },
    { simde_mm_set_epi16(-20765,  27683,  13646,  26224, -12316,  -2556,  -1320, -15938),
      simde_mm_set_epi16( -5976,  27683,  -6395,  26224, -12316,  -2556,  -1320, -15143),
      simde_mm_set_epi16(     0,     -1,      0,     -1,     -1,     -1,     -1,      0) },
    { simde_mm_set_epi16( 25864,  17430,  25473,  24392,  27481,   2288,  24811,  18514),
      simde_mm_set_epi16( 25864,   8829,  25473,  24392,  27481,   4599,  24811,  18514),
      simde_mm_set_epi16(    -1,      0,     -1,     -1,     -1,      0,     -1,     -1) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_cmpeq_epi16(test_vec[i].a, test_vec[i].b);
    simde_assert_m128i_i16(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_cmpeq_epi32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi32(  385059296,   325951229,  -175741819,   120447133),
      simde_mm_set_epi32( -411118693,   325951229,  -175741819,   -74467379),
      simde_mm_set_epi32(          0,          -1,          -1,           0) },
    { simde_mm_set_epi32( 2086724423,  2071647391,   395772386,  -878201179),
      simde_mm_set_epi32( 2086724423,    25827198,  1685929649,   -43174974),
      simde_mm_set_epi32(         -1,           0,           0,           0) },
    { simde_mm_set_epi32(-1656549033,  -529471298,  -677159845, -1011499644),
      simde_mm_set_epi32(-1108138959,  2008596507,    36966751, -1011499644),
      simde_mm_set_epi32(          0,           0,           0,          -1) },
    { simde_mm_set_epi32(  -42154427,   232395060,   315449676,  -694564205),
      simde_mm_set_epi32(-1781616670,   232395060,   315449676,  -694564205),
      simde_mm_set_epi32(          0,          -1,          -1,          -1) },
    { simde_mm_set_epi32(-1373730688, -1555760464,   442771296,  2044385272),
      simde_mm_set_epi32( -819547083, -1555760464,   442771296,  2044385272),
      simde_mm_set_epi32(          0,          -1,          -1,          -1) },
    { simde_mm_set_epi32( -285007987,  1222927916,  -234086536,   711157928),
      simde_mm_set_epi32( -285007987,  1222927916,  1235303843,   711157928),
      simde_mm_set_epi32(         -1,          -1,           0,          -1) },
    { simde_mm_set_epi32( 1734698060,  -250509290,  -430142591,   970705024),
      simde_mm_set_epi32( 1734698060, -1399422252,  -430142591, -1199939349),
      simde_mm_set_epi32(         -1,           0,          -1,           0) },
    { simde_mm_set_epi32( 1285559999,  -709744735, -1852486552,  -530433851),
      simde_mm_set_epi32( 1285559999,  -709744735, -1768521466,  -530433851),
      simde_mm_set_epi32(         -1,          -1,           0,          -1) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_cmpeq_epi32(test_vec[i].a, test_vec[i].b);
    simde_assert_m128i_i32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_cmpeq_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128d a;
    simde__m128d b;
    simde__m128i r;
  } test_vec[8] = {
   { simde_mm_set_pd(SIMDE_FLOAT64_C(  780.35), SIMDE_FLOAT64_C(  826.07)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  625.03), SIMDE_FLOAT64_C(  826.07)),
      simde_mm_set_epi32(INT32_C( 0), INT32_C( 0), INT32_C(-1), INT32_C(-1)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -334.66), SIMDE_FLOAT64_C(  476.36)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -334.66), SIMDE_FLOAT64_C(  556.75)),
      simde_mm_set_epi32(INT32_C(-1), INT32_C(-1), INT32_C( 0), INT32_C( 0)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  324.97), SIMDE_FLOAT64_C(  726.67)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -886.03), SIMDE_FLOAT64_C(  556.75)),
      simde_mm_set_epi32(INT32_C( 0), INT32_C( 0), INT32_C( 0), INT32_C( 0)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  432.42), SIMDE_FLOAT64_C(  208.20)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -886.03), SIMDE_FLOAT64_C(  556.75)),
      simde_mm_set_epi32(INT32_C( 0), INT32_C( 0), INT32_C( 0), INT32_C( 0)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  361.87), SIMDE_FLOAT64_C( -173.19)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  190.30), SIMDE_FLOAT64_C( -730.35)),
      simde_mm_set_epi32(INT32_C( 0), INT32_C( 0), INT32_C( 0), INT32_C( 0)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  187.80), SIMDE_FLOAT64_C( -428.45)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  754.99), SIMDE_FLOAT64_C( -730.35)),
      simde_mm_set_epi32(INT32_C( 0), INT32_C( 0), INT32_C( 0), INT32_C( 0)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(   34.65), SIMDE_FLOAT64_C(  814.87)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  105.60), SIMDE_FLOAT64_C(  292.36)),
      simde_mm_set_epi32(INT32_C( 0), INT32_C( 0), INT32_C( 0), INT32_C( 0)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  221.70), SIMDE_FLOAT64_C( -277.53)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -578.28), SIMDE_FLOAT64_C(  292.36)),
      simde_mm_set_epi32(INT32_C( 0), INT32_C( 0), INT32_C( 0), INT32_C( 0)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_castpd_si128(simde_mm_cmpeq_pd(test_vec[i].a, test_vec[i].b));
    simde_assert_m128i_i32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_cmpeq_sd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  for (int i = 0 ; i < TEST_PREFERRED_ITERATIONS ; i++) {
    simde__m128d a, b, r;
    int rn = munit_rand_int_range(0, 1);

    a.f64[0] = random_f64_range(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    a.f64[1] = random_f64_range(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    b.f64[0] = rn ? a.f64[0] : random_f64_range(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    b.f64[1] = random_f64_range(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));

    r = simde_mm_cmpeq_sd(a, b);

    munit_assert_uint64(r.u64[0], ==, rn ? ~UINT64_C(0) : UINT64_C(0));
    munit_assert_double(r.f64[1], ==, a.f64[1]);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_cmpneq_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128d a;
    simde__m128d b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  -17.42), SIMDE_FLOAT64_C( -471.42)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -120.90), SIMDE_FLOAT64_C( -471.42)),
      simde_mm_set_epi64x(INT64_C(-1), INT64_C( 0)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  174.13), SIMDE_FLOAT64_C(  302.06)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -462.00), SIMDE_FLOAT64_C(  302.06)),
      simde_mm_set_epi64x(INT64_C(-1), INT64_C( 0)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  456.61), SIMDE_FLOAT64_C(  -31.59)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  456.61), SIMDE_FLOAT64_C(  -31.59)),
      simde_mm_set_epi64x(INT64_C( 0), INT64_C( 0)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  863.75), SIMDE_FLOAT64_C(  743.68)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  863.75), SIMDE_FLOAT64_C( -940.38)),
      simde_mm_set_epi64x(INT64_C( 0), INT64_C(-1)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -207.80), SIMDE_FLOAT64_C(  181.86)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -207.80), SIMDE_FLOAT64_C(  980.93)),
      simde_mm_set_epi64x(INT64_C( 0), INT64_C(-1)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -330.41), SIMDE_FLOAT64_C(  936.80)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -223.97), SIMDE_FLOAT64_C(  936.80)),
      simde_mm_set_epi64x(INT64_C(-1), INT64_C( 0)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -293.06), SIMDE_FLOAT64_C( -978.73)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -858.76), SIMDE_FLOAT64_C( -978.73)),
      simde_mm_set_epi64x(INT64_C(-1), INT64_C( 0)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  215.10), SIMDE_FLOAT64_C( -720.29)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -813.22), SIMDE_FLOAT64_C(  235.59)),
      simde_mm_set_epi64x(INT64_C(-1), INT64_C(-1)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_castpd_si128(simde_mm_cmpneq_pd(test_vec[i].a, test_vec[i].b));
    simde_assert_m128i_i64(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_cmpneq_sd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128d a;
    simde__m128d b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  -17.42), SIMDE_FLOAT64_C( -471.42)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -120.90), SIMDE_FLOAT64_C( -471.42)),
      simde_mm_set_epi64x(   UINT64_C(0),               UINT64_C(0)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  174.13), SIMDE_FLOAT64_C(  302.06)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -462.00), SIMDE_FLOAT64_C(  302.06)),
      simde_mm_set_epi64x(   UINT64_C(0),               UINT64_C(0)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  456.61), SIMDE_FLOAT64_C(  -31.59)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  456.61), SIMDE_FLOAT64_C(  -31.59)),
      simde_mm_set_epi64x(   UINT64_C(0),               UINT64_C(0)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  863.75), SIMDE_FLOAT64_C(  743.68)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  863.75), SIMDE_FLOAT64_C( -940.38)),
      simde_mm_set_epi64x(   UINT64_C(0),              ~UINT64_C(0)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -207.80), SIMDE_FLOAT64_C(  181.86)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -207.80), SIMDE_FLOAT64_C(  980.93)),
      simde_mm_set_epi64x(   UINT64_C(0),              ~UINT64_C(0)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -330.41), SIMDE_FLOAT64_C(  936.80)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -223.97), SIMDE_FLOAT64_C(  936.80)),
      simde_mm_set_epi64x(   UINT64_C(0),               UINT64_C(0)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -293.06), SIMDE_FLOAT64_C( -978.73)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -858.76), SIMDE_FLOAT64_C( -978.73)),
      simde_mm_set_epi64x(   UINT64_C(0),               UINT64_C(0)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  215.10), SIMDE_FLOAT64_C( -720.29)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -813.22), SIMDE_FLOAT64_C(  235.59)),
      simde_mm_set_epi64x(   UINT64_C(0),              ~UINT64_C(0)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_cmpneq_sd(test_vec[i].a, test_vec[i].b);
    munit_assert_uint64(r.u64[0], ==, test_vec[i].r.u64[0]);
    munit_assert_double(r.f64[1], ==, test_vec[i].a.f64[1]);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_cmplt_epi8(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi8(INT8_C( -98), INT8_C( 126), INT8_C( -78), INT8_C( -97),
                        INT8_C( -35), INT8_C( -49), INT8_C( -62), INT8_C(  -8),
                        INT8_C( -88), INT8_C(  71), INT8_C(  16), INT8_C(  -4),
                        INT8_C(  69), INT8_C( -61), INT8_C(  47), INT8_C(  84)),
      simde_mm_set_epi8(INT8_C(   5), INT8_C(-114), INT8_C( -27), INT8_C( -61),
                        INT8_C(  56), INT8_C( 115), INT8_C( -53), INT8_C(  16),
                        INT8_C( -80), INT8_C( -18), INT8_C(  83), INT8_C(  -9),
                        INT8_C(  -3), INT8_C(  36), INT8_C( -57), INT8_C(  89)),
      simde_mm_set_epi8(INT8_C(  -1), INT8_C(   0), INT8_C(  -1), INT8_C(  -1),
                        INT8_C(  -1), INT8_C(  -1), INT8_C(  -1), INT8_C(  -1),
                        INT8_C(  -1), INT8_C(   0), INT8_C(  -1), INT8_C(   0),
                        INT8_C(   0), INT8_C(  -1), INT8_C(   0), INT8_C(  -1)) },
    { simde_mm_set_epi8(INT8_C(  94), INT8_C(  78), INT8_C( -26), INT8_C(-126),
                        INT8_C( -98), INT8_C(  65), INT8_C(  38), INT8_C( -71),
                        INT8_C( -54), INT8_C(  20), INT8_C( -52), INT8_C(  55),
                        INT8_C( -76), INT8_C(  37), INT8_C( -95), INT8_C(  91)),
      simde_mm_set_epi8(INT8_C( -10), INT8_C( -43), INT8_C(  70), INT8_C(  -4),
                        INT8_C( -89), INT8_C( -31), INT8_C( -61), INT8_C(  81),
                        INT8_C(  64), INT8_C( -78), INT8_C(  14), INT8_C( 125),
                        INT8_C(  81), INT8_C(  62), INT8_C(-124), INT8_C(  39)),
      simde_mm_set_epi8(INT8_C(   0), INT8_C(   0), INT8_C(  -1), INT8_C(  -1),
                        INT8_C(  -1), INT8_C(   0), INT8_C(   0), INT8_C(  -1),
                        INT8_C(  -1), INT8_C(   0), INT8_C(  -1), INT8_C(  -1),
                        INT8_C(  -1), INT8_C(  -1), INT8_C(   0), INT8_C(   0)) },
    { simde_mm_set_epi8(INT8_C( 103), INT8_C(  49), INT8_C(  24), INT8_C(   0),
                        INT8_C( -50), INT8_C(  64), INT8_C(  11), INT8_C( 101),
                        INT8_C(  39), INT8_C(  41), INT8_C(-111), INT8_C( -32),
                        INT8_C(  91), INT8_C(  86), INT8_C(-117), INT8_C( 115)),
      simde_mm_set_epi8(INT8_C( -44), INT8_C(  47), INT8_C( -14), INT8_C( 109),
                        INT8_C(  44), INT8_C(  97), INT8_C( -41), INT8_C(  53),
                        INT8_C(-121), INT8_C( -57), INT8_C(  54), INT8_C( 124),
                        INT8_C(  50), INT8_C( -73), INT8_C( -30), INT8_C( -62)),
      simde_mm_set_epi8(INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(  -1),
                        INT8_C(  -1), INT8_C(  -1), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(  -1), INT8_C(  -1),
                        INT8_C(   0), INT8_C(   0), INT8_C(  -1), INT8_C(   0)) },
    { simde_mm_set_epi8(INT8_C(-110), INT8_C(   5), INT8_C(  41), INT8_C(  -3),
                        INT8_C(-114), INT8_C(  14), INT8_C(-117), INT8_C( -89),
                        INT8_C(  52), INT8_C(  62), INT8_C(  41), INT8_C( -25),
                        INT8_C( 114), INT8_C(  56), INT8_C(  58), INT8_C( -99)),
      simde_mm_set_epi8(INT8_C( -31), INT8_C( -36), INT8_C(-126), INT8_C( -69),
                        INT8_C( 113), INT8_C( -30), INT8_C( -24), INT8_C(  69),
                        INT8_C( -15), INT8_C(-110), INT8_C(  23), INT8_C(  87),
                        INT8_C(-127), INT8_C( -64), INT8_C( -38), INT8_C( -83)),
      simde_mm_set_epi8(INT8_C(  -1), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(  -1), INT8_C(   0), INT8_C(  -1), INT8_C(  -1),
                        INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(  -1),
                        INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(  -1)) },
    { simde_mm_set_epi8(INT8_C( -38), INT8_C( -67), INT8_C( -79), INT8_C( -41),
                        INT8_C(-114), INT8_C(  37), INT8_C( -71), INT8_C(  11),
                        INT8_C( 105), INT8_C( 102), INT8_C(  48), INT8_C( 127),
                        INT8_C(  84), INT8_C( 115), INT8_C(-102), INT8_C( -24)),
      simde_mm_set_epi8(INT8_C(  94), INT8_C( -20), INT8_C( -97), INT8_C(  -2),
                        INT8_C(-113), INT8_C(  46), INT8_C( 123), INT8_C(  -9),
                        INT8_C(  35), INT8_C( -47), INT8_C(  90), INT8_C( -73),
                        INT8_C(-122), INT8_C(  -3), INT8_C(-116), INT8_C(  -4)),
      simde_mm_set_epi8(INT8_C(  -1), INT8_C(  -1), INT8_C(   0), INT8_C(  -1),
                        INT8_C(  -1), INT8_C(  -1), INT8_C(  -1), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(  -1), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(  -1)) },
    { simde_mm_set_epi8(INT8_C(  27), INT8_C(  41), INT8_C(  36), INT8_C( -97),
                        INT8_C( -84), INT8_C( 108), INT8_C( -37), INT8_C( -69),
                        INT8_C( -29), INT8_C(  45), INT8_C( 101), INT8_C( 104),
                        INT8_C( 102), INT8_C( -85), INT8_C(   3), INT8_C( 124)),
      simde_mm_set_epi8(INT8_C(-119), INT8_C(  16), INT8_C( -80), INT8_C(  97),
                        INT8_C(  97), INT8_C( -44), INT8_C(  71), INT8_C( -43),
                        INT8_C(  39), INT8_C( -54), INT8_C(  15), INT8_C( -61),
                        INT8_C( 100), INT8_C( -92), INT8_C(   5), INT8_C( -93)),
      simde_mm_set_epi8(INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(  -1),
                        INT8_C(  -1), INT8_C(   0), INT8_C(  -1), INT8_C(  -1),
                        INT8_C(  -1), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(  -1), INT8_C(   0)) },
    { simde_mm_set_epi8(INT8_C(  53), INT8_C(  82), INT8_C(  -6), INT8_C(  99),
                        INT8_C(  95), INT8_C( -34), INT8_C( -90), INT8_C( -14),
                        INT8_C( -43), INT8_C( -72), INT8_C( -83), INT8_C(-104),
                        INT8_C(  -1), INT8_C( -60), INT8_C( 103), INT8_C( -66)),
      simde_mm_set_epi8(INT8_C(  13), INT8_C( 118), INT8_C(  25), INT8_C(  60),
                        INT8_C( -83), INT8_C( -43), INT8_C(  90), INT8_C(  54),
                        INT8_C( -84), INT8_C(-125), INT8_C( -41), INT8_C(  52),
                        INT8_C(  18), INT8_C(  46), INT8_C( 126), INT8_C( -65)),
      simde_mm_set_epi8(INT8_C(   0), INT8_C(  -1), INT8_C(  -1), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(  -1), INT8_C(  -1),
                        INT8_C(   0), INT8_C(   0), INT8_C(  -1), INT8_C(  -1),
                        INT8_C(  -1), INT8_C(  -1), INT8_C(  -1), INT8_C(  -1)) },
    { simde_mm_set_epi8(INT8_C(  43), INT8_C( 123), INT8_C( -13), INT8_C(  35),
                        INT8_C(-119), INT8_C(  53), INT8_C( -35), INT8_C( -46),
                        INT8_C(  44), INT8_C(  69), INT8_C(  50), INT8_C(-120),
                        INT8_C(   2), INT8_C(  50), INT8_C( -95), INT8_C(  46)),
      simde_mm_set_epi8(INT8_C( -57), INT8_C( -76), INT8_C(-104), INT8_C(-127),
                        INT8_C( -27), INT8_C( 127), INT8_C( 127), INT8_C(-109),
                        INT8_C(  40), INT8_C( -63), INT8_C(  87), INT8_C( -27),
                        INT8_C(  -1), INT8_C(-101), INT8_C(  11), INT8_C(  44)),
      simde_mm_set_epi8(INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(  -1), INT8_C(  -1), INT8_C(  -1), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(  -1), INT8_C(  -1),
                        INT8_C(   0), INT8_C(   0), INT8_C(  -1), INT8_C(   0)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i r = simde_mm_cmplt_epi8(test_vec[i].a, test_vec[i].b);
    simde_assert_m128i_i8(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_cmplt_epi16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi16(-19152,   7219,   8875, -12109,  -6164, -29571,  29544,  12828),
      simde_mm_set_epi16(-19152,  -1176, -32721,  28268,  28536, -24890, -20501,  12828),
      simde_mm_set_epi16(     0,      0,      0,     -1,     -1,     -1,      0,      0) },
    { simde_mm_set_epi16(  -385,  10411,  -4671,  18534,  18234,   8064, -32746,   1460),
      simde_mm_set_epi16(-11261,  19475,  -4671, -23700,   8656,   8064, -28801,   5582),
      simde_mm_set_epi16(     0,     -1,      0,      0,      0,      0,     -1,     -1) },
    { simde_mm_set_epi16( 23112,  21760, -29652,  -7707,   4438, -14112,    617, -29125),
      simde_mm_set_epi16(-20847, -17750,   7413,  13270,  30220, -14112,   -140,  23495),
      simde_mm_set_epi16(     0,      0,     -1,     -1,     -1,      0,      0,     -1) },
    { simde_mm_set_epi16( 12262, -26458, -17793,  15097, -28884,    -39,  29206,  24614),
      simde_mm_set_epi16(-12392, -30769, -17793,  15097,  22525,   7510,  28529,  -9470),
      simde_mm_set_epi16(     0,      0,      0,      0,     -1,     -1,      0,      0) },
    { simde_mm_set_epi16( 14581,  30465,  26611, -25355,  12222, -12322,    176,  -4760),
      simde_mm_set_epi16( 10242,  15750, -11513,   7111, -29171, -12322,    176,  -4760),
      simde_mm_set_epi16(     0,      0,      0,     -1,      0,      0,      0,      0) },
    { simde_mm_set_epi16(-12610,  30415, -22748,   8564, -28400, -22984, -31130,   2400),
      simde_mm_set_epi16( 17489, -18807,  19401,    -73, -28400,  -7356,  31412,   2400),
      simde_mm_set_epi16(    -1,      0,     -1,      0,      0,     -1,     -1,      0) },
    { simde_mm_set_epi16(  5617,  -8984,  20729,  15025, -12038, -32017, -24693,  -3874),
      simde_mm_set_epi16( -8219,  19022, -28515,  15025,  -2982,   -314,  16536, -17813),
      simde_mm_set_epi16(     0,     -1,      0,      0,     -1,     -1,     -1,      0) },
    { simde_mm_set_epi16(  3028,  25056, -30420,   3400,  27498, -24168, -10264,  -5651),
      simde_mm_set_epi16( 16763,   3971, -30420, -13950,  26793, -27284,  22512, -19434),
      simde_mm_set_epi16(    -1,      0,      0,      0,      0,      0,     -1,      0) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_cmplt_epi16(test_vec[i].a, test_vec[i].b);
    simde_assert_m128i_i16(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_cmplt_epi32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi32(-1255138253,   581685427,  -403927939,  1936208412),
      simde_mm_set_epi32(  212007784, -2144375188,  1870175942,  1936208412),
      simde_mm_set_epi32(         -1,           0,          -1,           0) },
    { simde_mm_set_epi32(-1412605706,  -573136614,  -789373589,  1859272017),
      simde_mm_set_epi32(-1412605706,  -306100122,  1194991488, -2146040396),
      simde_mm_set_epi32(          0,          -1,          -1,           0) },
    { simde_mm_set_epi32(-1857828629,  -865462431,  1845130162,  -790702535),
      simde_mm_set_epi32( 1020632409,  -786544507,   219144900,   222814568),
      simde_mm_set_epi32(         -1,          -1,           0,          -1) },
    { simde_mm_set_epi32(-1366181206,   485831638,  1980524634,    -9151545),
      simde_mm_set_epi32(-1932199485,   327347510,   706051828,  -541415230),
      simde_mm_set_epi32(          0,           0,           0,           0) },
    { simde_mm_set_epi32(  803641510, -1166066951, -1892876327,  1914069030),
      simde_mm_set_epi32( -812087345, -1002684270,  1476205910,  1869732610),
      simde_mm_set_epi32(          0,          -1,          -1,           0) },
    { simde_mm_set_epi32(-1773657387, -1529382252,  1397468980,  1171964570),
      simde_mm_set_epi32(  955610881,  1744018677,   801034206,  1171964570),
      simde_mm_set_epi32(         -1,          -1,           0,           0) },
    { simde_mm_set_epi32(-1807229965, -1210178631,  1522043695, -1735369601),
      simde_mm_set_epi32(-1560329504,  1101415557,  1311721597,  1371106332),
      simde_mm_set_epi32(         -1,          -1,           0,          -1) },
    { simde_mm_set_epi32( 1146205833,  1271529399,  1661264708,  2058651784),
      simde_mm_set_epi32(  624079870,  1320739553, -1066082248, -1119644266),
      simde_mm_set_epi32(          0,          -1,           0,           0) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_cmplt_epi32(test_vec[i].a, test_vec[i].b);
    simde_assert_m128i_i32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_cmplt_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128d a;
    simde__m128d b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  415.53), SIMDE_FLOAT64_C(  -98.38)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  415.53), SIMDE_FLOAT64_C( -729.13)),
      simde_mm_set_epi64x(INT64_C( 0), INT64_C( 0)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -102.02), SIMDE_FLOAT64_C( -129.13)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  345.59), SIMDE_FLOAT64_C( -901.28)),
      simde_mm_set_epi64x(INT64_C(-1), INT64_C( 0)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  733.11), SIMDE_FLOAT64_C(  268.99)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  733.11), SIMDE_FLOAT64_C(  632.42)),
      simde_mm_set_epi64x(INT64_C( 0), INT64_C(-1)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  988.26), SIMDE_FLOAT64_C(    0.67)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -735.83), SIMDE_FLOAT64_C(  857.46)),
      simde_mm_set_epi64x(INT64_C( 0), INT64_C(-1)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  631.80), SIMDE_FLOAT64_C(  -84.12)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  596.99), SIMDE_FLOAT64_C(  -84.12)),
      simde_mm_set_epi64x(INT64_C( 0), INT64_C( 0)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  633.74), SIMDE_FLOAT64_C(  134.88)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -981.15), SIMDE_FLOAT64_C( -897.95)),
      simde_mm_set_epi64x(INT64_C( 0), INT64_C( 0)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  995.74), SIMDE_FLOAT64_C( -864.54)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -773.77), SIMDE_FLOAT64_C( -294.67)),
      simde_mm_set_epi64x(INT64_C( 0), INT64_C(-1)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -847.57), SIMDE_FLOAT64_C(  363.82)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  743.31), SIMDE_FLOAT64_C( -671.22)),
      simde_mm_set_epi64x(INT64_C(-1), INT64_C( 0)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_castpd_si128(simde_mm_cmplt_pd(test_vec[i].a, test_vec[i].b));
    simde_assert_m128i_i64(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_cmplt_sd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128d a;
    simde__m128d b;
    int64_t r;
  } test_vec[8] = {
    { simde_mm_set_pd(       SIMDE_FLOAT64_C(  731.11),  SIMDE_FLOAT64_C( -222.95)),
      simde_mm_set_pd(       SIMDE_FLOAT64_C( -336.46),  SIMDE_FLOAT64_C(  540.91)),
      ~INT64_C(0) },
    { simde_mm_set_pd(       SIMDE_FLOAT64_C( -256.50),  SIMDE_FLOAT64_C( -689.24)),
      simde_mm_set_pd(       SIMDE_FLOAT64_C(  750.53),  SIMDE_FLOAT64_C(  140.47)),
      ~INT64_C(0) },
    { simde_mm_set_pd(       SIMDE_FLOAT64_C(  494.12),  SIMDE_FLOAT64_C(   -4.44)),
      simde_mm_set_pd(       SIMDE_FLOAT64_C( -897.32),  SIMDE_FLOAT64_C(  109.86)),
      ~INT64_C(0) },
    { simde_mm_set_pd(       SIMDE_FLOAT64_C( -223.20),  SIMDE_FLOAT64_C(  -82.73)),
      simde_mm_set_pd(       SIMDE_FLOAT64_C(  123.05),  SIMDE_FLOAT64_C( -323.35)),
       INT64_C(0) },
    { simde_mm_set_pd(       SIMDE_FLOAT64_C( -631.48),  SIMDE_FLOAT64_C(  865.56)),
      simde_mm_set_pd(       SIMDE_FLOAT64_C( -801.61),  SIMDE_FLOAT64_C(  442.41)),
       INT64_C(0) },
    { simde_mm_set_pd(       SIMDE_FLOAT64_C( -400.88),  SIMDE_FLOAT64_C( -544.39)),
      simde_mm_set_pd(       SIMDE_FLOAT64_C( -979.29),  SIMDE_FLOAT64_C(  757.50)),
      ~INT64_C(0) },
    { simde_mm_set_pd(       SIMDE_FLOAT64_C( -415.28),  SIMDE_FLOAT64_C(  485.32)),
      simde_mm_set_pd(       SIMDE_FLOAT64_C(  205.81),  SIMDE_FLOAT64_C( -642.02)),
       INT64_C(0) },
    { simde_mm_set_pd(       SIMDE_FLOAT64_C(   -6.82),  SIMDE_FLOAT64_C(  -97.75)),
      simde_mm_set_pd(       SIMDE_FLOAT64_C( -138.73),  SIMDE_FLOAT64_C( -545.99)),
       INT64_C(0) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r_d = simde_mm_cmplt_sd(test_vec[i].a, test_vec[i].b);
    simde__m128i r_i = simde_mm_castpd_si128(r_d);
    munit_assert_double(r_i.i64[0], ==, test_vec[i].r);
    munit_assert_int64(r_d.f64[1], ==, test_vec[i].a.f64[1]);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_cmpnlt_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128d a;
    simde__m128d b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  852.01), SIMDE_FLOAT64_C( -875.21)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  852.01), SIMDE_FLOAT64_C( -124.49)),
      simde_mm_set_epi64x(INT64_C(-1), INT64_C( 0)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  396.43), SIMDE_FLOAT64_C( -754.13)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  396.43), SIMDE_FLOAT64_C( -446.22)),
      simde_mm_set_epi64x(INT64_C(-1), INT64_C( 0)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  253.13), SIMDE_FLOAT64_C(  198.68)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  253.13), SIMDE_FLOAT64_C(  828.60)),
      simde_mm_set_epi64x(INT64_C(-1), INT64_C( 0)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  137.84), SIMDE_FLOAT64_C( -995.54)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  137.84), SIMDE_FLOAT64_C( -366.89)),
      simde_mm_set_epi64x(INT64_C(-1), INT64_C( 0)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  981.94), SIMDE_FLOAT64_C( -371.83)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -999.24), SIMDE_FLOAT64_C(  567.77)),
      simde_mm_set_epi64x(INT64_C(-1), INT64_C( 0)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  471.23), SIMDE_FLOAT64_C( -984.85)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -365.65), SIMDE_FLOAT64_C(  102.67)),
      simde_mm_set_epi64x(INT64_C(-1), INT64_C( 0)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -625.86), SIMDE_FLOAT64_C(  -91.22)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -928.96), SIMDE_FLOAT64_C( -311.29)),
      simde_mm_set_epi64x(INT64_C(-1), INT64_C(-1)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -444.22), SIMDE_FLOAT64_C(  458.27)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  882.56), SIMDE_FLOAT64_C(  290.13)),
      simde_mm_set_epi64x(INT64_C( 0), INT64_C(-1)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_castpd_si128(simde_mm_cmpnlt_pd(test_vec[i].a, test_vec[i].b));
    simde_assert_m128i_i64(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_cmpnlt_sd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128d a;
    simde__m128d b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  852.01), SIMDE_FLOAT64_C( -875.21)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  852.01), SIMDE_FLOAT64_C( -124.49)),
      simde_x_mm_set_epu64x(UINT64_C(0), UINT64_C(0)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  396.43), SIMDE_FLOAT64_C( -754.13)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  396.43), SIMDE_FLOAT64_C( -446.22)),
      simde_x_mm_set_epu64x(UINT64_C(0), UINT64_C(0)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  253.13), SIMDE_FLOAT64_C(  198.68)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  253.13), SIMDE_FLOAT64_C(  828.60)),
      simde_x_mm_set_epu64x(UINT64_C(0), UINT64_C(0)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  137.84), SIMDE_FLOAT64_C( -995.54)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  137.84), SIMDE_FLOAT64_C( -366.89)),
      simde_x_mm_set_epu64x(UINT64_C(0), UINT64_C(0)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  981.94), SIMDE_FLOAT64_C( -371.83)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -999.24), SIMDE_FLOAT64_C(  567.77)),
      simde_x_mm_set_epu64x(UINT64_C(0), UINT64_C(0)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  471.23), SIMDE_FLOAT64_C( -984.85)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -365.65), SIMDE_FLOAT64_C(  102.67)),
      simde_x_mm_set_epu64x(UINT64_C(0), UINT64_C(0)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -625.86), SIMDE_FLOAT64_C(  -91.22)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -928.96), SIMDE_FLOAT64_C( -311.29)),
      simde_x_mm_set_epu64x(UINT64_C(0), ~UINT64_C(0)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -444.22), SIMDE_FLOAT64_C(  458.27)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  882.56), SIMDE_FLOAT64_C(  290.13)),
      simde_x_mm_set_epu64x(UINT64_C(0), ~UINT64_C(0)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_cmpnlt_sd(test_vec[i].a, test_vec[i].b);
    munit_assert_uint64(r.u64[0], ==, test_vec[i].r.u64[0]);
    munit_assert_double(r.f64[1], ==, test_vec[i].a.f64[1]);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_cmple_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128d a;
    simde__m128d b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  543.54), SIMDE_FLOAT64_C( -463.43)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  803.80), SIMDE_FLOAT64_C( -383.88)),
      simde_mm_set_epi64x(INT64_C(-1), INT64_C(-1)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -420.41), SIMDE_FLOAT64_C(  497.43)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -592.95), SIMDE_FLOAT64_C( -224.51)),
      simde_mm_set_epi64x(INT64_C( 0), INT64_C( 0)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -921.01), SIMDE_FLOAT64_C( -601.69)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -921.01), SIMDE_FLOAT64_C( -730.20)),
      simde_mm_set_epi64x(INT64_C(-1), INT64_C( 0)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -456.56), SIMDE_FLOAT64_C(  380.21)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -456.56), SIMDE_FLOAT64_C(  380.21)),
      simde_mm_set_epi64x(INT64_C(-1), INT64_C(-1)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  317.08), SIMDE_FLOAT64_C(  136.54)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  944.53), SIMDE_FLOAT64_C(  370.42)),
      simde_mm_set_epi64x(INT64_C(-1), INT64_C(-1)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -193.09), SIMDE_FLOAT64_C(  515.21)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -63.27), SIMDE_FLOAT64_C(  515.21)),
      simde_mm_set_epi64x(INT64_C(-1), INT64_C(-1)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(   14.93), SIMDE_FLOAT64_C(  166.91)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   14.93), SIMDE_FLOAT64_C( -633.50)),
      simde_mm_set_epi64x(INT64_C(-1), INT64_C( 0)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  121.98), SIMDE_FLOAT64_C( -542.50)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  121.98), SIMDE_FLOAT64_C( -244.93)),
      simde_mm_set_epi64x(INT64_C(-1), INT64_C(-1)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_castpd_si128(simde_mm_cmple_pd(test_vec[i].a, test_vec[i].b));
    simde_assert_m128i_i64(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_cmple_sd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128d a;
    simde__m128d b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  543.54), SIMDE_FLOAT64_C( -463.43)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  803.80), SIMDE_FLOAT64_C( -383.88)),
      simde_x_mm_set_epu64x(UINT64_C(0), ~UINT64_C(0)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -420.41), SIMDE_FLOAT64_C(  497.43)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -592.95), SIMDE_FLOAT64_C( -224.51)),
      simde_x_mm_set_epu64x(UINT64_C(0), UINT64_C(0)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -921.01), SIMDE_FLOAT64_C( -601.69)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -921.01), SIMDE_FLOAT64_C( -730.20)),
      simde_x_mm_set_epu64x(UINT64_C(0), UINT64_C(0)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -456.56), SIMDE_FLOAT64_C(  380.21)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -456.56), SIMDE_FLOAT64_C(  380.21)),
      simde_x_mm_set_epu64x(UINT64_C(0), ~UINT64_C(0)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  317.08), SIMDE_FLOAT64_C(  136.54)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  944.53), SIMDE_FLOAT64_C(  370.42)),
      simde_x_mm_set_epu64x(UINT64_C(0), ~UINT64_C(0)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -193.09), SIMDE_FLOAT64_C(  515.21)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -63.27), SIMDE_FLOAT64_C(  515.21)),
      simde_x_mm_set_epu64x(UINT64_C(0), ~UINT64_C(0)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(   14.93), SIMDE_FLOAT64_C(  166.91)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   14.93), SIMDE_FLOAT64_C( -633.50)),
      simde_x_mm_set_epu64x(UINT64_C(0), UINT64_C(0)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  121.98), SIMDE_FLOAT64_C( -542.50)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  121.98), SIMDE_FLOAT64_C( -244.93)),
      simde_x_mm_set_epu64x(UINT64_C(0), ~UINT64_C(0)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_cmple_sd(test_vec[i].a, test_vec[i].b);
    munit_assert_uint64(r.u64[0], ==, test_vec[i].r.u64[0]);
    munit_assert_double(r.f64[1], ==, test_vec[i].a.f64[1]);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_cmpnle_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128d a;
    simde__m128d b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  -50.93), SIMDE_FLOAT64_C( -877.25)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -50.93), SIMDE_FLOAT64_C(   61.42)),
      simde_mm_set_epi64x(INT64_C( 0), INT64_C( 0)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  567.19), SIMDE_FLOAT64_C(  768.82)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -689.51), SIMDE_FLOAT64_C(  768.82)),
      simde_mm_set_epi64x(INT64_C(-1), INT64_C( 0)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  625.00), SIMDE_FLOAT64_C(  979.36)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   59.83), SIMDE_FLOAT64_C(  979.36)),
      simde_mm_set_epi64x(INT64_C(-1), INT64_C( 0)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -994.58), SIMDE_FLOAT64_C(  130.45)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -720.49), SIMDE_FLOAT64_C(  130.45)),
      simde_mm_set_epi64x(INT64_C( 0), INT64_C( 0)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  889.79), SIMDE_FLOAT64_C( -677.25)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  889.79), SIMDE_FLOAT64_C( -677.25)),
      simde_mm_set_epi64x(INT64_C( 0), INT64_C( 0)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  802.11), SIMDE_FLOAT64_C( -926.46)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -136.48), SIMDE_FLOAT64_C( -926.46)),
      simde_mm_set_epi64x(INT64_C(-1), INT64_C( 0)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -579.79), SIMDE_FLOAT64_C(  368.31)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -579.79), SIMDE_FLOAT64_C( -736.86)),
      simde_mm_set_epi64x(INT64_C( 0), INT64_C(-1)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  408.86), SIMDE_FLOAT64_C(   63.85)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  408.86), SIMDE_FLOAT64_C(  878.02)),
      simde_mm_set_epi64x(INT64_C( 0), INT64_C( 0)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_castpd_si128(simde_mm_cmpnle_pd(test_vec[i].a, test_vec[i].b));
    simde_assert_m128i_i64(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_cmpnle_sd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128d a;
    simde__m128d b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  -50.93), SIMDE_FLOAT64_C( -877.25)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -50.93), SIMDE_FLOAT64_C(   61.42)),
      simde_x_mm_set_epu64x(UINT64_C(0), UINT64_C(0)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  567.19), SIMDE_FLOAT64_C(  768.82)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -689.51), SIMDE_FLOAT64_C(  768.82)),
      simde_x_mm_set_epu64x(UINT64_C(0), UINT64_C(0)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  625.00), SIMDE_FLOAT64_C(  979.36)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   59.83), SIMDE_FLOAT64_C(  979.36)),
      simde_x_mm_set_epu64x(UINT64_C(0), UINT64_C(0)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -994.58), SIMDE_FLOAT64_C(  130.45)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -720.49), SIMDE_FLOAT64_C(  130.45)),
      simde_x_mm_set_epu64x(UINT64_C(0), UINT64_C(0)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  889.79), SIMDE_FLOAT64_C( -677.25)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  889.79), SIMDE_FLOAT64_C( -677.25)),
      simde_x_mm_set_epu64x(UINT64_C(0), UINT64_C(0)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  802.11), SIMDE_FLOAT64_C( -926.46)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -136.48), SIMDE_FLOAT64_C( -926.46)),
      simde_x_mm_set_epu64x(UINT64_C(0), UINT64_C(0)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -579.79), SIMDE_FLOAT64_C(  368.31)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -579.79), SIMDE_FLOAT64_C( -736.86)),
      simde_x_mm_set_epu64x(UINT64_C(0), ~UINT64_C(0)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  408.86), SIMDE_FLOAT64_C(   63.85)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  408.86), SIMDE_FLOAT64_C(  878.02)),
      simde_x_mm_set_epu64x(UINT64_C(0), UINT64_C(0)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_cmpnle_sd(test_vec[i].a, test_vec[i].b);
    munit_assert_uint64(r.u64[0], ==, test_vec[i].r.u64[0]);
    munit_assert_double(r.f64[1], ==, test_vec[i].a.f64[1]);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_cmpgt_epi8(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi8(INT8_C(  13), INT8_C( -99), INT8_C(-128), INT8_C(  91), INT8_C( -96), INT8_C( 103), INT8_C(-104), INT8_C(-110),
                        INT8_C( -46), INT8_C(  -5), INT8_C(  62), INT8_C(-125), INT8_C( -51), INT8_C( -65), INT8_C(-102), INT8_C( -14)),
      simde_mm_set_epi8(INT8_C(  10), INT8_C( -84), INT8_C(  90), INT8_C(-110), INT8_C( 113), INT8_C( -34), INT8_C( -75), INT8_C(-110),
                        INT8_C( -79), INT8_C(-114), INT8_C(  26), INT8_C(-127), INT8_C(  -5), INT8_C(  -9), INT8_C(-102), INT8_C( -38)),
      simde_mm_set_epi8(INT8_C(  -1), INT8_C(   0), INT8_C(   0), INT8_C(  -1), INT8_C(   0), INT8_C(  -1), INT8_C(   0), INT8_C(   0),
                        INT8_C(  -1), INT8_C(  -1), INT8_C(  -1), INT8_C(  -1), INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(  -1)) },
    { simde_mm_set_epi8(INT8_C(-110), INT8_C( -93), INT8_C( 106), INT8_C( -55), INT8_C(  91), INT8_C( -78), INT8_C(  69), INT8_C(  62),
                        INT8_C(  38), INT8_C(-101), INT8_C(  86), INT8_C(-107), INT8_C( 114), INT8_C( 120), INT8_C(-118), INT8_C( 101)),
      simde_mm_set_epi8(INT8_C(  58), INT8_C( -88), INT8_C(  75), INT8_C( -55), INT8_C(  92), INT8_C(  51), INT8_C(-109), INT8_C(  62),
                        INT8_C( 123), INT8_C( -42), INT8_C(   0), INT8_C(  40), INT8_C( 114), INT8_C(-115), INT8_C(  34), INT8_C( 101)),
      simde_mm_set_epi8(INT8_C(   0), INT8_C(   0), INT8_C(  -1), INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(  -1), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(  -1), INT8_C(   0), INT8_C(   0), INT8_C(  -1), INT8_C(   0), INT8_C(   0)) },
    { simde_mm_set_epi8(INT8_C(  79), INT8_C(  -2), INT8_C(-126), INT8_C(-121), INT8_C(  71), INT8_C( -59), INT8_C(  95), INT8_C(  38),
                        INT8_C( -95), INT8_C( 103), INT8_C( -55), INT8_C( -42), INT8_C(-124), INT8_C( -82), INT8_C( 102), INT8_C(  97)),
      simde_mm_set_epi8(INT8_C( -39), INT8_C( -59), INT8_C(-126), INT8_C(-107), INT8_C(-111), INT8_C( 122), INT8_C( -55), INT8_C(  87),
                        INT8_C( -95), INT8_C( -99), INT8_C(  56), INT8_C( 120), INT8_C( 107), INT8_C( -79), INT8_C(  -9), INT8_C( -36)),
      simde_mm_set_epi8(INT8_C(  -1), INT8_C(  -1), INT8_C(   0), INT8_C(   0), INT8_C(  -1), INT8_C(   0), INT8_C(  -1), INT8_C(   0),
                        INT8_C(   0), INT8_C(  -1), INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(  -1), INT8_C(  -1)) },
    { simde_mm_set_epi8(INT8_C( -68), INT8_C(   7), INT8_C( -32), INT8_C( 120), INT8_C(-106), INT8_C(-127), INT8_C(  37), INT8_C(  95),
                        INT8_C( -77), INT8_C(-126), INT8_C(-111), INT8_C( -96), INT8_C(  67), INT8_C(  43), INT8_C(-123), INT8_C(  21)),
      simde_mm_set_epi8(INT8_C(  72), INT8_C(  68), INT8_C(  76), INT8_C( -22), INT8_C( -11), INT8_C(  34), INT8_C( 112), INT8_C(  95),
                        INT8_C( -77), INT8_C(  36), INT8_C( 119), INT8_C( -59), INT8_C( -49), INT8_C( -22), INT8_C(-125), INT8_C(  21)),
      simde_mm_set_epi8(INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(  -1), INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(  -1), INT8_C(  -1), INT8_C(  -1), INT8_C(   0)) },
    { simde_mm_set_epi8(INT8_C( -18), INT8_C(  13), INT8_C(  66), INT8_C( -52), INT8_C( -92), INT8_C(  28), INT8_C(-122), INT8_C( -12),
                        INT8_C( -60), INT8_C( 125), INT8_C(-104), INT8_C(-118), INT8_C( -76), INT8_C(  42), INT8_C( -48), INT8_C(-120)),
      simde_mm_set_epi8(INT8_C( -17), INT8_C(  13), INT8_C(  66), INT8_C( -64), INT8_C( -92), INT8_C( 114), INT8_C(-119), INT8_C(-106),
                        INT8_C(  78), INT8_C(-125), INT8_C(  88), INT8_C( -88), INT8_C( 101), INT8_C(  42), INT8_C( -58), INT8_C(  -8)),
      simde_mm_set_epi8(INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(  -1), INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(  -1),
                        INT8_C(   0), INT8_C(  -1), INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(  -1), INT8_C(   0)) },
    { simde_mm_set_epi8(INT8_C(-112), INT8_C( -16), INT8_C(  96), INT8_C( -64), INT8_C(  75), INT8_C(  56), INT8_C( -96), INT8_C(  96),
                        INT8_C(  -8), INT8_C(  16), INT8_C(  95), INT8_C(  41), INT8_C(  62), INT8_C(  -2), INT8_C(-105), INT8_C(-101)),
      simde_mm_set_epi8(INT8_C(  42), INT8_C(   7), INT8_C(  90), INT8_C( -93), INT8_C(  75), INT8_C(  14), INT8_C(  -5), INT8_C(  61),
                        INT8_C(  -8), INT8_C( -49), INT8_C(  95), INT8_C(  82), INT8_C( -93), INT8_C( -80), INT8_C(   6), INT8_C( -48)),
      simde_mm_set_epi8(INT8_C(   0), INT8_C(   0), INT8_C(  -1), INT8_C(  -1), INT8_C(   0), INT8_C(  -1), INT8_C(   0), INT8_C(  -1),
                        INT8_C(   0), INT8_C(  -1), INT8_C(   0), INT8_C(   0), INT8_C(  -1), INT8_C(  -1), INT8_C(   0), INT8_C(   0)) },
    { simde_mm_set_epi8(INT8_C( -56), INT8_C( -85), INT8_C(   9), INT8_C(   3), INT8_C(  32), INT8_C(-105), INT8_C(  93), INT8_C( -78),
                        INT8_C(-113), INT8_C(  96), INT8_C(  61), INT8_C(  14), INT8_C( -92), INT8_C(  53), INT8_C(  51), INT8_C(  -7)),
      simde_mm_set_epi8(INT8_C(  15), INT8_C( 100), INT8_C(   9), INT8_C(  70), INT8_C(-115), INT8_C(-105), INT8_C(  14), INT8_C( -41),
                        INT8_C(-113), INT8_C( -54), INT8_C( -38), INT8_C(  14), INT8_C( -53), INT8_C(   5), INT8_C(-127), INT8_C(  -7)),
      simde_mm_set_epi8(INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(  -1), INT8_C(   0), INT8_C(  -1), INT8_C(   0),
                        INT8_C(   0), INT8_C(  -1), INT8_C(  -1), INT8_C(   0), INT8_C(   0), INT8_C(  -1), INT8_C(  -1), INT8_C(   0)) },
    { simde_mm_set_epi8(INT8_C( 120), INT8_C(  38), INT8_C(  44), INT8_C( 103), INT8_C(  33), INT8_C( -93), INT8_C(-102), INT8_C( -46),
                        INT8_C(  47), INT8_C(   7), INT8_C( 120), INT8_C( 102), INT8_C( -87), INT8_C( -84), INT8_C(  92), INT8_C(  87)),
      simde_mm_set_epi8(INT8_C( -11), INT8_C(  89), INT8_C(  26), INT8_C(  69), INT8_C( 108), INT8_C( 127), INT8_C(-102), INT8_C(  49),
                        INT8_C(  53), INT8_C(  57), INT8_C( 120), INT8_C( -23), INT8_C( -87), INT8_C( -84), INT8_C( 113), INT8_C( -36)),
      simde_mm_set_epi8(INT8_C(  -1), INT8_C(   0), INT8_C(  -1), INT8_C(  -1), INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                        INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(  -1), INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(  -1)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i r = simde_mm_cmpgt_epi8(test_vec[i].a, test_vec[i].b);
    simde_assert_m128i_i8(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_cmpgt_epi16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi16( 11481, -31028, -28938,   3434,   2523, -16298, -20752,  -3418),
      simde_mm_set_epi16( 11481, -30562,   4762,  -6519,   2523,   9845,    -18,  -5787),
      simde_mm_set_epi16(     0,      0,      0,     -1,      0,      0,      0,     -1) },
    { simde_mm_set_epi16( -3487,  -2281,   2722, -23699,  -5087,  24907,  26126,  26357),
      simde_mm_set_epi16( 32178, -24562,  -3261, -23699,   2431, -16600,  -5679, -12625),
      simde_mm_set_epi16(     0,     -1,     -1,      0,      0,     -1,     -1,     -1) },
    { simde_mm_set_epi16( 28908,  -8639, -27999, -19726,  28446,   -947,  -9756, -32088),
      simde_mm_set_epi16(-24056, -13026, -27999,  27584, -22292,  18403, -15329,  30515),
      simde_mm_set_epi16(    -1,     -1,      0,      0,     -1,      0,     -1,      0) },
    { simde_mm_set_epi16( 32500,  28770, -12789,    764, -17186,   5823,   5923, -14898),
      simde_mm_set_epi16(  5264, -27897, -22472, -17764,  20191,  20077, -20539,  -7345),
      simde_mm_set_epi16(    -1,     -1,     -1,     -1,      0,      0,     -1,      0) },
    { simde_mm_set_epi16(-32420, -10018,  10034,  21195,  23576,  23578,  27261,  22728),
      simde_mm_set_epi16(-22785,   9581,  -7653, -22519,   2089,  10927,  31136,  28081),
      simde_mm_set_epi16(     0,      0,     -1,     -1,     -1,     -1,      0,      0) },
    { simde_mm_set_epi16( -8613,  14814,  25977, -32026, -14164,  15788,  26276, -23351),
      simde_mm_set_epi16( 18907,  31050,  25483,  -1544, -22377, -30002,  26276, -21368),
      simde_mm_set_epi16(     0,      0,     -1,      0,     -1,     -1,      0,      0) },
    { simde_mm_set_epi16( -8616,  18300, -13448, -25384, -20778,   9404,  18457, -13013),
      simde_mm_set_epi16( 28965, -22807,  20081, -25384,  21664, -19420, -10494,   8092),
      simde_mm_set_epi16(     0,     -1,      0,      0,      0,     -1,     -1,      0) },
    { simde_mm_set_epi16(-19643,  19578, -31344, -10120,  -1042,  26214,   7476,  19171),
      simde_mm_set_epi16(  3338, -31811,  23264,  16135,  10963,  28585,  10267,  15982),
      simde_mm_set_epi16(     0,     -1,      0,      0,      0,      0,      0,     -1) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_cmpgt_epi16(test_vec[i].a, test_vec[i].b);
    simde_assert_m128i_i16(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_cmpgt_epi32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi32(  752453324, -1896477334,   165396566, -1359940954),
      simde_mm_set_epi32(  752453324,   312141449, -1431099787,    -1119899),
      simde_mm_set_epi32(          0,           0,          -1,           0) },
    { simde_mm_set_epi32(  107153560,  1681238316, -2021152487, -1327623679),
      simde_mm_set_epi32( -228460777,   178430829,  -333356725,  1712219893),
      simde_mm_set_epi32(         -1,          -1,           0,           0) },
    { simde_mm_set_epi32( -899341348, -1183976764,    50756911,  -774436817),
      simde_mm_set_epi32( -899341348, -1675909702,    50756911,   393145285),
      simde_mm_set_epi32(          0,          -1,           0,           0) },
    { simde_mm_set_epi32(-1576481506,   693332928, -1460910109, -1004570829),
      simde_mm_set_epi32(-1038801032, -1159952439, -1460910109,   -43665635),
      simde_mm_set_epi32(          0,          -1,           0,           0) },
    { simde_mm_set_epi32( 2129948770,  -838139140, -1126295873,   388220366),
      simde_mm_set_epi32(  345019143, -1472677220,  1323257453, -1345985713),
      simde_mm_set_epi32(         -1,          -1,           0,          -1) },
    { simde_mm_set_epi32(  324758156,  1228690576, -1773311089,   254589418),
      simde_mm_set_epi32(-2124621602,  1228690576,  1545100314,  1786599624),
      simde_mm_set_epi32(         -1,           0,           0,           0) },
    { simde_mm_set_epi32(-1939857174,   351576089,    62939556, -1061610170),
      simde_mm_set_epi32(-1899113305,  1851167226,    62939556, -2109881445),
      simde_mm_set_epi32(          0,           0,           0,          -1) },
    { simde_mm_set_epi32( 1239120202,  1670117880, -1466463538,  1932307592),
      simde_mm_set_epi32( 1694384857,    79202881,  -114087446,  -617386644),
      simde_mm_set_epi32(          0,          -1,           0,          -1) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_cmpgt_epi32(test_vec[i].a, test_vec[i].b);
    simde_assert_m128i_i32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_cmpgt_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128d a;
    simde__m128d b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -649.61), SIMDE_FLOAT64_C(  366.73)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  333.59), SIMDE_FLOAT64_C(  116.88)),
      simde_mm_set_epi64x(INT64_C( 0), INT64_C(-1)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -619.22), SIMDE_FLOAT64_C( -854.65)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -854.79), SIMDE_FLOAT64_C(  863.33)),
      simde_mm_set_epi64x(INT64_C(-1), INT64_C( 0)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -950.10), SIMDE_FLOAT64_C(  381.78)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  844.77), SIMDE_FLOAT64_C( -217.11)),
      simde_mm_set_epi64x(INT64_C( 0), INT64_C(-1)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -925.79), SIMDE_FLOAT64_C( -916.91)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -17.99), SIMDE_FLOAT64_C(  826.72)),
      simde_mm_set_epi64x(INT64_C( 0), INT64_C( 0)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  581.21), SIMDE_FLOAT64_C(  639.37)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  581.21), SIMDE_FLOAT64_C(  448.67)),
      simde_mm_set_epi64x(INT64_C( 0), INT64_C(-1)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  702.29), SIMDE_FLOAT64_C( -582.84)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  702.29), SIMDE_FLOAT64_C(  186.24)),
      simde_mm_set_epi64x(INT64_C( 0), INT64_C( 0)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  532.21), SIMDE_FLOAT64_C(  145.56)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -677.14), SIMDE_FLOAT64_C(  145.56)),
      simde_mm_set_epi64x(INT64_C(-1), INT64_C( 0)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  459.86), SIMDE_FLOAT64_C(  265.89)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -130.43), SIMDE_FLOAT64_C(  334.48)),
      simde_mm_set_epi64x(INT64_C(-1), INT64_C( 0)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_castpd_si128(simde_mm_cmpgt_pd(test_vec[i].a, test_vec[i].b));
    simde_assert_m128i_i64(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_cmpgt_sd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128d a;
    simde__m128d b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -649.61), SIMDE_FLOAT64_C(  366.73)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  333.59), SIMDE_FLOAT64_C(  116.88)),
      simde_x_mm_set_epu64x(UINT64_C(0), ~UINT64_C(0)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -619.22), SIMDE_FLOAT64_C( -854.65)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -854.79), SIMDE_FLOAT64_C(  863.33)),
      simde_x_mm_set_epu64x(UINT64_C(0), UINT64_C(0)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -950.10), SIMDE_FLOAT64_C(  381.78)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  844.77), SIMDE_FLOAT64_C( -217.11)),
      simde_x_mm_set_epu64x(UINT64_C(0), ~UINT64_C(0)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -925.79), SIMDE_FLOAT64_C( -916.91)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -17.99), SIMDE_FLOAT64_C(  826.72)),
      simde_x_mm_set_epu64x(UINT64_C(0), UINT64_C(0)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  581.21), SIMDE_FLOAT64_C(  639.37)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  581.21), SIMDE_FLOAT64_C(  448.67)),
      simde_x_mm_set_epu64x(UINT64_C(0), ~UINT64_C(0)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  702.29), SIMDE_FLOAT64_C( -582.84)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  702.29), SIMDE_FLOAT64_C(  186.24)),
      simde_x_mm_set_epu64x(UINT64_C(0), UINT64_C(0)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  532.21), SIMDE_FLOAT64_C(  145.56)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -677.14), SIMDE_FLOAT64_C(  145.56)),
      simde_x_mm_set_epu64x(UINT64_C(0), UINT64_C(0)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  459.86), SIMDE_FLOAT64_C(  265.89)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -130.43), SIMDE_FLOAT64_C(  334.48)),
      simde_x_mm_set_epu64x(UINT64_C(0), UINT64_C(0)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_cmpgt_sd(test_vec[i].a, test_vec[i].b);
    munit_assert_uint64(r.u64[0], ==, test_vec[i].r.u64[0]);
    munit_assert_double(r.f64[1], ==, test_vec[i].a.f64[1]);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_cmpge_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128d a;
    simde__m128d b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -649.61), SIMDE_FLOAT64_C(  366.73)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  333.59), SIMDE_FLOAT64_C(  116.88)),
      simde_mm_set_epi64x(INT64_C( 0), INT64_C(-1)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -619.22), SIMDE_FLOAT64_C( -854.65)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -854.79), SIMDE_FLOAT64_C(  863.33)),
      simde_mm_set_epi64x(INT64_C(-1), INT64_C( 0)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -950.10), SIMDE_FLOAT64_C(  381.78)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  844.77), SIMDE_FLOAT64_C( -217.11)),
      simde_mm_set_epi64x(INT64_C( 0), INT64_C(-1)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -925.79), SIMDE_FLOAT64_C( -916.91)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -17.99), SIMDE_FLOAT64_C(  826.72)),
      simde_mm_set_epi64x(INT64_C( 0), INT64_C( 0)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  581.21), SIMDE_FLOAT64_C(  639.37)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  581.21), SIMDE_FLOAT64_C(  448.67)),
      simde_mm_set_epi64x(INT64_C(-1), INT64_C(-1)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  702.29), SIMDE_FLOAT64_C( -582.84)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  702.29), SIMDE_FLOAT64_C(  186.24)),
      simde_mm_set_epi64x(INT64_C(-1), INT64_C( 0)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  532.21), SIMDE_FLOAT64_C(  145.56)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -677.14), SIMDE_FLOAT64_C(  145.56)),
      simde_mm_set_epi64x(INT64_C(-1), INT64_C(-1)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  459.86), SIMDE_FLOAT64_C(  265.89)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -130.43), SIMDE_FLOAT64_C(  334.48)),
      simde_mm_set_epi64x(INT64_C(-1), INT64_C( 0)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_castpd_si128(simde_mm_cmpge_pd(test_vec[i].a, test_vec[i].b));
    simde_assert_m128i_i64(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_cmpge_sd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128d a;
    simde__m128d b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -649.61), SIMDE_FLOAT64_C(  366.73)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  333.59), SIMDE_FLOAT64_C(  116.88)),
      simde_x_mm_set_epu64x(UINT64_C(0), ~UINT64_C(0)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -619.22), SIMDE_FLOAT64_C( -854.65)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -854.79), SIMDE_FLOAT64_C(  863.33)),
      simde_x_mm_set_epu64x(UINT64_C(0), UINT64_C(0)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -950.10), SIMDE_FLOAT64_C(  381.78)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  844.77), SIMDE_FLOAT64_C( -217.11)),
      simde_x_mm_set_epu64x(UINT64_C(0), ~UINT64_C(0)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -925.79), SIMDE_FLOAT64_C( -916.91)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -17.99), SIMDE_FLOAT64_C(  826.72)),
      simde_x_mm_set_epu64x(UINT64_C(0), UINT64_C(0)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  581.21), SIMDE_FLOAT64_C(  639.37)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  581.21), SIMDE_FLOAT64_C(  448.67)),
      simde_x_mm_set_epu64x(UINT64_C(0), ~UINT64_C(0)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  702.29), SIMDE_FLOAT64_C( -582.84)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  702.29), SIMDE_FLOAT64_C(  186.24)),
      simde_x_mm_set_epu64x(UINT64_C(0), UINT64_C(0)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  532.21), SIMDE_FLOAT64_C(  145.56)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -677.14), SIMDE_FLOAT64_C(  145.56)),
      simde_x_mm_set_epu64x(UINT64_C(0), ~UINT64_C(0)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  459.86), SIMDE_FLOAT64_C(  265.89)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -130.43), SIMDE_FLOAT64_C(  334.48)),
      simde_x_mm_set_epu64x(UINT64_C(0), UINT64_C(0)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_cmpge_sd(test_vec[i].a, test_vec[i].b);
    munit_assert_uint64(r.u64[0], ==, test_vec[i].r.u64[0]);
    munit_assert_double(r.f64[1], ==, test_vec[i].a.f64[1]);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_cmpnge_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128d a;
    simde__m128d b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C(   65.48), SIMDE_FLOAT64_C( -195.60)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   65.48), SIMDE_FLOAT64_C(   18.27)),
      simde_mm_set_epi64x(INT64_C( 0), INT64_C(-1)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -563.65), SIMDE_FLOAT64_C(  884.03)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  467.71), SIMDE_FLOAT64_C( -906.63)),
      simde_mm_set_epi64x(INT64_C(-1), INT64_C( 0)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -553.85), SIMDE_FLOAT64_C(   49.09)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  731.88), SIMDE_FLOAT64_C(  974.91)),
      simde_mm_set_epi64x(INT64_C(-1), INT64_C(-1)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  492.98), SIMDE_FLOAT64_C(   64.21)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -392.36), SIMDE_FLOAT64_C( -188.43)),
      simde_mm_set_epi64x(INT64_C( 0), INT64_C( 0)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -248.75), SIMDE_FLOAT64_C( -404.39)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -495.92), SIMDE_FLOAT64_C( -819.81)),
      simde_mm_set_epi64x(INT64_C( 0), INT64_C( 0)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -932.57), SIMDE_FLOAT64_C(  741.27)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -307.42), SIMDE_FLOAT64_C(  170.69)),
      simde_mm_set_epi64x(INT64_C(-1), INT64_C( 0)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -939.12), SIMDE_FLOAT64_C( -161.45)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -939.12), SIMDE_FLOAT64_C( -161.45)),
      simde_mm_set_epi64x(INT64_C( 0), INT64_C( 0)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -900.20), SIMDE_FLOAT64_C( -314.63)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  138.12), SIMDE_FLOAT64_C(  517.19)),
      simde_mm_set_epi64x(INT64_C(-1), INT64_C(-1)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_castpd_si128(simde_mm_cmpnge_pd(test_vec[i].a, test_vec[i].b));
    simde_assert_m128i_i64(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_cmpnge_sd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128d a;
    simde__m128d b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C(   65.48), SIMDE_FLOAT64_C( -195.60)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   65.48), SIMDE_FLOAT64_C(   18.27)),
      simde_x_mm_set_epu64x(UINT64_C(0), ~UINT64_C(0)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -563.65), SIMDE_FLOAT64_C(  884.03)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  467.71), SIMDE_FLOAT64_C( -906.63)),
      simde_x_mm_set_epu64x(UINT64_C(0), UINT64_C(0)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -553.85), SIMDE_FLOAT64_C(   49.09)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  731.88), SIMDE_FLOAT64_C(  974.91)),
      simde_x_mm_set_epu64x(UINT64_C(0), ~UINT64_C(0)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  492.98), SIMDE_FLOAT64_C(   64.21)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -392.36), SIMDE_FLOAT64_C( -188.43)),
      simde_x_mm_set_epu64x(UINT64_C(0), UINT64_C(0)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -248.75), SIMDE_FLOAT64_C( -404.39)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -495.92), SIMDE_FLOAT64_C( -819.81)),
      simde_x_mm_set_epu64x(UINT64_C(0), UINT64_C(0)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -932.57), SIMDE_FLOAT64_C(  741.27)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -307.42), SIMDE_FLOAT64_C(  170.69)),
      simde_x_mm_set_epu64x(UINT64_C(0), UINT64_C(0)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -939.12), SIMDE_FLOAT64_C( -161.45)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -939.12), SIMDE_FLOAT64_C( -161.45)),
      simde_x_mm_set_epu64x(UINT64_C(0), UINT64_C(0)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -900.20), SIMDE_FLOAT64_C( -314.63)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  138.12), SIMDE_FLOAT64_C(  517.19)),
      simde_x_mm_set_epu64x(UINT64_C(0), ~UINT64_C(0)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_cmpnge_sd(test_vec[i].a, test_vec[i].b);
    munit_assert_uint64(r.u64[0], ==, test_vec[i].r.u64[0]);
    munit_assert_double(r.f64[1], ==, test_vec[i].a.f64[1]);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_cmpord_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128d a;
    simde__m128d b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  107.72), SIMDE_FLOAT64_C( -915.48)),
      simde_mm_set_pd( nan(""), SIMDE_FLOAT64_C( -303.84)),
      simde_mm_set_epi64x(INT64_C(0), INT64_C(-1)) },
    { simde_mm_set_pd( nan(""), SIMDE_FLOAT64_C(  173.20)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -817.33), SIMDE_FLOAT64_C(  659.40)),
      simde_mm_set_epi64x(INT64_C(0), INT64_C(-1)) },
    { simde_mm_set_pd( nan(""),  nan("")),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -425.32), SIMDE_FLOAT64_C(  993.95)),
      simde_mm_set_epi64x(INT64_C(0), INT64_C(0)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -650.75),  nan("")),
      simde_mm_set_pd( nan(""), SIMDE_FLOAT64_C( -971.81)),
      simde_mm_set_epi64x(INT64_C(0), INT64_C(0)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -761.29), SIMDE_FLOAT64_C( -694.76)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -709.09), SIMDE_FLOAT64_C(  614.12)),
      simde_mm_set_epi64x(INT64_C(-1), INT64_C(-1)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  498.19), SIMDE_FLOAT64_C( -379.74)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -247.48), SIMDE_FLOAT64_C( -578.21)),
      simde_mm_set_epi64x(INT64_C(-1), INT64_C(-1)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  101.51), SIMDE_FLOAT64_C(  387.46)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  215.97), SIMDE_FLOAT64_C(  173.76)),
      simde_mm_set_epi64x(INT64_C(-1), INT64_C(-1)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  729.13), SIMDE_FLOAT64_C(  771.13)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  902.43), SIMDE_FLOAT64_C( -416.43)),
      simde_mm_set_epi64x(INT64_C(-1), INT64_C(-1)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_castpd_si128(simde_mm_cmpord_pd(test_vec[i].a, test_vec[i].b));
    simde_assert_m128i_i64(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_cmpord_sd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128d a;
    simde__m128d b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  243.61), SIMDE_FLOAT64_C(  376.31)),
      simde_mm_set_pd( nan(""),  nan("")),
      simde_x_mm_set_epu64x(UINT64_C(0x406e73851eb851ec), UINT64_C(0)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -269.92), SIMDE_FLOAT64_C(  109.63)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -480.22), SIMDE_FLOAT64_C(  930.22)),
      simde_x_mm_set_epu64x(UINT64_C(0xc070deb851eb851f), ~UINT64_C(0)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -954.22), SIMDE_FLOAT64_C( -637.73)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -866.80), SIMDE_FLOAT64_C(  770.28)),
      simde_x_mm_set_epu64x(UINT64_C(0xc08dd1c28f5c28f6), ~UINT64_C(0)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -499.36), SIMDE_FLOAT64_C( -515.42)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  198.37), SIMDE_FLOAT64_C(  980.21)),
      simde_x_mm_set_epu64x(UINT64_C(0xc07f35c28f5c28f6), ~UINT64_C(0)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  661.89), SIMDE_FLOAT64_C( -778.93)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  182.64), SIMDE_FLOAT64_C( -310.55)),
      simde_x_mm_set_epu64x(UINT64_C(0x4084af1eb851eb85), ~UINT64_C(0)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  555.69), SIMDE_FLOAT64_C( -313.06)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -374.85), SIMDE_FLOAT64_C(  627.14)),
      simde_x_mm_set_epu64x(UINT64_C(0x40815d851eb851ec), ~UINT64_C(0)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -502.78), SIMDE_FLOAT64_C(  974.01)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  676.46), SIMDE_FLOAT64_C(  514.23)),
      simde_x_mm_set_epu64x(UINT64_C(0xc07f6c7ae147ae14), ~UINT64_C(0)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  108.28), SIMDE_FLOAT64_C(  -38.67)),
      simde_mm_set_pd( nan(""),  nan("")),
      simde_x_mm_set_epu64x(UINT64_C(0x405b11eb851eb852), UINT64_C(0)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_cmpord_sd(test_vec[i].a, test_vec[i].b);
    munit_assert_uint64(r.u64[0], ==, test_vec[i].r.u64[0]);
    munit_assert_double(r.f64[1], ==, test_vec[i].a.f64[1]);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_cmpunord_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128d a;
    simde__m128d b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_pd( nan(""), SIMDE_FLOAT64_C(  670.49)),
      simde_mm_set_pd( nan(""), SIMDE_FLOAT64_C(  826.75)),
      simde_mm_set_epi64x(INT64_C(-1), INT64_C(0)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -774.95),  nan("")),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  247.71),  nan("")),
      simde_mm_set_epi64x(INT64_C(0), INT64_C(-1)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  -88.77), SIMDE_FLOAT64_C(  116.09)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -32.79), SIMDE_FLOAT64_C( -442.07)),
      simde_mm_set_epi64x(INT64_C(0), INT64_C(0)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(   71.71), SIMDE_FLOAT64_C(  549.42)),
      simde_mm_set_pd( nan(""), SIMDE_FLOAT64_C( -288.27)),
      simde_mm_set_epi64x(INT64_C(-1), INT64_C(0)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -266.24), SIMDE_FLOAT64_C( -147.24)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  900.46), SIMDE_FLOAT64_C( -288.71)),
      simde_mm_set_epi64x(INT64_C(0), INT64_C(0)) },
    { simde_mm_set_pd( nan(""),  nan("")),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  196.30),  nan("")),
      simde_mm_set_epi64x(INT64_C(-1), INT64_C(-1)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -447.36), SIMDE_FLOAT64_C(  236.69)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -774.85), SIMDE_FLOAT64_C( -611.68)),
      simde_mm_set_epi64x(INT64_C(0), INT64_C(0)) },
    { simde_mm_set_pd( nan(""),  nan("")),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  711.66), SIMDE_FLOAT64_C( -751.40)),
      simde_mm_set_epi64x(INT64_C(-1), INT64_C(-1)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_castpd_si128(simde_mm_cmpunord_pd(test_vec[i].a, test_vec[i].b));
    simde_assert_m128i_i64(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_cmpunord_sd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128d a;
    simde__m128d b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -900.44), SIMDE_FLOAT64_C(  555.35)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -768.21),  nan("")),
      simde_x_mm_set_epu64x(UINT64_C(0xc08c23851eb851ec), ~UINT64_C(0)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -356.71), SIMDE_FLOAT64_C(  937.54)),
      simde_mm_set_pd( nan(""), SIMDE_FLOAT64_C(  223.12)),
      simde_x_mm_set_epu64x(UINT64_C(0xc0764b5c28f5c28f), UINT64_C(0)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  227.98), SIMDE_FLOAT64_C(  -74.57)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -452.57),  nan("")),
      simde_x_mm_set_epu64x(UINT64_C(0x406c7f5c28f5c28f), ~UINT64_C(0)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  297.17), SIMDE_FLOAT64_C(  401.91)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  857.32), SIMDE_FLOAT64_C(  626.54)),
      simde_x_mm_set_epu64x(UINT64_C(0x407292b851eb851f), UINT64_C(0)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  739.06), SIMDE_FLOAT64_C( -952.53)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  352.92), SIMDE_FLOAT64_C( -550.85)),
      simde_x_mm_set_epu64x(UINT64_C(0x4087187ae147ae14), UINT64_C(0)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  215.28), SIMDE_FLOAT64_C(  461.45)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   12.14),  nan("")),
      simde_x_mm_set_epu64x(UINT64_C(0x406ae8f5c28f5c29), ~UINT64_C(0)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  735.02), SIMDE_FLOAT64_C(  398.76)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  640.06),  nan("")),
      simde_x_mm_set_epu64x(UINT64_C(0x4086f828f5c28f5c), ~UINT64_C(0)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  358.88), SIMDE_FLOAT64_C( -165.28)),
      simde_mm_set_pd( nan(""), SIMDE_FLOAT64_C(  339.89)),
      simde_x_mm_set_epu64x(UINT64_C(0x40766e147ae147ae), UINT64_C(0)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_cmpunord_sd(test_vec[i].a, test_vec[i].b);
    munit_assert_uint64(r.u64[0], ==, test_vec[i].r.u64[0]);
    munit_assert_double(r.f64[1], ==, test_vec[i].a.f64[1]);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_comieq_sd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128d a;
    simde__m128d b;
    int r;
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -969.61), SIMDE_FLOAT64_C(  839.23)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -969.61), SIMDE_FLOAT64_C( -432.69)),
      0 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  281.50), SIMDE_FLOAT64_C( -752.55)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  281.50), SIMDE_FLOAT64_C( -752.55)),
      1 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  590.09), SIMDE_FLOAT64_C(  270.42)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -206.33), SIMDE_FLOAT64_C(  270.42)),
      1 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  412.70), SIMDE_FLOAT64_C( -500.58)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  145.06), SIMDE_FLOAT64_C(  763.45)),
      0 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -374.23), SIMDE_FLOAT64_C(  380.82)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -374.23), SIMDE_FLOAT64_C(  380.82)),
      1 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -875.64), SIMDE_FLOAT64_C(   30.13)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -823.83), SIMDE_FLOAT64_C(   30.13)),
      1 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  890.78), SIMDE_FLOAT64_C( -652.66)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  719.69), SIMDE_FLOAT64_C( -685.53)),
      0 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  740.88), SIMDE_FLOAT64_C(  116.37)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -528.65), SIMDE_FLOAT64_C(  536.46)),
      0 }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    int r = simde_mm_comieq_sd(test_vec[i].a, test_vec[i].b);
    munit_assert_int(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_comige_sd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128d a;
    simde__m128d b;
    int r;
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  105.66), SIMDE_FLOAT64_C(  552.43)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  105.66), SIMDE_FLOAT64_C(  267.88)),
      1 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -590.31), SIMDE_FLOAT64_C( -921.70)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -590.31), SIMDE_FLOAT64_C(  330.81)),
      0 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  865.75), SIMDE_FLOAT64_C( -938.03)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  865.75), SIMDE_FLOAT64_C(  970.01)),
      0 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -158.01), SIMDE_FLOAT64_C(  635.18)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -394.88), SIMDE_FLOAT64_C(  -19.73)),
      1 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  -29.19), SIMDE_FLOAT64_C( -429.43)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -29.19), SIMDE_FLOAT64_C(  -32.37)),
      0 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  507.45), SIMDE_FLOAT64_C( -241.62)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  507.45), SIMDE_FLOAT64_C(  500.55)),
      0 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -667.19), SIMDE_FLOAT64_C(  338.98)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  225.94), SIMDE_FLOAT64_C(  338.98)),
      1 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  890.13), SIMDE_FLOAT64_C( -203.09)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -221.49), SIMDE_FLOAT64_C(  304.99)),
      0 }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    int r = simde_mm_comige_sd(test_vec[i].a, test_vec[i].b);
    munit_assert_int(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_comigt_sd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128d a;
    simde__m128d b;
    int r;
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  105.66), SIMDE_FLOAT64_C(  552.43)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  105.66), SIMDE_FLOAT64_C(  267.88)),
      1 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -590.31), SIMDE_FLOAT64_C( -921.70)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -590.31), SIMDE_FLOAT64_C(  330.81)),
      0 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  865.75), SIMDE_FLOAT64_C( -938.03)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  865.75), SIMDE_FLOAT64_C(  970.01)),
      0 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -158.01), SIMDE_FLOAT64_C(  635.18)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -394.88), SIMDE_FLOAT64_C(  -19.73)),
      1 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  -29.19), SIMDE_FLOAT64_C( -429.43)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -29.19), SIMDE_FLOAT64_C(  -32.37)),
      0 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  507.45), SIMDE_FLOAT64_C( -241.62)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  507.45), SIMDE_FLOAT64_C(  500.55)),
      0 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -667.19), SIMDE_FLOAT64_C(  338.98)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  225.94), SIMDE_FLOAT64_C(  338.98)),
      0 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  890.13), SIMDE_FLOAT64_C( -203.09)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -221.49), SIMDE_FLOAT64_C(  304.99)),
      0 }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    int r = simde_mm_comigt_sd(test_vec[i].a, test_vec[i].b);
    munit_assert_int(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_comile_sd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128d a;
    simde__m128d b;
    int r;
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  105.66), SIMDE_FLOAT64_C(  552.43)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  105.66), SIMDE_FLOAT64_C(  267.88)),
      0 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -590.31), SIMDE_FLOAT64_C( -921.70)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -590.31), SIMDE_FLOAT64_C(  330.81)),
      1 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  865.75), SIMDE_FLOAT64_C( -938.03)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  865.75), SIMDE_FLOAT64_C(  970.01)),
      1 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -158.01), SIMDE_FLOAT64_C(  635.18)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -394.88), SIMDE_FLOAT64_C(  -19.73)),
      0 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  -29.19), SIMDE_FLOAT64_C( -429.43)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -29.19), SIMDE_FLOAT64_C(  -32.37)),
      1 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  507.45), SIMDE_FLOAT64_C( -241.62)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  507.45), SIMDE_FLOAT64_C(  500.55)),
      1 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -667.19), SIMDE_FLOAT64_C(  338.98)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  225.94), SIMDE_FLOAT64_C(  338.98)),
      1 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  890.13), SIMDE_FLOAT64_C( -203.09)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -221.49), SIMDE_FLOAT64_C(  304.99)),
      1 }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    int r = simde_mm_comile_sd(test_vec[i].a, test_vec[i].b);
    munit_assert_int(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_comilt_sd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128d a;
    simde__m128d b;
    int r;
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  766.54), SIMDE_FLOAT64_C(  -69.58)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  185.38), SIMDE_FLOAT64_C(  -69.58)),
      0 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  489.65), SIMDE_FLOAT64_C(  372.98)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  489.65), SIMDE_FLOAT64_C(  372.98)),
      0 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(   79.48), SIMDE_FLOAT64_C( -168.45)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -648.03), SIMDE_FLOAT64_C( -710.04)),
      0 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  907.60), SIMDE_FLOAT64_C(  955.73)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  907.60), SIMDE_FLOAT64_C( -965.39)),
      0 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -237.33), SIMDE_FLOAT64_C(  558.83)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  415.12), SIMDE_FLOAT64_C(  558.83)),
      0 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -796.13), SIMDE_FLOAT64_C(   18.69)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -796.13), SIMDE_FLOAT64_C(   18.69)),
      0 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -380.36), SIMDE_FLOAT64_C( -737.73)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -380.36), SIMDE_FLOAT64_C( -737.73)),
      0 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -975.15), SIMDE_FLOAT64_C( -296.93)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -975.15), SIMDE_FLOAT64_C( -296.93)),
      0 }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    int r = simde_mm_comilt_sd(test_vec[i].a, test_vec[i].b);
    munit_assert_int(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_comineq_sd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128d a;
    simde__m128d b;
    int r;
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  105.66), SIMDE_FLOAT64_C(  552.43)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  105.66), SIMDE_FLOAT64_C(  267.88)),
      1 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -590.31), SIMDE_FLOAT64_C( -921.70)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -590.31), SIMDE_FLOAT64_C(  330.81)),
      1 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  865.75), SIMDE_FLOAT64_C( -938.03)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  865.75), SIMDE_FLOAT64_C(  970.01)),
      1 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -158.01), SIMDE_FLOAT64_C(  635.18)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -394.88), SIMDE_FLOAT64_C(  -19.73)),
      1 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  -29.19), SIMDE_FLOAT64_C( -429.43)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -29.19), SIMDE_FLOAT64_C(  -32.37)),
      1 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  507.45), SIMDE_FLOAT64_C( -241.62)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  507.45), SIMDE_FLOAT64_C(  500.55)),
      1 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -667.19), SIMDE_FLOAT64_C(  338.98)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  225.94), SIMDE_FLOAT64_C(  338.98)),
      0 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  890.13), SIMDE_FLOAT64_C( -203.09)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -221.49), SIMDE_FLOAT64_C(  304.99)),
      1 }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    int r = simde_mm_comineq_sd(test_vec[i].a, test_vec[i].b);
    munit_assert_int(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_cvtepi32_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m128d r;
  } test_vec[8] = {
    { simde_mm_set_epi32( 1668601445,     8850426,  1726684816, -1842005323),
      simde_mm_set_pd(SIMDE_FLOAT64_C(1726684816.00), SIMDE_FLOAT64_C(-1842005323.00)) },
    { simde_mm_set_epi32(-1162443511,  1098837378,  -970075414,  1210551220),
      simde_mm_set_pd(SIMDE_FLOAT64_C(-970075414.00), SIMDE_FLOAT64_C(1210551220.00)) },
    { simde_mm_set_epi32( 1014915875,   235168560,   691866984,  -431325465),
      simde_mm_set_pd(SIMDE_FLOAT64_C(691866984.00), SIMDE_FLOAT64_C(-431325465.00)) },
    { simde_mm_set_epi32( 1621419008,  1286931249, -1424446000,  -169673917),
      simde_mm_set_pd(SIMDE_FLOAT64_C(-1424446000.00), SIMDE_FLOAT64_C(-169673917.00)) },
    { simde_mm_set_epi32(  982570498,    31161721,   410129833,  1249524705),
      simde_mm_set_pd(SIMDE_FLOAT64_C(410129833.00), SIMDE_FLOAT64_C(1249524705.00)) },
    { simde_mm_set_epi32(-1807976526,   584564543,  1386856775,  -792093051),
      simde_mm_set_pd(SIMDE_FLOAT64_C(1386856775.00), SIMDE_FLOAT64_C(-792093051.00)) },
    { simde_mm_set_epi32( 1927957259,   324939853,  1056227907,   960202603),
      simde_mm_set_pd(SIMDE_FLOAT64_C(1056227907.00), SIMDE_FLOAT64_C(960202603.00)) },
    { simde_mm_set_epi32( 2096858414,  2117774841,   250894175,  1268045519),
      simde_mm_set_pd(SIMDE_FLOAT64_C(250894175.00), SIMDE_FLOAT64_C(1268045519.00)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_cvtepi32_pd(test_vec[i].a);
    simde_assert_m128d_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_cvtepi32_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m128 r;
  } test_vec[8] = {
    { simde_mm_set_epi32( 332, -787,  -79, -785),
      simde_mm_set_ps(SIMDE_FLOAT32_C( 332.00), SIMDE_FLOAT32_C(-787.00), SIMDE_FLOAT32_C( -79.00), SIMDE_FLOAT32_C(-785.00)) },
    { simde_mm_set_epi32( 394, -936, -733, -136),
      simde_mm_set_ps(SIMDE_FLOAT32_C( 394.00), SIMDE_FLOAT32_C(-936.00), SIMDE_FLOAT32_C(-733.00), SIMDE_FLOAT32_C(-136.00)) },
    { simde_mm_set_epi32( 618, -416,  310,  183),
      simde_mm_set_ps(SIMDE_FLOAT32_C( 618.00), SIMDE_FLOAT32_C(-416.00), SIMDE_FLOAT32_C( 310.00), SIMDE_FLOAT32_C( 183.00)) },
    { simde_mm_set_epi32(-748,  245,  533, -152),
      simde_mm_set_ps(SIMDE_FLOAT32_C(-748.00), SIMDE_FLOAT32_C( 245.00), SIMDE_FLOAT32_C( 533.00), SIMDE_FLOAT32_C(-152.00)) },
    { simde_mm_set_epi32(  42,  893,  849, -741),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  42.00), SIMDE_FLOAT32_C( 893.00), SIMDE_FLOAT32_C( 849.00), SIMDE_FLOAT32_C(-741.00)) },
    { simde_mm_set_epi32( 657,  222, -709, -177),
      simde_mm_set_ps(SIMDE_FLOAT32_C( 657.00), SIMDE_FLOAT32_C( 222.00), SIMDE_FLOAT32_C(-709.00), SIMDE_FLOAT32_C(-177.00)) },
    { simde_mm_set_epi32( 762, -586,  196,  717),
      simde_mm_set_ps(SIMDE_FLOAT32_C( 762.00), SIMDE_FLOAT32_C(-586.00), SIMDE_FLOAT32_C( 196.00), SIMDE_FLOAT32_C( 717.00)) },
    { simde_mm_set_epi32( 322,  178,  766, -110),
      simde_mm_set_ps(SIMDE_FLOAT32_C( 322.00), SIMDE_FLOAT32_C( 178.00), SIMDE_FLOAT32_C( 766.00), SIMDE_FLOAT32_C(-110.00)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128 r = simde_mm_cvtepi32_ps(test_vec[i].a);
    simde_assert_m128_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_cvtpd_epi32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128d a;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  619.07), SIMDE_FLOAT64_C(  892.74)),
      simde_mm_set_epi32(   0,    0,  619,  893) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  470.31), SIMDE_FLOAT64_C(  660.22)),
      simde_mm_set_epi32(   0,    0,  470,  660) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  -60.85), SIMDE_FLOAT64_C( -627.46)),
      simde_mm_set_epi32(   0,    0,  -61, -627) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  597.08), SIMDE_FLOAT64_C(  713.19)),
      simde_mm_set_epi32(   0,    0,  597,  713) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -711.34), SIMDE_FLOAT64_C(  677.87)),
      simde_mm_set_epi32(   0,    0, -711,  678) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -193.79), SIMDE_FLOAT64_C(  610.22)),
      simde_mm_set_epi32(   0,    0, -194,  610) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -983.22), SIMDE_FLOAT64_C(  418.34)),
      simde_mm_set_epi32(   0,    0, -983,  418) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  586.10), SIMDE_FLOAT64_C( -114.71)),
      simde_mm_set_epi32(   0,    0,  586, -115) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_cvtpd_epi32(test_vec[i].a);
    for (size_t j = 0 ; j < sizeof(test_vec[i].a.f64) / sizeof(test_vec[i].a.f64[0]) ; j++)
      simde_assert_int32_close(r.i32[j], test_vec[i].r.i32[j]);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_cvtpd_pi32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128d a;
    simde__m64 r;
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -666.48), SIMDE_FLOAT64_C( -362.59)),
      simde_mm_set_pi32(-666, -363) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  339.74), SIMDE_FLOAT64_C( -157.66)),
      simde_mm_set_pi32( 340, -158) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -938.51), SIMDE_FLOAT64_C( -421.36)),
      simde_mm_set_pi32(-939, -421) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(   51.73), SIMDE_FLOAT64_C( -650.75)),
      simde_mm_set_pi32(  52, -651) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  657.87), SIMDE_FLOAT64_C( -405.12)),
      simde_mm_set_pi32( 658, -405) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  690.88), SIMDE_FLOAT64_C(  348.18)),
      simde_mm_set_pi32( 691,  348) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  574.12), SIMDE_FLOAT64_C( -708.36)),
      simde_mm_set_pi32( 574, -708) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -392.27), SIMDE_FLOAT64_C( -706.05)),
      simde_mm_set_pi32(-392, -706) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m64 r = simde_mm_cvtpd_pi32(test_vec[i].a);
    for (size_t j = 0 ; j < sizeof(test_vec[i].a.f64) / sizeof(test_vec[i].a.f64[0]) ; j++)
      simde_assert_int32_close(r.i32[j], test_vec[i].r.i32[j]);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_cvtpd_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128d a;
    simde__m128 r;
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  655.71), SIMDE_FLOAT64_C(  689.41)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(  655.71), SIMDE_FLOAT32_C(  689.41)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  -50.10), SIMDE_FLOAT64_C( -149.72)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(  -50.10), SIMDE_FLOAT32_C( -149.72)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  227.42), SIMDE_FLOAT64_C(  655.70)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(  227.42), SIMDE_FLOAT32_C(  655.70)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -635.17), SIMDE_FLOAT64_C(  938.65)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C( -635.17), SIMDE_FLOAT32_C(  938.65)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  548.99), SIMDE_FLOAT64_C(  -18.53)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(  548.99), SIMDE_FLOAT32_C(  -18.53)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -548.71), SIMDE_FLOAT64_C(   31.33)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C( -548.71), SIMDE_FLOAT32_C(   31.33)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -978.36), SIMDE_FLOAT64_C( -341.93)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C( -978.36), SIMDE_FLOAT32_C( -341.93)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  211.73), SIMDE_FLOAT64_C(  471.24)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(  211.73), SIMDE_FLOAT32_C(  471.24)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128 r = simde_mm_cvtpd_ps(test_vec[i].a);
    for (size_t j = 0 ; j < sizeof(test_vec[i].a.f64) / sizeof(test_vec[i].a.f64[0]) ; j++)
      munit_assert_double_equal(r.f32[j], test_vec[i].r.f32[j], 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_cvtpi32_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m64 a;
    simde__m128d r;
  } test_vec[8] = {
    { simde_mm_set_pi32(  -42,  -579),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -42.00), SIMDE_FLOAT64_C(-579.00)) },
    { simde_mm_set_pi32( -633,    29),
      simde_mm_set_pd(SIMDE_FLOAT64_C(-633.00), SIMDE_FLOAT64_C(  29.00)) },
    { simde_mm_set_pi32( -149,   196),
      simde_mm_set_pd(SIMDE_FLOAT64_C(-149.00), SIMDE_FLOAT64_C( 196.00)) },
    { simde_mm_set_pi32(  308,  -433),
      simde_mm_set_pd(SIMDE_FLOAT64_C( 308.00), SIMDE_FLOAT64_C(-433.00)) },
    { simde_mm_set_pi32( -881,   358),
      simde_mm_set_pd(SIMDE_FLOAT64_C(-881.00), SIMDE_FLOAT64_C( 358.00)) },
    { simde_mm_set_pi32(  723,   273),
      simde_mm_set_pd(SIMDE_FLOAT64_C( 723.00), SIMDE_FLOAT64_C( 273.00)) },
    { simde_mm_set_pi32( -182,   457),
      simde_mm_set_pd(SIMDE_FLOAT64_C(-182.00), SIMDE_FLOAT64_C( 457.00)) },
    { simde_mm_set_pi32( -239,  -577),
      simde_mm_set_pd(SIMDE_FLOAT64_C(-239.00), SIMDE_FLOAT64_C(-577.00)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_cvtpi32_pd(test_vec[i].a);
    for (size_t j = 0 ; j < sizeof(r.f64) / sizeof(r.f64[0]) ; j++)
      munit_assert_double_equal(r.f64[j], test_vec[i].r.f64[j], 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_cvtps_epi32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128 a;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_ps(SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(-11516.98), SIMDE_FLOAT32_C( -879.85), SIMDE_FLOAT32_C( -804.87)),
      simde_mm_set_epi32(   0, -11517, -880, -805) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(-11516.98), SIMDE_FLOAT32_C(  -75.52), SIMDE_FLOAT32_C( -969.73)),
      simde_mm_set_epi32(   0, -11517,  -76, -970) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(-11516.98), SIMDE_FLOAT32_C(  469.26), SIMDE_FLOAT32_C(  307.36)),
      simde_mm_set_epi32(   0, -11517,  469,  307) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(-11516.98), SIMDE_FLOAT32_C(  953.93), SIMDE_FLOAT32_C( -612.11)),
      simde_mm_set_epi32(   0, -11517,  954, -612) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(-11516.98), SIMDE_FLOAT32_C( -155.14), SIMDE_FLOAT32_C( -589.40)),
      simde_mm_set_epi32(   0, -11517, -155, -589) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(-11516.98), SIMDE_FLOAT32_C( -256.28), SIMDE_FLOAT32_C( -717.85)),
      simde_mm_set_epi32(   0, -11517, -256, -718) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(-11516.98), SIMDE_FLOAT32_C(  293.21), SIMDE_FLOAT32_C( -340.18)),
      simde_mm_set_epi32(   0, -11517,  293, -340) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(-11516.98), SIMDE_FLOAT32_C( -141.85), SIMDE_FLOAT32_C(  -14.16)),
      simde_mm_set_epi32(   0, -11517, -142,  -14) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_cvtps_epi32(test_vec[i].a);
    for (size_t j = 0 ; j < sizeof(test_vec[i].a.f32) / sizeof(test_vec[i].a.f32[0]) ; j++)
      simde_assert_int32_close(r.i32[j], test_vec[i].r.i32[j]);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_cvtps_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128 a;
    simde__m128d r;
  } test_vec[8] = {
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  295.41), SIMDE_FLOAT32_C( -909.65), SIMDE_FLOAT32_C(  156.64), SIMDE_FLOAT32_C( -802.16)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  156.64), SIMDE_FLOAT64_C( -802.16)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  649.83), SIMDE_FLOAT32_C( -763.68), SIMDE_FLOAT32_C(  364.80), SIMDE_FLOAT32_C(  389.19)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  364.80), SIMDE_FLOAT64_C(  389.19)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  269.92), SIMDE_FLOAT32_C( -207.13), SIMDE_FLOAT32_C(  538.63), SIMDE_FLOAT32_C(  487.11)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  538.63), SIMDE_FLOAT64_C(  487.11)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C( -982.29), SIMDE_FLOAT32_C(  234.64), SIMDE_FLOAT32_C(  -53.82), SIMDE_FLOAT32_C(  899.43)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -53.82), SIMDE_FLOAT64_C(  899.43)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  945.89), SIMDE_FLOAT32_C(  -98.53), SIMDE_FLOAT32_C(    1.57), SIMDE_FLOAT32_C(   49.07)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    1.57), SIMDE_FLOAT64_C(   49.07)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  -47.73), SIMDE_FLOAT32_C(  806.42), SIMDE_FLOAT32_C(   11.76), SIMDE_FLOAT32_C(   -1.19)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   11.76), SIMDE_FLOAT64_C(   -1.19)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C( -961.08), SIMDE_FLOAT32_C( -192.05), SIMDE_FLOAT32_C(  553.30), SIMDE_FLOAT32_C( -994.71)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  553.30), SIMDE_FLOAT64_C( -994.71)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(    9.30), SIMDE_FLOAT32_C( -203.20), SIMDE_FLOAT32_C( -196.20), SIMDE_FLOAT32_C(  707.05)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -196.20), SIMDE_FLOAT64_C(  707.05)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_cvtps_pd(test_vec[i].a);
    simde_assert_m128d_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_cvtsd_f64(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128d a;
    simde_float64 r;
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  298.96), SIMDE_FLOAT64_C(   39.67)),
      SIMDE_FLOAT64_C(  39.67) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  -98.64), SIMDE_FLOAT64_C( -641.95)),
      SIMDE_FLOAT64_C(-641.95) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -307.30), SIMDE_FLOAT64_C( -193.04)),
      SIMDE_FLOAT64_C(-193.04) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -648.72), SIMDE_FLOAT64_C(  830.29)),
      SIMDE_FLOAT64_C( 830.29) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -701.20), SIMDE_FLOAT64_C( -501.79)),
      SIMDE_FLOAT64_C(-501.79) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  755.28), SIMDE_FLOAT64_C(  648.10)),
      SIMDE_FLOAT64_C( 648.10) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -664.63), SIMDE_FLOAT64_C(  220.54)),
      SIMDE_FLOAT64_C( 220.54) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -762.92), SIMDE_FLOAT64_C( -101.29)),
      SIMDE_FLOAT64_C(-101.29) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_float64 r = simde_mm_cvtsd_f64(test_vec[i].a);
    munit_assert_double_equal(r, test_vec[i].r, 2);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_cvtsd_si32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128d a;
    int32_t r;
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -786.65), SIMDE_FLOAT64_C(   95.61)),   96 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  269.52), SIMDE_FLOAT64_C(  731.54)),  732 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  692.00), SIMDE_FLOAT64_C(  924.73)),  925 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  482.19), SIMDE_FLOAT64_C( -585.95)), -586 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -916.45), SIMDE_FLOAT64_C(    4.54)),    5 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(   -1.98), SIMDE_FLOAT64_C(  865.83)),  866 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  763.06), SIMDE_FLOAT64_C(  897.97)),  898 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  320.71), SIMDE_FLOAT64_C(  383.53)),  384 }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    int32_t r = simde_mm_cvtsd_si32(test_vec[i].a);
    simde_assert_int32_close(r, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_cvtsd_si64(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128d a;
    int64_t r;
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  793.30), SIMDE_FLOAT64_C( -706.75)), -707 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(   29.13), SIMDE_FLOAT64_C( -309.00)), -309 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(   21.24), SIMDE_FLOAT64_C(  368.17)),  368 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -595.30), SIMDE_FLOAT64_C(  351.60)),  352 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -640.13), SIMDE_FLOAT64_C( -466.84)), -467 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -237.20), SIMDE_FLOAT64_C( -994.72)), -995 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -983.23), SIMDE_FLOAT64_C(  645.14)),  645 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  -89.10), SIMDE_FLOAT64_C(  585.69)),  586 }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    int64_t r = simde_mm_cvtsd_si64(test_vec[i].a);
    simde_assert_int64_close(r, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_cvtsd_ss(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128 a;
    simde__m128d b;
    simde__m128 r;
  } test_vec[8] = {
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  522.41), SIMDE_FLOAT32_C(  122.44), SIMDE_FLOAT32_C(  708.76), SIMDE_FLOAT32_C(  910.97)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -52.04), SIMDE_FLOAT64_C(  228.75)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  522.41), SIMDE_FLOAT32_C(  122.44), SIMDE_FLOAT32_C(  708.76), SIMDE_FLOAT32_C(  228.75)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C( -311.44), SIMDE_FLOAT32_C(  267.00), SIMDE_FLOAT32_C(  965.23), SIMDE_FLOAT32_C( -248.92)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -89.48), SIMDE_FLOAT64_C(  178.71)),
      simde_mm_set_ps(SIMDE_FLOAT32_C( -311.44), SIMDE_FLOAT32_C(  267.00), SIMDE_FLOAT32_C(  965.23), SIMDE_FLOAT32_C(  178.71)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  252.50), SIMDE_FLOAT32_C(  744.35), SIMDE_FLOAT32_C(  237.50), SIMDE_FLOAT32_C(  713.77)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -913.96), SIMDE_FLOAT64_C(  935.45)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  252.50), SIMDE_FLOAT32_C(  744.35), SIMDE_FLOAT32_C(  237.50), SIMDE_FLOAT32_C(  935.45)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  781.08), SIMDE_FLOAT32_C(  -50.03), SIMDE_FLOAT32_C( -658.11), SIMDE_FLOAT32_C(  945.59)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -556.84), SIMDE_FLOAT64_C(  452.90)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  781.08), SIMDE_FLOAT32_C(  -50.03), SIMDE_FLOAT32_C( -658.11), SIMDE_FLOAT32_C(  452.90)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  459.13), SIMDE_FLOAT32_C(  794.72), SIMDE_FLOAT32_C(  105.91), SIMDE_FLOAT32_C(  688.90)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -123.20), SIMDE_FLOAT64_C(  469.36)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  459.13), SIMDE_FLOAT32_C(  794.72), SIMDE_FLOAT32_C(  105.91), SIMDE_FLOAT32_C(  469.36)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C( -699.67), SIMDE_FLOAT32_C(  751.26), SIMDE_FLOAT32_C(   72.14), SIMDE_FLOAT32_C( -162.03)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  868.66), SIMDE_FLOAT64_C(  138.18)),
      simde_mm_set_ps(SIMDE_FLOAT32_C( -699.67), SIMDE_FLOAT32_C(  751.26), SIMDE_FLOAT32_C(   72.14), SIMDE_FLOAT32_C(  138.18)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C( -144.80), SIMDE_FLOAT32_C(  372.44), SIMDE_FLOAT32_C( -878.31), SIMDE_FLOAT32_C(  984.43)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -559.54), SIMDE_FLOAT64_C(  112.58)),
      simde_mm_set_ps(SIMDE_FLOAT32_C( -144.80), SIMDE_FLOAT32_C(  372.44), SIMDE_FLOAT32_C( -878.31), SIMDE_FLOAT32_C(  112.58)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C( -958.65), SIMDE_FLOAT32_C(  333.33), SIMDE_FLOAT32_C( -940.30), SIMDE_FLOAT32_C(  396.81)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  263.65), SIMDE_FLOAT64_C(  199.76)),
      simde_mm_set_ps(SIMDE_FLOAT32_C( -958.65), SIMDE_FLOAT32_C(  333.33), SIMDE_FLOAT32_C( -940.30), SIMDE_FLOAT32_C(  199.76)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128 r = simde_mm_cvtsd_ss(test_vec[i].a, test_vec[i].b);
    simde_assert_m128_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_cvtsi128_si32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    int32_t r;
  } test_vec[8] = {
    { simde_mm_set_epi32(   26453550,  -127780894,   765191664, -1527053336), -1527053336 },
    { simde_mm_set_epi32(-2072408746,   654549051, -1035182329,  -310311602),  -310311602 },
    { simde_mm_set_epi32(-1491944780,  -848128842,   200170171,  -471300206),  -471300206 },
    { simde_mm_set_epi32(-1218501110,   680592926,  -869682471,  -297305797),  -297305797 },
    { simde_mm_set_epi32(-1884581495,  -571508262,  -111379645, -1274133785), -1274133785 },
    { simde_mm_set_epi32(  486988098,   416284528,  1359642222,   197671232),   197671232 },
    { simde_mm_set_epi32(  296562088, -1151305617, -1413122888, -1640910233), -1640910233 },
    { simde_mm_set_epi32(-1262725255, -1253335394,   -91416000, -1892793314), -1892793314 }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    int32_t r = simde_mm_cvtsi128_si32(test_vec[i].a);
    munit_assert_int32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_cvtsi64_si128(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    int64_t a;
    simde__m128i r;
  } test_vec[8] = {
    { INT64_C(   6168135010467220065),
      simde_mm_set_epi64x(INT64_C(                     0), INT64_C(   6168135010467220065)) },
    { INT64_C(   3895170522828645721),
      simde_mm_set_epi64x(INT64_C(                     0), INT64_C(   3895170522828645721)) },
    { INT64_C(  -3378210069702593578),
      simde_mm_set_epi64x(INT64_C(                     0), INT64_C(  -3378210069702593578)) },
    { INT64_C(   2750396577149404222),
      simde_mm_set_epi64x(INT64_C(                     0), INT64_C(   2750396577149404222)) },
    { INT64_C(   1438311486113044813),
      simde_mm_set_epi64x(INT64_C(                     0), INT64_C(   1438311486113044813)) },
    { INT64_C(   3416877519561179684),
      simde_mm_set_epi64x(INT64_C(                     0), INT64_C(   3416877519561179684)) },
    { INT64_C(   5633937201227624265),
      simde_mm_set_epi64x(INT64_C(                     0), INT64_C(   5633937201227624265)) },
    { INT64_C(  -3544191055453826903),
      simde_mm_set_epi64x(INT64_C(                     0), INT64_C(  -3544191055453826903)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_cvtsi64_si128(test_vec[i].a);
    simde_assert_m128i_i64(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_cvtsi128_si64(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    int64_t r;
  } test_vec[8] = {
    { simde_mm_set_epi64x(INT64_C(   6773505374496819552), INT64_C(   4667650958864037640)),
      INT64_C(   4667650958864037640) },
    { simde_mm_set_epi64x(INT64_C(   1327994882711935975), INT64_C(   6055234041306631062)),
      INT64_C(   6055234041306631062) },
    { simde_mm_set_epi64x(INT64_C(   8972445642279437044), INT64_C(  -4761409530754735793)),
      INT64_C(  -4761409530754735793) },
    { simde_mm_set_epi64x(INT64_C(   7460890732678939925), INT64_C(   5266150742597997743)),
      INT64_C(   5266150742597997743) },
    { simde_mm_set_epi64x(INT64_C(  -6075061397734634308), INT64_C(    487741331498539771)),
      INT64_C(    487741331498539771) },
    { simde_mm_set_epi64x(INT64_C(   2874947710909797095), INT64_C(   2287065406213692181)),
      INT64_C(   2287065406213692181) },
    { simde_mm_set_epi64x(INT64_C(   8598185467708417568), INT64_C(  -2745610728130306920)),
      INT64_C(  -2745610728130306920) },
    { simde_mm_set_epi64x(INT64_C(   6122366414867950497), INT64_C(    614503884136124395)),
      INT64_C(    614503884136124395) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    int64_t r = simde_mm_cvtsi128_si64(test_vec[i].a);
    munit_assert_int64(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_cvtsi32_sd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128d a;
    int b;
    simde__m128d r;
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -601.07), SIMDE_FLOAT64_C(  516.34)),
      -768,
      simde_mm_set_pd(SIMDE_FLOAT64_C( -601.07), SIMDE_FLOAT64_C( -768.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -939.83), SIMDE_FLOAT64_C(  135.41)),
      -383,
      simde_mm_set_pd(SIMDE_FLOAT64_C( -939.83), SIMDE_FLOAT64_C( -383.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  503.65), SIMDE_FLOAT64_C(  859.44)),
       872,
      simde_mm_set_pd(SIMDE_FLOAT64_C(  503.65), SIMDE_FLOAT64_C(  872.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  -76.44), SIMDE_FLOAT64_C(  854.87)),
       613,
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -76.44), SIMDE_FLOAT64_C(  613.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  520.67), SIMDE_FLOAT64_C( -993.40)),
       197,
      simde_mm_set_pd(SIMDE_FLOAT64_C(  520.67), SIMDE_FLOAT64_C(  197.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  461.59), SIMDE_FLOAT64_C( -572.51)),
      -157,
      simde_mm_set_pd(SIMDE_FLOAT64_C(  461.59), SIMDE_FLOAT64_C( -157.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -113.22), SIMDE_FLOAT64_C(  791.22)),
      -840,
      simde_mm_set_pd(SIMDE_FLOAT64_C( -113.22), SIMDE_FLOAT64_C( -840.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  707.47), SIMDE_FLOAT64_C(  954.02)),
      -347,
      simde_mm_set_pd(SIMDE_FLOAT64_C(  707.47), SIMDE_FLOAT64_C( -347.00)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_cvtsi32_sd(test_vec[i].a, test_vec[i].b);
    simde_assert_m128d_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_cvtsi32_si128(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    int32_t a;
    simde__m128i r;
  } test_vec[8] = {
    {   306582644, simde_mm_set_epi32(0, 0, 0,  306582644) },
    {  -365974780, simde_mm_set_epi32(0, 0, 0, -365974780) },
    {   -85065628, simde_mm_set_epi32(0, 0, 0,  -85065628) },
    {  1053254834, simde_mm_set_epi32(0, 0, 0, 1053254834) },
    {  -236294791, simde_mm_set_epi32(0, 0, 0, -236294791) },
    {  1341442607, simde_mm_set_epi32(0, 0, 0, 1341442607) },
    {   336976017, simde_mm_set_epi32(0, 0, 0,  336976017) },
    {  1400276059, simde_mm_set_epi32(0, 0, 0, 1400276059) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_cvtsi32_si128(test_vec[i].a);
    simde_assert_m128i_i32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_cvtsi64_sd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128d a;
    int64_t b;
    simde__m128d r;
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  229.24), SIMDE_FLOAT64_C(  177.04)),  637,
      simde_mm_set_pd(SIMDE_FLOAT64_C(  229.24), SIMDE_FLOAT64_C(  637.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  401.10), SIMDE_FLOAT64_C(  284.52)), -162,
      simde_mm_set_pd(SIMDE_FLOAT64_C(  401.10), SIMDE_FLOAT64_C( -162.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  499.46), SIMDE_FLOAT64_C(  321.47)), -540,
      simde_mm_set_pd(SIMDE_FLOAT64_C(  499.46), SIMDE_FLOAT64_C( -540.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -710.92), SIMDE_FLOAT64_C(  858.14)),  -64,
      simde_mm_set_pd(SIMDE_FLOAT64_C( -710.92), SIMDE_FLOAT64_C(  -64.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -289.27), SIMDE_FLOAT64_C( -887.54)), -238,
      simde_mm_set_pd(SIMDE_FLOAT64_C( -289.27), SIMDE_FLOAT64_C( -238.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  865.34), SIMDE_FLOAT64_C(  242.15)),  121,
      simde_mm_set_pd(SIMDE_FLOAT64_C(  865.34), SIMDE_FLOAT64_C(  121.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -376.10), SIMDE_FLOAT64_C( -965.52)),  315,
      simde_mm_set_pd(SIMDE_FLOAT64_C( -376.10), SIMDE_FLOAT64_C(  315.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  673.51), SIMDE_FLOAT64_C( -882.88)),  -72,
      simde_mm_set_pd(SIMDE_FLOAT64_C(  673.51), SIMDE_FLOAT64_C(  -72.00)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_cvtsi64_sd(test_vec[i].a, test_vec[i].b);
    simde_assert_m128d_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_cvtss_sd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128d a;
    simde__m128 b;
    simde__m128d r;
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C( 546.48), SIMDE_FLOAT64_C( 729.20)),
      simde_mm_set_ps(SIMDE_FLOAT32_C( 142.68), SIMDE_FLOAT32_C( -75.76), SIMDE_FLOAT32_C(-648.72), SIMDE_FLOAT32_C( 148.36)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( 546.48), SIMDE_FLOAT64_C( 148.36)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  79.60), SIMDE_FLOAT64_C( 648.49)),
      simde_mm_set_ps(SIMDE_FLOAT32_C( 631.34), SIMDE_FLOAT32_C( 902.53), SIMDE_FLOAT32_C( -54.65), SIMDE_FLOAT32_C( 614.98)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  79.60), SIMDE_FLOAT64_C( 614.98)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( 811.47), SIMDE_FLOAT64_C( -95.71)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  13.27), SIMDE_FLOAT32_C( 315.63), SIMDE_FLOAT32_C( 407.80), SIMDE_FLOAT32_C(-826.61)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( 811.47), SIMDE_FLOAT64_C(-826.61)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( 315.42), SIMDE_FLOAT64_C( -69.06)),
      simde_mm_set_ps(SIMDE_FLOAT32_C( 775.15), SIMDE_FLOAT32_C( 935.54), SIMDE_FLOAT32_C(-964.44), SIMDE_FLOAT32_C( 659.62)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( 315.42), SIMDE_FLOAT64_C( 659.62)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(-579.75), SIMDE_FLOAT64_C(-291.65)),
      simde_mm_set_ps(SIMDE_FLOAT32_C( 533.61), SIMDE_FLOAT32_C( 565.53), SIMDE_FLOAT32_C( -36.93), SIMDE_FLOAT32_C(  57.54)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(-579.75), SIMDE_FLOAT64_C(  57.54)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( 979.09), SIMDE_FLOAT64_C(-471.44)),
      simde_mm_set_ps(SIMDE_FLOAT32_C( 927.62), SIMDE_FLOAT32_C( 955.93), SIMDE_FLOAT32_C(-964.80), SIMDE_FLOAT32_C( 823.88)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( 979.09), SIMDE_FLOAT64_C( 823.88)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( 172.44), SIMDE_FLOAT64_C(-427.74)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(-343.18), SIMDE_FLOAT32_C(-352.03), SIMDE_FLOAT32_C(-836.30), SIMDE_FLOAT32_C( -61.82)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( 172.44), SIMDE_FLOAT64_C( -61.82)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( 975.42), SIMDE_FLOAT64_C( 394.72)),
      simde_mm_set_ps(SIMDE_FLOAT32_C( 748.90), SIMDE_FLOAT32_C(-410.84), SIMDE_FLOAT32_C( 636.92), SIMDE_FLOAT32_C( 230.31)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( 975.42), SIMDE_FLOAT64_C( 230.31)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_cvtss_sd(test_vec[i].a, test_vec[i].b);
    simde_assert_m128d_close(r, test_vec[i].r, 2);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_cvttpd_epi32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128d a;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C(-804.05), SIMDE_FLOAT64_C( 341.74)),
      simde_mm_set_epi32(0, 0, -804,  341) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( 962.24), SIMDE_FLOAT64_C(-569.72)),
      simde_mm_set_epi32(0, 0,  962, -569) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( 250.89), SIMDE_FLOAT64_C( 802.88)),
      simde_mm_set_epi32(0, 0,  250,  802) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( 810.60), SIMDE_FLOAT64_C(-311.86)),
      simde_mm_set_epi32(0, 0,  810, -311) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(-993.06), SIMDE_FLOAT64_C(-497.38)),
      simde_mm_set_epi32(0, 0, -993, -497) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  41.80), SIMDE_FLOAT64_C(-969.69)),
      simde_mm_set_epi32(0, 0,   41, -969) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( 550.85), SIMDE_FLOAT64_C( 912.08)),
      simde_mm_set_epi32(0, 0,  550,  912) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( 165.92), SIMDE_FLOAT64_C( -84.76)),
      simde_mm_set_epi32(0, 0,  165,  -84) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_cvttpd_epi32(test_vec[i].a);
    for (size_t j = 0 ; j < 2 ; j++)
      munit_assert_int32(r.i32[j], ==, test_vec[i].r.i32[j]);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_cvttpd_pi32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128d a;
    simde__m64 r;
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -31.65), SIMDE_FLOAT64_C( 302.59)),
      simde_mm_set_pi32( -31,  302) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(-119.29), SIMDE_FLOAT64_C( -18.22)),
      simde_mm_set_pi32(-119,  -18) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(-706.80), SIMDE_FLOAT64_C(-266.39)),
      simde_mm_set_pi32(-706, -266) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( 204.37), SIMDE_FLOAT64_C( 451.92)),
      simde_mm_set_pi32( 204,  451) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(-953.22), SIMDE_FLOAT64_C(-488.59)),
      simde_mm_set_pi32(-953, -488) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( 812.77), SIMDE_FLOAT64_C( -99.24)),
      simde_mm_set_pi32( 812,  -99) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(-532.78), SIMDE_FLOAT64_C(-983.93)),
      simde_mm_set_pi32(-532, -983) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( 864.25), SIMDE_FLOAT64_C(-434.51)),
      simde_mm_set_pi32( 864, -434) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m64 r = simde_mm_cvttpd_pi32(test_vec[i].a);
    simde_assert_m64_i32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_cvttps_epi32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128 a;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_ps(SIMDE_FLOAT32_C(-529.70), SIMDE_FLOAT32_C( 872.16), SIMDE_FLOAT32_C( 247.85), SIMDE_FLOAT32_C( 866.62)),
      simde_mm_set_epi32(-529, 872,  247,  866) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C( 543.02), SIMDE_FLOAT32_C(-211.71), SIMDE_FLOAT32_C( 579.48), SIMDE_FLOAT32_C(-807.83)),
      simde_mm_set_epi32(543, -211,  579, -807) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(-740.55), SIMDE_FLOAT32_C( 847.79), SIMDE_FLOAT32_C(-708.61), SIMDE_FLOAT32_C( 883.97)),
      simde_mm_set_epi32(-740, 847, -708,  883) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(-439.93), SIMDE_FLOAT32_C( 682.25), SIMDE_FLOAT32_C(-615.83), SIMDE_FLOAT32_C( 330.85)),
      simde_mm_set_epi32(-439, 682, -615,  330) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C( 750.74), SIMDE_FLOAT32_C( 646.41), SIMDE_FLOAT32_C( 456.96), SIMDE_FLOAT32_C(-492.54)),
      simde_mm_set_epi32(750, 646,  456, -492) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(-556.32), SIMDE_FLOAT32_C( 674.09), SIMDE_FLOAT32_C(-481.35), SIMDE_FLOAT32_C( 566.79)),
      simde_mm_set_epi32(-556, 674, -481,  566) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C( 753.09), SIMDE_FLOAT32_C( 737.97), SIMDE_FLOAT32_C( 556.48), SIMDE_FLOAT32_C( 999.26)),
      simde_mm_set_epi32(753, 737,  556,  999) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_cvttps_epi32(test_vec[i].a);
    simde_assert_m128i_i32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_cvttsd_si32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128d a;
    int32_t r;
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C( 598.37), SIMDE_FLOAT64_C(  47.84)),   47 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( 651.65), SIMDE_FLOAT64_C( 630.05)),  630 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(-329.53), SIMDE_FLOAT64_C(-222.72)), -222 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( 472.59), SIMDE_FLOAT64_C( 189.93)),  189 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( 916.43), SIMDE_FLOAT64_C(-342.09)), -342 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( 904.58), SIMDE_FLOAT64_C(  10.13)),   10 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( 841.20), SIMDE_FLOAT64_C( -18.78)),  -18 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(-895.94), SIMDE_FLOAT64_C(-849.46)), -849 }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    int32_t r = simde_mm_cvttsd_si32(test_vec[i].a);
    munit_assert_int32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_cvttsd_si64(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128d a;
    int64_t r;
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C(-345.97), SIMDE_FLOAT64_C( 664.87)),  664 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( 648.27), SIMDE_FLOAT64_C(-390.19)), -390 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(-500.63), SIMDE_FLOAT64_C(-258.15)), -258 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(-109.22), SIMDE_FLOAT64_C(-784.27)), -784 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(-688.79), SIMDE_FLOAT64_C(-698.22)), -698 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(-914.25), SIMDE_FLOAT64_C(-650.88)), -650 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(-228.35), SIMDE_FLOAT64_C(-603.46)), -603 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(-556.94), SIMDE_FLOAT64_C( 694.64)),  694 }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    int64_t r = simde_mm_cvttsd_si64(test_vec[i].a);
    munit_assert_int64(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_div_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128d a;
    simde__m128d b;
    simde__m128d r;
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -184.40), SIMDE_FLOAT64_C(  992.45)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  155.72), SIMDE_FLOAT64_C(  856.52)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   -1.18), SIMDE_FLOAT64_C(    1.16)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  -34.37), SIMDE_FLOAT64_C(  596.67)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -718.99), SIMDE_FLOAT64_C(  -17.98)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.05), SIMDE_FLOAT64_C(  -33.19)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  797.64), SIMDE_FLOAT64_C(  669.98)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -872.55), SIMDE_FLOAT64_C(  857.06)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   -0.91), SIMDE_FLOAT64_C(    0.78)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -864.62), SIMDE_FLOAT64_C(  635.60)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -556.59), SIMDE_FLOAT64_C(  676.91)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    1.55), SIMDE_FLOAT64_C(    0.94)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -635.32), SIMDE_FLOAT64_C(  518.94)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -426.58), SIMDE_FLOAT64_C( -331.30)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    1.49), SIMDE_FLOAT64_C(   -1.57)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -494.90), SIMDE_FLOAT64_C(  -42.04)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  432.98), SIMDE_FLOAT64_C(  277.38)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   -1.14), SIMDE_FLOAT64_C(   -0.15)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -530.41), SIMDE_FLOAT64_C(  112.07)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -914.02), SIMDE_FLOAT64_C(   90.15)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.58), SIMDE_FLOAT64_C(    1.24)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -176.73), SIMDE_FLOAT64_C( -245.01)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  315.38), SIMDE_FLOAT64_C( -747.83)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   -0.56), SIMDE_FLOAT64_C(    0.33)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_div_pd(test_vec[i].a, test_vec[i].b);
    simde_assert_m128d_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_div_sd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128d a;
    simde__m128d b;
    simde__m128d r;
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -164.12), SIMDE_FLOAT64_C( -192.56)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -917.87), SIMDE_FLOAT64_C(  429.05)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -164.12), SIMDE_FLOAT64_C(   -0.45)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  658.48), SIMDE_FLOAT64_C(  164.94)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -29.79), SIMDE_FLOAT64_C(  356.73)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  658.48), SIMDE_FLOAT64_C(    0.46)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -450.41), SIMDE_FLOAT64_C(  587.65)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  553.54), SIMDE_FLOAT64_C( -684.22)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -450.41), SIMDE_FLOAT64_C(   -0.86)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -742.91), SIMDE_FLOAT64_C( -966.41)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  180.37), SIMDE_FLOAT64_C(  175.93)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -742.91), SIMDE_FLOAT64_C(   -5.49)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -280.67), SIMDE_FLOAT64_C(  415.67)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  495.86), SIMDE_FLOAT64_C( -819.23)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -280.67), SIMDE_FLOAT64_C(   -0.51)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  391.69), SIMDE_FLOAT64_C(  589.87)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -651.02), SIMDE_FLOAT64_C( -239.35)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  391.69), SIMDE_FLOAT64_C(   -2.46)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  423.52), SIMDE_FLOAT64_C(  419.28)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  336.50), SIMDE_FLOAT64_C(  431.02)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  423.52), SIMDE_FLOAT64_C(    0.97)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  235.17), SIMDE_FLOAT64_C( -333.81)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -715.21), SIMDE_FLOAT64_C(    4.82)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  235.17), SIMDE_FLOAT64_C(  -69.26)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_div_sd(test_vec[i].a, test_vec[i].b);
    simde_assert_m128d_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_extract_epi16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    int32_t r;
  } test_vec[8] = {
    { simde_mm_set_epi16(-22888, -26241,  16094,  25365, -10975,  -4323,   9478, -18966), 54561 },
    { simde_mm_set_epi16( -4494, -23544,  12313,  19220,  16921,   9248,  -1076, -18617), 16921 },
    { simde_mm_set_epi16(  5051,  30913,  18404, -11820,  16495,  32647,  21150,  16664), 16495 },
    { simde_mm_set_epi16(   987,  32176, -17758,  21096,   -945,   5537,   5495, -18130), 64591 },
    { simde_mm_set_epi16(-16046,  13714,  12272,  32151, -14156,   8851, -19624,  -2653), 51380 },
    { simde_mm_set_epi16(-28172,   1666,  15569,  -1622,  22048, -24364,   2478,  20826), 22048 },
    { simde_mm_set_epi16(-29653, -27750,   5027,  -7816, -20852,   3178, -27881,   3156), 44684 },
    { simde_mm_set_epi16(-26280,  27067,  10815, -30178, -26852,  26399, -30202, -11030), 38684 }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    int32_t r = simde_mm_extract_epi16(test_vec[i].a, 3);
    munit_assert_int32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_insert_epi16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    int16_t b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi16(-18659,  19491, -30434,  -6059,  11985,   5369, -14188,   9668),
       21712,
      simde_mm_set_epi16(-18659,  19491, -30434,  -6059,  21712,   5369, -14188,   9668) },
    { simde_mm_set_epi16( 32684, -21716,   7657,   3627,  12377,  30609, -12611, -11955),
      -27473,
      simde_mm_set_epi16( 32684, -21716,   7657,   3627, -27473,  30609, -12611, -11955) },
    { simde_mm_set_epi16(-18344,  -4896, -19094,   -638, -30376, -17556, -31358, -17530),
      -19116,
      simde_mm_set_epi16(-18344,  -4896, -19094,   -638, -19116, -17556, -31358, -17530) },
    { simde_mm_set_epi16(-11121,  29288,  -3915,  13306,  30582,   4374,  -9323,  -2317),
        5778,
      simde_mm_set_epi16(-11121,  29288,  -3915,  13306,   5778,   4374,  -9323,  -2317) },
    { simde_mm_set_epi16(  7542, -16196, -24612,   8929, -16460,  17259,    672, -18076),
        -411,
      simde_mm_set_epi16(  7542, -16196, -24612,   8929,   -411,  17259,    672, -18076) },
    { simde_mm_set_epi16( 15913, -18873,  14978,  31946,  -6939,  26150,  18499, -16752),
        1141,
      simde_mm_set_epi16( 15913, -18873,  14978,  31946,   1141,  26150,  18499, -16752) },
    { simde_mm_set_epi16(  1093,  -6101, -30747, -18266,   4085, -14478,  -6279, -25531),
      -18605,
      simde_mm_set_epi16(  1093,  -6101, -30747, -18266, -18605, -14478,  -6279, -25531) },
    { simde_mm_set_epi16( -2463,  -3389,  28311,  -5667,  24886,  24368,  19484, -11581),
      -17420,
      simde_mm_set_epi16( -2463,  -3389,  28311,  -5667, -17420,  24368,  19484, -11581) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_insert_epi16(test_vec[i].a, test_vec[i].b, 3);
    simde_assert_m128i_i16(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_load_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    SIMDE_ALIGN(16) simde_float64 mem_addr[2];
    simde__m128d r;
  } test_vec[8] = {
    { {SIMDE_FLOAT64_C(  -851.11), SIMDE_FLOAT64_C( -276.93) },
      simde_mm_set_pd(SIMDE_FLOAT64_C(-276.93), SIMDE_FLOAT64_C(-851.11)) },
    { {SIMDE_FLOAT64_C(   817.70), SIMDE_FLOAT64_C(  975.23) },
      simde_mm_set_pd(SIMDE_FLOAT64_C( 975.23), SIMDE_FLOAT64_C( 817.70)) },
    { {SIMDE_FLOAT64_C(   -76.44), SIMDE_FLOAT64_C( -676.02) },
      simde_mm_set_pd(SIMDE_FLOAT64_C(-676.02), SIMDE_FLOAT64_C( -76.44)) },
    { {SIMDE_FLOAT64_C(   744.31), SIMDE_FLOAT64_C( -487.12) },
      simde_mm_set_pd(SIMDE_FLOAT64_C(-487.12), SIMDE_FLOAT64_C( 744.31)) },
    { {SIMDE_FLOAT64_C(   396.80), SIMDE_FLOAT64_C( -527.42) },
      simde_mm_set_pd(SIMDE_FLOAT64_C(-527.42), SIMDE_FLOAT64_C( 396.80)) },
    { {SIMDE_FLOAT64_C(  -957.24), SIMDE_FLOAT64_C( -712.40) },
      simde_mm_set_pd(SIMDE_FLOAT64_C(-712.40), SIMDE_FLOAT64_C(-957.24)) },
    { {SIMDE_FLOAT64_C(  -703.05), SIMDE_FLOAT64_C(  457.17) },
      simde_mm_set_pd(SIMDE_FLOAT64_C( 457.17), SIMDE_FLOAT64_C(-703.05)) },
    { {SIMDE_FLOAT64_C(   990.46), SIMDE_FLOAT64_C(  487.75) },
      simde_mm_set_pd(SIMDE_FLOAT64_C( 487.75), SIMDE_FLOAT64_C( 990.46)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_load_pd(test_vec[i].mem_addr);
    simde_assert_m128d_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_load_pd1(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde_float64 a;
    simde__m128d r;
  } test_vec[8] = {
    {SIMDE_FLOAT64_C( -639.28), simde_mm_set_pd(SIMDE_FLOAT64_C(-639.28), SIMDE_FLOAT64_C(-639.28)) },
    {SIMDE_FLOAT64_C(  754.31), simde_mm_set_pd(SIMDE_FLOAT64_C( 754.31), SIMDE_FLOAT64_C( 754.31)) },
    {SIMDE_FLOAT64_C( -143.09), simde_mm_set_pd(SIMDE_FLOAT64_C(-143.09), SIMDE_FLOAT64_C(-143.09)) },
    {SIMDE_FLOAT64_C( -509.95), simde_mm_set_pd(SIMDE_FLOAT64_C(-509.95), SIMDE_FLOAT64_C(-509.95)) },
    {SIMDE_FLOAT64_C(  357.11), simde_mm_set_pd(SIMDE_FLOAT64_C( 357.11), SIMDE_FLOAT64_C( 357.11)) },
    {SIMDE_FLOAT64_C(  414.83), simde_mm_set_pd(SIMDE_FLOAT64_C( 414.83), SIMDE_FLOAT64_C( 414.83)) },
    {SIMDE_FLOAT64_C(  416.46), simde_mm_set_pd(SIMDE_FLOAT64_C( 416.46), SIMDE_FLOAT64_C( 416.46)) },
    {SIMDE_FLOAT64_C(  167.42), simde_mm_set_pd(SIMDE_FLOAT64_C( 167.42), SIMDE_FLOAT64_C( 167.42)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_load_pd1(&test_vec[i].a);
    simde_assert_m128d_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_load_sd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde_float64 a;
    simde__m128d r;
  } test_vec[8] = {
    {SIMDE_FLOAT64_C(  883.59), simde_mm_set_pd(SIMDE_FLOAT64_C(   0.00), SIMDE_FLOAT64_C( 883.59)) },
    {SIMDE_FLOAT64_C(  719.08), simde_mm_set_pd(SIMDE_FLOAT64_C(   0.00), SIMDE_FLOAT64_C( 719.08)) },
    {SIMDE_FLOAT64_C(  -82.94), simde_mm_set_pd(SIMDE_FLOAT64_C(   0.00), SIMDE_FLOAT64_C( -82.94)) },
    {SIMDE_FLOAT64_C(  -87.79), simde_mm_set_pd(SIMDE_FLOAT64_C(   0.00), SIMDE_FLOAT64_C( -87.79)) },
    {SIMDE_FLOAT64_C(  309.31), simde_mm_set_pd(SIMDE_FLOAT64_C(   0.00), SIMDE_FLOAT64_C( 309.31)) },
    {SIMDE_FLOAT64_C( -987.67), simde_mm_set_pd(SIMDE_FLOAT64_C(   0.00), SIMDE_FLOAT64_C(-987.67)) },
    {SIMDE_FLOAT64_C(  196.18), simde_mm_set_pd(SIMDE_FLOAT64_C(   0.00), SIMDE_FLOAT64_C( 196.18)) },
    {SIMDE_FLOAT64_C(  313.82), simde_mm_set_pd(SIMDE_FLOAT64_C(   0.00), SIMDE_FLOAT64_C( 313.82)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_load_sd(&test_vec[i].a);
    simde_assert_m128d_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_load_si128(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi32(INT32_C(-1485513264), INT32_C( 2130924320), INT32_C( 1226074611), INT32_C( -306486659)),
      simde_mm_set_epi32(INT32_C(-1485513264), INT32_C( 2130924320), INT32_C( 1226074611), INT32_C( -306486659)) },
    { simde_mm_set_epi32(INT32_C(  952258085), INT32_C( -534886765), INT32_C( -354984724), INT32_C(-1450427500)),
      simde_mm_set_epi32(INT32_C(  952258085), INT32_C( -534886765), INT32_C( -354984724), INT32_C(-1450427500)) },
    { simde_mm_set_epi32(INT32_C(-1417585996), INT32_C(  546041970), INT32_C(-1469146664), INT32_C(-2062567602)),
      simde_mm_set_epi32(INT32_C(-1417585996), INT32_C(  546041970), INT32_C(-1469146664), INT32_C(-2062567602)) },
    { simde_mm_set_epi32(INT32_C(-1482230799), INT32_C(-1421432180), INT32_C(-1588201284), INT32_C(-1267673212)),
      simde_mm_set_epi32(INT32_C(-1482230799), INT32_C(-1421432180), INT32_C(-1588201284), INT32_C(-1267673212)) },
    { simde_mm_set_epi32(INT32_C(-1153380991), INT32_C( 1838203743), INT32_C( -180063833), INT32_C( -699223421)),
      simde_mm_set_epi32(INT32_C(-1153380991), INT32_C( 1838203743), INT32_C( -180063833), INT32_C( -699223421)) },
    { simde_mm_set_epi32(INT32_C( -711752348), INT32_C(  464328511), INT32_C( 1773807699), INT32_C(  849844772)),
      simde_mm_set_epi32(INT32_C( -711752348), INT32_C(  464328511), INT32_C( 1773807699), INT32_C(  849844772)) },
    { simde_mm_set_epi32(INT32_C(-1083662155), INT32_C( -641783129), INT32_C(-1893537704), INT32_C( 1971283674)),
      simde_mm_set_epi32(INT32_C(-1083662155), INT32_C( -641783129), INT32_C(-1893537704), INT32_C( 1971283674)) },
    { simde_mm_set_epi32(INT32_C(-1329936037), INT32_C( -364329957), INT32_C(-1886427840), INT32_C(-1935682760)),
      simde_mm_set_epi32(INT32_C(-1329936037), INT32_C( -364329957), INT32_C(-1886427840), INT32_C(-1935682760)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_load_si128(&test_vec[i].a);
    simde_assert_m128i_i32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_loadh_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128d a;
    simde_float64 b;
    simde__m128d r;
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -625.39), SIMDE_FLOAT64_C( -212.79)),
SIMDE_FLOAT64_C(       -544.03),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -544.03), SIMDE_FLOAT64_C( -212.79)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  906.58), SIMDE_FLOAT64_C( -446.43)),
SIMDE_FLOAT64_C(       -955.62),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -955.62), SIMDE_FLOAT64_C( -446.43)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  575.38), SIMDE_FLOAT64_C( -468.21)),
SIMDE_FLOAT64_C(       -790.22),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -790.22), SIMDE_FLOAT64_C( -468.21)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  375.10), SIMDE_FLOAT64_C( -731.74)),
SIMDE_FLOAT64_C(        857.52),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  857.52), SIMDE_FLOAT64_C( -731.74)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  -48.07), SIMDE_FLOAT64_C( -201.78)),
SIMDE_FLOAT64_C(       -122.99),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -122.99), SIMDE_FLOAT64_C( -201.78)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(   97.66), SIMDE_FLOAT64_C( -743.76)),
SIMDE_FLOAT64_C(        123.61),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  123.61), SIMDE_FLOAT64_C( -743.76)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  622.43), SIMDE_FLOAT64_C( -815.78)),
SIMDE_FLOAT64_C(       -884.62),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -884.62), SIMDE_FLOAT64_C( -815.78)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  233.02), SIMDE_FLOAT64_C(  337.90)),
SIMDE_FLOAT64_C(        566.08),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  566.08), SIMDE_FLOAT64_C(  337.90)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_loadh_pd(test_vec[i].a, &test_vec[i].b);
    simde_assert_m128d_close(r, test_vec[i].r, 4);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_loadl_epi64(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi64x(INT64_C( 7255813106314264288), INT64_C(-7993810106397570817)),
      simde_mm_set_epi64x(INT64_C(                   0), INT64_C(-7993810106397570817)) },
    { simde_mm_set_epi64x(INT64_C( 4332750521721589865), INT64_C( 5817844384904280102)),
      simde_mm_set_epi64x(INT64_C(                   0), INT64_C( 5817844384904280102)) },
    { simde_mm_set_epi64x(INT64_C( 4283557962483650351), INT64_C( 2784845276469276714)),
      simde_mm_set_epi64x(INT64_C(                   0), INT64_C( 2784845276469276714)) },
    { simde_mm_set_epi64x(INT64_C(-7450212554795150386), INT64_C(-5796827838366546148)),
      simde_mm_set_epi64x(INT64_C(                   0), INT64_C(-5796827838366546148)) },
    { simde_mm_set_epi64x(INT64_C(-3789423371168711426), INT64_C(-4307681161489005059)),
      simde_mm_set_epi64x(INT64_C(                   0), INT64_C(-4307681161489005059)) },
    { simde_mm_set_epi64x(INT64_C( 7262021029879737589), INT64_C(-2052119711886828042)),
      simde_mm_set_epi64x(INT64_C(                   0), INT64_C(-2052119711886828042)) },
    { simde_mm_set_epi64x(INT64_C( 5143182215332151867), INT64_C( 3089069619998927580)),
      simde_mm_set_epi64x(INT64_C(                   0), INT64_C( 3089069619998927580)) },
    { simde_mm_set_epi64x(INT64_C(-8554837128822217935), INT64_C( -929112165442292882)),
      simde_mm_set_epi64x(INT64_C(                   0), INT64_C( -929112165442292882)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_loadl_epi64(&test_vec[i].a);
    simde_assert_m128i_i64(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_loadl_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128d a;
    simde_float64 b;
    simde__m128d r;
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  398.25), SIMDE_FLOAT64_C(  169.44)),
SIMDE_FLOAT64_C(        512.14),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  398.25), SIMDE_FLOAT64_C(  512.14)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  747.05), SIMDE_FLOAT64_C(  122.36)),
SIMDE_FLOAT64_C(       -219.24),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  747.05), SIMDE_FLOAT64_C( -219.24)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  806.68), SIMDE_FLOAT64_C(  439.45)),
SIMDE_FLOAT64_C(        545.31),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  806.68), SIMDE_FLOAT64_C(  545.31)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -494.45), SIMDE_FLOAT64_C(  273.54)),
SIMDE_FLOAT64_C(        233.72),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -494.45), SIMDE_FLOAT64_C(  233.72)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -435.22), SIMDE_FLOAT64_C( -790.14)),
SIMDE_FLOAT64_C(        334.56),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -435.22), SIMDE_FLOAT64_C(  334.56)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -387.92), SIMDE_FLOAT64_C(  587.13)),
SIMDE_FLOAT64_C(        782.99),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -387.92), SIMDE_FLOAT64_C(  782.99)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -656.10), SIMDE_FLOAT64_C( -868.90)),
SIMDE_FLOAT64_C(       -241.17),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -656.10), SIMDE_FLOAT64_C( -241.17)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  155.11), SIMDE_FLOAT64_C( -412.38)),
SIMDE_FLOAT64_C(        606.64),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  155.11), SIMDE_FLOAT64_C(  606.64)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_loadl_pd(test_vec[i].a, &test_vec[i].b);
    simde_assert_m128d_close(r, test_vec[i].r, 4);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_loadr_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    SIMDE_ALIGN(16) simde_float64 mem_addr[2];
    simde__m128d r;
  } test_vec[8] = {
    { {SIMDE_FLOAT64_C(   808.22), SIMDE_FLOAT64_C( -538.55) },
      simde_mm_set_pd(SIMDE_FLOAT64_C( 808.22), SIMDE_FLOAT64_C(-538.55)) },
    { {SIMDE_FLOAT64_C(   475.76), SIMDE_FLOAT64_C(  878.69) },
      simde_mm_set_pd(SIMDE_FLOAT64_C( 475.76), SIMDE_FLOAT64_C( 878.69)) },
    { {SIMDE_FLOAT64_C(  -400.00), SIMDE_FLOAT64_C( -135.07) },
      simde_mm_set_pd(SIMDE_FLOAT64_C(-400.00), SIMDE_FLOAT64_C(-135.07)) },
    { {SIMDE_FLOAT64_C(   -32.33), SIMDE_FLOAT64_C( -148.19) },
      simde_mm_set_pd(SIMDE_FLOAT64_C( -32.33), SIMDE_FLOAT64_C(-148.19)) },
    { {SIMDE_FLOAT64_C(  -971.23), SIMDE_FLOAT64_C( -835.90) },
      simde_mm_set_pd(SIMDE_FLOAT64_C(-971.23), SIMDE_FLOAT64_C(-835.90)) },
    { {SIMDE_FLOAT64_C(  -891.74), SIMDE_FLOAT64_C( -424.87) },
      simde_mm_set_pd(SIMDE_FLOAT64_C(-891.74), SIMDE_FLOAT64_C(-424.87)) },
    { {SIMDE_FLOAT64_C(  -199.77), SIMDE_FLOAT64_C(  631.45) },
      simde_mm_set_pd(SIMDE_FLOAT64_C(-199.77), SIMDE_FLOAT64_C( 631.45)) },
    { {SIMDE_FLOAT64_C(   410.30), SIMDE_FLOAT64_C(  721.68) },
      simde_mm_set_pd(SIMDE_FLOAT64_C( 410.30), SIMDE_FLOAT64_C( 721.68)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_loadr_pd(test_vec[i].mem_addr);
    simde_assert_m128d_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_loadu_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde_float64 mem_addr[2];
    simde__m128d r;
  } test_vec[8] = {
    { {SIMDE_FLOAT64_C(  -578.02), SIMDE_FLOAT64_C(   20.66) },
      simde_mm_set_pd(SIMDE_FLOAT64_C(  20.66), SIMDE_FLOAT64_C(-578.02)) },
    { {SIMDE_FLOAT64_C(   370.06), SIMDE_FLOAT64_C( -720.89) },
      simde_mm_set_pd(SIMDE_FLOAT64_C(-720.89), SIMDE_FLOAT64_C( 370.06)) },
    { {SIMDE_FLOAT64_C(   584.38), SIMDE_FLOAT64_C( -849.44) },
      simde_mm_set_pd(SIMDE_FLOAT64_C(-849.44), SIMDE_FLOAT64_C( 584.38)) },
    { {SIMDE_FLOAT64_C(   636.90), SIMDE_FLOAT64_C(  349.95) },
      simde_mm_set_pd(SIMDE_FLOAT64_C( 349.95), SIMDE_FLOAT64_C( 636.90)) },
    { {SIMDE_FLOAT64_C(  -617.52), SIMDE_FLOAT64_C(  599.47) },
      simde_mm_set_pd(SIMDE_FLOAT64_C( 599.47), SIMDE_FLOAT64_C(-617.52)) },
    { {SIMDE_FLOAT64_C(   633.70), SIMDE_FLOAT64_C(   30.57) },
      simde_mm_set_pd(SIMDE_FLOAT64_C(  30.57), SIMDE_FLOAT64_C( 633.70)) },
    { {SIMDE_FLOAT64_C(  -333.40), SIMDE_FLOAT64_C(  592.38) },
      simde_mm_set_pd(SIMDE_FLOAT64_C( 592.38), SIMDE_FLOAT64_C(-333.40)) },
    { {SIMDE_FLOAT64_C(  -335.86), SIMDE_FLOAT64_C(  212.26) },
      simde_mm_set_pd(SIMDE_FLOAT64_C( 212.26), SIMDE_FLOAT64_C(-335.86)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_loadu_pd(test_vec[i].mem_addr);
    simde_assert_m128d_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_loadu_si128(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi32(INT32_C(-1538587633), INT32_C( 1769380496), INT32_C(-2023785418), INT32_C(-1729331330)),
      simde_mm_set_epi32(INT32_C(-1538587633), INT32_C( 1769380496), INT32_C(-2023785418), INT32_C(-1729331330)) },
    { simde_mm_set_epi32(INT32_C(  683658674), INT32_C( -272282451), INT32_C( -869014611), INT32_C( -138507219)),
      simde_mm_set_epi32(INT32_C(  683658674), INT32_C( -272282451), INT32_C( -869014611), INT32_C( -138507219)) },
    { simde_mm_set_epi32(INT32_C(   91205327), INT32_C(  490922736), INT32_C(-1027840667), INT32_C( -176944495)),
      simde_mm_set_epi32(INT32_C(   91205327), INT32_C(  490922736), INT32_C(-1027840667), INT32_C( -176944495)) },
    { simde_mm_set_epi32(INT32_C(-1717325090), INT32_C(-2087568357), INT32_C(-1247194597), INT32_C( 2013217211)),
      simde_mm_set_epi32(INT32_C(-1717325090), INT32_C(-2087568357), INT32_C(-1247194597), INT32_C( 2013217211)) },
    { simde_mm_set_epi32(INT32_C(  -71964779), INT32_C(  991285765), INT32_C( -740413325), INT32_C(  781513152)),
      simde_mm_set_epi32(INT32_C(  -71964779), INT32_C(  991285765), INT32_C( -740413325), INT32_C(  781513152)) },
    { simde_mm_set_epi32(INT32_C( -667758201), INT32_C( 1406497890), INT32_C( 2124206329), INT32_C(  367090944)),
      simde_mm_set_epi32(INT32_C( -667758201), INT32_C( 1406497890), INT32_C( 2124206329), INT32_C(  367090944)) },
    { simde_mm_set_epi32(INT32_C(  145405807), INT32_C( 2005056075), INT32_C(  -13890329), INT32_C(-1559659219)),
      simde_mm_set_epi32(INT32_C(  145405807), INT32_C( 2005056075), INT32_C(  -13890329), INT32_C(-1559659219)) },
    { simde_mm_set_epi32(INT32_C(  973704080), INT32_C( 1654460219), INT32_C(-1187284768), INT32_C(  306325074)),
      simde_mm_set_epi32(INT32_C(  973704080), INT32_C( 1654460219), INT32_C(-1187284768), INT32_C(  306325074)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_loadu_si128(&test_vec[i].a);
    simde_assert_m128i_i64(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_madd_epi16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi16( 24289,  22642,  24338,  21466, -21399, -25114,    -38,  24157),
      simde_mm_set_epi16( -9939, -13077, -13691, -22496,  -7750,   2620, -25114,   6535),
      simde_mm_set_epi32( -537497805,  -816110694,   100043570,   158820327) },
    { simde_mm_set_epi16( 13645,  20663,  21053,   5963,  -9189,  -1395,  25221,  27070),
      simde_mm_set_epi16(-28936, -24038,   6837,  18195, -15316, -11637,   5200,   7885),
      simde_mm_set_epi32( -891528914,   252436146,   156972339,   344596150) },
    { simde_mm_set_epi16(-31367, -13886,  25125, -12503,  15451,  -6370, -24113,   2653),
      simde_mm_set_epi16(  5595, -23387, -11854,    264,  15071,   3868, -30127,   2383),
      simde_mm_set_epi32(  149253517,  -301132542,   208222861,   732774450) },
    { simde_mm_set_epi16(  6250,    794,  -7973,  27046,  13164,  16469,   1989, -24542),
      simde_mm_set_epi16( 22452,  -4402, -26550,  31252, -29251,  -1650, -13867,  26387),
      simde_mm_set_epi32(  136829812,  1056924742,  -412234014,  -675171217) },
    { simde_mm_set_epi16(-17693, -18978,  22797,  31393,  32262, -21009,   9435,  20059),
      simde_mm_set_epi16( 20064,   4406,   1105, -32185,  26331,  -8672,  15113, -24381),
      simde_mm_set_epi32( -438609420,  -985193020,  1031680770,  -346467324) },
    { simde_mm_set_epi16( -9214, -31455, -14871,  -8603,  17039, -27694,  18091,  27811),
      simde_mm_set_epi16(  9903,   7626,  -7009, -11696, -31989,  28434, -24743, -27058),
      simde_mm_set_epi32( -331122072,   204851527, -1332511767, -1200135651) },
    { simde_mm_set_epi16( 20741,   5382, -29692,  12589,  21204,   3076, -24365,  -1783),
      simde_mm_set_epi16(-15203, -26894,  -6878, -23472, -18994,  11044,  15739,   -241),
      simde_mm_set_epi32( -460068931,   -91267432,  -368777432,  -383051032) },
    { simde_mm_set_epi16( 24682,  17647, -19806, -13656,  26394,   4814,  -4589,  17983),
      simde_mm_set_epi16(-32304, -30224, -20430, -28018,  29012,   7494,  -7871,  16228),
      simde_mm_set_epi32(-1330690256,   787250388,   801818844,   327948143) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_madd_epi16(test_vec[i].a, test_vec[i].b);
    simde_assert_m128i_i32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_maskmoveu_si128(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m128i mask;
    int8_t i[16];
    int8_t r[16];
  } test_vec[8] = {
    { simde_mm_set_epi8(INT8_C(-127), INT8_C( 121), INT8_C(  33), INT8_C(  92), INT8_C(  95), INT8_C(  30), INT8_C( 117), INT8_C( 103),
                        INT8_C( -74), INT8_C( -18), INT8_C(  28), INT8_C(  15), INT8_C(-111), INT8_C( -65), INT8_C( 117), INT8_C(  -8)),
      simde_mm_set_epi8(INT8_C(  42), INT8_C(  73), INT8_C(   1), INT8_C( -97), INT8_C( -45), INT8_C(  24), INT8_C(  88), INT8_C( -76),
                        INT8_C(-109), INT8_C(  78), INT8_C( -80), INT8_C( -97), INT8_C(  85), INT8_C( 102), INT8_C(  36), INT8_C( -19)),
      {    0, -116,  -92,  122,  -68,   23,  -43,   86,
         -50,  -28,  -43,   -3,   19, -114,  122,   62 },
      {   -8, -116,  -92,  122,   15,   28,  -43,  -74,
         103,  -28,  -43,   95,   92, -114,  122,   62 } },
    { simde_mm_set_epi8(INT8_C(  70), INT8_C( 102), INT8_C( -59), INT8_C(   6), INT8_C( -83), INT8_C(  40), INT8_C( -32), INT8_C(  43),
                        INT8_C(  90), INT8_C(-118), INT8_C(  82), INT8_C(  24), INT8_C(-106), INT8_C( -61), INT8_C( -19), INT8_C(-101)),
      simde_mm_set_epi8(INT8_C(  17), INT8_C( -58), INT8_C( -68), INT8_C(  86), INT8_C(  20), INT8_C(  40), INT8_C(  60), INT8_C(  30),
                        INT8_C(  31), INT8_C(  30), INT8_C(  18), INT8_C(  67), INT8_C(  -9), INT8_C( 103), INT8_C(  21), INT8_C( -50)),
      { -125,  126,  -10,  -60,   19,   92,   -8, -124,
          81, -122,  122,   13,  -58,   49, -122,   24 },
      { -101,  126,  -10, -106,   19,   92,   -8, -124,
          81, -122,  122,   13,  -58,  -59,  102,   24 } },
    { simde_mm_set_epi8(INT8_C( -26), INT8_C(-127), INT8_C(  58), INT8_C( -79), INT8_C( -88), INT8_C(-105), INT8_C( -66), INT8_C(  41),
                        INT8_C(  75), INT8_C( -34), INT8_C(  97), INT8_C( -55), INT8_C( -65), INT8_C( -30), INT8_C(  23), INT8_C(  28)),
      simde_mm_set_epi8(INT8_C(-107), INT8_C(  69), INT8_C( -28), INT8_C( -40), INT8_C( 105), INT8_C(   0), INT8_C( 114), INT8_C( 113),
                        INT8_C( -65), INT8_C( -82), INT8_C(  87), INT8_C( -14), INT8_C( -36), INT8_C(  68), INT8_C(-120), INT8_C(  38)),
      { -114,   55,  -16,   51,  110,  -44,   59,   -6,
          43,  -95,  -82,  119,  -56,    9,  -47,  -20 },
      { -114,   23,  -16,  -65,  -55,  -44,  -34,   75,
          43,  -95,  -82,  119,  -79,   58,  -47,  -26 } },
    { simde_mm_set_epi8(INT8_C(  87), INT8_C(  99), INT8_C(  22), INT8_C(  78), INT8_C(  93), INT8_C( -44), INT8_C( -98), INT8_C(  62),
                        INT8_C( -97), INT8_C( -50), INT8_C( -31), INT8_C(-109), INT8_C(  10), INT8_C( -86), INT8_C( -15), INT8_C(   7)),
      simde_mm_set_epi8(INT8_C(  96), INT8_C(  76), INT8_C(  14), INT8_C(-114), INT8_C(  84), INT8_C( -85), INT8_C(  61), INT8_C( -38),
                        INT8_C( -45), INT8_C( -83), INT8_C( -13), INT8_C( -50), INT8_C( -35), INT8_C(-111), INT8_C(-107), INT8_C( -50)),
      {   -8,   64,  -68,   23, -101,   35,  126,  119,
         -47,    4,   79,   23,  113,  117,  -76,   93 },
      {    7,  -15,  -86,   10, -109,  -31,  -50,  -97,
          62,    4,  -44,   23,   78,  117,  -76,   93 } },
    { simde_mm_set_epi8(INT8_C( -38), INT8_C(-119), INT8_C( -46), INT8_C( -13), INT8_C(  -3), INT8_C(-122), INT8_C(  75), INT8_C( 123),
                        INT8_C(  26), INT8_C( -71), INT8_C( -42), INT8_C(-124), INT8_C(  49), INT8_C(   1), INT8_C(   5), INT8_C( -90)),
      simde_mm_set_epi8(INT8_C( 116), INT8_C(  -8), INT8_C(  33), INT8_C(  63), INT8_C(-110), INT8_C( -94), INT8_C( -34), INT8_C(  66),
                        INT8_C(  51), INT8_C(-117), INT8_C(  28), INT8_C( -95), INT8_C( -52), INT8_C( 122), INT8_C( 118), INT8_C( -99)),
      {  -45,   85,   12,   62,  -89, -105,   90,  -19,
          48,   18,  -59,  -98,  -30, -113,   13,   91 },
      {  -90,   85,   12,   49, -124, -105,  -71,  -19,
          48,   75, -122,   -3,  -30, -113, -119,   91 } },
    { simde_mm_set_epi8(INT8_C(  52), INT8_C(  36), INT8_C( 112), INT8_C(  70), INT8_C( 110), INT8_C(  75), INT8_C(  -6), INT8_C(-101),
                        INT8_C(   3), INT8_C( 113), INT8_C( -32), INT8_C( 119), INT8_C( -19), INT8_C( 117), INT8_C(  31), INT8_C( 119)),
      simde_mm_set_epi8(INT8_C(  79), INT8_C(  39), INT8_C(   6), INT8_C(  30), INT8_C( 120), INT8_C( -75), INT8_C(  26), INT8_C(  57),
                        INT8_C( 123), INT8_C(  70), INT8_C(  40), INT8_C(  84), INT8_C( 111), INT8_C( -59), INT8_C( -79), INT8_C( -87)),
      {  -74,   -2, -124,   73,   44,   83,   18,  -48,
         -78,   27,   30,  -26,   -3,   56,   89,  125 },
      {  119,   31,  117,   73,   44,   83,   18,  -48,
         -78,   27,   75,  -26,   -3,   56,   89,  125 } },
    { simde_mm_set_epi8(INT8_C( -83), INT8_C( -42), INT8_C(-124), INT8_C( -81), INT8_C( -65), INT8_C(  46), INT8_C( -62), INT8_C( 102),
                        INT8_C(  50), INT8_C(   6), INT8_C(  -6), INT8_C( -21), INT8_C( -51), INT8_C(-114), INT8_C(-126), INT8_C(  74)),
      simde_mm_set_epi8(INT8_C( 127), INT8_C(-119), INT8_C( -85), INT8_C(  95), INT8_C(  70), INT8_C( -40), INT8_C(  17), INT8_C( 124),
                        INT8_C( -61), INT8_C(-126), INT8_C( 117), INT8_C( -42), INT8_C(  62), INT8_C(-111), INT8_C(-103), INT8_C(  57)),
      {  108,   40, -118,  -12,   90,  -12,  -24,   50,
         104,   87,  -20,  -86,  -53,   25,  -94, -101 },
      {  108, -126, -114,  -12,  -21,  -12,    6,   50,
         104,   87,   46,  -86,  -53, -124,  -42, -101 } },
    { simde_mm_set_epi8(INT8_C( -23), INT8_C( -92), INT8_C(  93), INT8_C( -78), INT8_C( -39), INT8_C( -72), INT8_C( -43), INT8_C(   1),
                        INT8_C(-121), INT8_C( 103), INT8_C(  61), INT8_C(  82), INT8_C(  45), INT8_C(-120), INT8_C( -86), INT8_C(  51)),
      simde_mm_set_epi8(INT8_C( -82), INT8_C(  92), INT8_C( -46), INT8_C( -97), INT8_C(  59), INT8_C( -16), INT8_C(  95), INT8_C( -85),
                        INT8_C(  38), INT8_C(  36), INT8_C(-125), INT8_C(  74), INT8_C(  14), INT8_C(  75), INT8_C( -74), INT8_C( -25)),
      {  -53,   48,   63,  -44, -103,   12,   49,   -1,
         -58,   70,  -18, -117,  101,  -90,  121,  -31 },
      {   51,  -86,   63,  -44, -103,   61,   49,   -1,
           1,   70,  -72, -117,  -78,   93,  121,  -23 } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    int8_t r[16];
    memcpy(r, test_vec[i].i, 16);
    simde_mm_maskmoveu_si128(test_vec[i].a, test_vec[i].mask, r);
    simde_assert_typev(int8_t, PRId8, 16, r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_min_epu8(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_x_mm_set_epu8(164, 110, 116,  95,  43, 222, 122,  21,
                           12,  65, 208, 248, 108, 166, 116,  17),
      simde_x_mm_set_epu8( 56,  62, 214,  11, 248, 124,  69,   2,
                          198, 169, 227, 124, 192, 250, 140,  32),
      simde_x_mm_set_epu8( 56,  62, 116,  11,  43, 124,  69,   2,
                           12,  65, 208, 124, 108, 166, 116,  17) },
    { simde_x_mm_set_epu8(136, 183, 233,  96,  11,  36, 213, 146,
                          238, 174,  59, 229,  56, 186, 203,  28),
      simde_x_mm_set_epu8( 82,  12,   9, 200, 196, 116, 127, 247,
                            1,  69, 178, 128,  65,  11, 179, 176),
      simde_x_mm_set_epu8( 82,  12,   9,  96,  11,  36, 127, 146,
                            1,  69,  59, 128,  56,  11, 179,  28) },
    { simde_x_mm_set_epu8(164,  64, 195, 253,  35,  95, 119, 110,
                          106, 102,  21, 173,  49,  40, 101, 151),
      simde_x_mm_set_epu8(109,  25,  32, 203,  64,  71,  33,  98,
                           48,  43, 195,  67, 254, 158, 167, 217),
      simde_x_mm_set_epu8(109,  25,  32, 203,  35,  71,  33,  98,
                           48,  43,  21,  67,  49,  40, 101, 151) },
    { simde_x_mm_set_epu8(233, 255, 136, 159, 118, 246,  37,   8,
                          195,  35,  70,   7,  91,  37,  20, 112),
      simde_x_mm_set_epu8(  4,  91, 243, 163, 160,  26, 137, 208,
                          146, 195, 124, 148,  53,  99,  21, 240),
      simde_x_mm_set_epu8(  4,  91, 136, 159, 118,  26,  37,   8,
                          146,  35,  70,   7,  53,  37,  20, 112) },
    { simde_x_mm_set_epu8(196,   4, 110, 234,  88, 121, 133, 146,
                          127, 167, 173, 105, 205,   0, 197, 107),
      simde_x_mm_set_epu8(240, 105, 248,  55, 202, 217, 219, 230,
                          183, 240,  91, 164, 168,   6,  75, 186),
      simde_x_mm_set_epu8(196,   4, 110,  55,  88, 121, 133, 146,
                          127, 167,  91, 105, 168,   0,  75, 107) },
    { simde_x_mm_set_epu8(191, 108, 145, 178, 194, 118, 187, 175,
                           80, 196,  99, 239,   6, 206, 186, 130),
      simde_x_mm_set_epu8(109, 182, 208,  91, 232, 171,  41, 238,
                          121, 144, 203,  42, 182,  89,  69, 166),
      simde_x_mm_set_epu8(109, 108, 145,  91, 194, 118,  41, 175,
                           80, 144,  99,  42,   6,  89,  69, 130) },
    { simde_x_mm_set_epu8(  5, 152, 184, 251, 233,  22, 184, 152,
                           12, 126, 120,  80, 191,  98,  37,  36),
      simde_x_mm_set_epu8(194, 116, 229, 250, 247, 241, 153, 192,
                           20, 172, 224, 148, 240, 246, 120,   0),
      simde_x_mm_set_epu8(  5, 116, 184, 250, 233,  22, 153, 152,
                           12, 126, 120,  80, 191,  98,  37,   0) },
    { simde_x_mm_set_epu8(188, 102, 137, 134, 213,   1, 140, 166,
                          143, 171, 248,  89, 128,  81, 226, 136),
      simde_x_mm_set_epu8(246, 210,  83, 107,  44, 255, 100, 235,
                           99, 233, 199, 197,   1, 159,  61,  31),
      simde_x_mm_set_epu8(188, 102,  83, 107,  44,   1, 100, 166,
                           99, 171, 199,  89,   1,  81,  61,  31) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_min_epu8(test_vec[i].a, test_vec[i].b);
    simde_assert_m128i_u8(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_min_epi16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi16(-23442,  29791,  11230,  31253,   3137, -12040,  27814,  29713),
      simde_mm_set_epi16( 14398, -10741,  -1924,  17666, -14679,  -7300, -16134, -29664),
      simde_mm_set_epi16(-23442, -10741,  -1924,  17666, -14679, -12040, -16134, -29664) },
    { simde_mm_set_epi16(-30537,  -5792,   2852, -10862,  -4434,  15333,  14522, -13540),
      simde_mm_set_epi16( 21004,   2504, -15244,  32759,    325, -19840,  16651, -19536),
      simde_mm_set_epi16(-30537,  -5792, -15244, -10862,  -4434, -19840,  14522, -19536) },
    { simde_mm_set_epi16(-23488, -15363,   9055,  30574,  27238,   5549,  12584,  26007),
      simde_mm_set_epi16( 27929,   8395,  16455,   8546,  12331, -15549,   -354, -22567),
      simde_mm_set_epi16(-23488, -15363,   9055,   8546,  12331, -15549,   -354, -22567) },
    { simde_mm_set_epi16( -5633, -30561,  30454,   9480, -15581,  17927,  23333,   5232),
      simde_mm_set_epi16(  1115,  -3165, -24550, -30256, -27965,  31892,  13667,   5616),
      simde_mm_set_epi16( -5633, -30561, -24550, -30256, -27965,  17927,  13667,   5232) },
    { simde_mm_set_epi16(-15356,  28394,  22649, -31342,  32679, -21143, -13056, -14997),
      simde_mm_set_epi16( -3991,  -1993, -13607,  -9242, -18448,  23460, -22522,  19386),
      simde_mm_set_epi16(-15356,  -1993, -13607, -31342, -18448, -21143, -22522, -14997) },
    { simde_mm_set_epi16(-16532, -28238, -15754, -17489,  20676,  25583,   1742, -17790),
      simde_mm_set_epi16( 28086, -12197,  -5973,  10734,  31120, -13526, -18855,  17830),
      simde_mm_set_epi16(-16532, -28238, -15754, -17489,  20676, -13526, -18855, -17790) },
    { simde_mm_set_epi16(  1432, -18181,  -5866, -18280,   3198,  30800, -16542,   9508),
      simde_mm_set_epi16(-15756,  -6662,  -2063, -26176,   5292,  -8044,  -3850,  30720),
      simde_mm_set_epi16(-15756, -18181,  -5866, -26176,   3198,  -8044, -16542,   9508) },
    { simde_mm_set_epi16(-17306, -30330, -11007, -29530, -28757,  -1959, -32687,  -7544),
      simde_mm_set_epi16( -2350,  21355,  11519,  25835,  25577, -14395,    415,  15647),
      simde_mm_set_epi16(-17306, -30330, -11007, -29530, -28757, -14395, -32687,  -7544) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_min_epi16(test_vec[i].a, test_vec[i].b);
    simde_assert_m128i_u16(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_min_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128d a;
    simde__m128d b;
    simde__m128d r;
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -927.67), SIMDE_FLOAT64_C( -514.32)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  342.71), SIMDE_FLOAT64_C(  927.58)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -927.67), SIMDE_FLOAT64_C( -514.32)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -704.64), SIMDE_FLOAT64_C(  925.40)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -589.60), SIMDE_FLOAT64_C( -498.63)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -704.64), SIMDE_FLOAT64_C( -498.63)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -244.39), SIMDE_FLOAT64_C(  572.76)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -10.04), SIMDE_FLOAT64_C(  293.99)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -244.39), SIMDE_FLOAT64_C(  293.99)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  321.70), SIMDE_FLOAT64_C( -283.39)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   60.35), SIMDE_FLOAT64_C( -248.75)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   60.35), SIMDE_FLOAT64_C( -283.39)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  -67.84), SIMDE_FLOAT64_C(  763.91)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  150.47), SIMDE_FLOAT64_C( -773.85)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -67.84), SIMDE_FLOAT64_C( -773.85)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  -42.86), SIMDE_FLOAT64_C(  169.28)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -820.89), SIMDE_FLOAT64_C(  325.20)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -820.89), SIMDE_FLOAT64_C(  169.28)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -976.90), SIMDE_FLOAT64_C(  883.11)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -450.39), SIMDE_FLOAT64_C( -249.21)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -976.90), SIMDE_FLOAT64_C( -249.21)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  495.76), SIMDE_FLOAT64_C(  415.93)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -979.87), SIMDE_FLOAT64_C( -567.72)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -979.87), SIMDE_FLOAT64_C( -567.72)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_min_pd(test_vec[i].a, test_vec[i].b);
    simde_assert_m128d_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_min_sd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128d a;
    simde__m128d b;
    simde__m128d r;
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -927.67), SIMDE_FLOAT64_C( -514.32)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  342.71), SIMDE_FLOAT64_C(  927.58)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -927.67), SIMDE_FLOAT64_C( -514.32)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -704.64), SIMDE_FLOAT64_C(  925.40)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -589.60), SIMDE_FLOAT64_C( -498.63)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -704.64), SIMDE_FLOAT64_C( -498.63)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -244.39), SIMDE_FLOAT64_C(  572.76)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -10.04), SIMDE_FLOAT64_C(  293.99)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -244.39), SIMDE_FLOAT64_C(  293.99)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  321.70), SIMDE_FLOAT64_C( -283.39)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   60.35), SIMDE_FLOAT64_C( -248.75)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  321.70), SIMDE_FLOAT64_C( -283.39)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  -67.84), SIMDE_FLOAT64_C(  763.91)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  150.47), SIMDE_FLOAT64_C( -773.85)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -67.84), SIMDE_FLOAT64_C( -773.85)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  -42.86), SIMDE_FLOAT64_C(  169.28)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -820.89), SIMDE_FLOAT64_C(  325.20)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -42.86), SIMDE_FLOAT64_C(  169.28)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -976.90), SIMDE_FLOAT64_C(  883.11)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -450.39), SIMDE_FLOAT64_C( -249.21)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -976.90), SIMDE_FLOAT64_C( -249.21)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  495.76), SIMDE_FLOAT64_C(  415.93)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -979.87), SIMDE_FLOAT64_C( -567.72)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  495.76), SIMDE_FLOAT64_C( -567.72)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_min_sd(test_vec[i].a, test_vec[i].b);
    simde_assert_m128d_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_max_epu8(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_x_mm_set_epu8(168, 216, 116,  83,  89,  36,  70,  43,
                          213,  80, 178, 134,  66, 113, 243, 129),
      simde_x_mm_set_epu8(121,  26,  77, 212,  58, 167,  83, 180,
                          236,  50,  65, 112, 248, 228,  87, 231),
      simde_x_mm_set_epu8(168, 216, 116, 212,  89, 167,  83, 180,
                          236,  80, 178, 134, 248, 228, 243, 231) },
    { simde_x_mm_set_epu8(157, 143, 244, 146,  49, 140, 145, 221,
                           80,  79, 154,  71,  49, 213, 105,  22),
      simde_x_mm_set_epu8( 81,  58, 115, 104,  26, 180,  63,  33,
                           16, 205,  98, 228, 235, 156, 147, 109),
      simde_x_mm_set_epu8(157, 143, 244, 146,  49, 180, 145, 221,
                           80, 205, 154, 228, 235, 213, 147, 109) },
    { simde_x_mm_set_epu8(120, 153, 102, 244, 149, 171, 101, 141,
                          231, 205, 156,  11, 214, 255,  28, 215),
      simde_x_mm_set_epu8( 89, 227, 119,  48, 219,  88,   0,  68,
                          146, 196, 199,  34, 143, 246, 184,  31),
      simde_x_mm_set_epu8(120, 227, 119, 244, 219, 171, 101, 141,
                          231, 205, 199,  34, 214, 255, 184, 215) },
    { simde_x_mm_set_epu8(201, 221,  39,  38, 119, 106,  89, 236,
                            8,  81, 136,  17,  62,  33, 200,  24),
      simde_x_mm_set_epu8( 76, 153, 167,  42, 171, 206,  46, 181,
                           37, 117,  72, 251, 153,  91, 107,  96),
      simde_x_mm_set_epu8(201, 221, 167,  42, 171, 206,  89, 236,
                           37, 117, 136, 251, 153,  91, 200,  96) },
    { simde_x_mm_set_epu8( 34,  94, 125,  66, 238, 110, 110,  27,
                           90, 179, 184, 250, 202,  62, 132,  68),
      simde_x_mm_set_epu8(135, 208,  31,  76,  51,   5,  50, 220,
                           43, 120,  10, 131, 247, 241, 134, 232),
      simde_x_mm_set_epu8(135, 208, 125,  76, 238, 110, 110, 220,
                           90, 179, 184, 250, 247, 241, 134, 232) },
    { simde_x_mm_set_epu8( 12, 112,  35,  12, 111,   1,  16, 229,
                          119, 199,  69,  96, 220, 123, 153, 230),
      simde_x_mm_set_epu8(147, 155,  56, 136, 236,  16,  93,  16,
                           43, 253, 136, 239, 147,  44, 146,   0),
      simde_x_mm_set_epu8(147, 155,  56, 136, 236,  16,  93, 229,
                          119, 253, 136, 239, 220, 123, 153, 230) },
    { simde_x_mm_set_epu8(138, 177,  86, 183, 144, 112,  42,  67,
                          100, 123, 214, 234,  34, 240,  19,  10),
      simde_x_mm_set_epu8( 81,  53, 255, 195, 169, 127, 131, 109,
                          181, 161, 246, 113,  87,  20, 157, 194),
      simde_x_mm_set_epu8(138, 177, 255, 195, 169, 127, 131, 109,
                          181, 161, 246, 234,  87, 240, 157, 194) },
    { simde_x_mm_set_epu8(  5,  26, 135,  12, 151, 226, 187,  12,
                          213, 244, 209, 245, 136,  13, 164, 249),
      simde_x_mm_set_epu8( 92,  57, 200, 208, 212, 214, 211, 217,
                           65, 228, 179,  64,  34, 236, 220, 208),
      simde_x_mm_set_epu8( 92,  57, 200, 208, 212, 226, 211, 217,
                          213, 244, 209, 245, 136, 236, 220, 249) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_max_epu8(test_vec[i].a, test_vec[i].b);
    simde_assert_m128i_u8(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_max_epi16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi16(-22312,  29779,  22820,  17963, -10928, -19834,  17009,  -3199),
      simde_mm_set_epi16( 31002,  19924,  15015,  21428,  -5070,  16752,  -1820,  22503),
      simde_mm_set_epi16( 31002,  29779,  22820,  21428,  -5070,  16752,  17009,  22503) },
    { simde_mm_set_epi16(-25201,  -2926,  12684, -28195,  20559, -26041,  12757,  26902),
      simde_mm_set_epi16( 20794,  29544,   6836,  16161,   4301,  25316,  -5220, -27795),
      simde_mm_set_epi16( 20794,  29544,  12684,  16161,  20559,  25316,  12757,  26902) },
    { simde_mm_set_epi16( 30873,  26356, -27221,  25997,  -6195, -25589, -10497,   7383),
      simde_mm_set_epi16( 23011,  30512,  -9384,     68, -27964, -14558, -28682, -18401),
      simde_mm_set_epi16( 30873,  30512,  -9384,  25997,  -6195, -14558, -10497,   7383) },
    { simde_mm_set_epi16(-13859,  10022,  30570,  23020,   2129, -30703,  15905, -14312),
      simde_mm_set_epi16( 19609, -22742, -21554,  11957,   9589,  18683, -26277,  27488),
      simde_mm_set_epi16( 19609,  10022,  30570,  23020,   9589,  18683,  15905,  27488) },
    { simde_mm_set_epi16(  8798,  32066,  -4498,  28187,  23219, -18182, -13762, -31676),
      simde_mm_set_epi16(-30768,   8012,  13061,  13020,  11128,   2691,  -2063, -31000),
      simde_mm_set_epi16(  8798,  32066,  13061,  28187,  23219,   2691,  -2063, -31000) },
    { simde_mm_set_epi16(  3184,   8972,  28417,   4325,  30663,  17760,  -9093, -26138),
      simde_mm_set_epi16(-27749,  14472,  -5104,  23824,  11261, -30481, -27860, -28160),
      simde_mm_set_epi16(  3184,  14472,  28417,  23824,  30663,  17760,  -9093, -26138) },
    { simde_mm_set_epi16(-30031,  22199, -28560,  10819,  25723, -10518,   8944,   4874),
      simde_mm_set_epi16( 20789,    -61, -22145, -31891, -19039,  -2447,  22292, -25150),
      simde_mm_set_epi16( 20789,  22199, -22145,  10819,  25723,  -2447,  22292,   4874) },
    { simde_mm_set_epi16(  1306, -30964, -26654, -17652, -10764, -11787, -30707, -23303),
      simde_mm_set_epi16( 23609, -14128, -11050, -11303,  16868, -19648,   8940,  -9008),
      simde_mm_set_epi16( 23609, -14128, -11050, -11303,  16868, -11787,   8940,  -9008) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_max_epi16(test_vec[i].a, test_vec[i].b);
    simde_assert_m128i_i16(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_max_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128d a;
    simde__m128d b;
    simde__m128d r;
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -303.58), SIMDE_FLOAT64_C( -480.90)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  319.11), SIMDE_FLOAT64_C(  666.53)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  319.11), SIMDE_FLOAT64_C(  666.53)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -541.77), SIMDE_FLOAT64_C(  944.47)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -53.88), SIMDE_FLOAT64_C(  845.28)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -53.88), SIMDE_FLOAT64_C(  944.47)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -612.90), SIMDE_FLOAT64_C( -610.67)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  230.96), SIMDE_FLOAT64_C( -372.57)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  230.96), SIMDE_FLOAT64_C( -372.57)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -791.37), SIMDE_FLOAT64_C(  840.72)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -365.40), SIMDE_FLOAT64_C( -868.73)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -365.40), SIMDE_FLOAT64_C(  840.72)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  169.29), SIMDE_FLOAT64_C(  679.66)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -57.82), SIMDE_FLOAT64_C(  810.96)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  169.29), SIMDE_FLOAT64_C(  810.96)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  713.62), SIMDE_FLOAT64_C(  124.72)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -297.75), SIMDE_FLOAT64_C(  146.63)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  713.62), SIMDE_FLOAT64_C(  146.63)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  -67.07), SIMDE_FLOAT64_C( -514.59)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  577.06), SIMDE_FLOAT64_C( -935.01)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  577.06), SIMDE_FLOAT64_C( -514.59)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  342.23), SIMDE_FLOAT64_C(  198.10)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -401.56), SIMDE_FLOAT64_C( -707.36)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  342.23), SIMDE_FLOAT64_C(  198.10)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_max_pd(test_vec[i].a, test_vec[i].b);
    simde_assert_m128d_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_max_sd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128d a;
    simde__m128d b;
    simde__m128d r;
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -303.58), SIMDE_FLOAT64_C( -480.90)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  319.11), SIMDE_FLOAT64_C(  666.53)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -303.58), SIMDE_FLOAT64_C(  666.53)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -541.77), SIMDE_FLOAT64_C(  944.47)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -53.88), SIMDE_FLOAT64_C(  845.28)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -541.77), SIMDE_FLOAT64_C(  944.47)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -612.90), SIMDE_FLOAT64_C( -610.67)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  230.96), SIMDE_FLOAT64_C( -372.57)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -612.90), SIMDE_FLOAT64_C( -372.57)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -791.37), SIMDE_FLOAT64_C(  840.72)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -365.40), SIMDE_FLOAT64_C( -868.73)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -791.37), SIMDE_FLOAT64_C(  840.72)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  169.29), SIMDE_FLOAT64_C(  679.66)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -57.82), SIMDE_FLOAT64_C(  810.96)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  169.29), SIMDE_FLOAT64_C(  810.96)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  713.62), SIMDE_FLOAT64_C(  124.72)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -297.75), SIMDE_FLOAT64_C(  146.63)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  713.62), SIMDE_FLOAT64_C(  146.63)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  -67.07), SIMDE_FLOAT64_C( -514.59)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  577.06), SIMDE_FLOAT64_C( -935.01)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -67.07), SIMDE_FLOAT64_C( -514.59)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  342.23), SIMDE_FLOAT64_C(  198.10)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -401.56), SIMDE_FLOAT64_C( -707.36)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  342.23), SIMDE_FLOAT64_C(  198.10)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_max_sd(test_vec[i].a, test_vec[i].b);
    simde_assert_m128d_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_move_epi64(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi64x(INT64_C(-2982745844705455901), INT64_C( 4775804171231816037)),
      simde_mm_set_epi64x(INT64_C(                   0), INT64_C( 4775804171231816037)) },
    { simde_mm_set_epi64x(INT64_C( 5762346410957661033), INT64_C( 2977172799723381810)),
      simde_mm_set_epi64x(INT64_C(                   0), INT64_C( 2977172799723381810)) },
    { simde_mm_set_epi64x(INT64_C( 1008079402021318109), INT64_C( 2502061726771043310)),
      simde_mm_set_epi64x(INT64_C(                   0), INT64_C( 2502061726771043310)) },
    { simde_mm_set_epi64x(INT64_C( 5339677830223010942), INT64_C( 8124798084034539527)),
      simde_mm_set_epi64x(INT64_C(                   0), INT64_C( 8124798084034539527)) },
    { simde_mm_set_epi64x(INT64_C(-4521066662096167363), INT64_C( -947809468227977762)),
      simde_mm_set_epi64x(INT64_C(                   0), INT64_C( -947809468227977762)) },
    { simde_mm_set_epi64x(INT64_C(-1218747510360922612), INT64_C( 3122441631876631480)),
      simde_mm_set_epi64x(INT64_C(                   0), INT64_C( 3122441631876631480)) },
    { simde_mm_set_epi64x(INT64_C(-3523922424397514946), INT64_C( -108841976580709576)),
      simde_mm_set_epi64x(INT64_C(                   0), INT64_C( -108841976580709576)) },
    { simde_mm_set_epi64x(INT64_C(-3961221708434347271), INT64_C(-1875395594913971276)),
      simde_mm_set_epi64x(INT64_C(                   0), INT64_C(-1875395594913971276)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_move_epi64(test_vec[i].a);
    simde_assert_m128i_i64(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_move_sd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128d a;
    simde__m128d b;
    simde__m128d r;
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  570.81), SIMDE_FLOAT64_C( -941.79)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -875.32), SIMDE_FLOAT64_C( -356.30)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  570.81), SIMDE_FLOAT64_C( -356.30)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -816.08), SIMDE_FLOAT64_C(  126.72)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -886.56), SIMDE_FLOAT64_C(  985.06)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -816.08), SIMDE_FLOAT64_C(  985.06)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  358.01), SIMDE_FLOAT64_C(   59.13)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -61.40), SIMDE_FLOAT64_C( -717.39)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  358.01), SIMDE_FLOAT64_C( -717.39)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  110.04), SIMDE_FLOAT64_C(  -44.09)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -614.96), SIMDE_FLOAT64_C( -267.93)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  110.04), SIMDE_FLOAT64_C( -267.93)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  571.79), SIMDE_FLOAT64_C( -816.23)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  917.45), SIMDE_FLOAT64_C(  287.41)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  571.79), SIMDE_FLOAT64_C(  287.41)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  827.50), SIMDE_FLOAT64_C(  261.09)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  478.77), SIMDE_FLOAT64_C(   33.99)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  827.50), SIMDE_FLOAT64_C(   33.99)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -335.82), SIMDE_FLOAT64_C(  465.36)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -993.24), SIMDE_FLOAT64_C(  100.89)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -335.82), SIMDE_FLOAT64_C(  100.89)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  415.58), SIMDE_FLOAT64_C( -984.83)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  764.57), SIMDE_FLOAT64_C(  672.72)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  415.58), SIMDE_FLOAT64_C(  672.72)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_move_sd(test_vec[i].a, test_vec[i].b);
    simde_assert_m128d_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_movemask_epi8(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    int32_t r;
  } test_vec[] = {
    { simde_mm_set_epi8(INT8_C(-125), INT8_C( -40), INT8_C(  -7), INT8_C( -71),
                        INT8_C( -75), INT8_C(  99), INT8_C( 101), INT8_C(  -5),
                        INT8_C( -71), INT8_C( -91), INT8_C( -60), INT8_C(   9),
                        INT8_C( -27), INT8_C( -81), INT8_C(   5), INT8_C(  97)),
      INT32_C(63980) },
    { simde_mm_set_epi8(INT8_C(  44), INT8_C( -98), INT8_C(  82), INT8_C(-127),
                        INT8_C( -28), INT8_C( 122), INT8_C( -22), INT8_C(  46),
                        INT8_C( -41), INT8_C( -35), INT8_C(  15), INT8_C(  43),
                        INT8_C( -37), INT8_C( -12), INT8_C(  17), INT8_C( -17)),
      INT32_C(23245) },
    { simde_mm_set_epi8(INT8_C( -53), INT8_C( -99), INT8_C(  91), INT8_C( -56),
                        INT8_C(  10), INT8_C( 114), INT8_C(-120), INT8_C(  67),
                        INT8_C( -82), INT8_C(  13), INT8_C( 104), INT8_C(   1),
                        INT8_C(  15), INT8_C(-115), INT8_C(  16), INT8_C(  33)),
      INT32_C(53892) },
    { simde_mm_set_epi8(INT8_C( 109), INT8_C(  -5), INT8_C( -45), INT8_C(  60),
                        INT8_C( -20), INT8_C(  -7), INT8_C( -24), INT8_C(  63),
                        INT8_C(  61), INT8_C( -94), INT8_C(-110), INT8_C(  16),
                        INT8_C( 117), INT8_C( -23), INT8_C( -49), INT8_C( -74)),
      INT32_C(28263) },
    { simde_mm_set_epi8(INT8_C( -88), INT8_C( 110), INT8_C(-108), INT8_C( -88),
                        INT8_C(  28), INT8_C( 110), INT8_C(   0), INT8_C( -12),
                        INT8_C( -90), INT8_C(  44), INT8_C( -42), INT8_C( -87),
                        INT8_C( -48), INT8_C( -87), INT8_C( -21), INT8_C( -64)),
      INT32_C(45503) },
    { simde_mm_set_epi8(INT8_C( 121), INT8_C(-111), INT8_C(  -1), INT8_C( -61),
                        INT8_C(  67), INT8_C(  90), INT8_C(  10), INT8_C(  65),
                        INT8_C(  36), INT8_C( -60), INT8_C(  93), INT8_C(  -3),
                        INT8_C(-112), INT8_C(  -8), INT8_C(  55), INT8_C( -49)),
      INT32_C(28765) },
    { simde_mm_set_epi8(INT8_C(  92), INT8_C( -27), INT8_C(  37), INT8_C( -87),
                        INT8_C(  58), INT8_C( 108), INT8_C( -50), INT8_C( -10),
                        INT8_C(   5), INT8_C(  21), INT8_C(  14), INT8_C(  72),
                        INT8_C( -76), INT8_C(  21), INT8_C(-104), INT8_C( 110)),
      INT32_C(21258) },
    { simde_mm_set_epi8(INT8_C( -60), INT8_C(  23), INT8_C( -54), INT8_C(  54),
                        INT8_C(  31), INT8_C(  13), INT8_C( -93), INT8_C(  18),
                        INT8_C( -62), INT8_C(-128), INT8_C(  70), INT8_C(  59),
                        INT8_C(  17), INT8_C(  49), INT8_C(  95), INT8_C( -96)),
      INT32_C(41665) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    int32_t r = simde_mm_movemask_epi8(test_vec[i].a);
    munit_assert_int32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_movemask_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128d a;
    int32_t r;
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -532.45), SIMDE_FLOAT64_C(  863.01)),
      INT32_C(2) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -749.24), SIMDE_FLOAT64_C( -869.97)),
      INT32_C(3) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  994.23), SIMDE_FLOAT64_C(  351.47)),
      INT32_C(0) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  413.53), SIMDE_FLOAT64_C( -655.32)),
      INT32_C(1) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -253.74), SIMDE_FLOAT64_C(   -2.37)),
      INT32_C(3) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  696.22), SIMDE_FLOAT64_C( -699.75)),
      INT32_C(1) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(   55.24), SIMDE_FLOAT64_C( -722.45)),
      INT32_C(1) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -592.60), SIMDE_FLOAT64_C(  141.10)),
      INT32_C(2) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    int32_t r = simde_mm_movemask_pd(test_vec[i].a);
    munit_assert_int32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_movepi64_pi64(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m64 r;
  } test_vec[8] = {
    { simde_mm_set_epi64x(INT64_C(-3369091548753669372), INT64_C(-3862634862308997761)),
      simde_x_mm_set_pi64(INT64_C(-3862634862308997761)) },
    { simde_mm_set_epi64x(INT64_C( 1195923961730132400), INT64_C(-4203048506958717476)),
      simde_x_mm_set_pi64(INT64_C(-4203048506958717476)) },
    { simde_mm_set_epi64x(INT64_C( 4316262850566382732), INT64_C(  743544812785944809)),
      simde_x_mm_set_pi64(INT64_C(743544812785944809)) },
    { simde_mm_set_epi64x(INT64_C( 9153964415619232912), INT64_C( 7102186508934354546)),
      simde_x_mm_set_pi64(INT64_C(7102186508934354546)) },
    { simde_mm_set_epi64x(INT64_C( -149536427124813706), INT64_C(-2645616526676309339)),
      simde_x_mm_set_pi64(INT64_C(-2645616526676309339)) },
    { simde_mm_set_epi64x(INT64_C( 7660292028637459230), INT64_C(-4472173852492382560)),
      simde_x_mm_set_pi64(INT64_C(-4472173852492382560)) },
    { simde_mm_set_epi64x(INT64_C( 2373412759770157312), INT64_C( -249935199655019513)),
      simde_x_mm_set_pi64(INT64_C(-249935199655019513)) },
    { simde_mm_set_epi64x(INT64_C(-2495482311671930573), INT64_C( 7782795372632782061)),
      simde_x_mm_set_pi64(INT64_C(7782795372632782061)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m64 r = simde_mm_movepi64_pi64(test_vec[i].a);
    simde_assert_m64_i64(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_movpi64_epi64(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m64 a;
    simde__m128i r;
  } test_vec[8] = {
   { simde_x_mm_set_pi64(INT64_C(8307669974137432024)),
      simde_mm_set_epi64x(INT64_C(                   0), INT64_C( 8307669974137432024)) },
    { simde_x_mm_set_pi64(INT64_C(-6174863101947913477)),
      simde_mm_set_epi64x(INT64_C(                   0), INT64_C(-6174863101947913477)) },
    { simde_x_mm_set_pi64(INT64_C(-3709498539865079997)),
      simde_mm_set_epi64x(INT64_C(                   0), INT64_C(-3709498539865079997)) },
    { simde_x_mm_set_pi64(INT64_C(-5655514474221449119)),
      simde_mm_set_epi64x(INT64_C(                   0), INT64_C(-5655514474221449119)) },
    { simde_x_mm_set_pi64(INT64_C(-4407711847161442183)),
      simde_mm_set_epi64x(INT64_C(                   0), INT64_C(-4407711847161442183)) },
    { simde_x_mm_set_pi64(INT64_C(-7730135383563833284)),
      simde_mm_set_epi64x(INT64_C(                   0), INT64_C(-7730135383563833284)) },
    { simde_x_mm_set_pi64(INT64_C(1417829150564629578)),
      simde_mm_set_epi64x(INT64_C(                   0), INT64_C( 1417829150564629578)) },
    { simde_x_mm_set_pi64(INT64_C(5667864625160412978)),
      simde_mm_set_epi64x(INT64_C(                   0), INT64_C( 5667864625160412978)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_movpi64_epi64(test_vec[i].a);
    simde_assert_m128i_i64(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_mul_epu32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_x_mm_set_epu32 (1251634950, 3010014325, 3844926313,  887004237),
      simde_x_mm_set_epu32 ( 771412494,  328239887, 3360452571,  298292680),
      simde_x_mm_set_epu64x(UINT64_C(  988006761906381275), UINT64_C(  264586871026085160)) },
    { simde_x_mm_set_epu32 (4076207020,  368393187, 3498508084,  981141316),
      simde_x_mm_set_epu32 (  81654802,  140153335, 2110173535, 3134478151),
      simde_x_mm_set_epu64x(UINT64_C(   51631533749328645), UINT64_C( 3075366018045386716)) },
    { simde_x_mm_set_epu32 (4261415154,  846454649,  108194122, 4167432393),
      simde_x_mm_set_epu32 (2698880481, 1287129030, 2616406220, 1248265871),
      simde_x_mm_set_epu64x(UINT64_C( 1089496351306360470), UINT64_C( 5202063625881759303)) },
    { simde_x_mm_set_epu32 ( 911193301, 1110766386, 3009613617, 1645784878),
      simde_x_mm_set_epu32 (3094480659, 3697181600, 4236850839, 2133678416),
      simde_x_mm_set_epu64x(UINT64_C( 4106705044217697600), UINT64_C( 3511575671567793248)) },
    { simde_x_mm_set_epu32 (2154112155, 2960710803, 2851801912,  678710951),
      simde_x_mm_set_epu32 (4001207654, 4056994829, 1341523746,  568161818),
      simde_x_mm_set_epu64x(UINT64_C(12011588417935437687), UINT64_C(  385617647816668918)) },
    { simde_x_mm_set_epu32 (3273494172, 3612698350, 4103906203, 1678207566),
      simde_x_mm_set_epu32 (  48120942,  160747207, 2820564214, 1404181744),
      simde_x_mm_set_epu64x(UINT64_C(  580731169496008450), UINT64_C( 2356508426819875104)) },
    { simde_x_mm_set_epu32 ( 396392525, 2486526122, 1177281917, 3038155803),
      simde_x_mm_set_epu32 ( 760783698, 1253190575, 4064848310, 1630883223),
      simde_x_mm_set_epu64x(UINT64_C( 3116091100581700150), UINT64_C( 4954877327972793069)) },
    { simde_x_mm_set_epu32 (1438827395, 1294325524, 3245229436,  122146781),
      simde_x_mm_set_epu32 (1030238038, 4273209339,  197838277, 1151380764),
      simde_x_mm_set_epu64x(UINT64_C( 5530923916862868636), UINT64_C(  140637454027920684)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_mul_epu32(test_vec[i].a, test_vec[i].b);
    simde_assert_m128i_u64(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_mul_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128d a;
    simde__m128d b;
    simde__m128d r;
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C(    602.19), SIMDE_FLOAT64_C(   -103.53)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   -952.79), SIMDE_FLOAT64_C(   -150.84)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(-573760.61), SIMDE_FLOAT64_C(  15616.47)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(   -140.84), SIMDE_FLOAT64_C(   -241.95)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    540.86), SIMDE_FLOAT64_C(   -754.39)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -76174.72), SIMDE_FLOAT64_C( 182524.66)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(   -648.21), SIMDE_FLOAT64_C(   -612.11)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   -327.08), SIMDE_FLOAT64_C(   -865.34)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( 212016.53), SIMDE_FLOAT64_C( 529683.27)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(    518.61), SIMDE_FLOAT64_C(   -573.43)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   -650.79), SIMDE_FLOAT64_C(    196.03)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(-337506.20), SIMDE_FLOAT64_C(-112409.48)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(   -750.40), SIMDE_FLOAT64_C(    324.63)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    343.74), SIMDE_FLOAT64_C(     -4.14)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(-257942.50), SIMDE_FLOAT64_C(  -1343.97)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(    -48.73), SIMDE_FLOAT64_C(    769.19)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    268.16), SIMDE_FLOAT64_C(   -953.46)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -13067.44), SIMDE_FLOAT64_C(-733391.90)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(    188.02), SIMDE_FLOAT64_C(    614.87)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    396.91), SIMDE_FLOAT64_C(   -399.68)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  74627.02), SIMDE_FLOAT64_C(-245751.24)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(    813.52), SIMDE_FLOAT64_C(    480.96)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    664.31), SIMDE_FLOAT64_C(    447.07)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( 540429.47), SIMDE_FLOAT64_C( 215022.79)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_mul_pd(test_vec[i].a, test_vec[i].b);
    simde_assert_m128d_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_mul_sd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128d a;
    simde__m128d b;
    simde__m128d r;
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C(    815.66), SIMDE_FLOAT64_C(    839.23)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    748.66), SIMDE_FLOAT64_C(    -52.12)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    815.66), SIMDE_FLOAT64_C( -43740.67)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(   -714.36), SIMDE_FLOAT64_C(   -808.00)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    401.75), SIMDE_FLOAT64_C(    319.13)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   -714.36), SIMDE_FLOAT64_C(-257857.04)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(    453.36), SIMDE_FLOAT64_C(   -764.44)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   -934.41), SIMDE_FLOAT64_C(   -454.88)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    453.36), SIMDE_FLOAT64_C( 347728.47)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(    489.60), SIMDE_FLOAT64_C(    724.31)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   -101.25), SIMDE_FLOAT64_C(    196.93)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    489.60), SIMDE_FLOAT64_C( 142638.37)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(    187.03), SIMDE_FLOAT64_C(    665.07)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    487.15), SIMDE_FLOAT64_C(    851.16)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    187.03), SIMDE_FLOAT64_C( 566080.98)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(    589.48), SIMDE_FLOAT64_C(    648.27)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   -683.48), SIMDE_FLOAT64_C(    -59.67)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    589.48), SIMDE_FLOAT64_C( -38682.27)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(    838.61), SIMDE_FLOAT64_C(    822.18)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   -364.43), SIMDE_FLOAT64_C(    962.26)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    838.61), SIMDE_FLOAT64_C( 791150.93)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(    530.83), SIMDE_FLOAT64_C(    379.76)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(     27.92), SIMDE_FLOAT64_C(    -56.09)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    530.83), SIMDE_FLOAT64_C( -21300.74)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_mul_sd(test_vec[i].a, test_vec[i].b);
    simde_assert_m128d_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_mul_su32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m64 a;
    simde__m64 b;
    simde__m64 r;
  } test_vec[8] = {
    { simde_x_mm_set_pu32(2885180946,  844141489),
      simde_x_mm_set_pu32(4148185385, 2032441685),
      simde_x_mm_set_pu32( 399460166, 1256837829) },
    { simde_x_mm_set_pu32(2917915813, 1026492335),
      simde_x_mm_set_pu32(2398310293, 1547581003),
      simde_x_mm_set_pu32( 369870112, 2563254853) },
    { simde_x_mm_set_pu32(1196710263,   16457138),
      simde_x_mm_set_pu32( 498148298, 2315637948),
      simde_x_mm_set_pu32(   8872890,  897267384) },
    { simde_x_mm_set_pu32(2000266929, 2697502765),
      simde_x_mm_set_pu32( 424873771, 2340971717),
      simde_x_mm_set_pu32(1470273751, 2682050209) },
    { simde_x_mm_set_pu32(2959249192, 1383399844),
      simde_x_mm_set_pu32(2822147566, 1013328039),
      simde_x_mm_set_pu32( 326390809,  703443452) },
    { simde_x_mm_set_pu32( 140695271, 1900694124),
      simde_x_mm_set_pu32(2599132138,   64207643),
      simde_x_mm_set_pu32(  28414439, 3526802788) },
    { simde_x_mm_set_pu32(3691531686, 4170021601),
      simde_x_mm_set_pu32(1397113221, 2055875512),
      simde_x_mm_set_pu32(1996067653, 3768458424) },
    { simde_x_mm_set_pu32(1077797086, 3961727000),
      simde_x_mm_set_pu32(2718729587, 1683130919),
      simde_x_mm_set_pu32(1552539227,  614992808) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m64 r = simde_mm_mul_su32(test_vec[i].a, test_vec[i].b);
    simde_assert_m64_u32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_mulhi_epi16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi16(-28198, -30713,  20992, -15285,  16558, -12771, -10872, -32584),
      simde_mm_set_epi16( -2396, -16729,  31162, -10205,  24928,   5223,   7262,  25352),
      simde_mm_set_epi16(  1030,   7839,   9981,   2380,   6298,  -1018,  -1205, -12605) },
    { simde_mm_set_epi16(-29475,  -4667,  18782, -15431, -27740,  28051,   4978,   1222),
      simde_mm_set_epi16(-10541, -14468,  18685,  12375,  -5884, -11112,  23337,  12576),
      simde_mm_set_epi16(  4740,   1030,   5354,  -2914,   2490,  -4757,   1772,    234) },
    { simde_mm_set_epi16( 27783,   6960,  17513,  -7755,  14695,  12404,  -4129, -25366),
      simde_mm_set_epi16( 29475,  25763,  29366,  12820,  -5355,   7751, -24426,  -6617),
      simde_mm_set_epi16( 12495,   2736,   7847,  -1518,  -1201,   1467,   1538,   2561) },
    { simde_mm_set_epi16(  8852,  11654,  12030,  21843,  27012,  24122,  -4121,  19864),
      simde_mm_set_epi16(-24799, -30738,  19688, -21919,  23874,  -4632, -21648, -28317),
      simde_mm_set_epi16( -3350,  -5467,   3613,  -7306,   9840,  -1705,   1361,  -8583) },
    { simde_mm_set_epi16(  2959, -18532,   4909,  17932,   9150,  13660, -28547,   5006),
      simde_mm_set_epi16( 16706, -30015, -32638,  13608,  -7846,  14914, -15409, -27711),
      simde_mm_set_epi16(   754,   8487,  -2445,   3723,  -1096,   3108,   6712,  -2117) },
    { simde_mm_set_epi16( 23854, -13644, -14015, -13375, -26086,  -6430,  -5411,   7716),
      simde_mm_set_epi16( -3281, -16733, -20310,    760, -18586,   1673, -25298, -31758),
      simde_mm_set_epi16( -1195,   3483,   4343,   -156,   7397,   -165,   2088,  -3740) },
    { simde_mm_set_epi16(  5449,     38,   6018,  10627,  20505,  28284,   4633, -26325),
      simde_mm_set_epi16( 24784,  11314,   7455,  17813,  -6570, -17283,  30512,   2646),
      simde_mm_set_epi16(  2060,      6,    684,   2888,  -2056,  -7459,   2157,  -1063) },
    { simde_mm_set_epi16(-21624,   5121,  20041,  13722, -24360, -19124, -16069,  19357),
      simde_mm_set_epi16( -7842,  31372, -32681,  23520,  -3879,  -7485,  22256,  12396),
      simde_mm_set_epi16(  2587,   2451,  -9994,   4924,   1441,   2184,  -5458,   3661) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_mulhi_epi16(test_vec[i].a, test_vec[i].b);
    simde_assert_m128i_i16(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_mulhi_epu16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_x_mm_set_epu16(35566, 15689, 63042, 57362, 59041, 31224, 19546, 12829),
      simde_x_mm_set_epu16(51447, 14621, 39095, 25022,  7138, 40387, 23161, 61024),
      simde_x_mm_set_epu16(27919,  3500, 37607, 21901,  6430, 19241,  6907, 11945) },
    { simde_x_mm_set_epu16(38922,  8893,  7997, 20067, 60307, 12929, 44791, 36818),
      simde_x_mm_set_epu16(56115, 46352, 39645, 27986, 64864, 64084,  5079, 17389),
      simde_x_mm_set_epu16(33326,  6289,  4837,  8569, 59688, 12642,  3471,  9769) },
    { simde_x_mm_set_epu16(15336, 63669, 63771, 21657, 12681, 61746,  3959, 20213),
      simde_x_mm_set_epu16(61649,  7462, 20857, 18418, 43120, 17135, 41045, 26167),
      simde_x_mm_set_epu16(14426,  7249, 20295,  6086,  8343, 16144,  2479,  8070) },
    { simde_x_mm_set_epu16(18737, 50787, 58977, 18610,  8077,  2942, 26014, 51355),
      simde_x_mm_set_epu16( 1776,  1953, 55756, 22299, 19400, 25284, 34496, 57058),
      simde_x_mm_set_epu16(  507,  1513, 50175,  6332,  2390,  1135, 13692, 44711) },
    { simde_x_mm_set_epu16(10154, 39850, 18306, 55081, 15606, 51707, 30878, 20967),
      simde_x_mm_set_epu16(43083, 50945, 49120, 63736, 15921, 64165, 33035, 50764),
      simde_x_mm_set_epu16( 6675, 30977, 13720, 53568,  3791, 50625, 15564, 16240) },
    { simde_x_mm_set_epu16(12757,  5042, 57712, 50374, 33497, 44643,  9249, 27444),
      simde_x_mm_set_epu16( 5516, 28001, 37996, 50447,  2209, 25118, 63921,  7578),
      simde_x_mm_set_epu16( 1073,  2154, 33459, 38775,  1129, 17110,  9021,  3173) },
    { simde_x_mm_set_epu16( 6520, 35794, 15094, 63136, 22779, 57672,  2423,  7676),
      simde_x_mm_set_epu16(20640, 11808, 58236, 53501, 38005, 59820,  7041, 59845),
      simde_x_mm_set_epu16( 2053,  6449, 13412, 51541, 13209, 52641,   260,  7009) },
    { simde_x_mm_set_epu16(60138,  6017, 21659, 30716, 29807, 17606, 41408, 64807),
      simde_x_mm_set_epu16(25712,  8473, 49119, 61515, 61789, 54600, 37356, 34280),
      simde_x_mm_set_epu16(23594,   777, 16233, 28831, 28102, 14668, 23602, 33898) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_mulhi_epu16(test_vec[i].a, test_vec[i].b);
    simde_assert_m128i_u16(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_mullo_epi16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi16( -7862,  26852,  10752,  -9273,  -9160,  -7080, -16165,  -8327),
      simde_mm_set_epi16(-20410,  24193, -22278,   -948, -31925,  -8469,   5801,  10383),
      simde_mm_set_epi16( 31292, -27932,   1024,   8980,  11368,  -4920,   8851, -17257) },
    { simde_mm_set_epi16( 10435,  19268,  27420,   9542, -22355,  22255, -32016,  23304),
      simde_mm_set_epi16( -3883,  14714, -16367,   4175,  13386,  20048, -30329, -26826),
      simde_mm_set_epi16(-17857,    616,   7388,  -8038,  -6654,   -848,  31888,  -5200) },
    { simde_mm_set_epi16( 16747, -31494,  -6008,    256,  13584,  -2628,  32210, -21204),
      simde_mm_set_epi16(  5844, -28058,  -1961,  -4057, -28767, -15421, -28399,   6019),
      simde_mm_set_epi16( 24220, -28772, -14792,   9984,  20240,  25140,  19698, -28284) },
    { simde_mm_set_epi16( -6420,  -8597,  -3796,  23244, -31410,   -804,  31623,   -736),
      simde_mm_set_epi16( -5973,  -2870,  -5873,  -1641,  -1760,  10653, -28567,  14335),
      simde_mm_set_epi16(  8100,  31854,  11668,  -1452, -30784,  20204, -26017,    736) },
    { simde_mm_set_epi16(-30942,  23208,   -332, -26357,  -4575,  25713, -11436, -20469),
      simde_mm_set_epi16( 10752,  -6855, -32031,  11523,    341,  13013,  12462, -19043),
      simde_mm_set_epi16(-27648,  30568,  17460, -17887,  12789, -23547,  25368, -16961) },
    { simde_mm_set_epi16( -9419, -28719,  16604,  20761,   7656,  31821,  14202, -12774),
      simde_mm_set_epi16(-24440,  -4751, -13213,  10351,  25105,  -3784,   2889,  15532),
      simde_mm_set_epi16(-27608,  -1983,  25876,   4567, -13208, -21032,   4042, -28296) },
    { simde_mm_set_epi16( 24274,  31467,  17654, -30184,  -7163,  32482,  19535, -21227),
      simde_mm_set_epi16( 18405, -30234,   7564, -18060,  16638, -17950,   -411, -23904),
      simde_mm_set_epi16(  4058,  12834, -27512,  -5408,  31990,  21892,  32043,  30496) },
    { simde_mm_set_epi16(-10768, -21062,  22181,  31606,  16135, -14823, -19116, -13035),
      simde_mm_set_epi16( 25288, -13107, -24173, -10010, -10251,   9523,  29977, -13646),
      simde_mm_set_epi16(   896,  22002, -31297,  31748,  12979,   5115,   6452,  10906) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_mullo_epi16(test_vec[i].a, test_vec[i].b);
    simde_assert_m128i_i16(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_or_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128d a;
    simde__m128d b;
    simde__m128d r;
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C(    724.92), SIMDE_FLOAT64_C(    616.22)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    797.85), SIMDE_FLOAT64_C(    484.18)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    989.98), SIMDE_FLOAT64_C( 128062.24)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(    482.51), SIMDE_FLOAT64_C(    841.87)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   -558.83), SIMDE_FLOAT64_C(    997.07)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(-129002.75), SIMDE_FLOAT64_C(   1005.87)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(    741.60), SIMDE_FLOAT64_C(   -412.08)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   -337.67), SIMDE_FLOAT64_C(   -516.98)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -95215.80), SIMDE_FLOAT64_C(-106109.48)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(    724.85), SIMDE_FLOAT64_C(   -403.04)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   -503.03), SIMDE_FLOAT64_C(   -699.51)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(-130927.93), SIMDE_FLOAT64_C(-122827.50)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(    231.42), SIMDE_FLOAT64_C(    688.03)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   -373.50), SIMDE_FLOAT64_C(    983.44)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   -511.84), SIMDE_FLOAT64_C(   1015.47)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(    625.94), SIMDE_FLOAT64_C(   -703.47)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   -942.06), SIMDE_FLOAT64_C(    249.38)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -1024.00), SIMDE_FLOAT64_C( -65535.34)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(    -97.92), SIMDE_FLOAT64_C(    -70.84)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   -510.77), SIMDE_FLOAT64_C(   -381.02)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   -511.93), SIMDE_FLOAT64_C(   -383.36)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(   -350.87), SIMDE_FLOAT64_C(   -439.10)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(     66.40), SIMDE_FLOAT64_C(    195.88)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   -351.87), SIMDE_FLOAT64_C(   -439.86)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_or_pd(test_vec[i].a, test_vec[i].b);
    simde_assert_m128d_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_or_si128(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi64x(INT64_C(   3806780817851842454), INT64_C(   3002076500639794819)),
      simde_mm_set_epi64x(INT64_C(  -1576369425501019200), INT64_C(   5863973371898850910)),
      simde_mm_set_epi64x(INT64_C(    -81065909581643818), INT64_C(   8784698508288454367)) },
    { simde_mm_set_epi64x(INT64_C(   4358272343769327172), INT64_C(  -4254544166297055533)),
      simde_mm_set_epi64x(INT64_C(  -3870591542062132163), INT64_C(   8365983368440196218)),
      simde_mm_set_epi64x(INT64_C(   -109223286268234115), INT64_C(   -793210092996038917)) },
    { simde_mm_set_epi64x(INT64_C(  -8935978336450140157), INT64_C(  -4292132981830530492)),
      simde_mm_set_epi64x(INT64_C(  -5275996428160709349), INT64_C(   1809702168782653061)),
      simde_mm_set_epi64x(INT64_C(  -5188173984729010917), INT64_C(  -2486163139644895547)) },
    { simde_mm_set_epi64x(INT64_C(  -3617483608260678394), INT64_C(  -7299761588855953181)),
      simde_mm_set_epi64x(INT64_C(  -3679366837934484296), INT64_C(   5342128716508209170)),
      simde_mm_set_epi64x(INT64_C(  -3603900203459740226), INT64_C(  -2687789418219853581)) },
    { simde_mm_set_epi64x(INT64_C(   8613776548693408177), INT64_C(  -1221094295236221778)),
      simde_mm_set_epi64x(INT64_C(   8491744443283364215), INT64_C(   4783609441494973751)),
      simde_mm_set_epi64x(INT64_C(   8636493096189557239), INT64_C(  -1193507273608823361)) },
    { simde_mm_set_epi64x(INT64_C(   2256952633337952767), INT64_C(  -5574602856706714295)),
      simde_mm_set_epi64x(INT64_C(  -7711313128986328449), INT64_C(  -5631421726257218112)),
      simde_mm_set_epi64x(INT64_C(  -6918672559143650305), INT64_C(  -5477736148453327415)) },
    { simde_mm_set_epi64x(INT64_C(   6915809581026069253), INT64_C(  -4447049561909832301)),
      simde_mm_set_epi64x(INT64_C(   7606865206928880870), INT64_C(    526097040835303983)),
      simde_mm_set_epi64x(INT64_C(   9221656517182193639), INT64_C(  -4085336622434885697)) },
    { simde_mm_set_epi64x(INT64_C(   6255716227368614659), INT64_C(   3842255123517004943)),
      simde_mm_set_epi64x(INT64_C(  -2544504471973996098), INT64_C(   7324902981920444710)),
      simde_mm_set_epi64x(INT64_C(  -2382159098826458177), INT64_C(   8500384867471056303)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_or_si128(test_vec[i].a, test_vec[i].b);
    simde_assert_m128i_i8(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_packs_epi16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi16(-22268,    -16,    -49,      8,  20029, -30901, -17364,    -65),
      simde_mm_set_epi16(-20429,   4131, -19140,  23907,    -87, -15818,    -93,    -34),
      simde_mm_set_epi8(INT8_C(-128), INT8_C( 127), INT8_C(-128), INT8_C( 127), INT8_C( -87), INT8_C(-128), INT8_C( -93), INT8_C( -34),
                        INT8_C(-128), INT8_C( -16), INT8_C( -49), INT8_C(   8), INT8_C( 127), INT8_C(-128), INT8_C(-128), INT8_C( -65)) },
    { simde_mm_set_epi16( -1320,     64,   7903,    -86,  17775,    -29, -24347,  20534),
      simde_mm_set_epi16(   -26,  32460,    -35,      9,     97, -16116,  21908,  31051),
      simde_mm_set_epi8(INT8_C( -26), INT8_C( 127), INT8_C( -35), INT8_C(   9), INT8_C(  97), INT8_C(-128), INT8_C( 127), INT8_C( 127),
                        INT8_C(-128), INT8_C(  64), INT8_C( 127), INT8_C( -86), INT8_C( 127), INT8_C( -29), INT8_C(-128), INT8_C( 127)) },
    { simde_mm_set_epi16(    16, -23521,    107,  10693,     37,  32277,   -120,    -13),
      simde_mm_set_epi16(  7912,    127, -27046,   -104,    114,    -54,    -26,  29057),
      simde_mm_set_epi8(INT8_C( 127), INT8_C( 127), INT8_C(-128), INT8_C(-104), INT8_C( 114), INT8_C( -54), INT8_C( -26), INT8_C( 127),
                        INT8_C(  16), INT8_C(-128), INT8_C( 107), INT8_C( 127), INT8_C(  37), INT8_C( 127), INT8_C(-120), INT8_C( -13)) },
    { simde_mm_set_epi16(     8,    -84,     26,  -1727,     53,  29056,  -7932,     40),
      simde_mm_set_epi16(-25560,     94,  19164,   -119, -25450,  26043,  -9549,    110),
      simde_mm_set_epi8(INT8_C(-128), INT8_C(  94), INT8_C( 127), INT8_C(-119), INT8_C(-128), INT8_C( 127), INT8_C(-128), INT8_C( 110),
                        INT8_C(   8), INT8_C( -84), INT8_C(  26), INT8_C(-128), INT8_C(  53), INT8_C( 127), INT8_C(-128), INT8_C(  40)) },
    { simde_mm_set_epi16( 17087,      3,  26871,    126, -10072,     95,    117,    110),
      simde_mm_set_epi16(  7667,  -3918,    -98,    -77,  29383, -21060, -18775,  21121),
      simde_mm_set_epi8(INT8_C( 127), INT8_C(-128), INT8_C( -98), INT8_C( -77), INT8_C( 127), INT8_C(-128), INT8_C(-128), INT8_C( 127),
                        INT8_C( 127), INT8_C(   3), INT8_C( 127), INT8_C( 126), INT8_C(-128), INT8_C(  95), INT8_C( 117), INT8_C( 110)) },
    { simde_mm_set_epi16(  -120, -29564,   -120,    -79,    -93, -23649,  25423, -23661),
      simde_mm_set_epi16(   109, -30808,     45,    -18,  -4268,  30580,     77,  -1896),
      simde_mm_set_epi8(INT8_C( 109), INT8_C(-128), INT8_C(  45), INT8_C( -18), INT8_C(-128), INT8_C( 127), INT8_C(  77), INT8_C(-128),
                        INT8_C(-120), INT8_C(-128), INT8_C(-120), INT8_C( -79), INT8_C( -93), INT8_C(-128), INT8_C( 127), INT8_C(-128)) },
    { simde_mm_set_epi16(    75,    -80,     -5,    -23,  -9879,    116, -20199,   5095),
      simde_mm_set_epi16( -3339,    -48,   -117,  -2107,  11715, -13793, -31434,  25021),
      simde_mm_set_epi8(INT8_C(-128), INT8_C( -48), INT8_C(-117), INT8_C(-128), INT8_C( 127), INT8_C(-128), INT8_C(-128), INT8_C( 127),
                        INT8_C(  75), INT8_C( -80), INT8_C(  -5), INT8_C( -23), INT8_C(-128), INT8_C( 116), INT8_C(-128), INT8_C( 127)) },
    { simde_mm_set_epi16(   -15,    110,   -521,     75,  12019, -30116,  17702,  14401),
      simde_mm_set_epi16(-15008,    -80,   -127, -29333,     -7, -17846,     83,  25637),
      simde_mm_set_epi8(INT8_C(-128), INT8_C( -80), INT8_C(-127), INT8_C(-128), INT8_C(  -7), INT8_C(-128), INT8_C(  83), INT8_C( 127),
                        INT8_C( -15), INT8_C( 110), INT8_C(-128), INT8_C(  75), INT8_C( 127), INT8_C(-128), INT8_C( 127), INT8_C( 127)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_packs_epi16(test_vec[i].a, test_vec[i].b);
    simde_assert_m128i_i8(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_packs_epi32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi32(INT32_C( 1221393622), INT32_C(    1245122), INT32_C( -546439182), INT32_C( 1653967185)),
      simde_mm_set_epi32(INT32_C(   -5570627), INT32_C( 1604714526), INT32_C(    3276815), INT32_C( -865960168)),
      simde_mm_set_epi16(-32768,  32767,  32767, -32768,  32767,  32767, -32768,  32767) },
    { simde_mm_set_epi32(INT32_C(-1556742099), INT32_C(    3735602), INT32_C( -795913538), INT32_C(    5177351)),
      simde_mm_set_epi32(INT32_C(  230555532), INT32_C( -681902099), INT32_C(-1460947394), INT32_C( 1435959285)),
      simde_mm_set_epi16( 32767, -32768, -32768,  32767, -32768,  32767, -32768,  32767) },
    { simde_mm_set_epi32(INT32_C( 1058013130), INT32_C( 1801350196), INT32_C(    3735625), INT32_C(     393200)),
      simde_mm_set_epi32(INT32_C(   -5046245), INT32_C( 1947557327), INT32_C( -390520293), INT32_C(-1060577736)),
      simde_mm_set_epi16(-32768,  32767, -32768, -32768,  32767,  32767,  32767,  32767) },
    { simde_mm_set_epi32(INT32_C( 1625994666), INT32_C(  151157112), INT32_C(   -6356918), INT32_C(  574958135)),
      simde_mm_set_epi32(INT32_C( -878149423), INT32_C(   -1310820), INT32_C(    7694016), INT32_C(    1656093)),
      simde_mm_set_epi16(-32768, -32768,  32767,  32767,  32767,  32767, -32768,  32767) },
    { simde_mm_set_epi32(INT32_C(  906756004), INT32_C(  589883340), INT32_C(-1375993871), INT32_C(   -5221415)),
      simde_mm_set_epi32(INT32_C(-1492628097), INT32_C(   -7536518), INT32_C(    1834989), INT32_C(-2090880115)),
      simde_mm_set_epi16(-32768, -32768,  32767, -32768,  32767,  32767, -32768, -32768) },
    { simde_mm_set_epi32(INT32_C( 1759910713), INT32_C( 2028743221), INT32_C( 1203039561), INT32_C(    3735524)),
      simde_mm_set_epi32(INT32_C(    5505016), INT32_C(   68681650), INT32_C(    3895727), INT32_C(-1084227687)),
      simde_mm_set_epi16( 32767,  32767,  32767, -32768,  32767,  32767,  32767,  32767) },
    { simde_mm_set_epi32(INT32_C( 1249181759), INT32_C(  850460644), INT32_C(  643956807), INT32_C( 1402185830)),
      simde_mm_set_epi32(INT32_C(  503821785), INT32_C(   -1966044), INT32_C(   -1228291), INT32_C(    6420027)),
      simde_mm_set_epi16( 32767, -32768, -32768,  32767,  32767,  32767,  32767,  32767) },
    { simde_mm_set_epi32(INT32_C( 1562990695), INT32_C(  134021098), INT32_C(-1071906850), INT32_C( -558152330)),
      simde_mm_set_epi32(INT32_C(-1746927677), INT32_C(    7209004), INT32_C(     917512), INT32_C(    4155429)),
      simde_mm_set_epi16(-32768,  32767,  32767,  32767,  32767,  32767, -32768, -32768) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_packs_epi32(test_vec[i].a, test_vec[i].b);
    simde_assert_m128i_i16(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_packus_epi16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi16(   217, -10893,  10007, -11974,    134,     45,     21,    179),
      simde_mm_set_epi16( 14829,     37,   2757, -26385,     26,    196,   2768,    221),
      simde_x_mm_set_epu8(255,  37, 255,   0,  26, 196, 255, 221,
                          217,   0, 255,   0, 134,  45,  21, 179) },
    { simde_mm_set_epi16(    84,  11197,     28, -18960,      0,    243,    209,    115),
      simde_mm_set_epi16( 26800,     44,    244,    114,    234,   7269,   2441,  -9419),
      simde_x_mm_set_epu8(255,  44, 244, 114, 234, 255, 255,   0,
                           84, 255,  28,   0,   0, 243, 209, 115) },
    { simde_mm_set_epi16( 26559, -13811,    141,    130, -24149,    185,   9120, -14604),
      simde_mm_set_epi16(   190,    162,   3761, -10696,  15175,   6926,  19649,     79),
      simde_x_mm_set_epu8(190, 162, 255,   0, 255, 255, 255,  79,
                          255,   0, 141, 130,   0, 185, 255,   0) },
    { simde_mm_set_epi16(   250, -23643, -15994,    173,     97,    158,     82,    231),
      simde_mm_set_epi16(    70,  30022,      0,  -8717,      6,    206, -25401,    252),
      simde_x_mm_set_epu8( 70, 255,   0,   0,   6, 206,   0, 252,
                          250,   0,   0, 173,  97, 158,  82, 231) },
    { simde_mm_set_epi16(    92, -13839,    243,  -3624,    252, -29405,      3,   6730),
      simde_mm_set_epi16(  4496,  19200,     70,    128,   2496,     60,  18531, -20006),
      simde_x_mm_set_epu8(255, 255,  70, 128, 255,  60, 255,   0,
                           92,   0, 243,   0, 252,   0,   3, 255) },
    { simde_mm_set_epi16(    57, -14586,  21134,   7065,      3, -16049,  26223, -20721),
      simde_mm_set_epi16(   129,    105,  -1899,    221, -24446, -20297,  30906,    192),
      simde_x_mm_set_epu8(129, 105,   0, 221,   0,   0, 255, 192,
                           57,   0, 255, 255,   3,   0, 255,   0) },
    { simde_mm_set_epi16(   128,  22639,  -9670,   8168,  -1055, -24505,  32719,  16999),
      simde_mm_set_epi16(-23185,    119,    108,     34, -15892,   2641,    242,  -7325),
      simde_x_mm_set_epu8(  0, 119, 108,  34,   0, 255, 242,   0,
                          128, 255,   0, 255,   0,   0, 255, 255) },
    { simde_mm_set_epi16(    95,    145,    101,   5449,    163,  19185,   3025,     52),
      simde_mm_set_epi16(  2870,    140,    144,    254,   8482,   4388,    201, -14867),
      simde_x_mm_set_epu8(255, 140, 144, 254, 255, 255, 201,   0,
                           95, 145, 101, 255, 163, 255, 255,  52) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_packus_epi16(test_vec[i].a, test_vec[i].b);
    simde_assert_m128i_i8(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_sad_epu8(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_x_mm_set_epu8(215,  90,  59, 114, 199, 190,   5,  88,
                          189, 152,  95,  90,  71,  40,  85,  39),
      simde_x_mm_set_epu8( 54, 166, 154, 195, 131,  97, 225, 141,
                          107,   5,  50,  55, 194,  31, 223,  92),
      simde_mm_set_epi64x(INT64_C( 847), INT64_C( 632)) },
    { simde_x_mm_set_epu8( 73,   8,  35,  63,   9, 118, 137, 154,
                          163,  61,   8,   4,  96,  39, 181,  31),
      simde_x_mm_set_epu8(244,  64,  21,   0,  73,  79,  47, 148,
                          227,   0, 217, 151, 241, 123, 179, 200),
      simde_mm_set_epi64x(INT64_C( 503), INT64_C( 881)) },
    { simde_x_mm_set_epu8(188, 156, 164, 209,  37, 165, 186, 237,
                          157,  45, 141,   9, 227,   9,   6, 113),
      simde_x_mm_set_epu8(196,  12, 188, 136, 227,  14, 111, 188,
                           42, 252, 141, 251,  41,  42,  48,  10),
      simde_mm_set_epi64x(INT64_C( 714), INT64_C( 928)) },
    { simde_x_mm_set_epu8(221, 210, 203,  74, 151,  53, 237,  96,
                          105,  62,  32, 146, 208,  27, 214,  15),
      simde_x_mm_set_epu8(106, 143, 238,  35, 165, 158,  48,  47,
                           51, 172,  84,  44, 119, 233,  73,  10),
      simde_mm_set_epi64x(INT64_C( 613), INT64_C( 759)) },
    { simde_x_mm_set_epu8(158, 146, 218,  39,  84, 176,  15, 200,
                          114, 100, 110,  72,  37, 118, 124,  52),
      simde_x_mm_set_epu8(250, 173, 237, 165,  77, 193,  83,  68,
                          159, 214,  52, 182, 160, 117, 236, 237),
      simde_mm_set_epi64x(INT64_C( 488), INT64_C( 748)) },
    { simde_x_mm_set_epu8(116,  17,  11, 212,  41, 247, 182,  55,
                          218, 151,  38, 248,  87,   3, 108,   3),
      simde_x_mm_set_epu8(178, 255,   4, 183,  81, 104,  79, 156,
                          178, 174,  55, 110, 255,  70, 179, 129),
      simde_mm_set_epi64x(INT64_C( 723), INT64_C( 650)) },
    { simde_x_mm_set_epu8( 26, 112, 229,  82, 174, 243,  79,  54,
                          103,  25, 150, 156, 120,  47,  29, 212),
      simde_x_mm_set_epu8(155, 158, 100, 233, 190, 145,   4, 176,
                          236,  88,  45,  24, 159, 182,  83, 215),
      simde_mm_set_epi64x(INT64_C( 766), INT64_C( 664)) },
    { simde_x_mm_set_epu8( 29, 127,  97,  34, 247,  17,  64,  73,
                          255,  69, 189, 150, 155,  84, 174,  88),
      simde_x_mm_set_epu8(224, 212,  67, 184, 190,  48, 118, 149,
                          209, 255,   9, 200, 126, 242, 201,  30),
      simde_mm_set_epi64x(INT64_C( 678), INT64_C( 734)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_sad_epu8(test_vec[i].a, test_vec[i].b);
    simde_assert_m128i_u8(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_set_epi8(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  for (size_t i = 0 ; i < 32 ; i++) {
    int8_t a[16];
    simde__m128i r;

    munit_rand_memory(sizeof(a), (uint8_t*) a);
    r = simde_mm_set_epi8(a[15], a[14], a[13], a[12], a[11], a[10], a[ 9], a[ 8],
                          a[ 7], a[ 6], a[ 5], a[ 4], a[ 3], a[ 2], a[ 1], a[ 0]);

    munit_assert_memory_equal(sizeof(a), a, &r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_set_epi16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  for (size_t i = 0 ; i < 32 ; i++) {
    int16_t a[8];
    simde__m128i r;

    munit_rand_memory(sizeof(a), (uint8_t*) a);
    r = simde_mm_set_epi16(a[7], a[6], a[5], a[4], a[3], a[2], a[1], a[0]);

    munit_assert_memory_equal(sizeof(a), a, &r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_set_epi32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  for (size_t i = 0 ; i < 32 ; i++) {
    int32_t a[4];
    simde__m128i r;

    munit_rand_memory(sizeof(a), (uint8_t*) a);
    r = simde_mm_set_epi32(a[3], a[2], a[1], a[0]);

    munit_assert_memory_equal(sizeof(a), a, &r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_set_epi64(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  for (size_t i = 0 ; i < 32 ; i++) {
    simde__m64 e1, e0;
    simde__m128i r;

    munit_rand_memory(sizeof(e1), (uint8_t*) &e1);
    munit_rand_memory(sizeof(e0), (uint8_t*) &e0);
    r = simde_mm_set_epi64(e1, e0);

    munit_assert_int64(r.i64[1], ==, e1.i64[0]);
    munit_assert_int64(r.i64[0], ==, e0.i64[0]);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_set_epi64x(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  for (size_t i = 0 ; i < 32 ; i++) {
    int64_t e1, e0;
    simde__m128i r;

    munit_rand_memory(sizeof(e1), (uint8_t*) &e1);
    munit_rand_memory(sizeof(e0), (uint8_t*) &e0);
    r = simde_mm_set_epi64x(e1, e0);

    munit_assert_int64(r.i64[1], ==, e1);
    munit_assert_int64(r.i64[0], ==, e0);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_set_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  for (size_t i = 0 ; i < 32 ; i++) {
    simde_float64 e1, e0;
    simde__m128d r;

    e0 = random_f64_range(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    e1 = random_f64_range(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    r = simde_mm_set_pd(e1, e0);

    munit_assert_double(r.f64[0], ==, e0);
    munit_assert_double(r.f64[1], ==, e1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_set1_epi8(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  for (size_t i = 0 ; i < 32 ; i++) {
    int8_t v;
    simde__m128i r;

    munit_rand_memory(sizeof(v), (uint8_t*) &v);

    r = simde_mm_set1_epi8(v);

    for (size_t j = 0 ; j < sizeof(r) / sizeof(r.i8) ; j++) {
      munit_assert_int8(v, ==, r.i8[j]);
    }
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_set_pd1(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  for (size_t i = 0 ; i < 32 ; i++) {
    simde_float64 a;
    simde__m128d r;

    a = random_f64_range(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    r = simde_mm_set_pd1(a);

    munit_assert_double(r.f64[0], ==, a);
    munit_assert_double(r.f64[1], ==, a);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_set_sd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  for (size_t i = 0 ; i < 32 ; i++) {
    simde_float64 a;
    simde__m128d r;

    a = random_f64_range(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    r = simde_mm_set_sd(a);

    munit_assert_double(r.f64[0], ==, a);
    munit_assert_int64(r.i64[1], ==, 0);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_set1_epi64(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  for (size_t i = 0 ; i < 32 ; i++) {
    simde__m64 v;
    simde__m128i r;

    munit_rand_memory(sizeof(v), (uint8_t*) &v);

    r = simde_mm_set1_epi64(v);

    for (size_t j = 0 ; j < sizeof(r) / sizeof(r.i64[0]) ; j++) {
      munit_assert_int64(v.i64[0], ==, r.i64[j]);
    }
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_set1_epi64x(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  for (size_t i = 0 ; i < 32 ; i++) {
    int64_t v;
    simde__m128i r;

    munit_rand_memory(sizeof(v), (uint8_t*) &v);

    r = simde_mm_set1_epi64x(v);

    for (size_t j = 0 ; j < sizeof(r) / sizeof(r.i64[0]) ; j++) {
      munit_assert_int64(v, ==, r.i64[j]);
    }
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_setr_epi8(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    int8_t a[16];
    simde__m128i r;
  } test_vec[8] = {
    { { -117,  101,  -68,  -84,   57,  -16,   14,  112,
          -4,  -62,   47,  -17,   21,   25,  -74,   93 },
      simde_mm_set_epi8(INT8_C(  93), INT8_C( -74), INT8_C(  25), INT8_C(  21), INT8_C( -17), INT8_C(  47), INT8_C( -62), INT8_C(  -4),
                        INT8_C( 112), INT8_C(  14), INT8_C( -16), INT8_C(  57), INT8_C( -84), INT8_C( -68), INT8_C( 101), INT8_C(-117)) },
    { { -121,  -99,   93,   75,  -45,   61,  -29,   21,
          43,  -55, -114,  120,    9,  -25,  107,  106 },
      simde_mm_set_epi8(INT8_C( 106), INT8_C( 107), INT8_C( -25), INT8_C(   9), INT8_C( 120), INT8_C(-114), INT8_C( -55), INT8_C(  43),
                        INT8_C(  21), INT8_C( -29), INT8_C(  61), INT8_C( -45), INT8_C(  75), INT8_C(  93), INT8_C( -99), INT8_C(-121)) },
    { {   17,  120,   33,  -15,  -38,  -48,   75,  -19,
         105,  -73,  -87,   91,   57,  125,   70,   11 },
      simde_mm_set_epi8(INT8_C(  11), INT8_C(  70), INT8_C( 125), INT8_C(  57), INT8_C(  91), INT8_C( -87), INT8_C( -73), INT8_C( 105),
                        INT8_C( -19), INT8_C(  75), INT8_C( -48), INT8_C( -38), INT8_C( -15), INT8_C(  33), INT8_C( 120), INT8_C(  17)) },
    { {   56,  -40,   93,   54,    0, -115,  -62,    6,
          10,  -58,  -12,   31,  -96,   67,   12,   19 },
      simde_mm_set_epi8(INT8_C(  19), INT8_C(  12), INT8_C(  67), INT8_C( -96), INT8_C(  31), INT8_C( -12), INT8_C( -58), INT8_C(  10),
                        INT8_C(   6), INT8_C( -62), INT8_C(-115), INT8_C(   0), INT8_C(  54), INT8_C(  93), INT8_C( -40), INT8_C(  56)) },
    { {   37,  -21,   96,  -83,   46,  -81,  -51,  -14,
         127,   26,  -91,  -48,   45,  -55, -111,  109 },
      simde_mm_set_epi8(INT8_C( 109), INT8_C(-111), INT8_C( -55), INT8_C(  45), INT8_C( -48), INT8_C( -91), INT8_C(  26), INT8_C( 127),
                        INT8_C( -14), INT8_C( -51), INT8_C( -81), INT8_C(  46), INT8_C( -83), INT8_C(  96), INT8_C( -21), INT8_C(  37)) },
    { {  -77,   43,  114,  -94,  -36,  -86,  -18,   18,
          14,   -4,   99,   78,   44,   70,  105,  -91 },
      simde_mm_set_epi8(INT8_C( -91), INT8_C( 105), INT8_C(  70), INT8_C(  44), INT8_C(  78), INT8_C(  99), INT8_C(  -4), INT8_C(  14),
                        INT8_C(  18), INT8_C( -18), INT8_C( -86), INT8_C( -36), INT8_C( -94), INT8_C( 114), INT8_C(  43), INT8_C( -77)) },
    { {  125,  -73,  -25, -106,   -9,  112,  -96,   59,
          61,  -50,   73,  -71,   13,    0,  -64,  -15 },
      simde_mm_set_epi8(INT8_C( -15), INT8_C( -64), INT8_C(   0), INT8_C(  13), INT8_C( -71), INT8_C(  73), INT8_C( -50), INT8_C(  61),
                        INT8_C(  59), INT8_C( -96), INT8_C( 112), INT8_C(  -9), INT8_C(-106), INT8_C( -25), INT8_C( -73), INT8_C( 125)) },
    { {   76,   81,  -62,   21,   -3,   99,  -61,  126,
         -15,  -95,   99,  -34,   78,   36,   56,  -38 },
      simde_mm_set_epi8(INT8_C( -38), INT8_C(  56), INT8_C(  36), INT8_C(  78), INT8_C( -34), INT8_C(  99), INT8_C( -95), INT8_C( -15),
                        INT8_C( 126), INT8_C( -61), INT8_C(  99), INT8_C(  -3), INT8_C(  21), INT8_C( -62), INT8_C(  81), INT8_C(  76)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r =
      simde_mm_setr_epi8(test_vec[i].a[ 0], test_vec[i].a[ 1], test_vec[i].a[ 2], test_vec[i].a[ 3],
                         test_vec[i].a[ 4], test_vec[i].a[ 5], test_vec[i].a[ 6], test_vec[i].a[ 7],
                         test_vec[i].a[ 8], test_vec[i].a[ 9], test_vec[i].a[10], test_vec[i].a[11],
                         test_vec[i].a[12], test_vec[i].a[13], test_vec[i].a[14], test_vec[i].a[15]);
    simde_assert_m128i_i8(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_setr_epi16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    int16_t a[8];
    simde__m128i r;
  } test_vec[8] = {
    { { -10562,  -1563,   3119,   8148, -20473,  28066,  19911,  32415 },
      simde_mm_set_epi16( 32415,  19911,  28066, -20473,   8148,   3119,  -1563, -10562) },
    { {  -5842, -19524,  19809,  -4522, -18693, -13515,  10296, -11468 },
      simde_mm_set_epi16(-11468,  10296, -13515, -18693,  -4522,  19809, -19524,  -5842) },
    { {  21973, -10968, -22468,   4564,  15035,   4920,  15286,  10966 },
      simde_mm_set_epi16( 10966,  15286,   4920,  15035,   4564, -22468, -10968,  21973) },
    { { -30861,  17137,  12124,  23736,  -1854,  30822, -26631,  14095 },
      simde_mm_set_epi16( 14095, -26631,  30822,  -1854,  23736,  12124,  17137, -30861) },
    { {  -8301, -14416, -32194,  -4341,   1212,  26290, -16654,  -9801 },
      simde_mm_set_epi16( -9801, -16654,  26290,   1212,  -4341, -32194, -14416,  -8301) },
    { {  -5842,  17831,    171,  10031,   7446,  23430,  -5408, -23387 },
      simde_mm_set_epi16(-23387,  -5408,  23430,   7446,  10031,    171,  17831,  -5842) },
    { {   3343, -24774,  -5050,  25934, -13848,  27661,  13484,  -5817 },
      simde_mm_set_epi16( -5817,  13484,  27661, -13848,  25934,  -5050, -24774,   3343) },
    { {  27516, -24147, -18268,  10553,  12061, -22335,  29977, -25416 },
      simde_mm_set_epi16(-25416,  29977, -22335,  12061,  10553, -18268, -24147,  27516) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r =
      simde_mm_setr_epi16(test_vec[i].a[ 0], test_vec[i].a[ 1], test_vec[i].a[ 2], test_vec[i].a[ 3],
                          test_vec[i].a[ 4], test_vec[i].a[ 5], test_vec[i].a[ 6], test_vec[i].a[ 7]);
    simde_assert_m128i_i16(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_setr_epi32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    int32_t a[4];
    simde__m128i r;
  } test_vec[8] = {
    { { INT32_C(  576930619), INT32_C(-1056617076), INT32_C( 1391020156), INT32_C( -119436850) },
      simde_mm_set_epi32(INT32_C( -119436850), INT32_C( 1391020156), INT32_C(-1056617076), INT32_C(  576930619)) },
    { { INT32_C(-2038323421), INT32_C(-1916700674), INT32_C( 1438851519), INT32_C( 1990196695) },
      simde_mm_set_epi32(INT32_C( 1990196695), INT32_C( 1438851519), INT32_C(-1916700674), INT32_C(-2038323421)) },
    { { INT32_C( 1146758814), INT32_C(  625179194), INT32_C(-1226824864), INT32_C(-1523319395) },
      simde_mm_set_epi32(INT32_C(-1523319395), INT32_C(-1226824864), INT32_C(  625179194), INT32_C( 1146758814)) },
    { { INT32_C( -276839793), INT32_C( 1178530072), INT32_C(-1956542830), INT32_C( -556652843) },
      simde_mm_set_epi32(INT32_C( -556652843), INT32_C(-1956542830), INT32_C( 1178530072), INT32_C( -276839793)) },
    { { INT32_C(-1720519476), INT32_C(  147115658), INT32_C(  736217848), INT32_C(-1149123643) },
      simde_mm_set_epi32(INT32_C(-1149123643), INT32_C(  736217848), INT32_C(  147115658), INT32_C(-1720519476)) },
    { { INT32_C( 1888725856), INT32_C( -696349459), INT32_C(-1872984731), INT32_C( 1198325431) },
      simde_mm_set_epi32(INT32_C( 1198325431), INT32_C(-1872984731), INT32_C( -696349459), INT32_C( 1888725856)) },
    { { INT32_C( 1999809110), INT32_C( -469856594), INT32_C(-1721902839), INT32_C(-1910021155) },
      simde_mm_set_epi32(INT32_C(-1910021155), INT32_C(-1721902839), INT32_C( -469856594), INT32_C( 1999809110)) },
    { { INT32_C(   57396463), INT32_C(-1219624618), INT32_C( -492678555), INT32_C(-1751286944) },
      simde_mm_set_epi32(INT32_C(-1751286944), INT32_C( -492678555), INT32_C(-1219624618), INT32_C(   57396463)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_setr_epi32(test_vec[i].a[ 0], test_vec[i].a[ 1], test_vec[i].a[ 2], test_vec[i].a[ 3]);
    simde_assert_m128i_i32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_setzero_si128(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  simde__m128i r = simde_mm_setzero_si128();

  for (size_t j = 0 ; j < sizeof(r.i8) / sizeof(r.i8[0]) ; j++) {
    munit_assert_int8(0, ==, r.i8[j]);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_shuffle_epi32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi32(INT32_C( -749480461), INT32_C(-1872761030), INT32_C( 1690143325), INT32_C( -258848374)),
      simde_mm_set_epi32(INT32_C(-1872761030), INT32_C(-1872761030), INT32_C(-1872761030), INT32_C(-1872761030)) },
    { simde_mm_set_epi32(INT32_C( 1030695986), INT32_C( 1932252260), INT32_C( 1962976759), INT32_C(-1621624916)),
      simde_mm_set_epi32(INT32_C( 1932252260), INT32_C( 1932252260), INT32_C( 1932252260), INT32_C( 1932252260)) },
    { simde_mm_set_epi32(INT32_C( -897180326), INT32_C( 1675136548), INT32_C( 1746269378), INT32_C( 1984702409)),
      simde_mm_set_epi32(INT32_C( 1675136548), INT32_C( 1675136548), INT32_C( 1675136548), INT32_C( 1675136548)) },
    { simde_mm_set_epi32(INT32_C(  -11612835), INT32_C(-1878653813), INT32_C(-2135957543), INT32_C( -134555953)),
      simde_mm_set_epi32(INT32_C(-1878653813), INT32_C(-1878653813), INT32_C(-1878653813), INT32_C(-1878653813)) },
    { simde_mm_set_epi32(INT32_C( 1051337342), INT32_C(  755742115), INT32_C(  338927136), INT32_C( 1410014436)),
      simde_mm_set_epi32(INT32_C(  755742115), INT32_C(  755742115), INT32_C(  755742115), INT32_C(  755742115)) },
    { simde_mm_set_epi32(INT32_C(-1826960183), INT32_C( -119444047), INT32_C(-1224980361), INT32_C( 1323381864)),
      simde_mm_set_epi32(INT32_C( -119444047), INT32_C( -119444047), INT32_C( -119444047), INT32_C( -119444047)) },
    { simde_mm_set_epi32(INT32_C( 1256541920), INT32_C( 1446192699), INT32_C( -117794523), INT32_C(-1904270778)),
      simde_mm_set_epi32(INT32_C( 1446192699), INT32_C( 1446192699), INT32_C( 1446192699), INT32_C( 1446192699)) },
    { simde_mm_set_epi32(INT32_C(  542509546), INT32_C(-1970305999), INT32_C(-1492486994), INT32_C( 1078541043)),
      simde_mm_set_epi32(INT32_C(-1970305999), INT32_C(-1970305999), INT32_C(-1970305999), INT32_C(-1970305999)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_shuffle_epi32(test_vec[i].a, 0xaa);
    simde_assert_m128i_i32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_shuffle_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128d a;
    simde__m128d b;
    simde__m128d r;
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  897.05), SIMDE_FLOAT64_C(  524.15)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -346.39), SIMDE_FLOAT64_C( -595.93)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -595.93), SIMDE_FLOAT64_C(  524.15)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -684.88), SIMDE_FLOAT64_C(   62.45)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  765.70), SIMDE_FLOAT64_C( -126.52)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -126.52), SIMDE_FLOAT64_C(   62.45)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -871.69), SIMDE_FLOAT64_C( -753.55)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -923.31), SIMDE_FLOAT64_C( -103.97)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -103.97), SIMDE_FLOAT64_C( -753.55)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -377.03), SIMDE_FLOAT64_C(  701.23)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -672.47), SIMDE_FLOAT64_C( -328.63)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -328.63), SIMDE_FLOAT64_C(  701.23)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  238.70), SIMDE_FLOAT64_C(  837.56)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -429.19), SIMDE_FLOAT64_C(  106.67)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  106.67), SIMDE_FLOAT64_C(  837.56)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  571.83), SIMDE_FLOAT64_C( -389.51)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  447.48), SIMDE_FLOAT64_C(   -8.02)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   -8.02), SIMDE_FLOAT64_C( -389.51)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -214.27), SIMDE_FLOAT64_C(  549.07)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -967.02), SIMDE_FLOAT64_C( -162.29)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -162.29), SIMDE_FLOAT64_C(  549.07)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -528.33), SIMDE_FLOAT64_C(  376.34)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -959.95), SIMDE_FLOAT64_C( -855.93)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -855.93), SIMDE_FLOAT64_C(  376.34)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_shuffle_pd(test_vec[i].a, test_vec[i].b, 0);
    simde_assert_m128d_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_shufflehi_epi16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi16(  3588, -23598,  -2669,  -7880,  20391,  13327,  18868,  31239),
      simde_mm_set_epi16(  3588,   3588,  -2669,  -2669,  20391,  13327,  18868,  31239) },
    { simde_mm_set_epi16(  5701,  15357,  27973, -26447, -18797, -27249,  -9707,  -1950),
      simde_mm_set_epi16(  5701,   5701,  27973,  27973, -18797, -27249,  -9707,  -1950) },
    { simde_mm_set_epi16(-14544,  26887,  -7591,  22567,  -8366, -11381,   1736, -23069),
      simde_mm_set_epi16(-14544, -14544,  -7591,  -7591,  -8366, -11381,   1736, -23069) },
    { simde_mm_set_epi16( 31637,  12965, -23234, -12784,    364,   7338,  16998, -14384),
      simde_mm_set_epi16( 31637,  31637, -23234, -23234,    364,   7338,  16998, -14384) },
    { simde_mm_set_epi16( 20104, -31033,  12782,  -8281,  17249,  -1757, -22510, -23902),
      simde_mm_set_epi16( 20104,  20104,  12782,  12782,  17249,  -1757, -22510, -23902) },
    { simde_mm_set_epi16( 28403, -26721,  -6834, -28104,  -6404,  -5723, -30154,  -4442),
      simde_mm_set_epi16( 28403,  28403,  -6834,  -6834,  -6404,  -5723, -30154,  -4442) },
    { simde_mm_set_epi16( 18671,  -6207,  14078, -30976, -25644, -24126,  10939, -13801),
      simde_mm_set_epi16( 18671,  18671,  14078,  14078, -25644, -24126,  10939, -13801) },
    { simde_mm_set_epi16(-28546,  12696, -10401,  -8517,  29702, -10694,  25940,  28112),
      simde_mm_set_epi16(-28546, -28546, -10401, -10401,  29702, -10694,  25940,  28112) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_shufflehi_epi16(test_vec[i].a, 245);
    simde_assert_m128i_i16(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_shufflelo_epi16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi16( 25921,  23086, -17780,  -8946,  -3821, -23407,   3363, -23898),
      simde_mm_set_epi16( 25921,  23086, -17780,  -8946, -23407,   3363,   3363,   3363) },
    { simde_mm_set_epi16(-15732, -14043, -24694, -28614,   9258,  -6444,  22259, -29550),
      simde_mm_set_epi16(-15732, -14043, -24694, -28614,  -6444,  22259,  22259,  22259) },
    { simde_mm_set_epi16( 29589,  24471,    935,  15548, -31326,  12242, -15498,  20611),
      simde_mm_set_epi16( 29589,  24471,    935,  15548,  12242, -15498, -15498, -15498) },
    { simde_mm_set_epi16(-11775,  19870,  27196, -27788, -25544, -26192,  16129,  25581),
      simde_mm_set_epi16(-11775,  19870,  27196, -27788, -26192,  16129,  16129,  16129) },
    { simde_mm_set_epi16( 31307,  -8332, -11671, -17958, -30437,  30830,  32511,  26274),
      simde_mm_set_epi16( 31307,  -8332, -11671, -17958,  30830,  32511,  32511,  32511) },
    { simde_mm_set_epi16(-19440, -28661, -27597, -21720, -29791,  17924,  -2221, -31687),
      simde_mm_set_epi16(-19440, -28661, -27597, -21720,  17924,  -2221,  -2221,  -2221) },
    { simde_mm_set_epi16( 26610,  31793,   1765,   -378, -15235,  17943,      8,  14365),
      simde_mm_set_epi16( 26610,  31793,   1765,   -378,  17943,      8,      8,      8) },
    { simde_mm_set_epi16( -8514,  17338,   1723,   1355,  27911, -15857,  13585,   3367),
      simde_mm_set_epi16( -8514,  17338,   1723,   1355, -15857,  13585,  13585,  13585) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    /* 149 chosen by fair dice roll.  guaranteed to be random. */
    simde__m128i r = simde_mm_shufflelo_epi16(test_vec[i].a, 149);
    simde_assert_m128i_i16(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_sra_epi16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m128i count;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi16( 28258,   1159,  20634, -30158,  10049, -31721, -26691, -28181),
      simde_mm_set_epi16(    11,      6,     10,      8,     15,      3,      8,      1),
      simde_mm_set_epi16(     0,      0,      0,     -1,      0,     -1,     -1,     -1) },
    { simde_mm_set_epi16(-25682,   7964,   1259,  18017,  10765, -10649,  -9400,  12110),
      simde_mm_set_epi16(     3,      8,      3,      2,     10,      5,      2,      2),
      simde_mm_set_epi16(    -1,      0,      0,      0,      0,     -1,     -1,      0) },
    { simde_mm_set_epi16(-24685,  14370,  13079,  -6409, -18776,  20941,  22692,    312),
      simde_mm_set_epi16(    13,     13,      0,      7,      4,     10,     15,     11),
      simde_mm_set_epi16(    -1,      0,      0,     -1,     -1,      0,      0,      0) },
    { simde_mm_set_epi16( 13442, -32489, -21378,  10156,  15393,  20131,  15138, -12589),
      simde_mm_set_epi16(     1,      3,      1,      8,     12,      3,      4,      2),
      simde_mm_set_epi16(     0,     -1,     -1,      0,      0,      0,      0,     -1) },
    { simde_mm_set_epi16( -9561,  25554,  -5305,  -7173, -10064,  31075,  30218, -18929),
      simde_mm_set_epi16(     5,     10,      8,      1,     12,      3,     10,     10),
      simde_mm_set_epi16(    -1,      0,     -1,     -1,     -1,      0,      0,     -1) },
    { simde_mm_set_epi16( 14091,  24202,  -8543,  -7482, -26143,  20277, -27984, -32658),
      simde_mm_set_epi16(     5,      7,      6,      6,     10,      3,      7,     11),
      simde_mm_set_epi16(     0,      0,     -1,     -1,     -1,      0,     -1,     -1) },
    { simde_mm_set_epi16(-19726,  12311,  16279,  -6277,  19874, -27089,  14524, -14305),
      simde_mm_set_epi16(     7,      7,      3,      1,     12,      1,     10,      9),
      simde_mm_set_epi16(    -1,      0,      0,     -1,      0,     -1,      0,     -1) },
    { simde_mm_set_epi16( 19801, -12786,  31632,  19030, -19420, -12406,  12426,  27612),
      simde_mm_set_epi16(     2,      0,     10,      3,      9,      0,      1,      8),
      simde_mm_set_epi16(     0,     -1,      0,      0,     -1,     -1,      0,      0) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_sra_epi16(test_vec[i].a, test_vec[i].count);
    simde_assert_m128i_i16(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_sll_epi16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m128i count;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi16( 28619,  -5953, -16254,  14321, -32212,   8822, -19096,  -5776),
      simde_mm_set_epi64x(INT64_C(-5262793264663215472), INT64_C(16)),
      simde_mm_set_epi16(     0,      0,      0,      0,      0,      0,      0,      0) },
    { simde_mm_set_epi16(  8674, -14570, -26957,  29447,   -441,    741, -14495,   6207),
      simde_mm_set_epi64x(INT64_C(-8018169735231443299), INT64_C( 1)),
      simde_mm_set_epi16( 17348, -29140,  11622,  -6642,   -882,   1482, -28990,  12414) },
    { simde_mm_set_epi16( -7857, -27771,  -4956,  26444,  -1246, -29532, -28523,  26469),
      simde_mm_set_epi64x(INT64_C( 1150552132815785095), INT64_C(12)),
      simde_mm_set_epi16( -4096,  20480,  16384, -16384,   8192,  16384,  20480,  20480) },
    { simde_mm_set_epi16( 10613, -11227,  -7453, -22857,   2268,   9708,  27547, -10355),
      simde_mm_set_epi64x(INT64_C(-1714103729784977145), INT64_C( 5)),
      simde_mm_set_epi16( 11936, -31584,  23648, -10528,   7040, -17024,  29536,  -3680) },
    { simde_mm_set_epi16( 17665,  -2674,  27172,    634,  21804, -24222,  25510,  21049),
      simde_mm_set_epi64x(INT64_C(-8922909725876665702), INT64_C( 2)),
      simde_mm_set_epi16(  5124, -10696, -22384,   2536,  21680, -31352, -29032,  18660) },
    { simde_mm_set_epi16(-23037,  -7377,  27134,  -3511,   1468,  -6294,   9114, -31690),
      simde_mm_set_epi64x(INT64_C( 7011241116916112587), INT64_C(15)),
      simde_mm_set_epi16(-32768, -32768,      0, -32768,      0,      0,      0,      0) },
    { simde_mm_set_epi16( -6386,  18833,  24907,  -7277,  12368, -12450,    267,  18654),
      simde_mm_set_epi64x(INT64_C( 4951339001913100627), INT64_C(13)),
      simde_mm_set_epi16(-16384,   8192,  24576,  24576,      0, -16384,  24576, -16384) },
    { simde_mm_set_epi16( 27095,  -9690,  16598,   5234, -15080,  -4410,  31377,  31629),
      simde_mm_set_epi64x(INT64_C( 1577848631857250403), INT64_C( 4)),
      simde_mm_set_epi16(-25232, -23968,   3424,  18208,  20864,  -5024, -22256, -18224) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_sll_epi16(test_vec[i].a, test_vec[i].count);
    simde_assert_m128i_i16(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_sll_epi32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m128i count;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi32(INT32_C( 1875634367), INT32_C(-1065207823), INT32_C(-2111036810), INT32_C(-1251415696)),
      simde_mm_set_epi64x(INT64_C(-5262793264663215472), INT64_C(16)),
      simde_mm_set_epi32(INT32_C( -390135808), INT32_C(  938541056), INT32_C(  578158592), INT32_C( -378535936)) },
    { simde_mm_set_epi32(INT32_C(  568510230), INT32_C(-1766624505), INT32_C(  -28900635), INT32_C( -949938113)),
      simde_mm_set_epi64x(INT64_C(-8018169735231443299), INT64_C( 1)),
      simde_mm_set_epi32(INT32_C( 1137020460), INT32_C(  761718286), INT32_C(  -57801270), INT32_C(-1899876226)) },
    { simde_mm_set_epi32(INT32_C( -514878587), INT32_C( -324769972), INT32_C(  -81621852), INT32_C(-1869256859)),
      simde_mm_set_epi64x(INT64_C( 1150552132815785095), INT64_C(12)),
      simde_mm_set_epi32(INT32_C( -113750016), INT32_C( 1182056448), INT32_C(  684343296), INT32_C( 1450594304)) },
    { simde_mm_set_epi32(INT32_C(  695587877), INT32_C( -488397129), INT32_C(  148645356), INT32_C( 1805375373)),
      simde_mm_set_epi64x(INT64_C(-1714103729784977145), INT64_C( 5)),
      simde_mm_set_epi32(INT32_C(  783975584), INT32_C( 1551161056), INT32_C(  461684096), INT32_C( 1937437088)) },
    { simde_mm_set_epi32(INT32_C( 1157756302), INT32_C( 1780744826), INT32_C( 1428988258), INT32_C( 1671844409)),
      simde_mm_set_epi64x(INT64_C(-8922909725876665702), INT64_C( 2)),
      simde_mm_set_epi32(INT32_C(  336057912), INT32_C(-1466955288), INT32_C( 1420985736), INT32_C(-1902556956)) },
    { simde_mm_set_epi32(INT32_C(-1509694673), INT32_C( 1778315849), INT32_C(   96266090), INT32_C(  597328950)),
      simde_mm_set_epi64x(INT64_C( 7011241116916112587), INT64_C(15)),
      simde_mm_set_epi32(INT32_C( -241729536), INT32_C( 2032435200), INT32_C( 1941241856), INT32_C( 1109065728)) },
    { simde_mm_set_epi32(INT32_C( -418494063), INT32_C( 1632363411), INT32_C(  810602334), INT32_C(   17516766)),
      simde_mm_set_epi64x(INT64_C( 4951339001913100627), INT64_C(13)),
      simde_mm_set_epi32(INT32_C( -919461888), INT32_C( 2087870464), INT32_C(  434880512), INT32_C( 1763426304)) },
    { simde_mm_set_epi32(INT32_C( 1775753766), INT32_C( 1087771762), INT32_C( -988221754), INT32_C( 2056354701)),
      simde_mm_set_epi64x(INT64_C( 1577848631857250403), INT64_C( 4)),
      simde_mm_set_epi32(INT32_C(-1652710816), INT32_C(  224479008), INT32_C( 1368321120), INT32_C(-1458063152)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_sll_epi32(test_vec[i].a, test_vec[i].count);
    simde_assert_m128i_i32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_sll_epi64(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m128i count;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi64x(INT64_C( 8055788268748421105), INT64_C(-9066834056558614160)),
      simde_mm_set_epi64x(INT64_C(-5262793264663215472), INT64_C(16)),
      simde_mm_set_epi64x(INT64_C(-1675408870841712640), INT64_C( 2483371706739064832)) },
    { simde_mm_set_epi64x(INT64_C( 2441732847819780871), INT64_C( -124127278813603777)),
      simde_mm_set_epi64x(INT64_C(-8018169735231443299), INT64_C( 1)),
      simde_mm_set_epi64x(INT64_C( 4883465695639561742), INT64_C( -248254557627207554)) },
    { simde_mm_set_epi64x(INT64_C(-2211386688605493428), INT64_C( -350563182553241755)),
      simde_mm_set_epi64x(INT64_C( 1150552132815785095), INT64_C(12)),
      simde_mm_set_epi64x(INT64_C( -488536336711237632), INT64_C( 2939242011266797568)) },
    { simde_mm_set_epi64x(INT64_C( 2987527187015640759), INT64_C(  638426944527652749)),
      simde_mm_set_epi64x(INT64_C(-1714103729784977145), INT64_C( 5)),
      simde_mm_set_epi64x(INT64_C( 3367149615952746208), INT64_C( 1982918151175336352)) },
    { simde_mm_set_epi64x(INT64_C( 4972525455608644218), INT64_C( 6137457836149854777)),
      simde_mm_set_epi64x(INT64_C(-8922909725876665702), INT64_C( 2)),
      simde_mm_set_epi64x(INT64_C( 1443357748725025256), INT64_C( 6103087270889867492)) },
    { simde_mm_set_epi64x(INT64_C(-6484089245702098359), INT64_C(  413459708861121590)),
      simde_mm_set_epi64x(INT64_C( 7011241116916112587), INT64_C(15)),
      simde_mm_set_epi64x(INT64_C(-1038162179743514624), INT64_C( 8337589858421374976)) },
    { simde_mm_set_epi64x(INT64_C(-1797418312522800237), INT64_C( 3481510514608785630)),
      simde_mm_set_epi64x(INT64_C( 4951339001913100627), INT64_C(13)),
      simde_mm_set_epi64x(INT64_C(-3949045366557351936), INT64_C( 1867797720205082624)) },
    { simde_mm_set_epi64x(INT64_C( 7626804351806608498), INT64_C(-4244380112569402483)),
      simde_mm_set_epi64x(INT64_C( 1577848631857250403), INT64_C( 4)),
      simde_mm_set_epi64x(INT64_C(-7098338887061125344), INT64_C( 5876894493727766736)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_sll_epi64(test_vec[i].a, test_vec[i].count);
    simde_assert_m128i_i64(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_sqrt_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128d a;
    simde__m128d r;
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  621.52), SIMDE_FLOAT64_C(  868.47)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   24.93), SIMDE_FLOAT64_C(   29.47)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  180.11), SIMDE_FLOAT64_C(    1.82)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   13.42), SIMDE_FLOAT64_C(    1.35)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  152.28), SIMDE_FLOAT64_C(  211.55)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   12.34), SIMDE_FLOAT64_C(   14.54)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  430.02), SIMDE_FLOAT64_C(  458.20)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   20.74), SIMDE_FLOAT64_C(   21.41)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  929.30), SIMDE_FLOAT64_C(  272.49)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   30.48), SIMDE_FLOAT64_C(   16.51)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  882.78), SIMDE_FLOAT64_C(  790.70)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   29.71), SIMDE_FLOAT64_C(   28.12)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  784.04), SIMDE_FLOAT64_C(   65.43)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   28.00), SIMDE_FLOAT64_C(    8.09)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  542.46), SIMDE_FLOAT64_C(  103.00)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   23.29), SIMDE_FLOAT64_C(   10.15)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_sqrt_pd(test_vec[i].a);
    simde_assert_m128d_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_sqrt_sd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128d a;
    simde__m128d b;
    simde__m128d r;
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C(    1.82), SIMDE_FLOAT64_C(  868.47)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  180.11), SIMDE_FLOAT64_C(  621.52)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    1.82), SIMDE_FLOAT64_C(   24.93)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  458.20), SIMDE_FLOAT64_C(  211.55)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  430.02), SIMDE_FLOAT64_C(  152.28)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  458.20), SIMDE_FLOAT64_C(   12.34)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  790.70), SIMDE_FLOAT64_C(  272.49)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  882.78), SIMDE_FLOAT64_C(  929.30)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  790.70), SIMDE_FLOAT64_C(   30.48)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  103.00), SIMDE_FLOAT64_C(   65.43)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  542.46), SIMDE_FLOAT64_C(  784.04)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  103.00), SIMDE_FLOAT64_C(   28.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  373.53), SIMDE_FLOAT64_C(  698.61)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  142.54), SIMDE_FLOAT64_C(  348.23)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  373.53), SIMDE_FLOAT64_C(   18.66)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  528.07), SIMDE_FLOAT64_C(  477.87)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  384.87), SIMDE_FLOAT64_C(  433.33)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  528.07), SIMDE_FLOAT64_C(   20.82)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  241.09), SIMDE_FLOAT64_C(  679.09)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  322.35), SIMDE_FLOAT64_C(  620.04)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  241.09), SIMDE_FLOAT64_C(   24.90)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  651.18), SIMDE_FLOAT64_C(  446.59)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  886.36), SIMDE_FLOAT64_C(  269.28)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  651.18), SIMDE_FLOAT64_C(   16.41)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_sqrt_sd(test_vec[i].a, test_vec[i].b);
    simde_assert_m128d_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_srl_epi16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m128i count;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi16(  1445,  14472, -18508,  -4645, -24581, -12656,   1275, -25245),
      simde_mm_set_epi64x(INT64_C( 4678230141678036905), INT64_C( 4)),
      simde_mm_set_epi16(    90,    904,   2939,   3805,   2559,   3305,     79,   2518) },
    { simde_mm_set_epi16(   986,  31796, -12770, -28401,  15186, -17595,  31992,  19329),
      simde_mm_set_epi64x(INT64_C(  234386534661459961), INT64_C( 2)),
      simde_mm_set_epi16(   246,   7949,  13191,   9283,   3796,  11985,   7998,   4832) },
    { simde_mm_set_epi16(-23898,   7158,  21829, -16536,   2052,  -6635,  18408,  -3755),
      simde_mm_set_epi64x(INT64_C( 8276161762185938564), INT64_C( 7)),
      simde_mm_set_epi16(   325,     55,    170,    382,     16,    460,    143,    482) },
    { simde_mm_set_epi16(-19513, -10508, -12500,  22379,   4775,   8063,   8132,   7840),
      simde_mm_set_epi64x(INT64_C( 1101003055866698034), INT64_C( 6)),
      simde_mm_set_epi16(   719,    859,    828,    349,     74,    125,    127,    122) },
    { simde_mm_set_epi16(  9942,  29561,  -4121, -26882, -17939,  13186,   6796,  14206),
      simde_mm_set_epi64x(INT64_C(  735258903315099979), INT64_C( 1)),
      simde_mm_set_epi16(  4971,  14780,  30707,  19327,  23798,   6593,   3398,   7103) },
    { simde_mm_set_epi16(  5648, -13469, -23201,   7029, -28211, -14496,  31202, -32095),
      simde_mm_set_epi64x(INT64_C( 4870695400140482879), INT64_C(13)),
      simde_mm_set_epi16(     0,      6,      5,      0,      4,      6,      3,      4) },
    { simde_mm_set_epi16( 11526,  20336,  18003,  21727, -28471, -32732, -25472,  12636),
      simde_mm_set_epi64x(INT64_C(-6737308052137237000), INT64_C( 3)),
      simde_mm_set_epi16(  1440,   2542,   2250,   2715,   4633,   4100,   5008,   1579) },
    { simde_mm_set_epi16(-30386,  -2761,  11467,   9929, -19380, -12818,  -4584,  -6145),
      simde_mm_set_epi64x(INT64_C(-2450775638354168945), INT64_C( 3)),
      simde_mm_set_epi16(  4393,   7846,   1433,   1241,   5769,   6589,   7619,   7423) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_srl_epi16(test_vec[i].a, test_vec[i].count);
    simde_assert_m128i_i16(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_srl_epi32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m128i count;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi32(INT32_C(   94713992), INT32_C(-1212879397), INT32_C(-1610887536), INT32_C(   83598691)),
      simde_mm_set_epi64x(INT64_C( 4678230141678036905), INT64_C( 4)),
      simde_mm_set_epi32(INT32_C(    5919624), INT32_C(  192630493), INT32_C(  167754985), INT32_C(    5224918)) },
    { simde_mm_set_epi32(INT32_C(   64650292), INT32_C( -836857585), INT32_C(  995277637), INT32_C( 2096647041)),
      simde_mm_set_epi64x(INT64_C(  234386534661459961), INT64_C( 2)),
      simde_mm_set_epi32(INT32_C(   16162573), INT32_C(  864527427), INT32_C(  248819409), INT32_C(  524161760)) },
    { simde_mm_set_epi32(INT32_C(-1566172170), INT32_C( 1430634344), INT32_C(  134538773), INT32_C( 1206448469)),
      simde_mm_set_epi64x(INT64_C( 8276161762185938564), INT64_C( 7)),
      simde_mm_set_epi32(INT32_C(   21318711), INT32_C(   11176830), INT32_C(    1051084), INT32_C(    9425378)) },
    { simde_mm_set_epi32(INT32_C(-1278748940), INT32_C( -819177621), INT32_C(  312942463), INT32_C(  532946592)),
      simde_mm_set_epi64x(INT64_C( 1101003055866698034), INT64_C( 6)),
      simde_mm_set_epi32(INT32_C(   47128411), INT32_C(   54309213), INT32_C(    4889725), INT32_C(    8327290)) },
    { simde_mm_set_epi32(INT32_C(  651588473), INT32_C( -270035202), INT32_C(-1175637118), INT32_C(  445396862)),
      simde_mm_set_epi64x(INT64_C(  735258903315099979), INT64_C( 1)),
      simde_mm_set_epi32(INT32_C(  325794236), INT32_C( 2012466047), INT32_C( 1559665089), INT32_C(  222698431)) },
    { simde_mm_set_epi32(INT32_C(  370199395), INT32_C(-1520493707), INT32_C(-1848785056), INT32_C( 2044887713)),
      simde_mm_set_epi64x(INT64_C( 4870695400140482879), INT64_C(13)),
      simde_mm_set_epi32(INT32_C(      45190), INT32_C(     338680), INT32_C(     298606), INT32_C(     249620)) },
    { simde_mm_set_epi32(INT32_C(  755388272), INT32_C( 1179866335), INT32_C(-1865842652), INT32_C(-1669320356)),
      simde_mm_set_epi64x(INT64_C(-6737308052137237000), INT64_C( 3)),
      simde_mm_set_epi32(INT32_C(   94423534), INT32_C(  147483291), INT32_C(  303640580), INT32_C(  328205867)) },
    { simde_mm_set_epi32(INT32_C(-1991314121), INT32_C(  751511241), INT32_C(-1270034962), INT32_C( -300357633)),
      simde_mm_set_epi64x(INT64_C(-2450775638354168945), INT64_C( 3)),
      simde_mm_set_epi32(INT32_C(  287956646), INT32_C(   93938905), INT32_C(  378116541), INT32_C(  499326207)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_srl_epi32(test_vec[i].a, test_vec[i].count);
    simde_assert_m128i_i32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_srl_epi64(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m128i count;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi64x(INT64_C(  406793501195693531), INT64_C(-6918709284570423965)),
      simde_mm_set_epi64x(INT64_C( 4678230141678036905), INT64_C( 4)),
      simde_mm_set_epi64x(INT64_C(   25424593824730845), INT64_C(  720502174321195478)) },
    { simde_mm_set_epi64x(INT64_C(  277670893274960143), INT64_C( 4274684903451806593)),
      simde_mm_set_epi64x(INT64_C(  234386534661459961), INT64_C( 2)),
      simde_mm_set_epi64x(INT64_C(   69417723318740035), INT64_C( 1068671225862951648)) },
    { simde_mm_set_epi64x(INT64_C(-6726658248624717976), INT64_C(  577839631285416277)),
      simde_mm_set_epi64x(INT64_C( 8276161762185938564), INT64_C( 7)),
      simde_mm_set_epi64x(INT64_C(   91563170508475262), INT64_C(    4514372119417314)) },
    { simde_mm_set_epi64x(INT64_C(-5492184873618876565), INT64_C( 1344077644647636640)),
      simde_mm_set_epi64x(INT64_C( 1101003055866698034), INT64_C( 6)),
      simde_mm_set_epi64x(INT64_C(  202414987501416797), INT64_C(   21001213197619322)) },
    { simde_mm_set_epi64x(INT64_C( 2798551186010511102), INT64_C(-5049322973328296066)),
      simde_mm_set_epi64x(INT64_C(  735258903315099979), INT64_C( 1)),
      simde_mm_set_epi64x(INT64_C( 1399275593005255551), INT64_C( 6698710550190627775)) },
    { simde_mm_set_epi64x(INT64_C( 1589994297298459509), INT64_C(-7940471350808640863)),
      simde_mm_set_epi64x(INT64_C( 4870695400140482879), INT64_C(13)),
      simde_mm_set_epi64x(INT64_C(     194091100744440), INT64_C(    1282503994494740)) },
    { simde_mm_set_epi64x(INT64_C( 3244367925201818847), INT64_C(-8013733167196262052)),
      simde_mm_set_epi64x(INT64_C(-6737308052137237000), INT64_C( 3)),
      simde_mm_set_epi64x(INT64_C(  405545990650227355), INT64_C( 1304126363314161195)) },
    { simde_mm_set_epi64x(INT64_C(-8552629025006475575), INT64_C(-5454758622571993089)),
      simde_mm_set_epi64x(INT64_C(-2450775638354168945), INT64_C( 3)),
      simde_mm_set_epi64x(INT64_C( 1236764381087884505), INT64_C( 1623998181392194815)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_srl_epi64(test_vec[i].a, test_vec[i].count);
    simde_assert_m128i_i64(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_sra_epi32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m128i count;
    simde__m128i r;
  } test_vec[] = {
    { simde_mm_set_epi32( -561103335,  1276754862,  1749589432,   517536789),
      simde_mm_set_epi64x(0,  3),
      simde_mm_set_epi32(  -70137917,   159594357,   218698679,    64692098) },
    { simde_mm_set_epi32( -159892315, -1509631224, -1642880399,  1227124763),
      simde_mm_set_epi64x(0, 31),
      simde_mm_set_epi32(         -1,          -1,          -1,           0) },
    { simde_mm_set_epi32(-1747665335, -1727232090, -1061986990, -1651964431),
      simde_mm_set_epi64x(0, 21),
      simde_mm_set_epi32(       -834,        -824,        -507,        -788) },
    { simde_mm_set_epi32(  -43034101,  1748997429, -1014034292,  -471404994),
      simde_mm_set_epi64x(0, 23),
      simde_mm_set_epi32(         -6,         208,        -121,         -57) },
    { simde_mm_set_epi32(  663988211,   279391652,   930358665,   693100359),
      simde_mm_set_epi64x(0, 31),
      simde_mm_set_epi32(          0,           0,           0,           0) },
    { simde_mm_set_epi32( 1596760027,  -525985264, -1328341949, -1278585249),
      simde_mm_set_epi64x(0, 30),
      simde_mm_set_epi32(          1,          -1,          -2,          -2) },
    { simde_mm_set_epi32( 2099244913,  -668946691, -1425692748,  1445785661),
      simde_mm_set_epi64x(0, 19),
      simde_mm_set_epi32(       4003,       -1276,       -2720,        2757) },
    { simde_mm_set_epi32( -572539662,  1511976084, -2125946535, -1043884202),
      simde_mm_set_epi64x(0,  4),
      simde_mm_set_epi32(  -35783729,    94498505,  -132871659,   -65242763) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_sra_epi32(test_vec[i].a, test_vec[i].count);
    simde_assert_m128i_i32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_srai_epi16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    int count;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi16( 23582,  20066, -22582,  -6703, -24294, -27424,  18869,  26741),
      9,
      simde_mm_set_epi16(    46,     39,    -45,    -14,    -48,    -54,     36,     52) },
    { simde_mm_set_epi16(-31006,  27597,  15778,  26853,  15128,   5628,  15204, -20146),
      7,
      simde_mm_set_epi16(  -243,    215,    123,    209,    118,     43,    118,   -158) },
    { simde_mm_set_epi16(-14866, -32053,   3649,   1973,  21119, -16403, -16731,  29131),
      8,
      simde_mm_set_epi16(   -59,   -126,     14,      7,     82,    -65,    -66,    113) },
    { simde_mm_set_epi16(-23938,  -8837,  23202,   2346, -22781,  -7725,  30292, -24024),
      11,
      simde_mm_set_epi16(   -12,     -5,     11,      1,    -12,     -4,     14,    -12) },
    { simde_mm_set_epi16( 10586, -31643,  28726, -28181,  23679, -32344,  17987,   4670),
      13,
      simde_mm_set_epi16(     1,     -4,      3,     -4,      2,     -4,      2,      0) },
    { simde_mm_set_epi16(-32292,   5538, -10255, -11002, -14111,  -4210,  17581,  15112),
      12,
      simde_mm_set_epi16(    -8,      1,     -3,     -3,     -4,     -2,      4,      3) },
    { simde_mm_set_epi16(  9274,   5650,  10395, -25251, -30201, -15673,  -5153,   9214),
      1,
      simde_mm_set_epi16(  4637,   2825,   5197, -12626, -15101,  -7837,  -2577,   4607) },
    { simde_mm_set_epi16(-15540,  22158,   4092,   6979,  -6646, -25697, -31903,   5928),
      7,
      simde_mm_set_epi16(  -122,    173,     31,     54,    -52,   -201,   -250,     46) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_srai_epi16(test_vec[i].a, test_vec[i].count);
    simde_assert_m128i_i16(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_srai_epi32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi32(INT32_C( 1376258289), INT32_C(-1706053826), INT32_C(-1453299791), INT32_C( 1957670308)),
      simde_mm_set_epi32(INT32_C(   21504035), INT32_C(  -26657092), INT32_C(  -22707810), INT32_C(   30588598)) },
    { simde_mm_set_epi32(INT32_C( -987178070), INT32_C(-1848596736), INT32_C(  129186724), INT32_C(-1716082103)),
      simde_mm_set_epi32(INT32_C(  -15424658), INT32_C(  -28884324), INT32_C(    2018542), INT32_C(  -26813783)) },
    { simde_mm_set_epi32(INT32_C( -234644460), INT32_C(  433030254), INT32_C(  545613441), INT32_C(-1884669607)),
      simde_mm_set_epi32(INT32_C(   -3666320), INT32_C(    6766097), INT32_C(    8525210), INT32_C(  -29447963)) },
    { simde_mm_set_epi32(INT32_C( -867257848), INT32_C(-1023156928), INT32_C(  967922247), INT32_C(  502198363)),
      simde_mm_set_epi32(INT32_C(  -13550904), INT32_C(  -15986827), INT32_C(   15123785), INT32_C(    7846849)) },
    { simde_mm_set_epi32(INT32_C(-1378148631), INT32_C(  908123340), INT32_C( -632440988), INT32_C(-1285317707)),
      simde_mm_set_epi32(INT32_C(  -21533573), INT32_C(   14189427), INT32_C(   -9881891), INT32_C(  -20083090)) },
    { simde_mm_set_epi32(INT32_C(-1083362196), INT32_C(-1640695627), INT32_C(-1362811468), INT32_C(-1852035314)),
      simde_mm_set_epi32(INT32_C(  -16927535), INT32_C(  -25635870), INT32_C(  -21293930), INT32_C(  -28938052)) },
    { simde_mm_set_epi32(INT32_C(  840318059), INT32_C( 2038482840), INT32_C( -611554758), INT32_C(-1407203570)),
      simde_mm_set_epi32(INT32_C(   13129969), INT32_C(   31851294), INT32_C(   -9555544), INT32_C(  -21987556)) },
    { simde_mm_set_epi32(INT32_C( 1357110356), INT32_C( -162175806), INT32_C( -668288751), INT32_C(  229393371)),
      simde_mm_set_epi32(INT32_C(   21204849), INT32_C(   -2533997), INT32_C(  -10442012), INT32_C(    3584271)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_srai_epi32(test_vec[i].a, 6);
    simde_assert_m128i_i32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_slli_epi16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi16(-29640,  27486, -30681,  22606, -21221,   7042,  -7099, -13884),
      simde_mm_set_epi16( 25024,  23280,  16696, -15760,  26840,  -9200,   8744,  20000) },
    { simde_mm_set_epi16( 15230,  23269, -21546,  15633,   9645, -32001,  -1446,  -7049),
      simde_mm_set_epi16( -9232, -10456,  24240,  -6008,  11624,   6136, -11568,   9144) },
    { simde_mm_set_epi16( -4964,  29371,  -7375,   7185, -25257,  29335,  15023,  23258),
      simde_mm_set_epi16( 25824, -27176,   6536,  -8056,  -5448, -27464, -10888, -10544) },
    { simde_mm_set_epi16(-29984, -17481, -31241,  11397,   2926, -28904, -20560, -32448),
      simde_mm_set_epi16( 22272,  -8776,  12216,  25640,  23408,  30912,  32128,   2560) },
    { simde_mm_set_epi16(-18879,   5889, -27972,  -4500, -12683,  25849,  24809,  26782),
      simde_mm_set_epi16(-19960, -18424, -27168,  29536,  29608,  10184,   1864,  17648) },
    { simde_mm_set_epi16(-12553, -22953,  21946,  -9017, -10462,  -7608,  26015, -24893),
      simde_mm_set_epi16( 30648,  12984, -21040,  -6600, -18160,   4672,  11512,  -2536) },
    { simde_mm_set_epi16( 23545,   -728,  17963, -24889,  18443,  19433, -18886, -28120),
      simde_mm_set_epi16( -8248,  -5824,  12632,  -2504,  16472,  24392, -20016, -28352) },
    { simde_mm_set_epi16(  1885, -18948, -21057,    636,  -9667, -20298,  25111,  30554),
      simde_mm_set_epi16( 15080, -20512,  28152,   5088, -11800, -31312,   4280, -17712) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_slli_epi16(test_vec[i].a, 3);
    simde_assert_m128i_i16(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_srli_epi16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi16(-29640,  27486, -30681,  22606, -21221,   7042,  -7099, -13884),
      simde_mm_set_epi16(  4487,   3435,   4356,   2825,   5539,    880,   7304,   6456) },
    { simde_mm_set_epi16( 15230,  23269, -21546,  15633,   9645, -32001,  -1446,  -7049),
      simde_mm_set_epi16(  1903,   2908,   5498,   1954,   1205,   4191,   8011,   7310) },
    { simde_mm_set_epi16( -4964,  29371,  -7375,   7185, -25257,  29335,  15023,  23258),
      simde_mm_set_epi16(  7571,   3671,   7270,    898,   5034,   3666,   1877,   2907) },
    { simde_mm_set_epi16(-29984, -17481, -31241,  11397,   2926, -28904, -20560, -32448),
      simde_mm_set_epi16(  4444,   6006,   4286,   1424,    365,   4579,   5622,   4136) },
    { simde_mm_set_epi16(-18879,   5889, -27972,  -4500, -12683,  25849,  24809,  26782),
      simde_mm_set_epi16(  5832,    736,   4695,   7629,   6606,   3231,   3101,   3347) },
    { simde_mm_set_epi16(-12553, -22953,  21946,  -9017, -10462,  -7608,  26015, -24893),
      simde_mm_set_epi16(  6622,   5322,   2743,   7064,   6884,   7241,   3251,   5080) },
    { simde_mm_set_epi16( 23545,   -728,  17963, -24889,  18443,  19433, -18886, -28120),
      simde_mm_set_epi16(  2943,   8101,   2245,   5080,   2305,   2429,   5831,   4677) },
    { simde_mm_set_epi16(  1885, -18948, -21057,    636,  -9667, -20298,  25111,  30554),
      simde_mm_set_epi16(   235,   5823,   5559,     79,   6983,   5654,   3138,   3819) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_srli_epi16(test_vec[i].a, 3);
    simde_assert_m128i_i16(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_slli_epi32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi32(-1285208672,  1618695439, -1484382898,    97979804),
      simde_mm_set_epi32( 1822995456,   258646496,  -255612480, -1159613568) },
    { simde_mm_set_epi32( -215274446, -1750972712, -2134111648,  -338295419),
      simde_mm_set_epi32( 1701152320,  -196551936,   427904000,  2059448480) },
    { simde_mm_set_epi32(  406577052, -1272707531,  -128013424,  1090211344),
      simde_mm_set_epi32(  125563776, -2071935328,   198537728,   527024640) },
    { simde_mm_set_epi32( -547315834,   386023226,   789460810, -2097507270),
      simde_mm_set_epi32( -334237504,  -532158656,  -507057856,  1599244096) },
    { simde_mm_set_epi32( 1943314584,   126005183,   199695502, -1431967820),
      simde_mm_set_epi32( 2056524544,  -262801440,  2095288768,  1421670016) },
    { simde_mm_set_epi32( 1899687789, -1162493730,  1537811436,   825134965),
      simde_mm_set_epi32(  660467104,  1454906304,  1965325696,   634515104) },
    { simde_mm_set_epi32(-1452393292, -1781210226, -1307434085, -2039047771),
      simde_mm_set_epi32(  768054912, -1164152384,  1111782240,  -825019232) },
    { simde_mm_set_epi32(-1646930836,   816193989, -1662050152,   347461227),
      simde_mm_set_epi32(-1162179200,   348403872, -1645997312, -1766142624) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_slli_epi32(test_vec[i].a, 5);
    simde_assert_m128i_i32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_srli_epi32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi32(   71624167,   617025209,  -286267780, -1151099730),
      simde_mm_set_epi32(    2238255,    19282037,   125271859,    98245861) },
    { simde_mm_set_epi32(-1660949423,    45505817,  1892774959,  -917815961),
      simde_mm_set_epi32(   82313058,     1422056,    59149217,   105535979) },
    { simde_mm_set_epi32( 1642659615,  -757986143, -1891097222,   940303240),
      simde_mm_set_epi32(   51333112,   110530661,    75120939,    29384476) },
    { simde_mm_set_epi32( 1761409447,   115333600,  -589319110, -1530115830),
      simde_mm_set_epi32(   55044045,     3604175,   115801505,    86401608) },
    { simde_mm_set_epi32( -502944468, -1500485927,    32222499,  1115657749),
      simde_mm_set_epi32(  118500713,    87327542,     1006953,    34864304) },
    { simde_mm_set_epi32( -545012251,   924477372, -1883097200,  1327167226),
      simde_mm_set_epi32(  117186095,    28889917,    75370940,    41473975) },
    { simde_mm_set_epi32(  995448668,   377764585, -1462273550,  1306007963),
      simde_mm_set_epi32(   31107770,    11805143,    88521679,    40812748) },
    { simde_mm_set_epi32( 1991954175,   665906947,  -606406775,  1678465696),
      simde_mm_set_epi32(   62248567,    20809592,   115267516,    52452053) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_srli_epi32(test_vec[i].a, 5);
    simde_assert_m128i_i32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_slli_epi64(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi64x(INT64_C(-2315072815474662386), INT64_C( 6072154117607221746)),
      simde_mm_set_epi64x(INT64_C(-1181415201403959552), INT64_C( 2472475957923215616)) },
    { simde_mm_set_epi64x(INT64_C(-2150345518249743204), INT64_C( 3180241355952247476)),
      simde_mm_set_epi64x(INT64_C( 1456934769676144128), INT64_C( 1242523940277541376)) },
    { simde_mm_set_epi64x(INT64_C( 6492638483912689614), INT64_C( 7722522576063149658)),
      simde_mm_set_epi64x(INT64_C(  954242623894447872), INT64_C(-7641290244232631040)) },
    { simde_mm_set_epi64x(INT64_C(-3437371876454060839), INT64_C(-7472017034411611746)),
      simde_mm_set_epi64x(INT64_C( 2738257582909451392), INT64_C( 2812511428210380544)) },
    { simde_mm_set_epi64x(INT64_C(-2994435188669454779), INT64_C(-4713226846452985822)),
      simde_mm_set_epi64x(INT64_C( 4093921398210372224), INT64_C( 5449518086433018112)) },
    { simde_mm_set_epi64x(INT64_C(-1348831542752523511), INT64_C(-2794326256527200530)),
      simde_mm_set_epi64x(INT64_C(-6629740808937044864), INT64_C(-7185623435000187136)) },
    { simde_mm_set_epi64x(INT64_C(-5602242705933140185), INT64_C( 6492190109232091873)),
      simde_mm_set_epi64x(INT64_C( 2335952515230569344), INT64_C(  896850664777937024)) },
    { simde_mm_set_epi64x(INT64_C( 8003331601608352009), INT64_C(-5520322068937257120)),
      simde_mm_set_epi64x(INT64_C(-8591223121865833344), INT64_C(-5624950023005949952)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_slli_epi64(test_vec[i].a, 7);
    simde_assert_m128i_i32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_srli_epi64(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi64x(INT64_C(-2315072815474662386), INT64_C( 6072154117607221746)),
      simde_mm_set_epi64x(INT64_C(  126028681704960072), INT64_C(   47438704043806419)) },
    { simde_mm_set_epi64x(INT64_C(-2150345518249743204), INT64_C( 3180241355952247476)),
      simde_mm_set_epi64x(INT64_C(  127315613714529753), INT64_C(   24845635593376933)) },
    { simde_mm_set_epi64x(INT64_C( 6492638483912689614), INT64_C( 7722522576063149658)),
      simde_mm_set_epi64x(INT64_C(   50723738155567887), INT64_C(   60332207625493356)) },
    { simde_mm_set_epi64x(INT64_C(-3437371876454060839), INT64_C(-7472017034411611746)),
      simde_mm_set_epi64x(INT64_C(  117260720291058521), INT64_C(   85740054994515155)) },
    { simde_mm_set_epi64x(INT64_C(-2994435188669454779), INT64_C(-4713226846452985822)),
      simde_mm_set_epi64x(INT64_C(  120721163164375756), INT64_C(  107293103337941920)) },
    { simde_mm_set_epi64x(INT64_C(-1348831542752523511), INT64_C(-2794326256527200530)),
      simde_mm_set_epi64x(INT64_C(  133577441648101782), INT64_C(  122284514196737117)) },
    { simde_mm_set_epi64x(INT64_C(-5602242705933140185), INT64_C( 6492190109232091873)),
      simde_mm_set_epi64x(INT64_C(  100347666935753214), INT64_C(   50720235228375717)) },
    { simde_mm_set_epi64x(INT64_C( 8003331601608352009), INT64_C(-5520322068937257120)),
      simde_mm_set_epi64x(INT64_C(   62526028137565250), INT64_C(  100987671912283550)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r;
    simde__m128i zeros = simde_mm_set1_epi64x(INT64_C(0));

    r = simde_mm_srli_epi64(test_vec[i].a, -1);
    simde_assert_m128i_i32(r, ==, zeros);

    r = simde_mm_srli_epi64(test_vec[i].a, 0);
    simde_assert_m128i_i32(r, ==, test_vec[i].a);

    r = simde_mm_srli_epi64(test_vec[i].a, 7);
    simde_assert_m128i_i32(r, ==, test_vec[i].r);

    r = simde_mm_srli_epi64(test_vec[i].a, 64);
    simde_assert_m128i_i32(r, ==, zeros);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_store_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128d a;
    SIMDE_ALIGN(16) simde_float64 r[2];
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  825.31), SIMDE_FLOAT64_C(  176.75)),
      {SIMDE_FLOAT64_C(   176.75), SIMDE_FLOAT64_C(  825.31) } },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -248.58), SIMDE_FLOAT64_C( -171.93)),
      {SIMDE_FLOAT64_C(  -171.93), SIMDE_FLOAT64_C( -248.58) } },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  419.77), SIMDE_FLOAT64_C(  712.85)),
      {SIMDE_FLOAT64_C(   712.85), SIMDE_FLOAT64_C(  419.77) } },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  785.55), SIMDE_FLOAT64_C(   78.74)),
      {SIMDE_FLOAT64_C(    78.74), SIMDE_FLOAT64_C(  785.55) } },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -963.92), SIMDE_FLOAT64_C(  614.28)),
      {SIMDE_FLOAT64_C(   614.28), SIMDE_FLOAT64_C( -963.92) } },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  624.62), SIMDE_FLOAT64_C( -260.28)),
      {SIMDE_FLOAT64_C(  -260.28), SIMDE_FLOAT64_C(  624.62) } },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -178.24), SIMDE_FLOAT64_C(  945.12)),
      {SIMDE_FLOAT64_C(   945.12), SIMDE_FLOAT64_C( -178.24) } },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -271.60), SIMDE_FLOAT64_C( -674.20)),
      {SIMDE_FLOAT64_C(  -674.20), SIMDE_FLOAT64_C( -271.60) } }
  };

  for (size_t i = 0 ; i < sizeof(test_vec) / sizeof(test_vec[0]) ; i++) {
    SIMDE_ALIGN(16) simde_float64 r[2];
    simde_mm_store_pd(r, test_vec[i].a);
    simde_assert_f32v_equal(simde_float64, 2, test_vec[i].r, r, 4);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_store_pd1(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128d a;
    SIMDE_ALIGN(16) simde_float64 r[2];
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  278.50), SIMDE_FLOAT64_C(  554.87)),
      {SIMDE_FLOAT64_C(   554.87), SIMDE_FLOAT64_C(  554.87) } },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -348.28), SIMDE_FLOAT64_C(  361.13)),
      {SIMDE_FLOAT64_C(   361.13), SIMDE_FLOAT64_C(  361.13) } },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -701.38), SIMDE_FLOAT64_C(  708.23)),
      {SIMDE_FLOAT64_C(   708.23), SIMDE_FLOAT64_C(  708.23) } },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -362.77), SIMDE_FLOAT64_C( -574.16)),
      {SIMDE_FLOAT64_C(  -574.16), SIMDE_FLOAT64_C( -574.16) } },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  420.63), SIMDE_FLOAT64_C(  850.70)),
      {SIMDE_FLOAT64_C(   850.70), SIMDE_FLOAT64_C(  850.70) } },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -223.78), SIMDE_FLOAT64_C(  845.58)),
      {SIMDE_FLOAT64_C(   845.58), SIMDE_FLOAT64_C(  845.58) } },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  948.70), SIMDE_FLOAT64_C(  544.62)),
      {SIMDE_FLOAT64_C(   544.62), SIMDE_FLOAT64_C(  544.62) } },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -216.79), SIMDE_FLOAT64_C( -830.24)),
      {SIMDE_FLOAT64_C(  -830.24), SIMDE_FLOAT64_C( -830.24) } }
  };

  for (size_t i = 0 ; i < sizeof(test_vec) / sizeof(test_vec[0]) ; i++) {
    SIMDE_ALIGN(16) simde_float64 r[2];
    simde_mm_store_pd1(r, test_vec[i].a);
    simde_assert_f32v_equal(simde_float64, 2, test_vec[i].r, r, 4);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_store_sd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128d a;
    SIMDE_ALIGN(16) simde_float64 b[2];
    SIMDE_ALIGN(16) simde_float64 r[2];
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -380.32), SIMDE_FLOAT64_C(  589.10)),
      {SIMDE_FLOAT64_C(  -886.38), SIMDE_FLOAT64_C(  706.27) },
      {SIMDE_FLOAT64_C(   589.10), SIMDE_FLOAT64_C(  706.27) } },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(   97.55), SIMDE_FLOAT64_C( -921.93)),
      {SIMDE_FLOAT64_C(   175.08), SIMDE_FLOAT64_C( -498.43) },
      {SIMDE_FLOAT64_C(  -921.93), SIMDE_FLOAT64_C( -498.43) } },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -962.76), SIMDE_FLOAT64_C( -267.73)),
      {SIMDE_FLOAT64_C(  -505.37), SIMDE_FLOAT64_C( -729.92) },
      {SIMDE_FLOAT64_C(  -267.73), SIMDE_FLOAT64_C( -729.92) } },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  154.59), SIMDE_FLOAT64_C( -829.83)),
      {SIMDE_FLOAT64_C(   141.33), SIMDE_FLOAT64_C(  657.26) },
      {SIMDE_FLOAT64_C(  -829.83), SIMDE_FLOAT64_C(  657.26) } },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -623.49), SIMDE_FLOAT64_C( -306.50)),
      {SIMDE_FLOAT64_C(  -540.89), SIMDE_FLOAT64_C(  213.61) },
      {SIMDE_FLOAT64_C(  -306.50), SIMDE_FLOAT64_C(  213.61) } },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  708.57), SIMDE_FLOAT64_C( -626.05)),
      {SIMDE_FLOAT64_C(  -658.64), SIMDE_FLOAT64_C(  310.68) },
      {SIMDE_FLOAT64_C(  -626.05), SIMDE_FLOAT64_C(  310.68) } },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(    7.10), SIMDE_FLOAT64_C(   84.59)),
      {SIMDE_FLOAT64_C(   191.88), SIMDE_FLOAT64_C( -258.06) },
      {SIMDE_FLOAT64_C(    84.59), SIMDE_FLOAT64_C( -258.06) } },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  399.99), SIMDE_FLOAT64_C( -337.50)),
      {SIMDE_FLOAT64_C(   733.91), SIMDE_FLOAT64_C( -756.49) },
      {SIMDE_FLOAT64_C(  -337.50), SIMDE_FLOAT64_C( -756.49) } }
  };

  for (size_t i = 0 ; i < sizeof(test_vec) / sizeof(test_vec[0]) ; i++) {
    simde_float64 SIMDE_ALIGN(16) r[2];
    memcpy(r, &(test_vec[i].b), sizeof(test_vec[i].b));
    simde_mm_store_sd(r, test_vec[i].a);
    simde_assert_f32v_equal(simde_float64, 2, test_vec[i].r, r, 4);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_store_si128(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi32(INT32_C(-1969078312), INT32_C( 1646650233), INT32_C(-1190611301), INT32_C(  889904733)),
      simde_mm_set_epi32(INT32_C(-1969078312), INT32_C( 1646650233), INT32_C(-1190611301), INT32_C(  889904733)) },
    { simde_mm_set_epi32(INT32_C(  361491951), INT32_C(-1497327260), INT32_C(-2092062445), INT32_C(-1242536811)),
      simde_mm_set_epi32(INT32_C(  361491951), INT32_C(-1497327260), INT32_C(-2092062445), INT32_C(-1242536811)) },
    { simde_mm_set_epi32(INT32_C(  790325756), INT32_C( -295457696), INT32_C(   30297459), INT32_C(  860807687)),
      simde_mm_set_epi32(INT32_C(  790325756), INT32_C( -295457696), INT32_C(   30297459), INT32_C(  860807687)) },
    { simde_mm_set_epi32(INT32_C(-1228048681), INT32_C( 1236867704), INT32_C(-1927827785), INT32_C(-1233913343)),
      simde_mm_set_epi32(INT32_C(-1228048681), INT32_C( 1236867704), INT32_C(-1927827785), INT32_C(-1233913343)) },
    { simde_mm_set_epi32(INT32_C( 1007412231), INT32_C( -296710614), INT32_C(-1416317108), INT32_C( -839008134)),
      simde_mm_set_epi32(INT32_C( 1007412231), INT32_C( -296710614), INT32_C(-1416317108), INT32_C( -839008134)) },
    { simde_mm_set_epi32(INT32_C( 1325410731), INT32_C( 2049780007), INT32_C(  190337706), INT32_C( 1948643128)),
      simde_mm_set_epi32(INT32_C( 1325410731), INT32_C( 2049780007), INT32_C(  190337706), INT32_C( 1948643128)) },
    { simde_mm_set_epi32(INT32_C(-1295145224), INT32_C( -913388140), INT32_C(-1185110338), INT32_C(  127220065)),
      simde_mm_set_epi32(INT32_C(-1295145224), INT32_C( -913388140), INT32_C(-1185110338), INT32_C(  127220065)) },
    { simde_mm_set_epi32(INT32_C(  479405479), INT32_C(  641965302), INT32_C(-1100092667), INT32_C( 1837148945)),
      simde_mm_set_epi32(INT32_C(  479405479), INT32_C(  641965302), INT32_C(-1100092667), INT32_C( 1837148945)) }
  };

  for (size_t i = 0 ; i < sizeof(test_vec) / sizeof(test_vec[0]) ; i++) {
    simde__m128i r;
    simde_mm_store_si128(&r, test_vec[i].a);
    simde_assert_m128i_i32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_storeh_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128d a;
    SIMDE_ALIGN(16) simde_float64 b[2];
    SIMDE_ALIGN(16) simde_float64 r[2];
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -154.79), SIMDE_FLOAT64_C(  689.59)),
      {SIMDE_FLOAT64_C(  -986.30), SIMDE_FLOAT64_C( -463.82) },
      {SIMDE_FLOAT64_C(  -154.79), SIMDE_FLOAT64_C( -463.82) } },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  944.07), SIMDE_FLOAT64_C( -598.47)),
      {SIMDE_FLOAT64_C(  -514.42), SIMDE_FLOAT64_C(  652.02) },
      {SIMDE_FLOAT64_C(   944.07), SIMDE_FLOAT64_C(  652.02) } },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  -34.72), SIMDE_FLOAT64_C( -771.52)),
      {SIMDE_FLOAT64_C(   343.91), SIMDE_FLOAT64_C( -171.75) },
      {SIMDE_FLOAT64_C(   -34.72), SIMDE_FLOAT64_C( -171.75) } },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  305.40), SIMDE_FLOAT64_C( -671.87)),
      {SIMDE_FLOAT64_C(  -579.65), SIMDE_FLOAT64_C( -985.37) },
      {SIMDE_FLOAT64_C(   305.40), SIMDE_FLOAT64_C( -985.37) } },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  173.51), SIMDE_FLOAT64_C(  643.06)),
      {SIMDE_FLOAT64_C(   794.84), SIMDE_FLOAT64_C(  233.08) },
      {SIMDE_FLOAT64_C(   173.51), SIMDE_FLOAT64_C(  233.08) } },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -130.21), SIMDE_FLOAT64_C( -290.59)),
      {SIMDE_FLOAT64_C(   584.05), SIMDE_FLOAT64_C( -167.57) },
      {SIMDE_FLOAT64_C(  -130.21), SIMDE_FLOAT64_C( -167.57) } },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -759.48), SIMDE_FLOAT64_C(  428.70)),
      {SIMDE_FLOAT64_C(    36.98), SIMDE_FLOAT64_C( -189.97) },
      {SIMDE_FLOAT64_C(  -759.48), SIMDE_FLOAT64_C( -189.97) } },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  222.49), SIMDE_FLOAT64_C(  621.71)),
      {SIMDE_FLOAT64_C(  -467.95), SIMDE_FLOAT64_C( -910.73) },
      {SIMDE_FLOAT64_C(   222.49), SIMDE_FLOAT64_C( -910.73) } }
  };

  for (size_t i = 0 ; i < sizeof(test_vec) / sizeof(test_vec[0]) ; i++) {
    SIMDE_ALIGN(16) simde_float64 r[2];
    memcpy(r, &(test_vec[i].b), sizeof(test_vec[i].b));
    simde_mm_storeh_pd(r, test_vec[i].a);
    simde_assert_f32v_equal(simde_float64, 2, test_vec[i].r, r, 4);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_storel_epi64(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi64x(INT64_C(-8572402204481175152), INT64_C(-3565447379630862345)),
      simde_mm_set_epi64x(INT64_C(-5836787758646654491), INT64_C(  978262207997446536)),
      simde_mm_set_epi64x(INT64_C(-5836787758646654491), INT64_C(-3565447379630862345)) },
    { simde_mm_set_epi64x(INT64_C(  883894259135204982), INT64_C(-6785295924552521928)),
      simde_mm_set_epi64x(INT64_C( 5751908210058630765), INT64_C(-7999305285706001942)),
      simde_mm_set_epi64x(INT64_C( 5751908210058630765), INT64_C(-6785295924552521928)) },
    { simde_mm_set_epi64x(INT64_C( 4991496111910955453), INT64_C(-1947231678451890517)),
      simde_mm_set_epi64x(INT64_C( 1054715717267865334), INT64_C(-5199938312574175167)),
      simde_mm_set_epi64x(INT64_C( 1054715717267865334), INT64_C(-1947231678451890517)) },
    { simde_mm_set_epi64x(INT64_C(-6916286228894702079), INT64_C(-7888320918323423602)),
      simde_mm_set_epi64x(INT64_C(-4560271213984560857), INT64_C( 1030486561279856923)),
      simde_mm_set_epi64x(INT64_C(-4560271213984560857), INT64_C(-7888320918323423602)) },
    { simde_mm_set_epi64x(INT64_C(-5516402797122916761), INT64_C( 8516393373254709766)),
      simde_mm_set_epi64x(INT64_C(-8984432431227422893), INT64_C(-1285772213781786319)),
      simde_mm_set_epi64x(INT64_C(-8984432431227422893), INT64_C( 8516393373254709766)) },
    { simde_mm_set_epi64x(INT64_C( 1537881028582424966), INT64_C( 3855597324285413517)),
      simde_mm_set_epi64x(INT64_C(-1087659369158402202), INT64_C( 5504181592152866903)),
      simde_mm_set_epi64x(INT64_C(-1087659369158402202), INT64_C( 3855597324285413517)) },
    { simde_mm_set_epi64x(INT64_C(-1003754336566127903), INT64_C( 3155788073225494266)),
      simde_mm_set_epi64x(INT64_C( 7014294951579480267), INT64_C(-6777837266490471507)),
      simde_mm_set_epi64x(INT64_C( 7014294951579480267), INT64_C( 3155788073225494266)) },
    { simde_mm_set_epi64x(INT64_C( 7343239871058385173), INT64_C(-8089093160963830084)),
      simde_mm_set_epi64x(INT64_C(-7180996141698966448), INT64_C( 1747758344108352756)),
      simde_mm_set_epi64x(INT64_C(-7180996141698966448), INT64_C(-8089093160963830084)) }
  };

  for (size_t i = 0 ; i < sizeof(test_vec) / sizeof(test_vec[0]) ; i++) {
    simde__m128i r;
    memcpy(&r, &(test_vec[i].b), sizeof(r));
    simde_mm_storel_epi64(&r, test_vec[i].a);
    simde_assert_m128i_i64(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_storel_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128d a;
    SIMDE_ALIGN(16) simde_float64 b[2];
    SIMDE_ALIGN(16) simde_float64 r[2];
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -887.08), SIMDE_FLOAT64_C( -520.70)),
      {SIMDE_FLOAT64_C(  -258.49), SIMDE_FLOAT64_C(  913.00) },
      {SIMDE_FLOAT64_C(  -520.70), SIMDE_FLOAT64_C(  913.00) } },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  724.04), SIMDE_FLOAT64_C( -774.49)),
      {SIMDE_FLOAT64_C(   557.37), SIMDE_FLOAT64_C( -701.13) },
      {SIMDE_FLOAT64_C(  -774.49), SIMDE_FLOAT64_C( -701.13) } },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -366.90), SIMDE_FLOAT64_C( -168.25)),
      {SIMDE_FLOAT64_C(   485.14), SIMDE_FLOAT64_C(  500.94) },
      {SIMDE_FLOAT64_C(  -168.25), SIMDE_FLOAT64_C(  500.94) } },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -783.51), SIMDE_FLOAT64_C( -187.73)),
      {SIMDE_FLOAT64_C(  -391.92), SIMDE_FLOAT64_C( -506.74) },
      {SIMDE_FLOAT64_C(  -187.73), SIMDE_FLOAT64_C( -506.74) } },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  -50.27), SIMDE_FLOAT64_C( -405.84)),
      {SIMDE_FLOAT64_C(  -733.12), SIMDE_FLOAT64_C( -697.37) },
      {SIMDE_FLOAT64_C(  -405.84), SIMDE_FLOAT64_C( -697.37) } },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -773.31), SIMDE_FLOAT64_C( -470.65)),
      {SIMDE_FLOAT64_C(   738.01), SIMDE_FLOAT64_C( -908.23) },
      {SIMDE_FLOAT64_C(  -470.65), SIMDE_FLOAT64_C( -908.23) } },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  -43.07), SIMDE_FLOAT64_C( -143.29)),
      {SIMDE_FLOAT64_C(   985.95), SIMDE_FLOAT64_C(   19.70) },
      {SIMDE_FLOAT64_C(  -143.29), SIMDE_FLOAT64_C(   19.70) } },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  649.59), SIMDE_FLOAT64_C( -925.70)),
      {SIMDE_FLOAT64_C(   519.96), SIMDE_FLOAT64_C(  348.23) },
      {SIMDE_FLOAT64_C(  -925.70), SIMDE_FLOAT64_C(  348.23) } }
  };

  for (size_t i = 0 ; i < sizeof(test_vec) / sizeof(test_vec[0]) ; i++) {
    SIMDE_ALIGN(16) simde_float64 r[2];
    memcpy(r, &(test_vec[i].b), sizeof(test_vec[i].b));
    simde_mm_storel_pd(r, test_vec[i].a);
    simde_assert_f32v_equal(simde_float64, 2, test_vec[i].r, r, 4);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_storer_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128d a;
    SIMDE_ALIGN(16) simde_float64 b[2];
    SIMDE_ALIGN(16) simde_float64 r[2];
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  765.90), SIMDE_FLOAT64_C( -392.20)),
      {SIMDE_FLOAT64_C(  -898.96), SIMDE_FLOAT64_C(  810.87) },
      {SIMDE_FLOAT64_C(   765.90), SIMDE_FLOAT64_C( -392.20) } },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  848.80), SIMDE_FLOAT64_C(  -20.45)),
      {SIMDE_FLOAT64_C(  -298.33), SIMDE_FLOAT64_C(  199.86) },
      {SIMDE_FLOAT64_C(   848.80), SIMDE_FLOAT64_C(  -20.45) } },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -770.38), SIMDE_FLOAT64_C(   73.29)),
      {SIMDE_FLOAT64_C(  -471.45), SIMDE_FLOAT64_C(   85.53) },
      {SIMDE_FLOAT64_C(  -770.38), SIMDE_FLOAT64_C(   73.29) } },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  181.32), SIMDE_FLOAT64_C( -528.68)),
      {SIMDE_FLOAT64_C(   925.12), SIMDE_FLOAT64_C(  -79.25) },
      {SIMDE_FLOAT64_C(   181.32), SIMDE_FLOAT64_C( -528.68) } },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  786.51), SIMDE_FLOAT64_C( -396.45)),
      {SIMDE_FLOAT64_C(  -196.75), SIMDE_FLOAT64_C( -493.37) },
      {SIMDE_FLOAT64_C(   786.51), SIMDE_FLOAT64_C( -396.45) } },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  379.82), SIMDE_FLOAT64_C( -482.63)),
      {SIMDE_FLOAT64_C(   356.61), SIMDE_FLOAT64_C(    6.76) },
      {SIMDE_FLOAT64_C(   379.82), SIMDE_FLOAT64_C( -482.63) } },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -597.31), SIMDE_FLOAT64_C( -427.66)),
      {SIMDE_FLOAT64_C(  -787.49), SIMDE_FLOAT64_C(  322.82) },
      {SIMDE_FLOAT64_C(  -597.31), SIMDE_FLOAT64_C( -427.66) } },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  515.42), SIMDE_FLOAT64_C(  801.05)),
      {SIMDE_FLOAT64_C(  -892.50), SIMDE_FLOAT64_C(  794.29) },
      {SIMDE_FLOAT64_C(   515.42), SIMDE_FLOAT64_C(  801.05) } }
  };

  for (size_t i = 0 ; i < sizeof(test_vec) / sizeof(test_vec[0]) ; i++) {
    SIMDE_ALIGN(16) simde_float64 r[2];
    memcpy(r, &(test_vec[i].b), sizeof(test_vec[i].b));
    simde_mm_storer_pd(r, test_vec[i].a);
    simde_assert_f32v_equal(simde_float64, 2, test_vec[i].r, r, 4);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_storeu_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128d a;
    simde_float64 b[2];
    simde_float64 r[2];
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -787.29), SIMDE_FLOAT64_C(  410.40)),
      {SIMDE_FLOAT64_C(   579.61), SIMDE_FLOAT64_C( -320.32) },
      {SIMDE_FLOAT64_C(   410.40), SIMDE_FLOAT64_C( -787.29) } },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  944.41), SIMDE_FLOAT64_C( -149.27)),
      {SIMDE_FLOAT64_C(   850.87), SIMDE_FLOAT64_C( -993.24) },
      {SIMDE_FLOAT64_C(  -149.27), SIMDE_FLOAT64_C(  944.41) } },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -415.98), SIMDE_FLOAT64_C( -916.88)),
      {SIMDE_FLOAT64_C(   966.39), SIMDE_FLOAT64_C( -183.52) },
      {SIMDE_FLOAT64_C(  -916.88), SIMDE_FLOAT64_C( -415.98) } },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  431.98), SIMDE_FLOAT64_C( -691.20)),
      {SIMDE_FLOAT64_C(  -659.73), SIMDE_FLOAT64_C(  -34.04) },
      {SIMDE_FLOAT64_C(  -691.20), SIMDE_FLOAT64_C(  431.98) } },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -483.35), SIMDE_FLOAT64_C(  766.13)),
      {SIMDE_FLOAT64_C(  -638.61), SIMDE_FLOAT64_C(  157.38) },
      {SIMDE_FLOAT64_C(   766.13), SIMDE_FLOAT64_C( -483.35) } },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  386.12), SIMDE_FLOAT64_C(  330.08)),
      {SIMDE_FLOAT64_C(   588.80), SIMDE_FLOAT64_C( -111.35) },
      {SIMDE_FLOAT64_C(   330.08), SIMDE_FLOAT64_C(  386.12) } },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(   45.12), SIMDE_FLOAT64_C(  964.86)),
      {SIMDE_FLOAT64_C(   199.95), SIMDE_FLOAT64_C(  998.07) },
      {SIMDE_FLOAT64_C(   964.86), SIMDE_FLOAT64_C(   45.12) } },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  -30.76), SIMDE_FLOAT64_C( -723.78)),
      {SIMDE_FLOAT64_C(    -8.78), SIMDE_FLOAT64_C(  410.81) },
      {SIMDE_FLOAT64_C(  -723.78), SIMDE_FLOAT64_C(  -30.76) } }
  };

  for (size_t i = 0 ; i < sizeof(test_vec) / sizeof(test_vec[0]) ; i++) {
    SIMDE_ALIGN(16) simde_float64 r[2];
    memcpy(r, &(test_vec[i].b), sizeof(test_vec[i].b));
    simde_mm_storeu_pd(r, test_vec[i].a);
    simde_assert_f32v_equal(simde_float64, 2, test_vec[i].r, r, 4);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_storeu_si128(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi32(INT32_C(  559775826), INT32_C( -953548695), INT32_C(  811731668), INT32_C(  717258119)),
      simde_mm_set_epi32(INT32_C(  559775826), INT32_C( -953548695), INT32_C(  811731668), INT32_C(  717258119)) },
    { simde_mm_set_epi32(INT32_C( -819991397), INT32_C(-1367017296), INT32_C( 1998597245), INT32_C( -194600747)),
      simde_mm_set_epi32(INT32_C( -819991397), INT32_C(-1367017296), INT32_C( 1998597245), INT32_C( -194600747)) },
    { simde_mm_set_epi32(INT32_C(-1983970353), INT32_C( 1036245224), INT32_C( 1208146280), INT32_C( 2086212378)),
      simde_mm_set_epi32(INT32_C(-1983970353), INT32_C( 1036245224), INT32_C( 1208146280), INT32_C( 2086212378)) },
    { simde_mm_set_epi32(INT32_C(-1115487208), INT32_C( 1901412157), INT32_C( -373768038), INT32_C( 1379732008)),
      simde_mm_set_epi32(INT32_C(-1115487208), INT32_C( 1901412157), INT32_C( -373768038), INT32_C( 1379732008)) },
    { simde_mm_set_epi32(INT32_C( -772363216), INT32_C( 1208166493), INT32_C( 2006133231), INT32_C( -567476934)),
      simde_mm_set_epi32(INT32_C( -772363216), INT32_C( 1208166493), INT32_C( 2006133231), INT32_C( -567476934)) },
    { simde_mm_set_epi32(INT32_C( -117502444), INT32_C(  175751722), INT32_C(-1353399970), INT32_C( -281466966)),
      simde_mm_set_epi32(INT32_C( -117502444), INT32_C(  175751722), INT32_C(-1353399970), INT32_C( -281466966)) },
    { simde_mm_set_epi32(INT32_C( 2118723593), INT32_C(-1657083210), INT32_C( 1907402314), INT32_C(  669913338)),
      simde_mm_set_epi32(INT32_C( 2118723593), INT32_C(-1657083210), INT32_C( 1907402314), INT32_C(  669913338)) },
    { simde_mm_set_epi32(INT32_C(  372135232), INT32_C( 1779530333), INT32_C(-1088754891), INT32_C( 1773872281)),
      simde_mm_set_epi32(INT32_C(  372135232), INT32_C( 1779530333), INT32_C(-1088754891), INT32_C( 1773872281)) }
  };

  for (size_t i = 0 ; i < sizeof(test_vec) / sizeof(test_vec[0]) ; i++) {
    simde__m128i r;
    simde_mm_storeu_si128(&r, test_vec[i].a);
    simde_assert_m128i_i64(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_stream_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128d a;
    SIMDE_ALIGN(16) simde_float64 r[2];
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -749.31), SIMDE_FLOAT64_C( -483.97)),
      {SIMDE_FLOAT64_C(  -483.97), SIMDE_FLOAT64_C( -749.31) } },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  587.52), SIMDE_FLOAT64_C( -903.15)),
      {SIMDE_FLOAT64_C(  -903.15), SIMDE_FLOAT64_C(  587.52) } },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -515.61), SIMDE_FLOAT64_C(  144.37)),
      {SIMDE_FLOAT64_C(   144.37), SIMDE_FLOAT64_C( -515.61) } },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -183.60), SIMDE_FLOAT64_C(  483.36)),
      {SIMDE_FLOAT64_C(   483.36), SIMDE_FLOAT64_C( -183.60) } },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(   33.37), SIMDE_FLOAT64_C( -802.26)),
      {SIMDE_FLOAT64_C(  -802.26), SIMDE_FLOAT64_C(   33.37) } },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -131.42), SIMDE_FLOAT64_C( -156.48)),
      {SIMDE_FLOAT64_C(  -156.48), SIMDE_FLOAT64_C( -131.42) } },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -317.87), SIMDE_FLOAT64_C(  140.87)),
      {SIMDE_FLOAT64_C(   140.87), SIMDE_FLOAT64_C( -317.87) } },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  924.07), SIMDE_FLOAT64_C(  709.42)),
      {SIMDE_FLOAT64_C(   709.42), SIMDE_FLOAT64_C(  924.07) } }
  };

  for (size_t i = 0 ; i < sizeof(test_vec) / sizeof(test_vec[0]) ; i++) {
    SIMDE_ALIGN(16) simde_float64 r[2];
    simde_mm_stream_pd(r, test_vec[i].a);
    simde_assert_f64v_close(simde_float64, 2,r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_stream_si128(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi32(INT32_C(   34091183), INT32_C(  572850908), INT32_C(  428781754), INT32_C(-1984722387)),
      simde_mm_set_epi32(INT32_C(   34091183), INT32_C(  572850908), INT32_C(  428781754), INT32_C(-1984722387)) },
    { simde_mm_set_epi32(INT32_C( 2059236852), INT32_C(  436410728), INT32_C(  338757718), INT32_C( 1985336145)),
      simde_mm_set_epi32(INT32_C( 2059236852), INT32_C(  436410728), INT32_C(  338757718), INT32_C( 1985336145)) },
    { simde_mm_set_epi32(INT32_C( -559686487), INT32_C(  981390363), INT32_C(  629822759), INT32_C(   26629572)),
      simde_mm_set_epi32(INT32_C( -559686487), INT32_C(  981390363), INT32_C(  629822759), INT32_C(   26629572)) },
    { simde_mm_set_epi32(INT32_C( 1401959784), INT32_C( -900492538), INT32_C( -328421218), INT32_C(  452144845)),
      simde_mm_set_epi32(INT32_C( 1401959784), INT32_C( -900492538), INT32_C( -328421218), INT32_C(  452144845)) },
    { simde_mm_set_epi32(INT32_C( 1914664610), INT32_C( 1467736241), INT32_C(-2062482935), INT32_C(-1765775255)),
      simde_mm_set_epi32(INT32_C( 1914664610), INT32_C( 1467736241), INT32_C(-2062482935), INT32_C(-1765775255)) },
    { simde_mm_set_epi32(INT32_C(  659730578), INT32_C(  874862437), INT32_C( -487086426), INT32_C(-1161523548)),
      simde_mm_set_epi32(INT32_C(  659730578), INT32_C(  874862437), INT32_C( -487086426), INT32_C(-1161523548)) },
    { simde_mm_set_epi32(INT32_C( 1195652072), INT32_C( -415424127), INT32_C(   77100736), INT32_C( 1699618155)),
      simde_mm_set_epi32(INT32_C( 1195652072), INT32_C( -415424127), INT32_C(   77100736), INT32_C( 1699618155)) },
    { simde_mm_set_epi32(INT32_C( 1626943139), INT32_C( 1327578602), INT32_C(-1477047999), INT32_C( 1569415359)),
      simde_mm_set_epi32(INT32_C( 1626943139), INT32_C( 1327578602), INT32_C(-1477047999), INT32_C( 1569415359)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r;
    simde_mm_stream_si128(&r, test_vec[i].a);
    simde_assert_m128i_i32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_stream_si32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    int32_t a;
    int32_t r;
  } test_vec[8] = {
    {  -895547977,  -895547977 },
    {  1712937231,  1712937231 },
    { -1086654689, -1086654689 },
    {  1855506850,  1855506850 },
    {  1870001810,  1870001810 },
    {  -396094407,  -396094407 },
    { -1262223993, -1262223993 },
    {  2015532253,  2015532253 }
  };

  for (size_t i = 0 ; i < sizeof(test_vec) / sizeof(test_vec[0]) ; i++) {
    int32_t r;
    simde_mm_stream_si32(&r, test_vec[i].a);
    munit_assert_int32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_stream_si64(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    int64_t a;
    int64_t r;
  } test_vec[8] = {
    { INT64_C( -908741869362791955), INT64_C( -908741869362791955) },
    { INT64_C( 6977779886002528513), INT64_C( 6977779886002528513) },
    { INT64_C(-3803748866185605675), INT64_C(-3803748866185605675) },
    { INT64_C( 9126491633461219066), INT64_C( 9126491633461219066) },
    { INT64_C(-1680016917440909978), INT64_C(-1680016917440909978) },
    { INT64_C( 9194247506078439345), INT64_C( 9194247506078439345) },
    { INT64_C(-5911248664473270680), INT64_C(-5911248664473270680) },
    { INT64_C(-9131883318362768052), INT64_C(-9131883318362768052) }
  };

  for (size_t i = 0 ; i < sizeof(test_vec) / sizeof(test_vec[0]) ; i++) {
    int64_t r;
    simde_mm_stream_si64(&r, test_vec[i].a);
    munit_assert_int64(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_sub_epi8(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi8(INT8_C(-114), INT8_C(-102), INT8_C( -21), INT8_C(  93),
                        INT8_C(-120), INT8_C( 125), INT8_C( -36), INT8_C( -23),
                        INT8_C( -12), INT8_C(  11), INT8_C(  22), INT8_C(  78),
                        INT8_C( -16), INT8_C(  57), INT8_C(  71), INT8_C( 112)),
      simde_mm_set_epi8(INT8_C( -15), INT8_C( -47), INT8_C(   8), INT8_C(  73),
                        INT8_C(  45), INT8_C(  37), INT8_C(  27), INT8_C( -63),
                        INT8_C( -74), INT8_C( -76), INT8_C( -34), INT8_C(  78),
                        INT8_C( -50), INT8_C( 121), INT8_C(-113), INT8_C(-123)),
      simde_mm_set_epi8(INT8_C( -99), INT8_C( -55), INT8_C( -29), INT8_C(  20),
                        INT8_C(  91), INT8_C(  88), INT8_C( -63), INT8_C(  40),
                        INT8_C(  62), INT8_C(  87), INT8_C(  56), INT8_C(   0),
                        INT8_C(  34), INT8_C( -64), INT8_C( -72), INT8_C( -21)) },
    { simde_mm_set_epi8(INT8_C( -71), INT8_C( -77), INT8_C( -40), INT8_C(  99),
                        INT8_C( -40), INT8_C(  24), INT8_C(  45), INT8_C( 125),
                        INT8_C(  16), INT8_C(  82), INT8_C( -66), INT8_C( -93),
                        INT8_C(  92), INT8_C(  60), INT8_C(  65), INT8_C(  70)),
      simde_mm_set_epi8(INT8_C( -15), INT8_C( -11), INT8_C(  41), INT8_C(  35),
                        INT8_C(  87), INT8_C( -22), INT8_C( -28), INT8_C( -74),
                        INT8_C(  88), INT8_C(-100), INT8_C(  28), INT8_C( -30),
                        INT8_C( 122), INT8_C( -93), INT8_C( -11), INT8_C(  47)),
      simde_mm_set_epi8(INT8_C( -56), INT8_C( -66), INT8_C( -81), INT8_C(  64),
                        INT8_C(-127), INT8_C(  46), INT8_C(  73), INT8_C( -57),
                        INT8_C( -72), INT8_C( -74), INT8_C( -94), INT8_C( -63),
                        INT8_C( -30), INT8_C(-103), INT8_C(  76), INT8_C(  23)) },
    { simde_mm_set_epi8(INT8_C(  88), INT8_C(   7), INT8_C(  21), INT8_C(  40),
                        INT8_C( -45), INT8_C( -52), INT8_C( 105), INT8_C(   9),
                        INT8_C( -65), INT8_C( -48), INT8_C(  74), INT8_C( -11),
                        INT8_C(  71), INT8_C( -73), INT8_C( -92), INT8_C(-128)),
      simde_mm_set_epi8(INT8_C(  51), INT8_C( -25), INT8_C(  14), INT8_C( -31),
                        INT8_C( -75), INT8_C(  81), INT8_C( 123), INT8_C( -32),
                        INT8_C( -73), INT8_C(-121), INT8_C(  36), INT8_C( -43),
                        INT8_C(  95), INT8_C(  -5), INT8_C(  71), INT8_C( -67)),
      simde_mm_set_epi8(INT8_C(  37), INT8_C(  32), INT8_C(   7), INT8_C(  71),
                        INT8_C(  30), INT8_C( 123), INT8_C( -18), INT8_C(  41),
                        INT8_C(   8), INT8_C(  73), INT8_C(  38), INT8_C(  32),
                        INT8_C( -24), INT8_C( -68), INT8_C(  93), INT8_C( -61)) },
    { simde_mm_set_epi8(INT8_C( -26), INT8_C( -30), INT8_C(-127), INT8_C( -96),
                        INT8_C( -93), INT8_C(  85), INT8_C( -61), INT8_C(  31),
                        INT8_C(  84), INT8_C(  86), INT8_C(  14), INT8_C(  51),
                        INT8_C( -75), INT8_C( -80), INT8_C(  35), INT8_C(  49)),
      simde_mm_set_epi8(INT8_C(-102), INT8_C(  55), INT8_C( 103), INT8_C(  19),
                        INT8_C(-107), INT8_C( -66), INT8_C(-128), INT8_C(  92),
                        INT8_C(-108), INT8_C( -59), INT8_C( -55), INT8_C(  84),
                        INT8_C( -42), INT8_C(  42), INT8_C( -85), INT8_C( -73)),
      simde_mm_set_epi8(INT8_C(  76), INT8_C( -85), INT8_C(  26), INT8_C(-115),
                        INT8_C(  14), INT8_C(-105), INT8_C(  67), INT8_C( -61),
                        INT8_C( -64), INT8_C(-111), INT8_C(  69), INT8_C( -33),
                        INT8_C( -33), INT8_C(-122), INT8_C( 120), INT8_C( 122)) },
    { simde_mm_set_epi8(INT8_C( -92), INT8_C(  56), INT8_C( -22), INT8_C( -76),
                        INT8_C( -77), INT8_C(-116), INT8_C( -11), INT8_C(  34),
                        INT8_C(  -7), INT8_C(  37), INT8_C( -64), INT8_C( -72),
                        INT8_C(  28), INT8_C(-107), INT8_C(-128), INT8_C(-117)),
      simde_mm_set_epi8(INT8_C( -56), INT8_C(  -3), INT8_C(  32), INT8_C(  22),
                        INT8_C(  49), INT8_C(-125), INT8_C( 122), INT8_C(  -3),
                        INT8_C(-111), INT8_C(  65), INT8_C( -17), INT8_C(  15),
                        INT8_C( -83), INT8_C( -49), INT8_C(  13), INT8_C(  98)),
      simde_mm_set_epi8(INT8_C( -36), INT8_C(  59), INT8_C( -54), INT8_C( -98),
                        INT8_C(-126), INT8_C(   9), INT8_C( 123), INT8_C(  37),
                        INT8_C( 104), INT8_C( -28), INT8_C( -47), INT8_C( -87),
                        INT8_C( 111), INT8_C( -58), INT8_C( 115), INT8_C(  41)) },
    { simde_mm_set_epi8(INT8_C(-104), INT8_C(   9), INT8_C(  90), INT8_C( -26),
                        INT8_C(-114), INT8_C(-100), INT8_C( -19), INT8_C(  82),
                        INT8_C(  96), INT8_C(  58), INT8_C(  39), INT8_C(   9),
                        INT8_C(  -4), INT8_C(  91), INT8_C( -93), INT8_C( -73)),
      simde_mm_set_epi8(INT8_C(  16), INT8_C(   2), INT8_C(  -9), INT8_C( 107),
                        INT8_C(-122), INT8_C(-106), INT8_C(  -7), INT8_C(  11),
                        INT8_C( 116), INT8_C( -40), INT8_C(  -9), INT8_C( -94),
                        INT8_C(  61), INT8_C( -90), INT8_C(  69), INT8_C(   0)),
      simde_mm_set_epi8(INT8_C(-120), INT8_C(   7), INT8_C(  99), INT8_C( 123),
                        INT8_C(   8), INT8_C(   6), INT8_C( -12), INT8_C(  71),
                        INT8_C( -20), INT8_C(  98), INT8_C(  48), INT8_C( 103),
                        INT8_C( -65), INT8_C( -75), INT8_C(  94), INT8_C( -73)) },
    { simde_mm_set_epi8(INT8_C( -61), INT8_C( -71), INT8_C( 103), INT8_C(  76),
                        INT8_C(  44), INT8_C(  98), INT8_C(  70), INT8_C(-120),
                        INT8_C(  17), INT8_C( 126), INT8_C( -43), INT8_C( 108),
                        INT8_C( -31), INT8_C(  12), INT8_C( -92), INT8_C( -28)),
      simde_mm_set_epi8(INT8_C(-114), INT8_C(  71), INT8_C(  -5), INT8_C(  -9),
                        INT8_C(  -6), INT8_C( 117), INT8_C( -23), INT8_C( -62),
                        INT8_C( -10), INT8_C( -22), INT8_C( 106), INT8_C(  35),
                        INT8_C( -63), INT8_C(  18), INT8_C(  58), INT8_C(  22)),
      simde_mm_set_epi8(INT8_C(  53), INT8_C( 114), INT8_C( 108), INT8_C(  85),
                        INT8_C(  50), INT8_C( -19), INT8_C(  93), INT8_C( -58),
                        INT8_C(  27), INT8_C(-108), INT8_C( 107), INT8_C(  73),
                        INT8_C(  32), INT8_C(  -6), INT8_C( 106), INT8_C( -50)) },
    { simde_mm_set_epi8(INT8_C(  19), INT8_C( -54), INT8_C(  71), INT8_C(   0),
                        INT8_C( -13), INT8_C(  85), INT8_C( 113), INT8_C(   7),
                        INT8_C( -78), INT8_C(-122), INT8_C( -69), INT8_C( -15),
                        INT8_C( -57), INT8_C(  -9), INT8_C(-125), INT8_C(  84)),
      simde_mm_set_epi8(INT8_C( -78), INT8_C( 106), INT8_C(-106), INT8_C(  60),
                        INT8_C(  36), INT8_C( 103), INT8_C( -55), INT8_C(  69),
                        INT8_C(-119), INT8_C( -53), INT8_C(  67), INT8_C( -86),
                        INT8_C( -37), INT8_C( -20), INT8_C( -58), INT8_C( -28)),
      simde_mm_set_epi8(INT8_C(  97), INT8_C(  96), INT8_C( -79), INT8_C( -60),
                        INT8_C( -49), INT8_C( -18), INT8_C( -88), INT8_C( -62),
                        INT8_C(  41), INT8_C( -69), INT8_C( 120), INT8_C(  71),
                        INT8_C( -20), INT8_C(  11), INT8_C( -67), INT8_C( 112)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_sub_epi8(test_vec[i].a, test_vec[i].b);
    simde_assert_m128i_i8(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_sub_epi16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi16(  4649, -10562, -25917,   9425,  27983,  -7888,   3337, -19608),
      simde_mm_set_epi16(-13637,  -2631,  26607,  19784, -32723, -19066,  18245, -23690),
      simde_mm_set_epi16( 18286,  -7931,  13012, -10359,  -4830,  11178, -14908,   4082) },
    { simde_mm_set_epi16(   708,  11434,  -1239, -25521, -21333,  14389,   1705,  20680),
      simde_mm_set_epi16(-28483,   8156, -22073,  17984,  20902,   3569,  31387,   7806),
      simde_mm_set_epi16( 29191,   3278,  20834,  22031,  23301,  10820, -29682,  12874) },
    { simde_mm_set_epi16( -3626,    757,    189, -19968,   5676,   7663,   8524,  15372),
      simde_mm_set_epi16( 20254, -31977,  18332, -14379,  -7613,  19737,  22035,  -6952),
      simde_mm_set_epi16(-23880,  32734, -18143,  -5589,  13289, -12074, -13511,  22324) },
    { simde_mm_set_epi16(-12411,  25999,   8485,  -8542,  21018, -31213,  15766,  18574),
      simde_mm_set_epi16(  6484, -10154,  20175,  32085,  18950, -19405, -12089,   8199),
      simde_mm_set_epi16(-18895, -29383, -11690,  24909,   2068, -11808,  27855,  10375) },
    { simde_mm_set_epi16(  7148, -25537,   5647, -25529,  -5324, -12025,  27072, -30360),
      simde_mm_set_epi16(-24506,  -9630,  25801,  32734,   1516,  10059,  10693,  13623),
      simde_mm_set_epi16( 31654, -15907, -20154,   7273,  -6840, -22084,  16379,  21553) },
    { simde_mm_set_epi16(-24730, -23496, -16567, -13323, -12986, -31808,  27730,  -2264),
      simde_mm_set_epi16(-13737, -18451, -16289,  22307,  -2961,  22412,  13917,   8259),
      simde_mm_set_epi16(-10993,  -5045,   -278,  29906, -10025,  11316,  13813, -10523) },
    { simde_mm_set_epi16(  5718,  31027,  29094,   1906,  -3938,  -2339, -13536,  11931),
      simde_mm_set_epi16(-23545,   2546,  -2953,  -8072,  28237, -11239, -13996,  29497),
      simde_mm_set_epi16( 29263,  28481,  32047,   9978, -32175,   8900,    460, -17566) },
    { simde_mm_set_epi16( 29491, -30965,   4748, -28809, -21877, -21669, -28233, -28758),
      simde_mm_set_epi16(  5029,   4694, -16956, -15561, -23049, -31774,   3835, -12557),
      simde_mm_set_epi16( 24462,  29877,  21704, -13248,   1172,  10105, -32068, -16201) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_sub_epi16(test_vec[i].a, test_vec[i].b);
    simde_assert_m128i_i16(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_sub_epi32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi32(  304731838, -1698487087,  1833951536,   218739560),
      simde_mm_set_epi32( -893651527,  1743736136, -2144488058,  1195746166),
      simde_mm_set_epi32( 1198383365,   852744073,  -316527702,  -977006606) },
    { simde_mm_set_epi32(   46410922,   -81159089, -1398065099,   111759560),
      simde_mm_set_epi32(-1866653732, -1446558144,  1369837041,  2056986238),
      simde_mm_set_epi32( 1913064654,  1365399055,  1527065156, -1945226678) },
    { simde_mm_set_epi32( -237632779,    12431872,   371989999,   558644236),
      simde_mm_set_epi32( 1327399703,  1201457109,  -498905831,  1444144344),
      simde_mm_set_epi32(-1565032482, -1189025237,   870895830,  -885500108) },
    { simde_mm_set_epi32( -813341297,   556129954,  1377469971,  1033259150),
      simde_mm_set_epi32(  424990806,  1322220885,  1241953331,  -792256505),
      simde_mm_set_epi32(-1238332103,  -766090931,   135516640,  1825515655) },
    { simde_mm_set_epi32(  468491327,   370121799,  -348860153,  1774225768),
      simde_mm_set_epi32(-1605969310,  1690927070,    99362635,   700790071),
      simde_mm_set_epi32( 2074460637, -1320805271,  -448222788,  1073435697) },
    { simde_mm_set_epi32(-1620663240, -1085682699,  -851016768,  1817376552),
      simde_mm_set_epi32( -900220947, -1067493597,  -194029684,   912072771),
      simde_mm_set_epi32( -720442293,   -18189102,  -656987084,   905303781) },
    { simde_mm_set_epi32(  374765875,  1906706290,  -258017571,  -887083365),
      simde_mm_set_epi32(-1543042574,  -193470344,  1850594329,  -917212359),
      simde_mm_set_epi32( 1917808449,  2100176634, -2108611900,    30128994) },
    { simde_mm_set_epi32( 1932756747,   311201655, -1433687205, -1850241110),
      simde_mm_set_epi32(  329585238, -1111178441, -1510505502,   251383539),
      simde_mm_set_epi32( 1603171509,  1422380096,    76818297, -2101624649) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_sub_epi32(test_vec[i].a, test_vec[i].b);
    simde_assert_m128i_i32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_sub_epi64(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi64x(INT64_C(-5763845342482697816), INT64_C( 2103077785434280804)),
      simde_mm_set_epi64x(INT64_C(  -84933559585222060), INT64_C(-2626653918467514964)),
      simde_mm_set_epi64x(INT64_C(-5678911782897475756), INT64_C( 4729731703901795768)) },
    { simde_mm_set_epi64x(INT64_C( 1527789798480118137), INT64_C( 8436112421047310932)),
      simde_mm_set_epi64x(INT64_C(-1700732467797798250), INT64_C(-3973336518996013340)),
      simde_mm_set_epi64x(INT64_C( 3228522266277916387), INT64_C(-6037295133666227344)) },
    { simde_mm_set_epi64x(INT64_C( 4851345631989659335), INT64_C(-7206764788471565568)),
      simde_mm_set_epi64x(INT64_C( 5406657072094052149), INT64_C( 1553917979932899417)),
      simde_mm_set_epi64x(INT64_C( -555311440104392814), INT64_C(-8760682768404464985)) },
    { simde_mm_set_epi64x(INT64_C( 4880585840903485916), INT64_C(-3214111508108965857)),
      simde_mm_set_epi64x(INT64_C(-9030069389987018552), INT64_C(-3395779442469856546)),
      simde_mm_set_epi64x(INT64_C(-4536088842819047148), INT64_C(  181667934360890689)) },
    { simde_mm_set_epi64x(INT64_C( 5848110560047382754), INT64_C( 5491947693722128435)),
      simde_mm_set_epi64x(INT64_C(  213782131019667117), INT64_C( -937970910639813333)),
      simde_mm_set_epi64x(INT64_C( 5634328429027715637), INT64_C( 6429918604361941768)) },
    { simde_mm_set_epi64x(INT64_C(-1470278109522038956), INT64_C(-7185464081677005028)),
      simde_mm_set_epi64x(INT64_C( 7512013344600346304), INT64_C(-1151368750409397152)),
      simde_mm_set_epi64x(INT64_C(-8982291454122385260), INT64_C(-6034095331267607876)) },
    { simde_mm_set_epi64x(INT64_C(-1414880571892272072), INT64_C(-5464559564131319132)),
      simde_mm_set_epi64x(INT64_C(-8460263392275774431), INT64_C( 3444946385257741717)),
      simde_mm_set_epi64x(INT64_C( 7045382820383502359), INT64_C(-8909505949389060849)) },
    { simde_mm_set_epi64x(INT64_C( 2041037654020608990), INT64_C(-5135476174064773616)),
      simde_mm_set_epi64x(INT64_C(-2250411574230731306), INT64_C( 6301008926808412830)),
      simde_mm_set_epi64x(INT64_C( 4291449228251340296), INT64_C( 7010258972836365170)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_sub_epi64(test_vec[i].a, test_vec[i].b);
    simde_assert_m128i_i64(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_sub_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128d a;
    simde__m128d b;
    simde__m128d r;
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -989.09), SIMDE_FLOAT64_C(  415.70)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -630.71), SIMDE_FLOAT64_C(  755.53)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -358.38), SIMDE_FLOAT64_C( -339.83)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -609.69), SIMDE_FLOAT64_C( -266.09)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  904.74), SIMDE_FLOAT64_C(  704.00)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(-1514.43), SIMDE_FLOAT64_C( -970.09)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -864.69), SIMDE_FLOAT64_C( -728.75)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -549.96), SIMDE_FLOAT64_C(  478.05)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -314.73), SIMDE_FLOAT64_C(-1206.80)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -607.45), SIMDE_FLOAT64_C( -593.32)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -648.70), SIMDE_FLOAT64_C( -195.04)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   41.24), SIMDE_FLOAT64_C( -398.28)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -442.58), SIMDE_FLOAT64_C( -296.11)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  195.46), SIMDE_FLOAT64_C(  287.25)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -638.04), SIMDE_FLOAT64_C( -583.37)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -930.71), SIMDE_FLOAT64_C(  996.22)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -786.74), SIMDE_FLOAT64_C(   77.74)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -143.98), SIMDE_FLOAT64_C(  918.47)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  702.75), SIMDE_FLOAT64_C(  -28.87)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  970.37), SIMDE_FLOAT64_C( -443.97)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -267.62), SIMDE_FLOAT64_C(  415.10)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -369.79), SIMDE_FLOAT64_C(  539.64)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -404.57), SIMDE_FLOAT64_C( -587.93)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   34.78), SIMDE_FLOAT64_C( 1127.56)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_sub_pd(test_vec[i].a, test_vec[i].b);
    simde_assert_m128d_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_sub_sd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128d a;
    simde__m128d b;
    simde__m128d r;
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -989.09), SIMDE_FLOAT64_C(  415.70)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -630.71), SIMDE_FLOAT64_C(  755.53)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -989.09), SIMDE_FLOAT64_C( -339.83)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -609.69), SIMDE_FLOAT64_C( -266.09)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  904.74), SIMDE_FLOAT64_C(  704.00)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -609.69), SIMDE_FLOAT64_C( -970.09)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -864.69), SIMDE_FLOAT64_C( -728.75)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -549.96), SIMDE_FLOAT64_C(  478.05)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -864.69), SIMDE_FLOAT64_C(-1206.80)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -607.45), SIMDE_FLOAT64_C( -593.32)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -648.70), SIMDE_FLOAT64_C( -195.04)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -607.45), SIMDE_FLOAT64_C( -398.28)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -442.58), SIMDE_FLOAT64_C( -296.11)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  195.46), SIMDE_FLOAT64_C(  287.25)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -442.58), SIMDE_FLOAT64_C( -583.37)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -930.71), SIMDE_FLOAT64_C(  996.22)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -786.74), SIMDE_FLOAT64_C(   77.74)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -930.71), SIMDE_FLOAT64_C(  918.47)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  702.75), SIMDE_FLOAT64_C(  -28.87)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  970.37), SIMDE_FLOAT64_C( -443.97)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  702.75), SIMDE_FLOAT64_C(  415.10)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -369.79), SIMDE_FLOAT64_C(  539.64)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -404.57), SIMDE_FLOAT64_C( -587.93)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -369.79), SIMDE_FLOAT64_C( 1127.56)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_sub_sd(test_vec[i].a, test_vec[i].b);
    simde_assert_m128d_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_sub_si64(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m64 a;
    simde__m64 b;
    simde__m64 r;
  } test_vec[8] = {
    { simde_mm_cvtsi64_m64(INT64_C(  -40015113898169895)),
      simde_mm_cvtsi64_m64(INT64_C( 3843942487505240466)),
      simde_mm_cvtsi64_m64(INT64_C(-3883957601403410361)), },
    { simde_mm_cvtsi64_m64(INT64_C( 8317116700671824816)),
      simde_mm_cvtsi64_m64(INT64_C( 2891842609034633421)),
      simde_mm_cvtsi64_m64(INT64_C( 5425274091637191395)), },
    { simde_mm_cvtsi64_m64(INT64_C(  922042182678065366)),
      simde_mm_cvtsi64_m64(INT64_C( 4937799652981992213)),
      simde_mm_cvtsi64_m64(INT64_C(-4015757470303926847)), },
    { simde_mm_cvtsi64_m64(INT64_C(  297526191920431793)),
      simde_mm_cvtsi64_m64(INT64_C(-8568639315346032946)),
      simde_mm_cvtsi64_m64(INT64_C( 8866165507266464739)), },
    { simde_mm_cvtsi64_m64(INT64_C(  944913740190663659)),
      simde_mm_cvtsi64_m64(INT64_C(-5569388163200780530)),
      simde_mm_cvtsi64_m64(INT64_C( 6514301903391444189)), },
    { simde_mm_cvtsi64_m64(INT64_C( 2756927115722410076)),
      simde_mm_cvtsi64_m64(INT64_C( 1302679549898517242)),
      simde_mm_cvtsi64_m64(INT64_C( 1454247565823892834)), },
    { simde_mm_cvtsi64_m64(INT64_C(  977005230827305840)),
      simde_mm_cvtsi64_m64(INT64_C( 4908563834369883454)),
      simde_mm_cvtsi64_m64(INT64_C(-3931558603542577614)), },
    { simde_mm_cvtsi64_m64(INT64_C(-7062092201406124762)),
      simde_mm_cvtsi64_m64(INT64_C( 2377066878085823882)),
      simde_mm_cvtsi64_m64(INT64_C( 9007584994217602972)), }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m64 r = simde_mm_sub_si64(test_vec[i].a, test_vec[i].b);
    simde_assert_m64_i64(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_subs_epi8(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi8(INT8_C(  77), INT8_C( -15), INT8_C( -74), INT8_C(  52), INT8_C( -61), INT8_C(  64), INT8_C(  59), INT8_C(  21),
                        INT8_C( -60), INT8_C( -67), INT8_C( -73), INT8_C( 104), INT8_C(  30), INT8_C( 107), INT8_C(  83), INT8_C(-117)),
      simde_mm_set_epi8(INT8_C(-110), INT8_C(-112), INT8_C( -53), INT8_C(  89), INT8_C(  74), INT8_C(  81), INT8_C( -22), INT8_C( -97),
                        INT8_C(-128), INT8_C( -54), INT8_C( 101), INT8_C(  96), INT8_C(  36), INT8_C(  87), INT8_C(-125), INT8_C(  28)),
      simde_mm_set_epi8(INT8_C( 127), INT8_C(  97), INT8_C( -21), INT8_C( -37), INT8_C(-128), INT8_C( -17), INT8_C(  81), INT8_C( 118),
                        INT8_C(  68), INT8_C( -13), INT8_C(-128), INT8_C(   8), INT8_C(  -6), INT8_C(  20), INT8_C( 127), INT8_C(-128)) },
    { simde_mm_set_epi8(INT8_C(  57), INT8_C(  79), INT8_C( 101), INT8_C(  47), INT8_C(  60), INT8_C(  12), INT8_C(   0), INT8_C( -19),
                        INT8_C(  63), INT8_C(  39), INT8_C(-108), INT8_C(  37), INT8_C(  92), INT8_C( 114), INT8_C(-110), INT8_C(  91)),
      simde_mm_set_epi8(INT8_C( -59), INT8_C( -81), INT8_C(  49), INT8_C( 126), INT8_C(  33), INT8_C( 120), INT8_C(-127), INT8_C(  80),
                        INT8_C( 109), INT8_C(-100), INT8_C(  21), INT8_C(-125), INT8_C(   7), INT8_C(  60), INT8_C(-122), INT8_C( -61)),
      simde_mm_set_epi8(INT8_C( 116), INT8_C( 127), INT8_C(  52), INT8_C( -79), INT8_C(  27), INT8_C(-108), INT8_C( 127), INT8_C( -99),
                        INT8_C( -46), INT8_C( 127), INT8_C(-128), INT8_C( 127), INT8_C(  85), INT8_C(  54), INT8_C(  12), INT8_C( 127)) },
    { simde_mm_set_epi8(INT8_C(  84), INT8_C(-104), INT8_C( -82), INT8_C( 105), INT8_C( -43), INT8_C( -36), INT8_C(  16), INT8_C( -15),
                        INT8_C( -34), INT8_C( 120), INT8_C(-110), INT8_C(  90), INT8_C(  78), INT8_C(  45), INT8_C(-124), INT8_C( -84)),
      simde_mm_set_epi8(INT8_C( -66), INT8_C(  -1), INT8_C(  91), INT8_C(  74), INT8_C(  83), INT8_C( -91), INT8_C( -97), INT8_C( 115),
                        INT8_C( -29), INT8_C(  67), INT8_C( -98), INT8_C( -51), INT8_C( 110), INT8_C( -43), INT8_C( 125), INT8_C(  63)),
      simde_mm_set_epi8(INT8_C( 127), INT8_C(-103), INT8_C(-128), INT8_C(  31), INT8_C(-126), INT8_C(  55), INT8_C( 113), INT8_C(-128),
                        INT8_C(  -5), INT8_C(  53), INT8_C( -12), INT8_C( 127), INT8_C( -32), INT8_C(  88), INT8_C(-128), INT8_C(-128)) },
    { simde_mm_set_epi8(INT8_C( -75), INT8_C(  37), INT8_C( 126), INT8_C(  21), INT8_C(  92), INT8_C(-124), INT8_C( -81), INT8_C(  -6),
                        INT8_C(-117), INT8_C( -14), INT8_C(  38), INT8_C( -68), INT8_C( -45), INT8_C( 114), INT8_C(  32), INT8_C( -13)),
      simde_mm_set_epi8(INT8_C(  80), INT8_C(-123), INT8_C( -25), INT8_C(  71), INT8_C(-108), INT8_C( -31), INT8_C(  98), INT8_C( -67),
                        INT8_C( -23), INT8_C(-112), INT8_C( -42), INT8_C( -16), INT8_C( -56), INT8_C( 107), INT8_C(   6), INT8_C(  16)),
      simde_mm_set_epi8(INT8_C(-128), INT8_C( 127), INT8_C( 127), INT8_C( -50), INT8_C( 127), INT8_C( -93), INT8_C(-128), INT8_C(  61),
                        INT8_C( -94), INT8_C(  98), INT8_C(  80), INT8_C( -52), INT8_C(  11), INT8_C(   7), INT8_C(  26), INT8_C( -29)) },
    { simde_mm_set_epi8(INT8_C(  85), INT8_C(  18), INT8_C(  15), INT8_C( 100), INT8_C( 107), INT8_C( -69), INT8_C( -96), INT8_C( -20),
                        INT8_C( -18), INT8_C(  42), INT8_C(  98), INT8_C( 104), INT8_C( -70), INT8_C(-121), INT8_C( -91), INT8_C(  77)),
      simde_mm_set_epi8(INT8_C( 103), INT8_C( -62), INT8_C( 107), INT8_C(-125), INT8_C( -86), INT8_C(-112), INT8_C( -45), INT8_C(   3),
                        INT8_C( -26), INT8_C(  96), INT8_C(  83), INT8_C(  23), INT8_C( 100), INT8_C( 127), INT8_C( -56), INT8_C( -52)),
      simde_mm_set_epi8(INT8_C( -18), INT8_C(  80), INT8_C( -92), INT8_C( 127), INT8_C( 127), INT8_C(  43), INT8_C( -51), INT8_C( -23),
                        INT8_C(   8), INT8_C( -54), INT8_C(  15), INT8_C(  81), INT8_C(-128), INT8_C(-128), INT8_C( -35), INT8_C( 127)) },
    { simde_mm_set_epi8(INT8_C(  63), INT8_C(  16), INT8_C( 100), INT8_C( -10), INT8_C(  78), INT8_C( 116), INT8_C( -91), INT8_C(  21),
                        INT8_C( -10), INT8_C( -27), INT8_C( -92), INT8_C(  31), INT8_C( -23), INT8_C( -53), INT8_C(  -1), INT8_C(  -1)),
      simde_mm_set_epi8(INT8_C(  20), INT8_C(-123), INT8_C(  36), INT8_C( -10), INT8_C( 127), INT8_C(-111), INT8_C( -60), INT8_C(  54),
                        INT8_C(  92), INT8_C( 101), INT8_C( -13), INT8_C( -31), INT8_C(-124), INT8_C( 112), INT8_C(-118), INT8_C( -29)),
      simde_mm_set_epi8(INT8_C(  43), INT8_C( 127), INT8_C(  64), INT8_C(   0), INT8_C( -49), INT8_C( 127), INT8_C( -31), INT8_C( -33),
                        INT8_C(-102), INT8_C(-128), INT8_C( -79), INT8_C(  62), INT8_C( 101), INT8_C(-128), INT8_C( 117), INT8_C(  28)) },
    { simde_mm_set_epi8(INT8_C(   1), INT8_C( -28), INT8_C( -45), INT8_C( -32), INT8_C(-103), INT8_C(  27), INT8_C( -38), INT8_C(-127),
                        INT8_C( -89), INT8_C( -74), INT8_C(  47), INT8_C(  91), INT8_C(  46), INT8_C( -24), INT8_C(  60), INT8_C(  23)),
      simde_mm_set_epi8(INT8_C( -25), INT8_C( -68), INT8_C(-116), INT8_C(  92), INT8_C(  33), INT8_C(  -5), INT8_C( -35), INT8_C( -44),
                        INT8_C(  -9), INT8_C( -90), INT8_C(  63), INT8_C( 108), INT8_C(  36), INT8_C(  27), INT8_C( 112), INT8_C( -11)),
      simde_mm_set_epi8(INT8_C(  26), INT8_C(  40), INT8_C(  71), INT8_C(-124), INT8_C(-128), INT8_C(  32), INT8_C(  -3), INT8_C( -83),
                        INT8_C( -80), INT8_C(  16), INT8_C( -16), INT8_C( -17), INT8_C(  10), INT8_C( -51), INT8_C( -52), INT8_C(  34)) },
    { simde_mm_set_epi8(INT8_C(  29), INT8_C( 123), INT8_C(  -8), INT8_C( -35), INT8_C(   3), INT8_C( -97), INT8_C( 124), INT8_C(-121),
                        INT8_C(  52), INT8_C(  75), INT8_C( -93), INT8_C(-127), INT8_C( -78), INT8_C(  87), INT8_C( 102), INT8_C( 119)),
      simde_mm_set_epi8(INT8_C(  51), INT8_C( -89), INT8_C(  -6), INT8_C(   8), INT8_C( -19), INT8_C( -88), INT8_C(  22), INT8_C(  21),
                        INT8_C( -37), INT8_C( -42), INT8_C( -97), INT8_C(  58), INT8_C(  70), INT8_C( -92), INT8_C(-100), INT8_C(-124)),
      simde_mm_set_epi8(INT8_C( -22), INT8_C( 127), INT8_C(  -2), INT8_C( -43), INT8_C(  22), INT8_C(  -9), INT8_C( 102), INT8_C(-128),
                        INT8_C(  89), INT8_C( 117), INT8_C(   4), INT8_C(-128), INT8_C(-128), INT8_C( 127), INT8_C( 127), INT8_C( 127)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_subs_epi8(test_vec[i].a, test_vec[i].b);
    simde_assert_m128i_i8(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_subs_epi16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi16(  3087, -11046,  16009,  -2784,  23836,    341,  25120,    792),
      simde_mm_set_epi16(-13938,  11942,  18967, -24666, -12194, -15141,  27868,   7667),
      simde_mm_set_epi16( 17025, -22988,  -2958,  21882,  32767,  15482,  -2748,  -6875) },
    { simde_mm_set_epi16( 15944,  21174, -19487,  30166,   9880,   2293,   1544,   6216),
      simde_mm_set_epi16(-22637,  27460,  16112, -21899,  28784,   -234,  -5361,  25377),
      simde_mm_set_epi16( 32767,  -6286, -32768,  32767, -18904,   2527,   6905, -19161) },
    { simde_mm_set_epi16( 25177,  16000, -30398, -17760,  16727,  -4856, -10813,  11418),
      simde_mm_set_epi16( 25832, -14964,  17267,  -2360,  15960,  12601,   9707,  24108),
      simde_mm_set_epi16(  -655,  30964, -32768, -15400,    767, -17457, -20520, -12690) },
    { simde_mm_set_epi16(-19601, -21914, -30623,  -8160,  24427, -16073,  14239,  20391),
      simde_mm_set_epi16(-19582, -27440,  -9450, -25104,  11842,   4749,   3094,  19163),
      simde_mm_set_epi16(   -19,   5526, -21173,  16944,  12585, -20822,  11145,   1228) },
    { simde_mm_set_epi16(-10118,  25388, -18110,  -8312,   5249,  27800,   2023,    338),
      simde_mm_set_epi16( 14501,  30804,  26885, -32444, -27012, -14925, -31013,  10807),
      simde_mm_set_epi16(-24619,  -5416, -32768,  24132,  32261,  32767,  32767, -10469) },
    { simde_mm_set_epi16(-17246, -28624,  13423,  27394,   7877, -20368, -24205, -15569),
      simde_mm_set_epi16(-21987,  -4056,   2917,  23573,  -2283,  21821,  32369,  26504),
      simde_mm_set_epi16(  4741, -24568,  10506,   3821,  10160, -32768, -32768, -32768) },
    { simde_mm_set_epi16(-10290,  29918, -29258, -28749,   6048, -25677,  24207,    366),
      simde_mm_set_epi16( 13339, -11229,  23811,   -333, -29847,  21714,   2843,  -2618),
      simde_mm_set_epi16(-23629,  32767, -32768, -28416,  32767, -32768,  21364,   2984) },
    { simde_mm_set_epi16(   824,  19299, -14246, -19942,  17549,   5220, -11590, -29570),
      simde_mm_set_epi16( 30144, -11230, -24828,  29586,  29999,  25519,   5645,  16976),
      simde_mm_set_epi16(-29320,  30529,  10582, -32768, -12450, -20299, -17235, -32768) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_subs_epi16(test_vec[i].a, test_vec[i].b);
    simde_assert_m128i_i16(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_subs_epu8(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_x_mm_set_epu8( 29,  76, 238,  61, 229, 243, 175, 238,
                           75,  27, 166, 154, 166, 157, 121, 248),
      simde_x_mm_set_epu8(129,  19, 253, 149,   9, 247,  10, 249,
                          105, 205, 179, 225, 124, 146,  91, 221),
      simde_x_mm_set_epu8(  0,  57,   0,   0, 220,   0, 165,   0,
                            0,   0,   0,   0,  42,  11,  30,  27) },
    { simde_x_mm_set_epu8(101, 150, 221,  18, 105, 115, 165,  92,
                          211,  64,  38,  72, 139,   6,  65, 201),
      simde_x_mm_set_epu8(124, 107, 110,  57, 116, 209, 153,  76,
                          122,  56,  60, 234, 120, 132,   4,  95),
      simde_x_mm_set_epu8(  0,  43, 111,   0,   0,   0,  12,  16,
                           89,   8,   0,   0,  19,   0,  61, 106) },
    { simde_x_mm_set_epu8(198, 232, 134,  13, 155, 189, 203,  84,
                          209, 255, 163, 211,  57, 177,  19,  86),
      simde_x_mm_set_epu8(205,  92, 216, 169, 196, 192,  93, 101,
                          208, 230, 232,  36,  70, 151, 125,  72),
      simde_x_mm_set_epu8(  0, 140,   0,   0,   0,   0, 110,   0,
                            1,  25,   0, 175,   0,  26,   0,  14) },
    { simde_x_mm_set_epu8(150, 141, 253,  10, 218, 100, 243,  17,
                           87,  99, 224, 222, 198, 181,  26,  41),
      simde_x_mm_set_epu8(221, 130, 146,  56,  57, 169,  46,  50,
                          234,  43,   8, 172,  95,  74,  51, 101),
      simde_x_mm_set_epu8(  0,  11, 107,   0, 161,   0, 197,   0,
                            0,  56, 216,  50, 103, 107,   0,   0) },
    { simde_x_mm_set_epu8( 91, 188, 127, 216,  55, 208,  83,  14,
                          153, 114,  48, 224,  59,  66, 100,  10),
      simde_x_mm_set_epu8( 88,  28,  13,  17,  78,  38,   8, 111,
                           57,  44, 184,  85, 188, 182, 235, 151),
      simde_x_mm_set_epu8(  3, 160, 114, 199,   0, 170,  75,   0,
                           96,  70,   0, 139,   0,   0,   0,   0) },
    { simde_x_mm_set_epu8(116,  32, 155, 196,  56,  42,  17, 217,
                           51, 162,   4,   4, 150,  83,  16, 147),
      simde_x_mm_set_epu8(216, 235, 181, 255,  89, 143,  40,  48,
                           52,  24, 160,   9, 162, 223, 243, 117),
      simde_x_mm_set_epu8(  0,   0,   0,   0,   0,   0,   0, 169,
                            0, 138,   0,   0,   0,   0,   0,  30) },
    { simde_x_mm_set_epu8(217, 238, 218, 168,  98, 146,  87, 217,
                          135, 103, 179, 182, 128,  74, 156,   3),
      simde_x_mm_set_epu8(157,   0, 179, 231, 176,  37, 226, 198,
                          145, 138, 239, 164,   0, 170,  52,  61),
      simde_x_mm_set_epu8( 60, 238,  39,   0,   0, 109,   0,  19,
                            0,   0,   0,  18, 128,   0, 104,   0) },
    { simde_x_mm_set_epu8(181,  83, 160, 141,  77, 119, 160, 171,
                          112,  95,  47,  88,   0,  90, 237,  18),
      simde_x_mm_set_epu8(139, 146,  25, 173,  34,  31, 251, 200,
                          190, 131,  23,  41, 246,  91,  98, 221),
      simde_x_mm_set_epu8( 42,   0, 135,   0,  43,  88,   0,   0,
                            0,   0,  24,  47,   0,   0, 139,   0) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_subs_epu8(test_vec[i].a, test_vec[i].b);
    simde_assert_m128i_u8(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_subs_epu16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_x_mm_set_epu16(55440, 59202, 42058, 53369, 32796,  7917, 33818, 17136),
      simde_x_mm_set_epu16(26104, 52689, 47050, 39249, 59785, 38246, 31610, 10518),
      simde_x_mm_set_epu16(29336,  6513,     0, 14120,     0,     0,  2208,  6618) },
    { simde_x_mm_set_epu16(34216, 34652, 60066, 36214,  4826, 65416, 55052, 33573),
      simde_x_mm_set_epu16(26443, 15803,  4000, 33420, 50076, 27556,  5522, 41665),
      simde_x_mm_set_epu16( 7773, 18849, 56066,  2794,     0, 37860, 49530,     0) },
    { simde_x_mm_set_epu16(64499, 21603, 35445, 16287, 15728, 23400, 23336, 39270),
      simde_x_mm_set_epu16(56255, 54924, 45249, 41636, 27152, 13319, 19428,   768),
      simde_x_mm_set_epu16( 8244,     0,     0,     0,     0, 10081,  3908, 38502) },
    { simde_x_mm_set_epu16( 1242, 22793, 21812, 57045, 22651, 26751, 59072, 30159),
      simde_x_mm_set_epu16(11521, 44413, 36849,   788, 57441, 54148,  2979, 46303),
      simde_x_mm_set_epu16(    0,     0,     0, 56257,     0,     0, 56093,     0) },
    { simde_x_mm_set_epu16(37620, 40488, 64998, 40075, 44204, 34122, 59592, 65445),
      simde_x_mm_set_epu16(40351, 64891, 27393, 62063,  1981, 56033, 30691, 62006),
      simde_x_mm_set_epu16(    0,     0, 37605,     0, 42223,     0, 28901,  3439) },
    { simde_x_mm_set_epu16(65230, 30209, 16765,  1470, 31101, 49860, 26882, 55440),
      simde_x_mm_set_epu16(49049, 44537, 10442, 42049,   271, 49034, 11746,  5994),
      simde_x_mm_set_epu16(16181,     0,  6323,     0, 30830,   826, 15136, 49446) },
    { simde_x_mm_set_epu16(37013,  9547, 22144, 27612, 32177, 62691, 50927, 50782),
      simde_x_mm_set_epu16(18153,  2530, 10375, 48140,  7056, 62459, 20700, 31971),
      simde_x_mm_set_epu16(18860,  7017, 11769,     0, 25121,   232, 30227, 18811) },
    { simde_x_mm_set_epu16( 9831, 28967, 28080, 17470, 59616, 18625, 64250, 31724),
      simde_x_mm_set_epu16(52094, 35298, 55420,  3659, 42707, 55727, 29250, 17787),
      simde_x_mm_set_epu16(    0,     0,     0, 13811, 16909,     0, 35000, 13937) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_subs_epu16(test_vec[i].a, test_vec[i].b);
    simde_assert_m128i_u16(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_ucomieq_sd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128d a;
    simde__m128d b;
    int r;
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  523.45), SIMDE_FLOAT64_C( -718.90)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   39.72), SIMDE_FLOAT64_C(  184.39)),
      0 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  666.01), SIMDE_FLOAT64_C( -592.10)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -592.10), SIMDE_FLOAT64_C( -592.10)),
      1 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  840.01), SIMDE_FLOAT64_C( -550.36)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -550.36), SIMDE_FLOAT64_C( -701.38)),
      0 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -236.99), SIMDE_FLOAT64_C(  791.25)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  791.25), SIMDE_FLOAT64_C(  791.25)),
      1 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  743.24), SIMDE_FLOAT64_C(  945.47)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  945.47), SIMDE_FLOAT64_C(  844.58)),
      0 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  938.39), SIMDE_FLOAT64_C( -590.62)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -590.62), SIMDE_FLOAT64_C( -183.26)),
      0 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  876.49), SIMDE_FLOAT64_C(  503.26)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  503.26), SIMDE_FLOAT64_C(  503.26)),
      1 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  927.98), SIMDE_FLOAT64_C( -197.60)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -197.60), SIMDE_FLOAT64_C( -197.60)),
      1 }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    int r = simde_mm_ucomieq_sd(test_vec[i].a, test_vec[i].b);
    munit_assert_int(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_ucomige_sd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128d a;
    simde__m128d b;
    int r;
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  214.53), SIMDE_FLOAT64_C(  606.90)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  814.33), SIMDE_FLOAT64_C(  606.90)),
      1 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -487.58), SIMDE_FLOAT64_C(  444.56)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -781.36), SIMDE_FLOAT64_C(   30.46)),
      1 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  605.28), SIMDE_FLOAT64_C( -943.32)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -943.32), SIMDE_FLOAT64_C( -943.32)),
      1 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -981.47), SIMDE_FLOAT64_C(   31.75)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   31.75), SIMDE_FLOAT64_C(  299.12)),
      0 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  480.83), SIMDE_FLOAT64_C(  255.57)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  946.90), SIMDE_FLOAT64_C(  608.16)),
      0 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  634.58), SIMDE_FLOAT64_C(  320.38)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  320.38), SIMDE_FLOAT64_C(  942.24)),
      0 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(   98.67), SIMDE_FLOAT64_C(  118.05)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  118.05), SIMDE_FLOAT64_C(  118.05)),
      1 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  544.57), SIMDE_FLOAT64_C(  783.14)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  636.80), SIMDE_FLOAT64_C(  783.14)),
      1 }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    int r = simde_mm_ucomige_sd(test_vec[i].a, test_vec[i].b);
    munit_assert_int(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_ucomigt_sd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128d a;
    simde__m128d b;
    int r;
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  523.45), SIMDE_FLOAT64_C( -718.90)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   39.72), SIMDE_FLOAT64_C(  184.39)),
      0 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  666.01), SIMDE_FLOAT64_C( -592.10)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -592.10), SIMDE_FLOAT64_C( -592.10)),
      0 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  840.01), SIMDE_FLOAT64_C( -550.36)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -550.36), SIMDE_FLOAT64_C( -701.38)),
      1 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -236.99), SIMDE_FLOAT64_C(  791.25)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  791.25), SIMDE_FLOAT64_C(  791.25)),
      0 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  743.24), SIMDE_FLOAT64_C(  945.47)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  945.47), SIMDE_FLOAT64_C(  844.58)),
      1 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  938.39), SIMDE_FLOAT64_C( -590.62)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -590.62), SIMDE_FLOAT64_C( -183.26)),
      0 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  876.49), SIMDE_FLOAT64_C(  503.26)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  503.26), SIMDE_FLOAT64_C(  503.26)),
      0 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  927.98), SIMDE_FLOAT64_C( -197.60)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -197.60), SIMDE_FLOAT64_C( -197.60)),
      0 }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    int r = simde_mm_ucomigt_sd(test_vec[i].a, test_vec[i].b);
    munit_assert_int(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_ucomile_sd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128d a;
    simde__m128d b;
    int r;
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  523.45), SIMDE_FLOAT64_C( -718.90)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   39.72), SIMDE_FLOAT64_C(  184.39)),
      1 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  666.01), SIMDE_FLOAT64_C( -592.10)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -592.10), SIMDE_FLOAT64_C( -592.10)),
      1 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  840.01), SIMDE_FLOAT64_C( -550.36)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -550.36), SIMDE_FLOAT64_C( -701.38)),
      0 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -236.99), SIMDE_FLOAT64_C(  791.25)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  791.25), SIMDE_FLOAT64_C(  791.25)),
      1 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  743.24), SIMDE_FLOAT64_C(  945.47)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  945.47), SIMDE_FLOAT64_C(  844.58)),
      0 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  938.39), SIMDE_FLOAT64_C( -590.62)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -590.62), SIMDE_FLOAT64_C( -183.26)),
      1 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  876.49), SIMDE_FLOAT64_C(  503.26)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  503.26), SIMDE_FLOAT64_C(  503.26)),
      1 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  927.98), SIMDE_FLOAT64_C( -197.60)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -197.60), SIMDE_FLOAT64_C( -197.60)),
      1 }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    int r = simde_mm_ucomile_sd(test_vec[i].a, test_vec[i].b);
    munit_assert_int(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_ucomilt_sd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128d a;
    simde__m128d b;
    int r;
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  523.45), SIMDE_FLOAT64_C( -718.90)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   39.72), SIMDE_FLOAT64_C(  184.39)),
      1 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  666.01), SIMDE_FLOAT64_C( -592.10)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -592.10), SIMDE_FLOAT64_C( -592.10)),
      0 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  840.01), SIMDE_FLOAT64_C( -550.36)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -550.36), SIMDE_FLOAT64_C( -701.38)),
      0 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -236.99), SIMDE_FLOAT64_C(  791.25)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  791.25), SIMDE_FLOAT64_C(  791.25)),
      0 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  743.24), SIMDE_FLOAT64_C(  945.47)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  945.47), SIMDE_FLOAT64_C(  844.58)),
      0 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  938.39), SIMDE_FLOAT64_C( -590.62)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -590.62), SIMDE_FLOAT64_C( -183.26)),
      1 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  876.49), SIMDE_FLOAT64_C(  503.26)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  503.26), SIMDE_FLOAT64_C(  503.26)),
      0 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  927.98), SIMDE_FLOAT64_C( -197.60)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -197.60), SIMDE_FLOAT64_C( -197.60)),
      0 }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    int r = simde_mm_ucomilt_sd(test_vec[i].a, test_vec[i].b);
    munit_assert_int(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_ucomineq_sd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128d a;
    simde__m128d b;
    int r;
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  523.45), SIMDE_FLOAT64_C( -718.90)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   39.72), SIMDE_FLOAT64_C(  184.39)),
      1 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  666.01), SIMDE_FLOAT64_C( -592.10)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -592.10), SIMDE_FLOAT64_C( -592.10)),
      0 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  840.01), SIMDE_FLOAT64_C( -550.36)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -550.36), SIMDE_FLOAT64_C( -701.38)),
      1 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -236.99), SIMDE_FLOAT64_C(  791.25)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  791.25), SIMDE_FLOAT64_C(  791.25)),
      0 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  743.24), SIMDE_FLOAT64_C(  945.47)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  945.47), SIMDE_FLOAT64_C(  844.58)),
      1 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  938.39), SIMDE_FLOAT64_C( -590.62)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -590.62), SIMDE_FLOAT64_C( -183.26)),
      1 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  876.49), SIMDE_FLOAT64_C(  503.26)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  503.26), SIMDE_FLOAT64_C(  503.26)),
      0 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  927.98), SIMDE_FLOAT64_C( -197.60)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -197.60), SIMDE_FLOAT64_C( -197.60)),
      0 }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    int r = simde_mm_ucomineq_sd(test_vec[i].a, test_vec[i].b);
    munit_assert_int(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_unpackhi_epi8(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi8(INT8_C( -36), INT8_C(  95), INT8_C(  84), INT8_C(-106), INT8_C(  32), INT8_C( 120), INT8_C(  19), INT8_C( -16),
                        INT8_C(  46), INT8_C(-123), INT8_C(-117), INT8_C(  46), INT8_C(  18), INT8_C( -72), INT8_C( -36), INT8_C(  78)),
      simde_mm_set_epi8(INT8_C(  10), INT8_C(-106), INT8_C( -91), INT8_C( -62), INT8_C( -61), INT8_C( -62), INT8_C( -83), INT8_C( -45),
                        INT8_C( -36), INT8_C(  17), INT8_C(  58), INT8_C(-114), INT8_C(  96), INT8_C(-102), INT8_C( -89), INT8_C( -20)),
      simde_mm_set_epi8(INT8_C(  10), INT8_C( -36), INT8_C(-106), INT8_C(  95), INT8_C( -91), INT8_C(  84), INT8_C( -62), INT8_C(-106),
                        INT8_C( -61), INT8_C(  32), INT8_C( -62), INT8_C( 120), INT8_C( -83), INT8_C(  19), INT8_C( -45), INT8_C( -16)) },
    { simde_mm_set_epi8(INT8_C( -54), INT8_C(-123), INT8_C(  74), INT8_C(  62), INT8_C(  43), INT8_C(  85), INT8_C( -99), INT8_C( -95),
                        INT8_C( -93), INT8_C( -92), INT8_C( 121), INT8_C(  82), INT8_C(  61), INT8_C(-110), INT8_C(-111), INT8_C( -40)),
      simde_mm_set_epi8(INT8_C(  61), INT8_C( -50), INT8_C(  88), INT8_C( -56), INT8_C(  14), INT8_C( -92), INT8_C(-109), INT8_C( -80),
                        INT8_C( -22), INT8_C( -61), INT8_C(-108), INT8_C(  69), INT8_C( -82), INT8_C(  29), INT8_C(  38), INT8_C( -72)),
      simde_mm_set_epi8(INT8_C(  61), INT8_C( -54), INT8_C( -50), INT8_C(-123), INT8_C(  88), INT8_C(  74), INT8_C( -56), INT8_C(  62),
                        INT8_C(  14), INT8_C(  43), INT8_C( -92), INT8_C(  85), INT8_C(-109), INT8_C( -99), INT8_C( -80), INT8_C( -95)) },
    { simde_mm_set_epi8(INT8_C(-103), INT8_C( -78), INT8_C( -94), INT8_C( -12), INT8_C( -31), INT8_C( -92), INT8_C( -17), INT8_C(  16),
                        INT8_C(-122), INT8_C( 113), INT8_C( -48), INT8_C( -99), INT8_C(  32), INT8_C( -67), INT8_C( 124), INT8_C( 107)),
      simde_mm_set_epi8(INT8_C(  42), INT8_C(  65), INT8_C( -45), INT8_C( -19), INT8_C( -55), INT8_C( -49), INT8_C( -54), INT8_C(  56),
                        INT8_C( -67), INT8_C( -54), INT8_C(-109), INT8_C( -80), INT8_C( -85), INT8_C(  96), INT8_C( -36), INT8_C( -69)),
      simde_mm_set_epi8(INT8_C(  42), INT8_C(-103), INT8_C(  65), INT8_C( -78), INT8_C( -45), INT8_C( -94), INT8_C( -19), INT8_C( -12),
                        INT8_C( -55), INT8_C( -31), INT8_C( -49), INT8_C( -92), INT8_C( -54), INT8_C( -17), INT8_C(  56), INT8_C(  16)) },
    { simde_mm_set_epi8(INT8_C( -33), INT8_C(  -6), INT8_C( -31), INT8_C( -33), INT8_C( -45), INT8_C( -71), INT8_C( 119), INT8_C(  79),
                        INT8_C(  29), INT8_C(   8), INT8_C( -44), INT8_C( -42), INT8_C( 113), INT8_C( -23), INT8_C(  53), INT8_C(-118)),
      simde_mm_set_epi8(INT8_C(  -4), INT8_C( -47), INT8_C( -67), INT8_C(  41), INT8_C(  84), INT8_C(   5), INT8_C( -24), INT8_C( 123),
                        INT8_C( 102), INT8_C( -69), INT8_C(  66), INT8_C( 117), INT8_C(-128), INT8_C( 115), INT8_C(  -2), INT8_C( -19)),
      simde_mm_set_epi8(INT8_C(  -4), INT8_C( -33), INT8_C( -47), INT8_C(  -6), INT8_C( -67), INT8_C( -31), INT8_C(  41), INT8_C( -33),
                        INT8_C(  84), INT8_C( -45), INT8_C(   5), INT8_C( -71), INT8_C( -24), INT8_C( 119), INT8_C( 123), INT8_C(  79)) },
    { simde_mm_set_epi8(INT8_C(-100), INT8_C( -57), INT8_C(  -5), INT8_C(-111), INT8_C( 124), INT8_C(-127), INT8_C( -90), INT8_C( -88),
                        INT8_C(  23), INT8_C(-114), INT8_C( -41), INT8_C( -98), INT8_C(  73), INT8_C(  14), INT8_C(   5), INT8_C(  46)),
      simde_mm_set_epi8(INT8_C(  66), INT8_C(-115), INT8_C( -36), INT8_C( -25), INT8_C( -75), INT8_C(-124), INT8_C(  96), INT8_C(  16),
                        INT8_C(  14), INT8_C( 103), INT8_C( -98), INT8_C(-105), INT8_C( -21), INT8_C( -89), INT8_C( -87), INT8_C( -43)),
      simde_mm_set_epi8(INT8_C(  66), INT8_C(-100), INT8_C(-115), INT8_C( -57), INT8_C( -36), INT8_C(  -5), INT8_C( -25), INT8_C(-111),
                        INT8_C( -75), INT8_C( 124), INT8_C(-124), INT8_C(-127), INT8_C(  96), INT8_C( -90), INT8_C(  16), INT8_C( -88)) },
    { simde_mm_set_epi8(INT8_C( -66), INT8_C( -23), INT8_C( -71), INT8_C( 103), INT8_C(  67), INT8_C( -33), INT8_C(-118), INT8_C( -19),
                        INT8_C(  25), INT8_C( -53), INT8_C(  56), INT8_C(  16), INT8_C(-126), INT8_C( 121), INT8_C(  96), INT8_C(-121)),
      simde_mm_set_epi8(INT8_C( -16), INT8_C(  18), INT8_C(  55), INT8_C(-104), INT8_C(-120), INT8_C(  39), INT8_C( -14), INT8_C(  76),
                        INT8_C(  39), INT8_C(  41), INT8_C( -81), INT8_C(  -9), INT8_C( -56), INT8_C(-103), INT8_C(   3), INT8_C( -27)),
      simde_mm_set_epi8(INT8_C( -16), INT8_C( -66), INT8_C(  18), INT8_C( -23), INT8_C(  55), INT8_C( -71), INT8_C(-104), INT8_C( 103),
                        INT8_C(-120), INT8_C(  67), INT8_C(  39), INT8_C( -33), INT8_C( -14), INT8_C(-118), INT8_C(  76), INT8_C( -19)) },
    { simde_mm_set_epi8(INT8_C( 114), INT8_C( -36), INT8_C(  60), INT8_C( -26), INT8_C(  24), INT8_C( -63), INT8_C( -29), INT8_C( 114),
                        INT8_C(  74), INT8_C( -94), INT8_C(  33), INT8_C( -33), INT8_C(  38), INT8_C( 109), INT8_C(  31), INT8_C( -91)),
      simde_mm_set_epi8(INT8_C( -28), INT8_C( -92), INT8_C(  30), INT8_C(-101), INT8_C(  -7), INT8_C(   1), INT8_C(-108), INT8_C(  29),
                        INT8_C( 114), INT8_C(  44), INT8_C(  -8), INT8_C(-107), INT8_C( -68), INT8_C(  90), INT8_C( 100), INT8_C( -37)),
      simde_mm_set_epi8(INT8_C( -28), INT8_C( 114), INT8_C( -92), INT8_C( -36), INT8_C(  30), INT8_C(  60), INT8_C(-101), INT8_C( -26),
                        INT8_C(  -7), INT8_C(  24), INT8_C(   1), INT8_C( -63), INT8_C(-108), INT8_C( -29), INT8_C(  29), INT8_C( 114)) },
    { simde_mm_set_epi8(INT8_C(  83), INT8_C( -32), INT8_C( -17), INT8_C( -35), INT8_C(  52), INT8_C( -64), INT8_C(  46), INT8_C(  89),
                        INT8_C( -65), INT8_C( -27), INT8_C(-104), INT8_C(   5), INT8_C(  84), INT8_C(  41), INT8_C(  88), INT8_C(  34)),
      simde_mm_set_epi8(INT8_C( -95), INT8_C(  93), INT8_C(-118), INT8_C( -44), INT8_C(  65), INT8_C( 114), INT8_C(  28), INT8_C( -90),
                        INT8_C( -85), INT8_C( 102), INT8_C(  78), INT8_C( -99), INT8_C(-120), INT8_C(  43), INT8_C( -56), INT8_C(  25)),
      simde_mm_set_epi8(INT8_C( -95), INT8_C(  83), INT8_C(  93), INT8_C( -32), INT8_C(-118), INT8_C( -17), INT8_C( -44), INT8_C( -35),
                        INT8_C(  65), INT8_C(  52), INT8_C( 114), INT8_C( -64), INT8_C(  28), INT8_C(  46), INT8_C( -90), INT8_C(  89)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_unpackhi_epi8(test_vec[i].a, test_vec[i].b);
    simde_assert_m128i_i8(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_unpackhi_epi16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi16( 18787,  30957,   6745,   5288, -10333,  29461,    961, -14007),
      simde_mm_set_epi16(-29691,  32561, -16442,  -4659,  21222, -21527,  30610,  14168),
      simde_mm_set_epi16(-29691,  18787,  32561,  30957, -16442,   6745,  -4659,   5288) },
    { simde_mm_set_epi16( 14241, -17353,  15871,   3653, -29200,  -9979, -30607,  31741),
      simde_mm_set_epi16( 16753,  10981,  24190,  25811,   6793,  -6051,   1979, -14675),
      simde_mm_set_epi16( 16753,  14241,  10981, -17353,  24190,  15871,  25811,   3653) },
    { simde_mm_set_epi16( 24118,  -7950,   8813,  23815, -12880,  22441, -31736,  28417),
      simde_mm_set_epi16( -2535, -21518,  10955, -16484, -17119,   5667,   5018,  -9313),
      simde_mm_set_epi16( -2535,  24118, -21518,  -7950,  10955,   8813, -16484,  23815) },
    { simde_mm_set_epi16(-15717,   7765, -27156,  26721,  -2021,  -7166,    832,   3368),
      simde_mm_set_epi16(-17604,  -2433, -22343,  -9047,  -8009, -14884, -31015,   9072),
      simde_mm_set_epi16(-17604, -15717,  -2433,   7765, -22343, -27156,  -9047,  26721) },
    { simde_mm_set_epi16(  9613, -25734, -29111,  -6271,  28183,   5627,  23471, -31640),
      simde_mm_set_epi16( 17448, -17387,  12535,  19499,  11772,   2463,  20494,  -6320),
      simde_mm_set_epi16( 17448,   9613, -17387, -25734,  12535, -29111,  19499,  -6271) },
    { simde_mm_set_epi16(-23597, -19655, -17057,  18059,   9484,   5905,  26068,   7424),
      simde_mm_set_epi16(-16983,  -3720, -18613,   7615, -29369, -17019,    736,  23842),
      simde_mm_set_epi16(-16983, -23597,  -3720, -19655, -18613, -17057,   7615,  18059) },
    { simde_mm_set_epi16( 10339,   5875, -28772,   4220,  31801,  29049,  31270, -18878),
      simde_mm_set_epi16(-18888,  24242, -31726, -29025,    845,  -8031,   4992,  -3599),
      simde_mm_set_epi16(-18888,  10339,  24242,   5875, -31726, -28772, -29025,   4220) },
    { simde_mm_set_epi16(-14097,  31063, -25063,  16951, -20725,   5387,  -3219, -20465),
      simde_mm_set_epi16(-23465, -30434,  28479, -15276, -28694,  -9228,  22420, -31453),
      simde_mm_set_epi16(-23465, -14097, -30434,  31063,  28479, -25063, -15276,  16951) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_unpackhi_epi16(test_vec[i].a, test_vec[i].b);
    simde_assert_m128i_i16(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_unpackhi_epi32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi32(INT32_C(  168291084), INT32_C(  803222516), INT32_C(-2059191165), INT32_C(  156619127)),
      simde_mm_set_epi32(INT32_C( 1247164255), INT32_C(-1585504202), INT32_C(   81979034), INT32_C(-1257437380)),
      simde_mm_set_epi32(INT32_C( 1247164255), INT32_C(  168291084), INT32_C(-1585504202), INT32_C(  803222516)) },
    { simde_mm_set_epi32(INT32_C(-1229392695), INT32_C( -447420261), INT32_C(  -26173961), INT32_C( 1549193795)),
      simde_mm_set_epi32(INT32_C(-1584985518), INT32_C(-1825626458), INT32_C( 1790250510), INT32_C( -280669042)),
      simde_mm_set_epi32(INT32_C(-1584985518), INT32_C(-1229392695), INT32_C(-1825626458), INT32_C( -447420261)) },
    { simde_mm_set_epi32(INT32_C( -648698663), INT32_C( 1485053046), INT32_C(-2125470397), INT32_C(  507664294)),
      simde_mm_set_epi32(INT32_C( -735759218), INT32_C( -710175418), INT32_C(-1695159870), INT32_C(-1167064304)),
      simde_mm_set_epi32(INT32_C( -735759218), INT32_C( -648698663), INT32_C( -710175418), INT32_C( 1485053046)) },
    { simde_mm_set_epi32(INT32_C( -103259786), INT32_C( -188357300), INT32_C(  452180145), INT32_C(-1396420115)),
      simde_mm_set_epi32(INT32_C( 1404727965), INT32_C( -804737565), INT32_C(-1054802326), INT32_C( 1642647928)),
      simde_mm_set_epi32(INT32_C( 1404727965), INT32_C( -103259786), INT32_C( -804737565), INT32_C( -188357300)) },
    { simde_mm_set_epi32(INT32_C( 1212827068), INT32_C( 1189440629), INT32_C(-1547155816), INT32_C( 1839063433)),
      simde_mm_set_epi32(INT32_C(  796540528), INT32_C( -982269468), INT32_C(  -40316418), INT32_C( -430354120)),
      simde_mm_set_epi32(INT32_C(  796540528), INT32_C( 1212827068), INT32_C( -982269468), INT32_C( 1189440629)) },
    { simde_mm_set_epi32(INT32_C( 1356454008), INT32_C( -215878264), INT32_C(-1695191474), INT32_C(  378220333)),
      simde_mm_set_epi32(INT32_C( -864195447), INT32_C(-1443486627), INT32_C(-2133730470), INT32_C(  373467456)),
      simde_mm_set_epi32(INT32_C( -864195447), INT32_C( 1356454008), INT32_C(-1443486627), INT32_C( -215878264)) },
    { simde_mm_set_epi32(INT32_C(  764442598), INT32_C( 1720554406), INT32_C( 1938751418), INT32_C( 1005471402)),
      simde_mm_set_epi32(INT32_C(  883878116), INT32_C(  255422854), INT32_C(  583152961), INT32_C( -594123403)),
      simde_mm_set_epi32(INT32_C(  883878116), INT32_C(  764442598), INT32_C(  255422854), INT32_C( 1720554406)) },
    { simde_mm_set_epi32(INT32_C( -822423451), INT32_C( -180339328), INT32_C( -689601673), INT32_C(-1524838623)),
      simde_mm_set_epi32(INT32_C( -665157473), INT32_C(-2141208691), INT32_C(-1935796365), INT32_C( -482464349)),
      simde_mm_set_epi32(INT32_C( -665157473), INT32_C( -822423451), INT32_C(-2141208691), INT32_C( -180339328)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_unpackhi_epi32(test_vec[i].a, test_vec[i].b);
    simde_assert_m128i_i32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_unpackhi_epi64(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi64x(INT64_C(  722804702791611380), INT64_C(-8844158709730520713)),
      simde_mm_set_epi64x(INT64_C( 5356529690674667574), INT64_C(  352097273025201980)),
      simde_mm_set_epi64x(INT64_C( 5356529690674667574), INT64_C(  722804702791611380)) },
    { simde_mm_set_epi64x(INT64_C(-5280201415118755685), INT64_C( -112416304952585661)),
      simde_mm_set_epi64x(INT64_C(-6807460961974278490), INT64_C( 7689067396111619214)),
      simde_mm_set_epi64x(INT64_C(-6807460961974278490), INT64_C(-5280201415118755685)) },
    { simde_mm_set_epi64x(INT64_C(-2786139541058872202), INT64_C(-9128825843223472218)),
      simde_mm_set_epi64x(INT64_C(-3160061775455742650), INT64_C(-7280656200013708528)),
      simde_mm_set_epi64x(INT64_C(-3160061775455742650), INT64_C(-2786139541058872202)) },
    { simde_mm_set_epi64x(INT64_C( -443497399755348660), INT64_C( 1942098937574085101)),
      simde_mm_set_epi64x(INT64_C( 6033260672941862371), INT64_C(-4530341492272082568)),
      simde_mm_set_epi64x(INT64_C( 6033260672941862371), INT64_C( -443497399755348660)) },
    { simde_mm_set_epi64x(INT64_C( 5209052593953008757), INT64_C(-6644983629697130103)),
      simde_mm_set_epi64x(INT64_C( 3421115521011270116), INT64_C( -173157692937252552)),
      simde_mm_set_epi64x(INT64_C( 3421115521011270116), INT64_C( 5209052593953008757)) },
    { simde_mm_set_epi64x(INT64_C( 5825925606967211400), INT64_C(-7280791940909813971)),
      simde_mm_set_epi64x(INT64_C(-3711691179365620643), INT64_C(-9164302586755241664)),
      simde_mm_set_epi64x(INT64_C(-3711691179365620643), INT64_C( 5825925606967211400)) },
    { simde_mm_set_epi64x(INT64_C( 3283255959799829414), INT64_C( 8326873936389097130)),
      simde_mm_set_epi64x(INT64_C( 3796227602125517190), INT64_C( 2504622899761407349)),
      simde_mm_set_epi64x(INT64_C( 3796227602125517190), INT64_C( 3283255959799829414)) },
    { simde_mm_set_epi64x(INT64_C(-3532281821393830528), INT64_C(-2961816630031757535)),
      simde_mm_set_epi64x(INT64_C(-2856829591071244403), INT64_C(-8314182075578176093)),
      simde_mm_set_epi64x(INT64_C(-2856829591071244403), INT64_C(-3532281821393830528)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_unpackhi_epi64(test_vec[i].a, test_vec[i].b);
    simde_assert_m128i_i64(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_unpackhi_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128d a;
    simde__m128d b;
    simde__m128d r;
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -788.38), SIMDE_FLOAT64_C(  -23.22)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -996.21), SIMDE_FLOAT64_C(  645.47)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -996.21), SIMDE_FLOAT64_C( -788.38)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -986.13), SIMDE_FLOAT64_C(  267.77)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  401.03), SIMDE_FLOAT64_C(  978.53)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  401.03), SIMDE_FLOAT64_C( -986.13)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -468.32), SIMDE_FLOAT64_C( -478.73)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -484.79), SIMDE_FLOAT64_C( -613.68)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -484.79), SIMDE_FLOAT64_C( -468.32)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  169.21), SIMDE_FLOAT64_C(  897.06)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -872.63), SIMDE_FLOAT64_C( -172.69)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -872.63), SIMDE_FLOAT64_C(  169.21)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  499.02), SIMDE_FLOAT64_C(   28.99)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  532.77), SIMDE_FLOAT64_C( -718.79)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  532.77), SIMDE_FLOAT64_C(  499.02)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  208.34), SIMDE_FLOAT64_C(  635.19)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -165.40), SIMDE_FLOAT64_C(  391.08)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -165.40), SIMDE_FLOAT64_C(  208.34)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -371.80), SIMDE_FLOAT64_C(  698.49)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  603.26), SIMDE_FLOAT64_C(  962.25)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  603.26), SIMDE_FLOAT64_C( -371.80)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -939.32), SIMDE_FLOAT64_C(  149.18)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  349.36), SIMDE_FLOAT64_C(  -60.66)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  349.36), SIMDE_FLOAT64_C( -939.32)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_unpackhi_pd(test_vec[i].a, test_vec[i].b);
    simde_assert_m128d_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_unpacklo_epi8(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi8(INT8_C( -46), INT8_C(  11), INT8_C( -95), INT8_C(  -6), INT8_C(-108), INT8_C(-107), INT8_C( -24), INT8_C( -94),
                        INT8_C( -54), INT8_C(   2), INT8_C( 111), INT8_C(  78), INT8_C(  16), INT8_C( -54), INT8_C( -31), INT8_C( -19)),
      simde_mm_set_epi8(INT8_C(  40), INT8_C( -29), INT8_C( -79), INT8_C( -49), INT8_C(  12), INT8_C( -63), INT8_C(  87), INT8_C(  55),
                        INT8_C( 121), INT8_C( 100), INT8_C( -21), INT8_C(  -2), INT8_C( -22), INT8_C(  29), INT8_C( 110), INT8_C(-110)),
      simde_mm_set_epi8(INT8_C( 121), INT8_C( -54), INT8_C( 100), INT8_C(   2), INT8_C( -21), INT8_C( 111), INT8_C(  -2), INT8_C(  78),
                        INT8_C( -22), INT8_C(  16), INT8_C(  29), INT8_C( -54), INT8_C( 110), INT8_C( -31), INT8_C(-110), INT8_C( -19)) },
    { simde_mm_set_epi8(INT8_C(  40), INT8_C( -52), INT8_C( -72), INT8_C(   9), INT8_C( -57), INT8_C( -62), INT8_C(-100), INT8_C( 119),
                        INT8_C( 120), INT8_C( -83), INT8_C( 102), INT8_C( -39), INT8_C( -78), INT8_C( -92), INT8_C( -76), INT8_C( 121)),
      simde_mm_set_epi8(INT8_C(   7), INT8_C( -69), INT8_C(-112), INT8_C(  84), INT8_C(  -8), INT8_C(  23), INT8_C(  71), INT8_C( -37),
                        INT8_C( 104), INT8_C(-121), INT8_C( -93), INT8_C(  99), INT8_C(  47), INT8_C(-114), INT8_C( -52), INT8_C( 101)),
      simde_mm_set_epi8(INT8_C( 104), INT8_C( 120), INT8_C(-121), INT8_C( -83), INT8_C( -93), INT8_C( 102), INT8_C(  99), INT8_C( -39),
                        INT8_C(  47), INT8_C( -78), INT8_C(-114), INT8_C( -92), INT8_C( -52), INT8_C( -76), INT8_C( 101), INT8_C( 121)) },
    { simde_mm_set_epi8(INT8_C(  23), INT8_C(  31), INT8_C( -95), INT8_C( -23), INT8_C( -83), INT8_C(  40), INT8_C( -32), INT8_C(  -4),
                        INT8_C(  97), INT8_C( 107), INT8_C(-118), INT8_C(  28), INT8_C(  58), INT8_C( -42), INT8_C(   6), INT8_C(  14)),
      simde_mm_set_epi8(INT8_C(  87), INT8_C( -63), INT8_C(  17), INT8_C( -66), INT8_C( -73), INT8_C( -52), INT8_C(  21), INT8_C( -51),
                        INT8_C(  77), INT8_C( 127), INT8_C(-123), INT8_C(  35), INT8_C( -87), INT8_C(  10), INT8_C(-116), INT8_C( -15)),
      simde_mm_set_epi8(INT8_C(  77), INT8_C(  97), INT8_C( 127), INT8_C( 107), INT8_C(-123), INT8_C(-118), INT8_C(  35), INT8_C(  28),
                        INT8_C( -87), INT8_C(  58), INT8_C(  10), INT8_C( -42), INT8_C(-116), INT8_C(   6), INT8_C( -15), INT8_C(  14)) },
    { simde_mm_set_epi8(INT8_C(  82), INT8_C( -82), INT8_C( 120), INT8_C(-117), INT8_C(  95), INT8_C(  34), INT8_C(  57), INT8_C(-126),
                        INT8_C( 125), INT8_C( -41), INT8_C(  26), INT8_C( -67), INT8_C( -28), INT8_C( 110), INT8_C(  56), INT8_C(   8)),
      simde_mm_set_epi8(INT8_C(  43), INT8_C(  84), INT8_C( -22), INT8_C( -23), INT8_C(-118), INT8_C( 101), INT8_C( -61), INT8_C(   0),
                        INT8_C( 102), INT8_C(  10), INT8_C( -14), INT8_C( -26), INT8_C( -16), INT8_C(  -9), INT8_C(-102), INT8_C(  -6)),
      simde_mm_set_epi8(INT8_C( 102), INT8_C( 125), INT8_C(  10), INT8_C( -41), INT8_C( -14), INT8_C(  26), INT8_C( -26), INT8_C( -67),
                        INT8_C( -16), INT8_C( -28), INT8_C(  -9), INT8_C( 110), INT8_C(-102), INT8_C(  56), INT8_C(  -6), INT8_C(   8)) },
    { simde_mm_set_epi8(INT8_C( -53), INT8_C( -22), INT8_C(  64), INT8_C( -17), INT8_C( -84), INT8_C(-128), INT8_C(-124), INT8_C( -98),
                        INT8_C( -10), INT8_C( -24), INT8_C(  47), INT8_C( 109), INT8_C(  15), INT8_C( -93), INT8_C(  -3), INT8_C( -83)),
      simde_mm_set_epi8(INT8_C( 102), INT8_C(  24), INT8_C(  10), INT8_C(  77), INT8_C( -47), INT8_C( 121), INT8_C(  -9), INT8_C(  31),
                        INT8_C(   5), INT8_C(  32), INT8_C( -40), INT8_C(  72), INT8_C(-114), INT8_C( -28), INT8_C(  76), INT8_C(  98)),
      simde_mm_set_epi8(INT8_C(   5), INT8_C( -10), INT8_C(  32), INT8_C( -24), INT8_C( -40), INT8_C(  47), INT8_C(  72), INT8_C( 109),
                        INT8_C(-114), INT8_C(  15), INT8_C( -28), INT8_C( -93), INT8_C(  76), INT8_C(  -3), INT8_C(  98), INT8_C( -83)) },
    { simde_mm_set_epi8(INT8_C(  42), INT8_C(-126), INT8_C( -81), INT8_C(  -3), INT8_C(  60), INT8_C( -79), INT8_C(  80), INT8_C( -92),
                        INT8_C( -48), INT8_C(  40), INT8_C(-125), INT8_C(  24), INT8_C(  38), INT8_C( -84), INT8_C( 120), INT8_C(  92)),
      simde_mm_set_epi8(INT8_C(-118), INT8_C(-121), INT8_C(  29), INT8_C(-128), INT8_C(-101), INT8_C(   4), INT8_C( -66), INT8_C(  29),
                        INT8_C(  -3), INT8_C(  82), INT8_C(  -7), INT8_C( -87), INT8_C(  76), INT8_C(  52), INT8_C(-124), INT8_C(  86)),
      simde_mm_set_epi8(INT8_C(  -3), INT8_C( -48), INT8_C(  82), INT8_C(  40), INT8_C(  -7), INT8_C(-125), INT8_C( -87), INT8_C(  24),
                        INT8_C(  76), INT8_C(  38), INT8_C(  52), INT8_C( -84), INT8_C(-124), INT8_C( 120), INT8_C(  86), INT8_C(  92)) },
    { simde_mm_set_epi8(INT8_C(-121), INT8_C( 102), INT8_C( -71), INT8_C(-105), INT8_C(-120), INT8_C( 124), INT8_C( -56), INT8_C(  80),
                        INT8_C( -23), INT8_C(  26), INT8_C(-103), INT8_C(  31), INT8_C( -30), INT8_C( -86), INT8_C( 103), INT8_C( -93)),
      simde_mm_set_epi8(INT8_C(-114), INT8_C(   9), INT8_C(  28), INT8_C( -23), INT8_C( 125), INT8_C(  28), INT8_C( -55), INT8_C( -13),
                        INT8_C( -41), INT8_C( 123), INT8_C( -52), INT8_C(  49), INT8_C( -94), INT8_C( -66), INT8_C(  69), INT8_C(  75)),
      simde_mm_set_epi8(INT8_C( -41), INT8_C( -23), INT8_C( 123), INT8_C(  26), INT8_C( -52), INT8_C(-103), INT8_C(  49), INT8_C(  31),
                        INT8_C( -94), INT8_C( -30), INT8_C( -66), INT8_C( -86), INT8_C(  69), INT8_C( 103), INT8_C(  75), INT8_C( -93)) },
    { simde_mm_set_epi8(INT8_C( -30), INT8_C(  56), INT8_C(  -7), INT8_C( -85), INT8_C(  -3), INT8_C( -30), INT8_C(  87), INT8_C( 101),
                        INT8_C(-112), INT8_C( -18), INT8_C(   7), INT8_C(  45), INT8_C(  32), INT8_C( 103), INT8_C(  -2), INT8_C( 100)),
      simde_mm_set_epi8(INT8_C(  75), INT8_C( -55), INT8_C(   1), INT8_C(  61), INT8_C(-126), INT8_C( -76), INT8_C(  61), INT8_C( -69),
                        INT8_C( -86), INT8_C( 110), INT8_C( -52), INT8_C( 110), INT8_C(  96), INT8_C( -55), INT8_C(  76), INT8_C(  15)),
      simde_mm_set_epi8(INT8_C( -86), INT8_C(-112), INT8_C( 110), INT8_C( -18), INT8_C( -52), INT8_C(   7), INT8_C( 110), INT8_C(  45),
                        INT8_C(  96), INT8_C(  32), INT8_C( -55), INT8_C( 103), INT8_C(  76), INT8_C(  -2), INT8_C(  15), INT8_C( 100)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_unpacklo_epi8(test_vec[i].a, test_vec[i].b);
    simde_assert_m128i_i8(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_unpacklo_epi16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi16(-11765, -24070, -27499,  -5982, -13822,  28494,   4298,  -7699),
      simde_mm_set_epi16( 10467, -20017,   3265,  22327,  31076,  -5122,  -5603,  28306),
      simde_mm_set_epi16( 31076, -13822,  -5122,  28494,  -5603,   4298,  28306,  -7699) },
    { simde_mm_set_epi16( 10444, -18423, -14398, -25481,  30893,  26329, -19804, -19335),
      simde_mm_set_epi16(  1979, -28588,  -2025,  18395,  26759, -23709,  12174, -13211),
      simde_mm_set_epi16( 26759,  30893, -23709,  26329,  12174, -19804, -13211, -19335) },
    { simde_mm_set_epi16(  5919, -24087, -21208,  -7940,  24939, -30180,  15062,   1550),
      simde_mm_set_epi16( 22465,   4542, -18484,   5581,  19839, -31453, -22262, -29455),
      simde_mm_set_epi16( 19839,  24939, -31453, -30180, -22262,  15062, -29455,   1550) },
    { simde_mm_set_epi16( 21166,  30859,  24354,  14722,  32215,   6845,  -7058,  14344),
      simde_mm_set_epi16( 11092,  -5399, -30107, -15616,  26122,  -3354,  -3849, -25862),
      simde_mm_set_epi16( 26122,  32215,  -3354,   6845,  -3849,  -7058, -25862,  14344) },
    { simde_mm_set_epi16(-13334,  16623, -21376, -31586,  -2328,  12141,   4003,   -595),
      simde_mm_set_epi16( 26136,   2637, -11911,  -2273,   1312, -10168, -28956,  19554),
      simde_mm_set_epi16(  1312,  -2328, -10168,  12141, -28956,   4003,  19554,   -595) },
    { simde_mm_set_epi16( 10882, -20483,  15537,  20644, -12248, -31976,   9900,  30812),
      simde_mm_set_epi16(-30073,   7552, -25852, -16867,   -686,  -1623,  19508, -31658),
      simde_mm_set_epi16(  -686, -12248,  -1623, -31976,  19508,   9900, -31658,  30812) },
    { simde_mm_set_epi16(-30874, -18025, -30596, -14256,  -5862, -26337,  -7510,  26531),
      simde_mm_set_epi16(-29175,   7401,  32028, -13837, -10373, -13263, -23874,  17739),
      simde_mm_set_epi16(-10373,  -5862, -13263, -26337, -23874,  -7510,  17739,  26531) },
    { simde_mm_set_epi16( -7624,  -1621,   -542,  22373, -28434,   1837,   8295,   -412),
      simde_mm_set_epi16( 19401,    317, -32076,  15803, -21906, -13202,  24777,  19471),
      simde_mm_set_epi16(-21906, -28434, -13202,   1837,  24777,   8295,  19471,   -412) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_unpacklo_epi16(test_vec[i].a, test_vec[i].b);
    simde_assert_m128i_i16(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_unpacklo_epi32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi32(INT32_C( -770989574), INT32_C(-1802114910), INT32_C( -905810098), INT32_C(  281731565)),
      simde_mm_set_epi32(INT32_C(  686010831), INT32_C(  213997367), INT32_C( 2036657150), INT32_C( -367169902)),
      simde_mm_set_epi32(INT32_C( 2036657150), INT32_C( -905810098), INT32_C( -367169902), INT32_C(  281731565)) },
    { simde_mm_set_epi32(INT32_C(  684505097), INT32_C( -943547273), INT32_C( 2024629977), INT32_C(-1297828743)),
      simde_mm_set_epi32(INT32_C(  129732692), INT32_C( -132692005), INT32_C( 1753719651), INT32_C(  797887589)),
      simde_mm_set_epi32(INT32_C( 1753719651), INT32_C( 2024629977), INT32_C(  797887589), INT32_C(-1297828743)) },
    { simde_mm_set_epi32(INT32_C(  387949033), INT32_C(-1389829892), INT32_C( 1634437660), INT32_C(  987104782)),
      simde_mm_set_epi32(INT32_C( 1472270782), INT32_C(-1211361843), INT32_C( 1300202787), INT32_C(-1458926351)),
      simde_mm_set_epi32(INT32_C( 1300202787), INT32_C( 1634437660), INT32_C(-1458926351), INT32_C(  987104782)) },
    { simde_mm_set_epi32(INT32_C( 1387165835), INT32_C( 1596078466), INT32_C( 2111249085), INT32_C( -462538744)),
      simde_mm_set_epi32(INT32_C(  726985449), INT32_C(-1973042432), INT32_C( 1711993574), INT32_C( -252208390)),
      simde_mm_set_epi32(INT32_C( 1711993574), INT32_C( 2111249085), INT32_C( -252208390), INT32_C( -462538744)) },
    { simde_mm_set_epi32(INT32_C( -873840401), INT32_C(-1400863586), INT32_C( -152555667), INT32_C(  262405549)),
      simde_mm_set_epi32(INT32_C( 1712851533), INT32_C( -780536033), INT32_C(   86038600), INT32_C(-1897640862)),
      simde_mm_set_epi32(INT32_C(   86038600), INT32_C( -152555667), INT32_C(-1897640862), INT32_C(  262405549)) },
    { simde_mm_set_epi32(INT32_C(  713207805), INT32_C( 1018253476), INT32_C( -802651368), INT32_C(  648837212)),
      simde_mm_set_epi32(INT32_C(-1970856576), INT32_C(-1694188003), INT32_C(  -44893783), INT32_C( 1278510166)),
      simde_mm_set_epi32(INT32_C(  -44893783), INT32_C( -802651368), INT32_C( 1278510166), INT32_C(  648837212)) },
    { simde_mm_set_epi32(INT32_C(-2023310953), INT32_C(-2005088176), INT32_C( -384132833), INT32_C( -492148829)),
      simde_mm_set_epi32(INT32_C(-1912005399), INT32_C( 2099038707), INT32_C( -679752655), INT32_C(-1564588725)),
      simde_mm_set_epi32(INT32_C( -679752655), INT32_C( -384132833), INT32_C(-1564588725), INT32_C( -492148829)) },
    { simde_mm_set_epi32(INT32_C( -499582549), INT32_C(  -35498139), INT32_C(-1863448787), INT32_C(  543686244)),
      simde_mm_set_epi32(INT32_C( 1271464253), INT32_C(-2102116933), INT32_C(-1435579282), INT32_C( 1623804943)),
      simde_mm_set_epi32(INT32_C(-1435579282), INT32_C(-1863448787), INT32_C( 1623804943), INT32_C(  543686244)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_unpacklo_epi32(test_vec[i].a, test_vec[i].b);
    simde_assert_m128i_i32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_unpacklo_epi64(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi64x(INT64_C(-3311375003394119518), INT64_C(-3890424747014823443)),
      simde_mm_set_epi64x(INT64_C( 2946394084060780343), INT64_C( 8747375856342363794)),
      simde_mm_set_epi64x(INT64_C( 8747375856342363794), INT64_C(-3890424747014823443)) },
    { simde_mm_set_epi64x(INT64_C( 2939927008911727735), INT64_C( 8695719540713370745)),
      simde_mm_set_epi64x(INT64_C(  557197673524316123), INT64_C( 7532168548195421285)),
      simde_mm_set_epi64x(INT64_C( 7532168548195421285), INT64_C( 8695719540713370745)) },
    { simde_mm_set_epi64x(INT64_C( 1666228412154962172), INT64_C( 7019856298037872142)),
      simde_mm_set_epi64x(INT64_C( 6323354862629950925), INT64_C( 5584328451169094897)),
      simde_mm_set_epi64x(INT64_C( 5584328451169094897), INT64_C( 7019856298037872142)) },
    { simde_mm_set_epi64x(INT64_C( 5957831897049610626), INT64_C( 9067745777617352712)),
      simde_mm_set_epi64x(INT64_C( 3122378730444800768), INT64_C( 7352956415334914810)),
      simde_mm_set_epi64x(INT64_C( 7352956415334914810), INT64_C( 9067745777617352712)) },
    { simde_mm_set_epi64x(INT64_C(-3753115941324421986), INT64_C( -655221600322060883)),
      simde_mm_set_epi64x(INT64_C( 7356641320652896031), INT64_C(  369532975590952034)),
      simde_mm_set_epi64x(INT64_C(  369532975590952034), INT64_C( -655221600322060883)) },
    { simde_mm_set_epi64x(INT64_C( 3063204198745198756), INT64_C(-3447361375000823716)),
      simde_mm_set_epi64x(INT64_C(-8464764536425759203), INT64_C( -192817328500210602)),
      simde_mm_set_epi64x(INT64_C( -192817328500210602), INT64_C(-3447361375000823716)) },
    { simde_mm_set_epi64x(INT64_C(-8690054370483713968), INT64_C(-1649837951252011101)),
      simde_mm_set_epi64x(INT64_C(-8212000656381392397), INT64_C(-2919515419863792309)),
      simde_mm_set_epi64x(INT64_C(-2919515419863792309), INT64_C(-1649837951252011101)) },
    { simde_mm_set_epi64x(INT64_C(-2145690705347848347), INT64_C(-8003451597392183708)),
      simde_mm_set_epi64x(INT64_C( 5460897386860920251), INT64_C(-6165766065381356529)),
      simde_mm_set_epi64x(INT64_C(-6165766065381356529), INT64_C(-8003451597392183708)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_unpacklo_epi64(test_vec[i].a, test_vec[i].b);
    simde_assert_m128i_i64(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_unpacklo_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128d a;
    simde__m128d b;
    simde__m128d r;
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  160.82), SIMDE_FLOAT64_C( -868.81)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  640.98), SIMDE_FLOAT64_C(  578.20)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  578.20), SIMDE_FLOAT64_C( -868.81)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -900.35), SIMDE_FLOAT64_C(  829.02)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -680.55), SIMDE_FLOAT64_C(  -51.61)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -51.61), SIMDE_FLOAT64_C(  829.02)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  560.63), SIMDE_FLOAT64_C(  395.65)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -681.25), SIMDE_FLOAT64_C(  -57.21)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -57.21), SIMDE_FLOAT64_C(  395.65)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  938.21), SIMDE_FLOAT64_C( -628.45)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -939.59), SIMDE_FLOAT64_C( -183.36)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -183.36), SIMDE_FLOAT64_C( -628.45)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  352.81), SIMDE_FLOAT64_C( -540.34)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -819.35), SIMDE_FLOAT64_C( -238.91)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -238.91), SIMDE_FLOAT64_C( -540.34)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  435.92), SIMDE_FLOAT64_C(  320.63)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -314.42), SIMDE_FLOAT64_C( -394.55)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -394.55), SIMDE_FLOAT64_C(  320.63)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -256.77), SIMDE_FLOAT64_C(  784.61)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -354.05), SIMDE_FLOAT64_C(  -16.87)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -16.87), SIMDE_FLOAT64_C(  784.61)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(   81.23), SIMDE_FLOAT64_C(  882.56)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -661.47), SIMDE_FLOAT64_C( -202.79)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -202.79), SIMDE_FLOAT64_C(  882.56)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_unpacklo_pd(test_vec[i].a, test_vec[i].b);
    simde_assert_m128d_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_xor_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128d a;
    simde__m128d b;
    simde__m128d r;
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  754.54), SIMDE_FLOAT64_C(  311.60)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -44.15), SIMDE_FLOAT64_C(  943.33)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   -0.00), SIMDE_FLOAT64_C(    0.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  426.90), SIMDE_FLOAT64_C(   93.11)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -872.00), SIMDE_FLOAT64_C(  937.77)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   -0.00), SIMDE_FLOAT64_C(    0.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  730.91), SIMDE_FLOAT64_C(  715.51)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  887.10), SIMDE_FLOAT64_C(  758.35)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  189.13), SIMDE_FLOAT64_C( -797.73)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -890.31), SIMDE_FLOAT64_C(  275.51)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   -0.00), SIMDE_FLOAT64_C(   -0.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -844.48), SIMDE_FLOAT64_C(  650.25)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -135.28), SIMDE_FLOAT64_C( -212.75)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(   -0.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -220.34), SIMDE_FLOAT64_C( -131.08)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -898.36), SIMDE_FLOAT64_C( -723.05)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -371.02), SIMDE_FLOAT64_C( -258.68)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -118.33), SIMDE_FLOAT64_C(   54.62)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(   -0.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -938.96), SIMDE_FLOAT64_C(  237.04)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -464.61), SIMDE_FLOAT64_C( -202.17)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(   -0.00)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_xor_pd(test_vec[i].a, test_vec[i].b);
    simde_assert_m128d_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_xor_si128(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi32(INT32_C( 1623880239), INT32_C( 1318620160), INT32_C(-1283662193), INT32_C(-1453845482)),
      simde_mm_set_epi32(INT32_C(-1675083604), INT32_C(  603168286), INT32_C(  409798099), INT32_C(  632966287)),
      simde_mm_set_epi32(INT32_C(  -52284797), INT32_C( 1835733534), INT32_C(-1424893092), INT32_C(-1931323239)) },
    { simde_mm_set_epi32(INT32_C( 1509092554), INT32_C( 1648495442), INT32_C(-1486316171), INT32_C(  868417203)),
      simde_mm_set_epi32(INT32_C( 1183220554), INT32_C(-1650741405), INT32_C(-1277877547), INT32_C( -793058853)),
      simde_mm_set_epi32(INT32_C(  527724416), INT32_C(   -2513871), INT32_C(  347979680), INT32_C( -478666904)) },
    { simde_mm_set_epi32(INT32_C(  373711788), INT32_C(-1451210820), INT32_C( 1218370771), INT32_C( 1535794325)),
      simde_mm_set_epi32(INT32_C( -155546503), INT32_C(-2037105503), INT32_C( 1041195962), INT32_C(-1654529737)),
      simde_mm_set_epi32(INT32_C( -520294443), INT32_C(  789871389), INT32_C( 1989263209), INT32_C( -957629022)) },
    { simde_mm_set_epi32(INT32_C(-1223418601), INT32_C(  332961755), INT32_C(  688173092), INT32_C(  352304516)),
      simde_mm_set_epi32(INT32_C( -734452212), INT32_C( -791801405), INT32_C(  114386244), INT32_C(  996038140)),
      simde_mm_set_epi32(INT32_C( 1663908635), INT32_C(-1021934056), INT32_C(  802542944), INT32_C(  799139960)) },
    { simde_mm_set_epi32(INT32_C( 1204298996), INT32_C( 1777561493), INT32_C(  531158614), INT32_C(-1345218351)),
      simde_mm_set_epi32(INT32_C(  465699923), INT32_C(-1417149028), INT32_C(-1963684061), INT32_C( -837148929)),
      simde_mm_set_epi32(INT32_C( 1544167591), INT32_C(-1032099319), INT32_C(-1789109899), INT32_C( 1640728110)) },
    { simde_mm_set_epi32(INT32_C( 1401162168), INT32_C( -922039657), INT32_C( 1348044504), INT32_C( 1592606181)),
      simde_mm_set_epi32(INT32_C(-1635510345), INT32_C(-1462861610), INT32_C(-1206905626), INT32_C( -326154944)),
      simde_mm_set_epi32(INT32_C( -855630321), INT32_C( 1640254017), INT32_C( -397831618), INT32_C(-1302169435)) },
    { simde_mm_set_epi32(INT32_C(  882266138), INT32_C( 2140233068), INT32_C( -978476725), INT32_C( -962797184)),
      simde_mm_set_epi32(INT32_C( 1476434174), INT32_C(  732384170), INT32_C(  406886944), INT32_C( 1700501859)),
      simde_mm_set_epi32(INT32_C( 1821821156), INT32_C( 1412830918), INT32_C( -571655317), INT32_C(-1547208477)) },
    { simde_mm_set_epi32(INT32_C(  782585313), INT32_C( 1758933973), INT32_C(-1583302414), INT32_C(-1602193751)),
      simde_mm_set_epi32(INT32_C(  760188951), INT32_C(  624290102), INT32_C(  378021852), INT32_C(-1714147587)),
      simde_mm_set_epi32(INT32_C(   65723894), INT32_C( 1306712803), INT32_C(-1222074578), INT32_C(  961828948)) }
  };

  for (size_t i = 0 ; i < sizeof(test_vec) / sizeof(test_vec[0]) ; i++) {
    simde__m128i r = simde_mm_xor_si128(test_vec[i].a, test_vec[i].b);
    simde_assert_m128i_i64(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_x_mm_not_si128(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi32(INT32_C( -817965525), INT32_C( 2140859656), INT32_C(  142941694), INT32_C(-1061432158)),
      simde_mm_set_epi32(INT32_C(  817965524), INT32_C(-2140859657), INT32_C( -142941695), INT32_C( 1061432157)) },
    { simde_mm_set_epi32(INT32_C( 1656377120), INT32_C( 1182756765), INT32_C(  499148047), INT32_C( 1939837842)),
      simde_mm_set_epi32(INT32_C(-1656377121), INT32_C(-1182756766), INT32_C( -499148048), INT32_C(-1939837843)) },
    { simde_mm_set_epi32(INT32_C(-1391390683), INT32_C( -880299242), INT32_C( 1262346433), INT32_C(-1162276292)),
      simde_mm_set_epi32(INT32_C( 1391390682), INT32_C(  880299241), INT32_C(-1262346434), INT32_C( 1162276291)) },
    { simde_mm_set_epi32(INT32_C(  402553699), INT32_C(-1406117325), INT32_C(-1620159472), INT32_C( 1950201834)),
      simde_mm_set_epi32(INT32_C( -402553700), INT32_C( 1406117324), INT32_C( 1620159471), INT32_C(-1950201835)) },
    { simde_mm_set_epi32(INT32_C( 1201512664), INT32_C( -722158977), INT32_C(-1427673018), INT32_C(-1348620069)),
      simde_mm_set_epi32(INT32_C(-1201512665), INT32_C(  722158976), INT32_C( 1427673017), INT32_C( 1348620068)) },
    { simde_mm_set_epi32(INT32_C( 2022239253), INT32_C(  336656978), INT32_C(-2043097029), INT32_C( 2060912582)),
      simde_mm_set_epi32(INT32_C(-2022239254), INT32_C( -336656979), INT32_C( 2043097028), INT32_C(-2060912583)) },
    { simde_mm_set_epi32(INT32_C(-1767401405), INT32_C(  988173440), INT32_C(  653493949), INT32_C( 1545873213)),
      simde_mm_set_epi32(INT32_C( 1767401404), INT32_C( -988173441), INT32_C( -653493950), INT32_C(-1545873214)) },
    { simde_mm_set_epi32(INT32_C(  164259681), INT32_C( 1625402133), INT32_C(  274817939), INT32_C( 1382941610)),
      simde_mm_set_epi32(INT32_C( -164259682), INT32_C(-1625402134), INT32_C( -274817940), INT32_C(-1382941611)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_x_mm_not_si128(test_vec[i].a);
    simde_assert_m128i_i32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_x_mm_mul_epi64(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi64x(INT64_C(-6673265146157132667), INT64_C(-8036865195274064518)),
      simde_mm_set_epi64x(INT64_C( 4763310881806863840), INT64_C(-2953190602401137090)),
      simde_mm_set_epi64x(INT64_C(  804621865193403744), INT64_C( 7037306546512957324)) },
    { simde_mm_set_epi64x(INT64_C( 4912321112367014754), INT64_C( 5506077972841640415)),
      simde_mm_set_epi64x(INT64_C( 5790159379234202843), INT64_C(-7860297575342104977)),
      simde_mm_set_epi64x(INT64_C(-6503632121046397738), INT64_C(-1366099594229104207)) },
    { simde_mm_set_epi64x(INT64_C( 2749162021411530208), INT64_C(  408462426494202626)),
      simde_mm_set_epi64x(INT64_C( 8447492608754880299), INT64_C(-7046703966410124624)),
      simde_mm_set_epi64x(INT64_C(-4973831282761794400), INT64_C( 2599589224149726560)) },
    { simde_mm_set_epi64x(INT64_C(  -88834185851708236), INT64_C(-8089393205327952234)),
      simde_mm_set_epi64x(INT64_C(  381269932343520540), INT64_C( 2138325983301945876)),
      simde_mm_set_epi64x(INT64_C(-7088569628310845520), INT64_C( 1233235991476166584)) },
    { simde_mm_set_epi64x(INT64_C( -822706701071313394), INT64_C(-2759012498076821456)),
      simde_mm_set_epi64x(INT64_C( 3465917358098376677), INT64_C(-7954598628423398790)),
      simde_mm_set_epi64x(INT64_C(-6698232051336684410), INT64_C(-6956668788971772192)) },
    { simde_mm_set_epi64x(INT64_C( 8188114688325369058), INT64_C(-5073366312523094897)),
      simde_mm_set_epi64x(INT64_C(-8915693716470801407), INT64_C( 9186903668894606147)),
      simde_mm_set_epi64x(INT64_C( 3677373050832155874), INT64_C(-2924803137816977811)) },
    { simde_mm_set_epi64x(INT64_C(-5966336380315033651), INT64_C( 8263120995643775133)),
      simde_mm_set_epi64x(INT64_C(-4262947749795433008), INT64_C(-8185205248719856231)),
      simde_mm_set_epi64x(INT64_C(-5369329972927887472), INT64_C(-4868166633591505195)) },
    { simde_mm_set_epi64x(INT64_C( 2800078338557512603), INT64_C(-7382248080413965284)),
      simde_mm_set_epi64x(INT64_C( -645055313537887494), INT64_C( 2018860835012845242)),
      simde_mm_set_epi64x(INT64_C( 3796538949364005726), INT64_C(-1962708987484978088)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_x_mm_mul_epi64(test_vec[i].a, test_vec[i].b);
    simde_assert_m128i_i64(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_x_mm_mod_epi64(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi64x(INT64_C(-8053187774363015445), INT64_C( 9050551738356525681)),
      simde_mm_set_epi64x(INT64_C(-5432362900125533563), INT64_C( 4656333831414330662)),
      simde_mm_set_epi64x(INT64_C(-2620824874237481882), INT64_C( 4394217906942195019)) },
    { simde_mm_set_epi64x(INT64_C( 3643434954039553447), INT64_C(-6234539097175065740)),
      simde_mm_set_epi64x(INT64_C(-1834126128625936904), INT64_C( 5974848154734978575)),
      simde_mm_set_epi64x(INT64_C( 1809308825413616543), INT64_C( -259690942440087165)) },
    { simde_mm_set_epi64x(INT64_C( 9161306297850640165), INT64_C(-8306180370740150176)),
      simde_mm_set_epi64x(INT64_C( 2055562205091916701), INT64_C(-6680168448646461201)),
      simde_mm_set_epi64x(INT64_C(  939057477482973361), INT64_C(-1626011922093688975)) },
    { simde_mm_set_epi64x(INT64_C(-8267679289606370918), INT64_C(-5928191487249150522)),
      simde_mm_set_epi64x(INT64_C( -367540592738432621), INT64_C(-9016984680455221058)),
      simde_mm_set_epi64x(INT64_C( -181786249360853256), INT64_C(-5928191487249150522)) },
    { simde_mm_set_epi64x(INT64_C(-5911217161035399691), INT64_C(-1038656028139092449)),
      simde_mm_set_epi64x(INT64_C(  170272479168034452), INT64_C( 6507756447489319344)),
      simde_mm_set_epi64x(INT64_C( -121952869322228323), INT64_C(-1038656028139092449)) },
    { simde_mm_set_epi64x(INT64_C(-8644627274378588029), INT64_C( 5613017538463476646)),
      simde_mm_set_epi64x(INT64_C(-8247421513208151154), INT64_C(-1150990985458942599)),
      simde_mm_set_epi64x(INT64_C( -397205761170436875), INT64_C( 1009053596627706250)) },
    { simde_mm_set_epi64x(INT64_C( 8688276933216716257), INT64_C( -409477294924409172)),
      simde_mm_set_epi64x(INT64_C( 7651480072460119172), INT64_C( 5980691967331237074)),
      simde_mm_set_epi64x(INT64_C( 1036796860756597085), INT64_C( -409477294924409172)) },
    { simde_mm_set_epi64x(INT64_C(-6308927419868714376), INT64_C( 6327163388033237975)),
      simde_mm_set_epi64x(INT64_C( 4310605020200368092), INT64_C( 1934689183910316990)),
      simde_mm_set_epi64x(INT64_C(-1998322399668346284), INT64_C(  523095836302287005)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_x_mm_mod_epi64(test_vec[i].a, test_vec[i].b);
    simde_assert_m128i_i64(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitTest test_suite_tests[] = {
  SIMDE_TESTS_DEFINE_TEST(mm_set_epi8),
  SIMDE_TESTS_DEFINE_TEST(mm_set_epi16),
  SIMDE_TESTS_DEFINE_TEST(mm_set_epi32),
  SIMDE_TESTS_DEFINE_TEST(mm_set_epi64),
  SIMDE_TESTS_DEFINE_TEST(mm_set_epi64x),
  SIMDE_TESTS_DEFINE_TEST(mm_set_pd),
  SIMDE_TESTS_DEFINE_TEST(mm_set_pd1),
  SIMDE_TESTS_DEFINE_TEST(mm_set_sd),
  SIMDE_TESTS_DEFINE_TEST(mm_set1_epi8),
  SIMDE_TESTS_DEFINE_TEST(mm_set1_epi64),
  SIMDE_TESTS_DEFINE_TEST(mm_set1_epi64x),
  SIMDE_TESTS_DEFINE_TEST(mm_setr_epi8),
  SIMDE_TESTS_DEFINE_TEST(mm_setr_epi16),
  SIMDE_TESTS_DEFINE_TEST(mm_setr_epi32),
  SIMDE_TESTS_DEFINE_TEST(mm_setzero_si128),

  SIMDE_TESTS_DEFINE_TEST(mm_add_epi8),
  SIMDE_TESTS_DEFINE_TEST(mm_add_epi16),
  SIMDE_TESTS_DEFINE_TEST(mm_add_epi32),
  SIMDE_TESTS_DEFINE_TEST(mm_add_epi64),
  SIMDE_TESTS_DEFINE_TEST(mm_add_pd),
  SIMDE_TESTS_DEFINE_TEST(mm_add_sd),
  SIMDE_TESTS_DEFINE_TEST(mm_add_si64),
  SIMDE_TESTS_DEFINE_TEST(mm_adds_epi8),
  SIMDE_TESTS_DEFINE_TEST(mm_adds_epi16),
  SIMDE_TESTS_DEFINE_TEST(mm_adds_epu8),
  SIMDE_TESTS_DEFINE_TEST(mm_adds_epu16),

  SIMDE_TESTS_DEFINE_TEST(mm_and_pd),
  SIMDE_TESTS_DEFINE_TEST(mm_and_si128),
  SIMDE_TESTS_DEFINE_TEST(mm_andnot_pd),
  SIMDE_TESTS_DEFINE_TEST(mm_andnot_si128),

  SIMDE_TESTS_DEFINE_TEST(mm_avg_epu8),
  SIMDE_TESTS_DEFINE_TEST(mm_avg_epu16),

  SIMDE_TESTS_DEFINE_TEST(mm_bslli_si128),
  SIMDE_TESTS_DEFINE_TEST(mm_bsrli_si128),
  SIMDE_TESTS_DEFINE_TEST(mm_slli_epi16),
  SIMDE_TESTS_DEFINE_TEST(mm_slli_epi32),
  SIMDE_TESTS_DEFINE_TEST(mm_slli_epi64),
  SIMDE_TESTS_DEFINE_TEST(mm_srli_epi16),
  SIMDE_TESTS_DEFINE_TEST(mm_srli_epi32),
  SIMDE_TESTS_DEFINE_TEST(mm_srli_epi64),

  SIMDE_TESTS_DEFINE_TEST(mm_sra_epi16),
  SIMDE_TESTS_DEFINE_TEST(mm_sra_epi32),
  SIMDE_TESTS_DEFINE_TEST(mm_srai_epi16),
  SIMDE_TESTS_DEFINE_TEST(mm_srai_epi32),

  SIMDE_TESTS_DEFINE_TEST(mm_store_pd),
  SIMDE_TESTS_DEFINE_TEST(mm_store_pd1),
  SIMDE_TESTS_DEFINE_TEST(mm_store_sd),
  SIMDE_TESTS_DEFINE_TEST(mm_store_si128),
  SIMDE_TESTS_DEFINE_TEST(mm_storeh_pd),
  SIMDE_TESTS_DEFINE_TEST(mm_storel_epi64),
  SIMDE_TESTS_DEFINE_TEST(mm_storel_pd),
  SIMDE_TESTS_DEFINE_TEST(mm_storer_pd),
  SIMDE_TESTS_DEFINE_TEST(mm_storeu_pd),
  SIMDE_TESTS_DEFINE_TEST(mm_storeu_si128),

  SIMDE_TESTS_DEFINE_TEST(mm_stream_pd),
  SIMDE_TESTS_DEFINE_TEST(mm_stream_si128),
  SIMDE_TESTS_DEFINE_TEST(mm_stream_si32),
  SIMDE_TESTS_DEFINE_TEST(mm_stream_si64),

  SIMDE_TESTS_DEFINE_TEST(mm_sub_epi8),
  SIMDE_TESTS_DEFINE_TEST(mm_sub_epi16),
  SIMDE_TESTS_DEFINE_TEST(mm_sub_epi32),
  SIMDE_TESTS_DEFINE_TEST(mm_sub_epi64),
  SIMDE_TESTS_DEFINE_TEST(mm_sub_pd),
  SIMDE_TESTS_DEFINE_TEST(mm_sub_sd),
  SIMDE_TESTS_DEFINE_TEST(mm_sub_si64),
  SIMDE_TESTS_DEFINE_TEST(mm_subs_epi8),
  SIMDE_TESTS_DEFINE_TEST(mm_subs_epi16),
  SIMDE_TESTS_DEFINE_TEST(mm_subs_epu8),
  SIMDE_TESTS_DEFINE_TEST(mm_subs_epu16),

  SIMDE_TESTS_DEFINE_TEST(mm_min_epu8),
  SIMDE_TESTS_DEFINE_TEST(mm_min_epi16),
  SIMDE_TESTS_DEFINE_TEST(mm_min_pd),
  SIMDE_TESTS_DEFINE_TEST(mm_min_sd),
  SIMDE_TESTS_DEFINE_TEST(mm_max_epu8),
  SIMDE_TESTS_DEFINE_TEST(mm_max_epi16),
  SIMDE_TESTS_DEFINE_TEST(mm_max_pd),
  SIMDE_TESTS_DEFINE_TEST(mm_max_sd),

  SIMDE_TESTS_DEFINE_TEST(mm_mul_epu32),
  SIMDE_TESTS_DEFINE_TEST(mm_mul_pd),
  SIMDE_TESTS_DEFINE_TEST(mm_mul_sd),
  SIMDE_TESTS_DEFINE_TEST(mm_mul_su32),
  SIMDE_TESTS_DEFINE_TEST(mm_mulhi_epi16),
  SIMDE_TESTS_DEFINE_TEST(mm_mulhi_epu16),
  SIMDE_TESTS_DEFINE_TEST(mm_mullo_epi16),

  SIMDE_TESTS_DEFINE_TEST(mm_cmpeq_epi8),
  SIMDE_TESTS_DEFINE_TEST(mm_cmpeq_epi16),
  SIMDE_TESTS_DEFINE_TEST(mm_cmpeq_epi32),
  SIMDE_TESTS_DEFINE_TEST(mm_cmpeq_pd),
  SIMDE_TESTS_DEFINE_TEST(mm_cmpeq_sd),
  SIMDE_TESTS_DEFINE_TEST(mm_cmpneq_pd),
  SIMDE_TESTS_DEFINE_TEST(mm_cmpneq_sd),
  SIMDE_TESTS_DEFINE_TEST(mm_cmplt_epi8),
  SIMDE_TESTS_DEFINE_TEST(mm_cmplt_epi16),
  SIMDE_TESTS_DEFINE_TEST(mm_cmplt_epi32),
  SIMDE_TESTS_DEFINE_TEST(mm_cmplt_pd),
  SIMDE_TESTS_DEFINE_TEST(mm_cmplt_sd),
  SIMDE_TESTS_DEFINE_TEST(mm_cmpnlt_pd),
  SIMDE_TESTS_DEFINE_TEST(mm_cmpnlt_sd),
  SIMDE_TESTS_DEFINE_TEST(mm_cmple_pd),
  SIMDE_TESTS_DEFINE_TEST(mm_cmple_sd),
  SIMDE_TESTS_DEFINE_TEST(mm_cmpnle_pd),
  SIMDE_TESTS_DEFINE_TEST(mm_cmpnle_sd),
  SIMDE_TESTS_DEFINE_TEST(mm_cmpgt_epi8),
  SIMDE_TESTS_DEFINE_TEST(mm_cmpgt_epi16),
  SIMDE_TESTS_DEFINE_TEST(mm_cmpgt_epi32),
  SIMDE_TESTS_DEFINE_TEST(mm_cmpgt_pd),
  SIMDE_TESTS_DEFINE_TEST(mm_cmpgt_sd),
  SIMDE_TESTS_DEFINE_TEST(mm_cmpge_pd),
  SIMDE_TESTS_DEFINE_TEST(mm_cmpge_sd),
  SIMDE_TESTS_DEFINE_TEST(mm_cmpnge_pd),
  SIMDE_TESTS_DEFINE_TEST(mm_cmpnge_sd),
  SIMDE_TESTS_DEFINE_TEST(mm_cmpord_pd),
  SIMDE_TESTS_DEFINE_TEST(mm_cmpord_sd),
  SIMDE_TESTS_DEFINE_TEST(mm_cmpunord_pd),
  SIMDE_TESTS_DEFINE_TEST(mm_cmpunord_sd),

  SIMDE_TESTS_DEFINE_TEST(mm_castpd_ps),
  SIMDE_TESTS_DEFINE_TEST(mm_castsi128_pd),
  SIMDE_TESTS_DEFINE_TEST(mm_castsi128_ps),

  SIMDE_TESTS_DEFINE_TEST(mm_comieq_sd),
  SIMDE_TESTS_DEFINE_TEST(mm_comige_sd),
  SIMDE_TESTS_DEFINE_TEST(mm_comigt_sd),
  SIMDE_TESTS_DEFINE_TEST(mm_comile_sd),
  SIMDE_TESTS_DEFINE_TEST(mm_comilt_sd),
  SIMDE_TESTS_DEFINE_TEST(mm_comineq_sd),
  SIMDE_TESTS_DEFINE_TEST(mm_ucomieq_sd),
  SIMDE_TESTS_DEFINE_TEST(mm_ucomige_sd),
  SIMDE_TESTS_DEFINE_TEST(mm_ucomigt_sd),
  SIMDE_TESTS_DEFINE_TEST(mm_ucomile_sd),
  SIMDE_TESTS_DEFINE_TEST(mm_ucomilt_sd),
  SIMDE_TESTS_DEFINE_TEST(mm_ucomineq_sd),

  SIMDE_TESTS_DEFINE_TEST(mm_cvtepi32_pd),
  SIMDE_TESTS_DEFINE_TEST(mm_cvtepi32_ps),
  SIMDE_TESTS_DEFINE_TEST(mm_cvtpd_epi32),
  SIMDE_TESTS_DEFINE_TEST(mm_cvtpd_pi32),
  SIMDE_TESTS_DEFINE_TEST(mm_cvtpd_ps),
  SIMDE_TESTS_DEFINE_TEST(mm_cvtpi32_pd),
  SIMDE_TESTS_DEFINE_TEST(mm_cvtps_epi32),
  SIMDE_TESTS_DEFINE_TEST(mm_cvtps_pd),
  SIMDE_TESTS_DEFINE_TEST(mm_cvtsd_f64),
  SIMDE_TESTS_DEFINE_TEST(mm_cvtsd_si32),
  SIMDE_TESTS_DEFINE_TEST(mm_cvtsd_si64),
  SIMDE_TESTS_DEFINE_TEST(mm_cvtsd_ss),
  SIMDE_TESTS_DEFINE_TEST(mm_cvtsi128_si32),
  SIMDE_TESTS_DEFINE_TEST(mm_cvtsi128_si64),
  SIMDE_TESTS_DEFINE_TEST(mm_cvtsi32_sd),
  SIMDE_TESTS_DEFINE_TEST(mm_cvtsi32_si128),
  SIMDE_TESTS_DEFINE_TEST(mm_cvtsi64_sd),
  SIMDE_TESTS_DEFINE_TEST(mm_cvtsi64_si128),
  SIMDE_TESTS_DEFINE_TEST(mm_cvtss_sd),
  SIMDE_TESTS_DEFINE_TEST(mm_cvttpd_epi32),
  SIMDE_TESTS_DEFINE_TEST(mm_cvttpd_pi32),
  SIMDE_TESTS_DEFINE_TEST(mm_cvttps_epi32),
  SIMDE_TESTS_DEFINE_TEST(mm_cvttsd_si32),
  SIMDE_TESTS_DEFINE_TEST(mm_cvttsd_si64),

  SIMDE_TESTS_DEFINE_TEST(mm_div_pd),
  SIMDE_TESTS_DEFINE_TEST(mm_div_sd),

  SIMDE_TESTS_DEFINE_TEST(mm_extract_epi16),
  SIMDE_TESTS_DEFINE_TEST(mm_insert_epi16),

  SIMDE_TESTS_DEFINE_TEST(mm_load_pd),
  SIMDE_TESTS_DEFINE_TEST(mm_load_pd1),
  SIMDE_TESTS_DEFINE_TEST(mm_load_sd),
  SIMDE_TESTS_DEFINE_TEST(mm_load_si128),
  SIMDE_TESTS_DEFINE_TEST(mm_loadh_pd),
  SIMDE_TESTS_DEFINE_TEST(mm_loadl_epi64),
  SIMDE_TESTS_DEFINE_TEST(mm_loadl_pd),
  SIMDE_TESTS_DEFINE_TEST(mm_loadr_pd),
  SIMDE_TESTS_DEFINE_TEST(mm_loadu_pd),
  SIMDE_TESTS_DEFINE_TEST(mm_loadu_si128),

  SIMDE_TESTS_DEFINE_TEST(mm_movemask_epi8),
  SIMDE_TESTS_DEFINE_TEST(mm_movemask_pd),
  SIMDE_TESTS_DEFINE_TEST(mm_maskmoveu_si128),

  SIMDE_TESTS_DEFINE_TEST(mm_move_epi64),
  SIMDE_TESTS_DEFINE_TEST(mm_move_sd),
  SIMDE_TESTS_DEFINE_TEST(mm_movepi64_pi64),
  SIMDE_TESTS_DEFINE_TEST(mm_movpi64_epi64),

  SIMDE_TESTS_DEFINE_TEST(mm_or_pd),
  SIMDE_TESTS_DEFINE_TEST(mm_or_si128),

  SIMDE_TESTS_DEFINE_TEST(mm_packs_epi16),
  SIMDE_TESTS_DEFINE_TEST(mm_packs_epi32),
  SIMDE_TESTS_DEFINE_TEST(mm_packus_epi16),

  SIMDE_TESTS_DEFINE_TEST(mm_unpackhi_epi8),
  SIMDE_TESTS_DEFINE_TEST(mm_unpackhi_epi16),
  SIMDE_TESTS_DEFINE_TEST(mm_unpackhi_epi32),
  SIMDE_TESTS_DEFINE_TEST(mm_unpackhi_epi64),
  SIMDE_TESTS_DEFINE_TEST(mm_unpackhi_pd),
  SIMDE_TESTS_DEFINE_TEST(mm_unpacklo_epi8),
  SIMDE_TESTS_DEFINE_TEST(mm_unpacklo_epi16),
  SIMDE_TESTS_DEFINE_TEST(mm_unpacklo_epi32),
  SIMDE_TESTS_DEFINE_TEST(mm_unpacklo_epi64),
  SIMDE_TESTS_DEFINE_TEST(mm_unpacklo_pd),

  SIMDE_TESTS_DEFINE_TEST(mm_shuffle_epi32),
  SIMDE_TESTS_DEFINE_TEST(mm_shuffle_pd),
  SIMDE_TESTS_DEFINE_TEST(mm_shufflehi_epi16),
  SIMDE_TESTS_DEFINE_TEST(mm_shufflelo_epi16),

  SIMDE_TESTS_DEFINE_TEST(mm_sll_epi16),
  SIMDE_TESTS_DEFINE_TEST(mm_sll_epi32),
  SIMDE_TESTS_DEFINE_TEST(mm_sll_epi64),
  SIMDE_TESTS_DEFINE_TEST(mm_srl_epi16),
  SIMDE_TESTS_DEFINE_TEST(mm_srl_epi32),
  SIMDE_TESTS_DEFINE_TEST(mm_srl_epi64),

  SIMDE_TESTS_DEFINE_TEST(mm_sqrt_pd),
  SIMDE_TESTS_DEFINE_TEST(mm_sqrt_sd),

  SIMDE_TESTS_DEFINE_TEST(mm_madd_epi16),
  SIMDE_TESTS_DEFINE_TEST(mm_sad_epu8),

  SIMDE_TESTS_DEFINE_TEST(mm_xor_pd),
  SIMDE_TESTS_DEFINE_TEST(mm_xor_si128),

  SIMDE_TESTS_DEFINE_TEST(x_mm_not_si128),
  SIMDE_TESTS_DEFINE_TEST(x_mm_mul_epi64),
  SIMDE_TESTS_DEFINE_TEST(x_mm_mod_epi64),

  { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};

HEDLEY_C_DECL MunitSuite* SIMDE_TESTS_GENERATE_SYMBOL(suite)(void) {
  static MunitSuite suite = { (char*) "/" HEDLEY_STRINGIFY(SIMDE_TESTS_CURRENT_ISAX), test_suite_tests, NULL, 1, MUNIT_SUITE_OPTION_NONE };

  return &suite;
}
