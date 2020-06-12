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
 */

#if !defined(SIMDE_ARM_NEON_PMIN_H)
#define SIMDE_ARM_NEON_PMIN_H

#include "types.h"
#include "min.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

SIMDE_FUNCTION_ATTRIBUTES
simde_float32x2_t
simde_vpmin_f32(simde_float32x2_t a, simde_float32x2_t b) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vpmin_f32(a, b);
  #else
    simde_float32x2_private
      r_,
      a_ = simde_float32x2_to_private(a),
      b_ = simde_float32x2_to_private(b);

    #if defined(SIMDE_SHUFFLE_VECTOR_)
      __typeof__(r_) lo, hi;
      lo.values = SIMDE_SHUFFLE_VECTOR_(32, 8, a_.values, b_.values, 0, 2);
      hi.values = SIMDE_SHUFFLE_VECTOR_(32, 8, a_.values, b_.values, 1, 3);
      r_ = simde_float32x2_to_private(simde_vmin_f32(simde_float32x2_from_private(lo), simde_float32x2_from_private(hi)));
    #else
      const size_t halfway_point = sizeof(r_.values) / sizeof(r_.values[0]) / 2;
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < halfway_point ; i++) {
        const size_t idx = i << 1;
        r_.values[        i        ] = (a_.values[idx] < a_.values[idx + 1]) ? a_.values[idx] : a_.values[idx + 1];
        r_.values[i + halfway_point] = (b_.values[idx] < b_.values[idx + 1]) ? b_.values[idx] : b_.values[idx + 1];
      }
    #endif

    return simde_float32x2_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vpmin_f32
  #define vpmin_f32(a, b) simde_vpmin_f32((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_int8x8_t
simde_vpmin_s8(simde_int8x8_t a, simde_int8x8_t b) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vpmin_s8(a, b);
  #else
    simde_int8x8_private
      r_,
      a_ = simde_int8x8_to_private(a),
      b_ = simde_int8x8_to_private(b);

    #if defined(SIMDE_SHUFFLE_VECTOR_)
      __typeof__(r_) lo, hi;
      lo.values = SIMDE_SHUFFLE_VECTOR_(8, 8, a_.values, b_.values, 0, 2, 4, 6, 8, 10, 12, 14);
      hi.values = SIMDE_SHUFFLE_VECTOR_(8, 8, a_.values, b_.values, 1, 3, 5, 7, 9, 11, 13, 15);
      r_ = simde_int8x8_to_private(simde_vmin_s8(simde_int8x8_from_private(lo), simde_int8x8_from_private(hi)));
    #else
      const size_t halfway_point = sizeof(r_.values) / sizeof(r_.values[0]) / 2;
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < halfway_point ; i++) {
        const size_t idx = i << 1;
        r_.values[        i        ] = (a_.values[idx] < a_.values[idx + 1]) ? a_.values[idx] : a_.values[idx + 1];
        r_.values[i + halfway_point] = (b_.values[idx] < b_.values[idx + 1]) ? b_.values[idx] : b_.values[idx + 1];
      }
    #endif

    return simde_int8x8_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vpmin_s8
  #define vpmin_s8(a, b) simde_vpmin_s8((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_int16x4_t
simde_vpmin_s16(simde_int16x4_t a, simde_int16x4_t b) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vpmin_s16(a, b);
  #else
    simde_int16x4_private
      r_,
      a_ = simde_int16x4_to_private(a),
      b_ = simde_int16x4_to_private(b);

    #if defined(SIMDE_SHUFFLE_VECTOR_)
      __typeof__(r_) lo, hi;
      lo.values = SIMDE_SHUFFLE_VECTOR_(16, 8, a_.values, b_.values, 0, 2, 4, 6);
      hi.values = SIMDE_SHUFFLE_VECTOR_(16, 8, a_.values, b_.values, 1, 3, 5, 7);
      r_ = simde_int16x4_to_private(simde_vmin_s16(simde_int16x4_from_private(lo), simde_int16x4_from_private(hi)));
    #else
      const size_t halfway_point = sizeof(r_.values) / sizeof(r_.values[0]) / 2;
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < halfway_point ; i++) {
        const size_t idx = i << 1;
        r_.values[        i        ] = (a_.values[idx] < a_.values[idx + 1]) ? a_.values[idx] : a_.values[idx + 1];
        r_.values[i + halfway_point] = (b_.values[idx] < b_.values[idx + 1]) ? b_.values[idx] : b_.values[idx + 1];
      }
    #endif

    return simde_int16x4_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vpmin_s16
  #define vpmin_s16(a, b) simde_vpmin_s16((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_int32x2_t
