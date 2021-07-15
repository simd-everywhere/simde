#if !defined(SIMDE_X86_AVX512_DPBUSD_H)
#define SIMDE_X86_AVX512_DPBUSD_H

#include "types.h"
#include "mov.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_dpbusd_epi32(simde__m128i src, simde__m128i a, simde__m128i b) {
  #if defined(SIMDE_X86_AVX512VL_NATIVE) && defined(SIMDE_X86_AVX512VNNI_NATIVE)
    return _mm_dpbusd_epi32(src, a, b);
  #else
    simde__m128i_private
      src_ = simde__m128i_to_private(src),
      a_ = simde__m128i_to_private(a),
      b_ = simde__m128i_to_private(b);
    #if defined(SIMDE_SHUFFLE_VECTOR_) && defined(SIMDE_CONVERT_VECTOR_)
      simde__m512i_private
        r1_,
        r2_;

      a_.u8 =
        SIMDE_SHUFFLE_VECTOR_(
          8, 16,
          a_.u8, a_.u8,
           0,  4,  8, 12,
           1,  5,  9, 13,
           2,  6, 10, 14,
           3,  7, 11, 15
        );
      b_.i8 =
        SIMDE_SHUFFLE_VECTOR_(
          8, 16,
          b_.i8, b_.i8,
           0,  4,  8, 12,
           1,  5,  9, 13,
           2,  6, 10, 14,
           3,  7, 11, 15
        );

      SIMDE_CONVERT_VECTOR_(r1_.u32, a_.u8);
      SIMDE_CONVERT_VECTOR_(r2_.i32, b_.i8);

      src_.i32 +=
        (HEDLEY_REINTERPRET_CAST(__typeof__(a_.i32), r1_.m128i_private[0].u32) * r2_.m128i_private[0].i32) +
        (HEDLEY_REINTERPRET_CAST(__typeof__(a_.i32), r1_.m128i_private[1].u32) * r2_.m128i_private[1].i32) +
        (HEDLEY_REINTERPRET_CAST(__typeof__(a_.i32), r1_.m128i_private[2].u32) * r2_.m128i_private[2].i32) +
        (HEDLEY_REINTERPRET_CAST(__typeof__(a_.i32), r1_.m128i_private[3].u32) * r2_.m128i_private[3].i32);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(a_.u8) / sizeof(a_.u8[0])) ; i++) {
        src_.i32[i / 4] += HEDLEY_STATIC_CAST(uint16_t, a_.u8[i]) * HEDLEY_STATIC_CAST(int16_t, b_.i8[i]);
      }
    #endif

    return simde__m128i_from_private(src_);
  #endif
}
#if defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VNNI_ENABLE_NATIVE_ALIASES)
  #undef _mm_dpbusd_epi32
  #define _mm_dpbusd_epi32(src, a, b) simde_mm_dpbusd_epi32(src, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_mask_dpbusd_epi32(simde__m128i src, simde__mmask8 k, simde__m128i a, simde__m128i b) {
  #if defined(SIMDE_X86_AVX512VL_NATIVE) && defined(SIMDE_X86_AVX512VNNI_NATIVE)
    return _mm_mask_dpbusd_epi32(src, k, a, b);
  #else
    return simde_mm_mask_mov_epi32(src, k, simde_mm_dpbusd_epi32(src, a, b));
  #endif
}
#if defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VNNI_ENABLE_NATIVE_ALIASES)
  #undef _mm_mask_dpbusd_epi32
  #define _mm_mask_dpbusd_epi32(src, k, a, b) simde_mm_mask_dpbusd_epi32(src, k, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_maskz_dpbusd_epi32(simde__mmask8 k, simde__m128i src, simde__m128i a, simde__m128i b) {
  #if defined(SIMDE_X86_AVX512VL_NATIVE) && defined(SIMDE_X86_AVX512VNNI_NATIVE)
    return _mm_maskz_dpbusd_epi32(k, src, a, b);
  #else
    return simde_mm_maskz_mov_epi32(k, simde_mm_dpbusd_epi32(src, a, b));
  #endif
}
#if defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VNNI_ENABLE_NATIVE_ALIASES)
  #undef _mm_maskz_dpbusd_epi32
  #define _mm_maskz_dpbusd_epi32(k, src, a, b) simde_mm_maskz_dpbusd_epi32(k, src, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_dpbusd_epi32(simde__m256i src, simde__m256i a, simde__m256i b) {
  #if defined(SIMDE_X86_AVX512VL_NATIVE) && defined(SIMDE_X86_AVX512VNNI_NATIVE)
    return _mm256_dpbusd_epi32(src, a, b);
  #else
    simde__m256i_private
      src_ = simde__m256i_to_private(src),
      a_ = simde__m256i_to_private(a),
      b_ = simde__m256i_to_private(b);
    #if defined(SIMDE_SHUFFLE_VECTOR_) && defined(SIMDE_CONVERT_VECTOR_)
      union {
        uint32_t u32 SIMDE_VECTOR(128);
        int32_t  i32 SIMDE_VECTOR(128);
        simde__m256i_private m256i_private[4];
      } r1_, r2_;

      a_.u8 =
        SIMDE_SHUFFLE_VECTOR_(
          8, 32,
          a_.u8, a_.u8,
           0,  4,  8, 12, 16, 20, 24, 28,
           1,  5,  9, 13, 17, 21, 25, 29,
           2,  6, 10, 14, 18, 22, 26, 30,
           3,  7, 11, 15, 19, 23, 27, 31
        );
      b_.i8 =
        SIMDE_SHUFFLE_VECTOR_(
          8, 32,
          b_.i8, b_.i8,
           0,  4,  8, 12, 16, 20, 24, 28,
           1,  5,  9, 13, 17, 21, 25, 29,
           2,  6, 10, 14, 18, 22, 26, 30,
           3,  7, 11, 15, 19, 23, 27, 31
        );

      SIMDE_CONVERT_VECTOR_(r1_.u32, a_.u8);
      SIMDE_CONVERT_VECTOR_(r2_.i32, b_.i8);

      src_.i32 +=
        (HEDLEY_REINTERPRET_CAST(__typeof__(a_.i32), r1_.m256i_private[0].u32) * r2_.m256i_private[0].i32) +
        (HEDLEY_REINTERPRET_CAST(__typeof__(a_.i32), r1_.m256i_private[1].u32) * r2_.m256i_private[1].i32) +
        (HEDLEY_REINTERPRET_CAST(__typeof__(a_.i32), r1_.m256i_private[2].u32) * r2_.m256i_private[2].i32) +
        (HEDLEY_REINTERPRET_CAST(__typeof__(a_.i32), r1_.m256i_private[3].u32) * r2_.m256i_private[3].i32);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(a_.u8) / sizeof(a_.u8[0])) ; i++) {
        src_.i32[i / 4] += HEDLEY_STATIC_CAST(uint16_t, a_.u8[i]) * HEDLEY_STATIC_CAST(int16_t, b_.i8[i]);
      }
    #endif

    return simde__m256i_from_private(src_);
  #endif
}
#if defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VNNI_ENABLE_NATIVE_ALIASES)
  #undef _mm256_dpbusd_epi32
  #define _mm256_dpbusd_epi32(src, a, b) simde_mm256_dpbusd_epi32(src, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_mask_dpbusd_epi32(simde__m256i src, simde__mmask8 k, simde__m256i a, simde__m256i b) {
  #if defined(SIMDE_X86_AVX512VL_NATIVE) && defined(SIMDE_X86_AVX512VNNI_NATIVE)
    return _mm256_mask_dpbusd_epi32(src, k, a, b);
  #else
    return simde_mm256_mask_mov_epi32(src, k, simde_mm256_dpbusd_epi32(src, a, b));
  #endif
}
#if defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VNNI_ENABLE_NATIVE_ALIASES)
  #undef _mm256_mask_dpbusd_epi32
  #define _mm256_mask_dpbusd_epi32(src, k, a, b) simde_mm256_mask_dpbusd_epi32(src, k, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_maskz_dpbusd_epi32(simde__mmask8 k, simde__m256i src, simde__m256i a, simde__m256i b) {
  #if defined(SIMDE_X86_AVX512VL_NATIVE) && defined(SIMDE_X86_AVX512VNNI_NATIVE)
    return _mm256_maskz_dpbusd_epi32(k, src, a, b);
  #else
    return simde_mm256_maskz_mov_epi32(k, simde_mm256_dpbusd_epi32(src, a, b));
  #endif
}
#if defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VNNI_ENABLE_NATIVE_ALIASES)
  #undef _mm256_maskz_dpbusd_epi32
  #define _mm256_maskz_dpbusd_epi32(k, src, a, b) simde_mm256_maskz_dpbusd_epi32(k, src, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_dpbusd_epi32(simde__m512i src, simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_AVX512VNNI_NATIVE)
    return _mm512_dpbusd_epi32(src, a, b);
  #else
    simde__m512i_private
      src_ = simde__m512i_to_private(src),
      a_ = simde__m512i_to_private(a),
      b_ = simde__m512i_to_private(b);
    #if defined(SIMDE_SHUFFLE_VECTOR_) && defined(SIMDE_CONVERT_VECTOR_)
      union {
        uint32_t u32 SIMDE_VECTOR(256);
        int32_t  i32 SIMDE_VECTOR(256);
        simde__m512i_private m512i_private[4];
      } r1_, r2_;

      a_.u8 =
        SIMDE_SHUFFLE_VECTOR_(
          8, 64,
          a_.u8, a_.u8,
            0,   4,   8,  12,  16,  20,  24,  28,  32,  36,  40,  44,  48,  52,  56,  60,
            1,   5,   9,  13,  17,  21,  25,  29,  33,  37,  41,  45,  49,  53,  57,  61,
            2,   6,  10,  14,  18,  22,  26,  30,  34,  38,  42,  46,  50,  54,  58,  62,
            3,   7,  11,  15,  19,  23,  27,  31,  35,  39,  43,  47,  51,  55,  59,  63
        );
      b_.i8 =
        SIMDE_SHUFFLE_VECTOR_(
          8, 64,
          b_.i8, b_.i8,
            0,   4,   8,  12,  16,  20,  24,  28,  32,  36,  40,  44,  48,  52,  56,  60,
            1,   5,   9,  13,  17,  21,  25,  29,  33,  37,  41,  45,  49,  53,  57,  61,
            2,   6,  10,  14,  18,  22,  26,  30,  34,  38,  42,  46,  50,  54,  58,  62,
            3,   7,  11,  15,  19,  23,  27,  31,  35,  39,  43,  47,  51,  55,  59,  63
        );

      SIMDE_CONVERT_VECTOR_(r1_.u32, a_.u8);
      SIMDE_CONVERT_VECTOR_(r2_.i32, b_.i8);

      src_.i32 +=
        (HEDLEY_REINTERPRET_CAST(__typeof__(a_.i32), r1_.m512i_private[0].u32) * r2_.m512i_private[0].i32) +
        (HEDLEY_REINTERPRET_CAST(__typeof__(a_.i32), r1_.m512i_private[1].u32) * r2_.m512i_private[1].i32) +
        (HEDLEY_REINTERPRET_CAST(__typeof__(a_.i32), r1_.m512i_private[2].u32) * r2_.m512i_private[2].i32) +
        (HEDLEY_REINTERPRET_CAST(__typeof__(a_.i32), r1_.m512i_private[3].u32) * r2_.m512i_private[3].i32);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(a_.u8) / sizeof(a_.u8[0])) ; i++) {
        src_.i32[i / 4] += HEDLEY_STATIC_CAST(uint16_t, a_.u8[i]) * HEDLEY_STATIC_CAST(int16_t, b_.i8[i]);
      }
    #endif

    return simde__m512i_from_private(src_);
  #endif
}
#if defined(SIMDE_X86_AVX512VNNI_ENABLE_NATIVE_ALIASES)
  #undef _mm512_dpbusd_epi32
  #define _mm512_dpbusd_epi32(src, a, b) simde_mm512_dpbusd_epi32(src, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_mask_dpbusd_epi32(simde__m512i src, simde__mmask16 k, simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_AVX512VNNI_NATIVE)
    return _mm512_mask_dpbusd_epi32(src, k, a, b);
  #else
    return simde_mm512_mask_mov_epi32(src, k, simde_mm512_dpbusd_epi32(src, a, b));
  #endif
}
#if defined(SIMDE_X86_AVX512VNNI_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_dpbusd_epi32
  #define _mm512_mask_dpbusd_epi32(src, k, a, b) simde_mm512_mask_dpbusd_epi32(src, k, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_maskz_dpbusd_epi32(simde__mmask16 k, simde__m512i src, simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_AVX512VNNI_NATIVE)
    return _mm512_maskz_dpbusd_epi32(k, src, a, b);
  #else
    return simde_mm512_maskz_mov_epi32(k, simde_mm512_dpbusd_epi32(src, a, b));
  #endif
}
#if defined(SIMDE_X86_AVX512VNNI_ENABLE_NATIVE_ALIASES)
  #undef _mm512_maskz_dpbusd_epi32
  #define _mm512_maskz_dpbusd_epi32(k, src, a, b) simde_mm512_maskz_dpbusd_epi32(k, src, a, b)
#endif

SIMDE_END_DECLS_
HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_X86_AVX512_DPBUSD_H) */
