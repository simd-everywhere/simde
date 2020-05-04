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

#if !defined(SIMDE_X86_AVX512VL_H)
#define SIMDE_X86_AVX512VL_H

#include "avx512bw.h"

#if !defined(SIMDE_X86_AVX512VL_NATIVE) && defined(SIMDE_ENABLE_NATIVE_ALIASES)
#  define SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES
#endif

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE__BEGIN_DECLS

SIMDE__FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_mask_mov_epi8(simde__m128i src, simde__mmask16 k, simde__m128i a) {
  #if defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm_mask_mov_epi8(src, k, a);
  #else
    simde__m128i_private
      src_ = simde__m128i_to_private(src),
      a_ = simde__m128i_to_private(a),
      r_;

    SIMDE__VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.i8) / sizeof(r_.i8[0])) ; i++) {
      r_.i8[i] = ((k >> i) & 1) ? a_.i8[i] : src_.i8[i];
    }

    return simde__m128i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #define _mm_mask_mov_epi8(src, k, a) simde_mm_mask_mov_epi8(src, k, a)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_mask_mov_epi16(simde__m128i src, simde__mmask8 k, simde__m128i a) {
  #if defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm_mask_mov_epi16(src, k, a);
  #else
    simde__m128i_private
      src_ = simde__m128i_to_private(src),
      a_ = simde__m128i_to_private(a),
      r_;

    SIMDE__VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.i16) / sizeof(r_.i16[0])) ; i++) {
      r_.i16[i] = ((k >> i) & 1) ? a_.i16[i] : src_.i16[i];
    }

    return simde__m128i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #define _mm_mask_mov_epi16(src, k, a) simde_mm_mask_mov_epi16(src, k, a)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_mask_mov_epi32(simde__m128i src, simde__mmask8 k, simde__m128i a) {
  #if defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm_mask_mov_epi32(src, k, a);
  #else
    simde__m128i_private
      src_ = simde__m128i_to_private(src),
      a_ = simde__m128i_to_private(a),
      r_;

    SIMDE__VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.i32) / sizeof(r_.i32[0])) ; i++) {
      r_.i32[i] = ((k >> i) & 1) ? a_.i32[i] : src_.i32[i];
    }

    return simde__m128i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #define _mm_mask_mov_epi32(src, k, a) simde_mm_mask_mov_epi32(src, k, a)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_mask_mov_epi64(simde__m128i src, simde__mmask8 k, simde__m128i a) {
  #if defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm_mask_mov_epi64(src, k, a);
  #else
    simde__m128i_private
      src_ = simde__m128i_to_private(src),
      a_ = simde__m128i_to_private(a),
      r_;

    SIMDE__VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.i64) / sizeof(r_.i64[0])) ; i++) {
      r_.i64[i] = ((k >> i) & 1) ? a_.i64[i] : src_.i64[i];
    }

    return simde__m128i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #define _mm_mask_mov_epi64(src, k, a) simde_mm_mask_mov_epi64(src, k, a)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_maskz_mov_epi8(simde__mmask16 k, simde__m128i a) {
  #if defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm_maskz_mov_epi8(k, a);
  #else
    simde__m128i_private
      a_ = simde__m128i_to_private(a),
      r_;

    SIMDE__VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.i8) / sizeof(r_.i8[0])) ; i++) {
      r_.i8[i] = ((k >> i) & 1) ? a_.i8[i] : INT8_C(0);
    }

    return simde__m128i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #define _mm_maskz_mov_epi8(k, a) simde_mm_maskz_mov_epi8(k, a)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_maskz_mov_epi16(simde__mmask8 k, simde__m128i a) {
  #if defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm_maskz_mov_epi16(k, a);
  #else
    simde__m128i_private
      a_ = simde__m128i_to_private(a),
      r_;

    SIMDE__VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.i16) / sizeof(r_.i16[0])) ; i++) {
      r_.i16[i] = ((k >> i) & 1) ? a_.i16[i] : INT16_C(0);
    }

    return simde__m128i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #define _mm_maskz_mov_epi16(k, a) simde_mm_maskz_mov_epi16(k, a)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_maskz_mov_epi32(simde__mmask8 k, simde__m128i a) {
  #if defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm_maskz_mov_epi32(k, a);
  #else
    simde__m128i_private
      a_ = simde__m128i_to_private(a),
      r_;

    SIMDE__VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.i32) / sizeof(r_.i32[0])) ; i++) {
      r_.i32[i] = ((k >> i) & 1) ? a_.i32[i] : INT32_C(0);
    }

    return simde__m128i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #define _mm_maskz_mov_epi32(k, a) simde_mm_maskz_mov_epi32(k, a)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_maskz_mov_epi64(simde__mmask8 k, simde__m128i a) {
  #if defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm_maskz_mov_epi64(k, a);
  #else
    simde__m128i_private
      a_ = simde__m128i_to_private(a),
      r_;

    SIMDE__VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.i64) / sizeof(r_.i64[0])) ; i++) {
      r_.i64[i] = ((k >> i) & 1) ? a_.i64[i] : INT64_C(0);
    }

    return simde__m128i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #define _mm_maskz_mov_epi64(k, a) simde_mm_maskz_mov_epi64(k, a)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_mask_mov_epi8 (simde__m256i src, simde__mmask32 k, simde__m256i a) {
  simde__m256i_private
    r_,
    src_ = simde__m256i_to_private(src),
    a_ = simde__m256i_to_private(a);

  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.i8) / sizeof(r_.i8[0])) ; i++) {
    r_.i8[i] = ((k >> i) & 1) ? a_.i8[i] : src_.i8[i];
  }

  return simde__m256i_from_private(r_);
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES) && defined(SIMDE_AVX512BW_NATIVE)
  #define simde_mm256_mask_mov_epi8(src, k, a) _mm256_mask_mov_epi8(src, k, a)
