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
 *   2023      Michael R. Crusoe <crusoe@debian.org>
 */

#if !defined(SIMDE_X86_AVX512_MULTISHIFT_H)
#define SIMDE_X86_AVX512_MULTISHIFT_H

#include "types.h"
#include "mov.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_multishift_epi64_epi8 (simde__m128i a, simde__m128i b) {
  #if defined(SIMDE_X86_AVX512VBMI_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm_multishift_epi64_epi8(a, b);
  #else
    simde__m128i_private
      r_,
      a_ = simde__m128i_to_private(a),
      b_ = simde__m128i_to_private(b);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < sizeof(r_.u8) / sizeof(r_.u8[0]) ; i++) {
      r_.u8[i] = HEDLEY_STATIC_CAST(uint8_t, (b_.u64[i / 8] >> (a_.u8[i] & 63)) | (b_.u64[i / 8] << (64 - (a_.u8[i] & 63))));
    }

    return simde__m128i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512VBMI_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm_multishift_epi64_epi8
  #define _mm_multishift_epi64_epi8(a, b) simde_mm_multishift_epi64_epi8(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_mask_multishift_epi64_epi8 (simde__m128i src, simde__mmask16 k, simde__m128i a, simde__m128i b) {
  #if defined(SIMDE_X86_AVX512VBMI_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm_mask_multishift_epi64_epi8(src, k, a, b);
  #else
    return simde_mm_mask_mov_epi8(src, k, simde_mm_multishift_epi64_epi8(a, b));
  #endif
}
#if defined(SIMDE_X86_AVX512VBMI_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm_mask_multishift_epi64_epi8
  #define _mm_mask_multishift_epi64_epi8(src, k, a, b) simde_mm_mask_multishift_epi64_epi8(src, k, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_maskz_multishift_epi64_epi8 (simde__mmask16 k, simde__m128i a, simde__m128i b) {
  #if defined(SIMDE_X86_AVX512VBMI_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm_maskz_multishift_epi64_epi8(k, a, b);
  #else
    return simde_mm_maskz_mov_epi8(k, simde_mm_multishift_epi64_epi8(a, b));
  #endif
}
#if defined(SIMDE_X86_AVX512VBMI_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm_maskz_multishift_epi64_epi8
  #define _mm_maskz_multishift_epi64_epi8(k, a, b) simde_mm_maskz_multishift_epi64_epi8(k, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_multishift_epi64_epi8 (simde__m256i a, simde__m256i b) {
  #if defined(SIMDE_X86_AVX512VBMI_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm256_multishift_epi64_epi8(a, b);
  #else
    simde__m256i_private
      r_,
      a_ = simde__m256i_to_private(a),
      b_ = simde__m256i_to_private(b);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < sizeof(r_.u8) / sizeof(r_.u8[0]) ; i++) {
      r_.u8[i] = HEDLEY_STATIC_CAST(uint8_t, (b_.u64[i / 8] >> (a_.u8[i] & 63)) | (b_.u64[i / 8] << (64 - (a_.u8[i] & 63))));
    }

    return simde__m256i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512VBMI_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm256_multishift_epi64_epi8
  #define _mm256_multishift_epi64_epi8(a, b) simde_mm256_multishift_epi64_epi8(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_mask_multishift_epi64_epi8 (simde__m256i src, simde__mmask32 k, simde__m256i a, simde__m256i b) {
  #if defined(SIMDE_X86_AVX512VBMI_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm256_mask_multishift_epi64_epi8(src, k, a, b);
  #else
    return simde_mm256_mask_mov_epi8(src, k, simde_mm256_multishift_epi64_epi8(a, b));
  #endif
}
#if defined(SIMDE_X86_AVX512VBMI_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm256_mask_multishift_epi64_epi8
  #define _mm256_mask_multishift_epi64_epi8(src, k, a, b) simde_mm256_mask_multishift_epi64_epi8(src, k, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_maskz_multishift_epi64_epi8 (simde__mmask32 k, simde__m256i a, simde__m256i b) {
  #if defined(SIMDE_X86_AVX512VBMI_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm256_maskz_multishift_epi64_epi8(k, a, b);
  #else
    return simde_mm256_maskz_mov_epi8(k, simde_mm256_multishift_epi64_epi8(a, b));
  #endif
}
#if defined(SIMDE_X86_AVX512VBMI_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm256_maskz_multishift_epi64_epi8
  #define _mm256_maskz_multishift_epi64_epi8(k, a, b) simde_mm256_maskz_multishift_epi64_epi8(k, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_multishift_epi64_epi8 (simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_AVX512VBMI_NATIVE)
    return _mm512_multishift_epi64_epi8(a, b);
  #else
    simde__m512i_private
      r_,
      a_ = simde__m512i_to_private(a),
      b_ = simde__m512i_to_private(b);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < sizeof(r_.u8) / sizeof(r_.u8[0]) ; i++) {
      r_.u8[i] = HEDLEY_STATIC_CAST(uint8_t, (b_.u64[i / 8] >> (a_.u8[i] & 63)) | (b_.u64[i / 8] << (64 - (a_.u8[i] & 63))));
    }

    return simde__m512i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512VBMI_ENABLE_NATIVE_ALIASES)
  #undef _mm512_multishift_epi64_epi8
  #define _mm512_multishift_epi64_epi8(a, b) simde_mm512_multishift_epi64_epi8(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_mask_multishift_epi64_epi8 (simde__m512i src, simde__mmask64 k, simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_AVX512VBMI_NATIVE)
    return _mm512_mask_multishift_epi64_epi8(src, k, a, b);
  #else
    return simde_mm512_mask_mov_epi8(src, k, simde_mm512_multishift_epi64_epi8(a, b));
  #endif
}
#if defined(SIMDE_X86_AVX512VBMI_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_multishift_epi64_epi8
  #define _mm512_mask_multishift_epi64_epi8(src, k, a, b) simde_mm512_mask_multishift_epi64_epi8(src, k, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_maskz_multishift_epi64_epi8 (simde__mmask64 k, simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_AVX512VBMI_NATIVE)
    return _mm512_maskz_multishift_epi64_epi8(k, a, b);
  #else
    return simde_mm512_maskz_mov_epi8(k, simde_mm512_multishift_epi64_epi8(a, b));
  #endif
}
#if defined(SIMDE_X86_AVX512VBMI_ENABLE_NATIVE_ALIASES)
  #undef _mm512_maskz_multishift_epi64_epi8
  #define _mm512_maskz_multishift_epi64_epi8(k, a, b) simde_mm512_maskz_multishift_epi64_epi8(k, a, b)
#endif

SIMDE_END_DECLS_
HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_X86_AVX512_MULTISHIFT_H) */
