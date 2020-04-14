/* Copyright (c) 2017-2020 Evan Nemerson <evan@nemerson.com>
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

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS

#  if defined(SIMDE_SSE4_1_NATIVE)
#    undef SIMDE_SSE4_1_NATIVE
#  endif
#  if defined(SIMDE_ARCH_X86_SSE4_1) && !defined(SIMDE_SSE4_1_NO_NATIVE) && !defined(SIMDE_NO_NATIVE)
#    define SIMDE_SSE4_1_NATIVE
#  elif defined(__ARM_NEON) && !defined(SIMDE_SSE4_1_NO_NEON) && !defined(SIMDE_NO_NEON)
#    define SIMDE_SSE4_1_NEON
#  elif defined(SIMDE_ARCH_POWER_ALTIVEC)
#    define SIMDE_SSE4_1_POWER_ALTIVEC
#  endif

#  if defined(SIMDE_SSE4_1_NATIVE) && !defined(SIMDE_SSE3_NATIVE)
#    if defined(SIMDE_SSE4_1_FORCE_NATIVE)
#      error Native SSE4.1 support requires native SSE3 support
#    else
       HEDLEY_WARNING("Native SSE4.1 support requires native SSE3 support, disabling")
#      undef SIMDE_SSE4_1_NATIVE
#    endif
#  elif defined(SIMDE_SSE4_1_NEON) && !defined(SIMDE_SSE3_NEON)
     HEDLEY_WARNING("SSE4.1 NEON support requires SSE3 NEON support, disabling")
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

#if !defined(SIMDE_SSE4_1_NATIVE) && defined(SIMDE_ENABLE_NATIVE_ALIASES)
#  define SIMDE_SSE4_1_ENABLE_NATIVE_ALIASES
#endif

#if defined(SIMDE_SSE4_1_NATIVE)
#  define SIMDE_MM_FROUND_TO_NEAREST_INT _MM_FROUND_TO_NEAREST_INT
#  define SIMDE_MM_FROUND_TO_NEG_INF     _MM_FROUND_TO_NEG_INF
#  define SIMDE_MM_FROUND_TO_POS_INF     _MM_FROUND_TO_POS_INF
#  define SIMDE_MM_FROUND_TO_ZERO        _MM_FROUND_TO_ZERO
#  define SIMDE_MM_FROUND_CUR_DIRECTION  _MM_FROUND_CUR_DIRECTION

#  define SIMDE_MM_FROUND_RAISE_EXC      _MM_FROUND_RAISE_EXC
#  define SIMDE_MM_FROUND_NO_EXC         _MM_FROUND_NO_EXC
#else
#  define SIMDE_MM_FROUND_TO_NEAREST_INT 0x00
#  define SIMDE_MM_FROUND_TO_NEG_INF     0x01
#  define SIMDE_MM_FROUND_TO_POS_INF     0x02
#  define SIMDE_MM_FROUND_TO_ZERO        0x03
#  define SIMDE_MM_FROUND_CUR_DIRECTION  0x04

#  define SIMDE_MM_FROUND_RAISE_EXC      0x00
#  define SIMDE_MM_FROUND_NO_EXC         0x08
#endif

#define SIMDE_MM_FROUND_NINT		\
  (SIMDE_MM_FROUND_TO_NEAREST_INT | SIMDE_MM_FROUND_RAISE_EXC)
#define SIMDE_MM_FROUND_FLOOR	\
  (SIMDE_MM_FROUND_TO_NEG_INF | SIMDE_MM_FROUND_RAISE_EXC)
#define SIMDE_MM_FROUND_CEIL		\
  (SIMDE_MM_FROUND_TO_POS_INF | SIMDE_MM_FROUND_RAISE_EXC)
#define SIMDE_MM_FROUND_TRUNC	\
  (SIMDE_MM_FROUND_TO_ZERO | SIMDE_MM_FROUND_RAISE_EXC)
#define SIMDE_MM_FROUND_RINT		\
  (SIMDE_MM_FROUND_CUR_DIRECTION | SIMDE_MM_FROUND_RAISE_EXC)
#define SIMDE_MM_FROUND_NEARBYINT	\
  (SIMDE_MM_FROUND_CUR_DIRECTION | SIMDE_MM_FROUND_NO_EXC)

#if defined(SIMDE_SSE4_1_ENABLE_NATIVE_ALIASES)
#  define _MM_FROUND_TO_NEAREST_INT SIMDE_MM_FROUND_TO_NEAREST_INT
#  define _MM_FROUND_TO_NEG_INF SIMDE_MM_FROUND_TO_NEG_INF
#  define _MM_FROUND_TO_POS_INF SIMDE_MM_FROUND_TO_POS_INF
#  define _MM_FROUND_TO_ZERO SIMDE_MM_FROUND_TO_ZERO
#  define _MM_FROUND_CUR_DIRECTION SIMDE_MM_FROUND_CUR_DIRECTION
#  define _MM_FROUND_RAISE_EXC SIMDE_MM_FROUND_RAISE_EXC
#  define _MM_FROUND_NINT SIMDE_MM_FROUND_NINT
#  define _MM_FROUND_FLOOR SIMDE_MM_FROUND_FLOOR
#  define _MM_FROUND_CEIL SIMDE_MM_FROUND_CEIL
#  define _MM_FROUND_TRUNC SIMDE_MM_FROUND_TRUNC
#  define _MM_FROUND_RINT SIMDE_MM_FROUND_RINT
#  define _MM_FROUND_NEARBYINT SIMDE_MM_FROUND_NEARBYINT
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_blend_epi16 (simde__m128i a, simde__m128i b, const int imm8)
    HEDLEY_REQUIRE_MSG((imm8 & 0xff) == imm8, "imm8 must be in range [0, 255]")  {
  simde__m128i_private
    r_,
    a_ = simde__m128i_to_private(a),
    b_ = simde__m128i_to_private(b);

  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.u16) / sizeof(r_.u16[0])) ; i++) {
    r_.u16[i] = ((imm8 >> i) & 1) ? b_.u16[i] : a_.u16[i];
  }

  return simde__m128i_from_private(r_);
}
#if defined(SIMDE_SSE4_1_NATIVE)
#  define simde_mm_blend_epi16(a, b, imm8) _mm_blend_epi16(a, b, imm8)
#endif
#if defined(SIMDE_SSE4_1_ENABLE_NATIVE_ALIASES)
#  define _mm_blend_epi16(a, b, imm8) simde_mm_blend_epi16(a, b, imm8)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128d
simde_mm_blend_pd (simde__m128d a, simde__m128d b, const int imm8)
    HEDLEY_REQUIRE_MSG((imm8 & 3) == imm8, "imm8 must be in range [0, 3]")  {
  simde__m128d_private
    r_,
    a_ = simde__m128d_to_private(a),
    b_ = simde__m128d_to_private(b);

  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.f64) / sizeof(r_.f64[0])) ; i++) {
    r_.f64[i] = ((imm8 >> i) & 1) ? b_.f64[i] : a_.f64[i];
  }
  return simde__m128d_from_private(r_);
}
#if defined(SIMDE_SSE4_1_NATIVE)
#  define simde_mm_blend_pd(a, b, imm8) _mm_blend_pd(a, b, imm8)
#endif
#if defined(SIMDE_SSE4_1_ENABLE_NATIVE_ALIASES)
#  define _mm_blend_pd(a, b, imm8) simde_mm_blend_pd(a, b, imm8)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128
simde_mm_blend_ps (simde__m128 a, simde__m128 b, const int imm8)
    HEDLEY_REQUIRE_MSG((imm8 & 0xf) == imm8, "imm8 must be in range [0, 15]")  {
  simde__m128_private
    r_,
    a_ = simde__m128_to_private(a),
    b_ = simde__m128_to_private(b);

  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.f32) / sizeof(r_.f32[0])) ; i++) {
    r_.f32[i] = ((imm8 >> i) & 1) ? b_.f32[i] : a_.f32[i];
  }
  return simde__m128_from_private(r_);
}
#if defined(SIMDE_SSE4_1_NATIVE)
#  define simde_mm_blend_ps(a, b, imm8) _mm_blend_ps(a, b, imm8)
#endif
#if defined(SIMDE_SSE4_1_ENABLE_NATIVE_ALIASES)
#  define _mm_blend_ps(a, b, imm8) simde_mm_blend_ps(a, b, imm8)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_blendv_epi8 (simde__m128i a, simde__m128i b, simde__m128i mask) {
#if defined(SIMDE_SSE4_1_NATIVE)
  return _mm_blendv_epi8(a, b, mask);
#else
  simde__m128i_private
    r_,
    a_ = simde__m128i_to_private(a),
    b_ = simde__m128i_to_private(b),
    mask_ = simde__m128i_to_private(mask);

#if defined(SIMDE_SSE4_1_NEON)
  mask_ = simde__m128i_to_private(simde_mm_cmplt_epi8(mask, simde_mm_setzero_si128()));
  r_.neon_i8 = vbslq_s8(mask_.neon_u8, b_.neon_i8, a_.neon_i8);
#elif defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
  /* https://software.intel.com/en-us/forums/intel-c-compiler/topic/850087 */
  #if defined(HEDLEY_INTEL_VERSION_CHECK)
    __typeof__(mask_.i8) z = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    mask_.i8 = HEDLEY_STATIC_CAST(__typeof__(mask_.i8), mask_.i8 < z);
  #else
    mask_.i8 >>= (CHAR_BIT * sizeof(mask_.i8[0])) - 1;
  #endif

  r_.i8 = (mask_.i8 & b_.i8) | (~mask_.i8 & a_.i8);
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.i8) / sizeof(r_.i8[0])) ; i++) {
    int8_t m = mask_.i8[i] >> 7;
    r_.i8[i] = (m & b_.i8[i]) | (~m & a_.i8[i]);
  }
