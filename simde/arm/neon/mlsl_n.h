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
 *   2023      Ju-Hung Li <jhlee@pllab.cs.nthu.edu.tw> (Copyright owned by NTHU pllab)
 */

#if !defined(SIMDE_ARM_NEON_MLSL_N_H)
#define SIMDE_ARM_NEON_MLSL_N_H

#include "mull_n.h"
#include "sub.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

SIMDE_FUNCTION_ATTRIBUTES
simde_int32x4_t
simde_vmlsl_n_s16(simde_int32x4_t a, simde_int16x4_t b, int16_t c) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vmlsl_n_s16(a, b, c);
  #elif defined(SIMDE_RISCV_V_NATIVE)
    simde_int32x4_private r_;
    simde_int32x4_private a_ = simde_int32x4_to_private(a);
    simde_int16x4_private b_ = simde_int16x4_to_private(b);
    vint16mf2_t vb = __riscv_vlmul_trunc_v_i16m1_i16mf2 (b_.sv64);
    r_.sv128 = __riscv_vsub_vv_i32m1(a_.sv128 , __riscv_vwmul_vx_i32m1(vb , c , 4) , 4);
    return simde_int32x4_from_private(r_);
  #else
    return simde_vsubq_s32(a, simde_vmull_n_s16(b, c));
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vmlsl_n_s16
  #define vmlsl_n_s16(a, b, c) simde_vmlsl_n_s16((a), (b), (c))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_int64x2_t
simde_vmlsl_n_s32(simde_int64x2_t a, simde_int32x2_t b, int32_t c) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vmlsl_n_s32(a, b, c);
  #elif defined(SIMDE_RISCV_V_NATIVE)
    simde_int64x2_private r_;
    simde_int64x2_private a_ = simde_int64x2_to_private(a);
    simde_int32x2_private b_ = simde_int32x2_to_private(b);
    vint32mf2_t vb = __riscv_vlmul_trunc_v_i32m1_i32mf2 (b_.sv64);
    r_.sv128 = __riscv_vsub_vv_i64m1(a_.sv128 , __riscv_vwmul_vx_i64m1(vb , c , 2) , 2);
    return simde_int64x2_from_private(r_);
  #else
    return simde_vsubq_s64(a, simde_vmull_n_s32(b, c));
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vmlsl_n_s32
  #define vmlsl_n_s32(a, b, c) simde_vmlsl_n_s32((a), (b), (c))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint32x4_t
simde_vmlsl_n_u16(simde_uint32x4_t a, simde_uint16x4_t b, uint16_t c) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vmlsl_n_u16(a, b, c);
  #elif defined(SIMDE_RISCV_V_NATIVE)
    simde_uint32x4_private r_;
    simde_uint32x4_private a_ = simde_uint32x4_to_private(a);
    simde_uint16x4_private b_ = simde_uint16x4_to_private(b);
    vuint16mf2_t vb = __riscv_vlmul_trunc_v_u16m1_u16mf2 (b_.sv64);
    r_.sv128 = __riscv_vsub_vv_u32m1(a_.sv128 , __riscv_vwmulu_vx_u32m1(vb , c , 4) , 4);
    return simde_uint32x4_from_private(r_);
  #else
    return simde_vsubq_u32(a, simde_vmull_n_u16(b, c));
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vmlsl_n_u16
  #define vmlsl_n_u16(a, b, c) simde_vmlsl_n_u16((a), (b), (c))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint64x2_t
simde_vmlsl_n_u32(simde_uint64x2_t a, simde_uint32x2_t b, uint32_t c) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vmlsl_n_u32(a, b, c);
  #elif defined(SIMDE_RISCV_V_NATIVE)
    simde_uint64x2_private r_;
    simde_uint64x2_private a_ = simde_uint64x2_to_private(a);
    simde_uint32x2_private b_ = simde_uint32x2_to_private(b);
    vuint32mf2_t vb = __riscv_vlmul_trunc_v_u32m1_u32mf2 (b_.sv64);
    r_.sv128 = __riscv_vsub_vv_u64m1(a_.sv128 , __riscv_vwmulu_vx_u64m1(vb , c , 2) , 2);
    return simde_uint64x2_from_private(r_);
  #else
    return simde_vsubq_u64(a, simde_vmull_n_u32(b, c));
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vmlsl_n_u32
  #define vmlsl_n_u32(a, b, c) simde_vmlsl_n_u32((a), (b), (c))
#endif

SIMDE_END_DECLS_
HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_ARM_NEON_MLSL_N_H) */
