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
 *   2017-2020 Evan Nemerson <evan@nemerson.com>
 */

#if !defined(SIMDE_X86_SSSE3_H)
#define SIMDE_X86_SSSE3_H

#include "sse3.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_abs_epi8 (simde__m128i a) {
#if defined(SIMDE_X86_SSSE3_NATIVE)
  return _mm_abs_epi8(a);
#else
  simde__m128i_private
    r_,
    a_ = simde__m128i_to_private(a);

  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    r_.neon_i8 = vabsq_s8(a_.neon_i8);
#elif defined(SIMDE_POWER_ALTIVEC_P5_NATIVE)
  r_.altivec_i8 = vec_abs(a_.altivec_i8);
  #else
    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.i8) / sizeof(r_.i8[0])) ; i++) {
      r_.u8[i] = HEDLEY_STATIC_CAST(uint8_t, (a_.i8[i] < 0) ? (- a_.i8[i]) : a_.i8[i]);
    }
  #endif

  return simde__m128i_from_private(r_);
#endif
}
#if defined(SIMDE_X86_SSSE3_ENABLE_NATIVE_ALIASES)
#  define _mm_abs_epi8(a) simde_mm_abs_epi8(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_abs_epi16 (simde__m128i a) {
#if defined(SIMDE_X86_SSSE3_NATIVE)
  return _mm_abs_epi16(a);
#else
  simde__m128i_private
    r_,
    a_ = simde__m128i_to_private(a);

  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    r_.neon_i16 = vabsq_s16(a_.neon_i16);
  #elif defined(SIMDE_POWER_ALTIVEC_P5_NATIVE)
    r_.altivec_i16 = vec_abs(a_.altivec_i16);
  #else
    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.i16) / sizeof(r_.i16[0])) ; i++) {
      r_.u16[i] = HEDLEY_STATIC_CAST(uint16_t, (a_.i16[i] < 0) ? (- a_.i16[i]) : a_.i16[i]);
    }
  #endif

  return simde__m128i_from_private(r_);
#endif
}
#if defined(SIMDE_X86_SSSE3_ENABLE_NATIVE_ALIASES)
#  define _mm_abs_epi16(a) simde_mm_abs_epi16(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_abs_epi32 (simde__m128i a) {
#if defined(SIMDE_X86_SSSE3_NATIVE)
  return _mm_abs_epi32(a);
#else
  simde__m128i_private
    r_,
    a_ = simde__m128i_to_private(a);

  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    r_.neon_i32 = vabsq_s32(a_.neon_i32);
  #elif defined(SIMDE_POWER_ALTIVEC_P5_NATIVE)
    r_.altivec_i32 = vec_abs(a_.altivec_i32);
  #else
    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.i32) / sizeof(r_.i32[0])) ; i++) {
      #if defined(_MSC_VER)
        HEDLEY_DIAGNOSTIC_PUSH
        #pragma warning(disable:4146)
      #endif
      r_.u32[i] = (a_.i32[i] < 0) ? (- HEDLEY_STATIC_CAST(uint32_t, a_.i32[i])) : HEDLEY_STATIC_CAST(uint32_t, a_.i32[i]);
      #if defined(_MSC_VER)
        HEDLEY_DIAGNOSTIC_POP
      #endif
    }
  #endif

  return simde__m128i_from_private(r_);
#endif
}
#if defined(SIMDE_X86_SSSE3_ENABLE_NATIVE_ALIASES)
#  define _mm_abs_epi32(a) simde_mm_abs_epi32(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m64
simde_mm_abs_pi8 (simde__m64 a) {
#if defined(SIMDE_X86_SSSE3_NATIVE) && defined(SIMDE_X86_MMX_NATIVE)
  return _mm_abs_pi8(a);
#else
  simde__m64_private
    r_,
    a_ = simde__m64_to_private(a);

  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    r_.neon_i8 = vabs_s8(a_.neon_i8);
  #else
    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.i8) / sizeof(r_.i8[0])) ; i++) {
      r_.u8[i] = HEDLEY_STATIC_CAST(uint8_t, (a_.i8[i] < 0) ? (- a_.i8[i]) : a_.i8[i]);
    }
  #endif

  return simde__m64_from_private(r_);
#endif
}
#if defined(SIMDE_X86_SSSE3_ENABLE_NATIVE_ALIASES)
#  define _mm_abs_pi8(a) simde_mm_abs_pi8(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m64
simde_mm_abs_pi16 (simde__m64 a) {
#if defined(SIMDE_X86_SSSE3_NATIVE) && defined(SIMDE_X86_MMX_NATIVE)
  return _mm_abs_pi16(a);
#else
  simde__m64_private
    r_,
    a_ = simde__m64_to_private(a);

  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    r_.neon_i16 = vabs_s16(a_.neon_i16);
  #else
    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.i16) / sizeof(r_.i16[0])) ; i++) {
      r_.u16[i] = HEDLEY_STATIC_CAST(uint16_t, (a_.i16[i] < 0) ? (- a_.i16[i]) : a_.i16[i]);
    }
  #endif

  return simde__m64_from_private(r_);
