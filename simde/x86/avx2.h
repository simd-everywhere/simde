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
 *   2018      Evan Nemerson <evan@nemerson.com>
 *   2019      Michael R. Crusoe <michael.crusoe@gmail.com>
 */

#include "sse4.1.h"
#if !defined(SIMDE__AVX2_H)
#  if !defined(SIMDE__AVX2_H)
#    define SIMDE__AVX2_H
#  endif
#  include "avx.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS

#  if defined(SIMDE_AVX2_NATIVE)
#    undef SIMDE_AVX2_NATIVE
#  endif
#  if defined(SIMDE_AVX2_FORCE_NATIVE)
#    define SIMDE_AVX2_NATIVE
#  elif defined(__AVX2__) && !defined(SIMDE_AVX2_NO_NATIVE) && !defined(SIMDE_NO_NATIVE)
#    define SIMDE_AVX2_NATIVE
#  elif defined(__ARM_NEON) && !defined(SIMDE_AVX2_NO_NEON) && !defined(SIMDE_NO_NEON)
#    define SIMDE_AVX2_NEON
#  endif

#  if defined(SIMDE_AVX2_NATIVE) && !defined(SIMDE_AVX_NATIVE)
#    if defined(SIMDE_AVX2_FORCE_NATIVE)
#      error Native AVX2 support requires native AVX support
#    else
#      warning Native AVX2 support requires native AVX support, disabling
#      undef SIMDE_AVX2_NATIVE
#    endif
#  elif defined(SIMDE_AVX2_NEON) && !defined(SIMDE_AVX_NEON)
#    warning AVX2 NEON support requires AVX NEON support, disabling
#    undef SIMDE_AVX_NEON
#  endif

#  if defined(SIMDE_AVX2_NATIVE)
#    include <immintrin.h>
#  endif

#  if !defined(SIMDE_AVX2_NATIVE) && defined(SIMDE_ENABLE_NATIVE_ALIASES)
#    define SIMDE_AVX2_ENABLE_NATIVE_ALIASES
#  endif

#  include <stdint.h>

SIMDE__BEGIN_DECLS

SIMDE__FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_add_epi8 (simde__m256i a, simde__m256i b) {
#if defined(SIMDE_AVX2_NATIVE)
  return _mm256_add_epi8(a, b);
#else
  simde__m256i_private
    r_,
    a_ = simde__m256i_to_private(a),
    b_ = simde__m256i_to_private(b);

#if defined(SIMDE_SSE2_NATIVE)
  r_.m128i[0] = _mm_add_epi8(a_.m128i[0], b_.m128i[0]);
  r_.m128i[1] = _mm_add_epi8(a_.m128i[1], b_.m128i[1]);
#elif defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
  r_.i8 = a_.i8 + b_.i8;
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.i8) / sizeof(r_.i8[0])) ; i++) {
    r_.i8[i] = a_.i8[i] + b_.i8[i];
  }
#endif

  return simde__m256i_from_private(r_);
#endif
}
#if defined(SIMDE_AVX2_ENABLE_NATIVE_ALIASES)
#  define _mm256_add_epi8(a, b) simde_mm256_add_epi8(a, b)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_add_epi16 (simde__m256i a, simde__m256i b) {
#if defined(SIMDE_AVX2_NATIVE)
  return _mm256_add_epi16(a, b);
#else
  simde__m256i_private
    r_,
    a_ = simde__m256i_to_private(a),
    b_ = simde__m256i_to_private(b);

#if defined(SIMDE_SSE2_NATIVE)
  r_.m128i[0] = _mm_add_epi16(a_.m128i[0], b_.m128i[0]);
  r_.m128i[1] = _mm_add_epi16(a_.m128i[1], b_.m128i[1]);
#elif defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
  r_.i16 = a_.i16 + b_.i16;
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.i16) / sizeof(r_.i16[0])) ; i++) {
    r_.i16[i] = a_.i16[i] + b_.i16[i];
  }
#endif

  return simde__m256i_from_private(r_);
#endif
}
#if defined(SIMDE_AVX2_ENABLE_NATIVE_ALIASES)
#  define _mm256_add_epi16(a, b) simde_mm256_add_epi16(a, b)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_add_epi32 (simde__m256i a, simde__m256i b) {
#if defined(SIMDE_AVX2_NATIVE)
  return _mm256_add_epi32(a, b);
#else
  simde__m256i_private
    r_,
    a_ = simde__m256i_to_private(a),
    b_ = simde__m256i_to_private(b);

#if defined(SIMDE_SSE2_NATIVE)
  r_.m128i[0] = _mm_add_epi32(a_.m128i[0], b_.m128i[0]);
  r_.m128i[1] = _mm_add_epi32(a_.m128i[1], b_.m128i[1]);
#elif defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
  r_.i32 = a_.i32 + b_.i32;
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.i32) / sizeof(r_.i32[0])) ; i++) {
    r_.i32[i] = a_.i32[i] + b_.i32[i];
  }
#endif

  return simde__m256i_from_private(r_);
#endif
}
#if defined(SIMDE_AVX2_ENABLE_NATIVE_ALIASES)
#  define _mm256_add_epi32(a, b) simde_mm256_add_epi32(a, b)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_add_epi64 (simde__m256i a, simde__m256i b) {
#if defined(SIMDE_AVX2_NATIVE)
  return _mm256_add_epi64(a, b);
#else
  simde__m256i_private
    r_,
    a_ = simde__m256i_to_private(a),
    b_ = simde__m256i_to_private(b);

#if defined(SIMDE_SSE2_NATIVE)
  r_.m128i[0] = _mm_add_epi64(a_.m128i[0], b_.m128i[0]);
  r_.m128i[1] = _mm_add_epi64(a_.m128i[1], b_.m128i[1]);
#elif defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
  r_.i64 = a_.i64 + b_.i64;
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.i64) / sizeof(r_.i64[0])) ; i++) {
    r_.i64[i] = a_.i64[i] + b_.i64[i];
  }
#endif

  return simde__m256i_from_private(r_);
