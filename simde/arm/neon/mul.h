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

#if !defined(SIMDE_ARM_NEON_MUL_H)
#define SIMDE_ARM_NEON_MUL_H

#include "types.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

SIMDE_FUNCTION_ATTRIBUTES
simde_float32x2_t
simde_vmul_f32(simde_float32x2_t a, simde_float32x2_t b) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vmul_f32(a, b);
  #else
    simde_float32x2_private
      r_,
      a_ = simde_float32x2_to_private(a),
      b_ = simde_float32x2_to_private(b);

    #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r_.values = a_.values * b_.values;
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
        r_.values[i] = a_.values[i] * b_.values[i];
      }
    #endif

    return simde_float32x2_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vmul_f32
  #define vmul_f32(a, b) simde_vmul_f32((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_float64x1_t
simde_vmul_f64(simde_float64x1_t a, simde_float64x1_t b) {
  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
    return vmul_f64(a, b);
  #else
    simde_float64x1_private
      r_,
      a_ = simde_float64x1_to_private(a),
      b_ = simde_float64x1_to_private(b);

    #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r_.values = a_.values * b_.values;
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
        r_.values[i] = a_.values[i] * b_.values[i];
      }
    #endif

    return simde_float64x1_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES)
  #undef vmul_f64
  #define vmul_f64(a, b) simde_vmul_f64((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_int8x8_t
simde_vmul_s8(simde_int8x8_t a, simde_int8x8_t b) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vmul_s8(a, b);
  #else
    simde_int8x8_private
      r_,
      a_ = simde_int8x8_to_private(a),
      b_ = simde_int8x8_to_private(b);

    #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r_.values = a_.values * b_.values;
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
        r_.values[i] = a_.values[i] * b_.values[i];
      }
    #endif

    return simde_int8x8_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vmul_s8
  #define vmul_s8(a, b) simde_vmul_s8((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_int16x4_t
simde_vmul_s16(simde_int16x4_t a, simde_int16x4_t b) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vmul_s16(a, b);
  #elif defined(SIMDE_X86_MMX_NATIVE)
    return _m_pmullw(a, b);
  #else
    simde_int16x4_private
      r_,
      a_ = simde_int16x4_to_private(a),
      b_ = simde_int16x4_to_private(b);

    #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r_.values = a_.values * b_.values;
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
        r_.values[i] = a_.values[i] * b_.values[i];
      }
    #endif

    return simde_int16x4_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vmul_s16
  #define vmul_s16(a, b) simde_vmul_s16((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_int32x2_t
simde_vmul_s32(simde_int32x2_t a, simde_int32x2_t b) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vmul_s32(a, b);
  #else
    simde_int32x2_private
      r_,
      a_ = simde_int32x2_to_private(a),
      b_ = simde_int32x2_to_private(b);

    #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r_.values = a_.values * b_.values;
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
        r_.values[i] = a_.values[i] * b_.values[i];
      }
    #endif

    return simde_int32x2_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vmul_s32
  #define vmul_s32(a, b) simde_vmul_s32((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_int64x1_t
simde_x_vmul_s64(simde_int64x1_t a, simde_int64x1_t b) {
  simde_int64x1_private
    r_,
    a_ = simde_int64x1_to_private(a),
    b_ = simde_int64x1_to_private(b);

  #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
    r_.values = a_.values * b_.values;
  #else
    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
      r_.values[i] = a_.values[i] * b_.values[i];
    }
  #endif

  return simde_int64x1_from_private(r_);
}

SIMDE_FUNCTION_ATTRIBUTES
simde_uint8x8_t
simde_vmul_u8(simde_uint8x8_t a, simde_uint8x8_t b) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vmul_u8(a, b);
  #else
    simde_uint8x8_private
      r_,
      a_ = simde_uint8x8_to_private(a),
      b_ = simde_uint8x8_to_private(b);

    #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r_.values = a_.values * b_.values;
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
        r_.values[i] = a_.values[i] * b_.values[i];
      }
    #endif

    return simde_uint8x8_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vmul_u8
  #define vmul_u8(a, b) simde_vmul_u8((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint16x4_t
