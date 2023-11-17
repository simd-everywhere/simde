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
 *   2020      Sean Maher <seanptmaher@gmail.com>
 *   2020-2021 Evan Nemerson <evan@nemerson.com>
 *   2023      Yi-Yen Chung <eric681@andestech.com> (Copyright owned by Andes Technology)
 */

#if !defined(SIMDE_ARM_NEON_CVT_H)
#define SIMDE_ARM_NEON_CVT_H

#include "types.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

SIMDE_FUNCTION_ATTRIBUTES
simde_float16x4_t
simde_vcvt_f16_f32(simde_float32x4_t a) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE) && defined(SIMDE_ARM_NEON_FP16)
    return vcvt_f16_f32(a);
  #else
    simde_float32x4_private a_ = simde_float32x4_to_private(a);
    simde_float16x4_private r_;

    #if defined(SIMDE_CONVERT_VECTOR_) && defined(SIMDE_FLOAT16_VECTOR)
      SIMDE_CONVERT_VECTOR_(r_.values, a_.values);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
        r_.values[i] = simde_float16_from_float32(a_.values[i]);
      }
    #endif

    return simde_float16x4_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES)
  #undef vcvt_f16_f32
  #define vcvt_f16_f32(a) simde_vcvt_f16_f32(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_float32x4_t
simde_vcvt_f32_f16(simde_float16x4_t a) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE) && defined(SIMDE_ARM_NEON_FP16)
    return vcvt_f32_f16(a);
  #else
    simde_float16x4_private a_ = simde_float16x4_to_private(a);
    simde_float32x4_private r_;

    #if defined(SIMDE_CONVERT_VECTOR_) && defined(SIMDE_FLOAT16_VECTOR)
      SIMDE_CONVERT_VECTOR_(r_.values, a_.values);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
        r_.values[i] = simde_float16_to_float32(a_.values[i]);
      }
    #endif

    return simde_float32x4_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES)
  #undef vcvt_f32_f16
  #define vcvt_f32_f16(a) simde_vcvt_f32_f16(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_float32x2_t
simde_vcvt_f32_f64(simde_float64x2_t a) {
  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
    return vcvt_f32_f64(a);
  #else
    simde_float64x2_private a_ = simde_float64x2_to_private(a);
    simde_float32x2_private r_;

    #if defined(SIMDE_CONVERT_VECTOR_)
      SIMDE_CONVERT_VECTOR_(r_.values, a_.values);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
        r_.values[i] = HEDLEY_STATIC_CAST(simde_float32, a_.values[i]);
      }
    #endif

    return simde_float32x2_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES)
  #undef vcvt_f32_f64
  #define vcvt_f32_f64(a) simde_vcvt_f32_f64(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_float64x2_t
simde_vcvt_f64_f32(simde_float32x2_t a) {
  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
    return vcvt_f64_f32(a);
  #else
    simde_float32x2_private a_ = simde_float32x2_to_private(a);
    simde_float64x2_private r_;

    #if defined(SIMDE_CONVERT_VECTOR_)
      SIMDE_CONVERT_VECTOR_(r_.values, a_.values);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
        r_.values[i] = HEDLEY_STATIC_CAST(simde_float64, a_.values[i]);
      }
    #endif

    return simde_float64x2_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES)
  #undef vcvt_f64_f32
  #define vcvt_f64_f32(a) simde_vcvt_f64_f32(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
int16_t
simde_vcvth_s16_f16(simde_float16_t a) {
  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE) && defined(SIMDE_ARM_NEON_FP16)
    return vcvth_s16_f16(a);
  #elif defined(SIMDE_FAST_CONVERSION_RANGE)
    return HEDLEY_STATIC_CAST(int16_t,
        simde_float16_to_float32(a));
  #else
    simde_float32 af = simde_float16_to_float32(a);
    if (HEDLEY_UNLIKELY(af <= HEDLEY_STATIC_CAST(simde_float32, INT16_MIN))) {
      return INT16_MIN;
    } else if (HEDLEY_UNLIKELY(af >= HEDLEY_STATIC_CAST(simde_float32, INT16_MAX))) {
      return INT16_MAX;
    } else if (HEDLEY_UNLIKELY(simde_isnanhf(a))) {
      return 0;
    } else {
      return HEDLEY_STATIC_CAST(int16_t, af);
    }
  #endif
}
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES)
  #undef vcvth_s16_f16
  #define vcvth_s16_f16(a) simde_vcvth_s16_f16(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
uint16_t
simde_vcvth_u16_f16(simde_float16_t a) {
  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE) && defined(SIMDE_ARM_NEON_FP16)
    return vcvth_u16_f16(a);
  #elif defined(SIMDE_FAST_CONVERSION_RANGE)
    return HEDLEY_STATIC_CAST(uint16_t,
        simde_float16_to_float32(a));
  #else
    simde_float32 af = simde_float16_to_float32(a);
    if (HEDLEY_UNLIKELY(af <= SIMDE_FLOAT32_C(0.0))) {
      return 0;
    } else if (HEDLEY_UNLIKELY(af >= HEDLEY_STATIC_CAST(simde_float32, UINT16_MAX))) {
      return UINT16_MAX;
    } else if (simde_isnanhf(a)) {
      return 0;
    } else {
      return HEDLEY_STATIC_CAST(uint16_t, af);
    }
  #endif
}
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES)
  #undef vcvth_u16_f16
  #define vcvth_u16_f16(a) simde_vcvth_u16_f16(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
int32_t
simde_vcvth_s32_f16(simde_float16_t a) {
  #if defined(SIMDE_ARM_NEON_A32V8_NATIVE) && defined(SIMDE_ARM_NEON_FP16)
    return vcvth_s32_f16(a);
  #elif defined(SIMDE_FAST_CONVERSION_RANGE)
    return HEDLEY_STATIC_CAST(int32_t,
        simde_float16_to_float32(a));
  #else
    simde_float32 af = simde_float16_to_float32(a);
    if (HEDLEY_UNLIKELY(af <= HEDLEY_STATIC_CAST(simde_float32, INT32_MIN))) {
      return INT32_MIN;
    } else if (HEDLEY_UNLIKELY(af >= HEDLEY_STATIC_CAST(simde_float32, INT32_MAX))) {
      return INT32_MAX;
    } else if (HEDLEY_UNLIKELY(simde_isnanhf(a))) {
      return 0;
    } else {
      return HEDLEY_STATIC_CAST(int32_t, af);
    }
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V8_ENABLE_NATIVE_ALIASES)
  #undef vcvth_s32_f16
  #define vcvth_s32_f16(a) simde_vcvth_s32_f16(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
uint32_t
simde_vcvth_u32_f16(simde_float16_t a) {
  #if defined(SIMDE_ARM_NEON_A32V8_NATIVE) && defined(SIMDE_ARM_NEON_FP16)
    return vcvth_u32_f16(a);
  #elif defined(SIMDE_FAST_CONVERSION_RANGE)
    return HEDLEY_STATIC_CAST(uint32_t,
        simde_float16_to_float32(a));
  #else
    simde_float32 af = simde_float16_to_float32(a);
    if (HEDLEY_UNLIKELY(af <= SIMDE_FLOAT32_C(0.0))) {
      return 0;
    } else if (HEDLEY_UNLIKELY(af >= HEDLEY_STATIC_CAST(simde_float32, UINT32_MAX))) {
      return UINT32_MAX;
    } else if (HEDLEY_UNLIKELY(simde_isnanhf(a))) {
      return 0;
    } else {
      return HEDLEY_STATIC_CAST(uint32_t, af);
    }
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V8_ENABLE_NATIVE_ALIASES)
  #undef vcvth_u32_f16
  #define vcvth_u32_f16(a) simde_vcvth_u32_f16(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
int64_t
simde_vcvth_s64_f16(simde_float16_t a) {
  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE) && defined(SIMDE_ARM_NEON_FP16)
    return vcvth_s64_f16(a);
  #elif defined(SIMDE_FAST_CONVERSION_RANGE)
    return HEDLEY_STATIC_CAST(int64_t,
        simde_float16_to_float32(a));
  #else
    simde_float32 af = simde_float16_to_float32(a);
    if (HEDLEY_UNLIKELY(af <= HEDLEY_STATIC_CAST(simde_float32, INT64_MIN))) {
      return INT64_MIN;
    } else if (HEDLEY_UNLIKELY(af >= HEDLEY_STATIC_CAST(simde_float32, INT64_MAX))) {
      return INT64_MAX;
    } else if (HEDLEY_UNLIKELY(simde_isnanhf(a))) {
      return 0;
    } else {
      return HEDLEY_STATIC_CAST(int64_t, af);
    }
  #endif
}
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES)
  #undef vcvth_s64_f16
  #define vcvth_s64_f16(a) simde_vcvth_s64_f16(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
uint64_t
simde_vcvth_u64_f16(simde_float16_t a) {
  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE) && defined(SIMDE_ARM_NEON_FP16)
    return vcvth_u64_f16(a);
  #elif defined(SIMDE_FAST_CONVERSION_RANGE)
    return HEDLEY_STATIC_CAST(uint64_t,
        simde_float16_to_float32(a));
  #else
    simde_float32 af = simde_float16_to_float32(a);
    if (HEDLEY_UNLIKELY(af <= SIMDE_FLOAT32_C(0.0))) {
      return 0;
    } else if (HEDLEY_UNLIKELY(af >= HEDLEY_STATIC_CAST(simde_float32, UINT64_MAX))) {
      return UINT64_MAX;
    } else if (HEDLEY_UNLIKELY(simde_isnanhf(a))) {
      return 0;
    } else {
      return HEDLEY_STATIC_CAST(uint64_t, af);
    }
  #endif
}
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES)
  #undef vcvth_u64_f16
  #define vcvth_u64_f16(a) simde_vcvth_u64_f16(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
int32_t
simde_vcvts_s32_f32(simde_float32 a) {
  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
    return vcvts_s32_f32(a);
  #elif defined(SIMDE_FAST_CONVERSION_RANGE)
    return HEDLEY_STATIC_CAST(int32_t, a);
  #else
    if (HEDLEY_UNLIKELY(a < HEDLEY_STATIC_CAST(simde_float32, INT32_MIN))) {
      return INT32_MIN;
    } else if (HEDLEY_UNLIKELY(a > HEDLEY_STATIC_CAST(simde_float32, INT32_MAX))) {
      return INT32_MAX;
    } else if (HEDLEY_UNLIKELY(simde_math_isnanf(a))) {
      return 0;
    } else {
      return HEDLEY_STATIC_CAST(int32_t, a);
    }
  #endif
}
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES)
  #undef vcvts_s32_f32
  #define vcvts_s32_f32(a) simde_vcvts_s32_f32(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
