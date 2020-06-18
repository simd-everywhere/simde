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

#if !defined(SIMDE_ARM_NEON_ADD_H)
#define SIMDE_ARM_NEON_ADD_H

#include "types.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

#if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
#define SIMDE_ARM_NEON_A32V7_REINTERPRET_BODY(Element_Source_Name, Element_Target_Name, Source_Type, Return_Type) \
  return vreinterpret_##Element_Target_Name##_##Element_Source_Name(a);
#else
#define SIMDE_ARM_NEON_A32V7_REINTERPRET_BODY(Element_Source_Name, Element_Target_Name, Source_Type, Return_Type) \
  simde_##Return_Type##_private r_;                                     \
  simde_##Source_Type##_private a_ = simde_##Source_Type##_to_private(a); \
  simde_memcpy(&r_, &a_, sizeof(r_));                                   \
  return simde_##Return_Type##_from_private(r_);
#endif
#if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
#define SIMDE_ARM_NEON_A32V7_REINTERPRETQ_BODY(Element_Source_Name, Element_Target_Name, Source_Type, Return_Type) \
  return vreinterpretq_##Element_Target_Name##_##Element_Source_Name(a);
#else
#define SIMDE_ARM_NEON_A32V7_REINTERPRETQ_BODY(Element_Source_Name, Element_Target_Name, Source_Type, Return_Type) \
  simde_##Return_Type##_private r_;                                     \
  simde_##Source_Type##_private a_ = simde_##Source_Type##_to_private(a); \
  simde_memcpy(&r_, &a_, sizeof(r_));                                   \
  return simde_##Return_Type##_from_private(r_);
#endif

#if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
#define SIMDE_ARM_NEON_A64V8_REINTERPRET_BODY(Element_Source_Name, Element_Target_Name, Source_Type, Return_Type) \
  return vreinterpret_##Element_Target_Name##_##Element_Source_Name(a);
#else
#define SIMDE_ARM_NEON_A64V8_REINTERPRET_BODY(Element_Source_Name, Element_Target_Name, Source_Type, Return_Type) \
  simde_##Return_Type##_private r_;                                     \
  simde_##Source_Type##_private a_ = simde_##Source_Type##_to_private(a); \
  simde_memcpy(&r_, &a_, sizeof(r_));                                   \
  return simde_##Return_Type##_from_private(r_);
#endif

#if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
#define SIMDE_ARM_NEON_A64V8_REINTERPRETQ_BODY(Element_Source_Name, Element_Target_Name, Source_Type, Return_Type) \
  return vreinterpretq_##Element_Target_Name##_##Element_Source_Name(a);
#else
#define SIMDE_ARM_NEON_A64V8_REINTERPRETQ_BODY(Element_Source_Name, Element_Target_Name, Source_Type, Return_Type) \
  simde_##Return_Type##_private r_;                                     \
  simde_##Source_Type##_private a_ = simde_##Source_Type##_to_private(a); \
  simde_memcpy(&r_, &a_, sizeof(r_));                                   \
  return simde_##Return_Type##_from_private(r_);
#endif

#define SIMDE_ARM_NEON_A32V7_REINTERPRET_GEN(Element_Source_Name, Element_Target_Name, Source_Type, Return_Type) \
SIMDE_FUNCTION_ATTRIBUTES \
simde_##Return_Type##_t \
simde_vreinterpret_##Element_Target_Name##_##Element_Source_Name(simde_##Source_Type##_t a) {  \
  SIMDE_ARM_NEON_A32V7_REINTERPRET_BODY(Element_Source_Name, Element_Target_Name, Source_Type, Return_Type) \
} \

#define SIMDE_ARM_NEON_A32V7_REINTERPRETQ_GEN(Element_Source_Name, Element_Target_Name, Source_Type, Return_Type) \
SIMDE_FUNCTION_ATTRIBUTES \
simde_##Return_Type##_t \
simde_vreinterpretq_##Element_Target_Name##_##Element_Source_Name(simde_##Source_Type##_t a) { \
  SIMDE_ARM_NEON_A32V7_REINTERPRETQ_BODY(Element_Source_Name, Element_Target_Name, Source_Type, Return_Type) \
} \

#define SIMDE_ARM_NEON_A64V8_REINTERPRET_GEN(Element_Source_Name, Element_Target_Name, Source_Type, Return_Type) \
SIMDE_FUNCTION_ATTRIBUTES \
simde_##Return_Type##_t \
simde_vreinterpret_##Element_Target_Name##_##Element_Source_Name(simde_##Source_Type##_t a) {  \
  SIMDE_ARM_NEON_A64V8_REINTERPRET_BODY(Element_Source_Name, Element_Target_Name, Source_Type, Return_Type) \
} \

