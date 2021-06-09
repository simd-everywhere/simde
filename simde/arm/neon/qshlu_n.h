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
 */

#if !defined(SIMDE_ARM_NEON_QSHLU_N_H)
#define SIMDE_ARM_NEON_QSHLU_N_H
#include "types.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

SIMDE_FUNCTION_ATTRIBUTES
simde_uint8x8_t
simde_vqshlu_n_s8(simde_int8x8_t a, const int n)
    SIMDE_REQUIRE_CONSTANT_RANGE(n, 0, 7) {
  simde_uint8x8_t result;
  simde_int8x8_private a_ = simde_int8x8_to_private(a);
  simde_uint8x8_private r_;
  #if defined(SIMDE_VECTOR_SUBSCRIPT_SCALAR)
      __typeof__(r_.values) shifted = HEDLEY_REINTERPRET_CAST(__typeof__(r_.values), a_.values) << n;

      __typeof__(r_.values) overflow = HEDLEY_REINTERPRET_CAST(__typeof__(r_.values), (shifted >> n) != HEDLEY_REINTERPRET_CAST(__typeof__(r_.values), a_.values));

      r_.values = (shifted & ~overflow) | overflow;

      r_.values &= HEDLEY_REINTERPRET_CAST(__typeof__(r_.values), (a_.values >= 0));
      result = simde_uint8x8_from_private(r_);
  #else
    #if defined(SIMDE_WASM_SIMD128_NATIVE)
      __typeof__(a_.values) zeros = { 0, };

      simde_int8x16_private
        A, R;
      A.values = __builtin_shufflevector(a_.values, zeros, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);

      v128_t shifted = wasm_i8x16_shl(A.v128, n);
      v128_t overflow = wasm_i8x16_eq(A.v128, wasm_u8x16_shr(shifted, n));
      R.v128 = wasm_v128_bitselect(shifted, wasm_v128_not(wasm_i8x16_splat(0)), overflow);

      R.v128 = wasm_v128_and(wasm_i8x16_gt(A.v128, wasm_i8x16_splat(0)), R.v128);
      a_.values = __builtin_shufflevector(R.values, R.values, 0, 1, 2, 3, 4, 5, 6, 7);
      r_.values = HEDLEY_REINTERPRET_CAST(__typeof__(r_.values), a_.values);
      result = simde_uint8x8_from_private(r_);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
        if(a_.values[i] < 0) {
          r_.values[i] = 0;
          continue;
        }

        r_.values[i] = HEDLEY_STATIC_CAST(uint8_t, a_.values[i] << n);

        if((r_.values[i] >> n) != HEDLEY_STATIC_CAST(uint8_t, a_.values[i])) {
          r_.values[i] = UINT8_MAX;
        }
      }

      result = simde_uint8x8_from_private(r_);
    #endif
  #endif
  return result;
}
#if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
  #define simde_vqshlu_n_s8(a, n) vqshlu_n_s8(a, n)
#endif
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vqshlu_n_s8
  #define vqshlu_n_s8(a, n) simde_vqshlu_n_s8((a), (n))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint16x4_t
