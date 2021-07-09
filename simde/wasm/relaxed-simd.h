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
 */

#if !defined(SIMDE_WASM_RELAXED_SIMD_H)
#define SIMDE_WASM_RELAXED_SIMD_H

#include "simd128.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

/* swizzle */

SIMDE_FUNCTION_ATTRIBUTES
simde_v128_t
simde_wasm_i8x16_swizzle_relaxed (simde_v128_t a, simde_v128_t b) {
  #if defined(SIMDE_WASM_SIMD128_NATIVE)
    return wasm_i8x16_swizzle(a, b);
  #else
    simde_v128_private
      a_ = simde_v128_to_private(a),
      b_ = simde_v128_to_private(b),
      r_;

    #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
      int8x8x2_t tmp = { { vget_low_s8(a_.neon_i8), vget_high_s8(a_.neon_i8) } };
      r_.neon_i8 = vcombine_s8(
        vtbl2_s8(tmp, vget_low_s8(b_.neon_i8)),
        vtbl2_s8(tmp, vget_high_s8(b_.neon_i8))
      );
    #elif defined(SIMDE_X86_SSSE3_NATIVE)
      r_.sse_m128i = _mm_shuffle_epi8(a_.sse_m128i, b_.sse_m128i);
    #elif defined(SIMDE_POWER_ALTIVEC_P6_NATIVE)
      r_.altivec_i8 = vec_perm(
        a_.altivec_i8,
        a_.altivec_i8,
        b_.altivec_u8
      );
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.i8) / sizeof(r_.i8[0])) ; i++) {
        r_.i8[i] = a_.i8[b_.u8[i] & 15];
      }
    #endif

    return simde_v128_from_private(r_);
  #endif
}
#if defined(SIMDE_WASM_SIMD128_ENABLE_NATIVE_ALIASES)
  #define wasm_i8x16_swizzle_relaxed(a, b) simde_wasm_i8x16_swizzle_relaxed((a), (b))
#endif

SIMDE_END_DECLS_
HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_WASM_RELAXED_SIMD_H) */
