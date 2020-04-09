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
 *   2017-2020 Evan Nemerson <evan@nemerson.com>
 *   2015-2017 John W. Ratcliff <jratcliffscarab@gmail.com>
 *   2015      Brandon Rowlett <browlett@nvidia.com>
 *   2015      Ken Fast <kfast@gdeb.com>
 */

#if !defined(SIMDE__SSE_H)
#  if !defined(SIMDE__SSE_H)
#    define SIMDE__SSE_H
#  endif
#  include "mmx.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS

#  if defined(SIMDE_SSE_NATIVE)
#    undef SIMDE_SSE_NATIVE
#  endif
#  if defined(SIMDE_ARCH_X86_SSE) && !defined(SIMDE_SSE_NO_NATIVE) && !defined(SIMDE_NO_NATIVE)
#    define SIMDE_SSE_NATIVE
#  elif defined(SIMDE_ARCH_ARM_NEON) && !defined(SIMDE_SSE_NO_NEON) && !defined(SIMDE_NO_NEON)
#    define SIMDE_SSE_NEON
#  elif defined(SIMDE_ARCH_WASM_SIMD128)
#    define SIMDE_SSE_WASM_SIMD128
#  elif defined(SIMDE_ARCH_POWER_ALTIVEC)
#    define SIMDE_SSE_POWER_ALTIVEC
#  endif

#  if defined(SIMDE_SSE_NATIVE)
#    include <xmmintrin.h>
#  else
#    if defined(SIMDE_SSE_NEON)
#      include <arm_neon.h>
#    endif
#    if defined(SIMDE_SSE_WASM_SIMD128)
#      if !defined(__wasm_unimplemented_simd128__)
#        define __wasm_unimplemented_simd128__
#      endif
#      include <wasm_simd128.h>
#    endif
#    if defined(SIMDE_SSE_POWER_ALTIVEC)
#      include <altivec.h>
#    endif

#    if !defined(HEDLEY_INTEL_VERSION) && !defined(HEDLEY_EMSCRIPTEN_VERSION) && defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 201112L) && !defined(__STDC_NO_ATOMICS__)
#      include <stdatomic.h>
#    elif defined(_WIN32)
#      include <windows.h>
#    endif
#  endif

SIMDE__BEGIN_DECLS

typedef union {
#if defined(SIMDE_VECTOR_SUBSCRIPT)
  SIMDE_ALIGN(16) int8_t          i8 SIMDE_VECTOR(16) SIMDE_MAY_ALIAS;
  SIMDE_ALIGN(16) int16_t        i16 SIMDE_VECTOR(16) SIMDE_MAY_ALIAS;
  SIMDE_ALIGN(16) int32_t        i32 SIMDE_VECTOR(16) SIMDE_MAY_ALIAS;
  SIMDE_ALIGN(16) int64_t        i64 SIMDE_VECTOR(16) SIMDE_MAY_ALIAS;
  SIMDE_ALIGN(16) uint8_t         u8 SIMDE_VECTOR(16) SIMDE_MAY_ALIAS;
  SIMDE_ALIGN(16) uint16_t       u16 SIMDE_VECTOR(16) SIMDE_MAY_ALIAS;
  SIMDE_ALIGN(16) uint32_t       u32 SIMDE_VECTOR(16) SIMDE_MAY_ALIAS;
  SIMDE_ALIGN(16) uint64_t       u64 SIMDE_VECTOR(16) SIMDE_MAY_ALIAS;
  #if defined(SIMDE__HAVE_INT128)
  SIMDE_ALIGN(16) simde_int128  i128 SIMDE_VECTOR(16) SIMDE_MAY_ALIAS;
  SIMDE_ALIGN(16) simde_uint128 u128 SIMDE_VECTOR(16) SIMDE_MAY_ALIAS;
  #endif
  SIMDE_ALIGN(16) simde_float32  f32 SIMDE_VECTOR(16) SIMDE_MAY_ALIAS;
  SIMDE_ALIGN(16) int_fast32_t  i32f SIMDE_VECTOR(16) SIMDE_MAY_ALIAS;
  SIMDE_ALIGN(16) uint_fast32_t u32f SIMDE_VECTOR(16) SIMDE_MAY_ALIAS;
#else
  SIMDE_ALIGN(16) int8_t         i8[16];
  SIMDE_ALIGN(16) int16_t        i16[8];
  SIMDE_ALIGN(16) int32_t        i32[4];
  SIMDE_ALIGN(16) int64_t        i64[2];
  SIMDE_ALIGN(16) uint8_t        u8[16];
  SIMDE_ALIGN(16) uint16_t       u16[8];
  SIMDE_ALIGN(16) uint32_t       u32[4];
  SIMDE_ALIGN(16) uint64_t       u64[2];
  #if defined(SIMDE__HAVE_INT128)
  SIMDE_ALIGN(16) simde_int128  i128[1];
  SIMDE_ALIGN(16) simde_uint128 u128[1];
  #endif
  SIMDE_ALIGN(16) simde_float32  f32[4];
  SIMDE_ALIGN(16) int_fast32_t  i32f[16 / sizeof(int_fast32_t)];
  SIMDE_ALIGN(16) uint_fast32_t u32f[16 / sizeof(uint_fast32_t)];
#endif

  SIMDE_ALIGN(16) simde__m64_private m64_private[2];
  SIMDE_ALIGN(16) simde__m64         m64[2];

#if defined(SIMDE_SSE_NATIVE)
  SIMDE_ALIGN(16) __m128         n;
#elif defined(SIMDE_SSE_NEON)
  SIMDE_ALIGN(16) int8x16_t      neon_i8;
  SIMDE_ALIGN(16) int16x8_t      neon_i16;
  SIMDE_ALIGN(16) int32x4_t      neon_i32;
  SIMDE_ALIGN(16) int64x2_t      neon_i64;
  SIMDE_ALIGN(16) uint8x16_t     neon_u8;
  SIMDE_ALIGN(16) uint16x8_t     neon_u16;
  SIMDE_ALIGN(16) uint32x4_t     neon_u32;
  SIMDE_ALIGN(16) uint64x2_t     neon_u64;
  SIMDE_ALIGN(16) float32x4_t    neon_f32;
  #if defined(SIMDE_ARCH_AARCH64)
  SIMDE_ALIGN(16) float64x2_t    neon_f64;
  #endif
#elif defined(SIMDE_SSE_WASM_SIMD128)
  SIMDE_ALIGN(16) v128_t         wasm_v128;
#elif defined(SIMDE_SSE_POWER_ALTIVEC)
  SIMDE_ALIGN(16) vector unsigned char      altivec_u8;
  SIMDE_ALIGN(16) vector unsigned short     altivec_u16;
  SIMDE_ALIGN(16) vector unsigned int       altivec_u32;
  SIMDE_ALIGN(16) vector unsigned long long altivec_u64;
  SIMDE_ALIGN(16) vector signed char        altivec_i8;
  SIMDE_ALIGN(16) vector signed short       altivec_i16;
  SIMDE_ALIGN(16) vector signed int         altivec_i32;
  SIMDE_ALIGN(16) vector signed long long   altivec_i64;
  SIMDE_ALIGN(16) vector float              altivec_f32;
  SIMDE_ALIGN(16) vector double             altivec_f64;
#endif
} simde__m128_private;

#if defined(SIMDE_SSE_NATIVE)
  typedef __m128 simde__m128;
#elif defined(SIMDE_SSE_NEON)
   typedef float32x4_t simde__m128;
#elif defined(SIMDE_SSE_WASM_SIMD128)
   typedef v128_t simde__m128;
#elif defined(SIMDE_SSE_POWER_ALTIVEC)
   typedef vector float simde__m128;
#elif defined(SIMDE_VECTOR_SUBSCRIPT)
  typedef simde_float32 simde__m128 SIMDE_ALIGN(16) SIMDE_VECTOR(16) SIMDE_MAY_ALIAS;
#else
  typedef simde__m128_private simde__m128;
#endif

#if !defined(SIMDE_SSE_NATIVE) && defined(SIMDE_ENABLE_NATIVE_ALIASES)
  #define SIMDE_SSE_ENABLE_NATIVE_ALIASES
  typedef simde__m128 __m128;
#endif

HEDLEY_STATIC_ASSERT(16 == sizeof(simde__m128), "simde__m128 size incorrect");
HEDLEY_STATIC_ASSERT(16 == sizeof(simde__m128_private), "simde__m128_private size incorrect");
#if defined(SIMDE_CHECK_ALIGNMENT) && defined(SIMDE_ALIGN_OF)
HEDLEY_STATIC_ASSERT(SIMDE_ALIGN_OF(simde__m128) == 16, "simde__m128 is not 16-byte aligned");
HEDLEY_STATIC_ASSERT(SIMDE_ALIGN_OF(simde__m128_private) == 16, "simde__m128_private is not 16-byte aligned");
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128
simde__m128_from_private(simde__m128_private v) {
  simde__m128 r;
  simde_memcpy(&r, &v, sizeof(r));
  return r;
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m128_private
simde__m128_to_private(simde__m128 v) {
  simde__m128_private r;
  simde_memcpy(&r, &v, sizeof(r));
  return r;
}

#if defined(SIMDE_DIAGNOSTIC_DISABLE_UNINITIALIZED_)
  HEDLEY_DIAGNOSTIC_POP
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128
simde_mm_set_ps (simde_float32 e3, simde_float32 e2, simde_float32 e1, simde_float32 e0) {
  #if defined(SIMDE_SSE_NATIVE)
    return _mm_set_ps(e3, e2, e1, e0);
  #else
    simde__m128_private r_;

    #if defined(SIMDE_SSE_NEON)
      SIMDE_ALIGN(16) simde_float32 data[4] = { e0, e1, e2, e3 };
      r_.neon_f32 = vld1q_f32(data);
    #elif defined(SIMDE_SSE_WASM_SIMD128)
      r_.wasm_v128 = wasm_f32x4_make(e0, e1, e2, e3);
    #else
      r_.f32[0] = e0;
      r_.f32[1] = e1;
      r_.f32[2] = e2;
      r_.f32[3] = e3;
    #endif

    return simde__m128_from_private(r_);
  #endif
}
#if defined(SIMDE_SSE_ENABLE_NATIVE_ALIASES)
#  define _mm_set_ps(e3, e2, e1, e0) simde_mm_set_ps(e3, e2, e1, e0)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128
simde_mm_set_ps1 (simde_float32 a) {
#if defined(SIMDE_SSE_NATIVE)
  return _mm_set_ps1(a);
#elif defined(SIMDE_SSE_NEON)
  return vdupq_n_f32(a);
#else
  return simde_mm_set_ps(a, a, a, a);
#endif
}
#define simde_mm_set1_ps(a) simde_mm_set_ps1(a)
#if defined(SIMDE_SSE_ENABLE_NATIVE_ALIASES)
#  define _mm_set_ps1(a) simde_mm_set_ps1(a)
#  define _mm_set1_ps(a) simde_mm_set1_ps(a)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128
simde_mm_move_ss (simde__m128 a, simde__m128 b) {
#if defined(SIMDE_SSE_NATIVE)
  return _mm_move_ss(a, b);
#else
  simde__m128_private
    r_,
    a_ = simde__m128_to_private(a),
    b_ = simde__m128_to_private(b);

#if defined(SIMDE_SSE_NEON)
  r_.neon_f32 = vsetq_lane_f32(vgetq_lane_f32(b_.neon_f32, 0), a_.neon_f32, 0);
#elif defined(SIMDE_SSE_POWER_ALTIVEC)
  vector unsigned char m = {
    16, 17, 18, 19,
     4,  5,  6,  7,
     8,  9, 10, 11,
    12, 13, 14, 15
  };
  r_.altivec_f32 = vec_perm(a_.altivec_f32, b_.altivec_f32, m);
#elif defined(SIMDE__SHUFFLE_VECTOR)
  r_.f32 = SIMDE__SHUFFLE_VECTOR(32, 16, a_.f32, b_.f32, 4, 1, 2, 3);
#else
  r_.f32[0] = b_.f32[0];
  r_.f32[1] = a_.f32[1];
  r_.f32[2] = a_.f32[2];
  r_.f32[3] = a_.f32[3];
#endif

  return simde__m128_from_private(r_);
#endif
}
#if defined(SIMDE_SSE_ENABLE_NATIVE_ALIASES)
#  define _mm_move_ss(a, b) simde_mm_move_ss((a), (b))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128
simde_mm_add_ps (simde__m128 a, simde__m128 b) {
#if defined(SIMDE_SSE_NATIVE)
  return _mm_add_ps(a, b);
#else
  simde__m128_private
    r_,
    a_ = simde__m128_to_private(a),
    b_ = simde__m128_to_private(b);

#if defined(SIMDE_SSE_NEON)
  r_.neon_f32 = vaddq_f32(a_.neon_f32, b_.neon_f32);
#elif defined(SIMDE_SSE_WASM_SIMD128)
  r_.wasm_v128 = wasm_f32x4_add(a_.wasm_v128, b_.wasm_v128);
#elif defined(SIMDE_SSE_POWER_ALTIVEC)
  r_.altivec_f32 = vec_add(a_.altivec_f32, b_.altivec_f32);
#elif defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
  r_.f32 = a_.f32 + b_.f32;
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.f32) / sizeof(r_.f32[0])) ; i++) {
    r_.f32[i] = a_.f32[i] + b_.f32[i];
  }
#endif

  return simde__m128_from_private(r_);
#endif
}
#if defined(SIMDE_SSE_ENABLE_NATIVE_ALIASES)
#  define _mm_add_ps(a, b) simde_mm_add_ps((a), (b))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128
simde_mm_add_ss (simde__m128 a, simde__m128 b) {
#if defined(SIMDE_SSE_NATIVE)
  return _mm_add_ss(a, b);
#elif defined(SIMDE_ASSUME_VECTORIZATION)
  return simde_mm_move_ss(a, simde_mm_add_ps(a, b));
#else
  simde__m128_private
    r_,
    a_ = simde__m128_to_private(a),
    b_ = simde__m128_to_private(b);

  r_.f32[0] = a_.f32[0] + b_.f32[0];
  r_.f32[1] = a_.f32[1];
  r_.f32[2] = a_.f32[2];
  r_.f32[3] = a_.f32[3];

  return simde__m128_from_private(r_);
#endif
}
#if defined(SIMDE_SSE_ENABLE_NATIVE_ALIASES)
#  define _mm_add_ss(a, b) simde_mm_add_ss((a), (b))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128
simde_mm_and_ps (simde__m128 a, simde__m128 b) {
#if defined(SIMDE_SSE_NATIVE)
  return _mm_and_ps(a, b);
#else
  simde__m128_private
    r_,
    a_ = simde__m128_to_private(a),
    b_ = simde__m128_to_private(b);

#if defined(SIMDE_SSE_NEON)
  r_.neon_i32 = vandq_s32(a_.neon_i32, b_.neon_i32);
#elif defined(SIMDE_SSE_WASM_SIMD128)
  r_.wasm_v128 = wasm_v128_and(a_.wasm_v128, b_.wasm_v128);
#elif defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
  r_.i32 = a_.i32 & b_.i32;
#elif defined(SIMDE_SSE_POWER_ALTIVEC)
  r_.altivec_f32 = vec_and(a_.altivec_f32, b_.altivec_f32);
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.i32) / sizeof(r_.i32[0])) ; i++) {
    r_.i32[i] = a_.i32[i] & b_.i32[i];
  }
#endif

  return simde__m128_from_private(r_);
#endif
}
#if defined(SIMDE_SSE_ENABLE_NATIVE_ALIASES)
#  define _mm_and_ps(a, b) simde_mm_and_ps((a), (b))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128
simde_mm_andnot_ps (simde__m128 a, simde__m128 b) {
#if defined(SIMDE_SSE_NATIVE)
  return _mm_andnot_ps(a, b);
#else
  simde__m128_private
    r_,
    a_ = simde__m128_to_private(a),
    b_ = simde__m128_to_private(b);

#if defined(SIMDE_SSE_NEON)
  r_.neon_i32 = vbicq_s32(b_.neon_i32, a_.neon_i32);
#elif defined(SIMDE_SSE_WASM_SIMD128)
  r_.wasm_v128 = wasm_v128_andnot(b_.wasm_v128, a_.wasm_v128);
#elif defined(SIMDE_SSE_POWER_ALTIVEC)
  r_.altivec_f32 = vec_andc(b_.altivec_f32, a_.altivec_f32);
#elif defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
  r_.i32 = ~a_.i32 & b_.i32;
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.i32) / sizeof(r_.i32[0])) ; i++) {
    r_.i32[i] = ~(a_.i32[i]) & b_.i32[i];
  }
#endif

  return simde__m128_from_private(r_);
#endif
}
#if defined(SIMDE_SSE_ENABLE_NATIVE_ALIASES)
#  define _mm_andnot_ps(a, b) simde_mm_andnot_ps((a), (b))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_mm_avg_pu16 (simde__m64 a, simde__m64 b) {
#if defined(SIMDE_SSE_NATIVE) && defined(SIMDE_ARCH_X86_MMX)
  return _mm_avg_pu16(a, b);
#else
  simde__m64_private
    r_,
    a_ = simde__m64_to_private(a),
    b_ = simde__m64_to_private(b);

#if defined(SIMDE_SSE_NEON)
  r_.neon_u16 = vrhadd_u16(b_.neon_u16, a_.neon_u16);
#elif defined(SIMDE_VECTOR_SUBSCRIPT_OPS) && defined(SIMDE_VECTOR_SUBSCRIPT_SCALAR) && defined(SIMDE__CONVERT_VECTOR)
  uint32_t wa SIMDE_VECTOR(16);
  uint32_t wb SIMDE_VECTOR(16);
  uint32_t wr SIMDE_VECTOR(16);
  SIMDE__CONVERT_VECTOR(wa, a_.u16);
  SIMDE__CONVERT_VECTOR(wb, b_.u16);
  wr = (wa + wb + 1) >> 1;
  SIMDE__CONVERT_VECTOR(r_.u16, wr);
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.u16) / sizeof(r_.u16[0])) ; i++) {
    r_.u16[i] = (a_.u16[i] + b_.u16[i] + 1) >> 1;
  }
#endif

  return simde__m64_from_private(r_);
#endif
}
#define simde_m_pavgw(a, b) simde_mm_avg_pu16(a, b)
#if defined(SIMDE_SSE_ENABLE_NATIVE_ALIASES)
#  define _mm_avg_pu16(a, b) simde_mm_avg_pu16(a, b)
#  define _m_pavgw(a, b) simde_mm_avg_pu16(a, b)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_mm_avg_pu8 (simde__m64 a, simde__m64 b) {
#if defined(SIMDE_SSE_NATIVE) && defined(SIMDE_ARCH_X86_MMX)
  return _mm_avg_pu8(a, b);
