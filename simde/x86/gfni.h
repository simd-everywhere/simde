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
 *   2020      Christopher Moore <moore@free.fr>
 *   2020      Evan Nemerson <evan@nemerson.com>
 */

#if !defined(SIMDE_X86_GFNI_H)
#define SIMDE_X86_GFNI_H

#include "avx512/add.h"
#include "avx512/and.h"
#include "avx512/cmpeq.h"
#include "avx512/cmpge.h"
#include "avx512/cmpgt.h"
#include "avx512/broadcast.h"
#include "avx512/permutex2var.h"
#include "avx512/mov.h"
#include "avx512/mov_mask.h"
#include "avx512/set.h"
#include "avx512/set1.h"
#include "avx512/setzero.h"
#include "avx512/shuffle.h"
#include "avx512/srli.h"
#include "avx512/xor.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

/* In all the *gf2p8affine* intrinsics the argument b must be a compile-time constant so we must use macros and simde_x_mm* helper functions */

/* N.B. The _mm*gf2p8affineinv_epi64_epi8 and _mm*gf2p8mul_epi8 intrinsics are for a Field Generator Polynomial (FGP) (aka reduction polynomial) of 0x11B */
/* Only the _mm*gf2p8affine_epi64_epi8 intrinsics do not assume this specific FGP */

/* Computing the inverse of an GF element is expensive so use this LUT for an FGP of 0x11B */