uint32_t
simde_vcvts_u32_f32(simde_float32 a) {
  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE) && !defined(SIMDE_BUG_CLANG_46844)
    return vcvts_u32_f32(a);
  #elif defined(SIMDE_FAST_CONVERSION_RANGE)
    return HEDLEY_STATIC_CAST(uint32_t, a);
  #else
    if (HEDLEY_UNLIKELY(a < SIMDE_FLOAT32_C(0.0))) {
      return 0;
    } else if (HEDLEY_UNLIKELY(a > HEDLEY_STATIC_CAST(simde_float32, UINT32_MAX))) {
      return UINT32_MAX;
    } else if (simde_math_isnanf(a)) {
      return 0;
    } else {
      return HEDLEY_STATIC_CAST(uint32_t, a);
    }
  #endif
}
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES)
  #undef vcvts_u32_f32
  #define vcvts_u32_f32(a) simde_vcvts_u32_f32(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_float32
simde_vcvts_f32_s32(int32_t a) {
  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
    return vcvts_f32_s32(a);
  #else
    return HEDLEY_STATIC_CAST(simde_float32, a);
  #endif
}
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES)
  #undef vcvts_f32_s32
  #define vcvts_f32_s32(a) simde_vcvts_f32_s32(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_float32
simde_vcvts_f32_u32 (uint32_t a) {
  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE) && !defined(SIMDE_BUG_CLANG_46844)
    return vcvts_f32_u32(a);
  #else
    return HEDLEY_STATIC_CAST(simde_float32, a);
  #endif
}
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES)
  #undef vcvts_f32_u32
  #define vcvts_f32_u32(a) simde_vcvts_f32_u32(a)
#endif


SIMDE_FUNCTION_ATTRIBUTES
int64_t
simde_vcvtd_s64_f64(simde_float64 a) {
  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
    return vcvtd_s64_f64(a);
  #elif defined(SIMDE_FAST_CONVERSION_RANGE)
    return HEDLEY_STATIC_CAST(int64_t, a);
  #else
    if (HEDLEY_UNLIKELY(a < HEDLEY_STATIC_CAST(simde_float64, INT64_MIN))) {
      return INT64_MIN;
    } else if (HEDLEY_UNLIKELY(a > HEDLEY_STATIC_CAST(simde_float64, INT64_MAX))) {
      return INT64_MAX;
    } else if (simde_math_isnan(a)) {
      return 0;
    } else {
      return HEDLEY_STATIC_CAST(int64_t, a);
    }
  #endif
}
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES)
  #undef vcvtd_s64_f64
  #define vcvtd_s64_f64(a) simde_vcvtd_s64_f64(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
uint64_t
simde_vcvtd_u64_f64(simde_float64 a) {
  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE) && !defined(SIMDE_BUG_CLANG_46844)
    return vcvtd_u64_f64(a);
  #elif defined(SIMDE_FAST_CONVERSION_RANGE)
    return HEDLEY_STATIC_CAST(uint64_t, a);
  #else
    if (HEDLEY_UNLIKELY(a < SIMDE_FLOAT64_C(0.0))) {
      return 0;
    } else if (HEDLEY_UNLIKELY(a > HEDLEY_STATIC_CAST(simde_float64, UINT64_MAX))) {
      return UINT64_MAX;
    } else if (simde_math_isnan(a)) {
      return 0;
    } else {
      return HEDLEY_STATIC_CAST(uint64_t, a);
    }
  #endif
}
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES)
  #undef vcvtd_u64_f64
  #define vcvtd_u64_f64(a) simde_vcvtd_u64_f64(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_float64
simde_vcvtd_f64_s64(int64_t a) {
  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
    return vcvtd_f64_s64(a);
  #else
    return HEDLEY_STATIC_CAST(simde_float64, a);
  #endif
}
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES)
  #undef vcvtd_f64_s64
  #define vcvtd_f64_s64(a) simde_vcvtd_f64_s64(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_float64
simde_vcvtd_f64_u64(uint64_t a) {
  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE) && !defined(SIMDE_BUG_CLANG_46844)
    return vcvtd_f64_u64(a);
  #else
    return HEDLEY_STATIC_CAST(simde_float64, a);
  #endif
}
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES)
  #undef vcvtd_f64_u64
  #define vcvtd_f64_u64(a) simde_vcvtd_f64_u64(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_float16_t
simde_vcvth_f16_u32(uint32_t a) {
  #if defined(SIMDE_ARM_NEON_A32V8_NATIVE) && defined(SIMDE_ARM_NEON_FP16)
    return vcvth_f16_u32(a);
  #elif SIMDE_FLOAT16_API != SIMDE_FLOAT16_API_PORTABLE && SIMDE_FLOAT16_API != SIMDE_FLOAT16_API_FP16_NO_ABI
    return HEDLEY_STATIC_CAST(simde_float16_t, a);
  #else
    return simde_float16_from_float32(HEDLEY_STATIC_CAST(simde_float32_t, a));
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V8_ENABLE_NATIVE_ALIASES)
  #undef vcvth_f16_u32
  #define vcvth_f16_u32(a) simde_vcvth_f16_u32(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_float16_t
simde_vcvth_f16_u64(uint64_t a) {
  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE) && defined(SIMDE_ARM_NEON_FP16)
    return vcvth_f16_u64(a);
  #elif SIMDE_FLOAT16_API != SIMDE_FLOAT16_API_PORTABLE && SIMDE_FLOAT16_API != SIMDE_FLOAT16_API_FP16_NO_ABI
    return HEDLEY_STATIC_CAST(simde_float16_t, a);
  #else
    return simde_float16_from_float32(HEDLEY_STATIC_CAST(simde_float32_t, a));
  #endif
}
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES)
  #undef vcvth_f16_u64
  #define vcvth_f16_u64(a) simde_vcvth_f16_u64(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_float16_t
simde_vcvth_f16_s32(int32_t a) {
  #if defined(SIMDE_ARM_NEON_A32V8_NATIVE) && defined(SIMDE_ARM_NEON_FP16)
    return vcvth_f16_s32(a);
  #elif SIMDE_FLOAT16_API != SIMDE_FLOAT16_API_PORTABLE && SIMDE_FLOAT16_API != SIMDE_FLOAT16_API_FP16_NO_ABI
    return HEDLEY_STATIC_CAST(simde_float16_t, a);
  #else
    return simde_float16_from_float32(HEDLEY_STATIC_CAST(simde_float32_t, a));
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V8_ENABLE_NATIVE_ALIASES)
  #undef vcvth_f16_s32
  #define vcvth_f16_s32(a) simde_vcvth_f16_s32(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_float16_t
simde_vcvth_f16_s64(int64_t a) {
  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE) && defined(SIMDE_ARM_NEON_FP16)
    return vcvth_f16_s64(a);
  #elif SIMDE_FLOAT16_API != SIMDE_FLOAT16_API_PORTABLE && SIMDE_FLOAT16_API != SIMDE_FLOAT16_API_FP16_NO_ABI
    return HEDLEY_STATIC_CAST(simde_float16_t, a);
  #else
    return simde_float16_from_float32(HEDLEY_STATIC_CAST(simde_float32_t, a));
  #endif
}
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES)
  #undef vcvth_f16_s64
  #define vcvth_f16_s64(a) simde_vcvth_f16_s64(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_float16_t
simde_vcvth_f16_s16(int16_t a) {
  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE) && defined(SIMDE_ARM_NEON_FP16)
    return vcvth_f16_s16(a);
  #elif SIMDE_FLOAT16_API != SIMDE_FLOAT16_API_PORTABLE && SIMDE_FLOAT16_API != SIMDE_FLOAT16_API_FP16_NO_ABI
    return HEDLEY_STATIC_CAST(simde_float16_t, a);
  #else
    return simde_float16_from_float32(HEDLEY_STATIC_CAST(simde_float32_t, a));
  #endif
}
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES)
  #undef vcvth_f16_s16
  #define vcvth_f16_s16(a) simde_vcvth_f16_s16(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_float16_t
simde_vcvth_f16_u16(uint16_t a) {
  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE) && defined(SIMDE_ARM_NEON_FP16)
    return vcvth_f16_u16(a);
  #elif SIMDE_FLOAT16_API != SIMDE_FLOAT16_API_PORTABLE && SIMDE_FLOAT16_API != SIMDE_FLOAT16_API_FP16_NO_ABI
    return HEDLEY_STATIC_CAST(simde_float16_t, a);
  #else
    return simde_float16_from_float32(HEDLEY_STATIC_CAST(simde_float32_t, a));
  #endif
}
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES)
  #undef vcvth_f16_u16
  #define vcvth_f16_u16(a) simde_vcvth_f16_u16(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_int16x4_t
simde_vcvt_s16_f16(simde_float16x4_t a) {
  #if defined(SIMDE_ARM_NEON_A32V8_NATIVE) && defined(SIMDE_ARM_NEON_FP16)
    return vcvt_s16_f16(a);
  #else
    simde_float16x4_private a_ = simde_float16x4_to_private(a);
    simde_int16x4_private r_;

    #if defined(SIMDE_CONVERT_VECTOR_) && defined(SIMDE_FAST_CONVERSION_RANGE) && defined(SIMDE_FLOAT16_VECTOR)
      SIMDE_CONVERT_VECTOR_(r_.values, a_.values);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
        r_.values[i] = simde_vcvth_s16_f16(a_.values[i]);
      }
    #endif

    return simde_int16x4_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V8_ENABLE_NATIVE_ALIASES)
  #undef vcvt_s16_f16
  #define vcvt_s16_f16(a) simde_vcvt_s16_f16(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_int32x2_t