#endif
}
#if defined(SIMDE_AVX2_ENABLE_NATIVE_ALIASES)
#  define _mm256_add_epi64(a, b) simde_mm256_add_epi64(a, b)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_alignr_epi8 (simde__m256i a, simde__m256i b, int count) {
  simde__m256i_private
    r_,
    a_ = simde__m256i_to_private(a),
    b_ = simde__m256i_to_private(b);
  const int bits = (8 * count) % 64;
  const int eo = count / 8;

  switch (eo) {
    case 0:
      r_.u64[0]  = b_.u64[0] >> bits;
      r_.u64[0] |= b_.u64[1] << (64 - bits);
      r_.u64[1]  = b_.u64[1] >> bits;
      r_.u64[1] |= a_.u64[0] << (64 - bits);
      r_.u64[2]  = b_.u64[2] >> bits;
      r_.u64[2] |= b_.u64[3] << (64 - bits);
      r_.u64[3]  = b_.u64[3] >> bits;
      r_.u64[3] |= a_.u64[2] << (64 - bits);
      break;
    case 1:
      r_.u64[0]  = b_.u64[1] >> bits;
      r_.u64[0] |= a_.u64[0] << (64 - bits);
      r_.u64[1]  = a_.u64[0] >> bits;
      r_.u64[1] |= a_.u64[1] << (64 - bits);
      r_.u64[2]  = b_.u64[3] >> bits;
      r_.u64[2] |= a_.u64[2] << (64 - bits);
      r_.u64[3]  = a_.u64[2] >> bits;
      r_.u64[3] |= a_.u64[3] << (64 - bits);
       break;
    case 2:
      r_.u64[0]  = a_.u64[0] >> bits;
      r_.u64[0] |= a_.u64[1] << (64 - bits);
      r_.u64[1]  = a_.u64[1] >> bits;
      r_.u64[2]  = a_.u64[2] >> bits;
      r_.u64[2] |= a_.u64[3] << (64 - bits);
      r_.u64[3]  = a_.u64[3] >> bits;
      break;
    case 3:
      r_.u64[0]  = a_.u64[1] >> bits;
      r_.u64[1]  = 0;
      r_.u64[2]  = a_.u64[3] >> bits;
      r_.u64[3]  = 0;
      break;
    default:
      HEDLEY_UNREACHABLE();
      break;
  }

  return simde__m256i_from_private(r_);
}
#if defined(SIMDE_AVX2_NATIVE)
#  define simde_mm256_alignr_epi8(a, b, count) _mm256_alignr_epi8(a, b, count)
#elif defined(SIMDE_SSSE3_NATIVE)
#  define simde_mm256_alignr_epi8(a, b, count) \
      simde_mm256_set_m128i( \
          _mm_alignr_epi8(simde__m256i_to_private(a).m128i[1], simde__m256i_to_private(b).m128i[1], (count)), \
          _mm_alignr_epi8(simde__m256i_to_private(a).m128i[0], simde__m256i_to_private(b).m128i[0], (count)))
#endif
#if defined(SIMDE_AVX2_ENABLE_NATIVE_ALIASES)
#  define _mm256_alignr_epi8(a, b, count) simde_mm256_alignr_epi8(a, b, (count))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_and_si256 (simde__m256i a, simde__m256i b) {
#if defined(SIMDE_AVX2_NATIVE)
  return _mm256_and_si256(a, b);
#else
  simde__m256i_private
    r_,
    a_ = simde__m256i_to_private(a),
    b_ = simde__m256i_to_private(b);

#if defined(SIMDE_SSE2_NATIVE)
  r_.m128i[0] = _mm_and_si128(a_.m128i[0], b_.m128i[0]);
  r_.m128i[1] = _mm_and_si128(a_.m128i[1], b_.m128i[1]);
#elif defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
  r_.i32f = a_.i32f & b_.i32f;
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.i64) / sizeof(r_.i64[0])) ; i++) {
    r_.i64[i] = a_.i64[i] & b_.i64[i];
  }
#endif

  return simde__m256i_from_private(r_);
#endif
}
#if defined(SIMDE_AVX2_ENABLE_NATIVE_ALIASES)
#  define _mm256_and_si256(a, b) simde_mm256_and_si256(a, b)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_andnot_si256 (simde__m256i a, simde__m256i b) {
#if defined(SIMDE_AVX2_NATIVE)
  return _mm256_andnot_si256(a, b);
#else
  simde__m256i_private
    r_,
    a_ = simde__m256i_to_private(a),
    b_ = simde__m256i_to_private(b);

#if defined(SIMDE_SSE2_NATIVE) || defined(SIMDE_SSE2_NEON)
  r_.m128i_private[0] = simde__m128i_to_private(simde_mm_andnot_si128(simde__m128i_from_private(a_.m128i_private[0]), simde__m128i_from_private(b_.m128i_private[0])));
  r_.m128i_private[1] = simde__m128i_to_private(simde_mm_andnot_si128(simde__m128i_from_private(a_.m128i_private[1]), simde__m128i_from_private(b_.m128i_private[1])));
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.i32f) / sizeof(r_.i32f[0])) ; i++) {
    r_.i32f[i] = ~(a_.i32f[i]) & b_.i32f[i];
  }
#endif

  return simde__m256i_from_private(r_);
#endif
}
#if defined(SIMDE_AVX2_ENABLE_NATIVE_ALIASES)
#  define _mm256_andnot_si256(a, b) simde_mm256_andnot_si256(a, b)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_adds_epu8 (simde__m256i a, simde__m256i b) {
#if defined(SIMDE_AVX2_NATIVE)
  return _mm256_adds_epu8(a, b);
#else
  simde__m256i_private
    r_,
    a_ = simde__m256i_to_private(a),
    b_ = simde__m256i_to_private(b);

#if defined(SIMDE_SSE2_NATIVE)
  r_.m128i[0] = _mm_adds_epu8(a_.m128i[0], b_.m128i[0]);
  r_.m128i[1] = _mm_adds_epu8(a_.m128i[1], b_.m128i[1]);
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.u8) / sizeof(r_.u8[0])) ; i++) {
    r_.u8[i] = ((UINT8_MAX - a_.u8[i]) > b_.u8[i]) ? (a_.u8[i] + b_.u8[i]) : UINT8_MAX;
  }
#endif

  return simde__m256i_from_private(r_);
#endif
}
#if defined(SIMDE_AVX2_ENABLE_NATIVE_ALIASES)
#  define _mm256_adds_epu8(a, b) simde_mm256_adds_epu8(a, b)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_blendv_epi8(simde__m256i a, simde__m256i b, simde__m256i mask) {
#if defined(SIMDE_AVX2_NATIVE)
  return _mm256_blendv_epi8(a, b, mask);
#else
  simde__m256i_private
    r_,
    a_ = simde__m256i_to_private(a),
    b_ = simde__m256i_to_private(b),
    mask_ = simde__m256i_to_private(mask);

