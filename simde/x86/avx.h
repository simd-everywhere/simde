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
#  include "sse4.1.h"

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

typedef union {
#if defined(SIMDE__ENABLE_GCC_VEC_EXT)
  SIMDE_ALIGN(32) int8_t          i8 __attribute__((__vector_size__(32), __may_alias__));
  SIMDE_ALIGN(32) int16_t        i16 __attribute__((__vector_size__(32), __may_alias__));
  SIMDE_ALIGN(32) int32_t        i32 __attribute__((__vector_size__(32), __may_alias__));
  SIMDE_ALIGN(32) int64_t        i64 __attribute__((__vector_size__(32), __may_alias__));
  SIMDE_ALIGN(32) uint8_t         u8 __attribute__((__vector_size__(32), __may_alias__));
  SIMDE_ALIGN(32) uint16_t       u16 __attribute__((__vector_size__(32), __may_alias__));
  SIMDE_ALIGN(32) uint32_t       u32 __attribute__((__vector_size__(32), __may_alias__));
  SIMDE_ALIGN(32) uint64_t       u64 __attribute__((__vector_size__(32), __may_alias__));
  #if defined(SIMDE__HAVE_INT128)
  SIMDE_ALIGN(32) simde_int128  i128 __attribute__((__vector_size__(32), __may_alias__));
  SIMDE_ALIGN(32) simde_uint128 u128 __attribute__((__vector_size__(32), __may_alias__));
  #endif
  SIMDE_ALIGN(32) simde_float32  f32 __attribute__((__vector_size__(32), __may_alias__));
  SIMDE_ALIGN(32) simde_float64  f64 __attribute__((__vector_size__(32), __may_alias__));
#else
  SIMDE_ALIGN(32) int8_t          i8[32];
  SIMDE_ALIGN(32) int16_t        i16[16];
  SIMDE_ALIGN(32) int32_t        i32[8];
  SIMDE_ALIGN(32) int64_t        i64[4];
  SIMDE_ALIGN(32) uint8_t         u8[32];
  SIMDE_ALIGN(32) uint16_t       u16[16];
  SIMDE_ALIGN(32) uint32_t       u32[8];
  SIMDE_ALIGN(32) uint64_t       u64[4];
  #if defined(SIMDE__HAVE_INT128)
  SIMDE_ALIGN(32) simde_int128  i128[2];
  SIMDE_ALIGN(32) simde_uint128 u128[2];
  #endif
  SIMDE_ALIGN(32) simde_float32  f32[8];
  SIMDE_ALIGN(32) simde_float64  f64[4];
#endif

  SIMDE_ALIGN(32) simde__m128    m128[2];
#if defined(SIMDE_AVX_NATIVE)
  SIMDE_ALIGN(32) __m256         n;
#endif
} simde__m256;

typedef union {
#if defined(SIMDE__ENABLE_GCC_VEC_EXT)
  SIMDE_ALIGN(32) int8_t          i8 __attribute__((__vector_size__(32), __may_alias__));
  SIMDE_ALIGN(32) int16_t        i16 __attribute__((__vector_size__(32), __may_alias__));
  SIMDE_ALIGN(32) int32_t        i32 __attribute__((__vector_size__(32), __may_alias__));
  SIMDE_ALIGN(32) int64_t        i64 __attribute__((__vector_size__(32), __may_alias__));
  SIMDE_ALIGN(32) uint8_t         u8 __attribute__((__vector_size__(32), __may_alias__));
  SIMDE_ALIGN(32) uint16_t       u16 __attribute__((__vector_size__(32), __may_alias__));
  SIMDE_ALIGN(32) uint32_t       u32 __attribute__((__vector_size__(32), __may_alias__));
  SIMDE_ALIGN(32) uint64_t       u64 __attribute__((__vector_size__(32), __may_alias__));
  #if defined(SIMDE__HAVE_INT128)
  SIMDE_ALIGN(32) simde_int128  i128 __attribute__((__vector_size__(32), __may_alias__));
  SIMDE_ALIGN(32) simde_uint128 u128 __attribute__((__vector_size__(32), __may_alias__));
  #endif
  SIMDE_ALIGN(32) simde_float32  f32 __attribute__((__vector_size__(32), __may_alias__));
  SIMDE_ALIGN(32) simde_float64  f64 __attribute__((__vector_size__(32), __may_alias__));
#else
  SIMDE_ALIGN(32) int8_t          i8[32];
  SIMDE_ALIGN(32) int16_t        i16[16];
  SIMDE_ALIGN(32) int32_t        i32[8];
  SIMDE_ALIGN(32) int64_t        i64[4];
  SIMDE_ALIGN(32) uint8_t         u8[32];
  SIMDE_ALIGN(32) uint16_t       u16[16];
  SIMDE_ALIGN(32) uint32_t       u32[8];
  SIMDE_ALIGN(32) uint64_t       u64[4];
  #if defined(SIMDE__HAVE_INT128)
  SIMDE_ALIGN(32) simde_int128  i128[2];
  SIMDE_ALIGN(32) simde_uint128 u128[2];
  #endif
  SIMDE_ALIGN(32) simde_float32  f32[8];
  SIMDE_ALIGN(32) simde_float64  f64[4];
#endif

  SIMDE_ALIGN(32) simde__m128d m128d[2];
#if defined(SIMDE_AVX_NATIVE)
  SIMDE_ALIGN(32) __m256d        n;
#endif
} simde__m256d;

typedef union {
#if defined(SIMDE__ENABLE_GCC_VEC_EXT)
  SIMDE_ALIGN(32) int8_t          i8 __attribute__((__vector_size__(32), __may_alias__));
  SIMDE_ALIGN(32) int16_t        i16 __attribute__((__vector_size__(32), __may_alias__));
  SIMDE_ALIGN(32) int32_t        i32 __attribute__((__vector_size__(32), __may_alias__));
  SIMDE_ALIGN(32) int64_t        i64 __attribute__((__vector_size__(32), __may_alias__));
  SIMDE_ALIGN(32) uint8_t         u8 __attribute__((__vector_size__(32), __may_alias__));
  SIMDE_ALIGN(32) uint16_t       u16 __attribute__((__vector_size__(32), __may_alias__));
  SIMDE_ALIGN(32) uint32_t       u32 __attribute__((__vector_size__(32), __may_alias__));
  SIMDE_ALIGN(32) uint64_t       u64 __attribute__((__vector_size__(32), __may_alias__));
  #if defined(SIMDE__HAVE_INT128)
  SIMDE_ALIGN(32) simde_int128  i128 __attribute__((__vector_size__(32), __may_alias__));
  SIMDE_ALIGN(32) simde_uint128 u128 __attribute__((__vector_size__(32), __may_alias__));
  #endif
  SIMDE_ALIGN(32) simde_float32  f32 __attribute__((__vector_size__(32), __may_alias__));
  SIMDE_ALIGN(32) simde_float64  f64 __attribute__((__vector_size__(32), __may_alias__));
#else
  SIMDE_ALIGN(32) int8_t          i8[32];
  SIMDE_ALIGN(32) int16_t        i16[16];
  SIMDE_ALIGN(32) int32_t        i32[8];
  SIMDE_ALIGN(32) int64_t        i64[4];
  SIMDE_ALIGN(32) uint8_t         u8[32];
  SIMDE_ALIGN(32) uint16_t       u16[16];
  SIMDE_ALIGN(32) uint32_t       u32[8];
  SIMDE_ALIGN(32) uint64_t       u64[4];
  #if defined(SIMDE__HAVE_INT128)
  SIMDE_ALIGN(32) simde_int128  i128[2];
  SIMDE_ALIGN(32) simde_uint128 u128[2];
  #endif
  SIMDE_ALIGN(32) simde_float32  f32[8];
  SIMDE_ALIGN(32) simde_float64  f64[4];
#endif

  SIMDE_ALIGN(32) simde__m128i   m128i[2];
#if defined(SIMDE_AVX_NATIVE)
  SIMDE_ALIGN(32) __m256i        n;
#endif
} simde__m256i;

#if defined(SIMDE_AVX_NATIVE)
  HEDLEY_STATIC_ASSERT(sizeof(__m256i) == sizeof(simde__m256i), "__m256i size doesn't match simde__m256i size");
  HEDLEY_STATIC_ASSERT(sizeof(__m256d) == sizeof(simde__m256d), "__m256d size doesn't match simde__m256d size");
  HEDLEY_STATIC_ASSERT( sizeof(__m256) ==  sizeof(simde__m256), "__m256 size doesn't match simde__m256 size");
  SIMDE__FUNCTION_ATTRIBUTES simde__m256i SIMDE__M256I_C(__m256i v) { simde__m256i r; r.n = v; return r; }
  SIMDE__FUNCTION_ATTRIBUTES simde__m256d SIMDE__M256D_C(__m256d v) { simde__m256d r; r.n = v; return r; }
  SIMDE__FUNCTION_ATTRIBUTES simde__m256 SIMDE__M256_C(__m256 v) { simde__m256 r; r.n = v; return r; }
#endif
HEDLEY_STATIC_ASSERT(32 == sizeof(simde__m256i), "simde__m256i size incorrect");
HEDLEY_STATIC_ASSERT(32 == sizeof(simde__m256d), "simde__m256d size incorrect");
HEDLEY_STATIC_ASSERT(32 ==  sizeof(simde__m256),  "simde__m256 size incorrect");

#define SIMDE_CMP_EQ_OQ     0
#define SIMDE_CMP_LT_OS     1
#define SIMDE_CMP_LE_OS     2
#define SIMDE_CMP_UNORD_Q   3
#define SIMDE_CMP_NEQ_UQ    4
#define SIMDE_CMP_NLT_US    5
#define SIMDE_CMP_NLE_US    6
#define SIMDE_CMP_ORD_Q     7
#define SIMDE_CMP_EQ_UQ     8
#define SIMDE_CMP_NGE_US    9
#define SIMDE_CMP_NGT_US   10
#define SIMDE_CMP_FALSE_OQ 11
#define SIMDE_CMP_NEQ_OQ   12
#define SIMDE_CMP_GE_OS    13
#define SIMDE_CMP_GT_OS    14
#define SIMDE_CMP_TRUE_UQ  15
#define SIMDE_CMP_EQ_OS    16
#define SIMDE_CMP_LT_OQ    17
#define SIMDE_CMP_LE_OQ    18
#define SIMDE_CMP_UNORD_S  19
#define SIMDE_CMP_NEQ_US   20
#define SIMDE_CMP_NLT_UQ   21
#define SIMDE_CMP_NLE_UQ   22
#define SIMDE_CMP_ORD_S    23
#define SIMDE_CMP_EQ_US    24
#define SIMDE_CMP_NGE_UQ   25
#define SIMDE_CMP_NGT_UQ   26
#define SIMDE_CMP_FALSE_OS 27
#define SIMDE_CMP_NEQ_OS   28
#define SIMDE_CMP_GE_OQ    29
#define SIMDE_CMP_GT_OQ    30
#define SIMDE_CMP_TRUE_US  31

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
  res.m128i[0].n = _mm_set_epi8(e15, e14, e13, e12, e11, e10,  e9,  e8,
				e7,  e6,  e5,  e4,  e3,  e2,  e1,  e0);
  res.m128i[1].n = _mm_set_epi8(e31, e30, e29, e28, e27, e26, e25, e24,
			       e23, e22, e21, e20, e19, e18, e17, e16);
  return res;
