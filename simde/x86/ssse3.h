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
 *   2017-2020 Evan Nemerson <evan@nemerson.com>
 */

#if !defined(SIMDE__SSSE3_H)
#  if !defined(SIMDE__SSSE3_H)
#    define SIMDE__SSSE3_H
#  endif
#  include "sse3.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS

#  if defined(SIMDE_SSSE3_NATIVE)
#    undef SIMDE_SSSE3_NATIVE
#  endif
#  if defined(SIMDE_SSSE3_FORCE_NATIVE)
#    define SIMDE_SSSE3_NATIVE
#  elif defined(__SSSE3__) && !defined(SIMDE_SSSE3_NO_NATIVE) && !defined(SIMDE_NO_NATIVE)
#    define SIMDE_SSSE3_NATIVE
#  elif defined(__ARM_NEON) && !defined(SIMDE_SSSE3_NO_NEON) && !defined(SIMDE_NO_NEON)
#    define SIMDE_SSSE3_NEON
#  endif

#  if defined(SIMDE_SSSE3_NATIVE) && !defined(SIMDE_SSE3_NATIVE)
#    if defined(SIMDE_SSSE3_FORCE_NATIVE)
#      error Native SSSE3 support requires native SSE3 support
#    else
#      warning Native SSSE3 support requires native SSE3 support, disabling
#      undef SIMDE_SSSE3_NATIVE
#    endif
#  elif defined(SIMDE_SSSE3_NEON) && !defined(SIMDE_SSE3_NEON)
#    warning SSSE3 NEON support requires SSE3 NEON support, disabling
#    undef SIMDE_SSSE3_NEON
#  endif

#  if defined(SIMDE_SSSE3_NATIVE)
#    include <tmmintrin.h>
#  else
#    if defined(SIMDE_SSSE3_NEON)
#      include <arm_neon.h>
#    endif
#  endif

#if !defined(SIMDE_SSSE3_NATIVE) && defined(SIMDE_ENABLE_NATIVE_ALIASES)
#  define SIMDE_SSSE3_ENABLE_NATIVE_ALIASES
#endif

SIMDE__BEGIN_DECLS

SIMDE__FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_abs_epi8 (simde__m128i a) {
#if defined(SIMDE_SSSE3_NATIVE)
  return _mm_abs_epi8(a);
#else
  simde__m128i_private
    r_,
    a_ = simde__m128i_to_private(a);

  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.i8) / sizeof(r_.i8[0])) ; i++) {
    r_.u8[i] = HEDLEY_STATIC_CAST(uint8_t, (a_.i8[i] < 0) ? (- a_.i8[i]) : a_.i8[i]);
  }

  return simde__m128i_from_private(r_);
#endif
}
#if defined(SIMDE_SSSE3_ENABLE_NATIVE_ALIASES)
#  define _mm_abs_epi8(a) simde_mm_abs_epi8(a)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_abs_epi16 (simde__m128i a) {
#if defined(SIMDE_SSSE3_NATIVE)
  return _mm_abs_epi16(a);
#else
  simde__m128i_private
    r_,
    a_ = simde__m128i_to_private(a);

  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.i16) / sizeof(r_.i16[0])) ; i++) {
    r_.u16[i] = HEDLEY_STATIC_CAST(uint16_t, (a_.i16[i] < 0) ? (- a_.i16[i]) : a_.i16[i]);
  }

  return simde__m128i_from_private(r_);
#endif
}
#if defined(SIMDE_SSSE3_ENABLE_NATIVE_ALIASES)
#  define _mm_abs_epi16(a) simde_mm_abs_epi16(a)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_abs_epi32 (simde__m128i a) {
#if defined(SIMDE_SSSE3_NATIVE)
  return _mm_abs_epi32(a);
#else
  simde__m128i_private
    r_,
    a_ = simde__m128i_to_private(a);

  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.i32) / sizeof(r_.i32[0])) ; i++) {
    r_.u32[i] = (a_.i32[i] < 0) ? (- HEDLEY_STATIC_CAST(uint32_t, a_.i32[i])) : HEDLEY_STATIC_CAST(uint32_t, a_.i32[i]);
  }

  return simde__m128i_from_private(r_);
#endif
}
#if defined(SIMDE_SSSE3_ENABLE_NATIVE_ALIASES)
#  define _mm_abs_epi32(a) simde_mm_abs_epi32(a)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_mm_abs_pi8 (simde__m64 a) {
#if defined(SIMDE_SSSE3_NATIVE)
  return _mm_abs_pi8(a);
