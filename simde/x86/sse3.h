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
 */

#if !defined(SIMDE__SSE3_H)
#  if !defined(SIMDE__SSE3_H)
#    define SIMDE__SSE3_H
#  endif
#  include "sse2.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS

#  if defined(SIMDE_SSE3_NATIVE)
#    undef SIMDE_SSE3_NATIVE
#  endif
#  if defined(SIMDE_ARCH_X86_SSE3) && !defined(SIMDE_SSE3_NO_NATIVE) && !defined(SIMDE_NO_NATIVE)
#    define SIMDE_SSE3_NATIVE
#  elif defined(SIMDE_ARCH_ARM_NEON) && !defined(SIMDE_SSE3_NO_NEON) && !defined(SIMDE_NO_NEON)
#    define SIMDE_SSE3_NEON
#  endif

#  if defined(SIMDE_SSE3_NATIVE) && !defined(SIMDE_SSE2_NATIVE)
#    if defined(SIMDE_SSE3_FORCE_NATIVE)
#      error Native SSE3 support requires native SSE2 support
#    else
       HEDLEY_WARNING("Native SSE3 support requires native SSE2 support, disabling")
#      undef SIMDE_SSE3_NATIVE
#    endif
#  elif defined(SIMDE_SSE3_NEON) && !defined(SIMDE_SSE2_NEON)
     HEDLEY_WARNING("SSE3 NEON support requires SSE2 NEON support, disabling")
#    undef SIMDE_SSE3_NEON
#  endif

#  if defined(SIMDE_SSE3_NATIVE)
#    include <pmmintrin.h>
#  endif

#if !defined(SIMDE_SSE3_NATIVE) && defined(SIMDE_ENABLE_NATIVE_ALIASES)
#  define SIMDE_SSE3_ENABLE_NATIVE_ALIASES
#endif

SIMDE__BEGIN_DECLS

