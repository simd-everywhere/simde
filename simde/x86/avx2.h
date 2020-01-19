/* Permission is hereby granted, free of charge, to any person
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
 *
 * Copyright:
 *   2018      Evan Nemerson <evan@nemerson.com>
 *   2019      Michael R. Crusoe <michael.crusoe@gmail.com>
 */

#include "sse4.1.h"
#if !defined(SIMDE__AVX2_H)
#  if !defined(SIMDE__AVX2_H)
#    define SIMDE__AVX2_H
#  endif
#  include "avx.h"

#  if defined(SIMDE_AVX2_NATIVE)
#    undef SIMDE_AVX2_NATIVE
#  endif
#  if defined(SIMDE_AVX2_FORCE_NATIVE)
#    define SIMDE_AVX2_NATIVE
#  elif defined(__AVX2__) && !defined(SIMDE_AVX2_NO_NATIVE) && !defined(SIMDE_NO_NATIVE)
#    define SIMDE_AVX2_NATIVE
#  elif defined(__ARM_NEON) && !defined(SIMDE_AVX2_NO_NEON) && !defined(SIMDE_NO_NEON)
#    define SIMDE_AVX2_NEON
#  endif

#  if defined(SIMDE_AVX2_NATIVE) && !defined(SIMDE_AVX_NATIVE)
#    if defined(SIMDE_AVX2_FORCE_NATIVE)
#      error Native AVX2 support requires native AVX support
#    else
#      warning Native AVX2 support requires native AVX support, disabling
#      undef SIMDE_AVX2_NATIVE
#    endif
#  elif defined(SIMDE_AVX2_NEON) && !defined(SIMDE_AVX_NEON)
#    warning AVX2 NEON support requires AVX NEON support, disabling
#    undef SIMDE_AVX_NEON
#  endif

#  if defined(SIMDE_AVX2_NATIVE)
#    include <immintrin.h>
#  endif

#  if !defined(SIMDE_AVX2_NATIVE) && defined(SIMDE_ENABLE_NATIVE_ALIASES)
#    define SIMDE_AVX2_ENABLE_NATIVE_ALIASES
#  endif

#  include <stdint.h>

SIMDE__BEGIN_DECLS

SIMDE__FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_add_epi8 (simde__m256i a, simde__m256i b) {
  simde__m256i r;

#if defined(SIMDE_AVX2_NATIVE)
  r.n = _mm256_add_epi8(a.n, b.n);
#elif defined(SIMDE_SSE2_NATIVE)
  r.m128i[0].n = _mm_add_epi8(a.m128i[0].n, b.m128i[0].n);
  r.m128i[1].n = _mm_add_epi8(a.m128i[1].n, b.m128i[1].n);
#elif defined(SIMDE_VECTOR_SUBSCRIPT_BINARY)
  r.i8 = a.i8 + b.i8;
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.i8) / sizeof(r.i8[0])) ; i++) {
    r.i8[i] = a.i8[i] + b.i8[i];
  }
#endif

  return r;
}
#if defined(SIMDE_AVX2_ENABLE_NATIVE_ALIASES)
#  define _mm256_add_epi8(a, b) SIMDE__M256I_TO_NATIVE(simde_mm256_add_epi8(SIMDE__M256I_FROM_NATIVE(a), SIMDE__M256I_FROM_NATIVE(b)))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_add_epi16 (simde__m256i a, simde__m256i b) {
  simde__m256i r;

#if defined(SIMDE_AVX2_NATIVE)
  r.n = _mm256_add_epi16(a.n, b.n);
#elif defined(SIMDE_SSE2_NATIVE)
  r.m128i[0].n = _mm_add_epi16(a.m128i[0].n, b.m128i[0].n);
  r.m128i[1].n = _mm_add_epi16(a.m128i[1].n, b.m128i[1].n);
#elif defined(SIMDE_VECTOR_SUBSCRIPT_BINARY)
  r.i16 = a.i16 + b.i16;
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.i16) / sizeof(r.i16[0])) ; i++) {
    r.i16[i] = a.i16[i] + b.i16[i];
  }
#endif

  return r;
}
#if defined(SIMDE_AVX2_ENABLE_NATIVE_ALIASES)
#  define _mm256_add_epi16(a, b) SIMDE__M256I_TO_NATIVE(simde_mm256_add_epi16(SIMDE__M256I_FROM_NATIVE(a), SIMDE__M256I_FROM_NATIVE(b)))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_add_epi32 (simde__m256i a, simde__m256i b) {
  simde__m256i r;

#if defined(SIMDE_AVX2_NATIVE)
  r.n = _mm256_add_epi32(a.n, b.n);
#elif defined(SIMDE_SSE2_NATIVE)
  r.m128i[0].n = _mm_add_epi32(a.m128i[0].n, b.m128i[0].n);
  r.m128i[1].n = _mm_add_epi32(a.m128i[1].n, b.m128i[1].n);
#elif defined(SIMDE_VECTOR_SUBSCRIPT_BINARY)
  r.i32 = a.i32 + b.i32;
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.i32) / sizeof(r.i32[0])) ; i++) {
    r.i32[i] = a.i32[i] + b.i32[i];
  }
#endif

  return r;
}
#if defined(SIMDE_AVX2_ENABLE_NATIVE_ALIASES)
#  define _mm256_add_epi32(a, b) SIMDE__M256I_TO_NATIVE(simde_mm256_add_epi32(SIMDE__M256I_FROM_NATIVE(a), SIMDE__M256I_FROM_NATIVE(b)))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_add_epi64 (simde__m256i a, simde__m256i b) {
  simde__m256i r;

#if defined(SIMDE_AVX2_NATIVE)
  r.n = _mm256_add_epi64(a.n, b.n);
#elif defined(SIMDE_SSE2_NATIVE)
  r.m128i[0].n = _mm_add_epi64(a.m128i[0].n, b.m128i[0].n);
  r.m128i[1].n = _mm_add_epi64(a.m128i[1].n, b.m128i[1].n);
#elif defined(SIMDE_VECTOR_SUBSCRIPT_BINARY)
  r.i64 = a.i64 + b.i64;
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.i64) / sizeof(r.i64[0])) ; i++) {
    r.i64[i] = a.i64[i] + b.i64[i];
  }
