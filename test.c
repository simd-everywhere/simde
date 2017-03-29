#define SIMDE__EMULATE_NATIVE

#if defined(TEST_NATIVE)
#  define SIMDE__MMX_NATIVE
#  define SIMDE__SSE_NATIVE
#endif

#include <stdio.h>
#include <limits.h>

#include "sse.h"
#include "munit/munit.h"

/*** MMX ***/

static MunitResult
test_simd_mm_set_pi8(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  char d[8 / sizeof(char)];
  munit_rand_memory(sizeof(d), (uint8_t*) d);

  __m64 x = _mm_set_pi8(d[0], d[1], d[2], d[3], d[4], d[5], d[6], d[7]);
  char* c = (char*) &x;

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
test_simd_mm_set_pi16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  short d[8 / sizeof(short)];
  munit_rand_memory(sizeof(d), (uint8_t*) d);

  __m64 x = _mm_set_pi16(d[0], d[1], d[2], d[3]);
  short* s = (short*) &x;

  munit_assert_short(s[0], ==, d[3]);
  munit_assert_short(s[1], ==, d[2]);
  munit_assert_short(s[2], ==, d[1]);
  munit_assert_short(s[3], ==, d[0]);

  return MUNIT_OK;
}

static MunitResult
test_simd_mm_set_pi32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  int d[8 / sizeof(int)];
  munit_rand_memory(sizeof(d), (uint8_t*) d);

  __m64 x = _mm_set_pi32(d[0], d[1]);
  int* i = (int*) &x;

  munit_assert_int(i[0], ==, d[1]);
  munit_assert_int(i[1], ==, d[0]);

  return MUNIT_OK;
}

static MunitResult
test_simd_mm_set1_pi8(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  char v = (char) munit_rand_int_range(CHAR_MIN, CHAR_MAX);

  __m64 x = _mm_set1_pi8(v);
  char* r = (char*) &x;

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
test_simd_mm_set1_pi16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  short v = (short) munit_rand_int_range(SHRT_MIN, SHRT_MAX);

  __m64 x = _mm_set1_pi16(v);
  short* r = (short*) &x;

  munit_assert_int8(r[0], ==, v);
  munit_assert_int8(r[1], ==, v);
  munit_assert_int8(r[2], ==, v);
  munit_assert_int8(r[3], ==, v);

  return MUNIT_OK;
}

static MunitResult
test_simd_mm_set1_pi32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  int v = (int) munit_rand_int_range(INT_MIN, INT_MAX);

  __m64 x = _mm_set1_pi32(v);
  int* r = (int*) &x;

  munit_assert_int8(r[0], ==, v);
  munit_assert_int8(r[1], ==, v);

  return MUNIT_OK;
}

static MunitResult
test_simd_mm_setr_pi8(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  char d[8 / sizeof(char)];
  munit_rand_memory(sizeof(d), (uint8_t*) d);

  __m64 x = _mm_setr_pi8(d[0], d[1], d[2], d[3], d[4], d[5], d[6], d[7]);
  char* c = (char*) &x;

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
test_simd_mm_setr_pi16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  short d[8 / sizeof(short)];
  munit_rand_memory(sizeof(d), (uint8_t*) d);

  __m64 x = _mm_setr_pi16(d[0], d[1], d[2], d[3]);
  short* s = (short*) &x;

  munit_assert_short(s[0], ==, d[0]);
  munit_assert_short(s[1], ==, d[1]);
  munit_assert_short(s[2], ==, d[2]);
  munit_assert_short(s[3], ==, d[3]);

  return MUNIT_OK;
}

static MunitResult
test_simd_mm_setr_pi32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  int d[8 / sizeof(int)];
  munit_rand_memory(sizeof(d), (uint8_t*) d);

  __m64 x = _mm_setr_pi32(d[0], d[1]);
  int* i = (int*) &x;

  munit_assert_int(i[0], ==, d[0]);
  munit_assert_int(i[1], ==, d[1]);

  return MUNIT_OK;
}

#define assert_m64_pi8(a, cmp, b)					\
  do {									\
    munit_assert_int8(((char*) (&a))[0], cmp, ((char*) (&b))[0]);	\
    munit_assert_int8(((char*) (&a))[1], cmp, ((char*) (&b))[1]);	\
    munit_assert_int8(((char*) (&a))[2], cmp, ((char*) (&b))[2]);	\
    munit_assert_int8(((char*) (&a))[3], cmp, ((char*) (&b))[3]);	\
    munit_assert_int8(((char*) (&a))[4], cmp, ((char*) (&b))[4]);	\
    munit_assert_int8(((char*) (&a))[5], cmp, ((char*) (&b))[5]);	\
    munit_assert_int8(((char*) (&a))[6], cmp, ((char*) (&b))[6]);	\
    munit_assert_int8(((char*) (&a))[7], cmp, ((char*) (&b))[7]);	\
  } while (0)

#define assert_m64_pi16(a, cmp, b)					\
  do {									\
    munit_assert_short(((short*) (&a))[0], cmp, ((short*) (&b))[0]);	\
    munit_assert_short(((short*) (&a))[1], cmp, ((short*) (&b))[1]);	\
    munit_assert_short(((short*) (&a))[2], cmp, ((short*) (&b))[2]);	\
    munit_assert_short(((short*) (&a))[3], cmp, ((short*) (&b))[3]);	\
  } while (0)

#define assert_m64_pi32(a, cmp, b)				\
  do {								\
    munit_assert_int(((int*) (&a))[0], cmp, ((int*) (&b))[0]);	\
    munit_assert_int(((int*) (&a))[1], cmp, ((int*) (&b))[1]);	\
  } while (0)

#define assert_m64_si64(a, cmp, b)				\
  do {								\
    munit_assert_long long int(((long long int*) (&a))[0], cmp, ((long long int*) (&b))[0]);	\
  } while (0)

