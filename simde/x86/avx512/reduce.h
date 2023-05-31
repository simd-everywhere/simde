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
 *   2023      Michael R. Crusoe <crusoe@debian.org>
 */

#if !defined(SIMDE_X86_AVX512_REDUCE_H)
#define SIMDE_X86_AVX512_REDUCE_H

#include "types.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

SIMDE_FUNCTION_ATTRIBUTES
simde_float16
simde_mm512_reduce_max_ph(simde__m512h a) {
  #if defined(SIMDE_X86_AVX512FP16_NATIVE)
    return _mm512_reduce_max_ph(a);
  #else
    simde__m512h_private a_;
    simde_float16 r;
    a_ = simde__m512h_to_private(a);

    r = SIMDE_NINFINITYHF;
    #if defined(SIMDE_FLOAT16_VECTOR)
    SIMDE_VECTORIZE_REDUCTION(max:r)
    #endif
    for (size_t i = 0 ; i < (sizeof(a_.f16) / sizeof(a_.f16[0])) ; i++) {
      r = simde_float16_to_float32(a_.f16[i]) > simde_float16_to_float32(r) ? a_.f16[i] : r;
    }
    return r;
  #endif
}
#if defined(SIMDE_X86_AVX512FP16_ENABLE_NATIVE_ALIASES)
#  define _mm512_reduce_max_ph(a) simde_mm512_reduce_max_ph((a))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_float16
simde_mm512_reduce_min_ph(simde__m512h a) {
  #if defined(SIMDE_X86_AVX512FP16_NATIVE)
    return _mm512_reduce_min_ph(a);
  #else
    simde__m512h_private a_;
    simde_float16 r;
    a_ = simde__m512h_to_private(a);

    r = SIMDE_INFINITYHF;
    #if defined(SIMDE_FLOAT16_VECTOR)
    SIMDE_VECTORIZE_REDUCTION(min:r)
    #endif
    for (size_t i = 0 ; i < (sizeof(a_.f16) / sizeof(a_.f16[0])) ; i++) {
      r = simde_float16_to_float32(a_.f16[i]) < simde_float16_to_float32(r) ? a_.f16[i] : r;
    }
    return r;
  #endif
}
#if defined(SIMDE_X86_AVX512FP16_ENABLE_NATIVE_ALIASES)
#  define _mm512_reduce_min_ph(a) simde_mm512_reduce_min_ph((a))
#endif

SIMDE_END_DECLS_
HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_X86_AVX512_REDUCE_H) */
