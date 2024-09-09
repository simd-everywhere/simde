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
 *   2023      Chi-Wei Chu <wewe5215@gapp.nthu.edu.tw> (Copyright owned by NTHU pllab)
 */

#if !defined(SIMDE_ARM_NEON_CMLA_LANE_H)
#define SIMDE_ARM_NEON_CMLA_LANE_H

#include "add.h"
#include "combine.h"
#include "cvt.h"
#include "dup_lane.h"
#include "get_high.h"
#include "get_low.h"
#include "mul.h"
#include "types.h"
HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

SIMDE_FUNCTION_ATTRIBUTES
simde_float16x4_t simde_vcmla_lane_f16(simde_float16x4_t r, simde_float16x4_t a, simde_float16x4_t b, const int lane)
    SIMDE_REQUIRE_CONSTANT_RANGE(lane, 0, 1)
{
  #if defined(SIMDE_RISCV_V_NATIVE) && SIMDE_ARCH_RISCV_ZVFH
      simde_float16x4_private r_ = simde_float16x4_to_private(r),
                              a_ = simde_float16x4_to_private(a),
                              b_ = simde_float16x4_to_private(b);
      uint16_t idx1[4] = {0, 0, 2, 2};
      vfloat16m1_t op1 = __riscv_vrgather_vv_f16m1(__riscv_vslideup_vx_f16m1( \
        a_.sv64, a_.sv64, 4, 8), __riscv_vle16_v_u16m1(idx1, 4), 4);
      r_.sv64 = __riscv_vfmacc_vf_f16m1(r_.sv64, b_.values[lane], op1, 4);
      return simde_float16x4_from_private(r_);
  #else
    simde_float32x4_private r_ = simde_float32x4_to_private(simde_vcvt_f32_f16(r)),
                          a_ = simde_float32x4_to_private(simde_vcvt_f32_f16(a)),
                          b_ = simde_float32x4_to_private(
                              simde_vcvt_f32_f16(simde_vdup_n_f16(simde_float16x4_to_private(b).values[lane])));
    #if defined(SIMDE_SHUFFLE_VECTOR_) &&                                                                                       \
        ((SIMDE_FLOAT16_API == SIMDE_FLOAT16_API_FP16) || (SIMDE_FLOAT16_API == SIMDE_FLOAT16_API_FLOAT16))
      a_.values = SIMDE_SHUFFLE_VECTOR_(32, 16, a_.values, a_.values, 0, 0, 2, 2);
      r_.values += b_.values * a_.values;
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0; i < (sizeof(r_.values) / (2 * sizeof(r_.values[0]))); i++)
      {
        r_.values[2 * i] += b_.values[lane] * a_.values[2 * i];
        r_.values[2 * i + 1] += b_.values[lane] * a_.values[2 * i];
      }
    #endif
    return simde_vcvt_f16_f32(simde_float32x4_from_private(r_));
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V8_ENABLE_NATIVE_ALIASES)
  #undef vcmla_lane_f16
  #define vcmla_lane_f16(r, a, b, lane) simde_vcmla_lane_f16(r, a, b, lane)
