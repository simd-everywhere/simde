#if !defined(SIMDE_X86_AVX512_ROUNDSCALE_H)
#define SIMDE_X86_AVX512_ROUNDSCALE_H

#include "types.h"
#include "../sse.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

#if defined(SIMDE_X86_AVX512VL_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
  #define simde_mm_roundscale_ps(a, imm8) _mm_roundscale_ps((a), (imm8))
#else
  SIMDE_FUNCTION_ATTRIBUTES
  simde__m128
  simde_mm_roundscale_ps (simde__m128 a, int imm8)
    SIMDE_REQUIRE_CONSTANT_RANGE(imm8, 0, 255) {
      simde__m128 temp, r;
      int32_t
        exponent1 = (127 + ((imm8 >> 4) & 15)) << 23,
        exponent2 = (127 - ((imm8 >> 4) & 15)) << 23;

      SIMDE_CONSTIFY_16_(simde_mm_round_ps, temp, simde_mm_setzero_ps(), imm8 & 15, simde_mm_mul_ps(a, simde_mm_set1_ps(*HEDLEY_REINTERPRET_CAST(SIMDE_FLOAT32_TYPE*, &exponent1))));
      r = simde_mm_mul_ps(simde_mm_set1_ps(*HEDLEY_REINTERPRET_CAST(SIMDE_FLOAT32_TYPE*, &exponent2)), temp);
      return r;
  }
#endif
#if defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm_roundscale_ps
  #define _mm_roundscale_ps(a, imm8) simde_mm_roundscale_ps(a, imm8)
#endif

SIMDE_END_DECLS_
HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_X86_AVX512_ROUNDSCALE_H) */
