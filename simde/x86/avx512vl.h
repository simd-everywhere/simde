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

#if !defined(SIMDE__AVX512VL_H)
#define SIMDE__AVX512VL_H
#include "avx512bw.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS

#if defined(SIMDE_AVX512VL_NATIVE)
  #undef SIMDE_AVX512VL_NATIVE
#endif
#if defined(SIMDE_ARCH_X86_AVX512VL) && !defined(SIMDE_AVX512VL_NO_NATIVE) && !defined(SIMDE_NO_NATIVE)
  #define SIMDE_AVX512VL_NATIVE
#elif defined(SIMDE_ARCH_ARM_NEON) && !defined(SIMDE_AVX512VL_NO_NEON) && !defined(SIMDE_NO_NEON)
  #define SIMDE_AVX512VL_NEON
#elif defined(SIMDE_ARCH_POWER_ALTIVEC)
  #define SIMDE_AVX512VL_POWER_ALTIVEC
#endif

#if defined(SIMDE_AVX512VL_NATIVE)
  #include <immintrin.h>
#endif

#if defined(SIMDE_AVX512VL_POWER_ALTIVEC)
  #include <altivec.h>
#endif

#if !defined(SIMDE_AVX512VL_NATIVE) && defined(SIMDE_ENABLE_NATIVE_ALIASES)
  #define SIMDE_AVX512VL_ENABLE_NATIVE_ALIASES
#endif
SIMDE__BEGIN_DECLS

SIMDE__FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_cvtsepi16_epi8 (simde__m128i a) {
  #if defined(SIMDE_AVX512VL_NATIVE) && defined(SIMDE_AVX512BW_NATIVE)
    return _mm_cvtsepi16_epi8(a);
  #else
    simde__m128i_private r_ = simde__m128i_to_private(simde_mm_setzero_si128());;
    simde__m128i_private a_ = simde__m128i_to_private(a);

    SIMDE__VECTORIZE
    for (size_t i = 0 ; i < (sizeof(a_.i16) / sizeof(a_.i16[0])) ; i++) {
      r_.i8[i] =
          (a_.i16[i] < INT8_MIN)
            ? (INT8_MIN)
            : ((a_.i16[i] > INT8_MAX)
              ? (INT8_MAX)
              : HEDLEY_STATIC_CAST(int8_t, a_.i16[i]));
    }

    return simde__m128i_from_private(r_);
  #endif
}
#if defined(SIMDE_AVX512VL_ENABLE_NATIVE_ALIASES)
  #define _mm_cvtsepi16_epi8(a) simde_mm_cvtsepi16_epi8(a)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128i
simde_mm256_cvtsepi16_epi8 (simde__m256i a) {
  #if defined(SIMDE_AVX512VL_NATIVE) && defined(SIMDE_AVX512BW_NATIVE)
    return _mm256_cvtsepi16_epi8(a);
  #else
    simde__m128i_private r_;
    simde__m256i_private a_ = simde__m256i_to_private(a);

    SIMDE__VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.i8) / sizeof(r_.i8[0])) ; i++) {
      r_.i8[i] =
          (a_.i16[i] < INT8_MIN)
            ? (INT8_MIN)
            : ((a_.i16[i] > INT8_MAX)
              ? (INT8_MAX)
              : HEDLEY_STATIC_CAST(int8_t, a_.i16[i]));
    }

    return simde__m128i_from_private(r_);
  #endif
}
#if defined(SIMDE_AVX512VL_ENABLE_NATIVE_ALIASES)
  #define _mm256_cvtsepi16_epi8(a) simde_mm256_cvtsepi16_epi8(a)
#endif

SIMDE__END_DECLS

HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE__AVX512VL_H) */
