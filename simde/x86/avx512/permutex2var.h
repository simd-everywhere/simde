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

#if !defined(SIMDE_X86_AVX512_PERMUTEX2VAR_H)
#define SIMDE_X86_AVX512_PERMUTEX2VAR_H

#include "types.h"
#include "mov.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_permutex2var_epi32 (simde__m512i a, simde__m512i idx, simde__m512i b) {
  #if defined(SIMDE_X86_AVX512BW_NATIVE)
    return _mm512_permutex2var_epi32(a, idx, b);
  #else
    simde__m512i_private
      a_ = simde__m512i_to_private(a),
      idx_ = simde__m512i_to_private(idx),
      b_ = simde__m512i_to_private(b),
      r_;

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.i32) / sizeof(r_.i32[0])) ; i++) {
      r_.i32[i] = ((idx_.i32[i] & 0x10) ? b_ : a_).i32[idx_.i32[i] & 0x0F];
    }

    return simde__m512i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES)
  #undef _mm512_permutex2var_epi32
  #define _mm512_permutex2var_epi32(a, idx, b) simde_mm512_permutex2var_epi32(a, idx, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_mask_permutex2var_epi32 (simde__m512i a, simde__mmask16 k, simde__m512i idx, simde__m512i b) {
  #if defined(SIMDE_X86_AVX512BW_NATIVE)
    return _mm512_mask_permutex2var_epi32(a, k, idx, b);
  #else
    return simde_mm512_mask_mov_epi32(a, k, simde_mm512_permutex2var_epi32(a, idx, b));
  #endif
}
#if defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_permutex2var_epi32
#define _mm512_mask_permutex2var_epi32(a, k, idx, b) simde_mm512_mask_permutex2var_epi32(a, k, idx, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_mask2_permutex2var_epi32 (simde__m512i a, simde__m512i idx, simde__mmask16 k, simde__m512i b) {
  #if defined(SIMDE_X86_AVX512BW_NATIVE)
    return _mm512_mask2_permutex2var_epi32(a, idx, k, b);
  #else
    return simde_mm512_mask_mov_epi32(idx, k, simde_mm512_permutex2var_epi32(a, idx, b));
  #endif
}
#if defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask2_permutex2var_epi32
#define _mm512_mask2_permutex2var_epi32(a, idx, k, b) simde_mm512_mask2_permutex2var_epi32(a, idx, k, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_maskz_permutex2var_epi32 (simde__mmask16 k, simde__m512i a, simde__m512i idx, simde__m512i b) {
  #if defined(SIMDE_X86_AVX512BW_NATIVE)
    return _mm512_maskz_permutex2var_epi32(k, a, idx, b);
  #else
    return simde_mm512_maskz_mov_epi32(k, simde_mm512_permutex2var_epi32(a, idx, b));
  #endif
}
#if defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES)
  #undef _mm512_maskz_permutex2var_epi32
#define _mm512_maskz_permutex2var_epi32(k, a, idx, b) simde_mm512_maskz_permutex2var_epi32(k, a, idx, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_permutex2var_epi64 (simde__m512i a, simde__m512i idx, simde__m512i b) {
  #if defined(SIMDE_X86_AVX512BW_NATIVE)
    return _mm512_permutex2var_epi64(a, idx, b);
  #else
    simde__m512i_private
      a_ = simde__m512i_to_private(a),
      idx_ = simde__m512i_to_private(idx),
      b_ = simde__m512i_to_private(b),
      r_;

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.i64) / sizeof(r_.i64[0])) ; i++) {
      r_.i64[i] = ((idx_.i64[i] & 0x08) ? b_ : a_).i64[idx_.i64[i] & 0x07];
    }

    return simde__m512i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES)
  #undef _mm512_permutex2var_epi64
  #define _mm512_permutex2var_epi64(a, idx, b) simde_mm512_permutex2var_epi64(a, idx, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_mask_permutex2var_epi64 (simde__m512i a, simde__mmask8 k, simde__m512i idx, simde__m512i b) {
  #if defined(SIMDE_X86_AVX512BW_NATIVE)
    return _mm512_mask_permutex2var_epi64(a, k, idx, b);
  #else
    return simde_mm512_mask_mov_epi64(a, k, simde_mm512_permutex2var_epi64(a, idx, b));
  #endif
}
#if defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_permutex2var_epi64
#define _mm512_mask_permutex2var_epi64(a, k, idx, b) simde_mm512_mask_permutex2var_epi64(a, k, idx, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_mask2_permutex2var_epi64 (simde__m512i a, simde__m512i idx, simde__mmask8 k, simde__m512i b) {
  #if defined(SIMDE_X86_AVX512BW_NATIVE)
    return _mm512_mask2_permutex2var_epi64(a, idx, k, b);
  #else
    return simde_mm512_mask_mov_epi64(idx, k, simde_mm512_permutex2var_epi64(a, idx, b));
  #endif
}
#if defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask2_permutex2var_epi64
#define _mm512_mask2_permutex2var_epi64(a, idx, k, b) simde_mm512_mask2_permutex2var_epi64(a, idx, k, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_maskz_permutex2var_epi64 (simde__mmask8 k, simde__m512i a, simde__m512i idx, simde__m512i b) {
  #if defined(SIMDE_X86_AVX512BW_NATIVE)
    return _mm512_maskz_permutex2var_epi64(k, a, idx, b);
  #else
    return simde_mm512_maskz_mov_epi64(k, simde_mm512_permutex2var_epi64(a, idx, b));
  #endif
}
#if defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES)
  #undef _mm512_maskz_permutex2var_epi64