#endif
}
#if defined(SIMDE_X86_SSSE3_ENABLE_NATIVE_ALIASES)
#  define _mm_abs_pi16(a) simde_mm_abs_pi16(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m64
simde_mm_abs_pi32 (simde__m64 a) {
#if defined(SIMDE_X86_SSSE3_NATIVE) && defined(SIMDE_X86_MMX_NATIVE)
  return _mm_abs_pi32(a);
#else
  simde__m64_private
    r_,
    a_ = simde__m64_to_private(a);

  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    r_.neon_i32 = vabs_s32(a_.neon_i32);
  #else
    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.i32) / sizeof(r_.i32[0])) ; i++) {
      r_.u32[i] = HEDLEY_STATIC_CAST(uint32_t, (a_.i32[i] < 0) ? (- a_.i32[i]) : a_.i32[i]);
    }
  #endif

  return simde__m64_from_private(r_);
#endif
}
#if defined(SIMDE_X86_SSSE3_ENABLE_NATIVE_ALIASES)
#  define _mm_abs_pi32(a) simde_mm_abs_pi32(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_alignr_epi8 (simde__m128i a, simde__m128i b, int count) {
  simde__m128i_private
    r_,
    a_ = simde__m128i_to_private(a),
    b_ = simde__m128i_to_private(b);

#if 0 && defined(SIMDE_BYTE_ORDER_LE)
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
#else
  if (HEDLEY_UNLIKELY(count > 31))
    return simde_mm_setzero_si128();

  for (size_t i = 0 ; i < (sizeof(r_.i8) / sizeof(r_.i8[0])) ; i++) {
    const int srcpos = count + HEDLEY_STATIC_CAST(int, i);
    if (srcpos > 31) {
      r_.i8[i] = 0;
    } else if (srcpos > 15) {
      r_.i8[i] = a_.i8[(srcpos) & 15];
    } else {
      r_.i8[i] = b_.i8[srcpos];
    }
  }
#endif

  return simde__m128i_from_private(r_);
}
#if defined(SIMDE_X86_SSSE3_NATIVE)
#  define simde_mm_alignr_epi8(a, b, count) _mm_alignr_epi8(a, b, count)
// #elif defined(SIMDE_ARM_NEON_A32V7_NATIVE)
// #  define simde_mm_alignr_epi8(a, b, count) simde__m128i_from_neon_i8(vextq_s8((int8x16_t) (b), (int8x16_t) (a), (count)))
// doesn't work with count > 15 (the tests use 17)
#endif
#if defined(SIMDE_X86_SSSE3_ENABLE_NATIVE_ALIASES)
#  define _mm_alignr_epi8(a, b, count) simde_mm_alignr_epi8(a, b, count)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m64
simde_mm_alignr_pi8 (simde__m64 a, simde__m64 b, const int count) {
  simde__m64_private
    r_,
    a_ = simde__m64_to_private(a),
    b_ = simde__m64_to_private(b);

  if (HEDLEY_UNLIKELY(count > 15))
    return simde_mm_setzero_si64();

  for (size_t i = 0 ; i < (sizeof(r_.i8) / sizeof(r_.i8[0])) ; i++) {
    const int srcpos = count + HEDLEY_STATIC_CAST(int, i);
    if (srcpos > 15) {
      r_.i8[i] = 0;
    } else if (srcpos > 7) {
      r_.i8[i] = a_.i8[(srcpos) & 7];
    } else {
      r_.i8[i] = b_.i8[srcpos];
    }
  }

  return simde__m64_from_private(r_);
}
#if defined(SIMDE_X86_SSSE3_NATIVE) && defined(SIMDE_X86_MMX_NATIVE)
#  define simde_mm_alignr_pi8(a, b, count) _mm_alignr_pi8(a, b, count)
#endif
#if defined(SIMDE_X86_SSSE3_ENABLE_NATIVE_ALIASES)
#  define _mm_alignr_pi8(a, b, count) simde_mm_alignr_pi8(a, b, count)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_shuffle_epi8 (simde__m128i a, simde__m128i b) {
  #if defined(SIMDE_X86_SSSE3_NATIVE)
    return _mm_shuffle_epi8(a, b);
  #else
    simde__m128i_private
      r_,
      a_ = simde__m128i_to_private(a),
      b_ = simde__m128i_to_private(b);

    #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
      r_.neon_i8 = vqtbl1q_s8(a_.neon_i8, vandq_u8(b_.neon_u8, vdupq_n_u8(0x8F)));
    #elif defined(SIMDE_ARM_NEON_A32V7_NATIVE)
      /* Mask out the bits we're not interested in.  vtbl will result in 0
         for any values outside of [0, 15], so if the high bit is set it
         will return 0, just like in SSSE3. */
      b_.neon_i8 = vandq_s8(b_.neon_i8, vdupq_n_s8(HEDLEY_STATIC_CAST(int8_t, (1 << 7) | 15)));

      /* Convert a from an int8x16_t to an int8x8x2_t */
      int8x8x2_t i;
      i.val[0] = vget_low_s8(a_.neon_i8);
      i.val[1] = vget_high_s8(a_.neon_i8);

      /* Table lookups */
      int8x8_t l = vtbl2_s8(i, vget_low_s8(b_.neon_i8));
      int8x8_t h = vtbl2_s8(i, vget_high_s8(b_.neon_i8));

      r_.neon_i8 = vcombine_s8(l, h);
    #elif defined(SIMDE_POWER_ALTIVEC_P5_NATIVE)
      /* This is a bit ugly because of the casts and the awful type
      * macros (SIMDE_POWER_ALTIVEC_VECTOR), but it's really just
       * vec_sel(vec_perm(a, a, b), 0, vec_cmplt(b, 0)) */
      SIMDE_POWER_ALTIVEC_VECTOR(signed char) z = { 0, };
      SIMDE_POWER_ALTIVEC_VECTOR(signed char) msb_mask = HEDLEY_REINTERPRET_CAST(SIMDE_POWER_ALTIVEC_VECTOR(signed char), vec_cmplt(b_.altivec_i8, z));
      SIMDE_POWER_ALTIVEC_VECTOR(signed char) c = vec_perm(a_.altivec_i8, a_.altivec_i8, HEDLEY_REINTERPRET_CAST(SIMDE_POWER_ALTIVEC_VECTOR(unsigned char), b_.altivec_i8));
      r_.altivec_i8 = vec_sel(c, z, HEDLEY_REINTERPRET_CAST(SIMDE_POWER_ALTIVEC_VECTOR(unsigned char), msb_mask));
    #else
      for (size_t i = 0 ; i < (sizeof(r_.i8) / sizeof(r_.i8[0])) ; i++) {
        r_.i8[i] = a_.i8[b_.i8[i] & 15] & (~(b_.i8[i]) >> 7);
      }
    #endif

    return simde__m128i_from_private(r_);