static const union {
  uint8_t      u8[256];
  simde__m128i m128i[16];
} simde_x_gf2p8inverse_lut = {
  {
   0x00, 0x01, 0x8d, 0xf6, 0xcb, 0x52, 0x7b, 0xd1, 0xe8, 0x4f, 0x29, 0xc0, 0xb0, 0xe1, 0xe5, 0xc7,
   0x74, 0xb4, 0xaa, 0x4b, 0x99, 0x2b, 0x60, 0x5f, 0x58, 0x3f, 0xfd, 0xcc, 0xff, 0x40, 0xee, 0xb2,
   0x3a, 0x6e, 0x5a, 0xf1, 0x55, 0x4d, 0xa8, 0xc9, 0xc1, 0x0a, 0x98, 0x15, 0x30, 0x44, 0xa2, 0xc2,
   0x2c, 0x45, 0x92, 0x6c, 0xf3, 0x39, 0x66, 0x42, 0xf2, 0x35, 0x20, 0x6f, 0x77, 0xbb, 0x59, 0x19,
   0x1d, 0xfe, 0x37, 0x67, 0x2d, 0x31, 0xf5, 0x69, 0xa7, 0x64, 0xab, 0x13, 0x54, 0x25, 0xe9, 0x09,
   0xed, 0x5c, 0x05, 0xca, 0x4c, 0x24, 0x87, 0xbf, 0x18, 0x3e, 0x22, 0xf0, 0x51, 0xec, 0x61, 0x17,
   0x16, 0x5e, 0xaf, 0xd3, 0x49, 0xa6, 0x36, 0x43, 0xf4, 0x47, 0x91, 0xdf, 0x33, 0x93, 0x21, 0x3b,
   0x79, 0xb7, 0x97, 0x85, 0x10, 0xb5, 0xba, 0x3c, 0xb6, 0x70, 0xd0, 0x06, 0xa1, 0xfa, 0x81, 0x82,
   0x83, 0x7e, 0x7f, 0x80, 0x96, 0x73, 0xbe, 0x56, 0x9b, 0x9e, 0x95, 0xd9, 0xf7, 0x02, 0xb9, 0xa4,
   0xde, 0x6a, 0x32, 0x6d, 0xd8, 0x8a, 0x84, 0x72, 0x2a, 0x14, 0x9f, 0x88, 0xf9, 0xdc, 0x89, 0x9a,
   0xfb, 0x7c, 0x2e, 0xc3, 0x8f, 0xb8, 0x65, 0x48, 0x26, 0xc8, 0x12, 0x4a, 0xce, 0xe7, 0xd2, 0x62,
   0x0c, 0xe0, 0x1f, 0xef, 0x11, 0x75, 0x78, 0x71, 0xa5, 0x8e, 0x76, 0x3d, 0xbd, 0xbc, 0x86, 0x57,
   0x0b, 0x28, 0x2f, 0xa3, 0xda, 0xd4, 0xe4, 0x0f, 0xa9, 0x27, 0x53, 0x04, 0x1b, 0xfc, 0xac, 0xe6,
   0x7a, 0x07, 0xae, 0x63, 0xc5, 0xdb, 0xe2, 0xea, 0x94, 0x8b, 0xc4, 0xd5, 0x9d, 0xf8, 0x90, 0x6b,
   0xb1, 0x0d, 0xd6, 0xeb, 0xc6, 0x0e, 0xcf, 0xad, 0x08, 0x4e, 0xd7, 0xe3, 0x5d, 0x50, 0x1e, 0xb3,
   0x5b, 0x23, 0x38, 0x34, 0x68, 0x46, 0x03, 0x8c, 0xdd, 0x9c, 0x7d, 0xa0, 0xcd, 0x1a, 0x41, 0x1c
  }
};

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_x_mm_gf2p8matrix_multiply_epi64_epi8 (simde__m128i x, simde__m128i A) {
  #if defined(SIMDE_X86_SSSE3_NATIVE)
    simde__m128i r, a, p;
    const simde__m128i byte_select = simde_x_mm_set_epu64x(UINT64_C(0xFDFDFDFDFDFDFDFD), UINT64_C(0xFEFEFEFEFEFEFEFE));
    const simde__m128i zero = simde_mm_setzero_si128();

    a = simde_mm_shuffle_epi8(A, simde_x_mm_set_epu64x(UINT64_C(0x08090A0B0C0D0E0F), UINT64_C(0x0001020304050607)));
    r = zero;

    #if !defined(__INTEL_COMPILER)
      SIMDE_VECTORIZE
    #endif
    for (int i = 0 ; i < 8 ; i++) {
      p = simde_mm_insert_epi16(zero, simde_mm_movemask_epi8(a), 1);
      p = simde_mm_shuffle_epi8(p, simde_mm_sign_epi8(byte_select, x));
      r = simde_mm_xor_si128(r, p);
      a = simde_mm_add_epi8(a, a);
      x = simde_mm_add_epi8(x, x);
    }

    return r;
  #else
    simde__m128i_private
      r_,
      x_ = simde__m128i_to_private(x),
      A_ = simde__m128i_to_private(A);
    const uint64_t ones = UINT64_C(0x0101010101010101);
    const uint64_t mask = UINT64_C(0x0102040810204080);
    uint64_t q;

    #if !defined(__INTEL_COMPILER)
      SIMDE_VECTORIZE
    #endif
    for (size_t i = 0 ; i < (sizeof(r_.u8) / sizeof(r_.u8[0])) ; i++) {
      q = simde_endian_bswap64_le(A_.u64[i / 8]);
      q &= HEDLEY_STATIC_CAST(uint64_t, x_.u8[i]) * ones;
      q ^= q >> 4;
      q ^= q >> 2;
      q ^= q >> 1;
      q &= ones;
      q *= 255;
      q &= mask;
      q |= q >> 32;
      q |= q >> 16;
      q |= q >> 8;
      r_.u8[i] = HEDLEY_STATIC_CAST(uint8_t, q);
    }

    return simde__m128i_from_private(r_);
  #endif
}

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_x_mm256_gf2p8matrix_multiply_epi64_epi8 (simde__m256i x, simde__m256i A) {
  #if defined(SIMDE_X86_AVX2_NATIVE)
    simde__m256i r, a, p;
    const simde__m256i byte_select = simde_x_mm256_set_epu64x(UINT64_C(0x0303030303030303), UINT64_C(0x0202020202020202),
                                                              UINT64_C(0x0101010101010101), UINT64_C(0x0000000000000000));
    a = simde_mm256_shuffle_epi8(A, simde_mm256_broadcastsi128_si256(simde_x_mm_set_epu64x(UINT64_C(0x08090A0B0C0D0E0F), UINT64_C(0x0001020304050607))));
    r = simde_mm256_setzero_si256();

    #if !defined(__INTEL_COMPILER)
      SIMDE_VECTORIZE
    #endif
    for (int i = 0 ; i < 8 ; i++) {
      p = simde_mm256_set1_epi32(simde_mm256_movemask_epi8(a));
      p = simde_mm256_shuffle_epi8(p, byte_select);
      p = simde_mm256_xor_si256(r, p);
      r = simde_mm256_blendv_epi8(r, p, x);
      a = simde_mm256_add_epi8(a, a);
      x = simde_mm256_add_epi8(x, x);
    }

    return r;
  #else
    simde__m256i_private
      r_,
      x_ = simde__m256i_to_private(x),
      A_ = simde__m256i_to_private(A);

    #if !defined(__INTEL_COMPILER)
      SIMDE_VECTORIZE
    #endif
    for (size_t i = 0 ; i < (sizeof(r_.m128i) / sizeof(r_.m128i[0])) ; i++) {
      r_.m128i[i] = simde_x_mm_gf2p8matrix_multiply_epi64_epi8(x_.m128i[i], A_.m128i[i]);
    }

    return simde__m256i_from_private(r_);
  #endif
}

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_x_mm512_gf2p8matrix_multiply_epi64_epi8 (simde__m512i x, simde__m512i A) {
  #if defined(SIMDE_X86_AVX512BW_NATIVE)
    simde__m512i r, a, p;
    const simde__m512i byte_select = simde_x_mm512_set_epu64(UINT64_C(0x0707070707070707), UINT64_C(0x0606060606060606), UINT64_C(0x0505050505050505), UINT64_C(0x0404040404040404),
                                                             UINT64_C(0x0303030303030303), UINT64_C(0x0202020202020202), UINT64_C(0x0101010101010101), UINT64_C(0X0000000000000000));
    a = simde_mm512_shuffle_epi8(A, simde_mm512_broadcast_i32x4(simde_x_mm_set_epu64x(UINT64_C(0x08090A0B0C0D0E0F), UINT64_C(0x0001020304050607))));
    r = simde_mm512_setzero_si512();

    #if !defined(__INTEL_COMPILER)
      SIMDE_VECTORIZE
    #endif
    for (int i = 0 ; i < 8 ; i++) {
      p = simde_mm512_set1_epi64(HEDLEY_STATIC_CAST(int64_t, simde_mm512_movepi8_mask(a)));
      p = simde_mm512_maskz_shuffle_epi8(simde_mm512_movepi8_mask(x), p, byte_select);
      r = simde_mm512_xor_si512(r, p);
      a = simde_mm512_add_epi8(a, a);
      x = simde_mm512_add_epi8(x, x);
    }

    return r;
  #else
    simde__m512i_private
      r_,
      x_ = simde__m512i_to_private(x),
      A_ = simde__m512i_to_private(A);

    #if !defined(__INTEL_COMPILER)
      SIMDE_VECTORIZE
    #endif
    for (size_t i = 0 ; i < (sizeof(r_.m256i) / sizeof(r_.m256i[0])) ; i++) {
      r_.m256i[i] = simde_x_mm256_gf2p8matrix_multiply_epi64_epi8(x_.m256i[i], A_.m256i[i]);
    }

    return simde__m512i_from_private(r_);
  #endif
}

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_x_mm_gf2p8inverse_epi8 (simde__m128i x) {
  #if defined(SIMDE_X86_SSE4_1_NATIVE)
    /* N.B. CM: this fallback may not be faster */
    simde__m128i r, u, t, test;
    const simde__m128i sixteens = simde_mm_set1_epi8(16);
    const simde__m128i masked_x = simde_mm_and_si128(x, simde_mm_set1_epi8(0x0F));

    test = simde_mm_set1_epi8(INT8_MIN /* 0x80 */);
    x = simde_mm_xor_si128(x, test);
    r = simde_mm_shuffle_epi8(simde_x_gf2p8inverse_lut.m128i[0], masked_x);

    #if !defined(__INTEL_COMPILER)
      SIMDE_VECTORIZE
    #endif
    for (int i = 1 ; i < 16 ; i++) {
      t = simde_mm_shuffle_epi8(simde_x_gf2p8inverse_lut.m128i[i], masked_x);
      test = simde_mm_add_epi8(test, sixteens);
      u = simde_mm_cmplt_epi8(x, test);
      r = simde_mm_blendv_epi8(t, r, u);
    }

    return r;
  #else
    simde__m128i_private
      r_,
      x_ = simde__m128i_to_private(x);

    #if !defined(__INTEL_COMPILER)
      SIMDE_VECTORIZE
    #endif
    for (size_t i = 0 ; i < (sizeof(r_.u8) / sizeof(r_.u8[0])) ; i++) {
      r_.u8[i] = simde_x_gf2p8inverse_lut.u8[x_.u8[i]];
    }

    return simde__m128i_from_private(r_);
  #endif
}

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_x_mm256_gf2p8inverse_epi8 (simde__m256i x) {
  #if defined(SIMDE_X86_AVX2_NATIVE)
    /* N.B. CM: this fallback may not be faster */
    simde__m256i r, u, t, test;
    const simde__m256i sixteens = simde_mm256_set1_epi8(16);
    const simde__m256i masked_x = simde_mm256_and_si256(x, simde_mm256_set1_epi8(0x0F));

    test = simde_mm256_set1_epi8(INT8_MIN /* 0x80 */);
    x = simde_mm256_xor_si256(x, test);
    r = simde_mm256_shuffle_epi8(simde_mm256_broadcastsi128_si256(simde_x_gf2p8inverse_lut.m128i[0]), masked_x);

    #if !defined(__INTEL_COMPILER)
      SIMDE_VECTORIZE
    #endif
    for (int i = 1 ; i < 16 ; i++) {
      t = simde_mm256_shuffle_epi8(simde_mm256_broadcastsi128_si256(simde_x_gf2p8inverse_lut.m128i[i]), masked_x);
      test = simde_mm256_add_epi8(test, sixteens);
      u = simde_mm256_cmpgt_epi8(test, x);
      r = simde_mm256_blendv_epi8(t, r, u);
    }

    return r;
  #else
    simde__m256i_private
      r_,
      x_ = simde__m256i_to_private(x);

    #if !defined(__INTEL_COMPILER)
      SIMDE_VECTORIZE
    #endif
    for (size_t i = 0 ; i < (sizeof(r_.m128i) / sizeof(r_.m128i[0])) ; i++) {
      r_.m128i[i] = simde_x_mm_gf2p8inverse_epi8(x_.m128i[i]);
    }

    return simde__m256i_from_private(r_);
  #endif
}

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_x_mm512_gf2p8inverse_epi8 (simde__m512i x) {
  /* N.B. CM: TODO: later add VBMI version using just two _mm512_permutex2var_epi8 and friends */
  /* But except for Cannon Lake all processors with VBMI also have GFNI */
  #if defined(SIMDE_X86_AVX512BW_NATIVE)
    /* N.B. CM: this fallback may not be faster */
    simde__m512i r, test;
    const simde__m512i sixteens = simde_mm512_set1_epi8(16);
    const simde__m512i masked_x = simde_mm512_and_si512(x, simde_mm512_set1_epi8(0x0F));

    r = simde_mm512_shuffle_epi8(simde_mm512_broadcast_i32x4(simde_x_gf2p8inverse_lut.m128i[0]), masked_x);
    test = sixteens;

    #if !defined(__INTEL_COMPILER)
      SIMDE_VECTORIZE
    #endif
    for (int i = 1 ; i < 16 ; i++) {
      r = simde_mm512_mask_shuffle_epi8(r, simde_mm512_cmpge_epu8_mask(x, test), simde_mm512_broadcast_i32x4(simde_x_gf2p8inverse_lut.m128i[i]), masked_x);
      test = simde_mm512_add_epi8(test, sixteens);
    }

    return r;
  #else
    simde__m512i_private
      r_,
      x_ = simde__m512i_to_private(x);

    #if !defined(__INTEL_COMPILER)
      SIMDE_VECTORIZE
    #endif
    for (size_t i = 0 ; i < (sizeof(r_.m256i) / sizeof(r_.m256i[0])) ; i++) {
      r_.m256i[i] = simde_x_mm256_gf2p8inverse_epi8(x_.m256i[i]);
    }

    return simde__m512i_from_private(r_);
  #endif
}

