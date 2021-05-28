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
 *   2021      Zhi An Ng <zhin@google.com> (Copyright owned by Google, LLC)
 *   2021      Evan Nemerson <evan@nemerson.com>
 */

#if !defined(SIMDE_ARM_NEON_LD4_LANE_H)
#define SIMDE_ARM_NEON_LD4_LANE_H

#include "types.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

#if !defined(SIMDE_BUG_INTEL_857088)

SIMDE_FUNCTION_ATTRIBUTES
simde_int8x8x4_t
simde_vld4_lane_s8(int8_t const ptr[HEDLEY_ARRAY_PARAM(4)], simde_int8x8x4_t src, const int lane)
    SIMDE_REQUIRE_CONSTANT_RANGE(lane, 0, 7) {
  simde_int8x8x4_t r;

  for (size_t i = 0 ; i < 4 ; i++) {
    simde_int8x8_private tmp_ = simde_int8x8_to_private(src.val[i]);
    tmp_.values[lane] = ptr[i];
    r.val[i] = simde_int8x8_from_private(tmp_);
  }

  return r;
}
#if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
  #define simde_vld4_lane_s8(ptr, src, lane) vld4_lane_s8(ptr, src, lane)
#endif
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vld4_lane_s8
  #define vld4_lane_s8(ptr, src, lane) simde_vld4_lane_s8((ptr), (src), (lane))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_int16x4x4_t
simde_vld4_lane_s16(int16_t const ptr[HEDLEY_ARRAY_PARAM(4)], simde_int16x4x4_t src, const int lane)
    SIMDE_REQUIRE_CONSTANT_RANGE(lane, 0, 3) {
  simde_int16x4x4_t r;

  for (size_t i = 0 ; i < 4 ; i++) {
    simde_int16x4_private tmp_ = simde_int16x4_to_private(src.val[i]);
    tmp_.values[lane] = ptr[i];
    r.val[i] = simde_int16x4_from_private(tmp_);
  }

  return r;
}
#if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
  #define simde_vld4_lane_s16(ptr, src, lane) vld4_lane_s16(ptr, src, lane)
#endif
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vld4_lane_s16
  #define vld4_lane_s16(ptr, src, lane) simde_vld4_lane_s16((ptr), (src), (lane))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_int32x2x4_t
simde_vld4_lane_s32(int32_t const ptr[HEDLEY_ARRAY_PARAM(4)], simde_int32x2x4_t src, const int lane)
    SIMDE_REQUIRE_CONSTANT_RANGE(lane, 0, 1) {
  simde_int32x2x4_t r;

  for (size_t i = 0 ; i < 4 ; i++) {
    simde_int32x2_private tmp_ = simde_int32x2_to_private(src.val[i]);
    tmp_.values[lane] = ptr[i];
    r.val[i] = simde_int32x2_from_private(tmp_);
  }

  return r;
}
#if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
  #define simde_vld4_lane_s32(ptr, src, lane) vld4_lane_s32(ptr, src, lane)
#endif
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vld4_lane_s32
  #define vld4_lane_s32(ptr, src, lane) simde_vld4_lane_s32((ptr), (src), (lane))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint8x8x4_t
simde_vld4_lane_u8(uint8_t const ptr[HEDLEY_ARRAY_PARAM(4)], simde_uint8x8x4_t src, const int lane)
    SIMDE_REQUIRE_CONSTANT_RANGE(lane, 0, 7) {
  simde_uint8x8x4_t r;

  for (size_t i = 0 ; i < 4 ; i++) {
    simde_uint8x8_private tmp_ = simde_uint8x8_to_private(src.val[i]);
    tmp_.values[lane] = ptr[i];
    r.val[i] = simde_uint8x8_from_private(tmp_);
  }

  return r;
}
#if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
  #define simde_vld4_lane_u8(ptr, src, lane) vld4_lane_u8(ptr, src, lane)
#endif
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vld4_lane_u8
  #define vld4_lane_u8(ptr, src, lane) simde_vld4_lane_u8((ptr), (src), (lane))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint16x4x4_t
simde_vld4_lane_u16(uint16_t const ptr[HEDLEY_ARRAY_PARAM(4)], simde_uint16x4x4_t src, const int lane)
    SIMDE_REQUIRE_CONSTANT_RANGE(lane, 0, 3) {
  simde_uint16x4x4_t r;

  for (size_t i = 0 ; i < 4 ; i++) {
    simde_uint16x4_private tmp_ = simde_uint16x4_to_private(src.val[i]);
    tmp_.values[lane] = ptr[i];
    r.val[i] = simde_uint16x4_from_private(tmp_);
  }

  return r;
}
#if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
  #define simde_vld4_lane_u16(ptr, src, lane) vld4_lane_u16(ptr, src, lane)
#endif
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vld4_lane_u16
  #define vld4_lane_u16(ptr, src, lane) simde_vld4_lane_u16((ptr), (src), (lane))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint32x2x4_t
simde_vld4_lane_u32(uint32_t const ptr[HEDLEY_ARRAY_PARAM(4)], simde_uint32x2x4_t src, const int lane)
    SIMDE_REQUIRE_CONSTANT_RANGE(lane, 0, 1) {
  simde_uint32x2x4_t r;

  for (size_t i = 0 ; i < 4 ; i++) {
    simde_uint32x2_private tmp_ = simde_uint32x2_to_private(src.val[i]);
    tmp_.values[lane] = ptr[i];
    r.val[i] = simde_uint32x2_from_private(tmp_);
  }

  return r;
}
#if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
  #define simde_vld4_lane_u32(ptr, src, lane) vld4_lane_u32(ptr, src, lane)
#endif
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vld4_lane_u32
  #define vld4_lane_u32(ptr, src, lane) simde_vld4_lane_u32((ptr), (src), (lane))
#endif

#endif /* !defined(SIMDE_BUG_INTEL_857088) */

SIMDE_END_DECLS_
HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_ARM_NEON_LD4_LANE_H) */
