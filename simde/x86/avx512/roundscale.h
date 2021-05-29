#if !defined(SIMDE_X86_AVX512_ROUNDSCALE_H)
#define SIMDE_X86_AVX512_ROUNDSCALE_H

#include "types.h"
#include "andnot.h"
#include "set1.h"
#include "mul.h"
#include "round.h"
#include "cmpeq.h"

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

    clear_sign = simde_mm_andnot_ps(simde_mm_set1_ps(SIMDE_FLOAT32_C(-0.0)), result);
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

#if defined(SIMDE_X86_AVX512VL_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
  #define simde_mm256_roundscale_ps(a, imm8) _mm256_roundscale_ps((a), (imm8))
#elif SIMDE_NATURAL_VECTOR_SIZE_LE(128) && defined(SIMDE_STATEMENT_EXPR_)
  #define simde_mm256_roundscale_ps(a, imm8) SIMDE_STATEMENT_EXPR_(({ \
    simde__m256_private \
      simde_mm256_roundscale_ps_r_, \
      simde_mm256_roundscale_ps_a_ = simde__m256_to_private(a); \
    \
    for (size_t simde_mm256_roundscale_ps_i = 0 ; simde_mm256_roundscale_ps_i < (sizeof(simde_mm256_roundscale_ps_r_.m128) / sizeof(simde_mm256_roundscale_ps_r_.m128[0])) ; simde_mm256_roundscale_ps_i++) { \
      simde_mm256_roundscale_ps_r_.m128[simde_mm256_roundscale_ps_i] = simde_mm_roundscale_ps(simde_mm256_roundscale_ps_a_.m128[simde_mm256_roundscale_ps_i], imm8); \
    } \
    \
    simde__m256_from_private(simde_mm256_roundscale_ps_r_); \
  }))
#else
  SIMDE_FUNCTION_ATTRIBUTES
  simde__m256
  simde_mm256_roundscale_ps_internal_ (simde__m256 result, simde__m256 a, int imm8)
      SIMDE_REQUIRE_CONSTANT_RANGE(imm8, 0, 255) {
    HEDLEY_STATIC_CAST(void, imm8);

    simde__m256 r, clear_sign;

    clear_sign = simde_mm256_andnot_ps(simde_mm256_set1_ps(SIMDE_FLOAT32_C(-0.0)), result);
    r = simde_x_mm256_select_ps(result, a, simde_mm256_castsi256_ps(simde_mm256_cmpeq_epi32(simde_mm256_castps_si256(clear_sign), simde_mm256_castps_si256(simde_mm256_set1_ps(SIMDE_MATH_INFINITY)))));

    return r;
  }
  #define simde_mm256_roundscale_ps(a, imm8) \
    simde_mm256_roundscale_ps_internal_( \
      simde_mm256_mul_ps( \
        simde_mm256_round_ps( \
          simde_mm256_mul_ps( \
            a, \
            simde_mm256_set1_ps(simde_uint32_as_float32((127 + ((imm8 >> 4) & 15)) << 23))), \
          ((imm8) & 15) \
        ), \
        simde_mm256_set1_ps(simde_uint32_as_float32((127 - ((imm8 >> 4) & 15)) << 23)) \
      ), \
      (a), \
      (imm8) \
    )
#endif
#if defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm256_roundscale_ps
  #define _mm256_roundscale_ps(a, imm8) simde_mm256_roundscale_ps(a, imm8)
#endif

#if defined(SIMDE_X86_AVX512F_NATIVE)
  #define simde_mm512_roundscale_ps(a, imm8) _mm512_roundscale_ps((a), (imm8))
#elif SIMDE_NATURAL_VECTOR_SIZE_LE(256) && defined(SIMDE_STATEMENT_EXPR_)
  #define simde_mm512_roundscale_ps(a, imm8) SIMDE_STATEMENT_EXPR_(({ \
    simde__m512_private \
      simde_mm512_roundscale_ps_r_, \
      simde_mm512_roundscale_ps_a_ = simde__m512_to_private(a); \
    \
    for (size_t simde_mm512_roundscale_ps_i = 0 ; simde_mm512_roundscale_ps_i < (sizeof(simde_mm512_roundscale_ps_r_.m256) / sizeof(simde_mm512_roundscale_ps_r_.m256[0])) ; simde_mm512_roundscale_ps_i++) { \
      simde_mm512_roundscale_ps_r_.m256[simde_mm512_roundscale_ps_i] = simde_mm256_roundscale_ps(simde_mm512_roundscale_ps_a_.m256[simde_mm512_roundscale_ps_i], imm8); \
    } \
    \
    simde__m512_from_private(simde_mm512_roundscale_ps_r_); \
  }))