#endif
#if defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #define _mm256_mask_mov_epi8(src, k, a) simde_mm256_mask_mov_epi8(src, k, a)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_mask_mov_epi32(simde__m256i src, simde__mmask8 k, simde__m256i a) {
  #if defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm256_mask_mov_epi32(src, k, a);
  #else
    simde__m256i_private
      src_ = simde__m256i_to_private(src),
      a_ = simde__m256i_to_private(a),
      r_;

    SIMDE__VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.i32) / sizeof(r_.i32[0])) ; i++) {
      r_.i32[i] = ((k >> i) & 1) ? a_.i32[i] : src_.i32[i];
    }

    return simde__m256i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #define _mm256_mask_mov_epi32(src, k, a) simde_mm256_mask_mov_epi32(src, k, a)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_mask_mov_epi64(simde__m256i src, simde__mmask8 k, simde__m256i a) {
  #if defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm256_mask_mov_epi64(src, k, a);
  #else
    simde__m256i_private
      src_ = simde__m256i_to_private(src),
      a_ = simde__m256i_to_private(a),
      r_;

    SIMDE__VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.i64) / sizeof(r_.i64[0])) ; i++) {
      r_.i64[i] = ((k >> i) & 1) ? a_.i64[i] : src_.i64[i];
    }

    return simde__m256i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #define _mm256_mask_mov_epi64(src, k, a) simde_mm256_mask_mov_epi64(src, k, a)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m256
simde_mm256_mask_mov_ps(simde__m256 src, simde__mmask8 k, simde__m256 a) {
  #if defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm256_mask_mov_ps(src, k, a);
  #else
    simde__m256_private
      src_ = simde__m256_to_private(src),
      a_ = simde__m256_to_private(a),
      r_;

    SIMDE__VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f32) / sizeof(r_.f32[0])) ; i++) {
      r_.f32[i] = ((k >> i) & 1) ? a_.f32[i] : src_.f32[i];
    }

    return simde__m256_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #define _mm256_mask_mov_ps(src, k, a) simde_mm256_mask_mov_ps(src, k, a)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m256d
simde_mm256_mask_mov_pd(simde__m256d src, simde__mmask8 k, simde__m256d a) {
  #if defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm256_mask_mov_pd(src, k, a);
  #else
    simde__m256d_private
      src_ = simde__m256d_to_private(src),
      a_ = simde__m256d_to_private(a),
      r_;

    SIMDE__VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f64) / sizeof(r_.f64[0])) ; i++) {
      r_.f64[i] = ((k >> i) & 1) ? a_.f64[i] : src_.f64[i];
    }

    return simde__m256d_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #define _mm256_mask_mov_pd(src, k, a) simde_mm256_mask_mov_pd(src, k, a)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_maskz_mov_epi8 (simde__mmask32 k, simde__m256i a) {
  simde__m256i_private
    r_,
    a_ = simde__m256i_to_private(a);

  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.i8) / sizeof(r_.i8[0])) ; i++) {
    r_.i8[i] = ((k >> i) & 1) ? a_.i8[i] : INT8_C(0);
  }

  return simde__m256i_from_private(r_);
}
#if defined(SIMDE_X86_AVX512VL_NATIVE) && defined(SIMDE_AVX512BW_NATIVE)
  #define simde_mm256_maskz_mov_epi8(k, a) _mm256_maskz_mov_epi8(k, a)
