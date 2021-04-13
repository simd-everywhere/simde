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
 *   2021      Evan Nemerson <evan@nemerson.com>
 */

#if !defined(SIMDE_ARM_SVE_ADD_H)
#define SIMDE_ARM_SVE_ADD_H

#include "types.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS

SIMDE_FUNCTION_ATTRIBUTES
simde_svint8_t
simde_svadd_s8_z(simde_svbool_t pg, simde_svint8_t op1, simde_svint8_t op2) {
  #if defined(SIMDE_ARM_SVE_NATIVE)
    return svadd_s8_z(pg, op1, op2);
  #else
    simde_svint8_t r;

    #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
      r.neon = vandq_s8(pg.neon_i8, vaddq_s8(op1.neon, op2.neon));
    #elif defined(SIMDE_X86_AVX512BW_NATIVE) && (SIMDE_ARM_SVE_VECTOR_SIZE >= 512)
      r.m512i = _mm512_maskz_add_epi8(simde_svbool_to_mmask64(pg), op1.m512i, op2.m512i);
    #elif defined(SIMDE_X86_AVX512BW_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
      r.m256i[0] = _mm256_maskz_add_epi8(simde_svbool_to_mmask32(pg), op1.m256i[0], op2.m256i[0]);
    #elif defined(SIMDE_X86_AVX2_NATIVE)
      for (int i = 0 ; i < HEDLEY_STATIC_CAST(int, sizeof(r.m256i) / sizeof(r.m256i[0])) ; i++) {
        r.m256i[i] = _mm256_and_si256(pg.m256i[i], _mm256_add_epi8(op1.m256i[i], op2.m256i[i]));
      }
    #elif defined(SIMDE_X86_SSE2_NATIVE)
      for (int i = 0 ; i < HEDLEY_STATIC_CAST(int, sizeof(r.m128i) / sizeof(r.m128i[0])) ; i++) {
        r.m128i[i] = _mm_and_si128(pg.m128i[i], _mm_add_epi8(op1.m128i[i], op2.m128i[i]));
      }
    #elif defined(SIMDE_POWER_ALTIVEC_P6_NATIVE)
      r.altivec = vec_and(pg.altivec_b8, vec_add(op1.altivec, op2.altivec));
    #elif defined(SIMDE_ZARCH_ZVECTOR_13_NATIVE)
      r.altivec = pg.values & (op1.altivec + op2.altivec);
    #elif defined(SIMDE_WASM_SIMD128_NATIVE)
      r.v128 = wasm_v128_and(pg.v128, wasm_i8x16_add(op1.v128, op2.v128));
    #elif defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r.values = pg.values_i8 & (op1.values + op2.values);
    #else
      SIMDE_VECTORIZE
      for (int i = 0 ; i < HEDLEY_STATIC_CAST(int, sizeof(r.values) / sizeof(r.values[0])) ; i++) {
        r.values[i] = pg.values_i8[i] & (op1.values[i] + op2.values[i]);
      }
    #endif

    return r;
  #endif
}
#if defined(SIMDE_ARM_SVE_ENABLE_NATIVE_ALIASES)
  #undef simde_svadd_s8_z
  #define svadd_s8_z(pg, op1, op2) simde_svadd_s8_z(pg, op1, op2)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_svint8_t
simde_svadd_s8_m(simde_svbool_t pg, simde_svint8_t op1, simde_svint8_t op2) {
  #if defined(SIMDE_ARM_SVE_NATIVE)
    return svadd_s8_m(pg, op1, op2);
  #else
    simde_svint8_t r;

    #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
      r.neon = vaddq_s8(op1.neon, vandq_s8(pg.neon_i8, op2.neon));
    #elif defined(SIMDE_X86_AVX512BW_NATIVE) && (SIMDE_ARM_SVE_VECTOR_SIZE >= 512)
      r.m512i = _mm512_mask_add_epi8(op1.m512i, simde_svbool_to_mmask64(pg), op1.m512i, op2.m512i);
    #elif defined(SIMDE_X86_AVX512BW_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
      r.m256i[0] = _mm256_mask_add_epi8(op1.m256i[0], simde_svbool_to_mmask32(pg), op1.m256i[0], op2.m256i[0]);
    #elif defined(SIMDE_X86_AVX2_NATIVE)
      for (int i = 0 ; i < HEDLEY_STATIC_CAST(int, sizeof(r.m256i) / sizeof(r.m256i[0])) ; i++) {
        r.m256i[i] = _mm256_add_epi8(op1.m256i[i], _mm256_and_si256(pg.m256i[i], op2.m256i[i]));
      }
    #elif defined(SIMDE_X86_SSE2_NATIVE)
      for (int i = 0 ; i < HEDLEY_STATIC_CAST(int, sizeof(r.m128i) / sizeof(r.m128i[0])) ; i++) {
        r.m128i[i] = _mm_add_epi8(op1.m128i[i], _mm_and_si128(pg.m128i[i], op2.m128i[i]));
      }
    #elif defined(SIMDE_POWER_ALTIVEC_P6_NATIVE)
      r.altivec = vec_add(op1.altivec, vec_and(pg.altivec_b8, op2.altivec));
    #elif defined(SIMDE_ZARCH_ZVECTOR_13_NATIVE)
      r.altivec = op1.altivec + (pg.values & op2.altivec);
    #elif defined(SIMDE_WASM_SIMD128_NATIVE)
      r.v128 = wasm_i8x16_add(op1.v128, wasm_v128_and(pg.v128, op2.v128));
    #elif defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r.values = op1.values + (pg.values_i8 & op2.values);
    #else
      SIMDE_VECTORIZE
      for (int i = 0 ; i < HEDLEY_STATIC_CAST(int, sizeof(r.values) / sizeof(r.values[0])) ; i++) {
        r.values[i] = op1.values[i] + (pg.values_i8[i] & op2.values[i]);
      }
    #endif

    return r;
  #endif
}
#if defined(SIMDE_ARM_SVE_ENABLE_NATIVE_ALIASES)
  #undef simde_svadd_s8_m
  #define svadd_s8_m(pg, op1, op2) simde_svadd_s8_m(pg, op1, op2)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_svint16_t
simde_svadd_s16_z(simde_svbool_t pg, simde_svint16_t op1, simde_svint16_t op2) {
  #if defined(SIMDE_ARM_SVE_NATIVE)
    return svadd_s16_z(pg, op1, op2);
  #else
    simde_svint16_t r;

    #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
      r.neon = vandq_s16(pg.neon_i16, vaddq_s16(op1.neon, op2.neon));
    #elif defined(SIMDE_X86_AVX512BW_NATIVE) && (SIMDE_ARM_SVE_VECTOR_SIZE >= 512)
      r.m512i = _mm512_maskz_add_epi16(simde_svbool_to_mmask32(pg), op1.m512i, op2.m512i);
    #elif defined(SIMDE_X86_AVX512BW_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
      r.m256i[0] = _mm256_maskz_add_epi16(simde_svbool_to_mmask16(pg), op1.m256i[0], op2.m256i[0]);
    #elif defined(SIMDE_X86_AVX2_NATIVE)
      for (int i = 0 ; i < HEDLEY_STATIC_CAST(int, sizeof(r.m256i) / sizeof(r.m256i[0])) ; i++) {
        r.m256i[i] = _mm256_and_si256(pg.m256i[i], _mm256_add_epi16(op1.m256i[i], op2.m256i[i]));
      }
    #elif defined(SIMDE_X86_SSE2_NATIVE)
      for (int i = 0 ; i < HEDLEY_STATIC_CAST(int, sizeof(r.m128i) / sizeof(r.m128i[0])) ; i++) {
        r.m128i[i] = _mm_and_si128(pg.m128i[i], _mm_add_epi16(op1.m128i[i], op2.m128i[i]));
      }
    #elif defined(SIMDE_POWER_ALTIVEC_P6_NATIVE)
      r.altivec = vec_and(pg.altivec_b16, vec_add(op1.altivec, op2.altivec));
    #elif defined(SIMDE_ZARCH_ZVECTOR_13_NATIVE)
      r.altivec = pg.values & (op1.altivec + op2.altivec);
    #elif defined(SIMDE_WASM_SIMD128_NATIVE)
      r.v128 = wasm_v128_and(pg.v128, wasm_i16x8_add(op1.v128, op2.v128));
    #elif defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r.values = pg.values_i16 & (op1.values + op2.values);
    #else
      SIMDE_VECTORIZE
      for (int i = 0 ; i < HEDLEY_STATIC_CAST(int, sizeof(r.values) / sizeof(r.values[0])) ; i++) {
        r.values[i] = pg.values_i16[i] & (op1.values[i] + op2.values[i]);
      }
    #endif

    return r;
  #endif
}
#if defined(SIMDE_ARM_SVE_ENABLE_NATIVE_ALIASES)
  #undef simde_svadd_s16_z
  #define svadd_s16_z(pg, op1, op2) simde_svadd_s16_z(pg, op1, op2)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_svint16_t
