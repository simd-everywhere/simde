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

#if !defined(SIMDE_ARM_NEON_ADDW_HIGH_H)
#define SIMDE_ARM_NEON_ADDW_HIGH_H

#include "types.h"
#include "movl_high.h"
#include "add.h"
#include "addw.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

SIMDE_FUNCTION_ATTRIBUTES
simde_int16x8_t
simde_vaddw_high_s8(simde_int16x8_t a, simde_int8x16_t b) {
  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
    return vaddw_high_s8(a, b);
  #elif SIMDE_NATURAL_VECTOR_SIZE_GE(128) && !defined(SIMDE_RISCV_V_NATIVE)
    return simde_vaddq_s16(a, simde_vmovl_high_s8(b));
  #else
    simde_int16x8_private r_;
    simde_int16x8_private a_ = simde_int16x8_to_private(a);
    simde_int8x16_private b_ = simde_int8x16_to_private(b);

    #if defined(SIMDE_RISCV_V_NATIVE)
      vint8mf2_t b_high = __riscv_vlmul_trunc_v_i8m1_i8mf2(__riscv_vslidedown_vx_i8m1(b_.sv128 , 8 , 16));
      r_.sv128 =  __riscv_vwadd_wv_i16m1(a_.sv128, b_high, 8);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
        r_.values[i] = a_.values[i] + b_.values[i + ((sizeof(b_.values) / sizeof(b_.values[0])) / 2)];
      }
    #endif

    return simde_int16x8_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES)
  #undef vaddw_high_s8
  #define vaddw_high_s8(a, b) simde_vaddw_high_s8((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_int32x4_t
simde_vaddw_high_s16(simde_int32x4_t a, simde_int16x8_t b) {
  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
    return vaddw_high_s16(a, b);
  #elif SIMDE_NATURAL_VECTOR_SIZE_GE(128) && !defined(SIMDE_RISCV_V_NATIVE)
    return simde_vaddq_s32(a, simde_vmovl_high_s16(b));
  #else
    simde_int32x4_private r_;
    simde_int32x4_private a_ = simde_int32x4_to_private(a);
    simde_int16x8_private b_ = simde_int16x8_to_private(b);

    #if defined(SIMDE_RISCV_V_NATIVE)
      vint16mf2_t b_high = __riscv_vlmul_trunc_v_i16m1_i16mf2(__riscv_vslidedown_vx_i16m1(b_.sv128 , 4 , 8));
      r_.sv128 =  __riscv_vwadd_wv_i32m1(a_.sv128, b_high, 4);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
        r_.values[i] = a_.values[i] + b_.values[i + ((sizeof(b_.values) / sizeof(b_.values[0])) / 2)];
      }
    #endif

    return simde_int32x4_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES)
  #undef vaddw_high_s16
  #define vaddw_high_s16(a, b) simde_vaddw_high_s16((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_int64x2_t
simde_vaddw_high_s32(simde_int64x2_t a, simde_int32x4_t b) {
  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
    return vaddw_high_s32(a, b);
  #elif SIMDE_NATURAL_VECTOR_SIZE_GE(128) && !defined(SIMDE_RISCV_V_NATIVE)
    return simde_vaddq_s64(a, simde_vmovl_high_s32(b));
  #else
    simde_int64x2_private r_;
    simde_int64x2_private a_ = simde_int64x2_to_private(a);
    simde_int32x4_private b_ = simde_int32x4_to_private(b);
    #if defined(SIMDE_RISCV_V_NATIVE)
      vint32mf2_t b_high = __riscv_vlmul_trunc_v_i32m1_i32mf2(__riscv_vslidedown_vx_i32m1(b_.sv128 , 2 , 4));
      r_.sv128 =  __riscv_vwadd_wv_i64m1(a_.sv128, b_high, 2);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
        r_.values[i] = a_.values[i] + b_.values[i + ((sizeof(b_.values) / sizeof(b_.values[0])) / 2)];
      }
    #endif
    return simde_int64x2_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES)
  #undef vaddw_high_s32
  #define vaddw_high_s32(a, b) simde_vaddw_high_s32((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint16x8_t
