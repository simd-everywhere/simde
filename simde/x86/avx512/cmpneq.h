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
 *   2021      Evan Nemerson <evan@nemerson.com>
 *   2025      Michael R. Crusoe <crusoe@debian.org>
 */

#if !defined(SIMDE_X86_AVX512_CMPNEQ_H)
#define SIMDE_X86_AVX512_CMPNEQ_H

#include "types.h"
#include "../avx2.h"
#include "mov.h"
#include "cmp.h"
#include "mov_mask.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

SIMDE_FUNCTION_ATTRIBUTES
simde__mmask16
simde_mm_cmpneq_epi8_mask(simde__m128i a, simde__m128i b) {
  #if defined(SIMDE_X86_AVX512VL_NATIVE) && defined(SIMDE_X86_AVX512BW_NATIVE)
    return _mm_cmpneq_epi8_mask(a, b);
  #else
    simde__m128i_private
      a_ = simde__m128i_to_private(a),
      b_ = simde__m128i_to_private(b);
    simde__mmask16 r;

    #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      simde__m128i_private tmp;

      tmp.i8 = HEDLEY_REINTERPRET_CAST(__typeof__(tmp.i8), a_.i8 != b_.i8);
      r = simde_mm_movepi8_mask(simde__m128i_from_private(tmp));
    #else
      r = 0;

      SIMDE_VECTORIZE_REDUCTION(|:r)
      for (size_t i = 0 ; i < (sizeof(a_.u8) / sizeof(a_.u8[0])) ; i++) {
        r |= (a_.u8[i] != b_.u8[i]) ? (UINT16_C(1) << i) : 0;
      }
    #endif

    return r;
  #endif
}
#if defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES) || defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES)
  #undef _mm_cmpneq_epi8_mask
  #define _mm_cmpneq_epi8_mask(a, b) simde_mm_cmpneq_epi8_mask((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__mmask16
simde_mm_mask_cmpneq_epi8_mask(simde__mmask16 k1, simde__m128i a, simde__m128i b) {
  #if defined(SIMDE_X86_AVX512VL_NATIVE) && defined(SIMDE_X86_AVX512BW_NATIVE)
    return _mm_mask_cmpneq_epi8_mask(k1, a, b);
  #else
    return simde_mm_cmpneq_epi8_mask(a, b) & k1;
  #endif
}
#if defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES) || defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES)
  #undef _mm_mask_cmpneq_epi8_mask
  #define _mm_mask_cmpneq_epi8_mask(k1, a, b) simde_mm_mask_cmpneq_epi8_mask((k1), (a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__mmask32
simde_mm256_cmpneq_epi8_mask(simde__m256i a, simde__m256i b) {
  #if defined(SIMDE_X86_AVX512VL_NATIVE) && defined(SIMDE_X86_AVX512BW_NATIVE)
    return _mm256_cmpneq_epi8_mask(a, b);
  #else
    simde__m256i_private
      a_ = simde__m256i_to_private(a),
      b_ = simde__m256i_to_private(b);
    simde__mmask32 r;

    #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      simde__m256i_private tmp;

      tmp.i8 = HEDLEY_REINTERPRET_CAST(__typeof__(tmp.i8), a_.i8 != b_.i8);
      r = simde_mm256_movepi8_mask(simde__m256i_from_private(tmp));
    #else
      r = 0;

      SIMDE_VECTORIZE_REDUCTION(|:r)
      for (size_t i = 0 ; i < (sizeof(a_.u8) / sizeof(a_.u8[0])) ; i++) {
        r |= (a_.u8[i] != b_.u8[i]) ? (UINT32_C(1) << i) : 0;
      }
    #endif

    return r;
  #endif
}
#if defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES) || defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES)
  #undef _mm256_cmpneq_epi8_mask
  #define _mm256_cmpneq_epi8_mask(a, b) simde_mm256_cmpneq_epi8_mask((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__mmask32
simde_mm256_mask_cmpneq_epi8_mask(simde__mmask32 k1, simde__m256i a, simde__m256i b) {
  #if defined(SIMDE_X86_AVX512VL_NATIVE) && defined(SIMDE_X86_AVX512BW_NATIVE)
    return _mm256_mask_cmpneq_epi8_mask(k1, a, b);
  #else
    return simde_mm256_cmpneq_epi8_mask(a, b) & k1;
  #endif
}
#if defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES) || defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES)
  #undef _mm256_mask_cmpneq_epi8_mask
  #define _mm256_mask_cmpneq_epi8_mask(k1, a, b) simde_mm256_mask_cmpneq_epi8_mask((k1), (a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__mmask64
simde_mm512_cmpneq_epi8_mask(simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_AVX512BW_NATIVE)
    return _mm512_cmpneq_epi8_mask(a, b);
  #else
    simde__m512i_private
      a_ = simde__m512i_to_private(a),
      b_ = simde__m512i_to_private(b);
    simde__mmask64 r;

    #if SIMDE_NATURAL_VECTOR_SIZE_LE(256)
      r = 0;

      SIMDE_VECTORIZE_REDUCTION(|:r)
      for (size_t i = 0 ; i < (sizeof(a_.m256i) / sizeof(a_.m256i[0])) ; i++) {
        const uint32_t t = HEDLEY_STATIC_CAST(uint32_t, simde_mm256_movemask_epi8(simde_x_mm256_cmpneq_epi8(a_.m256i[i], b_.m256i[i])));
        r |= HEDLEY_STATIC_CAST(uint64_t, t) << (i * 32);
      }
    #elif defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      simde__m512i_private tmp;

      tmp.i8 = HEDLEY_REINTERPRET_CAST(__typeof__(tmp.i8), a_.i8 != b_.i8);
      r = simde_mm512_movepi8_mask(simde__m512i_from_private(tmp));
    #else
      r = 0;

      SIMDE_VECTORIZE_REDUCTION(|:r)
      for (size_t i = 0 ; i < (sizeof(a_.u8) / sizeof(a_.u8[0])) ; i++) {
        r |= (a_.u8[i] != b_.u8[i]) ? (UINT64_C(1) << i) : 0;
      }
    #endif

    return r;
  #endif
}
#if defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES)
  #undef _mm512_cmpneq_epi8_mask
  #define _mm512_cmpneq_epi8_mask(a, b) simde_mm512_cmpneq_epi8_mask(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__mmask64