simde_vqshlu_n_s16(simde_int16x4_t a, const int n)
    SIMDE_REQUIRE_CONSTANT_RANGE(n, 0, 15) {
  simde_uint16x4_t result;
  simde_int16x4_private a_ = simde_int16x4_to_private(a);
  simde_uint16x4_private r_;
  #if defined(SIMDE_VECTOR_SUBSCRIPT_SCALAR)
      __typeof__(r_.values) shifted = HEDLEY_REINTERPRET_CAST(__typeof__(r_.values), a_.values) << n;

      __typeof__(r_.values) overflow = HEDLEY_REINTERPRET_CAST(__typeof__(r_.values), (shifted >> n) != HEDLEY_REINTERPRET_CAST(__typeof__(r_.values), a_.values));

      r_.values = (shifted & ~overflow) | overflow;

      r_.values &= HEDLEY_REINTERPRET_CAST(__typeof__(r_.values), (a_.values >= 0));
      result = simde_uint16x4_from_private(r_);
  #else
    #if defined(SIMDE_WASM_SIMD128_NATIVE)
      __typeof__(a_.values) zeros = { 0, };

      simde_int16x8_private
        A, R;
      A.values = __builtin_shufflevector(a_.values, zeros, 0, 1, 2, 3, 4, 5, 6, 7);

      v128_t shifted = wasm_i16x8_shl(A.v128, n);
      v128_t overflow = wasm_i16x8_eq(A.v128, wasm_u16x8_shr(shifted, n));
      R.v128 = wasm_v128_bitselect(shifted, wasm_v128_not(wasm_i16x8_splat(0)), overflow);

      R.v128 = wasm_v128_and(wasm_i16x8_gt(A.v128, wasm_i16x8_splat(0)), R.v128);
      a_.values = __builtin_shufflevector(R.values, R.values, 0, 1, 2, 3);
      r_.values = HEDLEY_REINTERPRET_CAST(__typeof__(r_.values), a_.values);
      result = simde_uint16x4_from_private(r_);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
        if(a_.values[i] < 0) {
          r_.values[i] = 0;
          continue;
        }

        r_.values[i] = HEDLEY_STATIC_CAST(uint16_t, a_.values[i] << n);

        if((r_.values[i] >> n) != HEDLEY_STATIC_CAST(uint16_t, a_.values[i])) {
          r_.values[i] = UINT16_MAX;
        }
      }

      result = simde_uint16x4_from_private(r_);
    #endif
  #endif
  return result;
}
#if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
  #define simde_vqshlu_n_s16(a, n) vqshlu_n_s16(a, n)
#endif
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vqshlu_n_s16
  #define vqshlu_n_s16(a, n) simde_vqshlu_n_s16((a), (n))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint32x2_t
simde_vqshlu_n_s32(simde_int32x2_t a, const int n)
    SIMDE_REQUIRE_CONSTANT_RANGE(n, 0, 31) {
  simde_uint32x2_t result;
  simde_int32x2_private a_ = simde_int32x2_to_private(a);
  simde_uint32x2_private r_;
  #if defined(SIMDE_VECTOR_SUBSCRIPT_SCALAR)
      __typeof__(r_.values) shifted = HEDLEY_REINTERPRET_CAST(__typeof__(r_.values), a_.values) << n;

      __typeof__(r_.values) overflow = HEDLEY_REINTERPRET_CAST(__typeof__(r_.values), (shifted >> n) != HEDLEY_REINTERPRET_CAST(__typeof__(r_.values), a_.values));

      r_.values = (shifted & ~overflow) | overflow;

      r_.values &= HEDLEY_REINTERPRET_CAST(__typeof__(r_.values), (a_.values >= 0));
      result = simde_uint32x2_from_private(r_);
  #else
    #if defined(SIMDE_WASM_SIMD128_NATIVE)
      __typeof__(a_.values) zeros = { 0, };

      simde_int32x4_private
        A, R;
      A.values = __builtin_shufflevector(a_.values, zeros, 0, 1, 2, 3);

      v128_t shifted = wasm_i32x4_shl(A.v128, n);
      v128_t overflow = wasm_i32x4_eq(A.v128, wasm_u32x4_shr(shifted, n));
      R.v128 = wasm_v128_bitselect(shifted, wasm_v128_not(wasm_i32x4_splat(0)), overflow);

      R.v128 = wasm_v128_and(wasm_i32x4_gt(A.v128, wasm_i32x4_splat(0)), R.v128);
      a_.values = __builtin_shufflevector(R.values, R.values, 0, 1);
      r_.values = HEDLEY_REINTERPRET_CAST(__typeof__(r_.values), a_.values);
      result = simde_uint32x2_from_private(r_);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
        if(a_.values[i] < 0) {
          r_.values[i] = 0;
          continue;
        }

        r_.values[i] = HEDLEY_STATIC_CAST(uint32_t, a_.values[i] << n);

        if((r_.values[i] >> n) != HEDLEY_STATIC_CAST(uint32_t, a_.values[i])) {
          r_.values[i] = UINT32_MAX;
        }
      }

      result = simde_uint32x2_from_private(r_);
    #endif
  #endif
  return result;
}
#if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
  #define simde_vqshlu_n_s32(a, n) vqshlu_n_s32(a, n)
#endif
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vqshlu_n_s32
  #define vqshlu_n_s32(a, n) simde_vqshlu_n_s32((a), (n))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint64x1_t
