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
 *   2020      Evan Nemerson <evan@nemerson.com>
 */

#if !defined(SIMDE_SVML_H)
#define SIMDE_SVML_H

#include "avx2.h"
#include "avx512f.h"

#if !defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_ENABLE_NATIVE_ALIASES)
#  define SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES
#endif

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

#if !defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_ENABLE_NATIVE_ALIASES)
#  define SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_div_epi8 (simde__m128i a, simde__m128i b) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_div_epi8(a, b);
  #else
    simde__m128i_private
      r_,
      a_ = simde__m128i_to_private(a),
      b_ = simde__m128i_to_private(b);

  #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
    r_.i8 = a_.i8 / b_.i8;
  #elif defined(SIMDE_WASM_SIMD128_NATIVE)
    r_.wasm_v128 = wasm_i8x4_div(a_.wasm_v128, b_.wasm_v128);
  #else
    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.i8) / sizeof(r_.i8[0])) ; i++) {
      r_.i8[i] = a_.i8[i] / b_.i8[i];
    }
  #endif

    return simde__m128i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm_div_epi8
  #define _mm_div_epi8(a, b) simde_mm_div_epi8((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_div_epi16 (simde__m128i a, simde__m128i b) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_div_epi16(a, b);
  #else
    simde__m128i_private
      r_,
      a_ = simde__m128i_to_private(a),
      b_ = simde__m128i_to_private(b);

  #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
    r_.i16 = a_.i16 / b_.i16;
  #elif defined(SIMDE_WASM_SIMD128_NATIVE)
    r_.wasm_v128 = wasm_i16x4_div(a_.wasm_v128, b_.wasm_v128);
  #else
    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.i16) / sizeof(r_.i16[0])) ; i++) {
      r_.i16[i] = a_.i16[i] / b_.i16[i];
    }
  #endif

    return simde__m128i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm_div_epi16
  #define _mm_div_epi16(a, b) simde_mm_div_epi16((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_div_epi32 (simde__m128i a, simde__m128i b) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_div_epi32(a, b);
  #else
    simde__m128i_private
      r_,
      a_ = simde__m128i_to_private(a),
      b_ = simde__m128i_to_private(b);

  #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
    r_.i32 = a_.i32 / b_.i32;
  #elif defined(SIMDE_WASM_SIMD128_NATIVE)
    r_.wasm_v128 = wasm_i32x4_div(a_.wasm_v128, b_.wasm_v128);
  #else
    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.i32) / sizeof(r_.i32[0])) ; i++) {
      r_.i32[i] = a_.i32[i] / b_.i32[i];
    }
  #endif

    return simde__m128i_from_private(r_);
  #endif
}
#define simde_mm_idiv_epi32(a, b) simde_mm_div_epi32(a, b)
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm_div_epi32
  #define _mm_div_epi32(a, b) simde_mm_div_epi32(a, b)
  #undef _mm_idiv_epi32
  #define _mm_idiv_epi32(a, b) simde_mm_div_epi32(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_div_epi64 (simde__m128i a, simde__m128i b) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_div_epi64(a, b);
  #else
    simde__m128i_private
      r_,
      a_ = simde__m128i_to_private(a),
      b_ = simde__m128i_to_private(b);

  #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
    r_.i64 = a_.i64 / b_.i64;
  #elif defined(SIMDE_WASM_SIMD128_NATIVE)
    r_.wasm_v128 = wasm_i64x4_div(a_.wasm_v128, b_.wasm_v128);
  #else
    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.i64) / sizeof(r_.i64[0])) ; i++) {
      r_.i64[i] = a_.i64[i] / b_.i64[i];
    }
  #endif

    return simde__m128i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm_div_epi64
  #define _mm_div_epi64(a, b) simde_mm_div_epi64((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_div_epu8 (simde__m128i a, simde__m128i b) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_div_epu8(a, b);
  #else
    simde__m128i_private
      r_,
      a_ = simde__m128i_to_private(a),
      b_ = simde__m128i_to_private(b);

  #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
    r_.u8 = a_.u8 / b_.u8;
  #elif defined(SIMDE_WASM_SIMD128_NATIVE)
    r_.wasm_v128 =  wasm_u8x16_div(a_.wasm_v128, b_.wasm_v128);
  #else
    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.u8) / sizeof(r_.u8[0])) ; i++) {
      r_.u8[i] = a_.u8[i] / b_.u8[i];
    }
  #endif

    return simde__m128i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm_div_epu8
  #define _mm_div_epu8(a, b) simde_mm_div_epu8((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_div_epu16 (simde__m128i a, simde__m128i b) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_div_epu16(a, b);
  #else
    simde__m128i_private
      r_,
      a_ = simde__m128i_to_private(a),
      b_ = simde__m128i_to_private(b);

  #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
    r_.u16 = a_.u16 / b_.u16;
  #elif defined(SIMDE_WASM_SIMD128_NATIVE)
    r_.wasm_v128 =  wasm_u16x16_div(a_.wasm_v128, b_.wasm_v128);
  #else
    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.u16) / sizeof(r_.u16[0])) ; i++) {
      r_.u16[i] = a_.u16[i] / b_.u16[i];
    }
  #endif

    return simde__m128i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm_div_epu16
  #define _mm_div_epu16(a, b) simde_mm_div_epu16((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_div_epu32 (simde__m128i a, simde__m128i b) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_div_epu32(a, b);
  #else
    simde__m128i_private
      r_,
      a_ = simde__m128i_to_private(a),
      b_ = simde__m128i_to_private(b);

  #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
    r_.u32 = a_.u32 / b_.u32;
  #elif defined(SIMDE_WASM_SIMD128_NATIVE)
    r_.wasm_v128 =  wasm_u32x16_div(a_.wasm_v128, b_.wasm_v128);
  #else
    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.u32) / sizeof(r_.u32[0])) ; i++) {
      r_.u32[i] = a_.u32[i] / b_.u32[i];
    }
  #endif

    return simde__m128i_from_private(r_);
  #endif
}
#define simde_mm_udiv_epu32(a, b) simde_mm_div_epu32(a, b)
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm_div_epu32
  #define _mm_div_epu32(a, b) simde_mm_div_epu32(a, b)
  #undef _mm_udiv_epu32
  #define _mm_udiv_epu32(a, b) simde_mm_div_epu32(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_div_epu64 (simde__m128i a, simde__m128i b) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_div_epu64(a, b);
  #else
    simde__m128i_private
      r_,
      a_ = simde__m128i_to_private(a),
      b_ = simde__m128i_to_private(b);

  #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
    r_.u64 = a_.u64 / b_.u64;
  #elif defined(SIMDE_WASM_SIMD128_NATIVE)
    r_.wasm_v128 =  wasm_u64x16_div(a_.wasm_v128, b_.wasm_v128);
  #else
    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.u64) / sizeof(r_.u64[0])) ; i++) {
      r_.u64[i] = a_.u64[i] / b_.u64[i];
    }
  #endif

    return simde__m128i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm_div_epu64
  #define _mm_div_epu64(a, b) simde_mm_div_epu64((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_div_epi8 (simde__m256i a, simde__m256i b) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX_NATIVE)
    return _mm256_div_epi8(a, b);
  #else
    simde__m256i_private
      r_,
      a_ = simde__m256i_to_private(a),
      b_ = simde__m256i_to_private(b);

  #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
    r_.i8 = a_.i8 / b_.i8;
  #else
    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.i8) / sizeof(r_.i8[0])) ; i++) {
      r_.i8[i] = a_.i8[i] / b_.i8[i];
    }
  #endif

    return simde__m256i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm256_div_epi8
  #define _mm256_div_epi8(a, b) simde_mm256_div_epi8((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_div_epi16 (simde__m256i a, simde__m256i b) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX_NATIVE)
    return _mm256_div_epi16(a, b);
  #else
    simde__m256i_private
      r_,
      a_ = simde__m256i_to_private(a),
      b_ = simde__m256i_to_private(b);

  #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
    r_.i16 = a_.i16 / b_.i16;
  #else
    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.i16) / sizeof(r_.i16[0])) ; i++) {
      r_.i16[i] = a_.i16[i] / b_.i16[i];
    }
  #endif

    return simde__m256i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm256_div_epi16
  #define _mm256_div_epi16(a, b) simde_mm256_div_epi16((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_div_epi32 (simde__m256i a, simde__m256i b) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX_NATIVE)
    return _mm256_div_epi32(a, b);
  #else
    simde__m256i_private
      r_,
      a_ = simde__m256i_to_private(a),
      b_ = simde__m256i_to_private(b);

  #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
    r_.i32 = a_.i32 / b_.i32;
  #else
    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.i32) / sizeof(r_.i32[0])) ; i++) {
      r_.i32[i] = a_.i32[i] / b_.i32[i];
    }
  #endif

    return simde__m256i_from_private(r_);
  #endif
}
#define simde_mm256_idiv_epi32(a, b) simde_mm256_div_epi32(a, b)
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm256_div_epi32
  #define _mm256_div_epi32(a, b) simde_mm256_div_epi32(a, b)
  #undef _mm256_idiv_epi32
  #define _mm256_idiv_epi32(a, b) simde_mm256_div_epi32(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_div_epi64 (simde__m256i a, simde__m256i b) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX_NATIVE)
    return _mm256_div_epi64(a, b);
  #else
    simde__m256i_private
      r_,
      a_ = simde__m256i_to_private(a),
      b_ = simde__m256i_to_private(b);

  #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
    r_.i64 = a_.i64 / b_.i64;
  #else
    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.i64) / sizeof(r_.i64[0])) ; i++) {
      r_.i64[i] = a_.i64[i] / b_.i64[i];
    }
  #endif

    return simde__m256i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm256_div_epi64
  #define _mm256_div_epi64(a, b) simde_mm256_div_epi64((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_div_epu8 (simde__m256i a, simde__m256i b) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX_NATIVE)
    return _mm256_div_epu8(a, b);
  #else
    simde__m256i_private
      r_,
      a_ = simde__m256i_to_private(a),
      b_ = simde__m256i_to_private(b);

  #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
    r_.u8 = a_.u8 / b_.u8;
  #else
    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.u8) / sizeof(r_.u8[0])) ; i++) {
      r_.u8[i] = a_.u8[i] / b_.u8[i];
    }
  #endif

    return simde__m256i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm256_div_epu8
  #define _mm256_div_epu8(a, b) simde_mm256_div_epu8((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_div_epu16 (simde__m256i a, simde__m256i b) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX_NATIVE)
    return _mm256_div_epu16(a, b);
  #else
    simde__m256i_private
      r_,
      a_ = simde__m256i_to_private(a),
      b_ = simde__m256i_to_private(b);

  #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
    r_.u16 = a_.u16 / b_.u16;
  #else
    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.u16) / sizeof(r_.u16[0])) ; i++) {
      r_.u16[i] = a_.u16[i] / b_.u16[i];
    }
  #endif

    return simde__m256i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm256_div_epu16
  #define _mm256_div_epu16(a, b) simde_mm256_div_epu16((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_div_epu32 (simde__m256i a, simde__m256i b) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX_NATIVE)
    return _mm256_div_epu32(a, b);
  #else
    simde__m256i_private
      r_,
      a_ = simde__m256i_to_private(a),
      b_ = simde__m256i_to_private(b);

  #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
    r_.u32 = a_.u32 / b_.u32;
  #else
    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.u32) / sizeof(r_.u32[0])) ; i++) {
      r_.u32[i] = a_.u32[i] / b_.u32[i];
    }
  #endif

    return simde__m256i_from_private(r_);
  #endif
}
#define simde_mm256_udiv_epu32(a, b) simde_mm256_div_epu32(a, b)
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm256_div_epu32
  #define _mm256_div_epu32(a, b) simde_mm256_div_epu32(a, b)
  #undef _mm256_udiv_epu32
  #define _mm256_udiv_epu32(a, b) simde_mm256_div_epu32(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_div_epu64 (simde__m256i a, simde__m256i b) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX_NATIVE)
    return _mm256_div_epu64(a, b);
  #else
    simde__m256i_private
      r_,
      a_ = simde__m256i_to_private(a),
      b_ = simde__m256i_to_private(b);

  #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
    r_.u64 = a_.u64 / b_.u64;
  #else
    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.u64) / sizeof(r_.u64[0])) ; i++) {
      r_.u64[i] = a_.u64[i] / b_.u64[i];
    }
  #endif

    return simde__m256i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm256_div_epu64
  #define _mm256_div_epu64(a, b) simde_mm256_div_epu64((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_div_epi8 (simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_div_epi8(a, b);
  #else
    simde__m512i_private
      r_,
      a_ = simde__m512i_to_private(a),
      b_ = simde__m512i_to_private(b);

  #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
    r_.i8 = a_.i8 / b_.i8;
  #else
    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.i8) / sizeof(r_.i8[0])) ; i++) {
      r_.i8[i] = a_.i8[i] / b_.i8[i];
    }
  #endif

    return simde__m512i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