#if defined(SIMDE_SSE4_1_NATIVE)
  r_.m128i_private[0] = simde__m128i_to_private(_mm_blendv_epi8(simde__m128i_from_private(a_.m128i_private[0]), simde__m128i_from_private(b_.m128i_private[0]), simde__m128i_from_private(mask_.m128i_private[0])));
  r_.m128i_private[1] = simde__m128i_to_private(_mm_blendv_epi8(simde__m128i_from_private(a_.m128i_private[1]), simde__m128i_from_private(b_.m128i_private[1]), simde__m128i_from_private(mask_.m128i_private[1])));
#else
  SIMDE__VECTORIZE
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
#if defined(SIMDE_AVX2_ENABLE_NATIVE_ALIASES)
#  define _mm256_blendv_epi8(a, b, mask) simde_mm256_blendv_epi8(a, b, mask)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_broadcastsi128_si256 (simde__m128i a) {
#if defined(SIMDE_AVX2_NATIVE)
  return _mm256_broadcastsi128_si256(a);
#else
  simde__m256i_private r_;
  simde__m128i_private a_ = simde__m128i_to_private(a);

#if defined(SIMDE_SSE2_NATIVE)
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
#if defined(SIMDE_AVX2_ENABLE_NATIVE_ALIASES)
#  define _mm256_broadcastsi128_si256(a) simde_mm256_broadcastsi128_si256(a)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_cmpeq_epi8 (simde__m256i a, simde__m256i b) {
#if defined(SIMDE_AVX2_NATIVE)
  return _mm256_cmpeq_epi8(a, b);
#else
  simde__m256i_private
    r_,
    a_ = simde__m256i_to_private(a),
    b_ = simde__m256i_to_private(b);

  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.i8) / sizeof(r_.i8[0])) ; i++) {
    r_.i8[i] = (a_.i8[i] == b_.i8[i]) ? ~INT8_C(0) : INT8_C(0);
  }

  return simde__m256i_from_private(r_);
#endif
}
#if defined(SIMDE_AVX2_ENABLE_NATIVE_ALIASES)
#  define _mm256_cmpeq_epi8(a, b) simde_mm256_cmpeq_epi8(a, b)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_cmpeq_epi32 (simde__m256i a, simde__m256i b) {
#if defined(SIMDE_AVX2_NATIVE)
  return _mm256_cmpeq_epi32(a, b);
#else
  simde__m256i_private
    r_,
    a_ = simde__m256i_to_private(a),
    b_ = simde__m256i_to_private(b);

#if defined(SIMDE_SSE2_NATIVE) || defined(SIMDE_SSE2_NEON)
  r_.m128i[0] = simde_mm_cmpeq_epi32(a_.m128i[0], b_.m128i[0]);
  r_.m128i[1] = simde_mm_cmpeq_epi32(a_.m128i[1], b_.m128i[1]);
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.i32) / sizeof(r_.i32[0])) ; i++) {
    r_.i32[i] = (a_.i32[i] == b_.i32[i]) ? ~INT32_C(0) : INT32_C(0);
  }
#endif

  return simde__m256i_from_private(r_);
#endif
}
#if defined(SIMDE_AVX2_ENABLE_NATIVE_ALIASES)
#  define _mm256_cmpeq_epi32(a, b) simde_mm256_cmpeq_epi32(a, b)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_cmpgt_epi16 (simde__m256i a, simde__m256i b) {
#if defined(SIMDE_AVX2_NATIVE)
  return _mm256_cmpgt_epi16(a, b);
#else
  simde__m256i_private
    r_,
    a_ = simde__m256i_to_private(a),
    b_ = simde__m256i_to_private(b);

#if defined(SIMDE_SSE2_NATIVE)
  r_.m128i[0] = _mm_cmpgt_epi16(a_.m128i[0], b_.m128i[0]);
  r_.m128i[1] = _mm_cmpgt_epi16(a_.m128i[1], b_.m128i[1]);
#elif defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
  r_.i16 = a_.i16 > b_.i16;
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.i16) / sizeof(r_.i16[0])) ; i++) {
    r_.i16[i] = (a_.i16[i] > b_.i16[i]) ? ~INT16_C(0) : INT16_C(0);
  }
#endif

  return simde__m256i_from_private(r_);
#endif
}
#if defined(SIMDE_AVX2_ENABLE_NATIVE_ALIASES)
#  define _mm256_cmpgt_epi16(a, b) simde_mm256_cmpgt_epi16(a, b)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_cmpgt_epi32 (simde__m256i a, simde__m256i b) {
#if defined(SIMDE_AVX2_NATIVE)
  return _mm256_cmpgt_epi32(a, b);
#else
  simde__m256i_private
    r_,
    a_ = simde__m256i_to_private(a),
    b_ = simde__m256i_to_private(b);

#if defined(SIMDE_SSE2_NATIVE)
  r_.m128i[0] = _mm_cmpgt_epi32(a_.m128i[0], b_.m128i[0]);
  r_.m128i[1] = _mm_cmpgt_epi32(a_.m128i[1], b_.m128i[1]);
#elif defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
  r_.i32 = a_.i32 > b_.i32;
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.i32) / sizeof(r_.i32[0])) ; i++) {
    r_.i32[i] = (a_.i32[i] > b_.i32[i]) ? ~INT32_C(0) : INT32_C(0);
  }
#endif

  return simde__m256i_from_private(r_);
#endif
}
#if defined(SIMDE_AVX2_ENABLE_NATIVE_ALIASES)
#  define _mm256_cmpgt_epi32(a, b) simde_mm256_cmpgt_epi32(a, b)
#endif


SIMDE__FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_cvtepi8_epi16 (simde__m128i a) {
#if defined(SIMDE_AVX2_NATIVE)
  return _mm256_cvtepi8_epi16(a);
#else
  simde__m256i_private r_;
  simde__m128i_private a_ = simde__m128i_to_private(a);

#if defined(SIMDE__CONVERT_VECTOR)
  SIMDE__CONVERT_VECTOR(r_.i16, a_.i8);
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.i16) / sizeof(r_.i16[0])) ; i++) {
    r_.i16[i] = a_.i8[i];
  }
#endif

  return simde__m256i_from_private(r_);
#endif
}
#if defined(SIMDE_AVX2_ENABLE_NATIVE_ALIASES)
#  define _mm256_cvtepi8_epi16(a) simde_mm256_cvtepi8_epi16(a)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_cvtepi8_epi32 (simde__m128i a) {
#if defined(SIMDE_AVX2_NATIVE)
  return _mm256_cvtepi8_epi32(a);
#else
  simde__m256i_private r_;
  simde__m128i_private a_ = simde__m128i_to_private(a);

