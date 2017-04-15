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

#if defined(SIMDE__SSE2_NATIVE)
typedef __m128i SIMDE__SYMBOL(__m128i);
#else
typedef union {
  char           i8[16];
  short          i16[8];
  int            i32[4];
  int64_t        i64[2];
  unsigned char  u8[16];
  unsigned short u16[8];
  unsigned int   u32[4];
  uint64_t       u64[2];
} SIMDE__SYMBOL(__m128i);
#endif

SIMDE__FUNCTION_ATTRIBUTES
SIMDE__SYMBOL(__m128i)
SIMDE__SYMBOL(_mm_add_epi8) (SIMDE__SYMBOL(__m128i) a, SIMDE__SYMBOL(__m128i) b) {
#if defined(SIMDE__SSE2_NATIVE)
  return _mm_add_epi8(a, b);
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
SIMDE__SYMBOL(_mm_set_epi8) (char e15, char e14, char e13, char e12,
			     char e11, char e10, char  e9, char  e8,
			     char  e7, char  e6, char  e5, char  e4,
			     char  e3, char  e2, char  e1, char  e0) {
#if defined(SIMDE__SSE2_NATIVE)
  return _mm_set_epi8(e15, e14, e13, e12, e11, e10,  e9,  e8,
		       e7,  e6,  e5,  e4,  e3,  e2,  e1,  e0);
#else
  return (SIMDE__SYMBOL(__m128i)) { .i8 = {  e0,  e1,  e2,  e3,  e4,  e5,  e6,  e7,
					   e8,  e9, e10, e11, e12, e13, e14, e15 } };
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
SIMDE__SYMBOL(__m128i)
SIMDE__SYMBOL(_mm_set_epi16) (short  e7, short  e6, short  e5, short  e4,
			      short  e3, short  e2, short  e1, short  e0) {
#if defined(SIMDE__SSE2_NATIVE)
  return _mm_set_epi16(e7, e6, e5, e4, e3, e2, e1, e0);
#else
  return (SIMDE__SYMBOL(__m128i)) { .i16 = { e0, e1, e2, e3, e4, e5, e6, e7 } };
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
SIMDE__SYMBOL(__m128i)
SIMDE__SYMBOL(_mm_set_epi32) (int  e3, int  e2, int  e1, int  e0) {
#if defined(SIMDE__SSE2_NATIVE)
  return _mm_set_epi32(e3, e2, e1, e0);
#else
  return (SIMDE__SYMBOL(__m128i)) { .i32 = { e0, e1, e2, e3 } };
#endif
}

#endif /* !defined(SIMDE__SSE2_H) */
