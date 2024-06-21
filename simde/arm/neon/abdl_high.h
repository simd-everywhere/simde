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
 *   2023      Chi-Wei Chu <wewe5215@gapp.nthu.edu.tw> (Copyright owned by NTHU pllab)
 */

#if !defined(SIMDE_ARM_NEON_ABDL_HIGH_H)
#define SIMDE_ARM_NEON_ABDL_HIGH_H

#include "abdl.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

SIMDE_FUNCTION_ATTRIBUTES
simde_int16x8_t
simde_vabdl_high_s8(simde_int8x16_t a, simde_int8x16_t b) {
  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
    return vabdl_high_s8(a, b);
  #elif defined(SIMDE_RISCV_V_NATIVE)
    simde_int16x8_private r_;
    simde_int8x16_private a_ = simde_int8x16_to_private(a);
    simde_int8x16_private b_ = simde_int8x16_to_private(b);
    vint16m1_t rst = __riscv_vwsub_vv_i16m1(__riscv_vlmul_trunc_v_i8m1_i8mf2(__riscv_vslidedown_vx_i8m1(a_.sv128 , 8 , 16)),
      __riscv_vlmul_trunc_v_i8m1_i8mf2(__riscv_vslidedown_vx_i8m1(b_.sv128 , 8 , 16)) , 8);
    r_.sv128 = __riscv_vmax_vv_i16m1(rst , __riscv_vneg_v_i16m1(rst , 8) , 8);
    return simde_int16x8_from_private(r_);
  #else
    return simde_vabdl_s8(simde_vget_high_s8(a), simde_vget_high_s8(b));
  #endif
}
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES)
  #undef vabdl_high_s8
  #define vabdl_high_s8(a, b) simde_vabdl_high_s8((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_int32x4_t
simde_vabdl_high_s16(simde_int16x8_t a, simde_int16x8_t b) {
  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
    return vabdl_high_s16(a, b);
  #elif defined(SIMDE_RISCV_V_NATIVE)
    simde_int32x4_private r_;
    simde_int16x8_private a_ = simde_int16x8_to_private(a);
    simde_int16x8_private b_ = simde_int16x8_to_private(b);
    vint32m1_t rst = __riscv_vwsub_vv_i32m1(__riscv_vlmul_trunc_v_i16m1_i16mf2(__riscv_vslidedown_vx_i16m1(a_.sv128 , 4 , 8)) , \
      __riscv_vlmul_trunc_v_i16m1_i16mf2(__riscv_vslidedown_vx_i16m1(b_.sv128 , 4 , 8)) , 4);
    r_.sv128 = __riscv_vmax_vv_i32m1(rst , __riscv_vneg_v_i32m1(rst , 4) , 4);
    return simde_int32x4_from_private(r_);
  #else
    return simde_vabdl_s16(simde_vget_high_s16(a), simde_vget_high_s16(b));
  #endif
}
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES)
  #undef vabdl_high_s16
  #define vabdl_high_s16(a, b) simde_vabdl_high_s16((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_int64x2_t
simde_vabdl_high_s32(simde_int32x4_t a, simde_int32x4_t b) {
  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
    return vabdl_high_s32(a, b);
  #elif defined(SIMDE_RISCV_V_NATIVE)
    simde_int64x2_private r_;
    simde_int32x4_private a_ = simde_int32x4_to_private(a);
    simde_int32x4_private b_ = simde_int32x4_to_private(b);
    vint64m1_t rst = __riscv_vwsub_vv_i64m1(__riscv_vlmul_trunc_v_i32m1_i32mf2(__riscv_vslidedown_vx_i32m1(a_.sv128 , 2 , 4)) , \
      __riscv_vlmul_trunc_v_i32m1_i32mf2(__riscv_vslidedown_vx_i32m1(b_.sv128 , 2 , 4)) , 2);
    r_.sv128 = __riscv_vmax_vv_i64m1(rst , __riscv_vneg_v_i64m1(rst , 2) , 2);
    return simde_int64x2_from_private(r_);
  #else
    return simde_vabdl_s32(simde_vget_high_s32(a), simde_vget_high_s32(b));
  #endif
}
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES)
  #undef vabdl_high_s32
  #define vabdl_high_s32(a, b) simde_vabdl_high_s32((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint16x8_t
