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
 *   2017      Evan Nemerson <evan@nemerson.com>
 */

#if !defined(SIMDE__EM_H)
#  if !defined(SIMDE__EM_H)
#    define SIMDE__EM_H
#  endif
#  include "../simde-common.h"

#  if defined(SIMDE_EM_NATIVE)
#    undef SIMDE_EM_NATIVE
#  endif
#  if defined(SIMDE_EM_FORCE_NATIVE)
#    define SIMDE_EM_NATIVE
#  elif defined(__EMSCRIPTEN__) && !defined(SIMDE_EM_NO_NATIVE) && !defined(SIMDE_NO_NATIVE)
#    define SIMDE_EM_NATIVE
#  elif defined(__SSE2__) && !defined(SIMDE_EM_NO_SSE2) && !defined(SIMDE_NO_SSE2)
#    define SIMDE_EM_SSE2
#  elif defined(__ARM_NEON) && !defined(SIMDE_EM_NO_NEON) && !defined(SIMDE_NO_NEON)
#    define SIMDE_EM_NEON
#  endif

#  if defined(SIMDE_EM_NATIVE)
#    include <emscripten/vector.h>
#  elif defined(SIMDE_EM_SSE2)
#    if defined(__SSE4_1__)
#      include <smmintrin.h>
#    else
#      include <emmintrin.h>
#    endif
#  elif defined(SIMDE_EM_NEON)
#    include <arm_neon.h>
#  endif

SIMDE__BEGIN_DECLS

typedef SIMDE__ALIGN(16) union {
#if defined(SIMDE__ENABLE_GCC_VEC_EXT)
  int32_t       v __attribute__((__vector_size__(16), __may_alias__));
#else
  int32_t       v[4];
#endif

#if defined(SIMDE_EM_NATIVE)
  int32x4       n;
#elif defined(SIMDE_EM_SSE2)
  __m128i       sse2;
#elif defined(SIMDE_EM_NEON)
  int32x4_t     neon;
#endif
} simde_em_int32x4;

typedef SIMDE__ALIGN(16) union {
#if defined(SIMDE__ENABLE_GCC_VEC_EXT)
  int32_t       v __attribute__((__vector_size__(16), __may_alias__));
#else
  int32_t       v[4];
#endif

#if defined(SIMDE_EM_NATIVE)
  bool32x4      n;
#elif defined(SIMDE_EM_SSE2)
  __m128i       sse2;
#elif defined(SIMDE_EM_NEON)
  int32x4_t     neon;
#endif
} simde_em_bool32x4;

#if defined(SIMDE_EM_NATIVE)
  HEDLEY_STATIC_ASSERT(sizeof(int32x4_t) == sizeof(simde_em_int32x4), "int32x4_t size doesn't match simde__m128 size");
  #define SIMDE_EM_INT32X4_C(expr) ((simde_em_int32x4) { .n = (expr) })
  #define SIMDE_EM_BOOL32X4_C(expr) ((simde_em_bool32x4) { .n = (expr) })
#elif defined(SIMDE_EM_SSE2)
  #define SIMDE_EM_INT32X4_SSE2_C(expr) ((simde_em_int32x4) { .sse2 = (expr) })
  #define SIMDE_EM_BOOL32X4_SSE2_C(expr) ((simde_em_bool32x4) { .sse2 = (expr) })
#elif defined(SIMDE_EM_NEON)
  #define SIMDE_EM_INT32X4_NEON_C(expr) ((simde_em_int32x4) { .neon = (expr) })
  #define SIMDE_EM_BOOL32X4_NEON_C(expr) ((simde_em_bool32x4) { .neon = (expr) })
  #define SIMDE_EM_BOOL32X4_NEON_UC(expr) ((simde_em_bool32x4) { .neon = vreinterpretq_s32_u32(expr) })
#endif
HEDLEY_STATIC_ASSERT(16 == sizeof(simde_em_int32x4), "simde_em_int32x4 size incorrect");
HEDLEY_STATIC_ASSERT(16 == sizeof(simde_em_bool32x4), "simde_em_bool32x4 size incorrect");

