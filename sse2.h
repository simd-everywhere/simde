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

#if !defined(SIMDE__SSE2_H)
#  if !defined(SIMDE__SSE2_H)
#    define SIMDE__SSE2_H
#  endif
#  include "sse.h"

#  if defined(SIMDE_SSE2_NATIVE)
#    undef SIMDE_SSE2_NATIVE
#  endif
#  if defined(SIMDE_SSE2_FORCE_NATIVE)
#    define SIMDE_SSE2_NATIVE
#  elif defined(__SSE2__) && (!defined(SIMDE_SSE2_NO_NATIVE) && !defined(SIMDE_NO_NATIVE))
#    define SIMDE_SSE2_NATIVE
#  endif

#  if defined(SIMDE_SSE2_NATIVE) && !defined(SIMDE_SSE_NATIVE)
#    if defined(SIMDE_SSE2_FORCE_NATIVE)
#      error Native SSE2 support requires native SSE support
#    else
#      warning Native SSE2 support requires native SSE support, disabling
#      undef SIMDE_SSE2_NATIVE
#    endif
#  endif

#  if defined(SIMDE_SSE2_NATIVE)
#    include <emmintrin.h>
#  endif

#  include <stdint.h>
#  include <limits.h>
#  include <string.h>

typedef union {
#if defined(SIMDE__ENABLE_GCC_VEC_EXT)
  int8_t          i8 __attribute__((__vector_size__(16), __may_alias__));
  int16_t        i16 __attribute__((__vector_size__(16), __may_alias__));
  int32_t        i32 __attribute__((__vector_size__(16), __may_alias__));
  int64_t        i64 __attribute__((__vector_size__(16), __may_alias__));
  uint8_t         u8 __attribute__((__vector_size__(16), __may_alias__));
  uint16_t       u16 __attribute__((__vector_size__(16), __may_alias__));
  uint32_t       u32 __attribute__((__vector_size__(16), __may_alias__));
  uint64_t       u64 __attribute__((__vector_size__(16), __may_alias__));
  float          f32 __attribute__((__vector_size__(16), __may_alias__));
  double         f64 __attribute__((__vector_size__(16), __may_alias__));
#else
  int8_t         i8[16];
  int16_t        i16[8];
  int32_t        i32[4];
  int64_t        i64[2];
  uint8_t        u8[16];
  uint16_t       u16[8];
  uint32_t       u32[4];
  uint64_t       u64[2];
  float          f32[4];
  double         f64[2];
#endif

#if defined(SIMDE_SSE2_NATIVE)
  __m128i        n;
#endif
} simde__m128i;

typedef union {
#if defined(SIMDE__ENABLE_GCC_VEC_EXT)
  int8_t          i8 __attribute__((__vector_size__(16), __may_alias__));
  int16_t        i16 __attribute__((__vector_size__(16), __may_alias__));
  int32_t        i32 __attribute__((__vector_size__(16), __may_alias__));
  int64_t        i64 __attribute__((__vector_size__(16), __may_alias__));
  uint8_t         u8 __attribute__((__vector_size__(16), __may_alias__));
  uint16_t       u16 __attribute__((__vector_size__(16), __may_alias__));
  uint32_t       u32 __attribute__((__vector_size__(16), __may_alias__));
  uint64_t       u64 __attribute__((__vector_size__(16), __may_alias__));
  float          f32 __attribute__((__vector_size__(16), __may_alias__));
  double         f64 __attribute__((__vector_size__(16), __may_alias__));
#else
  int8_t         i8[16];
  int16_t        i16[8];
  int32_t        i32[4];
  int64_t        i64[2];
  uint8_t        u8[16];
  uint16_t       u16[8];
  uint32_t       u32[4];
  uint64_t       u64[2];
  float          f32[4];
  double         f64[2];
#endif

#if defined(SIMDE_SSE2_NATIVE)
  __m128d        n;
#endif
} simde__m128d;