simde_mm512_mask_cmpneq_epi8_mask(simde__mmask64 k1, simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_AVX512BW_NATIVE)
    return _mm512_mask_cmpneq_epi8_mask(k1, a, b);
  #else
    return simde_mm512_cmpneq_epi8_mask(a, b) & k1;
  #endif
}
#if defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_cmpneq_epi8_mask
  #define _mm512_mask_cmpneq_epi8_mask(k1, a, b) simde_mm512_mask_cmpneq_epi8_mask((k1), (a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__mmask8
simde_mm_cmpneq_epi16_mask(simde__m128i a, simde__m128i b) {
  #if defined(SIMDE_X86_AVX512VL_NATIVE) && defined(SIMDE_X86_AVX512BW_NATIVE)
    return _mm_cmpneq_epi16_mask(a, b);
  #else
    simde__m128i_private
      a_ = simde__m128i_to_private(a),
      b_ = simde__m128i_to_private(b);
    simde__mmask8 r;

    #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      simde__m128i_private tmp;

      tmp.i16 = HEDLEY_REINTERPRET_CAST(__typeof__(tmp.i16), a_.i16 != b_.i16);
      r = simde_mm_movepi16_mask(simde__m128i_from_private(tmp));
    #else
      r = 0;

      SIMDE_VECTORIZE_REDUCTION(|:r)
      for (size_t i = 0 ; i < (sizeof(a_.u16) / sizeof(a_.u16[0])) ; i++) {
        r |= (a_.u16[i] != b_.u16[i]) ? (UINT8_C(1) << i) : 0;
      }
    #endif

    return r;
  #endif
}
#if defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES) || defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES)
  #undef _mm_cmpneq_epi16_mask
  #define _mm_cmpneq_epi16_mask(a, b) simde_mm_cmpneq_epi16_mask((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__mmask8
simde_mm_mask_cmpneq_epi16_mask(simde__mmask8 k1, simde__m128i a, simde__m128i b) {
  #if defined(SIMDE_X86_AVX512VL_NATIVE) && defined(SIMDE_X86_AVX512BW_NATIVE)
    return _mm_mask_cmpneq_epi16_mask(k1, a, b);
  #else
    return simde_mm_cmpneq_epi16_mask(a, b) & k1;
  #endif
}
#if defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES) || defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES)
  #undef _mm_mask_cmpneq_epi16_mask
  #define _mm_mask_cmpneq_epi16_mask(k1, a, b) simde_mm_mask_cmpneq_epi16_mask((k1), (a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__mmask16
simde_mm256_cmpneq_epi16_mask(simde__m256i a, simde__m256i b) {
  #if defined(SIMDE_X86_AVX512VL_NATIVE) && defined(SIMDE_X86_AVX512BW_NATIVE)
    return _mm256_cmpneq_epi16_mask(a, b);
  #else
    simde__m256i_private
      a_ = simde__m256i_to_private(a),
      b_ = simde__m256i_to_private(b);
    simde__mmask16 r;

    #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      simde__m256i_private tmp;

      tmp.i16 = HEDLEY_REINTERPRET_CAST(__typeof__(tmp.i16), a_.i16 != b_.i16);
      r = simde_mm256_movepi16_mask(simde__m256i_from_private(tmp));
    #else
      r = 0;

      SIMDE_VECTORIZE_REDUCTION(|:r)
      for (size_t i = 0 ; i < (sizeof(a_.u16) / sizeof(a_.u16[0])) ; i++) {
        r |= (a_.u16[i] != b_.u16[i]) ? (UINT16_C(1) << i) : 0;
      }
    #endif

    return r;
  #endif
}
#if defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES) || defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES)
  #undef _mm256_cmpneq_epi16_mask
  #define _mm256_cmpneq_epi16_mask(a, b) simde_mm256_cmpneq_epi16_mask((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__mmask16
simde_mm256_mask_cmpneq_epi16_mask(simde__mmask16 k1, simde__m256i a, simde__m256i b) {
  #if defined(SIMDE_X86_AVX512VL_NATIVE) && defined(SIMDE_X86_AVX512BW_NATIVE)
    return _mm256_mask_cmpneq_epi16_mask(k1, a, b);
  #else
    return simde_mm256_cmpneq_epi16_mask(a, b) & k1;
  #endif
}
#if defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES) || defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES)
  #undef _mm256_mask_cmpneq_epi16_mask
  #define _mm256_mask_cmpneq_epi16_mask(k1, a, b) simde_mm256_mask_cmpneq_epi16_mask((k1), (a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__mmask32
