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
 *   2020      Sean Maher <seanptmaher@gmail.com> (Copyright owned by Google, LLC)
 */

#if !defined(SIMDE_ARM_NEON_SUDOT_LANE_H)
#define SIMDE_ARM_NEON_SUDOT_LANE_H

#include "types.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

SIMDE_FUNCTION_ATTRIBUTES
simde_int32x2_t
simde_vsudot_lane_s32(simde_int32x2_t r, simde_int8x8_t a, simde_uint8x8_t b, const int lane)
    SIMDE_REQUIRE_CONSTANT_RANGE(lane, 0, 1) {
  simde_int32x2_t result;
  simde_int32x2_private r_ = simde_int32x2_to_private(r);
  simde_int8x8_private a_ = simde_int8x8_to_private(a);
  simde_uint8x8_private b_ = simde_uint8x8_to_private(b);

  for (int i = 0 ; i < 2 ; i++) {
    int32_t acc = 0;
    SIMDE_VECTORIZE_REDUCTION(+:acc)
    for (int j = 0 ; j < 4 ; j++) {
      const int idx_b = j + (lane << 2);
      const int idx_a = j + (i << 2);
      acc += HEDLEY_STATIC_CAST(int32_t, a_.values[idx_a]) * HEDLEY_STATIC_CAST(uint32_t, b_.values[idx_b]);
    }
    r_.values[i] += acc;
  }

  result = simde_int32x2_from_private(r_);

  return result;
}
#if defined(SIMDE_ARM_NEON_A32V8_NATIVE)
  #define simde_vsudot_lane_s32(r, a, b, lane) vsudot_lane_s32((r), (a), (b), (lane))
#endif
#if defined(SIMDE_ARM_NEON_A32V8_ENABLE_NATIVE_ALIASES)
  #undef vsudot_lane_s32
  #define vsudot_lane_s32(r, a, b, lane) simde_vsudot_lane_s32((r), (a), (b), (lane))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_int32x2_t
simde_vsudot_laneq_s32(simde_int32x2_t r, simde_int8x8_t a, simde_uint8x16_t b, const int lane)
    SIMDE_REQUIRE_CONSTANT_RANGE(lane, 0, 3) {
  simde_int32x2_t result;
  simde_int32x2_private r_ = simde_int32x2_to_private(r);
  simde_int8x8_private a_ = simde_int8x8_to_private(a);
  simde_uint8x16_private b_ = simde_uint8x16_to_private(b);

  for (int i = 0 ; i < 2 ; i++) {
    int32_t acc = 0;
    SIMDE_VECTORIZE_REDUCTION(+:acc)
    for (int j = 0 ; j < 4 ; j++) {
      const int idx_b = j + (lane << 2);
      const int idx_a = j + (i << 2);
      acc += HEDLEY_STATIC_CAST(int32_t, a_.values[idx_a]) * HEDLEY_STATIC_CAST(uint32_t, b_.values[idx_b]);
    }
    r_.values[i] += acc;
  }

  result = simde_int32x2_from_private(r_);

  return result;
}
#if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
  #define simde_vsudot_laneq_s32(r, a, b, lane) vsudot_laneq_s32((r), (a), (b), (lane))
#endif
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES)
  #undef vsudot_laneq_s32
  #define vsudot_laneq_s32(r, a, b, lane) simde_vsudot_laneq_s32((r), (a), (b), (lane))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_int32x4_t
simde_vsudotq_laneq_s32(simde_int32x4_t r, simde_int8x16_t a, simde_uint8x16_t b, const int lane)
    SIMDE_REQUIRE_CONSTANT_RANGE(lane, 0, 3) {
  simde_int32x4_t result;
  simde_int32x4_private r_ = simde_int32x4_to_private(r);
  simde_int8x16_private a_ = simde_int8x16_to_private(a);
  simde_uint8x16_private b_ = simde_uint8x16_to_private(b);

  for(int i = 0 ; i < 4 ; i++) {
    int32_t acc = 0;
    SIMDE_VECTORIZE_REDUCTION(+:acc)
    for(int j = 0 ; j < 4 ; j++) {
      const int idx_b = j + (lane << 2);
      const int idx_a = j + (i << 2);
      acc += HEDLEY_STATIC_CAST(int32_t, a_.values[idx_a]) * HEDLEY_STATIC_CAST(uint32_t, b_.values[idx_b]);
    }
    r_.values[i] += acc;
  }

  result = simde_int32x4_from_private(r_);
  return result;
}
#if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
  #define simde_vsudotq_laneq_s32(r, a, b, lane) vsudotq_laneq_s32((r), (a), (b), (lane))
#endif
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES)
  #undef vsudotq_laneq_s32
  #define vsudotq_laneq_s32(r, a, b, lane) simde_vsudotq_laneq_s32((r), (a), (b), (lane))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_int32x4_t
simde_vsudotq_lane_s32(simde_int32x4_t r, simde_int8x16_t a, simde_uint8x8_t b, const int lane)
    SIMDE_REQUIRE_CONSTANT_RANGE(lane, 0, 1) {
  simde_int32x4_t result;
  simde_int32x4_private r_ = simde_int32x4_to_private(r);
  simde_int8x16_private a_ = simde_int8x16_to_private(a);
  simde_uint8x8_private b_ = simde_uint8x8_to_private(b);

  for(int i = 0 ; i < 4 ; i++) {
    int32_t acc = 0;
    SIMDE_VECTORIZE_REDUCTION(+:acc)
    for(int j = 0 ; j < 4 ; j++) {
      const int idx_b = j + (lane << 2);
      const int idx_a = j + (i << 2);
      acc += HEDLEY_STATIC_CAST(int32_t, a_.values[idx_a]) * HEDLEY_STATIC_CAST(uint32_t, b_.values[idx_b]);
    }
    r_.values[i] += acc;
  }

  result = simde_int32x4_from_private(r_);
  return result;
}
#if defined(SIMDE_ARM_NEON_A32V8_NATIVE)
  #define simde_vsudotq_lane_s32(r, a, b, lane) vsudotq_lane_s32((r), (a), (b), (lane))
#endif
#if defined(SIMDE_ARM_NEON_A32V8_ENABLE_NATIVE_ALIASES)
  #undef vsudotq_lane_s32
  #define vsudotq_lane_s32(r, a, b, lane) simde_vsudotq_lane_s32((r), (a), (b), (lane))
#endif

SIMDE_END_DECLS_
HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_ARM_NEON_SUDOT_LANE_H) */