simde_svadd_s16_m(simde_svbool_t pg, simde_svint16_t op1, simde_svint16_t op2) {
  #if defined(SIMDE_ARM_SVE_NATIVE)
    return svadd_s16_m(pg, op1, op2);
  #else
    simde_svint16_t r;

    #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
      r.neon = vaddq_s16(op1.neon, vandq_s16(pg.neon_i16, op2.neon));
    #elif defined(SIMDE_X86_AVX512BW_NATIVE) && (SIMDE_ARM_SVE_VECTOR_SIZE >= 512)
      r.m512i = _mm512_mask_add_epi16(op1.m512i, simde_svbool_to_mmask32(pg), op1.m512i, op2.m512i);
    #elif defined(SIMDE_X86_AVX512BW_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
      r.m256i[0] = _mm256_mask_add_epi16(op1.m256i[0], simde_svbool_to_mmask16(pg), op1.m256i[0], op2.m256i[0]);
    #elif defined(SIMDE_X86_AVX2_NATIVE)
      for (int i = 0 ; i < HEDLEY_STATIC_CAST(int, sizeof(r.m256i) / sizeof(r.m256i[0])) ; i++) {
        r.m256i[i] = _mm256_add_epi16(op1.m256i[i], _mm256_and_si256(pg.m256i[i], op2.m256i[i]));
      }
    #elif defined(SIMDE_X86_SSE2_NATIVE)
      for (int i = 0 ; i < HEDLEY_STATIC_CAST(int, sizeof(r.m128i) / sizeof(r.m128i[0])) ; i++) {
        r.m128i[i] = _mm_add_epi16(op1.m128i[i], _mm_and_si128(pg.m128i[i], op2.m128i[i]));
      }
    #elif defined(SIMDE_POWER_ALTIVEC_P6_NATIVE)
      r.altivec = vec_add(op1.altivec, vec_and(pg.altivec_b16, op2.altivec));
    #elif defined(SIMDE_ZARCH_ZVECTOR_13_NATIVE)
      r.altivec = op1.altivec + (pg.values_i16 & op2.altivec);
    #elif defined(SIMDE_WASM_SIMD128_NATIVE)
      r.v128 = wasm_i16x8_add(op1.v128, wasm_v128_and(pg.v128, op2.v128));
    #elif defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r.values = op1.values + (pg.values_i16 & op2.values);
    #else
      SIMDE_VECTORIZE
      for (int i = 0 ; i < HEDLEY_STATIC_CAST(int, sizeof(r.values) / sizeof(r.values[0])) ; i++) {
        r.values[i] = op1.values[i] + (pg.values_i16[i] & op2.values[i]);
      }
    #endif

    return r;
  #endif
}
#if defined(SIMDE_ARM_SVE_ENABLE_NATIVE_ALIASES)
  #undef simde_svadd_s16_m
  #define svadd_s16_m(pg, op1, op2) simde_svadd_s16_m(pg, op1, op2)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_svint32_t
simde_svadd_s32_z(simde_svbool_t pg, simde_svint32_t op1, simde_svint32_t op2) {
  #if defined(SIMDE_ARM_SVE_NATIVE)
    return svadd_s32_z(pg, op1, op2);
  #else
    simde_svint32_t r;

    #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
      r.neon = vandq_s32(pg.neon_i32, vaddq_s32(op1.neon, op2.neon));
    #elif defined(SIMDE_X86_AVX512BW_NATIVE) && (SIMDE_ARM_SVE_VECTOR_SIZE >= 512)
      r.m512i = _mm512_maskz_add_epi32(simde_svbool_to_mmask16(pg), op1.m512i, op2.m512i);
    #elif defined(SIMDE_X86_AVX512BW_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
      r.m256i[0] = _mm256_maskz_add_epi32(simde_svbool_to_mmask8(pg), op1.m256i[0], op2.m256i[0]);
    #elif defined(SIMDE_X86_AVX2_NATIVE)
      for (int i = 0 ; i < HEDLEY_STATIC_CAST(int, sizeof(r.m256i) / sizeof(r.m256i[0])) ; i++) {
        r.m256i[i] = _mm256_and_si256(pg.m256i[i], _mm256_add_epi32(op1.m256i[i], op2.m256i[i]));
      }
    #elif defined(SIMDE_X86_SSE2_NATIVE)
      for (int i = 0 ; i < HEDLEY_STATIC_CAST(int, sizeof(r.m128i) / sizeof(r.m128i[0])) ; i++) {
        r.m128i[i] = _mm_and_si128(pg.m128i[i], _mm_add_epi32(op1.m128i[i], op2.m128i[i]));
      }
    #elif defined(SIMDE_POWER_ALTIVEC_P6_NATIVE)
      r.altivec = vec_and(pg.altivec_b32, vec_add(op1.altivec, op2.altivec));
    #elif defined(SIMDE_ZARCH_ZVECTOR_13_NATIVE)
      r.altivec = pg.values & (op1.altivec + op2.altivec);
    #elif defined(SIMDE_WASM_SIMD128_NATIVE)
      r.v128 = wasm_v128_and(pg.v128, wasm_i32x4_add(op1.v128, op2.v128));
    #elif defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r.values = pg.values_i32 & (op1.values + op2.values);
    #else
      SIMDE_VECTORIZE
      for (int i = 0 ; i < HEDLEY_STATIC_CAST(int, sizeof(r.values) / sizeof(r.values[0])) ; i++) {
        r.values[i] = pg.values_i32[i] & (op1.values[i] + op2.values[i]);
      }
    #endif

    return r;
  #endif
}
#if defined(SIMDE_ARM_SVE_ENABLE_NATIVE_ALIASES)
  #undef simde_svadd_s32_z
  #define svadd_s32_z(pg, op1, op2) simde_svadd_s32_z(pg, op1, op2)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_svint32_t
simde_svadd_s32_m(simde_svbool_t pg, simde_svint32_t op1, simde_svint32_t op2) {
  #if defined(SIMDE_ARM_SVE_NATIVE)
    return svadd_s32_m(pg, op1, op2);
  #else
    simde_svint32_t r;

    #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
      r.neon = vaddq_s32(op1.neon, vandq_s32(pg.neon_i32, op2.neon));
    #elif defined(SIMDE_X86_AVX512BW_NATIVE) && (SIMDE_ARM_SVE_VECTOR_SIZE >= 512)
      r.m512i = _mm512_mask_add_epi32(op1.m512i, simde_svbool_to_mmask16(pg), op1.m512i, op2.m512i);
    #elif defined(SIMDE_X86_AVX512BW_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
      r.m256i[0] = _mm256_mask_add_epi32(op1.m256i[0], simde_svbool_to_mmask8(pg), op1.m256i[0], op2.m256i[0]);
    #elif defined(SIMDE_X86_AVX2_NATIVE)
      for (int i = 0 ; i < HEDLEY_STATIC_CAST(int, sizeof(r.m256i) / sizeof(r.m256i[0])) ; i++) {
        r.m256i[i] = _mm256_add_epi32(op1.m256i[i], _mm256_and_si256(pg.m256i[i], op2.m256i[i]));
      }
    #elif defined(SIMDE_X86_SSE2_NATIVE)
      for (int i = 0 ; i < HEDLEY_STATIC_CAST(int, sizeof(r.m128i) / sizeof(r.m128i[0])) ; i++) {
        r.m128i[i] = _mm_add_epi32(op1.m128i[i], _mm_and_si128(pg.m128i[i], op2.m128i[i]));
      }
    #elif defined(SIMDE_POWER_ALTIVEC_P6_NATIVE)
      r.altivec = vec_add(op1.altivec, vec_and(pg.altivec_b32, op2.altivec));
    #elif defined(SIMDE_ZARCH_ZVECTOR_13_NATIVE)
      r.altivec = op1.altivec + (pg.values & op2.altivec);
    #elif defined(SIMDE_WASM_SIMD128_NATIVE)
      r.v128 = wasm_i32x4_add(op1.v128, wasm_v128_and(pg.v128, op2.v128));
    #elif defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r.values = op1.values + (pg.values_i32 & op2.values);
    #else
      SIMDE_VECTORIZE
      for (int i = 0 ; i < HEDLEY_STATIC_CAST(int, sizeof(r.values) / sizeof(r.values[0])) ; i++) {
        r.values[i] = op1.values[i] + (pg.values_i32[i] & op2.values[i]);
      }
    #endif

    return r;
  #endif
}
#if defined(SIMDE_ARM_SVE_ENABLE_NATIVE_ALIASES)
  #undef simde_svadd_s32_m
  #define svadd_s32_m(pg, op1, op2) simde_svadd_s32_m(pg, op1, op2)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_svint64_t
