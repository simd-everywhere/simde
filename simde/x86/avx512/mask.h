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
 *   2021      Andrew Rodriguez <anrodriguez@linkedin.com>
 */

#if !defined(SIMDE_X86_AVX512_MASK_H)
#define SIMDE_X86_AVX512_MASK_H

#include "types.h"
#include "mov.h"
#include "mov_mask.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

SIMDE_FUNCTION_ATTRIBUTES
simde__mmask8
simde_kor_mask8(simde__mmask8 a, simde__mmask8 b) {
  #if defined(SIMDE_X86_AVX512DQ_NATIVE)
    return _kor_mask8(a, b);
  #else
    return a | b;
  #endif
}
#if defined(SIMDE_X86_AVX512DQ_ENABLE_NATIVE_ALIASES)
  #undef _kor_mask8
  #define _kor_mask8(a, b) simde_kor_mask8(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__mmask8
simde_knot_mask8(simde__mmask8 a) {
  #if defined(SIMDE_X86_AVX512DQ_NATIVE)
    return _knot_mask8(a);
  #else
    return ~a;
  #endif
}
#if defined(SIMDE_X86_AVX512DQ_ENABLE_NATIVE_ALIASES)
  #undef _knot_mask8
  #define _knot_mask8(a) simde_knot_mask8(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__mmask8
simde_kandn_mask8(simde__mmask8 a, simde__mmask8 b) {
  #if defined(SIMDE_X86_AVX512DQ_NATIVE)
    return _kandn_mask8(a, b);
  #else
    return (~a) & b;
  #endif
}
#if defined(SIMDE_X86_AVX512DQ_ENABLE_NATIVE_ALIASES)
  #undef _kandn_mask8
  #define _kandn_mask8(a, b) simde_kandn_mask8(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
unsigned char
simde_kortestz_mask8_u8(simde__mmask8 a, simde__mmask8 b) {
  #if defined(SIMDE_X86_AVX512DQ_NATIVE)
    return _kortestz_mask8_u8(a, b);
  #else
    return (a | b) == 0;
  #endif
}
#if defined(SIMDE_X86_AVX512DQ_ENABLE_NATIVE_ALIASES)
  #undef _kortestz_mask8_u8
  #define _kortestz_mask8_u8(a, b) simde_kortestz_mask8_u8(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
unsigned char
simde_kortestz_mask16_u8(simde__mmask16 a, simde__mmask16 b) {
  #if defined(SIMDE_X86_AVX512DQ_NATIVE)
    return _kortestz_mask16_u8(a, b);
  #else
    return (a | b) == 0;
  #endif
}
#if defined(SIMDE_X86_AVX512DQ_ENABLE_NATIVE_ALIASES)
  #undef _kortestz_mask16_u8
  #define _kortestz_mask16_u8(a, b) simde_kortestz_mask16_u8(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__mmask16
simde_mm512_kunpackb(simde__mmask16 a, simde__mmask16 b) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_kunpackb(a, b);
  #else
    return (a << 8) | b;
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_kunpackb
  #define _mm512_kunpackb(a, b) simde_mm512_kunpackb(a, b)
#endif

SIMDE_END_DECLS_
HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_X86_AVX512_MASK_H) */
