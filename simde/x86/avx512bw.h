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
 *   2020      Hidayat Khan <huk2209@gmail.com>
 */

#if !defined(SIMDE_X86_AVX512BW_H)
#define SIMDE_X86_AVX512BW_H

#include "avx512vl.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_mask_set1_epi8(simde__m512i src, simde__mmask64 k, int8_t a) {
#if defined(SIMDE_X86_AVX512BW_NATIVE)
  return _mm512_mask_set1_epi8(src, k, a);
#else
  return simde_mm512_mask_mov_epi8(src, k, simde_mm512_set1_epi8(a));
#endif
}
#if defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES)
#define _mm512_mask_set1_epi8(src, k, a) simde_mm512_mask_set1_epi8(src, k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_maskz_set1_epi8(simde__mmask64 k, int8_t a) {
#if defined(SIMDE_X86_AVX512BW_NATIVE)
  return _mm512_maskz_set1_epi8(k, a);
#else
  return simde_mm512_maskz_mov_epi8(k, simde_mm512_set1_epi8(a));
#endif
}
#if defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES)
#define _mm512_maskz_set1_epi8(k, a) simde_mm512_maskz_set1_epi8(k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_mask_set1_epi16(simde__m512i src, simde__mmask32 k, int16_t a) {
#if defined(SIMDE_X86_AVX512BW_NATIVE)
  return _mm512_mask_set1_epi16(src, k, a);
#else
  return simde_mm512_mask_mov_epi16(src, k, simde_mm512_set1_epi16(a));
#endif
}
#if defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES)
#define _mm512_mask_set1_epi16(src, k, a) simde_mm512_mask_set1_epi16(src, k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_maskz_set1_epi16(simde__mmask32 k, int16_t a) {
#if defined(SIMDE_X86_AVX512BW_NATIVE)
  return _mm512_maskz_set1_epi16(k, a);
#else
  return simde_mm512_maskz_mov_epi16(k, simde_mm512_set1_epi16(a));
#endif
}
#if defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES)
#define _mm512_maskz_set1_epi16(k, a) simde_mm512_maskz_set1_epi16(k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_abs_epi8 (simde__m512i a) {
#if defined(SIMDE_X86_AVX512BW_NATIVE)
  return _mm512_abs_epi8(a);
#else
  simde__m512i_private
    r_,
    a_ = simde__m512i_to_private(a);

  SIMDE_VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.i8) / sizeof(r_.i8[0])) ; i++) {
    r_.i8[i] = (a_.i8[i] < INT32_C(0)) ? -a_.i8[i] : a_.i8[i];
  }

  return simde__m512i_from_private(r_);
#endif
}
#if defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES)
  #undef _mm512_abs_epi8
  #define _mm512_abs_epi8(a) simde_mm512_abs_epi8(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_mask_abs_epi8 (simde__m512i src, simde__mmask64 k, simde__m512i a) {
  #if defined(SIMDE_X86_AVX512BW_NATIVE)
    return _mm512_mask_abs_epi8(src, k, a);
  #else
    return simde_mm512_mask_mov_epi8(src, k, simde_mm512_abs_epi8(a));
  #endif
}
#if defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_abs_epi8
  #define _mm512_mask_abs_epi8(src, k, a) simde_mm512_mask_abs_epi8(src, k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_maskz_abs_epi8 (simde__mmask64 k, simde__m512i a) {
  #if defined(SIMDE_X86_AVX512BW_NATIVE)
    return _mm512_maskz_abs_epi8(k, a);
  #else
    return simde_mm512_maskz_mov_epi8(k, simde_mm512_abs_epi8(a));
  #endif
}
#if defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES)
  #undef _mm512_maskz_abs_epi8
  #define _mm512_maskz_abs_epi8(k, a) simde_mm512_maskz_abs_epi8(k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_abs_epi16 (simde__m512i a) {
#if defined(SIMDE_X86_AVX512BW_NATIVE)
  return _mm512_abs_epi16(a);
#else
  simde__m512i_private
    r_,
    a_ = simde__m512i_to_private(a);

  SIMDE_VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.i16) / sizeof(r_.i16[0])) ; i++) {
    r_.i16[i] = (a_.i16[i] < INT32_C(0)) ? -a_.i16[i] : a_.i16[i];
  }

  return simde__m512i_from_private(r_);
