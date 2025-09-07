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
 *   2021      Evan Nemerson <evan@nemerson.com>
 *   2025      Michael R. Crusoe <crusoe@debian.org>
 */

#if !defined(SIMDE_X86_AVX512_EXPANDLOADU_H)
#define SIMDE_X86_AVX512_EXPANDLOADU_H

#include "types.h"
#include "loadu.h"
#include "expand.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_mask_expandloadu_epi8(simde__m128i src, simde__mmask16 k, void const * mem_addr) {
  #if defined(SIMDE_X864_AVX512VBMI2_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm_mask_expandloadu_epi8(src, k, mem_addr);
  #else
    return simde_mm_mask_expand_epi8(src, k, simde_mm_loadu_epi8(mem_addr));
  #endif
}
#if defined(SIMDE_X86_AVX512VBMI2_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm_mask_expandloadu_epi8
  #define _mm_mask_expandloadu_epi8(src, k, mem_addr) simde_mm_mask_expandloadu_epi8((src), (k), (mem_addr))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_maskz_expandloadu_epi8(simde__mmask16 k, void const * mem_addr) {
  #if defined(SIMDE_X864_AVX512VBMI2_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm_maskz_expandloadu_epi8(k, mem_addr);
  #else
    return simde_mm_maskz_expand_epi8(k, simde_mm_loadu_epi8(mem_addr));
  #endif
}
#if defined(SIMDE_X86_AVX512VBMI2_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm_maskz_expandloadu_epi8
  #define _mm_maskz_expandloadu_epi8(k, mem_addr) simde_mm_maskz_expandloadu_epi8((k), (mem_addr))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_mask_expandloadu_epi8(simde__m256i src, simde__mmask32 k, void const * mem_addr) {
  #if defined(SIMDE_X864_AVX512VBMI2_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm256_mask_expandloadu_epi8(src, k, mem_addr);
  #else
    return simde_mm256_mask_expand_epi8(src, k, simde_mm256_loadu_epi8(mem_addr));
  #endif
}
#if defined(SIMDE_X86_AVX512VBMI2_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm256_mask_expandloadu_epi8
  #define _mm256_mask_expandloadu_epi8(src, k, mem_addr) simde_mm256_mask_expandloadu_epi8((src), (k), (mem_addr))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_maskz_expandloadu_epi8(simde__mmask32 k, void const * mem_addr) {
  #if defined(SIMDE_X864_AVX512VBMI2_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm_maskz_expandloadu_epi8(k, mem_addr);
  #else
    return simde_mm256_maskz_expand_epi8(k, simde_mm256_loadu_epi8(mem_addr));
  #endif
}
#if defined(SIMDE_X86_AVX512VBMI2_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm256_maskz_expandloadu_epi8
  #define _mm256_maskz_expandloadu_epi8(k, mem_addr) simde_mm256_maskz_expandloadu_epi8((k), (mem_addr))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_mask_expandloadu_epi8(simde__m512i src, simde__mmask64 k, void const * mem_addr) {
  #if defined(SIMDE_X864_AVX512VBMI2_NATIVE)
    return _mm512_mask_expandloadu_epi8(src, k, mem_addr);
  #else
    return simde_mm512_mask_expand_epi8(src, k, simde_mm512_loadu_epi8(mem_addr));
  #endif
}
#if defined(SIMDE_X86_AVX512VBMI2_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_expandloadu_epi8
  #define _mm512_mask_expandloadu_epi8(src, k, mem_addr) simde_mm512_mask_expandloadu_epi8((src), (k), (mem_addr))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_maskz_expandloadu_epi8(simde__mmask64 k, void const * mem_addr) {
  #if defined(SIMDE_X864_AVX512VBMI2_NATIVE)
    return _mm512_maskz_expandloadu_epi8(k, mem_addr);
  #else
    return simde_mm512_maskz_expand_epi8(k, simde_mm512_loadu_epi8(mem_addr));
  #endif
}
#if defined(SIMDE_X86_AVX512VBMI2_ENABLE_NATIVE_ALIASES)
  #undef _mm512_maskz_expandloadu_epi8
  #define _mm512_maskz_expandloadu_epi8(k, mem_addr) simde_mm512_maskz_expandloadu_epi8((k), (mem_addr))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_mask_expandloadu_epi16(simde__m128i src, simde__mmask8 k, void const * mem_addr) {
  #if defined(SIMDE_X864_AVX512VBMI2_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm_mask_expandloadu_epi16(src, k, mem_addr);
  #else
    return simde_mm_mask_expand_epi16(src, k, simde_mm_loadu_epi16(mem_addr));
  #endif
}
#if defined(SIMDE_X86_AVX512VBMI2_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm_mask_expandloadu_epi16
  #define _mm_mask_expandloadu_epi16(src, k, mem_addr) simde_mm_mask_expandloadu_epi16((src), (k), (mem_addr))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_maskz_expandloadu_epi16(simde__mmask8 k, void const * mem_addr) {
  #if defined(SIMDE_X864_AVX512VBMI2_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm_maskz_expandloadu_epi16(k, mem_addr);
  #else
    return simde_mm_maskz_expand_epi16(k, simde_mm_loadu_epi16(mem_addr));
  #endif
}
#if defined(SIMDE_X86_AVX512VBMI2_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm_maskz_expandloadu_epi16
  #define _mm_maskz_expandloadu_epi16(k, mem_addr) simde_mm_maskz_expandloadu_epi16((k), (mem_addr))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_mask_expandloadu_epi16(simde__m256i src, simde__mmask16 k, void const * mem_addr) {
  #if defined(SIMDE_X864_AVX512VBMI2_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm256_mask_expandloadu_epi16(src, k, mem_addr);
  #else
    return simde_mm256_mask_expand_epi16(src, k, simde_mm256_loadu_epi16(mem_addr));
  #endif
}
#if defined(SIMDE_X86_AVX512VBMI2_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm256_mask_expandloadu_epi16
  #define _mm256_mask_expandloadu_epi16(src, k, mem_addr) simde_mm256_mask_expandloadu_epi16((src), (k), (mem_addr))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_maskz_expandloadu_epi16(simde__mmask16 k, void const * mem_addr) {
  #if defined(SIMDE_X864_AVX512VBMI2_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm_maskz_expandloadu_epi16(k, mem_addr);
  #else
    return simde_mm256_maskz_expand_epi16(k, simde_mm256_loadu_epi16(mem_addr));
  #endif
}
#if defined(SIMDE_X86_AVX512VBMI2_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm256_maskz_expandloadu_epi16
  #define _mm256_maskz_expandloadu_epi16(k, mem_addr) simde_mm256_maskz_expandloadu_epi16((k), (mem_addr))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_mask_expandloadu_epi16(simde__m512i src, simde__mmask32 k, void const * mem_addr) {
  #if defined(SIMDE_X864_AVX512VBMI2_NATIVE)
    return _mm512_mask_expandloadu_epi16(src, k, mem_addr);
  #else
    return simde_mm512_mask_expand_epi16(src, k, simde_mm512_loadu_epi16(mem_addr));
  #endif
}
#if defined(SIMDE_X86_AVX512VBMI2_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_expandloadu_epi16
  #define _mm512_mask_expandloadu_epi16(src, k, mem_addr) simde_mm512_mask_expandloadu_epi16((src), (k), (mem_addr))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_maskz_expandloadu_epi16(simde__mmask32 k, void const * mem_addr) {
  #if defined(SIMDE_X864_AVX512VBMI2_NATIVE)
    return _mm512_maskz_expandloadu_epi16(k, mem_addr);
  #else
    return simde_mm512_maskz_expand_epi16(k, simde_mm512_loadu_epi16(mem_addr));
  #endif
}
#if defined(SIMDE_X86_AVX512VBMI2_ENABLE_NATIVE_ALIASES)
  #undef _mm512_maskz_expandloadu_epi16
  #define _mm512_maskz_expandloadu_epi16(k, mem_addr) simde_mm512_maskz_expandloadu_epi16((k), (mem_addr))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_mask_expandloadu_epi32(simde__m128i src, simde__mmask8 k, void const * mem_addr) {
  #if defined(SIMDE_X864_AVX512F_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm_mask_expandloadu_epi32(src, k, mem_addr);
  #else
    return simde_mm_mask_expand_epi32(src, k, simde_mm_loadu_epi32(mem_addr));
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm_mask_expandloadu_epi32
  #define _mm_mask_expandloadu_epi32(src, k, mem_addr) simde_mm_mask_expandloadu_epi32((src), (k), (mem_addr))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_maskz_expandloadu_epi32(simde__mmask8 k, void const * mem_addr) {
  #if defined(SIMDE_X864_AVX512F_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm_maskz_expandloadu_epi32(k, mem_addr);
  #else
    return simde_mm_maskz_expand_epi32(k, simde_mm_loadu_epi32(mem_addr));
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm_maskz_expandloadu_epi32
  #define _mm_maskz_expandloadu_epi32(k, mem_addr) simde_mm_maskz_expandloadu_epi32((k), (mem_addr))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_mask_expandloadu_epi32(simde__m256i src, simde__mmask8 k, void const * mem_addr) {
  #if defined(SIMDE_X864_AVX512F_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm256_mask_expandloadu_epi32(src, k, mem_addr);
  #else
    return simde_mm256_mask_expand_epi32(src, k, simde_mm256_loadu_epi32(mem_addr));
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm256_mask_expandloadu_epi32
  #define _mm256_mask_expandloadu_epi32(src, k, mem_addr) simde_mm256_mask_expandloadu_epi32((src), (k), (mem_addr))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_maskz_expandloadu_epi32(simde__mmask8 k, void const * mem_addr) {
  #if defined(SIMDE_X864_AVX512F_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm256_maskz_expandloadu_epi32(k, mem_addr);
  #else
    return simde_mm256_maskz_expand_epi32(k, simde_mm256_loadu_epi32(mem_addr));
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm256_maskz_expandloadu_epi32
  #define _mm256_maskz_expandloadu_epi32(k, mem_addr) simde_mm256_maskz_expandloadu_epi32((k), (mem_addr))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_mask_expandloadu_epi32(simde__m512i src, simde__mmask16 k, void const * mem_addr) {
  #if defined(SIMDE_X864_AVX512F_NATIVE)
    return _mm512_mask_expandloadu_epi32(src, k, mem_addr);
  #else
    return simde_mm512_mask_expand_epi32(src, k, simde_mm512_loadu_epi32(mem_addr));
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_expandloadu_epi32
  #define _mm512_mask_expandloadu_epi32(src, k, mem_addr) simde_mm512_mask_expandloadu_epi32((src), (k), (mem_addr))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_maskz_expandloadu_epi32(simde__mmask16 k, void const * mem_addr) {
  #if defined(SIMDE_X864_AVX512F_NATIVE)
    return _mm512_maskz_expandloadu_epi32(k, mem_addr);
  #else
    return simde_mm512_maskz_expand_epi32(k, simde_mm512_loadu_epi32(mem_addr));
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_maskz_expandloadu_epi32
  #define _mm512_maskz_expandloadu_epi32(k, mem_addr) simde_mm512_maskz_expandloadu_epi32((k), (mem_addr))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_mask_expandloadu_epi64(simde__m128i src, simde__mmask8 k, void const * mem_addr) {
  #if defined(SIMDE_X86_AVX512F_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm_mask_expandloadu_epi64(src, k, mem_addr);
  #else
    return simde_mm_mask_expand_epi64(src, k, simde_mm_loadu_epi64(mem_addr));
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm_mask_expandloadu_epi64
  #define _mm_mask_expandloadu_epi64(src, k, mem_addr) simde_mm_mask_expandloadu_epi64((src), (k), (mem_addr))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_maskz_expandloadu_epi64(simde__mmask8 k, void const * mem_addr) {
  #if defined(SIMDE_X86_AVX512F_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm_maskz_expandloadu_epi64(k, mem_addr);
  #else
    return simde_mm_maskz_expand_epi64(k, simde_mm_loadu_epi64(mem_addr));
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm_maskz_expandloadu_epi64
  #define _mm_maskz_expandloadu_epi64(k, mem_addr) simde_mm_maskz_expandloadu_epi64((k), (mem_addr))
