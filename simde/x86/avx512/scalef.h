#if !defined(SIMDE_X86_AVX512_SCALEF_H)
#define SIMDE_X86_AVX512_SCALEF_H

#include "types.h"
#include "flushsubnormal.h"
#include "../svml.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

SIMDE_FUNCTION_ATTRIBUTES
simde__m128
simde_mm_scalef_ps (simde__m128 a, simde__m128 b) {
  #if defined(SIMDE_X86_AVX512F_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm_scalef_ps(a, b);
  #else
    return simde_mm_mul_ps(simde_x_mm_flushsubnormal_ps(a), simde_mm_exp2_ps(simde_mm_floor_ps(simde_x_mm_flushsubnormal_ps(b))));
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm_scalef_ps
  #define _mm_scalef_ps(a, b) simde_mm_scalef_ps(a, b)
#endif

SIMDE_END_DECLS_
HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_X86_AVX512_SCALEF_H) */