#else
  simde__m64_private
    r_,
    a_ = simde__m64_to_private(a);

  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.i8) / sizeof(r_.i8[0])) ; i++) {
    r_.u8[i] = HEDLEY_STATIC_CAST(uint8_t, (a_.i8[i] < 0) ? (- a_.i8[i]) : a_.i8[i]);
  }

  return simde__m64_from_private(r_);
#endif
}
#if defined(SIMDE_SSSE3_ENABLE_NATIVE_ALIASES)
#  define _mm_abs_pi8(a) simde_mm_abs_pi8(a)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_mm_abs_pi16 (simde__m64 a) {
#if defined(SIMDE_SSSE3_NATIVE)
  return _mm_abs_pi16(a);
#else
  simde__m64_private
    r_,
    a_ = simde__m64_to_private(a);

  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.i16) / sizeof(r_.i16[0])) ; i++) {
    r_.u16[i] = HEDLEY_STATIC_CAST(uint16_t, (a_.i16[i] < 0) ? (- a_.i16[i]) : a_.i16[i]);
  }

  return simde__m64_from_private(r_);
#endif
}
#if defined(SIMDE_SSSE3_ENABLE_NATIVE_ALIASES)
#  define _mm_abs_pi16(a) simde_mm_abs_pi16(a)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_mm_abs_pi32 (simde__m64 a) {
#if defined(SIMDE_SSSE3_NATIVE)
  return _mm_abs_pi32(a);
#else
  simde__m64_private
    r_,
    a_ = simde__m64_to_private(a);

  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.i32) / sizeof(r_.i32[0])) ; i++) {
    r_.u32[i] = HEDLEY_STATIC_CAST(uint32_t, (a_.i32[i] < 0) ? (- a_.i32[i]) : a_.i32[i]);
  }

  return simde__m64_from_private(r_);
#endif
}
#if defined(SIMDE_SSSE3_ENABLE_NATIVE_ALIASES)
#  define _mm_abs_pi32(a) simde_mm_abs_pi32(a)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_alignr_epi8 (simde__m128i a, simde__m128i b, int count) {
  simde__m128i_private
    r_,
    a_ = simde__m128i_to_private(a),
    b_ = simde__m128i_to_private(b);
  const int bits = (8 * count) % 64;
  const int eo = count / 8;

  switch (eo) {
    case 0:
      r_.u64[0]  = b_.u64[0] >> bits;
      r_.u64[0] |= b_.u64[1] << (64 - bits);
      r_.u64[1]  = b_.u64[1] >> bits;
      r_.u64[1] |= a_.u64[0] << (64 - bits);
      break;
    case 1:
      r_.u64[0]  = b_.u64[1] >> bits;
      r_.u64[0] |= a_.u64[0] << (64 - bits);
      r_.u64[1]  = a_.u64[0] >> bits;
      r_.u64[1] |= a_.u64[1] << (64 - bits);
      break;
    case 2:
      r_.u64[0]  = a_.u64[0] >> bits;
      r_.u64[0] |= a_.u64[1] << (64 - bits);
      r_.u64[1]  = a_.u64[1] >> bits;
      break;
    case 3:
      r_.u64[0]  = a_.u64[1] >> bits;
      r_.u64[1]  = 0;
      break;
    default:
      HEDLEY_UNREACHABLE();
      break;
  }

  return simde__m128i_from_private(r_);
}
#if defined(SIMDE_SSSE3_NATIVE)
#  define simde_mm_alignr_epi8(a, b, count) _mm_alignr_epi8(a, b, count)
#endif
#if defined(SIMDE_SSSE3_ENABLE_NATIVE_ALIASES)
#  define _mm_alignr_epi8(a, b, count) simde_mm_alignr_epi8(a, b, count)
#endif

