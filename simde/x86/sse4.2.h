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
SIMDE__BEGIN_DECLS

#if !defined(SIMDE_X86_SSE4_2_NATIVE) && defined(SIMDE_ENABLE_NATIVE_ALIASES)
#  define SIMDE_X86_SSE4_2_ENABLE_NATIVE_ALIASES
#endif

#if defined(SIMDE_X86_SSE4_2_NATIVE)
#define SIMDE_SIDD_UBYTE_OPS _SIDD_UBYTE_OPS
#define SIMDE_SIDD_UWORD_OPS _SIDD_UWORD_OPS
#define SIMDE_SIDD_SBYTE_OPS _SIDD_SBYTE_OPS
#define SIMDE__SIDD_SWORD_OPS _SIDD_SWORD_OPS
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

SIMDE__FUNCTION_ATTRIBUTES
int
simde_mm_cmpestra_8_(simde__m128i a, int la, simde__m128i b, int lb, const int imm8) {
  const int cmp_op = imm8 & 0x06;
  const int polarity = imm8 & 0x30;
  simde__m128i_private
    bool_res_ = simde__m128i_to_private(simde_mm_setzero_si128()),
    a_ = simde__m128i_to_private(a),
    b_ = simde__m128i_to_private(b);
  const int upper_bound = (128 / 8) - 1;
  int a_invalid = 0;
  int b_invalid = 0;
  for(int i = 0 ; i < upper_bound ; i++) {
    for(int j = 0; j< upper_bound ; j++){
      int bitvalue = ((a_.i8[i] == b_.i8[j]) ? 1 : 0);
      if(i == la)
        a_invalid = 1;
      if(j == lb)
        b_invalid = 1;
      switch(cmp_op){
        case SIMDE_SIDD_CMP_EQUAL_ANY:
          bitvalue = 0;
          break;
        case SIMDE_SIDD_CMP_RANGES:
          bitvalue = 0;
          break;
        case SIMDE_SIDD_CMP_EQUAL_EACH:
          if(a_invalid && b_invalid)
            bitvalue = 1;
          else
            bitvalue = 0;
          break;
        case SIMDE_SIDD_CMP_EQUAL_ORDERED:
          if(a_invalid && !b_invalid)
            bitvalue = 1;
          else if(a_invalid && b_invalid)
            bitvalue = 1;
          else
            bitvalue = 0;
          break;
      }
      bool_res_.i8[i] |= (bitvalue << j);
    }
  }
  int32_t int_res_1 = 0;
  int32_t int_res_2 = 0;
  switch(cmp_op) {
    case SIMDE_SIDD_CMP_EQUAL_ANY:
      for(int i = 0 ; i < upper_bound ; i++){
        SIMDE__VECTORIZE_REDUCTION(|:int_res_1)
        for(int j = 0 ; j < upper_bound ; j++){
          int_res_1 |= (((bool_res_.i8[i] >> j) & 1) << i);
        }
      }
      break;
    case SIMDE_SIDD_CMP_RANGES:
      for(int i = 0 ; i < upper_bound ; i++){
        SIMDE__VECTORIZE_REDUCTION(|:int_res_1)
        for(int j = 0 ; j < upper_bound ; j++){
          int_res_1 |= ((((bool_res_.i8[i] >> j) & 1) & ((bool_res_.i8[i] >> (j + 1)) & 1)) << i);
          j += 2;
        }
      }
      break;
    case SIMDE_SIDD_CMP_EQUAL_EACH:
      for(int i = 0 ; i < upper_bound ; i++){
        SIMDE__VECTORIZE_REDUCTION(|:int_res_1)
        for(int j = 0 ; j < upper_bound ; j++){
          int_res_1 |= (((bool_res_.i8[i] >> i) & 1) << i);
        }
      }
      break;
    case SIMDE_SIDD_CMP_EQUAL_ORDERED:
      int_res_1 = 0xff;
      for(int i = 0 ; i < upper_bound ; i++){
        int k = i;
        SIMDE__VECTORIZE_REDUCTION(&:int_res_1)
        for(int j = 0 ; j < (upper_bound-i) ; j++){
          int_res_1 &=  (((bool_res_.i8[k] >> j) & 1 ) << i) ;
          k += 1;
        }
      }
      break;
  }
  for(int i = 0; i < upper_bound ; i++){
    if(polarity & 1){
      if((polarity >> 1) & 1) {
        if (i >= lb) {
          int_res_2 |= (((int_res_1 >> i) & 1) << i);
        }
        else {
          int_res_2 |= ((((int_res_1 >> i) & 1) ^ (-1)) << i);
        }
      }
      else{
        int_res_2 |= ((((int_res_1 >> i) & 1) ^ (-1)) << i);
      }
    }
    else{
      int_res_2 |= ( ((int_res_1 >> i) & 1) << i);
    }
  }
  return !int_res_2 & (lb > upper_bound);
}