simde_vpmin_s32(simde_int32x2_t a, simde_int32x2_t b) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vpmin_s32(a, b);
  #else
    simde_int32x2_private
      r_,
      a_ = simde_int32x2_to_private(a),
      b_ = simde_int32x2_to_private(b);

    #if defined(SIMDE_SHUFFLE_VECTOR_)
      __typeof__(r_) lo, hi;
      lo.values = SIMDE_SHUFFLE_VECTOR_(32, 8, a_.values, b_.values, 0, 2);
      hi.values = SIMDE_SHUFFLE_VECTOR_(32, 8, a_.values, b_.values, 1, 3);
      r_ = simde_int32x2_to_private(simde_vmin_s32(simde_int32x2_from_private(lo), simde_int32x2_from_private(hi)));
    #else
      const size_t halfway_point = sizeof(r_.values) / sizeof(r_.values[0]) / 2;
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < halfway_point ; i++) {
        const size_t idx = i << 1;
        r_.values[        i        ] = (a_.values[idx] < a_.values[idx + 1]) ? a_.values[idx] : a_.values[idx + 1];
        r_.values[i + halfway_point] = (b_.values[idx] < b_.values[idx + 1]) ? b_.values[idx] : b_.values[idx + 1];
      }
    #endif

    return simde_int32x2_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vpmin_s32
  #define vpmin_s32(a, b) simde_vpmin_s32((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint8x8_t
simde_vpmin_u8(simde_uint8x8_t a, simde_uint8x8_t b) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vpmin_u8(a, b);
  #else
    simde_uint8x8_private
      r_,
      a_ = simde_uint8x8_to_private(a),
      b_ = simde_uint8x8_to_private(b);

    #if defined(SIMDE_SHUFFLE_VECTOR_)
      __typeof__(r_) lo, hi;
      lo.values = SIMDE_SHUFFLE_VECTOR_(8, 8, a_.values, b_.values, 0, 2, 4, 6, 8, 10, 12, 14);
      hi.values = SIMDE_SHUFFLE_VECTOR_(8, 8, a_.values, b_.values, 1, 3, 5, 7, 9, 11, 13, 15);
      r_ = simde_uint8x8_to_private(simde_vmin_u8(simde_uint8x8_from_private(lo), simde_uint8x8_from_private(hi)));
    #else
      const size_t halfway_point = sizeof(r_.values) / sizeof(r_.values[0]) / 2;
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < halfway_point ; i++) {
        const size_t idx = i << 1;
        r_.values[        i        ] = (a_.values[idx] < a_.values[idx + 1]) ? a_.values[idx] : a_.values[idx + 1];
        r_.values[i + halfway_point] = (b_.values[idx] < b_.values[idx + 1]) ? b_.values[idx] : b_.values[idx + 1];
      }
    #endif

    return simde_uint8x8_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vpmin_u8
  #define vpmin_u8(a, b) simde_vpmin_u8((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint16x4_t
simde_vpmin_u16(simde_uint16x4_t a, simde_uint16x4_t b) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vpmin_u16(a, b);
  #else
    simde_uint16x4_private
      r_,
      a_ = simde_uint16x4_to_private(a),
      b_ = simde_uint16x4_to_private(b);

    #if defined(SIMDE_SHUFFLE_VECTOR_)
      __typeof__(r_) lo, hi;
      lo.values = SIMDE_SHUFFLE_VECTOR_(16, 8, a_.values, b_.values, 0, 2, 4, 6);
      hi.values = SIMDE_SHUFFLE_VECTOR_(16, 8, a_.values, b_.values, 1, 3, 5, 7);
      r_ = simde_uint16x4_to_private(simde_vmin_u16(simde_uint16x4_from_private(lo), simde_uint16x4_from_private(hi)));
    #else
      const size_t halfway_point = sizeof(r_.values) / sizeof(r_.values[0]) / 2;
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < halfway_point ; i++) {
        const size_t idx = i << 1;
        r_.values[        i        ] = (a_.values[idx] < a_.values[idx + 1]) ? a_.values[idx] : a_.values[idx + 1];
        r_.values[i + halfway_point] = (b_.values[idx] < b_.values[idx + 1]) ? b_.values[idx] : b_.values[idx + 1];
      }
    #endif

    return simde_uint16x4_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vpmin_u16
  #define vpmin_u16(a, b) simde_vpmin_u16((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint32x2_t