#endif
}
#if defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES)
  #undef _mm512_abs_epi16
  #define _mm512_abs_epi16(a) simde_mm512_abs_epi16(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_mask_abs_epi16 (simde__m512i src, simde__mmask32 k, simde__m512i a) {
  #if defined(SIMDE_X86_AVX512BW_NATIVE)
    return _mm512_mask_abs_epi16(src, k, a);
  #else
    return simde_mm512_mask_mov_epi16(src, k, simde_mm512_abs_epi16(a));
  #endif
}
#if defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_abs_epi16
  #define _mm512_mask_abs_epi16(src, k, a) simde_mm512_mask_abs_epi16(src, k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_maskz_abs_epi16 (simde__mmask32 k, simde__m512i a) {
  #if defined(SIMDE_X86_AVX512BW_NATIVE)
    return _mm512_maskz_abs_epi16(k, a);
  #else
    return simde_mm512_maskz_mov_epi16(k, simde_mm512_abs_epi16(a));
  #endif
}
#if defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES)
  #undef _mm512_maskz_abs_epi16
  #define _mm512_maskz_abs_epi16(k, a) simde_mm512_maskz_abs_epi16(k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_add_epi8 (simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_AVX512BW_NATIVE)
    return _mm512_add_epi8(a, b);
  #else
    simde__m512i_private
      r_,
      a_ = simde__m512i_to_private(a),
      b_ = simde__m512i_to_private(b);

    #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r_.i8 = a_.i8 + b_.i8;
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.m256i) / sizeof(r_.m256i[0])) ; i++) {
        r_.m256i[i] = simde_mm256_add_epi8(a_.m256i[i], b_.m256i[i]);
      }
    #endif

    return simde__m512i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES)
  #undef _mm512_add_epi8
  #define _mm512_add_epi8(a, b) simde_mm512_add_epi8(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_mask_add_epi8 (simde__m512i src, simde__mmask64 k, simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_AVX512BW_NATIVE)
    return _mm512_mask_add_epi8(src, k, a, b);
  #else
    return simde_mm512_mask_mov_epi8(src, k, simde_mm512_add_epi8(a, b));
  #endif
}
#if defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_add_epi8
  #define _mm512_mask_add_epi8(src, k, a, b) simde_mm512_mask_add_epi8(src, k, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_maskz_add_epi8 (simde__mmask64 k, simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_AVX512BW_NATIVE)
    return _mm512_maskz_add_epi8(k, a, b);
  #else
    return simde_mm512_maskz_mov_epi8(k, simde_mm512_add_epi8(a, b));
  #endif
}
#if defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES)
  #undef _mm512_maskz_add_epi8
  #define _mm512_maskz_add_epi8(k, a, b) simde_mm512_maskz_add_epi8(k, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_add_epi16 (simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_AVX512BW_NATIVE)
    return _mm512_add_epi16(a, b);
  #else
    simde__m512i_private
      r_,
      a_ = simde__m512i_to_private(a),
      b_ = simde__m512i_to_private(b);

    #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r_.i16 = a_.i16 + b_.i16;
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.m256i) / sizeof(r_.m256i[0])) ; i++) {
        r_.m256i[i] = simde_mm256_add_epi16(a_.m256i[i], b_.m256i[i]);
      }
    #endif

    return simde__m512i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES)
  #undef _mm512_add_epi16
  #define _mm512_add_epi16(a, b) simde_mm512_add_epi16(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_mask_add_epi16 (simde__m512i src, simde__mmask32 k, simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_AVX512BW_NATIVE)
    return _mm512_mask_add_epi16(src, k, a, b);
  #else
    return simde_mm512_mask_mov_epi16(src, k, simde_mm512_add_epi16(a, b));
  #endif
}
#if defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_add_epi16
  #define _mm512_mask_add_epi16(src, k, a, b) simde_mm512_mask_add_epi16(src, k, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_maskz_add_epi16 (simde__mmask32 k, simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_AVX512BW_NATIVE)
    return _mm512_maskz_add_epi16(k, a, b);
  #else
    return simde_mm512_maskz_mov_epi16(k, simde_mm512_add_epi16(a, b));
  #endif
}
#if defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES)
  #undef _mm512_maskz_add_epi16
  #define _mm512_maskz_add_epi16(k, a, b) simde_mm512_maskz_add_epi16(k, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_adds_epi8 (simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_AVX512BW_NATIVE)
    return _mm512_adds_epi8(a, b);
  #else
    simde__m512i_private
      r_,
      a_ = simde__m512i_to_private(a),
      b_ = simde__m512i_to_private(b);

    #if !defined(HEDLEY_INTEL_VERSION)
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.m256i) / sizeof(r_.m256i[0])) ; i++) {
        r_.m256i[i] = simde_mm256_adds_epi8(a_.m256i[i], b_.m256i[i]);
      }
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.i8) / sizeof(r_.i8[0])) ; i++) {
        const int16_t tmp =
          HEDLEY_STATIC_CAST(int16_t, a_.i8[i]) +
          HEDLEY_STATIC_CAST(int16_t, b_.i8[i]);
        r_.i8[i] = HEDLEY_STATIC_CAST(int8_t, ((tmp < INT8_MAX) ? ((tmp > INT8_MIN) ? tmp : INT8_MIN) : INT8_MAX));
      }
    #endif

    return simde__m512i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES)
  #undef _mm512_adds_epi8
  #define _mm512_adds_epi8(a, b) simde_mm512_adds_epi8(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_mask_adds_epi8 (simde__m512i src, simde__mmask64 k, simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_AVX512BW_NATIVE)
    return _mm512_mask_adds_epi8(src, k, a, b);
  #else
    return simde_mm512_mask_mov_epi8(src, k, simde_mm512_adds_epi8(a, b));
  #endif
}
#if defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_adds_epi8
  #define _mm512_mask_adds_epi8(src, k, a, b) simde_mm512_mask_adds_epi8(src, k, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_maskz_adds_epi8 (simde__mmask64 k, simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_AVX512BW_NATIVE)
    return _mm512_maskz_adds_epi8(k, a, b);
  #else
    return simde_mm512_maskz_mov_epi8(k, simde_mm512_adds_epi8(a, b));
  #endif
}
#if defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES)
  #undef _mm512_maskz_adds_epi8
  #define _mm512_maskz_adds_epi8(k, a, b) simde_mm512_maskz_adds_epi8(k, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_adds_epi16 (simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_AVX512BW_NATIVE)
    return _mm512_adds_epi16(a, b);
  #else
    simde__m512i_private
      r_,
      a_ = simde__m512i_to_private(a),
      b_ = simde__m512i_to_private(b);

      #if !defined(HEDLEY_INTEL_VERSION)
        SIMDE_VECTORIZE
        for (size_t i = 0 ; i < (sizeof(r_.m256i) / sizeof(r_.m256i[0])) ; i++) {
          r_.m256i[i] = simde_mm256_adds_epi16(a_.m256i[i], b_.m256i[i]);
        }
      #else
        SIMDE_VECTORIZE
        for (size_t i = 0 ; i < (sizeof(r_.i16) / sizeof(r_.i16[0])) ; i++) {
          const int32_t tmp =
            HEDLEY_STATIC_CAST(int32_t, a_.i16[i]) +
            HEDLEY_STATIC_CAST(int32_t, b_.i16[i]);
          r_.i16[i] = HEDLEY_STATIC_CAST(int16_t, ((tmp < INT16_MAX) ? ((tmp > INT16_MIN) ? tmp : INT16_MIN) : INT16_MAX));
        }
      #endif

    return simde__m512i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES)
  #undef _mm512_adds_epi16
  #define _mm512_adds_epi16(a, b) simde_mm512_adds_epi16(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_mask_adds_epi16 (simde__m512i src, simde__mmask32 k, simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_AVX512BW_NATIVE)
    return _mm512_mask_adds_epi16(src, k, a, b);
  #else
    return simde_mm512_mask_mov_epi16(src, k, simde_mm512_adds_epi16(a, b));
  #endif
}
#if defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_adds_epi16
  #define _mm512_mask_adds_epi16(src, k, a, b) simde_mm512_mask_adds_epi16(src, k, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_maskz_adds_epi16 (simde__mmask32 k, simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_AVX512BW_NATIVE)
    return _mm512_maskz_adds_epi16(k, a, b);
  #else
    return simde_mm512_maskz_mov_epi16(k, simde_mm512_adds_epi16(a, b));
  #endif
}
#if defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES)
  #undef _mm512_maskz_adds_epi16
  #define _mm512_maskz_adds_epi16(k, a, b) simde_mm512_maskz_adds_epi16(k, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_adds_epu8 (simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_AVX512BW_NATIVE)
    return _mm512_adds_epu8(a, b);
  #else
    simde__m512i_private
      r_,
      a_ = simde__m512i_to_private(a),
      b_ = simde__m512i_to_private(b);

    #if !defined(HEDLEY_INTEL_VERSION)
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.m128i) / sizeof(r_.m128i[0])) ; i++) {
        r_.m128i[i] = simde_mm_adds_epu8(a_.m128i[i], b_.m128i[i]);
      }
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.u8) / sizeof(r_.u8[0])) ; i++) {
        r_.u8[i] = ((UINT8_MAX - a_.u8[i]) > b_.u8[i]) ? (a_.u8[i] + b_.u8[i]) : UINT8_MAX;
      }
    #endif

    return simde__m512i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES)
  #undef _mm512_adds_epu8
  #define _mm512_adds_epu8(a, b) simde_mm512_adds_epu8(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_mask_adds_epu8 (simde__m512i src, simde__mmask64 k, simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_AVX512BW_NATIVE)
    return _mm512_mask_adds_epu8(src, k, a, b);
  #else
    return simde_mm512_mask_mov_epi8(src, k, simde_mm512_adds_epu8(a, b));
  #endif
}
#if defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_adds_epu8
  #define _mm512_mask_adds_epu8(src, k, a, b) simde_mm512_mask_adds_epu8(src, k, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_maskz_adds_epu8 (simde__mmask64 k, simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_AVX512BW_NATIVE)
    return _mm512_maskz_adds_epu8(k, a, b);
  #else
    return simde_mm512_maskz_mov_epi8(k, simde_mm512_adds_epu8(a, b));
  #endif
}
#if defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES)
  #undef _mm512_maskz_adds_epu8
  #define _mm512_maskz_adds_epu8(k, a, b) simde_mm512_maskz_adds_epu8(k, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_adds_epu16 (simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_AVX512BW_NATIVE)
    return _mm512_adds_epu16(a, b);
  #else
    simde__m512i_private
      r_,
      a_ = simde__m512i_to_private(a),
      b_ = simde__m512i_to_private(b);

    #if !defined(HEDLEY_INTEL_VERSION)
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.m256i) / sizeof(r_.m256i[0])) ; i++) {
        r_.m256i[i] = simde_mm256_adds_epu16(a_.m256i[i], b_.m256i[i]);
      }
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.u16) / sizeof(r_.u16[0])) ; i++) {
        r_.u16[i] = ((UINT16_MAX - a_.u16[i]) > b_.u16[i]) ? (a_.u16[i] + b_.u16[i]) : UINT16_MAX;
      }
    #endif

    return simde__m512i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES)
  #undef _mm512_adds_epu16
  #define _mm512_adds_epu16(a, b) simde_mm512_adds_epu16(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_mask_adds_epu16 (simde__m512i src, simde__mmask32 k, simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_AVX512BW_NATIVE)
    return _mm512_mask_adds_epu16(src, k, a, b);
  #else
    return simde_mm512_mask_mov_epi16(src, k, simde_mm512_adds_epu16(a, b));
  #endif
}
#if defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_adds_epu16
  #define _mm512_mask_adds_epu16(src, k, a, b) simde_mm512_mask_adds_epu16(src, k, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_maskz_adds_epu16 (simde__mmask32 k, simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_AVX512BW_NATIVE)
    return _mm512_maskz_adds_epu16(k, a, b);
  #else
    return simde_mm512_maskz_mov_epi16(k, simde_mm512_adds_epu16(a, b));
  #endif
}
#if defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES)
  #undef _mm512_maskz_adds_epu16
  #define _mm512_maskz_adds_epu16(k, a, b) simde_mm512_maskz_adds_epu16(k, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_avg_epu8 (simde__m512i a, simde__m512i b) {