#else
  simde__m64_private
    r_,
    a_ = simde__m64_to_private(a),
    b_ = simde__m64_to_private(b);

#if defined(SIMDE_SSE_NEON)
  r_.neon_u8 = vrhadd_u8(b_.neon_u8, a_.neon_u8);
#elif defined(SIMDE_VECTOR_SUBSCRIPT_OPS) && defined(SIMDE_VECTOR_SUBSCRIPT_SCALAR) && defined(SIMDE__CONVERT_VECTOR)
  uint16_t wa SIMDE_VECTOR(16);
  uint16_t wb SIMDE_VECTOR(16);
  uint16_t wr SIMDE_VECTOR(16);
  SIMDE__CONVERT_VECTOR(wa, a_.u8);
  SIMDE__CONVERT_VECTOR(wb, b_.u8);
  wr = (wa + wb + 1) >> 1;
  SIMDE__CONVERT_VECTOR(r_.u8, wr);
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.u8) / sizeof(r_.u8[0])) ; i++) {
    r_.u8[i] = (a_.u8[i] + b_.u8[i] + 1) >> 1;
  }
#endif

  return simde__m64_from_private(r_);
#endif
}
#define simde_m_pavgb(a, b) simde_mm_avg_pu8(a, b)
#if defined(SIMDE_SSE_ENABLE_NATIVE_ALIASES)
#  define _mm_avg_pu8(a, b) simde_mm_avg_pu8(a, b)
#  define _m_pavgb(a, b) simde_mm_avg_pu8(a, b)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128
simde_mm_cmpeq_ps (simde__m128 a, simde__m128 b) {
#if defined(SIMDE_SSE_NATIVE)
  return _mm_cmpeq_ps(a, b);
#else
  simde__m128_private
    r_,
    a_ = simde__m128_to_private(a),
    b_ = simde__m128_to_private(b);

  #if defined(SIMDE_SSE_NEON)
    r_.neon_u32 = vceqq_f32(a_.neon_f32, b_.neon_f32);
  #elif defined(SIMDE_SSE_WASM_SIMD128)
    r_.wasm_v128 = wasm_f32x4_eq(a_.wasm_v128, b_.wasm_v128);
  #elif defined(SIMDE_SSE_POWER_ALTIVEC)
    r_.altivec_f32 = (vector float) vec_cmpeq(a_.altivec_f32, b_.altivec_f32);
  #elif defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
    r_.i32 = HEDLEY_STATIC_CAST(__typeof__(r_.i32), a_.f32 == b_.f32);
  #else
    SIMDE__VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f32) / sizeof(r_.f32[0])) ; i++) {
      r_.u32[i] = (a_.f32[i] == b_.f32[i]) ? ~UINT32_C(0) : UINT32_C(0);
    }
  #endif

  return simde__m128_from_private(r_);
#endif
}
#if defined(SIMDE_SSE_ENABLE_NATIVE_ALIASES)
#  define _mm_cmpeq_ps(a, b) simde_mm_cmpeq_ps((a), (b))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128
simde_mm_cmpeq_ss (simde__m128 a, simde__m128 b) {
#if defined(SIMDE_SSE_NATIVE)
  return _mm_cmpeq_ss(a, b);
#elif defined(SIMDE_ASSUME_VECTORIZATION)
  return simde_mm_move_ss(a, simde_mm_cmpeq_ps(a, b));
#else
  simde__m128_private
    r_,
    a_ = simde__m128_to_private(a),
    b_ = simde__m128_to_private(b);

  r_.u32[0] = (a_.f32[0] == b_.f32[0]) ? ~UINT32_C(0) : UINT32_C(0);
  SIMDE__VECTORIZE
  for (size_t i = 1 ; i < (sizeof(r_.f32) / sizeof(r_.f32[0])) ; i++) {
    r_.u32[i] = a_.u32[i];
  }

  return simde__m128_from_private(r_);
#endif
}
#if defined(SIMDE_SSE_ENABLE_NATIVE_ALIASES)
#  define _mm_cmpeq_ss(a, b) simde_mm_cmpeq_ss((a), (b))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128
simde_mm_cmpge_ps (simde__m128 a, simde__m128 b) {
#if defined(SIMDE_SSE_NATIVE)
  return _mm_cmpge_ps(a, b);
#else
  simde__m128_private
    r_,
    a_ = simde__m128_to_private(a),
    b_ = simde__m128_to_private(b);

  #if defined(SIMDE_SSE_NEON)
    r_.neon_u32 = vcgeq_f32(a_.neon_f32, b_.neon_f32);
  #elif defined(SIMDE_SSE_WASM_SIMD128)
    r_.wasm_v128 = wasm_f32x4_ge(a_.wasm_v128, b_.wasm_v128);
  #elif defined(SIMDE_SSE_POWER_ALTIVEC)
    r_.altivec_f32 = (vector float) vec_cmpge(a_.altivec_f32, b_.altivec_f32);
  #elif defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
    r_.i32 = (__typeof__(r_.i32)) (a_.f32 >= b_.f32);
  #else
    SIMDE__VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f32) / sizeof(r_.f32[0])) ; i++) {
      r_.u32[i] = (a_.f32[i] >= b_.f32[i]) ? ~UINT32_C(0) : UINT32_C(0);
    }
  #endif

  return simde__m128_from_private(r_);
#endif
}
#if defined(SIMDE_SSE_ENABLE_NATIVE_ALIASES)
#  define _mm_cmpge_ps(a, b) simde_mm_cmpge_ps((a), (b))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128
simde_mm_cmpge_ss (simde__m128 a, simde__m128 b) {
#if defined(SIMDE_SSE_NATIVE) && !defined(__PGI)
  return _mm_cmpge_ss(a, b);
#elif defined(SIMDE_ASSUME_VECTORIZATION)
  return simde_mm_move_ss(a, simde_mm_cmpge_ps(a, b));
#else
  simde__m128_private
    r_,
    a_ = simde__m128_to_private(a),
    b_ = simde__m128_to_private(b);

  r_.u32[0] = (a_.f32[0] >= b_.f32[0]) ? ~UINT32_C(0) : UINT32_C(0);
  SIMDE__VECTORIZE
  for (size_t i = 1 ; i < (sizeof(r_.f32) / sizeof(r_.f32[0])) ; i++) {
    r_.u32[i] = a_.u32[i];
  }

  return simde__m128_from_private(r_);
#endif
}
#if defined(SIMDE_SSE_ENABLE_NATIVE_ALIASES)
#  define _mm_cmpge_ss(a, b) simde_mm_cmpge_ss((a), (b))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128
simde_mm_cmpgt_ps (simde__m128 a, simde__m128 b) {
#if defined(SIMDE_SSE_NATIVE)
  return _mm_cmpgt_ps(a, b);
#else
  simde__m128_private
    r_,
    a_ = simde__m128_to_private(a),
    b_ = simde__m128_to_private(b);

  #if defined(SIMDE_SSE_NEON)
    r_.neon_u32 = vcgtq_f32(a_.neon_f32, b_.neon_f32);
  #elif defined(SIMDE_SSE_WASM_SIMD128)
    r_.wasm_v128 = wasm_f32x4_gt(a_.wasm_v128, b_.wasm_v128);
  #elif defined(SIMDE_SSE_POWER_ALTIVEC)
    r_.altivec_f32 = (vector float) vec_cmpgt(a_.altivec_f32, b_.altivec_f32);
  #elif defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
    r_.i32 = (__typeof__(r_.i32)) (a_.f32 > b_.f32);
  #else
    SIMDE__VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f32) / sizeof(r_.f32[0])) ; i++) {
      r_.u32[i] = (a_.f32[i] > b_.f32[i]) ? ~UINT32_C(0) : UINT32_C(0);
    }
  #endif

  return simde__m128_from_private(r_);
#endif
}
#if defined(SIMDE_SSE_ENABLE_NATIVE_ALIASES)
#  define _mm_cmpgt_ps(a, b) simde_mm_cmpgt_ps((a), (b))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128
simde_mm_cmpgt_ss (simde__m128 a, simde__m128 b) {
#if defined(SIMDE_SSE_NATIVE) && !defined(__PGI)
  return _mm_cmpgt_ss(a, b);
#elif defined(SIMDE_ASSUME_VECTORIZATION)
  return simde_mm_move_ss(a, simde_mm_cmpgt_ps(a, b));
#else
  simde__m128_private
    r_,
    a_ = simde__m128_to_private(a),
    b_ = simde__m128_to_private(b);

  r_.u32[0] = (a_.f32[0] > b_.f32[0]) ? ~UINT32_C(0) : UINT32_C(0);
  SIMDE__VECTORIZE
  for (size_t i = 1 ; i < (sizeof(r_.f32) / sizeof(r_.f32[0])) ; i++) {
    r_.u32[i] = a_.u32[i];
  }

  return simde__m128_from_private(r_);
#endif
}
#if defined(SIMDE_SSE_ENABLE_NATIVE_ALIASES)
#  define _mm_cmpgt_ss(a, b) simde_mm_cmpgt_ss((a), (b))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128
simde_mm_cmple_ps (simde__m128 a, simde__m128 b) {
#if defined(SIMDE_SSE_NATIVE)
  return _mm_cmple_ps(a, b);
#else
  simde__m128_private
    r_,
    a_ = simde__m128_to_private(a),
    b_ = simde__m128_to_private(b);

  #if defined(SIMDE_SSE_NEON)
    r_.neon_u32 = vcleq_f32(a_.neon_f32, b_.neon_f32);
  #elif defined(SIMDE_SSE_WASM_SIMD128)
    r_.wasm_v128 = wasm_f32x4_le(a_.wasm_v128, b_.wasm_v128);
  #elif defined(SIMDE_SSE_POWER_ALTIVEC)
    r_.altivec_f32 = (vector float) vec_cmple(a_.altivec_f32, b_.altivec_f32);
  #elif defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
    r_.i32 = (__typeof__(r_.i32)) (a_.f32 <= b_.f32);
  #else
    SIMDE__VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f32) / sizeof(r_.f32[0])) ; i++) {
      r_.u32[i] = (a_.f32[i] <= b_.f32[i]) ? ~UINT32_C(0) : UINT32_C(0);
    }
  #endif

  return simde__m128_from_private(r_);
#endif
}
#if defined(SIMDE_SSE_ENABLE_NATIVE_ALIASES)
#  define _mm_cmple_ps(a, b) simde_mm_cmple_ps((a), (b))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128
simde_mm_cmple_ss (simde__m128 a, simde__m128 b) {
#if defined(SIMDE_SSE_NATIVE)
  return _mm_cmple_ss(a, b);
#elif defined(SIMDE_ASSUME_VECTORIZATION)
  return simde_mm_move_ss(a, simde_mm_cmple_ps(a, b));
#else
  simde__m128_private
    r_,
    a_ = simde__m128_to_private(a),
    b_ = simde__m128_to_private(b);

  r_.u32[0] = (a_.f32[0] <= b_.f32[0]) ? ~UINT32_C(0) : UINT32_C(0);
  SIMDE__VECTORIZE
  for (size_t i = 1 ; i < (sizeof(r_.f32) / sizeof(r_.f32[0])) ; i++) {
    r_.u32[i] = a_.u32[i];
  }

  return simde__m128_from_private(r_);
#endif
}
#if defined(SIMDE_SSE_ENABLE_NATIVE_ALIASES)
#  define _mm_cmple_ss(a, b) simde_mm_cmple_ss((a), (b))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128
simde_mm_cmplt_ps (simde__m128 a, simde__m128 b) {
#if defined(SIMDE_SSE_NATIVE)
  return _mm_cmplt_ps(a, b);
#else
  simde__m128_private
    r_,
    a_ = simde__m128_to_private(a),
    b_ = simde__m128_to_private(b);

  #if defined(SIMDE_SSE_NEON)
    r_.neon_u32 = vcltq_f32(a_.neon_f32, b_.neon_f32);
  #elif defined(SIMDE_SSE_WASM_SIMD128)
    r_.wasm_v128 = wasm_f32x4_lt(a_.wasm_v128, b_.wasm_v128);
  #elif defined(SIMDE_SSE_POWER_ALTIVEC)
    r_.altivec_f32 = (vector float) vec_cmplt(a_.altivec_f32, b_.altivec_f32);
  #elif defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
    r_.i32 = (__typeof__(r_.i32)) (a_.f32 < b_.f32);
  #else
    SIMDE__VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f32) / sizeof(r_.f32[0])) ; i++) {
      r_.u32[i] = (a_.f32[i] < b_.f32[i]) ? ~UINT32_C(0) : UINT32_C(0);
    }
  #endif

  return simde__m128_from_private(r_);
#endif
}
#if defined(SIMDE_SSE_ENABLE_NATIVE_ALIASES)
#  define _mm_cmplt_ps(a, b) simde_mm_cmplt_ps((a), (b))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128
simde_mm_cmplt_ss (simde__m128 a, simde__m128 b) {
#if defined(SIMDE_SSE_NATIVE)
  return _mm_cmplt_ss(a, b);
#elif defined(SIMDE_ASSUME_VECTORIZATION)
  return simde_mm_move_ss(a, simde_mm_cmplt_ps(a, b));
#else
  simde__m128_private
    r_,
    a_ = simde__m128_to_private(a),
    b_ = simde__m128_to_private(b);

  r_.u32[0] = (a_.f32[0] < b_.f32[0]) ? ~UINT32_C(0) : UINT32_C(0);
  SIMDE__VECTORIZE
  for (size_t i = 1 ; i < (sizeof(r_.f32) / sizeof(r_.f32[0])) ; i++) {
    r_.u32[i] = a_.u32[i];
  }

  return simde__m128_from_private(r_);
#endif
}
#if defined(SIMDE_SSE_ENABLE_NATIVE_ALIASES)
#  define _mm_cmplt_ss(a, b) simde_mm_cmplt_ss((a), (b))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128
simde_mm_cmpneq_ps (simde__m128 a, simde__m128 b) {
#if defined(SIMDE_SSE_NATIVE)
  return _mm_cmpneq_ps(a, b);
#else
  simde__m128_private
    r_,
    a_ = simde__m128_to_private(a),
    b_ = simde__m128_to_private(b);

  #if defined(SIMDE_SSE_NEON)
    r_.neon_u32 = vmvnq_u32(vceqq_f32(a_.neon_f32, b_.neon_f32));
  #elif defined(SIMDE_SSE_WASM_SIMD128)
    r_.wasm_v128 = wasm_f32x4_ne(a_.wasm_v128, b_.wasm_v128);
  #elif defined(SIMDE_SSE_POWER_ALTIVEC) && (SIMDE_ARCH_POWER >= 900) && !defined(HEDLEY_IBM_VERSION)
    /* vec_cmpne(vector float, vector float) is missing from XL C/C++ v16.1.1,
       though the documentation (table 89 on page 432 of the IBM XL C/C++ for
       Linux Compiler Reference, Version 16.1.1) shows that it should be
       present.  Both GCC and clang support it. */
    r_.altivec_f32 = (vector float) vec_cmpne(a_.altivec_f32, b_.altivec_f32);
  #elif defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
    r_.i32 = (__typeof__(r_.i32)) (a_.f32 != b_.f32);
  #else
    SIMDE__VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f32) / sizeof(r_.f32[0])) ; i++) {
      r_.u32[i] = (a_.f32[i] != b_.f32[i]) ? ~UINT32_C(0) : UINT32_C(0);
    }
  #endif

  return simde__m128_from_private(r_);
#endif
}
#if defined(SIMDE_SSE_ENABLE_NATIVE_ALIASES)
#  define _mm_cmpneq_ps(a, b) simde_mm_cmpneq_ps((a), (b))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128
simde_mm_cmpneq_ss (simde__m128 a, simde__m128 b) {
#if defined(SIMDE_SSE_NATIVE)
  return _mm_cmpneq_ss(a, b);
#elif defined(SIMDE_ASSUME_VECTORIZATION)
  return simde_mm_move_ss(a, simde_mm_cmpneq_ps(a, b));
#else
  simde__m128_private
    r_,
    a_ = simde__m128_to_private(a),
    b_ = simde__m128_to_private(b);

  r_.u32[0] = (a_.f32[0] != b_.f32[0]) ? ~UINT32_C(0) : UINT32_C(0);
  SIMDE__VECTORIZE
  for (size_t i = 1 ; i < (sizeof(r_.f32) / sizeof(r_.f32[0])) ; i++) {
    r_.u32[i] = a_.u32[i];
  }

  return simde__m128_from_private(r_);
#endif
}
#if defined(SIMDE_SSE_ENABLE_NATIVE_ALIASES)
#  define _mm_cmpneq_ss(a, b) simde_mm_cmpneq_ss((a), (b))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128
simde_mm_cmpnge_ps (simde__m128 a, simde__m128 b) {
  return simde_mm_cmplt_ps(a, b);
}
#if defined(SIMDE_SSE_ENABLE_NATIVE_ALIASES)
#  define _mm_cmpnge_ps(a, b) simde_mm_cmpnge_ps((a), (b))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128
simde_mm_cmpnge_ss (simde__m128 a, simde__m128 b) {
  return simde_mm_cmplt_ss(a, b);
}
#if defined(SIMDE_SSE_ENABLE_NATIVE_ALIASES)
#  define _mm_cmpnge_ss(a, b) simde_mm_cmpnge_ss((a), (b))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128
simde_mm_cmpngt_ps (simde__m128 a, simde__m128 b) {
  return simde_mm_cmple_ps(a, b);
}
#if defined(SIMDE_SSE_ENABLE_NATIVE_ALIASES)
#  define _mm_cmpngt_ps(a, b) simde_mm_cmpngt_ps((a), (b))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128
simde_mm_cmpngt_ss (simde__m128 a, simde__m128 b) {
  return simde_mm_cmple_ss(a, b);
}
#if defined(SIMDE_SSE_ENABLE_NATIVE_ALIASES)
#  define _mm_cmpngt_ss(a, b) simde_mm_cmpngt_ss((a), (b))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128
simde_mm_cmpnle_ps (simde__m128 a, simde__m128 b) {
  return simde_mm_cmpgt_ps(a, b);
}
#if defined(SIMDE_SSE_ENABLE_NATIVE_ALIASES)
#  define _mm_cmpnle_ps(a, b) simde_mm_cmpnle_ps((a), (b))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128
simde_mm_cmpnle_ss (simde__m128 a, simde__m128 b) {
  return simde_mm_cmpgt_ss(a, b);
}
#if defined(SIMDE_SSE_ENABLE_NATIVE_ALIASES)
#  define _mm_cmpnle_ss(a, b) simde_mm_cmpnle_ss((a), (b))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128
simde_mm_cmpnlt_ps (simde__m128 a, simde__m128 b) {
  return simde_mm_cmpge_ps(a, b);
}
#if defined(SIMDE_SSE_ENABLE_NATIVE_ALIASES)
#  define _mm_cmpnlt_ps(a, b) simde_mm_cmpnlt_ps((a), (b))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128
simde_mm_cmpnlt_ss (simde__m128 a, simde__m128 b) {
  return simde_mm_cmpge_ss(a, b);
}
#if defined(SIMDE_SSE_ENABLE_NATIVE_ALIASES)
#  define _mm_cmpnlt_ss(a, b) simde_mm_cmpnlt_ss((a), (b))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128
simde_mm_cmpord_ps (simde__m128 a, simde__m128 b) {
#if defined(SIMDE_SSE_NATIVE)
  return _mm_cmpord_ps(a, b);
#else
  simde__m128_private
    r_,
    a_ = simde__m128_to_private(a),
    b_ = simde__m128_to_private(b);

#if defined(SIMDE_SSE_NEON)
  /* Note: NEON does not have ordered compare builtin
     Need to compare a eq a and b eq b to check for NaN
     Do AND of results to get final */
  uint32x4_t ceqaa = vceqq_f32(a_.neon_f32, a_.neon_f32);
  uint32x4_t ceqbb = vceqq_f32(b_.neon_f32, b_.neon_f32);
  r_.neon_u32 = vandq_u32(ceqaa, ceqbb);
#elif defined(simde_isnanf)
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.f32) / sizeof(r_.f32[0])) ; i++) {
    r_.u32[i] = (simde_isnanf(a_.f32[i]) || simde_isnanf(b_.f32[i])) ? UINT32_C(0) : ~UINT32_C(0);
  }