#endif
#if defined(SIMDE_ARM_NEON_A32V8_NATIVE) && SIMDE_ARCH_ARM_CHECK(8, 3) &&                                                   \
    (!defined(HEDLEY_GCC_VERSION) || HEDLEY_GCC_VERSION_CHECK(9, 0, 0)) &&                                                  \
    (!defined(__clang__) || SIMDE_DETECT_CLANG_VERSION_CHECK(12, 0, 0))
  #define simde_vcmla_lane_f16(r, a, b, lane) vcmla_lane_f16(r, a, b, lane)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_float32x2_t simde_vcmla_lane_f32(simde_float32x2_t r, simde_float32x2_t a, simde_float32x2_t b, const int lane)
    SIMDE_REQUIRE_CONSTANT_RANGE(lane, 0, 0)
{
  #if defined(SIMDE_RISCV_V_NATIVE)
      simde_float32x2_private r_ = simde_float32x2_to_private(r),
                              a_ = simde_float32x2_to_private(a),
                              b_ = simde_float32x2_to_private(b);
      uint32_t idx1[2] = {0, 0};
      vfloat32m1_t op1 = __riscv_vrgather_vv_f32m1(__riscv_vslideup_vx_f32m1( \
        a_.sv64, a_.sv64, 2, 4), __riscv_vle32_v_u32m1(idx1, 2), 2);
      r_.sv64 = __riscv_vfmacc_vf_f32m1(r_.sv64, b_.values[lane], op1, 2);
      return simde_float32x2_from_private(r_);
  #else
    simde_float32x2_private r_ = simde_float32x2_to_private(r), a_ = simde_float32x2_to_private(a),
                            b_ = simde_float32x2_to_private(simde_vdup_n_f32(simde_float32x2_to_private(b).values[lane]));
    #if defined(SIMDE_SHUFFLE_VECTOR_)
      a_.values = SIMDE_SHUFFLE_VECTOR_(32, 8, a_.values, a_.values, 0, 0);
      r_.values += b_.values * a_.values;
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0; i < (sizeof(r_.values) / (2 * sizeof(r_.values[0]))); i++)
      {
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
#if defined(SIMDE_ARM_NEON_A32V8_NATIVE) && SIMDE_ARCH_ARM_CHECK(8, 3) &&                                                   \
    (!defined(HEDLEY_GCC_VERSION) || HEDLEY_GCC_VERSION_CHECK(9, 0, 0)) &&                                                  \
    (!defined(__clang__) || SIMDE_DETECT_CLANG_VERSION_CHECK(12, 0, 0))
  #define simde_vcmla_lane_f32(r, a, b, lane) vcmla_lane_f32(r, a, b, lane)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_float16x4_t simde_vcmla_laneq_f16(simde_float16x4_t r, simde_float16x4_t a, simde_float16x8_t b, const int lane)
    SIMDE_REQUIRE_CONSTANT_RANGE(lane, 0, 1)
{
  #if defined(SIMDE_RISCV_V_NATIVE) && SIMDE_ARCH_RISCV_ZVFH
      simde_float16x4_private r_ = simde_float16x4_to_private(r),
                              a_ = simde_float16x4_to_private(a);
      simde_float16x8_private b_ = simde_float16x8_to_private(b);
      uint16_t idx1[4] = {0, 0, 2, 2};
      vfloat16m1_t op1 = __riscv_vrgather_vv_f16m1(__riscv_vslideup_vx_f16m1( \
        a_.sv64, a_.sv64, 4, 8), __riscv_vle16_v_u16m1(idx1, 4), 4);
      r_.sv64 = __riscv_vfmacc_vf_f16m1(r_.sv64, b_.values[lane], op1, 4);
      return simde_float16x4_from_private(r_);
  #else
    simde_float32x4_private r_ = simde_float32x4_to_private(simde_vcvt_f32_f16(r)),
                          a_ = simde_float32x4_to_private(simde_vcvt_f32_f16(a)),
                          b_ = simde_float32x4_to_private(
                              simde_vcvt_f32_f16(simde_vdup_n_f16(simde_float16x8_to_private(b).values[lane])));
    #if defined(SIMDE_SHUFFLE_VECTOR_) &&                                                                                       \
        ((SIMDE_FLOAT16_API == SIMDE_FLOAT16_API_FP16) || (SIMDE_FLOAT16_API == SIMDE_FLOAT16_API_FLOAT16))
      a_.values = SIMDE_SHUFFLE_VECTOR_(32, 16, a_.values, a_.values, 0, 0, 2, 2);
      r_.values += b_.values * a_.values;
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0; i < (sizeof(r_.values) / (2 * sizeof(r_.values[0]))); i++)
      {
        r_.values[2 * i] += b_.values[lane] * a_.values[2 * i];
        r_.values[2 * i + 1] += b_.values[lane] * a_.values[2 * i];
      }
    #endif
    return simde_vcvt_f16_f32(simde_float32x4_from_private(r_));
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V8_ENABLE_NATIVE_ALIASES)
  #undef vcmla_laneq_f16
  #define vcmla_laneq_f16(r, a, b, lane) simde_vcmla_laneq_f16(r, a, b, lane)