#endif

  return simde__m128i_from_private(r_);
#endif
}
#if defined(SIMDE_SSE4_1_ENABLE_NATIVE_ALIASES)
#  define _mm_blendv_epi8(a, b, mask) simde_mm_blendv_epi8(a, b, mask)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128i
simde_x_mm_blendv_epi16 (simde__m128i a, simde__m128i b, simde__m128i mask) {
#if defined(SIMDE_SSE2_NATIVE)
  mask = simde_mm_srai_epi16(mask, 15);
  return simde_mm_or_si128(simde_mm_and_si128(mask, b), simde_mm_andnot_si128(mask, a));
#else
  simde__m128i_private
    r_,
    a_ = simde__m128i_to_private(a),
    b_ = simde__m128i_to_private(b),
    mask_ = simde__m128i_to_private(mask);

#if defined(SIMDE_SSE4_1_NEON)
  mask_ = simde__m128i_to_private(simde_mm_cmplt_epi16(mask, simde_mm_setzero_si128()));
  r_.neon_i16 = vbslq_s16(mask_.neon_u16, b_.neon_i16, a_.neon_i16);
#elif defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
  #if defined(HEDLEY_INTEL_VERSION_CHECK)
    __typeof__(mask_.i16) z = { 0, 0, 0, 0, 0, 0, 0, 0 };
    mask_.i16 = mask_.i16 < z;
  #else
    mask_.i16 >>= (CHAR_BIT * sizeof(mask_.i16[0])) - 1;
  #endif

  r_.i16 = (mask_.i16 & b_.i16) | (~mask_.i16 & a_.i16);
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.i16) / sizeof(r_.i16[0])) ; i++) {
    int16_t m = mask_.i16[i] >> 15;
    r_.i16[i] = (m & b_.i16[i]) | (~m & a_.i16[i]);
  }
#endif

  return simde__m128i_from_private(r_);
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m128i
simde_x_mm_blendv_epi32 (simde__m128i a, simde__m128i b, simde__m128i mask) {
#if defined(SIMDE_SSE4_1_NATIVE)
  return _mm_castps_si128(_mm_blendv_ps(_mm_castsi128_ps(a), _mm_castsi128_ps(b), _mm_castsi128_ps(mask)));
#else
  simde__m128i_private
    r_,
    a_ = simde__m128i_to_private(a),
    b_ = simde__m128i_to_private(b),
    mask_ = simde__m128i_to_private(mask);

#if defined(SIMDE_SSE4_1_NEON)
  mask_ = simde__m128i_to_private(simde_mm_cmplt_epi32(mask, simde_mm_setzero_si128()));
  r_.neon_i32 = vbslq_s32(mask_.neon_u32, b_.neon_i32, a_.neon_i32);
#elif defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
  #if defined(HEDLEY_INTEL_VERSION_CHECK)
    __typeof__(mask_.i32) z = { 0, 0, 0, 0 };
    mask_.i32 = mask_.i32 < z;
  #else
    mask_.i32 >>= (CHAR_BIT * sizeof(mask_.i32[0])) - 1;
  #endif

  r_.i32 = (mask_.i32 & b_.i32) | (~mask_.i32 & a_.i32);
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.i32) / sizeof(r_.i32[0])) ; i++) {
    int32_t m = mask_.i32[i] >> 31;
    r_.i32[i] = (m & b_.i32[i]) | (~m & a_.i32[i]);
  }
#endif

  return simde__m128i_from_private(r_);
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m128i
simde_x_mm_blendv_epi64 (simde__m128i a, simde__m128i b, simde__m128i mask) {
#if defined(SIMDE_SSE4_1_NATIVE)
  return _mm_castpd_si128(_mm_blendv_pd(_mm_castsi128_pd(a), _mm_castsi128_pd(b), _mm_castsi128_pd(mask)));
#else
  simde__m128i_private
    r_,
    a_ = simde__m128i_to_private(a),
    b_ = simde__m128i_to_private(b),
    mask_ = simde__m128i_to_private(mask);

#if defined(SIMDE_SSE4_1_NEON) && defined(SIMDE_ARCH_AARCH64)
  mask_.i64 = vreinterpretq_s64_u64(vcltq_s64(mask_.i64, vdupq_n_s64(UINT64_C(0))));
  r_.neon_i64 = vbslq_s64(mask_.neon_u64, b_.neon_i64, a_.neon_i64);
#elif defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
  #if defined(HEDLEY_INTEL_VERSION_CHECK)
    __typeof__(mask_.i64) z = { 0, 0 };
    mask_.i64 = HEDLEY_STATIC_CAST(__typeof__(mask_.i64), mask_.i64 < z);
  #else
    mask_.i64 >>= (CHAR_BIT * sizeof(mask_.i64[0])) - 1;
  #endif

  r_.i64 = (mask_.i64 & b_.i64) | (~mask_.i64 & a_.i64);
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.i64) / sizeof(r_.i64[0])) ; i++) {
    int64_t m = mask_.i64[i] >> 63;
    r_.i64[i] = (m & b_.i64[i]) | (~m & a_.i64[i]);
  }
#endif

  return simde__m128i_from_private(r_);
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m128d
simde_mm_blendv_pd (simde__m128d a, simde__m128d b, simde__m128d mask) {
#if defined(SIMDE_SSE4_1_NATIVE)
  return _mm_blendv_pd(a, b, mask);
#else
  return simde_mm_castsi128_pd(simde_x_mm_blendv_epi64(simde_mm_castpd_si128(a), simde_mm_castpd_si128(b), simde_mm_castpd_si128(mask)));
#endif
}
#if defined(SIMDE_SSE4_1_ENABLE_NATIVE_ALIASES)
#  define _mm_blendv_pd(a, b, mask) simde_mm_blendv_pd(a, b, mask)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128
simde_mm_blendv_ps (simde__m128 a, simde__m128 b, simde__m128 mask) {
#if defined(SIMDE_SSE4_1_NATIVE)
  return _mm_blendv_ps(a, b, mask);
#else
  return simde_mm_castsi128_ps(simde_x_mm_blendv_epi32(simde_mm_castps_si128(a), simde_mm_castps_si128(b), simde_mm_castps_si128(mask)));
#endif
}
#if defined(SIMDE_SSE4_1_ENABLE_NATIVE_ALIASES)
#  define _mm_blendv_ps(a, b, mask) simde_mm_blendv_ps(a, b, mask)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128d
simde_mm_ceil_pd (simde__m128d a) {
#if defined(SIMDE_SSE4_1_NATIVE)
  return _mm_ceil_pd(a);
#else
  simde__m128d_private
    r_,
    a_ = simde__m128d_to_private(a);

  #if defined(SIMDE_SSE4_1_NEON) && defined(SIMDE_ARCH_AARCH64)
    r_.neon_f64 = vrndpq_f64(a_.neon_f64);
  #elif defined(SIMDE_SSE_POWER_ALTIVEC)
    r_.altivec_f64 = vec_ceil(a_.altivec_f64);
  #elif defined(SIMDE_HAVE_MATH_H)
    SIMDE__VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f64) / sizeof(r_.f64[0])) ; i++) {
      r_.f64[i] = ceil(a_.f64[i]);
    }
  #else
    HEDLEY_UNREACHABLE();
  #endif

  return simde__m128d_from_private(r_);
