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
 *   2021      Zhi An Ng <zhin@google.com> (Copyright owned by Google, LLC)
 */

#if !defined(SIMDE_ARM_NEON_RSQRTS_H)
#define SIMDE_ARM_NEON_RSQRTS_H

#include "types.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

SIMDE_FUNCTION_ATTRIBUTES
simde_float32x2_t
simde_vrsqrts_f32(simde_float32x2_t a, simde_float32x2_t b) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vrsqrts_f32(a, b);
  #else
    simde_float32x2_private
      r_,
      a_ = simde_float32x2_to_private(a),
      b_ = simde_float32x2_to_private(b);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
      r_.values[i] = (SIMDE_FLOAT32_C(3.0) - (a_.values[i] * b_.values[i])) /
                     SIMDE_FLOAT32_C(2.0);
    }

    return simde_float32x2_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vrsqrts_f32
  #define vrsqrts_f32(a, b) simde_vrsqrts_f32((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_float32x4_t
simde_vrsqrtsq_f32(simde_float32x4_t a, simde_float32x4_t b) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vrsqrtsq_f32(a, b);
  #else
    simde_float32x4_private
      r_,
      a_ = simde_float32x4_to_private(a),
      b_ = simde_float32x4_to_private(b);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
      r_.values[i] = (SIMDE_FLOAT32_C(3.0) - (a_.values[i] * b_.values[i])) /
                     SIMDE_FLOAT32_C(2.0);
    }

    return simde_float32x4_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vrsqrtsq_f32
  #define vrsqrtsq_f32(a, b) simde_vrsqrtsq_f32((a), (b))
#endif

SIMDE_END_DECLS_
HEDLEY_DIAGNOSTIC_POP
#endif /* !defined(SIMDE_ARM_NEON_RSQRTS_H) */
