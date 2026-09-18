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
 *   2025      Russell Graves <rgraves@sevarg.net>
 */

/*
 * This file is an attempt to solve the problem of "Exact ARM NaNs" in a sane,
 * performant way.  For most use cases, a NaN is a NaN - as long as it reflects
 * that properly, and as long as valid math is correct, there is no problem.
 * However, some use cases require accurate NaN generation that matches the
 * reference hardware, even at the cost of some performance.
 * 
 * To achieve this, while still allowing full vector acceleration of the
 * operations when possible, the NaN checking is bolted on at the end.  After
 * results are created, this implementation checks the input operands for NaN
 * values, and, if any are present, properly propagates them per the rules of
 * NaN propagation in the ARMv8 ISA manual.
 * 
 * General rules of operation:
 * - If at least one operand is a signaling NaN, the first signaling NaN is
 *     quieted and output.
 * - If at least one operand is a NaN but none of the operands are signaling,
 *     the first NaN is output.
 * - If only one input is a NaN, a quiet NaN derived from the input is output.
 * 
 * Certain instructions may behave differently, and this will be documented in
 * the instruction implementation notes.  FMAX* and FMIN* are examples.
 * 
 * For ARM (and x86), a quiet NaN is derived from a signaling NaN by setting the
 * most significant bit of the fractional part to 1.
 * 
 * Note that this system is still reliant on the hardware behavior to generate
 * the initial NaN, so this should be tested if you rely on it.  This set of
 * functions only handles proper NaN propagation per the ARM spec.
 * 
 * Open questions:
 * - Should this be gated on SIMDE_FAST_NANS, or SIMDE_NO_FAST_NANS?
 */

#if !defined(SIMDE_ARM_NEON_ARM_NAN_H)
#define SIMDE_ARM_NEON_ARM_NAN_H

#include "types.h"

#include "../../x86/sse2.h"
#include "../../x86/sse4.1.h"
#include "../../x86/sse4.2.h"

// These bits are set to quiet a signaling NaN.
#define SIMDE_ARM_QUIET_NAN32 0x00400000
#define SIMDE_ARM_QUIET_NAN64 0x0008000000000000

/*
 * If either operand is signaling, that one is quieted and propagated.  Else the
 * first NaN operand is propagated.  Unions are solve reading floating point as
 * binary, not a number.
 */
SIMDE_FUNCTION_ATTRIBUTES simde_float32_t
simde_propagate_arm_nan_f32(simde_float32_t a, simde_float32_t b) {
  union {
    simde_float32_t f;
    uint32_t u;
  } a_c, b_c;

  a_c.f = a;
  b_c.f = b;

  // Only A is NaN, return it.
  if (simde_math_isnanf(a) && !simde_math_isnanf(b)) {
    a_c.u |= SIMDE_ARM_QUIET_NAN32;
    return a_c.f;
  }
  // Only B is NaN, return it.
  else if (!simde_math_isnanf(a) && simde_math_isnanf(b)) {
    b_c.u |= SIMDE_ARM_QUIET_NAN32;
    return b_c.f;
  }

  // Both are NaN, so apply priority rules.
  // If A is signaling, quiet it and return it.
  if (!(a_c.u & SIMDE_ARM_QUIET_NAN32)) {
    a_c.u |= SIMDE_ARM_QUIET_NAN32;
    return a_c.f;
  }
  // If B is signaling, quiet it and return it.
  else if (!(b_c.u & SIMDE_ARM_QUIET_NAN32)) {
    b_c.u |= SIMDE_ARM_QUIET_NAN32;
    return b_c.f;
  }
  // Otherwise quiet and return the first operand.
  else {
    a_c.u |= SIMDE_ARM_QUIET_NAN32;
    return a_c.f;
  }
}

// Same rules as above.
SIMDE_FUNCTION_ATTRIBUTES float64_t simde_propagate_arm_nan_f64(float64_t a,
                                                                float64_t b) {
  union f {
    simde_float64_t f;
    uint64_t u;
  } a_c, b_c;

  a_c.f = a;
  b_c.f = b;

  if (simde_math_isnanf(a) && !simde_math_isnanf(b)) {
    a_c.u |= SIMDE_ARM_QUIET_NAN64;
    return a_c.f;
  } else if (!simde_math_isnanf(a) && simde_math_isnanf(b)) {
    b_c.u |= SIMDE_ARM_QUIET_NAN64;
    return b_c.f;
  }
  if (!(a_c.u & SIMDE_ARM_QUIET_NAN64)) {
    a_c.u |= SIMDE_ARM_QUIET_NAN64;
    return a_c.f;
  } else if (!(b_c.u & SIMDE_ARM_QUIET_NAN64)) {
    b_c.u |= SIMDE_ARM_QUIET_NAN64;
    return b_c.f;
  } else {
    a_c.u |= SIMDE_ARM_QUIET_NAN64;
    return a_c.f;
  }
}

/*
 * This is a vectorized set of utility functions to look for NaNs in input
 * operands.  If the NaN behavior is enabled, this will be used on every
 * operation, so ought be fairly fast.  This simply checks to see if the values
 * in the input operands are NaN, by masking and checking to see if the results
 * are > the minimum NaN value (0x7F800000 is infinity, 0x7F800001 is NaN).
 * 
 * If any of the inputs are NaN, the output rewritten for those elements,
 * otherwise the existing output is used.
 */
