#if !defined(SIMDE__SSE_H)
#define SIMDE__SSE_H

#include "simde-common.h"

#include "mmx.h"

#if defined(SIMDE__SSE_NATIVE)
#  include <xmmintrin.h>
#else

typedef union {
  char  i8  __attribute__((__vector_size__(16)));
  short i16 __attribute__((__vector_size__(16)));
  int   i32 __attribute__((__vector_size__(16)));
  float flt __attribute__((__vector_size__(16)));
} SIMDE__SYMBOL(__m128);

SIMDE__FUNCTION_ATTRIBUTES
SIMDE__SYMBOL(__m128)
SIMDE__SYMBOL(_mm_set_ps) (float a, float b, float c, float d) {
  return (SIMDE__SYMBOL(__m128)) { .flt = { d, c, b, a } };
}

SIMDE__FUNCTION_ATTRIBUTES
SIMDE__SYMBOL(__m128)
SIMDE__SYMBOL(_mm_set1_ps) (float v) {
  return SIMDE__SYMBOL(_mm_set_ps)(v, v, v, v);
}

SIMDE__FUNCTION_ATTRIBUTES
SIMDE__SYMBOL(__m128)
SIMDE__SYMBOL(_mm_add_ps) (SIMDE__SYMBOL(__m128) a, SIMDE__SYMBOL(__m128) b) {
  return (SIMDE__SYMBOL(__m128)) { .flt = a.flt + b.flt };
}

SIMDE__FUNCTION_ATTRIBUTES
SIMDE__SYMBOL(__m128)
SIMDE__SYMBOL(_mm_add_ss) (SIMDE__SYMBOL(__m128) a, SIMDE__SYMBOL(__m128) b) {
  return (SIMDE__SYMBOL(__m128)) {
    .flt = { a.flt[0] + b.flt[0], a.flt[1], a.flt[2], a.flt[3] }
  };
}

SIMDE__FUNCTION_ATTRIBUTES
SIMDE__SYMBOL(__m128)
SIMDE__SYMBOL(_mm_and_ps) (SIMDE__SYMBOL(__m128) a, SIMDE__SYMBOL(__m128) b) {
  return (SIMDE__SYMBOL(__m128)) {
    .i32 = a.i32 & b.i32
  };
}

SIMDE__FUNCTION_ATTRIBUTES
SIMDE__SYMBOL(__m128)
SIMDE__SYMBOL(_mm_andnot_ps) (SIMDE__SYMBOL(__m128) a, SIMDE__SYMBOL(__m128) b) {
  return (SIMDE__SYMBOL(__m128)) {
    .i32 = ~(a.i32) & b.i32
  };
}

SIMDE__FUNCTION_ATTRIBUTES
SIMDE__SYMBOL(__m128)
SIMDE__SYMBOL(_mm_sub_ps) (SIMDE__SYMBOL(__m128) a, SIMDE__SYMBOL(__m128) b) {
  return (SIMDE__SYMBOL(__m128)) {
    .flt = a.flt - b.flt
  };
}

SIMDE__FUNCTION_ATTRIBUTES
SIMDE__SYMBOL(__m128)
SIMDE__SYMBOL(_mm_mul_ps) (SIMDE__SYMBOL(__m128) a, SIMDE__SYMBOL(__m128) b) {
  return (SIMDE__SYMBOL(__m128)) {
    .flt = a.flt * b.flt
  };
}

SIMDE__FUNCTION_ATTRIBUTES
SIMDE__SYMBOL(__m128)
SIMDE__SYMBOL(_mm_div_ps) (SIMDE__SYMBOL(__m128) a, SIMDE__SYMBOL(__m128) b) {
  return (SIMDE__SYMBOL(__m128)) {
    .flt = a.flt / b.flt
  };
}

#endif /* !defined(SIMDE__SSE_NATIVE) */
#endif /* !defined(SIMDE__SSE_H) */
