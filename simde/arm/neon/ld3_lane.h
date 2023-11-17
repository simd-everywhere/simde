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

#if !defined(SIMDE_ARM_NEON_LD3_LANE_H)
#define SIMDE_ARM_NEON_LD3_LANE_H

#include "types.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

SIMDE_FUNCTION_ATTRIBUTES
simde_int8x8x3_t simde_vld3_lane_s8(int8_t const ptr[HEDLEY_ARRAY_PARAM(3)], simde_int8x8x3_t src, const int lane)
    SIMDE_REQUIRE_CONSTANT_RANGE(lane, 0, 7) {
  simde_int8x8x3_t r;

  for (size_t i = 0 ; i < 3 ; i++) {
    simde_int8x8_private tmp_ = simde_int8x8_to_private(src.val[i]);
    tmp_.values[lane] = ptr[i];
    r.val[i] = simde_int8x8_from_private(tmp_);
  }
  return r;
}
#if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
  #define simde_vld3_lane_s8(ptr, src, lane) vld3_lane_s8(ptr, src, lane)
#endif
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vld3_lane_s8
  #define vld3_lane_s8(ptr, src, lane) simde_vld3_lane_s8((ptr), (src), (lane))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_int16x4x3_t simde_vld3_lane_s16(int16_t const ptr[HEDLEY_ARRAY_PARAM(3)], simde_int16x4x3_t src, const int lane)
    SIMDE_REQUIRE_CONSTANT_RANGE(lane, 0, 3) {
  simde_int16x4x3_t r;

  for (size_t i = 0 ; i < 3 ; i++) {
    simde_int16x4_private tmp_ = simde_int16x4_to_private(src.val[i]);
    tmp_.values[lane] = ptr[i];
    r.val[i] = simde_int16x4_from_private(tmp_);
  }
  return r;
}
#if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
  #define simde_vld3_lane_s16(ptr, src, lane) vld3_lane_s16(ptr, src, lane)
#endif
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vld3_lane_s16
  #define vld3_lane_s16(ptr, src, lane) simde_vld3_lane_s16((ptr), (src), (lane))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_int32x2x3_t simde_vld3_lane_s32(int32_t const ptr[HEDLEY_ARRAY_PARAM(3)], simde_int32x2x3_t src, const int lane)
    SIMDE_REQUIRE_CONSTANT_RANGE(lane, 0, 1) {
  simde_int32x2x3_t r;

  for (size_t i = 0 ; i < 3 ; i++) {
    simde_int32x2_private tmp_ = simde_int32x2_to_private(src.val[i]);
    tmp_.values[lane] = ptr[i];
    r.val[i] = simde_int32x2_from_private(tmp_);
  }
  return r;
}
#if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
  #define simde_vld3_lane_s32(ptr, src, lane) vld3_lane_s32(ptr, src, lane)
#endif
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vld3_lane_s32
  #define vld3_lane_s32(ptr, src, lane) simde_vld3_lane_s32((ptr), (src), (lane))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_int64x1x3_t simde_vld3_lane_s64(int64_t const ptr[HEDLEY_ARRAY_PARAM(3)], simde_int64x1x3_t src, const int lane)
    SIMDE_REQUIRE_CONSTANT_RANGE(lane, 0, 0) {
  simde_int64x1x3_t r;

  for (size_t i = 0 ; i < 3 ; i++) {
    simde_int64x1_private tmp_ = simde_int64x1_to_private(src.val[i]);
    tmp_.values[lane] = ptr[i];
    r.val[i] = simde_int64x1_from_private(tmp_);
  }
  return r;
}
#if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
  #define simde_vld3_lane_s64(ptr, src, lane) vld3_lane_s64(ptr, src, lane)