#else
  HEDLEY_UNREACHABLE();
#endif

  return simde__m128_from_private(r_);
#endif
}
#if defined(SIMDE_SSE_ENABLE_NATIVE_ALIASES)
#  define _mm_cmpord_ps(a, b) simde_mm_cmpord_ps((a), (b))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128
simde_mm_cmpunord_ps (simde__m128 a, simde__m128 b) {
#if defined(SIMDE_SSE_NATIVE)
  return _mm_cmpunord_ps(a, b);
#else
  simde__m128_private
    r_,
    a_ = simde__m128_to_private(a),
    b_ = simde__m128_to_private(b);

#if defined(simde_isnanf)
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.f32) / sizeof(r_.f32[0])) ; i++) {
    r_.u32[i] = (simde_isnanf(a_.f32[i]) || simde_isnanf(b_.f32[i])) ? ~UINT32_C(0) : UINT32_C(0);
  }
#else
  HEDLEY_UNREACHABLE();
#endif

  return simde__m128_from_private(r_);
#endif
}
#if defined(SIMDE_SSE_ENABLE_NATIVE_ALIASES)
#  define _mm_cmpunord_ps(a, b) simde_mm_cmpunord_ps((a), (b))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128
simde_mm_cmpunord_ss (simde__m128 a, simde__m128 b) {
#if defined(SIMDE_SSE_NATIVE) && !defined(__PGI)
  return _mm_cmpunord_ss(a, b);
#elif defined(SIMDE_ASSUME_VECTORIZATION)
  return simde_mm_move_ss(a, simde_mm_cmpunord_ps(a, b));
#else
  simde__m128_private
    r_,
    a_ = simde__m128_to_private(a),
    b_ = simde__m128_to_private(b);

#if defined(simde_isnanf)
  r_.u32[0] = (simde_isnanf(a_.f32[0]) || simde_isnanf(b_.f32[0])) ? ~UINT32_C(0) : UINT32_C(0);
  SIMDE__VECTORIZE
  for (size_t i = 1 ; i < (sizeof(r_.u32) / sizeof(r_.u32[0])) ; i++) {
    r_.u32[i] = a_.u32[i];
  }
#else
  HEDLEY_UNREACHABLE();
#endif

  return simde__m128_from_private(r_);
#endif
}
#if defined(SIMDE_SSE_ENABLE_NATIVE_ALIASES)
#  define _mm_cmpunord_ss(a, b) simde_mm_cmpunord_ss((a), (b))
#endif

SIMDE__FUNCTION_ATTRIBUTES
int
simde_mm_comieq_ss (simde__m128 a, simde__m128 b) {
#if defined(SIMDE_SSE_NATIVE)
  return _mm_comieq_ss(a, b);
#else
  simde__m128_private
    a_ = simde__m128_to_private(a),
    b_ = simde__m128_to_private(b);

#if defined(SIMDE_SSE_NEON)
  uint32x4_t a_not_nan = vceqq_f32(a_.neon_f32, a_.neon_f32);
  uint32x4_t b_not_nan = vceqq_f32(b_.neon_f32, b_.neon_f32);
  uint32x4_t a_or_b_nan = vmvnq_u32(vandq_u32(a_not_nan, b_not_nan));
  uint32x4_t a_eq_b = vceqq_f32(a_.neon_f32, b_.neon_f32);
  return !!(vgetq_lane_u32(vorrq_u32(a_or_b_nan, a_eq_b), 0) != 0);
#else
  return a_.f32[0] == b_.f32[0];
#endif
#endif
}
#if defined(SIMDE_SSE_ENABLE_NATIVE_ALIASES)
#  define _mm_comieq_ss(a, b) simde_mm_comieq_ss((a), (b))
#endif

SIMDE__FUNCTION_ATTRIBUTES
int
simde_mm_comige_ss (simde__m128 a, simde__m128 b) {
#if defined(SIMDE_SSE_NATIVE)
  return _mm_comige_ss(a, b);
#else
  simde__m128_private
    a_ = simde__m128_to_private(a),
    b_ = simde__m128_to_private(b);

#if defined(SIMDE_SSE_NEON)
  uint32x4_t a_not_nan = vceqq_f32(a_.neon_f32, a_.neon_f32);
  uint32x4_t b_not_nan = vceqq_f32(b_.neon_f32, b_.neon_f32);
  uint32x4_t a_and_b_not_nan = vandq_u32(a_not_nan, b_not_nan);
  uint32x4_t a_ge_b = vcgeq_f32(a_.neon_f32, b_.neon_f32);
  return !!(vgetq_lane_u32(vandq_u32(a_and_b_not_nan, a_ge_b), 0) != 0);
#else
  return a_.f32[0] >= b_.f32[0];
#endif
#endif
}
#if defined(SIMDE_SSE_ENABLE_NATIVE_ALIASES)
#  define _mm_comige_ss(a, b) simde_mm_comige_ss((a), (b))
#endif

SIMDE__FUNCTION_ATTRIBUTES
int
simde_mm_comigt_ss (simde__m128 a, simde__m128 b) {
#if defined(SIMDE_SSE_NATIVE)
  return _mm_comigt_ss(a, b);
#else
  simde__m128_private
    a_ = simde__m128_to_private(a),
    b_ = simde__m128_to_private(b);

#if defined(SIMDE_SSE_NEON)
  uint32x4_t a_not_nan = vceqq_f32(a_.neon_f32, a_.neon_f32);
  uint32x4_t b_not_nan = vceqq_f32(b_.neon_f32, b_.neon_f32);
  uint32x4_t a_and_b_not_nan = vandq_u32(a_not_nan, b_not_nan);
  uint32x4_t a_gt_b = vcgtq_f32(a_.neon_f32, b_.neon_f32);
  return !!(vgetq_lane_u32(vandq_u32(a_and_b_not_nan, a_gt_b), 0) != 0);
#else
  return a_.f32[0] > b_.f32[0];
#endif
#endif
}
#if defined(SIMDE_SSE_ENABLE_NATIVE_ALIASES)
#  define _mm_comigt_ss(a, b) simde_mm_comigt_ss((a), (b))
#endif

SIMDE__FUNCTION_ATTRIBUTES
int
simde_mm_comile_ss (simde__m128 a, simde__m128 b) {
#if defined(SIMDE_SSE_NATIVE)
  return _mm_comile_ss(a, b);
#else
  simde__m128_private
    a_ = simde__m128_to_private(a),
    b_ = simde__m128_to_private(b);

#if defined(SIMDE_SSE_NEON)
  uint32x4_t a_not_nan = vceqq_f32(a_.neon_f32, a_.neon_f32);
  uint32x4_t b_not_nan = vceqq_f32(b_.neon_f32, b_.neon_f32);
  uint32x4_t a_or_b_nan = vmvnq_u32(vandq_u32(a_not_nan, b_not_nan));
  uint32x4_t a_le_b = vcleq_f32(a_.neon_f32, b_.neon_f32);
  return !!(vgetq_lane_u32(vorrq_u32(a_or_b_nan, a_le_b), 0) != 0);
#else
  return a_.f32[0] <= b_.f32[0];
#endif
#endif
}
#if defined(SIMDE_SSE_ENABLE_NATIVE_ALIASES)
#  define _mm_comile_ss(a, b) simde_mm_comile_ss((a), (b))
#endif

SIMDE__FUNCTION_ATTRIBUTES
int
simde_mm_comilt_ss (simde__m128 a, simde__m128 b) {
#if defined(SIMDE_SSE_NATIVE)
  return _mm_comilt_ss(a, b);
#else
  simde__m128_private
    a_ = simde__m128_to_private(a),
    b_ = simde__m128_to_private(b);

#if defined(SIMDE_SSE_NEON)
  uint32x4_t a_not_nan = vceqq_f32(a_.neon_f32, a_.neon_f32);
  uint32x4_t b_not_nan = vceqq_f32(b_.neon_f32, b_.neon_f32);
  uint32x4_t a_or_b_nan = vmvnq_u32(vandq_u32(a_not_nan, b_not_nan));
  uint32x4_t a_lt_b = vcltq_f32(a_.neon_f32, b_.neon_f32);
  return !!(vgetq_lane_u32(vorrq_u32(a_or_b_nan, a_lt_b), 0) != 0);
#else
  return a_.f32[0] < b_.f32[0];
#endif
#endif
}
#if defined(SIMDE_SSE_ENABLE_NATIVE_ALIASES)
#  define _mm_comilt_ss(a, b) simde_mm_comilt_ss((a), (b))
#endif

SIMDE__FUNCTION_ATTRIBUTES
int
simde_mm_comineq_ss (simde__m128 a, simde__m128 b) {
#if defined(SIMDE_SSE_NATIVE)
  return _mm_comineq_ss(a, b);
#else
  simde__m128_private
    a_ = simde__m128_to_private(a),
    b_ = simde__m128_to_private(b);

#if defined(SIMDE_SSE_NEON)
  uint32x4_t a_not_nan = vceqq_f32(a_.neon_f32, a_.neon_f32);
  uint32x4_t b_not_nan = vceqq_f32(b_.neon_f32, b_.neon_f32);
  uint32x4_t a_and_b_not_nan = vandq_u32(a_not_nan, b_not_nan);
  uint32x4_t a_neq_b = vmvnq_u32(vceqq_f32(a_.neon_f32, b_.neon_f32));
  return !!(vgetq_lane_u32(vandq_u32(a_and_b_not_nan, a_neq_b), 0) != 0);
#else
  return a_.f32[0] != b_.f32[0];
#endif
#endif
}
#if defined(SIMDE_SSE_ENABLE_NATIVE_ALIASES)
#  define _mm_comineq_ss(a, b) simde_mm_comineq_ss((a), (b))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128
simde_mm_cvt_pi2ps (simde__m128 a, simde__m64 b) {
#if defined(SIMDE_SSE_NATIVE) && defined(SIMDE_ARCH_X86_MMX)
  return _mm_cvt_pi2ps(a, b);
#else
  simde__m128_private
    r_,
    a_ = simde__m128_to_private(a);
  simde__m64_private b_ = simde__m64_to_private(b);

#if defined(SIMDE_SSE_NEON)
  r_.neon_f32 = vcombine_f32(vcvt_f32_s32(b_.neon_i32), vget_high_f32(a_.neon_f32));
#elif defined(SIMDE__CONVERT_VECTOR)
  SIMDE__CONVERT_VECTOR(r_.m64_private[0].f32, b_.i32);
  r_.m64_private[1] = a_.m64_private[1];

#else
  r_.f32[0] = (simde_float32) b_.i32[0];
  r_.f32[1] = (simde_float32) b_.i32[1];
  r_.i32[2] = a_.i32[2];
  r_.i32[3] = a_.i32[3];
#endif

  return simde__m128_from_private(r_);
#endif
}
#if defined(SIMDE_SSE_ENABLE_NATIVE_ALIASES)
#  define _mm_cvt_pi2ps(a, b) simde_mm_cvt_pi2ps((a), b)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_mm_cvt_ps2pi (simde__m128 a) {
#if defined(SIMDE_SSE_NATIVE) && defined(SIMDE_ARCH_X86_MMX)
  return _mm_cvt_ps2pi(a);
#else
  simde__m64_private r_;
  simde__m128_private a_ = simde__m128_to_private(a);

#if defined(SIMDE_SSE_NEON)
  r_.neon_i32 = vcvt_s32_f32(vget_low_f32(a_.neon_f32));
#elif defined(SIMDE__CONVERT_VECTOR) && !defined(__clang__)
  SIMDE__CONVERT_VECTOR(r_.i32, a_.m64_private[0].f32);
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.i32) / sizeof(r_.i32[0])) ; i++) {
    r_.i32[i] = (int32_t) a_.f32[i];
  }
#endif

  return simde__m64_from_private(r_);
#endif
}
#if defined(SIMDE_SSE_ENABLE_NATIVE_ALIASES)
#  define _mm_cvt_ps2pi(a) simde_mm_cvt_ps2pi((a))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128
simde_mm_cvt_si2ss (simde__m128 a, int32_t b) {
#if defined(SIMDE_SSE_NATIVE)
  return _mm_cvt_si2ss(a, b);
#else
  simde__m128_private
    r_,
    a_ = simde__m128_to_private(a);

#if defined(SIMDE_SSE_NEON)
  r_.neon_f32 = vsetq_lane_f32((float) b, a_.neon_f32, 0);
#else
  r_.f32[0] = (simde_float32) b;
  r_.i32[1] = a_.i32[1];
  r_.i32[2] = a_.i32[2];
  r_.i32[3] = a_.i32[3];
#endif

  return simde__m128_from_private(r_);
#endif
}
#if defined(SIMDE_SSE_ENABLE_NATIVE_ALIASES)
#  define _mm_cvt_si2ss(a, b) simde_mm_cvt_si2ss((a), b)
#endif

SIMDE__FUNCTION_ATTRIBUTES
int32_t
simde_mm_cvt_ss2si (simde__m128 a) {
#if defined(SIMDE_SSE_NATIVE)
  return _mm_cvt_ss2si(a);
#else
  simde__m128_private a_ = simde__m128_to_private(a);

  #if defined(SIMDE_SSE_NEON)
    return SIMDE_CONVERT_FTOI(int32_t, nearbyintf(vgetq_lane_f32(a_.neon_f32, 0)));
  #elif defined(SIMDE_HAVE_MATH_H)
    return SIMDE_CONVERT_FTOI(int32_t, nearbyintf(a_.f32[0]));
  #else
    HEDLEY_UNREACHABLE();
  #endif
#endif
}
#if defined(SIMDE_SSE_ENABLE_NATIVE_ALIASES)
#  define _mm_cvt_ss2si(a) simde_mm_cvt_ss2si((a))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128
simde_mm_cvtpi16_ps (simde__m64 a) {
#if defined(SIMDE_SSE_NATIVE) && defined(SIMDE_ARCH_X86_MMX)
  return _mm_cvtpi16_ps(a);
#else
  simde__m128_private r_;
  simde__m64_private a_ = simde__m64_to_private(a);

#if defined(SIMDE_SSE_NEON) && 0 /* TODO */
  r_.neon_f32 = vmovl_s16(vget_low_s16(vuzp1q_s16(a_.neon_i16, vmovq_n_s16(0))));
#elif defined(SIMDE__CONVERT_VECTOR)
  SIMDE__CONVERT_VECTOR(r_.f32, a_.i16);
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.f32) / sizeof(r_.f32[0])) ; i++) {
    simde_float32 v = a_.i16[i];
    r_.f32[i] = v;
  }
#endif

  return simde__m128_from_private(r_);
#endif
}
#if defined(SIMDE_SSE_ENABLE_NATIVE_ALIASES)
#  define _mm_cvtpi16_ps(a) simde_mm_cvtpi16_ps(a)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128
simde_mm_cvtpi32_ps (simde__m128 a, simde__m64 b) {
#if defined(SIMDE_SSE_NATIVE) && defined(SIMDE_ARCH_X86_MMX)
  return _mm_cvtpi32_ps(a, b);
#else
  simde__m128_private
    r_,
    a_ = simde__m128_to_private(a);
  simde__m64_private b_ = simde__m64_to_private(b);

#if defined(SIMDE_SSE_NEON)
  r_.neon_f32 = vcombine_f32(vcvt_f32_s32(b_.neon_i32), vget_high_f32(a_.neon_f32));
#elif defined(SIMDE__CONVERT_VECTOR)
  SIMDE__CONVERT_VECTOR(r_.m64_private[0].f32, b_.i32);
  r_.m64_private[1] = a_.m64_private[1];
#else
  r_.f32[0] = (simde_float32) b_.i32[0];
  r_.f32[1] = (simde_float32) b_.i32[1];
  r_.i32[2] = a_.i32[2];
  r_.i32[3] = a_.i32[3];
#endif

  return simde__m128_from_private(r_);
#endif
}
#if defined(SIMDE_SSE_ENABLE_NATIVE_ALIASES)
#  define _mm_cvtpi32_ps(a, b) simde_mm_cvtpi32_ps((a), b)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128
simde_mm_cvtpi32x2_ps (simde__m64 a, simde__m64 b) {
#if defined(SIMDE_SSE_NATIVE) && defined(SIMDE_ARCH_X86_MMX)
  return _mm_cvtpi32x2_ps(a, b);
#else
  simde__m128_private r_;
  simde__m64_private
    a_ = simde__m64_to_private(a),
    b_ = simde__m64_to_private(b);

#if defined(SIMDE_SSE_NEON)
  r_.neon_f32 = vcvtq_f32_s32(vcombine_s32(a_.neon_i32, b_.neon_i32));
#elif defined(SIMDE__CONVERT_VECTOR)
  SIMDE__CONVERT_VECTOR(r_.m64_private[0].f32, a_.i32);
  SIMDE__CONVERT_VECTOR(r_.m64_private[1].f32, b_.i32);
#else
  r_.f32[0] = (simde_float32) a_.i32[0];
  r_.f32[1] = (simde_float32) a_.i32[1];
  r_.f32[2] = (simde_float32) b_.i32[0];
  r_.f32[3] = (simde_float32) b_.i32[1];
#endif

  return simde__m128_from_private(r_);
#endif
}
#if defined(SIMDE_SSE_ENABLE_NATIVE_ALIASES)
#  define _mm_cvtpi32x2_ps(a, b) simde_mm_cvtpi32x2_ps(a, b)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128
simde_mm_cvtpi8_ps (simde__m64 a) {
#if defined(SIMDE_SSE_NATIVE) && defined(SIMDE_ARCH_X86_MMX)
  return _mm_cvtpi8_ps(a);
#else
  simde__m128_private r_;
  simde__m64_private a_ = simde__m64_to_private(a);

#if defined(SIMDE_SSE_NEON)
  r_.neon_f32 = vcvtq_f32_s32(vmovl_s16(vget_low_s16(vmovl_s8(a_.neon_i8))));
#else
  r_.f32[0] = (simde_float32) a_.i8[0];
  r_.f32[1] = (simde_float32) a_.i8[1];
  r_.f32[2] = (simde_float32) a_.i8[2];
  r_.f32[3] = (simde_float32) a_.i8[3];
#endif

  return simde__m128_from_private(r_);
#endif
}
#if defined(SIMDE_SSE_ENABLE_NATIVE_ALIASES)
#  define _mm_cvtpi8_ps(a) simde_mm_cvtpi8_ps(a)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_mm_cvtps_pi16 (simde__m128 a) {
#if defined(SIMDE_SSE_NATIVE) && defined(SIMDE_ARCH_X86_MMX)
  return _mm_cvtps_pi16(a);