#if defined(SIMDE_X86_AVX512BW_NATIVE)
  return _mm512_avg_epu8(a, b);
#else
  simde__m512i_private
    r_,
    a_ = simde__m512i_to_private(a),
    b_ = simde__m512i_to_private(b);

  SIMDE_VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.u8) / sizeof(r_.u8[0])) ; i++) {
    r_.u8[i] = (a_.u8[i] + b_.u8[i] + 1) >> 1;
  }

  return simde__m512i_from_private(r_);
#endif
}
#if defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES)
  #undef _mm512_avg_epu8
  #define _mm512_avg_epu8(a, b) simde_mm512_avg_epu8(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_mask_avg_epu8 (simde__m512i src, simde__mmask64 k, simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_AVX512BW_NATIVE)
    return _mm512_mask_avg_epu8(src, k, a, b);
  #else
    return simde_mm512_mask_mov_epi8(src, k, simde_mm512_avg_epu8(a, b));
  #endif
}
#if defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_avg_epu8
  #define _mm512_mask_avg_epu8(src, k, a, b) simde_mm512_mask_avg_epu8(src, k, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_maskz_avg_epu8 (simde__mmask64 k, simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_AVX512BW_NATIVE)
    return _mm512_maskz_avg_epu8(k, a, b);
  #else
    return simde_mm512_maskz_mov_epi8(k, simde_mm512_avg_epu8(a, b));
  #endif
}
#if defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES)
  #undef _mm512_maskz_avg_epu8
  #define _mm512_maskz_avg_epu8(k, a, b) simde_mm512_maskz_avg_epu8(k, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_avg_epu16 (simde__m512i a, simde__m512i b) {
#if defined(SIMDE_X86_AVX512BW_NATIVE)
  return _mm512_avg_epu16(a, b);
#else
  simde__m512i_private
    r_,
    a_ = simde__m512i_to_private(a),
    b_ = simde__m512i_to_private(b);

  SIMDE_VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.u16) / sizeof(r_.u16[0])) ; i++) {
    r_.u16[i] = (a_.u16[i] + b_.u16[i] + 1) >> 1;
  }

  return simde__m512i_from_private(r_);
#endif
}
#if defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES)
  #undef _mm512_avg_epu16
  #define _mm512_avg_epu16(a, b) simde_mm512_avg_epu16(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_broadcastb_epi8 (simde__m128i a) {
#if defined(SIMDE_X86_AVX512BW_NATIVE)
  return _mm512_broadcastb_epi8(a);
#else
  simde__m128i_private a_= simde__m128i_to_private(a);
  return simde_mm512_set1_epi8(a_.i8[0]);
#endif
}
#if defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES)
  #undef _mm512_broadcastb_epi8
  #define _mm512_broadcastb_epi8(a) simde_mm512_broadcastb_epi8(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_mask_broadcastb_epi8 (simde__m512i src, simde__mmask64 k, simde__m128i a) {
  #if defined(SIMDE_X86_AVX512BW_NATIVE)
    return _mm512_mask_broadcastb_epi8(src, k, a);
  #else
    return simde_mm512_mask_mov_epi8(src, k, simde_mm512_broadcastb_epi8(a));
  #endif
}
#if defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_broadcastb_epi8
  #define _mm512_mask_broadcastb_epi8(src, k, a) simde_mm512_mask_broadcastb_epi8(src, k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_maskz_broadcastb_epi8 (simde__mmask64 k, simde__m128i a) {
  #if defined(SIMDE_X86_AVX512BW_NATIVE)
    return _mm512_maskz_broadcastb_epi8(k, a);
  #else
    return simde_mm512_maskz_mov_epi8(k, simde_mm512_broadcastb_epi8(a));
  #endif
}
#if defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES)
  #undef _mm512_maskz_broadcastb_epi8
  #define _mm512_maskz_broadcastb_epi8(k, a) simde_mm512_maskz_broadcastb_epi8(k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_broadcastw_epi16 (simde__m128i a) {
#if defined(SIMDE_X86_AVX512BW_NATIVE)
  return _mm512_broadcastw_epi16(a);
#else
  simde__m128i_private a_= simde__m128i_to_private(a);
  return simde_mm512_set1_epi16(a_.i16[0]);
#endif
}
#if defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES)
  #undef _mm512_broadcastw_epi16
  #define _mm512_broadcastw_epi16(a) simde_mm512_broadcastw_epi16(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_shuffle_epi8 (simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_AVX512BW_NATIVE)
    return _mm512_shuffle_epi8(a, b);
  #else
    simde__m512i_private
      r_,
      a_ = simde__m512i_to_private(a),
      b_ = simde__m512i_to_private(b);

  #if defined(SIMDE_X86_AVX2_NATIVE)
    r_.m256i[0] = simde_mm256_shuffle_epi8(a_.m256i[0], b_.m256i[0]);
    r_.m256i[1] = simde_mm256_shuffle_epi8(a_.m256i[1], b_.m256i[1]);
  #elif defined(SIMDE_X86_SSSE3_NATIVE)
    r_.m128i[0] = simde_mm_shuffle_epi8(a_.m128i[0], b_.m128i[0]);
    r_.m128i[1] = simde_mm_shuffle_epi8(a_.m128i[1], b_.m128i[1]);
    r_.m128i[2] = simde_mm_shuffle_epi8(a_.m128i[2], b_.m128i[2]);
    r_.m128i[3] = simde_mm_shuffle_epi8(a_.m128i[3], b_.m128i[3]);
  #else
  SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.u8) / sizeof(r_.u8[0])) ; i++) {
      r_.u8[i] = (b_.u8[i] & 0x80) ? 0 : a_.u8[(b_.u8[i] & 0x0f) + (i & 0x30)];
    }
  #endif

  return simde__m512i_from_private(r_);
#endif
}
#if defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES)
  #undef _mm512_shuffle_epi8
  #define _mm512_shuffle_epi8(a, b) simde_mm512_shuffle_epi8(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_mask_shuffle_epi8 (simde__m512i src, simde__mmask64 k, simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_AVX512BW_NATIVE)
    return _mm512_mask_shuffle_epi8(src, k, a, b);
  #else
    return simde_mm512_mask_mov_epi8(src, k, simde_mm512_shuffle_epi8(a, b));
  #endif
}
#if defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_shuffle_epi8
  #define _mm512_mask_shuffle_epi8(src, k, a, b) simde_mm512_mask_shuffle_epi8(src, k, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_maskz_shuffle_epi8 (simde__mmask64 k, simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_AVX512BW_NATIVE)
    return _mm512_maskz_shuffle_epi8(k, a, b);
  #else
    return simde_mm512_maskz_mov_epi8(k, simde_mm512_shuffle_epi8(a, b));
  #endif
}
#if defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES)
  #undef _mm512_maskz_shuffle_epi8
  #define _mm512_maskz_shuffle_epi8(k, a, b) simde_mm512_maskz_shuffle_epi8(k, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__mmask64
