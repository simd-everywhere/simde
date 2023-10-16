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
*   2023      Chi-Wei Chu <wewe5215@gapp.nthu.edu.tw>
*/

#if !defined(SIMDE_ARM_NEON_CMLA_LANE_H)
#define SIMDE_ARM_NEON_CMLA_LANE_H

#include "types.h"
#include "dup_lane.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

SIMDE_FUNCTION_ATTRIBUTES
simde_float16x4_t
simde_vcmla_lane_f16(simde_float16x4_t r, simde_float16x4_t a, simde_float16x4_t b, const int lane) 
    SIMDE_REQUIRE_CONSTANT_RANGE(lane, 0, 1){
  simde_float16x4_t result;
  #if defined(SIMDE_ARM_NEON_A32V8_NATIVE) && SIMDE_ARCH_ARM_CHECK(8,3) && \
      (!defined(HEDLEY_GCC_VERSION) || HEDLEY_GCC_VERSION_CHECK(9,0,0)) && \
      (!defined(__clang__) || SIMDE_DETECT_CLANG_VERSION_CHECK(12,0,0))
    SIMDE_CONSTIFY_2_(vcmla_lane_f16, result, (HEDLEY_UNREACHABLE(), result), lane, r, a, b);
    
  #else
    simde_float16x4_private
      r_ = simde_float16x4_to_private(r),
      a_ = simde_float16x4_to_private(a),
      b_ = simde_float16x4_to_private(simde_vdup_n_f16(simde_float16x4_to_private(b).values[lane]));

      #if defined(SIMDE_SHUFFLE_VECTOR_)
        a_.values = SIMDE_SHUFFLE_VECTOR_(16, 4, a_.values, a_.values, 0, 0, 2, 2);
        r_.values += b_.values * a_.values;
      #else
        SIMDE_VECTORIZE
        for (size_t i = 0 ; i < (sizeof(r_.values) / (2 * sizeof(r_.values[0]))) ; i++) {
          r_.values[2 * i] += b_.values[lane] * a_.values[2 * i];
          r_.values[2 * i + 1] += b_.values[lane] * a_.values[2 * i];
        }
      #endif
    result = simde_float16x4_from_private(r_);
    return result;
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V8_ENABLE_NATIVE_ALIASES)
  #undef vcmla_lane_f16
  #define vcmla_lane_f16(r, a, b, lane) simde_vcmla_lane_f16(r, a, b, lane)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_float32x2_t
simde_vcmla_lane_f32(simde_float32x2_t r, simde_float32x2_t a, simde_float32x2_t b, const int lane) 
    SIMDE_REQUIRE_CONSTANT_RANGE(lane, 0, 0) {
  #if defined(SIMDE_ARM_NEON_A32V8_NATIVE) && SIMDE_ARCH_ARM_CHECK(8,3) && \
      (!defined(HEDLEY_GCC_VERSION) || HEDLEY_GCC_VERSION_CHECK(9,0,0)) && \
      (!defined(__clang__) || SIMDE_DETECT_CLANG_VERSION_CHECK(12,0,0))
    return vcmla_lane_f32(r, a, b, 0);
  #else
    simde_float32x2_private
      r_ = simde_float32x2_to_private(r),
      a_ = simde_float32x2_to_private(a),
      b_ = simde_float32x2_to_private(simde_vdup_n_f32(simde_float32x2_to_private(b).values[lane]));

      #if defined(SIMDE_SHUFFLE_VECTOR_)
        a_.values = SIMDE_SHUFFLE_VECTOR_(32, 8, a_.values, a_.values, 0, 0);
        r_.values += b_.values * a_.values;
      #else
        SIMDE_VECTORIZE
        for (size_t i = 0 ; i < (sizeof(r_.values) / (2 * sizeof(r_.values[0]))) ; i++) {
          r_.values[2 * i] += b_.values[lane] * a_.values[2 * i];
          r_.values[2 * i + 1] += b_.values[lane] * a_.values[2 * i];
        }
      #endif

    return simde_float32x2_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V8_ENABLE_NATIVE_ALIASES)
  #undef vcmla_lane_f32
  #define vcmla_lane_f32(r, a, b, lane) simde_vcmla_lane_f32(r, a, b, lane)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_float16x4_t
