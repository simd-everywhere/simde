#if !defined(SIMDE__SSE_H)
#define SIMDE__SSE_H

#include "simde-common.h"

#include "mmx.h"

#if defined(SIMDE__SSE_NATIVE)
#  include <xmmintrin.h>
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
  float          flt[4];
} SIMDE__ALIGN(16) SIMDE__SYMBOL(__m128);

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
  SIMDE__SYMBOL(__m128) r;
  for (size_t i = 0 ; i < (sizeof(r.flt) / sizeof(r.flt[0])) ; i++) {
    r.flt[i] = a.flt[i] + b.flt[i];
  }
  return r;
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
  SIMDE__SYMBOL(__m128) r;
  for (size_t i = 0 ; i < (sizeof(r.i32) / sizeof(r.i32[0])) ; i++) {
    r.i32[i] = a.i32[i] & b.i32[i];
  }
  return r;
}

SIMDE__FUNCTION_ATTRIBUTES
SIMDE__SYMBOL(__m128)
SIMDE__SYMBOL(_mm_andnot_ps) (SIMDE__SYMBOL(__m128) a, SIMDE__SYMBOL(__m128) b) {
  SIMDE__SYMBOL(__m128) r;
  for (size_t i = 0 ; i < (sizeof(r.i32) / sizeof(r.i32[0])) ; i++) {
    r.i32[i] = ~(a.i32[i]) & b.i32[i];
  }
  return r;
}

SIMDE__FUNCTION_ATTRIBUTES
SIMDE__SYMBOL(__m64)
SIMDE__SYMBOL(_mm_avg_pu16) (SIMDE__SYMBOL(__m64) a, SIMDE__SYMBOL(__m64) b) {
  SIMDE__SYMBOL(__m64) r;
  for (size_t i = 0 ; i < 4 ; i++) {
    r.u16[i] = (a.u16[i] + b.u16[i] + 1) >> 1;
  }
  return r;
}

SIMDE__FUNCTION_ATTRIBUTES
SIMDE__SYMBOL(__m64)
SIMDE__SYMBOL(_mm_avg_pu8) (SIMDE__SYMBOL(__m64) a, SIMDE__SYMBOL(__m64) b) {
  SIMDE__SYMBOL(__m64) r;
  for (size_t i = 0 ; i < 8 ; i++) {
    r.u8[i] = (a.u8[i] + b.u8[i] + 1) >> 1;
  }
  return r;
}

SIMDE__FUNCTION_ATTRIBUTES
SIMDE__SYMBOL(__m128)
SIMDE__SYMBOL(_mm_sub_ps) (SIMDE__SYMBOL(__m128) a, SIMDE__SYMBOL(__m128) b) {
  SIMDE__SYMBOL(__m128) r;
  for (size_t i = 0 ; i < (sizeof(r.flt) / sizeof(r.flt[0])) ; i++) {
    r.flt[i] = a.flt[i] - b.flt[i];
  }
  return r;
}

SIMDE__FUNCTION_ATTRIBUTES
SIMDE__SYMBOL(__m128)
SIMDE__SYMBOL(_mm_mul_ps) (SIMDE__SYMBOL(__m128) a, SIMDE__SYMBOL(__m128) b) {
  SIMDE__SYMBOL(__m128) r;
  for (size_t i = 0 ; i < (sizeof(r.flt) / sizeof(r.flt[0])) ; i++) {
    r.flt[i] = a.flt[i] * b.flt[i];
  }
  return r;
}

SIMDE__FUNCTION_ATTRIBUTES
SIMDE__SYMBOL(__m128)
SIMDE__SYMBOL(_mm_div_ps) (SIMDE__SYMBOL(__m128) a, SIMDE__SYMBOL(__m128) b) {
  SIMDE__SYMBOL(__m128) r;
  for (size_t i = 0 ; i < (sizeof(r.flt) / sizeof(r.flt[0])) ; i++) {
    r.flt[i] = a.flt[i] / b.flt[i];
  }
  return r;
}

#endif /* !defined(SIMDE__SSE_NATIVE) */
#endif /* !defined(SIMDE__SSE_H) */