#else
  simde__m64_private r_;
  simde__m128_private a_ = simde__m128_to_private(a);

  #if defined(SIMDE__CONVERT_VECTOR)
    SIMDE__CONVERT_VECTOR(r_.i16, a_.f32);
  #elif defined(SIMDE_SSE_NEON)
    r_.neon_i16 = vmovn_s32(vcvtq_s32_f32(a_.neon_f32));
  #else
    SIMDE__VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.i16) / sizeof(r_.i16[0])) ; i++) {
      r_.i16[i] = SIMDE_CONVERT_FTOI(int16_t, a_.f32[i]);
    }
  #endif

  return simde__m64_from_private(r_);
#endif
}
#if defined(SIMDE_SSE_ENABLE_NATIVE_ALIASES)
#  define _mm_cvtps_pi16(a) simde_mm_cvtps_pi16((a))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_mm_cvtps_pi32 (simde__m128 a) {
#if defined(SIMDE_SSE_NATIVE) && defined(SIMDE_ARCH_X86_MMX)
  return _mm_cvtps_pi32(a);
#else
  simde__m64_private r_;
  simde__m128_private a_ = simde__m128_to_private(a);

#if defined(SIMDE_SSE_NEON)
  r_.neon_i32 = vcvt_s32_f32(vget_low_f32(a_.neon_f32));
#elif defined(SIMDE__CONVERT_VECTOR)
  SIMDE__CONVERT_VECTOR(r_.i32, a_.m64_private[0].f32);
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.i32) / sizeof(r_.i32[0])) ; i++) {
    r_.i32[i] = SIMDE_CONVERT_FTOI(int32_t, a_.f32[i]);
  }
#endif

  return simde__m64_from_private(r_);
#endif
}
#if defined(SIMDE_SSE_ENABLE_NATIVE_ALIASES)
#  define _mm_cvtps_pi32(a) simde_mm_cvtps_pi32((a))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_mm_cvtps_pi8 (simde__m128 a) {
#if defined(SIMDE_SSE_NATIVE) && defined(SIMDE_ARCH_X86_MMX)
  return _mm_cvtps_pi8(a);
#else
  simde__m64_private r_;
  simde__m128_private a_ = simde__m128_to_private(a);

#if defined(SIMDE_SSE_NEON)
  int16x4_t b = vmovn_s32(vcvtq_s32_f32(a_.neon_f32));
  int16x8_t c = vcombine_s16(b, vmov_n_s16(0));
  r_.neon_i8 = vmovn_s16(c);
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(a_.f32) / sizeof(a_.f32[0])) ; i++) {
    r_.i8[i] = SIMDE_CONVERT_FTOI(int8_t, a_.f32[i]);
  }
  /* Note: the upper half is undefined */
#endif

  return simde__m64_from_private(r_);
#endif
}
#if defined(SIMDE_SSE_ENABLE_NATIVE_ALIASES)
#  define _mm_cvtps_pi8(a) simde_mm_cvtps_pi8((a))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128
simde_mm_cvtpu16_ps (simde__m64 a) {
#if defined(SIMDE_SSE_NATIVE) && defined(SIMDE_ARCH_X86_MMX)
  return _mm_cvtpu16_ps(a);
#else
  simde__m128_private r_;
  simde__m64_private a_ = simde__m64_to_private(a);

#if defined(SIMDE_SSE_NEON)
  r_.neon_f32 = vcvtq_f32_u32(vmovl_u16(a_.neon_u16));
#elif defined(SIMDE__CONVERT_VECTOR)
  SIMDE__CONVERT_VECTOR(r_.f32, a_.u16);
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.f32) / sizeof(r_.f32[0])) ; i++) {
    r_.f32[i] = (simde_float32) a_.u16[i];
  }
#endif

  return simde__m128_from_private(r_);
#endif
}
#if defined(SIMDE_SSE_ENABLE_NATIVE_ALIASES)
#  define _mm_cvtpu16_ps(a) simde_mm_cvtpu16_ps(a)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128
simde_mm_cvtpu8_ps (simde__m64 a) {
#if defined(SIMDE_SSE_NATIVE) && defined(SIMDE_ARCH_X86_MMX)
  return _mm_cvtpu8_ps(a);
#else
  simde__m128_private r_;
  simde__m64_private a_ = simde__m64_to_private(a);

#if defined(SIMDE_SSE_NEON)
  r_.neon_f32 = vcvtq_f32_u32(vmovl_u16(vget_low_u16(vmovl_u8(a_.neon_u8))));
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.f32) / sizeof(r_.f32[0])) ; i++) {
    r_.f32[i] = (simde_float32) a_.u8[i];
  }
#endif

  return simde__m128_from_private(r_);
#endif
}
#if defined(SIMDE_SSE_ENABLE_NATIVE_ALIASES)
#  define _mm_cvtpu8_ps(a) simde_mm_cvtpu8_ps(a)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128
  simde_mm_cvtsi32_ss (simde__m128 a, int32_t b) {
#if defined(SIMDE_SSE_NATIVE)
  return _mm_cvtsi32_ss(a, b);
#else
  simde__m128_private r_;
  simde__m128_private a_ = simde__m128_to_private(a);

#if defined(SIMDE_SSE_NEON)
  r_.neon_f32 = vsetq_lane_f32((simde_float32) b, a_.neon_f32, 0);
#else
  r_.f32[0] = (simde_float32) b;
  SIMDE__VECTORIZE
  for (size_t i = 1 ; i < (sizeof(r_.i32) / sizeof(r_.i32[0])) ; i++) {
    r_.i32[i] = a_.i32[i];
  }
#endif

  return simde__m128_from_private(r_);
#endif
}
#if defined(SIMDE_SSE_ENABLE_NATIVE_ALIASES)
#  define _mm_cvtsi32_ss(a, b) simde_mm_cvtsi32_ss((a), b)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128
simde_mm_cvtsi64_ss (simde__m128 a, int64_t b) {
#if defined(SIMDE_SSE_NATIVE) && defined(SIMDE_ARCH_AMD64)
  #if !defined(__PGI)
    return _mm_cvtsi64_ss(a, b);
  #else
    return _mm_cvtsi64x_ss(a, b);
  #endif
#else
  simde__m128_private r_;
  simde__m128_private a_ = simde__m128_to_private(a);

#if defined(SIMDE_SSE_NEON)
  r_.neon_f32 = vsetq_lane_f32((simde_float32) b, a_.neon_f32, 0);
#else
  r_ = a_;
  r_.f32[0] = (simde_float32) b;
#endif

  return simde__m128_from_private(r_);
#endif
}
#if defined(SIMDE_SSE_ENABLE_NATIVE_ALIASES)
#  define _mm_cvtsi64_ss(a, b) simde_mm_cvtsi64_ss((a), b)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde_float32
simde_mm_cvtss_f32 (simde__m128 a) {
#if defined(SIMDE_SSE_NATIVE)
  return _mm_cvtss_f32(a);
#else
  simde__m128_private a_ = simde__m128_to_private(a);
#if defined(SIMDE_SSE_NEON)
  return vgetq_lane_f32(a_.neon_f32, 0);
#else
  return a_.f32[0];
#endif
#endif
}
#if defined(SIMDE_SSE_ENABLE_NATIVE_ALIASES)
#  define _mm_cvtss_f32(a) simde_mm_cvtss_f32((a))
#endif

SIMDE__FUNCTION_ATTRIBUTES
int32_t
simde_mm_cvtss_si32 (simde__m128 a) {
  return simde_mm_cvt_ss2si(a);
}
#if defined(SIMDE_SSE_ENABLE_NATIVE_ALIASES)
#  define _mm_cvtss_si32(a) simde_mm_cvtss_si32((a))
#endif

SIMDE__FUNCTION_ATTRIBUTES
int64_t
simde_mm_cvtss_si64 (simde__m128 a) {
#if defined(SIMDE_SSE_NATIVE) && defined(SIMDE_ARCH_AMD64)
  #if !defined(__PGI)
    return _mm_cvtss_si64(a);
  #else
    return _mm_cvtss_si64x(a);
  #endif
#else
  simde__m128_private a_ = simde__m128_to_private(a);
  #if defined(SIMDE_SSE_NEON)
    return SIMDE_CONVERT_FTOI(int64_t, vgetq_lane_f32(a_.neon_f32, 0));
  #else
    return SIMDE_CONVERT_FTOI(int64_t, a_.f32[0]);
  #endif
#endif
}
#if defined(SIMDE_SSE_ENABLE_NATIVE_ALIASES)
#  define _mm_cvtss_si64(a) simde_mm_cvtss_si64((a))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_mm_cvtt_ps2pi (simde__m128 a) {
#if defined(SIMDE_SSE_NATIVE) && defined(SIMDE_ARCH_X86_MMX)
  return _mm_cvtt_ps2pi(a);
#else
  simde__m64_private r_;
  simde__m128_private a_ = simde__m128_to_private(a);

#if defined(SIMDE_SSE_NEON)
  r_.neon_i32 = vcvt_s32_f32(vget_low_f32(a_.neon_f32));
#elif defined(SIMDE__CONVERT_VECTOR)
  SIMDE__CONVERT_VECTOR(r_.i32, a_.m64_private[0].f32);
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.f32) / sizeof(r_.f32[0])) ; i++) {
    r_.i32[i] = SIMDE_CONVERT_FTOI(int32_t, a_.f32[i]);
  }
#endif

  return simde__m64_from_private(r_);
#endif
}
#define simde_mm_cvttps_pi32(a) simde_mm_cvtt_ps2pi(a)
#if defined(SIMDE_SSE_ENABLE_NATIVE_ALIASES)
#  define _mm_cvtt_ps2pi(a) simde_mm_cvtt_ps2pi((a))
#  define _mm_cvttps_pi32(a) simde_mm_cvttps_pi32((a))
#endif

SIMDE__FUNCTION_ATTRIBUTES
int32_t
simde_mm_cvtt_ss2si (simde__m128 a) {
#if defined(SIMDE_SSE_NATIVE)
  return _mm_cvtt_ss2si(a);
#else
  simde__m128_private a_ = simde__m128_to_private(a);

#if defined(SIMDE_SSE_NEON)
  return SIMDE_CONVERT_FTOI(int32_t, vgetq_lane_f32(a_.neon_f32, 0));
#else
  return SIMDE_CONVERT_FTOI(int32_t, a_.f32[0]);
#endif
#endif
}
#if defined(SIMDE_SSE_ENABLE_NATIVE_ALIASES)
#  define _mm_cvtt_ss2si(a) simde_mm_cvtt_ss2si((a))
#  define _mm_cvttss_si32(a) simde_mm_cvttss_si32((a))
#endif

SIMDE__FUNCTION_ATTRIBUTES
int64_t
simde_mm_cvttss_si64 (simde__m128 a) {
#if defined(SIMDE_SSE_NATIVE) && defined(SIMDE_ARCH_AMD64) && !defined(_MSC_VER)
  #if defined(__PGI)
    return _mm_cvttss_si64x(a);
  #else
    return _mm_cvttss_si64(a);
  #endif
#else
  simde__m128_private a_ = simde__m128_to_private(a);

#if defined(SIMDE_SSE_NEON)
  return SIMDE_CONVERT_FTOI(int64_t, vgetq_lane_f32(a_.neon_f32, 0));
#else
  return SIMDE_CONVERT_FTOI(int64_t, a_.f32[0]);
#endif
#endif
}
#if defined(SIMDE_SSE_ENABLE_NATIVE_ALIASES)
#  define _mm_cvttss_si64(a) simde_mm_cvttss_si64((a))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128
simde_mm_cmpord_ss (simde__m128 a, simde__m128 b) {
#if defined(SIMDE_SSE_NATIVE)
  return _mm_cmpord_ss(a, b);
#elif defined(SIMDE_ASSUME_VECTORIZATION)
  return simde_mm_move_ss(a, simde_mm_cmpord_ps(a, b));
#else
  simde__m128_private
    r_,
    a_ = simde__m128_to_private(a);

#if defined(simde_isnanf)
  r_.u32[0] = (simde_isnanf(simde_mm_cvtss_f32(a)) || simde_isnanf(simde_mm_cvtss_f32(b))) ? UINT32_C(0) : ~UINT32_C(0);
  SIMDE__VECTORIZE
  for (size_t i = 1 ; i < (sizeof(r_.f32) / sizeof(r_.f32[0])) ; i++) {
    r_.u32[i] = a_.u32[i];
  }
#else
  HEDLEY_UNREACHABLE();
#endif

  return simde__m128_from_private(r_);
#endif
}
#if defined(SIMDE_SSE_ENABLE_NATIVE_ALIASES)
#  define _mm_cmpord_ss(a, b) simde_mm_cmpord_ss((a), (b))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128
simde_mm_div_ps (simde__m128 a, simde__m128 b) {
#if defined(SIMDE_SSE_NATIVE)
  return _mm_div_ps(a, b);
#else
  simde__m128_private
    r_,
    a_ = simde__m128_to_private(a),
    b_ = simde__m128_to_private(b);

#if defined(SIMDE_SSE_NEON) && defined(SIMDE_ARCH_AARCH64)
  r_.neon_f32 = vdivq_f32(a_.neon_f32, b_.neon_f32);
#elif defined(SIMDE_SSE_NEON)
  float32x4_t recip0 = vrecpeq_f32(b_.neon_f32);
  float32x4_t recip1 = vmulq_f32(recip0, vrecpsq_f32(recip0, b_.neon_f32));
  r_.neon_f32 = vmulq_f32(a_.neon_f32, recip1);
#elif defined(SIMDE_SSE_WASM_SIMD128)
    r_.wasm_v128 =  wasm_f32x4_div(a_.wasm_v128, b_.wasm_v128);
#elif defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
  r_.f32 = a_.f32 / b_.f32;
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.f32) / sizeof(r_.f32[0])) ; i++) {
    r_.f32[i] = a_.f32[i] / b_.f32[i];
  }
#endif

  return simde__m128_from_private(r_);
#endif
}
#if defined(SIMDE_SSE_ENABLE_NATIVE_ALIASES)
#  define _mm_div_ps(a, b) simde_mm_div_ps((a), (b))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128
simde_mm_div_ss (simde__m128 a, simde__m128 b) {
#if defined(SIMDE_SSE_NATIVE)
  return _mm_div_ss(a, b);
#elif defined(SIMDE_ASSUME_VECTORIZATION)
  return simde_mm_move_ss(a, simde_mm_div_ps(a, b));
#else
  simde__m128_private
    r_,
    a_ = simde__m128_to_private(a),
    b_ = simde__m128_to_private(b);

  r_.f32[0] = a_.f32[0] / b_.f32[0];
  SIMDE__VECTORIZE
  for (size_t i = 1 ; i < (sizeof(r_.f32) / sizeof(r_.f32[0])) ; i++) {
    r_.f32[i] = a_.f32[i];
  }

  return simde__m128_from_private(r_);
#endif
}
#if defined(SIMDE_SSE_ENABLE_NATIVE_ALIASES)
#  define _mm_div_ss(a, b) simde_mm_div_ss((a), (b))
#endif

SIMDE__FUNCTION_ATTRIBUTES
int16_t
simde_mm_extract_pi16 (simde__m64 a, const int imm8)
    HEDLEY_REQUIRE_MSG((imm8 & 3) == imm8, "imm8 must be in range [0, 3]") {
  simde__m64_private a_ = simde__m64_to_private(a);
  return a_.i16[imm8];
}
#if defined(SIMDE_SSE_NATIVE) && defined(SIMDE_ARCH_X86_MMX) && !defined(HEDLEY_PGI_VERSION)
#  if HEDLEY_HAS_WARNING("-Wvector-conversion")
     /* https://bugs.llvm.org/show_bug.cgi?id=44589 */
#    define simde_mm_extract_pi16(a, imm8) ( \
         HEDLEY_DIAGNOSTIC_PUSH \
         _Pragma("clang diagnostic ignored \"-Wvector-conversion\"") \
         HEDLEY_STATIC_CAST(int16_t, _mm_extract_pi16((a), (imm8))) \
         HEDLEY_DIAGNOSTIC_POP \
       )
#  else
#    define simde_mm_extract_pi16(a, imm8) ((int16_t) (_mm_extract_pi16(a, imm8)))
#  endif
#elif defined(SIMDE_SSE_NEON)
#  define simde_mm_extract_pi16(a, imm8) ((int16_t) (vget_lane_s16(simde__m64_to_private(a).neon_i16, imm8)))
#endif
#define simde_m_pextrw(a, imm8) simde_mm_extract_pi16(a, imm8)

enum {
#if defined(SIMDE_SSE_NATIVE)
  SIMDE_MM_ROUND_NEAREST     = _MM_ROUND_NEAREST,
  SIMDE_MM_ROUND_DOWN        = _MM_ROUND_DOWN,
  SIMDE_MM_ROUND_UP          = _MM_ROUND_UP,
  SIMDE_MM_ROUND_TOWARD_ZERO = _MM_ROUND_TOWARD_ZERO
#else
  SIMDE_MM_ROUND_NEAREST
#if defined(FE_TONEAREST)
  = FE_TONEAREST
#endif
  ,