#endif
#if defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #define _mm256_maskz_mov_epi8(k, a) simde_mm256_maskz_mov_epi8(k, a)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_maskz_mov_epi32(simde__mmask8 k, simde__m256i a) {
  #if defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm256_maskz_mov_epi32(k, a);
  #else
    simde__m256i_private
      a_ = simde__m256i_to_private(a),
      r_;

    SIMDE__VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.i32) / sizeof(r_.i32[0])) ; i++) {
      r_.i32[i] = ((k >> i) & 1) ? a_.i32[i] : INT32_C(0);
    }

    return simde__m256i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #define _mm256_maskz_mov_epi32(k, a) simde_mm256_maskz_mov_epi32(k, a)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_maskz_mov_epi64(simde__mmask8 k, simde__m256i a) {
  #if defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm256_maskz_mov_epi64(k, a);
  #else
    simde__m256i_private
      a_ = simde__m256i_to_private(a),
      r_;

    SIMDE__VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.i64) / sizeof(r_.i64[0])) ; i++) {
      r_.i64[i] = ((k >> i) & 1) ? a_.i64[i] : INT64_C(0);
    }

    return simde__m256i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #define _mm256_maskz_mov_epi64(k, a) simde_mm256_maskz_mov_epi64(k, a)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m256
simde_mm256_maskz_mov_ps(simde__mmask8 k, simde__m256 a) {
  #if defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm256_maskz_mov_ps(k, a);
  #else
    simde__m256_private
      a_ = simde__m256_to_private(a),
      r_;

    SIMDE__VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f32) / sizeof(r_.f32[0])) ; i++) {
      r_.f32[i] = ((k >> i) & 1) ? a_.f32[i] : SIMDE_FLOAT32_C(0.0);
    }

    return simde__m256_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #define _mm256_maskz_mov_ps(k, a) simde_mm256_maskz_mov_ps(k, a)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m256d
simde_mm256_maskz_mov_pd(simde__mmask8 k, simde__m256d a) {
  #if defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm256_maskz_mov_pd(k, a);
  #else
    simde__m256d_private
      a_ = simde__m256d_to_private(a),
      r_;

    SIMDE__VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f64) / sizeof(r_.f64[0])) ; i++) {
      r_.f64[i] = ((k >> i) & 1) ? a_.f64[i] : SIMDE_FLOAT64_C(0.0);
    }

    return simde__m256d_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #define _mm256_maskz_mov_pd(k, a) simde_mm256_maskz_mov_pd(k, a)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_cvtsepi16_epi8 (simde__m128i a) {
  #if defined(SIMDE_X86_AVX512VL_NATIVE) && defined(SIMDE_X86_AVX512BW_NATIVE)
    return _mm_cvtsepi16_epi8(a);
  #else
    simde__m128i_private r_ = simde__m128i_to_private(simde_mm_setzero_si128());
    simde__m128i_private a_ = simde__m128i_to_private(a);

    SIMDE__VECTORIZE
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
  #define _mm_cvtsepi16_epi8(a) simde_mm_cvtsepi16_epi8(a)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128i