SIMDE_FUNCTION_ATTRIBUTES simde_float32x4_private
arm_nan_eval_float32x4_internal(simde_float32x4_t a, simde_float32x4_t b,
                                simde_float32x4_private r_, simde_bool q) {
  const simde__m128i mask = simde_mm_set1_epi32(~0x80000000);
  const simde__m128i comparef32 = simde_mm_set1_epi32(0x7F800000);

  simde__m128i masked1 = simde_mm_and_si128(mask, (simde__m128i)a);
  simde__m128i masked2 = simde_mm_and_si128(mask, (simde__m128i)b);

  simde__m128i result1 = simde_mm_cmpgt_epi32(masked1, comparef32);
  simde__m128i result2 = simde_mm_cmpgt_epi32(masked2, comparef32);

  if (HEDLEY_UNLIKELY(!simde_mm_testz_si128(result1, result1) ||
      !simde_mm_testz_si128(result2, result2))) {
    simde_float32x4_private a_ = simde_float32x4_to_private(a),
                            b_ = simde_float32x4_to_private(b);

    for (size_t i = 0;
         i < ((sizeof(r_.values) / sizeof(r_.values[0])) / (q ? 1 : 2)); i++) {
      if (HEDLEY_UNLIKELY(simde_math_isnanf(a_.values[i]) ||
                          simde_math_isnanf(b_.values[i])))
        r_.values[i] = simde_propagate_arm_nan_f32(a_.values[i], b_.values[i]);
    }
  }

  return r_;
}

SIMDE_FUNCTION_ATTRIBUTES simde_float32x4_private arm_nan_eval_float32x4(
    simde_float32x4_t a, simde_float32x4_t b, simde_float32x4_private r_) {
  return arm_nan_eval_float32x4_internal(a, b, r_, 1);
}

SIMDE_FUNCTION_ATTRIBUTES simde_float32x2_private arm_nan_eval_float32x2(
    simde_float32x2_t a, simde_float32x2_t b, simde_float32x2_private r_) {
  simde_float32x4_t a4, b4;
  simde_float32x4_private r4_;

  // Ensure that there are not false NaNs - they are slow!
  simde_memset(&a4, 0, sizeof(a4));
  simde_memset(&b4, 0, sizeof(b4));
  simde_memset(&r4_, 0, sizeof(r4_));

  simde_memcpy(&a4, &a, sizeof(a));
  simde_memcpy(&b4, &b, sizeof(b));
  simde_memcpy(&r4_, &r_, sizeof(r_));

  r4_ = arm_nan_eval_float32x4_internal(a4, b4, r4_, 0);

  simde_memcpy(&r_, &r4_, sizeof(r_));

  return r_;
}

SIMDE_FUNCTION_ATTRIBUTES simde_float64x2_private
arm_nan_eval_float64x2_internal(simde_float64x2_t a, simde_float64x2_t b,
                                simde_float64x2_private r_, simde_bool q) {
  const simde__m128i mask = simde_mm_set1_epi64x(~0x8000000000000000);
  const simde__m128i comparef32 = simde_mm_set1_epi64x(0x7FF0000000000000);

  simde__m128i masked1 = simde_mm_and_si128(mask, (simde__m128i)a);
  simde__m128i masked2 = simde_mm_and_si128(mask, (simde__m128i)b);

  simde__m128i result1 = simde_mm_cmpgt_epi64(masked1, comparef32);
  simde__m128i result2 = simde_mm_cmpgt_epi64(masked2, comparef32);

  if (HEDLEY_UNLIKELY(!simde_mm_testz_si128(result1, result1) ||
      !simde_mm_testz_si128(result2, result2))) {
    simde_float64x2_private a_ = simde_float64x2_to_private(a),
                            b_ = simde_float64x2_to_private(b);

    for (size_t i = 0;
         i < ((sizeof(r_.values) / sizeof(r_.values[0])) / (q ? 1 : 2)); i++) {
      if (HEDLEY_UNLIKELY(simde_math_isnanf(a_.values[i]) ||
                          simde_math_isnanf(b_.values[i])))
        r_.values[i] = simde_propagate_arm_nan_f64(a_.values[i], b_.values[i]);
    }
  }

  return r_;
}

SIMDE_FUNCTION_ATTRIBUTES simde_float64x2_private arm_nan_eval_float64x2(
    simde_float64x2_t a, simde_float64x2_t b, simde_float64x2_private r_) {
  return arm_nan_eval_float64x2_internal(a, b, r_, 1);
}

SIMDE_FUNCTION_ATTRIBUTES simde_float64x1_private arm_nan_eval_float64x1(
    simde_float64x1_t a, simde_float64x1_t b, simde_float64x1_private r_) {
  simde_float64x2_t a4, b4;
  simde_float64x2_private r4_;

  simde_memset(&a4, 0, sizeof(a4));
  simde_memset(&b4, 0, sizeof(b4));
  simde_memset(&r4_, 0, sizeof(r4_));

  simde_memcpy(&a4, &a, sizeof(a));
  simde_memcpy(&b4, &b, sizeof(b));
  simde_memcpy(&r4_, &r_, sizeof(r_));

  r4_ = arm_nan_eval_float64x2_internal(a4, b4, r4_, 0);

  simde_memcpy(&r_, &r4_, sizeof(r_));

  return r_;
}

#undef SIMDE_ARM_QUIET_NAN32
#undef SIMDE_ARM_QUIET_NAN64

#endif // SIMDE_ARM_NEON_ARM_NAN_H