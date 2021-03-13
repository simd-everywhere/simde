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
 *   2021      Atharva Nimbalkar <atharvakn@gmail.com>
 */

 #if !defined(SIMDE_ARM_NEON_CMLA_H)
 #define SIMDE_ARM_NEON_CMLA_H

 #include "types.h"

 HEDLEY_DIAGNOSTIC_PUSH
 SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
 SIMDE_BEGIN_DECLS_

 /* * rot 0 * */

 SIMDE_FUNCTION_ATTRIBUTES
 simde_float32x2_t
 simde_vcmla_f32(simde_float32x2_t r, simde_float32x2_t a, simde_float32x2_t b) {
   #if defined(SIMDE_ARM_NEON_A32V8_NATIVE)
    return vcmla_f32(r, a, b);
   #else
    simde_float32x2_private
      r_ = simde_float32x2_to_private(r),
      a_ = simde_float32x2_to_private(a),
      b_ = simde_float32x2_to_private(b);

    SIMDE_VECTORIZE
    for(size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
      if(i % 2 == 0)
        r_.values[i] += b_.values[i] * a_.values[i];
      else
        r_.values[i] += b_.values[i] * a_.values[i-1];
    }

    return simde_float32x2_from_private(r_);
   #endif
 }
 #if defined(SIMDE_ARM_NEON_A32V8_ENABLE_NATIVE_ALIASES)
   #undef vcmla_f32
   #define vcmla_f32(r, a, b) simde_vcmla_f32(r, a, b)
 #endif

 SIMDE_FUNCTION_ATTRIBUTES
 simde_float32x4_t
 simde_vcmlaq_f32(simde_float32x4_t r, simde_float32x4_t a, simde_float32x4_t b) {
   #if defined(SIMDE_ARM_NEON_A32V8_NATIVE)
    return vcmlaq_f32(r, a, b);
   #else
    simde_float32x4_private
      r_ = simde_float32x4_to_private(r),
      a_ = simde_float32x4_to_private(a),
      b_ = simde_float32x4_to_private(b);

    SIMDE_VECTORIZE
    for(size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
      if(i % 2 == 0)
        r_.values[i] += b_.values[i] * a_.values[i];
      else
        r_.values[i] += b_.values[i] * a_.values[i-1];
    }

    return simde_float32x4_from_private(r_);
   #endif
 }
 #if defined(SIMDE_ARM_NEON_A32V8_ENABLE_NATIVE_ALIASES)
   #undef vcmlaq_f32
   #define vcmlaq_f32(r, a, b) simde_vcmlaq_f32(r, a, b)
 #endif

 SIMDE_FUNCTION_ATTRIBUTES
 simde_float64x2_t
 simde_vcmlaq_f64(simde_float64x2_t r, simde_float64x2_t a, simde_float64x2_t b) {
   #if defined(SIMDE_ARM_NEON_A32V8_NATIVE)
    return vcmlaq_f64(r, a, b);
   #else
    simde_float64x2_private
      r_ = simde_float64x2_to_private(r),
      a_ = simde_float64x2_to_private(a),
      b_ = simde_float64x2_to_private(b);

    SIMDE_VECTORIZE
    for(size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
      if(i % 2 == 0)
        r_.values[i] += b_.values[i] * a_.values[i];
      else
        r_.values[i] += b_.values[i] * a_.values[i-1];
    }

    return simde_float64x2_from_private(r_);
   #endif
 }
 #if defined(SIMDE_ARM_NEON_A32V8_ENABLE_NATIVE_ALIASES)
   #undef vcmlaq_f64
   #define vcmlaq_f64(r, a, b) simde_vcmlaq_f64(r, a, b)
 #endif

 /* * rot 90 * */

 SIMDE_FUNCTION_ATTRIBUTES
 simde_float32x2_t
 simde_vcmla_rot90_f32(simde_float32x2_t r, simde_float32x2_t a, simde_float32x2_t b) {
   #if defined(SIMDE_ARM_NEON_A32V8_NATIVE)
    return vcmla_rot90_f32(r, a, b);
   #else
    simde_float32x2_private
      r_ = simde_float32x2_to_private(r),
      a_ = simde_float32x2_to_private(a),
      b_ = simde_float32x2_to_private(b);

    SIMDE_VECTORIZE
    for(size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
      if(i % 2 == 0)
        r_.values[i] += -(b_.values[i+1]) * a_.values[i+1];
      else
        r_.values[i] += b_.values[i-1] * a_.values[i];
    }

    return simde_float32x2_from_private(r_);
   #endif
 }
 #if defined(SIMDE_ARM_NEON_A32V8_ENABLE_NATIVE_ALIASES)
   #undef vcmla_rot90_f32
   #define vcmla_rot90_f32(r, a, b) simde_vcmla_rot90_f32(r, a, b)
 #endif

 SIMDE_FUNCTION_ATTRIBUTES
 simde_float32x4_t
 simde_vcmlaq_rot90_f32(simde_float32x4_t r, simde_float32x4_t a, simde_float32x4_t b) {
   #if defined(SIMDE_ARM_NEON_A32V8_NATIVE)
    return vcmlaq_rot90_f32(r, a, b);
   #else
    simde_float32x4_private
      r_ = simde_float32x4_to_private(r),
      a_ = simde_float32x4_to_private(a),
      b_ = simde_float32x4_to_private(b);

    SIMDE_VECTORIZE
    for(size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
      if(i % 2 == 0)
        r_.values[i] += -(b_.values[i+1]) * a_.values[i+1];
      else
        r_.values[i] += b_.values[i-1] * a_.values[i];
    }

    return simde_float32x4_from_private(r_);
   #endif
 }
 #if defined(SIMDE_ARM_NEON_A32V8_ENABLE_NATIVE_ALIASES)
   #undef vcmlaq_rot90_f32
   #define vcmlaq_rot90_f32(r, a, b) simde_vcmlaq_rot90_f32(r, a, b)
 #endif

 SIMDE_FUNCTION_ATTRIBUTES
 simde_float64x2_t
 simde_vcmlaq_rot90_f64(simde_float64x2_t r, simde_float64x2_t a, simde_float64x2_t b) {
   #if defined(SIMDE_ARM_NEON_A32V8_NATIVE)
    return vcmlaq_rot90_f64(r, a, b);
   #else
    simde_float64x2_private
      r_ = simde_float64x2_to_private(r),
      a_ = simde_float64x2_to_private(a),
      b_ = simde_float64x2_to_private(b);

    SIMDE_VECTORIZE
    for(size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
      if(i % 2 == 0)
        r_.values[i] += -(b_.values[i+1]) * a_.values[i+1];
      else
        r_.values[i] += b_.values[i-1] * a_.values[i];
    }

    return simde_float64x2_from_private(r_);
   #endif
 }
 #if defined(SIMDE_ARM_NEON_A32V8_ENABLE_NATIVE_ALIASES)
   #undef vcmlaq_rot90_f64
   #define vcmlaq_rot90_f64(r, a, b) simde_vcmlaq_rot90_f64(r, a, b)
 #endif

 /* * rot 180 * */

 SIMDE_FUNCTION_ATTRIBUTES
 simde_float32x2_t
 simde_vcmla_rot180_f32(simde_float32x2_t r, simde_float32x2_t a, simde_float32x2_t b) {
   #if defined(SIMDE_ARM_NEON_A32V8_NATIVE)
    return vcmla_rot180_f32(r, a, b);
   #else
    simde_float32x2_private
      r_ = simde_float32x2_to_private(r),
      a_ = simde_float32x2_to_private(a),
      b_ = simde_float32x2_to_private(b);

    SIMDE_VECTORIZE
    for(size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
      if(i % 2 == 0)
        r_.values[i] += -(b_.values[i]) * a_.values[i];
      else
        r_.values[i] += -(b_.values[i]) * a_.values[i-1];
    }

    return simde_float32x2_from_private(r_);
   #endif
 }
 #if defined(SIMDE_ARM_NEON_A32V8_ENABLE_NATIVE_ALIASES)
   #undef vcmla_rot180_f32
   #define vcmla_rot180_f32(r, a, b) simde_vcmla_rot180_f32(r, a, b)
 #endif

 SIMDE_FUNCTION_ATTRIBUTES
 simde_float32x4_t
 simde_vcmlaq_rot180_f32(simde_float32x4_t r, simde_float32x4_t a, simde_float32x4_t b) {
   #if defined(SIMDE_ARM_NEON_A32V8_NATIVE)
    return vcmlaq_rot180_f32(r, a, b);
   #else
    simde_float32x4_private
      r_ = simde_float32x4_to_private(r),
      a_ = simde_float32x4_to_private(a),
      b_ = simde_float32x4_to_private(b);

    SIMDE_VECTORIZE
    for(size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
      if(i % 2 == 0)
        r_.values[i] += -(b_.values[i]) * a_.values[i];
      else
        r_.values[i] += -(b_.values[i]) * a_.values[i-1];
    }

    return simde_float32x4_from_private(r_);
   #endif
 }
 #if defined(SIMDE_ARM_NEON_A32V8_ENABLE_NATIVE_ALIASES)
   #undef vcmlaq_rot180_f32
   #define vcmlaq_rot180_f32(r, a, b) simde_vcmlaq_rot180_f32(r, a, b)
 #endif

 SIMDE_FUNCTION_ATTRIBUTES
 simde_float64x2_t
 simde_vcmlaq_rot180_f64(simde_float64x2_t r, simde_float64x2_t a, simde_float64x2_t b) {
   #if defined(SIMDE_ARM_NEON_A32V8_NATIVE)
    return vcmlaq_rot180_f64(r, a, b);
   #else
    simde_float64x2_private
      r_ = simde_float64x2_to_private(r),
      a_ = simde_float64x2_to_private(a),
      b_ = simde_float64x2_to_private(b);

    SIMDE_VECTORIZE
    for(size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
      if(i % 2 == 0)
        r_.values[i] += -(b_.values[i]) * a_.values[i];
      else
        r_.values[i] += -(b_.values[i]) * a_.values[i-1];
    }

    return simde_float64x2_from_private(r_);
   #endif
 }
 #if defined(SIMDE_ARM_NEON_A32V8_ENABLE_NATIVE_ALIASES)
   #undef vcmlaq_rot180_f64
   #define vcmlaq_rot180_f64(r, a, b) simde_vcmlaq_rot180_f64(r, a, b)
 #endif

 /* * rot 270 * */

 SIMDE_FUNCTION_ATTRIBUTES
 simde_float32x2_t
 simde_vcmla_rot270_f32(simde_float32x2_t r, simde_float32x2_t a, simde_float32x2_t b) {
   #if defined(SIMDE_ARM_NEON_A32V8_NATIVE)
    return vcmla_rot270_f32(r, a, b);
   #else
    simde_float32x2_private
      r_ = simde_float32x2_to_private(r),
      a_ = simde_float32x2_to_private(a),
      b_ = simde_float32x2_to_private(b);

    SIMDE_VECTORIZE
    for(size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
      if(i % 2 == 0)
        r_.values[i] += b_.values[i+1] * a_.values[i+1];
      else
        r_.values[i] += -(b_.values[i-1]) * a_.values[i];
    }

    return simde_float32x2_from_private(r_);
   #endif
 }
 #if defined(SIMDE_ARM_NEON_A32V8_ENABLE_NATIVE_ALIASES)
   #undef vcmla_rot270_f32
   #define vcmla_rot270_f32(r, a, b) simde_vcmla_rot270_f32(r, a, b)
 #endif

 SIMDE_FUNCTION_ATTRIBUTES
 simde_float32x4_t
 simde_vcmlaq_rot270_f32(simde_float32x4_t r, simde_float32x4_t a, simde_float32x4_t b) {
   #if defined(SIMDE_ARM_NEON_A32V8_NATIVE)
    return vcmlaq_rot270_f32(r, a, b);
   #else
    simde_float32x4_private
      r_ = simde_float32x4_to_private(r),
      a_ = simde_float32x4_to_private(a),
      b_ = simde_float32x4_to_private(b);

    SIMDE_VECTORIZE
    for(size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
      if(i % 2 == 0)
        r_.values[i] += b_.values[i+1] * a_.values[i+1];
      else
        r_.values[i] += -(b_.values[i-1]) * a_.values[i];
    }

    return simde_float32x4_from_private(r_);
   #endif
 }
 #if defined(SIMDE_ARM_NEON_A32V8_ENABLE_NATIVE_ALIASES)
   #undef vcmlaq_rot270_f32
   #define vcmlaq_rot270_f32(r, a, b) simde_vcmlaq_rot270_f32(r, a, b)
 #endif

 SIMDE_FUNCTION_ATTRIBUTES
 simde_float64x2_t
 simde_vcmlaq_rot270_f64(simde_float64x2_t r, simde_float64x2_t a, simde_float64x2_t b) {
   #if defined(SIMDE_ARM_NEON_A32V8_NATIVE)
    return vcmlaq_rot270_f64(r, a, b);
   #else
    simde_float64x2_private
      r_ = simde_float64x2_to_private(r),
      a_ = simde_float64x2_to_private(a),
      b_ = simde_float64x2_to_private(b);

    SIMDE_VECTORIZE
    for(size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
      if(i % 2 == 0)
        r_.values[i] += b_.values[i+1] * a_.values[i+1];
      else
        r_.values[i] += -(b_.values[i-1]) * a_.values[i];
    }

    return simde_float64x2_from_private(r_);
   #endif
 }
 #if defined(SIMDE_ARM_NEON_A32V8_ENABLE_NATIVE_ALIASES)
   #undef vcmlaq_rot270_f64
   #define vcmlaq_rot270_f64(r, a, b) simde_vcmlaq_rot270_f64(r, a, b)
 #endif

 SIMDE_END_DECLS_
 HEDLEY_DIAGNOSTIC_POP

 #endif /* !defined(SIMDE_ARM_NEON_CMLA_H) */