#if defined(simde_mm_alignr_pi8)
#  undef simde_mm_alignr_pi8
#endif
SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_mm_alignr_pi8 (simde__m64 a, simde__m64 b, const int count) {
  simde__m64_private
    r_,
    a_ = simde__m64_to_private(a),
    b_ = simde__m64_to_private(b);

#if defined(SIMDE__HAVE_INT128)
HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DIAGNOSTIC_DISABLE_INT128
  unsigned __int128 t = a_.u64[0];
  t <<= 64;
  t |= b_.u64[0];
  t >>= count * 8;
  r_.u64[0] = HEDLEY_STATIC_CAST(uint64_t, t);
HEDLEY_DIAGNOSTIC_POP
#else
  const int cb = count * 8;

  if (cb > 64) {
    r_.u64[0] = a_.u64[0] >> (cb - 64);
  } else {
    r_.u64[0] = (a_.u64[0] << (64 - cb)) | (b_.u64[0] >> cb);
  }
#endif

  return simde__m64_from_private(r_);
}
#if defined(SIMDE_SSSE3_NATIVE)
#  define simde_mm_alignr_pi8(a, b, count) _mm_alignr_pi8(a, b, count)
#endif
#if defined(SIMDE_SSSE3_ENABLE_NATIVE_ALIASES)
#  define _mm_alignr_pi8(a, b, count) simde_mm_alignr_pi8(a, b, count)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_shuffle_epi8 (simde__m128i a, simde__m128i b) {
#if defined(SIMDE_SSSE3_NATIVE)
  return _mm_shuffle_epi8(a, b);
#else
  simde__m128i_private
    r_,
    a_ = simde__m128i_to_private(a),
    b_ = simde__m128i_to_private(b);
  for (size_t i = 0 ; i < (sizeof(r_.u8) / sizeof(r_.u8[0])) ; i++) {
    r_.u8[i] = a_.u8[b_.u8[i] & 15] * ((~(b_.u8[i]) >> 7) & 1);
  }
  return simde__m128i_from_private(r_);
#endif
}
#if defined(SIMDE_SSSE3_ENABLE_NATIVE_ALIASES)
#  define _mm_shuffle_epi8(a, b) simde_mm_shuffle_epi8(a, b)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_mm_shuffle_pi8 (simde__m64 a, simde__m64 b) {
#if defined(SIMDE_SSSE3_NATIVE)
  return _mm_shuffle_pi8(a, b);
#else
  simde__m64_private
    r_,
    a_ = simde__m64_to_private(a),
    b_ = simde__m64_to_private(b);
  for (size_t i = 0 ; i < (sizeof(r_.u8) / sizeof(r_.u8[0])) ; i++) {
    r_.u8[i] = a_.u8[b_.u8[i] & 7] * ((~(b_.u8[i]) >> 7) & 1);
  }
  return simde__m64_from_private(r_);
#endif
}
#if defined(SIMDE_SSSE3_ENABLE_NATIVE_ALIASES)
#  define _mm_shuffle_pi8(a, b) simde_mm_shuffle_pi8(a, b)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_hadd_epi16 (simde__m128i a, simde__m128i b) {
#if defined(SIMDE_SSSE3_NATIVE)
  return _mm_hadd_epi16(a, b);
#else
  simde__m128i_private
    r_,
    a_ = simde__m128i_to_private(a),
    b_ = simde__m128i_to_private(b);

  r_.i16[0] = a_.i16[0] + a_.i16[1];
  r_.i16[1] = a_.i16[2] + a_.i16[3];
  r_.i16[2] = a_.i16[4] + a_.i16[5];
  r_.i16[3] = a_.i16[6] + a_.i16[7];
  r_.i16[4] = b_.i16[0] + b_.i16[1];
  r_.i16[5] = b_.i16[2] + b_.i16[3];
  r_.i16[6] = b_.i16[4] + b_.i16[5];
  r_.i16[7] = b_.i16[6] + b_.i16[7];

  return simde__m128i_from_private(r_);
#endif
}
#if defined(SIMDE_SSSE3_ENABLE_NATIVE_ALIASES)
#  define _mm_hadd_epi16(a, b) simde_mm_hadd_epi16(a, b)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_hadd_epi32 (simde__m128i a, simde__m128i b) {
#if defined(SIMDE_SSSE3_NATIVE)
  return _mm_hadd_epi32(a, b);
#else
  simde__m128i_private
    r_,
    a_ = simde__m128i_to_private(a),
    b_ = simde__m128i_to_private(b);

  r_.i32[0] = a_.i32[0] + a_.i32[1];
  r_.i32[1] = a_.i32[2] + a_.i32[3];
  r_.i32[2] = b_.i32[0] + b_.i32[1];
  r_.i32[3] = b_.i32[2] + b_.i32[3];

  return simde__m128i_from_private(r_);
