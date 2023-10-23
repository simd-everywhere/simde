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
 *   2023      Yi-Yen Chung <eric681@andestech.com> (Copyright owned by Andes Technology)
 */

#if !defined(SIMDE_ARM_NEON_ST1_X3_H)
#define SIMDE_ARM_NEON_ST1_X3_H

#include "types.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

#if !defined(SIMDE_BUG_INTEL_857088)

SIMDE_FUNCTION_ATTRIBUTES
void
simde_vst1_f16_x3(simde_float16_t ptr[HEDLEY_ARRAY_PARAM(12)], simde_float16x4x3_t val) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE) && defined(SIMDE_ARM_NEON_FP16)
    vst1_f16_x3(ptr, val);
  #else
    simde_float16x4_private val_[3];
    for (size_t i = 0; i < 3; i++) {
      val_[i] = simde_float16x4_to_private(val.val[i]);
    }
    simde_memcpy(ptr, &val_, sizeof(val_));
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vst1_f16_x3
  #define vst1_f16_x3(a, b) simde_vst1_f16_x3((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
void
simde_vst1_f32_x3(simde_float32 ptr[HEDLEY_ARRAY_PARAM(6)], simde_float32x2x3_t val) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE) && !defined(SIMDE_BUG_GCC_REV_260989)
    vst1_f32_x3(ptr, val);
  #else
    simde_vst1_f32(ptr, val.val[0]);
    simde_vst1_f32(ptr+2, val.val[1]);
    simde_vst1_f32(ptr+4, val.val[2]);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vst1_f32_x3
  #define vst1_f32_x3(ptr, val) simde_vst1_f32_x3((ptr), (val))
#endif

SIMDE_FUNCTION_ATTRIBUTES
void
simde_vst1_f64_x3(simde_float64 ptr[HEDLEY_ARRAY_PARAM(3)], simde_float64x1x3_t val) {
  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
    vst1_f64_x3(ptr, val);
  #else
    simde_vst1_f64(ptr, val.val[0]);
    simde_vst1_f64(ptr+1, val.val[1]);
    simde_vst1_f64(ptr+2, val.val[2]);
  #endif
}
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES)
  #undef vst1_f64_x3
  #define vst1_f64_x3(ptr, val) simde_vst1_f64_x3((ptr), (val))
#endif

SIMDE_FUNCTION_ATTRIBUTES
void
simde_vst1_s8_x3(int8_t ptr[HEDLEY_ARRAY_PARAM(24)], simde_int8x8x3_t val) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE) && !defined(SIMDE_BUG_GCC_REV_260989)
    vst1_s8_x3(ptr, val);
  #else
    simde_vst1_s8(ptr, val.val[0]);
    simde_vst1_s8(ptr+8, val.val[1]);
    simde_vst1_s8(ptr+16, val.val[2]);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vst1_s8_x3
  #define vst1_s8_x3(ptr, val) simde_vst1_s8_x3((ptr), (val))
#endif

SIMDE_FUNCTION_ATTRIBUTES
void
simde_vst1_s16_x3(int16_t ptr[HEDLEY_ARRAY_PARAM(12)], simde_int16x4x3_t val) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE) && !defined(SIMDE_BUG_GCC_REV_260989)
    vst1_s16_x3(ptr, val);
  #else
    simde_vst1_s16(ptr, val.val[0]);
    simde_vst1_s16(ptr+4, val.val[1]);
    simde_vst1_s16(ptr+8, val.val[2]);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vst1_s16_x3
  #define vst1_s16_x3(ptr, val) simde_vst1_s16_x3((ptr), (val))
#endif

SIMDE_FUNCTION_ATTRIBUTES
void
simde_vst1_s32_x3(int32_t ptr[HEDLEY_ARRAY_PARAM(6)], simde_int32x2x3_t val) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE) && !defined(SIMDE_BUG_GCC_REV_260989)
    vst1_s32_x3(ptr, val);
  #else
    simde_vst1_s32(ptr, val.val[0]);
    simde_vst1_s32(ptr+2, val.val[1]);
    simde_vst1_s32(ptr+4, val.val[2]);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vst1_s32_x3
  #define vst1_s32_x3(ptr, val) simde_vst1_s32_x3((ptr), (val))
#endif

SIMDE_FUNCTION_ATTRIBUTES
void
simde_vst1_s64_x3(int64_t ptr[HEDLEY_ARRAY_PARAM(3)], simde_int64x1x3_t val) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE) && !defined(SIMDE_BUG_GCC_REV_260989)
    vst1_s64_x3(ptr, val);
  #else
    simde_vst1_s64(ptr, val.val[0]);
    simde_vst1_s64(ptr+1, val.val[1]);
    simde_vst1_s64(ptr+2, val.val[2]);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vst1_s64_x3
  #define vst1_s64_x3(ptr, val) simde_vst1_s64_x3((ptr), (val))
#endif

SIMDE_FUNCTION_ATTRIBUTES
void
simde_vst1_u8_x3(uint8_t ptr[HEDLEY_ARRAY_PARAM(24)], simde_uint8x8x3_t val) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE) && !defined(SIMDE_BUG_GCC_REV_260989)
    vst1_u8_x3(ptr, val);
  #else
    simde_vst1_u8(ptr, val.val[0]);
    simde_vst1_u8(ptr+8, val.val[1]);
    simde_vst1_u8(ptr+16, val.val[2]);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vst1_u8_x3
  #define vst1_u8_x3(ptr, val) simde_vst1_u8_x3((ptr), (val))
#endif

SIMDE_FUNCTION_ATTRIBUTES
void
simde_vst1_u16_x3(uint16_t ptr[HEDLEY_ARRAY_PARAM(12)], simde_uint16x4x3_t val) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE) && !defined(SIMDE_BUG_GCC_REV_260989)
    vst1_u16_x3(ptr, val);
  #else
    simde_vst1_u16(ptr, val.val[0]);
    simde_vst1_u16(ptr+4, val.val[1]);
    simde_vst1_u16(ptr+8, val.val[2]);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vst1_u16_x3
  #define vst1_u16_x3(ptr, val) simde_vst1_u16_x3((ptr), (val))
#endif

SIMDE_FUNCTION_ATTRIBUTES
void
simde_vst1_u32_x3(uint32_t ptr[HEDLEY_ARRAY_PARAM(6)], simde_uint32x2x3_t val) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE) && !defined(SIMDE_BUG_GCC_REV_260989)
    vst1_u32_x3(ptr, val);
  #else
    simde_vst1_u32(ptr, val.val[0]);
    simde_vst1_u32(ptr+2, val.val[1]);
    simde_vst1_u32(ptr+4, val.val[2]);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vst1_u32_x3
  #define vst1_u32_x3(ptr, val) simde_vst1_u32_x3((ptr), (val))
#endif

SIMDE_FUNCTION_ATTRIBUTES
void
simde_vst1_u64_x3(uint64_t ptr[HEDLEY_ARRAY_PARAM(3)], simde_uint64x1x3_t val) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE) && !defined(SIMDE_BUG_GCC_REV_260989)
    vst1_u64_x3(ptr, val);
  #else
    simde_vst1_u64(ptr, val.val[0]);
    simde_vst1_u64(ptr+1, val.val[1]);
    simde_vst1_u64(ptr+2, val.val[2]);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vst1_u64_x3
  #define vst1_u64_x3(ptr, val) simde_vst1_u64_x3((ptr), (val))
#endif

#endif /* !defined(SIMDE_BUG_INTEL_857088) */

SIMDE_END_DECLS_
HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_ARM_NEON_ST1_X3_H) */
