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
 *   2017      Evan Nemerson <evan@nemerson.com>
 */

#if !defined(SIMDE_X86_SSE4_2_H)
#define SIMDE_X86_SSE4_2_H

#include "sse4.1.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE__BEGIN_DECLS

#if !defined(SIMDE_X86_SSE4_2_NATIVE) && defined(SIMDE_ENABLE_NATIVE_ALIASES)
#  define SIMDE_X86_SSE4_2_ENABLE_NATIVE_ALIASES
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_cmpgt_epi64 (simde__m128i a, simde__m128i b) {
#if defined(SIMDE_X86_SSE4_2_NATIVE)
  return _mm_cmpgt_epi64(a, b);
#else
  simde__m128i_private
    r_,
    a_ = simde__m128i_to_private(a),
    b_ = simde__m128i_to_private(b);

  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
    r_.neon_i64 = vreinterpretq_s64_u64(vcgtq_s64(a_.neon_i64, b_.neon_i64));
  #elif defined(SIMDE_POWER_ALTIVEC_P5)
    r_.altivec_i64 = (vector signed long long) vec_cmpgt(a_.altivec_i64, b_.altivec_i64);
  #elif defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
    r_.i64 = HEDLEY_STATIC_CAST(__typeof__(r_.i64), a_.i64 > b_.i64);
  #else
    SIMDE__VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.i64) / sizeof(r_.i64[0])) ; i++) {
      r_.i64[i] = (a_.i64[i] > b_.i64[i]) ? ~INT64_C(0) : INT64_C(0);
    }
  #endif

  return simde__m128i_from_private(r_);
#endif
}
#if defined(SIMDE_X86_SSE2_ENABLE_NATIVE_ALIASES)
#  define _mm_cmpgt_epi64(a, b) simde_mm_cmpgt_epi64(a, b)
#endif

SIMDE__END_DECLS

HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_X86_SSE4_2_H) */