static MunitResult
test_simd_mm_add_pi8(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    __m64 a;
    __m64 b;
    __m64 r;
  } test_vec[8] = {
    { _mm_set_pi8(0x19, 0x96, 0x5d, 0x56, 0xc8, 0x65, 0x4f, 0x53),
      _mm_set_pi8(0xda, 0xfa, 0x2f, 0x3b, 0xbd, 0xdc, 0x7f, 0x68),
      _mm_set_pi8(0xf3, 0x90, 0x8c, 0x91, 0x85, 0x41, 0xce, 0xbb) },
    { _mm_set_pi8(0x97, 0x71, 0x16, 0xa5, 0x3b, 0xfc, 0x43, 0x2b),
      _mm_set_pi8(0xf3, 0x5d, 0x51, 0x6c, 0x98, 0x7b, 0x69, 0x77),
      _mm_set_pi8(0x8a, 0xce, 0x67, 0x11, 0xd3, 0x77, 0xac, 0xa2) },
    { _mm_set_pi8(0xf8, 0x34, 0x5c, 0x79, 0x3a, 0x98, 0x1b, 0xb0),
      _mm_set_pi8(0x3e, 0x9c, 0x05, 0xa1, 0xf0, 0x6d, 0x7f, 0x3e),
      _mm_set_pi8(0x36, 0xd0, 0x61, 0x1a, 0x2a, 0x05, 0x9a, 0xee) },
    { _mm_set_pi8(0x20, 0x7c, 0x73, 0x03, 0x68, 0x1b, 0x2b, 0xf5),
      _mm_set_pi8(0xea, 0x1b, 0xd1, 0x2d, 0xa0, 0xcf, 0xb6, 0xde),
      _mm_set_pi8(0x0a, 0x97, 0x44, 0x30, 0x08, 0xea, 0xe1, 0xd3) },
    { _mm_set_pi8(0xf2, 0xb1, 0xda, 0xa3, 0xc9, 0x53, 0x4e, 0xa6),
      _mm_set_pi8(0x5b, 0xc3, 0x84, 0xc0, 0x4c, 0xf1, 0x8b, 0x0b),
      _mm_set_pi8(0x4d, 0x74, 0x5e, 0x63, 0x15, 0x44, 0xd9, 0xb1) },
    { _mm_set_pi8(0x89, 0x21, 0xc7, 0x36, 0xee, 0x4f, 0x56, 0xe7),
      _mm_set_pi8(0x8d, 0x8e, 0x48, 0x82, 0xb0, 0x72, 0x82, 0x2a),
      _mm_set_pi8(0x16, 0xaf, 0x0f, 0xb8, 0x9e, 0xc1, 0xd8, 0x11) },
    { _mm_set_pi8(0x3c, 0x6d, 0x5d, 0xd3, 0xc2, 0x98, 0xd7, 0x48),
      _mm_set_pi8(0x48, 0xaa, 0x15, 0x4f, 0x2b, 0x17, 0xb6, 0xc2),
      _mm_set_pi8(0x84, 0x17, 0x72, 0x22, 0xed, 0xaf, 0x8d, 0x0a) },
    { _mm_set_pi8(0x6e, 0x6a, 0xa2, 0x66, 0xae, 0x6c, 0xf4, 0xd0),
      _mm_set_pi8(0x6c, 0x03, 0xa5, 0x41, 0x1e, 0x6a, 0xff, 0x64),
      _mm_set_pi8(0xda, 0x6d, 0x47, 0xa7, 0xcc, 0xd6, 0xf3, 0x34) }
  };

  /* for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) { */
  /*   __m64 a, b, r; */
  /*   munit_rand_memory(sizeof(a), (uint8_t*) &a); */
  /*   munit_rand_memory(sizeof(b), (uint8_t*) &b); */
  /*   r = _mm_add_pi8(a, b); */

  /*   char* av = (char*) &a; */
  /*   char* bv = (char*) &b; */
  /*   char* rv = (char*) &r; */

  /*   printf("{ _mm_set_pi8(0x%02hhx, 0x%02hhx, 0x%02hhx, 0x%02hhx, 0x%02hhx, 0x%02hhx, 0x%02hhx, 0x%02hhx),\n", */
  /* 	   av[0], av[1], av[2], av[3], av[4], av[5], av[6], av[7]); */
  /*   printf("  _mm_set_pi8(0x%02hhx, 0x%02hhx, 0x%02hhx, 0x%02hhx, 0x%02hhx, 0x%02hhx, 0x%02hhx, 0x%02hhx),\n", */
  /* 	   bv[0], bv[1], bv[2], bv[3], bv[4], bv[5], bv[6], bv[7]); */
  /*   printf("  _mm_set_pi8(0x%02hhx, 0x%02hhx, 0x%02hhx, 0x%02hhx, 0x%02hhx, 0x%02hhx, 0x%02hhx, 0x%02hhx) },\n", */
  /* 	   rv[0], rv[1], rv[2], rv[3], rv[4], rv[5], rv[6], rv[7]); */
  /* } */

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    __m64 r = _mm_add_pi8(test_vec[i].a, test_vec[i].b);
    assert_m64_pi8(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simd_mm_add_pi16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    __m64 a;
    __m64 b;
    __m64 r;
  } test_vec[8] = {
    { _mm_set_pi16(0xcc36, 0xddb8, 0x7e6d, 0xf0d1),
      _mm_set_pi16(0x4e32, 0x5b79, 0xfcfa, 0x16b2),
      _mm_set_pi16(0x1a68, 0x3931, 0x7b67, 0x0783) },
    { _mm_set_pi16(0x2c47, 0x7424, 0x65cb, 0xc564),
      _mm_set_pi16(0xca34, 0xae46, 0x07c9, 0x8945),
      _mm_set_pi16(0xf67b, 0x226a, 0x6d94, 0x4ea9) },
    { _mm_set_pi16(0x009f, 0x5c4c, 0xbcb8, 0xa508),
      _mm_set_pi16(0xb881, 0x1e13, 0x574f, 0xc092),
      _mm_set_pi16(0xb920, 0x7a5f, 0x1407, 0x659a) },
    { _mm_set_pi16(0x2389, 0xe8a2, 0x6e1f, 0x803d),
      _mm_set_pi16(0xbde8, 0xb989, 0x81fd, 0x28a5),
      _mm_set_pi16(0xe171, 0xa22b, 0xf01c, 0xa8e2) },
    { _mm_set_pi16(0x0831, 0x5f83, 0x63bd, 0xc883),
      _mm_set_pi16(0x9193, 0x1184, 0xa931, 0x4619),
      _mm_set_pi16(0x99c4, 0x7107, 0x0cee, 0x0e9c) },
    { _mm_set_pi16(0xbb0a, 0x30a3, 0x3025, 0x144e),
      _mm_set_pi16(0x9822, 0x7c91, 0xc6c0, 0x18ea),
      _mm_set_pi16(0x532c, 0xad34, 0xf6e5, 0x2d38) },
    { _mm_set_pi16(0x7b0a, 0xb6da, 0xda08, 0xbd6e),
      _mm_set_pi16(0x4281, 0x3382, 0x9abd, 0x3aa9),
      _mm_set_pi16(0xbd8b, 0xea5c, 0x74c5, 0xf817) },
    { _mm_set_pi16(0x26b0, 0x9263, 0x8285, 0xfafb),
      _mm_set_pi16(0xe3ea, 0xf882, 0x681e, 0x8527),
      _mm_set_pi16(0x0a9a, 0x8ae5, 0xeaa3, 0x8022) }
  };

  /* for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) { */
  /*   __m64 a, b, r; */
  /*   munit_rand_memory(sizeof(a), (uint8_t*) &a); */
  /*   munit_rand_memory(sizeof(b), (uint8_t*) &b); */
  /*   r = _mm_add_pi16(a, b); */

  /*   short* av = (short*) &a; */
  /*   short* bv = (short*) &b; */
  /*   short* rv = (short*) &r; */

  /*   printf("{ _mm_set_pi16(0x%04hx, 0x%04hx, 0x%04hx, 0x%04hx),\n", av[0], av[1], av[2], av[3]); */
  /*   printf("  _mm_set_pi16(0x%04hx, 0x%04hx, 0x%04hx, 0x%04hx),\n", bv[0], bv[1], bv[2], bv[3]); */
  /*   printf("  _mm_set_pi16(0x%04hx, 0x%04hx, 0x%04hx, 0x%04hx) },\n", rv[0], rv[1], rv[2], rv[3]); */
  /* } */

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    __m64 r = _mm_add_pi16(test_vec[i].a, test_vec[i].b);
    assert_m64_pi16(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simd_mm_add_pi32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    __m64 a;
    __m64 b;
    __m64 r;
  } test_vec[8] = {
    { _mm_set_pi32(0xa4e05d2d, 0x93297f7c),
      _mm_set_pi32(0xb6b4ca2f, 0x3b0097a1),
      _mm_set_pi32(0x5b95275c, 0xce2a171d) },
    { _mm_set_pi32(0x73715e7c, 0x4f55c863),
      _mm_set_pi32(0xe1da937c, 0x57b2d16a),
      _mm_set_pi32(0x554bf1f8, 0xa70899cd) },
    { _mm_set_pi32(0x2eb84efc, 0x72a06142),
      _mm_set_pi32(0x65566652, 0xf58a7afd),
      _mm_set_pi32(0x940eb54e, 0x682adc3f) },
    { _mm_set_pi32(0x4749244b, 0x4f39928a),
      _mm_set_pi32(0xdb8caca1, 0x2eed6088),
      _mm_set_pi32(0x22d5d0ec, 0x7e26f312) },
    { _mm_set_pi32(0x38a16c13, 0x22075321),
      _mm_set_pi32(0x65255049, 0x96ef5dc0),
      _mm_set_pi32(0x9dc6bc5c, 0xb8f6b0e1) },
    { _mm_set_pi32(0x026fa3d0, 0x08e4259d),
      _mm_set_pi32(0x6159d6bf, 0xf2a5a065),
      _mm_set_pi32(0x63c97a8f, 0xfb89c602) },
    { _mm_set_pi32(0xd525e259, 0x569edf13),
      _mm_set_pi32(0x0360eaae, 0xdc8cf548),
      _mm_set_pi32(0xd886cd07, 0x332bd45b) },
    { _mm_set_pi32(0xc759ded1, 0xffe934bc),
      _mm_set_pi32(0x9bd96cf5, 0x13223ea9),
      _mm_set_pi32(0x63334bc6, 0x130b7365) }
  };

  /* for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) { */
  /*   __m64 a, b, r; */
  /*   munit_rand_memory(sizeof(a), (uint8_t*) &a); */
  /*   munit_rand_memory(sizeof(b), (uint8_t*) &b); */
  /*   r = _mm_add_pi32(a, b); */

  /*   int* av = (int*) &a; */
  /*   int* bv = (int*) &b; */
  /*   int* rv = (int*) &r; */

  /*   printf("{ _mm_set_pi32(0x%08x, 0x%08x),\n", av[0], av[1]); */
  /*   printf("  _mm_set_pi32(0x%08x, 0x%08x),\n", bv[0], bv[1]); */
  /*   printf("  _mm_set_pi32(0x%08x, 0x%08x) },\n", rv[0], rv[1]); */
  /* } */

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    __m64 r = _mm_add_pi32(test_vec[i].a, test_vec[i].b);
    assert_m64_pi32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simd_mm_adds_pi8(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    __m64 a;
    __m64 b;
    __m64 r;
  } test_vec[8] = {
    { _mm_set_pi8(  99,   16,  -73,  -73,   34,   32,   87,   42),
      _mm_set_pi8( -29,  -82,  -26,  -38,   66,  -51,   82,   53),
      _mm_set_pi8(  70,  -66,  -99, -111,  100,  -19,  127,   95) },
    { _mm_set_pi8( -63, -116,  -41,  -11,  -99,  -60,  -36,  -15),
      _mm_set_pi8(  84, -113,  107,   81,  -28,  -25,  -90, -115),
      _mm_set_pi8(  21, -128,   66,   70, -127,  -85, -126, -128) },
    { _mm_set_pi8( -79, -104,  -10,  -65,   84,  -40, -102,   75),
      _mm_set_pi8(  30,   54,  127,   16,   -7,  -31,  -83,  -89),
      _mm_set_pi8( -49,  -50,  117,  -49,   77,  -71, -128,  -14) },
    { _mm_set_pi8(-115,  -50,  111,  104,  -19,  -48,  122,   59),
      _mm_set_pi8( -74,  -15,   43,    9,   94,  -81,  -68,   15),
      _mm_set_pi8(-128,  -65,  127,  113,   75, -128,   54,   74) },
    { _mm_set_pi8(  18,  -79,    5,   80,   99,  108,   39,  -27),
      _mm_set_pi8( 127,   44,   22,  -80,  -86,  -11,  108,  -95),
      _mm_set_pi8( 127,  -35,   27,    0,   13,   97,  127, -122) },
    { _mm_set_pi8( -35,   62,  102,  -79,  117,  108,   56,  -21),
      _mm_set_pi8(  68,  119,  -10,   17,   40, -124,  -75,  -39),
      _mm_set_pi8(  33,  127,   92,  -62,  127,  -16,  -19,  -60) },
    { _mm_set_pi8(  45,   -5,  -10,   -4,  -23,  -76, -111,  -38),
      _mm_set_pi8(  24,  -15,   -2,   75,   11, -108,   -5,  124),
      _mm_set_pi8(  69,  -20,  -12,   71,  -12, -128, -116,   86) },
    { _mm_set_pi8( 116,   38,   87,    5,  -25, -119,  117,  -12),
      _mm_set_pi8( -51,   25, -122,   40, -111,  -50,  -55, -109),
      _mm_set_pi8(  65,   63,  -35,   45, -128, -128,   62, -121) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    __m64 r = _mm_adds_pi8(test_vec[i].a, test_vec[i].b);
    assert_m64_pi8(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simd_mm_adds_pi16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    __m64 a;
    __m64 b;
    __m64 r;
  } test_vec[8] = {
    { _mm_set_pi16(0x85b3, 0xea33, 0xcb36, 0x9f96),
      _mm_set_pi16(0x4db4, 0xd080, 0x0cc2, 0x232a),
      _mm_set_pi16(0xd367, 0xbab3, 0xd7f8, 0xc2c0) },
    { _mm_set_pi16(0x5054, 0x9c2e, 0x485a, 0xff95),
      _mm_set_pi16(0x3028, 0x3253, 0x08cb, 0xb551),
      _mm_set_pi16(0x7fff, 0xce81, 0x5125, 0xb4e6) },
    { _mm_set_pi16(0x4e8a, 0xc367, 0x9c30, 0xa339),
      _mm_set_pi16(0x2c74, 0x125a, 0x41f6, 0x2c28),
      _mm_set_pi16(0x7afe, 0xd5c1, 0xde26, 0xcf61) },
    { _mm_set_pi16(0x87a9, 0xcf38, 0x2f76, 0x0158),
      _mm_set_pi16(0xab19, 0x2ca0, 0x4b8e, 0xa790),
      _mm_set_pi16(0x8000, 0xfbd8, 0x7b04, 0xa8e8) },
    { _mm_set_pi16(0x5a94, 0xae33, 0x696f, 0xd389),
      _mm_set_pi16(0x5066, 0x19e4, 0x7d61, 0x5b65),
      _mm_set_pi16(0x7fff, 0xc817, 0x7fff, 0x2eee) },
    { _mm_set_pi16(0x06fd, 0x6f96, 0x4a33, 0x810c),
      _mm_set_pi16(0x809f, 0x8947, 0x0706, 0x6f45),
      _mm_set_pi16(0x879c, 0xf8dd, 0x5139, 0xf051) },
    { _mm_set_pi16(0x483b, 0xd1fb, 0x949d, 0x0151),
      _mm_set_pi16(0x01a4, 0x7066, 0x8679, 0x3b98),
      _mm_set_pi16(0x49df, 0x4261, 0x8000, 0x3ce9) },
    { _mm_set_pi16(0xc2b9, 0x638f, 0x5a08, 0xdee2),
      _mm_set_pi16(0x2437, 0xed6c, 0xd0c9, 0xc3e9),
      _mm_set_pi16(0xe6f0, 0x50fb, 0x2ad1, 0xa2cb) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    __m64 r = _mm_adds_pi16(test_vec[i].a, test_vec[i].b);
    assert_m64_pi16(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simd_mm_and_si64(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    __m64 a;
    __m64 b;
    __m64 r;
  } test_vec[8] = {
    { _mm_set_pi32(0x144c257e, 0x33ba1fbe),
      _mm_set_pi32(0x99c6657b, 0x13835d57),
      _mm_set_pi32(0x1044257a, 0x13821d16) },
    { _mm_set_pi32(0x15b94c0e, 0x91869bf9),
      _mm_set_pi32(0x196337a0, 0xdfee49cd),
      _mm_set_pi32(0x11210400, 0x918609c9) },
    { _mm_set_pi32(0x48da74ac, 0x8bbf676f),
      _mm_set_pi32(0x0641aef3, 0x1443debe),
      _mm_set_pi32(0x004024a0, 0x0003462e) },
    { _mm_set_pi32(0x28732761, 0x50acbfb4),
      _mm_set_pi32(0x3eab5e0e, 0xc30b648f),
      _mm_set_pi32(0x28230600, 0x40082484) },
    { _mm_set_pi32(0x6cb04b6a, 0x991ae02b),
      _mm_set_pi32(0x43f0cdd5, 0x3419e02a),
      _mm_set_pi32(0x40b04940, 0x1018e02a) },
    { _mm_set_pi32(0x0b3f944b, 0x36ca8c12),
      _mm_set_pi32(0xe1e07d37, 0x9b9452a5),
      _mm_set_pi32(0x01201403, 0x12800000) },
    { _mm_set_pi32(0xa7641f1a, 0x12570460),
      _mm_set_pi32(0x9513fe43, 0x750d4083),
      _mm_set_pi32(0x85001e02, 0x10050000) },
    { _mm_set_pi32(0xda6f00b9, 0xfb1799bc),
      _mm_set_pi32(0x5fc97d85, 0x33b95b4c),
      _mm_set_pi32(0x5a490081, 0x3311190c) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    __m64 r = _mm_and_si64(test_vec[i].a, test_vec[i].b);
    assert_m64_pi32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simd_mm_andnot_si64(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    __m64 a;
    __m64 b;
    __m64 r;
  } test_vec[8] = {
    { _mm_set_pi32(0x3425e371, 0xd02dfafb),
      _mm_set_pi32(0x13a8010e, 0x1c99a489),
      _mm_set_pi32(0x0388000e, 0x0c900400) },
    { _mm_set_pi32(0xc7af1daf, 0x74738f9e),
      _mm_set_pi32(0xc97744fb, 0xded2bbba),
      _mm_set_pi32(0x08504050, 0x8a803020) },
    { _mm_set_pi32(0xf0e35afb, 0x5813fda1),
      _mm_set_pi32(0xa1b63aec, 0xa03a2993),
      _mm_set_pi32(0x01142004, 0xa0280012) },
    { _mm_set_pi32(0xdd14761c, 0x3134f75f),
      _mm_set_pi32(0x972f6a8e, 0xd9a4754f),
      _mm_set_pi32(0x022b0882, 0xc8800000) },
    { _mm_set_pi32(0xffacf087, 0x296a73ad),
      _mm_set_pi32(0x9fcf4978, 0x0cdd9711),
      _mm_set_pi32(0x00430978, 0x04958410) },
    { _mm_set_pi32(0x554f2958, 0x3c2df6ee),
      _mm_set_pi32(0x9c91ca9a, 0xd44aee0d),
      _mm_set_pi32(0x8890c282, 0xc0420801) },
    { _mm_set_pi32(0x65c0b6ff, 0xa8d8d28e),
      _mm_set_pi32(0xc36aba80, 0x8fd87d5b),
      _mm_set_pi32(0x822a0800, 0x07002d51) },
    { _mm_set_pi32(0x1407f68e, 0x885a1c80),
      _mm_set_pi32(0x8b36f6ec, 0xcf11be13),
      _mm_set_pi32(0x8b300060, 0x4701a213) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    __m64 r = _mm_andnot_si64(test_vec[i].a, test_vec[i].b);
    assert_m64_pi32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simd_mm_cmpeq_pi8(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    __m64 a;
    __m64 b;
    __m64 r;
  } test_vec[8] = {
    { _mm_set_pi8(0x3d, 0x8b, 0x8b, 0xe9, 0xed, 0x06, 0xe8, 0x59),
      _mm_set_pi8(0x2f, 0x47, 0x97, 0x0d, 0xe6, 0x5d, 0x76, 0xc6),
      _mm_set_pi8(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00) },
    { _mm_set_pi8(0x4e, 0x0b, 0xfe, 0x56, 0xce, 0xcf, 0xff, 0x5c),
      _mm_set_pi8(0xab, 0x9d, 0xd7, 0x74, 0x4a, 0x72, 0xfd, 0x9e),
      _mm_set_pi8(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00) },
    { _mm_set_pi8(0x3c, 0x0a, 0xde, 0x1e, 0x30, 0xf3, 0x96, 0x69),
      _mm_set_pi8(0x51, 0x6c, 0xbf, 0xc6, 0xe2, 0xa6, 0x2a, 0x00),
      _mm_set_pi8(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00) },
    { _mm_set_pi8(0x8f, 0xbd, 0xc9, 0x54, 0xa4, 0xbe, 0x07, 0x15),
      _mm_set_pi8(0x8f, 0xbd, 0xc9, 0x54, 0xa4, 0xbe, 0x07, 0x15),
      _mm_set_pi8(0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff) },
    { _mm_set_pi8(0xb8, 0xc8, 0x98, 0xfa, 0x25, 0x8e, 0x54, 0x15),
      _mm_set_pi8(0x4d, 0xe7, 0x98, 0x00, 0xd9, 0x26, 0xca, 0xa6),
      _mm_set_pi8(0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00) },
    { _mm_set_pi8(0x2e, 0x78, 0xf3, 0x83, 0x32, 0x0a, 0x78, 0xf6),
      _mm_set_pi8(0x55, 0x59, 0x09, 0x41, 0xae, 0xb0, 0x41, 0xbf),
      _mm_set_pi8(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00) },
    { _mm_set_pi8(0xf4, 0xd7, 0xca, 0x5c, 0xa9, 0xae, 0x88, 0x25),
      _mm_set_pi8(0x5e, 0xeb, 0x24, 0x87, 0xc2, 0xfc, 0x2a, 0x89),
      _mm_set_pi8(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00) },
    { _mm_set_pi8(0xf8, 0xc4, 0x23, 0xe1, 0x99, 0xf9, 0xd9, 0x2f),
      _mm_set_pi8(0x0d, 0xac, 0x82, 0x81, 0xae, 0x25, 0x3c, 0x1e),
      _mm_set_pi8(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    __m64 r = _mm_cmpeq_pi8(test_vec[i].a, test_vec[i].b);
    assert_m64_pi8(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simd_mm_cmpeq_pi16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    __m64 a;
    __m64 b;
    __m64 r;
  } test_vec[8] = {
    { _mm_set_pi16(0xc9b1, 0x919d, 0x2a22, 0x5fc6),
      _mm_set_pi16(0x1493, 0x0784, 0x33e1, 0x9e21),
      _mm_set_pi16(0x0000, 0x0000, 0x0000, 0x0000) },
    { _mm_set_pi16(0xaa43, 0xcb55, 0xfe7a, 0x18e9),
      _mm_set_pi16(0xda91, 0x1adc, 0x5cd8, 0x1841),
      _mm_set_pi16(0x0000, 0x0000, 0x0000, 0x0000) },
    { _mm_set_pi16(0x2c64, 0x6edf, 0x3429, 0x37b5),
      _mm_set_pi16(0x346e, 0x7d21, 0x0fd7, 0x15f7),
      _mm_set_pi16(0x0000, 0x0000, 0x0000, 0x0000) },
    { _mm_set_pi16(0x00ce, 0xf9e1, 0xbcff, 0x46f6),
      _mm_set_pi16(0x7737, 0x77b3, 0x7fdf, 0xef9d),
      _mm_set_pi16(0x0000, 0x0000, 0x0000, 0x0000) },
    { _mm_set_pi16(0x633e, 0xb859, 0xc202, 0xc36f),
      _mm_set_pi16(0x633e, 0xb859, 0xc202, 0xc36f),
      _mm_set_pi16(0xffff, 0xffff, 0xffff, 0xffff) },
    { _mm_set_pi16(0x5391, 0x591f, 0x0142, 0x2588),
      _mm_set_pi16(0x5d91, 0x8448, 0xe286, 0x7cfc),
      _mm_set_pi16(0x0000, 0x0000, 0x0000, 0x0000) },
    { _mm_set_pi16(0xbf86, 0xfc67, 0x8243, 0x480c),
      _mm_set_pi16(0xd79c, 0x9232, 0x5df9, 0xe479),
      _mm_set_pi16(0x0000, 0x0000, 0x0000, 0x0000) },
    { _mm_set_pi16(0xfb6b, 0x9b0c, 0xd617, 0x5669),
      _mm_set_pi16(0x6572, 0x31ae, 0x6350, 0x2e5b),
      _mm_set_pi16(0x0000, 0x0000, 0x0000, 0x0000) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    __m64 r = _mm_cmpeq_pi16(test_vec[i].a, test_vec[i].b);
    assert_m64_pi16(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simd_mm_cmpeq_pi32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    __m64 a;
    __m64 b;
    __m64 r;
  } test_vec[8] = {
    { _mm_set_pi32(0xcb55aa43, 0x18e9fe7a),
      _mm_set_pi32(0x1adcda91, 0x18415cd8),
      _mm_set_pi32(0x00000000, 0x00000000) },
    { _mm_set_pi32(0x6edf2c64, 0x37b53429),
      _mm_set_pi32(0x7d21346e, 0x15f70fd7),
      _mm_set_pi32(0x00000000, 0x00000000) },
    { _mm_set_pi32(0xf9e100ce, 0x46f6bcff),
      _mm_set_pi32(0x77b37737, 0xef9d7fdf),
      _mm_set_pi32(0x00000000, 0x00000000) },
    { _mm_set_pi32(0x07841493, 0x9e2133e1),
      _mm_set_pi32(0x07841493, 0x9e2133e1),
      _mm_set_pi32(0xffffffff, 0xffffffff) },
    { _mm_set_pi32(0xb859633e, 0xc36fc202),
      _mm_set_pi32(0xc2526ad6, 0xc4ce7bc7),
      _mm_set_pi32(0x00000000, 0x00000000) },
    { _mm_set_pi32(0x591f5391, 0x25880142),
      _mm_set_pi32(0x84485d91, 0x7cfce286),
      _mm_set_pi32(0x00000000, 0x00000000) },
    { _mm_set_pi32(0xfc67bf86, 0x480c8243),
      _mm_set_pi32(0x9232d79c, 0xe4795df9),
      _mm_set_pi32(0x00000000, 0x00000000) },
    { _mm_set_pi32(0x9b0cfb6b, 0x5669d617),
      _mm_set_pi32(0x31ae6572, 0x2e5b6350),
      _mm_set_pi32(0x00000000, 0x00000000) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    __m64 r = _mm_cmpeq_pi32(test_vec[i].a, test_vec[i].b);
    assert_m64_pi32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simd_mm_cmpgt_pi8(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    __m64 a;
    __m64 b;
    __m64 r;
  } test_vec[8] = {
    { _mm_set_pi8(0xb3, 0x1d, 0xde, 0x92, 0xb2, 0xf8, 0x5c, 0x2c),
      _mm_set_pi8(0xc7, 0x63, 0xf6, 0x1c, 0x2e, 0x4f, 0xb4, 0x3b),
      _mm_set_pi8(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x00) },
    { _mm_set_pi8(0x60, 0xf7, 0xc3, 0x2e, 0x68, 0x97, 0x59, 0x30),
      _mm_set_pi8(0x6d, 0x46, 0x0d, 0x5a, 0x8c, 0xe9, 0x0a, 0xa0),
      _mm_set_pi8(0x00, 0x00, 0x00, 0x00, 0xff, 0x00, 0xff, 0xff) },
    { _mm_set_pi8(0xe8, 0xfe, 0x49, 0x24, 0xe3, 0xba, 0x49, 0x87),
      _mm_set_pi8(0x11, 0xef, 0x4d, 0xfe, 0x6f, 0x91, 0xbe, 0xe2),
      _mm_set_pi8(0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0xff, 0x00) },
    { _mm_set_pi8(0x48, 0x9a, 0x87, 0x29, 0xe3, 0x9c, 0xba, 0x52),
      _mm_set_pi8(0x65, 0x76, 0x92, 0xb6, 0xc7, 0xfe, 0x59, 0xf0),
      _mm_set_pi8(0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0xff) },
    { _mm_set_pi8(0x40, 0x02, 0x8a, 0x17, 0xa8, 0x88, 0x3d, 0x72),
      _mm_set_pi8(0x3c, 0x5b, 0x60, 0xea, 0x26, 0x31, 0x50, 0xe3),
      _mm_set_pi8(0xff, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff) },
    { _mm_set_pi8(0x1f, 0xe0, 0x87, 0x09, 0x50, 0x6c, 0x1d, 0x02),
      _mm_set_pi8(0x89, 0x21, 0x09, 0x65, 0x65, 0x4f, 0x29, 0x57),
      _mm_set_pi8(0xff, 0x00, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00) },
    { _mm_set_pi8(0x60, 0xb5, 0x87, 0x9b, 0x0a, 0x82, 0x3a, 0x3c),
      _mm_set_pi8(0x65, 0xb7, 0x7e, 0x69, 0xd0, 0x89, 0x9f, 0xa6),
      _mm_set_pi8(0x00, 0x00, 0x00, 0x00, 0xff, 0x00, 0xff, 0xff) },
    { _mm_set_pi8(0x76, 0x76, 0xeb, 0xcf, 0x55, 0x45, 0x54, 0x6f),
      _mm_set_pi8(0xa0, 0x79, 0x92, 0xa9, 0xb7, 0x25, 0x2d, 0x88),
      _mm_set_pi8(0xff, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    __m64 r = _mm_cmpgt_pi8(test_vec[i].a, test_vec[i].b);
    assert_m64_pi8(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simd_mm_cmpgt_pi16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    __m64 a;
    __m64 b;
    __m64 r;
  } test_vec[8] = {
    { _mm_set_pi16(0x6a97, 0xbbdb, 0x1ebc, 0x4543),
      _mm_set_pi16(0x827e, 0xcf9b, 0xc297, 0xd6df),
      _mm_set_pi16(0xffff, 0x0000, 0xffff, 0xffff) },
    { _mm_set_pi16(0xa4dd, 0x4b52, 0x6c3e, 0x1200),
      _mm_set_pi16(0x807a, 0xf6f1, 0x4cfe, 0x6351),
      _mm_set_pi16(0xffff, 0xffff, 0xffff, 0x0000) },
    { _mm_set_pi16(0x72a6, 0xcfbc, 0xb93b, 0x8e02),
      _mm_set_pi16(0x271f, 0xecf1, 0x7815, 0xefd0),
      _mm_set_pi16(0xffff, 0x0000, 0x0000, 0x0000) },
    { _mm_set_pi16(0x77e9, 0xef89, 0x7b44, 0x2e89),
      _mm_set_pi16(0x95d8, 0x4503, 0x8911, 0xf77d),
      _mm_set_pi16(0xffff, 0x0000, 0xffff, 0xffff) },
    { _mm_set_pi16(0x23f7, 0x12b9, 0x9fec, 0x2765),
      _mm_set_pi16(0xb6d9, 0xfc5f, 0x1b8b, 0x2295),
      _mm_set_pi16(0xffff, 0xffff, 0x0000, 0xffff) },
    { _mm_set_pi16(0x58ce, 0x1702, 0xf25e, 0x9e9e),
      _mm_set_pi16(0x5c68, 0x38d4, 0x7c3e, 0xb835),
      _mm_set_pi16(0x0000, 0x0000, 0x0000, 0x0000) },
    { _mm_set_pi16(0x8fac, 0x08a3, 0xc30b, 0x82f6),
      _mm_set_pi16(0xd060, 0xd581, 0x703b, 0x1ee7),
      _mm_set_pi16(0x0000, 0xffff, 0x0000, 0x0000) },
    { _mm_set_pi16(0xda52, 0xdea0, 0xfcb5, 0x2f6c),
      _mm_set_pi16(0x10e4, 0x740a, 0x3563, 0xdc5d),
      _mm_set_pi16(0x0000, 0x0000, 0x0000, 0xffff) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    __m64 r = _mm_cmpgt_pi16(test_vec[i].a, test_vec[i].b);
    assert_m64_pi16(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simd_mm_cmpgt_pi32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    __m64 a;
    __m64 b;
    __m64 r;
  } test_vec[8] = {
    { _mm_set_pi32(0xbbdb6a97, 0x45431ebc),
      _mm_set_pi32(0xcf9b827e, 0xd6dfc297),
      _mm_set_pi32(0x00000000, 0xffffffff) },
    { _mm_set_pi32(0x4b52a4dd, 0x12006c3e),
      _mm_set_pi32(0xf6f1807a, 0x63514cfe),
      _mm_set_pi32(0xffffffff, 0x00000000) },
    { _mm_set_pi32(0xcfbc72a6, 0x8e02b93b),
      _mm_set_pi32(0xecf1271f, 0xefd07815),
      _mm_set_pi32(0x00000000, 0x00000000) },
    { _mm_set_pi32(0xef8977e9, 0x2e897b44),
      _mm_set_pi32(0x450395d8, 0xf77d8911),
      _mm_set_pi32(0x00000000, 0xffffffff) },
    { _mm_set_pi32(0x12b923f7, 0x27659fec),
      _mm_set_pi32(0xfc5fb6d9, 0x22951b8b),
      _mm_set_pi32(0xffffffff, 0xffffffff) },
    { _mm_set_pi32(0x170258ce, 0x9e9ef25e),
      _mm_set_pi32(0x38d45c68, 0xb8357c3e),
      _mm_set_pi32(0x00000000, 0x00000000) },
    { _mm_set_pi32(0x08a38fac, 0x82f6c30b),
      _mm_set_pi32(0xd581d060, 0x1ee7703b),
      _mm_set_pi32(0xffffffff, 0x00000000) },
    { _mm_set_pi32(0xdea0da52, 0x2f6cfcb5),
      _mm_set_pi32(0x740a10e4, 0xdc5d3563),
      _mm_set_pi32(0x00000000, 0xffffffff) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    __m64 r = _mm_cmpgt_pi32(test_vec[i].a, test_vec[i].b);
    assert_m64_pi32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

/*** SSE ***/

#define assert_m128_ps(a, cmp, b)					\
  do {									\
    munit_assert_float(((float*) (&a))[0], cmp, ((float*) (&b))[0]);	\
    munit_assert_float(((float*) (&a))[1], cmp, ((float*) (&b))[1]);	\
    munit_assert_float(((float*) (&a))[2], cmp, ((float*) (&b))[2]);	\
    munit_assert_float(((float*) (&a))[3], cmp, ((float*) (&b))[3]);	\
  } while (0)

static MunitResult
test_simd_mm_set_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  float d[4];
  munit_rand_memory(sizeof(d), (uint8_t*) d);

  __m128 x = _mm_set_ps(d[0], d[1], d[2], d[3]);

  float* f = (float*) &x;
  munit_assert_float(f[0], ==, d[3]);
  munit_assert_float(f[1], ==, d[2]);
  munit_assert_float(f[2], ==, d[1]);
  munit_assert_float(f[3], ==, d[0]);

  return MUNIT_OK;
}

static MunitResult
test_simd_mm_set1_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  float d;
  munit_rand_memory(sizeof(d), (uint8_t*) &d);

  __m128 x = _mm_set1_ps(d);

  float* f = (float*) &x;
  munit_assert_float(f[0], ==, d);
  munit_assert_float(f[1], ==, d);
  munit_assert_float(f[2], ==, d);
  munit_assert_float(f[3], ==, d);

  return MUNIT_OK;
}

static MunitResult
test_simd_mm_add_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const __m128 expected = _mm_set_ps(6.0f, 8.0f, 10.0f, 12.0f);

  __m128 a = _mm_set_ps(1.0f, 2.0f, 3.0f, 4.0f);
  __m128 b = _mm_set_ps(5.0f, 6.0f, 7.0f, 8.0f);
  __m128 r = _mm_add_ps(a, b);

  assert_m128_ps(r, ==, expected);

  return MUNIT_OK;
}

static MunitResult
test_simd_mm_add_ss(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const __m128 expected = _mm_set_ps(1.0f, 2.0f, 3.0f, 12.0f);

  __m128 a = _mm_set_ps(1.0f, 2.0f, 3.0f, 4.0f);
  __m128 b = _mm_set_ps(5.0f, 6.0f, 7.0f, 8.0f);
  __m128 r = _mm_add_ss(a, b);

  assert_m128_ps(r, ==, expected);

  return MUNIT_OK;
}

/* static __m128 test_rand_m128(void) { */
/*   __m128 v; */
/*   v[0] = (float) munit_rand_double(); */
/*   v[1] = (float) munit_rand_double(); */
/*   v[2] = (float) munit_rand_double(); */
/*   v[3] = (float) munit_rand_double(); */
/*   return v; */
/* } */

static MunitResult
test_simd_mm_and_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  /* __m128 a = test_rand_m128(); */
  /* __m128 b = test_rand_m128(); */

  /* float expected[] = { */
  /*   flt_bitwise_and(a[0], b[0]), */
  /*   flt_bitwise_and(a[1], b[1]), */
  /*   flt_bitwise_and(a[2], b[2]), */
  /*   flt_bitwise_and(a[3], b[3]), */
  /* }; */

  /* __m128 r = _mm_and_ps(a, b); */

  /* assert_m128_ps(r, ==, expected); */

  return MUNIT_FAIL;
}

union test_m128 {
  __m128 flt;
  unsigned int u32 __attribute__((__vector_size__(16)));
};

#define assert_test_m128_equal(a, b)			\
  do {							\
    munit_assert_uint((a).u32[0], ==, (b).u32[0]);	\
    munit_assert_uint((a).u32[1], ==, (b).u32[1]);	\
    munit_assert_uint((a).u32[2], ==, (b).u32[2]);	\
    munit_assert_uint((a).u32[3], ==, (b).u32[3]);	\
  } while (0)

static MunitResult
test_simd_mm_andnot_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    union test_m128 a;
    union test_m128 b;
    union test_m128 r;
  } test_vec[] = {
    { { .u32 = { 0x68a765a6U, 0x3615220eU, 0xf27caeb4U, 0x145357a5U } },
      { .u32 = { 0x7db442f9U, 0xc2f92119U, 0xdf75482eU, 0xa5d29ccaU } },
      { .u32 = { 0x15100259U, 0xc0e80111U, 0x0d01400aU, 0xa180884aU } } },
    { { .u32 = { 0xbac21a36U, 0x1b8c1a30U, 0x207e65f1U, 0x7e986bc6U } },
      { .u32 = { 0xb4e0053fU, 0xb1b443c2U, 0x1df73f23U, 0xb88c9b63U } },
      { .u32 = { 0x04200509U, 0xa03041c2U, 0x1d811a02U, 0x80049021U } } },
    { { .u32 = { 0x9f9907b0U, 0x266cf90bU, 0xefbcb2daU, 0x63721e2fU } },
      { .u32 = { 0xb418e8e0U, 0x04c49252U, 0x85f1d529U, 0x20ab72fcU } },
      { .u32 = { 0x2000e840U, 0x00800250U, 0x00414521U, 0x008960d0U } } },
    { { .u32 = { 0x32a6778fU, 0x927fa890U, 0x2f76ea91U, 0x9fdc18a3U } },
      { .u32 = { 0x9a45c22bU, 0xfb88b4f5U, 0x8d063b31U, 0x832b9acdU } },
      { .u32 = { 0x88418020U, 0x69801465U, 0x80001120U, 0x0023824cU } } },
    { { .u32 = { 0x659de4f8U, 0xf213fa5eU, 0xc6c9e0beU, 0x6b9bf277U } },
      { .u32 = { 0x31908876U, 0x1eeec04cU, 0x5310af8fU, 0xef14b6d9U } },
      { .u32 = { 0x10000806U, 0x0cec0000U, 0x11100f01U, 0x84040488U } } },
    { { .u32 = { 0x6d451104U, 0x027c2d5cU, 0xdc87cb64U, 0x6bf717a5U } },
      { .u32 = { 0x01e81e45U, 0xa1fea0d1U, 0x68287855U, 0x54e0538dU } },
      { .u32 = { 0x00a80e41U, 0xa1828081U, 0x20283011U, 0x14004008U } } },
    { { .u32 = { 0xb1e89e3aU, 0x6d79a9c6U, 0x43e7d670U, 0x98a011a6U } },
      { .u32 = { 0x96a71891U, 0x43f287c0U, 0x125aace7U, 0x8e69b84bU } },
      { .u32 = { 0x06070081U, 0x02820600U, 0x10182887U, 0x0649a849U } } },
    { { .u32 = { 0xe497a675U, 0x9ab8e09eU, 0x25f2ae74U, 0xfc5647eaU } },
      { .u32 = { 0x045e24cdU, 0xd72971afU, 0x1ec71d1fU, 0x9f4d091dU } },
      { .u32 = { 0x00480088U, 0x45011121U, 0x1a05110bU, 0x03090815U } } }
  };

  /* for (size_t i = 0 ; i < 8; i++) { */
  /*   union test_m128 a, b, r; */
  /*   munit_rand_memory(sizeof(a), (uint8_t*) &a); */
  /*   munit_rand_memory(sizeof(b), (uint8_t*) &b); */

  /*   r.flt = _mm_andnot_ps(a.flt, b.flt); */

  /*   printf("{ { .u32 = { 0x%08xU, 0x%08xU, 0x%08xU, 0x%08xU } },\n", a.u32[0], a.u32[1], a.u32[2], a.u32[3]); */
  /*   printf("  { .u32 = { 0x%08xU, 0x%08xU, 0x%08xU, 0x%08xU } },\n", b.u32[0], b.u32[1], b.u32[2], b.u32[3]); */
  /*   printf("  { .u32 = { 0x%08xU, 0x%08xU, 0x%08xU, 0x%08xU } } },\n", r.u32[0], r.u32[1], r.u32[2], r.u32[3]); */
  /* } */

  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    union test_m128 r;
    r.flt = _mm_andnot_ps(test_vec[i].a.flt, test_vec[i].b.flt);

    assert_test_m128_equal(r, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simd_mm_sub_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const __m128 expected = _mm_set1_ps(-4.0f);

  __m128 a = _mm_set_ps(1.0f, 2.0f, 3.0f, 4.0f);
  __m128 b = _mm_set_ps(5.0f, 6.0f, 7.0f, 8.0f);
  __m128 sum = _mm_sub_ps(a, b);

  assert_m128_ps(sum, ==, expected);

  return MUNIT_OK;
}

static MunitTest test_suite_tests[] = {
  { (char*) "/mmx/mm_set_pi8",     test_simd_mm_set_pi8,     NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mmx/mm_set_pi16",    test_simd_mm_set_pi16,    NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mmx/mm_set_pi32",    test_simd_mm_set_pi32,    NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mmx/mm_set1_pi8",    test_simd_mm_set1_pi8,    NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mmx/mm_set1_pi16",   test_simd_mm_set1_pi16,   NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mmx/mm_set1_pi32",   test_simd_mm_set1_pi32,   NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mmx/mm_setr_pi8",    test_simd_mm_setr_pi8,    NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mmx/mm_setr_pi16",   test_simd_mm_setr_pi16,   NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mmx/mm_setr_pi32",   test_simd_mm_setr_pi32,   NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mmx/mm_add_pi8",     test_simd_mm_add_pi8,     NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mmx/mm_add_pi16",    test_simd_mm_add_pi16,    NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mmx/mm_add_pi32",    test_simd_mm_add_pi32,    NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mmx/mm_adds_pi8",    test_simd_mm_adds_pi8,    NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mmx/mm_adds_pi16",   test_simd_mm_adds_pi16,   NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mmx/mm_and_si64",    test_simd_mm_and_si64,    NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mmx/mm_andnot_si64", test_simd_mm_andnot_si64, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mmx/mm_cmpeq_pi8",   test_simd_mm_cmpeq_pi8,   NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mmx/mm_cmpeq_pi16",  test_simd_mm_cmpeq_pi16,  NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mmx/mm_cmpeq_pi32",  test_simd_mm_cmpeq_pi32,  NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mmx/mm_cmpgt_pi8",   test_simd_mm_cmpgt_pi8,   NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mmx/mm_cmpgt_pi16",  test_simd_mm_cmpgt_pi16,  NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mmx/mm_cmpgt_pi32",  test_simd_mm_cmpgt_pi32,  NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },

  { (char*) "/sse/mm_set_ps",      test_simd_mm_set_ps,      NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/sse/mm_set1_ps",     test_simd_mm_set1_ps,     NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/sse/mm_add_ps",      test_simd_mm_add_ps,      NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/sse/mm_add_ss",      test_simd_mm_add_ss,      NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/sse/mm_and_ps",      test_simd_mm_and_ps,      NULL, NULL, MUNIT_TEST_OPTION_TODO, NULL },
  { (char*) "/sse/mm_andnot_ps",   test_simd_mm_andnot_ps,   NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },

  { (char*) "/sse/mm_sub_ps", test_simd_mm_sub_ps, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};

static const MunitSuite test_suite = {
#if defined(TEST_NATIVE)
  (char*) "/native",
#else
  (char*) "/emul",
#endif
  test_suite_tests, NULL, 1, MUNIT_SUITE_OPTION_NONE
};

int main(int argc, char* argv[MUNIT_ARRAY_PARAM(argc + 1)]) {
  return munit_suite_main(&test_suite, NULL, argc, argv);
}
