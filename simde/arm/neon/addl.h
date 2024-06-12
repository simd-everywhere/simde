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
 *   2020      Sean Maher <seanptmaher@gmail.com> (Copyright owned by Google, LLC)
 *   2023      Ju-Hung Li <jhlee@pllab.cs.nthu.edu.tw> (Copyright owned by NTHU pllab)
 */

#if !defined(SIMDE_ARM_NEON_ADDL_H)
#define SIMDE_ARM_NEON_ADDL_H

#include "add.h"
#include "movl.h"
#include "movl_high.h"
#include "types.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

SIMDE_FUNCTION_ATTRIBUTES
simde_int16x8_t
simde_vaddl_s8(simde_int8x8_t a, simde_int8x8_t b) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vaddl_s8(a, b);
  #elif defined(SIMDE_RISCV_V_NATIVE)
    simde_int16x8_private r_;
    simde_int8x8_private a_ = simde_int8x8_to_private(a);
    simde_int8x8_private b_ = simde_int8x8_to_private(b);

    r_.sv128 = __riscv_vwadd_vv_i16m1(__riscv_vlmul_trunc_v_i8m1_i8mf2(a_.sv64) , __riscv_vlmul_trunc_v_i8m1_i8mf2(b_.sv64) , 8);
    return simde_int16x8_from_private(r_);
  #else
    return simde_vaddq_s16(simde_vmovl_s8(a), simde_vmovl_s8(b));
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vaddl_s8
  #define vaddl_s8(a, b) simde_vaddl_s8((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_int32x4_t
simde_vaddl_s16(simde_int16x4_t a, simde_int16x4_t b) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vaddl_s16(a, b);
  #elif defined(SIMDE_RISCV_V_NATIVE)
    simde_int32x4_private r_;
    simde_int16x4_private a_ = simde_int16x4_to_private(a);
    simde_int16x4_private b_ = simde_int16x4_to_private(b);

    r_.sv128 = __riscv_vwadd_vv_i32m1(__riscv_vlmul_trunc_v_i16m1_i16mf2(a_.sv64) , __riscv_vlmul_trunc_v_i16m1_i16mf2(b_.sv64) , 4);
    return simde_int32x4_from_private(r_);
  #else
    return simde_vaddq_s32(simde_vmovl_s16(a), simde_vmovl_s16(b));
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vaddl_s16
  #define vaddl_s16(a, b) simde_vaddl_s16((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_int64x2_t
simde_vaddl_s32(simde_int32x2_t a, simde_int32x2_t b) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vaddl_s32(a, b);
  #elif defined(SIMDE_RISCV_V_NATIVE)
    simde_int64x2_private r_;
    simde_int32x2_private a_ = simde_int32x2_to_private(a);
    simde_int32x2_private b_ = simde_int32x2_to_private(b);

    r_.sv128 = __riscv_vwadd_vv_i64m1(__riscv_vlmul_trunc_v_i32m1_i32mf2(a_.sv64) , __riscv_vlmul_trunc_v_i32m1_i32mf2(b_.sv64) , 2);
    return simde_int64x2_from_private(r_);
  #else
    return simde_vaddq_s64(simde_vmovl_s32(a), simde_vmovl_s32(b));
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vaddl_s32
  #define vaddl_s32(a, b) simde_vaddl_s32((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint16x8_t
simde_vaddl_u8(simde_uint8x8_t a, simde_uint8x8_t b) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vaddl_u8(a, b);
  #elif defined(SIMDE_RISCV_V_NATIVE)
    simde_uint16x8_private r_;
    simde_uint8x8_private a_ = simde_uint8x8_to_private(a);
    simde_uint8x8_private b_ = simde_uint8x8_to_private(b);

    r_.sv128 = __riscv_vwaddu_vv_u16m1(__riscv_vlmul_trunc_v_u8m1_u8mf2 (a_.sv64) , __riscv_vlmul_trunc_v_u8m1_u8mf2 (b_.sv64) , 8);
    return simde_uint16x8_from_private(r_);
  #else
    return simde_vaddq_u16(simde_vmovl_u8(a), simde_vmovl_u8(b));
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vaddl_u8
  #define vaddl_u8(a, b) simde_vaddl_u8((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint32x4_t
simde_vaddl_u16(simde_uint16x4_t a, simde_uint16x4_t b) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vaddl_u16(a, b);
  #elif defined(SIMDE_RISCV_V_NATIVE)
    simde_uint32x4_private r_;
    simde_uint16x4_private a_ = simde_uint16x4_to_private(a);
    simde_uint16x4_private b_ = simde_uint16x4_to_private(b);

    r_.sv128 = __riscv_vwaddu_vv_u32m1(__riscv_vlmul_trunc_v_u16m1_u16mf2 (a_.sv64) , __riscv_vlmul_trunc_v_u16m1_u16mf2 (b_.sv64) , 4);
    return simde_uint32x4_from_private(r_);
  #else
    return simde_vaddq_u32(simde_vmovl_u16(a), simde_vmovl_u16(b));
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vaddl_u16
  #define vaddl_u16(a, b) simde_vaddl_u16((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint64x2_t
simde_vaddl_u32(simde_uint32x2_t a, simde_uint32x2_t b) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vaddl_u32(a, b);
  #elif defined(SIMDE_RISCV_V_NATIVE)
    simde_uint64x2_private r_;
    simde_uint32x2_private a_ = simde_uint32x2_to_private(a);
    simde_uint32x2_private b_ = simde_uint32x2_to_private(b);

    r_.sv128 = __riscv_vwaddu_vv_u64m1(__riscv_vlmul_trunc_v_u32m1_u32mf2 (a_.sv64) , __riscv_vlmul_trunc_v_u32m1_u32mf2 (b_.sv64) , 4);
    return simde_uint64x2_from_private(r_);
  #else
    return simde_vaddq_u64(simde_vmovl_u32(a), simde_vmovl_u32(b));
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vaddl_u32
  #define vaddl_u32(a, b) simde_vaddl_u32((a), (b))
#endif

SIMDE_END_DECLS_
HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_ARM_NEON_ADDL_H) */