#else
  simde__m256i r;
  r.i8[ 0] =  e0;
  r.i8[ 1] =  e1;
  r.i8[ 2] =  e2;
  r.i8[ 3] =  e3;
  r.i8[ 4] =  e4;
  r.i8[ 5] =  e5;
  r.i8[ 6] =  e6;
  r.i8[ 7] =  e7;
  r.i8[ 8] =  e8;
  r.i8[ 9] =  e9;
  r.i8[10] = e10;
  r.i8[11] = e11;
  r.i8[12] = e12;
  r.i8[13] = e13;
  r.i8[14] = e14;
  r.i8[15] = e15;
  r.i8[16] = e16;
  r.i8[17] = e17;
  r.i8[18] = e18;
  r.i8[19] = e19;
  r.i8[20] = e20;
  r.i8[20] = e20;
  r.i8[21] = e21;
  r.i8[22] = e22;
  r.i8[23] = e23;
  r.i8[24] = e24;
  r.i8[25] = e25;
  r.i8[26] = e26;
  r.i8[27] = e27;
  r.i8[28] = e28;
  r.i8[29] = e29;
  r.i8[30] = e30;
  r.i8[31] = e31;
  return r;
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
  res.m128i[0].n = _mm_set_epi16( e7,  e6,  e5,  e4,  e3,  e2,  e1,  e0);
  res.m128i[1].n = _mm_set_epi16(e15, e14, e13, e12, e11, e10,  e9,  e8);
  return res;
#else
  simde__m256i r;
  r.i16[ 0] =  e0;
  r.i16[ 1] =  e1;
  r.i16[ 2] =  e2;
  r.i16[ 3] =  e3;
  r.i16[ 4] =  e4;
  r.i16[ 5] =  e5;
  r.i16[ 6] =  e6;
  r.i16[ 7] =  e7;
  r.i16[ 8] =  e8;
  r.i16[ 9] =  e9;
  r.i16[10] = e10;
  r.i16[11] = e11;
  r.i16[12] = e12;
  r.i16[13] = e13;
  r.i16[14] = e14;
  r.i16[15] = e15;
  return r;
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
  res.m128i[0].n = _mm_set_epi32(e3, e2, e1, e0);
  res.m128i[1].n = _mm_set_epi32(e7, e6, e5, e4);
  return res;
#else
  simde__m256i r;
  r.i32[0] = e0;
  r.i32[1] = e1;
  r.i32[2] = e2;
  r.i32[3] = e3;
  r.i32[4] = e4;
  r.i32[5] = e5;
  r.i32[6] = e6;
  r.i32[7] = e7;
  return r;
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_set_epi64x (int64_t  e3, int64_t  e2, int64_t  e1, int64_t  e0) {
#if defined(SIMDE_AVX_NATIVE)
  return SIMDE__M256I_C(_mm256_set_epi64x(e3, e2, e1, e0));
#elif defined(SIMDE_SSE2_NATIVE)
  simde__m256i res;
  res.m128i[0].n = _mm_set_epi64x(e1, e0);
  res.m128i[1].n = _mm_set_epi64x(e3, e2);
  return res;
#else
  simde__m256i r;
  r.i64[0] = e0;
  r.i64[1] = e1;
  r.i64[2] = e2;
  r.i64[3] = e3;
  return r;
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m256i
simde_x_mm256_set_epu8 (uint8_t e31, uint8_t e30, uint8_t e29, uint8_t e28,
                        uint8_t e27, uint8_t e26, uint8_t e25, uint8_t e24,
                        uint8_t e23, uint8_t e22, uint8_t e21, uint8_t e20,
                        uint8_t e19, uint8_t e18, uint8_t e17, uint8_t e16,
                        uint8_t e15, uint8_t e14, uint8_t e13, uint8_t e12,
                        uint8_t e11, uint8_t e10, uint8_t  e9, uint8_t  e8,
                        uint8_t  e7, uint8_t  e6, uint8_t  e5, uint8_t  e4,
                        uint8_t  e3, uint8_t  e2, uint8_t  e1, uint8_t  e0) {
  simde__m256i r;
  r.u8[ 0] =  e0;
  r.u8[ 1] =  e1;
  r.u8[ 2] =  e2;
  r.u8[ 3] =  e3;
  r.u8[ 4] =  e4;
  r.u8[ 5] =  e5;
  r.u8[ 6] =  e6;
  r.u8[ 7] =  e7;
  r.u8[ 8] =  e8;
  r.u8[ 9] =  e9;
  r.u8[10] = e10;
  r.u8[11] = e11;
  r.u8[12] = e12;
  r.u8[13] = e13;
  r.u8[14] = e14;
  r.u8[15] = e15;
  r.u8[16] = e16;
  r.u8[17] = e17;
  r.u8[18] = e18;
  r.u8[19] = e19;
  r.u8[20] = e20;
  r.u8[20] = e20;
  r.u8[21] = e21;
  r.u8[22] = e22;
  r.u8[23] = e23;
  r.u8[24] = e24;
  r.u8[25] = e25;
  r.u8[26] = e26;
  r.u8[27] = e27;
  r.u8[28] = e28;
  r.u8[29] = e29;
  r.u8[30] = e30;
  r.u8[31] = e31;
  return r;
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m256
simde_mm256_set_ps (simde_float32 e7, simde_float32 e6, simde_float32 e5, simde_float32 e4,
                    simde_float32 e3, simde_float32 e2, simde_float32 e1, simde_float32 e0) {
#if defined(SIMDE_AVX_NATIVE)
  return SIMDE__M256_C(_mm256_set_ps(e7, e6, e5, e4, e3, e2, e1, e0));
#elif defined(SIMDE_SSE_NATIVE)
  simde__m256 res;
  res.m128[0].n = _mm_set_ps(e3, e2, e1, e0);
  res.m128[1].n = _mm_set_ps(e7, e6, e5, e4);
  return res;
#else
  simde__m256 r;
  r.f32[0] = e0;
  r.f32[1] = e1;
  r.f32[2] = e2;
  r.f32[3] = e3;
  r.f32[4] = e4;
  r.f32[5] = e5;
  r.f32[6] = e6;
  r.f32[7] = e7;
  return r;
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m256d
simde_mm256_set_pd (simde_float64 e3, simde_float64 e2, simde_float64 e1, simde_float64 e0) {
#if defined(SIMDE_AVX_NATIVE)
  return SIMDE__M256D_C(_mm256_set_pd(e3, e2, e1, e0));
#elif defined(SIMDE_SSE2_NATIVE)
  simde__m256d res;
  res.m128d[0].n = _mm_set_pd(e1, e0);
  res.m128d[1].n = _mm_set_pd(e3, e2);
  return res;
#else
  simde__m256d r;
  r.f64[0] = e0;
  r.f64[1] = e1;
  r.f64[2] = e2;
  r.f64[3] = e3;
  return r;
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m256
simde_mm256_set_m128 (simde__m128 e1, simde__m128 e0) {
  simde__m256 r;

#if defined(SIMDE_AVX_NATIVE)
  r.n = _mm256_insertf128_ps(_mm256_castps128_ps256(e0.n), e1.n, 1);
#elif defined(SIMDE_SSE2_NATIVE)
  r.m128[0] = e0;
  r.m128[1] = e1;
#elif defined(SIMDE__HAVE_INT128)
  r.i128[0] = e0.i128[0];
  r.i128[1] = e1.i128[0];
#else
  r.i64[0] = e0.i64[0];
  r.i64[1] = e0.i64[1];
  r.i64[2] = e1.i64[0];
  r.i64[3] = e1.i64[1];
#endif

  return r;
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m256d
simde_mm256_set_m128d (simde__m128d e1, simde__m128d e0) {
  simde__m256d r;

#if defined(SIMDE_AVX_NATIVE)
  r.n = _mm256_insertf128_pd(_mm256_castpd128_pd256(e0.n), e1.n, 1);
#elif defined(SIMDE_SSE2_NATIVE)
  r.m128d[0] = e0;
  r.m128d[1] = e1;
#else
  r.i64[0] = e0.i64[0];
  r.i64[1] = e0.i64[1];
  r.i64[2] = e1.i64[0];
  r.i64[3] = e1.i64[1];
#endif

  return r;
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_set_m128i (simde__m128i e1, simde__m128i e0) {
  simde__m256i r;

#if defined(SIMDE_AVX_NATIVE)
  r.n = _mm256_insertf128_si256(_mm256_castsi128_si256(e0.n), e1.n, 1);
#elif defined(SIMDE_SSE2_NATIVE)
  r.m128i[0] = e0;
  r.m128i[1] = e1;
#else
  r.i64[0] = e0.i64[0];
  r.i64[1] = e0.i64[1];
  r.i64[2] = e1.i64[0];
  r.i64[3] = e1.i64[1];
#endif

  return r;
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_set1_epi8 (int8_t a) {
  simde__m256i r;

#if defined(SIMDE_AVX_NATIVE)
  r.n = _mm256_set1_epi8(a);
#elif defined(SIMDE_SSE2_NATIVE)
  r.m128i[0].n = _mm_set1_epi8(a);
  r.m128i[1].n = _mm_set1_epi8(a);
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.i8) / sizeof(r.i8[0])) ; i++) {
    r.i8[i] = a;
  }
#endif

  return r;
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_set1_epi16 (int16_t a) {
  simde__m256i r;

#if defined(SIMDE_AVX_NATIVE)
  r.n = _mm256_set1_epi16(a);
#elif defined(SIMDE_SSE2_NATIVE)
  r.m128i[0].n = _mm_set1_epi16(a);
  r.m128i[1].n = _mm_set1_epi16(a);
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.i16) / sizeof(r.i16[0])) ; i++) {
    r.i16[i] = a;
  }
#endif

  return r;
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_set1_epi32 (int32_t a) {
  simde__m256i r;

#if defined(SIMDE_AVX_NATIVE)
  r.n = _mm256_set1_epi32(a);
#elif defined(SIMDE_SSE2_NATIVE)
  r.m128i[0].n = _mm_set1_epi32(a);
  r.m128i[1].n = _mm_set1_epi32(a);
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.i32) / sizeof(r.i32[0])) ; i++) {
    r.i32[i] = a;
  }
#endif

  return r;
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_set1_epi64x (int64_t a) {
  simde__m256i r;

#if defined(SIMDE_AVX_NATIVE)
  r.n = _mm256_set1_epi64x(a);
#elif defined(SIMDE_SSE2_NATIVE)
  r.m128i[0].n = _mm_set1_epi64x(a);
  r.m128i[1].n = _mm_set1_epi64x(a);
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.i64) / sizeof(r.i64[0])) ; i++) {
    r.i64[i] = a;
  }
