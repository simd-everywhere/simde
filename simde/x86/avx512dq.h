/* Permission is hereby granted, free of charge, to any person
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
 */

#if !defined(SIMDE__AVX512DQ_H)
#define SIMDE__AVX512DQ_H
#include "avx512bw.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS

#if defined(SIMDE_AVX512DQ_NATIVE)
  #undef SIMDE_AVX512DQ_NATIVE
#endif
#if defined(SIMDE_ARCH_X86_AVX512DQ) && !defined(SIMDE_AVX512DQ_NO_NATIVE) && !defined(SIMDE_NO_NATIVE)
  #define SIMDE_AVX512DQ_NATIVE
#elif defined(SIMDE_ARCH_ARM_NEON) && !defined(SIMDE_AVX512DQ_NO_NEON) && !defined(SIMDE_NO_NEON)
  #define SIMDE_AVX512DQ_NEON
#elif defined(SIMDE_ARCH_POWER_ALTIVEC)
  #define SIMDE_AVX512DQ_POWER_ALTIVEC
#endif

#if defined(SIMDE_AVX512DQ_NATIVE)
  #include <immintrin.h>
#endif

#if defined(SIMDE_AVX512DQ_POWER_ALTIVEC)
  #include <altivec.h>
#endif

#if !defined(SIMDE_AVX512DQ_NATIVE) && defined(SIMDE_ENABLE_NATIVE_ALIASES)
  #define SIMDE_AVX512DQ_ENABLE_NATIVE_ALIASES
#endif
SIMDE__BEGIN_DECLS

SIMDE__FUNCTION_ATTRIBUTES
simde__m512d
simde_mm512_and_pd (simde__m512d a, simde__m512d b) {
#if defined(SIMDE_AVX512DQ_NATIVE)
  return _mm512_and_pd(a, b);
#else
  simde__m512d_private
    r_,
    a_ = simde__m512d_to_private(a),
    b_ = simde__m512d_to_private(b);

#if defined(SIMDE_ARCH_X86_AVX)
  r_.m256d[0] = simde_mm256_and_pd(a_.m256d[0], b_.m256d[0]);
  r_.m256d[1] = simde_mm256_and_pd(a_.m256d[1], b_.m256d[1]);
#elif defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
  r_.i32f = a_.i32f & b_.i32f;
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.i32f) / sizeof(r_.i32f[0])) ; i++) {
    r_.i32f[i] = a_.i32f[i] & b_.i32f[i];
  }
#endif

  return simde__m512d_from_private(r_);
#endif
}
#if defined(SIMDE_AVX512DQ_ENABLE_NATIVE_ALIASES)
#  define _mm512_and_pd(a, b) simde_mm512_and_pd(a, b)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m512
simde_mm512_and_ps (simde__m512 a, simde__m512 b) {
#if defined(SIMDE_AVX512DQ_NATIVE)
  return _mm512_and_ps(a, b);
#else
  simde__m512_private
    r_,
    a_ = simde__m512_to_private(a),
    b_ = simde__m512_to_private(b);

#if defined(SIMDE_ARCH_X86_AVX)
  r_.m256[0] = simde_mm256_and_ps(a_.m256[0], b_.m256[0]);
  r_.m256[1] = simde_mm256_and_ps(a_.m256[1], b_.m256[1]);
#elif defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
  r_.i32f = a_.i32f & b_.i32f;
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.i32f) / sizeof(r_.i32f[0])) ; i++) {
    r_.i32f[i] = a_.i32f[i] & b_.i32f[i];
  }
#endif

  return simde__m512_from_private(r_);
#endif
}
#if defined(SIMDE_AVX512DQ_ENABLE_NATIVE_ALIASES)
#  define _mm512_and_ps(a, b) simde_mm512_and_ps(a, b)
#endif

SIMDE__END_DECLS

HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE__AVX512DQ_H) */
