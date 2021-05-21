#if !defined(SIMDE_X86_AVX512_RANGE_H)
#define SIMDE_X86_AVX512_RANGE_H

#include "types.h"
#include "max.h"
#include "min.h"
#include "set1.h"
#include "copysign.h"
#include "abs.h"
#include "setzero.h"
#include "cmp.h"
#include "or.h"
#include "andnot.h"
#include "insert.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

SIMDE_FUNCTION_ATTRIBUTES
simde__m128
simde_mm_range_ps (simde__m128 a, simde__m128 b, int imm8)
    SIMDE_REQUIRE_CONSTANT_RANGE(imm8, 0, 15) {
  simde__m128 r;

  switch (imm8 & 3) {
    case 0:
      r = simde_mm_min_ps(a, b);
      break;
    case 1:
      r = simde_mm_max_ps(a, b);
      break;
    case 2:
      r = simde_mm_mask_mov_ps(b, simde_mm_cmp_ps_mask(simde_x_mm_abs_ps(a), simde_x_mm_abs_ps(b), SIMDE_CMP_LE_OS), a);
      break;
    case 3:
      r = simde_mm_mask_mov_ps(a, simde_mm_cmp_ps_mask(simde_x_mm_abs_ps(b), simde_x_mm_abs_ps(a), SIMDE_CMP_GE_OS), b);
      break;
    default:
      break;
  }

  switch (imm8 & 12) {
    case 0:
      r = simde_x_mm_copysign_ps(r, a);
      break;
    case 8:
      r = simde_mm_andnot_ps(simde_mm_set1_ps(SIMDE_FLOAT32_C(-0.0)), r);
      break;
    case 12:
      r = simde_mm_or_ps(simde_mm_set1_ps(SIMDE_FLOAT32_C(-0.0)), r);
      break;
    default:
      break;
  }

  return r;
}
#if defined(SIMDE_X86_AVX512DQ_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
  #define simde_mm_range_ps(a, b, imm8) _mm_range_ps((a), (b), (imm8))
#endif
#if defined(SIMDE_X86_AVX512DQ_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm_range_ps
  #define _mm_range_ps(a, b, imm8) simde_mm_range_ps(a, b, imm8)
#endif

#if defined(SIMDE_X86_AVX512DQ_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
  #define simde_mm_mask_range_ps(src, k, a, b, imm8) _mm_mask_range_ps(src, k, a, b, imm8)
#else
  #define simde_mm_mask_range_ps(src, k, a, b, imm8) simde_mm_mask_mov_ps(src, k, simde_mm_range_ps(a, b, imm8))
#endif
#if defined(SIMDE_X86_AVX512DQ_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm_mask_range_ps
  #define _mm_mask_range_ps(src, k, a, b, imm8) simde_mm_mask_range_ps(src, k, a, b, imm8)
#endif

#if defined(SIMDE_X86_AVX512DQ_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
  #define simde_mm_maskz_range_ps(k, a, b, imm8) _mm_maskz_range_ps(k, a, b, imm8)
#else
  #define simde_mm_maskz_range_ps(k, a, b, imm8) simde_mm_maskz_mov_ps(k, simde_mm_range_ps(a, b, imm8))
#endif
#if defined(SIMDE_X86_AVX512DQ_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm_maskz_range_ps
  #define _mm_maskz_range_ps(k, a, b, imm8) simde_mm_maskz_range_ps(k, a, b, imm8)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256