#define simde_x_mm_gf2p8matrix_multiply_inverse_epi64_epi8(x, A) simde_x_mm_gf2p8matrix_multiply_epi64_epi8(simde_x_mm_gf2p8inverse_epi8(x), A)
#define simde_x_mm256_gf2p8matrix_multiply_inverse_epi64_epi8(x, A) simde_x_mm256_gf2p8matrix_multiply_epi64_epi8(simde_x_mm256_gf2p8inverse_epi8(x), A)
#define simde_x_mm512_gf2p8matrix_multiply_inverse_epi64_epi8(x, A) simde_x_mm512_gf2p8matrix_multiply_epi64_epi8(simde_x_mm512_gf2p8inverse_epi8(x), A)

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_gf2p8affine_epi64_epi8 (simde__m128i x, simde__m128i A, int b)
    SIMDE_REQUIRE_CONSTANT_RANGE(b, 0, 255) {
  return simde_mm_xor_si128(simde_x_mm_gf2p8matrix_multiply_epi64_epi8(x, A), simde_mm_set1_epi8(HEDLEY_STATIC_CAST(int8_t, b)));
}
#if defined(SIMDE_X86_GFNI_NATIVE)
  #define simde_mm_gf2p8affine_epi64_epi8(x, A, b) _mm_gf2p8affine_epi64_epi8(x, A, b)