#define SIMDE_ARM_NEON_A64V8_REINTERPRETQ_GEN(Element_Source_Name, Element_Target_Name, Source_Type, Return_Type) \
SIMDE_FUNCTION_ATTRIBUTES \
simde_##Return_Type##_t \
simde_vreinterpretq_##Element_Target_Name##_##Element_Source_Name(simde_##Source_Type##_t a) { \
  SIMDE_ARM_NEON_A64V8_REINTERPRETQ_BODY(Element_Source_Name, Element_Target_Name, Source_Type, Return_Type) \
} \

#define SIMDE_ARM_NEON_REINTERPRET_GEN_S8(Element_Target_Return_Type_Short, Element_Target_Return_Type_Long) \
    SIMDE_ARM_NEON_A32V7_REINTERPRET_GEN(s16, s8, int16x4, Element_Target_Return_Type_Short) \
    SIMDE_ARM_NEON_A32V7_REINTERPRET_GEN(s32, s8, int32x2, Element_Target_Return_Type_Short) \
    SIMDE_ARM_NEON_A32V7_REINTERPRET_GEN(s64, s8, int64x1, Element_Target_Return_Type_Short) \
    SIMDE_ARM_NEON_A32V7_REINTERPRET_GEN(u8,  s8, uint8x8, Element_Target_Return_Type_Short) \
    SIMDE_ARM_NEON_A32V7_REINTERPRET_GEN(u16, s8, uint16x4, Element_Target_Return_Type_Short) \
    SIMDE_ARM_NEON_A32V7_REINTERPRET_GEN(u32, s8, uint32x2, Element_Target_Return_Type_Short) \
    SIMDE_ARM_NEON_A32V7_REINTERPRET_GEN(u64, s8, uint64x1, Element_Target_Return_Type_Short) \
    SIMDE_ARM_NEON_A32V7_REINTERPRET_GEN(f32, s8, float32x2, Element_Target_Return_Type_Short) \
    SIMDE_ARM_NEON_A64V8_REINTERPRET_GEN(f64, s8, float64x1, Element_Target_Return_Type_Short) \
    SIMDE_ARM_NEON_A32V7_REINTERPRETQ_GEN(s16, s8, int16x8, Element_Target_Return_Type_Long) \
    SIMDE_ARM_NEON_A32V7_REINTERPRETQ_GEN(s32, s8, int32x4, Element_Target_Return_Type_Long) \
    SIMDE_ARM_NEON_A32V7_REINTERPRETQ_GEN(s64, s8, int64x2, Element_Target_Return_Type_Long) \
    SIMDE_ARM_NEON_A32V7_REINTERPRETQ_GEN(u8,  s8, uint8x16, Element_Target_Return_Type_Long) \
    SIMDE_ARM_NEON_A32V7_REINTERPRETQ_GEN(u16, s8, uint16x8, Element_Target_Return_Type_Long) \
    SIMDE_ARM_NEON_A32V7_REINTERPRETQ_GEN(u32, s8, uint32x4, Element_Target_Return_Type_Long) \
    SIMDE_ARM_NEON_A32V7_REINTERPRETQ_GEN(u64, s8, uint64x2, Element_Target_Return_Type_Long) \
    SIMDE_ARM_NEON_A32V7_REINTERPRETQ_GEN(f32, s8, float32x4, Element_Target_Return_Type_Long) \
    SIMDE_ARM_NEON_A64V8_REINTERPRETQ_GEN(f64, s8, float64x2, Element_Target_Return_Type_Long)