#if defined(SIMDE__CONVERT_VECTOR)
  SIMDE__CONVERT_VECTOR(r_.i32, a_.m64_private[0].i8);
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.i32) / sizeof(r_.i32[0])) ; i++) {
    r_.i32[i] = a_.i8[i];
  }
#endif

  return simde__m256i_from_private(r_);
#endif
}
#if defined(SIMDE_AVX2_ENABLE_NATIVE_ALIASES)
#  define _mm256_cvtepi8_epi32(a) simde_mm256_cvtepi8_epi16(a)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_cvtepi8_epi64 (simde__m128i a) {
#if defined(SIMDE_AVX2_NATIVE)
  return _mm256_cvtepi8_epi64(a);
#else
  simde__m256i_private r_;
  simde__m128i_private a_ = simde__m128i_to_private(a);

  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.i64) / sizeof(r_.i64[0])) ; i++) {
    r_.i64[i] = a_.i8[i];
  }

  return simde__m256i_from_private(r_);
#endif
}
#if defined(SIMDE_AVX2_ENABLE_NATIVE_ALIASES)
#  define _mm256_cvtepi8_epi64(a) simde_mm256_cvtepi8_epi64(a)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_cvtepi16_epi32 (simde__m128i a) {
#if defined(SIMDE_AVX2_NATIVE)
  return _mm256_cvtepi16_epi32(a);
#else
  simde__m256i_private r_;
  simde__m128i_private a_ = simde__m128i_to_private(a);

#if defined(SIMDE__CONVERT_VECTOR)
  SIMDE__CONVERT_VECTOR(r_.i32, a_.i16);
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.i32) / sizeof(r_.i32[0])) ; i++) {
    r_.i32[i] = a_.i16[i];
  }
#endif

  return simde__m256i_from_private(r_);
#endif
}
#if defined(SIMDE_AVX2_ENABLE_NATIVE_ALIASES)
#  define _mm256_cvtepi16_epi32(a) simde_mm256_cvtepi16_epi32(a)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_cvtepi16_epi64 (simde__m128i a) {
#if defined(SIMDE_AVX2_NATIVE)
  return _mm256_cvtepi16_epi64(a);
#else
  simde__m256i_private r_;
  simde__m128i_private a_ = simde__m128i_to_private(a);

#if defined(SIMDE__CONVERT_VECTOR)
  SIMDE__CONVERT_VECTOR(r_.i64, a_.m64_private[0].i16);
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.i64) / sizeof(r_.i64[0])) ; i++) {
    r_.i64[i] = a_.i16[i];
  }
#endif

  return simde__m256i_from_private(r_);
#endif
}
#if defined(SIMDE_AVX2_ENABLE_NATIVE_ALIASES)
#  define _mm256_cvtepi16_epi64(a) simde_mm256_cvtepi16_epi64(a)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_cvtepi32_epi64 (simde__m128i a) {
#if defined(SIMDE_AVX2_NATIVE)
  return _mm256_cvtepi32_epi64(a);
#else
  simde__m256i_private r_;
  simde__m128i_private a_ = simde__m128i_to_private(a);

#if defined(SIMDE__CONVERT_VECTOR)
  SIMDE__CONVERT_VECTOR(r_.i64, a_.i32);
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.i64) / sizeof(r_.i64[0])) ; i++) {
    r_.i64[i] = a_.i32[i];
  }
#endif

  return simde__m256i_from_private(r_);
#endif
}
#if defined(SIMDE_AVX2_ENABLE_NATIVE_ALIASES)
#  define _mm256_cvtepi32_epi64(a) simde_mm256_cvtepi32_epi64(a)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_cvtepu8_epi16 (simde__m128i a) {
#if defined(SIMDE_AVX2_NATIVE)
  return _mm256_cvtepu8_epi16(a);
#else
  simde__m256i_private r_;
  simde__m128i_private a_ = simde__m128i_to_private(a);

#if defined(SIMDE__CONVERT_VECTOR)
  SIMDE__CONVERT_VECTOR(r_.i16, a_.u8);
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.i16) / sizeof(r_.i16[0])) ; i++) {
    r_.i16[i] = a_.u8[i];
  }
#endif

  return simde__m256i_from_private(r_);
#endif
}
#if defined(SIMDE_AVX2_ENABLE_NATIVE_ALIASES)
#  define _mm256_cvtepu8_epi64(a) simde_mm256_cvtepu8_epi64(a)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_cvtepu8_epi32 (simde__m128i a) {
#if defined(SIMDE_AVX2_NATIVE)
  return _mm256_cvtepu8_epi32(a);
#else
  simde__m256i_private r_;
  simde__m128i_private a_ = simde__m128i_to_private(a);

#if defined(SIMDE__CONVERT_VECTOR)
  SIMDE__CONVERT_VECTOR(r_.i32, a_.m64_private[0].u8);
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.i32) / sizeof(r_.i32[0])) ; i++) {
    r_.i32[i] = a_.u8[i];
  }
#endif

  return simde__m256i_from_private(r_);
#endif
}
#if defined(SIMDE_AVX2_ENABLE_NATIVE_ALIASES)
#  define _mm256_cvtepu8_epi32(a) simde_mm256_cvtepu8_epi32(a)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_cvtepu8_epi64 (simde__m128i a) {
#if defined(SIMDE_AVX2_NATIVE)
  return _mm256_cvtepu8_epi64(a);
#else
  simde__m256i_private r_;
  simde__m128i_private a_ = simde__m128i_to_private(a);

  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.i64) / sizeof(r_.i64[0])) ; i++) {
    r_.i64[i] = a_.u8[i];
  }

  return simde__m256i_from_private(r_);
#endif
}
#if defined(SIMDE_AVX2_ENABLE_NATIVE_ALIASES)
#  define _mm256_cvtepu8_epi64(a) simde_mm256_cvtepu8_epi64(a)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_cvtepu16_epi32 (simde__m128i a) {
#if defined(SIMDE_AVX2_NATIVE)
  return _mm256_cvtepu16_epi32(a);
#else
  simde__m256i_private r_;
  simde__m128i_private a_ = simde__m128i_to_private(a);

#if defined(SIMDE__CONVERT_VECTOR)
  SIMDE__CONVERT_VECTOR(r_.i32, a_.u16);
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.i32) / sizeof(r_.i32[0])) ; i++) {
    r_.i32[i] = a_.u16[i];
  }
#endif

  return simde__m256i_from_private(r_);
