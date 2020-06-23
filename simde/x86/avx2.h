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
 *   2018-2020 Evan Nemerson <evan@nemerson.com>
 *   2019      Michael R. Crusoe <michael.crusoe@gmail.com>
 *   2020      Himanshi Mathur <himanshi18037@iiitd.ac.in>
 *   2020      Hidayat Khan <huk2209@gmail.com>
 */

#if !defined(SIMDE_X86_AVX2_H)
#define SIMDE_X86_AVX2_H

#include "avx.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_abs_epi8 (simde__m256i a) {
#if defined(SIMDE_X86_AVX2_NATIVE)
  return _mm256_abs_epi8(a);
#else
  simde__m256i_private
    r_,
    a_ = simde__m256i_to_private(a);

  SIMDE_VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.i8) / sizeof(r_.i8[0])) ; i++) {
    r_.i8[i] = (a_.i8[i] < INT32_C(0)) ? -a_.i8[i] : a_.i8[i];
  }

  return simde__m256i_from_private(r_);
#endif
}
#if defined(SIMDE_X86_AVX2_ENABLE_NATIVE_ALIASES)
  #undef _mm256_abs_epi8
  #define _mm256_abs_epi8(a) simde_mm256_abs_epi8(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_abs_epi16 (simde__m256i a) {
#if defined(SIMDE_X86_AVX2_NATIVE)
  return _mm256_abs_epi16(a);
#else
  simde__m256i_private
    r_,
    a_ = simde__m256i_to_private(a);

  SIMDE_VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.i16) / sizeof(r_.i16[0])) ; i++) {
    r_.i16[i] = (a_.i16[i] < INT32_C(0)) ? -a_.i16[i] : a_.i16[i];
  }

  return simde__m256i_from_private(r_);
#endif
}
#if defined(SIMDE_X86_AVX2_ENABLE_NATIVE_ALIASES)
  #undef _mm256_abs_epi16
  #define _mm256_abs_epi16(a) simde_mm256_abs_epi16(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_abs_epi32(simde__m256i a) {
#if defined(SIMDE_X86_AVX2_NATIVE)
  return _mm256_abs_epi32(a);
#else
  simde__m256i_private
    r_,
    a_ = simde__m256i_to_private(a);

  SIMDE_VECTORIZE
  for (size_t i = 0; i < (sizeof(r_.i32) / sizeof(r_.i32[0])); i++) {
    r_.i32[i] = (a_.i32[i] < INT32_C(0)) ? -a_.i32[i] : a_.i32[i];
  }

  return simde__m256i_from_private(r_);
#endif
}
#if defined(SIMDE_X86_AVX2_ENABLE_NATIVE_ALIASES)
  #undef _mm256_abs_epi32
  #define _mm256_abs_epi32(a) simde_mm256_abs_epi32(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_add_epi8 (simde__m256i a, simde__m256i b) {
#if defined(SIMDE_X86_AVX2_NATIVE)
  return _mm256_add_epi8(a, b);
#else
  simde__m256i_private
    r_,
    a_ = simde__m256i_to_private(a),
    b_ = simde__m256i_to_private(b);

#if defined(SIMDE_X86_SSE2_NATIVE)
  r_.m128i[0] = simde_mm_add_epi8(a_.m128i[0], b_.m128i[0]);
  r_.m128i[1] = simde_mm_add_epi8(a_.m128i[1], b_.m128i[1]);
#elif defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
  r_.i8 = a_.i8 + b_.i8;
#else
  SIMDE_VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.i8) / sizeof(r_.i8[0])) ; i++) {
    r_.i8[i] = a_.i8[i] + b_.i8[i];
  }
#endif

  return simde__m256i_from_private(r_);
#endif
}
#if defined(SIMDE_X86_AVX2_ENABLE_NATIVE_ALIASES)
  #undef _mm256_add_epi8
  #define _mm256_add_epi8(a, b) simde_mm256_add_epi8(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_add_epi16 (simde__m256i a, simde__m256i b) {
#if defined(SIMDE_X86_AVX2_NATIVE)
  return _mm256_add_epi16(a, b);
#else
  simde__m256i_private
    r_,
    a_ = simde__m256i_to_private(a),
    b_ = simde__m256i_to_private(b);

#if defined(SIMDE_X86_SSE2_NATIVE)
  r_.m128i[0] = simde_mm_add_epi16(a_.m128i[0], b_.m128i[0]);
  r_.m128i[1] = simde_mm_add_epi16(a_.m128i[1], b_.m128i[1]);
#elif defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
  r_.i16 = a_.i16 + b_.i16;
#else
  SIMDE_VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.i16) / sizeof(r_.i16[0])) ; i++) {
    r_.i16[i] = a_.i16[i] + b_.i16[i];
  }
#endif

  return simde__m256i_from_private(r_);
#endif
}
#if defined(SIMDE_X86_AVX2_ENABLE_NATIVE_ALIASES)
  #undef _mm256_add_epi16
  #define _mm256_add_epi16(a, b) simde_mm256_add_epi16(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_add_epi32 (simde__m256i a, simde__m256i b) {
#if defined(SIMDE_X86_AVX2_NATIVE)
  return _mm256_add_epi32(a, b);
#else
  simde__m256i_private
    r_,
    a_ = simde__m256i_to_private(a),
    b_ = simde__m256i_to_private(b);

#if defined(SIMDE_X86_SSE2_NATIVE)
  r_.m128i[0] = simde_mm_add_epi32(a_.m128i[0], b_.m128i[0]);
  r_.m128i[1] = simde_mm_add_epi32(a_.m128i[1], b_.m128i[1]);
#elif defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
  r_.i32 = a_.i32 + b_.i32;
#else
  SIMDE_VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.i32) / sizeof(r_.i32[0])) ; i++) {
    r_.i32[i] = a_.i32[i] + b_.i32[i];
  }
#endif

  return simde__m256i_from_private(r_);
#endif
}
#if defined(SIMDE_X86_AVX2_ENABLE_NATIVE_ALIASES)
  #undef _mm256_add_epi32
  #define _mm256_add_epi32(a, b) simde_mm256_add_epi32(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_add_epi64 (simde__m256i a, simde__m256i b) {
#if defined(SIMDE_X86_AVX2_NATIVE)
  return _mm256_add_epi64(a, b);
#else
  simde__m256i_private
    r_,
    a_ = simde__m256i_to_private(a),
    b_ = simde__m256i_to_private(b);

#if defined(SIMDE_X86_SSE2_NATIVE)
  r_.m128i[0] = simde_mm_add_epi64(a_.m128i[0], b_.m128i[0]);
  r_.m128i[1] = simde_mm_add_epi64(a_.m128i[1], b_.m128i[1]);
#elif defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
  r_.i64 = a_.i64 + b_.i64;
#else
  SIMDE_VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.i64) / sizeof(r_.i64[0])) ; i++) {
    r_.i64[i] = a_.i64[i] + b_.i64[i];
  }
#endif

  return simde__m256i_from_private(r_);
#endif
}
#if defined(SIMDE_X86_AVX2_ENABLE_NATIVE_ALIASES)
  #undef _mm256_add_epi64
  #define _mm256_add_epi64(a, b) simde_mm256_add_epi64(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_alignr_epi8 (simde__m256i a, simde__m256i b, int count) {
  simde__m256i_private
    r_,
    a_ = simde__m256i_to_private(a),
    b_ = simde__m256i_to_private(b);

  if (HEDLEY_UNLIKELY(count > 31))
    return simde_mm256_setzero_si256();

  for (size_t h = 0 ; h < (sizeof(r_.m128i) / sizeof(r_.m128i[0])) ; h++) {
    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.m128i_private[h].i8) / sizeof(r_.m128i_private[h].i8[0])) ; i++) {
      const int srcpos = count + HEDLEY_STATIC_CAST(int, i);
      if (srcpos > 31) {
        r_.m128i_private[h].i8[i] = 0;
      } else if (srcpos > 15) {
        r_.m128i_private[h].i8[i] = a_.m128i_private[h].i8[(srcpos) & 15];
      } else {
        r_.m128i_private[h].i8[i] = b_.m128i_private[h].i8[srcpos];
      }
    }
  }

  return simde__m256i_from_private(r_);
}
#if defined(SIMDE_X86_AVX2_NATIVE)
#  define simde_mm256_alignr_epi8(a, b, count) _mm256_alignr_epi8(a, b, count)
#elif defined(SIMDE_X86_SSSE3_NATIVE)
#  define simde_mm256_alignr_epi8(a, b, count) \
      simde_mm256_set_m128i( \
          simde_mm_alignr_epi8(simde_mm256_extracti128_si256(a, 1), simde_mm256_extracti128_si256(b, 1), (count)), \
          simde_mm_alignr_epi8(simde_mm256_extracti128_si256(a, 0), simde_mm256_extracti128_si256(b, 0), (count)))
#endif
#if defined(SIMDE_X86_AVX2_ENABLE_NATIVE_ALIASES)
  #undef _mm256_alignr_epi8
  #define _mm256_alignr_epi8(a, b, count) simde_mm256_alignr_epi8(a, b, (count))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_and_si256 (simde__m256i a, simde__m256i b) {
#if defined(SIMDE_X86_AVX2_NATIVE)
  return _mm256_and_si256(a, b);
#else
  simde__m256i_private
    r_,
    a_ = simde__m256i_to_private(a),
    b_ = simde__m256i_to_private(b);

#if defined(SIMDE_X86_SSE2_NATIVE)
  r_.m128i[0] = simde_mm_and_si128(a_.m128i[0], b_.m128i[0]);
  r_.m128i[1] = simde_mm_and_si128(a_.m128i[1], b_.m128i[1]);
#elif defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
  r_.i32f = a_.i32f & b_.i32f;
#else
  SIMDE_VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.i64) / sizeof(r_.i64[0])) ; i++) {
    r_.i64[i] = a_.i64[i] & b_.i64[i];
  }
#endif

  return simde__m256i_from_private(r_);
#endif
}
#if defined(SIMDE_X86_AVX2_ENABLE_NATIVE_ALIASES)
  #undef _mm256_and_si256
  #define _mm256_and_si256(a, b) simde_mm256_and_si256(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_andnot_si256 (simde__m256i a, simde__m256i b) {
#if defined(SIMDE_X86_AVX2_NATIVE)
  return _mm256_andnot_si256(a, b);
#else
  simde__m256i_private
    r_,
    a_ = simde__m256i_to_private(a),
    b_ = simde__m256i_to_private(b);

#if defined(SIMDE_X86_SSE2_NATIVE) || defined(SIMDE_ARM_NEON_A32V7_NATIVE)
  r_.m128i_private[0] = simde__m128i_to_private(simde_mm_andnot_si128(simde__m128i_from_private(a_.m128i_private[0]), simde__m128i_from_private(b_.m128i_private[0])));
  r_.m128i_private[1] = simde__m128i_to_private(simde_mm_andnot_si128(simde__m128i_from_private(a_.m128i_private[1]), simde__m128i_from_private(b_.m128i_private[1])));
#else
  SIMDE_VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.i32f) / sizeof(r_.i32f[0])) ; i++) {
    r_.i32f[i] = ~(a_.i32f[i]) & b_.i32f[i];
  }
#endif

  return simde__m256i_from_private(r_);
#endif
}
#if defined(SIMDE_X86_AVX2_ENABLE_NATIVE_ALIASES)
  #undef _mm256_andnot_si256
  #define _mm256_andnot_si256(a, b) simde_mm256_andnot_si256(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_adds_epi8 (simde__m256i a, simde__m256i b) {
#if defined(SIMDE_X86_AVX2_NATIVE)
  return _mm256_adds_epi8(a, b);
#else
  simde__m256i_private
    r_,
    a_ = simde__m256i_to_private(a),
    b_ = simde__m256i_to_private(b);

  #if defined(SIMDE_X86_SSE2_NATIVE) && !defined(HEDLEY_INTEL_VERSION)
    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.m128i) / sizeof(r_.m128i[0])) ; i++) {
      r_.m128i[i] = simde_mm_adds_epi8(a_.m128i[i], b_.m128i[i]);
    }
  #else
    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.i8) / sizeof(r_.i8[0])) ; i++) {
      const int32_t tmp =
        HEDLEY_STATIC_CAST(int16_t, a_.i8[i]) +
        HEDLEY_STATIC_CAST(int16_t, b_.i8[i]);
      r_.i8[i] = HEDLEY_STATIC_CAST(int8_t, ((tmp < INT8_MAX) ? ((tmp > INT8_MIN) ? tmp : INT8_MIN) : INT8_MAX));
    }
  #endif

  return simde__m256i_from_private(r_);
#endif
}
#if defined(SIMDE_X86_AVX2_ENABLE_NATIVE_ALIASES)
  #undef _mm256_adds_epi8
  #define _mm256_adds_epi8(a, b) simde_mm256_adds_epi8(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_adds_epi16(simde__m256i a, simde__m256i b) {
#if defined(SIMDE_X86_AVX2_NATIVE)
  return _mm256_adds_epi16(a, b);
#else
  simde__m256i_private
    r_,
    a_ = simde__m256i_to_private(a),
    b_ = simde__m256i_to_private(b);

  #if defined(SIMDE_X86_SSE2_NATIVE) && !defined(HEDLEY_INTEL_VERSION)
    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.m128i) / sizeof(r_.m128i[0])) ; i++) {
      r_.m128i[i] = simde_mm_adds_epi16(a_.m128i[i], b_.m128i[i]);
    }
  #else
    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.i16) / sizeof(r_.i16[0])) ; i++) {
      const int32_t tmp =
        HEDLEY_STATIC_CAST(int32_t, a_.i16[i]) +
        HEDLEY_STATIC_CAST(int32_t, b_.i16[i]);
      r_.i16[i] = HEDLEY_STATIC_CAST(int16_t, ((tmp < INT16_MAX) ? ((tmp > INT16_MIN) ? tmp : INT16_MIN) : INT16_MAX));
    }
  #endif

  return simde__m256i_from_private(r_);
#endif
}
#if defined(SIMDE_X86_AVX2_ENABLE_NATIVE_ALIASES)
  #undef _mm256_adds_epi16
  #define _mm256_adds_epi16(a, b) simde_mm256_adds_epi16(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_adds_epu8 (simde__m256i a, simde__m256i b) {
#if defined(SIMDE_X86_AVX2_NATIVE)
  return _mm256_adds_epu8(a, b);
#else
  simde__m256i_private
    r_,
    a_ = simde__m256i_to_private(a),
    b_ = simde__m256i_to_private(b);

#if defined(SIMDE_X86_SSE2_NATIVE)
  r_.m128i[0] = simde_mm_adds_epu8(a_.m128i[0], b_.m128i[0]);
  r_.m128i[1] = simde_mm_adds_epu8(a_.m128i[1], b_.m128i[1]);
#else
  SIMDE_VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.u8) / sizeof(r_.u8[0])) ; i++) {
    r_.u8[i] = ((UINT8_MAX - a_.u8[i]) > b_.u8[i]) ? (a_.u8[i] + b_.u8[i]) : UINT8_MAX;
  }
#endif

  return simde__m256i_from_private(r_);
#endif
}
#if defined(SIMDE_X86_AVX2_ENABLE_NATIVE_ALIASES)
  #undef _mm256_adds_epu8
  #define _mm256_adds_epu8(a, b) simde_mm256_adds_epu8(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_adds_epu16(simde__m256i a, simde__m256i b) {
#if defined(SIMDE_X86_AVX2_NATIVE)
  return _mm256_adds_epu16(a, b);
#else
  simde__m256i_private
    r_,
    a_ = simde__m256i_to_private(a),
    b_ = simde__m256i_to_private(b);

#if defined(SIMDE_X86_SSE2_NATIVE)
  r_.m128i[0] = simde_mm_adds_epu16(a_.m128i[0], b_.m128i[0]);
  r_.m128i[1] = simde_mm_adds_epu16(a_.m128i[1], b_.m128i[1]);
#else
  SIMDE_VECTORIZE
for (size_t i = 0 ; i < (sizeof(r_.u16) / sizeof(r_.u16[0])) ; i++) {
  r_.u16[i] = ((UINT16_MAX - a_.u16[i]) > b_.u16[i]) ? (a_.u16[i] + b_.u16[i]) : UINT16_MAX;
}
#endif

  return simde__m256i_from_private(r_);
#endif
}
#if defined(SIMDE_X86_AVX2_ENABLE_NATIVE_ALIASES)
  #undef _mm256_adds_epu16
  #define _mm256_adds_epu16(a, b) simde_mm256_adds_epu16(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_avg_epu8 (simde__m256i a, simde__m256i b) {
#if defined(SIMDE_X86_AVX2_NATIVE)
  return _mm256_avg_epu8(a, b);
#else
  simde__m256i_private
    r_,
    a_ = simde__m256i_to_private(a),
    b_ = simde__m256i_to_private(b);

  SIMDE_VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.u8) / sizeof(r_.u8[0])) ; i++) {
    r_.u8[i] = (a_.u8[i] + b_.u8[i] + 1) >> 1;
  }

  return simde__m256i_from_private(r_);
#endif
}
#if defined(SIMDE_X86_AVX2_ENABLE_NATIVE_ALIASES)
  #undef _mm256_avg_epu8
  #define _mm256_avg_epu8(a, b) simde_mm256_avg_epu8(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_avg_epu16 (simde__m256i a, simde__m256i b) {
#if defined(SIMDE_X86_AVX2_NATIVE)
  return _mm256_avg_epu16(a, b);
#else
  simde__m256i_private
    r_,
    a_ = simde__m256i_to_private(a),
    b_ = simde__m256i_to_private(b);

  SIMDE_VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.u16) / sizeof(r_.u16[0])) ; i++) {
    r_.u16[i] = (a_.u16[i] + b_.u16[i] + 1) >> 1;
  }

  return simde__m256i_from_private(r_);
