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
 *   2020      Christopher Moore <moore@free.fr>
 */

#if !defined(SIMDE_X86_AVX512_INSERT_H)
#define SIMDE_X86_AVX512_INSERT_H

#include "types.h"
#include "mov.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

SIMDE_FUNCTION_ATTRIBUTES
simde__m512
simde_mm512_insertf32x4 (simde__m512 a, simde__m128 b, int imm8)
    SIMDE_REQUIRE_CONSTANT_RANGE(imm8, 0, 3) {
  simde__m512_private a_ = simde__m512_to_private(a);

  a_.m128[imm8 & 3] = b;

  return simde__m512_from_private(a_);
}
#if defined(SIMDE_X86_AVX512F_NATIVE)
  #define simde_mm512_insertf32x4(a, b, imm8) _mm512_insertf32x4(a, b, imm8)
#endif
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_insertf32x4
  #define _mm512_insertf32x4(a, b, imm8) simde_mm512_insertf32x4(a, b, imm8)
#endif

#if defined(SIMDE_X86_AVX512F_NATIVE) && (!defined(HEDLEY_GCC_VERSION) || HEDLEY_GCC_VERSION_CHECK(8,0,0))
  #define simde_mm512_mask_insertf32x4(src, k, a, b, imm8) _mm512_mask_insertf32x4(src, k, a, b, imm8)
#else
  #define simde_mm512_mask_insertf32x4(src, k, a, b, imm8) simde_mm512_mask_mov_ps(src, k, simde_mm512_insertf32x4(a, b, imm8))
#endif
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_insertf32x4
  #define _mm512_mask_insertf32x4(src, k, a, b, imm8) simde_mm512_mask_insertf32x4(src, k, a, b, imm8)
#endif

#if defined(SIMDE_X86_AVX512F_NATIVE) && (!defined(HEDLEY_GCC_VERSION) || HEDLEY_GCC_VERSION_CHECK(8,0,0))
  #define simde_mm512_maskz_insertf32x4(k, a, b, imm8) _mm512_maskz_insertf32x4(k, a, b, imm8)
#else
  #define simde_mm512_maskz_insertf32x4(k, a, b, imm8) simde_mm512_maskz_mov_ps(k, simde_mm512_insertf32x4(a, b, imm8))
#endif
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_maskz_insertf32x4
  #define _mm512_maskz_insertf32x4(k, a, b, imm8) simde_mm512_maskz_insertf32x4(k, a, b, imm8)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512d
simde_mm512_insertf64x4 (simde__m512d a, simde__m256d b, int imm8)
    SIMDE_REQUIRE_CONSTANT_RANGE(imm8, 0, 1) {
  simde__m512d_private a_ = simde__m512d_to_private(a);

  a_.m256d[imm8 & 1] = b;

  return simde__m512d_from_private(a_);
}
#if defined(SIMDE_X86_AVX512F_NATIVE)
  #define simde_mm512_insertf64x4(a, b, imm8) _mm512_insertf64x4(a, b, imm8)
#endif
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_insertf64x4
  #define _mm512_insertf64x4(a, b, imm8) simde_mm512_insertf64x4(a, b, imm8)
#endif

#if defined(SIMDE_X86_AVX512F_NATIVE)
  #define simde_mm512_mask_insertf64x4(src, k, a, b, imm8) _mm512_mask_insertf64x4(src, k, a, b, imm8)
#else
  #define simde_mm512_mask_insertf64x4(src, k, a, b, imm8) simde_mm512_mask_mov_pd(src, k, simde_mm512_insertf64x4(a, b, imm8))
#endif
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_insertf64x4
  #define _mm512_mask_insertf64x4(src, k, a, b, imm8) simde_mm512_mask_insertf64x4(src, k, a, b, imm8)
#endif

#if defined(SIMDE_X86_AVX512F_NATIVE)
  #define simde_mm512_maskz_insertf64x4(k, a, b, imm8) _mm512_maskz_insertf64x4(k, a, b, imm8)
#else
  #define simde_mm512_maskz_insertf64x4(k, a, b, imm8) simde_mm512_maskz_mov_pd(k, simde_mm512_insertf64x4(a, b, imm8))