#endif
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES)
  #undef vld3_lane_s64
  #define vld3_lane_s64(ptr, src, lane) simde_vld3_lane_s64((ptr), (src), (lane))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint8x8x3_t simde_vld3_lane_u8(uint8_t const ptr[HEDLEY_ARRAY_PARAM(3)], simde_uint8x8x3_t src, const int lane)
    SIMDE_REQUIRE_CONSTANT_RANGE(lane, 0, 7) {
  simde_uint8x8x3_t r;

  for (size_t i = 0 ; i < 3 ; i++) {
    simde_uint8x8_private tmp_ = simde_uint8x8_to_private(src.val[i]);
    tmp_.values[lane] = ptr[i];
    r.val[i] = simde_uint8x8_from_private(tmp_);
  }
  return r;
}
#if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
  #define simde_vld3_lane_u8(ptr, src, lane) vld3_lane_u8(ptr, src, lane)
#endif
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vld3_lane_u8
  #define vld3_lane_u8(ptr, src, lane) simde_vld3_lane_u8((ptr), (src), (lane))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint16x4x3_t simde_vld3_lane_u16(uint16_t const ptr[HEDLEY_ARRAY_PARAM(3)], simde_uint16x4x3_t src, const int lane)
    SIMDE_REQUIRE_CONSTANT_RANGE(lane, 0, 3) {
  simde_uint16x4x3_t r;

  for (size_t i = 0 ; i < 3 ; i++) {
    simde_uint16x4_private tmp_ = simde_uint16x4_to_private(src.val[i]);
    tmp_.values[lane] = ptr[i];
    r.val[i] = simde_uint16x4_from_private(tmp_);
  }
  return r;
}
#if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
  #define simde_vld3_lane_u16(ptr, src, lane) vld3_lane_u16(ptr, src, lane)
#endif
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vld3_lane_u16
  #define vld3_lane_u16(ptr, src, lane) simde_vld3_lane_u16((ptr), (src), (lane))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint32x2x3_t simde_vld3_lane_u32(uint32_t const ptr[HEDLEY_ARRAY_PARAM(3)], simde_uint32x2x3_t src, const int lane)
    SIMDE_REQUIRE_CONSTANT_RANGE(lane, 0, 1) {
  simde_uint32x2x3_t r;

  for (size_t i = 0 ; i < 3 ; i++) {
    simde_uint32x2_private tmp_ = simde_uint32x2_to_private(src.val[i]);
    tmp_.values[lane] = ptr[i];
    r.val[i] = simde_uint32x2_from_private(tmp_);
  }
  return r;
}
#if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
  #define simde_vld3_lane_u32(ptr, src, lane) vld3_lane_u32(ptr, src, lane)
#endif
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vld3_lane_u32
  #define vld3_lane_u32(ptr, src, lane) simde_vld3_lane_u32((ptr), (src), (lane))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint64x1x3_t simde_vld3_lane_u64(uint64_t const ptr[HEDLEY_ARRAY_PARAM(3)], simde_uint64x1x3_t src, const int lane)
    SIMDE_REQUIRE_CONSTANT_RANGE(lane, 0, 0) {
  simde_uint64x1x3_t r;

  for (size_t i = 0 ; i < 3 ; i++) {
    simde_uint64x1_private tmp_ = simde_uint64x1_to_private(src.val[i]);
    tmp_.values[lane] = ptr[i];
    r.val[i] = simde_uint64x1_from_private(tmp_);
  }
  return r;
}
#if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
  #define simde_vld3_lane_u64(ptr, src, lane) vld3_lane_u64(ptr, src, lane)
#endif
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES)
  #undef vld3_lane_u64
  #define vld3_lane_u64(ptr, src, lane) simde_vld3_lane_u64((ptr), (src), (lane))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_float16x4x3_t simde_vld3_lane_f16(simde_float16_t const ptr[HEDLEY_ARRAY_PARAM(3)], simde_float16x4x3_t src, const int lane)
    SIMDE_REQUIRE_CONSTANT_RANGE(lane, 0, 3) {
  simde_float16x4x3_t r;

  for (size_t i = 0 ; i < 3 ; i++) {
    simde_float16x4_private tmp_ = simde_float16x4_to_private(src.val[i]);
    tmp_.values[lane] = ptr[i];
    r.val[i] = simde_float16x4_from_private(tmp_);
  }
  return r;
}
#if defined(SIMDE_ARM_NEON_A32V7_NATIVE) && defined(SIMDE_ARM_NEON_FP16)
  #define simde_vld3_lane_f16(ptr, src, lane) vld3_lane_f16(ptr, src, lane)