#endif
#if defined(SIMDE_ARM_NEON_A32V8_NATIVE) && SIMDE_ARCH_ARM_CHECK(8, 3) &&                                                   \
    (!defined(HEDLEY_GCC_VERSION) || HEDLEY_GCC_VERSION_CHECK(9, 0, 0)) &&                                                  \
    (!defined(__clang__) || SIMDE_DETECT_CLANG_VERSION_CHECK(12, 0, 0))
  #define simde_vcmla_laneq_f16(r, a, b, lane) vcmla_laneq_f16(r, a, b, lane)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_float32x2_t simde_vcmla_laneq_f32(simde_float32x2_t r, simde_float32x2_t a, simde_float32x4_t b, const int lane)
    SIMDE_REQUIRE_CONSTANT_RANGE(lane, 0, 1)
{
  #if defined(SIMDE_RISCV_V_NATIVE)
      simde_float32x2_private r_ = simde_float32x2_to_private(r),
                              a_ = simde_float32x2_to_private(a);
      simde_float32x4_private b_ = simde_float32x4_to_private(b);
      uint32_t idx1[2] = {0, 0};
      vfloat32m1_t op1 = __riscv_vrgather_vv_f32m1(__riscv_vslideup_vx_f32m1( \
        a_.sv64, a_.sv64, 2, 4), __riscv_vle32_v_u32m1(idx1, 2), 2);
      r_.sv64 = __riscv_vfmacc_vf_f32m1(r_.sv64, b_.values[lane], op1, 2);
      return simde_float32x2_from_private(r_);
  #else
    simde_float32x2_private r_ = simde_float32x2_to_private(r), a_ = simde_float32x2_to_private(a),
                            b_ = simde_float32x2_to_private(simde_vdup_n_f32(simde_float32x4_to_private(b).values[lane]));
    #if defined(SIMDE_SHUFFLE_VECTOR_)
      a_.values = SIMDE_SHUFFLE_VECTOR_(32, 8, a_.values, a_.values, 0, 0);
      r_.values += b_.values * a_.values;
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0; i < (sizeof(r_.values) / (2 * sizeof(r_.values[0]))); i++)
      {
        r_.values[2 * i] += b_.values[lane] * a_.values[2 * i];
        r_.values[2 * i + 1] += b_.values[lane] * a_.values[2 * i];
      }
    #endif
    return simde_float32x2_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V8_ENABLE_NATIVE_ALIASES)
  #undef vcmla_laneq_f32
  #define vcmla_laneq_f32(r, a, b, lane) simde_vcmla_laneq_f32(r, a, b, lane)