#  define _mm512_div_epi8(a, b) simde_mm512_div_epi8((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_div_epi16 (simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_div_epi16(a, b);
  #else
    simde__m512i_private
      r_,
      a_ = simde__m512i_to_private(a),
      b_ = simde__m512i_to_private(b);

  #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
    r_.i16 = a_.i16 / b_.i16;
  #else
    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.i16) / sizeof(r_.i16[0])) ; i++) {
      r_.i16[i] = a_.i16[i] / b_.i16[i];
    }
  #endif

    return simde__m512i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
#  define _mm512_div_epi16(a, b) simde_mm512_div_epi16((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_div_epi32 (simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_div_epi32(a, b);
  #else
    simde__m512i_private
      r_,
      a_ = simde__m512i_to_private(a),
      b_ = simde__m512i_to_private(b);

  #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
    r_.i32 = a_.i32 / b_.i32;
  #else
    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.i32) / sizeof(r_.i32[0])) ; i++) {
      r_.i32[i] = a_.i32[i] / b_.i32[i];
    }
  #endif

    return simde__m512i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
#  define _mm512_div_epi32(a, b) simde_mm512_div_epi32((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_mask_div_epi32(simde__m512i src, simde__mmask16 k, simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_SVML_NATIVE)
    return _mm512_mask_div_epi32(src, k, a, b);
  #else
    return simde_mm512_mask_mov_epi32(src, k, simde_mm512_div_epi32(a, b));
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_div_epi32
  #define _mm512_mask_div_epi32(src, k, a, b) simde_mm512_mask_div_epi32(src, k, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_div_epi64 (simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_div_epi64(a, b);
  #else
    simde__m512i_private
      r_,
      a_ = simde__m512i_to_private(a),
      b_ = simde__m512i_to_private(b);

  #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
    r_.i64 = a_.i64 / b_.i64;
  #else
    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.i64) / sizeof(r_.i64[0])) ; i++) {
      r_.i64[i] = a_.i64[i] / b_.i64[i];
    }
  #endif

    return simde__m512i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
