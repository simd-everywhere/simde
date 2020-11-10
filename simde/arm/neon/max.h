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

#if !defined(SIMDE_ARM_NEON_MAX_H)
#define SIMDE_ARM_NEON_MAX_H

#include "types.h"
#include "cgt.h"
#include "bsl.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

SIMDE_FUNCTION_ATTRIBUTES
simde_float32x2_t
simde_vmax_f32(simde_float32x2_t a, simde_float32x2_t b) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vmax_f32(a, b);
  #else
    simde_float32x2_private
      r_,
      a_ = simde_float32x2_to_private(a),
      b_ = simde_float32x2_to_private(b);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
      #if !defined(SIMDE_FAST_NANS)
        r_.values[i] = (a_.values[i] >= b_.values[i]) ? a_.values[i] : ((a_.values[i] < b_.values[i]) ? b_.values[i] : SIMDE_MATH_NANF);
      #else
        r_.values[i] = (a_.values[i] > b_.values[i]) ? a_.values[i] : b_.values[i];
      #endif
    }

    return simde_float32x2_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vmax_f32
  #define vmax_f32(a, b) simde_vmax_f32((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_float64x1_t
simde_vmax_f64(simde_float64x1_t a, simde_float64x1_t b) {
  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
    return vmax_f64(a, b);
  #else
    simde_float64x1_private
      r_,
      a_ = simde_float64x1_to_private(a),
      b_ = simde_float64x1_to_private(b);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
      #if !defined(SIMDE_FAST_NANS)
        r_.values[i] = (a_.values[i] >= b_.values[i]) ? a_.values[i] : ((a_.values[i] < b_.values[i]) ? b_.values[i] : SIMDE_MATH_NAN);
      #else
        r_.values[i] = (a_.values[i] > b_.values[i]) ? a_.values[i] : b_.values[i];
      #endif
    }

    return simde_float64x1_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES)
  #undef vmax_f64
  #define vmax_f64(a, b) simde_vmax_f64((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_int8x8_t
simde_vmax_s8(simde_int8x8_t a, simde_int8x8_t b) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vmax_s8(a, b);
  #elif SIMDE_NATURAL_VECTOR_SIZE > 0
    return simde_vbsl_s8(simde_vcgt_s8(a, b), a, b);
  #else
    simde_int8x8_private
      r_,
      a_ = simde_int8x8_to_private(a),
      b_ = simde_int8x8_to_private(b);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
      r_.values[i] = (a_.values[i] > b_.values[i]) ? a_.values[i] : b_.values[i];
    }

    return simde_int8x8_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vmax_s8
  #define vmax_s8(a, b) simde_vmax_s8((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_int16x4_t
simde_vmax_s16(simde_int16x4_t a, simde_int16x4_t b) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vmax_s16(a, b);
  #elif SIMDE_NATURAL_VECTOR_SIZE > 0
    return simde_vbsl_s16(simde_vcgt_s16(a, b), a, b);
  #else
    simde_int16x4_private
      r_,
      a_ = simde_int16x4_to_private(a),
      b_ = simde_int16x4_to_private(b);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
      r_.values[i] = (a_.values[i] > b_.values[i]) ? a_.values[i] : b_.values[i];
    }

    return simde_int16x4_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vmax_s16
  #define vmax_s16(a, b) simde_vmax_s16((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_int32x2_t
simde_vmax_s32(simde_int32x2_t a, simde_int32x2_t b) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vmax_s32(a, b);
  #elif SIMDE_NATURAL_VECTOR_SIZE > 0
    return simde_vbsl_s32(simde_vcgt_s32(a, b), a, b);
  #else
    simde_int32x2_private
      r_,
      a_ = simde_int32x2_to_private(a),
      b_ = simde_int32x2_to_private(b);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
      r_.values[i] = (a_.values[i] > b_.values[i]) ? a_.values[i] : b_.values[i];
    }

    return simde_int32x2_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vmax_s32
  #define vmax_s32(a, b) simde_vmax_s32((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_int64x1_t
simde_x_vmax_s64(simde_int64x1_t a, simde_int64x1_t b) {
  #if SIMDE_NATURAL_VECTOR_SIZE > 0
    return simde_vbsl_s64(simde_vcgt_s64(a, b), a, b);
  #else
    simde_int64x1_private
      r_,
      a_ = simde_int64x1_to_private(a),
      b_ = simde_int64x1_to_private(b);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
      r_.values[i] = (a_.values[i] > b_.values[i]) ? a_.values[i] : b_.values[i];
    }

    return simde_int64x1_from_private(r_);
  #endif
}

