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
 *   2021      Kunwar Maheep Singh <kunwar.maheep@students.iiit.ac.in>
 *   2025      Michael R. Crusoe <crusoe@debian.org>
 */

#if !defined(SIMDE_X86_AVX512_CONFLICT_H)
#define SIMDE_X86_AVX512_CONFLICT_H

#include "types.h"
#include "mov.h"
#include "cmpeq.h"
#include "set1.h"
#include "setzero.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_conflict_epi32 (simde__m128i a) {
  #if defined(SIMDE_X86_AVX512VL_NATIVE) && defined(SIMDE_X86_AVX512CD_NATIVE)
    return _mm_conflict_epi32(a);
  #else
    simde__m128i_private
      r_ = simde__m128i_to_private(simde_mm_setzero_si128()),
      a_ = simde__m128i_to_private(a);

    for (size_t i = 1 ; i < (sizeof(r_.i32) / sizeof(r_.i32[0])) ; i++) {
      r_.i32[i] =
          simde_mm_movemask_ps(
            simde_mm_castsi128_ps(
              simde_mm_cmpeq_epi32(simde_mm_set1_epi32(a_.i32[i]), a)
            )
          ) & ((1 << i) - 1);
    }

    return simde__m128i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512CD_ENABLE_NATIVE_ALIASES)
  #undef _mm_conflict_epi32
  #define _mm_conflict_epi32(a) simde_mm_conflict_epi32(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_mask_conflict_epi32 (simde__m128i src, simde__mmask8 k, simde__m128i a) {
  #if defined(SIMDE_X86_AVX512VL_NATIVE) && defined(SIMDE_X86_AVX512CD_NATIVE)
    return _mm_mask_conflict_epi32(src, k, a);
  #else
    return simde_mm_mask_mov_epi32(src, k, simde_mm_conflict_epi32(a));
  #endif
}
#if defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512CD_ENABLE_NATIVE_ALIASES)
  #undef _mm_mask_conflict_epi32
  #define _mm_mask_conflict_epi32(src, k, a) simde_mm_mask_conflict_epi32(src, k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_maskz_conflict_epi32 (simde__mmask8 k, simde__m128i a) {
  #if defined(SIMDE_X86_AVX512VL_NATIVE) && defined(SIMDE_X86_AVX512CD_NATIVE)
    return _mm_maskz_conflict_epi32(k, a);
  #else
    return simde_mm_maskz_mov_epi32(k, simde_mm_conflict_epi32(a));
  #endif
}
#if defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512CD_ENABLE_NATIVE_ALIASES)
  #undef _mm_maskz_conflict_epi32
  #define _mm_maskz_conflict_epi32(k, a) simde_mm_maskz_conflict_epi32(k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_conflict_epi32 (simde__m256i a) {
  #if defined(SIMDE_X86_AVX512VL_NATIVE) && defined(SIMDE_X86_AVX512CD_NATIVE)
    return _mm256_conflict_epi32(a);
  #else
    simde__m256i_private
      r_ = simde__m256i_to_private(simde_mm256_setzero_si256()),
      a_ = simde__m256i_to_private(a);

    for (size_t i = 1 ; i < (sizeof(r_.i32) / sizeof(r_.i32[0])) ; i++) {
      r_.i32[i] =
          simde_mm256_movemask_ps(
            simde_mm256_castsi256_ps(
              simde_mm256_cmpeq_epi32(simde_mm256_set1_epi32(a_.i32[i]), a)
            )
          ) & ((1 << i) - 1);
    }

    return simde__m256i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512CD_ENABLE_NATIVE_ALIASES)
  #undef _mm256_conflict_epi32
  #define _mm256_conflict_epi32(a) simde_mm256_conflict_epi32(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_mask_conflict_epi32 (simde__m256i src, simde__mmask8 k, simde__m256i a) {
  #if defined(SIMDE_X86_AVX512VL_NATIVE) && defined(SIMDE_X86_AVX512CD_NATIVE)
    return _mm256_mask_conflict_epi32(src, k, a);
  #else
    return simde_mm256_mask_mov_epi32(src, k, simde_mm256_conflict_epi32(a));
  #endif
}
#if defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512CD_ENABLE_NATIVE_ALIASES)
  #undef _mm256_mask_conflict_epi32
  #define _mm256_mask_conflict_epi32(src, k, a) simde_mm256_mask_conflict_epi32(src, k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_maskz_conflict_epi32 (simde__mmask8 k, simde__m256i a) {
  #if defined(SIMDE_X86_AVX512VL_NATIVE) && defined(SIMDE_X86_AVX512CD_NATIVE)
    return _mm256_maskz_conflict_epi32(k, a);
  #else
    return simde_mm256_maskz_mov_epi32(k, simde_mm256_conflict_epi32(a));
  #endif
}
#if defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512CD_ENABLE_NATIVE_ALIASES)
  #undef _mm256_maskz_conflict_epi32
  #define _mm256_maskz_conflict_epi32(k, a) simde_mm256_maskz_conflict_epi32(k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_conflict_epi32 (simde__m512i a) {
  #if defined(SIMDE_X86_AVX512CD_NATIVE)
    return _mm512_conflict_epi32(a);
  #else
    simde__m512i_private
      r_ = simde__m512i_to_private(simde_mm512_setzero_si512()),
      a_ = simde__m512i_to_private(a);

    for (size_t i = 1 ; i < (sizeof(r_.i32) / sizeof(r_.i32[0])) ; i++) {
      r_.i32[i] =
        HEDLEY_STATIC_CAST(
          int32_t,
          simde_mm512_cmpeq_epi32_mask(simde_mm512_set1_epi32(a_.i32[i]), a)
        ) & ((1 << i) - 1);
    }

    return simde__m512i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512CD_ENABLE_NATIVE_ALIASES)
  #undef _mm512_conflict_epi32
  #define _mm512_conflict_epi32(a) simde_mm512_conflict_epi32(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_mask_conflict_epi32 (simde__m512i src, simde__mmask16 k, simde__m512i a) {
  #if defined(SIMDE_X86_AVX512CD_NATIVE)
    return _mm512_mask_conflict_epi32(src, k, a);
  #else
    return simde_mm512_mask_mov_epi32(src, k, simde_mm512_conflict_epi32(a));
  #endif
}
#if defined(SIMDE_X86_AVX512CD_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_conflict_epi32
  #define _mm512_mask_conflict_epi32(src, k, a) simde_mm512_mask_conflict_epi32(src, k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_maskz_conflict_epi32 (simde__mmask16 k, simde__m512i a) {
  #if defined(SIMDE_X86_AVX512CD_NATIVE)
    return _mm512_maskz_conflict_epi32(k, a);
  #else
    return simde_mm512_maskz_mov_epi32(k, simde_mm512_conflict_epi32(a));
  #endif
}
#if defined(SIMDE_X86_AVX512CD_ENABLE_NATIVE_ALIASES)
  #undef _mm512_maskz_conflict_epi32
  #define _mm512_maskz_conflict_epi32(k, a) simde_mm512_maskz_conflict_epi32(k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_conflict_epi64 (simde__m128i a) {
  #if defined(SIMDE_X86_AVX512VL_NATIVE) && defined(SIMDE_X86_AVX512CD_NATIVE)
    return _mm_conflict_epi64(a);
  #else
    simde__m128i_private
      r_ = simde__m128i_to_private(simde_mm_setzero_si128()),
      a_ = simde__m128i_to_private(a);

    for (size_t i = 1 ; i < (sizeof(r_.i64) / sizeof(r_.i64[0])) ; i++) {
      r_.i64[i] =
        HEDLEY_STATIC_CAST(
          int64_t,
          simde_mm_movemask_pd(
            simde_mm_castsi128_pd(
              simde_mm_cmpeq_epi64(simde_mm_set1_epi64x(a_.i64[i]), a)
            )
          )
        ) & ((1 << i) - 1);
    }

    return simde__m128i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512CD_ENABLE_NATIVE_ALIASES)
  #undef _mm_conflict_epi64
  #define _mm_conflict_epi64(a) simde_mm_conflict_epi64(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_mask_conflict_epi64 (simde__m128i src, simde__mmask8 k, simde__m128i a) {
  #if defined(SIMDE_X86_AVX512VL_NATIVE) && defined(SIMDE_X86_AVX512CD_NATIVE)
    return _mm_mask_conflict_epi64(src, k, a);
  #else
    return simde_mm_mask_mov_epi64(src, k, simde_mm_conflict_epi64(a));
  #endif
}
#if defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512CD_ENABLE_NATIVE_ALIASES)
  #undef _mm_mask_conflict_epi64
  #define _mm_mask_conflict_epi64(src, k, a) simde_mm_mask_conflict_epi64(src, k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_maskz_conflict_epi64 (simde__mmask8 k, simde__m128i a) {
  #if defined(SIMDE_X86_AVX512VL_NATIVE) && defined(SIMDE_X86_AVX512CD_NATIVE)
    return _mm_maskz_conflict_epi64(k, a);
  #else
    return simde_mm_maskz_mov_epi64(k, simde_mm_conflict_epi64(a));
  #endif
}
#if defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512CD_ENABLE_NATIVE_ALIASES)
  #undef _mm_maskz_conflict_epi64
  #define _mm_maskz_conflict_epi64(k, a) simde_mm_maskz_conflict_epi64(k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_conflict_epi64 (simde__m256i a) {
  #if defined(SIMDE_X86_AVX512VL_NATIVE) && defined(SIMDE_X86_AVX512CD_NATIVE)
    return _mm256_conflict_epi64(a);
  #else
    simde__m256i_private
      r_ = simde__m256i_to_private(simde_mm256_setzero_si256()),
      a_ = simde__m256i_to_private(a);

    for (size_t i = 1 ; i < (sizeof(r_.i64) / sizeof(r_.i64[0])) ; i++) {
      r_.i64[i] =
        HEDLEY_STATIC_CAST(
          int64_t,
          simde_mm256_movemask_pd(
            simde_mm256_castsi256_pd(
              simde_mm256_cmpeq_epi64(simde_mm256_set1_epi64x(a_.i64[i]), a)
            )
          )
        ) & ((1 << i) - 1);
    }

    return simde__m256i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512CD_ENABLE_NATIVE_ALIASES)
  #undef _mm256_conflict_epi64
  #define _mm256_conflict_epi64(a) simde_mm256_conflict_epi64(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_mask_conflict_epi64 (simde__m256i src, simde__mmask8 k, simde__m256i a) {
  #if defined(SIMDE_X86_AVX512VL_NATIVE) && defined(SIMDE_X86_AVX512CD_NATIVE)
    return _mm256_mask_conflict_epi64(src, k, a);
  #else
    return simde_mm256_mask_mov_epi64(src, k, simde_mm256_conflict_epi64(a));
  #endif
}
#if defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512CD_ENABLE_NATIVE_ALIASES)
  #undef _mm256_mask_conflict_epi64
  #define _mm256_mask_conflict_epi64(src, k, a) simde_mm256_mask_conflict_epi64(src, k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_maskz_conflict_epi64 (simde__mmask8 k, simde__m256i a) {
  #if defined(SIMDE_X86_AVX512VL_NATIVE) && defined(SIMDE_X86_AVX512CD_NATIVE)
    return _mm256_maskz_conflict_epi64(k, a);
  #else
    return simde_mm256_maskz_mov_epi64(k, simde_mm256_conflict_epi64(a));
  #endif
}
#if defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512CD_ENABLE_NATIVE_ALIASES)
  #undef _mm256_maskz_conflict_epi64
  #define _mm256_maskz_conflict_epi64(k, a) simde_mm256_maskz_conflict_epi64(k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_conflict_epi64 (simde__m512i a) {
  #if defined(SIMDE_X86_AVX512CD_NATIVE)
    return _mm512_conflict_epi64(a);
  #else
    simde__m512i_private
      r_ = simde__m512i_to_private(simde_mm512_setzero_si512()),
      a_ = simde__m512i_to_private(a);

    for (size_t i = 1 ; i < (sizeof(r_.i64) / sizeof(r_.i64[0])) ; i++) {
      r_.i64[i] =
        HEDLEY_STATIC_CAST(
          int64_t,
          simde_mm512_cmpeq_epi64_mask(simde_mm512_set1_epi64(a_.i64[i]), a)
        ) & ((1 << i) - 1);
    }

    return simde__m512i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512CD_ENABLE_NATIVE_ALIASES)
  #undef _mm512_conflict_epi64
  #define _mm512_conflict_epi64(a) simde_mm512_conflict_epi64(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_mask_conflict_epi64 (simde__m512i src, simde__mmask8 k, simde__m512i a) {
  #if defined(SIMDE_X86_AVX512CD_NATIVE)
    return _mm512_mask_conflict_epi64(src, k, a);
  #else
    return simde_mm512_mask_mov_epi64(src, k, simde_mm512_conflict_epi64(a));
  #endif
}
#if defined(SIMDE_X86_AVX512CD_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_conflict_epi64
  #define _mm512_mask_conflict_epi64(src, k, a) simde_mm512_mask_conflict_epi64(src, k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_maskz_conflict_epi64 (simde__mmask8 k, simde__m512i a) {
  #if defined(SIMDE_X86_AVX512CD_NATIVE)
    return _mm512_maskz_conflict_epi64(k, a);
  #else
    return simde_mm512_maskz_mov_epi64(k, simde_mm512_conflict_epi64(a));
  #endif
}
#if defined(SIMDE_X86_AVX512CD_ENABLE_NATIVE_ALIASES)
  #undef _mm512_maskz_conflict_epi64
  #define _mm512_maskz_conflict_epi64(k, a) simde_mm512_maskz_conflict_epi64(k, a)
#endif

SIMDE_END_DECLS_
HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_X86_AVX512_CONFLICT_H) */
