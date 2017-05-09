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
test_simde_mm_add_si64(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m64 a;
    simde__m64 b;
    simde__m64 r;
  } test_vec[8] = {
    { simde_mm_cvtsi64_m64(UINT64_C(  793111073070173174)),
      simde_mm_cvtsi64_m64(UINT64_C( 2108668061446341817)),
      simde_mm_cvtsi64_m64(UINT64_C( 2901779134516514991)), },
    { simde_mm_cvtsi64_m64(UINT64_C( 8875506276833571865)),
      simde_mm_cvtsi64_m64(UINT64_C(-8625831155966083456)),
      simde_mm_cvtsi64_m64(UINT64_C(  249675120867488409)), },
    { simde_mm_cvtsi64_m64(UINT64_C( 2916092148231541839)),
      simde_mm_cvtsi64_m64(UINT64_C( 7640479428881902755)),
      simde_mm_cvtsi64_m64(UINT64_C(-7890172496596107022)), },
    { simde_mm_cvtsi64_m64(UINT64_C(-3448012693901819300)),
      simde_mm_cvtsi64_m64(UINT64_C(-9198379985559078668)),
      simde_mm_cvtsi64_m64(UINT64_C( 5800351394248653648)), },
    { simde_mm_cvtsi64_m64(UINT64_C( 3628113225825158935)),
      simde_mm_cvtsi64_m64(UINT64_C(-1333669735654572042)),
      simde_mm_cvtsi64_m64(UINT64_C( 2294443490170586893)), },
    { simde_mm_cvtsi64_m64(UINT64_C( 5048798289215441413)),
      simde_mm_cvtsi64_m64(UINT64_C( -388036903570542302)),
      simde_mm_cvtsi64_m64(UINT64_C( 4660761385644899111)), },
    { simde_mm_cvtsi64_m64(UINT64_C( 6446512717337269554)),
      simde_mm_cvtsi64_m64(UINT64_C(-7669829270527021775)),
      simde_mm_cvtsi64_m64(UINT64_C(-1223316553189752221)), },
    { simde_mm_cvtsi64_m64(UINT64_C( 6296531259101832881)),
      simde_mm_cvtsi64_m64(UINT64_C( 5834912758815977701)),
      simde_mm_cvtsi64_m64(UINT64_C(-6315300055791741034)), }
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
    simde__m128d r;
  } test_vec[8] = {
    { simde_mm_set_pd(  131.76,  -843.51),
      simde_mm_set_pd(  922.43,  -843.51),
      simde_mm_set_pd( 0, -1) },
    { simde_mm_set_pd( -923.25,  -873.08),
      simde_mm_set_pd( -923.25,   171.05),
      simde_mm_set_pd(-1,  0) },
    { simde_mm_set_pd( -762.00,   296.14),
      simde_mm_set_pd( -762.00,   296.14),
      simde_mm_set_pd(-1, -1) },
    { simde_mm_set_pd( -371.82,  -722.13),
      simde_mm_set_pd( -786.46,  -850.14),
      simde_mm_set_pd( 0,  0) },
    { simde_mm_set_pd(  245.21,   623.70),
      simde_mm_set_pd(  993.30,    72.16),
      simde_mm_set_pd( 0,  0) },
    { simde_mm_set_pd(    1.55,   956.28),
      simde_mm_set_pd( -377.95,  -993.64),
      simde_mm_set_pd( 0,  0) },
    { simde_mm_set_pd( -739.56,   148.59),
      simde_mm_set_pd( -120.67,   148.59),
      simde_mm_set_pd( 0, -1) },
    { simde_mm_set_pd(  554.04,  -630.74),
      simde_mm_set_pd(  844.21,  -630.74),
      simde_mm_set_pd( 0, -1) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_cmpeq_pd(test_vec[i].a, test_vec[i].b);
    simde_assert_m128d_f64_equal(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_cmpeq_sd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128d a;
    simde__m128d b;
    simde__m128d r;
  } test_vec[8] = {
    { simde_mm_set_pd( -280.38,  -309.53),
      simde_mm_set_pd( -280.38,  -309.53),
      (simde__m128d) { .u64 = { ~UINT64_C(0), 0 } } },
    { simde_mm_set_pd(  814.59,  -423.01),
      simde_mm_set_pd(  814.59,  -161.68),
      (simde__m128d) { .u64 = {  UINT64_C(0), 0 } } },
    { simde_mm_set_pd(  386.76,   224.09),
      simde_mm_set_pd(  -13.47,   -13.47),
      (simde__m128d) { .u64 = {  UINT64_C(0), 0 } } },
    { simde_mm_set_pd(  792.94,   -28.17),
      simde_mm_set_pd(  792.94,   863.32),
      (simde__m128d) { .u64 = {  UINT64_C(0), 0 } } },
    { simde_mm_set_pd(  -70.63,   394.70),
      simde_mm_set_pd( -935.55,   188.26),
      (simde__m128d) { .u64 = {  UINT64_C(0), 0 } } },
    { simde_mm_set_pd( -645.10,  -454.79),
      simde_mm_set_pd(  252.15,  -454.79),
      (simde__m128d) { .u64 = { ~UINT64_C(0), 0 } } },
    { simde_mm_set_pd(  -32.49,   875.53),
      simde_mm_set_pd(  -32.49,   347.69),
      (simde__m128d) { .u64 = {  UINT64_C(0), 0 } } },
    { simde_mm_set_pd(  133.91,  -983.96),
      simde_mm_set_pd(  133.91,   944.66),
      (simde__m128d) { .u64 = {  UINT64_C(0), 0 } } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_cmpeq_sd(test_vec[i].a, test_vec[i].b);
    munit_assert_uint64(r.u64[0], ==, test_vec[i].r.u64[0]);
    munit_assert_float(r.f64[1], ==, test_vec[i].a.f64[1]);
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
    simde__m128d r;
  } test_vec[8] = {
    { simde_mm_set_pd(  -17.42,  -471.42),
      simde_mm_set_pd( -120.90,  -471.42),
      simde_mm_set_pd(-1,  0) },
    { simde_mm_set_pd(  174.13,   302.06),
      simde_mm_set_pd( -462.00,   302.06),
      simde_mm_set_pd(-1,  0) },
    { simde_mm_set_pd(  456.61,   -31.59),
      simde_mm_set_pd(  456.61,   -31.59),
      simde_mm_set_pd( 0,  0) },
    { simde_mm_set_pd(  863.75,   743.68),
      simde_mm_set_pd(  863.75,  -940.38),
      simde_mm_set_pd( 0, -1) },
    { simde_mm_set_pd( -207.80,   181.86),
      simde_mm_set_pd( -207.80,   980.93),
      simde_mm_set_pd( 0, -1) },
    { simde_mm_set_pd( -330.41,   936.80),
      simde_mm_set_pd( -223.97,   936.80),
      simde_mm_set_pd(-1,  0) },
    { simde_mm_set_pd( -293.06,  -978.73),
      simde_mm_set_pd( -858.76,  -978.73),
      simde_mm_set_pd(-1,  0) },
    { simde_mm_set_pd(  215.10,  -720.29),
      simde_mm_set_pd( -813.22,   235.59),
      simde_mm_set_pd(-1, -1) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_cmpneq_pd(test_vec[i].a, test_vec[i].b);
    simde_assert_m128d_f64_equal(r, test_vec[i].r, 1);
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
    simde__m128d r;
  } test_vec[8] = {
    { simde_mm_set_pd(  -17.42,  -471.42),
      simde_mm_set_pd( -120.90,  -471.42),
      (simde__m128d) { .u64 = {  UINT64_C(0), 0 } } },
    { simde_mm_set_pd(  174.13,   302.06),
      simde_mm_set_pd( -462.00,   302.06),
      (simde__m128d) { .u64 = {  UINT64_C(0), 0 } } },
    { simde_mm_set_pd(  456.61,   -31.59),
      simde_mm_set_pd(  456.61,   -31.59),
      (simde__m128d) { .u64 = {  UINT64_C(0), 0 } } },
    { simde_mm_set_pd(  863.75,   743.68),
      simde_mm_set_pd(  863.75,  -940.38),
      (simde__m128d) { .u64 = { ~UINT64_C(0), 0 } } },
    { simde_mm_set_pd( -207.80,   181.86),
      simde_mm_set_pd( -207.80,   980.93),
      (simde__m128d) { .u64 = { ~UINT64_C(0), 0 } } },
    { simde_mm_set_pd( -330.41,   936.80),
      simde_mm_set_pd( -223.97,   936.80),
      (simde__m128d) { .u64 = {  UINT64_C(0), 0 } } },
    { simde_mm_set_pd( -293.06,  -978.73),
      simde_mm_set_pd( -858.76,  -978.73),
      (simde__m128d) { .u64 = {  UINT64_C(0), 0 } } },
    { simde_mm_set_pd(  215.10,  -720.29),
      simde_mm_set_pd( -813.22,   235.59),
      (simde__m128d) { .u64 = { ~UINT64_C(0), 0 } } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_cmpneq_sd(test_vec[i].a, test_vec[i].b);
    munit_assert_uint64(r.u64[0], ==, test_vec[i].r.u64[0]);
    munit_assert_float(r.f64[1], ==, test_vec[i].a.f64[1]);
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
    simde__m128d r;
  } test_vec[8] = {
    { simde_mm_set_pd(  415.53,   -98.38),
      simde_mm_set_pd(  415.53,  -729.13),
      simde_mm_set_pd( 0,  0) },
    { simde_mm_set_pd( -102.02,  -129.13),
      simde_mm_set_pd(  345.59,  -901.28),
      simde_mm_set_pd(-1,  0) },
    { simde_mm_set_pd(  733.11,   268.99),
      simde_mm_set_pd(  733.11,   632.42),
      simde_mm_set_pd( 0, -1) },
    { simde_mm_set_pd(  988.26,     0.67),
      simde_mm_set_pd( -735.83,   857.46),
      simde_mm_set_pd( 0, -1) },
    { simde_mm_set_pd(  631.80,   -84.12),
      simde_mm_set_pd(  596.99,   -84.12),
      simde_mm_set_pd( 0,  0) },
    { simde_mm_set_pd(  633.74,   134.88),
      simde_mm_set_pd( -981.15,  -897.95),
      simde_mm_set_pd( 0,  0) },
    { simde_mm_set_pd(  995.74,  -864.54),
      simde_mm_set_pd( -773.77,  -294.67),
      simde_mm_set_pd( 0, -1) },
    { simde_mm_set_pd( -847.57,   363.82),
      simde_mm_set_pd(  743.31,  -671.22),
      simde_mm_set_pd(-1,  0) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_cmplt_pd(test_vec[i].a, test_vec[i].b);
    simde_assert_m128d_f64_equal(r, test_vec[i].r, 1);
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
    simde__m128d r;
  } test_vec[8] = {
    { simde_mm_set_pd(  415.53,   -98.38),
      simde_mm_set_pd(  415.53,  -729.13),
      (simde__m128d) { .u64 = {  UINT64_C(0), 0 } } },
    { simde_mm_set_pd( -102.02,  -129.13),
      simde_mm_set_pd(  345.59,  -901.28),
      (simde__m128d) { .u64 = {  UINT64_C(0), 0 } } },
    { simde_mm_set_pd(  733.11,   268.99),
      simde_mm_set_pd(  733.11,   632.42),
      (simde__m128d) { .u64 = { ~UINT64_C(0), 0 } } },
    { simde_mm_set_pd(  988.26,     0.67),
      simde_mm_set_pd( -735.83,   857.46),
      (simde__m128d) { .u64 = { ~UINT64_C(0), 0 } } },
    { simde_mm_set_pd(  631.80,   -84.12),
      simde_mm_set_pd(  596.99,   -84.12),
      (simde__m128d) { .u64 = {  UINT64_C(0), 0 } } },
    { simde_mm_set_pd(  633.74,   134.88),
      simde_mm_set_pd( -981.15,  -897.95),
      (simde__m128d) { .u64 = {  UINT64_C(0), 0 } } },
    { simde_mm_set_pd(  995.74,  -864.54),
      simde_mm_set_pd( -773.77,  -294.67),
      (simde__m128d) { .u64 = { ~UINT64_C(0), 0 } } },
    { simde_mm_set_pd( -847.57,   363.82),
      simde_mm_set_pd(  743.31,  -671.22),
      (simde__m128d) { .u64 = {  UINT64_C(0), 0 } } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_cmplt_sd(test_vec[i].a, test_vec[i].b);
    munit_assert_uint64(r.u64[0], ==, test_vec[i].r.u64[0]);
    munit_assert_float(r.f64[1], ==, test_vec[i].a.f64[1]);
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
    simde__m128d r;
  } test_vec[8] = {
    { simde_mm_set_pd(  852.01,  -875.21),
      simde_mm_set_pd(  852.01,  -124.49),
      simde_mm_set_pd(-1,  0) },
    { simde_mm_set_pd(  396.43,  -754.13),
      simde_mm_set_pd(  396.43,  -446.22),
      simde_mm_set_pd(-1,  0) },
    { simde_mm_set_pd(  253.13,   198.68),
      simde_mm_set_pd(  253.13,   828.60),
      simde_mm_set_pd(-1,  0) },
    { simde_mm_set_pd(  137.84,  -995.54),
      simde_mm_set_pd(  137.84,  -366.89),
      simde_mm_set_pd(-1,  0) },
    { simde_mm_set_pd(  981.94,  -371.83),
      simde_mm_set_pd( -999.24,   567.77),
      simde_mm_set_pd(-1,  0) },
    { simde_mm_set_pd(  471.23,  -984.85),
      simde_mm_set_pd( -365.65,   102.67),
      simde_mm_set_pd(-1,  0) },
    { simde_mm_set_pd( -625.86,   -91.22),
      simde_mm_set_pd( -928.96,  -311.29),
      simde_mm_set_pd(-1, -1) },
    { simde_mm_set_pd( -444.22,   458.27),
      simde_mm_set_pd(  882.56,   290.13),
      simde_mm_set_pd( 0, -1) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_cmpnlt_pd(test_vec[i].a, test_vec[i].b);
    simde_assert_m128d_f64_equal(r, test_vec[i].r, 1);
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
    simde__m128d r;
  } test_vec[8] = {
    { simde_mm_set_pd(  852.01,  -875.21),
      simde_mm_set_pd(  852.01,  -124.49),
      (simde__m128d) { .u64 = {  UINT64_C(0), 0 } } },
    { simde_mm_set_pd(  396.43,  -754.13),
      simde_mm_set_pd(  396.43,  -446.22),
      (simde__m128d) { .u64 = {  UINT64_C(0), 0 } } },
    { simde_mm_set_pd(  253.13,   198.68),
      simde_mm_set_pd(  253.13,   828.60),
      (simde__m128d) { .u64 = {  UINT64_C(0), 0 } } },
    { simde_mm_set_pd(  137.84,  -995.54),
      simde_mm_set_pd(  137.84,  -366.89),
      (simde__m128d) { .u64 = {  UINT64_C(0), 0 } } },
    { simde_mm_set_pd(  981.94,  -371.83),
      simde_mm_set_pd( -999.24,   567.77),
      (simde__m128d) { .u64 = {  UINT64_C(0), 0 } } },
    { simde_mm_set_pd(  471.23,  -984.85),
      simde_mm_set_pd( -365.65,   102.67),
      (simde__m128d) { .u64 = {  UINT64_C(0), 0 } } },
    { simde_mm_set_pd( -625.86,   -91.22),
      simde_mm_set_pd( -928.96,  -311.29),
      (simde__m128d) { .u64 = { ~UINT64_C(0), 0 } } },
    { simde_mm_set_pd( -444.22,   458.27),
      simde_mm_set_pd(  882.56,   290.13),
      (simde__m128d) { .u64 = { ~UINT64_C(0), 0 } } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_cmpnlt_sd(test_vec[i].a, test_vec[i].b);
    munit_assert_uint64(r.u64[0], ==, test_vec[i].r.u64[0]);
    munit_assert_float(r.f64[1], ==, test_vec[i].a.f64[1]);
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
    simde__m128d r;
  } test_vec[8] = {
    { simde_mm_set_pd(  543.54,  -463.43),
      simde_mm_set_pd(  803.80,  -383.88),
      simde_mm_set_pd(-1, -1) },
    { simde_mm_set_pd( -420.41,   497.43),
      simde_mm_set_pd( -592.95,  -224.51),
      simde_mm_set_pd( 0,  0) },
    { simde_mm_set_pd( -921.01,  -601.69),
      simde_mm_set_pd( -921.01,  -730.20),
      simde_mm_set_pd(-1,  0) },
    { simde_mm_set_pd( -456.56,   380.21),
      simde_mm_set_pd( -456.56,   380.21),
      simde_mm_set_pd(-1, -1) },
    { simde_mm_set_pd(  317.08,   136.54),
      simde_mm_set_pd(  944.53,   370.42),
      simde_mm_set_pd(-1, -1) },
    { simde_mm_set_pd( -193.09,   515.21),
      simde_mm_set_pd(  -63.27,   515.21),
      simde_mm_set_pd(-1, -1) },
    { simde_mm_set_pd(   14.93,   166.91),
      simde_mm_set_pd(   14.93,  -633.50),
      simde_mm_set_pd(-1,  0) },
    { simde_mm_set_pd(  121.98,  -542.50),
      simde_mm_set_pd(  121.98,  -244.93),
      simde_mm_set_pd(-1, -1) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_cmple_pd(test_vec[i].a, test_vec[i].b);
    simde_assert_m128d_f64_equal(r, test_vec[i].r, 1);
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
    simde__m128d r;
  } test_vec[8] = {
    { simde_mm_set_pd(  543.54,  -463.43),
      simde_mm_set_pd(  803.80,  -383.88),
      (simde__m128d) { .u64 = { ~UINT64_C(0), 0 } } },
    { simde_mm_set_pd( -420.41,   497.43),
      simde_mm_set_pd( -592.95,  -224.51),
      (simde__m128d) { .u64 = {  UINT64_C(0), 0 } } },
    { simde_mm_set_pd( -921.01,  -601.69),
      simde_mm_set_pd( -921.01,  -730.20),
      (simde__m128d) { .u64 = {  UINT64_C(0), 0 } } },
    { simde_mm_set_pd( -456.56,   380.21),
      simde_mm_set_pd( -456.56,   380.21),
      (simde__m128d) { .u64 = { ~UINT64_C(0), 0 } } },
    { simde_mm_set_pd(  317.08,   136.54),
      simde_mm_set_pd(  944.53,   370.42),
      (simde__m128d) { .u64 = { ~UINT64_C(0), 0 } } },
    { simde_mm_set_pd( -193.09,   515.21),
      simde_mm_set_pd(  -63.27,   515.21),
      (simde__m128d) { .u64 = { ~UINT64_C(0), 0 } } },
    { simde_mm_set_pd(   14.93,   166.91),
      simde_mm_set_pd(   14.93,  -633.50),
      (simde__m128d) { .u64 = {  UINT64_C(0), 0 } } },
    { simde_mm_set_pd(  121.98,  -542.50),
      simde_mm_set_pd(  121.98,  -244.93),
      (simde__m128d) { .u64 = { ~UINT64_C(0), 0 } } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_cmple_sd(test_vec[i].a, test_vec[i].b);
    munit_assert_uint64(r.u64[0], ==, test_vec[i].r.u64[0]);
    munit_assert_float(r.f64[1], ==, test_vec[i].a.f64[1]);
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
    simde__m128d r;
  } test_vec[8] = {
    { simde_mm_set_pd(  -50.93,  -877.25),
      simde_mm_set_pd(  -50.93,    61.42),
      simde_mm_set_pd( 0,  0) },
    { simde_mm_set_pd(  567.19,   768.82),
      simde_mm_set_pd( -689.51,   768.82),
      simde_mm_set_pd(-1,  0) },
    { simde_mm_set_pd(  625.00,   979.36),
      simde_mm_set_pd(   59.83,   979.36),
      simde_mm_set_pd(-1,  0) },
    { simde_mm_set_pd( -994.58,   130.45),
      simde_mm_set_pd( -720.49,   130.45),
      simde_mm_set_pd( 0,  0) },
    { simde_mm_set_pd(  889.79,  -677.25),
      simde_mm_set_pd(  889.79,  -677.25),
      simde_mm_set_pd( 0,  0) },
    { simde_mm_set_pd(  802.11,  -926.46),
      simde_mm_set_pd( -136.48,  -926.46),
      simde_mm_set_pd(-1,  0) },
    { simde_mm_set_pd( -579.79,   368.31),
      simde_mm_set_pd( -579.79,  -736.86),
      simde_mm_set_pd( 0, -1) },
    { simde_mm_set_pd(  408.86,    63.85),
      simde_mm_set_pd(  408.86,   878.02),
      simde_mm_set_pd( 0,  0) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_cmpnle_pd(test_vec[i].a, test_vec[i].b);
    simde_assert_m128d_f64_equal(r, test_vec[i].r, 1);
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
    simde__m128d r;
  } test_vec[8] = {
    { simde_mm_set_pd(  -50.93,  -877.25),
      simde_mm_set_pd(  -50.93,    61.42),
      (simde__m128d) { .u64 = {  UINT64_C(0), 0 } } },
    { simde_mm_set_pd(  567.19,   768.82),
      simde_mm_set_pd( -689.51,   768.82),
      (simde__m128d) { .u64 = {  UINT64_C(0), 0 } } },
    { simde_mm_set_pd(  625.00,   979.36),
      simde_mm_set_pd(   59.83,   979.36),
      (simde__m128d) { .u64 = {  UINT64_C(0), 0 } } },
    { simde_mm_set_pd( -994.58,   130.45),
      simde_mm_set_pd( -720.49,   130.45),
      (simde__m128d) { .u64 = {  UINT64_C(0), 0 } } },
    { simde_mm_set_pd(  889.79,  -677.25),
      simde_mm_set_pd(  889.79,  -677.25),
      (simde__m128d) { .u64 = {  UINT64_C(0), 0 } } },
    { simde_mm_set_pd(  802.11,  -926.46),
      simde_mm_set_pd( -136.48,  -926.46),
      (simde__m128d) { .u64 = {  UINT64_C(0), 0 } } },
    { simde_mm_set_pd( -579.79,   368.31),
      simde_mm_set_pd( -579.79,  -736.86),
      (simde__m128d) { .u64 = { ~UINT64_C(0), 0 } } },
    { simde_mm_set_pd(  408.86,    63.85),
      simde_mm_set_pd(  408.86,   878.02),
      (simde__m128d) { .u64 = {  UINT64_C(0), 0 } } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_cmpnle_sd(test_vec[i].a, test_vec[i].b);
    munit_assert_uint64(r.u64[0], ==, test_vec[i].r.u64[0]);
    munit_assert_float(r.f64[1], ==, test_vec[i].a.f64[1]);
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
    { simde_mm_set_epi8(  13,  -99, -128,   91,  -96,  103, -104, -110,
                         -46,   -5,   62, -125,  -51,  -65, -102,  -14),
      simde_mm_set_epi8(  10,  -84,   90, -110,  113,  -34,  -75, -110,
                         -79, -114,   26, -127,   -5,   -9, -102,  -38),
      simde_mm_set_epi8(  -1,    0,    0,   -1,    0,   -1,    0,    0,
                          -1,   -1,   -1,   -1,    0,    0,    0,   -1) },
    { simde_mm_set_epi8(-110,  -93,  106,  -55,   91,  -78,   69,   62,
                          38, -101,   86, -107,  114,  120, -118,  101),
      simde_mm_set_epi8(  58,  -88,   75,  -55,   92,   51, -109,   62,
                         123,  -42,    0,   40,  114, -115,   34,  101),
      simde_mm_set_epi8(   0,    0,   -1,    0,    0,    0,   -1,    0,
                           0,    0,   -1,    0,    0,   -1,    0,    0) },
    { simde_mm_set_epi8(  79,   -2, -126, -121,   71,  -59,   95,   38,
                         -95,  103,  -55,  -42, -124,  -82,  102,   97),
      simde_mm_set_epi8( -39,  -59, -126, -107, -111,  122,  -55,   87,
                         -95,  -99,   56,  120,  107,  -79,   -9,  -36),
      simde_mm_set_epi8(  -1,   -1,    0,    0,   -1,    0,   -1,    0,
                           0,   -1,    0,    0,    0,    0,   -1,   -1) },
    { simde_mm_set_epi8( -68,    7,  -32,  120, -106, -127,   37,   95,
                         -77, -126, -111,  -96,   67,   43, -123,   21),
      simde_mm_set_epi8(  72,   68,   76,  -22,  -11,   34,  112,   95,
                         -77,   36,  119,  -59,  -49,  -22, -125,   21),
      simde_mm_set_epi8(   0,    0,    0,   -1,    0,    0,    0,    0,
                           0,    0,    0,    0,   -1,   -1,   -1,    0) },
    { simde_mm_set_epi8( -18,   13,   66,  -52,  -92,   28, -122,  -12,
                         -60,  125, -104, -118,  -76,   42,  -48, -120),
      simde_mm_set_epi8( -17,   13,   66,  -64,  -92,  114, -119, -106,
                          78, -125,   88,  -88,  101,   42,  -58,   -8),
      simde_mm_set_epi8(   0,    0,    0,   -1,    0,    0,    0,   -1,
                           0,   -1,    0,    0,    0,    0,   -1,    0) },
    { simde_mm_set_epi8(-112,  -16,   96,  -64,   75,   56,  -96,   96,
                          -8,   16,   95,   41,   62,   -2, -105, -101),
      simde_mm_set_epi8(  42,    7,   90,  -93,   75,   14,   -5,   61,
                          -8,  -49,   95,   82,  -93,  -80,    6,  -48),
      simde_mm_set_epi8(   0,    0,   -1,   -1,    0,   -1,    0,   -1,
                           0,   -1,    0,    0,   -1,   -1,    0,    0) },
    { simde_mm_set_epi8( -56,  -85,    9,    3,   32, -105,   93,  -78,
                        -113,   96,   61,   14,  -92,   53,   51,   -7),
      simde_mm_set_epi8(  15,  100,    9,   70, -115, -105,   14,  -41,
                        -113,  -54,  -38,   14,  -53,    5, -127,   -7),
      simde_mm_set_epi8(   0,    0,    0,    0,   -1,    0,   -1,    0,
                           0,   -1,   -1,    0,    0,   -1,   -1,    0) },
    { simde_mm_set_epi8( 120,   38,   44,  103,   33,  -93, -102,  -46,
                          47,    7,  120,  102,  -87,  -84,   92,   87),
      simde_mm_set_epi8( -11,   89,   26,   69,  108,  127, -102,   49,
                          53,   57,  120,  -23,  -87,  -84,  113,  -36),
      simde_mm_set_epi8(  -1,    0,   -1,   -1,    0,    0,    0,    0,
                           0,    0,    0,   -1,    0,    0,    0,   -1) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i r = simde_mm_cmpgt_epi8(test_vec[i].a, test_vec[i].b);
    simde_assert_m128_i8(r, ==, test_vec[i].r);
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
    simde__m128d r;
  } test_vec[8] = {
    { simde_mm_set_pd( -649.61,   366.73),
      simde_mm_set_pd(  333.59,   116.88),
      simde_mm_set_pd( 0, -1) },
    { simde_mm_set_pd( -619.22,  -854.65),
      simde_mm_set_pd( -854.79,   863.33),
      simde_mm_set_pd(-1,  0) },
    { simde_mm_set_pd( -950.10,   381.78),
      simde_mm_set_pd(  844.77,  -217.11),
      simde_mm_set_pd( 0, -1) },
    { simde_mm_set_pd( -925.79,  -916.91),
      simde_mm_set_pd(  -17.99,   826.72),
      simde_mm_set_pd( 0,  0) },
    { simde_mm_set_pd(  581.21,   639.37),
      simde_mm_set_pd(  581.21,   448.67),
      simde_mm_set_pd( 0, -1) },
    { simde_mm_set_pd(  702.29,  -582.84),
      simde_mm_set_pd(  702.29,   186.24),
      simde_mm_set_pd( 0,  0) },
    { simde_mm_set_pd(  532.21,   145.56),
      simde_mm_set_pd( -677.14,   145.56),
      simde_mm_set_pd(-1,  0) },
    { simde_mm_set_pd(  459.86,   265.89),
      simde_mm_set_pd( -130.43,   334.48),
      simde_mm_set_pd(-1,  0) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_cmpgt_pd(test_vec[i].a, test_vec[i].b);
    simde_assert_m128d_f64_equal(r, test_vec[i].r, 1);
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
    simde__m128d r;
  } test_vec[8] = {
    { simde_mm_set_pd( -649.61,   366.73),
      simde_mm_set_pd(  333.59,   116.88),
      (simde__m128d) { .u64 = { ~UINT64_C(0), 0 } } },
    { simde_mm_set_pd( -619.22,  -854.65),
      simde_mm_set_pd( -854.79,   863.33),
      (simde__m128d) { .u64 = {  UINT64_C(0), 0 } } },
    { simde_mm_set_pd( -950.10,   381.78),
      simde_mm_set_pd(  844.77,  -217.11),
      (simde__m128d) { .u64 = { ~UINT64_C(0), 0 } } },
    { simde_mm_set_pd( -925.79,  -916.91),
      simde_mm_set_pd(  -17.99,   826.72),
      (simde__m128d) { .u64 = {  UINT64_C(0), 0 } } },
    { simde_mm_set_pd(  581.21,   639.37),
      simde_mm_set_pd(  581.21,   448.67),
      (simde__m128d) { .u64 = { ~UINT64_C(0), 0 } } },
    { simde_mm_set_pd(  702.29,  -582.84),
      simde_mm_set_pd(  702.29,   186.24),
      (simde__m128d) { .u64 = {  UINT64_C(0), 0 } } },
    { simde_mm_set_pd(  532.21,   145.56),
      simde_mm_set_pd( -677.14,   145.56),
      (simde__m128d) { .u64 = {  UINT64_C(0), 0 } } },
    { simde_mm_set_pd(  459.86,   265.89),
      simde_mm_set_pd( -130.43,   334.48),
      (simde__m128d) { .u64 = {  UINT64_C(0), 0 } } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_cmpgt_sd(test_vec[i].a, test_vec[i].b);
    munit_assert_uint64(r.u64[0], ==, test_vec[i].r.u64[0]);
    munit_assert_float(r.f64[1], ==, test_vec[i].a.f64[1]);
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
    simde__m128d r;
  } test_vec[8] = {
    { simde_mm_set_pd( -649.61,   366.73),
      simde_mm_set_pd(  333.59,   116.88),
      simde_mm_set_pd( 0, -1) },
    { simde_mm_set_pd( -619.22,  -854.65),
      simde_mm_set_pd( -854.79,   863.33),
      simde_mm_set_pd(-1,  0) },
    { simde_mm_set_pd( -950.10,   381.78),
      simde_mm_set_pd(  844.77,  -217.11),
      simde_mm_set_pd( 0, -1) },
    { simde_mm_set_pd( -925.79,  -916.91),
      simde_mm_set_pd(  -17.99,   826.72),
      simde_mm_set_pd( 0,  0) },
    { simde_mm_set_pd(  581.21,   639.37),
      simde_mm_set_pd(  581.21,   448.67),
      simde_mm_set_pd(-1, -1) },
    { simde_mm_set_pd(  702.29,  -582.84),
      simde_mm_set_pd(  702.29,   186.24),
      simde_mm_set_pd(-1,  0) },
    { simde_mm_set_pd(  532.21,   145.56),
      simde_mm_set_pd( -677.14,   145.56),
      simde_mm_set_pd(-1, -1) },
    { simde_mm_set_pd(  459.86,   265.89),
      simde_mm_set_pd( -130.43,   334.48),
      simde_mm_set_pd(-1,  0) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_cmpge_pd(test_vec[i].a, test_vec[i].b);
    simde_assert_m128d_f64_equal(r, test_vec[i].r, 1);
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
    simde__m128d r;
  } test_vec[8] = {
    { simde_mm_set_pd( -649.61,   366.73),
      simde_mm_set_pd(  333.59,   116.88),
      (simde__m128d) { .u64 = { ~UINT64_C(0), 0 } } },
    { simde_mm_set_pd( -619.22,  -854.65),
      simde_mm_set_pd( -854.79,   863.33),
      (simde__m128d) { .u64 = {  UINT64_C(0), 0 } } },
    { simde_mm_set_pd( -950.10,   381.78),
      simde_mm_set_pd(  844.77,  -217.11),
      (simde__m128d) { .u64 = { ~UINT64_C(0), 0 } } },
    { simde_mm_set_pd( -925.79,  -916.91),
      simde_mm_set_pd(  -17.99,   826.72),
      (simde__m128d) { .u64 = {  UINT64_C(0), 0 } } },
    { simde_mm_set_pd(  581.21,   639.37),
      simde_mm_set_pd(  581.21,   448.67),
      (simde__m128d) { .u64 = { ~UINT64_C(0), 0 } } },
    { simde_mm_set_pd(  702.29,  -582.84),
      simde_mm_set_pd(  702.29,   186.24),
      (simde__m128d) { .u64 = {  UINT64_C(0), 0 } } },
    { simde_mm_set_pd(  532.21,   145.56),
      simde_mm_set_pd( -677.14,   145.56),
      (simde__m128d) { .u64 = { ~UINT64_C(0), 0 } } },
    { simde_mm_set_pd(  459.86,   265.89),
      simde_mm_set_pd( -130.43,   334.48),
      (simde__m128d) { .u64 = {  UINT64_C(0), 0 } } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_cmpge_sd(test_vec[i].a, test_vec[i].b);
    munit_assert_uint64(r.u64[0], ==, test_vec[i].r.u64[0]);
    munit_assert_float(r.f64[1], ==, test_vec[i].a.f64[1]);
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
    simde__m128d r;
  } test_vec[8] = {
    { simde_mm_set_pd(   65.48,  -195.60),
      simde_mm_set_pd(   65.48,    18.27),
      simde_mm_set_pd( 0, -1) },
    { simde_mm_set_pd( -563.65,   884.03),
      simde_mm_set_pd(  467.71,  -906.63),
      simde_mm_set_pd(-1,  0) },
    { simde_mm_set_pd( -553.85,    49.09),
      simde_mm_set_pd(  731.88,   974.91),
      simde_mm_set_pd(-1, -1) },
    { simde_mm_set_pd(  492.98,    64.21),
      simde_mm_set_pd( -392.36,  -188.43),
      simde_mm_set_pd( 0,  0) },
    { simde_mm_set_pd( -248.75,  -404.39),
      simde_mm_set_pd( -495.92,  -819.81),
      simde_mm_set_pd( 0,  0) },
    { simde_mm_set_pd( -932.57,   741.27),
      simde_mm_set_pd( -307.42,   170.69),
      simde_mm_set_pd(-1,  0) },
    { simde_mm_set_pd( -939.12,  -161.45),
      simde_mm_set_pd( -939.12,  -161.45),
      simde_mm_set_pd( 0,  0) },
    { simde_mm_set_pd( -900.20,  -314.63),
      simde_mm_set_pd(  138.12,   517.19),
      simde_mm_set_pd(-1, -1) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_cmpnge_pd(test_vec[i].a, test_vec[i].b);
    simde_assert_m128d_f64_equal(r, test_vec[i].r, 1);
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
    simde__m128d r;
  } test_vec[8] = {
    { simde_mm_set_pd(   65.48,  -195.60),
      simde_mm_set_pd(   65.48,    18.27),
      (simde__m128d) { .u64 = { ~UINT64_C(0), 0 } } },
    { simde_mm_set_pd( -563.65,   884.03),
      simde_mm_set_pd(  467.71,  -906.63),
      (simde__m128d) { .u64 = {  UINT64_C(0), 0 } } },
    { simde_mm_set_pd( -553.85,    49.09),
      simde_mm_set_pd(  731.88,   974.91),
      (simde__m128d) { .u64 = { ~UINT64_C(0), 0 } } },
    { simde_mm_set_pd(  492.98,    64.21),
      simde_mm_set_pd( -392.36,  -188.43),
      (simde__m128d) { .u64 = {  UINT64_C(0), 0 } } },
    { simde_mm_set_pd( -248.75,  -404.39),
      simde_mm_set_pd( -495.92,  -819.81),
      (simde__m128d) { .u64 = {  UINT64_C(0), 0 } } },
    { simde_mm_set_pd( -932.57,   741.27),
      simde_mm_set_pd( -307.42,   170.69),
      (simde__m128d) { .u64 = {  UINT64_C(0), 0 } } },
    { simde_mm_set_pd( -939.12,  -161.45),
      simde_mm_set_pd( -939.12,  -161.45),
      (simde__m128d) { .u64 = {  UINT64_C(0), 0 } } },
    { simde_mm_set_pd( -900.20,  -314.63),
      simde_mm_set_pd(  138.12,   517.19),
      (simde__m128d) { .u64 = { ~UINT64_C(0), 0 } } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_cmpnge_sd(test_vec[i].a, test_vec[i].b);
    munit_assert_uint64(r.u64[0], ==, test_vec[i].r.u64[0]);
    munit_assert_float(r.f64[1], ==, test_vec[i].a.f64[1]);
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
    simde__m128d r;
  } test_vec[8] = {
    { simde_mm_set_pd(  107.72,  -915.48),
      simde_mm_set_pd( nan(""),  -303.84),
      { .u64 = { UINT64_C(0xffffffffffffffff), UINT64_C(0x0000000000000000) } } },
    { simde_mm_set_pd( nan(""),   173.20),
      simde_mm_set_pd( -817.33,   659.40),
      { .u64 = { UINT64_C(0xffffffffffffffff), UINT64_C(0x0000000000000000) } } },
    { simde_mm_set_pd( nan(""),  nan("")),
      simde_mm_set_pd( -425.32,   993.95),
      { .u64 = { UINT64_C(0x0000000000000000), UINT64_C(0x0000000000000000) } } },
    { simde_mm_set_pd( -650.75,  nan("")),
      simde_mm_set_pd( nan(""),  -971.81),
      { .u64 = { UINT64_C(0x0000000000000000), UINT64_C(0x0000000000000000) } } },
    { simde_mm_set_pd( -761.29,  -694.76),
      simde_mm_set_pd( -709.09,   614.12),
      { .u64 = { UINT64_C(0xffffffffffffffff), UINT64_C(0xffffffffffffffff) } } },
    { simde_mm_set_pd(  498.19,  -379.74),
      simde_mm_set_pd( -247.48,  -578.21),
      { .u64 = { UINT64_C(0xffffffffffffffff), UINT64_C(0xffffffffffffffff) } } },
    { simde_mm_set_pd(  101.51,   387.46),
      simde_mm_set_pd(  215.97,   173.76),
      { .u64 = { UINT64_C(0xffffffffffffffff), UINT64_C(0xffffffffffffffff) } } },
    { simde_mm_set_pd(  729.13,   771.13),
      simde_mm_set_pd(  902.43,  -416.43),
      { .u64 = { UINT64_C(0xffffffffffffffff), UINT64_C(0xffffffffffffffff) } } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_cmpord_pd(test_vec[i].a, test_vec[i].b);
    simde_assert_m128d_f64_equal(r, test_vec[i].r, 1);
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
    simde__m128d r;
  } test_vec[8] = {
    { simde_mm_set_pd(  243.61,   376.31),
      simde_mm_set_pd( nan(""),  nan("")),
      { .u64 = { UINT64_C(0x0000000000000000), UINT64_C(0x406e73851eb851ec) } } },
    { simde_mm_set_pd( -269.92,   109.63),
      simde_mm_set_pd( -480.22,   930.22),
      { .u64 = { UINT64_C(0xffffffffffffffff), UINT64_C(0xc070deb851eb851f) } } },
    { simde_mm_set_pd( -954.22,  -637.73),
      simde_mm_set_pd( -866.80,   770.28),
      { .u64 = { UINT64_C(0xffffffffffffffff), UINT64_C(0xc08dd1c28f5c28f6) } } },
    { simde_mm_set_pd( -499.36,  -515.42),
      simde_mm_set_pd(  198.37,   980.21),
      { .u64 = { UINT64_C(0xffffffffffffffff), UINT64_C(0xc07f35c28f5c28f6) } } },
    { simde_mm_set_pd(  661.89,  -778.93),
      simde_mm_set_pd(  182.64,  -310.55),
      { .u64 = { UINT64_C(0xffffffffffffffff), UINT64_C(0x4084af1eb851eb85) } } },
    { simde_mm_set_pd(  555.69,  -313.06),
      simde_mm_set_pd( -374.85,   627.14),
      { .u64 = { UINT64_C(0xffffffffffffffff), UINT64_C(0x40815d851eb851ec) } } },
    { simde_mm_set_pd( -502.78,   974.01),
      simde_mm_set_pd(  676.46,   514.23),
      { .u64 = { UINT64_C(0xffffffffffffffff), UINT64_C(0xc07f6c7ae147ae14) } } },
    { simde_mm_set_pd(  108.28,   -38.67),
      simde_mm_set_pd( nan(""),  nan("")),
      { .u64 = { UINT64_C(0x0000000000000000), UINT64_C(0x405b11eb851eb852) } } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_cmpord_sd(test_vec[i].a, test_vec[i].b);
    munit_assert_uint64(r.u64[0], ==, test_vec[i].r.u64[0]);
    munit_assert_float(r.f64[1], ==, test_vec[i].a.f64[1]);
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
    simde__m128d r;
  } test_vec[8] = {
    { simde_mm_set_pd( nan(""),   670.49),
      simde_mm_set_pd( nan(""),   826.75),
      { .u64 = { UINT64_C(0x0000000000000000), UINT64_C(0xffffffffffffffff) } } },
    { simde_mm_set_pd( -774.95,  nan("")),
      simde_mm_set_pd(  247.71,  nan("")),
      { .u64 = { UINT64_C(0xffffffffffffffff), UINT64_C(0x0000000000000000) } } },
    { simde_mm_set_pd(  -88.77,   116.09),
      simde_mm_set_pd(  -32.79,  -442.07),
      { .u64 = { UINT64_C(0x0000000000000000), UINT64_C(0x0000000000000000) } } },
    { simde_mm_set_pd(   71.71,   549.42),
      simde_mm_set_pd( nan(""),  -288.27),
      { .u64 = { UINT64_C(0x0000000000000000), UINT64_C(0xffffffffffffffff) } } },
    { simde_mm_set_pd( -266.24,  -147.24),
      simde_mm_set_pd(  900.46,  -288.71),
      { .u64 = { UINT64_C(0x0000000000000000), UINT64_C(0x0000000000000000) } } },
    { simde_mm_set_pd( nan(""),  nan("")),
      simde_mm_set_pd(  196.30,  nan("")),
      { .u64 = { UINT64_C(0xffffffffffffffff), UINT64_C(0xffffffffffffffff) } } },
    { simde_mm_set_pd( -447.36,   236.69),
      simde_mm_set_pd( -774.85,  -611.68),
      { .u64 = { UINT64_C(0x0000000000000000), UINT64_C(0x0000000000000000) } } },
    { simde_mm_set_pd( nan(""),  nan("")),
      simde_mm_set_pd(  711.66,  -751.40),
      { .u64 = { UINT64_C(0xffffffffffffffff), UINT64_C(0xffffffffffffffff) } } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_cmpunord_pd(test_vec[i].a, test_vec[i].b);
    simde_assert_m128d_f64_equal(r, test_vec[i].r, 1);
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
    simde__m128d r;
  } test_vec[8] = {
    { simde_mm_set_pd( -900.44,   555.35),
      simde_mm_set_pd( -768.21,  nan("")),
      { .u64 = { UINT64_C(0xffffffffffffffff), UINT64_C(0xc08c23851eb851ec) } } },
    { simde_mm_set_pd( -356.71,   937.54),
      simde_mm_set_pd( nan(""),   223.12),
      { .u64 = { UINT64_C(0x0000000000000000), UINT64_C(0xc0764b5c28f5c28f) } } },
    { simde_mm_set_pd(  227.98,   -74.57),
      simde_mm_set_pd( -452.57,  nan("")),
      { .u64 = { UINT64_C(0xffffffffffffffff), UINT64_C(0x406c7f5c28f5c28f) } } },
    { simde_mm_set_pd(  297.17,   401.91),
      simde_mm_set_pd(  857.32,   626.54),
      { .u64 = { UINT64_C(0x0000000000000000), UINT64_C(0x407292b851eb851f) } } },
    { simde_mm_set_pd(  739.06,  -952.53),
      simde_mm_set_pd(  352.92,  -550.85),
      { .u64 = { UINT64_C(0x0000000000000000), UINT64_C(0x4087187ae147ae14) } } },
    { simde_mm_set_pd(  215.28,   461.45),
      simde_mm_set_pd(   12.14,  nan("")),
      { .u64 = { UINT64_C(0xffffffffffffffff), UINT64_C(0x406ae8f5c28f5c29) } } },
    { simde_mm_set_pd(  735.02,   398.76),
      simde_mm_set_pd(  640.06,  nan("")),
      { .u64 = { UINT64_C(0xffffffffffffffff), UINT64_C(0x4086f828f5c28f5c) } } },
    { simde_mm_set_pd(  358.88,  -165.28),
      simde_mm_set_pd( nan(""),   339.89),
      { .u64 = { UINT64_C(0x0000000000000000), UINT64_C(0x40766e147ae147ae) } } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_cmpunord_sd(test_vec[i].a, test_vec[i].b);
    munit_assert_uint64(r.u64[0], ==, test_vec[i].r.u64[0]);
    munit_assert_float(r.f64[1], ==, test_vec[i].a.f64[1]);
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
      simde_mm_set_pd(1726684816.00, -1842005323.00) },
    { simde_mm_set_epi32(-1162443511,  1098837378,  -970075414,  1210551220),
      simde_mm_set_pd(-970075414.00, 1210551220.00) },
    { simde_mm_set_epi32( 1014915875,   235168560,   691866984,  -431325465),
      simde_mm_set_pd(691866984.00, -431325465.00) },
    { simde_mm_set_epi32( 1621419008,  1286931249, -1424446000,  -169673917),
      simde_mm_set_pd(-1424446000.00, -169673917.00) },
    { simde_mm_set_epi32(  982570498,    31161721,   410129833,  1249524705),
      simde_mm_set_pd(410129833.00, 1249524705.00) },
    { simde_mm_set_epi32(-1807976526,   584564543,  1386856775,  -792093051),
      simde_mm_set_pd(1386856775.00, -792093051.00) },
    { simde_mm_set_epi32( 1927957259,   324939853,  1056227907,   960202603),
      simde_mm_set_pd(1056227907.00, 960202603.00) },
    { simde_mm_set_epi32( 2096858414,  2117774841,   250894175,  1268045519),
      simde_mm_set_pd(250894175.00, 1268045519.00) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_cvtepi32_pd(test_vec[i].a);
    simde_assert_m128d_f64_equal(r, test_vec[i].r, 1);
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
      simde_mm_set_ps( 332.00, -787.00,  -79.00, -785.00) },
    { simde_mm_set_epi32( 394, -936, -733, -136),
      simde_mm_set_ps( 394.00, -936.00, -733.00, -136.00) },
    { simde_mm_set_epi32( 618, -416,  310,  183),
      simde_mm_set_ps( 618.00, -416.00,  310.00,  183.00) },
    { simde_mm_set_epi32(-748,  245,  533, -152),
      simde_mm_set_ps(-748.00,  245.00,  533.00, -152.00) },
    { simde_mm_set_epi32(  42,  893,  849, -741),
      simde_mm_set_ps(  42.00,  893.00,  849.00, -741.00) },
    { simde_mm_set_epi32( 657,  222, -709, -177),
      simde_mm_set_ps( 657.00,  222.00, -709.00, -177.00) },
    { simde_mm_set_epi32( 762, -586,  196,  717),
      simde_mm_set_ps( 762.00, -586.00,  196.00,  717.00) },
    { simde_mm_set_epi32( 322,  178,  766, -110),
      simde_mm_set_ps( 322.00,  178.00,  766.00, -110.00) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128 r = simde_mm_cvtepi32_ps(test_vec[i].a);
    simde_assert_m128_f32_equal(r, test_vec[i].r, 1);
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
    { simde_mm_set_pd(  619.07,   892.74),
      simde_mm_set_epi32(   0,    0,  619,  893) },
    { simde_mm_set_pd(  470.31,   660.22),
      simde_mm_set_epi32(   0,    0,  470,  660) },
    { simde_mm_set_pd(  -60.85,  -627.46),
      simde_mm_set_epi32(   0,    0,  -61, -627) },
    { simde_mm_set_pd(  597.08,   713.19),
      simde_mm_set_epi32(   0,    0,  597,  713) },
    { simde_mm_set_pd( -711.34,   677.87),
      simde_mm_set_epi32(   0,    0, -711,  678) },
    { simde_mm_set_pd( -193.79,   610.22),
      simde_mm_set_epi32(   0,    0, -194,  610) },
    { simde_mm_set_pd( -983.22,   418.34),
      simde_mm_set_epi32(   0,    0, -983,  418) },
    { simde_mm_set_pd(  586.10,  -114.71),
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
    { simde_mm_set_pd( -666.48,  -362.59),
      simde_mm_set_pi32(-666, -363) },
    { simde_mm_set_pd(  339.74,  -157.66),
      simde_mm_set_pi32( 340, -158) },
    { simde_mm_set_pd( -938.51,  -421.36),
      simde_mm_set_pi32(-939, -421) },
    { simde_mm_set_pd(   51.73,  -650.75),
      simde_mm_set_pi32(  52, -651) },
    { simde_mm_set_pd(  657.87,  -405.12),
      simde_mm_set_pi32( 658, -405) },
    { simde_mm_set_pd(  690.88,   348.18),
      simde_mm_set_pi32( 691,  348) },
    { simde_mm_set_pd(  574.12,  -708.36),
      simde_mm_set_pi32( 574, -708) },
    { simde_mm_set_pd( -392.27,  -706.05),
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
    { simde_mm_set_pd(  655.71,   689.41),
      simde_mm_set_ps(    0.00,     0.00,   655.71,   689.41) },
    { simde_mm_set_pd(  -50.10,  -149.72),
      simde_mm_set_ps(    0.00,     0.00,   -50.10,  -149.72) },
    { simde_mm_set_pd(  227.42,   655.70),
      simde_mm_set_ps(    0.00,     0.00,   227.42,   655.70) },
    { simde_mm_set_pd( -635.17,   938.65),
      simde_mm_set_ps(    0.00,     0.00,  -635.17,   938.65) },
    { simde_mm_set_pd(  548.99,   -18.53),
      simde_mm_set_ps(    0.00,     0.00,   548.99,   -18.53) },
    { simde_mm_set_pd( -548.71,    31.33),
      simde_mm_set_ps(    0.00,     0.00,  -548.71,    31.33) },
    { simde_mm_set_pd( -978.36,  -341.93),
      simde_mm_set_ps(    0.00,     0.00,  -978.36,  -341.93) },
    { simde_mm_set_pd(  211.73,   471.24),
      simde_mm_set_ps(    0.00,     0.00,   211.73,   471.24) }
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
      simde_mm_set_pd( -42.00, -579.00) },
    { simde_mm_set_pi32( -633,    29),
      simde_mm_set_pd(-633.00,   29.00) },
    { simde_mm_set_pi32( -149,   196),
      simde_mm_set_pd(-149.00,  196.00) },
    { simde_mm_set_pi32(  308,  -433),
      simde_mm_set_pd( 308.00, -433.00) },
    { simde_mm_set_pi32( -881,   358),
      simde_mm_set_pd(-881.00,  358.00) },
    { simde_mm_set_pi32(  723,   273),
      simde_mm_set_pd( 723.00,  273.00) },
    { simde_mm_set_pi32( -182,   457),
      simde_mm_set_pd(-182.00,  457.00) },
    { simde_mm_set_pi32( -239,  -577),
      simde_mm_set_pd(-239.00, -577.00) }
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
    { simde_mm_set_ps(    0.00, -11516.98,  -879.85,  -804.87),
      simde_mm_set_epi32(   0, -11517, -880, -805) },
    { simde_mm_set_ps(    0.00, -11516.98,   -75.52,  -969.73),
      simde_mm_set_epi32(   0, -11517,  -76, -970) },
    { simde_mm_set_ps(    0.00, -11516.98,   469.26,   307.36),
      simde_mm_set_epi32(   0, -11517,  469,  307) },
    { simde_mm_set_ps(    0.00, -11516.98,   953.93,  -612.11),
      simde_mm_set_epi32(   0, -11517,  954, -612) },
    { simde_mm_set_ps(    0.00, -11516.98,  -155.14,  -589.40),
      simde_mm_set_epi32(   0, -11517, -155, -589) },
    { simde_mm_set_ps(    0.00, -11516.98,  -256.28,  -717.85),
      simde_mm_set_epi32(   0, -11517, -256, -718) },
    { simde_mm_set_ps(    0.00, -11516.98,   293.21,  -340.18),
      simde_mm_set_epi32(   0, -11517,  293, -340) },
    { simde_mm_set_ps(    0.00, -11516.98,  -141.85,   -14.16),
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
    { simde_mm_set_ps(  295.41,  -909.65,   156.64,  -802.16),
      simde_mm_set_pd(  156.64,  -802.16) },
    { simde_mm_set_ps(  649.83,  -763.68,   364.80,   389.19),
      simde_mm_set_pd(  364.80,   389.19) },
    { simde_mm_set_ps(  269.92,  -207.13,   538.63,   487.11),
      simde_mm_set_pd(  538.63,   487.11) },
    { simde_mm_set_ps( -982.29,   234.64,   -53.82,   899.43),
      simde_mm_set_pd(  -53.82,   899.43) },
    { simde_mm_set_ps(  945.89,   -98.53,     1.57,    49.07),
      simde_mm_set_pd(    1.57,    49.07) },
    { simde_mm_set_ps(  -47.73,   806.42,    11.76,    -1.19),
      simde_mm_set_pd(   11.76,    -1.19) },
    { simde_mm_set_ps( -961.08,  -192.05,   553.30,  -994.71),
      simde_mm_set_pd(  553.30,  -994.71) },
    { simde_mm_set_ps(    9.30,  -203.20,  -196.20,   707.05),
      simde_mm_set_pd( -196.20,   707.05) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_cvtps_pd(test_vec[i].a);
    simde_assert_m128d_f64_equal(r, test_vec[i].r, 1);
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
    { simde_mm_set_pd(  298.96,    39.67),
      39.67 },
    { simde_mm_set_pd(  -98.64,  -641.95),
      -641.95 },
    { simde_mm_set_pd( -307.30,  -193.04),
      -193.04 },
    { simde_mm_set_pd( -648.72,   830.29),
      830.29 },
    { simde_mm_set_pd( -701.20,  -501.79),
      -501.79 },
    { simde_mm_set_pd(  755.28,   648.10),
      648.10 },
    { simde_mm_set_pd( -664.63,   220.54),
      220.54 },
    { simde_mm_set_pd( -762.92,  -101.29),
      -101.29 }
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
    { simde_mm_set_pd( -786.65,    95.61),   96 },
    { simde_mm_set_pd(  269.52,   731.54),  732 },
    { simde_mm_set_pd(  692.00,   924.73),  925 },
    { simde_mm_set_pd(  482.19,  -585.95), -586 },
    { simde_mm_set_pd( -916.45,     4.54),    5 },
    { simde_mm_set_pd(   -1.98,   865.83),  866 },
    { simde_mm_set_pd(  763.06,   897.97),  898 },
    { simde_mm_set_pd(  320.71,   383.53),  384 }
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
    { simde_mm_set_pd(  793.30,  -706.75), -707 },
    { simde_mm_set_pd(   29.13,  -309.00), -309 },
    { simde_mm_set_pd(   21.24,   368.17),  368 },
    { simde_mm_set_pd( -595.30,   351.60),  352 },
    { simde_mm_set_pd( -640.13,  -466.84), -467 },
    { simde_mm_set_pd( -237.20,  -994.72), -995 },
    { simde_mm_set_pd( -983.23,   645.14),  645 },
    { simde_mm_set_pd(  -89.10,   585.69),  586 }
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
    { simde_mm_set_ps(  522.41,   122.44,   708.76,   910.97),
      simde_mm_set_pd(  -52.04,   228.75),
      simde_mm_set_ps(  522.41,   122.44,   708.76,   228.75) },
    { simde_mm_set_ps( -311.44,   267.00,   965.23,  -248.92),
      simde_mm_set_pd(  -89.48,   178.71),
      simde_mm_set_ps( -311.44,   267.00,   965.23,   178.71) },
    { simde_mm_set_ps(  252.50,   744.35,   237.50,   713.77),
      simde_mm_set_pd( -913.96,   935.45),
      simde_mm_set_ps(  252.50,   744.35,   237.50,   935.45) },
    { simde_mm_set_ps(  781.08,   -50.03,  -658.11,   945.59),
      simde_mm_set_pd( -556.84,   452.90),
      simde_mm_set_ps(  781.08,   -50.03,  -658.11,   452.90) },
    { simde_mm_set_ps(  459.13,   794.72,   105.91,   688.90),
      simde_mm_set_pd( -123.20,   469.36),
      simde_mm_set_ps(  459.13,   794.72,   105.91,   469.36) },
    { simde_mm_set_ps( -699.67,   751.26,    72.14,  -162.03),
      simde_mm_set_pd(  868.66,   138.18),
      simde_mm_set_ps( -699.67,   751.26,    72.14,   138.18) },
    { simde_mm_set_ps( -144.80,   372.44,  -878.31,   984.43),
      simde_mm_set_pd( -559.54,   112.58),
      simde_mm_set_ps( -144.80,   372.44,  -878.31,   112.58) },
    { simde_mm_set_ps( -958.65,   333.33,  -940.30,   396.81),
      simde_mm_set_pd(  263.65,   199.76),
      simde_mm_set_ps( -958.65,   333.33,  -940.30,   199.76) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128 r = simde_mm_cvtsd_ss(test_vec[i].a, test_vec[i].b);
    simde_assert_m128_f64_equal(r, test_vec[i].r, 1);
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
test_simde_mm_cvtsi32_sd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128d a;
    int b;
    simde__m128d r;
  } test_vec[8] = {
    { simde_mm_set_pd( -601.07,   516.34),
      -768,
      simde_mm_set_pd( -601.07,  -768.00) },
    { simde_mm_set_pd( -939.83,   135.41),
      -383,
      simde_mm_set_pd( -939.83,  -383.00) },
    { simde_mm_set_pd(  503.65,   859.44),
       872,
      simde_mm_set_pd(  503.65,   872.00) },
    { simde_mm_set_pd(  -76.44,   854.87),
       613,
      simde_mm_set_pd(  -76.44,   613.00) },
    { simde_mm_set_pd(  520.67,  -993.40),
       197,
      simde_mm_set_pd(  520.67,   197.00) },
    { simde_mm_set_pd(  461.59,  -572.51),
      -157,
      simde_mm_set_pd(  461.59,  -157.00) },
    { simde_mm_set_pd( -113.22,   791.22),
      -840,
      simde_mm_set_pd( -113.22,  -840.00) },
    { simde_mm_set_pd(  707.47,   954.02),
      -347,
      simde_mm_set_pd(  707.47,  -347.00) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_cvtsi32_sd(test_vec[i].a, test_vec[i].b);
    simde_assert_m128d_f64_equal(r, test_vec[i].r, 1);
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
    { simde_mm_set_pd(  229.24,   177.04),  637,
      simde_mm_set_pd(  229.24,   637.00) },
    { simde_mm_set_pd(  401.10,   284.52), -162,
      simde_mm_set_pd(  401.10,  -162.00) },
    { simde_mm_set_pd(  499.46,   321.47), -540,
      simde_mm_set_pd(  499.46,  -540.00) },
    { simde_mm_set_pd( -710.92,   858.14),  -64,
      simde_mm_set_pd( -710.92,   -64.00) },
    { simde_mm_set_pd( -289.27,  -887.54), -238,
      simde_mm_set_pd( -289.27,  -238.00) },
    { simde_mm_set_pd(  865.34,   242.15),  121,
      simde_mm_set_pd(  865.34,   121.00) },
    { simde_mm_set_pd( -376.10,  -965.52),  315,
      simde_mm_set_pd( -376.10,   315.00) },
    { simde_mm_set_pd(  673.51,  -882.88),  -72,
      simde_mm_set_pd(  673.51,   -72.00) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_cvtsi64_sd(test_vec[i].a, test_vec[i].b);
    simde_assert_m128d_f64(r, ==, test_vec[i].r);
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
    { simde_mm_set_pd( 546.48,  729.20),
      simde_mm_set_ps( 142.68,  -75.76, -648.72,  148.36),
      simde_mm_set_pd( 546.48,  148.36) },
    { simde_mm_set_pd(  79.60,  648.49),
      simde_mm_set_ps( 631.34,  902.53,  -54.65,  614.98),
      simde_mm_set_pd(  79.60,  614.98) },
    { simde_mm_set_pd( 811.47,  -95.71),
      simde_mm_set_ps(  13.27,  315.63,  407.80, -826.61),
      simde_mm_set_pd( 811.47, -826.61) },
    { simde_mm_set_pd( 315.42,  -69.06),
      simde_mm_set_ps( 775.15,  935.54, -964.44,  659.62),
      simde_mm_set_pd( 315.42,  659.62) },
    { simde_mm_set_pd(-579.75, -291.65),
      simde_mm_set_ps( 533.61,  565.53,  -36.93,   57.54),
      simde_mm_set_pd(-579.75,   57.54) },
    { simde_mm_set_pd( 979.09, -471.44),
      simde_mm_set_ps( 927.62,  955.93, -964.80,  823.88),
      simde_mm_set_pd( 979.09,  823.88) },
    { simde_mm_set_pd( 172.44, -427.74),
      simde_mm_set_ps(-343.18, -352.03, -836.30,  -61.82),
      simde_mm_set_pd( 172.44,  -61.82) },
    { simde_mm_set_pd( 975.42,  394.72),
      simde_mm_set_ps( 748.90, -410.84,  636.92,  230.31),
      simde_mm_set_pd( 975.42,  230.31) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_cvtss_sd(test_vec[i].a, test_vec[i].b);
    simde_assert_m128d_f64_equal(r, test_vec[i].r, 2);
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
    { simde_mm_set_pd(-804.05,  341.74),
      simde_mm_set_epi32(0, 0, -804,  341) },
    { simde_mm_set_pd( 962.24, -569.72),
      simde_mm_set_epi32(0, 0,  962, -569) },
    { simde_mm_set_pd( 250.89,  802.88),
      simde_mm_set_epi32(0, 0,  250,  802) },
    { simde_mm_set_pd( 810.60, -311.86),
      simde_mm_set_epi32(0, 0,  810, -311) },
    { simde_mm_set_pd(-993.06, -497.38),
      simde_mm_set_epi32(0, 0, -993, -497) },
    { simde_mm_set_pd(  41.80, -969.69),
      simde_mm_set_epi32(0, 0,   41, -969) },
    { simde_mm_set_pd( 550.85,  912.08),
      simde_mm_set_epi32(0, 0,  550,  912) },
    { simde_mm_set_pd( 165.92,  -84.76),
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
    { simde_mm_set_pd( -31.65,  302.59),
      simde_mm_set_pi32( -31,  302) },
    { simde_mm_set_pd(-119.29,  -18.22),
      simde_mm_set_pi32(-119,  -18) },
    { simde_mm_set_pd(-706.80, -266.39),
      simde_mm_set_pi32(-706, -266) },
    { simde_mm_set_pd( 204.37,  451.92),
      simde_mm_set_pi32( 204,  451) },
    { simde_mm_set_pd(-953.22, -488.59),
      simde_mm_set_pi32(-953, -488) },
    { simde_mm_set_pd( 812.77,  -99.24),
      simde_mm_set_pi32( 812,  -99) },
    { simde_mm_set_pd(-532.78, -983.93),
      simde_mm_set_pi32(-532, -983) },
    { simde_mm_set_pd( 864.25, -434.51),
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
    { simde_mm_set_ps(-529.70,  872.16,  247.85,  866.62),
      simde_mm_set_epi32(-529, 872,  247,  866) },
    { simde_mm_set_ps( 543.02, -211.71,  579.48, -807.83),
      simde_mm_set_epi32(543, -211,  579, -807) },
    { simde_mm_set_ps(-740.55,  847.79, -708.61,  883.97),
      simde_mm_set_epi32(-740, 847, -708,  883) },
    { simde_mm_set_ps(-439.93,  682.25, -615.83,  330.85),
      simde_mm_set_epi32(-439, 682, -615,  330) },
    { simde_mm_set_ps( 750.74,  646.41,  456.96, -492.54),
      simde_mm_set_epi32(750, 646,  456, -492) },
    { simde_mm_set_ps(-556.32,  674.09, -481.35,  566.79),
      simde_mm_set_epi32(-556, 674, -481,  566) },
    { simde_mm_set_ps( 753.09,  737.97,  556.48,  999.26),
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
    { simde_mm_set_pd( 598.37,   47.84),   47 },
    { simde_mm_set_pd( 651.65,  630.05),  630 },
    { simde_mm_set_pd(-329.53, -222.72), -222 },
    { simde_mm_set_pd( 472.59,  189.93),  189 },
    { simde_mm_set_pd( 916.43, -342.09), -342 },
    { simde_mm_set_pd( 904.58,   10.13),   10 },
    { simde_mm_set_pd( 841.20,  -18.78),  -18 },
    { simde_mm_set_pd(-895.94, -849.46), -849 }
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
    { simde_mm_set_pd(-345.97,  664.87),  664 },
    { simde_mm_set_pd( 648.27, -390.19), -390 },
    { simde_mm_set_pd(-500.63, -258.15), -258 },
    { simde_mm_set_pd(-109.22, -784.27), -784 },
    { simde_mm_set_pd(-688.79, -698.22), -698 },
    { simde_mm_set_pd(-914.25, -650.88), -650 },
    { simde_mm_set_pd(-228.35, -603.46), -603 },
    { simde_mm_set_pd(-556.94,  694.64),  694 }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    int64_t r = simde_mm_cvttsd_si64(test_vec[i].a);
    munit_assert_int32(r, ==, test_vec[i].r);
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
    { simde_mm_set_pd( -927.67,  -514.32),
      simde_mm_set_pd(  342.71,   927.58),
      simde_mm_set_pd( -927.67,  -514.32) },
    { simde_mm_set_pd( -704.64,   925.40),
      simde_mm_set_pd( -589.60,  -498.63),
      simde_mm_set_pd( -704.64,  -498.63) },
    { simde_mm_set_pd( -244.39,   572.76),
      simde_mm_set_pd(  -10.04,   293.99),
      simde_mm_set_pd( -244.39,   293.99) },
    { simde_mm_set_pd(  321.70,  -283.39),
      simde_mm_set_pd(   60.35,  -248.75),
      simde_mm_set_pd(   60.35,  -283.39) },
    { simde_mm_set_pd(  -67.84,   763.91),
      simde_mm_set_pd(  150.47,  -773.85),
      simde_mm_set_pd(  -67.84,  -773.85) },
    { simde_mm_set_pd(  -42.86,   169.28),
      simde_mm_set_pd( -820.89,   325.20),
      simde_mm_set_pd( -820.89,   169.28) },
    { simde_mm_set_pd( -976.90,   883.11),
      simde_mm_set_pd( -450.39,  -249.21),
      simde_mm_set_pd( -976.90,  -249.21) },
    { simde_mm_set_pd(  495.76,   415.93),
      simde_mm_set_pd( -979.87,  -567.72),
      simde_mm_set_pd( -979.87,  -567.72) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_min_pd(test_vec[i].a, test_vec[i].b);
    simde_assert_m128d_f64_equal(r, test_vec[i].r, 1);
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
    { simde_mm_set_pd( -927.67,  -514.32),
      simde_mm_set_pd(  342.71,   927.58),
      simde_mm_set_pd( -927.67,  -514.32) },
    { simde_mm_set_pd( -704.64,   925.40),
      simde_mm_set_pd( -589.60,  -498.63),
      simde_mm_set_pd( -704.64,  -498.63) },
    { simde_mm_set_pd( -244.39,   572.76),
      simde_mm_set_pd(  -10.04,   293.99),
      simde_mm_set_pd( -244.39,   293.99) },
    { simde_mm_set_pd(  321.70,  -283.39),
      simde_mm_set_pd(   60.35,  -248.75),
      simde_mm_set_pd(  321.70,  -283.39) },
    { simde_mm_set_pd(  -67.84,   763.91),
      simde_mm_set_pd(  150.47,  -773.85),
      simde_mm_set_pd(  -67.84,  -773.85) },
    { simde_mm_set_pd(  -42.86,   169.28),
      simde_mm_set_pd( -820.89,   325.20),
      simde_mm_set_pd(  -42.86,   169.28) },
    { simde_mm_set_pd( -976.90,   883.11),
      simde_mm_set_pd( -450.39,  -249.21),
      simde_mm_set_pd( -976.90,  -249.21) },
    { simde_mm_set_pd(  495.76,   415.93),
      simde_mm_set_pd( -979.87,  -567.72),
      simde_mm_set_pd(  495.76,  -567.72) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_min_sd(test_vec[i].a, test_vec[i].b);
    simde_assert_m128d_f64_equal(r, test_vec[i].r, 1);
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
    { simde_mm_set_pd( -303.58,  -480.90),
      simde_mm_set_pd(  319.11,   666.53),
      simde_mm_set_pd(  319.11,   666.53) },
    { simde_mm_set_pd( -541.77,   944.47),
      simde_mm_set_pd(  -53.88,   845.28),
      simde_mm_set_pd(  -53.88,   944.47) },
    { simde_mm_set_pd( -612.90,  -610.67),
      simde_mm_set_pd(  230.96,  -372.57),
      simde_mm_set_pd(  230.96,  -372.57) },
    { simde_mm_set_pd( -791.37,   840.72),
      simde_mm_set_pd( -365.40,  -868.73),
      simde_mm_set_pd( -365.40,   840.72) },
    { simde_mm_set_pd(  169.29,   679.66),
      simde_mm_set_pd(  -57.82,   810.96),
      simde_mm_set_pd(  169.29,   810.96) },
    { simde_mm_set_pd(  713.62,   124.72),
      simde_mm_set_pd( -297.75,   146.63),
      simde_mm_set_pd(  713.62,   146.63) },
    { simde_mm_set_pd(  -67.07,  -514.59),
      simde_mm_set_pd(  577.06,  -935.01),
      simde_mm_set_pd(  577.06,  -514.59) },
    { simde_mm_set_pd(  342.23,   198.10),
      simde_mm_set_pd( -401.56,  -707.36),
      simde_mm_set_pd(  342.23,   198.10) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_max_pd(test_vec[i].a, test_vec[i].b);
    simde_assert_m128d_f64_equal(r, test_vec[i].r, 1);
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
    { simde_mm_set_pd( -303.58,  -480.90),
      simde_mm_set_pd(  319.11,   666.53),
      simde_mm_set_pd( -303.58,   666.53) },
    { simde_mm_set_pd( -541.77,   944.47),
      simde_mm_set_pd(  -53.88,   845.28),
      simde_mm_set_pd( -541.77,   944.47) },
    { simde_mm_set_pd( -612.90,  -610.67),
      simde_mm_set_pd(  230.96,  -372.57),
      simde_mm_set_pd( -612.90,  -372.57) },
    { simde_mm_set_pd( -791.37,   840.72),
      simde_mm_set_pd( -365.40,  -868.73),
      simde_mm_set_pd( -791.37,   840.72) },
    { simde_mm_set_pd(  169.29,   679.66),
      simde_mm_set_pd(  -57.82,   810.96),
      simde_mm_set_pd(  169.29,   810.96) },
    { simde_mm_set_pd(  713.62,   124.72),
      simde_mm_set_pd( -297.75,   146.63),
      simde_mm_set_pd(  713.62,   146.63) },
    { simde_mm_set_pd(  -67.07,  -514.59),
      simde_mm_set_pd(  577.06,  -935.01),
      simde_mm_set_pd(  -67.07,  -514.59) },
    { simde_mm_set_pd(  342.23,   198.10),
      simde_mm_set_pd( -401.56,  -707.36),
      simde_mm_set_pd(  342.23,   198.10) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_max_sd(test_vec[i].a, test_vec[i].b);
    simde_assert_m128d_f64_equal(r, test_vec[i].r, 1);
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
    { simde_mm_set_pd(    602.19,    -103.53),
      simde_mm_set_pd(   -952.79,    -150.84),
      simde_mm_set_pd(-573760.61,   15616.47) },
    { simde_mm_set_pd(   -140.84,    -241.95),
      simde_mm_set_pd(    540.86,    -754.39),
      simde_mm_set_pd( -76174.72,  182524.66) },
    { simde_mm_set_pd(   -648.21,    -612.11),
      simde_mm_set_pd(   -327.08,    -865.34),
      simde_mm_set_pd( 212016.53,  529683.27) },
    { simde_mm_set_pd(    518.61,    -573.43),
      simde_mm_set_pd(   -650.79,     196.03),
      simde_mm_set_pd(-337506.20, -112409.48) },
    { simde_mm_set_pd(   -750.40,     324.63),
      simde_mm_set_pd(    343.74,      -4.14),
      simde_mm_set_pd(-257942.50,   -1343.97) },
    { simde_mm_set_pd(    -48.73,     769.19),
      simde_mm_set_pd(    268.16,    -953.46),
      simde_mm_set_pd( -13067.44, -733391.90) },
    { simde_mm_set_pd(    188.02,     614.87),
      simde_mm_set_pd(    396.91,    -399.68),
      simde_mm_set_pd(  74627.02, -245751.24) },
    { simde_mm_set_pd(    813.52,     480.96),
      simde_mm_set_pd(    664.31,     447.07),
      simde_mm_set_pd( 540429.47,  215022.79) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_mul_pd(test_vec[i].a, test_vec[i].b);
    simde_assert_m128d_f64_close(r, test_vec[i].r, 1);
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
    { simde_mm_set_pd(    815.66,     839.23),
      simde_mm_set_pd(    748.66,     -52.12),
      simde_mm_set_pd(    815.66,  -43740.67) },
    { simde_mm_set_pd(   -714.36,    -808.00),
      simde_mm_set_pd(    401.75,     319.13),
      simde_mm_set_pd(   -714.36, -257857.04) },
    { simde_mm_set_pd(    453.36,    -764.44),
      simde_mm_set_pd(   -934.41,    -454.88),
      simde_mm_set_pd(    453.36,  347728.47) },
    { simde_mm_set_pd(    489.60,     724.31),
      simde_mm_set_pd(   -101.25,     196.93),
      simde_mm_set_pd(    489.60,  142638.37) },
    { simde_mm_set_pd(    187.03,     665.07),
      simde_mm_set_pd(    487.15,     851.16),
      simde_mm_set_pd(    187.03,  566080.98) },
    { simde_mm_set_pd(    589.48,     648.27),
      simde_mm_set_pd(   -683.48,     -59.67),
      simde_mm_set_pd(    589.48,  -38682.27) },
    { simde_mm_set_pd(    838.61,     822.18),
      simde_mm_set_pd(   -364.43,     962.26),
      simde_mm_set_pd(    838.61,  791150.93) },
    { simde_mm_set_pd(    530.83,     379.76),
      simde_mm_set_pd(     27.92,     -56.09),
      simde_mm_set_pd(    530.83,  -21300.74) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_mul_sd(test_vec[i].a, test_vec[i].b);
    simde_assert_m128d_f64_close(r, test_vec[i].r, 1);
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
    simde_float64 e1, e0;
    simde__m128d r;

    e0 = random_f64_range(-1000.0, 1000.0);
    e1 = random_f64_range(-1000.0, 1000.0);
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
    simde_float64 a;
    simde__m128d r;

    a = random_f64_range(-1000.0, 1000.0);
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

    a = random_f64_range(-1000.0, 1000.0);
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
test_simde_mm_sra_epi32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m128i count;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi32(-1401500752,  1421016087, -1798399636,  -218944829),
      simde_mm_set_epi32(          3,           4,          14,          13),
      simde_mm_set_epi32(         -1,           0,          -1,          -1) },
    { simde_mm_set_epi32(-1301672349, -1257788466,  1299081562, -2081916956),
      simde_mm_set_epi32(          5,           0,          28,          28),
      simde_mm_set_epi32(         -1,          -1,           0,          -1) },
    { simde_mm_set_epi32(  486412899,  1710025226, -1708639681,   179026170),
      simde_mm_set_epi32(          8,          27,           7,          28),
      simde_mm_set_epi32(          0,           0,          -1,           0) },
    { simde_mm_set_epi32(  611228560,  1089473069,  -348396556,  1221615457),
      simde_mm_set_epi32(         22,          10,          31,          13),
      simde_mm_set_epi32(          0,           0,          -1,           0) },
    { simde_mm_set_epi32(-1397263422,   364817906,   -61765119,   893503448),
      simde_mm_set_epi32(          7,          26,          26,           9),
      simde_mm_set_epi32(         -1,           0,          -1,           0) },
    { simde_mm_set_epi32( -809986849,   -41634974,  2083198151,  -832824649),
      simde_mm_set_epi32(         26,          28,           3,          28),
      simde_mm_set_epi32(         -1,          -1,           0,          -1) },
    { simde_mm_set_epi32(-1514242199,  1925959405, -1844305920,   423301368),
      simde_mm_set_epi32(          9,          11,          26,           3),
      simde_mm_set_epi32(         -1,           0,          -1,           0) },
    { simde_mm_set_epi32( 1189234358,  1471344312,  2129964179,   228172545),
      simde_mm_set_epi32(         15,          22,          29,          13),
      simde_mm_set_epi32(          0,           0,           0,           0) }
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
    int count;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi32(-1131934153,  1564906572, -1819251842,  2113577502),
      6,
      simde_mm_set_epi32(  -17686472,    24451665,   -28425811,    33024648) },
    { simde_mm_set_epi32( 1898762691, -1673929561,  -363852881, -1016088778),
      25,
      simde_mm_set_epi32(         56,         -50,         -11,         -31) },
    { simde_mm_set_epi32(-1661480117, -1741629978,  1726631387, -1146598010),
      15,
      simde_mm_set_epi32(     -50705,      -53151,       52692,      -34992) },
    { simde_mm_set_epi32( 1786148983,   684894373,  1599659581, -1871135081),
      11,
      simde_mm_set_epi32(     872143,      334421,      781083,     -913641) },
    { simde_mm_set_epi32( -970339319,  1644341516,   150378618, -1952528595),
      25,
      simde_mm_set_epi32(        -29,          49,           4,         -59) },
    { simde_mm_set_epi32(-2135894572,  -293347256,  -925174046,  1577624957),
      27,
      simde_mm_set_epi32(        -16,          -3,          -7,          11) },
    { simde_mm_set_epi32(-1521729654,  2089690706, -1865503124,  1738035635),
      18,
      simde_mm_set_epi32(      -5805,        7971,       -7117,        6630) },
    { simde_mm_set_epi32( 1496299243,   260013912,  -621752978,   -20875751),
      6,
      simde_mm_set_epi32(   23379675,     4062717,    -9714891,     -326184) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_srai_epi32(test_vec[i].a, test_vec[i].count);
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
    simde__m128i r = simde_mm_srli_epi64(test_vec[i].a, 7);
    simde_assert_m128i_i32(r, ==, test_vec[i].r);
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
    simde_assert_m128_i32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_store_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128d a;
    simde_float64 SIMDE__ALIGN(16) r[2];
  } test_vec[8] = {
    { simde_mm_set_pd(  825.31,   176.75),
      {   176.75,   825.31 } },
    { simde_mm_set_pd( -248.58,  -171.93),
      {  -171.93,  -248.58 } },
    { simde_mm_set_pd(  419.77,   712.85),
      {   712.85,   419.77 } },
    { simde_mm_set_pd(  785.55,    78.74),
      {    78.74,   785.55 } },
    { simde_mm_set_pd( -963.92,   614.28),
      {   614.28,  -963.92 } },
    { simde_mm_set_pd(  624.62,  -260.28),
      {  -260.28,   624.62 } },
    { simde_mm_set_pd( -178.24,   945.12),
      {   945.12,  -178.24 } },
    { simde_mm_set_pd( -271.60,  -674.20),
      {  -674.20,  -271.60 } }
  };

  for (size_t i = 0 ; i < sizeof(test_vec) / sizeof(test_vec[0]) ; i++) {
    simde_float64 SIMDE__ALIGN(16) r[2];
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
    simde_float64 SIMDE__ALIGN(16) r[2];
  } test_vec[8] = {
    { simde_mm_set_pd(  278.50,   554.87),
      {   554.87,   554.87 } },
    { simde_mm_set_pd( -348.28,   361.13),
      {   361.13,   361.13 } },
    { simde_mm_set_pd( -701.38,   708.23),
      {   708.23,   708.23 } },
    { simde_mm_set_pd( -362.77,  -574.16),
      {  -574.16,  -574.16 } },
    { simde_mm_set_pd(  420.63,   850.70),
      {   850.70,   850.70 } },
    { simde_mm_set_pd( -223.78,   845.58),
      {   845.58,   845.58 } },
    { simde_mm_set_pd(  948.70,   544.62),
      {   544.62,   544.62 } },
    { simde_mm_set_pd( -216.79,  -830.24),
      {  -830.24,  -830.24 } }
  };

  for (size_t i = 0 ; i < sizeof(test_vec) / sizeof(test_vec[0]) ; i++) {
    simde_float64 SIMDE__ALIGN(16) r[2];
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
    simde_float64 SIMDE__ALIGN(16) b[2];
    simde_float64 SIMDE__ALIGN(16) r[2];
  } test_vec[8] = {
    { simde_mm_set_pd( -380.32,   589.10),
      {  -886.38,   706.27 },
      {   589.10,   706.27 } },
    { simde_mm_set_pd(   97.55,  -921.93),
      {   175.08,  -498.43 },
      {  -921.93,  -498.43 } },
    { simde_mm_set_pd( -962.76,  -267.73),
      {  -505.37,  -729.92 },
      {  -267.73,  -729.92 } },
    { simde_mm_set_pd(  154.59,  -829.83),
      {   141.33,   657.26 },
      {  -829.83,   657.26 } },
    { simde_mm_set_pd( -623.49,  -306.50),
      {  -540.89,   213.61 },
      {  -306.50,   213.61 } },
    { simde_mm_set_pd(  708.57,  -626.05),
      {  -658.64,   310.68 },
      {  -626.05,   310.68 } },
    { simde_mm_set_pd(    7.10,    84.59),
      {   191.88,  -258.06 },
      {    84.59,  -258.06 } },
    { simde_mm_set_pd(  399.99,  -337.50),
      {   733.91,  -756.49 },
      {  -337.50,  -756.49 } }
  };

  for (size_t i = 0 ; i < sizeof(test_vec) / sizeof(test_vec[0]) ; i++) {
    simde_float64 SIMDE__ALIGN(16) r[2];
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
    simde_assert_m128_i32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_storeh_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128d a;
    simde_float64 SIMDE__ALIGN(16) b[2];
    simde_float64 SIMDE__ALIGN(16) r[2];
  } test_vec[8] = {
    { simde_mm_set_pd( -154.79,   689.59),
      {  -986.30,  -463.82 },
      {  -154.79,  -463.82 } },
    { simde_mm_set_pd(  944.07,  -598.47),
      {  -514.42,   652.02 },
      {   944.07,   652.02 } },
    { simde_mm_set_pd(  -34.72,  -771.52),
      {   343.91,  -171.75 },
      {   -34.72,  -171.75 } },
    { simde_mm_set_pd(  305.40,  -671.87),
      {  -579.65,  -985.37 },
      {   305.40,  -985.37 } },
    { simde_mm_set_pd(  173.51,   643.06),
      {   794.84,   233.08 },
      {   173.51,   233.08 } },
    { simde_mm_set_pd( -130.21,  -290.59),
      {   584.05,  -167.57 },
      {  -130.21,  -167.57 } },
    { simde_mm_set_pd( -759.48,   428.70),
      {    36.98,  -189.97 },
      {  -759.48,  -189.97 } },
    { simde_mm_set_pd(  222.49,   621.71),
      {  -467.95,  -910.73 },
      {   222.49,  -910.73 } }
  };

  for (size_t i = 0 ; i < sizeof(test_vec) / sizeof(test_vec[0]) ; i++) {
    simde_float64 SIMDE__ALIGN(16) r[2];
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
    { simde_mm_set_epi64x(UINT64_C(-8572402204481175152), UINT64_C(-3565447379630862345)),
      simde_mm_set_epi64x(UINT64_C(-5836787758646654491), UINT64_C(  978262207997446536)),
      simde_mm_set_epi64x(UINT64_C(-5836787758646654491), UINT64_C(-3565447379630862345)) },
    { simde_mm_set_epi64x(UINT64_C(  883894259135204982), UINT64_C(-6785295924552521928)),
      simde_mm_set_epi64x(UINT64_C( 5751908210058630765), UINT64_C(-7999305285706001942)),
      simde_mm_set_epi64x(UINT64_C( 5751908210058630765), UINT64_C(-6785295924552521928)) },
    { simde_mm_set_epi64x(UINT64_C( 4991496111910955453), UINT64_C(-1947231678451890517)),
      simde_mm_set_epi64x(UINT64_C( 1054715717267865334), UINT64_C(-5199938312574175167)),
      simde_mm_set_epi64x(UINT64_C( 1054715717267865334), UINT64_C(-1947231678451890517)) },
    { simde_mm_set_epi64x(UINT64_C(-6916286228894702079), UINT64_C(-7888320918323423602)),
      simde_mm_set_epi64x(UINT64_C(-4560271213984560857), UINT64_C( 1030486561279856923)),
      simde_mm_set_epi64x(UINT64_C(-4560271213984560857), UINT64_C(-7888320918323423602)) },
    { simde_mm_set_epi64x(UINT64_C(-5516402797122916761), UINT64_C( 8516393373254709766)),
      simde_mm_set_epi64x(UINT64_C(-8984432431227422893), UINT64_C(-1285772213781786319)),
      simde_mm_set_epi64x(UINT64_C(-8984432431227422893), UINT64_C( 8516393373254709766)) },
    { simde_mm_set_epi64x(UINT64_C( 1537881028582424966), UINT64_C( 3855597324285413517)),
      simde_mm_set_epi64x(UINT64_C(-1087659369158402202), UINT64_C( 5504181592152866903)),
      simde_mm_set_epi64x(UINT64_C(-1087659369158402202), UINT64_C( 3855597324285413517)) },
    { simde_mm_set_epi64x(UINT64_C(-1003754336566127903), UINT64_C( 3155788073225494266)),
      simde_mm_set_epi64x(UINT64_C( 7014294951579480267), UINT64_C(-6777837266490471507)),
      simde_mm_set_epi64x(UINT64_C( 7014294951579480267), UINT64_C( 3155788073225494266)) },
    { simde_mm_set_epi64x(UINT64_C( 7343239871058385173), UINT64_C(-8089093160963830084)),
      simde_mm_set_epi64x(UINT64_C(-7180996141698966448), UINT64_C( 1747758344108352756)),
      simde_mm_set_epi64x(UINT64_C(-7180996141698966448), UINT64_C(-8089093160963830084)) }
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
    simde_float64 SIMDE__ALIGN(16) b[2];
    simde_float64 SIMDE__ALIGN(16) r[2];
  } test_vec[8] = {
    { simde_mm_set_pd( -887.08,  -520.70),
      {  -258.49,   913.00 },
      {  -520.70,   913.00 } },
    { simde_mm_set_pd(  724.04,  -774.49),
      {   557.37,  -701.13 },
      {  -774.49,  -701.13 } },
    { simde_mm_set_pd( -366.90,  -168.25),
      {   485.14,   500.94 },
      {  -168.25,   500.94 } },
    { simde_mm_set_pd( -783.51,  -187.73),
      {  -391.92,  -506.74 },
      {  -187.73,  -506.74 } },
    { simde_mm_set_pd(  -50.27,  -405.84),
      {  -733.12,  -697.37 },
      {  -405.84,  -697.37 } },
    { simde_mm_set_pd( -773.31,  -470.65),
      {   738.01,  -908.23 },
      {  -470.65,  -908.23 } },
    { simde_mm_set_pd(  -43.07,  -143.29),
      {   985.95,    19.70 },
      {  -143.29,    19.70 } },
    { simde_mm_set_pd(  649.59,  -925.70),
      {   519.96,   348.23 },
      {  -925.70,   348.23 } }
  };

  for (size_t i = 0 ; i < sizeof(test_vec) / sizeof(test_vec[0]) ; i++) {
    simde_float64 SIMDE__ALIGN(16) r[2];
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
    simde_float64 SIMDE__ALIGN(16) b[2];
    simde_float64 SIMDE__ALIGN(16) r[2];
  } test_vec[8] = {
    { simde_mm_set_pd( -545.91,  -446.91),
      {   394.90,    50.99 },
      {  -446.91,    50.99 } },
    { simde_mm_set_pd( -455.77,   343.77),
      {  -201.79,   875.74 },
      {   343.77,   875.74 } },
    { simde_mm_set_pd( -712.05,   234.43),
      {   113.05,   472.67 },
      {   234.43,   472.67 } },
    { simde_mm_set_pd( -620.78,   681.36),
      {  -571.78,   503.32 },
      {   681.36,   503.32 } },
    { simde_mm_set_pd( -831.20,  -553.90),
      {   838.66,   971.27 },
      {  -553.90,   971.27 } },
    { simde_mm_set_pd(    7.58,  -572.44),
      {  -637.44,  -242.31 },
      {  -572.44,  -242.31 } },
    { simde_mm_set_pd( -569.19,   -40.53),
      {   496.41,    97.51 },
      {   -40.53,    97.51 } },
    { simde_mm_set_pd(  166.32,  -555.89),
      {  -518.44,   926.00 },
      {  -555.89,   926.00 } }
  };

  for (size_t i = 0 ; i < sizeof(test_vec) / sizeof(test_vec[0]) ; i++) {
    simde_float64 SIMDE__ALIGN(16) r[2];
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
    simde_float64 SIMDE__ALIGN(16) b[2];
    simde_float64 SIMDE__ALIGN(16) r[2];
  } test_vec[8] = {
    { simde_mm_set_pd( -545.91,  -446.91),
      {   394.90,    50.99 },
      {  -446.91,    50.99 } },
    { simde_mm_set_pd( -455.77,   343.77),
      {  -201.79,   875.74 },
      {   343.77,   875.74 } },
    { simde_mm_set_pd( -712.05,   234.43),
      {   113.05,   472.67 },
      {   234.43,   472.67 } },
    { simde_mm_set_pd( -620.78,   681.36),
      {  -571.78,   503.32 },
      {   681.36,   503.32 } },
    { simde_mm_set_pd( -831.20,  -553.90),
      {   838.66,   971.27 },
      {  -553.90,   971.27 } },
    { simde_mm_set_pd(    7.58,  -572.44),
      {  -637.44,  -242.31 },
      {  -572.44,  -242.31 } },
    { simde_mm_set_pd( -569.19,   -40.53),
      {   496.41,    97.51 },
      {   -40.53,    97.51 } },
    { simde_mm_set_pd(  166.32,  -555.89),
      {  -518.44,   926.00 },
      {  -555.89,   926.00 } }
  };

  for (size_t i = 0 ; i < sizeof(test_vec) / sizeof(test_vec[0]) ; i++) {
    simde_float64 SIMDE__ALIGN(16) r[2];
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
    { simde_mm_set_epi64x(UINT64_C(-5763845342482697816), UINT64_C( 2103077785434280804)),
      simde_mm_set_epi64x(UINT64_C(  -84933559585222060), UINT64_C(-2626653918467514964)),
      simde_mm_set_epi64x(UINT64_C(-5678911782897475756), UINT64_C( 4729731703901795768)) },
    { simde_mm_set_epi64x(UINT64_C( 1527789798480118137), UINT64_C( 8436112421047310932)),
      simde_mm_set_epi64x(UINT64_C(-1700732467797798250), UINT64_C(-3973336518996013340)),
      simde_mm_set_epi64x(UINT64_C( 3228522266277916387), UINT64_C(-6037295133666227344)) },
    { simde_mm_set_epi64x(UINT64_C( 4851345631989659335), UINT64_C(-7206764788471565568)),
      simde_mm_set_epi64x(UINT64_C( 5406657072094052149), UINT64_C( 1553917979932899417)),
      simde_mm_set_epi64x(UINT64_C( -555311440104392814), UINT64_C(-8760682768404464985)) },
    { simde_mm_set_epi64x(UINT64_C( 4880585840903485916), UINT64_C(-3214111508108965857)),
      simde_mm_set_epi64x(UINT64_C(-9030069389987018552), UINT64_C(-3395779442469856546)),
      simde_mm_set_epi64x(UINT64_C(-4536088842819047148), UINT64_C(  181667934360890689)) },
    { simde_mm_set_epi64x(UINT64_C( 5848110560047382754), UINT64_C( 5491947693722128435)),
      simde_mm_set_epi64x(UINT64_C(  213782131019667117), UINT64_C( -937970910639813333)),
      simde_mm_set_epi64x(UINT64_C( 5634328429027715637), UINT64_C( 6429918604361941768)) },
    { simde_mm_set_epi64x(UINT64_C(-1470278109522038956), UINT64_C(-7185464081677005028)),
      simde_mm_set_epi64x(UINT64_C( 7512013344600346304), UINT64_C(-1151368750409397152)),
      simde_mm_set_epi64x(UINT64_C(-8982291454122385260), UINT64_C(-6034095331267607876)) },
    { simde_mm_set_epi64x(UINT64_C(-1414880571892272072), UINT64_C(-5464559564131319132)),
      simde_mm_set_epi64x(UINT64_C(-8460263392275774431), UINT64_C( 3444946385257741717)),
      simde_mm_set_epi64x(UINT64_C( 7045382820383502359), UINT64_C(-8909505949389060849)) },
    { simde_mm_set_epi64x(UINT64_C( 2041037654020608990), UINT64_C(-5135476174064773616)),
      simde_mm_set_epi64x(UINT64_C(-2250411574230731306), UINT64_C( 6301008926808412830)),
      simde_mm_set_epi64x(UINT64_C( 4291449228251340296), UINT64_C( 7010258972836365170)) }
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
    { simde_mm_set_pd( -989.09,   415.70),
      simde_mm_set_pd( -630.71,   755.53),
      simde_mm_set_pd( -358.38,  -339.83) },
    { simde_mm_set_pd( -609.69,  -266.09),
      simde_mm_set_pd(  904.74,   704.00),
      simde_mm_set_pd(-1514.43,  -970.09) },
    { simde_mm_set_pd( -864.69,  -728.75),
      simde_mm_set_pd( -549.96,   478.05),
      simde_mm_set_pd( -314.73, -1206.80) },
    { simde_mm_set_pd( -607.45,  -593.32),
      simde_mm_set_pd( -648.70,  -195.04),
      simde_mm_set_pd(   41.24,  -398.28) },
    { simde_mm_set_pd( -442.58,  -296.11),
      simde_mm_set_pd(  195.46,   287.25),
      simde_mm_set_pd( -638.04,  -583.37) },
    { simde_mm_set_pd( -930.71,   996.22),
      simde_mm_set_pd( -786.74,    77.74),
      simde_mm_set_pd( -143.98,   918.47) },
    { simde_mm_set_pd(  702.75,   -28.87),
      simde_mm_set_pd(  970.37,  -443.97),
      simde_mm_set_pd( -267.62,   415.10) },
    { simde_mm_set_pd( -369.79,   539.64),
      simde_mm_set_pd( -404.57,  -587.93),
      simde_mm_set_pd(   34.78,  1127.56) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_sub_pd(test_vec[i].a, test_vec[i].b);
    simde_assert_m128d_f64_equal(r, test_vec[i].r, 1);
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
    { simde_mm_set_pd( -989.09,   415.70),
      simde_mm_set_pd( -630.71,   755.53),
      simde_mm_set_pd( -989.09,  -339.83) },
    { simde_mm_set_pd( -609.69,  -266.09),
      simde_mm_set_pd(  904.74,   704.00),
      simde_mm_set_pd( -609.69,  -970.09) },
    { simde_mm_set_pd( -864.69,  -728.75),
      simde_mm_set_pd( -549.96,   478.05),
      simde_mm_set_pd( -864.69, -1206.80) },
    { simde_mm_set_pd( -607.45,  -593.32),
      simde_mm_set_pd( -648.70,  -195.04),
      simde_mm_set_pd( -607.45,  -398.28) },
    { simde_mm_set_pd( -442.58,  -296.11),
      simde_mm_set_pd(  195.46,   287.25),
      simde_mm_set_pd( -442.58,  -583.37) },
    { simde_mm_set_pd( -930.71,   996.22),
      simde_mm_set_pd( -786.74,    77.74),
      simde_mm_set_pd( -930.71,   918.47) },
    { simde_mm_set_pd(  702.75,   -28.87),
      simde_mm_set_pd(  970.37,  -443.97),
      simde_mm_set_pd(  702.75,   415.10) },
    { simde_mm_set_pd( -369.79,   539.64),
      simde_mm_set_pd( -404.57,  -587.93),
      simde_mm_set_pd( -369.79,  1127.56) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_sub_sd(test_vec[i].a, test_vec[i].b);
    simde_assert_m128d_f64_equal(r, test_vec[i].r, 1);
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
    { simde_mm_cvtsi64_m64(UINT64_C(  -40015113898169895)),
      simde_mm_cvtsi64_m64(UINT64_C( 3843942487505240466)),
      simde_mm_cvtsi64_m64(UINT64_C(-3883957601403410361)), },
    { simde_mm_cvtsi64_m64(UINT64_C( 8317116700671824816)),
      simde_mm_cvtsi64_m64(UINT64_C( 2891842609034633421)),
      simde_mm_cvtsi64_m64(UINT64_C( 5425274091637191395)), },
    { simde_mm_cvtsi64_m64(UINT64_C(  922042182678065366)),
      simde_mm_cvtsi64_m64(UINT64_C( 4937799652981992213)),
      simde_mm_cvtsi64_m64(UINT64_C(-4015757470303926847)), },
    { simde_mm_cvtsi64_m64(UINT64_C(  297526191920431793)),
      simde_mm_cvtsi64_m64(UINT64_C(-8568639315346032946)),
      simde_mm_cvtsi64_m64(UINT64_C( 8866165507266464739)), },
    { simde_mm_cvtsi64_m64(UINT64_C(  944913740190663659)),
      simde_mm_cvtsi64_m64(UINT64_C(-5569388163200780530)),
      simde_mm_cvtsi64_m64(UINT64_C( 6514301903391444189)), },
    { simde_mm_cvtsi64_m64(UINT64_C( 2756927115722410076)),
      simde_mm_cvtsi64_m64(UINT64_C( 1302679549898517242)),
      simde_mm_cvtsi64_m64(UINT64_C( 1454247565823892834)), },
    { simde_mm_cvtsi64_m64(UINT64_C(  977005230827305840)),
      simde_mm_cvtsi64_m64(UINT64_C( 4908563834369883454)),
      simde_mm_cvtsi64_m64(UINT64_C(-3931558603542577614)), },
    { simde_mm_cvtsi64_m64(UINT64_C(-7062092201406124762)),
      simde_mm_cvtsi64_m64(UINT64_C( 2377066878085823882)),
      simde_mm_cvtsi64_m64(UINT64_C( 9007584994217602972)), }
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
    { simde_mm_set_epi8(  77,  -15,  -74,   52,  -61,   64,   59,   21,
                         -60,  -67,  -73,  104,   30,  107,   83, -117),
      simde_mm_set_epi8(-110, -112,  -53,   89,   74,   81,  -22,  -97,
                        -128,  -54,  101,   96,   36,   87, -125,   28),
      simde_mm_set_epi8( 127,   97,  -21,  -37, -128,  -17,   81,  118,
                          68,  -13, -128,    8,   -6,   20,  127, -128) },
    { simde_mm_set_epi8(  57,   79,  101,   47,   60,   12,    0,  -19,
                          63,   39, -108,   37,   92,  114, -110,   91),
      simde_mm_set_epi8( -59,  -81,   49,  126,   33,  120, -127,   80,
                         109, -100,   21, -125,    7,   60, -122,  -61),
      simde_mm_set_epi8( 116,  127,   52,  -79,   27, -108,  127,  -99,
                         -46,  127, -128,  127,   85,   54,   12,  127) },
    { simde_mm_set_epi8(  84, -104,  -82,  105,  -43,  -36,   16,  -15,
                         -34,  120, -110,   90,   78,   45, -124,  -84),
      simde_mm_set_epi8( -66,   -1,   91,   74,   83,  -91,  -97,  115,
                         -29,   67,  -98,  -51,  110,  -43,  125,   63),
      simde_mm_set_epi8( 127, -103, -128,   31, -126,   55,  113, -128,
                          -5,   53,  -12,  127,  -32,   88, -128, -128) },
    { simde_mm_set_epi8( -75,   37,  126,   21,   92, -124,  -81,   -6,
                        -117,  -14,   38,  -68,  -45,  114,   32,  -13),
      simde_mm_set_epi8(  80, -123,  -25,   71, -108,  -31,   98,  -67,
                         -23, -112,  -42,  -16,  -56,  107,    6,   16),
      simde_mm_set_epi8(-128,  127,  127,  -50,  127,  -93, -128,   61,
                         -94,   98,   80,  -52,   11,    7,   26,  -29) },
    { simde_mm_set_epi8(  85,   18,   15,  100,  107,  -69,  -96,  -20,
                         -18,   42,   98,  104,  -70, -121,  -91,   77),
      simde_mm_set_epi8( 103,  -62,  107, -125,  -86, -112,  -45,    3,
                         -26,   96,   83,   23,  100,  127,  -56,  -52),
      simde_mm_set_epi8( -18,   80,  -92,  127,  127,   43,  -51,  -23,
                           8,  -54,   15,   81, -128, -128,  -35,  127) },
    { simde_mm_set_epi8(  63,   16,  100,  -10,   78,  116,  -91,   21,
                         -10,  -27,  -92,   31,  -23,  -53,   -1,   -1),
      simde_mm_set_epi8(  20, -123,   36,  -10,  127, -111,  -60,   54,
                          92,  101,  -13,  -31, -124,  112, -118,  -29),
      simde_mm_set_epi8(  43,  127,   64,    0,  -49,  127,  -31,  -33,
                        -102, -128,  -79,   62,  101, -128,  117,   28) },
    { simde_mm_set_epi8(   1,  -28,  -45,  -32, -103,   27,  -38, -127,
                         -89,  -74,   47,   91,   46,  -24,   60,   23),
      simde_mm_set_epi8( -25,  -68, -116,   92,   33,   -5,  -35,  -44,
                          -9,  -90,   63,  108,   36,   27,  112,  -11),
      simde_mm_set_epi8(  26,   40,   71, -124, -128,   32,   -3,  -83,
                         -80,   16,  -16,  -17,   10,  -51,  -52,   34) },
    { simde_mm_set_epi8(  29,  123,   -8,  -35,    3,  -97,  124, -121,
                          52,   75,  -93, -127,  -78,   87,  102,  119),
      simde_mm_set_epi8(  51,  -89,   -6,    8,  -19,  -88,   22,   21,
                         -37,  -42,  -97,   58,   70,  -92, -100, -124),
      simde_mm_set_epi8( -22,  127,   -2,  -43,   22,   -9,  102, -128,
                          89,  117,    4, -128, -128,  127,  127,  127) }
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
  { (char*) "/mm_add_si64",      test_simde_mm_add_si64,      NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
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
  { (char*) "/mm_slli_epi16",    test_simde_mm_slli_epi16,    NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_slli_epi32",    test_simde_mm_slli_epi32,    NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_slli_epi64",    test_simde_mm_slli_epi64,    NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_srli_epi16",    test_simde_mm_srli_epi16,    NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_srli_epi32",    test_simde_mm_srli_epi32,    NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_srli_epi64",    test_simde_mm_srli_epi64,    NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_srli_si128",    test_simde_mm_srli_si128,    NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },

  { (char*) "/mm_sra_epi16",     test_simde_mm_sra_epi16,     NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_sra_epi32",     test_simde_mm_sra_epi32,     NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_srai_epi16",    test_simde_mm_srai_epi16,    NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_srai_epi32",    test_simde_mm_srai_epi32,    NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },

  { (char*) "/mm_store_pd",      test_simde_mm_store_pd,      NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_store_pd1",     test_simde_mm_store_pd1,     NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_store_sd",      test_simde_mm_store_sd,      NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_store_si128",   test_simde_mm_store_si128,   NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_storeh_pd",     test_simde_mm_storeh_pd,     NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_storel_epi64",  test_simde_mm_storel_epi64,  NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_storel_pd",     test_simde_mm_storel_pd,     NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_storer_pd",     test_simde_mm_storer_pd,     NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_storeu_pd",     test_simde_mm_storeu_pd,     NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_storeu_si128",  test_simde_mm_storeu_si128,  NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },

  { (char*) "/mm_sub_epi8",      test_simde_mm_sub_epi8,      NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_sub_epi16",     test_simde_mm_sub_epi16,     NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_sub_epi32",     test_simde_mm_sub_epi32,     NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_sub_epi64",     test_simde_mm_sub_epi64,     NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_sub_pd",        test_simde_mm_sub_pd,        NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_sub_sd",        test_simde_mm_sub_sd,        NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_sub_si64",      test_simde_mm_sub_si64,      NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_subs_epi8",     test_simde_mm_subs_epi8,     NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_subs_epi16",    test_simde_mm_subs_epi16,    NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_subs_epu8",     test_simde_mm_subs_epu8,     NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_subs_epu16",    test_simde_mm_subs_epu16,    NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },

  { (char*) "/mm_min_epu8",      test_simde_mm_min_epu8,      NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_min_epi16",     test_simde_mm_min_epi16,     NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_min_pd",        test_simde_mm_min_pd,        NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_min_sd",        test_simde_mm_min_sd,        NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_max_epu8",      test_simde_mm_max_epu8,      NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_max_epi16",     test_simde_mm_max_epi16,     NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_max_pd",        test_simde_mm_max_pd,        NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_max_sd",        test_simde_mm_max_sd,        NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },

  { (char*) "/mm_mul_epu32",     test_simde_mm_mul_epu32,     NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_mul_pd",        test_simde_mm_mul_pd,        NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_mul_sd",        test_simde_mm_mul_sd,        NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_mul_su32",      test_simde_mm_mul_su32,      NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_mulhi_epi16",   test_simde_mm_mulhi_epi16,   NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_mulhi_epu16",   test_simde_mm_mulhi_epu16,   NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_mullo_epi16",   test_simde_mm_mullo_epi16,   NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },

  { (char*) "/mm_cmpeq_epi8",    test_simde_mm_cmpeq_epi8,    NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_cmpeq_epi16",   test_simde_mm_cmpeq_epi16,   NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_cmpeq_epi32",   test_simde_mm_cmpeq_epi32,   NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_cmpeq_pd",      test_simde_mm_cmpeq_pd,      NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_cmpeq_sd",      test_simde_mm_cmpeq_sd,      NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_cmpneq_pd",     test_simde_mm_cmpneq_pd,     NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_cmpneq_sd",     test_simde_mm_cmpneq_sd,     NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_cmplt_epi8",    test_simde_mm_cmplt_epi8,    NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_cmplt_epi16",   test_simde_mm_cmplt_epi16,   NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_cmplt_epi32",   test_simde_mm_cmplt_epi32,   NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_cmplt_pd",      test_simde_mm_cmplt_pd,      NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_cmplt_sd",      test_simde_mm_cmplt_sd,      NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_cmpnlt_pd",     test_simde_mm_cmpnlt_pd,     NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_cmpnlt_sd",     test_simde_mm_cmpnlt_sd,     NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_cmple_pd",      test_simde_mm_cmple_pd,      NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_cmple_sd",      test_simde_mm_cmple_sd,      NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_cmpnle_pd",     test_simde_mm_cmpnle_pd,     NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_cmpnle_sd",     test_simde_mm_cmpnle_sd,     NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_cmpgt_epi8",    test_simde_mm_cmpgt_epi8,    NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_cmpgt_epi16",   test_simde_mm_cmpgt_epi16,   NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_cmpgt_epi32",   test_simde_mm_cmpgt_epi32,   NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_cmpgt_pd",      test_simde_mm_cmpgt_pd,      NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_cmpgt_sd",      test_simde_mm_cmpgt_sd,      NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_cmpge_pd",      test_simde_mm_cmpge_pd,      NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_cmpge_sd",      test_simde_mm_cmpge_sd,      NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_cmpnge_pd",     test_simde_mm_cmpnge_pd,     NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_cmpnge_sd",     test_simde_mm_cmpnge_sd,     NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_cmpord_pd",     test_simde_mm_cmpord_pd,     NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_cmpord_sd",     test_simde_mm_cmpord_sd,     NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_cmpunord_pd",   test_simde_mm_cmpunord_pd,   NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_cmpunord_sd",   test_simde_mm_cmpunord_sd,   NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },

  { (char*) "/mm_cvtepi32_pd",   test_simde_mm_cvtepi32_pd,   NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_cvtepi32_ps",   test_simde_mm_cvtepi32_ps,   NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_cvtpd_epi32",   test_simde_mm_cvtpd_epi32,   NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_cvtpd_pi32",    test_simde_mm_cvtpd_pi32,    NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_cvtpd_ps",      test_simde_mm_cvtpd_ps,      NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_cvtpi32_pd",    test_simde_mm_cvtpi32_pd,    NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_cvtps_epi32",   test_simde_mm_cvtps_epi32,   NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_cvtps_pd",      test_simde_mm_cvtps_pd,      NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_cvtsd_f64",     test_simde_mm_cvtsd_f64,     NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_cvtsd_si32",    test_simde_mm_cvtsd_si32,    NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_cvtsd_si64",    test_simde_mm_cvtsd_si64,    NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_cvtsd_ss",      test_simde_mm_cvtsd_ss,      NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_cvtsi128_si32", test_simde_mm_cvtsi128_si32, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_cvtsi128_si64", test_simde_mm_cvtsi128_si64, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_cvtsi32_sd",    test_simde_mm_cvtsi32_sd,    NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_cvtsi32_si128", test_simde_mm_cvtsi32_si128, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_cvtsi64_sd",    test_simde_mm_cvtsi64_sd,    NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_cvtsi64_si128", test_simde_mm_cvtsi64_si128, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_cvtss_sd",      test_simde_mm_cvtss_sd,      NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_cvttpd_epi32",  test_simde_mm_cvttpd_epi32,  NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_cvttpd_pi32",   test_simde_mm_cvttpd_pi32,   NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_cvttps_epi32",  test_simde_mm_cvttps_epi32,  NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_cvttsd_si32",   test_simde_mm_cvttsd_si32,   NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_cvttsd_si64",   test_simde_mm_cvttsd_si64,   NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },

  { (char*) "/mm_loadu_si128",   test_simde_mm_loadu_si128,   NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_madd_epi16",    test_simde_mm_madd_epi16,    NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_movemask_epi8", test_simde_mm_movemask_epi8, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_or_si128",      test_simde_mm_or_si128,      NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },

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
