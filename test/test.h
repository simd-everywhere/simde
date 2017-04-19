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

#if !defined(TEST_NATIVE)
#  define SIMDE__MMX_NO_NATIVE
#  define SIMDE__SSE_NO_NATIVE
#  define SIMDE__SSE2_NO_NATIVE
#endif

#include <stdio.h>
#include <limits.h>

#include "../hedley.h"
#include "munit/munit.h"

const MunitSuite simde_mmx_test_suite;
const MunitSuite simde_sse_test_suite;
const MunitSuite simde_sse2_test_suite;

void debug_array_u32(const char* prefix, size_t nmemb, uint32_t v[HEDLEY_ARRAY_PARAM(nmemb)]);
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
  simde_assert_array_full("0x", "", munit_int64_t, "016x" PRIx64, nmemb, a, op, b)
#define simde_assert_uint64vx(nmemb, a, op, b)				\
  simde_assert_array_full("0x", "", munit_uint64_t, "016x" PRIx64, nmemb, a, op, b)

/* SIMDe-specific */

#define simde_assert_m64_i8(a, op, b) \
  simde_assert_int8vx(8, a.i8, op, b.i8)
#define simde_assert_m64_u8(a, op, b) \
  simde_assert_uint8vx(8, a.u8, op, b.u8)
#define simde_assert_m64_i16(a, op, b) \
  simde_assert_int16vx(4, a.i16, op, b.i16)
#define simde_assert_m64_u16(a, op, b) \
  simde_assert_uint16vx(4, a.u16, op, b.u16)
#define simde_assert_m64_i32(a, op, b) \
  simde_assert_int32vx(2, a.i32, op, b.i32)
#define simde_assert_m64_u32(a, op, b) \
  simde_assert_uint32vx(2, a.u32, op, b.u32)
#define simde_assert_m64_i64(a, op, b) \
  munit_assert_int64(a.i64, op, b.i64)
#define simde_assert_m64_u64(a, op, b) \
  munit_assert_uint64(a.u64, op, b.u64)

#define simde_assert_m128_i8(a, op, b) \
  simde_assert_int8vx(16, a.i8, op, b.i8)
#define simde_assert_m128_u8(a, op, b) \
  simde_assert_uint8vx(16, a.u8, op, b.u8)
#define simde_assert_m128_i16(a, op, b) \
  simde_assert_int16vx(8, a.i16, op, b.i16)
#define simde_assert_m128_u16(a, op, b) \
  simde_assert_uint16vx(8, a.u16, op, b.u16)
#define simde_assert_m128_i32(a, op, b) \
  simde_assert_int32vx(4, a.i32, op, b.i32)
#define simde_assert_m128_u32(a, op, b) \
  simde_assert_uint32vx(4, a.u32, op, b.u32)
#define simde_assert_m128_i64(a, op, b) \
  simde_assert_int64vx(2, a.i64, op, b.i64)
#define simde_assert_m128_u64(a, op, b) \
  simde_assert_uint64vx(2, a.u64, op, b.u64)

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

#endif /* !defined(SIMDE_TEST_H) */