simde_mm512_cmpneq_epi16_mask(simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_AVX512BW_NATIVE)
    return _mm512_cmpneq_epi16_mask(a, b);
  #else
    simde__m512i_private
      a_ = simde__m512i_to_private(a),
      b_ = simde__m512i_to_private(b);
    simde__mmask32 r;

    #if SIMDE_NATURAL_VECTOR_SIZE_LE(256)
      r = 0;

      SIMDE_VECTORIZE_REDUCTION(|:r)
      for (size_t i = 0 ; i < (sizeof(a_.m256i) / sizeof(a_.m256i[0])) ; i++) {
        const uint32_t t = HEDLEY_STATIC_CAST(uint32_t, simde_mm256_movepi16_mask(simde_x_mm256_cmpneq_epi16(a_.m256i[i], b_.m256i[i])));
        r |= HEDLEY_STATIC_CAST(uint64_t, t) << (i * 16);
      }
    #elif defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      simde__m512i_private tmp;

      tmp.i16 = HEDLEY_REINTERPRET_CAST(__typeof__(tmp.i16), a_.i16 != b_.i16);
      r = simde_mm512_movepi16_mask(simde__m512i_from_private(tmp));
    #else
      r = 0;

      SIMDE_VECTORIZE_REDUCTION(|:r)
      for (size_t i = 0 ; i < (sizeof(a_.u16) / sizeof(a_.u16[0])) ; i++) {
        r |= (a_.u16[i] != b_.u16[i]) ? (UINT32_C(1) << i) : 0;
      }
    #endif

    return r;
  #endif
}
#if defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES)
  #undef _mm512_cmpneq_epi16_mask
  #define _mm512_cmpneq_epi16_mask(a, b) simde_mm512_cmpneq_epi16_mask(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__mmask32
simde_mm512_mask_cmpneq_epi16_mask(simde__mmask32 k1, simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_AVX512BW_NATIVE)
    return _mm512_mask_cmpneq_epi16_mask(k1, a, b);
  #else
    return simde_mm512_cmpneq_epi16_mask(a, b) & k1;
  #endif
}
#if defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_cmpneq_epi16_mask
  #define _mm512_mask_cmpneq_epi16_mask(k1, a, b) simde_mm512_mask_cmpneq_epi16_mask((k1), (a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__mmask8