simde_vpmin_u32(simde_uint32x2_t a, simde_uint32x2_t b) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vpmin_u32(a, b);
  #else
    simde_uint32x2_private
      r_,
      a_ = simde_uint32x2_to_private(a),
      b_ = simde_uint32x2_to_private(b);

    #if defined(SIMDE_SHUFFLE_VECTOR_)
      __typeof__(r_) lo, hi;
      lo.values = SIMDE_SHUFFLE_VECTOR_(32, 8, a_.values, b_.values, 0, 2);
      hi.values = SIMDE_SHUFFLE_VECTOR_(32, 8, a_.values, b_.values, 1, 3);
      r_ = simde_uint32x2_to_private(simde_vmin_u32(simde_uint32x2_from_private(lo), simde_uint32x2_from_private(hi)));
    #else
      const size_t halfway_point = sizeof(r_.values) / sizeof(r_.values[0]) / 2;
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < halfway_point ; i++) {
        const size_t idx = i << 1;
        r_.values[        i        ] = (a_.values[idx] < a_.values[idx + 1]) ? a_.values[idx] : a_.values[idx + 1];
        r_.values[i + halfway_point] = (b_.values[idx] < b_.values[idx + 1]) ? b_.values[idx] : b_.values[idx + 1];
      }
    #endif

    return simde_uint32x2_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vpmin_u32
  #define vpmin_u32(a, b) simde_vpmin_u32((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_float32x4_t
simde_vpminq_f32(simde_float32x4_t a, simde_float32x4_t b) {
  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
    return vpminq_f32(a, b);
  #else
    simde_float32x4_private
      r_,
      a_ = simde_float32x4_to_private(a),
      b_ = simde_float32x4_to_private(b);

    #if defined(SIMDE_SHUFFLE_VECTOR_)
      __typeof__(r_) lo, hi;
      lo.values = SIMDE_SHUFFLE_VECTOR_(32, 16, a_.values, b_.values, 0, 2, 4, 6);
      hi.values = SIMDE_SHUFFLE_VECTOR_(32, 16, a_.values, b_.values, 1, 3, 5, 7);
      r_ = simde_float32x4_to_private(simde_vminq_f32(simde_float32x4_from_private(lo), simde_float32x4_from_private(hi)));
    #else
      const size_t halfway_point = sizeof(r_.values) / sizeof(r_.values[0]) / 2;
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < halfway_point ; i++) {
        const size_t idx = i << 1;
        r_.values[        i        ] = (a_.values[idx] < a_.values[idx + 1]) ? a_.values[idx] : a_.values[idx + 1];
        r_.values[i + halfway_point] = (b_.values[idx] < b_.values[idx + 1]) ? b_.values[idx] : b_.values[idx + 1];
      }
    #endif

    return simde_float32x4_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vpminq_f32
  #define vpminq_f32(a, b) simde_vpminq_f32((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_float64x2_t
simde_vpminq_f64(simde_float64x2_t a, simde_float64x2_t b) {
  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
    return vpminq_f64(a, b);
  #else
    simde_float64x2_private
      r_,
      a_ = simde_float64x2_to_private(a),
      b_ = simde_float64x2_to_private(b);

    #if defined(SIMDE_SHUFFLE_VECTOR_)
      __typeof__(r_) lo, hi;
      lo.values = SIMDE_SHUFFLE_VECTOR_(64, 16, a_.values, b_.values, 0, 2);
      hi.values = SIMDE_SHUFFLE_VECTOR_(64, 16, a_.values, b_.values, 1, 3);
      r_ = simde_float64x2_to_private(simde_vminq_f64(simde_float64x2_from_private(lo), simde_float64x2_from_private(hi)));
    #else
      const size_t halfway_point = sizeof(r_.values) / sizeof(r_.values[0]) / 2;
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < halfway_point ; i++) {
        const size_t idx = i << 1;
        r_.values[        i        ] = (a_.values[idx] < a_.values[idx + 1]) ? a_.values[idx] : a_.values[idx + 1];
        r_.values[i + halfway_point] = (b_.values[idx] < b_.values[idx + 1]) ? b_.values[idx] : b_.values[idx + 1];
      }
    #endif

    return simde_float64x2_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES)
  #undef vpminq_f64
  #define vpminq_f64(a, b) simde_vpminq_f64((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_int8x16_t