#endif
}
#if defined(SIMDE_X86_AVX2_ENABLE_NATIVE_ALIASES)
  #undef _mm256_avg_epu16
  #define _mm256_avg_epu16(a, b) simde_mm256_avg_epu16(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_blend_epi32(simde__m128i a, simde__m128i b, const int imm8)
    SIMDE_REQUIRE_RANGE(imm8, 0, 255) {
  simde__m128i_private
    r_,
    a_ = simde__m128i_to_private(a),
    b_ = simde__m128i_to_private(b);

  SIMDE_VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.i32) / sizeof(r_.i32[0])) ; i++) {
    r_.i32[i] = ((imm8 >> i) & 1) ? b_.i32[i] : a_.i32[i];
  }

  return simde__m128i_from_private(r_);
}
#if defined(SIMDE_X86_AVX2_NATIVE)
#  define simde_mm_blend_epi32(a, b, imm8) _mm_blend_epi32(a, b, imm8)
#elif defined(SIMDE_X86_SSE4_1_NATIVE) || defined(SIMDE_ARM_NEON_A32V7_NATIVE) || defined(SIMDE_POWER_ALTIVEC_P5_NATIVE)
#  define simde_mm_blend_epi32(a, b, imm8) \
  simde_mm_castps_si128(simde_mm_blend_ps(simde_mm_castsi128_ps(a), simde_mm_castsi128_ps(b), (imm8)))
#endif
#if defined(SIMDE_X86_AVX2_ENABLE_NATIVE_ALIASES)
  #undef _mm_blend_epi32
  #define _mm_blend_epi32(a, b, imm8) simde_mm_blend_epi32(a, b, imm8)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_blend_epi16(simde__m256i a, simde__m256i b, const int imm8)
    SIMDE_REQUIRE_RANGE(imm8, 0, 255) {
  simde__m256i_private
    r_,
    a_ = simde__m256i_to_private(a),
    b_ = simde__m256i_to_private(b);

  SIMDE_VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.i16) / sizeof(r_.i16[0])) ; i++) {
    r_.i16[i] = ((imm8 >> i%8) & 1) ? b_.i16[i] : a_.i16[i];
  }

  return simde__m256i_from_private(r_);
}
#if defined(SIMDE_X86_AVX2_NATIVE)
#  define simde_mm256_blend_epi16(a, b, imm8) _mm256_blend_epi16(a, b, imm8)
#elif defined(SIMDE_X86_SSE4_1_NATIVE) || defined(SIMDE_ARM_NEON_A32V7_NATIVE) || defined(SIMDE_POWER_ALTIVEC_P5_NATIVE)
#  define simde_mm256_blend_epi16(a, b, imm8) \
      simde_mm256_set_m128i( \
          simde_mm_blend_epi16(simde_mm256_extracti128_si256(a, 1), simde_mm256_extracti128_si256(b, 1), (imm8)), \
          simde_mm_blend_epi16(simde_mm256_extracti128_si256(a, 0), simde_mm256_extracti128_si256(b, 0), (imm8)))
#endif
#if defined(SIMDE_X86_AVX2_ENABLE_NATIVE_ALIASES)
  #undef _mm256_blend_epi16
  #define _mm256_blend_epi16(a, b, imm8) simde_mm256_blend_epi16(a, b, imm8)
#endif


SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_blend_epi32(simde__m256i a, simde__m256i b, const int imm8)
    SIMDE_REQUIRE_RANGE(imm8, 0, 255) {
  simde__m256i_private
    r_,
    a_ = simde__m256i_to_private(a),
    b_ = simde__m256i_to_private(b);

  SIMDE_VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.i32) / sizeof(r_.i32[0])) ; i++) {
    r_.i32[i] = ((imm8 >> i) & 1) ? b_.i32[i] : a_.i32[i];
  }

  return simde__m256i_from_private(r_);
}
#if defined(SIMDE_X86_AVX2_NATIVE)
#  define simde_mm256_blend_epi32(a, b, imm8) _mm256_blend_epi32(a, b, imm8)
#elif defined(SIMDE_X86_SSE4_1_NATIVE) || defined(SIMDE_ARM_NEON_A32V7_NATIVE) || defined(SIMDE_POWER_ALTIVEC_P5_NATIVE)
#  define simde_mm256_blend_epi32(a, b, imm8) \
      simde_mm256_set_m128i( \
          simde_mm_blend_epi32(simde_mm256_extracti128_si256(a, 1), simde_mm256_extracti128_si256(b, 1), (imm8) >> 4), \
          simde_mm_blend_epi32(simde_mm256_extracti128_si256(a, 0), simde_mm256_extracti128_si256(b, 0), (imm8) & 0x0F))
#endif
#if defined(SIMDE_X86_AVX2_ENABLE_NATIVE_ALIASES)
  #undef _mm256_blend_epi32
  #define _mm256_blend_epi32(a, b, imm8) simde_mm256_blend_epi32(a, b, imm8)
#endif


SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_blendv_epi8(simde__m256i a, simde__m256i b, simde__m256i mask) {
#if defined(SIMDE_X86_AVX2_NATIVE)
  return _mm256_blendv_epi8(a, b, mask);
#else
  simde__m256i_private
    r_,
    a_ = simde__m256i_to_private(a),
    b_ = simde__m256i_to_private(b),
    mask_ = simde__m256i_to_private(mask);

#if defined(SIMDE_X86_SSE4_1_NATIVE) || defined(SIMDE_ARM_NEON_A32V7_NATIVE) || defined(SIMDE_POWER_ALTIVEC_P5_NATIVE)
  r_.m128i_private[0] = simde__m128i_to_private(simde_mm_blendv_epi8(simde__m128i_from_private(a_.m128i_private[0]), simde__m128i_from_private(b_.m128i_private[0]), simde__m128i_from_private(mask_.m128i_private[0])));
  r_.m128i_private[1] = simde__m128i_to_private(simde_mm_blendv_epi8(simde__m128i_from_private(a_.m128i_private[1]), simde__m128i_from_private(b_.m128i_private[1]), simde__m128i_from_private(mask_.m128i_private[1])));
#else
  SIMDE_VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.u8) / sizeof(r_.u8[0])) ; i++) {
    if (mask_.u8[i] & 0x80) {
      r_.u8[i] = b_.u8[i];
    } else {
      r_.u8[i] = a_.u8[i];
    }
  }
#endif

  return simde__m256i_from_private(r_);
#endif
}
#if defined(SIMDE_X86_AVX2_NATIVE)
#  define simde_mm256_blendv_epi8(a, b, imm8)  _mm256_blendv_epi8(a, b, imm8)
#endif
#if defined(SIMDE_X86_AVX2_ENABLE_NATIVE_ALIASES)
  #undef _mm256_blendv_epi8
  #define _mm256_blendv_epi8(a, b, mask) simde_mm256_blendv_epi8(a, b, mask)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_broadcastb_epi8 (simde__m128i a) {
#if defined(SIMDE_X86_AVX2_NATIVE)
  return _mm_broadcastb_epi8(a);
#else
  simde__m128i_private r_;
  simde__m128i_private a_= simde__m128i_to_private(a);

  SIMDE_VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.i8) / sizeof(r_.i8[0])) ; i++) {
    r_.i8[i] = a_.i8[0];
  }

  return simde__m128i_from_private(r_);
#endif
}
#if defined(SIMDE_X86_AVX2_ENABLE_NATIVE_ALIASES)
  #undef _mm_broadcastb_epi8
  #define _mm_broadcastb_epi8(a) simde_mm_broadcastb_epi8(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_broadcastb_epi8 (simde__m128i a) {
#if defined(SIMDE_X86_AVX2_NATIVE)
  return _mm256_broadcastb_epi8(a);
#else
  simde__m256i_private r_;
  simde__m128i_private a_= simde__m128i_to_private(a);

  SIMDE_VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.i8) / sizeof(r_.i8[0])) ; i++) {
    r_.i8[i] = a_.i8[0];
  }

  return simde__m256i_from_private(r_);
#endif
}
#if defined(SIMDE_X86_AVX2_ENABLE_NATIVE_ALIASES)
  #undef _mm256_broadcastb_epi8
  #define _mm256_broadcastb_epi8(a) simde_mm256_broadcastb_epi8(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_broadcastw_epi16 (simde__m128i a) {
#if defined(SIMDE_X86_AVX2_NATIVE)
  return _mm_broadcastw_epi16(a);
#else
  simde__m128i_private r_;
  simde__m128i_private a_= simde__m128i_to_private(a);

  SIMDE_VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.i16) / sizeof(r_.i16[0])) ; i++) {
    r_.i16[i] = a_.i16[0];
  }

  return simde__m128i_from_private(r_);
#endif
}
#if defined(SIMDE_X86_AVX2_ENABLE_NATIVE_ALIASES)
  #undef _mm_broadcastw_epi16
  #define _mm_broadcastw_epi16(a) simde_mm_broadcastw_epi16(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_broadcastw_epi16 (simde__m128i a) {
#if defined(SIMDE_X86_AVX2_NATIVE)
  return _mm256_broadcastw_epi16(a);
#else
  simde__m256i_private r_;
  simde__m128i_private a_= simde__m128i_to_private(a);

  SIMDE_VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.i16) / sizeof(r_.i16[0])) ; i++) {
    r_.i16[i] = a_.i16[0];
  }

  return simde__m256i_from_private(r_);
#endif
}
#if defined(SIMDE_X86_AVX2_ENABLE_NATIVE_ALIASES)
  #undef _mm256_broadcastw_epi16
  #define _mm256_broadcastw_epi16(a) simde_mm256_broadcastw_epi16(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_broadcastd_epi32 (simde__m128i a) {
#if defined(SIMDE_X86_AVX2_NATIVE)
  return _mm_broadcastd_epi32(a);
#else
  simde__m128i_private r_;
  simde__m128i_private a_= simde__m128i_to_private(a);

  SIMDE_VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.i32) / sizeof(r_.i32[0])) ; i++) {
    r_.i32[i] = a_.i32[0];
  }

  return simde__m128i_from_private(r_);
#endif
}
#if defined(SIMDE_X86_AVX2_ENABLE_NATIVE_ALIASES)
  #undef _mm_broadcastd_epi32
  #define _mm_broadcastd_epi32(a) simde_mm_broadcastd_epi32(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_broadcastd_epi32 (simde__m128i a) {
#if defined(SIMDE_X86_AVX2_NATIVE)
  return _mm256_broadcastd_epi32(a);
#else
  simde__m256i_private r_;
  simde__m128i_private a_= simde__m128i_to_private(a);

  SIMDE_VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.i32) / sizeof(r_.i32[0])) ; i++) {
    r_.i32[i] = a_.i32[0];
  }

  return simde__m256i_from_private(r_);
#endif
}
#if defined(SIMDE_X86_AVX2_ENABLE_NATIVE_ALIASES)
  #undef _mm256_broadcastd_epi32
  #define _mm256_broadcastd_epi32(a) simde_mm256_broadcastd_epi32(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_broadcastq_epi64 (simde__m128i a) {
#if defined(SIMDE_X86_AVX2_NATIVE)
  return _mm_broadcastq_epi64(a);
#else
  simde__m128i_private r_;
  simde__m128i_private a_= simde__m128i_to_private(a);

  SIMDE_VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.i64) / sizeof(r_.i64[0])) ; i++) {
    r_.i64[i] = a_.i64[0];
  }

  return simde__m128i_from_private(r_);
#endif
}
#if defined(SIMDE_X86_AVX2_ENABLE_NATIVE_ALIASES)
  #undef _mm_broadcastq_epi64
  #define _mm_broadcastq_epi64(a) simde_mm_broadcastq_epi64(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_broadcastq_epi64 (simde__m128i a) {
#if defined(SIMDE_X86_AVX2_NATIVE)
  return _mm256_broadcastq_epi64(a);
#else
  simde__m256i_private r_;
  simde__m128i_private a_= simde__m128i_to_private(a);

  SIMDE_VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.i64) / sizeof(r_.i64[0])) ; i++) {
    r_.i64[i] = a_.i64[0];
  }

  return simde__m256i_from_private(r_);
#endif
}
#if defined(SIMDE_X86_AVX2_ENABLE_NATIVE_ALIASES)
  #undef _mm256_broadcastq_epi64
  #define _mm256_broadcastq_epi64(a) simde_mm256_broadcastq_epi64(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128
simde_mm_broadcastss_ps (simde__m128 a) {
#if defined(SIMDE_X86_AVX2_NATIVE)
  return _mm_broadcastss_ps(a);
#else
  simde__m128_private r_;
  simde__m128_private a_= simde__m128_to_private(a);

  SIMDE_VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.f32) / sizeof(r_.f32[0])) ; i++) {
    r_.f32[i] = a_.f32[0];
  }

  return simde__m128_from_private(r_);
#endif
}
#if defined(SIMDE_X86_AVX2_ENABLE_NATIVE_ALIASES)
  #undef _mm_broadcastss_ps
  #define _mm_broadcastss_ps(a) simde_mm_broadcastss_ps(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256
simde_mm256_broadcastss_ps (simde__m128 a) {
#if defined(SIMDE_X86_AVX2_NATIVE)
  return _mm256_broadcastss_ps(a);
#else
  simde__m256_private r_;
  simde__m128_private a_= simde__m128_to_private(a);

  SIMDE_VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.f32) / sizeof(r_.f32[0])) ; i++) {
    r_.f32[i] = a_.f32[0];
  }

  return simde__m256_from_private(r_);
#endif
}
#if defined(SIMDE_X86_AVX2_ENABLE_NATIVE_ALIASES)
  #undef _mm256_broadcastss_ps
  #define _mm256_broadcastss_ps(a) simde_mm256_broadcastss_ps(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128d
simde_mm_broadcastsd_pd (simde__m128d a) {
  return simde_mm_movedup_pd(a);
}
#if defined(SIMDE_X86_AVX2_ENABLE_NATIVE_ALIASES)
  #undef _mm_broadcastsd_pd
  #define _mm_broadcastsd_pd(a) simde_mm_broadcastsd_pd(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256d
simde_mm256_broadcastsd_pd (simde__m128d a) {
#if defined(SIMDE_X86_AVX2_NATIVE)
  return _mm256_broadcastsd_pd(a);
#else
  simde__m256d_private r_;
  simde__m128d_private a_= simde__m128d_to_private(a);

  SIMDE_VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.f64) / sizeof(r_.f64[0])) ; i++) {
    r_.f64[i] = a_.f64[0];
  }

  return simde__m256d_from_private(r_);
#endif
}
#if defined(SIMDE_X86_AVX2_ENABLE_NATIVE_ALIASES)
  #undef _mm256_broadcastsd_pd
  #define _mm256_broadcastsd_pd(a) simde_mm256_broadcastsd_pd(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_broadcastsi128_si256 (simde__m128i a) {
#if defined(SIMDE_X86_AVX2_NATIVE)
  return _mm256_broadcastsi128_si256(a);
#else
  simde__m256i_private r_;
  simde__m128i_private a_ = simde__m128i_to_private(a);

#if defined(SIMDE_X86_SSE2_NATIVE)
  r_.m128i_private[0] = a_;
  r_.m128i_private[1] = a_;
#else
  r_.i64[0] = a_.i64[0];
  r_.i64[1] = a_.i64[1];
  r_.i64[2] = a_.i64[0];
  r_.i64[3] = a_.i64[1];
#endif

  return simde__m256i_from_private(r_);
#endif
}
#if defined(SIMDE_X86_AVX2_ENABLE_NATIVE_ALIASES)
  #undef _mm256_broadcastsi128_si256
  #define _mm256_broadcastsi128_si256(a) simde_mm256_broadcastsi128_si256(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_bslli_epi128 (simde__m256i a, const int imm8)
    SIMDE_REQUIRE_CONSTANT_RANGE(imm8, 0, 255)  {
    simde__m256i_private
      r_,
      a_ = simde__m256i_to_private(a);
    const int ssize = HEDLEY_STATIC_CAST(int, (sizeof(r_.i8) / sizeof(r_.i8[0])));

    SIMDE_VECTORIZE
    for (int i = 0 ; i < ssize ; i++) {
      const int e = i - imm8;
      if(i >= (ssize/2)) {
        if(e >= (ssize/2) && e < ssize)
          r_.i8[i] = a_.i8[e];
        else
          r_.i8[i] = 0;
      }
      else{
        if(e >= 0 && e < (ssize/2))
          r_.i8[i] = a_.i8[e];
        else
          r_.i8[i] = 0;
      }
    }

  return simde__m256i_from_private(r_);
}
#if defined(SIMDE_X86_AVX2_NATIVE)
  #define simde_mm256_bslli_epi128(a, imm8) _mm256_bslli_epi128(a, imm8)
#endif
#if defined(SIMDE_X86_AVX2_ENABLE_NATIVE_ALIASES)
  #undef _mm256_bslli_epi128
  #define _mm256_bslli_epi128(a, imm8) simde_mm256_bslli_epi128(a, imm8)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_bsrli_epi128 (simde__m256i a, const int imm8)
    SIMDE_REQUIRE_CONSTANT_RANGE(imm8, 0, 255)  {
    simde__m256i_private
      r_,
      a_ = simde__m256i_to_private(a);
    const int ssize = HEDLEY_STATIC_CAST(int, (sizeof(r_.i8) / sizeof(r_.i8[0])));

    SIMDE_VECTORIZE
    for (int i = 0 ; i < ssize ; i++) {
      const int e = i + imm8;
      if(i < (ssize/2)) {
        if(e >= 0 && e < (ssize/2))
          r_.i8[i] = a_.i8[e];
        else
          r_.i8[i] = 0;
      }
      else{
        if(e >= (ssize/2) && e < ssize)
          r_.i8[i] = a_.i8[e];
        else
          r_.i8[i] = 0;
      }
    }

  return simde__m256i_from_private(r_);
}
#if defined(SIMDE_X86_AVX2_NATIVE)
  #define simde_mm256_bsrli_epi128(a, imm8) _mm256_bsrli_epi128(a, imm8)
#endif
#if defined(SIMDE_X86_AVX2_ENABLE_NATIVE_ALIASES)
  #undef _mm256_bsrli_epi128
  #define _mm256_bsrli_epi128(a, imm8) simde_mm256_bsrli_epi128(a, imm8)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_cmpeq_epi8 (simde__m256i a, simde__m256i b) {
#if defined(SIMDE_X86_AVX2_NATIVE)
  return _mm256_cmpeq_epi8(a, b);
#else
  simde__m256i_private
    r_,
    a_ = simde__m256i_to_private(a),
    b_ = simde__m256i_to_private(b);

#if defined(SIMDE_X86_SSE2_NATIVE)
  r_.m128i[0] = simde_mm_cmpeq_epi8(a_.m128i[0], b_.m128i[0]);
  r_.m128i[1] = simde_mm_cmpeq_epi8(a_.m128i[1], b_.m128i[1]);
