/* Copyright (c) 2017-2019 Evan Nemerson <evan@nemerson.com>
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

#if !defined(SIMDE__MMX_H)
#  if !defined(SIMDE__MMX_H)
#    define SIMDE__MMX_H
#  endif
#  include "../simde-common.h"

#  if defined(SIMDE_MMX_FORCE_NATIVE)
#    define SIMDE_MMX_NATIVE
#  elif (defined(__MMX__) || (defined(_MSC_VER) && defined(_M_IX86))) && !defined(SIMDE_MMX_NO_NATIVE) && !defined(SIMDE_NO_NATIVE)
#    define SIMDE_MMX_NATIVE
#  elif defined(__ARM_NEON) && !defined(SIMDE_MMX_NO_NEON) && !defined(SIMDE_NO_NEON)
#    define SIMDE_MMX_NEON
#  endif

#  if defined(SIMDE_MMX_NATIVE)
#    include <mmintrin.h>
#  else
#    if defined(SIMDE_MMX_NEON)
#      include <arm_neon.h>
#    endif
#  endif
#  include <stdint.h>
#  include <limits.h>
#  include <stdlib.h>
#  include <string.h>

SIMDE__BEGIN_DECLS

typedef union {
#if defined(SIMDE__ENABLE_GCC_VEC_EXT)
  SIMDE_ALIGN(8) int8_t          i8 __attribute__((__vector_size__(8), __may_alias__));
  SIMDE_ALIGN(8) int16_t        i16 __attribute__((__vector_size__(8), __may_alias__));
  SIMDE_ALIGN(8) int32_t        i32 __attribute__((__vector_size__(8), __may_alias__));
  SIMDE_ALIGN(8) int64_t        i64 __attribute__((__vector_size__(8), __may_alias__));
  SIMDE_ALIGN(8) uint8_t         u8 __attribute__((__vector_size__(8), __may_alias__));
  SIMDE_ALIGN(8) uint16_t       u16 __attribute__((__vector_size__(8), __may_alias__));
  SIMDE_ALIGN(8) uint32_t       u32 __attribute__((__vector_size__(8), __may_alias__));
  SIMDE_ALIGN(8) uint64_t       u64 __attribute__((__vector_size__(8), __may_alias__));
  SIMDE_ALIGN(8) simde_float32  f32 __attribute__((__vector_size__(8), __may_alias__));
  SIMDE_ALIGN(8) int_fast32_t  i32f __attribute__((__vector_size__(8), __may_alias__));
  SIMDE_ALIGN(8) uint_fast32_t u32f __attribute__((__vector_size__(8), __may_alias__));
#else
  SIMDE_ALIGN(8) int8_t          i8[8];
  SIMDE_ALIGN(8) int16_t        i16[4];
  SIMDE_ALIGN(8) int32_t        i32[2];
  SIMDE_ALIGN(8) int64_t        i64[1];
  SIMDE_ALIGN(8) uint8_t         u8[8];
  SIMDE_ALIGN(8) uint16_t       u16[4];
  SIMDE_ALIGN(8) uint32_t       u32[2];
  SIMDE_ALIGN(8) uint64_t       u64[1];
  SIMDE_ALIGN(8) simde_float32  f32[2];
  SIMDE_ALIGN(8) int_fast32_t  i32f[8 / sizeof(int_fast32_t)];
  SIMDE_ALIGN(8) uint_fast32_t u32f[8 / sizeof(uint_fast32_t)];
#endif

#if defined(SIMDE_MMX_NATIVE)
  __m64          n;
#elif defined(SIMDE_MMX_NEON)
  int8x8_t       neon_i8;
  int16x4_t      neon_i16;
  int32x2_t      neon_i32;
  int64x1_t      neon_i64;
  uint8x8_t      neon_u8;
  uint16x4_t     neon_u16;
  uint32x2_t     neon_u32;
  uint64x1_t     neon_u64;
  float32x2_t    neon_f32;
#endif
} simde__m64;

#if !defined(SIMDE_MMX_NATIVE) && defined(SIMDE_ENABLE_NATIVE_ALIASES)
#  define SIMDE_MMX_ENABLE_NATIVE_ALIASES
   typedef simde__m64 __m64;
#endif

#if defined(SIMDE_MMX_NATIVE)
  HEDLEY_STATIC_ASSERT(sizeof(__m64) == sizeof(simde__m64), "__m64 size doesn't match simde__m64 size");
#endif
HEDLEY_STATIC_ASSERT(8 == sizeof(simde__m64), "__m64 size incorrect");

#if defined(SIMDE_ALIGN_OF)
HEDLEY_STATIC_ASSERT(SIMDE_ALIGN_OF(simde__m64) == 8, "__m64 is not 8-byte aligned");
#endif

HEDLEY_DIAGNOSTIC_PUSH

/* Function has no EMMS instruction */
#if defined(HEDLEY_MSVC_VERSION)
#pragma warning(disable:4799)
#endif

#if defined(SIMDE_MMX_NATIVE)
   SIMDE__FUNCTION_ATTRIBUTES simde__m64 SIMDE__M64_FROM_NATIVE(__m64 v) { simde__m64 r; r.n = v; return r; }
#  define SIMDE__M64_TO_NATIVE(v) (v.n)
#else
#  define SIMDE__M64_FROM_NATIVE(val) (val)
#  define SIMDE__M64_TO_NATIVE(val) (val)
#endif

#if defined(SIMDE_MMX_NEON)
#  define SIMDE__M64_FROM_NEON(T, expr) ((simde__m64) { .neon_##T = (expr) })
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_mm_add_pi8 (simde__m64 a, simde__m64 b) {
  simde__m64 r;

#if defined(SIMDE_MMX_NATIVE)
  r.n = _mm_add_pi8(a.n, b.n);
#elif defined(SIMDE_MMX_NEON)
  r.neon_i8 = vadd_s8(a.neon_i8, b.neon_i8);
#elif defined(SIMDE__ENABLE_GCC_VEC_EXT)
  r.i8 = a.i8 + b.i8;
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.i8) / sizeof(r.i8[0])) ; i++) {
    r.i8[i] = a.i8[i] + b.i8[i];
  }
#endif

  return r;
}
#define simde_m_paddb(a, b) simde_mm_add_pi8(a, b)
#if defined(SIMDE_MMX_ENABLE_NATIVE_ALIASES)
#  define _mm_add_pi8(a, b) SIMDE__M64_TO_NATIVE(simde_mm_add_pi8(SIMDE__M64_FROM_NATIVE(a), SIMDE__M64_FROM_NATIVE(b)))
#  define _m_add_paddb(a, b) SIMDE__M64_TO_NATIVE(simde_mm_add_pi8(SIMDE__M64_FROM_NATIVE(a), SIMDE__M64_FROM_NATIVE(b)))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_mm_add_pi16 (simde__m64 a, simde__m64 b) {
#if defined(SIMDE_MMX_NATIVE)
  return SIMDE__M64_FROM_NATIVE(_mm_add_pi16(a.n, b.n));
#else
  simde__m64 r;

#if defined(SIMDE_MMX_NEON)
  r.neon_i16 = vadd_s16(a.neon_i16, b.neon_i16);
#elif defined(SIMDE__ENABLE_GCC_VEC_EXT)
  r.i16 = a.i16 + b.i16;
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.i16) / sizeof(r.i16[0])) ; i++) {
    r.i16[i] = a.i16[i] + b.i16[i];
  }
#endif

  return r;
#endif
}
#define simde_m_paddw(a, b) simde_mm_add_pi16(a, b)
#if defined(SIMDE_MMX_ENABLE_NATIVE_ALIASES)
#  define _mm_add_pi16(a, b) SIMDE__M64_TO_NATIVE(simde_mm_add_pi16(SIMDE__M64_FROM_NATIVE(a), SIMDE__M64_FROM_NATIVE(b)))
#  define _m_add_paddw(a, b) SIMDE__M64_TO_NATIVE(simde_mm_add_pi16(SIMDE__M64_FROM_NATIVE(a), SIMDE__M64_FROM_NATIVE(b)))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_mm_add_pi32 (simde__m64 a, simde__m64 b) {
#if defined(SIMDE_MMX_NATIVE)
  return SIMDE__M64_FROM_NATIVE(_mm_add_pi32(a.n, b.n));
#else
  simde__m64 r;

#if defined(SIMDE_MMX_NEON)
  r.neon_i32 = vadd_s32(a.neon_i32, b.neon_i32);
#elif defined(SIMDE__ENABLE_GCC_VEC_EXT)
  r.i32 = a.i32 + b.i32;
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.i32) / sizeof(r.i32[0])) ; i++) {
    r.i32[i] = a.i32[i] + b.i32[i];
  }
#endif

  return r;
#endif
}
#define simde_m_paddd(a, b) simde_mm_add_pi32(a, b)
#if defined(SIMDE_MMX_ENABLE_NATIVE_ALIASES)
#  define _mm_add_pi32(a, b) SIMDE__M64_TO_NATIVE(simde_mm_add_pi32(SIMDE__M64_FROM_NATIVE(a), SIMDE__M64_FROM_NATIVE(b)))
#  define _m_add_paddd(a, b) SIMDE__M64_TO_NATIVE(simde_mm_add_pi32(SIMDE__M64_FROM_NATIVE(a), SIMDE__M64_FROM_NATIVE(b)))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_mm_adds_pi8 (simde__m64 a, simde__m64 b) {
#if defined(SIMDE_MMX_NATIVE)
  return SIMDE__M64_FROM_NATIVE(_mm_adds_pi8(a.n, b.n));
#else
  simde__m64 r;

#if defined(SIMDE_MMX_NEON)
  r.neon_i8 = vqadd_s8(a.neon_i8, b.neon_i8);
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.i8) / sizeof(r.i8[0])) ; i++) {
    if ((((b.i8[i]) > 0) && ((a.i8[i]) > (INT8_MAX - (b.i8[i]))))) {
      r.i8[i] = INT8_MAX;
    } else if ((((b.i8[i]) < 0) && ((a.i8[i]) < (INT8_MIN - (b.i8[i]))))) {
      r.i8[i] = INT8_MIN;
    } else {
      r.i8[i] = (a.i8[i]) + (b.i8[i]);
    }
  }
#endif

  return r;
#endif
}
#define simde_m_paddsb(a, b) simde_mm_adds_pi8(a, b)
#if defined(SIMDE_MMX_ENABLE_NATIVE_ALIASES)
#  define _mm_adds_pi8(a, b) SIMDE__M64_TO_NATIVE(simde_mm_adds_pi8(SIMDE__M64_FROM_NATIVE(a), SIMDE__M64_FROM_NATIVE(b)))
#  define _m_add_paddsb(a, b) SIMDE__M64_TO_NATIVE(simde_mm_adds_pi8(SIMDE__M64_FROM_NATIVE(a), SIMDE__M64_FROM_NATIVE(b)))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_mm_adds_pu8 (simde__m64 a, simde__m64 b) {
#if defined(SIMDE_MMX_NATIVE)
  return SIMDE__M64_FROM_NATIVE(_mm_adds_pu8(a.n, b.n));
#else
  simde__m64 r;

#if defined(SIMDE_MMX_NEON)
  r.neon_u8 = vqadd_u8(a.neon_u8, b.neon_u8);
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.u8) / sizeof(r.u8[0])) ; i++) {
    const uint_fast16_t x = ((uint_fast16_t) a.u8[i]) + ((uint_fast16_t) b.u8[i]);
    if (x > UINT8_MAX)
      r.u8[i] = UINT8_MAX;
    else
      r.u8[i] = (uint8_t) x;
  }
#endif

  return r;
