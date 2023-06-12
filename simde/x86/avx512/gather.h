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
 *   2023      Michael R. Crusoe <crusoe@debian.org>
 */

#if !defined(SIMDE_X86_AVX512_GATHER_H)
#define SIMDE_X86_AVX512_GATHER_H

#include "types.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

SIMDE_FUNCTION_ATTRIBUTES
simde__m512
simde_mm512_i32gather_ps(simde__m512i vindex, const void* base_addr, const int32_t scale)
    SIMDE_REQUIRE_CONSTANT(scale)
    HEDLEY_REQUIRE_MSG((scale && scale <= 8 && !(scale & (scale - 1))), "`scale' must be a power of two less than or equal to 8") {
  simde__m512i_private vindex_ = simde__m512i_to_private(vindex);
  simde__m512_private r_ = simde__m512_to_private(simde_mm512_setzero_ps());
  const uint8_t* addr = HEDLEY_REINTERPRET_CAST(const uint8_t*, base_addr);

  SIMDE_VECTORIZE
  for (size_t i = 0 ; i < (sizeof(vindex_.i32) / sizeof(vindex_.i32[0])) ; i++) {
    const uint8_t* src = addr + (HEDLEY_STATIC_CAST(size_t , vindex_.i32[i]) * HEDLEY_STATIC_CAST(size_t , scale));
    simde_float32 dst;
    simde_memcpy(&dst, src, sizeof(dst));
    r_.f32[i] = dst;
  }

  return simde__m512_from_private(r_);
}
#if defined(SIMDE_X86_AVX512F_NATIVE) && (!defined(__clang__) || SIMDE_DETECT_CLANG_VERSION_CHECK(10,0,0))
  #define simde_mm512_i32gather_ps(vindex, base_addr, scale) _mm512_i32gather_ps((vindex), (base_addr), (scale))
#endif
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_i32gather_ps
  #define _mm512_i32gather_ps(vindex, base_addr, scale) simde_mm512_i32gather_ps((vindex), (base_addr), (scale))
#endif

SIMDE_END_DECLS_
HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_X86_AVX512_GATHER_H) */
