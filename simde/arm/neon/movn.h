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
 *   2023      Chi-Wei Chu <wewe5215@gapp.nthu.edu.tw> (Copyright owned by NTHU pllab)
 */

#if !defined(SIMDE_ARM_NEON_MOVN_H)
#define SIMDE_ARM_NEON_MOVN_H

#include "types.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

SIMDE_FUNCTION_ATTRIBUTES
simde_int8x8_t
simde_vmovn_s16(simde_int16x8_t a) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vmovn_s16(a);
  #else
    simde_int8x8_private r_;
    simde_int16x8_private a_ = simde_int16x8_to_private(a);

    #if defined(SIMDE_RISCV_V_NATIVE)
      r_.sv64 = __riscv_vlmul_ext_v_i8mf2_i8m1(__riscv_vncvt_x_x_w_i8mf2(a_.sv128, 8));
    #elif defined(SIMDE_CONVERT_VECTOR_)
      SIMDE_CONVERT_VECTOR_(r_.values, a_.values);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
        r_.values[i] = HEDLEY_STATIC_CAST(int8_t, a_.values[i]);
      }
    #endif

    return simde_int8x8_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vmovn_s16
  #define vmovn_s16(a) simde_vmovn_s16((a))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_int16x4_t
simde_vmovn_s32(simde_int32x4_t a) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vmovn_s32(a);
  #else
    simde_int16x4_private r_;
    simde_int32x4_private a_ = simde_int32x4_to_private(a);

    #if defined(SIMDE_RISCV_V_NATIVE)
      r_.sv64 = __riscv_vlmul_ext_v_i16mf2_i16m1(__riscv_vncvt_x_x_w_i16mf2(a_.sv128, 4));
    #elif defined(SIMDE_CONVERT_VECTOR_)
      SIMDE_CONVERT_VECTOR_(r_.values, a_.values);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
        r_.values[i] = HEDLEY_STATIC_CAST(int16_t, a_.values[i]);
      }
    #endif

    return simde_int16x4_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vmovn_s32
  #define vmovn_s32(a) simde_vmovn_s32((a))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_int32x2_t
simde_vmovn_s64(simde_int64x2_t a) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vmovn_s64(a);
  #else
    simde_int32x2_private r_;
    simde_int64x2_private a_ = simde_int64x2_to_private(a);

    #if defined(SIMDE_RISCV_V_NATIVE)
      r_.sv64 = __riscv_vlmul_ext_v_i32mf2_i32m1(__riscv_vncvt_x_x_w_i32mf2(a_.sv128, 2));
    #elif defined(SIMDE_CONVERT_VECTOR_)
      SIMDE_CONVERT_VECTOR_(r_.values, a_.values);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
        r_.values[i] = HEDLEY_STATIC_CAST(int32_t, a_.values[i]);
      }
    #endif

    return simde_int32x2_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vmovn_s64
  #define vmovn_s64(a) simde_vmovn_s64((a))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint8x8_t
simde_vmovn_u16(simde_uint16x8_t a) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vmovn_u16(a);
  #else
    simde_uint8x8_private r_;
    simde_uint16x8_private a_ = simde_uint16x8_to_private(a);

    #if defined(SIMDE_RISCV_V_NATIVE)
      r_.sv64 = __riscv_vlmul_ext_v_u8mf2_u8m1(__riscv_vncvt_x_x_w_u8mf2(a_.sv128, 8));
    #elif defined(SIMDE_CONVERT_VECTOR_)
      SIMDE_CONVERT_VECTOR_(r_.values, a_.values);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
        r_.values[i] = HEDLEY_STATIC_CAST(uint8_t, a_.values[i]);
      }
    #endif

    return simde_uint8x8_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vmovn_u16
  #define vmovn_u16(a) simde_vmovn_u16((a))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint16x4_t
simde_vmovn_u32(simde_uint32x4_t a) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vmovn_u32(a);
  #else
    simde_uint16x4_private r_;
    simde_uint32x4_private a_ = simde_uint32x4_to_private(a);

    #if defined(SIMDE_RISCV_V_NATIVE)
      r_.sv64 = __riscv_vlmul_ext_v_u16mf2_u16m1(__riscv_vncvt_x_x_w_u16mf2(a_.sv128, 4));
    #elif defined(SIMDE_CONVERT_VECTOR_)
      SIMDE_CONVERT_VECTOR_(r_.values, a_.values);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
        r_.values[i] = HEDLEY_STATIC_CAST(uint16_t, a_.values[i]);
      }
    #endif

    return simde_uint16x4_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vmovn_u32
  #define vmovn_u32(a) simde_vmovn_u32((a))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint32x2_t
simde_vmovn_u64(simde_uint64x2_t a) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vmovn_u64(a);
  #else
    simde_uint32x2_private r_;
    simde_uint64x2_private a_ = simde_uint64x2_to_private(a);

    #if defined(SIMDE_RISCV_V_NATIVE)
      r_.sv64 = __riscv_vlmul_ext_v_u32mf2_u32m1(__riscv_vncvt_x_x_w_u32mf2(a_.sv128, 2));
    #elif defined(SIMDE_CONVERT_VECTOR_)
      SIMDE_CONVERT_VECTOR_(r_.values, a_.values);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
        r_.values[i] = HEDLEY_STATIC_CAST(uint32_t, a_.values[i]);
      }
    #endif

    return simde_uint32x2_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vmovn_u64
  #define vmovn_u64(a) simde_vmovn_u64((a))
#endif

SIMDE_END_DECLS_
HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_ARM_NEON_MOVN_H) */