#  define _mm512_div_epi64(a, b) simde_mm512_div_epi64((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_div_epu8 (simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX_NATIVE)
    return _mm512_div_epu8(a, b);
  #else
    simde__m512i_private
      r_,
      a_ = simde__m512i_to_private(a),
      b_ = simde__m512i_to_private(b);

  #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
    r_.u8 = a_.u8 / b_.u8;
  #else
    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.u8) / sizeof(r_.u8[0])) ; i++) {
      r_.u8[i] = a_.u8[i] / b_.u8[i];
    }
  #endif

    return simde__m512i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
#  define _mm512_div_epu8(a, b) simde_mm512_div_epu8((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_div_epu16 (simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX_NATIVE)
    return _mm512_div_epu16(a, b);
  #else
    simde__m512i_private
      r_,
      a_ = simde__m512i_to_private(a),
      b_ = simde__m512i_to_private(b);

  #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
    r_.u16 = a_.u16 / b_.u16;
  #else
    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.u16) / sizeof(r_.u16[0])) ; i++) {
      r_.u16[i] = a_.u16[i] / b_.u16[i];
    }
  #endif

    return simde__m512i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
#  define _mm512_div_epu16(a, b) simde_mm512_div_epu16((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_div_epu32 (simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX_NATIVE)
    return _mm512_div_epu32(a, b);
  #else
    simde__m512i_private
      r_,
      a_ = simde__m512i_to_private(a),
      b_ = simde__m512i_to_private(b);

  #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
    r_.u32 = a_.u32 / b_.u32;
  #else
    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.u32) / sizeof(r_.u32[0])) ; i++) {
      r_.u32[i] = a_.u32[i] / b_.u32[i];
    }
  #endif

    return simde__m512i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