#endif
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vld3_lane_f16
  #define vld3_lane_f16(ptr, src, lane) simde_vld3_lane_f16((ptr), (src), (lane))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_float32x2x3_t simde_vld3_lane_f32(simde_float32_t const ptr[HEDLEY_ARRAY_PARAM(3)], simde_float32x2x3_t src, const int lane)
    SIMDE_REQUIRE_CONSTANT_RANGE(lane, 0, 1) {
  simde_float32x2x3_t r;

  for (size_t i = 0 ; i < 3 ; i++) {
    simde_float32x2_private tmp_ = simde_float32x2_to_private(src.val[i]);
    tmp_.values[lane] = ptr[i];
    r.val[i] = simde_float32x2_from_private(tmp_);
  }
  return r;
}
#if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
  #define simde_vld3_lane_f32(ptr, src, lane) vld3_lane_f32(ptr, src, lane)
#endif
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vld3_lane_f32
  #define vld3_lane_f32(ptr, src, lane) simde_vld3_lane_f32((ptr), (src), (lane))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_float64x1x3_t simde_vld3_lane_f64(simde_float64_t const ptr[HEDLEY_ARRAY_PARAM(3)], simde_float64x1x3_t src, const int lane)
    SIMDE_REQUIRE_CONSTANT_RANGE(lane, 0, 0) {
  simde_float64x1x3_t r;

  for (size_t i = 0 ; i < 3 ; i++) {
    simde_float64x1_private tmp_ = simde_float64x1_to_private(src.val[i]);
    tmp_.values[lane] = ptr[i];
    r.val[i] = simde_float64x1_from_private(tmp_);
  }
  return r;
}
#if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
  #define simde_vld3_lane_f64(ptr, src, lane) vld3_lane_f64(ptr, src, lane)
#endif
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES)
  #undef vld3_lane_f64
  #define vld3_lane_f64(ptr, src, lane) simde_vld3_lane_f64((ptr), (src), (lane))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_int8x16x3_t simde_vld3q_lane_s8(int8_t const ptr[HEDLEY_ARRAY_PARAM(3)], simde_int8x16x3_t src, const int lane)
    SIMDE_REQUIRE_CONSTANT_RANGE(lane, 0, 15) {
  simde_int8x16x3_t r;

  for (size_t i = 0 ; i < 3 ; i++) {
    simde_int8x16_private tmp_ = simde_int8x16_to_private(src.val[i]);
    tmp_.values[lane] = ptr[i];
    r.val[i] = simde_int8x16_from_private(tmp_);
  }
  return r;
}
#if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
  #define simde_vld3q_lane_s8(ptr, src, lane) vld3q_lane_s8(ptr, src, lane)
#endif
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES)
  #undef vld3q_lane_s8
  #define vld3q_lane_s8(ptr, src, lane) simde_vld3q_lane_s8((ptr), (src), (lane))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_int16x8x3_t simde_vld3q_lane_s16(int16_t const ptr[HEDLEY_ARRAY_PARAM(3)], simde_int16x8x3_t src, const int lane)
    SIMDE_REQUIRE_CONSTANT_RANGE(lane, 0, 7) {
  simde_int16x8x3_t r;

  for (size_t i = 0 ; i < 3 ; i++) {
    simde_int16x8_private tmp_ = simde_int16x8_to_private(src.val[i]);
    tmp_.values[lane] = ptr[i];
    r.val[i] = simde_int16x8_from_private(tmp_);
  }
  return r;
}
#if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
  #define simde_vld3q_lane_s16(ptr, src, lane) vld3q_lane_s16(ptr, src, lane)