#define SIMDE_ARM_NEON_REINTERPRET_GEN_S16(Element_Target_Return_Type_Short, Element_Target_Return_Type_Long) \
    SIMDE_ARM_NEON_A32V7_REINTERPRET_GEN(s8,  s16, int8x8, Element_Target_Return_Type_Short) \
    SIMDE_ARM_NEON_A32V7_REINTERPRET_GEN(s32, s16, int32x2, Element_Target_Return_Type_Short) \
    SIMDE_ARM_NEON_A32V7_REINTERPRET_GEN(s64, s16, int64x1, Element_Target_Return_Type_Short) \
    SIMDE_ARM_NEON_A32V7_REINTERPRET_GEN(u8,  s16, uint8x8, Element_Target_Return_Type_Short) \
    SIMDE_ARM_NEON_A32V7_REINTERPRET_GEN(u16, s16, uint16x4, Element_Target_Return_Type_Short) \
    SIMDE_ARM_NEON_A32V7_REINTERPRET_GEN(u32, s16, uint32x2, Element_Target_Return_Type_Short) \
    SIMDE_ARM_NEON_A32V7_REINTERPRET_GEN(u64, s16, uint64x1, Element_Target_Return_Type_Short) \
    SIMDE_ARM_NEON_A32V7_REINTERPRET_GEN(f32, s16, float32x2, Element_Target_Return_Type_Short) \
    SIMDE_ARM_NEON_A64V8_REINTERPRET_GEN(f64, s16, float64x1, Element_Target_Return_Type_Short) \
    SIMDE_ARM_NEON_A32V7_REINTERPRETQ_GEN(s8,  s16, int8x16, Element_Target_Return_Type_Long) \
    SIMDE_ARM_NEON_A32V7_REINTERPRETQ_GEN(s32, s16, int32x4, Element_Target_Return_Type_Long) \
    SIMDE_ARM_NEON_A32V7_REINTERPRETQ_GEN(s64, s16, int64x2, Element_Target_Return_Type_Long) \
    SIMDE_ARM_NEON_A32V7_REINTERPRETQ_GEN(u8,  s16, uint8x16, Element_Target_Return_Type_Long) \
    SIMDE_ARM_NEON_A32V7_REINTERPRETQ_GEN(u16, s16, uint16x8, Element_Target_Return_Type_Long) \
    SIMDE_ARM_NEON_A32V7_REINTERPRETQ_GEN(u32, s16, uint32x4, Element_Target_Return_Type_Long) \
    SIMDE_ARM_NEON_A32V7_REINTERPRETQ_GEN(u64, s16, uint64x2, Element_Target_Return_Type_Long) \
    SIMDE_ARM_NEON_A32V7_REINTERPRETQ_GEN(f32, s16, float32x4, Element_Target_Return_Type_Long) \
    SIMDE_ARM_NEON_A64V8_REINTERPRETQ_GEN(f64, s16, float64x2, Element_Target_Return_Type_Long)

#define SIMDE_ARM_NEON_REINTERPRET_GEN_S32(Element_Target_Return_Type_Short, Element_Target_Return_Type_Long) \
    SIMDE_ARM_NEON_A32V7_REINTERPRET_GEN(s8,  s32, int8x8, Element_Target_Return_Type_Short) \
    SIMDE_ARM_NEON_A32V7_REINTERPRET_GEN(s16, s32, int16x4, Element_Target_Return_Type_Short) \
    SIMDE_ARM_NEON_A32V7_REINTERPRET_GEN(s64, s32, int64x1, Element_Target_Return_Type_Short) \
    SIMDE_ARM_NEON_A32V7_REINTERPRET_GEN(u8,  s32, uint8x8, Element_Target_Return_Type_Short) \
    SIMDE_ARM_NEON_A32V7_REINTERPRET_GEN(u16, s32, uint16x4, Element_Target_Return_Type_Short) \
    SIMDE_ARM_NEON_A32V7_REINTERPRET_GEN(u32, s32, uint32x2, Element_Target_Return_Type_Short) \
    SIMDE_ARM_NEON_A32V7_REINTERPRET_GEN(u64, s32, uint64x1, Element_Target_Return_Type_Short) \
    SIMDE_ARM_NEON_A32V7_REINTERPRET_GEN(f32, s32, float32x2, Element_Target_Return_Type_Short) \
    SIMDE_ARM_NEON_A64V8_REINTERPRET_GEN(f64, s32, float64x1, Element_Target_Return_Type_Short) \
    SIMDE_ARM_NEON_A32V7_REINTERPRETQ_GEN(s8,  s32, int8x16, Element_Target_Return_Type_Long) \
    SIMDE_ARM_NEON_A32V7_REINTERPRETQ_GEN(s16, s32, int16x8, Element_Target_Return_Type_Long) \
    SIMDE_ARM_NEON_A32V7_REINTERPRETQ_GEN(s64, s32, int64x2, Element_Target_Return_Type_Long) \
    SIMDE_ARM_NEON_A32V7_REINTERPRETQ_GEN(u8,  s32, uint8x16, Element_Target_Return_Type_Long) \
    SIMDE_ARM_NEON_A32V7_REINTERPRETQ_GEN(u16, s32, uint16x8, Element_Target_Return_Type_Long) \
    SIMDE_ARM_NEON_A32V7_REINTERPRETQ_GEN(u32, s32, uint32x4, Element_Target_Return_Type_Long) \
    SIMDE_ARM_NEON_A32V7_REINTERPRETQ_GEN(u64, s32, uint64x2, Element_Target_Return_Type_Long) \
    SIMDE_ARM_NEON_A32V7_REINTERPRETQ_GEN(f32, s32, float32x4, Element_Target_Return_Type_Long) \
    SIMDE_ARM_NEON_A64V8_REINTERPRETQ_GEN(f64, s32, float64x2, Element_Target_Return_Type_Long)