#else
  SIMDE_FUNCTION_ATTRIBUTES
  simde__m512
  simde_mm512_roundscale_ps_internal_ (simde__m512 result, simde__m512 a, int imm8)
      SIMDE_REQUIRE_CONSTANT_RANGE(imm8, 0, 255) {
    HEDLEY_STATIC_CAST(void, imm8);

    simde__m512 r, clear_sign;

    clear_sign = simde_mm512_andnot_ps(simde_mm512_set1_ps(SIMDE_FLOAT32_C(-0.0)), result);
    r = simde_mm512_mask_mov_ps(result, simde_mm512_cmpeq_epi32_mask(simde_mm512_castps_si512(clear_sign), simde_mm512_castps_si512(simde_mm512_set1_ps(SIMDE_MATH_INFINITY))), a);

    return r;
  }
  #define simde_mm512_roundscale_ps(a, imm8) \
    simde_mm512_roundscale_ps_internal_( \
      simde_mm512_mul_ps( \
        simde_x_mm512_round_ps( \
          simde_mm512_mul_ps( \
            a, \
            simde_mm512_set1_ps(simde_uint32_as_float32((127 + ((imm8 >> 4) & 15)) << 23))), \
          ((imm8) & 15) \
        ), \
        simde_mm512_set1_ps(simde_uint32_as_float32((127 - ((imm8 >> 4) & 15)) << 23)) \
      ), \
      (a), \
      (imm8) \
    )
#endif
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_roundscale_ps
  #define _mm512_roundscale_ps(a, imm8) simde_mm512_roundscale_ps(a, imm8)
#endif

#if defined(SIMDE_X86_AVX512VL_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
  #define simde_mm_roundscale_pd(a, imm8) _mm_roundscale_pd((a), (imm8))
#else
  SIMDE_FUNCTION_ATTRIBUTES
  simde__m128d
  simde_mm_roundscale_pd_internal_ (simde__m128d result, simde__m128d a, int imm8)
      SIMDE_REQUIRE_CONSTANT_RANGE(imm8, 0, 255) {
    HEDLEY_STATIC_CAST(void, imm8);

    simde__m128d r, clear_sign;

    clear_sign = simde_mm_andnot_pd(simde_mm_set1_pd(SIMDE_FLOAT64_C(-0.0)), result);
    r = simde_x_mm_select_pd(result, a, simde_mm_cmpeq_pd(clear_sign, simde_mm_set1_pd(SIMDE_MATH_INFINITY)));

    return r;
  }
  #define simde_mm_roundscale_pd(a, imm8) \
    simde_mm_roundscale_pd_internal_( \
      simde_mm_mul_pd( \
        simde_mm_round_pd( \
          simde_mm_mul_pd( \
            a, \
            simde_mm_set1_pd(simde_uint64_as_float64((UINT64_C(1023) + ((imm8 >> 4) & 15)) << 52))), \
          ((imm8) & 15) \
        ), \
        simde_mm_set1_pd(simde_uint64_as_float64((UINT64_C(1023) - ((imm8 >> 4) & 15)) << 52)) \
      ), \
      (a), \
      (imm8) \
    )
#endif
#if defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm_roundscale_ps
  #define _mm_roundscale_ps(a, imm8) simde_mm_roundscale_ps(a, imm8)
#endif

#if defined(SIMDE_X86_AVX512VL_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
  #define simde_mm256_roundscale_pd(a, imm8) _mm256_roundscale_pd((a), (imm8))
#elif SIMDE_NATURAL_VECTOR_SIZE_LE(128) && defined(SIMDE_STATEMENT_EXPR_)
  #define simde_mm256_roundscale_pd(a, imm8) SIMDE_STATEMENT_EXPR_(({ \
    simde__m256d_private \
      simde_mm256_roundscale_pd_r_, \
      simde_mm256_roundscale_pd_a_ = simde__m256d_to_private(a); \
    \
    for (size_t simde_mm256_roundscale_pd_i = 0 ; simde_mm256_roundscale_pd_i < (sizeof(simde_mm256_roundscale_pd_r_.m128d) / sizeof(simde_mm256_roundscale_pd_r_.m128d[0])) ; simde_mm256_roundscale_pd_i++) { \
      simde_mm256_roundscale_pd_r_.m128d[simde_mm256_roundscale_pd_i] = simde_mm_roundscale_pd(simde_mm256_roundscale_pd_a_.m128d[simde_mm256_roundscale_pd_i], imm8); \
    } \
    \
    simde__m256d_from_private(simde_mm256_roundscale_pd_r_); \
  }))