#endif
}
#if defined(SIMDE_AVX2_ENABLE_NATIVE_ALIASES)
#  define _mm256_cvtepu16_epi32(a) simde_mm256_cvtepu16_epi32(a)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_cvtepu16_epi64 (simde__m128i a) {
#if defined(SIMDE_AVX2_NATIVE)
  return _mm256_cvtepu16_epi64(a);
#else
  simde__m256i_private r_;
  simde__m128i_private a_ = simde__m128i_to_private(a);

#if defined(SIMDE__CONVERT_VECTOR)
  SIMDE__CONVERT_VECTOR(r_.i64, a_.m64_private[0].u16);
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.i64) / sizeof(r_.i64[0])) ; i++) {
    r_.i64[i] = a_.u16[i];
  }
#endif

  return simde__m256i_from_private(r_);
#endif
}
#if defined(SIMDE_AVX2_ENABLE_NATIVE_ALIASES)
#  define _mm256_cvtepu16_epi64(a) simde_mm256_cvtepu16_epi64(a)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_cvtepu32_epi64 (simde__m128i a) {
#if defined(SIMDE_AVX2_NATIVE)
  return _mm256_cvtepu32_epi64(a);
#else
  simde__m256i_private r_;
  simde__m128i_private a_ = simde__m128i_to_private(a);

#if defined(SIMDE__CONVERT_VECTOR)
  SIMDE__CONVERT_VECTOR(r_.i64, a_.u32);
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.i64) / sizeof(r_.i64[0])) ; i++) {
    r_.i64[i] = a_.u32[i];
  }
#endif

  return simde__m256i_from_private(r_);
#endif
}
#if defined(SIMDE_AVX2_ENABLE_NATIVE_ALIASES)
#  define _mm256_cvtepu32_epi64(a) simde_mm256_cvtepu32_epi64(a)
#endif

SIMDE__FUNCTION_ATTRIBUTES
int
simde_mm256_extract_epi8 (simde__m256i a, const int index) {
  return simde__m256i_to_private(a).i8[index];
}
#if defined(SIMDE_AVX2_ENABLE_NATIVE_ALIASES)
#  define _mm256_extract_epi8(a, index) simde_mm256_extract_epi8(a, index)
#endif

SIMDE__FUNCTION_ATTRIBUTES
int
simde_mm256_extract_epi16 (simde__m256i a, const int index) {
  return simde__m256i_to_private(a).i16[index];
}
#if defined(SIMDE_AVX2_ENABLE_NATIVE_ALIASES)
#  define _mm256_extract_epi16(a, index) simde_mm256_extract_epi16(a, index)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128i
simde_mm256_extracti128_si256 (simde__m256i a, const int imm8)
    HEDLEY_REQUIRE_MSG((imm8 & 1) == imm8, "imm8 must be 0 or 1") {
  return simde__m256i_to_private(a).m128i[imm8];
}
#if defined(SIMDE_AVX2_NATIVE)
#  define simde_mm256_extracti128_si256(a, imm8) _mm256_extracti128_si256(a, imm8)
#endif
#if defined(SIMDE_AVX2_ENABLE_NATIVE_ALIASES)
#  define _mm256_extracti128_si256(a, imm8) simde_mm256_extracti128_si256(a, imm8)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_max_epi8 (simde__m256i a, simde__m256i b) {
#if defined(SIMDE_AVX2_NATIVE) && !defined(__PGI)
  return _mm256_max_epi8(a, b);
#else
  simde__m256i_private
    r_,
    a_ = simde__m256i_to_private(a),
    b_ = simde__m256i_to_private(b);

#if defined(SIMDE_SSE4_1_NATIVE)
  r_.m128i[0] = _mm_max_epi8(a_.m128i[0], b_.m128i[0]);
  r_.m128i[1] = _mm_max_epi8(a_.m128i[1], b_.m128i[1]);
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.i8) / sizeof(r_.i8[0])) ; i++) {
    r_.i8[i] = a_.i8[i] > b_.i8[i] ? a_.i8[i] : b_.i8[i];
  }
#endif

  return simde__m256i_from_private(r_);
#endif
}
#if defined(SIMDE_AVX2_ENABLE_NATIVE_ALIASES)
#  define _mm256_max_epi8(a, b) simde_mm256_max_epi8(a, b)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_max_epu8 (simde__m256i a, simde__m256i b) {
#if defined(SIMDE_AVX2_NATIVE)
  return _mm256_max_epu8(a, b);
#else
  simde__m256i_private
    r_,
    a_ = simde__m256i_to_private(a),
    b_ = simde__m256i_to_private(b);

#if defined(SIMDE_SSE2_NATIVE) || defined(SIMDE_SSE2_NEON)
  r_.m128i[0] = simde_mm_max_epu8(a_.m128i[0], b_.m128i[0]);
  r_.m128i[1] = simde_mm_max_epu8(a_.m128i[1], b_.m128i[1]);
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.u8) / sizeof(r_.u8[0])) ; i++) {
    r_.u8[i] = (a_.u8[i] > b_.u8[i]) ? a_.u8[i] : b_.u8[i];
  }
#endif

  return simde__m256i_from_private(r_);
#endif
}
#if defined(SIMDE_AVX2_ENABLE_NATIVE_ALIASES)
#  define _mm256_max_epu8(a, b) simde_mm256_max_epu8(a, b)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_max_epi16 (simde__m256i a, simde__m256i b) {
#if defined(SIMDE_AVX2_NATIVE)
  return _mm256_max_epi16(a, b);
#else
  simde__m256i_private
    r_,
    a_ = simde__m256i_to_private(a),
    b_ = simde__m256i_to_private(b);

#if defined(SIMDE_SSE2_NATIVE)
  r_.m128i[0] = _mm_max_epi16(a_.m128i[0], b_.m128i[0]);
  r_.m128i[1] = _mm_max_epi16(a_.m128i[1], b_.m128i[1]);
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.i16) / sizeof(r_.i16[0])) ; i++) {
    r_.i16[i] = (a_.i16[i] > b_.i16[i]) ? a_.i16[i] : b_.i16[i];
  }
#endif

  return simde__m256i_from_private(r_);
#endif
}
#if defined(SIMDE_AVX2_ENABLE_NATIVE_ALIASES)
#  define _mm256_max_epi16(a, b) simde_mm256_max_epi16(a, b)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_max_epi32 (simde__m256i a, simde__m256i b) {
#if defined(SIMDE_AVX2_NATIVE)
  return _mm256_max_epi32(a, b);
#else
  simde__m256i_private
    r_,
    a_ = simde__m256i_to_private(a),
    b_ = simde__m256i_to_private(b);