#endif
#if defined(SIMDE_X86_GFNI_ENABLE_NATIVE_ALIASES)
  #undef _mm_gf2p8affine_epi64_epi8
  #define _mm_gf2p8affine_epi64_epi8(x, A, b) simde_mm_gf2p8affine_epi64_epi8(x, A, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_gf2p8affine_epi64_epi8 (simde__m256i x, simde__m256i A, int b)
    SIMDE_REQUIRE_CONSTANT_RANGE(b, 0, 255) {
  return simde_mm256_xor_si256(simde_x_mm256_gf2p8matrix_multiply_epi64_epi8(x, A), simde_mm256_set1_epi8(HEDLEY_STATIC_CAST(int8_t, b)));
}
#if defined(SIMDE_X86_GFNI_NATIVE) && defined(SIMDE_X86_AVX_NATIVE)
  #define simde_mm256_gf2p8affine_epi64_epi8(x, A, b) _mm256_gf2p8affine_epi64_epi8(x, A, b)
#endif
#if defined(SIMDE_X86_GFNI_ENABLE_NATIVE_ALIASES)
  #undef _mm256_gf2p8affine_epi64_epi8
  #define _mm256_gf2p8affine_epi64_epi8(x, A, b) simde_mm256_gf2p8affine_epi64_epi8(x, A, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_gf2p8affine_epi64_epi8 (simde__m512i x, simde__m512i A, int b)
    SIMDE_REQUIRE_CONSTANT_RANGE(b, 0, 255) {
  return simde_mm512_xor_si512(simde_x_mm512_gf2p8matrix_multiply_epi64_epi8(x, A), simde_mm512_set1_epi8(HEDLEY_STATIC_CAST(int8_t, b)));
}
#if defined(SIMDE_X86_GFNI_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
  #define simde_mm512_gf2p8affine_epi64_epi8(x, A, b) _mm512_gf2p8affine_epi64_epi8(x, A, b)
#endif
#if defined(SIMDE_X86_GFNI_ENABLE_NATIVE_ALIASES)
  #undef _mm512_gf2p8affine_epi64_epi8
  #define _mm512_gf2p8affine_epi64_epi8(x, A, b) simde_mm512_gf2p8affine_epi64_epi8(x, A, b)
#endif

#if defined(SIMDE_X86_GFNI_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
  #define simde_mm_mask_gf2p8affine_epi64_epi8(src, k, x, A, b) _mm_mask_gf2p8affine_epi64_epi8(src, k, x, A, b)
#else
  #define simde_mm_mask_gf2p8affine_epi64_epi8(src, k, x, A, b) simde_mm_mask_mov_epi8(src, k, simde_mm_gf2p8affine_epi64_epi8(x, A, b))
#endif
#if defined(SIMDE_X86_GFNI_ENABLE_NATIVE_ALIASES)
  #undef _mm_mask_gf2p8affine_epi64_epi8
  #define _mm_mask_gf2p8affine_epi64_epi8(src, k, x, A, b) simde_mm_mask_gf2p8affine_epi64_epi8(src, k, x, A, b)
#endif

#if defined(SIMDE_X86_GFNI_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
  #define simde_mm256_mask_gf2p8affine_epi64_epi8(src, k, x, A, b) _mm256_mask_gf2p8affine_epi64_epi8(src, k, x, A, b)
#else
  #define simde_mm256_mask_gf2p8affine_epi64_epi8(src, k, x, A, b) simde_mm256_mask_mov_epi8(src, k, simde_mm256_gf2p8affine_epi64_epi8(x, A, b))
#endif
#if defined(SIMDE_X86_GFNI_ENABLE_NATIVE_ALIASES)
  #undef _mm256_mask_gf2p8affine_epi64_epi8
  #define _mm256_mask_gf2p8affine_epi64_epi8(src, k, x, A, b) simde_mm256_mask_gf2p8affine_epi64_epi8(src, k, x, A, b)
#endif

#if defined(SIMDE_X86_GFNI_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
  #define simde_mm512_mask_gf2p8affine_epi64_epi8(src, k, x, A, b) _mm512_mask_gf2p8affine_epi64_epi8(src, k, x, A, b)