#  define _mm512_div_epu32(a, b) simde_mm512_div_epu32((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_mask_div_epu32(simde__m512i src, simde__mmask16 k, simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_SVML_NATIVE)
    return _mm512_mask_div_epu32(src, k, a, b);
  #else
    return simde_mm512_mask_mov_epi32(src, k, simde_mm512_div_epu32(a, b));
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_div_epu32
  #define _mm512_mask_div_epu32(src, k, a, b) simde_mm512_mask_div_epu32(src, k, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_div_epu64 (simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX_NATIVE)
    return _mm512_div_epu64(a, b);
  #else
    simde__m512i_private
      r_,
      a_ = simde__m512i_to_private(a),
      b_ = simde__m512i_to_private(b);

  #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
    r_.u64 = a_.u64 / b_.u64;
  #else
    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.u64) / sizeof(r_.u64[0])) ; i++) {
      r_.u64[i] = a_.u64[i] / b_.u64[i];
    }
  #endif

    return simde__m512i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
#  define _mm512_div_epu64(a, b) simde_mm512_div_epu64((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_rem_epi8 (simde__m128i a, simde__m128i b) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_rem_epi8(a, b);
  #else
    simde__m128i_private
      r_,
      a_ = simde__m128i_to_private(a),
      b_ = simde__m128i_to_private(b);

  #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
    r_.i8 = a_.i8 % b_.i8;
  #else
    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.i8) / sizeof(r_.i8[0])) ; i++) {
      r_.i8[i] = a_.i8[i] % b_.i8[i];
    }
  #endif

    return simde__m128i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm_rem_epi8
  #define _mm_rem_epi8(a, b) simde_mm_rem_epi8((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_rem_epi16 (simde__m128i a, simde__m128i b) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_rem_epi16(a, b);
  #else
    simde__m128i_private
      r_,
      a_ = simde__m128i_to_private(a),
      b_ = simde__m128i_to_private(b);

  #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
    r_.i16 = a_.i16 % b_.i16;
  #else
    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.i16) / sizeof(r_.i16[0])) ; i++) {
      r_.i16[i] = a_.i16[i] % b_.i16[i];
    }
  #endif

    return simde__m128i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm_rem_epi16
  #define _mm_rem_epi16(a, b) simde_mm_rem_epi16((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_rem_epi32 (simde__m128i a, simde__m128i b) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_rem_epi32(a, b);
  #else
    simde__m128i_private
      r_,
      a_ = simde__m128i_to_private(a),
      b_ = simde__m128i_to_private(b);

  #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
    r_.i32 = a_.i32 % b_.i32;
  #else
    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.i32) / sizeof(r_.i32[0])) ; i++) {
      r_.i32[i] = a_.i32[i] % b_.i32[i];
    }
  #endif

    return simde__m128i_from_private(r_);
  #endif
}
#define simde_mm_irem_epi32(a, b) simde_mm_rem_epi32(a, b)
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm_rem_epi32
  #define _mm_rem_epi32(a, b) simde_mm_rem_epi32(a, b)
  #undef _mm_irem_epi32
  #define _mm_irem_epi32(a, b) simde_mm_rem_epi32(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_idivrem_epi32 (simde__m128i * mem_addr, simde__m128i a, simde__m128i b) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_idivrem_epi32(mem_addr, a, b);
  #else
    simde__m128i r;

    r = simde_mm_div_epi32(a, b);
    *mem_addr = simde_mm_sub_epi32(a, simde_mm_mullo_epi32(r, b));

    return r;
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm_idivrem_epi32
  #define _mm_idivrem_epi32(mem_addr, a, b) simde_mm_idivrem_epi32((mem_addr),(a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_rem_epi64 (simde__m128i a, simde__m128i b) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_rem_epi64(a, b);
  #else
    simde__m128i_private
      r_,
      a_ = simde__m128i_to_private(a),
      b_ = simde__m128i_to_private(b);

  #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
    r_.i64 = a_.i64 % b_.i64;
  #else
    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.i64) / sizeof(r_.i64[0])) ; i++) {
      r_.i64[i] = a_.i64[i] % b_.i64[i];
    }
  #endif

    return simde__m128i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm_rem_epi64
  #define _mm_rem_epi64(a, b) simde_mm_rem_epi64((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_rem_epu8 (simde__m128i a, simde__m128i b) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_rem_epu8(a, b);
  #else
    simde__m128i_private
      r_,
      a_ = simde__m128i_to_private(a),
      b_ = simde__m128i_to_private(b);

    #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r_.u8 = a_.u8 % b_.u8;
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.u8) / sizeof(r_.u8[0])) ; i++) {
        r_.u8[i] = a_.u8[i] % b_.u8[i];
      }
    #endif

    return simde__m128i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm_rem_epu8
  #define _mm_rem_epu8(a, b) simde_mm_rem_epu8((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_rem_epu16 (simde__m128i a, simde__m128i b) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_rem_epu16(a, b);
  #else
    simde__m128i_private
      r_,
      a_ = simde__m128i_to_private(a),
      b_ = simde__m128i_to_private(b);

    #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r_.u16 = a_.u16 % b_.u16;
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.u16) / sizeof(r_.u16[0])) ; i++) {
        r_.u16[i] = a_.u16[i] % b_.u16[i];
      }
    #endif

    return simde__m128i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm_rem_epu16
  #define _mm_rem_epu16(a, b) simde_mm_rem_epu16((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_rem_epu32 (simde__m128i a, simde__m128i b) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_rem_epu32(a, b);
  #else
    simde__m128i_private
      r_,
      a_ = simde__m128i_to_private(a),
      b_ = simde__m128i_to_private(b);

    #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r_.u32 = a_.u32 % b_.u32;
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.u32) / sizeof(r_.u32[0])) ; i++) {
        r_.u32[i] = a_.u32[i] % b_.u32[i];
      }
    #endif

    return simde__m128i_from_private(r_);
  #endif
}
#define simde_mm_urem_epu32(a, b) simde_mm_rem_epu32(a, b)
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm_rem_epu32
  #define _mm_rem_epu32(a, b) simde_mm_rem_epu32(a, b)
  #undef _mm_urem_epu32
  #define _mm_urem_epu32(a, b) simde_mm_rem_epu32(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_udivrem_epi32 (simde__m128i * mem_addr, simde__m128i a, simde__m128i b) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_udivrem_epi32(mem_addr, a, b);
  #else
    simde__m128i r;

    r = simde_mm_div_epu32(a, b);
    *mem_addr = simde_x_mm_sub_epu32(a, simde_x_mm_mullo_epu32(r, b));

    return r;
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm_udivrem_epi32
  #define _mm_udivrem_epi32(mem_addr, a, b) simde_mm_udivrem_epi32((mem_addr),(a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_rem_epu64 (simde__m128i a, simde__m128i b) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_rem_epu64(a, b);
  #else
    simde__m128i_private
      r_,
      a_ = simde__m128i_to_private(a),
      b_ = simde__m128i_to_private(b);

    #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r_.u64 = a_.u64 % b_.u64;
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.u64) / sizeof(r_.u64[0])) ; i++) {
        r_.u64[i] = a_.u64[i] % b_.u64[i];
      }
    #endif

    return simde__m128i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm_rem_epu64
  #define _mm_rem_epu64(a, b) simde_mm_rem_epu64((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_rem_epi8 (simde__m256i a, simde__m256i b) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX_NATIVE)
    return _mm256_rem_epi8(a, b);
  #else
    simde__m256i_private
      r_,
      a_ = simde__m256i_to_private(a),
      b_ = simde__m256i_to_private(b);

    #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r_.i8 = a_.i8 % b_.i8;
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.i8) / sizeof(r_.i8[0])) ; i++) {
        r_.i8[i] = a_.i8[i] % b_.i8[i];
      }
    #endif

    return simde__m256i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm256_rem_epi8
  #define _mm256_rem_epi8(a, b) simde_mm256_rem_epi8((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_rem_epi16 (simde__m256i a, simde__m256i b) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX_NATIVE)
    return _mm256_rem_epi16(a, b);
  #else
    simde__m256i_private
      r_,
      a_ = simde__m256i_to_private(a),
      b_ = simde__m256i_to_private(b);

    #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r_.i16 = a_.i16 % b_.i16;
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.i16) / sizeof(r_.i16[0])) ; i++) {
        r_.i16[i] = a_.i16[i] % b_.i16[i];
      }
    #endif

    return simde__m256i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm256_rem_epi16
  #define _mm256_rem_epi16(a, b) simde_mm256_rem_epi16((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_rem_epi32 (simde__m256i a, simde__m256i b) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX_NATIVE)
    return _mm256_rem_epi32(a, b);
  #else
    simde__m256i_private
      r_,
      a_ = simde__m256i_to_private(a),
      b_ = simde__m256i_to_private(b);

    #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r_.i32 = a_.i32 % b_.i32;
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.i32) / sizeof(r_.i32[0])) ; i++) {
        r_.i32[i] = a_.i32[i] % b_.i32[i];
      }
    #endif

    return simde__m256i_from_private(r_);
  #endif
}
#define simde_mm256_irem_epi32(a, b) simde_mm256_rem_epi32(a, b)
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm256_rem_epi32
  #define _mm256_rem_epi32(a, b) simde_mm256_rem_epi32(a, b)
  #undef _mm256_irem_epi32
  #define _mm256_irem_epi32(a, b) simde_mm256_rem_epi32(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_idivrem_epi32 (simde__m256i * mem_addr, simde__m256i a, simde__m256i b) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_SSE2_NATIVE)
    return _mm256_idivrem_epi32(mem_addr, a, b);
  #else
    simde__m256i r;

    r = simde_mm256_div_epi32(a, b);
    *mem_addr = simde_mm256_sub_epi32(a, simde_mm256_mullo_epi32(r, b));

    return r;
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm256_idivrem_epi32
  #define _mm256_idivrem_epi32(mem_addr, a, b) simde_mm256_idivrem_epi32((mem_addr),(a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_rem_epi64 (simde__m256i a, simde__m256i b) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX_NATIVE)
    return _mm256_rem_epi64(a, b);
  #else
    simde__m256i_private
      r_,
      a_ = simde__m256i_to_private(a),
      b_ = simde__m256i_to_private(b);

    #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r_.i64 = a_.i64 % b_.i64;
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.i64) / sizeof(r_.i64[0])) ; i++) {
        r_.i64[i] = a_.i64[i] % b_.i64[i];
      }
    #endif

    return simde__m256i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm256_rem_epi64
  #define _mm256_rem_epi64(a, b) simde_mm256_rem_epi64((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_rem_epu8 (simde__m256i a, simde__m256i b) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX_NATIVE)
    return _mm256_rem_epu8(a, b);
  #else
    simde__m256i_private
      r_,
      a_ = simde__m256i_to_private(a),
      b_ = simde__m256i_to_private(b);

    #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r_.u8 = a_.u8 % b_.u8;
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.u8) / sizeof(r_.u8[0])) ; i++) {
        r_.u8[i] = a_.u8[i] % b_.u8[i];
      }
    #endif

    return simde__m256i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm256_rem_epu8
  #define _mm256_rem_epu8(a, b) simde_mm256_rem_epu8((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_rem_epu16 (simde__m256i a, simde__m256i b) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX_NATIVE)
    return _mm256_rem_epu16(a, b);
  #else
    simde__m256i_private
      r_,
      a_ = simde__m256i_to_private(a),
      b_ = simde__m256i_to_private(b);

    #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r_.u16 = a_.u16 % b_.u16;
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.u16) / sizeof(r_.u16[0])) ; i++) {
        r_.u16[i] = a_.u16[i] % b_.u16[i];
      }
    #endif

    return simde__m256i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm256_rem_epu16
  #define _mm256_rem_epu16(a, b) simde_mm256_rem_epu16((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_rem_epu32 (simde__m256i a, simde__m256i b) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX_NATIVE)
    return _mm256_rem_epu32(a, b);
  #else
    simde__m256i_private
      r_,
      a_ = simde__m256i_to_private(a),
      b_ = simde__m256i_to_private(b);

    #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r_.u32 = a_.u32 % b_.u32;
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.u32) / sizeof(r_.u32[0])) ; i++) {
        r_.u32[i] = a_.u32[i] % b_.u32[i];
      }
    #endif

    return simde__m256i_from_private(r_);
  #endif
}
#define simde_mm256_urem_epu32(a, b) simde_mm256_rem_epu32(a, b)
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm256_rem_epu32
  #define _mm256_rem_epu32(a, b) simde_mm256_rem_epu32(a, b)
  #undef _mm256_urem_epu32
  #define _mm256_urem_epu32(a, b) simde_mm256_rem_epu32(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_udivrem_epi32 (simde__m256i * mem_addr, simde__m256i a, simde__m256i b) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_SSE2_NATIVE)
    return _mm256_udivrem_epi32(mem_addr, a, b);
  #else
    simde__m256i r;

    r = simde_mm256_div_epu32(a, b);
    *mem_addr = simde_x_mm256_sub_epu32(a, simde_x_mm256_mullo_epu32(r, b));

    return r;
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm256_udivrem_epi32
  #define _mm256_udivrem_epi32(mem_addr, a, b) simde_mm256_udivrem_epi32((mem_addr),(a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_rem_epu64 (simde__m256i a, simde__m256i b) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX_NATIVE)
    return _mm256_rem_epu64(a, b);
  #else
    simde__m256i_private
      r_,
      a_ = simde__m256i_to_private(a),
      b_ = simde__m256i_to_private(b);

    #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r_.u64 = a_.u64 % b_.u64;
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.u64) / sizeof(r_.u64[0])) ; i++) {
        r_.u64[i] = a_.u64[i] % b_.u64[i];
      }
    #endif

    return simde__m256i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm256_rem_epu64
  #define _mm256_rem_epu64(a, b) simde_mm256_rem_epu64((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_rem_epi8 (simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_rem_epi8(a, b);
  #else
    simde__m512i_private
      r_,
      a_ = simde__m512i_to_private(a),
      b_ = simde__m512i_to_private(b);

    #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r_.i8 = a_.i8 % b_.i8;
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.i8) / sizeof(r_.i8[0])) ; i++) {
        r_.i8[i] = a_.i8[i] % b_.i8[i];
      }
    #endif

    return simde__m512i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
