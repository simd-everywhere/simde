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

#if !defined(SIMDE__AVX_H)
#  if !defined(SIMDE__AVX_H)
#    define SIMDE__AVX_H
#  endif
#  include "sse2.h"

#  if defined(SIMDE_AVX_NATIVE)
#    undef SIMDE_AVX_NATIVE
#  endif
#  if defined(SIMDE_AVX_FORCE_NATIVE)
#    define SIMDE_AVX_NATIVE
#  elif defined(__AVX__) && !defined(SIMDE_AVX_NO_NATIVE) && !defined(SIMDE_NO_NATIVE)
#    define SIMDE_AVX_NATIVE
#  elif defined(__ARM_NEON) && !defined(SIMDE_AVX_NO_NEON) && !defined(SIMDE_NO_NEON)
#    define SIMDE_AVX_NEON
#  endif

#  if defined(SIMDE_AVX_NATIVE)
#    include <immintrin.h>
#  endif

#  include <stdint.h>
#  include <limits.h>
#  include <string.h>

SIMDE__BEGIN_DECLS

typedef SIMDE__ALIGN(16) union {
#if defined(SIMDE__ENABLE_GCC_VEC_EXT)
  int8_t          i8 __attribute__((__vector_size__(32), __may_alias__));
  int16_t        i16 __attribute__((__vector_size__(32), __may_alias__));
  int32_t        i32 __attribute__((__vector_size__(32), __may_alias__));
  int64_t        i64 __attribute__((__vector_size__(32), __may_alias__));
  uint8_t         u8 __attribute__((__vector_size__(32), __may_alias__));
  uint16_t       u16 __attribute__((__vector_size__(32), __may_alias__));
  uint32_t       u32 __attribute__((__vector_size__(32), __may_alias__));
  uint64_t       u64 __attribute__((__vector_size__(32), __may_alias__));
  #if defined(SIMDE__HAVE_INT128)
  simde_int128  i128 __attribute__((__vector_size__(32), __may_alias__));
  simde_uint128 u128 __attribute__((__vector_size__(32), __may_alias__));
  #endif
  simde_float32  f32 __attribute__((__vector_size__(32), __may_alias__));
  simde_float64  f64 __attribute__((__vector_size__(32), __may_alias__));
#else
  int8_t          i8[32];
  int16_t        i16[16];
  int32_t        i32[8];
  int64_t        i64[4];
  uint8_t         u8[32];
  uint16_t       u16[16];
  uint32_t       u32[8];
  uint64_t       u64[4];
  #if defined(SIMDE__HAVE_INT128)
  simde_int128  i128[2];
  simde_uint128 u128[2];
  #endif
  simde_float32  f32[8];
  simde_float64  f64[4];
#endif

#if defined(SIMDE_SSE2_NATIVE)
  __m128         sse2[2];
#endif
#if defined(SIMDE_AVX_NATIVE)
  __m256         n;
#endif
} simde__m256;

typedef SIMDE__ALIGN(16) union {
#if defined(SIMDE__ENABLE_GCC_VEC_EXT)
  int8_t          i8 __attribute__((__vector_size__(32), __may_alias__));
  int16_t        i16 __attribute__((__vector_size__(32), __may_alias__));
  int32_t        i32 __attribute__((__vector_size__(32), __may_alias__));
  int64_t        i64 __attribute__((__vector_size__(32), __may_alias__));
  uint8_t         u8 __attribute__((__vector_size__(32), __may_alias__));
  uint16_t       u16 __attribute__((__vector_size__(32), __may_alias__));
  uint32_t       u32 __attribute__((__vector_size__(32), __may_alias__));
  uint64_t       u64 __attribute__((__vector_size__(32), __may_alias__));
  #if defined(SIMDE__HAVE_INT128)
  simde_int128  i128 __attribute__((__vector_size__(32), __may_alias__));
  simde_uint128 u128 __attribute__((__vector_size__(32), __may_alias__));
  #endif
  simde_float32  f32 __attribute__((__vector_size__(32), __may_alias__));
  simde_float64  f64 __attribute__((__vector_size__(32), __may_alias__));
#else
  int8_t          i8[32];
  int16_t        i16[16];
  int32_t        i32[8];
  int64_t        i64[4];
  uint8_t         u8[32];
  uint16_t       u16[16];
  uint32_t       u32[8];
  uint64_t       u64[4];
  #if defined(SIMDE__HAVE_INT128)
  simde_int128  i128[2];
  simde_uint128 u128[2];
  #endif
  simde_float32  f32[8];
  simde_float64  f64[4];
#endif

#if defined(SIMDE_SSE2_NATIVE)
  __m128d        sse2[2];
#endif
#if defined(SIMDE_AVX_NATIVE)
  __m256d        n;
#endif
} simde__m256d;

