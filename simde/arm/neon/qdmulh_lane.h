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
 *   2021      Zhi An Ng <zhin@google.com> (Copyright owned by Google, LLC)
 *   2023      Yi-Yen Chung <eric681@andestech.com> (Copyright owned by Andes Technology)
 */

#if !defined(SIMDE_ARM_NEON_QDMULH_LANE_H)
#define SIMDE_ARM_NEON_QDMULH_LANE_H

#include "types.h"

#include "qdmulh_n.h"
#include "get_lane.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

#if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
  #define simde_vqdmulhh_lane_s16(a, v, lane) vqdmulhh_lane_s16((a), (v), (lane))
#else
  #define simde_vqdmulhh_lane_s16(a, v, lane) \
    simde_vqdmulhh_s16((a), simde_vget_lane_s16((v), (lane)))
#endif
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES)
  #undef vqdmulhh_lane_s16
  #define vqdmulhh_lane_s16(a, v, lane) simde_vqdmulhh_lane_s16((a), (v), (lane))
#endif

#if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
  #define simde_vqdmulh_lane_s16(a, v, lane) vqdmulh_lane_s16((a), (v), (lane))
#else
  #define simde_vqdmulh_lane_s16(a, v, lane) \
    simde_vqdmulh_n_s16((a), simde_vget_lane_s16((v), (lane)))
#endif
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vqdmulh_lane_s16
  #define vqdmulh_lane_s16(a, v, lane) simde_vqdmulh_lane_s16((a), (v), (lane))
#endif

#if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
  #define simde_vqdmulh_lane_s32(a, v, lane) vqdmulh_lane_s32((a), (v), (lane))
#else
  #define simde_vqdmulh_lane_s32(a, v, lane) \
    simde_vqdmulh_n_s32((a), simde_vget_lane_s32((v), (lane)))
#endif
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vqdmulh_lane_s32
  #define vqdmulh_lane_s32(a, v, lane) simde_vqdmulh_lane_s32((a), (v), (lane))
#endif

#if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
  #define simde_vqdmulhq_lane_s16(a, v, lane) vqdmulhq_lane_s16((a), (v), (lane))
#else
  #define simde_vqdmulhq_lane_s16(a, v, lane) \
    simde_vqdmulhq_n_s16((a), simde_vget_lane_s16((v), (lane)))
#endif
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vqdmulhq_lane_s16
  #define vqdmulhq_lane_s16(a, v, lane) simde_vqdmulhq_lane_s16((a), (v), (lane))
#endif

#if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
  #define simde_vqdmulhq_lane_s32(a, v, lane) vqdmulhq_lane_s32((a), (v), (lane))
#else
  #define simde_vqdmulhq_lane_s32(a, v, lane) \
    simde_vqdmulhq_n_s32((a), simde_vget_lane_s32((v), (lane)))
#endif
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vqdmulhq_lane_s32
  #define vqdmulhq_lane_s32(a, v, lane) simde_vqdmulhq_lane_s32((a), (v), (lane))
#endif

#if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
  #define simde_vqdmulhh_laneq_s16(a, v, lane) vqdmulhh_laneq_s16((a), (v), (lane))
#else
  #define simde_vqdmulhh_laneq_s16(a, v, lane) \
    simde_vqdmulhh_s16((a), simde_vgetq_lane_s16((v), (lane)))
#endif
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES)
  #undef vqdmulhh_laneq_s16
  #define vqdmulhh_laneq_s16(a, v, lane) simde_vqdmulhh_laneq_s16((a), (v), (lane))
#endif

#if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
  #define simde_vqdmulh_laneq_s16(a, v, lane) vqdmulh_laneq_s16((a), (v), (lane))
#else
  #define simde_vqdmulh_laneq_s16(a, v, lane) \
    simde_vqdmulh_n_s16((a), simde_vgetq_lane_s16((v), (lane)))
#endif
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES)
  #undef vqdmulh_laneq_s16
  #define vqdmulh_laneq_s16(a, v, lane) simde_vqdmulh_laneq_s16((a), (v), (lane))
#endif

#if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
  #define simde_vqdmulh_laneq_s32(a, v, lane) vqdmulh_laneq_s32((a), (v), (lane))
#else
  #define simde_vqdmulh_laneq_s32(a, v, lane) \
    simde_vqdmulh_n_s32((a), simde_vgetq_lane_s32((v), (lane)))
#endif
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES)
  #undef vqdmulh_laneq_s32
  #define vqdmulh_laneq_s32(a, v, lane) simde_vqdmulh_laneq_s32((a), (v), (lane))
#endif

#if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
  #define simde_vqdmulhq_laneq_s16(a, v, lane) vqdmulhq_laneq_s16((a), (v), (lane))
#else
  #define simde_vqdmulhq_laneq_s16(a, v, lane) \
    simde_vqdmulhq_n_s16((a), simde_vgetq_lane_s16((v), (lane)))
#endif
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES)
  #undef vqdmulhq_laneq_s16
  #define vqdmulhq_laneq_s16(a, v, lane) simde_vqdmulhq_laneq_s16((a), (v), (lane))
#endif

#if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
  #define simde_vqdmulhq_laneq_s32(a, v, lane) vqdmulhq_laneq_s32((a), (v), (lane))
#else
  #define simde_vqdmulhq_laneq_s32(a, v, lane) \
    simde_vqdmulhq_n_s32((a), simde_vgetq_lane_s32((v), (lane)))
#endif
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES)
  #undef vqdmulhq_laneq_s32
  #define vqdmulhq_laneq_s32(a, v, lane) simde_vqdmulhq_laneq_s32((a), (v), (lane))
#endif

#if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
  #if defined(__clang__) && !SIMDE_DETECT_CLANG_VERSION_CHECK(11,0,0)
    #define simde_vqdmulhs_lane_s32(a, v, lane) \
    SIMDE_DISABLE_DIAGNOSTIC_EXPR_(SIMDE_DIAGNOSTIC_DISABLE_VECTOR_CONVERSION_, vqdmulhs_lane_s32((a), (v), (lane)))
  #else
    #define simde_vqdmulhs_lane_s32(a, v, lane) vqdmulhs_lane_s32(a, v, lane)
  #endif
#else
  #define simde_vqdmulhs_lane_s32(a, v, lane) \
    simde_vqdmulhs_s32((a), simde_vget_lane_s32((v), (lane)))
#endif
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES)
  #undef vqdmulhs_lane_s32
  #define vqdmulhs_lane_s32(a, v, lane) simde_vqdmulhs_lane_s32((a), (v), (lane))
#endif

#if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
  #if defined(__clang__) && !SIMDE_DETECT_CLANG_VERSION_CHECK(11,0,0)
    #define simde_vqdmulhs_laneq_s32(a, v, lane) \
    SIMDE_DISABLE_DIAGNOSTIC_EXPR_(SIMDE_DIAGNOSTIC_DISABLE_VECTOR_CONVERSION_, vqdmulhs_laneq_s32((a), (v), (lane)))
  #else
    #define simde_vqdmulhs_laneq_s32(a, v, lane) vqdmulhs_laneq_s32(a, v, lane)
  #endif
#else
  #define simde_vqdmulhs_laneq_s32(a, v, lane) \
    simde_vqdmulhs_s32((a), simde_vgetq_lane_s32((v), (lane)))
#endif
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES)
  #undef vqdmulhs_laneq_s32
  #define vqdmulhs_laneq_s32(a, v, lane) simde_vqdmulhs_laneq_s32((a), (v), (lane))
#endif

SIMDE_END_DECLS_
HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_ARM_NEON_QDMULH_LANE_H) */