#define _mm512_maskz_permutex2var_epi64(k, a, idx, b) simde_mm512_maskz_permutex2var_epi64(k, a, idx, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512d
simde_mm512_permutex2var_pd (simde__m512d a, simde__m512i idx, simde__m512d b) {
  #if defined(SIMDE_X86_AVX512BW_NATIVE)
    return _mm512_permutex2var_pd(a, idx, b);
  #else
    simde__m512i_private idx_ = simde__m512i_to_private(idx);
    simde__m512d_private
      a_ = simde__m512d_to_private(a),
      b_ = simde__m512d_to_private(b),
      r_;

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f64) / sizeof(r_.f64[0])) ; i++) {
      r_.f64[i] = ((idx_.i64[i] & 0x08) ? b_ : a_).f64[idx_.i64[i] & 0x07];
    }

    return simde__m512d_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES)
  #undef _mm512_permutex2var_pd
  #define _mm512_permutex2var_pd(a, idx, b) simde_mm512_permutex2var_pd(a, idx, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512d
simde_mm512_mask_permutex2var_pd (simde__m512d a, simde__mmask8 k, simde__m512i idx, simde__m512d b) {
  #if defined(SIMDE_X86_AVX512BW_NATIVE)
    return _mm512_mask_permutex2var_pd(a, k, idx, b);
  #else
    return simde_mm512_mask_mov_pd(a, k, simde_mm512_permutex2var_pd(a, idx, b));
  #endif
}
#if defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_permutex2var_pd
#define _mm512_mask_permutex2var_pd(a, k, idx, b) simde_mm512_mask_permutex2var_pd(a, k, idx, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512d
simde_mm512_mask2_permutex2var_pd (simde__m512d a, simde__m512i idx, simde__mmask8 k, simde__m512d b) {
  #if defined(SIMDE_X86_AVX512BW_NATIVE)
    return _mm512_mask2_permutex2var_pd(a, idx, k, b);
  #else
    return simde_mm512_mask_mov_pd(simde_mm512_castsi512_pd(idx), k, simde_mm512_permutex2var_pd(a, idx, b));
  #endif
}
#if defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask2_permutex2var_pd
#define _mm512_mask2_permutex2var_pd(a, idx, k, b) simde_mm512_mask2_permutex2var_pd(a, idx, k, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512d
simde_mm512_maskz_permutex2var_pd (simde__mmask8 k, simde__m512d a, simde__m512i idx, simde__m512d b) {
  #if defined(SIMDE_X86_AVX512BW_NATIVE)
    return _mm512_maskz_permutex2var_pd(k, a, idx, b);
  #else
    return simde_mm512_maskz_mov_pd(k, simde_mm512_permutex2var_pd(a, idx, b));
  #endif
}
#if defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES)
  #undef _mm512_maskz_permutex2var_pd
#define _mm512_maskz_permutex2var_pd(k, a, idx, b) simde_mm512_maskz_permutex2var_pd(k, a, idx, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512
simde_mm512_permutex2var_ps (simde__m512 a, simde__m512i idx, simde__m512 b) {
  #if defined(SIMDE_X86_AVX512BW_NATIVE)
    return _mm512_permutex2var_ps(a, idx, b);
  #else
    simde__m512i_private idx_ = simde__m512i_to_private(idx);
    simde__m512_private
      a_ = simde__m512_to_private(a),
      b_ = simde__m512_to_private(b),
      r_;

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f32) / sizeof(r_.f32[0])) ; i++) {
      r_.f32[i] = ((idx_.i32[i] & 0x10) ? b_ : a_).f32[idx_.i32[i] & 0x0F];
    }

    return simde__m512_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES)
  #undef _mm512_permutex2var_ps
  #define _mm512_permutex2var_ps(a, idx, b) simde_mm512_permutex2var_ps(a, idx, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512
simde_mm512_mask_permutex2var_ps (simde__m512 a, simde__mmask16 k, simde__m512i idx, simde__m512 b) {
  #if defined(SIMDE_X86_AVX512BW_NATIVE)
    return _mm512_mask_permutex2var_ps(a, k, idx, b);
  #else
    return simde_mm512_mask_mov_ps(a, k, simde_mm512_permutex2var_ps(a, idx, b));
  #endif
}
#if defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_permutex2var_ps
#define _mm512_mask_permutex2var_ps(a, k, idx, b) simde_mm512_mask_permutex2var_ps(a, k, idx, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512
simde_mm512_mask2_permutex2var_ps (simde__m512 a, simde__m512i idx, simde__mmask16 k, simde__m512 b) {
  #if defined(SIMDE_X86_AVX512BW_NATIVE)
    return _mm512_mask2_permutex2var_ps(a, idx, k, b);
  #else
    return simde_mm512_mask_mov_ps(simde_mm512_castsi512_ps(idx), k, simde_mm512_permutex2var_ps(a, idx, b));
  #endif
}
#if defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask2_permutex2var_ps
#define _mm512_mask2_permutex2var_ps(a, idx, k, b) simde_mm512_mask2_permutex2var_ps(a, idx, k, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512
simde_mm512_maskz_permutex2var_ps (simde__mmask16 k, simde__m512 a, simde__m512i idx, simde__m512 b) {
  #if defined(SIMDE_X86_AVX512BW_NATIVE)
    return _mm512_maskz_permutex2var_ps(k, a, idx, b);
  #else
    return simde_mm512_maskz_mov_ps(k, simde_mm512_permutex2var_ps(a, idx, b));
  #endif
}
#if defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES)
  #undef _mm512_maskz_permutex2var_ps
#define _mm512_maskz_permutex2var_ps(k, a, idx, b) simde_mm512_maskz_permutex2var_ps(k, a, idx, b)
#endif

SIMDE_END_DECLS_
HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_X86_AVX512_PERMUTEX2VAR_H) */
