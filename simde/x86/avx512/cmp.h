/* SPDX-License-Identifier: MIT
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use, copy,
 * modify, merge, publish, distribute, sublicense, and/or sell copies
 * of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
 * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
 * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 * Copyright:
 *   2020      Evan Nemerson <evan@nemerson.com>
 *   2020      Himanshi Mathur <himanshi18037@iiitd.ac.in>
 */

#if !defined(SIMDE_X86_AVX512_CMP_H)
#define SIMDE_X86_AVX512_CMP_H

#include "types.h"
#include "../avx2.h"
#include "mov.h"
#include "mov_mask.h"
#include "setzero.h"
#include "setone.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

SIMDE_FUNCTION_ATTRIBUTES
simde__mmask16
simde_mm512_cmp_ps_mask (simde__m512 a, simde__m512 b, const int imm8)
    SIMDE_REQUIRE_CONSTANT_RANGE(imm8, 0, 31) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    simde__mmask16 r;
    SIMDE_CONSTIFY_32_(_mm512_cmp_ps_mask, r, (HEDLEY_UNREACHABLE(), 0), imm8, a, b);
    return r;
  #else
    simde__m512_private
      r_,
      a_ = simde__m512_to_private(a),
      b_ = simde__m512_to_private(b);

    #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      switch (imm8) {
        case SIMDE_CMP_EQ_OQ:
          r_.i32 = HEDLEY_STATIC_CAST(__typeof__(r_.i32), (a_.f32 == b_.f32));
          break;
        case SIMDE_CMP_LT_OS:
          r_.i32 = HEDLEY_STATIC_CAST(__typeof__(r_.i32), (a_.f32 < b_.f32));
          break;
        case SIMDE_CMP_LE_OS:
          r_.i32 = HEDLEY_STATIC_CAST(__typeof__(r_.i32), (a_.f32 <= b_.f32));
          break;
        case SIMDE_CMP_UNORD_Q:
          #if defined(simde_math_isnanf)
            for (size_t i = 0 ; i < (sizeof(r_.f32) / sizeof(r_.f32[0])) ; i++) {
              r_.u32[i] = (simde_math_isnanf(a_.f32[i]) || simde_math_isnanf(b_.f32[i])) ? ~UINT32_C(0) : UINT32_C(0);
            }
          #else
            HEDLEY_UNREACHABLE();
          #endif
          break;
        case SIMDE_CMP_NEQ_UQ:
          r_.i32 = HEDLEY_STATIC_CAST(__typeof__(r_.i32), (a_.f32 != b_.f32));
          break;
        case SIMDE_CMP_NLT_US:
          r_.i32 = HEDLEY_STATIC_CAST(__typeof__(r_.i32), (a_.f32 >= b_.f32));
          break;
        case SIMDE_CMP_NLE_US:
          r_.i32 = HEDLEY_STATIC_CAST(__typeof__(r_.i32), (a_.f32 > b_.f32));
          break;
        case SIMDE_CMP_ORD_Q:
          #if defined(simde_math_isnanf)
            for (size_t i = 0 ; i < (sizeof(r_.f32) / sizeof(r_.f32[0])) ; i++) {
              r_.u32[i] = (!simde_math_isnanf(a_.f32[i]) && !simde_math_isnanf(b_.f32[i])) ? ~UINT32_C(0) : UINT32_C(0);
              }
          #else
            HEDLEY_UNREACHABLE();
          #endif
          break;
        case SIMDE_CMP_EQ_UQ:
          r_.i32 = HEDLEY_STATIC_CAST(__typeof__(r_.i32), (a_.f32 == b_.f32));
          break;
        case SIMDE_CMP_NGE_US:
          r_.i32 = HEDLEY_STATIC_CAST(__typeof__(r_.i32), (a_.f32 < b_.f32));
          break;
        case SIMDE_CMP_NGT_US:
          r_.i32 = HEDLEY_STATIC_CAST(__typeof__(r_.i32), (a_.f32 <= b_.f32));
          break;
        case SIMDE_CMP_FALSE_OQ:
          r_ = simde__m512_to_private(simde_mm512_setzero_ps());
          break;
        case SIMDE_CMP_NEQ_OQ:
          r_.i32 = HEDLEY_STATIC_CAST(__typeof__(r_.i32), (a_.f32 != b_.f32));
          break;
        case SIMDE_CMP_GE_OS:
          r_.i32 = HEDLEY_STATIC_CAST(__typeof__(r_.i32), (a_.f32 >= b_.f32));
          break;
        case SIMDE_CMP_GT_OS:
          r_.i32 = HEDLEY_STATIC_CAST(__typeof__(r_.i32), (a_.f32 > b_.f32));
          break;
        case SIMDE_CMP_TRUE_UQ:
          r_ = simde__m512_to_private(simde_x_mm512_setone_ps());
          break;
        case SIMDE_CMP_EQ_OS:
          r_.i32 = HEDLEY_STATIC_CAST(__typeof__(r_.i32), (a_.f32 == b_.f32));
          break;
        case SIMDE_CMP_LT_OQ:
          r_.i32 = HEDLEY_STATIC_CAST(__typeof__(r_.i32), (a_.f32 < b_.f32));
          break;
        case SIMDE_CMP_LE_OQ:
          r_.i32 = HEDLEY_STATIC_CAST(__typeof__(r_.i32), (a_.f32 <= b_.f32));
          break;
        case SIMDE_CMP_UNORD_S:
          #if defined(simde_math_isnanf)
            for (size_t i = 0 ; i < (sizeof(r_.f32) / sizeof(r_.f32[0])) ; i++) {
                r_.u32[i] = (simde_math_isnanf(a_.f32[i]) || simde_math_isnanf(b_.f32[i])) ? ~UINT32_C(0) : UINT32_C(0);
            }
          #else
            HEDLEY_UNREACHABLE();
          #endif
          break;
        case SIMDE_CMP_NEQ_US:
          r_.i32 = HEDLEY_STATIC_CAST(__typeof__(r_.i32), (a_.f32 != b_.f32));
          break;
        case SIMDE_CMP_NLT_UQ:
          r_.i32 = HEDLEY_STATIC_CAST(__typeof__(r_.i32), (a_.f32 >= b_.f32));
          break;
        case SIMDE_CMP_NLE_UQ:
          r_.i32 = HEDLEY_STATIC_CAST(__typeof__(r_.i32), (a_.f32 > b_.f32));
          break;
        case SIMDE_CMP_ORD_S:
          #if defined(simde_math_isnanf)
            for (size_t i = 0 ; i < (sizeof(r_.f32) / sizeof(r_.f32[0])) ; i++) {
              r_.u32[i] = (simde_math_isnanf(a_.f32[i]) || simde_math_isnanf(b_.f32[i])) ? UINT32_C(0) : ~UINT32_C(0);
            }
          #else
            HEDLEY_UNREACHABLE();
          #endif
          break;
        case SIMDE_CMP_EQ_US:
          r_.i32 = HEDLEY_STATIC_CAST(__typeof__(r_.i32), (a_.f32 == b_.f32));
          break;
        case SIMDE_CMP_NGE_UQ:
          r_.i32 = HEDLEY_STATIC_CAST(__typeof__(r_.i32), (a_.f32 < b_.f32));
          break;
        case SIMDE_CMP_NGT_UQ:
          r_.i32 = HEDLEY_STATIC_CAST(__typeof__(r_.i32), (a_.f32 <= b_.f32));
          break;
        case SIMDE_CMP_FALSE_OS:
          r_ = simde__m512_to_private(simde_mm512_setzero_ps());
          break;
        case SIMDE_CMP_NEQ_OS:
          r_.i32 = HEDLEY_STATIC_CAST(__typeof__(r_.i32), (a_.f32 != b_.f32));
          break;
        case SIMDE_CMP_GE_OQ:
          r_.i32 = HEDLEY_STATIC_CAST(__typeof__(r_.i32), (a_.f32 >= b_.f32));
          break;
        case SIMDE_CMP_GT_OQ:
          r_.i32 = HEDLEY_STATIC_CAST(__typeof__(r_.i32), (a_.f32 > b_.f32));
          break;
        case SIMDE_CMP_TRUE_US:
          r_ = simde__m512_to_private(simde_x_mm512_setone_ps());
          break;
        default:
          HEDLEY_UNREACHABLE();
          break;
      }
    #else /* defined(SIMDE_VECTOR_SUBSCRIPT_OPS) */
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.f32) / sizeof(r_.f32[0])) ; i++) {
        switch (imm8) {
          case SIMDE_CMP_EQ_OQ:
            r_.u32[i] = (a_.f32[i] == b_.f32[i]) ? ~UINT32_C(0) : UINT32_C(0);
            break;
          case SIMDE_CMP_LT_OS:
            r_.u32[i] = (a_.f32[i] < b_.f32[i]) ? ~UINT32_C(0) : UINT32_C(0);
            break;
          case SIMDE_CMP_LE_OS:
            r_.u32[i] = (a_.f32[i] <= b_.f32[i]) ? ~UINT32_C(0) : UINT32_C(0);
            break;
          case SIMDE_CMP_UNORD_Q:
            #if defined(simde_math_isnanf)
              r_.u32[i] = (simde_math_isnanf(a_.f32[i]) || simde_math_isnanf(b_.f32[i])) ? ~UINT32_C(0) : UINT32_C(0);
            #else
              HEDLEY_UNREACHABLE();
            #endif
            break;
          case SIMDE_CMP_NEQ_UQ:
            r_.u32[i] = (a_.f32[i] != b_.f32[i]) ? ~UINT32_C(0) : UINT32_C(0);
            break;
          case SIMDE_CMP_NLT_US:
            r_.u32[i] = (a_.f32[i] >= b_.f32[i]) ? ~UINT32_C(0) : UINT32_C(0);
            break;
          case SIMDE_CMP_NLE_US:
            r_.u32[i] = (a_.f32[i] > b_.f32[i]) ? ~UINT32_C(0) : UINT32_C(0);
            break;
          case SIMDE_CMP_ORD_Q:
            #if defined(simde_math_isnanf)
              r_.u32[i] = (!simde_math_isnanf(a_.f32[i]) && !simde_math_isnanf(b_.f32[i])) ? ~UINT32_C(0) : UINT32_C(0);
            #else
              HEDLEY_UNREACHABLE();
            #endif
            break;
          case SIMDE_CMP_EQ_UQ:
            r_.u32[i] = (a_.f32[i] == b_.f32[i]) ? ~UINT32_C(0) : UINT32_C(0);
            break;
          case SIMDE_CMP_NGE_US:
            r_.u32[i] = (a_.f32[i] < b_.f32[i]) ? ~UINT32_C(0) : UINT32_C(0);
            break;
          case SIMDE_CMP_NGT_US:
            r_.u32[i] = (a_.f32[i] <= b_.f32[i]) ? ~UINT32_C(0) : UINT32_C(0);
            break;
          case SIMDE_CMP_FALSE_OQ:
            r_.u32[i] = UINT32_C(0);
            break;
          case SIMDE_CMP_NEQ_OQ:
            r_.u32[i] = (a_.f32[i] != b_.f32[i]) ? ~UINT32_C(0) : UINT32_C(0);
            break;
          case SIMDE_CMP_GE_OS:
            r_.u32[i] = (a_.f32[i] >= b_.f32[i]) ? ~UINT32_C(0) : UINT32_C(0);
            break;
          case SIMDE_CMP_GT_OS:
            r_.u32[i] = (a_.f32[i] > b_.f32[i]) ? ~UINT32_C(0) : UINT32_C(0);
            break;
          case SIMDE_CMP_TRUE_UQ:
            r_.u32[i] = ~UINT32_C(0);
            break;
          case SIMDE_CMP_EQ_OS:
            r_.u32[i] = (a_.f32[i] == b_.f32[i]) ? ~UINT32_C(0) : UINT32_C(0);
            break;
          case SIMDE_CMP_LT_OQ:
            r_.u32[i] = (a_.f32[i] < b_.f32[i]) ? ~UINT32_C(0) : UINT32_C(0);
            break;
          case SIMDE_CMP_LE_OQ:
            r_.u32[i] = (a_.f32[i] <= b_.f32[i]) ? ~UINT32_C(0) : UINT32_C(0);
            break;
          case SIMDE_CMP_UNORD_S:
            #if defined(simde_math_isnanf)
              r_.u32[i] = (simde_math_isnanf(a_.f32[i]) || simde_math_isnanf(b_.f32[i])) ? ~UINT32_C(0) : UINT32_C(0);
            #else
              HEDLEY_UNREACHABLE();
            #endif
            break;
          case SIMDE_CMP_NEQ_US:
            r_.u32[i] = (a_.f32[i] != b_.f32[i]) ? ~UINT32_C(0) : UINT32_C(0);
            break;
          case SIMDE_CMP_NLT_UQ:
            r_.u32[i] = (a_.f32[i] >= b_.f32[i]) ? ~UINT32_C(0) : UINT32_C(0);
            break;
          case SIMDE_CMP_NLE_UQ:
            r_.u32[i] = (a_.f32[i] > b_.f32[i]) ? ~UINT32_C(0) : UINT32_C(0);
            break;
          case SIMDE_CMP_ORD_S:
            #if defined(simde_math_isnanf)
              r_.u32[i] = (simde_math_isnanf(a_.f32[i]) || simde_math_isnanf(b_.f32[i])) ? UINT32_C(0) : ~UINT32_C(0);
            #else
              HEDLEY_UNREACHABLE();
            #endif
            break;
          case SIMDE_CMP_EQ_US:
            r_.u32[i] = (a_.f32[i] == b_.f32[i]) ? ~UINT32_C(0) : UINT32_C(0);
            break;
          case SIMDE_CMP_NGE_UQ:
            r_.u32[i] = (a_.f32[i] < b_.f32[i]) ? ~UINT32_C(0) : UINT32_C(0);
            break;
          case SIMDE_CMP_NGT_UQ:
            r_.u32[i] = (a_.f32[i] <= b_.f32[i]) ? ~UINT32_C(0) : UINT32_C(0);
            break;
          case SIMDE_CMP_FALSE_OS:
            r_.u32[i] = UINT32_C(0);
            break;
          case SIMDE_CMP_NEQ_OS:
            r_.u32[i] = (a_.f32[i] != b_.f32[i]) ? ~UINT32_C(0) : UINT32_C(0);
            break;
          case SIMDE_CMP_GE_OQ:
            r_.u32[i] = (a_.f32[i] >= b_.f32[i]) ? ~UINT32_C(0) : UINT32_C(0);
            break;
          case SIMDE_CMP_GT_OQ:
            r_.u32[i] = (a_.f32[i] > b_.f32[i]) ? ~UINT32_C(0) : UINT32_C(0);
            break;
          case SIMDE_CMP_TRUE_US:
            r_.u32[i] = ~UINT32_C(0);
            break;
          default:
            HEDLEY_UNREACHABLE();
            break;
        }
      }
    #endif

    return simde_mm512_movepi32_mask(simde_mm512_castps_si512(simde__m512_from_private(r_)));
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_cmp_ps_mask
  #define _mm512_cmp_ps_mask(a, b, imm8) simde_mm512_cmp_ps_mask((a), (b), (imm8))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__mmask8
