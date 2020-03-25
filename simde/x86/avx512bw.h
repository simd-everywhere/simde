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

#if !defined(SIMDE__AVX512BW_H)
#  if !defined(SIMDE__AVX512BW_H)
#    define SIMDE__AVX512BW_H
#  endif
#  include "avx512f.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS

#  if defined(SIMDE_AVX512BW_NATIVE)
#    undef SIMDE_AVX512BW_NATIVE
#  endif
#  if defined(SIMDE_ARCH_X86_AVX512BW) && !defined(SIMDE_AVX512BW_NO_NATIVE) && !defined(SIMDE_NO_NATIVE)
#    define SIMDE_AVX512BW_NATIVE
#  elif defined(SIMDE_ARCH_ARM_NEON) && !defined(SIMDE_AVX512BW_NO_NEON) && !defined(SIMDE_NO_NEON)
#    define SIMDE_AVX512BW_NEON
#  elif defined(SIMDE_ARCH_POWER_ALTIVEC)
#    define SIMDE_AVX512BW_POWER_ALTIVEC
#  endif

#  if defined(SIMDE_AVX512BW_NATIVE)
#    include <immintrin.h>
#  endif

#  if defined(SIMDE_AVX512BW_POWER_ALTIVEC)
#    include <altivec.h>
#  endif

SIMDE__BEGIN_DECLS

SIMDE__FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_add_epi8 (simde__m512i a, simde__m512i b) {
#if defined(SIMDE_AVX512BW_NATIVE)
  return _mm512_add_epi8(a, b);
#else
  simde__m512i_private
    r_,
    a_ = simde__m512i_to_private(a),
    b_ = simde__m512i_to_private(b);

#if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
  r_.i8 = a_.i8 + b_.i8;
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.m256i) / sizeof(r_.m256i[0])) ; i++) {
    r_.m256i[i] = simde_mm256_add_epi8(a_.m256i[i], b_.m256i[i]);
  }
#endif

  return simde__m512i_from_private(r_);
#endif
}
#if defined(SIMDE_AVX2_ENABLE_NATIVE_ALIASES)
#  define _mm512_add_epi8(a, b) simde_mm512_add_epi8(a, b)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_add_epi16 (simde__m512i a, simde__m512i b) {
#if defined(SIMDE_AVX512BW_NATIVE)
  return _mm512_add_epi16(a, b);
#else
  simde__m512i_private
    r_,
    a_ = simde__m512i_to_private(a),
    b_ = simde__m512i_to_private(b);

#if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
  r_.i16 = a_.i16 + b_.i16;
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.m256i) / sizeof(r_.m256i[0])) ; i++) {
    r_.m256i[i] = simde_mm256_add_epi16(a_.m256i[i], b_.m256i[i]);
  }
#endif

  return simde__m512i_from_private(r_);
#endif
}
#if defined(SIMDE_AVX2_ENABLE_NATIVE_ALIASES)
#  define _mm512_add_epi16(a, b) simde_mm512_add_epi16(a, b)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_adds_epu8 (simde__m512i a, simde__m512i b) {
#if defined(SIMDE_AVX512BW_NATIVE)
  return _mm512_adds_epu8(a, b);
#else
  simde__m512i_private
    r_,
    a_ = simde__m512i_to_private(a),
    b_ = simde__m512i_to_private(b);

  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.m256i) / sizeof(r_.m256i[0])) ; i++) {
    r_.m256i[i] = simde_mm256_adds_epu8(a_.m256i[i], b_.m256i[i]);
  }

  return simde__m512i_from_private(r_);
#endif
}
#if defined(SIMDE_AVX512BW_ENABLE_NATIVE_ALIASES)
#  define _mm512_adds_epu8(a, b) simde_mm512_adds_epu8(a, b)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_adds_epu16 (simde__m512i a, simde__m512i b) {
#if defined(SIMDE_AVX512BW_NATIVE)
  return _mm512_adds_epu16(a, b);
#else
  simde__m512i_private
    r_,
    a_ = simde__m512i_to_private(a),
    b_ = simde__m512i_to_private(b);

  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.m256i) / sizeof(r_.m256i[0])) ; i++) {
    r_.m256i[i] = simde_mm256_adds_epu16(a_.m256i[i], b_.m256i[i]);
  }

  return simde__m512i_from_private(r_);
#endif
}
#if defined(SIMDE_AVX512BW_ENABLE_NATIVE_ALIASES)
#  define _mm512_adds_epu16(a, b) simde_mm512_adds_epu16(a, b)
#endif

SIMDE__END_DECLS

HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE__AVX512BW_H) */
