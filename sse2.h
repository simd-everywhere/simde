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

#if !defined(SIMDE__SSE2_H)
#define SIMDE__SSE2_H

#include "simde-common.h"

#include "sse.h"

#if !defined(SIMDE__SSE2_NATIVE) && !defined(SIMDE__SSE_NO_NATIVE) && defined(__SSE2__)
#  define SIMDE__SSE2_NATIVE
#endif

#if defined(SIMDE__SSE2_NATIVE)
#  include <emmintrin.h>
#endif

#include <stdint.h>
#include <limits.h>

typedef union {
  int8_t         i8[16];
  int16_t        i16[8];
  int32_t        i32[4];
  int64_t        i64[2];
  uint8_t        u8[16];
  uint16_t       u16[8];
  uint32_t       u32[4];
  uint64_t       u64[2];
#if defined(SIMDE__SSE2_NATIVE)
  __m128i        n;
#endif
} SIMDE__SYMBOL(__m128i);

#if defined(SIMDE__SSE_NATIVE)
HEDLEY_STATIC_ASSERT(sizeof(__m128i) == sizeof(SIMDE__SYMBOL_U(_m128i)), "__m128i size incorrect");
#define SIMDE__M128I_C(expr) ((SIMDE__SYMBOL_U(_m128i)) { .n = expr })
#endif

SIMDE__FUNCTION_ATTRIBUTES
SIMDE__SYMBOL(__m128i)
SIMDE__SYMBOL(_mm_add_epi8) (SIMDE__SYMBOL(__m128i) a, SIMDE__SYMBOL(__m128i) b) {
#if defined(SIMDE__SSE2_NATIVE)
  return SIMDE__M128I_C(_mm_add_epi8(a.n, b.n));
#else
  SIMDE__SYMBOL(__m128i) r;
  for (size_t i = 0 ; i < (sizeof(r.i8) / sizeof(r.i8[0])) ; i++) {
    r.i8[i] = a.i8[i] + b.i8[i];
  }
  return r;
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
SIMDE__SYMBOL(__m128i)
SIMDE__SYMBOL(_mm_set_epi8) (int8_t e15, int8_t e14, int8_t e13, int8_t e12,
			     int8_t e11, int8_t e10, int8_t  e9, int8_t  e8,
			     int8_t  e7, int8_t  e6, int8_t  e5, int8_t  e4,
			     int8_t  e3, int8_t  e2, int8_t  e1, int8_t  e0) {
#if defined(SIMDE__SSE2_NATIVE)
  return SIMDE__M128I_C(_mm_set_epi8(e15, e14, e13, e12, e11, e10,  e9,  e8,
				      e7,  e6,  e5,  e4,  e3,  e2,  e1,  e0));
#else
  return (SIMDE__SYMBOL(__m128i)) { .i8 = {  e0,  e1,  e2,  e3,  e4,  e5,  e6,  e7,
					     e8,  e9, e10, e11, e12, e13, e14, e15 } };
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
SIMDE__SYMBOL(__m128i)
SIMDE__SYMBOL(_mm_set_epi16) (int16_t e7, int16_t e6, int16_t e5, int16_t e4,
			      int16_t e3, int16_t e2, int16_t e1, int16_t e0) {
#if defined(SIMDE__SSE2_NATIVE)
  return SIMDE__M128I_C(_mm_set_epi16(e7, e6, e5, e4, e3, e2, e1, e0));
#else
  return (SIMDE__SYMBOL(__m128i)) { .i16 = { e0, e1, e2, e3, e4, e5, e6, e7 } };
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
SIMDE__SYMBOL(__m128i)
SIMDE__SYMBOL(_mm_set_epi32) (int32_t e3, int32_t e2, int32_t e1, int32_t e0) {
#if defined(SIMDE__SSE2_NATIVE)
  return SIMDE__M128I_C(_mm_set_epi32(e3, e2, e1, e0));
#else
  return (SIMDE__SYMBOL(__m128i)) { .i32 = { e0, e1, e2, e3 } };
#endif
}

#endif /* !defined(SIMDE__SSE2_H) */
