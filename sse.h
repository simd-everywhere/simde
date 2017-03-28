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
#if defined(SIMDE__EMULATE_NATIVE)
#  if defined(__m128)
#    undef __m128
#  endif
#  define __m128 SIMDE__TYPE(m128)
#endif

SIMDE__SSE_INLINE_FUNC
SIMDE__TYPE(m128)
SIMDE__SYMBOL(set_ps) (float a, float b, float c, float d) {
  return (SIMDE__TYPE(m128)) { .flt = { d, c, b, a } };
}
#if defined(SIMDE__EMULATE_NATIVE)
#  define _mm_set_ps SIMDE__SYMBOL(set_ps)
#endif

SIMDE__SSE_INLINE_FUNC
SIMDE__TYPE(m128)
SIMDE__SYMBOL(set1_ps) (float v) {
  return SIMDE__SYMBOL(set_ps)(v, v, v, v);
}
#if defined(SIMDE__EMULATE_NATIVE)
#  define _mm_set1_ps SIMDE__SYMBOL(set1_ps)
#endif

SIMDE__SSE_INLINE_FUNC
SIMDE__TYPE(m128)
SIMDE__SYMBOL(add_ps) (SIMDE__TYPE(m128) a, SIMDE__TYPE(m128) b) {
  return (SIMDE__TYPE(m128)) { .flt = a.flt + b.flt };
}
#if defined(SIMDE__EMULATE_NATIVE)
#  define _mm_add_ps SIMDE__SYMBOL(add_ps)
#endif

SIMDE__SSE_INLINE_FUNC
SIMDE__TYPE(m128)
SIMDE__SYMBOL(add_ss) (SIMDE__TYPE(m128) a, SIMDE__TYPE(m128) b) {
  return (SIMDE__TYPE(m128)) {
    .flt = { a.flt[0] + b.flt[0], a.flt[1], a.flt[2], a.flt[3] }
  };
}
#if defined(SIMDE__EMULATE_NATIVE)
#  define _mm_add_ss SIMDE__SYMBOL(add_ss)
#endif

SIMDE__SSE_INLINE_FUNC
SIMDE__TYPE(m128)
SIMDE__SYMBOL(and_ps) (SIMDE__TYPE(m128) a, SIMDE__TYPE(m128) b) {
  return (SIMDE__TYPE(m128)) {
    .i32 = a.i32 & b.i32
  };
}
#if defined(SIMDE__EMULATE_NATIVE)
#  define _mm_and_ps SIMDE__SYMBOL(and_ps)
#endif

SIMDE__SSE_INLINE_FUNC
SIMDE__TYPE(m128)
SIMDE__SYMBOL(andnot_ps) (SIMDE__TYPE(m128) a, SIMDE__TYPE(m128) b) {
  return (SIMDE__TYPE(m128)) {
    .i32 = ~(a.i32) & b.i32
  };
}
#if defined(SIMDE__EMULATE_NATIVE)
#  define _mm_andnot_ps SIMDE__SYMBOL(andnot_ps)
#endif

SIMDE__SSE_INLINE_FUNC
SIMDE__TYPE(m128)
SIMDE__SYMBOL(sub_ps) (SIMDE__TYPE(m128) a, SIMDE__TYPE(m128) b) {
  return (SIMDE__TYPE(m128)) {
    .flt = a.flt - b.flt
  };
}
#if defined(SIMDE__EMULATE_NATIVE)
#  define _mm_sub_ps SIMDE__SYMBOL(sub_ps)
#endif

SIMDE__SSE_INLINE_FUNC
SIMDE__TYPE(m128)
SIMDE__SYMBOL(mul_ps) (SIMDE__TYPE(m128) a, SIMDE__TYPE(m128) b) {
  return (SIMDE__TYPE(m128)) {
    .flt = a.flt * b.flt
  };
}
#if defined(SIMDE__EMULATE_NATIVE)
#  define _mm_mul_ps SIMDE__SYMBOL(mul_ps)
#endif

SIMDE__SSE_INLINE_FUNC
SIMDE__TYPE(m128)
SIMDE__SYMBOL(div_ps) (SIMDE__TYPE(m128) a, SIMDE__TYPE(m128) b) {
  return (SIMDE__TYPE(m128)) {
    .flt = a.flt / b.flt
  };
}
#if defined(SIMDE__EMULATE_NATIVE)
#  define _mm_div_ps SIMDE__SYMBOL(div_ps)
#endif

#endif /* !defined(SIMDE__SSE_NATIVE) */
#endif /* !defined(SIMDE__SSE_H) */
