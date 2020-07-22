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
 *   2020      Christopher Moore <moore@free.fr>
 */

#if !defined(SIMDE_ARM_NEON_RBIT_H)
#define SIMDE_ARM_NEON_RBIT_H

#include "reinterpret.h"
#include "types.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

SIMDE_FUNCTION_ATTRIBUTES
simde_uint8x8_t
simde_vrbit_u8(simde_uint8x8_t a) {
  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
    return vrbit_u8(a);
  #elif defined(SIMDE_X86_MMX_NATIVE)
    __m64 mask;
    mask = _mm_set1_pi8(0x55);
    a = _mm_or_si64(_mm_andnot_si64(mask, _mm_slli_pi16(a, 1)), _mm_and_si64(mask, _mm_srli_pi16(a, 1)));
    mask = _mm_set1_pi8(0x33);
    a = _mm_or_si64(_mm_andnot_si64(mask, _mm_slli_pi16(a, 2)), _mm_and_si64(mask, _mm_srli_pi16(a, 2)));
    mask = _mm_set1_pi8(0x0F);
    a = _mm_or_si64(_mm_andnot_si64(mask, _mm_slli_pi16(a, 4)), _mm_and_si64(mask, _mm_srli_pi16(a, 4)));
    return a;
  #else
    simde_uint8x8_private
      r_,
      a_ = simde_uint8x8_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
      r_.values[i] = HEDLEY_STATIC_CAST(uint8_t, (((a_.values[i] * UINT64_C(0x80200802)) & UINT64_C(0x0884422110)) * UINT64_C(0x0101010101)) >> 32);
    }

    return simde_uint8x8_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES)
  #undef vrbit_u8
  #define vrbit_u8(a) simde_vrbit_u8(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_int8x8_t
simde_vrbit_s8(simde_int8x8_t a) {
  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
    return vrbit_s8(a);
  #else
    return simde_vreinterpret_s8_u8(simde_vrbit_u8(simde_vreinterpret_u8_s8(a)));
  #endif
}
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES)
  #undef vrbit_s8
  #define vrbit_s8(a) simde_vrbit_s8(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint8x16_t
simde_vrbitq_u8(simde_uint8x16_t a) {
  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
    return vrbitq_u8(a);
  #elif defined(SIMDE_X86_SSE2_NATIVE)
    __m128i mask;
    mask = _mm_set1_epi8(0x55);
    a = _mm_or_si128(_mm_andnot_si128(mask, _mm_slli_epi16(a, 1)), _mm_and_si128(mask, _mm_srli_epi16(a, 1)));
    mask = _mm_set1_epi8(0x33);
    a = _mm_or_si128(_mm_andnot_si128(mask, _mm_slli_epi16(a, 2)), _mm_and_si128(mask, _mm_srli_epi16(a, 2)));
    mask = _mm_set1_epi8(0x0F);
    a = _mm_or_si128(_mm_andnot_si128(mask, _mm_slli_epi16(a, 4)), _mm_and_si128(mask, _mm_srli_epi16(a, 4)));
    return a;
  #elif defined(SIMDE_POWER_ALTIVEC_P6_NATIVE)
    SIMDE_POWER_ALTIVEC_VECTOR(unsigned char) shift;
    shift = vec_splat_u8(1);
    a = vec_sel(vec_sl(a, shift), vec_sr(a, shift), vec_splats(HEDLEY_STATIC_CAST(unsigned char, 0x55)));
    shift = vec_splat_u8(2);
    a = vec_sel(vec_sl(a, shift), vec_sr(a, shift), vec_splats(HEDLEY_STATIC_CAST(unsigned char, 0x33)));
    shift = vec_splat_u8(4);
    a = vec_or(vec_sl(a, shift), vec_sr(a, shift));
    return a;
  #elif defined(SIMDE_WASM_SIMD128_NATIVE)
    a = wasm_v128_bitselect(wasm_u8x16_shr(a, 1), wasm_i8x16_shl(a, 1), wasm_i8x16_splat(0x55));
    a = wasm_v128_bitselect(wasm_u8x16_shr(a, 2), wasm_i8x16_shl(a, 2), wasm_i8x16_splat(0x33));
    a = wasm_v128_or(wasm_u8x16_shr(a, 4), wasm_i8x16_shl(a, 4));
    return a;
  #else
    simde_uint8x16_private
      r_,
      a_ = simde_uint8x16_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
      r_.values[i] = HEDLEY_STATIC_CAST(uint8_t, (((a_.values[i] * UINT64_C(0x80200802)) & UINT64_C(0x0884422110)) * UINT64_C(0x0101010101)) >> 32);
    }

    return simde_uint8x16_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES)
  #undef vrbitq_u8
  #define vrbitq_u8(a) simde_vrbitq_u8(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_int8x16_t
simde_vrbitq_s8(simde_int8x16_t a) {
  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
    return vrbitq_s8(a);
  #else
    return simde_vreinterpretq_s8_u8(simde_vrbitq_u8(simde_vreinterpretq_u8_s8(a)));
  #endif
}
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES)
  #undef vrbitq_s8
  #define vrbitq_s8(a) simde_vrbitq_s8(a)
#endif

SIMDE_END_DECLS_
HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_ARM_NEON_RBIT_H) */