simde_mm512_cmp_pd_mask (simde__m512d a, simde__m512d b, const int imm8)
    SIMDE_REQUIRE_CONSTANT_RANGE(imm8, 0, 31) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    simde__mmask8 r;
    SIMDE_CONSTIFY_32_(_mm512_cmp_pd_mask, r, (HEDLEY_UNREACHABLE(), 0), imm8, a, b);
    return r;
  #else
    simde__m512d_private
      r_,
      a_ = simde__m512d_to_private(a),
      b_ = simde__m512d_to_private(b);

    #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      switch (imm8) {
        case SIMDE_CMP_EQ_OQ:
          r_.i64 = HEDLEY_STATIC_CAST(__typeof__(r_.i64), (a_.f64 == b_.f64));
          break;
        case SIMDE_CMP_LT_OS:
          r_.i64 = HEDLEY_STATIC_CAST(__typeof__(r_.i64), (a_.f64 < b_.f64));
          break;
        case SIMDE_CMP_LE_OS:
          r_.i64 = HEDLEY_STATIC_CAST(__typeof__(r_.i64), (a_.f64 <= b_.f64));
          break;
        case SIMDE_CMP_UNORD_Q:
          #if defined(simde_math_isnanf)
            for (size_t i = 0 ; i < (sizeof(r_.f64) / sizeof(r_.f64[0])) ; i++) {
              r_.u64[i] = (simde_math_isnanf(a_.f64[i]) || simde_math_isnanf(b_.f64[i])) ? ~UINT64_C(0) : UINT64_C(0);
            }
          #else
            HEDLEY_UNREACHABLE();
          #endif
          break;
        case SIMDE_CMP_NEQ_UQ:
          r_.i64 = HEDLEY_STATIC_CAST(__typeof__(r_.i64), (a_.f64 != b_.f64));
          break;
        case SIMDE_CMP_NLT_US:
          r_.i64 = HEDLEY_STATIC_CAST(__typeof__(r_.i64), (a_.f64 >= b_.f64));
          break;
        case SIMDE_CMP_NLE_US:
          r_.i64 = HEDLEY_STATIC_CAST(__typeof__(r_.i64), (a_.f64 > b_.f64));
          break;
        case SIMDE_CMP_ORD_Q:
          #if defined(simde_math_isnanf)
            for (size_t i = 0 ; i < (sizeof(r_.f64) / sizeof(r_.f64[0])) ; i++) {
              r_.u64[i] = (!simde_math_isnanf(a_.f64[i]) && !simde_math_isnanf(b_.f64[i])) ? ~UINT64_C(0) : UINT64_C(0);
              }
          #else
            HEDLEY_UNREACHABLE();
          #endif
          break;
        case SIMDE_CMP_EQ_UQ:
          r_.i64 = HEDLEY_STATIC_CAST(__typeof__(r_.i64), (a_.f64 == b_.f64));
          break;
        case SIMDE_CMP_NGE_US:
          r_.i64 = HEDLEY_STATIC_CAST(__typeof__(r_.i64), (a_.f64 < b_.f64));
          break;
        case SIMDE_CMP_NGT_US:
          r_.i64 = HEDLEY_STATIC_CAST(__typeof__(r_.i64), (a_.f64 <= b_.f64));
          break;
        case SIMDE_CMP_FALSE_OQ:
          r_ = simde__m512d_to_private(simde_mm512_setzero_pd());
          break;
        case SIMDE_CMP_NEQ_OQ:
          r_.i64 = HEDLEY_STATIC_CAST(__typeof__(r_.i64), (a_.f64 != b_.f64));
          break;
        case SIMDE_CMP_GE_OS:
          r_.i64 = HEDLEY_STATIC_CAST(__typeof__(r_.i64), (a_.f64 >= b_.f64));
          break;
        case SIMDE_CMP_GT_OS:
          r_.i64 = HEDLEY_STATIC_CAST(__typeof__(r_.i64), (a_.f64 > b_.f64));
          break;
        case SIMDE_CMP_TRUE_UQ:
          r_ = simde__m512d_to_private(simde_x_mm512_setone_pd());
          break;
        case SIMDE_CMP_EQ_OS:
          r_.i64 = HEDLEY_STATIC_CAST(__typeof__(r_.i64), (a_.f64 == b_.f64));
          break;
        case SIMDE_CMP_LT_OQ:
          r_.i64 = HEDLEY_STATIC_CAST(__typeof__(r_.i64), (a_.f64 < b_.f64));
          break;
        case SIMDE_CMP_LE_OQ:
          r_.i64 = HEDLEY_STATIC_CAST(__typeof__(r_.i64), (a_.f64 <= b_.f64));
          break;
        case SIMDE_CMP_UNORD_S:
          #if defined(simde_math_isnanf)
            for (size_t i = 0 ; i < (sizeof(r_.f64) / sizeof(r_.f64[0])) ; i++) {
                r_.u64[i] = (simde_math_isnanf(a_.f64[i]) || simde_math_isnanf(b_.f64[i])) ? ~UINT64_C(0) : UINT64_C(0);
            }
          #else
            HEDLEY_UNREACHABLE();
          #endif
          break;
        case SIMDE_CMP_NEQ_US:
          r_.i64 = HEDLEY_STATIC_CAST(__typeof__(r_.i64), (a_.f64 != b_.f64));
          break;
        case SIMDE_CMP_NLT_UQ:
          r_.i64 = HEDLEY_STATIC_CAST(__typeof__(r_.i64), (a_.f64 >= b_.f64));
          break;
        case SIMDE_CMP_NLE_UQ:
          r_.i64 = HEDLEY_STATIC_CAST(__typeof__(r_.i64), (a_.f64 > b_.f64));
          break;
        case SIMDE_CMP_ORD_S:
          #if defined(simde_math_isnanf)
            for (size_t i = 0 ; i < (sizeof(r_.f64) / sizeof(r_.f64[0])) ; i++) {
              r_.u64[i] = (simde_math_isnanf(a_.f64[i]) || simde_math_isnanf(b_.f64[i])) ? UINT64_C(0) : ~UINT64_C(0);
            }
          #else
            HEDLEY_UNREACHABLE();
          #endif
          break;
        case SIMDE_CMP_EQ_US:
          r_.i64 = HEDLEY_STATIC_CAST(__typeof__(r_.i64), (a_.f64 == b_.f64));
          break;
        case SIMDE_CMP_NGE_UQ:
          r_.i64 = HEDLEY_STATIC_CAST(__typeof__(r_.i64), (a_.f64 < b_.f64));
          break;
        case SIMDE_CMP_NGT_UQ:
          r_.i64 = HEDLEY_STATIC_CAST(__typeof__(r_.i64), (a_.f64 <= b_.f64));
          break;
        case SIMDE_CMP_FALSE_OS:
          r_ = simde__m512d_to_private(simde_mm512_setzero_pd());
          break;
        case SIMDE_CMP_NEQ_OS:
          r_.i64 = HEDLEY_STATIC_CAST(__typeof__(r_.i64), (a_.f64 != b_.f64));
          break;
        case SIMDE_CMP_GE_OQ:
          r_.i64 = HEDLEY_STATIC_CAST(__typeof__(r_.i64), (a_.f64 >= b_.f64));
          break;
        case SIMDE_CMP_GT_OQ:
          r_.i64 = HEDLEY_STATIC_CAST(__typeof__(r_.i64), (a_.f64 > b_.f64));
          break;
        case SIMDE_CMP_TRUE_US:
          r_ = simde__m512d_to_private(simde_x_mm512_setone_pd());
          break;
        default:
          HEDLEY_UNREACHABLE();
          break;
      }
    #else /* defined(SIMDE_VECTOR_SUBSCRIPT_OPS) */
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.f64) / sizeof(r_.f64[0])) ; i++) {
        switch (imm8) {
          case SIMDE_CMP_EQ_OQ:
            r_.u64[i] = (a_.f64[i] == b_.f64[i]) ? ~UINT64_C(0) : UINT64_C(0);
            break;
          case SIMDE_CMP_LT_OS:
            r_.u64[i] = (a_.f64[i] < b_.f64[i]) ? ~UINT64_C(0) : UINT64_C(0);
            break;
          case SIMDE_CMP_LE_OS:
            r_.u64[i] = (a_.f64[i] <= b_.f64[i]) ? ~UINT64_C(0) : UINT64_C(0);
            break;
          case SIMDE_CMP_UNORD_Q:
            #if defined(simde_math_isnanf)
              r_.u64[i] = (simde_math_isnanf(a_.f64[i]) || simde_math_isnanf(b_.f64[i])) ? ~UINT64_C(0) : UINT64_C(0);
            #else
              HEDLEY_UNREACHABLE();
            #endif
            break;
          case SIMDE_CMP_NEQ_UQ:
            r_.u64[i] = (a_.f64[i] != b_.f64[i]) ? ~UINT64_C(0) : UINT64_C(0);
            break;
          case SIMDE_CMP_NLT_US:
            r_.u64[i] = (a_.f64[i] >= b_.f64[i]) ? ~UINT64_C(0) : UINT64_C(0);
            break;
          case SIMDE_CMP_NLE_US:
            r_.u64[i] = (a_.f64[i] > b_.f64[i]) ? ~UINT64_C(0) : UINT64_C(0);
            break;
          case SIMDE_CMP_ORD_Q:
            #if defined(simde_math_isnanf)
              r_.u64[i] = (!simde_math_isnanf(a_.f64[i]) && !simde_math_isnanf(b_.f64[i])) ? ~UINT64_C(0) : UINT64_C(0);
            #else
              HEDLEY_UNREACHABLE();
            #endif
            break;
          case SIMDE_CMP_EQ_UQ:
            r_.u64[i] = (a_.f64[i] == b_.f64[i]) ? ~UINT64_C(0) : UINT64_C(0);
            break;
          case SIMDE_CMP_NGE_US:
            r_.u64[i] = (a_.f64[i] < b_.f64[i]) ? ~UINT64_C(0) : UINT64_C(0);
            break;
          case SIMDE_CMP_NGT_US:
            r_.u64[i] = (a_.f64[i] <= b_.f64[i]) ? ~UINT64_C(0) : UINT64_C(0);
            break;
          case SIMDE_CMP_FALSE_OQ:
            r_.u64[i] = UINT64_C(0);
            break;
          case SIMDE_CMP_NEQ_OQ:
            r_.u64[i] = (a_.f64[i] != b_.f64[i]) ? ~UINT64_C(0) : UINT64_C(0);
            break;
          case SIMDE_CMP_GE_OS:
            r_.u64[i] = (a_.f64[i] >= b_.f64[i]) ? ~UINT64_C(0) : UINT64_C(0);
            break;
          case SIMDE_CMP_GT_OS:
            r_.u64[i] = (a_.f64[i] > b_.f64[i]) ? ~UINT64_C(0) : UINT64_C(0);
            break;
          case SIMDE_CMP_TRUE_UQ:
            r_.u64[i] = ~UINT64_C(0);
            break;
          case SIMDE_CMP_EQ_OS:
            r_.u64[i] = (a_.f64[i] == b_.f64[i]) ? ~UINT64_C(0) : UINT64_C(0);
            break;
          case SIMDE_CMP_LT_OQ:
            r_.u64[i] = (a_.f64[i] < b_.f64[i]) ? ~UINT64_C(0) : UINT64_C(0);
            break;
          case SIMDE_CMP_LE_OQ:
            r_.u64[i] = (a_.f64[i] <= b_.f64[i]) ? ~UINT64_C(0) : UINT64_C(0);
            break;
          case SIMDE_CMP_UNORD_S:
            #if defined(simde_math_isnanf)
              r_.u64[i] = (simde_math_isnanf(a_.f64[i]) || simde_math_isnanf(b_.f64[i])) ? ~UINT64_C(0) : UINT64_C(0);
            #else
              HEDLEY_UNREACHABLE();
            #endif
            break;
          case SIMDE_CMP_NEQ_US:
            r_.u64[i] = (a_.f64[i] != b_.f64[i]) ? ~UINT64_C(0) : UINT64_C(0);
            break;
          case SIMDE_CMP_NLT_UQ:
            r_.u64[i] = (a_.f64[i] >= b_.f64[i]) ? ~UINT64_C(0) : UINT64_C(0);
            break;
          case SIMDE_CMP_NLE_UQ:
            r_.u64[i] = (a_.f64[i] > b_.f64[i]) ? ~UINT64_C(0) : UINT64_C(0);
            break;
          case SIMDE_CMP_ORD_S:
            #if defined(simde_math_isnanf)
              r_.u64[i] = (simde_math_isnanf(a_.f64[i]) || simde_math_isnanf(b_.f64[i])) ? UINT64_C(0) : ~UINT64_C(0);
            #else
              HEDLEY_UNREACHABLE();
            #endif
            break;
          case SIMDE_CMP_EQ_US:
            r_.u64[i] = (a_.f64[i] == b_.f64[i]) ? ~UINT64_C(0) : UINT64_C(0);
            break;
          case SIMDE_CMP_NGE_UQ:
            r_.u64[i] = (a_.f64[i] < b_.f64[i]) ? ~UINT64_C(0) : UINT64_C(0);
            break;
          case SIMDE_CMP_NGT_UQ:
            r_.u64[i] = (a_.f64[i] <= b_.f64[i]) ? ~UINT64_C(0) : UINT64_C(0);
            break;
          case SIMDE_CMP_FALSE_OS:
            r_.u64[i] = UINT64_C(0);
            break;
          case SIMDE_CMP_NEQ_OS:
            r_.u64[i] = (a_.f64[i] != b_.f64[i]) ? ~UINT64_C(0) : UINT64_C(0);
            break;
          case SIMDE_CMP_GE_OQ:
            r_.u64[i] = (a_.f64[i] >= b_.f64[i]) ? ~UINT64_C(0) : UINT64_C(0);
            break;
          case SIMDE_CMP_GT_OQ:
            r_.u64[i] = (a_.f64[i] > b_.f64[i]) ? ~UINT64_C(0) : UINT64_C(0);
            break;
          case SIMDE_CMP_TRUE_US:
            r_.u64[i] = ~UINT64_C(0);
            break;
          default:
            HEDLEY_UNREACHABLE();
            break;
        }
      }
    #endif

    return simde_mm512_movepi64_mask(simde_mm512_castpd_si512(simde__m512d_from_private(r_)));
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_cmp_pd_mask
  #define _mm512_cmp_pd_mask(a, b, imm8) simde_mm512_cmp_pd_mask((a), (b), (imm8))
#endif

SIMDE_END_DECLS_
HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_X86_AVX512_CMP_H) */