#endif
}
#if defined(SIMDE_SSSE3_ENABLE_NATIVE_ALIASES)
#  define _mm_hadd_epi32(a, b) simde_mm_hadd_epi32(a, b)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_mm_hadd_pi16 (simde__m64 a, simde__m64 b) {
#if defined(SIMDE_SSSE3_NATIVE)
  return _mm_hadd_pi16(a, b);
#else
  simde__m64_private
    r_,
    a_ = simde__m64_to_private(a),
    b_ = simde__m64_to_private(b);

  r_.i16[0] = a_.i16[0] + a_.i16[1];
  r_.i16[1] = a_.i16[2] + a_.i16[3];
  r_.i16[2] = b_.i16[0] + b_.i16[1];
  r_.i16[3] = b_.i16[2] + b_.i16[3];

  return simde__m64_from_private(r_);
#endif
}
#if defined(SIMDE_SSSE3_ENABLE_NATIVE_ALIASES)
#  define _mm_hadd_pi16(a, b) simde_mm_hadd_pi16(a, b)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_mm_hadd_pi32 (simde__m64 a, simde__m64 b) {
#if defined(SIMDE_SSSE3_NATIVE)
  return _mm_hadd_pi32(a, b);
#else
  simde__m64_private
    r_,
    a_ = simde__m64_to_private(a),
    b_ = simde__m64_to_private(b);

  r_.i32[0] = a_.i32[0] + a_.i32[1];
  r_.i32[1] = b_.i32[0] + b_.i32[1];

  return simde__m64_from_private(r_);
#endif
}
#if defined(SIMDE_SSSE3_ENABLE_NATIVE_ALIASES)
#  define _mm_hadd_pi32(a, b) simde_mm_hadd_pi32(a, b)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_hadds_epi16 (simde__m128i a, simde__m128i b) {
#if defined(SIMDE_SSSE3_NATIVE)
  return _mm_hadds_epi16(a, b);
#else
  simde__m128i_private
    r_,
    a_ = simde__m128i_to_private(a),
    b_ = simde__m128i_to_private(b);

  for (size_t i = 0 ; i < ((sizeof(r_.i16) / sizeof(r_.i16[0])) / 2) ; i++) {
    int32_t ta = HEDLEY_STATIC_CAST(int32_t, a_.i16[i * 2]) + HEDLEY_STATIC_CAST(int32_t, a_.i16[(i * 2) + 1]);
    r_.i16[  i  ] = HEDLEY_LIKELY(ta > INT16_MIN) ? (HEDLEY_LIKELY(ta < INT16_MAX) ? HEDLEY_STATIC_CAST(int16_t, ta) : INT16_MAX) : INT16_MIN;
    int32_t tb = HEDLEY_STATIC_CAST(int32_t, b_.i16[i * 2]) + HEDLEY_STATIC_CAST(int32_t, b_.i16[(i * 2) + 1]);
    r_.i16[i + 4] = HEDLEY_LIKELY(tb > INT16_MIN) ? (HEDLEY_LIKELY(tb < INT16_MAX) ? HEDLEY_STATIC_CAST(int16_t, tb) : INT16_MAX) : INT16_MIN;
  }

  return simde__m128i_from_private(r_);
#endif
}
#if defined(SIMDE_SSSE3_ENABLE_NATIVE_ALIASES)
#  define _mm_hadds_epi16(a, b) simde_mm_hadds_epi16(a, b)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_mm_hadds_pi16 (simde__m64 a, simde__m64 b) {
#if defined(SIMDE_SSSE3_NATIVE)
  return _mm_hadds_pi16(a, b);
#else
  simde__m64_private
    r_,
    a_ = simde__m64_to_private(a),
    b_ = simde__m64_to_private(b);

  for (size_t i = 0 ; i < ((sizeof(r_.i16) / sizeof(r_.i16[0])) / 2) ; i++) {
    int32_t ta = HEDLEY_STATIC_CAST(int32_t, a_.i16[i * 2]) + HEDLEY_STATIC_CAST(int32_t, a_.i16[(i * 2) + 1]);
    r_.i16[  i  ] = HEDLEY_LIKELY(ta > INT16_MIN) ? (HEDLEY_LIKELY(ta < INT16_MAX) ? HEDLEY_STATIC_CAST(int16_t, ta) : INT16_MAX) : INT16_MIN;
    int32_t tb = HEDLEY_STATIC_CAST(int32_t, b_.i16[i * 2]) + HEDLEY_STATIC_CAST(int32_t, b_.i16[(i * 2) + 1]);
    r_.i16[i + 2] = HEDLEY_LIKELY(tb > INT16_MIN) ? (HEDLEY_LIKELY(tb < INT16_MAX) ? HEDLEY_STATIC_CAST(int16_t, tb) : INT16_MAX) : INT16_MIN;
  }

  return simde__m64_from_private(r_);
