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

#define assert_m64_pi32(a, cmp, b)					\
  do {									\
    munit_assert_int(((int*) (&a))[0], cmp, ((int*) (&b))[0]);	\
    munit_assert_int(((int*) (&a))[1], cmp, ((int*) (&b))[1]);	\
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
    assert_m64_pi16(r,
		    ==,
		    test_vec[i].r);
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
  { (char*) "/mmx/mm_set_pi8",   test_simd_mm_set_pi8,   NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mmx/mm_set_pi16",  test_simd_mm_set_pi16,  NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mmx/mm_set_pi32",  test_simd_mm_set_pi32,  NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mmx/mm_set1_pi8",  test_simd_mm_set1_pi8,  NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mmx/mm_set1_pi16", test_simd_mm_set1_pi16, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mmx/mm_set1_pi32", test_simd_mm_set1_pi32, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mmx/mm_setr_pi8",  test_simd_mm_setr_pi8,  NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mmx/mm_setr_pi16", test_simd_mm_setr_pi16, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mmx/mm_setr_pi32", test_simd_mm_setr_pi32, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mmx/mm_add_pi8",   test_simd_mm_add_pi8,   NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mmx/mm_add_pi16",  test_simd_mm_add_pi16,  NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mmx/mm_add_pi32",  test_simd_mm_add_pi32,  NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },

  { (char*) "/sse/mm_set_ps",    test_simd_mm_set_ps,    NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/sse/mm_set1_ps",   test_simd_mm_set1_ps,   NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/sse/mm_add_ps",    test_simd_mm_add_ps,    NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/sse/mm_add_ss",    test_simd_mm_add_ss,    NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/sse/mm_and_ps",    test_simd_mm_and_ps,    NULL, NULL, MUNIT_TEST_OPTION_TODO, NULL },
  { (char*) "/sse/mm_andnot_ps", test_simd_mm_andnot_ps, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },

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
