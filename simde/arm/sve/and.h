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

#if !defined(SIMDE_ARM_SVE_AND_H)
#define SIMDE_ARM_SVE_AND_H

#include "types.h"
#include "dup_n.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS

SIMDE_FUNCTION_ATTRIBUTES
simde_svint8_t
simde_svand_s8_z(simde_svbool_t pg, simde_svint8_t op1, simde_svint8_t op2) {
  #if defined(SIMDE_ARM_SVE_NATIVE)
    return svand_s8_z(pg, op1, op2);
  #else
    simde_svint8_t r;

    #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
      r.neon = vandq_s8(pg.neon_i8, vandq_s8(op1.neon, op2.neon));
    #elif defined(SIMDE_X86_AVX512BW_NATIVE) && (SIMDE_ARM_SVE_VECTOR_SIZE >= 512)
      r.m512i = _mm512_maskz_mov_epi8(simde_svbool_to_mmask64(pg), _mm512_and_si512(op1.m512i, op2.m512i));
    #elif defined(SIMDE_X86_AVX512BW_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
      r.m256i[0] = _mm256_maskz_mov_epi8(simde_svbool_to_mmask32(pg), _mm256_and_si256(op1.m256i[0], op2.m256i[0]));
    #elif defined(SIMDE_X86_AVX2_NATIVE)
      for (int i = 0 ; i < HEDLEY_STATIC_CAST(int, sizeof(r.m256i) / sizeof(r.m256i[0])) ; i++) {
        r.m256i[i] = _mm256_and_si256(pg.m256i[i], _mm256_and_si256(op1.m256i[i], op2.m256i[i]));
      }
    #elif defined(SIMDE_X86_SSE2_NATIVE)
      for (int i = 0 ; i < HEDLEY_STATIC_CAST(int, sizeof(r.m128i) / sizeof(r.m128i[0])) ; i++) {
        r.m128i[i] = _mm_and_si128(pg.m128i[i], _mm_and_si128(op1.m128i[i], op2.m128i[i]));
      }
    #elif defined(SIMDE_POWER_ALTIVEC_P6_NATIVE)
      r.altivec = vec_and(pg.altivec_b8, vec_and(op1.altivec, op2.altivec));
    #elif defined(SIMDE_ZARCH_ZVECTOR_13_NATIVE)
      r.altivec = HEDLEY_REINTERPRET_CAST(__typeof__(r.altivec), pg.altivec_b8) & (op1.altivec & op2.altivec);
    #elif defined(SIMDE_WASM_SIMD128_NATIVE)
      r.v128 = wasm_v128_and(pg.v128, wasm_v128_and(op1.v128, op2.v128));
    #elif defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r.values = pg.values_i8 & (op1.values & op2.values);
    #else
      SIMDE_VECTORIZE
      for (int i = 0 ; i < HEDLEY_STATIC_CAST(int, sizeof(r.values) / sizeof(r.values[0])) ; i++) {
        r.values[i] = pg.values_i8[i] & (op1.values[i] & op2.values[i]);
      }
    #endif

    return r;
  #endif
}
#if defined(SIMDE_ARM_SVE_ENABLE_NATIVE_ALIASES)
  #undef simde_svand_s8_z
  #define svand_s8_z(pg, op1, op2) simde_svand_s8_z(pg, op1, op2)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_svint8_t
simde_svand_s8_m(simde_svbool_t pg, simde_svint8_t op1, simde_svint8_t op2) {
  #if defined(SIMDE_ARM_SVE_NATIVE)
    return svand_s8_m(pg, op1, op2);
  #else
    simde_svint8_t r;

    #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
      r.neon = vbslq_s8(pg.neon_u8, vandq_s8(op1.neon, op2.neon), op1.neon);
    #elif defined(SIMDE_X86_AVX512BW_NATIVE) && (SIMDE_ARM_SVE_VECTOR_SIZE >= 512)
      r.m512i = _mm512_mask_mov_epi8(op1.m512i, simde_svbool_to_mmask64(pg), _mm512_and_si512(op1.m512i, op2.m512i));
    #elif defined(SIMDE_X86_AVX512BW_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
      r.m256i[0] = _mm256_mask_mov_epi8(op1.m256i[0], simde_svbool_to_mmask32(pg), _mm256_and_si256(op1.m256i[0], op2.m256i[0]));
    #elif defined(SIMDE_X86_AVX2_NATIVE)
      for (int i = 0 ; i < HEDLEY_STATIC_CAST(int, sizeof(r.m256i) / sizeof(r.m256i[0])) ; i++) {
        r.m256i[i] = _mm256_blendv_epi8(op1.m256i[i], _mm256_and_si256(op1.m256i[i], op2.m256i[i]), pg.m256i[i]);
      }
    #elif defined(SIMDE_X86_SSE4_1_NATIVE)
      for (int i = 0 ; i < HEDLEY_STATIC_CAST(int, sizeof(r.m128i) / sizeof(r.m128i[0])) ; i++) {
        r.m128i[i] = _mm_blendv_epi8(op1.m128i[i], _mm_and_si128(op1.m128i[i], op2.m128i[i]), pg.m128i[i]);
      }
    #elif defined(SIMDE_X86_SSE2_NATIVE)
      for (int i = 0 ; i < HEDLEY_STATIC_CAST(int, sizeof(r.m128i) / sizeof(r.m128i[0])) ; i++) {
        r.m128i[i] = _mm_or_si128(_mm_andnot_si128(pg.m128i[i], op1.m128i[i]), _mm_and_si128(pg.m128i[i], _mm_and_si128(op1.m128i[i], op2.m128i[i])));
      }
    #elif defined(SIMDE_POWER_ALTIVEC_P6_NATIVE) || defined(SIMDE_ZARCH_ZVECTOR_13_NATIVE)
      r.altivec = vec_sel(op1.altivec, vec_and(op1.altivec, op2.altivec), pg.altivec_b8);
    #elif defined(SIMDE_WASM_SIMD128_NATIVE)
      r.v128 = wasm_v128_bitselect(wasm_v128_and(op1.v128, op2.v128), op1.v128, pg.v128);
    #elif defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r.values = (~pg.values_i8 & op1.values) | (op1.values & op2.values);
    #else
      SIMDE_VECTORIZE
      for (int i = 0 ; i < HEDLEY_STATIC_CAST(int, sizeof(r.values) / sizeof(r.values[0])) ; i++) {
        r.values[i] = (~pg.values_i8[i] & op1.values[i]) | (op1.values[i] & op2.values[i]);
      }
    #endif

    return r;
  #endif
}
#if defined(SIMDE_ARM_SVE_ENABLE_NATIVE_ALIASES)
  #undef simde_svand_s8_m
  #define svand_s8_m(pg, op1, op2) simde_svand_s8_m(pg, op1, op2)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_svint8_t
