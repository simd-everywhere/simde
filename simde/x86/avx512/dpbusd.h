#if !defined(SIMDE_X86_AVX512_DPBUSD_H)
#define SIMDE_X86_AVX512_DPBUSD_H

#include "types.h"

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

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(a_.u8) / sizeof(a_.u8[0])) ; i++) {
      src_.i32[i / 4] += HEDLEY_STATIC_CAST(uint16_t, a_.u8[i]) * HEDLEY_STATIC_CAST(int16_t, b_.i8[i]);
    }

    return simde__m128i_from_private(src_);
  #endif
}
#if defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VNNI_ENABLE_NATIVE_ALIASES)
  #undef _mm_dpbusd_epi32
  #define _mm_dpbusd_epi32(src, a, b) simde_mm_dpbusd_epi32(src, a, b)
#endif

SIMDE_END_DECLS_
HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_X86_AVX512_DPBUSD_H) */