simde_mm256_cvtsepi16_epi8 (simde__m256i a) {
  #if defined(SIMDE_X86_AVX512VL_NATIVE) && defined(SIMDE_X86_AVX512BW_NATIVE)
    return _mm256_cvtsepi16_epi8(a);
  #else
    simde__m128i_private r_;
    simde__m256i_private a_ = simde__m256i_to_private(a);

    SIMDE__VECTORIZE
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
  #define _mm256_cvtsepi16_epi8(a) simde_mm256_cvtsepi16_epi8(a)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_cvtsepi32_epi8 (simde__m128i a) {
  #if defined(SIMDE_X86_AVX512VL_NATIVE) && defined(SIMDE_X86_AVX512BW_NATIVE)
    return _mm_cvtsepi32_epi8(a);
  #else
    simde__m128i_private r_ = simde__m128i_to_private(simde_mm_setzero_si128());
    simde__m128i_private a_ = simde__m128i_to_private(a);

    SIMDE__VECTORIZE
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
  #define _mm_cvtsepi32_epi8(a) simde_mm_cvtsepi32_epi8(a)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128i
simde_mm256_cvtsepi32_epi8 (simde__m256i a) {
  #if defined(SIMDE_X86_AVX512VL_NATIVE) && defined(SIMDE_X86_AVX512BW_NATIVE)
    return _mm256_cvtsepi32_epi8(a);
  #else
    simde__m128i_private r_ = simde__m128i_to_private(simde_mm_setzero_si128());
    simde__m256i_private a_ = simde__m256i_to_private(a);

    SIMDE__VECTORIZE
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
  #define _mm256_cvtsepi32_epi8(a) simde_mm256_cvtsepi32_epi8(a)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_cvtsepi32_epi16 (simde__m128i a) {
  #if defined(SIMDE_X86_AVX512VL_NATIVE) && defined(SIMDE_X86_AVX512BW_NATIVE)
    return _mm_cvtsepi32_epi16(a);
  #else
    simde__m128i_private r_ = simde__m128i_to_private(simde_mm_setzero_si128());
    simde__m128i_private a_ = simde__m128i_to_private(a);

    SIMDE__VECTORIZE
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
  #define _mm_cvtsepi32_epi16(a) simde_mm_cvtsepi32_epi16(a)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128i
simde_mm256_cvtsepi32_epi16 (simde__m256i a) {
  #if defined(SIMDE_X86_AVX512VL_NATIVE) && defined(SIMDE_X86_AVX512BW_NATIVE)
    return _mm256_cvtsepi32_epi16(a);
  #else
    simde__m128i_private r_ = simde__m128i_to_private(simde_mm_setzero_si128());
    simde__m256i_private a_ = simde__m256i_to_private(a);

    SIMDE__VECTORIZE
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
  #define _mm256_cvtsepi32_epi16(a) simde_mm256_cvtsepi32_epi16(a)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_cvtsepi64_epi8 (simde__m128i a) {
  #if defined(SIMDE_X86_AVX512VL_NATIVE) && defined(SIMDE_X86_AVX512BW_NATIVE)
    return _mm_cvtsepi64_epi8(a);
  #else
    simde__m128i_private r_ = simde__m128i_to_private(simde_mm_setzero_si128());
    simde__m128i_private a_ = simde__m128i_to_private(a);

    SIMDE__VECTORIZE
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
  #define _mm_cvtsepi64_epi8(a) simde_mm_cvtsepi64_epi8(a)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128i
simde_mm256_cvtsepi64_epi8 (simde__m256i a) {
  #if defined(SIMDE_X86_AVX512VL_NATIVE) && defined(SIMDE_X86_AVX512BW_NATIVE)
    return _mm256_cvtsepi64_epi8(a);
  #else
    simde__m128i_private r_ = simde__m128i_to_private(simde_mm_setzero_si128());
    simde__m256i_private a_ = simde__m256i_to_private(a);

    SIMDE__VECTORIZE
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
  #define _mm256_cvtsepi64_epi8(a) simde_mm256_cvtsepi64_epi8(a)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_abs_epi64(simde__m256i a) {
#if defined(SIMDE_X86_AVX512VL_NATIVE)
  return _mm256_abs_epi64(a);
#else
  simde__m256i_private
    r_,
    a_ = simde__m256i_to_private(a);

  SIMDE__VECTORIZE
  for (size_t i = 0; i < (sizeof(r_.i64) / sizeof(r_.i64[0])); i++) {
    r_.i64[i] = (a_.i64[i] < INT64_C(0)) ? -a_.i64[i] : a_.i64[i];
  }

  return simde__m256i_from_private(r_);
#endif
}
#if defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
#  define _mm256_abs_epi64(a) simde_mm256_abs_epi64(a)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_mask_abs_epi64(simde__m256i src, simde__mmask8 k, simde__m256i a) {
#if defined(SIMDE_X86_AVX512VL_NATIVE)
  return _mm256_mask_abs_epi64(src, k, a);
#else
  return simde_mm256_mask_mov_epi64(src, k, simde_mm256_abs_epi64(a));
#endif
}
#if defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
#define _mm256_mask_abs_epi64(src, k, a) simde_mm256_mask_abs_epi64(src, k, a)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_maskz_abs_epi64(simde__mmask8 k, simde__m256i a) {
#if defined(SIMDE_X86_AVX512VL_NATIVE)
  return _mm256_maskz_abs_epi64(k, a);
#else
  return simde_mm256_maskz_mov_epi64(k, simde_mm256_abs_epi64(a));
#endif
}
#if defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
#define _mm256_maskz_abs_epi64(k, a) simde_mm256_maskz_abs_epi64(k, a)
#endif

SIMDE__END_DECLS

HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_X86_AVX512VL_H) */