#endif

  return r;
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m256
simde_mm256_set1_ps (simde_float32 a) {
  simde__m256 r;

#if defined(SIMDE_AVX_NATIVE)
  r.n = _mm256_set1_ps(a);
#elif defined(SIMDE_SSE_NATIVE)
  r.m128[0].n = _mm_set1_ps(a);
  r.m128[1].n = _mm_set1_ps(a);
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.f32) / sizeof(r.f32[0])) ; i++) {
    r.f32[i] = a;
  }
#endif

  return r;
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m256d
simde_mm256_set1_pd (simde_float64 a) {
  simde__m256d r;

#if defined(SIMDE_AVX_NATIVE)
  r.n = _mm256_set1_pd(a);
#elif defined(SIMDE_SSE2_NATIVE)
  r.m128d[0].n = _mm_set1_pd(a);
  r.m128d[1].n = _mm_set1_pd(a);
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.f64) / sizeof(r.f64[0])) ; i++) {
    r.f64[i] = a;
  }
#endif

  return r;
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m256
simde_mm256_add_ps (simde__m256 a, simde__m256 b) {
  simde__m256 r;

#if defined(SIMDE_AVX_NATIVE)
  r.n = _mm256_add_ps(a.n, b.n);
#elif defined(SIMDE_SSE_NATIVE)
  r.m128[0].n = _mm_add_ps(a.m128[0].n, b.m128[0].n);
  r.m128[1].n = _mm_add_ps(a.m128[1].n, b.m128[1].n);
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.f32) / sizeof(r.f32[0])) ; i++) {
    r.f32[i] = a.f32[i] + b.f32[i];
  }
#endif

  return r;
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m256d
simde_mm256_add_pd (simde__m256d a, simde__m256d b) {
  simde__m256d r;

#if defined(SIMDE_AVX_NATIVE)
  r.n = _mm256_add_pd(a.n, b.n);
#elif defined(SIMDE_SSE2_NATIVE)
  r.m128d[0].n = _mm_add_pd(a.m128d[0].n, b.m128d[0].n);
  r.m128d[1].n = _mm_add_pd(a.m128d[1].n, b.m128d[1].n);
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.f64) / sizeof(r.f64[0])) ; i++) {
    r.f64[i] = a.f64[i] + b.f64[i];
  }
#endif

  return r;
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m256
simde_mm256_addsub_ps (simde__m256 a, simde__m256 b) {
  simde__m256 r;

#if defined(SIMDE_AVX_NATIVE)
  r.n = _mm256_addsub_ps(a.n, b.n);
#elif defined(SIMDE_SSE3_NATIVE)
  r.m128[0].n = _mm_addsub_ps(a.m128[0].n, b.m128[0].n);
  r.m128[1].n = _mm_addsub_ps(a.m128[1].n, b.m128[1].n);
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.f32) / sizeof(r.f32[0])) ; i += 2) {
    r.f32[  i  ] = a.f32[  i  ] - b.f32[  i  ];
    r.f32[i + 1] = a.f32[i + 1] + b.f32[i + 1];
  }
#endif

  return r;
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m256d
simde_mm256_addsub_pd (simde__m256d a, simde__m256d b) {
  simde__m256d r;

#if defined(SIMDE_AVX_NATIVE)
  r.n = _mm256_addsub_pd(a.n, b.n);
#elif defined(SIMDE_SSE3_NATIVE)
  r.m128d[0].n = _mm_addsub_pd(a.m128d[0].n, b.m128d[0].n);
  r.m128d[1].n = _mm_addsub_pd(a.m128d[1].n, b.m128d[1].n);
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.f64) / sizeof(r.f64[0])) ; i += 2) {
    r.f64[  i  ] = a.f64[  i  ] - b.f64[  i  ];
    r.f64[i + 1] = a.f64[i + 1] + b.f64[i + 1];
  }
#endif

  return r;
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m256
simde_mm256_and_ps (simde__m256 a, simde__m256 b) {
  simde__m256 r;

#if defined(SIMDE_AVX_NATIVE)
  r.n = _mm256_and_ps(a.n, b.n);
#elif defined(SIMDE_SSE_NATIVE)
  r.m128[0].n = _mm_and_ps(a.m128[0].n, b.m128[0].n);
  r.m128[1].n = _mm_and_ps(a.m128[1].n, b.m128[1].n);
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.u32) / sizeof(r.u32[0])) ; i++) {
    r.u32[i] = a.u32[i] & b.u32[i];
  }
#endif

  return r;
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m256d
simde_mm256_and_pd (simde__m256d a, simde__m256d b) {
  simde__m256d r;

#if defined(SIMDE_AVX_NATIVE)
  r.n = _mm256_and_pd(a.n, b.n);
#elif defined(SIMDE_SSE2_NATIVE)
  r.m128d[0].n = _mm_and_pd(a.m128d[0].n, b.m128d[0].n);
  r.m128d[1].n = _mm_and_pd(a.m128d[1].n, b.m128d[1].n);
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.u64) / sizeof(r.u64[0])) ; i++) {
    r.u64[i] = a.u64[i] & b.u64[i];
  }
#endif

  return r;
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m256
simde_mm256_andnot_ps (simde__m256 a, simde__m256 b) {
  simde__m256 r;

#if defined(SIMDE_AVX_NATIVE)
  r.n = _mm256_andnot_ps(a.n, b.n);
#elif defined(SIMDE_SSE_NATIVE)
  r.m128[0].n = _mm_andnot_ps(a.m128[0].n, b.m128[0].n);
  r.m128[1].n = _mm_andnot_ps(a.m128[1].n, b.m128[1].n);
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.u32) / sizeof(r.u32[0])) ; i++) {
    r.u32[i] = a.u32[i] & b.u32[i];
  }
#endif

  return r;
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m256d
simde_mm256_andnot_pd (simde__m256d a, simde__m256d b) {
  simde__m256d r;

#if defined(SIMDE_AVX_NATIVE)
  r.n = _mm256_andnot_pd(a.n, b.n);
#elif defined(SIMDE_SSE2_NATIVE)
  r.m128d[0].n = _mm_andnot_pd(a.m128d[0].n, b.m128d[0].n);
  r.m128d[1].n = _mm_andnot_pd(a.m128d[1].n, b.m128d[1].n);
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.u64) / sizeof(r.u64[0])) ; i++) {
    r.u64[i] = a.u64[i] & b.u64[i];
  }
#endif

  return r;
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m256
simde_mm256_blend_ps (simde__m256 a, simde__m256 b, const int imm8)
    HEDLEY_REQUIRE_MSG((imm8 & 0xff) == imm8, "imm8 must be in range [0, 255]") {
  simde__m256 r;
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.f32) / sizeof(r.f32[0])) ; i++) {
    r.f32[i] = ((imm8 >> i) & 1) ? b.f32[i] : a.f32[i];
  }
  return r;
}
#if defined(SIMDE_AVX_NATIVE)
#  define simde_mm256_blend_ps(a, b, imm8) SIMDE__M256_C(_mm256_blend_ps(a.n, b.n, imm8))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m256d
simde_mm256_blend_pd (simde__m256d a, simde__m256d b, const int imm8)
    HEDLEY_REQUIRE_MSG((imm8 & 0xf) == imm8, "imm8 must be in range [0, 15]") {
  simde__m256d r;
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.f64) / sizeof(r.f64[0])) ; i++) {
    r.f64[i] = ((imm8 >> i) & 1) ? b.f64[i] : a.f64[i];
  }
  return r;
}
#if defined(SIMDE_AVX_NATIVE)
#  define simde_mm256_blend_pd(a, b, imm8) SIMDE__M256D_C(_mm256_blend_pd(a.n, b.n, imm8))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m256
simde_mm256_blendv_ps (simde__m256 a, simde__m256 b, simde__m256 mask) {
  simde__m256 r;

#if defined(SIMDE_AVX_NATIVE)
  r.n = _mm256_blendv_ps(a.n, b.n, mask.n);
#elif defined(SIMDE_SSE4_1_NATIVE)
  r.m128[0].n = _mm_blendv_ps(a.m128[0].n, b.m128[0].n, mask.m128[0].n);
  r.m128[1].n = _mm_blendv_ps(a.m128[1].n, b.m128[1].n, mask.m128[1].n);
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.u32) / sizeof(r.u32[0])) ; i++) {
    r.f32[i] = (mask.u32[i] & (UINT32_C(1) << 31)) ? b.f32[i] : a.f32[i];
  }
#endif

  return r;
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m256d
simde_mm256_blendv_pd (simde__m256d a, simde__m256d b, simde__m256d mask) {
  simde__m256d r;

#if defined(SIMDE_AVX_NATIVE)
  r.n = _mm256_blendv_pd(a.n, b.n, mask.n);
#elif defined(SIMDE_SSE4_1_NATIVE)
  r.m128d[0].n = _mm_blendv_pd(a.m128d[0].n, b.m128d[0].n, mask.m128d[0].n);
  r.m128d[1].n = _mm_blendv_pd(a.m128d[1].n, b.m128d[1].n, mask.m128d[1].n);
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.u64) / sizeof(r.u64[0])) ; i++) {
    r.f64[i] = (mask.u64[i] & (UINT64_C(1) << 63)) ? b.f64[i] : a.f64[i];
  }
#endif

  return r;
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m256d
simde_mm256_broadcast_pd (simde__m128d const * mem_addr) {
  simde__m256d r;

#if defined(SIMDE_AVX_NATIVE)
  r.n = _mm256_broadcast_pd(&(mem_addr->n));
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.f64) / sizeof(r.f64[0])) ; i += 2) {
    r.f64[  i  ] = mem_addr->f64[0];
    r.f64[i + 1] = mem_addr->f64[1];
  }
