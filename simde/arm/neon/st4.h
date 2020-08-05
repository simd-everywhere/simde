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

#if !defined(SIMDE_ARM_NEON_ST4_H)
#define SIMDE_ARM_NEON_ST4_H

#include "types.h"
#include "st1.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

SIMDE_FUNCTION_ATTRIBUTES
void
simde_vst4_f32(simde_float32_t *ptr, simde_float32x2x4_t val) {
  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
    vst4_f32(ptr, val);
  #else
    simde_vst1_f32(ptr + ((sizeof(val.val[0]) / sizeof(*ptr)) * 0), val.val[0]);
    simde_vst1_f32(ptr + ((sizeof(val.val[0]) / sizeof(*ptr)) * 1), val.val[1]);
    simde_vst1_f32(ptr + ((sizeof(val.val[0]) / sizeof(*ptr)) * 2), val.val[2]);
    simde_vst1_f32(ptr + ((sizeof(val.val[0]) / sizeof(*ptr)) * 3), val.val[3]);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vst4_f32
  #define vst4_f32(a, b) simde_vst4_f32((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
void
simde_vst4_f64(simde_float64_t *ptr, simde_float64x1x4_t val) {
  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
    vst4_f64(ptr, val);
  #else
    simde_vst1_f64(ptr + ((sizeof(val.val[0]) / sizeof(*ptr)) * 0), val.val[0]);
    simde_vst1_f64(ptr + ((sizeof(val.val[0]) / sizeof(*ptr)) * 1), val.val[1]);
    simde_vst1_f64(ptr + ((sizeof(val.val[0]) / sizeof(*ptr)) * 2), val.val[2]);
    simde_vst1_f64(ptr + ((sizeof(val.val[0]) / sizeof(*ptr)) * 3), val.val[3]);
  #endif
}
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES)
  #undef vst4_f64
  #define vst4_f64(a, b) simde_vst4_f64((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
void
simde_vst4_s8(int8_t *ptr, simde_int8x8x4_t val) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    vst4_s8(ptr, val);
  #else
    simde_vst1_s8(ptr + ((sizeof(val.val[0]) / sizeof(*ptr)) * 0), val.val[0]);
    simde_vst1_s8(ptr + ((sizeof(val.val[0]) / sizeof(*ptr)) * 1), val.val[1]);
    simde_vst1_s8(ptr + ((sizeof(val.val[0]) / sizeof(*ptr)) * 2), val.val[2]);
    simde_vst1_s8(ptr + ((sizeof(val.val[0]) / sizeof(*ptr)) * 3), val.val[3]);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vst4_s8
  #define vst4_s8(a, b) simde_vst4_s8((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
void
simde_vst4_s16(int16_t *ptr, simde_int16x4x4_t val) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    vst4_s16(ptr, val);
  #else
    simde_vst1_s16(ptr + ((sizeof(val.val[0]) / sizeof(*ptr)) * 0), val.val[0]);
    simde_vst1_s16(ptr + ((sizeof(val.val[0]) / sizeof(*ptr)) * 1), val.val[1]);
    simde_vst1_s16(ptr + ((sizeof(val.val[0]) / sizeof(*ptr)) * 2), val.val[2]);
    simde_vst1_s16(ptr + ((sizeof(val.val[0]) / sizeof(*ptr)) * 3), val.val[3]);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vst4_s16
  #define vst4_s16(a, b) simde_vst4_s16((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
void
simde_vst4_s32(int32_t *ptr, simde_int32x2x4_t val) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    vst4_s32(ptr, val);
  #else
    simde_vst1_s32(ptr + ((sizeof(val.val[0]) / sizeof(*ptr)) * 0), val.val[0]);
    simde_vst1_s32(ptr + ((sizeof(val.val[0]) / sizeof(*ptr)) * 1), val.val[1]);
    simde_vst1_s32(ptr + ((sizeof(val.val[0]) / sizeof(*ptr)) * 2), val.val[2]);
    simde_vst1_s32(ptr + ((sizeof(val.val[0]) / sizeof(*ptr)) * 3), val.val[3]);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vst4_s32
  #define vst4_s32(a, b) simde_vst4_s32((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