#endif
}
#define simde_m_paddusb(a, b) simde_mm_adds_pu8(a, b)
#if defined(SIMDE_MMX_ENABLE_NATIVE_ALIASES)
#  define _mm_adds_pu8(a, b) SIMDE__M64_TO_NATIVE(simde_mm_adds_pu8(SIMDE__M64_FROM_NATIVE(a), SIMDE__M64_FROM_NATIVE(b)))
#  define _m_paddusb(a, b) SIMDE__M64_TO_NATIVE(simde_mm_adds_pu8(SIMDE__M64_FROM_NATIVE(a), SIMDE__M64_FROM_NATIVE(b)))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_mm_adds_pi16 (simde__m64 a, simde__m64 b) {
#if defined(SIMDE_MMX_NATIVE)
  return SIMDE__M64_FROM_NATIVE(_mm_adds_pi16(a.n, b.n));
#else
  simde__m64 r;

#if defined(SIMDE_MMX_NEON)
  r.neon_i16 = vqadd_s16(a.neon_i16, b.neon_i16);
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.i16) / sizeof(r.i16[0])) ; i++) {
    if ((((b.i16[i]) > 0) && ((a.i16[i]) > (INT16_MAX - (b.i16[i]))))) {
      r.i16[i] = INT16_MAX;
    } else if ((((b.i16[i]) < 0) && ((a.i16[i]) < (SHRT_MIN - (b.i16[i]))))) {
      r.i16[i] = SHRT_MIN;
    } else {
      r.i16[i] = (a.i16[i]) + (b.i16[i]);
    }
  }
#endif

  return r;
#endif
}
#define simde_m_paddsw(a, b) simde_mm_adds_pi16(a, b)
#if defined(SIMDE_MMX_ENABLE_NATIVE_ALIASES)
#  define _mm_adds_pi16(a, b) SIMDE__M64_TO_NATIVE(simde_mm_adds_pi16(SIMDE__M64_FROM_NATIVE(a), SIMDE__M64_FROM_NATIVE(b)))
#  define _m_paddsw(a, b) SIMDE__M64_TO_NATIVE(simde_mm_adds_pi16(SIMDE__M64_FROM_NATIVE(a), SIMDE__M64_FROM_NATIVE(b)))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_mm_adds_pu16 (simde__m64 a, simde__m64 b) {
#if defined(SIMDE_MMX_NATIVE)
  return SIMDE__M64_FROM_NATIVE(_mm_adds_pu16(a.n, b.n));
#else
  simde__m64 r;

#if defined(SIMDE_MMX_NEON)
  r.neon_u16 = vqadd_u16(a.neon_u16, b.neon_u16);
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.i16) / sizeof(r.i16[0])) ; i++) {
    const uint32_t x = a.u16[i] + b.u16[i];
    if (x > UINT16_MAX)
      r.u16[i] = UINT16_MAX;
    else
      r.u16[i] = (uint16_t) x;
  }
#endif

  return r;
#endif
}
#define simde_m_paddusw(a, b) simde_mm_adds_pu16(a, b)
#if defined(SIMDE_MMX_ENABLE_NATIVE_ALIASES)
#  define _mm_adds_pu16(a, b) SIMDE__M64_TO_NATIVE(simde_mm_adds_pu16(SIMDE__M64_FROM_NATIVE(a), SIMDE__M64_FROM_NATIVE(b)))
#  define _m_paddusw(a, b) SIMDE__M64_TO_NATIVE(simde_mm_adds_pu16(SIMDE__M64_FROM_NATIVE(a), SIMDE__M64_FROM_NATIVE(b)))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_mm_and_si64 (simde__m64 a, simde__m64 b) {
#if defined(SIMDE_MMX_NATIVE)
  return SIMDE__M64_FROM_NATIVE(_mm_and_si64(a.n, b.n));
#else
  simde__m64 r;

#if defined(SIMDE_MMX_NEON)
  r.neon_i32 = vand_s32(a.neon_i32, b.neon_i32);
#elif defined(SIMDE__ENABLE_GCC_VEC_EXT)
  r.i64 = a.i64 & b.i64;
#else
  r.i64[0] = a.i64[0] & b.i64[0];
#endif

  return r;
#endif
}
#define simde_m_pand(a, b) simde_mm_and_si64(a, b)
#if defined(SIMDE_MMX_ENABLE_NATIVE_ALIASES)
#  define _mm_and_si64(a, b) SIMDE__M64_TO_NATIVE(simde_mm_and_si64(SIMDE__M64_FROM_NATIVE(a), SIMDE__M64_FROM_NATIVE(b)))
#  define _m_pand(a, b) SIMDE__M64_TO_NATIVE(simde_mm_and_si64(SIMDE__M64_FROM_NATIVE(a), SIMDE__M64_FROM_NATIVE(b)))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_mm_andnot_si64 (simde__m64 a, simde__m64 b) {
#if defined(SIMDE_MMX_NATIVE)
  return SIMDE__M64_FROM_NATIVE(_mm_andnot_si64(a.n, b.n));
#else
  simde__m64 r;

#if defined(SIMDE_MMX_NEON)
  r.neon_i32 = vbic_s32(b.neon_i32, a.neon_i32);
#elif defined(SIMDE__ENABLE_GCC_VEC_EXT)
  r.i32f = ~a.i32f & b.i32f;
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.i32f) / sizeof(r.i32f[0])) ; i++) {
    r.i32f[0] = ~(a.i32f[0]) & b.i32f[0];
  }
#endif

  return r;
#endif
}
#define simde_m_pandn(a, b) simde_mm_andnot_si64(a, b)
#if defined(SIMDE_MMX_ENABLE_NATIVE_ALIASES)
#  define _mm_andnot_si64(a, b) SIMDE__M64_TO_NATIVE(simde_mm_andnot_si64(SIMDE__M64_FROM_NATIVE(a), SIMDE__M64_FROM_NATIVE(b)))
#  define _m_pandn(a, b) SIMDE__M64_TO_NATIVE(simde_mm_andnot_si64(SIMDE__M64_FROM_NATIVE(a), SIMDE__M64_FROM_NATIVE(b)))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_mm_cmpeq_pi8 (simde__m64 a, simde__m64 b) {
#if defined(SIMDE_MMX_NATIVE)
  return SIMDE__M64_FROM_NATIVE(_mm_cmpeq_pi8(a.n, b.n));
#else
  simde__m64 r;

#if defined(SIMDE_MMX_NEON)
  r.neon_i8 = vreinterpret_s8_u8(vceq_s8(a.neon_i8, b.neon_i8));
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.i8) / sizeof(r.i8[0])) ; i++) {
    r.i8[i] = (a.i8[i] == b.i8[i]) ? ~INT8_C(0) : INT8_C(0);
  }
#endif

  return r;
#endif
}
#define simde_m_pcmpeqb(a, b) simde_mm_cmpeq_pi8(a, b)
#if defined(SIMDE_MMX_ENABLE_NATIVE_ALIASES)
#  define _mm_cmpeq_pi8(a, b) SIMDE__M64_TO_NATIVE(simde_mm_cmpeq_pi8(SIMDE__M64_FROM_NATIVE(a), SIMDE__M64_FROM_NATIVE(b)))
#  define _m_pcmpeqb(a, b) SIMDE__M64_TO_NATIVE(simde_mm_cmpeq_pi8(SIMDE__M64_FROM_NATIVE(a), SIMDE__M64_FROM_NATIVE(b)))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_mm_cmpeq_pi16 (simde__m64 a, simde__m64 b) {
#if defined(SIMDE_MMX_NATIVE)
  return SIMDE__M64_FROM_NATIVE(_mm_cmpeq_pi16(a.n, b.n));
#else
  simde__m64 r;

#if defined(SIMDE_MMX_NEON)
  r.neon_i16 = vreinterpret_s16_u16(vceq_s16(a.neon_i16, b.neon_i16));
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.i16) / sizeof(r.i16[0])) ; i++) {
    r.i16[i] = (a.i16[i] == b.i16[i]) ? ~INT16_C(0) : INT16_C(0);
  }
#endif

  return r;
#endif
}
#define simde_m_pcmpeqw(a, b) simde_mm_cmpeq_pi16(a, b)
#if defined(SIMDE_MMX_ENABLE_NATIVE_ALIASES)
#  define _mm_cmpeq_pi16(a, b) SIMDE__M64_TO_NATIVE(simde_mm_cmpeq_pi16(SIMDE__M64_FROM_NATIVE(a), SIMDE__M64_FROM_NATIVE(b)))
#  define _m_pcmpeqw(a, b) SIMDE__M64_TO_NATIVE(simde_mm_cmpeq_pi16(SIMDE__M64_FROM_NATIVE(a), SIMDE__M64_FROM_NATIVE(b)))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_mm_cmpeq_pi32 (simde__m64 a, simde__m64 b) {
#if defined(SIMDE_MMX_NATIVE)
  return SIMDE__M64_FROM_NATIVE(_mm_cmpeq_pi32(a.n, b.n));
#else
  simde__m64 r;

#if defined(SIMDE_MMX_NEON)
  r.neon_i32 = vreinterpret_s32_u32(vceq_s32(a.neon_i32, b.neon_i32));
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.i32) / sizeof(r.i32[0])) ; i++) {
    r.i32[i] = (a.i32[i] == b.i32[i]) ? ~INT32_C(0) : INT32_C(0);
  }
#endif

  return r;
#endif
}
#define simde_m_pcmpeqd(a, b) simde_mm_cmpeq_pi32(a, b)
#if defined(SIMDE_MMX_ENABLE_NATIVE_ALIASES)
#  define _mm_cmpeq_pi32(a, b) SIMDE__M64_TO_NATIVE(simde_mm_cmpeq_pi32(SIMDE__M64_FROM_NATIVE(a), SIMDE__M64_FROM_NATIVE(b)))
#  define _m_pcmpeqd(a, b) SIMDE__M64_TO_NATIVE(simde_mm_cmpeq_pi32(SIMDE__M64_FROM_NATIVE(a), SIMDE__M64_FROM_NATIVE(b)))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_mm_cmpgt_pi8 (simde__m64 a, simde__m64 b) {
#if defined(SIMDE_MMX_NATIVE)
  return SIMDE__M64_FROM_NATIVE(_mm_cmpgt_pi8(a.n, b.n));
#else
  simde__m64 r;

#if defined(SIMDE_MMX_NEON)
  r.neon_i8 = vreinterpret_s8_u8(vcgt_s8(a.neon_i8, b.neon_i8));
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.i8) / sizeof(r.i8[0])) ; i++) {
    r.i8[i] = (a.i8[i] > b.i8[i]) ? ~INT8_C(0) : INT8_C(0);
  }
#endif

  return r;
#endif
}
#define simde_m_pcmpgtb(a, b) simde_mm_cmpgt_pi8(a, b)
#if defined(SIMDE_MMX_ENABLE_NATIVE_ALIASES)
#  define _mm_cmpgt_pi8(a, b) SIMDE__M64_TO_NATIVE(simde_mm_cmpgt_pi8(SIMDE__M64_FROM_NATIVE(a), SIMDE__M64_FROM_NATIVE(b)))
#  define _m_pcmpgtb(a, b) SIMDE__M64_TO_NATIVE(simde_mm_cmpgt_pi8(SIMDE__M64_FROM_NATIVE(a), SIMDE__M64_FROM_NATIVE(b)))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_mm_cmpgt_pi16 (simde__m64 a, simde__m64 b) {
#if defined(SIMDE_MMX_NATIVE)
  return SIMDE__M64_FROM_NATIVE(_mm_cmpgt_pi16(a.n, b.n));
#else
  simde__m64 r;

#if defined(SIMDE_MMX_NEON)
  r.neon_i16 = vreinterpret_s16_u16(vcgt_s16(a.neon_i16, b.neon_i16));
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.i16) / sizeof(r.i16[0])) ; i++) {
    r.i16[i] = (a.i16[i] > b.i16[i]) ? ~INT16_C(0) : INT16_C(0);
  }
#endif

  return r;