simde_vcmla_laneq_f16(simde_float16x4_t r, simde_float16x4_t a, simde_float16x8_t b, const int lane)
    SIMDE_REQUIRE_CONSTANT_RANGE(lane, 0, 1) {
  simde_float16x4_t result;
  #if defined(SIMDE_ARM_NEON_A32V8_NATIVE) && SIMDE_ARCH_ARM_CHECK(8,3) && \
      (!defined(HEDLEY_GCC_VERSION) || HEDLEY_GCC_VERSION_CHECK(9,0,0)) && \
      (!defined(__clang__) || SIMDE_DETECT_CLANG_VERSION_CHECK(12,0,0))
    SIMDE_CONSTIFY_2_(vcmla_laneq_f16, result, (HEDLEY_UNREACHABLE(), result), lane, r, a, b);
  #else
    simde_float16x4_private
      r_ = simde_float16x4_to_private(r),
      a_ = simde_float16x4_to_private(a),
      b_ = simde_float16x4_to_private(simde_vdup_n_f16(simde_float16x8_to_private(b).values[lane]));
    
      #if defined(SIMDE_SHUFFLE_VECTOR_)
        a_.values = SIMDE_SHUFFLE_VECTOR_(16, 4, a_.values, a_.values, 0, 0, 2, 2);
        r_.values += b_.values * a_.values;
      #else
        SIMDE_VECTORIZE
        for (size_t i = 0 ; i < (sizeof(r_.values) / (2 * sizeof(r_.values[0]))) ; i++) {
          r_.values[2 * i] += b_.values[lane] * a_.values[2 * i];
          r_.values[2 * i + 1] += b_.values[lane] * a_.values[2 * i];
        }
      #endif
    result = simde_float16x4_from_private(r_);
    return result;
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V8_ENABLE_NATIVE_ALIASES)
  #undef vcmla_laneq_f16
  #define vcmla_laneq_f16(r, a, b, lane) simde_vcmla_laneq_f16(r, a, b, lane)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_float32x2_t
simde_vcmla_laneq_f32(simde_float32x2_t r, simde_float32x2_t a, simde_float32x4_t b, const int lane) 
    SIMDE_REQUIRE_CONSTANT_RANGE(lane, 0, 1) {
  simde_float32x2_t result;
  #if defined(SIMDE_ARM_NEON_A32V8_NATIVE) && SIMDE_ARCH_ARM_CHECK(8,3) && \
      (!defined(HEDLEY_GCC_VERSION) || HEDLEY_GCC_VERSION_CHECK(9,0,0)) && \
      (!defined(__clang__) || SIMDE_DETECT_CLANG_VERSION_CHECK(12,0,0))
    SIMDE_CONSTIFY_2_(vcmla_laneq_f32, result, (HEDLEY_UNREACHABLE(), result), lane, r, a, b);
  #else
    simde_float32x2_private
      r_ = simde_float32x2_to_private(r),
      a_ = simde_float32x2_to_private(a),
      b_ = simde_float32x2_to_private(simde_vdup_n_f32(simde_float32x4_to_private(b).values[lane]));
    

      #if defined(SIMDE_SHUFFLE_VECTOR_)
        a_.values = SIMDE_SHUFFLE_VECTOR_(32, 8, a_.values, a_.values, 0, 0);
        r_.values += b_.values * a_.values;
      #else
        SIMDE_VECTORIZE
        for (size_t i = 0 ; i < (sizeof(r_.values) / (2 * sizeof(r_.values[0]))) ; i++) {
          r_.values[2 * i] += b_.values[lane] * a_.values[2 * i];
          r_.values[2 * i + 1] += b_.values[lane] * a_.values[2 * i];
        }
      #endif
    result = simde_float32x2_from_private(r_);
    return result;
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V8_ENABLE_NATIVE_ALIASES)
  #undef vcmla_laneq_f32
  #define vcmla_laneq_f32(r, a, b, lane) simde_vcmla_laneq_f32(r, a, b, lane)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_float16x8_t
