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

typedef float SIMDE__TYPE(m128) __attribute__((__vector_size__(16),__unused__));
#if defined(SIMDE__EMULATE_NATIVE)
#  define __m128 SIMDE__TYPE(m128)
#endif

/* Internal types.  We cast to these for some operations because
   bitwise operations on floats are undefined in C, but some functions
   require them. */
typedef unsigned int SIMDE__TYPE(_m128_u32) __attribute__((__vector_size__(16),__unused__));
union SIMDE__TYPE(_m128_u) {
  SIMDE__TYPE(m128) flt;
  unsigned int u32 __attribute__((__vector_size__(16)));
};

SIMDE__SSE_INLINE_FUNC
SIMDE__TYPE(m128)
SIMDE__SYMBOL(set_ps) (float a, float b, float c, float d) {
  return (SIMDE__TYPE(m128)) { d, c, b, a };
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
  return a + b;
}
#if defined(SIMDE__EMULATE_NATIVE)
#  define _mm_add_ps SIMDE__SYMBOL(add_ps)
#endif

SIMDE__SSE_INLINE_FUNC
SIMDE__TYPE(m128)
SIMDE__SYMBOL(add_ss) (SIMDE__TYPE(m128) a, SIMDE__TYPE(m128) b) {
  return (SIMDE__TYPE(m128)) {
    a[0] + b[0],
    a[1],
    a[2],
    a[3]
  };
}
#if defined(SIMDE__EMULATE_NATIVE)
#  define _mm_add_ss SIMDE__SYMBOL(add_ss)
#endif

SIMDE__SSE_INLINE_FUNC
SIMDE__TYPE(m128)
SIMDE__SYMBOL(and_ps) (SIMDE__TYPE(m128) a, SIMDE__TYPE(m128) b) {
  SIMDE__TYPE(m128) r;
  int p;
  for (p = 0 ; p < 4 ; p++) {
    unsigned int tmp = *((unsigned int*) (&a[p])) & *((unsigned int*) (&b[p]));
    r[p] = *((float*) &tmp);
  }
  return r;
}
#if defined(SIMDE__EMULATE_NATIVE)
#  define _mm_and_ps SIMDE__SYMBOL(and_ps)
#endif

SIMDE__SSE_INLINE_FUNC
SIMDE__TYPE(m128)
SIMDE__SYMBOL(andnot_ps) (SIMDE__TYPE(m128) a, SIMDE__TYPE(m128) b) {
  SIMDE__TYPE(m128) r;
  union SIMDE__TYPE(_m128_u)* au = (union SIMDE__TYPE(_m128_u)*) &a;
  union SIMDE__TYPE(_m128_u)* bu = (union SIMDE__TYPE(_m128_u)*) &b;
  union SIMDE__TYPE(_m128_u)* ru = (union SIMDE__TYPE(_m128_u)*) &r;

  int p;
  for (p = 0 ; p < 4 ; p++)
    ((*ru).u32)[p] = (~(((*au).u32)[p])) & (((*bu).u32)[p]);

  return r;
}
#if defined(SIMDE__EMULATE_NATIVE)
#  define _mm_andnot_ps SIMDE__SYMBOL(andnot_ps)
#endif

SIMDE__SSE_INLINE_FUNC
SIMDE__TYPE(m128)
SIMDE__SYMBOL(sub_ps) (SIMDE__TYPE(m128) a, SIMDE__TYPE(m128) b) {
  return a - b;
}
#if defined(SIMDE__EMULATE_NATIVE)
#  define _mm_sub_ps SIMDE__SYMBOL(sub_ps)
#endif

SIMDE__SSE_INLINE_FUNC
SIMDE__TYPE(m128)
SIMDE__SYMBOL(mul_ps) (SIMDE__TYPE(m128) a, SIMDE__TYPE(m128) b) {
  return a * b;
}
#if defined(SIMDE__EMULATE_NATIVE)
#  define _mm_mul_ps SIMDE__SYMBOL(mul_ps)
#endif

SIMDE__SSE_INLINE_FUNC
SIMDE__TYPE(m128)
SIMDE__SYMBOL(div_ps) (SIMDE__TYPE(m128) a, SIMDE__TYPE(m128) b) {
  return a / b;
}
#if defined(SIMDE__EMULATE_NATIVE)
#  define _mm_div_ps SIMDE__SYMBOL(div_ps)
#endif

#endif /* !defined(SIMDE__SSE_NATIVE) */
#endif /* !defined(SIMDE__SSE_H) */