SIMDE__FUNCTION_ATTRIBUTES
simde__m128d
simde_mm_addsub_pd (simde__m128d a, simde__m128d b) {
#if defined(SIMDE_SSE3_NATIVE)
  return _mm_addsub_pd(a, b);
#else
  simde__m128d_private
    r_,
    a_ = simde__m128d_to_private(a),
    b_ = simde__m128d_to_private(b);

  #if defined(SIMDE_ASSUME_VECTORIZATION) && defined(SIMDE__SHUFFLE_VECTOR)
    r_.f64 = SIMDE__SHUFFLE_VECTOR(64, 16, a_.f64 - b_.f64, a_.f64 + b_.f64, 0, 3);
  #else
    for (size_t i = 0 ; i < (sizeof(r_.f64) / sizeof(r_.f64[0])) ; i += 2) {
      r_.f64[  i  ] = a_.f64[  i  ] - b_.f64[  i  ];
      r_.f64[1 + i] = a_.f64[1 + i] + b_.f64[1 + i];
    }
  #endif

  return simde__m128d_from_private(r_);
#endif
}
#if defined(SIMDE_SSE3_ENABLE_NATIVE_ALIASES)
#  define _mm_addsub_pd(a, b) simde_mm_addsub_pd(a, b)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128
simde_mm_addsub_ps (simde__m128 a, simde__m128 b) {
#if defined(SIMDE_SSE3_NATIVE)
  return _mm_addsub_ps(a, b);
#else
  simde__m128_private
    r_,
    a_ = simde__m128_to_private(a),
    b_ = simde__m128_to_private(b);

  #if defined(SIMDE_SSE3_NEON) && defined(SIMDE_ARCH_AARCH64)
    float32x4_t rs = vsubq_f32(a_.neon_f32, b_.neon_f32);
    float32x4_t ra = vaddq_f32(a_.neon_f32, b_.neon_f32);
    return vtrn2q_f32(vreinterpretq_f32_s32(vrev64q_s32(vreinterpretq_s32_f32(rs))), ra);
  #elif defined(SIMDE_ASSUME_VECTORIZATION) && defined(SIMDE__SHUFFLE_VECTOR)
    r_.f32 = SIMDE__SHUFFLE_VECTOR(32, 16, a_.f32 - b_.f32, a_.f32 + b_.f32, 0, 5, 2, 7);
  #else
    for (size_t i = 0 ; i < (sizeof(r_.f32) / sizeof(r_.f32[0])) ; i += 2) {
      r_.f32[  i  ] = a_.f32[  i  ] - b_.f32[  i  ];
      r_.f32[1 + i] = a_.f32[1 + i] + b_.f32[1 + i];
    }
  #endif

  return simde__m128_from_private(r_);
#endif
}
#if defined(SIMDE_SSE3_ENABLE_NATIVE_ALIASES)
#  define _mm_addsub_ps(a, b) simde_mm_addsub_ps(a, b)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128d
simde_mm_hadd_pd (simde__m128d a, simde__m128d b) {
#if defined(SIMDE_SSE3_NATIVE)
  return _mm_hadd_pd(a, b);
#else
  simde__m128d_private
    r_,
    a_ = simde__m128d_to_private(a),
    b_ = simde__m128d_to_private(b);

  #if defined(SIMDE_SSE3_NEON) && defined(SIMDE_ARCH_AARCH64)
    simde_float64 res[2] = { vaddvq_f64(a_.neon_f64), vaddvq_f64(b_.neon_f64)};
    r_.neon_f64 = vld1q_f64(res);
  #elif defined(SIMDE_ASSUME_VECTORIZATION) && defined(SIMDE__SHUFFLE_VECTOR)
    r_.f64 =
      SIMDE__SHUFFLE_VECTOR(64, 16, a_.f64, b_.f64, 0, 2) +
      SIMDE__SHUFFLE_VECTOR(64, 16, a_.f64, b_.f64, 1, 3);
  #else
    r_.f64[0] = a_.f64[0] + a_.f64[1];
    r_.f64[1] = b_.f64[0] + b_.f64[1];
  #endif

  return simde__m128d_from_private(r_);
#endif
}
#if defined(SIMDE_SSE3_ENABLE_NATIVE_ALIASES)
#  define _mm_hadd_pd(a, b) simde_mm_hadd_pd(a, b)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128
simde_mm_hadd_ps (simde__m128 a, simde__m128 b) {
#if defined(SIMDE_SSE3_NATIVE)
  return _mm_hadd_ps(a, b);
#else
  simde__m128_private
    r_,
    a_ = simde__m128_to_private(a),
    b_ = simde__m128_to_private(b);

#if defined(SIMDE_SSE3_NEON) && defined(SIMDE_ARCH_AARCH64)
  r_.f32 = vpaddq_f32(a_.neon_f32, b_.neon_f32);
#elif defined(SIMDE_ASSUME_VECTORIZATION) && defined(SIMDE__SHUFFLE_VECTOR)
  r_.f32 =
    SIMDE__SHUFFLE_VECTOR(32, 16, a_.f32, b_.f32, 0, 2, 4, 6) +
    SIMDE__SHUFFLE_VECTOR(32, 16, a_.f32, b_.f32, 1, 3, 5, 7);
#else
  r_.f32[0] = a_.f32[0] + a_.f32[1];
  r_.f32[1] = a_.f32[2] + a_.f32[3];
  r_.f32[2] = b_.f32[0] + b_.f32[1];
  r_.f32[3] = b_.f32[2] + b_.f32[3];
#endif

  return simde__m128_from_private(r_);
#endif
}
#if defined(SIMDE_SSE3_ENABLE_NATIVE_ALIASES)
#  define _mm_hadd_ps(a, b) simde_mm_hadd_ps(a, b)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128d
simde_mm_hsub_pd (simde__m128d a, simde__m128d b) {
#if defined(SIMDE_SSE3_NATIVE)
  return _mm_hsub_pd(a, b);
#else
  simde__m128d_private
    r_,
    a_ = simde__m128d_to_private(a),
    b_ = simde__m128d_to_private(b);

  #if defined(SIMDE_ASSUME_VECTORIZATION) && defined(SIMDE__SHUFFLE_VECTOR)
    r_.f64 =
      SIMDE__SHUFFLE_VECTOR(64, 16, a_.f64, b_.f64, 0, 2) -
      SIMDE__SHUFFLE_VECTOR(64, 16, a_.f64, b_.f64, 1, 3);
  #else
    r_.f64[0] = a_.f64[0] - a_.f64[1];
    r_.f64[1] = b_.f64[0] - b_.f64[1];
  #endif

  return simde__m128d_from_private(r_);
#endif
}
#if defined(SIMDE_SSE3_ENABLE_NATIVE_ALIASES)
#  define _mm_hsub_pd(a, b) simde_mm_hsub_pd(a, b)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128
simde_mm_hsub_ps (simde__m128 a, simde__m128 b) {
#if defined(SIMDE_SSE3_NATIVE)
  return _mm_hsub_ps(a, b);
#else
  simde__m128_private
    r_,
    a_ = simde__m128_to_private(a),
    b_ = simde__m128_to_private(b);

#if defined(SIMDE_SSE3_NEON) && defined(SIMDE_ARCH_AARCH64)
  r_.f32 = vsubq_f32(vuzp1q_f32(a_.neon_f32, b_.neon_f32), vuzp2q_f32(a_.neon_f32, b_.neon_f32));
#elif defined(SIMDE_ASSUME_VECTORIZATION) && defined(SIMDE__SHUFFLE_VECTOR)
  r_.f32 =
    SIMDE__SHUFFLE_VECTOR(32, 16, a_.f32, b_.f32, 0, 2, 4, 6) -
    SIMDE__SHUFFLE_VECTOR(32, 16, a_.f32, b_.f32, 1, 3, 5, 7);
#else
  r_.f32[0] = a_.f32[0] - a_.f32[1];
  r_.f32[1] = a_.f32[2] - a_.f32[3];
  r_.f32[2] = b_.f32[0] - b_.f32[1];
  r_.f32[3] = b_.f32[2] - b_.f32[3];
#endif

  return simde__m128_from_private(r_);
#endif
}
#if defined(SIMDE_SSE3_ENABLE_NATIVE_ALIASES)
#  define _mm_hsub_ps(a, b) simde_mm_hsub_ps(a, b)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_lddqu_si128 (simde__m128i const* mem_addr) {
#if defined(SIMDE_SSE3_NATIVE)
  return _mm_lddqu_si128(mem_addr);