#endif
}
#if defined(SIMDE_SSE4_1_ENABLE_NATIVE_ALIASES)
#  define _mm_ceil_pd(a) simde_mm_ceil_pd(a)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128
simde_mm_ceil_ps (simde__m128 a) {
#if defined(SIMDE_SSE4_1_NATIVE)
  return _mm_ceil_ps(a);
#else
  simde__m128_private
    r_,
    a_ = simde__m128_to_private(a);

  #if defined(SIMDE_SSE4_1_NEON) && (SIMDE_ARCH_ARM >= 80) && (!defined(HEDLEY_GCC_VERSION) || HEDLEY_GCC_VERSION_CHECK(9,0,0))
    r_.neon_f32 = vrndpq_f32(a_.neon_f32);
  #elif defined(SIMDE_SSE_POWER_ALTIVEC)
    r_.altivec_f32 = vec_ceil(a_.altivec_f32);
  #elif defined(SIMDE_HAVE_MATH_H)
    SIMDE__VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f32) / sizeof(r_.f32[0])) ; i++) {
      r_.f32[i] = ceilf(a_.f32[i]);
    }
  #else
    HEDLEY_UNREACHABLE();
  #endif

  return simde__m128_from_private(r_);
#endif
}
#if defined(SIMDE_SSE4_1_ENABLE_NATIVE_ALIASES)
#  define _mm_ceil_ps(a) simde_mm_ceil_ps(a)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128d
simde_mm_ceil_sd (simde__m128d a, simde__m128d b) {
#if defined(SIMDE_SSE4_1_NATIVE)
  return _mm_ceil_sd(a, b);
#else
  simde__m128d_private
    r_,
    a_ = simde__m128d_to_private(a),
    b_ = simde__m128d_to_private(b);

#if defined(SIMDE_HAVE_MATH_H)
  r_ = simde__m128d_to_private(simde_mm_set_pd(a_.f64[1], ceil(b_.f64[0])));
#else
  HEDLEY_UNREACHABLE();
#endif

  return simde__m128d_from_private(r_);
#endif
}
#if defined(SIMDE_SSE4_1_ENABLE_NATIVE_ALIASES)
#  define _mm_ceil_sd(a, b) simde_mm_ceil_sd(a, b)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128
simde_mm_ceil_ss (simde__m128 a, simde__m128 b) {
#if defined(SIMDE_SSE4_1_NATIVE)
  return _mm_ceil_ss(a, b);
#elif defined(SIMDE_ASSUME_VECTORIZATION)
  return simde_mm_move_ss(a, simde_mm_ceil_ps(b));
#else
  simde__m128_private
    r_,
    a_ = simde__m128_to_private(a),
    b_ = simde__m128_to_private(b);

  #if defined(SIMDE_HAVE_MATH_H)
    r_ = simde__m128_to_private(simde_mm_set_ps(a_.f32[3], a_.f32[2], a_.f32[1], ceilf(b_.f32[0])));
  #else
    HEDLEY_UNREACHABLE();
  #endif

  return simde__m128_from_private(r_);
#endif
}
#if defined(SIMDE_SSE4_1_ENABLE_NATIVE_ALIASES)
#  define _mm_ceil_ss(a, b) simde_mm_ceil_ss(a, b)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_cmpeq_epi64 (simde__m128i a, simde__m128i b) {
#if defined(SIMDE_SSE4_1_NATIVE)
  return _mm_cmpeq_epi64(a, b);
#else
  simde__m128i_private
    r_,
    a_ = simde__m128i_to_private(a),
    b_ = simde__m128i_to_private(b);

  #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
    r_.i64 = HEDLEY_STATIC_CAST(__typeof__(r_.i64), a_.i64 == b_.i64);
  #elif defined(SIMDE_SSE_POWER_ALTIVEC)
    r_.altivec_i64 = (vector signed long long) vec_cmpeq(a_.altivec_i64, b_.altivec_i64);
  #else
    SIMDE__VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.u64) / sizeof(r_.u64[0])) ; i++) {
      r_.u64[i] = (a_.u64[i] == b_.u64[i]) ? ~UINT64_C(0) : UINT64_C(0);
    }
  #endif

  return simde__m128i_from_private(r_);
#endif
}
#if defined(SIMDE_SSE4_1_ENABLE_NATIVE_ALIASES)
#  define _mm_cmpeq_epi64(a, b) simde_mm_cmpeq_epi64(a, b)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_cvtepi8_epi16 (simde__m128i a) {
#if defined(SIMDE_SSE4_1_NATIVE)
  return _mm_cvtepi8_epi16(a);
#else
  simde__m128i_private
    r_,
    a_ = simde__m128i_to_private(a);

  #if defined(SIMDE__CONVERT_VECTOR)
    SIMDE__CONVERT_VECTOR(r_.i16, a_.m64_private[0].i8);
  #else
    SIMDE__VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.i16) / sizeof(r_.i16[0])) ; i++) {
      r_.i16[i] = a_.i8[i];
    }
  #endif

  return simde__m128i_from_private(r_);
#endif
}
#if defined(SIMDE_SSE4_1_ENABLE_NATIVE_ALIASES)
#  define _mm_cvtepi8_epi16(a) simde_mm_cvtepi8_epi16(a)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_cvtepi8_epi32 (simde__m128i a) {
#if defined(SIMDE_SSE4_1_NATIVE)
  return _mm_cvtepi8_epi32(a);
#else
  simde__m128i_private
    r_,
    a_ = simde__m128i_to_private(a);

  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.i32) / sizeof(r_.i32[0])) ; i++) {
    r_.i32[i] = a_.i8[i];
  }

  return simde__m128i_from_private(r_);
#endif
}
#if defined(SIMDE_SSE4_1_ENABLE_NATIVE_ALIASES)
#  define _mm_cvtepi8_epi32(a) simde_mm_cvtepi8_epi32(a)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_cvtepi8_epi64 (simde__m128i a) {
#if defined(SIMDE_SSE4_1_NATIVE)
  return _mm_cvtepi8_epi64(a);
#else
  simde__m128i_private
    r_,
    a_ = simde__m128i_to_private(a);

  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.i64) / sizeof(r_.i64[0])) ; i++) {
    r_.i64[i] = a_.i8[i];
  }

  return simde__m128i_from_private(r_);
#endif
}
#if defined(SIMDE_SSE4_1_ENABLE_NATIVE_ALIASES)
#  define _mm_cvtepi8_epi64(a) simde_mm_cvtepi8_epi64(a)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_cvtepu8_epi16 (simde__m128i a) {
#if defined(SIMDE_SSE4_1_NATIVE)
  return _mm_cvtepu8_epi16(a);
#else
  simde__m128i_private
    r_,
    a_ = simde__m128i_to_private(a);

  #if defined(SIMDE__CONVERT_VECTOR) && !defined(SIMDE_BUG_CLANG_45541)
    SIMDE__CONVERT_VECTOR(r_.i16, a_.m64_private[0].u8);
  #else
    SIMDE__VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.i16) / sizeof(r_.i16[0])) ; i++) {
      r_.i16[i] = a_.u8[i];
    }
  #endif

  return simde__m128i_from_private(r_);
#endif
}
#if defined(SIMDE_SSE4_1_ENABLE_NATIVE_ALIASES)
#  define _mm_cvtepu8_epi16(a) simde_mm_cvtepu8_epi16(a)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_cvtepu8_epi32 (simde__m128i a) {
#if defined(SIMDE_SSE4_1_NATIVE)
  return _mm_cvtepu8_epi32(a);
#else
  simde__m128i_private
    r_,
    a_ = simde__m128i_to_private(a);

#if defined(SIMDE_SSE4_1_NEON)
  uint8x16_t u8x16 = a_.neon_u8;
  uint16x8_t u16x8 = vmovl_u8(vget_low_u8(u8x16));
  r_.neon_u32 = vmovl_u16(vget_low_u16(u16x8));
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.i32) / sizeof(r_.i32[0])) ; i++) {
    r_.i32[i] = a_.u8[i];
  }
#endif

  return simde__m128i_from_private(r_);
#endif
}
#if defined(SIMDE_SSE4_1_ENABLE_NATIVE_ALIASES)
#  define _mm_cvtepu8_epi32(a) simde_mm_cvtepu8_epi32(a)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_cvtepu8_epi64 (simde__m128i a) {
#if defined(SIMDE_SSE4_1_NATIVE)
  return _mm_cvtepu8_epi64(a);
#else
  simde__m128i_private
    r_,
    a_ = simde__m128i_to_private(a);

  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.i64) / sizeof(r_.i64[0])) ; i++) {
    r_.i64[i] = a_.u8[i];
  }

  return simde__m128i_from_private(r_);
