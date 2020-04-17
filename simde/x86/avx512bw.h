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

#if !defined(SIMDE_AVX512BW_NATIVE) && defined(SIMDE_ENABLE_NATIVE_ALIASES)
  #define SIMDE_AVX512BW_ENABLE_NATIVE_ALIASES
#endif

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
#if defined(SIMDE_AVX512BW_ENABLE_NATIVE_ALIASES)
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
#if defined(SIMDE_AVX512BW_ENABLE_NATIVE_ALIASES)
#  define _mm512_add_epi16(a, b) simde_mm512_add_epi16(a, b)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_adds_epi8 (simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_AVX512BW_NATIVE)
    return _mm512_adds_epi8(a, b);
  #else
    simde__m512i_private
      r_,
      a_ = simde__m512i_to_private(a),
      b_ = simde__m512i_to_private(b);

    #if !defined(HEDLEY_INTEL_VERSION)
      SIMDE__VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.m256i) / sizeof(r_.m256i[0])) ; i++) {
        r_.m256i[i] = simde_mm256_adds_epi8(a_.m256i[i], b_.m256i[i]);
      }
    #else
      SIMDE__VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.i8) / sizeof(r_.i8[0])) ; i++) {
        const int16_t tmp =
          HEDLEY_STATIC_CAST(int16_t, a_.i8[i]) +
          HEDLEY_STATIC_CAST(int16_t, b_.i8[i]);
        r_.i8[i] = HEDLEY_STATIC_CAST(int8_t, ((tmp < INT8_MAX) ? ((tmp > INT8_MIN) ? tmp : INT8_MIN) : INT8_MAX));
      }
    #endif

    return simde__m512i_from_private(r_);
  #endif
}
#if defined(SIMDE_AVX512BW_ENABLE_NATIVE_ALIASES)
#  define _mm512_adds_epi8(a, b) simde_mm512_adds_epi8(a, b)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_adds_epi16 (simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_AVX512BW_NATIVE)
    return _mm512_adds_epi16(a, b);
  #else
    simde__m512i_private
      r_,
      a_ = simde__m512i_to_private(a),
      b_ = simde__m512i_to_private(b);

      #if !defined(HEDLEY_INTEL_VERSION)
        SIMDE__VECTORIZE
        for (size_t i = 0 ; i < (sizeof(r_.m256i) / sizeof(r_.m256i[0])) ; i++) {
          r_.m256i[i] = simde_mm256_adds_epi16(a_.m256i[i], b_.m256i[i]);
        }
      #else
        SIMDE__VECTORIZE
        for (size_t i = 0 ; i < (sizeof(r_.i16) / sizeof(r_.i16[0])) ; i++) {
          const int32_t tmp =
            HEDLEY_STATIC_CAST(int32_t, a_.i16[i]) +
            HEDLEY_STATIC_CAST(int32_t, b_.i16[i]);
          r_.i16[i] = HEDLEY_STATIC_CAST(int32_t, ((tmp < INT16_MAX) ? ((tmp > INT16_MIN) ? tmp : INT16_MIN) : INT16_MAX));
        }
      #endif

    return simde__m512i_from_private(r_);
  #endif
}
#if defined(SIMDE_AVX512BW_ENABLE_NATIVE_ALIASES)
#  define _mm512_adds_epi16(a, b) simde_mm512_adds_epi16(a, b)
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

    #if !defined(HEDLEY_INTEL_VERSION)
      SIMDE__VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.m128i) / sizeof(r_.m128i[0])) ; i++) {
        r_.m128i[i] = simde_mm_adds_epu8(a_.m128i[i], b_.m128i[i]);
      }
    #else
      SIMDE__VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.u8) / sizeof(r_.u8[0])) ; i++) {
        r_.u8[i] = ((UINT8_MAX - a_.u8[i]) > b_.u8[i]) ? (a_.u8[i] + b_.u8[i]) : UINT8_MAX;
      }
    #endif

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

    #if !defined(HEDLEY_INTEL_VERSION)
      SIMDE__VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.m256i) / sizeof(r_.m256i[0])) ; i++) {
        r_.m256i[i] = simde_mm256_adds_epu16(a_.m256i[i], b_.m256i[i]);
      }
    #else
      SIMDE__VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.u16) / sizeof(r_.u16[0])) ; i++) {
        r_.u16[i] = ((UINT16_MAX - a_.u16[i]) > b_.u16[i]) ? (a_.u16[i] + b_.u16[i]) : UINT16_MAX;
      }
    #endif

    return simde__m512i_from_private(r_);
  #endif
}
#if defined(SIMDE_AVX512BW_ENABLE_NATIVE_ALIASES)
#  define _mm512_adds_epu16(a, b) simde_mm512_adds_epu16(a, b)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_shuffle_epi8 (simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_AVX512BW_NATIVE)
    return _mm512_shuffle_epi8(a, b);
  #else
    simde__m512i_private
      r_,
      a_ = simde__m512i_to_private(a),
      b_ = simde__m512i_to_private(b);

  #if defined(SIMDE_ARCH_X86_AVX2)
    r_.m256i[0] = simde_mm256_shuffle_epi8(a_.m256i[0], b_.m256i[0]);
    r_.m256i[1] = simde_mm256_shuffle_epi8(a_.m256i[1], b_.m256i[1]);
  #elif defined(SIMDE_ARCH_X86_SSSE3)
    r_.m128i[0] = simde_mm_shuffle_epi8(a_.m128i[0], b_.m128i[0]);
    r_.m128i[1] = simde_mm_shuffle_epi8(a_.m128i[1], b_.m128i[1]);
    r_.m128i[2] = simde_mm_shuffle_epi8(a_.m128i[2], b_.m128i[2]);
    r_.m128i[3] = simde_mm_shuffle_epi8(a_.m128i[3], b_.m128i[3]);
  #else
  SIMDE__VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.u8) / sizeof(r_.u8[0])) ; i++) {
      r_.u8[i] = (b_.u8[i] & 0x80) ? 0 : a_.u8[(b_.u8[i] & 0x0f) + (i & 0x30)];
    }
  #endif

  return simde__m512i_from_private(r_);
