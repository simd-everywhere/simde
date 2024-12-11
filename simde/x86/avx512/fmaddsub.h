#if !defined(SIMDE_X86_AVX512_FMADDSUB_H)
#define SIMDE_X86_AVX512_FMADDSUB_H

#include "types.h"
#include "../fma.h"
#include "mul.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

SIMDE_FUNCTION_ATTRIBUTES
simde__m512d
simde_x_mm512_addsub_pd (simde__m512d a, simde__m512d b) {
  //mm512_addsub_pd does not exist, but we define it for utility purposes (only with simde_x prefix, no native alias)
  simde__m512d_private
    r_,
    a_ = simde__m512d_to_private(a),
    b_ = simde__m512d_to_private(b);

  #if SIMDE_NATURAL_VECTOR_SIZE_LE(256)
    r_.m256d[0] = simde_mm256_addsub_pd(a_.m256d[0], b_.m256d[0]);
    r_.m256d[1] = simde_mm256_addsub_pd(a_.m256d[1], b_.m256d[1]);
  #else
    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f64) / sizeof(r_.f64[0])) ; i += 2) {
      r_.f64[  i  ] = a_.f64[  i  ] - b_.f64[  i  ];
      r_.f64[i + 1] = a_.f64[i + 1] + b_.f64[i + 1];
    }
  #endif

  return simde__m512d_from_private(r_);
}

SIMDE_FUNCTION_ATTRIBUTES
simde__m512
simde_x_mm512_addsub_ps (simde__m512 a, simde__m512 b) {
  //mm512_addsub_ps does not exist, but we define it for utility purposes (only with simde_x prefix, no native alias)
  simde__m512_private
    r_,
    a_ = simde__m512_to_private(a),
    b_ = simde__m512_to_private(b);

  #if SIMDE_NATURAL_VECTOR_SIZE_LE(256)
    r_.m256[0] = simde_mm256_addsub_ps(a_.m256[0], b_.m256[0]);
    r_.m256[1] = simde_mm256_addsub_ps(a_.m256[1], b_.m256[1]);
  #else
    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f32) / sizeof(r_.f32[0])) ; i += 2) {
      r_.f32[  i  ] = a_.f32[  i  ] - b_.f32[  i  ];
      r_.f32[i + 1] = a_.f32[i + 1] + b_.f32[i + 1];
    }
  #endif

  return simde__m512_from_private(r_);
}

SIMDE_FUNCTION_ATTRIBUTES
simde__m512d
simde_mm512_fmaddsub_pd (simde__m512d a, simde__m512d b, simde__m512d c) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_fmaddsub_pd(a, b, c);
  #else
    return simde_x_mm512_addsub_pd(simde_mm512_mul_pd(a, b), c);
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_fmaddsub_pd
  #define _mm512_fmaddsub_pd(a, b, c) simde_mm512_fmaddsub_pd(a, b, c)
#endif


SIMDE_FUNCTION_ATTRIBUTES
simde__m512
simde_mm512_fmaddsub_ps (simde__m512 a, simde__m512 b, simde__m512 c) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_fmaddsub_ps(a, b, c);
  #else
    return simde_x_mm512_addsub_ps(simde_mm512_mul_ps(a, b), c);
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_fmaddsub_ps
  #define _mm512_fmaddsub_ps(a, b, c) simde_mm512_fmaddsub_ps(a, b, c)
#endif


SIMDE_END_DECLS_
HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_X86_AVX512_FMADDSUB_H) */