#endif

  return r;
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m256
simde_mm256_broadcast_ps (simde__m128 const * mem_addr) {
  simde__m256 r;

#if defined(SIMDE_AVX_NATIVE)
  r.n = _mm256_broadcast_ps(&(mem_addr->n));
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.f32) / sizeof(r.f32[0])) ; i++) {
    r.f32[i] = mem_addr->f32[i & 3];
  }
#endif

  return r;
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m256d
simde_mm256_broadcast_sd (simde_float64 const * a) {
  simde__m256d r;

#if defined(SIMDE_AVX_NATIVE)
  r.n = _mm256_broadcast_sd(a);
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.f64) / sizeof(r.f64[0])) ; i++) {
    r.f64[i] = *a;
  }
#endif

  return r;
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m128
simde_mm_broadcast_ss (simde_float32 const * a) {
  simde__m128 r;

#if defined(SIMDE_AVX_NATIVE)
  r.n = _mm_broadcast_ss(a);
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.f32) / sizeof(r.f32[0])) ; i++) {
    r.f32[i] = *a;
  }
#endif

  return r;
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m256
simde_mm256_broadcast_ss (simde_float32 const * a) {
  simde__m256 r;

#if defined(SIMDE_AVX_NATIVE)
  r.n = _mm256_broadcast_ss(a);
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.f32) / sizeof(r.f32[0])) ; i++) {
    r.f32[i] = *a;
  }
#endif

  return r;
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m256
simde_mm256_castpd_ps (simde__m256d a) {
#if defined(SIMDE_AVX_NATIVE)
  return SIMDE__M256_C(_mm256_castpd_ps(a.n));
#else
  return *((simde__m256*) &a);
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_castpd_si256 (simde__m256d a) {
#if defined(SIMDE_AVX_NATIVE)
  return SIMDE__M256I_C(_mm256_castpd_si256(a.n));
#else
  return *((simde__m256i*) &a);
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m256d
simde_mm256_castpd128_pd256 (simde__m128d a) {
#if defined(SIMDE_AVX_NATIVE)
  return SIMDE__M256D_C(_mm256_castpd128_pd256(a.n));
#else
  simde__m256d r;
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < 2 ; i++) {
    r.i64[i] = a.i64[i];
  }
  return r;
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m128d
simde_mm256_castpd256_pd128 (simde__m256d a) {
#if defined(SIMDE_AVX_NATIVE)
  return SIMDE__M128D_C(_mm256_castpd256_pd128(a.n));
#else
  simde__m128d r;
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < 2 ; i++) {
    r.i64[i] = a.i64[i];
  }
  return r;
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m256d
simde_mm256_castps_pd (simde__m256 a) {
#if defined(SIMDE_AVX_NATIVE)
  return SIMDE__M256D_C(_mm256_castps_pd(a.n));
#else
  return *((simde__m256d*) &a);
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_castps_si256 (simde__m256 a) {
#if defined(SIMDE_AVX_NATIVE)
  return SIMDE__M256I_C(_mm256_castps_si256(a.n));
#else
  return *((simde__m256i*) &a);
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m256
simde_mm256_castps128_ps256 (simde__m128 a) {
#if defined(SIMDE_AVX_NATIVE)
  return SIMDE__M256_C(_mm256_castps128_ps256(a.n));
#else
  simde__m256 r;
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < 2 ; i++) {
    r.i64[i] = a.i64[i];
  }
  return r;
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m128
simde_mm256_castps256_ps128 (simde__m256 a) {
#if defined(SIMDE_AVX_NATIVE)
  return SIMDE__M128_C(_mm256_castps256_ps128(a.n));
#else
  simde__m128 r;
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < 2 ; i++) {
    r.i64[i] = a.i64[i];
  }
  return r;
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_castsi128_si256 (simde__m128i a) {
#if defined(SIMDE_AVX_NATIVE)
  return SIMDE__M256I_C(_mm256_castsi128_si256(a.n));
#else
  simde__m256i r;
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < 2 ; i++) {
    r.i64[i] = a.i64[i];
  }
  return r;
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m128i
simde_mm256_castsi256_si128 (simde__m256i a) {
#if defined(SIMDE_AVX_NATIVE)
  return SIMDE__M128I_C(_mm256_castsi256_si128(a.n));
#else
  simde__m128i r;
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < 2 ; i++) {
    r.i64[i] = a.i64[i];
  }
  return r;
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m256d
simde_mm256_castsi256_pd (simde__m256i a) {
#if defined(SIMDE_AVX_NATIVE)
  return SIMDE__M256D_C(_mm256_castsi256_pd(a.n));
#else
  return *((simde__m256d*) &a);
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m256
simde_mm256_castsi256_ps (simde__m256i a) {
#if defined(SIMDE_AVX_NATIVE)
  return SIMDE__M256_C(_mm256_castsi256_ps(a.n));
#else
  return *((simde__m256*) &a);
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m256d
simde_mm256_ceil_pd (simde__m256d a) {
  simde__m256d r;

#if defined(SIMDE_AVX_NATIVE)
  r.n = _mm256_ceil_pd(a.n);
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.f64) / sizeof(r.f64[0])) ; i++) {
    r.f64[i] = ceil(a.f64[i]);
  }
#endif

  return r;
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m256
simde_mm256_ceil_ps (simde__m256 a) {
  simde__m256 r;

#if defined(SIMDE_AVX_NATIVE)
  r.n = _mm256_ceil_ps(a.n);
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.f32) / sizeof(r.f32[0])) ; i++) {
    r.f32[i] = ceilf(a.f32[i]);
  }
#endif

  return r;
}

/* This implementation does not support signaling NaNs (yet?) */
SIMDE__FUNCTION_ATTRIBUTES
simde__m128d
simde_mm_cmp_pd (simde__m128d a, simde__m128d b, const int imm8)
    HEDLEY_REQUIRE_MSG((imm8 & 31) == imm8, "imm8 must one of the SIMDE_CMP_* macros (values: [0, 31])") {
  simde__m128d r;

  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.f64) / sizeof(r.f64[0])) ; i++) {
    switch (imm8) {
      case SIMDE_CMP_EQ_OQ:
	r.u64[i] = (a.f64[i] == b.f64[i]) ? ~UINT64_C(0) : UINT64_C(0);
	break;
      case SIMDE_CMP_LT_OS:
	r.u64[i] = (a.f64[i] < b.f64[i]) ? ~UINT64_C(0) : UINT64_C(0);
	break;
      case SIMDE_CMP_LE_OS:
	r.u64[i] = (a.f64[i] <= b.f64[i]) ? ~UINT64_C(0) : UINT64_C(0);
	break;
      case SIMDE_CMP_UNORD_Q:
	r.u64[i] = (isnan(a.f64[i]) || isnan(b.f64[i])) ? ~UINT64_C(0) : UINT64_C(0);
	break;
      case SIMDE_CMP_NEQ_UQ:
	r.u64[i] = (a.f64[i] != b.f64[i]) ? ~UINT64_C(0) : UINT64_C(0);
	break;
      case SIMDE_CMP_NLT_US:
	r.u64[i] = (a.f64[i] >= b.f64[i]) ? ~UINT64_C(0) : UINT64_C(0);
	break;
      case SIMDE_CMP_NLE_US:
	r.u64[i] = (a.f64[i] > b.f64[i]) ? ~UINT64_C(0) : UINT64_C(0);
	break;
      case SIMDE_CMP_ORD_Q:
	r.u64[i] = (!isnan(a.f64[i]) && !isnan(b.f64[i])) ? ~UINT64_C(0) : UINT64_C(0);
	break;
      case SIMDE_CMP_EQ_UQ:
	r.u64[i] = (a.f64[i] == b.f64[i]) ? ~UINT64_C(0) : UINT64_C(0);
	break;
      case SIMDE_CMP_NGE_US:
	r.u64[i] = (a.f64[i] < b.f64[i]) ? ~UINT64_C(0) : UINT64_C(0);
	break;
      case SIMDE_CMP_NGT_US:
	r.u64[i] = (a.f64[i] <= b.f64[i]) ? ~UINT64_C(0) : UINT64_C(0);
	break;
      case SIMDE_CMP_FALSE_OQ:
	r.u64[i] = UINT64_C(0);
	break;
      case SIMDE_CMP_NEQ_OQ:
	r.u64[i] = (a.f64[i] != b.f64[i]) ? ~UINT64_C(0) : UINT64_C(0);
	break;
      case SIMDE_CMP_GE_OS:
	r.u64[i] = (a.f64[i] >= b.f64[i]) ? ~UINT64_C(0) : UINT64_C(0);
	break;
      case SIMDE_CMP_GT_OS:
	r.u64[i] = (a.f64[i] > b.f64[i]) ? ~UINT64_C(0) : UINT64_C(0);
	break;
      case SIMDE_CMP_TRUE_UQ:
	r.u64[i] = ~UINT64_C(0);
	break;
      case SIMDE_CMP_EQ_OS:
	r.u64[i] = (a.f64[i] == b.f64[i]) ? ~UINT64_C(0) : UINT64_C(0);
	break;
      case SIMDE_CMP_LT_OQ:
	r.u64[i] = (a.f64[i] < b.f64[i]) ? ~UINT64_C(0) : UINT64_C(0);
	break;
      case SIMDE_CMP_LE_OQ:
	r.u64[i] = (a.f64[i] <= b.f64[i]) ? ~UINT64_C(0) : UINT64_C(0);
	break;
      case SIMDE_CMP_UNORD_S:
	r.u64[i] = (isnan(a.f64[i]) || isnan(b.f64[i])) ? ~UINT64_C(0) : UINT64_C(0);
	break;
      case SIMDE_CMP_NEQ_US:
	r.u64[i] = (a.f64[i] != b.f64[i]) ? ~UINT64_C(0) : UINT64_C(0);
	break;
      case SIMDE_CMP_NLT_UQ:
	r.u64[i] = (a.f64[i] >= b.f64[i]) ? ~UINT64_C(0) : UINT64_C(0);
	break;
      case SIMDE_CMP_NLE_UQ:
	r.u64[i] = (a.f64[i] > b.f64[i]) ? ~UINT64_C(0) : UINT64_C(0);
	break;
      case SIMDE_CMP_ORD_S:
	r.u64[i] = (isnan(a.f64[i]) || isnan(b.f64[i])) ? UINT64_C(0) : ~UINT64_C(0);
	break;
      case SIMDE_CMP_EQ_US:
	r.u64[i] = (a.f64[i] == b.f64[i]) ? ~UINT64_C(0) : UINT64_C(0);
	break;
      case SIMDE_CMP_NGE_UQ:
	r.u64[i] = (a.f64[i] < b.f64[i]) ? ~UINT64_C(0) : UINT64_C(0);
	break;
      case SIMDE_CMP_NGT_UQ:
	r.u64[i] = (a.f64[i] <= b.f64[i]) ? ~UINT64_C(0) : UINT64_C(0);
	break;
      case SIMDE_CMP_FALSE_OS:
	r.u64[i] = UINT64_C(0);
	break;
      case SIMDE_CMP_NEQ_OS:
	r.u64[i] = (a.f64[i] != b.f64[i]) ? ~UINT64_C(0) : UINT64_C(0);
	break;
      case SIMDE_CMP_GE_OQ:
	r.u64[i] = (a.f64[i] >= b.f64[i]) ? ~UINT64_C(0) : UINT64_C(0);
	break;
      case SIMDE_CMP_GT_OQ:
	r.u64[i] = (a.f64[i] > b.f64[i]) ? ~UINT64_C(0) : UINT64_C(0);
	break;
      case SIMDE_CMP_TRUE_US:
	r.u64[i] = ~UINT64_C(0);
	break;
    }
  }

  return r;
}
#if defined(SIMDE_AVX_NATIVE)
#  define simde_mm_cmp_pd(a, b, imm8) SIMDE__M128D_C(_mm_cmp_pd(a.n, b.n, imm8))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m256d
simde_mm256_cvtepi32_pd (simde__m128i a) {
  simde__m256d r;

#if defined(SIMDE_AVX_NATIVE)
  r.n = _mm256_cvtepi32_pd(a.n);
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.f64) / sizeof(r.f64[0])) ; i++) {
    r.f64[i] = (simde_float64) a.i32[i];
  }