simde_vcvt_s32_f32(simde_float32x2_t a) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vcvt_s32_f32(a);
  #else
    simde_float32x2_private a_ = simde_float32x2_to_private(a);
    simde_int32x2_private r_;

    #if defined(SIMDE_CONVERT_VECTOR_) && defined(SIMDE_FAST_CONVERSION_RANGE)
      SIMDE_CONVERT_VECTOR_(r_.values, a_.values);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
        r_.values[i] = simde_vcvts_s32_f32(a_.values[i]);
      }
    #endif

    return simde_int32x2_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vcvt_s32_f32
  #define vcvt_s32_f32(a) simde_vcvt_s32_f32(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint16x4_t
simde_vcvt_u16_f16(simde_float16x4_t a) {
  #if defined(SIMDE_ARM_NEON_A32V8_NATIVE) && defined(SIMDE_ARM_NEON_FP16)
    return vcvt_u16_f16(a);
  #else
    simde_float16x4_private a_ = simde_float16x4_to_private(a);
    simde_uint16x4_private r_;

    #if defined(SIMDE_CONVERT_VECTOR_) && defined(SIMDE_FAST_CONVERSION_RANGE) && defined(SIMDE_FLOAT16_VECTOR)
      SIMDE_CONVERT_VECTOR_(r_.values, a_.values);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
        r_.values[i] = simde_vcvth_u16_f16(a_.values[i]);
      }
    #endif

    return simde_uint16x4_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V8_ENABLE_NATIVE_ALIASES)
  #undef vcvt_u16_f16
  #define vcvt_u16_f16(a) simde_vcvt_u16_f16(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint32x2_t
simde_vcvt_u32_f32(simde_float32x2_t a) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE) && !defined(SIMDE_BUG_CLANG_46844)
    return vcvt_u32_f32(a);
  #else
    simde_float32x2_private a_ = simde_float32x2_to_private(a);
    simde_uint32x2_private r_;

    #if defined(SIMDE_CONVERT_VECTOR_) && defined(SIMDE_FAST_CONVERSION_RANGE)
      SIMDE_CONVERT_VECTOR_(r_.values, a_.values);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
        r_.values[i] = simde_vcvts_u32_f32(a_.values[i]);
      }
    #endif

    return simde_uint32x2_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vcvt_u32_f32
  #define vcvt_u32_f32(a) simde_vcvt_u32_f32(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_int64x1_t
simde_vcvt_s64_f64(simde_float64x1_t a) {
  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
    return vcvt_s64_f64(a);
  #else
    simde_float64x1_private a_ = simde_float64x1_to_private(a);
    simde_int64x1_private r_;

    #if defined(SIMDE_CONVERT_VECTOR_) && defined(SIMDE_FAST_CONVERSION_RANGE)
      SIMDE_CONVERT_VECTOR_(r_.values, a_.values);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
        r_.values[i] = simde_vcvtd_s64_f64(a_.values[i]);
      }
    #endif

    return simde_int64x1_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES)
  #undef vcvt_s64_f64
  #define vcvt_s64_f64(a) simde_vcvt_s64_f64(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint64x1_t
simde_vcvt_u64_f64(simde_float64x1_t a) {
  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE) && !defined(SIMDE_BUG_CLANG_46844)
    return vcvt_u64_f64(a);
  #else
    simde_float64x1_private a_ = simde_float64x1_to_private(a);
    simde_uint64x1_private r_;

    #if defined(SIMDE_CONVERT_VECTOR_) && defined(SIMDE_FAST_CONVERSION_RANGE)
      SIMDE_CONVERT_VECTOR_(r_.values, a_.values);
      r_.values &= HEDLEY_REINTERPRET_CAST(__typeof__(r_.values), (a_.values >= SIMDE_FLOAT64_C(0.0)));
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
        r_.values[i] = simde_vcvtd_u64_f64(a_.values[i]);
      }
    #endif

    return simde_uint64x1_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES)
  #undef vcvt_u64_f64
  #define vcvt_u64_f64(a) simde_vcvt_u64_f64(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_int16x8_t
simde_vcvtq_s16_f16(simde_float16x8_t a) {
  #if defined(SIMDE_ARM_NEON_A32V8_NATIVE) && defined(SIMDE_ARM_NEON_FP16)
    return vcvtq_s16_f16(a);
  #else
    simde_float16x8_private a_ = simde_float16x8_to_private(a);
    simde_int16x8_private r_;

    #if defined(SIMDE_CONVERT_VECTOR_) && defined(SIMDE_FAST_CONVERSION_RANGE) && defined(SIMDE_FLOAT16_VECTOR)
      SIMDE_CONVERT_VECTOR_(r_.values, a_.values);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
        r_.values[i] = simde_vcvth_s16_f16(a_.values[i]);
      }
    #endif

    return simde_int16x8_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V8_ENABLE_NATIVE_ALIASES)
  #undef vcvtq_s16_f16
  #define vcvtq_s16_f16(a) simde_vcvtq_s16_f16(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_int32x4_t
simde_vcvtq_s32_f32(simde_float32x4_t a) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vcvtq_s32_f32(a);
  #elif defined(SIMDE_ZARCH_ZVECTOR_13_NATIVE) && defined(SIMDE_FAST_NANS)
    return vec_signed(a);
  #elif defined(SIMDE_ZARCH_ZVECTOR_13_NATIVE) && !defined(SIMDE_BUG_GCC_101614)
    return (a == a) & vec_signed(a);
  #else
    simde_float32x4_private a_ = simde_float32x4_to_private(a);
    simde_int32x4_private r_;

    #if defined(SIMDE_WASM_SIMD128_NATIVE)
      r_.v128 = wasm_i32x4_trunc_sat_f32x4(a_.v128);
    #elif defined(SIMDE_X86_SSE2_NATIVE)
      #if !defined(SIMDE_FAST_CONVERSION_RANGE)
        const __m128i i32_max_mask = _mm_castps_si128(_mm_cmpgt_ps(a_.m128, _mm_set1_ps(SIMDE_FLOAT32_C(2147483520.0))));
        const __m128 clamped = _mm_max_ps(a_.m128, _mm_set1_ps(HEDLEY_STATIC_CAST(simde_float32, INT32_MIN)));
      #else
        const __m128 clamped = a_.m128;
      #endif

      r_.m128i = _mm_cvttps_epi32(clamped);

      #if !defined(SIMDE_FAST_CONVERSION_RANGE)
        #if defined(SIMDE_X86_SSE4_1_NATIVE)
          r_.m128i =
            _mm_castps_si128(
              _mm_blendv_ps(
                _mm_castsi128_ps(r_.m128i),
                _mm_castsi128_ps(_mm_set1_epi32(INT32_MAX)),
                _mm_castsi128_ps(i32_max_mask)
              )
            );
        #else
          r_.m128i =
            _mm_or_si128(
              _mm_and_si128(i32_max_mask, _mm_set1_epi32(INT32_MAX)),
              _mm_andnot_si128(i32_max_mask, r_.m128i)
            );
        #endif
      #endif

      #if !defined(SIMDE_FAST_NANS)
        r_.m128i = _mm_and_si128(r_.m128i, _mm_castps_si128(_mm_cmpord_ps(a_.m128, a_.m128)));
      #endif
    #elif defined(SIMDE_CONVERT_VECTOR_) && defined(SIMDE_FAST_CONVERSION_RANGE) && !defined(SIMDE_FAST_NANS)
      SIMDE_CONVERT_VECTOR_(r_.values, a_.values);
    #elif defined(SIMDE_CONVERT_VECTOR_) && defined(SIMDE_IEEE754_STORAGE)
      SIMDE_CONVERT_VECTOR_(r_.values, a_.values);

      static const float SIMDE_VECTOR(16) max_representable = { SIMDE_FLOAT32_C(2147483520.0), SIMDE_FLOAT32_C(2147483520.0), SIMDE_FLOAT32_C(2147483520.0), SIMDE_FLOAT32_C(2147483520.0) };
      int32_t SIMDE_VECTOR(16) max_mask = HEDLEY_REINTERPRET_CAST(__typeof__(max_mask), a_.values > max_representable);
      int32_t SIMDE_VECTOR(16) max_i32 = { INT32_MAX, INT32_MAX, INT32_MAX, INT32_MAX };
      r_.values  = (max_i32 & max_mask) | (r_.values & ~max_mask);

      static const float SIMDE_VECTOR(16) min_representable = { HEDLEY_STATIC_CAST(simde_float32, INT32_MIN), HEDLEY_STATIC_CAST(simde_float32, INT32_MIN), HEDLEY_STATIC_CAST(simde_float32, INT32_MIN), HEDLEY_STATIC_CAST(simde_float32, INT32_MIN) };
      int32_t SIMDE_VECTOR(16) min_mask = HEDLEY_REINTERPRET_CAST(__typeof__(min_mask), a_.values < min_representable);
      int32_t SIMDE_VECTOR(16) min_i32 = { INT32_MIN, INT32_MIN, INT32_MIN, INT32_MIN };
      r_.values  = (min_i32 & min_mask) | (r_.values & ~min_mask);

      r_.values &= HEDLEY_REINTERPRET_CAST(__typeof__(r_.values), a_.values == a_.values);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
        r_.values[i] = simde_vcvts_s32_f32(a_.values[i]);
      }
    #endif

    return simde_int32x4_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vcvtq_s32_f32
  #define vcvtq_s32_f32(a) simde_vcvtq_s32_f32(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint16x8_t
simde_vcvtq_u16_f16(simde_float16x8_t a) {
  #if defined(SIMDE_ARM_NEON_A32V8_NATIVE) && defined(SIMDE_ARM_NEON_FP16)
    return vcvtq_u16_f16(a);
  #else
    simde_float16x8_private a_ = simde_float16x8_to_private(a);
    simde_uint16x8_private r_;

    #if defined(SIMDE_CONVERT_VECTOR_) && defined(SIMDE_FAST_CONVERSION_RANGE) && defined(SIMDE_FLOAT16_VECTOR)
      SIMDE_CONVERT_VECTOR_(r_.values, a_.values);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
        r_.values[i] = simde_vcvth_u16_f16(a_.values[i]);
      }
    #endif

    return simde_uint16x8_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V8_ENABLE_NATIVE_ALIASES)
  #undef vcvtq_u16_f16
  #define vcvtq_u16_f16(a) simde_vcvtq_u16_f16(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint32x4_t
