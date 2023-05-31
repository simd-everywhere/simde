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
 *   2021      Décio Luiz Gazzoni Filho <decio@decpp.net>
 */

#if !defined(SIMDE_ARM_NEON_MLSL_HIGH_N_H)
#define SIMDE_ARM_NEON_MLSL_HIGH_N_H

#include "get_high.h"
#include "mlsl_n.h"
#include "types.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

SIMDE_FUNCTION_ATTRIBUTES
simde_int32x4_t
simde_vmlsl_high_n_s16(simde_int32x4_t a, simde_int16x8_t b, int16_t c) {
  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
    return vmlsl_high_n_s16(a, b, c);
  #else
    return simde_vmlsl_n_s16(a, simde_vget_high_s16(b), c);
  #endif
}
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES)
  #undef vmlsl_high_n_s16
  #define vmlsl_high_n_s16(a, b, c) simde_vmlsl_high_n_s16((a), (b), (c))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_int64x2_t
simde_vmlsl_high_n_s32(simde_int64x2_t a, simde_int32x4_t b, int32_t c) {
  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
    return vmlsl_high_n_s32(a, b, c);
  #else
    return simde_vmlsl_n_s32(a, simde_vget_high_s32(b), c);
  #endif
}
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES)
  #undef vmlsl_high_n_s32
  #define vmlsl_high_n_s32(a, b, c) simde_vmlsl_high_n_s32((a), (b), (c))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint32x4_t
simde_vmlsl_high_n_u16(simde_uint32x4_t a, simde_uint16x8_t b, uint16_t c) {
  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
    return vmlsl_high_n_u16(a, b, c);
  #else
    return simde_vmlsl_n_u16(a, simde_vget_high_u16(b), c);
  #endif
}
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES)
  #undef vmlsl_high_n_u16
  #define vmlsl_high_n_u16(a, b, c) simde_vmlsl_high_n_u16((a), (b), (c))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint64x2_t
simde_vmlsl_high_n_u32(simde_uint64x2_t a, simde_uint32x4_t b, uint32_t c) {
  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
    return vmlsl_high_n_u32(a, b, c);
  #else
    return simde_vmlsl_n_u32(a, simde_vget_high_u32(b), c);
  #endif
}
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES)
  #undef vmlsl_high_n_u32
  #define vmlsl_high_n_u32(a, b, c) simde_vmlsl_high_n_u32((a), (b), (c))
#endif

SIMDE_END_DECLS_
HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_ARM_NEON_MLSL_HIGH_N_H) */
