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

#if !defined(SIMDE_X86_AVX512_UNPACKLO_H)
#define SIMDE_X86_AVX512_UNPACKLO_H

#include "types.h"
#include "../avx2.h"
#include "mov.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_unpacklo_epi8 (simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_AVX512BW_NATIVE)
    return _mm512_unpacklo_epi8(a, b);
  #else
    simde__m512i_private
      r_,
      a_ = simde__m512i_to_private(a),
      b_ = simde__m512i_to_private(b);

    #if defined(SIMDE_SHUFFLE_VECTOR_)
      r_.i8 = SIMDE_SHUFFLE_VECTOR_(8, 64, a_.i8, b_.i8,
                                    0,   64,  1,  65,  2,  66,  3,  67,
                                    4,   68,  5,  69,  6,  70,  7,  71,
                                    16,  80, 17,  81, 18,  82, 19,  83,
                                    20,  84, 21,  85, 22,  86, 23,  87,
                                    32,  96, 33,  97, 34,  98, 35,  99,
                                    36, 100, 37, 101, 38, 102, 39, 103,
                                    48, 112, 49, 113, 50, 114, 51, 115,
                                    52, 116, 53, 117, 54, 118, 55, 119);
    #else
      r_.m256i[0] = simde_mm256_unpacklo_epi8(a_.m256i[0], b_.m256i[0]);
      r_.m256i[1] = simde_mm256_unpacklo_epi8(a_.m256i[1], b_.m256i[1]);
    #endif

    return simde__m512i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES)
  #undef _mm512_unpacklo_epi8
  #define _mm512_unpacklo_epi8(a, b) simde_mm512_unpacklo_epi8(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_unpacklo_epi16 (simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_AVX512BW_NATIVE)
    return _mm512_unpacklo_epi16(a, b);
  #else
    simde__m512i_private
      r_,
      a_ = simde__m512i_to_private(a),
      b_ = simde__m512i_to_private(b);

    #if defined(SIMDE_SHUFFLE_VECTOR_)
      r_.i16 =SIMDE_SHUFFLE_VECTOR_(16, 64, a_.i16, b_.i16,
                                    0,  32,  1, 33,  2, 34,  3, 35,  8, 40,  9, 41, 10, 42, 11, 43,
                                    16, 48, 17, 49, 18, 50, 19, 51, 24, 56, 25, 57, 26, 58, 27, 59);
    #else
      r_.m256i[0] = simde_mm256_unpacklo_epi16(a_.m256i[0], b_.m256i[0]);
      r_.m256i[1] = simde_mm256_unpacklo_epi16(a_.m256i[1], b_.m256i[1]);
    #endif

    return simde__m512i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES)
  #undef _mm512_unpacklo_epi16
  #define _mm512_unpacklo_epi16(a, b) simde_mm512_unpacklo_epi16(a, b)
#endif

SIMDE_END_DECLS_
HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_X86_AVX512_UNPACKLO_H) */