#endif
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES)
  #undef vld3q_lane_s16
  #define vld3q_lane_s16(ptr, src, lane) simde_vld3q_lane_s16((ptr), (src), (lane))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_int32x4x3_t simde_vld3q_lane_s32(int32_t const ptr[HEDLEY_ARRAY_PARAM(3)], simde_int32x4x3_t src, const int lane)
    SIMDE_REQUIRE_CONSTANT_RANGE(lane, 0, 3) {
  simde_int32x4x3_t r;

  for (size_t i = 0 ; i < 3 ; i++) {
    simde_int32x4_private tmp_ = simde_int32x4_to_private(src.val[i]);
    tmp_.values[lane] = ptr[i];
    r.val[i] = simde_int32x4_from_private(tmp_);
  }
  return r;
}
#if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
  #define simde_vld3q_lane_s32(ptr, src, lane) vld3q_lane_s32(ptr, src, lane)
#endif
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vld3q_lane_s32
  #define vld3q_lane_s32(ptr, src, lane) simde_vld3q_lane_s32((ptr), (src), (lane))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_int64x2x3_t simde_vld3q_lane_s64(int64_t const ptr[HEDLEY_ARRAY_PARAM(3)], simde_int64x2x3_t src, const int lane)
    SIMDE_REQUIRE_CONSTANT_RANGE(lane, 0, 1) {
  simde_int64x2x3_t r;

  for (size_t i = 0 ; i < 3 ; i++) {
    simde_int64x2_private tmp_ = simde_int64x2_to_private(src.val[i]);
    tmp_.values[lane] = ptr[i];
    r.val[i] = simde_int64x2_from_private(tmp_);
  }
  return r;
}
#if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
  #define simde_vld3q_lane_s64(ptr, src, lane) vld3q_lane_s64(ptr, src, lane)
#endif
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES)
  #undef vld3q_lane_s64
  #define vld3q_lane_s64(ptr, src, lane) simde_vld3q_lane_s64((ptr), (src), (lane))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint8x16x3_t simde_vld3q_lane_u8(uint8_t const ptr[HEDLEY_ARRAY_PARAM(3)], simde_uint8x16x3_t src, const int lane)
    SIMDE_REQUIRE_CONSTANT_RANGE(lane, 0, 15) {
  simde_uint8x16x3_t r;

  for (size_t i = 0 ; i < 3 ; i++) {
    simde_uint8x16_private tmp_ = simde_uint8x16_to_private(src.val[i]);
    tmp_.values[lane] = ptr[i];
    r.val[i] = simde_uint8x16_from_private(tmp_);
  }
  return r;
}
#if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
  #define simde_vld3q_lane_u8(ptr, src, lane) vld3q_lane_u8(ptr, src, lane)
#endif
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES)
  #undef vld3q_lane_u8
  #define vld3q_lane_u8(ptr, src, lane) simde_vld3q_lane_u8((ptr), (src), (lane))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint16x8x3_t simde_vld3q_lane_u16(uint16_t const ptr[HEDLEY_ARRAY_PARAM(3)], simde_uint16x8x3_t src, const int lane)
    SIMDE_REQUIRE_CONSTANT_RANGE(lane, 0, 7) {
  simde_uint16x8x3_t r;

  for (size_t i = 0 ; i < 3 ; i++) {
    simde_uint16x8_private tmp_ = simde_uint16x8_to_private(src.val[i]);
    tmp_.values[lane] = ptr[i];
    r.val[i] = simde_uint16x8_from_private(tmp_);
  }
  return r;
}
#if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
  #define simde_vld3q_lane_u16(ptr, src, lane) vld3q_lane_u16(ptr, src, lane)
#endif
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES)
  #undef vld3q_lane_u16
  #define vld3q_lane_u16(ptr, src, lane) simde_vld3q_lane_u16((ptr), (src), (lane))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint32x4x3_t simde_vld3q_lane_u32(uint32_t const ptr[HEDLEY_ARRAY_PARAM(3)], simde_uint32x4x3_t src, const int lane)
    SIMDE_REQUIRE_CONSTANT_RANGE(lane, 0, 3) {
  simde_uint32x4x3_t r;

  for (size_t i = 0 ; i < 3 ; i++) {
    simde_uint32x4_private tmp_ = simde_uint32x4_to_private(src.val[i]);
    tmp_.values[lane] = ptr[i];
    r.val[i] = simde_uint32x4_from_private(tmp_);
  }
  return r;
}
#if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
  #define simde_vld3q_lane_u32(ptr, src, lane) vld3q_lane_u32(ptr, src, lane)
