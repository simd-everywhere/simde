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

#if !defined(SIMDE_ARM_NEON_SHL_H)
#define SIMDE_ARM_NEON_SHL_H

#include "types.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

SIMDE_FUNCTION_ATTRIBUTES
simde_int8x8_t
simde_vshl_n_s8 (const simde_int8x8_t a, const int32_t b)
  SIMDE_REQUIRE_CONSTANT_RANGE(b, 0, 7) {
  simde_int8x8_private
    r_,
    a_ = simde_int8x8_to_private(a);

  #if defined(SIMDE_VECTOR_SUBSCRIPT_SCALAR)
    r_.values = a_.values << b;
  #else
    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
      r_.values[i] = HEDLEY_STATIC_CAST(int8_t, a_.values[i] << b);
    }
  #endif

  return simde_int8x8_from_private(r_);
}
#if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
  #define simde_vshl_n_s8(a, b) vshl_n_s8((a), (b))
#elif defined(SIMDE_X86_MMX_NATIVE)
  #define simde_vshl_n_s8(a, b) \
    _mm_andnot_si64(_mm_set1_pi8((1 << b) - 1), _mm_slli_si64((a), (b)))
#endif
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vshl_n_s8
  #define vshl_n_s8(a, b) simde_vshl_n_s8((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_int16x4_t
simde_vshl_n_s16 (const simde_int16x4_t a, const int32_t b)
  SIMDE_REQUIRE_CONSTANT_RANGE(b, 0, 15) {
  simde_int16x4_private
    r_,
    a_ = simde_int16x4_to_private(a);

  #if defined(SIMDE_VECTOR_SUBSCRIPT_SCALAR)
    r_.values = a_.values << b;
  #else
    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
      r_.values[i] = HEDLEY_STATIC_CAST(int16_t, a_.values[i] << b);
    }
  #endif

  return simde_int16x4_from_private(r_);
}
#if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
  #define simde_vshl_n_s16(a, b) vshl_n_s16((a), (b))
#elif defined(SIMDE_X86_MMX_NATIVE)
  #define simde_vshl_n_s16(a, b) _mm_slli_pi16((a), (b))
#endif
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vshl_n_s16
  #define vshl_n_s16(a, b) simde_vshl_n_s16((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_int32x2_t
simde_vshl_n_s32 (const simde_int32x2_t a, const int32_t b)
  SIMDE_REQUIRE_CONSTANT_RANGE(b, 0, 31) {
  simde_int32x2_private
    r_,
    a_ = simde_int32x2_to_private(a);

  #if defined(SIMDE_VECTOR_SUBSCRIPT_SCALAR)
    r_.values = a_.values << b;
  #else
    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
      r_.values[i] = a_.values[i] << b;
    }
  #endif

  return simde_int32x2_from_private(r_);
}
#if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
  #define simde_vshl_n_s32(a, b) vshl_n_s32((a), (b))
#elif defined(SIMDE_X86_MMX_NATIVE)
  #define simde_vshl_n_s32(a, b) _mm_slli_pi32((a), (b))
#endif
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vshl_n_s32
  #define vshl_n_s32(a, b) simde_vshl_n_s32((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_int64x1_t
simde_vshl_n_s64 (const simde_int64x1_t a, const int32_t b)
  SIMDE_REQUIRE_CONSTANT_RANGE(b, 0, 63) {
  simde_int64x1_private
    r_,
    a_ = simde_int64x1_to_private(a);

  #if defined(SIMDE_VECTOR_SUBSCRIPT_SCALAR)
    r_.values = a_.values << b;
  #else
    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
      r_.values[i] = a_.values[i] << b;
    }
  #endif

  return simde_int64x1_from_private(r_);
}
#if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
  #define simde_vshl_n_s64(a, b) vshl_n_s64((a), (b))
#elif defined(SIMDE_X86_MMX_NATIVE)
  #define simde_vshl_n_s64(a, b) _mm_slli_si64((a), (b))
