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
 *   2023      Yi-Yen Chung <eric681@andestech.com> (Copyright owned by Andes Technology)
 *   2023      Ju-Hung Li <jhlee@pllab.cs.nthu.edu.tw> (Copyright owned by NTHU pllab)
 */

#if !defined(SIMDE_ARM_NEON_CLEZ_H)
#define SIMDE_ARM_NEON_CLEZ_H

#include "cle.h"
#include "dup_n.h"
#include "types.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

SIMDE_FUNCTION_ATTRIBUTES
uint64_t
simde_vclezd_s64(int64_t a) {
  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
    return HEDLEY_STATIC_CAST(uint64_t, vclezd_s64(a));
  #else
    return (a <= 0) ? UINT64_MAX : 0;
  #endif
}
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES)
  #undef vclezd_s64
  #define vclezd_s64(a) simde_vclezd_s64(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
uint64_t
simde_vclezd_f64(simde_float64_t a) {
  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
    return HEDLEY_STATIC_CAST(uint64_t, vclezd_f64(a));
  #else
    return (a <= SIMDE_FLOAT64_C(0.0)) ? UINT64_MAX : 0;
  #endif
}
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES)
  #undef vclezd_f64
  #define vclezd_f64(a) simde_vclezd_f64(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
uint32_t
simde_vclezs_f32(simde_float32_t a) {
  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
    return HEDLEY_STATIC_CAST(uint32_t, vclezs_f32(a));
  #else
    return (a <= SIMDE_FLOAT32_C(0.0)) ? UINT32_MAX : 0;
  #endif
}
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES)
  #undef vclezs_f32
  #define vclezs_f32(a) simde_vclezs_f32(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
uint16_t
simde_vclezh_f16(simde_float16_t a) {
  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE) && defined(SIMDE_ARM_NEON_FP16)
    return HEDLEY_STATIC_CAST(uint16_t, vclezh_f16(a));
  #else
    simde_float32_t a_ = simde_float16_to_float32(a);

    return (a_ <= 0.0f) ? UINT16_MAX : 0;
  #endif
}
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES)
  #undef vclezh_f16
  #define vclezh_f16(a) simde_vclezh_f16(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint16x8_t
simde_vclezq_f16(simde_float16x8_t a) {
  #if defined(SIMDE_ARM_NEON_A32V8_NATIVE) && defined(SIMDE_ARM_NEON_FP16)
    return vclezq_f16(a);
  #else
    simde_float16x8_private a_ = simde_float16x8_to_private(a);
    simde_uint16x8_private r_;

    #if defined(SIMDE_RISCV_V_NATIVE) && defined(SIMDE_ARCH_RISCV_ZVFH)
      vbool16_t result = __riscv_vmfle_vf_f16m1_b16(a_.sv128, 0, 8);
      r_.sv128 = __riscv_vmv_v_x_u16m1(0, 8);
      r_.sv128 = __riscv_vmerge_vxm_u16m1(r_.sv128, -1, result, 8);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
        r_.values[i] = simde_vclezh_f16(a_.values[i]);
      }
    #endif

    return simde_uint16x8_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V8_ENABLE_NATIVE_ALIASES)
  #undef vclezq_f16
  #define vclezq_f16(a) simde_vclezq_f16(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint32x4_t
simde_vclezq_f32(simde_float32x4_t a) {
  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
    return vclezq_f32(a);
  #elif SIMDE_NATURAL_VECTOR_SIZE > 0 && !defined(SIMDE_RISCV_V_NATIVE)
    return simde_vcleq_f32(a, simde_vdupq_n_f32(SIMDE_FLOAT32_C(0.0)));
  #else
    simde_float32x4_private a_ = simde_float32x4_to_private(a);
    simde_uint32x4_private r_;

    #if defined(SIMDE_RISCV_V_NATIVE)
      vbool32_t result = __riscv_vmfle_vf_f32m1_b32(a_.sv128, 0, 4);
      r_.sv128 = __riscv_vmv_v_x_u32m1(0, 4);
      r_.sv128 = __riscv_vmerge_vxm_u32m1(r_.sv128, -1, result, 4);
    #elif defined(SIMDE_VECTOR_SUBSCRIPT_SCALAR)
      r_.values = HEDLEY_REINTERPRET_CAST(__typeof__(r_.values), a_.values <= SIMDE_FLOAT32_C(0.0));
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
        r_.values[i] = (a_.values[i] <= SIMDE_FLOAT32_C(0.0)) ? UINT32_MAX : 0;
      }
    #endif

    return simde_uint32x4_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES)
  #undef vclezq_f32
  #define vclezq_f32(a) simde_vclezq_f32(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint64x2_t