#if defined(SIMDE_SSE4_1_NATIVE)
  r_.m128i[0] = _mm_max_epi32(a_.m128i[0], b_.m128i[0]);
  r_.m128i[1] = _mm_max_epi32(a_.m128i[1], b_.m128i[1]);
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.i32) / sizeof(r_.i32[0])) ; i++) {
    r_.i32[i] = a_.i32[i] > b_.i32[i] ? a_.i32[i] : b_.i32[i];
  }
#endif

  return simde__m256i_from_private(r_);
#endif
}
#if defined(SIMDE_AVX2_ENABLE_NATIVE_ALIASES)
#  define _mm256_max_epi32(a, b) simde_mm256_max_epi32(a, b)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_min_epu8 (simde__m256i a, simde__m256i b) {
#if defined(SIMDE_AVX2_NATIVE)
  return _mm256_min_epu8(a, b);
#else
  simde__m256i_private
    r_,
    a_ = simde__m256i_to_private(a),
    b_ = simde__m256i_to_private(b);

#if defined(SIMDE_SSE2_NATIVE)
  r_.m128i[0] = _mm_min_epu8(a_.m128i[0], b_.m128i[0]);
  r_.m128i[1] = _mm_min_epu8(a_.m128i[1], b_.m128i[1]);
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.u8) / sizeof(r_.u8[0])) ; i++) {
    r_.u8[i] = (a_.u8[i] < b_.u8[i]) ? a_.u8[i] : b_.u8[i];
  }
#endif

  return simde__m256i_from_private(r_);
#endif
}
#if defined(SIMDE_AVX22_ENABLE_NATIVE_ALIASES)
#  define _mm256_min_epu8(a, b) simde_mm256_min_epu8(a, b)
#endif

SIMDE__FUNCTION_ATTRIBUTES
int32_t
simde_mm256_movemask_epi8 (simde__m256i a) {
#if defined(SIMDE_AVX2_NATIVE)
  return _mm256_movemask_epi8(a);
#else
  simde__m256i_private a_ = simde__m256i_to_private(a);
  int32_t r = 0;
  SIMDE__VECTORIZE_REDUCTION(|:r)
  for (size_t i = 0 ; i < 32 ; i++) {
    r |= (a_.u8[31 - i] >> 7) << (31 - i);
  }
  return r;
#endif
}
#if defined(SIMDE_AVX2_ENABLE_NATIVE_ALIASES)
#  define _mm256_movemask_epi8(a) simde_mm256_movemask_epi8(a)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_or_si256 (simde__m256i a, simde__m256i b) {
#if defined(SIMDE_AVX2_NATIVE)
  return _mm256_or_si256(a, b);
#else
  simde__m256i_private
    r_,
    a_ = simde__m256i_to_private(a),
    b_ = simde__m256i_to_private(b);

#if defined(SIMDE_SSE2_NATIVE)
  r_.m128i[0] = _mm_or_si128(a_.m128i[0], b_.m128i[0]);
  r_.m128i[1] = _mm_or_si128(a_.m128i[1], b_.m128i[1]);
#elif defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
  r_.i32f = a_.i32f | b_.i32f;
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.i32f) / sizeof(r_.i32f[0])) ; i++) {
    r_.i32f[i] = a_.i32f[i] | b_.i32f[i];
  }
#endif

  return simde__m256i_from_private(r_);
#endif
}
#if defined(SIMDE_AVX2_ENABLE_NATIVE_ALIASES)
#  define _mm256_or_si256(a, b) simde_mm256_or_si128(a, b)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_packs_epi32 (simde__m256i a, simde__m256i b) {
#if defined(SIMDE_AVX2_NATIVE)
  return _mm256_packs_epi32(a, b);
#else
  simde__m256i_private
    r_,
    a_ = simde__m256i_to_private(a),
    b_ = simde__m256i_to_private(b);

#if defined(SIMDE_SSE2_NATIVE) || defined(SIMDE_SSE2_NEON)
  r_.m128i_private[0] = simde__m128i_to_private(simde_mm_packs_epi32(simde__m128i_from_private(a_.m128i_private[0]), simde__m128i_from_private(b_.m128i_private[0])));
  r_.m128i_private[1] = simde__m128i_to_private(simde_mm_packs_epi32(simde__m128i_from_private(a_.m128i_private[1]), simde__m128i_from_private(b_.m128i_private[1])));
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.i32) / sizeof(r_.i32[0]) / 2) ; i++) {
    r_.i16[i]      = (a_.i32[i] > INT16_MAX) ? INT16_MAX : ((a_.i32[i] < INT16_MIN) ? INT16_MIN : ((int16_t) a_.i32[i]));
    r_.i16[i + 4]  = (b_.i32[i] > INT16_MAX) ? INT16_MAX : ((b_.i32[i] < INT16_MIN) ? INT16_MIN : ((int16_t) b_.i32[i]));
    r_.i16[i + 8]  = (a_.i32[i + 4] > INT16_MAX) ? INT16_MAX : ((a_.i32[i + 4] < INT16_MIN) ? INT16_MIN : ((int16_t) a_.i32[i]));
    r_.i16[i + 12] = (b_.i32[i + 4] > INT16_MAX) ? INT16_MAX : ((b_.i32[i + 4] < INT16_MIN) ? INT16_MIN : ((int16_t) b_.i32[i]));
  }
#endif

  return simde__m256i_from_private(r_);
#endif
}
#if defined(SIMDE_AVX2_ENABLE_NATIVE_ALIASES)
#  define _mm256_packs_epi32(a, b) simde_mm256_packs_epi32(a, b)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_permute2x128_si256 (simde__m256i a, simde__m256i b, const int imm8)
    HEDLEY_REQUIRE_MSG((imm8 & 0xf) == imm8, "imm8 must be in range [0, 15]") {
  simde__m256i_private
    r_,
    a_ = simde__m256i_to_private(a),
    b_ = simde__m256i_to_private(b);

  r_.m128i_private[0] = (imm8 & 0x08) ? simde__m128i_to_private(simde_mm_setzero_si128()) : ((imm8 & 0x02) ? b_.m128i_private[(imm8     ) & 1] : a_.m128i_private[(imm8     ) & 1]);
  r_.m128i_private[1] = (imm8 & 0x80) ? simde__m128i_to_private(simde_mm_setzero_si128()) : ((imm8 & 0x20) ? b_.m128i_private[(imm8 >> 4) & 1] : a_.m128i_private[(imm8 >> 4) & 1]);

  return simde__m256i_from_private(r_);
}
#if defined(SIMDE_AVX2_NATIVE)
#  define simde_mm256_permute2x128_si128(a, b, imm8) _mm256_permute2x128_si128(a, b, imm8)
#endif
#if defined(SIMDE_AVX2_ENABLE_NATIVE_ALIASES)
#  define _mm256_permute2x128_si256(a, b, imm8) simde_mm256_permute2x128_si256(a, b, imm8)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_shuffle_epi8 (simde__m256i a, simde__m256i b) {
#if defined(SIMDE_AVX2_NATIVE)
  return _mm256_shuffle_epi8(a, b);