#define SIMDE_ARM_NEON_REINTERPRET_GEN_S64(Element_Target_Return_Type_Short, Element_Target_Return_Type_Long) \
    SIMDE_ARM_NEON_A32V7_REINTERPRET_GEN(s8,  s64, int8x8, Element_Target_Return_Type_Short) \
    SIMDE_ARM_NEON_A32V7_REINTERPRET_GEN(s16, s64, int16x4, Element_Target_Return_Type_Short) \
    SIMDE_ARM_NEON_A32V7_REINTERPRET_GEN(s32, s64, int32x2, Element_Target_Return_Type_Short) \
    SIMDE_ARM_NEON_A32V7_REINTERPRET_GEN(u8,  s64, uint8x8, Element_Target_Return_Type_Short) \
    SIMDE_ARM_NEON_A32V7_REINTERPRET_GEN(u16, s64, uint16x4, Element_Target_Return_Type_Short) \
    SIMDE_ARM_NEON_A32V7_REINTERPRET_GEN(u32, s64, uint32x2, Element_Target_Return_Type_Short) \
    SIMDE_ARM_NEON_A32V7_REINTERPRET_GEN(u64, s64, uint64x1, Element_Target_Return_Type_Short) \
    SIMDE_ARM_NEON_A32V7_REINTERPRET_GEN(f32, s64, float32x2, Element_Target_Return_Type_Short) \
    SIMDE_ARM_NEON_A64V8_REINTERPRET_GEN(f64, s64, float64x1, Element_Target_Return_Type_Short) \
    SIMDE_ARM_NEON_A32V7_REINTERPRETQ_GEN(s8,  s64, int8x16, Element_Target_Return_Type_Long) \
    SIMDE_ARM_NEON_A32V7_REINTERPRETQ_GEN(s16, s64, int16x8, Element_Target_Return_Type_Long) \
    SIMDE_ARM_NEON_A32V7_REINTERPRETQ_GEN(s32, s64, int32x4, Element_Target_Return_Type_Long) \
    SIMDE_ARM_NEON_A32V7_REINTERPRETQ_GEN(u8,  s64, uint8x16, Element_Target_Return_Type_Long) \
    SIMDE_ARM_NEON_A32V7_REINTERPRETQ_GEN(u16, s64, uint16x8, Element_Target_Return_Type_Long) \
    SIMDE_ARM_NEON_A32V7_REINTERPRETQ_GEN(u32, s64, uint32x4, Element_Target_Return_Type_Long) \
    SIMDE_ARM_NEON_A32V7_REINTERPRETQ_GEN(u64, s64, uint64x2, Element_Target_Return_Type_Long) \
    SIMDE_ARM_NEON_A32V7_REINTERPRETQ_GEN(f32, s64, float32x4, Element_Target_Return_Type_Long) \
    SIMDE_ARM_NEON_A64V8_REINTERPRETQ_GEN(f64, s64, float64x2, Element_Target_Return_Type_Long)

