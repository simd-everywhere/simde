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
  char  i8 __attribute__((__vector_size__(16)));
  short i16 __attribute__((__vector_size__(16)));
  int   i32 __attribute__((__vector_size__(16)));
} SIMDE__TYPE(m64);
#if defined(SIMDE__EMULATE_NATIVE)
#  if defined(__m64)
#    undef __m64
#  endif
#  define __m64 SIMDE__TYPE(m64)
#endif

SIMDE__MMX_INLINE_FUNC
SIMDE__TYPE(m64)
SIMDE__SYMBOL(add_pi8) (__m64 a, __m64 b) {
  return (SIMDE__TYPE(m64)) { .i8 = a.i8 + b.i8 };
}
#if defined(SIMDE__EMULATE_NATIVE)
#  define _mm_add_pi8 SIMDE__SYMBOL(add_pi8)
#endif

SIMDE__MMX_INLINE_FUNC
SIMDE__TYPE(m64)
SIMDE__SYMBOL(add_pi16) (__m64 a, __m64 b) {
  return (SIMDE__TYPE(m64)) { .i16 = a.i16 + b.i16 };
}
#if defined(SIMDE__EMULATE_NATIVE)
#  define _mm_add_pi16 SIMDE__SYMBOL(add_pi16)
#endif

SIMDE__MMX_INLINE_FUNC
SIMDE__TYPE(m64)
SIMDE__SYMBOL(add_pi32) (__m64 a, __m64 b) {
  return (SIMDE__TYPE(m64)) { .i32 = a.i32 + b.i32 };
}
#if defined(SIMDE__EMULATE_NATIVE)
#  define _mm_add_pi32 SIMDE__SYMBOL(add_pi32)
#endif

SIMDE__MMX_INLINE_FUNC
SIMDE__TYPE(m64)
SIMDE__SYMBOL(set_pi8) (char e7, char e6, char e5, char e4, char e3, char e2, char e1, char e0) {
  return (SIMDE__TYPE(m64)) { .i8 = { e0, e1, e2, e3, e4, e5, e6, e7 } };
}
#if defined(SIMDE__EMULATE_NATIVE)
#  define _mm_set_pi8 SIMDE__SYMBOL(set_pi8)
#endif

SIMDE__MMX_INLINE_FUNC
SIMDE__TYPE(m64)
SIMDE__SYMBOL(set_pi16) (short e3, short e2, short e1, short e0) {
  return (SIMDE__TYPE(m64)) { .i16 = { e0, e1, e2, e3 } };
}
#if defined(SIMDE__EMULATE_NATIVE)
#  define _mm_set_pi16 SIMDE__SYMBOL(set_pi16)
#endif

SIMDE__MMX_INLINE_FUNC
SIMDE__TYPE(m64)
SIMDE__SYMBOL(set_pi32) (int e1, int e0) {
  return (SIMDE__TYPE(m64)) { .i32 = { e0, e1 } };
}
#if defined(SIMDE__EMULATE_NATIVE)
#  define _mm_set_pi32 SIMDE__SYMBOL(set_pi32)
#endif

SIMDE__MMX_INLINE_FUNC
SIMDE__TYPE(m64)
SIMDE__SYMBOL(set1_pi8) (char a) {
  return SIMDE__SYMBOL(set_pi8)(a, a, a, a, a, a, a, a);
}
#if defined(SIMDE__EMULATE_NATIVE)
#  define _mm_set1_pi8 SIMDE__SYMBOL(set1_pi8)
#endif

SIMDE__MMX_INLINE_FUNC
SIMDE__TYPE(m64)
SIMDE__SYMBOL(set1_pi16) (char a) {
  return SIMDE__SYMBOL(set_pi16)(a, a, a, a);
}
#if defined(SIMDE__EMULATE_NATIVE)
#  define _mm_set1_pi16 SIMDE__SYMBOL(set1_pi16)
#endif

SIMDE__MMX_INLINE_FUNC
SIMDE__TYPE(m64)
SIMDE__SYMBOL(set1_pi32) (char a) {
  return SIMDE__SYMBOL(set_pi32)(a, a);
}
#if defined(SIMDE__EMULATE_NATIVE)
#  define _mm_set1_pi32 SIMDE__SYMBOL(set1_pi32)
#endif

SIMDE__MMX_INLINE_FUNC
SIMDE__TYPE(m64)
SIMDE__SYMBOL(setr_pi8) (char e7, char e6, char e5, char e4, char e3, char e2, char e1, char e0) {
  return (SIMDE__TYPE(m64)) { .i8 = { e7, e6, e5, e4, e3, e2, e1, e0 } };
}
#if defined(SIMDE__EMULATE_NATIVE)
#  define _mm_setr_pi8 SIMDE__SYMBOL(setr_pi8)
#endif

SIMDE__MMX_INLINE_FUNC
SIMDE__TYPE(m64)
SIMDE__SYMBOL(setr_pi16) (short e3, short e2, short e1, short e0) {
  return (SIMDE__TYPE(m64)) { .i16 = { e3, e2, e1, e0 } };
}
#if defined(SIMDE__EMULATE_NATIVE)
#  define _mm_setr_pi16 SIMDE__SYMBOL(setr_pi16)
#endif

SIMDE__MMX_INLINE_FUNC
SIMDE__TYPE(m64)
SIMDE__SYMBOL(setr_pi32) (int e1, int e0) {
  return (SIMDE__TYPE(m64)) { .i32 = { e1, e0 } };
}
#if defined(SIMDE__EMULATE_NATIVE)
#  define _mm_setr_pi32 SIMDE__SYMBOL(setr_pi32)
#endif

SIMDE__MMX_INLINE_FUNC
SIMDE__TYPE(m64)
SIMDE__SYMBOL(setzero_si64) (void) {
  return (SIMDE__TYPE(m64)) { .i32 = { 0, 0 } };
}
#if defined(SIMDE__EMULATE_NATIVE)
#  define _mm_setzero_si64 SIMDE__SYMBOL(setr_si64)
#endif

#endif /* !defined(SIMDE__MMX_NATIVE) */
#endif /* !defined(SIMDE__MMX_H) */