#endif
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vshl_n_s64
  #define vshl_n_s64(a, b) simde_vshl_n_u64((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint8x8_t
simde_vshl_n_u8 (const simde_uint8x8_t a, const int32_t b)
  SIMDE_REQUIRE_CONSTANT_RANGE(b, 0, 7) {
  simde_uint8x8_private
    r_,
    a_ = simde_uint8x8_to_private(a);

  #if defined(SIMDE_VECTOR_SUBSCRIPT_SCALAR)
    r_.values = a_.values << b;
  #else
    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
      r_.values[i] = HEDLEY_STATIC_CAST(uint8_t, a_.values[i] << b);
    }
  #endif

  return simde_uint8x8_from_private(r_);
}
#if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
  #define simde_vshl_n_u8(a, b) vshl_n_u8((a), (b))
#elif defined(SIMDE_X86_MMX_NATIVE)
  #define simde_vshl_n_u8(a, b) \
    _mm_andnot_si64(_mm_set1_pi8((1 << b) - 1), _mm_slli_si64((a), (b)))
#endif
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vshl_n_u8
  #define vshl_n_u8(a, b) simde_vshl_n_u8((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint16x4_t
simde_vshl_n_u16 (const simde_uint16x4_t a, const int32_t b)
  SIMDE_REQUIRE_CONSTANT_RANGE(b, 0, 15) {
  simde_uint16x4_private
    r_,
    a_ = simde_uint16x4_to_private(a);

  #if defined(SIMDE_VECTOR_SUBSCRIPT_SCALAR)
    r_.values = a_.values << b;
  #else
    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
      r_.values[i] = HEDLEY_STATIC_CAST(uint16_t, a_.values[i] << b);
    }
  #endif

  return simde_uint16x4_from_private(r_);
}
#if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
  #define simde_vshl_n_u16(a, b) vshl_n_u16((a), (b))
#elif defined(SIMDE_X86_MMX_NATIVE)
  #define simde_vshl_n_u16(a, b) _mm_slli_pi16((a), (b))
#endif
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vshl_n_u16
  #define vshl_n_u16(a, b) simde_vshl_n_u16((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint32x2_t
simde_vshl_n_u32 (const simde_uint32x2_t a, const int32_t b)
  SIMDE_REQUIRE_CONSTANT_RANGE(b, 0, 31) {
  simde_uint32x2_private
    r_,
    a_ = simde_uint32x2_to_private(a);

  #if defined(SIMDE_VECTOR_SUBSCRIPT_SCALAR)
    r_.values = a_.values << b;
  #else
    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
      r_.values[i] = a_.values[i] << b;
    }
  #endif

  return simde_uint32x2_from_private(r_);
}
#if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
  #define simde_vshl_n_u32(a, b) vshl_n_u32((a), (b))
#elif defined(SIMDE_X86_MMX_NATIVE)
  #define simde_vshl_n_u32(a, b) _mm_slli_pi32((a), (b))
#endif
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vshl_n_u32
  #define vshl_n_u32(a, b) simde_vshl_n_u32((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint64x1_t
simde_vshl_n_u64 (const simde_uint64x1_t a, const int32_t b)
  SIMDE_REQUIRE_CONSTANT_RANGE(b, 0, 63) {
  simde_uint64x1_private
    r_,
    a_ = simde_uint64x1_to_private(a);

  #if defined(SIMDE_VECTOR_SUBSCRIPT_SCALAR)
    r_.values = a_.values << b;
  #else
    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
      r_.values[i] = a_.values[i] << b;
    }
  #endif

  return simde_uint64x1_from_private(r_);
}
#if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
  #define simde_vshl_n_u64(a, b) vshl_n_u64((a), (b))
#elif defined(SIMDE_X86_MMX_NATIVE)
  #define simde_vshl_n_u64(a, b) _mm_slli_si64((a), (b))
#endif
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vshl_n_u64
  #define vshl_n_u64(a, b) simde_vshl_n_u64((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_int8x16_t