simde_vqshlu_n_s64(simde_int64x1_t a, const int n)
    SIMDE_REQUIRE_CONSTANT_RANGE(n, 0, 63) {
  simde_uint64x1_t result;
  simde_int64x1_private a_ = simde_int64x1_to_private(a);
  simde_uint64x1_private r_;
  #if defined(SIMDE_VECTOR_SUBSCRIPT_SCALAR)
      __typeof__(r_.values) shifted = HEDLEY_REINTERPRET_CAST(__typeof__(r_.values), a_.values) << n;

      __typeof__(r_.values) overflow = HEDLEY_REINTERPRET_CAST(__typeof__(r_.values), (shifted >> n) != HEDLEY_REINTERPRET_CAST(__typeof__(r_.values), a_.values));

      r_.values = (shifted & ~overflow) | overflow;

      r_.values &= HEDLEY_REINTERPRET_CAST(__typeof__(r_.values), (a_.values >= 0));
      result = simde_uint64x1_from_private(r_);
  #else
    #if defined(SIMDE_WASM_SIMD128_NATIVE)
      __typeof__(a_.values) zeros = { 0, };

      simde_int64x2_private
        A, R;
      A.values = __builtin_shufflevector(a_.values, zeros, 0, 1);

      v128_t shifted = wasm_i64x2_shl(A.v128, n);
      v128_t overflow = wasm_i64x2_eq(A.v128, wasm_u64x2_shr(shifted, n));
      R.v128 = wasm_v128_bitselect(shifted, wasm_v128_not(wasm_i64x2_splat(0)), overflow);

      R.v128 = wasm_v128_and(wasm_i64x2_gt(A.v128, wasm_i64x2_splat(0)), R.v128);
      a_.values = __builtin_shufflevector(R.values, R.values, 0);
      r_.values = HEDLEY_REINTERPRET_CAST(__typeof__(r_.values), a_.values);
      result = simde_uint64x1_from_private(r_);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
        if(a_.values[i] < 0) {
          r_.values[i] = 0;
          continue;
        }

        r_.values[i] = HEDLEY_STATIC_CAST(uint64_t, a_.values[i] << n);

        if((r_.values[i] >> n) != HEDLEY_STATIC_CAST(uint64_t, a_.values[i])) {
          r_.values[i] = UINT64_MAX;
        }
      }

      result = simde_uint64x1_from_private(r_);
    #endif
  #endif
  return result;
}
#if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
  #define simde_vqshlu_n_s64(a, n) vqshlu_n_s64(a, n)
#endif
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vqshlu_n_s64
  #define vqshlu_n_s64(a, n) simde_vqshlu_n_s64((a), (n))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint8x16_t
simde_vqshluq_n_s8(simde_int8x16_t a, const int n)
    SIMDE_REQUIRE_CONSTANT_RANGE(n, 0, 7) {
  simde_uint8x16_t result;
  simde_int8x16_private a_ = simde_int8x16_to_private(a);
  simde_uint8x16_private r_;
  #if defined(SIMDE_VECTOR_SUBSCRIPT_SCALAR)
      __typeof__(r_.values) shifted = HEDLEY_REINTERPRET_CAST(__typeof__(r_.values), a_.values) << n;

      __typeof__(r_.values) overflow = HEDLEY_REINTERPRET_CAST(__typeof__(r_.values), (shifted >> n) != HEDLEY_REINTERPRET_CAST(__typeof__(r_.values), a_.values));

      r_.values = (shifted & ~overflow) | overflow;

      r_.values &= HEDLEY_REINTERPRET_CAST(__typeof__(r_.values), (a_.values >= 0));
      result = simde_uint8x16_from_private(r_);
  #else
    #if defined(SIMDE_WASM_SIMD128_NATIVE)
      simde_int8x16_private R;

      v128_t shifted = wasm_i8x16_shl(a_.v128, n);
      v128_t overflow = wasm_i8x16_eq(a_.v128, wasm_u8x16_shr(shifted, n));
      R.v128 = wasm_v128_bitselect(shifted, wasm_v128_not(wasm_i8x16_splat(0)), overflow);
      R.v128 = wasm_v128_and(wasm_i8x16_gt(a_.v128, wasm_i8x16_splat(0)), R.v128);

      r_.values = HEDLEY_REINTERPRET_CAST(__typeof__(r_.values), R.values);
      result = simde_uint8x16_from_private(r_);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
        if(a_.values[i] < 0) {
          r_.values[i] = 0;
          continue;
        }

        r_.values[i] = HEDLEY_STATIC_CAST(uint8_t, a_.values[i] << n);

        if((r_.values[i] >> n) != HEDLEY_STATIC_CAST(uint8_t, a_.values[i])) {
          r_.values[i] = UINT8_MAX;
        }
      }

      result = simde_uint8x16_from_private(r_);
    #endif
  #endif
  return result;
}
#if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
  #define simde_vqshluq_n_s8(a, n) vqshluq_n_s8(a, n)