#endif

  return r;
}
#if defined(SIMDE_AVX2_ENABLE_NATIVE_ALIASES)
#  define _mm256_add_epi64(a, b) SIMDE__M256I_TO_NATIVE(simde_mm256_add_epi64(SIMDE__M256I_FROM_NATIVE(a), SIMDE__M256I_FROM_NATIVE(b)))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_alignr_epi8 (simde__m256i a, simde__m256i b, int count) {
  simde__m256i r;
  const int bits = (8 * count) % 64;
  const int eo = count / 8;

  switch (eo) {
    case 0:
      r.u64[0]  = b.u64[0] >> bits;
      r.u64[0] |= b.u64[1] << (64 - bits);
      r.u64[1]  = b.u64[1] >> bits;
      r.u64[1] |= a.u64[0] << (64 - bits);
      r.u64[2]  = b.u64[2] >> bits;
      r.u64[2] |= b.u64[3] << (64 - bits);
      r.u64[3]  = b.u64[3] >> bits;
      r.u64[3] |= a.u64[2] << (64 - bits);
      break;
    case 1:
      r.u64[0]  = b.u64[1] >> bits;
      r.u64[0] |= a.u64[0] << (64 - bits);
      r.u64[1]  = a.u64[0] >> bits;
      r.u64[1] |= a.u64[1] << (64 - bits);
      r.u64[2]  = b.u64[3] >> bits;
      r.u64[2] |= a.u64[2] << (64 - bits);
      r.u64[3]  = a.u64[2] >> bits;
      r.u64[3] |= a.u64[3] << (64 - bits);
       break;
    case 2:
      r.u64[0]  = a.u64[0] >> bits;
      r.u64[0] |= a.u64[1] << (64 - bits);
      r.u64[1]  = a.u64[1] >> bits;
      r.u64[2]  = a.u64[2] >> bits;
      r.u64[2] |= a.u64[3] << (64 - bits);
      r.u64[3]  = a.u64[3] >> bits;
      break;
    case 3:
      r.u64[0]  = a.u64[1] >> bits;
      r.u64[1]  = 0;
      r.u64[2]  = a.u64[3] >> bits;
      r.u64[3]  = 0;
      break;
    default:
      HEDLEY_UNREACHABLE();
      break;
  }

  return r;
}
#if defined(SIMDE_AVX2_NATIVE)
#  define simde_mm256_alignr_epi8(a, b, count) SIMDE__M256I_FROM_NATIVE(_mm256_alignr_epi8(a.n, b.n, count))
#elif defined(SIMDE_SSSE3_NATIVE)
#  define simde_mm256_alignr_epi8(a, b, count) \
     simde_mm256_set_m128i( \
       SIMDE__M128I_FROM_NATIVE(_mm_alignr_epi8((a).m128i[1].n, (b).m128i[1].n, (count))), \
       SIMDE__M128I_FROM_NATIVE(_mm_alignr_epi8((a).m128i[0].n, (b).m128i[0].n, (count))))
#endif
#if defined(SIMDE_AVX2_ENABLE_NATIVE_ALIASES)
#  define _mm256_alignr_epi8(a, b, count) SIMDE__M256I_TO_NATIVE(simde_mm256_alignr_epi8(SIMDE__M256I_FROM_NATIVE(a), SIMDE__M256I_FROM_NATIVE(b), (count)))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_and_si256 (simde__m256i a, simde__m256i b) {
  simde__m256i r;

#if defined(SIMDE_AVX2_NATIVE)
  r.n = _mm256_and_si256(a.n, b.n);
#elif defined(SIMDE_SSE2_NATIVE)
  r.m128i[0].n = _mm_and_si128(a.m128i[0].n, b.m128i[0].n);
  r.m128i[1].n = _mm_and_si128(a.m128i[1].n, b.m128i[1].n);
#elif defined(SIMDE_VECTOR_SUBSCRIPT_BINARY)
  r.i32f = a.i32f & b.i32f;
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.i64) / sizeof(r.i64[0])) ; i++) {
    r.i64[i] = a.i64[i] & b.i64[i];
  }
#endif

  return r;
}
#if defined(SIMDE_AVX2_ENABLE_NATIVE_ALIASES)
#  define _mm256_and_si256(a, b) SIMDE__M256I_TO_NATIVE(simde_mm256_and_si256(SIMDE__M256I_FROM_NATIVE(a), SIMDE__M256I_FROM_NATIVE(b)))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_andnot_si256 (simde__m256i a, simde__m256i b) {
  simde__m256i r;

#if defined(SIMDE_AVX2_NATIVE)
  r.n = _mm256_andnot_si256(a.n, b.n);
#elif defined(SIMDE_SSE2_NATIVE) || defined(SIMDE_SSE2_NEON)
  r = simde_mm256_set_m128i(
        simde_mm_andnot_si128(a.m128i[1], b.m128i[1]),
	simde_mm_andnot_si128(a.m128i[0], b.m128i[0]));
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.i32f) / sizeof(r.i32f[0])) ; i++) {
    r.i32f[i] = ~(a.i32f[i]) & b.i32f[i];
  }
#endif

  return r;
}
#if defined(SIMDE_AVX2_ENABLE_NATIVE_ALIASES)
#  define _mm256_andnot_si256(a, b) SIMDE__M256I_TO_NATIVE(simde_mm256_andnot_si256(SIMDE__M256I_FROM_NATIVE(a), SIMDE__M256I_FROM_NATIVE(b)))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_adds_epu8 (simde__m256i a, simde__m256i b) {
  simde__m256i r;

#if defined(SIMDE_AVX2_NATIVE)
  r.n = _mm256_adds_epu8(a.n, b.n);
#elif defined(SIMDE_SSE2_NATIVE)
  r.m128i[0].n = _mm_adds_epu8(a.m128i[0].n, b.m128i[0].n);
  r.m128i[1].n = _mm_adds_epu8(a.m128i[1].n, b.m128i[1].n);
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.u8) / sizeof(r.u8[0])) ; i++) {
    r.u8[i] = ((UINT8_MAX - a.u8[i]) > b.u8[i]) ? (a.u8[i] + b.u8[i]) : UINT8_MAX;
  }
#endif

  return r;
}
#if defined(SIMDE_AVX2_ENABLE_NATIVE_ALIASES)
#  define _mm256_adds_epu8(a, b) SIMDE__M256I_TO_NATIVE(simde_mm256_adds_epu8(SIMDE__M256I_FROM_NATIVE(a), SIMDE__M256I_FROM_NATIVE(b)))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_blendv_epi8 (simde__m256i a, simde__m256i b, simde__m256i mask) {
  simde__m256i r;

#if defined(SIMDE_AVX2_NATIVE)
  r.n = _mm256_blendv_epi8(a.n, b.n, mask.n);
#elif defined(SIMDE_SSE4_1_NATIVE)
  r.m128i[0].n = _mm_blendv_epi8(a.m128i[0].n, b.m128i[0].n, mask.m128i[0].n);
  r.m128i[1].n = _mm_blendv_epi8(a.m128i[1].n, b.m128i[1].n, mask.m128i[1].n);
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.u8) / sizeof(r.u8[0])) ; i++) {
    if (mask.u8[i] & 0x80) {
      r.u8[i] = b.u8[i];
    } else {
      r.u8[i] = a.u8[i];
    }
  }
#endif

  return r;
}
#if defined(SIMDE_AVX2_ENABLE_NATIVE_ALIASES)
#  define _mm256_blendv_epi8(a, b, mask) SIMDE__M256I_TO_NATIVE(simde_mm256_blendv_epi8(SIMDE__M256I_FROM_NATIVE(a), SIMDE__M256I_FROM_NATIVE(b), SIMDE__M256i_FROM_NATIVE(mask)))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_broadcastsi128_si256 (simde__m128i a) {
  simde__m256i r;

