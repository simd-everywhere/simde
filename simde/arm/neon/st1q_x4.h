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
 *   2021      Décio Luiz Gazzoni Filho <decio@decpp.net>
 *   2023      Yi-Yen Chung <eric681@andestech.com> (Copyright owned by Andes Technology)
 */

#if !defined(SIMDE_ARM_NEON_ST1Q_X4_H)
#define SIMDE_ARM_NEON_ST1Q_X4_H

#include "types.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

#if !defined(SIMDE_BUG_INTEL_857088)

SIMDE_FUNCTION_ATTRIBUTES
void
simde_vst1q_f16_x4(simde_float16_t ptr[HEDLEY_ARRAY_PARAM(32)], simde_float16x8x4_t val) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE) && defined(SIMDE_ARM_NEON_FP16)
    vst1q_f16_x4(ptr, val);
  #else
    simde_float16x8_private val_[4];
    for (size_t i = 0; i < 4; i++) {
      val_[i] = simde_float16x8_to_private(val.val[i]);
    }
    simde_memcpy(ptr, &val_, sizeof(val_));
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vst1q_f16_x4
  #define vst1q_f16_x4(a, b) simde_vst1q_f16_x4((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
void
simde_vst1q_f32_x4(simde_float32 ptr[HEDLEY_ARRAY_PARAM(16)], simde_float32x4x4_t val) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE) && !defined(SIMDE_BUG_GCC_REV_260989)
    vst1q_f32_x4(ptr, val);
  #else
    simde_vst1q_f32(ptr, val.val[0]);
    simde_vst1q_f32(ptr+4, val.val[1]);
    simde_vst1q_f32(ptr+8, val.val[2]);
    simde_vst1q_f32(ptr+12, val.val[3]);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vst1q_f32_x4
  #define vst1q_f32_x4(ptr, val) simde_vst1q_f32_x4((ptr), (val))
#endif

SIMDE_FUNCTION_ATTRIBUTES
void
simde_vst1q_f64_x4(simde_float64 ptr[HEDLEY_ARRAY_PARAM(8)], simde_float64x2x4_t val) {
  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
    vst1q_f64_x4(ptr, val);
  #else
    simde_vst1q_f64(ptr, val.val[0]);
    simde_vst1q_f64(ptr+2, val.val[1]);
    simde_vst1q_f64(ptr+4, val.val[2]);
    simde_vst1q_f64(ptr+6, val.val[3]);
  #endif
}
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES)
  #undef vst1q_f64_x4
  #define vst1q_f64_x4(ptr, val) simde_vst1q_f64_x4((ptr), (val))
#endif

SIMDE_FUNCTION_ATTRIBUTES
void
simde_vst1q_s8_x4(int8_t ptr[HEDLEY_ARRAY_PARAM(64)], simde_int8x16x4_t val) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE) && !defined(SIMDE_BUG_GCC_REV_260989)
    vst1q_s8_x4(ptr, val);
  #else
    simde_vst1q_s8(ptr, val.val[0]);
    simde_vst1q_s8(ptr+16, val.val[1]);
    simde_vst1q_s8(ptr+32, val.val[2]);
    simde_vst1q_s8(ptr+48, val.val[3]);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vst1q_s8_x4
  #define vst1q_s8_x4(ptr, val) simde_vst1q_s8_x4((ptr), (val))
#endif

SIMDE_FUNCTION_ATTRIBUTES
void
simde_vst1q_s16_x4(int16_t ptr[HEDLEY_ARRAY_PARAM(32)], simde_int16x8x4_t val) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE) && !defined(SIMDE_BUG_GCC_REV_260989)
    vst1q_s16_x4(ptr, val);
  #else
    simde_vst1q_s16(ptr, val.val[0]);
    simde_vst1q_s16(ptr+8, val.val[1]);
    simde_vst1q_s16(ptr+16, val.val[2]);
    simde_vst1q_s16(ptr+24, val.val[3]);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vst1q_s16_x4
  #define vst1q_s16_x4(ptr, val) simde_vst1q_s16_x4((ptr), (val))