#endif
#if defined(SIMDE_ARM_NEON_A32V8_NATIVE) && SIMDE_ARCH_ARM_CHECK(8, 3) &&                                                   \
    (!defined(HEDLEY_GCC_VERSION) || HEDLEY_GCC_VERSION_CHECK(9, 0, 0)) &&                                                  \
    (!defined(__clang__) || SIMDE_DETECT_CLANG_VERSION_CHECK(12, 0, 0))
  #define simde_vcmla_laneq_f32(r, a, b, lane) vcmla_laneq_f32(r, a, b, lane)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_float16x8_t simde_vcmlaq_lane_f16(simde_float16x8_t r, simde_float16x8_t a, simde_float16x4_t b, const int lane)
    SIMDE_REQUIRE_CONSTANT_RANGE(lane, 0, 1)
{
  #if defined(SIMDE_RISCV_V_NATIVE) && SIMDE_ARCH_RISCV_ZVFH
      simde_float16x8_private r_ = simde_float16x8_to_private(r),
                              a_ = simde_float16x8_to_private(a);
      simde_float16x4_private b_ = simde_float16x4_to_private(b);
      uint16_t idx1[8] = {0, 0, 2, 2, 4, 4, 6, 6};
      vfloat16m2_t a_tmp = __riscv_vlmul_ext_v_f16m1_f16m2 (a_.sv128);
      vfloat16m1_t op1 = __riscv_vlmul_trunc_v_f16m2_f16m1(__riscv_vrgather_vv_f16m2( \
        __riscv_vslideup_vx_f16m2(a_tmp, a_tmp, 8, 16), __riscv_vle16_v_u16m2(idx1, 8), 8));
      r_.sv128 = __riscv_vfmacc_vf_f16m1(r_.sv128, b_.values[lane], op1, 8);
      return simde_float16x8_from_private(r_);
  #else
    simde_float32x4_private r_low = simde_float32x4_to_private(simde_vcvt_f32_f16(simde_vget_low_f16(r))),
                            a_low = simde_float32x4_to_private(simde_vcvt_f32_f16(simde_vget_low_f16(a))),
                            r_high = simde_float32x4_to_private(simde_vcvt_f32_f16(simde_vget_high_f16(r))),
                            a_high = simde_float32x4_to_private(simde_vcvt_f32_f16(simde_vget_high_f16(a))),
                            b_ = simde_float32x4_to_private(
                                simde_vcvt_f32_f16(simde_vdup_n_f16(simde_float16x4_to_private(b).values[lane])));
    #if defined(SIMDE_SHUFFLE_VECTOR_) &&                                                                                       \
        ((SIMDE_FLOAT16_API == SIMDE_FLOAT16_API_FP16) || (SIMDE_FLOAT16_API == SIMDE_FLOAT16_API_FLOAT16))
      a_low.values = SIMDE_SHUFFLE_VECTOR_(32, 16, a_low.values, a_low.values, 0, 0, 2, 2);
      a_high.values = SIMDE_SHUFFLE_VECTOR_(32, 16, a_high.values, a_high.values, 0, 0, 2, 2);
      r_low.values += b_.values * a_low.values;
      r_high.values += b_.values * a_high.values;
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0; i < (sizeof(r_low.values) / (2 * sizeof(r_low.values[0]))); i++)
      {
        r_low.values[2 * i] += b_.values[lane] * a_low.values[2 * i];
        r_low.values[2 * i + 1] += b_.values[lane] * a_low.values[2 * i];
        r_high.values[2 * i] += b_.values[lane] * a_high.values[2 * i];
        r_high.values[2 * i + 1] += b_.values[lane] * a_high.values[2 * i];
      }
    #endif
    return simde_vcombine_f16(simde_vcvt_f16_f32(simde_float32x4_from_private(r_low)),
                              simde_vcvt_f16_f32(simde_float32x4_from_private(r_high)));
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V8_ENABLE_NATIVE_ALIASES)
  #undef vcmlaq_lane_f16
  #define vcmlaq_lane_f16(r, a, b, lane) simde_vcmlaq_lane_f16(r, a, b, lane)
