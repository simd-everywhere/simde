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
 */

#if !defined(SIMDE_X86_AVX512_MOV_MASK_H)
#define SIMDE_X86_AVX512_MOV_MASK_H

#include "types.h"
#include "../avx2.h"

#include "cast.h"
#include "set.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

SIMDE_FUNCTION_ATTRIBUTES
simde__mmask64
simde_mm512_movepi8_mask (simde__m512i a) {
  #if defined(SIMDE_X86_AVX512BW_NATIVE)
    return _mm512_movepi8_mask(a);
  #else
    simde__m512i_private a_ = simde__m512i_to_private(a);
    uint64_t r = 0;

    #if SIMDE_NATURAL_VECTOR_SIZE_LE(256)
      for (size_t i = 0 ; i < (sizeof(a_.m256i) / sizeof(a_.m256i[0])) ; i++) {
        const uint32_t t = HEDLEY_STATIC_CAST(uint32_t, simde_mm256_movemask_epi8(a_.m256i[i]));
        r |= HEDLEY_STATIC_CAST(uint64_t, t) << (i * 32);
      }
    #else
      r = 0;

      SIMDE_VECTORIZE_REDUCTION(|:r)
      for (size_t i = 0 ; i < (sizeof(a_.i8) / sizeof(a_.i8[0])) ; i++) {
        r |= (a_.i8[i] < 0) ? (UINT64_C(1) << i) : 0;
      }
    #endif

    return HEDLEY_STATIC_CAST(simde__mmask64, r);
  #endif
}
#if defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES)
  #undef _mm512_movepi8_mask
  #define _mm512_movepi8_mask(a) simde_mm512_movepi8_mask(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__mmask32
simde_mm512_movepi16_mask (simde__m512i a) {
  #if defined(SIMDE_X86_AVX512BW_NATIVE)
    return _mm512_movepi16_mask(a);
  #else
    simde__m512i_private a_ = simde__m512i_to_private(a);
    simde__mmask32 r = 0;

    SIMDE_VECTORIZE_REDUCTION(|:r)
    for (size_t i = 0 ; i < (sizeof(a_.i16) / sizeof(a_.i16[0])) ; i++) {
      r |= (a_.i16[i] < 0) ? (UINT32_C(1) << i) : 0;
    }

    return r;
  #endif
}
#if defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES)
  #undef _mm512_movepi16_mask
  #define _mm512_movepi16_mask(a) simde_mm512_movepi16_mask(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__mmask16
simde_mm512_movepi32_mask (simde__m512i a) {
  #if defined(SIMDE_X86_AVX512DQ_NATIVE)
    return _mm512_movepi32_mask(a);
  #else
    simde__m512i_private a_ = simde__m512i_to_private(a);
    simde__mmask16 r = 0;

    SIMDE_VECTORIZE_REDUCTION(|:r)
    for (size_t i = 0 ; i < (sizeof(a_.i32) / sizeof(a_.i32[0])) ; i++) {
      r |= (a_.i32[i] < 0) ? (UINT32_C(1) << i) : 0;
    }

    return r;
  #endif
}
#if defined(SIMDE_X86_AVX512DQ_ENABLE_NATIVE_ALIASES)
  #undef _mm512_movepi32_mask
  #define _mm512_movepi32_mask(a) simde_mm512_movepi32_mask(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__mmask8
simde_mm512_movepi64_mask (simde__m512i a) {
  #if defined(SIMDE_X86_AVX512DQ_NATIVE)
    return _mm512_movepi64_mask(a);
  #else
    simde__m512i_private a_ = simde__m512i_to_private(a);
    simde__mmask8 r = 0;

    SIMDE_VECTORIZE_REDUCTION(|:r)
    for (size_t i = 0 ; i < (sizeof(a_.i64) / sizeof(a_.i64[0])) ; i++) {
      r |= (a_.i64[i] < 0) ? (UINT32_C(1) << i) : 0;
    }

    return r;
  #endif
}
#if defined(SIMDE_X86_AVX512DQ_ENABLE_NATIVE_ALIASES)
  #undef _mm512_movepi64_mask
  #define _mm512_movepi64_mask(a) simde_mm512_movepi64_mask(a)
#endif

SIMDE_END_DECLS_
HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_X86_AVX512_MOV_MASK_H) */