simde_mm512_cmpeq_epi8_mask (simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_AVX512BW_NATIVE)
    return _mm512_cmpeq_epi8_mask(a, b);
  #else
    simde__m512i_private
      a_ = simde__m512i_to_private(a),
      b_ = simde__m512i_to_private(b);
    simde__mmask64 r;

    #if defined(SIMDE_X86_AVX2_NATIVE) && 0
      /* The second cast is absolutely necessary otherwise if the sign bit is set it will be sign extended to 64 bits */
      r =             HEDLEY_STATIC_CAST(uint32_t, simde_mm256_movemask_epi8(simde_mm256_cmpeq_epi8(a_.m256i[1], b_.m256i[1])));
      r = (r << 32) | HEDLEY_STATIC_CAST(uint32_t, simde_mm256_movemask_epi8(simde_mm256_cmpeq_epi8(a_.m256i[0], b_.m256i[0])));
    #elif defined(SIMDE_X86_SSE2_NATIVE) && 0
      r =             HEDLEY_STATIC_CAST(simde__mmask64, simde_mm_movemask_epi8(simde_mm_cmpeq_epi8(a_.m128i[3], b_.m128i[3])));
      r = (r << 16) | HEDLEY_STATIC_CAST(simde__mmask64, simde_mm_movemask_epi8(simde_mm_cmpeq_epi8(a_.m128i[2], b_.m128i[2])));
      r = (r << 16) | HEDLEY_STATIC_CAST(simde__mmask64, simde_mm_movemask_epi8(simde_mm_cmpeq_epi8(a_.m128i[1], b_.m128i[1])));
      r = (r << 16) | HEDLEY_STATIC_CAST(simde__mmask64, simde_mm_movemask_epi8(simde_mm_cmpeq_epi8(a_.m128i[0], b_.m128i[0])));
    #elif defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      simde__m512i_private tmp;

      tmp.i8 = HEDLEY_STATIC_CAST(__typeof__(tmp.i8), a_.i8 == b_.i8);
      r = simde_mm512_movepi8_mask(simde__m512i_from_private(tmp));
    #else
      r = 0;

      SIMDE_VECTORIZE_REDUCTION(|:r)
      for (size_t i = 0 ; i < (sizeof(a_.u8) / sizeof(a_.u8[0])) ; i++) {
        r |= (a_.u8[i] == b_.u8[i]) ? (UINT64_C(1) << i) : 0;
      }
    #endif

    return r;
  #endif
}
#if defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES)
  #undef _mm512_cmpeq_epi8_mask
  #define _mm512_cmpeq_epi8_mask(a, b) simde_mm512_cmpeq_epi8_mask(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__mmask64
simde_mm512_cmpge_epi8_mask (simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_AVX512BW_NATIVE)
    return _mm512_cmpge_epi8_mask(a, b);
  #else
    simde__m512i_private
      a_ = simde__m512i_to_private(a),
      b_ = simde__m512i_to_private(b);
    simde__mmask64 r = 0;

    #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      simde__m512i_private tmp;

      tmp.i8 = HEDLEY_STATIC_CAST(__typeof__(tmp.i8), a_.i8 >= b_.i8);
      r = simde_mm512_movepi8_mask(simde__m512i_from_private(tmp));
    #else
      SIMDE_VECTORIZE_REDUCTION(|:r)
      for (size_t i = 0 ; i < (sizeof(a_.i8) / sizeof(a_.i8[0])) ; i++) {
        r |= (a_.i8[i] >= b_.i8[i]) ? (UINT64_C(1) << i) : 0;
      }
    #endif

    return r;
  #endif
}
#if defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES)
  #undef _mm512_cmpge_epi8_mask
  #define _mm512_cmpge_epi8_mask(a, b) simde_mm512_cmpge_epi8_mask(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__mmask64
simde_mm512_cmpge_epu8_mask (simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_AVX512BW_NATIVE)
    return _mm512_cmpge_epu8_mask(a, b);
  #else
    simde__m512i_private
      a_ = simde__m512i_to_private(a),
      b_ = simde__m512i_to_private(b);
    simde__mmask64 r = 0;

    #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      simde__m512i_private tmp;

      tmp.i8 = HEDLEY_STATIC_CAST(__typeof__(tmp.i8), a_.u8 >= b_.u8);
      r = simde_mm512_movepi8_mask(simde__m512i_from_private(tmp));
    #else
      SIMDE_VECTORIZE_REDUCTION(|:r)
      for (size_t i = 0 ; i < (sizeof(a_.u8) / sizeof(a_.u8[0])) ; i++) {
        r |= (a_.u8[i] >= b_.u8[i]) ? (UINT64_C(1) << i) : 0;
      }
    #endif

    return r;
  #endif
}
#if defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES)
  #undef _mm512_cmpge_epu8_mask
  #define _mm512_cmpge_epu8_mask(a, b) simde_mm512_cmpge_epu8_mask(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__mmask64
simde_mm512_cmpgt_epi8_mask (simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_AVX512BW_NATIVE)
    return _mm512_cmpgt_epi8_mask(a, b);
  #else
    simde__m512i_private
      a_ = simde__m512i_to_private(a),
      b_ = simde__m512i_to_private(b);
    simde__mmask64 r;

    #if defined(SIMDE_X86_AVX2_NATIVE)
      /* The second cast is absolutely necessary otherwise if the sign bit is set it will be sign extended to 64 bits */
      r =             HEDLEY_STATIC_CAST(uint32_t, simde_mm256_movemask_epi8(simde_mm256_cmpgt_epi8(a_.m256i[1], b_.m256i[1])));
      r = (r << 32) | HEDLEY_STATIC_CAST(uint32_t, simde_mm256_movemask_epi8(simde_mm256_cmpgt_epi8(a_.m256i[0], b_.m256i[0])));
    #elif defined(SIMDE_X86_SSE2_NATIVE)
      r =             HEDLEY_STATIC_CAST(simde__mmask64, simde_mm_movemask_epi8(simde_mm_cmpgt_epi8(a_.m128i[3], b_.m128i[3])));
      r = (r << 16) | HEDLEY_STATIC_CAST(simde__mmask64, simde_mm_movemask_epi8(simde_mm_cmpgt_epi8(a_.m128i[2], b_.m128i[2])));
      r = (r << 16) | HEDLEY_STATIC_CAST(simde__mmask64, simde_mm_movemask_epi8(simde_mm_cmpgt_epi8(a_.m128i[1], b_.m128i[1])));
      r = (r << 16) | HEDLEY_STATIC_CAST(simde__mmask64, simde_mm_movemask_epi8(simde_mm_cmpgt_epi8(a_.m128i[0], b_.m128i[0])));
    #elif defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      simde__m512i_private tmp;

      tmp.i8 = HEDLEY_STATIC_CAST(__typeof__(tmp.i8), a_.i8 > b_.i8);
      r = simde_mm512_movepi8_mask(simde__m512i_from_private(tmp));
    #else
      r = 0;

      SIMDE_VECTORIZE_REDUCTION(|:r)
      for (size_t i = 0 ; i < (sizeof(a_.i8) / sizeof(a_.i8[0])) ; i++) {
        r |= (a_.i8[i] > b_.i8[i]) ? (UINT64_C(1) << i) : 0;
      }
    #endif

    return r;
  #endif
}
#if defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES)
  #undef _mm512_cmpgt_epi8_mask
  #define _mm512_cmpgt_epi8_mask(a, b) simde_mm512_cmpgt_epi8_mask(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__mmask64
simde_mm512_cmpgt_epu8_mask (simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_AVX512BW_NATIVE)
    return _mm512_cmpgt_epu8_mask(a, b);
  #else
    simde__m512i_private
      a_ = simde__m512i_to_private(a),
      b_ = simde__m512i_to_private(b);
    simde__mmask64 r = 0;

    #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      simde__m512i_private tmp;

      tmp.i8 = HEDLEY_STATIC_CAST(__typeof__(tmp.i8), a_.u8 > b_.u8);
      r = simde_mm512_movepi8_mask(simde__m512i_from_private(tmp));
    #else
      SIMDE_VECTORIZE_REDUCTION(|:r)
      for (size_t i = 0 ; i < (sizeof(a_.u8) / sizeof(a_.u8[0])) ; i++) {
        r |= (a_.u8[i] > b_.u8[i]) ? (UINT64_C(1) << i) : 0;
      }
    #endif

    return r;
  #endif
}
#if defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES)
  #undef _mm512_cmpgt_epu8_mask
  #define _mm512_cmpgt_epu8_mask(a, b) simde_mm512_cmpgt_epu8_mask(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__mmask64