#else
  simde__m256i_private
    r_,
    a_ = simde__m256i_to_private(a),
    b_ = simde__m256i_to_private(b);

  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < ((sizeof(r_.u8) / sizeof(r_.u8[0])) / 2) ; i++) {
    r_.u8[  i   ] = (b_.u8[  i   ] & 0x80) ? 0 : a_.u8[(b_.u8[  i   ] & 0x0f)     ];
    r_.u8[i + 16] = (b_.u8[i + 16] & 0x80) ? 0 : a_.u8[(b_.u8[i + 16] & 0x0f) + 16];
  }

  return simde__m256i_from_private(r_);
#endif
}
#if defined(SIMDE_AVX2_ENABLE_NATIVE_ALIASES)
#  define _mm256_shuffle_epi8(a, b) simde_mm256_shuffle_epi8(a, b)
#endif

SIMDE__FUNCTION_ATTRIBUTES
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
#if defined(SIMDE_AVX2_NATIVE)
#  define simde_mm256_shuffle_epi32(a, imm8) _mm256_shuffle_epi32(a, imm8)
#elif defined(SIMDE_SSE2_NATIVE) && !defined(__PGI)
#  define simde_mm256_shuffle_epi32(a, imm8) \
     simde_mm256_set_m128i( \
       _mm_shuffle_epi32(simde__m256i_to_private(a).m128i[1], (imm8)), \
       _mm_shuffle_epi32(simde__m256i_to_private(a).m128i[0], (imm8)))
#elif defined(SIMDE__SHUFFLE_VECTOR)
#  define simde_mm256_shuffle_epi32(a, imm8) (__extension__ ({ \
      const simde__m256i_private simde__tmp_a_ = simde__m256i_to_private(a); \
      simde__m256i_from_private((simde__m256i_private) { .i32 = \
          SIMDE__SHUFFLE_VECTOR(32, 32, \
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
#if defined(SIMDE_AVX2_ENABLE_NATIVE_ALIASES)
#  define _mm256_shuffle_epi32(a, imm8) simde_mm256_shuffle_epi32(a, imm8)
#endif

#if defined(SIMDE_AVX2_NATIVE)
#  define simde_mm256_shufflelo_epi16(a, imm8) _mm256_shufflelo_epi16(a, imm8)
#elif defined(SIMDE_SSE2_NATIVE)
#  define simde_mm256_shufflelo_epi32(a, imm8) \
     simde_mm256_set_m128i( \
       _mm_shufflelo_epi16((a).m128i[1], (imm8)), \
       _mm_shufflelo_epi16((a).m128i[0], (imm8)))
#elif defined(SIMDE__SHUFFLE_VECTOR)
#  define simde_mm256_shufflelo_epi16(a, imm8) (__extension__ ({ \
      const simde__m256i_private simde__tmp_a_ = simde__m256i_to_private(a); \
      simde__m256i_from_private((simde__m256i_private) { .i16 = \
	      SIMDE__SHUFFLE_VECTOR(16, 32, \
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
       simde_mm_shufflelo_epi16(simde__m256i_to_private(a).m128i[1], imm8), \
       simde_mm_shufflelo_epi16(simde__m256i_to_private(a).m128i[0], imm8))
#endif
#if defined(SIMDE_AVX2_ENABLE_NATIVE_ALIASES)
#  define _mm256_shufflelo_epi16(a, imm8) simde_mm256_shufflelo_epi16(a, imm8)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_slli_epi32 (simde__m256i a, const int imm8) {
  simde__m256i_private
    r_,
    a_ = simde__m256i_to_private(a);

#if defined(SIMDE_VECTOR_SUBSCRIPT_SCALAR)
  r_.i32 = a_.i32 << HEDLEY_STATIC_CAST(int32_t, imm8);
#else
  const int s = (imm8 > HEDLEY_STATIC_CAST(int, sizeof(r_.i32[0]) * CHAR_BIT) - 1) ? 0 : imm8;
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.i32) / sizeof(r_.i32[0])) ; i++) {
    r_.i32[i] = a_.i32[i] << s;
  }
#endif

  return simde__m256i_from_private(r_);
}
#if defined(SIMDE_AVX2_NATIVE)
#  define simde_mm256_slli_epi32(a, imm8) _mm256_slli_epi32(a, imm8)
#elif defined(SIMDE_SSE2_NATIVE)
#  define simde_mm256_slli_epi32(a, imm8) \
     simde_mm256_set_m128i( \
         _mm_slli_epi32(simde__m256i_to_private(a).m128i[1], (imm8)), \
         _mm_slli_epi32(simde__m256i_to_private(a).m128i[0], (imm8)))
#endif
#if defined(SIMDE_AVX2_ENABLE_NATIVE_ALIASES)
#  define _mm256_slli_epi32(a, imm8) simde_mm256_slli_epi32(a, imm8)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_sub_epi8 (simde__m256i a, simde__m256i b) {
#if defined(SIMDE_AVX2_NATIVE)
  return _mm256_sub_epi8(a, b);
#else
  simde__m256i_private
    r_,
    a_ = simde__m256i_to_private(a),
    b_ = simde__m256i_to_private(b);

#if defined(SIMDE_SSE2_NATIVE)
  r_.m128i[0] = _mm_sub_epi8(a_.m128i[0], b_.m128i[0]);
  r_.m128i[1] = _mm_sub_epi8(a_.m128i[1], b_.m128i[1]);
#elif defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
  r_.i8 = a_.i8 - b_.i8;
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.i8) / sizeof(r_.i8[0])) ; i++) {
    r_.i8[i] = a_.i8[i] - b_.i8[i];
  }
#endif

  return simde__m256i_from_private(r_);
#endif
}
#if defined(SIMDE_AVX2_ENABLE_NATIVE_ALIASES)
#  define _mm256_sub_epi8(a, b) simde_mm256_sub_epi8(a, b)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_sub_epi16 (simde__m256i a, simde__m256i b) {
#if defined(SIMDE_AVX2_NATIVE)
  return _mm256_sub_epi16(a, b);