#endif
}
#define simde_m_pcmpgtw(a, b) simde_mm_cmpgt_pi16(a, b)
#if defined(SIMDE_MMX_ENABLE_NATIVE_ALIASES)
#  define _mm_cmpgt_pi16(a, b) SIMDE__M64_TO_NATIVE(simde_mm_cmpgt_pi16(SIMDE__M64_FROM_NATIVE(a), SIMDE__M64_FROM_NATIVE(b)))
#  define _m_pcmpgtw(a, b) SIMDE__M64_TO_NATIVE(simde_mm_cmpgt_pi16(SIMDE__M64_FROM_NATIVE(a), SIMDE__M64_FROM_NATIVE(b)))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_mm_cmpgt_pi32 (simde__m64 a, simde__m64 b) {
#if defined(SIMDE_MMX_NATIVE)
  return SIMDE__M64_FROM_NATIVE(_mm_cmpgt_pi32(a.n, b.n));
#else
  simde__m64 r;

#if defined(SIMDE_MMX_NEON)
  r.neon_i32 = vreinterpret_s32_u32(vcgt_s32(a.neon_i32, b.neon_i32));
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.i32) / sizeof(r.i32[0])) ; i++) {
    r.i32[i] = (a.i32[i] > b.i32[i]) ? ~INT32_C(0) : INT32_C(0);
  }
#endif

  return r;
#endif
}
#define simde_m_pcmpgtd(a, b) simde_mm_cmpgt_pi32(a, b)
#if defined(SIMDE_MMX_ENABLE_NATIVE_ALIASES)
#  define _mm_cmpgt_pi32(a, b) SIMDE__M64_TO_NATIVE(simde_mm_cmpgt_pi32(SIMDE__M64_FROM_NATIVE(a), SIMDE__M64_FROM_NATIVE(b)))
#  define _m_pcmpgtd(a, b) SIMDE__M64_TO_NATIVE(simde_mm_cmpgt_pi32(SIMDE__M64_FROM_NATIVE(a), SIMDE__M64_FROM_NATIVE(b)))
#endif

SIMDE__FUNCTION_ATTRIBUTES
int64_t
simde_mm_cvtm64_si64 (simde__m64 a) {
#if defined(SIMDE_MMX_NATIVE) && defined(SIMDE_ARCH_AMD64) && !defined(__PGI)
  return _mm_cvtm64_si64(a.n);
#elif defined(SIMDE_MMX_NEON)
  return vget_lane_s64(a.neon_i64, 0);
#else
  return a.i64[0];
#endif
}
#define simde_m_to_int64(a) simde_mm_cvtm64_si64(a)
#if defined(SIMDE_MMX_ENABLE_NATIVE_ALIASES)
#  define _mm_cvtm64_si64(a) simde_mm_cvtm64_si64(SIMDE__M64_FROM_NATIVE(a))
#  define _m_to_int64(a) simde_mm_cvtm64_si64(SIMDE__M64_FROM_NATIVE(a))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_mm_cvtsi32_si64 (int32_t a) {
#if defined(SIMDE_MMX_NATIVE)
  return SIMDE__M64_FROM_NATIVE(_mm_cvtsi32_si64(a));
#else
  simde__m64 r;

#if defined(SIMDE_MMX_NEON)
  const int32_t av[sizeof(r.neon_i32) / sizeof(r.neon_i32[0])] = { a, 0 };
  r.neon_i32 = vld1_s32(av);
#else
  r.i32[0] = a;
  r.i32[1] = 0;
#endif

  return r;
#endif
}
#define simde_m_from_int(a) simde_mm_cvtsi32_si64(a)
#if defined(SIMDE_MMX_ENABLE_NATIVE_ALIASES)
#  define _mm_cvtsi32_si64(a) SIMDE__M64_TO_NATIVE(simde_mm_cvtsi32_si64(a))
#  define _m_from_int(a) SIMDE__M64_TO_NATIVE(simde_mm_cvtsi32_si64(a))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_mm_cvtsi64_m64 (int64_t a) {
#if defined(SIMDE_MMX_NATIVE) && defined(SIMDE_ARCH_AMD64) && !defined(__PGI)
  return SIMDE__M64_FROM_NATIVE(_mm_cvtsi64_m64(a));
#else
  simde__m64 r;

#if defined(SIMDE_MMX_NEON)
  r.neon_i64 = vld1_s64(&a);
#else
  r.i64[0] = a;
#endif

  return r;
#endif
}
#define simde_m_from_int64(a) simde_mm_cvtsi64_m64(a)
#if defined(SIMDE_MMX_ENABLE_NATIVE_ALIASES)
#  define _mm_cvtsi64_m64(a) SIMDE__M64_TO_NATIVE(simde_mm_cvtsi64_m64(a))
#  define _m_from_int64(a) SIMDE__M64_TO_NATIVE(simde_mm_cvtsi64_m64(a))
#endif

SIMDE__FUNCTION_ATTRIBUTES
int32_t
simde_mm_cvtsi64_si32 (simde__m64 a) {
#if defined(SIMDE_MMX_NATIVE)
  return _mm_cvtsi64_si32(a.n);
#elif defined(SIMDE_MMX_NEON)
  return vget_lane_s32(a.neon_i32, 0);
#else
  return a.i32[0];
#endif
}
#if defined(SIMDE_MMX_ENABLE_NATIVE_ALIASES)
#  define _mm_cvtsi64_si32(a) simde_mm_cvtsi64_si32(SIMDE__M64_FROM_NATIVE(a))
#endif

SIMDE__FUNCTION_ATTRIBUTES
void
simde_mm_empty (void) {
#if defined(SIMDE_MMX_NATIVE)
  _mm_empty();
#else
#endif
}
#define simde_m_empty() simde_mm_empty()
#if defined(SIMDE_MMX_ENABLE_NATIVE_ALIASES)
#  define _mm_empty() SIMDE__M64_TO_NATIVE(simde_mm_empty())
#  define _m_empty() SIMDE__M64_TO_NATIVE(simde_mm_empty())
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_mm_madd_pi16 (simde__m64 a, simde__m64 b) {
#if defined(SIMDE_MMX_NATIVE)
  return SIMDE__M64_FROM_NATIVE(_mm_madd_pi16(a.n, b.n));
#else
  simde__m64 r;

#if defined(SIMDE_MMX_NEON)
  int32x4_t i1 = vmull_s16(a.neon_i16, b.neon_i16);
  r.neon_i32 = vpadd_s32(vget_low_s32(i1), vget_high_s32(i1));
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.i16) / sizeof(r.i16[0])) ; i += 2) {
    r.i32[i / 2] = (a.i16[i] * b.i16[i]) + (a.i16[i + 1] * b.i16[i + 1]);
  }
#endif

  return r;
#endif
}
#define simde_m_pmaddwd(a, b) simde_mm_madd_pi16(a, b)
#if defined(SIMDE_MMX_ENABLE_NATIVE_ALIASES)
#  define _mm_madd_pi16(a, b) SIMDE__M64_TO_NATIVE(simde_mm_madd_pi16(SIMDE__M64_FROM_NATIVE(a), SIMDE__M64_FROM_NATIVE(b)))
#  define _m_pmaddwd(a, b) SIMDE__M64_TO_NATIVE(simde_mm_madd_pi16(SIMDE__M64_FROM_NATIVE(a), SIMDE__M64_FROM_NATIVE(b)))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_mm_mulhi_pi16 (simde__m64 a, simde__m64 b) {
#if defined(SIMDE_MMX_NATIVE)
  return SIMDE__M64_FROM_NATIVE(_mm_mulhi_pi16(a.n, b.n));
#else
  simde__m64 r;

#if defined(SIMDE_MMX_NEON)
  const int32x4_t t1 = vmull_s16(a.neon_i16, b.neon_i16);
  const uint32x4_t t2 = vshrq_n_u32(vreinterpretq_u32_s32(t1), 16);
  const uint16x4_t t3 = vmovn_u32(t2);
  r.neon_i16 = vreinterpret_s16_u16(t3);
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.i16) / sizeof(r.i16[0])) ; i++) {
    r.i16[i] = (int16_t) ((a.i16[i] * b.i16[i]) >> 16);
  }
#endif

  return r;
#endif
}
#define simde_m_pmulhw(a, b) simde_mm_mulhi_pi16(a, b)
#if defined(SIMDE_MMX_ENABLE_NATIVE_ALIASES)
#  define _mm_mulhi_pi16(a, b) SIMDE__M64_TO_NATIVE(simde_mm_mulhi_pi16(SIMDE__M64_FROM_NATIVE(a), SIMDE__M64_FROM_NATIVE(b)))
#  define _m_pmulhw(a, b) SIMDE__M64_TO_NATIVE(simde_mm_mulhi_pi16(SIMDE__M64_FROM_NATIVE(a), SIMDE__M64_FROM_NATIVE(b)))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_mm_mullo_pi16 (simde__m64 a, simde__m64 b) {
#if defined(SIMDE_MMX_NATIVE)
  return SIMDE__M64_FROM_NATIVE(_mm_mullo_pi16(a.n, b.n));
#else
  simde__m64 r;

#if defined(SIMDE_MMX_NEON)
  const int32x4_t t1 = vmull_s16(a.neon_i16, b.neon_i16);
  const uint16x4_t t2 = vmovn_u32(vreinterpretq_u32_s32(t1));
  r.neon_i16 = vreinterpret_s16_u16(t2);
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.i16) / sizeof(r.i16[0])) ; i++) {
    r.i16[i] = (int16_t) ((a.i16[i] * b.i16[i]) & 0xffff);
  }
#endif

  return r;
#endif
}
#define simde_m_pmullw(a, b) simde_mm_mullo_pi16(a, b)
#if defined(SIMDE_MMX_ENABLE_NATIVE_ALIASES)
#  define _mm_mullo_pi16(a, b) SIMDE__M64_TO_NATIVE(simde_mm_mullo_pi16(SIMDE__M64_FROM_NATIVE(a), SIMDE__M64_FROM_NATIVE(b)))
#  define _m_pmullw(a, b) SIMDE__M64_TO_NATIVE(simde_mm_mullo_pi16(SIMDE__M64_FROM_NATIVE(a), SIMDE__M64_FROM_NATIVE(b)))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_mm_or_si64 (simde__m64 a, simde__m64 b) {
#if defined(SIMDE_MMX_NATIVE)
  return SIMDE__M64_FROM_NATIVE(_mm_or_si64(a.n, b.n));
#else
  simde__m64 r;

#if defined(SIMDE_MMX_NEON)
  r.neon_i32 = vorr_s32(a.neon_i32, b.neon_i32);
#elif defined(SIMDE__ENABLE_GCC_VEC_EXT)
  r.i64 = a.i64 | b.i64;
#else
  r.i64[0] = a.i64[0] | b.i64[0];
#endif

  return r;
#endif
}
#define simde_m_por(a, b) simde_mm_or_si64(a, b)
#if defined(SIMDE_MMX_ENABLE_NATIVE_ALIASES)
#  define _mm_or_si64(a, b) SIMDE__M64_TO_NATIVE(simde_mm_or_si64(SIMDE__M64_FROM_NATIVE(a), SIMDE__M64_FROM_NATIVE(b)))
#  define _m_por(a, b) SIMDE__M64_TO_NATIVE(simde_mm_or_si64(SIMDE__M64_FROM_NATIVE(a), SIMDE__M64_FROM_NATIVE(b)))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_mm_packs_pi16 (simde__m64 a, simde__m64 b) {
#if defined(SIMDE_MMX_NATIVE)
  return SIMDE__M64_FROM_NATIVE(_mm_packs_pi16(a.n, b.n));
#else
  simde__m64 r;