  SIMDE_MM_ROUND_DOWN
#if defined(FE_DOWNWARD)
  = FE_DOWNWARD
#endif
  ,

  SIMDE_MM_ROUND_UP
#if defined(FE_UPWARD)
  = FE_UPWARD
#endif
  ,

  SIMDE_MM_ROUND_TOWARD_ZERO
#if defined(FE_TOWARDZERO)
  = FE_TOWARDZERO
#endif
#endif
};

SIMDE__FUNCTION_ATTRIBUTES
unsigned int
SIMDE_MM_GET_ROUNDING_MODE(void) {
#if defined(SIMDE_SSE_NATIVE)
  return _MM_GET_ROUNDING_MODE();
#elif defined(SIMDE_HAVE_MATH_H)
  return (unsigned int) fegetround();
#else
  HEDLEY_UNREACHABLE();
#endif
}
#if defined(SIMDE_SSE_ENABLE_NATIVE_ALIASES)
#  define _mm_extract_pi16(a, imm8) simde_mm_extract_pi16((a), imm8)
#endif

SIMDE__FUNCTION_ATTRIBUTES
void
SIMDE_MM_SET_ROUNDING_MODE(unsigned int a) {
#if defined(SIMDE_SSE_NATIVE)
  _MM_SET_ROUNDING_MODE(a);
#else
  fesetround((int) a);
#endif
}
#if defined(SIMDE_SSE_ENABLE_NATIVE_ALIASES)
#  define _MM_SET_ROUNDING_MODE(a) SIMDE_MM_SET_ROUNDING_MODE(a)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_mm_insert_pi16 (simde__m64 a, int16_t i, const int imm8)
    HEDLEY_REQUIRE_MSG((imm8 & 3) == imm8, "imm8 must be in range [0, 3]") {
  simde__m64_private
    r_,
    a_ = simde__m64_to_private(a);

  r_.i64[0] = a_.i64[0];
  r_.i16[imm8] = i;

  return simde__m64_from_private(r_);
}
#if defined(SIMDE_SSE_NATIVE) && defined(SIMDE_ARCH_X86_MMX) && !defined(__PGI)
#  if HEDLEY_HAS_WARNING("-Wvector-conversion")
     /* https://bugs.llvm.org/show_bug.cgi?id=44589 */
#    define ssimde_mm_insert_pi16(a, i, imm8) ( \
         HEDLEY_DIAGNOSTIC_PUSH \
         _Pragma("clang diagnostic ignored \"-Wvector-conversion\"") \
        (_mm_insert_pi16((a), (i), (imm8))) \
         HEDLEY_DIAGNOSTIC_POP \
       )
#  else
#    define simde_mm_insert_pi16(a, i, imm8) _mm_insert_pi16(a, i, imm8)
#  endif
#elif defined(SIMDE_SSE_NEON)
#  define simde_mm_insert_pi16(a, i, imm8) simde__m64_from_private((simde__m64_private) { .neon_i16 = vset_lane_s16(i, simde__m64_to_private(a).neon_i16, (imm8)) })
#endif
#define simde_m_pinsrw(a, i, imm8) (simde_mm_insert_pi16(a, i, imm8))
#if defined(SIMDE_SSE_ENABLE_NATIVE_ALIASES)
#  define _mm_insert_pi16(a, i, imm8) simde_mm_insert_pi16(a, i, imm8)
#  define _m_pinsrw(a, i, imm8) simde_mm_insert_pi16(a, i, imm8)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128
simde_mm_load_ps (simde_float32 const mem_addr[HEDLEY_ARRAY_PARAM(4)]) {
  simde_assert_aligned(16, mem_addr);

#if defined(SIMDE_SSE_NATIVE)
  return _mm_load_ps(mem_addr);
#else
  simde__m128_private r_;

#if defined(SIMDE_SSE_NEON)
  r_.neon_f32 = vld1q_f32(mem_addr);
#elif defined(SIMDE_SSE_POWER_ALTIVEC)
  r_.altivec_f32 = vec_ld(0, mem_addr);
#else
  r_ = *SIMDE_CAST_ALIGN(16, simde__m128_private const*, mem_addr);
#endif

  return simde__m128_from_private(r_);
#endif
}
#if defined(SIMDE_SSE_ENABLE_NATIVE_ALIASES)
#  define _mm_load_ps(mem_addr) simde_mm_load_ps(mem_addr)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128
simde_mm_load_ps1 (simde_float32 const* mem_addr) {
#if defined(SIMDE_SSE_NATIVE)
  return _mm_load_ps1(mem_addr);
#else
  simde__m128_private r_;

#if defined(SIMDE_SSE_NEON)
  r_.neon_f32 = vld1q_dup_f32(mem_addr);
#else
  r_ = simde__m128_to_private(simde_mm_set1_ps(*mem_addr));
#endif

  return simde__m128_from_private(r_);
#endif
}
#define simde_mm_load1_ps(mem_addr) simde_mm_load_ps1(mem_addr)
#if defined(SIMDE_SSE_ENABLE_NATIVE_ALIASES)
#  define _mm_load_ps1(mem_addr) simde_mm_load_ps1(mem_addr)
#  define _mm_load1_ps(mem_addr) simde_mm_load_ps1(mem_addr)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128
simde_mm_load_ss (simde_float32 const* mem_addr) {
#if defined(SIMDE_SSE_NATIVE)
  return _mm_load_ss(mem_addr);
#else
  simde__m128_private r_;

#if defined(SIMDE_SSE_NEON)
  r_.neon_f32 = vsetq_lane_f32(*mem_addr, vdupq_n_f32(0), 0);
#else
  r_.f32[0] = *mem_addr;
  r_.i32[1] = 0;
  r_.i32[2] = 0;
  r_.i32[3] = 0;
#endif

  return simde__m128_from_private(r_);
#endif
}
#if defined(SIMDE_SSE_ENABLE_NATIVE_ALIASES)
#  define _mm_load_ss(mem_addr) simde_mm_load_ss(mem_addr)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128
simde_mm_loadh_pi (simde__m128 a, simde__m64 const* mem_addr) {
#if defined(SIMDE_SSE_NATIVE) && defined(SIMDE_ARCH_X86_MMX)
  return _mm_loadh_pi(a, HEDLEY_REINTERPRET_CAST(__m64 const*, mem_addr));
#else
  simde__m128_private
    r_,
    a_ = simde__m128_to_private(a);

#if defined(SIMDE_SSE_NEON)
  r_.neon_f32 = vcombine_f32(vget_low_f32(a_.neon_f32), vld1_f32(HEDLEY_REINTERPRET_CAST(const float32_t*, mem_addr)));
#else
  simde__m64_private b_ = *HEDLEY_REINTERPRET_CAST(simde__m64_private const*, mem_addr);
  r_.f32[0] = a_.f32[0];
  r_.f32[1] = a_.f32[1];
  r_.f32[2] = b_.f32[0];
  r_.f32[3] = b_.f32[1];
#endif

  return simde__m128_from_private(r_);
#endif
}
#if defined(SIMDE_SSE_ENABLE_NATIVE_ALIASES)
#  define _mm_loadh_pi(a, mem_addr) simde_mm_loadh_pi((a), (simde__m64 const*) (mem_addr))
#endif

/* The SSE documentation says that there are no alignment requirements
   for mem_addr.  Unfortunately they used the __m64 type for the argument
   which is supposed to be 8-byte aligned, so some compilers (like clang
   with -Wcast-align) will generate a warning if you try to cast, say,
   a simde_float32* to a simde__m64* for this function.

   I think the choice of argument type is unfortunate, but I do think we
   need to stick to it here.  If there is demand I can always add something
   like simde_x_mm_loadl_f32(simde__m128, simde_float32 mem_addr[2]) */
SIMDE__FUNCTION_ATTRIBUTES
simde__m128
simde_mm_loadl_pi (simde__m128 a, simde__m64 const* mem_addr) {
#if defined(SIMDE_SSE_NATIVE)
  return _mm_loadl_pi(a, HEDLEY_REINTERPRET_CAST(__m64 const*, mem_addr));
#else
  simde__m128_private
    r_,
    a_ = simde__m128_to_private(a);

#if defined(SIMDE_SSE_NEON)
  r_.neon_f32 = vcombine_f32(vld1_f32(HEDLEY_REINTERPRET_CAST(const float32_t*, mem_addr)), vget_high_f32(a_.neon_f32));
#else
  simde__m64_private b_;
  simde_memcpy(&b_, mem_addr, sizeof(b_));
  r_.i32[0] = b_.i32[0];
  r_.i32[1] = b_.i32[1];
  r_.i32[2] = a_.i32[2];
  r_.i32[3] = a_.i32[3];
#endif

  return simde__m128_from_private(r_);
#endif
}
#if defined(SIMDE_SSE_ENABLE_NATIVE_ALIASES)
#  define _mm_loadl_pi(a, mem_addr) simde_mm_loadl_pi((a), (simde__m64 const*) (mem_addr))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128
simde_mm_loadr_ps (simde_float32 const mem_addr[HEDLEY_ARRAY_PARAM(4)]) {
  simde_assert_aligned(16, mem_addr);

#if defined(SIMDE_SSE_NATIVE)
  return _mm_loadr_ps(mem_addr);
#else
  simde__m128_private
    r_,
    v_ = simde__m128_to_private(simde_mm_load_ps(mem_addr));

#if defined(SIMDE_SSE_NEON)
  r_.neon_f32 = vrev64q_f32(v_.neon_f32);
  r_.neon_f32 = vextq_f32(r_.neon_f32, r_.neon_f32, 2);
#elif defined(SIMDE__SHUFFLE_VECTOR)
  r_.f32 = SIMDE__SHUFFLE_VECTOR(32, 16, v_.f32, v_.f32, 3, 2, 1, 0);
#else
  r_.f32[0] = v_.f32[3];
  r_.f32[1] = v_.f32[2];
  r_.f32[2] = v_.f32[1];
  r_.f32[3] = v_.f32[0];
#endif

  return simde__m128_from_private(r_);
#endif
}
#if defined(SIMDE_SSE_ENABLE_NATIVE_ALIASES)
#  define _mm_loadr_ps(mem_addr) simde_mm_loadr_ps(mem_addr)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128
simde_mm_loadu_ps (simde_float32 const mem_addr[HEDLEY_ARRAY_PARAM(4)]) {
#if defined(SIMDE_SSE_NATIVE)
  return _mm_loadu_ps(mem_addr);
#else
  simde__m128_private r_;

#if defined(SIMDE_SSE_NEON)
  r_.neon_f32 = vld1q_f32(HEDLEY_REINTERPRET_CAST(const float32_t*, mem_addr));
#else
  r_.f32[0] = mem_addr[0];
  r_.f32[1] = mem_addr[1];
  r_.f32[2] = mem_addr[2];
  r_.f32[3] = mem_addr[3];
#endif

  return simde__m128_from_private(r_);
#endif
}
#if defined(SIMDE_SSE_ENABLE_NATIVE_ALIASES)
#  define _mm_loadu_ps(mem_addr) simde_mm_loadu_ps(mem_addr)
#endif

SIMDE__FUNCTION_ATTRIBUTES
void
simde_mm_maskmove_si64 (simde__m64 a, simde__m64 mask, int8_t* mem_addr) {
#if defined(SIMDE_SSE_NATIVE) && defined(SIMDE_ARCH_X86_MMX)
  _mm_maskmove_si64(a, mask, HEDLEY_REINTERPRET_CAST(char*, mem_addr));
#else
  simde__m64_private
    a_ = simde__m64_to_private(a),
    mask_ = simde__m64_to_private(mask);

  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(a_.i8) / sizeof(a_.i8[0])) ; i++)
    if (mask_.i8[i] < 0)
      mem_addr[i] = a_.i8[i];
#endif
}
#define simde_m_maskmovq(a, mask, mem_addr) simde_mm_maskmove_si64(a, mask, mem_addr)
#if defined(SIMDE_SSE_ENABLE_NATIVE_ALIASES)
#  define _mm_maskmove_si64(a, mask, mem_addr) simde_mm_maskmove_si64(a, (mask), mem_addr)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_mm_max_pi16 (simde__m64 a, simde__m64 b) {
#if defined(SIMDE_SSE_NATIVE) && defined(SIMDE_ARCH_X86_MMX)
  return _mm_max_pi16(a, b);
#else
  simde__m64_private
    r_,
    a_ = simde__m64_to_private(a),
    b_ = simde__m64_to_private(b);

#if defined(SIMDE_SSE_NEON)
  r_.neon_i16 = vmax_s16(a_.neon_i16, b_.neon_i16);
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.i16) / sizeof(r_.i16[0])) ; i++) {
    r_.i16[i] = (a_.i16[i] > b_.i16[i]) ? a_.i16[i] : b_.i16[i];
  }
#endif

  return simde__m64_from_private(r_);
#endif
}
#define simde_m_pmaxsw(a, b) simde_mm_max_pi16(a, b)
#if defined(SIMDE_SSE_ENABLE_NATIVE_ALIASES)
#  define _mm_max_pi16(a, b) simde_mm_max_pi16(a, b)
#  define _m_pmaxsw(a, b) simde_mm_max_pi16(a, b)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128
simde_mm_max_ps (simde__m128 a, simde__m128 b) {
#if defined(SIMDE_SSE_NATIVE)
  return _mm_max_ps(a, b);
#else
  simde__m128_private
    r_,
    a_ = simde__m128_to_private(a),
    b_ = simde__m128_to_private(b);

#if defined(SIMDE_SSE_NEON)
  r_.neon_f32 = vmaxq_f32(a_.neon_f32, b_.neon_f32);
#elif defined(SIMDE_SSE_POWER_ALTIVEC)
  r_.altivec_f32 = vec_max(a_.altivec_f32, b_.altivec_f32);
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.f32) / sizeof(r_.f32[0])) ; i++) {
    r_.f32[i] = (a_.f32[i] > b_.f32[i]) ? a_.f32[i] : b_.f32[i];
  }
#endif

  return simde__m128_from_private(r_);
#endif
}
#if defined(SIMDE_SSE_ENABLE_NATIVE_ALIASES)
#  define _mm_max_ps(a, b) simde_mm_max_ps((a), (b))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_mm_max_pu8 (simde__m64 a, simde__m64 b) {
#if defined(SIMDE_SSE_NATIVE) && defined(SIMDE_ARCH_X86_MMX)
  return _mm_max_pu8(a, b);
#else
  simde__m64_private
    r_,
    a_ = simde__m64_to_private(a),
    b_ = simde__m64_to_private(b);

#if defined(SIMDE_SSE_NEON)
  r_.neon_u8 = vmax_u8(a_.neon_u8, b_.neon_u8);
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.u8) / sizeof(r_.u8[0])) ; i++) {
    r_.u8[i] = (a_.u8[i] > b_.u8[i]) ? a_.u8[i] : b_.u8[i];
  }
#endif

  return simde__m64_from_private(r_);
#endif
}
#define simde_m_pmaxub(a, b) simde_mm_max_pu8(a, b)
#if defined(SIMDE_SSE_ENABLE_NATIVE_ALIASES)
#  define _mm_max_pu8(a, b) simde_mm_max_pu8(a, b)
#  define _m_pmaxub(a, b) simde_mm_max_pu8(a, b)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128
simde_mm_max_ss (simde__m128 a, simde__m128 b) {
#if defined(SIMDE_SSE_NATIVE)
  return _mm_max_ss(a, b);
#elif defined(SIMDE_ASSUME_VECTORIZATION)
  return simde_mm_move_ss(a, simde_mm_max_ps(a, b));
#else
  simde__m128_private
    r_,
    a_ = simde__m128_to_private(a),
    b_ = simde__m128_to_private(b);

  r_.f32[0] = (a_.f32[0] > b_.f32[0]) ? a_.f32[0] : b_.f32[0];
  r_.f32[1] = a_.f32[1];
  r_.f32[2] = a_.f32[2];
  r_.f32[3] = a_.f32[3];

  return simde__m128_from_private(r_);
#endif
}
#if defined(SIMDE_SSE_ENABLE_NATIVE_ALIASES)
#  define _mm_max_ss(a, b) simde_mm_max_ss((a), (b))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_mm_min_pi16 (simde__m64 a, simde__m64 b) {
#if defined(SIMDE_SSE_NATIVE) && defined(SIMDE_ARCH_X86_MMX)
  return _mm_min_pi16(a, b);
#else
  simde__m64_private
    r_,
    a_ = simde__m64_to_private(a),
    b_ = simde__m64_to_private(b);

#if defined(SIMDE_SSE_NEON)
  r_.neon_i16 = vmin_s16(a_.neon_i16, b_.neon_i16);
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.i16) / sizeof(r_.i16[0])) ; i++) {
    r_.i16[i] = (a_.i16[i] < b_.i16[i]) ? a_.i16[i] : b_.i16[i];
  }
#endif

  return simde__m64_from_private(r_);
#endif
}
#define simde_m_pminsw(a, b) simde_mm_min_pi16(a, b)
#if defined(SIMDE_SSE_ENABLE_NATIVE_ALIASES)
#  define _mm_min_pi16(a, b) simde_mm_min_pi16(a, b)
#  define _m_pminsw(a, b) simde_mm_min_pi16(a, b)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128
simde_mm_min_ps (simde__m128 a, simde__m128 b) {
#if defined(SIMDE_SSE_NATIVE)
  return _mm_min_ps(a, b);
#else
  simde__m128_private
    r_,
    a_ = simde__m128_to_private(a),
    b_ = simde__m128_to_private(b);

#if defined(SIMDE_SSE_NEON)
  r_.neon_f32 = vminq_f32(a_.neon_f32, b_.neon_f32);
#elif defined(SIMDE_SSE_POWER_ALTIVEC)
  r_.altivec_f32 = vec_min(a_.altivec_f32, b_.altivec_f32);
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.f32) / sizeof(r_.f32[0])) ; i++) {
    r_.f32[i] = (a_.f32[i] < b_.f32[i]) ? a_.f32[i] : b_.f32[i];
  }
#endif

  return simde__m128_from_private(r_);
#endif
}
#if defined(SIMDE_SSE_ENABLE_NATIVE_ALIASES)
#  define _mm_min_ps(a, b) simde_mm_min_ps((a), (b))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_mm_min_pu8 (simde__m64 a, simde__m64 b) {
#if defined(SIMDE_SSE_NATIVE) && defined(SIMDE_ARCH_X86_MMX)
  return _mm_min_pu8(a, b);
#else
  simde__m64_private
    r_,
    a_ = simde__m64_to_private(a),
    b_ = simde__m64_to_private(b);