#endif
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vld3q_lane_u32
  #define vld3q_lane_u32(ptr, src, lane) simde_vld3q_lane_u32((ptr), (src), (lane))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint64x2x3_t simde_vld3q_lane_u64(uint64_t const ptr[HEDLEY_ARRAY_PARAM(3)], simde_uint64x2x3_t src, const int lane)
    SIMDE_REQUIRE_CONSTANT_RANGE(lane, 0, 1) {
  simde_uint64x2x3_t r;

  for (size_t i = 0 ; i < 3 ; i++) {
    simde_uint64x2_private tmp_ = simde_uint64x2_to_private(src.val[i]);
    tmp_.values[lane] = ptr[i];
    r.val[i] = simde_uint64x2_from_private(tmp_);
  }
  return r;
}
#if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
  #define simde_vld3q_lane_u64(ptr, src, lane) vld3q_lane_u64(ptr, src, lane)
#endif
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES)
  #undef vld3q_lane_u64
  #define vld3q_lane_u64(ptr, src, lane) simde_vld3q_lane_u64((ptr), (src), (lane))
#endif
SIMDE_FUNCTION_ATTRIBUTES
simde_float16x8x3_t simde_vld3q_lane_f16(simde_float16_t const ptr[HEDLEY_ARRAY_PARAM(3)], simde_float16x8x3_t src, const int lane)
    SIMDE_REQUIRE_CONSTANT_RANGE(lane, 0, 7) {
  simde_float16x8x3_t r;

  for (size_t i = 0 ; i < 3 ; i++) {
    simde_float16x8_private tmp_ = simde_float16x8_to_private(src.val[i]);
    tmp_.values[lane] = ptr[i];
    r.val[i] = simde_float16x8_from_private(tmp_);
  }
  return r;
}
#if defined(SIMDE_ARM_NEON_A32V7_NATIVE) && defined(SIMDE_ARM_NEON_FP16)
  #define simde_vld3q_lane_f16(ptr, src, lane) vld3q_lane_f16(ptr, src, lane)
#endif
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vld3q_lane_f16
  #define vld3q_lane_f16(ptr, src, lane) simde_vld3q_lane_f16((ptr), (src), (lane))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_float32x4x3_t simde_vld3q_lane_f32(simde_float32_t const ptr[HEDLEY_ARRAY_PARAM(3)], simde_float32x4x3_t src, const int lane)
    SIMDE_REQUIRE_CONSTANT_RANGE(lane, 0, 3) {
  simde_float32x4x3_t r;

  for (size_t i = 0 ; i < 3 ; i++) {
    simde_float32x4_private tmp_ = simde_float32x4_to_private(src.val[i]);
    tmp_.values[lane] = ptr[i];
    r.val[i] = simde_float32x4_from_private(tmp_);
  }
  return r;
}
#if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
  #define simde_vld3q_lane_f32(ptr, src, lane) vld3q_lane_f32(ptr, src, lane)
#endif
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vld3q_lane_f32
  #define vld3q_lane_f32(ptr, src, lane) simde_vld3q_lane_f32((ptr), (src), (lane))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_float64x2x3_t simde_vld3q_lane_f64(simde_float64_t const ptr[HEDLEY_ARRAY_PARAM(3)], simde_float64x2x3_t src, const int lane)
    SIMDE_REQUIRE_CONSTANT_RANGE(lane, 0, 1) {
  simde_float64x2x3_t r;

  for (size_t i = 0 ; i < 3 ; i++) {
    simde_float64x2_private tmp_ = simde_float64x2_to_private(src.val[i]);
    tmp_.values[lane] = ptr[i];
    r.val[i] = simde_float64x2_from_private(tmp_);
  }
  return r;
}
#if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
  #define simde_vld3q_lane_f64(ptr, src, lane) vld3q_lane_f64(ptr, src, lane)