simde_mm512_cmple_epi8_mask (simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_AVX512BW_NATIVE)
    return _mm512_cmple_epi8_mask(a, b);
  #else
    simde__m512i_private
      a_ = simde__m512i_to_private(a),
      b_ = simde__m512i_to_private(b);
    simde__mmask64 r = 0;

    #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      simde__m512i_private tmp;

      tmp.i8 = HEDLEY_STATIC_CAST(__typeof__(tmp.i8), a_.i8 <= b_.i8);
      r = simde_mm512_movepi8_mask(simde__m512i_from_private(tmp));
    #else
      SIMDE_VECTORIZE_REDUCTION(|:r)
      for (size_t i = 0 ; i < (sizeof(a_.i8) / sizeof(a_.i8[0])) ; i++) {
        r |= (a_.i8[i] <= b_.i8[i]) ? (UINT64_C(1) << i) : 0;
      }
    #endif

    return r;
  #endif
}
#if defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES)
  #undef _mm512_cmple_epi8_mask
  #define _mm512_cmple_epi8_mask(a, b) simde_mm512_cmple_epi8_mask(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__mmask64
simde_mm512_cmple_epu8_mask (simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_AVX512BW_NATIVE)
    return _mm512_cmple_epu8_mask(a, b);
  #else
    simde__m512i_private
      a_ = simde__m512i_to_private(a),
      b_ = simde__m512i_to_private(b);
    simde__mmask64 r = 0;

    #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      simde__m512i_private tmp;

      tmp.i8 = HEDLEY_STATIC_CAST(__typeof__(tmp.i8), a_.u8 <= b_.u8);
      r = simde_mm512_movepi8_mask(simde__m512i_from_private(tmp));
    #else
      SIMDE_VECTORIZE_REDUCTION(|:r)
      for (size_t i = 0 ; i < (sizeof(a_.u8) / sizeof(a_.u8[0])) ; i++) {
        r |= (a_.u8[i] <= b_.u8[i]) ? (UINT64_C(1) << i) : 0;
      }
    #endif

    return r;
  #endif
}
#if defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES)
  #undef _mm512_cmple_epu8_mask
  #define _mm512_cmple_epu8_mask(a, b) simde_mm512_cmple_epu8_mask(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__mmask64
simde_mm512_cmplt_epi8_mask (simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_AVX512BW_NATIVE)
    return _mm512_cmplt_epi8_mask(a, b);
  #else
    simde__m512i_private
      a_ = simde__m512i_to_private(a),
      b_ = simde__m512i_to_private(b);
    simde__mmask64 r = 0;

    #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      simde__m512i_private tmp;

      tmp.i8 = HEDLEY_STATIC_CAST(__typeof__(tmp.i8), a_.i8 < b_.i8);
      r = simde_mm512_movepi8_mask(simde__m512i_from_private(tmp));
    #else
      SIMDE_VECTORIZE_REDUCTION(|:r)
      for (size_t i = 0 ; i < (sizeof(a_.i8) / sizeof(a_.i8[0])) ; i++) {
        r |= (a_.i8[i] < b_.i8[i]) ? (UINT64_C(1) << i) : 0;
      }
    #endif

    return r;
  #endif
}
#if defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES)
  #undef _mm512_cmplt_epi8_mask
  #define _mm512_cmplt_epi8_mask(a, b) simde_mm512_cmplt_epi8_mask(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__mmask64
simde_mm512_cmplt_epu8_mask (simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_AVX512BW_NATIVE)
    return _mm512_cmplt_epu8_mask(a, b);
  #else
    simde__m512i_private
      a_ = simde__m512i_to_private(a),
      b_ = simde__m512i_to_private(b);
    simde__mmask64 r = 0;

    #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      simde__m512i_private tmp;

      tmp.i8 = HEDLEY_STATIC_CAST(__typeof__(tmp.i8), a_.u8 < b_.u8);
      r = simde_mm512_movepi8_mask(simde__m512i_from_private(tmp));
    #else
      SIMDE_VECTORIZE_REDUCTION(|:r)
      for (size_t i = 0 ; i < (sizeof(a_.u8) / sizeof(a_.u8[0])) ; i++) {
        r |= (a_.u8[i] < b_.u8[i]) ? (UINT64_C(1) << i) : 0;
      }
    #endif

    return r;
  #endif
}
#if defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES)
  #undef _mm512_cmplt_epu8_mask
  #define _mm512_cmplt_epu8_mask(a, b) simde_mm512_cmplt_epu8_mask(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm512_cvtepi16_epi8 (simde__m512i a) {
  #if defined(SIMDE_X86_AVX512BW_NATIVE)
    return _mm512_cvtepi16_epi8(a);
  #else
    simde__m256i_private r_;
    simde__m512i_private a_ = simde__m512i_to_private(a);

    #if defined(SIMDE_CONVERT_VECTOR_)
      SIMDE_CONVERT_VECTOR_(r_.i8, a_.i16);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.i8) / sizeof(r_.i8[0])) ; i++) {
        r_.i8[i] = HEDLEY_STATIC_CAST(int8_t, a_.i16[i]);
      }
    #endif

    return simde__m256i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES)
  #undef _mm512_cvtepi16_epi8
  #define _mm512_cvtepi16_epi8(a) simde_mm512_cvtepi16_epi8(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm512_mask_cvtepi16_epi8 (simde__m256i src, simde__mmask32 k, simde__m512i a) {
  #if defined(SIMDE_X86_AVX512BW_NATIVE)
    return _mm512_mask_cvtepi16_epi8(src, k, a);
  #else
    return simde_mm256_mask_mov_epi8(src, k, simde_mm512_cvtepi16_epi8(a));
  #endif
}
#if defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_cvtepi16_epi8
  #define _mm512_mask_cvtepi16_epi8(src, k, a) simde_mm512_mask_cvtepi16_epi8(src, k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm512_maskz_cvtepi16_epi8 (simde__mmask32 k, simde__m512i a) {
  #if defined(SIMDE_X86_AVX512BW_NATIVE)
    return _mm512_maskz_cvtepi16_epi8(k, a);
  #else
    return simde_mm256_maskz_mov_epi8(k, simde_mm512_cvtepi16_epi8(a));
  #endif
}
#if defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES)
  #undef _mm512_maskz_cvtepi16_epi8
  #define _mm512_maskz_cvtepi16_epi8(k, a) simde_mm512_maskz_cvtepi16_epi8(k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_cvtepi8_epi16 (simde__m256i a) {
  #if defined(SIMDE_X86_AVX512BW_NATIVE)
    return _mm512_cvtepi8_epi16(a);
  #else
    simde__m512i_private r_;
    simde__m256i_private a_ = simde__m256i_to_private(a);

    #if defined(SIMDE_CONVERT_VECTOR_)
      SIMDE_CONVERT_VECTOR_(r_.i16, a_.i8);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.i16) / sizeof(r_.i16[0])) ; i++) {
        r_.i16[i] = a_.i8[i];
      }
    #endif

    return simde__m512i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES)
  #undef _mm512_cvtepi8_epi16
  #define _mm512_cvtepi8_epi16(a) simde_mm512_cvtepi8_epi16(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm512_cvtsepi16_epi8 (simde__m512i a) {
  #if defined(SIMDE_X86_AVX512VL_NATIVE) && defined(SIMDE_X86_AVX512BW_NATIVE)
    return _mm512_cvtsepi16_epi8(a);
  #else
    simde__m256i_private r_;
    simde__m512i_private a_ = simde__m512i_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.i8) / sizeof(r_.i8[0])) ; i++) {
      r_.i8[i] =
          (a_.i16[i] < INT8_MIN)
            ? (INT8_MIN)
            : ((a_.i16[i] > INT8_MAX)
              ? (INT8_MAX)
              : HEDLEY_STATIC_CAST(int8_t, a_.i16[i]));
    }

    return simde__m256i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES)
  #undef _mm512_cvtsepi16_epi8
  #define _mm512_cvtsepi16_epi8(a) simde_mm512_cvtsepi16_epi8(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm512_mask_cvtsepi16_epi8 (simde__m256i src, simde__mmask32 k, simde__m512i a) {
  #if defined(SIMDE_X86_AVX512BW_NATIVE)
    return _mm512_mask_cvtsepi16_epi8(src, k, a);
  #else
    return simde_mm256_mask_mov_epi8(src, k, simde_mm512_cvtsepi16_epi8(a));
  #endif
}
#if defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_cvtsepi16_epi8
  #define _mm512_mask_cvtsepi16_epi8(src, k, a) simde_mm512_mask_cvtsepi16_epi8(src, k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm512_maskz_cvtsepi16_epi8 (simde__mmask32 k, simde__m512i a) {
  #if defined(SIMDE_X86_AVX512BW_NATIVE)
    return _mm512_maskz_cvtsepi16_epi8(k, a);
  #else
    return simde_mm256_maskz_mov_epi8(k, simde_mm512_cvtsepi16_epi8(a));
  #endif
}
#if defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES)
  #undef _mm512_maskz_cvtsepi16_epi8
  #define _mm512_maskz_cvtsepi16_epi8(k, a) simde_mm512_maskz_cvtsepi16_epi8(k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_min_epi8 (simde__m512i a, simde__m512i b) {
