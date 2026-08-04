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
 *   2021      Evan Nemerson <evan@nemerson.com>
 */

#if !defined(SIMDE_ARM_NEON_MULL_LANE_H)
#define SIMDE_ARM_NEON_MULL_LANE_H

#include "mull.h"
#include "dup_lane.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

#if defined(SIMDE_LOONGARCH_LSX_NATIVE)
  SIMDE_FUNCTION_ATTRIBUTES
  simde_int32x4_t
  simde_x_lsx_vmull_lane_s16(simde_int16x4_t a, simde_int16x4_t v, const int lane) {
    simde_int32x4_private r_;
    simde_int16x4_private
      a_ = simde_int16x4_to_private(a),
      v_ = simde_int16x4_to_private(v);

    r_.m128i = __lsx_vmulwev_w_h(
      __lsx_vilvl_h(simde_x_lsx_load64(&a_.values), simde_x_lsx_load64(&a_.values)),
      __lsx_vreplve_h(simde_x_lsx_load64(&v_.values), lane));

    return simde_int32x4_from_private(r_);
  }

  SIMDE_FUNCTION_ATTRIBUTES
  simde_int64x2_t
  simde_x_lsx_vmull_lane_s32(simde_int32x2_t a, simde_int32x2_t v, const int lane) {
    simde_int64x2_private r_;
    simde_int32x2_private
      a_ = simde_int32x2_to_private(a),
      v_ = simde_int32x2_to_private(v);

    r_.m128i = __lsx_vmulwev_d_w(
      __lsx_vilvl_w(simde_x_lsx_load64(&a_.values), simde_x_lsx_load64(&a_.values)),
      __lsx_vreplve_w(simde_x_lsx_load64(&v_.values), lane));

    return simde_int64x2_from_private(r_);
  }

  SIMDE_FUNCTION_ATTRIBUTES
  simde_uint32x4_t
  simde_x_lsx_vmull_lane_u16(simde_uint16x4_t a, simde_uint16x4_t v, const int lane) {
    simde_uint32x4_private r_;
    simde_uint16x4_private
      a_ = simde_uint16x4_to_private(a),
      v_ = simde_uint16x4_to_private(v);

    r_.m128i = __lsx_vmulwev_w_hu(
      __lsx_vilvl_h(simde_x_lsx_load64(&a_.values), simde_x_lsx_load64(&a_.values)),
      __lsx_vreplve_h(simde_x_lsx_load64(&v_.values), lane));

    return simde_uint32x4_from_private(r_);
  }

  SIMDE_FUNCTION_ATTRIBUTES
  simde_uint64x2_t
  simde_x_lsx_vmull_lane_u32(simde_uint32x2_t a, simde_uint32x2_t v, const int lane) {
    simde_uint64x2_private r_;
    simde_uint32x2_private
      a_ = simde_uint32x2_to_private(a),
      v_ = simde_uint32x2_to_private(v);

    r_.m128i = __lsx_vmulwev_d_wu(
      __lsx_vilvl_w(simde_x_lsx_load64(&a_.values), simde_x_lsx_load64(&a_.values)),
      __lsx_vreplve_w(simde_x_lsx_load64(&v_.values), lane));

    return simde_uint64x2_from_private(r_);
  }

  SIMDE_FUNCTION_ATTRIBUTES
  simde_int32x4_t
  simde_x_lsx_vmull_laneq_s16(simde_int16x4_t a, simde_int16x8_t v, const int lane) {
    simde_int32x4_private r_;
    simde_int16x4_private a_ = simde_int16x4_to_private(a);
    simde_int16x8_private v_ = simde_int16x8_to_private(v);

    r_.m128i = __lsx_vmulwev_w_h(
      __lsx_vilvl_h(simde_x_lsx_load64(&a_.values), simde_x_lsx_load64(&a_.values)),
      __lsx_vreplve_h(v_.m128i, lane));

    return simde_int32x4_from_private(r_);
  }

  SIMDE_FUNCTION_ATTRIBUTES
  simde_int64x2_t
  simde_x_lsx_vmull_laneq_s32(simde_int32x2_t a, simde_int32x4_t v, const int lane) {
    simde_int64x2_private r_;
    simde_int32x2_private a_ = simde_int32x2_to_private(a);
    simde_int32x4_private v_ = simde_int32x4_to_private(v);

    r_.m128i = __lsx_vmulwev_d_w(
      __lsx_vilvl_w(simde_x_lsx_load64(&a_.values), simde_x_lsx_load64(&a_.values)),
      __lsx_vreplve_w(v_.m128i, lane));

    return simde_int64x2_from_private(r_);
  }

  SIMDE_FUNCTION_ATTRIBUTES
  simde_uint32x4_t
  simde_x_lsx_vmull_laneq_u16(simde_uint16x4_t a, simde_uint16x8_t v, const int lane) {
    simde_uint32x4_private r_;
    simde_uint16x4_private a_ = simde_uint16x4_to_private(a);
    simde_uint16x8_private v_ = simde_uint16x8_to_private(v);

    r_.m128i = __lsx_vmulwev_w_hu(
      __lsx_vilvl_h(simde_x_lsx_load64(&a_.values), simde_x_lsx_load64(&a_.values)),
      __lsx_vreplve_h(v_.m128i, lane));

    return simde_uint32x4_from_private(r_);
  }

  SIMDE_FUNCTION_ATTRIBUTES
  simde_uint64x2_t
  simde_x_lsx_vmull_laneq_u32(simde_uint32x2_t a, simde_uint32x4_t v, const int lane) {
    simde_uint64x2_private r_;
    simde_uint32x2_private a_ = simde_uint32x2_to_private(a);
    simde_uint32x4_private v_ = simde_uint32x4_to_private(v);

    r_.m128i = __lsx_vmulwev_d_wu(
      __lsx_vilvl_w(simde_x_lsx_load64(&a_.values), simde_x_lsx_load64(&a_.values)),
      __lsx_vreplve_w(v_.m128i, lane));

    return simde_uint64x2_from_private(r_);
  }