typedef SIMDE__ALIGN(16) union {
#if defined(SIMDE__ENABLE_GCC_VEC_EXT)
  int8_t          i8 __attribute__((__vector_size__(32), __may_alias__));
  int16_t        i16 __attribute__((__vector_size__(32), __may_alias__));
  int32_t        i32 __attribute__((__vector_size__(32), __may_alias__));
  int64_t        i64 __attribute__((__vector_size__(32), __may_alias__));
  uint8_t         u8 __attribute__((__vector_size__(32), __may_alias__));
  uint16_t       u16 __attribute__((__vector_size__(32), __may_alias__));
  uint32_t       u32 __attribute__((__vector_size__(32), __may_alias__));
  uint64_t       u64 __attribute__((__vector_size__(32), __may_alias__));
  #if defined(SIMDE__HAVE_INT128)
  simde_int128  i128 __attribute__((__vector_size__(32), __may_alias__));
  simde_uint128 u128 __attribute__((__vector_size__(32), __may_alias__));
  #endif
  simde_float32  f32 __attribute__((__vector_size__(32), __may_alias__));
  simde_float64  f64 __attribute__((__vector_size__(32), __may_alias__));
#else
  int8_t          i8[32];
  int16_t        i16[16];
  int32_t        i32[8];
  int64_t        i64[4];
  uint8_t         u8[32];
  uint16_t       u16[16];
  uint32_t       u32[8];
  uint64_t       u64[4];
  #if defined(SIMDE__HAVE_INT128)
  simde_int128  i128[2];
  simde_uint128 u128[2];
  #endif
  simde_float32  f32[8];
  simde_float64  f64[4];
#endif

#if defined(SIMDE_SSE2_NATIVE)
  __m128i        sse2[2];
#endif
#if defined(SIMDE_AVX_NATIVE)
  __m256i        n;
#endif
} simde__m256i;

#if defined(SIMDE_AVX_NATIVE)
HEDLEY_STATIC_ASSERT(sizeof(__m256i) == sizeof(simde__m256i), "__m256i size doesn't match simde__m256i size");
HEDLEY_STATIC_ASSERT(sizeof(__m256d) == sizeof(simde__m256d), "__m256d size doesn't match simde__m256d size");
HEDLEY_STATIC_ASSERT( sizeof(__m256) ==  sizeof(simde__m256), "__m256 size doesn't match simde__m256 size");
#define SIMDE__M256I_C(expr) ((simde__m256i) { .n = expr })
#define SIMDE__M256D_C(expr) ((simde__m256d) { .n = expr })
#define SIMDE__M256_C(expr)  ( (simde__m256) { .n = expr })
#endif
HEDLEY_STATIC_ASSERT(32 == sizeof(simde__m256i), "simde__m256i size incorrect");
HEDLEY_STATIC_ASSERT(32 == sizeof(simde__m256d), "simde__m256d size incorrect");
HEDLEY_STATIC_ASSERT(32 ==  sizeof(simde__m256),  "simde__m256 size incorrect");