#if defined(SIMDE_X86_AVX512BW_NATIVE)
  return _mm512_min_epi8(a, b);
#else
  simde__m512i_private
    r_,
    a_ = simde__m512i_to_private(a),
    b_ = simde__m512i_to_private(b);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.i8) / sizeof(r_.i8[0])) ; i++) {
      r_.i8[i] = (a_.i8[i] < b_.i8[i]) ? a_.i8[i] : b_.i8[i];
    }

  return simde__m512i_from_private(r_);
#endif
}
#if defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES)
#  define _mm512_min_epi8(a, b) simde_mm512_min_epi8(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_mask_min_epi8 (simde__m512i src, simde__mmask64 k, simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_AVX512BW_NATIVE)
    return _mm512_mask_min_epi8(src, k, a, b);
  #else
    return simde_mm512_mask_mov_epi8(src, k, simde_mm512_min_epi8(a, b));
  #endif
}
#if defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_min_epi8
  #define _mm512_mask_min_epi8(src, k, a, b) simde_mm512_mask_min_epi8(src, k, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_maskz_min_epi8 (simde__mmask64 k, simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_AVX512BW_NATIVE)
    return _mm512_maskz_min_epi8(k, a, b);
  #else
    return simde_mm512_maskz_mov_epi8(k, simde_mm512_min_epi8(a, b));
  #endif
}
#if defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES)
  #undef _mm512_maskz_min_epi8
  #define _mm512_maskz_min_epi8(k, a, b) simde_mm512_maskz_min_epi8(k, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_min_epu8 (simde__m512i a, simde__m512i b) {
#if defined(SIMDE_X86_AVX512BW_NATIVE)
  return _mm512_min_epu8(a, b);
#else
  simde__m512i_private
    r_,
    a_ = simde__m512i_to_private(a),
    b_ = simde__m512i_to_private(b);

  #if defined(SIMDE_X86_AVX2_NATIVE)
    r_.m256i[0] = simde_mm256_min_epu8(a_.m256i[0], b_.m256i[0]);
    r_.m256i[1] = simde_mm256_min_epu8(a_.m256i[1], b_.m256i[1]);
  #else
    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.u8) / sizeof(r_.u8[0])) ; i++) {
      r_.u8[i] = (a_.u8[i] < b_.u8[i]) ? a_.u8[i] : b_.u8[i];
    }
  #endif

  return simde__m512i_from_private(r_);
#endif
}
#if defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES)
  #undef _mm512_min_epu8
  #define _mm512_min_epu8(a, b) simde_mm512_min_epu8(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_mask_min_epu8 (simde__m512i src, simde__mmask64 k, simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_AVX512BW_NATIVE)
    return _mm512_mask_min_epu8(src, k, a, b);
  #else
    return simde_mm512_mask_mov_epi8(src, k, simde_mm512_min_epu8(a, b));
  #endif
}
#if defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_min_epu8
  #define _mm512_mask_min_epu8(src, k, a, b) simde_mm512_mask_min_epu8(src, k, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_maskz_min_epu8 (simde__mmask64 k, simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_AVX512BW_NATIVE)
    return _mm512_maskz_min_epu8(k, a, b);
  #else
    return simde_mm512_maskz_mov_epi8(k, simde_mm512_min_epu8(a, b));
  #endif
}
#if defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES)
  #undef _mm512_maskz_min_epu8
  #define _mm512_maskz_min_epu8(k, a, b) simde_mm512_maskz_min_epu8(k, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_max_epi8 (simde__m512i a, simde__m512i b) {
#if defined(SIMDE_X86_AVX512BW_NATIVE)
  return _mm512_max_epi8(a, b);
#else
  simde__m512i_private
    r_,
    a_ = simde__m512i_to_private(a),
    b_ = simde__m512i_to_private(b);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.i8) / sizeof(r_.i8[0])) ; i++) {
      r_.i8[i] = (a_.i8[i] > b_.i8[i]) ? a_.i8[i] : b_.i8[i];
    }

  return simde__m512i_from_private(r_);
#endif
}
#if defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES)
#  define _mm512_max_epi8(a, b) simde_mm512_max_epi8(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_mask_max_epi8 (simde__m512i src, simde__mmask64 k, simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_AVX512BW_NATIVE)
    return _mm512_mask_max_epi8(src, k, a, b);
  #else
    return simde_mm512_mask_mov_epi8(src, k, simde_mm512_max_epi8(a, b));
  #endif
}
#if defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_max_epi8
  #define _mm512_mask_max_epi8(src, k, a, b) simde_mm512_mask_max_epi8(src, k, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_maskz_max_epi8 (simde__mmask64 k, simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_AVX512BW_NATIVE)
    return _mm512_maskz_max_epi8(k, a, b);
  #else
    return simde_mm512_maskz_mov_epi8(k, simde_mm512_max_epi8(a, b));
  #endif
}
#if defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES)
  #undef _mm512_maskz_max_epi8
  #define _mm512_maskz_max_epi8(k, a, b) simde_mm512_maskz_max_epi8(k, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_max_epu8 (simde__m512i a, simde__m512i b) {
#if defined(SIMDE_X86_AVX512BW_NATIVE)
  return _mm512_max_epu8(a, b);
#else
  simde__m512i_private
    r_,
    a_ = simde__m512i_to_private(a),
    b_ = simde__m512i_to_private(b);

  #if defined(SIMDE_X86_AVX2_NATIVE)
    r_.m256i[0] = simde_mm256_max_epu8(a_.m256i[0], b_.m256i[0]);
    r_.m256i[1] = simde_mm256_max_epu8(a_.m256i[1], b_.m256i[1]);
  #else
    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.u8) / sizeof(r_.u8[0])) ; i++) {
      r_.u8[i] = (a_.u8[i] > b_.u8[i]) ? a_.u8[i] : b_.u8[i];
    }
  #endif

  return simde__m512i_from_private(r_);
#endif
}
#if defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES)
  #undef _mm512_max_epu8
  #define _mm512_max_epu8(a, b) simde_mm512_max_epu8(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_mask_max_epu8 (simde__m512i src, simde__mmask64 k, simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_AVX512BW_NATIVE)
    return _mm512_mask_max_epu8(src, k, a, b);
  #else
    return simde_mm512_mask_mov_epi8(src, k, simde_mm512_max_epu8(a, b));
  #endif
}
#if defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_max_epu8
  #define _mm512_mask_max_epu8(src, k, a, b) simde_mm512_mask_max_epu8(src, k, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_maskz_max_epu8 (simde__mmask64 k, simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_AVX512BW_NATIVE)
    return _mm512_maskz_max_epu8(k, a, b);
  #else
    return simde_mm512_maskz_mov_epi8(k, simde_mm512_max_epu8(a, b));
  #endif
}
#if defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES)
  #undef _mm512_maskz_max_epu8
  #define _mm512_maskz_max_epu8(k, a, b) simde_mm512_maskz_max_epu8(k, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_min_epi16 (simde__m512i a, simde__m512i b) {