#endif

SIMDE_FUNCTION_ATTRIBUTES
void
simde_vst1q_s32_x4(int32_t ptr[HEDLEY_ARRAY_PARAM(16)], simde_int32x4x4_t val) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE) && !defined(SIMDE_BUG_GCC_REV_260989)
    vst1q_s32_x4(ptr, val);
  #else
    simde_vst1q_s32(ptr, val.val[0]);
    simde_vst1q_s32(ptr+4, val.val[1]);
    simde_vst1q_s32(ptr+8, val.val[2]);
    simde_vst1q_s32(ptr+12, val.val[3]);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vst1q_s32_x4
  #define vst1q_s32_x4(ptr, val) simde_vst1q_s32_x4((ptr), (val))
#endif

SIMDE_FUNCTION_ATTRIBUTES
void
simde_vst1q_s64_x4(int64_t ptr[HEDLEY_ARRAY_PARAM(8)], simde_int64x2x4_t val) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE) && !defined(SIMDE_BUG_GCC_REV_260989)
    vst1q_s64_x4(ptr, val);
  #else
    simde_vst1q_s64(ptr, val.val[0]);
    simde_vst1q_s64(ptr+2, val.val[1]);
    simde_vst1q_s64(ptr+4, val.val[2]);
    simde_vst1q_s64(ptr+6, val.val[3]);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vst1q_s64_x4
  #define vst1q_s64_x4(ptr, val) simde_vst1q_s64_x4((ptr), (val))
#endif

SIMDE_FUNCTION_ATTRIBUTES
void
simde_vst1q_u8_x4(uint8_t ptr[HEDLEY_ARRAY_PARAM(64)], simde_uint8x16x4_t val) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE) && !defined(SIMDE_BUG_GCC_REV_260989)
    vst1q_u8_x4(ptr, val);
  #else
    simde_vst1q_u8(ptr, val.val[0]);
    simde_vst1q_u8(ptr+16, val.val[1]);
    simde_vst1q_u8(ptr+32, val.val[2]);
    simde_vst1q_u8(ptr+48, val.val[3]);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vst1q_u8_x4
  #define vst1q_u8_x4(ptr, val) simde_vst1q_u8_x4((ptr), (val))
#endif

SIMDE_FUNCTION_ATTRIBUTES
void
simde_vst1q_u16_x4(uint16_t ptr[HEDLEY_ARRAY_PARAM(32)], simde_uint16x8x4_t val) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE) && !defined(SIMDE_BUG_GCC_REV_260989)
    vst1q_u16_x4(ptr, val);
  #else
    simde_vst1q_u16(ptr, val.val[0]);
    simde_vst1q_u16(ptr+8, val.val[1]);
    simde_vst1q_u16(ptr+16, val.val[2]);
    simde_vst1q_u16(ptr+24, val.val[3]);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vst1q_u16_x4
  #define vst1q_u16_x4(ptr, val) simde_vst1q_u16_x4((ptr), (val))
#endif

SIMDE_FUNCTION_ATTRIBUTES
void
simde_vst1q_u32_x4(uint32_t ptr[HEDLEY_ARRAY_PARAM(16)], simde_uint32x4x4_t val) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE) && !defined(SIMDE_BUG_GCC_REV_260989)
    vst1q_u32_x4(ptr, val);
  #else
    simde_vst1q_u32(ptr, val.val[0]);
    simde_vst1q_u32(ptr+4, val.val[1]);
    simde_vst1q_u32(ptr+8, val.val[2]);
    simde_vst1q_u32(ptr+12, val.val[3]);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vst1q_u32_x4
  #define vst1q_u32_x4(ptr, val) simde_vst1q_u32_x4((ptr), (val))
#endif