#endif
}
#if defined(SIMDE_X86_SSSE3_ENABLE_NATIVE_ALIASES)
#  define _mm_shuffle_epi8(a, b) simde_mm_shuffle_epi8(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m64
simde_mm_shuffle_pi8 (simde__m64 a, simde__m64 b) {
  #if defined(SIMDE_X86_SSSE3_NATIVE) && defined(SIMDE_X86_MMX_NATIVE)
    return _mm_shuffle_pi8(a, b);
  #else
    simde__m64_private
      r_,
      a_ = simde__m64_to_private(a),
      b_ = simde__m64_to_private(b);

    #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
      b_.neon_i8 = vand_s8(b_.neon_i8, vdup_n_s8(HEDLEY_STATIC_CAST(int8_t, (1 << 7) | 7)));
      r_.neon_i8 = vtbl1_s8(a_.neon_i8, b_.neon_i8);
    #else
      for (size_t i = 0 ; i < (sizeof(r_.u8) / sizeof(r_.u8[0])) ; i++) {
        r_.i8[i] = a_.i8[b_.i8[i] & 7] & (~(b_.i8[i]) >> 7);
      }
    #endif

    return simde__m64_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SSSE3_ENABLE_NATIVE_ALIASES)
#  define _mm_shuffle_pi8(a, b) simde_mm_shuffle_pi8(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_hadd_epi16 (simde__m128i a, simde__m128i b) {
#if defined(SIMDE_X86_SSSE3_NATIVE)
  return _mm_hadd_epi16(a, b);
#else
  return simde_mm_add_epi16(simde_x_mm_deinterleaveeven_epi16(a, b), simde_x_mm_deinterleaveodd_epi16(a, b));
#endif
}
#if defined(SIMDE_X86_SSSE3_ENABLE_NATIVE_ALIASES)
#  define _mm_hadd_epi16(a, b) simde_mm_hadd_epi16(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_hadd_epi32 (simde__m128i a, simde__m128i b) {
#if defined(SIMDE_X86_SSSE3_NATIVE)
  return _mm_hadd_epi32(a, b);
#else
  return simde_mm_add_epi32(simde_x_mm_deinterleaveeven_epi32(a, b), simde_x_mm_deinterleaveodd_epi32(a, b));
#endif
}
#if defined(SIMDE_X86_SSSE3_ENABLE_NATIVE_ALIASES)
#  define _mm_hadd_epi32(a, b) simde_mm_hadd_epi32(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m64
simde_mm_hadd_pi16 (simde__m64 a, simde__m64 b) {
#if defined(SIMDE_X86_SSSE3_NATIVE) && defined(SIMDE_X86_MMX_NATIVE)
  return _mm_hadd_pi16(a, b);
#else
  simde__m64_private
    r_,
    a_ = simde__m64_to_private(a),
    b_ = simde__m64_to_private(b);

  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
    r_.neon_i16 = vadd_s16(vuzp1_s16(a_.neon_i16, b_.neon_i16), vuzp2_s16(a_.neon_i16, b_.neon_i16));
  #elif defined(SIMDE_ASSUME_VECTORIZATION) && defined(SIMDE_SHUFFLE_VECTOR_)
    r_.i16 =
      SIMDE_SHUFFLE_VECTOR_(16, 8, a_.i16, b_.i16, 0, 2, 4, 6) +
      SIMDE_SHUFFLE_VECTOR_(16, 8, a_.i16, b_.i16, 1, 3, 5, 7);
  #else
    r_.i16[0] = a_.i16[0] + a_.i16[1];
    r_.i16[1] = a_.i16[2] + a_.i16[3];
    r_.i16[2] = b_.i16[0] + b_.i16[1];
    r_.i16[3] = b_.i16[2] + b_.i16[3];
  #endif

  return simde__m64_from_private(r_);
#endif
}
#if defined(SIMDE_X86_SSSE3_ENABLE_NATIVE_ALIASES)
#  define _mm_hadd_pi16(a, b) simde_mm_hadd_pi16(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m64
simde_mm_hadd_pi32 (simde__m64 a, simde__m64 b) {
#if defined(SIMDE_X86_SSSE3_NATIVE) && defined(SIMDE_X86_MMX_NATIVE)
  return _mm_hadd_pi32(a, b);
#else
  simde__m64_private
    r_,
    a_ = simde__m64_to_private(a),
    b_ = simde__m64_to_private(b);

  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
    r_.neon_i32 = vadd_s32(vuzp1_s32(a_.neon_i32, b_.neon_i32), vuzp2_s32(a_.neon_i32, b_.neon_i32));
  #elif defined(SIMDE_ASSUME_VECTORIZATION) && defined(SIMDE_SHUFFLE_VECTOR_)
    r_.i32 =
      SIMDE_SHUFFLE_VECTOR_(32, 8, a_.i32, b_.i32, 0, 2) +
      SIMDE_SHUFFLE_VECTOR_(32, 8, a_.i32, b_.i32, 1, 3);
  #else
    r_.i32[0] = a_.i32[0] + a_.i32[1];
    r_.i32[1] = b_.i32[0] + b_.i32[1];
  #endif

  return simde__m64_from_private(r_);
#endif
}
#if defined(SIMDE_X86_SSSE3_ENABLE_NATIVE_ALIASES)
#  define _mm_hadd_pi32(a, b) simde_mm_hadd_pi32(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_hadds_epi16 (simde__m128i a, simde__m128i b) {
#if defined(SIMDE_X86_SSSE3_NATIVE)
  return _mm_hadds_epi16(a, b);