#else
  SIMDE_FUNCTION_ATTRIBUTES
  simde__m256d
  simde_mm256_roundscale_pd_internal_ (simde__m256d result, simde__m256d a, int imm8)
      SIMDE_REQUIRE_CONSTANT_RANGE(imm8, 0, 255) {
    HEDLEY_STATIC_CAST(void, imm8);

    simde__m256d r, clear_sign;

    clear_sign = simde_mm256_andnot_pd(simde_mm256_set1_pd(SIMDE_FLOAT64_C(-0.0)), result);
    r = simde_x_mm256_select_pd(result, a, simde_mm256_castsi256_pd(simde_mm256_cmpeq_epi64(simde_mm256_castpd_si256(clear_sign), simde_mm256_castpd_si256(simde_mm256_set1_pd(SIMDE_MATH_INFINITY)))));

    return r;
  }
  #define simde_mm256_roundscale_pd(a, imm8) \
    simde_mm256_roundscale_pd_internal_( \
      simde_mm256_mul_pd( \
        simde_mm256_round_pd( \
          simde_mm256_mul_pd( \
            a, \
            simde_mm256_set1_pd(simde_uint64_as_float64((UINT64_C(1023) + ((imm8 >> 4) & 15)) << 52))), \
          ((imm8) & 15) \
        ), \
        simde_mm256_set1_pd(simde_uint64_as_float64((UINT64_C(1023) - ((imm8 >> 4) & 15)) << 52)) \
      ), \
      (a), \
      (imm8) \
    )
#endif
#if defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm256_roundscale_pd
  #define _mm256_roundscale_pd(a, imm8) simde_mm256_roundscale_pd(a, imm8)
#endif

#if defined(SIMDE_X86_AVX512F_NATIVE)
  #define simde_mm512_roundscale_pd(a, imm8) _mm512_roundscale_pd((a), (imm8))
#elif SIMDE_NATURAL_VECTOR_SIZE_LE(256) && defined(SIMDE_STATEMENT_EXPR_)
  #define simde_mm512_roundscale_pd(a, imm8) SIMDE_STATEMENT_EXPR_(({ \
    simde__m512d_private \
      simde_mm512_roundscale_pd_r_, \
      simde_mm512_roundscale_pd_a_ = simde__m512d_to_private(a); \
    \
    for (size_t simde_mm512_roundscale_pd_i = 0 ; simde_mm512_roundscale_pd_i < (sizeof(simde_mm512_roundscale_pd_r_.m256d) / sizeof(simde_mm512_roundscale_pd_r_.m256d[0])) ; simde_mm512_roundscale_pd_i++) { \
      simde_mm512_roundscale_pd_r_.m256d[simde_mm512_roundscale_pd_i] = simde_mm256_roundscale_pd(simde_mm512_roundscale_pd_a_.m256d[simde_mm512_roundscale_pd_i], imm8); \
    } \
    \
    simde__m512d_from_private(simde_mm512_roundscale_pd_r_); \
  }))
#else
  SIMDE_FUNCTION_ATTRIBUTES
  simde__m512d
  simde_mm512_roundscale_pd_internal_ (simde__m512d result, simde__m512d a, int imm8)
      SIMDE_REQUIRE_CONSTANT_RANGE(imm8, 0, 255) {
    HEDLEY_STATIC_CAST(void, imm8);

    simde__m512d r, clear_sign;

    clear_sign = simde_mm512_andnot_pd(simde_mm512_set1_pd(SIMDE_FLOAT64_C(-0.0)), result);
    r = simde_mm512_mask_mov_pd(result, simde_mm512_cmpeq_epi64_mask(simde_mm512_castpd_si512(clear_sign), simde_mm512_castpd_si512(simde_mm512_set1_pd(SIMDE_MATH_INFINITY))), a);

    return r;
  }
  #define simde_mm512_roundscale_pd(a, imm8) \
    simde_mm512_roundscale_pd_internal_( \
      simde_mm512_mul_pd( \
        simde_x_mm512_round_pd( \
          simde_mm512_mul_pd( \
            a, \
            simde_mm512_set1_pd(simde_uint64_as_float64((UINT64_C(1023) + ((imm8 >> 4) & 15)) << 52))), \
          ((imm8) & 15) \
        ), \
        simde_mm512_set1_pd(simde_uint64_as_float64((UINT64_C(1023) - ((imm8 >> 4) & 15)) << 52)) \
      ), \
      (a), \
      (imm8) \
    )
#endif
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_roundscale_pd
  #define _mm512_roundscale_pd(a, imm8) simde_mm512_roundscale_pd(a, imm8)
#endif

SIMDE_END_DECLS_
HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_X86_AVX512_ROUNDSCALE_H) */