#define SIMDE_ARM_NEON_REINTERPRET_GEN_U8(Element_Target_Return_Type_Short, Element_Target_Return_Type_Long) \
    SIMDE_ARM_NEON_A32V7_REINTERPRET_GEN(s8,  u8, int8x8, Element_Target_Return_Type_Short) \
    SIMDE_ARM_NEON_A32V7_REINTERPRET_GEN(s16, u8, int16x4, Element_Target_Return_Type_Short) \
    SIMDE_ARM_NEON_A32V7_REINTERPRET_GEN(s32, u8, int32x2, Element_Target_Return_Type_Short) \
    SIMDE_ARM_NEON_A32V7_REINTERPRET_GEN(s64, u8, int64x1, Element_Target_Return_Type_Short) \
    SIMDE_ARM_NEON_A32V7_REINTERPRET_GEN(u8,  u8, uint8x8, Element_Target_Return_Type_Short) \
    SIMDE_ARM_NEON_A32V7_REINTERPRET_GEN(u16, u8, uint16x4, Element_Target_Return_Type_Short) \
    SIMDE_ARM_NEON_A32V7_REINTERPRET_GEN(u32, u8, uint32x2, Element_Target_Return_Type_Short) \
    SIMDE_ARM_NEON_A32V7_REINTERPRET_GEN(u64, u8, uint64x1, Element_Target_Return_Type_Short) \
    SIMDE_ARM_NEON_A32V7_REINTERPRET_GEN(f32, u8, float32x2, Element_Target_Return_Type_Short) \
    SIMDE_ARM_NEON_A64V8_REINTERPRET_GEN(f64, u8, float64x1, Element_Target_Return_Type_Short) \
    SIMDE_ARM_NEON_A32V7_REINTERPRETQ_GEN(s8,  u8, int8x16, Element_Target_Return_Type_Long) \
    SIMDE_ARM_NEON_A32V7_REINTERPRETQ_GEN(s16, u8, int16x8, Element_Target_Return_Type_Long) \
    SIMDE_ARM_NEON_A32V7_REINTERPRETQ_GEN(s32, u8, int32x4, Element_Target_Return_Type_Long) \
    SIMDE_ARM_NEON_A32V7_REINTERPRETQ_GEN(s64, u8, int64x2, Element_Target_Return_Type_Long) \
    SIMDE_ARM_NEON_A32V7_REINTERPRETQ_GEN(u8,  u8, uint8x16, Element_Target_Return_Type_Long) \
    SIMDE_ARM_NEON_A32V7_REINTERPRETQ_GEN(u16, u8, uint16x8, Element_Target_Return_Type_Long) \
    SIMDE_ARM_NEON_A32V7_REINTERPRETQ_GEN(u32, u8, uint32x4, Element_Target_Return_Type_Long) \
    SIMDE_ARM_NEON_A32V7_REINTERPRETQ_GEN(u64, u8, uint64x2, Element_Target_Return_Type_Long) \
    SIMDE_ARM_NEON_A32V7_REINTERPRETQ_GEN(f32, u8, float32x4, Element_Target_Return_Type_Long) \
    SIMDE_ARM_NEON_A64V8_REINTERPRETQ_GEN(f64, u8, float64x2, Element_Target_Return_Type_Long)

#define SIMDE_ARM_NEON_REINTERPRET_GEN_U16(Element_Target_Return_Type_Short, Element_Target_Return_Type_Long) \
    SIMDE_ARM_NEON_A32V7_REINTERPRET_GEN(s8,  u16, int8x8, Element_Target_Return_Type_Short) \
    SIMDE_ARM_NEON_A32V7_REINTERPRET_GEN(s16, u16, int16x4, Element_Target_Return_Type_Short) \
    SIMDE_ARM_NEON_A32V7_REINTERPRET_GEN(s32, u16, int32x2, Element_Target_Return_Type_Short) \
    SIMDE_ARM_NEON_A32V7_REINTERPRET_GEN(s64, u16, int64x1, Element_Target_Return_Type_Short) \
    SIMDE_ARM_NEON_A32V7_REINTERPRET_GEN(u8,  u16, uint8x8, Element_Target_Return_Type_Short) \
    SIMDE_ARM_NEON_A32V7_REINTERPRET_GEN(u32, u16, uint32x2, Element_Target_Return_Type_Short) \
    SIMDE_ARM_NEON_A32V7_REINTERPRET_GEN(u64, u16, uint64x1, Element_Target_Return_Type_Short) \
    SIMDE_ARM_NEON_A32V7_REINTERPRET_GEN(f32, u16, float32x2, Element_Target_Return_Type_Short) \
    SIMDE_ARM_NEON_A64V8_REINTERPRET_GEN(f64, u16, float64x1, Element_Target_Return_Type_Short) \
    SIMDE_ARM_NEON_A32V7_REINTERPRETQ_GEN(s8,  u16, int8x16, Element_Target_Return_Type_Long) \
    SIMDE_ARM_NEON_A32V7_REINTERPRETQ_GEN(s16, u16, int16x8, Element_Target_Return_Type_Long) \
    SIMDE_ARM_NEON_A32V7_REINTERPRETQ_GEN(s32, u16, int32x4, Element_Target_Return_Type_Long) \
    SIMDE_ARM_NEON_A32V7_REINTERPRETQ_GEN(s64, u16, int64x2, Element_Target_Return_Type_Long) \
    SIMDE_ARM_NEON_A32V7_REINTERPRETQ_GEN(u8,  u16, uint8x16, Element_Target_Return_Type_Long) \
    SIMDE_ARM_NEON_A32V7_REINTERPRETQ_GEN(u32, u16, uint32x4, Element_Target_Return_Type_Long) \
    SIMDE_ARM_NEON_A32V7_REINTERPRETQ_GEN(u64, u16, uint64x2, Element_Target_Return_Type_Long) \
    SIMDE_ARM_NEON_A32V7_REINTERPRETQ_GEN(f32, u16, float32x4, Element_Target_Return_Type_Long) \
    SIMDE_ARM_NEON_A64V8_REINTERPRETQ_GEN(f64, u16, float64x2, Element_Target_Return_Type_Long)