#else
  return simde_mm_adds_epi16(simde_x_mm_deinterleaveeven_epi16(a, b), simde_x_mm_deinterleaveodd_epi16(a, b));
#endif
}
#if defined(SIMDE_X86_SSSE3_ENABLE_NATIVE_ALIASES)
#  define _mm_hadds_epi16(a, b) simde_mm_hadds_epi16(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m64
simde_mm_hadds_pi16 (simde__m64 a, simde__m64 b) {
#if defined(SIMDE_X86_SSSE3_NATIVE) && defined(SIMDE_X86_MMX_NATIVE)
  return _mm_hadds_pi16(a, b);
#else
  simde__m64_private
    r_,
    a_ = simde__m64_to_private(a),
    b_ = simde__m64_to_private(b);

  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
    r_.neon_i16 = vqadd_s16(vuzp1_s16(a_.neon_i16, b_.neon_i16), vuzp2_s16(a_.neon_i16, b_.neon_i16));
  #else
    for (size_t i = 0 ; i < ((sizeof(r_.i16) / sizeof(r_.i16[0])) / 2) ; i++) {
      int32_t ta = HEDLEY_STATIC_CAST(int32_t, a_.i16[i * 2]) + HEDLEY_STATIC_CAST(int32_t, a_.i16[(i * 2) + 1]);
      r_.i16[  i  ] = HEDLEY_LIKELY(ta > INT16_MIN) ? (HEDLEY_LIKELY(ta < INT16_MAX) ? HEDLEY_STATIC_CAST(int16_t, ta) : INT16_MAX) : INT16_MIN;
      int32_t tb = HEDLEY_STATIC_CAST(int32_t, b_.i16[i * 2]) + HEDLEY_STATIC_CAST(int32_t, b_.i16[(i * 2) + 1]);
      r_.i16[i + 2] = HEDLEY_LIKELY(tb > INT16_MIN) ? (HEDLEY_LIKELY(tb < INT16_MAX) ? HEDLEY_STATIC_CAST(int16_t, tb) : INT16_MAX) : INT16_MIN;
    }
  #endif

  return simde__m64_from_private(r_);
#endif
}
#if defined(SIMDE_X86_SSSE3_ENABLE_NATIVE_ALIASES)
#  define _mm_hadds_pi16(a, b) simde_mm_hadds_pi16(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_hsub_epi16 (simde__m128i a, simde__m128i b) {
#if defined(SIMDE_X86_SSSE3_NATIVE)
  return _mm_hsub_epi16(a, b);
#else
  return simde_mm_sub_epi16(simde_x_mm_deinterleaveeven_epi16(a, b), simde_x_mm_deinterleaveodd_epi16(a, b));
#endif
}
#if defined(SIMDE_X86_SSSE3_ENABLE_NATIVE_ALIASES)
#  define _mm_hsub_epi16(a, b) simde_mm_hsub_epi16(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_hsub_epi32 (simde__m128i a, simde__m128i b) {
#if defined(SIMDE_X86_SSSE3_NATIVE)
  return _mm_hsub_epi32(a, b);
#else
  return simde_mm_sub_epi32(simde_x_mm_deinterleaveeven_epi32(a, b), simde_x_mm_deinterleaveodd_epi32(a, b));
