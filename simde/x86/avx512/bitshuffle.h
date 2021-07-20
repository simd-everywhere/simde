#if !defined(SIMDE_X86_AVX512_BITSHUFFLE_H)
#define SIMDE_X86_AVX512_BITSHUFFLE_H

#include "types.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

SIMDE_FUNCTION_ATTRIBUTES
simde__mmask16
simde_mm_bitshuffle_epi64_mask (simde__m128i b, simde__m128i c) {
  #if defined(SIMDE_X86_AVX512BITALG_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm_bitshuffle_epi64_mask(b, c);
  #else
    simde__m128i_private
      b_ = simde__m128i_to_private(b),
      c_ = simde__m128i_to_private(c);
    simde__mmask16 r = 0;

    for (size_t i = 0 ; i < (sizeof(c_.m64_private) / sizeof(c_.m64_private[0])) ; i++) {
      SIMDE_VECTORIZE_REDUCTION(|:r)
      for (size_t j = 0 ; j < (sizeof(c_.m64_private[i].u8) / sizeof(c_.m64_private[i].u8[0])) ; j++) {
        r |= (((b_.u64[i] >> (c_.m64_private[i].u8[j] & 0x3f)) & 1) << ((i * 8) + j));
      }
    }

    return r;
  #endif
}
#if defined(SIMDE_X86_AVX512BITALG_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm_bitshuffle_epi64_mask
  #define _mm_bitshuffle_epi64_mask(b, c) simde_mm_bitshuffle_epi64_mask(b, c)
#endif

SIMDE_END_DECLS_
HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_X86_AVX512_BITSHUFFLE_H) */
