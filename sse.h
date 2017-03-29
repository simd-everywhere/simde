#if !defined(SIMDE__SSE_H)
#define SIMDE__SSE_H

#define SIMDE__SSE_INLINE_FUNC __attribute__((__always_inline__)) static inline

#if !defined(SIMDE__TYPE)
#  define SIMDE__TYPE(name) simde_simd__sse1_##name
#  define SIMDE__SYMBOL(name) simde_simd__sse1_##name
#endif

#include "mmx.h"

#if defined(SIMDE__SSE_NATIVE)
#  include <xmmintrin.h>
#else

typedef union {
  char  i8  __attribute__((__vector_size__(16)));
  short i16 __attribute__((__vector_size__(16)));
  int   i32 __attribute__((__vector_size__(16)));
  float flt __attribute__((__vector_size__(16)));
} SIMDE__TYPE(m128);
#if defined(__m128)
#  undef __m128
#endif
#define __m128 SIMDE__TYPE(m128)

SIMDE__SSE_INLINE_FUNC
SIMDE__TYPE(m128)
SIMDE__SYMBOL(__mm_set_ps) (float a, float b, float c, float d) {
  return (SIMDE__TYPE(m128)) { .flt = { d, c, b, a } };
}
#if defined(_mm_set_ps)
#  undef _mm_set_ps
#endif
#define _mm_set_ps SIMDE__SYMBOL(__mm_set_ps)

SIMDE__SSE_INLINE_FUNC
SIMDE__TYPE(m128)
SIMDE__SYMBOL(__mm_set1_ps) (float v) {
  return SIMDE__SYMBOL(__mm_set_ps)(v, v, v, v);
}
#if defined(_mm_set1_ps)
#  undef _mm_set1_ps
#endif
#define _mm_set1_ps SIMDE__SYMBOL(__mm_set1_ps)

SIMDE__SSE_INLINE_FUNC
SIMDE__TYPE(m128)
SIMDE__SYMBOL(__mm_add_ps) (SIMDE__TYPE(m128) a, SIMDE__TYPE(m128) b) {
  return (SIMDE__TYPE(m128)) { .flt = a.flt + b.flt };
}
#if defined(_mm_add_ps)
#  undef _mm_add_ps
#endif
#define _mm_add_ps SIMDE__SYMBOL(__mm_add_ps)

SIMDE__SSE_INLINE_FUNC
SIMDE__TYPE(m128)
SIMDE__SYMBOL(__mm_add_ss) (SIMDE__TYPE(m128) a, SIMDE__TYPE(m128) b) {
  return (SIMDE__TYPE(m128)) {
    .flt = { a.flt[0] + b.flt[0], a.flt[1], a.flt[2], a.flt[3] }
  };
}
#if defined(_mm_add_ss)
#  undef _mm_add_ss
#endif
#define _mm_add_ss SIMDE__SYMBOL(__mm_add_ss)

SIMDE__SSE_INLINE_FUNC
SIMDE__TYPE(m128)
SIMDE__SYMBOL(__mm_and_ps) (SIMDE__TYPE(m128) a, SIMDE__TYPE(m128) b) {
  return (SIMDE__TYPE(m128)) {
    .i32 = a.i32 & b.i32
  };
}
#if defined(_mm_and_ps)
#  undef _mm_and_ps
#endif
#define _mm_and_ps SIMDE__SYMBOL(__mm_and_ps)

SIMDE__SSE_INLINE_FUNC
SIMDE__TYPE(m128)
SIMDE__SYMBOL(__mm_andnot_ps) (SIMDE__TYPE(m128) a, SIMDE__TYPE(m128) b) {
  return (SIMDE__TYPE(m128)) {
    .i32 = ~(a.i32) & b.i32
  };
}
#if defined(_mm_andnot_ps)
#  undef _mm_andnot_ps
#endif
#define _mm_andnot_ps SIMDE__SYMBOL(__mm_andnot_ps)

SIMDE__SSE_INLINE_FUNC
SIMDE__TYPE(m128)
SIMDE__SYMBOL(__mm_sub_ps) (SIMDE__TYPE(m128) a, SIMDE__TYPE(m128) b) {
  return (SIMDE__TYPE(m128)) {
    .flt = a.flt - b.flt
  };
}
#if defined(_mm_sub_ps)
#  undef _mm_sub_ps
#endif
#define _mm_sub_ps SIMDE__SYMBOL(__mm_sub_ps)

SIMDE__SSE_INLINE_FUNC
SIMDE__TYPE(m128)
SIMDE__SYMBOL(__mm_mul_ps) (SIMDE__TYPE(m128) a, SIMDE__TYPE(m128) b) {
  return (SIMDE__TYPE(m128)) {
    .flt = a.flt * b.flt
  };
}
#if defined(_mm_mul_ps)
#  undef _mm_mul_ps
#endif
#define _mm_mul_ps SIMDE__SYMBOL(__mm_mul_ps)

SIMDE__SSE_INLINE_FUNC
SIMDE__TYPE(m128)
SIMDE__SYMBOL(__mm_div_ps) (SIMDE__TYPE(m128) a, SIMDE__TYPE(m128) b) {
  return (SIMDE__TYPE(m128)) {
    .flt = a.flt / b.flt
  };
}
#if defined(_mm_div_ps)
#  undef _mm_div_ps
#endif
#define _mm_div_ps SIMDE__SYMBOL(__mm_div_ps)

#endif /* !defined(SIMDE__SSE_NATIVE) */
#endif /* !defined(SIMDE__SSE_H) */
