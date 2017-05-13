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
#include "../sse4.1.h"

#include <stdio.h>

static MunitResult
test_simde_mm_blendv_epi8(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i mask;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi8(0x34, 0xa7, 0x72, 0x78, 0x4b, 0xd1, 0x7a, 0xcf,
			0x2c, 0xe8, 0x66, 0x94, 0x48, 0xcc, 0xde, 0xee),
      simde_mm_set_epi8(0xc0, 0x9e, 0xe2, 0x5d, 0x63, 0xfb, 0x66, 0x2e,
			0x7b, 0x82, 0x71, 0x9e, 0xc8, 0x5c, 0x91, 0x46),
      simde_mm_set_epi8(0x05, 0xe4, 0x69, 0x00, 0x89, 0x60, 0xce, 0x3c,
			0x07, 0xc2, 0xe1, 0x5b, 0xb6, 0xb0, 0x01, 0x25),
      simde_mm_set_epi8(0x34, 0x9e, 0x72, 0x78, 0x63, 0xd1, 0x66, 0xcf,
			0x2c, 0x82, 0x71, 0x94, 0xc8, 0x5c, 0xde, 0xee) },
    { simde_mm_set_epi8(0xf2, 0x28, 0xce, 0x53, 0x90, 0xff, 0xa6, 0xa0,
			0x48, 0x5d, 0x95, 0x88, 0xe1, 0xee, 0x0b, 0x76),
      simde_mm_set_epi8(0xe6, 0x5d, 0xfc, 0x7b, 0x53, 0xa8, 0xe1, 0xf5,
			0x51, 0xa3, 0x9a, 0x18, 0xb3, 0x58, 0x71, 0xb1),
      simde_mm_set_epi8(0xea, 0x82, 0xe3, 0xcc, 0xb9, 0xab, 0x5a, 0x79,
			0x5c, 0x8a, 0x20, 0xef, 0xc9, 0xa7, 0x9e, 0x2f),
      simde_mm_set_epi8(0xe6, 0x5d, 0xfc, 0x7b, 0x53, 0xa8, 0xa6, 0xa0,
			0x48, 0xa3, 0x95, 0x18, 0xb3, 0x58, 0x71, 0x76) },
    { simde_mm_set_epi8(0x81, 0x28, 0xa8, 0x5c, 0xf7, 0xf4, 0xb6, 0xde,
			0xe2, 0xdb, 0xae, 0x81, 0x17, 0x13, 0x7f, 0xfb),
      simde_mm_set_epi8(0xfe, 0xbe, 0xbd, 0xee, 0xf8, 0x16, 0x29, 0x13,
			0x5b, 0xf2, 0xbe, 0x81, 0xb2, 0xa7, 0xa7, 0x55),
      simde_mm_set_epi8(0x0f, 0xaa, 0xef, 0x52, 0xee, 0xd2, 0x15, 0x92,
			0xda, 0xbb, 0xbb, 0x13, 0x8d, 0x7c, 0xed, 0x33),
      simde_mm_set_epi8(0x81, 0xbe, 0xbd, 0x5c, 0xf8, 0x16, 0xb6, 0x13,
			0x5b, 0xf2, 0xbe, 0x81, 0xb2, 0x13, 0xa7, 0xfb) },
    { simde_mm_set_epi8(0xa5, 0xde, 0x6f, 0xb2, 0x26, 0x2d, 0x47, 0x80,
			0xa7, 0xc0, 0xe5, 0xd1, 0x32, 0x11, 0xe4, 0xbf),
      simde_mm_set_epi8(0x46, 0xea, 0x2b, 0x73, 0x22, 0x24, 0xd5, 0x98,
			0x6d, 0x43, 0x61, 0x56, 0xd7, 0x78, 0x3f, 0x31),
      simde_mm_set_epi8(0x7c, 0x3a, 0x72, 0xe8, 0xcb, 0xdd, 0xf7, 0x2f,
			0xec, 0xda, 0xde, 0x92, 0x03, 0x4f, 0x41, 0x28),
      simde_mm_set_epi8(0xa5, 0xde, 0x6f, 0x73, 0x22, 0x24, 0xd5, 0x80,
			0x6d, 0x43, 0x61, 0x56, 0x32, 0x11, 0xe4, 0xbf) },
    { simde_mm_set_epi8(0xff, 0x4a, 0x0a, 0xab, 0x07, 0xc7, 0xb4, 0xe5,
			0x87, 0x46, 0xda, 0x67, 0x3b, 0x8b, 0x87, 0x16),
      simde_mm_set_epi8(0x45, 0xbd, 0x48, 0x02, 0xe3, 0xb7, 0xf1, 0x58,
			0x1b, 0xeb, 0x79, 0xd8, 0xaf, 0xa5, 0x6c, 0xde),
      simde_mm_set_epi8(0xd5, 0x47, 0xb2, 0xcb, 0x9c, 0xab, 0xc6, 0x76,
			0xe2, 0xc7, 0x30, 0x73, 0xfd, 0xf3, 0x83, 0x6a),
      simde_mm_set_epi8(0x45, 0x4a, 0x48, 0x02, 0xe3, 0xb7, 0xf1, 0xe5,
			0x1b, 0xeb, 0xda, 0x67, 0xaf, 0xa5, 0x6c, 0x16) },
    { simde_mm_set_epi8(0x39, 0xac, 0xc7, 0x31, 0x0e, 0xfe, 0xcd, 0x12,
			0x88, 0x73, 0x6c, 0x17, 0x4f, 0xaa, 0x02, 0xb1),
      simde_mm_set_epi8(0xee, 0xf3, 0x2a, 0xca, 0x08, 0x82, 0xe3, 0x0f,
			0xbc, 0x36, 0x8b, 0x32, 0x3d, 0x59, 0x6e, 0x13),
      simde_mm_set_epi8(0xa4, 0xb2, 0x1d, 0x5a, 0x1a, 0x32, 0x2e, 0x13,
			0xaf, 0xbc, 0xf3, 0x77, 0x19, 0xdc, 0xf7, 0x91),
      simde_mm_set_epi8(0xee, 0xf3, 0xc7, 0x31, 0x0e, 0xfe, 0xcd, 0x12,
			0xbc, 0x36, 0x8b, 0x17, 0x4f, 0x59, 0x6e, 0x13) },
    { simde_mm_set_epi8(0xc4, 0x5d, 0x16, 0xa8, 0x7c, 0x7b, 0x67, 0x40,
			0xa1, 0x74, 0x44, 0x65, 0x7e, 0xdc, 0x16, 0x01),
      simde_mm_set_epi8(0x02, 0xfb, 0xea, 0xd6, 0x7b, 0xa1, 0x89, 0xda,
			0x60, 0x2c, 0x2b, 0x22, 0x47, 0x99, 0xd0, 0xe7),
      simde_mm_set_epi8(0x36, 0xa1, 0x88, 0x6a, 0x2f, 0x6b, 0x06, 0x25,
			0x80, 0x98, 0x95, 0x84, 0x70, 0x95, 0xfe, 0xa6),
      simde_mm_set_epi8(0xc4, 0xfb, 0xea, 0xa8, 0x7c, 0x7b, 0x67, 0x40,
			0x60, 0x2c, 0x2b, 0x22, 0x7e, 0x99, 0xd0, 0xe7) },
    { simde_mm_set_epi8(0x21, 0x0c, 0x28, 0x62, 0x77, 0x32, 0xd2, 0x1f,
			0x9a, 0xa9, 0x93, 0xc5, 0xdb, 0x6b, 0x13, 0xef),
      simde_mm_set_epi8(0xa5, 0x7d, 0x8b, 0x2e, 0xb4, 0xb5, 0x8a, 0x37,
			0x25, 0xda, 0xec, 0x21, 0x7e, 0x89, 0x6a, 0x11),
      simde_mm_set_epi8(0x0f, 0x46, 0x0a, 0x7d, 0xdb, 0xd5, 0x8d, 0xfe,
			0x4e, 0x54, 0x03, 0x67, 0x13, 0xc5, 0x25, 0x19),
      simde_mm_set_epi8(0x21, 0x0c, 0x28, 0x62, 0xb4, 0xb5, 0x8a, 0x37,
			0x9a, 0xa9, 0x93, 0xc5, 0xdb, 0x89, 0x13, 0xef) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_blendv_epi8(test_vec[i].a, test_vec[i].b, test_vec[i].mask);
    simde_assert_m128_i8(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_cvtepi16_epi32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi16(-15854,      0, -12807,   5951,  29318, -11078,  -2252,  10096),
      simde_mm_set_epi32( 29318, -11078,  -2252,  10096) },
    { simde_mm_set_epi16( 24388,  32521, -30980, -12289,  27092,  24521,  12106, -27709),
      simde_mm_set_epi32( 27092,  24521,  12106, -27709) },
    { simde_mm_set_epi16(-11871,  15750,  -7986,   4594,  22346,   1400, -21386,   7662),
      simde_mm_set_epi32( 22346,   1400, -21386,   7662) },
    { simde_mm_set_epi16(-15687, -15477, -26077, -28781, -29737, -30311,  16950,  14614),
      simde_mm_set_epi32(-29737, -30311,  16950,  14614) },
    { simde_mm_set_epi16(-30646,  13049, -24166,    637,   7297,   -627,   6143, -26200),
      simde_mm_set_epi32(  7297,   -627,   6143, -26200) },
    { simde_mm_set_epi16( 30171,   1922,   -122, -17991,  30806,  12552, -28515,  -9185),
      simde_mm_set_epi32( 30806,  12552, -28515,  -9185) },
    { simde_mm_set_epi16( 29385,  21267, -10152,  25553,  20674,   6661, -29222, -19848),
      simde_mm_set_epi32( 20674,   6661, -29222, -19848) },
    { simde_mm_set_epi16( 24527,  18305,  30094,  -5437, -26652,  20361,  10408,  -4948),
      simde_mm_set_epi32(-26652,  20361,  10408,  -4948) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_cvtepi16_epi32(test_vec[i].a);
    simde_assert_m128i_i32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_cvtepu8_epi32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m128i r;
  } test_vec[8] = {
    { simde_x_mm_set_epu8(216,  58,  77, 216, 179, 254,  83,  42,
                          179, 211,  84, 116, 211, 142,  19, 247),
      simde_mm_set_epi32(211, 142,  19, 247) },
    { simde_x_mm_set_epu8(161,  70,  71,  24,  62,  44,  28,  40,
                           34, 181, 114,  59,  33, 122,  68, 198),
      simde_mm_set_epi32( 33, 122,  68, 198) },
    { simde_x_mm_set_epu8(145, 160,  60, 140,  53, 127,  68, 235,
                          225, 143, 244,  79,  20,  67, 173, 209),
      simde_mm_set_epi32( 20,  67, 173, 209) },
    { simde_x_mm_set_epu8(117, 146, 120,  54, 143, 242, 141, 149,
                           73,  58,  87,  32, 199, 183, 202,  12),
      simde_mm_set_epi32(199, 183, 202,  12) },
    { simde_x_mm_set_epu8( 40,  57,  16,  79, 103, 249, 143, 197,
                          214,  78, 201,  95,  85,  53, 247, 134),
      simde_mm_set_epi32( 85,  53, 247, 134) },
    { simde_x_mm_set_epu8( 72, 163, 211, 103, 152, 114,   2, 140,
                           52,  64,   1,   9, 184, 145, 190, 245),
      simde_mm_set_epi32(184, 145, 190, 245) },
    { simde_x_mm_set_epu8(  7,  28, 147,   3,  70,  73, 159,  19,
                          118, 122, 100,  52, 236,  17, 135, 121),
      simde_mm_set_epi32(236,  17, 135, 121) },
    { simde_x_mm_set_epu8(100, 233, 199,  97, 158, 240, 121, 115,
                          142, 146, 159, 107, 202, 224, 156, 149),
      simde_mm_set_epi32(202, 224, 156, 149) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_cvtepu8_epi32(test_vec[i].a);
    simde_assert_m128i_i32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_extract_epi64(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    int64_t r;
  } test_vec[8] = {
    { simde_mm_set_epi64x(UINT64_C(0x2d6953577f6833d6), UINT64_C(0x16f735ecbef74fb0)),
      UINT64_C(0x2d6953577f6833d6) },
    { simde_mm_set_epi64x(UINT64_C(0xaaf04de6a347535b), UINT64_C(0x7788e3823cf2dd88)),
      UINT64_C(0xaaf04de6a347535b) },
    { simde_mm_set_epi64x(UINT64_C(0xac0b5ad60a8ae313), UINT64_C(0xd8ff1f0e49d5732f)),
      UINT64_C(0xac0b5ad60a8ae313) },
    { simde_mm_set_epi64x(UINT64_C(0x14a013af8adde846), UINT64_C(0x94084d3fce3dc16a)),
      UINT64_C(0x14a013af8adde846) },
    { simde_mm_set_epi64x(UINT64_C(0xbbdc18f6133d616c), UINT64_C(0xaf38bb2c8ccea04d)),
      UINT64_C(0xbbdc18f6133d616c) },
    { simde_mm_set_epi64x(UINT64_C(0xe54cff88e2d2bf95), UINT64_C(0xb26d52ff06ed52cc)),
      UINT64_C(0xe54cff88e2d2bf95) },
    { simde_mm_set_epi64x(UINT64_C(0xcf0c1539d8ce6a60), UINT64_C(0x3f166cf969999ecb)),
      UINT64_C(0xcf0c1539d8ce6a60) },
    { simde_mm_set_epi64x(UINT64_C(0x54fa14fce453dab2), UINT64_C(0x192a2e66cbd255b7)),
      UINT64_C(0x54fa14fce453dab2) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    int64_t r = simde_mm_extract_epi64(test_vec[i].a, 1);
    munit_assert_int64(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_max_epi8(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi8( -83,   29,    3,   84,   22,   -7,  112, -107,
                         -53, -125,  -41,  -27, -118,   43,   44,   16),
      simde_mm_set_epi8( -80,  -52,   93,   71,   45,  -99,  -14,  -97,
                          11,   62,  111,   17, -108,   -6,   95,    1),
      simde_mm_set_epi8( -80,   29,   93,   84,   45,   -7,  112,  -97,
                          11,   62,  111,   17, -108,   43,   95,   16) },
    { simde_mm_set_epi8(  61, -100,   79,   19,  -86,  116,  -34,   96,
                          70,  -48,  -13,  103, -107,   79,   24,  -71),
      simde_mm_set_epi8(  39,  -53, -117,   65,  -55,   21,   49,  -22,
                         118,  -71, -113,    2,  -83,  -74,  -11,   85),
      simde_mm_set_epi8(  61,  -53,   79,   65,  -55,  116,   49,   96,
                         118,  -48,  -13,  103,  -83,   79,   24,   85) },
    { simde_mm_set_epi8( -13, -124, -110,   22, -109,  127,  -45,  -62,
                           0,   51,  -98,  -11,  -54,  -75, -101, -109),
      simde_mm_set_epi8( -28, -120,   90,  -89,  -72,   93,  -68, -105,
                          39,   46,    2,    5,   16,   34,  -99,   64),
      simde_mm_set_epi8( -13, -120,   90,   22,  -72,  127,  -45,  -62,
                          39,   51,    2,    5,   16,   34,  -99,   64) },
    { simde_mm_set_epi8( -43, -102,  111,   97,  -69,  104,  -24,   -6,
                          29,   43,   65,   47,  -60,   52,    2,  -40),
      simde_mm_set_epi8(  -7,   85,  -63,   48, -117,   19,   99,   67,
                         -50, -116,    5,    2,  -96,  125,  -95,    0),
      simde_mm_set_epi8(  -7,   85,  111,   97,  -69,  104,   99,   67,
                          29,   43,   65,   47,  -60,  125,    2,    0) },
    { simde_mm_set_epi8(  98,   -7,  -56,    9,   74,   50,  -95,  127,
                         114,  118,  -76,  110,  -48,  -50,   57,  -47),
      simde_mm_set_epi8(  47,  -82,   66,  -76,    6,  117,   80,  -13,
                          80, -109,  126,   70,   60,   40,  -54,    3),
      simde_mm_set_epi8(  98,   -7,   66,    9,   74,  117,   80,  127,
                         114,  118,  126,  110,   60,   40,   57,    3) },
    { simde_mm_set_epi8( -80,  -39,  113,  -58,   58,  -88,   22,  -99,
                         112,  -21,   44,  -31,   -2,  109,   19,  -74),
      simde_mm_set_epi8(  71,  -38,   47,  -92,    8,   48,  105,  -82,
                          35,   54,   25,   36,  111,   -7,  -12,  -75),
      simde_mm_set_epi8(  71,  -38,  113,  -58,   58,   48,  105,  -82,
                         112,   54,   44,   36,  111,  109,   19,  -74) },
    { simde_mm_set_epi8(  18,  -41,  -74,   60,  -63,  -55,  -71,  118,
                          46,  -19,   19,   -7,  -55,  -75,  125,  -82),
      simde_mm_set_epi8(-125, -106, -127,  -23,  -63,    0,   56,  -23,
                         -34,  -32,   33,  127,   39,  -68, -103,  126),
      simde_mm_set_epi8(  18,  -41,  -74,   60,  -63,    0,   56,  118,
                          46,  -19,   33,  127,   39,  -68,  125,  126) },
    { simde_mm_set_epi8( -90,  -81,   72,  -34,  -85,  108,   42,   34,
                         -79,  -48,    3,  113,  -62,   25,  -74,   13),
      simde_mm_set_epi8( -44,  -22,   26,  -52,   29,   96,  -97,   88,
                         -11, -125,  -60,   88,  -55,   40,   76,  -80),
      simde_mm_set_epi8( -44,  -22,   72,  -34,   29,  108,   42,   88,
                         -11,  -48,    3,  113,  -55,   40,   76,   13) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_max_epi8(test_vec[i].a, test_vec[i].b);
    simde_assert_m128i_i8(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_max_epi32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi32(UINT32_C(  477039853), UINT32_C( 1555162887), UINT32_C(  960008067), UINT32_C(-2078514865)),
      simde_mm_set_epi32(UINT32_C( -346254872), UINT32_C(   70690131), UINT32_C( -249580279), UINT32_C( -297974983)),
      simde_mm_set_epi32(UINT32_C(  477039853), UINT32_C( 1555162887), UINT32_C(  960008067), UINT32_C( -297974983)) },
    { simde_mm_set_epi32(UINT32_C( 1946076095), UINT32_C( 1626099315), UINT32_C(  367020053), UINT32_C( -768900730)),
      simde_mm_set_epi32(UINT32_C( -534331032), UINT32_C(-1542646073), UINT32_C(  900332023), UINT32_C( 1625404528)),
      simde_mm_set_epi32(UINT32_C( 1946076095), UINT32_C( 1626099315), UINT32_C(  900332023), UINT32_C( 1625404528)) },
    { simde_mm_set_epi32(UINT32_C( 1785938855), UINT32_C(  217054136), UINT32_C(    6277613), UINT32_C( 1323071612)),
      simde_mm_set_epi32(UINT32_C(-1842447194), UINT32_C( 1202045241), UINT32_C(  391997517), UINT32_C(  904511960)),
      simde_mm_set_epi32(UINT32_C( 1785938855), UINT32_C( 1202045241), UINT32_C(  391997517), UINT32_C( 1323071612)) },
    { simde_mm_set_epi32(UINT32_C( -303416903), UINT32_C(  131247622), UINT32_C(-2038528381), UINT32_C(-1774779832)),
      simde_mm_set_epi32(UINT32_C(  307942484), UINT32_C(-1408988466), UINT32_C(-1799017519), UINT32_C( 1885804693)),
      simde_mm_set_epi32(UINT32_C(  307942484), UINT32_C(  131247622), UINT32_C(-1799017519), UINT32_C( 1885804693)) },
    { simde_mm_set_epi32(UINT32_C( -424176665), UINT32_C(  531131808), UINT32_C( -752351935), UINT32_C(  650848232)),
      simde_mm_set_epi32(UINT32_C(-1513144536), UINT32_C( -875213417), UINT32_C(-1592044131), UINT32_C(-1714853090)),
      simde_mm_set_epi32(UINT32_C( -424176665), UINT32_C(  531131808), UINT32_C( -752351935), UINT32_C(  650848232)) },
    { simde_mm_set_epi32(UINT32_C( 1901471013), UINT32_C(-1928782687), UINT32_C(-1204237637), UINT32_C(-1735607658)),
      simde_mm_set_epi32(UINT32_C( 1526238167), UINT32_C( 1155872155), UINT32_C( -981128645), UINT32_C(-1655952235)),
      simde_mm_set_epi32(UINT32_C( 1901471013), UINT32_C( 1155872155), UINT32_C( -981128645), UINT32_C(-1655952235)) },
    { simde_mm_set_epi32(UINT32_C( 2067002242), UINT32_C( -967820279), UINT32_C(-1842332164), UINT32_C( 1466140749)),
      simde_mm_set_epi32(UINT32_C(  -25857443), UINT32_C(-1417095277), UINT32_C(  -31302876), UINT32_C(-1114441571)),
      simde_mm_set_epi32(UINT32_C( 2067002242), UINT32_C( -967820279), UINT32_C(  -31302876), UINT32_C( 1466140749)) },
    { simde_mm_set_epi32(UINT32_C( -515864750), UINT32_C( 1885657427), UINT32_C(-1627411585), UINT32_C( -455970760)),
      simde_mm_set_epi32(UINT32_C( -505553594), UINT32_C(-1363391302), UINT32_C( 1929235496), UINT32_C(-1212934452)),
      simde_mm_set_epi32(UINT32_C( -505553594), UINT32_C( 1885657427), UINT32_C( 1929235496), UINT32_C( -455970760)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_max_epi32(test_vec[i].a, test_vec[i].b);
    simde_assert_m128i_i32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_min_epi8(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi8(0xc9, 0xe9, 0x1f, 0x97, 0x87, 0x04, 0x80, 0x76,
			0x20, 0x62, 0xfb, 0x67, 0xc7, 0x9f, 0x8e, 0x0a),
      simde_mm_set_epi8(0xef, 0xdf, 0xe2, 0x1c, 0x8f, 0x43, 0xea, 0xb3,
			0xd0, 0xea, 0xbc, 0x1b, 0xea, 0x65, 0x20, 0x4c),
      simde_mm_set_epi8(0xc9, 0xdf, 0xe2, 0x97, 0x87, 0x04, 0x80, 0xb3,
			0xd0, 0xea, 0xbc, 0x1b, 0xc7, 0x9f, 0x8e, 0x0a) },
    { simde_mm_set_epi8(0xbc, 0x1a, 0xeb, 0xda, 0xa2, 0x25, 0x2b, 0x11,
			0xf0, 0x01, 0x7a, 0x88, 0x94, 0x03, 0x15, 0x05),
      simde_mm_set_epi8(0xb7, 0x9d, 0x0c, 0x35, 0x77, 0xa0, 0x46, 0x04,
			0xf3, 0x23, 0x08, 0xfc, 0x74, 0xb7, 0x81, 0xda),
      simde_mm_set_epi8(0xb7, 0x9d, 0xeb, 0xda, 0xa2, 0xa0, 0x2b, 0x04,
			0xf0, 0x01, 0x08, 0x88, 0x94, 0xb7, 0x81, 0xda) },
    { simde_mm_set_epi8(0x06, 0x59, 0x0c, 0x14, 0x01, 0x4f, 0x09, 0x5e,
			0x2d, 0xd8, 0x7d, 0x71, 0x02, 0xfa, 0x49, 0xaa),
      simde_mm_set_epi8(0xb1, 0xe8, 0xc9, 0x61, 0xcf, 0x61, 0x79, 0x6e,
			0x2c, 0xa6, 0x8b, 0x75, 0x95, 0xf4, 0xf3, 0x4b),
      simde_mm_set_epi8(0xb1, 0xe8, 0xc9, 0x14, 0xcf, 0x4f, 0x09, 0x5e,
			0x2c, 0xa6, 0x8b, 0x71, 0x95, 0xf4, 0xf3, 0xaa) },
    { simde_mm_set_epi8(0x97, 0x70, 0x9c, 0xb5, 0x18, 0x1f, 0x25, 0x8c,
			0xa8, 0x3e, 0xac, 0xc3, 0x96, 0x7b, 0xf4, 0x55),
      simde_mm_set_epi8(0x16, 0x4c, 0x0e, 0x4f, 0x75, 0xca, 0xbb, 0x3e,
			0x5f, 0x88, 0x96, 0x85, 0x48, 0xb8, 0xe1, 0xb5),
      simde_mm_set_epi8(0x97, 0x4c, 0x9c, 0xb5, 0x18, 0xca, 0xbb, 0x8c,
			0xa8, 0x88, 0x96, 0x85, 0x96, 0xb8, 0xe1, 0xb5) },
    { simde_mm_set_epi8(0x80, 0x42, 0x86, 0x16, 0xf0, 0xf2, 0x2e, 0x22,
			0xba, 0xd2, 0x26, 0xc1, 0x99, 0x1b, 0x32, 0xc9),
      simde_mm_set_epi8(0xf6, 0x93, 0x6c, 0x52, 0x4f, 0xff, 0xad, 0x24,
			0x04, 0xa7, 0x1e, 0xcc, 0x2c, 0x12, 0x32, 0x89),
      simde_mm_set_epi8(0x80, 0x93, 0x86, 0x16, 0xf0, 0xf2, 0xad, 0x22,
			0xba, 0xa7, 0x1e, 0xc1, 0x99, 0x12, 0x32, 0x89) },
    { simde_mm_set_epi8(0xa7, 0x80, 0x20, 0x27, 0x69, 0xfb, 0x1b, 0x03,
			0x57, 0xa8, 0x5f, 0x8b, 0x6a, 0x80, 0x38, 0x01),
      simde_mm_set_epi8(0x5b, 0xd3, 0x0e, 0x20, 0x4f, 0x0a, 0x58, 0x80,
			0xc2, 0x8b, 0x21, 0x13, 0x84, 0xf8, 0x01, 0xaf),
      simde_mm_set_epi8(0xa7, 0x80, 0x0e, 0x20, 0x4f, 0xfb, 0x1b, 0x80,
			0xc2, 0x8b, 0x21, 0x8b, 0x84, 0x80, 0x01, 0xaf) },
    { simde_mm_set_epi8(0x51, 0xed, 0xd3, 0xe0, 0x1d, 0x69, 0x38, 0xee,
			0x5b, 0xdc, 0x73, 0x98, 0xe6, 0x7a, 0x00, 0x88),
      simde_mm_set_epi8(0x9e, 0x8c, 0xcc, 0x07, 0x5b, 0x77, 0x11, 0xb1,
			0x7d, 0x99, 0x04, 0x3c, 0xc8, 0xce, 0xd2, 0x9f),
      simde_mm_set_epi8(0x9e, 0x8c, 0xcc, 0xe0, 0x1d, 0x69, 0x11, 0xb1,
			0x5b, 0x99, 0x04, 0x98, 0xc8, 0xce, 0xd2, 0x88) },
    { simde_mm_set_epi8(0xc3, 0xbd, 0x40, 0x28, 0x91, 0x09, 0x85, 0xdd,
			0x89, 0x9d, 0xc7, 0xaa, 0x61, 0xa4, 0x00, 0x31),
      simde_mm_set_epi8(0xcf, 0xe5, 0xdb, 0xbd, 0x87, 0x0f, 0x0b, 0xe6,
			0x98, 0x78, 0x38, 0xa3, 0x22, 0xb8, 0xe3, 0x59),
      simde_mm_set_epi8(0xc3, 0xbd, 0xdb, 0xbd, 0x87, 0x09, 0x85, 0xdd,
			0x89, 0x9d, 0xc7, 0xa3, 0x22, 0xa4, 0xe3, 0x31) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_min_epi8(test_vec[i].a, test_vec[i].b);
    simde_assert_m128_i8(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_min_epi32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi32(UINT32_C(-1390607532), UINT32_C(  385446037), UINT32_C( -880551963), UINT32_C(-1976882160)),
      simde_mm_set_epi32(UINT32_C(-1328784057), UINT32_C(  765325983), UINT32_C(  188641041), UINT32_C(-1795531007)),
      simde_mm_set_epi32(UINT32_C(-1390607532), UINT32_C(  385446037), UINT32_C( -880551963), UINT32_C(-1976882160)) },
    { simde_mm_set_epi32(UINT32_C( 1033654035), UINT32_C(-1435181472), UINT32_C( 1188098919), UINT32_C(-1789978439)),
      simde_mm_set_epi32(UINT32_C(  667650881), UINT32_C( -921357846), UINT32_C( 1991872258), UINT32_C(-1380518571)),
      simde_mm_set_epi32(UINT32_C(  667650881), UINT32_C(-1435181472), UINT32_C( 1188098919), UINT32_C(-1789978439)) },
    { simde_mm_set_epi32(UINT32_C( -209415658), UINT32_C(-1820339262), UINT32_C(    3383029), UINT32_C( -894067821)),
      simde_mm_set_epi32(UINT32_C( -460825945), UINT32_C(-1201816425), UINT32_C(  657326597), UINT32_C(  270703936)),
      simde_mm_set_epi32(UINT32_C( -460825945), UINT32_C(-1820339262), UINT32_C(    3383029), UINT32_C( -894067821)) },
    { simde_mm_set_epi32(UINT32_C( -711299231), UINT32_C(-1150752518), UINT32_C(  489373999), UINT32_C(-1003224360)),
      simde_mm_set_epi32(UINT32_C( -111820496), UINT32_C(-1961663677), UINT32_C( -829684478), UINT32_C(-1602379520)),
      simde_mm_set_epi32(UINT32_C( -711299231), UINT32_C(-1961663677), UINT32_C( -829684478), UINT32_C(-1602379520)) },
    { simde_mm_set_epi32(UINT32_C( 1660536841), UINT32_C( 1244832127), UINT32_C( 1920382062), UINT32_C( -791791151)),
      simde_mm_set_epi32(UINT32_C(  799949492), UINT32_C(  108351731), UINT32_C( 1351843398), UINT32_C( 1009306115)),
      simde_mm_set_epi32(UINT32_C(  799949492), UINT32_C(  108351731), UINT32_C( 1351843398), UINT32_C( -791791151)) },
    { simde_mm_set_epi32(UINT32_C(-1327926842), UINT32_C(  984094365), UINT32_C( 1894460641), UINT32_C(  -26405962)),
      simde_mm_set_epi32(UINT32_C( 1205481380), UINT32_C(  137390510), UINT32_C(  590747940), UINT32_C( 1878652085)),
      simde_mm_set_epi32(UINT32_C(-1327926842), UINT32_C(  137390510), UINT32_C(  590747940), UINT32_C(  -26405962)) },
    { simde_mm_set_epi32(UINT32_C(  316126780), UINT32_C(-1043744394), UINT32_C(  787289081), UINT32_C( -910852690)),
      simde_mm_set_epi32(UINT32_C(-2087288343), UINT32_C(-1056950039), UINT32_C( -555736705), UINT32_C(  666671486)),
      simde_mm_set_epi32(UINT32_C(-2087288343), UINT32_C(-1056950039), UINT32_C( -555736705), UINT32_C( -910852690)) },
    { simde_mm_set_epi32(UINT32_C(-1498461986), UINT32_C(-1418974686), UINT32_C(-1311767695), UINT32_C(-1038502387)),
      simde_mm_set_epi32(UINT32_C( -722855220), UINT32_C(  492871512), UINT32_C( -175913896), UINT32_C( -920105808)),
      simde_mm_set_epi32(UINT32_C(-1498461986), UINT32_C(-1418974686), UINT32_C(-1311767695), UINT32_C(-1038502387)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_min_epi32(test_vec[i].a, test_vec[i].b);
    simde_assert_m128i_i32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_mullo_epi32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi32(UINT32_C( 1431531471), UINT32_C(-1934656662), UINT32_C( -638668877), UINT32_C( 1966621031)),
      simde_mm_set_epi32(UINT32_C( -646581607), UINT32_C( 1232530244), UINT32_C(  841047033), UINT32_C(-1472432488)),
      simde_mm_set_epi32(UINT32_C( 1865056439), UINT32_C(-1849485784), UINT32_C( 1840285211), UINT32_C( 1940934440)) },
    { simde_mm_set_epi32(UINT32_C( 2119691862), UINT32_C( 1656188631), UINT32_C(  949015012), UINT32_C( -645064268)),
      simde_mm_set_epi32(UINT32_C( 1854664684), UINT32_C( 1364588379), UINT32_C( -185048322), UINT32_C( 1546431794)),
      simde_mm_set_epi32(UINT32_C( -314310328), UINT32_C( -410462355), UINT32_C(  887719992), UINT32_C( -220354264)) },
    { simde_mm_set_epi32(UINT32_C(  390191893), UINT32_C( 1246080619), UINT32_C( 2032818940), UINT32_C(-1664549536)),
      simde_mm_set_epi32(UINT32_C( 1802476280), UINT32_C(-1492538899), UINT32_C( -866846002), UINT32_C(-1929477089)),
      simde_mm_set_epi32(UINT32_C( -357441960), UINT32_C(-1318446065), UINT32_C(-2019602744), UINT32_C(-2076430688)) },
    { simde_mm_set_epi32(UINT32_C( -629988407), UINT32_C(-1719063308), UINT32_C( -231912988), UINT32_C( 1462330866)),
      simde_mm_set_epi32(UINT32_C(-1320599620), UINT32_C( -769970788), UINT32_C( -625134420), UINT32_C(  293199422)),
      simde_mm_set_epi32(UINT32_C( -273826148), UINT32_C(-1841674064), UINT32_C(-1631324880), UINT32_C( 1137740956)) },
    { simde_mm_set_epi32(UINT32_C(-1221152076), UINT32_C(-1223458578), UINT32_C(-1263311025), UINT32_C( 2089857790)),
      simde_mm_set_epi32(UINT32_C(-2068401725), UINT32_C( 1531524331), UINT32_C( 1064638153), UINT32_C( -843878287)),
      simde_mm_set_epi32(UINT32_C( 1009816348), UINT32_C( 1660269178), UINT32_C( -203954425), UINT32_C( -674749922)) },
    { simde_mm_set_epi32(UINT32_C(-1283522478), UINT32_C(  524522527), UINT32_C( 1152886109), UINT32_C( -438302719)),
      simde_mm_set_epi32(UINT32_C(-2012975476), UINT32_C(  -67951228), UINT32_C(  258710699), UINT32_C(  -25585755)),
      simde_mm_set_epi32(UINT32_C( 1289709784), UINT32_C( -508699908), UINT32_C( 1615798559), UINT32_C(  345423781)) },
    { simde_mm_set_epi32(UINT32_C(  199098300), UINT32_C(-1941350427), UINT32_C(-1170519288), UINT32_C( 2117275260)),
      simde_mm_set_epi32(UINT32_C( 1736533752), UINT32_C(  668304389), UINT32_C(-1871663356), UINT32_C( -231105582)),
      simde_mm_set_epi32(UINT32_C( 1957733920), UINT32_C(-1823880327), UINT32_C( -994597856), UINT32_C( -515705416)) },
    { simde_mm_set_epi32(UINT32_C(  796248112), UINT32_C(  -74441002), UINT32_C(  756194998), UINT32_C(  128690934)),
      simde_mm_set_epi32(UINT32_C( -934813484), UINT32_C( 1495167051), UINT32_C(  549239917), UINT32_C( 1315900336)),
      simde_mm_set_epi32(UINT32_C( 1644414912), UINT32_C(-1010128718), UINT32_C(  723729278), UINT32_C(-1157096672)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_mullo_epi32(test_vec[i].a, test_vec[i].b);
    simde_assert_m128i_i32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitTest test_suite_tests[] = {
  { (char*) "/mm_blendv_epi8",    test_simde_mm_blendv_epi8,    NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },

  { (char*) "/mm_cvtepi16_epi32", test_simde_mm_cvtepi16_epi32, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_cvtepu8_epi32",  test_simde_mm_cvtepu8_epi32,  NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },

  { (char*) "/mm_extract_epi64",  test_simde_mm_extract_epi64,  NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },

  { (char*) "/mm_max_epi32",      test_simde_mm_max_epi32,      NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_max_epi8",       test_simde_mm_max_epi8,       NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_min_epi8",       test_simde_mm_min_epi8,       NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mm_min_epi32",      test_simde_mm_min_epi32,      NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },

  { (char*) "/mm_mullo_epi32",    test_simde_mm_mullo_epi32,    NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },

  { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};

const MunitSuite simde_sse4_1_test_suite = {
  (char*) "/sse4.1",
  test_suite_tests,
  NULL,
  1,
  MUNIT_SUITE_OPTION_NONE
};
