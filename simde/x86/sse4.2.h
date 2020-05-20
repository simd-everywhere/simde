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
 *   2017      Evan Nemerson <evan@nemerson.com>
 */

#if !defined(SIMDE_X86_SSE4_2_H)
#define SIMDE_X86_SSE4_2_H

#include "sse4.1.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

#if !defined(SIMDE_X86_SSE4_2_NATIVE) && defined(SIMDE_ENABLE_NATIVE_ALIASES)
#  define SIMDE_X86_SSE4_2_ENABLE_NATIVE_ALIASES
#endif

#if defined(SIMDE_X86_SSE4_2_NATIVE)
  #define SIMDE_SIDD_UBYTE_OPS _SIDD_UBYTE_OPS
  #define SIMDE_SIDD_UWORD_OPS _SIDD_UWORD_OPS
  #define SIMDE_SIDD_SBYTE_OPS _SIDD_SBYTE_OPS
  #define SIMDE_SIDD_SWORD_OPS _SIDD_SWORD_OPS
  #define SIMDE_SIDD_CMP_EQUAL_ANY _SIDD_CMP_EQUAL_ANY
  #define SIMDE_SIDD_CMP_RANGES _SIDD_CMP_RANGES
  #define SIMDE_SIDD_CMP_EQUAL_EACH _SIDD_CMP_EQUAL_EACH
  #define SIMDE_SIDD_CMP_EQUAL_ORDERED _SIDD_CMP_EQUAL_ORDERED
  #define SIMDE_SIDD_POSITIVE_POLARITY _SIDD_POSITIVE_POLARITY
  #define SIMDE_SIDD_NEGATIVE_POLARITY _SIDD_NEGATIVE_POLARITY
  #define SIMDE_SIDD_MASKED_POSITIVE_POLARITY _SIDD_MASKED_POSITIVE_POLARITY
  #define SIMDE_SIDD_MASKED_NEGATIVE_POLARITY _SIDD_MASKED_NEGATIVE_POLARITY
  #define SIMDE_SIDD_LEAST_SIGNIFICANT _SIDD_LEAST_SIGNIFICANT
  #define SIMDE_SIDD_MOST_SIGNIFICANT _SIDD_MOST_SIGNIFICANT
  #define SIMDE_SIDD_BIT_MASK _SIDD_BIT_MASK
  #define SIMDE_SIDD_UNIT_MASK _SIDD_UNIT_MASK
#else
  #define SIMDE_SIDD_UBYTE_OPS 0x00
  #define SIMDE_SIDD_UWORD_OPS 0x01
  #define SIMDE_SIDD_SBYTE_OPS 0x02
  #define SIMDE_SIDD_SWORD_OPS 0x03
  #define SIMDE_SIDD_CMP_EQUAL_ANY 0x00
  #define SIMDE_SIDD_CMP_RANGES 0x04
  #define SIMDE_SIDD_CMP_EQUAL_EACH 0x08
  #define SIMDE_SIDD_CMP_EQUAL_ORDERED 0x0c
  #define SIMDE_SIDD_POSITIVE_POLARITY 0x00
  #define SIMDE_SIDD_NEGATIVE_POLARITY 0x10
  #define SIMDE_SIDD_MASKED_POSITIVE_POLARITY 0x20
  #define SIMDE_SIDD_MASKED_NEGATIVE_POLARITY 0x30
  #define SIMDE_SIDD_LEAST_SIGNIFICANT 0x00
  #define SIMDE_SIDD_MOST_SIGNIFICANT 0x40
  #define SIMDE_SIDD_BIT_MASK 0x00
  #define SIMDE_SIDD_UNIT_MASK 0x40
#endif