#endif
}
#if defined(SIMDE_SSSE3_ENABLE_NATIVE_ALIASES)
#  define _mm_hadds_pi16(a, b) simde_mm_hadds_pi16(a, b)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_hsub_epi16 (simde__m128i a, simde__m128i b) {
#if defined(SIMDE_SSSE3_NATIVE)
  return _mm_hsub_epi16(a, b);
#else
  simde__m128i_private
    r_,
    a_ = simde__m128i_to_private(a),
    b_ = simde__m128i_to_private(b);

  r_.i16[0] = a_.i16[0] - a_.i16[1];
  r_.i16[1] = a_.i16[2] - a_.i16[3];
  r_.i16[2] = a_.i16[4] - a_.i16[5];
  r_.i16[3] = a_.i16[6] - a_.i16[7];
  r_.i16[4] = b_.i16[0] - b_.i16[1];
  r_.i16[5] = b_.i16[2] - b_.i16[3];
  r_.i16[6] = b_.i16[4] - b_.i16[5];
  r_.i16[7] = b_.i16[6] - b_.i16[7];

  return simde__m128i_from_private(r_);
#endif
}
#if defined(SIMDE_SSSE3_ENABLE_NATIVE_ALIASES)
#  define _mm_hsub_epi16(a, b) simde_mm_hsub_epi16(a, b)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_hsub_epi32 (simde__m128i a, simde__m128i b) {
#if defined(SIMDE_SSSE3_NATIVE)
  return _mm_hsub_epi32(a, b);
#else
  simde__m128i_private
    r_,
    a_ = simde__m128i_to_private(a),
    b_ = simde__m128i_to_private(b);

  r_.i32[0] = a_.i32[0] - a_.i32[1];
  r_.i32[1] = a_.i32[2] - a_.i32[3];
  r_.i32[2] = b_.i32[0] - b_.i32[1];
  r_.i32[3] = b_.i32[2] - b_.i32[3];

  return simde__m128i_from_private(r_);
#endif
}
#if defined(SIMDE_SSSE3_ENABLE_NATIVE_ALIASES)
#  define _mm_hsub_epi32(a, b) simde_mm_hsub_epi32(a, b)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_mm_hsub_pi16 (simde__m64 a, simde__m64 b) {
#if defined(SIMDE_SSSE3_NATIVE)
  return _mm_hsub_pi16(a, b);
#else
  simde__m64_private
    r_,
    a_ = simde__m64_to_private(a),
    b_ = simde__m64_to_private(b);

  r_.i16[0] = a_.i16[0] - a_.i16[1];
  r_.i16[1] = a_.i16[2] - a_.i16[3];
  r_.i16[2] = b_.i16[0] - b_.i16[1];
  r_.i16[3] = b_.i16[2] - b_.i16[3];

  return simde__m64_from_private(r_);
#endif
}
#if defined(SIMDE_SSSE3_ENABLE_NATIVE_ALIASES)
#  define _mm_hsub_pi16(a, b) simde_mm_hsub_pi16(a, b)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_mm_hsub_pi32 (simde__m64 a, simde__m64 b) {
#if defined(SIMDE_SSSE3_NATIVE)
  return _mm_hsub_pi32(a, b);
#else
  simde__m64_private
    r_,
    a_ = simde__m64_to_private(a),
    b_ = simde__m64_to_private(b);

  r_.i32[0] = a_.i32[0] - a_.i32[1];
  r_.i32[1] = b_.i32[0] - b_.i32[1];

  return simde__m64_from_private(r_);
#endif
}
#if defined(SIMDE_SSSE3_ENABLE_NATIVE_ALIASES)
#  define _mm_hsub_pi32(a, b) simde_mm_hsub_pi32(a, b)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_hsubs_epi16 (simde__m128i a, simde__m128i b) {
#if defined(SIMDE_SSSE3_NATIVE)
  return _mm_hsubs_epi16(a, b);
