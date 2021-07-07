#if !defined(SIMDE_X86_AVX512_DBSAD_H)
#define SIMDE_X86_AVX512_DBSAD_H

#include "types.h"
#include "mov.h"
#include "../avx2.h"
#include "shuffle.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

#if defined(SIMDE_X86_AVX512BW_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
  #define simde_mm_dbsad_epu8(a, b, imm8) _mm_dbsad_epu8((a), (b), (imm8))
#else
  SIMDE_FUNCTION_ATTRIBUTES
  simde__m128i
  simde_mm_dbsad_epu8_internal_ (simde__m128i a, simde__m128i b) {
    simde__m128i_private
      r_,
      a_ = simde__m128i_to_private(a),
      b_ = simde__m128i_to_private(b);

    for (size_t i = 0 ; i < (sizeof(r_.m64_private) / sizeof(r_.m64_private[0])) ; i++) {
      for (size_t j = 0 ; j < (sizeof(r_.m64_private[i].u16) / sizeof(r_.m64_private[i].u16[0])) ; j++) {
        uint16_t tmp = 0;
        SIMDE_VECTORIZE_REDUCTION(+:tmp)
        for (size_t k = 0 ; k < (sizeof(uint32_t) / sizeof(uint8_t)) ; k++) {
          const size_t e1 = j + k;
          const size_t e2 = ((j >> 1) << 2) + k;
          tmp +=
            HEDLEY_STATIC_CAST(
              uint16_t,
              (a_.m64_private[i].u8[e2] > b_.m64_private[i].u8[e1]) ?
              (a_.m64_private[i].u8[e2] - b_.m64_private[i].u8[e1]) :
              (b_.m64_private[i].u8[e1] - a_.m64_private[i].u8[e2])
            );
        }
        r_.m64_private[i].u16[j] = tmp;
      }
    }

    return simde__m128i_from_private(r_);
  }
  #define simde_mm_dbsad_epu8(a, b, imm8) simde_mm_dbsad_epu8_internal_((a), simde_mm_shuffle_epi32(b, imm8))
#endif
#if defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm_dbsad_epu8
  #define _mm_dbsad_epu8(a, b, imm8) simde_mm_dbsad_epu8(a, b, imm8)
#endif

#if defined(SIMDE_X86_AVX512BW_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
  #define simde_mm_mask_dbsad_epu8(src, k, a, b, imm8) _mm_mask_dbsad_epu8((src), (k), (a), (b), (imm8))
#else
  #define simde_mm_mask_dbsad_epu8(src, k, a, b, imm8) simde_mm_mask_mov_epi16(src, k, simde_mm_dbsad_epu8(a, b, imm8))
#endif
#if defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm_mask_dbsad_epu8
  #define _mm_mask_dbsad_epu8(src, k, a, b, imm8) simde_mm_mask_dbsad_epu8(src, k, a, b, imm8)
#endif

#if defined(SIMDE_X86_AVX512BW_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
  #define simde_mm_maskz_dbsad_epu8(k, a, b, imm8) _mm_maskz_dbsad_epu8((k), (a), (b), (imm8))
#else
  #define simde_mm_maskz_dbsad_epu8(k, a, b, imm8) simde_mm_maskz_mov_epi16(k, simde_mm_dbsad_epu8(a, b, imm8))
#endif
#if defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm_maskz_dbsad_epu8
  #define _mm_maskz_dbsad_epu8(k, a, b, imm8) simde_mm_maskz_dbsad_epu8(k, a, b, imm8)
#endif

#if defined(SIMDE_X86_AVX512BW_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
  #define simde_mm256_dbsad_epu8(a, b, imm8) _mm256_dbsad_epu8((a), (b), (imm8))
#elif SIMDE_NATURAL_VECTOR_SIZE_LE(128) && defined(SIMDE_STATEMENT_EXPR_)
  #define simde_mm256_dbsad_epu8(a, b, imm8) SIMDE_STATEMENT_EXPR_(({ \
    simde__m256i_private \
      simde_mm256_dbsad_epu8_a_ = simde__m256i_to_private(a), \
      simde_mm256_dbsad_epu8_b_ = simde__m256i_to_private(b); \
    \
    simde_mm256_dbsad_epu8_a_.m128i[0] = simde_mm_dbsad_epu8(simde_mm256_dbsad_epu8_a_.m128i[0], simde_mm256_dbsad_epu8_b_.m128i[0], imm8); \
    simde_mm256_dbsad_epu8_a_.m128i[1] = simde_mm_dbsad_epu8(simde_mm256_dbsad_epu8_a_.m128i[1], simde_mm256_dbsad_epu8_b_.m128i[1], imm8); \
    \
    simde__m256i_from_private(simde_mm256_dbsad_epu8_a_); \
  }))