simde_mm256_range_ps (simde__m256 a, simde__m256 b, int imm8)
    SIMDE_REQUIRE_CONSTANT_RANGE(imm8, 0, 15) {
  simde__m256 r;

  switch (imm8 & 3) {
    case 0:
      r = simde_mm256_min_ps(a, b);
      break;
    case 1:
      r = simde_mm256_max_ps(a, b);
      break;
    case 2:
      r = simde_mm256_mask_mov_ps(b, simde_mm256_cmp_ps_mask(simde_x_mm256_abs_ps(a), simde_x_mm256_abs_ps(b), SIMDE_CMP_LE_OS), a);
      break;
    case 3:
      r = simde_mm256_mask_mov_ps(a, simde_mm256_cmp_ps_mask(simde_x_mm256_abs_ps(b), simde_x_mm256_abs_ps(a), SIMDE_CMP_GE_OS), b);
      break;
    default:
      break;
  }

  switch (imm8 & 12) {
    case 0:
      r = simde_x_mm256_copysign_ps(r, a);
      break;
    case 8:
      r = simde_mm256_andnot_ps(simde_mm256_set1_ps(SIMDE_FLOAT32_C(-0.0)), r);
      break;
    case 12:
      r = simde_mm256_or_ps(simde_mm256_set1_ps(SIMDE_FLOAT32_C(-0.0)), r);
      break;
    default:
      break;
  }

  return r;
}
#if defined(SIMDE_X86_AVX512DQ_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
  #define simde_mm256_range_ps(a, b, imm8) _mm256_range_ps((a), (b), (imm8))
#elif SIMDE_NATURAL_VECTOR_SIZE_LE(128) && defined(SIMDE_STATEMEN_EXPR_)
  #define simde_mm256_range_ps(a, b, imm8) SIMDE_STATEMENT_EXPR_({ \
      simde__m256_private \
        simde_mm256_range_ps_r_, \
        simde_mm256_range_ps_a_ = simde__m256_to_private(a), \
        simde_mm256_range_ps_b_ = simde__m256_to_private(b); \
      \
      for (size_t i = 0 ; i < (sizeof(simde_mm256_range_ps_r_.m128) / sizeof(simde_mm256_range_ps_r_.m128[0])) ; i++) { \
        simde_mm256_range_ps_r_.m128[i] = simde_mm_range_ps(simde_mm256_range_ps_a_.m128[i], simde_mm256_range_ps_b_.m128[i], imm8); \
      } \
      \
      simde__m256_from_private(simde_mm256_range_ps_r_); \
    })
#endif
#if defined(SIMDE_X86_AVX512DQ_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm256_range_ps
  #define _mm256_range_ps(a, b, imm8) simde_mm256_range_ps(a, b, imm8)
#endif

#if defined(SIMDE_X86_AVX512DQ_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
  #define simde_mm256_mask_range_ps(src, k, a, b, imm8) _mm256_mask_range_ps(src, k, a, b, imm8)
#else
  #define simde_mm256_mask_range_ps(src, k, a, b, imm8) simde_mm256_mask_mov_ps(src, k, simde_mm256_range_ps(a, b, imm8))
#endif
#if defined(SIMDE_X86_AVX512DQ_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm256_mask_range_ps
  #define _mm256_mask_range_ps(src, k, a, b, imm8) simde_mm256_mask_range_ps(src, k, a, b, imm8)
#endif

#if defined(SIMDE_X86_AVX512DQ_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
  #define simde_mm256_maskz_range_ps(k, a, b, imm8) _mm256_maskz_range_ps(k, a, b, imm8)
#else
  #define simde_mm256_maskz_range_ps(k, a, b, imm8) simde_mm256_maskz_mov_ps(k, simde_mm256_range_ps(a, b, imm8))
#endif
#if defined(SIMDE_X86_AVX512DQ_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm256_maskz_range_ps
  #define _mm256_maskz_range_ps(k, a, b, imm8) simde_mm256_maskz_range_ps(k, a, b, imm8)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512
simde_mm512_range_ps (simde__m512 a, simde__m512 b, int imm8)
    SIMDE_REQUIRE_CONSTANT_RANGE(imm8, 0, 15) {
  simde__m512 r;

  switch (imm8 & 3) {
    case 0:
      r = simde_mm512_min_ps(a, b);
      break;
    case 1:
      r = simde_mm512_max_ps(a, b);
      break;
    case 2:
      r = simde_mm512_mask_mov_ps(b, simde_mm512_cmp_ps_mask(simde_mm512_abs_ps(a), simde_mm512_abs_ps(b), SIMDE_CMP_LE_OS), a);
      break;
    case 3:
      r = simde_mm512_mask_mov_ps(a, simde_mm512_cmp_ps_mask(simde_mm512_abs_ps(b), simde_mm512_abs_ps(a), SIMDE_CMP_GE_OS), b);
      break;
    default:
      break;
  }

  switch (imm8 & 12) {
    case 0:
      r = simde_x_mm512_copysign_ps(r, a);
      break;
    case 8:
      r = simde_mm512_andnot_ps(simde_mm512_set1_ps(SIMDE_FLOAT32_C(-0.0)), r);
      break;
    case 12:
      r = simde_mm512_or_ps(simde_mm512_set1_ps(SIMDE_FLOAT32_C(-0.0)), r);
      break;
    default:
      break;
  }

  return r;
}
#if defined(SIMDE_X86_AVX512DQ_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
  #define simde_mm512_range_ps(a, b, imm8) _mm512_range_ps((a), (b), (imm8))