#else
  simde__m128i_private
    r_,
    a_ = simde__m128i_to_private(a),
    b_ = simde__m128i_to_private(b);

  for (size_t i = 0 ; i < ((sizeof(r_.i16) / sizeof(r_.i16[0])) / 2) ; i++) {
    int32_t ta = HEDLEY_STATIC_CAST(int32_t, a_.i16[i * 2]) - HEDLEY_STATIC_CAST(int32_t, a_.i16[(i * 2) + 1]);
    r_.i16[  i  ] = HEDLEY_LIKELY(ta > INT16_MIN) ? (HEDLEY_LIKELY(ta < INT16_MAX) ? HEDLEY_STATIC_CAST(int16_t, ta) : INT16_MAX) : INT16_MIN;
    int32_t tb = HEDLEY_STATIC_CAST(int32_t, b_.i16[i * 2]) - HEDLEY_STATIC_CAST(int32_t, b_.i16[(i * 2) + 1]);
    r_.i16[i + 4] = HEDLEY_LIKELY(tb > INT16_MIN) ? (HEDLEY_LIKELY(tb < INT16_MAX) ? HEDLEY_STATIC_CAST(int16_t, tb) : INT16_MAX) : INT16_MIN;
  }

  return simde__m128i_from_private(r_);
#endif
}
#if defined(SIMDE_SSSE3_ENABLE_NATIVE_ALIASES)
#  define _mm_hsubs_epi16(a, b) simde_mm_hsubs_epi16(a, b)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_mm_hsubs_pi16 (simde__m64 a, simde__m64 b) {
#if defined(SIMDE_SSSE3_NATIVE)
  return _mm_hsubs_pi16(a, b);
#else
  simde__m64_private
    r_,
    a_ = simde__m64_to_private(a),
    b_ = simde__m64_to_private(b);

  for (size_t i = 0 ; i < ((sizeof(r_.i16) / sizeof(r_.i16[0])) / 2) ; i++) {
    int32_t ta = HEDLEY_STATIC_CAST(int32_t, a_.i16[i * 2]) - HEDLEY_STATIC_CAST(int32_t, a_.i16[(i * 2) + 1]);
    r_.i16[  i  ] = HEDLEY_LIKELY(ta > INT16_MIN) ? (HEDLEY_LIKELY(ta < INT16_MAX) ? HEDLEY_STATIC_CAST(int16_t, ta) : INT16_MAX) : INT16_MIN;
    int32_t tb = HEDLEY_STATIC_CAST(int32_t, b_.i16[i * 2]) - HEDLEY_STATIC_CAST(int32_t, b_.i16[(i * 2) + 1]);
    r_.i16[i + 2] = HEDLEY_LIKELY(tb > INT16_MIN) ? (HEDLEY_LIKELY(tb < INT16_MAX) ? HEDLEY_STATIC_CAST(int16_t, tb) : INT16_MAX) : INT16_MIN;
  }

  return simde__m64_from_private(r_);
#endif
}
#if defined(SIMDE_SSSE3_ENABLE_NATIVE_ALIASES)
#  define _mm_hsubs_pi16(a, b) simde_mm_hsubs_pi16(a, b)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_maddubs_epi16 (simde__m128i a, simde__m128i b) {
#if defined(SIMDE_SSSE3_NATIVE)
  return _mm_maddubs_epi16(a, b);
#else
  simde__m128i_private
    r_,
    a_ = simde__m128i_to_private(a),
    b_ = simde__m128i_to_private(b);

  for (size_t i = 0 ; i < (sizeof(r_.i16) / sizeof(r_.i16[0])) ; i++) {
    const int idx = HEDLEY_STATIC_CAST(int, i) << 1;
    int32_t ts =
      (HEDLEY_STATIC_CAST(int16_t, a_.u8[  idx  ]) * HEDLEY_STATIC_CAST(int16_t, b_.i8[  idx  ])) +
      (HEDLEY_STATIC_CAST(int16_t, a_.u8[idx + 1]) * HEDLEY_STATIC_CAST(int16_t, b_.i8[idx + 1]));
    r_.i16[i] = HEDLEY_LIKELY(ts > INT16_MIN) ? (HEDLEY_LIKELY(ts < INT16_MAX) ? HEDLEY_STATIC_CAST(int16_t, ts) : INT16_MAX) : INT16_MIN;
  }

  return simde__m128i_from_private(r_);