#else
  SIMDE_FUNCTION_ATTRIBUTES
  simde__m256i
  simde_mm256_dbsad_epu8_internal_ (simde__m256i a, simde__m256i b) {
    simde__m256i_private
      r_,
      a_ = simde__m256i_to_private(a),
      b_ = simde__m256i_to_private(b);

    for (size_t i = 0 ; i < sizeof(r_.m128i_private) / sizeof(r_.m128i_private[0]) ; i++) {
      for (size_t j = 0 ; j < (sizeof(r_.m128i_private[i].m64_private) / sizeof(r_.m128i_private[i].m64_private[0])) ; j++) {
        for (size_t k = 0 ; k < (sizeof(r_.m128i_private[i].m64_private[j].u16) / sizeof(r_.m128i_private[i].m64_private[j].u16[0])) ; k++) {
          uint16_t tmp = 0;
          SIMDE_VECTORIZE_REDUCTION(+:tmp)
          for (size_t l = 0 ; l < (sizeof(uint32_t) / sizeof(uint8_t)) ; l++) {
            const size_t e1 = k + l;
            const size_t e2 = ((k >> 1) << 2) + l;
            tmp +=
              HEDLEY_STATIC_CAST(
                uint16_t,
                (a_.m128i_private[i].m64_private[j].u8[e2] > b_.m128i_private[i].m64_private[j].u8[e1]) ?
                (a_.m128i_private[i].m64_private[j].u8[e2] - b_.m128i_private[i].m64_private[j].u8[e1]) :
                (b_.m128i_private[i].m64_private[j].u8[e1] - a_.m128i_private[i].m64_private[j].u8[e2])
              );
          }
          r_.m128i_private[i].m64_private[j].u16[k] = tmp;
        }
      }
    }

    return simde__m256i_from_private(r_);
  }
  #define simde_mm256_dbsad_epu8(a, b, imm8) simde_mm256_dbsad_epu8_internal_((a), simde_mm256_shuffle_epi32(b, imm8))
#endif
#if defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm256_dbsad_epu8
  #define _mm256_dbsad_epu8(a, b, imm8) simde_mm256_dbsad_epu8(a, b, imm8)
#endif

#if defined(SIMDE_X86_AVX512BW_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
  #define simde_mm256_mask_dbsad_epu8(src, k, a, b, imm8) _mm256_mask_dbsad_epu8((src), (k), (a), (b), (imm8))
#else
  #define simde_mm256_mask_dbsad_epu8(src, k, a, b, imm8) simde_mm256_mask_mov_epi16(src, k, simde_mm256_dbsad_epu8(a, b, imm8))
#endif
#if defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm256_mask_dbsad_epu8
  #define _mm256_mask_dbsad_epu8(src, k, a, b, imm8) simde_mm256_mask_dbsad_epu8(src, k, a, b, imm8)
#endif

#if defined(SIMDE_X86_AVX512BW_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
  #define simde_mm256_maskz_dbsad_epu8(k, a, b, imm8) _mm256_maskz_dbsad_epu8((k), (a), (b), (imm8))
#else
  #define simde_mm256_maskz_dbsad_epu8(k, a, b, imm8) simde_mm256_maskz_mov_epi16(k, simde_mm256_dbsad_epu8(a, b, imm8))
#endif
#if defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm256_maskz_dbsad_epu8
  #define _mm256_maskz_dbsad_epu8(k, a, b, imm8) simde_mm256_maskz_dbsad_epu8(k, a, b, imm8)
#endif

#if defined(SIMDE_X86_AVX512BW_NATIVE)
  #define simde_mm512_dbsad_epu8(a, b, imm8) _mm512_dbsad_epu8((a), (b), (imm8))