#if defined(SIMDE_AVX2_NATIVE)
  return SIMDE__M256I_FROM_NATIVE(_mm256_broadcastsi128_si256(a.n));
#elif defined(SIMDE_SSE2_NATIVE)
  r.m128i[0].n = a.n;
  r.m128i[1].n = a.n;
#else
  r.i64[0] = a.i64[0];
  r.i64[1] = a.i64[1];
  r.i64[2] = a.i64[0];
  r.i64[3] = a.i64[1];
#endif

  return r;
}
#if defined(SIMDE_AVX2_ENABLE_NATIVE_ALIASES)
#  define _mm256_broadcastsi128_si256(a) SIMDE__M256I_TO_NATIVE(simde_mm256_broadcastsi128_si256(SIMDE__M128I_FROM_NATIVE(a)))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_cmpeq_epi8 (simde__m256i a, simde__m256i b) {
  simde__m256i r;

#if defined(SIMDE_AVX2_NATIVE)
  r.n = _mm256_cmpeq_epi8(a.n, b.n);
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.i8) / sizeof(r.i8[0])) ; i++) {
    r.i8[i] = (a.i8[i] == b.i8[i]) ? ~INT8_C(0) : INT8_C(0);
  }
#endif

  return r;
}
#if defined(SIMDE_AVX2_ENABLE_NATIVE_ALIASES)
#  define _mm256_cmpeq_epi8(a, b) SIMDE__M256I_TO_NATIVE(simde_mm256_cmpeq_epi8(SIMDE__M256I_FROM_NATIVE(a), SIMDE__M256I_FROM_NATIVE(b)))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_cmpeq_epi32 (simde__m256i a, simde__m256i b) {
  simde__m256i r;

#if defined(SIMDE_AVX2_NATIVE)
  r.n = _mm256_cmpeq_epi32(a.n, b.n);
#elif defined(SIMDE_SSE2_NATIVE) || defined(SIMDE_SSE2_NEON)
  r = simde_mm256_set_m128i(
        simde_mm_cmpeq_epi32(a.m128i[1], b.m128i[1]),
        simde_mm_cmpeq_epi32(a.m128i[0], b.m128i[0]));
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.i32) / sizeof(r.i32[0])) ; i++) {
    r.i32[i] = (a.i32[i] == b.i32[i]) ? ~INT32_C(0) : INT32_C(0);
  }
#endif

  return r;
}
#if defined(SIMDE_AVX2_ENABLE_NATIVE_ALIASES)
#  define _mm256_cmpeq_epi32(a, b) SIMDE__M256I_TO_NATIVE(simde_mm256_cmpeq_epi32(SIMDE__M256I_FROM_NATIVE(a), SIMDE__M256I_FROM_NATIVE(b)))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_cmpgt_epi16 (simde__m256i a, simde__m256i b) {
  simde__m256i r;

#if defined(SIMDE_AVX2_NATIVE)
  r.n = _mm256_cmpgt_epi16(a.n, b.n);
#elif defined(SIMDE_SSE2_NATIVE)
  r.m128i[0].n = _mm_cmpgt_epi16(a.m128i[0].n, b.m128i[0].n);
  r.m128i[1].n = _mm_cmpgt_epi16(a.m128i[1].n, b.m128i[1].n);
#elif defined(SIMDE_VECTOR_SUBSCRIPT_BINARY)
  r.i16 = a.i16 > b.i16;
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.i16) / sizeof(r.i16[0])) ; i++) {
    r.i16[i] = (a.i16[i] > b.i16[i]) ? ~INT16_C(0) : INT16_C(0);
  }
#endif

  return r;
}
#if defined(SIMDE_AVX2_ENABLE_NATIVE_ALIASES)
#  define _mm256_cmpgt_epi16(a, b) SIMDE__M256I_TO_NATIVE(simde_mm256_cmpgt_epi16(SIMDE__M256I_FROM_NATIVE(a), SIMDE__M256I_FROM_NATIVE(b)))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_cmpgt_epi32 (simde__m256i a, simde__m256i b) {
  simde__m256i r;

#if defined(SIMDE_AVX2_NATIVE)
  r.n = _mm256_cmpgt_epi32(a.n, b.n);
#elif defined(SIMDE_SSE2_NATIVE)
  r.m128i[0].n = _mm_cmpgt_epi32(a.m128i[0].n, b.m128i[0].n);
  r.m128i[1].n = _mm_cmpgt_epi32(a.m128i[1].n, b.m128i[1].n);
#elif defined(SIMDE_VECTOR_SUBSCRIPT_BINARY)
  r.i32 = a.i32 > b.i32;
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.i32) / sizeof(r.i32[0])) ; i++) {
    r.i32[i] = (a.i32[i] > b.i32[i]) ? ~INT32_C(0) : INT32_C(0);
  }
#endif

  return r;
}
#if defined(SIMDE_AVX2_ENABLE_NATIVE_ALIASES)
#  define _mm256_cmpgt_epi32(a, b) SIMDE__M256I_TO_NATIVE(simde_mm256_cmpgt_epi32(SIMDE__M256I_FROM_NATIVE(a), SIMDE__M256I_FROM_NATIVE(b)))
#endif


SIMDE__FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_cvtepi8_epi16 (simde__m128i a){
  simde__m256i r;
#if defined(SIMDE_AVX2_NATIVE)
  r = SIMDE__M256I_FROM_NATIVE(_mm256_cvtepi8_epi16(a.n));
#elif defined(SIMDE__CONVERT_VECTOR)
  SIMDE__CONVERT_VECTOR(r.i16, a.i8);
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.i16) / sizeof(r.i16[0])) ; i++) {
    r.i16[i] = a.i8[i];
  }
#endif
  return r;
}
#if defined(SIMDE_AVX2_ENABLE_NATIVE_ALIASES)
#  define _mm256_cvtepi8_epi16(a) SIMDE__M256I_TO_NATIVE(simde_mm256_cvtepi8_epi16(SIMDE__M128I_FROM_NATIVE(a)))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_cvtepi8_epi32 (simde__m128i a){
  simde__m256i r;
#if defined(SIMDE_AVX2_NATIVE)
  r = SIMDE__M256I_FROM_NATIVE(_mm256_cvtepi8_epi32(a.n));
#elif defined(SIMDE__CONVERT_VECTOR)
  SIMDE__CONVERT_VECTOR(r.i32, a.m64[0].i8);
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.i32) / sizeof(r.i32[0])) ; i++) {
    r.i32[i] = a.i8[i];
  }
#endif
  return r;
}
#if defined(SIMDE_AVX2_ENABLE_NATIVE_ALIASES)
#  define _mm256_cvtepi8_epi32(a) SIMDE__M256I_TO_NATIVE(simde_mm256_cvtepi8_epi16(SIMDE__M128I_FROM_NATIVE(a)))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_cvtepi8_epi64 (simde__m128i a){
  simde__m256i r;
#if defined(SIMDE_AVX2_NATIVE)
  r = SIMDE__M256I_FROM_NATIVE(_mm256_cvtepi8_epi64(a.n));
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.i64) / sizeof(r.i64[0])) ; i++) {
    r.i64[i] = a.i8[i];
  }