simde_vcmlaq_lane_f16(simde_float16x8_t r, simde_float16x8_t a, simde_float16x4_t b, const int lane)
    SIMDE_REQUIRE_CONSTANT_RANGE(lane, 0, 1) {
  simde_float16x8_t result;
  #if defined(SIMDE_ARM_NEON_A32V8_NATIVE) && SIMDE_ARCH_ARM_CHECK(8,3) && \
      (!defined(HEDLEY_GCC_VERSION) || HEDLEY_GCC_VERSION_CHECK(9,0,0)) && \
      (!defined(__clang__) || SIMDE_DETECT_CLANG_VERSION_CHECK(12,0,0))
    SIMDE_CONSTIFY_2_(vcmlaq_lane_f16, result, (HEDLEY_UNREACHABLE(), result), lane, r, a, b);
  #else
    simde_float16x8_private
      r_ = simde_float16x8_to_private(r),
      a_ = simde_float16x8_to_private(a),
      b_ = simde_float16x8_to_private(simde_vdupq_n_f16(simde_float16x4_to_private(b).values[lane]));


    #if defined(SIMDE_SHUFFLE_VECTOR_)
      a_.values = SIMDE_SHUFFLE_VECTOR_(16, 8, a_.values, a_.values, 0, 0, 2, 2, 4, 4, 6, 6);
      r_.values += b_.values * a_.values;
    #else
      SIMDE_VECTORIZE
        for (size_t i = 0 ; i < (sizeof(r_.values) / (2 * sizeof(r_.values[0]))) ; i++) {
          r_.values[2 * i] += b_.values[lane] * a_.values[2 * i];
          r_.values[2 * i + 1] += b_.values[lane] * a_.values[2 * i];
        }
      #endif
    result = simde_float16x8_from_private(r_);
    return result;
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V8_ENABLE_NATIVE_ALIASES)
  #undef vcmlaq_lane_f16
  #define vcmlaq_lane_f16(r, a, b, lane) simde_vcmlaq_lane_f16(r, a, b, lane)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_float32x4_t
simde_vcmlaq_lane_f32(simde_float32x4_t r, simde_float32x4_t a, simde_float32x2_t b, const int lane) 
    SIMDE_REQUIRE_CONSTANT_RANGE(lane, 0, 0) {
  #if defined(SIMDE_ARM_NEON_A32V8_NATIVE) && SIMDE_ARCH_ARM_CHECK(8,3) && \
      (!defined(HEDLEY_GCC_VERSION) || HEDLEY_GCC_VERSION_CHECK(9,0,0)) && \
      (!defined(__clang__) || SIMDE_DETECT_CLANG_VERSION_CHECK(12,0,0))
    return vcmlaq_lane_f32(r, a, b, 0);
  #else
    simde_float32x4_private
      r_ = simde_float32x4_to_private(r),
      a_ = simde_float32x4_to_private(a),
      b_ = simde_float32x4_to_private(simde_vdupq_n_f32(simde_float32x2_to_private(b).values[lane]));
    

    #if defined(SIMDE_SHUFFLE_VECTOR_)
      a_.values = SIMDE_SHUFFLE_VECTOR_(32, 16, a_.values, a_.values, 0, 0, 2, 2);
      r_.values += b_.values * a_.values;
    #else
      SIMDE_VECTORIZE
        for (size_t i = 0 ; i < (sizeof(r_.values) / (2 * sizeof(r_.values[0]))) ; i++) {
          r_.values[2 * i] += b_.values[lane] * a_.values[2 * i];
          r_.values[2 * i + 1] += b_.values[lane] * a_.values[2 * i];
        }
      #endif

    return simde_float32x4_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V8_ENABLE_NATIVE_ALIASES)
  #undef vcmlaq_lane_f32
  #define vcmlaq_lane_f32(r, a, b, lane) simde_vcmlaq_lane_f32(r, a, b, lane)
#endif