#if defined(SIMDE_MMX_NEON)
  r.neon_i8 = vqmovn_s16(vcombine_s16(a.neon_i16, b.neon_i16));
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.i16) / sizeof(r.i16[0])) ; i++) {
    if (a.i16[i] < INT8_MIN) {
      r.i8[i] = INT8_MIN;
    } else if (a.i16[i] > INT8_MAX) {
      r.i8[i] = INT8_MAX;
    } else {
      r.i8[i] = (int8_t) a.i16[i];
    }
  }

  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.i16) / sizeof(r.i16[0])) ; i++) {
    if (b.i16[i] < INT8_MIN) {
      r.i8[i + 4] = INT8_MIN;
    } else if (b.i16[i] > INT8_MAX) {
      r.i8[i + 4] = INT8_MAX;
    } else {
      r.i8[i + 4] = (int8_t) b.i16[i];
    }
  }
#endif

  return r;
#endif
}
#define simde_m_packsswb(a, b) simde_mm_packs_pi16(a, b)
#if defined(SIMDE_MMX_ENABLE_NATIVE_ALIASES)
#  define _mm_packs_pi16(a, b) SIMDE__M64_TO_NATIVE(simde_mm_packs_pi16(SIMDE__M64_FROM_NATIVE(a), SIMDE__M64_FROM_NATIVE(b)))
#  define _m_packsswb(a, b) SIMDE__M64_TO_NATIVE(simde_mm_packs_pi16(SIMDE__M64_FROM_NATIVE(a), SIMDE__M64_FROM_NATIVE(b)))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_mm_packs_pi32 (simde__m64 a, simde__m64 b) {
#if defined(SIMDE_MMX_NATIVE)
  return SIMDE__M64_FROM_NATIVE(_mm_packs_pi32(a.n, b.n));
#else
  simde__m64 r;

#if defined(SIMDE_MMX_NEON)
  r.neon_i16 = vqmovn_s32(vcombine_s32(a.neon_i32, b.neon_i32));
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (8 / sizeof(a.i32[0])) ; i++) {
    if (a.i32[i] < SHRT_MIN) {
      r.i16[i] = SHRT_MIN;
    } else if (a.i32[i] > INT16_MAX) {
      r.i16[i] = INT16_MAX;
    } else {
      r.i16[i] = (int16_t) a.i32[i];
    }
  }

  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (8 / sizeof(b.i32[0])) ; i++) {
    if (b.i32[i] < SHRT_MIN) {
      r.i16[i + 2] = SHRT_MIN;
    } else if (b.i32[i] > INT16_MAX) {
      r.i16[i + 2] = INT16_MAX;
    } else {
      r.i16[i + 2] = (int16_t) b.i32[i];
    }
  }
#endif

  return r;
#endif
}
#define simde_m_packssdw(a, b) simde_mm_packs_pi32(a, b)
#if defined(SIMDE_MMX_ENABLE_NATIVE_ALIASES)
#  define _mm_packs_pi32(a, b) SIMDE__M64_TO_NATIVE(simde_mm_packs_pi32(SIMDE__M64_FROM_NATIVE(a), SIMDE__M64_FROM_NATIVE(b)))
#  define _m_packssdw(a, b) SIMDE__M64_TO_NATIVE(simde_mm_packs_pi32(SIMDE__M64_FROM_NATIVE(a), SIMDE__M64_FROM_NATIVE(b)))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_mm_packs_pu16 (simde__m64 a, simde__m64 b) {
#if defined(SIMDE_MMX_NATIVE)
  return SIMDE__M64_FROM_NATIVE(_mm_packs_pu16(a.n, b.n));
#else
  simde__m64 r;

#if defined(SIMDE_MMX_NEON) && defined(SIMDE_ARCH_AARCH64)
  const int16x8_t t1 = vcombine_s16(a.neon_i16, b.neon_i16);

  /* Set elements which are < 0 to 0 */
  const int16x8_t t2 = vandq_s16(t1, vreinterpretq_s16_u16(vcgezq_s16(t1)));

  /* Vector with all s16 elements set to UINT8_MAX */
  const int16x8_t vmax = vmovq_n_s16((int16_t) UINT8_MAX);

  /* Elements which are within the acceptable range */
  const int16x8_t le_max = vandq_s16(t2, vreinterpretq_s16_u16(vcleq_s16(t2, vmax)));
  const int16x8_t gt_max = vandq_s16(vmax, vreinterpretq_s16_u16(vcgtq_s16(t2, vmax)));

  /* Final values as 16-bit integers */
  const int16x8_t values = vorrq_s16(le_max, gt_max);

  r.neon_u8 = vmovn_u16(vreinterpretq_u16_s16(values));
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.i16) / sizeof(r.i16[0])) ; i++) {
    if (a.i16[i] > UINT8_MAX) {
      r.u8[i] = UINT8_MAX;
    } else if (a.i16[i] < 0) {
      r.u8[i] = 0;
    } else {
      r.u8[i] = (uint8_t) a.i16[i];
    }
  }

  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.i16) / sizeof(r.i16[0])) ; i++) {
    if (b.i16[i] > UINT8_MAX) {
      r.u8[i + 4] = UINT8_MAX;
    } else if (b.i16[i] < 0) {
      r.u8[i + 4] = 0;
    } else {
      r.u8[i + 4] = (uint8_t) b.i16[i];
    }
  }
#endif

  return r;
#endif
}
#define simde_m_packuswb(a, b) simde_mm_packs_pu16(a, b)
#if defined(SIMDE_MMX_ENABLE_NATIVE_ALIASES)
#  define _mm_packs_pu16(a, b) SIMDE__M64_TO_NATIVE(simde_mm_packs_pu16(SIMDE__M64_FROM_NATIVE(a), SIMDE__M64_FROM_NATIVE(b)))
#  define _m_packuswb(a, b) SIMDE__M64_TO_NATIVE(simde_mm_packs_pu16(SIMDE__M64_FROM_NATIVE(a), SIMDE__M64_FROM_NATIVE(b)))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_mm_set_pi8 (int8_t e7, int8_t e6, int8_t e5, int8_t e4, int8_t e3, int8_t e2, int8_t e1, int8_t e0) {
#if defined(SIMDE_MMX_NATIVE)
  return SIMDE__M64_FROM_NATIVE(_mm_set_pi8(e7, e6, e5, e4, e3, e2, e1, e0));
#else
  simde__m64 r;

#if defined(SIMDE_MMX_NEON)
  const int8_t v[sizeof(r.i8) / sizeof(r.i8[0])] = { e0, e1, e2, e3, e4, e5, e6, e7 };
  r.neon_i8 = vld1_s8(v);
#else
  r.i8[0] = e0;
  r.i8[1] = e1;
  r.i8[2] = e2;
  r.i8[3] = e3;
  r.i8[4] = e4;
  r.i8[5] = e5;
  r.i8[6] = e6;
  r.i8[7] = e7;
#endif

  return r;
#endif
}
#if defined(SIMDE_MMX_ENABLE_NATIVE_ALIASES)
#  define _mm_set_pi8(e7, e6, e5, e4, e3, e2, e1, e0) SIMDE__M64_TO_NATIVE(simde_mm_set_pi8(e7, e6, e5, e4, e3, e2, e1, e0))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_x_mm_set_pu8 (uint8_t e7, uint8_t e6, uint8_t e5, uint8_t e4, uint8_t e3, uint8_t e2, uint8_t e1, uint8_t e0) {
  simde__m64 r;

#if defined(SIMDE_MMX_NATIVE)
  r.n = _mm_set_pi8(
      HEDLEY_STATIC_CAST(int8_t, e7),
      HEDLEY_STATIC_CAST(int8_t, e6),
      HEDLEY_STATIC_CAST(int8_t, e5),
      HEDLEY_STATIC_CAST(int8_t, e4),
      HEDLEY_STATIC_CAST(int8_t, e3),
      HEDLEY_STATIC_CAST(int8_t, e2),
      HEDLEY_STATIC_CAST(int8_t, e1),
      HEDLEY_STATIC_CAST(int8_t, e0));
#elif defined(SIMDE_MMX_NEON)
  const uint8_t v[sizeof(r.u8) / sizeof(r.u8[0])] = { e0, e1, e2, e3, e4, e5, e6, e7 };
  r.neon_u8 = vld1_u8(v);
#else
  r.u8[0] = e0;
  r.u8[1] = e1;
  r.u8[2] = e2;
  r.u8[3] = e3;
  r.u8[4] = e4;
  r.u8[5] = e5;
  r.u8[6] = e6;
  r.u8[7] = e7;
#endif

  return r;
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_mm_set_pi16 (int16_t e3, int16_t e2, int16_t e1, int16_t e0) {
#if defined(SIMDE_MMX_NATIVE)
  return SIMDE__M64_FROM_NATIVE(_mm_set_pi16(e3, e2, e1, e0));
#else
  simde__m64 r;

#if defined(SIMDE_MMX_NEON)
  const int16_t v[sizeof(r.i16) / sizeof(r.i16[0])] = { e0, e1, e2, e3 };
  r.neon_i16 = vld1_s16(v);
#else
  r.i16[0] = e0;
  r.i16[1] = e1;
  r.i16[2] = e2;
  r.i16[3] = e3;
#endif
  return r;
#endif
}
#if defined(SIMDE_MMX_ENABLE_NATIVE_ALIASES)
#  define _mm_set_pi16(e3, e2, e1, e0) SIMDE__M64_TO_NATIVE(simde_mm_set_pi16(e3, e2, e1, e0))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_x_mm_set_pu16 (uint16_t e3, uint16_t e2, uint16_t e1, uint16_t e0) {
  simde__m64 r;

#if defined(SIMDE_MMX_NATIVE)
  r.n = _mm_set_pi16(
      HEDLEY_STATIC_CAST(int16_t, e3),
      HEDLEY_STATIC_CAST(int16_t, e2),
      HEDLEY_STATIC_CAST(int16_t, e1),
      HEDLEY_STATIC_CAST(int16_t, e0)
    );
#elif defined(SIMDE_MMX_NEON)
  const uint16_t v[sizeof(r.u16) / sizeof(r.u16[0])] = { e0, e1, e2, e3 };
  r.neon_u16 = vld1_u16(v);
#else
  r.u16[0] = e0;
  r.u16[1] = e1;
  r.u16[2] = e2;
  r.u16[3] = e3;
#endif

  return r;
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_x_mm_set_pu32 (uint32_t e1, uint32_t e0) {
  simde__m64 r;

#if defined(SIMDE_MMX_NATIVE)
  r.n = _mm_set_pi32(
      HEDLEY_STATIC_CAST(int32_t, e1),
      HEDLEY_STATIC_CAST(int32_t, e0));
#elif defined(SIMDE_MMX_NEON)
  const uint32_t v[sizeof(r.u32) / sizeof(r.u32[0])] = { e0, e1 };
  r.neon_u32 = vld1_u32(v);
#else
  r.u32[0] = e0;
  r.u32[1] = e1;
#endif

  return r;
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_mm_set_pi32 (int32_t e1, int32_t e0) {
  simde__m64 r;

#if defined(SIMDE_MMX_NATIVE)
  r.n = _mm_set_pi32(e1, e0);
#elif defined(SIMDE_MMX_NEON)
  const int32_t v[sizeof(r.i32) / sizeof(r.i32[0])] = { e0, e1 };
  r.neon_i32 = vld1_s32(v);
#else
  r.i32[0] = e0;
  r.i32[1] = e1;
#endif

  return r;
}
#if defined(SIMDE_MMX_ENABLE_NATIVE_ALIASES)
#  define _mm_set_pi32(e1, e0) SIMDE__M64_TO_NATIVE(simde_mm_set_pi32(e1, e0))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_x_mm_set_f32x2 (simde_float32 e1, simde_float32 e0) {
  simde__m64 r;

#if defined(SIMDE_MMX_NEON)
  const simde_float32 v[sizeof(r.f32) / sizeof(r.f32[0])] = { e0, e1 };
  r.neon_f32 = vld1_f32(v);
#else
  r.f32[0] = e0;
  r.f32[1] = e1;
#endif

  return r;
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_mm_set1_pi8 (int8_t a) {
  simde__m64 r;

#if defined(SIMDE_MMX_NATIVE)
  r.n = _mm_set1_pi8(a);
#elif defined(SIMDE_MMX_NEON)
  r.neon_i8 = vmov_n_s8(a);
#else
  r = simde_mm_set_pi8(a, a, a, a, a, a, a, a);
#endif

  return r;
}
#if defined(SIMDE_MMX_ENABLE_NATIVE_ALIASES)
#  define _mm_set1_pi8(a) SIMDE__M64_TO_NATIVE(simde_mm_set1_pi8(a))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_mm_set1_pi16 (int16_t a) {
  simde__m64 r;

#if defined(SIMDE_MMX_NATIVE)
  r.n = _mm_set1_pi16(a);
#elif defined(SIMDE_MMX_NEON)
  r.neon_i16 = vmov_n_s16(a);
#else
  r = simde_mm_set_pi16(a, a, a, a);
#endif

  return r;
}
#if defined(SIMDE_MMX_ENABLE_NATIVE_ALIASES)
#  define _mm_set1_pi16(a) SIMDE__M64_TO_NATIVE(simde_mm_set1_pi16(a))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_mm_set1_pi32 (int32_t a) {
  simde__m64 r;

