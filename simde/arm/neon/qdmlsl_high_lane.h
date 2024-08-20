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
 *   2023      Yi-Yen Chung <eric681@andestech.com> (Copyright owned by Andes Technology)
 */

#if !defined(SIMDE_ARM_NEON_QDMLSL_HIGH_LANE_H)
#define SIMDE_ARM_NEON_QDMLSL_HIGH_LANE_H

#include "dup_lane.h"
#include "get_high.h"
#include "types.h"
#include "qdmlsl.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

#if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
  #define simde_vqdmlsl_high_lane_s16(a, b, v, lane) vqdmlsl_high_lane_s16(a, b, v, lane)
#else
  #define simde_vqdmlsl_high_lane_s16(a, b, v, lane) simde_vqdmlsl_s16((a), simde_vget_high_s16((b)), simde_vdup_lane_s16((v), (lane)))
#endif
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES)
  #undef vqdmlsl_high_lane_s16
  #define vqdmlsl_high_lane_s16(a, b, v, lane) simde_vqdmlsl_high_lane_s16((a), (b), (v), (lane))
#endif

#if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
  #define simde_vqdmlsl_high_laneq_s16(a, b, v, lane) vqdmlsl_high_laneq_s16(a, b, v, lane)
#else
  #define simde_vqdmlsl_high_laneq_s16(a, b, v, lane) simde_vqdmlsl_s16((a), simde_vget_high_s16((b)), simde_vdup_laneq_s16((v), (lane)))
#endif
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES)
  #undef vqdmlsl_high_laneq_s16
  #define vqdmlsl_high_laneq_s16(a, b, v, lane) simde_vqdmlsl_high_laneq_s16((a), (b), (v), (lane))
#endif

#if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
  #define simde_vqdmlsl_high_lane_s32(a, b, v, lane) vqdmlsl_high_lane_s32(a, b, v, lane)
#else
  #define simde_vqdmlsl_high_lane_s32(a, b, v, lane) simde_vqdmlsl_s32((a), simde_vget_high_s32((b)), simde_vdup_lane_s32((v), (lane)))
#endif
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES)
  #undef vqdmlsl_high_lane_s32
  #define vqdmlsl_high_lane_s32(a, b, v, lane) simde_vqdmlsl_high_lane_s32((a), (b), (v), (lane))
#endif

#if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
  #define simde_vqdmlsl_high_laneq_s32(a, b, v, lane) vqdmlsl_high_laneq_s32(a, b, v, lane)
#else
  #define simde_vqdmlsl_high_laneq_s32(a, b, v, lane) simde_vqdmlsl_s32((a), simde_vget_high_s32((b)), simde_vdup_laneq_s32((v), (lane)))
#endif
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES)
  #undef vqdmlsl_high_laneq_s32
  #define vqdmlsl_high_laneq_s32(a, b, v, lane) simde_vqdmlsl_high_laneq_s32((a), (b), (v), (lane))
#endif

SIMDE_END_DECLS_
HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_ARM_NEON_QDMLSL_HIGH_LANE_H) */