simde_svand_s8_x(simde_svbool_t pg, simde_svint8_t op1, simde_svint8_t op2) {
  #if defined(SIMDE_ARM_SVE_NATIVE)
    return svand_s8_x(pg, op1, op2);
  #else
    return SIMDE_ARM_SVE_UNDEFINED_SYMBOL(simde_svand_s8)(pg, op1, op2);
  #endif
}
#if defined(SIMDE_ARM_SVE_ENABLE_NATIVE_ALIASES)
  #undef simde_svand_s8_x
  #define svand_s8_x(pg, op1, op2) simde_svand_s8_x(pg, op1, op2)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_svint8_t
simde_svand_n_s8_z(simde_svbool_t pg, simde_svint8_t op1, int8_t op2) {
  #if defined(SIMDE_ARM_SVE_NATIVE)
    return svand_n_s8_z(pg, op1, op2);
  #else
    return simde_svand_s8_z(pg, op1, simde_svdup_n_s8(op2));
  #endif
}
#if defined(SIMDE_ARM_SVE_ENABLE_NATIVE_ALIASES)
  #undef simde_svand_n_s8_z
  #define svand_n_s8_z(pg, op1, op2) simde_svand_n_s8_z(pg, op1, op2)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_svint8_t
simde_svand_n_s8_m(simde_svbool_t pg, simde_svint8_t op1, int8_t op2) {
  #if defined(SIMDE_ARM_SVE_NATIVE)
    return svand_n_s8_m(pg, op1, op2);
  #else
    return simde_svand_s8_m(pg, op1, simde_svdup_n_s8(op2));
  #endif
}
#if defined(SIMDE_ARM_SVE_ENABLE_NATIVE_ALIASES)
  #undef simde_svand_n_s8_m
  #define svand_n_s8_m(pg, op1, op2) simde_svand_n_s8_m(pg, op1, op2)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_svint8_t
simde_svand_n_s8_x(simde_svbool_t pg, simde_svint8_t op1, int8_t op2) {
  #if defined(SIMDE_ARM_SVE_NATIVE)
    return svand_n_s8_x(pg, op1, op2);
  #else
    return simde_svand_s8_x(pg, op1, simde_svdup_n_s8(op2));
  #endif
}
#if defined(SIMDE_ARM_SVE_ENABLE_NATIVE_ALIASES)
  #undef simde_svand_n_s8_x
  #define svand_n_s8_x(pg, op1, op2) simde_svand_n_s8_x(pg, op1, op2)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_svint16_t
simde_svand_s16_z(simde_svbool_t pg, simde_svint16_t op1, simde_svint16_t op2) {
  #if defined(SIMDE_ARM_SVE_NATIVE)
    return svand_s16_z(pg, op1, op2);
  #else
    return simde_svreinterpret_s16_s8(simde_svand_s8_z(pg, simde_svreinterpret_s8_s16(op1), simde_svreinterpret_s8_s16(op2)));
  #endif
}
#if defined(SIMDE_ARM_SVE_ENABLE_NATIVE_ALIASES)
  #undef simde_svand_s16_z
  #define svand_s16_z(pg, op1, op2) simde_svand_s16_z(pg, op1, op2)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_svint16_t
simde_svand_s16_m(simde_svbool_t pg, simde_svint16_t op1, simde_svint16_t op2) {
  #if defined(SIMDE_ARM_SVE_NATIVE)
    return svand_s16_m(pg, op1, op2);
  #else
    return simde_svreinterpret_s16_s8(simde_svand_s8_m(pg, simde_svreinterpret_s8_s16(op1), simde_svreinterpret_s8_s16(op2)));
  #endif
}
#if defined(SIMDE_ARM_SVE_ENABLE_NATIVE_ALIASES)
  #undef simde_svand_s16_m
  #define svand_s16_m(pg, op1, op2) simde_svand_s16_m(pg, op1, op2)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_svint16_t
simde_svand_s16_x(simde_svbool_t pg, simde_svint16_t op1, simde_svint16_t op2) {
  #if defined(SIMDE_ARM_SVE_NATIVE)
    return svand_s16_x(pg, op1, op2);
  #else
    return SIMDE_ARM_SVE_UNDEFINED_SYMBOL(simde_svand_s16)(pg, op1, op2);
  #endif
}
#if defined(SIMDE_ARM_SVE_ENABLE_NATIVE_ALIASES)
  #undef simde_svand_s16_x
  #define svand_s16_x(pg, op1, op2) simde_svand_s16_x(pg, op1, op2)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_svint16_t
simde_svand_n_s16_z(simde_svbool_t pg, simde_svint16_t op1, int16_t op2) {
  #if defined(SIMDE_ARM_SVE_NATIVE)
    return svand_n_s16_z(pg, op1, op2);
  #else
    return simde_svand_s16_z(pg, op1, simde_svdup_n_s16(op2));
  #endif
}
#if defined(SIMDE_ARM_SVE_ENABLE_NATIVE_ALIASES)
  #undef simde_svand_n_s16_z
  #define svand_n_s16_z(pg, op1, op2) simde_svand_n_s16_z(pg, op1, op2)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_svint16_t
simde_svand_n_s16_m(simde_svbool_t pg, simde_svint16_t op1, int16_t op2) {
  #if defined(SIMDE_ARM_SVE_NATIVE)
    return svand_n_s16_m(pg, op1, op2);
  #else
    return simde_svand_s16_m(pg, op1, simde_svdup_n_s16(op2));
  #endif
}
#if defined(SIMDE_ARM_SVE_ENABLE_NATIVE_ALIASES)
  #undef simde_svand_n_s16_m
  #define svand_n_s16_m(pg, op1, op2) simde_svand_n_s16_m(pg, op1, op2)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_svint16_t
simde_svand_n_s16_x(simde_svbool_t pg, simde_svint16_t op1, int16_t op2) {
  #if defined(SIMDE_ARM_SVE_NATIVE)
    return svand_n_s16_x(pg, op1, op2);
  #else
    return simde_svand_s16_x(pg, op1, simde_svdup_n_s16(op2));
  #endif
}
#if defined(SIMDE_ARM_SVE_ENABLE_NATIVE_ALIASES)
  #undef simde_svand_n_s16_x
  #define svand_n_s16_x(pg, op1, op2) simde_svand_n_s16_x(pg, op1, op2)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_svint32_t