void
simde_vst4_s64(int64_t *ptr, simde_int64x1x4_t val) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    vst4_s64(ptr, val);
  #else
    simde_vst1_s64(ptr + ((sizeof(val.val[0]) / sizeof(*ptr)) * 0), val.val[0]);
    simde_vst1_s64(ptr + ((sizeof(val.val[0]) / sizeof(*ptr)) * 1), val.val[1]);
    simde_vst1_s64(ptr + ((sizeof(val.val[0]) / sizeof(*ptr)) * 2), val.val[2]);
    simde_vst1_s64(ptr + ((sizeof(val.val[0]) / sizeof(*ptr)) * 3), val.val[3]);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vst4_s64
  #define vst4_s64(a, b) simde_vst4_s64((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
void
simde_vst4_u8(uint8_t *ptr, simde_uint8x8x4_t val) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    vst4_u8(ptr, val);
  #else
    simde_vst1_u8(ptr + ((sizeof(val.val[0]) / sizeof(*ptr)) * 0), val.val[0]);
    simde_vst1_u8(ptr + ((sizeof(val.val[0]) / sizeof(*ptr)) * 1), val.val[1]);
    simde_vst1_u8(ptr + ((sizeof(val.val[0]) / sizeof(*ptr)) * 2), val.val[2]);
    simde_vst1_u8(ptr + ((sizeof(val.val[0]) / sizeof(*ptr)) * 3), val.val[3]);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vst4_u8
  #define vst4_u8(a, b) simde_vst4_u8((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
void
simde_vst4_u16(uint16_t *ptr, simde_uint16x4x4_t val) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    vst4_u16(ptr, val);
  #else
    simde_vst1_u16(ptr + ((sizeof(val.val[0]) / sizeof(*ptr)) * 0), val.val[0]);
    simde_vst1_u16(ptr + ((sizeof(val.val[0]) / sizeof(*ptr)) * 1), val.val[1]);
    simde_vst1_u16(ptr + ((sizeof(val.val[0]) / sizeof(*ptr)) * 2), val.val[2]);
    simde_vst1_u16(ptr + ((sizeof(val.val[0]) / sizeof(*ptr)) * 3), val.val[3]);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vst4_u16
  #define vst4_u16(a, b) simde_vst4_u16((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
void
simde_vst4_u32(uint32_t *ptr, simde_uint32x2x4_t val) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    vst4_u32(ptr, val);
  #else
    simde_vst1_u32(ptr + ((sizeof(val.val[0]) / sizeof(*ptr)) * 0), val.val[0]);
    simde_vst1_u32(ptr + ((sizeof(val.val[0]) / sizeof(*ptr)) * 1), val.val[1]);
    simde_vst1_u32(ptr + ((sizeof(val.val[0]) / sizeof(*ptr)) * 2), val.val[2]);
    simde_vst1_u32(ptr + ((sizeof(val.val[0]) / sizeof(*ptr)) * 3), val.val[3]);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vst4_u32
  #define vst4_u32(a, b) simde_vst4_u32((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
void
simde_vst4_u64(uint64_t *ptr, simde_uint64x1x4_t val) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    vst4_u64(ptr, val);
  #else
    simde_vst1_u64(ptr + ((sizeof(val.val[0]) / sizeof(*ptr)) * 0), val.val[0]);
    simde_vst1_u64(ptr + ((sizeof(val.val[0]) / sizeof(*ptr)) * 1), val.val[1]);
    simde_vst1_u64(ptr + ((sizeof(val.val[0]) / sizeof(*ptr)) * 2), val.val[2]);
    simde_vst1_u64(ptr + ((sizeof(val.val[0]) / sizeof(*ptr)) * 3), val.val[3]);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vst4_u64
  #define vst4_u64(a, b) simde_vst4_u64((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