simde_vclezq_f64(simde_float64x2_t a) {
  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
    return vclezq_f64(a);
  #elif SIMDE_NATURAL_VECTOR_SIZE > 0 && !defined(SIMDE_RISCV_V_NATIVE)
    return simde_vcleq_f64(a, simde_vdupq_n_f64(SIMDE_FLOAT64_C(0.0)));
  #else
    simde_float64x2_private a_ = simde_float64x2_to_private(a);
    simde_uint64x2_private r_;

    #if defined(SIMDE_RISCV_V_NATIVE)
      vbool64_t result = __riscv_vmfle_vf_f64m1_b64(a_.sv128, 0, 2);
      r_.sv128 = __riscv_vmv_v_x_u64m1(0, 2);
      r_.sv128 = __riscv_vmerge_vxm_u64m1(r_.sv128, -1, result, 2);
    #elif defined(SIMDE_VECTOR_SUBSCRIPT_SCALAR)
      r_.values = HEDLEY_REINTERPRET_CAST(__typeof__(r_.values), a_.values <= SIMDE_FLOAT64_C(0.0));
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
        r_.values[i] = (a_.values[i] <= SIMDE_FLOAT64_C(0.0)) ? UINT64_MAX : 0;
      }
    #endif

    return simde_uint64x2_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES)
  #undef vclezq_f64
  #define vclezq_f64(a) simde_vclezq_f64(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint8x16_t
simde_vclezq_s8(simde_int8x16_t a) {
  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
    return vclezq_s8(a);
  #elif SIMDE_NATURAL_VECTOR_SIZE > 0 && !defined(SIMDE_RISCV_V_NATIVE)
    return simde_vcleq_s8(a, simde_vdupq_n_s8(0));
  #else
    simde_int8x16_private a_ = simde_int8x16_to_private(a);
    simde_uint8x16_private r_;

    #if defined(SIMDE_RISCV_V_NATIVE)
      vbool8_t result = __riscv_vmsle_vx_i8m1_b8(a_.sv128, 0, 16);
      r_.sv128 = __riscv_vmv_v_x_u8m1(0, 16);
      r_.sv128 = __riscv_vmerge_vxm_u8m1(r_.sv128, -1, result, 16);
    #elif defined(SIMDE_VECTOR_SUBSCRIPT_SCALAR)
      r_.values = HEDLEY_REINTERPRET_CAST(__typeof__(r_.values), a_.values <= 0);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
        r_.values[i] = (a_.values[i] <= 0) ? UINT8_MAX : 0;
      }
    #endif

    return simde_uint8x16_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES)
  #undef vclezq_s8
  #define vclezq_s8(a) simde_vclezq_s8(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint16x8_t
simde_vclezq_s16(simde_int16x8_t a) {
  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
    return vclezq_s16(a);
  #elif SIMDE_NATURAL_VECTOR_SIZE > 0 && !defined(SIMDE_RISCV_V_NATIVE)
    return simde_vcleq_s16(a, simde_vdupq_n_s16(0));
  #else
    simde_int16x8_private a_ = simde_int16x8_to_private(a);
    simde_uint16x8_private r_;

    #if defined(SIMDE_RISCV_V_NATIVE)
      vbool16_t result = __riscv_vmsle_vx_i16m1_b16(a_.sv128, 0, 8);
      r_.sv128 = __riscv_vmv_v_x_u16m1(0, 8);
      r_.sv128 = __riscv_vmerge_vxm_u16m1(r_.sv128, -1, result, 8);
    #elif defined(SIMDE_VECTOR_SUBSCRIPT_SCALAR)
      r_.values = HEDLEY_REINTERPRET_CAST(__typeof__(r_.values), a_.values <= 0);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
        r_.values[i] = (a_.values[i] <= 0) ? UINT16_MAX : 0;
      }
    #endif

    return simde_uint16x8_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES)
  #undef vclezq_s16
  #define vclezq_s16(a) simde_vclezq_s16(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint32x4_t
