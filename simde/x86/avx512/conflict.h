#if !defined(SIMDE_X86_AVX512_CONFLICT_H)
#define SIMDE_X86_AVX512_CONFLICT_H

#include "types.h"
#include "mov_mask.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_conflict_epi32 (simde__m128i a) {
  #if defined(SIMDE_X86_AVX512VL_NATIVE) && defined(SIMDE_X86_AVX512CD_NATIVE)
    return _mm_conflict_epi32(a);
  #else
    simde__m128i_private
      r_ = simde__m128i_to_private(simde_mm_setzero_si128()),
      a_ = simde__m128i_to_private(a);

    for (size_t i = 1 ; i < (sizeof(r_.i32) / sizeof(r_.i32[0])) ; i++) {
      r_.i32[i] =
        HEDLEY_STATIC_CAST(int32_t,
          simde_mm_movepi32_mask(
            simde_mm_cmpeq_epi32(simde_mm_set1_epi32(a_.i32[i]), a)
          )
        ) & ((1 << i) - 1);
    }

    return simde__m128i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512CD_ENABLE_NATIVE_ALIASES)
  #undef _mm_conflict_epi32
  #define _mm_conflict_epi32(a) simde_mm_conflict_epi32(a)
#endif

SIMDE_END_DECLS_
HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_X86_AVX512_CONFLICT_H) */