simde_svand_s32_z(simde_svbool_t pg, simde_svint32_t op1, simde_svint32_t op2) {
  #if defined(SIMDE_ARM_SVE_NATIVE)
    return svand_s32_z(pg, op1, op2);
  #else
    return simde_svreinterpret_s32_s8(simde_svand_s8_z(pg, simde_svreinterpret_s8_s32(op1), simde_svreinterpret_s8_s32(op2)));
  #endif
}
#if defined(SIMDE_ARM_SVE_ENABLE_NATIVE_ALIASES)
  #undef simde_svand_s32_z
  #define svand_s32_z(pg, op1, op2) simde_svand_s32_z(pg, op1, op2)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_svint32_t
simde_svand_s32_m(simde_svbool_t pg, simde_svint32_t op1, simde_svint32_t op2) {
  #if defined(SIMDE_ARM_SVE_NATIVE)
    return svand_s32_m(pg, op1, op2);
  #else
    return simde_svreinterpret_s32_s8(simde_svand_s8_m(pg, simde_svreinterpret_s8_s32(op1), simde_svreinterpret_s8_s32(op2)));
  #endif
}
#if defined(SIMDE_ARM_SVE_ENABLE_NATIVE_ALIASES)
  #undef simde_svand_s32_m
  #define svand_s32_m(pg, op1, op2) simde_svand_s32_m(pg, op1, op2)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_svint32_t
simde_svand_s32_x(simde_svbool_t pg, simde_svint32_t op1, simde_svint32_t op2) {
  #if defined(SIMDE_ARM_SVE_NATIVE)
    return svand_s32_x(pg, op1, op2);
  #else
    return SIMDE_ARM_SVE_UNDEFINED_SYMBOL(simde_svand_s32)(pg, op1, op2);
  #endif
}
#if defined(SIMDE_ARM_SVE_ENABLE_NATIVE_ALIASES)
  #undef simde_svand_s32_x
  #define svand_s32_x(pg, op1, op2) simde_svand_s32_x(pg, op1, op2)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_svint32_t
simde_svand_n_s32_z(simde_svbool_t pg, simde_svint32_t op1, int32_t op2) {
  #if defined(SIMDE_ARM_SVE_NATIVE)
    return svand_n_s32_z(pg, op1, op2);
  #else
    return simde_svand_s32_z(pg, op1, simde_svdup_n_s32(op2));
  #endif
}
#if defined(SIMDE_ARM_SVE_ENABLE_NATIVE_ALIASES)
  #undef simde_svand_n_s32_z
  #define svand_n_s32_z(pg, op1, op2) simde_svand_n_s32_z(pg, op1, op2)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_svint32_t
simde_svand_n_s32_m(simde_svbool_t pg, simde_svint32_t op1, int32_t op2) {
  #if defined(SIMDE_ARM_SVE_NATIVE)
    return svand_n_s32_m(pg, op1, op2);
  #else
    return simde_svand_s32_m(pg, op1, simde_svdup_n_s32(op2));
  #endif
}
#if defined(SIMDE_ARM_SVE_ENABLE_NATIVE_ALIASES)
  #undef simde_svand_n_s32_m
  #define svand_n_s32_m(pg, op1, op2) simde_svand_n_s32_m(pg, op1, op2)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_svint32_t
simde_svand_n_s32_x(simde_svbool_t pg, simde_svint32_t op1, int32_t op2) {
  #if defined(SIMDE_ARM_SVE_NATIVE)
    return svand_n_s32_x(pg, op1, op2);
  #else
    return simde_svand_s32_x(pg, op1, simde_svdup_n_s32(op2));
  #endif
}
#if defined(SIMDE_ARM_SVE_ENABLE_NATIVE_ALIASES)
  #undef simde_svand_n_s32_x
  #define svand_n_s32_x(pg, op1, op2) simde_svand_n_s32_x(pg, op1, op2)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_svint64_t
simde_svand_s64_z(simde_svbool_t pg, simde_svint64_t op1, simde_svint64_t op2) {
  #if defined(SIMDE_ARM_SVE_NATIVE)
    return svand_s64_z(pg, op1, op2);
  #else
    return simde_svreinterpret_s64_s8(simde_svand_s8_z(pg, simde_svreinterpret_s8_s64(op1), simde_svreinterpret_s8_s64(op2)));
  #endif
}
#if defined(SIMDE_ARM_SVE_ENABLE_NATIVE_ALIASES)
  #undef simde_svand_s64_z
  #define svand_s64_z(pg, op1, op2) simde_svand_s64_z(pg, op1, op2)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_svint64_t
simde_svand_s64_m(simde_svbool_t pg, simde_svint64_t op1, simde_svint64_t op2) {
  #if defined(SIMDE_ARM_SVE_NATIVE)
    return svand_s64_m(pg, op1, op2);
  #else
    return simde_svreinterpret_s64_s8(simde_svand_s8_m(pg, simde_svreinterpret_s8_s64(op1), simde_svreinterpret_s8_s64(op2)));
  #endif
}
#if defined(SIMDE_ARM_SVE_ENABLE_NATIVE_ALIASES)
  #undef simde_svand_s64_m
  #define svand_s64_m(pg, op1, op2) simde_svand_s64_m(pg, op1, op2)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_svint64_t
simde_svand_s64_x(simde_svbool_t pg, simde_svint64_t op1, simde_svint64_t op2) {
  #if defined(SIMDE_ARM_SVE_NATIVE)
    return svand_s64_x(pg, op1, op2);
  #else
    return SIMDE_ARM_SVE_UNDEFINED_SYMBOL(simde_svand_s64)(pg, op1, op2);
  #endif
}
#if defined(SIMDE_ARM_SVE_ENABLE_NATIVE_ALIASES)
  #undef simde_svand_s64_x
  #define svand_s64_x(pg, op1, op2) simde_svand_s64_x(pg, op1, op2)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_svint64_t
simde_svand_n_s64_z(simde_svbool_t pg, simde_svint64_t op1, int64_t op2) {
  #if defined(SIMDE_ARM_SVE_NATIVE)
    return svand_n_s64_z(pg, op1, op2);
  #else
    return simde_svand_s64_z(pg, op1, simde_svdup_n_s64(op2));
  #endif
}
#if defined(SIMDE_ARM_SVE_ENABLE_NATIVE_ALIASES)
  #undef simde_svand_n_s64_z
  #define svand_n_s64_z(pg, op1, op2) simde_svand_n_s64_z(pg, op1, op2)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_svint64_t