simde_svadd_s64_z(simde_svbool_t pg, simde_svint64_t op1, simde_svint64_t op2) {
  #if defined(SIMDE_ARM_SVE_NATIVE)
    return svadd_s64_z(pg, op1, op2);
  #else
    simde_svint64_t r;

    #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
      r.neon = vandq_s64(pg.neon_i64, vaddq_s64(op1.neon, op2.neon));
    #elif defined(SIMDE_X86_AVX512BW_NATIVE) && (SIMDE_ARM_SVE_VECTOR_SIZE >= 512)
      r.m512i = _mm512_maskz_add_epi64(simde_svbool_to_mmask8(pg), op1.m512i, op2.m512i);
    #elif defined(SIMDE_X86_AVX512BW_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
      r.m256i[0] = _mm256_maskz_add_epi64(simde_svbool_to_mmask8(pg), op1.m256i[0], op2.m256i[0]);
    #elif defined(SIMDE_X86_AVX2_NATIVE)
      for (int i = 0 ; i < HEDLEY_STATIC_CAST(int, sizeof(r.m256i) / sizeof(r.m256i[0])) ; i++) {
        r.m256i[i] = _mm256_and_si256(pg.m256i[i], _mm256_add_epi64(op1.m256i[i], op2.m256i[i]));
      }
    #elif defined(SIMDE_X86_SSE2_NATIVE)
      for (int i = 0 ; i < HEDLEY_STATIC_CAST(int, sizeof(r.m128i) / sizeof(r.m128i[0])) ; i++) {
        r.m128i[i] = _mm_and_si128(pg.m128i[i], _mm_add_epi64(op1.m128i[i], op2.m128i[i]));
      }
    #elif defined(SIMDE_POWER_ALTIVEC_P8_NATIVE)
      r.altivec = vec_and(pg.altivec_b64, vec_add(op1.altivec, op2.altivec));
    #elif defined(SIMDE_ZARCH_ZVECTOR_13_NATIVE)
      r.altivec = pg.values & (op1.altivec + op2.altivec);
    #elif defined(SIMDE_WASM_SIMD128_NATIVE)
      r.v128 = wasm_v128_and(pg.v128, wasm_i64x2_add(op1.v128, op2.v128));
    #elif defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r.values = pg.values_i64 & (op1.values + op2.values);
    #else
      SIMDE_VECTORIZE
      for (int i = 0 ; i < HEDLEY_STATIC_CAST(int, sizeof(r.values) / sizeof(r.values[0])) ; i++) {
        r.values[i] = pg.values_i64[i] & (op1.values[i] + op2.values[i]);
      }
    #endif

    return r;
  #endif
}
#if defined(SIMDE_ARM_SVE_ENABLE_NATIVE_ALIASES)
  #undef simde_svadd_s64_z
  #define svadd_s64_z(pg, op1, op2) simde_svadd_s64_z(pg, op1, op2)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_svint64_t
simde_svadd_s64_m(simde_svbool_t pg, simde_svint64_t op1, simde_svint64_t op2) {
  #if defined(SIMDE_ARM_SVE_NATIVE)
    return svadd_s64_m(pg, op1, op2);
  #else
    simde_svint64_t r;

    #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
      r.neon = vaddq_s64(op1.neon, vandq_s64(pg.neon_i64, op2.neon));
    #elif defined(SIMDE_X86_AVX512BW_NATIVE) && (SIMDE_ARM_SVE_VECTOR_SIZE >= 512)
      r.m512i = _mm512_mask_add_epi64(op1.m512i, simde_svbool_to_mmask8(pg), op1.m512i, op2.m512i);
    #elif defined(SIMDE_X86_AVX512BW_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
      r.m256i[0] = _mm256_mask_add_epi64(op1.m256i[0], simde_svbool_to_mmask8(pg), op1.m256i[0], op2.m256i[0]);
    #elif defined(SIMDE_X86_AVX2_NATIVE)
      for (int i = 0 ; i < HEDLEY_STATIC_CAST(int, sizeof(r.m256i) / sizeof(r.m256i[0])) ; i++) {
        r.m256i[i] = _mm256_add_epi64(op1.m256i[i], _mm256_and_si256(pg.m256i[i], op2.m256i[i]));
      }
    #elif defined(SIMDE_X86_SSE2_NATIVE)
      for (int i = 0 ; i < HEDLEY_STATIC_CAST(int, sizeof(r.m128i) / sizeof(r.m128i[0])) ; i++) {
        r.m128i[i] = _mm_add_epi64(op1.m128i[i], _mm_and_si128(pg.m128i[i], op2.m128i[i]));
      }
    #elif defined(SIMDE_POWER_ALTIVEC_P8_NATIVE)
      r.altivec = vec_add(op1.altivec, vec_and(pg.altivec_b64, op2.altivec));
    #elif defined(SIMDE_ZARCH_ZVECTOR_13_NATIVE)
      r.altivec = op1.altivec + (pg.values & op2.altivec);
    #elif defined(SIMDE_WASM_SIMD128_NATIVE)
      r.v128 = wasm_i64x2_add(op1.v128, wasm_v128_and(pg.v128, op2.v128));
    #elif defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r.values = op1.values + (pg.values_i64 & op2.values);
    #else
      SIMDE_VECTORIZE
      for (int i = 0 ; i < HEDLEY_STATIC_CAST(int, sizeof(r.values) / sizeof(r.values[0])) ; i++) {
        r.values[i] = op1.values[i] + (pg.values_i64[i] & op2.values[i]);
      }
    #endif

    return r;
  #endif
}
#if defined(SIMDE_ARM_SVE_ENABLE_NATIVE_ALIASES)
  #undef simde_svadd_s64_m
  #define svadd_s64_m(pg, op1, op2) simde_svadd_s64_m(pg, op1, op2)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_svuint8_t
simde_svadd_u8_z(simde_svbool_t pg, simde_svuint8_t op1, simde_svuint8_t op2) {
  #if defined(SIMDE_ARM_SVE_NATIVE)
    return svadd_u8_z(pg, op1, op2);
  #else
    simde_svuint8_t r;

    #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
      r.neon = vandq_u8(pg.neon_u8, vaddq_u8(op1.neon, op2.neon));
    #elif defined(SIMDE_X86_AVX512BW_NATIVE) && (SIMDE_ARM_SVE_VECTOR_SIZE >= 512)
      r.m512i = _mm512_maskz_add_epi8(simde_svbool_to_mmask64(pg), op1.m512i, op2.m512i);
    #elif defined(SIMDE_X86_AVX512BW_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
      r.m256i[0] = _mm256_maskz_add_epi8(simde_svbool_to_mmask32(pg), op1.m256i[0], op2.m256i[0]);
    #elif defined(SIMDE_X86_AVX2_NATIVE)
      for (int i = 0 ; i < HEDLEY_STATIC_CAST(int, sizeof(r.m256i) / sizeof(r.m256i[0])) ; i++) {
        r.m256i[i] = _mm256_and_si256(pg.m256i[i], _mm256_add_epi8(op1.m256i[i], op2.m256i[i]));
      }
    #elif defined(SIMDE_X86_SSE2_NATIVE)
      for (int i = 0 ; i < HEDLEY_STATIC_CAST(int, sizeof(r.m128i) / sizeof(r.m128i[0])) ; i++) {
        r.m128i[i] = _mm_and_si128(pg.m128i[i], _mm_add_epi8(op1.m128i[i], op2.m128i[i]));
      }
    #elif defined(SIMDE_POWER_ALTIVEC_P6_NATIVE)
      r.altivec = vec_and(pg.altivec_b8, vec_add(op1.altivec, op2.altivec));
    #elif defined(SIMDE_ZARCH_ZVECTOR_13_NATIVE)
      r.altivec = pg.values & (op1.altivec + op2.altivec);
    #elif defined(SIMDE_WASM_SIMD128_NATIVE)
      r.v128 = wasm_v128_and(pg.v128, wasm_i8x16_add(op1.v128, op2.v128));
    #elif defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r.values = pg.values_u8 & (op1.values + op2.values);
    #else
      SIMDE_VECTORIZE
      for (int i = 0 ; i < HEDLEY_STATIC_CAST(int, sizeof(r.values) / sizeof(r.values[0])) ; i++) {
        r.values[i] = pg.values_u8[i] & (op1.values[i] + op2.values[i]);
      }
    #endif

    return r;
  #endif
}
#if defined(SIMDE_ARM_SVE_ENABLE_NATIVE_ALIASES)
  #undef simde_svadd_u8_z
  #define svadd_u8_z(pg, op1, op2) simde_svadd_u8_z(pg, op1, op2)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_svuint8_t
