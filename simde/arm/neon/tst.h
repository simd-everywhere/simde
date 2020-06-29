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
 */

#if !defined(SIMDE_ARM_NEON_TST_H)
#define SIMDE_ARM_NEON_TST_H

#include "and.h"
#include "cgt.h"
#include "dup_n.h"
#include "reinterpret.h"
#include "types.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

SIMDE_FUNCTION_ATTRIBUTES
simde_uint8x8_t
simde_vtst_s8(simde_int8x8_t a, simde_int8x8_t b) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vtst_s8(a, b);
  #elif defined(SIMDE_NATURAL_VECTOR_SIZE) && (SIMDE_NATURAL_VECTOR_SIZE >= 64)
    return simde_vcgt_u8(simde_vreinterpret_u8_s8(simde_vand_s8(a, b)), simde_vdup_n_u8(0));
  #else
    simde_int8x8_private
      a_ = simde_int8x8_to_private(a),
      b_ = simde_int8x8_to_private(b);
    simde_uint8x8_private r_;

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
      r_.values[i] = ((a_.values[i] & b_.values[i]) != 0) ? UINT8_MAX : 0;
    }

    return simde_uint8x8_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vtst_s8
  #define vtst_s8(a, b) simde_vtst_s8((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint16x4_t
simde_vtst_s16(simde_int16x4_t a, simde_int16x4_t b) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vtst_s16(a, b);
  #elif defined(SIMDE_NATURAL_VECTOR_SIZE) && (SIMDE_NATURAL_VECTOR_SIZE >= 64)
    return simde_vcgt_u16(simde_vreinterpret_u16_s16(simde_vand_s16(a, b)), simde_vdup_n_u16(0));
  #else
    simde_int16x4_private
      a_ = simde_int16x4_to_private(a),
      b_ = simde_int16x4_to_private(b);
    simde_uint16x4_private r_;

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
      r_.values[i] = ((a_.values[i] & b_.values[i]) != 0) ? UINT16_MAX : 0;
    }

    return simde_uint16x4_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vtst_s16
  #define vtst_s16(a, b) simde_vtst_s16((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint32x2_t
simde_vtst_s32(simde_int32x2_t a, simde_int32x2_t b) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vtst_s32(a, b);
  #elif defined(SIMDE_NATURAL_VECTOR_SIZE) && (SIMDE_NATURAL_VECTOR_SIZE >= 64)
    return simde_vcgt_u32(simde_vreinterpret_u32_s32(simde_vand_s32(a, b)), simde_vdup_n_u32(0));
  #else
    simde_int32x2_private
      a_ = simde_int32x2_to_private(a),
      b_ = simde_int32x2_to_private(b);
    simde_uint32x2_private r_;

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
      r_.values[i] = ((a_.values[i] & b_.values[i]) != 0) ? UINT32_MAX : 0;
    }

    return simde_uint32x2_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vtst_s32
  #define vtst_s32(a, b) simde_vtst_s32((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint64x1_t
simde_vtst_s64(simde_int64x1_t a, simde_int64x1_t b) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vtst_s64(a, b);
  #elif defined(SIMDE_NATURAL_VECTOR_SIZE) && (SIMDE_NATURAL_VECTOR_SIZE >= 64)
    return simde_vcgt_u64(simde_vreinterpret_u64_s64(simde_vand_s64(a, b)), simde_vdup_n_u64(0));
  #else
    simde_int64x1_private
      a_ = simde_int64x1_to_private(a),
      b_ = simde_int64x1_to_private(b);
    simde_uint64x1_private r_;

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
      r_.values[i] = ((a_.values[i] & b_.values[i]) != 0) ? UINT64_MAX : 0;
    }

    return simde_uint64x1_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vtst_s64
  #define vtst_s64(a, b) simde_vtst_s64((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint8x8_t
simde_vtst_u8(simde_uint8x8_t a, simde_uint8x8_t b) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vtst_u8(a, b);
  #elif defined(SIMDE_NATURAL_VECTOR_SIZE) && (SIMDE_NATURAL_VECTOR_SIZE >= 64)
    return simde_vcgt_u8(simde_vand_u8(a, b), simde_vdup_n_u8(0));
  #else
    simde_uint8x8_private
      r_,
      a_ = simde_uint8x8_to_private(a),
      b_ = simde_uint8x8_to_private(b);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
      r_.values[i] = ((a_.values[i] & b_.values[i]) != 0) ? UINT8_MAX : 0;
    }

    return simde_uint8x8_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vtst_u8
  #define vtst_u8(a, b) simde_vtst_u8((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint16x4_t
