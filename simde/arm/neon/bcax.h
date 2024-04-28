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
 *   2021      Atharva Nimbalkar <atharvakn@gmail.com>
 *   2023      Chi-Wei Chu <wewe5215@gapp.nthu.edu.tw> (Copyright owned by NTHU pllab)
 */

#if !defined(SIMDE_ARM_NEON_BCAX_H)
#define SIMDE_ARM_NEON_BCAX_H

#include "types.h"

#include "eor.h"
#include "bic.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

SIMDE_FUNCTION_ATTRIBUTES
simde_uint8x16_t
simde_vbcaxq_u8(simde_uint8x16_t a, simde_uint8x16_t b, simde_uint8x16_t c) {
  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE) && defined(SIMDE_ARCH_ARM_SHA3)
    return vbcaxq_u8(a, b, c);
  #elif defined(SIMDE_RISCV_V_NATIVE)
    simde_uint8x16_private
      r_,
      a_ = simde_uint8x16_to_private(a),
      b_ = simde_uint8x16_to_private(b),
      c_ = simde_uint8x16_to_private(c);
    r_.sv128 = __riscv_vxor_vv_u8m1(a_.sv128, __riscv_vand_vv_u8m1(b_.sv128 , \
      __riscv_vnot_v_u8m1(c_.sv128 , 16), 16), 16);
    return simde_uint8x16_from_private(r_);
  #else
    return simde_veorq_u8(a, simde_vbicq_u8(b, c));
  #endif
}
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES) || (defined(SIMDE_ENABLE_NATIVE_ALIASES) && !defined(SIMDE_ARCH_ARM_SHA3))
  #undef vbcaxq_u8
  #define vbcaxq_u8(a, b, c) simde_vbcaxq_u8(a, b, c)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint16x8_t
simde_vbcaxq_u16(simde_uint16x8_t a, simde_uint16x8_t b, simde_uint16x8_t c) {
  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE) && defined(SIMDE_ARCH_ARM_SHA3)
    return vbcaxq_u16(a, b, c);
  #elif defined(SIMDE_RISCV_V_NATIVE)
    simde_uint16x8_private
      r_,
      a_ = simde_uint16x8_to_private(a),
      b_ = simde_uint16x8_to_private(b),
      c_ = simde_uint16x8_to_private(c);
    r_.sv128 = __riscv_vxor_vv_u16m1(a_.sv128, __riscv_vand_vv_u16m1(b_.sv128 , \
      __riscv_vnot_v_u16m1(c_.sv128 , 8), 8), 8);
    return simde_uint16x8_from_private(r_);
  #else
    return simde_veorq_u16(a, simde_vbicq_u16(b, c));
  #endif
}
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES) || (defined(SIMDE_ENABLE_NATIVE_ALIASES) && !defined(SIMDE_ARCH_ARM_SHA3))
  #undef vbcaxq_u16
  #define vbcaxq_u16(a, b, c) simde_vbcaxq_u16(a, b, c)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint32x4_t
simde_vbcaxq_u32(simde_uint32x4_t a, simde_uint32x4_t b, simde_uint32x4_t c) {
  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE) && defined(SIMDE_ARCH_ARM_SHA3)
    return vbcaxq_u32(a, b, c);
  #elif defined(SIMDE_RISCV_V_NATIVE)
    simde_uint32x4_private
      r_,
      a_ = simde_uint32x4_to_private(a),
      b_ = simde_uint32x4_to_private(b),
      c_ = simde_uint32x4_to_private(c);
    r_.sv128 = __riscv_vxor_vv_u32m1(a_.sv128, __riscv_vand_vv_u32m1(b_.sv128 , \
      __riscv_vnot_v_u32m1(c_.sv128 , 4), 4), 4);
    return simde_uint32x4_from_private(r_);
  #else
    return simde_veorq_u32(a, simde_vbicq_u32(b, c));
  #endif
}
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES) || (defined(SIMDE_ENABLE_NATIVE_ALIASES) && !defined(SIMDE_ARCH_ARM_SHA3))
  #undef vbcaxq_u32
  #define vbcaxq_u32(a, b, c) simde_vbcaxq_u32(a, b, c)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint64x2_t
simde_vbcaxq_u64(simde_uint64x2_t a, simde_uint64x2_t b, simde_uint64x2_t c) {
  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE) && defined(SIMDE_ARCH_ARM_SHA3)
    return vbcaxq_u64(a, b, c);
  #elif defined(SIMDE_RISCV_V_NATIVE)
    simde_uint64x2_private
      r_,
      a_ = simde_uint64x2_to_private(a),
      b_ = simde_uint64x2_to_private(b),
      c_ = simde_uint64x2_to_private(c);
    r_.sv128 = __riscv_vxor_vv_u64m1(a_.sv128, __riscv_vand_vv_u64m1(b_.sv128 , \
      __riscv_vnot_v_u64m1(c_.sv128 , 2), 2), 2);
    return simde_uint64x2_from_private(r_);
  #else
    return simde_veorq_u64(a, simde_vbicq_u64(b, c));
  #endif
}
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES) || (defined(SIMDE_ENABLE_NATIVE_ALIASES) && !defined(SIMDE_ARCH_ARM_SHA3))
  #undef vbcaxq_u64
  #define vbcaxq_u64(a, b, c) simde_vbcaxq_u64(a, b, c)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_int8x16_t
