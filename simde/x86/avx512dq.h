/* SPDX-License-Identifier: MIT
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
 *
 * Copyright:
 *   2020      Evan Nemerson <evan@nemerson.com>
 *   2020      Himanshi Mathur <himanshi18037@iiitd.ac.in>
 */

#if !defined(SIMDE_X86_AVX512DQ_H)
#define SIMDE_X86_AVX512DQ_H

#include "avx512bw.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

SIMDE_FUNCTION_ATTRIBUTES
simde__m512d
simde_mm512_and_pd (simde__m512d a, simde__m512d b) {
#if defined(SIMDE_X86_AVX512DQ_NATIVE)
  return _mm512_and_pd(a, b);
#else
  simde__m512d_private
    r_,
    a_ = simde__m512d_to_private(a),
    b_ = simde__m512d_to_private(b);

#if defined(SIMDE_X86_AVX_NATIVE)
  r_.m256d[0] = simde_mm256_and_pd(a_.m256d[0], b_.m256d[0]);
  r_.m256d[1] = simde_mm256_and_pd(a_.m256d[1], b_.m256d[1]);
#elif defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
  r_.i32f = a_.i32f & b_.i32f;
#else
  SIMDE_VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.i32f) / sizeof(r_.i32f[0])) ; i++) {
    r_.i32f[i] = a_.i32f[i] & b_.i32f[i];
  }
#endif

  return simde__m512d_from_private(r_);
#endif
}
#if defined(SIMDE_X86_AVX512DQ_ENABLE_NATIVE_ALIASES)
  #undef _mm512_and_pd
  #define _mm512_and_pd(a, b) simde_mm512_and_pd(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512
simde_mm512_and_ps (simde__m512 a, simde__m512 b) {
#if defined(SIMDE_X86_AVX512DQ_NATIVE)
  return _mm512_and_ps(a, b);
#else
  simde__m512_private
    r_,
    a_ = simde__m512_to_private(a),
    b_ = simde__m512_to_private(b);

#if defined(SIMDE_X86_AVX_NATIVE)
  r_.m256[0] = simde_mm256_and_ps(a_.m256[0], b_.m256[0]);
  r_.m256[1] = simde_mm256_and_ps(a_.m256[1], b_.m256[1]);
#elif defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
  r_.i32f = a_.i32f & b_.i32f;
#else
  SIMDE_VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.i32f) / sizeof(r_.i32f[0])) ; i++) {
    r_.i32f[i] = a_.i32f[i] & b_.i32f[i];
  }
#endif

  return simde__m512_from_private(r_);
#endif
}
#if defined(SIMDE_X86_AVX512DQ_ENABLE_NATIVE_ALIASES)
  #undef _mm512_and_ps
  #define _mm512_and_ps(a, b) simde_mm512_and_ps(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512
simde_mm512_mask_and_ps(simde__m512 src, simde__mmask16 k, simde__m512 a, simde__m512 b) {
#if defined(SIMDE_X86_AVX512DQ_NATIVE)
  return _mm512_mask_and_ps(src, k, a, b);
#else
  return simde_mm512_mask_mov_ps(src, k, simde_mm512_and_ps(a, b));
#endif
}
#if defined(SIMDE_X86_AVX512DQ_ENABLE_NATIVE_ALIASES)
#define _mm512_mask_and_ps(src, k, a, b) simde_mm512_mask_and_ps(src, k, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512
simde_mm512_maskz_and_ps(simde__mmask16 k, simde__m512 a, simde__m512 b) {
#if defined(SIMDE_X86_AVX512DQ_NATIVE)
  return _mm512_maskz_and_ps(k, a, b);
#else
  return simde_mm512_maskz_mov_ps(k, simde_mm512_and_ps(a, b));
#endif
}
#if defined(SIMDE_X86_AVX512DQ_ENABLE_NATIVE_ALIASES)
#define _mm512_maskz_and_ps(k, a, b) simde_mm512_maskz_and_ps(k, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512d
simde_mm512_mask_and_pd(simde__m512d src, simde__mmask8 k, simde__m512d a, simde__m512d b) {
#if defined(SIMDE_X86_AVX512DQ_NATIVE)
  return _mm512_mask_and_pd(src, k, a, b);
#else
  return simde_mm512_mask_mov_pd(src, k, simde_mm512_and_pd(a, b));
#endif
}
#if defined(SIMDE_X86_AVX512DQ_ENABLE_NATIVE_ALIASES)
#define _mm512_mask_and_pd(src, k, a, b) simde_mm512_mask_and_pd(src, k, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512d
simde_mm512_maskz_and_pd(simde__mmask8 k, simde__m512d a, simde__m512d b) {
#if defined(SIMDE_X86_AVX512DQ_NATIVE)
  return _mm512_maskz_and_pd(k, a, b);
#else
  return simde_mm512_maskz_mov_pd(k, simde_mm512_and_pd(a, b));
#endif
}
#if defined(SIMDE_X86_AVX512DQ_ENABLE_NATIVE_ALIASES)
#define _mm512_maskz_and_pd(k, a, b) simde_mm512_maskz_and_pd(k, a, b)
#endif

