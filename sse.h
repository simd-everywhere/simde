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

#if !defined(SIMDE__SSE_H)
#  if !defined(SIMDE__SSE_H)
#    define SIMDE__SSE_H
#  endif
#  include "mmx.h"

#  if defined(SIMDE_SSE_NATIVE)
#    undef SIMDE_SSE_NATIVE
#  endif
#  if defined(SIMDE_SSE_FORCE_NATIVE)
#    define SIMDE_SSE_NATIVE
#  elif defined(__SSE__) && (!defined(SIMDE_SSE_NO_NATIVE) && !defined(SIMDE_NO_NATIVE))
#    define SIMDE_SSE_NATIVE
#  endif

#  if defined(SIMDE_SSE_NATIVE) && !defined(SIMDE_MMX_NATIVE)
#    if defined(SIMDE_SSE_FORCE_NATIVE)
#      error Native SSE support requires native MMX support
#    else
#      warning Native SSE support requires native MMX support, disabling
#      undef SIMDE_SSE_NATIVE
#    endif
#  endif

#  if defined(SIMDE_SSE_NATIVE)
#    include <xmmintrin.h>
#    if defined(__PGI)
#      include <math.h>
#    endif
#  else
#    include <math.h>
#    include <fenv.h>
#  endif

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
#endif

#if defined(SIMDE_SSE_NATIVE)
  __m128         n;
#endif
} SIMDE__ALIGN(16) simde__m128;

