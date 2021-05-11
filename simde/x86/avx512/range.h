#if !defined(SIMDE_X86_AVX512_RANGE_H)
#define SIMDE_X86_AVX512_RANGE_H

#include "types.h"
#include "max.h"
#include "min.h"
#include "set1.h"
#include "and.h"
#include "or.h"
#include "copysign.h"
#include "abs.h"
#include "setzero.h"
#include "cmp.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

SIMDE_FUNCTION_ATTRIBUTES
simde__m512d
simde_mm512_range_pd (simde__m512d a, simde__m512d b, int imm8)
    SIMDE_REQUIRE_CONSTANT_RANGE(imm8, 0, 15) {
  #if defined(SIMDE_X86_AVX512DQ_NATIVE)
    simde__m512d r;
    SIMDE_CONSTIFY_16_(_mm512_range_pd, r, (HEDLEY_UNREACHABLE(), simde_mm512_setzero_pd ()), imm8, a, b);
    return r;
  #else
    simde__m512d r;

    if (imm8 & 1) {
      if (imm8 & 2) {
        r = simde_mm512_mask_mov_pd(a, simde_mm512_cmp_pd_mask(simde_mm512_abs_pd(b), simde_mm512_abs_pd(a), SIMDE_CMP_GE_OS), b);
      }
      else {
        r = simde_mm512_max_pd(a, b);
      }
    }
    else {
      if (imm8 & 2) {
        r = simde_mm512_mask_mov_pd(b, simde_mm512_cmp_pd_mask(simde_mm512_abs_pd(a), simde_mm512_abs_pd(b), SIMDE_CMP_LE_OS), a);
      }
      else {
        r = simde_mm512_min_pd(a, b);
      }
    }

    if (imm8 & 8) {
      if (imm8 & 4) {
        r = simde_x_mm512_copysign_pd(r, simde_mm512_set1_pd(SIMDE_FLOAT64_C(-0.0)));
      }
      else {
        r = simde_x_mm512_copysign_pd(r, simde_mm512_set1_pd(SIMDE_FLOAT64_C(0.0)));
      }
    }
    else if (!(imm8 & 4)){
      r = simde_x_mm512_copysign_pd(r, a);
    }

    return r;
  #endif
}
#if defined(SIMDE_X86_AVX512DQ_ENABLE_NATIVE_ALIASES)
  #undef _mm512_range_pd
  #define _mm512_range_pd(a, b, imm8) simde_mm512_range_pd(a, b, imm8)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512
simde_mm512_range_ps (simde__m512 a, simde__m512 b, int imm8)
    SIMDE_REQUIRE_CONSTANT_RANGE(imm8, 0, 15) {
  #if defined(SIMDE_X86_AVX512DQ_NATIVE)
    simde__m512 r;
    SIMDE_CONSTIFY_16_(_mm512_range_ps, r, (HEDLEY_UNREACHABLE(), simde_mm512_setzero_ps ()), imm8, a, b);
    return r;
  #else
    simde__m512 r;

    if (imm8 & 1) {
      if (imm8 & 2) {
        r = simde_mm512_mask_mov_ps(a, simde_mm512_cmp_ps_mask(simde_mm512_abs_ps(b), simde_mm512_abs_ps(a), SIMDE_CMP_GE_OS), b);
      }
      else {
        r = simde_mm512_max_ps(a, b);
      }
    }
    else {
      if (imm8 & 2) {
        r = simde_mm512_mask_mov_ps(b, simde_mm512_cmp_ps_mask(simde_mm512_abs_ps(a), simde_mm512_abs_ps(b), SIMDE_CMP_LE_OS), a);
      }
      else {
        r = simde_mm512_min_ps(a, b);
      }
    }

    if (imm8 & 8) {
      if (imm8 & 4) {
        r = simde_x_mm512_copysign_ps(r, simde_mm512_set1_ps(SIMDE_FLOAT64_C(-0.0)));
      }
      else {
        r = simde_x_mm512_copysign_ps(r, simde_mm512_set1_ps(SIMDE_FLOAT64_C(0.0)));
      }
    }
    else if (!(imm8 & 4)){
      r = simde_x_mm512_copysign_ps(r, a);
    }

    return r;
  #endif
}
#if defined(SIMDE_X86_AVX512DQ_ENABLE_NATIVE_ALIASES)
  #undef _mm512_range_ps
  #define _mm512_range_ps(a, b, imm8) simde_mm512_range_ps(a, b, imm8)
#endif

SIMDE_END_DECLS_
HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_X86_AVX512_RANGE_H) */