#  define _mm512_rem_epi8(a, b) simde_mm512_rem_epi8((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_rem_epi16 (simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_rem_epi16(a, b);
  #else
    simde__m512i_private
      r_,
      a_ = simde__m512i_to_private(a),
      b_ = simde__m512i_to_private(b);

    #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r_.i16 = a_.i16 % b_.i16;
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.i16) / sizeof(r_.i16[0])) ; i++) {
        r_.i16[i] = a_.i16[i] % b_.i16[i];
      }
    #endif

    return simde__m512i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
#  define _mm512_rem_epi16(a, b) simde_mm512_rem_epi16((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_rem_epi32 (simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_rem_epi32(a, b);
  #else
    simde__m512i_private
      r_,
      a_ = simde__m512i_to_private(a),
      b_ = simde__m512i_to_private(b);

    #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r_.i32 = a_.i32 % b_.i32;
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.i32) / sizeof(r_.i32[0])) ; i++) {
        r_.i32[i] = a_.i32[i] % b_.i32[i];
      }
    #endif

    return simde__m512i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
#  define _mm512_rem_epi32(a, b) simde_mm512_rem_epi32((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_mask_rem_epi32(simde__m512i src, simde__mmask16 k, simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_SVML_NATIVE)
    return _mm512_mask_rem_epi32(src, k, a, b);
  #else
    return simde_mm512_mask_mov_epi32(src, k, simde_mm512_rem_epi32(a, b));
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_rem_epi32
  #define _mm512_mask_rem_epi32(src, k, a, b) simde_mm512_mask_rem_epi32(src, k, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_rem_epi64 (simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_rem_epi64(a, b);
  #else
    simde__m512i_private
      r_,
      a_ = simde__m512i_to_private(a),
      b_ = simde__m512i_to_private(b);

    #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r_.i64 = a_.i64 % b_.i64;
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.i64) / sizeof(r_.i64[0])) ; i++) {
        r_.i64[i] = a_.i64[i] % b_.i64[i];
      }
    #endif

    return simde__m512i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
