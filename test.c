#define SIMDE__EMULATE_NATIVE

#if defined(TEST_NATIVE)
#  define SIMDE__MMX_NATIVE
#  define SIMDE__SSE_NATIVE
#endif

#include <limits.h>

#include "sse.h"
#include "munit/munit.h"

#define assert_m128_ps(a, cmp, b)      \
  munit_assert_float((a)[0], cmp, (b)[0]); \
  munit_assert_float((a)[1], cmp, (b)[1]); \
  munit_assert_float((a)[2], cmp, (b)[2]); \
  munit_assert_float((a)[3], cmp, (b)[3]);

#define assert_m128_eq(a, b) \
  munit_assert_double_equal((a)[0], (b)[0], 10); \
  munit_assert_double_equal((a)[1], (b)[1], 10); \
  munit_assert_double_equal((a)[2], (b)[2], 10); \
  munit_assert_double_equal((a)[3], (b)[3], 10);

/*** MMX ***/

static MunitResult
test_simd_mm_set_pi8(const MunitParameter params[], void* data) {
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
  int v = (int) munit_rand_int_range(INT_MIN, INT_MAX);

  __m64 x = _mm_set1_pi32(v);
  int* r = (int*) &x;

  munit_assert_int8(r[0], ==, v);
  munit_assert_int8(r[1], ==, v);

  return MUNIT_OK;
}

static MunitResult
test_simd_mm_setr_pi8(const MunitParameter params[], void* data) {
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
  int d[8 / sizeof(int)];
  munit_rand_memory(sizeof(d), (uint8_t*) d);

  __m64 x = _mm_setr_pi32(d[0], d[1]);
  int* i = (int*) &x;

  munit_assert_int(i[0], ==, d[0]);
  munit_assert_int(i[1], ==, d[1]);

  return MUNIT_OK;
}

/*** SSE ***/

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

static float flt_bitwise_and(float a, float b) {
  unsigned int r = *((unsigned int*) &a) & *((unsigned int*) &b);
  return *((float *) &r);
}

static __m128 test_rand_m128(void) {
  __m128 v;
  v[0] = (float) munit_rand_double();
  v[1] = (float) munit_rand_double();
  v[2] = (float) munit_rand_double();
  v[3] = (float) munit_rand_double();
  return v;
}

static MunitResult
test_simd_mm_and_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  __m128 a = test_rand_m128();
  __m128 b = test_rand_m128();

  float expected[] = {
    flt_bitwise_and(a[0], b[0]),
    flt_bitwise_and(a[1], b[1]),
    flt_bitwise_and(a[2], b[2]),
    flt_bitwise_and(a[3], b[3]),
  };

  __m128 r = _mm_and_ps(a, b);

  assert_m128_ps(r, ==, expected);

  return MUNIT_OK;
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
  { (char*) "/mmx/mm_set1_pi16", test_simd_mm_set1_pi8,  NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mmx/mm_set1_pi32", test_simd_mm_set1_pi8,  NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mmx/mm_setr_pi8",  test_simd_mm_setr_pi8,  NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mmx/mm_setr_pi16", test_simd_mm_setr_pi16, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/mmx/mm_setr_pi32", test_simd_mm_setr_pi32, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },

  { (char*) "/sse/mm_set_ps",    test_simd_mm_set_ps,    NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/sse/mm_set1_ps",   test_simd_mm_set1_ps,   NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/sse/mm_add_ps",    test_simd_mm_add_ps,    NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/sse/mm_add_ss",    test_simd_mm_add_ss,    NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/sse/mm_and_ps",    test_simd_mm_and_ps,    NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
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
