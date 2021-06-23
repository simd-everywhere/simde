#if !defined(SIMDE_X86_AVX512_MULTISHIFT_H)
#define SIMDE_X86_AVX512_MULTISHIFT_H

#include "types.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_multishift_epi64_epi8 (simde__m128i a, simde__m128i b) {
  #if defined(SIMDE_X86_AVX512VBMI_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm_multishift_epi64_epi8(a, b);
  #else
    simde__m128i_private
      r_,
      a_ = simde__m128i_to_private(a),
      b_ = simde__m128i_to_private(b);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < sizeof(r_.u8) / sizeof(r_.u8[0]) ; i++) {
      r_.u8[i] = HEDLEY_STATIC_CAST(uint8_t, (b_.u64[i / 8] >> (a_.u8[i] & 63)) | (b_.u64[i / 8] << (64 - (a_.u8[i] & 63))));
    }

    return simde__m128i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512VBMI_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm_multishift_epi64_epi8
  #define _mm_multishift_epi64_epi8(a, b) simde_mm_multishift_epi64_epi8(a, b)
#endif

SIMDE_END_DECLS_
HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_X86_AVX512_MULTISHIFT_H) */
