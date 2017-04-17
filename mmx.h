#if !defined(SIMDE__MMX_H)
#define SIMDE__MMX_H

#include "simde-common.h"

#if !defined(SIMDE__MMX_NATIVE) && !defined(SIMDE__MMX_NO_NATIVE) && defined(__MMX__)
#  define SIMDE__MMX_NATIVE
#endif

#if defined(SIMDE__MMX_NATIVE)
#  include <mmintrin.h>
#endif

#include <stdint.h>
#include <limits.h>
#include <stdlib.h>

typedef SIMDE__ALIGN(16) union {
  char           i8[8];
  short          i16[4];
  int            i32[2];
  int64_t        i64;
  unsigned char  u8[8];
  unsigned short u16[4];
  unsigned int   u32[2];
  uint64_t       u64;
  float          f32[2];
#if defined(SIMDE__MMX_NATIVE)
  __m64          n;
#endif
} SIMDE__SYMBOL_U(_m64);

#if defined(SIMDE__MMX_NATIVE)
HEDLEY_STATIC_ASSERT(sizeof(__m64) == sizeof(SIMDE__SYMBOL_U(_m64)), "__m64 size incorrect");
#define SIMDE__M64_C(expr) ((SIMDE__SYMBOL_U(_m64)) { .n = expr })
#endif