#if defined(SIMDE_SSE_NEON)
  r_.neon_u8 = vmin_u8(a_.neon_u8, b_.neon_u8);
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.u8) / sizeof(r_.u8[0])) ; i++) {
    r_.u8[i] = (a_.u8[i] < b_.u8[i]) ? a_.u8[i] : b_.u8[i];
  }
#endif

  return simde__m64_from_private(r_);
#endif
}
#define simde_m_pminub(a, b) simde_mm_min_pu8(a, b)
#if defined(SIMDE_SSE_ENABLE_NATIVE_ALIASES)
#  define _mm_min_pu8(a, b) simde_mm_min_pu8(a, b)
#  define _m_pminub(a, b) simde_mm_min_pu8(a, b)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128
simde_mm_min_ss (simde__m128 a, simde__m128 b) {
#if defined(SIMDE_SSE_NATIVE)
  return _mm_min_ss(a, b);
#elif defined(SIMDE_ASSUME_VECTORIZATION)
  return simde_mm_move_ss(a, simde_mm_min_ps(a, b));
#else
  simde__m128_private
    r_,
    a_ = simde__m128_to_private(a),
    b_ = simde__m128_to_private(b);

  r_.f32[0] = (a_.f32[0] < b_.f32[0]) ? a_.f32[0] : b_.f32[0];
  r_.f32[1] = a_.f32[1];
  r_.f32[2] = a_.f32[2];
  r_.f32[3] = a_.f32[3];

  return simde__m128_from_private(r_);
#endif
}
#if defined(SIMDE_SSE_ENABLE_NATIVE_ALIASES)
#  define _mm_min_ss(a, b) simde_mm_min_ss((a), (b))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128
simde_mm_movehl_ps (simde__m128 a, simde__m128 b) {
#if defined(SIMDE_SSE_NATIVE)
  return _mm_movehl_ps(a, b);
#else
  simde__m128_private
    r_,
    a_ = simde__m128_to_private(a),
    b_ = simde__m128_to_private(b);

  #if defined(SIMDE__SHUFFLE_VECTOR)
    r_.f32 = SIMDE__SHUFFLE_VECTOR(32, 16, a_.f32, b_.f32, 6, 7, 2, 3);
  #else
    r_.f32[0] = b_.f32[2];
    r_.f32[1] = b_.f32[3];
    r_.f32[2] = a_.f32[2];
    r_.f32[3] = a_.f32[3];
  #endif

  return simde__m128_from_private(r_);
#endif
}
#if defined(SIMDE_SSE_ENABLE_NATIVE_ALIASES)
#  define _mm_movehl_ps(a, b) simde_mm_movehl_ps((a), (b))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128
simde_mm_movelh_ps (simde__m128 a, simde__m128 b) {
#if defined(SIMDE_SSE_NATIVE)
  return _mm_movelh_ps(a, b);
#else
  simde__m128_private
    r_,
    a_ = simde__m128_to_private(a),
    b_ = simde__m128_to_private(b);

  #if defined(SIMDE__SHUFFLE_VECTOR)
    r_.f32 = SIMDE__SHUFFLE_VECTOR(32, 16, a_.f32, b_.f32, 0, 1, 4, 5);
  #else
    r_.f32[0] = a_.f32[0];
    r_.f32[1] = a_.f32[1];
    r_.f32[2] = b_.f32[0];
    r_.f32[3] = b_.f32[1];
  #endif

  return simde__m128_from_private(r_);
#endif
}
#if defined(SIMDE_SSE_ENABLE_NATIVE_ALIASES)
#  define _mm_movelh_ps(a, b) simde_mm_movelh_ps((a), (b))
#endif

SIMDE__FUNCTION_ATTRIBUTES
int
simde_mm_movemask_pi8 (simde__m64 a) {
#if defined(SIMDE_SSE_NATIVE) && defined(SIMDE_ARCH_X86_MMX)
  return _mm_movemask_pi8(a);
#else
  simde__m64_private a_ = simde__m64_to_private(a);
  int r = 0;
  const size_t nmemb = sizeof(a_.i8) / sizeof(a_.i8[0]);

  SIMDE__VECTORIZE_REDUCTION(|:r)
  for (size_t i = 0 ; i < nmemb ; i++) {
    r |= (a_.u8[nmemb - 1 - i] >> 7) << (nmemb - 1 - i);
  }

  return r;
#endif
}
#define simde_m_pmovmskb(a, b) simde_mm_movemask_pi8(a, b)
#if defined(SIMDE_SSE_ENABLE_NATIVE_ALIASES)
#  define _mm_movemask_pi8(a) simde_mm_movemask_pi8(a)
#endif

SIMDE__FUNCTION_ATTRIBUTES
int
simde_mm_movemask_ps (simde__m128 a) {
#if defined(SIMDE_SSE_NATIVE) && defined(SIMDE_ARCH_X86_MMX)
  return _mm_movemask_ps(a);
#else
  int r = 0;
  simde__m128_private a_ = simde__m128_to_private(a);

#if defined(SIMDE_SSE_NEON)
  /* TODO: check to see if NEON version is faster than the portable version */
  static const uint32x4_t movemask = { 1, 2, 4, 8 };
  static const uint32x4_t highbit = { 0x80000000, 0x80000000, 0x80000000, 0x80000000 };
  uint32x4_t t0 = a_.neon_u32;
  uint32x4_t t1 = vtstq_u32(t0, highbit);
  uint32x4_t t2 = vandq_u32(t1, movemask);
  uint32x2_t t3 = vorr_u32(vget_low_u32(t2), vget_high_u32(t2));
  r = vget_lane_u32(t3, 0) | vget_lane_u32(t3, 1);
#else
  SIMDE__VECTORIZE_REDUCTION(|:r)
  for (size_t i = 0 ; i < sizeof(a_.u32) / sizeof(a_.u32[0]) ; i++) {
    r |= (a_.u32[i] >> ((sizeof(a_.u32[i]) * CHAR_BIT) - 1)) << i;
  }
#endif

  return r;
#endif
}
#if defined(SIMDE_SSE_ENABLE_NATIVE_ALIASES)
#  define _mm_movemask_ps(a) simde_mm_movemask_ps((a))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128
simde_mm_mul_ps (simde__m128 a, simde__m128 b) {
#if defined(SIMDE_SSE_NATIVE)
  return _mm_mul_ps(a, b);
#else
  simde__m128_private
    r_,
    a_ = simde__m128_to_private(a),
    b_ = simde__m128_to_private(b);

#if defined(SIMDE_SSE_NEON)
  r_.neon_f32 = vmulq_f32(a_.neon_f32, b_.neon_f32);
#elif defined(SIMDE_SSE_WASM_SIMD128)
  r_.wasm_v128 = wasm_f32x4_mul(a_.wasm_v128, b_.wasm_v128);
#elif defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
  r_.f32 = a_.f32 * b_.f32;
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.f32) / sizeof(r_.f32[0])) ; i++) {
    r_.f32[i] = a_.f32[i] * b_.f32[i];
  }
#endif

  return simde__m128_from_private(r_);
#endif
}
#if defined(SIMDE_SSE_ENABLE_NATIVE_ALIASES)
#  define _mm_mul_ps(a, b) simde_mm_mul_ps((a), (b))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128
simde_mm_mul_ss (simde__m128 a, simde__m128 b) {
#if defined(SIMDE_SSE_NATIVE)
  return _mm_mul_ss(a, b);
#elif defined(SIMDE_ASSUME_VECTORIZATION)
  return simde_mm_move_ss(a, simde_mm_mul_ps(a, b));
#else
  simde__m128_private
    r_,
    a_ = simde__m128_to_private(a),
    b_ = simde__m128_to_private(b);

  r_.f32[0] = a_.f32[0] * b_.f32[0];
  r_.f32[1] = a_.f32[1];
  r_.f32[2] = a_.f32[2];
  r_.f32[3] = a_.f32[3];

  return simde__m128_from_private(r_);
#endif
}
#if defined(SIMDE_SSE_ENABLE_NATIVE_ALIASES)
#  define _mm_mul_ss(a, b) simde_mm_mul_ss((a), (b))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_mm_mulhi_pu16 (simde__m64 a, simde__m64 b) {
#if defined(SIMDE_SSE_NATIVE) && defined(SIMDE_ARCH_X86_MMX)
  return _mm_mulhi_pu16(a, b);
#else
  simde__m64_private
    r_,
    a_ = simde__m64_to_private(a),
    b_ = simde__m64_to_private(b);

  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.u16) / sizeof(r_.u16[0])) ; i++) {
    r_.u16[i] = HEDLEY_STATIC_CAST(uint16_t, ((HEDLEY_STATIC_CAST(uint32_t, a_.u16[i]) * HEDLEY_STATIC_CAST(uint32_t, b_.u16[i])) >> UINT32_C(16)));
  }

  return simde__m64_from_private(r_);
#endif
}
#define simde_m_pmulhuw(a, b) simde_mm_mulhi_pu16(a, b)
#if defined(SIMDE_SSE_ENABLE_NATIVE_ALIASES)
#  define _mm_mulhi_pu16(a, b) simde_mm_mulhi_pu16(a, b)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128
simde_mm_or_ps (simde__m128 a, simde__m128 b) {
#if defined(SIMDE_SSE_NATIVE)
  return _mm_or_ps(a, b);
#else
  simde__m128_private
    r_,
    a_ = simde__m128_to_private(a),
    b_ = simde__m128_to_private(b);

#if defined(SIMDE_SSE_NEON)
  r_.neon_i32 = vorrq_s32(a_.neon_i32, b_.neon_i32);
#elif defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
  r_.i32f = a_.i32f | b_.i32f;
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.u32) / sizeof(r_.u32[0])) ; i++) {
    r_.u32[i] = a_.u32[i] | b_.u32[i];
  }
#endif

  return simde__m128_from_private(r_);
#endif
}
#if defined(SIMDE_SSE_ENABLE_NATIVE_ALIASES)
#  define _mm_or_ps(a, b) simde_mm_or_ps((a), (b))
#endif

SIMDE__FUNCTION_ATTRIBUTES
void
simde_mm_prefetch (char const* p, int i) {
  (void) p;
  (void) i;
}
#if defined(SIMDE_SSE_NATIVE)
#  define simde_mm_prefetch(p, i) _mm_prefetch(p, i)
#endif
#if defined(SIMDE_SSE_ENABLE_NATIVE_ALIASES)
#  define _mm_prefetch(p, i) simde_mm_prefetch(p, i)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128
simde_mm_rcp_ps (simde__m128 a) {
#if defined(SIMDE_SSE_NATIVE)
  return _mm_rcp_ps(a);
#else
  simde__m128_private
    r_,
    a_ = simde__m128_to_private(a);

#if defined(SIMDE_SSE_NEON)
  float32x4_t recip = vrecpeq_f32(a_.neon_f32);

#  if !defined(SIMDE_MM_RCP_PS_ITERS)
#    define SIMDE_MM_RCP_PS_ITERS SIMDE_ACCURACY_ITERS
#  endif

  for (int i = 0; i < SIMDE_MM_RCP_PS_ITERS ; ++i) {
    recip = vmulq_f32(recip, vrecpsq_f32(recip, a_.neon_f32));
  }

  r_.neon_f32 = recip;
#elif defined(SIMDE_VECTOR_SUBSCRIPT_SCALAR)
  r_.f32 = 1.0f / a_.f32;
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.f32) / sizeof(r_.f32[0])) ; i++) {
    r_.f32[i] = 1.0f / a_.f32[i];
  }
#endif

  return simde__m128_from_private(r_);
#endif
}
#if defined(SIMDE_SSE_ENABLE_NATIVE_ALIASES)
#  define _mm_rcp_ps(a) simde_mm_rcp_ps((a))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128
simde_mm_rcp_ss (simde__m128 a) {
#if defined(SIMDE_SSE_NATIVE)
  return _mm_rcp_ss(a);
#elif defined(SIMDE_ASSUME_VECTORIZATION)
  return simde_mm_move_ss(a, simde_mm_rcp_ps(a));
#else
  simde__m128_private
    r_,
    a_ = simde__m128_to_private(a);

  r_.f32[0] = 1.0f / a_.f32[0];
  r_.f32[1] = a_.f32[1];
  r_.f32[2] = a_.f32[2];
  r_.f32[3] = a_.f32[3];

  return simde__m128_from_private(r_);
#endif
}
#if defined(SIMDE_SSE_ENABLE_NATIVE_ALIASES)
#  define _mm_rcp_ss(a) simde_mm_rcp_ss((a))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128
simde_mm_rsqrt_ps (simde__m128 a) {
#if defined(SIMDE_SSE_NATIVE)
  return _mm_rsqrt_ps(a);
#else
  simde__m128_private
    r_,
    a_ = simde__m128_to_private(a);

#if defined(SIMDE_SSE_NEON)
  r_.neon_f32 = vrsqrteq_f32(a_.neon_f32);
#elif defined(__STDC_IEC_559__)
  /* http://h14s.p5r.org/2012/09/0x5f3759df.html?mwh=1 */
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.f32) / sizeof(r_.f32[0])) ; i++) {
    r_.i32[i]  = INT32_C(0x5f3759df) - (a_.i32[i] >> 1);

#if SIMDE_ACCURACY_ITERS > 2
    const float half = SIMDE_FLOAT32_C(0.5) * a_.f32[i];
    for (int ai = 2 ; ai < SIMDE_ACCURACY_ITERS ; ai++)
      r_.f32[i] *= SIMDE_FLOAT32_C(1.5) - (half * r_.f32[i] * r_.f32[i]);
#endif
  }
#elif defined(SIMDE_HAVE_MATH_H)
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.f32) / sizeof(r_.f32[0])) ; i++) {
    r_.f32[i] = 1.0f / sqrtf(a_.f32[i]);
  }
#else
  HEDLEY_UNREACHABLE();
#endif

  return simde__m128_from_private(r_);
#endif
}
#if defined(SIMDE_SSE_ENABLE_NATIVE_ALIASES)
#  define _mm_rsqrt_ps(a) simde_mm_rsqrt_ps((a))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128
simde_mm_rsqrt_ss (simde__m128 a) {
#if defined(SIMDE_SSE_NATIVE)
  return _mm_rsqrt_ss(a);
#elif defined(SIMDE_ASSUME_VECTORIZATION)
  return simde_mm_move_ss(a, simde_mm_rsqrt_ps(a));
#else
  simde__m128_private
    r_,
    a_ = simde__m128_to_private(a);

#if defined(__STDC_IEC_559__)
  {
    r_.i32[0]  = INT32_C(0x5f3759df) - (a_.i32[0] >> 1);

#if SIMDE_ACCURACY_ITERS > 2
    float half = SIMDE_FLOAT32_C(0.5) * a_.f32[0];
    for (int ai = 2 ; ai < SIMDE_ACCURACY_ITERS ; ai++)
      r_.f32[0] *= SIMDE_FLOAT32_C(1.5) - (half * r_.f32[0] * r_.f32[0]);
#endif
  }
  r_.f32[0] = 1.0f / sqrtf(a_.f32[0]);
  r_.f32[1] = a_.f32[1];
  r_.f32[2] = a_.f32[2];
  r_.f32[3] = a_.f32[3];
#elif defined(SIMDE_HAVE_MATH_H)
  r_.f32[0] = 1.0f / sqrtf(a_.f32[0]);
  r_.f32[1] = a_.f32[1];
  r_.f32[2] = a_.f32[2];
  r_.f32[3] = a_.f32[3];
#else
  HEDLEY_UNREACHABLE();
#endif

  return simde__m128_from_private(r_);
#endif
}
#if defined(SIMDE_SSE_ENABLE_NATIVE_ALIASES)
#  define _mm_rsqrt_ss(a) simde_mm_rsqrt_ss((a))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_mm_sad_pu8 (simde__m64 a, simde__m64 b) {
#if defined(SIMDE_SSE_NATIVE) && defined(SIMDE_ARCH_X86_MMX)
  return _mm_sad_pu8(a, b);
#else
  simde__m64_private
    r_,
    a_ = simde__m64_to_private(a),
    b_ = simde__m64_to_private(b);
  uint16_t sum = 0;

#if defined(SIMDE_HAVE_STDLIB_H)
  SIMDE__VECTORIZE_REDUCTION(+:sum)
  for (size_t i = 0 ; i < (sizeof(r_.u8) / sizeof(r_.u8[0])) ; i++) {
    sum += (uint8_t) abs(a_.u8[i] - b_.u8[i]);
  }

  r_.i16[0] = (int16_t) sum;
  r_.i16[1] = 0;
  r_.i16[2] = 0;
  r_.i16[3] = 0;
#else
  HEDLEY_UNREACHABLE();
#endif

  return simde__m64_from_private(r_);
#endif
}
#define simde_m_psadbw(a, b) simde_mm_sad_pu8(a, b)
#if defined(SIMDE_SSE_ENABLE_NATIVE_ALIASES)
#  define _mm_sad_pu8(a, b) simde_mm_sad_pu8(a, b)
#  define _m_psadbw(a, b) simde_mm_sad_pu8(a, b)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128
simde_mm_set_ss (simde_float32 a) {
#if defined(SIMDE_SSE_NATIVE)
  return _mm_set_ss(a);
#elif defined(SIMDE_SSE_NEON)
  return vsetq_lane_f32(a, vdupq_n_f32(SIMDE_FLOAT32_C(0.0)), 0);
#else
  return simde_mm_set_ps(SIMDE_FLOAT32_C(0.0), SIMDE_FLOAT32_C(0.0), SIMDE_FLOAT32_C(0.0), a);
#endif
}
#if defined(SIMDE_SSE_ENABLE_NATIVE_ALIASES)
#  define _mm_set_ss(a) simde_mm_set_ss(a)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128
simde_mm_setr_ps (simde_float32 e3, simde_float32 e2, simde_float32 e1, simde_float32 e0) {
#if defined(SIMDE_SSE_NATIVE)
  return _mm_setr_ps(e3, e2, e1, e0);
#elif defined(SIMDE_SSE_NEON)
  SIMDE_ALIGN(16) simde_float32 data[4] = { e3, e2, e1, e0 };
  return vld1q_f32(data);
#else
  return simde_mm_set_ps(e0, e1, e2, e3);
#endif
}
#if defined(SIMDE_SSE_ENABLE_NATIVE_ALIASES)
#  define _mm_setr_ps(e3, e2, e1, e0) simde_mm_setr_ps(e3, e2, e1, e0)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128
simde_mm_setzero_ps (void) {
#if defined(SIMDE_SSE_NATIVE)
  return _mm_setzero_ps();
#elif defined(SIMDE_SSE_NEON)
  return vdupq_n_f32(SIMDE_FLOAT32_C(0.0));
#else
  simde__m128 r;
  simde_memset(&r, 0, sizeof(r));
  return r;
#endif
}
#if defined(SIMDE_SSE_ENABLE_NATIVE_ALIASES)
#  define _mm_setzero_ps() simde_mm_setzero_ps()
#endif

