/* Copyright (c) 2017 Evan Nemerson <evan@nemerson.com>
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
 */

#if !defined(SIMDE__SSE4_1_H) || defined(SIMDE_MULTIPLE_INCLUDES)
#  if !defined(SIMDE__SSE4_1_H)
#    define SIMDE__SSE4_1_H
#  endif
#  include "ssse3.h"

#  if defined(SIMDE_SSE4_1_NATIVE)
#    undef SIMDE_SSE4_1_NATIVE
#  endif
#  if defined(SIMDE_SSE4_1_FORCE_NATIVE)
#    define SIMDE_SSE4_1_NATIVE
#  elif defined(__SSE4_1__) && (!defined(SIMDE_SSE4_1_NO_NATIVE) && !defined(SIMDE_NO_NATIVE))
#    define SIMDE_SSE4_1_NATIVE
#  endif

#  if defined(SIMDE_SSE4_1_NATIVE) && !defined(SIMDE_SSE3_NATIVE)
#    if defined(SIMDE_SSE4_1_FORCE_NATIVE)
#      error Native SSE4.11 support requires native SSE3 support
#    else
#      warning Native SSE4.11 support requires native SSE3 support, disabling
#      undef SIMDE_SSE4_1_NATIVE
#    endif
#  endif

#  if defined(SIMDE_SSE4_1_NATIVE)
#    include <smmintrin.h>
#  endif

SIMDE__FUNCTION_ATTRIBUTES
SIMDE__SYMBOL(_m128i)
SIMDE__SYMBOL(mm_blendv_epi8) (SIMDE__SYMBOL(_m128i) a, SIMDE__SYMBOL(_m128i) b, SIMDE__SYMBOL(_m128i) mask) {
#if defined(SIMDE_SSE4_1_NATIVE)
  return SIMDE__M128I_C(_mm_blendv_epi8(a.n, b.n, mask.n));
#else
  SIMDE__SYMBOL(_m128i) r;
  for (size_t i = 0 ; i < (sizeof(r.u8) / sizeof(r.u8[0])) ; i++) {
    if (mask.u8[i] & 0x80) {
      r.u8[i] = b.u8[i];
    } else {
      r.u8[i] = a.u8[i];
    }
  }
  return r;
#endif
}

#if defined(simde_mm_extract_epi64)
#  undef simde_mm_extract_epi64
#endif
SIMDE__FUNCTION_ATTRIBUTES
int64_t
SIMDE__SYMBOL(mm_extract_epi64) (SIMDE__SYMBOL(_m128i) a, const int imm8) {
  return a.u64[imm8];
}
#if defined(SIMDE_SSE4_1_NATIVE)
#  define simde_mm_extract_epi64(a, imm8) _mm_extract_epi64(a.n, imm8)
#endif

SIMDE__FUNCTION_ATTRIBUTES
SIMDE__SYMBOL(_m128i)
SIMDE__SYMBOL(mm_min_epi8) (SIMDE__SYMBOL(_m128i) a, SIMDE__SYMBOL(_m128i) b) {
#if defined(SIMDE_SSE4_1_NATIVE) && !defined(__PGI)
  return SIMDE__M128I_C(_mm_min_epi8(a.n, b.n));
#else
  SIMDE__SYMBOL(_m128i) r;
  for (size_t i = 0 ; i < (sizeof(r.i8) / sizeof(r.i8[0])) ; i++) {
    r.i8[i] = a.i8[i] < b.i8[i] ? a.i8[i] : b.i8[i];
  }
  return r;
#endif
}

#endif /* !defined(SIMDE__SSE4_1_H) */
