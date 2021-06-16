#if !defined(SIMDE_X86_AVX512_SCALEF_H)
#define SIMDE_X86_AVX512_SCALEF_H

#include "types.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

SIMDE_FUNCTION_ATTRIBUTES
simde_float32
simde_scalef_ps_impl_(simde_float32 a, simde_float32 b) {
  if(simde_math_isnanf(b)) {
    if (!(simde_uint32_as_float32(simde_float32_as_uint32(b) & UINT32_C(4194304))))
      return simde_uint32_as_float32(simde_float32_as_uint32(b) | UINT32_C(4194304));
  } else if (simde_math_isnanf(a)) {
    if (!(simde_uint32_as_float32(simde_float32_as_uint32(a) & UINT32_C(4194304))) || !simde_math_isinff(b)) {
      return simde_uint32_as_float32(simde_float32_as_uint32(a) | UINT32_C(4194304));
    }
  } else {
    a = simde_math_issubnormalf(a) ? 0.0f : a;
    b = simde_math_issubnormalf(b) ? 0.0f : b;
  }

  return a * simde_math_exp2f(simde_math_floorf(b));
}

SIMDE_FUNCTION_ATTRIBUTES
simde__m128
simde_mm_scalef_ps (simde__m128 a, simde__m128 b) {
  #if defined(SIMDE_X86_AVX512F_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm_scalef_ps(a, b);
  #else
    simde__m128_private
      r_,
      a_ = simde__m128_to_private(a),
      b_ = simde__m128_to_private(b);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f32) / sizeof(r_.f32[0])) ; i++) {
      r_.f32[i] = simde_scalef_ps_impl_(a_.f32[i], b_.f32[i]);
    }

    return simde__m128_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm_scalef_ps
  #define _mm_scalef_ps(a, b) simde_mm_scalef_ps(a, b)
#endif

SIMDE_END_DECLS_
HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_X86_AVX512_SCALEF_H) */
