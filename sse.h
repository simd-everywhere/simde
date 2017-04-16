#if !defined(SIMDE__SSE_H)
#define SIMDE__SSE_H

#include "simde-common.h"

#include "mmx.h"

#if !defined(SIMDE__SSE_NATIVE) && !defined(SIMDE__SSE_NO_NATIVE) && defined(__SSE__)
#  define SIMDE__SSE_NATIVE
#endif

#if defined(SIMDE__SSE_NATIVE)
#  include <xmmintrin.h>
#else
#  include <math.h>
#endif

#if defined(SIMDE__MMX_NATIVE)
typedef __m128 SIMDE__SYMBOL_U(_m128);
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
  float          f32[4];
} SIMDE__ALIGN(16) SIMDE__SYMBOL_U(_m128);
#endif

SIMDE__FUNCTION_ATTRIBUTES
SIMDE__SYMBOL_U(_m128)
SIMDE__SYMBOL_U(mm_set_ps) (float a, float b, float c, float d) {
#if defined(SIMDE__SSE_NATIVE)
  return _mm_set_ps(a, b, c, d);
#else
  return (SIMDE__SYMBOL_U(_m128)) { .f32 = { d, c, b, a } };
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
SIMDE__SYMBOL_U(_m128)
SIMDE__SYMBOL_U(mm_set1_ps) (float v) {
#if defined(SIMDE__SSE_NATIVE)
  return _mm_set1_ps(v);
#else
  return SIMDE__SYMBOL_U(mm_set_ps)(v, v, v, v);
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
SIMDE__SYMBOL_U(_m128)
SIMDE__SYMBOL_U(mm_add_ps) (SIMDE__SYMBOL_U(_m128) a, SIMDE__SYMBOL_U(_m128) b) {
#if defined(SIMDE__SSE_NATIVE)
  return _mm_add_ps(a, b);
#else
  SIMDE__SYMBOL_U(_m128) r;
  for (size_t i = 0 ; i < (sizeof(r.f32) / sizeof(r.f32[0])) ; i++) {
    r.f32[i] = a.f32[i] + b.f32[i];
  }
  return r;
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
SIMDE__SYMBOL_U(_m128)
SIMDE__SYMBOL_U(mm_add_ss) (SIMDE__SYMBOL_U(_m128) a, SIMDE__SYMBOL_U(_m128) b) {
#if defined(SIMDE__SSE_NATIVE)
  return _mm_add_ss(a, b);
#else
  return (SIMDE__SYMBOL_U(_m128)) {
    .f32 = { a.f32[0] + b.f32[0], a.f32[1], a.f32[2], a.f32[3] }
  };
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
SIMDE__SYMBOL_U(_m128)
SIMDE__SYMBOL_U(mm_and_ps) (SIMDE__SYMBOL_U(_m128) a, SIMDE__SYMBOL_U(_m128) b) {
#if defined(SIMDE__SSE_NATIVE)
  return _mm_and_ps(a, b);
#else
  SIMDE__SYMBOL_U(_m128) r;
  for (size_t i = 0 ; i < (sizeof(r.i32) / sizeof(r.i32[0])) ; i++) {
    r.i32[i] = a.i32[i] & b.i32[i];
  }
  return r;
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
SIMDE__SYMBOL_U(_m128)
SIMDE__SYMBOL_U(mm_andnot_ps) (SIMDE__SYMBOL_U(_m128) a, SIMDE__SYMBOL_U(_m128) b) {
#if defined(SIMDE__SSE_NATIVE)
  return _mm_andnot_ps(a, b);
#else
  SIMDE__SYMBOL_U(_m128) r;
  for (size_t i = 0 ; i < (sizeof(r.i32) / sizeof(r.i32[0])) ; i++) {
    r.i32[i] = ~(a.i32[i]) & b.i32[i];
  }
  return r;
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
SIMDE__SYMBOL_U(_m64)
SIMDE__SYMBOL_U(mm_avg_pu16) (SIMDE__SYMBOL_U(_m64) a, SIMDE__SYMBOL_U(_m64) b) {
#if defined(SIMDE__SSE_NATIVE)
  return _mm_avg_pu16(a, b);
#else
  SIMDE__SYMBOL_U(_m64) r;
  for (size_t i = 0 ; i < 4 ; i++) {
    r.u16[i] = (a.u16[i] + b.u16[i] + 1) >> 1;
  }
  return r;
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
SIMDE__SYMBOL_U(_m64)
SIMDE__SYMBOL_U(mm_avg_pu8) (SIMDE__SYMBOL_U(_m64) a, SIMDE__SYMBOL_U(_m64) b) {
#if defined(SIMDE__SSE_NATIVE)
  return _mm_avg_pu8(a, b);
#else
  SIMDE__SYMBOL_U(_m64) r;
  for (size_t i = 0 ; i < 8 ; i++) {
    r.u8[i] = (a.u8[i] + b.u8[i] + 1) >> 1;
  }
  return r;
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
SIMDE__SYMBOL_U(_m128)
SIMDE__SYMBOL_U(mm_cmpeq_ps) (SIMDE__SYMBOL_U(_m128) a, SIMDE__SYMBOL_U(_m128) b) {
#if defined(SIMDE__SSE_NATIVE)
  return _mm_cmpeq_ps(a, b);
#else
  SIMDE__SYMBOL_U(_m128) r;
  for (size_t i = 0 ; i < (sizeof(r.f32) / sizeof(r.f32[0])) ; i++) {
    r.u32[i] = (a.f32[i] == b.f32[i]) ? 0xffffffff : 0;
  }
  return r;
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
SIMDE__SYMBOL_U(_m128)
SIMDE__SYMBOL_U(mm_cmpeq_ss) (SIMDE__SYMBOL_U(_m128) a, SIMDE__SYMBOL_U(_m128) b) {
#if defined(SIMDE__SSE_NATIVE)
  return _mm_cmpeq_ss(a, b);
#else
  SIMDE__SYMBOL_U(_m128) r;
  r.u32[0] = (a.f32[0] == b.f32[0]) ? 0xffffffff : 0;
  for (size_t i = 1 ; i < (sizeof(r.f32) / sizeof(r.f32[0])) ; i++) {
    r.u32[i] = a.u32[i];
  }
  return r;
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
SIMDE__SYMBOL_U(_m128)
SIMDE__SYMBOL_U(mm_cmpge_ps) (SIMDE__SYMBOL_U(_m128) a, SIMDE__SYMBOL_U(_m128) b) {
#if defined(SIMDE__SSE_NATIVE)
  return _mm_cmpge_ps(a, b);
#else
  SIMDE__SYMBOL_U(_m128) r;
  for (size_t i = 0 ; i < (sizeof(r.f32) / sizeof(r.f32[0])) ; i++) {
    r.u32[i] = (a.f32[i] >= b.f32[i]) ? 0xffffffff : 0;
  }
  return r;
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
SIMDE__SYMBOL_U(_m128)
SIMDE__SYMBOL_U(mm_cmpge_ss) (SIMDE__SYMBOL_U(_m128) a, SIMDE__SYMBOL_U(_m128) b) {
#if defined(SIMDE__SSE_NATIVE)
  return _mm_cmpge_ss(a, b);
#else
  SIMDE__SYMBOL_U(_m128) r;
  r.u32[0] = (a.f32[0] >= b.f32[0]) ? 0xffffffff : 0;
  for (size_t i = 1 ; i < (sizeof(r.f32) / sizeof(r.f32[0])) ; i++) {
    r.u32[i] = a.u32[i];
  }
  return r;
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
SIMDE__SYMBOL_U(_m128)
SIMDE__SYMBOL_U(mm_cmpgt_ps) (SIMDE__SYMBOL_U(_m128) a, SIMDE__SYMBOL_U(_m128) b) {
#if defined(SIMDE__SSE_NATIVE)
  return _mm_cmpgt_ps(a, b);
#else
  SIMDE__SYMBOL_U(_m128) r;
  for (size_t i = 0 ; i < (sizeof(r.f32) / sizeof(r.f32[0])) ; i++) {
    r.u32[i] = (a.f32[i] > b.f32[i]) ? 0xffffffff : 0;
  }
  return r;
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
SIMDE__SYMBOL_U(_m128)
SIMDE__SYMBOL_U(mm_cmpgt_ss) (SIMDE__SYMBOL_U(_m128) a, SIMDE__SYMBOL_U(_m128) b) {
#if defined(SIMDE__SSE_NATIVE)
  return _mm_cmpgt_ss(a, b);
#else
  SIMDE__SYMBOL_U(_m128) r;
  r.u32[0] = (a.f32[0] > b.f32[0]) ? 0xffffffff : 0;
  for (size_t i = 1 ; i < (sizeof(r.f32) / sizeof(r.f32[0])) ; i++) {
    r.u32[i] = a.u32[i];
  }
  return r;
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
SIMDE__SYMBOL_U(_m128)
SIMDE__SYMBOL_U(mm_cmple_ps) (SIMDE__SYMBOL_U(_m128) a, SIMDE__SYMBOL_U(_m128) b) {
#if defined(SIMDE__SSE_NATIVE)
  return _mm_cmple_ps(a, b);
#else
  SIMDE__SYMBOL_U(_m128) r;
  for (size_t i = 0 ; i < (sizeof(r.f32) / sizeof(r.f32[0])) ; i++) {
    r.u32[i] = (a.f32[i] <= b.f32[i]) ? 0xffffffff : 0;
  }
  return r;
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
SIMDE__SYMBOL_U(_m128)
SIMDE__SYMBOL_U(mm_cmple_ss) (SIMDE__SYMBOL_U(_m128) a, SIMDE__SYMBOL_U(_m128) b) {
#if defined(SIMDE__SSE_NATIVE)
  return _mm_cmple_ss(a, b);
#else
  SIMDE__SYMBOL_U(_m128) r;
  r.u32[0] = (a.f32[0] <= b.f32[0]) ? 0xffffffff : 0;
  for (size_t i = 1 ; i < (sizeof(r.f32) / sizeof(r.f32[0])) ; i++) {
    r.u32[i] = a.u32[i];
  }
  return r;
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
SIMDE__SYMBOL_U(_m128)
SIMDE__SYMBOL_U(mm_cmplt_ps) (SIMDE__SYMBOL_U(_m128) a, SIMDE__SYMBOL_U(_m128) b) {
#if defined(SIMDE__SSE_NATIVE)
  return _mm_cmplt_ps(a, b);
#else
  SIMDE__SYMBOL_U(_m128) r;
  for (size_t i = 0 ; i < (sizeof(r.f32) / sizeof(r.f32[0])) ; i++) {
    r.u32[i] = (a.f32[i] < b.f32[i]) ? 0xffffffff : 0;
  }
  return r;
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
SIMDE__SYMBOL_U(_m128)
SIMDE__SYMBOL_U(mm_cmplt_ss) (SIMDE__SYMBOL_U(_m128) a, SIMDE__SYMBOL_U(_m128) b) {
#if defined(SIMDE__SSE_NATIVE)
  return _mm_cmplt_ss(a, b);
#else
  SIMDE__SYMBOL_U(_m128) r;
  r.u32[0] = (a.f32[0] < b.f32[0]) ? 0xffffffff : 0;
  for (size_t i = 1 ; i < (sizeof(r.f32) / sizeof(r.f32[0])) ; i++) {
    r.u32[i] = a.u32[i];
  }
  return r;
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
SIMDE__SYMBOL_U(_m128)
SIMDE__SYMBOL_U(mm_cmpneq_ps) (SIMDE__SYMBOL_U(_m128) a, SIMDE__SYMBOL_U(_m128) b) {
#if defined(SIMDE__SSE_NATIVE)
  return _mm_cmpneq_ps(a, b);
#else
  SIMDE__SYMBOL_U(_m128) r;
  for (size_t i = 0 ; i < (sizeof(r.f32) / sizeof(r.f32[0])) ; i++) {
    r.u32[i] = (a.f32[i] != b.f32[i]) ? 0xffffffff : 0;
  }
  return r;
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
SIMDE__SYMBOL_U(_m128)
SIMDE__SYMBOL_U(mm_cmpneq_ss) (SIMDE__SYMBOL_U(_m128) a, SIMDE__SYMBOL_U(_m128) b) {
#if defined(SIMDE__SSE_NATIVE)
  return _mm_cmpneq_ss(a, b);
#else
  SIMDE__SYMBOL_U(_m128) r;
  r.u32[0] = (a.f32[0] != b.f32[0]) ? 0xffffffff : 0;
  for (size_t i = 1 ; i < (sizeof(r.f32) / sizeof(r.f32[0])) ; i++) {
    r.u32[i] = a.u32[i];
  }
  return r;
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
SIMDE__SYMBOL_U(_m128)
SIMDE__SYMBOL_U(mm_cmpnge_ps) (SIMDE__SYMBOL_U(_m128) a, SIMDE__SYMBOL_U(_m128) b) {
#if defined(SIMDE__SSE_NATIVE)
  return _mm_cmpnge_ps(a, b);
#else
  return SIMDE__SYMBOL_U(mm_cmplt_ps)(a, b);
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
SIMDE__SYMBOL_U(_m128)
SIMDE__SYMBOL_U(mm_cmpnge_ss) (SIMDE__SYMBOL_U(_m128) a, SIMDE__SYMBOL_U(_m128) b) {
#if defined(SIMDE__SSE_NATIVE)
  return _mm_cmpnge_ss(a, b);
#else
  return SIMDE__SYMBOL_U(mm_cmplt_ss)(a, b);
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
SIMDE__SYMBOL_U(_m128)
SIMDE__SYMBOL_U(mm_cmpngt_ps) (SIMDE__SYMBOL_U(_m128) a, SIMDE__SYMBOL_U(_m128) b) {
#if defined(SIMDE__SSE_NATIVE)
  return _mm_cmpngt_ps(a, b);
#else
  return SIMDE__SYMBOL_U(mm_cmple_ps)(a, b);
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
SIMDE__SYMBOL_U(_m128)
SIMDE__SYMBOL_U(mm_cmpngt_ss) (SIMDE__SYMBOL_U(_m128) a, SIMDE__SYMBOL_U(_m128) b) {
#if defined(SIMDE__SSE_NATIVE)
  return _mm_cmpngt_ss(a, b);
#else
  return SIMDE__SYMBOL_U(mm_cmple_ss)(a, b);
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
SIMDE__SYMBOL_U(_m128)
SIMDE__SYMBOL_U(mm_cmpnle_ps) (SIMDE__SYMBOL_U(_m128) a, SIMDE__SYMBOL_U(_m128) b) {
#if defined(SIMDE__SSE_NATIVE)
  return _mm_cmpnle_ps(a, b);
#else
  return SIMDE__SYMBOL_U(mm_cmpgt_ps)(a, b);
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
SIMDE__SYMBOL_U(_m128)
SIMDE__SYMBOL_U(mm_cmpnle_ss) (SIMDE__SYMBOL_U(_m128) a, SIMDE__SYMBOL_U(_m128) b) {
#if defined(SIMDE__SSE_NATIVE)
  return _mm_cmpnle_ss(a, b);
#else
  return SIMDE__SYMBOL_U(mm_cmpgt_ss)(a, b);
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
SIMDE__SYMBOL_U(_m128)
SIMDE__SYMBOL_U(mm_cmpnlt_ps) (SIMDE__SYMBOL_U(_m128) a, SIMDE__SYMBOL_U(_m128) b) {
#if defined(SIMDE__SSE_NATIVE)
  return _mm_cmpnlt_ps(a, b);
#else
  return SIMDE__SYMBOL_U(mm_cmpge_ps)(a, b);
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
SIMDE__SYMBOL_U(_m128)
SIMDE__SYMBOL_U(mm_cmpnlt_ss) (SIMDE__SYMBOL_U(_m128) a, SIMDE__SYMBOL_U(_m128) b) {
#if defined(SIMDE__SSE_NATIVE)
  return _mm_cmpnlt_ss(a, b);
#else
  return SIMDE__SYMBOL_U(mm_cmpge_ss)(a, b);
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
SIMDE__SYMBOL_U(_m128)
SIMDE__SYMBOL_U(mm_cmpord_ps) (SIMDE__SYMBOL_U(_m128) a, SIMDE__SYMBOL_U(_m128) b) {
#if defined(SIMDE__SSE_NATIVE)
  return _mm_cmpord_ps(a, b);
#else
  SIMDE__SYMBOL_U(_m128) r;
  for (size_t i = 0 ; i < (sizeof(r.f32) / sizeof(r.f32[0])) ; i++) {
    r.u32[i] = (isnan(a.f32[i]) || isnan(b.f32[i])) ? 0 : 0xffffffff;
  }
  return r;
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
SIMDE__SYMBOL_U(_m128)
SIMDE__SYMBOL_U(mm_cmpord_ss) (SIMDE__SYMBOL_U(_m128) a, SIMDE__SYMBOL_U(_m128) b) {
#if defined(SIMDE__SSE_NATIVE)
  return _mm_cmpord_ss(a, b);
#else
  SIMDE__SYMBOL_U(_m128) r;
  r.u32[0] = (isnan(a.f32[0]) || isnan(b.f32[0])) ? 0 : 0xffffffff;
  for (size_t i = 1 ; i < (sizeof(r.f32) / sizeof(r.f32[0])) ; i++) {
    r.f32[i] = a.f32[i];
  }
  return r;
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
SIMDE__SYMBOL_U(_m128)
SIMDE__SYMBOL_U(mm_cmpunord_ps) (SIMDE__SYMBOL_U(_m128) a, SIMDE__SYMBOL_U(_m128) b) {
#if defined(SIMDE__SSE_NATIVE)
  return _mm_cmpunord_ps(a, b);
#else
  SIMDE__SYMBOL_U(_m128) r;
  for (size_t i = 0 ; i < (sizeof(r.f32) / sizeof(r.f32[0])) ; i++) {
    r.u32[i] = (isnan(a.f32[i]) || isnan(b.f32[i])) ? 0xffffffff : 0;
  }
  return r;
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
SIMDE__SYMBOL_U(_m128)
SIMDE__SYMBOL_U(mm_cmpunord_ss) (SIMDE__SYMBOL_U(_m128) a, SIMDE__SYMBOL_U(_m128) b) {
#if defined(SIMDE__SSE_NATIVE)
  return _mm_cmpunord_ss(a, b);
#else
  SIMDE__SYMBOL_U(_m128) r;
  r.u32[0] = (isnan(a.f32[0]) || isnan(b.f32[0])) ? 0xffffffff : 0;
  for (size_t i = 1 ; i < (sizeof(r.f32) / sizeof(r.f32[0])) ; i++) {
    r.f32[i] = a.f32[i];
  }
  return r;
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
int
SIMDE__SYMBOL_U(mm_comieq_ss) (SIMDE__SYMBOL_U(_m128) a, SIMDE__SYMBOL_U(_m128) b) {
#if defined(SIMDE__SSE_NATIVE)
  return _mm_comieq_ss(a, b);
#else
  return a.f32[0] == b.f32[0];
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
int
SIMDE__SYMBOL_U(mm_comige_ss) (SIMDE__SYMBOL_U(_m128) a, SIMDE__SYMBOL_U(_m128) b) {
#if defined(SIMDE__SSE_NATIVE)
  return _mm_comige_ss(a, b);
#else
  return a.f32[0] >= b.f32[0];
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
int
SIMDE__SYMBOL_U(mm_comigt_ss) (SIMDE__SYMBOL_U(_m128) a, SIMDE__SYMBOL_U(_m128) b) {
#if defined(SIMDE__SSE_NATIVE)
  return _mm_comigt_ss(a, b);
#else
  return a.f32[0] > b.f32[0];
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
int
SIMDE__SYMBOL_U(mm_comile_ss) (SIMDE__SYMBOL_U(_m128) a, SIMDE__SYMBOL_U(_m128) b) {
#if defined(SIMDE__SSE_NATIVE)
  return _mm_comile_ss(a, b);
#else
  return a.f32[0] <= b.f32[0];
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
int
SIMDE__SYMBOL_U(mm_comilt_ss) (SIMDE__SYMBOL_U(_m128) a, SIMDE__SYMBOL_U(_m128) b) {
#if defined(SIMDE__SSE_NATIVE)
  return _mm_comilt_ss(a, b);
#else
  return a.f32[0] < b.f32[0];
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
int
SIMDE__SYMBOL_U(mm_comineq_ss) (SIMDE__SYMBOL_U(_m128) a, SIMDE__SYMBOL_U(_m128) b) {
#if defined(SIMDE__SSE_NATIVE)
  return _mm_comineq_ss(a, b);
#else
  return a.f32[0] != b.f32[0];
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
SIMDE__SYMBOL_U(_m128)
SIMDE__SYMBOL_U(mm_sub_ps) (SIMDE__SYMBOL_U(_m128) a, SIMDE__SYMBOL_U(_m128) b) {
#if defined(SIMDE__SSE_NATIVE)
  return _mm_sub_ps(a, b);
#else
  SIMDE__SYMBOL_U(_m128) r;
  for (size_t i = 0 ; i < (sizeof(r.f32) / sizeof(r.f32[0])) ; i++) {
    r.f32[i] = a.f32[i] - b.f32[i];
  }
  return r;
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
SIMDE__SYMBOL_U(_m128)
SIMDE__SYMBOL_U(mm_mul_ps) (SIMDE__SYMBOL_U(_m128) a, SIMDE__SYMBOL_U(_m128) b) {
#if defined(SIMDE__SSE_NATIVE)
  return _mm_mul_ps(a, b);
#else
  SIMDE__SYMBOL_U(_m128) r;
  for (size_t i = 0 ; i < (sizeof(r.f32) / sizeof(r.f32[0])) ; i++) {
    r.f32[i] = a.f32[i] * b.f32[i];
  }
  return r;
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
SIMDE__SYMBOL_U(_m128)
SIMDE__SYMBOL_U(mm_div_ps) (SIMDE__SYMBOL_U(_m128) a, SIMDE__SYMBOL_U(_m128) b) {
#if defined(SIMDE__SSE_NATIVE)
  return _mm_div_ps(a, b);
#else
  SIMDE__SYMBOL_U(_m128) r;
  for (size_t i = 0 ; i < (sizeof(r.f32) / sizeof(r.f32[0])) ; i++) {
    r.f32[i] = a.f32[i] / b.f32[i];
  }
  return r;
#endif
}

#endif /* !defined(SIMDE__SSE_H) */
