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

#if !defined(SIMDE_ARM_NEON_BIC_H)
#define SIMDE_ARM_NEON_BIC_H

#include "dup_n.h"
#include "types.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

SIMDE_FUNCTION_ATTRIBUTES
simde_int8x8_t
simde_vbic_s8(simde_int8x8_t a, simde_int8x8_t b) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vbic_s8(a, b);
  #else
    simde_int8x8_private
      a_ = simde_int8x8_to_private(a),
      b_ = simde_int8x8_to_private(b),
      r_;

    #if defined(SIMDE_X86_MMX_NATIVE)
      r_.m64 = _mm_andnot_si64(b_.m64, a_.m64);
    #else
      #if defined(SIMDE_RISCV_V_NATIVE)
        r_.sv64 = __riscv_vand_vv_i8m1(a_.sv64 , __riscv_vnot_v_i8m1(b_.sv64 , 8) , 8);
      #else
        for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
          r_.values[i] = a_.values[i] & ~b_.values[i];
        }
      #endif
    #endif

    return simde_int8x8_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vbic_s8
  #define vbic_s8(a, b) simde_vbic_s8((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_int16x4_t
simde_vbic_s16(simde_int16x4_t a, simde_int16x4_t b) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vbic_s16(a, b);
  #else
    simde_int16x4_private
      a_ = simde_int16x4_to_private(a),
      b_ = simde_int16x4_to_private(b),
      r_;

    #if defined(SIMDE_X86_MMX_NATIVE)
      r_.m64 = _mm_andnot_si64(b_.m64, a_.m64);
    #else
      #if defined(SIMDE_RISCV_V_NATIVE)
        r_.sv64 = __riscv_vand_vv_i16m1(a_.sv64 , __riscv_vnot_v_i16m1(b_.sv64 , 4) , 4);
      #else
        for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
          r_.values[i] = a_.values[i] & ~b_.values[i];
        }
      #endif
    #endif

    return simde_int16x4_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vbic_s16
  #define vbic_s16(a, b) simde_vbic_s16((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_int32x2_t
simde_vbic_s32(simde_int32x2_t a, simde_int32x2_t b) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vbic_s32(a, b);
  #else
    simde_int32x2_private
      a_ = simde_int32x2_to_private(a),
      b_ = simde_int32x2_to_private(b),
      r_;

    #if defined(SIMDE_X86_MMX_NATIVE)
      r_.m64 = _mm_andnot_si64(b_.m64, a_.m64);
    #else
      #if defined(SIMDE_RISCV_V_NATIVE)
        r_.sv64 = __riscv_vand_vv_i32m1(a_.sv64 , __riscv_vnot_v_i32m1(b_.sv64 , 2) , 2);
      #else
        for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
          r_.values[i] = a_.values[i] & ~b_.values[i];
        }
      #endif
    #endif

    return simde_int32x2_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vbic_s32
  #define vbic_s32(a, b) simde_vbic_s32((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_int64x1_t
simde_vbic_s64(simde_int64x1_t a, simde_int64x1_t b) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vbic_s64(a, b);
  #else
    simde_int64x1_private
      a_ = simde_int64x1_to_private(a),
      b_ = simde_int64x1_to_private(b),
      r_;

    #if defined(SIMDE_X86_MMX_NATIVE)
      r_.m64 = _mm_andnot_si64(b_.m64, a_.m64);
    #else
      #if defined(SIMDE_RISCV_V_NATIVE)
        r_.sv64 = __riscv_vand_vv_i64m1(a_.sv64 , __riscv_vnot_v_i64m1(b_.sv64 , 1) , 1);
      #else
        for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
          r_.values[i] = a_.values[i] & ~b_.values[i];
        }
      #endif
    #endif

    return simde_int64x1_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vbic_s64
  #define vbic_s64(a, b) simde_vbic_s64((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint8x8_t