#else
  simde__m256i_private
    r_,
    a_ = simde__m256i_to_private(a),
    b_ = simde__m256i_to_private(b);

#if defined(SIMDE_SSE2_NATIVE)
  r_.m128i[0] = _mm_sub_epi16(a_.m128i[0], b_.m128i[0]);
  r_.m128i[1] = _mm_sub_epi16(a_.m128i[1], b_.m128i[1]);
#elif defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
  r_.i16 = a_.i16 - b_.i16;
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.i16) / sizeof(r_.i16[0])) ; i++) {
    r_.i16[i] = a_.i16[i] - b_.i16[i];
  }
#endif

  return simde__m256i_from_private(r_);
#endif
}
#if defined(SIMDE_AVX2_ENABLE_NATIVE_ALIASES)
#  define _mm256_sub_epi16(a, b) simde_mm256_sub_epi16(a, b)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_sub_epi32 (simde__m256i a, simde__m256i b) {
#if defined(SIMDE_AVX2_NATIVE)
  return _mm256_sub_epi32(a, b);
#else
  simde__m256i_private
    r_,
    a_ = simde__m256i_to_private(a),
    b_ = simde__m256i_to_private(b);

#if defined(SIMDE_SSE2_NATIVE)
  r_.m128i[0] = _mm_sub_epi32(a_.m128i[0], b_.m128i[0]);
  r_.m128i[1] = _mm_sub_epi32(a_.m128i[1], b_.m128i[1]);
#elif defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
  r_.i32 = a_.i32 - b_.i32;
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.i32) / sizeof(r_.i32[0])) ; i++) {
    r_.i32[i] = a_.i32[i] - b_.i32[i];
  }
#endif

  return simde__m256i_from_private(r_);
#endif
}
#if defined(SIMDE_AVX2_ENABLE_NATIVE_ALIASES)
#  define _mm256_sub_epi32(a, b) simde_mm256_sub_epi32(a, b)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_srli_epi64 (simde__m256i a, const int imm8) {
  simde__m256i_private
    r_,
    a_ = simde__m256i_to_private(a);

#if defined(SIMDE_VECTOR_SUBSCRIPT_SCALAR)
  r_.u64 = a_.u64 >> HEDLEY_STATIC_CAST(int32_t, imm8);
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.u64) / sizeof(r_.u64[0])) ; i++) {
    r_.u64[i] = a_.u64[i] >> imm8;
  }
#endif

  return simde__m256i_from_private(r_);
}
#if defined(SIMDE_AVX2_NATIVE)
#  define simde_mm256_srli_epi64(a, imm8) _mm256_srli_epi64(a, imm8)
#elif defined(SIMDE_SSE2_NATIVE)
#  define simde_mm256_srli_epi64(a, imm8) \
     simde_mm256_set_m128i( \
         _mm_srli_epi64(simde__m256i_to_private(a).m128i[1], (imm8)), \
         _mm_srli_epi64(simde__m256i_to_private(a).m128i[0], (imm8)))
#endif
#if defined(SIMDE_AVX2_ENABLE_NATIVE_ALIASES)
#  define _mm256_srli_epi64(a, imm8) simde_mm256_srli_epi64(a, imm8)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_srli_si256 (simde__m256i a, const int imm8) {
  simde__m256i_private
    r_,
    a_ = simde__m256i_to_private(a);

  if (HEDLEY_UNLIKELY(imm8 > 15)) {
    return simde_mm256_setzero_si256();
  }

  const int s = imm8 * 8;

#if defined(SIMDE__HAVE_INT128)
  r_.u128[0] = a_.u128[0] >> s;
  r_.u128[1] = a_.u128[1] >> s;
#else
  if (s < 64) {
    r_.u64[0] = (a_.u64[0] >> s) | (a_.u64[1] << (64 - s));
    r_.u64[1] = (a_.u64[1] >> s);
    r_.u64[2] = (a_.u64[2] >> s) | (a_.u64[3] << (64 - s));
    r_.u64[3] = (a_.u64[3] >> s);
  } else {
    r_.u64[0] = a_.u64[1] >> (s - 64);
    r_.u64[1] = 0;
    r_.u64[2] = a_.u64[3] >> (s - 64);
    r_.u64[3] = 0;
  }
#endif

  return simde__m256i_from_private(r_);
}

#if defined(SIMDE_AVX2_NATIVE)
#  define simde_mm256_srli_si256(a, imm8) _mm256_srli_si256(a, imm8)
#elif defined(SIMDE_SSE2_NATIVE) && !defined(__PGI)
#  define simde_mm256_srli_si256(a, imm8) \
     simde_mm256_set_m128i( \
         _mm_srli_si128(simde__m256i_to_private(a).m128i[1], (imm8)), \
         _mm_srli_si128(simde__m256i_to_private(a).m128i[0], (imm8)))
#elif defined(SIMDE_SSE2_NEON)
#  define simde_mm256_srli_si256(a, imm8) \
     simde_mm256_set_m128i( \
       simde_mm_bsrli_si128(simde__m256i_to_private(a).m128i[1], (imm8)), \
       simde_mm_bsrli_si128(simde__m256i_to_private(a).m128i[0], (imm8)))
#endif
#if defined(SIMDE_AVX2_ENABLE_NATIVE_ALIASES)
#  define _mm256_srli_si256(a, imm8) simde_mm_srli_si256(a, imm8)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_xor_si256 (simde__m256i a, simde__m256i b) {
#if defined(SIMDE_AVX2_NATIVE)
  return _mm256_xor_si256(a, b);
#else
  simde__m256i_private
    r_,
    a_ = simde__m256i_to_private(a),
    b_ = simde__m256i_to_private(b);

#if defined(SIMDE_SSE2_NATIVE)
  r_.m128i[0] = _mm_xor_si128(a_.m128i[0], b_.m128i[0]);
  r_.m128i[1] = _mm_xor_si128(a_.m128i[1], b_.m128i[1]);
#elif defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
  r_.i32f = a_.i32f ^ b_.i32f;
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.i64) / sizeof(r_.i64[0])) ; i++) {
    r_.i64[i] = a_.i64[i] ^ b_.i64[i];
  }
#endif

  return simde__m256i_from_private(r_);
#endif
}
#if defined(SIMDE_AVX2_ENABLE_NATIVE_ALIASES)
#  define _mm256_xor_epi8(a, b) simde_mm256_xor_epi8(a, b)
#endif

SIMDE__END_DECLS

HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE__AVX2_H) */
