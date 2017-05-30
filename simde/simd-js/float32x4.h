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

#if !defined(SIMDE__EM_H_INSIDE)
#  error float32x4.h must not be included directly; use <simde/simde-js/simde-js.h> instead.
#endif

#if !defined(SIMDE__EM_FLOAT32X4_H)
#define SIMDE__EM_FLOAT32X4_H

SIMDE__BEGIN_DECLS

SIMDE__FUNCTION_ATTRIBUTES
simde_em_float32x4
simde_em_float32x4_set (simde_float32 s0, simde_float32 s1, simde_float32 s2, simde_float32 s3) {
#if defined(SIMDE_EM_NATIVE)
  return SIMDE_EM_FLOAT32X4_C(emscripten_float32x4_set(s0, s1, s2, s3));
#elif defined(SIMDE_EM_SSE)
  return SIMDE_EM_FLOAT32X4_SSE_C(_mm_set_ps(s3, s2, s1, s0));
#elif defined(SIMDE_EM_NEON)
  SIMDE__ALIGN(16) simde_float32 data[4] = { s0, s1, s2, s3 };
  return SIMDE_EM_FLOAT32X4_NEON_C(vld1q_f32(data));
#else
  return (simde_em_float32x4) {
    .v = { s0, s1, s2, s3 }
  };
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde_em_float32x4
simde_em_float32x4_splat (int32_t s) {
#if defined(SIMDE_EM_NATIVE)
  return SIMDE_EM_FLOAT32X4_C(emscripten_float32x4_splat(s));
#elif defined(SIMDE_EM_SSE)
  return SIMDE_EM_FLOAT32X4_SSE_C(_mm_set1_ps(s));
#elif defined(SIMDE_SSE2_NEON)
  return SIMDE_EM_FLOAT32X4_NEON_C(vdupq_n_f32(a));
#else
  return (simde_em_float32x4) {
    .v = { s, s, s, s }
  };
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde_em_float32x4
simde_em_float32x4_add (simde_em_float32x4 a, simde_em_float32x4 b) {
#if defined(SIMDE_EM_NATIVE)
  return SIMDE_EM_FLOAT32X4_C(emscripten_float32x4_add(a.n, b.n));
#elif defined(SIMDE_EM_SSE)
  return SIMDE_EM_FLOAT32X4_SSE_C(_mm_add_ps(a.sse, b.sse));
#elif defined(SIMDE_EM_NEON)
  return SIMDE_EM_FLOAT32X4_NEON_C(vaddq_f32(a.neon, b.neon));
#elif defined(SIMDE__ENABLE_GCC_VEC_EXT)
  simde_em_float32x4 r;
  r.v = a.v + b.v;
  return r;
#else
  simde_em_float32x4 r;
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.v) / sizeof(r.v[0])) ; i++) {
    r.v[i] = a.v[i] + b.v[i];
  }
  return r;
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde_em_float32x4
simde_em_float32x4_sub (simde_em_float32x4 a, simde_em_float32x4 b) {
#if defined(SIMDE_EM_NATIVE)
  return SIMDE_EM_FLOAT32X4_C(emscripten_float32x4_sub(a.n, b.n));
#elif defined(SIMDE_EM_SSE)
  return SIMDE_EM_FLOAT32X4_SSE_C(_mm_sub_ps(a.sse, b.sse));
#elif defined(SIMDE_EM_NEON)
  return SIMDE_EM_FLOAT32X4_NEON_C(vsubq_f32(a.neon, b.neon));
#elif defined(SIMDE__ENABLE_GCC_VEC_EXT)
  simde_em_float32x4 r;
  r.v = a.v - b.v;
  return r;
#else
  simde_em_float32x4 r;
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.v) / sizeof(r.v[0])) ; i++) {
    r.v[i] = a.v[i] - b.v[i];
  }
  return r;
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde_em_float32x4
simde_em_float32x4_mul (simde_em_float32x4 a, simde_em_float32x4 b) {
#if defined(SIMDE_EM_NATIVE)
  return SIMDE_EM_FLOAT32X4_C(emscripten_float32x4_mul(a.n, b.n));
#elif defined(SIMDE_EM_SSE)
  return SIMDE_EM_FLOAT32X4_SSE_C(_mm_mul_ps(a.sse, b.sse));
#elif defined(SIMDE_EM_NEON)
  return SIMDE_EM_FLOAT32X4_NEON_C(vmulq_f32(a.neon, b.neon));
#elif defined(SIMDE__ENABLE_GCC_VEC_EXT)
  simde_em_float32x4 r;
  r.v = a.v * b.v;
  return r;
#else
  simde_em_float32x4 r;
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.v) / sizeof(r.v[0])) ; i++) {
    r.v[i] = a.v[i] * b.v[i];
  }
  return r;
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde_em_float32x4
simde_em_float32x4_neg (simde_em_float32x4 a) {
#if defined(SIMDE_EM_NATIVE)
  return SIMDE_EM_FLOAT32X4_C(emscripten_float32x4_neg(a.n));
#elif defined(SIMDE_EM_SSE)
  return SIMDE_EM_FLOAT32X4_SSE_C(_mm_mul_ps(a.sse, _mm_set1_ps(-1)));
#elif defined(SIMDE_EM_NEON)
  return SIMDE_EM_FLOAT32X4_NEON_C(vnegq_f32(a.neon));
#elif defined(SIMDE__ENABLE_GCC_VEC_EXT)
  simde_em_float32x4 r;
  r.v = -(a.v);
  return r;
#else
  simde_em_float32x4 r;
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.v) / sizeof(r.v[0])) ; i++) {
    r.v[i] = -(a.v[i]);
  }
  return r;
#endif
}

SIMDE__END_DECLS

#endif /* !defined(SIMDE__EM_FLOAT32X4_H) */
