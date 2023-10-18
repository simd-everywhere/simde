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
 *   2023      Yung-Cheng Su <eric20607@gapp.nthu.edu.tw>
 */

#if !defined(SIMDE_ARM_NEON_QRDMLSH_H)
#define SIMDE_ARM_NEON_QRDMLSH_H

#include "types.h"
#include "qadd.h"
#include "qrdmulh.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

SIMDE_FUNCTION_ATTRIBUTES
int16_t
simde_vqrdmlshh_s16(int16_t a, int16_t b, int16_t c) {
  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
    return vqrdmlshh_s16(a, b, c);
  #else
    return simde_vqaddh_s16(a, simde_vqrdmulhh_s16(-b, c));
  #endif
}
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES)
  #undef vqrdmlshh_s16
  #define vqrdmlshh_s16(a, b, c) simde_vqrdmlshh_s16((a), (b), (c))
#endif

SIMDE_FUNCTION_ATTRIBUTES
int32_t
simde_vqrdmlshs_s32(int32_t a, int32_t b, int32_t c) {
  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
    return vqrdmlshs_s32(a, b, c);
  #else
    return simde_vqadds_s32(a, simde_vqrdmulhs_s32(-b, c));
  #endif
}
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES)
  #undef vqrdmlshs_s32
  #define vqrdmlshs_s32(a, b, c) simde_vqrdmlshs_s32((a), (b), (c))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_int16x4_t
simde_vqrdmlsh_s16(simde_int16x4_t a, simde_int16x4_t b, simde_int16x4_t c) {
  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
    return vqrdmlsh_s16(a, b, c);
  #else
    simde_int16x4_private
      r_,
      a_ = simde_int16x4_to_private(a),
      b_ = simde_int16x4_to_private(b),
      c_ = simde_int16x4_to_private(c);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
      r_.values[i] = simde_vqrdmlshh_s16(a_.values[i], b_.values[i], c_.values[i]);
    }

    return simde_int16x4_from_private(r_);

  #endif
}
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES)
  #undef vqrdmlsh_s16
  #define vqrdmlsh_s16(a, b, c) simde_vqrdmlsh_s16((a), (b), (c))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_int32x2_t
simde_vqrdmlsh_s32(simde_int32x2_t a, simde_int32x2_t b, simde_int32x2_t c) {
  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
    return vqrdmlsh_s32(a, b, c);
  #else
    simde_int32x2_private
      r_,
      a_ = simde_int32x2_to_private(a),
      b_ = simde_int32x2_to_private(b),
      c_ = simde_int32x2_to_private(c);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
      r_.values[i] = simde_vqrdmlshs_s32(a_.values[i], b_.values[i], c_.values[i]);
    }

    return simde_int32x2_from_private(r_);

  #endif
}
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES)
  #undef vqrdmlsh_s32
  #define vqrdmlsh_s32(a, b, c) simde_vqrdmlsh_s32((a), (b), (c))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_int16x8_t
simde_vqrdmlshq_s16(simde_int16x8_t a, simde_int16x8_t b, simde_int16x8_t c) {
  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
    return vqrdmlshq_s16(a, b, c);
  #else
    simde_int16x8_private
      r_,
      a_ = simde_int16x8_to_private(a),
      b_ = simde_int16x8_to_private(b),
      c_ = simde_int16x8_to_private(c);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
      r_.values[i] = simde_vqrdmlshh_s16(a_.values[i], b_.values[i], c_.values[i]);
    }

    return simde_int16x8_from_private(r_);

  #endif
}
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES)
  #undef vqrdmlshq_s16
  #define vqrdmlshq_s16(a, b, c) simde_vqrdmlshq_s16((a), (b), (c))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_int32x4_t
simde_vqrdmlshq_s32(simde_int32x4_t a, simde_int32x4_t b, simde_int32x4_t c) {
  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
    return vqrdmlshq_s32(a, b, c);
  #else
    simde_int32x4_private
      r_,
      a_ = simde_int32x4_to_private(a),
      b_ = simde_int32x4_to_private(b),
      c_ = simde_int32x4_to_private(c);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
      r_.values[i] = simde_vqrdmlshs_s32(a_.values[i], b_.values[i], c_.values[i]);
    }

    return simde_int32x4_from_private(r_);

  #endif
}
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES)
  #undef vqrdmlshq_s32
  #define vqrdmlshq_s32(a, b, c) simde_vqrdmlshq_s32((a), (b), (c))
#endif

SIMDE_END_DECLS_
HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_ARM_NEON_QRDMLSH_H) */
