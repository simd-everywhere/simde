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

#if !defined(SIMDE_ARM_NEON_FMS_N_H)
#define SIMDE_ARM_NEON_FMS_N_H

#include "types.h"
#include "dup_n.h"
#include "fms.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

SIMDE_FUNCTION_ATTRIBUTES
simde_float16x4_t
simde_vfms_n_f16(simde_float16x4_t a, simde_float16x4_t b, simde_float16_t c) {
  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE) && defined(SIMDE_ARCH_ARM_FMA) && (!defined(__clang__) || SIMDE_DETECT_CLANG_VERSION_CHECK(7,0,0)) && !defined(SIMDE_BUG_GCC_95399) && defined(SIMDE_ARM_NEON_FP16)
    return vfms_n_f16(a, b, c);
  #else
    return simde_vfms_f16(a, b, simde_vdup_n_f16(c));
  #endif
}
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES)
  #undef vfms_n_f16
  #define vfms_n_f16(a, b, c) simde_vfms_n_f16(a, b, c)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_float16x8_t
simde_vfmsq_n_f16(simde_float16x8_t a, simde_float16x8_t b, simde_float16_t c) {
  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE) && defined(SIMDE_ARCH_ARM_FMA) && (!defined(__clang__) || SIMDE_DETECT_CLANG_VERSION_CHECK(7,0,0)) && !defined(SIMDE_BUG_GCC_95399) && defined(SIMDE_ARM_NEON_FP16)
    return vfmsq_n_f16(a, b, c);
  #else
    return simde_vfmsq_f16(a, b, simde_vdupq_n_f16(c));
  #endif
}
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES)
  #undef vfmsq_n_f16
  #define vfmsq_n_f16(a, b, c) simde_vfmsq_n_f16(a, b, c)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_float32x2_t
simde_vfms_n_f32(simde_float32x2_t a, simde_float32x2_t b, simde_float32_t c) {
  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE) && defined(SIMDE_ARCH_ARM_FMA) && (!defined(__clang__) || SIMDE_DETECT_CLANG_VERSION_CHECK(7,0,0)) && !defined(SIMDE_BUG_GCC_95399)
    return vfms_n_f32(a, b, c);
  #else
    return simde_vfms_f32(a, b, simde_vdup_n_f32(c));
  #endif
}
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES)
  #undef vfms_n_f32
  #define vfms_n_f32(a, b, c) simde_vfms_n_f32(a, b, c)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_float64x1_t
simde_vfms_n_f64(simde_float64x1_t a, simde_float64x1_t b, simde_float64_t c) {
  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE) && defined(SIMDE_ARCH_ARM_FMA) && (!defined(__clang__) || SIMDE_DETECT_CLANG_VERSION_CHECK(7,0,0))
    return vfms_n_f64(a, b, c);
  #else
    return simde_vfms_f64(a, b, simde_vdup_n_f64(c));
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vfms_n_f64
  #define vfms_n_f64(a, b, c) simde_vfms_n_f64(a, b, c)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_float32x4_t
simde_vfmsq_n_f32(simde_float32x4_t a, simde_float32x4_t b, simde_float32_t c) {
  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE) && defined(SIMDE_ARCH_ARM_FMA) && (!defined(__clang__) || SIMDE_DETECT_CLANG_VERSION_CHECK(7,0,0)) && !defined(SIMDE_BUG_GCC_95399)
    return vfmsq_n_f32(a, b, c);
  #else
    return simde_vfmsq_f32(a, b, simde_vdupq_n_f32(c));
  #endif
}
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES)
  #undef vfmsq_n_f32
  #define vfmsq_n_f32(a, b, c) simde_vfmsq_n_f32(a, b, c)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_float64x2_t
simde_vfmsq_n_f64(simde_float64x2_t a, simde_float64x2_t b, simde_float64_t c) {
  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE) && defined(SIMDE_ARCH_ARM_FMA) && (!defined(__clang__) || SIMDE_DETECT_CLANG_VERSION_CHECK(7,0,0))
    return vfmsq_n_f64(a, b, c);
  #else
    return simde_vfmsq_f64(a, b, simde_vdupq_n_f64(c));
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vfmsq_n_f64
  #define vfmsq_n_f64(a, b, c) simde_vfmsq_n_f64(a, b, c)
#endif

SIMDE_END_DECLS_
HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_ARM_NEON_FMS_N_H) */