#endif
  return r;
}
#if defined(SIMDE_AVX2_ENABLE_NATIVE_ALIASES)
#  define _mm256_cvtepi8_epi64(a) SIMDE__M256I_TO_NATIVE(simde_mm256_cvtepi8_epi64(SIMDE__M128I_FROM_NATIVE(a)))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_cvtepi16_epi32 (simde__m128i a){
  simde__m256i r;
#if defined(SIMDE_AVX2_NATIVE)
  r = SIMDE__M256I_FROM_NATIVE(_mm256_cvtepi16_epi32(a.n));
#elif defined(SIMDE__CONVERT_VECTOR)
  SIMDE__CONVERT_VECTOR(r.i32, a.i16);
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.i32) / sizeof(r.i32[0])) ; i++) {
    r.i32[i] = a.i16[i];
  }
#endif
  return r;
}
#if defined(SIMDE_AVX2_ENABLE_NATIVE_ALIASES)
#  define _mm256_cvtepi16_epi32(a) SIMDE__M256I_TO_NATIVE(simde_mm256_cvtepi16_epi32(SIMDE__M128I_FROM_NATIVE(a)))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_cvtepi16_epi64 (simde__m128i a){
  simde__m256i r;
#if defined(SIMDE_AVX2_NATIVE)
  r = SIMDE__M256I_FROM_NATIVE(_mm256_cvtepi16_epi64(a.n));
#elif defined(SIMDE__CONVERT_VECTOR)
  SIMDE__CONVERT_VECTOR(r.i64, a.m64[0].i16);
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.i64) / sizeof(r.i64[0])) ; i++) {
    r.i64[i] = a.i16[i];
  }
#endif
  return r;
}
#if defined(SIMDE_AVX2_ENABLE_NATIVE_ALIASES)
#  define _mm256_cvtepi16_epi64(a) SIMDE__M256I_TO_NATIVE(simde_mm256_cvtepi16_epi64(SIMDE__M128I_FROM_NATIVE(a)))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_cvtepi32_epi64 (simde__m128i a){
  simde__m256i r;
#if defined(SIMDE_AVX2_NATIVE)
  r = SIMDE__M256I_FROM_NATIVE(_mm256_cvtepi32_epi64(a.n));
#elif defined(SIMDE__CONVERT_VECTOR)
  SIMDE__CONVERT_VECTOR(r.i64, a.i32);
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.i64) / sizeof(r.i64[0])) ; i++) {
    r.i64[i] = a.i32[i];
  }
#endif
  return r;
}
#if defined(SIMDE_AVX2_ENABLE_NATIVE_ALIASES)
#  define _mm256_cvtepi32_epi64(a) SIMDE__M256I_TO_NATIVE(simde_mm256_cvtepi32_epi64(SIMDE__M128I_FROM_NATIVE(a)))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_cvtepu8_epi16 (simde__m128i a){
  simde__m256i r;
#if defined(SIMDE_AVX2_NATIVE)
  r = SIMDE__M256I_FROM_NATIVE(_mm256_cvtepu8_epi16(a.n));
#elif defined(SIMDE__CONVERT_VECTOR)
  SIMDE__CONVERT_VECTOR(r.i16, a.u8);
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.i16) / sizeof(r.i16[0])) ; i++) {
    r.i16[i] = a.u8[i];
  }
#endif
  return r;
}
#if defined(SIMDE_AVX2_ENABLE_NATIVE_ALIASES)
#  define _mm256_cvtepu8_epi64(a) SIMDE__M256I_TO_NATIVE(simde_mm256_cvtepu8_epi64(SIMDE__M128I_FROM_NATIVE(a)))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_cvtepu8_epi32 (simde__m128i a){
  simde__m256i r;
#if defined(SIMDE_AVX2_NATIVE)
  r = SIMDE__M256I_FROM_NATIVE(_mm256_cvtepu8_epi32(a.n));
#elif defined(SIMDE__CONVERT_VECTOR)
  SIMDE__CONVERT_VECTOR(r.i32, a.m64[0].u8);
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.i32) / sizeof(r.i32[0])) ; i++) {
    r.i32[i] = a.u8[i];
  }
#endif
  return r;
}
#if defined(SIMDE_AVX2_ENABLE_NATIVE_ALIASES)
#  define _mm256_cvtepu8_epi32(a) SIMDE__M256I_TO_NATIVE(simde_mm256_cvtepu8_epi32(SIMDE__M128I_FROM_NATIVE(a)))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_cvtepu8_epi64 (simde__m128i a){
  simde__m256i r;
#if defined(SIMDE_AVX2_NATIVE)
  r = SIMDE__M256I_FROM_NATIVE(_mm256_cvtepu8_epi64(a.n));
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.i64) / sizeof(r.i64[0])) ; i++) {
    r.i64[i] = a.u8[i];
  }
#endif
  return r;
}
#if defined(SIMDE_AVX2_ENABLE_NATIVE_ALIASES)
#  define _mm256_cvtepu8_epi64(a) SIMDE__M256I_TO_NATIVE(simde_mm256_cvtepu8_epi64(SIMDE__M128I_FROM_NATIVE(a)))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_cvtepu16_epi32 (simde__m128i a){
  simde__m256i r;
#if defined(SIMDE_AVX2_NATIVE)
  r = SIMDE__M256I_FROM_NATIVE(_mm256_cvtepu16_epi32(a.n));
#elif defined(SIMDE__CONVERT_VECTOR)
  SIMDE__CONVERT_VECTOR(r.i32, a.u16);
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.i32) / sizeof(r.i32[0])) ; i++) {
    r.i32[i] = a.u16[i];
  }
#endif
  return r;
}
#if defined(SIMDE_AVX2_ENABLE_NATIVE_ALIASES)
#  define _mm256_cvtepu16_epi32(a) SIMDE__M256I_TO_NATIVE(simde_mm256_cvtepu16_epi32(SIMDE__M128I_FROM_NATIVE(a)))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_cvtepu16_epi64 (simde__m128i a){
  simde__m256i r;
#if defined(SIMDE_AVX2_NATIVE)
  r = SIMDE__M256I_FROM_NATIVE(_mm256_cvtepu16_epi64(a.n));
#elif defined(SIMDE__CONVERT_VECTOR)
  SIMDE__CONVERT_VECTOR(r.i64, a.m64[0].u16);
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.i64) / sizeof(r.i64[0])) ; i++) {
    r.i64[i] = a.u16[i];
  }
#endif
  return r;
}
#if defined(SIMDE_AVX2_ENABLE_NATIVE_ALIASES)
#  define _mm256_cvtepu16_epi64(a) SIMDE__M256I_TO_NATIVE(simde_mm256_cvtepu16_epi64(SIMDE__M128I_FROM_NATIVE(a)))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_cvtepu32_epi64 (simde__m128i a){
  simde__m256i r;
#if defined(SIMDE_AVX2_NATIVE)
  r = SIMDE__M256I_FROM_NATIVE(_mm256_cvtepu32_epi64(a.n));