#define SIMDE_ARM_NEON_REINTERPRET_GEN_U32(Element_Target_Return_Type_Short, Element_Target_Return_Type_Long) \
    SIMDE_ARM_NEON_A32V7_REINTERPRET_GEN(s8,  u32, int8x8, Element_Target_Return_Type_Short) \
    SIMDE_ARM_NEON_A32V7_REINTERPRET_GEN(s16, u32, int16x4, Element_Target_Return_Type_Short)\
    SIMDE_ARM_NEON_A32V7_REINTERPRET_GEN(s32, u32, int32x2, Element_Target_Return_Type_Short)\
    SIMDE_ARM_NEON_A32V7_REINTERPRET_GEN(s64, u32, int64x1, Element_Target_Return_Type_Short)\
    SIMDE_ARM_NEON_A32V7_REINTERPRET_GEN(u8,  u32, uint8x8, Element_Target_Return_Type_Short)\
    SIMDE_ARM_NEON_A32V7_REINTERPRET_GEN(u16, u32, uint16x4, Element_Target_Return_Type_Short)\
    SIMDE_ARM_NEON_A32V7_REINTERPRET_GEN(u64, u32, uint64x1, Element_Target_Return_Type_Short)\
    SIMDE_ARM_NEON_A32V7_REINTERPRET_GEN(f32, u32, float32x2, Element_Target_Return_Type_Short)\
    SIMDE_ARM_NEON_A64V8_REINTERPRET_GEN(f64, u32, float64x1, Element_Target_Return_Type_Short)\
    SIMDE_ARM_NEON_A32V7_REINTERPRETQ_GEN(s8,  u32, int8x16, Element_Target_Return_Type_Long)\
    SIMDE_ARM_NEON_A32V7_REINTERPRETQ_GEN(s16, u32, int16x8, Element_Target_Return_Type_Long)\
    SIMDE_ARM_NEON_A32V7_REINTERPRETQ_GEN(s32, u32, int32x4, Element_Target_Return_Type_Long)\
    SIMDE_ARM_NEON_A32V7_REINTERPRETQ_GEN(s64, u32, int64x2, Element_Target_Return_Type_Long)\
    SIMDE_ARM_NEON_A32V7_REINTERPRETQ_GEN(u8,  u32, uint8x16, Element_Target_Return_Type_Long)\
    SIMDE_ARM_NEON_A32V7_REINTERPRETQ_GEN(u16, u32, uint16x8, Element_Target_Return_Type_Long)\
    SIMDE_ARM_NEON_A32V7_REINTERPRETQ_GEN(u64, u32, uint64x2, Element_Target_Return_Type_Long)\
    SIMDE_ARM_NEON_A32V7_REINTERPRETQ_GEN(f32, u32, float32x4, Element_Target_Return_Type_Long)\
    SIMDE_ARM_NEON_A64V8_REINTERPRETQ_GEN(f64, u32, float64x2, Element_Target_Return_Type_Long)