SIMDE_FUNCTION_ATTRIBUTES
simde_uint8x8_t
simde_vmax_u8(simde_uint8x8_t a, simde_uint8x8_t b) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vmax_u8(a, b);
  #elif SIMDE_NATURAL_VECTOR_SIZE > 0
    return simde_vbsl_u8(simde_vcgt_u8(a, b), a, b);
  #else
    simde_uint8x8_private
      r_,
      a_ = simde_uint8x8_to_private(a),
      b_ = simde_uint8x8_to_private(b);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
      r_.values[i] = (a_.values[i] > b_.values[i]) ? a_.values[i] : b_.values[i];
    }

    return simde_uint8x8_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vmax_u8
  #define vmax_u8(a, b) simde_vmax_u8((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint16x4_t
simde_vmax_u16(simde_uint16x4_t a, simde_uint16x4_t b) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vmax_u16(a, b);
  #elif SIMDE_NATURAL_VECTOR_SIZE > 0
    return simde_vbsl_u16(simde_vcgt_u16(a, b), a, b);
  #else
    simde_uint16x4_private
      r_,
      a_ = simde_uint16x4_to_private(a),
      b_ = simde_uint16x4_to_private(b);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
      r_.values[i] = (a_.values[i] > b_.values[i]) ? a_.values[i] : b_.values[i];
    }

    return simde_uint16x4_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vmax_u16
  #define vmax_u16(a, b) simde_vmax_u16((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint32x2_t
simde_vmax_u32(simde_uint32x2_t a, simde_uint32x2_t b) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vmax_u32(a, b);
  #elif SIMDE_NATURAL_VECTOR_SIZE > 0
    return simde_vbsl_u32(simde_vcgt_u32(a, b), a, b);
  #else
    simde_uint32x2_private
      r_,
      a_ = simde_uint32x2_to_private(a),
      b_ = simde_uint32x2_to_private(b);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
      r_.values[i] = (a_.values[i] > b_.values[i]) ? a_.values[i] : b_.values[i];
    }

    return simde_uint32x2_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vmax_u32
  #define vmax_u32(a, b) simde_vmax_u32((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint64x1_t
simde_x_vmax_u64(simde_uint64x1_t a, simde_uint64x1_t b) {
  #if SIMDE_NATURAL_VECTOR_SIZE > 0
    return simde_vbsl_u64(simde_vcgt_u64(a, b), a, b);
  #else
    simde_uint64x1_private
      r_,
      a_ = simde_uint64x1_to_private(a),
      b_ = simde_uint64x1_to_private(b);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
      r_.values[i] = (a_.values[i] > b_.values[i]) ? a_.values[i] : b_.values[i];
    }

    return simde_uint64x1_from_private(r_);
  #endif
}

SIMDE_FUNCTION_ATTRIBUTES
simde_float32x4_t
simde_vmaxq_f32(simde_float32x4_t a, simde_float32x4_t b) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vmaxq_f32(a, b);
  #elif defined(SIMDE_X86_SSE_NATIVE)
    #if !defined(SIMDE_FAST_NANS)
      __m128 nan_mask = _mm_cmpunord_ps(a, b);
      __m128 res = _mm_max_ps(a, b);
      res = _mm_andnot_ps(nan_mask, res);
      res = _mm_or_ps(res, _mm_and_ps(_mm_set1_ps(SIMDE_MATH_NANF), nan_mask));
      return res;
    #else
      return _mm_max_ps(a, b);
    #endif
  #elif defined(SIMDE_POWER_ALTIVEC_P6_NATIVE) && defined(SIMDE_FAST_NANS)
    return vec_max(a, b);
  #elif defined(SIMDE_WASM_SIMD128_NATIVE)
    return wasm_f32x4_max(a, b);
  #else
    simde_float32x4_private
      r_,
      a_ = simde_float32x4_to_private(a),
      b_ = simde_float32x4_to_private(b);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
      #if !defined(SIMDE_FAST_NANS)
        r_.values[i] = (a_.values[i] >= b_.values[i]) ? a_.values[i] : ((a_.values[i] < b_.values[i]) ? b_.values[i] : SIMDE_MATH_NANF);
      #else
        r_.values[i] = (a_.values[i] > b_.values[i]) ? a_.values[i] : b_.values[i];
      #endif
    }

    return simde_float32x4_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vmaxq_f32
  #define vmaxq_f32(a, b) simde_vmaxq_f32((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_float64x2_t