simde_vaddw_high_u8(simde_uint16x8_t a, simde_uint8x16_t b) {
  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
    return vaddw_high_u8(a, b);
  #elif SIMDE_NATURAL_VECTOR_SIZE_GE(128) && !defined(SIMDE_RISCV_V_NATIVE)
    return simde_vaddq_u16(a, simde_vmovl_high_u8(b));
  #else
    simde_uint16x8_private r_;
    simde_uint16x8_private a_ = simde_uint16x8_to_private(a);
    simde_uint8x16_private b_ = simde_uint8x16_to_private(b);
    #if defined(SIMDE_RISCV_V_NATIVE)
      vuint8mf2_t b_high = __riscv_vlmul_trunc_v_u8m1_u8mf2(__riscv_vslidedown_vx_u8m1(b_.sv128 , 8 , 16));
      r_.sv128 =  __riscv_vwaddu_wv_u16m1(a_.sv128, b_high, 8);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
        r_.values[i] = a_.values[i] + b_.values[i + ((sizeof(b_.values) / sizeof(b_.values[0])) / 2)];
      }
    #endif
    return simde_uint16x8_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES)
  #undef vaddw_high_u8
  #define vaddw_high_u8(a, b) simde_vaddw_high_u8((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint32x4_t
simde_vaddw_high_u16(simde_uint32x4_t a, simde_uint16x8_t b) {
  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
    return vaddw_high_u16(a, b);
  #elif SIMDE_NATURAL_VECTOR_SIZE_GE(128) && !defined(SIMDE_RISCV_V_NATIVE)
    return simde_vaddq_u32(a, simde_vmovl_high_u16(b));
  #else
    simde_uint32x4_private r_;
    simde_uint32x4_private a_ = simde_uint32x4_to_private(a);
    simde_uint16x8_private b_ = simde_uint16x8_to_private(b);
    #if defined(SIMDE_RISCV_V_NATIVE)
      vuint16mf2_t b_high = __riscv_vlmul_trunc_v_u16m1_u16mf2(__riscv_vslidedown_vx_u16m1(b_.sv128 , 4 , 8));
      r_.sv128 =  __riscv_vwaddu_wv_u32m1(a_.sv128, b_high, 4);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
        r_.values[i] = a_.values[i] + b_.values[i + ((sizeof(b_.values) / sizeof(b_.values[0])) / 2)];
      }
    #endif
    return simde_uint32x4_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES)
  #undef vaddw_high_u16
  #define vaddw_high_u16(a, b) simde_vaddw_high_u16((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint64x2_t
simde_vaddw_high_u32(simde_uint64x2_t a, simde_uint32x4_t b) {
  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
    return vaddw_high_u32(a, b);
  #elif SIMDE_NATURAL_VECTOR_SIZE_GE(128) && !defined(SIMDE_RISCV_V_NATIVE)
    return simde_vaddq_u64(a, simde_vmovl_high_u32(b));
  #else
    simde_uint64x2_private r_;
    simde_uint64x2_private a_ = simde_uint64x2_to_private(a);
    simde_uint32x4_private b_ = simde_uint32x4_to_private(b);
    #if defined(SIMDE_RISCV_V_NATIVE)
      vuint32mf2_t b_high = __riscv_vlmul_trunc_v_u32m1_u32mf2(__riscv_vslidedown_vx_u32m1(b_.sv128 , 2 , 4));
      r_.sv128 =  __riscv_vwaddu_wv_u64m1(a_.sv128, b_high, 2);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
        r_.values[i] = a_.values[i] + b_.values[i + ((sizeof(b_.values) / sizeof(b_.values[0])) / 2)];
      }
    #endif
    return simde_uint64x2_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES)
  #undef vaddw_high_u32
  #define vaddw_high_u32(a, b) simde_vaddw_high_u32((a), (b))
#endif

SIMDE_END_DECLS_
HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_ARM_NEON_ADDW_HIGH_H) */
