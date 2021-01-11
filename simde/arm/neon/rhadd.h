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
 *   2020      Sean Maher <seanptmaher@gmail.com> (Copyright owned by Google, LLC)
 */

#if !defined(SIMDE_ARM_NEON_RHADD_H)
#define SIMDE_ARM_NEON_RHADD_H

#include "types.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

SIMDE_FUNCTION_ATTRIBUTES
simde_int8x8_t
simde_vrhadd_s8(simde_int8x8_t a, simde_int8x8_t b) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vrhadd_s8(a, b);
  #else
    simde_int8x8_private
      r_,
      a_ = simde_int8x8_to_private(a),
      b_ = simde_int8x8_to_private(b);

    #if defined(SIMDE_VECTOR_SUBSCRIPT_SCALAR)
      r_.values = (((a_.values >> HEDLEY_STATIC_CAST(int8_t, 1)) + (b_.values >> HEDLEY_STATIC_CAST(int8_t, 1))) + ((a_.values | b_.values) & HEDLEY_STATIC_CAST(int8_t, 1)));
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
        r_.values[i] = (((a_.values[i] >> HEDLEY_STATIC_CAST(int8_t, 1)) + (b_.values[i] >> HEDLEY_STATIC_CAST(int8_t, 1))) + ((a_.values[i] | b_.values[i]) & HEDLEY_STATIC_CAST(int8_t, 1)));
      }
    #endif

    return simde_int8x8_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vrhadd_s8
  #define vrhadd_s8(a, b) simde_vrhadd_s8((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_int16x4_t
simde_vrhadd_s16(simde_int16x4_t a, simde_int16x4_t b) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vrhadd_s16(a, b);
  #elif defined(SIMDE_X86_MMX_NATIVE)
    return _mm_add_pi16(_m_pand(_m_por(a, b), _mm_set1_pi16(HEDLEY_STATIC_CAST(int16_t, 1))),
                        _mm_add_pi16(_m_psrawi(a, 1), _m_psrawi(b, 1)));
  #else
    simde_int16x4_private
      r_,
      a_ = simde_int16x4_to_private(a),
      b_ = simde_int16x4_to_private(b);

    #if defined(SIMDE_VECTOR_SUBSCRIPT_SCALAR)
      r_.values = (((a_.values >> HEDLEY_STATIC_CAST(int16_t, 1)) + (b_.values >> HEDLEY_STATIC_CAST(int16_t, 1))) + ((a_.values | b_.values) & HEDLEY_STATIC_CAST(int16_t, 1)));
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
        r_.values[i] = (((a_.values[i] >> HEDLEY_STATIC_CAST(int16_t, 1)) + (b_.values[i] >> HEDLEY_STATIC_CAST(int16_t, 1))) + ((a_.values[i] | b_.values[i]) & HEDLEY_STATIC_CAST(int16_t, 1)));
      }
    #endif

    return simde_int16x4_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vrhadd_s16
  #define vrhadd_s16(a, b) simde_vrhadd_s16((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_int32x2_t
simde_vrhadd_s32(simde_int32x2_t a, simde_int32x2_t b) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vrhadd_s32(a, b);
  #elif defined(SIMDE_X86_MMX_NATIVE)
    return _mm_add_pi32(_m_pand(_m_por(a, b), _mm_set1_pi32(HEDLEY_STATIC_CAST(int32_t, 1))),
                        _mm_add_pi32(_m_psradi(a, 1), _m_psradi(b, 1)));
  #else
    simde_int32x2_private
      r_,
      a_ = simde_int32x2_to_private(a),
      b_ = simde_int32x2_to_private(b);

    #if defined(SIMDE_VECTOR_SUBSCRIPT_SCALAR)
      r_.values = (((a_.values >> HEDLEY_STATIC_CAST(int32_t, 1)) + (b_.values >> HEDLEY_STATIC_CAST(int32_t, 1))) + ((a_.values | b_.values) & HEDLEY_STATIC_CAST(int32_t, 1)));
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
        r_.values[i] = (((a_.values[i] >> HEDLEY_STATIC_CAST(int32_t, 1)) + (b_.values[i] >> HEDLEY_STATIC_CAST(int32_t, 1))) + ((a_.values[i] | b_.values[i]) & HEDLEY_STATIC_CAST(int32_t, 1)));
      }
    #endif

    return simde_int32x2_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vrhadd_s32
  #define vrhadd_s32(a, b) simde_vrhadd_s32((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint8x8_t
