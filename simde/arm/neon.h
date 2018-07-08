/* Copyright (c) 2017-2018 Evan Nemerson <evan@nemerson.com>
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

#if !defined(SIMDE__NEON_H)
#  define SIMDE__INSIDE_NEON_H
#  if !defined(SIMDE__NEON_H)
#    define SIMDE__NEON_H
#  endif
#  include "../simde-common.h"

#  if defined(SIMDE_NEON_FORCE_NATIVE)
#    define SIMDE_NEON_NATIVE
#  elif defined(__ARM_NEON) && !defined(SIMDE_NEON_NO_NATIVE) && !defined(SIMDE_NO_NATIVE)
#    define SIMDE_NEON_NATIVE
#  endif

#  if defined(SIMDE_NEON64_FORCE_NATIVE)
#    define SIMDE_NEON64_NATIVE
#  elif defined(SIMDE_ARCH_AARCH64) && !defined(SIMDE_NEON64_NO_NATIVE) && !defined(SIMDE_NO_NATIVE)
#    define SIMDE_NEON64_NATIVE
#  endif

#  if defined(__MMX__) && !defined(SIMDE_NEON_NO_MMX) && !defined(SIMDE_NO_MMX)
#    define SIMDE_NEON_MMX
#    include <mmintrin.h>
#  endif
#  if defined(__SSE__) && !defined(SIMDE_NEON_NO_SSE) && !defined(SIMDE_NO_SSE)
#    define SIMDE_NEON_SSE
#    include <xmmintrin.h>
#  endif
#  if defined(__SSE2__) && !defined(SIMDE_NEON_NO_SSE2) && !defined(SIMDE_NO_SSE2)
#    define SIMDE_NEON_SSE2
#    include <emmintrin.h>
#  endif

#  if defined(SIMDE_NEON_NATIVE)
#    include <arm_neon.h>
#  endif
#  include <stdint.h>

SIMDE__BEGIN_DECLS

#include "neon/int8x8.h"
#include "neon/int16x4.h"
#include "neon/int32x2.h"
#include "neon/int64x1.h"
#include "neon/uint8x8.h"
#include "neon/uint16x4.h"
#include "neon/uint32x2.h"
#include "neon/uint64x1.h"
#include "neon/float32x2.h"
#include "neon/float64x1.h"

#include "neon/int8x16.h"
#include "neon/int16x8.h"
#include "neon/int32x4.h"
#include "neon/int64x2.h"
#include "neon/uint8x16.h"
#include "neon/uint16x8.h"
#include "neon/uint32x4.h"
#include "neon/uint64x2.h"
#include "neon/float32x4.h"
#include "neon/float64x2.h"


SIMDE__FUNCTION_ATTRIBUTES
simde_int8x8_t
simde_vadd_s8(simde_int8x8_t a, simde_int8x8_t b) {
  simde_int8x8_t r;
#if defined(SIMDE_NEON_NATIVE)
  r.n = vadd_s8(a.n, b.n);
#elif defined(SIMDE_MMX_NATIVE)
  r.mmx = _mm_add_pi8(a.mmx, b.mmx);
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.i8) / sizeof(r.i8[0])) ; i++) {
    r.i8[i] = a.i8[i] + b.i8[i];
  }
#endif
  return r;
}

SIMDE__FUNCTION_ATTRIBUTES
simde_int8x16_t
simde_vaddq_s8(simde_int8x16_t a, simde_int8x16_t b) {
  simde_int8x16_t r;
#if defined(SIMDE_NEON_NATIVE)
  r.n = vaddq_s8(a.n, b.n);
#elif defined(SIMDE_SSE2_NATIVE)
  r.sse = _mm_add_epi8(a.sse, b.sse);
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.i8) / sizeof(r.i8[0])) ; i++) {
    r.i8[i] = a.i8[i] + b.i8[i];
  }
#endif
  return r;
}

SIMDE__FUNCTION_ATTRIBUTES
simde_int16x4_t
simde_vadd_s16(simde_int16x4_t a, simde_int16x4_t b) {
  simde_int16x4_t r;
#if defined(SIMDE_NEON_NATIVE)
  r.n = vadd_s16(a.n, b.n);
#elif defined(SIMDE_MMX_NATIVE)
  r.mmx = _mm_add_pi16(a.mmx, b.mmx);
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.i16) / sizeof(r.i16[0])) ; i++) {
    r.i16[i] = a.i16[i] + b.i16[i];
  }
#endif
  return r;
}

SIMDE__FUNCTION_ATTRIBUTES
simde_int16x8_t
simde_vaddq_s16(simde_int16x8_t a, simde_int16x8_t b) {
  simde_int16x8_t r;
#if defined(SIMDE_NEON_NATIVE)
  r.n = vaddq_s16(a.n, b.n);
#elif defined(SIMDE_SSE2_NATIVE)
  r.sse = _mm_add_epi16(a.sse, b.sse);
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.i16) / sizeof(r.i16[0])) ; i++) {
    r.i16[i] = a.i16[i] + b.i16[i];
  }
#endif
  return r;
}

SIMDE__FUNCTION_ATTRIBUTES
simde_int32x2_t
simde_vadd_s32(simde_int32x2_t a, simde_int32x2_t b) {
  simde_int32x2_t r;
#if defined(SIMDE_NEON_NATIVE)
  r.n = vadd_s32(a.n, b.n);
#elif defined(SIMDE_MMX_NATIVE)
  r.mmx = _mm_add_pi32(a.mmx, b.mmx);
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.i32) / sizeof(r.i32[0])) ; i++) {
    r.i32[i] = a.i32[i] + b.i32[i];
  }
#endif
  return r;
}

SIMDE__FUNCTION_ATTRIBUTES
simde_int32x4_t
simde_vaddq_s32(simde_int32x4_t a, simde_int32x4_t b) {
  simde_int32x4_t r;
#if defined(SIMDE_NEON_NATIVE)
  r.n = vaddq_s32(a.n, b.n);
#elif defined(SIMDE_SSE2_NATIVE)
  r.sse = _mm_add_epi32(a.sse, b.sse);
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.i32) / sizeof(r.i32[0])) ; i++) {
    r.i32[i] = a.i32[i] + b.i32[i];
  }
#endif
  return r;
}

SIMDE__FUNCTION_ATTRIBUTES
simde_int64x1_t
simde_vadd_s64(simde_int64x1_t a, simde_int64x1_t b) {
  simde_int64x1_t r;
#if defined(SIMDE_NEON_NATIVE)
  r.n = vadd_s64(a.n, b.n);
#elif defined(SIMDE_MMX_NATIVE)
  r.mmx = _mm_add_pi64(a.mmx, b.mmx);
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.i64) / sizeof(r.i64[0])) ; i++) {
    r.i64[i] = a.i64[i] + b.i64[i];
  }
#endif
  return r;
}

SIMDE__FUNCTION_ATTRIBUTES
simde_int64x2_t
simde_vaddq_s64(simde_int64x2_t a, simde_int64x2_t b) {
  simde_int64x2_t r;
#if defined(SIMDE_NEON_NATIVE)
  r.n = vaddq_s64(a.n, b.n);
#elif defined(SIMDE_SSE2_NATIVE)
  r.sse = _mm_add_epi64(a.sse, b.sse);
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.i64) / sizeof(r.i64[0])) ; i++) {
    r.i64[i] = a.i64[i] + b.i64[i];
  }
#endif
  return r;
}

SIMDE__FUNCTION_ATTRIBUTES
int8_t
simde_vget_lane_s8(simde_int8x8_t v, const int lane) {
  return v.i8[lane];
}
#if defined(SIMDE_NEON_NATIVE)
#  define simde_vget_lane_s8(v, lane) vget_lane_s8(v.n, lane);
#endif

SIMDE__END_DECLS

#undef SIMDE__INSIDE_NEON_H
#endif /* !defined(SIMDE__NEON_H) */