#else
  SIMDE_VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.i8) / sizeof(r_.i8[0])) ; i++) {
    r_.i8[i] = (a_.i8[i] == b_.i8[i]) ? ~INT8_C(0) : INT8_C(0);
  }
#endif

  return simde__m256i_from_private(r_);
#endif
}
#if defined(SIMDE_X86_AVX2_ENABLE_NATIVE_ALIASES)
  #undef _mm256_cmpeq_epi8
  #define _mm256_cmpeq_epi8(a, b) simde_mm256_cmpeq_epi8(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_cmpeq_epi16 (simde__m256i a, simde__m256i b) {
#if defined(SIMDE_X86_AVX2_NATIVE)
  return _mm256_cmpeq_epi16(a, b);
#else
  simde__m256i_private
    r_,
    a_ = simde__m256i_to_private(a),
    b_ = simde__m256i_to_private(b);

  SIMDE_VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.i16) / sizeof(r_.i16[0])) ; i++) {
    r_.i16[i] = (a_.i16[i] == b_.i16[i]) ? ~INT16_C(0) : INT16_C(0);
  }

  return simde__m256i_from_private(r_);
#endif
}
#if defined(SIMDE_X86_AVX2_ENABLE_NATIVE_ALIASES)
  #undef _mm256_cmpeq_epi16
  #define _mm256_cmpeq_epi16(a, b) simde_mm256_cmpeq_epi16(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_cmpeq_epi32 (simde__m256i a, simde__m256i b) {
#if defined(SIMDE_X86_AVX2_NATIVE)
  return _mm256_cmpeq_epi32(a, b);
#else
  simde__m256i_private
    r_,
    a_ = simde__m256i_to_private(a),
    b_ = simde__m256i_to_private(b);

#if defined(SIMDE_X86_SSE2_NATIVE) || defined(SIMDE_ARM_NEON_A32V7_NATIVE)
  r_.m128i[0] = simde_mm_cmpeq_epi32(a_.m128i[0], b_.m128i[0]);
  r_.m128i[1] = simde_mm_cmpeq_epi32(a_.m128i[1], b_.m128i[1]);
#else
  SIMDE_VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.i32) / sizeof(r_.i32[0])) ; i++) {
    r_.i32[i] = (a_.i32[i] == b_.i32[i]) ? ~INT32_C(0) : INT32_C(0);
  }
#endif

  return simde__m256i_from_private(r_);
#endif
}
#if defined(SIMDE_X86_AVX2_ENABLE_NATIVE_ALIASES)
  #undef _mm256_cmpeq_epi32
  #define _mm256_cmpeq_epi32(a, b) simde_mm256_cmpeq_epi32(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_cmpeq_epi64 (simde__m256i a, simde__m256i b) {
#if defined(SIMDE_X86_AVX2_NATIVE)
  return _mm256_cmpeq_epi64(a, b);
#else
  simde__m256i_private
    r_,
    a_ = simde__m256i_to_private(a),
    b_ = simde__m256i_to_private(b);

#if defined(SIMDE_X86_SSE2_NATIVE) || defined(SIMDE_ARM_NEON_A32V7_NATIVE)
  r_.m128i[0] = simde_mm_cmpeq_epi64(a_.m128i[0], b_.m128i[0]);
  r_.m128i[1] = simde_mm_cmpeq_epi64(a_.m128i[1], b_.m128i[1]);
#else
  SIMDE_VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.i64) / sizeof(r_.i64[0])) ; i++) {
    r_.i64[i] = (a_.i64[i] == b_.i64[i]) ? ~INT64_C(0) : INT64_C(0);
  }
#endif

  return simde__m256i_from_private(r_);
#endif
}
#if defined(SIMDE_X86_AVX2_ENABLE_NATIVE_ALIASES)
  #undef _mm256_cmpeq_epi64
  #define _mm256_cmpeq_epi64(a, b) simde_mm256_cmpeq_epi64(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_cmpgt_epi8 (simde__m256i a, simde__m256i b) {
#if defined(SIMDE_X86_AVX2_NATIVE)
  return _mm256_cmpgt_epi8(a, b);
#else
  simde__m256i_private
    r_,
    a_ = simde__m256i_to_private(a),
    b_ = simde__m256i_to_private(b);

#if defined(SIMDE_X86_SSE2_NATIVE)
  r_.m128i[0] = simde_mm_cmpgt_epi8(a_.m128i[0], b_.m128i[0]);
  r_.m128i[1] = simde_mm_cmpgt_epi8(a_.m128i[1], b_.m128i[1]);
#elif defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
  r_.i8 = HEDLEY_STATIC_CAST(__typeof__(r_.i8), a_.i8 > b_.i8);
#else
  SIMDE_VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.i8) / sizeof(r_.i8[0])) ; i++) {
    r_.i8[i] = (a_.i8[i] > b_.i8[i]) ? ~INT8_C(0) : INT8_C(0);
  }
#endif

  return simde__m256i_from_private(r_);
#endif
}
#if defined(SIMDE_X86_AVX2_ENABLE_NATIVE_ALIASES)
  #undef _mm256_cmpgt_epi8
  #define _mm256_cmpgt_epi8(a, b) simde_mm256_cmpgt_epi8(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_cmpgt_epi16 (simde__m256i a, simde__m256i b) {
#if defined(SIMDE_X86_AVX2_NATIVE)
  return _mm256_cmpgt_epi16(a, b);
#else
  simde__m256i_private
    r_,
    a_ = simde__m256i_to_private(a),
    b_ = simde__m256i_to_private(b);

#if defined(SIMDE_X86_SSE2_NATIVE)
  r_.m128i[0] = simde_mm_cmpgt_epi16(a_.m128i[0], b_.m128i[0]);
  r_.m128i[1] = simde_mm_cmpgt_epi16(a_.m128i[1], b_.m128i[1]);
#elif defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
  r_.i16 = a_.i16 > b_.i16;
#else
  SIMDE_VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.i16) / sizeof(r_.i16[0])) ; i++) {
    r_.i16[i] = (a_.i16[i] > b_.i16[i]) ? ~INT16_C(0) : INT16_C(0);
  }
#endif

  return simde__m256i_from_private(r_);
#endif
}
#if defined(SIMDE_X86_AVX2_ENABLE_NATIVE_ALIASES)
  #undef _mm256_cmpgt_epi16
  #define _mm256_cmpgt_epi16(a, b) simde_mm256_cmpgt_epi16(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_cmpgt_epi32 (simde__m256i a, simde__m256i b) {
#if defined(SIMDE_X86_AVX2_NATIVE)
  return _mm256_cmpgt_epi32(a, b);
#else
  simde__m256i_private
    r_,
    a_ = simde__m256i_to_private(a),
    b_ = simde__m256i_to_private(b);

#if defined(SIMDE_X86_SSE2_NATIVE)
  r_.m128i[0] = simde_mm_cmpgt_epi32(a_.m128i[0], b_.m128i[0]);
  r_.m128i[1] = simde_mm_cmpgt_epi32(a_.m128i[1], b_.m128i[1]);
#elif defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
  r_.i32 = HEDLEY_STATIC_CAST(__typeof__(r_.i32), a_.i32 > b_.i32);
#else
  SIMDE_VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.i32) / sizeof(r_.i32[0])) ; i++) {
    r_.i32[i] = (a_.i32[i] > b_.i32[i]) ? ~INT32_C(0) : INT32_C(0);
  }
#endif

  return simde__m256i_from_private(r_);
#endif
}
#if defined(SIMDE_X86_AVX2_ENABLE_NATIVE_ALIASES)
  #undef _mm256_cmpgt_epi32
  #define _mm256_cmpgt_epi32(a, b) simde_mm256_cmpgt_epi32(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_cmpgt_epi64 (simde__m256i a, simde__m256i b) {
#if defined(SIMDE_X86_AVX2_NATIVE)
  return _mm256_cmpgt_epi64(a, b);
#else
  simde__m256i_private
    r_,
    a_ = simde__m256i_to_private(a),
    b_ = simde__m256i_to_private(b);

#if defined(SIMDE_X86_SSE2_NATIVE)
  r_.m128i[0] = simde_mm_cmpgt_epi64(a_.m128i[0], b_.m128i[0]);
  r_.m128i[1] = simde_mm_cmpgt_epi64(a_.m128i[1], b_.m128i[1]);
#elif defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
  r_.i64 = HEDLEY_STATIC_CAST(__typeof__(r_.i64), a_.i64 > b_.i64);
#else
  SIMDE_VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.i64) / sizeof(r_.i64[0])) ; i++) {
    r_.i64[i] = (a_.i64[i] > b_.i64[i]) ? ~INT64_C(0) : INT64_C(0);
  }
#endif

  return simde__m256i_from_private(r_);
#endif
}
#if defined(SIMDE_X86_AVX2_ENABLE_NATIVE_ALIASES)
  #undef _mm256_cmpgt_epi64
  #define _mm256_cmpgt_epi64(a, b) simde_mm256_cmpgt_epi64(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_cvtepi8_epi16 (simde__m128i a) {
#if defined(SIMDE_X86_AVX2_NATIVE)
  return _mm256_cvtepi8_epi16(a);
#else
  simde__m256i_private r_;
  simde__m128i_private a_ = simde__m128i_to_private(a);

#if defined(SIMDE_CONVERT_VECTOR_)
  SIMDE_CONVERT_VECTOR_(r_.i16, a_.i8);
#else
  SIMDE_VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.i16) / sizeof(r_.i16[0])) ; i++) {
    r_.i16[i] = a_.i8[i];
  }
#endif

  return simde__m256i_from_private(r_);
#endif
}
#if defined(SIMDE_X86_AVX2_ENABLE_NATIVE_ALIASES)
  #undef _mm256_cvtepi8_epi16
  #define _mm256_cvtepi8_epi16(a) simde_mm256_cvtepi8_epi16(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_cvtepi8_epi32 (simde__m128i a) {
#if defined(SIMDE_X86_AVX2_NATIVE)
  return _mm256_cvtepi8_epi32(a);
#else
  simde__m256i_private r_;
  simde__m128i_private a_ = simde__m128i_to_private(a);

#if defined(SIMDE_CONVERT_VECTOR_)
  SIMDE_CONVERT_VECTOR_(r_.i32, a_.m64_private[0].i8);
#else
  SIMDE_VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.i32) / sizeof(r_.i32[0])) ; i++) {
    r_.i32[i] = a_.i8[i];
  }
#endif

  return simde__m256i_from_private(r_);
#endif
}
#if defined(SIMDE_X86_AVX2_ENABLE_NATIVE_ALIASES)
  #undef _mm256_cvtepi8_epi32
  #define _mm256_cvtepi8_epi32(a) simde_mm256_cvtepi8_epi32(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_cvtepi8_epi64 (simde__m128i a) {
#if defined(SIMDE_X86_AVX2_NATIVE)
  return _mm256_cvtepi8_epi64(a);
#else
  simde__m256i_private r_;
  simde__m128i_private a_ = simde__m128i_to_private(a);

  SIMDE_VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.i64) / sizeof(r_.i64[0])) ; i++) {
    r_.i64[i] = a_.i8[i];
  }

  return simde__m256i_from_private(r_);
#endif
}
#if defined(SIMDE_X86_AVX2_ENABLE_NATIVE_ALIASES)
  #undef _mm256_cvtepi8_epi64
  #define _mm256_cvtepi8_epi64(a) simde_mm256_cvtepi8_epi64(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_cvtepi16_epi32 (simde__m128i a) {
#if defined(SIMDE_X86_AVX2_NATIVE)
  return _mm256_cvtepi16_epi32(a);
#else
  simde__m256i_private r_;
  simde__m128i_private a_ = simde__m128i_to_private(a);

#if defined(SIMDE_CONVERT_VECTOR_)
  SIMDE_CONVERT_VECTOR_(r_.i32, a_.i16);
#else
  SIMDE_VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.i32) / sizeof(r_.i32[0])) ; i++) {
    r_.i32[i] = a_.i16[i];
  }
#endif

  return simde__m256i_from_private(r_);
#endif
}
#if defined(SIMDE_X86_AVX2_ENABLE_NATIVE_ALIASES)
  #undef _mm256_cvtepi16_epi32
  #define _mm256_cvtepi16_epi32(a) simde_mm256_cvtepi16_epi32(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_cvtepi16_epi64 (simde__m128i a) {
#if defined(SIMDE_X86_AVX2_NATIVE)
  return _mm256_cvtepi16_epi64(a);
#else
  simde__m256i_private r_;
  simde__m128i_private a_ = simde__m128i_to_private(a);

#if defined(SIMDE_CONVERT_VECTOR_)
  SIMDE_CONVERT_VECTOR_(r_.i64, a_.m64_private[0].i16);
#else
  SIMDE_VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.i64) / sizeof(r_.i64[0])) ; i++) {
    r_.i64[i] = a_.i16[i];
  }
#endif

  return simde__m256i_from_private(r_);
#endif
}
#if defined(SIMDE_X86_AVX2_ENABLE_NATIVE_ALIASES)
  #undef _mm256_cvtepi16_epi64
  #define _mm256_cvtepi16_epi64(a) simde_mm256_cvtepi16_epi64(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_cvtepi32_epi64 (simde__m128i a) {
#if defined(SIMDE_X86_AVX2_NATIVE)
  return _mm256_cvtepi32_epi64(a);
#else
  simde__m256i_private r_;
  simde__m128i_private a_ = simde__m128i_to_private(a);

#if defined(SIMDE_CONVERT_VECTOR_)
  SIMDE_CONVERT_VECTOR_(r_.i64, a_.i32);
#else
  SIMDE_VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.i64) / sizeof(r_.i64[0])) ; i++) {
    r_.i64[i] = a_.i32[i];
  }
#endif

  return simde__m256i_from_private(r_);
#endif
}
#if defined(SIMDE_X86_AVX2_ENABLE_NATIVE_ALIASES)
  #undef _mm256_cvtepi32_epi64
  #define _mm256_cvtepi32_epi64(a) simde_mm256_cvtepi32_epi64(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_cvtepu8_epi16 (simde__m128i a) {
#if defined(SIMDE_X86_AVX2_NATIVE)
  return _mm256_cvtepu8_epi16(a);
#else
  simde__m256i_private r_;
  simde__m128i_private a_ = simde__m128i_to_private(a);

#if defined(SIMDE_CONVERT_VECTOR_)
  SIMDE_CONVERT_VECTOR_(r_.i16, a_.u8);
#else
  SIMDE_VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.i16) / sizeof(r_.i16[0])) ; i++) {
    r_.i16[i] = a_.u8[i];
  }
#endif

  return simde__m256i_from_private(r_);
#endif
}
#if defined(SIMDE_X86_AVX2_ENABLE_NATIVE_ALIASES)
  #undef _mm256_cvtepu8_epi16
  #define _mm256_cvtepu8_epi16(a) simde_mm256_cvtepu8_epi16(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_cvtepu8_epi32 (simde__m128i a) {
#if defined(SIMDE_X86_AVX2_NATIVE)
  return _mm256_cvtepu8_epi32(a);
#else
  simde__m256i_private r_;
  simde__m128i_private a_ = simde__m128i_to_private(a);

#if defined(SIMDE_CONVERT_VECTOR_)
  SIMDE_CONVERT_VECTOR_(r_.i32, a_.m64_private[0].u8);
#else
  SIMDE_VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.i32) / sizeof(r_.i32[0])) ; i++) {
    r_.i32[i] = a_.u8[i];
  }
#endif

  return simde__m256i_from_private(r_);
#endif
}
#if defined(SIMDE_X86_AVX2_ENABLE_NATIVE_ALIASES)
  #undef _mm256_cvtepu8_epi32
  #define _mm256_cvtepu8_epi32(a) simde_mm256_cvtepu8_epi32(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_cvtepu8_epi64 (simde__m128i a) {
#if defined(SIMDE_X86_AVX2_NATIVE)
  return _mm256_cvtepu8_epi64(a);
#else
  simde__m256i_private r_;
  simde__m128i_private a_ = simde__m128i_to_private(a);

  SIMDE_VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.i64) / sizeof(r_.i64[0])) ; i++) {
    r_.i64[i] = a_.u8[i];
  }

  return simde__m256i_from_private(r_);
#endif
}
#if defined(SIMDE_X86_AVX2_ENABLE_NATIVE_ALIASES)
  #undef _mm256_cvtepu8_epi64
  #define _mm256_cvtepu8_epi64(a) simde_mm256_cvtepu8_epi64(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_cvtepu16_epi32 (simde__m128i a) {
#if defined(SIMDE_X86_AVX2_NATIVE)
  return _mm256_cvtepu16_epi32(a);
#else
  simde__m256i_private r_;
  simde__m128i_private a_ = simde__m128i_to_private(a);

#if defined(SIMDE_CONVERT_VECTOR_)
  SIMDE_CONVERT_VECTOR_(r_.i32, a_.u16);
#else
  SIMDE_VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.i32) / sizeof(r_.i32[0])) ; i++) {
    r_.i32[i] = a_.u16[i];
  }
#endif

  return simde__m256i_from_private(r_);
#endif
}
#if defined(SIMDE_X86_AVX2_ENABLE_NATIVE_ALIASES)
  #undef _mm256_cvtepu16_epi32
  #define _mm256_cvtepu16_epi32(a) simde_mm256_cvtepu16_epi32(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_cvtepu16_epi64 (simde__m128i a) {
#if defined(SIMDE_X86_AVX2_NATIVE)
  return _mm256_cvtepu16_epi64(a);
#else
  simde__m256i_private r_;
  simde__m128i_private a_ = simde__m128i_to_private(a);

#if defined(SIMDE_CONVERT_VECTOR_)
  SIMDE_CONVERT_VECTOR_(r_.i64, a_.m64_private[0].u16);
#else
  SIMDE_VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.i64) / sizeof(r_.i64[0])) ; i++) {
    r_.i64[i] = a_.u16[i];
  }
#endif

  return simde__m256i_from_private(r_);
#endif
}
#if defined(SIMDE_X86_AVX2_ENABLE_NATIVE_ALIASES)
  #undef _mm256_cvtepu16_epi64
  #define _mm256_cvtepu16_epi64(a) simde_mm256_cvtepu16_epi64(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_cvtepu32_epi64 (simde__m128i a) {
#if defined(SIMDE_X86_AVX2_NATIVE)
  return _mm256_cvtepu32_epi64(a);
