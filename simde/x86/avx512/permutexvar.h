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
 *   2020      Christopher Moore <moore@free.fr>
 */

#if !defined(SIMDE_X86_AVX512_PERMUTEXVAR_H)
#define SIMDE_X86_AVX512_PERMUTEXVAR_H

#include "types.h"
#include "mov.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_permutexvar_epi32 (simde__m512i idx, simde__m512i a) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_permutexvar_epi32(idx, a);
  #else
    simde__m512i_private
      idx_ = simde__m512i_to_private(idx),
      a_ = simde__m512i_to_private(a),
      r_;

    #if !defined(__INTEL_COMPILER)
      SIMDE_VECTORIZE
    #endif
    for (size_t i = 0 ; i < (sizeof(r_.i32) / sizeof(r_.i32[0])) ; i++) {
      r_.i32[i] = a_.i32[idx_.i32[i] & 0x0F];
    }

    return simde__m512i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_permutexvar_epi32
  #define _mm512_permutexvar_epi32(idx, a) simde_mm512_permutexvar_epi32(idx, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_mask_permutexvar_epi32 (simde__m512i src, simde__mmask16 k, simde__m512i idx, simde__m512i a) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_mask_permutexvar_epi32(src, k, idx, a);
  #else
    return simde_mm512_mask_mov_epi32(src, k, simde_mm512_permutexvar_epi32(idx, a));
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_permutexvar_epi32
  #define _mm512_mask_permutexvar_epi32(src, k, idx, a) simde_mm512_mask_permutexvar_epi32(src, k, idx, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_maskz_permutexvar_epi32 (simde__mmask16 k, simde__m512i idx, simde__m512i a) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_maskz_permutexvar_epi32(k, idx, a);
  #else
    return simde_mm512_maskz_mov_epi32(k, simde_mm512_permutexvar_epi32(idx, a));
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_maskz_permutexvar_epi32
  #define _mm512_maskz_permutexvar_epi32(k, idx, a) simde_mm512_maskz_permutexvar_epi32(k, idx, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_permutexvar_epi64 (simde__m512i idx, simde__m512i a) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_permutexvar_epi64(idx, a);
  #else
    simde__m512i_private
      idx_ = simde__m512i_to_private(idx),
      a_ = simde__m512i_to_private(a),
      r_;

    #if !defined(__INTEL_COMPILER)
      SIMDE_VECTORIZE
    #endif
    for (size_t i = 0 ; i < (sizeof(r_.i64) / sizeof(r_.i64[0])) ; i++) {
      r_.i64[i] = a_.i64[idx_.i64[i] & 7];
    }

    return simde__m512i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_permutexvar_epi64
  #define _mm512_permutexvar_epi64(idx, a) simde_mm512_permutexvar_epi64(idx, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_mask_permutexvar_epi64 (simde__m512i src, simde__mmask8 k, simde__m512i idx, simde__m512i a) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_mask_permutexvar_epi64(src, k, idx, a);
  #else
    return simde_mm512_mask_mov_epi64(src, k, simde_mm512_permutexvar_epi64(idx, a));
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_permutexvar_epi64
  #define _mm512_mask_permutexvar_epi64(src, k, idx, a) simde_mm512_mask_permutexvar_epi64(src, k, idx, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_maskz_permutexvar_epi64 (simde__mmask8 k, simde__m512i idx, simde__m512i a) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_maskz_permutexvar_epi64(k, idx, a);
  #else
    return simde_mm512_maskz_mov_epi64(k, simde_mm512_permutexvar_epi64(idx, a));
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_maskz_permutexvar_epi64
  #define _mm512_maskz_permutexvar_epi64(k, idx, a) simde_mm512_maskz_permutexvar_epi64(k, idx, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512d
simde_mm512_permutexvar_pd (simde__m512i idx, simde__m512d a) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_permutexvar_pd(idx, a);
  #else
    simde__m512i_private idx_ = simde__m512i_to_private(idx);
    simde__m512d_private
      a_ = simde__m512d_to_private(a),
      r_;

    #if !defined(__INTEL_COMPILER)
      SIMDE_VECTORIZE
    #endif
    for (size_t i = 0 ; i < (sizeof(r_.f64) / sizeof(r_.f64[0])) ; i++) {
      r_.f64[i] = a_.f64[idx_.i64[i] & 7];
    }

    return simde__m512d_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_permutexvar_pd
  #define _mm512_permutexvar_pd(idx, a) simde_mm512_permutexvar_pd(idx, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512d
simde_mm512_mask_permutexvar_pd (simde__m512d src, simde__mmask8 k, simde__m512i idx, simde__m512d a) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_mask_permutexvar_pd(src, k, idx, a);
  #else
    return simde_mm512_mask_mov_pd(src, k, simde_mm512_permutexvar_pd(idx, a));
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_permutexvar_pd
  #define _mm512_mask_permutexvar_pd(src, k, idx, a) simde_mm512_mask_permutexvar_pd(src, k, idx, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512d
simde_mm512_maskz_permutexvar_pd (simde__mmask8 k, simde__m512i idx, simde__m512d a) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_maskz_permutexvar_pd(k, idx, a);
  #else
    return simde_mm512_maskz_mov_pd(k, simde_mm512_permutexvar_pd(idx, a));
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_maskz_permutexvar_pd
  #define _mm512_maskz_permutexvar_pd(k, idx, a) simde_mm512_maskz_permutexvar_pd(k, idx, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512
simde_mm512_permutexvar_ps (simde__m512i idx, simde__m512 a) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_permutexvar_ps(idx, a);
  #else
    simde__m512i_private idx_ = simde__m512i_to_private(idx);
    simde__m512_private
      a_ = simde__m512_to_private(a),
      r_;

    #if !defined(__INTEL_COMPILER)
      SIMDE_VECTORIZE
    #endif
    for (size_t i = 0 ; i < (sizeof(r_.f32) / sizeof(r_.f32[0])) ; i++) {
      r_.f32[i] = a_.f32[idx_.i32[i] & 0x0F];
    }

    return simde__m512_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_permutexvar_ps
  #define _mm512_permutexvar_ps(idx, a) simde_mm512_permutexvar_ps(idx, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512
simde_mm512_mask_permutexvar_ps (simde__m512 src, simde__mmask16 k, simde__m512i idx, simde__m512 a) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_mask_permutexvar_ps(src, k, idx, a);
  #else
    return simde_mm512_mask_mov_ps(src, k, simde_mm512_permutexvar_ps(idx, a));
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_permutexvar_ps
  #define _mm512_mask_permutexvar_ps(src, k, idx, a) simde_mm512_mask_permutexvar_ps(src, k, idx, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512
simde_mm512_maskz_permutexvar_ps (simde__mmask16 k, simde__m512i idx, simde__m512 a) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_maskz_permutexvar_ps(k, idx, a);
  #else
    return simde_mm512_maskz_mov_ps(k, simde_mm512_permutexvar_ps(idx, a));
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_maskz_permutexvar_ps
  #define _mm512_maskz_permutexvar_ps(k, idx, a) simde_mm512_maskz_permutexvar_ps(k, idx, a)
#endif

SIMDE_END_DECLS_
HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_X86_AVX512_PERMUTEXVAR_H) */