simde_svadd_u8_m(simde_svbool_t pg, simde_svuint8_t op1, simde_svuint8_t op2) {
  #if defined(SIMDE_ARM_SVE_NATIVE)
    return svadd_u8_m(pg, op1, op2);
  #else
    simde_svuint8_t r;

    #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
      r.neon = vaddq_u8(op1.neon, vandq_u8(pg.neon_u8, op2.neon));
    #elif defined(SIMDE_X86_AVX512BW_NATIVE) && (SIMDE_ARM_SVE_VECTOR_SIZE >= 512)
      r.m512i = _mm512_mask_add_epi8(op1.m512i, simde_svbool_to_mmask64(pg), op1.m512i, op2.m512i);
    #elif defined(SIMDE_X86_AVX512BW_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
      r.m256i[0] = _mm256_mask_add_epi8(op1.m256i[0], simde_svbool_to_mmask32(pg), op1.m256i[0], op2.m256i[0]);
    #elif defined(SIMDE_X86_AVX2_NATIVE)
      for (int i = 0 ; i < HEDLEY_STATIC_CAST(int, sizeof(r.m256i) / sizeof(r.m256i[0])) ; i++) {
        r.m256i[i] = _mm256_add_epi8(op1.m256i[i], _mm256_and_si256(pg.m256i[i], op2.m256i[i]));
      }
    #elif defined(SIMDE_X86_SSE2_NATIVE)
      for (int i = 0 ; i < HEDLEY_STATIC_CAST(int, sizeof(r.m128i) / sizeof(r.m128i[0])) ; i++) {
        r.m128i[i] = _mm_add_epi8(op1.m128i[i], _mm_and_si128(pg.m128i[i], op2.m128i[i]));
      }
    #elif defined(SIMDE_POWER_ALTIVEC_P6_NATIVE)
      r.altivec = vec_add(op1.altivec, vec_and(pg.altivec_b8, op2.altivec));
    #elif defined(SIMDE_ZARCH_ZVECTOR_13_NATIVE)
      r.altivec = op1.altivec + (pg.values & op2.altivec);
    #elif defined(SIMDE_WASM_SIMD128_NATIVE)
      r.v128 = wasm_i8x16_add(op1.v128, wasm_v128_and(pg.v128, op2.v128));
    #elif defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r.values = op1.values + (pg.values_u8 & op2.values);
    #else
      SIMDE_VECTORIZE
      for (int i = 0 ; i < HEDLEY_STATIC_CAST(int, sizeof(r.values) / sizeof(r.values[0])) ; i++) {
        r.values[i] = op1.values[i] + (pg.values_u8[i] & op2.values[i]);
      }
    #endif

    return r;
  #endif
}
#if defined(SIMDE_ARM_SVE_ENABLE_NATIVE_ALIASES)
  #undef simde_svadd_u8_m
  #define svadd_u8_m(pg, op1, op2) simde_svadd_u8_m(pg, op1, op2)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_svuint16_t
simde_svadd_u16_z(simde_svbool_t pg, simde_svuint16_t op1, simde_svuint16_t op2) {
  #if defined(SIMDE_ARM_SVE_NATIVE)
    return svadd_u16_z(pg, op1, op2);
  #else
    simde_svuint16_t r;

    #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
      r.neon = vandq_u16(pg.neon_u16, vaddq_u16(op1.neon, op2.neon));
    #elif defined(SIMDE_X86_AVX512BW_NATIVE) && (SIMDE_ARM_SVE_VECTOR_SIZE >= 512)
      r.m512i = _mm512_maskz_add_epi16(simde_svbool_to_mmask32(pg), op1.m512i, op2.m512i);
    #elif defined(SIMDE_X86_AVX512BW_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
      r.m256i[0] = _mm256_maskz_add_epi16(simde_svbool_to_mmask16(pg), op1.m256i[0], op2.m256i[0]);
    #elif defined(SIMDE_X86_AVX2_NATIVE)
      for (int i = 0 ; i < HEDLEY_STATIC_CAST(int, sizeof(r.m256i) / sizeof(r.m256i[0])) ; i++) {
        r.m256i[i] = _mm256_and_si256(pg.m256i[i], _mm256_add_epi16(op1.m256i[i], op2.m256i[i]));
      }
    #elif defined(SIMDE_X86_SSE2_NATIVE)
      for (int i = 0 ; i < HEDLEY_STATIC_CAST(int, sizeof(r.m128i) / sizeof(r.m128i[0])) ; i++) {
        r.m128i[i] = _mm_and_si128(pg.m128i[i], _mm_add_epi16(op1.m128i[i], op2.m128i[i]));
      }
    #elif defined(SIMDE_POWER_ALTIVEC_P6_NATIVE)
      r.altivec = vec_and(pg.altivec_b16, vec_add(op1.altivec, op2.altivec));
    #elif defined(SIMDE_ZARCH_ZVECTOR_13_NATIVE)
      r.altivec = pg.values & (op1.altivec + op2.altivec);
    #elif defined(SIMDE_WASM_SIMD128_NATIVE)
      r.v128 = wasm_v128_and(pg.v128, wasm_i16x8_add(op1.v128, op2.v128));
    #elif defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r.values = pg.values_u16 & (op1.values + op2.values);
    #else
      SIMDE_VECTORIZE
      for (int i = 0 ; i < HEDLEY_STATIC_CAST(int, sizeof(r.values) / sizeof(r.values[0])) ; i++) {
        r.values[i] = pg.values_u16[i] & (op1.values[i] + op2.values[i]);
      }
    #endif

    return r;
  #endif
}
#if defined(SIMDE_ARM_SVE_ENABLE_NATIVE_ALIASES)
  #undef simde_svadd_u16_z
  #define svadd_u16_z(pg, op1, op2) simde_svadd_u16_z(pg, op1, op2)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_svuint16_t