simde_vshlq_n_s8 (const simde_int8x16_t a, const int32_t b)
  SIMDE_REQUIRE_CONSTANT_RANGE(b, 0, 7) {
  simde_int8x16_private
    r_,
    a_ = simde_int8x16_to_private(a);

  #if defined(SIMDE_VECTOR_SUBSCRIPT_SCALAR)
    r_.values = a_.values << b;
  #else
    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
      r_.values[i] = HEDLEY_STATIC_CAST(int8_t, a_.values[i] << b);
    }
  #endif

  return simde_int8x16_from_private(r_);
}
#if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
  #define simde_vshlq_n_s8(a, b) vshlq_n_s8((a), (b))
#elif defined(SIMDE_X86_SSE2_NATIVE)
  #define simde_vshlq_n_s8(a, b) \
    _mm_andnot_si128(_mm_set1_epi8((1 << b) - 1), _mm_slli_epi64((a), (b)))
#elif defined(SIMDE_POWER_ALTIVEC_P5_NATIVE)
  #define simde_vshlq_n_s8(a, b) vec_sl((a), vec_splat_u8(b))
#elif defined(SIMDE_WASM_SIMD128_NATIVE)
  /* N.B. CM: WASM doesn't seem to require an constant shift count but use macro just in case */
  #define simde_vshlq_n_s8(a, b) wasm_i8x16_shl((a), (b))
#endif
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vshlq_n_s8
  #define vshlq_n_s8(a, b) simde_vshlq_n_s8((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_int16x8_t
simde_vshlq_n_s16 (const simde_int16x8_t a, const int32_t b)
  SIMDE_REQUIRE_CONSTANT_RANGE(b, 0, 15) {
  simde_int16x8_private
    r_,
    a_ = simde_int16x8_to_private(a);

  #if defined(SIMDE_VECTOR_SUBSCRIPT_SCALAR)
    r_.values = a_.values << b;
  #else
    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
      r_.values[i] = HEDLEY_STATIC_CAST(int16_t, a_.values[i] << b);
    }
  #endif

  return simde_int16x8_from_private(r_);
}
#if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
  #define simde_vshlq_n_s16(a, b) vshlq_n_s16((a), (b))
#elif defined(SIMDE_X86_SSE2_NATIVE)
  #define simde_vshlq_n_s16(a, b) _mm_slli_epi16((a), (b))
#elif defined(SIMDE_POWER_ALTIVEC_P5_NATIVE)
  #define simde_vshlq_n_s16(a, b) vec_sl((a), vec_splat_u16(b))
#elif defined(SIMDE_WASM_SIMD128_NATIVE)
  /* N.B. CM: WASM doesn't seem to require an constant shift count but use macro just in case */
  #define simde_vshlq_n_s16(a, b) wasm_i16x8_shl((a), (b))
#endif
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vshlq_n_s16
  #define vshlq_n_s16(a, b) simde_vshlq_n_s16((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_int32x4_t
simde_vshlq_n_s32 (const simde_int32x4_t a, const int32_t b)
  SIMDE_REQUIRE_CONSTANT_RANGE(b, 0, 31) {
  simde_int32x4_private
    r_,
    a_ = simde_int32x4_to_private(a);

  #if defined(SIMDE_VECTOR_SUBSCRIPT_SCALAR)
    r_.values = a_.values << b;
  #else
    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
      r_.values[i] = a_.values[i] << b;
    }
  #endif

  return simde_int32x4_from_private(r_);
}
#if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
  #define simde_vshlq_n_s32(a, b) vshlq_n_s32((a), (b))
#elif defined(SIMDE_X86_SSE2_NATIVE)
  #define simde_vshlq_n_s32(a, b) _mm_slli_epi32((a), (b))
#elif defined(SIMDE_POWER_ALTIVEC_P5_NATIVE)
  #define simde_vshlq_n_s32(a, b) \
    vec_sl((a), vec_splats(HEDLEY_STATIC_CAST(unsigned int, (b))))