SIMDE_FUNCTION_ATTRIBUTES
simde_float16x8_t
simde_vcmlaq_laneq_f16(simde_float16x8_t r, simde_float16x8_t a, simde_float16x8_t b, const int lane)
    SIMDE_REQUIRE_CONSTANT_RANGE(lane, 0, 3) {
  simde_float16x8_t result;
  #if defined(SIMDE_ARM_NEON_A32V8_NATIVE) && SIMDE_ARCH_ARM_CHECK(8,3) && \
      (!defined(HEDLEY_GCC_VERSION) || HEDLEY_GCC_VERSION_CHECK(9,0,0)) && \
      (!defined(__clang__) || SIMDE_DETECT_CLANG_VERSION_CHECK(12,0,0))
    SIMDE_CONSTIFY_4_(vcmlaq_laneq_f16, result, (HEDLEY_UNREACHABLE(), result), lane, r, a, b);
  #else
    simde_float16x8_private
      r_ = simde_float16x8_to_private(r),
      a_ = simde_float16x8_to_private(a),
      b_ = simde_float16x8_to_private(simde_vdupq_n_f16(simde_float16x8_to_private(b).values[lane]));

    #if defined(SIMDE_SHUFFLE_VECTOR_)
      a_.values = SIMDE_SHUFFLE_VECTOR_(16, 8, a_.values, a_.values, 0, 0, 2, 2, 4, 4, 6, 6);
      r_.values += b_.values * a_.values;
    #else
      SIMDE_VECTORIZE
        for (size_t i = 0 ; i < (sizeof(r_.values) / (2 * sizeof(r_.values[0]))) ; i++) {
          r_.values[2 * i] += b_.values[lane] * a_.values[2 * i];
          r_.values[2 * i + 1] += b_.values[lane] * a_.values[2 * i];
        }
      #endif
    result = simde_float16x8_from_private(r_);
    return result;
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V8_ENABLE_NATIVE_ALIASES)
  #undef vcmlaq_laneq_f16
  #define vcmlaq_laneq_f16(r, a, b, lane) simde_vcmlaq_laneq_f16(r, a, b, lane)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_float32x4_t
simde_vcmlaq_laneq_f32(simde_float32x4_t r, simde_float32x4_t a, simde_float32x4_t b, const int lane)
    SIMDE_REQUIRE_CONSTANT_RANGE(lane, 0, 1) {
  simde_float32x4_t result;
  #if defined(SIMDE_ARM_NEON_A32V8_NATIVE) && SIMDE_ARCH_ARM_CHECK(8,3) && \
      (!defined(HEDLEY_GCC_VERSION) || HEDLEY_GCC_VERSION_CHECK(9,0,0)) && \
      (!defined(__clang__) || SIMDE_DETECT_CLANG_VERSION_CHECK(12,0,0))
    SIMDE_CONSTIFY_2_(vcmlaq_laneq_f32, result, (HEDLEY_UNREACHABLE(), result), lane, r, a, b);
  #else
    simde_float32x4_private
      r_ = simde_float32x4_to_private(r),
      a_ = simde_float32x4_to_private(a),
      b_ = simde_float32x4_to_private(simde_vdupq_n_f32(simde_float32x4_to_private(b).values[lane]));

    #if defined(SIMDE_SHUFFLE_VECTOR_)
      a_.values = SIMDE_SHUFFLE_VECTOR_(32, 16, a_.values, a_.values, 0, 0, 2, 2);
      r_.values += b_.values * a_.values;
    #else
      SIMDE_VECTORIZE
        for (size_t i = 0 ; i < (sizeof(r_.values) / (2 * sizeof(r_.values[0]))) ; i++) {
          r_.values[2 * i] += b_.values[lane] * a_.values[2 * i];
          r_.values[2 * i + 1] += b_.values[lane] * a_.values[2 * i];
        }
      #endif
      result = simde_float32x4_from_private(r_);
    return result;
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V8_ENABLE_NATIVE_ALIASES)
  #undef vcmlaq_laneq_f32
  #define vcmlaq_laneq_f32(r, a, b, lane) simde_vcmlaq_laneq_f32(r, a, b, lane)
#endif


SIMDE_END_DECLS_
HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_ARM_NEON_CMLA_LANE_H) */