#else
  simde__m256i_private r_;
  simde__m128i_private a_ = simde__m128i_to_private(a);

#if defined(SIMDE_CONVERT_VECTOR_)
  SIMDE_CONVERT_VECTOR_(r_.i64, a_.u32);
#else
  SIMDE_VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.i64) / sizeof(r_.i64[0])) ; i++) {
    r_.i64[i] = a_.u32[i];
  }
#endif

  return simde__m256i_from_private(r_);
#endif
}
#if defined(SIMDE_X86_AVX2_ENABLE_NATIVE_ALIASES)
  #undef _mm256_cvtepu32_epi64
  #define _mm256_cvtepu32_epi64(a) simde_mm256_cvtepu32_epi64(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
int
simde_mm256_extract_epi8 (simde__m256i a, const int index)
    SIMDE_REQUIRE_RANGE(index, 0, 31){
  simde__m256i_private a_ = simde__m256i_to_private(a);
  return a_.i8[index];
}
#if defined(SIMDE_X86_AVX_NATIVE)
  #define simde_mm256_extract_epi8(a, index) _mm256_extract_epi8(a, index)
#endif
#if defined(SIMDE_X86_AVX2_ENABLE_NATIVE_ALIASES)
  #undef _mm256_extract_epi8
  #define _mm256_extract_epi8(a, index) simde_mm256_extract_epi8(a, index)
#endif

SIMDE_FUNCTION_ATTRIBUTES
int
simde_mm256_extract_epi16 (simde__m256i a, const int index)
    SIMDE_REQUIRE_RANGE(index, 0, 15)  {
  simde__m256i_private a_ = simde__m256i_to_private(a);
  return a_.i16[index];
}
#if defined(SIMDE_X86_AVX_NATIVE)
  #define simde_mm256_extract_epi16(a, index) _mm256_extract_epi16(a, index)
#endif
#if defined(SIMDE_X86_AVX2_ENABLE_NATIVE_ALIASES)
  #undef _mm256_extract_epi16
  #define _mm256_extract_epi16(a, index) simde_mm256_extract_epi16(a, index)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm256_extracti128_si256 (simde__m256i a, const int imm8)
    SIMDE_REQUIRE_RANGE(imm8, 0, 1) {
  simde__m256i_private a_ = simde__m256i_to_private(a);
  return a_.m128i[imm8];
}
#if defined(SIMDE_X86_AVX2_NATIVE)
#  define simde_mm256_extracti128_si256(a, imm8) _mm256_extracti128_si256(a, imm8)
#endif
#if defined(SIMDE_X86_AVX2_ENABLE_NATIVE_ALIASES)
  #undef _mm256_extracti128_si256
  #define _mm256_extracti128_si256(a, imm8) simde_mm256_extracti128_si256(a, imm8)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_hadd_epi16 (simde__m256i a, simde__m256i b) {
#if defined(SIMDE_X86_AVX2_NATIVE)
  return _mm256_hadd_epi16(a, b);
#else
  simde__m256i_private
    r_,
    a_ = simde__m256i_to_private(a),
    b_ = simde__m256i_to_private(b);

  SIMDE_VECTORIZE
  for (size_t  i = 0 ; i < (sizeof(r_.m128i) / sizeof(r_.m128i[0])) ; i++ ) {
    const simde__m128i even = simde_x_mm_deinterleaveeven_epi16(a_.m128i[i], b_.m128i[i]);
    const simde__m128i odd = simde_x_mm_deinterleaveodd_epi16(a_.m128i[i], b_.m128i[i]);
    r_.m128i[i] = simde_mm_add_epi16(even, odd);
  }

  return simde__m256i_from_private(r_);
#endif
}
#if defined(SIMDE_X86_AVX2_ENABLE_NATIVE_ALIASES)
  #undef _mm256_hadd_epi16
  #define _mm256_hadd_epi16(a, b) simde_mm256_hadd_epi16(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_hadd_epi32 (simde__m256i a, simde__m256i b) {
#if defined(SIMDE_X86_AVX2_NATIVE)
  return _mm256_hadd_epi32(a, b);
#else
  simde__m256i_private r_;
  simde__m256i_private a_ = simde__m256i_to_private(a);
  simde__m256i_private b_ = simde__m256i_to_private(b);

  r_.i32[0] = a_.i32[1] + a_.i32[0];
  r_.i32[1] = a_.i32[3] + a_.i32[2];
  r_.i32[2] = b_.i32[1] + b_.i32[0];
  r_.i32[3] = b_.i32[3] + b_.i32[2];
  r_.i32[4] = a_.i32[5] + a_.i32[4];
  r_.i32[5] = a_.i32[7] + a_.i32[6];
  r_.i32[6] = b_.i32[5] + b_.i32[4];
  r_.i32[7] = b_.i32[7] + b_.i32[6];

  return simde__m256i_from_private(r_);
#endif
}
#if defined(SIMDE_X86_AVX2_ENABLE_NATIVE_ALIASES)
  #undef _mm256_hadd_epi32
  #define _mm256_hadd_epi32(a, b) simde_mm256_hadd_epi32(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_hsub_epi16 (simde__m256i a, simde__m256i b) {
#if defined(SIMDE_X86_AVX2_NATIVE)
  return _mm256_hsub_epi16(a, b);
#else
  simde__m256i_private r_;
  simde__m256i_private a_ = simde__m256i_to_private(a);
  simde__m256i_private b_ = simde__m256i_to_private(b);

  r_.i16[0] = a_.i16[0] - a_.i16[1];
  r_.i16[1] = a_.i16[2] - a_.i16[3];
  r_.i16[2] = a_.i16[4] - a_.i16[5];
  r_.i16[3] = a_.i16[6] - a_.i16[7];
  r_.i16[4] = b_.i16[0] - b_.i16[1];
  r_.i16[5] = b_.i16[2] - b_.i16[3];
  r_.i16[6] = b_.i16[4] - b_.i16[5];
  r_.i16[7] = b_.i16[6] - b_.i16[7];
  r_.i16[8] = a_.i16[8] - a_.i16[9];
  r_.i16[9] = a_.i16[10] - a_.i16[11];
  r_.i16[10] = a_.i16[12] - a_.i16[13];
  r_.i16[11] = a_.i16[14] - a_.i16[15];
  r_.i16[12] = b_.i16[8] - b_.i16[9];
  r_.i16[13] = b_.i16[10] - b_.i16[11];
  r_.i16[14] = b_.i16[12] - b_.i16[13];
  r_.i16[15] = b_.i16[14] - b_.i16[15];

  return simde__m256i_from_private(r_);
#endif
}
#if defined(SIMDE_X86_AVX2_ENABLE_NATIVE_ALIASES)
  #undef _mm256_hsub_epi16
  #define _mm256_hsub_epi16(a, b) simde_mm256_hsub_epi16(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_hsub_epi32 (simde__m256i a, simde__m256i b) {
#if defined(SIMDE_X86_AVX2_NATIVE)
  return _mm256_hsub_epi32(a, b);
#else
  simde__m256i_private r_;
  simde__m256i_private a_ = simde__m256i_to_private(a);
  simde__m256i_private b_ = simde__m256i_to_private(b);

  r_.i32[0] = a_.i32[0] - a_.i32[1];
  r_.i32[1] = a_.i32[2] - a_.i32[3];
  r_.i32[2] = b_.i32[0] - b_.i32[1];
  r_.i32[3] = b_.i32[2] - b_.i32[3];
  r_.i32[4] = a_.i32[4] - a_.i32[5];
  r_.i32[5] = a_.i32[6] - a_.i32[7];
  r_.i32[6] = b_.i32[4] - b_.i32[5];
  r_.i32[7] = b_.i32[6] - b_.i32[7];

  return simde__m256i_from_private(r_);
#endif
}
#if defined(SIMDE_X86_AVX2_ENABLE_NATIVE_ALIASES)
  #undef _mm256_hsub_epi32
  #define _mm256_hsub_epi32(a, b) simde_mm256_hsub_epi32(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_inserti128_si256(simde__m256i a, simde__m128i b, const int imm8)
    SIMDE_REQUIRE_RANGE(imm8, 0, 7) {
  simde__m256i_private a_ = simde__m256i_to_private(a);
  simde__m128i_private b_ = simde__m128i_to_private(b);

  a_.m128i_private[ imm8 & 1 ] = b_;

  return simde__m256i_from_private(a_);
}
#if defined(SIMDE_X86_AVX2_NATIVE)
  #define simde_mm256_inserti128_si256(a, b, imm8) _mm256_inserti128_si256(a, b, imm8)
#endif
#if defined(SIMDE_X86_AVX_ENABLE_NATIVE_ALIASES)
  #define _mm256_inserti128_si256(a, b, imm8) simde_mm256_inserti128_si256(a, b, imm8)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_madd_epi16 (simde__m256i a, simde__m256i b) {
#if defined(SIMDE_X86_AVX2_NATIVE)
  return _mm256_madd_epi16(a, b);
#else
  simde__m256i_private
    r_,
    a_ = simde__m256i_to_private(a),
    b_ = simde__m256i_to_private(b);

  r_.m128i[0] = simde_mm_madd_epi16(a_.m128i[0], b_.m128i[0]);
  r_.m128i[1] = simde_mm_madd_epi16(a_.m128i[1], b_.m128i[1]);

  return simde__m256i_from_private(r_);
#endif
}
#if defined(SIMDE_X86_AVX2_ENABLE_NATIVE_ALIASES)
  #undef _mm256_madd_epi16
  #define _mm256_madd_epi16(a, b) simde_mm256_madd_epi16(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_max_epi8 (simde__m256i a, simde__m256i b) {
#if defined(SIMDE_X86_AVX2_NATIVE) && !defined(__PGI)
  return _mm256_max_epi8(a, b);
#else
  simde__m256i_private
    r_,
    a_ = simde__m256i_to_private(a),
    b_ = simde__m256i_to_private(b);

#if defined(SIMDE_X86_SSE4_1_NATIVE)
  r_.m128i[0] = simde_mm_max_epi8(a_.m128i[0], b_.m128i[0]);
  r_.m128i[1] = simde_mm_max_epi8(a_.m128i[1], b_.m128i[1]);
#else
  SIMDE_VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.i8) / sizeof(r_.i8[0])) ; i++) {
    r_.i8[i] = a_.i8[i] > b_.i8[i] ? a_.i8[i] : b_.i8[i];
  }
#endif

  return simde__m256i_from_private(r_);
#endif
}
#if defined(SIMDE_X86_AVX2_ENABLE_NATIVE_ALIASES)
  #undef _mm256_max_epi8
  #define _mm256_max_epi8(a, b) simde_mm256_max_epi8(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_max_epu8 (simde__m256i a, simde__m256i b) {
#if defined(SIMDE_X86_AVX2_NATIVE)
  return _mm256_max_epu8(a, b);
#else
  simde__m256i_private
    r_,
    a_ = simde__m256i_to_private(a),
    b_ = simde__m256i_to_private(b);

#if defined(SIMDE_X86_SSE2_NATIVE) || defined(SIMDE_ARM_NEON_A32V7_NATIVE)
  r_.m128i[0] = simde_mm_max_epu8(a_.m128i[0], b_.m128i[0]);
  r_.m128i[1] = simde_mm_max_epu8(a_.m128i[1], b_.m128i[1]);
#else
  SIMDE_VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.u8) / sizeof(r_.u8[0])) ; i++) {
    r_.u8[i] = (a_.u8[i] > b_.u8[i]) ? a_.u8[i] : b_.u8[i];
  }
#endif

  return simde__m256i_from_private(r_);
#endif
}
#if defined(SIMDE_X86_AVX2_ENABLE_NATIVE_ALIASES)
  #undef _mm256_max_epu8
  #define _mm256_max_epu8(a, b) simde_mm256_max_epu8(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_max_epu16 (simde__m256i a, simde__m256i b) {
#if defined(SIMDE_X86_AVX2_NATIVE)
  return _mm256_max_epu16(a, b);
#else
  simde__m256i_private
    r_,
    a_ = simde__m256i_to_private(a),
    b_ = simde__m256i_to_private(b);

#if defined(SIMDE_X86_SSE2_NATIVE) || defined(SIMDE_ARM_NEON_A32V7_NATIVE)
  r_.m128i[0] = simde_mm_max_epu16(a_.m128i[0], b_.m128i[0]);
  r_.m128i[1] = simde_mm_max_epu16(a_.m128i[1], b_.m128i[1]);
#else
  SIMDE_VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.u16) / sizeof(r_.u16[0])) ; i++) {
    r_.u16[i] = (a_.u16[i] > b_.u16[i]) ? a_.u16[i] : b_.u16[i];
  }
#endif

  return simde__m256i_from_private(r_);
#endif
}
#if defined(SIMDE_X86_AVX2_ENABLE_NATIVE_ALIASES)
  #undef _mm256_max_epu16
  #define _mm256_max_epu16(a, b) simde_mm256_max_epu16(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_max_epu32 (simde__m256i a, simde__m256i b) {
#if defined(SIMDE_X86_AVX2_NATIVE)
  return _mm256_max_epu32(a, b);
#else
  simde__m256i_private
    r_,
    a_ = simde__m256i_to_private(a),
    b_ = simde__m256i_to_private(b);

#if defined(SIMDE_X86_SSE2_NATIVE) || defined(SIMDE_ARM_NEON_A32V7_NATIVE)
  r_.m128i[0] = simde_mm_max_epu32(a_.m128i[0], b_.m128i[0]);
  r_.m128i[1] = simde_mm_max_epu32(a_.m128i[1], b_.m128i[1]);
#else
  SIMDE_VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.u32) / sizeof(r_.u32[0])) ; i++) {
    r_.u32[i] = (a_.u32[i] > b_.u32[i]) ? a_.u32[i] : b_.u32[i];
  }
#endif

  return simde__m256i_from_private(r_);
#endif
}
#if defined(SIMDE_X86_AVX2_ENABLE_NATIVE_ALIASES)
  #undef _mm256_max_epu32
  #define _mm256_max_epu32(a, b) simde_mm256_max_epu32(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_max_epi16 (simde__m256i a, simde__m256i b) {
#if defined(SIMDE_X86_AVX2_NATIVE)
  return _mm256_max_epi16(a, b);
#else
  simde__m256i_private
    r_,
    a_ = simde__m256i_to_private(a),
    b_ = simde__m256i_to_private(b);

#if defined(SIMDE_X86_SSE2_NATIVE)
  r_.m128i[0] = simde_mm_max_epi16(a_.m128i[0], b_.m128i[0]);
  r_.m128i[1] = simde_mm_max_epi16(a_.m128i[1], b_.m128i[1]);
#else
  SIMDE_VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.i16) / sizeof(r_.i16[0])) ; i++) {
    r_.i16[i] = (a_.i16[i] > b_.i16[i]) ? a_.i16[i] : b_.i16[i];
  }
#endif

  return simde__m256i_from_private(r_);
#endif
}
#if defined(SIMDE_X86_AVX2_ENABLE_NATIVE_ALIASES)
  #undef _mm256_max_epi16
  #define _mm256_max_epi16(a, b) simde_mm256_max_epi16(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_max_epi32 (simde__m256i a, simde__m256i b) {
#if defined(SIMDE_X86_AVX2_NATIVE)
  return _mm256_max_epi32(a, b);
#else
  simde__m256i_private
    r_,
    a_ = simde__m256i_to_private(a),
    b_ = simde__m256i_to_private(b);

#if defined(SIMDE_X86_SSE4_1_NATIVE)
  r_.m128i[0] = simde_mm_max_epi32(a_.m128i[0], b_.m128i[0]);
  r_.m128i[1] = simde_mm_max_epi32(a_.m128i[1], b_.m128i[1]);
#else
  SIMDE_VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.i32) / sizeof(r_.i32[0])) ; i++) {
    r_.i32[i] = a_.i32[i] > b_.i32[i] ? a_.i32[i] : b_.i32[i];
  }
#endif

  return simde__m256i_from_private(r_);
#endif
}
#if defined(SIMDE_X86_AVX2_ENABLE_NATIVE_ALIASES)
  #undef _mm256_max_epi32
  #define _mm256_max_epi32(a, b) simde_mm256_max_epi32(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_min_epi8 (simde__m256i a, simde__m256i b) {
#if defined(SIMDE_X86_AVX2_NATIVE) && !defined(__PGI)
  return _mm256_min_epi8(a, b);
#else
  simde__m256i_private
    r_,
    a_ = simde__m256i_to_private(a),
    b_ = simde__m256i_to_private(b);

#if defined(SIMDE_X86_SSE4_1_NATIVE)
  r_.m128i[0] = simde_mm_min_epi8(a_.m128i[0], b_.m128i[0]);
  r_.m128i[1] = simde_mm_min_epi8(a_.m128i[1], b_.m128i[1]);
#else
  SIMDE_VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.i8) / sizeof(r_.i8[0])) ; i++) {
    r_.i8[i] = a_.i8[i] < b_.i8[i] ? a_.i8[i] : b_.i8[i];
  }
#endif

  return simde__m256i_from_private(r_);
#endif
}
#if defined(SIMDE_X86_AVX2_ENABLE_NATIVE_ALIASES)
  #undef _mm256_min_epi8
  #define _mm256_min_epi8(a, b) simde_mm256_min_epi8(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_min_epi16 (simde__m256i a, simde__m256i b) {
#if defined(SIMDE_X86_AVX2_NATIVE)
  return _mm256_min_epi16(a, b);
#else
  simde__m256i_private
    r_,
    a_ = simde__m256i_to_private(a),
    b_ = simde__m256i_to_private(b);

#if defined(SIMDE_X86_SSE2_NATIVE)
  r_.m128i[0] = simde_mm_min_epi16(a_.m128i[0], b_.m128i[0]);
  r_.m128i[1] = simde_mm_min_epi16(a_.m128i[1], b_.m128i[1]);
#else
  SIMDE_VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.i16) / sizeof(r_.i16[0])) ; i++) {
    r_.i16[i] = (a_.i16[i] < b_.i16[i]) ? a_.i16[i] : b_.i16[i];
  }
#endif

  return simde__m256i_from_private(r_);
#endif
}
#if defined(SIMDE_X86_AVX2_ENABLE_NATIVE_ALIASES)
  #undef _mm256_min_epi16
  #define _mm256_min_epi16(a, b) simde_mm256_min_epi16(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_min_epi32 (simde__m256i a, simde__m256i b) {
