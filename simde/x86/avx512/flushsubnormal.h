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
 *   2021      Kunwar Maheep Singh <kunwar.maheep@students.iiit.ac.in>
 */

#if !defined(SIMDE_X86_AVX512_FLUSHSUBNORMAL_H)
#define SIMDE_X86_AVX512_FLUSHSUBNORMAL_H

#include "types.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

SIMDE_FUNCTION_ATTRIBUTES
simde__m128
simde_x_mm_flushsubnormal_ps (simde__m128 a) {
  simde__m128_private a_ = simde__m128_to_private(a);

  SIMDE_VECTORIZE
  for (size_t i = 0 ; i < (sizeof(a_.f32) / sizeof(a_.f32[0])) ; i++) {
    a_.f32[i] = simde_math_issubnormalf(a_.f32[i]) ? 0 : a_.f32[i];
  }

  return simde__m128_from_private(a_);
}

SIMDE_FUNCTION_ATTRIBUTES
simde__m256
simde_x_mm256_flushsubnormal_ps (simde__m256 a) {
  simde__m256_private a_ = simde__m256_to_private(a);

  SIMDE_VECTORIZE
  for (size_t i = 0 ; i < (sizeof(a_.f32) / sizeof(a_.f32[0])) ; i++) {
    a_.f32[i] = simde_math_issubnormalf(a_.f32[i]) ? 0 : a_.f32[i];
  }

  return simde__m256_from_private(a_);
}

SIMDE_FUNCTION_ATTRIBUTES
simde__m512
simde_x_mm512_flushsubnormal_ps (simde__m512 a) {
  simde__m512_private a_ = simde__m512_to_private(a);

  SIMDE_VECTORIZE
  for (size_t i = 0 ; i < (sizeof(a_.f32) / sizeof(a_.f32[0])) ; i++) {
    a_.f32[i] = simde_math_issubnormalf(a_.f32[i]) ? 0 : a_.f32[i];
  }

  return simde__m512_from_private(a_);
}

SIMDE_FUNCTION_ATTRIBUTES
simde__m128d
simde_x_mm_flushsubnormal_pd (simde__m128d a) {
  simde__m128d_private a_ = simde__m128d_to_private(a);

  SIMDE_VECTORIZE
  for (size_t i = 0 ; i < (sizeof(a_.f64) / sizeof(a_.f64[0])) ; i++) {
    a_.f64[i] = simde_math_issubnormal(a_.f64[i]) ? 0 : a_.f64[i];
  }

  return simde__m128d_from_private(a_);
}

SIMDE_FUNCTION_ATTRIBUTES
simde__m256d
simde_x_mm256_flushsubnormal_pd (simde__m256d a) {
  simde__m256d_private a_ = simde__m256d_to_private(a);

  SIMDE_VECTORIZE
  for (size_t i = 0 ; i < (sizeof(a_.f64) / sizeof(a_.f64[0])) ; i++) {
    a_.f64[i] = simde_math_issubnormal(a_.f64[i]) ? 0 : a_.f64[i];
  }

  return simde__m256d_from_private(a_);
}

SIMDE_FUNCTION_ATTRIBUTES
simde__m512d
simde_x_mm512_flushsubnormal_pd (simde__m512d a) {
  simde__m512d_private a_ = simde__m512d_to_private(a);

  SIMDE_VECTORIZE
  for (size_t i = 0 ; i < (sizeof(a_.f64) / sizeof(a_.f64[0])) ; i++) {
    a_.f64[i] = simde_math_issubnormal(a_.f64[i]) ? 0 : a_.f64[i];
  }

  return simde__m512d_from_private(a_);
}

SIMDE_END_DECLS_
HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_X86_AVX512_FLUSHSUBNORMAL_H) */