#  define _mm512_rem_epi64(a, b) simde_mm512_rem_epi64((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_rem_epu8 (simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX_NATIVE)
    return _mm512_rem_epu8(a, b);
  #else
    simde__m512i_private
      r_,
      a_ = simde__m512i_to_private(a),
      b_ = simde__m512i_to_private(b);

    #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r_.u8 = a_.u8 % b_.u8;
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.u8) / sizeof(r_.u8[0])) ; i++) {
        r_.u8[i] = a_.u8[i] % b_.u8[i];
      }
    #endif

    return simde__m512i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
#  define _mm512_rem_epu8(a, b) simde_mm512_rem_epu8((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_rem_epu16 (simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX_NATIVE)
    return _mm512_rem_epu16(a, b);
  #else
    simde__m512i_private
      r_,
      a_ = simde__m512i_to_private(a),
      b_ = simde__m512i_to_private(b);

    #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r_.u16 = a_.u16 % b_.u16;
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.u16) / sizeof(r_.u16[0])) ; i++) {
        r_.u16[i] = a_.u16[i] % b_.u16[i];
      }
    #endif

    return simde__m512i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
#  define _mm512_rem_epu16(a, b) simde_mm512_rem_epu16((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_rem_epu32 (simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX_NATIVE)
    return _mm512_rem_epu32(a, b);
  #else
    simde__m512i_private
      r_,
      a_ = simde__m512i_to_private(a),
      b_ = simde__m512i_to_private(b);

    #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r_.u32 = a_.u32 % b_.u32;
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.u32) / sizeof(r_.u32[0])) ; i++) {
        r_.u32[i] = a_.u32[i] % b_.u32[i];
      }
    #endif

    return simde__m512i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