simde_svand_n_s64_m(simde_svbool_t pg, simde_svint64_t op1, int64_t op2) {
  #if defined(SIMDE_ARM_SVE_NATIVE)
    return svand_n_s64_m(pg, op1, op2);
  #else
    return simde_svand_s64_m(pg, op1, simde_svdup_n_s64(op2));
  #endif
}
#if defined(SIMDE_ARM_SVE_ENABLE_NATIVE_ALIASES)
  #undef simde_svand_n_s64_m
  #define svand_n_s64_m(pg, op1, op2) simde_svand_n_s64_m(pg, op1, op2)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_svint64_t
simde_svand_n_s64_x(simde_svbool_t pg, simde_svint64_t op1, int64_t op2) {
  #if defined(SIMDE_ARM_SVE_NATIVE)
    return svand_n_s64_x(pg, op1, op2);
  #else
    return simde_svand_s64_x(pg, op1, simde_svdup_n_s64(op2));
  #endif
}
#if defined(SIMDE_ARM_SVE_ENABLE_NATIVE_ALIASES)
  #undef simde_svand_n_s64_x
  #define svand_n_s64_x(pg, op1, op2) simde_svand_n_s64_x(pg, op1, op2)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_svuint8_t
simde_svand_u8_z(simde_svbool_t pg, simde_svuint8_t op1, simde_svuint8_t op2) {
  #if defined(SIMDE_ARM_SVE_NATIVE)
    return svand_u8_z(pg, op1, op2);
  #else
    return simde_svreinterpret_u8_s8(simde_svand_s8_z(pg, simde_svreinterpret_s8_u8(op1), simde_svreinterpret_s8_u8(op2)));
  #endif
}
#if defined(SIMDE_ARM_SVE_ENABLE_NATIVE_ALIASES)
  #undef simde_svand_u8_z
  #define svand_u8_z(pg, op1, op2) simde_svand_u8_z(pg, op1, op2)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_svuint8_t
simde_svand_u8_m(simde_svbool_t pg, simde_svuint8_t op1, simde_svuint8_t op2) {
  #if defined(SIMDE_ARM_SVE_NATIVE)
    return svand_u8_m(pg, op1, op2);
  #else
    return simde_svreinterpret_u8_s8(simde_svand_s8_m(pg, simde_svreinterpret_s8_u8(op1), simde_svreinterpret_s8_u8(op2)));
  #endif
}
#if defined(SIMDE_ARM_SVE_ENABLE_NATIVE_ALIASES)
  #undef simde_svand_u8_m
  #define svand_u8_m(pg, op1, op2) simde_svand_u8_m(pg, op1, op2)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_svuint8_t
simde_svand_u8_x(simde_svbool_t pg, simde_svuint8_t op1, simde_svuint8_t op2) {
  #if defined(SIMDE_ARM_SVE_NATIVE)
    return svand_u8_x(pg, op1, op2);
  #else
    return SIMDE_ARM_SVE_UNDEFINED_SYMBOL(simde_svand_u8)(pg, op1, op2);
  #endif
}
#if defined(SIMDE_ARM_SVE_ENABLE_NATIVE_ALIASES)
  #undef simde_svand_u8_x
  #define svand_u8_x(pg, op1, op2) simde_svand_u8_x(pg, op1, op2)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_svuint8_t
simde_svand_n_u8_z(simde_svbool_t pg, simde_svuint8_t op1, uint8_t op2) {
  #if defined(SIMDE_ARM_SVE_NATIVE)
    return svand_n_u8_z(pg, op1, op2);
  #else
    return simde_svand_u8_z(pg, op1, simde_svdup_n_u8(op2));
  #endif
}
#if defined(SIMDE_ARM_SVE_ENABLE_NATIVE_ALIASES)
  #undef simde_svand_n_u8_z
  #define svand_n_u8_z(pg, op1, op2) simde_svand_n_u8_z(pg, op1, op2)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_svuint8_t
simde_svand_n_u8_m(simde_svbool_t pg, simde_svuint8_t op1, uint8_t op2) {
  #if defined(SIMDE_ARM_SVE_NATIVE)
    return svand_n_u8_m(pg, op1, op2);
  #else
    return simde_svand_u8_m(pg, op1, simde_svdup_n_u8(op2));
  #endif
}
#if defined(SIMDE_ARM_SVE_ENABLE_NATIVE_ALIASES)
  #undef simde_svand_n_u8_m
  #define svand_n_u8_m(pg, op1, op2) simde_svand_n_u8_m(pg, op1, op2)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_svuint8_t
simde_svand_n_u8_x(simde_svbool_t pg, simde_svuint8_t op1, uint8_t op2) {
  #if defined(SIMDE_ARM_SVE_NATIVE)
    return svand_n_u8_x(pg, op1, op2);
  #else
    return simde_svand_u8_x(pg, op1, simde_svdup_n_u8(op2));
  #endif
}
#if defined(SIMDE_ARM_SVE_ENABLE_NATIVE_ALIASES)
  #undef simde_svand_n_u8_x
  #define svand_n_u8_x(pg, op1, op2) simde_svand_n_u8_x(pg, op1, op2)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_svuint16_t
simde_svand_u16_z(simde_svbool_t pg, simde_svuint16_t op1, simde_svuint16_t op2) {
  #if defined(SIMDE_ARM_SVE_NATIVE)
    return svand_u16_z(pg, op1, op2);
  #else
    return simde_svreinterpret_u16_s8(simde_svand_s8_z(pg, simde_svreinterpret_s8_u16(op1), simde_svreinterpret_s8_u16(op2)));
  #endif
}
#if defined(SIMDE_ARM_SVE_ENABLE_NATIVE_ALIASES)
  #undef simde_svand_u16_z
  #define svand_u16_z(pg, op1, op2) simde_svand_u16_z(pg, op1, op2)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_svuint16_t
simde_svand_u16_m(simde_svbool_t pg, simde_svuint16_t op1, simde_svuint16_t op2) {
  #if defined(SIMDE_ARM_SVE_NATIVE)
    return svand_u16_m(pg, op1, op2);
  #else
    return simde_svreinterpret_u16_s8(simde_svand_s8_m(pg, simde_svreinterpret_s8_u16(op1), simde_svreinterpret_s8_u16(op2)));
  #endif
}
#if defined(SIMDE_ARM_SVE_ENABLE_NATIVE_ALIASES)
  #undef simde_svand_u16_m
  #define svand_u16_m(pg, op1, op2) simde_svand_u16_m(pg, op1, op2)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_svuint16_t