#if defined(SIMDE_X86_AVX512BW_NATIVE)
  return _mm512_min_epi16(a, b);
#else
  simde__m512i_private
    r_,
    a_ = simde__m512i_to_private(a),
    b_ = simde__m512i_to_private(b);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.i16) / sizeof(r_.i16[0])) ; i++) {
      r_.i16[i] = (a_.i16[i] < b_.i16[i]) ? a_.i16[i] : b_.i16[i];
    }

  return simde__m512i_from_private(r_);
#endif
}
#if defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES)
#  define _mm512_min_epi16(a, b) simde_mm512_min_epi16(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_mask_min_epi16 (simde__m512i src, simde__mmask32 k, simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_AVX512BW_NATIVE)
    return _mm512_mask_min_epi16(src, k, a, b);
  #else
    return simde_mm512_mask_mov_epi16(src, k, simde_mm512_min_epi16(a, b));
  #endif
}
#if defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_min_epi16
  #define _mm512_mask_min_epi16(src, k, a, b) simde_mm512_mask_min_epi16(src, k, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_maskz_min_epi16 (simde__mmask32 k, simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_AVX512BW_NATIVE)
    return _mm512_maskz_min_epi16(k, a, b);
  #else
    return simde_mm512_maskz_mov_epi16(k, simde_mm512_min_epi16(a, b));
  #endif
}
#if defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES)
  #undef _mm512_maskz_min_epi16
  #define _mm512_maskz_min_epi16(k, a, b) simde_mm512_maskz_min_epi16(k, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_min_epu16 (simde__m512i a, simde__m512i b) {
#if defined(SIMDE_X86_AVX512BW_NATIVE)
  return _mm512_min_epu16(a, b);
#else
  simde__m512i_private
    r_,
    a_ = simde__m512i_to_private(a),
    b_ = simde__m512i_to_private(b);

  #if defined(SIMDE_X86_AVX2_NATIVE)
    r_.m256i[0] = simde_mm256_min_epu16(a_.m256i[0], b_.m256i[0]);
    r_.m256i[1] = simde_mm256_min_epu16(a_.m256i[1], b_.m256i[1]);
  #else
    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.u16) / sizeof(r_.u16[0])) ; i++) {
      r_.u16[i] = (a_.u16[i] < b_.u16[i]) ? a_.u16[i] : b_.u16[i];
    }
  #endif

  return simde__m512i_from_private(r_);
#endif
}
#if defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES)
  #undef _mm512_min_epu16
  #define _mm512_min_epu16(a, b) simde_mm512_min_epu16(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_mask_min_epu16 (simde__m512i src, simde__mmask32 k, simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_AVX512BW_NATIVE)
    return _mm512_mask_min_epu16(src, k, a, b);
  #else
    return simde_mm512_mask_mov_epi16(src, k, simde_mm512_min_epu16(a, b));
  #endif
}
#if defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_min_epu16
  #define _mm512_mask_min_epu16(src, k, a, b) simde_mm512_mask_min_epu16(src, k, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_maskz_min_epu16 (simde__mmask32 k, simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_AVX512BW_NATIVE)
    return _mm512_maskz_min_epu16(k, a, b);
  #else
    return simde_mm512_maskz_mov_epi16(k, simde_mm512_min_epu16(a, b));
  #endif
}
#if defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES)
  #undef _mm512_maskz_min_epu16
  #define _mm512_maskz_min_epu16(k, a, b) simde_mm512_maskz_min_epu16(k, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_max_epi16 (simde__m512i a, simde__m512i b) {
#if defined(SIMDE_X86_AVX512BW_NATIVE)
  return _mm512_max_epi16(a, b);
#else
  simde__m512i_private
    r_,
    a_ = simde__m512i_to_private(a),
    b_ = simde__m512i_to_private(b);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.i16) / sizeof(r_.i16[0])) ; i++) {
      r_.i16[i] = (a_.i16[i] > b_.i16[i]) ? a_.i16[i] : b_.i16[i];
    }

  return simde__m512i_from_private(r_);
#endif
}
#if defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES)
#  define _mm512_max_epi16(a, b) simde_mm512_max_epi16(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_mask_max_epi16 (simde__m512i src, simde__mmask32 k, simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_AVX512BW_NATIVE)
    return _mm512_mask_max_epi16(src, k, a, b);
  #else
    return simde_mm512_mask_mov_epi16(src, k, simde_mm512_max_epi16(a, b));
  #endif
}
#if defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_max_epi16
  #define _mm512_mask_max_epi16(src, k, a, b) simde_mm512_mask_max_epi16(src, k, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_maskz_max_epi16 (simde__mmask32 k, simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_AVX512BW_NATIVE)
    return _mm512_maskz_max_epi16(k, a, b);
  #else
    return simde_mm512_maskz_mov_epi16(k, simde_mm512_max_epi16(a, b));
  #endif
}
#if defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES)
  #undef _mm512_maskz_max_epi16
  #define _mm512_maskz_max_epi16(k, a, b) simde_mm512_maskz_max_epi16(k, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_max_epu16 (simde__m512i a, simde__m512i b) {
#if defined(SIMDE_X86_AVX512BW_NATIVE)
  return _mm512_max_epu16(a, b);
#else
  simde__m512i_private
    r_,
    a_ = simde__m512i_to_private(a),
    b_ = simde__m512i_to_private(b);

  #if defined(SIMDE_X86_AVX2_NATIVE)
    r_.m256i[0] = simde_mm256_max_epu16(a_.m256i[0], b_.m256i[0]);
    r_.m256i[1] = simde_mm256_max_epu16(a_.m256i[1], b_.m256i[1]);
  #else
    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.u16) / sizeof(r_.u16[0])) ; i++) {
      r_.u16[i] = (a_.u16[i] > b_.u16[i]) ? a_.u16[i] : b_.u16[i];
    }
  #endif

  return simde__m512i_from_private(r_);