#endif


SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_mask_expandloadu_epi64(simde__m256i src, simde__mmask8 k, void const * mem_addr) {
  #if defined(SIMDE_X86_AVX512F_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm256_mask_expandloadu_epi64(src, k, mem_addr);
  #else
    return simde_mm256_mask_expand_epi64(src, k, simde_mm256_loadu_epi64(mem_addr));
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm256_mask_expandloadu_epi64
  #define _mm256_mask_expandloadu_epi64(src, k, mem_addr) simde_mm256_mask_expandloadu_epi64((src), (k), (mem_addr))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_maskz_expandloadu_epi64(simde__mmask8 k, void const * mem_addr) {
  #if defined(SIMDE_X86_AVX512F_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm256_maskz_expandloadu_epi64(k, mem_addr);
  #else
    return simde_mm256_maskz_expand_epi64(k, simde_mm256_loadu_epi64(mem_addr));
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm256_maskz_expandloadu_epi64
  #define _mm256_maskz_expandloadu_epi64(k, mem_addr) simde_mm256_maskz_expandloadu_epi64((k), (mem_addr))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_mask_expandloadu_epi64(simde__m512i src, simde__mmask8 k, void const * mem_addr) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_mask_expandloadu_epi64(src, k, mem_addr);
  #else
    return simde_mm512_mask_expand_epi64(src, k, simde_mm512_loadu_epi64(mem_addr));
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_expandloadu_epi64
  #define _mm512_mask_expandloadu_epi64(src, k, mem_addr) simde_mm512_mask_expandloadu_epi64((src), (k), (mem_addr))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_maskz_expandloadu_epi64(simde__mmask8 k, void const * mem_addr) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_maskz_expandloadu_epi64(k, mem_addr);
  #else
    return simde_mm512_maskz_expand_epi64(k, simde_mm512_loadu_epi64(mem_addr));
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_maskz_expandloadu_epi64
  #define _mm512_maskz_expandloadu_epi64(k, mem_addr) simde_mm512_maskz_expandloadu_epi64((k), (mem_addr))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128
simde_mm_mask_expandloadu_ps(simde__m128 src, simde__mmask8 k, void const * mem_addr) {
  #if defined(SIMDE_X86_AVX512F_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm_mask_expandloadu_ps(src, k, mem_addr);
  #else
    return simde_mm_mask_expand_ps(src, k, simde_mm_loadu_ps(HEDLEY_REINTERPRET_CAST(simde_float32 const*, mem_addr)));
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm_mask_expandloadu_ps
  #define _mm_mask_expandloadu_ps(src, k, mem_addr) simde_mm_mask_expandloadu_ps((src), (k), (mem_addr))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128
simde_mm_maskz_expandloadu_ps(simde__mmask8 k, void const * mem_addr) {
  #if defined(SIMDE_X86_AVX512F_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm_maskz_expandloadu_ps(k, mem_addr);
  #else
    return simde_mm_maskz_expand_ps(k, simde_mm_loadu_ps(HEDLEY_REINTERPRET_CAST(simde_float32 const*, mem_addr)));
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm_maskz_expandloadu_ps
  #define _mm_maskz_expandloadu_ps(k, mem_addr) simde_mm_maskz_expandloadu_ps((k), (mem_addr))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256
simde_mm256_mask_expandloadu_ps(simde__m256 src, simde__mmask8 k, void const * mem_addr) {
  #if defined(SIMDE_X86_AVX512F_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm256_mask_expandloadu_ps(src, k, mem_addr);
  #else
    return simde_mm256_mask_expand_ps(src, k, simde_mm256_loadu_ps(HEDLEY_REINTERPRET_CAST(simde_float32 const*, mem_addr)));
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm256_mask_expandloadu_ps
  #define _mm256_mask_expandloadu_ps(src, k, mem_addr) simde_mm256_mask_expandloadu_ps((src), (k), (mem_addr))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256
simde_mm256_maskz_expandloadu_ps(simde__mmask8 k, void const * mem_addr) {
  #if defined(SIMDE_X86_AVX512F_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm256_maskz_expandloadu_ps(k, mem_addr);
  #else
    return simde_mm256_maskz_expand_ps(k, simde_mm256_loadu_ps(HEDLEY_REINTERPRET_CAST(simde_float32 const*, mem_addr)));
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm256_maskz_expandloadu_ps
  #define _mm256_maskz_expandloadu_ps(k, mem_addr) simde_mm256_maskz_expandloadu_ps((k), (mem_addr))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512
simde_mm512_mask_expandloadu_ps(simde__m512 src, simde__mmask16 k, void const * mem_addr) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_mask_expandloadu_ps(src, k, mem_addr);
  #else
    return simde_mm512_mask_expand_ps(src, k, simde_mm512_loadu_ps(HEDLEY_REINTERPRET_CAST(simde_float32 const*, mem_addr)));
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_expandloadu_ps
  #define _mm512_mask_expandloadu_ps(src, k, mem_addr) simde_mm512_mask_expandloadu_ps((src), (k), (mem_addr))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512
simde_mm512_maskz_expandloadu_ps(simde__mmask16 k, void const * mem_addr) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_maskz_expandloadu_ps(k, mem_addr);
  #else
    return simde_mm512_maskz_expand_ps(k, simde_mm512_loadu_ps(HEDLEY_REINTERPRET_CAST(simde_float32 const*, mem_addr)));
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_maskz_expandloadu_ps
  #define _mm512_maskz_expandloadu_ps(k, mem_addr) simde_mm512_maskz_expandloadu_ps((k), (mem_addr))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128d
simde_mm_mask_expandloadu_pd(simde__m128d src, simde__mmask8 k, void const * mem_addr) {
  #if defined(SIMDE_X86_AVX512F_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm_mask_expandloadu_pd(src, k, mem_addr);
  #else
    return simde_mm_mask_expand_pd(src, k, simde_mm_loadu_pd(HEDLEY_REINTERPRET_CAST(simde_float64 const*, mem_addr)));
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm_mask_expandloadu_pd
  #define _mm_mask_expandloadu_pd(src, k, mem_addr) simde_mm_mask_expandloadu_pd((src), (k), (mem_addr))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128d
simde_mm_maskz_expandloadu_pd(simde__mmask8 k, void const * mem_addr) {
  #if defined(SIMDE_X86_AVX512F_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm_maskz_expandloadu_pd(k, mem_addr);
  #else
    return simde_mm_maskz_expand_pd(k, simde_mm_loadu_pd(HEDLEY_REINTERPRET_CAST(simde_float64 const*, mem_addr)));
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm_maskz_expandloadu_pd
  #define _mm_maskz_expandloadu_pd(k, mem_addr) simde_mm_maskz_expandloadu_pd((k), (mem_addr))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256d
simde_mm256_mask_expandloadu_pd(simde__m256d src, simde__mmask8 k, void const * mem_addr) {
  #if defined(SIMDE_X86_AVX512F_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm256_mask_expandloadu_pd(src, k, mem_addr);
  #else
    return simde_mm256_mask_expand_pd(src, k, simde_mm256_loadu_pd(HEDLEY_REINTERPRET_CAST(simde_float64 const*, mem_addr)));
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm256_mask_expandloadu_pd
  #define _mm256_mask_expandloadu_pd(src, k, mem_addr) simde_mm256_mask_expandloadu_pd((src), (k), (mem_addr))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256d
simde_mm256_maskz_expandloadu_pd(simde__mmask8 k, void const * mem_addr) {
  #if defined(SIMDE_X86_AVX512F_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm256_maskz_expandloadu_pd(k, mem_addr);
  #else
    return simde_mm256_maskz_expand_pd(k, simde_mm256_loadu_pd(HEDLEY_REINTERPRET_CAST(simde_float64 const*, mem_addr)));
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm256_maskz_expandloadu_pd
  #define _mm256_maskz_expandloadu_pd(k, mem_addr) simde_mm256_maskz_expandloadu_pd((k), (mem_addr))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512d
simde_mm512_mask_expandloadu_pd(simde__m512d src, simde__mmask8 k, void const * mem_addr) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_mask_expandloadu_pd(src, k, mem_addr);
  #else
    return simde_mm512_mask_expand_pd(src, k, simde_mm512_loadu_pd(mem_addr));
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_expandloadu_pd
  #define _mm512_mask_expandloadu_pd(src, k, mem_addr) simde_mm512_mask_expandloadu_pd((src), (k), (mem_addr))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512d
simde_mm512_maskz_expandloadu_pd(simde__mmask8 k, void const * mem_addr) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_maskz_expandloadu_pd(k, mem_addr);
  #else
    return simde_mm512_maskz_expand_pd(k, simde_mm512_loadu_pd(mem_addr));
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_maskz_expandloadu_pd
  #define _mm512_maskz_expandloadu_pd(k, mem_addr) simde_mm512_maskz_expandloadu_pd((k), (mem_addr))
#endif

SIMDE_END_DECLS_
HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_X86_AVX512_EXPANDLOADU_H) */