#endif
}
#if defined(SIMDE_X86_SSSE3_ENABLE_NATIVE_ALIASES)
#  define _mm_hsub_epi32(a, b) simde_mm_hsub_epi32(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m64
simde_mm_hsub_pi16 (simde__m64 a, simde__m64 b) {
#if defined(SIMDE_X86_SSSE3_NATIVE) && defined(SIMDE_X86_MMX_NATIVE)
  return _mm_hsub_pi16(a, b);
#else
  simde__m64_private
    r_,
    a_ = simde__m64_to_private(a),
    b_ = simde__m64_to_private(b);

  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
    r_.neon_i16 = vsub_s16(vuzp1_s16(a_.neon_i16, b_.neon_i16), vuzp2_s16(a_.neon_i16, b_.neon_i16));
  #elif defined(SIMDE_ASSUME_VECTORIZATION) && defined(SIMDE_SHUFFLE_VECTOR_)
    r_.i16 =
      SIMDE_SHUFFLE_VECTOR_(16, 8, a_.i16, b_.i16, 0, 2, 4, 6) -
      SIMDE_SHUFFLE_VECTOR_(16, 8, a_.i16, b_.i16, 1, 3, 5, 7);
  #else
    r_.i16[0] = a_.i16[0] - a_.i16[1];
    r_.i16[1] = a_.i16[2] - a_.i16[3];
    r_.i16[2] = b_.i16[0] - b_.i16[1];
    r_.i16[3] = b_.i16[2] - b_.i16[3];
  #endif

  return simde__m64_from_private(r_);
#endif
}
#if defined(SIMDE_X86_SSSE3_ENABLE_NATIVE_ALIASES)
#  define _mm_hsub_pi16(a, b) simde_mm_hsub_pi16(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m64
simde_mm_hsub_pi32 (simde__m64 a, simde__m64 b) {
#if defined(SIMDE_X86_SSSE3_NATIVE) && defined(SIMDE_X86_MMX_NATIVE)
  return _mm_hsub_pi32(a, b);
#else
  simde__m64_private
    r_,
    a_ = simde__m64_to_private(a),
    b_ = simde__m64_to_private(b);

  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
    r_.neon_i32 = vsub_s32(vuzp1_s32(a_.neon_i32, b_.neon_i32), vuzp2_s32(a_.neon_i32, b_.neon_i32));
  #elif defined(SIMDE_ASSUME_VECTORIZATION) && defined(SIMDE_SHUFFLE_VECTOR_)
    r_.i32 =
      SIMDE_SHUFFLE_VECTOR_(32, 8, a_.i32, b_.i32, 0, 2) -
      SIMDE_SHUFFLE_VECTOR_(32, 8, a_.i32, b_.i32, 1, 3);
  #else
    r_.i32[0] = a_.i32[0] - a_.i32[1];
    r_.i32[1] = b_.i32[0] - b_.i32[1];
  #endif

  return simde__m64_from_private(r_);
#endif
}
#if defined(SIMDE_X86_SSSE3_ENABLE_NATIVE_ALIASES)
#  define _mm_hsub_pi32(a, b) simde_mm_hsub_pi32(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_hsubs_epi16 (simde__m128i a, simde__m128i b) {
#if defined(SIMDE_X86_SSSE3_NATIVE)
  return _mm_hsubs_epi16(a, b);
#else
  return simde_mm_subs_epi16(simde_x_mm_deinterleaveeven_epi16(a, b), simde_x_mm_deinterleaveodd_epi16(a, b));
#endif
}
#if defined(SIMDE_X86_SSSE3_ENABLE_NATIVE_ALIASES)
#  define _mm_hsubs_epi16(a, b) simde_mm_hsubs_epi16(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m64
simde_mm_hsubs_pi16 (simde__m64 a, simde__m64 b) {
#if defined(SIMDE_X86_SSSE3_NATIVE) && defined(SIMDE_X86_MMX_NATIVE)
  return _mm_hsubs_pi16(a, b);
#else
  simde__m64_private
    r_,
    a_ = simde__m64_to_private(a),
    b_ = simde__m64_to_private(b);

  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
    r_.neon_i16 = vqsub_s16(vuzp1_s16(a_.neon_i16, b_.neon_i16), vuzp2_s16(a_.neon_i16, b_.neon_i16));
  #else
    for (size_t i = 0 ; i < ((sizeof(r_.i16) / sizeof(r_.i16[0])) / 2) ; i++) {
      int32_t ta = HEDLEY_STATIC_CAST(int32_t, a_.i16[i * 2]) - HEDLEY_STATIC_CAST(int32_t, a_.i16[(i * 2) + 1]);
      r_.i16[  i  ] = HEDLEY_LIKELY(ta > INT16_MIN) ? (HEDLEY_LIKELY(ta < INT16_MAX) ? HEDLEY_STATIC_CAST(int16_t, ta) : INT16_MAX) : INT16_MIN;
      int32_t tb = HEDLEY_STATIC_CAST(int32_t, b_.i16[i * 2]) - HEDLEY_STATIC_CAST(int32_t, b_.i16[(i * 2) + 1]);
      r_.i16[i + 2] = HEDLEY_LIKELY(tb > INT16_MIN) ? (HEDLEY_LIKELY(tb < INT16_MAX) ? HEDLEY_STATIC_CAST(int16_t, tb) : INT16_MAX) : INT16_MIN;
    }
  #endif

  return simde__m64_from_private(r_);
#endif
}
#if defined(SIMDE_X86_SSSE3_ENABLE_NATIVE_ALIASES)
#  define _mm_hsubs_pi16(a, b) simde_mm_hsubs_pi16(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_maddubs_epi16 (simde__m128i a, simde__m128i b) {
#if defined(SIMDE_X86_SSSE3_NATIVE)
  return _mm_maddubs_epi16(a, b);