#if defined(SIMDE_DIAGNOSTIC_DISABLE_UNINITIALIZED_)
HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DIAGNOSTIC_DISABLE_UNINITIALIZED_
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128
simde_mm_undefined_ps (void) {
  simde__m128_private r_;

#if defined(SIMDE__HAVE_UNDEFINED128)
  r_.n = _mm_undefined_ps();
#elif !defined(SIMDE_DIAGNOSTIC_DISABLE_UNINITIALIZED_)
  r_ = simde__m128_to_private(simde_mm_setzero_ps());
#endif

 return simde__m128_from_private(r_);
}
#if defined(SIMDE_SSE_ENABLE_NATIVE_ALIASES)
#  define _mm_undefined_ps() simde_mm_undefined_ps()
#endif

#if defined(SIMDE_DIAGNOSTIC_DISABLE_UNINITIALIZED_)
HEDLEY_DIAGNOSTIC_POP
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128
simde_mm_setone_ps (void) {
  simde__m128 t = simde_mm_setzero_ps();
  return simde_mm_cmpeq_ps(t, t);
}

SIMDE__FUNCTION_ATTRIBUTES
void
simde_mm_sfence (void) {
  /* TODO: Use Hedley. */
#if defined(SIMDE_SSE_NATIVE)
  _mm_sfence();
#elif defined(__GNUC__) && ((__GNUC__ > 4) || (__GNUC__ == 4 && __GNUC_MINOR__ >= 7))
  __atomic_thread_fence(__ATOMIC_SEQ_CST);
#elif !defined(__INTEL_COMPILER) && defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 201112L) && !defined(__STDC_NO_ATOMICS__)
#  if defined(__GNUC__) && (__GNUC__ == 4) && (__GNUC_MINOR__ < 9)
  __atomic_thread_fence(__ATOMIC_SEQ_CST);
#  else
  atomic_thread_fence(memory_order_seq_cst);
#  endif
#elif defined(_MSC_VER)
  MemoryBarrier();
#elif HEDLEY_HAS_EXTENSION(c_atomic)
  __c11_atomic_thread_fence(__ATOMIC_SEQ_CST);
#elif defined(__GNUC__) && ((__GNUC__ > 4) || (__GNUC__ == 4 && __GNUC_MINOR__ >= 1))
  __sync_synchronize();
#elif defined(_OPENMP)
#  pragma omp critical(simde_mm_sfence_)
  { }
#endif
}
#if defined(SIMDE_SSE_ENABLE_NATIVE_ALIASES)
#  define _mm_sfence() simde_mm_sfence()
#endif

#define SIMDE_MM_SHUFFLE(z, y, x, w) (((z) << 6) | ((y) << 4) | ((x) << 2) | (w))
#if defined(SIMDE_SSE_ENABLE_NATIVE_ALIASES)
#  define _MM_SHUFFLE(z, y, x, w) SIMDE_MM_SHUFFLE(z, y, x, w)
#endif

#if defined(SIMDE_SSE_NATIVE) && defined(SIMDE_ARCH_X86_MMX) && !defined(__PGI)
#  define simde_mm_shuffle_pi16(a, imm8) _mm_shuffle_pi16(a, imm8)
#elif defined(SIMDE__SHUFFLE_VECTOR)
#  define simde_mm_shuffle_pi16(a, imm8) (__extension__ ({ \
      const simde__m64_private simde__tmp_a_ = simde__m64_to_private(a); \
      simde__m64_from_private((simde__m64_private) { .i16 = \
        SIMDE__SHUFFLE_VECTOR(16, 8, \
          (simde__tmp_a_).i16, \
          (simde__tmp_a_).i16, \
          (((imm8)     ) & 3), \
          (((imm8) >> 2) & 3), \
          (((imm8) >> 4) & 3), \
          (((imm8) >> 6) & 3)) }); }))
#else
SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_mm_shuffle_pi16 (simde__m64 a, const int imm8)
    HEDLEY_REQUIRE_MSG((imm8 & 0xff) == imm8, "imm8 must be in range [0, 255]") {
  simde__m64_private r_;
  simde__m64_private a_ = simde__m64_to_private(a);

  for (size_t i = 0 ; i < sizeof(r_.i16) / sizeof(r_.i16[0]) ; i++) {
    r_.i16[i] = a_.i16[(imm8 >> (i * 2)) & 3];
  }

HEDLEY_DIAGNOSTIC_PUSH
#if HEDLEY_HAS_WARNING("-Wconditional-uninitialized")
#  pragma clang diagnostic ignored "-Wconditional-uninitialized"
#endif
  return simde__m64_from_private(r_);
HEDLEY_DIAGNOSTIC_POP
}
#endif
#if defined(SIMDE_SSE_NATIVE) && !defined(__PGI)
#  define simde_m_pshufw(a, imm8) _m_pshufw(a, imm8)
#else
#  define simde_m_pshufw(a, imm8) simde_mm_shuffle_pi16(a, imm8)
#endif
#if defined(SIMDE_SSE_ENABLE_NATIVE_ALIASES)
#  define _mm_shuffle_pi16(a, imm8) simde_mm_shuffle_pi16(a, imm8)
#  define _m_pshufw(a, imm8) simde_mm_shuffle_pi16(a, imm8)
#endif

#if defined(SIMDE_SSE_NATIVE) && !defined(__PGI)
#  define simde_mm_shuffle_ps(a, b, imm8) _mm_shuffle_ps(a, b, imm8)
#elif defined(SIMDE__SHUFFLE_VECTOR)
#  define simde_mm_shuffle_ps(a, b, imm8) (__extension__ ({ \
      simde__m128_from_private((simde__m128_private) { .f32 = \
        SIMDE__SHUFFLE_VECTOR(32, 16, \
          simde__m128_to_private(a).f32, \
          simde__m128_to_private(b).f32, \
          (((imm8)     ) & 3), \
          (((imm8) >> 2) & 3), \
          (((imm8) >> 4) & 3) + 4, \
          (((imm8) >> 6) & 3) + 4) }); }))
#else
SIMDE__FUNCTION_ATTRIBUTES
simde__m128
simde_mm_shuffle_ps (simde__m128 a, simde__m128 b, const int imm8)
    HEDLEY_REQUIRE_MSG((imm8 & 0xff) == imm8, "imm8 must be in range [0, 255]") {
  simde__m128_private
    r_,
    a_ = simde__m128_to_private(a),
    b_ = simde__m128_to_private(b);

  r_.f32[0] = a_.f32[(imm8 >> 0) & 3];
  r_.f32[1] = a_.f32[(imm8 >> 2) & 3];
  r_.f32[2] = b_.f32[(imm8 >> 4) & 3];
  r_.f32[3] = b_.f32[(imm8 >> 6) & 3];

  return simde__m128_from_private(r_);
}
#endif
#if defined(SIMDE_SSE_ENABLE_NATIVE_ALIASES)
#  define _mm_shuffle_ps(a, b, imm8) simde_mm_shuffle_ps((a), (b), imm8)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128
simde_mm_sqrt_ps (simde__m128 a) {
#if defined(SIMDE_SSE_NATIVE)
  return _mm_sqrt_ps(a);
#else
  simde__m128_private
    r_,
    a_ = simde__m128_to_private(a);

#if defined(SIMDE_SSE_NEON)
  float32x4_t recipsq = vrsqrteq_f32(a_.neon_f32);
  float32x4_t sq = vrecpeq_f32(recipsq);
  /* ??? use step versions of both sqrt and recip for better accuracy? */
  r_.neon_f32 = sq;
#elif defined(SIMDE_HAVE_MATH_H)
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < sizeof(r_.f32) / sizeof(r_.f32[0]) ; i++) {
    r_.f32[i] = sqrtf(a_.f32[i]);
  }
#else
  HEDLEY_UNREACHABLE();
#endif

  return simde__m128_from_private(r_);
#endif
}
#if defined(SIMDE_SSE_ENABLE_NATIVE_ALIASES)
#  define _mm_sqrt_ps(a) simde_mm_sqrt_ps((a))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128
simde_mm_sqrt_ss (simde__m128 a) {
#if defined(SIMDE_SSE_NATIVE)
  return _mm_sqrt_ss(a);
#elif defined(SIMDE_ASSUME_VECTORIZATION)
  return simde_mm_move_ss(a, simde_mm_sqrt_ps(a));
#else
  simde__m128_private
    r_,
    a_ = simde__m128_to_private(a);

#if defined(SIMDE_HAVE_MATH_H)
  r_.f32[0] = sqrtf(a_.f32[0]);
  r_.f32[1] = a_.f32[1];
  r_.f32[2] = a_.f32[2];
  r_.f32[3] = a_.f32[3];
#else
  HEDLEY_UNREACHABLE();
#endif

  return simde__m128_from_private(r_);
#endif
}
#if defined(SIMDE_SSE_ENABLE_NATIVE_ALIASES)
#  define _mm_sqrt_ss(a) simde_mm_sqrt_ss((a))
#endif

SIMDE__FUNCTION_ATTRIBUTES
void
simde_mm_store_ps (simde_float32 mem_addr[4], simde__m128 a) {
  simde_assert_aligned(16, mem_addr);

#if defined(SIMDE_SSE_NATIVE)
  _mm_store_ps(mem_addr, a);
#else
  simde__m128_private a_ = simde__m128_to_private(a);

  #if defined(SIMDE_SSE_NEON)
    vst1q_f32(mem_addr, a_.neon_f32);
  #elif defined(SIMDE_SSE_WASM_SIMD128)
    wasm_v128_store(mem_addr, a_.wasm_v128);
  #else
    SIMDE__VECTORIZE_ALIGNED(mem_addr:16)
    for (size_t i = 0 ; i < sizeof(a_.f32) / sizeof(a_.f32[0]) ; i++) {
      mem_addr[i] = a_.f32[i];
    }
#endif
#endif
}
#if defined(SIMDE_SSE_ENABLE_NATIVE_ALIASES)
#  define _mm_store_ps(mem_addr, a) simde_mm_store_ps(HEDLEY_REINTERPRET_CAST(float*, mem_addr), (a))
#endif

SIMDE__FUNCTION_ATTRIBUTES
void
simde_mm_store_ps1 (simde_float32 mem_addr[4], simde__m128 a) {
  simde_assert_aligned(16, mem_addr);

#if defined(SIMDE_SSE_NATIVE)
  _mm_store_ps1(mem_addr, a);
#else
  simde__m128_private a_ = simde__m128_to_private(a);

  SIMDE__VECTORIZE_ALIGNED(mem_addr:16)
  for (size_t i = 0 ; i < sizeof(a_.f32) / sizeof(a_.f32[0]) ; i++) {
    mem_addr[i] = a_.f32[0];
  }
#endif
}
#if defined(SIMDE_SSE_ENABLE_NATIVE_ALIASES)
#  define _mm_store_ps1(mem_addr, a) simde_mm_store_ps1(HEDLEY_REINTERPRET_CAST(float*, mem_addr), (a))
#endif

SIMDE__FUNCTION_ATTRIBUTES
void
simde_mm_store_ss (simde_float32* mem_addr, simde__m128 a) {
#if defined(SIMDE_SSE_NATIVE)
  _mm_store_ss(mem_addr, a);
#else
  simde__m128_private a_ = simde__m128_to_private(a);

  #if defined(SIMDE_SSE_NEON)
    vst1q_lane_f32(mem_addr, a_.neon_f32, 0);
  #else
    *mem_addr = a_.f32[0];
  #endif
#endif
}
#if defined(SIMDE_SSE_ENABLE_NATIVE_ALIASES)
#  define _mm_store_ss(mem_addr, a) simde_mm_store_ss(HEDLEY_REINTERPRET_CAST(float*, mem_addr), (a))
#endif

SIMDE__FUNCTION_ATTRIBUTES
void
simde_mm_store1_ps (simde_float32 mem_addr[4], simde__m128 a) {
  simde_assert_aligned(16, mem_addr);

#if defined(SIMDE_SSE_NATIVE)
  _mm_store1_ps(mem_addr, a);
#else
  simde_mm_store_ps1(mem_addr, a);
#endif
}
#if defined(SIMDE_SSE_ENABLE_NATIVE_ALIASES)
#  define _mm_store1_ps(mem_addr, a) simde_mm_store1_ps(HEDLEY_REINTERPRET_CAST(float*, mem_addr), (a))
#endif

SIMDE__FUNCTION_ATTRIBUTES
void
simde_mm_storeh_pi (simde__m64* mem_addr, simde__m128 a) {
#if defined(SIMDE_SSE_NATIVE)
  _mm_storeh_pi(HEDLEY_REINTERPRET_CAST(__m64*, mem_addr), a);
#else
  simde__m64_private* dest_ = HEDLEY_REINTERPRET_CAST(simde__m64_private*, mem_addr);
  simde__m128_private a_ = simde__m128_to_private(a);

  dest_->f32[0] = a_.f32[2];
  dest_->f32[1] = a_.f32[3];
#endif
}
#if defined(SIMDE_SSE_ENABLE_NATIVE_ALIASES)
#  define _mm_storeh_pi(mem_addr, a) simde_mm_storeh_pi(mem_addr, (a))
#endif

SIMDE__FUNCTION_ATTRIBUTES
void
simde_mm_storel_pi (simde__m64* mem_addr, simde__m128 a) {
#if defined(SIMDE_SSE_NATIVE)
  _mm_storel_pi(HEDLEY_REINTERPRET_CAST(__m64*, mem_addr), a);
#else
  simde__m64_private* dest_ = HEDLEY_REINTERPRET_CAST(simde__m64_private*, mem_addr);
  simde__m128_private a_ = simde__m128_to_private(a);

  dest_->f32[0] = a_.f32[0];
  dest_->f32[1] = a_.f32[1];
#endif
}
#if defined(SIMDE_SSE_ENABLE_NATIVE_ALIASES)
#  define _mm_storel_pi(mem_addr, a) simde_mm_storel_pi(mem_addr, (a))
#endif

SIMDE__FUNCTION_ATTRIBUTES
void
simde_mm_storer_ps (simde_float32 mem_addr[4], simde__m128 a) {
  simde_assert_aligned(16, mem_addr);

#if defined(SIMDE_SSE_NATIVE)
  _mm_storer_ps(mem_addr, a);
#else
  simde__m128_private a_ = simde__m128_to_private(a);

  #if defined(SIMDE__SHUFFLE_VECTOR)
    a_.f32 = SIMDE__SHUFFLE_VECTOR(32, 16, a_.f32, a_.f32, 3, 2, 1, 0);
    simde_mm_store_ps(mem_addr, simde__m128_from_private(a_));
  #else
    SIMDE__VECTORIZE_ALIGNED(mem_addr:16)
    for (size_t i = 0 ; i < sizeof(a_.f32) / sizeof(a_.f32[0]) ; i++) {
      mem_addr[i] = a_.f32[((sizeof(a_.f32) / sizeof(a_.f32[0])) - 1) - i];
    }
  #endif
#endif
}
#if defined(SIMDE_SSE_ENABLE_NATIVE_ALIASES)
#  define _mm_storer_ps(mem_addr, a) simde_mm_storer_ps(HEDLEY_REINTERPRET_CAST(float*, mem_addr), (a))
#endif

SIMDE__FUNCTION_ATTRIBUTES
void
simde_mm_storeu_ps (simde_float32 mem_addr[4], simde__m128 a) {
#if defined(SIMDE_SSE_NATIVE)
  _mm_storeu_ps(mem_addr, a);
#else
  simde__m128_private a_ = simde__m128_to_private(a);

#if defined(SIMDE_SSE_NEON)
  vst1q_f32(mem_addr, a_.neon_f32);
#else
  simde_memcpy(mem_addr, &a_, sizeof(a_));
#endif
#endif
}
#if defined(SIMDE_SSE_ENABLE_NATIVE_ALIASES)
#  define _mm_storeu_ps(mem_addr, a) simde_mm_storeu_ps(HEDLEY_REINTERPRET_CAST(float*, mem_addr), (a))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128
simde_mm_sub_ps (simde__m128 a, simde__m128 b) {
#if defined(SIMDE_SSE_NATIVE)
  return _mm_sub_ps(a, b);
#else
  simde__m128_private
    r_,
    a_ = simde__m128_to_private(a),
    b_ = simde__m128_to_private(b);

#if defined(SIMDE_SSE_NEON)
  r_.neon_f32 = vsubq_f32(a_.neon_f32, b_.neon_f32);
#elif defined(SIMDE_SSE_WASM_SIMD128)
  r_.wasm_v128 = wasm_f32x4_sub(a_.wasm_v128, b_.wasm_v128);
#elif defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
  r_.f32 = a_.f32 - b_.f32;
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.f32) / sizeof(r_.f32[0])) ; i++) {
    r_.f32[i] = a_.f32[i] - b_.f32[i];
  }
#endif

  return simde__m128_from_private(r_);
#endif
}
#if defined(SIMDE_SSE_ENABLE_NATIVE_ALIASES)
#  define _mm_sub_ps(a, b) simde_mm_sub_ps((a), (b))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128
simde_mm_sub_ss (simde__m128 a, simde__m128 b) {
#if defined(SIMDE_SSE_NATIVE)
  return _mm_sub_ss(a, b);
#elif defined(SIMDE_ASSUME_VECTORIZATION)
  return simde_mm_move_ss(a, simde_mm_sub_ps(a, b));
#else
  simde__m128_private
    r_,
    a_ = simde__m128_to_private(a),
    b_ = simde__m128_to_private(b);

  r_.f32[0] = a_.f32[0] - b_.f32[0];
  r_.f32[1] = a_.f32[1];
  r_.f32[2] = a_.f32[2];
  r_.f32[3] = a_.f32[3];

  return simde__m128_from_private(r_);
#endif
}
#if defined(SIMDE_SSE_ENABLE_NATIVE_ALIASES)
#  define _mm_sub_ss(a, b) simde_mm_sub_ss((a), (b))
#endif

SIMDE__FUNCTION_ATTRIBUTES
int
simde_mm_ucomieq_ss (simde__m128 a, simde__m128 b) {
#if defined(SIMDE_SSE_NATIVE)
  return _mm_ucomieq_ss(a, b);
#else
  simde__m128_private
    a_ = simde__m128_to_private(a),
    b_ = simde__m128_to_private(b);
  int r;

#if defined(SIMDE_HAVE_FENV_H)
  fenv_t envp;
  int x = feholdexcept(&envp);
  r = a_.f32[0] == b_.f32[0];
  if (HEDLEY_LIKELY(x == 0))
    fesetenv(&envp);
#else
  HEDLEY_UNREACHABLE();
#endif

  return r;
#endif
}
#if defined(SIMDE_SSE_ENABLE_NATIVE_ALIASES)
#  define _mm_ucomieq_ss(a, b) simde_mm_ucomieq_ss((a), (b))
#endif