#endif
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_maskz_insertf64x4
  #define _mm512_maskz_insertf64x4(k, a, b, imm8) simde_mm512_maskz_insertf64x4(k, a, b, imm8)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_inserti32x4 (simde__m512i a, simde__m128i b, int imm8)
    SIMDE_REQUIRE_CONSTANT_RANGE(imm8, 0, 3) {
  simde__m512i_private a_ = simde__m512i_to_private(a);

  a_.m128i[imm8 & 3] = b;

  return simde__m512i_from_private(a_);
}
#if defined(SIMDE_X86_AVX512F_NATIVE)
  #define simde_mm512_inserti32x4(a, b, imm8) _mm512_inserti32x4(a, b, imm8)
#endif
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_inserti32x4
  #define _mm512_inserti32x4(a, b, imm8) simde_mm512_inserti32x4(a, b, imm8)
#endif

#if defined(SIMDE_X86_AVX512F_NATIVE) && (!defined(HEDLEY_GCC_VERSION) || HEDLEY_GCC_VERSION_CHECK(8,0,0))
  #define simde_mm512_mask_inserti32x4(src, k, a, b, imm8) _mm512_mask_inserti32x4(src, k, a, b, imm8)
#else
  #define simde_mm512_mask_inserti32x4(src, k, a, b, imm8) simde_mm512_mask_mov_epi32(src, k, simde_mm512_inserti32x4(a, b, imm8))
#endif
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_inserti32x4
  #define _mm512_mask_inserti32x4(src, k, a, b, imm8) simde_mm512_mask_inserti32x4(src, k, a, b, imm8)
#endif

#if defined(SIMDE_X86_AVX512F_NATIVE) && (!defined(HEDLEY_GCC_VERSION) || HEDLEY_GCC_VERSION_CHECK(8,0,0))
  #define simde_mm512_maskz_inserti32x4(k, a, b, imm8) _mm512_maskz_inserti32x4(k, a, b, imm8)
#else
  #define simde_mm512_maskz_inserti32x4(k, a, b, imm8) simde_mm512_maskz_mov_epi32(k, simde_mm512_inserti32x4(a, b, imm8))
#endif
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_maskz_inserti32x4
  #define _mm512_maskz_inserti32x4(k, a, b, imm8) simde_mm512_maskz_inserti32x4(k, a, b, imm8)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_inserti64x4 (simde__m512i a, simde__m256i b, int imm8)
    SIMDE_REQUIRE_CONSTANT_RANGE(imm8, 0, 1) {
  simde__m512i_private a_ = simde__m512i_to_private(a);

  a_.m256i[imm8 & 1] = b;

  return simde__m512i_from_private(a_);
}
#if defined(SIMDE_X86_AVX512F_NATIVE)
  #define simde_mm512_inserti64x4(a, b, imm8) _mm512_inserti64x4(a, b, imm8)
#endif
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_inserti64x4
  #define _mm512_inserti64x4(a, b, imm8) simde_mm512_inserti64x4(a, b, imm8)
#endif

#if defined(SIMDE_X86_AVX512F_NATIVE)
  #define simde_mm512_mask_inserti64x4(src, k, a, b, imm8) _mm512_mask_inserti64x4(src, k, a, b, imm8)
#else
  #define simde_mm512_mask_inserti64x4(src, k, a, b, imm8) simde_mm512_mask_mov_epi64(src, k, simde_mm512_inserti64x4(a, b, imm8))
#endif
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_inserti64x4
  #define _mm512_mask_inserti64x4(src, k, a, b, imm8) simde_mm512_mask_inserti64x4(src, k, a, b, imm8)
#endif

#if defined(SIMDE_X86_AVX512F_NATIVE)
  #define simde_mm512_maskz_inserti64x4(k, a, b, imm8) _mm512_maskz_inserti64x4(k, a, b, imm8)
#else
  #define simde_mm512_maskz_inserti64x4(k, a, b, imm8) simde_mm512_maskz_mov_epi64(k, simde_mm512_inserti64x4(a, b, imm8))
#endif
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_maskz_inserti64x4
  #define _mm512_maskz_inserti64x4(k, a, b, imm8) simde_mm512_maskz_inserti64x4(k, a, b, imm8)
#endif

SIMDE_END_DECLS_
HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_X86_AVX512_INSERT_H) */