#if defined(SIMDE_SSE_NATIVE)
HEDLEY_STATIC_ASSERT(sizeof(__m128) == sizeof(simde__m128), "__m128 size incorrect");
#define SIMDE__M128_C(expr) ((simde__m128) { .n = expr })
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128
simde_mm_set_ps (float a, float b, float c, float d) {
#if defined(SIMDE_SSE_NATIVE)
  return SIMDE__M128_C(_mm_set_ps(a, b, c, d));
#else
  return (simde__m128) { .f32 = { d, c, b, a } };
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m128
simde_mm_set1_ps (float v) {
#if defined(SIMDE_SSE_NATIVE)
  return SIMDE__M128_C(_mm_set1_ps(v));
#else
  return simde_mm_set_ps(v, v, v, v);
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m128
simde_mm_add_ps (simde__m128 a, simde__m128 b) {
#if defined(SIMDE_SSE_NATIVE)
  return SIMDE__M128_C(_mm_add_ps(a.n, b.n));
#else
  simde__m128 r;
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.f32) / sizeof(r.f32[0])) ; i++) {
    r.f32[i] = a.f32[i] + b.f32[i];
  }
  return r;
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m128
simde_mm_add_ss (simde__m128 a, simde__m128 b) {
#if defined(SIMDE_SSE_NATIVE)
  return SIMDE__M128_C(_mm_add_ss(a.n, b.n));
#else
  return (simde__m128) {
    .f32 = { a.f32[0] + b.f32[0], a.f32[1], a.f32[2], a.f32[3] }
  };
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m128
simde_mm_and_ps (simde__m128 a, simde__m128 b) {
#if defined(SIMDE_SSE_NATIVE)
  return SIMDE__M128_C(_mm_and_ps(a.n, b.n));
#else
  simde__m128 r;
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.i32) / sizeof(r.i32[0])) ; i++) {
    r.i32[i] = a.i32[i] & b.i32[i];
  }
  return r;
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m128
simde_mm_andnot_ps (simde__m128 a, simde__m128 b) {
#if defined(SIMDE_SSE_NATIVE)
  return SIMDE__M128_C(_mm_andnot_ps(a.n, b.n));
#else
  simde__m128 r;
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.i32) / sizeof(r.i32[0])) ; i++) {
    r.i32[i] = ~(a.i32[i]) & b.i32[i];
  }
  return r;
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_mm_avg_pu16 (simde__m64 a, simde__m64 b) {
#if defined(SIMDE_SSE_NATIVE)
  return SIMDE__M64_C(_mm_avg_pu16(a.n, b.n));
#else
  simde__m64 r;
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < 4 ; i++) {
    r.u16[i] = (a.u16[i] + b.u16[i] + 1) >> 1;
  }
  return r;
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_mm_avg_pu8 (simde__m64 a, simde__m64 b) {
#if defined(SIMDE_SSE_NATIVE)
  return SIMDE__M64_C(_mm_avg_pu8(a.n, b.n));
#else
  simde__m64 r;
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < 8 ; i++) {
    r.u8[i] = (a.u8[i] + b.u8[i] + 1) >> 1;
  }
  return r;
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m128
simde_mm_cmpeq_ps (simde__m128 a, simde__m128 b) {
#if defined(SIMDE_SSE_NATIVE)
  return SIMDE__M128_C(_mm_cmpeq_ps(a.n, b.n));
#else
  simde__m128 r;
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.f32) / sizeof(r.f32[0])) ; i++) {
    r.u32[i] = (a.f32[i] == b.f32[i]) ? 0xffffffff : 0;
  }
  return r;
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m128
simde_mm_cmpeq_ss (simde__m128 a, simde__m128 b) {
#if defined(SIMDE_SSE_NATIVE)
  return SIMDE__M128_C(_mm_cmpeq_ss(a.n, b.n));
#else
  simde__m128 r;
  r.u32[0] = (a.f32[0] == b.f32[0]) ? 0xffffffff : 0;
  SIMDE__VECTORIZE
  for (size_t i = 1 ; i < (sizeof(r.f32) / sizeof(r.f32[0])) ; i++) {
    r.u32[i] = a.u32[i];
  }
  return r;
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m128
simde_mm_cmpge_ps (simde__m128 a, simde__m128 b) {
#if defined(SIMDE_SSE_NATIVE)
  return SIMDE__M128_C(_mm_cmpge_ps(a.n, b.n));
#else
  simde__m128 r;
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.f32) / sizeof(r.f32[0])) ; i++) {
    r.u32[i] = (a.f32[i] >= b.f32[i]) ? 0xffffffff : 0;
  }
  return r;
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m128
simde_mm_cmpge_ss (simde__m128 a, simde__m128 b) {
#if defined(SIMDE_SSE_NATIVE)
  return SIMDE__M128_C(_mm_cmpge_ss(a.n, b.n));
#else
  simde__m128 r;
  r.u32[0] = (a.f32[0] >= b.f32[0]) ? 0xffffffff : 0;
  SIMDE__VECTORIZE
  for (size_t i = 1 ; i < (sizeof(r.f32) / sizeof(r.f32[0])) ; i++) {
    r.u32[i] = a.u32[i];
  }
  return r;
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m128
simde_mm_cmpgt_ps (simde__m128 a, simde__m128 b) {
#if defined(SIMDE_SSE_NATIVE)
  return SIMDE__M128_C(_mm_cmpgt_ps(a.n, b.n));
#else
  simde__m128 r;
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.f32) / sizeof(r.f32[0])) ; i++) {
    r.u32[i] = (a.f32[i] > b.f32[i]) ? 0xffffffff : 0;
  }
  return r;
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m128
simde_mm_cmpgt_ss (simde__m128 a, simde__m128 b) {
#if defined(SIMDE_SSE_NATIVE)
  return SIMDE__M128_C(_mm_cmpgt_ss(a.n, b.n));
#else
  simde__m128 r;
  r.u32[0] = (a.f32[0] > b.f32[0]) ? 0xffffffff : 0;
  SIMDE__VECTORIZE
  for (size_t i = 1 ; i < (sizeof(r.f32) / sizeof(r.f32[0])) ; i++) {
    r.u32[i] = a.u32[i];
  }
  return r;
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m128
simde_mm_cmple_ps (simde__m128 a, simde__m128 b) {
#if defined(SIMDE_SSE_NATIVE)
  return SIMDE__M128_C(_mm_cmple_ps(a.n, b.n));
#else
  simde__m128 r;
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.f32) / sizeof(r.f32[0])) ; i++) {
    r.u32[i] = (a.f32[i] <= b.f32[i]) ? 0xffffffff : 0;
  }
  return r;
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m128
simde_mm_cmple_ss (simde__m128 a, simde__m128 b) {
#if defined(SIMDE_SSE_NATIVE)
  return SIMDE__M128_C(_mm_cmple_ss(a.n, b.n));
#else
  simde__m128 r;
  r.u32[0] = (a.f32[0] <= b.f32[0]) ? 0xffffffff : 0;
  SIMDE__VECTORIZE
  for (size_t i = 1 ; i < (sizeof(r.f32) / sizeof(r.f32[0])) ; i++) {
    r.u32[i] = a.u32[i];
  }
  return r;
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m128
simde_mm_cmplt_ps (simde__m128 a, simde__m128 b) {
#if defined(SIMDE_SSE_NATIVE)
  return SIMDE__M128_C(_mm_cmplt_ps(a.n, b.n));
#else
  simde__m128 r;
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.f32) / sizeof(r.f32[0])) ; i++) {
    r.u32[i] = (a.f32[i] < b.f32[i]) ? 0xffffffff : 0;
  }
  return r;
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m128
simde_mm_cmplt_ss (simde__m128 a, simde__m128 b) {
#if defined(SIMDE_SSE_NATIVE)
  return SIMDE__M128_C(_mm_cmplt_ss(a.n, b.n));
#else
  simde__m128 r;
  r.u32[0] = (a.f32[0] < b.f32[0]) ? 0xffffffff : 0;
  SIMDE__VECTORIZE
  for (size_t i = 1 ; i < (sizeof(r.f32) / sizeof(r.f32[0])) ; i++) {
    r.u32[i] = a.u32[i];
  }
  return r;
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m128
simde_mm_cmpneq_ps (simde__m128 a, simde__m128 b) {
#if defined(SIMDE_SSE_NATIVE)
  return SIMDE__M128_C(_mm_cmpneq_ps(a.n, b.n));
#else
  simde__m128 r;
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.f32) / sizeof(r.f32[0])) ; i++) {
    r.u32[i] = (a.f32[i] != b.f32[i]) ? 0xffffffff : 0;
  }
  return r;
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m128
simde_mm_cmpneq_ss (simde__m128 a, simde__m128 b) {
#if defined(SIMDE_SSE_NATIVE)
  return SIMDE__M128_C(_mm_cmpneq_ss(a.n, b.n));
#else
  simde__m128 r;
  r.u32[0] = (a.f32[0] != b.f32[0]) ? 0xffffffff : 0;
  SIMDE__VECTORIZE
  for (size_t i = 1 ; i < (sizeof(r.f32) / sizeof(r.f32[0])) ; i++) {
    r.u32[i] = a.u32[i];
  }
  return r;
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m128
simde_mm_cmpnge_ps (simde__m128 a, simde__m128 b) {
#if defined(SIMDE_SSE_NATIVE)
  return SIMDE__M128_C(_mm_cmpnge_ps(a.n, b.n));
#else
  return simde_mm_cmplt_ps(a, b);
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m128
simde_mm_cmpnge_ss (simde__m128 a, simde__m128 b) {
#if defined(SIMDE_SSE_NATIVE)
  return SIMDE__M128_C(_mm_cmpnge_ss(a.n, b.n));
#else
  return simde_mm_cmplt_ss(a, b);
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m128
simde_mm_cmpngt_ps (simde__m128 a, simde__m128 b) {
#if defined(SIMDE_SSE_NATIVE)
  return SIMDE__M128_C(_mm_cmpngt_ps(a.n, b.n));
#else
  return simde_mm_cmple_ps(a, b);
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m128
simde_mm_cmpngt_ss (simde__m128 a, simde__m128 b) {
#if defined(SIMDE_SSE_NATIVE)
  return SIMDE__M128_C(_mm_cmpngt_ss(a.n, b.n));
#else
  return simde_mm_cmple_ss(a, b);
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m128
simde_mm_cmpnle_ps (simde__m128 a, simde__m128 b) {
#if defined(SIMDE_SSE_NATIVE)
  return SIMDE__M128_C(_mm_cmpnle_ps(a.n, b.n));
#else
  return simde_mm_cmpgt_ps(a, b);
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m128
simde_mm_cmpnle_ss (simde__m128 a, simde__m128 b) {
#if defined(SIMDE_SSE_NATIVE)
  return SIMDE__M128_C(_mm_cmpnle_ss(a.n, b.n));
#else
  return simde_mm_cmpgt_ss(a, b);
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m128
simde_mm_cmpnlt_ps (simde__m128 a, simde__m128 b) {
#if defined(SIMDE_SSE_NATIVE)
  return SIMDE__M128_C(_mm_cmpnlt_ps(a.n, b.n));
#else
  return simde_mm_cmpge_ps(a, b);
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m128
simde_mm_cmpnlt_ss (simde__m128 a, simde__m128 b) {
#if defined(SIMDE_SSE_NATIVE)
  return SIMDE__M128_C(_mm_cmpnlt_ss(a.n, b.n));
#else
  return simde_mm_cmpge_ss(a, b);
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m128
simde_mm_cmpord_ps (simde__m128 a, simde__m128 b) {
#if defined(SIMDE_SSE_NATIVE)
  return SIMDE__M128_C(_mm_cmpord_ps(a.n, b.n));
#else
  simde__m128 r;
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.f32) / sizeof(r.f32[0])) ; i++) {
    r.u32[i] = (isnan(a.f32[i]) || isnan(b.f32[i])) ? 0 : 0xffffffff;
  }
  return r;
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m128
simde_mm_cmpord_ss (simde__m128 a, simde__m128 b) {
#if defined(SIMDE_SSE_NATIVE)
  return SIMDE__M128_C(_mm_cmpord_ss(a.n, b.n));
#else
  simde__m128 r;
  r.u32[0] = (isnan(a.f32[0]) || isnan(b.f32[0])) ? 0 : 0xffffffff;
  SIMDE__VECTORIZE
  for (size_t i = 1 ; i < (sizeof(r.f32) / sizeof(r.f32[0])) ; i++) {
    r.f32[i] = a.f32[i];
  }
  return r;
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m128
simde_mm_cmpunord_ps (simde__m128 a, simde__m128 b) {
#if defined(SIMDE_SSE_NATIVE)
  return SIMDE__M128_C(_mm_cmpunord_ps(a.n, b.n));
#else
  simde__m128 r;
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.f32) / sizeof(r.f32[0])) ; i++) {
    r.u32[i] = (isnan(a.f32[i]) || isnan(b.f32[i])) ? 0xffffffff : 0;
  }
  return r;
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m128
simde_mm_cmpunord_ss (simde__m128 a, simde__m128 b) {
#if defined(SIMDE_SSE_NATIVE)
  return SIMDE__M128_C(_mm_cmpunord_ss(a.n, b.n));
#else
  simde__m128 r;
  r.u32[0] = (isnan(a.f32[0]) || isnan(b.f32[0])) ? 0xffffffff : 0;
  SIMDE__VECTORIZE
  for (size_t i = 1 ; i < (sizeof(r.f32) / sizeof(r.f32[0])) ; i++) {
    r.f32[i] = a.f32[i];
  }
  return r;
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
int
simde_mm_comieq_ss (simde__m128 a, simde__m128 b) {
#if defined(SIMDE_SSE_NATIVE)
  return _mm_comieq_ss(a.n, b.n);
#else
  return a.f32[0] == b.f32[0];
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
int
simde_mm_comige_ss (simde__m128 a, simde__m128 b) {
#if defined(SIMDE_SSE_NATIVE)
  return _mm_comige_ss(a.n, b.n);
#else
  return a.f32[0] >= b.f32[0];
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
int
simde_mm_comigt_ss (simde__m128 a, simde__m128 b) {
#if defined(SIMDE_SSE_NATIVE)
  return _mm_comigt_ss(a.n, b.n);
#else
  return a.f32[0] > b.f32[0];
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
int
simde_mm_comile_ss (simde__m128 a, simde__m128 b) {
#if defined(SIMDE_SSE_NATIVE)
  return _mm_comile_ss(a.n, b.n);
#else
  return a.f32[0] <= b.f32[0];
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
int
simde_mm_comilt_ss (simde__m128 a, simde__m128 b) {
#if defined(SIMDE_SSE_NATIVE)
  return _mm_comilt_ss(a.n, b.n);
#else
  return a.f32[0] < b.f32[0];
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
int
simde_mm_comineq_ss (simde__m128 a, simde__m128 b) {
#if defined(SIMDE_SSE_NATIVE)
  return _mm_comineq_ss(a.n, b.n);
#else
  return a.f32[0] != b.f32[0];
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m128
simde_mm_cvt_pi2ps (simde__m128 a, simde__m64 b) {
#if defined(SIMDE_SSE_NATIVE)
  return SIMDE__M128_C(_mm_cvt_pi2ps(a.n, b.n));
#else
  simde__m128 r;
  r.f32[0] = (float) b.i32[0];
  r.f32[1] = (float) b.i32[1];
  r.i32[2] = a.i32[2];
  r.i32[3] = a.i32[3];
  return r;
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_mm_cvt_ps2pi (simde__m128 a) {
#if defined(SIMDE_SSE_NATIVE)
  return SIMDE__M64_C(_mm_cvt_ps2pi(a.n));
#else
  simde__m64 r;
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.i32) / sizeof(r.i32[0])) ; i++) {
    r.i32[i] = (int32_t) a.f32[i];
  }
  return r;
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m128
simde_mm_cvt_si2ss (simde__m128 a, int32_t b) {
#if defined(SIMDE_SSE_NATIVE)
  return SIMDE__M128_C(_mm_cvt_si2ss(a.n, b));
#else
  simde__m128 r;
  r.f32[0] = (float) b;
  r.i32[1] = a.i32[1];
  r.i32[2] = a.i32[2];
  r.i32[3] = a.i32[3];
  return r;
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
int32_t
simde_mm_cvt_ss2si (simde__m128 a) {
#if defined(SIMDE_SSE_NATIVE)
  return _mm_cvt_ss2si(a.n);
#else
  return (int32_t) a.f32[0];
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m128
simde_mm_cvtpi16_ps (simde__m64 a) {
#if defined(SIMDE_SSE_NATIVE)
  return SIMDE__M128_C(_mm_cvtpi16_ps(a.n));
#else
  simde__m128 r;
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.f32) / sizeof(r.f32[0])) ; i++) {
    r.f32[i] = (float) a.i16[i];
  }
  return r;
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m128
simde_mm_cvtpi32_ps (simde__m128 a, simde__m64 b) {
#if defined(SIMDE_SSE_NATIVE)
  return SIMDE__M128_C(_mm_cvtpi32_ps(a.n, b.n));
#else
  simde__m128 r;
  r.f32[0] = (float) b.i32[0];
  r.f32[1] = (float) b.i32[1];
  r.i32[2] = a.i32[2];
  r.i32[3] = a.i32[3];
  return r;
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m128
simde_mm_cvtpi32x2_ps (simde__m64 a, simde__m64 b) {
#if defined(SIMDE_SSE_NATIVE)
  return SIMDE__M128_C(_mm_cvtpi32x2_ps(a.n, b.n));
#else
  simde__m128 r;
  r.f32[0] = (float) a.i32[0];
  r.f32[1] = (float) a.i32[1];
  r.f32[2] = (float) b.i32[0];
  r.f32[3] = (float) b.i32[1];
  return r;
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m128
simde_mm_cvtpi8_ps (simde__m64 a) {
#if defined(SIMDE_SSE_NATIVE)
  return SIMDE__M128_C(_mm_cvtpi8_ps(a.n));
#else
  simde__m128 r;
  r.f32[0] = (float) a.i8[0];
  r.f32[1] = (float) a.i8[1];
  r.f32[2] = (float) a.i8[2];
  r.f32[3] = (float) a.i8[3];
  return r;
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_mm_cvtps_pi16 (simde__m128 a) {
#if defined(SIMDE_SSE_NATIVE)
  return SIMDE__M64_C(_mm_cvtps_pi16(a.n));
#else
  simde__m64 r;
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.i16) / sizeof(r.i16[0])) ; i++) {
    r.i16[i] = (int16_t) a.f32[i];
  }
  return r;
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_mm_cvtps_pi32 (simde__m128 a) {
#if defined(SIMDE_SSE_NATIVE)
  return SIMDE__M64_C(_mm_cvtps_pi32(a.n));
#else
  simde__m64 r;
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.i32) / sizeof(r.i32[0])) ; i++) {
    r.i32[i] = (int32_t) a.f32[i];
  }
  return r;
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_mm_cvtps_pi8 (simde__m128 a) {
#if defined(SIMDE_SSE_NATIVE)
  return SIMDE__M64_C(_mm_cvtps_pi8(a.n));
#else
  simde__m64 r;
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.i8) / sizeof(r.i8[0])) ; i++) {
    r.i8[i] = (int8_t) a.f32[i];
  }
  return r;
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m128
simde_mm_cvtpu16_ps (simde__m64 a) {
#if defined(SIMDE_SSE_NATIVE)
  return SIMDE__M128_C(_mm_cvtpu16_ps(a.n));
#else
  simde__m128 r;
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.f32) / sizeof(r.f32[0])) ; i++) {
    r.f32[i] = (float) a.u16[i];
  }
  return r;
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m128
simde_mm_cvtpu8_ps (simde__m64 a) {
#if defined(SIMDE_SSE_NATIVE)
  return SIMDE__M128_C(_mm_cvtpu8_ps(a.n));
#else
  simde__m128 r;
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < 4 ; i++) {
    r.f32[i] = (float) a.u8[i];
  }
  return r;
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m128
  simde_mm_cvtsi32_ss (simde__m128 a, int32_t b) {
#if defined(SIMDE_SSE_NATIVE)
  return SIMDE__M128_C(_mm_cvtsi32_ss(a.n, b));
#else
  simde__m128 r;
  r.f32[0] = (float) b;
  SIMDE__VECTORIZE
  for (size_t i = 1 ; i < 4 ; i++) {
    r.i32[i] = a.i32[i];
  }
  return r;
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m128
simde_mm_cvtsi64_ss (simde__m128 a, int64_t b) {
#if defined(SIMDE_SSE_NATIVE) && !defined(__PGI)
  return SIMDE__M128_C(_mm_cvtsi64_ss(a.n, b));
#elif defined(SIMDE_SSE_NATIVE)
  return SIMDE__M128_C(_mm_cvtsi64x_ss(a.n, b));
#else
  simde__m128 r;
  r.f32[0] = (float) b;
  SIMDE__VECTORIZE
  for (size_t i = 1 ; i < 4 ; i++) {
    r.i32[i] = a.i32[i];
  }
  return r;
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
float
simde_mm_cvtss_f32 (simde__m128 a) {
#if defined(SIMDE_SSE_NATIVE)
  return _mm_cvtss_f32(a.n);
#else
  return a.f32[0];
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
int32_t
simde_mm_cvtss_si32 (simde__m128 a) {
#if defined(SIMDE_SSE_NATIVE)
  return _mm_cvtss_si32(a.n);
#else
  return (int32_t) a.f32[0];
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
int64_t
simde_mm_cvtss_si64 (simde__m128 a) {
#if defined(SIMDE_SSE_NATIVE) && !defined(__PGI)
  return _mm_cvtss_si64(a.n);
#elif defined(SIMDE_SSE_NATIVE)
  return _mm_cvtss_si64x(a.n);
#else
  return (int64_t) a.f32[0];
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_mm_cvtt_ps2pi (simde__m128 a) {
#if defined(SIMDE_SSE_NATIVE)
  return SIMDE__M64_C(_mm_cvtt_ps2pi(a.n));
#else
  simde__m64 r;
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.f32) / sizeof(r.f32[0])) ; i++) {
    r.i32[i] = (int32_t) truncf(a.f32[i]);
  }
  return r;
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
int32_t
simde_mm_cvtt_ss2si (simde__m128 a) {
#if defined(SIMDE_SSE_NATIVE)
  return _mm_cvtt_ss2si(a.n);
#else
  return (int32_t) truncf(a.f32[0]);
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_mm_cvttps_pi32 (simde__m128 a) {
#if defined(SIMDE_SSE_NATIVE)
  return SIMDE__M64_C(_mm_cvttps_pi32(a.n));
#else
  return simde_mm_cvtt_ps2pi(a);
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
int32_t
simde_mm_cvttss_si32 (simde__m128 a) {
#if defined(SIMDE_SSE_NATIVE)
  return _mm_cvttss_si32(a.n);
#else
  return (int32_t) truncf(a.f32[0]);
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
int64_t
simde_mm_cvttss_si64 (simde__m128 a) {
#if defined(SIMDE_SSE_NATIVE) && !defined(__PGI)
  return _mm_cvttss_si64(a.n);
#else
  return (int64_t) truncf(a.f32[0]);
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m128
simde_mm_div_ps (simde__m128 a, simde__m128 b) {
#if defined(SIMDE_SSE_NATIVE)
  return SIMDE__M128_C(_mm_div_ps(a.n, b.n));
#else
  simde__m128 r;
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.f32) / sizeof(r.f32[0])) ; i++) {
    r.f32[i] = a.f32[i] / b.f32[i];
  }
  return r;
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m128
simde_mm_div_ss (simde__m128 a, simde__m128 b) {
#if defined(SIMDE_SSE_NATIVE)
  return SIMDE__M128_C(_mm_div_ss(a.n, b.n));
#else
  simde__m128 r;
  r.f32[0] = a.f32[0] / b.f32[0];
  SIMDE__VECTORIZE
  for (size_t i = 1 ; i < (sizeof(r.f32) / sizeof(r.f32[0])) ; i++) {
    r.f32[i] = a.f32[i];
  }
  return r;
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
int32_t
simde_mm_extract_pi16 (simde__m64 a, const int imm8) {
#if defined(SIMDE_SSE_NATIVE) && !defined(__clang__) && !defined(__PGI)
  return _mm_extract_pi16(a.n, imm8);
#else
  return a.u16[imm8];
#endif
}

enum {
#if defined(SIMDE_SSE_NATIVE)
  simde_MM_ROUND_NEAREST     = _MM_ROUND_NEAREST,
  simde_MM_ROUND_DOWN        = _MM_ROUND_DOWN,
  simde_MM_ROUND_UP          = _MM_ROUND_UP,
  simde_MM_ROUND_TOWARD_ZERO = _MM_ROUND_TOWARD_ZERO
#else
  simde_MM_ROUND_NEAREST
#if defined(FE_TONEAREST)
  = FE_TONEAREST
#endif
  ,

  simde_MM_ROUND_DOWN
#if defined(FE_DOWNWARD)
  = FE_DOWNWARD
#endif
  ,

  simde_MM_ROUND_UP
#if defined(FE_UPWARD)
  = FE_UPWARD
#endif
  ,

  simde_MM_ROUND_TOWARD_ZERO
#if defined(FE_TOWARDZERO)
  = FE_TOWARDZERO
#endif
#endif
};

SIMDE__FUNCTION_ATTRIBUTES
unsigned int
simde_MM_GET_ROUNDING_MODE(void) {
#if defined(SIMDE_SSE_NATIVE)
  return _MM_GET_ROUNDING_MODE();
#else
  return fegetround();
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
void
simde_MM_SET_ROUNDING_MODE(unsigned int a) {
#if defined(SIMDE_SSE_NATIVE)
  _MM_SET_ROUNDING_MODE(a);
#else
  fesetround((int) a);
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_mm_insert_pi16 (simde__m64 a, int16_t i, const int imm8) {
#if defined(SIMDE_SSE_NATIVE) && !defined(__clang__) && !defined(__PGI)
  return SIMDE__M64_C(_mm_insert_pi16(a.n, i, imm8));
#else
  simde__m64 r;
  r.i64[0] = a.i64[0];
  r.i16[imm8] = i;
  return r;
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m128
simde_mm_load_ps (float const mem_addr[HEDLEY_ARRAY_PARAM(4)]) {
#if defined(SIMDE_SSE_NATIVE)
  return SIMDE__M128_C(_mm_load_ps(mem_addr));
#else
  simde__m128 r;
  memcpy(&r, mem_addr, sizeof(r.f32));
  return r;
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m128
simde_mm_load_ps1 (float const* mem_addr) {
#if defined(SIMDE_SSE_NATIVE)
  return SIMDE__M128_C(_mm_load_ps1(mem_addr));
#else
  simde__m128 r;
  const float v = *mem_addr;
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.i32) / sizeof(r.i32[0])) ; i++) {
    r.f32[i] = v;
  }
  return r;
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m128
simde_mm_load_ss (float const* mem_addr) {
#if defined(SIMDE_SSE_NATIVE)
  return SIMDE__M128_C(_mm_load_ss(mem_addr));
#else
  simde__m128 r;
  r.f32[0] = *mem_addr;
  r.i32[1] = 0;
  r.i32[2] = 0;
  r.i32[3] = 0;
  return r;
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m128
simde_mm_load1_ps (float const* mem_addr) {
#if defined(SIMDE_SSE_NATIVE)
  return SIMDE__M128_C(_mm_load1_ps(mem_addr));
#else
  return simde_mm_load_ps1(mem_addr);
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m128
simde_mm_loadh_pi (simde__m128 a, simde__m64 const* mem_addr) {
#if defined(SIMDE_SSE_NATIVE)
  return SIMDE__M128_C(_mm_loadh_pi(a.n, (__m64*) mem_addr));
#else
  simde__m128 r;
  r.f32[0] = a.f32[0];
  r.f32[1] = a.f32[1];
  r.f32[2] = mem_addr->f32[0];
  r.f32[3] = mem_addr->f32[1];
  return r;
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m128
simde_mm_loadl_pi (simde__m128 a, simde__m64 const* mem_addr) {
#if defined(SIMDE_SSE_NATIVE)
  return SIMDE__M128_C(_mm_loadl_pi(a.n, (__m64*) mem_addr));
#else
  simde__m128 r;
  r.f32[0] = mem_addr->f32[0];
  r.f32[1] = mem_addr->f32[1];
  r.f32[2] = a.f32[2];
  r.f32[3] = a.f32[3];
  return r;
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m128
simde_mm_loadr_ps (float const mem_addr[HEDLEY_ARRAY_PARAM(4)]) {
#if defined(SIMDE_SSE_NATIVE)
  return SIMDE__M128_C(_mm_loadr_ps(mem_addr));
#else
  simde__m128 r;
  r.f32[0] = mem_addr[3];
  r.f32[1] = mem_addr[2];
  r.f32[2] = mem_addr[1];
  r.f32[3] = mem_addr[0];
  return r;
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m128
simde_mm_loadu_ps (float const mem_addr[HEDLEY_ARRAY_PARAM(4)]) {
#if defined(SIMDE_SSE_NATIVE)
  return SIMDE__M128_C(_mm_loadu_ps(mem_addr));
#else
  simde__m128 r;
  r.f32[0] = mem_addr[0];
  r.f32[1] = mem_addr[1];
  r.f32[2] = mem_addr[2];
  r.f32[3] = mem_addr[3];
  return r;
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
void
simde_mm_maskmove_si64 (simde__m64 a, simde__m64 mask, char* mem_addr) {
#if defined(SIMDE_SSE_NATIVE)
  _mm_maskmove_si64(a.n, mask.n, mem_addr);
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(a.i8) / sizeof(a.i8[0])) ; i++)
    if (mask.i8[i] < 0)
      mem_addr[i] = a.i8[i];
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
void
simde_m_maskmovq (simde__m64 a, simde__m64 mask, char* mem_addr) {
#if defined(SIMDE_SSE_NATIVE)
  _m_maskmovq(a.n, mask.n, mem_addr);
#else
  simde_mm_maskmove_si64(a, mask, mem_addr);
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_mm_max_pi16 (simde__m64 a, simde__m64 b) {
#if defined(SIMDE_SSE_NATIVE)
  return SIMDE__M64_C(_mm_max_pi16(a.n, b.n));
#else
  simde__m64 r;
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.i16) / sizeof(r.i16[0])) ; i++) {
    r.i16[i] = (a.i16[i] > b.i16[i]) ? a.i16[i] : b.i16[i];
  }
  return r;
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m128
simde_mm_max_ps (simde__m128 a, simde__m128 b) {
#if defined(SIMDE_SSE_NATIVE)
  return SIMDE__M128_C(_mm_max_ps(a.n, b.n));
#else
  simde__m128 r;
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.f32) / sizeof(r.f32[0])) ; i++) {
    r.f32[i] = (a.f32[i] > b.f32[i]) ? a.f32[i] : b.f32[i];
  }
  return r;
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_mm_max_pu8 (simde__m64 a, simde__m64 b) {
#if defined(SIMDE_SSE_NATIVE)
  return SIMDE__M64_C(_mm_max_pu8(a.n, b.n));
#else
  simde__m64 r;
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.u8) / sizeof(r.u8[0])) ; i++) {
    r.u8[i] = (a.u8[i] > b.u8[i]) ? a.u8[i] : b.u8[i];
  }
  return r;
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m128
simde_mm_max_ss (simde__m128 a, simde__m128 b) {
#if defined(SIMDE_SSE_NATIVE)
  return SIMDE__M128_C(_mm_max_ss(a.n, b.n));
#else
  simde__m128 r;
  r.f32[0] = (a.f32[0] > b.f32[0]) ? a.f32[0] : b.f32[0];
  r.f32[1] = a.f32[1];
  r.f32[2] = a.f32[2];
  r.f32[3] = a.f32[3];
  return r;
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_mm_min_pi16 (simde__m64 a, simde__m64 b) {
#if defined(SIMDE_SSE_NATIVE)
  return SIMDE__M64_C(_mm_min_pi16(a.n, b.n));
#else
  simde__m64 r;
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.i16) / sizeof(r.i16[0])) ; i++) {
    r.i16[i] = (a.i16[i] < b.i16[i]) ? a.i16[i] : b.i16[i];
  }
  return r;
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m128
simde_mm_min_ps (simde__m128 a, simde__m128 b) {
#if defined(SIMDE_SSE_NATIVE)
  return SIMDE__M128_C(_mm_min_ps(a.n, b.n));
#else
  simde__m128 r;
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.f32) / sizeof(r.f32[0])) ; i++) {
    r.f32[i] = (a.f32[i] < b.f32[i]) ? a.f32[i] : b.f32[i];
  }
  return r;
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_mm_min_pu8 (simde__m64 a, simde__m64 b) {
#if defined(SIMDE_SSE_NATIVE)
  return SIMDE__M64_C(_mm_min_pu8(a.n, b.n));
#else
  simde__m64 r;
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.u8) / sizeof(r.u8[0])) ; i++) {
    r.u8[i] = (a.u8[i] < b.u8[i]) ? a.u8[i] : b.u8[i];
  }
  return r;
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m128
simde_mm_min_ss (simde__m128 a, simde__m128 b) {
#if defined(SIMDE_SSE_NATIVE)
  return SIMDE__M128_C(_mm_min_ss(a.n, b.n));
#else
  simde__m128 r;
  r.f32[0] = (a.f32[0] < b.f32[0]) ? a.f32[0] : b.f32[0];
  r.f32[1] = a.f32[1];
  r.f32[2] = a.f32[2];
  r.f32[3] = a.f32[3];
  return r;
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m128
simde_mm_move_ss (simde__m128 a, simde__m128 b) {
#if defined(SIMDE_SSE_NATIVE)
  return SIMDE__M128_C(_mm_move_ss(a.n, b.n));
#else
  simde__m128 r;
  r.f32[0] = b.f32[0];
  r.f32[1] = a.f32[1];
  r.f32[2] = a.f32[2];
  r.f32[3] = a.f32[3];
  return r;
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m128
simde_mm_movehl_ps (simde__m128 a, simde__m128 b) {
#if defined(SIMDE_SSE_NATIVE)
  return SIMDE__M128_C(_mm_movehl_ps(a.n, b.n));
#else
  simde__m128 r;
  r.f32[0] = b.f32[2];
  r.f32[1] = b.f32[3];
  r.f32[2] = a.f32[2];
  r.f32[3] = a.f32[3];
  return r;
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m128
simde_mm_movelh_ps (simde__m128 a, simde__m128 b) {
#if defined(SIMDE_SSE_NATIVE)
  return SIMDE__M128_C(_mm_movelh_ps(a.n, b.n));
#else
  simde__m128 r;
  r.f32[0] = a.f32[0];
  r.f32[1] = a.f32[1];
  r.f32[2] = b.f32[0];
  r.f32[3] = b.f32[1];
  return r;
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m128
simde_mm_mul_ps (simde__m128 a, simde__m128 b) {
#if defined(SIMDE_SSE_NATIVE)
  return SIMDE__M128_C(_mm_mul_ps(a.n, b.n));
#else
  simde__m128 r;
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.f32) / sizeof(r.f32[0])) ; i++) {
    r.f32[i] = a.f32[i] * b.f32[i];
  }
  return r;
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m128
simde_mm_sub_ps (simde__m128 a, simde__m128 b) {
#if defined(SIMDE_SSE_NATIVE)
  return SIMDE__M128_C(_mm_sub_ps(a.n, b.n));
#else
  simde__m128 r;
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.f32) / sizeof(r.f32[0])) ; i++) {
    r.f32[i] = a.f32[i] - b.f32[i];
  }
  return r;
#endif
}

#endif /* !defined(SIMDE__SSE_H) */
