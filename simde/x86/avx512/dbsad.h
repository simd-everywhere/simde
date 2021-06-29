#if !defined(SIMDE_X86_AVX512_DBSAD_H)
#define SIMDE_X86_AVX512_DBSAD_H

#include "types.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

#if defined(SIMDE_X86_AVX512BW_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
  #define simde_mm_dbsad_epu8(a, b, imm8) _mm_dbsad_epu8((a), (b), (imm8))
#else
  SIMDE_FUNCTION_ATTRIBUTES
  simde__m128i
  simde_mm_dbsad_epu8_internal_ (simde__m128i a, simde__m128i b, int imm8)
      SIMDE_REQUIRE_CONSTANT_RANGE(imm8, 0, 255) {
    HEDLEY_STATIC_CAST(void, imm8);
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
  #define simde_mm_dbsad_epu8(a, b, imm8) simde_mm_dbsad_epu8_internal_((a), simde_mm_shuffle_epi32(b, imm8), (imm8))
#endif
#if defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm_dbsad_epu8
  #define _mm_dbsad_epu8(a, b, imm8) simde_mm_dbsad_epu8(a, b, imm8)
#endif

SIMDE_END_DECLS_
HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_X86_AVX512_DBSAD_H) */