simde_mm_cmpneq_epi32_mask(simde__m128i a, simde__m128i b) {
  #if defined(SIMDE_X86_AVX512F_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm_cmpneq_epi32_mask(a, b);
  #else
    simde__m128i_private
      a_ = simde__m128i_to_private(a),
      b_ = simde__m128i_to_private(b);
    simde__mmask8 r;

    #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      simde__m128i_private tmp;

      tmp.i32 = HEDLEY_REINTERPRET_CAST(__typeof__(tmp.i32), a_.i32 != b_.i32);
      r = simde_mm_movepi32_mask(simde__m128i_from_private(tmp));
    #else
      r = 0;

      SIMDE_VECTORIZE_REDUCTION(|:r)
      for (size_t i = 0 ; i < (sizeof(a_.u32) / sizeof(a_.u32[0])) ; i++) {
        r |= (a_.u32[i] != b_.u32[i]) ? (UINT8_C(1) << i) : 0;
      }
    #endif

    return r;
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm_cmpneq_epi32_mask
  #define _mm_cmpneq_epi32_mask(a, b) simde_mm_cmpneq_epi32_mask((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__mmask8
simde_mm_mask_cmpneq_epi32_mask(simde__mmask8 k1, simde__m128i a, simde__m128i b) {
  #if defined(SIMDE_X86_AVX512F_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm_mask_cmpneq_epi32_mask(k1, a, b);
  #else
    return simde_mm_cmpneq_epi32_mask(a, b) & k1;
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm_mask_cmpneq_epi32_mask
  #define _mm_mask_cmpneq_epi32_mask(k1, a, b) simde_mm_mask_cmpneq_epi32_mask((k1), (a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__mmask8
simde_mm256_cmpneq_epi32_mask(simde__m256i a, simde__m256i b) {
  #if defined(SIMDE_X86_AVX512F_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm256_cmpneq_epi32_mask(a, b);
  #else
    simde__m256i r = simde_x_mm256_cmpneq_epi32(a, b);
    return simde_mm256_movepi32_mask(r);
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm256_cmpneq_epi32_mask
  #define _mm256_cmpneq_epi32_mask(a, b) simde_mm256_cmpneq_epi32_mask((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__mmask8
simde_mm256_mask_cmpneq_epi32_mask(simde__mmask8 k1, simde__m256i a, simde__m256i b) {
  #if defined(SIMDE_X86_AVX512F_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm256_mask_cmpneq_epi32_mask(k1, a, b);
  #else
    return simde_mm256_cmpneq_epi32_mask(a, b) & k1;
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm256_mask_cmpneq_epi32_mask
  #define _mm256_mask_cmpneq_epi32_mask(k1, a, b) simde_mm256_mask_cmpneq_epi32_mask((k1), (a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__mmask16
simde_mm512_cmpneq_epi32_mask(simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_cmpneq_epi32_mask(a, b);
  #else
    simde__m512i_private
      r_,
      a_ = simde__m512i_to_private(a),
      b_ = simde__m512i_to_private(b);

    for (size_t i = 0 ; i < (sizeof(r_.m256i) / sizeof(r_.m256i[0])) ; i++) {
      r_.m256i[i] = simde_x_mm256_cmpneq_epi32(a_.m256i[i], b_.m256i[i]);
    }

    return simde_mm512_movepi32_mask(simde__m512i_from_private(r_));
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_cmpneq_epi32_mask
  #define _mm512_cmpneq_epi32_mask(a, b) simde_mm512_cmpneq_epi32_mask(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__mmask16
simde_mm512_mask_cmpneq_epi32_mask(simde__mmask16 k1, simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_mask_cmpneq_epi32_mask(k1, a, b);
  #else
    return simde_mm512_cmpneq_epi32_mask(a, b) & k1;
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_cmpneq_epi32_mask
  #define _mm512_mask_cmpneq_epi32_mask(k1, a, b) simde_mm512_mask_cmpneq_epi32_mask(k1, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__mmask8
simde_mm_cmpneq_epi64_mask(simde__m128i a, simde__m128i b) {
  #if defined(SIMDE_X86_AVX512F_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm_cmpneq_epi64_mask(a, b);
  #else
    simde__m128i_private
      a_ = simde__m128i_to_private(a),
      b_ = simde__m128i_to_private(b);
    simde__mmask8 r;

    #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      simde__m128i_private tmp;

      tmp.i64 = HEDLEY_REINTERPRET_CAST(__typeof__(tmp.i64), a_.i64 != b_.i64);
      r = simde_mm_movepi64_mask(simde__m128i_from_private(tmp));
    #else
      r = 0;

      SIMDE_VECTORIZE_REDUCTION(|:r)
      for (size_t i = 0 ; i < (sizeof(a_.u64) / sizeof(a_.u64[0])) ; i++) {
        r |= (a_.u64[i] != b_.u64[i]) ? (UINT8_C(1) << i) : 0;
      }
    #endif

    return r;
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm_cmpneq_epi64_mask
  #define _mm_cmpneq_epi64_mask(a, b) simde_mm_cmpneq_epi64_mask((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__mmask8
simde_mm_mask_cmpneq_epi64_mask(simde__mmask8 k1, simde__m128i a, simde__m128i b) {
  #if defined(SIMDE_X86_AVX512F_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm_mask_cmpneq_epi64_mask(k1, a, b);
  #else
    return simde_mm_cmpneq_epi64_mask(a, b) & k1;
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm_mask_cmpneq_epi64_mask
  #define _mm_mask_cmpneq_epi64_mask(k1, a, b) simde_mm_mask_cmpneq_epi64_mask((k1), (a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__mmask8
simde_mm256_cmpneq_epi64_mask(simde__m256i a, simde__m256i b) {
  #if defined(SIMDE_X86_AVX512F_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm256_cmpneq_epi64_mask(a, b);
  #else
    simde__m256i r = simde_x_mm256_cmpneq_epi64(a, b);
    return simde_mm256_movepi64_mask(r);
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm256_cmpneq_epi64_mask
  #define _mm256_cmpneq_epi64_mask(a, b) simde_mm256_cmpneq_epi64_mask((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__mmask8
simde_mm256_mask_cmpneq_epi64_mask(simde__mmask8 k1, simde__m256i a, simde__m256i b) {
  #if defined(SIMDE_X86_AVX512F_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm256_mask_cmpneq_epi64_mask(k1, a, b);
  #else
    return simde_mm256_cmpneq_epi64_mask(a, b) & k1;
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm256_mask_cmpneq_epi64_mask
  #define _mm256_mask_cmpneq_epi64_mask(k1, a, b) simde_mm256_mask_cmpneq_epi64_mask((k1), (a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__mmask8
simde_mm512_cmpneq_epi64_mask(simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_cmpneq_epi64_mask(a, b);
  #else
    simde__m512i_private
      r_,
      a_ = simde__m512i_to_private(a),
      b_ = simde__m512i_to_private(b);

    for (size_t i = 0 ; i < (sizeof(r_.m256i) / sizeof(r_.m256i[0])) ; i++) {
      r_.m256i[i] = simde_x_mm256_cmpneq_epi64(a_.m256i[i], b_.m256i[i]);
    }

    return simde_mm512_movepi64_mask(simde__m512i_from_private(r_));
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_cmpneq_epi64_mask
  #define _mm512_cmpneq_epi64_mask(a, b) simde_mm512_cmpneq_epi64_mask(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__mmask8
simde_mm512_mask_cmpneq_epi64_mask(simde__mmask8 k1, simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_mask_cmpneq_epi64_mask(k1, a, b);
  #else
    return simde_mm512_cmpneq_epi64_mask(a, b) & k1;
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_cmpneq_epi64_mask
  #define _mm512_mask_cmpneq_epi64_mask(k1, a, b) simde_mm512_mask_cmpneq_epi64_mask(k1, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__mmask16
simde_mm_cmpneq_epu8_mask(simde__m128i a, simde__m128i b) {
  #if defined(SIMDE_X86_AVX512BW_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm_cmpneq_epu8_mask(a, b);
  #else
    simde__m128i_private
      a_ = simde__m128i_to_private(a),
      b_ = simde__m128i_to_private(b);
    simde__mmask16 r;

    #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      simde__m128i_private tmp;

      tmp.u8 = HEDLEY_REINTERPRET_CAST(__typeof__(tmp.u8), a_.u8 != b_.u8);
      r = simde_mm_movepi8_mask(simde__m128i_from_private(tmp));
    #else
      r = 0;

      SIMDE_VECTORIZE_REDUCTION(|:r)
      for (size_t i = 0 ; i < (sizeof(a_.u8) / sizeof(a_.u8[0])) ; i++) {
        r |= (a_.u8[i] != b_.u8[i]) ? (UINT16_C(1) << i) : 0;
      }
    #endif

    return r;
  #endif
}
#if defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm_cmpneq_epu8_mask
  #define _mm_cmpneq_epu8_mask(a, b) simde_mm_cmpneq_epu8_mask((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__mmask16
simde_mm_mask_cmpneq_epu8_mask(simde__mmask16 k1, simde__m128i a, simde__m128i b) {
  #if defined(SIMDE_X86_AVX512BW_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm_mask_cmpneq_epu8_mask(k1, a, b);
  #else
    return simde_mm_cmpneq_epu8_mask(a, b) & k1;
  #endif
}
#if defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm_mask_cmpneq_epu8_mask
  #define _mm_mask_cmpneq_epu8_mask(k1, a, b) simde_mm_mask_cmpneq_epu8_mask((k1), (a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__mmask32
simde_mm256_cmpneq_epu8_mask(simde__m256i a, simde__m256i b) {
  #if defined(SIMDE_X86_AVX512BW_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm256_cmpneq_epu8_mask(a, b);
  #elif SIMDE_NATURAL_VECTOR_SIZE_LE(256)
    return HEDLEY_STATIC_CAST(simde__mmask32, simde_mm256_movemask_epi8(simde_x_mm256_cmpneq_epu8(a, b)));
  #else
    simde__m256i_private
      a_ = simde__m256i_to_private(a),
      b_ = simde__m256i_to_private(b);
    simde__mmask32 r;

    #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      simde__m256i_private tmp;

      tmp.u8 = HEDLEY_REINTERPRET_CAST(__typeof__(tmp.u8), a_.u8 != b_.u8);
      r = simde_mm256_movepi8_mask(simde__m256i_from_private(tmp));
    #else
      r = 0;

      SIMDE_VECTORIZE_REDUCTION(|:r)
      for (size_t i = 0 ; i < (sizeof(a_.u8) / sizeof(a_.u8[0])) ; i++) {
        r |= (a_.u8[i] != b_.u8[i]) ? (UINT32_C(1) << i) : 0;
      }
    #endif

    return r;
  #endif
}
#if defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm256_cmpneq_epu8_mask
  #define _mm256_cmpneq_epu8_mask(a, b) simde_mm256_cmpneq_epu8_mask((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__mmask32
simde_mm256_mask_cmpneq_epu8_mask(simde__mmask32 k1, simde__m256i a, simde__m256i b) {
  #if defined(SIMDE_X86_AVX512BW_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm256_mask_cmpneq_epu8_mask(k1, a, b);
  #else
    return simde_mm256_cmpneq_epu8_mask(a, b) & k1;
  #endif
}
#if defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm256_mask_cmpneq_epu8_mask
  #define _mm256_mask_cmpneq_epu8_mask(k1, a, b) simde_mm256_mask_cmpneq_epu8_mask((k1), (a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__mmask64
simde_mm512_cmpneq_epu8_mask(simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_AVX512BW_NATIVE)
    return _mm512_cmpneq_epu8_mask(a, b);
  #else
    simde__m512i_private
      a_ = simde__m512i_to_private(a),
      b_ = simde__m512i_to_private(b);
    simde__mmask64 r;

    #if SIMDE_NATURAL_VECTOR_SIZE_LE(256)
      r = 0;

      SIMDE_VECTORIZE_REDUCTION(|:r)
      for (size_t i = 0 ; i < (sizeof(a_.m256i) / sizeof(a_.m256i[0])) ; i++) {
        const uint32_t t = HEDLEY_STATIC_CAST(uint32_t, simde_mm256_movemask_epi8(simde_x_mm256_cmpneq_epu8(a_.m256i[i], b_.m256i[i])));
        r |= HEDLEY_STATIC_CAST(uint64_t, t) << (i * 32);
      }
    #elif defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      simde__m512i_private tmp;

      tmp.u8 = HEDLEY_REINTERPRET_CAST(__typeof__(tmp.u8), a_.u8 != b_.u8);
      r = simde_mm512_movepi8_mask(simde__m512i_from_private(tmp));
    #else
      r = 0;

      SIMDE_VECTORIZE_REDUCTION(|:r)
      for (size_t i = 0 ; i < (sizeof(a_.u8) / sizeof(a_.u8[0])) ; i++) {
        r |= (a_.u8[i] != b_.u8[i]) ? (UINT64_C(1) << i) : 0;
      }
    #endif

    return r;
  #endif
}
#if defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES)
  #undef _mm512_cmpneq_epu8_mask
  #define _mm512_cmpneq_epu8_mask(a, b) simde_mm512_cmpneq_epu8_mask(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__mmask64
simde_mm512_mask_cmpneq_epu8_mask(simde__mmask64 k1, simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_AVX512BW_NATIVE)
    return _mm512_mask_cmpneq_epu8_mask(k1, a, b);
  #else
    return simde_mm512_cmpneq_epu8_mask(a, b) & k1;
  #endif
}
#if defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_cmpneq_epu8_mask
  #define _mm512_mask_cmpneq_epu8_mask(k1, a, b) simde_mm512_mask_cmpneq_epu8_mask((k1), (a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__mmask8
simde_mm_cmpneq_epu16_mask(simde__m128i a, simde__m128i b) {
  #if defined(SIMDE_X86_AVX512BW_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm_cmpneq_epu16_mask(a, b);
  #else
    simde__m128i_private
      a_ = simde__m128i_to_private(a),
      b_ = simde__m128i_to_private(b);
    simde__mmask8 r;

    #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      simde__m128i_private tmp;

      tmp.u16 = HEDLEY_REINTERPRET_CAST(__typeof__(tmp.u16), a_.u16 != b_.u16);
      r = simde_mm_movepi16_mask(simde__m128i_from_private(tmp));
    #else
      r = 0;

      SIMDE_VECTORIZE_REDUCTION(|:r)
      for (size_t i = 0 ; i < (sizeof(a_.u16) / sizeof(a_.u16[0])) ; i++) {
        r |= (a_.u16[i] != b_.u16[i]) ? (UINT8_C(1) << i) : 0;
      }
    #endif

    return r;
  #endif
}
#if defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm_cmpneq_epu16_mask
  #define _mm_cmpneq_epu16_mask(a, b) simde_mm_cmpneq_epu16_mask((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__mmask8
simde_mm_mask_cmpneq_epu16_mask(simde__mmask8 k1, simde__m128i a, simde__m128i b) {
  #if defined(SIMDE_X86_AVX512BW_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm_mask_cmpneq_epu16_mask(k1, a, b);
  #else
    return simde_mm_cmpneq_epu16_mask(a, b) & k1;
  #endif
}
#if defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm_mask_cmpneq_epu16_mask
  #define _mm_mask_cmpneq_epu16_mask(k1, a, b) simde_mm_mask_cmpneq_epu16_mask((k1), (a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__mmask16
simde_mm256_cmpneq_epu16_mask(simde__m256i a, simde__m256i b) {
  #if defined(SIMDE_X86_AVX512BW_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm256_cmpneq_epu16_mask(a, b);
  #elif SIMDE_NATURAL_VECTOR_SIZE_LE(256)
    return simde_mm256_movepi16_mask(simde_x_mm256_cmpneq_epu16(a, b));
  #else
    simde__m256i_private
      a_ = simde__m256i_to_private(a),
      b_ = simde__m256i_to_private(b);
    simde__mmask16 r;

    #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      simde__m256i_private tmp;

      tmp.u16 = HEDLEY_REINTERPRET_CAST(__typeof__(tmp.u16), a_.u16 != b_.u16);
      r = simde_mm256_movepi16_mask(simde__m256i_from_private(tmp));
    #else
      r = 0;

      SIMDE_VECTORIZE_REDUCTION(|:r)
      for (size_t i = 0 ; i < (sizeof(a_.u16) / sizeof(a_.u16[0])) ; i++) {
        r |= (a_.u16[i] != b_.u16[i]) ? (UINT16_C(1) << i) : 0;
      }
    #endif

    return r;
  #endif
}
#if defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm256_cmpneq_epu16_mask
  #define _mm256_cmpneq_epu16_mask(a, b) simde_mm256_cmpneq_epu16_mask((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__mmask16
simde_mm256_mask_cmpneq_epu16_mask(simde__mmask16 k1, simde__m256i a, simde__m256i b) {
  #if defined(SIMDE_X86_AVX512BW_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm256_mask_cmpneq_epu16_mask(k1, a, b);
  #else
    return simde_mm256_cmpneq_epu16_mask(a, b) & k1;
  #endif
}
#if defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm256_mask_cmpneq_epu16_mask
  #define _mm256_mask_cmpneq_epu16_mask(k1, a, b) simde_mm256_mask_cmpneq_epu16_mask((k1), (a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__mmask32
simde_mm512_cmpneq_epu16_mask(simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_AVX512BW_NATIVE)
    return _mm512_cmpneq_epu16_mask(a, b);
  #else
    simde__m512i_private
      a_ = simde__m512i_to_private(a),
      b_ = simde__m512i_to_private(b);
    simde__mmask32 r;

    #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      simde__m512i_private tmp;

      tmp.u16 = HEDLEY_REINTERPRET_CAST(__typeof__(tmp.u16), a_.u16 != b_.u16);
      r = simde_mm512_movepi16_mask(simde__m512i_from_private(tmp));
    #else
      r = 0;

      SIMDE_VECTORIZE_REDUCTION(|:r)
      for (size_t i = 0 ; i < (sizeof(a_.u16) / sizeof(a_.u16[0])) ; i++) {
        r |= (a_.u16[i] != b_.u16[i]) ? (UINT32_C(1) << i) : 0;
      }
    #endif

    return r;
  #endif
}
#if defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES)
  #undef _mm512_cmpneq_epu16_mask
  #define _mm512_cmpneq_epu16_mask(a, b) simde_mm512_cmpneq_epu16_mask((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__mmask32
simde_mm512_mask_cmpneq_epu16_mask(simde__mmask32 k1, simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_AVX512BW_NATIVE)
    return _mm512_mask_cmpneq_epu16_mask(k1, a, b);
  #else
    return k1 & simde_mm512_cmpneq_epu16_mask(a, b);
  #endif
}
#if defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_cmpneq_epu16_mask
  #define _mm512_mask_cmpneq_epu16_mask(k1, a, b) simde_mm512_mask_cmpneq_epu16_mask(k1, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__mmask8
simde_mm_cmpneq_epu32_mask(simde__m128i a, simde__m128i b) {
  #if defined(SIMDE_X86_AVX512F_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm_cmpneq_epu32_mask(a, b);
  #else
    simde__m128i_private
      a_ = simde__m128i_to_private(a),
      b_ = simde__m128i_to_private(b);
    simde__mmask8 r;

    #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      simde__m128i_private tmp;

      tmp.u32 = HEDLEY_REINTERPRET_CAST(__typeof__(tmp.u32), a_.u32 != b_.u32);
      r = simde_mm_movepi32_mask(simde__m128i_from_private(tmp));
    #else
      r = 0;

      SIMDE_VECTORIZE_REDUCTION(|:r)
      for (size_t i = 0 ; i < (sizeof(a_.u32) / sizeof(a_.u32[0])) ; i++) {
        r |= (a_.u32[i] != b_.u32[i]) ? (UINT8_C(1) << i) : 0;
      }
    #endif

    return r;
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm_cmpneq_epu32_mask
  #define _mm_cmpneq_epu32_mask(a, b) simde_mm_cmpneq_epu32_mask((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__mmask8
simde_mm_mask_cmpneq_epu32_mask(simde__mmask8 k1, simde__m128i a, simde__m128i b) {
  #if defined(SIMDE_X86_AVX512F_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm_mask_cmpneq_epu32_mask(k1, a, b);
  #else
    return simde_mm_cmpneq_epu32_mask(a, b) & k1;
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm_mask_cmpneq_epu32_mask
  #define _mm_mask_cmpneq_epu32_mask(k1, a, b) simde_mm_mask_cmpneq_epu32_mask((k1), (a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__mmask8
simde_mm256_cmpneq_epu32_mask(simde__m256i a, simde__m256i b) {
  #if defined(SIMDE_X86_AVX512F_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm256_cmpneq_epu32_mask(a, b);
  #elif SIMDE_NATURAL_VECTOR_SIZE_LE(256)
    return simde_mm256_movepi32_mask(simde_x_mm256_cmpneq_epu32(a, b));
  #else
    simde__m256i_private
      a_ = simde__m256i_to_private(a),
      b_ = simde__m256i_to_private(b);
    simde__mmask8 r;

    #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      simde__m256i_private tmp;

      tmp.u32 = HEDLEY_REINTERPRET_CAST(__typeof__(tmp.u32), a_.u32 != b_.u32);
      r = simde_mm256_movepi32_mask(simde__m256i_from_private(tmp));
    #else
      r = 0;

      SIMDE_VECTORIZE_REDUCTION(|:r)
      for (size_t i = 0 ; i < (sizeof(a_.u32) / sizeof(a_.u32[0])) ; i++) {
        r |= (a_.u32[i] != b_.u32[i]) ? (UINT8_C(1) << i) : 0;
      }
    #endif

    return r;
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm256_cmpneq_epu32_mask
  #define _mm256_cmpneq_epu32_mask(a, b) simde_mm256_cmpneq_epu32_mask((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__mmask8
simde_mm256_mask_cmpneq_epu32_mask(simde__mmask8 k1, simde__m256i a, simde__m256i b) {
  #if defined(SIMDE_X86_AVX512F_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm256_mask_cmpneq_epu32_mask(k1, a, b);
  #else
    return simde_mm256_cmpneq_epu32_mask(a, b) & k1;
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm256_mask_cmpneq_epu32_mask
  #define _mm256_mask_cmpneq_epu32_mask(k1, a, b) simde_mm256_mask_cmpneq_epu32_mask((k1), (a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__mmask16
simde_mm512_cmpneq_epu32_mask(simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_cmpneq_epu32_mask(a, b);
  #else
    simde__m512i_private
      a_ = simde__m512i_to_private(a),
      b_ = simde__m512i_to_private(b);
    simde__mmask16 r;

    #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      simde__m512i_private tmp;

      tmp.u32 = HEDLEY_REINTERPRET_CAST(__typeof__(tmp.u32), a_.u32 != b_.u32);
      r = simde_mm512_movepi32_mask(simde__m512i_from_private(tmp));
    #else
      r = 0;

      SIMDE_VECTORIZE_REDUCTION(|:r)
      for (size_t i = 0 ; i < (sizeof(a_.u32) / sizeof(a_.u32[0])) ; i++) {
        r |= (a_.u32[i] != b_.u32[i]) ? (UINT16_C(1) << i) : 0;
      }
    #endif

    return r;
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_cmpneq_epu32_mask
  #define _mm512_cmpneq_epu32_mask(a, b) simde_mm512_cmpneq_epu32_mask((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__mmask16
simde_mm512_mask_cmpneq_epu32_mask(simde__mmask32 k1, simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_mask_cmpneq_epu32_mask(k1, a, b);
  #else
    return k1 & simde_mm512_cmpneq_epu32_mask(a, b);
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_cmpneq_epu32_mask
  #define _mm512_mask_cmpneq_epu32_mask(k1, a, b) simde_mm512_mask_cmpneq_epu32_mask(k1, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__mmask8
simde_mm_cmpneq_epu64_mask(simde__m128i a, simde__m128i b) {
  #if defined(SIMDE_X86_AVX512F_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm_cmpneq_epu64_mask(a, b);
  #else
    simde__m128i_private
      a_ = simde__m128i_to_private(a),
      b_ = simde__m128i_to_private(b);
    simde__mmask8 r;

    #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      simde__m128i_private tmp;

      tmp.u64 = HEDLEY_REINTERPRET_CAST(__typeof__(tmp.u64), a_.u64 != b_.u64);
      r = simde_mm_movepi64_mask(simde__m128i_from_private(tmp));
    #else
      r = 0;

      SIMDE_VECTORIZE_REDUCTION(|:r)
      for (size_t i = 0 ; i < (sizeof(a_.u64) / sizeof(a_.u64[0])) ; i++) {
        r |= (a_.u64[i] != b_.u64[i]) ? (UINT8_C(1) << i) : 0;
      }
    #endif

    return r;
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm_cmpneq_epu64_mask
  #define _mm_cmpneq_epu64_mask(a, b) simde_mm_cmpneq_epu64_mask((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__mmask8
simde_mm_mask_cmpneq_epu64_mask(simde__mmask8 k1, simde__m128i a, simde__m128i b) {
  #if defined(SIMDE_X86_AVX512F_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm_mask_cmpneq_epu64_mask(k1, a, b);
  #else
    return simde_mm_cmpneq_epu64_mask(a, b) & k1;
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm_mask_cmpneq_epu64_mask
  #define _mm_mask_cmpneq_epu64_mask(k1, a, b) simde_mm_mask_cmpneq_epu64_mask((k1), (a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__mmask8
simde_mm256_cmpneq_epu64_mask(simde__m256i a, simde__m256i b) {
  #if defined(SIMDE_X86_AVX512F_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm256_cmpneq_epu64_mask(a, b);
  #elif SIMDE_NATURAL_VECTOR_SIZE_LE(256)
    return simde_mm256_movepi64_mask(simde_x_mm256_cmpneq_epu64(a, b));
  #else
    simde__m256i_private
      a_ = simde__m256i_to_private(a),
      b_ = simde__m256i_to_private(b);
    simde__mmask8 r;

    #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      simde__m256i_private tmp;

      tmp.u64 = HEDLEY_REINTERPRET_CAST(__typeof__(tmp.u64), a_.u64 != b_.u64);
      r = simde_mm256_movepi64_mask(simde__m256i_from_private(tmp));
    #else
      r = 0;

      SIMDE_VECTORIZE_REDUCTION(|:r)
      for (size_t i = 0 ; i < (sizeof(a_.u64) / sizeof(a_.u64[0])) ; i++) {
        r |= (a_.u64[i] != b_.u64[i]) ? (UINT8_C(1) << i) : 0;
      }
    #endif

    return r;
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm256_cmpneq_epu64_mask
  #define _mm256_cmpneq_epu64_mask(a, b) simde_mm256_cmpneq_epu64_mask((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__mmask8
simde_mm256_mask_cmpneq_epu64_mask(simde__mmask8 k1, simde__m256i a, simde__m256i b) {
  #if defined(SIMDE_X86_AVX512F_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm256_mask_cmpneq_epu64_mask(k1, a, b);
  #else
    return simde_mm256_cmpneq_epu64_mask(a, b) & k1;
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm256_mask_cmpneq_epu64_mask
  #define _mm256_mask_cmpneq_epu64_mask(k1, a, b) simde_mm256_mask_cmpneq_epu64_mask((k1), (a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__mmask8
simde_mm512_cmpneq_epu64_mask(simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_cmpneq_epu64_mask(a, b);
  #else
    simde__m512i_private
      a_ = simde__m512i_to_private(a),
      b_ = simde__m512i_to_private(b);
    simde__mmask8 r;

    #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      simde__m512i_private tmp;

      tmp.u64 = HEDLEY_REINTERPRET_CAST(__typeof__(tmp.u64), a_.u64 != b_.u64);
      r = simde_mm512_movepi64_mask(simde__m512i_from_private(tmp));
    #else
      r = 0;

      SIMDE_VECTORIZE_REDUCTION(|:r)
      for (size_t i = 0 ; i < (sizeof(a_.u64) / sizeof(a_.u64[0])) ; i++) {
        r |= (a_.u64[i] != b_.u64[i]) ? (UINT8_C(1) << i) : 0;
      }
    #endif

    return r;
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_cmpneq_epu64_mask
  #define _mm512_cmpneq_epu64_mask(a, b) simde_mm512_cmpneq_epu64_mask((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__mmask8
simde_mm512_mask_cmpneq_epu64_mask(simde__mmask8 k1, simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_mask_cmpneq_epu64_mask(k1, a, b);
  #else
    return k1 & simde_mm512_cmpneq_epu64_mask(a, b);
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_cmpneq_epu64_mask
  #define _mm512_mask_cmpneq_epu64_mask(k1, a, b) simde_mm512_mask_cmpneq_epu64_mask(k1, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__mmask16
simde_mm512_cmpneq_ps_mask (simde__m512 a, simde__m512 b) {
  return simde_mm512_cmp_ps_mask(a, b, SIMDE_CMP_NEQ_OQ);
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_cmpneq_ps_mask
  #define _mm512_cmpneq_ps_mask(a, b) simde_mm512_cmp_ps_mask(a, b, SIMDE_CMP_NEQ_OQ)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__mmask16
simde_mm512_mask_cmpneq_ps_mask(simde__mmask16 k1, simde__m512 a, simde__m512 b) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_mask_cmpneq_ps_mask(k1, a, b);
  #else
    return k1 & simde_mm512_cmpneq_ps_mask(a, b);
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_cmpneq_ps_mask
  #define _mm512_mask_cmpneq_ps_mask(k1, a, b) simde_mm512_mask_cmpneq_ps_mask(k1, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__mmask8
simde_mm512_cmpneq_pd_mask (simde__m512d a, simde__m512d b) {
  return simde_mm512_cmp_pd_mask(a, b, SIMDE_CMP_NEQ_OQ);
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_cmpneq_pd_mask
  #define _mm512_cmpneq_pd_mask(a, b) simde_mm512_cmp_pd_mask(a, b, SIMDE_CMP_NEQ_OQ)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__mmask8
simde_mm512_mask_cmpneq_pd_mask(simde__mmask8 k1, simde__m512d a, simde__m512d b) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_mask_cmpneq_pd_mask(k1, a, b);
  #else
    return k1 & simde_mm512_cmpneq_pd_mask(a, b);
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_cmpneq_pd_mask
  #define _mm512_mask_cmpneq_pd_mask(k1, a, b) simde_mm512_mask_cmpneq_pd_mask(k1, a, b)
#endif

SIMDE_END_DECLS_
HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_X86_AVX512_CMPNEQ_H) */