simde_vbic_u8(simde_uint8x8_t a, simde_uint8x8_t b) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vbic_u8(a, b);
  #else
    simde_uint8x8_private
      a_ = simde_uint8x8_to_private(a),
      b_ = simde_uint8x8_to_private(b),
      r_;

    #if defined(SIMDE_X86_MMX_NATIVE)
      r_.m64 = _mm_andnot_si64(b_.m64, a_.m64);
    #else
      #if defined(SIMDE_RISCV_V_NATIVE)
        r_.sv64 = __riscv_vand_vv_u8m1(a_.sv64 , __riscv_vnot_v_u8m1(b_.sv64 , 8) , 8);
      #else
        for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
          r_.values[i] = a_.values[i] & ~b_.values[i];
        }
      #endif
    #endif

    return simde_uint8x8_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vbic_u8
  #define vbic_u8(a, b) simde_vbic_u8((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint16x4_t
simde_vbic_u16(simde_uint16x4_t a, simde_uint16x4_t b) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vbic_u16(a, b);
  #else
    simde_uint16x4_private
      a_ = simde_uint16x4_to_private(a),
      b_ = simde_uint16x4_to_private(b),
      r_;

    #if defined(SIMDE_X86_MMX_NATIVE)
      r_.m64 = _mm_andnot_si64(b_.m64, a_.m64);
    #else
      #if defined(SIMDE_RISCV_V_NATIVE)
        r_.sv64 = __riscv_vand_vv_u16m1(a_.sv64 , __riscv_vnot_v_u16m1(b_.sv64 , 4) , 4);
      #else
        for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
          r_.values[i] = a_.values[i] & ~b_.values[i];
        }
      #endif
    #endif

    return simde_uint16x4_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vbic_u16
  #define vbic_u16(a, b) simde_vbic_u16((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint32x2_t
simde_vbic_u32(simde_uint32x2_t a, simde_uint32x2_t b) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vbic_u32(a, b);
  #else
    simde_uint32x2_private
      a_ = simde_uint32x2_to_private(a),
      b_ = simde_uint32x2_to_private(b),
      r_;

    #if defined(SIMDE_X86_MMX_NATIVE)
      r_.m64 = _mm_andnot_si64(b_.m64, a_.m64);
    #else
      #if defined(SIMDE_RISCV_V_NATIVE)
        r_.sv64 = __riscv_vand_vv_u32m1(a_.sv64 , __riscv_vnot_v_u32m1(b_.sv64 , 2) , 2);
      #else
        for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
          r_.values[i] = a_.values[i] & ~b_.values[i];
        }
      #endif
    #endif

    return simde_uint32x2_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vbic_u32
  #define vbic_u32(a, b) simde_vbic_u32((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint64x1_t
simde_vbic_u64(simde_uint64x1_t a, simde_uint64x1_t b) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vbic_u64(a, b);
  #else
    simde_uint64x1_private
      a_ = simde_uint64x1_to_private(a),
      b_ = simde_uint64x1_to_private(b),
      r_;

    #if defined(SIMDE_X86_MMX_NATIVE)
      r_.m64 = _mm_andnot_si64(b_.m64, a_.m64);
    #else
      #if defined(SIMDE_RISCV_V_NATIVE)
        r_.sv64 = __riscv_vand_vv_u64m1(a_.sv64 , __riscv_vnot_v_u64m1(b_.sv64 , 1) , 1);
      #else
        for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
          r_.values[i] = a_.values[i] & ~b_.values[i];
        }
      #endif
    #endif

    return simde_uint64x1_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vbic_u64
  #define vbic_u64(a, b) simde_vbic_u64((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_int8x16_t
simde_vbicq_s8(simde_int8x16_t a, simde_int8x16_t b) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vbicq_s8(a, b);
  #elif defined(SIMDE_POWER_ALTIVEC_P6_NATIVE)
    return vec_andc(a, b);
  #else
    simde_int8x16_private
      a_ = simde_int8x16_to_private(a),
      b_ = simde_int8x16_to_private(b),
      r_;

    #if defined(SIMDE_RISCV_V_NATIVE)
      r_.sv128 = __riscv_vand_vv_i8m1(a_.sv128 , __riscv_vnot_v_i8m1(b_.sv128 , 16) , 16);
    #elif defined(SIMDE_X86_SSE2_NATIVE)
      r_.m128i = _mm_andnot_si128(b_.m128i, a_.m128i);
    #elif defined(SIMDE_WASM_SIMD128_NATIVE)
      r_.v128 = wasm_v128_andnot(a_.v128, b_.v128);
    #else
      for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
        r_.values[i] = a_.values[i] & ~b_.values[i];
      }
    #endif

    return simde_int8x16_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vbicq_s8
  #define vbicq_s8(a, b) simde_vbicq_s8((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_int16x8_t