#if defined(SIMDE_X86_AVX2_NATIVE)
  return _mm256_min_epi32(a, b);
#else
  simde__m256i_private
    r_,
    a_ = simde__m256i_to_private(a),
    b_ = simde__m256i_to_private(b);

#if defined(SIMDE_X86_SSE4_1_NATIVE)
  r_.m128i[0] = simde_mm_min_epi32(a_.m128i[0], b_.m128i[0]);
  r_.m128i[1] = simde_mm_min_epi32(a_.m128i[1], b_.m128i[1]);
#else
  SIMDE_VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.i32) / sizeof(r_.i32[0])) ; i++) {
    r_.i32[i] = a_.i32[i] < b_.i32[i] ? a_.i32[i] : b_.i32[i];
  }
#endif

  return simde__m256i_from_private(r_);
#endif
}
#if defined(SIMDE_X86_AVX2_ENABLE_NATIVE_ALIASES)
  #undef _mm256_min_epi32
  #define _mm256_min_epi32(a, b) simde_mm256_min_epi32(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_min_epu8 (simde__m256i a, simde__m256i b) {
#if defined(SIMDE_X86_AVX2_NATIVE)
  return _mm256_min_epu8(a, b);
#else
  simde__m256i_private
    r_,
    a_ = simde__m256i_to_private(a),
    b_ = simde__m256i_to_private(b);

#if defined(SIMDE_X86_SSE2_NATIVE)
  r_.m128i[0] = simde_mm_min_epu8(a_.m128i[0], b_.m128i[0]);
  r_.m128i[1] = simde_mm_min_epu8(a_.m128i[1], b_.m128i[1]);
#else
  SIMDE_VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.u8) / sizeof(r_.u8[0])) ; i++) {
    r_.u8[i] = (a_.u8[i] < b_.u8[i]) ? a_.u8[i] : b_.u8[i];
  }
#endif

  return simde__m256i_from_private(r_);
#endif
}
#if defined(SIMDE_X86_AVX2_ENABLE_NATIVE_ALIASES)
  #undef _mm256_min_epu8
  #define _mm256_min_epu8(a, b) simde_mm256_min_epu8(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_min_epu16 (simde__m256i a, simde__m256i b) {
#if defined(SIMDE_X86_AVX2_NATIVE)
  return _mm256_min_epu16(a, b);
#else
  simde__m256i_private
    r_,
    a_ = simde__m256i_to_private(a),
    b_ = simde__m256i_to_private(b);

#if defined(SIMDE_X86_SSE2_NATIVE)
  r_.m128i[0] = simde_mm_min_epu16(a_.m128i[0], b_.m128i[0]);
  r_.m128i[1] = simde_mm_min_epu16(a_.m128i[1], b_.m128i[1]);
#else
  SIMDE_VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.u16) / sizeof(r_.u16[0])) ; i++) {
    r_.u16[i] = (a_.u16[i] < b_.u16[i]) ? a_.u16[i] : b_.u16[i];
  }
#endif

  return simde__m256i_from_private(r_);
#endif
}
#if defined(SIMDE_X86_AVX2_ENABLE_NATIVE_ALIASES)
  #undef _mm256_min_epu16
  #define _mm256_min_epu16(a, b) simde_mm256_min_epu16(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_min_epu32 (simde__m256i a, simde__m256i b) {
#if defined(SIMDE_X86_AVX2_NATIVE)
  return _mm256_min_epu32(a, b);
#else
  simde__m256i_private
    r_,
    a_ = simde__m256i_to_private(a),
    b_ = simde__m256i_to_private(b);

#if defined(SIMDE_X86_SSE2_NATIVE)
  r_.m128i[0] = simde_mm_min_epu32(a_.m128i[0], b_.m128i[0]);
  r_.m128i[1] = simde_mm_min_epu32(a_.m128i[1], b_.m128i[1]);
#else
  SIMDE_VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.u32) / sizeof(r_.u32[0])) ; i++) {
    r_.u32[i] = (a_.u32[i] < b_.u32[i]) ? a_.u32[i] : b_.u32[i];
  }
#endif

  return simde__m256i_from_private(r_);
#endif
}
#if defined(SIMDE_X86_AVX2_ENABLE_NATIVE_ALIASES)
  #undef _mm256_min_epu32
  #define _mm256_min_epu32(a, b) simde_mm256_min_epu32(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
int32_t
simde_mm256_movemask_epi8 (simde__m256i a) {
#if defined(SIMDE_X86_AVX2_NATIVE)
  return _mm256_movemask_epi8(a);
#else
  simde__m256i_private a_ = simde__m256i_to_private(a);
  int32_t r;

#if defined(SIMDE_X86_SSE2_NATIVE)
  r =             simde_mm_movemask_epi8(a_.m128i[1]);
  r = (r << 16) | simde_mm_movemask_epi8(a_.m128i[0]);
#else
  r = 0;
  SIMDE_VECTORIZE_REDUCTION(|:r)
  for (size_t i = 0 ; i < (sizeof(a_.u8) / sizeof(a_.u8[0])) ; i++) {
    r |= (a_.u8[31 - i] >> 7) << (31 - i);
  }
#endif

  return r;
#endif
}
#if defined(SIMDE_X86_AVX2_ENABLE_NATIVE_ALIASES)
  #undef _mm256_movemask_epi8
  #define _mm256_movemask_epi8(a) simde_mm256_movemask_epi8(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_mul_epi32 (simde__m256i a, simde__m256i b) {
#if defined(SIMDE_X86_AVX2_NATIVE)
  return _mm256_mul_epi32(a, b);
#else
  simde__m256i_private
    r_,
    a_ = simde__m256i_to_private(a),
    b_ = simde__m256i_to_private(b);

  SIMDE_VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.i64) / sizeof(r_.i64[0])) ; i++) {
    r_.i64[i] =
      HEDLEY_STATIC_CAST(int64_t, a_.i32[i * 2]) *
      HEDLEY_STATIC_CAST(int64_t, b_.i32[i * 2]);
  }

  return simde__m256i_from_private(r_);
#endif
}
#if defined(SIMDE_X86_AVX2_ENABLE_NATIVE_ALIASES)
#  define _mm256_mul_epi32(a, b) simde_mm256_mul_epi32(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_mul_epu32 (simde__m256i a, simde__m256i b) {
#if defined(SIMDE_X86_AVX2_NATIVE)
  return _mm256_mul_epu32(a, b);
#else
  simde__m256i_private
    r_,
    a_ = simde__m256i_to_private(a),
    b_ = simde__m256i_to_private(b);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.u64) / sizeof(r_.u64[0])) ; i++) {
      r_.u64[i] = HEDLEY_STATIC_CAST(uint64_t, a_.u32[i * 2]) * HEDLEY_STATIC_CAST(uint64_t, b_.u32[i * 2]);
    }

  return simde__m256i_from_private(r_);
#endif
}
#if defined(SIMDE_X86_AVX2_ENABLE_NATIVE_ALIASES)
#  define _mm256_mul_epu32(a, b) simde_mm256_mul_epu32(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_mulhi_epi16 (simde__m256i a, simde__m256i b) {
  #if defined(SIMDE_X86_AVX2_NATIVE)
    return _mm256_mulhi_epi16(a, b);
  #else
    simde__m256i_private
      r_,
      a_ = simde__m256i_to_private(a),
      b_ = simde__m256i_to_private(b);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.i16) / sizeof(r_.i16[0])) ; i++) {
      r_.u16[i] = HEDLEY_STATIC_CAST(uint16_t, (HEDLEY_STATIC_CAST(uint32_t, HEDLEY_STATIC_CAST(int32_t, a_.i16[i]) * HEDLEY_STATIC_CAST(int32_t, b_.i16[i])) >> 16));
    }

    return simde__m256i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX2_ENABLE_NATIVE_ALIASES)
#  define _mm256_mulhi_epi16(a, b) simde_mm256_mulhi_epi16(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_mulhi_epu16 (simde__m256i a, simde__m256i b) {
  #if defined(SIMDE_X86_AVX2_NATIVE)
    return _mm256_mulhi_epu16(a, b);
  #else
    simde__m256i_private
      r_,
      a_ = simde__m256i_to_private(a),
      b_ = simde__m256i_to_private(b);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.u16) / sizeof(r_.u16[0])) ; i++) {
      r_.u16[i] = HEDLEY_STATIC_CAST(uint16_t, HEDLEY_STATIC_CAST(uint32_t, a_.u16[i]) * HEDLEY_STATIC_CAST(uint32_t, b_.u16[i]) >> 16);
    }

    return simde__m256i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX2_ENABLE_NATIVE_ALIASES)
#  define _mm256_mulhi_epu16(a, b) simde_mm256_mulhi_epu16(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_mulhrs_epi16 (simde__m256i a, simde__m256i b) {
  #if defined(SIMDE_X86_AVX2_NATIVE)
    return _mm256_mulhrs_epi16(a, b);
  #else
    simde__m256i_private
      r_,
      a_ = simde__m256i_to_private(a),
      b_ = simde__m256i_to_private(b);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.i16) / sizeof(r_.i16[0])) ; i++) {
      r_.i16[i] = HEDLEY_STATIC_CAST(int16_t, (((HEDLEY_STATIC_CAST(int32_t, a_.i16[i]) * HEDLEY_STATIC_CAST(int32_t, b_.i16[i])) + 0x4000) >> 15));
    }

    return simde__m256i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX2_ENABLE_NATIVE_ALIASES)
#  define _mm256_mulhrs_epi16(a, b) simde_mm256_mulhrs_epi16(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_mullo_epi16 (simde__m256i a, simde__m256i b) {
  #if defined(SIMDE_X86_AVX2_NATIVE)
    return _mm256_mullo_epi16(a, b);
  #else
    simde__m256i_private
    a_ = simde__m256i_to_private(a),
    b_ = simde__m256i_to_private(b),
    r_;

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.i16) / sizeof(r_.i16[0])) ; i++) {
      r_.i16[i] = HEDLEY_STATIC_CAST(int16_t, a_.i16[i] * b_.i16[i]);
    }

    return simde__m256i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX2_ENABLE_NATIVE_ALIASES)
  #undef _mm256_mullo_epi16
  #define _mm256_mullo_epi16(a, b) simde_mm256_mullo_epi16(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_mullo_epi32 (simde__m256i a, simde__m256i b) {
  #if defined(SIMDE_X86_AVX2_NATIVE)
    return _mm256_mullo_epi32(a, b);
  #else
    simde__m256i_private
    a_ = simde__m256i_to_private(a),
    b_ = simde__m256i_to_private(b),
    r_;

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.i32) / sizeof(r_.i32[0])) ; i++) {
      r_.i32[i] = HEDLEY_STATIC_CAST(int32_t, a_.i32[i] * b_.i32[i]);
    }

    return simde__m256i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX2_ENABLE_NATIVE_ALIASES)
  #undef _mm256_mullo_epi32
  #define _mm256_mullo_epi32(a, b) simde_mm256_mullo_epi32(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_x_mm256_mullo_epu32 (simde__m256i a, simde__m256i b) {
  simde__m256i_private
    r_,
    a_ = simde__m256i_to_private(a),
    b_ = simde__m256i_to_private(b);

    #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r_.u32 = a_.u32 * b_.u32;
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.u32) / sizeof(r_.u32[0])) ; i++) {
        r_.u32[i] = a_.u32[i] * b_.u32[i];
      }
    #endif

  return simde__m256i_from_private(r_);
}

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_or_si256 (simde__m256i a, simde__m256i b) {
#if defined(SIMDE_X86_AVX2_NATIVE)
  return _mm256_or_si256(a, b);
#else
  simde__m256i_private
    r_,
    a_ = simde__m256i_to_private(a),
    b_ = simde__m256i_to_private(b);

#if defined(SIMDE_X86_SSE2_NATIVE)
  r_.m128i[0] = simde_mm_or_si128(a_.m128i[0], b_.m128i[0]);
  r_.m128i[1] = simde_mm_or_si128(a_.m128i[1], b_.m128i[1]);
#elif defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
  r_.i32f = a_.i32f | b_.i32f;
#else
  SIMDE_VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.i32f) / sizeof(r_.i32f[0])) ; i++) {
    r_.i32f[i] = a_.i32f[i] | b_.i32f[i];
  }
#endif

  return simde__m256i_from_private(r_);
#endif
}
#if defined(SIMDE_X86_AVX2_ENABLE_NATIVE_ALIASES)
  #undef _mm256_or_si256
  #define _mm256_or_si256(a, b) simde_mm256_or_si256(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_packs_epi32 (simde__m256i a, simde__m256i b) {
#if defined(SIMDE_X86_AVX2_NATIVE)
  return _mm256_packs_epi32(a, b);
#else
  simde__m256i_private
    r_,
    v_[] = {
      simde__m256i_to_private(a),
      simde__m256i_to_private(b)
    };
#if defined(SIMDE_X86_SSE2_NATIVE) || defined(SIMDE_ARM_NEON_A32V7_NATIVE)
  r_.m128i_private[0] = simde__m128i_to_private(simde_mm_packs_epi32(simde__m128i_from_private(v_[0].m128i_private[0]), simde__m128i_from_private(v_[1].m128i_private[0])));
  r_.m128i_private[1] = simde__m128i_to_private(simde_mm_packs_epi32(simde__m128i_from_private(v_[0].m128i_private[1]), simde__m128i_from_private(v_[1].m128i_private[1])));
#else
  SIMDE_VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.i16) / sizeof(r_.i16[0])) ; i++) {
    const int32_t v = v_[(i >> 2) & 1].i32[(i & 11) - ((i & 8) >> 1)];
    r_.i16[i] = HEDLEY_STATIC_CAST(int16_t, (v > INT16_MAX) ? INT16_MAX : ((v < INT16_MIN) ? INT16_MIN : v));
  }
#endif

  return simde__m256i_from_private(r_);
#endif
}
#if defined(SIMDE_X86_AVX2_ENABLE_NATIVE_ALIASES)
  #undef _mm256_packs_epi32
  #define _mm256_packs_epi32(a, b) simde_mm256_packs_epi32(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_permute2x128_si256 (simde__m256i a, simde__m256i b, const int imm8)
    SIMDE_REQUIRE_RANGE(imm8, 0, 255) {
  simde__m256i_private
    r_,
    a_ = simde__m256i_to_private(a),
    b_ = simde__m256i_to_private(b);

  r_.m128i_private[0] = (imm8 & 0x08) ? simde__m128i_to_private(simde_mm_setzero_si128()) : ((imm8 & 0x02) ? b_.m128i_private[(imm8     ) & 1] : a_.m128i_private[(imm8     ) & 1]);
  r_.m128i_private[1] = (imm8 & 0x80) ? simde__m128i_to_private(simde_mm_setzero_si128()) : ((imm8 & 0x20) ? b_.m128i_private[(imm8 >> 4) & 1] : a_.m128i_private[(imm8 >> 4) & 1]);

  return simde__m256i_from_private(r_);
}
#if defined(SIMDE_X86_AVX2_NATIVE)
#  define simde_mm256_permute2x128_si256(a, b, imm8) _mm256_permute2x128_si256(a, b, imm8)
#endif
#if defined(SIMDE_X86_AVX2_ENABLE_NATIVE_ALIASES)
  #undef _mm256_permute2x128_si256
  #define _mm256_permute2x128_si256(a, b, imm8) simde_mm256_permute2x128_si256(a, b, imm8)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_permute4x64_epi64 (simde__m256i a, const int imm8)
SIMDE_REQUIRE_RANGE(imm8, 0, 255) {
  simde__m256i_private
    r_,
    a_ = simde__m256i_to_private(a);

  r_.i64[0] = (imm8 & 0x02) ? a_.i64[((imm8     ) & 1)+2] : a_.i64[(imm8     ) & 1];
  r_.i64[1] = (imm8 & 0x08) ? a_.i64[((imm8 >> 2  ) & 1)+2] : a_.i64[(imm8 >> 2  ) & 1];
  r_.i64[2] = (imm8 & 0x20) ? a_.i64[((imm8 >> 4  ) & 1)+2] : a_.i64[(imm8 >> 4  ) & 1];
  r_.i64[3] = (imm8 & 0x80) ? a_.i64[((imm8 >> 6  ) & 1)+2] : a_.i64[(imm8 >> 6  ) & 1];

  return simde__m256i_from_private(r_);
}
#if defined(SIMDE_X86_AVX2_NATIVE)
#  define simde_mm256_permute4x64_epi64(a, imm8) _mm256_permute4x64_epi64(a, imm8)
#endif
#if defined(SIMDE_X86_AVX2_ENABLE_NATIVE_ALIASES)
  #undef _mm256_permute4x64_epi64
  #define _mm256_permute4x64_epi64(a, imm8) simde_mm256_permute4x64_epi64(a, imm8)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256d
simde_mm256_permute4x64_pd (simde__m256d a, const int imm8)
SIMDE_REQUIRE_RANGE(imm8, 0, 255) {
  simde__m256d_private
    r_,
    a_ = simde__m256d_to_private(a);

  r_.f64[0] = (imm8 & 0x02) ? a_.f64[((imm8     ) & 1)+2] : a_.f64[(imm8     ) & 1];
  r_.f64[1] = (imm8 & 0x08) ? a_.f64[((imm8 >> 2  ) & 1)+2] : a_.f64[(imm8 >> 2  ) & 1];
  r_.f64[2] = (imm8 & 0x20) ? a_.f64[((imm8 >> 4  ) & 1)+2] : a_.f64[(imm8 >> 4  ) & 1];
  r_.f64[3] = (imm8 & 0x80) ? a_.f64[((imm8 >> 6  ) & 1)+2] : a_.f64[(imm8 >> 6  ) & 1];

  return simde__m256d_from_private(r_);
}
#if defined(SIMDE_X86_AVX2_NATIVE)
#  define simde_mm256_permute4x64_pd(a, imm8) _mm256_permute4x64_pd(a, imm8)
#endif
#if defined(SIMDE_X86_AVX2_ENABLE_NATIVE_ALIASES)
  #undef _mm256_permute4x64_pd
  #define _mm256_permute4x64_pd(a, imm8) simde_mm256_permute4x64_pd(a, imm8)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_shuffle_epi8 (simde__m256i a, simde__m256i b) {
#if defined(SIMDE_X86_AVX2_NATIVE)
  return _mm256_shuffle_epi8(a, b);