#endif

  return r;
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m256
simde_mm256_cvtepi32_ps (simde__m256i a) {
  simde__m256 r;

#if defined(SIMDE_AVX_NATIVE)
  r.n = _mm256_cvtepi32_ps(a.n);
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.f32) / sizeof(r.f32[0])) ; i++) {
    r.f32[i] = (simde_float32) a.i32[i];
  }
#endif

  return r;
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m128i
simde_mm256_cvtpd_epi32 (simde__m256d a) {
  simde__m128i r;

#if defined(SIMDE_AVX_NATIVE)
  r.n = _mm256_cvtpd_epi32(a.n);
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(a.f64) / sizeof(a.f64[0])) ; i++) {
    r.i32[i] = (int32_t) round(a.f64[i]);
  }
#endif

  return r;
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m128
simde_mm256_cvtpd_ps (simde__m256d a) {
  simde__m128 r;

#if defined(SIMDE_AVX_NATIVE)
  r.n = _mm256_cvtpd_ps(a.n);
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.f32) / sizeof(r.f32[0])) ; i++) {
    r.f32[i] = (simde_float32) a.f64[i];
  }
#endif

  return r;
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_cvtps_epi32 (simde__m256 a) {
  simde__m256i r;

#if defined(SIMDE_AVX_NATIVE)
  r.n = _mm256_cvtps_epi32(a.n);
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(a.f32) / sizeof(a.f32[0])) ; i++) {
    r.i32[i] = (int32_t) roundf(a.f32[i]);
  }
#endif

  return r;
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m256d
simde_mm256_cvtps_pd (simde__m128 a) {
  simde__m256d r;

#if defined(SIMDE_AVX_NATIVE)
  r.n = _mm256_cvtps_pd(a.n);
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(a.f32) / sizeof(a.f32[0])) ; i++) {
    r.f64[i] = a.f32[i];
  }
#endif

  return r;
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m128i
simde_mm256_cvttpd_epi32 (simde__m256d a) {
  simde__m128i r;

#if defined(SIMDE_AVX_NATIVE)
  r.n = _mm256_cvttpd_epi32(a.n);
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(a.f64) / sizeof(a.f64[0])) ; i++) {
    r.i32[i] = (int32_t) trunc(a.f64[i]);
  }
#endif

  return r;
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_cvttps_epi32 (simde__m256 a) {
  simde__m256i r;

#if defined(SIMDE_AVX_NATIVE)
  r.n = _mm256_cvttps_epi32(a.n);
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(a.f32) / sizeof(a.f32[0])) ; i++) {
    r.i32[i] = (int32_t) trunc(a.f32[i]);
  }
#endif

  return r;
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m256
simde_mm256_div_ps (simde__m256 a, simde__m256 b) {
  simde__m256 r;

#if defined(SIMDE_AVX_NATIVE)
  r.n = _mm256_div_ps(a.n, b.n);
#elif defined(SIMDE_SSE_NATIVE)
  r.m128[0].n = _mm_div_ps(a.m128[0].n, b.m128[0].n);
  r.m128[1].n = _mm_div_ps(a.m128[1].n, b.m128[1].n);
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.f32) / sizeof(r.f32[0])) ; i++) {
    r.f32[i] = a.f32[i] / b.f32[i];
  }
#endif

  return r;
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m256d
simde_mm256_div_pd (simde__m256d a, simde__m256d b) {
  simde__m256d r;

#if defined(SIMDE_AVX_NATIVE)
  r.n = _mm256_div_pd(a.n, b.n);
#elif defined(SIMDE_SSE2_NATIVE)
  r.m128d[0].n = _mm_div_pd(a.m128d[0].n, b.m128d[0].n);
  r.m128d[1].n = _mm_div_pd(a.m128d[1].n, b.m128d[1].n);
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.f64) / sizeof(r.f64[0])) ; i++) {
    r.f64[i] = a.f64[i] / b.f64[i];
  }
#endif

  return r;
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m128d
simde_mm256_extractf128_pd (simde__m256d a, const int imm8)
    HEDLEY_REQUIRE_MSG((imm8 & 1) == imm8, "imm8 must be 0 or 1") {
  return a.m128d[imm8];
}
#if defined(SIMDE_AVX_NATIVE)
#  define simde_mm256_extractf128_pd(a, imm8) SIMDE__M128D_C(_mm256_extractf128_pd(a.n, imm8))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128
simde_mm256_extractf128_ps (simde__m256 a, const int imm8)
    HEDLEY_REQUIRE_MSG((imm8 & 1) == imm8, "imm8 must be 0 or 1") {
  return a.m128[imm8];
}
#if defined(SIMDE_AVX_NATIVE)
#  define simde_mm256_extractf128_ps(a, imm8) SIMDE__M128_C(_mm256_extractf128_ps(a.n, imm8))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128i
simde_mm256_extractf128_si256 (simde__m256i a, const int imm8)
    HEDLEY_REQUIRE_MSG((imm8 & 1) == imm8, "imm8 must be 0 or 1") {
  return a.m128i[imm8];
}
#if defined(SIMDE_AVX_NATIVE)
#  define simde_mm256_extractf128_si256(a, imm8) SIMDE__M128I_C(_mm256_extractf128_si256(a.n, imm8))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m256d
simde_mm256_floor_pd (simde__m256d a) {
  simde__m256d r;

#if defined(SIMDE_AVX_NATIVE)
  r.n = _mm256_floor_pd(a.n);
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.f64) / sizeof(r.f64[0])) ; i++) {
    r.f64[i] = floor(a.f64[i]);
  }
#endif

  return r;
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m256
simde_mm256_floor_ps (simde__m256 a) {
  simde__m256 r;

#if defined(SIMDE_AVX_NATIVE)
  r.n = _mm256_floor_ps(a.n);
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.f32) / sizeof(r.f32[0])) ; i++) {
    r.f32[i] = floorf(a.f32[i]);
  }
