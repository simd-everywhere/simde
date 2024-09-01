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
 *   2023      Chi-Wei Chu <wewe5215@gapp.nthu.edu.tw> (Copyright owned by NTHU pllab)
 */

#if !defined(SIMDE_ARM_NEON_SHLL_N_H)
#define SIMDE_ARM_NEON_SHLL_N_H

#include "types.h"

/*
 * The constant range requirements for the shift amount *n* looks strange.
 * The ARM Neon Intrinsics Reference states that for *_s8, 0 << n << 7. This
 * does not match the actual instruction decoding in the ARM Reference manual,
 * which states that the shift amount "must be equal to the source element width
 * in bits" (ARM DDI 0487F.b C7-1959). So for *_s8 instructions, *n* must be 8,
 * for *_s16, it must be 16, and *_s32 must be 32 (similarly for unsigned).
 */

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

SIMDE_FUNCTION_ATTRIBUTES
simde_int16x8_t
simde_vshll_n_s8 (const simde_int8x8_t a, const int n)
    SIMDE_REQUIRE_CONSTANT_RANGE(n, 0, 8) {
  simde_int16x8_private r_;
  simde_int8x8_private a_ = simde_int8x8_to_private(a);
  #if defined(SIMDE_RISCV_V_NATIVE)
    vint16m2_t va_wide = __riscv_vwcvt_x_x_v_i16m2 (a_.sv64, 8);
    vint16m2_t rst = __riscv_vsll_vx_i16m2 (va_wide, n, 8);
    r_.sv128 =  __riscv_vlmul_trunc_v_i16m2_i16m1 (rst);
  #elif defined(SIMDE_WASM_SIMD128_NATIVE)
    v128_t tmp = wasm_i16x8_load8x8(&a_.values);
    r_.v128 = wasm_i16x8_shl(tmp, HEDLEY_STATIC_CAST(uint32_t, n));
  #else
    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
      r_.values[i] = HEDLEY_STATIC_CAST(int16_t, HEDLEY_STATIC_CAST(int16_t, a_.values[i]) << n);
    }
  #endif
  return simde_int16x8_from_private(r_);
}
#if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
  #define simde_vshll_n_s8(a, n) vshll_n_s8((a), (n))
#endif
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vshll_n_s8
  #define vshll_n_s8(a, n) simde_vshll_n_s8((a), (n))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_int32x4_t
simde_vshll_n_s16 (const simde_int16x4_t a, const int n)
    SIMDE_REQUIRE_CONSTANT_RANGE(n, 0, 16) {
  simde_int32x4_private r_;
  simde_int16x4_private a_ = simde_int16x4_to_private(a);
  #if defined(SIMDE_RISCV_V_NATIVE)
    vint32m2_t va_wide = __riscv_vwcvt_x_x_v_i32m2 (a_.sv64, 4);
    vint32m2_t rst = __riscv_vsll_vx_i32m2 (va_wide, n, 4);
    r_.sv128 =  __riscv_vlmul_trunc_v_i32m2_i32m1 (rst);
  #elif defined(SIMDE_WASM_SIMD128_NATIVE)
    v128_t tmp = wasm_i32x4_load16x4(&a_.values);
    r_.v128 = wasm_i32x4_shl(tmp, HEDLEY_STATIC_CAST(uint32_t, n));
  #else
    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
      r_.values[i] = HEDLEY_STATIC_CAST(int32_t, a_.values[i]) << n;
    }
  #endif
  return simde_int32x4_from_private(r_);
}
#if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
  #define simde_vshll_n_s16(a, n) vshll_n_s16((a), (n))
#endif
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vshll_n_s16
  #define vshll_n_s16(a, n) simde_vshll_n_s16((a), (n))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_int64x2_t
simde_vshll_n_s32 (const simde_int32x2_t a, const int n)
    SIMDE_REQUIRE_CONSTANT_RANGE(n, 0, 32) {
  simde_int64x2_private r_;
  simde_int32x2_private a_ = simde_int32x2_to_private(a);
  #if defined(SIMDE_RISCV_V_NATIVE)
    vint64m2_t va_wide = __riscv_vwcvt_x_x_v_i64m2 (a_.sv64, 2);
    vint64m2_t rst = __riscv_vsll_vx_i64m2 (va_wide, n, 2);
    r_.sv128 =  __riscv_vlmul_trunc_v_i64m2_i64m1 (rst);
  #elif defined(SIMDE_WASM_SIMD128_NATIVE)
    v128_t tmp = wasm_i64x2_load32x2(&a_.values);
    r_.v128 = wasm_i64x2_shl(tmp, HEDLEY_STATIC_CAST(uint32_t, n));
  #else
    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
      r_.values[i] = HEDLEY_STATIC_CAST(int64_t, a_.values[i]) << n;
    }
  #endif
  return simde_int64x2_from_private(r_);
}
#if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
  #define simde_vshll_n_s32(a, n) vshll_n_s32((a), (n))