#endif
#if defined(SIMDE_ARM_NEON_A32V8_NATIVE) && SIMDE_ARCH_ARM_CHECK(8, 3) &&                                                   \
    (!defined(HEDLEY_GCC_VERSION) || HEDLEY_GCC_VERSION_CHECK(9, 0, 0)) &&                                                  \
    (!defined(__clang__) || SIMDE_DETECT_CLANG_VERSION_CHECK(12, 0, 0))
  #define simde_vcmlaq_lane_f16(r, a, b, lane) vcmlaq_lane_f16(r, a, b, lane)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_float32x4_t simde_vcmlaq_lane_f32(simde_float32x4_t r, simde_float32x4_t a, simde_float32x2_t b, const int lane)
    SIMDE_REQUIRE_CONSTANT_RANGE(lane, 0, 0)
{
  #if defined(SIMDE_RISCV_V_NATIVE)
      simde_float32x4_private r_ = simde_float32x4_to_private(r),
                              a_ = simde_float32x4_to_private(a);
      simde_float32x2_private b_ = simde_float32x2_to_private(b);
      uint32_t idx1[4] = {0, 0, 2, 2};
      vfloat32m2_t a_tmp = __riscv_vlmul_ext_v_f32m1_f32m2 (a_.sv128);
      vfloat32m1_t op1 = __riscv_vlmul_trunc_v_f32m2_f32m1(__riscv_vrgather_vv_f32m2( \
        __riscv_vslideup_vx_f32m2(a_tmp, a_tmp, 4, 8), __riscv_vle32_v_u32m2(idx1, 4), 4));
      r_.sv128 = __riscv_vfmacc_vf_f32m1(r_.sv128, b_.values[lane], op1, 4);
      return simde_float32x4_from_private(r_);
  #else
    simde_float32x4_private r_ = simde_float32x4_to_private(r), a_ = simde_float32x4_to_private(a),
                            b_ = simde_float32x4_to_private(simde_vdupq_n_f32(simde_float32x2_to_private(b).values[lane]));
    #if defined(SIMDE_SHUFFLE_VECTOR_)
      a_.values = SIMDE_SHUFFLE_VECTOR_(32, 16, a_.values, a_.values, 0, 0, 2, 2);
      r_.values += b_.values * a_.values;
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0; i < (sizeof(r_.values) / (2 * sizeof(r_.values[0]))); i++)
      {
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
#if defined(SIMDE_ARM_NEON_A32V8_NATIVE) && SIMDE_ARCH_ARM_CHECK(8, 3) &&                                                   \
    (!defined(HEDLEY_GCC_VERSION) || HEDLEY_GCC_VERSION_CHECK(9, 0, 0)) &&                                                  \
    (!defined(__clang__) || SIMDE_DETECT_CLANG_VERSION_CHECK(12, 0, 0))
  #define simde_vcmlaq_lane_f32(r, a, b, lane) vcmlaq_lane_f32(r, a, b, 0);
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_float16x8_t simde_vcmlaq_laneq_f16(simde_float16x8_t r, simde_float16x8_t a, simde_float16x8_t b, const int lane)
    SIMDE_REQUIRE_CONSTANT_RANGE(lane, 0, 3)
{
  #if defined(SIMDE_RISCV_V_NATIVE) && SIMDE_ARCH_RISCV_ZVFH
      simde_float16x8_private r_ = simde_float16x8_to_private(r),
                              a_ = simde_float16x8_to_private(a);
      simde_float16x8_private b_ = simde_float16x8_to_private(b);
      uint16_t idx1[8] = {0, 0, 2, 2, 4, 4, 6, 6};
      vfloat16m2_t a_tmp = __riscv_vlmul_ext_v_f16m1_f16m2 (a_.sv128);
      vfloat16m1_t op1 = __riscv_vlmul_trunc_v_f16m2_f16m1(__riscv_vrgather_vv_f16m2( \
        __riscv_vslideup_vx_f16m2(a_tmp, a_tmp, 8, 16), __riscv_vle16_v_u16m2(idx1, 8), 8));
      r_.sv128 = __riscv_vfmacc_vf_f16m1(r_.sv128, b_.values[lane], op1, 8);
      return simde_float16x8_from_private(r_);
  #else
    simde_float32x4_private r_low = simde_float32x4_to_private(simde_vcvt_f32_f16(simde_vget_low_f16(r))),
                            a_low = simde_float32x4_to_private(simde_vcvt_f32_f16(simde_vget_low_f16(a))),
                            r_high = simde_float32x4_to_private(simde_vcvt_f32_f16(simde_vget_high_f16(r))),
                            a_high = simde_float32x4_to_private(simde_vcvt_f32_f16(simde_vget_high_f16(a))),
                            b_ = simde_float32x4_to_private(
                                simde_vcvt_f32_f16(simde_vdup_n_f16(simde_float16x8_to_private(b).values[lane])));
    #if defined(SIMDE_SHUFFLE_VECTOR_) &&                                                                                       \
        ((SIMDE_FLOAT16_API == SIMDE_FLOAT16_API_FP16) || (SIMDE_FLOAT16_API == SIMDE_FLOAT16_API_FLOAT16))
      a_low.values = SIMDE_SHUFFLE_VECTOR_(32, 16, a_low.values, a_low.values, 0, 0, 2, 2);
      r_low.values += b_.values * a_low.values;
      a_high.values = SIMDE_SHUFFLE_VECTOR_(32, 16, a_high.values, a_high.values, 0, 0, 2, 2);
      r_high.values += b_.values * a_high.values;
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0; i < (sizeof(r_low.values) / (2 * sizeof(r_low.values[0]))); i++)
      {
        r_low.values[2 * i] += b_.values[lane] * a_low.values[2 * i];
        r_low.values[2 * i + 1] += b_.values[lane] * a_low.values[2 * i];
        r_high.values[2 * i] += b_.values[lane] * a_high.values[2 * i];
        r_high.values[2 * i + 1] += b_.values[lane] * a_high.values[2 * i];
      }
    #endif
    return simde_vcombine_f16(simde_vcvt_f16_f32(simde_float32x4_from_private(r_low)),
                              simde_vcvt_f16_f32(simde_float32x4_from_private(r_high)));
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V8_ENABLE_NATIVE_ALIASES)
  #undef vcmlaq_laneq_f16
  #define vcmlaq_laneq_f16(r, a, b, lane) simde_vcmlaq_laneq_f16(r, a, b, lane)