#if defined(SIMDE_X86_AVX512DQ_NATIVE)
  #define simde_mm512_andnot_ps(a, b) _mm512_andnot_ps(a, b)
#else
  #define simde_mm512_andnot_ps(a, b) simde_mm512_castsi512_ps(simde_mm512_andnot_si512(simde_mm512_castps_si512(a), simde_mm512_castps_si512(b)))
#endif
#if defined(SIMDE_X86_AVX512DQ_ENABLE_NATIVE_ALIASES)
  #undef _mm512_andnot_ps
  #define _mm512_andnot_ps(a, b) simde_mm512_andnot_ps(a, b)
#endif

#if defined(SIMDE_X86_AVX512DQ_NATIVE)
  #define simde_mm512_mask_andnot_ps(src, k, a, b) _mm512_mask_andnot_ps((src), (k), (a), (b))
#else
  #define simde_mm512_mask_andnot_ps(src, k, a, b) simde_mm512_castsi512_ps(simde_mm512_mask_andnot_epi32(simde_mm512_castps_si512(src), k, simde_mm512_castps_si512(a), simde_mm512_castps_si512(b)))
#endif
#if defined(SIMDE_X86_AVX512DQ_ENABLE_NATIVE_ALIASES)
#define _mm512_mask_andnot_ps(src, k, a, b) simde_mm512_mask_andnot_ps(src, k, a, b)
#endif

#if defined(SIMDE_X86_AVX512DQ_NATIVE)
  #define simde_mm512_maskz_andnot_ps(k, a, b) _mm512_maskz_andnot_ps((k), (a), (b))
#else
  #define simde_mm512_maskz_andnot_ps(k, a, b) simde_mm512_castsi512_ps(simde_mm512_maskz_andnot_epi32(k, simde_mm512_castps_si512(a), simde_mm512_castps_si512(b)))
#endif
#if defined(SIMDE_X86_AVX512DQ_ENABLE_NATIVE_ALIASES)
#define _mm512_maskz_andnot_ps(k, a, b) simde_mm512_maskz_andnot_ps(k, a, b)
#endif

#if defined(SIMDE_X86_AVX512DQ_NATIVE)
  #define simde_mm512_andnot_pd(a, b) _mm512_andnot_pd(a, b)
#else
  #define simde_mm512_andnot_pd(a, b) simde_mm512_castsi512_pd(simde_mm512_andnot_si512(simde_mm512_castpd_si512(a), simde_mm512_castpd_si512(b)))
#endif
#if defined(SIMDE_X86_AVX512DQ_ENABLE_NATIVE_ALIASES)
  #undef _mm512_andnot_pd
  #define _mm512_andnot_pd(a, b) simde_mm512_andnot_pd(a, b)
#endif

#if defined(SIMDE_X86_AVX512DQ_NATIVE)
  #define simde_mm512_mask_andnot_pd(src, k, a, b) _mm512_mask_andnot_pd((src), (k), (a), (b))
#else
  #define simde_mm512_mask_andnot_pd(src, k, a, b) simde_mm512_castsi512_pd(simde_mm512_mask_andnot_epi64(simde_mm512_castpd_si512(src), k, simde_mm512_castpd_si512(a), simde_mm512_castpd_si512(b)))
#endif
#if defined(SIMDE_X86_AVX512DQ_ENABLE_NATIVE_ALIASES)
#define _mm512_mask_andnot_pd(src, k, a, b) simde_mm512_mask_andnot_pd(src, k, a, b)
#endif

#if defined(SIMDE_X86_AVX512DQ_NATIVE)
  #define simde_mm512_maskz_andnot_pd(k, a, b) _mm512_maskz_andnot_pd((k), (a), (b))
