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
 *   2020      Hidayat Khan <huk2209@gmail.com>
 */

#if !defined(SIMDE_X86_AVX512_AVG_H)
#define SIMDE_X86_AVX512_AVG_H

#include "types.h"
#include "mov.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

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

SIMDE_END_DECLS_
HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_X86_AVX512_AVG_H) */