simde_vcvtq_u32_f32(simde_float32x4_t a) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE) && !defined(SIMDE_BUG_CLANG_46844)
    return vcvtq_u32_f32(a);
  #else
    simde_float32x4_private a_ = simde_float32x4_to_private(a);
    simde_uint32x4_private r_;

    #if defined(SIMDE_WASM_SIMD128_NATIVE)
      r_.v128 = wasm_u32x4_trunc_sat_f32x4(a_.v128);
    #elif defined(SIMDE_X86_SSE2_NATIVE)
      #if defined(SIMDE_X86_AVX512VL_NATIVE)
        r_.m128i = _mm_cvttps_epu32(a_.m128);
      #else
        __m128 first_oob_high = _mm_set1_ps(SIMDE_FLOAT32_C(4294967296.0));
        __m128 neg_zero_if_too_high =
          _mm_castsi128_ps(
            _mm_slli_epi32(
              _mm_castps_si128(_mm_cmple_ps(first_oob_high, a_.m128)),
              31
            )
          );
        r_.m128i =
          _mm_xor_si128(
            _mm_cvttps_epi32(
              _mm_sub_ps(a_.m128, _mm_and_ps(neg_zero_if_too_high, first_oob_high))
            ),
            _mm_castps_si128(neg_zero_if_too_high)
          );
      #endif

      #if !defined(SIMDE_FAST_CONVERSION_RANGE)
        r_.m128i = _mm_and_si128(r_.m128i, _mm_castps_si128(_mm_cmpgt_ps(a_.m128, _mm_set1_ps(SIMDE_FLOAT32_C(0.0)))));
        r_.m128i = _mm_or_si128 (r_.m128i, _mm_castps_si128(_mm_cmpge_ps(a_.m128, _mm_set1_ps(SIMDE_FLOAT32_C(4294967296.0)))));
      #endif

      #if !defined(SIMDE_FAST_NANS)
        r_.m128i = _mm_and_si128(r_.m128i, _mm_castps_si128(_mm_cmpord_ps(a_.m128, a_.m128)));
      #endif
    #elif defined(SIMDE_CONVERT_VECTOR_) && defined(SIMDE_FAST_CONVERSION_RANGE)
      SIMDE_CONVERT_VECTOR_(r_.values, a_.values);
    #elif defined(SIMDE_CONVERT_VECTOR_) && defined(SIMDE_IEEE754_STORAGE)
      SIMDE_CONVERT_VECTOR_(r_.values, a_.values);

      const __typeof__(a_.values) max_representable = { SIMDE_FLOAT32_C(4294967040.0), SIMDE_FLOAT32_C(4294967040.0), SIMDE_FLOAT32_C(4294967040.0), SIMDE_FLOAT32_C(4294967040.0) };
      r_.values |= HEDLEY_REINTERPRET_CAST(__typeof__(r_.values), a_.values > max_representable);

      const __typeof__(a_.values) min_representable = { SIMDE_FLOAT32_C(0.0), };
      r_.values &= HEDLEY_REINTERPRET_CAST(__typeof__(r_.values), a_.values > min_representable);

      r_.values &= HEDLEY_REINTERPRET_CAST(__typeof__(r_.values), a_.values == a_.values);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
        r_.values[i] = simde_vcvts_u32_f32(a_.values[i]);
      }
    #endif

    return simde_uint32x4_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vcvtq_u32_f32
  #define vcvtq_u32_f32(a) simde_vcvtq_u32_f32(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_int64x2_t
simde_vcvtq_s64_f64(simde_float64x2_t a) {
  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
    return vcvtq_s64_f64(a);
  #elif defined(SIMDE_ZARCH_ZVECTOR_13_NATIVE) && defined(SIMDE_FAST_NANS)
    return vec_signed(a);
  #elif defined(SIMDE_ZARCH_ZVECTOR_13_NATIVE)
    return (a == a) & vec_signed(a);
  #else
    simde_float64x2_private a_ = simde_float64x2_to_private(a);
    simde_int64x2_private r_;

    #if defined(SIMDE_X86_SSE2_NATIVE) && (defined(SIMDE_ARCH_AMD64) || (defined(SIMDE_X86_AVX512DQ_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)))
      #if !defined(SIMDE_FAST_CONVERSION_RANGE)
        const __m128i i64_max_mask = _mm_castpd_si128(_mm_cmpge_pd(a_.m128d, _mm_set1_pd(HEDLEY_STATIC_CAST(simde_float64, INT64_MAX))));
        const __m128d clamped_low = _mm_max_pd(a_.m128d, _mm_set1_pd(HEDLEY_STATIC_CAST(simde_float64, INT64_MIN)));
      #else
        const __m128d clamped_low = a_.m128d;
      #endif

      #if defined(SIMDE_X86_AVX512VL_NATIVE) && defined(SIMDE_X86_AVX512DQ_NATIVE)
        r_.m128i = _mm_cvttpd_epi64(clamped_low);
      #else
        r_.m128i =
          _mm_set_epi64x(
            _mm_cvttsd_si64(_mm_unpackhi_pd(clamped_low, clamped_low)),
            _mm_cvttsd_si64(clamped_low)
          );
      #endif

      #if !defined(SIMDE_FAST_CONVERSION_RANGE)
        #if defined(SIMDE_X86_SSE4_1_NATIVE)
          r_.m128i =
            _mm_castpd_si128(
              _mm_blendv_pd(
                _mm_castsi128_pd(r_.m128i),
                _mm_castsi128_pd(_mm_set1_epi64x(INT64_MAX)),
                _mm_castsi128_pd(i64_max_mask)
              )
            );
        #else
          r_.m128i =
            _mm_or_si128(
              _mm_and_si128(i64_max_mask, _mm_set1_epi64x(INT64_MAX)),
              _mm_andnot_si128(i64_max_mask, r_.m128i)
            );
        #endif
      #endif

      #if !defined(SIMDE_FAST_NANS)
        r_.m128i = _mm_and_si128(r_.m128i, _mm_castpd_si128(_mm_cmpord_pd(a_.m128d, a_.m128d)));
      #endif
    #elif defined(SIMDE_CONVERT_VECTOR_) && defined(SIMDE_FAST_CONVERSION_RANGE)
      SIMDE_CONVERT_VECTOR_(r_.values, a_.values);
    #elif defined(SIMDE_CONVERT_VECTOR_) && defined(SIMDE_IEEE754_STORAGE)
      SIMDE_CONVERT_VECTOR_(r_.values, a_.values);

      const __typeof__((a_.values)) max_representable = { SIMDE_FLOAT64_C(9223372036854774784.0), SIMDE_FLOAT64_C(9223372036854774784.0) };
      __typeof__(r_.values) max_mask = HEDLEY_REINTERPRET_CAST(__typeof__(max_mask), a_.values > max_representable);
      __typeof__(r_.values) max_i64 = { INT64_MAX, INT64_MAX };
      r_.values  = (max_i64 & max_mask) | (r_.values & ~max_mask);

      const __typeof__((a_.values)) min_representable = { HEDLEY_STATIC_CAST(simde_float64, INT64_MIN), HEDLEY_STATIC_CAST(simde_float64, INT64_MIN) };
      __typeof__(r_.values) min_mask = HEDLEY_REINTERPRET_CAST(__typeof__(min_mask), a_.values < min_representable);
      __typeof__(r_.values) min_i64 = { INT64_MIN, INT64_MIN };
      r_.values  = (min_i64 & min_mask) | (r_.values & ~min_mask);

      #if !defined(SIMDE_FAST_NANS)
        r_.values &= HEDLEY_REINTERPRET_CAST(__typeof__(r_.values), a_.values == a_.values);
      #endif
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
        r_.values[i] = simde_vcvtd_s64_f64(a_.values[i]);
    }
    #endif

    return simde_int64x2_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES)
  #undef vcvtq_s64_f64
  #define vcvtq_s64_f64(a) simde_vcvtq_s64_f64(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint64x2_t
simde_vcvtq_u64_f64(simde_float64x2_t a) {
  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE) && !defined(SIMDE_BUG_CLANG_46844)
    return vcvtq_u64_f64(a);
  #elif defined(SIMDE_ZARCH_ZVECTOR_13_NATIVE) && defined(SIMDE_FAST_NANS)
    return vec_unsigned(a);
  #elif defined(SIMDE_ZARCH_ZVECTOR_13_NATIVE)
    return HEDLEY_REINTERPRET_CAST(simde_uint64x2_t, (a == a)) & vec_unsigned(a);
  #else
    simde_float64x2_private a_ = simde_float64x2_to_private(a);
    simde_uint64x2_private r_;

    #if defined(SIMDE_CONVERT_VECTOR_) && defined(SIMDE_FAST_CONVERSION_RANGE)
      SIMDE_CONVERT_VECTOR_(r_.values, a_.values);
    #elif defined(SIMDE_X86_SSE2_NATIVE) && (defined(SIMDE_ARCH_AMD64) || (defined(SIMDE_X86_AVX512DQ_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)))
      #if defined(SIMDE_X86_AVX512DQ_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
        r_.m128i = _mm_cvttpd_epu64(a_.m128d);
      #else
        __m128d first_oob_high = _mm_set1_pd(SIMDE_FLOAT64_C(18446744073709551616.0));
        __m128d neg_zero_if_too_high =
          _mm_castsi128_pd(
            _mm_slli_epi64(
              _mm_castpd_si128(_mm_cmple_pd(first_oob_high, a_.m128d)),
              63
            )
          );
        __m128d tmp = _mm_sub_pd(a_.m128d, _mm_and_pd(neg_zero_if_too_high, first_oob_high));
        r_.m128i =
          _mm_xor_si128(
            _mm_set_epi64x(
              _mm_cvttsd_si64(_mm_unpackhi_pd(tmp, tmp)),
              _mm_cvttsd_si64(tmp)
            ),
            _mm_castpd_si128(neg_zero_if_too_high)
          );
      #endif

      #if !defined(SIMDE_FAST_CONVERSION_RANGE)
        r_.m128i = _mm_and_si128(r_.m128i, _mm_castpd_si128(_mm_cmpgt_pd(a_.m128d, _mm_set1_pd(SIMDE_FLOAT64_C(0.0)))));
        r_.m128i = _mm_or_si128 (r_.m128i, _mm_castpd_si128(_mm_cmpge_pd(a_.m128d, _mm_set1_pd(SIMDE_FLOAT64_C(18446744073709551616.0)))));
      #endif

      #if !defined(SIMDE_FAST_NANS)
        r_.m128i = _mm_and_si128(r_.m128i, _mm_castpd_si128(_mm_cmpord_pd(a_.m128d, a_.m128d)));
      #endif
    #elif defined(SIMDE_CONVERT_VECTOR_) && defined(SIMDE_IEEE754_STORAGE)
      SIMDE_CONVERT_VECTOR_(r_.values, a_.values);

      const __typeof__(a_.values) max_representable = { SIMDE_FLOAT64_C(18446744073709549568.0), SIMDE_FLOAT64_C(18446744073709549568.0) };
      r_.values |= HEDLEY_REINTERPRET_CAST(__typeof__(r_.values), a_.values > max_representable);

      const __typeof__(a_.values) min_representable = { SIMDE_FLOAT64_C(0.0), };
      r_.values &= HEDLEY_REINTERPRET_CAST(__typeof__(r_.values), a_.values > min_representable);

      r_.values &= HEDLEY_REINTERPRET_CAST(__typeof__(r_.values), (a_.values == a_.values));
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
        r_.values[i] = simde_vcvtd_u64_f64(a_.values[i]);
      }
    #endif

    return simde_uint64x2_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES)
  #undef vcvtq_u64_f64
  #define vcvtq_u64_f64(a) simde_vcvtq_u64_f64(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_float16x4_t