#if defined(SIMDE_MMX_NATIVE)
  r.n = _mm_set1_pi32(a);
#elif defined(SIMDE_MMX_NEON)
  r.neon_i32 = vmov_n_s32(a);
#else
  r = simde_mm_set_pi32(a, a);
#endif

  return r;
}
#if defined(SIMDE_MMX_ENABLE_NATIVE_ALIASES)
#  define _mm_set1_pi32(a) SIMDE__M64_TO_NATIVE(simde_mm_set1_pi32(a))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_mm_setr_pi8 (int8_t e7, int8_t e6, int8_t e5, int8_t e4, int8_t e3, int8_t e2, int8_t e1, int8_t e0) {
  simde__m64 r;

#if defined(SIMDE_MMX_NATIVE)
  r.n = _mm_setr_pi8(e7, e6, e5, e4, e3, e2, e1, e0);
#else
  r = simde_mm_set_pi8(e0, e1, e2, e3, e4, e5, e6, e7);
#endif

  return r;
}
#if defined(SIMDE_MMX_ENABLE_NATIVE_ALIASES)
#  define _mm_setr_pi8(e7, e6, e5, e4, e3, e2, e1, e0) SIMDE__M64_TO_NATIVE(simde_mm_setr_pi8(e7, e6, e5, e4, e3, e2, e1, e0))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_mm_setr_pi16 (int16_t e3, int16_t e2, int16_t e1, int16_t e0) {
  simde__m64 r;

#if defined(SIMDE_MMX_NATIVE)
  r.n = _mm_setr_pi16(e3, e2, e1, e0);
#else
  r = simde_mm_set_pi16(e0, e1, e2, e3);
#endif

  return r;
}
#if defined(SIMDE_MMX_ENABLE_NATIVE_ALIASES)
#  define _mm_setr_pi16(e3, e2, e1, e0) SIMDE__M64_TO_NATIVE(simde_mm_setr_pi16(e3, e2, e1, e0))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_mm_setr_pi32 (int32_t e1, int32_t e0) {
  simde__m64 r;

#if defined(SIMDE_MMX_NATIVE)
  r.n = _mm_setr_pi32(e1, e0);
#else
  r = simde_mm_set_pi32(e0, e1);
#endif

  return r;
}
#if defined(SIMDE_MMX_ENABLE_NATIVE_ALIASES)
#  define _mm_setr_pi32(e1, e0) SIMDE__M64_TO_NATIVE(simde_mm_setr_pi32(e1, e0))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_mm_setzero_si64 (void) {
  simde__m64 r;

#if defined(SIMDE_MMX_NATIVE)
  r.n = _mm_setzero_si64();
#elif defined(SIMDE_MMX_NEON)
  r.neon_u32 = vmov_n_u32(0);
#else
  r =  simde_mm_set_pi32(0, 0);
#endif

  return r;
}
#if defined(SIMDE_MMX_ENABLE_NATIVE_ALIASES)
#  define _mm_setzero_si64() SIMDE__M64_TO_NATIVE(simde_mm_setzero_si64())
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_mm_sll_pi16 (simde__m64 a, simde__m64 count) {
#if defined(SIMDE_MMX_NATIVE)
  return SIMDE__M64_FROM_NATIVE(_mm_sll_pi16(a.n, count.n));
#else
  simde__m64 r;

#if defined(SIMDE_MMX_NEON)
  r.neon_i16 = vshl_s16(a.neon_i16, vmov_n_s16((int16_t) vget_lane_u64(count.neon_u64, 0)));
#elif defined(SIMDE__ENABLE_GCC_VEC_EXT_SHIFT_BY_SCALAR)
  r.i16 = a.i16 << count.u64[0];
#else
  if (HEDLEY_UNLIKELY(count.u64[0] > 15)) {
    memset(&r, 0, sizeof(r));
    return r;
  }

  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.u16) / sizeof(r.u16[0])) ; i++) {
    r.u16[i] = (uint16_t) (a.u16[i] << count.u64[0]);
  }
#endif

  return r;
#endif
}
#define simde_m_psllw(a, count) simde_mm_sll_pi16(a, count)
#if defined(SIMDE_MMX_ENABLE_NATIVE_ALIASES)
#  define _mm_sll_pi16(a, count) SIMDE__M64_TO_NATIVE(simde_mm_sll_pi16(SIMDE__M64_FROM_NATIVE(a), SIMDE__M64_FROM_NATIVE(count)))
#  define _m_psllw(a, count) SIMDE__M64_TO_NATIVE(simde_mm_sll_pi16(SIMDE__M64_FROM_NATIVE(a), SIMDE__M64_FROM_NATIVE(count)))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_mm_sll_pi32 (simde__m64 a, simde__m64 count) {
#if defined(SIMDE_MMX_NATIVE)
  return SIMDE__M64_FROM_NATIVE(_mm_sll_pi32(a.n, count.n));
#else
  simde__m64 r;

#if defined(SIMDE_MMX_NEON)
  r.neon_i32 = vshl_s32(a.neon_i32, vmov_n_s32((int32_t) vget_lane_u64(count.neon_u64, 0)));
#elif defined(SIMDE__ENABLE_GCC_VEC_EXT_SHIFT_BY_SCALAR)
  r.i32 = a.i32 << count.u64[0];
#else
  if (HEDLEY_UNLIKELY(count.u64[0] > 31)) {
    memset(&r, 0, sizeof(r));
    return r;
  }

  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.u32) / sizeof(r.u32[0])) ; i++) {
    r.u32[i] = a.u32[i] << count.u64[0];
  }
#endif

  return r;
#endif
}
#define simde_m_pslld(a, count) simde_mm_sll_pi32(a, count)
#if defined(SIMDE_MMX_ENABLE_NATIVE_ALIASES)
#  define _mm_sll_pi32(a, count) SIMDE__M64_TO_NATIVE(simde_mm_sll_pi32(SIMDE__M64_FROM_NATIVE(a), SIMDE__M64_FROM_NATIVE(count)))
#  define _m_pslld(a, count) SIMDE__M64_TO_NATIVE(simde_mm_sll_pi32(SIMDE__M64_FROM_NATIVE(a), SIMDE__M64_FROM_NATIVE(count)))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_mm_slli_pi16 (simde__m64 a, int count) {
#if defined(SIMDE_MMX_NATIVE) && !defined(__PGI)
  return SIMDE__M64_FROM_NATIVE(_mm_slli_pi16(a.n, count));
#else
  simde__m64 r;

#if defined(SIMDE__ENABLE_GCC_VEC_EXT_SHIFT_BY_SCALAR)
  r.i16 = a.i16 << count;
#elif defined(SIMDE_MMX_NEON)
  r.neon_i16 = vshl_s16(a.neon_i16, vmov_n_s16((int16_t) count));
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.u16) / sizeof(r.u16[0])) ; i++) {
    r.u16[i] = (uint16_t) (a.u16[i] << count);
  }
#endif

  return r;
#endif
}
#define simde_m_psllwi(a, count) simde_mm_slli_pi16(a, count)
#if defined(SIMDE_MMX_ENABLE_NATIVE_ALIASES)
#  define _mm_slli_pi16(a, count) SIMDE__M64_TO_NATIVE(simde_mm_slli_pi16(SIMDE__M64_FROM_NATIVE(a), count))
#  define _m_psllwi(a, count) SIMDE__M64_TO_NATIVE(simde_mm_slli_pi16(SIMDE__M64_FROM_NATIVE(a), count))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_mm_slli_pi32 (simde__m64 a, int count) {
#if defined(SIMDE_MMX_NATIVE) && !defined(__PGI)
  return SIMDE__M64_FROM_NATIVE(_mm_slli_pi32(a.n, count));
#else
  simde__m64 r;

#if defined(SIMDE__ENABLE_GCC_VEC_EXT_SHIFT_BY_SCALAR)
  r.i32 = a.i32 << count;
#elif defined(SIMDE_MMX_NEON)
  r.neon_i32 = vshl_s32(a.neon_i32, vmov_n_s32((int32_t) count));
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.u32) / sizeof(r.u32[0])) ; i++) {
    r.u32[i] = a.u32[i] << count;
  }
#endif

  return r;
#endif
}
#define simde_m_pslldi(a, b) simde_mm_slli_pi32(a, b)
#if defined(SIMDE_MMX_ENABLE_NATIVE_ALIASES)
#  define _mm_slli_pi32(a, count) SIMDE__M64_TO_NATIVE(simde_mm_slli_pi32(SIMDE__M64_FROM_NATIVE(a), count))
#  define _m_pslldi(a, count) SIMDE__M64_TO_NATIVE(simde_mm_slli_pi32(SIMDE__M64_FROM_NATIVE(a), count))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_mm_slli_si64 (simde__m64 a, int count) {
#if defined(SIMDE_MMX_NATIVE)
  return SIMDE__M64_FROM_NATIVE(_mm_slli_si64(a.n, count));
#else
  simde__m64 r;

#if defined(SIMDE__ENABLE_GCC_VEC_EXT_SHIFT_BY_SCALAR)
  r.i64 = a.i64 << count;
#elif defined(SIMDE_MMX_NEON)
  r.neon_i64 = vshl_s64(a.neon_i64, vmov_n_s64((int64_t) count));
#else
  r.u64[0] = a.u64[0] << count;
#endif

  return r;
#endif
}
#define simde_m_psllqi(a, count) simde_mm_slli_si64(a, count)
#if defined(SIMDE_MMX_ENABLE_NATIVE_ALIASES)
#  define _mm_slli_si64(a, count) SIMDE__M64_TO_NATIVE(simde_mm_slli_si64(SIMDE__M64_FROM_NATIVE(a), count))
#  define _m_psllqi(a, count) SIMDE__M64_TO_NATIVE(simde_mm_slli_si64(SIMDE__M64_FROM_NATIVE(a), count))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_mm_sll_si64 (simde__m64 a, simde__m64 count) {
#if defined(SIMDE_MMX_NATIVE)
  return SIMDE__M64_FROM_NATIVE(_mm_sll_si64(a.n, count.n));
#else
  simde__m64 r;

#if defined(SIMDE_MMX_NEON)
  r.neon_i64 = vshl_s64(a.neon_i64, count.neon_i64);
#elif defined(SIMDE__ENABLE_GCC_VEC_EXT)
  r.i64 = a.i64 << count.i64;
#else
  if (HEDLEY_UNLIKELY(count.u64[0] > 63)) {
    memset(&r, 0, sizeof(r));
    return r;
  }

  r.u64[0] = a.u64[0] << count.u64[0];
#endif

  return r;