#else
  simde__m128i_private
    r_,
    a_ = simde__m128i_to_private(a),
    b_ = simde__m128i_to_private(b);

  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
    int16x8_t tl = vmulq_s16(vreinterpretq_s16_u16(vmovl_u8(vget_low_u8(a_.neon_u8))), vmovl_s8(vget_low_s8(b_.neon_i8)));
    int16x8_t th = vmulq_s16(vreinterpretq_s16_u16(vmovl_u8(vget_high_u8(a_.neon_u8))), vmovl_s8(vget_high_s8(b_.neon_i8)));
    r_.neon_i16 = vqaddq_s16(vuzp1q_s16(tl, th), vuzp2q_s16(tl, th));
  #elif defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    // This would be much simpler if x86 would choose to zero extend OR sign extend,
    // not both.
    // This could probably be optimized better.

    // Zero extend a
    int16x8_t a_odd = vreinterpretq_s16_u16(vshrq_n_u16(a_.neon_u16, 8));
    int16x8_t a_even = vreinterpretq_s16_u16(vbicq_u16(a_.neon_u16, vdupq_n_u16(0xff00)));

    // Sign extend by shifting left then shifting right.
    int16x8_t b_even = vshrq_n_s16(vshlq_n_s16(b_.neon_i16, 8), 8);
    int16x8_t b_odd = vshrq_n_s16(b_.neon_i16, 8);

    // multiply
    int16x8_t prod1 = vmulq_s16(a_even, b_even);
    int16x8_t prod2 = vmulq_s16(a_odd, b_odd);

    // saturated add
    r_.neon_i16 = vqaddq_s16(prod1, prod2);
  #else
    for (size_t i = 0 ; i < (sizeof(r_.i16) / sizeof(r_.i16[0])) ; i++) {
      const int idx = HEDLEY_STATIC_CAST(int, i) << 1;
      int32_t ts =
        (HEDLEY_STATIC_CAST(int16_t, a_.u8[  idx  ]) * HEDLEY_STATIC_CAST(int16_t, b_.i8[  idx  ])) +
        (HEDLEY_STATIC_CAST(int16_t, a_.u8[idx + 1]) * HEDLEY_STATIC_CAST(int16_t, b_.i8[idx + 1]));
      r_.i16[i] = HEDLEY_LIKELY(ts > INT16_MIN) ? (HEDLEY_LIKELY(ts < INT16_MAX) ? HEDLEY_STATIC_CAST(int16_t, ts) : INT16_MAX) : INT16_MIN;
    }
  #endif

  return simde__m128i_from_private(r_);
#endif
}
#if defined(SIMDE_X86_SSSE3_ENABLE_NATIVE_ALIASES)
#  define _mm_maddubs_epi16(a, b) simde_mm_maddubs_epi16(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m64
simde_mm_maddubs_pi16 (simde__m64 a, simde__m64 b) {
#if defined(SIMDE_X86_SSSE3_NATIVE) && defined(SIMDE_X86_MMX_NATIVE)
  return _mm_maddubs_pi16(a, b);
#else
  simde__m64_private
    r_,
    a_ = simde__m64_to_private(a),
    b_ = simde__m64_to_private(b);

  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
    int16x8_t ai = vreinterpretq_s16_u16(vmovl_u8(a_.neon_u8));
    int16x8_t bi = vmovl_s8(b_.neon_i8);
    int16x8_t p = vmulq_s16(ai, bi);
    int16x4_t l = vget_low_s16(p);
    int16x4_t h = vget_high_s16(p);
    r_.neon_i16 = vqadd_s16(vuzp1_s16(l, h), vuzp2_s16(l, h));
  #else
    for (size_t i = 0 ; i < (sizeof(r_.i16) / sizeof(r_.i16[0])) ; i++) {
      const int idx = HEDLEY_STATIC_CAST(int, i) << 1;
      int32_t ts =
        (HEDLEY_STATIC_CAST(int16_t, a_.u8[  idx  ]) * HEDLEY_STATIC_CAST(int16_t, b_.i8[  idx  ])) +
        (HEDLEY_STATIC_CAST(int16_t, a_.u8[idx + 1]) * HEDLEY_STATIC_CAST(int16_t, b_.i8[idx + 1]));
      r_.i16[i] = HEDLEY_LIKELY(ts > INT16_MIN) ? (HEDLEY_LIKELY(ts < INT16_MAX) ? HEDLEY_STATIC_CAST(int16_t, ts) : INT16_MAX) : INT16_MIN;
    }
  #endif

  return simde__m64_from_private(r_);
#endif
}
#if defined(SIMDE_X86_SSSE3_ENABLE_NATIVE_ALIASES)
#  define _mm_maddubs_pi16(a, b) simde_mm_maddubs_pi16(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_mulhrs_epi16 (simde__m128i a, simde__m128i b) {
#if defined(SIMDE_X86_SSSE3_NATIVE)
  return _mm_mulhrs_epi16(a, b);
#else
  simde__m128i_private
    r_,
    a_ = simde__m128i_to_private(a),
    b_ = simde__m128i_to_private(b);

  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    // Has issues due to saturation
    // r_.neon_i16 =  vqrdmulhq_s16(a, b);

    // Multiply
    int32x4_t mul_lo = vmull_s16(vget_low_s16(a_.neon_i16),
                                 vget_low_s16(b_.neon_i16));
    int32x4_t mul_hi = vmull_s16(vget_high_s16(a_.neon_i16),
                                 vget_high_s16(b_.neon_i16));

    // Rounding narrowing shift right
    // narrow = (int16_t)((mul + 16384) >> 15);
    int16x4_t narrow_lo = vrshrn_n_s32(mul_lo, 15);
    int16x4_t narrow_hi = vrshrn_n_s32(mul_hi, 15);

    // Join together
    r_.neon_i16 = vcombine_s16(narrow_lo, narrow_hi);
  #else
    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.i16) / sizeof(r_.i16[0])) ; i++) {
      r_.i16[i] = HEDLEY_STATIC_CAST(int16_t, (((HEDLEY_STATIC_CAST(int32_t, a_.i16[i]) * HEDLEY_STATIC_CAST(int32_t, b_.i16[i])) + 0x4000) >> 15));
    }
  #endif

  return simde__m128i_from_private(r_);