#elif defined(SIMDE__CONVERT_VECTOR)
  SIMDE__CONVERT_VECTOR(r.i64, a.u32);
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.i64) / sizeof(r.i64[0])) ; i++) {
    r.i64[i] = a.u32[i];
  }
#endif
  return r;
}
#if defined(SIMDE_AVX2_ENABLE_NATIVE_ALIASES)
#  define _mm256_cvtepu32_epi64(a) SIMDE__M256I_TO_NATIVE(simde_mm256_cvtepu32_epi64(SIMDE__M128I_FROM_NATIVE(a)))
#endif

SIMDE__FUNCTION_ATTRIBUTES
int
simde_mm256_extract_epi8 (simde__m256i a, const int index) {
  return a.i8[index];
}
#if defined(SIMDE_AVX2_ENABLE_NATIVE_ALIASES)
#  define _mm256_extract_epi8(a, index) simde_mm256_extract_epi8(SIMDE__M256I_FROM_NATIVE(a), index)
#endif

SIMDE__FUNCTION_ATTRIBUTES
int
simde_mm256_extract_epi16 (simde__m256i a, const int index) {
  return a.i16[index];
}
#if defined(SIMDE_AVX2_ENABLE_NATIVE_ALIASES)
#  define _mm256_extract_epi16(a, index) simde_mm256_extract_epi16(SIMDE__M256I_FROM_NATIVE(a), index)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128i
simde_mm256_extracti128_si256 (simde__m256i a, const int imm8)
    HEDLEY_REQUIRE_MSG((imm8 & 1) == imm8, "imm8 must be 0 or 1") {
  return a.m128i[imm8];
}
#if defined(SIMDE_AVX2_NATIVE)
#  define simde_mm256_extracti128_si256(a, imm8) SIMDE__M128I_FROM_NATIVE(_mm256_extracti128_si256(a.n, imm8))
#endif
#if defined(SIMDE_AVX2_ENABLE_NATIVE_ALIASES)
#  define _mm256_extracti128_si256(a, imm8) SIMDE__M128I_TO_NATIVE(simde_mm256_extracti128_si256(SIMDE__M256I_FROM_NATIVE(a), imm8))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_max_epi8 (simde__m256i a, simde__m256i b) {
  simde__m256i r;
#if defined(SIMDE_AVX2_NATIVE) && !defined(__PGI)
  r.n = _mm256_max_epi8(a.n, b.n);
#elif defined(SIMDE_SSE4_1_NATIVE)
  r.m128i[0].n = _mm_max_epi8(a.m128i[0].n, b.m128i[0].n);
  r.m128i[1].n = _mm_max_epi8(a.m128i[1].n, b.m128i[1].n);
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.i8) / sizeof(r.i8[0])) ; i++) {
    r.i8[i] = a.i8[i] > b.i8[i] ? a.i8[i] : b.i8[i];
  }
#endif
  return r;
}
#if defined(SIMDE_SSE4_1_NEON)
#  define simde_mm256_max_epi8(a, b) \
     simde_mm256_set_m128i( \
       simde_mm_max_epi8((a).m128i[1], (b).m128i[1]), \
       simde_mm_max_epi8((a).m128i[0], (b).m128i[0]))
#endif
#if defined(SIMDE_AVX2_ENABLE_NATIVE_ALIASES)
#  define _mm256_max_epi8(a, b) SIMDE__M256I_TO_NATIVE(simde_mm256_max_epi8(SIMDE__M256I_FROM_NATIVE(a), SIMDE__M256I_FROM_NATIVE(b)))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_max_epu8 (simde__m256i a, simde__m256i b) {
  simde__m256i r;

#if defined(SIMDE_AVX2_NATIVE)
  r.n = _mm256_max_epu8(a.n, b.n);
#elif defined(SIMDE_SSE2_NATIVE)
  r.m128i[0].n = _mm_max_epu8(a.m128i[0].n, b.m128i[0].n);
  r.m128i[1].n = _mm_max_epu8(a.m128i[1].n, b.m128i[1].n);
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.u8) / sizeof(r.u8[0])) ; i++) {
    r.u8[i] = (a.u8[i] > b.u8[i]) ? a.u8[i] : b.u8[i];
  }
#endif

  return r;
}
#if defined(SIMDE_SSE2_NEON)
#  define simde_mm256_max_epu8(a, b) \
     simde_mm256_set_m128i( \
       simde_mm_max_epu8((a).m128i[1], (b).m128i[1]), \
       simde_mm_max_epu8((a).m128i[0], (b).m128i[0]))
#endif
#if defined(SIMDE_AVX2_ENABLE_NATIVE_ALIASES)
#  define _mm256_max_epu8(a, b) SIMDE__M256I_TO_NATIVE(simde_mm256_max_epu8(SIMDE__M256I_FROM_NATIVE(a), SIMDE__M256I_FROM_NATIVE(b)))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_max_epi16 (simde__m256i a, simde__m256i b) {
  simde__m256i r;

#if defined(SIMDE_AVX2_NATIVE)
  r.n = _mm256_max_epi16(a.n, b.n);
#elif defined(SIMDE_SSE2_NATIVE)
  r.m128i[0].n = _mm_max_epi16(a.m128i[0].n, b.m128i[0].n);
  r.m128i[1].n = _mm_max_epi16(a.m128i[1].n, b.m128i[1].n);
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.i16) / sizeof(r.i16[0])) ; i++) {
    r.i16[i] = (a.i16[i] > b.i16[i]) ? a.i16[i] : b.i16[i];
  }
#endif

  return r;
}
#if defined(SIMDE_AVX2_ENABLE_NATIVE_ALIASES)
#  define _mm256_max_epi16(a, b) SIMDE__M256I_TO_NATIVE(simde_mm256_max_epi16(SIMDE__M256I_FROM_NATIVE(a), SIMDE__M256I_FROM_NATIVE(b)))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_max_epi32 (simde__m256i a, simde__m256i b) {
  simde__m256i r;

#if defined(SIMDE_AVX2_NATIVE)
  r.n = _mm256_max_epi32(a.n, b.n);
#elif defined(SIMDE_SSE4_1_NATIVE)
  r.m128i[0].n = _mm_max_epi32(a.m128i[0].n, b.m128i[0].n);
  r.m128i[1].n = _mm_max_epi32(a.m128i[1].n, b.m128i[1].n);
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.i32) / sizeof(r.i32[0])) ; i++) {
    r.i32[i] = a.i32[i] > b.i32[i] ? a.i32[i] : b.i32[i];
  }
#endif

  return r;
}
#if defined(SIMDE_AVX2_ENABLE_NATIVE_ALIASES)
#  define _mm256_max_epi32(a, b) SIMDE__M256I_TO_NATIVE(simde_mm256_max_epi32(SIMDE__M256I_FROM_NATIVE(a), SIMDE__M256I_FROM_NATIVE(b)))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_min_epu8 (simde__m256i a, simde__m256i b) {
  simde__m256i r;

#if defined(SIMDE_AVX2_NATIVE)
  r.n = _mm256_min_epu8(a.n, b.n);