SIMDE__FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_set_epi8 (int8_t e31, int8_t e30, int8_t e29, int8_t e28,
                      int8_t e27, int8_t e26, int8_t e25, int8_t e24,
                      int8_t e23, int8_t e22, int8_t e21, int8_t e20,
                      int8_t e19, int8_t e18, int8_t e17, int8_t e16,
                      int8_t e15, int8_t e14, int8_t e13, int8_t e12,
                      int8_t e11, int8_t e10, int8_t  e9, int8_t  e8,
                      int8_t  e7, int8_t  e6, int8_t  e5, int8_t  e4,
                      int8_t  e3, int8_t  e2, int8_t  e1, int8_t  e0) {
#if defined(SIMDE_AVX_NATIVE)
  return SIMDE__M256I_C(_mm256_set_epi8(e31, e30, e29, e28, e27, e26, e25, e24,
                                        e23, e22, e21, e20, e19, e18, e17, e16,
                                        e15, e14, e13, e12, e11, e10,  e9,  e8,
                                        e7,  e6,  e5,  e4,  e3,  e2,  e1,  e0));
#elif defined(SIMDE_SSE2_NATIVE)
  simde__m256i res;
  res.sse2[0] = _mm_set_epi8(e15, e14, e13, e12, e11, e10,  e9,  e8,
                              e7,  e6,  e5,  e4,  e3,  e2,  e1,  e0);
  res.sse2[1] = _mm_set_epi8(e31, e30, e29, e28, e27, e26, e25, e24,
                             e23, e22, e21, e20, e19, e18, e17, e16);
  return res;
#else
  return (simde__m256i) { .i8 = {  e0,  e1,  e2,  e3,  e4,  e5,  e6,  e7,
                                   e8,  e9, e10, e11, e12, e13, e14, e15,
                                   e16, e17, e18, e19, e20, e21, e22, e23,
                                   e24, e25, e26, e27, e28, e29, e30, e31 } };
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_set_epi16 (int16_t e15, int16_t e14, int16_t e13, int16_t e12,
                       int16_t e11, int16_t e10, int16_t  e9, int16_t  e8,
                       int16_t  e7, int16_t  e6, int16_t  e5, int16_t  e4,
                       int16_t  e3, int16_t  e2, int16_t  e1, int16_t  e0) {
#if defined(SIMDE_AVX_NATIVE)
  return SIMDE__M256I_C(_mm256_set_epi16(e15, e14, e13, e12, e11, e10,  e9,  e8,
                                          e7,  e6,  e5,  e4,  e3,  e2,  e1,  e0));
#elif defined(SIMDE_SSE2_NATIVE)
  simde__m256i res;
  res.sse2[0] = _mm_set_epi16( e7,  e6,  e5,  e4,  e3,  e2,  e1,  e0);
  res.sse2[1] = _mm_set_epi16(e15, e14, e13, e12, e11, e10,  e9,  e8);
  return res;
#else
  return (simde__m256i) { .i16 = { e0,  e1,  e2,  e3,  e4,  e5,  e6,  e7,
                                   e8,  e9, e10, e11, e12, e13, e14, e15 } };
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_set_epi32 (int32_t e7, int32_t e6, int32_t e5, int32_t e4,
                       int32_t e3, int32_t e2, int32_t e1, int32_t e0) {
#if defined(SIMDE_AVX_NATIVE)
  return SIMDE__M256I_C(_mm256_set_epi32(e7, e6, e5, e4, e3, e2, e1, e0));
#elif defined(SIMDE_SSE2_NATIVE)
  simde__m256i res;
  res.sse2[0] = _mm_set_epi32(e3, e2, e1, e0);
  res.sse2[1] = _mm_set_epi32(e7, e6, e5, e4);
  return res;
#else
  return (simde__m256i) { .i32 = { e0, e1, e2, e3, e4, e5, e6, e7 } };
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_set_epi64x (int64_t  e3, int64_t  e2, int64_t  e1, int64_t  e0) {
#if defined(SIMDE_AVX_NATIVE)
  return SIMDE__M256I_C(_mm256_set_epi64x(e3, e2, e1, e0));
#elif defined(SIMDE_SSE2_NATIVE)
  simde__m256i res;
  res.sse2[0] = _mm_set_epi64x(e1, e0);
  res.sse2[1] = _mm_set_epi64x(e3, e2);
  return res;
#else
  return (simde__m256i) { .i64 = { e0, e1, e2, e3 } };
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m256
simde_mm256_set_ps (simde_float32 e7, simde_float32 e6, simde_float32 e5, simde_float32 e4,
                    simde_float32 e3, simde_float32 e2, simde_float32 e1, simde_float32 e0) {
#if defined(SIMDE_AVX_NATIVE)
  return SIMDE__M256_C(_mm256_set_ps(e7, e6, e5, e4, e3, e2, e1, e0));
#elif defined(SIMDE_SSE2_NATIVE)
  simde__m256 res;
  res.sse2[0] = _mm_set_ps(e3, e2, e1, e0);
  res.sse2[1] = _mm_set_ps(e7, e6, e5, e4);
  return res;
#else
  return (simde__m256) { .f32 = { e0, e1, e2, e3, e4, e5, e6, e7 } };
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m256d
simde_mm256_set_pd (simde_float64 e3, simde_float64 e2, simde_float64 e1, simde_float64 e0) {
#if defined(SIMDE_AVX_NATIVE)
  return SIMDE__M256D_C(_mm256_set_pd(e3, e2, e1, e0));
#elif defined(SIMDE_SSE2_NATIVE)
  simde__m256d res;
  res.sse2[0] = _mm_set_pd(e1, e0);
  res.sse2[1] = _mm_set_pd(e3, e2);
  return res;
#else
  return (simde__m256d) { .f64 = { e0, e1, e2, e3 } };
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m256
simde_mm256_set_m128 (simde__m128 e1, simde__m128 e0) {
#if defined(SIMDE_AVX_NATIVE)
  return SIMDE__M256_C((__m256) _mm256_insertf128_si256(_mm256_castps128_ps256(e0.n), e1.n, 1));
#elif defined(SIMDE_SSE2_NATIVE)
  return (simde__m256) { .sse2 = { e0.n, e1.n } };
#elif defined(SIMDE__HAVE_INT128)
  return (simde__m256) { .i128 = { e0.i128[0], e1.i128[0] } };
#else
  return (simde__m256) { .i64 = { e0.i64[0], e0.i64[1], e1.i64[0], e1.i64[1] } };
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m256d
simde_mm256_set_m128d (simde__m128d e1, simde__m128d e0) {
#if defined(SIMDE_AVX_NATIVE)
  return SIMDE__M256D_C(_mm256_insertf128_pd(_mm256_castpd128_pd256(e0.n), e1.n, 1));
#elif defined(SIMDE_SSE2_NATIVE)
  return (simde__m256d) { .sse2 = { e0.n, e1.n } };
#else
  return (simde__m256d) { .i64 = { e0.i64[0], e0.i64[1], e1.i64[0], e1.i64[1] } };
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_set_m128i (simde__m128i e1, simde__m128i e0) {
#if defined(SIMDE_AVX_NATIVE)
  return SIMDE__M256I_C(_mm256_insertf128_si256(_mm256_castsi128_si256(e0.n), e1.n, 1));
#elif defined(SIMDE_SSE2_NATIVE)
  return (simde__m256i) { .sse2 = { e0.n, e1.n } };
#else
  return (simde__m256i) { .i64 = { e0.i64[0], e0.i64[1], e1.i64[0], e1.i64[1] } };
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_set1_epi8 (int8_t a) {
#if defined(SIMDE_AVX_NATIVE)
  return SIMDE__M256I_C(_mm256_set1_epi8(a));
#elif defined(SIMDE_SSE2_NATIVE)
  simde__m256i res;
  res.sse2[0] = _mm_set1_epi8(a);
  res.sse2[1] = _mm_set1_epi8(a);
  return res;
#else
  return (simde__m256i) { .i8 = { a, a, a, a, a, a, a, a,
                                  a, a, a, a, a, a, a, a,
                                  a, a, a, a, a, a, a, a,
                                  a, a, a, a, a, a, a, a } };
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_set1_epi16 (int16_t a) {
#if defined(SIMDE_AVX_NATIVE)
  return SIMDE__M256I_C(_mm256_set1_epi16(a));
#elif defined(SIMDE_SSE2_NATIVE)
  simde__m256i res;
  res.sse2[0] = _mm_set1_epi16(a);
  res.sse2[1] = _mm_set1_epi16(a);
  return res;
#else
  return (simde__m256i) { .i16 = { a, a, a, a, a, a, a, a,
                                   a, a, a, a, a, a, a, a } };
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_set1_epi32 (int32_t a) {
#if defined(SIMDE_AVX_NATIVE)
  return SIMDE__M256I_C(_mm256_set1_epi32(a));
#elif defined(SIMDE_SSE2_NATIVE)
  simde__m256i res;
  res.sse2[0] = _mm_set1_epi32(a);
  res.sse2[1] = _mm_set1_epi32(a);
  return res;
#else
  return (simde__m256i) { .i32 = { a, a, a, a, a, a, a, a } };
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_set1_epi64x (int64_t a) {
#if defined(SIMDE_AVX_NATIVE)
  return SIMDE__M256I_C(_mm256_set1_epi64x(a));
#elif defined(SIMDE_SSE2_NATIVE)
  simde__m256i res;
  res.sse2[0] = _mm_set1_epi64x(a);
  res.sse2[1] = _mm_set1_epi64x(a);
  return res;
#else
  return (simde__m256i) { .i64 = { a, a, a, a } };
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m256
simde_mm256_set1_ps (simde_float32 a) {
#if defined(SIMDE_AVX_NATIVE)
  return SIMDE__M256_C(_mm256_set1_ps(a));
#elif defined(SIMDE_SSE2_NATIVE)
  simde__m256 res;
  res.sse2[0] = _mm_set1_ps(a);
  res.sse2[1] = _mm_set1_ps(a);
  return res;
#else
  return (simde__m256) { .f32 = { a, a, a, a, a, a, a, a } };
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m256d
simde_mm256_set1_pd (simde_float64 a) {
#if defined(SIMDE_AVX_NATIVE)
  return SIMDE__M256D_C(_mm256_set1_pd(a));
#elif defined(SIMDE_SSE2_NATIVE)
  simde__m256d res;
  res.sse2[0] = _mm_set1_pd(a);
  res.sse2[1] = _mm_set1_pd(a);
  return res;
#else
  return (simde__m256d) { .f64 = { a, a, a, a } };
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m256
simde_mm256_add_ps (simde__m256 a, simde__m256 b) {
#if defined(SIMDE_AVX_NATIVE)
  return SIMDE__M256_C(_mm256_add_ps(a.n, b.n));
#elif defined(SIMDE_SSE2_NATIVE)
  simde__m256 res;
  res.sse2[0] = _mm_add_ps(a.sse2[0], b.sse2[0]);
  res.sse2[1] = _mm_add_ps(a.sse2[1], b.sse2[1]);
  return res;
#else
  simde__m256 r;
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.f32) / sizeof(r.f32[0])) ; i++) {
    r.f32[i] = a.f32[i] + b.f32[i];
  }
  return r;
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m256d
simde_mm256_add_pd (simde__m256d a, simde__m256d b) {
#if defined(SIMDE_AVX_NATIVE)
  return SIMDE__M256D_C(_mm256_add_pd(a.n, b.n));
#elif defined(SIMDE_SSE2_NATIVE)
  simde__m256d res;
  res.sse2[0] = _mm_add_pd(a.sse2[0], b.sse2[0]);
  res.sse2[1] = _mm_add_pd(a.sse2[1], b.sse2[1]);
  return res;
#else
  simde__m256d r;
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.f64) / sizeof(r.f64[0])) ; i++) {
    r.f64[i] = a.f64[i] + b.f64[i];
  }
  return r;
#endif
}

SIMDE__END_DECLS

#endif /* !defined(SIMDE__AVX_H) */