#if defined(SIMDE_SSE2_NATIVE)
HEDLEY_STATIC_ASSERT(sizeof(__m128i) == sizeof(simde__m128i), "__m128i size incorrect");
HEDLEY_STATIC_ASSERT(sizeof(__m128d) == sizeof(simde__m128d), "__m128d size incorrect");
#define SIMDE__M128I_C(expr) ((simde__m128i) { .n = expr })
#define SIMDE__M128D_C(expr) ((simde__m128d) { .n = expr })
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_add_epi8 (simde__m128i a, simde__m128i b) {
#if defined(SIMDE_SSE2_NATIVE)
  return SIMDE__M128I_C(_mm_add_epi8(a.n, b.n));
#else
  simde__m128i r;
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.i8) / sizeof(r.i8[0])) ; i++) {
    r.i8[i] = a.i8[i] + b.i8[i];
  }
  return r;
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_andnot_si128 (simde__m128i a, simde__m128i b) {
#if defined(SIMDE_SSE2_NATIVE)
  return SIMDE__M128I_C(_mm_andnot_si128(a.n, b.n));
#else
  simde__m128i r;
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.i64) / sizeof(r.i64[0])) ; i++) {
    r.i64[i] = ~(a.i64[i]) & b.i64[i];
  }
  return r;
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_and_si128 (simde__m128i a, simde__m128i b) {
#if defined(SIMDE_SSE2_NATIVE)
  return SIMDE__M128I_C(_mm_and_si128(a.n, b.n));
#else
  simde__m128i r;
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.i64) / sizeof(r.i64[0])) ; i++) {
    r.i64[i] = a.i64[i] & b.i64[i];
  }
  return r;
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_cmpeq_epi8 (simde__m128i a, simde__m128i b) {
#if defined(SIMDE_SSE2_NATIVE)
  return SIMDE__M128I_C(_mm_cmpeq_epi8(a.n, b.n));
#else
  simde__m128i r;
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.u8) / sizeof(r.u8[0])) ; i++) {
    r.u8[i] = (a.u8[i] == b.u8[i]) ? 0xff : 0x00;
  }
  return r;
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_cmplt_epi8 (simde__m128i a, simde__m128i b) {
#if defined(SIMDE_SSE2_NATIVE)
  return SIMDE__M128I_C(_mm_cmplt_epi8(a.n, b.n));
#else
  simde__m128i r;
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.u8) / sizeof(r.u8[0])) ; i++) {
    r.u8[i] = (a.i8[i] < b.i8[i]) ? 0xff : 0x00;
  }
  return r;
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
int64_t
simde_mm_cvtsi128_si64 (simde__m128i a) {
#if defined(SIMDE_SSE2_NATIVE) && defined(SIMDE_ARCH_AMD64) && !defined(SIMDE_BUG_PGI_TPR_24170)
  return _mm_cvtsi128_si64(a.n);
#else
  return a.i64[0];
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_cvtsi64_si128 (int64_t a) {
#if defined(SIMDE_SSE2_NATIVE) && defined(SIMDE_ARCH_AMD64)
  #if !defined(SIMDE_BUG_PGI_TPR_24170)
    return SIMDE__M128I_C(_mm_cvtsi64_si128(a));
  #else
    return SIMDE__M128I_C(_mm_cvtsi64x_si128(a));
  #endif
#else
  simde__m128i r;
  r.i64[0] = a;
  r.i64[1] = 0;
  return r;
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_loadu_si128 (simde__m128i const* mem_addr) {
#if defined(SIMDE_SSE2_NATIVE)
  return SIMDE__M128I_C(_mm_loadu_si128(&((*mem_addr).n)));
#else
  simde__m128i r;
  memcpy(&r, mem_addr, sizeof(r));
  return r;
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
int32_t
simde_mm_movemask_epi8 (simde__m128i a) {
#if defined(SIMDE_SSE2_NATIVE)
  return _mm_movemask_epi8(a.n);
#else
  int32_t r = 0;
  SIMDE__VECTORIZE_REDUCTION(|:r)
  for (size_t i = 0 ; i < 16 ; i++) {
    r |= (a.u8[15 - i] >> 7) << (15 - i);
  }
  return r;
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_or_si128 (simde__m128i a, simde__m128i b) {
#if defined(SIMDE_SSE2_NATIVE)
  return SIMDE__M128I_C(_mm_or_si128(a.n, b.n));
#else
  simde__m128i r;
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.i64) / sizeof(r.i64[0])) ; i++) {
    r.i64[i] = a.i64[i] | b.i64[i];
  }
  return r;
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_set_epi8 (int8_t e15, int8_t e14, int8_t e13, int8_t e12,
		   int8_t e11, int8_t e10, int8_t  e9, int8_t  e8,
		   int8_t  e7, int8_t  e6, int8_t  e5, int8_t  e4,
		   int8_t  e3, int8_t  e2, int8_t  e1, int8_t  e0) {
#if defined(SIMDE_SSE2_NATIVE)
  return SIMDE__M128I_C(_mm_set_epi8(e15, e14, e13, e12, e11, e10,  e9,  e8,
				      e7,  e6,  e5,  e4,  e3,  e2,  e1,  e0));
#else
  return (simde__m128i) { .i8 = {  e0,  e1,  e2,  e3,  e4,  e5,  e6,  e7,
				   e8,  e9, e10, e11, e12, e13, e14, e15 } };
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_set_epi16 (int16_t e7, int16_t e6, int16_t e5, int16_t e4,
		    int16_t e3, int16_t e2, int16_t e1, int16_t e0) {
#if defined(SIMDE_SSE2_NATIVE)
  return SIMDE__M128I_C(_mm_set_epi16(e7, e6, e5, e4, e3, e2, e1, e0));
#else
  return (simde__m128i) { .i16 = { e0, e1, e2, e3, e4, e5, e6, e7 } };
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_set_epi32 (int32_t e3, int32_t e2, int32_t e1, int32_t e0) {
#if defined(SIMDE_SSE2_NATIVE)
  return SIMDE__M128I_C(_mm_set_epi32(e3, e2, e1, e0));
#else
  return (simde__m128i) { .i32 = { e0, e1, e2, e3 } };
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_set_epi64 (simde__m64 e1, simde__m64 e0) {
#if defined(SIMDE_SSE2_NATIVE)
  return SIMDE__M128I_C(_mm_set_epi64(e1.n, e0.n));
#else
  return (simde__m128i) { .i64 = { e0.i64[0], e1.i64[0] } };
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_set_epi64x (int64_t e1, int64_t e0) {
#if defined(SIMDE_SSE2_NATIVE)
  return SIMDE__M128I_C(_mm_set_epi64x(e1, e0));
#else
  return (simde__m128i) { .i64 = { e0, e1 } };
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m128d
simde_mm_set_pd (double e1, double e0) {
#if defined(SIMDE_SSE2_NATIVE)
  return SIMDE__M128D_C(_mm_set_pd(e1, e0));
#else
  return (simde__m128d) { .f64 = { e0, e1 } };
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m128d
simde_mm_set_pd1 (double a) {
#if defined(SIMDE_SSE2_NATIVE)
  return SIMDE__M128D_C(_mm_set1_pd(a));
#else
  return (simde__m128d) { .f64 = { a, a } };
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m128d
simde_mm_set_sd (double a) {
#if defined(SIMDE_SSE2_NATIVE)
  return SIMDE__M128D_C(_mm_set_sd(a));
#else
  simde__m128d r;
  r.f64[0] = a;
  r.u64[1] = 0;
  return r;
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_set1_epi8 (int8_t a) {
#if defined(SIMDE_SSE2_NATIVE)
  return SIMDE__M128I_C(_mm_set1_epi8(a));
#else
  return (simde__m128i) { .i8 = { a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a } };
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_set1_epi16 (int16_t a) {
#if defined(SIMDE_SSE2_NATIVE)
  return SIMDE__M128I_C(_mm_set1_epi16(a));
#else
  return (simde__m128i) { .i16 = { a, a, a, a, a, a, a, a } };
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_set1_epi32 (int32_t a) {
#if defined(SIMDE_SSE2_NATIVE)
  return SIMDE__M128I_C(_mm_set1_epi32(a));
#else
  return (simde__m128i) { .i32 = { a, a, a, a } };
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_set1_epi64x (int64_t a) {
#if defined(SIMDE_SSE2_NATIVE)
  return SIMDE__M128I_C(_mm_set1_epi64x(a));
#else
  return (simde__m128i) { .i64 = { a, a } };
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_set1_epi64 (simde__m64 a) {
#if defined(SIMDE_SSE2_NATIVE)
  return SIMDE__M128I_C(_mm_set1_epi64(a.n));
#else
  return (simde__m128i) { .i64 = { a.i64[0], a.i64[0] } };
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m128d
simde_mm_set1_pd (double a) {
#if defined(SIMDE_SSE2_NATIVE)
  return SIMDE__M128D_C(_mm_set1_pd(a));
#else
  return (simde__m128d) { .f64 = { a, a } };
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_setr_epi8 (int8_t e15, int8_t e14, int8_t e13, int8_t e12,
		    int8_t e11, int8_t e10, int8_t  e9, int8_t  e8,
		    int8_t  e7, int8_t  e6, int8_t  e5, int8_t  e4,
		    int8_t  e3, int8_t  e2, int8_t  e1, int8_t  e0) {
#if defined(SIMDE_SSE2_NATIVE)
  return SIMDE__M128I_C(_mm_setr_epi8(e15, e14, e13, e12, e11, e10,  e9,  e8,
				       e7,  e6,  e5,  e4,  e3,  e2,  e1,  e0));
#else
  return (simde__m128i) { .i8 = { e15, e14, e13, e12, e11, e10,  e9,  e8,
				   e7,  e6,  e5,  e4,  e3,  e2,  e1,  e0  } };
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_setr_epi16 (int16_t e7, int16_t e6, int16_t e5, int16_t e4,
		     int16_t e3, int16_t e2, int16_t e1, int16_t e0) {
#if defined(SIMDE_SSE2_NATIVE)
  return SIMDE__M128I_C(_mm_setr_epi16(e7, e6, e5, e4, e3, e2, e1, e0));
#else
  return (simde__m128i) { .i16 = { e7, e6, e5, e4, e3, e2, e1, e0 } };
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_setr_epi32 (int32_t e3, int32_t e2, int32_t e1, int32_t e0) {
#if defined(SIMDE_SSE2_NATIVE)
  return SIMDE__M128I_C(_mm_setr_epi32(e3, e2, e1, e0));
#else
  return (simde__m128i) { .i32 = { e3, e2, e1, e0 } };
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_setr_epi64 (simde__m64 e1, simde__m64 e0) {
#if defined(SIMDE_SSE2_NATIVE)
  return SIMDE__M128I_C(_mm_setr_epi64(e1.n, e0.n));
#else
  return (simde__m128i) { .i64 = { e1.i64[0], e0.i64[0] } };
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m128d
simde_mm_setr_pd (double e1, double e0) {
#if defined(SIMDE_SSE2_NATIVE)
  return SIMDE__M128D_C(_mm_setr_pd(e1, e0));
#else
  return (simde__m128d) { .i64 = { e1, e0 } };
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m128d
simde_mm_setzero_pd (void) {
#if defined(SIMDE_SSE2_NATIVE)
  return SIMDE__M128D_C(_mm_setzero_pd());
#else
  return (simde__m128d) { .u64 = { 0.0, } };
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_setzero_si128 (void) {
#if defined(SIMDE_SSE2_NATIVE)
  return SIMDE__M128I_C(_mm_setzero_si128());
#else
  return (simde__m128i) { .i64 = { 0, } };
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_srli_epi32 (simde__m128i a, const int imm8) {
#if defined(SIMDE_SSE2_NATIVE)
  return SIMDE__M128I_C(_mm_srli_epi32(a.n, imm8));
#else
  simde__m128i r;
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.i32) / sizeof(r.i32[0])) ; i++) {
    r.u32[i] = a.u32[i] >> imm8;
  }
  return r;
#endif
}

#if defined(simde_mm_srli_si128)
#  undef simde_mm_srli_si128
#endif
SIMDE__FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_srli_si128 (simde__m128i a, const int imm8) {
  simde__m128i r;
  const int s = (imm8 > 15 ? 16 : imm8) * 8;

  if (s > 64) {
    r.u64[0] = a.u64[1] >> (s - 64);
    r.u64[1] = 0;
  } else {
    r.u64[0] = a.u64[0] >> s | a.u64[1] << (64 - s);
    r.u64[1] = a.u64[1] >> s;
  }

  return r;
}
#if defined(SIMDE_SSE2_NATIVE) && !defined(__PGI)
#  define simde_mm_srli_si128(a, imm8) SIMDE__M128I_C(_mm_srli_si128(a.n, imm8))
#endif

SIMDE__FUNCTION_ATTRIBUTES
void
simde_mm_storeu_si128 (simde__m128i* mem_addr, simde__m128i a) {
#if defined(SIMDE_SSE2_NATIVE)
  _mm_storeu_si128(&mem_addr->n, a.n);
#else
  memcpy(mem_addr, &a, sizeof(a));
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_sub_epi8 (simde__m128i a, simde__m128i b) {
#if defined(SIMDE_SSE2_NATIVE)
  return SIMDE__M128I_C(_mm_sub_epi8(a.n, b.n));
#else
  simde__m128i r;
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.i8) / sizeof(r.i8[0])) ; i++) {
    r.i8[i] = a.i8[i] - b.i8[i];
  }
  return r;
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_xor_si128 (simde__m128i a, simde__m128i b) {
#if defined(SIMDE_SSE2_NATIVE)
  return SIMDE__M128I_C(_mm_xor_si128(a.n, b.n));
#else
  simde__m128i r;
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.i32) / sizeof(r.i32[0])) ; i++) {
    r.i32[i] = a.i32[i] ^ b.i32[i];
  }
  return r;
#endif
}

#endif /* !defined(SIMDE__SSE2_H) */