simde_vcvt_f16_s16(simde_int16x4_t a) {
  #if defined(SIMDE_ARM_NEON_A32V8_NATIVE) && defined(SIMDE_ARM_NEON_FP16)
    return vcvt_f16_s16(a);
  #else
    simde_int16x4_private a_ = simde_int16x4_to_private(a);
    simde_float16x4_private r_;

    #if defined(SIMDE_CONVERT_VECTOR_) && defined(SIMDE_FLOAT16_VECTOR)
      SIMDE_CONVERT_VECTOR_(r_.values, a_.values);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
        #if SIMDE_FLOAT16_API != SIMDE_FLOAT16_API_PORTABLE && SIMDE_FLOAT16_API != SIMDE_FLOAT16_API_FP16_NO_ABI
          r_.values[i] = HEDLEY_STATIC_CAST(simde_float16_t, a_.values[i]);
        #else
          r_.values[i] = simde_float16_from_float32(HEDLEY_STATIC_CAST(simde_float32_t, a_.values[i]));
        #endif
      }
    #endif

    return simde_float16x4_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V8_ENABLE_NATIVE_ALIASES)
  #undef vcvt_f16_s16
  #define vcvt_f16_s16(a) simde_vcvt_f16_s16(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_float32x2_t
simde_vcvt_f32_s32(simde_int32x2_t a) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vcvt_f32_s32(a);
  #else
    simde_int32x2_private a_ = simde_int32x2_to_private(a);
    simde_float32x2_private r_;

    #if defined(SIMDE_CONVERT_VECTOR_)
      SIMDE_CONVERT_VECTOR_(r_.values, a_.values);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
        r_.values[i] = simde_vcvts_f32_s32(a_.values[i]);
      }
    #endif

    return simde_float32x2_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vcvt_f32_s32
  #define vcvt_f32_s32(a) simde_vcvt_f32_s32(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_float16x4_t
simde_vcvt_f16_u16(simde_uint16x4_t a) {
  #if defined(SIMDE_ARM_NEON_A32V8_NATIVE) && defined(SIMDE_ARM_NEON_FP16)
    return vcvt_f16_u16(a);
  #else
    simde_uint16x4_private a_ = simde_uint16x4_to_private(a);
    simde_float16x4_private r_;

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
      #if SIMDE_FLOAT16_API != SIMDE_FLOAT16_API_PORTABLE && SIMDE_FLOAT16_API != SIMDE_FLOAT16_API_FP16_NO_ABI
        r_.values[i] = HEDLEY_STATIC_CAST(simde_float16_t, a_.values[i]);
      #else
        r_.values[i] = simde_float16_from_float32(HEDLEY_STATIC_CAST(simde_float32_t, a_.values[i]));
      #endif
    }

    return simde_float16x4_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V8_ENABLE_NATIVE_ALIASES)
  #undef vcvt_f16_u16
  #define vcvt_f16_u16(a) simde_vcvt_f16_u16(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_float32x2_t
simde_vcvt_f32_u32(simde_uint32x2_t a) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE) && !defined(SIMDE_BUG_CLANG_46844)
    return vcvt_f32_u32(a);
  #else
    simde_uint32x2_private a_ = simde_uint32x2_to_private(a);
    simde_float32x2_private r_;

    #if defined(SIMDE_CONVERT_VECTOR_)
      SIMDE_CONVERT_VECTOR_(r_.values, a_.values);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
        r_.values[i] = simde_vcvts_f32_u32(a_.values[i]);
      }
    #endif

    return simde_float32x2_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vcvt_f32_u32
  #define vcvt_f32_u32(a) simde_vcvt_f32_u32(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_float64x1_t
simde_vcvt_f64_s64(simde_int64x1_t a) {
  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
    return vcvt_f64_s64(a);
  #else
    simde_int64x1_private a_ = simde_int64x1_to_private(a);
    simde_float64x1_private r_;

    #if defined(SIMDE_CONVERT_VECTOR_)
      SIMDE_CONVERT_VECTOR_(r_.values, a_.values);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
        r_.values[i] = simde_vcvtd_f64_s64(a_.values[i]);
      }
    #endif

    return simde_float64x1_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES)
  #undef vcvt_f64_s64
  #define vcvt_f64_s64(a) simde_vcvt_f64_s64(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_float64x1_t
simde_vcvt_f64_u64(simde_uint64x1_t a) {
  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE) && !defined(SIMDE_BUG_CLANG_46844)
    return vcvt_f64_u64(a);
  #else
    simde_uint64x1_private a_ = simde_uint64x1_to_private(a);
    simde_float64x1_private r_;

    #if defined(SIMDE_CONVERT_VECTOR_)
      SIMDE_CONVERT_VECTOR_(r_.values, a_.values);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
        r_.values[i] = simde_vcvtd_f64_u64(a_.values[i]);
      }
    #endif

    return simde_float64x1_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES)
  #undef vcvt_f64_u64
  #define vcvt_f64_u64(a) simde_vcvt_f64_u64(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_float16x8_t
simde_vcvtq_f16_s16(simde_int16x8_t a) {
  #if defined(SIMDE_ARM_NEON_A32V8_NATIVE) && defined(SIMDE_ARM_NEON_FP16)
    return vcvtq_f16_s16(a);
  #else
    simde_int16x8_private a_ = simde_int16x8_to_private(a);
    simde_float16x8_private r_;

    #if defined(SIMDE_CONVERT_VECTOR_) && defined(SIMDE_FLOAT16_VECTOR)
      SIMDE_CONVERT_VECTOR_(r_.values, a_.values);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
        #if SIMDE_FLOAT16_API != SIMDE_FLOAT16_API_PORTABLE && SIMDE_FLOAT16_API != SIMDE_FLOAT16_API_FP16_NO_ABI
          r_.values[i] = HEDLEY_STATIC_CAST(simde_float16_t, a_.values[i]);
        #else
          r_.values[i] = simde_float16_from_float32(HEDLEY_STATIC_CAST(simde_float32_t, a_.values[i]));
        #endif
      }
    #endif

    return simde_float16x8_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V8_ENABLE_NATIVE_ALIASES)
  #undef vcvtq_f16_s16
  #define vcvtq_f16_s16(a) simde_vcvtq_f16_s16(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_float32x4_t
simde_vcvtq_f32_s32(simde_int32x4_t a) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vcvtq_f32_s32(a);
  #else
    simde_int32x4_private a_ = simde_int32x4_to_private(a);
    simde_float32x4_private r_;

    #if defined(SIMDE_CONVERT_VECTOR_)
      SIMDE_CONVERT_VECTOR_(r_.values, a_.values);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
        r_.values[i] = simde_vcvts_f32_s32(a_.values[i]);
      }
    #endif

    return simde_float32x4_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vcvtq_f32_s32
  #define vcvtq_f32_s32(a) simde_vcvtq_f32_s32(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_float16x8_t
simde_vcvtq_f16_u16(simde_uint16x8_t a) {
  #if defined(SIMDE_ARM_NEON_A32V8_NATIVE) && !defined(SIMDE_BUG_CLANG_46844) && defined(SIMDE_ARM_NEON_FP16)
    return vcvtq_f16_u16(a);
  #else
    simde_uint16x8_private a_ = simde_uint16x8_to_private(a);
    simde_float16x8_private r_;

    #if defined(SIMDE_CONVERT_VECTOR_) && defined(SIMDE_FLOAT16_VECTOR)
      SIMDE_CONVERT_VECTOR_(r_.values, a_.values);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
        #if SIMDE_FLOAT16_API != SIMDE_FLOAT16_API_PORTABLE && SIMDE_FLOAT16_API != SIMDE_FLOAT16_API_FP16_NO_ABI
          r_.values[i] = HEDLEY_STATIC_CAST(simde_float16_t, a_.values[i]);
        #else
          r_.values[i] = simde_float16_from_float32(HEDLEY_STATIC_CAST(simde_float32_t, a_.values[i]));
        #endif
      }
    #endif

    return simde_float16x8_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V8_ENABLE_NATIVE_ALIASES)
  #undef vcvtq_f16_u16
  #define vcvtq_f16_u16(a) simde_vcvtq_f16_u16(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_float32x4_t
simde_vcvtq_f32_u32(simde_uint32x4_t a) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE) && !defined(SIMDE_BUG_CLANG_46844)
    return vcvtq_f32_u32(a);
  #else
    simde_uint32x4_private a_ = simde_uint32x4_to_private(a);
    simde_float32x4_private r_;

    #if defined(SIMDE_CONVERT_VECTOR_)
      SIMDE_CONVERT_VECTOR_(r_.values, a_.values);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
        r_.values[i] = simde_vcvts_f32_u32(a_.values[i]);
      }
    #endif

    return simde_float32x4_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vcvtq_f32_u32
  #define vcvtq_f32_u32(a) simde_vcvtq_f32_u32(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_float64x2_t