#define SIMDE_ARM_NEON_REINTERPRET_GEN_U64(Element_Target_Return_Type_Short, Element_Target_Return_Type_Long) \
    SIMDE_ARM_NEON_A32V7_REINTERPRET_GEN(s8,  u64, int8x8, Element_Target_Return_Type_Short)\
    SIMDE_ARM_NEON_A32V7_REINTERPRET_GEN(s16, u64, int16x4, Element_Target_Return_Type_Short)\
    SIMDE_ARM_NEON_A32V7_REINTERPRET_GEN(s32, u64, int32x2, Element_Target_Return_Type_Short)\
    SIMDE_ARM_NEON_A32V7_REINTERPRET_GEN(s64, u64, int64x1, Element_Target_Return_Type_Short)\
    SIMDE_ARM_NEON_A32V7_REINTERPRET_GEN(u8,  u64, uint8x8, Element_Target_Return_Type_Short)\
    SIMDE_ARM_NEON_A32V7_REINTERPRET_GEN(u16, u64, uint16x4, Element_Target_Return_Type_Short)\
    SIMDE_ARM_NEON_A32V7_REINTERPRET_GEN(u32, u64, uint32x2, Element_Target_Return_Type_Short)\
    SIMDE_ARM_NEON_A32V7_REINTERPRET_GEN(f32, u64, float32x2, Element_Target_Return_Type_Short)\
    SIMDE_ARM_NEON_A64V8_REINTERPRET_GEN(f64, u64, float64x1, Element_Target_Return_Type_Short)\
    SIMDE_ARM_NEON_A32V7_REINTERPRETQ_GEN(s8,  u64, int8x16, Element_Target_Return_Type_Long)\
    SIMDE_ARM_NEON_A32V7_REINTERPRETQ_GEN(s16, u64, int16x8, Element_Target_Return_Type_Long)\
    SIMDE_ARM_NEON_A32V7_REINTERPRETQ_GEN(s32, u64, int32x4, Element_Target_Return_Type_Long)\
    SIMDE_ARM_NEON_A32V7_REINTERPRETQ_GEN(s64, u64, int64x2, Element_Target_Return_Type_Long)\
    SIMDE_ARM_NEON_A32V7_REINTERPRETQ_GEN(u8,  u64, uint8x16, Element_Target_Return_Type_Long)\
    SIMDE_ARM_NEON_A32V7_REINTERPRETQ_GEN(u16, u64, uint16x8, Element_Target_Return_Type_Long)\
    SIMDE_ARM_NEON_A32V7_REINTERPRETQ_GEN(u32, u64, uint32x4, Element_Target_Return_Type_Long)\
    SIMDE_ARM_NEON_A32V7_REINTERPRETQ_GEN(f32, u64, float32x4, Element_Target_Return_Type_Long)\
    SIMDE_ARM_NEON_A64V8_REINTERPRETQ_GEN(f64, u64, float64x2, Element_Target_Return_Type_Long)

#define SIMDE_ARM_NEON_REINTERPRET_GEN_F32(Element_Target_Return_Type_Short, Element_Target_Return_Type_Long) \
    SIMDE_ARM_NEON_A32V7_REINTERPRET_GEN(s8,  f32, int8x8, Element_Target_Return_Type_Short)\
    SIMDE_ARM_NEON_A32V7_REINTERPRET_GEN(s16, f32, int16x4, Element_Target_Return_Type_Short)\
    SIMDE_ARM_NEON_A32V7_REINTERPRET_GEN(s32, f32, int32x2, Element_Target_Return_Type_Short)\
    SIMDE_ARM_NEON_A32V7_REINTERPRET_GEN(s64, f32, int64x1, Element_Target_Return_Type_Short)\
    SIMDE_ARM_NEON_A32V7_REINTERPRET_GEN(u8,  f32, uint8x8, Element_Target_Return_Type_Short)\
    SIMDE_ARM_NEON_A32V7_REINTERPRET_GEN(u16, f32, uint16x4, Element_Target_Return_Type_Short)\
    SIMDE_ARM_NEON_A32V7_REINTERPRET_GEN(u32, f32, uint32x2, Element_Target_Return_Type_Short)\
    SIMDE_ARM_NEON_A32V7_REINTERPRET_GEN(u64, f32, uint64x1, Element_Target_Return_Type_Short)\
    SIMDE_ARM_NEON_A64V8_REINTERPRET_GEN(f64, f32, float64x1, Element_Target_Return_Type_Short)\
    SIMDE_ARM_NEON_A32V7_REINTERPRETQ_GEN(s8,  f32, int8x16, Element_Target_Return_Type_Long)\
    SIMDE_ARM_NEON_A32V7_REINTERPRETQ_GEN(s16, f32, int16x8, Element_Target_Return_Type_Long)\
    SIMDE_ARM_NEON_A32V7_REINTERPRETQ_GEN(s32, f32, int32x4, Element_Target_Return_Type_Long)\
    SIMDE_ARM_NEON_A32V7_REINTERPRETQ_GEN(s64, f32, int64x2, Element_Target_Return_Type_Long)\
    SIMDE_ARM_NEON_A32V7_REINTERPRETQ_GEN(u8,  f32, uint8x16, Element_Target_Return_Type_Long)\
    SIMDE_ARM_NEON_A32V7_REINTERPRETQ_GEN(u16, f32, uint16x8, Element_Target_Return_Type_Long)\
    SIMDE_ARM_NEON_A32V7_REINTERPRETQ_GEN(u32, f32, uint32x4, Element_Target_Return_Type_Long)\
    SIMDE_ARM_NEON_A32V7_REINTERPRETQ_GEN(u64, f32, uint64x2, Element_Target_Return_Type_Long)\
    SIMDE_ARM_NEON_A64V8_REINTERPRETQ_GEN(f64, f32, float64x2, Element_Target_Return_Type_Long)