#endif
}
#if defined(SIMDE_SSE4_1_ENABLE_NATIVE_ALIASES)
#  define _mm_cvtepu8_epi64(a) simde_mm_cvtepu8_epi64(a)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_cvtepi16_epi32 (simde__m128i a) {
#if defined(SIMDE_SSE4_1_NATIVE)
  return _mm_cvtepi16_epi32(a);
#else
  simde__m128i_private
    r_,
    a_ = simde__m128i_to_private(a);

#if defined(SIMDE_SSE4_1_NEON)
  r_.neon_i32 = vmovl_s16(vget_low_s16(a_.neon_i16));
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.i32) / sizeof(r_.i32[0])) ; i++) {
    r_.i32[i] = a_.i16[i];
  }
#endif

  return simde__m128i_from_private(r_);
#endif
}
#if defined(SIMDE_SSE4_1_ENABLE_NATIVE_ALIASES)
#  define _mm_cvtepi16_epi32(a) simde_mm_cvtepi16_epi32(a)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_cvtepu16_epi32 (simde__m128i a) {
#if defined(SIMDE_SSE4_1_NATIVE)
  return _mm_cvtepu16_epi32(a);
#else
  simde__m128i_private
    r_,
    a_ = simde__m128i_to_private(a);

  #if defined(SIMDE__CONVERT_VECTOR) && !defined(SIMDE_BUG_CLANG_45541)
    SIMDE__CONVERT_VECTOR(r_.i32, a_.m64_private[0].u16);
  #else
    SIMDE__VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.i32) / sizeof(r_.i32[0])) ; i++) {
      r_.i32[i] = a_.u16[i];
    }
  #endif

  return simde__m128i_from_private(r_);
#endif
}
#if defined(SIMDE_SSE4_1_ENABLE_NATIVE_ALIASES)
#  define _mm_cvtepu16_epi32(a) simde_mm_cvtepu16_epi32(a)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_cvtepu16_epi64 (simde__m128i a) {
#if defined(SIMDE_SSE4_1_NATIVE)
  return _mm_cvtepu16_epi64(a);
#else
  simde__m128i_private
    r_,
    a_ = simde__m128i_to_private(a);

  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.i64) / sizeof(r_.i64[0])) ; i++) {
    r_.i64[i] = a_.u16[i];
  }

  return simde__m128i_from_private(r_);
#endif
}
#if defined(SIMDE_SSE4_1_ENABLE_NATIVE_ALIASES)
#  define _mm_cvtepu16_epi64(a) simde_mm_cvtepu16_epi64(a)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_cvtepi16_epi64 (simde__m128i a) {
#if defined(SIMDE_SSE4_1_NATIVE)
  return _mm_cvtepi16_epi64(a);
#else
  simde__m128i_private
    r_,
    a_ = simde__m128i_to_private(a);

  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.i64) / sizeof(r_.i64[0])) ; i++) {
    r_.i64[i] = a_.i16[i];
  }

  return simde__m128i_from_private(r_);
#endif
}
#if defined(SIMDE_SSE4_1_ENABLE_NATIVE_ALIASES)
#  define _mm_cvtepi16_epi64(a) simde_mm_cvtepi16_epi64(a)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_cvtepi32_epi64 (simde__m128i a) {
#if defined(SIMDE_SSE4_1_NATIVE)
  return _mm_cvtepi32_epi64(a);
#else
  simde__m128i_private
    r_,
    a_ = simde__m128i_to_private(a);

  #if defined(SIMDE__CONVERT_VECTOR)
    SIMDE__CONVERT_VECTOR(r_.i64, a_.m64_private[0].i32);
  #else
    SIMDE__VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.i64) / sizeof(r_.i64[0])) ; i++) {
      r_.i64[i] = a_.i32[i];
    }
  #endif

  return simde__m128i_from_private(r_);
#endif
}
#if defined(SIMDE_SSE4_1_ENABLE_NATIVE_ALIASES)
#  define _mm_cvtepi32_epi64(a) simde_mm_cvtepi32_epi64(a)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_cvtepu32_epi64 (simde__m128i a) {
#if defined(SIMDE_SSE4_1_NATIVE)
  return _mm_cvtepu32_epi64(a);
#else
  simde__m128i_private
    r_,
    a_ = simde__m128i_to_private(a);

  #if defined(SIMDE__CONVERT_VECTOR)
    SIMDE__CONVERT_VECTOR(r_.i64, a_.m64_private[0].u32);
  #else
    SIMDE__VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.i64) / sizeof(r_.i64[0])) ; i++) {
      r_.i64[i] = a_.u32[i];
    }
  #endif

  return simde__m128i_from_private(r_);
#endif
}
#if defined(SIMDE_SSE4_1_ENABLE_NATIVE_ALIASES)
#  define _mm_cvtepu32_epi64(a) simde_mm_cvtepu32_epi64(a)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128d
simde_mm_dp_pd (simde__m128d a, simde__m128d b, const int imm8)
    HEDLEY_REQUIRE_MSG((imm8 & 0xff) == imm8, "imm8 must be in range [0, 255]")  {
  simde__m128d_private
    r_,
    a_ = simde__m128d_to_private(a),
    b_ = simde__m128d_to_private(b);

  simde_float64 sum = SIMDE_FLOAT64_C(0.0);

  SIMDE__VECTORIZE_REDUCTION(+:sum)
  for (size_t i = 0 ; i < (sizeof(r_.f64) / sizeof(r_.f64[0])) ; i++) {
    sum += ((imm8 >> (i + 4)) & 1) ? (a_.f64[i] * b_.f64[i]) : 0.0;
  }

  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.f64) / sizeof(r_.f64[0])) ; i++) {
    r_.f64[i] = ((imm8 >> i) & 1) ? sum : 0.0;
  }

  return simde__m128d_from_private(r_);
}
#if defined(SIMDE_SSE4_1_NATIVE)
#  define simde_mm_dp_pd(a, b, imm8) _mm_dp_pd(a, b, imm8)
#endif
#if defined(SIMDE_SSE4_1_ENABLE_NATIVE_ALIASES)
#  define _mm_dp_pd(a, b, imm8) simde_mm_dp_pd(a, b, imm8)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128
simde_mm_dp_ps (simde__m128 a, simde__m128 b, const int imm8)
    HEDLEY_REQUIRE_MSG((imm8 & 0xff) == imm8, "imm8 must be in range [0, 255]")  {
  simde__m128_private
    r_,
    a_ = simde__m128_to_private(a),
    b_ = simde__m128_to_private(b);

  simde_float32 sum = SIMDE_FLOAT32_C(0.0);

  SIMDE__VECTORIZE_REDUCTION(+:sum)
  for (size_t i = 0 ; i < (sizeof(r_.f32) / sizeof(r_.f32[0])) ; i++) {
    sum += ((imm8 >> (i + 4)) & 1) ? (a_.f32[i] * b_.f32[i]) : SIMDE_FLOAT32_C(0.0);
  }

  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.f32) / sizeof(r_.f32[0])) ; i++) {
    r_.f32[i] = ((imm8 >> i) & 1) ? sum : SIMDE_FLOAT32_C(0.0);
  }

  return simde__m128_from_private(r_);
}
#if defined(SIMDE_SSE4_1_NATIVE)
#  define simde_mm_dp_ps(a, b, imm8) _mm_dp_ps(a, b, imm8)
#endif
#if defined(SIMDE_SSE4_1_ENABLE_NATIVE_ALIASES)
#  define _mm_dp_ps(a, b, imm8) simde_mm_dp_ps(a, b, imm8)
#endif

#if defined(simde_mm_extract_epi8)
#  undef simde_mm_extract_epi8
#endif
SIMDE__FUNCTION_ATTRIBUTES
int8_t
simde_mm_extract_epi8 (simde__m128i a, const int imm8)
    HEDLEY_REQUIRE_MSG((imm8 & 0xf) == imm8, "imm8 must be in range [0, 15]")  {
  simde__m128i_private
    a_ = simde__m128i_to_private(a);

  return a_.i8[imm8&15];
}
#if defined(SIMDE_SSE4_1_NATIVE) && !defined(SIMDE_BUG_GCC_BAD_MM_EXTRACT_EPI8)
#  define simde_mm_extract_epi8(a, imm8) HEDLEY_STATIC_CAST(int8_t, _mm_extract_epi8(a, imm8))
#elif defined(SIMDE_SSE4_1_NEON)
#  define simde_mm_extract_epi8(a, imm8) vgetq_lane_s8(simde__m128i_to_private(a).neon_i8, imm8)
#endif
#if defined(SIMDE_SSE4_1_ENABLE_NATIVE_ALIASES)
#  define _mm_extract_epi8(a, imm8) HEDLEY_STATIC_CAST(int, simde_mm_extract_epi8(a, imm8))
#endif

