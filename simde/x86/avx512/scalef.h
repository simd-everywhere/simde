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

SIMDE_FUNCTION_ATTRIBUTES
simde__m128
simde_mm_mask_scalef_ps (simde__m128 src, simde__mmask8 k, simde__m128 a, simde__m128 b) {
  #if defined(SIMDE_X86_AVX512F_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm_mask_scalef_ps(src, k, a, b);
  #else
    return simde_mm_mask_mov_ps(src, k, simde_mm_scalef_ps(a, b));
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm_mask_scalef_ps
  #define _mm_mask_scalef_ps(src, k, a, b) simde_mm_mask_scalef_ps(src, k, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128
simde_mm_maskz_scalef_ps (simde__mmask8 k, simde__m128 a, simde__m128 b) {
  #if defined(SIMDE_X86_AVX512F_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm_maskz_scalef_ps(k, a, b);
  #else
    return simde_mm_maskz_mov_ps(k, simde_mm_scalef_ps(a, b));
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm_maskz_scalef_ps
  #define _mm_maskz_scalef_ps(k, a, b) simde_mm_maskz_scalef_ps(k, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256
simde_mm256_scalef_ps (simde__m256 a, simde__m256 b) {
  #if defined(SIMDE_X86_AVX512F_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm256_scalef_ps(a, b);
  #else
    return simde_mm256_mul_ps(simde_x_mm256_flushsubnormal_ps(a), simde_mm256_exp2_ps(simde_mm256_floor_ps(simde_x_mm256_flushsubnormal_ps(b))));
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm256_scalef_ps
  #define _mm256_scalef_ps(a, b) simde_mm256_scalef_ps(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256
simde_mm256_mask_scalef_ps (simde__m256 src, simde__mmask8 k, simde__m256 a, simde__m256 b) {
  #if defined(SIMDE_X86_AVX512F_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm256_mask_scalef_ps(src, k, a, b);
  #else
    return simde_mm256_mask_mov_ps(src, k, simde_mm256_scalef_ps(a, b));
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm256_mask_scalef_ps
  #define _mm256_mask_scalef_ps(src, k, a, b) simde_mm256_mask_scalef_ps(src, k, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256
simde_mm256_maskz_scalef_ps (simde__mmask8 k, simde__m256 a, simde__m256 b) {
  #if defined(SIMDE_X86_AVX512F_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm256_maskz_scalef_ps(k, a, b);
  #else
    return simde_mm256_maskz_mov_ps(k, simde_mm256_scalef_ps(a, b));
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm256_maskz_scalef_ps
  #define _mm256_maskz_scalef_ps(k, a, b) simde_mm256_maskz_scalef_ps(k, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512
simde_mm512_scalef_ps (simde__m512 a, simde__m512 b) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_scalef_ps(a, b);
  #else
    return simde_mm512_mul_ps(simde_x_mm512_flushsubnormal_ps(a), simde_mm512_exp2_ps(simde_mm512_floor_ps(simde_x_mm512_flushsubnormal_ps(b))));
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_scalef_ps
  #define _mm512_scalef_ps(a, b) simde_mm512_scalef_ps(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512
simde_mm512_mask_scalef_ps (simde__m512 src, simde__mmask16 k, simde__m512 a, simde__m512 b) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_mask_scalef_ps(src, k, a, b);
  #else
    return simde_mm512_mask_mov_ps(src, k, simde_mm512_scalef_ps(a, b));
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_scalef_ps
  #define _mm512_mask_scalef_ps(src, k, a, b) simde_mm512_mask_scalef_ps(src, k, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512
simde_mm512_maskz_scalef_ps (simde__mmask16 k, simde__m512 a, simde__m512 b) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_maskz_scalef_ps(k, a, b);
  #else
    return simde_mm512_maskz_mov_ps(k, simde_mm512_scalef_ps(a, b));
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_maskz_scalef_ps
  #define _mm512_maskz_scalef_ps(k, a, b) simde_mm512_maskz_scalef_ps(k, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128d
simde_mm_scalef_pd (simde__m128d a, simde__m128d b) {
  #if defined(SIMDE_X86_AVX512F_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm_scalef_pd(a, b);
  #else
    return simde_mm_mul_pd(simde_x_mm_flushsubnormal_pd(a), simde_mm_exp2_pd(simde_mm_floor_pd(simde_x_mm_flushsubnormal_pd(b))));
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm_scalef_pd
  #define _mm_scalef_pd(a, b) simde_mm_scalef_pd(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128d
simde_mm_mask_scalef_pd (simde__m128d src, simde__mmask8 k, simde__m128d a, simde__m128d b) {
  #if defined(SIMDE_X86_AVX512F_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm_mask_scalef_pd(src, k, a, b);
  #else
    return simde_mm_mask_mov_pd(src, k, simde_mm_scalef_pd(a, b));
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm_mask_scalef_pd
  #define _mm_mask_scalef_pd(src, k, a, b) simde_mm_mask_scalef_pd(src, k, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128d
simde_mm_maskz_scalef_pd (simde__mmask8 k, simde__m128d a, simde__m128d b) {
  #if defined(SIMDE_X86_AVX512F_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm_maskz_scalef_pd(k, a, b);
  #else
    return simde_mm_maskz_mov_pd(k, simde_mm_scalef_pd(a, b));
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm_maskz_scalef_pd
  #define _mm_maskz_scalef_pd(k, a, b) simde_mm_maskz_scalef_pd(k, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256d
simde_mm256_scalef_pd (simde__m256d a, simde__m256d b) {
  #if defined(SIMDE_X86_AVX512F_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm256_scalef_pd(a, b);
  #else
    return simde_mm256_mul_pd(simde_x_mm256_flushsubnormal_pd(a), simde_mm256_exp2_pd(simde_mm256_floor_pd(simde_x_mm256_flushsubnormal_pd(b))));
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm256_scalef_pd
  #define _mm256_scalef_pd(a, b) simde_mm256_scalef_pd(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256d
simde_mm256_mask_scalef_pd (simde__m256d src, simde__mmask8 k, simde__m256d a, simde__m256d b) {
  #if defined(SIMDE_X86_AVX512F_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm256_mask_scalef_pd(src, k, a, b);
  #else
    return simde_mm256_mask_mov_pd(src, k, simde_mm256_scalef_pd(a, b));
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm256_mask_scalef_pd
  #define _mm256_mask_scalef_pd(src, k, a, b) simde_mm256_mask_scalef_pd(src, k, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256d
simde_mm256_maskz_scalef_pd (simde__mmask8 k, simde__m256d a, simde__m256d b) {
  #if defined(SIMDE_X86_AVX512F_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm256_maskz_scalef_pd(k, a, b);
  #else
    return simde_mm256_maskz_mov_pd(k, simde_mm256_scalef_pd(a, b));
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm256_maskz_scalef_pd
  #define _mm256_maskz_scalef_pd(k, a, b) simde_mm256_maskz_scalef_pd(k, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512d
simde_mm512_scalef_pd (simde__m512d a, simde__m512d b) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_scalef_pd(a, b);
  #else
    return simde_mm512_mul_pd(simde_x_mm512_flushsubnormal_pd(a), simde_mm512_exp2_pd(simde_mm512_floor_pd(simde_x_mm512_flushsubnormal_pd(b))));
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_scalef_pd
  #define _mm512_scalef_pd(a, b) simde_mm512_scalef_pd(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512d
simde_mm512_mask_scalef_pd (simde__m512d src, simde__mmask8 k, simde__m512d a, simde__m512d b) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_mask_scalef_pd(src, k, a, b);
  #else
    return simde_mm512_mask_mov_pd(src, k, simde_mm512_scalef_pd(a, b));
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_scalef_pd
  #define _mm512_mask_scalef_pd(src, k, a, b) simde_mm512_mask_scalef_pd(src, k, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512d
simde_mm512_maskz_scalef_pd (simde__mmask8 k, simde__m512d a, simde__m512d b) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_maskz_scalef_pd(k, a, b);
  #else
    return simde_mm512_maskz_mov_pd(k, simde_mm512_scalef_pd(a, b));
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_maskz_scalef_pd
  #define _mm512_maskz_scalef_pd(k, a, b) simde_mm512_maskz_scalef_pd(k, a, b)
#endif

SIMDE_END_DECLS_
HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_X86_AVX512_SCALEF_H) */