#endif
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vqshluq_n_s8
  #define vqshluq_n_s8(a, n) simde_vqshluq_n_s8((a), (n))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint16x8_t
simde_vqshluq_n_s16(simde_int16x8_t a, const int n)
    SIMDE_REQUIRE_CONSTANT_RANGE(n, 0, 15) {
  simde_uint16x8_t result;
  simde_int16x8_private a_ = simde_int16x8_to_private(a);
  simde_uint16x8_private r_;
  #if defined(SIMDE_VECTOR_SUBSCRIPT_SCALAR)
      __typeof__(r_.values) shifted = HEDLEY_REINTERPRET_CAST(__typeof__(r_.values), a_.values) << n;

      __typeof__(r_.values) overflow = HEDLEY_REINTERPRET_CAST(__typeof__(r_.values), (shifted >> n) != HEDLEY_REINTERPRET_CAST(__typeof__(r_.values), a_.values));

      r_.values = (shifted & ~overflow) | overflow;

      r_.values &= HEDLEY_REINTERPRET_CAST(__typeof__(r_.values), (a_.values >= 0));
      result = simde_uint16x8_from_private(r_);
  #else
    #if defined(SIMDE_WASM_SIMD128_NATIVE)
      simde_int16x8_private R;

      v128_t shifted = wasm_i16x8_shl(a_.v128, n);
      v128_t overflow = wasm_i16x8_eq(a_.v128, wasm_u16x8_shr(shifted, n));
      R.v128 = wasm_v128_bitselect(shifted, wasm_v128_not(wasm_i16x8_splat(0)), overflow);
      R.v128 = wasm_v128_and(wasm_i16x8_gt(a_.v128, wasm_i16x8_splat(0)), R.v128);

      r_.values = HEDLEY_REINTERPRET_CAST(__typeof__(r_.values), R.values);
      result = simde_uint16x8_from_private(r_);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
        if(a_.values[i] < 0) {
          r_.values[i] = 0;
          continue;
        }

        r_.values[i] = HEDLEY_STATIC_CAST(uint16_t, a_.values[i] << n);

        if((r_.values[i] >> n) != HEDLEY_STATIC_CAST(uint16_t, a_.values[i])) {
          r_.values[i] = UINT16_MAX;
        }
      }

      result = simde_uint16x8_from_private(r_);
    #endif
  #endif
  return result;
}
#if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
  #define simde_vqshluq_n_s16(a, n) vqshluq_n_s16(a, n)
#endif
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vqshluq_n_s16
  #define vqshluq_n_s16(a, n) simde_vqshluq_n_s16((a), (n))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint32x4_t