simde_vclezq_s32(simde_int32x4_t a) {
  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
    return vclezq_s32(a);
  #elif SIMDE_NATURAL_VECTOR_SIZE > 0 && !defined(SIMDE_RISCV_V_NATIVE)
    return simde_vcleq_s32(a, simde_vdupq_n_s32(0));
  #else
    simde_int32x4_private a_ = simde_int32x4_to_private(a);
    simde_uint32x4_private r_;

    #if defined(SIMDE_RISCV_V_NATIVE)
      vbool32_t result = __riscv_vmsle_vx_i32m1_b32(a_.sv128, 0, 4);
      r_.sv128 = __riscv_vmv_v_x_u32m1(0, 4);
      r_.sv128 = __riscv_vmerge_vxm_u32m1(r_.sv128, -1, result, 4);
    #elif defined(SIMDE_VECTOR_SUBSCRIPT_SCALAR)
      r_.values = HEDLEY_REINTERPRET_CAST(__typeof__(r_.values), a_.values <= 0);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
        r_.values[i] = (a_.values[i] <= 0) ? UINT32_MAX : 0;
      }
    #endif

    return simde_uint32x4_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES)
  #undef vclezq_s32
  #define vclezq_s32(a) simde_vclezq_s32(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint64x2_t
simde_vclezq_s64(simde_int64x2_t a) {
  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
    return vclezq_s64(a);
  #elif SIMDE_NATURAL_VECTOR_SIZE > 0 && !defined(SIMDE_RISCV_V_NATIVE)
    return simde_vcleq_s64(a, simde_vdupq_n_s64(0));
  #else
    simde_int64x2_private a_ = simde_int64x2_to_private(a);
    simde_uint64x2_private r_;

    #if defined(SIMDE_RISCV_V_NATIVE)
      vbool64_t result = __riscv_vmsle_vx_i64m1_b64(a_.sv128, 0, 2);
      r_.sv128 = __riscv_vmv_v_x_u64m1(0, 2);
      r_.sv128 = __riscv_vmerge_vxm_u64m1(r_.sv128, -1, result, 2);
    #elif defined(SIMDE_VECTOR_SUBSCRIPT_SCALAR)
      r_.values = HEDLEY_REINTERPRET_CAST(__typeof__(r_.values), a_.values <= 0);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
        r_.values[i] = (a_.values[i] <= 0) ? UINT64_MAX : 0;
      }
    #endif

    return simde_uint64x2_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES)
  #undef vclezq_s64
  #define vclezq_s64(a) simde_vclezq_s64(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint16x4_t
simde_vclez_f16(simde_float16x4_t a) {
  #if defined(SIMDE_ARM_NEON_A32V8_NATIVE) && defined(SIMDE_ARM_NEON_FP16)
    return vclez_f16(a);
  #else
    simde_float16x4_private a_ = simde_float16x4_to_private(a);
    simde_uint16x4_private r_;

    #if defined(SIMDE_RISCV_V_NATIVE) && defined(SIMDE_ARCH_RISCV_ZVFH)
      vbool16_t result = __riscv_vmfle_vf_f16m1_b16(a_.sv64, 0, 4);
      r_.sv64 = __riscv_vmv_v_x_u16m1(0, 4);
      r_.sv64 = __riscv_vmerge_vxm_u16m1(r_.sv64, -1, result, 4);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
        r_.values[i] = simde_vclezh_f16(a_.values[i]);
      }
    #endif

    return simde_uint16x4_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V8_ENABLE_NATIVE_ALIASES)
  #undef vclez_f16
  #define vclez_f16(a) simde_vclez_f16(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint32x2_t