SIMDE__FUNCTION_ATTRIBUTES
SIMDE__SYMBOL_U(_m64)
SIMDE__SYMBOL_U(mm_add_pi8) (SIMDE__SYMBOL_U(_m64) a, SIMDE__SYMBOL_U(_m64) b) {
#if defined(SIMDE__MMX_NATIVE)
  return SIMDE__M64_C(_mm_add_pi8(a.n, b.n));
#else
  SIMDE__SYMBOL_U(_m64) r;
  for (size_t i = 0 ; i < 8 ; i++) {
    r.i8[i] = a.i8[i] + b.i8[i];
  }
  return r;
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
SIMDE__SYMBOL_U(_m64)
SIMDE__SYMBOL_U(m_paddb) (SIMDE__SYMBOL_U(_m64) a, SIMDE__SYMBOL_U(_m64) b) {
#if defined(SIMDE__MMX_NATIVE)
  return SIMDE__M64_C(_m_paddb(a.n, b.n));
#else
  return SIMDE__SYMBOL_U(mm_add_pi8)(a, b);
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
SIMDE__SYMBOL_U(_m64)
SIMDE__SYMBOL_U(mm_add_pi16) (SIMDE__SYMBOL_U(_m64) a, SIMDE__SYMBOL_U(_m64) b) {
#if defined(SIMDE__MMX_NATIVE)
  return SIMDE__M64_C(_mm_add_pi16(a.n, b.n));
#else
  SIMDE__SYMBOL_U(_m64) r;
  for (size_t i = 0 ; i < (8 / sizeof(short)) ; i++) {
    r.i16[i] = a.i16[i] + b.i16[i];
  }
  return r;
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
SIMDE__SYMBOL_U(_m64)
SIMDE__SYMBOL_U(m_paddw) (SIMDE__SYMBOL_U(_m64) a, SIMDE__SYMBOL_U(_m64) b) {
#if defined(SIMDE__MMX_NATIVE)
  return SIMDE__M64_C(_m_paddw(a.n, b.n));
#else
  return SIMDE__SYMBOL_U(mm_add_pi16)(a, b);
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
SIMDE__SYMBOL_U(_m64)
SIMDE__SYMBOL_U(mm_add_pi32) (SIMDE__SYMBOL_U(_m64) a, SIMDE__SYMBOL_U(_m64) b) {
#if defined(SIMDE__MMX_NATIVE)
  return SIMDE__M64_C(_mm_add_pi32(a.n, b.n));
#else
  SIMDE__SYMBOL_U(_m64) r;
  for (size_t i = 0 ; i < (8 / sizeof(int)) ; i++) {
    r.i32[i] = a.i32[i] + b.i32[i];
  }
  return r;
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
SIMDE__SYMBOL_U(_m64)
SIMDE__SYMBOL_U(m_paddd) (SIMDE__SYMBOL_U(_m64) a, SIMDE__SYMBOL_U(_m64) b) {
#if defined(SIMDE__MMX_NATIVE)
  return SIMDE__M64_C(_m_paddd(a.n, b.n));
#else
  return SIMDE__SYMBOL_U(mm_add_pi32)(a, b);
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
SIMDE__SYMBOL_U(_m64)
SIMDE__SYMBOL_U(mm_adds_pi8) (SIMDE__SYMBOL_U(_m64) a, SIMDE__SYMBOL_U(_m64) b) {
#if defined(SIMDE__MMX_NATIVE)
  return SIMDE__M64_C(_mm_adds_pi8(a.n, b.n));
#else
  SIMDE__SYMBOL_U(_m64) r;
  for (int i = 0 ; i < 8 ; i++) {
    if ((((b.i8[i]) > 0) && ((a.i8[i]) > (CHAR_MAX - (b.i8[i]))))) {
      r.i8[i] = CHAR_MAX;
    } else if ((((b.i8[i]) < 0) && ((a.i8[i]) < (CHAR_MIN - (b.i8[i]))))) {
      r.i8[i] = CHAR_MIN;
    } else {
      r.i8[i] = (a.i8[i]) + (b.i8[i]);
    }
  }
  return r;
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
SIMDE__SYMBOL_U(_m64)
SIMDE__SYMBOL_U(m_paddsb) (SIMDE__SYMBOL_U(_m64) a, SIMDE__SYMBOL_U(_m64) b) {
#if defined(SIMDE__MMX_NATIVE)
  return SIMDE__M64_C(_m_paddsb(a.n, b.n));
#else
  return SIMDE__SYMBOL_U(mm_adds_pi8)(a, b);
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
SIMDE__SYMBOL_U(_m64)
SIMDE__SYMBOL_U(mm_adds_pu8) (SIMDE__SYMBOL_U(_m64) a, SIMDE__SYMBOL_U(_m64) b) {
#if defined(SIMDE__MMX_NATIVE)
  return SIMDE__M64_C(_mm_adds_pu8(a.n, b.n));
#else
  SIMDE__SYMBOL_U(_m64) r;
  for (size_t i = 0 ; i < 8 ; i++) {
    const int x = a.u8[i] + b.u8[i];
    if (x < 0)
      r.u8[i] = 0;
    else if (x > UCHAR_MAX)
      r.u8[i] = UCHAR_MAX;
    else
      r.u8[i] = (unsigned char) x;
  }
  return r;
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
SIMDE__SYMBOL_U(_m64)
SIMDE__SYMBOL_U(m_paddusb) (SIMDE__SYMBOL_U(_m64) a, SIMDE__SYMBOL_U(_m64) b) {
#if defined(SIMDE__MMX_NATIVE)
  return SIMDE__M64_C(_m_paddusb(a.n, b.n));
#else
  return SIMDE__SYMBOL_U(mm_adds_pu8)(a, b);
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
SIMDE__SYMBOL_U(_m64)
SIMDE__SYMBOL_U(mm_adds_pi16) (SIMDE__SYMBOL_U(_m64) a, SIMDE__SYMBOL_U(_m64) b) {
#if defined(SIMDE__MMX_NATIVE)
  return SIMDE__M64_C(_mm_adds_pi16(a.n, b.n));
#else
  SIMDE__SYMBOL_U(_m64) r;
  for (int i = 0 ; i < 4 ; i++) {
    if ((((b.i16[i]) > 0) && ((a.i16[i]) > (SHRT_MAX - (b.i16[i]))))) {
      r.i16[i] = SHRT_MAX;
    } else if ((((b.i16[i]) < 0) && ((a.i16[i]) < (SHRT_MIN - (b.i16[i]))))) {
      r.i16[i] = SHRT_MIN;
    } else {
      r.i16[i] = (a.i16[i]) + (b.i16[i]);
    }
  }
  return r;
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
SIMDE__SYMBOL_U(_m64)
SIMDE__SYMBOL_U(m_paddsw) (SIMDE__SYMBOL_U(_m64) a, SIMDE__SYMBOL_U(_m64) b) {
#if defined(SIMDE__MMX_NATIVE)
  return SIMDE__M64_C(_m_paddsw(a.n, b.n));
#else
  return SIMDE__SYMBOL_U(mm_adds_pi16)(a, b);
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
SIMDE__SYMBOL_U(_m64)
SIMDE__SYMBOL_U(mm_adds_pu16) (SIMDE__SYMBOL_U(_m64) a, SIMDE__SYMBOL_U(_m64) b) {
#if defined(SIMDE__MMX_NATIVE)
  return SIMDE__M64_C(_mm_adds_pu16(a.n, b.n));
#else
  SIMDE__SYMBOL_U(_m64) r;
  for (size_t i = 0 ; i < (8 / sizeof(short)) ; i++) {
    const unsigned int x = a.u16[i] + b.u16[i];
    if (x > USHRT_MAX)
      r.u16[i] = USHRT_MAX;
    else
      r.u16[i] = (unsigned short) x;
  }
  return r;
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
SIMDE__SYMBOL_U(_m64)
SIMDE__SYMBOL_U(m_paddusw) (SIMDE__SYMBOL_U(_m64) a, SIMDE__SYMBOL_U(_m64) b) {
#if defined(SIMDE__MMX_NATIVE)
  return SIMDE__M64_C(_m_paddusw(a.n, b.n));
#else
  return SIMDE__SYMBOL_U(mm_adds_pu16)(a, b);
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
SIMDE__SYMBOL_U(_m64)
SIMDE__SYMBOL_U(mm_and_si64) (SIMDE__SYMBOL_U(_m64) a, SIMDE__SYMBOL_U(_m64) b) {
#if defined(SIMDE__MMX_NATIVE)
  return SIMDE__M64_C(_mm_and_si64(a.n, b.n));
#else
  return (SIMDE__SYMBOL_U(_m64)) { .i64 = a.i64 & b.i64 };
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
SIMDE__SYMBOL_U(_m64)
SIMDE__SYMBOL_U(m_pand) (SIMDE__SYMBOL_U(_m64) a, SIMDE__SYMBOL_U(_m64) b) {
#if defined(SIMDE__MMX_NATIVE)
  return SIMDE__M64_C(_m_pand(a.n, b.n));
#else
  return SIMDE__SYMBOL_U(mm_and_si64)(a, b);
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
SIMDE__SYMBOL_U(_m64)
SIMDE__SYMBOL_U(mm_andnot_si64) (SIMDE__SYMBOL_U(_m64) a, SIMDE__SYMBOL_U(_m64) b) {
#if defined(SIMDE__MMX_NATIVE)
  return SIMDE__M64_C(_mm_andnot_si64(a.n, b.n));
#else
  return (SIMDE__SYMBOL_U(_m64)) { .i64 = ~(a.i64) & b.i64 };
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
SIMDE__SYMBOL_U(_m64)
SIMDE__SYMBOL_U(m_pandn) (SIMDE__SYMBOL_U(_m64) a, SIMDE__SYMBOL_U(_m64) b) {
#if defined(SIMDE__MMX_NATIVE)
  return SIMDE__M64_C(_m_pandn(a.n, b.n));
#else
  return SIMDE__SYMBOL_U(mm_andnot_si64)(a, b);
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
SIMDE__SYMBOL_U(_m64)
SIMDE__SYMBOL_U(mm_cmpeq_pi8) (SIMDE__SYMBOL_U(_m64) a, SIMDE__SYMBOL_U(_m64) b) {
#if defined(SIMDE__MMX_NATIVE)
  return SIMDE__M64_C(_mm_cmpeq_pi8(a.n, b.n));
#else
  SIMDE__SYMBOL_U(_m64) r;
  for (int i = 0 ; i < 8 ; i++) {
    r.i8[i] = (a.i8[i] == b.i8[i]) * 0xff;
  }
  return r;
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
SIMDE__SYMBOL_U(_m64)
SIMDE__SYMBOL_U(m_pcmpeqb) (SIMDE__SYMBOL_U(_m64) a, SIMDE__SYMBOL_U(_m64) b) {
#if defined(SIMDE__MMX_NATIVE)
  return SIMDE__M64_C(_m_pcmpeqb(a.n, b.n));
#else
  return SIMDE__SYMBOL_U(mm_cmpeq_pi8)(a, b);
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
SIMDE__SYMBOL_U(_m64)
SIMDE__SYMBOL_U(mm_cmpeq_pi16) (SIMDE__SYMBOL_U(_m64) a, SIMDE__SYMBOL_U(_m64) b) {
#if defined(SIMDE__MMX_NATIVE)
  return SIMDE__M64_C(_mm_cmpeq_pi16(a.n, b.n));
#else
  SIMDE__SYMBOL_U(_m64) r;
  for (int i = 0 ; i < 4 ; i++) {
    r.i16[i] = (a.i16[i] == b.i16[i]) * 0xffff;
  }
  return r;
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
SIMDE__SYMBOL_U(_m64)
SIMDE__SYMBOL_U(m_pcmpeqw) (SIMDE__SYMBOL_U(_m64) a, SIMDE__SYMBOL_U(_m64) b) {
#if defined(SIMDE__MMX_NATIVE)
  return SIMDE__M64_C(_m_pcmpeqw(a.n, b.n));
#else
  return SIMDE__SYMBOL_U(mm_cmpeq_pi16)(a, b);
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
SIMDE__SYMBOL_U(_m64)
SIMDE__SYMBOL_U(mm_cmpeq_pi32) (SIMDE__SYMBOL_U(_m64) a, SIMDE__SYMBOL_U(_m64) b) {
#if defined(SIMDE__MMX_NATIVE)
  return SIMDE__M64_C(_mm_cmpeq_pi32(a.n, b.n));
#else
  SIMDE__SYMBOL_U(_m64) r;
  for (int i = 0 ; i < 2 ; i++) {
    r.i32[i] = (a.i32[i] == b.i32[i]) * 0xffffffff;
  }
  return r;
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
SIMDE__SYMBOL_U(_m64)
SIMDE__SYMBOL_U(m_pcmpeqd) (SIMDE__SYMBOL_U(_m64) a, SIMDE__SYMBOL_U(_m64) b) {
#if defined(SIMDE__MMX_NATIVE)
  return SIMDE__M64_C(_m_pcmpeqd(a.n, b.n));
#else
  return SIMDE__SYMBOL_U(mm_cmpeq_pi32)(a, b);
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
SIMDE__SYMBOL_U(_m64)
SIMDE__SYMBOL_U(mm_cmpgt_pi8) (SIMDE__SYMBOL_U(_m64) a, SIMDE__SYMBOL_U(_m64) b) {
#if defined(SIMDE__MMX_NATIVE)
  return SIMDE__M64_C(_mm_cmpgt_pi8(a.n, b.n));
#else
  SIMDE__SYMBOL_U(_m64) r;
  for (int i = 0 ; i < 8 ; i++) {
    r.i8[i] = (a.i8[i] > b.i8[i]) * 0xff;
  }
  return r;
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
SIMDE__SYMBOL_U(_m64)
SIMDE__SYMBOL_U(m_pcmpgtb) (SIMDE__SYMBOL_U(_m64) a, SIMDE__SYMBOL_U(_m64) b) {
#if defined(SIMDE__MMX_NATIVE)
  return SIMDE__M64_C(_m_pcmpgtb(a.n, b.n));
#else
  return SIMDE__SYMBOL_U(mm_cmpgt_pi8)(a, b);
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
SIMDE__SYMBOL_U(_m64)
SIMDE__SYMBOL_U(mm_cmpgt_pi16) (SIMDE__SYMBOL_U(_m64) a, SIMDE__SYMBOL_U(_m64) b) {
#if defined(SIMDE__MMX_NATIVE)
  return SIMDE__M64_C(_mm_cmpgt_pi16(a.n, b.n));
#else
  SIMDE__SYMBOL_U(_m64) r;
  for (int i = 0 ; i < 4 ; i++) {
    r.i16[i] = (a.i16[i] > b.i16[i]) * 0xffff;
  }
  return r;
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
SIMDE__SYMBOL_U(_m64)
SIMDE__SYMBOL_U(m_pcmpgtw) (SIMDE__SYMBOL_U(_m64) a, SIMDE__SYMBOL_U(_m64) b) {
#if defined(SIMDE__MMX_NATIVE)
  return SIMDE__M64_C(_m_pcmpgtw(a.n, b.n));
#else
  return SIMDE__SYMBOL_U(mm_cmpgt_pi16)(a, b);
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
SIMDE__SYMBOL_U(_m64)
SIMDE__SYMBOL_U(mm_cmpgt_pi32) (SIMDE__SYMBOL_U(_m64) a, SIMDE__SYMBOL_U(_m64) b) {
#if defined(SIMDE__MMX_NATIVE)
  return SIMDE__M64_C(_mm_cmpgt_pi32(a.n, b.n));
#else
  SIMDE__SYMBOL_U(_m64) r;
  for (int i = 0 ; i < 2 ; i++) {
    r.i32[i] = (a.i32[i] > b.i32[i]) * 0xffffffff;
  }
  return r;
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
SIMDE__SYMBOL_U(_m64)
SIMDE__SYMBOL_U(m_pcmpgtd) (SIMDE__SYMBOL_U(_m64) a, SIMDE__SYMBOL_U(_m64) b) {
#if defined(SIMDE__MMX_NATIVE)
  return SIMDE__M64_C(_m_pcmpgtd(a.n, b.n));
#else
  return SIMDE__SYMBOL_U(mm_cmpgt_pi32)(a, b);
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
int64_t
SIMDE__SYMBOL_U(mm_cvtm64_si64) (SIMDE__SYMBOL_U(_m64) a) {
#if defined(SIMDE__MMX_NATIVE)
#  if defined(__PGI)
  return *((int64_t*) &a);
#  else
  return _mm_cvtm64_si64(a.n);
#  endif
#else
  return a.i64;
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
SIMDE__SYMBOL_U(_m64)
SIMDE__SYMBOL_U(mm_cvtsi32_si64) (int a) {
#if defined(SIMDE__MMX_NATIVE)
  return SIMDE__M64_C(_mm_cvtsi32_si64(a));
#else
  return (SIMDE__SYMBOL_U(_m64)) { .i32 = { a, 0 } };
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
SIMDE__SYMBOL_U(_m64)
SIMDE__SYMBOL_U(m_from_int) (int a) {
#if defined(SIMDE__MMX_NATIVE)
  return SIMDE__M64_C(_m_from_int(a));
#else
  return SIMDE__SYMBOL_U(mm_cvtsi32_si64)(a);
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
SIMDE__SYMBOL_U(_m64)
SIMDE__SYMBOL_U(mm_cvtsi64_m64) (int64_t a) {
#if defined(SIMDE__MMX_NATIVE)
#  if defined(__PGI)
  SIMDE__SYMBOL_U(_m64) r;
  *((int64_t*) &r) = a;
  return r;
#  else
  return SIMDE__M64_C(_mm_cvtsi64_m64(a));
#  endif
#else
  return (SIMDE__SYMBOL_U(_m64)) { .i64 = a };
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
SIMDE__SYMBOL_U(_m64)
SIMDE__SYMBOL_U(m_from_int64) (int64_t a) {
#if defined(SIMDE__MMX_NATIVE)
  return SIMDE__M64_C(_m_from_int64(a));
#else
  return SIMDE__SYMBOL_U(mm_cvtsi64_m64)(a);
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
int
SIMDE__SYMBOL_U(mm_cvtsi64_si32) (SIMDE__SYMBOL_U(_m64) a) {
#if defined(SIMDE__MMX_NATIVE)
  return _mm_cvtsi64_si32(a.n);
#else
  return a.i32[0];
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
void
SIMDE__SYMBOL_U(mm_empty) (void) {
#if defined(SIMDE__MMX_NATIVE)
  _mm_empty();
#else
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
void
SIMDE__SYMBOL_U(m_empty) (void) {
#if defined(SIMDE__MMX_NATIVE)
  _m_empty();
#else
  SIMDE__SYMBOL_U(mm_empty)();
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
SIMDE__SYMBOL_U(_m64)
SIMDE__SYMBOL_U(mm_madd_pi16) (SIMDE__SYMBOL_U(_m64) a, SIMDE__SYMBOL_U(_m64) b) {
#if defined(SIMDE__MMX_NATIVE)
  return SIMDE__M64_C(_mm_madd_pi16(a.n, b.n));
#else
  SIMDE__SYMBOL_U(_m64) r;
  for (int i = 0 ; i < 4 ; i += 2) {
    r.i32[i / 2] = (a.i16[i] * b.i16[i]) + (a.i16[i + 1] * b.i16[i + 1]);
  }
  return r;
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
SIMDE__SYMBOL_U(_m64)
SIMDE__SYMBOL_U(m_pmaddwd) (SIMDE__SYMBOL_U(_m64) a, SIMDE__SYMBOL_U(_m64) b) {
#if defined(SIMDE__MMX_NATIVE)
  return SIMDE__M64_C(_m_pmaddwd(a.n, b.n));
#else
  return SIMDE__SYMBOL_U(mm_madd_pi16)(a, b);
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
SIMDE__SYMBOL_U(_m64)
SIMDE__SYMBOL_U(mm_mulhi_pi16) (SIMDE__SYMBOL_U(_m64) a, SIMDE__SYMBOL_U(_m64) b) {
#if defined(SIMDE__MMX_NATIVE)
  return SIMDE__M64_C(_mm_mulhi_pi16(a.n, b.n));
#else
  SIMDE__SYMBOL_U(_m64) r;
  for (int i = 0 ; i < 4 ; i++) {
    r.i16[i] = (short) ((a.i16[i] * b.i16[i]) >> 16);
  }
  return r;
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
SIMDE__SYMBOL_U(_m64)
SIMDE__SYMBOL_U(m_pmulhw) (SIMDE__SYMBOL_U(_m64) a, SIMDE__SYMBOL_U(_m64) b) {
#if defined(SIMDE__MMX_NATIVE)
  return SIMDE__M64_C(_m_pmulhw(a.n, b.n));
#else
  return SIMDE__SYMBOL_U(mm_mulhi_pi16)(a, b);
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
SIMDE__SYMBOL_U(_m64)
SIMDE__SYMBOL_U(mm_mullo_pi16) (SIMDE__SYMBOL_U(_m64) a, SIMDE__SYMBOL_U(_m64) b) {
#if defined(SIMDE__MMX_NATIVE)
  return SIMDE__M64_C(_mm_mullo_pi16(a.n, b.n));
#else
  SIMDE__SYMBOL_U(_m64) r;
  for (int i = 0 ; i < 4 ; i++) {
    r.i16[i] = (short) ((a.i16[i] * b.i16[i]) & 0xffff);
  }
  return r;
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
SIMDE__SYMBOL_U(_m64)
SIMDE__SYMBOL_U(m_pmullw) (SIMDE__SYMBOL_U(_m64) a, SIMDE__SYMBOL_U(_m64) b) {
#if defined(SIMDE__MMX_NATIVE)
  return SIMDE__M64_C(_m_pmullw(a.n, b.n));
#else
  return SIMDE__SYMBOL_U(mm_mullo_pi16)(a, b);
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
SIMDE__SYMBOL_U(_m64)
SIMDE__SYMBOL_U(mm_or_si64) (SIMDE__SYMBOL_U(_m64) a, SIMDE__SYMBOL_U(_m64) b) {
#if defined(SIMDE__MMX_NATIVE)
  return SIMDE__M64_C(_mm_or_si64(a.n, b.n));
#else
  return (SIMDE__SYMBOL_U(_m64)) { .i64 = a.i64 | b.i64 };
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
SIMDE__SYMBOL_U(_m64)
SIMDE__SYMBOL_U(m_por) (SIMDE__SYMBOL_U(_m64) a, SIMDE__SYMBOL_U(_m64) b) {
#if defined(SIMDE__MMX_NATIVE)
  return SIMDE__M64_C(_m_por(a.n, b.n));
#else
  return SIMDE__SYMBOL_U(mm_or_si64)(a, b);
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
SIMDE__SYMBOL_U(_m64)
SIMDE__SYMBOL_U(mm_packs_pi16) (SIMDE__SYMBOL_U(_m64) a, SIMDE__SYMBOL_U(_m64) b) {
#if defined(SIMDE__MMX_NATIVE)
  return SIMDE__M64_C(_mm_packs_pi16(a.n, b.n));
#else
  SIMDE__SYMBOL_U(_m64) r;

  for (size_t i = 0 ; i < (8 / sizeof(short)) ; i++) {
    if (a.i16[i] < CHAR_MIN) {
      r.i8[i] = CHAR_MIN;
    } else if (a.i16[i] > CHAR_MAX) {
      r.i8[i] = CHAR_MAX;
    } else {
      r.i8[i] = (char) a.i16[i];
    }
  }

  for (size_t i = 0 ; i < (8 / sizeof(short)) ; i++) {
    if (b.i16[i] < CHAR_MIN) {
      r.i8[i + 4] = CHAR_MIN;
    } else if (b.i16[i] > CHAR_MAX) {
      r.i8[i + 4] = CHAR_MAX;
    } else {
      r.i8[i + 4] = (char) b.i16[i];
    }
  }

  return r;
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
SIMDE__SYMBOL_U(_m64)
SIMDE__SYMBOL_U(m_packsswb) (SIMDE__SYMBOL_U(_m64) a, SIMDE__SYMBOL_U(_m64) b) {
#if defined(SIMDE__MMX_NATIVE)
  return SIMDE__M64_C(_m_packsswb(a.n, b.n));
#else
  return SIMDE__SYMBOL_U(mm_packs_pi16)(a, b);
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
SIMDE__SYMBOL_U(_m64)
SIMDE__SYMBOL_U(mm_packs_pi32) (SIMDE__SYMBOL_U(_m64) a, SIMDE__SYMBOL_U(_m64) b) {
#if defined(SIMDE__MMX_NATIVE)
  return SIMDE__M64_C(_mm_packs_pi32(a.n, b.n));
#else
  SIMDE__SYMBOL_U(_m64) r;

  for (size_t i = 0 ; i < (8 / sizeof(a.i32[0])) ; i++) {
    if (a.i32[i] < SHRT_MIN) {
      r.i16[i] = SHRT_MIN;
    } else if (a.i32[i] > SHRT_MAX) {
      r.i16[i] = SHRT_MAX;
    } else {
      r.i16[i] = (short) a.i32[i];
    }
  }

  for (size_t i = 0 ; i < (8 / sizeof(b.i32[0])) ; i++) {
    if (b.i32[i] < SHRT_MIN) {
      r.i16[i + 2] = SHRT_MIN;
    } else if (b.i32[i] > SHRT_MAX) {
      r.i16[i + 2] = SHRT_MAX;
    } else {
      r.i16[i + 2] = (short) b.i32[i];
    }
  }

  return r;
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
SIMDE__SYMBOL_U(_m64)
SIMDE__SYMBOL_U(m_packssdw) (SIMDE__SYMBOL_U(_m64) a, SIMDE__SYMBOL_U(_m64) b) {
#if defined(SIMDE__MMX_NATIVE)
  return SIMDE__M64_C(_m_packssdw(a.n, b.n));
#else
  return SIMDE__SYMBOL_U(mm_packs_pi32)(a, b);
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
SIMDE__SYMBOL_U(_m64)
SIMDE__SYMBOL_U(mm_packs_pu16) (SIMDE__SYMBOL_U(_m64) a, SIMDE__SYMBOL_U(_m64) b) {
#if defined(SIMDE__MMX_NATIVE)
  return SIMDE__M64_C(_mm_packs_pu16(a.n, b.n));
#else
  SIMDE__SYMBOL_U(_m64) r;

  for (size_t i = 0 ; i < (8 / sizeof(short)) ; i++) {
    if (a.i16[i] > UCHAR_MAX) {
      r.u8[i] = UCHAR_MAX;
    } else if (a.i16[i] < 0) {
      r.u8[i] = 0;
    } else {
      r.u8[i] = (char) a.i16[i];
    }
  }

  for (size_t i = 0 ; i < (8 / sizeof(short)) ; i++) {
    if (b.i16[i] > UCHAR_MAX) {
      r.u8[i + 4] = UCHAR_MAX;
    } else if (b.i16[i] < 0) {
      r.u8[i + 4] = 0;
    } else {
      r.u8[i + 4] = (char) b.i16[i];
    }
  }

  return r;
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
SIMDE__SYMBOL_U(_m64)
SIMDE__SYMBOL_U(m_packuswb) (SIMDE__SYMBOL_U(_m64) a, SIMDE__SYMBOL_U(_m64) b) {
#if defined(SIMDE__MMX_NATIVE)
  return SIMDE__M64_C(_m_packuswb(a.n, b.n));
#else
  return SIMDE__SYMBOL_U(mm_packs_pu16)(a, b);
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
SIMDE__SYMBOL_U(_m64)
SIMDE__SYMBOL_U(mm_set_pi8) (char e7, char e6, char e5, char e4, char e3, char e2, char e1, char e0) {
#if defined(SIMDE__MMX_NATIVE)
  return SIMDE__M64_C(_mm_set_pi8(e7, e6, e5, e4, e3, e2, e1, e0));
#else
  return (SIMDE__SYMBOL_U(_m64)) { .i8 = { e0, e1, e2, e3, e4, e5, e6, e7 } };
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
SIMDE__SYMBOL_U(_m64)
SIMDE__SYMBOL_U(mm_set_pi16) (short e3, short e2, short e1, short e0) {
#if defined(SIMDE__MMX_NATIVE)
  return SIMDE__M64_C(_mm_set_pi16(e3, e2, e1, e0));
#else
  return (SIMDE__SYMBOL_U(_m64)) { .i16 = { e0, e1, e2, e3 } };
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
SIMDE__SYMBOL_U(_m64)
SIMDE__SYMBOL_U(mm_set_pi32) (int e1, int e0) {
#if defined(SIMDE__MMX_NATIVE)
  return SIMDE__M64_C(_mm_set_pi32(e1, e0));
#else
  return (SIMDE__SYMBOL_U(_m64)) { .i32 = { e0, e1 } };
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
SIMDE__SYMBOL_U(_m64)
SIMDE__SYMBOL_U(mm_set1_pi8) (char a) {
#if defined(SIMDE__MMX_NATIVE)
  return SIMDE__M64_C(_mm_set1_pi8(a));
#else
  return SIMDE__SYMBOL_U(mm_set_pi8)(a, a, a, a, a, a, a, a);
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
SIMDE__SYMBOL_U(_m64)
SIMDE__SYMBOL_U(mm_set1_pi16) (short a) {
#if defined(SIMDE__MMX_NATIVE)
  return SIMDE__M64_C(_mm_set1_pi16(a));
#else
  return SIMDE__SYMBOL_U(mm_set_pi16)(a, a, a, a);
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
SIMDE__SYMBOL_U(_m64)
SIMDE__SYMBOL_U(mm_set1_pi32) (char a) {
#if defined(SIMDE__MMX_NATIVE)
  return SIMDE__M64_C(_mm_set1_pi32(a));
#else
  return SIMDE__SYMBOL_U(mm_set_pi32)(a, a);
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
SIMDE__SYMBOL_U(_m64)
SIMDE__SYMBOL_U(mm_setr_pi8) (char e7, char e6, char e5, char e4, char e3, char e2, char e1, char e0) {
#if defined(SIMDE__MMX_NATIVE)
  return SIMDE__M64_C(_mm_setr_pi8(e7, e6, e5, e4, e3, e2, e1, e0));
#else
  return (SIMDE__SYMBOL_U(_m64)) { .i8 = { e7, e6, e5, e4, e3, e2, e1, e0 } };
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
SIMDE__SYMBOL_U(_m64)
SIMDE__SYMBOL_U(mm_setr_pi16) (short e3, short e2, short e1, short e0) {
#if defined(SIMDE__MMX_NATIVE)
  return SIMDE__M64_C(_mm_setr_pi16(e3, e2, e1, e0));
#else
  return (SIMDE__SYMBOL_U(_m64)) { .i16 = { e3, e2, e1, e0 } };
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
SIMDE__SYMBOL_U(_m64)
SIMDE__SYMBOL_U(mm_setr_pi32) (int e1, int e0) {
#if defined(SIMDE__MMX_NATIVE)
  return SIMDE__M64_C(_mm_setr_pi32(e1, e0));
#else
  return (SIMDE__SYMBOL_U(_m64)) { .i32 = { e1, e0 } };
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
SIMDE__SYMBOL_U(_m64)
SIMDE__SYMBOL_U(mm_setzero_si64) (void) {
#if defined(SIMDE__MMX_NATIVE)
  return SIMDE__M64_C(_mm_setzero_si64());
#else
  return (SIMDE__SYMBOL_U(_m64)) { .i32 = { 0, 0 } };
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
SIMDE__SYMBOL_U(_m64)
SIMDE__SYMBOL_U(mm_sll_pi16) (SIMDE__SYMBOL_U(_m64) a, SIMDE__SYMBOL_U(_m64) count) {
#if defined(SIMDE__MMX_NATIVE)
  return SIMDE__M64_C(_mm_sll_pi16(a.n, count.n));
#else
  SIMDE__SYMBOL_U(_m64) r;

  for (size_t i = 0 ; i < (8 / sizeof(unsigned short)) ; i++) {
    r.u16[i] = a.u16[i] << count.u64;
  }

  return r;
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
SIMDE__SYMBOL_U(_m64)
SIMDE__SYMBOL_U(m_psllw) (SIMDE__SYMBOL_U(_m64) a, SIMDE__SYMBOL_U(_m64) count) {
#if defined(SIMDE__MMX_NATIVE)
  return SIMDE__M64_C(_m_psllw(a.n, count.n));
#else
  return SIMDE__SYMBOL_U(mm_sll_pi16)(a, count);
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
SIMDE__SYMBOL_U(_m64)
SIMDE__SYMBOL_U(mm_sll_pi32) (SIMDE__SYMBOL_U(_m64) a, SIMDE__SYMBOL_U(_m64) count) {
#if defined(SIMDE__MMX_NATIVE)
  return SIMDE__M64_C(_mm_sll_pi32(a.n, count.n));
#else
  SIMDE__SYMBOL_U(_m64) r;

  for (size_t i = 0 ; i < (8 / sizeof(unsigned int)) ; i++) {
    r.u32[i] = a.u32[i] << count.u64;
  }

  return r;
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
SIMDE__SYMBOL_U(_m64)
SIMDE__SYMBOL_U(m_pslld) (SIMDE__SYMBOL_U(_m64) a, SIMDE__SYMBOL_U(_m64) count) {
#if defined(SIMDE__MMX_NATIVE)
  return SIMDE__M64_C(_m_pslld(a.n, count.n));
#else
  return SIMDE__SYMBOL_U(mm_sll_pi32)(a, count);
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
SIMDE__SYMBOL_U(_m64)
SIMDE__SYMBOL_U(mm_slli_pi16) (SIMDE__SYMBOL_U(_m64) a, int count) {
#if defined(SIMDE__MMX_NATIVE)
  return SIMDE__M64_C(_mm_slli_pi16(a.n, count));
#else
  SIMDE__SYMBOL_U(_m64) r;

  for (size_t i = 0 ; i < (8 / sizeof(unsigned short)) ; i++) {
    r.u16[i] = a.u16[i] << count;
  }

  return r;
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
SIMDE__SYMBOL_U(_m64)
SIMDE__SYMBOL_U(m_psllwi) (SIMDE__SYMBOL_U(_m64) a, int count) {
#if defined(SIMDE__MMX_NATIVE)
  return SIMDE__M64_C(_m_psllwi(a.n, count));
#else
  return SIMDE__SYMBOL_U(mm_slli_pi16)(a, count);
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
SIMDE__SYMBOL_U(_m64)
SIMDE__SYMBOL_U(mm_slli_pi32) (SIMDE__SYMBOL_U(_m64) a, int count) {
#if defined(SIMDE__MMX_NATIVE)
  return SIMDE__M64_C(_mm_slli_pi32(a.n, count));
#else
  SIMDE__SYMBOL_U(_m64) r;

  for (size_t i = 0 ; i < (8 / sizeof(int)) ; i++) {
    r.u32[i] = a.u32[i] << count;
  }

  return r;
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
SIMDE__SYMBOL_U(_m64)
SIMDE__SYMBOL_U(m_pslldi) (SIMDE__SYMBOL_U(_m64) a, int count) {
#if defined(SIMDE__MMX_NATIVE)
  return SIMDE__M64_C(_m_pslldi(a.n, count));
#else
  return SIMDE__SYMBOL_U(mm_slli_pi32)(a, count);
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
SIMDE__SYMBOL_U(_m64)
SIMDE__SYMBOL_U(mm_slli_si64) (SIMDE__SYMBOL_U(_m64) a, int count) {
#if defined(SIMDE__MMX_NATIVE)
  return SIMDE__M64_C(_mm_slli_si64(a.n, count));
#else
  return (SIMDE__SYMBOL_U(_m64)) { .u64 = a.u64 << count };
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
SIMDE__SYMBOL_U(_m64)
SIMDE__SYMBOL_U(m_psllqi) (SIMDE__SYMBOL_U(_m64) a, int count) {
#if defined(SIMDE__MMX_NATIVE)
  return SIMDE__M64_C(_m_psllqi(a.n, count));
#else
  return SIMDE__SYMBOL_U(mm_slli_si64)(a, count);
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
SIMDE__SYMBOL_U(_m64)
SIMDE__SYMBOL_U(mm_sll_si64) (SIMDE__SYMBOL_U(_m64) a, SIMDE__SYMBOL_U(_m64) count) {
#if defined(SIMDE__MMX_NATIVE)
  return SIMDE__M64_C(_mm_sll_si64(a.n, count.n));
#else
  return (SIMDE__SYMBOL_U(_m64)) { .u64 = a.u64 << count.u64 };
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
SIMDE__SYMBOL_U(_m64)
SIMDE__SYMBOL_U(m_psllq) (SIMDE__SYMBOL_U(_m64) a, SIMDE__SYMBOL_U(_m64) count) {
#if defined(SIMDE__MMX_NATIVE)
  return SIMDE__M64_C(_m_psllq(a.n, count.n));
#else
  return SIMDE__SYMBOL_U(mm_sll_si64)(a, count);
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
SIMDE__SYMBOL_U(_m64)
SIMDE__SYMBOL_U(mm_srl_pi16) (SIMDE__SYMBOL_U(_m64) a, SIMDE__SYMBOL_U(_m64) count) {
#if defined(SIMDE__MMX_NATIVE)
  return SIMDE__M64_C(_mm_srl_pi16(a.n, count.n));
#else
  SIMDE__SYMBOL_U(_m64) r;

  for (size_t i = 0 ; i < (8 / sizeof(unsigned short)) ; i++) {
    r.u16[i] = a.u16[i] >> count.u64;
  }

  return r;
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
SIMDE__SYMBOL_U(_m64)
SIMDE__SYMBOL_U(m_psrlw) (SIMDE__SYMBOL_U(_m64) a, SIMDE__SYMBOL_U(_m64) count) {
#if defined(SIMDE__MMX_NATIVE)
  return SIMDE__M64_C(_m_psrlw(a.n, count.n));
#else
  return SIMDE__SYMBOL_U(mm_srl_pi16)(a, count);
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
SIMDE__SYMBOL_U(_m64)
SIMDE__SYMBOL_U(mm_srl_pi32) (SIMDE__SYMBOL_U(_m64) a, SIMDE__SYMBOL_U(_m64) count) {
#if defined(SIMDE__MMX_NATIVE)
  return SIMDE__M64_C(_mm_srl_pi32(a.n, count.n));
#else
  SIMDE__SYMBOL_U(_m64) r;

  for (size_t i = 0 ; i < (8 / sizeof(unsigned int)) ; i++) {
    r.u32[i] = a.u32[i] >> count.u64;
  }

  return r;
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
SIMDE__SYMBOL_U(_m64)
SIMDE__SYMBOL_U(m_psrld) (SIMDE__SYMBOL_U(_m64) a, SIMDE__SYMBOL_U(_m64) count) {
#if defined(SIMDE__MMX_NATIVE)
  return SIMDE__M64_C(_m_psrld(a.n, count.n));
#else
  return SIMDE__SYMBOL_U(mm_srl_pi32)(a, count);
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
SIMDE__SYMBOL_U(_m64)
SIMDE__SYMBOL_U(mm_srli_pi16) (SIMDE__SYMBOL_U(_m64) a, int count) {
#if defined(SIMDE__MMX_NATIVE)
  return SIMDE__M64_C(_mm_srli_pi16(a.n, count));
#else
  SIMDE__SYMBOL_U(_m64) r;

  for (size_t i = 0 ; i < (8 / sizeof(unsigned short)) ; i++) {
    r.u16[i] = a.u16[i] >> count;
  }

  return r;
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
SIMDE__SYMBOL_U(_m64)
SIMDE__SYMBOL_U(m_psrlwi) (SIMDE__SYMBOL_U(_m64) a, int count) {
#if defined(SIMDE__MMX_NATIVE)
  return SIMDE__M64_C(_m_psrlwi(a.n, count));
#else
  return SIMDE__SYMBOL_U(mm_srli_pi16)(a, count);
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
SIMDE__SYMBOL_U(_m64)
SIMDE__SYMBOL_U(mm_srli_pi32) (SIMDE__SYMBOL_U(_m64) a, int count) {
#if defined(SIMDE__MMX_NATIVE)
  return SIMDE__M64_C(_mm_srli_pi32(a.n, count));
#else
  SIMDE__SYMBOL_U(_m64) r;

  for (size_t i = 0 ; i < (8 / sizeof(int)) ; i++) {
    r.u32[i] = a.u32[i] >> count;
  }

  return r;
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
SIMDE__SYMBOL_U(_m64)
SIMDE__SYMBOL_U(m_psrldi) (SIMDE__SYMBOL_U(_m64) a, int count) {
#if defined(SIMDE__MMX_NATIVE)
  return SIMDE__M64_C(_m_psrldi(a.n, count));
#else
  return SIMDE__SYMBOL_U(mm_srli_pi32)(a, count);
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
SIMDE__SYMBOL_U(_m64)
SIMDE__SYMBOL_U(mm_srli_si64) (SIMDE__SYMBOL_U(_m64) a, int count) {
#if defined(SIMDE__MMX_NATIVE)
  return SIMDE__M64_C(_mm_srli_si64(a.n, count));
#else
  return (SIMDE__SYMBOL_U(_m64)) { .u64 = a.u64 >> count };
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
SIMDE__SYMBOL_U(_m64)
SIMDE__SYMBOL_U(m_psrlqi) (SIMDE__SYMBOL_U(_m64) a, int count) {
#if defined(SIMDE__MMX_NATIVE)
  return SIMDE__M64_C(_m_psrlqi(a.n, count));
#else
  return SIMDE__SYMBOL_U(mm_srli_si64)(a, count);
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
SIMDE__SYMBOL_U(_m64)
SIMDE__SYMBOL_U(mm_srl_si64) (SIMDE__SYMBOL_U(_m64) a, SIMDE__SYMBOL_U(_m64) count) {
#if defined(SIMDE__MMX_NATIVE)
  return SIMDE__M64_C(_mm_srl_si64(a.n, count.n));
#else
  return (SIMDE__SYMBOL_U(_m64)) { .u64 = a.u64 >> count.u64 };
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
SIMDE__SYMBOL_U(_m64)
SIMDE__SYMBOL_U(m_psrlq) (SIMDE__SYMBOL_U(_m64) a, SIMDE__SYMBOL_U(_m64) count) {
#if defined(SIMDE__MMX_NATIVE)
  return SIMDE__M64_C(_m_psrlq(a.n, count.n));
#else
  return SIMDE__SYMBOL_U(mm_srl_si64)(a, count);
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
SIMDE__SYMBOL_U(_m64)
SIMDE__SYMBOL_U(mm_srai_pi16) (SIMDE__SYMBOL_U(_m64) a, int count) {
#if defined(SIMDE__MMX_NATIVE)
  return SIMDE__M64_C(_mm_srai_pi16(a.n, count));
#else
  SIMDE__SYMBOL_U(_m64) r;

  const unsigned short m = (unsigned short) ((~0U) << ((sizeof(short) * CHAR_BIT) - count));

  for (size_t i = 0 ; i < (8 / sizeof(short)) ; i++) {
    const unsigned short is_neg = ((unsigned short) (((a.u16[i]) >> ((sizeof(short) * CHAR_BIT) - 1))));
    r.u16[i] = (a.u16[i] >> count) | (m * is_neg);
  }

  return r;
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
SIMDE__SYMBOL_U(_m64)
SIMDE__SYMBOL_U(m_psrawi) (SIMDE__SYMBOL_U(_m64) a, int count) {
#if defined(SIMDE__MMX_NATIVE)
  return SIMDE__M64_C(_m_psrawi(a.n, count));
#else
  return SIMDE__SYMBOL_U(mm_srai_pi16)(a, count);
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
SIMDE__SYMBOL_U(_m64)
SIMDE__SYMBOL_U(mm_srai_pi32) (SIMDE__SYMBOL_U(_m64) a, int count) {
#if defined(SIMDE__MMX_NATIVE)
  return SIMDE__M64_C(_mm_srai_pi32(a.n, count));
#else
  SIMDE__SYMBOL_U(_m64) r;

  const unsigned int m = (unsigned int) ((~0U) << ((sizeof(int) * CHAR_BIT) - count));
  for (size_t i = 0 ; i < (8 / sizeof(int)) ; i++) {
    const unsigned int is_neg = ((unsigned int) (((a.u32[i]) >> ((sizeof(int) * CHAR_BIT) - 1))));
    r.u32[i] = (a.u32[i] >> count) | (m * is_neg);
  }

  return r;
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
SIMDE__SYMBOL_U(_m64)
SIMDE__SYMBOL_U(m_psradi) (SIMDE__SYMBOL_U(_m64) a, int count) {
#if defined(SIMDE__MMX_NATIVE)
  return SIMDE__M64_C(_m_psradi(a.n, count));
#else
  return SIMDE__SYMBOL_U(mm_srai_pi32)(a, count);
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
SIMDE__SYMBOL_U(_m64)
SIMDE__SYMBOL_U(mm_sra_pi16) (SIMDE__SYMBOL_U(_m64) a, SIMDE__SYMBOL_U(_m64) count) {
#if defined(SIMDE__MMX_NATIVE)
  return SIMDE__M64_C(_mm_sra_pi16(a.n, count.n));
#else
  SIMDE__SYMBOL_U(_m64) r;

  const unsigned short m = (unsigned short) ((~0U) << ((sizeof(short) * CHAR_BIT) - count.i64));

  for (size_t i = 0 ; i < (8 / sizeof(short)) ; i++) {
    const unsigned short is_neg = ((unsigned short) (((a.u16[i]) >> ((sizeof(short) * CHAR_BIT) - 1))));
    r.u16[i] = (a.u16[i] >> count.i64) | (m * is_neg);
  }

  return r;
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
SIMDE__SYMBOL_U(_m64)
SIMDE__SYMBOL_U(m_psraw) (SIMDE__SYMBOL_U(_m64) a, SIMDE__SYMBOL_U(_m64) count) {
#if defined(SIMDE__MMX_NATIVE)
  return SIMDE__M64_C(_m_psraw(a.n, count.n));
#else
  return SIMDE__SYMBOL_U(mm_sra_pi16)(a, count);
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
SIMDE__SYMBOL_U(_m64)
SIMDE__SYMBOL_U(mm_sra_pi32) (SIMDE__SYMBOL_U(_m64) a, SIMDE__SYMBOL_U(_m64) count) {
#if defined(SIMDE__MMX_NATIVE)
  return SIMDE__M64_C(_mm_sra_pi32(a.n, count.n));
#else
  SIMDE__SYMBOL_U(_m64) r;

  const unsigned int m = (unsigned int) ((~0U) << ((sizeof(int) * CHAR_BIT) - count.i64));
  for (size_t i = 0 ; i < (8 / sizeof(int)) ; i++) {
    const unsigned int is_neg = ((unsigned int) (((a.u32[i]) >> ((sizeof(int) * CHAR_BIT) - 1))));
    r.u32[i] = (a.u32[i] >> count.i64) | (m * is_neg);
  }

  return r;
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
SIMDE__SYMBOL_U(_m64)
SIMDE__SYMBOL_U(m_psrad) (SIMDE__SYMBOL_U(_m64) a, SIMDE__SYMBOL_U(_m64) b) {
#if defined(SIMDE__MMX_NATIVE)
  return SIMDE__M64_C(_m_psrad(a.n, b.n));
#else
  return SIMDE__SYMBOL_U(mm_sra_pi32)(a, b);
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
SIMDE__SYMBOL_U(_m64)
SIMDE__SYMBOL_U(mm_sub_pi8) (SIMDE__SYMBOL_U(_m64) a, SIMDE__SYMBOL_U(_m64) b) {
#if defined(SIMDE__MMX_NATIVE)
  return SIMDE__M64_C(_mm_sub_pi8(a.n, b.n));
#else
  SIMDE__SYMBOL_U(_m64) r;
  for (size_t i = 0 ; i < 8 ; i++) {
    r.i8[i] = a.i8[i] - b.i8[i];
  }
  return r;
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
SIMDE__SYMBOL_U(_m64)
SIMDE__SYMBOL_U(m_psubb) (SIMDE__SYMBOL_U(_m64) a, SIMDE__SYMBOL_U(_m64) b) {
#if defined(SIMDE__MMX_NATIVE)
  return SIMDE__M64_C(_m_psubb(a.n, b.n));
#else
  return SIMDE__SYMBOL_U(mm_sub_pi8)(a, b);
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
SIMDE__SYMBOL_U(_m64)
SIMDE__SYMBOL_U(mm_sub_pi16) (SIMDE__SYMBOL_U(_m64) a, SIMDE__SYMBOL_U(_m64) b) {
#if defined(SIMDE__MMX_NATIVE)
  return SIMDE__M64_C(_mm_sub_pi16(a.n, b.n));
#else
  SIMDE__SYMBOL_U(_m64) r;
  for (size_t i = 0 ; i < (8 / sizeof(short)) ; i++) {
    r.i16[i] = a.i16[i] - b.i16[i];
  }
  return r;
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
SIMDE__SYMBOL_U(_m64)
SIMDE__SYMBOL_U(m_psubw) (SIMDE__SYMBOL_U(_m64) a, SIMDE__SYMBOL_U(_m64) b) {
#if defined(SIMDE__MMX_NATIVE)
  return SIMDE__M64_C(_m_psubw(a.n, b.n));
#else
  return SIMDE__SYMBOL(_mm_sub_pi16)(a, b);
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
SIMDE__SYMBOL_U(_m64)
SIMDE__SYMBOL_U(mm_sub_pi32) (SIMDE__SYMBOL_U(_m64) a, SIMDE__SYMBOL_U(_m64) b) {
#if defined(SIMDE__MMX_NATIVE)
  return SIMDE__M64_C(_mm_sub_pi32(a.n, b.n));
#else
  SIMDE__SYMBOL_U(_m64) r;
  for (size_t i = 0 ; i < (8 / sizeof(int)) ; i++) {
    r.i32[i] = a.i32[i] - b.i32[i];
  }
  return r;
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
SIMDE__SYMBOL_U(_m64)
SIMDE__SYMBOL_U(m_psubd) (SIMDE__SYMBOL_U(_m64) a, SIMDE__SYMBOL_U(_m64) b) {
#if defined(SIMDE__MMX_NATIVE)
  return SIMDE__M64_C(_m_psubd(a.n, b.n));
#else
  return SIMDE__SYMBOL_U(mm_sub_pi32)(a, b);
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
SIMDE__SYMBOL_U(_m64)
SIMDE__SYMBOL_U(mm_subs_pi8) (SIMDE__SYMBOL_U(_m64) a, SIMDE__SYMBOL_U(_m64) b) {
#if defined(SIMDE__MMX_NATIVE)
  return SIMDE__M64_C(_mm_subs_pi8(a.n, b.n));
#else
  SIMDE__SYMBOL_U(_m64) r;
  for (size_t i = 0 ; i < (8) ; i++) {
    if (((b.i8[i]) > 0 && (a.i8[i]) < CHAR_MIN + (b.i8[i]))) {
      r.i8[i] = CHAR_MIN;
    } else if ((b.i8[i]) < 0 && (a.i8[i]) > CHAR_MAX + (b.i8[i])) {
      r.i8[i] = CHAR_MAX;
    } else {
      r.i8[i] = (a.i8[i]) - (b.i8[i]);
    }
  }
  return r;
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
SIMDE__SYMBOL_U(_m64)
SIMDE__SYMBOL_U(m_psubsb) (SIMDE__SYMBOL_U(_m64) a, SIMDE__SYMBOL_U(_m64) b) {
#if defined(SIMDE__MMX_NATIVE)
  return SIMDE__M64_C(_m_psubsb(a.n, b.n));
#else
  return SIMDE__SYMBOL_U(mm_subs_pi8)(a, b);
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
SIMDE__SYMBOL_U(_m64)
SIMDE__SYMBOL_U(mm_subs_pu8) (SIMDE__SYMBOL_U(_m64) a, SIMDE__SYMBOL_U(_m64) b) {
#if defined(SIMDE__MMX_NATIVE)
  return SIMDE__M64_C(_mm_subs_pu8(a.n, b.n));
#else
  SIMDE__SYMBOL_U(_m64) r;
  for (size_t i = 0 ; i < (8) ; i++) {
    const int x = a.u8[i] - b.u8[i];
    if (x < 0) {
      r.u8[i] = 0;
    } else if (x > UCHAR_MAX) {
      r.u8[i] = UCHAR_MAX;
    } else {
      r.u8[i] = (unsigned char) x;
    }
  }
  return r;
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
SIMDE__SYMBOL_U(_m64)
SIMDE__SYMBOL_U(m_psubusb) (SIMDE__SYMBOL_U(_m64) a, SIMDE__SYMBOL_U(_m64) b) {
#if defined(SIMDE__MMX_NATIVE)
  return SIMDE__M64_C(_m_psubusb(a.n, b.n));
#else
  return SIMDE__SYMBOL_U(mm_subs_pu8)(a, b);
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
SIMDE__SYMBOL_U(_m64)
SIMDE__SYMBOL_U(mm_subs_pi16) (SIMDE__SYMBOL_U(_m64) a, SIMDE__SYMBOL_U(_m64) b) {
#if defined(SIMDE__MMX_NATIVE)
  return SIMDE__M64_C(_mm_subs_pi16(a.n, b.n));
#else
  SIMDE__SYMBOL_U(_m64) r;
  for (size_t i = 0 ; i < (8 / sizeof(short)) ; i++) {
    if (((b.i16[i]) > 0 && (a.i16[i]) < SHRT_MIN + (b.i16[i]))) {
      r.i16[i] = SHRT_MIN;
    } else if ((b.i16[i]) < 0 && (a.i16[i]) > SHRT_MAX + (b.i16[i])) {
      r.i16[i] = SHRT_MAX;
    } else {
      r.i16[i] = (a.i16[i]) - (b.i16[i]);
    }
  }
  return r;
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
SIMDE__SYMBOL_U(_m64)
SIMDE__SYMBOL_U(m_psubsw) (SIMDE__SYMBOL_U(_m64) a, SIMDE__SYMBOL_U(_m64) b) {
#if defined(SIMDE__MMX_NATIVE)
  return SIMDE__M64_C(_m_psubsw(a.n, b.n));
#else
  return SIMDE__SYMBOL_U(mm_subs_pi16)(a, b);
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
SIMDE__SYMBOL_U(_m64)
SIMDE__SYMBOL_U(mm_subs_pu16) (SIMDE__SYMBOL_U(_m64) a, SIMDE__SYMBOL_U(_m64) b) {
#if defined(SIMDE__MMX_NATIVE)
  return SIMDE__M64_C(_mm_subs_pu16(a.n, b.n));
#else
  SIMDE__SYMBOL_U(_m64) r;
  for (size_t i = 0 ; i < (8 / sizeof(unsigned short)) ; i++) {
    const int x = a.u16[i] - b.u16[i];
    if (x < 0) {
      r.u16[i] = 0;
    } else if (x > USHRT_MAX) {
      r.u16[i] = USHRT_MAX;
    } else {
      r.u16[i] = (unsigned short) x;
    }
  }
  return r;
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
SIMDE__SYMBOL_U(_m64)
SIMDE__SYMBOL_U(m_psubusw) (SIMDE__SYMBOL_U(_m64) a, SIMDE__SYMBOL_U(_m64) b) {
#if defined(SIMDE__MMX_NATIVE)
  return SIMDE__M64_C(_m_psubusw(a.n, b.n));
#else
  return SIMDE__SYMBOL_U(mm_subs_pu16)(a, b);
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
SIMDE__SYMBOL_U(_m64)
SIMDE__SYMBOL_U(mm_unpackhi_pi8) (SIMDE__SYMBOL_U(_m64) a, SIMDE__SYMBOL_U(_m64) b) {
#if defined(SIMDE__MMX_NATIVE)
  return SIMDE__M64_C(_mm_unpackhi_pi8(a.n, b.n));
#else
  return (SIMDE__SYMBOL_U(_m64)) { .i8 = {
      a.i8[4], b.i8[4], a.i8[5], b.i8[5],
      a.i8[6], b.i8[6], a.i8[7], b.i8[7]
    }
  };
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
SIMDE__SYMBOL_U(_m64)
SIMDE__SYMBOL_U(m_punpckhbw) (SIMDE__SYMBOL_U(_m64) a, SIMDE__SYMBOL_U(_m64) b) {
#if defined(SIMDE__MMX_NATIVE)
  return SIMDE__M64_C(_m_punpckhbw(a.n, b.n));
#else
  return SIMDE__SYMBOL_U(mm_unpackhi_pi8)(a, b);
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
SIMDE__SYMBOL_U(_m64)
SIMDE__SYMBOL_U(mm_unpackhi_pi16) (SIMDE__SYMBOL_U(_m64) a, SIMDE__SYMBOL_U(_m64) b) {
#if defined(SIMDE__MMX_NATIVE)
  return SIMDE__M64_C(_mm_unpackhi_pi16(a.n, b.n));
#else
  return (SIMDE__SYMBOL_U(_m64)) { .i16 = { a.i16[2], b.i16[2], a.i16[3], b.i16[3] } };
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
SIMDE__SYMBOL_U(_m64)
SIMDE__SYMBOL_U(m_punpckhwd) (SIMDE__SYMBOL_U(_m64) a, SIMDE__SYMBOL_U(_m64) b) {
#if defined(SIMDE__MMX_NATIVE)
  return SIMDE__M64_C(_m_punpckhwd(a.n, b.n));
#else
  return SIMDE__SYMBOL_U(mm_unpackhi_pi16)(a, b);
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
SIMDE__SYMBOL_U(_m64)
SIMDE__SYMBOL_U(mm_unpackhi_pi32) (SIMDE__SYMBOL_U(_m64) a, SIMDE__SYMBOL_U(_m64) b) {
#if defined(SIMDE__MMX_NATIVE)
  return SIMDE__M64_C(_mm_unpackhi_pi32(a.n, b.n));
#else
  return (SIMDE__SYMBOL_U(_m64)) { .i32 = { a.i32[1], b.i32[1] } };
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
SIMDE__SYMBOL_U(_m64)
SIMDE__SYMBOL_U(m_punpckhdq) (SIMDE__SYMBOL_U(_m64) a, SIMDE__SYMBOL_U(_m64) b) {
#if defined(SIMDE__MMX_NATIVE)
  return SIMDE__M64_C(_m_punpckhdq(a.n, b.n));
#else
  return SIMDE__SYMBOL_U(mm_unpackhi_pi32)(a, b);
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
SIMDE__SYMBOL_U(_m64)
SIMDE__SYMBOL_U(mm_unpacklo_pi8) (SIMDE__SYMBOL_U(_m64) a, SIMDE__SYMBOL_U(_m64) b) {
#if defined(SIMDE__MMX_NATIVE)
  return SIMDE__M64_C(_mm_unpacklo_pi8(a.n, b.n));
#else
  return (SIMDE__SYMBOL_U(_m64)) { .i8 = {
      a.i8[0], b.i8[0], a.i8[1], b.i8[1],
      a.i8[2], b.i8[2], a.i8[3], b.i8[3]
    }
  };
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
SIMDE__SYMBOL_U(_m64)
SIMDE__SYMBOL_U(m_punpcklbw) (SIMDE__SYMBOL_U(_m64) a, SIMDE__SYMBOL_U(_m64) b) {
#if defined(SIMDE__MMX_NATIVE)
  return SIMDE__M64_C(_m_punpcklbw(a.n, b.n));
#else
  return SIMDE__SYMBOL_U(mm_unpacklo_pi8)(a, b);
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
SIMDE__SYMBOL_U(_m64)
SIMDE__SYMBOL_U(mm_unpacklo_pi16) (SIMDE__SYMBOL_U(_m64) a, SIMDE__SYMBOL_U(_m64) b) {
#if defined(SIMDE__MMX_NATIVE)
  return SIMDE__M64_C(_mm_unpacklo_pi16(a.n, b.n));
#else
  return (SIMDE__SYMBOL_U(_m64)) { .i16 = { a.i16[0], b.i16[0], a.i16[1], b.i16[1] } };
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
SIMDE__SYMBOL_U(_m64)
SIMDE__SYMBOL_U(m_punpcklwd) (SIMDE__SYMBOL_U(_m64) a, SIMDE__SYMBOL_U(_m64) b) {
#if defined(SIMDE__MMX_NATIVE)
  return SIMDE__M64_C(_m_punpcklwd(a.n, b.n));
#else
  return SIMDE__SYMBOL_U(mm_unpacklo_pi16)(a, b);
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
SIMDE__SYMBOL_U(_m64)
SIMDE__SYMBOL_U(mm_unpacklo_pi32) (SIMDE__SYMBOL_U(_m64) a, SIMDE__SYMBOL_U(_m64) b) {
#if defined(SIMDE__MMX_NATIVE)
  return SIMDE__M64_C(_mm_unpacklo_pi32(a.n, b.n));
#else
  return (SIMDE__SYMBOL_U(_m64)) { .i32 = { a.i32[0], b.i32[0] } };
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
SIMDE__SYMBOL_U(_m64)
SIMDE__SYMBOL_U(m_punpckldq) (SIMDE__SYMBOL_U(_m64) a, SIMDE__SYMBOL_U(_m64) b) {
#if defined(SIMDE__MMX_NATIVE)
  return SIMDE__M64_C(_m_punpckldq(a.n, b.n));
#else
  return SIMDE__SYMBOL_U(mm_unpacklo_pi32)(a, b);
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
SIMDE__SYMBOL_U(_m64)
SIMDE__SYMBOL_U(mm_xor_si64) (SIMDE__SYMBOL_U(_m64) a, SIMDE__SYMBOL_U(_m64) b) {
#if defined(SIMDE__MMX_NATIVE)
  return SIMDE__M64_C(_mm_xor_si64(a.n, b.n));
#else
  return (SIMDE__SYMBOL_U(_m64)) { .i64 = a.i64 ^ b.i64 };
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
SIMDE__SYMBOL_U(_m64)
SIMDE__SYMBOL_U(m_pxor) (SIMDE__SYMBOL_U(_m64) a, SIMDE__SYMBOL_U(_m64) b) {
#if defined(SIMDE__MMX_NATIVE)
  return SIMDE__M64_C(_m_pxor(a.n, b.n));
#else
  return SIMDE__SYMBOL_U(mm_xor_si64)(a, b);
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
int
SIMDE__SYMBOL_U(m_to_int) (SIMDE__SYMBOL_U(_m64) a) {
#if defined(SIMDE__MMX_NATIVE)
  return _m_to_int(a.n);
#else
  return a.i32[0];
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
int64_t
SIMDE__SYMBOL_U(m_to_int64) (SIMDE__SYMBOL_U(_m64) a) {
#if defined(SIMDE__MMX_NATIVE)
  return SIMDE__SYMBOL_U(mm_cvtm64_si64)(a);
#else
  return a.i64;
#endif
}

#endif /* !defined(SIMDE__MMX_H) */