#if defined(simde_mm_extract_epi32)
#  undef simde_mm_extract_epi32
#endif
SIMDE__FUNCTION_ATTRIBUTES
int32_t
simde_mm_extract_epi32 (simde__m128i a, const int imm8)
    HEDLEY_REQUIRE_MSG((imm8 & 3) == imm8, "imm8 must be in range [0, 3]")  {
  simde__m128i_private
    a_ = simde__m128i_to_private(a);

  return a_.i32[imm8&3];
}
#if defined(SIMDE_SSE4_1_NATIVE)
#  define simde_mm_extract_epi32(a, imm8) _mm_extract_epi32(a, imm8)
#elif defined(SIMDE_SSE4_1_NEON)
#  define simde_mm_extract_epi32(a, imm8) vgetq_lane_s32(simde__m128i_to_private(a).neon_i32, imm8)
#endif
#if defined(SIMDE_SSE4_1_ENABLE_NATIVE_ALIASES)
#  define _mm_extract_epi32(a, imm8) simde_mm_extract_epi32(a, imm8)
#endif

#if defined(simde_mm_extract_epi64)
#  undef simde_mm_extract_epi64
#endif
SIMDE__FUNCTION_ATTRIBUTES
int64_t
simde_mm_extract_epi64 (simde__m128i a, const int imm8)
    HEDLEY_REQUIRE_MSG((imm8 & 1) == imm8, "imm8 must be 0 or 1")  {
  simde__m128i_private
    a_ = simde__m128i_to_private(a);

  return a_.i64[imm8&1];
}
#if defined(SIMDE_SSE4_1_NATIVE) && defined(SIMDE_ARCH_AMD64)
#  define simde_mm_extract_epi64(a, imm8) _mm_extract_epi64(a, imm8)
#elif defined(SIMDE_SSE4_1_NEON)
#  define simde_mm_extract_epi64(a, imm8) vgetq_lane_s64(simde__m128i_to_private(a).neon_i64, imm8)
#endif
#if defined(SIMDE_SSE4_1_ENABLE_NATIVE_ALIASES)
#  define _mm_extract_epi64(a, imm8) simde_mm_extract_epi64(a, imm8)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128d
simde_mm_floor_pd (simde__m128d a) {
#if defined(SIMDE_SSE4_1_NATIVE)
  return _mm_floor_pd(a);
#else
  simde__m128d_private
    r_,
    a_ = simde__m128d_to_private(a);

#if defined(SIMDE_HAVE_MATH_H)
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.f64) / sizeof(r_.f64[0])) ; i++) {
    r_.f64[i] = floor(a_.f64[i]);
  }
#else
  HEDLEY_UNREACHABLE();
#endif

  return simde__m128d_from_private(r_);
#endif
}
#if defined(SIMDE_SSE4_1_ENABLE_NATIVE_ALIASES)
#  define _mm_floor_pd(a) simde_mm_floor_pd(a)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128
simde_mm_floor_ps (simde__m128 a) {
#if defined(SIMDE_SSE4_1_NATIVE)
  return _mm_floor_ps(a);
#else
  simde__m128_private
    r_,
    a_ = simde__m128_to_private(a);

#if defined(SIMDE_HAVE_MATH_H)
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.f32) / sizeof(r_.f32[0])) ; i++) {
    r_.f32[i] = floorf(a_.f32[i]);
  }
#else
  HEDLEY_UNREACHABLE();
#endif

  return simde__m128_from_private(r_);
#endif
}
#if defined(SIMDE_SSE4_1_ENABLE_NATIVE_ALIASES)
#  define _mm_floor_ps(a) simde_mm_floor_ps(a)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128d
simde_mm_floor_sd (simde__m128d a, simde__m128d b) {
#if defined(SIMDE_SSE4_1_NATIVE)
  return _mm_floor_sd(a, b);
#else
  simde__m128d_private
    r_,
    a_ = simde__m128d_to_private(a),
    b_ = simde__m128d_to_private(b);

#if defined(SIMDE_HAVE_MATH_H)
  r_.f64[0] = floor(b_.f64[0]);
  r_.f64[1] = a_.f64[1];
#else
  HEDLEY_UNREACHABLE();
#endif

  return simde__m128d_from_private(r_);
#endif
}
#if defined(SIMDE_SSE4_1_ENABLE_NATIVE_ALIASES)
#  define _mm_floor_sd(a, b) simde_mm_floor_sd(a, b)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128
simde_mm_floor_ss (simde__m128 a, simde__m128 b) {
#if defined(SIMDE_SSE4_1_NATIVE)
  return _mm_floor_ss(a, b);
#elif defined(SIMDE_ASSUME_VECTORIZATION)
    return simde_mm_move_ss(a, simde_mm_floor_ps(b));
#else
  simde__m128_private
    r_,
    a_ = simde__m128_to_private(a),
    b_ = simde__m128_to_private(b);

  #if defined(SIMDE_HAVE_MATH_H)
    r_.f32[0] = floorf(b_.f32[0]);
    for (size_t i = 1 ; i < (sizeof(r_.f32) / sizeof(r_.f32[0])) ; i++) {
      r_.f32[i] = a_.f32[i];
    }
  #else
    HEDLEY_UNREACHABLE();
  #endif

  return simde__m128_from_private(r_);
#endif
}
#if defined(SIMDE_SSE4_1_ENABLE_NATIVE_ALIASES)
#  define _mm_floor_ss(a, b) simde_mm_floor_ss(a, b)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_insert_epi8 (simde__m128i a, int i, const int imm8)
    HEDLEY_REQUIRE_MSG((imm8 & 0xf) == imm8, "imm8 must be in range [0, 15]")  {
  simde__m128i_private
    r_ = simde__m128i_to_private(a);

  r_.i8[imm8] = HEDLEY_STATIC_CAST(int8_t, i);

  return simde__m128i_from_private(r_);
}
#if defined(SIMDE_SSE4_1_NATIVE)
#  define simde_mm_insert_epi8(a, i, imm8) _mm_insert_epi8(a, i, imm8)
#endif
#if defined(SIMDE_SSE4_1_ENABLE_NATIVE_ALIASES)
#  define _mm_insert_epi8(a, i, imm8) simde_mm_insert_epi8(a, i, imm8)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_insert_epi32 (simde__m128i a, int i, const int imm8)
    HEDLEY_REQUIRE_MSG((imm8 & 3) == imm8, "imm8 must be in range [0, 3]")  {
  simde__m128i_private
    r_ = simde__m128i_to_private(a);

  r_.i32[imm8] = HEDLEY_STATIC_CAST(int32_t, i);

  return simde__m128i_from_private(r_);
}
#if defined(SIMDE_SSE4_1_NATIVE)
#  define simde_mm_insert_epi32(a, i, imm8) _mm_insert_epi32(a, i, imm8)
#endif
#if defined(SIMDE_SSE4_1_ENABLE_NATIVE_ALIASES)
#  define _mm_insert_epi32(a, i, imm8) simde_mm_insert_epi32(a, i, imm8)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_insert_epi64 (simde__m128i a, int64_t i, const int imm8)
    HEDLEY_REQUIRE_MSG((imm8 & 1) == imm8, "imm8 must be 0 or 1")  {
  #if defined(SIMDE_BUG_GCC_94482)
    simde__m128i_private
      a_ = simde__m128i_to_private(a);

    switch(imm8) {
      case 0:
        return simde_mm_set_epi64x(a_.i64[1], i);
        break;
      case 1:
        return simde_mm_set_epi64x(i, a_.i64[0]);
        break;
      default:
        HEDLEY_UNREACHABLE();
        break;
    }
  #else
    simde__m128i_private
      r_ = simde__m128i_to_private(a);

    r_.i64[imm8] = i;

    return simde__m128i_from_private(r_);
  #endif
}
#if defined(SIMDE_SSE4_1_NATIVE) && defined(SIMDE_ARCH_AMD64)
#  define simde_mm_insert_epi64(a, i, imm8) _mm_insert_epi64(a, i, imm8)
#endif
#if defined(SIMDE_SSE4_1_ENABLE_NATIVE_ALIASES)
#  define _mm_insert_epi64(a, i, imm8) simde_mm_insert_epi64(a, i, imm8)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128
simde_mm_insert_ps (simde__m128 a, simde__m128 b, const int imm8)
    HEDLEY_REQUIRE_MSG((imm8 & 0xff) == imm8, "imm8 must be in range [0, 255]")  {
  simde__m128_private
    r_,
    a_ = simde__m128_to_private(a),
    b_ = simde__m128_to_private(b);

  a_.f32[0] = b_.f32[(imm8 >> 6) & 3];
  a_.f32[(imm8 >> 4) & 3] = a_.f32[0];

  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.f32) / sizeof(r_.f32[0])) ; i++) {
    r_.f32[i] = (imm8 >> i) ? SIMDE_FLOAT32_C(0.0) : a_.f32[i];
  }

  return simde__m128_from_private(r_);
}
#if defined(SIMDE_SSE4_1_NATIVE)
#  define simde_mm_insert_ps(a, b, imm8) _mm_insert_ps(a, b, imm8)
#endif
#if defined(SIMDE_SSE4_1_ENABLE_NATIVE_ALIASES)
#  define _mm_insert_ps(a, b, imm8) simde_mm_insert_ps(a, b, imm8)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_max_epi8 (simde__m128i a, simde__m128i b) {
#if defined(SIMDE_SSE4_1_NATIVE) && !defined(__PGI)
  return _mm_max_epi8(a, b);
