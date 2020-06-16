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
 *   2020      Sean Maher <seanptmaher@gmail.com>
 */

#if !defined(SIMDE_ARM_NEON_BSL_H)
#define SIMDE_ARM_NEON_BSL_H

#include "types.h"
#include "and.h"
#include "eor.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

SIMDE_FUNCTION_ATTRIBUTES
simde_float32x2_t
simde_vbsl_f32(simde_float32x2_t a, simde_float32x2_t b, simde_float32x2_t c) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vbsl_f32(a, b, c);
  #else
    simde_uint8x8_t a_, b_, c_, r_;
    simde_float32x2_t r;
    simde_memcpy(&a_, &a, sizeof(a_));
    simde_memcpy(&b_, &b, sizeof(b_));
    simde_memcpy(&c_, &c, sizeof(c_));
    r_ = simde_veor_u8(c_, simde_vand_u8(simde_veor_u8(c_, b_), a_));
    simde_memcpy(&r, &r_, sizeof(r));
    return r;
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vbsl_f32
  #define vbsl_f32(a, b, c) simde_vbsl_f32((a), (b), (c))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_float64x1_t
simde_vbsl_f64(simde_float64x1_t a, simde_float64x1_t b, simde_float64x1_t c) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vbsl_f64(a, b, c);
  #else
    simde_uint8x8_t a_, b_, c_, r_;
    simde_float64x1_t r;
    simde_memcpy(&a_, &a, sizeof(a_));
    simde_memcpy(&b_, &b, sizeof(b_));
    simde_memcpy(&c_, &c, sizeof(c_));
    r_ = simde_veor_u8(c_, simde_vand_u8(simde_veor_u8(c_, b_), a_));
    simde_memcpy(&r, &r_, sizeof(r));
    return r;
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vbsl_f64
  #define vbsl_f64(a, b, c) simde_vbsl_f64((a), (b), (c))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_int8x8_t
simde_vbsl_s8(simde_int8x8_t a, simde_int8x8_t b, simde_int8x8_t c) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vbsl_s8(a, b, c);
  #else
    return simde_veor_s8(c, simde_vand_s8(simde_veor_s8(c, b), a));
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vbsl_s8
  #define vbsl_s8(a, b, c) simde_vbsl_s8((a), (b), (c))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_int16x4_t
simde_vbsl_s16(simde_int16x4_t a, simde_int16x4_t b, simde_int16x4_t c) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vbsl_s16(a, b, c);
  #else
    return simde_veor_s16(c, simde_vand_s16(simde_veor_s16(c, b), a));
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vbsl_s16
  #define vbsl_s16(a, b, c) simde_vbsl_s16((a), (b), (c))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_int32x2_t
simde_vbsl_s32(simde_int32x2_t a, simde_int32x2_t b, simde_int32x2_t c) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vbsl_s32(a, b, c);
  #else
    return simde_veor_s32(c, simde_vand_s32(simde_veor_s32(c, b), a));
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vbsl_s32
  #define vbsl_s32(a, b, c) simde_vbsl_s32((a), (b), (c))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_int64x1_t
simde_vbsl_s64(simde_int64x1_t a, simde_int64x1_t b, simde_int64x1_t c) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vbsl_s64(a, b, c);
  #else
    return simde_veor_s64(c, simde_vand_s64(simde_veor_s64(c, b), a));
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vbsl_s64
  #define vbsl_s64(a, b, c) simde_vbsl_s64((a), (b), (c))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint8x8_t
simde_vbsl_u8(simde_uint8x8_t a, simde_uint8x8_t b, simde_uint8x8_t c) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vbsl_u8(a, b, c);
  #else
    return simde_veor_u8(c, simde_vand_u8(simde_veor_u8(c, b), a));
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vbsl_u8
  #define vbsl_u8(a, b, c) simde_vbsl_u8((a), (b), (c))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint16x4_t
simde_vbsl_u16(simde_uint16x4_t a, simde_uint16x4_t b, simde_uint16x4_t c) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vbsl_u16(a, b, c);
  #else
    return simde_veor_u16(c, simde_vand_u16(simde_veor_u16(c, b), a));
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vbsl_u16
  #define vbsl_u16(a, b, c) simde_vbsl_u16((a), (b), (c))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint32x2_t
simde_vbsl_u32(simde_uint32x2_t a, simde_uint32x2_t b, simde_uint32x2_t c) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vbsl_u32(a, b, c);
  #else
    return simde_veor_u32(c, simde_vand_u32(simde_veor_u32(c, b), a));
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vbsl_u32
  #define vbsl_u32(a, b, c) simde_vbsl_u32((a), (b), (c))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint64x1_t
simde_vbsl_u64(simde_uint64x1_t a, simde_uint64x1_t b, simde_uint64x1_t c) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vbsl_u64(a, b, c);
  #else
    return simde_veor_u64(c, simde_vand_u64(simde_veor_u64(c, b), a));
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vbsl_u64
  #define vbsl_u64(a, b, c) simde_vbsl_u64((a), (b), (c))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_float32x4_t
