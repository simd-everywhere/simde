#if !defined(SIMDE_X86_AVX512_ROR_H)
#define SIMDE_X86_AVX512_ROR_H

#include "types.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

#if defined(SIMDE_X86_AVX512F_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
  #define simde_mm_ror_epi32(a, imm8) _mm_ror_epi32(a, imm8);
#else
  #define simde_mm_ror_epi32(a, imm8) simde_mm_or_si128(simde_mm_srli_epi32(a, (imm8 & 31)), simde_mm_slli_epi32(a, (32 - (imm8 & 31))))
#endif
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm_ror_epi32
  #define _mm_ror_epi32(a, imm8) simde_mm_ror_epi32(a, imm8)
#endif

SIMDE_END_DECLS_
HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_X86_AVX512_ROR_H) */