simde_vbcaxq_s8(simde_int8x16_t a, simde_int8x16_t b, simde_int8x16_t c) {
  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE) && defined(SIMDE_ARCH_ARM_SHA3)
    return vbcaxq_s8(a, b, c);
  #elif defined(SIMDE_RISCV_V_NATIVE)
    simde_int8x16_private
      r_,
      a_ = simde_int8x16_to_private(a),
      b_ = simde_int8x16_to_private(b),
      c_ = simde_int8x16_to_private(c);
    r_.sv128 = __riscv_vxor_vv_i8m1(a_.sv128, __riscv_vand_vv_i8m1(b_.sv128 , \
      __riscv_vnot_v_i8m1(c_.sv128 , 16), 16), 16);
    return simde_int8x16_from_private(r_);
  #else
    return simde_veorq_s8(a, simde_vbicq_s8(b, c));
  #endif
}
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES) || (defined(SIMDE_ENABLE_NATIVE_ALIASES) && !defined(SIMDE_ARCH_ARM_SHA3))
  #undef vbcaxq_s8
  #define vbcaxq_s8(a, b, c) simde_vbcaxq_s8(a, b, c)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_int16x8_t
simde_vbcaxq_s16(simde_int16x8_t a, simde_int16x8_t b, simde_int16x8_t c) {
  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE) && defined(SIMDE_ARCH_ARM_SHA3)
    return vbcaxq_s16(a, b, c);
  #elif defined(SIMDE_RISCV_V_NATIVE)
    simde_int16x8_private
      r_,
      a_ = simde_int16x8_to_private(a),
      b_ = simde_int16x8_to_private(b),
      c_ = simde_int16x8_to_private(c);
    r_.sv128 = __riscv_vxor_vv_i16m1(a_.sv128, __riscv_vand_vv_i16m1(b_.sv128 , \
      __riscv_vnot_v_i16m1(c_.sv128 , 8), 8), 8);
    return simde_int16x8_from_private(r_);
  #else
    return simde_veorq_s16(a,simde_vbicq_s16(b, c));
  #endif
}
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES) || (defined(SIMDE_ENABLE_NATIVE_ALIASES) && !defined(SIMDE_ARCH_ARM_SHA3))
  #undef vbcaxq_s16
  #define vbcaxq_s16(a, b, c) simde_vbcaxq_s16(a, b, c)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_int32x4_t
simde_vbcaxq_s32(simde_int32x4_t a, simde_int32x4_t b, simde_int32x4_t c) {
  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE) && defined(SIMDE_ARCH_ARM_SHA3)
    return vbcaxq_s32(a, b, c);
  #elif defined(SIMDE_RISCV_V_NATIVE)
    simde_int32x4_private
      r_,
      a_ = simde_int32x4_to_private(a),
      b_ = simde_int32x4_to_private(b),
      c_ = simde_int32x4_to_private(c);
    r_.sv128 = __riscv_vxor_vv_i32m1(a_.sv128, __riscv_vand_vv_i32m1(b_.sv128 , \
      __riscv_vnot_v_i32m1(c_.sv128 , 4), 4), 4);
    return simde_int32x4_from_private(r_);
  #else
    return simde_veorq_s32(a, simde_vbicq_s32(b, c));
  #endif
}
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES) || (defined(SIMDE_ENABLE_NATIVE_ALIASES) && !defined(SIMDE_ARCH_ARM_SHA3))
  #undef vbcaxq_s32
  #define vbcaxq_s32(a, b, c) simde_vbcaxq_s32(a, b, c)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_int64x2_t
simde_vbcaxq_s64(simde_int64x2_t a, simde_int64x2_t b, simde_int64x2_t c) {
  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE) && defined(SIMDE_ARCH_ARM_SHA3)
    return vbcaxq_s64(a, b, c);
  #elif defined(SIMDE_RISCV_V_NATIVE)
    simde_int64x2_private
      r_,
      a_ = simde_int64x2_to_private(a),
      b_ = simde_int64x2_to_private(b),
      c_ = simde_int64x2_to_private(c);
    r_.sv128 = __riscv_vxor_vv_i64m1(a_.sv128, __riscv_vand_vv_i64m1(b_.sv128 , \
      __riscv_vnot_v_i64m1(c_.sv128 , 2), 2), 2);
    return simde_int64x2_from_private(r_);
  #else
    return simde_veorq_s64(a, simde_vbicq_s64(b, c));
  #endif
}
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES) || (defined(SIMDE_ENABLE_NATIVE_ALIASES) && !defined(SIMDE_ARCH_ARM_SHA3))
  #undef vbcaxq_s64
  #define vbcaxq_s64(a, b, c) simde_vbcaxq_s64(a, b, c)
#endif

SIMDE_END_DECLS_
HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_ARM_NEON_BCAX_H) */