simde_vrhadd_u8(simde_uint8x8_t a, simde_uint8x8_t b) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vrhadd_u8(a, b);
  #else
    simde_uint8x8_private
      r_,
      a_ = simde_uint8x8_to_private(a),
      b_ = simde_uint8x8_to_private(b);

    #if defined(SIMDE_VECTOR_SUBSCRIPT_SCALAR)
      r_.values = (((a_.values >> HEDLEY_STATIC_CAST(uint8_t, 1)) + (b_.values >> HEDLEY_STATIC_CAST(uint8_t, 1))) + ((a_.values | b_.values) & HEDLEY_STATIC_CAST(uint8_t, 1)));
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
        r_.values[i] = (((a_.values[i] >> HEDLEY_STATIC_CAST(uint8_t, 1)) + (b_.values[i] >> HEDLEY_STATIC_CAST(uint8_t, 1))) + ((a_.values[i] | b_.values[i]) & HEDLEY_STATIC_CAST(uint8_t, 1)));
      }
    #endif

    return simde_uint8x8_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vrhadd_u8
  #define vrhadd_u8(a, b) simde_vrhadd_u8((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint16x4_t
simde_vrhadd_u16(simde_uint16x4_t a, simde_uint16x4_t b) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vrhadd_u16(a, b);
  #elif defined(SIMDE_X86_MMX_NATIVE)
    return _mm_add_pi16(_m_pand(_m_por(a, b), _mm_set1_pi16(HEDLEY_STATIC_CAST(int16_t, 1))),
                        _mm_add_pi16(_mm_srli_pi16(a, 1), _mm_srli_pi16(b, 1)));
  #else
    simde_uint16x4_private
      r_,
      a_ = simde_uint16x4_to_private(a),
      b_ = simde_uint16x4_to_private(b);

    #if defined(SIMDE_VECTOR_SUBSCRIPT_SCALAR)
      r_.values = (((a_.values >> HEDLEY_STATIC_CAST(uint16_t, 1)) + (b_.values >> HEDLEY_STATIC_CAST(uint16_t, 1))) + ((a_.values | b_.values) & HEDLEY_STATIC_CAST(uint16_t, 1)));
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
        r_.values[i] = (((a_.values[i] >> HEDLEY_STATIC_CAST(uint16_t, 1)) + (b_.values[i] >> HEDLEY_STATIC_CAST(uint16_t, 1))) + ((a_.values[i] | b_.values[i]) & HEDLEY_STATIC_CAST(uint16_t, 1)));
      }
    #endif

    return simde_uint16x4_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vrhadd_u16
  #define vrhadd_u16(a, b) simde_vrhadd_u16((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint32x2_t
simde_vrhadd_u32(simde_uint32x2_t a, simde_uint32x2_t b) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vrhadd_u32(a, b);
  #elif defined(SIMDE_X86_MMX_NATIVE)
    return _mm_add_pi32(_m_pand(_m_por(a, b), _mm_set1_pi32(HEDLEY_STATIC_CAST(int32_t, 1))),
                        _mm_add_pi32(_mm_srli_pi32(a, 1), _mm_srli_pi32(b, 1)));
  #else
    simde_uint32x2_private
      r_,
      a_ = simde_uint32x2_to_private(a),
      b_ = simde_uint32x2_to_private(b);

    #if defined(SIMDE_VECTOR_SUBSCRIPT_SCALAR)
      r_.values = (((a_.values >> HEDLEY_STATIC_CAST(uint32_t, 1)) + (b_.values >> HEDLEY_STATIC_CAST(uint32_t, 1))) + ((a_.values | b_.values) & HEDLEY_STATIC_CAST(uint32_t, 1)));
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
        r_.values[i] = (((a_.values[i] >> HEDLEY_STATIC_CAST(uint32_t, 1)) + (b_.values[i] >> HEDLEY_STATIC_CAST(uint32_t, 1))) + ((a_.values[i] | b_.values[i]) & HEDLEY_STATIC_CAST(uint32_t, 1)));
      }
    #endif

    return simde_uint32x2_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vrhadd_u32
  #define vrhadd_u32(a, b) simde_vrhadd_u32((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_int8x16_t