#elif SIMDE_NATURAL_VECTOR_SIZE_LE(128) && defined(SIMDE_STATEMEN_EXPR_)
  #define simde_mm512_range_ps(a, b, imm8) SIMDE_STATEMENT_EXPR_({ \
      simde__m512_private \
        simde_mm512_range_ps_r_, \
        simde_mm512_range_ps_a_ = simde__m512_to_private(a), \
        simde_mm512_range_ps_b_ = simde__m512_to_private(b); \
      \
      for (size_t i = 0 ; i < (sizeof(r_.m128) / sizeof(r_.m128[0])) ; i++) { \
        simde_mm256_range_ps_r_.m256[i] = simde_mm256_range_ps(simde_mm256_range_ps_a_.m128[i], simde_mm256_range_ps_b_.m128[i], imm8); \
      } \
      \
      simde__m512_from_private(simde_mm512_range_ps_r_); \
    })
#elif SIMDE_NATURAL_VECTOR_SIZE_LE(256) && defined(SIMDE_STATEMEN_EXPR_)
  #define simde_mm512_range_ps(a, b, imm8) SIMDE_STATEMENT_EXPR_({ \
      simde__m512_private \
        simde_mm512_range_ps_r_, \
        simde_mm512_range_ps_a_ = simde__m512_to_private(a), \
        simde_mm512_range_ps_b_ = simde__m512_to_private(b); \
      \
      for (size_t i = 0 ; i < (sizeof(simde_mm256_range_ps_r_.m256) / sizeof(simde_mm256_range_ps_r_.m256[0])) ; i++) { \
        simde_mm256_range_ps_r_.m256[i] = simde_mm256_range_ps(simde_mm256_range_ps_a_.m256[i], simde_mm256_range_ps_b_.m256[i], imm8); \
      } \
      \
      simde__m256_from_private(simde_mm256_range_ps_r_); \
    })
#endif
#if defined(SIMDE_X86_AVX512DQ_ENABLE_NATIVE_ALIASES)
  #undef _mm512_range_ps
  #define _mm512_range_ps(a, b, imm8) simde_mm512_range_ps(a, b, imm8)
#endif

#if defined(SIMDE_X86_AVX512DQ_NATIVE)
  #define simde_mm512_mask_range_ps(src, k, a, b, imm8) _mm512_mask_range_ps(src, k, a, b, imm8)
#else
  #define simde_mm512_mask_range_ps(src, k, a, b, imm8) simde_mm512_mask_mov_ps(src, k, simde_mm512_range_ps(a, b, imm8))
#endif
#if defined(SIMDE_X86_AVX512DQ_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_range_ps
  #define _mm512_mask_range_ps(src, k, a, b, imm8) simde_mm512_mask_range_ps(src, k, a, b, imm8)
#endif

#if defined(SIMDE_X86_AVX512DQ_NATIVE)
  #define simde_mm512_maskz_range_ps(k, a, b, imm8) _mm512_maskz_range_ps(k, a, b, imm8)
#else
  #define simde_mm512_maskz_range_ps(k, a, b, imm8) simde_mm512_maskz_mov_ps(k, simde_mm512_range_ps(a, b, imm8))
#endif
#if defined(SIMDE_X86_AVX512DQ_ENABLE_NATIVE_ALIASES)
  #undef _mm512_maskz_range_ps
  #define _mm512_maskz_range_ps(k, a, b, imm8) simde_mm512_maskz_range_ps(k, a, b, imm8)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128d