#elif defined(SIMDE_SSE2_NATIVE)
  r.m128i[0].n = _mm_min_epu8(a.m128i[0].n, b.m128i[0].n);
  r.m128i[1].n = _mm_min_epu8(a.m128i[1].n, b.m128i[1].n);
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.u8) / sizeof(r.u8[0])) ; i++) {
    r.u8[i] = (a.u8[i] < b.u8[i]) ? a.u8[i] : b.u8[i];
  }
#endif

  return r;
}
#if defined(SIMDE_AVX22_ENABLE_NATIVE_ALIASES)
#  define _mm256_min_epu8(a, b) SIMDE__M256I_TO_NATIVE(simde_mm256_min_epu8(SIMDE__M256I_FROM_NATIVE(a), SIMDE__M256I_FROM_NATIVE(b)))
#endif

SIMDE__FUNCTION_ATTRIBUTES
int32_t
simde_mm256_movemask_epi8 (simde__m256i a) {
#if defined(SIMDE_AVX2_NATIVE)
  return _mm256_movemask_epi8(a.n);
#else
  int32_t r = 0;
  SIMDE__VECTORIZE_REDUCTION(|:r)
  for (size_t i = 0 ; i < 32 ; i++) {
    r |= (a.u8[31 - i] >> 7) << (31 - i);
  }
  return r;
#endif
}
#if defined(SIMDE_AVX2_ENABLE_NATIVE_ALIASES)
#  define _mm256_movemask_epi8(a) simde_mm256_movemask_epi8(SIMDE__M256I_FROM_NATIVE(a))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_or_si256 (simde__m256i a, simde__m256i b) {
  simde__m256i r;

#if defined(SIMDE_AVX2_NATIVE)
  r.n = _mm256_or_si256(a.n, b.n);
#elif defined(SIMDE_SSE2_NATIVE)
  r.m128i[0].n = _mm_or_si128(a.m128i[0].n, b.m128i[0].n);
  r.m128i[1].n = _mm_or_si128(a.m128i[1].n, b.m128i[1].n);
#elif defined(SIMDE_VECTOR_SUBSCRIPT_BINARY)
  r.i32f = a.i32f | b.i32f;
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.i32f) / sizeof(r.i32f[0])) ; i++) {
    r.i32f[i] = a.i32f[i] | b.i32f[i];
  }
#endif

  return r;
}
#if defined(SIMDE_AVX2_ENABLE_NATIVE_ALIASES)
#  define _mm256_or_si256(a, b) SIMDE__M256I_TO_NATIVE(simde_mm256_or_si128(SIMDE__M256I_FROM_NATIVE(a), SIMDE__M256I_FROM_NATIVE(b)))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_packs_epi32 (simde__m256i a, simde__m256i b) {
  simde__m256i r;

#if defined(SIMDE_AVX2_NATIVE)
  r.n = _mm256_packs_epi32(a.n, b.n);
#elif defined(SIMDE_SSE2_NATIVE) || defined(SIMDE_SSE2_NEON)
  r = simde_mm256_set_m128i(
    simde_mm_packs_epi32(a.m128i[1], b.m128i[1]),
    simde_mm_packs_epi32(a.m128i[0], b.m128i[0]));
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.i32) / sizeof(r.i32[0]) / 2) ; i++) {
    r.i16[i]      = (a.i32[i] > INT16_MAX) ? INT16_MAX : ((a.i32[i] < INT16_MIN) ? INT16_MIN : ((int16_t) a.i32[i]));
    r.i16[i + 4]  = (b.i32[i] > INT16_MAX) ? INT16_MAX : ((b.i32[i] < INT16_MIN) ? INT16_MIN : ((int16_t) b.i32[i]));
    r.i16[i + 8]  = (a.i32[i + 4] > INT16_MAX) ? INT16_MAX : ((a.i32[i + 4] < INT16_MIN) ? INT16_MIN : ((int16_t) a.i32[i]));
    r.i16[i + 12] = (b.i32[i + 4] > INT16_MAX) ? INT16_MAX : ((b.i32[i + 4] < INT16_MIN) ? INT16_MIN : ((int16_t) b.i32[i]));
  }
#endif

  return r;
}
#if defined(SIMDE_AVX2_ENABLE_NATIVE_ALIASES)
#  define _mm256_packs_epi32(a, b) SIMDE__M256I_TO_NATIVE(simde_mm256_packs_epi32(SIMDE__M256I_FROM_NATIVE(a), SIMDE__M256I_FROM_NATIVE(b)))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_permute2x128_si256 (simde__m256i a, simde__m256i b, const int imm8)
    HEDLEY_REQUIRE_MSG((imm8 & 0xf) == imm8, "imm8 must be in range [0, 15]") {
  simde__m256i r;

  r.m128i[0] = (imm8 & 0x08) ? simde_mm_setzero_si128() : ((imm8 & 0x02) ? b.m128i[(imm8     ) & 1] : a.m128i[(imm8     ) & 1]);
  r.m128i[1] = (imm8 & 0x80) ? simde_mm_setzero_si128() : ((imm8 & 0x20) ? b.m128i[(imm8 >> 4) & 1] : a.m128i[(imm8 >> 4) & 1]);

  return r;
}
#if defined(SIMDE_AVX2_NATIVE)
#  define simde_mm256_permute2x128_si128(a, b, imm8) SIMDE__M256I_FROM_NATIVE(_mm256_permute2x128_si128(a.n, b.n, imm8))
#endif
#if defined(SIMDE_AVX2_ENABLE_NATIVE_ALIASES)
#  define _mm256_permute2x128_si256(a, b, imm8) SIMDE__M256I_TO_NATIVE(simde_mm256_permute2x128_si256(SIMDE__M256I_FROM_NATIVE(a), SIMDE__M256I_FROM_NATIVE(b), imm8))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_shuffle_epi8 (simde__m256i a, simde__m256i b) {
  simde__m256i r;

#if defined(SIMDE_AVX2_NATIVE)
  r.n = _mm256_shuffle_epi8(a.n, b.n);
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < ((sizeof(r.u8) / sizeof(r.u8[0])) / 2) ; i++) {
    r.u8[  i   ] = (b.u8[  i   ] & 0x80) ? 0 : a.u8[(b.u8[  i   ] & 0x0f)     ];
    r.u8[i + 16] = (b.u8[i + 16] & 0x80) ? 0 : a.u8[(b.u8[i + 16] & 0x0f) + 16];
  }