#else
  simde__m256i_private
    r_,
    a_ = simde__m256i_to_private(a),
    b_ = simde__m256i_to_private(b);

#if defined(SIMDE_X86_SSSE3_NATIVE)
  r_.m128i[0] = simde_mm_shuffle_epi8(a_.m128i[0], b_.m128i[0]);
  r_.m128i[1] = simde_mm_shuffle_epi8(a_.m128i[1], b_.m128i[1]);
#else
  SIMDE_VECTORIZE
  for (size_t i = 0 ; i < ((sizeof(r_.u8) / sizeof(r_.u8[0])) / 2) ; i++) {
    r_.u8[  i   ] = (b_.u8[  i   ] & 0x80) ? 0 : a_.u8[(b_.u8[  i   ] & 0x0f)     ];
    r_.u8[i + 16] = (b_.u8[i + 16] & 0x80) ? 0 : a_.u8[(b_.u8[i + 16] & 0x0f) + 16];
  }
#endif

  return simde__m256i_from_private(r_);
#endif
}
#if defined(SIMDE_X86_AVX2_ENABLE_NATIVE_ALIASES)
  #undef _mm256_shuffle_epi8
  #define _mm256_shuffle_epi8(a, b) simde_mm256_shuffle_epi8(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_shuffle_epi32 (simde__m256i a, const int imm8) {
  simde__m256i_private
    r_,
    a_ = simde__m256i_to_private(a);

  for (size_t i = 0 ; i < ((sizeof(r_.i32) / sizeof(r_.i32[0])) / 2) ; i++) {
    r_.i32[i] = a_.i32[(imm8 >> (i * 2)) & 3];
  }
  for (size_t i = 0 ; i < ((sizeof(r_.i32) / sizeof(r_.i32[0])) / 2) ; i++) {
    r_.i32[i + 4] = a_.i32[((imm8 >> (i * 2)) & 3) + 4];
  }

  return simde__m256i_from_private(r_);
}
#if defined(SIMDE_X86_AVX2_NATIVE)
#  define simde_mm256_shuffle_epi32(a, imm8) _mm256_shuffle_epi32(a, imm8)
#elif defined(SIMDE_X86_SSE2_NATIVE) && !defined(__PGI)
#  define simde_mm256_shuffle_epi32(a, imm8) \
     simde_mm256_set_m128i( \
       simde_mm_shuffle_epi32(simde_mm256_extracti128_si256(a, 1), (imm8)), \
       simde_mm_shuffle_epi32(simde_mm256_extracti128_si256(a, 0), (imm8)))
#elif defined(SIMDE_SHUFFLE_VECTOR_)
#  define simde_mm256_shuffle_epi32(a, imm8) (__extension__ ({ \
      const simde__m256i_private simde__tmp_a_ = simde__m256i_to_private(a); \
      simde__m256i_from_private((simde__m256i_private) { .i32 = \
          SIMDE_SHUFFLE_VECTOR_(32, 32, \
                                (simde__tmp_a_).i32, \
                                (simde__tmp_a_).i32, \
                                ((imm8)     ) & 3, \
                                ((imm8) >> 2) & 3, \
                                ((imm8) >> 4) & 3, \
                                ((imm8) >> 6) & 3, \
                                (((imm8)     ) & 3) + 4, \
                                (((imm8) >> 2) & 3) + 4, \
                                (((imm8) >> 4) & 3) + 4, \
                                (((imm8) >> 6) & 3) + 4) }); }))
#endif
#if defined(SIMDE_X86_AVX2_ENABLE_NATIVE_ALIASES)
  #undef _mm256_shuffle_epi32
  #define _mm256_shuffle_epi32(a, imm8) simde_mm256_shuffle_epi32(a, imm8)
#endif

#if defined(SIMDE_X86_AVX2_NATIVE)
#  define simde_mm256_shufflelo_epi16(a, imm8) _mm256_shufflelo_epi16(a, imm8)
#elif defined(SIMDE_X86_SSE2_NATIVE)
#  define simde_mm256_shufflelo_epi16(a, imm8) \
     simde_mm256_set_m128i( \
       simde_mm_shufflelo_epi16(simde_mm256_extracti128_si256(a, 1), (imm8)), \
       simde_mm_shufflelo_epi16(simde_mm256_extracti128_si256(a, 0), (imm8)))
#elif defined(SIMDE_SHUFFLE_VECTOR_)
#  define simde_mm256_shufflelo_epi16(a, imm8) (__extension__ ({ \
      const simde__m256i_private simde__tmp_a_ = simde__m256i_to_private(a); \
      simde__m256i_from_private((simde__m256i_private) { .i16 = \
        SIMDE_SHUFFLE_VECTOR_(16, 32, \
          (simde__tmp_a_).i16, \
          (simde__tmp_a_).i16, \
          (((imm8)     ) & 3), \
          (((imm8) >> 2) & 3), \
          (((imm8) >> 4) & 3), \
          (((imm8) >> 6) & 3), \
          4, 5, 6, 7, \
          ((((imm8)     ) & 3) + 8), \
          ((((imm8) >> 2) & 3) + 8), \
          ((((imm8) >> 4) & 3) + 8), \
          ((((imm8) >> 6) & 3) + 8), \
          12, 13, 14, 15) }); }))
#else
#  define simde_mm256_shufflelo_epi16(a, imm8) \
     simde_mm256_set_m128i( \
       simde_mm_shufflelo_epi16(simde_mm256_extracti128_si256(a, 1), imm8), \
       simde_mm_shufflelo_epi16(simde_mm256_extracti128_si256(a, 0), imm8))
#endif
#if defined(SIMDE_X86_AVX2_ENABLE_NATIVE_ALIASES)
  #undef _mm256_shufflelo_epi16
  #define _mm256_shufflelo_epi16(a, imm8) simde_mm256_shufflelo_epi16(a, imm8)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_sign_epi8 (simde__m256i a, simde__m256i b) {
#if defined(SIMDE_X86_AVX2_NATIVE)
  return _mm256_sign_epi8(a, b);
#else
  simde__m256i_private
    r_,
    a_ = simde__m256i_to_private(a),
    b_ = simde__m256i_to_private(b);

  SIMDE_VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.i8) / sizeof(r_.i8[0])) ; i++) {
    r_.i8[i] = (b_.i8[i] < INT32_C(0)) ? -a_.i8[i] : a_.i8[i];
  }

  return simde__m256i_from_private(r_);
#endif
}
#if defined(SIMDE_X86_AVX2_ENABLE_NATIVE_ALIASES)
  #undef _mm256_sign_epi8
  #define _mm256_sign_epi8(a, b) simde_mm256_sign_epi8(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_sign_epi16 (simde__m256i a, simde__m256i b) {
#if defined(SIMDE_X86_AVX2_NATIVE)
  return _mm256_sign_epi16(a, b);
#else
  simde__m256i_private
    r_,
    a_ = simde__m256i_to_private(a),
    b_ = simde__m256i_to_private(b);

  SIMDE_VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.i16) / sizeof(r_.i16[0])) ; i++) {
    r_.i16[i] = (b_.i16[i] < INT32_C(0)) ? -a_.i16[i] : a_.i16[i];
  }

  return simde__m256i_from_private(r_);
#endif
}
#if defined(SIMDE_X86_AVX2_ENABLE_NATIVE_ALIASES)
  #undef _mm256_sign_epi16
  #define _mm256_sign_epi16(a, b) simde_mm256_sign_epi16(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_sign_epi32(simde__m256i a, simde__m256i b) {
#if defined(SIMDE_X86_AVX2_NATIVE)
  return _mm256_sign_epi32(a, b);
#else
  simde__m256i_private
    r_,
    a_ = simde__m256i_to_private(a),
    b_ = simde__m256i_to_private(b);

  SIMDE_VECTORIZE
  for (size_t i = 0; i < (sizeof(r_.i32) / sizeof(r_.i32[0])); i++) {
    r_.i32[i] = (b_.i32[i] < INT32_C(0)) ? -a_.i32[i] : a_.i32[i];
  }

  return simde__m256i_from_private(r_);
#endif
}
#if defined(SIMDE_X86_AVX2_ENABLE_NATIVE_ALIASES)
  #undef _mm256_sign_epi32
  #define _mm256_sign_epi32(a, b) simde_mm256_sign_epi32(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_slli_epi16 (simde__m256i a, const int imm8)
    SIMDE_REQUIRE_RANGE(imm8, 0, 15) {
  /* Note: There is no consistency in how compilers handle values outside of
     the expected range, hence the discrepancy between what we allow and what
     Intel specifies.  Some compilers will return 0, others seem to just mask
     off everything outside of the range. */
  simde__m256i_private
    r_,
    a_ = simde__m256i_to_private(a);

  #if defined(SIMDE_POWER_ALTIVEC_P5_NATIVE)
    SIMDE_POWER_ALTIVEC_VECTOR(unsigned short) sv = vec_splats(HEDLEY_STATIC_CAST(unsigned short, imm8));
    for (size_t i = 0 ; i < (sizeof(a_.altivec_i16) / sizeof(a_.altivec_i16[0])) ; i++) {
      r_.altivec_i16[i] = vec_sl(a_.altivec_i16[i], sv);
    }
  #elif defined(SIMDE_VECTOR_SUBSCRIPT_SCALAR)
    r_.i16 = a_.i16 << HEDLEY_STATIC_CAST(int16_t, imm8);
  #else
    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.i16) / sizeof(r_.i16[0])) ; i++) {
      r_.i16[i] = HEDLEY_STATIC_CAST(int16_t, a_.i16[i] << (imm8 & 0xff));
    }
  #endif

  return simde__m256i_from_private(r_);
}
#if defined(SIMDE_X86_AVX2_NATIVE)
#  define simde_mm256_slli_epi16(a, imm8) _mm256_slli_epi16(a, imm8)
#elif defined(SIMDE_X86_SSE2_NATIVE)
#  define simde_mm256_slli_epi16(a, imm8) \
     simde_mm256_set_m128i( \
         simde_mm_slli_epi16(simde_mm256_extracti128_si256(a, 1), (imm8)), \
         simde_mm_slli_epi16(simde_mm256_extracti128_si256(a, 0), (imm8)))
#endif
#if defined(SIMDE_X86_AVX2_ENABLE_NATIVE_ALIASES)
  #undef _mm256_slli_epi16
  #define _mm256_slli_epi16(a, imm8) simde_mm256_slli_epi16(a, imm8)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_slli_epi32 (simde__m256i a, const int imm8)
    SIMDE_REQUIRE_RANGE(imm8, 0, 31) {
  simde__m256i_private
    r_,
    a_ = simde__m256i_to_private(a);

  #if defined(SIMDE_POWER_ALTIVEC_P5_NATIVE)
    SIMDE_POWER_ALTIVEC_VECTOR(unsigned int) sv = vec_splats(HEDLEY_STATIC_CAST(unsigned int, imm8));
    for (size_t i = 0 ; i < (sizeof(a_.altivec_i32) / sizeof(a_.altivec_i32[0])) ; i++) {
      r_.altivec_i32[i] = vec_sl(a_.altivec_i32[i], sv);
    }
  #elif defined(SIMDE_VECTOR_SUBSCRIPT_SCALAR)
    r_.i32 = a_.i32 << HEDLEY_STATIC_CAST(int32_t, imm8);
  #else
    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.i32) / sizeof(r_.i32[0])) ; i++) {
      r_.i32[i] = a_.i32[i] << (imm8 & 0xff);
    }
  #endif

  return simde__m256i_from_private(r_);
}
#if defined(SIMDE_X86_AVX2_NATIVE)
#  define simde_mm256_slli_epi32(a, imm8) _mm256_slli_epi32(a, imm8)
#elif defined(SIMDE_X86_SSE2_NATIVE)
#  define simde_mm256_slli_epi32(a, imm8) \
     simde_mm256_set_m128i( \
         simde_mm_slli_epi32(simde_mm256_extracti128_si256(a, 1), (imm8)), \
         simde_mm_slli_epi32(simde_mm256_extracti128_si256(a, 0), (imm8)))
#endif
#if defined(SIMDE_X86_AVX2_ENABLE_NATIVE_ALIASES)
  #undef _mm256_slli_epi32
  #define _mm256_slli_epi32(a, imm8) simde_mm256_slli_epi32(a, imm8)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_slli_epi64 (simde__m256i a, const int imm8)
    SIMDE_REQUIRE_RANGE(imm8, 0, 63) {
  simde__m256i_private
    r_,
    a_ = simde__m256i_to_private(a);

#if defined(SIMDE_VECTOR_SUBSCRIPT_SCALAR)
  r_.i64 = a_.i64 << HEDLEY_STATIC_CAST(int64_t, imm8);
#else
  SIMDE_VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.i64) / sizeof(r_.i64[0])) ; i++) {
    r_.i64[i] = a_.i64[i] << (imm8 & 0xff);
  }
#endif

  return simde__m256i_from_private(r_);
}
#if defined(SIMDE_X86_AVX2_NATIVE)
#  define simde_mm256_slli_epi64(a, imm8) _mm256_slli_epi64(a, imm8)
#elif defined(SIMDE_X86_SSE2_NATIVE)
#  define simde_mm256_slli_epi64(a, imm8) \
     simde_mm256_set_m128i( \
         simde_mm_slli_epi64(simde_mm256_extracti128_si256(a, 1), (imm8)), \
         simde_mm_slli_epi64(simde_mm256_extracti128_si256(a, 0), (imm8)))
#endif
#if defined(SIMDE_X86_AVX2_ENABLE_NATIVE_ALIASES)
  #undef _mm256_slli_epi64
  #define _mm256_slli_epi64(a, imm8) simde_mm256_slli_epi64(a, imm8)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_slli_si256 (simde__m256i a, const int imm8) {
  simde__m256i_private
    r_,
    a_ = simde__m256i_to_private(a);

  for (size_t h = 0 ; h < (sizeof(r_.m128i_private) / sizeof(r_.m128i_private[0])) ; h++) {
    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.m128i_private[h].i8) / sizeof(r_.m128i_private[h].i8[0])) ; i++) {
      const int e = HEDLEY_STATIC_CAST(int, i) - imm8;
      r_.m128i_private[h].i8[i] = (e >= 0) ? a_.m128i_private[h].i8[e] : 0;
    }
  }

  return simde__m256i_from_private(r_);
}
#if defined(SIMDE_X86_AVX2_NATIVE)
#  define simde_mm256_slli_si256(a, imm8) _mm256_slli_si256(a, imm8)
#elif defined(SIMDE_X86_SSE2_NATIVE) && !defined(__PGI)
#  define simde_mm256_slli_si256(a, imm8) \
     simde_mm256_set_m128i( \
         simde_mm_slli_si128(simde_mm256_extracti128_si256(a, 1), (imm8)), \
         simde_mm_slli_si128(simde_mm256_extracti128_si256(a, 0), (imm8)))
#elif defined(SIMDE_ARM_NEON_A32V7_NATIVE)
#  define simde_mm256_slli_si256(a, imm8) \
     simde_mm256_set_m128i( \
       simde_mm_bslli_si128(simde_mm256_extracti128_si256(a, 1), (imm8)), \
       simde_mm_bslli_si128(simde_mm256_extracti128_si256(a, 0), (imm8)))
#endif
#if defined(SIMDE_X86_AVX2_ENABLE_NATIVE_ALIASES)
  #undef _mm256_slli_si256
  #define _mm256_slli_si256(a, imm8) simde_mm256_slli_si256(a, imm8)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_sllv_epi32 (simde__m128i a, simde__m128i b) {
  simde__m128i_private
    a_ = simde__m128i_to_private(a),
    b_ = simde__m128i_to_private(b),
    r_;

  #if defined(SIMDE_VECTOR_SUBSCRIPT_SCALAR)
    r_.u32 = HEDLEY_STATIC_CAST(__typeof__(r_.u32), (b_.u32 < 32) & (a_.u32 << b_.u32));
  #else
    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.u32) / sizeof(r_.u32[0])) ; i++) {
      r_.u32[i] = (b_.u32[i] < 32) ? (a_.u32[i] << b_.u32[i]) : 0;
    }
  #endif

  return simde__m128i_from_private(r_);
}
#if defined(SIMDE_X86_AVX2_NATIVE)
  #define simde_mm_sllv_epi32(a, b) _mm_sllv_epi32(a, b)
#endif
#if defined(SIMDE_X86_AVX2_ENABLE_NATIVE_ALIASES)
  #undef _mm_sllv_epi32
  #define _mm_sllv_epi32(a, b) simde_mm_sllv_epi32(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_sllv_epi32 (simde__m256i a, simde__m256i b) {
  simde__m256i_private
    a_ = simde__m256i_to_private(a),
    b_ = simde__m256i_to_private(b),
    r_;

  #if defined(SIMDE_VECTOR_SUBSCRIPT_SCALAR)
    r_.u32 = HEDLEY_STATIC_CAST(__typeof__(r_.u32), (b_.u32 < 32) & (a_.u32 << b_.u32));
  #else
    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.u32) / sizeof(r_.u32[0])) ; i++) {
      r_.u32[i] = (b_.u32[i] < 32) ? (a_.u32[i] << b_.u32[i]) : 0;
    }
  #endif

  return simde__m256i_from_private(r_);
}
#if defined(SIMDE_X86_AVX2_NATIVE)
  #define simde_mm256_sllv_epi32(a, b) _mm256_sllv_epi32(a, b)
#endif
#if defined(SIMDE_X86_AVX2_ENABLE_NATIVE_ALIASES)
  #undef _mm256_sllv_epi32
  #define _mm256_sllv_epi32(a, b) simde_mm256_sllv_epi32(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_sllv_epi64 (simde__m128i a, simde__m128i b) {
  simde__m128i_private
    a_ = simde__m128i_to_private(a),
    b_ = simde__m128i_to_private(b),
    r_;

  #if defined(SIMDE_VECTOR_SUBSCRIPT_SCALAR)
    r_.u64 = HEDLEY_STATIC_CAST(__typeof__(r_.u64), (b_.u64 < 64) & (a_.u64 << b_.u64));
  #else
    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.u64) / sizeof(r_.u64[0])) ; i++) {
      r_.u64[i] = (b_.u64[i] < 64) ? (a_.u64[i] << b_.u64[i]) : 0;
    }
  #endif

  return simde__m128i_from_private(r_);
}
#if defined(SIMDE_X86_AVX2_NATIVE)
  #define simde_mm_sllv_epi64(a, b) _mm_sllv_epi64(a, b)
