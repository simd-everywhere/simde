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
 */

#if !defined(SIMDE_ARM_NEON_MMLAQ_H)
#define SIMDE_ARM_NEON_MMLAQ_H

#include "types.h"
#include "cgt.h"
#include "bsl.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

SIMDE_FUNCTION_ATTRIBUTES
simde_int32x4_t
simde_vmmlaq_s32(simde_int32x4_t r, simde_int8x16_t a, simde_int8x16_t b) {
  #if defined(SIMDE_ARM_NEON_A32V8_NATIVE)
    return vmmlaq_s32(r, a, b);
  #else
    simde_int8x16_private
      a_ = simde_int8x16_to_private(a),
      b_ = simde_int8x16_to_private(b);
    simde_int32x4_private
      r_ = simde_int32x4_to_private(r),
      ret;

    for (size_t k = 0 ; k < (sizeof(ret.values) / sizeof(ret.values[0])) ; k++) {
      ret.values[k] = r_.values[k];
      for (size_t i = 0 ; i < (sizeof(a_.values) / sizeof(a_.values[0]) / 2) ; i++) {
         ret.values[k] += a_.values[(k/2)*8+i] * b_.values[(k%2)*8+i];
      }
    }
    return simde_int32x4_from_private(ret);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V8_ENABLE_NATIVE_ALIASES)
  #undef vmmlaq_s32
  #define vmmlaq_s32(r, a, b) simde_vmmlaq_s32((r), (a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint32x4_t
simde_vmmlaq_u32(simde_uint32x4_t r, simde_uint8x16_t a, simde_uint8x16_t b) {
  #if defined(SIMDE_ARM_NEON_A32V8_NATIVE)
    return vmmlaq_u32(r, a, b);
  #else
    simde_uint8x16_private
      a_ = simde_uint8x16_to_private(a),
      b_ = simde_uint8x16_to_private(b);
    simde_uint32x4_private
      r_ = simde_uint32x4_to_private(r),
      ret;

    for (size_t k = 0 ; k < (sizeof(ret.values) / sizeof(ret.values[0])) ; k++) {
      ret.values[k] = r_.values[k];
      for (size_t i = 0 ; i < (sizeof(a_.values) / sizeof(a_.values[0]) / 2) ; i++) {
         ret.values[k] += a_.values[(k/2)*8+i] * b_.values[(k%2)*8+i];
      }
    }
    return simde_uint32x4_from_private(ret);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V8_ENABLE_NATIVE_ALIASES)
  #undef vmmlaq_u32
  #define vmmlaq_u32(r, a, b) simde_vmmlaq_u32((r), (a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_int32x4_t
simde_vusmmlaq_s32(simde_int32x4_t r, simde_uint8x16_t a, simde_int8x16_t b) {
  #if defined(SIMDE_ARM_NEON_A32V8_NATIVE)
    return vusmmlaq_s32(r, a, b);
  #else
    simde_uint8x16_private
      a_ = simde_uint8x16_to_private(a);
    simde_int8x16_private
      b_ = simde_int8x16_to_private(b);
    simde_int32x4_private
      r_ = simde_int32x4_to_private(r),
      ret;

    for (size_t k = 0 ; k < (sizeof(ret.values) / sizeof(ret.values[0])) ; k++) {
      ret.values[k] = r_.values[k];
      for (size_t i = 0 ; i < (sizeof(a_.values) / sizeof(a_.values[0]) / 2) ; i++) {
         ret.values[k] += a_.values[(k/2)*8+i] * b_.values[(k%2)*8+i];
      }
    }
    return simde_int32x4_from_private(ret);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V8_ENABLE_NATIVE_ALIASES)
  #undef vusmmlaq_s32
  #define vusmmlaq_s32(r, a, b) simde_vusmmlaq_s32((r), (a), (b))
#endif

/*
// [Eric] Pre-implemented bf16-related intrinsics
SIMDE_FUNCTION_ATTRIBUTES
simde_float32x4_t
simde_vbfmmlaq_f32(simde_float32x4_t r, simde_bfloat16x8_t a, simde_bfloat16x8_t b) {
  #if defined(SIMDE_ARM_NEON_A32V8_NATIVE)
    return vbfmmlaq_f32(r, a, b);
  #else
    simde_bfloat16x8_private
      a_ = simde_bfloat16x8_to_private(a),
      b_ = simde_bfloat16x8_to_private(b);
    simde_float32x4_private
      r_ = simde_float32x4_to_private(r),
      ret;

    for (size_t k = 0 ; k < (sizeof(ret.values) / sizeof(ret.values[0])) ; k++) {
      ret.values[k] = r_.values[k];
      for (size_t i = 0 ; i < (sizeof(a_.values) / sizeof(a_.values[0]) / 2) ; i++) {
         ret.values[k] += a_.values[(k/2)*4+i] * b_.values[(k%2)*4+i];
      }
    }
    return simde_float32x4_from_private(ret);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V8_ENABLE_NATIVE_ALIASES)
  #undef vbfmmlaq_f32
  #define vbfmmlaq_f32(r, a, b) simde_vbfmmlaq_f32((r), (a), (b))
#endif
*/

SIMDE_END_DECLS_
HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_ARM_NEON_MMLAQ_H) */