#else
  simde__m128i_private
    r_,
    a_ = simde__m128i_to_private(a),
    b_ = simde__m128i_to_private(b);

#if defined(SIMDE_SSE4_1_NEON)
  r_.neon_i8 = vmaxq_s8(a_.neon_i8, b_.neon_i8);
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.i8) / sizeof(r_.i8[0])) ; i++) {
    r_.i8[i] = a_.i8[i] > b_.i8[i] ? a_.i8[i] : b_.i8[i];
  }
#endif

  return simde__m128i_from_private(r_);
#endif
}
#if defined(SIMDE_SSE4_1_ENABLE_NATIVE_ALIASES)
#  define _mm_max_epi8(a, b) simde_mm_max_epi8(a, b)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_max_epi32 (simde__m128i a, simde__m128i b) {
#if defined(SIMDE_SSE4_1_NATIVE) && !defined(__PGI)
  return _mm_max_epi32(a, b);
#else
  simde__m128i_private
    r_,
    a_ = simde__m128i_to_private(a),
    b_ = simde__m128i_to_private(b);

#if defined(SIMDE_SSE4_1_NEON)
  r_.neon_i32 = vmaxq_s32(a_.neon_i32, b_.neon_i32);
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.i32) / sizeof(r_.i32[0])) ; i++) {
    r_.i32[i] = a_.i32[i] > b_.i32[i] ? a_.i32[i] : b_.i32[i];
  }
#endif

  return simde__m128i_from_private(r_);
#endif
}
#if defined(SIMDE_SSE4_1_ENABLE_NATIVE_ALIASES)
#  define _mm_max_epi32(a, b) simde_mm_max_epi32(a, b)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_max_epu16 (simde__m128i a, simde__m128i b) {
#if defined(SIMDE_SSE4_1_NATIVE)
  return _mm_max_epu16(a, b);
#else
  simde__m128i_private
    r_,
    a_ = simde__m128i_to_private(a),
    b_ = simde__m128i_to_private(b);

#if defined(SIMDE_SSE4_1_NEON)
  r_.neon_u16 = vmaxq_u16(a_.neon_u16, b_.neon_u16);
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.u16) / sizeof(r_.u16[0])) ; i++) {
    r_.u16[i] = a_.u16[i] > b_.u16[i] ? a_.u16[i] : b_.u16[i];
  }
#endif

  return simde__m128i_from_private(r_);
#endif
}
#if defined(SIMDE_SSE4_1_ENABLE_NATIVE_ALIASES)
#  define _mm_max_epu16(a, b) simde_mm_max_epu16(a, b)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_max_epu32 (simde__m128i a, simde__m128i b) {
#if defined(SIMDE_SSE4_1_NATIVE)
  return _mm_max_epu32(a, b);
#else
  simde__m128i_private
    r_,
    a_ = simde__m128i_to_private(a),
    b_ = simde__m128i_to_private(b);

#if defined(SIMDE_SSE4_1_NEON)
  r_.neon_u32 = vmaxq_u32(a_.neon_u32, b_.neon_u32);
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.u32) / sizeof(r_.u32[0])) ; i++) {
    r_.u32[i] = a_.u32[i] > b_.u32[i] ? a_.u32[i] : b_.u32[i];
  }
#endif

  return simde__m128i_from_private(r_);
#endif
}
#if defined(SIMDE_SSE4_1_ENABLE_NATIVE_ALIASES)
#  define _mm_max_epu32(a, b) simde_mm_max_epu32(a, b)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_min_epi8 (simde__m128i a, simde__m128i b) {
#if defined(SIMDE_SSE4_1_NATIVE) && !defined(__PGI)
  return _mm_min_epi8(a, b);
#else
  simde__m128i_private
    r_,
    a_ = simde__m128i_to_private(a),
    b_ = simde__m128i_to_private(b);

#if defined(SIMDE_SSE4_1_NEON)
  r_.neon_i8 = vminq_s8(a_.neon_i8, b_.neon_i8);
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.i8) / sizeof(r_.i8[0])) ; i++) {
    r_.i8[i] = a_.i8[i] < b_.i8[i] ? a_.i8[i] : b_.i8[i];
  }
#endif

  return simde__m128i_from_private(r_);
#endif
}
#if defined(SIMDE_SSE4_1_ENABLE_NATIVE_ALIASES)
#  define _mm_min_epi8(a, b) simde_mm_min_epi8(a, b)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_min_epi32 (simde__m128i a, simde__m128i b) {
#if defined(SIMDE_SSE4_1_NATIVE) && !defined(__PGI)
  return _mm_min_epi32(a, b);
#else
  simde__m128i_private
    r_,
    a_ = simde__m128i_to_private(a),
    b_ = simde__m128i_to_private(b);

#if defined(SIMDE_SSE4_1_NEON)
  r_.neon_i32 = vminq_s32(a_.neon_i32, b_.neon_i32);
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.i32) / sizeof(r_.i32[0])) ; i++) {
    r_.i32[i] = a_.i32[i] < b_.i32[i] ? a_.i32[i] : b_.i32[i];
  }
#endif

  return simde__m128i_from_private(r_);
#endif
}
#if defined(SIMDE_SSE4_1_ENABLE_NATIVE_ALIASES)
#  define _mm_min_epi32(a, b) simde_mm_min_epi32(a, b)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_min_epu16 (simde__m128i a, simde__m128i b) {
#if defined(SIMDE_SSE4_1_NATIVE)
  return _mm_min_epu16(a, b);
#else
  simde__m128i_private
    r_,
    a_ = simde__m128i_to_private(a),
    b_ = simde__m128i_to_private(b);

#if defined(SIMDE_SSE4_1_NEON)
  r_.neon_u16 = vminq_u16(a_.neon_u16, b_.neon_u16);
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.u16) / sizeof(r_.u16[0])) ; i++) {
    r_.u16[i] = a_.u16[i] < b_.u16[i] ? a_.u16[i] : b_.u16[i];
  }
#endif

  return simde__m128i_from_private(r_);
#endif
}
#if defined(SIMDE_SSE4_1_ENABLE_NATIVE_ALIASES)
#  define _mm_min_epu16(a, b) simde_mm_min_epu16(a, b)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_min_epu32 (simde__m128i a, simde__m128i b) {
#if defined(SIMDE_SSE4_1_NATIVE)
  return _mm_min_epu32(a, b);
#else
  simde__m128i_private
    r_,
    a_ = simde__m128i_to_private(a),
    b_ = simde__m128i_to_private(b);

#if defined(SIMDE_SSE4_1_NEON)
  r_.neon_u32 = vminq_u32(a_.neon_u32, b_.neon_u32);
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.u32) / sizeof(r_.u32[0])) ; i++) {
    r_.u32[i] = a_.u32[i] < b_.u32[i] ? a_.u32[i] : b_.u32[i];
  }
#endif

  return simde__m128i_from_private(r_);
#endif
}
#if defined(SIMDE_SSE4_1_ENABLE_NATIVE_ALIASES)
#  define _mm_min_epu32(a, b) simde_mm_min_epu32(a, b)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_minpos_epu16 (simde__m128i a) {
#if defined(SIMDE_SSE4_1_NATIVE)
  return _mm_minpos_epu16(a);
#else
  simde__m128i_private
    r_ = simde__m128i_to_private(simde_mm_setzero_si128()),
    a_ = simde__m128i_to_private(a);

  r_.u16[0] = UINT16_MAX;
  for (size_t i = 0 ; i < (sizeof(r_.u16) / sizeof(r_.u16[0])) ; i++) {
    if (a_.u16[i] < r_.u16[0]) {
      r_.u16[0] = a_.u16[i];
      r_.u16[1] = HEDLEY_STATIC_CAST(uint16_t, i);
    }
  }

  return simde__m128i_from_private(r_);
