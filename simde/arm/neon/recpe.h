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
 *   2021      Zhi An Ng <zhin@google.com> (Copyright owned by Google, LLC)
 */

#if !defined(SIMDE_ARM_NEON_RECPE_H)
#define SIMDE_ARM_NEON_RECPE_H

#include "types.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

SIMDE_FUNCTION_ATTRIBUTES
simde_float32x2_t
simde_vrecpe_f32(simde_float32x2_t a) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vrecpe_f32(a);
  #else
    simde_float32x2_private
      r_,
      a_ = simde_float32x2_to_private(a);

    #if defined(SIMDE_IEEE754_STORAGE)
      /* https://stackoverflow.com/questions/12227126/division-as-multiply-and-lut-fast-float-division-reciprocal/12228234#12228234 */
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
        int32_t ix;
        simde_float32 fx = a_.values[i];
        simde_memcpy(&ix, &fx, sizeof(ix));
        int32_t x = INT32_C(0x7EF311C3) - ix;
        simde_float32 temp;
        simde_memcpy(&temp, &x, sizeof(temp));
        r_.values[i] = temp * (SIMDE_FLOAT32_C(2.0) - temp * fx);
      }
    #elif defined(SIMDE_VECTOR_SUBSCRIPT_SCALAR)
      r_.f32 = 1.0f / a_.f32;
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.f32) / sizeof(r_.f32[0])) ; i++) {
        r_.values[i] = 1.0f / a_.values[i];
      }
    #endif

    return simde_float32x2_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vrecpe_f32
  #define vrecpe_f32(a) simde_vrecpe_f32((a))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_float32x4_t
simde_vrecpeq_f32(simde_float32x4_t a) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vrecpeq_f32(a);
  #elif defined(SIMDE_POWER_ALTIVEC_P6_NATIVE)
    return vec_re(a);
  #else
    simde_float32x4_private
      r_,
      a_ = simde_float32x4_to_private(a);

    #if defined(SIMDE_X86_SSE_NATIVE)
      r_.m128 = _mm_rcp_ps(a_.m128);
    #elif defined(SIMDE_IEEE754_STORAGE)
      /* https://stackoverflow.com/questions/12227126/division-as-multiply-and-lut-fast-float-division-reciprocal/12228234#12228234 */
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
        int32_t ix;
        simde_float32 fx = a_.values[i];
        simde_memcpy(&ix, &fx, sizeof(ix));
        int32_t x = INT32_C(0x7EF311C3) - ix;
        simde_float32 temp;
        simde_memcpy(&temp, &x, sizeof(temp));
        r_.values[i] = temp * (SIMDE_FLOAT32_C(2.0) - temp * fx);
      }
    #elif defined(SIMDE_VECTOR_SUBSCRIPT_SCALAR)
      r_.f32 = 1.0f / a_.f32;
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.f32) / sizeof(r_.f32[0])) ; i++) {
        r_.values[i] = 1.0f / a_.values[i];
      }
    #endif

    return simde_float32x4_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vrecpeq_f32
  #define vrecpeq_f32(a) simde_vrecpeq_f32((a))
#endif

SIMDE_END_DECLS_
HEDLEY_DIAGNOSTIC_POP
#endif /* !defined(SIMDE_ARM_NEON_RECPE_H) */
