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
 *   2020      Christopher Moore <moore@free.fr>
 */

#if !defined(SIMDE_X86_AVX512VL_H)
#define SIMDE_X86_AVX512VL_H

#include "avx512f.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_cvtsepi16_epi8 (simde__m128i a) {
  #if defined(SIMDE_X86_AVX512VL_NATIVE) && defined(SIMDE_X86_AVX512BW_NATIVE)
    return _mm_cvtsepi16_epi8(a);
  #else
    simde__m128i_private r_ = simde__m128i_to_private(simde_mm_setzero_si128());
    simde__m128i_private a_ = simde__m128i_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(a_.i16) / sizeof(a_.i16[0])) ; i++) {
      r_.i8[i] =
          (a_.i16[i] < INT8_MIN)
            ? (INT8_MIN)
            : ((a_.i16[i] > INT8_MAX)
              ? (INT8_MAX)
              : HEDLEY_STATIC_CAST(int8_t, a_.i16[i]));
    }

    return simde__m128i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm_cvtsepi16_epi8
  #define _mm_cvtsepi16_epi8(a) simde_mm_cvtsepi16_epi8(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm256_cvtsepi16_epi8 (simde__m256i a) {
  #if defined(SIMDE_X86_AVX512VL_NATIVE) && defined(SIMDE_X86_AVX512BW_NATIVE)
    return _mm256_cvtsepi16_epi8(a);
  #else
    simde__m128i_private r_;
    simde__m256i_private a_ = simde__m256i_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.i8) / sizeof(r_.i8[0])) ; i++) {
      r_.i8[i] =
          (a_.i16[i] < INT8_MIN)
            ? (INT8_MIN)
            : ((a_.i16[i] > INT8_MAX)
              ? (INT8_MAX)
              : HEDLEY_STATIC_CAST(int8_t, a_.i16[i]));
    }

    return simde__m128i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm256_cvtsepi16_epi8
  #define _mm256_cvtsepi16_epi8(a) simde_mm256_cvtsepi16_epi8(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_cvtsepi32_epi8 (simde__m128i a) {
  #if defined(SIMDE_X86_AVX512VL_NATIVE) && defined(SIMDE_X86_AVX512BW_NATIVE)
    return _mm_cvtsepi32_epi8(a);
  #else
    simde__m128i_private r_ = simde__m128i_to_private(simde_mm_setzero_si128());
    simde__m128i_private a_ = simde__m128i_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(a_.i32) / sizeof(a_.i32[0])) ; i++) {
      r_.i8[i] =
          (a_.i32[i] < INT8_MIN)
            ? (INT8_MIN)
            : ((a_.i32[i] > INT8_MAX)
              ? (INT8_MAX)
              : HEDLEY_STATIC_CAST(int8_t, a_.i32[i]));
    }

    return simde__m128i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm_cvtsepi32_epi8
  #define _mm_cvtsepi32_epi8(a) simde_mm_cvtsepi32_epi8(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm256_cvtsepi32_epi8 (simde__m256i a) {
  #if defined(SIMDE_X86_AVX512VL_NATIVE) && defined(SIMDE_X86_AVX512BW_NATIVE)
    return _mm256_cvtsepi32_epi8(a);
  #else
    simde__m128i_private r_ = simde__m128i_to_private(simde_mm_setzero_si128());
    simde__m256i_private a_ = simde__m256i_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(a_.i32) / sizeof(a_.i32[0])) ; i++) {
      r_.i8[i] =
          (a_.i32[i] < INT8_MIN)
            ? (INT8_MIN)
            : ((a_.i32[i] > INT8_MAX)
              ? (INT8_MAX)
              : HEDLEY_STATIC_CAST(int8_t, a_.i32[i]));
    }

    return simde__m128i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm256_cvtsepi32_epi8
  #define _mm256_cvtsepi32_epi8(a) simde_mm256_cvtsepi32_epi8(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_cvtsepi32_epi16 (simde__m128i a) {
  #if defined(SIMDE_X86_AVX512VL_NATIVE) && defined(SIMDE_X86_AVX512BW_NATIVE)
    return _mm_cvtsepi32_epi16(a);
  #else
    simde__m128i_private r_ = simde__m128i_to_private(simde_mm_setzero_si128());
    simde__m128i_private a_ = simde__m128i_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(a_.i32) / sizeof(a_.i32[0])) ; i++) {
      r_.i16[i] =
          (a_.i32[i] < INT16_MIN)
            ? (INT16_MIN)
            : ((a_.i32[i] > INT16_MAX)
              ? (INT16_MAX)
              : HEDLEY_STATIC_CAST(int16_t, a_.i32[i]));
    }

    return simde__m128i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm_cvtsepi32_epi16
  #define _mm_cvtsepi32_epi16(a) simde_mm_cvtsepi32_epi16(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm256_cvtsepi32_epi16 (simde__m256i a) {
  #if defined(SIMDE_X86_AVX512VL_NATIVE) && defined(SIMDE_X86_AVX512BW_NATIVE)
    return _mm256_cvtsepi32_epi16(a);
  #else
    simde__m128i_private r_ = simde__m128i_to_private(simde_mm_setzero_si128());
    simde__m256i_private a_ = simde__m256i_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(a_.i32) / sizeof(a_.i32[0])) ; i++) {
      r_.i16[i] =
          (a_.i32[i] < INT16_MIN)
            ? (INT16_MIN)
            : ((a_.i32[i] > INT16_MAX)
              ? (INT16_MAX)
              : HEDLEY_STATIC_CAST(int16_t, a_.i32[i]));
    }

    return simde__m128i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm256_cvtsepi32_epi16
  #define _mm256_cvtsepi32_epi16(a) simde_mm256_cvtsepi32_epi16(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_cvtsepi64_epi8 (simde__m128i a) {
  #if defined(SIMDE_X86_AVX512VL_NATIVE) && defined(SIMDE_X86_AVX512BW_NATIVE)
    return _mm_cvtsepi64_epi8(a);
  #else
    simde__m128i_private r_ = simde__m128i_to_private(simde_mm_setzero_si128());
    simde__m128i_private a_ = simde__m128i_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(a_.i64) / sizeof(a_.i64[0])) ; i++) {
      r_.i8[i] =
          (a_.i64[i] < INT8_MIN)
            ? (INT8_MIN)
            : ((a_.i64[i] > INT8_MAX)
              ? (INT8_MAX)
              : HEDLEY_STATIC_CAST(int8_t, a_.i64[i]));
    }

    return simde__m128i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm_cvtsepi64_epi8
  #define _mm_cvtsepi64_epi8(a) simde_mm_cvtsepi64_epi8(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm256_cvtsepi64_epi8 (simde__m256i a) {
  #if defined(SIMDE_X86_AVX512VL_NATIVE) && defined(SIMDE_X86_AVX512BW_NATIVE)
    return _mm256_cvtsepi64_epi8(a);
  #else
    simde__m128i_private r_ = simde__m128i_to_private(simde_mm_setzero_si128());
    simde__m256i_private a_ = simde__m256i_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(a_.i64) / sizeof(a_.i64[0])) ; i++) {
      r_.i8[i] =
          (a_.i64[i] < INT8_MIN)
            ? (INT8_MIN)
            : ((a_.i64[i] > INT8_MAX)
              ? (INT8_MAX)
              : HEDLEY_STATIC_CAST(int8_t, a_.i64[i]));
    }

    return simde__m128i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm256_cvtsepi64_epi8
  #define _mm256_cvtsepi64_epi8(a) simde_mm256_cvtsepi64_epi8(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_mask_abs_epi8(simde__m128i src, simde__mmask16 k, simde__m128i a) {
  #if defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm_mask_abs_epi8(src, k, a);
  #else
    return simde_mm_mask_mov_epi8(src, k, simde_mm_abs_epi8(a));
  #endif
}
#if defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm_mask_abs_epi8
  #define _mm_mask_abs_epi8(src, k, a) simde_mm_mask_abs_epi8(src, k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_maskz_abs_epi8(simde__mmask16 k, simde__m128i a) {
  #if defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm_maskz_abs_epi8(k, a);
  #else
    return simde_mm_maskz_mov_epi8(k, simde_mm_abs_epi8(a));
  #endif
}
#if defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm_maskz_abs_epi8
  #define _mm_maskz_abs_epi8(k, a) simde_mm_maskz_abs_epi8(k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_mask_abs_epi16(simde__m128i src, simde__mmask8 k, simde__m128i a) {
  #if defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm_mask_abs_epi16(src, k, a);
  #else
    return simde_mm_mask_mov_epi16(src, k, simde_mm_abs_epi16(a));
  #endif
}
#if defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm_mask_abs_epi16
  #define _mm_mask_abs_epi16(src, k, a) simde_mm_mask_abs_epi16(src, k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_maskz_abs_epi16(simde__mmask8 k, simde__m128i a) {
  #if defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm_maskz_abs_epi16(k, a);
  #else
    return simde_mm_maskz_mov_epi16(k, simde_mm_abs_epi16(a));
  #endif
}
#if defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm_maskz_abs_epi16
  #define _mm_maskz_abs_epi16(k, a) simde_mm_maskz_abs_epi16(k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_mask_abs_epi32(simde__m128i src, simde__mmask8 k, simde__m128i a) {
  #if defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm_mask_abs_epi32(src, k, a);
  #else
    return simde_mm_mask_mov_epi32(src, k, simde_mm_abs_epi32(a));
  #endif
}
#if defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm_mask_abs_epi32
  #define _mm_mask_abs_epi32(src, k, a) simde_mm_mask_abs_epi32(src, k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_maskz_abs_epi32(simde__mmask8 k, simde__m128i a) {
  #if defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm_maskz_abs_epi32(k, a);
  #else
    return simde_mm_maskz_mov_epi32(k, simde_mm_abs_epi32(a));
  #endif
}
#if defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm_maskz_abs_epi32
  #define _mm_maskz_abs_epi32(k, a) simde_mm_maskz_abs_epi32(k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_abs_epi64(simde__m128i a) {
  #if defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm_abs_epi64(a);
  #else
    simde__m128i_private
      r_,
      a_ = simde__m128i_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0; i < (sizeof(r_.i64) / sizeof(r_.i64[0])); i++) {
      r_.i64[i] = (a_.i64[i] < INT64_C(0)) ? -a_.i64[i] : a_.i64[i];
    }

    return simde__m128i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm_abs_epi64
  #define _mm_abs_epi64(a) simde_mm_abs_epi64(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_mask_abs_epi64(simde__m128i src, simde__mmask8 k, simde__m128i a) {
  #if defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm_mask_abs_epi64(src, k, a);
  #else
    return simde_mm_mask_mov_epi64(src, k, simde_mm_abs_epi64(a));
  #endif
}
#if defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm_mask_abs_epi64
  #define _mm_mask_abs_epi64(src, k, a) simde_mm_mask_abs_epi64(src, k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_maskz_abs_epi64(simde__mmask8 k, simde__m128i a) {
  #if defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm_maskz_abs_epi64(k, a);
  #else
    return simde_mm_maskz_mov_epi64(k, simde_mm_abs_epi64(a));
  #endif
}
#if defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm_maskz_abs_epi64
  #define _mm_maskz_abs_epi64(k, a) simde_mm_maskz_abs_epi64(k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_abs_epi64(simde__m256i a) {
  #if defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm256_abs_epi64(a);
  #else
    simde__m256i_private
      r_,
      a_ = simde__m256i_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0; i < (sizeof(r_.i64) / sizeof(r_.i64[0])); i++) {
      r_.i64[i] = (a_.i64[i] < INT64_C(0)) ? -a_.i64[i] : a_.i64[i];
    }

    return simde__m256i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm256_abs_epi64
  #define _mm256_abs_epi64(a) simde_mm256_abs_epi64(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_mask_abs_epi64(simde__m256i src, simde__mmask8 k, simde__m256i a) {
  #if defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm256_mask_abs_epi64(src, k, a);
  #else
    return simde_mm256_mask_mov_epi64(src, k, simde_mm256_abs_epi64(a));
  #endif
}
#if defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm256_mask_abs_epi64
  #define _mm256_mask_abs_epi64(src, k, a) simde_mm256_mask_abs_epi64(src, k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_maskz_abs_epi64(simde__mmask8 k, simde__m256i a) {
  #if defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm256_maskz_abs_epi64(k, a);
  #else
    return simde_mm256_maskz_mov_epi64(k, simde_mm256_abs_epi64(a));
  #endif
}
#if defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm256_maskz_abs_epi64
  #define _mm256_maskz_abs_epi64(k, a) simde_mm256_maskz_abs_epi64(k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_mask_add_epi8(simde__m128i src, simde__mmask16 k, simde__m128i a, simde__m128i b) {
  #if defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm_mask_add_epi8(src, k, a, b);
  #else
    return simde_mm_mask_mov_epi8(src, k, simde_mm_add_epi8(a, b));
  #endif
}
#if defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm_mask_add_epi8
  #define _mm_mask_add_epi8(src, k, a, b) simde_mm_mask_add_epi8(src, k, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_maskz_add_epi8(simde__mmask16 k, simde__m128i a, simde__m128i b) {
  #if defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm_maskz_add_epi8(k, a, b);
  #else
    return simde_mm_maskz_mov_epi8(k, simde_mm_add_epi8(a, b));
  #endif
}
#if defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm_maskz_add_epi8
  #define _mm_maskz_add_epi8(k, a, b) simde_mm_maskz_add_epi8(k, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_mask_add_epi16(simde__m128i src, simde__mmask8 k, simde__m128i a, simde__m128i b) {
  #if defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm_mask_add_epi16(src, k, a, b);
  #else
    return simde_mm_mask_mov_epi16(src, k, simde_mm_add_epi16(a, b));
  #endif
}
#if defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm_mask_add_epi16
  #define _mm_mask_add_epi16(src, k, a, b) simde_mm_mask_add_epi16(src, k, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_maskz_add_epi16(simde__mmask8 k, simde__m128i a, simde__m128i b) {
  #if defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm_maskz_add_epi16(k, a, b);
  #else
    return simde_mm_maskz_mov_epi16(k, simde_mm_add_epi16(a, b));
  #endif
}
#if defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm_maskz_add_epi16
  #define _mm_maskz_add_epi16(k, a, b) simde_mm_maskz_add_epi16(k, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_mask_add_epi32(simde__m128i src, simde__mmask8 k, simde__m128i a, simde__m128i b) {
  #if defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm_mask_add_epi32(src, k, a, b);
  #else
    return simde_mm_mask_mov_epi32(src, k, simde_mm_add_epi32(a, b));
  #endif
}
#if defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm_mask_add_epi32
  #define _mm_mask_add_epi32(src, k, a, b) simde_mm_mask_add_epi32(src, k, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_maskz_add_epi32(simde__mmask8 k, simde__m128i a, simde__m128i b) {
  #if defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm_maskz_add_epi32(k, a, b);
  #else
    return simde_mm_maskz_mov_epi32(k, simde_mm_add_epi32(a, b));
  #endif
}
#if defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm_maskz_add_epi32
  #define _mm_maskz_add_epi32(k, a, b) simde_mm_maskz_add_epi32(k, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_mask_add_epi64(simde__m128i src, simde__mmask8 k, simde__m128i a, simde__m128i b) {
  #if defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm_mask_add_epi64(src, k, a, b);
  #else
    return simde_mm_mask_mov_epi64(src, k, simde_mm_add_epi64(a, b));
  #endif
}
#if defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm_mask_add_epi64
  #define _mm_mask_add_epi64(src, k, a, b) simde_mm_mask_add_epi64(src, k, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_maskz_add_epi64(simde__mmask8 k, simde__m128i a, simde__m128i b) {
  #if defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm_maskz_add_epi64(k, a, b);
  #else
    return simde_mm_maskz_mov_epi64(k, simde_mm_add_epi64(a, b));
  #endif
}
#if defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm_maskz_add_epi64
  #define _mm_maskz_add_epi64(k, a, b) simde_mm_maskz_add_epi64(k, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_mask_add_epi16(simde__m256i src, simde__mmask16 k, simde__m256i a, simde__m256i b) {
  #if defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm256_mask_add_epi16(src, k, a, b);
  #else
    return simde_mm256_mask_mov_epi16(src, k, simde_mm256_add_epi16(a, b));
  #endif
}
#if defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm256_mask_add_epi16
  #define _mm256_mask_add_epi16(src, k, a, b) simde_mm256_mask_add_epi16(src, k, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_maskz_add_epi16(simde__mmask16 k, simde__m256i a, simde__m256i b) {
  #if defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm256_maskz_add_epi16(k, a, b);
  #else
    return simde_mm256_maskz_mov_epi16(k, simde_mm256_add_epi16(a, b));
  #endif
}
#if defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm256_maskz_add_epi16
  #define _mm256_maskz_add_epi16(k, a, b) simde_mm256_maskz_add_epi16(k, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_mask_add_epi32(simde__m256i src, simde__mmask8 k, simde__m256i a, simde__m256i b) {
  #if defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm256_mask_add_epi32(src, k, a, b);
  #else
    return simde_mm256_mask_mov_epi32(src, k, simde_mm256_add_epi32(a, b));
  #endif
}
#if defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm256_mask_add_epi32
  #define _mm256_mask_add_epi32(src, k, a, b) simde_mm256_mask_add_epi32(src, k, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_maskz_add_epi32(simde__mmask8 k, simde__m256i a, simde__m256i b) {
  #if defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm256_maskz_add_epi32(k, a, b);
  #else
    return simde_mm256_maskz_mov_epi32(k, simde_mm256_add_epi32(a, b));
  #endif
}
#if defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm256_maskz_add_epi32
  #define _mm256_maskz_add_epi32(k, a, b) simde_mm256_maskz_add_epi32(k, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_mask_add_epi64(simde__m256i src, simde__mmask8 k, simde__m256i a, simde__m256i b) {
  #if defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm256_mask_add_epi64(src, k, a, b);
  #else
    return simde_mm256_mask_mov_epi64(src, k, simde_mm256_add_epi64(a, b));
  #endif
}
#if defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm256_mask_add_epi64
  #define _mm256_mask_add_epi64(src, k, a, b) simde_mm256_mask_add_epi64(src, k, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_maskz_add_epi64(simde__mmask8 k, simde__m256i a, simde__m256i b) {
  #if defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm256_maskz_add_epi64(k, a, b);
  #else
    return simde_mm256_maskz_mov_epi64(k, simde_mm256_add_epi64(a, b));
  #endif
}
#if defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm256_maskz_add_epi64
  #define _mm256_maskz_add_epi64(k, a, b) simde_mm256_maskz_add_epi64(k, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_mask_adds_epi8(simde__m128i src, simde__mmask16 k, simde__m128i a, simde__m128i b) {
  #if defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm_mask_adds_epi8(src, k, a, b);
  #else
    return simde_mm_mask_mov_epi8(src, k, simde_mm_adds_epi8(a, b));
  #endif
}
#if defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm_mask_adds_epi8
  #define _mm_mask_adds_epi8(src, k, a, b) simde_mm_mask_adds_epi8(src, k, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_maskz_adds_epi8(simde__mmask16 k, simde__m128i a, simde__m128i b) {
  #if defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm_maskz_adds_epi8(k, a, b);
  #else
    return simde_mm_maskz_mov_epi8(k, simde_mm_adds_epi8(a, b));
  #endif
}
#if defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm_maskz_adds_epi8
  #define _mm_maskz_adds_epi8(k, a, b) simde_mm_maskz_adds_epi8(k, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_mask_adds_epi16(simde__m128i src, simde__mmask8 k, simde__m128i a, simde__m128i b) {
  #if defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm_mask_adds_epi16(src, k, a, b);
  #else
    return simde_mm_mask_mov_epi16(src, k, simde_mm_adds_epi16(a, b));
  #endif
}
#if defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm_mask_adds_epi16
  #define _mm_mask_adds_epi16(src, k, a, b) simde_mm_mask_adds_epi16(src, k, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_maskz_adds_epi16(simde__mmask8 k, simde__m128i a, simde__m128i b) {
  #if defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm_maskz_adds_epi16(k, a, b);
  #else
    return simde_mm_maskz_mov_epi16(k, simde_mm_adds_epi16(a, b));
  #endif
}
#if defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm_maskz_adds_epi16
  #define _mm_maskz_adds_epi16(k, a, b) simde_mm_maskz_adds_epi16(k, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_mask_adds_epi8(simde__m256i src, simde__mmask32 k, simde__m256i a, simde__m256i b) {
  #if defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm256_mask_adds_epi8(src, k, a, b);
  #else
    return simde_mm256_mask_mov_epi8(src, k, simde_mm256_adds_epi8(a, b));
  #endif
}
#if defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm256_mask_adds_epi8
  #define _mm256_mask_adds_epi8(src, k, a, b) simde_mm256_mask_adds_epi8(src, k, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_maskz_adds_epi8(simde__mmask32 k, simde__m256i a, simde__m256i b) {
  #if defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm256_maskz_adds_epi8(k, a, b);
  #else
    return simde_mm256_maskz_mov_epi8(k, simde_mm256_adds_epi8(a, b));
  #endif
}
#if defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm256_maskz_adds_epi8
  #define _mm256_maskz_adds_epi8(k, a, b) simde_mm256_maskz_adds_epi8(k, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_mask_adds_epi16(simde__m256i src, simde__mmask16 k, simde__m256i a, simde__m256i b) {
  #if defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm256_mask_adds_epi16(src, k, a, b);
  #else
    return simde_mm256_mask_mov_epi16(src, k, simde_mm256_adds_epi16(a, b));
  #endif
}
#if defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm256_mask_adds_epi16
  #define _mm256_mask_adds_epi16(src, k, a, b) simde_mm256_mask_adds_epi16(src, k, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_maskz_adds_epi16(simde__mmask16 k, simde__m256i a, simde__m256i b) {
  #if defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm256_maskz_adds_epi16(k, a, b);
  #else
    return simde_mm256_maskz_mov_epi16(k, simde_mm256_adds_epi16(a, b));
  #endif
}
#if defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm256_maskz_adds_epi16
  #define _mm256_maskz_adds_epi16(k, a, b) simde_mm256_maskz_adds_epi16(k, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256