#elif defined(SIMDE_WASM_SIMD128_NATIVE)
  /* N.B. CM: WASM doesn't seem to require an constant shift count but use macro just in case */
  #define simde_vshlq_n_s32(a, b) wasm_i32x4_shl((a), (b))
#endif
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vshlq_n_s32
  #define vshlq_n_s32(a, b) simde_vshlq_n_s32((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_int64x2_t
simde_vshlq_n_s64 (const simde_int64x2_t a, const int32_t b)
  SIMDE_REQUIRE_CONSTANT_RANGE(b, 0, 63) {
  simde_int64x2_private
    r_,
    a_ = simde_int64x2_to_private(a);

  #if defined(SIMDE_VECTOR_SUBSCRIPT_SCALAR)
    r_.values = a_.values << b;
  #else
    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
      r_.values[i] = a_.values[i] << b;
    }
  #endif

  return simde_int64x2_from_private(r_);
}
#if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
  #define simde_vshlq_n_s64(a, b) vshlq_n_s64((a), (b))
#elif defined(SIMDE_X86_SSE2_NATIVE)
  #define simde_vshlq_n_s64(a, b) _mm_slli_epi64((a), (b))
#elif defined(SIMDE_POWER_ALTIVEC_P5_NATIVE)
  #define simde_vshlq_n_s64(a, b) \
    vec_sl((a), vec_splats(HEDLEY_STATIC_CAST(unsigned long long, (b))))
#elif defined(SIMDE_WASM_SIMD128_NATIVE)
  /* N.B. CM: WASM doesn't seem to require an constant shift count but use macro just in case */
  #define simde_vshlq_n_s64(a, b) wasm_i64x2_shl((a), (b))
#endif
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vshlq_n_s64
  #define vshlq_n_s64(a, b) simde_vshlq_n_s64((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint8x16_t
simde_vshlq_n_u8 (const simde_uint8x16_t a, const int32_t b)
  SIMDE_REQUIRE_CONSTANT_RANGE(b, 0, 7) {
  simde_uint8x16_private
    r_,
    a_ = simde_uint8x16_to_private(a);

  #if defined(SIMDE_VECTOR_SUBSCRIPT_SCALAR)
    r_.values = a_.values << b;
  #else
    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
      r_.values[i] = HEDLEY_STATIC_CAST(uint8_t, a_.values[i] << b);
    }
  #endif

  return simde_uint8x16_from_private(r_);
}
#if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
  #define simde_vshlq_n_u8(a, b) vshlq_n_u8((a), (b))
#elif defined(SIMDE_X86_SSE2_NATIVE)
  #define simde_vshlq_n_u8(a, b) \
    _mm_andnot_si128(_mm_set1_epi8((1 << b) - 1), _mm_slli_epi64((a), (b)))
#elif defined(SIMDE_POWER_ALTIVEC_P5_NATIVE)
  #define simde_vshlq_n_u8(a, b) vec_sl((a), vec_splat_u8(b))
#elif defined(SIMDE_WASM_SIMD128_NATIVE)
  /* N.B. CM: WASM doesn't seem to require an constant shift count but use macro just in case */
  #define simde_vshlq_n_u8(a, b) wasm_i8x16_shl((a), (b))
#endif
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vshlq_n_u8
  #define vshlq_n_u8(a, b) simde_vshlq_n_u8((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint16x8_t
simde_vshlq_n_u16 (const simde_uint16x8_t a, const int32_t b)
  SIMDE_REQUIRE_CONSTANT_RANGE(b, 0, 15) {
  simde_uint16x8_private
    r_,
    a_ = simde_uint16x8_to_private(a);

  #if defined(SIMDE_VECTOR_SUBSCRIPT_SCALAR)
    r_.values = a_.values << b;
  #else
    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
      r_.values[i] = HEDLEY_STATIC_CAST(uint16_t, a_.values[i] << b);
    }
  #endif

  return simde_uint16x8_from_private(r_);
}
#if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
  #define simde_vshlq_n_u16(a, b) vshlq_n_u16((a), (b))