simde_vbicq_s16(simde_int16x8_t a, simde_int16x8_t b) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vbicq_s16(a, b);
  #elif defined(SIMDE_POWER_ALTIVEC_P6_NATIVE)
    return vec_andc(a, b);
  #else
    simde_int16x8_private
      a_ = simde_int16x8_to_private(a),
      b_ = simde_int16x8_to_private(b),
      r_;

    #if defined(SIMDE_RISCV_V_NATIVE)
      r_.sv128 = __riscv_vand_vv_i16m1(a_.sv128 , __riscv_vnot_v_i16m1(b_.sv128 , 8) , 8);
    #elif defined(SIMDE_X86_SSE2_NATIVE)
      r_.m128i = _mm_andnot_si128(b_.m128i, a_.m128i);
    #elif defined(SIMDE_WASM_SIMD128_NATIVE)
      r_.v128 = wasm_v128_andnot(a_.v128, b_.v128);
    #else
      for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
        r_.values[i] = a_.values[i] & ~b_.values[i];
      }
    #endif

    return simde_int16x8_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vbicq_s16
  #define vbicq_s16(a, b) simde_vbicq_s16((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_int32x4_t
simde_vbicq_s32(simde_int32x4_t a, simde_int32x4_t b) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vbicq_s32(a, b);
  #elif defined(SIMDE_POWER_ALTIVEC_P6_NATIVE)
    return vec_andc(a, b);
  #else
    simde_int32x4_private
      a_ = simde_int32x4_to_private(a),
      b_ = simde_int32x4_to_private(b),
      r_;

    #if defined(SIMDE_RISCV_V_NATIVE)
      r_.sv128 = __riscv_vand_vv_i32m1(a_.sv128 , __riscv_vnot_v_i32m1(b_.sv128 , 4) , 4);
    #elif defined(SIMDE_X86_SSE2_NATIVE)
      r_.m128i = _mm_andnot_si128(b_.m128i, a_.m128i);
    #elif defined(SIMDE_WASM_SIMD128_NATIVE)
      r_.v128 = wasm_v128_andnot(a_.v128, b_.v128);
    #else
      for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
        r_.values[i] = a_.values[i] & ~b_.values[i];
      }
    #endif

    return simde_int32x4_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vbicq_s32
  #define vbicq_s32(a, b) simde_vbicq_s32((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_int64x2_t
simde_vbicq_s64(simde_int64x2_t a, simde_int64x2_t b) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vbicq_s64(a, b);
  #elif defined(SIMDE_POWER_ALTIVEC_P7_NATIVE)
    return vec_andc(a, b);
  #else
    simde_int64x2_private
      a_ = simde_int64x2_to_private(a),
      b_ = simde_int64x2_to_private(b),
      r_;

    #if defined(SIMDE_RISCV_V_NATIVE)
      r_.sv128 = __riscv_vand_vv_i64m1(a_.sv128 , __riscv_vnot_v_i64m1(b_.sv128 , 2) , 2);
    #elif defined(SIMDE_X86_SSE2_NATIVE)
      r_.m128i = _mm_andnot_si128(b_.m128i, a_.m128i);
    #elif defined(SIMDE_WASM_SIMD128_NATIVE)
      r_.v128 = wasm_v128_andnot(a_.v128, b_.v128);
    #else
      for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
        r_.values[i] = a_.values[i] & ~b_.values[i];
      }
    #endif

    return simde_int64x2_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vbicq_s64
  #define vbicq_s64(a, b) simde_vbicq_s64((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint8x16_t