simde_mm256_broadcast_f32x4 (simde__m128 a) {
  #if defined(SIMDE_X86_AVX512DQ_NATIVE)
    return _mm256_broadcast_f32x4(a);
  #else
    simde__m256_private r_;
    simde__m128_private a_ = simde__m128_to_private(a);

    #if SIMDE_NATURAL_VECTOR_SIZE_LE(128)
        r_.m128_private[0] = a_;
        r_.m128_private[1] = a_;
    #elif defined(SIMDE_VECTOR_SUBSCRIPT) && HEDLEY_HAS_BUILTIN(__builtin_shufflevector)
      r_.f32 = __builtin_shufflevector(a_.f32, a_.f32, 0, 1, 2, 3, 0, 1, 2, 3);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.f32) / sizeof(r_.f32[0])) ; i += 4) {
         r_.f32[  i  ] = a_.f32[0];
         r_.f32[i + 1] = a_.f32[1];
         r_.f32[i + 2] = a_.f32[2];
         r_.f32[i + 3] = a_.f32[3];
      }
    #endif

    return simde__m256_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512DQ_ENABLE_NATIVE_ALIASES)
  #undef _mm256_broadcast_f32x4
  #define _mm256_broadcast_f32x4(a) simde_mm256_broadcast_f32x4(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256