simde_vabdl_high_u8(simde_uint8x16_t a, simde_uint8x16_t b) {
  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
    return vabdl_high_u8(a, b);
  #elif defined(SIMDE_RISCV_V_NATIVE)
    simde_uint16x8_private r_;
    simde_uint8x16_private a_ = simde_uint8x16_to_private(a);
    simde_uint8x16_private b_ = simde_uint8x16_to_private(b);
    vint16m1_t a_tmp = __riscv_vreinterpret_v_u16m1_i16m1(__riscv_vwcvtu_x_x_v_u16m1( \
      __riscv_vlmul_trunc_v_u8m1_u8mf2(__riscv_vslidedown_vx_u8m1(a_.sv128 , 8 , 16)), 8));
    vint16m1_t b_tmp = __riscv_vreinterpret_v_u16m1_i16m1(__riscv_vwcvtu_x_x_v_u16m1( \
      __riscv_vlmul_trunc_v_u8m1_u8mf2(__riscv_vslidedown_vx_u8m1(b_.sv128 , 8 , 16)), 8));
    vint16m1_t rst = __riscv_vsub_vv_i16m1(a_tmp, b_tmp, 8);
    r_.sv128 = __riscv_vreinterpret_v_i16m1_u16m1(__riscv_vmax_vv_i16m1(rst , __riscv_vneg_v_i16m1(rst , 8) , 8));
    return simde_uint16x8_from_private(r_);
  #else
    return simde_vabdl_u8(simde_vget_high_u8(a), simde_vget_high_u8(b));
  #endif
}
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES)
  #undef vabdl_high_u8
  #define vabdl_high_u8(a, b) simde_vabdl_high_u8((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint32x4_t
simde_vabdl_high_u16(simde_uint16x8_t a, simde_uint16x8_t b) {
  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
    return vabdl_high_u16(a, b);
  #elif defined(SIMDE_RISCV_V_NATIVE)
    simde_uint32x4_private r_;
    simde_uint16x8_private a_ = simde_uint16x8_to_private(a);
    simde_uint16x8_private b_ = simde_uint16x8_to_private(b);
    vint32m1_t a_tmp = __riscv_vreinterpret_v_u32m1_i32m1(__riscv_vwcvtu_x_x_v_u32m1( \
      __riscv_vlmul_trunc_v_u16m1_u16mf2(__riscv_vslidedown_vx_u16m1(a_.sv128 , 4 , 8)), 4));
    vint32m1_t b_tmp = __riscv_vreinterpret_v_u32m1_i32m1(__riscv_vwcvtu_x_x_v_u32m1( \
      __riscv_vlmul_trunc_v_u16m1_u16mf2(__riscv_vslidedown_vx_u16m1(b_.sv128 , 4 , 8)), 4));
    vint32m1_t rst = __riscv_vsub_vv_i32m1(a_tmp, b_tmp, 4);
    r_.sv128 = __riscv_vreinterpret_v_i32m1_u32m1(__riscv_vmax_vv_i32m1(rst , __riscv_vneg_v_i32m1(rst , 4) , 4));
    return simde_uint32x4_from_private(r_);
  #else
    return simde_vabdl_u16(simde_vget_high_u16(a), simde_vget_high_u16(b));
  #endif
}
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES)
  #undef vabdl_high_u16
  #define vabdl_high_u16(a, b) simde_vabdl_high_u16((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint64x2_t
simde_vabdl_high_u32(simde_uint32x4_t a, simde_uint32x4_t b) {
  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
    return vabdl_high_u32(a, b);
  #elif defined(SIMDE_RISCV_V_NATIVE)
    simde_uint64x2_private r_;
    simde_uint32x4_private a_ = simde_uint32x4_to_private(a);
    simde_uint32x4_private b_ = simde_uint32x4_to_private(b);
    vint64m1_t a_tmp = __riscv_vreinterpret_v_u64m1_i64m1(__riscv_vwcvtu_x_x_v_u64m1( \
      __riscv_vlmul_trunc_v_u32m1_u32mf2(__riscv_vslidedown_vx_u32m1(a_.sv128 , 2 , 4)), 2));
    vint64m1_t b_tmp = __riscv_vreinterpret_v_u64m1_i64m1(__riscv_vwcvtu_x_x_v_u64m1( \
      __riscv_vlmul_trunc_v_u32m1_u32mf2(__riscv_vslidedown_vx_u32m1(b_.sv128 , 2 , 4)), 2));
    vint64m1_t rst = __riscv_vsub_vv_i64m1(a_tmp, b_tmp, 4);
    r_.sv128 = __riscv_vreinterpret_v_i64m1_u64m1(__riscv_vmax_vv_i64m1(rst , __riscv_vneg_v_i64m1(rst , 2) , 2));
    return simde_uint64x2_from_private(r_);
  #else
    return simde_vabdl_u32(simde_vget_high_u32(a), simde_vget_high_u32(b));
  #endif
}
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES)
  #undef vabdl_high_u32
  #define vabdl_high_u32(a, b) simde_vabdl_high_u32((a), (b))
#endif

SIMDE_END_DECLS_
HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_ARM_NEON_ABDL_HIGH_H) */