#endif /* defined(SIMDE_LOONGARCH_LSX_NATIVE) */

#if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
  #define simde_vmull_lane_s16(a, v, lane) vmull_lane_s16((a), (v), (lane))
#elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
  #define simde_vmull_lane_s16(a, v, lane) simde_x_lsx_vmull_lane_s16((a), (v), (lane))
#else
  #define simde_vmull_lane_s16(a, v, lane) simde_vmull_s16((a), simde_vdup_lane_s16((v), (lane)))
#endif
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vmull_lane_s16
  #define vmull_lane_s16(a, v, lane) simde_vmull_lane_s16((a), (v), (lane))
#endif

#if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
  #define simde_vmull_lane_s32(a, v, lane) vmull_lane_s32((a), (v), (lane))
#elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
  #define simde_vmull_lane_s32(a, v, lane) simde_x_lsx_vmull_lane_s32((a), (v), (lane))
#else
  #define simde_vmull_lane_s32(a, v, lane) simde_vmull_s32((a), simde_vdup_lane_s32((v), (lane)))
#endif
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vmull_lane_s32
  #define vmull_lane_s32(a, v, lane) simde_vmull_lane_s32((a), (v), (lane))
#endif

#if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
  #define simde_vmull_lane_u16(a, v, lane) vmull_lane_u16((a), (v), (lane))
#elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
  #define simde_vmull_lane_u16(a, v, lane) simde_x_lsx_vmull_lane_u16((a), (v), (lane))
#else
  #define simde_vmull_lane_u16(a, v, lane) simde_vmull_u16((a), simde_vdup_lane_u16((v), (lane)))
#endif
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vmull_lane_u16
  #define vmull_lane_u16(a, v, lane) simde_vmull_lane_u16((a), (v), (lane))
#endif

#if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
  #define simde_vmull_lane_u32(a, v, lane) vmull_lane_u32((a), (v), (lane))
#elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
  #define simde_vmull_lane_u32(a, v, lane) simde_x_lsx_vmull_lane_u32((a), (v), (lane))
#else
  #define simde_vmull_lane_u32(a, v, lane) simde_vmull_u32((a), simde_vdup_lane_u32((v), (lane)))
#endif
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vmull_lane_u32
  #define vmull_lane_u32(a, v, lane) simde_vmull_lane_u32((a), (v), (lane))
#endif

#if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
  #define simde_vmull_laneq_s16(a, v, lane) vmull_laneq_s16((a), (v), (lane))
#elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
  #define simde_vmull_laneq_s16(a, v, lane) simde_x_lsx_vmull_laneq_s16((a), (v), (lane))
#else
  #define simde_vmull_laneq_s16(a, v, lane) simde_vmull_s16((a), simde_vdup_laneq_s16((v), (lane)))
#endif
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES)
  #undef vmull_laneq_s16
  #define vmull_laneq_s16(a, v, lane) simde_vmull_laneq_s16((a), (v), (lane))
#endif

#if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
  #define simde_vmull_laneq_s32(a, v, lane) vmull_laneq_s32((a), (v), (lane))
#elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
  #define simde_vmull_laneq_s32(a, v, lane) simde_x_lsx_vmull_laneq_s32((a), (v), (lane))
#else
  #define simde_vmull_laneq_s32(a, v, lane) simde_vmull_s32((a), simde_vdup_laneq_s32((v), (lane)))
#endif
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES)
  #undef vmull_laneq_s32
  #define vmull_laneq_s32(a, v, lane) simde_vmull_laneq_s32((a), (v), (lane))
#endif

#if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
  #define simde_vmull_laneq_u16(a, v, lane) vmull_laneq_u16((a), (v), (lane))
#elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
  #define simde_vmull_laneq_u16(a, v, lane) simde_x_lsx_vmull_laneq_u16((a), (v), (lane))
#else
  #define simde_vmull_laneq_u16(a, v, lane) simde_vmull_u16((a), simde_vdup_laneq_u16((v), (lane)))
#endif
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES)
  #undef vmull_laneq_u16
  #define vmull_laneq_u16(a, v, lane) simde_vmull_laneq_u16((a), (v), (lane))
#endif

#if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
  #define simde_vmull_laneq_u32(a, v, lane) vmull_laneq_u32((a), (v), (lane))
#elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
  #define simde_vmull_laneq_u32(a, v, lane) simde_x_lsx_vmull_laneq_u32((a), (v), (lane))
#else
  #define simde_vmull_laneq_u32(a, v, lane) simde_vmull_u32((a), simde_vdup_laneq_u32((v), (lane)))
#endif
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES)
  #undef vmull_laneq_u32
  #define vmull_laneq_u32(a, v, lane) simde_vmull_laneq_u32((a), (v), (lane))
#endif

SIMDE_END_DECLS_
HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_ARM_NEON_MULL_LANE_H) */