simde_mm_range_pd (simde__m128d a, simde__m128d b, int imm8)
    SIMDE_REQUIRE_CONSTANT_RANGE(imm8, 0, 15) {
  simde__m128d r;

  switch (imm8 & 3) {
    case 0:
      r = simde_mm_min_pd(a, b);
      break;
    case 1:
      r = simde_mm_max_pd(a, b);
      break;
    case 2:
      r = simde_mm_mask_mov_pd(b, simde_mm_cmp_pd_mask(simde_x_mm_abs_pd(a), simde_x_mm_abs_pd(b), SIMDE_CMP_LE_OS), a);
      break;
    case 3:
      r = simde_mm_mask_mov_pd(a, simde_mm_cmp_pd_mask(simde_x_mm_abs_pd(b), simde_x_mm_abs_pd(a), SIMDE_CMP_GE_OS), b);
      break;
    default:
      break;
  }

  switch (imm8 & 12) {
    case 0:
      r = simde_x_mm_copysign_pd(r, a);
      break;
    case 8:
      r = simde_mm_andnot_pd(simde_mm_set1_pd(SIMDE_FLOAT64_C(-0.0)), r);
      break;
    case 12:
      r = simde_mm_or_pd(simde_mm_set1_pd(SIMDE_FLOAT64_C(-0.0)), r);
      break;
    default:
      break;
  }

  return r;
}
#if defined(SIMDE_X86_AVX512DQ_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
  #define simde_mm_range_pd(a, b, imm8) _mm_range_pd((a), (b), (imm8))
#endif
#if defined(SIMDE_X86_AVX512DQ_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm_range_pd
  #define _mm_range_pd(a, b, imm8) simde_mm_range_pd(a, b, imm8)
#endif

#if defined(SIMDE_X86_AVX512DQ_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
  #define simde_mm_mask_range_pd(src, k, a, b, imm8) _mm_mask_range_pd(src, k, a, b, imm8)
#else
  #define simde_mm_mask_range_pd(src, k, a, b, imm8) simde_mm_mask_mov_pd(src, k, simde_mm_range_pd(a, b, imm8))
#endif
#if defined(SIMDE_X86_AVX512DQ_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm_mask_range_pd
  #define _mm_mask_range_pd(src, k, a, b, imm8) simde_mm_mask_range_pd(src, k, a, b, imm8)
#endif

#if defined(SIMDE_X86_AVX512DQ_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
  #define simde_mm_maskz_range_pd(k, a, b, imm8) _mm_maskz_range_pd(k, a, b, imm8)
#else
  #define simde_mm_maskz_range_pd(k, a, b, imm8) simde_mm_maskz_mov_pd(k, simde_mm_range_pd(a, b, imm8))
#endif
#if defined(SIMDE_X86_AVX512DQ_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm_maskz_range_pd
  #define _mm_maskz_range_pd(k, a, b, imm8) simde_mm_maskz_range_pd(k, a, b, imm8)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256d
simde_mm256_range_pd (simde__m256d a, simde__m256d b, int imm8)
    SIMDE_REQUIRE_CONSTANT_RANGE(imm8, 0, 15) {
  simde__m256d r;

  switch (imm8 & 3) {
    case 0:
      r = simde_mm256_min_pd(a, b);
      break;
    case 1:
      r = simde_mm256_max_pd(a, b);
      break;
    case 2:
      r = simde_mm256_mask_mov_pd(b, simde_mm256_cmp_pd_mask(simde_x_mm256_abs_pd(a), simde_x_mm256_abs_pd(b), SIMDE_CMP_LE_OS), a);
      break;
    case 3:
      r = simde_mm256_mask_mov_pd(a, simde_mm256_cmp_pd_mask(simde_x_mm256_abs_pd(b), simde_x_mm256_abs_pd(a), SIMDE_CMP_GE_OS), b);
      break;
    default:
      break;
  }

  switch (imm8 & 12) {
    case 0:
      r = simde_x_mm256_copysign_pd(r, a);
      break;
    case 8:
      r = simde_mm256_andnot_pd(simde_mm256_set1_pd(SIMDE_FLOAT64_C(-0.0)), r);
      break;
    case 12:
      r = simde_mm256_or_pd(simde_mm256_set1_pd(SIMDE_FLOAT64_C(-0.0)), r);
      break;
    default:
      break;
  }

  return r;
}
#if defined(SIMDE_X86_AVX512DQ_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
  #define simde_mm256_range_pd(a, b, imm8) _mm256_range_pd((a), (b), (imm8))
