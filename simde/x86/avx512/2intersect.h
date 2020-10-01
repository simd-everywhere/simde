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
 *   2020      Ashleigh Newman-Jones <ashnewman-jones@hotmail.co.uk>
 */

#if !defined(SIMDE_X86_AVX512_2INTERSECT_H)
#define SIMDE_X86_AVX512_2INTERSECT_H

#include "types.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

SIMDE_FUNCTION_ATTRIBUTES
void
simde_mm512_2intersect_epi32(simde__m512i a, simde__m512i b, simde__mmask16 *k1, simde__mmask16 *k2) {
  #if defined(SIMDE_X86_AVX512VP2INTERSECT_NATIVE)
    _mm512_2intersect_epi32(a, b, k1, k2);
  #else
    simde__m512i_private
    a_ = simde__m512i_to_private(a),
    b_ = simde__m512i_to_private(b);
    simde_memset(k1, 0, sizeof(simde__mmask16));
    simde_memset(k2, 0, sizeof(simde__mmask16));

    for (size_t i = 0 ; i < sizeof(a_.i32) / sizeof(a_.i32[0]) ; i++) {
      SIMDE_VECTORIZE
      for (size_t j = 0 ; j < sizeof(b_.i32) / sizeof(b_.i32[0]) ; j++) {
        if (a_.i32[i] == b_.i32[j]) {
          *k1 |= 1 << i;
          *k2 |= 1 << j;
        }
      }
    }
  #endif
}
#if defined(SIMDE_X86_AVX512VP2INTERSECT_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_2intersect_epi32
  #define _mm512_2intersect_epi32(a, b, k1, k2) simde_mm512_2intersect_epi32(a, b, k1, k2)
#endif

SIMDE_FUNCTION_ATTRIBUTES
void
simde_mm512_2intersect_epi64(simde__m512i a, simde__m512i b, simde__mmask8 *k1, simde__mmask8 *k2) {
  #if defined(SIMDE_X86_AVX512VP2INTERSECT_NATIVE)
    _mm512_2intersect_epi64(a, b, k1, k2);
  #else
    simde__m512i_private
    a_ = simde__m512i_to_private(a),
    b_ = simde__m512i_to_private(b);
    simde_memset(k1, 0, sizeof(simde__mmask8));
    simde_memset(k2, 0, sizeof(simde__mmask8));

    for (size_t i = 0 ; i < sizeof(a_.i64) / sizeof(a_.i64[0]) ; i++) {
      SIMDE_VECTORIZE
      for (size_t j = 0 ; j < sizeof(b_.i64) / sizeof(b_.i64[0]) ; j++) {
        if (a_.i64[i] == b_.i64[j]) {
          *k1 |= 1 << i;
          *k2 |= 1 << j;
        }
      }
    }
  #endif
}
#if defined(SIMDE_X86_AVX512VP2INTERSECT_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_2intersect_epi64
  #define _mm512_2intersect_epi64(a, b, k1, k2) simde_mm512_2intersect_epi64(a, b, k1, k2)
#endif

SIMDE_END_DECLS_
HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_X86_AVX512_2INTERSECT_H) */