simde_vmaxq_f64(simde_float64x2_t a, simde_float64x2_t b) {
  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
    return vmaxq_f64(a, b);
  #elif defined(SIMDE_X86_SSE2_NATIVE)
    #if !defined(SIMDE_FAST_NANS)
      __m128d nan_mask = _mm_cmpunord_pd(a, b);
      __m128d res = _mm_max_pd(a, b);
      res = _mm_andnot_pd(nan_mask, res);
      res = _mm_or_pd(res, _mm_and_pd(_mm_set1_pd(SIMDE_MATH_NAN), nan_mask));
      return res;
    #else
      return _mm_max_pd(a, b);
    #endif
  #elif defined(SIMDE_POWER_ALTIVEC_P7_NATIVE) && defined(SIMDE_FAST_NANS)
    return vec_max(a, b);
  #elif defined(SIMDE_WASM_SIMD128_NATIVE)
    return wasm_f64x2_max(a, b);
  #else
    simde_float64x2_private
      r_,
      a_ = simde_float64x2_to_private(a),
      b_ = simde_float64x2_to_private(b);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
      #if !defined(SIMDE_FAST_NANS)
        r_.values[i] = (a_.values[i] >= b_.values[i]) ? a_.values[i] : ((a_.values[i] < b_.values[i]) ? b_.values[i] : SIMDE_MATH_NAN);
      #else
        r_.values[i] = (a_.values[i] > b_.values[i]) ? a_.values[i] : b_.values[i];
      #endif
    }

    return simde_float64x2_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES)
  #undef vmaxq_f64
  #define vmaxq_f64(a, b) simde_vmaxq_f64((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_int8x16_t
simde_vmaxq_s8(simde_int8x16_t a, simde_int8x16_t b) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vmaxq_s8(a, b);
  #elif defined(SIMDE_X86_SSE4_1_NATIVE)
    return _mm_max_epi8(a, b);
  #elif defined(SIMDE_POWER_ALTIVEC_P6_NATIVE)
    return vec_max(a, b);
  #elif defined(SIMDE_WASM_SIMD128_NATIVE)
    return wasm_i8x16_max(a, b);
  #elif SIMDE_NATURAL_VECTOR_SIZE > 0
    return simde_vbslq_s8(simde_vcgtq_s8(a, b), a, b);
  #else
    simde_int8x16_private
      r_,
      a_ = simde_int8x16_to_private(a),
      b_ = simde_int8x16_to_private(b);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
      r_.values[i] = (a_.values[i] > b_.values[i]) ? a_.values[i] : b_.values[i];
    }

    return simde_int8x16_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vmaxq_s8
  #define vmaxq_s8(a, b) simde_vmaxq_s8((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_int16x8_t
simde_vmaxq_s16(simde_int16x8_t a, simde_int16x8_t b) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vmaxq_s16(a, b);
  #elif defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_max_epi16(a, b);
  #elif defined(SIMDE_POWER_ALTIVEC_P6_NATIVE)
    return vec_max(a, b);
  #elif defined(SIMDE_WASM_SIMD128_NATIVE)
    return wasm_i16x8_max(a, b);
  #elif SIMDE_NATURAL_VECTOR_SIZE > 0
    return simde_vbslq_s16(simde_vcgtq_s16(a, b), a, b);
  #else
    simde_int16x8_private
      r_,
      a_ = simde_int16x8_to_private(a),
      b_ = simde_int16x8_to_private(b);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
      r_.values[i] = (a_.values[i] > b_.values[i]) ? a_.values[i] : b_.values[i];
    }

    return simde_int16x8_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vmaxq_s16
  #define vmaxq_s16(a, b) simde_vmaxq_s16((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_int32x4_t
simde_vmaxq_s32(simde_int32x4_t a, simde_int32x4_t b) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vmaxq_s32(a, b);
  #elif defined(SIMDE_X86_SSE4_1_NATIVE)
    return _mm_max_epi32(a, b);
  #elif defined(SIMDE_POWER_ALTIVEC_P6_NATIVE)
    return vec_max(a, b);
  #elif defined(SIMDE_WASM_SIMD128_NATIVE)
    return wasm_i32x4_max(a, b);
  #elif SIMDE_NATURAL_VECTOR_SIZE > 0
    return simde_vbslq_s32(simde_vcgtq_s32(a, b), a, b);
  #else
    simde_int32x4_private
      r_,
      a_ = simde_int32x4_to_private(a),
      b_ = simde_int32x4_to_private(b);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
      r_.values[i] = (a_.values[i] > b_.values[i]) ? a_.values[i] : b_.values[i];
    }

    return simde_int32x4_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vmaxq_s32
  #define vmaxq_s32(a, b) simde_vmaxq_s32((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_int64x2_t