SIMDE_FUNCTION_ATTRIBUTES
void
simde_vst1q_u64_x4(uint64_t ptr[HEDLEY_ARRAY_PARAM(8)], simde_uint64x2x4_t val) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE) && !defined(SIMDE_BUG_GCC_REV_260989)
    vst1q_u64_x4(ptr, val);
  #else
    simde_vst1q_u64(ptr, val.val[0]);
    simde_vst1q_u64(ptr+2, val.val[1]);
    simde_vst1q_u64(ptr+4, val.val[2]);
    simde_vst1q_u64(ptr+6, val.val[3]);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vst1q_u64_x4
  #define vst1q_u64_x4(ptr, val) simde_vst1q_u64_x4((ptr), (val))
#endif

SIMDE_FUNCTION_ATTRIBUTES
void
simde_vst1q_p8_x4(simde_poly8_t ptr[HEDLEY_ARRAY_PARAM(64)], simde_poly8x16x4_t val) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE) && \
      (!defined(HEDLEY_GCC_VERSION) || (HEDLEY_GCC_VERSION_CHECK(8,5,0) && defined(SIMDE_ARM_NEON_A64V8_NATIVE)))
    vst1q_p8_x4(ptr, val);
  #else
    simde_poly8x16_private val_[4];
    for (size_t i = 0; i < 4; i++) {
      val_[i] = simde_poly8x16_to_private(val.val[i]);
    }
    simde_memcpy(ptr, &val_, sizeof(val_));
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vst1q_p8_x4
  #define vst1q_p8_x4(a, b) simde_vst1q_p8_x4((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
void
simde_vst1q_p16_x4(simde_poly16_t ptr[HEDLEY_ARRAY_PARAM(32)], simde_poly16x8x4_t val) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE) && \
      (!defined(HEDLEY_GCC_VERSION) || (HEDLEY_GCC_VERSION_CHECK(8,5,0) && defined(SIMDE_ARM_NEON_A64V8_NATIVE)))
    vst1q_p16_x4(ptr, val);
  #else
    simde_poly16x8_private val_[4];
    for (size_t i = 0; i < 4; i++) {
      val_[i] = simde_poly16x8_to_private(val.val[i]);
    }
    simde_memcpy(ptr, &val_, sizeof(val_));
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vst1q_p16_x4
  #define vst1q_p16_x4(a, b) simde_vst1q_p16_x4((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
void
simde_vst1q_p64_x4(simde_poly64_t ptr[HEDLEY_ARRAY_PARAM(8)], simde_poly64x2x4_t val) {
  #if defined(SIMDE_ARM_NEON_A32V8_NATIVE) && \
      (!defined(HEDLEY_GCC_VERSION) || (HEDLEY_GCC_VERSION_CHECK(8,5,0) && defined(SIMDE_ARM_NEON_A64V8_NATIVE)))
    vst1q_p64_x4(ptr, val);
  #else
    simde_poly64x2_private val_[4];
    for (size_t i = 0; i < 4; i++) {
      val_[i] = simde_poly64x2_to_private(val.val[i]);
    }
    simde_memcpy(ptr, &val_, sizeof(val_));
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V8_ENABLE_NATIVE_ALIASES)
  #undef vst1q_p64_x4
  #define vst1q_p64_x4(a, b) simde_vst1q_p64_x4((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
void
simde_vst1q_bf16_x4(simde_bfloat16_t ptr[HEDLEY_ARRAY_PARAM(32)], simde_bfloat16x8x4_t val) {
  #if defined(SIMDE_ARM_NEON_A32V8_NATIVE) && defined(SIMDE_ARM_NEON_BF16)
    vst1q_bf16_x4(ptr, val);
  #else
    simde_bfloat16x8_private val_[4];
    for (size_t i = 0; i < 4; i++) {
      val_[i] = simde_bfloat16x8_to_private(val.val[i]);
    }
    simde_memcpy(ptr, &val_, sizeof(val_));
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V8_ENABLE_NATIVE_ALIASES)
  #undef vst1q_bf16_x4
  #define vst1q_bf16_x4(a, b) simde_vst1q_bf16_x4((a), (b))
#endif

#endif /* !defined(SIMDE_BUG_INTEL_857088) */

SIMDE_END_DECLS_
HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_ARM_NEON_ST1Q_X4_H) */