simde_svadd_u16_m(simde_svbool_t pg, simde_svuint16_t op1, simde_svuint16_t op2) {
  #if defined(SIMDE_ARM_SVE_NATIVE)
    return svadd_u16_m(pg, op1, op2);
  #else
    simde_svuint16_t r;

    #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
      r.neon = vaddq_u16(op1.neon, vandq_u16(pg.neon_u16, op2.neon));
    #elif defined(SIMDE_X86_AVX512BW_NATIVE) && (SIMDE_ARM_SVE_VECTOR_SIZE >= 512)
      r.m512i = _mm512_mask_add_epi16(op1.m512i, simde_svbool_to_mmask32(pg), op1.m512i, op2.m512i);
    #elif defined(SIMDE_X86_AVX512BW_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
      r.m256i[0] = _mm256_mask_add_epi16(op1.m256i[0], simde_svbool_to_mmask16(pg), op1.m256i[0], op2.m256i[0]);
    #elif defined(SIMDE_X86_AVX2_NATIVE)
      for (int i = 0 ; i < HEDLEY_STATIC_CAST(int, sizeof(r.m256i) / sizeof(r.m256i[0])) ; i++) {
        r.m256i[i] = _mm256_add_epi16(op1.m256i[i], _mm256_and_si256(pg.m256i[i], op2.m256i[i]));
      }
    #elif defined(SIMDE_X86_SSE2_NATIVE)
      for (int i = 0 ; i < HEDLEY_STATIC_CAST(int, sizeof(r.m128i) / sizeof(r.m128i[0])) ; i++) {
        r.m128i[i] = _mm_add_epi16(op1.m128i[i], _mm_and_si128(pg.m128i[i], op2.m128i[i]));
      }
    #elif defined(SIMDE_POWER_ALTIVEC_P6_NATIVE)
      r.altivec = vec_add(op1.altivec, vec_and(pg.altivec_b16, op2.altivec));
    #elif defined(SIMDE_ZARCH_ZVECTOR_13_NATIVE)
      r.altivec = op1.altivec + (pg.values_u16 & op2.altivec);
    #elif defined(SIMDE_WASM_SIMD128_NATIVE)
      r.v128 = wasm_i16x8_add(op1.v128, wasm_v128_and(pg.v128, op2.v128));
    #elif defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r.values = op1.values + (pg.values_u16 & op2.values);
    #else
      SIMDE_VECTORIZE
      for (int i = 0 ; i < HEDLEY_STATIC_CAST(int, sizeof(r.values) / sizeof(r.values[0])) ; i++) {
        r.values[i] = op1.values[i] + (pg.values_u16[i] & op2.values[i]);
      }
    #endif

    return r;
  #endif
}
#if defined(SIMDE_ARM_SVE_ENABLE_NATIVE_ALIASES)
  #undef simde_svadd_u16_m
  #define svadd_u16_m(pg, op1, op2) simde_svadd_u16_m(pg, op1, op2)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_svuint32_t
simde_svadd_u32_z(simde_svbool_t pg, simde_svuint32_t op1, simde_svuint32_t op2) {
  #if defined(SIMDE_ARM_SVE_NATIVE)
    return svadd_u32_z(pg, op1, op2);
  #else
    simde_svuint32_t r;

    #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
      r.neon = vandq_u32(pg.neon_u32, vaddq_u32(op1.neon, op2.neon));
    #elif defined(SIMDE_X86_AVX512BW_NATIVE) && (SIMDE_ARM_SVE_VECTOR_SIZE >= 512)
      r.m512i = _mm512_maskz_add_epi32(simde_svbool_to_mmask16(pg), op1.m512i, op2.m512i);
    #elif defined(SIMDE_X86_AVX512BW_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
      r.m256i[0] = _mm256_maskz_add_epi32(simde_svbool_to_mmask8(pg), op1.m256i[0], op2.m256i[0]);
    #elif defined(SIMDE_X86_AVX2_NATIVE)
      for (int i = 0 ; i < HEDLEY_STATIC_CAST(int, sizeof(r.m256i) / sizeof(r.m256i[0])) ; i++) {
        r.m256i[i] = _mm256_and_si256(pg.m256i[i], _mm256_add_epi32(op1.m256i[i], op2.m256i[i]));
      }
    #elif defined(SIMDE_X86_SSE2_NATIVE)
      for (int i = 0 ; i < HEDLEY_STATIC_CAST(int, sizeof(r.m128i) / sizeof(r.m128i[0])) ; i++) {
        r.m128i[i] = _mm_and_si128(pg.m128i[i], _mm_add_epi32(op1.m128i[i], op2.m128i[i]));
      }
    #elif defined(SIMDE_POWER_ALTIVEC_P6_NATIVE)
      r.altivec = vec_and(pg.altivec_b32, vec_add(op1.altivec, op2.altivec));
    #elif defined(SIMDE_ZARCH_ZVECTOR_13_NATIVE)
      r.altivec = pg.values & (op1.altivec + op2.altivec);
    #elif defined(SIMDE_WASM_SIMD128_NATIVE)
      r.v128 = wasm_v128_and(pg.v128, wasm_i32x4_add(op1.v128, op2.v128));
    #elif defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r.values = pg.values_u32 & (op1.values + op2.values);
    #else
      SIMDE_VECTORIZE
      for (int i = 0 ; i < HEDLEY_STATIC_CAST(int, sizeof(r.values) / sizeof(r.values[0])) ; i++) {
        r.values[i] = pg.values_u32[i] & (op1.values[i] + op2.values[i]);
      }
    #endif

    return r;
  #endif
}
#if defined(SIMDE_ARM_SVE_ENABLE_NATIVE_ALIASES)
  #undef simde_svadd_u32_z
  #define svadd_u32_z(pg, op1, op2) simde_svadd_u32_z(pg, op1, op2)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_svuint32_t
simde_svadd_u32_m(simde_svbool_t pg, simde_svuint32_t op1, simde_svuint32_t op2) {
  #if defined(SIMDE_ARM_SVE_NATIVE)
    return svadd_u32_m(pg, op1, op2);
  #else
    simde_svuint32_t r;

    #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
      r.neon = vaddq_u32(op1.neon, vandq_u32(pg.neon_u32, op2.neon));
    #elif defined(SIMDE_X86_AVX512BW_NATIVE) && (SIMDE_ARM_SVE_VECTOR_SIZE >= 512)
      r.m512i = _mm512_mask_add_epi32(op1.m512i, simde_svbool_to_mmask16(pg), op1.m512i, op2.m512i);
    #elif defined(SIMDE_X86_AVX512BW_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
      r.m256i[0] = _mm256_mask_add_epi32(op1.m256i[0], simde_svbool_to_mmask8(pg), op1.m256i[0], op2.m256i[0]);
    #elif defined(SIMDE_X86_AVX2_NATIVE)
      for (int i = 0 ; i < HEDLEY_STATIC_CAST(int, sizeof(r.m256i) / sizeof(r.m256i[0])) ; i++) {
        r.m256i[i] = _mm256_add_epi32(op1.m256i[i], _mm256_and_si256(pg.m256i[i], op2.m256i[i]));
      }
    #elif defined(SIMDE_X86_SSE2_NATIVE)
      for (int i = 0 ; i < HEDLEY_STATIC_CAST(int, sizeof(r.m128i) / sizeof(r.m128i[0])) ; i++) {
        r.m128i[i] = _mm_add_epi32(op1.m128i[i], _mm_and_si128(pg.m128i[i], op2.m128i[i]));
      }
    #elif defined(SIMDE_POWER_ALTIVEC_P6_NATIVE)
      r.altivec = vec_add(op1.altivec, vec_and(pg.altivec_b32, op2.altivec));
    #elif defined(SIMDE_ZARCH_ZVECTOR_13_NATIVE)
      r.altivec = op1.altivec + (pg.values & op2.altivec);
    #elif defined(SIMDE_WASM_SIMD128_NATIVE)
      r.v128 = wasm_i32x4_add(op1.v128, wasm_v128_and(pg.v128, op2.v128));
    #elif defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r.values = op1.values + (pg.values_u32 & op2.values);
    #else
      SIMDE_VECTORIZE
      for (int i = 0 ; i < HEDLEY_STATIC_CAST(int, sizeof(r.values) / sizeof(r.values[0])) ; i++) {
        r.values[i] = op1.values[i] + (pg.values_u32[i] & op2.values[i]);
      }
    #endif

    return r;
  #endif
}
#if defined(SIMDE_ARM_SVE_ENABLE_NATIVE_ALIASES)
  #undef simde_svadd_u32_m
  #define svadd_u32_m(pg, op1, op2) simde_svadd_u32_m(pg, op1, op2)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_svuint64_t
