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

    #if defined(SIMDE_VECTOR_SUBSCRIPT_SCALAR)
      __typeof__(b_.u64) rv = { 0, 0 };
      __typeof__(b_.u64) lshift = { 0, 8 };

      for (int8_t i = 0 ; i < 8 ; i++) {
        __typeof__(b_.u64) ct = (HEDLEY_REINTERPRET_CAST(__typeof__(ct), c_.u8) >> (i * 8)) & 63;
        rv |= ((b_.u64 >> ct) & 1) << lshift;
        lshift += 1;
      }

      r = HEDLEY_STATIC_CAST(simde__mmask16, rv[0]) | HEDLEY_STATIC_CAST(simde__mmask16, rv[1]);
    #else
      for (size_t i = 0 ; i < (sizeof(c_.m64_private) / sizeof(c_.m64_private[0])) ; i++) {
        SIMDE_VECTORIZE_REDUCTION(|:r)
        for (size_t j = 0 ; j < (sizeof(c_.m64_private[i].u8) / sizeof(c_.m64_private[i].u8[0])) ; j++) {
          r |= (((b_.u64[i] >> (c_.m64_private[i].u8[j]) & 63) & 1) << ((i * 8) + j));
        }
      }
    #endif

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