simde_x_vmaxq_s64(simde_int64x2_t a, simde_int64x2_t b) {
  #if defined(SIMDE_POWER_ALTIVEC_P8_NATIVE)
    return vec_max(a, b);
  #elif SIMDE_NATURAL_VECTOR_SIZE > 0
    return simde_vbslq_s64(simde_vcgtq_s64(a, b), a, b);
  #else
    simde_int64x2_private
      r_,
      a_ = simde_int64x2_to_private(a),
      b_ = simde_int64x2_to_private(b);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
      r_.values[i] = (a_.values[i] > b_.values[i]) ? a_.values[i] : b_.values[i];
    }

    return simde_int64x2_from_private(r_);
  #endif
}

SIMDE_FUNCTION_ATTRIBUTES
simde_uint8x16_t
simde_vmaxq_u8(simde_uint8x16_t a, simde_uint8x16_t b) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vmaxq_u8(a, b);
  #elif defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_max_epu8(a, b);
  #elif defined(SIMDE_POWER_ALTIVEC_P6_NATIVE)
    return vec_max(a, b);
  #elif defined(SIMDE_WASM_SIMD128_NATIVE)
    return wasm_u8x16_max(a, b);
  #elif SIMDE_NATURAL_VECTOR_SIZE > 0
    return simde_vbslq_u8(simde_vcgtq_u8(a, b), a, b);
  #else
    simde_uint8x16_private
      r_,
      a_ = simde_uint8x16_to_private(a),
      b_ = simde_uint8x16_to_private(b);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
      r_.values[i] = (a_.values[i] > b_.values[i]) ? a_.values[i] : b_.values[i];
    }

    return simde_uint8x16_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vmaxq_u8
  #define vmaxq_u8(a, b) simde_vmaxq_u8((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint16x8_t
simde_vmaxq_u16(simde_uint16x8_t a, simde_uint16x8_t b) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vmaxq_u16(a, b);
  #elif defined(SIMDE_X86_SSE4_1_NATIVE)
    return _mm_max_epu16(a, b);
  #elif defined(SIMDE_POWER_ALTIVEC_P6_NATIVE)
    return vec_max(a, b);
  #elif defined(SIMDE_WASM_SIMD128_NATIVE)
    return wasm_u16x8_max(a, b);
  #elif SIMDE_NATURAL_VECTOR_SIZE > 0
    return simde_vbslq_u16(simde_vcgtq_u16(a, b), a, b);
  #else
    simde_uint16x8_private
      r_,
      a_ = simde_uint16x8_to_private(a),
      b_ = simde_uint16x8_to_private(b);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
      r_.values[i] = (a_.values[i] > b_.values[i]) ? a_.values[i] : b_.values[i];
    }

    return simde_uint16x8_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vmaxq_u16
  #define vmaxq_u16(a, b) simde_vmaxq_u16((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint32x4_t
simde_vmaxq_u32(simde_uint32x4_t a, simde_uint32x4_t b) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vmaxq_u32(a, b);
  #elif defined(SIMDE_X86_SSE4_1_NATIVE)
    return _mm_max_epu32(a, b);
  #elif defined(SIMDE_POWER_ALTIVEC_P6_NATIVE)
    return vec_max(a, b);
  #elif defined(SIMDE_WASM_SIMD128_NATIVE)
    return wasm_u32x4_max(a, b);
  #elif SIMDE_NATURAL_VECTOR_SIZE > 0
    return simde_vbslq_u32(simde_vcgtq_u32(a, b), a, b);
  #else
    simde_uint32x4_private
      r_,
      a_ = simde_uint32x4_to_private(a),
      b_ = simde_uint32x4_to_private(b);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
      r_.values[i] = (a_.values[i] > b_.values[i]) ? a_.values[i] : b_.values[i];
    }

    return simde_uint32x4_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vmaxq_u32
  #define vmaxq_u32(a, b) simde_vmaxq_u32((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint64x2_t
simde_x_vmaxq_u64(simde_uint64x2_t a, simde_uint64x2_t b) {
  #if defined(SIMDE_POWER_ALTIVEC_P8_NATIVE)
    return vec_max(a, b);
  #elif SIMDE_NATURAL_VECTOR_SIZE > 0
    return simde_vbslq_u64(simde_vcgtq_u64(a, b), a, b);
  #else
    simde_uint64x2_private
      r_,
      a_ = simde_uint64x2_to_private(a),
      b_ = simde_uint64x2_to_private(b);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
      r_.values[i] = (a_.values[i] > b_.values[i]) ? a_.values[i] : b_.values[i];
    }

    return simde_uint64x2_from_private(r_);
  #endif
}

SIMDE_END_DECLS_
HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_ARM_NEON_MAX_H) */