#elif SIMDE_NATURAL_VECTOR_SIZE_LE(128) && defined(SIMDE_STATEMEN_EXPR_)
  #define simde_mm256_range_pd(a, b, imm8) SIMDE_STATEMENT_EXPR_({ \
      simde__m256d_private \
        simde_mm256_range_pd_r_, \
        simde_mm256_range_pd_a_ = simde__m256d_to_private(a), \
        simde_mm256_range_pd_b_ = simde__m256d_to_private(b); \
      \
      for (size_t i = 0 ; i < (sizeof(simde_mm256_range_pd_r_.m128d) / sizeof(simde_mm256_range_pd_r_.m128d[0])) ; i++) { \
        simde_mm256_range_pd_r_.m128d[i] = simde_mm_range_pd(simde_mm256_range_pd_a_.m128d[i], simde_mm256_range_pd_b_.m128d[i], imm8); \
      } \
      \
      simde__m256d_from_private(simde_mm256_range_pd_r_); \
    })
#endif
#if defined(SIMDE_X86_AVX512DQ_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm256_range_pd
  #define _mm256_range_pd(a, b, imm8) simde_mm256_range_pd(a, b, imm8)
#endif

#if defined(SIMDE_X86_AVX512DQ_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
  #define simde_mm256_mask_range_pd(src, k, a, b, imm8) _mm256_mask_range_pd(src, k, a, b, imm8)
#else
  #define simde_mm256_mask_range_pd(src, k, a, b, imm8) simde_mm256_mask_mov_pd(src, k, simde_mm256_range_pd(a, b, imm8))
#endif
#if defined(SIMDE_X86_AVX512DQ_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm256_mask_range_pd
  #define _mm256_mask_range_pd(src, k, a, b, imm8) simde_mm256_mask_range_pd(src, k, a, b, imm8)
#endif

#if defined(SIMDE_X86_AVX512DQ_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
  #define simde_mm256_maskz_range_pd(k, a, b, imm8) _mm256_maskz_range_pd(k, a, b, imm8)
#else
  #define simde_mm256_maskz_range_pd(k, a, b, imm8) simde_mm256_maskz_mov_pd(k, simde_mm256_range_pd(a, b, imm8))
#endif
#if defined(SIMDE_X86_AVX512DQ_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm256_maskz_range_pd
  #define _mm256_maskz_range_pd(k, a, b, imm8) simde_mm256_maskz_range_pd(k, a, b, imm8)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512d
simde_mm512_range_pd (simde__m512d a, simde__m512d b, int imm8)
    SIMDE_REQUIRE_CONSTANT_RANGE(imm8, 0, 15) {
  simde__m512d r;

  switch (imm8 & 3) {
    case 0:
      r = simde_mm512_min_pd(a, b);
      break;
    case 1:
      r = simde_mm512_max_pd(a, b);
      break;
    case 2:
      r = simde_mm512_mask_mov_pd(b, simde_mm512_cmp_pd_mask(simde_mm512_abs_pd(a), simde_mm512_abs_pd(b), SIMDE_CMP_LE_OS), a);
      break;
    case 3:
      r = simde_mm512_mask_mov_pd(a, simde_mm512_cmp_pd_mask(simde_mm512_abs_pd(b), simde_mm512_abs_pd(a), SIMDE_CMP_GE_OS), b);
      break;
    default:
      break;
  }

  switch (imm8 & 12) {
    case 0:
      r = simde_x_mm512_copysign_pd(r, a);
      break;
    case 8:
      r = simde_mm512_andnot_pd(simde_mm512_set1_pd(SIMDE_FLOAT64_C(-0.0)), r);
      break;
    case 12:
      r = simde_mm512_or_pd(simde_mm512_set1_pd(SIMDE_FLOAT64_C(-0.0)), r);
      break;
    default:
      break;
  }

  return r;
}
#if defined(SIMDE_X86_AVX512DQ_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
  #define simde_mm512_range_pd(a, b, imm8) _mm512_range_pd((a), (b), (imm8))