simde_vbicq_u8(simde_uint8x16_t a, simde_uint8x16_t b) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vbicq_u8(a, b);
  #elif defined(SIMDE_POWER_ALTIVEC_P6_NATIVE)
    return vec_andc(a, b);
  #else
    simde_uint8x16_private
      a_ = simde_uint8x16_to_private(a),
      b_ = simde_uint8x16_to_private(b),
      r_;

    #if defined(SIMDE_RISCV_V_NATIVE)
      r_.sv128 = __riscv_vand_vv_u8m1(a_.sv128 , __riscv_vnot_v_u8m1(b_.sv128 , 16) , 16);
    #elif defined(SIMDE_X86_SSE2_NATIVE)
      r_.m128i = _mm_andnot_si128(b_.m128i, a_.m128i);
    #elif defined(SIMDE_WASM_SIMD128_NATIVE)
      r_.v128 = wasm_v128_andnot(a_.v128, b_.v128);
    #else
      for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
        r_.values[i] = a_.values[i] & ~b_.values[i];
      }
    #endif

    return simde_uint8x16_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vbicq_u8
  #define vbicq_u8(a, b) simde_vbicq_u8((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint16x8_t
simde_vbicq_u16(simde_uint16x8_t a, simde_uint16x8_t b) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vbicq_u16(a, b);
  #elif defined(SIMDE_POWER_ALTIVEC_P6_NATIVE)
    return vec_andc(a, b);
  #else
    simde_uint16x8_private
      a_ = simde_uint16x8_to_private(a),
      b_ = simde_uint16x8_to_private(b),
      r_;

    #if defined(SIMDE_RISCV_V_NATIVE)
      r_.sv128 = __riscv_vand_vv_u16m1(a_.sv128 , __riscv_vnot_v_u16m1(b_.sv128 , 8) , 8);
    #elif defined(SIMDE_X86_SSE2_NATIVE)
      r_.m128i = _mm_andnot_si128(b_.m128i, a_.m128i);
    #elif defined(SIMDE_WASM_SIMD128_NATIVE)
      r_.v128 = wasm_v128_andnot(a_.v128, b_.v128);
    #else
      for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
        r_.values[i] = a_.values[i] & ~b_.values[i];
      }
    #endif

    return simde_uint16x8_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vbicq_u16
  #define vbicq_u16(a, b) simde_vbicq_u16((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint32x4_t
simde_vbicq_u32(simde_uint32x4_t a, simde_uint32x4_t b) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vbicq_u32(a, b);
  #elif defined(SIMDE_POWER_ALTIVEC_P6_NATIVE)
    return vec_andc(a, b);
  #else
    simde_uint32x4_private
      a_ = simde_uint32x4_to_private(a),
      b_ = simde_uint32x4_to_private(b),
      r_;

    #if defined(SIMDE_RISCV_V_NATIVE)
      r_.sv128 = __riscv_vand_vv_u32m1(a_.sv128 , __riscv_vnot_v_u32m1(b_.sv128 , 4) , 4);
    #elif defined(SIMDE_X86_SSE2_NATIVE)
      r_.m128i = _mm_andnot_si128(b_.m128i, a_.m128i);
    #elif defined(SIMDE_WASM_SIMD128_NATIVE)
      r_.v128 = wasm_v128_andnot(a_.v128, b_.v128);
    #else
      for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
        r_.values[i] = a_.values[i] & ~b_.values[i];
      }
    #endif

    return simde_uint32x4_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vbicq_u32
  #define vbicq_u32(a, b) simde_vbicq_u32((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint64x2_t
simde_vbicq_u64(simde_uint64x2_t a, simde_uint64x2_t b) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vbicq_u64(a, b);
  #elif defined(SIMDE_POWER_ALTIVEC_P7_NATIVE)
    return vec_andc(a, b);
  #else
    simde_uint64x2_private
      a_ = simde_uint64x2_to_private(a),
      b_ = simde_uint64x2_to_private(b),
      r_;

    #if defined(SIMDE_RISCV_V_NATIVE)
      r_.sv128 = __riscv_vand_vv_u64m1(a_.sv128 , __riscv_vnot_v_u64m1(b_.sv128 , 2) , 2);
    #elif defined(SIMDE_X86_SSE2_NATIVE)
      r_.m128i = _mm_andnot_si128(b_.m128i, a_.m128i);
    #elif defined(SIMDE_WASM_SIMD128_NATIVE)
      r_.v128 = wasm_v128_andnot(a_.v128, b_.v128);
    #else
      for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
        r_.values[i] = a_.values[i] & ~b_.values[i];
      }
    #endif

    return simde_uint64x2_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vbicq_u64
  #define vbicq_u64(a, b) simde_vbicq_u64((a), (b))
#endif

SIMDE_END_DECLS_
HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_ARM_NEON_BIC_H) */