#else
  simde__m128i_private r_;

#if defined(SIMDE_SSE3_NEON)
  r_.neon_i32 = vld1q_s32(HEDLEY_REINTERPRET_CAST(int32_t const*, mem_addr));
#else
  simde_memcpy(&r_, mem_addr, sizeof(r_));
#endif

  return simde__m128i_from_private(r_);
#endif
}
#if defined(SIMDE_SSE3_ENABLE_NATIVE_ALIASES)
#  define _mm_lddqu_si128(mem_addr) simde_mm_lddqu_si128(mem_addr)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128d
simde_mm_movedup_pd (simde__m128d a) {
#if defined(SIMDE_SSE3_NATIVE)
  return _mm_movedup_pd(a);
#else
  simde__m128d_private
    r_,
    a_ = simde__m128d_to_private(a);

  #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS) && defined(SIMDE__SHUFFLE_VECTOR)
    r_.f64 = SIMDE__SHUFFLE_VECTOR(64, 16, a_.f64, a_.f64, 0, 0);
  #else
    r_.f64[0] = a_.f64[0];
    r_.f64[1] = a_.f64[0];
  #endif

  return simde__m128d_from_private(r_);
#endif
}
#if defined(SIMDE_SSE3_ENABLE_NATIVE_ALIASES)
#  define _mm_movedup_pd(a) simde_mm_movedup_pd(a)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128
simde_mm_movehdup_ps (simde__m128 a) {
#if defined(SIMDE_SSE3_NATIVE)
  return _mm_movehdup_ps(a);
#else
  simde__m128_private
    r_,
    a_ = simde__m128_to_private(a);

  #if defined(SIMDE_ASSUME_VECTORIZATION) && defined(SIMDE__SHUFFLE_VECTOR)
    r_.f32 = SIMDE__SHUFFLE_VECTOR(32, 16, a_.f32, a_.f32, 1, 1, 3, 3);
  #else
    r_.f32[0] = a_.f32[1];
    r_.f32[1] = a_.f32[1];
    r_.f32[2] = a_.f32[3];
    r_.f32[3] = a_.f32[3];
  #endif

  return simde__m128_from_private(r_);
#endif
}
#if defined(SIMDE_SSE3_ENABLE_NATIVE_ALIASES)
#  define _mm_movehdup_ps(a) simde_mm_movehdup_ps(a)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128
simde_mm_moveldup_ps (simde__m128 a) {
#if defined(SIMDE__SSE3_NATIVE)
  return _mm_moveldup_ps(a);
#else
  simde__m128_private
    r_,
    a_ = simde__m128_to_private(a);

  #if defined(SIMDE_ASSUME_VECTORIZATION) && defined(SIMDE__SHUFFLE_VECTOR)
    r_.f32 = SIMDE__SHUFFLE_VECTOR(32, 16, a_.f32, a_.f32, 0, 0, 2, 2);
  #else
    r_.f32[0] = a_.f32[0];
    r_.f32[1] = a_.f32[0];
    r_.f32[2] = a_.f32[2];
    r_.f32[3] = a_.f32[2];
  #endif

  return simde__m128_from_private(r_);
#endif
}
#if defined(SIMDE_SSE3_ENABLE_NATIVE_ALIASES)
#  define _mm_moveldup_ps(a) simde_mm_moveldup_ps(a)
#endif

SIMDE__END_DECLS

HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE__SSE3_H) */