#endif
}
#if defined(SIMDE_X86_SSSE3_ENABLE_NATIVE_ALIASES)
#  define _mm_mulhrs_epi16(a, b) simde_mm_mulhrs_epi16(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m64
simde_mm_mulhrs_pi16 (simde__m64 a, simde__m64 b) {
#if defined(SIMDE_X86_SSSE3_NATIVE) && defined(SIMDE_X86_MMX_NATIVE)
  return _mm_mulhrs_pi16(a, b);
#else
  simde__m64_private
    r_,
    a_ = simde__m64_to_private(a),
    b_ = simde__m64_to_private(b);

  SIMDE_VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.i16) / sizeof(r_.i16[0])) ; i++) {
    r_.i16[i] = HEDLEY_STATIC_CAST(int16_t, (((HEDLEY_STATIC_CAST(int32_t, a_.i16[i]) * HEDLEY_STATIC_CAST(int32_t, b_.i16[i])) + 0x4000) >> 15));
  }

  return simde__m64_from_private(r_);
#endif
}
#if defined(SIMDE_X86_SSSE3_ENABLE_NATIVE_ALIASES)
#  define _mm_mulhrs_pi16(a, b) simde_mm_mulhrs_pi16(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_sign_epi8 (simde__m128i a, simde__m128i b) {
#if defined(SIMDE_X86_SSSE3_NATIVE)
  return _mm_sign_epi8(a, b);
#else
  simde__m128i_private
    r_,
    a_ = simde__m128i_to_private(a),
    b_ = simde__m128i_to_private(b);

  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
    int8x16_t m = vreinterpretq_s8_u8(vcgezq_s8(b_.neon_i8));
    r_.neon_i8 = veorq_s8(vandq_s8(a_.neon_i8, m), vandq_s8(vnegq_s8(a_.neon_i8), vmvnq_s8(m)));
  // #elif defined(SIMDE_ARM_NEON_A32V7_NATIVE)
  //   int8x16_t zero = vdupq_n_s8(0);
  //   // signed shift right: faster than vclt
  //   // (b < 0) ? 0xFF : 0
  //   uint8x16_t ltMask = vreinterpretq_u8_s8(vshrq_n_s8(b_.neon_i8, 7));
  //   // (b == 0) ? 0xFF : 0
  //   int8x16_t zeroMask = vreinterpretq_s8_u8(vceqq_s8(b_.neon_i8, zero));
  //   // -a
  //   int8x16_t neg = vnegq_s8(a_.neon_i8);
  //   // bitwise select either a or neg based on ltMask
  //   int8x16_t masked = vbslq_s8(ltMask, a_.neon_i8, neg);
  //   // res = masked & (~zeroMask)
  //   r_.neon_i8 = vbicq_s8(masked, zeroMask);
  // test/x86/ssse3.c:1750: assertion failed: r.i8[0] == test_vec[i].r.i8[0] (66 == -66)
  #else
    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.i8) / sizeof(r_.i8[0])) ; i++) {
      r_.i8[i] = (b_.i8[i] < 0) ? (- a_.i8[i]) : ((b_.i8[i] > 0) ? (a_.i8[i]) : INT8_C(0));
    }
  #endif

  return simde__m128i_from_private(r_);
#endif
}
#if defined(SIMDE_X86_SSSE3_ENABLE_NATIVE_ALIASES)
#  define _mm_sign_epi8(a, b) simde_mm_sign_epi8(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_sign_epi16 (simde__m128i a, simde__m128i b) {
#if defined(SIMDE_X86_SSSE3_NATIVE)
  return _mm_sign_epi16(a, b);
#else
  simde__m128i_private
    r_,
    a_ = simde__m128i_to_private(a),
    b_ = simde__m128i_to_private(b);

  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
    int16x8_t m = vreinterpretq_s16_u16(vcgezq_s16(b_.neon_i16));
    r_.neon_i16 = veorq_s16(vandq_s16(a_.neon_i16, m), vandq_s16(vnegq_s16(a_.neon_i16), vmvnq_s16(m)));
  // #elif defined(SIMDE_ARM_NEON_A32V7_NATIVE)
  //   uint16x8_t ltMask = vreinterpretq_u16_s16(vshrq_n_s16(b_.neon_i16, 15));
  //   // (b == 0) ? 0xFFFF : 0
  //   int16x8_t zeroMask = vreinterpretq_s16_u16(vceqq_s16(b_.neon_i16, zero));
  //   // -a
  //   int16x8_t neg = vnegq_s16(a_.neon_i16);
  //   // bitwise select either a or neg based on ltMask
  //   int16x8_t masked = vbslq_s16(ltMask, a_.neon_i16, neg);
  //   // res = masked & (~zeroMask)
  //   r_.neon_i16 = vbicq_s16(masked, zeroMask);
  // x86/ssse3.cpp:1818: assertion failed: r.i16[0] == test_vec[i].r.i16[0] (28879 == -28879)
  #else
    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.i16) / sizeof(r_.i16[0])) ; i++) {
      r_.i16[i] = (b_.i16[i] < 0) ? (- a_.i16[i]) : ((b_.i16[i] > 0) ? (a_.i16[i]) : INT16_C(0));
    }
  #endif

  return simde__m128i_from_private(r_);
#endif
}
#if defined(SIMDE_X86_SSSE3_ENABLE_NATIVE_ALIASES)
#  define _mm_sign_epi16(a, b) simde_mm_sign_epi16(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_sign_epi32 (simde__m128i a, simde__m128i b) {
#if defined(SIMDE_X86_SSSE3_NATIVE)
  return _mm_sign_epi32(a, b);
