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

#if !defined(SIMDE_ARM_NEON_RECPS_H)
#define SIMDE_ARM_NEON_RECPS_H

#include "types.h"
#include "sub.h"
#include "mul.h"
#include "dup_n.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

SIMDE_FUNCTION_ATTRIBUTES
simde_float32x2_t
simde_vrecps_f32(simde_float32x2_t a, simde_float32x2_t b) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vrecps_f32(a, b);
  #else
    return simde_vsub_f32(simde_vdup_n_f32(SIMDE_FLOAT32_C(2.0)), simde_vmul_f32(a, b));
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vrecps_f32
  #define vrecps_f32(a, b) simde_vrecps_f32((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_float32x4_t
simde_vrecpsq_f32(simde_float32x4_t a, simde_float32x4_t b) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vrecpsq_f32(a, b);
  #else
    return simde_vsubq_f32(simde_vdupq_n_f32(SIMDE_FLOAT32_C(2.0)), simde_vmulq_f32(a, b));
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vrecpsq_f32
  #define vrecpsq_f32(a, b) simde_vrecpsq_f32((a), (b))
#endif

SIMDE_END_DECLS_
HEDLEY_DIAGNOSTIC_POP
#endif /* !defined(SIMDE_ARM_NEON_RECPS_H) */
