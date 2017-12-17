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

#if !defined(SIMDE__SSE4_1_H)
#  if !defined(SIMDE__SSE4_1_H)
#    define SIMDE__SSE4_1_H
#  endif
#  include "ssse3.h"

#  if defined(SIMDE_SSE4_1_NATIVE)
#    undef SIMDE_SSE4_1_NATIVE
#  endif
#  if defined(SIMDE_SSE4_1_FORCE_NATIVE)
#    define SIMDE_SSE4_1_NATIVE
#  elif defined(__SSE4_1__) && !defined(SIMDE_SSE4_1_NO_NATIVE) && !defined(SIMDE_NO_NATIVE)
#    define SIMDE_SSE4_1_NATIVE
#  elif defined(__ARM_NEON) && !defined(SIMDE_SSE4_1_NO_NEON) && !defined(SIMDE_NO_NEON)
#    define SIMDE_SSE4_1_NEON
#  endif

#  if defined(SIMDE_SSE4_1_NATIVE) && !defined(SIMDE_SSE3_NATIVE)
#    if defined(SIMDE_SSE4_1_FORCE_NATIVE)
#      error Native SSE4.1 support requires native SSE3 support
#    else
#      warning Native SSE4.1 support requires native SSE3 support, disabling
#      undef SIMDE_SSE4_1_NATIVE
#    endif
#  elif defined(SIMDE_SSE4_1_NEON) && !defined(SIMDE_SSE3_NEON)
#    warning SSE4.1 NEON support requires SSE3 NEON support, disabling
#    undef SIMDE_SSE4_1_NEON
#  endif

#  if defined(SIMDE_SSE4_1_NATIVE)
#    include <smmintrin.h>
#  else
#    if defined(SIMDE_SSE4_1_NEON)
#      include <arm_neon.h>
#    endif
#  endif

SIMDE__BEGIN_DECLS

SIMDE__FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_blendv_epi8 (simde__m128i a, simde__m128i b, simde__m128i mask) {
#if defined(SIMDE_SSE4_1_NATIVE)
  return SIMDE__M128I_C(_mm_blendv_epi8(a.n, b.n, mask.n));
#else
  simde__m128i r;
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.u8) / sizeof(r.u8[0])) ; i++) {
    if (mask.u8[i] & 0x80) {
      r.u8[i] = b.u8[i];
    } else {
      r.u8[i] = a.u8[i];
    }
  }
  return r;
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m128d
simde_mm_ceil_pd (simde__m128d a) {
#if defined(SIMDE_SSE4_1_NATIVE)
  return SIMDE__M128D_C(_mm_ceil_pd(a.n));
#else
  simde__m128d r;
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.f64) / sizeof(r.f64[0])) ; i++) {
    r.f64[i] = ceil(a.f64[i]);
  }
  return r;
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m128
simde_mm_ceil_ps (simde__m128 a) {
#if defined(SIMDE_SSE4_1_NATIVE)
  return SIMDE__M128_C(_mm_ceil_ps(a.n));
#else
  simde__m128 r;
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.f32) / sizeof(r.f32[0])) ; i++) {
    r.f32[i] = ceilf(a.f32[i]);
  }
  return r;
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m128d
simde_mm_ceil_sd (simde__m128d a, simde__m128d b) {
#if defined(SIMDE_SSE4_1_NATIVE)
  return SIMDE__M128D_C(_mm_ceil_sd(a.n, b.n));
#else
  return simde_mm_set_pd(a.f64[1], ceil(b.f64[0]));
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m128
simde_mm_ceil_ss (simde__m128 a, simde__m128 b) {
#if defined(SIMDE_SSE4_1_NATIVE)
  return SIMDE__M128_C(_mm_ceil_ss(a.n, b.n));
#else
  return simde_mm_set_ps(a.f32[3], a.f32[2], a.f32[1], ceil(b.f32[0]));
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_cmpeq_epi64 (simde__m128i a, simde__m128i b) {
#if defined(SIMDE_SSE4_1_NATIVE)
  return SIMDE__M128I_C(_mm_cmpeq_epi64(a.n, b.n));
#else
  simde__m128i r;
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.u64) / sizeof(r.u64[0])) ; i++) {
    r.u64[i] = (a.u64[i] == b.u64[i]) ? ~UINT64_C(0) : UINT64_C(0);
  }
  return r;
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_cvtepi16_epi32 (simde__m128i a) {
#if defined(SIMDE_SSE4_1_NATIVE)
  return SIMDE__M128I_C(_mm_cvtepi16_epi32(a.n));
#elif defined(SIMDE_SSE4_1_NEON)
  return SIMDE__M128I_NEON_C(i32, vmovl_s16(vget_low_s16(a.neon_i16)));
#else
  simde__m128i r;
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.i32) / sizeof(r.i32[0])) ; i++) {
    r.i32[i] = a.i16[i];
  }
  return r;
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_cvtepu8_epi32 (simde__m128i a) {
#if defined(SIMDE_SSE4_1_NATIVE)
  return SIMDE__M128I_C(_mm_cvtepu8_epi32(a.n));
#elif defined(SIMDE_SSE4_1_NEON)
  uint8x16_t u8x16 = a.neon_u8;                      /* xxxx xxxx xxxx DCBA */
  uint16x8_t u16x8 = vmovl_u8(vget_low_u8(u8x16));   /* 0x0x 0x0x 0D0C 0B0A */
  uint32x4_t u32x4 = vmovl_u16(vget_low_u16(u16x8)); /* 000D 000C 000B 000A */
  return SIMDE__M128I_NEON_C(u32, u32x4);
#else
  simde__m128i r;
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.i32) / sizeof(r.i32[0])) ; i++) {
    r.i32[i] = a.u8[i];
  }
  return r;