#else
  #define simde_mm512_mask_gf2p8affine_epi64_epi8(src, k, x, A, b) simde_mm512_mask_mov_epi8(src, k, simde_mm512_gf2p8affine_epi64_epi8(x, A, b))
#endif
#if defined(SIMDE_X86_GFNI_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_gf2p8affine_epi64_epi8
  #define _mm512_mask_gf2p8affine_epi64_epi8(src, k, x, A, b) simde_mm512_mask_gf2p8affine_epi64_epi8(src, k, x, A, b)
#endif

#if defined(SIMDE_X86_GFNI_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
  #define simde_mm_maskz_gf2p8affine_epi64_epi8(k, x, A, b) _mm_maskz_gf2p8affine_epi64_epi8(k, x, A, b)
#else
  #define simde_mm_maskz_gf2p8affine_epi64_epi8(k, x, A, b) simde_mm_maskz_mov_epi8(k, simde_mm_gf2p8affine_epi64_epi8(x, A, b))
#endif
#if defined(SIMDE_X86_GFNI_ENABLE_NATIVE_ALIASES)
  #undef _mm_maskz_gf2p8affine_epi64_epi8
  #define _mm_maskz_gf2p8affine_epi64_epi8(k, x, A, b) simde_mm_maskz_gf2p8affine_epi64_epi8(k, x, A, b)
#endif

#if defined(SIMDE_X86_GFNI_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
  #define simde_mm256_maskz_gf2p8affine_epi64_epi8(k, x, A, b) _mm256_maskz_gf2p8affine_epi64_epi8(k, x, A, b)
#else
  #define simde_mm256_maskz_gf2p8affine_epi64_epi8(k, x, A, b) simde_mm256_maskz_mov_epi8(k, simde_mm256_gf2p8affine_epi64_epi8(x, A, b))
#endif
#if defined(SIMDE_X86_GFNI_ENABLE_NATIVE_ALIASES)
  #undef _mm256_maskz_gf2p8affine_epi64_epi8
  #define _mm256_maskz_gf2p8affine_epi64_epi8(k, x, A, b) simde_mm256_maskz_gf2p8affine_epi64_epi8(k, x, A, b)
#endif

#if defined(SIMDE_X86_GFNI_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
  #define simde_mm512_maskz_gf2p8affine_epi64_epi8(k, x, A, b) _mm512_maskz_gf2p8affine_epi64_epi8(k, x, A, b)
#else
  #define simde_mm512_maskz_gf2p8affine_epi64_epi8(k, x, A, b) simde_mm512_maskz_mov_epi8(k, simde_mm512_gf2p8affine_epi64_epi8(x, A, b))
#endif
#if defined(SIMDE_X86_GFNI_ENABLE_NATIVE_ALIASES)
  #undef _mm512_maskz_gf2p8affine_epi64_epi8
  #define _mm512_maskz_gf2p8affine_epi64_epi8(k, x, A, b) simde_mm512_maskz_gf2p8affine_epi64_epi8(k, x, A, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_gf2p8affineinv_epi64_epi8 (simde__m128i x, simde__m128i A, int b)
    SIMDE_REQUIRE_CONSTANT_RANGE(b, 0, 255) {
  return simde_mm_xor_si128(simde_x_mm_gf2p8matrix_multiply_inverse_epi64_epi8(x, A), simde_mm_set1_epi8(HEDLEY_STATIC_CAST(int8_t, b)));
}
#if defined(SIMDE_X86_GFNI_NATIVE)
  #define simde_mm_gf2p8affineinv_epi64_epi8(x, A, b) _mm_gf2p8affineinv_epi64_epi8(x, A, b)
#endif
#if defined(SIMDE_X86_GFNI_ENABLE_NATIVE_ALIASES)
  #undef _mm_gf2p8affineinv_epi64_epi8
  #define _mm_gf2p8affineinv_epi64_epi8(x, A, b) simde_mm_gf2p8affineinv_epi64_epi8(x, A, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_gf2p8affineinv_epi64_epi8 (simde__m256i x, simde__m256i A, int b)
    SIMDE_REQUIRE_CONSTANT_RANGE(b, 0, 255) {
  return simde_mm256_xor_si256(simde_x_mm256_gf2p8matrix_multiply_inverse_epi64_epi8(x, A), simde_mm256_set1_epi8(HEDLEY_STATIC_CAST(int8_t, b)));
}
#if defined(SIMDE_X86_GFNI_NATIVE) && defined(SIMDE_X86_AVX_NATIVE)
  #define simde_mm256_gf2p8affineinv_epi64_epi8(x, A, b) _mm256_gf2p8affineinv_epi64_epi8(x, A, b)
#endif
#if defined(SIMDE_X86_GFNI_ENABLE_NATIVE_ALIASES)
  #undef _mm256_gf2p8affineinv_epi64_epi8
  #define _mm256_gf2p8affineinv_epi64_epi8(x, A, b) simde_mm256_gf2p8affineinv_epi64_epi8(x, A, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_gf2p8affineinv_epi64_epi8 (simde__m512i x, simde__m512i A, int b)
    SIMDE_REQUIRE_CONSTANT_RANGE(b, 0, 255) {
  return simde_mm512_xor_si512(simde_x_mm512_gf2p8matrix_multiply_inverse_epi64_epi8(x, A), simde_mm512_set1_epi8(HEDLEY_STATIC_CAST(int8_t, b)));
}
#if defined(SIMDE_X86_GFNI_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
  #define simde_mm512_gf2p8affineinv_epi64_epi8(x, A, b) _mm512_gf2p8affineinv_epi64_epi8(x, A, b)