#endif
}
#if defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES)
  #undef _mm512_max_epu16
  #define _mm512_max_epu16(a, b) simde_mm512_max_epu16(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_mask_max_epu16 (simde__m512i src, simde__mmask32 k, simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_AVX512BW_NATIVE)
    return _mm512_mask_max_epu16(src, k, a, b);
  #else
    return simde_mm512_mask_mov_epi16(src, k, simde_mm512_max_epu16(a, b));
  #endif
}
#if defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_max_epu16
  #define _mm512_mask_max_epu16(src, k, a, b) simde_mm512_mask_max_epu16(src, k, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_maskz_max_epu16 (simde__mmask32 k, simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_AVX512BW_NATIVE)
    return _mm512_maskz_max_epu16(k, a, b);
  #else
    return simde_mm512_maskz_mov_epi16(k, simde_mm512_max_epu16(a, b));
  #endif
}
#if defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES)
  #undef _mm512_maskz_max_epu16
  #define _mm512_maskz_max_epu16(k, a, b) simde_mm512_maskz_max_epu16(k, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_sub_epi8 (simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_AVX512BW_NATIVE)
    return _mm512_sub_epi8(a, b);
  #else
    simde__m512i_private
      r_,
      a_ = simde__m512i_to_private(a),
      b_ = simde__m512i_to_private(b);

    #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r_.i8 = a_.i8 - b_.i8;
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.m256i) / sizeof(r_.m256i[0])) ; i++) {
        r_.m256i[i] = simde_mm256_sub_epi8(a_.m256i[i], b_.m256i[i]);
      }
    #endif

    return simde__m512i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES)
  #undef _mm512_sub_epi8
  #define _mm512_sub_epi8(a, b) simde_mm512_sub_epi8(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_mask_sub_epi8 (simde__m512i src, simde__mmask64 k, simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_AVX512BW_NATIVE)
    return _mm512_mask_sub_epi8(src, k, a, b);
  #else
    return simde_mm512_mask_mov_epi8(src, k, simde_mm512_sub_epi8(a, b));
  #endif
}
#if defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_sub_epi8
  #define _mm512_mask_sub_epi8(src, k, a, b) simde_mm512_mask_sub_epi8(src, k, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_maskz_sub_epi8 (simde__mmask64 k, simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_AVX512BW_NATIVE)
    return _mm512_maskz_sub_epi8(k, a, b);
  #else
    return simde_mm512_maskz_mov_epi8(k, simde_mm512_sub_epi8(a, b));
  #endif
}
#if defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES)
  #undef _mm512_maskz_sub_epi8
  #define _mm512_maskz_sub_epi8(k, a, b) simde_mm512_maskz_sub_epi8(k, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_sub_epi16 (simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_AVX512BW_NATIVE)
    return _mm512_sub_epi16(a, b);
  #else
    simde__m512i_private
      r_,
      a_ = simde__m512i_to_private(a),
      b_ = simde__m512i_to_private(b);

    #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r_.i16 = a_.i16 - b_.i16;
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.m256i) / sizeof(r_.m256i[0])) ; i++) {
        r_.m256i[i] = simde_mm256_sub_epi16(a_.m256i[i], b_.m256i[i]);
      }
    #endif

    return simde__m512i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES)
  #undef _mm512_sub_epi16
  #define _mm512_sub_epi16(a, b) simde_mm512_sub_epi16(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_subs_epi8 (simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_AVX512BW_NATIVE)
    return _mm512_subs_epi8(a, b);
  #else
    simde__m512i_private
      r_,
      a_ = simde__m512i_to_private(a),
      b_ = simde__m512i_to_private(b);

    #if !defined(HEDLEY_INTEL_VERSION)
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.m256i) / sizeof(r_.m256i[0])) ; i++) {
        r_.m256i[i] = simde_mm256_subs_epi8(a_.m256i[i], b_.m256i[i]);
      }
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.i8) / sizeof(r_.i8[0])) ; i++) {
        const int16_t tmp =
          HEDLEY_STATIC_CAST(int16_t, a_.i8[i]) -
          HEDLEY_STATIC_CAST(int16_t, b_.i8[i]);
        r_.i8[i] = HEDLEY_STATIC_CAST(int8_t, ((tmp < INT8_MAX) ? ((tmp > INT8_MIN) ? tmp : INT8_MIN) : INT8_MAX));
      }
    #endif

    return simde__m512i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES)
  #undef _mm512_subs_epi8
  #define _mm512_subs_epi8(a, b) simde_mm512_subs_epi8(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_mask_subs_epi8 (simde__m512i src, simde__mmask64 k, simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_AVX512BW_NATIVE)
    return _mm512_mask_subs_epi8(src, k, a, b);
  #else
    return simde_mm512_mask_mov_epi8(src, k, simde_mm512_subs_epi8(a, b));
  #endif
}
#if defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_subs_epi8
  #define _mm512_mask_subs_epi8(src, k, a, b) simde_mm512_mask_subs_epi8(src, k, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_maskz_subs_epi8 (simde__mmask64 k, simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_AVX512BW_NATIVE)
    return _mm512_maskz_subs_epi8(k, a, b);
  #else
    return simde_mm512_maskz_mov_epi8(k, simde_mm512_subs_epi8(a, b));
  #endif
}
#if defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES)
  #undef _mm512_maskz_subs_epi8
  #define _mm512_maskz_subs_epi8(k, a, b) simde_mm512_maskz_subs_epi8(k, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_subs_epi16 (simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_AVX512BW_NATIVE)
    return _mm512_subs_epi16(a, b);
  #else
    simde__m512i_private
      r_,
      a_ = simde__m512i_to_private(a),
      b_ = simde__m512i_to_private(b);

      #if !defined(HEDLEY_INTEL_VERSION)
        SIMDE_VECTORIZE
        for (size_t i = 0 ; i < (sizeof(r_.m256i) / sizeof(r_.m256i[0])) ; i++) {
          r_.m256i[i] = simde_mm256_subs_epi16(a_.m256i[i], b_.m256i[i]);
        }
      #else
        SIMDE_VECTORIZE
        for (size_t i = 0 ; i < (sizeof(r_.i16) / sizeof(r_.i16[0])) ; i++) {
          const int32_t tmp =
            HEDLEY_STATIC_CAST(int32_t, a_.i16[i]) -
            HEDLEY_STATIC_CAST(int32_t, b_.i16[i]);
          r_.i16[i] = HEDLEY_STATIC_CAST(int16_t, ((tmp < INT16_MAX) ? ((tmp > INT16_MIN) ? tmp : INT16_MIN) : INT16_MAX));
        }
      #endif

    return simde__m512i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES)
  #undef _mm512_subs_epi16
  #define _mm512_subs_epi16(a, b) simde_mm512_subs_epi16(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_subs_epu8 (simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_AVX512BW_NATIVE)
    return _mm512_subs_epu8(a, b);
  #else
    simde__m512i_private
      r_,
      a_ = simde__m512i_to_private(a),
      b_ = simde__m512i_to_private(b);

    #if !defined(HEDLEY_INTEL_VERSION)
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.m128i) / sizeof(r_.m128i[0])) ; i++) {
        r_.m128i[i] = simde_mm_subs_epu8(a_.m128i[i], b_.m128i[i]);
      }
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.u8) / sizeof(r_.u8[0])) ; i++) {
        r_.u8[i] = (a_.u8[i] > b_.u8[i]) ? (a_.u8[i] - b_.u8[i]) : UINT8_C(0);
      }
    #endif

    return simde__m512i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES)
  #undef _mm512_subs_epu8
  #define _mm512_subs_epu8(a, b) simde_mm512_subs_epu8(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_mask_subs_epu8 (simde__m512i src, simde__mmask64 k, simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_AVX512BW_NATIVE)
    return _mm512_mask_subs_epu8(src, k, a, b);
  #else
    return simde_mm512_mask_mov_epi8(src, k, simde_mm512_subs_epu8(a, b));
  #endif
}
#if defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_subs_epu8
  #define _mm512_mask_subs_epu8(src, k, a, b) simde_mm512_mask_subs_epu8(src, k, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_maskz_subs_epu8 (simde__mmask64 k, simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_AVX512BW_NATIVE)
    return _mm512_maskz_subs_epu8(k, a, b);
  #else
    return simde_mm512_maskz_mov_epi8(k, simde_mm512_subs_epu8(a, b));
  #endif
}
#if defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES)
  #undef _mm512_maskz_subs_epu8
  #define _mm512_maskz_subs_epu8(k, a, b) simde_mm512_maskz_subs_epu8(k, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_subs_epu16 (simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_AVX512BW_NATIVE)
    return _mm512_subs_epu16(a, b);
  #else
    simde__m512i_private
      r_,
      a_ = simde__m512i_to_private(a),
      b_ = simde__m512i_to_private(b);

    #if !defined(HEDLEY_INTEL_VERSION)
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.m256i) / sizeof(r_.m256i[0])) ; i++) {
        r_.m256i[i] = simde_mm256_subs_epu16(a_.m256i[i], b_.m256i[i]);
      }
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.u16) / sizeof(r_.u16[0])) ; i++) {
        r_.u16[i] = (a_.u16[i] > b_.u16[i]) ? (a_.u16[i] - b_.u16[i]) : UINT16_C(0);
      }
    #endif

    return simde__m512i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES)
  #undef _mm512_subs_epu16
  #define _mm512_subs_epu16(a, b) simde_mm512_subs_epu16(a, b)
#endif


SIMDE_END_DECLS_

HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_X86_AVX512BW_H) */