#endif
}

#if defined(simde_mm_extract_epi64)
#  undef simde_mm_extract_epi64
#endif
SIMDE__FUNCTION_ATTRIBUTES
int64_t
simde_mm_extract_epi64 (simde__m128i a, const int imm8) {
  return a.u64[imm8];
}
#if defined(SIMDE_SSE4_1_NATIVE) && defined(SIMDE_ARCH_AMD64)
#  define simde_mm_extract_epi64(a, imm8) _mm_extract_epi64(a.n, imm8)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_max_epi8 (simde__m128i a, simde__m128i b) {
#if defined(SIMDE_SSE4_1_NATIVE) && !defined(__PGI)
  return SIMDE__M128I_C(_mm_max_epi8(a.n, b.n));
#else
  simde__m128i r;
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.i8) / sizeof(r.i8[0])) ; i++) {
    r.i8[i] = a.i8[i] > b.i8[i] ? a.i8[i] : b.i8[i];
  }
  return r;
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_max_epi32 (simde__m128i a, simde__m128i b) {
#if defined(SIMDE_SSE4_1_NATIVE) && !defined(__PGI)
  return SIMDE__M128I_C(_mm_max_epi32(a.n, b.n));
#elif defined(SIMDE_SSE4_1_NEON)
  return SIMDE__M128I_NEON_C(i32, vmaxq_s32(a.neon_i32, b.neon_i32));
#else
  simde__m128i r;
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.i32) / sizeof(r.i32[0])) ; i++) {
    r.i32[i] = a.i32[i] > b.i32[i] ? a.i32[i] : b.i32[i];
  }
  return r;
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_min_epi8 (simde__m128i a, simde__m128i b) {
#if defined(SIMDE_SSE4_1_NATIVE) && !defined(__PGI)
  return SIMDE__M128I_C(_mm_min_epi8(a.n, b.n));
#else
  simde__m128i r;
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.i8) / sizeof(r.i8[0])) ; i++) {
    r.i8[i] = a.i8[i] < b.i8[i] ? a.i8[i] : b.i8[i];
  }
  return r;
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_min_epi32 (simde__m128i a, simde__m128i b) {
#if defined(SIMDE_SSE4_1_NATIVE) && !defined(__PGI)
  return SIMDE__M128I_C(_mm_min_epi32(a.n, b.n));
#elif defined(SIMDE_SSE4_1_NEON)
  return SIMDE__M128I_NEON_C(i32, vminq_s32(a.neon_i32, b.neon_i32));
#else
  simde__m128i r;
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.i32) / sizeof(r.i32[0])) ; i++) {
    r.i32[i] = a.i32[i] < b.i32[i] ? a.i32[i] : b.i32[i];
  }
  return r;
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_mullo_epi32 (simde__m128i a, simde__m128i b) {
#if defined(SIMDE_SSE4_1_NATIVE)
  return SIMDE__M128I_C(_mm_mullo_epi32(a.n, b.n));
#elif defined(SIMDE_SSE4_1_NEON)
  return SIMDE__M128I_NEON_C(i32, vmulq_s32(a.neon_i32, b.neon_i32));
#else
  simde__m128i r;
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.i32) / sizeof(r.i32[0])) ; i++) {
    r.u32[i] = (uint32_t) (((uint64_t) (((int64_t) a.i32[i]) * ((int64_t) b.i32[i]))) & 0xffffffff);
  }
  return r;
#endif
}

SIMDE__END_DECLS

#endif /* !defined(SIMDE__SSE4_1_H) */
