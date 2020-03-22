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

#if !defined(SIMDE__SVML_H)
#  if !defined(SIMDE__SVML_H)
#    define SIMDE__SVML_H
#  endif
#  include "avx2.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS

#  if defined(SIMDE_SVML_NATIVE)
#    undef SIMDE_SVML_NATIVE
#  endif
#  if defined(__INTEL_COMPILER) && !defined(SIMDE_SVML_NO_NATIVE) && !defined(SIMDE_NO_NATIVE)
#    define SIMDE_SVML_NATIVE
#  elif defined(SIMDE_ARCH_ARM_NEON) && !defined(SIMDE_SVML_NO_NEON) && !defined(SIMDE_NO_NEON)
#    define SIMDE_SVML_NEON
#  elif defined(SIMDE_ARCH_WASM_SIMD128)
#    define SIMDE_SVML_WASM_SIMD128
#  endif

#  if defined(SIMDE_SVML_NATIVE)
#    if defined(SIMDE_ARCH_X86_SSE)
#      define SIMDE_SVML_SSE
#    endif
#    if defined(SIMDE_ARCH_X86_SSE2)
#      define SIMDE_SVML_SSE2
#    endif
#    if defined(SIMDE_ARCH_X86_SSE3)
#      define SIMDE_SVML_SSE3
#    endif
#    if defined(SIMDE_ARCH_X86_SSSE3)
#      define SIMDE_SVML_SSSE3
#    endif
#    if defined(SIMDE_ARCH_X86_SSE4_1)
#      define SIMDE_SVML_SSE4_1
#    endif
#    if defined(SIMDE_ARCH_X86_SSE4_2)
#      define SIMDE_SVML_SSE4_2
#    endif
#    if defined(SIMDE_ARCH_X86_AVX)
#      define SIMDE_SVML_SSE
#    endif
#    if defined(SIMDE_ARCH_X86_AVX2)
#      define SIMDE_SVML_SSE
#    endif
#  else
#    if defined(SIMDE_SVML_NEON)
#      include <arm_neon.h>
#    endif

#    if defined(SIMDE_SVML_WASM_SIMD128)
#      if !defined(__wasm_unimplemented_simd128__)
#        define __wasm_unimplemented_simd128__
#      endif
#      include <wasm_simd128.h>
#    endif

#    if !defined(HEDLEY_INTEL_VERSION) && !defined(HEDLEY_EMSCRIPTEN_VERSION) && defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 201112L) && !defined(__STDC_NO_ATOMICS__)
#      include <stdatomic.h>
#    elif defined(_WIN32)
#      include <windows.h>
#    endif
#  endif

SIMDE__BEGIN_DECLS

