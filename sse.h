#if !defined(SIMDE_SIMD__SSE_H)
#define SIMDE_SIMD__SSE_H

#define SIMDE_SIMD__SSE_INLINE_FUNC __attribute__((__always_inline__)) static inline

#define SIMDE_SIMD__SSE_TYPE(name)  simde_simd__sse_##name
#define SIMDE_SIMD__SSE1_SYMBOL(name) simde_simd__sse1_##name

#if defined(SIMDE_SIMD__SSE_NATIVE)
#  include <xmmintrin.h>
#else

typedef float SIMDE_SIMD__SSE_TYPE(m128) __attribute__((__vector_size__(16),__unused__));
#if defined(SIMDE_SIMD__EMULATE_NATIVE)
#  define __m128 SIMDE_SIMD__SSE_TYPE(m128)
#endif

typedef unsigned short SIMDE_SIMD__SSE_TYPE(m64) __attribute__((__vector_size__(8),__unused__));
#if defined(SIMDE_SIMD__EMULATE_NATIVE)
#  define __m64 SIMDE_SIMD__SSE_TYPE(m64)
#endif

/* Internal types.  We cast to these for some operations because
   bitwise operations on floats are undefined in C, but some functions
   require them. */
typedef unsigned int SIMDE_SIMD__SSE_TYPE(_m128_u32) __attribute__((__vector_size__(16),__unused__));
union SIMDE_SIMD__SSE_TYPE(_m128_u) {
  SIMDE_SIMD__SSE_TYPE(m128) flt;
  unsigned int u32 __attribute__((__vector_size__(16)));
};

SIMDE_SIMD__SSE_INLINE_FUNC
SIMDE_SIMD__SSE_TYPE(m128)
SIMDE_SIMD__SSE1_SYMBOL(set_ps) (float a, float b, float c, float d) {
  return (SIMDE_SIMD__SSE_TYPE(m128)) { d, c, b, a };
}
#if defined(SIMDE_SIMD__EMULATE_NATIVE)
#  define _mm_set_ps SIMDE_SIMD__SSE1_SYMBOL(set_ps)
#endif

SIMDE_SIMD__SSE_INLINE_FUNC
SIMDE_SIMD__SSE_TYPE(m128)
SIMDE_SIMD__SSE1_SYMBOL(set1_ps) (float v) {
  return SIMDE_SIMD__SSE1_SYMBOL(set_ps)(v, v, v, v);
}
#if defined(SIMDE_SIMD__EMULATE_NATIVE)
#  define _mm_set1_ps SIMDE_SIMD__SSE1_SYMBOL(set1_ps)
#endif

SIMDE_SIMD__SSE_INLINE_FUNC
SIMDE_SIMD__SSE_TYPE(m128)
SIMDE_SIMD__SSE1_SYMBOL(add_ps) (SIMDE_SIMD__SSE_TYPE(m128) a, SIMDE_SIMD__SSE_TYPE(m128) b) {
  return a + b;
}
#if defined(SIMDE_SIMD__EMULATE_NATIVE)
#  define _mm_add_ps SIMDE_SIMD__SSE1_SYMBOL(add_ps)
#endif

SIMDE_SIMD__SSE_INLINE_FUNC
SIMDE_SIMD__SSE_TYPE(m128)
SIMDE_SIMD__SSE1_SYMBOL(add_ss) (SIMDE_SIMD__SSE_TYPE(m128) a, SIMDE_SIMD__SSE_TYPE(m128) b) {
  return (SIMDE_SIMD__SSE_TYPE(m128)) {
    a[0] + b[0],
    a[1],
    a[2],
    a[3]
  };
}
#if defined(SIMDE_SIMD__EMULATE_NATIVE)
#  define _mm_add_ss SIMDE_SIMD__SSE1_SYMBOL(add_ss)
#endif

SIMDE_SIMD__SSE_INLINE_FUNC
SIMDE_SIMD__SSE_TYPE(m128)
SIMDE_SIMD__SSE1_SYMBOL(and_ps) (SIMDE_SIMD__SSE_TYPE(m128) a, SIMDE_SIMD__SSE_TYPE(m128) b) {
  SIMDE_SIMD__SSE_TYPE(m128) r;
  int p;
  for (p = 0 ; p < 4 ; p++) {
    unsigned int tmp = *((unsigned int*) (&a[p])) & *((unsigned int*) (&b[p]));
    r[p] = *((float*) &tmp);
  }
  return r;
}
#if defined(SIMDE_SIMD__EMULATE_NATIVE)
#  define _mm_and_ps SIMDE_SIMD__SSE1_SYMBOL(and_ps)
#endif

SIMDE_SIMD__SSE_INLINE_FUNC
SIMDE_SIMD__SSE_TYPE(m128)
SIMDE_SIMD__SSE1_SYMBOL(andnot_ps) (SIMDE_SIMD__SSE_TYPE(m128) a, SIMDE_SIMD__SSE_TYPE(m128) b) {
  SIMDE_SIMD__SSE_TYPE(m128) r;
  union SIMDE_SIMD__SSE_TYPE(_m128_u)* au = (union SIMDE_SIMD__SSE_TYPE(_m128_u)*) &a;
  union SIMDE_SIMD__SSE_TYPE(_m128_u)* bu = (union SIMDE_SIMD__SSE_TYPE(_m128_u)*) &b;
  union SIMDE_SIMD__SSE_TYPE(_m128_u)* ru = (union SIMDE_SIMD__SSE_TYPE(_m128_u)*) &r;

  int p;
  for (p = 0 ; p < 4 ; p++)
    ((*ru).u32)[p] = (~(((*au).u32)[p])) & (((*bu).u32)[p]);

  return r;
}
#if defined(SIMDE_SIMD__EMULATE_NATIVE)
#  define _mm_andnot_ps SIMDE_SIMD__SSE1_SYMBOL(andnot_ps)
#endif

SIMDE_SIMD__SSE_INLINE_FUNC
SIMDE_SIMD__SSE_TYPE(m128)
SIMDE_SIMD__SSE1_SYMBOL(sub_ps) (SIMDE_SIMD__SSE_TYPE(m128) a, SIMDE_SIMD__SSE_TYPE(m128) b) {
  return a - b;
}
#if defined(SIMDE_SIMD__EMULATE_NATIVE)
#  define _mm_sub_ps SIMDE_SIMD__SSE1_SYMBOL(sub_ps)
#endif

SIMDE_SIMD__SSE_INLINE_FUNC
SIMDE_SIMD__SSE_TYPE(m128)
SIMDE_SIMD__SSE1_SYMBOL(mul_ps) (SIMDE_SIMD__SSE_TYPE(m128) a, SIMDE_SIMD__SSE_TYPE(m128) b) {
  return a * b;
}
#if defined(SIMDE_SIMD__EMULATE_NATIVE)
#  define _mm_mul_ps SIMDE_SIMD__SSE1_SYMBOL(mul_ps)
#endif

SIMDE_SIMD__SSE_INLINE_FUNC
SIMDE_SIMD__SSE_TYPE(m128)
SIMDE_SIMD__SSE1_SYMBOL(div_ps) (SIMDE_SIMD__SSE_TYPE(m128) a, SIMDE_SIMD__SSE_TYPE(m128) b) {
  return a / b;
}
#if defined(SIMDE_SIMD__EMULATE_NATIVE)
#  define _mm_div_ps SIMDE_SIMD__SSE1_SYMBOL(div_ps)
#endif

#endif /* !defined(SIMDE_SIMD__SSE_NATIVE) */
#endif /* !defined(SIMDE_SIMD__SSE_H) */