simde_vpminq_s8(simde_int8x16_t a, simde_int8x16_t b) {
  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
    return vpminq_s8(a, b);
  #else
    simde_int8x16_private
      r_,
      a_ = simde_int8x16_to_private(a),
      b_ = simde_int8x16_to_private(b);

    #if defined(SIMDE_SHUFFLE_VECTOR_)
      __typeof__(r_) lo, hi;
      lo.values = SIMDE_SHUFFLE_VECTOR_(8, 16, a_.values, b_.values, 0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30);
      hi.values = SIMDE_SHUFFLE_VECTOR_(8, 16, a_.values, b_.values, 1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25, 27, 29, 31);
      r_ = simde_int8x16_to_private(simde_vminq_s8(simde_int8x16_from_private(lo), simde_int8x16_from_private(hi)));
    #else
      const size_t halfway_point = sizeof(r_.values) / sizeof(r_.values[0]) / 2;
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < halfway_point ; i++) {
        const size_t idx = i << 1;
        r_.values[        i        ] = (a_.values[idx] < a_.values[idx + 1]) ? a_.values[idx] : a_.values[idx + 1];
        r_.values[i + halfway_point] = (b_.values[idx] < b_.values[idx + 1]) ? b_.values[idx] : b_.values[idx + 1];
      }
    #endif

    return simde_int8x16_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vpminq_s8
  #define vpminq_s8(a, b) simde_vpminq_s8((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_int16x8_t
simde_vpminq_s16(simde_int16x8_t a, simde_int16x8_t b) {
  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
    return vpminq_s16(a, b);
  #else
    simde_int16x8_private
      r_,
      a_ = simde_int16x8_to_private(a),
      b_ = simde_int16x8_to_private(b);

    #if defined(SIMDE_SHUFFLE_VECTOR_)
      __typeof__(r_) lo, hi;
      lo.values = SIMDE_SHUFFLE_VECTOR_(16, 16, a_.values, b_.values, 0, 2, 4, 6, 8, 10, 12, 14);
      hi.values = SIMDE_SHUFFLE_VECTOR_(16, 16, a_.values, b_.values, 1, 3, 5, 7, 9, 11, 13, 15);
      r_ = simde_int16x8_to_private(simde_vminq_s16(simde_int16x8_from_private(lo), simde_int16x8_from_private(hi)));
    #else
      const size_t halfway_point = sizeof(r_.values) / sizeof(r_.values[0]) / 2;
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < halfway_point ; i++) {
        const size_t idx = i << 1;
        r_.values[        i        ] = (a_.values[idx] < a_.values[idx + 1]) ? a_.values[idx] : a_.values[idx + 1];
        r_.values[i + halfway_point] = (b_.values[idx] < b_.values[idx + 1]) ? b_.values[idx] : b_.values[idx + 1];
      }
    #endif

    return simde_int16x8_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vpminq_s16
  #define vpminq_s16(a, b) simde_vpminq_s16((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_int32x4_t
simde_vpminq_s32(simde_int32x4_t a, simde_int32x4_t b) {
  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
    return vpminq_s32(a, b);
  #else
    simde_int32x4_private
      r_,
      a_ = simde_int32x4_to_private(a),
      b_ = simde_int32x4_to_private(b);

    #if defined(SIMDE_SHUFFLE_VECTOR_)
      __typeof__(r_) lo, hi;
      lo.values = SIMDE_SHUFFLE_VECTOR_(32, 16, a_.values, b_.values, 0, 2, 4, 6);
      hi.values = SIMDE_SHUFFLE_VECTOR_(32, 16, a_.values, b_.values, 1, 3, 5, 7);
      r_ = simde_int32x4_to_private(simde_vminq_s32(simde_int32x4_from_private(lo), simde_int32x4_from_private(hi)));
    #else
      const size_t halfway_point = sizeof(r_.values) / sizeof(r_.values[0]) / 2;
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < halfway_point ; i++) {
        const size_t idx = i << 1;
        r_.values[        i        ] = (a_.values[idx] < a_.values[idx + 1]) ? a_.values[idx] : a_.values[idx + 1];
        r_.values[i + halfway_point] = (b_.values[idx] < b_.values[idx + 1]) ? b_.values[idx] : b_.values[idx + 1];
      }
    #endif

    return simde_int32x4_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vpminq_s32
  #define vpminq_s32(a, b) simde_vpminq_s32((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint8x16_t
