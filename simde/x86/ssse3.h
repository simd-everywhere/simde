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

#if !defined(SIMDE__SSSE3_H)
#  if !defined(SIMDE__SSSE3_H)
#    define SIMDE__SSSE3_H
#  endif
#  include "sse3.h"

#  if defined(SIMDE_SSSE3_NATIVE)
#    undef SIMDE_SSSE3_NATIVE
#  endif
#  if defined(SIMDE_SSSE3_FORCE_NATIVE)
#    define SIMDE_SSSE3_NATIVE
#  elif defined(__SSSE3__) && !defined(SIMDE_SSSE3_NO_NATIVE) && !defined(SIMDE_NO_NATIVE)
#    define SIMDE_SSSE3_NATIVE
#  elif defined(__ARM_NEON) && !defined(SIMDE_SSSE3_NO_NEON) && !defined(SIMDE_NO_NEON)
#    define SIMDE_SSSE3_NEON
#  endif

#  if defined(SIMDE_SSSE3_NATIVE) && !defined(SIMDE_SSE3_NATIVE)
#    if defined(SIMDE_SSSE3_FORCE_NATIVE)
#      error Native SSSE3 support requires native SSE3 support
#    else
#      warning Native SSSE3 support requires native SSE3 support, disabling
#      undef SIMDE_SSSE3_NATIVE
#    endif
#  elif defined(SIMDE_SSSE3_NEON) && !defined(SIMDE_SSE3_NEON)
#    warning SSSE3 NEON support requires SSE3 NEON support, disabling
#    undef SIMDE_SSSE3_NEON
#  endif

#  if defined(SIMDE_SSSE3_NATIVE)
#    include <tmmintrin.h>
#  else
#    if defined(SIMDE_SSSE3_NEON)
#      include <arm_neon.h>
#    endif
#  endif

SIMDE__BEGIN_DECLS

#if defined(simde_mm_abs_epi8)
#  undef simde_mm_abs_epi8
#endif
SIMDE__FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_abs_epi8 (simde__m128i a) {
#if defined(SIMDE_SSSE3_NATIVE)
  return SIMDE__M128I_C(_mm_abs_epi8(a.n));
#else
  simde__m128i r;
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.i8) / sizeof(r.i8[0])) ; i++) {
    r.u8[i] = (a.i8[i] < 0) ? (- a.i8[i]) : a.i8[i];
  }
  return r;
#endif
}
#if defined(SIMDE_SSSE3_NATIVE)
#  define simde_mm_abs_epi8(a) SIMDE__M128I_C(_mm_abs_epi8(a.n))
#endif

#if defined(simde_mm_abs_epi16)
#  undef simde_mm_abs_epi16
#endif
SIMDE__FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_abs_epi16 (simde__m128i a) {
#if defined(SIMDE_SSSE3_NATIVE)
  return SIMDE__M128I_C(_mm_abs_epi16(a.n));
#else
  simde__m128i r;
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.i16) / sizeof(r.i16[0])) ; i++) {
    r.u16[i] = (a.i16[i] < 0) ? (- a.i16[i]) : a.i16[i];
  }
  return r;
#endif
}
#if defined(SIMDE_SSSE3_NATIVE)
#  define simde_mm_abs_epi16(a) SIMDE__M128I_C(_mm_abs_epi16(a.n))
#endif

#if defined(simde_mm_abs_epi32)
#  undef simde_mm_abs_epi32
#endif
SIMDE__FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_abs_epi32 (simde__m128i a) {
#if defined(SIMDE_SSSE3_NATIVE)
  return SIMDE__M128I_C(_mm_abs_epi32(a.n));
#else
  simde__m128i r;
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.i32) / sizeof(r.i32[0])) ; i++) {
    r.u32[i] = (a.i32[i] < 0) ? (- a.i32[i]) : a.i32[i];
  }
  return r;
#endif
}
#if defined(SIMDE_SSSE3_NATIVE)
#  define simde_mm_abs_epi32(a) SIMDE__M128I_C(_mm_abs_epi32(a.n))
#endif

