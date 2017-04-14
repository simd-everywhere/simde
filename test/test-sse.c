#include "test.h"
#include "../sse.h"

#include <stdio.h>

inline void print_pi8(const char* prefix, __m64 v) {
  char* vp = (char*) &v;
  printf("%s: 0x%02hhx 0x%02hhx 0x%02hhx 0x%02hhx 0x%02hhx 0x%02hhx 0x%02hhx 0x%02hhx\n", prefix, vp[0], vp[1], vp[2], vp[3], vp[4], vp[5], vp[6], vp[7]);
}

inline void print_pi16(const char* prefix, __m64 v) {
  short* vp = (short*) &v;
  printf("%s: 0x%04hx 0x%04hx 0x%04hx 0x%04hx\n", prefix, vp[0], vp[1], vp[2], vp[3]);
}

inline void print_pi32(const char* prefix, __m64 v) {
  int* vp = (int*) &v;
  printf("%s: 0x%08x 0x%08x\n", prefix, vp[0], vp[1]);
}

inline void print_si64(const char* prefix, __m64 v) {
  printf("%s: 0x%016lx\n", prefix, *((int64_t*) &v));
}

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

static MunitResult
test_simd_mm_and_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  return MUNIT_FAIL;
}

/* I'll probably move these into µnit, but I want to play around with
   them for a while first. */

