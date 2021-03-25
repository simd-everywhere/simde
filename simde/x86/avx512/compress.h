#if !defined(SIMDE_X86_AVX512_COMPRESS_H)
#define SIMDE_X86_AVX512_COMPRESS_H

#include "types.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

SIMDE_FUNCTION_ATTRIBUTES
simde__m256d
simde_mm256_mask_compress_pd (simde__m256d src, simde__mmask8 k, simde__m256d a) {
  #if defined(SIMDE_X86_AVX512VL_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm256_mask_compress_pd(src, k, a);
  #else
    simde__m256d_private
      a_ = simde__m256d_to_private(a),
      src_ = simde__m256d_to_private(src);
    size_t ri = 0;

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(a_.f64) / sizeof(a_.f64[0])) ; i++) {
      if ((k >> i) & 1) {
        a_.f64[ri++] = a_.f64[i];
      }
    }

    for ( ; ri < (sizeof(a_.f64) / sizeof(a_.f64[0])) ; ri++) {
      a_.f64[ri] = src_.f64[ri];
    }

    return simde__m256d_from_private(a_);
  #endif
}
#if defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm256_mask_compress_pd
  #define _mm256_mask_compress_pd(src, k, a) _mm256_mask_compress_pd(src, k, a)
#endif

SIMDE_END_DECLS_
HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_X86_AVX512_COMPRESS_H) */