simde_svadd_u64_z(simde_svbool_t pg, simde_svuint64_t op1, simde_svuint64_t op2) {
  #if defined(SIMDE_ARM_SVE_NATIVE)
    return svadd_u64_z(pg, op1, op2);
  #else
    simde_svuint64_t r;

    #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
      r.neon = vandq_u64(pg.neon_u64, vaddq_u64(op1.neon, op2.neon));
    #elif defined(SIMDE_X86_AVX512BW_NATIVE) && (SIMDE_ARM_SVE_VECTOR_SIZE >= 512)
      r.m512i = _mm512_maskz_add_epi64(simde_svbool_to_mmask8(pg), op1.m512i, op2.m512i);
    #elif defined(SIMDE_X86_AVX512BW_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
      r.m256i[0] = _mm256_maskz_add_epi64(simde_svbool_to_mmask8(pg), op1.m256i[0], op2.m256i[0]);
    #elif defined(SIMDE_X86_AVX2_NATIVE)
      for (int i = 0 ; i < HEDLEY_STATIC_CAST(int, sizeof(r.m256i) / sizeof(r.m256i[0])) ; i++) {
        r.m256i[i] = _mm256_and_si256(pg.m256i[i], _mm256_add_epi64(op1.m256i[i], op2.m256i[i]));
      }
    #elif defined(SIMDE_X86_SSE2_NATIVE)
      for (int i = 0 ; i < HEDLEY_STATIC_CAST(int, sizeof(r.m128i) / sizeof(r.m128i[0])) ; i++) {
        r.m128i[i] = _mm_and_si128(pg.m128i[i], _mm_add_epi64(op1.m128i[i], op2.m128i[i]));
      }
    #elif defined(SIMDE_POWER_ALTIVEC_P8_NATIVE)
      r.altivec = vec_and(pg.altivec_b64, vec_add(op1.altivec, op2.altivec));
    #elif defined(SIMDE_ZARCH_ZVECTOR_13_NATIVE)
      r.altivec = pg.values & (op1.altivec + op2.altivec);
    #elif defined(SIMDE_WASM_SIMD128_NATIVE)
      r.v128 = wasm_v128_and(pg.v128, wasm_i64x2_add(op1.v128, op2.v128));
    #elif defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r.values = pg.values_u64 & (op1.values + op2.values);
    #else
      SIMDE_VECTORIZE
      for (int i = 0 ; i < HEDLEY_STATIC_CAST(int, sizeof(r.values) / sizeof(r.values[0])) ; i++) {
        r.values[i] = pg.values_u64[i] & (op1.values[i] + op2.values[i]);
      }
    #endif

    return r;
  #endif
}
#if defined(SIMDE_ARM_SVE_ENABLE_NATIVE_ALIASES)
  #undef simde_svadd_u64_z
  #define svadd_u64_z(pg, op1, op2) simde_svadd_u64_z(pg, op1, op2)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_svuint64_t
simde_svadd_u64_m(simde_svbool_t pg, simde_svuint64_t op1, simde_svuint64_t op2) {
  #if defined(SIMDE_ARM_SVE_NATIVE)
    return svadd_u64_m(pg, op1, op2);
  #else
    simde_svuint64_t r;

    #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
      r.neon = vaddq_u64(op1.neon, vandq_u64(pg.neon_u64, op2.neon));
    #elif defined(SIMDE_X86_AVX512BW_NATIVE) && (SIMDE_ARM_SVE_VECTOR_SIZE >= 512)
      r.m512i = _mm512_mask_add_epi64(op1.m512i, simde_svbool_to_mmask8(pg), op1.m512i, op2.m512i);
    #elif defined(SIMDE_X86_AVX512BW_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
      r.m256i[0] = _mm256_mask_add_epi64(op1.m256i[0], simde_svbool_to_mmask8(pg), op1.m256i[0], op2.m256i[0]);
    #elif defined(SIMDE_X86_AVX2_NATIVE)
      for (int i = 0 ; i < HEDLEY_STATIC_CAST(int, sizeof(r.m256i) / sizeof(r.m256i[0])) ; i++) {
        r.m256i[i] = _mm256_add_epi64(op1.m256i[i], _mm256_and_si256(pg.m256i[i], op2.m256i[i]));
      }
    #elif defined(SIMDE_X86_SSE2_NATIVE)
      for (int i = 0 ; i < HEDLEY_STATIC_CAST(int, sizeof(r.m128i) / sizeof(r.m128i[0])) ; i++) {
        r.m128i[i] = _mm_add_epi64(op1.m128i[i], _mm_and_si128(pg.m128i[i], op2.m128i[i]));
      }
    #elif defined(SIMDE_POWER_ALTIVEC_P8_NATIVE)
      r.altivec = vec_add(op1.altivec, vec_and(pg.altivec_b64, op2.altivec));
    #elif defined(SIMDE_ZARCH_ZVECTOR_13_NATIVE)
      r.altivec = op1.altivec + (pg.values & op2.altivec);
    #elif defined(SIMDE_WASM_SIMD128_NATIVE)
      r.v128 = wasm_i64x2_add(op1.v128, wasm_v128_and(pg.v128, op2.v128));
    #elif defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r.values = op1.values + (pg.values_u64 & op2.values);
    #else
      SIMDE_VECTORIZE
      for (int i = 0 ; i < HEDLEY_STATIC_CAST(int, sizeof(r.values) / sizeof(r.values[0])) ; i++) {
        r.values[i] = op1.values[i] + (pg.values_u64[i] & op2.values[i]);
      }
    #endif

    return r;
  #endif
}
#if defined(SIMDE_ARM_SVE_ENABLE_NATIVE_ALIASES)
  #undef simde_svadd_u64_m
  #define svadd_u64_m(pg, op1, op2) simde_svadd_u64_m(pg, op1, op2)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_svfloat32_t
simde_svadd_f32_z(simde_svbool_t pg, simde_svfloat32_t op1, simde_svfloat32_t op2) {
  #if defined(SIMDE_ARM_SVE_NATIVE)
    return svadd_f32_z(pg, op1, op2);
  #else
    simde_svfloat32_t r;

    #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
      r.neon = vreinterpretq_f32_s32(vandq_s32(pg.neon_i32, vreinterpretq_s32_f32(vaddq_f32(op1.neon, op2.neon))));
    #elif defined(SIMDE_X86_AVX512BW_NATIVE) && (SIMDE_ARM_SVE_VECTOR_SIZE >= 512)
      r.m512 = _mm512_maskz_add_ps(simde_svbool_to_mmask16(pg), op1.m512, op2.m512);
    #elif defined(SIMDE_X86_AVX512BW_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
      r.m256[0] = _mm256_maskz_add_ps(simde_svbool_to_mmask8(pg), op1.m256[0], op2.m256[0]);
    #elif defined(SIMDE_X86_AVX2_NATIVE)
      for (int i = 0 ; i < HEDLEY_STATIC_CAST(int, sizeof(r.m256) / sizeof(r.m256[0])) ; i++) {
        r.m256[i] = _mm256_and_ps(_mm256_castsi256_ps(pg.m256i[i]), _mm256_add_ps(op1.m256[i], op2.m256[i]));
      }
    #elif defined(SIMDE_X86_SSE2_NATIVE)
      for (int i = 0 ; i < HEDLEY_STATIC_CAST(int, sizeof(r.m128) / sizeof(r.m128[0])) ; i++) {
        r.m128[i] = _mm_and_ps(_mm_castsi128_ps(pg.m128i[i]), _mm_add_ps(op1.m128[i], op2.m128[i]));
      }
    #elif defined(SIMDE_POWER_ALTIVEC_P6_NATIVE)
      r.altivec = vec_and(pg.altivec_b32, vec_add(op1.altivec, op2.altivec));
    #elif defined(SIMDE_ZARCH_ZVECTOR_13_NATIVE)
      r.altivec = pg.values & (op1.altivec + op2.altivec);
    #elif defined(SIMDE_WASM_SIMD128_NATIVE)
      r.v128 = wasm_v128_and(pg.v128, wasm_i32x4_add(op1.v128, op2.v128));
    #elif defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r.values = HEDLEY_REINTERPRET_CAST(__typeof__(r.values), pg.values_i32 & HEDLEY_REINTERPRET_CAST(__typeof__(pg.values_i32), op1.values + op2.values));
    #else
      SIMDE_VECTORIZE
      for (int i = 0 ; i < HEDLEY_STATIC_CAST(int, sizeof(r.values) / sizeof(r.values[0])) ; i++) {
        simde_float32 tmpf = op1.values[i] + op2.values[i];
        int32_t tmpi;

        simde_memcpy(&tmpi, &tmpf, sizeof(tmpi));
        tmpi = pg.values_i32[i] & tmpi;
        simde_memcpy(&tmpf, &tmpi, sizeof(tmpf));

        r.values[i] = tmpf;
      }
    #endif

    return r;
  #endif
}
#if defined(SIMDE_ARM_SVE_ENABLE_NATIVE_ALIASES)
  #undef simde_svadd_f32_z
  #define svadd_f32_z(pg, op1, op2) simde_svadd_f32_z(pg, op1, op2)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_svfloat32_t