simde_vrhaddq_s8(simde_int8x16_t a, simde_int8x16_t b) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vrhaddq_s8(a, b);
  #elif defined(SIMDE_WASM_SIMD128_NATIVE)
    return wasm_i8x16_add(wasm_i8x16_add(wasm_i8x16_shr(a, 1), wasm_i8x16_shr(b, 1)), wasm_v128_and(wasm_v128_or(a, b), wasm_i8x16_splat(1)));
  #else
    simde_int8x16_private
      r_,
      a_ = simde_int8x16_to_private(a),
      b_ = simde_int8x16_to_private(b);

    #if defined(SIMDE_VECTOR_SUBSCRIPT_SCALAR)
      r_.values = (((a_.values >> HEDLEY_STATIC_CAST(int8_t, 1)) + (b_.values >> HEDLEY_STATIC_CAST(int8_t, 1))) + ((a_.values | b_.values) & HEDLEY_STATIC_CAST(int8_t, 1)));
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
        r_.values[i] = (((a_.values[i] >> HEDLEY_STATIC_CAST(int8_t, 1)) + (b_.values[i] >> HEDLEY_STATIC_CAST(int8_t, 1))) + ((a_.values[i] | b_.values[i]) & HEDLEY_STATIC_CAST(int8_t, 1)));
      }
    #endif

    return simde_int8x16_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vrhaddq_s8
  #define vrhaddq_s8(a, b) simde_vrhaddq_s8((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_int16x8_t
simde_vrhaddq_s16(simde_int16x8_t a, simde_int16x8_t b) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vrhaddq_s16(a, b);
  #elif defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_add_epi16(_mm_and_si128(_mm_or_si128(a, b), _mm_set1_epi16(HEDLEY_STATIC_CAST(int16_t, 1))),
                        _mm_add_epi16(_mm_srai_epi16(a, 1), _mm_srai_epi16(b, 1)));
  #elif defined(SIMDE_WASM_SIMD128_NATIVE)
    return wasm_i16x8_add(wasm_i16x8_add(wasm_i16x8_shr(a, 1), wasm_i16x8_shr(b, 1)), wasm_v128_and(wasm_v128_or(a, b), wasm_i16x8_splat(1)));
  #else
    simde_int16x8_private
      r_,
      a_ = simde_int16x8_to_private(a),
      b_ = simde_int16x8_to_private(b);

    #if defined(SIMDE_VECTOR_SUBSCRIPT_SCALAR)
      r_.values = (((a_.values >> HEDLEY_STATIC_CAST(int16_t, 1)) + (b_.values >> HEDLEY_STATIC_CAST(int16_t, 1))) + ((a_.values | b_.values) & HEDLEY_STATIC_CAST(int16_t, 1)));
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
        r_.values[i] = (((a_.values[i] >> HEDLEY_STATIC_CAST(int16_t, 1)) + (b_.values[i] >> HEDLEY_STATIC_CAST(int16_t, 1))) + ((a_.values[i] | b_.values[i]) & HEDLEY_STATIC_CAST(int16_t, 1)));
      }
    #endif

    return simde_int16x8_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vrhaddq_s16
  #define vrhaddq_s16(a, b) simde_vrhaddq_s16((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_int32x4_t
simde_vrhaddq_s32(simde_int32x4_t a, simde_int32x4_t b) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vrhaddq_s32(a, b);
  #elif defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_add_epi32(_mm_and_si128(_mm_or_si128(a, b), _mm_set1_epi32(HEDLEY_STATIC_CAST(int32_t, 1))),
                        _mm_add_epi32(_mm_srai_epi32(a, 1), _mm_srai_epi32(b, 1)));
  #elif defined(SIMDE_WASM_SIMD128_NATIVE)
    return wasm_i32x4_add(wasm_i32x4_add(wasm_i32x4_shr(a, 1), wasm_i32x4_shr(b, 1)), wasm_v128_and(wasm_v128_or(a, b), wasm_i32x4_splat(1)));
  #else
    simde_int32x4_private
      r_,
      a_ = simde_int32x4_to_private(a),
      b_ = simde_int32x4_to_private(b);

    #if defined(SIMDE_VECTOR_SUBSCRIPT_SCALAR)
      r_.values = (((a_.values >> HEDLEY_STATIC_CAST(int32_t, 1)) + (b_.values >> HEDLEY_STATIC_CAST(int32_t, 1))) + ((a_.values | b_.values) & HEDLEY_STATIC_CAST(int32_t, 1)));
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
        r_.values[i] = (((a_.values[i] >> HEDLEY_STATIC_CAST(int32_t, 1)) + (b_.values[i] >> HEDLEY_STATIC_CAST(int32_t, 1))) + ((a_.values[i] | b_.values[i]) & HEDLEY_STATIC_CAST(int32_t, 1)));
      }
    #endif

    return simde_int32x4_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vrhaddq_s32
  #define vrhaddq_s32(a, b) simde_vrhaddq_s32((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint8x16_t