#elif SIMDE_NATURAL_VECTOR_SIZE_LE(256) && defined(SIMDE_STATEMENT_EXPR_)
  #define simde_mm512_dbsad_epu8(a, b, imm8) SIMDE_STATEMENT_EXPR_(({ \
    simde__m512i_private \
      simde_mm512_dbsad_epu8_a_ = simde__m512i_to_private(a), \
      simde_mm512_dbsad_epu8_b_ = simde__m512i_to_private(b); \
    \
    simde_mm512_dbsad_epu8_a_.m256i[0] = simde_mm256_dbsad_epu8(simde_mm512_dbsad_epu8_a_.m256i[0], simde_mm512_dbsad_epu8_b_.m256i[0], imm8); \
    simde_mm512_dbsad_epu8_a_.m256i[1] = simde_mm256_dbsad_epu8(simde_mm512_dbsad_epu8_a_.m256i[1], simde_mm512_dbsad_epu8_b_.m256i[1], imm8); \
    \
    simde__m512i_from_private(simde_mm512_dbsad_epu8_a_); \
  }))
#else
  SIMDE_FUNCTION_ATTRIBUTES
  simde__m512i
  simde_mm512_dbsad_epu8_internal_ (simde__m512i a, simde__m512i b) {
    simde__m512i_private
      r_,
      a_ = simde__m512i_to_private(a),
      b_ = simde__m512i_to_private(b);

    for (size_t i = 0 ; i < sizeof(r_.m128i_private) / sizeof(r_.m128i_private[0]) ; i++) {
      for (size_t j = 0 ; j < (sizeof(r_.m128i_private[i].m64_private) / sizeof(r_.m128i_private[i].m64_private[0])) ; j++) {
        for (size_t k = 0 ; k < (sizeof(r_.m128i_private[i].m64_private[j].u16) / sizeof(r_.m128i_private[i].m64_private[j].u16[0])) ; k++) {
          uint16_t tmp = 0;
          SIMDE_VECTORIZE_REDUCTION(+:tmp)
          for (size_t l = 0 ; l < (sizeof(uint32_t) / sizeof(uint8_t)) ; l++) {
            const size_t e1 = k + l;
            const size_t e2 = ((k >> 1) << 2) + l;
            tmp +=
              HEDLEY_STATIC_CAST(
                uint16_t,
                (a_.m128i_private[i].m64_private[j].u8[e2] > b_.m128i_private[i].m64_private[j].u8[e1]) ?
                (a_.m128i_private[i].m64_private[j].u8[e2] - b_.m128i_private[i].m64_private[j].u8[e1]) :
                (b_.m128i_private[i].m64_private[j].u8[e1] - a_.m128i_private[i].m64_private[j].u8[e2])
              );
          }
          r_.m128i_private[i].m64_private[j].u16[k] = tmp;
        }
      }
    }

    return simde__m512i_from_private(r_);
  }
  #define simde_mm512_dbsad_epu8(a, b, imm8) simde_mm512_dbsad_epu8_internal_((a), simde_mm512_castps_si512(simde_mm512_shuffle_ps(simde_mm512_castsi512_ps(b), simde_mm512_castsi512_ps(b), imm8)))
#endif
#if defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES)
  #undef _mm512_dbsad_epu8
  #define _mm512_dbsad_epu8(a, b, imm8) simde_mm512_dbsad_epu8(a, b, imm8)
#endif

#if defined(SIMDE_X86_AVX512BW_NATIVE)
  #define simde_mm512_mask_dbsad_epu8(src, k, a, b, imm8) _mm512_mask_dbsad_epu8((src), (k), (a), (b), (imm8))
#else
  #define simde_mm512_mask_dbsad_epu8(src, k, a, b, imm8) simde_mm512_mask_mov_epi16(src, k, simde_mm512_dbsad_epu8(a, b, imm8))
#endif
#if defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_dbsad_epu8
  #define _mm512_mask_dbsad_epu8(src, k, a, b, imm8) simde_mm512_mask_dbsad_epu8(src, k, a, b, imm8)
#endif

#if defined(SIMDE_X86_AVX512BW_NATIVE)
  #define simde_mm512_maskz_dbsad_epu8(k, a, b, imm8) _mm512_maskz_dbsad_epu8((k), (a), (b), (imm8))
#else
  #define simde_mm512_maskz_dbsad_epu8(k, a, b, imm8) simde_mm512_maskz_mov_epi16(k, simde_mm512_dbsad_epu8(a, b, imm8))
#endif
#if defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES)
  #undef _mm512_maskz_dbsad_epu8
  #define _mm512_maskz_dbsad_epu8(k, a, b, imm8) simde_mm512_maskz_dbsad_epu8(k, a, b, imm8)
#endif


SIMDE_END_DECLS_
HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_X86_AVX512_DBSAD_H) */