#endif
}
#if defined(SIMDE_SSE4_1_ENABLE_NATIVE_ALIASES)
#  define _mm_minpos_epu16(a) simde_mm_minpos_epu16(a)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_mpsadbw_epu8 (simde__m128i a, simde__m128i b, const int imm8)
    HEDLEY_REQUIRE_MSG((imm8 & 7) == imm8, "imm8 must be in range [0, 7]")  {
  simde__m128i_private
    r_,
    a_ = simde__m128i_to_private(a),
    b_ = simde__m128i_to_private(b);

  const int a_offset = imm8 & 4;
  const int b_offset = (imm8 & 3) << 2;

#if defined(SIMDE_HAVE_MATH_H)
  for (int i = 0 ; i < HEDLEY_STATIC_CAST(int, (sizeof(r_.u16) / sizeof(r_.u16[0]))) ; i++) {
    r_.u16[i] =
      HEDLEY_STATIC_CAST(uint16_t, abs(a_.u8[a_offset + i + 0] - b_.u8[b_offset + 0])) +
      HEDLEY_STATIC_CAST(uint16_t, abs(a_.u8[a_offset + i + 1] - b_.u8[b_offset + 1])) +
      HEDLEY_STATIC_CAST(uint16_t, abs(a_.u8[a_offset + i + 2] - b_.u8[b_offset + 2])) +
      HEDLEY_STATIC_CAST(uint16_t, abs(a_.u8[a_offset + i + 3] - b_.u8[b_offset + 3]));
  }
#else
  HEDLEY_UNREACHABLE();
#endif

  return simde__m128i_from_private(r_);
}
#if defined(SIMDE_SSE4_1_NATIVE)
#  define simde_mm_mpsadbw_epu8(a, b, imm8) _mm_mpsadbw_epu8(a, b, imm8)
#endif
#if defined(SIMDE_SSE4_1_ENABLE_NATIVE_ALIASES)
#  define _mm_mpsadbw_epu8(a, b, imm8) simde_mm_mpsadbw_epu8(a, b, imm8)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_mul_epi32 (simde__m128i a, simde__m128i b) {
#if defined(SIMDE_SSE4_1_NATIVE)
  return _mm_mul_epi32(a, b);
#else
  simde__m128i_private
    r_,
    a_ = simde__m128i_to_private(a),
    b_ = simde__m128i_to_private(b);

  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.i64) / sizeof(r_.i64[0])) ; i++) {
    r_.i64[i] =
      HEDLEY_STATIC_CAST(int64_t, a_.i32[i * 2]) *
      HEDLEY_STATIC_CAST(int64_t, b_.i32[i * 2]);
  }

  return simde__m128i_from_private(r_);
#endif
}
#if defined(SIMDE_SSE4_1_ENABLE_NATIVE_ALIASES)
#  define _mm_mul_epi32(a, b) simde_mm_mul_epi32(a, b)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_mullo_epi32 (simde__m128i a, simde__m128i b) {
#if defined(SIMDE_SSE4_1_NATIVE)
  return _mm_mullo_epi32(a, b);
#else
  simde__m128i_private
    r_,
    a_ = simde__m128i_to_private(a),
    b_ = simde__m128i_to_private(b);

#if defined(SIMDE_SSE4_1_NEON)
  r_.neon_i32 = vmulq_s32(a_.neon_i32, b_.neon_i32);
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.i32) / sizeof(r_.i32[0])) ; i++) {
    r_.u32[i] = HEDLEY_STATIC_CAST(uint32_t, (HEDLEY_STATIC_CAST(uint64_t, (HEDLEY_STATIC_CAST(int64_t, a_.i32[i]) * HEDLEY_STATIC_CAST(int64_t, b_.i32[i]))) & 0xffffffff));
  }
#endif

  return simde__m128i_from_private(r_);
#endif
}
#if defined(SIMDE_SSE4_1_ENABLE_NATIVE_ALIASES)
#  define _mm_mullo_epi32(a, b) simde_mm_mullo_epi32(a, b)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_packus_epi32 (simde__m128i a, simde__m128i b) {
#if defined(SIMDE_SSE4_1_NATIVE)
  return _mm_packus_epi32(a, b);
#else
  simde__m128i_private
    r_,
    a_ = simde__m128i_to_private(a),
    b_ = simde__m128i_to_private(b);

  for (size_t i = 0 ; i < (sizeof(r_.i32) / sizeof(r_.i32[0])) ; i++) {
    r_.u16[i + 0] = (a_.i32[i] < 0) ? UINT16_C(0) : ((a_.i32[i] > UINT16_MAX) ? (UINT16_MAX) : HEDLEY_STATIC_CAST(uint16_t, a_.i32[i]));
    r_.u16[i + 4] = (b_.i32[i] < 0) ? UINT16_C(0) : ((b_.i32[i] > UINT16_MAX) ? (UINT16_MAX) : HEDLEY_STATIC_CAST(uint16_t, b_.i32[i]));
  }
  return simde__m128i_from_private(r_);
#endif
}
#if defined(SIMDE_SSE4_1_ENABLE_NATIVE_ALIASES)
#  define _mm_packus_epi32(a, b) simde_mm_packus_epi32(a, b)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128d
simde_mm_round_pd (simde__m128d a, int rounding) {
  simde__m128d_private
    r_,
    a_ = simde__m128d_to_private(a);

#if defined(SIMDE_HAVE_MATH_H)
  for (size_t i = 0 ; i < (sizeof(r_.f64) / sizeof(r_.f64[0])) ; i++) {
    switch (rounding & ~SIMDE_MM_FROUND_NO_EXC) {
      case SIMDE_MM_FROUND_TO_NEAREST_INT:
        r_.f64[i] = nearbyint(a_.f64[i]);
        break;
      case SIMDE_MM_FROUND_TO_NEG_INF:
        r_.f64[i] = floor(a_.f64[i]);
        break;
      case SIMDE_MM_FROUND_TO_POS_INF:
        r_.f64[i] = ceil(a_.f64[i]);
        break;
      case SIMDE_MM_FROUND_TO_ZERO:
        r_.f64[i] = trunc(a_.f64[i]);
        break;
      case SIMDE_MM_FROUND_CUR_DIRECTION:
        r_.f64[i] = nearbyint(a_.f64[i]);
        break;
      default:
        HEDLEY_UNREACHABLE();
        break;
    }
  }
#else
  HEDLEY_UNREACHABLE();
#endif

  return simde__m128d_from_private(r_);
}
#if defined(SIMDE_SSE4_1_NATIVE)
#  define simde_mm_round_pd(a, rounding) _mm_round_pd(a, rounding)
#endif
#if defined(SIMDE_SSE4_1_ENABLE_NATIVE_ALIASES)
#  define _mm_round_pd(a, rounding) simde_mm_round_pd(a, rounding)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128
simde_mm_round_ps (simde__m128 a, int rounding) {
  simde__m128_private
    r_,
    a_ = simde__m128_to_private(a);

#if defined(SIMDE_HAVE_MATH_H)
  for (size_t i = 0 ; i < (sizeof(r_.f32) / sizeof(r_.f32[0])) ; i++) {
    switch (rounding & ~SIMDE_MM_FROUND_NO_EXC) {
      case SIMDE_MM_FROUND_TO_NEAREST_INT:
        r_.f32[i] = nearbyintf(a_.f32[i]);
        break;
      case SIMDE_MM_FROUND_TO_NEG_INF:
        r_.f32[i] = floorf(a_.f32[i]);
        break;
      case SIMDE_MM_FROUND_TO_POS_INF:
        r_.f32[i] = ceilf(a_.f32[i]);
        break;
      case SIMDE_MM_FROUND_TO_ZERO:
        r_.f32[i] = truncf(a_.f32[i]);
        break;
      case SIMDE_MM_FROUND_CUR_DIRECTION:
        r_.f32[i] = nearbyintf (a_.f32[i]);
        break;
      default:
        HEDLEY_UNREACHABLE();
        break;
    }
  }
#else
  HEDLEY_UNREACHABLE();
#endif

  return simde__m128_from_private(r_);
}
#if defined(SIMDE_SSE4_1_NATIVE)
#  define simde_mm_round_ps(a, rounding) _mm_round_ps(a, rounding)
#endif
#if defined(SIMDE_SSE4_1_ENABLE_NATIVE_ALIASES)
#  define _mm_round_ps(a, rounding) simde_mm_round_ps(a, rounding)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128d
simde_mm_round_sd (simde__m128d a, simde__m128d b, int rounding) {
  simde__m128d_private
    r_ = simde__m128d_to_private(a),
    b_ = simde__m128d_to_private(b);

#if defined(SIMDE_HAVE_MATH_H)
  switch (rounding & ~SIMDE_MM_FROUND_NO_EXC) {
    case SIMDE_MM_FROUND_TO_NEAREST_INT:
      r_.f64[0] = nearbyint(b_.f64[0]);
      break;
    case SIMDE_MM_FROUND_TO_NEG_INF:
      r_.f64[0] = floor(b_.f64[0]);
      break;
    case SIMDE_MM_FROUND_TO_POS_INF:
      r_.f64[0] = ceil(b_.f64[0]);
      break;
    case SIMDE_MM_FROUND_TO_ZERO:
      r_.f64[0] = trunc(b_.f64[0]);
      break;
    case SIMDE_MM_FROUND_CUR_DIRECTION:
      r_.f64[0] = nearbyint(b_.f64[0]);
      break;
    default:
      HEDLEY_UNREACHABLE();
      break;
  }
#else
  HEDLEY_UNREACHABLE();
#endif

  return simde__m128d_from_private(r_);
}
#if defined(SIMDE_SSE4_1_NATIVE)
#  define simde_mm_round_sd(a, b, rounding) _mm_round_sd(a, b, rounding)
#endif
#if defined(SIMDE_SSE4_1_ENABLE_NATIVE_ALIASES)
#  define _mm_round_sd(a, b, rounding) simde_mm_round_sd(a, b, rounding)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128
simde_mm_round_ss (simde__m128 a, simde__m128 b, int rounding) {
  simde__m128_private
    r_ = simde__m128_to_private(a),
    b_ = simde__m128_to_private(b);

  #if defined(SIMDE_HAVE_MATH_H)
    switch (rounding & ~SIMDE_MM_FROUND_NO_EXC) {
      case SIMDE_MM_FROUND_TO_NEAREST_INT:
        r_.f32[0] = nearbyintf(b_.f32[0]);
        break;
      case SIMDE_MM_FROUND_TO_NEG_INF:
        r_.f32[0] = floorf(b_.f32[0]);
        break;
      case SIMDE_MM_FROUND_TO_POS_INF:
        r_.f32[0] = ceilf(b_.f32[0]);
        break;
      case SIMDE_MM_FROUND_TO_ZERO:
        r_.f32[0] = truncf(b_.f32[0]);
        break;
      case SIMDE_MM_FROUND_CUR_DIRECTION:
        r_.f32[0] = nearbyintf (b_.f32[0]);
        break;
      default:
        HEDLEY_UNREACHABLE();
        break;
    }
  #else
    HEDLEY_UNREACHABLE();
  #endif

  return simde__m128_from_private(r_);
}
#if defined(SIMDE_SSE4_1_NATIVE)
#  define simde_mm_round_ss(a, b, rounding) _mm_round_ss(a, b, rounding)
#endif
#if defined(SIMDE_SSE4_1_ENABLE_NATIVE_ALIASES)
#  define _mm_round_ss(a, b, rounding) simde_mm_round_ss(a, b, rounding)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_stream_load_si128 (const simde__m128i* mem_addr) {
#if defined(SIMDE_SSE4_1_NATIVE)
  return _mm_stream_load_si128(HEDLEY_CONST_CAST(simde__m128i*, mem_addr));
