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
 *   2020      Sean Maher <seanptmaher@gmail.com>
 */

#if !defined(SIMDE_ARM_NEON_PADD_H)
#define SIMDE_ARM_NEON_PADD_H

#include "types.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

SIMDE_FUNCTION_ATTRIBUTES
simde_float32x2_t
simde_vpadd_f32(simde_float32x2_t a, simde_float32x2_t b) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vpadd_f32(a, b);
  #else
    simde_float32x2_private
      r_,
      a_ = simde_float32x2_to_private(a),
      b_ = simde_float32x2_to_private(b);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) / 2 ; i += 1) {
      r_.values[i] = a_.values[(i * 2)] + a_.values[(i * 2) + 1];
    }
    SIMDE_VECTORIZE
    for (size_t i = 0; i < (sizeof(r_.values) / sizeof(r_.values[0])) / 2 ; i += 1) {
      r_.values[((sizeof(r_.values) / sizeof(r_.values[0])) / 2) + i] = b_.values[(i * 2)] + b_.values[(i * 2) + 1];
    }

    return simde_float32x2_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vpadd_f32
  #define vpadd_f32(a, b) simde_vpadd_f32((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_int8x8_t
simde_vpadd_s8(simde_int8x8_t a, simde_int8x8_t b) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vpadd_s8(a, b);
  #else
    simde_int8x8_private
      r_,
      a_ = simde_int8x8_to_private(a),
      b_ = simde_int8x8_to_private(b);


    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) / 2 ; i += 1) {
      r_.values[i] = a_.values[(i * 2)] + a_.values[(i * 2) + 1];
    }
    SIMDE_VECTORIZE
    for (size_t i = 0; i < (sizeof(r_.values) / sizeof(r_.values[0])) / 2 ; i += 1) {
      r_.values[((sizeof(r_.values) / sizeof(r_.values[0])) / 2) + i] = b_.values[(i * 2)] + b_.values[(i * 2) + 1];
    }

    return simde_int8x8_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vpadd_s8
  #define vpadd_s8(a, b) simde_vpadd_s8((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_int16x4_t
simde_vpadd_s16(simde_int16x4_t a, simde_int16x4_t b) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vpadd_s16(a, b);
  #else
    simde_int16x4_private
      r_,
      a_ = simde_int16x4_to_private(a),
      b_ = simde_int16x4_to_private(b);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) / 2 ; i += 1) {
      r_.values[i] = a_.values[(i * 2)] + a_.values[(i * 2) + 1];
    }
    SIMDE_VECTORIZE
    for (size_t i = 0; i < (sizeof(r_.values) / sizeof(r_.values[0])) / 2 ; i += 1) {
      r_.values[((sizeof(r_.values) / sizeof(r_.values[0])) / 2) + i] = b_.values[(i * 2)] + b_.values[(i * 2) + 1];
    }

    return simde_int16x4_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vpadd_s16
  #define vpadd_s16(a, b) simde_vpadd_s16((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_int32x2_t
simde_vpadd_s32(simde_int32x2_t a, simde_int32x2_t b) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vpadd_s32(a, b);
  #else
    simde_int32x2_private
      r_,
      a_ = simde_int32x2_to_private(a),
      b_ = simde_int32x2_to_private(b);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) / 2 ; i += 1) {
      r_.values[i] = a_.values[(i * 2)] + a_.values[(i * 2) + 1];
    }
    SIMDE_VECTORIZE
    for (size_t i = 0; i < (sizeof(r_.values) / sizeof(r_.values[0])) / 2 ; i += 1) {
      r_.values[((sizeof(r_.values) / sizeof(r_.values[0])) / 2) + i] = b_.values[(i * 2)] + b_.values[(i * 2) + 1];
    }

    return simde_int32x2_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vpadd_s32
  #define vpadd_s32(a, b) simde_vpadd_s32((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint8x8_t
