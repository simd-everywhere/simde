#if !defined(SIMDE_TEST_H)
#define SIMDE_TEST_H

#if !defined(TEST_NATIVE)
#  define SIMDE__MMX_NO_NATIVE
#  define SIMDE__SSE_NO_NATIVE
#  define SIMDE__SSE2_NO_NATIVE
#else
#  if defined(__GNUC__) && !defined(__clang__) && !defined(__INTEL_COMPILER)
#    pragma GCC target("sse4.1")
#  endif
#endif

#include <stdio.h>
#include <limits.h>

#include "../hedley.h"
#include "munit/munit.h"

const MunitSuite simde_mmx_test_suite;
const MunitSuite simde_sse_test_suite;
const MunitSuite simde_sse2_test_suite;

void debug_array_u32(const char* prefix, size_t nmemb, uint32_t v[HEDLEY_ARRAY_PARAM(nmemb)]);
void random_floatv(size_t nmemb, float v[HEDLEY_ARRAY_PARAM(nmemb)]);

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
    munit_assert_int64(((long long int*) (&a))[0], cmp, ((long long int*) (&b))[0]);	\
  } while (0)

#define assert_m64_pu16(a, cmp, b)					\
  do {									\
    munit_assert_ushort(((unsigned short*) (&a))[0], cmp, ((unsigned short*) (&b))[0]);	\
    munit_assert_ushort(((unsigned short*) (&a))[1], cmp, ((unsigned short*) (&b))[1]);	\
    munit_assert_ushort(((unsigned short*) (&a))[2], cmp, ((unsigned short*) (&b))[2]);	\
    munit_assert_ushort(((unsigned short*) (&a))[3], cmp, ((unsigned short*) (&b))[3]);	\
  } while (0)

#define assert_m64_pu8(a, cmp, b)					\
  do {									\
    munit_assert_uint8(((unsigned char*) (&a))[0], cmp, ((unsigned char*) (&b))[0]);	\
    munit_assert_uint8(((unsigned char*) (&a))[1], cmp, ((unsigned char*) (&b))[1]);	\
    munit_assert_uint8(((unsigned char*) (&a))[2], cmp, ((unsigned char*) (&b))[2]);	\
    munit_assert_uint8(((unsigned char*) (&a))[3], cmp, ((unsigned char*) (&b))[3]);	\
    munit_assert_uint8(((unsigned char*) (&a))[4], cmp, ((unsigned char*) (&b))[4]);	\
    munit_assert_uint8(((unsigned char*) (&a))[5], cmp, ((unsigned char*) (&b))[5]);	\
    munit_assert_uint8(((unsigned char*) (&a))[6], cmp, ((unsigned char*) (&b))[6]);	\
    munit_assert_uint8(((unsigned char*) (&a))[7], cmp, ((unsigned char*) (&b))[7]);	\
  } while (0)

#endif /* !defined(SIMDE_TEST_H) */