#endif

  return r;
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m256
simde_mm256_hadd_ps (simde__m256 a, simde__m256 b) {
  simde__m256 r;

#if defined(SIMDE_AVX_NATIVE)
  r.n = _mm256_hadd_ps(a.n, b.n);
#else
  r.f32[0] = a.f32[0] + a.f32[1];
  r.f32[1] = a.f32[2] + a.f32[3];
  r.f32[2] = b.f32[0] + b.f32[1];
  r.f32[3] = b.f32[2] + b.f32[3];
  r.f32[4] = a.f32[4] + a.f32[5];
  r.f32[5] = a.f32[6] + a.f32[7];
  r.f32[6] = b.f32[4] + b.f32[5];
  r.f32[7] = b.f32[6] + b.f32[7];
#endif

  return r;
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m256d
simde_mm256_hadd_pd (simde__m256d a, simde__m256d b) {
  simde__m256d r;

#if defined(SIMDE_AVX_NATIVE)
  r.n = _mm256_hadd_pd(a.n, b.n);
#else
  r.f64[0] = a.f64[0] + a.f64[1];
  r.f64[1] = b.f64[0] + b.f64[1];
  r.f64[2] = a.f64[2] + a.f64[3];
  r.f64[3] = b.f64[2] + b.f64[3];
#endif

  return r;
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m256
simde_mm256_hsub_ps (simde__m256 a, simde__m256 b) {
  simde__m256 r;

#if defined(SIMDE_AVX_NATIVE)
  r.n = _mm256_hsub_ps(a.n, b.n);
#else
  r.f32[0] = a.f32[0] - a.f32[1];
  r.f32[1] = a.f32[2] - a.f32[3];
  r.f32[2] = b.f32[0] - b.f32[1];
  r.f32[3] = b.f32[2] - b.f32[3];
  r.f32[4] = a.f32[4] - a.f32[5];
  r.f32[5] = a.f32[6] - a.f32[7];
  r.f32[6] = b.f32[4] - b.f32[5];
  r.f32[7] = b.f32[6] - b.f32[7];
#endif

  return r;
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m256d
simde_mm256_hsub_pd (simde__m256d a, simde__m256d b) {
  simde__m256d r;

#if defined(SIMDE_AVX_NATIVE)
  r.n = _mm256_hsub_pd(a.n, b.n);
#else
  r.f64[0] = a.f64[0] - a.f64[1];
  r.f64[1] = b.f64[0] - b.f64[1];
  r.f64[2] = a.f64[2] - a.f64[3];
  r.f64[3] = b.f64[2] - b.f64[3];
#endif

  return r;
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_insert_epi8 (simde__m256i a, int8_t i, const int index)
    HEDLEY_REQUIRE_MSG((index & 0xff) == index, "index must be in [0, 31]") {
  a.i8[index] = i;
  return a;
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_insert_epi16 (simde__m256i a, int16_t i, const int index)
    HEDLEY_REQUIRE_MSG((index & 0xff) == index, "index must be in [0, 15]")  {
  a.i16[index] = i;
  return a;
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_insert_epi32 (simde__m256i a, int32_t i, const int index)
    HEDLEY_REQUIRE_MSG((index & 0xff) == index, "index must be in [0, 7]")  {
  a.i32[index] = i;
  return a;
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_insert_epi64 (simde__m256i a, int64_t i, const int index)
    HEDLEY_REQUIRE_MSG((index & 0xff) == index, "index must be in [0, 3]")  {
  a.i64[index] = i;
  return a;
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m256d simde_mm256_insertf128_pd(simde__m256d a, simde__m128d b, int imm8)
    HEDLEY_REQUIRE_MSG((imm8 & 0xff) == imm8, "imm8 must be in [0, 3]") {
  a.m128d[imm8] = b;
  return a;
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m256 simde_mm256_insertf128_ps(simde__m256 a, simde__m128 b, int imm8)
    HEDLEY_REQUIRE_MSG((imm8 & 0xff) == imm8, "imm8 must be in [0, 7]") {
  a.m128[imm8] = b;
  return a;
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m256i simde_mm256_insertf128_si256(simde__m256i a, simde__m128i b, int imm8)
    HEDLEY_REQUIRE_MSG((imm8 & 0xff) == imm8, "imm8 must be in [0, 7]") {
  a.m128i[imm8] = b;
  return a;
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m256
simde_mm256_dp_ps (simde__m256 a, simde__m256 b, const int imm8) {
  simde__m256 r;
  simde_float32 sum1 = SIMDE_FLOAT32_C(0.0);
  simde_float32 sum2 = SIMDE_FLOAT32_C(0.0);

  SIMDE__VECTORIZE_REDUCTION(+:sum1)
  for (size_t i = 0 ; i < 4 ; i++) {
    sum1 += (imm8 & (16 << i)) ? (a.f32[i + 4] * b.f32[i + 4]) : SIMDE_FLOAT32_C(0.0);
  }
  SIMDE__VECTORIZE_REDUCTION(+:sum2)
  for (size_t i = 0 ; i < 4 ; i++) {
    sum2 += (imm8 & (16 << i)) ? (a.f32[  i  ] * b.f32[  i  ]) : SIMDE_FLOAT32_C(0.0);
  }

  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < 4 ; i++) {
    r.f32[i + 4] = (imm8 & (8 >> i)) ? sum1 : SIMDE_FLOAT32_C(0.0);
    r.f32[  i  ] = (imm8 & (8 >> i)) ? sum2 : SIMDE_FLOAT32_C(0.0);
  }

  return r;
}
#if defined(SIMDE_AVX_NATIVE)
#  define simde_mm256_dp_ps(a, b, imm8) SIMDE__M256_C(_mm256_dp_ps(a.n, b.n, imm8))
#endif

SIMDE__FUNCTION_ATTRIBUTES
int32_t
simde_mm256_extract_epi32 (simde__m256i a, const int index) {
  return a.i32[index];
}

SIMDE__FUNCTION_ATTRIBUTES
int64_t
simde_mm256_extract_epi64 (simde__m256i a, const int index) {
  return a.i64[index];
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_lddqu_si256 (simde__m256i const * a) {
  simde__m256i r;

#if defined(SIMDE_AVX_NATIVE)
  r.n = _mm256_loadu_si256(&(a->n));
#else
  memcpy(&r, a, sizeof(r));
#endif

  return r;
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m256d
simde_mm256_load_pd (const double a[HEDLEY_ARRAY_PARAM(4)]) {
  simde__m256d r;

  simde_assert_aligned(32, a);

#if defined(SIMDE_AVX_NATIVE)
  r.n = _mm256_load_pd(a);
#else
  r = *SIMDE_CAST_ALIGN(32, simde__m256d*, a);
#endif

  return r;
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m256
simde_mm256_load_ps (const float a[HEDLEY_ARRAY_PARAM(8)]) {
  simde__m256 r;

  simde_assert_aligned(32, a);

#if defined(SIMDE_AVX_NATIVE)
  r.n = _mm256_load_ps(a);
#else
  r = *SIMDE_CAST_ALIGN(32, simde__m256*, a);
#endif

  return r;
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_load_si256 (simde__m256i const * mem_addr) {
  simde__m256i r;

  simde_assert_aligned(32, mem_addr);

#if defined(SIMDE_AVX_NATIVE)
  r.n = _mm256_load_si256((__m256i*) mem_addr);
#else
  r = *mem_addr;
#endif

  return r;
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m256d
simde_mm256_loadu_pd (const double a[HEDLEY_ARRAY_PARAM(4)]) {
  simde__m256d r;

#if defined(SIMDE_AVX_NATIVE)
  r.n = _mm256_loadu_pd(a);
#else
  memcpy(&r, a, sizeof(r));
#endif

  return r;
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m256
simde_mm256_loadu_ps (const float a[HEDLEY_ARRAY_PARAM(8)]) {
  simde__m256 r;

#if defined(SIMDE_AVX_NATIVE)
  r.n = _mm256_loadu_ps(a);
#else
  memcpy(&r, a, sizeof(r));
#endif

  return r;
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_loadu_si256 (simde__m256i const * a) {
  simde__m256i r;

#if defined(SIMDE_AVX_NATIVE)
  r.n = _mm256_loadu_si256(&(a->n));
#else
  memcpy(&(r.i64), &(a->i64), sizeof(r.i64));
#endif

  return r;
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m256
simde_mm256_loadu2_m128 (const float hiaddr[HEDLEY_ARRAY_PARAM(4)], const float loaddr[HEDLEY_ARRAY_PARAM(4)]) {
  return
    simde_mm256_insertf128_ps(simde_mm256_castps128_ps256(simde_mm_loadu_ps(loaddr)),
			      simde_mm_loadu_ps(hiaddr), 1);
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m256d
simde_mm256_loadu2_m128d (const double hiaddr[HEDLEY_ARRAY_PARAM(2)], const double loaddr[HEDLEY_ARRAY_PARAM(2)]) {
  return
    simde_mm256_insertf128_pd(simde_mm256_castpd128_pd256(simde_mm_loadu_pd(loaddr)),
			      simde_mm_loadu_pd(hiaddr), 1);
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_loadu2_m128i (const simde__m128i* hiaddr, const simde__m128i* loaddr) {
  return
    simde_mm256_insertf128_si256(simde_mm256_castsi128_si256(simde_mm_loadu_si128(loaddr)),
				 simde_mm_loadu_si128(hiaddr), 1);
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m128d
simde_mm_maskload_pd (const simde_float64 mem_addr[HEDLEY_ARRAY_PARAM(4)], simde__m128i mask) {
  simde__m128d r;

#if defined(SIMDE_AVX_NATIVE)
  r.n = _mm_maskload_pd(mem_addr, mask.n);
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.f64) / sizeof(r.f64[0])) ; i++) {
    /* TODO: it may be better to just do something along the lines of
       (r.f64[i] = (mask.u64[i] & (1 << 63)) ? a.f64[i] : 0.0);
       Which compilers may bo more likely to compile to a masked op. */
    r.u64[i] = ((uint64_t*) mem_addr)[i] & (mask.i64[i] >> ((sizeof(mask.i64[0]) * CHAR_BIT) - 1));
  }
#endif

  return r;
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m256d
simde_mm256_maskload_pd (const simde_float64 mem_addr[HEDLEY_ARRAY_PARAM(4)], simde__m256i mask) {
  simde__m256d r;

#if defined(SIMDE_AVX_NATIVE)
  r.n = _mm256_maskload_pd(mem_addr, mask.n);
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.f64) / sizeof(r.f64[0])) ; i++) {
    r.u64[i] = ((uint64_t*) mem_addr)[i] & (mask.i64[i] >> ((sizeof(mask.i64[0]) * CHAR_BIT) - 1));
  }
#endif

  return r;
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m128
simde_mm_maskload_ps (const simde_float32 mem_addr[HEDLEY_ARRAY_PARAM(4)], simde__m128i mask) {
  simde__m128 r;

#if defined(SIMDE_AVX_NATIVE)
  r.n = _mm_maskload_ps(mem_addr, mask.n);
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.f32) / sizeof(r.f32[0])) ; i++) {
    r.u32[i] = ((uint32_t*) mem_addr)[i] & (mask.i32[i] >> ((sizeof(mask.i32[0]) * CHAR_BIT) - 1));
  }
#endif

  return r;
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m256
simde_mm256_maskload_ps (const simde_float32 mem_addr[HEDLEY_ARRAY_PARAM(4)], simde__m256i mask) {
  simde__m256 r;

#if defined(SIMDE_AVX_NATIVE)
  r.n = _mm256_maskload_ps(mem_addr, mask.n);
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.f32) / sizeof(r.f32[0])) ; i++) {
    r.u32[i] = ((uint32_t*) mem_addr)[i] & (mask.i32[i] >> ((sizeof(mask.i32[0]) * CHAR_BIT) - 1));
  }
#endif

  return r;
}

SIMDE__FUNCTION_ATTRIBUTES
void
simde_mm_maskstore_pd (simde_float64 mem_addr[HEDLEY_ARRAY_PARAM(2)], simde__m128i mask, simde__m128d a) {
#if defined(SIMDE_AVX_NATIVE)
  _mm_maskstore_pd(mem_addr, mask.n, a.n);
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < 2 ; i++) {
    if (mask.i64[i] >> 63)
      mem_addr[i] = a.f64[i];
  }
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
void
simde_mm256_maskstore_pd (simde_float64 mem_addr[HEDLEY_ARRAY_PARAM(4)], simde__m256i mask, simde__m256d a) {
#if defined(SIMDE_AVX_NATIVE)
  _mm256_maskstore_pd(mem_addr, mask.n, a.n);
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < 4 ; i++) {
    if (mask.i64[i] >> 63)
      mem_addr[i] = a.f64[i];
  }
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
void
simde_mm_maskstore_ps (simde_float32 mem_addr[HEDLEY_ARRAY_PARAM(4)], simde__m128i mask, simde__m128 a) {
#if defined(SIMDE_AVX_NATIVE)
  _mm_maskstore_ps(mem_addr, mask.n, a.n);
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < 4 ; i++) {
    if (mask.i32[i] >> 31)
      mem_addr[i] = a.f32[i];
  }
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
void
simde_mm256_maskstore_ps (simde_float32 mem_addr[HEDLEY_ARRAY_PARAM(8)], simde__m256i mask, simde__m256 a) {
#if defined(SIMDE_AVX_NATIVE)
  _mm256_maskstore_ps(mem_addr, mask.n, a.n);
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < 8 ; i++) {
    if (mask.i32[i] >> 31)
      mem_addr[i] = a.f32[i];
  }
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m256
simde_mm256_min_ps (simde__m256 a, simde__m256 b) {
  simde__m256 r;

#if defined(SIMDE_AVX_NATIVE)
  r.n = _mm256_min_ps(a.n,b.n);
#elif defined(SIMDE_SSE_NATIVE)
  r.m128[0].n = _mm_min_ps(a.m128[0].n, b.m128[0].n);
  r.m128[1].n = _mm_min_ps(a.m128[1].n, b.m128[1].n);
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.f32) / sizeof(r.f32[0])) ; i++) {
    r.f32[i] = (a.f32[i] < b.f32[i]) ? a.f32[i] : b.f32[i];
  }
#endif

  return r;
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m256d
simde_mm256_min_pd (simde__m256d a, simde__m256d b) {
  simde__m256d r;

#if defined(SIMDE_AVX_NATIVE)
  r.n = _mm256_min_pd(a.n,b.n);
#elif defined(SIMDE_SSE_NATIVE)
  r.m128d[0].n = _mm_min_pd(a.m128d[0].n, b.m128d[0].n);
  r.m128d[1].n = _mm_min_pd(a.m128d[1].n, b.m128d[1].n);
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.f64) / sizeof(r.f64[0])) ; i++) {
    r.f64[i] = (a.f64[i] < b.f64[i]) ? a.f64[i] : b.f64[i];
  }
#endif

  return r;
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m256
simde_mm256_max_ps (simde__m256 a, simde__m256 b) {
  simde__m256 r;

#if defined(SIMDE_AVX_NATIVE)
  r.n = _mm256_max_ps(a.n,b.n);
#elif defined(SIMDE_SSE_NATIVE)
  r.m128[0].n = _mm_max_ps(a.m128[0].n, b.m128[0].n);
  r.m128[1].n = _mm_max_ps(a.m128[1].n, b.m128[1].n);
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.f32) / sizeof(r.f32[0])) ; i++) {
    r.f32[i] = (a.f32[i] > b.f32[i]) ? a.f32[i] : b.f32[i];
  }
#endif

  return r;
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m256d
simde_mm256_max_pd (simde__m256d a, simde__m256d b) {
  simde__m256d r;

#if defined(SIMDE_AVX_NATIVE)
  r.n = _mm256_max_pd(a.n,b.n);
#elif defined(SIMDE_SSE_NATIVE)
  r.m128d[0].n = _mm_max_pd(a.m128d[0].n, b.m128d[0].n);
  r.m128d[1].n = _mm_max_pd(a.m128d[1].n, b.m128d[1].n);
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.f64) / sizeof(r.f64[0])) ; i++) {
    r.f64[i] = (a.f64[i] > b.f64[i]) ? a.f64[i] : b.f64[i];
  }
#endif

  return r;
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m256d
simde_mm256_movedup_pd (simde__m256d a) {
  simde__m256d r;

#if defined(SIMDE_AVX_NATIVE)
  r.n = _mm256_movedup_pd(a.n);
#elif defined(SIMDE__SHUFFLE_VECTOR)
  r.f64 = SIMDE__SHUFFLE_VECTOR(64, 32, a.f64, a.f64, 0, 0, 2, 2);
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.f64) / sizeof(r.f64[0])) ; i += 2) {
    r.f64[i] = r.f64[i + 1] = a.f64[i];
  }
#endif

  return r;
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m256
simde_mm256_movehdup_ps (simde__m256 a) {
  simde__m256 r;

#if defined(SIMDE_AVX_NATIVE)
  r.n = _mm256_movehdup_ps(a.n);
#elif defined(SIMDE__SHUFFLE_VECTOR)
  r.f32 = SIMDE__SHUFFLE_VECTOR(32, 32, a.f32, a.f32, 1, 1, 3, 3, 5, 5, 7, 7);
#else
  SIMDE__VECTORIZE
  for (size_t i = 1 ; i < (sizeof(r.f32) / sizeof(r.f32[0])) ; i += 2) {
    r.f32[i - 1] = r.f32[i] = a.f32[i];
  }
#endif

  return r;
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m256
simde_mm256_moveldup_ps (simde__m256 a) {
  simde__m256 r;

#if defined(SIMDE_AVX_NATIVE) && 0
  r.n = _mm256_moveldup_ps(a.n);
#elif defined(SIMDE__SHUFFLE_VECTOR)
  r.f32 = SIMDE__SHUFFLE_VECTOR(32, 32, a.f32, a.f32, 0, 0, 2, 2, 4, 4, 6, 6);
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.f32) / sizeof(r.f32[0])) ; i += 2) {
    r.f32[i] = r.f32[i + 1] = a.f32[i];
  }
#endif

  return r;
}