simde_vrhaddq_u8(simde_uint8x16_t a, simde_uint8x16_t b) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vrhaddq_u8(a, b);
  #elif defined(SIMDE_WASM_SIMD128_NATIVE)
    return wasm_u8x16_avgr(a, b);
  #else
    simde_uint8x16_private
      r_,
      a_ = simde_uint8x16_to_private(a),
      b_ = simde_uint8x16_to_private(b);

    #if defined(SIMDE_VECTOR_SUBSCRIPT_SCALAR)
      r_.values = (((a_.values >> HEDLEY_STATIC_CAST(uint8_t, 1)) + (b_.values >> HEDLEY_STATIC_CAST(uint8_t, 1))) + ((a_.values | b_.values) & HEDLEY_STATIC_CAST(uint8_t, 1)));
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
        r_.values[i] = (((a_.values[i] >> HEDLEY_STATIC_CAST(uint8_t, 1)) + (b_.values[i] >> HEDLEY_STATIC_CAST(uint8_t, 1))) + ((a_.values[i] | b_.values[i]) & HEDLEY_STATIC_CAST(uint8_t, 1)));
      }
    #endif

    return simde_uint8x16_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vrhaddq_u8
  #define vrhaddq_u8(a, b) simde_vrhaddq_u8((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint16x8_t
simde_vrhaddq_u16(simde_uint16x8_t a, simde_uint16x8_t b) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vrhaddq_u16(a, b);
  #elif defined(SIMDE_WASM_SIMD128_NATIVE)
    return wasm_u16x8_avgr(a, b);
  #else
    simde_uint16x8_private
      r_,
      a_ = simde_uint16x8_to_private(a),
      b_ = simde_uint16x8_to_private(b);

    #if defined(SIMDE_VECTOR_SUBSCRIPT_SCALAR)
      r_.values = (((a_.values >> HEDLEY_STATIC_CAST(uint16_t, 1)) + (b_.values >> HEDLEY_STATIC_CAST(uint16_t, 1))) + ((a_.values | b_.values) & HEDLEY_STATIC_CAST(uint16_t, 1)));
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
        r_.values[i] = (((a_.values[i] >> HEDLEY_STATIC_CAST(uint16_t, 1)) + (b_.values[i] >> HEDLEY_STATIC_CAST(uint16_t, 1))) + ((a_.values[i] | b_.values[i]) & HEDLEY_STATIC_CAST(uint16_t, 1)));
      }
    #endif

    return simde_uint16x8_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vrhaddq_u16
  #define vrhaddq_u16(a, b) simde_vrhaddq_u16((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint32x4_t
simde_vrhaddq_u32(simde_uint32x4_t a, simde_uint32x4_t b) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vrhaddq_u32(a, b);
  #elif defined(SIMDE_WASM_SIMD128_NATIVE)
    return wasm_i32x4_add(wasm_i32x4_add(wasm_u32x4_shr(a, 1), wasm_u32x4_shr(b, 1)), wasm_v128_and(wasm_v128_or(a, b), wasm_i32x4_splat(1)));
  #else
    simde_uint32x4_private
      r_,
      a_ = simde_uint32x4_to_private(a),
      b_ = simde_uint32x4_to_private(b);

    #if defined(SIMDE_VECTOR_SUBSCRIPT_SCALAR)
      r_.values = (((a_.values >> HEDLEY_STATIC_CAST(uint32_t, 1)) + (b_.values >> HEDLEY_STATIC_CAST(uint32_t, 1))) + ((a_.values | b_.values) & HEDLEY_STATIC_CAST(uint32_t, 1)));
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
        r_.values[i] = (((a_.values[i] >> HEDLEY_STATIC_CAST(uint32_t, 1)) + (b_.values[i] >> HEDLEY_STATIC_CAST(uint32_t, 1))) + ((a_.values[i] | b_.values[i]) & HEDLEY_STATIC_CAST(uint32_t, 1)));
      }
    #endif

    return simde_uint32x4_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vrhaddq_u32
  #define vrhaddq_u32(a, b) simde_vrhaddq_u32((a), (b))
#endif

SIMDE_END_DECLS_
HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_ARM_NEON_RHADD_H) */