SIMDE__FUNCTION_ATTRIBUTES
int
simde_mm_ucomige_ss (simde__m128 a, simde__m128 b) {
#if defined(SIMDE_SSE_NATIVE)
  return _mm_ucomige_ss(a, b);
#else
  simde__m128_private
    a_ = simde__m128_to_private(a),
    b_ = simde__m128_to_private(b);
  int r;

#if defined(SIMDE_HAVE_FENV_H)
  fenv_t envp;
  int x = feholdexcept(&envp);
  r = a_.f32[0] >= b_.f32[0];
  if (HEDLEY_LIKELY(x == 0))
    fesetenv(&envp);
#else
  HEDLEY_UNREACHABLE();
#endif

  return r;
#endif
}
#if defined(SIMDE_SSE_ENABLE_NATIVE_ALIASES)
#  define _mm_ucomige_ss(a, b) simde_mm_ucomige_ss((a), (b))
#endif

SIMDE__FUNCTION_ATTRIBUTES
int
simde_mm_ucomigt_ss (simde__m128 a, simde__m128 b) {
#if defined(SIMDE_SSE_NATIVE)
  return _mm_ucomigt_ss(a, b);
#else
  simde__m128_private
    a_ = simde__m128_to_private(a),
    b_ = simde__m128_to_private(b);
  int r;

#if defined(SIMDE_HAVE_FENV_H)
  fenv_t envp;
  int x = feholdexcept(&envp);
  r = a_.f32[0] > b_.f32[0];
  if (HEDLEY_LIKELY(x == 0))
    fesetenv(&envp);
#else
  HEDLEY_UNREACHABLE();
#endif

  return r;
#endif
}
#if defined(SIMDE_SSE_ENABLE_NATIVE_ALIASES)
#  define _mm_ucomigt_ss(a, b) simde_mm_ucomigt_ss((a), (b))
#endif

SIMDE__FUNCTION_ATTRIBUTES
int
simde_mm_ucomile_ss (simde__m128 a, simde__m128 b) {
#if defined(SIMDE_SSE_NATIVE)
  return _mm_ucomile_ss(a, b);
#else
  simde__m128_private
    a_ = simde__m128_to_private(a),
    b_ = simde__m128_to_private(b);
  int r;

#if defined(SIMDE_HAVE_FENV_H)
  fenv_t envp;
  int x = feholdexcept(&envp);
  r = a_.f32[0] <= b_.f32[0];
  if (HEDLEY_LIKELY(x == 0))
    fesetenv(&envp);
#else
  HEDLEY_UNREACHABLE();
#endif

  return r;
#endif
}
#if defined(SIMDE_SSE_ENABLE_NATIVE_ALIASES)
#  define _mm_ucomile_ss(a, b) simde_mm_ucomile_ss((a), (b))
#endif

SIMDE__FUNCTION_ATTRIBUTES
int
simde_mm_ucomilt_ss (simde__m128 a, simde__m128 b) {
#if defined(SIMDE_SSE_NATIVE)
  return _mm_ucomilt_ss(a, b);
#else
  simde__m128_private
    a_ = simde__m128_to_private(a),
    b_ = simde__m128_to_private(b);
  int r;

#if defined(SIMDE_HAVE_FENV_H)
  fenv_t envp;
  int x = feholdexcept(&envp);
  r = a_.f32[0] < b_.f32[0];
  if (HEDLEY_LIKELY(x == 0))
    fesetenv(&envp);
#else
  HEDLEY_UNREACHABLE();
#endif

  return r;
#endif
}
#if defined(SIMDE_SSE_ENABLE_NATIVE_ALIASES)
#  define _mm_ucomilt_ss(a, b) simde_mm_ucomilt_ss((a), (b))
#endif

SIMDE__FUNCTION_ATTRIBUTES
int
simde_mm_ucomineq_ss (simde__m128 a, simde__m128 b) {
#if defined(SIMDE_SSE_NATIVE)
  return _mm_ucomineq_ss(a, b);
#else
  simde__m128_private
    a_ = simde__m128_to_private(a),
    b_ = simde__m128_to_private(b);
  int r;

#if defined(SIMDE_HAVE_FENV_H)
  fenv_t envp;
  int x = feholdexcept(&envp);
  r = a_.f32[0] != b_.f32[0];
  if (HEDLEY_LIKELY(x == 0))
    fesetenv(&envp);
#else
  HEDLEY_UNREACHABLE();
#endif

  return r;
#endif
}
#if defined(SIMDE_SSE_ENABLE_NATIVE_ALIASES)
#  define _mm_ucomineq_ss(a, b) simde_mm_ucomineq_ss((a), (b))
#endif

#if defined(SIMDE_SSE_NATIVE)
#  if defined(__has_builtin)
#    if __has_builtin(__builtin_ia32_undef128)
#      define SIMDE__HAVE_UNDEFINED128
#    endif
#  elif !defined(__PGI) && !defined(SIMDE_BUG_GCC_REV_208793) && !defined(_MSC_VER)
#    define SIMDE__HAVE_UNDEFINED128
#  endif
#endif

#if defined(SIMDE_DIAGNOSTIC_DISABLE_UNINITIALIZED_)
  HEDLEY_DIAGNOSTIC_PUSH
  SIMDE_DIAGNOSTIC_DISABLE_UNINITIALIZED_
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128
simde_mm_unpackhi_ps (simde__m128 a, simde__m128 b) {
#if defined(SIMDE_SSE_NATIVE)
  return _mm_unpackhi_ps(a, b);
#else
  simde__m128_private
    r_,
    a_ = simde__m128_to_private(a),
    b_ = simde__m128_to_private(b);

#if defined(SIMDE_SSE_NEON)
  float32x2_t a1 = vget_high_f32(a_.neon_f32);
  float32x2_t b1 = vget_high_f32(b_.neon_f32);
  float32x2x2_t result = vzip_f32(a1, b1);
  r_.neon_f32 = vcombine_f32(result.val[0], result.val[1]);
#elif defined(SIMDE__SHUFFLE_VECTOR)
  r_.f32 = SIMDE__SHUFFLE_VECTOR(32, 16, a_.f32, b_.f32, 2, 6, 3, 7);
#else
  r_.f32[0] = a_.f32[2];
  r_.f32[1] = b_.f32[2];
  r_.f32[2] = a_.f32[3];
  r_.f32[3] = b_.f32[3];
#endif

  return simde__m128_from_private(r_);
#endif
}
#if defined(SIMDE_SSE_ENABLE_NATIVE_ALIASES)
#  define _mm_unpackhi_ps(a, b) simde_mm_unpackhi_ps((a), (b))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128
simde_mm_unpacklo_ps (simde__m128 a, simde__m128 b) {
#if defined(SIMDE_SSE_NATIVE)
  return _mm_unpacklo_ps(a, b);
#else
  simde__m128_private
    r_,
    a_ = simde__m128_to_private(a),
    b_ = simde__m128_to_private(b);

#if defined(SIMDE__SHUFFLE_VECTOR)
  r_.f32 = SIMDE__SHUFFLE_VECTOR(32, 16, a_.f32, b_.f32, 0, 4, 1, 5);
#elif defined(SIMDE_SSE_NEON)
  float32x2_t a1 = vget_low_f32(a_.neon_f32);
  float32x2_t b1 = vget_low_f32(b_.neon_f32);
  float32x2x2_t result = vzip_f32(a1, b1);
  r_.neon_f32 = vcombine_f32(result.val[0], result.val[1]);
#else
  r_.f32[0] = a_.f32[0];
  r_.f32[1] = b_.f32[0];
  r_.f32[2] = a_.f32[1];
  r_.f32[3] = b_.f32[1];
#endif

  return simde__m128_from_private(r_);
#endif
}
#if defined(SIMDE_SSE_ENABLE_NATIVE_ALIASES)
#  define _mm_unpacklo_ps(a, b) simde_mm_unpacklo_ps((a), (b))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128
simde_mm_xor_ps (simde__m128 a, simde__m128 b) {
#if defined(SIMDE_SSE_NATIVE)
  return _mm_xor_ps(a, b);
#else
  simde__m128_private
    r_,
    a_ = simde__m128_to_private(a),
    b_ = simde__m128_to_private(b);

#if defined(SIMDE_SSE_NEON)
  r_.neon_i32 = veorq_s32(a_.neon_i32, b_.neon_i32);
#elif defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
  r_.i32f = a_.i32f ^ b_.i32f;
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.u32) / sizeof(r_.u32[0])) ; i++) {
    r_.u32[i] = a_.u32[i] ^ b_.u32[i];
  }
#endif

  return simde__m128_from_private(r_);
#endif
}
#if defined(SIMDE_SSE_ENABLE_NATIVE_ALIASES)
#  define _mm_xor_ps(a, b) simde_mm_xor_ps((a), (b))
#endif

SIMDE__FUNCTION_ATTRIBUTES
void
simde_mm_stream_pi (simde__m64* mem_addr, simde__m64 a) {
#if defined(SIMDE_SSE_NATIVE) && defined(SIMDE_ARCH_X86_MMX)
  _mm_stream_pi(HEDLEY_REINTERPRET_CAST(__m64*, mem_addr), a);
#else
  simde__m64_private*
    dest = HEDLEY_REINTERPRET_CAST(simde__m64_private*, mem_addr),
    a_ = simde__m64_to_private(a);

#if defined(SIMDE_SSE_NEON)
  dest->i64[0] = vget_lane_s64(a_.neon_i64, 0);
#else
  dest->i64[0] = a_.i64[0];
#endif
#endif
}
#if defined(SIMDE_SSE_ENABLE_NATIVE_ALIASES)
#  define _mm_stream_pi(mem_addr, a) simde_mm_stream_pi(mem_addr, (a))
#endif

SIMDE__FUNCTION_ATTRIBUTES
void
simde_mm_stream_ps (simde_float32 mem_addr[4], simde__m128 a) {
  simde_assert_aligned(16, mem_addr);

#if defined(SIMDE_SSE_NATIVE)
  _mm_stream_ps(mem_addr, a);
#else
  simde__m128_private a_ = simde__m128_to_private(a);

#if defined(SIMDE_SSE_NEON)
  vst1q_f32(mem_addr, a_.neon_f32);
#else
  SIMDE__ASSUME_ALIGNED(mem_addr, 16);
  simde_memcpy(mem_addr, &a_, sizeof(a_));
#endif
#endif
}
#if defined(SIMDE_SSE_ENABLE_NATIVE_ALIASES)
#  define _mm_stream_ps(mem_addr, a) simde_mm_stream_ps(HEDLEY_REINTERPRET_CAST(float*, mem_addr), (a))
#endif

SIMDE__FUNCTION_ATTRIBUTES
uint32_t
simde_mm_getcsr (void) {
#if defined(SIMDE_SSE_NATIVE)
  return _mm_getcsr();
#else
  uint32_t r = 0;

#if defined(SIMDE_HAVE_FENV_H)
  int rounding_mode = fegetround();

  switch(rounding_mode) {
#if defined(FE_TONEAREST)
    case FE_TONEAREST:
      break;
#endif
#if defined(FE_UPWARD)
    case FE_UPWARD:
      r |= 2 << 13;
      break;
#endif
#if defined(FE_DOWNWARD)
    case FE_DOWNWARD:
      r |= 1 << 13;
      break;
#endif
#if defined(FE_TOWARDZERO)
    case FE_TOWARDZERO:
      r = 3 << 13;
      break;
#endif
  }
#else
  HEDLEY_UNREACHABLE();
#endif

  return r;
#endif
}
#if defined(SIMDE_SSE_ENABLE_NATIVE_ALIASES)
#  define _mm_getcsr() simde_mm_getcsr()
#endif

SIMDE__FUNCTION_ATTRIBUTES
void
simde_mm_setcsr (uint32_t a) {
#if defined(SIMDE_SSE_NATIVE)
  _mm_setcsr(a);
#else
  switch((a >> 13) & 3) {
#if defined(FE_TONEAREST)
    case 0:
      fesetround(FE_TONEAREST);
#endif
#if defined(FE_DOWNWARD)
      break;
    case 1:
      fesetround(FE_DOWNWARD);
#endif
#if defined(FE_UPWARD)
      break;
    case 2:
      fesetround(FE_UPWARD);
#endif
#if defined(FE_TOWARDZERO)
      break;
    case 3:
      fesetround(FE_TOWARDZERO);
      break;
#endif
  }
#endif
}
#if defined(SIMDE_SSE_ENABLE_NATIVE_ALIASES)
#  define _mm_setcsr(a) simde_mm_setcsr(a)
#endif

#define SIMDE_MM_TRANSPOSE4_PS(row0, row1, row2, row3) \
  do { \
    simde__m128 tmp3, tmp2, tmp1, tmp0; \
    tmp0 = simde_mm_unpacklo_ps((row0), (row1)); \
    tmp2 = simde_mm_unpacklo_ps((row2), (row3)); \
    tmp1 = simde_mm_unpackhi_ps((row0), (row1)); \
    tmp3 = simde_mm_unpackhi_ps((row2), (row3)); \
    row0 = simde_mm_movelh_ps(tmp0, tmp2); \
    row1 = simde_mm_movehl_ps(tmp2, tmp0); \
    row2 = simde_mm_movelh_ps(tmp1, tmp3); \
    row3 = simde_mm_movehl_ps(tmp3, tmp1); \
  } while (0)

#if defined(SIMDE_SSE_ENABLE_NATIVE_ALIASES)
#  define _MM_TRANSPOSE4_PS(row0, row1, row2, row3) SIMDE_MM_TRANSPOSE4_PS(row0, row1, row2, row3)
#endif

#if defined(_MM_EXCEPT_INVALID)
#  define SIMDE_MM_EXCEPT_INVALID _MM_EXCEPT_INVALID
#else
#  define SIMDE_MM_EXCEPT_INVALID (0x0001)
#endif
#if defined(_MM_EXCEPT_DENORM)
#  define SIMDE_MM_EXCEPT_DENORM _MM_EXCEPT_DENORM
#else
#  define SIMDE_MM_EXCEPT_DENORM (0x0002)
#endif
#if defined(_MM_EXCEPT_DIV_ZERO)
#  define SIMDE_MM_EXCEPT_DIV_ZERO _MM_EXCEPT_DIV_ZERO
#else
#  define SIMDE_MM_EXCEPT_DIV_ZERO (0x0004)
#endif
#if defined(_MM_EXCEPT_OVERFLOW)
#  define SIMDE_MM_EXCEPT_OVERFLOW _MM_EXCEPT_OVERFLOW
#else
#  define SIMDE_MM_EXCEPT_OVERFLOW (0x0008)
#endif
#if defined(_MM_EXCEPT_UNDERFLOW)
#  define SIMDE_MM_EXCEPT_UNDERFLOW _MM_EXCEPT_UNDERFLOW
#else
#  define SIMDE_MM_EXCEPT_UNDERFLOW (0x0010)
#endif
#if defined(_MM_EXCEPT_INEXACT)
#  define SIMDE_MM_EXCEPT_INEXACT _MM_EXCEPT_INEXACT
#else
#  define SIMDE_MM_EXCEPT_INEXACT (0x0020)
#endif
#if defined(_MM_EXCEPT_MASK)
#  define SIMDE_MM_EXCEPT_MASK _MM_EXCEPT_MASK
#else
#  define SIMDE_MM_EXCEPT_MASK \
     (SIMDE_MM_EXCEPT_INVALID | SIMDE_MM_EXCEPT_DENORM | \
      SIMDE_MM_EXCEPT_DIV_ZERO | SIMDE_MM_EXCEPT_OVERFLOW | \
      SIMDE_MM_EXCEPT_UNDERFLOW | SIMDE_MM_EXCEPT_INEXACT)
#endif

#if defined(_MM_MASK_INVALID)
#  define SIMDE_MM_MASK_INVALID _MM_MASK_INVALID
#else
#  define SIMDE_MM_MASK_INVALID (0x0080)
#endif
#if defined(_MM_MASK_DENORM)
#  define SIMDE_MM_MASK_DENORM _MM_MASK_DENORM
#else
#  define SIMDE_MM_MASK_DENORM (0x0100)
#endif
#if defined(_MM_MASK_DIV_ZERO)
#  define SIMDE_MM_MASK_DIV_ZERO _MM_MASK_DIV_ZERO
#else
#  define SIMDE_MM_MASK_DIV_ZERO (0x0200)
#endif
#if defined(_MM_MASK_OVERFLOW)
#  define SIMDE_MM_MASK_OVERFLOW _MM_MASK_OVERFLOW
#else
#  define SIMDE_MM_MASK_OVERFLOW (0x0400)
#endif
#if defined(_MM_MASK_UNDERFLOW)
#  define SIMDE_MM_MASK_UNDERFLOW _MM_MASK_UNDERFLOW
#else
#  define SIMDE_MM_MASK_UNDERFLOW (0x0800)
#endif
#if defined(_MM_MASK_INEXACT)
#  define SIMDE_MM_MASK_INEXACT _MM_MASK_INEXACT
#else
#  define SIMDE_MM_MASK_INEXACT (0x1000)
#endif
#if defined(_MM_MASK_MASK)
#  define SIMDE_MM_MASK_MASK _MM_MASK_MASK
#else
#  define SIMDE_MM_MASK_MASK \
     (SIMDE_MM_MASK_INVALID | SIMDE_MM_MASK_DENORM | \
      SIMDE_MM_MASK_DIV_ZERO | SIMDE_MM_MASK_OVERFLOW | \
      SIMDE_MM_MASK_UNDERFLOW | SIMDE_MM_MASK_INEXACT)
#endif

#if defined(_MM_FLUSH_ZERO_MASK)
#  define SIMDE_MM_FLUSH_ZERO_MASK _MM_FLUSH_ZERO_MASK
#else
#  define SIMDE_MM_FLUSH_ZERO_MASK (0x8000)
#endif
#if defined(_MM_FLUSH_ZERO_ON)
#  define SIMDE_MM_FLUSH_ZERO_ON _MM_FLUSH_ZERO_ON
#else
#  define SIMDE_MM_FLUSH_ZERO_ON (0x8000)
#endif
#if defined(_MM_FLUSH_ZERO_OFF)
#  define SIMDE_MM_FLUSH_ZERO_OFF _MM_FLUSH_ZERO_OFF
#else
#  define SIMDE_MM_FLUSH_ZERO_OFF (0x0000)
#endif

SIMDE__END_DECLS

HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE__SSE_H) */