#endif
}
#if defined(SIMDE_SSSE3_ENABLE_NATIVE_ALIASES)
#  define _mm_maddubs_epi16(a, b) simde_mm_maddubs_epi16(a, b)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_mm_maddubs_pi16 (simde__m64 a, simde__m64 b) {
#if defined(SIMDE_SSSE3_NATIVE)
  return _mm_maddubs_pi16(a, b);
#else
  simde__m64_private
    r_,
    a_ = simde__m64_to_private(a),
    b_ = simde__m64_to_private(b);

  for (size_t i = 0 ; i < (sizeof(r_.i16) / sizeof(r_.i16[0])) ; i++) {
    const int idx = HEDLEY_STATIC_CAST(int, i) << 1;
    int32_t ts =
      (HEDLEY_STATIC_CAST(int16_t, a_.u8[  idx  ]) * HEDLEY_STATIC_CAST(int16_t, b_.i8[  idx  ])) +
      (HEDLEY_STATIC_CAST(int16_t, a_.u8[idx + 1]) * HEDLEY_STATIC_CAST(int16_t, b_.i8[idx + 1]));
    r_.i16[i] = HEDLEY_LIKELY(ts > INT16_MIN) ? (HEDLEY_LIKELY(ts < INT16_MAX) ? HEDLEY_STATIC_CAST(int16_t, ts) : INT16_MAX) : INT16_MIN;
  }

  return simde__m64_from_private(r_);
#endif
}
#if defined(SIMDE_SSSE3_ENABLE_NATIVE_ALIASES)
#  define _mm_maddubs_pi16(a, b) simde_mm_maddubs_pi16(a, b)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_mulhrs_epi16 (simde__m128i a, simde__m128i b) {
#if defined(SIMDE_SSSE3_NATIVE)
  return _mm_mulhrs_epi16(a, b);
#else
  simde__m128i_private
    r_,
    a_ = simde__m128i_to_private(a),
    b_ = simde__m128i_to_private(b);

  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.i16) / sizeof(r_.i16[0])) ; i++) {
    r_.i16[i] = HEDLEY_STATIC_CAST(int16_t, (((HEDLEY_STATIC_CAST(int32_t, a_.i16[i]) * HEDLEY_STATIC_CAST(int32_t, b_.i16[i])) + 0x4000) >> 15));
  }

  return simde__m128i_from_private(r_);
#endif
}
#if defined(SIMDE_SSSE3_ENABLE_NATIVE_ALIASES)
#  define _mm_mulhrs_epi16(a, b) simde_mm_mulhrs_epi16(a, b)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_mm_mulhrs_pi16 (simde__m64 a, simde__m64 b) {
#if defined(SIMDE_SSSE3_NATIVE)
  return _mm_mulhrs_pi16(a, b);
#else
  simde__m64_private
    r_,
    a_ = simde__m64_to_private(a),
    b_ = simde__m64_to_private(b);

  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.i16) / sizeof(r_.i16[0])) ; i++) {
    r_.i16[i] = HEDLEY_STATIC_CAST(int16_t, (((HEDLEY_STATIC_CAST(int32_t, a_.i16[i]) * HEDLEY_STATIC_CAST(int32_t, b_.i16[i])) + 0x4000) >> 15));
  }

  return simde__m64_from_private(r_);
#endif
}
#if defined(SIMDE_SSSE3_ENABLE_NATIVE_ALIASES)
#  define _mm_mulhrs_pi16(a, b) simde_mm_mulhrs_pi16(a, b)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_sign_epi8 (simde__m128i a, simde__m128i b) {
#if defined(SIMDE_SSSE3_NATIVE)
  return _mm_sign_epi8(a, b);
#else
  simde__m128i_private
    r_,
    a_ = simde__m128i_to_private(a),
    b_ = simde__m128i_to_private(b);

  for (size_t i = 0 ; i < (sizeof(r_.i8) / sizeof(r_.i8[0])) ; i++) {
    r_.i8[i] = (b_.i8[i] < 0) ? (- a_.i8[i]) : ((b_.i8[i] > 0) ? (a_.i8[i]) : INT8_C(0));
  }
  return simde__m128i_from_private(r_);
#endif
}
#if defined(SIMDE_SSSE3_ENABLE_NATIVE_ALIASES)
#  define _mm_sign_epi8(a, b) simde_mm_sign_epi8(a, b)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_sign_epi16 (simde__m128i a, simde__m128i b) {
#if defined(SIMDE_SSSE3_NATIVE)
  return _mm_sign_epi16(a, b);