simde_vqshluq_n_s32(simde_int32x4_t a, const int n)
    SIMDE_REQUIRE_CONSTANT_RANGE(n, 0, 31) {
  simde_uint32x4_t result;
  simde_int32x4_private a_ = simde_int32x4_to_private(a);
  simde_uint32x4_private r_;
  #if defined(SIMDE_VECTOR_SUBSCRIPT_SCALAR)
      __typeof__(r_.values) shifted = HEDLEY_REINTERPRET_CAST(__typeof__(r_.values), a_.values) << n;

      __typeof__(r_.values) overflow = HEDLEY_REINTERPRET_CAST(__typeof__(r_.values), (shifted >> n) != HEDLEY_REINTERPRET_CAST(__typeof__(r_.values), a_.values));

      r_.values = (shifted & ~overflow) | overflow;

      r_.values &= HEDLEY_REINTERPRET_CAST(__typeof__(r_.values), (a_.values >= 0));
      result = simde_uint32x4_from_private(r_);
  #else
    #if defined(SIMDE_WASM_SIMD128_NATIVE)
      simde_int32x4_private R;

      v128_t shifted = wasm_i32x4_shl(a_.v128, n);
      v128_t overflow = wasm_i32x4_eq(a_.v128, wasm_u32x4_shr(shifted, n));
      R.v128 = wasm_v128_bitselect(shifted, wasm_v128_not(wasm_i32x4_splat(0)), overflow);
      R.v128 = wasm_v128_and(wasm_i32x4_gt(a_.v128, wasm_i32x4_splat(0)), R.v128);

      r_.values = HEDLEY_REINTERPRET_CAST(__typeof__(r_.values), R.values);
      result = simde_uint32x4_from_private(r_);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
        if(a_.values[i] < 0) {
          r_.values[i] = 0;
          continue;
        }

        r_.values[i] = HEDLEY_STATIC_CAST(uint32_t, a_.values[i] << n);

        if((r_.values[i] >> n) != HEDLEY_STATIC_CAST(uint32_t, a_.values[i])) {
          r_.values[i] = UINT32_MAX;
        }
      }

      result = simde_uint32x4_from_private(r_);
    #endif
  #endif
  return result;
}
#if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
  #define simde_vqshluq_n_s32(a, n) vqshluq_n_s32(a, n)
#endif
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vqshluq_n_s32
  #define vqshluq_n_s32(a, n) simde_vqshluq_n_s32((a), (n))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint64x2_t
simde_vqshluq_n_s64(simde_int64x2_t a, const int n)
    SIMDE_REQUIRE_CONSTANT_RANGE(n, 0, 63) {
  simde_uint64x2_t result;
  simde_int64x2_private a_ = simde_int64x2_to_private(a);
  simde_uint64x2_private r_;
  #if defined(SIMDE_VECTOR_SUBSCRIPT_SCALAR)
      __typeof__(r_.values) shifted = HEDLEY_REINTERPRET_CAST(__typeof__(r_.values), a_.values) << n;

      __typeof__(r_.values) overflow = HEDLEY_REINTERPRET_CAST(__typeof__(r_.values), (shifted >> n) != HEDLEY_REINTERPRET_CAST(__typeof__(r_.values), a_.values));

      r_.values = (shifted & ~overflow) | overflow;

      r_.values &= HEDLEY_REINTERPRET_CAST(__typeof__(r_.values), (a_.values >= 0));
      result = simde_uint64x2_from_private(r_);
  #else
    #if defined(SIMDE_WASM_SIMD128_NATIVE)
      simde_int64x2_private R;

      v128_t shifted = wasm_i64x2_shl(a_.v128, n);
      v128_t overflow = wasm_i64x2_eq(a_.v128, wasm_u64x2_shr(shifted, n));
      R.v128 = wasm_v128_bitselect(shifted, wasm_v128_not(wasm_i64x2_splat(0)), overflow);
      R.v128 = wasm_v128_and(wasm_i64x2_gt(a_.v128, wasm_i64x2_splat(0)), R.v128);

      r_.values = HEDLEY_REINTERPRET_CAST(__typeof__(r_.values), R.values);
      result = simde_uint64x2_from_private(r_);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
        if(a_.values[i] < 0) {
          r_.values[i] = 0;
          continue;
        }

        r_.values[i] = HEDLEY_STATIC_CAST(uint64_t, a_.values[i] << n);

        if((r_.values[i] >> n) != HEDLEY_STATIC_CAST(uint64_t, a_.values[i])) {
          r_.values[i] = UINT64_MAX;
        }
      }

      result = simde_uint64x2_from_private(r_);
    #endif
  #endif
  return result;
}
#if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
  #define simde_vqshluq_n_s64(a, n) vqshluq_n_s64(a, n)
#endif
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vqshluq_n_s64
  #define vqshluq_n_s64(a, n) simde_vqshluq_n_s64((a), (n))
#endif

SIMDE_END_DECLS_
HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_ARM_NEON_QSHLU_N_H) */
