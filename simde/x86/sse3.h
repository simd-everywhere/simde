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
#  if defined(SIMDE_SSE3_FORCE_NATIVE)
#    define SIMDE_SSE3_NATIVE
#  elif defined(__SSE3__) && (!defined(SIMDE_SSE3_NO_NATIVE) && !defined(SIMDE_NO_NATIVE))
#    define SIMDE_SSE3_NATIVE
#  elif defined(__ARM_NEON) && !defined(SIMDE_SSE3_NO_NEON) && !defined(SIMDE_NO_NEON)
#    define SIMDE_SSE3_NEON
#  endif

#  if defined(SIMDE_SSE3_NATIVE) && !defined(SIMDE_SSE2_NATIVE)
#    if defined(SIMDE_SSE3_FORCE_NATIVE)
#      error Native SSE3 support requires native SSE2 support
#    else
#      warning Native SSE3 support requires native SSE2 support, disabling
#      undef SIMDE_SSE3_NATIVE
#    endif
#  elif defined(SIMDE_SSE3_NEON) && !defined(SIMDE_SSE2_NEON)
#    warning SSE3 NEON support requires SSE2 NEON support, disabling
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

  for (size_t i = 0 ; i < (sizeof(r_.f64) / sizeof(r_.f64[0])) ; i += 2) {
    r_.f64[    i] = a_.f64[    i] - b_.f64[    i];
    r_.f64[1 + i] = a_.f64[1 + i] + b_.f64[1 + i];
  }

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
  return simde_mm_add_ps(a, simde_mm_mul_ps(simde_mm_set_ps( 1.0f, -1.0f,  1.0f, -1.0f), b));
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
  r_.f64[0] = a_.f64[0] + a_.f64[1];
  r_.f64[1] = b_.f64[0] + b_.f64[1];
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

#if defined(SIMDE_SSE3_NEON)
  #if defined(SIMDE_ARCH_AARCH64)
    r_.f32 = vpaddq_f32(a_.neon_f32, b_.neon_f32);
  #else
    float32x2_t a10 = vget_low_f32(a_.neon_f32);
    float32x2_t a32 = vget_high_f32(a_.neon_f32);
    float32x2_t b10 = vget_low_f32(b_.neon_f32);
    float32x2_t b32 = vget_high_f32(b_.neon_f32);
    r_.f32 = vcombine_f32(vpadd_f32(a10, a32), vpadd_f32(b10, b32));
  #endif
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

  r_.f64[0] = a_.f64[0] - a_.f64[1];
  r_.f64[1] = b_.f64[0] - b_.f64[1];

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

#if defined(SIMDE_SSE3_NEON)
  const float32_t mp[] = { 1.0f, -1.0f, 1.0f, -1.0f };
  const float32x4_t m = vld1q_f32(mp);

  float32x4_t ap = vmulq_f32(a_.neon_f32, m);
  float32x4_t bp = vmulq_f32(b_.neon_f32, m);
  float32x2_t ax = vpadd_f32(vget_low_f32(ap), vget_high_f32(ap));
  float32x2_t bx = vpadd_f32(vget_low_f32(bp), vget_high_f32(bp));

  r_.neon_f32 = vcombine_f32(ax, bx);
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
  memcpy(&r_, mem_addr, sizeof(r_));
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

  r_.f64[0] = a_.f64[0];
  r_.f64[1] = a_.f64[0];

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

  r_.f32[0] = a_.f32[1];
  r_.f32[1] = a_.f32[1];
  r_.f32[2] = a_.f32[3];
  r_.f32[3] = a_.f32[3];

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

  r_.f32[0] = a_.f32[0];
  r_.f32[1] = a_.f32[0];
  r_.f32[2] = a_.f32[2];
  r_.f32[3] = a_.f32[2];

  return simde__m128_from_private(r_);
#endif
}
#if defined(SIMDE_SSE3_ENABLE_NATIVE_ALIASES)
#  define _mm_moveldup_ps(a) simde_mm_moveldup_ps(a)
#endif

SIMDE__END_DECLS

HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE__SSE3_H) */