#endif
#if defined(SIMDE_X86_AVX2_ENABLE_NATIVE_ALIASES)
  #undef _mm_sllv_epi64
  #define _mm_sllv_epi64(a, b) simde_mm_sllv_epi64(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_sllv_epi64 (simde__m256i a, simde__m256i b) {
  simde__m256i_private
    a_ = simde__m256i_to_private(a),
    b_ = simde__m256i_to_private(b),
    r_;

  #if defined(SIMDE_VECTOR_SUBSCRIPT_SCALAR)
    r_.u64 = HEDLEY_STATIC_CAST(__typeof__(r_.u64), (b_.u64 < 64) & (a_.u64 << b_.u64));
  #else
    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.u64) / sizeof(r_.u64[0])) ; i++) {
      r_.u64[i] = (b_.u64[i] < 64) ? (a_.u64[i] << b_.u64[i]) : 0;
    }
  #endif

  return simde__m256i_from_private(r_);
}
#if defined(SIMDE_X86_AVX2_NATIVE)
  #define simde_mm256_sllv_epi64(a, b) _mm256_sllv_epi64(a, b)
#endif
#if defined(SIMDE_X86_AVX2_ENABLE_NATIVE_ALIASES)
  #undef _mm256_sllv_epi64
  #define _mm256_sllv_epi64(a, b) simde_mm256_sllv_epi64(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_srai_epi16 (simde__m256i a, const int imm8) {
  simde__m256i_private
    r_,
    a_ = simde__m256i_to_private(a);
  unsigned int shift = HEDLEY_STATIC_CAST(unsigned int, imm8);

  if (shift > 15) shift = 15;

  #if defined(SIMDE_VECTOR_SUBSCRIPT_SCALAR)
    r_.i16 = a_.i16 >> HEDLEY_STATIC_CAST(int16_t, shift);
  #else
    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.i16) / sizeof(r_.i16[0])) ; i++) {
      r_.i16[i] = a_.i16[i] >> shift;
    }
  #endif

  return simde__m256i_from_private(r_);
}
#if defined(SIMDE_X86_AVX2_NATIVE)
#  define simde_mm256_srai_epi16(a, imm8) _mm256_srai_epi16(a, imm8)
#elif defined(SIMDE_X86_SSE2_NATIVE)
#  define simde_mm256_srai_epi16(a, imm8) \
     simde_mm256_set_m128i( \
         simde_mm_srai_epi16(simde_mm256_extracti128_si256(a, 1), (imm8)), \
         simde_mm_srai_epi16(simde_mm256_extracti128_si256(a, 0), (imm8)))
#endif
#if defined(SIMDE_X86_AVX2_ENABLE_NATIVE_ALIASES)
  #undef _mm256_srai_epi16
  #define _mm256_srai_epi16(a, imm8) simde_mm256_srai_epi16(a, imm8)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_srai_epi32 (simde__m256i a, const int imm8) {
  simde__m256i_private
    r_,
    a_ = simde__m256i_to_private(a);
  unsigned int shift = HEDLEY_STATIC_CAST(unsigned int, imm8);

  if (shift > 31) shift = 31;

  #if defined(SIMDE_VECTOR_SUBSCRIPT_SCALAR)
    r_.i32 = a_.i32 >> HEDLEY_STATIC_CAST(int16_t, shift);
  #else
    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.i32) / sizeof(r_.i32[0])) ; i++) {
      r_.i32[i] = a_.i32[i] >> shift;
    }
  #endif

  return simde__m256i_from_private(r_);
}
#if defined(SIMDE_X86_AVX2_NATIVE)
#  define simde_mm256_srai_epi32(a, imm8) _mm256_srai_epi32(a, imm8)
#elif defined(SIMDE_X86_SSE2_NATIVE)
#  define simde_mm256_srai_epi32(a, imm8) \
     simde_mm256_set_m128i( \
         simde_mm_srai_epi32(simde_mm256_extracti128_si256(a, 1), (imm8)), \
         simde_mm_srai_epi32(simde_mm256_extracti128_si256(a, 0), (imm8)))
#endif
#if defined(SIMDE_X86_AVX2_ENABLE_NATIVE_ALIASES)
  #undef _mm256_srai_epi32
  #define _mm256_srai_epi32(a, imm8) simde_mm256_srai_epi32(a, imm8)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_srli_epi16 (simde__m256i a, const int imm8)
    SIMDE_REQUIRE_CONSTANT_RANGE(imm8, 0, 255) {
  simde__m256i_private
    r_,
    a_ = simde__m256i_to_private(a);

  if (imm8 > 15)
    return simde_mm256_setzero_si256();

  #if defined(SIMDE_POWER_ALTIVEC_P5_NATIVE)
    SIMDE_POWER_ALTIVEC_VECTOR(unsigned short) sv = vec_splats(HEDLEY_STATIC_CAST(unsigned short, imm8));
    for (size_t i = 0 ; i < (sizeof(a_.altivec_u16) / sizeof(a_.altivec_u16[0])) ; i++) {
      r_.altivec_u16[i] = vec_sr(a_.altivec_u16[i], sv);
    }
  #else
    if (HEDLEY_STATIC_CAST(unsigned int, imm8) > 15) {
      simde_memset(&r_, 0, sizeof(r_));
    } else {
      #if defined(SIMDE_VECTOR_SUBSCRIPT_SCALAR)
        r_.u16 = a_.u16 >> HEDLEY_STATIC_CAST(int16_t, imm8);
      #else
        SIMDE_VECTORIZE
        for (size_t i = 0 ; i < (sizeof(r_.u16) / sizeof(r_.u16[0])) ; i++) {
          r_.u16[i] = a_.u16[i] >> imm8;
        }
      #endif
    }
  #endif

  return simde__m256i_from_private(r_);
}
#if defined(SIMDE_X86_AVX2_NATIVE)
#  define simde_mm256_srli_epi16(a, imm8) _mm256_srli_epi16(a, imm8)
#elif defined(SIMDE_X86_SSE2_NATIVE)
#  define simde_mm256_srli_epi16(a, imm8) \
     simde_mm256_set_m128i( \
         simde_mm_srli_epi16(simde_mm256_extracti128_si256(a, 1), (imm8)), \
         simde_mm_srli_epi16(simde_mm256_extracti128_si256(a, 0), (imm8)))
#endif
#if defined(SIMDE_X86_AVX2_ENABLE_NATIVE_ALIASES)
  #undef _mm256_srli_epi16
  #define _mm256_srli_epi16(a, imm8) simde_mm256_srli_epi16(a, imm8)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_srli_epi32 (simde__m256i a, const int imm8) {
  simde__m256i_private
    r_,
    a_ = simde__m256i_to_private(a);

  #if defined(SIMDE_POWER_ALTIVEC_P5_NATIVE)
    SIMDE_POWER_ALTIVEC_VECTOR(unsigned int) sv = vec_splats(HEDLEY_STATIC_CAST(unsigned int, imm8));
    for (size_t i = 0 ; i < (sizeof(a_.altivec_u32) / sizeof(a_.altivec_u32[0])) ; i++) {
      r_.altivec_u32[i] = vec_sr(a_.altivec_u32[i], sv);
    }
  #elif defined(SIMDE_VECTOR_SUBSCRIPT_SCALAR)
    r_.u32 = a_.u32 >> HEDLEY_STATIC_CAST(int16_t, imm8);
  #else
    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.u32) / sizeof(r_.u32[0])) ; i++) {
      r_.u32[i] = a_.u32[i] >> imm8;
    }
  #endif

  return simde__m256i_from_private(r_);
}
#if defined(SIMDE_X86_AVX2_NATIVE)
#  define simde_mm256_srli_epi32(a, imm8) _mm256_srli_epi32(a, imm8)
#elif defined(SIMDE_X86_SSE2_NATIVE)
#  define simde_mm256_srli_epi32(a, imm8) \
     simde_mm256_set_m128i( \
         simde_mm_srli_epi32(simde_mm256_extracti128_si256(a, 1), (imm8)), \
         simde_mm_srli_epi32(simde_mm256_extracti128_si256(a, 0), (imm8)))
#endif
#if defined(SIMDE_X86_AVX2_ENABLE_NATIVE_ALIASES)
  #undef _mm256_srli_epi32
  #define _mm256_srli_epi32(a, imm8) simde_mm256_srli_epi32(a, imm8)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_srli_epi64 (simde__m256i a, const int imm8) {
  simde__m256i_private
    r_,
    a_ = simde__m256i_to_private(a);

#if defined(SIMDE_VECTOR_SUBSCRIPT_SCALAR)
  r_.u64 = a_.u64 >> HEDLEY_STATIC_CAST(int32_t, imm8);
#else
  SIMDE_VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.u64) / sizeof(r_.u64[0])) ; i++) {
    r_.u64[i] = a_.u64[i] >> imm8;
  }
#endif

  return simde__m256i_from_private(r_);
}
#if defined(SIMDE_X86_AVX2_NATIVE)
#  define simde_mm256_srli_epi64(a, imm8) _mm256_srli_epi64(a, imm8)
#elif defined(SIMDE_X86_SSE2_NATIVE)
#  define simde_mm256_srli_epi64(a, imm8) \
     simde_mm256_set_m128i( \
         simde_mm_srli_epi64(simde_mm256_extracti128_si256(a, 1), (imm8)), \
         simde_mm_srli_epi64(simde_mm256_extracti128_si256(a, 0), (imm8)))
#endif
#if defined(SIMDE_X86_AVX2_ENABLE_NATIVE_ALIASES)
  #undef _mm256_srli_epi64
  #define _mm256_srli_epi64(a, imm8) simde_mm256_srli_epi64(a, imm8)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_srli_si256 (simde__m256i a, const int imm8) {
  simde__m256i_private
    r_,
    a_ = simde__m256i_to_private(a);

  for (size_t h = 0 ; h < (sizeof(r_.m128i_private) / sizeof(r_.m128i_private[0])) ; h++) {
    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.m128i_private[h].i8) / sizeof(r_.m128i_private[h].i8[0])) ; i++) {
      const int e = imm8 + HEDLEY_STATIC_CAST(int, i);
      r_.m128i_private[h].i8[i] = (e < 16) ? a_.m128i_private[h].i8[e] : 0;
    }
  }

  return simde__m256i_from_private(r_);
}
#if defined(SIMDE_X86_AVX2_NATIVE)
#  define simde_mm256_srli_si256(a, imm8) _mm256_srli_si256(a, imm8)
#elif defined(SIMDE_X86_SSE2_NATIVE) && !defined(__PGI)
#  define simde_mm256_srli_si256(a, imm8) \
     simde_mm256_set_m128i( \
         simde_mm_srli_si128(simde_mm256_extracti128_si256(a, 1), (imm8)), \
         simde_mm_srli_si128(simde_mm256_extracti128_si256(a, 0), (imm8)))
#elif defined(SIMDE_ARM_NEON_A32V7_NATIVE)
#  define simde_mm256_srli_si256(a, imm8) \
     simde_mm256_set_m128i( \
       simde_mm_bsrli_si128(simde_mm256_extracti128_si256(a, 1), (imm8)), \
       simde_mm_bsrli_si128(simde_mm256_extracti128_si256(a, 0), (imm8)))
#endif
#if defined(SIMDE_X86_AVX2_ENABLE_NATIVE_ALIASES)
  #undef _mm256_srli_si256
  #define _mm256_srli_si256(a, imm8) simde_mm256_srli_si256(a, imm8)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_srlv_epi32 (simde__m128i a, simde__m128i b) {
  simde__m128i_private
    a_ = simde__m128i_to_private(a),
    b_ = simde__m128i_to_private(b),
    r_;

  #if defined(SIMDE_VECTOR_SUBSCRIPT_SCALAR)
    r_.u32 = HEDLEY_STATIC_CAST(__typeof__(r_.u32), (b_.u32 < 32) & (a_.u32 >> b_.u32));
  #else
    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.u32) / sizeof(r_.u32[0])) ; i++) {
      r_.u32[i] = (b_.u32[i] < 32) ? (a_.u32[i] >> b_.u32[i]) : 0;
    }
  #endif

  return simde__m128i_from_private(r_);
}
#if defined(SIMDE_X86_AVX2_NATIVE)
  #define simde_mm_srlv_epi32(a, b) _mm_srlv_epi32(a, b)
#endif
#if defined(SIMDE_X86_AVX2_ENABLE_NATIVE_ALIASES)
  #undef _mm_srlv_epi32
  #define _mm_srlv_epi32(a, b) simde_mm_srlv_epi32(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_srlv_epi32 (simde__m256i a, simde__m256i b) {
  simde__m256i_private
    a_ = simde__m256i_to_private(a),
    b_ = simde__m256i_to_private(b),
    r_;

  #if defined(SIMDE_VECTOR_SUBSCRIPT_SCALAR)
    r_.u32 = HEDLEY_STATIC_CAST(__typeof__(r_.u32), (b_.u32 < 32) & (a_.u32 >> b_.u32));
  #else
    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.u32) / sizeof(r_.u32[0])) ; i++) {
      r_.u32[i] = (b_.u32[i] < 32) ? (a_.u32[i] >> b_.u32[i]) : 0;
    }
  #endif

  return simde__m256i_from_private(r_);
}
#if defined(SIMDE_X86_AVX2_NATIVE)
  #define simde_mm256_srlv_epi32(a, b) _mm256_srlv_epi32(a, b)
#endif
#if defined(SIMDE_X86_AVX2_ENABLE_NATIVE_ALIASES)
  #undef _mm256_srlv_epi32
  #define _mm256_srlv_epi32(a, b) simde_mm256_srlv_epi32(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_srlv_epi64 (simde__m128i a, simde__m128i b) {
  simde__m128i_private
    a_ = simde__m128i_to_private(a),
    b_ = simde__m128i_to_private(b),
    r_;

  #if defined(SIMDE_VECTOR_SUBSCRIPT_SCALAR)
    r_.u64 = HEDLEY_STATIC_CAST(__typeof__(r_.u64), (b_.u64 < 64) & (a_.u64 >> b_.u64));
  #else
    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.u64) / sizeof(r_.u64[0])) ; i++) {
      r_.u64[i] = (b_.u64[i] < 64) ? (a_.u64[i] >> b_.u64[i]) : 0;
    }
  #endif

  return simde__m128i_from_private(r_);
}
#if defined(SIMDE_X86_AVX2_NATIVE)
  #define simde_mm_srlv_epi64(a, b) _mm_srlv_epi64(a, b)
#endif
#if defined(SIMDE_X86_AVX2_ENABLE_NATIVE_ALIASES)
  #undef _mm_srlv_epi64
  #define _mm_srlv_epi64(a, b) simde_mm_srlv_epi64(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_srlv_epi64 (simde__m256i a, simde__m256i b) {
  simde__m256i_private
    a_ = simde__m256i_to_private(a),
    b_ = simde__m256i_to_private(b),
    r_;

  #if defined(SIMDE_VECTOR_SUBSCRIPT_SCALAR)
    r_.u64 = HEDLEY_STATIC_CAST(__typeof__(r_.u64), (b_.u64 < 64) & (a_.u64 >> b_.u64));
  #else
    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.u64) / sizeof(r_.u64[0])) ; i++) {
      r_.u64[i] = (b_.u64[i] < 64) ? (a_.u64[i] >> b_.u64[i]) : 0;
    }
  #endif

  return simde__m256i_from_private(r_);
}
#if defined(SIMDE_X86_AVX2_NATIVE)
  #define simde_mm256_srlv_epi64(a, b) _mm256_srlv_epi64(a, b)
#endif
#if defined(SIMDE_X86_AVX2_ENABLE_NATIVE_ALIASES)
  #undef _mm256_srlv_epi64
  #define _mm256_srlv_epi64(a, b) simde_mm256_srlv_epi64(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_stream_load_si256 (const simde__m256i* mem_addr) {
  simde_assert_aligned(32, mem_addr);

  #if defined(SIMDE_X86_AVX2_NATIVE)
    return _mm256_stream_load_si256(HEDLEY_CONST_CAST(simde__m256i*, mem_addr));
  #else
    /* Use memcpy to avoid aliasing; data must still be 32-byte aligned */
    simde__m256i r;
    simde_memcpy(&r, mem_addr, sizeof(r));
    return r;
  #endif
}
#if defined(SIMDE_X86_AVX2_ENABLE_NATIVE_ALIASES)
#  define _mm256_stream_load_si256(mem_addr) simde_mm256_stream_load_si256(mem_addr)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_sub_epi8 (simde__m256i a, simde__m256i b) {
#if defined(SIMDE_X86_AVX2_NATIVE)
  return _mm256_sub_epi8(a, b);
#else
  simde__m256i_private
    r_,
    a_ = simde__m256i_to_private(a),
    b_ = simde__m256i_to_private(b);

  #if defined(SIMDE_X86_SSE2_NATIVE)
    r_.m128i[0] = simde_mm_sub_epi8(a_.m128i[0], b_.m128i[0]);
    r_.m128i[1] = simde_mm_sub_epi8(a_.m128i[1], b_.m128i[1]);
  #elif defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
    r_.i8 = a_.i8 - b_.i8;
  #else
    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.i8) / sizeof(r_.i8[0])) ; i++) {
      r_.i8[i] = a_.i8[i] - b_.i8[i];
    }
  #endif

  return simde__m256i_from_private(r_);
#endif
}
#if defined(SIMDE_X86_AVX2_ENABLE_NATIVE_ALIASES)
  #undef _mm256_sub_epi8
  #define _mm256_sub_epi8(a, b) simde_mm256_sub_epi8(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_sub_epi16 (simde__m256i a, simde__m256i b) {
#if defined(SIMDE_X86_AVX2_NATIVE)
  return _mm256_sub_epi16(a, b);
#else
  simde__m256i_private
    r_,
    a_ = simde__m256i_to_private(a),
    b_ = simde__m256i_to_private(b);

  #if defined(SIMDE_X86_SSE2_NATIVE)
    r_.m128i[0] = simde_mm_sub_epi16(a_.m128i[0], b_.m128i[0]);
    r_.m128i[1] = simde_mm_sub_epi16(a_.m128i[1], b_.m128i[1]);
  #elif defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
    r_.i16 = a_.i16 - b_.i16;
  #else
    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.i16) / sizeof(r_.i16[0])) ; i++) {
      r_.i16[i] = a_.i16[i] - b_.i16[i];
    }
  #endif

  return simde__m256i_from_private(r_);