SIMDE__FUNCTION_ATTRIBUTES
int
simde_mm256_movemask_ps (simde__m256 a) {
  int r = 0;

#if defined(SIMDE_AVX_NATIVE)
  r = _mm256_movemask_ps(a.n);
#else
  SIMDE__VECTORIZE_REDUCTION(|:r)
  for (size_t i = 0 ; i < (sizeof(a.f32) / sizeof(a.f32[0])) ; i++) {
    r |= (a.u32[i] >> 31) << i;
  }
#endif

  return r;
}

SIMDE__FUNCTION_ATTRIBUTES
int
simde_mm256_movemask_pd (simde__m256d a) {
  int r = 0;

#if defined(SIMDE_AVX_NATIVE)
  r = _mm256_movemask_pd(a.n);
#else
  SIMDE__VECTORIZE_REDUCTION(|:r)
  for (size_t i = 0 ; i < (sizeof(a.f64) / sizeof(a.f64[0])) ; i++) {
    r |= (a.u64[i] >> 63) << i;
  }
#endif

  return r;
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m256
simde_mm256_mul_ps (simde__m256 a, simde__m256 b) {
  simde__m256 r;

#if defined(SIMDE_AVX_NATIVE)
  r.n = _mm256_mul_ps(a.n,b.n);
#elif defined(SIMDE_SSE_NATIVE)
  r.m128[0].n = _mm_mul_ps(a.m128[0].n, b.m128[0].n);
  r.m128[1].n = _mm_mul_ps(a.m128[1].n, b.m128[1].n);
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.f32) / sizeof(r.f32[0])) ; i++) {
    r.f32[i] = a.f32[i] * b.f32[i];
  }
#endif

  return r;
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m256d
simde_mm256_mul_pd (simde__m256d a, simde__m256d b) {
  simde__m256d r;

#if defined(SIMDE_AVX_NATIVE)
  r.n = _mm256_mul_pd(a.n,b.n);
#elif defined(SIMDE_SSE_NATIVE)
  r.m128d[0].n = _mm_mul_pd(a.m128d[0].n, b.m128d[0].n);
  r.m128d[1].n = _mm_mul_pd(a.m128d[1].n, b.m128d[1].n);
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.f64) / sizeof(r.f64[0])) ; i++) {
    r.f64[i] = a.f64[i] * b.f64[i];
  }
#endif

  return r;
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m256
simde_mm256_or_ps (simde__m256 a, simde__m256 b) {
  simde__m256 r;

#if defined(SIMDE_AVX_NATIVE)
  r.n = _mm256_or_ps(a.n,b.n);
#elif defined(SIMDE_SSE_NATIVE)
  r.m128[0].n = _mm_or_ps(a.m128[0].n, b.m128[0].n);
  r.m128[1].n = _mm_or_ps(a.m128[1].n, b.m128[1].n);
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.u32) / sizeof(r.u32[0])) ; i++) {
    r.u32[i] = a.u32[i] | b.u32[i];
  }
#endif

  return r;
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m256d
simde_mm256_or_pd (simde__m256d a, simde__m256d b) {
  simde__m256d r;

#if defined(SIMDE_AVX_NATIVE)
  r.n = _mm256_or_pd(a.n,b.n);
#elif defined(SIMDE_SSE_NATIVE)
  r.m128d[0].n = _mm_or_pd(a.m128d[0].n, b.m128d[0].n);
  r.m128d[1].n = _mm_or_pd(a.m128d[1].n, b.m128d[1].n);
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.u64) / sizeof(r.u64[0])) ; i++) {
    r.u64[i] = a.u64[i] | b.u64[i];
  }
#endif

  return r;
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m256
simde_mm256_permute_ps (simde__m256 a, const int imm8) {
  simde__m256 r;

  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.f32) / sizeof(r.f32[0])) ; i++) {
    r.f32[i] = a.m128[i >> 2].f32[(imm8 >> ((i << 1) & 7)) & 3];
  }

  return r;
}
#if defined(SIMDE_AVX_NATIVE)
#  define simde_mm256_permute_ps(a, imm8) SIMDE__M256_C(_mm256_permute_ps(a.n, imm8))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m256d
simde_mm256_permute_pd (simde__m256d a, const int imm8) {
  simde__m256d r;

  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.f64) / sizeof(r.f64[0])) ; i++) {
    r.f64[i] = a.f64[((imm8 >> i) & 1) + (i & 2)];
  }

  return r;
}
#if defined(SIMDE_AVX_NATIVE)
#  define simde_mm256_permute_pd(a, imm8) SIMDE__M256D_C(_mm256_permute_pd(a.n, imm8))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128
simde_mm_permute_ps (simde__m128 a, const int imm8) {
  simde__m128 r;

  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.f32) / sizeof(r.f32[0])) ; i++) {
    r.f32[i] = a.f32[(imm8 >> ((i << 1) & 7)) & 3];
  }

  return r;
}
#if defined(SIMDE_AVX_NATIVE)
#  define simde_mm_permute_ps(a, imm8) SIMDE__M128_C(_mm_permute_ps(a.n, imm8))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128d
simde_mm_permute_pd (simde__m128d a, const int imm8) {
  simde__m128d r;

  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.f64) / sizeof(r.f64[0])) ; i++) {
    r.f64[i] = a.f64[((imm8 >> i) & 1) + (i & 2)];
  }

  return r;
}
#if defined(SIMDE_AVX_NATIVE)
#  define simde_mm_permute_pd(a, imm8) SIMDE__M128D_C(_mm_permute_pd(a.n, imm8))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m256
simde_mm256_rcp_ps (simde__m256 a) {
  simde__m256 r;

#if defined(SIMDE_AVX_NATIVE)
  r.n = _mm256_rcp_ps(a.n);
#elif 1
  for (size_t i = 0 ; i < (sizeof(r.m128) / sizeof(r.m128[0])) ; i++) {
    r.m128[i] = simde_mm_rcp_ps(a.m128[i]);
  }
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.f32) / sizeof(r.f32[0])) ; i++) {
    r.f32[i] = 1.0f / a.f32[i];
  }