SIMDE__FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_div_epi8 (simde__m128i a, simde__m128i b) {
  #if defined(SIMDE_SVML_NATIVE) && defined(SIMDE_SVML_SSE2)
    return _mm_div_epi8(a, b);
  #else
    simde__m128i_private
      r_,
      a_ = simde__m128i_to_private(a),
      b_ = simde__m128i_to_private(b);

  #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
    r_.i8 = a_.i8 / b_.i8;
  #elif defined(SIMDE_SVML_WASM_SIMD128)
    r_.wasm_v128 = wasm_i8x4_div(a_.wasm_v128, b_.wasm_v128);
  #else
    SIMDE__VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.i8) / sizeof(r_.i8[0])) ; i++) {
      r_.i8[i] = a_.i8[i] / b_.i8[i];
    }
  #endif

    return simde__m128i_from_private(r_);
  #endif
}
#if defined(SIMDE_SVML_ENABLE_NATIVE_ALIASES)
#  define _mm_div_epi8(a, b) simde_mm_div_epi8((a), (b))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_div_epi16 (simde__m128i a, simde__m128i b) {
  #if defined(SIMDE_SVML_NATIVE) && defined(SIMDE_SVML_SSE2)
    return _mm_div_epi16(a, b);
  #else
    simde__m128i_private
      r_,
      a_ = simde__m128i_to_private(a),
      b_ = simde__m128i_to_private(b);

  #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
    r_.i16 = a_.i16 / b_.i16;
  #elif defined(SIMDE_SVML_WASM_SIMD128)
    r_.wasm_v128 = wasm_i16x4_div(a_.wasm_v128, b_.wasm_v128);
  #else
    SIMDE__VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.i16) / sizeof(r_.i16[0])) ; i++) {
      r_.i16[i] = a_.i16[i] / b_.i16[i];
    }
  #endif

    return simde__m128i_from_private(r_);
  #endif
}
#if defined(SIMDE_SVML_ENABLE_NATIVE_ALIASES)
#  define _mm_div_epi16(a, b) simde_mm_div_epi16((a), (b))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_div_epi32 (simde__m128i a, simde__m128i b) {
  #if defined(SIMDE_SVML_NATIVE) && defined(SIMDE_SVML_SSE2)
    return _mm_div_epi32(a, b);
  #else
    simde__m128i_private
      r_,
      a_ = simde__m128i_to_private(a),
      b_ = simde__m128i_to_private(b);

  #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
    r_.i32 = a_.i32 / b_.i32;
  #elif defined(SIMDE_SVML_WASM_SIMD128)
    r_.wasm_v128 = wasm_i32x4_div(a_.wasm_v128, b_.wasm_v128);
  #else
    SIMDE__VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.i32) / sizeof(r_.i32[0])) ; i++) {
      r_.i32[i] = a_.i32[i] / b_.i32[i];
    }
  #endif

    return simde__m128i_from_private(r_);
  #endif
}
#if defined(SIMDE_SVML_ENABLE_NATIVE_ALIASES)
#  define _mm_div_epi32(a, b) simde_mm_div_epi32((a), (b))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_div_epi64 (simde__m128i a, simde__m128i b) {
  #if defined(SIMDE_SVML_NATIVE) && defined(SIMDE_SVML_SSE2)
    return _mm_div_epi64(a, b);
  #else
    simde__m128i_private
      r_,
      a_ = simde__m128i_to_private(a),
      b_ = simde__m128i_to_private(b);

  #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
    r_.i64 = a_.i64 / b_.i64;
  #elif defined(SIMDE_SVML_WASM_SIMD128)
    r_.wasm_v128 = wasm_i64x4_div(a_.wasm_v128, b_.wasm_v128);
  #else
    SIMDE__VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.i64) / sizeof(r_.i64[0])) ; i++) {
      r_.i64[i] = a_.i64[i] / b_.i64[i];
    }
  #endif

    return simde__m128i_from_private(r_);
  #endif
}
#if defined(SIMDE_SVML_ENABLE_NATIVE_ALIASES)
#  define _mm_div_epi64(a, b) simde_mm_div_epi64((a), (b))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_div_epu8 (simde__m128i a, simde__m128i b) {
  #if defined(SIMDE_SVML_NATIVE) && defined(SIMDE_SVML_SSE2)
    return _mm_div_epu8(a, b);
  #else
    simde__m128i_private
      r_,
      a_ = simde__m128i_to_private(a),
      b_ = simde__m128i_to_private(b);

  #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
    r_.u8 = a_.u8 / b_.u8;
  #elif defined(SIMDE_SVML_WASM_SIMD128)
    r_.wasm_v128 =  wasm_u8x16_div(a_.wasm_v128, b_.wasm_v128);
  #else
    SIMDE__VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.u8) / sizeof(r_.u8[0])) ; i++) {
      r_.u8[i] = a_.u8[i] / b_.u8[i];
    }
  #endif

    return simde__m128i_from_private(r_);
  #endif
}
#if defined(SIMDE_SVML_ENABLE_NATIVE_ALIASES)
#  define _mm_div_epu8(a, b) simde_mm_div_epu8((a), (b))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_div_epu16 (simde__m128i a, simde__m128i b) {
  #if defined(SIMDE_SVML_NATIVE) && defined(SIMDE_SVML_SSE2)
    return _mm_div_epu16(a, b);
  #else
    simde__m128i_private
      r_,
      a_ = simde__m128i_to_private(a),
      b_ = simde__m128i_to_private(b);

  #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
    r_.u16 = a_.u16 / b_.u16;
  #elif defined(SIMDE_SVML_WASM_SIMD128)
    r_.wasm_v128 =  wasm_u16x16_div(a_.wasm_v128, b_.wasm_v128);
  #else
    SIMDE__VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.u16) / sizeof(r_.u16[0])) ; i++) {
      r_.u16[i] = a_.u16[i] / b_.u16[i];
    }
  #endif

    return simde__m128i_from_private(r_);
  #endif
}
#if defined(SIMDE_SVML_ENABLE_NATIVE_ALIASES)
#  define _mm_div_epu16(a, b) simde_mm_div_epu16((a), (b))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_div_epu32 (simde__m128i a, simde__m128i b) {
  #if defined(SIMDE_SVML_NATIVE) && defined(SIMDE_SVML_SSE2)
    return _mm_div_epu32(a, b);
  #else
    simde__m128i_private
      r_,
      a_ = simde__m128i_to_private(a),
      b_ = simde__m128i_to_private(b);

  #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
    r_.u32 = a_.u32 / b_.u32;
  #elif defined(SIMDE_SVML_WASM_SIMD128)
    r_.wasm_v128 =  wasm_u32x16_div(a_.wasm_v128, b_.wasm_v128);
  #else
    SIMDE__VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.u32) / sizeof(r_.u32[0])) ; i++) {
      r_.u32[i] = a_.u32[i] / b_.u32[i];
    }
  #endif

    return simde__m128i_from_private(r_);
  #endif
}
#if defined(SIMDE_SVML_ENABLE_NATIVE_ALIASES)
#  define _mm_div_epu32(a, b) simde_mm_div_epu32((a), (b))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_div_epu64 (simde__m128i a, simde__m128i b) {
  #if defined(SIMDE_SVML_NATIVE) && defined(SIMDE_SVML_SSE2)
    return _mm_div_epu64(a, b);
  #else
    simde__m128i_private
      r_,
      a_ = simde__m128i_to_private(a),
      b_ = simde__m128i_to_private(b);

  #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
    r_.u64 = a_.u64 / b_.u64;
  #elif defined(SIMDE_SVML_WASM_SIMD128)
    r_.wasm_v128 =  wasm_u64x16_div(a_.wasm_v128, b_.wasm_v128);
  #else
    SIMDE__VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.u64) / sizeof(r_.u64[0])) ; i++) {
      r_.u64[i] = a_.u64[i] / b_.u64[i];
    }
  #endif

    return simde__m128i_from_private(r_);
  #endif
}
#if defined(SIMDE_SVML_ENABLE_NATIVE_ALIASES)
#  define _mm_div_epu64(a, b) simde_mm_div_epu64((a), (b))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_div_epi8 (simde__m256i a, simde__m256i b) {
  #if defined(SIMDE_SVML_NATIVE) && defined(SIMDE_SVML_AVX)
    return _mm256_div_epi32(a, b);
  #else
    simde__m256i_private
      r_,
      a_ = simde__m256i_to_private(a),
      b_ = simde__m256i_to_private(b);

  #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
    r_.i8 = a_.i8 / b_.i8;
  #else
    SIMDE__VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.i8) / sizeof(r_.i8[0])) ; i++) {
      r_.i8[i] = a_.i8[i] / b_.i8[i];
    }
  #endif

    return simde__m256i_from_private(r_);
  #endif
}
#if defined(SIMDE_SVML_ENABLE_NATIVE_ALIASES)
#  define _mm256_div_epi8(a, b) simde_mm256_div_epi8((a), (b))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_div_epi16 (simde__m256i a, simde__m256i b) {
  #if defined(SIMDE_SVML_NATIVE) && defined(SIMDE_SVML_AVX)
    return _mm256_div_epi16(a, b);
  #else
    simde__m256i_private
      r_,
      a_ = simde__m256i_to_private(a),
      b_ = simde__m256i_to_private(b);

  #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
    r_.i16 = a_.i16 / b_.i16;
  #else
    SIMDE__VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.i16) / sizeof(r_.i16[0])) ; i++) {
      r_.i16[i] = a_.i16[i] / b_.i16[i];
    }
  #endif

    return simde__m256i_from_private(r_);
  #endif
}
#if defined(SIMDE_SVML_ENABLE_NATIVE_ALIASES)
#  define _mm256_div_epi16(a, b) simde_mm256_div_epi16((a), (b))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_div_epi32 (simde__m256i a, simde__m256i b) {
  #if defined(SIMDE_SVML_NATIVE) && defined(SIMDE_SVML_AVX)
    return _mm256_div_epi32(a, b);
  #else
    simde__m256i_private
      r_,
      a_ = simde__m256i_to_private(a),
      b_ = simde__m256i_to_private(b);

  #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
    r_.i32 = a_.i32 / b_.i32;
  #else
    SIMDE__VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.i32) / sizeof(r_.i32[0])) ; i++) {
      r_.i32[i] = a_.i32[i] / b_.i32[i];
    }
  #endif

    return simde__m256i_from_private(r_);
  #endif
}
#if defined(SIMDE_SVML_ENABLE_NATIVE_ALIASES)
#  define _mm256_div_epi32(a, b) simde_mm256_div_epi32((a), (b))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_div_epi64 (simde__m256i a, simde__m256i b) {
  #if defined(SIMDE_SVML_NATIVE) && defined(SIMDE_SVML_AVX)
    return _mm256_div_epi64(a, b);
  #else
    simde__m256i_private
      r_,
      a_ = simde__m256i_to_private(a),
      b_ = simde__m256i_to_private(b);

  #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
    r_.i64 = a_.i64 / b_.i64;
  #else
    SIMDE__VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.i64) / sizeof(r_.i64[0])) ; i++) {
      r_.i64[i] = a_.i64[i] / b_.i64[i];
    }
  #endif

    return simde__m256i_from_private(r_);
  #endif
}
#if defined(SIMDE_SVML_ENABLE_NATIVE_ALIASES)
#  define _mm256_div_epi64(a, b) simde_mm256_div_epi64((a), (b))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_div_epu8 (simde__m256i a, simde__m256i b) {
  #if defined(SIMDE_SVML_NATIVE) && defined(SIMDE_SVML_AVX)
    return _mm256_div_epi32(a, b);
  #else
    simde__m256i_private
      r_,
      a_ = simde__m256i_to_private(a),
      b_ = simde__m256i_to_private(b);

  #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
    r_.u8 = a_.u8 / b_.u8;
  #else
    SIMDE__VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.u8) / sizeof(r_.u8[0])) ; i++) {
      r_.u8[i] = a_.u8[i] / b_.u8[i];
    }
  #endif

    return simde__m256i_from_private(r_);
  #endif
}
#if defined(SIMDE_SVML_ENABLE_NATIVE_ALIASES)
#  define _mm256_div_epu8(a, b) simde_mm256_div_epu8((a), (b))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_div_epu16 (simde__m256i a, simde__m256i b) {
  #if defined(SIMDE_SVML_NATIVE) && defined(SIMDE_SVML_AVX)
    return _mm256_div_epi16(a, b);
  #else
    simde__m256i_private
      r_,
      a_ = simde__m256i_to_private(a),
      b_ = simde__m256i_to_private(b);

  #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
    r_.u16 = a_.u16 / b_.u16;
  #else
    SIMDE__VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.u16) / sizeof(r_.u16[0])) ; i++) {
      r_.u16[i] = a_.u16[i] / b_.u16[i];
    }
  #endif

    return simde__m256i_from_private(r_);
  #endif
}
#if defined(SIMDE_SVML_ENABLE_NATIVE_ALIASES)
#  define _mm256_div_epu16(a, b) simde_mm256_div_epu16((a), (b))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_div_epu32 (simde__m256i a, simde__m256i b) {
  #if defined(SIMDE_SVML_NATIVE) && defined(SIMDE_SVML_AVX)
    return _mm256_div_epi32(a, b);
  #else
    simde__m256i_private
      r_,
      a_ = simde__m256i_to_private(a),
      b_ = simde__m256i_to_private(b);

  #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
    r_.u32 = a_.u32 / b_.u32;
  #else
    SIMDE__VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.u32) / sizeof(r_.u32[0])) ; i++) {
      r_.u32[i] = a_.u32[i] / b_.u32[i];
    }
  #endif

    return simde__m256i_from_private(r_);
  #endif
}
#if defined(SIMDE_SVML_ENABLE_NATIVE_ALIASES)
#  define _mm256_div_epu32(a, b) simde_mm256_div_epu32((a), (b))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_div_epu64 (simde__m256i a, simde__m256i b) {
  #if defined(SIMDE_SVML_NATIVE) && defined(SIMDE_SVML_AVX)
    return _mm256_div_epi64(a, b);
  #else
    simde__m256i_private
      r_,
      a_ = simde__m256i_to_private(a),
      b_ = simde__m256i_to_private(b);

  #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
    r_.u64 = a_.u64 / b_.u64;
  #else
    SIMDE__VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.u64) / sizeof(r_.u64[0])) ; i++) {
      r_.u64[i] = a_.u64[i] / b_.u64[i];
    }
  #endif

    return simde__m256i_from_private(r_);
  #endif
}
#if defined(SIMDE_SVML_ENABLE_NATIVE_ALIASES)
#  define _mm256_div_epu64(a, b) simde_mm256_div_epu64((a), (b))
#endif

SIMDE__END_DECLS

HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE__SVML_H) */