simde_vclez_f32(simde_float32x2_t a) {
  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
    return vclez_f32(a);
  #elif SIMDE_NATURAL_VECTOR_SIZE > 0 && !defined(SIMDE_RISCV_V_NATIVE)
    return simde_vcle_f32(a, simde_vdup_n_f32(SIMDE_FLOAT32_C(0.0)));
  #else
    simde_float32x2_private a_ = simde_float32x2_to_private(a);
    simde_uint32x2_private r_;

    #if defined(SIMDE_RISCV_V_NATIVE)
      vbool32_t result = __riscv_vmfle_vf_f32m1_b32(a_.sv64, 0, 2);
      r_.sv64 = __riscv_vmv_v_x_u32m1(0, 2);
      r_.sv64 = __riscv_vmerge_vxm_u32m1(r_.sv64, -1, result, 2);
    #elif defined(SIMDE_VECTOR_SUBSCRIPT_SCALAR) && !defined(SIMDE_BUG_GCC_100762)
      r_.values = HEDLEY_REINTERPRET_CAST(__typeof__(r_.values), a_.values <= SIMDE_FLOAT32_C(0.0));
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
        r_.values[i] = (a_.values[i] <= SIMDE_FLOAT32_C(0.0)) ? UINT32_MAX : 0;
      }
    #endif

    return simde_uint32x2_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES)
  #undef vclez_f32
  #define vclez_f32(a) simde_vclez_f32(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint64x1_t
simde_vclez_f64(simde_float64x1_t a) {
  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
    return vclez_f64(a);
  #elif SIMDE_NATURAL_VECTOR_SIZE > 0 && !defined(SIMDE_RISCV_V_NATIVE)
    return simde_vcle_f64(a, simde_vdup_n_f64(SIMDE_FLOAT64_C(0.0)));
  #else
    simde_float64x1_private a_ = simde_float64x1_to_private(a);
    simde_uint64x1_private r_;

    #if defined(SIMDE_RISCV_V_NATIVE)
      vbool64_t result = __riscv_vmfle_vf_f64m1_b64(a_.sv64, 0, 1);
      r_.sv64 = __riscv_vmv_v_x_u64m1(0, 1);
      r_.sv64 = __riscv_vmerge_vxm_u64m1(r_.sv64, -1, result, 1);
    #elif defined(SIMDE_VECTOR_SUBSCRIPT_SCALAR)
      r_.values =  HEDLEY_REINTERPRET_CAST(__typeof__(r_.values), a_.values <= SIMDE_FLOAT64_C(0.0));
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
        r_.values[i] = (a_.values[i] <= SIMDE_FLOAT64_C(0.0)) ? UINT64_MAX : 0;
      }
    #endif

    return simde_uint64x1_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES)
  #undef vclez_f64
  #define vclez_f64(a) simde_vclez_f64(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint8x8_t
simde_vclez_s8(simde_int8x8_t a) {
  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
    return vclez_s8(a);
  #elif SIMDE_NATURAL_VECTOR_SIZE > 0 && !defined(SIMDE_RISCV_V_NATIVE)
    return simde_vcle_s8(a, simde_vdup_n_s8(0));
  #else
    simde_int8x8_private a_ = simde_int8x8_to_private(a);
    simde_uint8x8_private r_;

    #if defined(SIMDE_RISCV_V_NATIVE)
      vbool8_t result = __riscv_vmsle_vx_i8m1_b8(a_.sv64, 0, 8);
      r_.sv64 = __riscv_vmv_v_x_u8m1(0, 8);
      r_.sv64 = __riscv_vmerge_vxm_u8m1(r_.sv64, -1, result, 8);
    #elif defined(SIMDE_VECTOR_SUBSCRIPT_SCALAR) && !defined(SIMDE_BUG_GCC_100762)
      r_.values = HEDLEY_REINTERPRET_CAST(__typeof__(r_.values), a_.values <= 0);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
        r_.values[i] = (a_.values[i] <= 0) ? UINT8_MAX : 0;
      }
    #endif

    return simde_uint8x8_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES)
  #undef vclez_s8
  #define vclez_s8(a) simde_vclez_s8(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint16x4_t