simde_vcvtq_f64_s64(simde_int64x2_t a) {
  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
    return vcvtq_f64_s64(a);
  #elif defined(SIMDE_ZARCH_ZVECTOR_13_NATIVE)
    return vec_ctd(a, 0);
  #else
    simde_int64x2_private a_ = simde_int64x2_to_private(a);
    simde_float64x2_private r_;

    #if defined(SIMDE_X86_AVX512VL_NATIVE) && defined(SIMDE_X86_AVX512DQ_NATIVE)
      r_.m128d = _mm_cvtepi64_pd(a_.m128i);
    #elif defined(SIMDE_CONVERT_VECTOR_)
      SIMDE_CONVERT_VECTOR_(r_.values, a_.values);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
        r_.values[i] = simde_vcvtd_f64_s64(a_.values[i]);
      }
    #endif

    return simde_float64x2_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES)
  #undef vcvtq_f64_s64
  #define vcvtq_f64_s64(a) simde_vcvtq_f64_s64(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_float64x2_t
simde_vcvtq_f64_u64(simde_uint64x2_t a) {
  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE) && !defined(SIMDE_BUG_CLANG_46844)
    return vcvtq_f64_u64(a);
  #else
    simde_uint64x2_private a_ = simde_uint64x2_to_private(a);
    simde_float64x2_private r_;

    #if defined(SIMDE_CONVERT_VECTOR_)
      SIMDE_CONVERT_VECTOR_(r_.values, a_.values);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
        r_.values[i] = simde_vcvtd_f64_u64(a_.values[i]);
      }
    #endif

    return simde_float64x2_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES)
  #undef vcvtq_f64_u64
  #define vcvtq_f64_u64(a) simde_vcvtq_f64_u64(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
int16_t
simde_vcvtah_s16_f16(simde_float16_t a) {
  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE) && defined(SIMDE_ARM_NEON_FP16)
    return vcvtah_s16_f16(a);
  #elif defined(SIMDE_FAST_CONVERSION_RANGE)
    return HEDLEY_STATIC_CAST(int16_t,
        simde_math_roundf(simde_float16_to_float32(a)));
  #else
    simde_float32 af = simde_float16_to_float32(a);
    if (HEDLEY_UNLIKELY(af <= HEDLEY_STATIC_CAST(simde_float32, INT16_MIN))) {
      return INT16_MIN;
    } else if (HEDLEY_UNLIKELY(af >= HEDLEY_STATIC_CAST(simde_float32, INT16_MAX))) {
      return INT16_MAX;
    } else if (HEDLEY_UNLIKELY(simde_isnanhf(a))) {
      return 0;
    } else {
      return HEDLEY_STATIC_CAST(int16_t, simde_math_roundf(af));
    }
  #endif
}
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES)
  #undef vcvtah_s16_f16
  #define vcvtah_s16_f16(a) simde_vcvtah_s16_f16(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
uint16_t
simde_vcvtah_u16_f16(simde_float16_t a) {
  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE) && !defined(SIMDE_BUG_CLANG_46844) && defined(SIMDE_ARM_NEON_FP16)
    return vcvtah_u16_f16(a);
  #elif defined(SIMDE_FAST_CONVERSION_RANGE)
    return HEDLEY_STATIC_CAST(uint16_t,
        simde_math_roundf(simde_float16_to_float32(a)));
  #else
    simde_float32 af = simde_float16_to_float32(a);
    if (HEDLEY_UNLIKELY(af <= SIMDE_FLOAT32_C(0.0))) {
      return 0;
    } else if (HEDLEY_UNLIKELY(af >= HEDLEY_STATIC_CAST(simde_float32, UINT16_MAX))) {
      return UINT16_MAX;
    } else if (HEDLEY_UNLIKELY(simde_isnanhf(a))) {
      return 0;
    } else {
      return HEDLEY_STATIC_CAST(uint16_t, simde_math_roundf(af));
    }
  #endif
}
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES)
  #undef vcvtah_u16_f16
  #define vcvtah_u16_f16(a) simde_vcvtah_u16_f16(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
int32_t
simde_vcvtah_s32_f16(simde_float16_t a) {
  #if defined(SIMDE_ARM_NEON_A32V8_NATIVE) && defined(SIMDE_ARM_NEON_FP16)
    return vcvtah_s32_f16(a);
  #elif defined(SIMDE_FAST_CONVERSION_RANGE)
    return HEDLEY_STATIC_CAST(int32_t,
        simde_math_roundf(simde_float16_to_float32(a)));
  #else
    simde_float32 af = simde_float16_to_float32(a);
    if (HEDLEY_UNLIKELY(af <= HEDLEY_STATIC_CAST(simde_float32, INT32_MIN))) {
      return INT32_MIN;
    } else if (HEDLEY_UNLIKELY(af >= HEDLEY_STATIC_CAST(simde_float32, INT32_MAX))) {
      return INT32_MAX;
    } else if (HEDLEY_UNLIKELY(simde_isnanhf(a))) {
      return 0;
    } else {
      return HEDLEY_STATIC_CAST(int32_t, simde_math_roundf(af));
    }
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V8_ENABLE_NATIVE_ALIASES)
  #undef vcvtah_s32_f16
  #define vcvtah_s32_f16(a) simde_vcvtah_s32_f16(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
uint32_t
simde_vcvtah_u32_f16(simde_float16_t a) {
  #if defined(SIMDE_ARM_NEON_A32V8_NATIVE) && !defined(SIMDE_BUG_CLANG_46844) && defined(SIMDE_ARM_NEON_FP16)
    return vcvtah_u32_f16(a);
  #elif defined(SIMDE_FAST_CONVERSION_RANGE)
    return HEDLEY_STATIC_CAST(uint32_t,
        simde_math_roundf(simde_float16_to_float32(a)));
  #else
    simde_float32 af = simde_float16_to_float32(a);
    if (HEDLEY_UNLIKELY(af <= SIMDE_FLOAT32_C(0.0))) {
      return 0;
    } else if (HEDLEY_UNLIKELY(af >= HEDLEY_STATIC_CAST(simde_float32, UINT32_MAX))) {
      return UINT32_MAX;
    } else if (HEDLEY_UNLIKELY(simde_isnanhf(a))) {
      return 0;
    } else {
      return HEDLEY_STATIC_CAST(uint32_t, simde_math_roundf(af));
    }
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V8_ENABLE_NATIVE_ALIASES)
  #undef vcvtah_u32_f16
  #define vcvtah_u32_f16(a) simde_vcvtah_u32_f16(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
int64_t
simde_vcvtah_s64_f16(simde_float16_t a) {
  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE) && defined(SIMDE_ARM_NEON_FP16)
    return vcvtah_s64_f16(a);
  #elif defined(SIMDE_FAST_CONVERSION_RANGE)
    return HEDLEY_STATIC_CAST(int64_t,
        simde_math_roundf(simde_float16_to_float32(a)));
  #else
    simde_float32 af = simde_float16_to_float32(a);
    if (HEDLEY_UNLIKELY(af <= HEDLEY_STATIC_CAST(simde_float32, INT64_MIN))) {
      return INT64_MIN;
    } else if (HEDLEY_UNLIKELY(af >= HEDLEY_STATIC_CAST(simde_float32, INT64_MAX))) {
      return INT64_MAX;
    } else if (HEDLEY_UNLIKELY(simde_isnanhf(a))) {
      return 0;
    } else {
      return HEDLEY_STATIC_CAST(int64_t, simde_math_roundf(af));
    }
  #endif
}
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES)
  #undef vcvtah_s64_f16
  #define vcvtah_s64_f16(a) simde_vcvtah_s64_f16(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
uint64_t
simde_vcvtah_u64_f16(simde_float16_t a) {
  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE) && !defined(SIMDE_BUG_CLANG_46844) && defined(SIMDE_ARM_NEON_FP16)
    return vcvtah_u64_f16(a);
  #elif defined(SIMDE_FAST_CONVERSION_RANGE)
    return HEDLEY_STATIC_CAST(uint64_t,
        simde_math_roundf(simde_float16_to_float32(a)));
  #else
    simde_float32 af = simde_float16_to_float32(a);
    if (HEDLEY_UNLIKELY(af <= SIMDE_FLOAT32_C(0.0))) {
      return 0;
    } else if (HEDLEY_UNLIKELY(af >= HEDLEY_STATIC_CAST(simde_float32, UINT64_MAX))) {
      return UINT64_MAX;
    } else if (HEDLEY_UNLIKELY(simde_isnanhf(a))) {
      return 0;
    } else {
      return HEDLEY_STATIC_CAST(uint64_t, simde_math_roundf(af));
    }
  #endif
}
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES)
  #undef vcvtah_u64_f16
  #define vcvtah_u64_f16(a) simde_vcvtah_u64_f16(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
int64_t
simde_vcvtad_s64_f64(simde_float64 a) {
  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
    return vcvtad_s64_f64(a);
  #elif defined(SIMDE_FAST_CONVERSION_RANGE)
    return HEDLEY_STATIC_CAST(int64_t, simde_math_round(a));
  #else
    if (HEDLEY_UNLIKELY(a <= HEDLEY_STATIC_CAST(simde_float64, INT64_MIN))) {
      return INT64_MIN;
    } else if (HEDLEY_UNLIKELY(a >= HEDLEY_STATIC_CAST(simde_float64, INT64_MAX))) {
      return INT64_MAX;
    } else if (HEDLEY_UNLIKELY(simde_math_isnan(a))) {
      return 0;
    } else {
      return HEDLEY_STATIC_CAST(int64_t, simde_math_round(a));
    }
  #endif
}
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES)
  #undef vcvtad_s64_f64
  #define vcvtad_s64_f64(a) simde_vcvtad_s64_f64(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
uint64_t
simde_vcvtad_u64_f64(simde_float64 a) {
  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE) && !defined(SIMDE_BUG_CLANG_46844)
    return vcvtad_u64_f64(a);
  #elif defined(SIMDE_FAST_CONVERSION_RANGE)
    return HEDLEY_STATIC_CAST(uint64_t, simde_math_round(a));
  #else
    if (HEDLEY_UNLIKELY(a <= SIMDE_FLOAT64_C(0.0))) {
      return 0;
    } else if (HEDLEY_UNLIKELY(a >= HEDLEY_STATIC_CAST(simde_float64, UINT64_MAX))) {
      return UINT64_MAX;
    } else if (simde_math_isnan(a)) {
      return 0;
    } else {
      return HEDLEY_STATIC_CAST(uint64_t, simde_math_round(a));
    }
  #endif
}
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES)
  #undef vcvtad_u64_f64
  #define vcvtad_u64_f64(a) simde_vcvtad_u64_f64(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