SIMDE__FUNCTION_ATTRIBUTES
simde_em_int32x4
simde_em_int32x4_set (int32_t s0, int32_t s1, int32_t s2, int32_t s3) {
#if defined(SIMDE_EM_NATIVE)
  return SIMDE_EM_INT32X4_C(emscripten_int32x4_set(s0, s1, s2, s3));
#elif defined(SIMDE_EM_SSE2)
  return SIMDE_EM_INT32X4_SSE2_C(_mm_set_epi32(s3, s2, s1, s0));
#elif defined(SIMDE_EM_NEON)
  SIMDE__ALIGN(16) int32_t data[4] = { s0, s1, s2, s3 };
  return SIMDE_EM_INT32X4_NEON_C(vld1q_s32(data));
#else
  return (simde_em_int32x4) {
    .v = { s0, s1, s2, s3 }
  };
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde_em_int32x4
simde_em_int32x4_splat (int32_t s) {
#if defined(SIMDE_EM_NATIVE)
  return SIMDE_EM_INT32X4_C(emscripten_int32x4_splat(s));
#elif defined(SIMDE_EM_SSE2)
  return SIMDE_EM_INT32X4_SSE2_C(_mm_set1_epi32(s));
#elif defined(SIMDE_SSE2_NEON)
  return SIMDE_EM_INT32X4_NEON_C(vdupq_n_s32(a));
#else
  return (simde_em_int32x4) {
    .v = { s, s, s, s }
  };
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde_em_int32x4
simde_em_int32x4_add (simde_em_int32x4 a, simde_em_int32x4 b) {
#if defined(SIMDE_EM_NATIVE)
  return SIMDE_EM_INT32X4_C(emscripten_int32x4_add(a.n, b.n));
#elif defined(SIMDE_EM_SSE2)
  return SIMDE_EM_INT32X4_SSE2_C(_mm_add_epi32(a.sse2, b.sse2));
#elif defined(SIMDE_EM_NEON)
  return SIMDE_EM_INT32X4_NEON_C(vaddq_s32(a.neon, b.neon));
#elif defined(SIMDE__ENABLE_GCC_VEC_EXT)
  simde_em_int32x4 r;
  r.v = a.v + b.v;
  return r;
#else
  simde_em_int32x4 r;
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.v) / sizeof(r.v[0])) ; i++) {
    r.v[i] = a.v[i] + b.v[i];
  }
  return r;
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde_em_int32x4
simde_em_int32x4_sub (simde_em_int32x4 a, simde_em_int32x4 b) {
#if defined(SIMDE_EM_NATIVE)
  return SIMDE_EM_INT32X4_C(emscripten_int32x4_sub(a.n, b.n));
#elif defined(SIMDE_EM_SSE2)
  return SIMDE_EM_INT32X4_SSE2_C(_mm_sub_epi32(a.sse2, b.sse2));
#elif defined(SIMDE_EM_NEON)
  return SIMDE_EM_INT32X4_NEON_C(vsubq_s32(a.neon, b.neon));
#elif defined(SIMDE__ENABLE_GCC_VEC_EXT)
  simde_em_int32x4 r;
  r.v = a.v - b.v;
  return r;
#else
  simde_em_int32x4 r;
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.v) / sizeof(r.v[0])) ; i++) {
    r.v[i] = a.v[i] - b.v[i];
  }
  return r;
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde_em_int32x4
simde_em_int32x4_mul (simde_em_int32x4 a, simde_em_int32x4 b) {
#if defined(SIMDE_EM_NATIVE)
  return SIMDE_EM_INT32X4_C(emscripten_int32x4_mul(a.n, b.n));
#elif defined(SIMDE_EM_SSE2) && defined(__SSE4_1__)
  return SIMDE_EM_INT32X4_SSE2_C(_mm_mullo_epi32(a.sse2, b.sse2));
#elif defined(SIMDE_EM_NEON)
  return SIMDE_EM_INT32X4_NEON_C(vmulq_s32(a.neon, b.neon));
#elif defined(SIMDE__ENABLE_GCC_VEC_EXT)
  simde_em_int32x4 r;
  r.v = a.v * b.v;
  return r;
#else
  simde_em_int32x4 r;
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.v) / sizeof(r.v[0])) ; i++) {
    r.v[i] = a.v[i] * b.v[i];
  }
  return r;
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde_em_int32x4
simde_em_int32x4_neg (simde_em_int32x4 a) {
#if defined(SIMDE_EM_NATIVE)
  return SIMDE_EM_INT32X4_C(emscripten_int32x4_neg(a.n));
#elif defined(SIMDE_EM_SSE2) && defined(__SSE4_1__)
  return SIMDE_EM_INT32X4_SSE2_C(_mm_mullo_epi32(a.sse2, _mm_set1_epi32(-1)));
#elif defined(SIMDE_EM_NEON)
  return SIMDE_EM_INT32X4_NEON_C(vnegq_s32(a.neon));
#elif defined(SIMDE__ENABLE_GCC_VEC_EXT)
  simde_em_int32x4 r;
  r.v = -(a.v);
  return r;
#else
  simde_em_int32x4 r;
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.v) / sizeof(r.v[0])) ; i++) {
    r.v[i] = -(a.v[i]);
  }
  return r;
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde_em_int32x4
simde_em_int32x4_and (simde_em_int32x4 a, simde_em_int32x4 b) {
#if defined(SIMDE_EM_NATIVE)
  return SIMDE_EM_INT32X4_C(emscripten_int32x4_and(a.n, b.n));
#elif defined(SIMDE_EM_SSE2)
  return SIMDE_EM_INT32X4_SSE2_C(_mm_and_si128(a.sse2, b.sse2));
#elif defined(SIMDE_EM_NEON)
  return SIMDE_EM_INT32X4_NEON_C(vandq_s32(a.neon, b.neon));
#elif defined(SIMDE__ENABLE_GCC_VEC_EXT)
  simde_em_int32x4 r;
  r.v = a.v & b.v;
  return r;
#else
  simde_em_int32x4 r;
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.v) / sizeof(r.v[0])) ; i++) {
    r.v[i] = a.v[i] & b.v[i];
  }
  return r;
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde_em_int32x4
simde_em_int32x4_xor (simde_em_int32x4 a, simde_em_int32x4 b) {
#if defined(SIMDE_EM_NATIVE)
  return SIMDE_EM_INT32X4_C(emscripten_int32x4_xor(a.n, b.n));
#elif defined(SIMDE_EM_SSE2)
  return SIMDE_EM_INT32X4_SSE2_C(_mm_xor_si128(a.sse2, b.sse2));
#elif defined(SIMDE_EM_NEON)
  return SIMDE_EM_INT32X4_NEON_C(veorq_s32(a.neon, b.neon));
#elif defined(SIMDE__ENABLE_GCC_VEC_EXT)
  simde_em_int32x4 r;
  r.v = a.v ^ b.v;
  return r;
#else
  simde_em_int32x4 r;
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.v) / sizeof(r.v[0])) ; i++) {
    r.v[i] = a.v[i] ^ b.v[i];
  }
  return r;
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde_em_int32x4
simde_em_int32x4_or (simde_em_int32x4 a, simde_em_int32x4 b) {
#if defined(SIMDE_EM_NATIVE)
  return SIMDE_EM_INT32X4_C(emscripten_int32x4_or(a.n, b.n));
#elif defined(SIMDE_EM_SSE2)
  return SIMDE_EM_INT32X4_SSE2_C(_mm_or_si128(a.sse2, b.sse2));
#elif defined(SIMDE_EM_NEON)
  return SIMDE_EM_INT32X4_NEON_C(vorrq_s32(a.neon, b.neon));
#elif defined(SIMDE__ENABLE_GCC_VEC_EXT)
  simde_em_int32x4 r;
  r.v = a.v | b.v;
  return r;
#else
  simde_em_int32x4 r;
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.v) / sizeof(r.v[0])) ; i++) {
    r.v[i] = a.v[i] | b.v[i];
  }
  return r;
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde_em_int32x4
simde_em_int32x4_not (simde_em_int32x4 a) {
#if defined(SIMDE_EM_NATIVE)
  return SIMDE_EM_INT32X4_C(emscripten_int32x4_not(a.n));
#elif defined(SIMDE_EM_SSE2)
  return SIMDE_EM_INT32X4_SSE2_C(_mm_andnot_si128(a.sse2, _mm_set1_epi32(~INT32_C(0))));
#elif defined(SIMDE_EM_NEON)
  return SIMDE_EM_INT32X4_NEON_C(vmvnq_s32(a.neon));
#elif defined(SIMDE__ENABLE_GCC_VEC_EXT)
  simde_em_int32x4 r;
  r.v = ~(a.v);
  return r;
#else
  simde_em_int32x4 r;
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.v) / sizeof(r.v[0])) ; i++) {
    r.v[i] = ~(a.v[i]);
  }
  return r;
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde_em_bool32x4
simde_em_int32x4_lessThan (simde_em_int32x4 a, simde_em_int32x4 b) {
#if defined(SIMDE_EM_NATIVE)
  return SIMDE_EM_BOOL32X4_C(emscripten_int32x4_lessThan(a.n, b.n));
#elif defined(SIMDE_EM_SSE2)
  return SIMDE_EM_BOOL32X4_SSE2_C(_mm_cmplt_epi32(a.sse2, b.sse2));
#elif defined(SIMDE_EM_NEON)
  return SIMDE_EM_BOOL32X4_NEON_UC(vcltq_s32(a.neon, b.neon));
#else
  simde_em_bool32x4 r;
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.v) / sizeof(r.v[0])) ; i++) {
    r.v[i] = (a.v[i] < b.v[i]) ? ~INT32_C(0) : 0;
  }
  return r;
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde_em_bool32x4
simde_em_int32x4_lessThanOrEqual (simde_em_int32x4 a, simde_em_int32x4 b) {
#if defined(SIMDE_EM_NATIVE)
  return SIMDE_EM_BOOL32X4_C(emscripten_int32x4_lessThanOrEqual(a.n, b.n));
#elif defined(SIMDE_EM_SSE2)
  return SIMDE_EM_BOOL32X4_SSE2_C(_mm_andnot_si128(_mm_cmpgt_epi32(a.sse2, b.sse2), _mm_set1_epi32(~INT32_C(0))));
#elif defined(SIMDE_EM_NEON)
  return SIMDE_EM_BOOL32X4_NEON_UC(vcleq_s32(a.neon, b.neon));
#else
  simde_em_bool32x4 r;
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.v) / sizeof(r.v[0])) ; i++) {
    r.v[i] = (a.v[i] <= b.v[i]) ? ~INT32_C(0) : 0;
  }
  return r;
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde_em_bool32x4
simde_em_int32x4_greaterThan (simde_em_int32x4 a, simde_em_int32x4 b) {
#if defined(SIMDE_EM_NATIVE)
  return SIMDE_EM_BOOL32X4_C(emscripten_int32x4_greaterThan(a.n, b.n));
#elif defined(SIMDE_EM_SSE2)
  return SIMDE_EM_BOOL32X4_SSE2_C(_mm_cmpgt_epi32(a.sse2, b.sse2));
#elif defined(SIMDE_EM_NEON)
  return SIMDE_EM_BOOL32X4_NEON_UC(vcgtq_s32(a.neon, b.neon));
#else
  simde_em_bool32x4 r;
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.v) / sizeof(r.v[0])) ; i++) {
    r.v[i] = (a.v[i] > b.v[i]) ? ~INT32_C(0) : 0;
  }
  return r;
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde_em_bool32x4
simde_em_int32x4_greaterThanOrEqual (simde_em_int32x4 a, simde_em_int32x4 b) {
#if defined(SIMDE_EM_NATIVE)
  return SIMDE_EM_BOOL32X4_C(emscripten_int32x4_greaterThanOrEqual(a.n, b.n));
#elif defined(SIMDE_EM_SSE2)
  return SIMDE_EM_BOOL32X4_SSE2_C(_mm_andnot_si128(_mm_cmplt_epi32(a.sse2, b.sse2), _mm_set1_epi32(~INT32_C(0))));
#elif defined(SIMDE_EM_NEON)
  return SIMDE_EM_BOOL32X4_NEON_UC(vcgeq_s32(a.neon, b.neon));
#else
  simde_em_bool32x4 r;
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.v) / sizeof(r.v[0])) ; i++) {
    r.v[i] = (a.v[i] >= b.v[i]) ? ~INT32_C(0) : 0;
  }
  return r;
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde_em_bool32x4
simde_em_int32x4_equal (simde_em_int32x4 a, simde_em_int32x4 b) {
#if defined(SIMDE_EM_NATIVE)
  return SIMDE_EM_BOOL32X4_C(emscripten_int32x4_equal(a.n, b.n));
#elif defined(SIMDE_EM_SSE2)
  return SIMDE_EM_BOOL32X4_SSE2_C(_mm_cmpeq_epi32(a.sse2, b.sse2));
#elif defined(SIMDE_EM_NEON)
  return SIMDE_EM_BOOL32X4_NEON_UC(vceqq_s32(a.neon, b.neon));
#else
  simde_em_bool32x4 r;
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.v) / sizeof(r.v[0])) ; i++) {
    r.v[i] = (a.v[i] == b.v[i]) ? ~INT32_C(0) : 0;
  }
  return r;
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde_em_bool32x4
simde_em_int32x4_notEqual (simde_em_int32x4 a, simde_em_int32x4 b) {
#if defined(SIMDE_EM_NATIVE)
  return SIMDE_EM_BOOL32X4_C(emscripten_int32x4_notEqual(a.n, b.n));
#elif defined(SIMDE_EM_SSE2)
  return SIMDE_EM_BOOL32X4_SSE2_C(_mm_andnot_si128(_mm_cmpeq_epi32(a.sse2, b.sse2), _mm_set1_epi32(~INT32_C(0))));
#elif defined(SIMDE_EM_NEON)
  return SIMDE_EM_BOOL32X4_NEON_UC(vmvnq_u32(vceqq_s32(a.neon, b.neon)));
#else
  simde_em_bool32x4 r;
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.v) / sizeof(r.v[0])) ; i++) {
    r.v[i] = (a.v[i] != b.v[i]) ? ~INT32_C(0) : 0;
  }
  return r;
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde_em_int32x4
simde_em_int32x4_select (simde_em_bool32x4 selector, simde_em_int32x4 a, simde_em_int32x4 b) {
#if defined(SIMDE_EM_NATIVE)
  return SIMDE_EM_INT32X4_C(emscripten_int32x4_select(selector.n, a.n, b.n));
#elif defined(SIMDE_EM_SSE2)
  #if defined(__AVX512VL__)
    return SIMDE_EM_INT32X4_SSE2_C(_mm_mask_blend_epi32(selector.n, b.n, a.n));
  #else
    /* TODO: check if this is faster than the portable version */
    __m128i s  = _mm_cmpeq_epi32(selector.sse2, _mm_set1_epi32(0));
    __m128i bp = _mm_and_si128(s, b.sse2);
    __m128i ap = _mm_and_si128(_mm_andnot_si128(s, _mm_set1_epi32(~0)), a.sse2);
    return SIMDE_EM_INT32X4_SSE2_C(_mm_or_si128(ap, bp));
  #endif
#elif defined(SIMDE_EM_NEON)
  return SIMDE_EM_INT32X4_NEON_C(vbslq_s32(vreinterpretq_u32_s32(selector.neon), a.neon, b.neon));
#else
  simde_em_int32x4 r;
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.v) / sizeof(r.v[0])) ; i++) {
    r.v[i] = selector.v[i] ? a.v[i] : b.v[i];
  }
  return r;
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde_em_int32x4
simde_em_int32x4_shiftLeftByScalar (simde_em_int32x4 a, const int bits) {
#if defined(SIMDE_EM_NATIVE)
  return SIMDE_EM_INT32X4_C(emscripten_int32x4_shiftLeftByScalar(a.n, bits & 31));
#elif defined(SIMDE_EM_SSE2)
  return SIMDE_EM_INT32X4_SSE2_C(_mm_slli_epi32(a.sse2, bits & 31));
#elif defined(SIMDE_EM_NEON)
  #if defined(__GNUC__)
    if (__builtin_constant_p(bits))
      return SIMDE_EM_INT32X4_NEON_C(vshlq_n_s32(a.neon, bits & 31));
    else
      return SIMDE_EM_INT32X4_NEON_C(vshlq_s32(a.neon, vdupq_n_s32(bits & 31)));
  #else
    return SIMDE_EM_INT32X4_NEON_C(vshlq_n_s32(a.neon, bits & 31));
  #endif
#elif defined(SIMDE__ENABLE_GCC_VEC_EXT)
  simde_em_int32x4 r;
  r.v = a.v << bits;
  return r;
#else
  simde_em_int32x4 r;
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.v) / sizeof(r.v[0])) ; i++) {
    r.v[i] = a.v[i] << bits;
  }
  return r;
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde_em_int32x4
simde_em_int32x4_shiftRightByScalar (simde_em_int32x4 a, const int bits) {
#if defined(SIMDE_EM_NATIVE)
  return SIMDE_EM_INT32X4_C(emscripten_int32x4_shiftRightByScalar(a.n, bits & 31));
#elif defined(SIMDE_EM_SSE2)
  return SIMDE_EM_INT32X4_SSE2_C(_mm_srai_epi32(a.sse2, bits & 31));
#elif defined(SIMDE_EM_NEON)
  #if defined(__GNUC__)
    if (__builtin_constant_p(bits))
      return SIMDE_EM_INT32X4_NEON_C(vshrq_n_s32(a.neon, bits & 31));
    else
      return SIMDE_EM_INT32X4_NEON_C(vshlq_s32(a.neon, vdupq_n_s32(-(bits & 31))));
  #else
    return SIMDE_EM_INT32X4_NEON_C(vshrq_n_s32(a.neon, bits & 31));
  #endif
#elif defined(SIMDE__ENABLE_GCC_VEC_EXT)
  simde_em_int32x4 r;
  r.v = a.v >> bits;
  return r;
#else
  simde_em_int32x4 r;
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.v) / sizeof(r.v[0])) ; i++) {
    r.v[i] = a.v[i] >> bits;
  }
  return r;
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
void
simde_em_int32x4_store (int32_t dest[HEDLEY_ARRAY_PARAM(4)], simde_em_int32x4 a) {
#if defined(SIMDE_EM_NATIVE)
  emscripten_int32x4_store(dest, a.n);
#elif defined(SIMDE_EM_SSE2)
  _mm_storeu_si128((__m128i*) dest, a.sse2);
#elif defined(SIMDE_EM_NEON)
  vst1q_s32(dest, a.neon);
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < 4 ; i++) {
    dest[i] = a.v[i];
  }
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
void
simde_em_int32x4_store1 (int32_t* dest, simde_em_int32x4 a) {
#if defined(SIMDE_EM_NATIVE)
  emscripten_int32x4_store1(dest, a.n);
#elif defined(SIMDE_EM_NEON)
  vst1q_lane_s32(dest, a.neon, 0);
#else
  *dest = a.v[0];
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
void
simde_em_int32x4_store2 (int32_t dest[HEDLEY_ARRAY_PARAM(2)], simde_em_int32x4 a) {
#if defined(SIMDE_EM_NATIVE)
  emscripten_int32x4_store2(dest, a.n);
#elif defined(SIMDE_EM_NEON)
  vst1_s32(dest, vget_low_s32(a.neon));
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < 2 ; i++) {
    dest[i] = a.v[i];
  }
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde_em_int32x4
simde_em_int32x4_load (const int32_t src[HEDLEY_ARRAY_PARAM(4)]) {
#if defined(SIMDE_EM_NATIVE)
  return SIMDE_EM_INT32X4_C(emscripten_int32x4_load(src));
#elif defined(SIMDE_EM_SSE2)
  return SIMDE_EM_INT32X4_SSE2_C(_mm_loadu_si128((__m128i const*) src));
#elif defined(SIMDE_EM_NEON)
  return SIMDE_EM_INT32X4_NEON_C(vld1q_s32(src));
#else
  simde_em_int32x4 r;
  memcpy(&r, src, sizeof(r));
  return r;
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde_em_int32x4
simde_em_int32x4_load1 (const int32_t* src) {
#if defined(SIMDE_EM_NATIVE)
  return SIMDE_EM_INT32X4_C(emscripten_int32x4_load1(src));
#elif defined(SIMDE_EM_SSE2)
  int32_t tmp;
  memcpy(&tmp, src, sizeof(int32_t));
  return SIMDE_EM_INT32X4_SSE2_C(_mm_set_epi32(0, 0, 0, tmp));
#elif defined(SIMDE_EM_NEON)
  int32_t tmp[4] = { 0, };
  memcpy(tmp, src, sizeof(int32_t));
  return SIMDE_EM_INT32X4_NEON_C(vld1q_s32(tmp));
#else
  int32_t tmp;
  memcpy(&tmp, src, sizeof(int32_t));
  return simde_em_int32x4_set(tmp, 0, 0, 0);
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde_em_int32x4
simde_em_int32x4_load2 (const int32_t src[HEDLEY_ARRAY_PARAM(2)]) {
#if defined(SIMDE_EM_NATIVE)
  return SIMDE_EM_INT32X4_C(emscripten_int32x4_load2(src));
#elif defined(SIMDE_EM_SSE2)
  __m128i r;
  memcpy(&(((int32_t*) &r)[0]), &(src[0]), sizeof(int32_t));
  memcpy(&(((int32_t*) &r)[1]), &(src[1]), sizeof(int32_t));
  memset(&(((int32_t*) &r)[2]), 0, sizeof(int32_t) * 2);
  return SIMDE_EM_INT32X4_SSE2_C(r);
#elif defined(SIMDE_EM_NEON)
  int32_t tmp[4] = { 0, };
  memcpy(&(tmp[0]), src, sizeof(int32_t) * 2);
  return SIMDE_EM_INT32X4_NEON_C(vld1q_s32(tmp));
#else
  return simde_em_int32x4_set(src[0], src[1], 0, 0);
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde_em_bool32x4
simde_x_em_bool32x4_set (_Bool s0, _Bool s1, _Bool s2, _Bool s3) {
#if defined(SIMDE_EM_NATIVE)
  int32x4 a = emscripten_int32x4_set(s0, s1, s2, s3);
  int32x4 b = emscripten_int32x4_splat(0);
  return SIMDE_EM_BOOL32X4_C(emscripten_int32x4_notEqual(a, b));
#elif defined(SIMDE_EM_SSE2)
  __m128i a = _mm_set_epi32(s3, s2, s1, s0);
  __m128i b = _mm_set1_epi32(0);
  return SIMDE_EM_BOOL32X4_SSE2_C(_mm_andnot_si128(_mm_cmpeq_epi32(a, b), _mm_set1_epi32(~INT32_C(0))));
#elif defined(SIMDE_EM_NEON)
  SIMDE__ALIGN(16) int32_t data[4] = { s0, s1, s2, s3 };
  return SIMDE_EM_BOOL32X4_NEON_UC(vmvnq_u32(vceqq_s32(vld1q_s32(data), vdupq_n_s32(0))));
#else
  return (simde_em_bool32x4) {
    .v = {
      s0 ? ~INT32_C(0) : 0,
      s1 ? ~INT32_C(0) : 0,
      s2 ? ~INT32_C(0) : 0,
      s3 ? ~INT32_C(0) : 0
    }
  };
#endif
}

SIMDE__END_DECLS

#endif /* !defined(SIMDE__EM_H) */