#endif
}
#define simde_m_psllq(a, count) simde_mm_sll_si64(a, count)
#if defined(SIMDE_MMX_ENABLE_NATIVE_ALIASES)
#  define _mm_sll_si64(a, count) SIMDE__M64_TO_NATIVE(simde_mm_sll_si64(SIMDE__M64_FROM_NATIVE(a), SIMDE__M64_FROM_NATIVE(count)))
#  define _m_psllq(a, count) SIMDE__M64_TO_NATIVE(simde_mm_sll_si64(SIMDE__M64_FROM_NATIVE(a), SIMDE__M64_FROM_NATIVE(count)))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_mm_srl_pi16 (simde__m64 a, simde__m64 count) {
#if defined(SIMDE_MMX_NATIVE)
  return SIMDE__M64_FROM_NATIVE(_mm_srl_pi16(a.n, count.n));
#else
  simde__m64 r;

#if defined(SIMDE__ENABLE_GCC_VEC_EXT_SHIFT_BY_SCALAR)
  r.u16 = a.u16 >> count.u64[0];
#elif defined(SIMDE_MMX_NEON)
  r.neon_u16 = vshl_u16(a.neon_u16, vmov_n_s16(-((int16_t) vget_lane_u64(count.neon_u64, 0))));
#else
  if (HEDLEY_UNLIKELY(count.u64[0] > 15)) {
    memset(&r, 0, sizeof(r));
    return r;
  }

  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < sizeof(r.u16) / sizeof(r.u16[0]) ; i++) {
    r.u16[i] = a.u16[i] >> count.u64[0];
  }
#endif

  return r;
#endif
}
#define simde_m_psrlw(a, count) simde_mm_srl_pi16(a, count)
#if defined(SIMDE_MMX_ENABLE_NATIVE_ALIASES)
#  define _mm_srl_pi16(a, count) SIMDE__M64_TO_NATIVE(simde_mm_srl_pi16(SIMDE__M64_FROM_NATIVE(a), SIMDE__M64_FROM_NATIVE(count)))
#  define _m_psrlw(a, count) SIMDE__M64_TO_NATIVE(simde_mm_srl_pi16(SIMDE__M64_FROM_NATIVE(a), SIMDE__M64_FROM_NATIVE(count)))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_mm_srl_pi32 (simde__m64 a, simde__m64 count) {
#if defined(SIMDE_MMX_NATIVE)
  return SIMDE__M64_FROM_NATIVE(_mm_srl_pi32(a.n, count.n));
#else
  simde__m64 r;

#if defined(SIMDE__ENABLE_GCC_VEC_EXT_SHIFT_BY_SCALAR)
  r.u32 = a.u32 >> count.u64[0];
#elif defined(SIMDE_MMX_NEON)
  r.neon_u32 = vshl_u32(a.neon_u32, vmov_n_s32(-((int32_t) vget_lane_u64(count.neon_u64, 0))));
#else
  if (HEDLEY_UNLIKELY(count.u64[0] > 31)) {
    memset(&r, 0, sizeof(r));
    return r;
  }

  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < sizeof(r.u32) / sizeof(r.u32[0]) ; i++) {
    r.u32[i] = a.u32[i] >> count.u64[0];
  }
#endif

  return r;
#endif
}
#define simde_m_psrld(a, count) simde_mm_srl_pi32(a, count)
#if defined(SIMDE_MMX_ENABLE_NATIVE_ALIASES)
#  define _mm_srl_pi32(a, count) SIMDE__M64_TO_NATIVE(simde_mm_srl_pi32(SIMDE__M64_FROM_NATIVE(a), SIMDE__M64_FROM_NATIVE(count)))
#  define _m_psrld(a, count) SIMDE__M64_TO_NATIVE(simde_mm_srl_pi32(SIMDE__M64_FROM_NATIVE(a), SIMDE__M64_FROM_NATIVE(count)))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_mm_srli_pi16 (simde__m64 a, int count) {
#if defined(SIMDE_MMX_NATIVE) && !defined(__PGI)
  return SIMDE__M64_FROM_NATIVE(_mm_srli_pi16(a.n, count));
#else
  simde__m64 r;

#if defined(SIMDE__ENABLE_GCC_VEC_EXT_SHIFT_BY_SCALAR)
  r.u16 = a.u16 >> count;
#elif defined(SIMDE_MMX_NEON)
  r.neon_u16 = vshl_u16(a.neon_u16, vmov_n_s16(-((int16_t) count)));
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.u16) / sizeof(r.u16[0])) ; i++) {
    r.u16[i] = a.u16[i] >> count;
  }
#endif

  return r;
#endif
}
#define simde_m_psrlwi(a, count) simde_mm_srli_pi16(a, count)
#if defined(SIMDE_MMX_ENABLE_NATIVE_ALIASES)
#  define _mm_srli_pi16(a, count) SIMDE__M64_TO_NATIVE(simde_mm_srli_pi16(SIMDE__M64_FROM_NATIVE(a), count))
#  define _m_psrlwi(a, count) SIMDE__M64_TO_NATIVE(simde_mm_srli_pi16(SIMDE__M64_FROM_NATIVE(a), count))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_mm_srli_pi32 (simde__m64 a, int count) {
#if defined(SIMDE_MMX_NATIVE) && !defined(__PGI)
  return SIMDE__M64_FROM_NATIVE(_mm_srli_pi32(a.n, count));
#else
  simde__m64 r;

#if defined(SIMDE__ENABLE_GCC_VEC_EXT_SHIFT_BY_SCALAR)
  r.u32 = a.u32 >> count;
#elif defined(SIMDE_MMX_NEON)
  r.neon_u32 = vshl_u32(a.neon_u32, vmov_n_s32(-((int32_t) count)));
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.u32) / sizeof(r.u32[0])) ; i++) {
    r.u32[i] = a.u32[i] >> count;
  }
#endif

  return r;
#endif
}
#define simde_m_psrldi(a, count) simde_mm_srli_pi32(a, count)
#if defined(SIMDE_MMX_ENABLE_NATIVE_ALIASES)
#  define _mm_srli_pi32(a, count) SIMDE__M64_TO_NATIVE(simde_mm_srli_pi32(SIMDE__M64_FROM_NATIVE(a), count))
#  define _m_psrldi(a, count) SIMDE__M64_TO_NATIVE(simde_mm_srli_pi32(SIMDE__M64_FROM_NATIVE(a), count))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_mm_srli_si64 (simde__m64 a, int count) {
#if defined(SIMDE_MMX_NATIVE) && !defined(__PGI)
  return SIMDE__M64_FROM_NATIVE(_mm_srli_si64(a.n, count));
#else
  simde__m64 r;

#if defined(SIMDE_MMX_NEON)
  r.neon_u64 = vshl_u64(a.neon_u64, vmov_n_s64(-count));
#elif defined(SIMDE__ENABLE_GCC_VEC_EXT_SHIFT_BY_SCALAR)
  r.u64 = a.u64 >> count;
#else
  r.u64[0] = a.u64[0] >> count;
#endif

  return r;
#endif
}
#define simde_m_psrlqi(a, count) simde_mm_srli_si64(a, count)
#if defined(SIMDE_MMX_ENABLE_NATIVE_ALIASES)
#  define _mm_srli_si64(a, count) SIMDE__M64_TO_NATIVE(simde_mm_srli_si64(SIMDE__M64_FROM_NATIVE(a), count))
#  define _m_psrlqi(a, count) SIMDE__M64_TO_NATIVE(simde_mm_srli_si64(SIMDE__M64_FROM_NATIVE(a), count))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_mm_srl_si64 (simde__m64 a, simde__m64 count) {
#if defined(SIMDE_MMX_NATIVE)
  return SIMDE__M64_FROM_NATIVE(_mm_srl_si64(a.n, count.n));
#else
  simde__m64 r;

#if defined(SIMDE_MMX_NEON) && defined(SIMDE_ARCH_AARCH64)
  r.neon_u64 = vshl_u64(a.neon_u64, vneg_s64(count.neon_i64));
#elif defined(SIMDE__ENABLE_GCC_VEC_EXT)
  r.u64 = a.u64 >> count.u64;
#else
  if (HEDLEY_UNLIKELY(count.u64[0] > 63)) {
    memset(&r, 0, sizeof(r));
    return r;
  }

  r.u64[0] = a.u64[0] >> count.u64[0];
#endif

  return r;
#endif
}
#define simde_m_psrlq(a, count) simde_mm_srl_si64(a, count)
#if defined(SIMDE_MMX_ENABLE_NATIVE_ALIASES)
#  define _mm_srl_si64(a, count) SIMDE__M64_TO_NATIVE(simde_mm_srl_si64(SIMDE__M64_FROM_NATIVE(a), SIMDE__M64_FROM_NATIVE(count)))
#  define _m_psrlq(a, count) SIMDE__M64_TO_NATIVE(simde_mm_srl_si64(SIMDE__M64_FROM_NATIVE(a), SIMDE__M64_FROM_NATIVE(count)))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_mm_srai_pi16 (simde__m64 a, int count) {
#if defined(SIMDE_MMX_NATIVE) && !defined(__PGI)
  return SIMDE__M64_FROM_NATIVE(_mm_srai_pi16(a.n, count));
#else
  simde__m64 r;

#if defined(SIMDE__ENABLE_GCC_VEC_EXT_SHIFT_BY_SCALAR)
  r.i16 = a.i16 >> (count & 0xff);
#elif defined(SIMDE_MMX_NEON)
  r.neon_i16 = vshl_s16(a.neon_i16, vmov_n_s16(-((int16_t) count)));
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.i16) / sizeof(r.i16[0])) ; i++) {
    r.i16[i] = a.i16[i] >> (count & 0xff);
  }
#endif

  return r;
#endif
}
#define simde_m_psrawi(a, count) simde_mm_srai_pi16(a, count)
#if defined(SIMDE_MMX_ENABLE_NATIVE_ALIASES)
#  define _mm_srai_pi16(a, count) SIMDE__M64_TO_NATIVE(simde_mm_srai_pi16(SIMDE__M64_FROM_NATIVE(a), count))
#  define _m_psrawi(a, count) SIMDE__M64_TO_NATIVE(simde_mm_srai_pi16(SIMDE__M64_FROM_NATIVE(a), count))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_mm_srai_pi32 (simde__m64 a, int count) {
#if defined(SIMDE_MMX_NATIVE) && !defined(__PGI)
  return SIMDE__M64_FROM_NATIVE(_mm_srai_pi32(a.n, count));
#else
  simde__m64 r;

#if defined(SIMDE__ENABLE_GCC_VEC_EXT_SHIFT_BY_SCALAR)
  r.i32 = a.i32 >> (count & 0xff);
#elif defined(SIMDE_MMX_NEON)
  r.neon_i32 = vshl_s32(a.neon_i32, vmov_n_s32(-((int32_t) count)));
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.i32) / sizeof(r.i32[0])) ; i++) {
    r.i32[i] = a.i32[i] >> (count & 0xff);
  }
#endif

  return r;
#endif
}
#define simde_m_psradi(a, count) simde_mm_srai_pi32(a, count)
#if defined(SIMDE_MMX_ENABLE_NATIVE_ALIASES)
#  define _mm_srai_pi32(a, count) SIMDE__M64_TO_NATIVE(simde_mm_srai_pi32(SIMDE__M64_FROM_NATIVE(a), count))
#  define _m_srai_pi32(a, count) SIMDE__M64_TO_NATIVE(simde_mm_srai_pi32(SIMDE__M64_FROM_NATIVE(a), count))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_mm_sra_pi16 (simde__m64 a, simde__m64 count) {
#if defined(SIMDE_MMX_NATIVE)
  return SIMDE__M64_FROM_NATIVE(_mm_sra_pi16(a.n, count.n));
#else
  simde__m64 r;
  const int cnt = (int) (count.i64[0] > 15 ? 15 : count.i64[0]);