#endif
}
#if defined(SIMDE_X86_AVX2_ENABLE_NATIVE_ALIASES)
  #undef _mm256_sub_epi16
  #define _mm256_sub_epi16(a, b) simde_mm256_sub_epi16(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_sub_epi32 (simde__m256i a, simde__m256i b) {
#if defined(SIMDE_X86_AVX2_NATIVE)
  return _mm256_sub_epi32(a, b);
#else
  simde__m256i_private
    r_,
    a_ = simde__m256i_to_private(a),
    b_ = simde__m256i_to_private(b);

  #if defined(SIMDE_X86_SSE2_NATIVE)
    r_.m128i[0] = simde_mm_sub_epi32(a_.m128i[0], b_.m128i[0]);
    r_.m128i[1] = simde_mm_sub_epi32(a_.m128i[1], b_.m128i[1]);
  #elif defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
    r_.i32 = a_.i32 - b_.i32;
  #else
    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.i32) / sizeof(r_.i32[0])) ; i++) {
      r_.i32[i] = a_.i32[i] - b_.i32[i];
    }
  #endif

  return simde__m256i_from_private(r_);
#endif
}
#if defined(SIMDE_X86_AVX2_ENABLE_NATIVE_ALIASES)
  #undef _mm256_sub_epi32
  #define _mm256_sub_epi32(a, b) simde_mm256_sub_epi32(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_sub_epi64 (simde__m256i a, simde__m256i b) {
  #if defined(SIMDE_X86_AVX2_NATIVE)
    return _mm256_sub_epi64(a, b);
  #else
    simde__m256i_private
      r_,
      a_ = simde__m256i_to_private(a),
      b_ = simde__m256i_to_private(b);

    #if defined(SIMDE_X86_SSE2_NATIVE)
      r_.m128i[0] = simde_mm_sub_epi64(a_.m128i[0], b_.m128i[0]);
      r_.m128i[1] = simde_mm_sub_epi64(a_.m128i[1], b_.m128i[1]);
    #elif defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r_.i64 = a_.i64 - b_.i64;
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.i64) / sizeof(r_.i64[0])) ; i++) {
        r_.i64[i] = a_.i64[i] - b_.i64[i];
      }
    #endif

  return simde__m256i_from_private(r_);
#endif
}
#if defined(SIMDE_X86_AVX2_ENABLE_NATIVE_ALIASES)
  #undef _mm256_sub_epi64
  #define _mm256_sub_epi64(a, b) simde_mm256_sub_epi64(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_x_mm256_sub_epu32 (simde__m256i a, simde__m256i b) {
  simde__m256i_private
    r_,
    a_ = simde__m256i_to_private(a),
    b_ = simde__m256i_to_private(b);

  #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
    r_.u32 = a_.u32 - b_.u32;
  #else
    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.u32) / sizeof(r_.u32[0])) ; i++) {
      r_.u32[i] = a_.u32[i] - b_.u32[i];
    }
  #endif

  return simde__m256i_from_private(r_);
}

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_subs_epi8 (simde__m256i a, simde__m256i b) {
#if defined(SIMDE_X86_AVX2_NATIVE)
  return _mm256_subs_epi8(a, b);
#else
  simde__m256i_private
    r_,
    a_ = simde__m256i_to_private(a),
    b_ = simde__m256i_to_private(b);

#if defined(SIMDE_X86_SSE2_NATIVE) && !defined(HEDLEY_INTEL_VERSION)
  SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.m128i) / sizeof(r_.m128i[0])) ; i++) {
      r_.m128i[i] = simde_mm_subs_epi8(a_.m128i[i], b_.m128i[i]);
    }
#else
  SIMDE_VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.i8) / sizeof(r_.i8[0])) ; i++) {
    const int32_t tmp =
      HEDLEY_STATIC_CAST(int16_t, a_.i8[i]) -
      HEDLEY_STATIC_CAST(int16_t, b_.i8[i]);
    r_.i8[i] = HEDLEY_STATIC_CAST(int8_t, ((tmp < INT8_MAX) ? ((tmp > INT8_MIN) ? tmp : INT8_MIN) : INT8_MAX));
  }
#endif

  return simde__m256i_from_private(r_);
#endif
}
#if defined(SIMDE_X86_AVX2_ENABLE_NATIVE_ALIASES)
  #undef _mm256_subs_epi8
  #define _mm256_subs_epi8(a, b) simde_mm256_subs_epi8(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_subs_epi16(simde__m256i a, simde__m256i b) {
#if defined(SIMDE_X86_AVX2_NATIVE)
  return _mm256_subs_epi16(a, b);
#else
  simde__m256i_private
    r_,
    a_ = simde__m256i_to_private(a),
    b_ = simde__m256i_to_private(b);

#if defined(SIMDE_X86_SSE2_NATIVE) && !defined(HEDLEY_INTEL_VERSION)
  SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.m128i) / sizeof(r_.m128i[0])) ; i++) {
      r_.m128i[i] = simde_mm_subs_epi16(a_.m128i[i], b_.m128i[i]);
    }
#else
  SIMDE_VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.i16) / sizeof(r_.i16[0])) ; i++) {
    const int32_t tmp =
      HEDLEY_STATIC_CAST(int32_t, a_.i16[i]) -
      HEDLEY_STATIC_CAST(int32_t, b_.i16[i]);
    r_.i16[i] = HEDLEY_STATIC_CAST(int16_t, ((tmp < INT16_MAX) ? ((tmp > INT16_MIN) ? tmp : INT16_MIN) : INT16_MAX));
  }
#endif

  return simde__m256i_from_private(r_);
#endif
}
#if defined(SIMDE_X86_AVX2_ENABLE_NATIVE_ALIASES)
  #undef _mm256_subs_epi16
  #define _mm256_subs_epi16(a, b) simde_mm256_subs_epi16(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_subs_epu8 (simde__m256i a, simde__m256i b) {
#if defined(SIMDE_X86_AVX2_NATIVE)
  return _mm256_subs_epu8(a, b);
#else
  simde__m256i_private
    r_,
    a_ = simde__m256i_to_private(a),
    b_ = simde__m256i_to_private(b);

#if defined(SIMDE_X86_SSE2_NATIVE)
  r_.m128i[0] = simde_mm_subs_epu8(a_.m128i[0], b_.m128i[0]);
  r_.m128i[1] = simde_mm_subs_epu8(a_.m128i[1], b_.m128i[1]);
#else
  SIMDE_VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.u8) / sizeof(r_.u8[0])) ; i++) {
    r_.u8[i] = (a_.u8[i] > b_.u8[i]) ? (a_.u8[i] - b_.u8[i]) : UINT8_C(0);
  }
#endif

  return simde__m256i_from_private(r_);
#endif
}
#if defined(SIMDE_X86_AVX2_ENABLE_NATIVE_ALIASES)
  #undef _mm256_subs_epu8
  #define _mm256_subs_epu8(a, b) simde_mm256_subs_epu8(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_subs_epu16(simde__m256i a, simde__m256i b) {
#if defined(SIMDE_X86_AVX2_NATIVE)
  return _mm256_subs_epu16(a, b);
#else
  simde__m256i_private
    r_,
    a_ = simde__m256i_to_private(a),
    b_ = simde__m256i_to_private(b);

#if defined(SIMDE_X86_SSE2_NATIVE)
  r_.m128i[0] = simde_mm_subs_epu16(a_.m128i[0], b_.m128i[0]);
  r_.m128i[1] = simde_mm_subs_epu16(a_.m128i[1], b_.m128i[1]);
#else
  SIMDE_VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.u16) / sizeof(r_.u16[0])) ; i++) {
    r_.u16[i] = (a_.u16[i] > b_.u16[i]) ? (a_.u16[i] - b_.u16[i]) : UINT16_C(0);
  }
#endif

  return simde__m256i_from_private(r_);
#endif
}
#if defined(SIMDE_X86_AVX2_ENABLE_NATIVE_ALIASES)
  #undef _mm256_subs_epu16
  #define _mm256_subs_epu16(a, b) simde_mm256_subs_epu16(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_unpacklo_epi8 (simde__m256i a, simde__m256i b) {
  #if defined(SIMDE_X86_AVX2_NATIVE)
    return _mm256_unpacklo_epi8(a, b);
  #else
    simde__m256i_private
      r_,
      a_ = simde__m256i_to_private(a),
      b_ = simde__m256i_to_private(b);

    #if defined(SIMDE_SHUFFLE_VECTOR_)
      r_.i8 = SIMDE_SHUFFLE_VECTOR_(8, 32, a_.i8, b_.i8,
           0, 32,  1, 33,  2, 34,  3, 35,
           4, 36,  5, 37,  6, 38,  7, 39,
          16, 48, 17, 49, 18, 50, 19, 51,
          20, 52, 21, 53, 22, 54, 23, 55);
    #else
      r_.m128i[0] = simde_mm_unpacklo_epi8(a_.m128i[0], b_.m128i[0]);
      r_.m128i[1] = simde_mm_unpacklo_epi8(a_.m128i[1], b_.m128i[1]);
    #endif

    return simde__m256i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX2_ENABLE_NATIVE_ALIASES)
  #undef _mm256_unpacklo_epi8
  #define _mm256_unpacklo_epi8(a, b) simde_mm256_unpacklo_epi8(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_unpacklo_epi16 (simde__m256i a, simde__m256i b) {
  #if defined(SIMDE_X86_AVX2_NATIVE)
    return _mm256_unpacklo_epi16(a, b);
  #else
    simde__m256i_private
      r_,
      a_ = simde__m256i_to_private(a),
      b_ = simde__m256i_to_private(b);

    #if defined(SIMDE_SHUFFLE_VECTOR_)
      r_.i16 =SIMDE_SHUFFLE_VECTOR_(16, 32, a_.i16, b_.i16,
        0, 16, 1, 17, 2, 18, 3, 19, 8, 24, 9, 25, 10, 26, 11, 27);
    #else
      r_.m128i[0] = simde_mm_unpacklo_epi16(a_.m128i[0], b_.m128i[0]);
      r_.m128i[1] = simde_mm_unpacklo_epi16(a_.m128i[1], b_.m128i[1]);
    #endif

    return simde__m256i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX2_ENABLE_NATIVE_ALIASES)
  #undef _mm256_unpacklo_epi16
  #define _mm256_unpacklo_epi16(a, b) simde_mm256_unpacklo_epi16(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_unpacklo_epi32 (simde__m256i a, simde__m256i b) {
#if defined(SIMDE_X86_AVX2_NATIVE)
  return _mm256_unpacklo_epi32(a, b);
#else
  simde__m256i_private
    r_,
    a_ = simde__m256i_to_private(a),
    b_ = simde__m256i_to_private(b);

#if defined(SIMDE_SHUFFLE_VECTOR_)
  r_.i32 = SIMDE_SHUFFLE_VECTOR_(32, 32, a_.i32, b_.i32,
                                0, 8, 1, 9, 4, 12, 5, 13);
#else
  r_.m128i[0] = simde_mm_unpacklo_epi32(a_.m128i[0], b_.m128i[0]);
  r_.m128i[1] = simde_mm_unpacklo_epi32(a_.m128i[1], b_.m128i[1]);
#endif

  return simde__m256i_from_private(r_);
#endif
}
#if defined(SIMDE_X86_AVX2_ENABLE_NATIVE_ALIASES)
  #undef _mm256_unpacklo_epi32
  #define _mm256_unpacklo_epi32(a, b) simde_mm256_unpacklo_epi32(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_unpacklo_epi64 (simde__m256i a, simde__m256i b) {
#if defined(SIMDE_X86_AVX2_NATIVE)
  return _mm256_unpacklo_epi64(a, b);
#else
  simde__m256i_private
    r_,
    a_ = simde__m256i_to_private(a),
    b_ = simde__m256i_to_private(b);

#if defined(SIMDE_SHUFFLE_VECTOR_)
  r_.i64 = SIMDE_SHUFFLE_VECTOR_(64, 32, a_.i64, b_.i64, 0, 4, 2, 6);
#else
  r_.m128i[0] = simde_mm_unpacklo_epi64(a_.m128i[0], b_.m128i[0]);
  r_.m128i[1] = simde_mm_unpacklo_epi64(a_.m128i[1], b_.m128i[1]);
#endif

  return simde__m256i_from_private(r_);
#endif
}
#if defined(SIMDE_X86_AVX2_ENABLE_NATIVE_ALIASES)
  #undef _mm256_unpacklo_epi64
  #define _mm256_unpacklo_epi64(a, b) simde_mm256_unpacklo_epi64(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_unpackhi_epi8 (simde__m256i a, simde__m256i b) {
  #if defined(SIMDE_X86_AVX2_NATIVE)
    return _mm256_unpackhi_epi8(a, b);
  #else
    simde__m256i_private
      r_,
      a_ = simde__m256i_to_private(a),
      b_ = simde__m256i_to_private(b);

    #if defined(SIMDE_SHUFFLE_VECTOR_)
      r_.i8 = SIMDE_SHUFFLE_VECTOR_(8, 32, a_.i8, b_.i8,
           8, 40,  9, 41, 10, 42, 11, 43,
          12, 44, 13, 45, 14, 46, 15, 47,
          24, 56, 25, 57, 26, 58, 27, 59,
          28, 60, 29, 61, 30, 62, 31, 63);
    #else
      r_.m128i[0] = simde_mm_unpackhi_epi8(a_.m128i[0], b_.m128i[0]);
      r_.m128i[1] = simde_mm_unpackhi_epi8(a_.m128i[1], b_.m128i[1]);
    #endif

    return simde__m256i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX2_ENABLE_NATIVE_ALIASES)
  #undef _mm256_unpackhi_epi8
  #define _mm256_unpackhi_epi8(a, b) simde_mm256_unpackhi_epi8(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_unpackhi_epi16 (simde__m256i a, simde__m256i b) {
  #if defined(SIMDE_X86_AVX2_NATIVE)
    return _mm256_unpackhi_epi16(a, b);
  #else
    simde__m256i_private
      r_,
      a_ = simde__m256i_to_private(a),
      b_ = simde__m256i_to_private(b);

    #if defined(SIMDE_SHUFFLE_VECTOR_)
      r_.i16 = SIMDE_SHUFFLE_VECTOR_(16, 32, a_.i16, b_.i16,
         4, 20,  5, 21,  6, 22,  7, 23,
        12, 28, 13, 29, 14, 30, 15, 31);
    #else
      r_.m128i[0] = simde_mm_unpackhi_epi16(a_.m128i[0], b_.m128i[0]);
      r_.m128i[1] = simde_mm_unpackhi_epi16(a_.m128i[1], b_.m128i[1]);
    #endif

    return simde__m256i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX2_ENABLE_NATIVE_ALIASES)
  #undef _mm256_unpackhi_epi16
  #define _mm256_unpackhi_epi16(a, b) simde_mm256_unpackhi_epi16(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_unpackhi_epi32 (simde__m256i a, simde__m256i b) {
#if defined(SIMDE_X86_AVX2_NATIVE)
  return _mm256_unpackhi_epi32(a, b);
#else
  simde__m256i_private
    r_,
    a_ = simde__m256i_to_private(a),
    b_ = simde__m256i_to_private(b);

#if defined(SIMDE_SHUFFLE_VECTOR_)
  r_.i32 = SIMDE_SHUFFLE_VECTOR_(32, 32, a_.i32, b_.i32,
                                 2, 10, 3, 11, 6, 14, 7, 15);
#else
  r_.m128i[0] = simde_mm_unpackhi_epi32(a_.m128i[0], b_.m128i[0]);
  r_.m128i[1] = simde_mm_unpackhi_epi32(a_.m128i[1], b_.m128i[1]);
#endif

  return simde__m256i_from_private(r_);
#endif
}
#if defined(SIMDE_X86_AVX2_ENABLE_NATIVE_ALIASES)
  #undef _mm256_unpackhi_epi32
  #define _mm256_unpackhi_epi32(a, b) simde_mm256_unpackhi_epi32(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_unpackhi_epi64 (simde__m256i a, simde__m256i b) {
#if defined(SIMDE_X86_AVX2_NATIVE)
  return _mm256_unpackhi_epi64(a, b);
#else
  simde__m256i_private
    r_,
    a_ = simde__m256i_to_private(a),
    b_ = simde__m256i_to_private(b);

#if defined(SIMDE_SHUFFLE_VECTOR_)
  r_.i64 = SIMDE_SHUFFLE_VECTOR_(64, 32, a_.i64, b_.i64, 1, 5, 3, 7);
#else
  r_.m128i[0] = simde_mm_unpackhi_epi64(a_.m128i[0], b_.m128i[0]);
  r_.m128i[1] = simde_mm_unpackhi_epi64(a_.m128i[1], b_.m128i[1]);
#endif

  return simde__m256i_from_private(r_);
#endif
}
#if defined(SIMDE_X86_AVX2_ENABLE_NATIVE_ALIASES)
  #undef _mm256_unpackhi_epi64
  #define _mm256_unpackhi_epi64(a, b) simde_mm256_unpackhi_epi64(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_xor_si256 (simde__m256i a, simde__m256i b) {
#if defined(SIMDE_X86_AVX2_NATIVE)
  return _mm256_xor_si256(a, b);
#else
  simde__m256i_private
    r_,
    a_ = simde__m256i_to_private(a),
    b_ = simde__m256i_to_private(b);

#if defined(SIMDE_X86_SSE2_NATIVE)
  r_.m128i[0] = simde_mm_xor_si128(a_.m128i[0], b_.m128i[0]);
  r_.m128i[1] = simde_mm_xor_si128(a_.m128i[1], b_.m128i[1]);
#elif defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
  r_.i32f = a_.i32f ^ b_.i32f;
#else
  SIMDE_VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.i64) / sizeof(r_.i64[0])) ; i++) {
    r_.i64[i] = a_.i64[i] ^ b_.i64[i];
  }
#endif

  return simde__m256i_from_private(r_);
#endif
}
#if defined(SIMDE_X86_AVX2_ENABLE_NATIVE_ALIASES)
  #undef _mm256_xor_si256
  #define _mm256_xor_si256(a, b) simde_mm256_xor_si256(a, b)
#endif

SIMDE_END_DECLS_

HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_X86_AVX2_H) */
