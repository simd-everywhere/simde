#if !defined(SIMDE__MMX_H)
#define SIMDE__MMX_H

#define SIMDE__MMX_INLINE_FUNC __attribute__((__always_inline__)) static inline

#if !defined(SIMDE__TYPE)
#  define SIMDE__TYPE(name) simde_simd__mmx_##name
#  define SIMDE__SYMBOL(name) simde_simd__mmx_##name
#endif

#if defined(SIMDE__MMX_NATIVE)
#  include <mmintrin.h>
#else

typedef union {
  int i32 __attribute__((__vector_size__(16)));
  short i16 __attribute__((__vector_size__(16)));
} SIMDE__TYPE(m64);
#if defined(SIMDE__EMULATE_NATIVE)
#  if defined(__m64)
#    undef __m64
#  endif
#  define __m64 SIMDE__TYPE(m64)
#endif

SIMDE__MMX_INLINE_FUNC
SIMDE__TYPE(m64)
SIMDE__SYMBOL(set_pi16) (short e3, short e2, short e1, short e0) {
  return (SIMDE__TYPE(m64)) { .i16 = { e0, e1, e2, e3 } };
  /* return (SIMDE__TYPE(m64)) { d, c, b, a }; */
}
#if defined(SIMDE__EMULATE_NATIVE)
#  define _mm_set_pi16 SIMDE__SYMBOL(set_pi16)
#endif

#endif /* !defined(SIMDE__MMX_NATIVE) */
#endif /* !defined(SIMDE__MMX_H) */
