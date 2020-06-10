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
 *   2020      Sean Maher <seanptmaher@gmail.com>
 */

#if !defined(SIMDE_ARM_NEON_GET_LANE_H)
#define SIMDE_ARM_NEON_GET_LANE_H

#include "types.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

SIMDE_FUNCTION_ATTRIBUTES
simde_float32
simde_vget_lane_f32(simde_float32x2_t a, const int b) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vget_lane_f32(a, b);
  #else
    simde_float32x2_private a_ = simde_float32x2_to_private(a);

    return a_.values[b];
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vget_lane_f32
  #define vget_lane_f32(a, b) simde_vget_lane_f32((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_float64
simde_vget_lane_f64(simde_float64x1_t a, const int b) {
  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
    return vget_lane_f64(a, b);
  #else
    simde_float64x1_private a_ = simde_float64x1_to_private(a);

    return a_.values[b];
  #endif
}
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES)
  #undef vget_lane_f64
  #define vget_lane_f64(a, b) simde_vget_lane_f64((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
int8_t
simde_vget_lane_s8(simde_int8x8_t a, const int b) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vget_lane_s8(a, b);
  #else
    simde_int8x8_private a_ = simde_int8x8_to_private(a);

    return a_.values[b];
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vget_lane_s8
  #define vget_lane_s8(a, b) simde_vget_lane_s8((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
int16_t
simde_vget_lane_s16(simde_int16x4_t a, const int b) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vget_lane_s16(a, b);
  #else
    simde_int16x4_private a_ = simde_int16x4_to_private(a);

    return a_.values[b];
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vget_lane_s16
  #define vget_lane_s16(a, b) simde_vget_lane_s16((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
int32_t
simde_vget_lane_s32(simde_int32x2_t a, const int b) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vget_lane_s32(a, b);
  #else
    simde_int32x2_private a_ = simde_int32x2_to_private(a);

    return a_.values[b];
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vget_lane_s32
  #define vget_lane_s32(a, b) simde_vget_lane_s32((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
int64_t
simde_vget_lane_s64(simde_int64x1_t a, const int b) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vget_lane_s64(a, b);
  #else
    simde_int64x1_private a_ = simde_int64x1_to_private(a);

    return a_.values[b];
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vget_lane_s64
  #define vget_lane_s64(a, b) simde_vget_lane_s64((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
uint8_t
simde_vget_lane_u8(simde_uint8x8_t a, const int b) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vget_lane_u8(a, b);
  #else
    simde_uint8x8_private a_ = simde_uint8x8_to_private(a);

    return a_.values[b];
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vget_lane_u8
  #define vget_lane_u8(a, b) simde_vget_lane_u8((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
uint16_t
simde_vget_lane_u16(simde_uint16x4_t a, const int b) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vget_lane_u16(a, b);
  #else
    simde_uint16x4_private a_ = simde_uint16x4_to_private(a);

    return a_.values[b];
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vget_lane_u16
  #define vget_lane_u16(a, b) simde_vget_lane_u16((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
uint32_t
simde_vget_lane_u32(simde_uint32x2_t a, const int b) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vget_lane_u32(a, b);
  #else
    simde_uint32x2_private a_ = simde_uint32x2_to_private(a);

    return a_.values[b];
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vget_lane_u32
  #define vget_lane_u32(a, b) simde_vget_lane_u32((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
uint64_t
simde_vget_lane_u64(simde_uint64x1_t a, const int b) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vget_lane_u64(a, b);
  #else
    simde_uint64x1_private a_ = simde_uint64x1_to_private(a);

    return a_.values[b];
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vget_lane_u64
  #define vget_lane_u64(a, b) simde_vget_lane_u64((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_float32
simde_vgetq_lane_f32(simde_float32x4_t a, const int b) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vgetq_lane_f32(a, b);
  #elif defined(SIMDE_WASM_SIMD128_NATIVE)
    return wasm_f32x4_extract_lane(a, b);
  #else
    simde_float32x4_private a_ = simde_float32x4_to_private(a);

    return a_.values[b];
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vgetq_lane_f32
  #define vgetq_lane_f32(a, b) simde_vgetq_lane_f32((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_float64
