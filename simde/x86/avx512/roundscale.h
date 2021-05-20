#if !defined(SIMDE_X86_AVX512_ROUNDSCALE_H)
#define SIMDE_X86_AVX512_ROUNDSCALE_H

#include "types.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

#if defined(SIMDE_X86_AVX512VL_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
  #define simde_mm_roundscale_ps(a, imm8) _mm_roundscale_ps((a), (imm8))
#else
  SIMDE_FUNCTION_ATTRIBUTES
  simde__m128
  simde_mm_roundscale_ps_internal_ (simde__m128 result, simde__m128 a, int imm8)
      SIMDE_REQUIRE_CONSTANT_RANGE(imm8, 0, 255) {
    HEDLEY_STATIC_CAST(void, imm8);

    simde__m128 r, clear_sign;

    clear_sign = simde_mm_andnot_ps(simde_mm_set1_ps(SIMDE_FLOAT32_C(-0.0)), a);
    r = simde_x_mm_select_ps(result, a, simde_mm_cmpeq_ps(clear_sign, simde_mm_set1_ps(SIMDE_MATH_INFINITY)));

    return r;
  }
  #define simde_mm_roundscale_ps(a, imm8) \
    simde_mm_roundscale_ps_internal_( \
      simde_mm_mul_ps( \
        simde_mm_round_ps( \
          simde_mm_mul_ps( \
            a, \
            simde_mm_set1_ps(simde_uint32_as_float32((127 + ((imm8 >> 4) & 15)) << 23))), \
          ((imm8) & 15) \
        ), \
        simde_mm_set1_ps(simde_uint32_as_float32((127 - ((imm8 >> 4) & 15)) << 23)) \
      ), \
      (a), \
      (imm8) \
    )
#endif
#if defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm_roundscale_ps
  #define _mm_roundscale_ps(a, imm8) simde_mm_roundscale_ps(a, imm8)
#endif

SIMDE_END_DECLS_
HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_X86_AVX512_ROUNDSCALE_H) */