#elif SIMDE_NATURAL_VECTOR_SIZE_LE(128) && defined(SIMDE_STATEMEN_EXPR_)
  #define simde_mm512_range_pd(a, b, imm8) SIMDE_STATEMENT_EXPR_({ \
      simde__m512d_private \
        simde_mm512_range_pd_r_, \
        simde_mm512_range_pd_a_ = simde__m512d_to_private(a), \
        simde_mm512_range_pd_b_ = simde__m512d_to_private(b); \
      \
      for (size_t i = 0 ; i < (sizeof(rsimde_mm512_range_pd__.m128d) / sizeof(simde_mm512_range_pd_r_.m128d[0])) ; i++) { \
        simde_mm512_range_pd_r_.m256d[i] = simde_mm256_range_pd(simde_mm512_range_pd_a_.m128d[i], simde_mm512_range_pd_b_.m128d[i], imm8); \
      } \
      \
      simde__m512d_from_private(simde_mm512_range_pd_r_); \
    })
#elif SIMDE_NATURAL_VECTOR_SIZE_LE(256) && defined(SIMDE_STATEMEN_EXPR_)
  #define simde_mm512_range_pd(a, b, imm8) SIMDE_STATEMENT_EXPR_({ \
      simde__m512d_private \
        simde_mm512_range_pd_r_, \
        simde_mm512_range_pd_a_ = simde__m512d_to_private(a), \
        simde_mm512_range_pd_b_ = simde__m512d_to_private(b); \
      \
      for (size_t i = 0 ; i < (sizeof(simde_mm512_range_pd_r_.m256d) / sizeof(simde_mm512_range_pd_r_.m256d[0])) ; i++) { \
        simde_mm512_range_pd_r_.m256d[i] = simde_mm256_range_pd(simde_mm512_range_pd_a_.m256d[i], simde_mm512_range_pd_b_.m256d[i], imm8); \
      } \
      \
      simde__m256d_from_private(simde_mm256_range_pd_r_); \
    })
#endif
#if defined(SIMDE_X86_AVX512DQ_ENABLE_NATIVE_ALIASES)
  #undef _mm512_range_pd
  #define _mm512_range_pd(a, b, imm8) simde_mm512_range_pd(a, b, imm8)
#endif

#if defined(SIMDE_X86_AVX512DQ_NATIVE)
  #define simde_mm512_mask_range_pd(src, k, a, b, imm8) _mm512_mask_range_pd(src, k, a, b, imm8)
#else
  #define simde_mm512_mask_range_pd(src, k, a, b, imm8) simde_mm512_mask_mov_pd(src, k, simde_mm512_range_pd(a, b, imm8))
#endif
#if defined(SIMDE_X86_AVX512DQ_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_range_pd
  #define _mm512_mask_range_pd(src, k, a, b, imm8) simde_mm512_mask_range_pd(src, k, a, b, imm8)
#endif

#if defined(SIMDE_X86_AVX512DQ_NATIVE)
  #define simde_mm512_maskz_range_pd(k, a, b, imm8) _mm512_maskz_range_pd(k, a, b, imm8)
#else
  #define simde_mm512_maskz_range_pd(k, a, b, imm8) simde_mm512_maskz_mov_pd(k, simde_mm512_range_pd(a, b, imm8))
#endif
#if defined(SIMDE_X86_AVX512DQ_ENABLE_NATIVE_ALIASES)
  #undef _mm512_maskz_range_pd
  #define _mm512_maskz_range_pd(k, a, b, imm8) simde_mm512_maskz_range_pd(k, a, b, imm8)
#endif

SIMDE_END_DECLS_
HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_X86_AVX512_RANGE_H) */
