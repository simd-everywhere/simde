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
 *   2023      Chi-Wei Chu <wewe5215@gapp.nthu.edu.tw> (Copyright owned by NTHU pllab)
 */

#if !defined(SIMDE_ARM_NEON_RNDA_H)
#define SIMDE_ARM_NEON_RNDA_H

#include "types.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

SIMDE_FUNCTION_ATTRIBUTES
simde_float16_t
simde_vrndah_f16(simde_float16_t a) {
  #if defined(SIMDE_ARM_NEON_A32V8_NATIVE) && defined(SIMDE_ARM_NEON_FP16)
    return vrndah_f16(a);
  #else
    return simde_float16_from_float32(simde_math_roundf(simde_float16_to_float32(a)));
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V8_ENABLE_NATIVE_ALIASES)
  #undef vrndah_f16
  #define vrndah_f16(a) simde_vrndah_f16(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_float16x4_t
simde_vrnda_f16(simde_float16x4_t a) {
  #if defined(SIMDE_ARM_NEON_A32V8_NATIVE) && defined(SIMDE_ARM_NEON_FP16)
    return vrnda_f16(a);
  #else
    simde_float16x4_private
      r_,
      a_ = simde_float16x4_to_private(a);
    #if defined(SIMDE_RISCV_V_NATIVE) && defined(SIMDE_ARCH_RISCV_ZVFH)
      r_.sv64 = __riscv_vfcvt_f_x_v_f16m1(__riscv_vfcvt_x_f_v_i16m1_rm(a_.sv64, 0, 4), 4);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
        r_.values[i] = simde_vrndah_f16(a_.values[i]);
      }
    #endif

    return simde_float16x4_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V8_ENABLE_NATIVE_ALIASES)
  #undef vrnda_f16
  #define vrnda_f16(a) simde_vrnda_f16(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_float32x2_t
simde_vrnda_f32(simde_float32x2_t a) {
  #if defined(SIMDE_ARM_NEON_A32V8_NATIVE)
    return vrnda_f32(a);
  #else
    simde_float32x2_private
      r_,
      a_ = simde_float32x2_to_private(a);

    #if defined(SIMDE_RISCV_V_NATIVE)
      #if defined(SIMDE_FAST_NANS)
        r_.sv64 = __riscv_vfcvt_f_x_v_f32m1(__riscv_vfcvt_x_f_v_i32m1_rm(a_.sv64, 0, 2), 2);
      #else
        simde_float32 nan = SIMDE_MATH_NAN;
        vbool32_t mask = __riscv_vmseq_vx_u32m1_b32(__riscv_vfclass_v_u32m1(a_.sv64 , 2) , 512 , 2);
        r_.sv64 = __riscv_vfmerge_vfm_f32m1(__riscv_vfcvt_f_x_v_f32m1(__riscv_vfcvt_x_f_v_i32m1_rm(a_.sv64, 0, 2), 2), \
                  nan, mask, 2);
      #endif
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
        r_.values[i] = simde_math_roundf(a_.values[i]);
      }
    #endif

    return simde_float32x2_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V8_ENABLE_NATIVE_ALIASES)
  #undef vrnda_f32
  #define vrnda_f32(a) simde_vrnda_f32(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_float64x1_t
simde_vrnda_f64(simde_float64x1_t a) {
  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
    return vrnda_f64(a);
  #else
    simde_float64x1_private
      r_,
      a_ = simde_float64x1_to_private(a);

    #if defined(SIMDE_RISCV_V_NATIVE)
      #if defined(SIMDE_FAST_NANS)
        r_.sv64 = __riscv_vfcvt_f_x_v_f64m1(__riscv_vfcvt_x_f_v_i64m1_rm(a_.sv64, 0, 1), 1);
      #else
        simde_float64 nan = SIMDE_MATH_NAN;
        vbool64_t mask = __riscv_vmseq_vx_u64m1_b64(__riscv_vfclass_v_u64m1(a_.sv64 , 1) , 512 , 1);
        r_.sv64 = __riscv_vfmerge_vfm_f64m1(__riscv_vfcvt_f_x_v_f64m1(__riscv_vfcvt_x_f_v_i64m1_rm(a_.sv64, 0, 1), 1), \
                  nan, mask, 1);
      #endif
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
        r_.values[i] = simde_math_round(a_.values[i]);
      }
    #endif

    return simde_float64x1_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES)
  #undef vrnda_f64
  #define vrnda_f64(a) simde_vrnda_f64(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_float16x8_t