simde_vmul_u16(simde_uint16x4_t a, simde_uint16x4_t b) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vmul_u16(a, b);
  #else
    simde_uint16x4_private
      r_,
      a_ = simde_uint16x4_to_private(a),
      b_ = simde_uint16x4_to_private(b);

    #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r_.values = a_.values * b_.values;
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
        r_.values[i] = a_.values[i] * b_.values[i];
      }
    #endif

    return simde_uint16x4_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vmul_u16
  #define vmul_u16(a, b) simde_vmul_u16((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint32x2_t
simde_vmul_u32(simde_uint32x2_t a, simde_uint32x2_t b) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vmul_u32(a, b);
  #else
    simde_uint32x2_private
      r_,
      a_ = simde_uint32x2_to_private(a),
      b_ = simde_uint32x2_to_private(b);

    #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r_.values = a_.values * b_.values;
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
        r_.values[i] = a_.values[i] * b_.values[i];
      }
    #endif

    return simde_uint32x2_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vmul_u32
  #define vmul_u32(a, b) simde_vmul_u32((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint64x1_t
simde_x_vmul_u64(simde_uint64x1_t a, simde_uint64x1_t b) {
  simde_uint64x1_private
    r_,
    a_ = simde_uint64x1_to_private(a),
    b_ = simde_uint64x1_to_private(b);

  #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
    r_.values = a_.values * b_.values;
  #else
    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
      r_.values[i] = a_.values[i] * b_.values[i];
    }
  #endif

  return simde_uint64x1_from_private(r_);
}

SIMDE_FUNCTION_ATTRIBUTES
simde_float32x4_t
simde_vmulq_f32(simde_float32x4_t a, simde_float32x4_t b) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vmulq_f32(a, b);
  #elif defined(SIMDE_X86_SSE_NATIVE)
    return _mm_mul_ps(a, b);
  #elif defined(SIMDE_WASM_SIMD128_NATIVE)
    return wasm_f32x4_mul(a, b);
  #else
    simde_float32x4_private
      r_,
      a_ = simde_float32x4_to_private(a),
      b_ = simde_float32x4_to_private(b);

    #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r_.values = a_.values * b_.values;
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
        r_.values[i] = a_.values[i] * b_.values[i];
      }
    #endif

    return simde_float32x4_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vmulq_f32
  #define vmulq_f32(a, b) simde_vmulq_f32((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_float64x2_t
simde_vmulq_f64(simde_float64x2_t a, simde_float64x2_t b) {
  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
    return vmulq_f64(a, b);
  #elif defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_mul_pd(a, b);
  #elif defined(SIMDE_WASM_SIMD128_NATIVE)
    return wasm_f64x2_mul(a, b);
  #else
    simde_float64x2_private
      r_,
      a_ = simde_float64x2_to_private(a),
      b_ = simde_float64x2_to_private(b);

    #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r_.values = a_.values * b_.values;
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
        r_.values[i] = a_.values[i] * b_.values[i];
      }
    #endif

    return simde_float64x2_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES)
  #undef vmulq_f64
  #define vmulq_f64(a, b) simde_vmulq_f64((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_int8x16_t
simde_vmulq_s8(simde_int8x16_t a, simde_int8x16_t b) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vmulq_s8(a, b);
  #else
    simde_int8x16_private
      r_,
      a_ = simde_int8x16_to_private(a),
      b_ = simde_int8x16_to_private(b);

    #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r_.values = a_.values * b_.values;
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
        r_.values[i] = a_.values[i] * b_.values[i];
      }
    #endif

    return simde_int8x16_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vmulq_s8
  #define vmulq_s8(a, b) simde_vmulq_s8((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_int16x8_t
simde_vmulq_s16(simde_int16x8_t a, simde_int16x8_t b) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vmulq_s16(a, b);
  #elif defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_mullo_epi16(a, b);
  #else
    simde_int16x8_private
      r_,
      a_ = simde_int16x8_to_private(a),
      b_ = simde_int16x8_to_private(b);

    #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r_.values = a_.values * b_.values;
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
        r_.values[i] = a_.values[i] * b_.values[i];
      }
    #endif

    return simde_int16x8_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vmulq_s16
  #define vmulq_s16(a, b) simde_vmulq_s16((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_int32x4_t