#else
  simde__m128i_private
    r_,
    a_ = simde__m128i_to_private(a),
    b_ = simde__m128i_to_private(b);

  for (size_t i = 0 ; i < (sizeof(r_.i16) / sizeof(r_.i16[0])) ; i++) {
    r_.i16[i] = (b_.i16[i] < 0) ? (- a_.i16[i]) : ((b_.i16[i] > 0) ? (a_.i16[i]) : INT16_C(0));
  }

  return simde__m128i_from_private(r_);
#endif
}
#if defined(SIMDE_SSSE3_ENABLE_NATIVE_ALIASES)
#  define _mm_sign_epi16(a, b) simde_mm_sign_epi16(a, b)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_sign_epi32 (simde__m128i a, simde__m128i b) {
#if defined(SIMDE_SSSE3_NATIVE)
  return _mm_sign_epi32(a, b);
#else
  simde__m128i_private
    r_,
    a_ = simde__m128i_to_private(a),
    b_ = simde__m128i_to_private(b);

  for (size_t i = 0 ; i < (sizeof(r_.i32) / sizeof(r_.i32[0])) ; i++) {
    r_.i32[i] = (b_.i32[i] < 0) ? (- a_.i32[i]) : ((b_.i32[i] > 0) ? (a_.i32[i]) : INT32_C(0));
  }

  return simde__m128i_from_private(r_);
#endif
}
#if defined(SIMDE_SSSE3_ENABLE_NATIVE_ALIASES)
#  define _mm_sign_epi32(a, b) simde_mm_sign_epi32(a, b)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_mm_sign_pi8 (simde__m64 a, simde__m64 b) {
#if defined(SIMDE_SSSE3_NATIVE)
  return _mm_sign_pi8(a, b);
#else
  simde__m64_private
    r_,
    a_ = simde__m64_to_private(a),
    b_ = simde__m64_to_private(b);

  for (size_t i = 0 ; i < (sizeof(r_.i8) / sizeof(r_.i8[0])) ; i++) {
    r_.i8[i] = (b_.i8[i] < 0) ? (- a_.i8[i]) : ((b_.i8[i] > 0) ? (a_.i8[i]) : INT8_C(0));
  }

  return simde__m64_from_private(r_);
#endif
}
#if defined(SIMDE_SSSE3_ENABLE_NATIVE_ALIASES)
#  define _mm_sign_pi8(a, b) simde_mm_sign_pi8(a, b)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_mm_sign_pi16 (simde__m64 a, simde__m64 b) {
#if defined(SIMDE_SSSE3_NATIVE)
  return _mm_sign_pi16(a, b);
#else
  simde__m64_private
    r_,
    a_ = simde__m64_to_private(a),
    b_ = simde__m64_to_private(b);

  for (size_t i = 0 ; i < (sizeof(r_.i16) / sizeof(r_.i16[0])) ; i++) {
    r_.i16[i] = (b_.i16[i] < 0) ? (- a_.i16[i]) : ((b_.i16[i] > 0) ? (a_.i16[i]) : INT16_C(0));
  }

  return simde__m64_from_private(r_);
#endif
}
#if defined(SIMDE_SSSE3_ENABLE_NATIVE_ALIASES)
#  define _mm_sign_pi16(a, b) simde_mm_sign_pi16(a, b)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_mm_sign_pi32 (simde__m64 a, simde__m64 b) {
#if defined(SIMDE_SSSE3_NATIVE)
  return _mm_sign_pi32(a, b);
#else
  simde__m64_private
    r_,
    a_ = simde__m64_to_private(a),
    b_ = simde__m64_to_private(b);

  for (size_t i = 0 ; i < (sizeof(r_.i32) / sizeof(r_.i32[0])) ; i++) {
    r_.i32[i] = (b_.i32[i] < 0) ? (- a_.i32[i]) : ((b_.i32[i] > 0) ? (a_.i32[i]) : INT32_C(0));
  }

  return simde__m64_from_private(r_);
#endif
}
#if defined(SIMDE_SSSE3_ENABLE_NATIVE_ALIASES)
#  define _mm_sign_pi32(a, b) simde_mm_sign_pi32(a, b)
#endif

SIMDE__END_DECLS

HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE__SSE2_H) */