#if defined(SIMDE_X86_SSE4_2_ENABLE_NATIVE_ALIASES)
  #define _SIDD_UBYTE_OPS SIMDE_SIDD_UBYTE_OPS
  #define _SIDD_UWORD_OPS SIMDE_SIDD_UWORD_OPS
  #define _SIDD_SBYTE_OPS SIMDE_SIDD_SBYTE_OPS
  #define _SIDD_SWORD_OPS SIMDE_SIDD_SWORD_OPS
  #define _SIDD_CMP_EQUAL_ANY SIMDE_SIDD_CMP_EQUAL_ANY
  #define _SIDD_CMP_RANGES SIMDE_SIDD_CMP_RANGES
  #define _SIDD_CMP_EQUAL_EACH SIMDE_SIDD_CMP_EQUAL_EACH
  #define _SIDD_CMP_EQUAL_ORDERED SIMDE_SIDD_CMP_EQUAL_ORDERED
  #define _SIDD_POSITIVE_POLARITY SIMDE_SIDD_POSITIVE_POLARITY
  #define _SIDD_NEGATIVE_POLARITY SIMDE_SIDD_NEGATIVE_POLARITY
  #define _SIDD_MASKED_POSITIVE_POLARITY SIMDE_SIDD_MASKED_POSITIVE_POLARITY
  #define _SIDD_MASKED_NEGATIVE_POLARITY SIMDE_SIDD_MASKED_NEGATIVE_POLARITY
  #define _SIDD_LEAST_SIGNIFICANT SIMDE_SIDD_LEAST_SIGNIFICANT
  #define _SIDD_MOST_SIGNIFICANT SIMDE_SIDD_MOST_SIGNIFICANT
  #define _SIDD_BIT_MASK SIMDE_SIDD_BIT_MASK
  #define _SIDD_UNIT_MASK SIMDE_SIDD_UNIT_MASK
#endif

SIMDE_FUNCTION_ATTRIBUTES
int simde_mm_cmpestrs (simde__m128i a, int la, simde__m128i b, int lb, const int imm8)
    SIMDE_REQUIRE_CONSTANT_RANGE(imm8, 0, 127) {
  #if !defined(HEDLEY_PGI_VERSION)
    /* https://www.pgroup.com/userforum/viewtopic.php?f=4&p=27590&sid=cf89f8bf30be801831fe4a2ff0a2fa6c */
    (void) a;
    (void) b;
  #endif
  (void) la;
  (void) lb;
  return la <= ((128 / ((imm8 & SIMDE_SIDD_UWORD_OPS) ? 16 : 8)) - 1);
}
#if defined(SIMDE_X86_SSE4_2_NATIVE)
  #define simde_mm_cmpestrs(a, la, b, lb, imm8) _mm_cmpestrs(a, la, b, lb, imm8)
#endif
#if defined(SIMDE_X86_SSE4_2_ENABLE_NATIVE_ALIASES)
  #define _mm_cmpestrs(a, la, b, lb, imm8) simde_mm_cmpestrs(a, la, b, lb, imm8)
#endif

SIMDE_FUNCTION_ATTRIBUTES
int simde_mm_cmpestrz (simde__m128i a, int la, simde__m128i b, int lb, const int imm8)
    SIMDE_REQUIRE_CONSTANT_RANGE(imm8, 0, 127) {
  #if !defined(HEDLEY_PGI_VERSION)
    /* https://www.pgroup.com/userforum/viewtopic.php?f=4&p=27590&sid=cf89f8bf30be801831fe4a2ff0a2fa6c */
    (void) a;
    (void) b;
  #endif
  (void) la;
  (void) lb;
  return lb <= ((128 / ((imm8 & SIMDE_SIDD_UWORD_OPS) ? 16 : 8)) - 1);
}
#if defined(SIMDE_X86_SSE4_2_NATIVE)
  #define simde_mm_cmpestrz(a, la, b, lb, imm8) _mm_cmpestrz(a, la, b, lb, imm8)
#endif
#if defined(SIMDE_X86_SSE4_2_ENABLE_NATIVE_ALIASES)
  #define _mm_cmpestrz(a, la, b, lb, imm8) simde_mm_cmpestrz(a, la, b, lb, imm8)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_cmpgt_epi64 (simde__m128i a, simde__m128i b) {
#if defined(SIMDE_X86_SSE4_2_NATIVE)
  return _mm_cmpgt_epi64(a, b);