simde_vclez_s16(simde_int16x4_t a) {
  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
    return vclez_s16(a);
  #elif SIMDE_NATURAL_VECTOR_SIZE > 0 && !defined(SIMDE_RISCV_V_NATIVE)
    return simde_vcle_s16(a, simde_vdup_n_s16(0));
  #else
    simde_int16x4_private a_ = simde_int16x4_to_private(a);
    simde_uint16x4_private r_;

    #if defined(SIMDE_RISCV_V_NATIVE)
      vbool16_t result = __riscv_vmsle_vx_i16m1_b16(a_.sv64, 0, 4);
      r_.sv64 = __riscv_vmv_v_x_u16m1(0, 4);
      r_.sv64 = __riscv_vmerge_vxm_u16m1(r_.sv64, -1, result, 4);
    #elif defined(SIMDE_VECTOR_SUBSCRIPT_SCALAR) && !defined(SIMDE_BUG_GCC_100762)
      r_.values = HEDLEY_REINTERPRET_CAST(__typeof__(r_.values), a_.values <= 0);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
        r_.values[i] = (a_.values[i] <= 0) ? UINT16_MAX : 0;
      }
    #endif

    return simde_uint16x4_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES)
  #undef vclez_s16
  #define vclez_s16(a) simde_vclez_s16(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint32x2_t
simde_vclez_s32(simde_int32x2_t a) {
  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
    return vclez_s32(a);
  #elif SIMDE_NATURAL_VECTOR_SIZE > 0 && !defined(SIMDE_RISCV_V_NATIVE)
    return simde_vcle_s32(a, simde_vdup_n_s32(0));
  #else
    simde_int32x2_private a_ = simde_int32x2_to_private(a);
    simde_uint32x2_private r_;

    #if defined(SIMDE_RISCV_V_NATIVE)
      vbool32_t result = __riscv_vmsle_vx_i32m1_b32(a_.sv64, 0, 2);
      r_.sv64 = __riscv_vmv_v_x_u32m1(0, 2);
      r_.sv64 = __riscv_vmerge_vxm_u32m1(r_.sv64, -1, result, 2);
    #elif defined(SIMDE_VECTOR_SUBSCRIPT_SCALAR) && !defined(SIMDE_BUG_GCC_100762)
      r_.values = HEDLEY_REINTERPRET_CAST(__typeof__(r_.values), a_.values <= 0);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
        r_.values[i] = (a_.values[i] <= 0) ? UINT32_MAX : 0;
      }
    #endif

    return simde_uint32x2_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES)
  #undef vclez_s32
  #define vclez_s32(a) simde_vclez_s32(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint64x1_t
simde_vclez_s64(simde_int64x1_t a) {
  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
    return vclez_s64(a);
  #elif SIMDE_NATURAL_VECTOR_SIZE > 0 && !defined(SIMDE_RISCV_V_NATIVE)
    return simde_vcle_s64(a, simde_vdup_n_s64(0));
  #else
    simde_int64x1_private a_ = simde_int64x1_to_private(a);
    simde_uint64x1_private r_;

    #if defined(SIMDE_RISCV_V_NATIVE)
      vbool64_t result = __riscv_vmsle_vx_i64m1_b64(a_.sv64, 0, 1);
      r_.sv64 = __riscv_vmv_v_x_u64m1(0, 1);
      r_.sv64 = __riscv_vmerge_vxm_u64m1(r_.sv64, -1, result, 1);
    #elif defined(SIMDE_VECTOR_SUBSCRIPT_SCALAR)
      r_.values = HEDLEY_REINTERPRET_CAST(__typeof__(r_.values), a_.values <= 0);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
        r_.values[i] = (a_.values[i] <= 0) ? UINT64_MAX : 0;
      }
    #endif

    return simde_uint64x1_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES)
  #undef vclez_s64
  #define vclez_s64(a) simde_vclez_s64(a)
#endif

SIMDE_END_DECLS_
HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_ARM_NEON_CLEZ_H) */