#else
  simde__m128i_private
    r_,
    a_ = simde__m128i_to_private(a),
    b_ = simde__m128i_to_private(b);

  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
    int32x4_t m = vreinterpretq_s32_u32(vcgezq_s32(b_.neon_i32));
    r_.neon_i32 = veorq_s32(vandq_s32(a_.neon_i32, m), vandq_s32(vnegq_s32(a_.neon_i32), vmvnq_s32(m)));
  // #elif defined(SIMDE_ARM_NEON_A32V7_NATIVE)
  //   int32x4_t zero = vdupq_n_s32(0);
  //   // signed shift right: faster than vclt
  //   // (b < 0) ? 0xFFFFFFFF : 0
  //   uint32x4_t ltMask = vreinterpretq_u32_s32(vshrq_n_s32(b_.neon_i32, 31));
  //   // (b == 0) ? 0xFFFFFFFF : 0
  //   int32x4_t zeroMask = vreinterpretq_s32_u32(vceqq_s32(b_.neon_i32, zero));
  //   // neg = -a
  //   int32x4_t neg = vnegq_s32(a_.neon_i32);
  //   // bitwise select either a or neg based on ltMask
  //   int32x4_t masked = vbslq_s32(ltMask, a_.neon_i32, neg);
  //   // res = masked & (~zeroMask)
  //   r_.neon_i32 = vbicq_s32(masked, zeroMask);
  // test/x86/ssse3.c:1862: assertion failed: r.i32[0] == test_vec[i].r.i32[0] (1034759358 == -1034759358
  #else
    for (size_t i = 0 ; i < (sizeof(r_.i32) / sizeof(r_.i32[0])) ; i++) {
      r_.i32[i] = (b_.i32[i] < 0) ? (- a_.i32[i]) : ((b_.i32[i] > 0) ? (a_.i32[i]) : INT32_C(0));
    }
  #endif

  return simde__m128i_from_private(r_);
#endif
}
#if defined(SIMDE_X86_SSSE3_ENABLE_NATIVE_ALIASES)
#  define _mm_sign_epi32(a, b) simde_mm_sign_epi32(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m64
simde_mm_sign_pi8 (simde__m64 a, simde__m64 b) {
#if defined(SIMDE_X86_SSSE3_NATIVE) && defined(SIMDE_X86_MMX_NATIVE)
  return _mm_sign_pi8(a, b);
#else
  simde__m64_private
    r_,
    a_ = simde__m64_to_private(a),
    b_ = simde__m64_to_private(b);

  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
    int8x8_t m = vreinterpret_s8_u8(vcgez_s8(b_.neon_i8));
    r_.neon_i8 = veor_s8(vand_s8(a_.neon_i8, m), vand_s8(vneg_s8(a_.neon_i8), vmvn_s8(m)));
  #else
    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.i8) / sizeof(r_.i8[0])) ; i++) {
      r_.i8[i] = (b_.i8[i] < 0) ? (- a_.i8[i]) : ((b_.i8[i] > 0) ? (a_.i8[i]) : INT8_C(0));
    }
  #endif

  return simde__m64_from_private(r_);
#endif
}
#if defined(SIMDE_X86_SSSE3_ENABLE_NATIVE_ALIASES)
#  define _mm_sign_pi8(a, b) simde_mm_sign_pi8(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m64
simde_mm_sign_pi16 (simde__m64 a, simde__m64 b) {
#if defined(SIMDE_X86_SSSE3_NATIVE) && defined(SIMDE_X86_MMX_NATIVE)
  return _mm_sign_pi16(a, b);
#else
  simde__m64_private
    r_,
    a_ = simde__m64_to_private(a),
    b_ = simde__m64_to_private(b);

  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
    int16x4_t m = vreinterpret_s16_u16(vcgez_s16(b_.neon_i16));
    r_.neon_i16 = veor_s16(vand_s16(a_.neon_i16, m), vand_s16(vneg_s16(a_.neon_i16), vmvn_s16(m)));
  #else
    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.i16) / sizeof(r_.i16[0])) ; i++) {
      r_.i16[i] = (b_.i16[i] < 0) ? (- a_.i16[i]) : ((b_.i16[i] > 0) ? (a_.i16[i]) : INT16_C(0));
    }
  #endif

  return simde__m64_from_private(r_);
#endif
}
#if defined(SIMDE_X86_SSSE3_ENABLE_NATIVE_ALIASES)
#  define _mm_sign_pi16(a, b) simde_mm_sign_pi16(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m64
simde_mm_sign_pi32 (simde__m64 a, simde__m64 b) {
#if defined(SIMDE_X86_SSSE3_NATIVE) && defined(SIMDE_X86_MMX_NATIVE)
  return _mm_sign_pi32(a, b);
#else
  simde__m64_private
    r_,
    a_ = simde__m64_to_private(a),
    b_ = simde__m64_to_private(b);

  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
    int32x2_t m = vreinterpret_s32_u32(vcgez_s32(b_.neon_i32));
    r_.neon_i32 = veor_s32(vand_s32(a_.neon_i32, m), vand_s32(vneg_s32(a_.neon_i32), vmvn_s32(m)));
  #else
    for (size_t i = 0 ; i < (sizeof(r_.i32) / sizeof(r_.i32[0])) ; i++) {
      r_.i32[i] = (b_.i32[i] < 0) ? (- a_.i32[i]) : ((b_.i32[i] > 0) ? (a_.i32[i]) : INT32_C(0));
    }
  #endif

  return simde__m64_from_private(r_);
#endif
}
#if defined(SIMDE_X86_SSSE3_ENABLE_NATIVE_ALIASES)
#  define _mm_sign_pi32(a, b) simde_mm_sign_pi32(a, b)
#endif

SIMDE_END_DECLS_

HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_X86_SSE2_H) */