#endif
}
#if defined(SIMDE_AVX512BW_ENABLE_NATIVE_ALIASES)
#  define _mm512_shuffle_epi8(a, b) simde_mm512_shuffle_epi8(a, b)
#endif


SIMDE__FUNCTION_ATTRIBUTES
simde__mmask64
simde_mm512_cmpeq_epi8_mask (simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_AVX512BW_NATIVE)
    return _mm512_cmpeq_epi8_mask(a, b);
  #else
    simde__m512i_private
      a_ = simde__m512i_to_private(a),
      b_ = simde__m512i_to_private(b);

    #if defined(SIMDE_ARCH_X86_AVX2)
      simde__mmask64 r_;

      // The second cast is absolutely necessary otherwise if the sign bit is set it will be sign extended to 64 bits
      r_ =              (uint32_t) simde_mm256_movemask_epi8(simde_mm256_cmpeq_epi8(a_.m256i[1], b_.m256i[1]));
      r_ = (r_ << 32) | (uint32_t) simde_mm256_movemask_epi8(simde_mm256_cmpeq_epi8(a_.m256i[0], b_.m256i[0]));
    #elif defined(SIMDE_ARCH_X86_SSE2)
      simde__mmask64 r_;

      r_ =              simde_mm_movemask_epi8(simde_mm_cmpeq_epi8(a_.m128i[3], b_.m128i[3]));
      r_ = (r_ << 16) | simde_mm_movemask_epi8(simde_mm_cmpeq_epi8(a_.m128i[2], b_.m128i[2]));
      r_ = (r_ << 16) | simde_mm_movemask_epi8(simde_mm_cmpeq_epi8(a_.m128i[1], b_.m128i[1]));
      r_ = (r_ << 16) | simde_mm_movemask_epi8(simde_mm_cmpeq_epi8(a_.m128i[0], b_.m128i[0]));
    #else
      simde__mmask64 r_ = 0;

      for (size_t i = 0 ; i < (sizeof(a_.u8) / sizeof(a_.u8[0])) ; i++) {
        r_ |= (a_.u8[i] == b_.u8[i]) ? (1ULL << i) : 0;
      }
  #endif

    return r_;
  #endif
}
#if defined(SIMDE_AVX512BW_ENABLE_NATIVE_ALIASES)
#  define _mm512_cmpeq_epi8_mask(a, b) simde_mm512_cmpeq_epi8_mask(a, b)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m256i
simde_mm512_cvtepi16_epi8 (simde__m512i a) {
  #if defined(SIMDE_AVX512BW_NATIVE)
    return _mm512_cvtepi16_epi8(a);
  #else
    simde__m256i_private r_;
    simde__m512i_private a_ = simde__m512i_to_private(a);

    #if defined(SIMDE__CONVERT_VECTOR)
      SIMDE__CONVERT_VECTOR(r_.i8, a_.i16);
    #else
      SIMDE__VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.i8) / sizeof(r_.i8[0])) ; i++) {
        r_.i8[i] = HEDLEY_STATIC_CAST(int8_t, a_.i16[i]);
      }
    #endif

    return simde__m256i_from_private(r_);
  #endif
}
#if defined(SIMDE_AVX512BW_ENABLE_NATIVE_ALIASES)
#  define _mm512_cvtepi16_epi8(a) simde_mm512_cvtepi16_epi8(a)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_cvtepi8_epi16 (simde__m256i a) {
  #if defined(SIMDE_AVX512BW_NATIVE)
    return _mm512_cvtepi8_epi16(a);
  #else
    simde__m512i_private r_;
    simde__m256i_private a_ = simde__m256i_to_private(a);

    #if defined(SIMDE__CONVERT_VECTOR)
      SIMDE__CONVERT_VECTOR(r_.i16, a_.i8);
    #else
      SIMDE__VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.i16) / sizeof(r_.i16[0])) ; i++) {
        r_.i16[i] = a_.i8[i];
      }
    #endif

    return simde__m512i_from_private(r_);
  #endif
}
#if defined(SIMDE_AVX512BW_ENABLE_NATIVE_ALIASES)
#  define _mm512_cvtepi8_epi16(a) simde_mm512_cvtepi8_epi16(a)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m256i
simde_mm512_cvtsepi16_epi8 (simde__m512i a) {
  #if defined(SIMDE_AVX512VL_NATIVE) && defined(SIMDE_AVX512BW_NATIVE)
    return _mm512_cvtsepi16_epi8(a);
  #else
    simde__m256i_private r_;
    simde__m512i_private a_ = simde__m512i_to_private(a);

    SIMDE__VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.i8) / sizeof(r_.i8[0])) ; i++) {
      r_.i8[i] =
          (a_.i16[i] < INT8_MIN)
            ? (INT8_MIN)
            : ((a_.i16[i] > INT8_MAX)
              ? (INT8_MAX)
              : HEDLEY_STATIC_CAST(int8_t, a_.i16[i]));
    }

    return simde__m256i_from_private(r_);
  #endif
}
#if defined(SIMDE_AVX512VL_ENABLE_NATIVE_ALIASES)
  #define _mm512_cvtsepi16_epi8(a) simde_mm512_cvtsepi16_epi8(a)
#endif

SIMDE__END_DECLS

HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE__AVX512BW_H) */