int32_t
simde_vcvtas_s32_f32(simde_float32 a) {
  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
    return vcvtas_s32_f32(a);
  #elif defined(SIMDE_FAST_CONVERSION_RANGE)
    return HEDLEY_STATIC_CAST(int32_t, simde_math_roundf(a));
  #else
    if (HEDLEY_UNLIKELY(a <= HEDLEY_STATIC_CAST(simde_float32, INT32_MIN))) {
      return INT32_MIN;
    } else if (HEDLEY_UNLIKELY(a >= HEDLEY_STATIC_CAST(simde_float32, INT32_MAX))) {
      return INT32_MAX;
    } else if (HEDLEY_UNLIKELY(simde_math_isnanf(a))) {
      return 0;
    } else {
      return HEDLEY_STATIC_CAST(int32_t, simde_math_roundf(a));
    }
  #endif
}
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES)
  #undef vcvtas_s32_f32
  #define vcvtas_s32_f32(a) simde_vcvtas_s32_f32(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
uint32_t
simde_vcvtas_u32_f32(simde_float32 a) {
  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
    return vcvtas_u32_f32(a);
  #elif defined(SIMDE_FAST_CONVERSION_RANGE)
    return HEDLEY_STATIC_CAST(uint32_t, simde_math_roundf(a));
  #else
    if (HEDLEY_UNLIKELY(a < SIMDE_FLOAT32_C(0.0))) {
      return 0;
    } else if (HEDLEY_UNLIKELY(a >= HEDLEY_STATIC_CAST(simde_float32, UINT32_MAX))) {
      return UINT32_MAX;
    } else if (HEDLEY_UNLIKELY(simde_math_isnanf(a))) {
      return 0;
    } else {
      if (a < 0) return 0;
      return HEDLEY_STATIC_CAST(uint32_t, simde_math_roundf(a));
    }
  #endif
}
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES)
  #undef vcvtas_u32_f32
  #define vcvtas_u32_f32(a) simde_vcvtas_u32_f32(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_int16x4_t
simde_vcvta_s16_f16(simde_float16x4_t a) {
  #if defined(SIMDE_ARM_NEON_A32V8_NATIVE) && defined(SIMDE_ARM_NEON_FP16)
    return vcvta_s16_f16(a);
  #else
    simde_float16x4_private a_ = simde_float16x4_to_private(a);
    simde_int16x4_private r_;

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
      r_.values[i] = simde_vcvtah_s16_f16(a_.values[i]);
    }

    return simde_int16x4_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V8_ENABLE_NATIVE_ALIASES)
  #undef vcvta_s16_f16
  #define vcvta_s16_f16(a) simde_vcvta_s16_f16(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint16x4_t
simde_vcvta_u16_f16(simde_float16x4_t a) {
  #if defined(SIMDE_ARM_NEON_A32V8_NATIVE) && defined(SIMDE_ARM_NEON_FP16)
    return vcvta_u16_f16(a);
  #else
    simde_float16x4_private a_ = simde_float16x4_to_private(a);
    simde_uint16x4_private r_;

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
      r_.values[i] = simde_vcvtah_u16_f16(a_.values[i]);
    }

    return simde_uint16x4_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V8_ENABLE_NATIVE_ALIASES)
  #undef vcvta_u16_f16
  #define vcvta_u16_f16(a) simde_vcvta_u16_f16(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_int64x1_t
simde_vcvta_s64_f64(simde_float64x1_t a) {
  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
    return vcvta_s64_f64(a);
  #else
    simde_float64x1_private a_ = simde_float64x1_to_private(a);
    simde_int64x1_private r_;

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
      r_.values[i] = simde_vcvtad_s64_f64(a_.values[i]);
    }

    return simde_int64x1_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES)
  #undef vcvta_s64_f64
  #define vcvta_s64_f64(a) simde_vcvta_s64_f64(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint64x1_t
simde_vcvta_u64_f64(simde_float64x1_t a) {
  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
    return vcvta_u64_f64(a);
  #else
    simde_float64x1_private a_ = simde_float64x1_to_private(a);
    simde_uint64x1_private r_;

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
      r_.values[i] = simde_vcvtad_u64_f64(a_.values[i]);
    }

    return simde_uint64x1_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES)
  #undef vcvta_u64_f64
  #define vcvta_u64_f64(a) simde_vcvta_u64_f64(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_int32x2_t
simde_vcvta_s32_f32(simde_float32x2_t a) {
  #if defined(SIMDE_ARM_NEON_A32V8_NATIVE)
    return vcvta_s32_f32(a);
  #else
    simde_float32x2_private a_ = simde_float32x2_to_private(a);
    simde_int32x2_private r_;

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
      r_.values[i] = simde_vcvtas_s32_f32(a_.values[i]);
    }

    return simde_int32x2_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V8_ENABLE_NATIVE_ALIASES)
  #undef vcvta_s32_f32
  #define vcvta_s32_f32(a) simde_vcvta_s32_f32(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_int16x8_t
simde_vcvtaq_s16_f16(simde_float16x8_t a) {
  #if defined(SIMDE_ARM_NEON_A32V8_NATIVE) && defined(SIMDE_ARM_NEON_FP16)
    return vcvtaq_s16_f16(a);
  #else
    simde_float16x8_private a_ = simde_float16x8_to_private(a);
    simde_int16x8_private r_;

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
      r_.values[i] = simde_vcvtah_s16_f16(a_.values[i]);
    }

    return simde_int16x8_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V8_ENABLE_NATIVE_ALIASES)
  #undef vcvtaq_s16_f16
  #define vcvtaq_s16_f16(a) simde_vcvtaq_s16_f16(a)
#endif


SIMDE_FUNCTION_ATTRIBUTES
simde_uint16x8_t
simde_vcvtaq_u16_f16(simde_float16x8_t a) {
  #if defined(SIMDE_ARM_NEON_A32V8_NATIVE) && defined(SIMDE_ARM_NEON_FP16)
    return vcvtaq_u16_f16(a);
  #else
    simde_float16x8_private a_ = simde_float16x8_to_private(a);
    simde_uint16x8_private r_;

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
      r_.values[i] = simde_vcvtah_u16_f16(a_.values[i]);
    }

    return simde_uint16x8_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V8_ENABLE_NATIVE_ALIASES)
  #undef vcvtaq_u16_f16
  #define vcvtaq_u16_f16(a) simde_vcvtaq_u16_f16(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_int32x4_t
simde_vcvtaq_s32_f32(simde_float32x4_t a) {
  #if defined(SIMDE_ARM_NEON_A32V8_NATIVE)
    return vcvtaq_s32_f32(a);
  #else
    simde_float32x4_private a_ = simde_float32x4_to_private(a);
    simde_int32x4_private r_;

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
      r_.values[i] = simde_vcvtas_s32_f32(a_.values[i]);
    }

    return simde_int32x4_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V8_ENABLE_NATIVE_ALIASES)
  #undef vcvtaq_s32_f32
  #define vcvtaq_s32_f32(a) simde_vcvtaq_s32_f32(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_int64x2_t
simde_vcvtaq_s64_f64(simde_float64x2_t a) {
  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
    return vcvtaq_s64_f64(a);
  #else
    simde_float64x2_private a_ = simde_float64x2_to_private(a);
    simde_int64x2_private r_;

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
      r_.values[i] = simde_vcvtad_s64_f64(a_.values[i]);
    }

    return simde_int64x2_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES)
  #undef vcvtaq_s64_f64
  #define vcvtaq_s64_f64(a) simde_vcvtaq_s64_f64(a)
#endif


SIMDE_FUNCTION_ATTRIBUTES
simde_uint64x2_t
simde_vcvtaq_u64_f64(simde_float64x2_t a) {
  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
    return vcvtaq_u64_f64(a);
  #else
    simde_float64x2_private a_ = simde_float64x2_to_private(a);
    simde_uint64x2_private r_;

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
      r_.values[i] = simde_vcvtad_u64_f64(a_.values[i]);
    }

    return simde_uint64x2_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES)
  #undef vcvtaq_u64_f64
  #define vcvtaq_u64_f64(a) simde_vcvtaq_u64_f64(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint32x2_t
simde_vcvta_u32_f32(simde_float32x2_t a) {
  #if defined(SIMDE_ARM_NEON_A32V8_NATIVE)
    return vcvta_u32_f32(a);
  #else
    simde_float32x2_private a_ = simde_float32x2_to_private(a);
    simde_uint32x2_private r_;

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
      r_.values[i] = simde_vcvtas_u32_f32(a_.values[i]);
    }

    return simde_uint32x2_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V8_ENABLE_NATIVE_ALIASES)
  #undef vcvta_u32_f32
  #define vcvta_u32_f32(a) simde_vcvta_u32_f32(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint32x4_t
simde_vcvtaq_u32_f32(simde_float32x4_t a) {
  #if defined(SIMDE_ARM_NEON_A32V8_NATIVE)
    return vcvtaq_u32_f32(a);
  #else
    simde_float32x4_private a_ = simde_float32x4_to_private(a);
    simde_uint32x4_private r_;

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
      r_.values[i] = simde_vcvtas_u32_f32(a_.values[i]);
    }

    return simde_uint32x4_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V8_ENABLE_NATIVE_ALIASES)
  #undef vcvtaq_u32_f32
  #define vcvtaq_u32_f32(a) simde_vcvtaq_u32_f32(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_float16x8_t
simde_vcvt_high_f16_f32(simde_float16x4_t r, simde_float32x4_t a) {
  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE) && defined(SIMDE_ARM_NEON_FP16)
    return vcvt_high_f16_f32(r, a);
  #else
    simde_float32x4_private a_ = simde_float32x4_to_private(a);
    simde_float16x4_private b_ = simde_float16x4_to_private(r);
    simde_float16x8_private r_;

    size_t half_pos = (sizeof(r_.values) / sizeof(r_.values[0]) / 2);
    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < half_pos; i++) {
      r_.values[i] = b_.values[i];
    }
    SIMDE_VECTORIZE
    for (size_t i = half_pos; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
      r_.values[i] = simde_float16_from_float32(a_.values[i-half_pos]);
    }

    return simde_float16x8_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES)
  #undef vcvt_high_f16_f32
  #define vcvt_high_f16_f32(r, a) simde_vcvt_high_f16_f32((r), (a))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_float32x4_t
