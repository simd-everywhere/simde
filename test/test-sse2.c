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

#include "test.h"
#include "../sse2.h"

#include <stdio.h>

static MunitResult
test_simde_mm_add_epi8(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi8(0x38, 0x70, 0xd8, 0x83, 0x2b, 0x0d, 0xc8, 0x0e,
			0x59, 0xc5, 0x29, 0x93, 0xf8, 0x91, 0x24, 0x5c),
      simde_mm_set_epi8(0xf7, 0xae, 0xd8, 0x72, 0x43, 0xc2, 0xa3, 0xad,
			0xaf, 0x39, 0xbf, 0x20, 0x01, 0x44, 0x1d, 0x37),
      simde_mm_set_epi8(0x2f, 0x1e, 0xb0, 0xf5, 0x6e, 0xcf, 0x6b, 0xbb,
			0x08, 0xfe, 0xe8, 0xb3, 0xf9, 0xd5, 0x41, 0x93) },
    { simde_mm_set_epi8(0x94, 0x89, 0xfb, 0x0a, 0x1a, 0xb2, 0xe5, 0x8f,
			0xfe, 0xc5, 0x90, 0x45, 0x74, 0xf5, 0x58, 0x6b),
      simde_mm_set_epi8(0xaf, 0xa6, 0x18, 0xae, 0x73, 0x15, 0x76, 0xfd,
			0x75, 0x66, 0xb8, 0x3c, 0x83, 0x9f, 0x0b, 0xe7),
      simde_mm_set_epi8(0x43, 0x2f, 0x13, 0xb8, 0x8d, 0xc7, 0x5b, 0x8c,
			0x73, 0x2b, 0x48, 0x81, 0xf7, 0x94, 0x63, 0x52) },
    { simde_mm_set_epi8(0xb6, 0x3a, 0x7d, 0x4e, 0xc0, 0xb0, 0x5b, 0x39,
			0xa4, 0x2b, 0xac, 0x0e, 0x77, 0xa3, 0xca, 0x3e),
      simde_mm_set_epi8(0x7f, 0x82, 0x01, 0x7d, 0xde, 0xa2, 0x79, 0x1c,
			0x35, 0x55, 0x53, 0x79, 0xf4, 0x8f, 0x7f, 0x51),
      simde_mm_set_epi8(0x35, 0xbc, 0x7e, 0xcb, 0x9e, 0x52, 0xd4, 0x55,
			0xd9, 0x80, 0xff, 0x87, 0x6b, 0x32, 0x49, 0x8f) },
    { simde_mm_set_epi8(0x1f, 0xe1, 0x17, 0x2f, 0x13, 0x9f, 0xb0, 0x85,
			0xf7, 0xca, 0x31, 0xaa, 0xf3, 0x99, 0xa8, 0x60),
      simde_mm_set_epi8(0x73, 0x1e, 0x9a, 0xdf, 0xc0, 0x9d, 0x2d, 0x8d,
			0x56, 0xa7, 0xca, 0xa1, 0x80, 0x0e, 0x8f, 0x3b),
      simde_mm_set_epi8(0x92, 0xff, 0xb1, 0x0e, 0xd3, 0x3c, 0xdd, 0x12,
			0x4d, 0x71, 0xfb, 0x4b, 0x73, 0xa7, 0x37, 0x9b) },
    { simde_mm_set_epi8(0x85, 0x9c, 0xe7, 0x43, 0x6f, 0x7f, 0x1a, 0x80,
			0xce, 0x88, 0x1d, 0x46, 0x44, 0x73, 0xe1, 0xd7),
      simde_mm_set_epi8(0x6a, 0x5e, 0x79, 0xca, 0x60, 0xd5, 0xd0, 0xcd,
			0x9f, 0x0f, 0xc2, 0xcc, 0xcd, 0x00, 0x97, 0x37),
      simde_mm_set_epi8(0xef, 0xfa, 0x60, 0x0d, 0xcf, 0x54, 0xea, 0x4d,
			0x6d, 0x97, 0xdf, 0x12, 0x11, 0x73, 0x78, 0x0e) },
    { simde_mm_set_epi8(0x9d, 0xec, 0x07, 0x00, 0x3a, 0xdc, 0xfb, 0xcc,
			0xf3, 0x36, 0xe5, 0x07, 0xc3, 0xe6, 0xa1, 0x17),
      simde_mm_set_epi8(0x2d, 0xbe, 0x44, 0x1c, 0xec, 0xfd, 0x3d, 0x97,
			0x5d, 0x5b, 0x85, 0xbe, 0x27, 0x35, 0x8d, 0x1f),
      simde_mm_set_epi8(0xca, 0xaa, 0x4b, 0x1c, 0x26, 0xd9, 0x38, 0x63,
			0x50, 0x91, 0x6a, 0xc5, 0xea, 0x1b, 0x2e, 0x36) },
    { simde_mm_set_epi8(0x31, 0x8b, 0xcc, 0x7e, 0x91, 0x8a, 0x17, 0xab,
			0xd8, 0xa1, 0xe6, 0xa9, 0x39, 0x8b, 0x4d, 0x20),
      simde_mm_set_epi8(0xf8, 0x50, 0x4f, 0xcf, 0x7c, 0x59, 0x25, 0x48,
			0x04, 0x09, 0x37, 0xe4, 0x91, 0x2f, 0x4d, 0x72),
      simde_mm_set_epi8(0x29, 0xdb, 0x1b, 0x4d, 0x0d, 0xe3, 0x3c, 0xf3,
			0xdc, 0xaa, 0x1d, 0x8d, 0xca, 0xba, 0x9a, 0x92) },
    { simde_mm_set_epi8(0xff, 0xfb, 0xc0, 0xae, 0xb9, 0x1e, 0x09, 0xe6,
			0xa1, 0x01, 0xf4, 0xe4, 0x07, 0xed, 0x37, 0x76),
      simde_mm_set_epi8(0x17, 0x64, 0x65, 0xca, 0xb9, 0xaf, 0xdd, 0xf8,
			0xc9, 0x16, 0x4a, 0x1c, 0x09, 0x20, 0x3d, 0x38),
      simde_mm_set_epi8(0x16, 0x5f, 0x25, 0x78, 0x72, 0xcd, 0xe6, 0xde,
			0x6a, 0x17, 0x3e, 0x00, 0x10, 0x0d, 0x74, 0xae) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_add_epi8(test_vec[i].a, test_vec[i].b);
    simde_assert_m128_i8(r, ==, test_vec[i].r);
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
    simde_assert_m128_i16(r, ==, test_vec[i].r);
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
    simde_assert_m128_i32(r, ==, test_vec[i].r);
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
    { simde_mm_set_pd(  692.94,   -54.00),
      simde_mm_set_pd(  808.70,  -119.61),
      simde_mm_set_pd( 1501.64,  -173.61) },
    { simde_mm_set_pd(  522.72,  -185.63),
      simde_mm_set_pd(  421.40,  -110.04),
      simde_mm_set_pd(  944.11,  -295.67) },
    { simde_mm_set_pd(  882.82,  -926.59),
      simde_mm_set_pd(   18.43,   439.06),
      simde_mm_set_pd(  901.25,  -487.53) },
    { simde_mm_set_pd( -812.39,  -968.80),
      simde_mm_set_pd( -611.22,  -994.53),
      simde_mm_set_pd(-1423.61, -1963.33) },
    { simde_mm_set_pd(  799.36,   503.15),
      simde_mm_set_pd( -287.21,  -449.06),
      simde_mm_set_pd(  512.15,    54.08) },
    { simde_mm_set_pd( -439.71,  -625.83),
      simde_mm_set_pd( -779.95,    52.26),
      simde_mm_set_pd(-1219.66,  -573.57) },
    { simde_mm_set_pd(  -20.82,  -138.96),
      simde_mm_set_pd( -136.01,  -829.13),
      simde_mm_set_pd( -156.83,  -968.09) },
    { simde_mm_set_pd( -846.81,   763.26),
      simde_mm_set_pd(  303.68,   274.55),
      simde_mm_set_pd( -543.14,  1037.81) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_add_pd(test_vec[i].a, test_vec[i].b);
    simde_assert_m128_f64_equal(r, test_vec[i].r, 1);
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
    { simde_mm_set_pd( -348.09,  -603.87),
      simde_mm_set_pd(   42.81,  -955.64),
      simde_mm_set_pd( -348.09, -1559.51) },
    { simde_mm_set_pd(  600.30,   362.82),
      simde_mm_set_pd( -245.13,  -144.52),
      simde_mm_set_pd(  600.30,   218.30) },
    { simde_mm_set_pd( -909.82,   -28.51),
      simde_mm_set_pd( -141.49,   174.41),
      simde_mm_set_pd( -909.82,   145.90) },
    { simde_mm_set_pd( -402.79,  -225.69),
      simde_mm_set_pd( -114.28,   118.74),
      simde_mm_set_pd( -402.79,  -106.95) },
    { simde_mm_set_pd(  476.58,   189.13),
      simde_mm_set_pd(  158.24,   133.22),
      simde_mm_set_pd(  476.58,   322.35) },
    { simde_mm_set_pd( -902.16,  -720.35),
      simde_mm_set_pd( -496.01,   563.52),
      simde_mm_set_pd( -902.16,  -156.83) },
    { simde_mm_set_pd(   32.48,  -172.74),
      simde_mm_set_pd(  435.61,   209.72),
      simde_mm_set_pd(   32.48,    36.98) },
    { simde_mm_set_pd(  322.78,  -415.13),
      simde_mm_set_pd(  -49.82,  -195.58),
      simde_mm_set_pd(  322.78,  -610.71) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_add_sd(test_vec[i].a, test_vec[i].b);
    simde_assert_m128_f64_equal(r, test_vec[i].r, 1);
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
    { simde_mm_set_epi64x(UINT64_C( 5302906957046332539), UINT64_C( 6896761003579441006)),
      simde_mm_set_epi64x(UINT64_C( 8080483180981769846), UINT64_C( -532551505374559044)),
      simde_mm_set_epi64x(UINT64_C(-5063353935681449231), UINT64_C( 6364209498204881962)) },
    { simde_mm_set_epi64x(UINT64_C(  244760848479017871), UINT64_C(-8308084306078226664)),
      simde_mm_set_epi64x(UINT64_C(-3779773313499286364), UINT64_C( 6113767891784897906)),
      simde_mm_set_epi64x(UINT64_C(-3535012465020268493), UINT64_C(-2194316414293328758)) },
    { simde_mm_set_epi64x(UINT64_C(-6850824349794960557), UINT64_C(-5605962976784798391)),
      simde_mm_set_epi64x(UINT64_C(-2244363788590884551), UINT64_C(-6273588010625182382)),
      simde_mm_set_epi64x(UINT64_C(-9095188138385845108), UINT64_C( 6567193086299570843)) },
    { simde_mm_set_epi64x(UINT64_C( 6565436457151053906), UINT64_C( 5511764898961433032)),
      simde_mm_set_epi64x(UINT64_C( 1077726064250254320), UINT64_C( -263844214123199019)),
      simde_mm_set_epi64x(UINT64_C( 7643162521401308226), UINT64_C( 5247920684838234013)) },
    { simde_mm_set_epi64x(UINT64_C(-5813163364316205654), UINT64_C( 4814776107221586548)),
      simde_mm_set_epi64x(UINT64_C(-2933269790578797014), UINT64_C(   74425625609844147)),
      simde_mm_set_epi64x(UINT64_C(-8746433154895002668), UINT64_C( 4889201732831430695)) },
    { simde_mm_set_epi64x(UINT64_C(-2444264382048445434), UINT64_C( 3369516233586132041)),
      simde_mm_set_epi64x(UINT64_C(-4296115714310543830), UINT64_C( 3847771998301827374)),
      simde_mm_set_epi64x(UINT64_C(-6740380096358989264), UINT64_C( 7217288231887959415)) },
    { simde_mm_set_epi64x(UINT64_C(-6266932275253634982), UINT64_C( 6725635524324655769)),
      simde_mm_set_epi64x(UINT64_C( 4821822804079289890), UINT64_C(-7857845909588692827)),
      simde_mm_set_epi64x(UINT64_C(-1445109471174345092), UINT64_C(-1132210385264037058)) },
    { simde_mm_set_epi64x(UINT64_C( 4307059302838028733), UINT64_C(-5215917355058769847)),
      simde_mm_set_epi64x(UINT64_C( 4398479129145449653), UINT64_C( 2472056074162910166)),
      simde_mm_set_epi64x(UINT64_C( 8705538431983478386), UINT64_C(-2743861280895859681)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_add_epi64(test_vec[i].a, test_vec[i].b);
    simde_assert_m128_i64(r, ==, test_vec[i].r);
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
    { simde_mm_set_epi8( 100,   33,   67,   67,  104, -123,  -86,   74,
                         -93,   -4,  -12,   28,    9,   39,   83,  -52),
      simde_mm_set_epi8(  40,  -64,  -19,  -17,   67,  -93,  -22,   98,
                         -73,  -83,  107,   95,   59,   84,  -72, -115),
      simde_mm_set_epi8( 127,  -31,   48,   50,  127, -128, -108,  127,
                        -128,  -87,   95,  123,   68,  123,   11, -128) },
    { simde_mm_set_epi8(  76,  121,   98,   52,   50,  -16,   53,    3,
                         -57,  -76,  -42,   70, -122,   71,  -56,  -15),
      simde_mm_set_epi8( 100,  124,   99,   11,   -8,    5,    6,  -54,
                          42,  -99,   23, -128,   77,   14,   94,   53),
      simde_mm_set_epi8( 127,  127,  127,   63,   42,  -11,   59,  -51,
                         -15, -128,  -19,  -58,  -45,   85,   38,   38) },
    { simde_mm_set_epi8( -13,   29,   30,   13,   51,   11,  -27,  -12,
                          97,   87,   67,   70,    2,  -40,   49,  116),
      simde_mm_set_epi8(  42,  -17,  -77,  126, -125,  -42,   45,  -79,
                         -23,  110,  117,  -44,  -92,  -20, -121,  102),
      simde_mm_set_epi8(  29,   12,  -47,  127,  -74,  -31,   18,  -91,
                          74,  127,  127,   26,  -90,  -60,  -72,  127) },
    { simde_mm_set_epi8(  55, -106,  -49,  -49,  -85,  -58,  -56,  -25,
                          78,   18,   71,  -12,   86,  -84,  -77, -116),
      simde_mm_set_epi8(-103,  107,   33,  -17,  106,    4,  -98, -128,
                          53,    4,  120,  -44,  -99,  120,  -27,   45),
      simde_mm_set_epi8( -48,    1,  -16,  -66,   21,  -54, -128, -128,
                         127,   22,  127,  -56,  -13,   36, -104,  -71) },
    { simde_mm_set_epi8(  47,   15,  126, -115,  -77,  -27,  -38,   32,
                         -21,  -80,  112,   75,  -15,  -92,   43,  -22),
      simde_mm_set_epi8( -33,  127,  123,   65,   63,   85,   75,   99,
                          -2,   13,  -46,   -8,  127, -115, -109,   14),
      simde_mm_set_epi8(  14,  127,  127,  -50,  -14,   58,   37,  127,
                         -23,  -67,   66,   67,  112, -128,  -66,   -8) },
    { simde_mm_set_epi8(  18,   75,   10,   29,   27,  101,   -1,   78,
                         -78,  110,   18,   82,  -41,   85, -113,  126),
      simde_mm_set_epi8( -90,   80, -103, -111,   86,   65,   89,   88,
                         -83, -121,   -2,   40,  -96,  -36,   64,  -15),
      simde_mm_set_epi8( -72,  127,  -93,  -82,  113,  127,   88,  127,
                        -128,  -11,   16,  122, -128,   49,  -49,  111) },
    { simde_mm_set_epi8( -90,   48,  -43,   22,   78,  -17,  -78,  -64,
                         -97,  -80,  -51,   72,  114,  -11,  -89,  -93),
      simde_mm_set_epi8(   8,   57,   66, -119,   79,  -29,  -49,   26,
                         -12,  -99, -101,  121, -112,   -5,  -19,  -27),
      simde_mm_set_epi8( -82,  105,   23,  -97,  127,  -46, -127,  -38,
                        -109, -128, -128,  127,    2,  -16, -108, -120) },
    { simde_mm_set_epi8(  26,  -15,   12,  -66,   -7, -115,  -21,   27,
                         111, -126,  -43,  -94,  -97,  -34,  -47,  -79),
      simde_mm_set_epi8(-124,  -47, -123, -115,  -15,  -87, -121,  -50,
                         103,   85,   34,  -85, -124,   70,   14,  -44),
      simde_mm_set_epi8( -98,  -62, -111, -128,  -22, -128, -128,  -23,
                         127,  -41,   -9, -128, -128,   36,  -33, -123) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_adds_epi8(test_vec[i].a, test_vec[i].b);
    simde_assert_m128_i8(r, ==, test_vec[i].r);
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
    simde_assert_m128_i16(r, ==, test_vec[i].r);
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
    debug_array_u8("\na", 16, (uint8_t*) &(test_vec[i].a));
    debug_array_u8("b", 16, (uint8_t*) &(test_vec[i].b));
    debug_array_u8("r", 16, (uint8_t*) &r);
    debug_array_u8("x", 16, (uint8_t*) &(test_vec[i].r));
    simde_assert_m128_u8(r, ==, test_vec[i].r);
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
    simde_assert_m128_u16(r, ==, test_vec[i].r);
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
    { simde_mm_set_pd( -606.22,   874.08),
      simde_mm_set_pd(  807.60,   -11.56),
      simde_mm_set_pd(  518.10,     2.38) },
    { simde_mm_set_pd(  352.03,   588.38),
      simde_mm_set_pd(  590.34,  -688.03),
      simde_mm_set_pd(    2.25,   512.01) },
    { simde_mm_set_pd(  365.91,  -165.12),
      simde_mm_set_pd( -877.33,   611.63),
      simde_mm_set_pd(    2.29,     2.00) },
    { simde_mm_set_pd( -616.20,   109.60),
      simde_mm_set_pd( -193.05,   975.05),
      simde_mm_set_pd(   -2.00,     3.30) },
    { simde_mm_set_pd( -450.67,  -722.66),
      simde_mm_set_pd( -984.89,   333.54),
      simde_mm_set_pd(   -3.50,     2.57) },
    { simde_mm_set_pd(  420.85,  -200.82),
      simde_mm_set_pd(    0.89,  -772.92),
      simde_mm_set_pd(    0.00,    -3.00) },
    { simde_mm_set_pd( -866.17,   206.85),
      simde_mm_set_pd( -904.55,   635.86),
      simde_mm_set_pd( -768.03,     2.23) },
    { simde_mm_set_pd(  108.59,  -506.28),
      simde_mm_set_pd( -260.87,   698.96),
      simde_mm_set_pd(   64.09,     2.69) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_and_pd(test_vec[i].a, test_vec[i].b);
    simde_assert_m128_f64_equal(r, test_vec[i].r, 1);
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
    { simde_mm_set_epi32(0x806d6228, 0x4f0c2b4a, 0xce78b680, 0xbe56c489),
      simde_mm_set_epi32(0xdffefdd4, 0x362b5d11, 0xd3d69135, 0xe2cb51b3),
      simde_mm_set_epi32(0x806c6000, 0x06080900, 0xc2509000, 0xa2424081) },
    { simde_mm_set_epi32(0xcfb94de7, 0xfb1d0563, 0x15f6cc30, 0xad7d75cb),
      simde_mm_set_epi32(0x6942d07d, 0x4c8c90d4, 0xcc33c55a, 0x15109aaf),
      simde_mm_set_epi32(0x49004065, 0x480c0040, 0x0432c410, 0x0510108b) },
    { simde_mm_set_epi32(0x225ca265, 0x1375c38d, 0xdadc13f8, 0x5067f651),
      simde_mm_set_epi32(0x3e33b0cd, 0x04960cbc, 0x7d30119b, 0x884ff3f4),
      simde_mm_set_epi32(0x2210a045, 0x0014008c, 0x58101198, 0x0047f250) },
    { simde_mm_set_epi32(0x6c9f716e, 0x439cfb74, 0xbfb2e707, 0xa6e5ceff),
      simde_mm_set_epi32(0x51f2abfd, 0x26120c82, 0x4e2d80b4, 0xd1df3f4b),
      simde_mm_set_epi32(0x4092216c, 0x02100800, 0x0e208004, 0x80c50e4b) },
    { simde_mm_set_epi32(0x09a33fb5, 0xb2f36786, 0xc029a302, 0xef34775f),
      simde_mm_set_epi32(0x9b015142, 0x16a7f8c6, 0x6b267a51, 0x7aae4105),
      simde_mm_set_epi32(0x09011100, 0x12a36086, 0x40202200, 0x6a244105) },
    { simde_mm_set_epi32(0x6952dee1, 0xf1c9b220, 0xb616c840, 0x3208929b),
      simde_mm_set_epi32(0x4337cf7b, 0x61568ddb, 0xf76adc34, 0x97c517e9),
      simde_mm_set_epi32(0x4112ce61, 0x61408000, 0xb602c800, 0x12001289) },
    { simde_mm_set_epi32(0x334b72e2, 0x1ebc9b65, 0xa3d33f43, 0x77f48a17),
      simde_mm_set_epi32(0x726b7e13, 0xd0540ef5, 0x92aa5c8f, 0x03bd6b12),
      simde_mm_set_epi32(0x324b7202, 0x10140a65, 0x82821c03, 0x03b40a12) },
    { simde_mm_set_epi32(0xb309ee5a, 0x8739416e, 0xc1383866, 0x286d5feb),
      simde_mm_set_epi32(0x0645696c, 0x904130fe, 0xb7163f17, 0x7cc19668),
      simde_mm_set_epi32(0x02016848, 0x8001006e, 0x81103806, 0x28411668) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_and_si128(test_vec[i].a, test_vec[i].b);
    simde_assert_m128_i8(r, ==, test_vec[i].r);
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
    { simde_mm_set_pd( -174.15,  -191.62),
      simde_mm_set_pd( -621.38,   807.23),
      simde_mm_set_pd(    0.00,     0.00) },
    { simde_mm_set_pd( -514.25,   644.41),
      simde_mm_set_pd(  127.18,   977.52),
      simde_mm_set_pd(    0.00,     0.00) },
    { simde_mm_set_pd( -636.38,   670.84),
      simde_mm_set_pd(  954.09,   244.99),
      simde_mm_set_pd(    0.00,     0.00) },
    { simde_mm_set_pd(  314.94,  -888.21),
      simde_mm_set_pd( -355.85,   580.14),
      simde_mm_set_pd(   -0.00,     0.00) },
    { simde_mm_set_pd(  658.98,    47.30),
      simde_mm_set_pd(  -65.64,   790.40),
      simde_mm_set_pd(   -0.00,     0.00) },
    { simde_mm_set_pd(  963.63,  -102.98),
      simde_mm_set_pd(  833.56,   345.51),
      simde_mm_set_pd(    0.00,     0.00) },
    { simde_mm_set_pd(  590.50,   508.59),
      simde_mm_set_pd(  551.21,  -654.02),
      simde_mm_set_pd(    0.00,    -0.00) },
    { simde_mm_set_pd(  172.90,  -248.58),
      simde_mm_set_pd(  199.86,  -719.44),
      simde_mm_set_pd(    0.00,     0.00) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_andnot_pd(test_vec[i].a, test_vec[i].b);
    simde_assert_m128_f64_equal(r, test_vec[i].r, 1);
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
    { simde_mm_set_epi32(0x0ff7cfc1, 0x49533388, 0x20f1da12, 0x5951e62e),
      simde_mm_set_epi32(0x33a2c0c1, 0x2c731b44, 0xc9be46d1, 0x741e7b72),
      simde_mm_set_epi32(0x30000000, 0x24200844, 0xc90e04c1, 0x240e1950) },
    { simde_mm_set_epi32(0x38aad5f2, 0x01b45929, 0xde8b062a, 0xabf67d1a),
      simde_mm_set_epi32(0x94987e79, 0xec4e0dca, 0x5505452c, 0x2da5e01b),
      simde_mm_set_epi32(0x84102a09, 0xec4a04c2, 0x01044104, 0x04018001) },
    { simde_mm_set_epi32(0x349c5719, 0xfbc7f8d5, 0xeb326b0b, 0x9bb2271e),
      simde_mm_set_epi32(0xb56f5a46, 0xf6a932e0, 0xe8a5c9fb, 0xbb6a0030),
      simde_mm_set_epi32(0x81630846, 0x04280220, 0x008580f0, 0x20480020) },
    { simde_mm_set_epi32(0x3d364b58, 0xe2f58c4a, 0xbcc2193e, 0x22842b42),
      simde_mm_set_epi32(0x42f00389, 0x16c809fa, 0xa1254421, 0x469066ad),
      simde_mm_set_epi32(0x42c00081, 0x140801b0, 0x01254401, 0x441044ad) },
    { simde_mm_set_epi32(0xc573f1ef, 0xe1ffb750, 0x8726f62b, 0xadd80564),
      simde_mm_set_epi32(0x616c95ed, 0xdb8e7a3c, 0xa705cbb7, 0xc63bf56f),
      simde_mm_set_epi32(0x200c0400, 0x1a00482c, 0x20010994, 0x4223f00b) },
    { simde_mm_set_epi32(0x6a91dc82, 0xf4a476ba, 0xed43d775, 0xed2d9692),
      simde_mm_set_epi32(0x39812ba7, 0xd583116e, 0xb0bc9ff9, 0x86e0518f),
      simde_mm_set_epi32(0x11002325, 0x01030144, 0x10bc0888, 0x02c0410d) },
    { simde_mm_set_epi32(0xf4d61368, 0xd2e0f4c3, 0x4853f6ab, 0x303bf4f9),
      simde_mm_set_epi32(0x626c931d, 0x28b09983, 0xc8d693f4, 0xde48d6e3),
      simde_mm_set_epi32(0x02288015, 0x28100900, 0x80840154, 0xce400202) },
    { simde_mm_set_epi32(0xd1d180b3, 0x203d4623, 0xdc173db9, 0x018fa3cb),
      simde_mm_set_epi32(0x7228b139, 0x40a2a528, 0xd4e5330d, 0x067b1c00),
      simde_mm_set_epi32(0x22283108, 0x4082a108, 0x00e00204, 0x06701c00) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_andnot_si128(test_vec[i].a, test_vec[i].b);
    simde_assert_m128_i8(r, ==, test_vec[i].r);
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
    simde_assert_m128_u8(r, ==, test_vec[i].r);
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
    simde_assert_m128_u16(r, ==, test_vec[i].r);
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
    { simde_mm_set_epi64x(UINT64_C(0x5a28bd9d89a4536f), UINT64_C(0xfa801ab52af8a0bb)),
      simde_mm_set_epi64x(UINT64_C(0xa4536ffa801ab52a), UINT64_C(0xf8a0bb0000000000)) },
    { simde_mm_set_epi64x(UINT64_C(0x62a4a58f46e1fdac), UINT64_C(0x27ceff2a94d4864e)),
      simde_mm_set_epi64x(UINT64_C(0x2a94d4864e000000), UINT64_C(0x0000000000000000)) },
    { simde_mm_set_epi64x(UINT64_C(0xce7e92d6fed2f41c), UINT64_C(0x5642d045ccd076aa)),
      simde_mm_set_epi64x(UINT64_C(0xd2f41c5642d045cc), UINT64_C(0xd076aa0000000000)) },
    { simde_mm_set_epi64x(UINT64_C(0x8112b33129fae185), UINT64_C(0xb784cc1a835ef987)),
      simde_mm_set_epi64x(UINT64_C(0x1a835ef987000000), UINT64_C(0x0000000000000000)) },
    { simde_mm_set_epi64x(UINT64_C(0x2d5273611fc8f28f), UINT64_C(0x8d3fd42bb4e4400c)),
      simde_mm_set_epi64x(UINT64_C(0xc8f28f8d3fd42bb4), UINT64_C(0xe4400c0000000000)) },
    { simde_mm_set_epi64x(UINT64_C(0x7d70b414ab6171b3), UINT64_C(0x49bc6df939c254c5)),
      simde_mm_set_epi64x(UINT64_C(0xf939c254c5000000), UINT64_C(0x0000000000000000)) },
    { simde_mm_set_epi64x(UINT64_C(0x862bca5cde3a4e8a), UINT64_C(0xedfb6b1198fdef83)),
      simde_mm_set_epi64x(UINT64_C(0x3a4e8aedfb6b1198), UINT64_C(0xfdef830000000000)) },
    { simde_mm_set_epi64x(UINT64_C(0x3356f11da6d1a8ea), UINT64_C(0xc7d2edf087fb72d4)),
      simde_mm_set_epi64x(UINT64_C(0xf087fb72d4000000), UINT64_C(0x0000000000000000)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r;
    if (i % 2) {
      r = simde_mm_bslli_si128(test_vec[i].a, 11);
    } else {
      r = simde_mm_bslli_si128(test_vec[i].a, 5);
    }
    simde_assert_m128_u64(r, ==, test_vec[i].r);
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
  } test_vec[8] = {
    { simde_mm_set_epi64x(UINT64_C(0xf756056220c4cc15), UINT64_C(0xc682702e7ceff764)),
      simde_mm_set_epi64x(UINT64_C(0x0000000000f75605), UINT64_C(0x6220c4cc15c68270)) },
    { simde_mm_set_epi64x(UINT64_C(0x10c69dbcb51bdb1f), UINT64_C(0x7814b4a2c58f6c58)),
      simde_mm_set_epi64x(UINT64_C(0x0000000000000000), UINT64_C(0x00000010c69dbcb5)) },
    { simde_mm_set_epi64x(UINT64_C(0x32c3d2c34ac8daba), UINT64_C(0xbe64037b9031c8e6)),
      simde_mm_set_epi64x(UINT64_C(0x000000000032c3d2), UINT64_C(0xc34ac8dababe6403)) },
    { simde_mm_set_epi64x(UINT64_C(0xcdaebcfc8d354bf5), UINT64_C(0x4670b52bc62e41e9)),
      simde_mm_set_epi64x(UINT64_C(0x0000000000000000), UINT64_C(0x000000cdaebcfc8d)) },
    { simde_mm_set_epi64x(UINT64_C(0x1b7d52a9d22616ff), UINT64_C(0xe67a61bc6e0dd9b8)),
      simde_mm_set_epi64x(UINT64_C(0x00000000001b7d52), UINT64_C(0xa9d22616ffe67a61)) },
    { simde_mm_set_epi64x(UINT64_C(0x77a146df43387240), UINT64_C(0x553fbe9b1e911c28)),
      simde_mm_set_epi64x(UINT64_C(0x0000000000000000), UINT64_C(0x00000077a146df43)) },
    { simde_mm_set_epi64x(UINT64_C(0xa238a74cf266ddca), UINT64_C(0x80c8b7989fed59dd)),
      simde_mm_set_epi64x(UINT64_C(0x0000000000a238a7), UINT64_C(0x4cf266ddca80c8b7)) },
    { simde_mm_set_epi64x(UINT64_C(0x953632e347ddef89), UINT64_C(0x5d7bb6c0e6cecf31)),
      simde_mm_set_epi64x(UINT64_C(0x0000000000000000), UINT64_C(0x000000953632e347)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r;
    if (i % 2) {
      r = simde_mm_bsrli_si128(test_vec[i].a, 11);
    } else {
      r = simde_mm_bsrli_si128(test_vec[i].a, 5);
    }
    simde_assert_m128_u64(r, ==, test_vec[i].r);
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
    { simde_mm_set_epi8(0xa8, 0x66, 0xdb, 0x50, 0x91, 0xe0, 0xea, 0xfb,
			0x6c, 0xd9, 0xcf, 0xf5, 0x47, 0x01, 0x44, 0x58),
      simde_mm_set_epi8(0xbe, 0xeb, 0xaa, 0x50, 0xbc, 0xc5, 0x0e, 0xfb,
			0x5e, 0x81, 0xcf, 0x89, 0x4d, 0x01, 0x44, 0x58),
      simde_mm_set_epi8(0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff,
			0x00, 0x00, 0xff, 0x00, 0x00, 0xff, 0xff, 0xff) },
    { simde_mm_set_epi8(0x51, 0x41, 0x82, 0x84, 0xaa, 0x10, 0xc5, 0xda,
			0x71, 0x66, 0x1a, 0xd6, 0x4e, 0x01, 0xbd, 0xa3),
      simde_mm_set_epi8(0x51, 0x41, 0xb9, 0x84, 0x72, 0x10, 0x5e, 0x37,
			0x71, 0x66, 0xf7, 0xa2, 0xe6, 0xa6, 0xdb, 0xe0),
      simde_mm_set_epi8(0xff, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0x00,
			0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00) },
    { simde_mm_set_epi8(0x3f, 0xc9, 0x9a, 0x51, 0x9c, 0xc6, 0xb7, 0xda,
			0x99, 0xb2, 0x5b, 0xf0, 0xdf, 0xd7, 0x5a, 0xb0),
      simde_mm_set_epi8(0x3f, 0xc9, 0xd7, 0xb3, 0x9c, 0xc6, 0xb7, 0x60,
			0x46, 0xb2, 0x60, 0xf0, 0x81, 0xd7, 0x9f, 0xf5),
      simde_mm_set_epi8(0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0xff, 0x00,
			0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0x00) },
    { simde_mm_set_epi8(0xb9, 0xf6, 0xd0, 0xdb, 0x69, 0x32, 0x0d, 0xed,
			0xaa, 0x96, 0x56, 0xc4, 0x3f, 0x89, 0x6f, 0xfe),
      simde_mm_set_epi8(0x94, 0xf6, 0xd0, 0xdb, 0xbc, 0x34, 0x5c, 0x04,
			0xce, 0x96, 0xec, 0x56, 0x3f, 0x89, 0x6f, 0xfe),
      simde_mm_set_epi8(0x00, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00,
			0x00, 0xff, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff) },
    { simde_mm_set_epi8(0xc7, 0x3e, 0x28, 0x67, 0x32, 0x9b, 0x4b, 0xed,
			0xd4, 0x75, 0xae, 0x24, 0x39, 0xeb, 0xed, 0xbd),
      simde_mm_set_epi8(0x10, 0x3e, 0x28, 0xb8, 0x32, 0x9b, 0x4b, 0xed,
			0xe7, 0x75, 0xae, 0xaf, 0xa8, 0xeb, 0x50, 0xbd),
      simde_mm_set_epi8(0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0xff,
			0x00, 0xff, 0xff, 0x00, 0x00, 0xff, 0x00, 0xff) },
    { simde_mm_set_epi8(0xd6, 0xf5, 0x60, 0x05, 0xfa, 0x9e, 0x78, 0x9d,
			0x27, 0x54, 0xa9, 0xeb, 0xf8, 0xe3, 0xfe, 0xd1),
      simde_mm_set_epi8(0x76, 0xf5, 0x60, 0x05, 0xfa, 0x9e, 0x0e, 0x9d,
			0x1e, 0xb9, 0xe2, 0xae, 0xf8, 0x1d, 0xfe, 0xd1),
      simde_mm_set_epi8(0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0xff,
			0x00, 0x00, 0x00, 0x00, 0xff, 0x00, 0xff, 0xff) },
    { simde_mm_set_epi8(0x1c, 0xad, 0x5b, 0x5b, 0x5c, 0xfb, 0x9c, 0x0e,
			0x09, 0x8a, 0x71, 0xb9, 0x31, 0x0e, 0x53, 0xed),
      simde_mm_set_epi8(0x1c, 0xad, 0x5b, 0x5b, 0x4d, 0x9c, 0x87, 0xbc,
			0x69, 0x8a, 0x71, 0x63, 0x31, 0x0e, 0xd4, 0xed),
      simde_mm_set_epi8(0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00,
			0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff) },
    { simde_mm_set_epi8(0xa5, 0xcd, 0xf3, 0x32, 0x91, 0x67, 0xc4, 0x35,
			0x05, 0xdd, 0xdd, 0x90, 0x83, 0x94, 0x0e, 0x27),
      simde_mm_set_epi8(0xa3, 0xcd, 0xd0, 0x32, 0xec, 0x67, 0xc4, 0x54,
			0x3e, 0xdd, 0xdd, 0xa3, 0xef, 0x94, 0x0e, 0x01),
      simde_mm_set_epi8(0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0xff, 0x00,
			0x00, 0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0x00) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_cmpeq_epi8(test_vec[i].a, test_vec[i].b);
    simde_assert_m128_i8(r, ==, test_vec[i].r);
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
    { simde_mm_set_epi8(0x40, 0x3e, 0x7b, 0x1e, 0x5e, 0x63, 0x1d, 0x0b,
			0x1c, 0x8d, 0xba, 0xd9, 0x9b, 0xb2, 0xf2, 0x43),
      simde_mm_set_epi8(0x40, 0xe5, 0x5d, 0x66, 0x53, 0xf4, 0x1d, 0xd5,
			0x8c, 0x5c, 0x77, 0xd4, 0x30, 0xb2, 0xa3, 0x43),
      simde_mm_set_epi8(0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0x00,
			0x00, 0xff, 0xff, 0x00, 0xff, 0x00, 0x00, 0x00) },
    { simde_mm_set_epi8(0x87, 0x9c, 0x1c, 0x28, 0x10, 0xae, 0x3a, 0x18,
			0xcc, 0xdc, 0x70, 0xba, 0x08, 0x3b, 0x2e, 0x0e),
      simde_mm_set_epi8(0x87, 0xc5, 0x2c, 0x28, 0x26, 0xda, 0x59, 0x1c,
			0x4f, 0x69, 0x20, 0xf4, 0x90, 0x3b, 0x27, 0x0e),
      simde_mm_set_epi8(0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0xff,
			0xff, 0xff, 0x00, 0xff, 0x00, 0x00, 0x00, 0x00) },
    { simde_mm_set_epi8(0x62, 0x7c, 0x3e, 0xea, 0x4c, 0xb2, 0x4b, 0x5d,
			0x19, 0x58, 0xac, 0xf3, 0xcf, 0xe9, 0x71, 0x0d),
      simde_mm_set_epi8(0x62, 0x7c, 0x47, 0xb0, 0x19, 0xb2, 0x81, 0x4b,
			0xf8, 0x58, 0xff, 0x85, 0xcf, 0xe9, 0x00, 0x41),
      simde_mm_set_epi8(0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0x00, 0xff) },
    { simde_mm_set_epi8(0xa1, 0x8e, 0xc5, 0xd9, 0x81, 0x5d, 0x9f, 0xb8,
			0xf7, 0x1a, 0xb2, 0x15, 0x1c, 0x6b, 0xd6, 0x45),
      simde_mm_set_epi8(0x09, 0x15, 0x15, 0xe9, 0xa5, 0xd6, 0x9f, 0xfe,
			0x12, 0xc3, 0xb2, 0x88, 0x1c, 0x6b, 0x49, 0x17),
      simde_mm_set_epi8(0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0xff,
			0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x00) },
    { simde_mm_set_epi8(0xd9, 0x6e, 0x92, 0x73, 0x6b, 0x8b, 0xcd, 0xb3,
			0x3a, 0x60, 0x1d, 0xbc, 0xc5, 0xc7, 0xb2, 0x57),
      simde_mm_set_epi8(0x24, 0x6e, 0x92, 0xe1, 0x45, 0x56, 0xfd, 0x80,
			0xa7, 0x60, 0xb2, 0xec, 0xc5, 0x6f, 0xe0, 0x57),
      simde_mm_set_epi8(0xff, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00,
			0x00, 0x00, 0x00, 0xff, 0x00, 0xff, 0xff, 0x00) },
    { simde_mm_set_epi8(0xd9, 0xc7, 0xab, 0x6f, 0x1a, 0xa0, 0x26, 0x70,
			0xef, 0x2e, 0xaa, 0xa5, 0x18, 0x68, 0xdc, 0x79),
      simde_mm_set_epi8(0x27, 0x4b, 0x42, 0x06, 0x1a, 0xa0, 0x26, 0x70,
			0xfd, 0xe6, 0xaa, 0xab, 0xc9, 0x30, 0x5c, 0xe6),
      simde_mm_set_epi8(0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00,
			0xff, 0x00, 0x00, 0xff, 0x00, 0x00, 0xff, 0x00) },
    { simde_mm_set_epi8(0x93, 0x00, 0x92, 0xec, 0x97, 0x20, 0x3d, 0xcd,
			0x45, 0xa0, 0x57, 0x27, 0xec, 0x71, 0x74, 0x21),
      simde_mm_set_epi8(0xd6, 0xda, 0xa2, 0xf5, 0x7f, 0x20, 0xe6, 0xd8,
			0xe7, 0xc1, 0xd2, 0x27, 0x83, 0x71, 0xc6, 0x21),
      simde_mm_set_epi8(0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0x00, 0xff,
			0x00, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00) },
    { simde_mm_set_epi8(0x05, 0x7e, 0xe7, 0xfe, 0xd0, 0xb7, 0x87, 0xdb,
			0x91, 0xa1, 0x2a, 0x42, 0x9e, 0x77, 0x37, 0x71),
      simde_mm_set_epi8(0x6d, 0x7e, 0xe7, 0x6b, 0xf0, 0x8f, 0xa4, 0x40,
			0xd4, 0x69, 0x0e, 0x42, 0x8c, 0xdd, 0xc0, 0x7c),
      simde_mm_set_epi8(0xff, 0x00, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff,
			0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i r = simde_mm_cmplt_epi8(test_vec[i].a, test_vec[i].b);
    simde_assert_m128_i8(r, ==, test_vec[i].r);
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
    { simde_mm_set_epi64x(UINT64_C(0x5e00534023150960), UINT64_C(0x40c6d3d11a9a3708)),
      UINT64_C(0x40c6d3d11a9a3708) },
    { simde_mm_set_epi64x(UINT64_C(0x126dfc4f4f94dbe7), UINT64_C(0x540883474fef4b96)),
      UINT64_C(0x540883474fef4b96) },
    { simde_mm_set_epi64x(UINT64_C(0x7c8487c60a9142f4), UINT64_C(0xbdec13424134614f)),
      UINT64_C(0xbdec13424134614f) },
    { simde_mm_set_epi64x(UINT64_C(0x678a689785550515), UINT64_C(0x49152032fa3694af)),
      UINT64_C(0x49152032fa3694af) },
    { simde_mm_set_epi64x(UINT64_C(0xabb10bd88756ccbc), UINT64_C(0x06c4ce28263f1afb)),
      UINT64_C(0x06c4ce28263f1afb) },
    { simde_mm_set_epi64x(UINT64_C(0x27e5ddb60099d2e7), UINT64_C(0x1fbd49de9b739b15)),
      UINT64_C(0x1fbd49de9b739b15) },
    { simde_mm_set_epi64x(UINT64_C(0x7752e420b3afa620), UINT64_C(0xd9e5a196f24a9c98)),
      UINT64_C(0xd9e5a196f24a9c98) },
    { simde_mm_set_epi64x(UINT64_C(0x54f703d10efc6ba1), UINT64_C(0x08872806df080feb)),
      UINT64_C(0x08872806df080feb) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    int64_t r = simde_mm_cvtsi128_si64(test_vec[i].a);
    munit_assert_int64(r, ==, test_vec[i].r);
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
    { UINT64_C(0x55999e1ca18c8a61),
      simde_mm_set_epi64x(UINT64_C(0x0000000000000000), UINT64_C(0x55999e1ca18c8a61)) },
    { UINT64_C(0x360e6cf3f8c62559),
      simde_mm_set_epi64x(UINT64_C(0x0000000000000000), UINT64_C(0x360e6cf3f8c62559)) },
    { UINT64_C(0xd11e2fd712bab3d6),
      simde_mm_set_epi64x(UINT64_C(0x0000000000000000), UINT64_C(0xd11e2fd712bab3d6)) },
    { UINT64_C(0x262b5f1d5c70c43e),
      simde_mm_set_epi64x(UINT64_C(0x0000000000000000), UINT64_C(0x262b5f1d5c70c43e)) },
    { UINT64_C(0x13f5e8ad1621d94d),
      simde_mm_set_epi64x(UINT64_C(0x0000000000000000), UINT64_C(0x13f5e8ad1621d94d)) },
    { UINT64_C(0x2f6b30002a764224),
      simde_mm_set_epi64x(UINT64_C(0x0000000000000000), UINT64_C(0x2f6b30002a764224)) },
    { UINT64_C(0x4e2fc408de07ef49),
      simde_mm_set_epi64x(UINT64_C(0x0000000000000000), UINT64_C(0x4e2fc408de07ef49)) },
    { UINT64_C(0xced08103538ed0a9),
      simde_mm_set_epi64x(UINT64_C(0x0000000000000000), UINT64_C(0xced08103538ed0a9)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_cvtsi64_si128(test_vec[i].a);
    simde_assert_m128_i64(r, ==, test_vec[i].r);
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
    { simde_mm_set_epi8(0x9a, 0x7f, 0xc0, 0xf4, 0x0f, 0x93, 0x19, 0x98,
			0x48, 0x48, 0x30, 0xbc, 0x15, 0x74, 0x5b, 0xec),
      simde_mm_set_epi8(0x9a, 0x7f, 0xc0, 0xf4, 0x0f, 0x93, 0x19, 0x98,
			0x48, 0x48, 0x30, 0xbc, 0x15, 0x74, 0x5b, 0xec) },
    { simde_mm_set_epi8(0xa2, 0x32, 0x6a, 0x0d, 0x04, 0x1b, 0x14, 0x23,
			0xbf, 0xbf, 0x71, 0xd2, 0x1e, 0xba, 0x73, 0x34),
      simde_mm_set_epi8(0xa2, 0x32, 0x6a, 0x0d, 0x04, 0x1b, 0x14, 0x23,
			0xbf, 0xbf, 0x71, 0xd2, 0x1e, 0xba, 0x73, 0x34) },
    { simde_mm_set_epi8(0x4d, 0x4f, 0xaa, 0xda, 0xcb, 0x0d, 0x45, 0x08,
			0x3c, 0x3c, 0x31, 0xe2, 0xbf, 0x11, 0x3f, 0x7e),
      simde_mm_set_epi8(0x4d, 0x4f, 0xaa, 0xda, 0xcb, 0x0d, 0x45, 0x08,
			0x3c, 0x3c, 0x31, 0xe2, 0xbf, 0x11, 0x3f, 0x7e) },
    { simde_mm_set_epi8(0xeb, 0xd1, 0xad, 0xc7, 0x78, 0xdc, 0x8f, 0x53,
			0x54, 0x54, 0xfc, 0x5c, 0x59, 0x6c, 0x32, 0x85),
      simde_mm_set_epi8(0xeb, 0xd1, 0xad, 0xc7, 0x78, 0xdc, 0x8f, 0x53,
			0x54, 0x54, 0xfc, 0x5c, 0x59, 0x6c, 0x32, 0x85) },
    { simde_mm_set_epi8(0x23, 0x69, 0x18, 0x20, 0x70, 0x09, 0x63, 0x74,
			0x70, 0x70, 0xfb, 0xd5, 0xb8, 0xc8, 0x4f, 0xce),
      simde_mm_set_epi8(0x23, 0x69, 0x18, 0x20, 0x70, 0x09, 0x63, 0x74,
			0x70, 0x70, 0xfb, 0xd5, 0xb8, 0xc8, 0x4f, 0xce) },
    { simde_mm_set_epi8(0x76, 0xb2, 0x80, 0x76, 0x02, 0x2f, 0x5d, 0x49,
			0xd8, 0xd8, 0x68, 0x88, 0x57, 0x62, 0x12, 0x77),
      simde_mm_set_epi8(0x76, 0xb2, 0x80, 0x76, 0x02, 0x2f, 0x5d, 0x49,
			0xd8, 0xd8, 0x68, 0x88, 0x57, 0x62, 0x12, 0x77) },
    { simde_mm_set_epi8(0x09, 0x12, 0x9f, 0xba, 0x6e, 0x04, 0xa3, 0xab,
			0x97, 0x97, 0x76, 0xca, 0x7d, 0xdf, 0x1d, 0xc3),
      simde_mm_set_epi8(0x09, 0x12, 0x9f, 0xba, 0x6e, 0x04, 0xa3, 0xab,
			0x97, 0x97, 0x76, 0xca, 0x7d, 0xdf, 0x1d, 0xc3) },
    { simde_mm_set_epi8(0xbf, 0x65, 0x55, 0x1f, 0x99, 0x06, 0x0c, 0xe4,
			0x36, 0x36, 0xbf, 0xe9, 0x79, 0x55, 0xf9, 0x5f),
      simde_mm_set_epi8(0xbf, 0x65, 0x55, 0x1f, 0x99, 0x06, 0x0c, 0xe4,
			0x36, 0x36, 0xbf, 0xe9, 0x79, 0x55, 0xf9, 0x5f) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_loadu_si128(&test_vec[i].a);
    simde_assert_m128_i64(r, ==, test_vec[i].r);
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
  } test_vec[8] = {
    { simde_mm_set_epi8(0xc6, 0x77, 0x86, 0xe5, 0xac, 0xac, 0x43, 0xc7,
			0x09, 0xd5, 0x17, 0x93, 0x09, 0x68, 0x44, 0x62),
      UINT32_C(0xbd50) },
    { simde_mm_set_epi8(0xbd, 0x26, 0xc7, 0x4f, 0xbf, 0x8a, 0x32, 0x93,
			0x75, 0xe9, 0x16, 0x61, 0xca, 0x8f, 0xaf, 0x5e),
      UINT32_C(0xad4e) },
    { simde_mm_set_epi8(0xd3, 0x2e, 0xfd, 0x3a, 0x65, 0xf5, 0x7b, 0x23,
			0xf9, 0x3b, 0x25, 0x95, 0x33, 0xce, 0xa3, 0xf4),
      UINT32_C(0xa497) },
    { simde_mm_set_epi8(0x61, 0x63, 0x87, 0x99, 0xf6, 0xd2, 0x64, 0xbd,
			0x62, 0x9a, 0x1f, 0x03, 0x1c, 0xb1, 0x31, 0xa0),
      UINT32_C(0x3d45) },
    { simde_mm_set_epi8(0x51, 0x2f, 0x0f, 0xe8, 0xcb, 0xae, 0x00, 0x51,
			0x37, 0x61, 0x63, 0xf7, 0xb2, 0x9b, 0x96, 0x41),
      UINT32_C(0x1c1e) },
    { simde_mm_set_epi8(0x4a, 0x6f, 0x75, 0x66, 0xa4, 0x29, 0x58, 0xef,
			0x2d, 0x58, 0x10, 0x1d, 0x43, 0x23, 0x01, 0xf5),
      UINT32_C(0x0901) },
    { simde_mm_set_epi8(0x99, 0x9c, 0xe0, 0x04, 0x4f, 0x39, 0xca, 0xe7,
			0xa2, 0x4e, 0x0a, 0xf7, 0xa8, 0x32, 0xe8, 0x91),
      UINT32_C(0xe39b) },
    { simde_mm_set_epi8(0x8f, 0x62, 0x9a, 0x77, 0xaf, 0x3a, 0x8f, 0xda,
			0xd1, 0xcd, 0x0d, 0xb7, 0xc5, 0x3e, 0xc9, 0xe1),
      UINT32_C(0xabdb) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    int32_t r = simde_mm_movemask_epi8(test_vec[i].a);
    munit_assert_int32(r, ==, test_vec[i].r);
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
    { simde_mm_set_epi64x(UINT64_C(0x34d466fc11d47f96), UINT64_C(0x29a984abf12ec683)),
      simde_mm_set_epi64x(UINT64_C(0xea1f9c5c0639a3c0), UINT64_C(0x516104b68c616e5e)),
      simde_mm_set_epi64x(UINT64_C(0xfedffefc17fdffd6), UINT64_C(0x79e984bffd6feedf)) },
    { simde_mm_set_epi64x(UINT64_C(0x3c7bb19b04c7a644), UINT64_C(0xc4f4d29f4ea74ed3)),
      simde_mm_set_epi64x(UINT64_C(0xca48e57ff0c1543d), UINT64_C(0x7419f18c78b42c7a)),
      simde_mm_set_epi64x(UINT64_C(0xfe7bf5fff4c7f67d), UINT64_C(0xf4fdf39f7eb76efb)) },
    { simde_mm_set_epi64x(UINT64_C(0x83fd070c3f4da803), UINT64_C(0xc46f47cb3140ca44)),
      simde_mm_set_epi64x(UINT64_C(0xb6c7e533b7404d1b), UINT64_C(0x191d5a88c78b4685)),
      simde_mm_set_epi64x(UINT64_C(0xb7ffe73fbf4ded1b), UINT64_C(0xdd7f5fcbf7cbcec5)) },
    { simde_mm_set_epi64x(UINT64_C(0xcdcc1dd314d2ed06), UINT64_C(0x9ab20982bf3328e3)),
      simde_mm_set_epi64x(UINT64_C(0xccf0435ae29014b8), UINT64_C(0x4a230dc38be2a012)),
      simde_mm_set_epi64x(UINT64_C(0xcdfc5fdbf6d2fdbe), UINT64_C(0xdab30dc3bff3a8f3)) },
    { simde_mm_set_epi64x(UINT64_C(0x778a48221f75f9b1), UINT64_C(0xef0dcd35473064ae)),
      simde_mm_set_epi64x(UINT64_C(0x75d8bc94794d5977), UINT64_C(0x4262cb7140833d37)),
      simde_mm_set_epi64x(UINT64_C(0x77dafcb67f7df9f7), UINT64_C(0xef6fcf7547b37dbf)) },
    { simde_mm_set_epi64x(UINT64_C(0x1f524e7650fdb9ff), UINT64_C(0xb2a3083cc21e5549)),
      simde_mm_set_epi64x(UINT64_C(0x94fbe990c2f6c27f), UINT64_C(0xb1d92bc6ca057dc0)),
      simde_mm_set_epi64x(UINT64_C(0x9ffbeff6d2fffbff), UINT64_C(0xb3fb2bfeca1f7dc9)) },
    { simde_mm_set_epi64x(UINT64_C(0x5ff9e42c234d4b05), UINT64_C(0xc248e7fc23ced593)),
      simde_mm_set_epi64x(UINT64_C(0x6991039a514634e6), UINT64_C(0x074d1278a45f5a2f)),
      simde_mm_set_epi64x(UINT64_C(0x7ff9e7be734f7fe7), UINT64_C(0xc74df7fca7dfdfbf)) },
    { simde_mm_set_epi64x(UINT64_C(0x56d0c4c3bbf3fb03), UINT64_C(0x35526ead7da7dc8f)),
      simde_mm_set_epi64x(UINT64_C(0xdcb01aaa0298d9be), UINT64_C(0x65a74873fb915126)),
      simde_mm_set_epi64x(UINT64_C(0xdef0deebbbfbfbbf), UINT64_C(0x75f76effffb7ddaf)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_or_si128(test_vec[i].a, test_vec[i].b);
    simde_assert_m128_i8(r, ==, test_vec[i].r);
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
    double e1, e0;
    simde__m128d r;

    e0 = random_double_range(-1000.0, 1000.0);
    e1 = random_double_range(-1000.0, 1000.0);
    r = simde_mm_set_pd(e1, e0);

    munit_assert_int64(r.f64[0], ==, e0);
    munit_assert_int64(r.f64[1], ==, e1);
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
    double a;
    simde__m128d r;

    a = random_double_range(-1000.0, 1000.0);
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
    double a;
    simde__m128d r;

    a = random_double_range(-1000.0, 1000.0);
    r = simde_mm_set_sd(a);

    munit_assert_double(r.f64[0], ==, a);
    munit_assert_int64(r.i64[1], ==, 0);
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
test_simde_mm_srli_epi32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    int imm8;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi32(0xbc86a144, 0x30ab31e4, 0x5521c348, 0xcf932eef),
      14,
      simde_mm_set_epi32(0x0002f21a, 0x0000c2ac, 0x00015487, 0x00033e4c) },
    { simde_mm_set_epi32(0x7d240145, 0x1ecfb081, 0x40961300, 0xcfad5ab6),
      17,
      simde_mm_set_epi32(0x00003e92, 0x00000f67, 0x0000204b, 0x000067d6) },
    { simde_mm_set_epi32(0x996bddc1, 0x1374762b, 0xecafdaee, 0x5fa7ac85),
      22,
      simde_mm_set_epi32(0x00000265, 0x0000004d, 0x000003b2, 0x0000017e) },
    { simde_mm_set_epi32(0x70fddfba, 0x9139ca7e, 0x9bbb9a7b, 0xad9b8144),
      10,
      simde_mm_set_epi32(0x001c3f77, 0x00244e72, 0x0026eee6, 0x002b66e0) },
    { simde_mm_set_epi32(0x2bead65e, 0x5452344c, 0x7add4cb9, 0xe18ac1e1),
      11,
      simde_mm_set_epi32(0x00057d5a, 0x000a8a46, 0x000f5ba9, 0x001c3158) },
    { simde_mm_set_epi32(0xf5a1ffa9, 0x9ce096ea, 0xc386d670, 0xcb94bb65),
      28,
      simde_mm_set_epi32(0x0000000f, 0x00000009, 0x0000000c, 0x0000000c) },
    { simde_mm_set_epi32(0xcf4851fa, 0xd3b76669, 0x83eb1076, 0x92a708a8),
      10,
      simde_mm_set_epi32(0x0033d214, 0x0034edd9, 0x0020fac4, 0x0024a9c2) },
    { simde_mm_set_epi32(0x204cac38, 0x2dd5f86c, 0xfb993fc0, 0x19f263d3),
      26,
      simde_mm_set_epi32(0x00000008, 0x0000000b, 0x0000003e, 0x00000006) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_srli_epi32(test_vec[i].a, test_vec[i].imm8);
    simde_assert_m128_i64(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_srli_si128(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m128i r;
  } test_vec[] = {
    /* 7 */
    { simde_mm_set_epi32(0x47cbef9b, 0xf37c681b, 0xe0db7ffa, 0x55b931b1),
      simde_mm_set_epi32(0x00000000, 0x00000047, 0xcbef9bf3, 0x7c681be0) },
    { simde_mm_set_epi32(0x66b2ef71, 0x8953e15e, 0xdf9e86f7, 0xeba5f6fa),
      simde_mm_set_epi32(0x00000000, 0x00000066, 0xb2ef7189, 0x53e15edf) },
    { simde_mm_set_epi32(0x94ef5556, 0x634aa32f, 0xd712a48b, 0x6988ae75),
      simde_mm_set_epi32(0x00000000, 0x00000094, 0xef555663, 0x4aa32fd7) },
    { simde_mm_set_epi32(0x8fb32058, 0xcdc81a0a, 0x705b7228, 0xf67253b0),
      simde_mm_set_epi32(0x00000000, 0x0000008f, 0xb32058cd, 0xc81a0a70) },
    { simde_mm_set_epi32(0x0ef23909, 0x4d648689, 0x7496ffa0, 0x5b738ef2),
      simde_mm_set_epi32(0x00000000, 0x0000000e, 0xf239094d, 0x64868974) },
    { simde_mm_set_epi32(0x31274e9b, 0x8df1bbf8, 0x7b1c9e50, 0xc893b6e5),
      simde_mm_set_epi32(0x00000000, 0x00000031, 0x274e9b8d, 0xf1bbf87b) },
    { simde_mm_set_epi32(0x23b4b19b, 0xabb75a2b, 0xccef392d, 0xbba221b5),
      simde_mm_set_epi32(0x00000000, 0x00000023, 0xb4b19bab, 0xb75a2bcc) },
    { simde_mm_set_epi32(0x66b0b27f, 0xf97b0a8e, 0xd86b776e, 0x7fe77f32),
      simde_mm_set_epi32(0x00000000, 0x00000066, 0xb0b27ff9, 0x7b0a8ed8) },

    /* 12 */
    { simde_mm_set_epi32(0xcc7298bc, 0x0eaefe5e, 0x83053094, 0x0eacbc77),
      simde_mm_set_epi32(0x00000000, 0x00000000, 0x00000000, 0xcc7298bc) },
    { simde_mm_set_epi32(0xea80c99e, 0xe9d9f6e5, 0x627abfad, 0xd8e9308f),
      simde_mm_set_epi32(0x00000000, 0x00000000, 0x00000000, 0xea80c99e) },
    { simde_mm_set_epi32(0x80e25197, 0x89703305, 0x432d91e4, 0xe5275d5f),
      simde_mm_set_epi32(0x00000000, 0x00000000, 0x00000000, 0x80e25197) },
    { simde_mm_set_epi32(0x648e872a, 0x1002e7bb, 0xcfac334d, 0x2c1bbc18),
      simde_mm_set_epi32(0x00000000, 0x00000000, 0x00000000, 0x648e872a) },
    { simde_mm_set_epi32(0x6a7be438, 0xe6a30e9c, 0xb169e292, 0x3691e799),
      simde_mm_set_epi32(0x00000000, 0x00000000, 0x00000000, 0x6a7be438) },
    { simde_mm_set_epi32(0x55989681, 0x9be27948, 0xbdef7a68, 0xedbaf7ae),
      simde_mm_set_epi32(0x00000000, 0x00000000, 0x00000000, 0x55989681) },
    { simde_mm_set_epi32(0xe9287476, 0x1ee24abc, 0x6bd94ff4, 0x712cfb27),
      simde_mm_set_epi32(0x00000000, 0x00000000, 0x00000000, 0xe9287476) },
    { simde_mm_set_epi32(0x6aa0826a, 0xd63b0b45, 0x8d69bc3c, 0xb0465f97),
      simde_mm_set_epi32(0x00000000, 0x00000000, 0x00000000, 0x6aa0826a) }
  };

  for (size_t i = 0 ; i < ((sizeof(test_vec) / sizeof(test_vec[0])) / 2) ; i++) {
    simde__m128i r = simde_mm_srli_si128(test_vec[i].a, 7);
    simde_assert_m128_i64(r, ==, test_vec[i].r);
  }

  for (size_t i = ((sizeof(test_vec) / sizeof(test_vec[0])) / 2) ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i r = simde_mm_srli_si128(test_vec[i].a, 12);
    simde_assert_m128_i64(r, ==, test_vec[i].r);
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
    { simde_mm_set_epi32(0x0ae179d4, 0x01032f04, 0x2ce74d5e, 0xce4f54b5),
      simde_mm_set_epi32(0x0ae179d4, 0x01032f04, 0x2ce74d5e, 0xce4f54b5) },
    { simde_mm_set_epi32(0x65555c4e, 0x28d018d7, 0xe8547f17, 0xe7e6b298),
      simde_mm_set_epi32(0x65555c4e, 0x28d018d7, 0xe8547f17, 0xe7e6b298) },
    { simde_mm_set_epi32(0x8cbf7747, 0x03b4a484, 0xe9e5b01f, 0x2763cf8f),
      simde_mm_set_epi32(0x8cbf7747, 0x03b4a484, 0xe9e5b01f, 0x2763cf8f) },
    { simde_mm_set_epi32(0x5f63e8f5, 0x2fa10fbd, 0x85220592, 0x09954875),
      simde_mm_set_epi32(0x5f63e8f5, 0x2fa10fbd, 0x85220592, 0x09954875) },
    { simde_mm_set_epi32(0x29c42d69, 0xa9c3ac72, 0x6ce51255, 0xdcd140f1),
      simde_mm_set_epi32(0x29c42d69, 0xa9c3ac72, 0x6ce51255, 0xdcd140f1) },
    { simde_mm_set_epi32(0xfcc9c4db, 0x3e04049d, 0xb6a5ce02, 0xc0e3a6b1),
      simde_mm_set_epi32(0xfcc9c4db, 0x3e04049d, 0xb6a5ce02, 0xc0e3a6b1) },
    { simde_mm_set_epi32(0x6d69063d, 0x7b96cc31, 0x4290b1ec, 0x8321d150),
      simde_mm_set_epi32(0x6d69063d, 0x7b96cc31, 0x4290b1ec, 0x8321d150) },
    { simde_mm_set_epi32(0xb5aa3938, 0x7f9f2f24, 0xb9261ebb, 0xd1164845),
      simde_mm_set_epi32(0xb5aa3938, 0x7f9f2f24, 0xb9261ebb, 0xd1164845) }
  };

  for (size_t i = 0 ; i < sizeof(test_vec) / sizeof(test_vec[0]) ; i++) {
    simde__m128i r;
    simde_mm_storeu_si128(&r, test_vec[i].a);
    simde_assert_m128_i64(r, ==, test_vec[i].r);
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
    { simde_mm_set_epi8(  -19,   -96,   125,   -23,   119,  -104,   119,   -85,
			   75,    30,   -68,  -118,    18,   -11,    43,    98),
      simde_mm_set_epi8(   13,   -69,   -85,   -88,   -79,    -1,   -71,  -121,
			  -34,   -53,    -8,    72,   -52,   115,    30,   -92),
      simde_mm_set_epi8(  -32,   -27,   -46,    65,   -58,  -103,   -66,    36,
			  109,    83,   -60,    66,    70,  -126,    13,   -66) },
    { simde_mm_set_epi8(  -60,    82,   -84,   106,   -37,    15,  -101,  -126,
			  -42,    20,    43,   -10,    51,   -72,    62,    88),
      simde_mm_set_epi8(   27,   112,  -127,  -119,   -70,    95,   -78,    88,
			 -105,   111,   117,   -26,     0,    86,  -128,    18),
      simde_mm_set_epi8(  -87,   -30,    43,   -31,    33,   -80,   -23,    42,
			   63,   -91,   -74,    16,    51,    98,   -66,    70) },
    { simde_mm_set_epi8(  -49,    -7,   -38,    72,   -30,     0,   -91,    -6,
			   95,    20,  -101,    78,    84,   -60,    44,    79),
      simde_mm_set_epi8(   95,    10,   -48,     4,   -12,   125,   117,   -62,
			   45,   104,  -112,    57,     1,    51,    50,   127),
      simde_mm_set_epi8(  112,   -17,    10,    68,   -18,  -125,    48,    56,
			   50,   -84,    11,    21,    83,  -111,    -6,   -48) },
    { simde_mm_set_epi8(  -28,    52,    81,   -76,   104,   -42,   -92,   -21,
			   69,  -109,    76,   111,     9,   103,   -25,     7),
      simde_mm_set_epi8(   50,   -80,    21,   -81,   -99,   103,  -101,    73,
			    8,    70,    -9,    83,    27,    -8,    94,   -46),
      simde_mm_set_epi8(  -78,  -124,    60,     5,   -53,   111,     9,   -94,
			   61,    77,    85,    28,   -18,   111,  -119,    53) },
    { simde_mm_set_epi8(  -57,   -57,  -102,   119,   127,     4,  -113,    76,
		 	   73,   -24,    -6,    41,    29,   -18,  -112,   -30),
      simde_mm_set_epi8(    6,   -75,    92,  -106,    12,   -66,   111,    37,
			   51,    15,    29,    56,    37,   109,    -7,   -41),
      simde_mm_set_epi8(  -63,    18,    62,   -31,   115,    70,    32,    39,
			   22,   -39,   -35,   -15,    -8,  -127,  -105,    11) },
    { simde_mm_set_epi8(   -1,   -16,   -11,   102,    88,   -85,   -35,    69,
			   13,    66,     2,   -63,    53,   -47,    89,  -118),
      simde_mm_set_epi8(   28,   -29,     4,   -85,   -22,   121,    81,    73,
			  118,    -1,   -18,   -62,     4,    58,    11,   -60),
      simde_mm_set_epi8(  -29,    13,   -15,   -69,   110,    50,  -116,    -4,
			 -105,    67,    20,    -1,    49,  -105,    78,   -58) },
    { simde_mm_set_epi8(  112,   -51,   -42,   -22,     7,    20,    -6,    48,
			  -49,    80,  -115,  -104,    -9,   -45,   -78,    37),
      simde_mm_set_epi8(  101,   -52,   -39,   -79,   -34,  -115,    36,    15,
			    6,    92,    77,    70,   108,   -57,    13,    -8),
      simde_mm_set_epi8(   11,     1,    -3,    57,    41,  -121,   -42,    33,
			  -55,   -12,    64,    82,  -117,    12,   -91,    45) },
    { simde_mm_set_epi8( -116,    21,   115,   115,   -95,    10,    90,  -125,
			  -75,     6,  -100,     4,   -33,    28,   -13,    18),
      simde_mm_set_epi8(  -36,    76,    77,   -45,    55,    18,  -114,    18,
			   95,    43,   101,   124,     2,   -12,   -75,   -72),
      simde_mm_set_epi8(  -80,   -55,    38,   -96,   106,    -8,   -52,   113,
			   86,   -37,    55,  -120,   -35,    40,    62,    90) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_sub_epi8(test_vec[i].a, test_vec[i].b);
    simde_assert_m128_i8(r, ==, test_vec[i].r);
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
    { simde_mm_set_epi32(0x89cb9ef4, 0x46da04a4, 0x462815ce, 0x28a65e7d),
      simde_mm_set_epi32(0x7de1c99e, 0xc6af29d0, 0x248d6aa9, 0xc6bf9982),
      simde_mm_set_epi32(0xf42a576a, 0x80752d74, 0x62a57f67, 0xee19c7ff) },
    { simde_mm_set_epi32(0x53031643, 0xfdc66b55, 0xd78ee654, 0xca3bd25d),
      simde_mm_set_epi32(0x472f27a7, 0x9bf79c68, 0x0bf9571e, 0x113b5c93),
      simde_mm_set_epi32(0x142c31e4, 0x6631f73d, 0xdc77b14a, 0xdb008ece) },
    { simde_mm_set_epi32(0x9a50eea7, 0xacf85c94, 0x62ceda43, 0xdb3655b8),
      simde_mm_set_epi32(0x50c0fc0f, 0xa9f43224, 0xf4b03bb9, 0x934d2770),
      simde_mm_set_epi32(0xca9012a8, 0x050c6eb0, 0x967ee1fa, 0x487b72c8) },
    { simde_mm_set_epi32(0x87241408, 0x8e696ce6, 0x70ca6eb2, 0xf1681c03),
      simde_mm_set_epi32(0x3426f722, 0x462b6948, 0xb3d52bb6, 0x21d01c7c),
      simde_mm_set_epi32(0xb302e32a, 0xc84205ae, 0xc31f4504, 0xd0b8007f) },
    { simde_mm_set_epi32(0xc2051fce, 0x6eaacbd9, 0x76fb7a81, 0x64dae4e9),
      simde_mm_set_epi32(0x85d1e746, 0xbac9c603, 0xa05e7f39, 0x31c8f771),
      simde_mm_set_epi32(0x47d4f888, 0xd4630dda, 0xd6a505b8, 0x55121398) },
    { simde_mm_set_epi32(0x7c749045, 0x21771b10, 0xef88c483, 0xd5a8f1b9),
      simde_mm_set_epi32(0x58148d1c, 0xefe387e7, 0x2daff35f, 0xae5eba19),
      simde_mm_set_epi32(0x24601d59, 0xce949cf7, 0xc22737dc, 0x7bf64ba0) },
    { simde_mm_set_epi32(0x3ef87e05, 0x6d683f8a, 0xb6ab0824, 0xafac58c0),
      simde_mm_set_epi32(0x56349e0f, 0x241ee716, 0x311ed590, 0x0fbdcaa5),
      simde_mm_set_epi32(0x68cce00a, 0x4976d89c, 0x87b5ddb4, 0xa0119265) },
    { simde_mm_set_epi32(0x78582f23, 0xded45a89, 0x24eedb32, 0x5bdb870c),
      simde_mm_set_epi32(0x657ed22b, 0xfe65afba, 0x6b2c405c, 0xcefaaa61),
      simde_mm_set_epi32(0x1d26fd08, 0x20b1f533, 0x4fc29b6e, 0x95212d6d) }
  };

  for (size_t i = 0 ; i < sizeof(test_vec) / sizeof(test_vec[0]) ; i++) {
    simde__m128i r = simde_mm_xor_si128(test_vec[i].a, test_vec[i].b);
    simde_assert_m128_i64(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitTest test_suite_tests[] = {
  { (char*) "/mm_set_epi8",      test_simde_mm_set_epi8,      NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_set_epi16",     test_simde_mm_set_epi16,     NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_set_epi32",     test_simde_mm_set_epi32,     NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_set_epi64",     test_simde_mm_set_epi64,     NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_set_epi64x",    test_simde_mm_set_epi64x,    NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_set_pd",        test_simde_mm_set_pd,        NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_set_pd1",       test_simde_mm_set_pd1,       NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_set_sd",        test_simde_mm_set_sd,        NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_set1_epi8",     test_simde_mm_set1_epi8,     NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_setzero_si128", test_simde_mm_setzero_si128, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },

  { (char*) "/mm_add_epi8",      test_simde_mm_add_epi8,      NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_add_epi16",     test_simde_mm_add_epi16,     NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_add_epi32",     test_simde_mm_add_epi32,     NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_add_epi64",     test_simde_mm_add_epi64,     NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_add_pd",        test_simde_mm_add_pd,        NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_add_sd",        test_simde_mm_add_sd,        NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_adds_epi8",     test_simde_mm_adds_epi8,     NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_adds_epi16",    test_simde_mm_adds_epi16,    NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_adds_epu8",     test_simde_mm_adds_epu8,     NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_adds_epu16",    test_simde_mm_adds_epu16,    NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },

  { (char*) "/mm_and_pd",        test_simde_mm_and_pd,        NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_and_si128",     test_simde_mm_and_si128,     NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_andnot_pd",     test_simde_mm_andnot_pd,     NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_andnot_si128",  test_simde_mm_andnot_si128,  NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },

  { (char*) "/mm_avg_epu8",      test_simde_mm_avg_epu8,      NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_avg_epu16",     test_simde_mm_avg_epu16,     NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },

  { (char*) "/mm_bslli_si128",   test_simde_mm_bslli_si128,   NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_bsrli_si128",   test_simde_mm_bsrli_si128,   NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },

  { (char*) "/mm_cmpeq_epi8",    test_simde_mm_cmpeq_epi8,    NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_cmplt_epi8",    test_simde_mm_cmplt_epi8,    NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_cvtsi128_si64", test_simde_mm_cvtsi128_si64, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_cvtsi64_si128", test_simde_mm_cvtsi64_si128, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_loadu_si128",   test_simde_mm_loadu_si128,   NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_movemask_epi8", test_simde_mm_movemask_epi8, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_or_si128",      test_simde_mm_or_si128,      NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_srli_epi32",    test_simde_mm_srli_epi32,    NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_srli_si128",    test_simde_mm_srli_si128,    NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_storeu_si128",  test_simde_mm_storeu_si128,  NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_sub_epi8",      test_simde_mm_sub_epi8,      NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_xor_si128",     test_simde_mm_xor_si128,     NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },

  { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};

const MunitSuite simde_sse2_test_suite = {
  (char*) "/sse2",
  test_suite_tests,
  NULL,
  1,
  MUNIT_SUITE_OPTION_NONE
};