#else
  simde__m128i_private
    r_,
    a_ = simde__m128i_to_private(a),
    b_ = simde__m128i_to_private(b);

  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
    r_.neon_i64 = vreinterpretq_s64_u64(vcgtq_s64(a_.neon_i64, b_.neon_i64));
  #elif defined(SIMDE_POWER_ALTIVEC_P5_NATIVE)
    r_.altivec_i64 = (vector signed long long) vec_cmpgt(a_.altivec_i64, b_.altivec_i64);
  #elif defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
    r_.i64 = HEDLEY_STATIC_CAST(__typeof__(r_.i64), a_.i64 > b_.i64);
  #else
    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.i64) / sizeof(r_.i64[0])) ; i++) {
      r_.i64[i] = (a_.i64[i] > b_.i64[i]) ? ~INT64_C(0) : INT64_C(0);
    }
  #endif

  return simde__m128i_from_private(r_);
#endif
}
#if defined(SIMDE_X86_SSE4_2_ENABLE_NATIVE_ALIASES)
#  define _mm_cmpgt_epi64(a, b) simde_mm_cmpgt_epi64(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
int
simde_mm_cmpistrs_8_(simde__m128i a) {
  simde__m128i_private a_= simde__m128i_to_private(a);
  const int upper_bound = (128 / 8) - 1;
  int a_invalid = 0;
  SIMDE_VECTORIZE
  for (int i = 0 ; i < upper_bound ; i++) {
    if(!a_.i8[i])
      a_invalid = 1;
  }
  return a_invalid;
}

SIMDE_FUNCTION_ATTRIBUTES
int
simde_mm_cmpistrs_16_(simde__m128i a) {
  simde__m128i_private a_= simde__m128i_to_private(a);
  const int upper_bound = (128 / 16) - 1;
  int a_invalid = 0;
  SIMDE_VECTORIZE
  for (int i = 0 ; i < upper_bound ; i++) {
    if(!a_.i16[i])
      a_invalid = 1;
  }
  return a_invalid;
}

#if defined(SIMDE_X86_SSE4_2_NATIVE)
  #define simde_mm_cmpistrs(a, b, imm8) _mm_cmpistrs(a, b, imm8)
#else
  #define simde_mm_cmpistrs(a, b, imm8) \
     (((imm8) & SIMDE_SIDD_UWORD_OPS) \
       ? simde_mm_cmpistrs_16_((a)) \
       : simde_mm_cmpistrs_8_((a)))
#endif
#if defined(SIMDE_X86_SSE4_2_ENABLE_NATIVE_ALIASES)
  #define _mm_cmpistrs(a, b, imm8) simde_mm_cmpistrs(a, b, imm8)
#endif

SIMDE_FUNCTION_ATTRIBUTES
int
simde_mm_cmpistrz_8_(simde__m128i b) {
  simde__m128i_private b_= simde__m128i_to_private(b);
  const int upper_bound = (128 / 8) - 1;
  int b_invalid = 0;
  SIMDE_VECTORIZE
  for (int i = 0 ; i < upper_bound ; i++) {
    if(!b_.i8[i])
      b_invalid = 1;
  }
  return b_invalid;
}

SIMDE_FUNCTION_ATTRIBUTES
int
simde_mm_cmpistrz_16_(simde__m128i b) {
  simde__m128i_private b_= simde__m128i_to_private(b);
  const int upper_bound = (128 / 16) - 1;
  int b_invalid = 0;
  SIMDE_VECTORIZE
  for (int i = 0 ; i < upper_bound ; i++) {
    if(!b_.i16[i])
      b_invalid = 1;
  }
  return b_invalid;
}

#if defined(SIMDE_X86_SSE4_2_NATIVE)
  #define simde_mm_cmpistrz(a, b, imm8) _mm_cmpistrz(a, b, imm8)
#else
  #define simde_mm_cmpistrz(a, b, imm8) \
     (((imm8) & SIMDE_SIDD_UWORD_OPS) \
       ? simde_mm_cmpistrz_16_((b)) \
       : simde_mm_cmpistrz_8_((b)))
#endif
#if defined(SIMDE_X86_SSE4_2_ENABLE_NATIVE_ALIASES)
  #define _mm_cmpistrz(a, b, imm8) simde_mm_cmpistrz(a, b, imm8)
#endif

SIMDE_END_DECLS_

HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_X86_SSE4_2_H) */
