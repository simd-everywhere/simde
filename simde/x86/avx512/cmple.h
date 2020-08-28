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

#if !defined(SIMDE_X86_AVX512_CMPLE_H)
#define SIMDE_X86_AVX512_CMPLE_H

#include "types.h"
#include "mov.h"
#include "mov_mask.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

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

SIMDE_END_DECLS_
HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_X86_AVX512_CMPLE_H) */