simde_svadd_f32_m(simde_svbool_t pg, simde_svfloat32_t op1, simde_svfloat32_t op2) {
  #if defined(SIMDE_ARM_SVE_NATIVE)
    return svadd_f32_m(pg, op1, op2);
  #else
    simde_svfloat32_t r;

    #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
      r.neon = vaddq_f32(op1.neon, vreinterpretq_f32_s32(vandq_s32(pg.neon_i32, vreinterpretq_s32_f32(op2.neon))));
    #elif defined(SIMDE_X86_AVX512BW_NATIVE) && (SIMDE_ARM_SVE_VECTOR_SIZE >= 512)
      r.m512 = _mm512_mask_add_ps(op1.m512, simde_svbool_to_mmask16(pg), op1.m512, op2.m512);
    #elif defined(SIMDE_X86_AVX512BW_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
      r.m256[0] = _mm256_mask_add_ps(op1.m256[0], simde_svbool_to_mmask8(pg), op1.m256[0], op2.m256[0]);
    #elif defined(SIMDE_X86_AVX2_NATIVE)
      for (int i = 0 ; i < HEDLEY_STATIC_CAST(int, sizeof(r.m256) / sizeof(r.m256[0])) ; i++) {
        r.m256[i] = _mm256_add_ps(op1.m256[i], _mm256_and_ps(_mm256_castsi256_ps(pg.m256i[i]), op2.m256[i]));
      }
    #elif defined(SIMDE_X86_SSE2_NATIVE)
      for (int i = 0 ; i < HEDLEY_STATIC_CAST(int, sizeof(r.m128) / sizeof(r.m128[0])) ; i++) {
        r.m128[i] = _mm_add_ps(op1.m128[i], _mm_and_ps(_mm_castsi128_ps(pg.m128i[i]), op2.m128[i]));
      }
    #elif defined(SIMDE_POWER_ALTIVEC_P6_NATIVE)
      r.altivec = vec_add(op1.altivec, vec_and(pg.altivec_b32, op2.altivec));
    #elif defined(SIMDE_ZARCH_ZVECTOR_13_NATIVE)
      r.altivec = op1.altivec + (pg.values & op2.altivec);
    #elif defined(SIMDE_WASM_SIMD128_NATIVE)
      r.v128 = wasm_i32x4_add(op1.v128, wasm_v128_and(pg.v128, op2.v128));
    #elif defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r.values = op1.values + HEDLEY_REINTERPRET_CAST(__typeof__(op1.values), pg.values_i32 & HEDLEY_REINTERPRET_CAST(__typeof__(pg.values_i32), op2.values));
    #else
      SIMDE_VECTORIZE
      for (int i = 0 ; i < HEDLEY_STATIC_CAST(int, sizeof(r.values) / sizeof(r.values[0])) ; i++) {
        simde_float32 tmpf = op2.values[i];
        int32_t tmpi;

        simde_memcpy(&tmpi, &tmpf, sizeof(tmpi));
        tmpi &= pg.values_i32[i];
        simde_memcpy(&tmpf, &tmpi, sizeof(tmpf));

        r.values[i] = op1.values[i] + tmpf;
      }
    #endif

    return r;
  #endif
}
#if defined(SIMDE_ARM_SVE_ENABLE_NATIVE_ALIASES)
  #undef simde_svadd_f32_m
  #define svadd_f32_m(pg, op1, op2) simde_svadd_f32_m(pg, op1, op2)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_svfloat64_t
simde_svadd_f64_z(simde_svbool_t pg, simde_svfloat64_t op1, simde_svfloat64_t op2) {
  #if defined(SIMDE_ARM_SVE_NATIVE)
    return svadd_f64_z(pg, op1, op2);
  #else
    simde_svfloat64_t r;

    #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
      r.neon = vreinterpretq_f64_s64(vandq_s64(pg.neon_i64, vreinterpretq_s64_f64(vaddq_f64(op1.neon, op2.neon))));
    #elif defined(SIMDE_X86_AVX512BW_NATIVE) && (SIMDE_ARM_SVE_VECTOR_SIZE >= 512)
      r.m512d = _mm512_maskz_add_pd(simde_svbool_to_mmask8(pg), op1.m512d, op2.m512d);
    #elif defined(SIMDE_X86_AVX512BW_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
      r.m256d[0] = _mm256_maskz_add_pd(simde_svbool_to_mmask8(pg), op1.m256d[0], op2.m256d[0]);
    #elif defined(SIMDE_X86_AVX2_NATIVE)
      for (int i = 0 ; i < HEDLEY_STATIC_CAST(int, sizeof(r.m256d) / sizeof(r.m256d[0])) ; i++) {
        r.m256d[i] = _mm256_and_pd(_mm256_castsi256_pd(pg.m256i[i]), _mm256_add_pd(op1.m256d[i], op2.m256d[i]));
      }
    #elif defined(SIMDE_X86_SSE2_NATIVE)
      for (int i = 0 ; i < HEDLEY_STATIC_CAST(int, sizeof(r.m128d) / sizeof(r.m128d[0])) ; i++) {
        r.m128d[i] = _mm_and_pd(_mm_castsi128_pd(pg.m128i[i]), _mm_add_pd(op1.m128d[i], op2.m128d[i]));
      }
    #elif defined(SIMDE_POWER_ALTIVEC_P8_NATIVE)
      r.altivec = vec_and(pg.altivec_b64, vec_add(op1.altivec, op2.altivec));
    #elif defined(SIMDE_ZARCH_ZVECTOR_13_NATIVE)
      r.altivec = pg.values & (op1.altivec + op2.altivec);
    #elif defined(SIMDE_WASM_SIMD128_NATIVE)
      r.v128 = wasm_v128_and(pg.v128, wasm_i64x2_add(op1.v128, op2.v128));
    #elif defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r.values = HEDLEY_REINTERPRET_CAST(__typeof__(r.values), pg.values_i64 & HEDLEY_REINTERPRET_CAST(__typeof__(pg.values_i64), op1.values + op2.values));
    #else
      SIMDE_VECTORIZE
      for (int i = 0 ; i < HEDLEY_STATIC_CAST(int, sizeof(r.values) / sizeof(r.values[0])) ; i++) {
        simde_float64 tmpf = op1.values[i] + op2.values[i];
        int64_t tmpi;

        simde_memcpy(&tmpi, &tmpf, sizeof(tmpi));
        tmpi = pg.values_i64[i] & tmpi;
        simde_memcpy(&tmpf, &tmpi, sizeof(tmpf));

        r.values[i] = tmpf;
      }
    #endif

    return r;
  #endif
}
#if defined(SIMDE_ARM_SVE_ENABLE_NATIVE_ALIASES)
  #undef simde_svadd_f64_z
  #define svadd_f64_z(pg, op1, op2) simde_svadd_f64_z(pg, op1, op2)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_svfloat64_t
simde_svadd_f64_m(simde_svbool_t pg, simde_svfloat64_t op1, simde_svfloat64_t op2) {
  #if defined(SIMDE_ARM_SVE_NATIVE)
    return svadd_f64_m(pg, op1, op2);
  #else
    simde_svfloat64_t r;

    #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
      r.neon = vaddq_f64(op1.neon, vreinterpretq_f64_s64(vandq_s64(pg.neon_i64, vreinterpretq_s64_f64(op2.neon))));
    #elif defined(SIMDE_X86_AVX512BW_NATIVE) && (SIMDE_ARM_SVE_VECTOR_SIZE >= 512)
      r.m512d = _mm512_mask_add_pd(op1.m512d, simde_svbool_to_mmask8(pg), op1.m512d, op2.m512d);
    #elif defined(SIMDE_X86_AVX512BW_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
      r.m256d[0] = _mm256_mask_add_pd(op1.m256d[0], simde_svbool_to_mmask8(pg), op1.m256d[0], op2.m256d[0]);
    #elif defined(SIMDE_X86_AVX2_NATIVE)
      for (int i = 0 ; i < HEDLEY_STATIC_CAST(int, sizeof(r.m256d) / sizeof(r.m256d[0])) ; i++) {
        r.m256d[i] = _mm256_add_pd(op1.m256d[i], _mm256_and_pd(_mm256_castsi256_pd(pg.m256i[i]), op2.m256d[i]));
      }
    #elif defined(SIMDE_X86_SSE2_NATIVE)
      for (int i = 0 ; i < HEDLEY_STATIC_CAST(int, sizeof(r.m128d) / sizeof(r.m128d[0])) ; i++) {
        r.m128d[i] = _mm_add_pd(op1.m128d[i], _mm_and_pd(_mm_castsi128_pd(pg.m128i[i]), op2.m128d[i]));
      }
    #elif defined(SIMDE_POWER_ALTIVEC_P7_NATIVE)
      r.altivec = vec_add(op1.altivec, vec_and(pg.altivec_b64, op2.altivec));
    #elif defined(SIMDE_ZARCH_ZVECTOR_13_NATIVE)
      r.altivec = op1.altivec + (pg.values & op2.altivec);
    #elif defined(SIMDE_WASM_SIMD128_NATIVE)
      r.v128 = wasm_i64x2_add(op1.v128, wasm_v128_and(pg.v128, op2.v128));
    #elif defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r.values = op1.values + HEDLEY_REINTERPRET_CAST(__typeof__(op1.values), pg.values_i64 & HEDLEY_REINTERPRET_CAST(__typeof__(pg.values_i64), op2.values));
    #else
      SIMDE_VECTORIZE
      for (int i = 0 ; i < HEDLEY_STATIC_CAST(int, sizeof(r.values) / sizeof(r.values[0])) ; i++) {
        simde_float64 tmpf = op2.values[i];
        int64_t tmpi;

        simde_memcpy(&tmpi, &tmpf, sizeof(tmpi));
        tmpi &= pg.values_i64[i];
        simde_memcpy(&tmpf, &tmpi, sizeof(tmpf));

        r.values[i] = op1.values[i] + tmpf;
      }
    #endif

    return r;
  #endif
}
#if defined(SIMDE_ARM_SVE_ENABLE_NATIVE_ALIASES)
  #undef simde_svadd_f64_m
  #define svadd_f64_m(pg, op1, op2) simde_svadd_f64_m(pg, op1, op2)