simde_svand_u16_x(simde_svbool_t pg, simde_svuint16_t op1, simde_svuint16_t op2) {
  #if defined(SIMDE_ARM_SVE_NATIVE)
    return svand_u16_x(pg, op1, op2);
  #else
    return SIMDE_ARM_SVE_UNDEFINED_SYMBOL(simde_svand_u16)(pg, op1, op2);
  #endif
}
#if defined(SIMDE_ARM_SVE_ENABLE_NATIVE_ALIASES)
  #undef simde_svand_u16_x
  #define svand_u16_x(pg, op1, op2) simde_svand_u16_x(pg, op1, op2)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_svuint16_t
simde_svand_n_u16_z(simde_svbool_t pg, simde_svuint16_t op1, uint16_t op2) {
  #if defined(SIMDE_ARM_SVE_NATIVE)
    return svand_n_u16_z(pg, op1, op2);
  #else
    return simde_svand_u16_z(pg, op1, simde_svdup_n_u16(op2));
  #endif
}
#if defined(SIMDE_ARM_SVE_ENABLE_NATIVE_ALIASES)
  #undef simde_svand_n_u16_z
  #define svand_n_u16_z(pg, op1, op2) simde_svand_n_u16_z(pg, op1, op2)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_svuint16_t
simde_svand_n_u16_m(simde_svbool_t pg, simde_svuint16_t op1, uint16_t op2) {
  #if defined(SIMDE_ARM_SVE_NATIVE)
    return svand_n_u16_m(pg, op1, op2);
  #else
    return simde_svand_u16_m(pg, op1, simde_svdup_n_u16(op2));
  #endif
}
#if defined(SIMDE_ARM_SVE_ENABLE_NATIVE_ALIASES)
  #undef simde_svand_n_u16_m
  #define svand_n_u16_m(pg, op1, op2) simde_svand_n_u16_m(pg, op1, op2)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_svuint16_t
simde_svand_n_u16_x(simde_svbool_t pg, simde_svuint16_t op1, uint16_t op2) {
  #if defined(SIMDE_ARM_SVE_NATIVE)
    return svand_n_u16_x(pg, op1, op2);
  #else
    return simde_svand_u16_x(pg, op1, simde_svdup_n_u16(op2));
  #endif
}
#if defined(SIMDE_ARM_SVE_ENABLE_NATIVE_ALIASES)
  #undef simde_svand_n_u16_x
  #define svand_n_u16_x(pg, op1, op2) simde_svand_n_u16_x(pg, op1, op2)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_svuint32_t
simde_svand_u32_z(simde_svbool_t pg, simde_svuint32_t op1, simde_svuint32_t op2) {
  #if defined(SIMDE_ARM_SVE_NATIVE)
    return svand_u32_z(pg, op1, op2);
  #else
    return simde_svreinterpret_u32_s8(simde_svand_s8_z(pg, simde_svreinterpret_s8_u32(op1), simde_svreinterpret_s8_u32(op2)));
  #endif
}
#if defined(SIMDE_ARM_SVE_ENABLE_NATIVE_ALIASES)
  #undef simde_svand_u32_z
  #define svand_u32_z(pg, op1, op2) simde_svand_u32_z(pg, op1, op2)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_svuint32_t
simde_svand_u32_m(simde_svbool_t pg, simde_svuint32_t op1, simde_svuint32_t op2) {
  #if defined(SIMDE_ARM_SVE_NATIVE)
    return svand_u32_m(pg, op1, op2);
  #else
    return simde_svreinterpret_u32_s8(simde_svand_s8_m(pg, simde_svreinterpret_s8_u32(op1), simde_svreinterpret_s8_u32(op2)));
  #endif
}
#if defined(SIMDE_ARM_SVE_ENABLE_NATIVE_ALIASES)
  #undef simde_svand_u32_m
  #define svand_u32_m(pg, op1, op2) simde_svand_u32_m(pg, op1, op2)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_svuint32_t
simde_svand_u32_x(simde_svbool_t pg, simde_svuint32_t op1, simde_svuint32_t op2) {
  #if defined(SIMDE_ARM_SVE_NATIVE)
    return svand_u32_x(pg, op1, op2);
  #else
    return SIMDE_ARM_SVE_UNDEFINED_SYMBOL(simde_svand_u32)(pg, op1, op2);
  #endif
}
#if defined(SIMDE_ARM_SVE_ENABLE_NATIVE_ALIASES)
  #undef simde_svand_u32_x
  #define svand_u32_x(pg, op1, op2) simde_svand_u32_x(pg, op1, op2)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_svuint32_t
simde_svand_n_u32_z(simde_svbool_t pg, simde_svuint32_t op1, uint32_t op2) {
  #if defined(SIMDE_ARM_SVE_NATIVE)
    return svand_n_u32_z(pg, op1, op2);
  #else
    return simde_svand_u32_z(pg, op1, simde_svdup_n_u32(op2));
  #endif
}
#if defined(SIMDE_ARM_SVE_ENABLE_NATIVE_ALIASES)
  #undef simde_svand_n_u32_z
  #define svand_n_u32_z(pg, op1, op2) simde_svand_n_u32_z(pg, op1, op2)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_svuint32_t
simde_svand_n_u32_m(simde_svbool_t pg, simde_svuint32_t op1, uint32_t op2) {
  #if defined(SIMDE_ARM_SVE_NATIVE)
    return svand_n_u32_m(pg, op1, op2);
  #else
    return simde_svand_u32_m(pg, op1, simde_svdup_n_u32(op2));
  #endif
}
#if defined(SIMDE_ARM_SVE_ENABLE_NATIVE_ALIASES)
  #undef simde_svand_n_u32_m
  #define svand_n_u32_m(pg, op1, op2) simde_svand_n_u32_m(pg, op1, op2)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_svuint32_t
simde_svand_n_u32_x(simde_svbool_t pg, simde_svuint32_t op1, uint32_t op2) {
  #if defined(SIMDE_ARM_SVE_NATIVE)
    return svand_n_u32_x(pg, op1, op2);
  #else
    return simde_svand_u32_x(pg, op1, simde_svdup_n_u32(op2));
  #endif
}
#if defined(SIMDE_ARM_SVE_ENABLE_NATIVE_ALIASES)
  #undef simde_svand_n_u32_x
  #define svand_n_u32_x(pg, op1, op2) simde_svand_n_u32_x(pg, op1, op2)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_svuint64_t