#  define _mm512_rem_epu32(a, b) simde_mm512_rem_epu32((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_mask_rem_epu32(simde__m512i src, simde__mmask16 k, simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_SVML_NATIVE)
    return _mm512_mask_rem_epu32(src, k, a, b);
  #else
    return simde_mm512_mask_mov_epi32(src, k, simde_mm512_rem_epu32(a, b));
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_rem_epu32
  #define _mm512_mask_rem_epu32(src, k, a, b) simde_mm512_mask_rem_epu32(src, k, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_rem_epu64 (simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX_NATIVE)
    return _mm512_rem_epu64(a, b);
  #else
    simde__m512i_private
      r_,
      a_ = simde__m512i_to_private(a),
      b_ = simde__m512i_to_private(b);

    #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r_.u64 = a_.u64 % b_.u64;
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.u64) / sizeof(r_.u64[0])) ; i++) {
        r_.u64[i] = a_.u64[i] % b_.u64[i];
      }
    #endif

    return simde__m512i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
#  define _mm512_rem_epu64(a, b) simde_mm512_rem_epu64((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128
simde_mm_sin_ps (simde__m128 a) {
#if defined(SIMDE_X86_SVML_NATIVE)
  return _mm_sin_ps(a);
#else
  simde__m128_private
    r_,
    a_ = simde__m128_to_private(a);

  SIMDE_VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.f32) / sizeof(r_.f32[0])) ; i++) {
    r_.f32[i] =  simde_math_sinf(a_.f32[i]);
  }

  return simde__m128_from_private(r_);
#endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
#  define _mm_sin_ps(a) simde_mm_sin_ps(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128d
simde_mm_sin_pd (simde__m128d a) {
#if defined(SIMDE_X86_SVML_NATIVE)
  return _mm_sin_pd(a);
#else
  simde__m128d_private
    r_,
    a_ = simde__m128d_to_private(a);

  SIMDE_VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.f64) / sizeof(r_.f64[0])) ; i++) {
    r_.f64[i] =  simde_math_sin(a_.f64[i]);
  }

  return simde__m128d_from_private(r_);
#endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
#  define _mm_sin_pd(a) simde_mm_sin_pd(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256
simde_mm256_sin_ps (simde__m256 a) {
#if defined(SIMDE_X86_SVML_NATIVE)
  return _mm256_sin_ps(a);
#else
  simde__m256_private
    r_,
    a_ = simde__m256_to_private(a);

  SIMDE_VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.f32) / sizeof(r_.f32[0])) ; i++) {
    r_.f32[i] =  simde_math_sinf(a_.f32[i]);
  }

  return simde__m256_from_private(r_);
#endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
#  define _mm256_sin_ps(a) simde_mm256_sin_ps(a)
#endif


SIMDE_FUNCTION_ATTRIBUTES
simde__m256d
simde_mm256_sin_pd (simde__m256d a) {
#if defined(SIMDE_X86_SVML_NATIVE)
  return _mm256_sin_pd(a);
#else
  simde__m256d_private
    r_,
    a_ = simde__m256d_to_private(a);

  SIMDE_VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.f64) / sizeof(r_.f64[0])) ; i++) {
    r_.f64[i] =  simde_math_sin(a_.f64[i]);
  }

  return simde__m256d_from_private(r_);
#endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
#  define _mm256_sin_pd(a) simde_mm256_sin_pd(a)
#endif

SIMDE_END_DECLS_

HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_SVML_H) */