simde_vcvt_high_f32_f64(simde_float32x2_t r, simde_float64x2_t a) {
  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE) && defined(SIMDE_ARM_NEON_FP16)
    return vcvt_high_f32_f64(r, a);
  #else
    simde_float64x2_private a_ = simde_float64x2_to_private(a);
    simde_float32x2_private b_ = simde_float32x2_to_private(r);
    simde_float32x4_private r_;

    size_t half_pos = (sizeof(r_.values) / sizeof(r_.values[0]) / 2);
    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < half_pos; i++) {
      r_.values[i] = b_.values[i];
    }
    SIMDE_VECTORIZE
    for (size_t i = half_pos; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
      r_.values[i] = HEDLEY_STATIC_CAST(simde_float32, a_.values[i-half_pos]);
    }

    return simde_float32x4_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES)
  #undef vcvt_high_f32_f64
  #define vcvt_high_f32_f64(r, a) simde_vcvt_high_f32_f64((r), (a))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_float32x4_t
simde_vcvt_high_f32_f16(simde_float16x8_t a) {
  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE) && defined(SIMDE_ARM_NEON_FP16)
    return vcvt_high_f32_f16(a);
  #else
    simde_float16x8_private a_ = simde_float16x8_to_private(a);
    simde_float32x4_private r_;

    size_t rsize = (sizeof(r_.values) / sizeof(r_.values[0]));
    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < rsize; i++) {
      r_.values[i] = simde_float16_to_float32(a_.values[i+rsize]);
    }

    return simde_float32x4_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES)
  #undef vcvt_high_f32_f16
  #define vcvt_high_f32_f16(a) simde_vcvt_high_f32_f16(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_float64x2_t
simde_vcvt_high_f64_f32(simde_float32x4_t a) {
  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
    return vcvt_high_f64_f32(a);
  #else
    simde_float32x4_private a_ = simde_float32x4_to_private(a);
    simde_float64x2_private r_;

    size_t rsize = (sizeof(r_.values) / sizeof(r_.values[0]));
    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
      r_.values[i] = HEDLEY_STATIC_CAST(simde_float64, a_.values[i+rsize]);
    }

    return simde_float64x2_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES)
  #undef vcvt_high_f64_f32
  #define vcvt_high_f64_f32(a) simde_vcvt_high_f64_f32(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_float32_t
simde_vcvtxd_f32_f64(simde_float64_t a) {
  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
    return vcvtxd_f32_f64(a);
  #else
    return HEDLEY_STATIC_CAST(simde_float32_t, a);
  #endif
}
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES)
  #undef vcvtxd_f32_f64
  #define vcvtxd_f32_f64(a) simde_vcvtxd_f32_f64(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_float32x2_t
simde_vcvtx_f32_f64(simde_float64x2_t a) {
  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
    return vcvtx_f32_f64(a);
  #else
    simde_float64x2_private a_ = simde_float64x2_to_private(a);
    simde_float32x2_private r_;

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
      r_.values[i] = simde_vcvtxd_f32_f64(a_.values[i]);
    }

    return simde_float32x2_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES)
  #undef vcvtx_f32_f64
  #define vcvtx_f32_f64(a) simde_vcvtx_f32_f64(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_float32x4_t
simde_vcvtx_high_f32_f64(simde_float32x2_t r, simde_float64x2_t a) {
  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
    return vcvtx_high_f32_f64(r, a);
  #else
    simde_float64x2_private a_ = simde_float64x2_to_private(a);
    simde_float32x2_private r_ = simde_float32x2_to_private(r);
    simde_float32x4_private ret;

    size_t half_pos = (sizeof(ret.values) / sizeof(ret.values[0]) / 2);
    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < half_pos; i++) {
      ret.values[i] = r_.values[i];
    }
    SIMDE_VECTORIZE
    for (size_t i = half_pos; i < (sizeof(ret.values) / sizeof(ret.values[0])) ; i++) {
      ret.values[i] = simde_vcvtxd_f32_f64(a_.values[i-half_pos]);
    }

    return simde_float32x4_from_private(ret);
  #endif
}
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES)
  #undef vcvtx_high_f32_f64
  #define vcvtx_high_f32_f64(r, a) simde_vcvtx_high_f32_f64((r), (a))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_bfloat16x4_t
simde_vcvt_bf16_f32(simde_float32x4_t a) {
  #if defined(SIMDE_ARM_NEON_A32V8_NATIVE) && defined(SIMDE_ARM_NEON_BF16)
    return vcvt_bf16_f32(a);
  #else
    simde_float32x4_private a_ = simde_float32x4_to_private(a);
    simde_bfloat16x4_private r_;

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
      r_.values[i] = simde_bfloat16_from_float32(a_.values[i]);
    }

    return simde_bfloat16x4_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V8_ENABLE_NATIVE_ALIASES)
  #undef vcvt_bf16_f32
  #define vcvt_bf16_f32(a) simde_vcvt_bf16_f32(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_float32x4_t
simde_vcvt_f32_bf16(simde_bfloat16x4_t a) {
  #if defined(SIMDE_ARM_NEON_A32V8_NATIVE) && defined(SIMDE_ARM_NEON_BF16)
    return vcvt_f32_bf16(a);
  #else
    simde_bfloat16x4_private a_ = simde_bfloat16x4_to_private(a);
    simde_float32x4_private r_;

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
      r_.values[i] = simde_bfloat16_to_float32(a_.values[i]);
    }

    return simde_float32x4_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V8_ENABLE_NATIVE_ALIASES)
  #undef vcvt_f32_bf16
  #define vcvt_f32_bf16(a) simde_vcvt_f32_bf16(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_float32_t
simde_vcvtah_f32_bf16(simde_bfloat16_t a) {
  #if defined(SIMDE_ARM_NEON_A32V8_NATIVE) && defined(SIMDE_ARM_NEON_BF16)
    return vcvtah_f32_bf16(a);
  #else
    return simde_bfloat16_to_float32(a);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V8_ENABLE_NATIVE_ALIASES)
  #undef vcvtah_f32_bf16
  #define vcvtah_f32_bf16(a) simde_vcvtah_f32_bf16(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_bfloat16_t
simde_vcvth_bf16_f32(float a) {
  #if defined(SIMDE_ARM_NEON_A32V8_NATIVE) && defined(SIMDE_ARM_NEON_BF16)
    return vcvth_bf16_f32(a);
  #else
    return simde_bfloat16_from_float32(a);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V8_ENABLE_NATIVE_ALIASES)
  #undef vcvth_bf16_f32
  #define vcvth_bf16_f32(a) simde_vcvth_bf16_f32(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_float32x4_t
simde_vcvtq_low_f32_bf16(simde_bfloat16x8_t a) {
  #if defined(SIMDE_ARM_NEON_A32V8_NATIVE) && defined(SIMDE_ARM_NEON_BF16)
    return vcvtq_low_f32_bf16(a);
  #else
    simde_bfloat16x8_private a_ = simde_bfloat16x8_to_private(a);
    simde_float32x4_private r_;

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
      r_.values[i] = simde_bfloat16_to_float32(a_.values[i]);
    }

    return simde_float32x4_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V8_ENABLE_NATIVE_ALIASES)
  #undef vcvtq_low_f32_bf16
  #define vcvtq_low_f32_bf16(a) simde_vcvtq_low_f32_bf16(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_float32x4_t
simde_vcvtq_high_f32_bf16(simde_bfloat16x8_t a) {
  #if defined(SIMDE_ARM_NEON_A32V8_NATIVE) && defined(SIMDE_ARM_NEON_BF16)
    return vcvtq_high_f32_bf16(a);
  #else
    simde_bfloat16x8_private a_ = simde_bfloat16x8_to_private(a);
    simde_float32x4_private r_;

    size_t rsize = (sizeof(r_.values) / sizeof(r_.values[0]));
    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
      r_.values[i] = simde_bfloat16_to_float32(a_.values[i + rsize]);
    }

    return simde_float32x4_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V8_ENABLE_NATIVE_ALIASES)
  #undef vcvtq_high_f32_bf16
  #define vcvtq_high_f32_bf16(a) simde_vcvtq_high_f32_bf16(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_bfloat16x8_t
simde_vcvtq_low_bf16_f32(simde_float32x4_t a) {
  #if defined(SIMDE_ARM_NEON_A32V8_NATIVE) && defined(SIMDE_ARM_NEON_BF16)
    return vcvtq_low_bf16_f32(a);
  #else
    simde_float32x4_private a_ = simde_float32x4_to_private(a);
    simde_bfloat16x8_private r_;

    size_t asize = (sizeof(a_.values) / sizeof(a_.values[0]));
    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < asize; i++) {
      r_.values[i] = simde_bfloat16_from_float32(a_.values[i]);
      r_.values[i + asize] = SIMDE_BFLOAT16_VALUE(0.0);
    }

    return simde_bfloat16x8_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V8_ENABLE_NATIVE_ALIASES)
  #undef vcvtq_low_bf16_f32
  #define vcvtq_low_bf16_f32(a) simde_vcvtq_low_bf16_f32(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_bfloat16x8_t
simde_vcvtq_high_bf16_f32(simde_bfloat16x8_t inactive, simde_float32x4_t a) {
  #if defined(SIMDE_ARM_NEON_A32V8_NATIVE) && defined(SIMDE_ARM_NEON_BF16)
    return vcvtq_high_bf16_f32(inactive, a);
  #else
    simde_bfloat16x8_private inactive_ = simde_bfloat16x8_to_private(inactive);
    simde_float32x4_private a_ = simde_float32x4_to_private(a);
    simde_bfloat16x8_private r_;

    size_t asize = (sizeof(a_.values) / sizeof(a_.values[0]));
    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(a_.values) / sizeof(a_.values[0])) ; i++) {
      r_.values[i] = inactive_.values[i];
      r_.values[i + asize] = simde_bfloat16_from_float32(a_.values[i]);
    }
    return simde_bfloat16x8_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V8_ENABLE_NATIVE_ALIASES)
  #undef vcvtq_high_bf16_f32
  #define vcvtq_high_bf16_f32(inactive, a) simde_vcvtq_high_bf16_f32((inactive), (a))
#endif

SIMDE_END_DECLS_
HEDLEY_DIAGNOSTIC_POP

#endif /* SIMDE_ARM_NEON_CVT_H */