simde_vpadd_u8(simde_uint8x8_t a, simde_uint8x8_t b) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vpadd_u8(a, b);
  #else
    simde_uint8x8_private
      r_,
      a_ = simde_uint8x8_to_private(a),
      b_ = simde_uint8x8_to_private(b);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) / 2 ; i += 1) {
      r_.values[i] = a_.values[(i * 2)] + a_.values[(i * 2) + 1];
    }
    SIMDE_VECTORIZE
    for (size_t i = 0; i < (sizeof(r_.values) / sizeof(r_.values[0])) / 2 ; i += 1) {
      r_.values[((sizeof(r_.values) / sizeof(r_.values[0])) / 2) + i] = b_.values[(i * 2)] + b_.values[(i * 2) + 1];
    }

    return simde_uint8x8_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vpadd_u8
  #define vpadd_u8(a, b) simde_vpadd_u8((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint16x4_t
simde_vpadd_u16(simde_uint16x4_t a, simde_uint16x4_t b) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vpadd_u16(a, b);
  #else
    simde_uint16x4_private
      r_,
      a_ = simde_uint16x4_to_private(a),
      b_ = simde_uint16x4_to_private(b);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) / 2 ; i += 1) {
      r_.values[i] = a_.values[(i * 2)] + a_.values[(i * 2) + 1];
    }
    SIMDE_VECTORIZE
    for (size_t i = 0; i < (sizeof(r_.values) / sizeof(r_.values[0])) / 2 ; i += 1) {
      r_.values[((sizeof(r_.values) / sizeof(r_.values[0])) / 2) + i] = b_.values[(i * 2)] + b_.values[(i * 2) + 1];
    }

    return simde_uint16x4_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vpadd_u16
  #define vpadd_u16(a, b) simde_vpadd_u16((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint32x2_t
simde_vpadd_u32(simde_uint32x2_t a, simde_uint32x2_t b) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vpadd_u32(a, b);
  #else
    simde_uint32x2_private
      r_,
      a_ = simde_uint32x2_to_private(a),
      b_ = simde_uint32x2_to_private(b);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) / 2 ; i += 1) {
      r_.values[i] = a_.values[(i * 2)] + a_.values[(i * 2) + 1];
    }
    SIMDE_VECTORIZE
    for (size_t i = 0; i < (sizeof(r_.values) / sizeof(r_.values[0])) / 2 ; i += 1) {
      r_.values[((sizeof(r_.values) / sizeof(r_.values[0])) / 2) + i] = b_.values[(i * 2)] + b_.values[(i * 2) + 1];
    }

    return simde_uint32x2_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vpadd_u32
  #define vpadd_u32(a, b) simde_vpadd_u32((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_float32x4_t
simde_vpaddq_f32(simde_float32x4_t a, simde_float32x4_t b) {
  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
    return vpaddq_f32(a, b);
  #elif defined(SIMDE_WASM_SIMD128_NATIVE)
    return wasm_f32x4_add(wasm_i8x16_shuffle(a, b,
                                             0, 1, 2, 3, 8, 9, 10, 11, 16, 17, 18, 19, 24, 25, 26, 27),
                          wasm_i8x16_shuffle(a, b,
                                             4, 5, 6, 7, 12, 13, 14, 15, 20, 21, 22, 23, 28, 29, 30, 31));
  #else
    simde_float32x4_private
      r_,
      a_ = simde_float32x4_to_private(a),
      b_ = simde_float32x4_to_private(b);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) / 2 ; i += 1) {
      r_.values[i] = a_.values[(i * 2)] + a_.values[(i * 2) + 1];
    }
    SIMDE_VECTORIZE
    for (size_t i = 0; i < (sizeof(r_.values) / sizeof(r_.values[0])) / 2 ; i += 1) {
      r_.values[((sizeof(r_.values) / sizeof(r_.values[0])) / 2) + i] = b_.values[(i * 2)] + b_.values[(i * 2) + 1];
    }

    return simde_float32x4_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vpaddq_f32
  #define vpaddq_f32(a, b) simde_vpaddq_f32((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_float64x2_t