#if defined(SIMDE__ENABLE_GCC_VEC_EXT_SHIFT_BY_SCALAR)
  r.i16 = a.i16 >> cnt;
#elif defined(SIMDE_MMX_NEON)
  r.neon_i16 = vshl_s16(a.neon_i16, vmov_n_s16(-((int16_t) vget_lane_u64(count.neon_u64, 0))));
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.i16) / sizeof(r.i16[0])) ; i++) {
    r.i16[i] = a.i16[i] >> cnt;
  }
#endif

  return r;
#endif
}
#define simde_m_psraw(a, count) simde_mm_sra_pi16(a, count)
#if defined(SIMDE_MMX_ENABLE_NATIVE_ALIASES)
#  define _mm_sra_pi16(a, count) SIMDE__M64_TO_NATIVE(simde_mm_sra_pi16(SIMDE__M64_FROM_NATIVE(a), SIMDE__M64_FROM_NATIVE(count)))
#  define _m_psraw(a, count) SIMDE__M64_TO_NATIVE(simde_mm_sra_pi16(SIMDE__M64_FROM_NATIVE(a), SIMDE__M64_FROM_NATIVE(count)))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_mm_sra_pi32 (simde__m64 a, simde__m64 count) {
#if defined(SIMDE_MMX_NATIVE)
  return SIMDE__M64_FROM_NATIVE(_mm_sra_pi32(a.n, count.n));
#else
  simde__m64 r;
  const int32_t cnt = (count.u64[0] > 31) ? 31 : ((int32_t) count.u64[0]);

#if defined(SIMDE__ENABLE_GCC_VEC_EXT_SHIFT_BY_SCALAR)
  r.i32 = a.i32 >> cnt;
#elif defined(SIMDE_MMX_NEON)
  r.neon_i32 = vshl_s32(a.neon_i32, vmov_n_s32(-((int32_t) vget_lane_u64(count.neon_u64, 0))));
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.i32) / sizeof(r.i32[0])) ; i++) {
    r.i32[i] = a.i32[i] >> cnt;
  }
#endif

  return r;
#endif
}
#define simde_m_psrad(a, b) simde_mm_sra_pi32(a, b)
#if defined(SIMDE_MMX_ENABLE_NATIVE_ALIASES)
#  define _mm_sra_pi32(a, count) SIMDE__M64_TO_NATIVE(simde_mm_sra_pi32(SIMDE__M64_FROM_NATIVE(a), SIMDE__M64_FROM_NATIVE(count)))
#  define _m_psrad(a, count) SIMDE__M64_TO_NATIVE(simde_mm_sra_pi32(SIMDE__M64_FROM_NATIVE(a), SIMDE__M64_FROM_NATIVE(count)))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_mm_sub_pi8 (simde__m64 a, simde__m64 b) {
#if defined(SIMDE_MMX_NATIVE)
  return SIMDE__M64_FROM_NATIVE(_mm_sub_pi8(a.n, b.n));
#else
  simde__m64 r;

#if defined(SIMDE_MMX_NEON)
  r.neon_i8 = vsub_s8(a.neon_i8, b.neon_i8);
#elif defined(SIMDE__ENABLE_GCC_VEC_EXT)
  r.i8 = a.i8 - b.i8;
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.i8) / sizeof(r.i8[0])) ; i++) {
    r.i8[i] = a.i8[i] - b.i8[i];
  }
#endif

  return r;
#endif
}
#define simde_m_psubb(a, b) simde_mm_sub_pi8(a, b)
#if defined(SIMDE_MMX_ENABLE_NATIVE_ALIASES)
#  define _mm_sub_pi8(a, b) SIMDE__M64_TO_NATIVE(simde_mm_sub_pi8(SIMDE__M64_FROM_NATIVE(a), SIMDE__M64_FROM_NATIVE(b)))
#  define _m_psubb(a, b) SIMDE__M64_TO_NATIVE(simde_mm_sub_pi8(SIMDE__M64_FROM_NATIVE(a), SIMDE__M64_FROM_NATIVE(b)))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_mm_sub_pi16 (simde__m64 a, simde__m64 b) {
#if defined(SIMDE_MMX_NATIVE)
  return SIMDE__M64_FROM_NATIVE(_mm_sub_pi16(a.n, b.n));
#else
  simde__m64 r;

#if defined(SIMDE_MMX_NEON)
  r.neon_i16 = vsub_s16(a.neon_i16, b.neon_i16);
#elif defined(SIMDE__ENABLE_GCC_VEC_EXT)
  r.i16 = a.i16 - b.i16;
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.i16) / sizeof(r.i16[0])) ; i++) {
    r.i16[i] = a.i16[i] - b.i16[i];
  }
#endif

  return r;
#endif
}
#define simde_m_psubw(a, b) simde_mm_sub_pi16(a, b)
#if defined(SIMDE_MMX_ENABLE_NATIVE_ALIASES)
#  define _mm_sub_pi16(a, b) SIMDE__M64_TO_NATIVE(simde_mm_sub_pi16(SIMDE__M64_FROM_NATIVE(a), SIMDE__M64_FROM_NATIVE(b)))
#  define _m_psubw(a, b) SIMDE__M64_TO_NATIVE(simde_mm_sub_pi16(SIMDE__M64_FROM_NATIVE(a), SIMDE__M64_FROM_NATIVE(b)))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_mm_sub_pi32 (simde__m64 a, simde__m64 b) {
#if defined(SIMDE_MMX_NATIVE)
  return SIMDE__M64_FROM_NATIVE(_mm_sub_pi32(a.n, b.n));
#else
  simde__m64 r;

#if defined(SIMDE_MMX_NEON)
  r.neon_i32 = vsub_s32(a.neon_i32, b.neon_i32);
#elif defined(SIMDE__ENABLE_GCC_VEC_EXT)
  r.i32 = a.i32 - b.i32;
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.i32) / sizeof(r.i32[0])) ; i++) {
    r.i32[i] = a.i32[i] - b.i32[i];
  }
#endif

  return r;
#endif
}
#define simde_m_psubd(a, b) simde_mm_sub_pi32(a, b)
#if defined(SIMDE_MMX_ENABLE_NATIVE_ALIASES)
#  define _mm_sub_pi32(a, b) SIMDE__M64_TO_NATIVE(simde_mm_sub_pi32(SIMDE__M64_FROM_NATIVE(a), SIMDE__M64_FROM_NATIVE(b)))
#  define _m_psubd(a, b) SIMDE__M64_TO_NATIVE(simde_mm_sub_pi32(SIMDE__M64_FROM_NATIVE(a), SIMDE__M64_FROM_NATIVE(b)))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_mm_subs_pi8 (simde__m64 a, simde__m64 b) {
#if defined(SIMDE_MMX_NATIVE)
  return SIMDE__M64_FROM_NATIVE(_mm_subs_pi8(a.n, b.n));
#else
  simde__m64 r;

#if defined(SIMDE_MMX_NEON)
  r.neon_i8 = vqsub_s8(a.neon_i8, b.neon_i8);
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.i8) / sizeof(r.i8[0])) ; i++) {
    if (((b.i8[i]) > 0 && (a.i8[i]) < INT8_MIN + (b.i8[i]))) {
      r.i8[i] = INT8_MIN;
    } else if ((b.i8[i]) < 0 && (a.i8[i]) > INT8_MAX + (b.i8[i])) {
      r.i8[i] = INT8_MAX;
    } else {
      r.i8[i] = (a.i8[i]) - (b.i8[i]);
    }
  }
#endif

  return r;
#endif
}
#define simde_m_psubsb(a, b) simde_mm_subs_pi8(a, b)
#if defined(SIMDE_MMX_ENABLE_NATIVE_ALIASES)
#  define _mm_subs_pi8(a, b) SIMDE__M64_TO_NATIVE(simde_mm_subs_pi8(SIMDE__M64_FROM_NATIVE(a), SIMDE__M64_FROM_NATIVE(b)))
#  define _m_psubsb(a, b) SIMDE__M64_TO_NATIVE(simde_mm_subs_pi8(SIMDE__M64_FROM_NATIVE(a), SIMDE__M64_FROM_NATIVE(b)))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_mm_subs_pu8 (simde__m64 a, simde__m64 b) {
#if defined(SIMDE_MMX_NATIVE)
  return SIMDE__M64_FROM_NATIVE(_mm_subs_pu8(a.n, b.n));
#else
  simde__m64 r;

#if defined(SIMDE_MMX_NEON)
  r.neon_u8 = vqsub_u8(a.neon_u8, b.neon_u8);
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.u8) / sizeof(r.u8[0])) ; i++) {
    const int32_t x = a.u8[i] - b.u8[i];
    if (x < 0) {
      r.u8[i] = 0;
    } else if (x > UINT8_MAX) {
      r.u8[i] = UINT8_MAX;
    } else {
      r.u8[i] = (uint8_t) x;
    }
  }
#endif

  return r;
#endif
}
#define simde_m_psubusb(a, b) simde_mm_subs_pu8(a, b)
#if defined(SIMDE_MMX_ENABLE_NATIVE_ALIASES)
#  define _mm_subs_pu8(a, b) SIMDE__M64_TO_NATIVE(simde_mm_subs_pu8(SIMDE__M64_FROM_NATIVE(a), SIMDE__M64_FROM_NATIVE(b)))
#  define _m_psubusb(a, b) SIMDE__M64_TO_NATIVE(simde_mm_subs_pu8(SIMDE__M64_FROM_NATIVE(a), SIMDE__M64_FROM_NATIVE(b)))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_mm_subs_pi16 (simde__m64 a, simde__m64 b) {
#if defined(SIMDE_MMX_NATIVE)
  return SIMDE__M64_FROM_NATIVE(_mm_subs_pi16(a.n, b.n));
#else
  simde__m64 r;

#if defined(SIMDE_MMX_NEON)
  r.neon_i16 = vqsub_s16(a.neon_i16, b.neon_i16);
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.i16) / sizeof(r.i16[0])) ; i++) {
    if (((b.i16[i]) > 0 && (a.i16[i]) < SHRT_MIN + (b.i16[i]))) {
      r.i16[i] = SHRT_MIN;
    } else if ((b.i16[i]) < 0 && (a.i16[i]) > INT16_MAX + (b.i16[i])) {
      r.i16[i] = INT16_MAX;
    } else {
      r.i16[i] = (a.i16[i]) - (b.i16[i]);
    }
  }
#endif

  return r;
#endif
}
#define simde_m_psubsw(a, b) simde_mm_subs_pi16(a, b)
#if defined(SIMDE_MMX_ENABLE_NATIVE_ALIASES)
#  define _mm_subs_pi16(a, b) SIMDE__M64_TO_NATIVE(simde_mm_subs_pi16(SIMDE__M64_FROM_NATIVE(a), SIMDE__M64_FROM_NATIVE(b)))
#  define _m_psubsw(a, b) SIMDE__M64_TO_NATIVE(simde_mm_pi16(SIMDE__M64_FROM_NATIVE(a), SIMDE__M64_FROM_NATIVE(b)))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_mm_subs_pu16 (simde__m64 a, simde__m64 b) {
#if defined(SIMDE_MMX_NATIVE)
  return SIMDE__M64_FROM_NATIVE(_mm_subs_pu16(a.n, b.n));
#else
  simde__m64 r;

#if defined(SIMDE_MMX_NEON)
  r.neon_u16 = vqsub_u16(a.neon_u16, b.neon_u16);
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.u16) / sizeof(r.u16[0])) ; i++) {
    const int x = a.u16[i] - b.u16[i];
    if (x < 0) {
      r.u16[i] = 0;
    } else if (x > UINT16_MAX) {
      r.u16[i] = UINT16_MAX;
    } else {
      r.u16[i] = (uint16_t) x;
    }
  }
#endif

  return r;