simde_vmulq_s32(simde_int32x4_t a, simde_int32x4_t b) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vmulq_s32(a, b);
  #elif defined(SIMDE_WASM_SIMD128_NATIVE)
    return wasm_i32x4_mul(a, b);
  #else
    simde_int32x4_private
      r_,
      a_ = simde_int32x4_to_private(a),
      b_ = simde_int32x4_to_private(b);

    #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r_.values = a_.values * b_.values;
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
        r_.values[i] = a_.values[i] * b_.values[i];
      }
    #endif

    return simde_int32x4_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vmulq_s32
  #define vmulq_s32(a, b) simde_vmulq_s32((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_int64x2_t
simde_x_vmulq_s64(simde_int64x2_t a, simde_int64x2_t b) {
  #if defined(SIMDE_WASM_SIMD128_NATIVE)
    return wasm_i64x2_mul(a, b);
  #else
    simde_int64x2_private
      r_,
      a_ = simde_int64x2_to_private(a),
      b_ = simde_int64x2_to_private(b);

    #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r_.values = a_.values * b_.values;
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
        r_.values[i] = a_.values[i] * b_.values[i];
      }
    #endif

    return simde_int64x2_from_private(r_);
  #endif
}

SIMDE_FUNCTION_ATTRIBUTES
simde_uint8x16_t
simde_vmulq_u8(simde_uint8x16_t a, simde_uint8x16_t b) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vmulq_u8(a, b);
  #else
    simde_uint8x16_private
      r_,
      a_ = simde_uint8x16_to_private(a),
      b_ = simde_uint8x16_to_private(b);

    #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r_.values = a_.values * b_.values;
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
        r_.values[i] = a_.values[i] * b_.values[i];
      }
    #endif

    return simde_uint8x16_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vmulq_u8
  #define vmulq_u8(a, b) simde_vmulq_u8((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint16x8_t
simde_vmulq_u16(simde_uint16x8_t a, simde_uint16x8_t b) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vmulq_u16(a, b);
  #elif defined(SIMDE_WASM_SIMD128_NATIVE)
    return wasm_i16x8_mul(a, b);
  #else
    simde_uint16x8_private
      r_,
      a_ = simde_uint16x8_to_private(a),
      b_ = simde_uint16x8_to_private(b);

    #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r_.values = a_.values * b_.values;
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
        r_.values[i] = a_.values[i] * b_.values[i];
      }
    #endif

    return simde_uint16x8_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vmulq_u16
  #define vmulq_u16(a, b) simde_vmulq_u16((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint32x4_t
simde_vmulq_u32(simde_uint32x4_t a, simde_uint32x4_t b) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vmulq_u32(a, b);
  #elif defined(SIMDE_WASM_SIMD128_NATIVE)
    return wasm_i32x4_mul(a, b);
  #else
    simde_uint32x4_private
      r_,
      a_ = simde_uint32x4_to_private(a),
      b_ = simde_uint32x4_to_private(b);

    #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r_.values = a_.values * b_.values;
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
        r_.values[i] = a_.values[i] * b_.values[i];
      }
    #endif

    return simde_uint32x4_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vmulq_u32
  #define vmulq_u32(a, b) simde_vmulq_u32((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint64x2_t
simde_x_vmulq_u64(simde_uint64x2_t a, simde_uint64x2_t b) {
  #if defined(SIMDE_WASM_SIMD128_NATIVE)
    return wasm_i64x2_mul(a, b);
  #else
    simde_uint64x2_private
      r_,
      a_ = simde_uint64x2_to_private(a),
      b_ = simde_uint64x2_to_private(b);

    #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r_.values = a_.values * b_.values;
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
        r_.values[i] = a_.values[i] * b_.values[i];
      }
    #endif

    return simde_uint64x2_from_private(r_);
  #endif
}

SIMDE_END_DECLS_
HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_ARM_NEON_MUL_H) */