simde_vtst_u16(simde_uint16x4_t a, simde_uint16x4_t b) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vtst_u16(a, b);
  #elif defined(SIMDE_NATURAL_VECTOR_SIZE) && (SIMDE_NATURAL_VECTOR_SIZE >= 64)
    return simde_vcgt_u16(simde_vand_u16(a, b), simde_vdup_n_u16(0));
  #else
    simde_uint16x4_private
      r_,
      a_ = simde_uint16x4_to_private(a),
      b_ = simde_uint16x4_to_private(b);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
      r_.values[i] = ((a_.values[i] & b_.values[i]) != 0) ? UINT16_MAX : 0;
    }

    return simde_uint16x4_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vtst_u16
  #define vtst_u16(a, b) simde_vtst_u16((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint32x2_t
simde_vtst_u32(simde_uint32x2_t a, simde_uint32x2_t b) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vtst_u32(a, b);
  #elif defined(SIMDE_NATURAL_VECTOR_SIZE) && (SIMDE_NATURAL_VECTOR_SIZE >= 64)
    return simde_vcgt_u32(simde_vand_u32(a, b), simde_vdup_n_u32(0));
  #else
    simde_uint32x2_private
      r_,
      a_ = simde_uint32x2_to_private(a),
      b_ = simde_uint32x2_to_private(b);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
      r_.values[i] = ((a_.values[i] & b_.values[i]) != 0) ? UINT32_MAX : 0;
    }

    return simde_uint32x2_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vtst_u32
  #define vtst_u32(a, b) simde_vtst_u32((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint64x1_t
simde_vtst_u64(simde_uint64x1_t a, simde_uint64x1_t b) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vtst_u64(a, b);
  #elif defined(SIMDE_NATURAL_VECTOR_SIZE) && (SIMDE_NATURAL_VECTOR_SIZE >= 64)
    return simde_vcgt_u64(simde_vand_u64(a, b), simde_vdup_n_u64(0));
  #else
    simde_uint64x1_private
      r_,
      a_ = simde_uint64x1_to_private(a),
      b_ = simde_uint64x1_to_private(b);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
      r_.values[i] = ((a_.values[i] & b_.values[i]) != 0) ? UINT64_MAX : 0;
    }

    return simde_uint64x1_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vtst_u64
  #define vtst_u64(a, b) simde_vtst_u64((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint8x16_t
simde_vtstq_s8(simde_int8x16_t a, simde_int8x16_t b) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vtstq_s8(a, b);
  #elif defined(SIMDE_NATURAL_VECTOR_SIZE) && (SIMDE_NATURAL_VECTOR_SIZE >= 128)
    return simde_vcgtq_u8(simde_vreinterpretq_u8_s8(simde_vandq_s8(a, b)), simde_vdupq_n_u8(0));
  #else
    simde_int8x16_private
      a_ = simde_int8x16_to_private(a),
      b_ = simde_int8x16_to_private(b);
    simde_uint8x16_private r_;

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
      r_.values[i] = ((a_.values[i] & b_.values[i]) != 0) ? UINT8_MAX : 0;
    }

    return simde_uint8x16_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vtstq_s8
  #define vtstq_s8(a, b) simde_vtstq_s8((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint16x8_t
simde_vtstq_s16(simde_int16x8_t a, simde_int16x8_t b) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vtstq_s16(a, b);
  #elif defined(SIMDE_NATURAL_VECTOR_SIZE) && (SIMDE_NATURAL_VECTOR_SIZE >= 128)
    return simde_vcgtq_u16(simde_vreinterpretq_u16_s16(simde_vandq_s16(a, b)), simde_vdupq_n_u16(0));
  #else
    simde_int16x8_private
      a_ = simde_int16x8_to_private(a),
      b_ = simde_int16x8_to_private(b);
    simde_uint16x8_private r_;

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
      r_.values[i] = ((a_.values[i] & b_.values[i]) != 0) ? UINT16_MAX : 0;
    }

    return simde_uint16x8_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vtstq_s16
  #define vtstq_s16(a, b) simde_vtstq_s16((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint32x4_t
simde_vtstq_s32(simde_int32x4_t a, simde_int32x4_t b) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vtstq_s32(a, b);
  #elif defined(SIMDE_NATURAL_VECTOR_SIZE) && (SIMDE_NATURAL_VECTOR_SIZE >= 128)
    return simde_vcgtq_u32(simde_vreinterpretq_u32_s32(simde_vandq_s32(a, b)), simde_vdupq_n_u32(0));
  #else
    simde_int32x4_private
      a_ = simde_int32x4_to_private(a),
      b_ = simde_int32x4_to_private(b);
    simde_uint32x4_private r_;

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
      r_.values[i] = ((a_.values[i] & b_.values[i]) != 0) ? UINT32_MAX : 0;
    }

    return simde_uint32x4_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vtstq_s32
  #define vtstq_s32(a, b) simde_vtstq_s32((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint64x2_t