#endif
#if defined(SIMDE_X86_GFNI_ENABLE_NATIVE_ALIASES)
  #undef _mm512_gf2p8affineinv_epi64_epi8
  #define _mm512_gf2p8affineinv_epi64_epi8(x, A, b) simde_mm512_gf2p8affineinv_epi64_epi8(x, A, b)
#endif

#if defined(SIMDE_X86_GFNI_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
  #define simde_mm_mask_gf2p8affineinv_epi64_epi8(src, k, x, A, b) _mm_mask_gf2p8affineinv_epi64_epi8(src, k, x, A, b)
#else
  #define simde_mm_mask_gf2p8affineinv_epi64_epi8(src, k, x, A, b) simde_mm_mask_mov_epi8(src, k, simde_mm_gf2p8affineinv_epi64_epi8(x, A, b))
#endif
#if defined(SIMDE_X86_GFNI_ENABLE_NATIVE_ALIASES)
  #undef _mm_mask_gf2p8affineinv_epi64_epi8
  #define _mm_mask_gf2p8affineinv_epi64_epi8(src, k, x, A, b) simde_mm_mask_gf2p8affineinv_epi64_epi8(src, k, x, A, b)
#endif

#if defined(SIMDE_X86_GFNI_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
  #define simde_mm256_mask_gf2p8affineinv_epi64_epi8(src, k, x, A, b) _mm256_mask_gf2p8affineinv_epi64_epi8(src, k, x, A, b)
#else
  #define simde_mm256_mask_gf2p8affineinv_epi64_epi8(src, k, x, A, b) simde_mm256_mask_mov_epi8(src, k, simde_mm256_gf2p8affineinv_epi64_epi8(x, A, b))
#endif
#if defined(SIMDE_X86_GFNI_ENABLE_NATIVE_ALIASES)
  #undef _mm256_mask_gf2p8affineinv_epi64_epi8
  #define _mm256_mask_gf2p8affineinv_epi64_epi8(src, k, x, A, b) simde_mm256_mask_gf2p8affineinv_epi64_epi8(src, k, x, A, b)
#endif

#if defined(SIMDE_X86_GFNI_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
  #define simde_mm512_mask_gf2p8affineinv_epi64_epi8(src, k, x, A, b) _mm512_mask_gf2p8affineinv_epi64_epi8(src, k, x, A, b)
#else
  #define simde_mm512_mask_gf2p8affineinv_epi64_epi8(src, k, x, A, b) simde_mm512_mask_mov_epi8(src, k, simde_mm512_gf2p8affineinv_epi64_epi8(x, A, b))
#endif
#if defined(SIMDE_X86_GFNI_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_gf2p8affineinv_epi64_epi8
  #define _mm512_mask_gf2p8affineinv_epi64_epi8(src, k, x, A, b) simde_mm512_mask_gf2p8affineinv_epi64_epi8(src, k, x, A, b)
#endif

#if defined(SIMDE_X86_GFNI_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
  #define simde_mm_maskz_gf2p8affineinv_epi64_epi8(k, x, A, b) _mm_maskz_gf2p8affineinv_epi64_epi8(k, x, A, b)
#else
  #define simde_mm_maskz_gf2p8affineinv_epi64_epi8(k, x, A, b) simde_mm_maskz_mov_epi8(k, simde_mm_gf2p8affineinv_epi64_epi8(x, A, b))
#endif
#if defined(SIMDE_X86_GFNI_ENABLE_NATIVE_ALIASES)
  #undef _mm_maskz_gf2p8affineinv_epi64_epi8
  #define _mm_maskz_gf2p8affineinv_epi64_epi8(k, x, A, b) simde_mm_maskz_gf2p8affineinv_epi64_epi8(k, x, A, b)
#endif

#if defined(SIMDE_X86_GFNI_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
  #define simde_mm256_maskz_gf2p8affineinv_epi64_epi8(k, x, A, b) _mm256_maskz_gf2p8affineinv_epi64_epi8(k, x, A, b)
#else
  #define simde_mm256_maskz_gf2p8affineinv_epi64_epi8(k, x, A, b) simde_mm256_maskz_mov_epi8(k, simde_mm256_gf2p8affineinv_epi64_epi8(x, A, b))
#endif
#if defined(SIMDE_X86_GFNI_ENABLE_NATIVE_ALIASES)
  #undef _mm256_maskz_gf2p8affineinv_epi64_epi8
  #define _mm256_maskz_gf2p8affineinv_epi64_epi8(k, x, A, b) simde_mm256_maskz_gf2p8affineinv_epi64_epi8(k, x, A, b)
#endif

#if defined(SIMDE_X86_GFNI_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
  #define simde_mm512_maskz_gf2p8affineinv_epi64_epi8(k, x, A, b) _mm512_maskz_gf2p8affineinv_epi64_epi8(k, x, A, b)
#else
  #define simde_mm512_maskz_gf2p8affineinv_epi64_epi8(k, x, A, b) simde_mm512_maskz_mov_epi8(k, simde_mm512_gf2p8affineinv_epi64_epi8(x, A, b))
#endif
#if defined(SIMDE_X86_GFNI_ENABLE_NATIVE_ALIASES)
  #undef _mm512_maskz_gf2p8affineinv_epi64_epi8
  #define _mm512_maskz_gf2p8affineinv_epi64_epi8(k, x, A, b) simde_mm512_maskz_gf2p8affineinv_epi64_epi8(k, x, A, b)