simde_vbslq_f32(simde_float32x4_t a, simde_float32x4_t b, simde_float32x4_t c) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vbsl_f64(a, b, c);
  #else
    simde_uint8x16_t a_, b_, c_, r_;
    simde_float32x4_t r;
    simde_memcpy(&a_, &a, sizeof(a_));
    simde_memcpy(&b_, &b, sizeof(b_));
    simde_memcpy(&c_, &c, sizeof(c_));
    r_ = simde_veorq_u8(c_, simde_vandq_u8(simde_veorq_u8(c_, b_), a_));
    simde_memcpy(&r, &r_, sizeof(r));
    return r;
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vbsl_f64
  #define vbsl_f64(a, b, c) simde_vbsl_f64((a), (b), (c))
#endif


SIMDE_FUNCTION_ATTRIBUTES
simde_float64x2_t
simde_vbslq_f64(simde_float64x2_t a, simde_float64x2_t b, simde_float64x2_t c) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vbsl_f64(a, b, c);
  #else
    simde_uint8x16_t a_, b_, c_, r_;
    simde_float64x2_t r;
    simde_memcpy(&a_, &a, sizeof(a_));
    simde_memcpy(&b_, &b, sizeof(b_));
    simde_memcpy(&c_, &c, sizeof(c_));
    r_ = simde_veorq_u8(c_, simde_vandq_u8(simde_veorq_u8(c_, b_), a_));
    simde_memcpy(&r, &r_, sizeof(r));
    return r;
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vbsl_f64
  #define vbsl_f64(a, b, c) simde_vbsl_f64((a), (b), (c))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_int8x16_t
simde_vbslq_s8(simde_int8x16_t a, simde_int8x16_t b, simde_int8x16_t c) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vbslq_s8(a, b, c);
  #else
    return simde_veorq_s8(c, simde_vandq_s8(simde_veorq_s8(c, b), a));
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vbslq_s8
  #define vbslq_s8(a, b, c) simde_vbslq_s8((a), (b), (c))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_int16x8_t
simde_vbslq_s16(simde_int16x8_t a, simde_int16x8_t b, simde_int16x8_t c) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vbslq_s16(a, b, c);
  #else
    return simde_veorq_s16(c, simde_vandq_s16(simde_veorq_s16(c, b), a));
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vbslq_s16
  #define vbslq_s16(a, b, c) simde_vbslq_s16((a), (b), (c))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_int32x4_t
simde_vbslq_s32(simde_int32x4_t a, simde_int32x4_t b, simde_int32x4_t c) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vbslq_s32(a, b, c);
  #else
    return simde_veorq_s32(c, simde_vandq_s32(simde_veorq_s32(c, b), a));
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vbslq_s32
  #define vbslq_s32(a, b, c) simde_vbslq_s32((a), (b), (c))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_int64x2_t
simde_vbslq_s64(simde_int64x2_t a, simde_int64x2_t b, simde_int64x2_t c) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vbslq_s64(a, b, c);
  #else
    return simde_veorq_s64(c, simde_vandq_s64(simde_veorq_s64(c, b), a));
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vbslq_s64
  #define vbslq_s64(a, b, c) simde_vbslq_s64((a), (b), (c))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint8x16_t
simde_vbslq_u8(simde_uint8x16_t a, simde_uint8x16_t b, simde_uint8x16_t c) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vbslq_u8(a, b, c);
  #else
    return simde_veorq_u8(c, simde_vandq_u8(simde_veorq_u8(c, b), a));
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vbslq_u8
  #define vbslq_u8(a, b, c) simde_vbslq_u8((a), (b), (c))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint16x8_t
simde_vbslq_u16(simde_uint16x8_t a, simde_uint16x8_t b, simde_uint16x8_t c) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vbslq_u16(a, b, c);
  #else
    return simde_veorq_u16(c, simde_vandq_u16(simde_veorq_u16(c, b), a));
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vbslq_u16
  #define vbslq_u16(a, b, c) simde_vbslq_u16((a), (b), (c))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint32x4_t
simde_vbslq_u32(simde_uint32x4_t a, simde_uint32x4_t b, simde_uint32x4_t c) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vbslq_u32(a, b, c);
  #else
    return simde_veorq_u32(c, simde_vandq_u32(simde_veorq_u32(c, b), a));
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vbslq_u32
  #define vbslq_u32(a, b, c) simde_vbslq_u32((a), (b), (c))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint64x2_t
simde_vbslq_u64(simde_uint64x2_t a, simde_uint64x2_t b, simde_uint64x2_t c) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vbslq_u64(a, b, c);
  #else
    return simde_veorq_u64(c, simde_vandq_u64(simde_veorq_u64(c, b), a));
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vbslq_u64
  #define vbslq_u64(a, b, c) simde_vbslq_u64((a), (b), (c))
#endif

SIMDE_END_DECLS_
HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_ARM_NEON_BSL_H) */