#define simde_assert_array_full(prefix, suffix, T, fmt, nmemb, a, op, b) \
  do {									\
    const T* simde__tmp_a_ = (a);					\
    const T* simde__tmp_b_ = (b);					\
    for (size_t simde__i_ = 0 ; simde__i_ < nmemb ; simde__i_++) {	\
      if (!(simde__tmp_a_[simde__i_] op simde__tmp_b_[simde__i_])) {			\
	munit_errorf("assertion failed: (" #a ")[%" MUNIT_SIZE_MODIFIER "u] " #op " (" #b ")[%" MUNIT_SIZE_MODIFIER "u] (" prefix "%" fmt suffix " " #op " " prefix "%" fmt suffix ")", simde__i_, simde__i_, simde__tmp_a_[simde__i_], simde__tmp_b_[simde__i_]); \
      }									\
    }									\
  } while (0)


#define simde_assert_typev(T, fmt, nmemb, a, op, b)		\
  simde_assert_array_full("", "", T, fmt, nmemb, a, op, b)

#define simde_assert_floatv(nmemb, a, op, b)	\
  simde_assert_typev(float, "g", nmemb, a, op, b)

#define simde_assert_intv(nmemb, a, op, b) \
  simde_assert_typev(int, "d", nmemb, a, op, b)

#define simde_assert_uintv(nmemb, a, op, b) \
  simde_assert_typev(int, "u", nmemb, a, op, b)

/* These probably won't go into µnit; they're similar to the
   simde_assert_*v macros above, but print in hex. */

#define simde_assert_int32vx(nmemb, a, op, b) \
  simde_assert_array_full("0x", "", int, "08x", 4, a, op, b)

#define simde_assert_uint32vx(nmemb, a, op, b) \
  simde_assert_array_full("0x", "", unsigned int, "08x", 4, a, op, b)

/* SIMDe-specific */

#define simde_assert_m128_i32(a, op, b) \
  simde_assert_int32vx(4, (int*) &(a), op, (int*) &(b))

#define simde_assert_m128_u32(a, op, b) \
  simde_assert_uint32vx(4, (unsigned int*) &(a), op, (unsigned int*) &(b))

static inline __m128
simde_m128_set_u32(unsigned int a, unsigned int b, unsigned int c, unsigned int d) {
  __m128 r;
  unsigned int* rp = (unsigned int*) &r;
  rp[0] = a;
  rp[1] = b;
  rp[2] = c;
  rp[3] = d;
  return r;
}

static MunitResult
test_simd_mm_andnot_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    __m128 a;
    __m128 b;
    __m128 r;
  } test_vec[] = {
    { simde_m128_set_u32(0x68a765a6U, 0x3615220eU, 0xf27caeb4U, 0x145357a5U),
      simde_m128_set_u32(0x7db442f9U, 0xc2f92119U, 0xdf75482eU, 0xa5d29ccaU),
      simde_m128_set_u32(0x15100259U, 0xc0e80111U, 0x0d01400aU, 0xa180884aU) },
    { simde_m128_set_u32(0xbac21a36U, 0x1b8c1a30U, 0x207e65f1U, 0x7e986bc6U),
      simde_m128_set_u32(0xb4e0053fU, 0xb1b443c2U, 0x1df73f23U, 0xb88c9b63U),
      simde_m128_set_u32(0x04200509U, 0xa03041c2U, 0x1d811a02U, 0x80049021U) },
    { simde_m128_set_u32(0x9f9907b0U, 0x266cf90bU, 0xefbcb2daU, 0x63721e2fU),
      simde_m128_set_u32(0xb418e8e0U, 0x04c49252U, 0x85f1d529U, 0x20ab72fcU),
      simde_m128_set_u32(0x2000e840U, 0x00800250U, 0x00414521U, 0x008960d0U) },
    { simde_m128_set_u32(0x32a6778fU, 0x927fa890U, 0x2f76ea91U, 0x9fdc18a3U),
      simde_m128_set_u32(0x9a45c22bU, 0xfb88b4f5U, 0x8d063b31U, 0x832b9acdU),
      simde_m128_set_u32(0x88418020U, 0x69801465U, 0x80001120U, 0x0023824cU) },
    { simde_m128_set_u32(0x659de4f8U, 0xf213fa5eU, 0xc6c9e0beU, 0x6b9bf277U),
      simde_m128_set_u32(0x31908876U, 0x1eeec04cU, 0x5310af8fU, 0xef14b6d9U),
      simde_m128_set_u32(0x10000806U, 0x0cec0000U, 0x11100f01U, 0x84040488U) },
    { simde_m128_set_u32(0x6d451104U, 0x027c2d5cU, 0xdc87cb64U, 0x6bf717a5U),
      simde_m128_set_u32(0x01e81e45U, 0xa1fea0d1U, 0x68287855U, 0x54e0538dU),
      simde_m128_set_u32(0x00a80e41U, 0xa1828081U, 0x20283011U, 0x14004008U) },
    { simde_m128_set_u32(0xb1e89e3aU, 0x6d79a9c6U, 0x43e7d670U, 0x98a011a6U),
      simde_m128_set_u32(0x96a71891U, 0x43f287c0U, 0x125aace7U, 0x8e69b84bU),
      simde_m128_set_u32(0x06070081U, 0x02820600U, 0x10182887U, 0x0649a849U) },
    { simde_m128_set_u32(0xe497a675U, 0x9ab8e09eU, 0x25f2ae74U, 0xfc5647eaU),
      simde_m128_set_u32(0x045e24cdU, 0xd72971afU, 0x1ec71d1fU, 0x9f4d091dU),
      simde_m128_set_u32(0x00480088U, 0x45011121U, 0x1a05110bU, 0x03090815U) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    __m128 r;
    r = _mm_andnot_ps(test_vec[i].a, test_vec[i].b);
    simde_assert_m128_i32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simd_mm_avg_pu16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    __m64 a;
    __m64 b;
    __m64 r;
  } test_vec[] = {
    { _mm_set_pi16(0x17f0, 0x1d12, 0x84d4, 0xeba7),
      _mm_set_pi16(0x7b42, 0x57c8, 0x476d, 0x63a8),
      _mm_set_pi16(0x4999, 0x3a6d, 0x6621, 0xa7a8) },
    { _mm_set_pi16(0xb202, 0x0f18, 0x3692, 0xbdb1),
      _mm_set_pi16(0x6fa1, 0xcff5, 0xff17, 0x8952),
      _mm_set_pi16(0x90d2, 0x6f87, 0x9ad5, 0xa382) },
    { _mm_set_pi16(0xcf1f, 0x3628, 0x83c5, 0xe2f0),
      _mm_set_pi16(0x32cf, 0x24dc, 0xddc7, 0xa531),
      _mm_set_pi16(0x80f7, 0x2d82, 0xb0c6, 0xc411) },
    { _mm_set_pi16(0xc61c, 0xebfe, 0x53f3, 0x6af8),
      _mm_set_pi16(0xb2be, 0x3b7c, 0xd646, 0xf5db),
      _mm_set_pi16(0xbc6d, 0x93bd, 0x951d, 0xb06a) },
    { _mm_set_pi16(0x2d75, 0x8696, 0xac92, 0x4be4),
      _mm_set_pi16(0xa670, 0x20d1, 0x5440, 0x5836),
      _mm_set_pi16(0x69f3, 0x53b4, 0x8069, 0x520d) },
    { _mm_set_pi16(0xc169, 0xc53a, 0x0562, 0x7fc4),
      _mm_set_pi16(0x2c37, 0xeb5f, 0x7086, 0xc453),
      _mm_set_pi16(0x76d0, 0xd84d, 0x3af4, 0xa20c) },
    { _mm_set_pi16(0x2d16, 0xa1eb, 0x56bd, 0x87a5),
      _mm_set_pi16(0x44d2, 0xd7c8, 0x02b6, 0xd1e0),
      _mm_set_pi16(0x38f4, 0xbcda, 0x2cba, 0xacc3) },
    { _mm_set_pi16(0x918e, 0x1c4e, 0xe910, 0x1816),
      _mm_set_pi16(0x8630, 0x1e27, 0xe859, 0xdf6a),
      _mm_set_pi16(0x8bdf, 0x1d3b, 0xe8b5, 0x7bc0) },
    { _mm_set_pi16(0xbefa, 0xcb05, 0x36f0, 0xc0b6),
      _mm_set_pi16(0x4a77, 0xfd64, 0xfb05, 0x550c),
      _mm_set_pi16(0x84b9, 0xe435, 0x98fb, 0x8ae1) },
    { _mm_set_pi16(0xdc01, 0xa585, 0xa004, 0xe495),
      _mm_set_pi16(0x14aa, 0xc327, 0x8fc7, 0x2d75),
      _mm_set_pi16(0x7856, 0xb456, 0x97e6, 0x8905) },
    { _mm_set_pi16(0xd015, 0x5fa8, 0x45c6, 0x286b),
      _mm_set_pi16(0x83ee, 0x7908, 0x9036, 0x7427),
      _mm_set_pi16(0xaa02, 0x6c58, 0x6afe, 0x4e49) },
    { _mm_set_pi16(0x0f0a, 0xa363, 0x0d88, 0x3ab0),
      _mm_set_pi16(0xdfa0, 0x604c, 0x0f68, 0x1aef),
      _mm_set_pi16(0x7755, 0x81d8, 0x0e78, 0x2ad0) },
    { _mm_set_pi16(0x680e, 0x33e3, 0xd83f, 0x75d8),
      _mm_set_pi16(0x54bf, 0x1fa6, 0x50a9, 0xbf47),
      _mm_set_pi16(0x5e67, 0x29c5, 0x9474, 0x9a90) },
    { _mm_set_pi16(0xe38a, 0x410b, 0x96b6, 0xe13b),
      _mm_set_pi16(0xf64a, 0x4490, 0x4565, 0x742c),
      _mm_set_pi16(0xecea, 0x42ce, 0x6e0e, 0xaab4) },
    { _mm_set_pi16(0x9293, 0xd89a, 0x3823, 0x5d17),
      _mm_set_pi16(0x745a, 0xd347, 0xe5a1, 0x2926),
      _mm_set_pi16(0x8377, 0xd5f1, 0x8ee2, 0x431f) },
    { _mm_set_pi16(0xaeac, 0x7278, 0x2343, 0xcd26),
      _mm_set_pi16(0xc004, 0x65ab, 0x2d47, 0x7148),
      _mm_set_pi16(0xb758, 0x6c12, 0x2845, 0x9f37) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    __m64 r = _mm_avg_pu16(test_vec[i].a, test_vec[i].b);
    assert_m64_pi16(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simd_mm_avg_pu8(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    __m64 a;
    __m64 b;
    __m64 r;
  } test_vec[16] = {
    { _mm_set_pi8(0x91, 0xe1, 0x7e, 0x06, 0x12, 0x2f, 0xf1, 0x7f),
      _mm_set_pi8(0xd1, 0xfc, 0x30, 0x76, 0x81, 0xc7, 0x76, 0x03),
      _mm_set_pi8(0xb1, 0xef, 0x57, 0x3e, 0x4a, 0x7b, 0xb4, 0x41) },
    { _mm_set_pi8(0x28, 0xe2, 0xc6, 0x08, 0xc6, 0xf1, 0x56, 0x1f),
      _mm_set_pi8(0xe8, 0x95, 0x6e, 0x04, 0x09, 0x51, 0xd2, 0xb3),
      _mm_set_pi8(0x88, 0xbc, 0x9a, 0x06, 0x68, 0xa1, 0x94, 0x69) },
    { _mm_set_pi8(0xc0, 0xc2, 0x13, 0x4c, 0x22, 0x94, 0x45, 0x19),
      _mm_set_pi8(0x10, 0x0f, 0x38, 0xff, 0xa0, 0x9f, 0x10, 0xe4),
      _mm_set_pi8(0x68, 0x69, 0x26, 0xa6, 0x61, 0x9a, 0x2b, 0x7f) },
    { _mm_set_pi8(0x1e, 0x80, 0x8f, 0x2a, 0x75, 0x0c, 0xbe, 0xe8),
      _mm_set_pi8(0x8d, 0x95, 0x48, 0x12, 0x5d, 0xed, 0x02, 0xff),
      _mm_set_pi8(0x56, 0x8b, 0x6c, 0x1e, 0x69, 0x7d, 0x60, 0xf4) },
    { _mm_set_pi8(0xbd, 0x28, 0x85, 0x34, 0xe4, 0x5d, 0x36, 0xff),
      _mm_set_pi8(0x7f, 0xfe, 0x2a, 0xf8, 0xc0, 0x72, 0x81, 0xcf),
      _mm_set_pi8(0x9e, 0x93, 0x58, 0x96, 0xd2, 0x68, 0x5c, 0xe7) },
    { _mm_set_pi8(0x33, 0x41, 0x89, 0x25, 0xcd, 0x5d, 0xba, 0x64),
      _mm_set_pi8(0x25, 0xee, 0xc1, 0xdf, 0x79, 0x43, 0x6a, 0x26),
      _mm_set_pi8(0x2c, 0x98, 0xa5, 0x82, 0xa3, 0x50, 0x92, 0x45) },
    { _mm_set_pi8(0xf0, 0xd0, 0x63, 0x95, 0xd8, 0x9e, 0xdf, 0xc9),
      _mm_set_pi8(0x83, 0x4f, 0x74, 0x6b, 0x67, 0x46, 0x8d, 0x5f),
      _mm_set_pi8(0xba, 0x90, 0x6c, 0x80, 0xa0, 0x72, 0xb6, 0x94) },
    { _mm_set_pi8(0x88, 0xbf, 0x20, 0xd2, 0x99, 0x57, 0x5b, 0x7d),
      _mm_set_pi8(0x85, 0xce, 0x9f, 0xfc, 0xd5, 0xa1, 0xaf, 0xba),
      _mm_set_pi8(0x87, 0xc7, 0x60, 0xe7, 0xb7, 0x7c, 0x85, 0x9c) },
    { _mm_set_pi8(0x1d, 0x88, 0xc2, 0xc4, 0xcf, 0x95, 0x3c, 0x27),
      _mm_set_pi8(0x84, 0xd6, 0x51, 0xf3, 0x4d, 0x28, 0x78, 0x9e),
      _mm_set_pi8(0x51, 0xaf, 0x8a, 0xdc, 0x8e, 0x5f, 0x5a, 0x63) },
    { _mm_set_pi8(0x7f, 0x7e, 0x22, 0xe5, 0x13, 0x92, 0x9a, 0xfa),
      _mm_set_pi8(0x5b, 0xd1, 0xd0, 0x82, 0x0e, 0x8b, 0xcf, 0x12),
      _mm_set_pi8(0x6d, 0xa8, 0x79, 0xb4, 0x11, 0x8f, 0xb5, 0x86) },
    { _mm_set_pi8(0x98, 0x86, 0xf1, 0xd3, 0xbd, 0x99, 0x22, 0x5c),
      _mm_set_pi8(0x65, 0xb2, 0x34, 0x36, 0x68, 0x16, 0xbe, 0xf9),
      _mm_set_pi8(0x7f, 0x9c, 0x93, 0x85, 0x93, 0x58, 0x70, 0xab) },
    { _mm_set_pi8(0xb2, 0x3b, 0x6f, 0xf0, 0x4a, 0xd1, 0x08, 0xd4),
      _mm_set_pi8(0x53, 0xe9, 0x83, 0xf8, 0xeb, 0x24, 0xf5, 0xd7),
      _mm_set_pi8(0x83, 0x92, 0x79, 0xf4, 0x9b, 0x7b, 0x7f, 0xd6) },
    { _mm_set_pi8(0x83, 0x6a, 0x3b, 0x8e, 0x5a, 0xf6, 0x9c, 0xc5),
      _mm_set_pi8(0x1c, 0xa3, 0xe7, 0x5b, 0x87, 0xa5, 0x06, 0x06),
      _mm_set_pi8(0x50, 0x87, 0x91, 0x75, 0x71, 0xce, 0x51, 0x66) },
    { _mm_set_pi8(0x5c, 0x3a, 0xa5, 0x0f, 0x3f, 0x23, 0x6a, 0x18),
      _mm_set_pi8(0x1a, 0xe4, 0xee, 0xf4, 0xec, 0xbc, 0xc9, 0x4e),
      _mm_set_pi8(0x3b, 0x8f, 0xca, 0x82, 0x96, 0x70, 0x9a, 0x33) },
    { _mm_set_pi8(0xa3, 0x77, 0x5c, 0x7e, 0x51, 0x77, 0xf1, 0xf4),
      _mm_set_pi8(0x2d, 0x3c, 0xd3, 0xbc, 0x5e, 0x32, 0xa6, 0x64),
      _mm_set_pi8(0x68, 0x5a, 0x98, 0x9d, 0x58, 0x55, 0xcc, 0xac) },
    { _mm_set_pi8(0x92, 0xb8, 0xc8, 0xb8, 0x4d, 0x82, 0xc4, 0xff),
      _mm_set_pi8(0xf7, 0x65, 0xea, 0xb9, 0x1d, 0x6f, 0xf1, 0x53),
      _mm_set_pi8(0xc5, 0x8f, 0xd9, 0xb9, 0x35, 0x79, 0xdb, 0xa9) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    __m64 r = _mm_avg_pu8(test_vec[i].a, test_vec[i].b);
    assert_m64_pi8(r, ==, test_vec[i].r);
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
  { (char*) "/sse/mm_set_ps",        test_simd_mm_set_ps,        NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/sse/mm_set1_ps",       test_simd_mm_set1_ps,       NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/sse/mm_add_ps",        test_simd_mm_add_ps,        NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/sse/mm_add_ss",        test_simd_mm_add_ss,        NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/sse/mm_and_ps",        test_simd_mm_and_ps,        NULL, NULL, MUNIT_TEST_OPTION_TODO, NULL },
  { (char*) "/sse/mm_andnot_ps",     test_simd_mm_andnot_ps,     NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/sse/mm_avg_pu16",      test_simd_mm_avg_pu16,      NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/sse/mm_avg_pu8",       test_simd_mm_avg_pu8,       NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },

  { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};

const MunitSuite simde_sse_test_suite = {
  (char*) "/sse",
  test_suite_tests,
  NULL,
  1,
  MUNIT_SUITE_OPTION_NONE
};