#define SIMDE_ARM_NEON_REINTERPRET_GEN_F64(Element_Target_Return_Type_Short, Element_Target_Return_Type_Long) \
    SIMDE_ARM_NEON_A64V8_REINTERPRET_GEN(s8, f64, int8x8, Element_Target_Return_Type_Short) \
    SIMDE_ARM_NEON_A64V8_REINTERPRET_GEN(s16, f64, int16x4, Element_Target_Return_Type_Short) \
    SIMDE_ARM_NEON_A64V8_REINTERPRET_GEN(s32, f64, int32x2, Element_Target_Return_Type_Short) \
    SIMDE_ARM_NEON_A64V8_REINTERPRET_GEN(s64, f64, int64x1, Element_Target_Return_Type_Short) \
    SIMDE_ARM_NEON_A64V8_REINTERPRET_GEN(u8, f64, uint8x8, Element_Target_Return_Type_Short) \
    SIMDE_ARM_NEON_A64V8_REINTERPRET_GEN(u16, f64, uint16x4, Element_Target_Return_Type_Short) \
    SIMDE_ARM_NEON_A64V8_REINTERPRET_GEN(u32, f64, uint32x2, Element_Target_Return_Type_Short) \
    SIMDE_ARM_NEON_A64V8_REINTERPRET_GEN(u64, f64, uint64x1, Element_Target_Return_Type_Short) \
    SIMDE_ARM_NEON_A64V8_REINTERPRET_GEN(f32, f64, float32x2, Element_Target_Return_Type_Short) \
    SIMDE_ARM_NEON_A64V8_REINTERPRETQ_GEN(s8, f64, int8x16, Element_Target_Return_Type_Long) \
    SIMDE_ARM_NEON_A64V8_REINTERPRETQ_GEN(s16, f64, int16x8, Element_Target_Return_Type_Long) \
    SIMDE_ARM_NEON_A64V8_REINTERPRETQ_GEN(s32, f64, int32x4, Element_Target_Return_Type_Long) \
    SIMDE_ARM_NEON_A64V8_REINTERPRETQ_GEN(s64, f64, int64x2, Element_Target_Return_Type_Long) \
    SIMDE_ARM_NEON_A64V8_REINTERPRETQ_GEN(u8, f64, uint8x16, Element_Target_Return_Type_Long) \
    SIMDE_ARM_NEON_A64V8_REINTERPRETQ_GEN(u16, f64, uint16x8, Element_Target_Return_Type_Long) \
    SIMDE_ARM_NEON_A64V8_REINTERPRETQ_GEN(u32, f64, uint32x4, Element_Target_Return_Type_Long) \
    SIMDE_ARM_NEON_A64V8_REINTERPRETQ_GEN(u64, f64, uint64x2, Element_Target_Return_Type_Long) \
    SIMDE_ARM_NEON_A64V8_REINTERPRETQ_GEN(f32, f64, float32x4, Element_Target_Return_Type_Long)

// These are spaced apart so I can more easily look at them with
//  `gcc -E`, feel free the change the style.
SIMDE_ARM_NEON_REINTERPRET_GEN_S8(int8x8, int8x16)

SIMDE_ARM_NEON_REINTERPRET_GEN_S16(int16x4, int16x8)

SIMDE_ARM_NEON_REINTERPRET_GEN_S32(int32x2, int32x4)

SIMDE_ARM_NEON_REINTERPRET_GEN_S64(int64x1, int64x2)

SIMDE_ARM_NEON_REINTERPRET_GEN_U8(uint8x8, uint8x16)

SIMDE_ARM_NEON_REINTERPRET_GEN_U16(uint16x4, uint16x8)

SIMDE_ARM_NEON_REINTERPRET_GEN_U32(uint32x2, uint32x4)

SIMDE_ARM_NEON_REINTERPRET_GEN_U64(uint64x1, uint64x2)

SIMDE_ARM_NEON_REINTERPRET_GEN_F32(float32x2, float32x4)

SIMDE_ARM_NEON_REINTERPRET_GEN_F64(float64x1, float64x2)

SIMDE_END_DECLS_
HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_ARM_NEON_ADD_H) */