simde_mm256_mask_broadcast_f32x4(simde__m256 src, simde__mmask8 k, simde__m128 a) {
  #if defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm256_mask_broadcast_f32x4(src, k, a);
  #else
    return simde_mm256_mask_mov_ps(src, k, simde_mm256_broadcast_f32x4(a));
  #endif
}
#if defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm256_mask_broadcast_f32x4
  #define _mm256_mask_broadcast_f32x4(src, k, a) simde_mm256_mask_broadcast_f32x4(src, k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256
simde_mm256_maskz_broadcast_f32x4(simde__mmask8 k, simde__m128 a) {
  #if defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm256_maskz_broadcast_f32x4(k, a);
  #else
    return simde_mm256_maskz_mov_ps(k, simde_mm256_broadcast_f32x4(a));
  #endif
}
#if defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm256_maskz_broadcast_f32x4
  #define _mm256_maskz_broadcast_f32x4(k, a) simde_mm256_maskz_broadcast_f32x4(k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256d
simde_mm256_broadcast_f64x2 (simde__m128d a) {
  #if defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm256_broadcast_f64x2(a);
  #else
    simde__m256d_private r_;
    simde__m128d_private a_ = simde__m128d_to_private(a);

    /* I don't have a bug # for this, but when compiled with clang-10 without optimization on aarch64
     * the __builtin_shufflevector version doesn't work correctly.  clang 9 and 11 aren't a problem */
    #if defined(SIMDE_VECTOR_SUBSCRIPT) && HEDLEY_HAS_BUILTIN(__builtin_shufflevector) && \
        (!defined(__clang__) || (SIMDE_DETECT_CLANG_VERSION < 100000 || SIMDE_DETECT_CLANG_VERSION > 100000))
      r_.f64 = __builtin_shufflevector(a_.f64, a_.f64, 0, 1, 0, 1);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.f64) / sizeof(r_.f64[0])) ; i += 2) {
         r_.f64[  i  ] = a_.f64[0];
         r_.f64[i + 1] = a_.f64[1];
      }
    #endif

    return simde__m256d_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm256_broadcast_f64x2
  #define _mm256_broadcast_f64x2(a) simde_mm256_broadcast_f64x2(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256d
simde_mm256_mask_broadcast_f64x2(simde__m256d src, simde__mmask8 k, simde__m128d a) {
  #if defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm256_mask_broadcast_f64x2(src, k, a);
  #else
    return simde_mm256_mask_mov_pd(src, k, simde_mm256_broadcast_f64x2(a));
  #endif
}
#if defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm256_mask_broadcast_f64x2
  #define _mm256_mask_broadcast_f64x2(src, k, a) simde_mm256_mask_broadcast_f64x2(src, k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256d
simde_mm256_maskz_broadcast_f64x2(simde__mmask8 k, simde__m128d a) {
  #if defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm256_maskz_broadcast_f64x2(k, a);
  #else
    return simde_mm256_maskz_mov_pd(k, simde_mm256_broadcast_f64x2(a));
  #endif
}
#if defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm256_maskz_broadcast_f64x2
  #define _mm256_maskz_broadcast_f64x2(k, a) simde_mm256_maskz_broadcast_f64x2(k, a)
#endif

SIMDE_END_DECLS_

HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_X86_AVX512VL_H) */