void
simde_vst4q_f32(simde_float32_t *ptr, simde_float32x4x4_t val) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    vst4q_f32(ptr, val);
  #else
    simde_vst1q_f32(ptr + ((sizeof(val.val[0]) / sizeof(*ptr)) * 0), val.val[0]);
    simde_vst1q_f32(ptr + ((sizeof(val.val[0]) / sizeof(*ptr)) * 1), val.val[1]);
    simde_vst1q_f32(ptr + ((sizeof(val.val[0]) / sizeof(*ptr)) * 2), val.val[2]);
    simde_vst1q_f32(ptr + ((sizeof(val.val[0]) / sizeof(*ptr)) * 3), val.val[3]);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vst4q_f32
  #define vst4q_f32(a, b) simde_vst4q_f32((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
void
simde_vst4q_f64(simde_float64_t *ptr, simde_float64x2x4_t val) {
  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
    vst4q_f64(ptr, val);
  #else
    simde_vst1q_f64(ptr + ((sizeof(val.val[0]) / sizeof(*ptr)) * 0), val.val[0]);
    simde_vst1q_f64(ptr + ((sizeof(val.val[0]) / sizeof(*ptr)) * 1), val.val[1]);
    simde_vst1q_f64(ptr + ((sizeof(val.val[0]) / sizeof(*ptr)) * 2), val.val[2]);
    simde_vst1q_f64(ptr + ((sizeof(val.val[0]) / sizeof(*ptr)) * 3), val.val[3]);
  #endif
}
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES)
  #undef vst4q_f64
  #define vst4q_f64(a, b) simde_vst4q_f64((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
void
simde_vst4q_s8(int8_t *ptr, simde_int8x16x4_t val) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    vst4q_s8(ptr, val);
  #else
    simde_vst1q_s8(ptr + ((sizeof(val.val[0]) / sizeof(*ptr)) * 0), val.val[0]);
    simde_vst1q_s8(ptr + ((sizeof(val.val[0]) / sizeof(*ptr)) * 1), val.val[1]);
    simde_vst1q_s8(ptr + ((sizeof(val.val[0]) / sizeof(*ptr)) * 2), val.val[2]);
    simde_vst1q_s8(ptr + ((sizeof(val.val[0]) / sizeof(*ptr)) * 3), val.val[3]);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vst4q_s8
  #define vst4q_s8(a, b) simde_vst4q_s8((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
void
simde_vst4q_s16(int16_t *ptr, simde_int16x8x4_t val) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    vst4q_s16(ptr, val);
  #else
    simde_vst1q_s16(ptr + ((sizeof(val.val[0]) / sizeof(*ptr)) * 0), val.val[0]);
    simde_vst1q_s16(ptr + ((sizeof(val.val[0]) / sizeof(*ptr)) * 1), val.val[1]);
    simde_vst1q_s16(ptr + ((sizeof(val.val[0]) / sizeof(*ptr)) * 2), val.val[2]);
    simde_vst1q_s16(ptr + ((sizeof(val.val[0]) / sizeof(*ptr)) * 3), val.val[3]);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vst4q_s16
  #define vst4q_s16(a, b) simde_vst4q_s16((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
void
simde_vst4q_s32(int32_t *ptr, simde_int32x4x4_t val) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    vst4q_s32(ptr, val);
  #else
    simde_vst1q_s32(ptr + ((sizeof(val.val[0]) / sizeof(*ptr)) * 0), val.val[0]);
    simde_vst1q_s32(ptr + ((sizeof(val.val[0]) / sizeof(*ptr)) * 1), val.val[1]);
    simde_vst1q_s32(ptr + ((sizeof(val.val[0]) / sizeof(*ptr)) * 2), val.val[2]);
    simde_vst1q_s32(ptr + ((sizeof(val.val[0]) / sizeof(*ptr)) * 3), val.val[3]);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vst4q_s32
  #define vst4q_s32(a, b) simde_vst4q_s32((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