#else
  return *mem_addr;
#endif
}
#if defined(SIMDE_SSE4_1_ENABLE_NATIVE_ALIASES)
#  define _mm_stream_load_si128(mem_addr) simde_mm_stream_load_si128(mem_addr)
#endif

SIMDE__FUNCTION_ATTRIBUTES
int
simde_mm_test_all_ones (simde__m128i a) {
#if defined(SIMDE_SSE4_1_NATIVE)
  return _mm_test_all_ones(a);
#else
  simde__m128i_private a_ = simde__m128i_to_private(a);

  for (size_t i = 0 ; i < (sizeof(a_.u64) / sizeof(a_.u64[0])) ; i++) {
    if (a_.u64[i] != ~UINT64_C(0))
      return 0;
  }

  return 1;
#endif
}
#if defined(SIMDE_SSE4_1_ENABLE_NATIVE_ALIASES)
#  define _mm_test_all_ones(a) simde_mm_test_all_ones(a)
#endif

SIMDE__FUNCTION_ATTRIBUTES
int
simde_mm_test_all_zeros (simde__m128i a, simde__m128i mask) {
#if defined(SIMDE_SSE4_1_NATIVE)
  return _mm_test_all_zeros(a, mask);
#else
  simde__m128i_private
    a_ = simde__m128i_to_private(a),
    mask_ = simde__m128i_to_private(mask);

  for (size_t i = 0 ; i < (sizeof(a_.u64) / sizeof(a_.u64[0])) ; i++) {
    if ((a_.u64[i] & mask_.u64[i]) != 0)
      return 0;
  }

  return 1;
#endif
}
#if defined(SIMDE_SSE4_1_ENABLE_NATIVE_ALIASES)
#  define _mm_test_all_zeros(a, mask) simde_mm_test_all_zeros(a, mask)
#endif

SIMDE__FUNCTION_ATTRIBUTES
int
simde_mm_test_mix_ones_zeros (simde__m128i a, simde__m128i mask) {
#if defined(SIMDE_SSE4_1_NATIVE)
  return _mm_test_mix_ones_zeros(a, mask);
#else
  simde__m128i_private
    a_ = simde__m128i_to_private(a),
    mask_ = simde__m128i_to_private(mask);

  for (size_t i = 0 ; i < (sizeof(a_.u64) / sizeof(a_.u64[0])) ; i++)
    if (((a_.u64[i] & mask_.u64[i]) != 0) && ((~a_.u64[i] & mask_.u64[i]) != 0))
      return 1;

  return 0;
#endif
}
#if defined(SIMDE_SSE4_1_ENABLE_NATIVE_ALIASES)
#  define _mm_test_mix_ones_zeros(a, mask) simde_mm_test_mix_ones_zeros(a, mask)
#endif

SIMDE__FUNCTION_ATTRIBUTES
int
simde_mm_testc_si128 (simde__m128i a, simde__m128i b) {
#if defined(SIMDE_SSE4_1_NATIVE)
  return _mm_testc_si128(a, b);
#else
  simde__m128i_private
    a_ = simde__m128i_to_private(a),
    b_ = simde__m128i_to_private(b);

  int_fast32_t r = 0;

  SIMDE__VECTORIZE_REDUCTION(|:r)
  for (size_t i = 0 ; i < (sizeof(a_.i32f) / sizeof(a_.i32f[0])) ; i++) {
    r |= ~a_.i32f[i] & b_.i32f[i];
  }

  return HEDLEY_STATIC_CAST(int, !r);
#endif
}
#if defined(SIMDE_SSE4_1_ENABLE_NATIVE_ALIASES)
#  define _mm_testc_si128(a, b) simde_mm_testc_si128(a, b)
#endif

SIMDE__FUNCTION_ATTRIBUTES
int
simde_mm_testnzc_si128 (simde__m128i a, simde__m128i b) {
#if defined(SIMDE_SSE4_1_NATIVE)
  return _mm_testnzc_si128(a, b);
#else
  simde__m128i_private
    a_ = simde__m128i_to_private(a),
    b_ = simde__m128i_to_private(b);

  for (size_t i = 0 ; i < (sizeof(a_.u64) / sizeof(a_.u64[0])) ; i++) {
    if (((a_.u64[i] & b_.u64[i]) != 0) && ((~a_.u64[i] & b_.u64[i]) != 0))
      return 1;
  }

  return 0;
#endif
}
#if defined(SIMDE_SSE4_1_ENABLE_NATIVE_ALIASES)
#  define _mm_testnzc_si128(a, b) simde_mm_testnzc_si128(a, b)
#endif

SIMDE__FUNCTION_ATTRIBUTES
int
simde_mm_testz_si128 (simde__m128i a, simde__m128i b) {
#if defined(SIMDE_SSE4_1_NATIVE)
  return _mm_testz_si128(a, b);
#else
  simde__m128i_private
    a_ = simde__m128i_to_private(a),
    b_ = simde__m128i_to_private(b);

  for (size_t i = 0 ; i < (sizeof(a_.u64) / sizeof(a_.u64[0])) ; i++) {
    if ((a_.u64[i] & b_.u64[i]) == 0)
      return 1;
  }

  return 0;
#endif
}
#if defined(SIMDE_SSE4_1_ENABLE_NATIVE_ALIASES)
#  define _mm_testz_si128(a, b) simde_mm_testz_si128(a, b)
#endif

SIMDE__END_DECLS

HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE__SSE4_1_H) */