simde_vpminq_u8(simde_uint8x16_t a, simde_uint8x16_t b) {
  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
    return vpminq_u8(a, b);
  #else
    simde_uint8x16_private
      r_,
      a_ = simde_uint8x16_to_private(a),
      b_ = simde_uint8x16_to_private(b);

    #if defined(SIMDE_SHUFFLE_VECTOR_)
      __typeof__(r_) lo, hi;
      lo.values = SIMDE_SHUFFLE_VECTOR_(8, 16, a_.values, b_.values, 0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30);
      hi.values = SIMDE_SHUFFLE_VECTOR_(8, 16, a_.values, b_.values, 1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25, 27, 29, 31);
      r_ = simde_uint8x16_to_private(simde_vminq_u8(simde_uint8x16_from_private(lo), simde_uint8x16_from_private(hi)));
    #else
      const size_t halfway_point = sizeof(r_.values) / sizeof(r_.values[0]) / 2;
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < halfway_point ; i++) {
        const size_t idx = i << 1;
        r_.values[        i        ] = (a_.values[idx] < a_.values[idx + 1]) ? a_.values[idx] : a_.values[idx + 1];
        r_.values[i + halfway_point] = (b_.values[idx] < b_.values[idx + 1]) ? b_.values[idx] : b_.values[idx + 1];
      }
    #endif

    return simde_uint8x16_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vpminq_u8
  #define vpminq_u8(a, b) simde_vpminq_u8((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint16x8_t
simde_vpminq_u16(simde_uint16x8_t a, simde_uint16x8_t b) {
  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
    return vpminq_u16(a, b);
  #else
    simde_uint16x8_private
      r_,
      a_ = simde_uint16x8_to_private(a),
      b_ = simde_uint16x8_to_private(b);

    #if defined(SIMDE_SHUFFLE_VECTOR_)
      __typeof__(r_) lo, hi;
      lo.values = SIMDE_SHUFFLE_VECTOR_(16, 16, a_.values, b_.values, 0, 2, 4, 6, 8, 10, 12, 14);
      hi.values = SIMDE_SHUFFLE_VECTOR_(16, 16, a_.values, b_.values, 1, 3, 5, 7, 9, 11, 13, 15);
      r_ = simde_uint16x8_to_private(simde_vminq_u16(simde_uint16x8_from_private(lo), simde_uint16x8_from_private(hi)));
    #else
      const size_t halfway_point = sizeof(r_.values) / sizeof(r_.values[0]) / 2;
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < halfway_point ; i++) {
        const size_t idx = i << 1;
        r_.values[        i        ] = (a_.values[idx] < a_.values[idx + 1]) ? a_.values[idx] : a_.values[idx + 1];
        r_.values[i + halfway_point] = (b_.values[idx] < b_.values[idx + 1]) ? b_.values[idx] : b_.values[idx + 1];
      }
    #endif

    return simde_uint16x8_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vpminq_u16
  #define vpminq_u16(a, b) simde_vpminq_u16((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint32x4_t
simde_vpminq_u32(simde_uint32x4_t a, simde_uint32x4_t b) {
  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
    return vpminq_u32(a, b);
  #else
    simde_uint32x4_private
      r_,
      a_ = simde_uint32x4_to_private(a),
      b_ = simde_uint32x4_to_private(b);

    #if defined(SIMDE_SHUFFLE_VECTOR_)
      __typeof__(r_) lo, hi;
      lo.values = SIMDE_SHUFFLE_VECTOR_(32, 16, a_.values, b_.values, 0, 2, 4, 6);
      hi.values = SIMDE_SHUFFLE_VECTOR_(32, 16, a_.values, b_.values, 1, 3, 5, 7);
      r_ = simde_uint32x4_to_private(simde_vminq_u32(simde_uint32x4_from_private(lo), simde_uint32x4_from_private(hi)));
    #else
      const size_t halfway_point = sizeof(r_.values) / sizeof(r_.values[0]) / 2;
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < halfway_point ; i++) {
        const size_t idx = i << 1;
        r_.values[        i        ] = (a_.values[idx] < a_.values[idx + 1]) ? a_.values[idx] : a_.values[idx + 1];
        r_.values[i + halfway_point] = (b_.values[idx] < b_.values[idx + 1]) ? b_.values[idx] : b_.values[idx + 1];
      }
    #endif

    return simde_uint32x4_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vpminq_u32
  #define vpminq_u32(a, b) simde_vpminq_u32((a), (b))
#endif

SIMDE_END_DECLS_
HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_ARM_NEON_PMIN_H) */