simde_vpaddq_f64(simde_float64x2_t a, simde_float64x2_t b) {
  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
    return vpaddq_f64(a, b);
  #elif defined(SIMDE_WASM_SIMD128_NATIVE)
    return wasm_f64x2_add(wasm_i8x16_shuffle(a, b,
                                             0, 1, 2, 3, 4, 5, 6, 7, 16, 17, 18, 19, 20, 21, 22, 23),
                          wasm_i8x16_shuffle(a, b,
                                             8, 9, 10, 11, 12, 13, 14, 15, 24, 25, 26, 27, 28, 29, 30, 31));
  #else
    simde_float64x2_private
      r_,
      a_ = simde_float64x2_to_private(a),
      b_ = simde_float64x2_to_private(b);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) / 2 ; i += 1) {
      r_.values[i] = a_.values[(i * 2)] + a_.values[(i * 2) + 1];
    }
    SIMDE_VECTORIZE
    for (size_t i = 0; i < (sizeof(r_.values) / sizeof(r_.values[0])) / 2 ; i += 1) {
      r_.values[((sizeof(r_.values) / sizeof(r_.values[0])) / 2) + i] = b_.values[(i * 2)] + b_.values[(i * 2) + 1];
    }

    return simde_float64x2_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES)
  #undef vpaddq_f64
  #define vpaddq_f64(a, b) simde_vpaddq_f64((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_int8x16_t
simde_vpaddq_s8(simde_int8x16_t a, simde_int8x16_t b) {
  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
    return vpaddq_s8(a, b);
  #elif defined(SIMDE_WASM_SIMD128_NATIVE)
    return wasm_i8x16_add(wasm_i8x16_shuffle(a, b,
                                             0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30),
                          wasm_i8x16_shuffle(a, b,
                                             1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25, 27, 29, 31));
  #else
    simde_int8x16_private
      r_,
      a_ = simde_int8x16_to_private(a),
      b_ = simde_int8x16_to_private(b);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) / 2 ; i += 1) {
      r_.values[i] = a_.values[(i * 2)] + a_.values[(i * 2) + 1];
    }
    SIMDE_VECTORIZE
    for (size_t i = 0; i < (sizeof(r_.values) / sizeof(r_.values[0])) / 2 ; i += 1) {
      r_.values[((sizeof(r_.values) / sizeof(r_.values[0])) / 2) + i] = b_.values[(i * 2)] + b_.values[(i * 2) + 1];
    }

    return simde_int8x16_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vpaddq_s8
  #define vpaddq_s8(a, b) simde_vpaddq_s8((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_int16x8_t
simde_vpaddq_s16(simde_int16x8_t a, simde_int16x8_t b) {
  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
    return vpaddq_s16(a, b);
  #elif defined(SIMDE_WASM_SIMD128_NATIVE)
    return wasm_i16x8_add(wasm_i8x16_shuffle(a, b,
                                             0, 1, 4, 5, 8, 9, 12, 13, 16, 17, 20, 21, 24, 25, 28, 29),
                          wasm_i8x16_shuffle(a, b,
                                             2, 3, 6, 7, 10, 11, 14, 15, 17, 19, 22, 23, 26, 27, 30, 31));
  #else
    simde_int16x8_private
      r_,
      a_ = simde_int16x8_to_private(a),
      b_ = simde_int16x8_to_private(b);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) / 2 ; i += 1) {
      r_.values[i] = a_.values[(i * 2)] + a_.values[(i * 2) + 1];
    }
    SIMDE_VECTORIZE
    for (size_t i = 0; i < (sizeof(r_.values) / sizeof(r_.values[0])) / 2 ; i += 1) {
      r_.values[((sizeof(r_.values) / sizeof(r_.values[0])) / 2) + i] = b_.values[(i * 2)] + b_.values[(i * 2) + 1];
    }

    return simde_int16x8_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vpaddq_s16
  #define vpaddq_s16(a, b) simde_vpaddq_s16((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_int32x4_t
