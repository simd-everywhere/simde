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

#if !defined(SIMDE_TEST_H)
#define SIMDE_TEST_H

#include <stdio.h>
#include <limits.h>

#include "../hedley.h"
#include "munit/munit.h"

const MunitSuite simde_mmx_test_suite;
const MunitSuite simde_sse_test_suite;
const MunitSuite simde_sse2_test_suite;
const MunitSuite simde_sse3_test_suite;
const MunitSuite simde_ssse3_test_suite;
const MunitSuite simde_sse4_1_test_suite;
const MunitSuite simde_sse4_2_test_suite;

void debug_array_u8(const char* prefix, size_t nmemb, uint8_t v[HEDLEY_ARRAY_PARAM(nmemb)]);
void debug_array_u16(const char* prefix, size_t nmemb, uint16_t v[HEDLEY_ARRAY_PARAM(nmemb)]);
void debug_array_u32(const char* prefix, size_t nmemb, uint32_t v[HEDLEY_ARRAY_PARAM(nmemb)]);
void debug_array_u64(const char* prefix, size_t nmemb, uint64_t v[HEDLEY_ARRAY_PARAM(nmemb)]);
void debug_array_f32(const char* prefix, size_t nmemb, float v[HEDLEY_ARRAY_PARAM(nmemb)]);
void random_floatv(size_t nmemb, float v[HEDLEY_ARRAY_PARAM(nmemb)]);

double random_double_range(double min, double max);

#define TEST_PREFERRED_ITERATIONS (16384)

/* I'll probably move these into µnit, but I want to play around with
   them for a while first. */