simde_svand_u64_z(simde_svbool_t pg, simde_svuint64_t op1, simde_svuint64_t op2) {
  #if defined(SIMDE_ARM_SVE_NATIVE)
    return svand_u64_z(pg, op1, op2);
  #else
    return simde_svreinterpret_u64_s8(simde_svand_s8_z(pg, simde_svreinterpret_s8_u64(op1), simde_svreinterpret_s8_u64(op2)));
  #endif
}
#if defined(SIMDE_ARM_SVE_ENABLE_NATIVE_ALIASES)
  #undef simde_svand_u64_z
  #define svand_u64_z(pg, op1, op2) simde_svand_u64_z(pg, op1, op2)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_svuint64_t
simde_svand_u64_m(simde_svbool_t pg, simde_svuint64_t op1, simde_svuint64_t op2) {
  #if defined(SIMDE_ARM_SVE_NATIVE)
    return svand_u64_m(pg, op1, op2);
  #else
    return simde_svreinterpret_u64_s8(simde_svand_s8_m(pg, simde_svreinterpret_s8_u64(op1), simde_svreinterpret_s8_u64(op2)));
  #endif
}
#if defined(SIMDE_ARM_SVE_ENABLE_NATIVE_ALIASES)
  #undef simde_svand_u64_m
  #define svand_u64_m(pg, op1, op2) simde_svand_u64_m(pg, op1, op2)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_svuint64_t
simde_svand_u64_x(simde_svbool_t pg, simde_svuint64_t op1, simde_svuint64_t op2) {
  #if defined(SIMDE_ARM_SVE_NATIVE)
    return svand_u64_x(pg, op1, op2);
  #else
    return SIMDE_ARM_SVE_UNDEFINED_SYMBOL(simde_svand_u64)(pg, op1, op2);
  #endif
}
#if defined(SIMDE_ARM_SVE_ENABLE_NATIVE_ALIASES)
  #undef simde_svand_u64_x
  #define svand_u64_x(pg, op1, op2) simde_svand_u64_x(pg, op1, op2)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_svuint64_t
simde_svand_n_u64_z(simde_svbool_t pg, simde_svuint64_t op1, uint64_t op2) {
  #if defined(SIMDE_ARM_SVE_NATIVE)
    return svand_n_u64_z(pg, op1, op2);
  #else
    return simde_svand_u64_z(pg, op1, simde_svdup_n_u64(op2));
  #endif
}
#if defined(SIMDE_ARM_SVE_ENABLE_NATIVE_ALIASES)
  #undef simde_svand_n_u64_z
  #define svand_n_u64_x(pg, op1, op2) simde_svand_n_u64_x(pg, op1, op2)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_svuint64_t
simde_svand_n_u64_m(simde_svbool_t pg, simde_svuint64_t op1, uint64_t op2) {
  #if defined(SIMDE_ARM_SVE_NATIVE)
    return svand_n_u64_m(pg, op1, op2);
  #else
    return simde_svand_u64_m(pg, op1, simde_svdup_n_u64(op2));
  #endif
}
#if defined(SIMDE_ARM_SVE_ENABLE_NATIVE_ALIASES)
  #undef simde_svand_n_u64_m
  #define svand_n_u64_x(pg, op1, op2) simde_svand_n_u64_x(pg, op1, op2)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_svuint64_t
simde_svand_n_u64_x(simde_svbool_t pg, simde_svuint64_t op1, uint64_t op2) {
  #if defined(SIMDE_ARM_SVE_NATIVE)
    return svand_n_u64_x(pg, op1, op2);
  #else
    return simde_svand_u64_x(pg, op1, simde_svdup_n_u64(op2));
  #endif
}
#if defined(SIMDE_ARM_SVE_ENABLE_NATIVE_ALIASES)
  #undef simde_svand_n_u64_x
  #define svand_n_u64_x(pg, op1, op2) simde_svand_n_u64_x(pg, op1, op2)
#endif

