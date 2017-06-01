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

#include <test/x86/x86-internal.h>
#include <simde/x86/mmx.h>

#include <stdio.h>

static MunitResult
test_simde_mm_set_pi8(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  int8_t d[8 / sizeof(int8_t)];
  munit_rand_memory(sizeof(d), (uint8_t*) d);

  simde__m64 x = simde_mm_set_pi8(d[0], d[1], d[2], d[3], d[4], d[5], d[6], d[7]);
  int8_t* c = (int8_t*) &x;

  simde_mm_empty();

  munit_assert_int8(c[0], ==, d[7]);
  munit_assert_int8(c[1], ==, d[6]);
  munit_assert_int8(c[2], ==, d[5]);
  munit_assert_int8(c[3], ==, d[4]);
  munit_assert_int8(c[4], ==, d[3]);
  munit_assert_int8(c[5], ==, d[2]);
  munit_assert_int8(c[6], ==, d[1]);
  munit_assert_int8(c[7], ==, d[0]);

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_set_pi16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  int16_t d[8 / sizeof(int16_t)];
  munit_rand_memory(sizeof(d), (uint8_t*) d);

  simde__m64 x = simde_mm_set_pi16(d[0], d[1], d[2], d[3]);
  int16_t* s = (int16_t*) &x;

  simde_mm_empty();

  munit_assert_int16(s[0], ==, d[3]);
  munit_assert_int16(s[1], ==, d[2]);
  munit_assert_int16(s[2], ==, d[1]);
  munit_assert_int16(s[3], ==, d[0]);

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_set_pi32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  int32_t d[8 / sizeof(int)];
  munit_rand_memory(sizeof(d), (uint8_t*) d);

  simde__m64 x = simde_mm_set_pi32(d[0], d[1]);
  int32_t* i = (int32_t*) &x;

  simde_mm_empty();

  munit_assert_int32(i[0], ==, d[1]);
  munit_assert_int32(i[1], ==, d[0]);

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_set1_pi8(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  int8_t v = (int8_t) munit_rand_int_range(INT8_MIN, INT8_MAX);

  simde__m64 x = simde_mm_set1_pi8(v);
  int8_t* r = (int8_t*) &x;

  simde_mm_empty();

  munit_assert_int8(r[0], ==, v);
  munit_assert_int8(r[1], ==, v);
  munit_assert_int8(r[2], ==, v);
  munit_assert_int8(r[3], ==, v);
  munit_assert_int8(r[4], ==, v);
  munit_assert_int8(r[5], ==, v);
  munit_assert_int8(r[6], ==, v);
  munit_assert_int8(r[7], ==, v);

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_set1_pi16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  int16_t v = (int16_t) munit_rand_int_range(SHRT_MIN, SHRT_MAX);

  simde__m64 x = simde_mm_set1_pi16(v);
  int16_t* r = (int16_t*) &x;

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

  int32_t v = (int32_t) munit_rand_int_range(INT32_MIN, INT32_MAX);

  simde__m64 x = simde_mm_set1_pi32(v);
  int32_t* r = (int32_t*) &x;

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
  munit_rand_memory(sizeof(d), (uint8_t*) d);

  simde__m64 x = simde_mm_setr_pi8(d[0], d[1], d[2], d[3], d[4], d[5], d[6], d[7]);
  int8_t* c = (int8_t*) &x;

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
  munit_rand_memory(sizeof(d), (uint8_t*) d);

  simde__m64 x = simde_mm_setr_pi16(d[0], d[1], d[2], d[3]);
  int16_t* s = (int16_t*) &x;

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
  munit_rand_memory(sizeof(d), (uint8_t*) d);

  simde__m64 x = simde_mm_setr_pi32(d[0], d[1]);
  int32_t* i = (int32_t*) &x;

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
    { simde_mm_set_pi8(0x19, 0x96, 0x5d, 0x56, 0xc8, 0x65, 0x4f, 0x53),
      simde_mm_set_pi8(0xda, 0xfa, 0x2f, 0x3b, 0xbd, 0xdc, 0x7f, 0x68),
      simde_mm_set_pi8(0xf3, 0x90, 0x8c, 0x91, 0x85, 0x41, 0xce, 0xbb) },
    { simde_mm_set_pi8(0x97, 0x71, 0x16, 0xa5, 0x3b, 0xfc, 0x43, 0x2b),
      simde_mm_set_pi8(0xf3, 0x5d, 0x51, 0x6c, 0x98, 0x7b, 0x69, 0x77),
      simde_mm_set_pi8(0x8a, 0xce, 0x67, 0x11, 0xd3, 0x77, 0xac, 0xa2) },
    { simde_mm_set_pi8(0xf8, 0x34, 0x5c, 0x79, 0x3a, 0x98, 0x1b, 0xb0),
      simde_mm_set_pi8(0x3e, 0x9c, 0x05, 0xa1, 0xf0, 0x6d, 0x7f, 0x3e),
      simde_mm_set_pi8(0x36, 0xd0, 0x61, 0x1a, 0x2a, 0x05, 0x9a, 0xee) },
    { simde_mm_set_pi8(0x20, 0x7c, 0x73, 0x03, 0x68, 0x1b, 0x2b, 0xf5),
      simde_mm_set_pi8(0xea, 0x1b, 0xd1, 0x2d, 0xa0, 0xcf, 0xb6, 0xde),
      simde_mm_set_pi8(0x0a, 0x97, 0x44, 0x30, 0x08, 0xea, 0xe1, 0xd3) },
    { simde_mm_set_pi8(0xf2, 0xb1, 0xda, 0xa3, 0xc9, 0x53, 0x4e, 0xa6),
      simde_mm_set_pi8(0x5b, 0xc3, 0x84, 0xc0, 0x4c, 0xf1, 0x8b, 0x0b),
      simde_mm_set_pi8(0x4d, 0x74, 0x5e, 0x63, 0x15, 0x44, 0xd9, 0xb1) },
    { simde_mm_set_pi8(0x89, 0x21, 0xc7, 0x36, 0xee, 0x4f, 0x56, 0xe7),
      simde_mm_set_pi8(0x8d, 0x8e, 0x48, 0x82, 0xb0, 0x72, 0x82, 0x2a),
      simde_mm_set_pi8(0x16, 0xaf, 0x0f, 0xb8, 0x9e, 0xc1, 0xd8, 0x11) },
    { simde_mm_set_pi8(0x3c, 0x6d, 0x5d, 0xd3, 0xc2, 0x98, 0xd7, 0x48),
      simde_mm_set_pi8(0x48, 0xaa, 0x15, 0x4f, 0x2b, 0x17, 0xb6, 0xc2),
      simde_mm_set_pi8(0x84, 0x17, 0x72, 0x22, 0xed, 0xaf, 0x8d, 0x0a) },
    { simde_mm_set_pi8(0x6e, 0x6a, 0xa2, 0x66, 0xae, 0x6c, 0xf4, 0xd0),
      simde_mm_set_pi8(0x6c, 0x03, 0xa5, 0x41, 0x1e, 0x6a, 0xff, 0x64),
      simde_mm_set_pi8(0xda, 0x6d, 0x47, 0xa7, 0xcc, 0xd6, 0xf3, 0x34) }
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
    { simde_mm_set_pi16(0xcc36, 0xddb8, 0x7e6d, 0xf0d1),
      simde_mm_set_pi16(0x4e32, 0x5b79, 0xfcfa, 0x16b2),
      simde_mm_set_pi16(0x1a68, 0x3931, 0x7b67, 0x0783) },
    { simde_mm_set_pi16(0x2c47, 0x7424, 0x65cb, 0xc564),
      simde_mm_set_pi16(0xca34, 0xae46, 0x07c9, 0x8945),
      simde_mm_set_pi16(0xf67b, 0x226a, 0x6d94, 0x4ea9) },
    { simde_mm_set_pi16(0x009f, 0x5c4c, 0xbcb8, 0xa508),
      simde_mm_set_pi16(0xb881, 0x1e13, 0x574f, 0xc092),
      simde_mm_set_pi16(0xb920, 0x7a5f, 0x1407, 0x659a) },
    { simde_mm_set_pi16(0x2389, 0xe8a2, 0x6e1f, 0x803d),
      simde_mm_set_pi16(0xbde8, 0xb989, 0x81fd, 0x28a5),
      simde_mm_set_pi16(0xe171, 0xa22b, 0xf01c, 0xa8e2) },
    { simde_mm_set_pi16(0x0831, 0x5f83, 0x63bd, 0xc883),
      simde_mm_set_pi16(0x9193, 0x1184, 0xa931, 0x4619),
      simde_mm_set_pi16(0x99c4, 0x7107, 0x0cee, 0x0e9c) },
    { simde_mm_set_pi16(0xbb0a, 0x30a3, 0x3025, 0x144e),
      simde_mm_set_pi16(0x9822, 0x7c91, 0xc6c0, 0x18ea),
      simde_mm_set_pi16(0x532c, 0xad34, 0xf6e5, 0x2d38) },
    { simde_mm_set_pi16(0x7b0a, 0xb6da, 0xda08, 0xbd6e),
      simde_mm_set_pi16(0x4281, 0x3382, 0x9abd, 0x3aa9),
      simde_mm_set_pi16(0xbd8b, 0xea5c, 0x74c5, 0xf817) },
    { simde_mm_set_pi16(0x26b0, 0x9263, 0x8285, 0xfafb),
      simde_mm_set_pi16(0xe3ea, 0xf882, 0x681e, 0x8527),
      simde_mm_set_pi16(0x0a9a, 0x8ae5, 0xeaa3, 0x8022) }
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
    { simde_mm_set_pi32(0xa4e05d2d, 0x93297f7c),
      simde_mm_set_pi32(0xb6b4ca2f, 0x3b0097a1),
      simde_mm_set_pi32(0x5b95275c, 0xce2a171d) },
    { simde_mm_set_pi32(0x73715e7c, 0x4f55c863),
      simde_mm_set_pi32(0xe1da937c, 0x57b2d16a),
      simde_mm_set_pi32(0x554bf1f8, 0xa70899cd) },
    { simde_mm_set_pi32(0x2eb84efc, 0x72a06142),
      simde_mm_set_pi32(0x65566652, 0xf58a7afd),
      simde_mm_set_pi32(0x940eb54e, 0x682adc3f) },
    { simde_mm_set_pi32(0x4749244b, 0x4f39928a),
      simde_mm_set_pi32(0xdb8caca1, 0x2eed6088),
      simde_mm_set_pi32(0x22d5d0ec, 0x7e26f312) },
    { simde_mm_set_pi32(0x38a16c13, 0x22075321),
      simde_mm_set_pi32(0x65255049, 0x96ef5dc0),
      simde_mm_set_pi32(0x9dc6bc5c, 0xb8f6b0e1) },
    { simde_mm_set_pi32(0x026fa3d0, 0x08e4259d),
      simde_mm_set_pi32(0x6159d6bf, 0xf2a5a065),
      simde_mm_set_pi32(0x63c97a8f, 0xfb89c602) },
    { simde_mm_set_pi32(0xd525e259, 0x569edf13),
      simde_mm_set_pi32(0x0360eaae, 0xdc8cf548),
      simde_mm_set_pi32(0xd886cd07, 0x332bd45b) },
    { simde_mm_set_pi32(0xc759ded1, 0xffe934bc),
      simde_mm_set_pi32(0x9bd96cf5, 0x13223ea9),
      simde_mm_set_pi32(0x63334bc6, 0x130b7365) }
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
    { simde_x_mm_set_pu8(0x3c, 0x96, 0x00, 0x26, 0x5f, 0x5e, 0xd9, 0xd0),
      simde_x_mm_set_pu8(0xfb, 0x3d, 0x8c, 0x9e, 0xbf, 0x76, 0x0f, 0xa5),
      simde_x_mm_set_pu8(0xff, 0xd3, 0x8c, 0xc4, 0xff, 0xd4, 0xe8, 0xff) },
    { simde_x_mm_set_pu8(0xe7, 0x1d, 0xd1, 0xe2, 0xaf, 0x23, 0xd8, 0x31),
      simde_x_mm_set_pu8(0xf4, 0xed, 0xad, 0xea, 0xd2, 0x50, 0x65, 0xf0),
      simde_x_mm_set_pu8(0xff, 0xff, 0xff, 0xff, 0xff, 0x73, 0xff, 0xff) },
    { simde_x_mm_set_pu8(0xf9, 0x8d, 0x68, 0x80, 0x09, 0xc3, 0x99, 0x86),
      simde_x_mm_set_pu8(0xca, 0x8f, 0xb8, 0xbf, 0x7a, 0xfb, 0xa0, 0xa1),
      simde_x_mm_set_pu8(0xff, 0xff, 0xff, 0xff, 0x83, 0xff, 0xff, 0xff) },
    { simde_x_mm_set_pu8(0x1f, 0xb9, 0x3f, 0x16, 0x02, 0x23, 0x72, 0xda),
      simde_x_mm_set_pu8(0xd6, 0xc2, 0xa7, 0xbe, 0x8c, 0xf8, 0x7f, 0x88),
      simde_x_mm_set_pu8(0xf5, 0xff, 0xe6, 0xd4, 0x8e, 0xff, 0xf1, 0xff) },
    { simde_x_mm_set_pu8(0x92, 0x59, 0xd9, 0x40, 0x81, 0xf7, 0xb4, 0x14),
      simde_x_mm_set_pu8(0x7c, 0x9d, 0x89, 0xc9, 0x10, 0x95, 0x35, 0x2d),
      simde_x_mm_set_pu8(0xff, 0xf6, 0xff, 0xff, 0x91, 0xff, 0xe9, 0x41) },
    { simde_x_mm_set_pu8(0xfa, 0x5d, 0x04, 0x54, 0xc4, 0x92, 0x20, 0xfd),
      simde_x_mm_set_pu8(0x05, 0x53, 0x92, 0x2f, 0x7e, 0x5d, 0xdf, 0x33),
      simde_x_mm_set_pu8(0xff, 0xb0, 0x96, 0x83, 0xff, 0xef, 0xff, 0xff) },
    { simde_x_mm_set_pu8(0x65, 0x67, 0x88, 0x23, 0x38, 0x51, 0xab, 0x96),
      simde_x_mm_set_pu8(0x3f, 0xc7, 0xd8, 0xa7, 0x36, 0x23, 0x1a, 0xef),
      simde_x_mm_set_pu8(0xa4, 0xff, 0xff, 0xca, 0x6e, 0x74, 0xc5, 0xff) },
    { simde_x_mm_set_pu8(0x72, 0x91, 0x2f, 0x87, 0x35, 0x43, 0x17, 0x3d),
      simde_x_mm_set_pu8(0x10, 0xd3, 0xfe, 0x73, 0x96, 0x22, 0xed, 0xe9),
      simde_x_mm_set_pu8(0x82, 0xff, 0xff, 0xfa, 0xcb, 0x65, 0xff, 0xff) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m64 r = simde_mm_adds_pu8(test_vec[i].a, test_vec[i].b);
    simde_mm_empty();
    simde_assert_m64_u8(r, ==, test_vec[i].r);
  }

  simde_mm_empty();
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
    { simde_mm_set_pi16(0x85b3, 0xea33, 0xcb36, 0x9f96),
      simde_mm_set_pi16(0x4db4, 0xd080, 0x0cc2, 0x232a),
      simde_mm_set_pi16(0xd367, 0xbab3, 0xd7f8, 0xc2c0) },
    { simde_mm_set_pi16(0x5054, 0x9c2e, 0x485a, 0xff95),
      simde_mm_set_pi16(0x3028, 0x3253, 0x08cb, 0xb551),
      simde_mm_set_pi16(0x7fff, 0xce81, 0x5125, 0xb4e6) },
    { simde_mm_set_pi16(0x4e8a, 0xc367, 0x9c30, 0xa339),
      simde_mm_set_pi16(0x2c74, 0x125a, 0x41f6, 0x2c28),
      simde_mm_set_pi16(0x7afe, 0xd5c1, 0xde26, 0xcf61) },
    { simde_mm_set_pi16(0x87a9, 0xcf38, 0x2f76, 0x0158),
      simde_mm_set_pi16(0xab19, 0x2ca0, 0x4b8e, 0xa790),
      simde_mm_set_pi16(0x8000, 0xfbd8, 0x7b04, 0xa8e8) },
    { simde_mm_set_pi16(0x5a94, 0xae33, 0x696f, 0xd389),
      simde_mm_set_pi16(0x5066, 0x19e4, 0x7d61, 0x5b65),
      simde_mm_set_pi16(0x7fff, 0xc817, 0x7fff, 0x2eee) },
    { simde_mm_set_pi16(0x06fd, 0x6f96, 0x4a33, 0x810c),
      simde_mm_set_pi16(0x809f, 0x8947, 0x0706, 0x6f45),
      simde_mm_set_pi16(0x879c, 0xf8dd, 0x5139, 0xf051) },
    { simde_mm_set_pi16(0x483b, 0xd1fb, 0x949d, 0x0151),
      simde_mm_set_pi16(0x01a4, 0x7066, 0x8679, 0x3b98),
      simde_mm_set_pi16(0x49df, 0x4261, 0x8000, 0x3ce9) },
    { simde_mm_set_pi16(0xc2b9, 0x638f, 0x5a08, 0xdee2),
      simde_mm_set_pi16(0x2437, 0xed6c, 0xd0c9, 0xc3e9),
      simde_mm_set_pi16(0xe6f0, 0x50fb, 0x2ad1, 0xa2cb) }
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
    { simde_x_mm_set_pu16(0x4d12, 0x3df9, 0x335a, 0xeb86),
      simde_x_mm_set_pu16(0xef25, 0x3789, 0x6db3, 0x462f),
      simde_x_mm_set_pu16(0xffff, 0x7582, 0xa10d, 0xffff) },
    { simde_x_mm_set_pu16(0xb40b, 0x746f, 0x5718, 0xbb81),
      simde_x_mm_set_pu16(0xa38b, 0x1fb9, 0x08ef, 0x2bc5),
      simde_x_mm_set_pu16(0xffff, 0x9428, 0x6007, 0xe746) },
    { simde_x_mm_set_pu16(0xb3bf, 0x9d1f, 0x9696, 0x9d99),
      simde_x_mm_set_pu16(0x36de, 0x7c18, 0xb6c4, 0x1b9d),
      simde_x_mm_set_pu16(0xea9d, 0xffff, 0xffff, 0xb936) },
    { simde_x_mm_set_pu16(0x996f, 0x0c13, 0x78c5, 0xadd2),
      simde_x_mm_set_pu16(0x735e, 0x3ffa, 0xf5a8, 0xf088),
      simde_x_mm_set_pu16(0xffff, 0x4c0d, 0xffff, 0xffff) },
    { simde_x_mm_set_pu16(0xa440, 0xc25f, 0x76c2, 0x1f54),
      simde_x_mm_set_pu16(0x04f4, 0x2fc9, 0xdd12, 0xf7e7),
      simde_x_mm_set_pu16(0xa934, 0xf228, 0xffff, 0xffff) },
    { simde_x_mm_set_pu16(0x072d, 0xfb9c, 0xa259, 0xc05c),
      simde_x_mm_set_pu16(0xe9c1, 0x0209, 0xccb3, 0x851f),
      simde_x_mm_set_pu16(0xf0ee, 0xfda5, 0xffff, 0xffff) },
    { simde_x_mm_set_pu16(0xe577, 0x82f6, 0x1fcd, 0xcb4a),
      simde_x_mm_set_pu16(0xf8ec, 0x61df, 0xbd83, 0xcccc),
      simde_x_mm_set_pu16(0xffff, 0xe4d5, 0xdd50, 0xffff) },
    { simde_x_mm_set_pu16(0x8b03, 0xc9b5, 0x2685, 0xeaa2),
      simde_x_mm_set_pu16(0xa38a, 0x6e80, 0x15d0, 0x7667),
      simde_x_mm_set_pu16(0xffff, 0xffff, 0x3c55, 0xffff) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m64 r = simde_mm_adds_pu16(test_vec[i].a, test_vec[i].b);
    simde_mm_empty();
    simde_assert_m64_u16(r, ==, test_vec[i].r);
  }

  simde_mm_empty();
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
    { simde_mm_set_pi32(0x144c257e, 0x33ba1fbe),
      simde_mm_set_pi32(0x99c6657b, 0x13835d57),
      simde_mm_set_pi32(0x1044257a, 0x13821d16) },
    { simde_mm_set_pi32(0x15b94c0e, 0x91869bf9),
      simde_mm_set_pi32(0x196337a0, 0xdfee49cd),
      simde_mm_set_pi32(0x11210400, 0x918609c9) },
    { simde_mm_set_pi32(0x48da74ac, 0x8bbf676f),
      simde_mm_set_pi32(0x0641aef3, 0x1443debe),
      simde_mm_set_pi32(0x004024a0, 0x0003462e) },
    { simde_mm_set_pi32(0x28732761, 0x50acbfb4),
      simde_mm_set_pi32(0x3eab5e0e, 0xc30b648f),
      simde_mm_set_pi32(0x28230600, 0x40082484) },
    { simde_mm_set_pi32(0x6cb04b6a, 0x991ae02b),
      simde_mm_set_pi32(0x43f0cdd5, 0x3419e02a),
      simde_mm_set_pi32(0x40b04940, 0x1018e02a) },
    { simde_mm_set_pi32(0x0b3f944b, 0x36ca8c12),
      simde_mm_set_pi32(0xe1e07d37, 0x9b9452a5),
      simde_mm_set_pi32(0x01201403, 0x12800000) },
    { simde_mm_set_pi32(0xa7641f1a, 0x12570460),
      simde_mm_set_pi32(0x9513fe43, 0x750d4083),
      simde_mm_set_pi32(0x85001e02, 0x10050000) },
    { simde_mm_set_pi32(0xda6f00b9, 0xfb1799bc),
      simde_mm_set_pi32(0x5fc97d85, 0x33b95b4c),
      simde_mm_set_pi32(0x5a490081, 0x3311190c) }
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
    { simde_mm_set_pi32(0x3425e371, 0xd02dfafb),
      simde_mm_set_pi32(0x13a8010e, 0x1c99a489),
      simde_mm_set_pi32(0x0388000e, 0x0c900400) },
    { simde_mm_set_pi32(0xc7af1daf, 0x74738f9e),
      simde_mm_set_pi32(0xc97744fb, 0xded2bbba),
      simde_mm_set_pi32(0x08504050, 0x8a803020) },
    { simde_mm_set_pi32(0xf0e35afb, 0x5813fda1),
      simde_mm_set_pi32(0xa1b63aec, 0xa03a2993),
      simde_mm_set_pi32(0x01142004, 0xa0280012) },
    { simde_mm_set_pi32(0xdd14761c, 0x3134f75f),
      simde_mm_set_pi32(0x972f6a8e, 0xd9a4754f),
      simde_mm_set_pi32(0x022b0882, 0xc8800000) },
    { simde_mm_set_pi32(0xffacf087, 0x296a73ad),
      simde_mm_set_pi32(0x9fcf4978, 0x0cdd9711),
      simde_mm_set_pi32(0x00430978, 0x04958410) },
    { simde_mm_set_pi32(0x554f2958, 0x3c2df6ee),
      simde_mm_set_pi32(0x9c91ca9a, 0xd44aee0d),
      simde_mm_set_pi32(0x8890c282, 0xc0420801) },
    { simde_mm_set_pi32(0x65c0b6ff, 0xa8d8d28e),
      simde_mm_set_pi32(0xc36aba80, 0x8fd87d5b),
      simde_mm_set_pi32(0x822a0800, 0x07002d51) },
    { simde_mm_set_pi32(0x1407f68e, 0x885a1c80),
      simde_mm_set_pi32(0x8b36f6ec, 0xcf11be13),
      simde_mm_set_pi32(0x8b300060, 0x4701a213) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m64 r = simde_mm_andnot_si64(test_vec[i].a, test_vec[i].b);
    simde_mm_empty();
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
    { simde_mm_set_pi8(0x3d, 0x8b, 0x8b, 0xe9, 0xed, 0x06, 0xe8, 0x59),
      simde_mm_set_pi8(0x2f, 0x47, 0x97, 0x0d, 0xe6, 0x5d, 0x76, 0xc6),
      simde_mm_set_pi8(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00) },
    { simde_mm_set_pi8(0x4e, 0x0b, 0xfe, 0x56, 0xce, 0xcf, 0xff, 0x5c),
      simde_mm_set_pi8(0xab, 0x9d, 0xd7, 0x74, 0x4a, 0x72, 0xfd, 0x9e),
      simde_mm_set_pi8(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00) },
    { simde_mm_set_pi8(0x3c, 0x0a, 0xde, 0x1e, 0x30, 0xf3, 0x96, 0x69),
      simde_mm_set_pi8(0x51, 0x6c, 0xbf, 0xc6, 0xe2, 0xa6, 0x2a, 0x00),
      simde_mm_set_pi8(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00) },
    { simde_mm_set_pi8(0x8f, 0xbd, 0xc9, 0x54, 0xa4, 0xbe, 0x07, 0x15),
      simde_mm_set_pi8(0x8f, 0xbd, 0xc9, 0x54, 0xa4, 0xbe, 0x07, 0x15),
      simde_mm_set_pi8(0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff) },
    { simde_mm_set_pi8(0xb8, 0xc8, 0x98, 0xfa, 0x25, 0x8e, 0x54, 0x15),
      simde_mm_set_pi8(0x4d, 0xe7, 0x98, 0x00, 0xd9, 0x26, 0xca, 0xa6),
      simde_mm_set_pi8(0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00) },
    { simde_mm_set_pi8(0x2e, 0x78, 0xf3, 0x83, 0x32, 0x0a, 0x78, 0xf6),
      simde_mm_set_pi8(0x55, 0x59, 0x09, 0x41, 0xae, 0xb0, 0x41, 0xbf),
      simde_mm_set_pi8(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00) },
    { simde_mm_set_pi8(0xf4, 0xd7, 0xca, 0x5c, 0xa9, 0xae, 0x88, 0x25),
      simde_mm_set_pi8(0x5e, 0xeb, 0x24, 0x87, 0xc2, 0xfc, 0x2a, 0x89),
      simde_mm_set_pi8(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00) },
    { simde_mm_set_pi8(0xf8, 0xc4, 0x23, 0xe1, 0x99, 0xf9, 0xd9, 0x2f),
      simde_mm_set_pi8(0x0d, 0xac, 0x82, 0x81, 0xae, 0x25, 0x3c, 0x1e),
      simde_mm_set_pi8(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00) }
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
    { simde_mm_set_pi16(0xc9b1, 0x919d, 0x2a22, 0x5fc6),
      simde_mm_set_pi16(0x1493, 0x0784, 0x33e1, 0x9e21),
      simde_mm_set_pi16(0x0000, 0x0000, 0x0000, 0x0000) },
    { simde_mm_set_pi16(0xaa43, 0xcb55, 0xfe7a, 0x18e9),
      simde_mm_set_pi16(0xda91, 0x1adc, 0x5cd8, 0x1841),
      simde_mm_set_pi16(0x0000, 0x0000, 0x0000, 0x0000) },
    { simde_mm_set_pi16(0x2c64, 0x6edf, 0x3429, 0x37b5),
      simde_mm_set_pi16(0x346e, 0x7d21, 0x0fd7, 0x15f7),
      simde_mm_set_pi16(0x0000, 0x0000, 0x0000, 0x0000) },
    { simde_mm_set_pi16(0x00ce, 0xf9e1, 0xbcff, 0x46f6),
      simde_mm_set_pi16(0x7737, 0x77b3, 0x7fdf, 0xef9d),
      simde_mm_set_pi16(0x0000, 0x0000, 0x0000, 0x0000) },
    { simde_mm_set_pi16(0x633e, 0xb859, 0xc202, 0xc36f),
      simde_mm_set_pi16(0x633e, 0xb859, 0xc202, 0xc36f),
      simde_mm_set_pi16(0xffff, 0xffff, 0xffff, 0xffff) },
    { simde_mm_set_pi16(0x5391, 0x591f, 0x0142, 0x2588),
      simde_mm_set_pi16(0x5d91, 0x8448, 0xe286, 0x7cfc),
      simde_mm_set_pi16(0x0000, 0x0000, 0x0000, 0x0000) },
    { simde_mm_set_pi16(0xbf86, 0xfc67, 0x8243, 0x480c),
      simde_mm_set_pi16(0xd79c, 0x9232, 0x5df9, 0xe479),
      simde_mm_set_pi16(0x0000, 0x0000, 0x0000, 0x0000) },
    { simde_mm_set_pi16(0xfb6b, 0x9b0c, 0xd617, 0x5669),
      simde_mm_set_pi16(0x6572, 0x31ae, 0x6350, 0x2e5b),
      simde_mm_set_pi16(0x0000, 0x0000, 0x0000, 0x0000) }
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
    { simde_mm_set_pi32(0xcb55aa43, 0x18e9fe7a),
      simde_mm_set_pi32(0x1adcda91, 0x18415cd8),
      simde_mm_set_pi32(0x00000000, 0x00000000) },
    { simde_mm_set_pi32(0x6edf2c64, 0x37b53429),
      simde_mm_set_pi32(0x7d21346e, 0x15f70fd7),
      simde_mm_set_pi32(0x00000000, 0x00000000) },
    { simde_mm_set_pi32(0xf9e100ce, 0x46f6bcff),
      simde_mm_set_pi32(0x77b37737, 0xef9d7fdf),
      simde_mm_set_pi32(0x00000000, 0x00000000) },
    { simde_mm_set_pi32(0x07841493, 0x9e2133e1),
      simde_mm_set_pi32(0x07841493, 0x9e2133e1),
      simde_mm_set_pi32(0xffffffff, 0xffffffff) },
    { simde_mm_set_pi32(0xb859633e, 0xc36fc202),
      simde_mm_set_pi32(0xc2526ad6, 0xc4ce7bc7),
      simde_mm_set_pi32(0x00000000, 0x00000000) },
    { simde_mm_set_pi32(0x591f5391, 0x25880142),
      simde_mm_set_pi32(0x84485d91, 0x7cfce286),
      simde_mm_set_pi32(0x00000000, 0x00000000) },
    { simde_mm_set_pi32(0xfc67bf86, 0x480c8243),
      simde_mm_set_pi32(0x9232d79c, 0xe4795df9),
      simde_mm_set_pi32(0x00000000, 0x00000000) },
    { simde_mm_set_pi32(0x9b0cfb6b, 0x5669d617),
      simde_mm_set_pi32(0x31ae6572, 0x2e5b6350),
      simde_mm_set_pi32(0x00000000, 0x00000000) }
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
    { simde_mm_set_pi8(0xb3, 0x1d, 0xde, 0x92, 0xb2, 0xf8, 0x5c, 0x2c),
      simde_mm_set_pi8(0xc7, 0x63, 0xf6, 0x1c, 0x2e, 0x4f, 0xb4, 0x3b),
      simde_mm_set_pi8(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x00) },
    { simde_mm_set_pi8(0x60, 0xf7, 0xc3, 0x2e, 0x68, 0x97, 0x59, 0x30),
      simde_mm_set_pi8(0x6d, 0x46, 0x0d, 0x5a, 0x8c, 0xe9, 0x0a, 0xa0),
      simde_mm_set_pi8(0x00, 0x00, 0x00, 0x00, 0xff, 0x00, 0xff, 0xff) },
    { simde_mm_set_pi8(0xe8, 0xfe, 0x49, 0x24, 0xe3, 0xba, 0x49, 0x87),
      simde_mm_set_pi8(0x11, 0xef, 0x4d, 0xfe, 0x6f, 0x91, 0xbe, 0xe2),
      simde_mm_set_pi8(0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0xff, 0x00) },
    { simde_mm_set_pi8(0x48, 0x9a, 0x87, 0x29, 0xe3, 0x9c, 0xba, 0x52),
      simde_mm_set_pi8(0x65, 0x76, 0x92, 0xb6, 0xc7, 0xfe, 0x59, 0xf0),
      simde_mm_set_pi8(0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0xff) },
    { simde_mm_set_pi8(0x40, 0x02, 0x8a, 0x17, 0xa8, 0x88, 0x3d, 0x72),
      simde_mm_set_pi8(0x3c, 0x5b, 0x60, 0xea, 0x26, 0x31, 0x50, 0xe3),
      simde_mm_set_pi8(0xff, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff) },
    { simde_mm_set_pi8(0x1f, 0xe0, 0x87, 0x09, 0x50, 0x6c, 0x1d, 0x02),
      simde_mm_set_pi8(0x89, 0x21, 0x09, 0x65, 0x65, 0x4f, 0x29, 0x57),
      simde_mm_set_pi8(0xff, 0x00, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00) },
    { simde_mm_set_pi8(0x60, 0xb5, 0x87, 0x9b, 0x0a, 0x82, 0x3a, 0x3c),
      simde_mm_set_pi8(0x65, 0xb7, 0x7e, 0x69, 0xd0, 0x89, 0x9f, 0xa6),
      simde_mm_set_pi8(0x00, 0x00, 0x00, 0x00, 0xff, 0x00, 0xff, 0xff) },
    { simde_mm_set_pi8(0x76, 0x76, 0xeb, 0xcf, 0x55, 0x45, 0x54, 0x6f),
      simde_mm_set_pi8(0xa0, 0x79, 0x92, 0xa9, 0xb7, 0x25, 0x2d, 0x88),
      simde_mm_set_pi8(0xff, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff) }
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
    { simde_mm_set_pi16(0x6a97, 0xbbdb, 0x1ebc, 0x4543),
      simde_mm_set_pi16(0x827e, 0xcf9b, 0xc297, 0xd6df),
      simde_mm_set_pi16(0xffff, 0x0000, 0xffff, 0xffff) },
    { simde_mm_set_pi16(0xa4dd, 0x4b52, 0x6c3e, 0x1200),
      simde_mm_set_pi16(0x807a, 0xf6f1, 0x4cfe, 0x6351),
      simde_mm_set_pi16(0xffff, 0xffff, 0xffff, 0x0000) },
    { simde_mm_set_pi16(0x72a6, 0xcfbc, 0xb93b, 0x8e02),
      simde_mm_set_pi16(0x271f, 0xecf1, 0x7815, 0xefd0),
      simde_mm_set_pi16(0xffff, 0x0000, 0x0000, 0x0000) },
    { simde_mm_set_pi16(0x77e9, 0xef89, 0x7b44, 0x2e89),
      simde_mm_set_pi16(0x95d8, 0x4503, 0x8911, 0xf77d),
      simde_mm_set_pi16(0xffff, 0x0000, 0xffff, 0xffff) },
    { simde_mm_set_pi16(0x23f7, 0x12b9, 0x9fec, 0x2765),
      simde_mm_set_pi16(0xb6d9, 0xfc5f, 0x1b8b, 0x2295),
      simde_mm_set_pi16(0xffff, 0xffff, 0x0000, 0xffff) },
    { simde_mm_set_pi16(0x58ce, 0x1702, 0xf25e, 0x9e9e),
      simde_mm_set_pi16(0x5c68, 0x38d4, 0x7c3e, 0xb835),
      simde_mm_set_pi16(0x0000, 0x0000, 0x0000, 0x0000) },
    { simde_mm_set_pi16(0x8fac, 0x08a3, 0xc30b, 0x82f6),
      simde_mm_set_pi16(0xd060, 0xd581, 0x703b, 0x1ee7),
      simde_mm_set_pi16(0x0000, 0xffff, 0x0000, 0x0000) },
    { simde_mm_set_pi16(0xda52, 0xdea0, 0xfcb5, 0x2f6c),
      simde_mm_set_pi16(0x10e4, 0x740a, 0x3563, 0xdc5d),
      simde_mm_set_pi16(0x0000, 0x0000, 0x0000, 0xffff) }
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
    { simde_mm_set_pi32(0xbbdb6a97, 0x45431ebc),
      simde_mm_set_pi32(0xcf9b827e, 0xd6dfc297),
      simde_mm_set_pi32(0x00000000, 0xffffffff) },
    { simde_mm_set_pi32(0x4b52a4dd, 0x12006c3e),
      simde_mm_set_pi32(0xf6f1807a, 0x63514cfe),
      simde_mm_set_pi32(0xffffffff, 0x00000000) },
    { simde_mm_set_pi32(0xcfbc72a6, 0x8e02b93b),
      simde_mm_set_pi32(0xecf1271f, 0xefd07815),
      simde_mm_set_pi32(0x00000000, 0x00000000) },
    { simde_mm_set_pi32(0xef8977e9, 0x2e897b44),
      simde_mm_set_pi32(0x450395d8, 0xf77d8911),
      simde_mm_set_pi32(0x00000000, 0xffffffff) },
    { simde_mm_set_pi32(0x12b923f7, 0x27659fec),
      simde_mm_set_pi32(0xfc5fb6d9, 0x22951b8b),
      simde_mm_set_pi32(0xffffffff, 0xffffffff) },
    { simde_mm_set_pi32(0x170258ce, 0x9e9ef25e),
      simde_mm_set_pi32(0x38d45c68, 0xb8357c3e),
      simde_mm_set_pi32(0x00000000, 0x00000000) },
    { simde_mm_set_pi32(0x08a38fac, 0x82f6c30b),
      simde_mm_set_pi32(0xd581d060, 0x1ee7703b),
      simde_mm_set_pi32(0xffffffff, 0x00000000) },
    { simde_mm_set_pi32(0xdea0da52, 0x2f6cfcb5),
      simde_mm_set_pi32(0x740a10e4, 0xdc5d3563),
      simde_mm_set_pi32(0x00000000, 0xffffffff) }
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
    { simde_mm_set_pi32(0x1909df06, 0xadc023ad), INT64_C(0x1909df06adc023ad) },
    { simde_mm_set_pi32(0x5d92f02c, 0x3a641e20), INT64_C(0x5d92f02c3a641e20) },
    { simde_mm_set_pi32(0x62195939, 0xd5d4f1fa), INT64_C(0x62195939d5d4f1fa) },
    { simde_mm_set_pi32(0x0f025282, 0x69d9aa4a), INT64_C(0x0f02528269d9aa4a) },
    { simde_mm_set_pi32(0xe33aa06e, 0x07284161), INT64_C(0xe33aa06e07284161) },
    { simde_mm_set_pi32(0xcfd51386, 0x785a7181), INT64_C(0xcfd51386785a7181) },
    { simde_mm_set_pi32(0xa1cd4124, 0x447edb08), INT64_C(0xa1cd4124447edb08) },
    { simde_mm_set_pi32(0x5e193237, 0x299721b7), INT64_C(0x5e193237299721b7) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    int64_t r = simde_mm_cvtm64_si64(test_vec[i].a);
    simde_mm_empty();
    munit_assert_int64(r, ==, test_vec[i].r);
  }

  simde_mm_empty();
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
    { 0xaf9e3edb, simde_mm_set_pi32(0x00000000, 0xaf9e3edb) },
    { 0xd2e56f4a, simde_mm_set_pi32(0x00000000, 0xd2e56f4a) },
    { 0xaa880cfd, simde_mm_set_pi32(0x00000000, 0xaa880cfd) },
    { 0xb17f1bfa, simde_mm_set_pi32(0x00000000, 0xb17f1bfa) },
    { 0x437a54ab, simde_mm_set_pi32(0x00000000, 0x437a54ab) },
    { 0x9b8f13e5, simde_mm_set_pi32(0x00000000, 0x9b8f13e5) },
    { 0xd157be56, simde_mm_set_pi32(0x00000000, 0xd157be56) },
    { 0xa06adee8, simde_mm_set_pi32(0x00000000, 0xa06adee8) }
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
    { INT64_C(0x0a213992287922eb), simde_mm_set_pi32(0x0a213992, 0x287922eb) },
    { INT64_C(0x6c1adb746c427d55), simde_mm_set_pi32(0x6c1adb74, 0x6c427d55) },
    { INT64_C(0xebf6a214f17bb34a), simde_mm_set_pi32(0xebf6a214, 0xf17bb34a) },
    { INT64_C(0xe06cc3268ead51ef), simde_mm_set_pi32(0xe06cc326, 0x8ead51ef) },
    { INT64_C(0x2ed66dbe21b71687), simde_mm_set_pi32(0x2ed66dbe, 0x21b71687) },
    { INT64_C(0xcb7f6152a87edf94), simde_mm_set_pi32(0xcb7f6152, 0xa87edf94) },
    { INT64_C(0xafbf4e510dd4d94b), simde_mm_set_pi32(0xafbf4e51, 0x0dd4d94b) },
    { INT64_C(0xda8a49210de6b19b), simde_mm_set_pi32(0xda8a4921, 0x0de6b19b) }
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
    { simde_mm_set_pi32(0x5263c8d6, 0xfef29fb0), 0xfef29fb0, },
    { simde_mm_set_pi32(0x7f1adc3c, 0xa7900f8d), 0xa7900f8d, },
    { simde_mm_set_pi32(0xcefdc926, 0x3bdb4413), 0x3bdb4413, },
    { simde_mm_set_pi32(0x21516e35, 0x8f86cc25), 0x8f86cc25, },
    { simde_mm_set_pi32(0x374884bb, 0x688d1d66), 0x688d1d66, },
    { simde_mm_set_pi32(0xb294efec, 0xbf90c942), 0xbf90c942, },
    { simde_mm_set_pi32(0x86bcf25e, 0x4bdca3ef), 0x4bdca3ef, },
    { simde_mm_set_pi32(0xbd93981f, 0x4e9cd8dc), 0x4e9cd8dc, }
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
    { simde_mm_set_pi16(0x8979, 0x98e8, 0x300b, 0x11f9),
      simde_mm_set_pi16(0x05ce, 0x68b9, 0x1e9c, 0x9b33),
      simde_mm_set_pi32(0xd323bc06, 0xfeaae84f) },
    { simde_mm_set_pi16(0x0762, 0x7a49, 0x8a83, 0x09f8),
      simde_mm_set_pi16(0x96d8, 0x8c9c, 0x3bc4, 0x67d2),
      simde_mm_set_pi32(0xc5d9172c, 0xe89d32bc) },
    { simde_mm_set_pi16(0x5770, 0x02b8, 0x6533, 0x9ed4),
      simde_mm_set_pi16(0xd1af, 0x6a76, 0x8322, 0x1e74),
      simde_mm_set_pi32(0xf14fa660, 0xc31459d6) },
    { simde_mm_set_pi16(0x7504, 0xf723, 0x19f1, 0xa621),
      simde_mm_set_pi16(0x1fcf, 0x7715, 0x3c33, 0xc74d),
      simde_mm_set_pi32(0x0a6aa51b, 0x1a0145f0) },
    { simde_mm_set_pi16(0x1dbf, 0x4fa0, 0x14ce, 0xd074),
      simde_mm_set_pi16(0x690d, 0x4bfc, 0x0622, 0xade6),
      simde_mm_set_pi32(0x23d71b33, 0x0fbf4394) },
    { simde_mm_set_pi16(0x542c, 0x206b, 0x92d9, 0xb353),
      simde_mm_set_pi16(0xe189, 0xb2e8, 0x91d3, 0x4980),
      simde_mm_set_pi32(0xec387e84, 0x18f6465b) },
    { simde_mm_set_pi16(0xc622, 0xabc3, 0x0fdd, 0x7d94),
      simde_mm_set_pi16(0x6626, 0x3fd3, 0x8e4e, 0x0eb5),
      simde_mm_set_pi32(0xd3e883c5, 0x002b4cfa) },
    { simde_mm_set_pi16(0xc7f3, 0x7170, 0x2abf, 0xc5c3),
      simde_mm_set_pi16(0x1240, 0x70ba, 0x0571, 0x11a9),
      simde_mm_set_pi32(0x2df47e20, 0xfce41a0a) }
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
    { simde_mm_set_pi16(0x2313, 0x1422, 0xbdae, 0x78d0),
      simde_mm_set_pi16(0x0083, 0x9862, 0x90a4, 0x0c54),
      simde_mm_set_pi16(0x0011, 0xf7d9, 0x1cd9, 0x05d1) },
    { simde_mm_set_pi16(0xaf0c, 0x80ce, 0xef41, 0xd126),
      simde_mm_set_pi16(0xfa81, 0xb003, 0x092e, 0xec08),
      simde_mm_set_pi16(0x01bc, 0x27be, 0xff66, 0x03a7) },
    { simde_mm_set_pi16(0xb4d6, 0xb026, 0x9f1d, 0x6846),
      simde_mm_set_pi16(0x33b1, 0xe5b0, 0x01c9, 0x415b),
      simde_mm_set_pi16(0xf0d2, 0x0835, 0xff53, 0x1a9e) },
    { simde_mm_set_pi16(0xe16a, 0x4a31, 0x07ff, 0x7fdf),
      simde_mm_set_pi16(0x4295, 0xa56c, 0xc089, 0xe71f),
      simde_mm_set_pi16(0xf80b, 0xe5bf, 0xfe04, 0xf392) },
    { simde_mm_set_pi16(0xb095, 0xf915, 0x1c97, 0xf784),
      simde_mm_set_pi16(0x6b51, 0x0e98, 0x680b, 0x9fc8),
      simde_mm_set_pi16(0xdeb5, 0xff9b, 0x0b9e, 0x0330) },
    { simde_mm_set_pi16(0x49af, 0x72ab, 0x562f, 0x61a0),
      simde_mm_set_pi16(0x7b9e, 0x2a62, 0xfb6a, 0x18f2),
      simde_mm_set_pi16(0x2394, 0x12fb, 0xfe74, 0x0983) },
    { simde_mm_set_pi16(0x3277, 0x6cbc, 0xc38f, 0x79fb),
      simde_mm_set_pi16(0xf7fd, 0x1879, 0xc9f1, 0x39cb),
      simde_mm_set_pi16(0xfe6b, 0x0a65, 0x0cc3, 0x1b89) },
    { simde_mm_set_pi16(0xb0d7, 0xf6ad, 0x0765, 0x40de),
      simde_mm_set_pi16(0x7b65, 0xe045, 0x6812, 0x1b46),
      simde_mm_set_pi16(0xd9d8, 0x0127, 0x0301, 0x06e9) }
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
    { simde_mm_set_pi16(0x04db, 0x4fc0, 0x3d33, 0x114e),
      simde_mm_set_pi16(0xe971, 0x6846, 0x4284, 0x5bf1),
      simde_mm_set_pi16(0x77ab, 0xce80, 0xb44c, 0x046e) },
    { simde_mm_set_pi16(0xeb92, 0xaf0a, 0x81d3, 0x10e4),
      simde_mm_set_pi16(0x7ab8, 0x9eda, 0x6f4a, 0x90c6),
      simde_mm_set_pi16(0xe4f0, 0x3a84, 0x03fe, 0x5058) },
    { simde_mm_set_pi16(0x0167, 0x6e9b, 0x759d, 0x76a2),
      simde_mm_set_pi16(0x2c62, 0xa02a, 0xe19d, 0x863a),
      simde_mm_set_pi16(0x3d6e, 0x056e, 0x1e49, 0xacb4) },
    { simde_mm_set_pi16(0xe1fe, 0xbbc0, 0x0465, 0x87f3),
      simde_mm_set_pi16(0x6abb, 0x5326, 0x6eac, 0x9720),
      simde_mm_set_pi16(0x408a, 0x1e80, 0x59dc, 0x5360) },
    { simde_mm_set_pi16(0x6f34, 0xf04b, 0x5b1d, 0xa033),
      simde_mm_set_pi16(0x723a, 0xebf1, 0x2fd1, 0xe9d9),
      simde_mm_set_pi16(0x59c8, 0x0f9b, 0xb5ad, 0x363b) },
    { simde_mm_set_pi16(0xd41f, 0xdbed, 0xa4d4, 0xffc9),
      simde_mm_set_pi16(0xabc1, 0xca87, 0x5424, 0x7fae),
      simde_mm_set_pi16(0xa05f, 0xfbfb, 0xbdd0, 0x919e) },
    { simde_mm_set_pi16(0x607f, 0x9603, 0x33e9, 0x5161),
      simde_mm_set_pi16(0x8014, 0x3d58, 0x298b, 0xc9a9),
      simde_mm_set_pi16(0x09ec, 0x4808, 0x8083, 0xe209) },
    { simde_mm_set_pi16(0xb053, 0xbc73, 0xf80a, 0xa10f),
      simde_mm_set_pi16(0x9d40, 0x0a76, 0xba7a, 0x27f3),
      simde_mm_set_pi16(0xfbc0, 0x5b02, 0x78c4, 0x2a3d), }
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

  for (size_t i = 0 ; i < 32 ; i++) {
    int64_t ai, bi, ri;
    simde__m64 a, b, r;
    munit_rand_memory(sizeof(ai), (uint8_t*) &ai);
    munit_rand_memory(sizeof(bi), (uint8_t*) &bi);

    a = simde_mm_cvtsi64_m64(ai);
    b = simde_mm_cvtsi64_m64(bi);
    r = simde_mm_or_si64(a, b);
    simde_mm_empty();

    ri = ai | bi;

    munit_assert_int64(ri, ==, *((int64_t*) &r));
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
    { simde_mm_set_pi16(0xbc19, 0xd06b, 0xf468, 0x6802),
      simde_mm_set_pi16(0xd8c8, 0x3578, 0x8717, 0xf03b),
      simde_mm_set_pi8 (0x80, 0x7f, 0x80, 0x80,
			0x80, 0x80, 0x80, 0x7f) },
    { simde_mm_set_pi16(0xb11e, 0x302b, 0xa5bb, 0x624a),
      simde_mm_set_pi16(0xfbd1, 0x5029, 0x035c, 0x16f3),
      simde_mm_set_pi8 (0x80, 0x7f, 0x7f, 0x7f,
			0x80, 0x7f, 0x80, 0x7f) },
    { simde_mm_set_pi16(0xd021, 0x33dd, 0x8eea, 0x1485),
      simde_mm_set_pi16(0x62ff, 0xfb1c, 0x0de9, 0x1d72),
      simde_mm_set_pi8 (0x7f, 0x80, 0x7f, 0x7f,
			0x80, 0x7f, 0x80, 0x7f) },
    { simde_mm_set_pi16(0xd40d, 0xad82, 0xf7e3, 0xb090),
      simde_mm_set_pi16(0x5b74, 0x1eda, 0xf20d, 0x241a),
      simde_mm_set_pi8 (0x7f, 0x7f, 0x80, 0x7f,
			0x80, 0x80, 0x80, 0x80) },
    { simde_mm_set_pi16(0x6e14, 0x62fb, 0x4f68, 0x0beb),
      simde_mm_set_pi16(0x799f, 0x0dfd, 0x2d20, 0x61ca),
      simde_mm_set_pi8 (0x7f, 0x7f, 0x7f, 0x7f,
			0x7f, 0x7f, 0x7f, 0x7f) },
    { simde_mm_set_pi16(0x3731, 0xf45a, 0xcc34, 0xd03f),
      simde_mm_set_pi16(0xfdd3, 0xc71c, 0x925f, 0x6424),
      simde_mm_set_pi8 (0x80, 0x80, 0x80, 0x7f,
			0x7f, 0x80, 0x80, 0x80) },
    { simde_mm_set_pi16(0x7a65, 0x513c, 0x419b, 0xebf9),
      simde_mm_set_pi16(0x562c, 0x29b9, 0x705b, 0x0b1f),
      simde_mm_set_pi8 (0x7f, 0x7f, 0x7f, 0x7f,
			0x7f, 0x7f, 0x7f, 0x80) },
    { simde_mm_set_pi16(0x00a7, 0x00e9, 0x0073, 0x007e),
      simde_mm_set_pi16(0x000a, 0x005e, 0x00b5, 0x00e9),
      simde_mm_set_pi8 (0x0a, 0x5e, 0x7f, 0x7f,
			0x7f, 0x7f, 0x73, 0x7e) }
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
    { simde_mm_set_pi32(0xffd41e9c, 0xfffffffc),
      simde_mm_set_pi32(0xffffffcb, 0x000e43e4),
      simde_mm_set_pi16(0xffcb, 0x7fff, 0x8000, 0xfffc) },
    { simde_mm_set_pi32(0x00000001, 0xf3140acf),
      simde_mm_set_pi32(0x00000078, 0xfffa33eb),
      simde_mm_set_pi16(0x0078, 0x8000, 0x0001, 0x8000) },
    { simde_mm_set_pi32(0xffffffee, 0x00000119),
      simde_mm_set_pi32(0xffff7ed8, 0x00000082),
      simde_mm_set_pi16(0x8000, 0x0082, 0xffee, 0x0119) },
    { simde_mm_set_pi32(0xffff35ef, 0x0000000e),
      simde_mm_set_pi32(0x00001ac4, 0xffffffdc),
      simde_mm_set_pi16(0x1ac4, 0xffdc, 0x8000, 0x000e) },
    { simde_mm_set_pi32(0xffffffff, 0xffffff2e),
      simde_mm_set_pi32(0x002e285f, 0x01d860a7),
      simde_mm_set_pi16(0x7fff, 0x7fff, 0xffff, 0xff2e) },
    { simde_mm_set_pi32(0x0000001c, 0x0000037a),
      simde_mm_set_pi32(0xffe1000f, 0xffffeb43),
      simde_mm_set_pi16(0x8000, 0xeb43, 0x001c, 0x037a) },
    { simde_mm_set_pi32(0xffffffb0, 0x00411d82),
      simde_mm_set_pi32(0x02125ab9, 0x0001f081),
      simde_mm_set_pi16(0x7fff, 0x7fff, 0xffb0, 0x7fff) },
    { simde_mm_set_pi32(0xffd5af7d, 0xffffffd6),
      simde_mm_set_pi32(0x00000021, 0x0035eed5),
      simde_mm_set_pi16(0x0021, 0x7fff, 0x8000, 0xffd6) }
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
    { simde_mm_set_pi16(0xfffe, 0x0071, 0x0031, 0xfd79),
      simde_mm_set_pi16(0x0038, 0x0005, 0x0001, 0xffca),
      simde_mm_set_pi8 (0x38, 0x05, 0x01, 0x00,
			0x00, 0x71, 0x31, 0x00) },
    { simde_mm_set_pi16(0xffff, 0xff32, 0xf98e, 0xff93),
      simde_mm_set_pi16(0xf10c, 0x0002, 0x01d7, 0x0002),
      simde_mm_set_pi8 (0x00, 0x02, 0xff, 0x02,
			0x00, 0x00, 0x00, 0x00) },
    { simde_mm_set_pi16(0x0003, 0xfffe, 0x01f4, 0xff9c),
      simde_mm_set_pi16(0xf9da, 0xffff, 0xffff, 0x0002),
      simde_mm_set_pi8 (0x00, 0x00, 0x00, 0x02,
			0x03, 0x00, 0xff, 0x00) },
    { simde_mm_set_pi16(0xfff3, 0xff27, 0x0ce9, 0xfff6),
      simde_mm_set_pi16(0xfe8e, 0x00b5, 0x0001, 0xfa66),
      simde_mm_set_pi8 (0x00, 0xb5, 0x01, 0x00,
			0x00, 0x00, 0xff, 0x00) },
    { simde_mm_set_pi16(0x0363, 0xffc1, 0xfc15, 0x000d),
      simde_mm_set_pi16(0x8b62, 0xfffa, 0x0021, 0x0005),
      simde_mm_set_pi8 (0x00, 0x00, 0x21, 0x05,
			0xff, 0x00, 0x00, 0x0d) },
    { simde_mm_set_pi16(0x0303, 0xffff, 0xfff3, 0xfffe),
      simde_mm_set_pi16(0xffbf, 0x0037, 0x0127, 0x4466),
      simde_mm_set_pi8 (0x00, 0x37, 0xff, 0xff,
			0xff, 0x00, 0x00, 0x00) },
    { simde_mm_set_pi16(0x0032, 0x7e51, 0x000d, 0x4fe1),
      simde_mm_set_pi16(0xfc7f, 0xff8f, 0xf0e6, 0xc271),
      simde_mm_set_pi8 (0x00, 0x00, 0x00, 0x00,
			0x32, 0xff, 0x0d, 0xff) },
    { simde_mm_set_pi16(0x0000, 0x1195, 0x00ca, 0x2614),
      simde_mm_set_pi16(0xfffe, 0xffff, 0xc024, 0xe762),
      simde_mm_set_pi8 (0x00, 0x00, 0x00, 0x00,
			0x00, 0xff, 0xca, 0xff) }
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
    { simde_mm_set_pi16(0xf5cc, 0xe395, 0x6194, 0x31c8),
      simde_mm_cvtsi64_m64(15),
      simde_mm_set_pi16(0x0000, 0x8000, 0x0000, 0x0000) },
    { simde_mm_set_pi16(0x42f7, 0xd120, 0x7dff, 0x1548),
      simde_mm_cvtsi64_m64(10),
      simde_mm_set_pi16(0xdc00, 0x8000, 0xfc00, 0x2000) },
    { simde_mm_set_pi16(0x04c3, 0xb817, 0x60bb, 0x32df),
      simde_mm_cvtsi64_m64(3),
      simde_mm_set_pi16(0x2618, 0xc0b8, 0x05d8, 0x96f8) },
    { simde_mm_set_pi16(0x877b, 0xfe4a, 0xcca2, 0xf65c),
      simde_mm_cvtsi64_m64(10),
      simde_mm_set_pi16(0xec00, 0x2800, 0x8800, 0x7000) },
    { simde_mm_set_pi16(0xb089, 0x77f9, 0x67c6, 0x23fd),
      simde_mm_cvtsi64_m64(7),
      simde_mm_set_pi16(0x4480, 0xfc80, 0xe300, 0xfe80) },
    { simde_mm_set_pi16(0xc7ff, 0xecde, 0x7f92, 0xecb0),
      simde_mm_cvtsi64_m64(5),
      simde_mm_set_pi16(0xffe0, 0x9bc0, 0xf240, 0x9600) },
    { simde_mm_set_pi16(0x5490, 0x6348, 0x4dd1, 0xbe9e),
      simde_mm_cvtsi64_m64(0),
      simde_mm_set_pi16(0x5490, 0x6348, 0x4dd1, 0xbe9e) },
    { simde_mm_set_pi16(0xd780, 0xb3e5, 0xc3cc, 0x8ae5),
      simde_mm_cvtsi64_m64(9),
      simde_mm_set_pi16(0x0000, 0xca00, 0x9800, 0xca00) }
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
    { simde_mm_set_pi32(0x7f4ad262, 0x9ce45b37),
      simde_mm_cvtsi64_m64(10),
      simde_mm_set_pi32(0x2b498800, 0x916cdc00) },
    { simde_mm_set_pi32(0x76509267, 0xfb7918be),
      simde_mm_cvtsi64_m64(14),
      simde_mm_set_pi32(0x2499c000, 0x462f8000) },
    { simde_mm_set_pi32(0xb1961bea, 0x99a67ad1),
      simde_mm_cvtsi64_m64(22),
      simde_mm_set_pi32(0xfa800000, 0xb4400000) },
    { simde_mm_set_pi32(0xcf780e55, 0x2ffc2805),
      simde_mm_cvtsi64_m64(9),
      simde_mm_set_pi32(0xf01caa00, 0xf8500a00) },
    { simde_mm_set_pi32(0xa14be044, 0x7f1e6323),
      simde_mm_cvtsi64_m64(1),
      simde_mm_set_pi32(0x4297c088, 0xfe3cc646) },
    { simde_mm_set_pi32(0x2ea0903c, 0x819cf8de),
      simde_mm_cvtsi64_m64(16),
      simde_mm_set_pi32(0x903c0000, 0xf8de0000) },
    { simde_mm_set_pi32(0x9b698d6c, 0xb4ae77cf),
      simde_mm_cvtsi64_m64(16),
      simde_mm_set_pi32(0x8d6c0000, 0x77cf0000) },
    { simde_mm_set_pi32(0xb4ff9134, 0x3a22907b),
      simde_mm_cvtsi64_m64(5),
      simde_mm_set_pi32(0x9ff22680, 0x44520f60) }
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
    { simde_mm_cvtsi64_m64(UINT64_C(0x2c04f0afbb6ea869)),
      simde_mm_cvtsi64_m64(26),
      simde_mm_cvtsi64_m64(UINT64_C(0xbeedbaa1a4000000)) },
    { simde_mm_cvtsi64_m64(UINT64_C(0x7a46741e0e1d199a)),
      simde_mm_cvtsi64_m64(35),
      simde_mm_cvtsi64_m64(UINT64_C(0x70e8ccd000000000)) },
    { simde_mm_cvtsi64_m64(UINT64_C(0x728909a27299f7e0)),
      simde_mm_cvtsi64_m64(60),
      simde_mm_cvtsi64_m64(UINT64_C(0x0000000000000000)) },
    { simde_mm_cvtsi64_m64(UINT64_C(0xfe7a4be78826c849)),
      simde_mm_cvtsi64_m64(35),
      simde_mm_cvtsi64_m64(UINT64_C(0x4136424800000000)) },
    { simde_mm_cvtsi64_m64(UINT64_C(0x0b12beceffaf415c)),
      simde_mm_cvtsi64_m64(19),
      simde_mm_cvtsi64_m64(UINT64_C(0xf677fd7a0ae00000)) },
    { simde_mm_cvtsi64_m64(UINT64_C(0xdf28bbede8bf899f)),
      simde_mm_cvtsi64_m64(28),
      simde_mm_cvtsi64_m64(UINT64_C(0xde8bf899f0000000)) },
    { simde_mm_cvtsi64_m64(UINT64_C(0x2a161b540172d78c)),
      simde_mm_cvtsi64_m64(28),
      simde_mm_cvtsi64_m64(UINT64_C(0x40172d78c0000000)) },
    { simde_mm_cvtsi64_m64(UINT64_C(0x4fae0c57c0b6e410)),
      simde_mm_cvtsi64_m64(44),
      simde_mm_cvtsi64_m64(UINT64_C(0x6e41000000000000)) }
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
    { simde_mm_set_pi16(0xcb19, 0x18d8, 0xfae6, 0xe8c4),
      6,
      simde_mm_set_pi16(0xc640, 0x3600, 0xb980, 0x3100) },
    { simde_mm_set_pi16(0x196a, 0x908b, 0x0f94, 0x8616),
      10,
      simde_mm_set_pi16(0xa800, 0x2c00, 0x5000, 0x5800) },
    { simde_mm_set_pi16(0x4bbc, 0xee58, 0x256e, 0x2b3b),
      9,
      simde_mm_set_pi16(0x7800, 0xb000, 0xdc00, 0x7600) },
    { simde_mm_set_pi16(0x2ee0, 0x70cc, 0x748a, 0xca52),
      13,
      simde_mm_set_pi16(0x0000, 0x8000, 0x4000, 0x4000) },
    { simde_mm_set_pi16(0x1228, 0xf799, 0x97ef, 0x93f5),
      13,
      simde_mm_set_pi16(0x0000, 0x2000, 0xe000, 0xa000) },
    { simde_mm_set_pi16(0xf6cf, 0x4f5d, 0x1d02, 0x60d4),
      8,
      simde_mm_set_pi16(0xcf00, 0x5d00, 0x0200, 0xd400) },
    { simde_mm_set_pi16(0xe7e2, 0x7b04, 0x6f9f, 0xb061),
      1,
      simde_mm_set_pi16(0xcfc4, 0xf608, 0xdf3e, 0x60c2) },
    { simde_mm_set_pi16(0x895d, 0x43b6, 0x097c, 0xee32),
      5,
      simde_mm_set_pi16(0x2ba0, 0x76c0, 0x2f80, 0xc640) }
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
    { simde_mm_set_pi32(0x04ffee39, 0x50f0b271),
      27,
      simde_mm_set_pi32(0xc8000000, 0x88000000) },
    { simde_mm_set_pi32(0x808c26ce, 0x87a74a01),
      21,
      simde_mm_set_pi32(0xd9c00000, 0x40200000) },
    { simde_mm_set_pi32(0xef396ea2, 0xa32de51c),
      27,
      simde_mm_set_pi32(0x10000000, 0xe0000000) },
    { simde_mm_set_pi32(0xb8065dee, 0xd69715dd),
      7,
      simde_mm_set_pi32(0x032ef700, 0x4b8aee80) },
    { simde_mm_set_pi32(0x35ce5c4f, 0x3837d0e9),
      20,
      simde_mm_set_pi32(0xc4f00000, 0x0e900000) },
    { simde_mm_set_pi32(0x00714779, 0x8a4c973c),
      5,
      simde_mm_set_pi32(0x0e28ef20, 0x4992e780) },
    { simde_mm_set_pi32(0x0a6a1f78, 0xcae36ead),
      23,
      simde_mm_set_pi32(0xbc000000, 0x56800000) },
    { simde_mm_set_pi32(0x08083026, 0x8f1bda56),
      27,
      simde_mm_set_pi32(0x30000000, 0xb0000000) }
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
    { simde_mm_cvtsi64_m64(UINT64_C(0xcd43562d622ff9b1)),
      37,
      simde_mm_cvtsi64_m64(UINT64_C(0x45ff362000000000)) },
    { simde_mm_cvtsi64_m64(UINT64_C(0x4a92fbd485a9b75f)),
      49,
      simde_mm_cvtsi64_m64(UINT64_C(0x6ebe000000000000)) },
    { simde_mm_cvtsi64_m64(UINT64_C(0x0d43ccc2a755e98b)),
      11,
      simde_mm_cvtsi64_m64(UINT64_C(0x1e66153aaf4c5800)) },
    { simde_mm_cvtsi64_m64(UINT64_C(0x3d8d216dac296ce8)),
      32,
      simde_mm_cvtsi64_m64(UINT64_C(0xac296ce800000000)) },
    { simde_mm_cvtsi64_m64(UINT64_C(0x0712ddca397d1f67)),
      0,
      simde_mm_cvtsi64_m64(UINT64_C(0x0712ddca397d1f67)) },
    { simde_mm_cvtsi64_m64(UINT64_C(0x2aec7cc06c8e582f)),
      24,
      simde_mm_cvtsi64_m64(UINT64_C(0xc06c8e582f000000)) },
    { simde_mm_cvtsi64_m64(UINT64_C(0x829e3515410b7239)),
      38,
      simde_mm_cvtsi64_m64(UINT64_C(0x42dc8e4000000000)) },
    { simde_mm_cvtsi64_m64(UINT64_C(0x73e930dce2b1e174)),
      34,
      simde_mm_cvtsi64_m64(UINT64_C(0x8ac785d000000000)) }
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
    { simde_mm_set_pi16(0xf075, 0x8ac3, 0x5934, 0x1d0e),
      simde_mm_cvtsi64_m64(5),
      simde_mm_set_pi16(0x0783, 0x0456, 0x02c9, 0x00e8) },
    { simde_mm_set_pi16(0xba1f, 0x8621, 0x08b9, 0x71f8),
      simde_mm_cvtsi64_m64(9),
      simde_mm_set_pi16(0x005d, 0x0043, 0x0004, 0x0038) },
    { simde_mm_set_pi16(0xc810, 0x8d5b, 0xed98, 0x0bd7),
      simde_mm_cvtsi64_m64(6),
      simde_mm_set_pi16(0x0320, 0x0235, 0x03b6, 0x002f) },
    { simde_mm_set_pi16(0x7022, 0xc4f7, 0xf329, 0xcad7),
      simde_mm_cvtsi64_m64(13),
      simde_mm_set_pi16(0x0003, 0x0006, 0x0007, 0x0006) },
    { simde_mm_set_pi16(0xef04, 0x37f4, 0x30cb, 0x8005),
      simde_mm_cvtsi64_m64(2),
      simde_mm_set_pi16(0x3bc1, 0x0dfd, 0x0c32, 0x2001) },
    { simde_mm_set_pi16(0xfa52, 0xf3c0, 0x4204, 0x9966),
      simde_mm_cvtsi64_m64(11),
      simde_mm_set_pi16(0x001f, 0x001e, 0x0008, 0x0013) },
    { simde_mm_set_pi16(0x59f8, 0x5229, 0x081a, 0x8990),
      simde_mm_cvtsi64_m64(9),
      simde_mm_set_pi16(0x002c, 0x0029, 0x0004, 0x0044) },
    { simde_mm_set_pi16(0x0963, 0x17b6, 0xc003, 0x3b5e),
      simde_mm_cvtsi64_m64(10),
      simde_mm_set_pi16(0x0002, 0x0005, 0x0030, 0x000e) }
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
    { simde_mm_set_pi32(0x45500e39, 0x29ce91a0),
      simde_mm_cvtsi64_m64(12),
      simde_mm_set_pi32(0x00045500, 0x00029ce9) },
    { simde_mm_set_pi32(0x98e22875, 0x5841f889),
      simde_mm_cvtsi64_m64(7),
      simde_mm_set_pi32(0x0131c450, 0x00b083f1) },
    { simde_mm_set_pi32(0x878f4877, 0xff28f0c5),
      simde_mm_cvtsi64_m64(9),
      simde_mm_set_pi32(0x0043c7a4, 0x007f9478) },
    { simde_mm_set_pi32(0x48326f60, 0xdf3c5d81),
      simde_mm_cvtsi64_m64(13),
      simde_mm_set_pi32(0x00024193, 0x0006f9e2) },
    { simde_mm_set_pi32(0x1f65e5a9, 0xae33f533),
      simde_mm_cvtsi64_m64(6),
      simde_mm_set_pi32(0x007d9796, 0x02b8cfd4) },
    { simde_mm_set_pi32(0x0f5d5327, 0x54fc0ab6),
      simde_mm_cvtsi64_m64(0),
      simde_mm_set_pi32(0x0f5d5327, 0x54fc0ab6) },
    { simde_mm_set_pi32(0x2cc48188, 0x8c7f8abd),
      simde_mm_cvtsi64_m64(6),
      simde_mm_set_pi32(0x00b31206, 0x0231fe2a) },
    { simde_mm_set_pi32(0xd60f89f8, 0x5881863d),
      simde_mm_cvtsi64_m64(14),
      simde_mm_set_pi32(0x0003583e, 0x00016206) }
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
    { simde_mm_cvtsi64_m64(UINT64_C(0xea7aa541209e78a3)),
      simde_mm_cvtsi64_m64(27),
      simde_mm_cvtsi64_m64(UINT64_C(0x0000001d4f54a824)) },
    { simde_mm_cvtsi64_m64(UINT64_C(0xbbec34bf863cb4d4)),
      simde_mm_cvtsi64_m64(51),
      simde_mm_cvtsi64_m64(UINT64_C(0x000000000000177d)) },
    { simde_mm_cvtsi64_m64(UINT64_C(0x0ae429e18cbb8916)),
      simde_mm_cvtsi64_m64(61),
      simde_mm_cvtsi64_m64(UINT64_C(0x0000000000000000)) },
    { simde_mm_cvtsi64_m64(UINT64_C(0x9c9f203aff59da8a)),
      simde_mm_cvtsi64_m64(36),
      simde_mm_cvtsi64_m64(UINT64_C(0x0000000009c9f203)) },
    { simde_mm_cvtsi64_m64(UINT64_C(0xfe491dcbefe1048e)),
      simde_mm_cvtsi64_m64(20),
      simde_mm_cvtsi64_m64(UINT64_C(0x00000fe491dcbefe)) },
    { simde_mm_cvtsi64_m64(UINT64_C(0x4f62e48272d323ba)),
      simde_mm_cvtsi64_m64(33),
      simde_mm_cvtsi64_m64(UINT64_C(0x0000000027b17241)) },
    { simde_mm_cvtsi64_m64(UINT64_C(0xd0d70b418df5be8a)),
      simde_mm_cvtsi64_m64(63),
      simde_mm_cvtsi64_m64(UINT64_C(0x0000000000000001)) },
    { simde_mm_cvtsi64_m64(UINT64_C(0xb5abd94b7f048cf1)),
      simde_mm_cvtsi64_m64(7),
      simde_mm_cvtsi64_m64(UINT64_C(0x016b57b296fe0919)) }
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
    { simde_mm_set_pi16(0xc2ae, 0x81ca, 0x0153, 0x0da8),
      10,
      simde_mm_set_pi16(0x0030, 0x0020, 0x0000, 0x0003) },
    { simde_mm_set_pi16(0x9581, 0xb910, 0xaff9, 0xad4b),
      6,
      simde_mm_set_pi16(0x0256, 0x02e4, 0x02bf, 0x02b5) },
    { simde_mm_set_pi16(0x5cfd, 0xc5a3, 0x199e, 0xa2a8),
      6,
      simde_mm_set_pi16(0x0173, 0x0316, 0x0066, 0x028a) },
    { simde_mm_set_pi16(0x5806, 0x9522, 0xdaef, 0xc19c),
      7,
      simde_mm_set_pi16(0x00b0, 0x012a, 0x01b5, 0x0183) },
    { simde_mm_set_pi16(0x08a4, 0x8dd9, 0xb2b9, 0xeff7),
      0,
      simde_mm_set_pi16(0x08a4, 0x8dd9, 0xb2b9, 0xeff7) },
    { simde_mm_set_pi16(0x5fef, 0xaaa6, 0x884a, 0x53af),
      14,
      simde_mm_set_pi16(0x0001, 0x0002, 0x0002, 0x0001) },
    { simde_mm_set_pi16(0xf357, 0x84ee, 0x0e4e, 0x41a5),
      5,
      simde_mm_set_pi16(0x079a, 0x0427, 0x0072, 0x020d) },
    { simde_mm_set_pi16(0xca93, 0x1bcd, 0xc339, 0xdf50),
      14,
      simde_mm_set_pi16(0x0003, 0x0000, 0x0003, 0x0003) }
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
    { simde_mm_set_pi32(0x06eb9f8e, 0xdb7ca4b4),
      14,
      simde_mm_set_pi32(0x00001bae, 0x00036df2) },
    { simde_mm_set_pi32(0xde11ef32, 0x3ef12f10),
      8,
      simde_mm_set_pi32(0x00de11ef, 0x003ef12f) },
    { simde_mm_set_pi32(0x32c19cf4, 0xb074f693),
      15,
      simde_mm_set_pi32(0x00006583, 0x000160e9) },
    { simde_mm_set_pi32(0xa504922a, 0x07c97d7c),
      14,
      simde_mm_set_pi32(0x00029412, 0x00001f25) },
    { simde_mm_set_pi32(0x92c20b1b, 0xfe4899a0),
      0,
      simde_mm_set_pi32(0x92c20b1b, 0xfe4899a0) },
    { simde_mm_set_pi32(0xa550f015, 0x0db9339b),
      4,
      simde_mm_set_pi32(0x0a550f01, 0x00db9339) },
    { simde_mm_set_pi32(0x3a86be3b, 0xd26a9556),
      15,
      simde_mm_set_pi32(0x0000750d, 0x0001a4d5) },
    { simde_mm_set_pi32(0x8f650e77, 0x57c7dfe5),
      10,
      simde_mm_set_pi32(0x0023d943, 0x0015f1f7) }
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
    { simde_mm_cvtsi64_m64(UINT64_C(0x8ce4027b1e0d360e)),
      62,
      simde_mm_cvtsi64_m64(UINT64_C(0x0000000000000002)) },
    { simde_mm_cvtsi64_m64(UINT64_C(0x6186090de6e3b8c5)),
      7,
      simde_mm_cvtsi64_m64(UINT64_C(0x00c30c121bcdc771)) },
    { simde_mm_cvtsi64_m64(UINT64_C(0x24c5ffa8091448c9)),
      19,
      simde_mm_cvtsi64_m64(UINT64_C(0x00000498bff50122)) },
    { simde_mm_cvtsi64_m64(UINT64_C(0x0acdfc81055556b5)),
      12,
      simde_mm_cvtsi64_m64(UINT64_C(0x0000acdfc8105555)) },
    { simde_mm_cvtsi64_m64(UINT64_C(0x142c9011f8b32d28)),
      17,
      simde_mm_cvtsi64_m64(UINT64_C(0x00000a164808fc59)) },
    { simde_mm_cvtsi64_m64(UINT64_C(0x0b94e13d3efa50ab)),
      22,
      simde_mm_cvtsi64_m64(UINT64_C(0x0000002e5384f4fb)) },
    { simde_mm_cvtsi64_m64(UINT64_C(0x1a24842798802ebd)),
      12,
      simde_mm_cvtsi64_m64(UINT64_C(0x0001a24842798802)) },
    { simde_mm_cvtsi64_m64(UINT64_C(0x6e47a6cda4f29c7c)),
      61,
      simde_mm_cvtsi64_m64(UINT64_C(0x0000000000000003)) }
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
    { simde_mm_set_pi16(0x81fd, 0xd76a, 0x6fd3, 0x493b),
      6,
      simde_mm_set_pi16(0xfe07, 0xff5d, 0x01bf, 0x0124) },
    { simde_mm_set_pi16(0xfed4, 0xf342, 0xf4d3, 0xd383),
      15,
      simde_mm_set_pi16(0xffff, 0xffff, 0xffff, 0xffff) },
    { simde_mm_set_pi16(0x1950, 0xc2bc, 0x0e03, 0x1ea4),
      2,
      simde_mm_set_pi16(0x0654, 0xf0af, 0x0380, 0x07a9) },
    { simde_mm_set_pi16(0xe864, 0xc1b6, 0x06b9, 0x89bf),
      5,
      simde_mm_set_pi16(0xff43, 0xfe0d, 0x0035, 0xfc4d) },
    { simde_mm_set_pi16(0x6021, 0x385f, 0x077d, 0xcc88),
      13,
      simde_mm_set_pi16(0x0003, 0x0001, 0x0000, 0xfffe) },
    { simde_mm_set_pi16(0x3507, 0x7f62, 0xed65, 0x29fc),
      12,
      simde_mm_set_pi16(0x0003, 0x0007, 0xfffe, 0x0002) },
    { simde_mm_set_pi16(0xf4f8, 0x6f43, 0xa439, 0xbca7),
      11,
      simde_mm_set_pi16(0xfffe, 0x000d, 0xfff4, 0xfff7) },
    { simde_mm_set_pi16(0xeb52, 0x7264, 0xf22a, 0x552e),
      10,
      simde_mm_set_pi16(0xfffa, 0x001c, 0xfffc, 0x0015) }
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
    { simde_mm_set_pi32(0x81fdd76a, 0x6fd3493b),
      6,
      simde_mm_set_pi32(0xfe07f75d, 0x01bf4d24) },
    { simde_mm_set_pi32(0xfed4f342, 0xf4d3d383),
      15,
      simde_mm_set_pi32(0xfffffda9, 0xffffe9a7) },
    { simde_mm_set_pi32(0x1950c2bc, 0x0e031ea4),
      2,
      simde_mm_set_pi32(0x065430af, 0x0380c7a9) },
    { simde_mm_set_pi32(0xe864c1b6, 0x06b989bf),
      5,
      simde_mm_set_pi32(0xff43260d, 0x0035cc4d) },
    { simde_mm_set_pi32(0x6021385f, 0x077dcc88),
      13,
      simde_mm_set_pi32(0x00030109, 0x00003bee) },
    { simde_mm_set_pi32(0x35077f62, 0xed6529fc),
      12,
      simde_mm_set_pi32(0x00035077, 0xfffed652) },
    { simde_mm_set_pi32(0xf4f86f43, 0xa439bca7),
      11,
      simde_mm_set_pi32(0xfffe9f0d, 0xfff48737) },
    { simde_mm_set_pi32(0xeb527264, 0xf22a552e),
      10,
      simde_mm_set_pi32(0xfffad49c, 0xfffc8a95) }
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
    { simde_mm_set_pi16(0x4499, 0x28f9, 0x8f69, 0x80e3),
      simde_mm_cvtsi64_m64(11),
      simde_mm_set_pi16(0x0008, 0x0005, 0xfff1, 0xfff0) },
    { simde_mm_set_pi16(0xa294, 0x572f, 0x9f65, 0x9e8c),
      simde_mm_cvtsi64_m64(6),
      simde_mm_set_pi16(0xfe8a, 0x015c, 0xfe7d, 0xfe7a) },
    { simde_mm_set_pi16(0x2841, 0x8b59, 0x9ab7, 0x67d6),
      simde_mm_cvtsi64_m64(4),
      simde_mm_set_pi16(0x0284, 0xf8b5, 0xf9ab, 0x067d) },
    { simde_mm_set_pi16(0xd173, 0x1bfd, 0x035c, 0xe43c),
      simde_mm_cvtsi64_m64(3),
      simde_mm_set_pi16(0xfa2e, 0x037f, 0x006b, 0xfc87) },
    { simde_mm_set_pi16(0x7788, 0x0c4a, 0xa6c7, 0x942f),
      simde_mm_cvtsi64_m64(0),
      simde_mm_set_pi16(0x7788, 0x0c4a, 0xa6c7, 0x942f) },
    { simde_mm_set_pi16(0x1f10, 0x215e, 0x93a8, 0x4f41),
      simde_mm_cvtsi64_m64(1),
      simde_mm_set_pi16(0x0f88, 0x10af, 0xc9d4, 0x27a0) },
    { simde_mm_set_pi16(0x9fee, 0xdda4, 0x9d95, 0x012c),
      simde_mm_cvtsi64_m64(10),
      simde_mm_set_pi16(0xffe7, 0xfff7, 0xffe7, 0x0000) },
    { simde_mm_set_pi16(0x2550, 0x5059, 0x072e, 0x6711),
      simde_mm_cvtsi64_m64(9),
      simde_mm_set_pi16(0x0012, 0x0028, 0x0003, 0x0033) }
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
    { simde_mm_set_pi32(0x8db8106b, 0xad890e21),
      simde_mm_cvtsi64_m64(15),
      simde_mm_set_pi32(0xffff1b70, 0xffff5b12) },
    { simde_mm_set_pi32(0xd4131b79, 0x3332ed1d),
      simde_mm_cvtsi64_m64(18),
      simde_mm_set_pi32(0xfffff504, 0x00000ccc) },
    { simde_mm_set_pi32(0x3c9a00e5, 0x99b1853a),
      simde_mm_cvtsi64_m64(20),
      simde_mm_set_pi32(0x000003c9, 0xfffff99b) },
    { simde_mm_set_pi32(0x34bef1ff, 0x82402227),
      simde_mm_cvtsi64_m64(17),
      simde_mm_set_pi32(0x00001a5f, 0xffffc120) },
    { simde_mm_set_pi32(0x69520025, 0x59c222cc),
      simde_mm_cvtsi64_m64(8),
      simde_mm_set_pi32(0x00695200, 0x0059c222) },
    { simde_mm_set_pi32(0x674363ed, 0x82451df9),
      simde_mm_cvtsi64_m64(22),
      simde_mm_set_pi32(0x0000019d, 0xfffffe09) },
    { simde_mm_set_pi32(0xb80b7625, 0x395df638),
      simde_mm_cvtsi64_m64(24),
      simde_mm_set_pi32(0xffffffb8, 0x00000039) },
    { simde_mm_set_pi32(0x1ef82555, 0x466d6c1c),
      simde_mm_cvtsi64_m64(2),
      simde_mm_set_pi32(0x07be0955, 0x119b5b07) }
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
    { simde_mm_set_pi8(0xbc, 0x80, 0x92, 0xd2, 0x40, 0xa9, 0x7b, 0x53),
      simde_mm_set_pi8(0xd4, 0xe5, 0x82, 0x2f, 0xfb, 0x7c, 0x91, 0x58),
      simde_mm_set_pi8(0xe8, 0x9b, 0x10, 0xa3, 0x45, 0x2d, 0xea, 0xfb) },
    { simde_mm_set_pi8(0x07, 0x44, 0xcb, 0xae, 0x32, 0x95, 0x6d, 0x21),
      simde_mm_set_pi8(0x79, 0x32, 0x1f, 0x50, 0x76, 0x08, 0xb7, 0x26),
      simde_mm_set_pi8(0x8e, 0x12, 0xac, 0x5e, 0xbc, 0x8d, 0xb6, 0xfb) },
    { simde_mm_set_pi8(0x3c, 0x05, 0x04, 0xab, 0xc3, 0x47, 0xed, 0xa4),
      simde_mm_set_pi8(0xcd, 0x76, 0x63, 0x0e, 0x7c, 0x8d, 0x31, 0x13),
      simde_mm_set_pi8(0x6f, 0x8f, 0xa1, 0x9d, 0x47, 0xba, 0xbc, 0x91) },
    { simde_mm_set_pi8(0x50, 0x2f, 0x2e, 0xf3, 0x5e, 0xbb, 0xb8, 0xe4),
      simde_mm_set_pi8(0x2d, 0x63, 0x0e, 0x04, 0x59, 0xb3, 0xfc, 0x6d),
      simde_mm_set_pi8(0x23, 0xcc, 0x20, 0xef, 0x05, 0x08, 0xbc, 0x77) },
    { simde_mm_set_pi8(0x75, 0x9b, 0xca, 0xce, 0x37, 0x9f, 0xb6, 0x4f),
      simde_mm_set_pi8(0x74, 0x13, 0x54, 0x5a, 0xf1, 0xcf, 0x22, 0x84),
      simde_mm_set_pi8(0x01, 0x88, 0x76, 0x74, 0x46, 0xd0, 0x94, 0xcb) },
    { simde_mm_set_pi8(0x2b, 0xa8, 0x07, 0xe1, 0xd3, 0xfa, 0xc3, 0xd1),
      simde_mm_set_pi8(0x92, 0x57, 0x9a, 0xc1, 0xdd, 0x4e, 0x60, 0x33),
      simde_mm_set_pi8(0x99, 0x51, 0x6d, 0x20, 0xf6, 0xac, 0x63, 0x9e) },
    { simde_mm_set_pi8(0x8f, 0xc2, 0x8b, 0x22, 0xd8, 0x18, 0xec, 0x34),
      simde_mm_set_pi8(0x35, 0xf0, 0x4b, 0x26, 0x02, 0xb5, 0xcd, 0x5c),
      simde_mm_set_pi8(0x5a, 0xd2, 0x40, 0xfc, 0xd6, 0x63, 0x1f, 0xd8) },
    { simde_mm_set_pi8(0xa2, 0xff, 0xba, 0x5a, 0x97, 0xec, 0xb9, 0xa1),
      simde_mm_set_pi8(0x9f, 0x31, 0x47, 0x45, 0xd0, 0x1f, 0xed, 0x1c),
      simde_mm_set_pi8(0x03, 0xce, 0x73, 0x15, 0xc7, 0xcd, 0xcc, 0x85) }
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
    { simde_mm_set_pi16(0xb385, 0x3111, 0x47a9, 0x3fbf),
      simde_mm_set_pi16(0x9186, 0x320b, 0xbd6e, 0x7fb6),
      simde_mm_set_pi16(0x21ff, 0xff06, 0x8a3b, 0xc009) },
    { simde_mm_set_pi16(0x6715, 0xbfc8, 0x79d9, 0x440c),
      simde_mm_set_pi16(0xbe7c, 0x8939, 0x3394, 0xf092),
      simde_mm_set_pi16(0xa899, 0x368f, 0x4645, 0x537a) },
    { simde_mm_set_pi16(0x698d, 0xaca3, 0x8bbb, 0x934f),
      simde_mm_set_pi16(0x7dff, 0xd197, 0xbca9, 0x453f),
      simde_mm_set_pi16(0xeb8e, 0xdb0c, 0xcf12, 0x4e10) },
    { simde_mm_set_pi16(0xfbdb, 0x29c3, 0x151a, 0x8bad),
      simde_mm_set_pi16(0xf3df, 0x4423, 0x73f3, 0xedc3),
      simde_mm_set_pi16(0x07fc, 0xe5a0, 0xa127, 0x9dea) },
    { simde_mm_set_pi16(0x94db, 0xa21a, 0x95de, 0x5da6),
      simde_mm_set_pi16(0x679f, 0xa333, 0x3216, 0x6212),
      simde_mm_set_pi16(0x2d3c, 0xfee7, 0x63c8, 0xfb94) },
    { simde_mm_set_pi16(0xaa10, 0x7a45, 0x0bcb, 0x14c7),
      simde_mm_set_pi16(0x4351, 0xec7d, 0x8194, 0x33b1),
      simde_mm_set_pi16(0x66bf, 0x8dc8, 0x8a37, 0xe116) },
    { simde_mm_set_pi16(0xf262, 0xf8f7, 0x19ad, 0xf675),
      simde_mm_set_pi16(0x3016, 0x0022, 0xb18e, 0x9dd8),
      simde_mm_set_pi16(0xc24c, 0xf8d5, 0x681f, 0x589d) },
    { simde_mm_set_pi16(0xef84, 0x4462, 0x1b3d, 0xddbd),
      simde_mm_set_pi16(0x8ee7, 0x4f6e, 0x77d9, 0xf2ff),
      simde_mm_set_pi16(0x609d, 0xf4f4, 0xa364, 0xeabe) }
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
    { simde_mm_set_pi32(0x5b2894f3, 0xd82da4dc),
      simde_mm_set_pi32(0x1c34f9b1, 0xfa9aa078),
      simde_mm_set_pi32(0x3ef39b42, 0xdd930464) },
    { simde_mm_set_pi32(0x8cdc272d, 0xd4f40796),
      simde_mm_set_pi32(0xb1fc455f, 0xe9609f01),
      simde_mm_set_pi32(0xdadfe1ce, 0xeb936895) },
    { simde_mm_set_pi32(0xee9a8e20, 0xf4a73a8e),
      simde_mm_set_pi32(0x080c90eb, 0x6a943ecb),
      simde_mm_set_pi32(0xe68dfd35, 0x8a12fbc3) },
    { simde_mm_set_pi32(0x70454a2b, 0x134c43d0),
      simde_mm_set_pi32(0x267a666c, 0x26d5128a),
      simde_mm_set_pi32(0x49cae3bf, 0xec773146) },
    { simde_mm_set_pi32(0x61864b05, 0x969899b2),
      simde_mm_set_pi32(0x1172d80c, 0xfb2521f6),
      simde_mm_set_pi32(0x501372f9, 0x9b7377bc) },
    { simde_mm_set_pi32(0xb84626ee, 0x553e92c8),
      simde_mm_set_pi32(0x467376f9, 0x9127035b),
      simde_mm_set_pi32(0x71d2aff5, 0xc4178f6d) },
    { simde_mm_set_pi32(0xfb2a0282, 0x0958ca81),
      simde_mm_set_pi32(0x53f6e598, 0xb1972416),
      simde_mm_set_pi32(0xa7331cea, 0x57c1a66b) },
    { simde_mm_set_pi32(0xfa156a9e, 0xa4004057),
      simde_mm_set_pi32(0x483b8743, 0x133dc78d),
      simde_mm_set_pi32(0xb1d9e35b, 0x90c278ca) }
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
    { simde_mm_set_pi8(0x2f, 0xcd, 0xf7, 0x2e, 0x25, 0x7d, 0x87, 0x58),
      simde_mm_set_pi8(0xdb, 0xc5, 0xee, 0xd9, 0xbc, 0x7f, 0xbe, 0xf2),
      simde_mm_set_pi8(0x54, 0x08, 0x09, 0x55, 0x69, 0xfe, 0xc9, 0x66) },
    { simde_mm_set_pi8(0xbc, 0x6f, 0x36, 0xfe, 0xa0, 0xe2, 0x07, 0xff),
      simde_mm_set_pi8(0x47, 0x6d, 0x2b, 0xe4, 0x80, 0x9e, 0x41, 0xaa),
      simde_mm_set_pi8(0x80, 0x02, 0x0b, 0x1a, 0x20, 0x44, 0xc6, 0x55) },
    { simde_mm_set_pi8(0x84, 0x97, 0x27, 0x44, 0xd4, 0xc4, 0xd4, 0x9d),
      simde_mm_set_pi8(0xf7, 0x81, 0x4d, 0xf2, 0xba, 0xd9, 0xee, 0xd8),
      simde_mm_set_pi8(0x8d, 0x16, 0xda, 0x52, 0x1a, 0xeb, 0xe6, 0xc5) },
    { simde_mm_set_pi8(0x34, 0x21, 0x61, 0x27, 0x82, 0xf5, 0x11, 0x6c),
      simde_mm_set_pi8(0x41, 0x70, 0x6c, 0x21, 0x44, 0x99, 0xd3, 0x07),
      simde_mm_set_pi8(0xf3, 0xb1, 0xf5, 0x06, 0x80, 0x5c, 0x3e, 0x65) },
    { simde_mm_set_pi8(0x97, 0x4b, 0x7f, 0xc7, 0x58, 0xe7, 0xb5, 0xb6),
      simde_mm_set_pi8(0x83, 0xaf, 0x3c, 0x94, 0x4e, 0xc4, 0x58, 0x1e),
      simde_mm_set_pi8(0x14, 0x7f, 0x43, 0x33, 0x0a, 0x23, 0x80, 0x98) },
    { simde_mm_set_pi8(0xe4, 0x9f, 0x50, 0xd5, 0xba, 0x2d, 0x0a, 0xbd),
      simde_mm_set_pi8(0x93, 0x61, 0x19, 0x3f, 0xbf, 0xa1, 0x91, 0xd9),
      simde_mm_set_pi8(0x51, 0x80, 0x37, 0x96, 0xfb, 0x7f, 0x79, 0xe4) },
    { simde_mm_set_pi8(0x34, 0xee, 0xaa, 0xe3, 0x45, 0x5c, 0x59, 0xbe),
      simde_mm_set_pi8(0x10, 0x00, 0x5f, 0x5f, 0x73, 0xcb, 0x37, 0x4b),
      simde_mm_set_pi8(0x24, 0xee, 0x80, 0x84, 0xd2, 0x7f, 0x22, 0x80) },
    { simde_mm_set_pi8(0x63, 0xd0, 0x10, 0x7e, 0x92, 0x91, 0xbe, 0x53),
      simde_mm_set_pi8(0x8a, 0x76, 0x64, 0x87, 0xef, 0x4a, 0xd1, 0xb3),
      simde_mm_set_pi8(0x7f, 0x80, 0xac, 0x7f, 0xa3, 0x80, 0xed, 0x7f) }
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
    { simde_mm_set_pi8(0x6c, 0x98, 0x6a, 0x5b, 0x36, 0x5f, 0xaa, 0xbc),
      simde_mm_set_pi8(0xb7, 0xf4, 0x0d, 0xf9, 0x9a, 0xe5, 0xa3, 0xff),
      simde_mm_set_pi8(0x00, 0x00, 0x5d, 0x00, 0x00, 0x00, 0x07, 0x00) },
    { simde_mm_set_pi8(0xfd, 0x86, 0x92, 0xa9, 0xe4, 0xda, 0x1e, 0xea),
      simde_mm_set_pi8(0xe8, 0x5c, 0xad, 0xa6, 0x94, 0x8b, 0x65, 0xc6),
      simde_mm_set_pi8(0x15, 0x2a, 0x00, 0x03, 0x50, 0x4f, 0x00, 0x24) },
    { simde_mm_set_pi8(0xce, 0x33, 0xf9, 0xbc, 0xf9, 0x0b, 0x0f, 0x02),
      simde_mm_set_pi8(0xfc, 0x9b, 0x96, 0xd5, 0x84, 0x01, 0xed, 0x12),
      simde_mm_set_pi8(0x00, 0x00, 0x63, 0x00, 0x75, 0x0a, 0x00, 0x00) },
    { simde_mm_set_pi8(0x14, 0xdf, 0x9d, 0xfc, 0x89, 0x48, 0x68, 0xd5),
      simde_mm_set_pi8(0xe5, 0x74, 0x7f, 0x47, 0x6e, 0x2f, 0x38, 0xee),
      simde_mm_set_pi8(0x00, 0x6b, 0x1e, 0xb5, 0x1b, 0x19, 0x30, 0x00) },
    { simde_mm_set_pi8(0x18, 0x2c, 0x7e, 0xf0, 0x30, 0x77, 0x7a, 0x5c),
      simde_mm_set_pi8(0xcb, 0x5d, 0x7b, 0x2b, 0xff, 0xaa, 0x0c, 0xd8),
      simde_mm_set_pi8(0x00, 0x00, 0x03, 0xc5, 0x00, 0x00, 0x6e, 0x00) },
    { simde_mm_set_pi8(0x2b, 0xe3, 0x48, 0xf0, 0x49, 0x24, 0x26, 0x86),
      simde_mm_set_pi8(0x44, 0x11, 0x97, 0x70, 0x7b, 0x8a, 0x25, 0x23),
      simde_mm_set_pi8(0x00, 0xd2, 0x00, 0x80, 0x00, 0x00, 0x01, 0x63) },
    { simde_mm_set_pi8(0x4e, 0x19, 0x85, 0x8e, 0x38, 0x21, 0xca, 0x2e),
      simde_mm_set_pi8(0xb9, 0x71, 0xcc, 0xeb, 0x90, 0xd3, 0x75, 0xa5),
      simde_mm_set_pi8(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x55, 0x00) },
    { simde_mm_set_pi8(0x23, 0x38, 0x6a, 0x76, 0xf4, 0xa4, 0xe8, 0x5d),
      simde_mm_set_pi8(0x8a, 0xe6, 0xd1, 0x56, 0xbb, 0x2b, 0x75, 0x65),
      simde_mm_set_pi8(0x00, 0x00, 0x00, 0x20, 0x39, 0x79, 0x73, 0x00) }
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
    { simde_mm_set_pi16(0x03e5, 0xf58c, 0x8db8, 0xabe2),
      simde_mm_set_pi16(0x61e1, 0xde46, 0x38e4, 0x5ba4),
      simde_mm_set_pi16(0xa204, 0x1746, 0x8000, 0x8000) },
    { simde_mm_set_pi16(0x456d, 0xac7d, 0xd8e0, 0x9e1f),
      simde_mm_set_pi16(0xbbaa, 0xe9a1, 0xa2c7, 0xcff7),
      simde_mm_set_pi16(0x7fff, 0xc2dc, 0x3619, 0xce28) },
    { simde_mm_set_pi16(0xb75d, 0x9c51, 0x642f, 0x46a1),
      simde_mm_set_pi16(0xbea6, 0x2182, 0xa17d, 0xa59e),
      simde_mm_set_pi16(0xf8b7, 0x8000, 0x7fff, 0x7fff) },
    { simde_mm_set_pi16(0x7873, 0xf894, 0xcf4f, 0x81ef),
      simde_mm_set_pi16(0x56c4, 0x7282, 0x76a1, 0xe2ce),
      simde_mm_set_pi16(0x21af, 0x8612, 0x8000, 0x9f21) },
    { simde_mm_set_pi16(0xee61, 0xd245, 0xfe38, 0x134b),
      simde_mm_set_pi16(0x255c, 0xe669, 0x3e0c, 0x653c),
      simde_mm_set_pi16(0xc905, 0xebdc, 0xc02c, 0xae0f) },
    { simde_mm_set_pi16(0x416b, 0x6603, 0x7035, 0xdaef),
      simde_mm_set_pi16(0x489d, 0x2a26, 0x3eae, 0x1df6),
      simde_mm_set_pi16(0xf8ce, 0x3bdd, 0x3187, 0xbcf9) },
    { simde_mm_set_pi16(0x2fc6, 0x7c4a, 0xb050, 0x720a),
      simde_mm_set_pi16(0x3538, 0x938e, 0xf17b, 0x248d),
      simde_mm_set_pi16(0xfa8e, 0x7fff, 0xbed5, 0x4d7d) },
    { simde_mm_set_pi16(0x107f, 0x5671, 0x6c22, 0x17e0),
      simde_mm_set_pi16(0x6376, 0x05d9, 0xb11d, 0x857d),
      simde_mm_set_pi16(0xad09, 0x5098, 0x7fff, 0x7fff) }
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
    { simde_mm_set_pi16(0xc5ab, 0x036a, 0xcdf4, 0xa386),
      simde_mm_set_pi16(0x27d7, 0xab7e, 0xc023, 0xf747),
      simde_mm_set_pi16(0x9dd4, 0x0000, 0x0dd1, 0x0000) },
    { simde_mm_set_pi16(0x8935, 0x3843, 0x3e93, 0xe3bd),
      simde_mm_set_pi16(0x5149, 0x7759, 0xcbdc, 0xdcc5),
      simde_mm_set_pi16(0x37ec, 0x0000, 0x0000, 0x06f8) },
    { simde_mm_set_pi16(0xf341, 0x42e9, 0x1bd0, 0x4485),
      simde_mm_set_pi16(0x455e, 0xa12f, 0xbe4f, 0x98f3),
      simde_mm_set_pi16(0xade3, 0x0000, 0x0000, 0x0000) },
    { simde_mm_set_pi16(0x6e5d, 0x94db, 0xf465, 0x9c91),
      simde_mm_set_pi16(0x8f46, 0x5da3, 0x75f2, 0x7507),
      simde_mm_set_pi16(0x0000, 0x3738, 0x7e73, 0x278a) },
    { simde_mm_set_pi16(0xeb70, 0xeaa3, 0x0b3c, 0x3271),
      simde_mm_set_pi16(0x9ca2, 0xcb5c, 0xaff3, 0x25d4),
      simde_mm_set_pi16(0x4ece, 0x1f47, 0x0000, 0x0c9d) },
    { simde_mm_set_pi16(0xe6fa, 0x733e, 0x810a, 0x7300),
      simde_mm_set_pi16(0x605d, 0x74f0, 0xcea5, 0x90b4),
      simde_mm_set_pi16(0x869d, 0x0000, 0x0000, 0x0000) },
    { simde_mm_set_pi16(0x050f, 0x4637, 0x9aef, 0xdf74),
      simde_mm_set_pi16(0x8a33, 0x007a, 0xaee6, 0x32b7),
      simde_mm_set_pi16(0x0000, 0x45bd, 0x0000, 0xacbd) },
    { simde_mm_set_pi16(0xbb0a, 0x8fd0, 0x9e34, 0xf698),
      simde_mm_set_pi16(0x7f3f, 0x363f, 0x5cbd, 0x81ef),
      simde_mm_set_pi16(0x3bcb, 0x5991, 0x4177, 0x74a9) }
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
    { simde_mm_set_pi8(0x81, 0x30, 0x2a, 0x73, 0xb3, 0x04, 0x19, 0xd6),
      simde_mm_set_pi8(0x39, 0x5c, 0xd9, 0xd6, 0x49, 0x04, 0x29, 0x76),
      simde_mm_set_pi8(0x39, 0x81, 0x5c, 0x30, 0xd9, 0x2a, 0xd6, 0x73) },
    { simde_mm_set_pi8(0xf0, 0x78, 0x10, 0x74, 0xdd, 0x9c, 0x00, 0xd9),
      simde_mm_set_pi8(0x3f, 0xb7, 0x30, 0xbe, 0xdf, 0x9a, 0xc2, 0x76),
      simde_mm_set_pi8(0x3f, 0xf0, 0xb7, 0x78, 0x30, 0x10, 0xbe, 0x74) },
    { simde_mm_set_pi8(0xe8, 0xcf, 0x14, 0x22, 0xff, 0x3f, 0x0b, 0xdc),
      simde_mm_set_pi8(0x9f, 0x34, 0x3e, 0xd0, 0xf1, 0x18, 0x12, 0xe4),
      simde_mm_set_pi8(0x9f, 0xe8, 0x34, 0xcf, 0x3e, 0x14, 0xd0, 0x22) },
    { simde_mm_set_pi8(0x22, 0xb6, 0xa8, 0xbc, 0x50, 0x50, 0xe5, 0x93),
      simde_mm_set_pi8(0xf2, 0x11, 0xce, 0x32, 0xb8, 0x91, 0xe0, 0x8e),
      simde_mm_set_pi8(0xf2, 0x22, 0x11, 0xb6, 0xce, 0xa8, 0x32, 0xbc) },
    { simde_mm_set_pi8(0xae, 0x22, 0x4f, 0x4b, 0xd3, 0x2b, 0x9f, 0x37),
      simde_mm_set_pi8(0x7e, 0x7e, 0x71, 0x7a, 0x07, 0x45, 0x1f, 0x53),
      simde_mm_set_pi8(0x7e, 0xae, 0x7e, 0x22, 0x71, 0x4f, 0x7a, 0x4b) },
    { simde_mm_set_pi8(0xfc, 0x9e, 0x07, 0x58, 0xa3, 0x38, 0xda, 0xf1),
      simde_mm_set_pi8(0x4b, 0x61, 0x4c, 0x1a, 0x89, 0xa0, 0xb6, 0xe8),
      simde_mm_set_pi8(0x4b, 0xfc, 0x61, 0x9e, 0x4c, 0x07, 0x1a, 0x58) },
    { simde_mm_set_pi8(0x7c, 0x47, 0xf2, 0x13, 0xbb, 0xe1, 0x23, 0xae),
      simde_mm_set_pi8(0xe1, 0x7d, 0x23, 0x54, 0x69, 0x8d, 0x0b, 0xf4),
      simde_mm_set_pi8(0xe1, 0x7c, 0x7d, 0x47, 0x23, 0xf2, 0x54, 0x13) },
    { simde_mm_set_pi8(0x2d, 0xcd, 0xb9, 0xd1, 0xe5, 0x14, 0x8b, 0xfb),
      simde_mm_set_pi8(0xa4, 0xb6, 0x3a, 0x75, 0xcb, 0x2b, 0x42, 0xc9),
      simde_mm_set_pi8(0xa4, 0x2d, 0xb6, 0xcd, 0x3a, 0xb9, 0x75, 0xd1) }
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
    { simde_mm_set_pi16(0xc58b, 0x6db0, 0xc30c, 0xd88d),
      simde_mm_set_pi16(0x409a, 0xb683, 0xff02, 0xa559),
      simde_mm_set_pi16(0x409a, 0xc58b, 0xb683, 0x6db0) },
    { simde_mm_set_pi16(0xef06, 0x8c5d, 0x0551, 0x3edc),
      simde_mm_set_pi16(0xeeb4, 0x9a98, 0x1bc7, 0x747f),
      simde_mm_set_pi16(0xeeb4, 0xef06, 0x9a98, 0x8c5d) },
    { simde_mm_set_pi16(0xa94b, 0xcb5a, 0x723b, 0xe416),
      simde_mm_set_pi16(0xe87a, 0xd758, 0xebff, 0xc2e8),
      simde_mm_set_pi16(0xe87a, 0xa94b, 0xd758, 0xcb5a) },
    { simde_mm_set_pi16(0xaca8, 0x3a1e, 0x3754, 0x0aa7),
      simde_mm_set_pi16(0x3123, 0xaec3, 0x465b, 0x153e),
      simde_mm_set_pi16(0x3123, 0xaca8, 0xaec3, 0x3a1e) },
    { simde_mm_set_pi16(0xaeca, 0xab29, 0xd020, 0xbbfe),
      simde_mm_set_pi16(0x11e0, 0x1aba, 0xce84, 0xd1b2),
      simde_mm_set_pi16(0x11e0, 0xaeca, 0x1aba, 0xab29) },
    { simde_mm_set_pi16(0xce31, 0x59a7, 0xd336, 0x98ed),
      simde_mm_set_pi16(0x9385, 0x851a, 0x3875, 0xf764),
      simde_mm_set_pi16(0x9385, 0xce31, 0x851a, 0x59a7) },
    { simde_mm_set_pi16(0xc2bb, 0x338c, 0x432e, 0x7411),
      simde_mm_set_pi16(0x73a0, 0xaab8, 0xe2b4, 0x7be0),
      simde_mm_set_pi16(0x73a0, 0xc2bb, 0xaab8, 0x338c) },
    { simde_mm_set_pi16(0xbed7, 0xbf6f, 0x7fd8, 0x7ae3),
      simde_mm_set_pi16(0x4fb7, 0xcdca, 0x4801, 0x0c2f),
      simde_mm_set_pi16(0x4fb7, 0xbed7, 0xcdca, 0xbf6f) }
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
    { simde_mm_set_pi32(0x9d28e725, 0xb58d699a),
      simde_mm_set_pi32(0x9b24ba0a, 0x19929dc7),
      simde_mm_set_pi32(0x9b24ba0a, 0x9d28e725) },
    { simde_mm_set_pi32(0x35b16936, 0xc03aa28a),
      simde_mm_set_pi32(0xe8202fa7, 0x87f55a6c),
      simde_mm_set_pi32(0xe8202fa7, 0x35b16936) },
    { simde_mm_set_pi32(0xc40d7a67, 0xf4c71f5c),
      simde_mm_set_pi32(0x3049fd79, 0xe5f4c846),
      simde_mm_set_pi32(0x3049fd79, 0xc40d7a67) },
    { simde_mm_set_pi32(0x029939e9, 0xa33572d4),
      simde_mm_set_pi32(0x9e8f706d, 0xee4a8cb1),
      simde_mm_set_pi32(0x9e8f706d, 0x029939e9) },
    { simde_mm_set_pi32(0x30e8b509, 0x0000087b),
      simde_mm_set_pi32(0x68364e38, 0x6a0ab740),
      simde_mm_set_pi32(0x68364e38, 0x30e8b509) },
    { simde_mm_set_pi32(0xf9a1f4c8, 0xd0cd717d),
      simde_mm_set_pi32(0x779e0fd8, 0x1ce3a6ea),
      simde_mm_set_pi32(0x779e0fd8, 0xf9a1f4c8) },
    { simde_mm_set_pi32(0x70c614c2, 0xca5eee3f),
      simde_mm_set_pi32(0x59325835, 0x321f31a1),
      simde_mm_set_pi32(0x59325835, 0x70c614c2) },
    { simde_mm_set_pi32(0x4d150666, 0xddbba464),
      simde_mm_set_pi32(0x0373a08d, 0xfbc7349f),
      simde_mm_set_pi32(0x0373a08d, 0x4d150666) }
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
    { simde_mm_set_pi8(0xf1, 0xe5, 0xe3, 0x02, 0x0b, 0x69, 0xcf, 0x0f),
      simde_mm_set_pi8(0xa6, 0x2b, 0x37, 0x32, 0x9a, 0x19, 0xd8, 0x2f),
      simde_mm_set_pi8(0x9a, 0x0b, 0x19, 0x69, 0xd8, 0xcf, 0x2f, 0x0f) },
    { simde_mm_set_pi8(0x01, 0x53, 0x9b, 0x75, 0xcc, 0xb6, 0xc5, 0x79),
      simde_mm_set_pi8(0x9a, 0x0c, 0xe4, 0x52, 0x86, 0x5e, 0x7f, 0xd0),
      simde_mm_set_pi8(0x86, 0xcc, 0x5e, 0xb6, 0x7f, 0xc5, 0xd0, 0x79) },
    { simde_mm_set_pi8(0x0d, 0x43, 0xb7, 0xdc, 0xa3, 0x65, 0x95, 0x76),
      simde_mm_set_pi8(0x2e, 0xb8, 0xce, 0x22, 0x91, 0xef, 0x80, 0x82),
      simde_mm_set_pi8(0x91, 0xa3, 0xef, 0x65, 0x80, 0x95, 0x82, 0x76) },
    { simde_mm_set_pi8(0x04, 0xd8, 0xb7, 0x7a, 0x55, 0x07, 0xca, 0x89),
      simde_mm_set_pi8(0xdb, 0xb0, 0x80, 0x45, 0x70, 0x32, 0x2c, 0xf5),
      simde_mm_set_pi8(0x70, 0x55, 0x32, 0x07, 0x2c, 0xca, 0xf5, 0x89) },
    { simde_mm_set_pi8(0x8f, 0x1e, 0x44, 0x60, 0xa2, 0xf3, 0xda, 0xc1),
      simde_mm_set_pi8(0xf7, 0x1d, 0x05, 0xea, 0x42, 0x5e, 0xb1, 0xff),
      simde_mm_set_pi8(0x42, 0xa2, 0x5e, 0xf3, 0xb1, 0xda, 0xff, 0xc1) },
    { simde_mm_set_pi8(0xd6, 0xd6, 0x29, 0xf3, 0xd7, 0xdf, 0xe8, 0xfb),
      simde_mm_set_pi8(0x55, 0x4f, 0x13, 0xa1, 0x2a, 0x84, 0xa0, 0x86),
      simde_mm_set_pi8(0x2a, 0xd7, 0x84, 0xdf, 0xa0, 0xe8, 0x86, 0xfb) },
    { simde_mm_set_pi8(0x1c, 0x63, 0xc7, 0x4f, 0x28, 0x9f, 0xb0, 0x10),
      simde_mm_set_pi8(0x3c, 0x00, 0xf3, 0xa6, 0x11, 0x0e, 0x8d, 0x74),
      simde_mm_set_pi8(0x11, 0x28, 0x0e, 0x9f, 0x8d, 0xb0, 0x74, 0x10) },
    { simde_mm_set_pi8(0xe6, 0xd5, 0xeb, 0x49, 0x53, 0x21, 0x69, 0x39),
      simde_mm_set_pi8(0xe3, 0x54, 0x0f, 0xad, 0xcd, 0x3c, 0xee, 0x13),
      simde_mm_set_pi8(0xcd, 0x53, 0x3c, 0x21, 0xee, 0x69, 0x13, 0x39) }
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
    { simde_mm_set_pi16(0x3a48, 0xc8e4, 0xb83d, 0x1045),
      simde_mm_set_pi16(0x5e3d, 0x735f, 0x3872, 0x02fc),
      simde_mm_set_pi16(0x3872, 0xb83d, 0x02fc, 0x1045) },
    { simde_mm_set_pi16(0x8d87, 0xae18, 0x8389, 0x0799),
      simde_mm_set_pi16(0x576c, 0xdbc6, 0xc743, 0x6da9),
      simde_mm_set_pi16(0xc743, 0x8389, 0x6da9, 0x0799) },
    { simde_mm_set_pi16(0x72d4, 0xee7f, 0x3e89, 0xe1f4),
      simde_mm_set_pi16(0x4b3e, 0xd6a0, 0x04b0, 0xa7f3),
      simde_mm_set_pi16(0x04b0, 0x3e89, 0xa7f3, 0xe1f4) },
    { simde_mm_set_pi16(0x2a1a, 0x89bc, 0x7b5c, 0x1030),
      simde_mm_set_pi16(0xc1e5, 0x5067, 0xcdc1, 0x35f0),
      simde_mm_set_pi16(0xcdc1, 0x7b5c, 0x35f0, 0x1030) },
    { simde_mm_set_pi16(0x89c5, 0xc91a, 0x5614, 0xe4b5),
      simde_mm_set_pi16(0xa8e8, 0x5613, 0xd4eb, 0x0f2a),
      simde_mm_set_pi16(0xd4eb, 0x5614, 0x0f2a, 0xe4b5) },
    { simde_mm_set_pi16(0x055d, 0x64bc, 0xc6d1, 0x4a34),
      simde_mm_set_pi16(0x19b4, 0x35a2, 0xcd4d, 0x97ea),
      simde_mm_set_pi16(0xcd4d, 0xc6d1, 0x97ea, 0x4a34) },
    { simde_mm_set_pi16(0x69e6, 0x4841, 0xc1f9, 0xb8c7),
      simde_mm_set_pi16(0x9a2c, 0x8de2, 0x7e6a, 0x9a09),
      simde_mm_set_pi16(0x7e6a, 0xc1f9, 0x9a09, 0xb8c7) },
    { simde_mm_set_pi16(0xf288, 0x6df7, 0x5392, 0x09f2),
      simde_mm_set_pi16(0x75e7, 0xf9a8, 0x2d45, 0x5a28),
      simde_mm_set_pi16(0x2d45, 0x5392, 0x5a28, 0x09f2) }
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
    { simde_mm_set_pi32(0xc49b1f7e, 0x02847d03),
      simde_mm_set_pi32(0xfdcb62fd, 0xba3626bc),
      simde_mm_set_pi32(0xba3626bc, 0x02847d03) },
    { simde_mm_set_pi32(0x7b052e6a, 0x1d48eb25),
      simde_mm_set_pi32(0x9a8655df, 0x181b2187),
      simde_mm_set_pi32(0x181b2187, 0x1d48eb25) },
    { simde_mm_set_pi32(0x1cbd2433, 0x7cf1e921),
      simde_mm_set_pi32(0x5dff1f45, 0xb200baaa),
      simde_mm_set_pi32(0xb200baaa, 0x7cf1e921) },
    { simde_mm_set_pi32(0xee57143a, 0xbc487f18),
      simde_mm_set_pi32(0x307628fa, 0x0862f5f7),
      simde_mm_set_pi32(0x0862f5f7, 0xbc487f18) },
    { simde_mm_set_pi32(0x9048b7e9, 0x3e5db541),
      simde_mm_set_pi32(0x66030646, 0x278f7ad2),
      simde_mm_set_pi32(0x278f7ad2, 0x3e5db541) },
    { simde_mm_set_pi32(0x18b105d4, 0xbc34a4de),
      simde_mm_set_pi32(0x4fa4e0ed, 0x89aaf1a3),
      simde_mm_set_pi32(0x89aaf1a3, 0xbc34a4de) },
    { simde_mm_set_pi32(0x8d123e24, 0x2a672b72),
      simde_mm_set_pi32(0x355466c7, 0xec3b85ce),
      simde_mm_set_pi32(0xec3b85ce, 0x2a672b72) },
    { simde_mm_set_pi32(0xba2a6efe, 0xc7c11bd7),
      simde_mm_set_pi32(0xb7bbaf6c, 0x957c8a00),
      simde_mm_set_pi32(0x957c8a00, 0xc7c11bd7) }
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
    { simde_mm_cvtsi64_m64(UINT64_C(0x31223f9b2157d5f6)),
      simde_mm_cvtsi64_m64(UINT64_C(0x6e62224be1c27237)),
      simde_mm_cvtsi64_m64(UINT64_C(0x5f401dd0c095a7c1)) },
    { simde_mm_cvtsi64_m64(UINT64_C(0x2d853f9f4aeea0d1)),
      simde_mm_cvtsi64_m64(UINT64_C(0x644d532e867f13d0)),
      simde_mm_cvtsi64_m64(UINT64_C(0x49c86cb1cc91b301)) },
    { simde_mm_cvtsi64_m64(UINT64_C(0xfef9eb85073b661b)),
      simde_mm_cvtsi64_m64(UINT64_C(0x860e8618f6f42555)),
      simde_mm_cvtsi64_m64(UINT64_C(0x78f76d9df1cf434e)) },
    { simde_mm_cvtsi64_m64(UINT64_C(0xcac757f23459353b)),
      simde_mm_cvtsi64_m64(UINT64_C(0x1471863b60d78bc8)),
      simde_mm_cvtsi64_m64(UINT64_C(0xdeb6d1c9548ebef3)) },
    { simde_mm_cvtsi64_m64(UINT64_C(0xe271a2d4f3baaf43)),
      simde_mm_cvtsi64_m64(UINT64_C(0x7964d30c668ace79)),
      simde_mm_cvtsi64_m64(UINT64_C(0x9b1571d89530613a)) },
    { simde_mm_cvtsi64_m64(UINT64_C(0x2f66222f6bd9a3c5)),
      simde_mm_cvtsi64_m64(UINT64_C(0xbe0dca25877fe7b3)),
      simde_mm_cvtsi64_m64(UINT64_C(0x916be80aeca64476)) },
    { simde_mm_cvtsi64_m64(UINT64_C(0x28cbc14f1fcb94b2)),
      simde_mm_cvtsi64_m64(UINT64_C(0xfd33dce8a66d2a3a)),
      simde_mm_cvtsi64_m64(UINT64_C(0xd5f81da7b9a6be88)) },
    { simde_mm_cvtsi64_m64(UINT64_C(0x261b738c874d5b92)),
      simde_mm_cvtsi64_m64(UINT64_C(0x2a83208729415044)),
      simde_mm_cvtsi64_m64(UINT64_C(0x0c98530bae0c0bd6)) }
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
    { simde_mm_set_pi32(0x0b305900, 0x2ce14997), 0x2ce14997 },
    { simde_mm_set_pi32(0x5dcceaf2, 0x0612924a), 0x0612924a },
    { simde_mm_set_pi32(0x3c4bbe31, 0x34cda252), 0x34cda252 },
    { simde_mm_set_pi32(0xbdfde335, 0xce0a7b7f), 0xce0a7b7f },
    { simde_mm_set_pi32(0x73ef67ae, 0x1bcf815e), 0x1bcf815e },
    { simde_mm_set_pi32(0x1b5823dd, 0x0f574e31), 0x0f574e31 },
    { simde_mm_set_pi32(0x3292e22f, 0xaba3930e), 0xaba3930e },
    { simde_mm_set_pi32(0xa96fe14f, 0x9acd6061), 0x9acd6061 }
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
    { simde_mm_cvtsi64_m64(INT64_C(0xe430bbd7345fbdc6)), INT64_C(0xe430bbd7345fbdc6) },
    { simde_mm_cvtsi64_m64(INT64_C(0xfad3191b857c9489)), INT64_C(0xfad3191b857c9489) },
    { simde_mm_cvtsi64_m64(INT64_C(0xcd412cd09e6100a4)), INT64_C(0xcd412cd09e6100a4) },
    { simde_mm_cvtsi64_m64(INT64_C(0x46c9e862ff60e44b)), INT64_C(0x46c9e862ff60e44b) },
    { simde_mm_cvtsi64_m64(INT64_C(0xfd079f05a421a2c1)), INT64_C(0xfd079f05a421a2c1) },
    { simde_mm_cvtsi64_m64(INT64_C(0x961974a98b0be6c7)), INT64_C(0x961974a98b0be6c7) },
    { simde_mm_cvtsi64_m64(INT64_C(0x7e9c3f25c9da7889)), INT64_C(0x7e9c3f25c9da7889) },
    { simde_mm_cvtsi64_m64(INT64_C(0x2d3ebe604bed8518)), INT64_C(0x2d3ebe604bed8518) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    int64_t r = simde_m_to_int64(test_vec[i].a);
    simde_mm_empty();
    munit_assert_int64(r, ==, test_vec[i].r);
  }

  simde_mm_empty();
  return MUNIT_OK;
}

static MunitTest test_suite_tests[] = {
  TEST_FUNC(mm_set_pi8),
  TEST_FUNC(mm_set_pi16),
  TEST_FUNC(mm_set_pi32),
  TEST_FUNC(mm_set1_pi8),
  TEST_FUNC(mm_set1_pi16),
  TEST_FUNC(mm_set1_pi32),
  TEST_FUNC(mm_setr_pi8),
  TEST_FUNC(mm_setr_pi16),
  TEST_FUNC(mm_setr_pi32),
  TEST_FUNC(mm_add_pi8),
  TEST_FUNC(mm_add_pi16),
  TEST_FUNC(mm_add_pi32),
  TEST_FUNC(mm_adds_pi8),
  TEST_FUNC(mm_adds_pi16),
  TEST_FUNC(mm_adds_pu8),
  TEST_FUNC(mm_adds_pu16),
  TEST_FUNC(mm_and_si64),
  TEST_FUNC(mm_andnot_si64),
  TEST_FUNC(mm_cmpeq_pi8),
  TEST_FUNC(mm_cmpeq_pi16),
  TEST_FUNC(mm_cmpeq_pi32),
  TEST_FUNC(mm_cmpgt_pi8),
  TEST_FUNC(mm_cmpgt_pi16),
  TEST_FUNC(mm_cmpgt_pi32),
  TEST_FUNC(mm_cvtm64_si64),
  TEST_FUNC(mm_cvtsi32_si64),
  TEST_FUNC(mm_cvtsi64_m64),
  TEST_FUNC(mm_cvtsi64_si32),
  TEST_FUNC(mm_madd_pi16),
  TEST_FUNC(mm_mulhi_pi16),
  TEST_FUNC(mm_mullo_pi16),
  TEST_FUNC(mm_or_si64),
  TEST_FUNC(mm_packs_pi16),
  TEST_FUNC(mm_packs_pi32),
  TEST_FUNC(mm_packs_pu16),
  TEST_FUNC(mm_sll_pi16),
  TEST_FUNC(mm_sll_pi32),
  TEST_FUNC(mm_sll_si64),
  TEST_FUNC(mm_slli_pi16),
  TEST_FUNC(mm_slli_pi32),
  TEST_FUNC(mm_slli_si64),
  TEST_FUNC(mm_srl_pi16),
  TEST_FUNC(mm_srl_pi32),
  TEST_FUNC(mm_srl_si64),
  TEST_FUNC(mm_srli_pi16),
  TEST_FUNC(mm_srli_pi32),
  TEST_FUNC(mm_srli_si64),
  TEST_FUNC(mm_srai_pi16),
  TEST_FUNC(mm_srai_pi32),
  TEST_FUNC(mm_sra_pi16),
  TEST_FUNC(mm_sra_pi32),
  TEST_FUNC(mm_sub_pi8),
  TEST_FUNC(mm_sub_pi16),
  TEST_FUNC(mm_sub_pi32),
  TEST_FUNC(mm_subs_pi8),
  TEST_FUNC(mm_subs_pi16),
  TEST_FUNC(mm_subs_pu8),
  TEST_FUNC(mm_subs_pu16),
  TEST_FUNC(mm_unpackhi_pi8),
  TEST_FUNC(mm_unpackhi_pi16),
  TEST_FUNC(mm_unpackhi_pi32),
  TEST_FUNC(mm_unpacklo_pi8),
  TEST_FUNC(mm_unpacklo_pi16),
  TEST_FUNC(mm_unpacklo_pi32),
  TEST_FUNC(mm_xor_si64),
  TEST_FUNC(m_to_int),
  TEST_FUNC(m_to_int64),

  { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};

#if defined(SIMDE_NO_NATIVE)
#  define simde_mmx_test_suite simde_mmx_emul_test_suite
#endif

MunitSuite simde_mmx_test_suite = {
  (char*) "/mmx",
  test_suite_tests,
  NULL,
  1,
  MUNIT_SUITE_OPTION_NONE
};