simde_vtstq_s64(simde_int64x2_t a, simde_int64x2_t b) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vtstq_s64(a, b);
  #elif defined(SIMDE_NATURAL_VECTOR_SIZE) && (SIMDE_NATURAL_VECTOR_SIZE >= 128)
    return simde_vcgtq_u64(simde_vreinterpretq_u64_s64(simde_vandq_s64(a, b)), simde_vdupq_n_u64(0));
  #else
    simde_int64x2_private
      a_ = simde_int64x2_to_private(a),
      b_ = simde_int64x2_to_private(b);
    simde_uint64x2_private r_;

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
      r_.values[i] = ((a_.values[i] & b_.values[i]) != 0) ? UINT64_MAX : 0;
    }

    return simde_uint64x2_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vtstq_s64
  #define vtstq_s64(a, b) simde_vtstq_s64((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint8x16_t
simde_vtstq_u8(simde_uint8x16_t a, simde_uint8x16_t b) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vtstq_u8(a, b);
  #elif defined(SIMDE_NATURAL_VECTOR_SIZE) && (SIMDE_NATURAL_VECTOR_SIZE >= 128)
    return simde_vcgtq_u8(simde_vandq_u8(a, b), simde_vdupq_n_u8(0));
  #else
    simde_uint8x16_private
      r_,
      a_ = simde_uint8x16_to_private(a),
      b_ = simde_uint8x16_to_private(b);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
      r_.values[i] = ((a_.values[i] & b_.values[i]) != 0) ? UINT8_MAX : 0;
    }

    return simde_uint8x16_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vtstq_u8
  #define vtstq_u8(a, b) simde_vtstq_u8((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint16x8_t
simde_vtstq_u16(simde_uint16x8_t a, simde_uint16x8_t b) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vtstq_u16(a, b);
  #elif defined(SIMDE_NATURAL_VECTOR_SIZE) && (SIMDE_NATURAL_VECTOR_SIZE >= 128)
    return simde_vcgtq_u16(simde_vandq_u16(a, b), simde_vdupq_n_u16(0));
  #else
    simde_uint16x8_private
      r_,
      a_ = simde_uint16x8_to_private(a),
      b_ = simde_uint16x8_to_private(b);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
      r_.values[i] = ((a_.values[i] & b_.values[i]) != 0) ? UINT16_MAX : 0;
    }

    return simde_uint16x8_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vtstq_u16
  #define vtstq_u16(a, b) simde_vtstq_u16((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint32x4_t
simde_vtstq_u32(simde_uint32x4_t a, simde_uint32x4_t b) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vtstq_u32(a, b);
  #elif defined(SIMDE_NATURAL_VECTOR_SIZE) && (SIMDE_NATURAL_VECTOR_SIZE >= 128)
    return simde_vcgtq_u32(simde_vandq_u32(a, b), simde_vdupq_n_u32(0));
  #else
    simde_uint32x4_private
      r_,
      a_ = simde_uint32x4_to_private(a),
      b_ = simde_uint32x4_to_private(b);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
      r_.values[i] = ((a_.values[i] & b_.values[i]) != 0) ? UINT32_MAX : 0;
    }

    return simde_uint32x4_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vtstq_u32
  #define vtstq_u32(a, b) simde_vtstq_u32((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint64x2_t
simde_vtstq_u64(simde_uint64x2_t a, simde_uint64x2_t b) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vtstq_u64(a, b);
  #elif defined(SIMDE_NATURAL_VECTOR_SIZE) && (SIMDE_NATURAL_VECTOR_SIZE >= 128)
    return simde_vcgtq_u64(simde_vandq_u64(a, b), simde_vdupq_n_u64(0));
  #else
    simde_uint64x2_private
      r_,
      a_ = simde_uint64x2_to_private(a),
      b_ = simde_uint64x2_to_private(b);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
      r_.values[i] = ((a_.values[i] & b_.values[i]) != 0) ? UINT64_MAX : 0;
    }

    return simde_uint64x2_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vtstq_u64
  #define vtstq_u64(a, b) simde_vtstq_u64((a), (b))
#endif

SIMDE_END_DECLS_
HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_ARM_NEON_TST_H) */