#if defined(simde_mm_abs_pi8)
#  undef simde_mm_abs_pi8
#endif
SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_mm_abs_pi8 (simde__m64 a) {
#if defined(SIMDE_SSSE3_NATIVE)
  return SIMDE__M64_C(_mm_abs_pi8(a.n));
#else
  simde__m64 r;
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.i8) / sizeof(r.i8[0])) ; i++) {
    r.u8[i] = (a.i8[i] < 0) ? (- a.i8[i]) : a.i8[i];
  }
  return r;
#endif
}
#if defined(SIMDE_SSSE3_NATIVE)
#  define simde_mm_abs_pi8(a) SIMDE__M64_C(_mm_abs_pi8(a.n))
#endif

#if defined(simde_mm_abs_pi16)
#  undef simde_mm_abs_pi16
#endif
SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_mm_abs_pi16 (simde__m64 a) {
#if defined(SIMDE_SSSE3_NATIVE)
  return SIMDE__M64_C(_mm_abs_pi16(a.n));
#else
  simde__m64 r;
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.i16) / sizeof(r.i16[0])) ; i++) {
    r.u16[i] = (a.i16[i] < 0) ? (- a.i16[i]) : a.i16[i];
  }
  return r;
#endif
}
#if defined(SIMDE_SSSE3_NATIVE)
#  define simde_mm_abs_pi16(a) SIMDE__M64_C(_mm_abs_pi16(a.n))
#endif

#if defined(simde_mm_abs_pi32)
#  undef simde_mm_abs_pi32
#endif
SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_mm_abs_pi32 (simde__m64 a) {
#if defined(SIMDE_SSSE3_NATIVE)
  return SIMDE__M64_C(_mm_abs_pi32(a.n));
#else
  simde__m64 r;
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.i32) / sizeof(r.i32[0])) ; i++) {
    r.u32[i] = (a.i32[i] < 0) ? (- a.i32[i]) : a.i32[i];
  }
  return r;
#endif
}
#if defined(SIMDE_SSSE3_NATIVE)
#  define simde_mm_abs_pi32(a) SIMDE__M64_C(_mm_abs_pi32(a.n))
#endif

#if defined(simde_mm_alignr_epi8)
#  undef simde_mm_alignr_epi8
#endif
SIMDE__FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_alignr_epi8 (simde__m128i a, simde__m128i b, int count) {
  simde__m128i r;
  const int bits = (8 * count) % 64;
  const int eo = count / 8;

  switch (eo) {
    case 0:
      r.u64[0]  = b.u64[0] >> bits;
      r.u64[0] |= b.u64[1] << (64 - bits);
      r.u64[1]  = b.u64[1] >> bits;
      r.u64[1] |= a.u64[0] << (64 - bits);
      break;
    case 1:
      r.u64[0]  = b.u64[1] >> bits;
      r.u64[0] |= a.u64[0] << (64 - bits);
      r.u64[1]  = a.u64[0] >> bits;
      r.u64[1] |= a.u64[1] << (64 - bits);
      break;
    case 2:
      r.u64[0]  = a.u64[0] >> bits;
      r.u64[0] |= a.u64[1] << (64 - bits);
      r.u64[1]  = a.u64[1] >> bits;
      break;
    case 3:
      r.u64[0]  = a.u64[1] >> bits;
      r.u64[1]  = 0;
      break;
    default:
      HEDLEY_UNREACHABLE();
      break;
  }

  return r;
}
#if defined(SIMDE_SSSE3_NATIVE)
#  define simde_mm_alignr_epi8(a, b, count) SIMDE__M128I_C(_mm_alignr_epi8(a.n, b.n, count))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_shuffle_epi8 (simde__m128i a, simde__m128i b) {
#if defined(SIMDE_SSSE3_NATIVE)
  return SIMDE__M128I_C(_mm_shuffle_epi8(a.n, b.n));
#else
  simde__m128i r;
  for (size_t i = 0 ; i < (sizeof(r.u8) / sizeof(r.u8[0])) ; i++) {
    r.u8[i] = a.u8[b.u8[i] & 15] * ((~(b.u8[i]) >> 7) & 1);
  }
  return r;
#endif
}

SIMDE__END_DECLS

#endif /* !defined(SIMDE__SSE2_H) */