#endif


SIMDE_FUNCTION_ATTRIBUTES
simde__m128i simde_mm_gf2p8mul_epi8 (simde__m128i a, simde__m128i b) {
  #if defined(SIMDE_X86_SSE2_NATIVE)
    simde__m128i r, t;
    const simde__m128i zero = simde_mm_setzero_si128();
    const simde__m128i ones = simde_mm_set1_epi8(0x01);

    /* The field generator polynomial is 0x11B but we drop the 0x100 bit */
    const simde__m128i fgp = simde_mm_set1_epi8(0x1B);

    r = zero;

    #if !defined(__INTEL_COMPILER)
      SIMDE_VECTORIZE
    #endif
    for (int i = 0 ; i < 8 ; i++) {
      t = simde_mm_and_si128(b, ones);
      t = simde_mm_cmpeq_epi8(t, ones);
      t = simde_mm_and_si128(a, t);
      r = simde_mm_xor_si128(r, t);
      t = simde_mm_cmpgt_epi8(zero, a);
      t = simde_mm_and_si128(fgp, t);
      a = simde_mm_add_epi8(a, a);
      a = simde_mm_xor_si128(a, t);
      b = simde_mm_srli_epi64(b, 1);
    }

    return r;
  #else
    simde__m128i_private
      r_,
      a_ = simde__m128i_to_private(a),
      b_ = simde__m128i_to_private(b);

    /* The field generator polynomial is 0x11B but we drop the 0x100 bit */
    const uint8_t fgp = 0x1B;

    #if !defined(__INTEL_COMPILER)
      SIMDE_VECTORIZE
    #endif
    for (size_t i = 0 ; i < (sizeof(r_.u8) / sizeof(r_.u8[0])) ; i++) {
      r_.u8[i] = 0;
      while ((a_.u8[i] != 0) && (b_.u8[i] != 0)) {
        if (b_.u8[i] & 1)
          r_.u8[i] ^= a_.u8[i];

        if (a_.u8[i] & 0x80)
          a_.u8[i] = HEDLEY_STATIC_CAST(uint8_t, (a_.u8[i] << 1) ^ fgp);
        else
          a_.u8[i] <<= 1;

        b_.u8[i] >>= 1;
      }
    }

    return simde__m128i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_GFNI_NATIVE)
  #define simde_mm_gf2p8mul_epi8(a, b) _mm_gf2p8mul_epi8(a, b)
#endif
#if defined(SIMDE_X86_GFNI_ENABLE_NATIVE_ALIASES)
  #undef _mm_gf2p8mul_epi8
  #define _mm_gf2p8mul_epi8(a, b) simde_mm_gf2p8mul_epi8(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_gf2p8mul_epi8 (simde__m256i a, simde__m256i b) {
  #if defined(SIMDE_X86_AVX2_NATIVE)
    simde__m256i r, t;
    const simde__m256i zero = simde_mm256_setzero_si256();
    const simde__m256i ones = simde_mm256_set1_epi8(0x01);

    /* The field generator polynomial is 0x11B but we drop the 0x100 bit */
    const simde__m256i fgp = simde_mm256_set1_epi8(0x1B);

    r = zero;

    #if !defined(__INTEL_COMPILER)
      SIMDE_VECTORIZE
    #endif
    for (int i = 0 ; i < 8 ; i++) {
      t = simde_mm256_and_si256(b, ones);
      t = simde_mm256_cmpeq_epi8(t, ones);
      t = simde_mm256_and_si256(a, t);
      r = simde_mm256_xor_si256(r, t);
      t = simde_mm256_cmpgt_epi8(zero, a);
      t = simde_mm256_and_si256(fgp, t);
      a = simde_mm256_add_epi8(a, a);
      a = simde_mm256_xor_si256(a, t);
      b = simde_mm256_srli_epi64(b, 1);
    }

    return r;
  #else
    simde__m256i_private
      r_,
      a_ = simde__m256i_to_private(a),
      b_ = simde__m256i_to_private(b);

    #if !defined(__INTEL_COMPILER)
      SIMDE_VECTORIZE
    #endif
    for (size_t i = 0 ; i < (sizeof(r_.m128i) / sizeof(r_.m128i[0])) ; i++) {
      r_.m128i[i] = simde_mm_gf2p8mul_epi8(a_.m128i[i], b_.m128i[i]);
    }

    return simde__m256i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_GFNI_NATIVE) && defined(SIMDE_X86_AVX_NATIVE)
  #define simde_mm256_gf2p8mul_epi8(a, b) _mm256_gf2p8mul_epi8(a, b)
