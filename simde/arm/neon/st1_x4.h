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
 */

#if !defined(SIMDE_ARM_NEON_ST1_X4_H)
#define SIMDE_ARM_NEON_ST1_X4_H

#include "types.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

SIMDE_FUNCTION_ATTRIBUTES
void
simde_vst1_f16_x4(simde_float16_t ptr[HEDLEY_ARRAY_PARAM(16)], simde_float16x4x4_t val) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE) && defined(SIMDE_ARM_NEON_FP16)
    vst1_f16_x4(ptr, val);
  #else
    simde_float16x4_private val_[4];
    for (size_t i = 0; i < 4; i++) {
      val_[i] = simde_float16x4_to_private(val.val[i]);
    }
    simde_memcpy(ptr, &val_, sizeof(val_));
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vst1_f16_x4
  #define vst1_f16_x4(a, b) simde_vst1_f16_x4((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
void
simde_vst1_f32_x4(simde_float32_t ptr[HEDLEY_ARRAY_PARAM(8)], simde_float32x2x4_t val) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    vst1_f32_x4(ptr, val);
  #else
    simde_float32x2_private val_[4];
    for (size_t i = 0; i < 4; i++) {
      val_[i] = simde_float32x2_to_private(val.val[i]);
    }
    simde_memcpy(ptr, &val_, sizeof(val_));
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vst1_f32_x4
  #define vst1_f32_x4(a, b) simde_vst1_f32_x4((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
void
simde_vst1_f64_x4(simde_float64_t ptr[HEDLEY_ARRAY_PARAM(4)], simde_float64x1x4_t val) {
  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
    vst1_f64_x4(ptr, val);
  #else
    simde_float64x1_private val_[4];
    for (size_t i = 0; i < 4; i++) {
      val_[i] = simde_float64x1_to_private(val.val[i]);
    }
    simde_memcpy(ptr, &val_, sizeof(val_));
  #endif
}
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES)
  #undef vst1_f64_x4
  #define vst1_f64_x4(a, b) simde_vst1_f64_x4((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
void
simde_vst1_s8_x4(int8_t ptr[HEDLEY_ARRAY_PARAM(32)], simde_int8x8x4_t val) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    vst1_s8_x4(ptr, val);
  #else
    simde_int8x8_private val_[4];
    for (size_t i = 0; i < 4; i++) {
      val_[i] = simde_int8x8_to_private(val.val[i]);
    }
    simde_memcpy(ptr, &val_, sizeof(val_));
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vst1_s8_x4
  #define vst1_s8_x4(a, b) simde_vst1_s8_x4((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
void
simde_vst1_s16_x4(int16_t ptr[HEDLEY_ARRAY_PARAM(16)], simde_int16x4x4_t val) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    vst1_s16_x4(ptr, val);
  #else
    simde_int16x4_private val_[4];
    for (size_t i = 0; i < 4; i++) {
      val_[i] = simde_int16x4_to_private(val.val[i]);
    }
    simde_memcpy(ptr, &val_, sizeof(val_));
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vst1_s16_x4
  #define vst1_s16_x4(a, b) simde_vst1_s16_x4((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
void
simde_vst1_s32_x4(int32_t ptr[HEDLEY_ARRAY_PARAM(8)], simde_int32x2x4_t val) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    vst1_s32_x4(ptr, val);
  #else
    simde_int32x2_private val_[4];
    for (size_t i = 0; i < 4; i++) {
      val_[i] = simde_int32x2_to_private(val.val[i]);
    }
    simde_memcpy(ptr, &val_, sizeof(val_));
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vst1_s32_x4
  #define vst1_s32_x4(a, b) simde_vst1_s32_x4((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
void
simde_vst1_s64_x4(int64_t ptr[HEDLEY_ARRAY_PARAM(4)], simde_int64x1x4_t val) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    vst1_s64_x4(ptr, val);
  #else
    simde_int64x1_private val_[4];
    for (size_t i = 0; i < 4; i++) {
      val_[i] = simde_int64x1_to_private(val.val[i]);
    }
    simde_memcpy(ptr, &val_, sizeof(val_));
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vst1_s64_x4
  #define vst1_s64_x4(a, b) simde_vst1_s64_x4((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
void
simde_vst1_u8_x4(uint8_t ptr[HEDLEY_ARRAY_PARAM(32)], simde_uint8x8x4_t val) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    vst1_u8_x4(ptr, val);
  #else
    simde_uint8x8_private val_[4];
    for (size_t i = 0; i < 4; i++) {
      val_[i] = simde_uint8x8_to_private(val.val[i]);
    }
    simde_memcpy(ptr, &val_, sizeof(val_));
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vst1_u8_x4
  #define vst1_u8_x4(a, b) simde_vst1_u8_x4((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
void
simde_vst1_u16_x4(uint16_t ptr[HEDLEY_ARRAY_PARAM(16)], simde_uint16x4x4_t val) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    vst1_u16_x4(ptr, val);
  #else
    simde_uint16x4_private val_[4];
    for (size_t i = 0; i < 4; i++) {
      val_[i] = simde_uint16x4_to_private(val.val[i]);
    }
    simde_memcpy(ptr, &val_, sizeof(val_));
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vst1_u16_x4
  #define vst1_u16_x4(a, b) simde_vst1_u16_x4((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
void
simde_vst1_u32_x4(uint32_t ptr[HEDLEY_ARRAY_PARAM(8)], simde_uint32x2x4_t val) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    vst1_u32_x4(ptr, val);
  #else
    simde_uint32x2_private val_[4];
    for (size_t i = 0; i < 4; i++) {
      val_[i] = simde_uint32x2_to_private(val.val[i]);
    }
    simde_memcpy(ptr, &val_, sizeof(val_));
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vst1_u32_x4
  #define vst1_u32_x4(a, b) simde_vst1_u32_x4((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
void
simde_vst1_u64_x4(uint64_t ptr[HEDLEY_ARRAY_PARAM(4)], simde_uint64x1x4_t val) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    vst1_u64_x4(ptr, val);
  #else
    simde_uint64x1_private val_[4];
    for (size_t i = 0; i < 4; i++) {
      val_[i] = simde_uint64x1_to_private(val.val[i]);
    }
    simde_memcpy(ptr, &val_, sizeof(val_));
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vst1_u64_x4
  #define vst1_u64_x4(a, b) simde_vst1_u64_x4((a), (b))
#endif

/*
// [Eric] Pre-implemented bf16-related intrinsics
SIMDE_FUNCTION_ATTRIBUTES
void
simde_vst1_bf16_x4(simde_bfloat16_t ptr[HEDLEY_ARRAY_PARAM(16)], simde_bfloat16x4x4_t val) {
  #if defined(SIMDE_ARM_NEON_A32V8_NATIVE) && defined(SIMDE_ARM_NEON_FP16)
    vst1_bf16_x4(ptr, val);
  #else
    simde_bfloat16x4_private val_[4];
    for (size_t i = 0; i < 4; i++) {
      val_[i] = simde_bfloat16x4_to_private(val.val[i]);
    }
    simde_memcpy(ptr, &val_, sizeof(val_));
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V8_ENABLE_NATIVE_ALIASES)
  #undef vst1_bf16_x4
  #define vst1_bf16_x4(a, b) simde_vst1_bf16_x4((a), (b))
#endif
*/

SIMDE_END_DECLS_
HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_ARM_NEON_ST1_X4_H) */