#endif
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vshll_n_s32
  #define vshll_n_s32(a, n) simde_vshll_n_s32((a), (n))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint16x8_t
simde_vshll_n_u8 (const simde_uint8x8_t a, const int n)
    SIMDE_REQUIRE_CONSTANT_RANGE(n, 0, 8) {
  simde_uint16x8_private r_;
  simde_uint8x8_private a_ = simde_uint8x8_to_private(a);
  #if defined(SIMDE_RISCV_V_NATIVE)
    vuint16m2_t va_wide = __riscv_vwcvtu_x_x_v_u16m2 (a_.sv64, 8);
    vuint16m2_t rst = __riscv_vsll_vx_u16m2 (va_wide, n, 8);
    r_.sv128 =  __riscv_vlmul_trunc_v_u16m2_u16m1 (rst);
  #elif defined(SIMDE_WASM_SIMD128_NATIVE)
    v128_t tmp = wasm_u16x8_load8x8(&a_.values);
    r_.v128 = wasm_i16x8_shl(tmp, HEDLEY_STATIC_CAST(uint32_t, n));
  #else
    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
      r_.values[i] = HEDLEY_STATIC_CAST(uint16_t, HEDLEY_STATIC_CAST(uint16_t, a_.values[i]) << n);
    }
  #endif
  return simde_uint16x8_from_private(r_);
}
#if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
  #define simde_vshll_n_u8(a, n) vshll_n_u8((a), (n))
#endif
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vshll_n_u8
  #define vshll_n_u8(a, n) simde_vshll_n_u8((a), (n))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint32x4_t
simde_vshll_n_u16 (const simde_uint16x4_t a, const int n)
    SIMDE_REQUIRE_CONSTANT_RANGE(n, 0, 16) {
  simde_uint32x4_private r_;
  simde_uint16x4_private a_ = simde_uint16x4_to_private(a);
  #if defined(SIMDE_RISCV_V_NATIVE)
    vuint32m2_t va_wide = __riscv_vwcvtu_x_x_v_u32m2 (a_.sv64, 4);
    vuint32m2_t rst = __riscv_vsll_vx_u32m2 (va_wide, n, 4);
    r_.sv128 =  __riscv_vlmul_trunc_v_u32m2_u32m1 (rst);
  #elif defined(SIMDE_WASM_SIMD128_NATIVE)
    v128_t tmp = wasm_u32x4_load16x4(&a_.values);
    r_.v128 = wasm_i32x4_shl(tmp, HEDLEY_STATIC_CAST(uint32_t, n));
  #else
    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
      r_.values[i] = HEDLEY_STATIC_CAST(uint32_t, a_.values[i]) << n;
    }
  #endif
  return simde_uint32x4_from_private(r_);
}
#if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
  #define simde_vshll_n_u16(a, n) vshll_n_u16((a), (n))
#endif
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vshll_n_u16
  #define vshll_n_u16(a, n) simde_vshll_n_u16((a), (n))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint64x2_t
simde_vshll_n_u32 (const simde_uint32x2_t a, const int n)
    SIMDE_REQUIRE_CONSTANT_RANGE(n, 0, 32) {
  simde_uint64x2_private r_;
  simde_uint32x2_private a_ = simde_uint32x2_to_private(a);
  #if defined(SIMDE_RISCV_V_NATIVE)
    vuint64m2_t va_wide = __riscv_vwcvtu_x_x_v_u64m2 (a_.sv64, 2);
    vuint64m2_t rst = __riscv_vsll_vx_u64m2 (va_wide, n, 2);
    r_.sv128 =  __riscv_vlmul_trunc_v_u64m2_u64m1 (rst);
  #elif defined(SIMDE_WASM_SIMD128_NATIVE)
    v128_t tmp = wasm_u64x2_load32x2(&a_.values);
    r_.v128 = wasm_i64x2_shl(tmp, HEDLEY_STATIC_CAST(uint32_t, n));
  #else
    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
      r_.values[i] = HEDLEY_STATIC_CAST(uint64_t, a_.values[i]) << n;
    }
  #endif
  return simde_uint64x2_from_private(r_);
}
#if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
  #define simde_vshll_n_u32(a, n) vshll_n_u32((a), (n))
#endif
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vshll_n_u32
  #define vshll_n_u32(a, n) simde_vshll_n_u32((a), (n))
#endif

SIMDE_END_DECLS_
HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_ARM_NEON_SHLL_N_H) */