#if defined(__cplusplus)
  SIMDE_FUNCTION_ATTRIBUTES    simde_svint8_t simde_svand_z(simde_svbool_t pg,    simde_svint8_t op1,    simde_svint8_t op2) { return simde_svand_s8_z (pg, op1, op2); }
  SIMDE_FUNCTION_ATTRIBUTES   simde_svint16_t simde_svand_z(simde_svbool_t pg,   simde_svint16_t op1,   simde_svint16_t op2) { return simde_svand_s16_z(pg, op1, op2); }
  SIMDE_FUNCTION_ATTRIBUTES   simde_svint32_t simde_svand_z(simde_svbool_t pg,   simde_svint32_t op1,   simde_svint32_t op2) { return simde_svand_s32_z(pg, op1, op2); }
  SIMDE_FUNCTION_ATTRIBUTES   simde_svint64_t simde_svand_z(simde_svbool_t pg,   simde_svint64_t op1,   simde_svint64_t op2) { return simde_svand_s64_z(pg, op1, op2); }
  SIMDE_FUNCTION_ATTRIBUTES   simde_svuint8_t simde_svand_z(simde_svbool_t pg,   simde_svuint8_t op1,   simde_svuint8_t op2) { return simde_svand_u8_z (pg, op1, op2); }
  SIMDE_FUNCTION_ATTRIBUTES  simde_svuint16_t simde_svand_z(simde_svbool_t pg,  simde_svuint16_t op1,  simde_svuint16_t op2) { return simde_svand_u16_z(pg, op1, op2); }
  SIMDE_FUNCTION_ATTRIBUTES  simde_svuint32_t simde_svand_z(simde_svbool_t pg,  simde_svuint32_t op1,  simde_svuint32_t op2) { return simde_svand_u32_z(pg, op1, op2); }
  SIMDE_FUNCTION_ATTRIBUTES  simde_svuint64_t simde_svand_z(simde_svbool_t pg,  simde_svuint64_t op1,  simde_svuint64_t op2) { return simde_svand_u64_z(pg, op1, op2); }

  SIMDE_FUNCTION_ATTRIBUTES    simde_svint8_t simde_svand_m(simde_svbool_t pg,    simde_svint8_t op1,    simde_svint8_t op2) { return simde_svand_s8_m (pg, op1, op2); }
  SIMDE_FUNCTION_ATTRIBUTES   simde_svint16_t simde_svand_m(simde_svbool_t pg,   simde_svint16_t op1,   simde_svint16_t op2) { return simde_svand_s16_m(pg, op1, op2); }
  SIMDE_FUNCTION_ATTRIBUTES   simde_svint32_t simde_svand_m(simde_svbool_t pg,   simde_svint32_t op1,   simde_svint32_t op2) { return simde_svand_s32_m(pg, op1, op2); }
  SIMDE_FUNCTION_ATTRIBUTES   simde_svint64_t simde_svand_m(simde_svbool_t pg,   simde_svint64_t op1,   simde_svint64_t op2) { return simde_svand_s64_m(pg, op1, op2); }
  SIMDE_FUNCTION_ATTRIBUTES   simde_svuint8_t simde_svand_m(simde_svbool_t pg,   simde_svuint8_t op1,   simde_svuint8_t op2) { return simde_svand_u8_m (pg, op1, op2); }
  SIMDE_FUNCTION_ATTRIBUTES  simde_svuint16_t simde_svand_m(simde_svbool_t pg,  simde_svuint16_t op1,  simde_svuint16_t op2) { return simde_svand_u16_m(pg, op1, op2); }
  SIMDE_FUNCTION_ATTRIBUTES  simde_svuint32_t simde_svand_m(simde_svbool_t pg,  simde_svuint32_t op1,  simde_svuint32_t op2) { return simde_svand_u32_m(pg, op1, op2); }
  SIMDE_FUNCTION_ATTRIBUTES  simde_svuint64_t simde_svand_m(simde_svbool_t pg,  simde_svuint64_t op1,  simde_svuint64_t op2) { return simde_svand_u64_m(pg, op1, op2); }

  SIMDE_FUNCTION_ATTRIBUTES    simde_svint8_t simde_svand_x(simde_svbool_t pg,    simde_svint8_t op1,    simde_svint8_t op2) { return simde_svand_s8_x (pg, op1, op2); }
  SIMDE_FUNCTION_ATTRIBUTES   simde_svint16_t simde_svand_x(simde_svbool_t pg,   simde_svint16_t op1,   simde_svint16_t op2) { return simde_svand_s16_x(pg, op1, op2); }
  SIMDE_FUNCTION_ATTRIBUTES   simde_svint32_t simde_svand_x(simde_svbool_t pg,   simde_svint32_t op1,   simde_svint32_t op2) { return simde_svand_s32_x(pg, op1, op2); }
  SIMDE_FUNCTION_ATTRIBUTES   simde_svint64_t simde_svand_x(simde_svbool_t pg,   simde_svint64_t op1,   simde_svint64_t op2) { return simde_svand_s64_x(pg, op1, op2); }
  SIMDE_FUNCTION_ATTRIBUTES   simde_svuint8_t simde_svand_x(simde_svbool_t pg,   simde_svuint8_t op1,   simde_svuint8_t op2) { return simde_svand_u8_x (pg, op1, op2); }
  SIMDE_FUNCTION_ATTRIBUTES  simde_svuint16_t simde_svand_x(simde_svbool_t pg,  simde_svuint16_t op1,  simde_svuint16_t op2) { return simde_svand_u16_x(pg, op1, op2); }
  SIMDE_FUNCTION_ATTRIBUTES  simde_svuint32_t simde_svand_x(simde_svbool_t pg,  simde_svuint32_t op1,  simde_svuint32_t op2) { return simde_svand_u32_x(pg, op1, op2); }
  SIMDE_FUNCTION_ATTRIBUTES  simde_svuint64_t simde_svand_x(simde_svbool_t pg,  simde_svuint64_t op1,  simde_svuint64_t op2) { return simde_svand_u64_x(pg, op1, op2); }

  SIMDE_FUNCTION_ATTRIBUTES    simde_svint8_t simde_svand_z(simde_svbool_t pg,    simde_svint8_t op1,    int8_t op2) { return  simde_svand_n_s8_z(pg, op1, op2); }
  SIMDE_FUNCTION_ATTRIBUTES   simde_svint16_t simde_svand_z(simde_svbool_t pg,   simde_svint16_t op1,   int16_t op2) { return simde_svand_n_s16_z(pg, op1, op2); }
  SIMDE_FUNCTION_ATTRIBUTES   simde_svint32_t simde_svand_z(simde_svbool_t pg,   simde_svint32_t op1,   int32_t op2) { return simde_svand_n_s32_z(pg, op1, op2); }
  SIMDE_FUNCTION_ATTRIBUTES   simde_svint64_t simde_svand_z(simde_svbool_t pg,   simde_svint64_t op1,   int64_t op2) { return simde_svand_n_s64_z(pg, op1, op2); }
  SIMDE_FUNCTION_ATTRIBUTES   simde_svuint8_t simde_svand_z(simde_svbool_t pg,   simde_svuint8_t op1,   uint8_t op2) { return  simde_svand_n_u8_z(pg, op1, op2); }
  SIMDE_FUNCTION_ATTRIBUTES  simde_svuint16_t simde_svand_z(simde_svbool_t pg,  simde_svuint16_t op1,  uint16_t op2) { return simde_svand_n_u16_z(pg, op1, op2); }
  SIMDE_FUNCTION_ATTRIBUTES  simde_svuint32_t simde_svand_z(simde_svbool_t pg,  simde_svuint32_t op1,  uint32_t op2) { return simde_svand_n_u32_z(pg, op1, op2); }
  SIMDE_FUNCTION_ATTRIBUTES  simde_svuint64_t simde_svand_z(simde_svbool_t pg,  simde_svuint64_t op1,  uint64_t op2) { return simde_svand_n_u64_z(pg, op1, op2); }

  SIMDE_FUNCTION_ATTRIBUTES    simde_svint8_t simde_svand_m(simde_svbool_t pg,    simde_svint8_t op1,    int8_t op2) { return  simde_svand_n_s8_m(pg, op1, op2); }
  SIMDE_FUNCTION_ATTRIBUTES   simde_svint16_t simde_svand_m(simde_svbool_t pg,   simde_svint16_t op1,   int16_t op2) { return simde_svand_n_s16_m(pg, op1, op2); }
  SIMDE_FUNCTION_ATTRIBUTES   simde_svint32_t simde_svand_m(simde_svbool_t pg,   simde_svint32_t op1,   int32_t op2) { return simde_svand_n_s32_m(pg, op1, op2); }
  SIMDE_FUNCTION_ATTRIBUTES   simde_svint64_t simde_svand_m(simde_svbool_t pg,   simde_svint64_t op1,   int64_t op2) { return simde_svand_n_s64_m(pg, op1, op2); }
  SIMDE_FUNCTION_ATTRIBUTES   simde_svuint8_t simde_svand_m(simde_svbool_t pg,   simde_svuint8_t op1,   uint8_t op2) { return  simde_svand_n_u8_m(pg, op1, op2); }
  SIMDE_FUNCTION_ATTRIBUTES  simde_svuint16_t simde_svand_m(simde_svbool_t pg,  simde_svuint16_t op1,  uint16_t op2) { return simde_svand_n_u16_m(pg, op1, op2); }
  SIMDE_FUNCTION_ATTRIBUTES  simde_svuint32_t simde_svand_m(simde_svbool_t pg,  simde_svuint32_t op1,  uint32_t op2) { return simde_svand_n_u32_m(pg, op1, op2); }
  SIMDE_FUNCTION_ATTRIBUTES  simde_svuint64_t simde_svand_m(simde_svbool_t pg,  simde_svuint64_t op1,  uint64_t op2) { return simde_svand_n_u64_m(pg, op1, op2); }

  SIMDE_FUNCTION_ATTRIBUTES    simde_svint8_t simde_svand_x(simde_svbool_t pg,    simde_svint8_t op1,    int8_t op2) { return  simde_svand_n_s8_x(pg, op1, op2); }
  SIMDE_FUNCTION_ATTRIBUTES   simde_svint16_t simde_svand_x(simde_svbool_t pg,   simde_svint16_t op1,   int16_t op2) { return simde_svand_n_s16_x(pg, op1, op2); }
  SIMDE_FUNCTION_ATTRIBUTES   simde_svint32_t simde_svand_x(simde_svbool_t pg,   simde_svint32_t op1,   int32_t op2) { return simde_svand_n_s32_x(pg, op1, op2); }
  SIMDE_FUNCTION_ATTRIBUTES   simde_svint64_t simde_svand_x(simde_svbool_t pg,   simde_svint64_t op1,   int64_t op2) { return simde_svand_n_s64_x(pg, op1, op2); }
  SIMDE_FUNCTION_ATTRIBUTES   simde_svuint8_t simde_svand_x(simde_svbool_t pg,   simde_svuint8_t op1,   uint8_t op2) { return  simde_svand_n_u8_x(pg, op1, op2); }
  SIMDE_FUNCTION_ATTRIBUTES  simde_svuint16_t simde_svand_x(simde_svbool_t pg,  simde_svuint16_t op1,  uint16_t op2) { return simde_svand_n_u16_x(pg, op1, op2); }
  SIMDE_FUNCTION_ATTRIBUTES  simde_svuint32_t simde_svand_x(simde_svbool_t pg,  simde_svuint32_t op1,  uint32_t op2) { return simde_svand_n_u32_x(pg, op1, op2); }
  SIMDE_FUNCTION_ATTRIBUTES  simde_svuint64_t simde_svand_x(simde_svbool_t pg,  simde_svuint64_t op1,  uint64_t op2) { return simde_svand_n_u64_x(pg, op1, op2); }