#endif

  return r;
}
#if defined(SIMDE_AVX2_ENABLE_NATIVE_ALIASES)
#  define _mm256_shuffle_epi8(a, b) SIMDE__M256I_TO_NATIVE(simde_mm256_shuffle_epi8(SIMDE__M256I_FROM_NATIVE(a), SIMDE__M256I_FROM_NATIVE(b)))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_shuffle_epi32 (simde__m256i a, const int imm8) {
  simde__m256i r;

  for (size_t i = 0 ; i < ((sizeof(r.i32) / sizeof(r.i32[0])) / 2) ; i++) {
    r.i32[i] = a.i32[(imm8 >> (i * 2)) & 3];
  }
  for (size_t i = 0 ; i < ((sizeof(r.i32) / sizeof(r.i32[0])) / 2) ; i++) {
    r.i32[i + 4] = a.i32[((imm8 >> (i * 2)) & 3) + 4];
  }

  return r;
}
#if defined(SIMDE_AVX2_NATIVE)
#  define simde_mm256_shuffle_epi32(a, imm8) SIMDE__M256I_FROM_NATIVE(_mm256_shuffle_epi32((a).n, (imm8)))
#elif defined(SIMDE_SSE2_NATIVE) && !defined(__PGI)
#  define simde_mm256_shuffle_epi32(a, imm8) \
     simde_mm256_set_m128i( \
       SIMDE__M128I_FROM_NATIVE(_mm_shuffle_epi32((a).m128i[1].n, (imm8))), \
       SIMDE__M128I_FROM_NATIVE(_mm_shuffle_epi32((a).m128i[0].n, (imm8))))
#elif defined(SIMDE__SHUFFLE_VECTOR)
#  define simde_mm256_shuffle_epi32(a, imm8) (__extension__ ({ \
      const simde__m256i simde__tmp_a_ = a;                     \
      (simde__m256i) { .i32 =                                   \
          SIMDE__SHUFFLE_VECTOR(32, 32,                         \
                                (simde__tmp_a_).i32,            \
                                (simde__tmp_a_).i32,            \
                                ((imm8)     ) & 3,              \
                                ((imm8) >> 2) & 3,              \
                                ((imm8) >> 4) & 3,              \
                                ((imm8) >> 6) & 3,              \
                                (((imm8)     ) & 3) + 4,        \
                                (((imm8) >> 2) & 3) + 4,        \
                                (((imm8) >> 4) & 3) + 4,        \
                                (((imm8) >> 6) & 3) + 4) }; }))
#endif
#if defined(SIMDE_AVX2_ENABLE_NATIVE_ALIASES)
#  define _mm256_shuffle_epi32(a, imm8) SIMDE__M256I_TO_NATIVE(simde_mm256_shuffle_epi32(SIMDE__M256I_FROM_NATIVE(a), imm8))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_shufflelo_epi16 (simde__m256i a, const int imm8) {
  simde__m256i r;

  for (size_t i = 0 ; i < 4 ; i++) {
    r.i16[i] = a.i16[((imm8 >> (i * 2)) & 3)];
    r.i16[i+8] = a.i16[((imm8 >> (i * 2)) & 3) + 8];
  }
  r.i64[1] = a.i64[1];
  r.i64[3] = a.i64[3];

  return r;
}
#if defined(SIMDE_AVX2_NATIVE)
#  define simde_mm256_shufflelo_epi16(a, imm8) SIMDE__M256I_FROM_NATIVE(_mm256_shufflelo_epi16((a).n, (imm8)))
#elif defined(SIMDE_SSE2_NATIVE)
#  define simde_mm256_shufflelo_epi32(a, imm8) \
     simde_mm256_set_m128i( \
       SIMDE__M128I_FROM_NATIVE(_mm_shufflelo_epi16((a).m128i[1].n, (imm8))), \
       SIMDE__M128I_FROM_NATIVE(_mm_shufflelo_epi16((a).m128i[0].n, (imm8))))
#elif defined(SIMDE__SHUFFLE_VECTOR)
#  define simde_mm256_shufflelo_epi16(a, imm8) (__extension__ ({ \
      const simde__m256i simde__tmp_a_ = a;			\
      (simde__m256i) { .i16 =					\
	  SIMDE__SHUFFLE_VECTOR(16, 32,				\
				(simde__tmp_a_).i16,		\
				(simde__tmp_a_).i16,		\
				(((imm8)     ) & 3),		\
				(((imm8) >> 2) & 3),		\
				(((imm8) >> 4) & 3),		\
				(((imm8) >> 6) & 3),		\
				4, 5, 6, 7,             	\
				((((imm8)     ) & 3) + 8),	\
				((((imm8) >> 2) & 3) + 8),	\
				((((imm8) >> 4) & 3) + 8),	\
				((((imm8) >> 6) & 3) + 8),	\
				12, 13, 14, 15) }; }))
#endif
#if defined(SIMDE_AVX2_ENABLE_NATIVE_ALIASES)
#  define _mm256_shufflelo_epi16(a, imm8) SIMDE__M256I_TO_NATIVE(simde_mm256_shufflelo_epi16(SIMDE__M256I_FROM_NATIVE(a), imm8))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_slli_epi32 (simde__m256i a, const int imm8) {
  simde__m256i r;

#if defined(SIMDE_VECTOR_SUBSCRIPT_SCALAR)
  r.i32 = a.i32 << HEDLEY_STATIC_CAST(int32_t, imm8);
#else
  const int s = (imm8 > HEDLEY_STATIC_CAST(int, sizeof(r.i32[0]) * CHAR_BIT) - 1) ? 0 : imm8;
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.i32) / sizeof(r.i32[0])) ; i++) {
    r.i32[i] = a.i32[i] << s;
  }
#endif

  return r;
}
#if defined(SIMDE_AVX2_NATIVE)
#  define simde_mm256_slli_epi32(a, imm8) SIMDE__M256I_FROM_NATIVE(_mm256_slli_epi32(a.n, imm8));
#elif defined(SIMDE_SSE2_NATIVE)
#  define simde_mm256_slli_epi32(a, imm8) \
     simde_mm256_set_m128i( \
         SIMDE__M128I_FROM_NATIVE(_mm_slli_epi32((a).m128i[1].n, (imm8))), \
         SIMDE__M128I_FROM_NATIVE(_mm_slli_epi32((a).m128i[0].n, (imm8))))
#endif
#if defined(SIMDE_AVX2_ENABLE_NATIVE_ALIASES)
#  define _mm256_slli_epi32(a, imm8) SIMDE__M256I_TO_NATIVE(simde_mm256_slli_epi32(SIMDE__M256I_FROM_NATIVE(a), imm8))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_sub_epi8 (simde__m256i a, simde__m256i b) {
  simde__m256i r;

#if defined(SIMDE_AVX2_NATIVE)
  r.n = _mm256_sub_epi8(a.n, b.n);
#elif defined(SIMDE_SSE2_NATIVE)
  r.m128i[0].n = _mm_sub_epi8(a.m128i[0].n, b.m128i[0].n);
  r.m128i[1].n = _mm_sub_epi8(a.m128i[1].n, b.m128i[1].n);
#elif defined(SIMDE_VECTOR_SUBSCRIPT_BINARY)
  r.i8 = a.i8 - b.i8;
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.i8) / sizeof(r.i8[0])) ; i++) {
    r.i8[i] = a.i8[i] - b.i8[i];
  }
#endif

  return r;
}
#if defined(SIMDE_AVX2_ENABLE_NATIVE_ALIASES)
#  define _mm256_sub_epi8(a, b) SIMDE__M256I_TO_NATIVE(simde_mm256_sub_epi8(SIMDE__M256I_FROM_NATIVE(a), SIMDE__M256I_FROM_NATIVE(b)))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_sub_epi16 (simde__m256i a, simde__m256i b) {
  simde__m256i r;