#elif defined(SIMDE_X86_SSE2_NATIVE)
  #define simde_vshlq_n_u16(a, b) _mm_slli_epi16((a), (b))
#elif defined(SIMDE_POWER_ALTIVEC_P5_NATIVE)
  #define simde_vshlq_n_u16(a, b) vec_sl((a), vec_splat_u16(b))
#elif defined(SIMDE_WASM_SIMD128_NATIVE)
  /* N.B. CM: WASM doesn't seem to require an constant shift count but use macro just in case */
  #define simde_vshlq_n_u16(a, b) wasm_i16x8_shl((a), (b))
#endif
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vshlq_n_u16
  #define vshlq_n_u16(a, b) simde_vshlq_n_u16((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint32x4_t
simde_vshlq_n_u32 (const simde_uint32x4_t a, const int32_t b)
  SIMDE_REQUIRE_CONSTANT_RANGE(b, 0, 31) {
  simde_uint32x4_private
    r_,
    a_ = simde_uint32x4_to_private(a);

  #if defined(SIMDE_VECTOR_SUBSCRIPT_SCALAR)
    r_.values = a_.values << b;
  #else
    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
      r_.values[i] = a_.values[i] << b;
    }
  #endif

  return simde_uint32x4_from_private(r_);
}
#if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
  #define simde_vshlq_n_u32(a, b) vshlq_n_u32((a), (b))
#elif defined(SIMDE_X86_SSE2_NATIVE)
  #define simde_vshlq_n_u32(a, b) _mm_slli_epi32((a), (b))
#elif defined(SIMDE_POWER_ALTIVEC_P5_NATIVE)
  #define simde_vshlq_n_u32(a, b) \
    vec_sl((a), vec_splats(HEDLEY_STATIC_CAST(unsigned int, (b))))
#elif defined(SIMDE_WASM_SIMD128_NATIVE)
  /* N.B. CM: WASM doesn't seem to require an constant shift count but use macro just in case */
  #define simde_vshlq_n_u32(a, b) wasm_i32x4_shl((a), (b))
#endif
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vshlq_n_u32
  #define vshlq_n_u32(a, b) simde_vshlq_n_u32((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint64x2_t
simde_vshlq_n_u64 (const simde_uint64x2_t a, const int32_t b)
  SIMDE_REQUIRE_CONSTANT_RANGE(b, 0, 63) {
  simde_uint64x2_private
    r_,
    a_ = simde_uint64x2_to_private(a);

  #if defined(SIMDE_VECTOR_SUBSCRIPT_SCALAR)
    r_.values = a_.values << b;
  #else
    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
      r_.values[i] = a_.values[i] << b;
    }
  #endif

  return simde_uint64x2_from_private(r_);
}
#if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
  #define simde_vshlq_n_u64(a, b) vshlq_n_u64((a), (b))
#elif defined(SIMDE_X86_SSE2_NATIVE)
  #define simde_vshlq_n_u64(a, b) _mm_slli_epi64((a), (b))
#elif defined(SIMDE_POWER_ALTIVEC_P5_NATIVE)
  #define simde_vshlq_n_u64(a, b) \
    vec_sl((a), vec_splats(HEDLEY_STATIC_CAST(unsigned long long, (b))))
#elif defined(SIMDE_WASM_SIMD128_NATIVE)
  /* N.B. CM: WASM doesn't seem to require an constant shift count but use macro just in case */
  #define simde_vshlq_n_u64(a, b) wasm_i64x2_shl((a), (b))
#endif
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vshlq_n_u64
  #define vshlq_n_u64(a, b) simde_vshlq_n_u64((a), (b))
#endif

SIMDE_END_DECLS_
HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_ARM_NEON_SHL_H) */