#elif defined(SIMDE_GENERIC_)
  #define simde_svand_z(pg, op1, op2) \
    (SIMDE_GENERIC_((op2), \
         simde_svint8_t: simde_svand_s8_z, \
        simde_svint16_t: simde_svand_s16_z, \
        simde_svint32_t: simde_svand_s32_z, \
        simde_svint64_t: simde_svand_s64_z, \
        simde_svuint8_t: simde_svand_u8_z, \
       simde_svuint16_t: simde_svand_u16_z, \
       simde_svuint32_t: simde_svand_u32_z, \
       simde_svuint64_t: simde_svand_u64_z, \
                 int8_t: simde_svand_n_s8_z, \
                int16_t: simde_svand_n_s16_z, \
                int32_t: simde_svand_n_s32_z, \
                int64_t: simde_svand_n_s64_z, \
                uint8_t: simde_svand_n_u8_z, \
               uint16_t: simde_svand_n_u16_z, \
               uint32_t: simde_svand_n_u32_z, \
               uint64_t: simde_svand_n_u64_z)((pg), (op1), (op2)))

  #define simde_svand_m(pg, op1, op2) \
    (SIMDE_GENERIC_((op2), \
         simde_svint8_t: simde_svand_s8_m, \
        simde_svint16_t: simde_svand_s16_m, \
        simde_svint32_t: simde_svand_s32_m, \
        simde_svint64_t: simde_svand_s64_m, \
        simde_svuint8_t: simde_svand_u8_m, \
       simde_svuint16_t: simde_svand_u16_m, \
       simde_svuint32_t: simde_svand_u32_m, \
       simde_svuint64_t: simde_svand_u64_m, \
                 int8_t: simde_svand_n_s8_m, \
                int16_t: simde_svand_n_s16_m, \
                int32_t: simde_svand_n_s32_m, \
                int64_t: simde_svand_n_s64_m, \
                uint8_t: simde_svand_n_u8_m, \
               uint16_t: simde_svand_n_u16_m, \
               uint32_t: simde_svand_n_u32_m, \
               uint64_t: simde_svand_n_u64_m)((pg), (op1), (op2)))

  #define simde_svand_x(pg, op1, op2) \
    (SIMDE_GENERIC_((op2), \
         simde_svint8_t: simde_svand_s8_x, \
        simde_svint16_t: simde_svand_s16_x, \
        simde_svint32_t: simde_svand_s32_x, \
        simde_svint64_t: simde_svand_s64_x, \
        simde_svuint8_t: simde_svand_u8_x, \
       simde_svuint16_t: simde_svand_u16_x, \
       simde_svuint32_t: simde_svand_u32_x, \
       simde_svuint64_t: simde_svand_u64_x, \
                 int8_t: simde_svand_n_s8_x, \
                int16_t: simde_svand_n_s16_x, \
                int32_t: simde_svand_n_s32_x, \
                int64_t: simde_svand_n_s64_x, \
                uint8_t: simde_svand_n_u8_x, \
               uint16_t: simde_svand_n_u16_x, \
               uint32_t: simde_svand_n_u32_x, \
               uint64_t: simde_svand_n_u64_x)((pg), (op1), (op2)))
#endif

HEDLEY_DIAGNOSTIC_POP

#endif /* SIMDE_ARM_SVE_AND_H */