#endif
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES)
  #undef vld3q_lane_f64
  #define vld3q_lane_f64(ptr, src, lane) simde_vld3q_lane_f64((ptr), (src), (lane))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_poly8x8x3_t simde_vld3_lane_p8(simde_poly8_t const ptr[HEDLEY_ARRAY_PARAM(3)], simde_poly8x8x3_t src, const int lane)
    SIMDE_REQUIRE_CONSTANT_RANGE(lane, 0, 7) {
  simde_poly8x8x3_t r;

  for (size_t i = 0 ; i < 3 ; i++) {
    simde_poly8x8_private tmp_ = simde_poly8x8_to_private(src.val[i]);
    tmp_.values[lane] = ptr[i];
    r.val[i] = simde_poly8x8_from_private(tmp_);
  }
  return r;
}
#if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
  #define simde_vld3_lane_p8(ptr, src, lane) vld3_lane_p8(ptr, src, lane)
#endif
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vld3_lane_p8
  #define vld3_lane_p8(ptr, src, lane) simde_vld3_lane_p8((ptr), (src), (lane))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_poly16x4x3_t simde_vld3_lane_p16(simde_poly16_t const ptr[HEDLEY_ARRAY_PARAM(3)], simde_poly16x4x3_t src, const int lane)
    SIMDE_REQUIRE_CONSTANT_RANGE(lane, 0, 3) {
  simde_poly16x4x3_t r;

  for (size_t i = 0 ; i < 3 ; i++) {
    simde_poly16x4_private tmp_ = simde_poly16x4_to_private(src.val[i]);
    tmp_.values[lane] = ptr[i];
    r.val[i] = simde_poly16x4_from_private(tmp_);
  }
  return r;
}
#if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
  #define simde_vld3_lane_p16(ptr, src, lane) vld3_lane_p16(ptr, src, lane)
#endif
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vld3_lane_p16
  #define vld3_lane_p16(ptr, src, lane) simde_vld3_lane_p16((ptr), (src), (lane))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_poly64x1x3_t simde_vld3_lane_p64(simde_poly64_t const ptr[HEDLEY_ARRAY_PARAM(3)], simde_poly64x1x3_t src, const int lane)
    SIMDE_REQUIRE_CONSTANT_RANGE(lane, 0, 0) {
  simde_poly64x1x3_t r;

  for (size_t i = 0 ; i < 3 ; i++) {
    simde_poly64x1_private tmp_ = simde_poly64x1_to_private(src.val[i]);
    tmp_.values[lane] = ptr[i];
    r.val[i] = simde_poly64x1_from_private(tmp_);
  }
  return r;
}
#if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
  #define simde_vld3_lane_p64(ptr, src, lane) vld3_lane_p64(ptr, src, lane)
#endif
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES)
  #undef vld3_lane_p64
  #define vld3_lane_p64(ptr, src, lane) simde_vld3_lane_p64((ptr), (src), (lane))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_poly8x16x3_t simde_vld3q_lane_p8(simde_poly8_t const ptr[HEDLEY_ARRAY_PARAM(3)], simde_poly8x16x3_t src, const int lane)
    SIMDE_REQUIRE_CONSTANT_RANGE(lane, 0, 15) {
  simde_poly8x16x3_t r;

  for (size_t i = 0 ; i < 3 ; i++) {
    simde_poly8x16_private tmp_ = simde_poly8x16_to_private(src.val[i]);
    tmp_.values[lane] = ptr[i];
    r.val[i] = simde_poly8x16_from_private(tmp_);
  }
  return r;
}
#if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
  #define simde_vld3q_lane_p8(ptr, src, lane) vld3q_lane_p8(ptr, src, lane)
#endif
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES)
  #undef vld3q_lane_p8
  #define vld3q_lane_p8(ptr, src, lane) simde_vld3q_lane_p8((ptr), (src), (lane))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_poly16x8x3_t simde_vld3q_lane_p16(simde_poly16_t const ptr[HEDLEY_ARRAY_PARAM(3)], simde_poly16x8x3_t src, const int lane)
    SIMDE_REQUIRE_CONSTANT_RANGE(lane, 0, 7) {
  simde_poly16x8x3_t r;

  for (size_t i = 0 ; i < 3 ; i++) {
    simde_poly16x8_private tmp_ = simde_poly16x8_to_private(src.val[i]);
    tmp_.values[lane] = ptr[i];
    r.val[i] = simde_poly16x8_from_private(tmp_);
  }
  return r;
}
#if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
  #define simde_vld3q_lane_p16(ptr, src, lane) vld3q_lane_p16(ptr, src, lane)