#endif

  return r;
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m256
simde_mm256_round_ps (simde__m256 a, const int rounding) {
  simde__m256 r;

  for (size_t i = 0 ; i < (sizeof(r.f32) / sizeof(r.f32[0])) ; i++) {
    switch (rounding & ~SIMDE_MM_FROUND_NO_EXC) {
      case SIMDE_MM_FROUND_TO_NEAREST_INT:
        r.f32[i] = nearbyintf(a.f32[i]);
        break;
      case SIMDE_MM_FROUND_TO_NEG_INF:
        r.f32[i] = floorf(a.f32[i]);
        break;
      case SIMDE_MM_FROUND_TO_POS_INF:
        r.f32[i] = ceilf(a.f32[i]);
        break;
      case SIMDE_MM_FROUND_TO_ZERO:
        r.f32[i] = truncf(a.f32[i]);
        break;
    }
  }

  return r;
}
#if defined(SIMDE_AVX_NATIVE)
#  define simde_mm256_round_ps(a, rounding) SIMDE__M256_C(_mm256_round_ps(a.n, rounding))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m256d
simde_mm256_round_pd (simde__m256d a, const int rounding) {
  simde__m256d r;

  for (size_t i = 0 ; i < (sizeof(r.f64) / sizeof(r.f64[0])) ; i++) {
    switch (rounding & ~SIMDE_MM_FROUND_NO_EXC) {
      case SIMDE_MM_FROUND_TO_NEAREST_INT:
        r.f64[i] = nearbyint(a.f64[i]);
        break;
      case SIMDE_MM_FROUND_TO_NEG_INF:
        r.f64[i] = floor(a.f64[i]);
        break;
      case SIMDE_MM_FROUND_TO_POS_INF:
        r.f64[i] = ceil(a.f64[i]);
        break;
      case SIMDE_MM_FROUND_TO_ZERO:
        r.f64[i] = trunc(a.f64[i]);
        break;
    }
  }

  return r;
}
#if defined(SIMDE_AVX_NATIVE)
#  define simde_mm256_round_pd(a, rounding) SIMDE__M256D_C(_mm256_round_pd(a.n, rounding))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m256
simde_mm256_rsqrt_ps (simde__m256 a) {
  simde__m256 r;

#if defined(SIMDE_AVX_NATIVE)
  r.n = _mm256_rsqrt_ps(a.n);
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.f32) / sizeof(r.f32[0])) ; i++) {
    r.f32[i] = 1.0f / sqrtf(a.f32[i]);
  }
#endif

  return r;
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_setr_epi8 (
    int8_t e31, int8_t e30, int8_t e29, int8_t e28, int8_t e27, int8_t e26, int8_t e25, int8_t e24,
    int8_t e23, int8_t e22, int8_t e21, int8_t e20, int8_t e19, int8_t e18, int8_t e17, int8_t e16,
    int8_t e15, int8_t e14, int8_t e13, int8_t e12, int8_t e11, int8_t e10, int8_t  e9, int8_t  e8,
    int8_t  e7, int8_t  e6, int8_t  e5, int8_t  e4, int8_t  e3, int8_t  e2, int8_t  e1, int8_t  e0) {
  simde__m256i r;

#if defined(SIMDE_AVX_NATIVE)
  r.n = _mm256_setr_epi8(
      e31, e30, e29, e28, e27, e26, e25, e24,
      e23, e22, e21, e20, e19, e18, e17, e16,
      e15, e14, e13, e12, e11, e10,  e9,  e8,
       e7,  e6,  e5,  e4,  e3,  e2,  e1,  e0);
#else
  r = simde_mm256_set_epi8(
       e0,  e1,  e2,  e3,  e4,  e5,  e6,  e7,
       e8,  e9, e10, e11, e12, e13, e14, e15,
      e16, e17, e18, e19, e20, e21, e22, e23,
      e24, e25, e26, e27, e28, e29, e30, e31);
#endif

  return r;
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_setr_epi16 (
    int16_t e15, int16_t e14, int16_t e13, int16_t e12, int16_t e11, int16_t e10, int16_t  e9, int16_t  e8,
    int16_t  e7, int16_t  e6, int16_t  e5, int16_t  e4, int16_t  e3, int16_t  e2, int16_t  e1, int16_t  e0) {
  simde__m256i r;

#if defined(SIMDE_AVX_NATIVE)
  r.n = _mm256_setr_epi16(
      e15, e14, e13, e12, e11, e10,  e9,  e8,
       e7,  e6,  e5,  e4,  e3,  e2,  e1,  e0);
#else
  r = simde_mm256_set_epi16(
       e0,  e1,  e2,  e3,  e4,  e5,  e6,  e7,
       e8,  e9, e10, e11, e12, e13, e14, e15);
#endif

  return r;
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_setr_epi32 (
    int32_t  e7, int32_t  e6, int32_t  e5, int32_t  e4, int32_t  e3, int32_t  e2, int32_t  e1, int32_t  e0) {
  simde__m256i r;

#if defined(SIMDE_AVX_NATIVE)
  r.n = _mm256_setr_epi32(
       e7,  e6,  e5,  e4,  e3,  e2,  e1,  e0);
#else
  r = simde_mm256_set_epi32(
       e0,  e1,  e2,  e3,  e4,  e5,  e6,  e7);
#endif

  return r;
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_setr_epi64 (int64_t  e3, int64_t  e2, int64_t  e1, int64_t  e0) {
  simde__m256i r;

#if defined(SIMDE_AVX_NATIVE)
  r.n = _mm256_setr_epi64x(e3, e2, e1, e0);
#else
  r = simde_mm256_set_epi64x(e0, e1, e2, e3);
#endif

  return r;
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m256
simde_mm256_setr_ps (
    simde_float32  e7, simde_float32  e6, simde_float32  e5, simde_float32  e4,
    simde_float32  e3, simde_float32  e2, simde_float32  e1, simde_float32  e0) {
  simde__m256 r;

#if defined(SIMDE_AVX_NATIVE)
  r.n = _mm256_setr_ps(
       e7,  e6,  e5,  e4,  e3,  e2,  e1,  e0);
#else
  r = simde_mm256_set_ps(
       e0,  e1,  e2,  e3,  e4,  e5,  e6,  e7);
#endif

  return r;
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m256d
simde_mm256_setr_pd (simde_float64  e3, simde_float64  e2, simde_float64  e1, simde_float64  e0) {
  simde__m256d r;

#if defined(SIMDE_AVX_NATIVE)
  r.n = _mm256_setr_pd(e3, e2, e1, e0);
#else
  r = simde_mm256_set_pd(e0, e1, e2, e3);
#endif

  return r;
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m256
simde_mm256_setr_m128 (simde__m128 lo, simde__m128 hi) {
  return simde_mm256_set_m128(hi, lo);
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m256d
simde_mm256_setr_m128d (simde__m128d lo, simde__m128d hi) {
  return simde_mm256_set_m128d(hi, lo);
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_setr_m128i (simde__m128i lo, simde__m128i hi) {
  return simde_mm256_set_m128i(hi, lo);
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m256
simde_mm256_sqrt_ps (simde__m256 a) {
  simde__m256 r;

#if defined(SIMDE_AVX_NATIVE)
  r.n = _mm256_sqrt_ps(a.n);
#elif defined(SIMDE_SSE_NATIVE)
  r.m128[0].n = _mm_sqrt_ps(a.m128[0].n);
  r.m128[1].n = _mm_sqrt_ps(a.m128[1].n);
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.f32) / sizeof(r.f32[0])) ; i++) {
    r.f32[i] = sqrtf(a.f32[i]);
  }
#endif

  return r;
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m256d
simde_mm256_sqrt_pd (simde__m256d a) {
  simde__m256d r;

#if defined(SIMDE_AVX_NATIVE)
  r.n = _mm256_sqrt_pd(a.n);
#elif defined(SIMDE_SSE2_NATIVE)
  r.m128d[0].n = _mm_sqrt_pd(a.m128d[0].n);
  r.m128d[1].n = _mm_sqrt_pd(a.m128d[1].n);
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.f64) / sizeof(r.f64[0])) ; i++) {
    r.f64[i] = sqrt(a.f64[i]);
  }
#endif

  return r;
}

SIMDE__FUNCTION_ATTRIBUTES
void
simde_mm256_store_ps (simde_float32 mem_addr[8], simde__m256 a) {
  simde_assert_aligned(32, mem_addr);

#if defined(SIMDE_AVX_NATIVE)
  _mm256_store_ps(mem_addr, a.n);
#else
  *SIMDE_CAST_ALIGN(32, simde__m256*, mem_addr) = a;
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
void
simde_mm256_store_pd (simde_float64 mem_addr[4], simde__m256d a) {
  simde_assert_aligned(32, mem_addr);

#if defined(SIMDE_AVX_NATIVE)
  _mm256_store_pd(mem_addr, a.n);
#else
  *SIMDE_CAST_ALIGN(32, simde__m256d*, mem_addr) =  a;
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
void
simde_mm256_store_si256 (simde__m256i* mem_addr, simde__m256i a) {
  simde_assert_aligned(32, mem_addr);

#if defined(SIMDE_AVX_NATIVE)
  _mm256_store_si256(&(mem_addr->n), a.n);
#else
  *mem_addr = a;
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
void
simde_mm256_storeu_ps (simde_float32 mem_addr[8], simde__m256 a) {
#if defined(SIMDE_AVX_NATIVE)
  _mm256_storeu_ps(mem_addr, a.n);
#else
  memcpy(mem_addr, &a, sizeof(a));
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
void
simde_mm256_storeu_pd (simde_float64 mem_addr[4], simde__m256d a) {
#if defined(SIMDE_AVX_NATIVE)
  _mm256_storeu_pd(mem_addr, a.n);
#else
  memcpy(mem_addr, &a, sizeof(a));
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
void
simde_mm256_storeu_si256 (simde__m256i* mem_addr, simde__m256i a) {
#if defined(SIMDE_AVX_NATIVE)
  _mm256_storeu_si256(&(mem_addr->n), a.n);
#else
  memcpy(mem_addr, &a, sizeof(a));
#endif
}

SIMDE__END_DECLS

#endif /* !defined(SIMDE__AVX_H) */