simde_vpaddq_s32(simde_int32x4_t a, simde_int32x4_t b) {
  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
    return vpaddq_s32(a, b);
  #elif defined(SIMDE_WASM_SIMD128_NATIVE)
    return wasm_i32x4_add(wasm_i8x16_shuffle(a, b,
                                             0, 1, 2, 3, 8, 9, 10, 11, 16, 17, 18, 19, 24, 25, 26, 27),
                          wasm_i8x16_shuffle(a, b,
                                             4, 5, 6, 7, 12, 13, 14, 15, 20, 21, 22, 23, 28, 29, 30, 31));
  #else
    simde_int32x4_private
      r_,
      a_ = simde_int32x4_to_private(a),
      b_ = simde_int32x4_to_private(b);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) / 2 ; i += 1) {
      r_.values[i] = a_.values[(i * 2)] + a_.values[(i * 2) + 1];
    }
    SIMDE_VECTORIZE
    for (size_t i = 0; i < (sizeof(r_.values) / sizeof(r_.values[0])) / 2 ; i += 1) {
      r_.values[((sizeof(r_.values) / sizeof(r_.values[0])) / 2) + i] = b_.values[(i * 2)] + b_.values[(i * 2) + 1];
    }

    return simde_int32x4_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vpaddq_s32
  #define vpaddq_s32(a, b) simde_vpaddq_s32((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_int64x2_t
simde_vpaddq_s64(simde_int64x2_t a, simde_int64x2_t b) {
  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
    return vpaddq_s64(a, b);
  #elif defined(SIMDE_WASM_SIMD128_NATIVE)
    return wasm_i64x2_add(wasm_i8x16_shuffle(a, b,
                                             0, 1, 2, 3, 4, 5, 6, 7, 16, 17, 18, 19, 20, 21, 22, 23),
                          wasm_i8x16_shuffle(a, b,
                                             8, 9, 10, 11, 12, 13, 14, 15, 24, 25, 26, 27, 28, 29, 30, 31));
  #else
    simde_int64x2_private
      r_,
      a_ = simde_int64x2_to_private(a),
      b_ = simde_int64x2_to_private(b);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) / 2 ; i += 1) {
      r_.values[i] = a_.values[(i * 2)] + a_.values[(i * 2) + 1];
    }
    SIMDE_VECTORIZE
    for (size_t i = 0; i < (sizeof(r_.values) / sizeof(r_.values[0])) / 2 ; i += 1) {
      r_.values[((sizeof(r_.values) / sizeof(r_.values[0])) / 2) + i] = b_.values[(i * 2)] + b_.values[(i * 2) + 1];
    }

    return simde_int64x2_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vpaddq_s64
  #define vpaddq_s64(a, b) simde_vpaddq_s64((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint8x16_t
simde_vpaddq_u8(simde_uint8x16_t a, simde_uint8x16_t b) {
  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
    return vpaddq_u8(a, b);
  #elif defined(SIMDE_WASM_SIMD128_NATIVE)
    return wasm_i8x16_add(wasm_i8x16_shuffle(a, b,
                                             0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30),
                          wasm_i8x16_shuffle(a, b,
                                             1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25, 27, 29, 31));
  #else
    simde_uint8x16_private
      r_,
      a_ = simde_uint8x16_to_private(a),
      b_ = simde_uint8x16_to_private(b);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) / 2 ; i += 1) {
      r_.values[i] = a_.values[(i * 2)] + a_.values[(i * 2) + 1];
    }
    SIMDE_VECTORIZE
    for (size_t i = 0; i < (sizeof(r_.values) / sizeof(r_.values[0])) / 2 ; i += 1) {
      r_.values[((sizeof(r_.values) / sizeof(r_.values[0])) / 2) + i] = b_.values[(i * 2)] + b_.values[(i * 2) + 1];
    }

    return simde_uint8x16_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vpaddq_u8
  #define vpaddq_u8(a, b) simde_vpaddq_u8((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint16x8_t