simde_vgetq_lane_f64(simde_float64x2_t a, const int b) {
  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
    return vgetq_lane_f64(a, b);
  #elif defined(SIMDE_WASM_SIMD128_NATIVE)
    return wasm_f64x2_extract_lane(a, b);
  #else
    simde_float64x2_private a_ = simde_float64x2_to_private(a);

    return a_.values[b];
  #endif
}
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES)
  #undef vgetq_lane_f64
  #define vgetq_lane_f64(a, b) simde_vgetq_lane_f64((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
int8_t
simde_vgetq_lane_s8(simde_int8x16_t a, const int b) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vgetq_lane_s8(a, b);
  #elif defined(SIMDE_WASM_SIMD128_NATIVE)
    return wasm_i8x16_extract_lane(a, b);
  #else
    simde_int8x16_private a_ = simde_int8x16_to_private(a);

    return a_.values[b];
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vgetq_lane_s8
  #define vgetq_lane_s8(a, b) simde_vgetq_lane_s8((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
int16_t
simde_vgetq_lane_s16(simde_int16x8_t a, const int b) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vgetq_lane_s16(a, b);
  #elif defined(SIMDE_WASM_SIMD128_NATIVE)
    return wasm_i16x8_extract_lane(a, b);
  #else
    simde_int16x8_private a_ = simde_int16x8_to_private(a);

    return a_.values[b];
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vgetq_lane_s16
  #define vgetq_lane_s16(a, b) simde_vgetq_lane_s16((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
int32_t
simde_vgetq_lane_s32(simde_int32x4_t a, const int b) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vgetq_lane_s32(a, b);
  #elif defined(SIMDE_WASM_SIMD128_NATIVE)
    return wasm_i32x4_extract_lane(a, b);
  #else
    simde_int32x4_private a_ = simde_int32x4_to_private(a);

    return a_.values[b];
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vgetq_lane_s32
  #define vgetq_lane_s32(a, b) simde_vgetq_lane_s32((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
int64_t
simde_vgetq_lane_s64(simde_int64x2_t a, const int b) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vgetq_lane_s64(a, b);
  #elif defined(SIMDE_WASM_SIMD128_NATIVE)
    return wasm_i64x2_extract_lane(a, b);
  #else
    simde_int64x2_private a_ = simde_int64x2_to_private(a);

    return a_.values[b];
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vgetq_lane_s64
  #define vgetq_lane_s64(a, b) simde_vgetq_lane_s64((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
uint8_t
simde_vgetq_lane_u8(simde_uint8x16_t a, const int b) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vgetq_lane_u8(a, b);
  #elif defined(SIMDE_WASM_SIMD128_NATIVE)
    return wasm_i8x16_extract_lane(a, b);
  #else
    simde_uint8x16_private a_ = simde_uint8x16_to_private(a);

    return a_.values[b];
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vgetq_lane_u8
  #define vgetq_lane_u8(a, b) simde_vgetq_lane_u8((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
uint16_t
simde_vgetq_lane_u16(simde_uint16x8_t a, const int b) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vgetq_lane_u16(a, b);
  #elif defined(SIMDE_WASM_SIMD128_NATIVE)
    return wasm_i16x8_extract_lane(a, b);
  #else
    simde_uint16x8_private a_ = simde_uint16x8_to_private(a);

    return a_.values[b];
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vgetq_lane_u16
  #define vgetq_lane_u16(a, b) simde_vgetq_lane_u16((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
uint32_t
simde_vgetq_lane_u32(simde_uint32x4_t a, const int b) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vgetq_lane_u32(a, b);
  #elif defined(SIMDE_WASM_SIMD128_NATIVE)
    return wasm_i32x4_extract_lane(a, b);
  #else
    simde_uint32x4_private a_ = simde_uint32x4_to_private(a);

    return a_.values[b];
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vgetq_lane_u32
  #define vgetq_lane_u32(a, b) simde_vgetq_lane_u32((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
uint64_t
simde_vgetq_lane_u64(simde_uint64x2_t a, const int b) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vgetq_lane_u64(a, b);
  #elif defined(SIMDE_WASM_SIMD128_NATIVE)
    return wasm_i64x2_extract_lane(a, b);
  #else
    simde_uint64x2_private a_ = simde_uint64x2_to_private(a);

    return a_.values[b];
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vgetq_lane_u64
  #define vgetq_lane_u64(a, b) simde_vgetq_lane_u64((a), (b))
#endif

SIMDE_END_DECLS_
HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_ARM_NEON_GET_LANE_H) */