simde_vrndaq_f16(simde_float16x8_t a) {
  #if defined(SIMDE_ARM_NEON_A32V8_NATIVE) && defined(SIMDE_ARM_NEON_FP16)
    return vrndaq_f16(a);
  #else
    simde_float16x8_private
      r_,
      a_ = simde_float16x8_to_private(a);
    #if defined(SIMDE_RISCV_V_NATIVE) && defined(SIMDE_ARCH_RISCV_ZVFH)
      r_.sv128 = __riscv_vfcvt_f_x_v_f16m1(__riscv_vfcvt_x_f_v_i16m1_rm(a_.sv128, 0, 8), 8);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
        r_.values[i] = simde_vrndah_f16(a_.values[i]);
      }
    #endif

    return simde_float16x8_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V8_ENABLE_NATIVE_ALIASES)
  #undef vrndaq_f16
  #define vrndaq_f16(a) simde_vrndaq_f16(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_float32x4_t
simde_vrndaq_f32(simde_float32x4_t a) {
  #if defined(SIMDE_ARM_NEON_A32V8_NATIVE)
    return vrndaq_f32(a);
  #else
    simde_float32x4_private
      r_,
      a_ = simde_float32x4_to_private(a);

    #if defined(SIMDE_RISCV_V_NATIVE)
      #if defined(SIMDE_FAST_NANS)
        r_.sv128 = __riscv_vfcvt_f_x_v_f32m1(__riscv_vfcvt_x_f_v_i32m1_rm(a_.sv128, 0, 4), 4);
      #else
        simde_float32 nan = SIMDE_MATH_NAN;
        vbool32_t mask = __riscv_vmseq_vx_u32m1_b32(__riscv_vfclass_v_u32m1(a_.sv128 , 4) , 512 , 4);
        r_.sv128 = __riscv_vfmerge_vfm_f32m1(__riscv_vfcvt_f_x_v_f32m1(__riscv_vfcvt_x_f_v_i32m1_rm(a_.sv128, 0, 4), 4), \
                  nan, mask, 4);
      #endif
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
        r_.values[i] = simde_math_roundf(a_.values[i]);
      }
    #endif

    return simde_float32x4_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V8_ENABLE_NATIVE_ALIASES)
  #undef vrndaq_f32
  #define vrndaq_f32(a) simde_vrndaq_f32(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_float64x2_t
simde_vrndaq_f64(simde_float64x2_t a) {
  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
    return vrndaq_f64(a);
  #else
    simde_float64x2_private
      r_,
      a_ = simde_float64x2_to_private(a);

    #if defined(SIMDE_RISCV_V_NATIVE)
      #if defined(SIMDE_FAST_NANS)
        r_.sv128 = __riscv_vfcvt_f_x_v_f64m1(__riscv_vfcvt_x_f_v_i64m1_rm(a_.sv128, 0, 2), 2);
      #else
        simde_float64 nan = SIMDE_MATH_NAN;
        vbool64_t mask = __riscv_vmseq_vx_u64m1_b64(__riscv_vfclass_v_u64m1(a_.sv128 , 2) , 512 , 2);
        r_.sv128 = __riscv_vfmerge_vfm_f64m1(__riscv_vfcvt_f_x_v_f64m1(__riscv_vfcvt_x_f_v_i64m1_rm(a_.sv128, 0, 2), 2), \
                  nan, mask, 2);
      #endif
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
        r_.values[i] = simde_math_round(a_.values[i]);
      }
    #endif

    return simde_float64x2_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES)
  #undef vrndaq_f64
  #define vrndaq_f64(a) simde_vrndaq_f64(a)
#endif

SIMDE_END_DECLS_
HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_ARM_NEON_RNDA_H) */
