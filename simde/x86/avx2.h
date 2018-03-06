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
 */

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

#  include <stdint.h>

SIMDE__BEGIN_DECLS

SIMDE__FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_add_epi8 (simde__m256i a, simde__m256i b) {
#if defined(SIMDE_AVX2_NATIVE)
  return SIMDE__M256I_C(_mm256_add_epi8(a.n, b.n));
#elif defined(SIMDE_SSE2_NATIVE)
  simde__m256i res;
  res.sse2[0] = _mm_add_epi8(a.sse2[0], b.sse2[0]);
  res.sse2[1] = _mm_add_epi8(a.sse2[1], b.sse2[1]);
  return res;
#else
  simde__m256i r;
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.i8) / sizeof(r.i8[0])) ; i++) {
    r.i8[i] = a.i8[i] + b.i8[i];
  }
  return r;
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_add_epi16 (simde__m256i a, simde__m256i b) {
#if defined(SIMDE_AVX2_NATIVE)
  return SIMDE__M256I_C(_mm256_add_epi16(a.n, b.n));
#elif defined(SIMDE_SSE2_NATIVE)
  simde__m256i res;
  res.sse2[0] = _mm_add_epi16(a.sse2[0], b.sse2[0]);
  res.sse2[1] = _mm_add_epi16(a.sse2[1], b.sse2[1]);
  return res;
#else
  simde__m256i r;
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.i16) / sizeof(r.i16[0])) ; i++) {
    r.i16[i] = a.i16[i] + b.i16[i];
  }
  return r;
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_add_epi32 (simde__m256i a, simde__m256i b) {
#if defined(SIMDE_AVX2_NATIVE)
  return SIMDE__M256I_C(_mm256_add_epi32(a.n, b.n));
#elif defined(SIMDE_SSE2_NATIVE)
  simde__m256i res;
  res.sse2[0] = _mm_add_epi32(a.sse2[0], b.sse2[0]);
  res.sse2[1] = _mm_add_epi32(a.sse2[1], b.sse2[1]);
  return res;
#else
  simde__m256i r;
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.i32) / sizeof(r.i32[0])) ; i++) {
    r.i32[i] = a.i32[i] + b.i32[i];
  }
  return r;
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_add_epi64 (simde__m256i a, simde__m256i b) {
#if defined(SIMDE_AVX2_NATIVE)
  return SIMDE__M256I_C(_mm256_add_epi64(a.n, b.n));
#elif defined(SIMDE_SSE2_NATIVE)
  simde__m256i res;
  res.sse2[0] = _mm_add_epi64(a.sse2[0], b.sse2[0]);
  res.sse2[1] = _mm_add_epi64(a.sse2[1], b.sse2[1]);
  return res;
#else
  simde__m256i r;
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.i64) / sizeof(r.i64[0])) ; i++) {
    r.i64[i] = a.i64[i] + b.i64[i];
  }
  return r;
#endif
}

SIMDE__END_DECLS

#endif /* !defined(SIMDE__AVX2_H) */