#endif

#if defined(__cplusplus)
  SIMDE_FUNCTION_ATTRIBUTES    simde_svint8_t simde_svadd_z(simde_svbool_t pg,    simde_svint8_t op1,    simde_svint8_t op2) { return simde_svadd_s8_z (pg, op1, op2); }
  SIMDE_FUNCTION_ATTRIBUTES   simde_svint16_t simde_svadd_z(simde_svbool_t pg,   simde_svint16_t op1,   simde_svint16_t op2) { return simde_svadd_s16_z(pg, op1, op2); }
  SIMDE_FUNCTION_ATTRIBUTES   simde_svint32_t simde_svadd_z(simde_svbool_t pg,   simde_svint32_t op1,   simde_svint32_t op2) { return simde_svadd_s32_z(pg, op1, op2); }
  SIMDE_FUNCTION_ATTRIBUTES   simde_svint64_t simde_svadd_z(simde_svbool_t pg,   simde_svint64_t op1,   simde_svint64_t op2) { return simde_svadd_s64_z(pg, op1, op2); }
  SIMDE_FUNCTION_ATTRIBUTES   simde_svuint8_t simde_svadd_z(simde_svbool_t pg,   simde_svuint8_t op1,   simde_svuint8_t op2) { return simde_svadd_u8_z (pg, op1, op2); }
  SIMDE_FUNCTION_ATTRIBUTES  simde_svuint16_t simde_svadd_z(simde_svbool_t pg,  simde_svuint16_t op1,  simde_svuint16_t op2) { return simde_svadd_u16_z(pg, op1, op2); }
  SIMDE_FUNCTION_ATTRIBUTES  simde_svuint32_t simde_svadd_z(simde_svbool_t pg,  simde_svuint32_t op1,  simde_svuint32_t op2) { return simde_svadd_u32_z(pg, op1, op2); }
  SIMDE_FUNCTION_ATTRIBUTES  simde_svuint64_t simde_svadd_z(simde_svbool_t pg,  simde_svuint64_t op1,  simde_svuint64_t op2) { return simde_svadd_u64_z(pg, op1, op2); }
  SIMDE_FUNCTION_ATTRIBUTES simde_svfloat32_t simde_svadd_z(simde_svbool_t pg, simde_svfloat32_t op1, simde_svfloat32_t op2) { return simde_svadd_f32_z(pg, op1, op2); }
  SIMDE_FUNCTION_ATTRIBUTES simde_svfloat64_t simde_svadd_z(simde_svbool_t pg, simde_svfloat64_t op1, simde_svfloat64_t op2) { return simde_svadd_f64_z(pg, op1, op2); }

  SIMDE_FUNCTION_ATTRIBUTES    simde_svint8_t simde_svadd_m(simde_svbool_t pg,    simde_svint8_t op1,    simde_svint8_t op2) { return simde_svadd_s8_m (pg, op1, op2); }
  SIMDE_FUNCTION_ATTRIBUTES   simde_svint16_t simde_svadd_m(simde_svbool_t pg,   simde_svint16_t op1,   simde_svint16_t op2) { return simde_svadd_s16_m(pg, op1, op2); }
  SIMDE_FUNCTION_ATTRIBUTES   simde_svint32_t simde_svadd_m(simde_svbool_t pg,   simde_svint32_t op1,   simde_svint32_t op2) { return simde_svadd_s32_m(pg, op1, op2); }
  SIMDE_FUNCTION_ATTRIBUTES   simde_svint64_t simde_svadd_m(simde_svbool_t pg,   simde_svint64_t op1,   simde_svint64_t op2) { return simde_svadd_s64_m(pg, op1, op2); }
  SIMDE_FUNCTION_ATTRIBUTES   simde_svuint8_t simde_svadd_m(simde_svbool_t pg,   simde_svuint8_t op1,   simde_svuint8_t op2) { return simde_svadd_u8_m (pg, op1, op2); }
  SIMDE_FUNCTION_ATTRIBUTES  simde_svuint16_t simde_svadd_m(simde_svbool_t pg,  simde_svuint16_t op1,  simde_svuint16_t op2) { return simde_svadd_u16_m(pg, op1, op2); }
  SIMDE_FUNCTION_ATTRIBUTES  simde_svuint32_t simde_svadd_m(simde_svbool_t pg,  simde_svuint32_t op1,  simde_svuint32_t op2) { return simde_svadd_u32_m(pg, op1, op2); }
  SIMDE_FUNCTION_ATTRIBUTES  simde_svuint64_t simde_svadd_m(simde_svbool_t pg,  simde_svuint64_t op1,  simde_svuint64_t op2) { return simde_svadd_u64_m(pg, op1, op2); }
  SIMDE_FUNCTION_ATTRIBUTES simde_svfloat32_t simde_svadd_m(simde_svbool_t pg, simde_svfloat32_t op1, simde_svfloat32_t op2) { return simde_svadd_f32_m(pg, op1, op2); }
  SIMDE_FUNCTION_ATTRIBUTES simde_svfloat64_t simde_svadd_m(simde_svbool_t pg, simde_svfloat64_t op1, simde_svfloat64_t op2) { return simde_svadd_f64_m(pg, op1, op2); }
#elif defined(SIMDE_GENERIC_)
  #define simde_svadd_z(pg, op1, op2) \
    (SIMDE_GENERIC_((op1), \
         simde_svint8_t: simde_svadd_s8_z, \
        simde_svint16_t: simde_svadd_s16_z, \
        simde_svint32_t: simde_svadd_s32_z, \
        simde_svint64_t: simde_svadd_s64_z, \
        simde_svuint8_t: simde_svadd_u8_z, \
       simde_svuint16_t: simde_svadd_u16_z, \
       simde_svuint32_t: simde_svadd_u32_z, \
       simde_svuint64_t: simde_svadd_u64_z, \
      simde_svfloat32_t: simde_svadd_f32_z, \
      simde_svfloat64_t: simde_svadd_f64_z)((pg), (op1), (op2)))

  #define simde_svadd_m(pg, op1, op2) \
    (SIMDE_GENERIC_((op1), \
         simde_svint8_t: simde_svadd_s8_m, \
        simde_svint16_t: simde_svadd_s16_m, \
        simde_svint32_t: simde_svadd_s32_m, \
        simde_svint64_t: simde_svadd_s64_m, \
        simde_svuint8_t: simde_svadd_u8_m, \
       simde_svuint16_t: simde_svadd_u16_m, \
       simde_svuint32_t: simde_svadd_u32_m, \
       simde_svuint64_t: simde_svadd_u64_m, \
      simde_svfloat32_t: simde_svadd_f32_m, \
      simde_svfloat64_t: simde_svadd_f64_m)((pg), (op1), (op2)))
#endif

HEDLEY_DIAGNOSTIC_POP

#endif /* SIMDE_ARM_SVE_ADD_H */