#else
  #define simde_mm512_maskz_andnot_pd(k, a, b) simde_mm512_castsi512_pd(simde_mm512_maskz_andnot_epi64(k, simde_mm512_castpd_si512(a), simde_mm512_castpd_si512(b)))
#endif
#if defined(SIMDE_X86_AVX512DQ_ENABLE_NATIVE_ALIASES)
#define _mm512_maskz_andnot_pd(k, a, b) simde_mm512_maskz_andnot_pd(k, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512
simde_mm512_or_ps (simde__m512 a, simde__m512 b) {
  #if defined(SIMDE_X86_AVX512DQ_NATIVE)
    return _mm512_or_ps(a, b);
  #else
    simde__m512_private
      r_,
      a_ = simde__m512_to_private(a),
      b_ = simde__m512_to_private(b);

  #if SIMDE_NATURAL_VECTOR_SIZE_LE(256)
    r_.m256[0] = simde_mm256_or_ps(a_.m256[0], b_.m256[0]);
    r_.m256[1] = simde_mm256_or_ps(a_.m256[1], b_.m256[1]);
  #elif defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
    r_.i32f = a_.i32f | b_.i32f;
  #else
    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.i32f) / sizeof(r_.i32f[0])) ; i++) {
      r_.i32f[i] = a_.i32f[i] | b_.i32f[i];
    }
  #endif

    return simde__m512_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512DQ_ENABLE_NATIVE_ALIASES)
  #undef _mm512_or_ps
  #define _mm512_or_ps(a, b) simde_mm512_or_ps(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512d
simde_mm512_or_pd (simde__m512d a, simde__m512d b) {
  #if defined(SIMDE_X86_AVX512DQ_NATIVE)
    return _mm512_or_pd(a, b);
  #else
    simde__m512d_private
      r_,
      a_ = simde__m512d_to_private(a),
      b_ = simde__m512d_to_private(b);

    #if SIMDE_NATURAL_VECTOR_SIZE_LE(256)
      r_.m256d[0] = simde_mm256_or_pd(a_.m256d[0], b_.m256d[0]);
      r_.m256d[1] = simde_mm256_or_pd(a_.m256d[1], b_.m256d[1]);
    #elif defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r_.i32f = a_.i32f | b_.i32f;
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.i32f) / sizeof(r_.i32f[0])) ; i++) {
        r_.i32f[i] = a_.i32f[i] | b_.i32f[i];
      }
    #endif

    return simde__m512d_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512DQ_ENABLE_NATIVE_ALIASES)
  #undef _mm512_or_pd
  #define _mm512_or_pd(a, b) simde_mm512_or_pd(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512
simde_mm512_xor_ps (simde__m512 a, simde__m512 b) {
  #if defined(SIMDE_X86_AVX512DQ_NATIVE)
    return _mm512_xor_ps(a, b);
  #else
    simde__m512_private
      r_,
      a_ = simde__m512_to_private(a),
      b_ = simde__m512_to_private(b);

    #if SIMDE_NATURAL_VECTOR_SIZE_LE(256)
      r_.m256[0] = simde_mm256_xor_ps(a_.m256[0], b_.m256[0]);
      r_.m256[1] = simde_mm256_xor_ps(a_.m256[1], b_.m256[1]);
    #elif defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r_.i32f = a_.i32f ^ b_.i32f;
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.i32f) / sizeof(r_.i32f[0])) ; i++) {
        r_.i32f[i] = a_.i32f[i] ^ b_.i32f[i];
      }
    #endif

    return simde__m512_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512DQ_ENABLE_NATIVE_ALIASES)
  #undef _mm512_xor_ps
  #define _mm512_xor_ps(a, b) simde_mm512_xor_ps(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512d
simde_mm512_xor_pd (simde__m512d a, simde__m512d b) {
  #if defined(SIMDE_X86_AVX512DQ_NATIVE)
    return _mm512_xor_pd(a, b);
  #else
    simde__m512d_private
      r_,
      a_ = simde__m512d_to_private(a),
      b_ = simde__m512d_to_private(b);

    #if SIMDE_NATURAL_VECTOR_SIZE_LE(256)
      r_.m256d[0] = simde_mm256_xor_pd(a_.m256d[0], b_.m256d[0]);
      r_.m256d[1] = simde_mm256_xor_pd(a_.m256d[1], b_.m256d[1]);
    #elif defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r_.i32f = a_.i32f ^ b_.i32f;
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.i32f) / sizeof(r_.i32f[0])) ; i++) {
        r_.i32f[i] = a_.i32f[i] ^ b_.i32f[i];
      }
    #endif

    return simde__m512d_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512DQ_ENABLE_NATIVE_ALIASES)
  #undef _mm512_xor_pd
  #define _mm512_xor_pd(a, b) simde_mm512_xor_pd(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512
