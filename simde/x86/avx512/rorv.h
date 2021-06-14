#if !defined(SIMDE_X86_AVX512_RORV_H)
#define SIMDE_X86_AVX512_RORV_H

#include "types.h"
#include "../avx2.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_rorv_epi32 (simde__m128i a, simde__m128i b) {
  #if defined(SIMDE_X86_AVX512F_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm_rorv_epi32(a, b);
  #elif defined(SIMDE_POWER_ALTIVEC_P6_NATIVE)
    simde__m128i_private
      r_,
      a_ = simde__m128i_to_private(a),
      b_ = simde__m128i_to_private(b);

    r_.altivec_i32 = vec_rl(a_.altivec_i32, vec_sub(vec_splats(HEDLEY_STATIC_CAST(unsigned int, 32)), b_.altivec_u32));
    return simde__m128i_from_private(r_);
  #else
    simde__m128i
      count1 = simde_mm_and_si128(b, simde_mm_set1_epi32(31)),
      count2 = simde_mm_sub_epi32(simde_mm_set1_epi32(32), count1);
    return simde_mm_or_si128(simde_mm_srlv_epi32(a, count1), simde_mm_sllv_epi32(a, count2));
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm_rorv_epi32
  #define _mm_rorv_epi32(a, b) simde_mm_rorv_epi32(a, b)
#endif

SIMDE_END_DECLS_
HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_X86_AVX512_RORV_H) */
