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

#if !defined(SIMDE_ARM_NEON_RSQRTE_H)
#define SIMDE_ARM_NEON_RSQRTE_H

#include "types.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

SIMDE_FUNCTION_ATTRIBUTES
simde_float32x2_t
simde_vrsqrte_f32(simde_float32x2_t a) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vrsqrte_f32(a);
  #else
    simde_float32x2_private
      r_,
      a_ = simde_float32x2_to_private(a);

    #if defined(SIMDE_IEEE754_STORAGE)
      /* https://basesandframes.files.wordpress.com/2020/04/even_faster_math_functions_green_2020.pdf
        Pages 100 - 103 */
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
        #if SIMDE_ACCURACY_PREFERENCE <= 0
          r_.i32[i] = INT32_C(0x5F37624F) - (a_.i32[i] >> 1);
        #else
          simde_float32 x = a_.values[i];
          simde_float32 xhalf = SIMDE_FLOAT32_C(0.5) * x;
          int32_t ix;

          simde_memcpy(&ix, &x, sizeof(ix));

          #if SIMDE_ACCURACY_PREFERENCE == 1
            ix = INT32_C(0x5F375A82) - (ix >> 1);
          #else
            ix = INT32_C(0x5F37599E) - (ix >> 1);
          #endif

          simde_memcpy(&x, &ix, sizeof(x));

          #if SIMDE_ACCURACY_PREFERENCE >= 2
            x = x * (SIMDE_FLOAT32_C(1.5008909) - xhalf * x * x);
          #endif
          x = x * (SIMDE_FLOAT32_C(1.5008909) - xhalf * x * x);

          r_.values[i] = x;
        #endif
      }
    #elif defined(simde_math_sqrtf)
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.f32) / sizeof(r_.f32[0])) ; i++) {
        r_.f32[i] = 1.0f / simde_math_sqrtf(a_.f32[i]);
      }
    #else
      HEDLEY_UNREACHABLE();
    #endif

    return simde_float32x2_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vrsqrte_f32
  #define vrsqrte_f32(a) simde_vrsqrte_f32((a))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_float32x4_t
simde_vrsqrteq_f32(simde_float32x4_t a) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vrsqrteq_f32(a);
  #elif defined(SIMDE_POWER_ALTIVEC_P6_NATIVE)
    return vec_rsqrte(a);
  #else
    simde_float32x4_private
      r_,
      a_ = simde_float32x4_to_private(a);

    #if defined(SIMDE_X86_SSE_NATIVE)
      r_.m128 = _mm_rsqrt_ps(a_.m128);
    #elif defined(SIMDE_IEEE754_STORAGE)
      /* https://basesandframes.files.wordpress.com/2020/04/even_faster_math_functions_green_2020.pdf
        Pages 100 - 103 */
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
        #if SIMDE_ACCURACY_PREFERENCE <= 0
          r_.i32[i] = INT32_C(0x5F37624F) - (a_.i32[i] >> 1);
        #else
          simde_float32 x = a_.values[i];
          simde_float32 xhalf = SIMDE_FLOAT32_C(0.5) * x;
          int32_t ix;

          simde_memcpy(&ix, &x, sizeof(ix));

          #if SIMDE_ACCURACY_PREFERENCE == 1
            ix = INT32_C(0x5F375A82) - (ix >> 1);
          #else
            ix = INT32_C(0x5F37599E) - (ix >> 1);
          #endif

          simde_memcpy(&x, &ix, sizeof(x));

          #if SIMDE_ACCURACY_PREFERENCE >= 2
            x = x * (SIMDE_FLOAT32_C(1.5008909) - xhalf * x * x);
          #endif
          x = x * (SIMDE_FLOAT32_C(1.5008909) - xhalf * x * x);

          r_.values[i] = x;
        #endif
      }
    #elif defined(simde_math_sqrtf)
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.f32) / sizeof(r_.f32[0])) ; i++) {
        r_.f32[i] = 1.0f / simde_math_sqrtf(a_.f32[i]);
      }
    #else
      HEDLEY_UNREACHABLE();
    #endif

    return simde_float32x4_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vrsqrteq_f32
  #define vrsqrteq_f32(a) simde_vrsqrteq_f32((a))
#endif

SIMDE_END_DECLS_
HEDLEY_DIAGNOSTIC_POP
#endif /* !defined(SIMDE_ARM_NEON_RSQRTE_H) */