simde_x_mm512_copysign_ps(simde__m512 dest, simde__m512 src) {
  simde__m512_private
    r_,
    dest_ = simde__m512_to_private(dest),
    src_ = simde__m512_to_private(src);

  #if defined(simde_math_copysignf)
    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f32) / sizeof(r_.f32[0])) ; i++) {
      r_.f32[i] = simde_math_copysignf(dest_.f32[i], src_.f32[i]);
    }
  #else
    simde__m512 sgnbit = simde_mm512_xor_ps(simde_mm512_set1_ps(SIMDE_FLOAT32_C(0.0)), simde_mm512_set1_ps(-SIMDE_FLOAT32_C(0.0)));
    return simde_mm512_xor_ps(simde_mm512_and_ps(sgnbit, src), simde_mm512_andnot_ps(sgnbit, dest));
  #endif

  return simde__m512_from_private(r_);
}

SIMDE_FUNCTION_ATTRIBUTES
simde__m512d
simde_x_mm512_copysign_pd(simde__m512d dest, simde__m512d src) {
  simde__m512d_private
    r_,
    dest_ = simde__m512d_to_private(dest),
    src_ = simde__m512d_to_private(src);

  #if defined(simde_math_copysign)
    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f64) / sizeof(r_.f64[0])) ; i++) {
      r_.f64[i] = simde_math_copysign(dest_.f64[i], src_.f64[i]);
    }
  #else
    simde__m512d sgnbit = simde_mm512_xor_pd(simde_mm512_set1_pd(SIMDE_FLOAT64_C(0.0)), simde_mm512_set1_pd(-SIMDE_FLOAT64_C(0.0)));
    return simde_mm512_xor_pd(simde_mm512_and_pd(sgnbit, src), simde_mm512_andnot_pd(sgnbit, dest));
  #endif

  return simde__m512d_from_private(r_);
}

SIMDE_FUNCTION_ATTRIBUTES
simde__m512
simde_x_mm512_negate_ps(simde__m512 a) {
  #if defined(SIMDE_X86_AVX512DQ_NATIVE)
    return simde_mm512_xor_ps(a,_mm512_set1_ps(SIMDE_FLOAT32_C(-0.0)));
  #else
    simde__m512_private
      r_,
      a_ = simde__m512_to_private(a);

    #if defined(SIMDE_VECTOR_NEGATE)
      r_.f32 = -a_.f32;
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.f32) / sizeof(r_.f32[0])) ; i++) {
        r_.f32[i] = -a_.f32[i];
      }
    #endif

    return simde__m512_from_private(r_);
  #endif
}

SIMDE_FUNCTION_ATTRIBUTES
simde__m512d
simde_x_mm512_negate_pd(simde__m512d a) {
  #if defined(SIMDE_X86_AVX512DQ_NATIVE)
    return simde_mm512_xor_pd(a, _mm512_set1_pd(SIMDE_FLOAT64_C(-0.0)));
  #else
    simde__m512d_private
      r_,
      a_ = simde__m512d_to_private(a);

    #if defined(SIMDE_VECTOR_NEGATE)
      r_.f64 = -a_.f64;
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.f64) / sizeof(r_.f64[0])) ; i++) {
        r_.f64[i] = -a_.f64[i];
      }
    #endif

    return simde__m512d_from_private(r_);
  #endif
}

SIMDE_FUNCTION_ATTRIBUTES
simde__m512
simde_x_mm512_xorsign_ps(simde__m512 dest, simde__m512 src) {
  return simde_mm512_xor_ps(simde_mm512_and_ps(simde_mm512_set1_ps(-0.0f), src), dest);
}

SIMDE_FUNCTION_ATTRIBUTES
simde__m512d
simde_x_mm512_xorsign_pd(simde__m512d dest, simde__m512d src) {
  return simde_mm512_xor_pd(simde_mm512_and_pd(simde_mm512_set1_pd(-0.0), src), dest);
}

SIMDE_END_DECLS_

HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_X86_AVX512DQ_H) */