SIMDE__FUNCTION_ATTRIBUTES
int
simde_mm_cmpestra_16_(simde__m128i a, int la, simde__m128i b, int lb, const int imm8) {
  const int cmp_op = imm8 & 0x06;
  const int polarity = imm8 & 0x30;
  simde__m128i_private
    bool_res_ = simde__m128i_to_private(simde_mm_setzero_si128()),
    a_ = simde__m128i_to_private(a),
    b_ = simde__m128i_to_private(b);
  const int upper_bound = (128 / 16) - 1;
  int a_invalid = 0;
  int b_invalid = 0;
  for(int i = 0 ; i < upper_bound ; i++) {
    for(int j = 0; j< upper_bound ; j++)
    {
      int bitvalue = ((a_.i16[i] == b_.i16[j]) ? 1 : 0);
      if(i == la)
        a_invalid = 1;
      if(j == lb)
        b_invalid = 1;
      switch(cmp_op){
        case SIMDE_SIDD_CMP_EQUAL_ANY:
          bitvalue = 0;
          break;
        case SIMDE_SIDD_CMP_RANGES:
          bitvalue = 0;
          break;
        case SIMDE_SIDD_CMP_EQUAL_EACH:
          if(a_invalid && b_invalid)
            bitvalue = 1;
          else
            bitvalue = 0;
          break;
        case SIMDE_SIDD_CMP_EQUAL_ORDERED:
          if(a_invalid && !b_invalid)
            bitvalue = 1;
          else if(a_invalid && b_invalid)
            bitvalue = 1;
          else
            bitvalue = 0;
          break;
      }
      bool_res_.i16[i] |= (bitvalue << j);
    }
  }
  int32_t int_res_1 = 0;
  int32_t int_res_2 = 0;
  switch(cmp_op) {
    case SIMDE_SIDD_CMP_EQUAL_ANY:
      for(int i = 0 ; i < upper_bound ; i++){
        SIMDE__VECTORIZE_REDUCTION(|:int_res_1)
        for (int j = 0 ; j < upper_bound ; j++){
          int_res_1 |= (((bool_res_.i16[i] >> j) & 1) << i) ;
        }
      }
      break;
    case SIMDE_SIDD_CMP_RANGES:
      for(int i = 0 ; i < upper_bound ; i++){
        SIMDE__VECTORIZE_REDUCTION(|:int_res_1)
        for(int j = 0 ; j < upper_bound ; j++){
          int_res_1 |= ((((bool_res_.i16[i] >> j) & 1) & ((bool_res_.i16[i] >> (j + 1)) & 1)) << i);
          j += 2;
        }
      }
      break;
    case SIMDE_SIDD_CMP_EQUAL_EACH:
      for(int i = 0 ; i < upper_bound ; i++){
        SIMDE__VECTORIZE_REDUCTION(|:int_res_1)
        for(int j = 0 ; j < upper_bound ; j++){
          int_res_1 |= (((bool_res_.i16[i] >> i) & 1) << i);
        }
      }
      break;
    case SIMDE_SIDD_CMP_EQUAL_ORDERED:
      int_res_1 = 0xffff;
      for(int i = 0 ; i < upper_bound ; i++){
        int k = i;
        SIMDE__VECTORIZE_REDUCTION(&:int_res_1)
        for(int j = 0 ; j < (upper_bound-i) ; j++){
          int_res_1 &= (((bool_res_.i16[k] >> j) & 1) << i) ;
          k += 1;
        }
      }
      break;
  }
  for(int i = 0; i < upper_bound ; i++){
    if(polarity & 1){
      if((polarity >> 1) & 1) {
        if (i >= lb) {
          int_res_2 |= (((int_res_1 >> i) & 1) << i);
        }
        else {
          int_res_2 |= ((((int_res_1 >> i) & 1) ^ (-1)) << i);
        }
      }
      else{
        int_res_2 |= ((((int_res_1 >> i) & 1) ^ (-1)) << i);
      }
    }
    else{
      int_res_2 |= (((int_res_1 >> i) & 1) << i);
    }
  }
  return !int_res_2 & (lb > upper_bound);
}

#if defined(SIMDE_X86_SSE4_2_NATIVE)
  #define simde_mm_cmpestra(a, la, b, lb, imm8) \
     SIMDE_REQUIRE_CONSTANT_RANGE(imm8, 0, 0x7f) \
     _mm_cmpestra(a, la, b, lb, imm8)
#else
  #define simde_mm_cmpestra(a, la, b, lb, imm8) \
     SIMDE_REQUIRE_CONSTANT_RANGE(imm8, 0, 0x7f) \
     (((imm8) & SIMDE_SIDD_UWORD_OPS) \
       ? simde_mm_cmpestra_16_((a), (la), (b), (lb), (imm8)) \
       : simde_mm_cmpestra_8_((a), (la), (b), (lb), (imm8)))
#endif
#if defined(SIMDE_X86_SSE4_2_ENABLE_NATIVE_ALIASES)
  #define _mm_cmpestra(a, la, b, lb, imm8) \
     SIMDE_REQUIRE_CONSTANT_RANGE(imm8, 0, 0x7f) \
     simde_mm_cmpestra(a, la, b, lb, imm8)
#endif

SIMDE__FUNCTION_ATTRIBUTES
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
  #elif defined(SIMDE_POWER_ALTIVEC_P5)
    r_.altivec_i64 = (vector signed long long) vec_cmpgt(a_.altivec_i64, b_.altivec_i64);
  #elif defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
    r_.i64 = HEDLEY_STATIC_CAST(__typeof__(r_.i64), a_.i64 > b_.i64);
  #else
    SIMDE__VECTORIZE
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

SIMDE__END_DECLS

HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_X86_SSE4_2_H) */