#define simde_assert_array_full(prefix, suffix, T, fmt, nmemb, a, op, b) \
  do {									\
    const T* simde__tmp_a_ = (a);					\
    const T* simde__tmp_b_ = (b);					\
    for (size_t simde__i_ = 0 ; simde__i_ < nmemb ; simde__i_++) {	\
      if (!(simde__tmp_a_[simde__i_] op simde__tmp_b_[simde__i_])) {	\
	munit_errorf("assertion failed: (" #a ")[%" MUNIT_SIZE_MODIFIER "u] " #op " (" #b ")[%" MUNIT_SIZE_MODIFIER "u] (" prefix "%" fmt suffix " " #op " " prefix "%" fmt suffix ")", simde__i_, simde__i_, simde__tmp_a_[simde__i_], simde__tmp_b_[simde__i_]); \
      }									\
    }									\
  } while (0)

#define simde_assert_typev(T, fmt, nmemb, a, op, b)		\
  simde_assert_array_full("", "", T, fmt, nmemb, a, op, b)

#define simde_assert_floatv(nmemb, a, op, b)		\
  simde_assert_typev(float, "g", nmemb, a, op, b)

#define simde_assert_intv(nmemb, a, op, b)	\
  simde_assert_typev(int, "d", nmemb, a, op, b)

#define simde_assert_uintv(nmemb, a, op, b)	\
  simde_assert_typev(int, "u", nmemb, a, op, b)

/* These probably won't go into µnit; they're similar to the
   simde_assert_*v macros above, but print in hex. */

#define simde_assert_int8vx(nmemb, a, op, b)			\
  simde_assert_array_full("0x", "", munit_int8_t, "02" PRIx8, nmemb, a, op, b)
#define simde_assert_uint8vx(nmemb, a, op, b)				\
  simde_assert_array_full("0x", "", munit_uint8_t, "02" PRIx8, nmemb, a, op, b)
#define simde_assert_int16vx(nmemb, a, op, b)			\
  simde_assert_array_full("0x", "", munit_int16_t, "04" PRIx16, nmemb, a, op, b)
#define simde_assert_uint16vx(nmemb, a, op, b)				\
  simde_assert_array_full("0x", "", munit_uint16_t, "04" PRIx16, nmemb, a, op, b)
#define simde_assert_int32vx(nmemb, a, op, b)			\
  simde_assert_array_full("0x", "", munit_int32_t, "08" PRIx32, nmemb, a, op, b)
#define simde_assert_uint32vx(nmemb, a, op, b)				\
  simde_assert_array_full("0x", "", munit_uint32_t, "08" PRIx32, nmemb, a, op, b)
#define simde_assert_int64vx(nmemb, a, op, b)			\
  simde_assert_array_full("0x", "", munit_int64_t, "016" PRIx64, nmemb, a, op, b)
#define simde_assert_uint64vx(nmemb, a, op, b)				\
  simde_assert_array_full("0x", "", munit_uint64_t, "016" PRIx64, nmemb, a, op, b)

/* SIMDe-specific */

#define simde_assert_m64_i8(a, op, b) \
  simde_assert_int8vx(8, (int8_t*) &(a), op, (int8_t*) &(b))
#define simde_assert_m64_u8(a, op, b) \
  simde_assert_uint8vx(8, (uint8_t*) &(a), op, (uint8_t*) &(b))
#define simde_assert_m64_i16(a, op, b) \
  simde_assert_int16vx(4, (int16_t*) &(a), op, (int16_t*) &(b))
#define simde_assert_m64_u16(a, op, b) \
  simde_assert_uint16vx(4, (uint16_t*) &(a), op, (uint16_t*) &(b))
#define simde_assert_m64_i32(a, op, b) \
  simde_assert_int32vx(2, (int32_t*) &(a), op, (int32_t*) &(b))
#define simde_assert_m64_u32(a, op, b) \
  simde_assert_uint32vx(2, (uint32_t*) &(a), op, (uint32_t*) &(b))
#define simde_assert_m64_i64(a, op, b) \
  simde_assert_int64vx(1, (int64_t*) &(a), op, (int64_t*) &(b))
#define simde_assert_m64_u64(a, op, b) \
  simde_assert_uint64vx(1, (uint64_t*) &(a), op, (uint64_t*) &(b))

#define simde_assert_m128_i8(a, op, b) \
  simde_assert_int8vx(16, (int8_t*) &(a), op, (int8_t*) &(b))
#define simde_assert_m128_u8(a, op, b) \
  simde_assert_uint8vx(16, (uint8_t*) &(a), op, (uint8_t*) &(b))
#define simde_assert_m128_i16(a, op, b) \
  simde_assert_int16vx(8, (int16_t*) &(a), op, (int16_t*) &(b))
#define simde_assert_m128_u16(a, op, b) \
  simde_assert_uint16vx(8, (uint16_t*) &(a), op, (uint16_t*) &(b))
#define simde_assert_m128_i32(a, op, b) \
  simde_assert_int32vx(4, (int32_t*) &(a), op, (int32_t*) &(b))
#define simde_assert_m128_u32(a, op, b) \
  simde_assert_uint32vx(4, (uint32_t*) &(a), op, (uint32_t*) &(b))
#define simde_assert_m128_i64(a, op, b) \
  simde_assert_int64vx(2, (int64_t*) &(a), op, (int64_t*) &(b))
#define simde_assert_m128_u64(a, op, b) \
  simde_assert_uint64vx(2, (uint64_t*) &(a), op, (uint64_t*) &(b)y)
#define simde_assert_m128_f32(a, op, b) \
  simde_assert_typev(float, "f", 4, (float*) &(a), op, (float*) &(b))

/* SIMD floating-point conversion functions may or may not be the same
   as the normal FP conversion functions. */

#define simde_assert_int32_close(value, target) \
  do { \
    if (value != target && value != target + 1 && value != target - 1) \
      munit_errorf("assertion failed: %s == %s (%" PRId32 " == %" PRId32 ")", #value, #target, value, target); \
  } while (0)

#define simde_assert_int64_close(value, target) \
  do { \
    if (value != target && value != target + 1 && value != target - 1) \
      munit_errorf("assertion failed: %s == %s (%" PRId64 " == %" PRId64 ")", #value, #target, value, target); \
  } while (0)

/* Sometimes there are issues with specific compilers... */
#if defined(__PGI)
#  define SIMDE_SKIP_PGI(bug_url) return (munit_logf(MUNIT_LOG_DEBUG, "Test skipped; see <%s> for details", bug_url), MUNIT_SKIP)
#else
#  define SIMDE_SKIP_PGI(bug_url)
#endif

/* Macros to verify results */

#define assert_m128i_epi8(a, cmp, b)					\
  do {									\
    munit_assert_int8(((int8_t*) (&a))[ 0], cmp, ((int8_t*) (&b))[ 0]);	\
    munit_assert_int8(((int8_t*) (&a))[ 1], cmp, ((int8_t*) (&b))[ 1]);	\
    munit_assert_int8(((int8_t*) (&a))[ 2], cmp, ((int8_t*) (&b))[ 2]);	\
    munit_assert_int8(((int8_t*) (&a))[ 3], cmp, ((int8_t*) (&b))[ 3]);	\
    munit_assert_int8(((int8_t*) (&a))[ 4], cmp, ((int8_t*) (&b))[ 4]);	\
    munit_assert_int8(((int8_t*) (&a))[ 5], cmp, ((int8_t*) (&b))[ 5]);	\
    munit_assert_int8(((int8_t*) (&a))[ 6], cmp, ((int8_t*) (&b))[ 6]);	\
    munit_assert_int8(((int8_t*) (&a))[ 7], cmp, ((int8_t*) (&b))[ 7]);	\
    munit_assert_int8(((int8_t*) (&a))[ 8], cmp, ((int8_t*) (&b))[ 8]);	\
    munit_assert_int8(((int8_t*) (&a))[ 9], cmp, ((int8_t*) (&b))[ 9]);	\
    munit_assert_int8(((int8_t*) (&a))[10], cmp, ((int8_t*) (&b))[10]);	\
    munit_assert_int8(((int8_t*) (&a))[11], cmp, ((int8_t*) (&b))[11]);	\
    munit_assert_int8(((int8_t*) (&a))[12], cmp, ((int8_t*) (&b))[12]);	\
    munit_assert_int8(((int8_t*) (&a))[13], cmp, ((int8_t*) (&b))[13]);	\
    munit_assert_int8(((int8_t*) (&a))[14], cmp, ((int8_t*) (&b))[14]);	\
    munit_assert_int8(((int8_t*) (&a))[15], cmp, ((int8_t*) (&b))[15]);	\
  } while (0)

#define assert_m128i_epi16(a, cmp, b)					\
  do {									\
    munit_assert_int16(((int16_t*) (&a))[ 0], cmp, ((int16_t*) (&b))[ 0]);	\
    munit_assert_int16(((int16_t*) (&a))[ 1], cmp, ((int16_t*) (&b))[ 1]);	\
    munit_assert_int16(((int16_t*) (&a))[ 2], cmp, ((int16_t*) (&b))[ 2]);	\
    munit_assert_int16(((int16_t*) (&a))[ 3], cmp, ((int16_t*) (&b))[ 3]);	\
    munit_assert_int16(((int16_t*) (&a))[ 4], cmp, ((int16_t*) (&b))[ 4]);	\
    munit_assert_int16(((int16_t*) (&a))[ 5], cmp, ((int16_t*) (&b))[ 5]);	\
    munit_assert_int16(((int16_t*) (&a))[ 6], cmp, ((int16_t*) (&b))[ 6]);	\
    munit_assert_int16(((int16_t*) (&a))[ 7], cmp, ((int16_t*) (&b))[ 7]);	\
  } while (0)

#define assert_m128i_epi32(a, cmp, b)					\
  do {									\
    munit_assert_int32(((int32_t*) (&a))[ 0], cmp, ((int32_t*) (&b))[ 0]);	\
    munit_assert_int32(((int32_t*) (&a))[ 1], cmp, ((int32_t*) (&b))[ 1]);	\
    munit_assert_int32(((int32_t*) (&a))[ 2], cmp, ((int32_t*) (&b))[ 2]);	\
    munit_assert_int32(((int32_t*) (&a))[ 3], cmp, ((int32_t*) (&b))[ 3]);	\
  } while (0)

#define assert_m128i_epi64(a, cmp, b)					\
  do {									\
    munit_assert_int64(((int64_t*) (&a))[ 0], cmp, ((int64_t*) (&b))[ 0]);	\
    munit_assert_int64(((int64_t*) (&a))[ 1], cmp, ((int64_t*) (&b))[ 1]);	\
  } while (0)

#define assert_m128d_epi8(a, cmp, b)  assert_m128i_epi8(a, cmp, b)
#define assert_m128d_epi16(a, cmp, b) assert_m128i_epi16(a, cmp, b)
#define assert_m128d_epi32(a, cmp, b) assert_m128i_epi32(a, cmp, b)
#define assert_m128d_epi64(a, cmp, b) assert_m128i_epi64(a, cmp, b)

#endif /* !defined(SIMDE_TEST_H) */