simde_vpaddq_u16(simde_uint16x8_t a, simde_uint16x8_t b) {
  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
    return vpaddq_u16(a, b);
  #elif defined(SIMDE_WASM_SIMD128_NATIVE)
    return wasm_i16x8_add(wasm_i8x16_shuffle(a, b,
                                             0, 1, 4, 5, 8, 9, 12, 13, 16, 17, 20, 21, 24, 25, 28, 29),
                          wasm_i8x16_shuffle(a, b,
                                             2, 3, 6, 7, 10, 11, 14, 15, 17, 19, 22, 23, 26, 27, 30, 31));
  #else
    simde_uint16x8_private
      r_,
      a_ = simde_uint16x8_to_private(a),
      b_ = simde_uint16x8_to_private(b);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) / 2 ; i += 1) {
      r_.values[i] = a_.values[(i * 2)] + a_.values[(i * 2) + 1];
    }
    SIMDE_VECTORIZE
    for (size_t i = 0; i < (sizeof(r_.values) / sizeof(r_.values[0])) / 2 ; i += 1) {
      r_.values[((sizeof(r_.values) / sizeof(r_.values[0])) / 2) + i] = b_.values[(i * 2)] + b_.values[(i * 2) + 1];
    }

    return simde_uint16x8_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vpaddq_u16
  #define vpaddq_u16(a, b) simde_vpaddq_u16((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint32x4_t
simde_vpaddq_u32(simde_uint32x4_t a, simde_uint32x4_t b) {
  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
    return vpaddq_u32(a, b);
  #elif defined(SIMDE_WASM_SIMD128_NATIVE)
    return wasm_i32x4_add(wasm_i8x16_shuffle(a, b,
                                             0, 1, 2, 3, 8, 9, 10, 11, 16, 17, 18, 19, 24, 25, 26, 27),
                          wasm_i8x16_shuffle(a, b,
                                             4, 5, 6, 7, 12, 13, 14, 15, 20, 21, 22, 23, 28, 29, 30, 31));
  #else
    simde_uint32x4_private
      r_,
      a_ = simde_uint32x4_to_private(a),
      b_ = simde_uint32x4_to_private(b);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) / 2 ; i += 1) {
      r_.values[i] = a_.values[(i * 2)] + a_.values[(i * 2) + 1];
    }
    SIMDE_VECTORIZE
    for (size_t i = 0; i < (sizeof(r_.values) / sizeof(r_.values[0])) / 2 ; i += 1) {
      r_.values[((sizeof(r_.values) / sizeof(r_.values[0])) / 2) + i] = b_.values[(i * 2)] + b_.values[(i * 2) + 1];
    }

    return simde_uint32x4_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vpaddq_u32
  #define vpaddq_u32(a, b) simde_vpaddq_u32((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint64x2_t
simde_vpaddq_u64(simde_uint64x2_t a, simde_uint64x2_t b) {
  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
    return vpaddq_u64(a, b);
  #elif defined(SIMDE_WASM_SIMD128_NATIVE)
    return wasm_i64x2_add(wasm_i8x16_shuffle(a, b,
                                             0, 1, 2, 3, 4, 5, 6, 7, 16, 17, 18, 19, 20, 21, 22, 23),
                          wasm_i8x16_shuffle(a, b,
                                             8, 9, 10, 11, 12, 13, 14, 15, 24, 25, 26, 27, 28, 29, 30, 31));
  #else
    simde_uint64x2_private
      r_,
      a_ = simde_uint64x2_to_private(a),
      b_ = simde_uint64x2_to_private(b);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) / 2 ; i += 1) {
      r_.values[i] = a_.values[(i * 2)] + a_.values[(i * 2) + 1];
    }
    SIMDE_VECTORIZE
    for (size_t i = 0; i < (sizeof(r_.values) / sizeof(r_.values[0])) / 2 ; i += 1) {
      r_.values[((sizeof(r_.values) / sizeof(r_.values[0])) / 2) + i] = b_.values[(i * 2)] + b_.values[(i * 2) + 1];
    }

    return simde_uint64x2_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vpaddq_u64
  #define vpaddq_u64(a, b) simde_vpaddq_u64((a), (b))
#endif

SIMDE_END_DECLS_
HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_ARM_NEON_PADD_H) */
