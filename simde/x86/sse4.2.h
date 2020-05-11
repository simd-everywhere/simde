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

#define SIMDE_SIDD_CMP_EQUAL_ANY     0
#define SIMDE_SIDD_CMP_RANGES     1
#define SIMDE_SIDD_CMP_EQUAL_EACH     2
#define SIMDE_SIDD_CMP_EQUAL_ORDERED   3

#if defined(SIMDE_X86_SSE4_2_ENABLE_NATIVE_ALIASES)
#define _SIDD_CMP_EQUAL_ANY SIMDE_SIDD_CMP_EQUAL_ANY
#define _SIDD_CMP_RANGES SIMDE_SIDD_CMP_RANGES
#define _SIDD_CMP_EQUAL_EACH SIMDE_SIDD_CMP_EQUAL_EACH
#define _SIDD_CMP_EQUAL_ORDERED SIMDE_SIDD_CMP_EQUAL_ORDERED
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
  for (size_t i = 0 ; i < (upper_bound) ; i++) {
    for(size_t j = 0; j< (upper_bound) ; j++){
      int bitvalue = ((a_.i8[i] == b_.i8[j]) ? 1 : 0);
      bool_res_.i8[i] |= (( bitvalue ) << j);
      if(i == la)
        a_invalid = 1;
      if(j == lb)
        b_invalid = 1;
      switch(((imm8 & 12) >> 2)){
        case SIMDE_SIDD_CMP_EQUAL_ANY:
          break;
        case SIMDE_SIDD_CMP_RANGES:
          break;
        case SIMDE_SIDD_CMP_EQUAL_EACH:
          if(a_invalid && b_invalid)
            bool_res_.i8[i] |= (1 << j);
          break;
        case SIMDE_SIDD_CMP_EQUAL_ORDERED:
          if(a_invalid && !b_invalid)
            bool_res_.i8[i] |= (1 << j);
          else if(a_invalid && b_invalid)
            bool_res_.i8[i] |= (1 << j);
          break;
      }
    }
  }
  int8_t int_res_1 = 0;
  int8_t int_res_2 = 0;
  switch( ((imm8 & 12) >> 2) ) {
    case SIMDE_SIDD_CMP_EQUAL_ANY:
      for(size_t i = 0 ; i < (upper_bound) ; i++){
        SIMDE__VECTORIZE_REDUCTION(|:int_res_1)
        for (size_t j = 0 ; j < (upper_bound) ; j++){
          int_res_1 |= (((bool_res_.i8[i] >> j) & 1) << i);
        }
      }
      break;
    case SIMDE_SIDD_CMP_RANGES:
      for(size_t i = 0 ; i < (upper_bound) ; i++){
        SIMDE__VECTORIZE_REDUCTION(|:int_res_1)
        for (size_t j = 0 ; j < (upper_bound) ; j++){
          int_res_1 |= ((((bool_res_.i8[i] >> j) & 1) & ((bool_res_.i8[i] >> (j + 1)) & 1)) << i);
          j += 2;
        }
      }
      break;
    case SIMDE_SIDD_CMP_EQUAL_EACH:
      for (size_t i = 0 ; i < (upper_bound) ; i++){
        SIMDE__VECTORIZE_REDUCTION(|:int_res_1)
        for (size_t j = 0 ; j < (upper_bound) ; j++){
          int_res_1 |= (((bool_res_.i8[i] >> i) & 1) << i);
        }
      }
      break;
    case SIMDE_SIDD_CMP_EQUAL_ORDERED:
      int_res_1 = (imm8 & 1) ? 0xff : 0xffff;
      for(size_t i = 0 ; i < (upper_bound) ; i++){
        size_t k = i;
        SIMDE__VECTORIZE_REDUCTION(|:int_res_1)
        for (size_t j = 0 ; j < (upper_bound-i) ; j++){
          int_res_1 &=  (((bool_res_.i8[k] >> j) & 1 ) << i) ;
          k += 1;
        }
      }
  }
  for(size_t i = 0; i < (upper_bound) ; i++){
    if((imm8 >> 4) & 1){
      if((imm8 >> 5) & 1) {
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
  return ( (int_res_2 == 0) & (lb > upper_bound) );
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
  for(size_t i = 0 ; i < (upper_bound) ; i++) {
    for(size_t j = 0; j< (upper_bound) ; j++)
    {
      int bitvalue = ((a_.i16[i] == b_.i16[j]) ? 1 : 0);
      bool_res_.i16[i] |= ((bitvalue) << j);
      if(i == la)
        a_invalid = 1;
      if(j == lb)
        b_invalid = 1;
      switch(((imm8 & 12) >> 2)){
        case SIMDE_SIDD_CMP_EQUAL_ANY:
          break;
        case SIMDE_SIDD_CMP_RANGES:
          break;
        case SIMDE_SIDD_CMP_EQUAL_EACH:
          if(a_invalid && b_invalid)
            bool_res_.i16[i] |= (1 << j);
          break;
        case SIMDE_SIDD_CMP_EQUAL_ORDERED:
          if(a_invalid && !b_invalid)
            bool_res_.i16[i] |= (1 << j);
          else if(a_invalid && b_invalid)
            bool_res_.i16[i] |= (1 << j);
          break;
      }
    }
  }
  int16_t int_res_1 = 0;
  int16_t int_res_2 = 0;
  switch(((imm8 & 12) >> 2)) {
    case SIMDE_SIDD_CMP_EQUAL_ANY:
      for(size_t i = 0 ; i < (upper_bound) ; i++){
        SIMDE__VECTORIZE_REDUCTION(|:int_res_1)
        for (size_t j = 0 ; j < (upper_bound) ; j++){
          int_res_1 |= (((bool_res_.i16[i] >> j) & 1) << i) ;
        }
      }
      break;
    case SIMDE_SIDD_CMP_RANGES:
      for(size_t i = 0 ; i < (upper_bound) ; i++){
        SIMDE__VECTORIZE_REDUCTION(|:int_res_1)
        for(size_t j = 0 ; j < (upper_bound) ; j++){
          int_res_1 |= ((((bool_res_.i16[i] >> j) & 1) & ((bool_res_.i16[i] >> (j + 1)) & 1)) << i);
          j += 2;
        }
      }
      break;
    case SIMDE_SIDD_CMP_EQUAL_EACH:
      for (size_t i = 0 ; i < (upper_bound) ; i++){
        SIMDE__VECTORIZE_REDUCTION(|:int_res_1)
        for (size_t j = 0 ; j < (upper_bound) ; j++){
          int_res_1 |= (((bool_res_.i16[i] >> i) & 1) << i);
        }
      }
      break;
    case SIMDE_SIDD_CMP_EQUAL_ORDERED:
      int_res_1 = (imm8 & 1) ? 0xff : 0xffff;
      for(size_t i = 0 ; i < (upper_bound) ; i++){
        size_t k = i;
        SIMDE__VECTORIZE_REDUCTION(|:int_res_1)
        for(size_t j = 0 ; j < (upper_bound-i) ; j++){
          int_res_1 &= (((bool_res_.i16[k] >> j) & 1) << i) ;
          k += 1;
        }
      }
  }
  for(size_t i = 0; i < (upper_bound) ; i++){
    if((imm8 >> 4) & 1){
      if((imm8 >> 5) & 1) {
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
  return ((int_res_2 == 0) & (lb > upper_bound));
}

SIMDE__FUNCTION_ATTRIBUTES
int
simde_mm_cmpestra(simde__m128i a, int la, simde__m128i b, int lb, const int imm8){
#if defined(SIMDE_X86_SSE4_2_NATIVE)
  return _mm_cmpestra(a, la, b, lb, imm8);
#else
  const int character_type = imm8 & 0x03;
  if(character_type & 1)
    return simde_mm_cmpestra_8_(a, la, b, lb, imm8);
  else
    return simde_mm_cmpestra_16_(a, la, b, lb, imm8);
#endif
}
#if defined(SIMDE_X86_SSE4_2_ENABLE_NATIVE_ALIASES)
#  define _mm_cmpestra(a, la, b, lb, imm8) simde_mm_cmpestra(a, la, b, lb, imm8)
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