#if defined(SIMDE_AVX2_NATIVE)
  r.n = _mm256_sub_epi16(a.n, b.n);
#elif defined(SIMDE_SSE2_NATIVE)
  r.m128i[0].n = _mm_sub_epi16(a.m128i[0].n, b.m128i[0].n);
  r.m128i[1].n = _mm_sub_epi16(a.m128i[1].n, b.m128i[1].n);
#elif defined(SIMDE_VECTOR_SUBSCRIPT_BINARY)
  r.i16 = a.i16 - b.i16;
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.i16) / sizeof(r.i16[0])) ; i++) {
    r.i16[i] = a.i16[i] - b.i16[i];
  }
#endif

  return r;
}
#if defined(SIMDE_AVX2_ENABLE_NATIVE_ALIASES)
#  define _mm256_sub_epi16(a, b) SIMDE__M256I_TO_NATIVE(simde_mm256_sub_epi16(SIMDE__M256I_FROM_NATIVE(a), SIMDE__M256I_FROM_NATIVE(b)))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_sub_epi32 (simde__m256i a, simde__m256i b) {
  simde__m256i r;

#if defined(SIMDE_AVX2_NATIVE)
  r.n = _mm256_sub_epi32(a.n, b.n);
#elif defined(SIMDE_SSE2_NATIVE)
  r.m128i[0].n = _mm_sub_epi32(a.m128i[0].n, b.m128i[0].n);
  r.m128i[1].n = _mm_sub_epi32(a.m128i[1].n, b.m128i[1].n);
#elif defined(SIMDE_VECTOR_SUBSCRIPT_BINARY)
  r.i32 = a.i32 - b.i32;
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.i32) / sizeof(r.i32[0])) ; i++) {
    r.i32[i] = a.i32[i] - b.i32[i];
  }
#endif

  return r;
}
#if defined(SIMDE_AVX2_ENABLE_NATIVE_ALIASES)
#  define _mm256_sub_epi32(a, b) SIMDE__M256I_TO_NATIVE(simde_mm256_sub_epi32(SIMDE__M256I_FROM_NATIVE(a), SIMDE__M256I_FROM_NATIVE(b)))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_srli_epi64 (simde__m256i a, const int imm8) {
  simde__m256i r;

#if defined(SIMDE_VECTOR_SUBSCRIPT_SCALAR)
  r.u64 = a.u64 >> HEDLEY_STATIC_CAST(int32_t, imm8);
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.u64) / sizeof(r.u64[0])) ; i++) {
    r.u64[i] = a.u64[i] >> imm8;
  }
#endif

  return r;
}
#if defined(SIMDE_AVX2_NATIVE)
#  define simde_mm256_srli_epi64(a, imm8) SIMDE__M256I_FROM_NATIVE(_mm256_srli_epi64(a.n, imm8))
#elif defined(SIMDE_SSE2_NATIVE)
#  define simde_mm256_srli_epi64(a, imm8) \
     simde_mm256_set_m128i( \
         SIMDE__M128I_FROM_NATIVE(_mm_srli_epi64((a).m128i[1].n, (imm8))), \
         SIMDE__M128I_FROM_NATIVE(_mm_srli_epi64((a).m128i[0].n, (imm8))))
#endif
#if defined(SIMDE_AVX2_ENABLE_NATIVE_ALIASES)
#  define _mm256_srli_epi64(a, imm8) simde_mm256_srli_epi64(SIMDE__M256I_FROM_NATIVE(a), imm8)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_srli_si256 (simde__m256i a, const int imm8) {
  simde__m256i r;

  if (HEDLEY_UNLIKELY(imm8 > 15)) {
    r.u64[0] = 0;
    r.u64[1] = 0;
    r.u64[2] = 0;
    r.u64[3] = 0;
    return r;
  }

  const int s = imm8 * 8;

#if defined(SIMDE__HAVE_INT128)
  r.u128[0] = a.u128[0] >> s;
  r.u128[1] = a.u128[1] >> s;
#else
  if (s < 64) {
    r.u64[0] = (a.u64[0] >> s) | (a.u64[1] << (64 - s));
    r.u64[1] = (a.u64[1] >> s);
    r.u64[2] = (a.u64[2] >> s) | (a.u64[3] << (64 - s));
    r.u64[3] = (a.u64[3] >> s);
  } else {
    r.u64[0] = a.u64[1] >> (s - 64);
    r.u64[1] = 0;
    r.u64[2] = a.u64[3] >> (s - 64);
    r.u64[3] = 0;
  }
#endif

  return r;
}

#if defined(SIMDE_AVX2_NATIVE)
#  define simde_mm256_srli_si256(a, imm8) SIMDE__M256I_FROM_NATIVE(_mm256_srli_si256(a.n, imm8))
#elif defined(SIMDE_SSE2_NATIVE) && !defined(__PGI)
#  define simde_mm256_srli_si256(a, imm8) \
     simde_mm256_set_m128i( \
         SIMDE__M128I_FROM_NATIVE(_mm_srli_si128((a).m128i[1].n, (imm8))), \
         SIMDE__M128I_FROM_NATIVE(_mm_srli_si128((a).m128i[0].n, (imm8))))
#elif defined(SIMDE_SSE2_NEON)
#  define simde_mm256_srli_si256(a, imm8) \
     simde_mm256_set_m128i( \
       simde_mm_bsrli_si128((a).m128i[1], (imm8)), \
       simde_mm_bsrli_si128((a).m128i[0], (imm8)))
#endif
#if defined(SIMDE_AVX2_ENABLE_NATIVE_ALIASES)
#  define _mm256_srli_si256(a, imm8) SIMDE__M256I_TO_NATIVE(simde_mm_srli_si256(SIMDE__M256I_FROM_NATIVE(a), imm8))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_xor_si256 (simde__m256i a, simde__m256i b) {
  simde__m256i r;

#if defined(SIMDE_AVX2_NATIVE)
  r.n = _mm256_xor_si256(a.n, b.n);
#elif defined(SIMDE_SSE2_NATIVE)
  r.m128i[0].n = _mm_xor_si128(a.m128i[0].n, b.m128i[0].n);
  r.m128i[1].n = _mm_xor_si128(a.m128i[1].n, b.m128i[1].n);
#elif defined(SIMDE_VECTOR_SUBSCRIPT_BINARY)
  r.i32f = a.i32f ^ b.i32f;
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.i64) / sizeof(r.i64[0])) ; i++) {
    r.i64[i] = a.i64[i] ^ b.i64[i];
  }
#endif

  return r;
}
#if defined(SIMDE_AVX2_ENABLE_NATIVE_ALIASES)
#  define _mm256_xor_epi8(a, b) simde_mm256_xor_epi8(SIMDE__M256I_FROM_NATIVE(a), SIMDE__M256I_FROM_NATIVE(b))
#endif

SIMDE__END_DECLS

#endif /* !defined(SIMDE__AVX2_H) */