#endif
#if defined(SIMDE_X86_GFNI_ENABLE_NATIVE_ALIASES)
  #undef _mm256_gf2p8mul_epi8
  #define _mm256_gf2p8mul_epi8(a, b) simde_mm256_gf2p8mul_epi8(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_gf2p8mul_epi8 (simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_AVX512BW_NATIVE)
    simde__m512i r, t;
    simde__mmask64 m;
    const simde__m512i zero = simde_mm512_setzero_si512();
    const simde__m512i ones = simde_mm512_set1_epi8(0x01);

    /* The field generator polynomial is 0x11B but we drop the 0x100 bit */
    const simde__m512i fgp = simde_mm512_set1_epi8(0x1B);

    r = zero;

    #if !defined(__INTEL_COMPILER)
      SIMDE_VECTORIZE
    #endif
    for (int i = 0 ; i < 8 ; i++) {
      t = simde_mm512_and_si512(b, ones);
      m = simde_mm512_cmpeq_epi8_mask(t, ones);
      t = simde_mm512_maskz_mov_epi8(m, a);
      r = simde_mm512_xor_si512(r, t);
      m = simde_mm512_cmpgt_epi8_mask(zero, a);
      a = simde_mm512_add_epi8(a, a);
      t = simde_mm512_maskz_mov_epi8(m, fgp);
      a = simde_mm512_xor_si512(a, t);
      b = simde_mm512_srli_epi64(b, 1);
    }

    return r;
  #else
    simde__m512i_private
      r_,
      a_ = simde__m512i_to_private(a),
      b_ = simde__m512i_to_private(b);

    #if !defined(__INTEL_COMPILER)
      SIMDE_VECTORIZE
    #endif
    for (size_t i = 0 ; i < (sizeof(r_.m128i) / sizeof(r_.m128i[0])) ; i++) {
      r_.m128i[i] = simde_mm_gf2p8mul_epi8(a_.m128i[i], b_.m128i[i]);
    }

    return simde__m512i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_GFNI_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
  #define simde_mm512_gf2p8mul_epi8(a, b) _mm512_gf2p8mul_epi8(a, b)
#endif
#if defined(SIMDE_X86_GFNI_ENABLE_NATIVE_ALIASES)
  #undef _mm512_gf2p8mul_epi8
  #define _mm512_gf2p8mul_epi8(a, b) simde_mm512_gf2p8mul_epi8(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_mask_gf2p8mul_epi8 (simde__m128i src, simde__mmask16 k, simde__m128i a, simde__m128i b) {
  #if defined(SIMDE_X86_GFNI_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm_mask_gf2p8mul_epi8(src, k, a, b);
  #else
    return simde_mm_mask_mov_epi8(src, k, simde_mm_gf2p8mul_epi8(a, b));
  #endif
}
#if defined(SIMDE_X86_GFNI_ENABLE_NATIVE_ALIASES)
  #undef _mm_mask_gf2p8mul_epi8
  #define _mm_mask_gf2p8mul_epi8(src, k, a, b) simde_mm_mask_gf2p8mul_epi8(src, k, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_mask_gf2p8mul_epi8 (simde__m256i src, simde__mmask32 k, simde__m256i a, simde__m256i b) {
  #if defined(SIMDE_X86_GFNI_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm256_mask_gf2p8mul_epi8(src, k, a, b);
  #else
    return simde_mm256_mask_mov_epi8(src, k, simde_mm256_gf2p8mul_epi8(a, b));
  #endif
}
#if defined(SIMDE_X86_GFNI_ENABLE_NATIVE_ALIASES)
  #undef _mm256_mask_gf2p8mul_epi8
  #define _mm256_mask_gf2p8mul_epi8(src, k, a, b) simde_mm256_mask_gf2p8mul_epi8(src, k, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_mask_gf2p8mul_epi8 (simde__m512i src, simde__mmask64 k, simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_GFNI_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_mask_gf2p8mul_epi8(src, k, a, b);
  #else
    return simde_mm512_mask_mov_epi8(src, k, simde_mm512_gf2p8mul_epi8(a, b));
  #endif
}
#if defined(SIMDE_X86_GFNI_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_gf2p8mul_epi8
  #define _mm512_mask_gf2p8mul_epi8(src, k, a, b) simde_mm512_mask_gf2p8mul_epi8(src, k, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_maskz_gf2p8mul_epi8 (simde__mmask16 k, simde__m128i a, simde__m128i b) {
  #if defined(SIMDE_X86_GFNI_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm_maskz_gf2p8mul_epi8(k, a, b);
  #else
    return simde_mm_maskz_mov_epi8(k, simde_mm_gf2p8mul_epi8(a, b));
  #endif
}
#if defined(SIMDE_X86_GFNI_ENABLE_NATIVE_ALIASES)
  #undef _mm_maskz_gf2p8mul_epi8
  #define _mm_maskz_gf2p8mul_epi8(k, a, b) simde_mm_maskz_gf2p8mul_epi8(k, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_maskz_gf2p8mul_epi8 (simde__mmask32 k, simde__m256i a, simde__m256i b) {
  #if defined(SIMDE_X86_GFNI_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm256_maskz_gf2p8mul_epi8(k, a, b);
  #else
    return  simde_mm256_maskz_mov_epi8(k, simde_mm256_gf2p8mul_epi8(a, b));
  #endif
}
#if defined(SIMDE_X86_GFNI_ENABLE_NATIVE_ALIASES)
  #undef _mm256_maskz_gf2p8mul_epi8
  #define _mm256_maskz_gf2p8mul_epi8(k, a, b) simde_mm256_maskz_gf2p8mul_epi8(k, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_maskz_gf2p8mul_epi8 (simde__mmask64 k, simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_GFNI_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_maskz_gf2p8mul_epi8(k, a, b);
  #else
    return simde_mm512_maskz_mov_epi8(k, simde_mm512_gf2p8mul_epi8(a, b));
  #endif
}
#if defined(SIMDE_X86_GFNI_ENABLE_NATIVE_ALIASES)
  #undef _mm512_maskz_gf2p8mul_epi8
  #define _mm512_maskz_gf2p8mul_epi8(k, a, b) simde_mm512_maskz_gf2p8mul_epi8(k, a, b)
#endif

SIMDE_END_DECLS_

HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_X86_GFNI_H) */