void
simde_vst4q_s64(int64_t *ptr, simde_int64x2x4_t val) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    vst4q_s64(ptr, val);
  #else
    simde_vst1q_s64(ptr + ((sizeof(val.val[0]) / sizeof(*ptr)) * 0), val.val[0]);
    simde_vst1q_s64(ptr + ((sizeof(val.val[0]) / sizeof(*ptr)) * 1), val.val[1]);
    simde_vst1q_s64(ptr + ((sizeof(val.val[0]) / sizeof(*ptr)) * 2), val.val[2]);
    simde_vst1q_s64(ptr + ((sizeof(val.val[0]) / sizeof(*ptr)) * 3), val.val[3]);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vst4q_s64
  #define vst4q_s64(a, b) simde_vst4q_s64((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
void
simde_vst4q_u8(uint8_t *ptr, simde_uint8x16x4_t val) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    vst4q_u8(ptr, val);
  #else
    simde_vst1q_u8(ptr + ((sizeof(val.val[0]) / sizeof(*ptr)) * 0), val.val[0]);
    simde_vst1q_u8(ptr + ((sizeof(val.val[0]) / sizeof(*ptr)) * 1), val.val[1]);
    simde_vst1q_u8(ptr + ((sizeof(val.val[0]) / sizeof(*ptr)) * 2), val.val[2]);
    simde_vst1q_u8(ptr + ((sizeof(val.val[0]) / sizeof(*ptr)) * 3), val.val[3]);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vst4q_u8
  #define vst4q_u8(a, b) simde_vst4q_u8((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
void
simde_vst4q_u16(uint16_t *ptr, simde_uint16x8x4_t val) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    vst4q_u16(ptr, val);
  #else
    simde_vst1q_u16(ptr + ((sizeof(val.val[0]) / sizeof(*ptr)) * 0), val.val[0]);
    simde_vst1q_u16(ptr + ((sizeof(val.val[0]) / sizeof(*ptr)) * 1), val.val[1]);
    simde_vst1q_u16(ptr + ((sizeof(val.val[0]) / sizeof(*ptr)) * 2), val.val[2]);
    simde_vst1q_u16(ptr + ((sizeof(val.val[0]) / sizeof(*ptr)) * 3), val.val[3]);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vst4q_u16
  #define vst4q_u16(a, b) simde_vst4q_u16((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
void
simde_vst4q_u32(uint32_t *ptr, simde_uint32x4x4_t val) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    vst4q_u32(ptr, val);
  #else
    simde_vst1q_u32(ptr + ((sizeof(val.val[0]) / sizeof(*ptr)) * 0), val.val[0]);
    simde_vst1q_u32(ptr + ((sizeof(val.val[0]) / sizeof(*ptr)) * 1), val.val[1]);
    simde_vst1q_u32(ptr + ((sizeof(val.val[0]) / sizeof(*ptr)) * 2), val.val[2]);
    simde_vst1q_u32(ptr + ((sizeof(val.val[0]) / sizeof(*ptr)) * 3), val.val[3]);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vst4q_u32
  #define vst4q_u32(a, b) simde_vst4q_u32((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
void
simde_vst4q_u64(uint64_t *ptr, simde_uint64x2x4_t val) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    vst4q_u64(ptr, val);
  #else
    simde_vst1q_u64(ptr + ((sizeof(val.val[0]) / sizeof(*ptr)) * 0), val.val[0]);
    simde_vst1q_u64(ptr + ((sizeof(val.val[0]) / sizeof(*ptr)) * 1), val.val[1]);
    simde_vst1q_u64(ptr + ((sizeof(val.val[0]) / sizeof(*ptr)) * 2), val.val[2]);
    simde_vst1q_u64(ptr + ((sizeof(val.val[0]) / sizeof(*ptr)) * 3), val.val[3]);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vst4q_u64
  #define vst4q_u64(a, b) simde_vst4q_u64((a), (b))
#endif

SIMDE_END_DECLS_
HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_ARM_NEON_ST4_H) */