#endif
}
#define simde_m_psubusw(a, b) simde_mm_subs_pu16(a, b)
#if defined(SIMDE_MMX_ENABLE_NATIVE_ALIASES)
#  define _mm_subs_pu16(a, b) SIMDE__M64_TO_NATIVE(simde_mm_subs_pu16(SIMDE__M64_FROM_NATIVE(a), SIMDE__M64_FROM_NATIVE(b)))
#  define _m_psubusw(a, b) SIMDE__M64_TO_NATIVE(simde_mm_subs_pu16(SIMDE__M64_FROM_NATIVE(a), SIMDE__M64_FROM_NATIVE(b)))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_mm_unpackhi_pi8 (simde__m64 a, simde__m64 b) {
#if defined(SIMDE_MMX_NATIVE)
  return SIMDE__M64_FROM_NATIVE(_mm_unpackhi_pi8(a.n, b.n));
#else
  simde__m64 r;

#if defined(SIMDE_MMX_NEON) && defined(SIMDE_ARCH_AARCH64)
  r.neon_i8 = vzip2_s8(a.neon_i8, b.neon_i8);
#elif defined(SIMDE__SHUFFLE_VECTOR)
  r.i8 = SIMDE__SHUFFLE_VECTOR(8, 8, a.i8, b.i8, 4, 12, 5, 13, 6, 14, 7, 15);
#else
  r.i8[0] = a.i8[4];
  r.i8[1] = b.i8[4];
  r.i8[2] = a.i8[5];
  r.i8[3] = b.i8[5];
  r.i8[4] = a.i8[6];
  r.i8[5] = b.i8[6];
  r.i8[6] = a.i8[7];
  r.i8[7] = b.i8[7];
#endif

  return r;
#endif
}
#define simde_m_punpckhbw(a, b) simde_mm_unpackhi_pi8(a, b)
#if defined(SIMDE_MMX_ENABLE_NATIVE_ALIASES)
#  define _mm_unpackhi_pi8(a, b) SIMDE__M64_TO_NATIVE(simde_mm_unpackhi_pi8(SIMDE__M64_FROM_NATIVE(a), SIMDE__M64_FROM_NATIVE(b)))
#  define _m_punpckhbw(a, b) SIMDE__M64_TO_NATIVE(simde_mm_unpackhi_pi8(SIMDE__M64_FROM_NATIVE(a), SIMDE__M64_FROM_NATIVE(b)))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_mm_unpackhi_pi16 (simde__m64 a, simde__m64 b) {
#if defined(SIMDE_MMX_NATIVE)
  return SIMDE__M64_FROM_NATIVE(_mm_unpackhi_pi16(a.n, b.n));
#else
  simde__m64 r;

#if defined(SIMDE_MMX_NEON) && defined(SIMDE_ARCH_AARCH64)
  r.neon_i16 = vzip2_s16(a.neon_i16, b.neon_i16);
#elif defined(SIMDE__SHUFFLE_VECTOR)
  r.i16 = SIMDE__SHUFFLE_VECTOR(16, 8, a.i16, b.i16, 2, 6, 3, 7);
#else
  r.i16[0] = a.i16[2];
  r.i16[1] = b.i16[2];
  r.i16[2] = a.i16[3];
  r.i16[3] = b.i16[3];
#endif

  return r;
#endif
}
#define simde_m_punpckhwd(a, b) simde_mm_unpackhi_pi16(a, b)
#if defined(SIMDE_MMX_ENABLE_NATIVE_ALIASES)
#  define _mm_unpackhi_pi16(a, b) SIMDE__M64_TO_NATIVE(simde_mm_unpackhi_pi16(SIMDE__M64_FROM_NATIVE(a), SIMDE__M64_FROM_NATIVE(b)))
#  define _m_punpckhwd(a, b) SIMDE__M64_TO_NATIVE(simde_mm_unpackhi_pi16(SIMDE__M64_FROM_NATIVE(a), SIMDE__M64_FROM_NATIVE(b)))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_mm_unpackhi_pi32 (simde__m64 a, simde__m64 b) {
#if defined(SIMDE_MMX_NATIVE)
  return SIMDE__M64_FROM_NATIVE(_mm_unpackhi_pi32(a.n, b.n));
#else
  simde__m64 r;

#if defined(SIMDE_MMX_NEON) && defined(SIMDE_ARCH_AARCH64)
  r.neon_i32 = vzip2_s32(a.neon_i32, b.neon_i32);
#elif defined(SIMDE__SHUFFLE_VECTOR)
  r.i32 = SIMDE__SHUFFLE_VECTOR(32, 8, a.i32, b.i32, 1, 3);
#else
  r.i32[0] = a.i32[1];
  r.i32[1] = b.i32[1];
#endif

  return r;
#endif
}
#define simde_m_punpckhdq(a, b) simde_mm_unpackhi_pi32(a, b)
#if defined(SIMDE_MMX_ENABLE_NATIVE_ALIASES)
#  define _mm_unpackhi_pi32(a, b) SIMDE__M64_TO_NATIVE(simde_mm_unpackhi_pi32(SIMDE__M64_FROM_NATIVE(a), SIMDE__M64_FROM_NATIVE(b)))
#  define _m_punpckhdq(a, b) SIMDE__M64_TO_NATIVE(simde_mm_unpackhi_pi32(SIMDE__M64_FROM_NATIVE(a), SIMDE__M64_FROM_NATIVE(b)))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_mm_unpacklo_pi8 (simde__m64 a, simde__m64 b) {
#if defined(SIMDE_MMX_NATIVE)
  return SIMDE__M64_FROM_NATIVE(_mm_unpacklo_pi8(a.n, b.n));
#else
  simde__m64 r;

#if defined(SIMDE_MMX_NEON) && defined(SIMDE_ARCH_AARCH64)
  r.neon_i8 = vzip1_s8(a.neon_i8, b.neon_i8);
#elif defined(SIMDE__SHUFFLE_VECTOR)
  r.i8 = SIMDE__SHUFFLE_VECTOR(8, 8, a.i8, b.i8, 0, 8, 1, 9, 2, 10, 3, 11);
#else
  r.i8[0] = a.i8[0];
  r.i8[1] = b.i8[0];
  r.i8[2] = a.i8[1];
  r.i8[3] = b.i8[1];
  r.i8[4] = a.i8[2];
  r.i8[5] = b.i8[2];
  r.i8[6] = a.i8[3];
  r.i8[7] = b.i8[3];
#endif

  return r;
#endif
}
#define simde_m_punpcklbw(a, b) simde_mm_unpacklo_pi8(a, b)
#if defined(SIMDE_MMX_ENABLE_NATIVE_ALIASES)
#  define _mm_unpacklo_pi8(a, b) SIMDE__M64_TO_NATIVE(simde_mm_unpacklo_pi8(SIMDE__M64_FROM_NATIVE(a), SIMDE__M64_FROM_NATIVE(b)))
#  define _m_punpcklbw(a, b) SIMDE__M64_TO_NATIVE(simde_mm_unpacklo_pi8(SIMDE__M64_FROM_NATIVE(a), SIMDE__M64_FROM_NATIVE(b)))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_mm_unpacklo_pi16 (simde__m64 a, simde__m64 b) {
#if defined(SIMDE_MMX_NATIVE)
  return SIMDE__M64_FROM_NATIVE(_mm_unpacklo_pi16(a.n, b.n));
#else
  simde__m64 r;

#if defined(SIMDE_MMX_NEON) && defined(SIMDE_ARCH_AARCH64)
  r.neon_i16 = vzip1_s16(a.neon_i16, b.neon_i16);
#elif defined(SIMDE__SHUFFLE_VECTOR)
  r.i16 = SIMDE__SHUFFLE_VECTOR(16, 8, a.i16, b.i16, 0, 4, 1, 5);
#else
  r.i16[0] = a.i16[0];
  r.i16[1] = b.i16[0];
  r.i16[2] = a.i16[1];
  r.i16[3] = b.i16[1];
#endif

  return r;
#endif
}
#define simde_m_punpcklwd(a, b) simde_mm_unpacklo_pi16(a, b)
#if defined(SIMDE_MMX_ENABLE_NATIVE_ALIASES)
#  define _mm_unpacklo_pi16(a, b) SIMDE__M64_TO_NATIVE(simde_mm_unpacklo_pi16(SIMDE__M64_FROM_NATIVE(a), SIMDE__M64_FROM_NATIVE(b)))
#  define _m_punpcklwd(a, b) SIMDE__M64_TO_NATIVE(simde_mm_unpacklo_pi16(SIMDE__M64_FROM_NATIVE(a), SIMDE__M64_FROM_NATIVE(b)))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_mm_unpacklo_pi32 (simde__m64 a, simde__m64 b) {
#if defined(SIMDE_MMX_NATIVE)
  return SIMDE__M64_FROM_NATIVE(_mm_unpacklo_pi32(a.n, b.n));
#else
  simde__m64 r;

#if defined(SIMDE_MMX_NEON) && defined(SIMDE_ARCH_AARCH64)
  r.neon_i32 = vzip1_s32(a.neon_i32, b.neon_i32);
#elif defined(SIMDE__SHUFFLE_VECTOR)
  r.i32 = SIMDE__SHUFFLE_VECTOR(32, 8, a.i32, b.i32, 0, 2);
#else
  r.i32[0] = a.i32[0];
  r.i32[1] = b.i32[0];
#endif

  return r;
#endif
}
#define simde_m_punpckldq(a, b) simde_mm_unpacklo_pi32(a, b)
#if defined(SIMDE_MMX_ENABLE_NATIVE_ALIASES)
#  define _mm_unpacklo_pi32(a, b) SIMDE__M64_TO_NATIVE(simde_mm_unpacklo_pi32(SIMDE__M64_FROM_NATIVE(a), SIMDE__M64_FROM_NATIVE(b)))
#  define _m_punpckldq(a, b) SIMDE__M64_TO_NATIVE(simde_mm_unpacklo_pi32(SIMDE__M64_FROM_NATIVE(a), SIMDE__M64_FROM_NATIVE(b)))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_mm_xor_si64 (simde__m64 a, simde__m64 b) {
#if defined(SIMDE_MMX_NATIVE)
  return SIMDE__M64_FROM_NATIVE(_mm_xor_si64(a.n, b.n));
#else
  simde__m64 r;

#if defined(SIMDE_MMX_NEON)
  r.neon_i32 = veor_s32(a.neon_i32, b.neon_i32);
#elif defined(SIMDE__ENABLE_GCC_VEC_EXT)
  r.i32f = a.i32f ^ b.i32f;
#else
  r.i32f[0] = a.i32f[0] ^ b.i32f[0];
#endif

  return r;
#endif
}
#define simde_m_pxor(a, b) simde_mm_xor_si64(a, b)
#if defined(SIMDE_MMX_ENABLE_NATIVE_ALIASES)
#  define _mm_xor_si64(a, b) SIMDE__M64_TO_NATIVE(simde_mm_xor_si64(SIMDE__M64_FROM_NATIVE(a), SIMDE__M64_FROM_NATIVE(b)))
#  define _m_pxor(a, b) SIMDE__M64_TO_NATIVE(simde_mm_xor_si64(SIMDE__M64_FROM_NATIVE(a), SIMDE__M64_FROM_NATIVE(b)))
#endif

SIMDE__FUNCTION_ATTRIBUTES
int32_t
simde_m_to_int (simde__m64 a) {
#if defined(SIMDE_MMX_NEON)
  return vget_lane_s32(a.neon_i32, 0);
#elif defined(SIMDE_MMX_NATIVE)
  return _m_to_int(a.n);
#else
  return a.i32[0];
#endif
}
#if defined(SIMDE_MMX_ENABLE_NATIVE_ALIASES)
#  define _m_to_int(a) simde_m_to_int(SIMDE__M64_FROM_NATIVE(a))
#endif

HEDLEY_DIAGNOSTIC_POP

SIMDE__END_DECLS

#endif /* !defined(SIMDE__MMX_H) */