#endif
#if defined(SIMDE_ARM_NEON_A32V8_NATIVE) && SIMDE_ARCH_ARM_CHECK(8, 3) &&                                                   \
    (!defined(HEDLEY_GCC_VERSION) || HEDLEY_GCC_VERSION_CHECK(9, 0, 0)) &&                                                  \
    (!defined(__clang__) || SIMDE_DETECT_CLANG_VERSION_CHECK(12, 0, 0))
  #define simde_vcmlaq_laneq_f16(r, a, b, lane) vcmlaq_laneq_f16(r, a, b, lane)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_float32x4_t simde_vcmlaq_laneq_f32(simde_float32x4_t r, simde_float32x4_t a, simde_float32x4_t b, const int lane)
    SIMDE_REQUIRE_CONSTANT_RANGE(lane, 0, 1)
{
  #if defined(SIMDE_RISCV_V_NATIVE)
      simde_float32x4_private r_ = simde_float32x4_to_private(r),
                              a_ = simde_float32x4_to_private(a);
      simde_float32x4_private b_ = simde_float32x4_to_private(b);
      uint32_t idx1[4] = {0, 0, 2, 2};
      vfloat32m2_t a_tmp = __riscv_vlmul_ext_v_f32m1_f32m2 (a_.sv128);
      vfloat32m1_t op1 = __riscv_vlmul_trunc_v_f32m2_f32m1(__riscv_vrgather_vv_f32m2( \
        __riscv_vslideup_vx_f32m2(a_tmp, a_tmp, 4, 8), __riscv_vle32_v_u32m2(idx1, 4), 4));
      r_.sv128 = __riscv_vfmacc_vf_f32m1(r_.sv128, b_.values[lane], op1, 4);
      return simde_float32x4_from_private(r_);
  #else
    simde_float32x4_private r_ = simde_float32x4_to_private(r), a_ = simde_float32x4_to_private(a),
                            b_ = simde_float32x4_to_private(simde_vdupq_n_f32(simde_float32x4_to_private(b).values[lane]));

    #if defined(SIMDE_SHUFFLE_VECTOR_)
      a_.values = SIMDE_SHUFFLE_VECTOR_(32, 16, a_.values, a_.values, 0, 0, 2, 2);
      r_.values += b_.values * a_.values;
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0; i < (sizeof(r_.values) / (2 * sizeof(r_.values[0]))); i++)
      {
        r_.values[2 * i] += b_.values[lane] * a_.values[2 * i];
        r_.values[2 * i + 1] += b_.values[lane] * a_.values[2 * i];
      }
    #endif
    return simde_float32x4_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V8_ENABLE_NATIVE_ALIASES)
  #undef vcmlaq_laneq_f32
  #define vcmlaq_laneq_f32(r, a, b, lane) simde_vcmlaq_laneq_f32(r, a, b, lane)
#endif
#if defined(SIMDE_ARM_NEON_A32V8_NATIVE) && SIMDE_ARCH_ARM_CHECK(8, 3) &&                                                   \
    (!defined(HEDLEY_GCC_VERSION) || HEDLEY_GCC_VERSION_CHECK(9, 0, 0)) &&                                                  \
    (!defined(__clang__) || SIMDE_DETECT_CLANG_VERSION_CHECK(12, 0, 0))
  #define simde_vcmlaq_laneq_f32(r, a, b, lane) vcmlaq_laneq_f32(r, a, b, lane)
#endif

SIMDE_END_DECLS_
HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_ARM_NEON_CMLA_LANE_H) */