#endif
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES)
  #undef vld3q_lane_p16
  #define vld3q_lane_p16(ptr, src, lane) simde_vld3q_lane_p16((ptr), (src), (lane))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_poly64x2x3_t simde_vld3q_lane_p64(simde_poly64_t const ptr[HEDLEY_ARRAY_PARAM(3)], simde_poly64x2x3_t src, const int lane)
    SIMDE_REQUIRE_CONSTANT_RANGE(lane, 0, 1) {
  simde_poly64x2x3_t r;

  for (size_t i = 0 ; i < 3 ; i++) {
    simde_poly64x2_private tmp_ = simde_poly64x2_to_private(src.val[i]);
    tmp_.values[lane] = ptr[i];
    r.val[i] = simde_poly64x2_from_private(tmp_);
  }
  return r;
}
#if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
  #define simde_vld3q_lane_p64(ptr, src, lane) vld3q_lane_p64(ptr, src, lane)
#endif
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES)
  #undef vld3q_lane_p64
  #define vld3q_lane_p64(ptr, src, lane) simde_vld3q_lane_p64((ptr), (src), (lane))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_bfloat16x4x3_t simde_vld3_lane_bf16(simde_bfloat16_t const ptr[HEDLEY_ARRAY_PARAM(3)], simde_bfloat16x4x3_t src, const int lane)
    SIMDE_REQUIRE_CONSTANT_RANGE(lane, 0, 3) {
  simde_bfloat16x4x3_t r;

  for (size_t i = 0 ; i < 3 ; i++) {
    simde_bfloat16x4_private tmp_ = simde_bfloat16x4_to_private(src.val[i]);
    tmp_.values[lane] = ptr[i];
    r.val[i] = simde_bfloat16x4_from_private(tmp_);
  }
  return r;
}
#if defined(SIMDE_ARM_NEON_A32V8_NATIVE) && defined(SIMDE_ARM_NEON_BF16)
  #define simde_vld3_lane_bf16(ptr, src, lane) vld3_lane_bf16(ptr, src, lane)
#endif
#if defined(SIMDE_ARM_NEON_A32V8_ENABLE_NATIVE_ALIASES)
  #undef vld3_lane_bf16
  #define vld3_lane_bf16(ptr, src, lane) simde_vld3_lane_bf16((ptr), (src), (lane))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_bfloat16x8x3_t simde_vld3q_lane_bf16(simde_bfloat16_t const ptr[HEDLEY_ARRAY_PARAM(3)], simde_bfloat16x8x3_t src, const int lane)
    SIMDE_REQUIRE_CONSTANT_RANGE(lane, 0, 7) {
  simde_bfloat16x8x3_t r;

  for (size_t i = 0 ; i < 3 ; i++) {
    simde_bfloat16x8_private tmp_ = simde_bfloat16x8_to_private(src.val[i]);
    tmp_.values[lane] = ptr[i];
    r.val[i] = simde_bfloat16x8_from_private(tmp_);
  }
  return r;
}
#if defined(SIMDE_ARM_NEON_A32V8_NATIVE) && defined(SIMDE_ARM_NEON_BF16)
  #define simde_vld3q_lane_bf16(ptr, src, lane) vld3q_lane_bf16(ptr, src, lane)
#endif
#if defined(SIMDE_ARM_NEON_A32V8_ENABLE_NATIVE_ALIASES)
  #undef vld3q_lane_bf16
  #define vld3q_lane_bf16(ptr, src, lane) simde_vld3q_lane_bf16((ptr), (src), (lane))
#endif

SIMDE_END_DECLS_
HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_ARM_NEON_LD3_LANE_H) */
