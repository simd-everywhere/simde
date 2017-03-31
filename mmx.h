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

#include <stdint.h>
#include <limits.h>

typedef union {
  char                   i8 __attribute__((__vector_size__(8)));
  short                  i16 __attribute__((__vector_size__(8)));
  int                    i32 __attribute__((__vector_size__(8)));
  long long int          i64;
  unsigned char          u8 __attribute__((__vector_size__(8)));
  unsigned short         u16 __attribute__((__vector_size__(8)));
  unsigned int           u32 __attribute__((__vector_size__(8)));
  unsigned long long int u64;
} SIMDE__TYPE(m64);
#if defined(__m64)
#  undef __m64
#endif
#define __m64 SIMDE__TYPE(m64)

SIMDE__MMX_INLINE_FUNC
SIMDE__TYPE(m64)
SIMDE__SYMBOL(__mm_add_pi8) (__m64 a, __m64 b) {
  return (SIMDE__TYPE(m64)) { .i8 = a.i8 + b.i8 };
}
#if defined(_mm_add_pi8)
#  undef _mm_add_pi8
#endif
#define _mm_add_pi8 SIMDE__SYMBOL(__mm_add_pi8)
#if defined(_m_paddb)
#  undef _m_paddb
#endif
#define _m_paddb SIMDE__SYMBOL(__mm_add_pi8)

SIMDE__MMX_INLINE_FUNC
SIMDE__TYPE(m64)
SIMDE__SYMBOL(__mm_add_pi16) (__m64 a, __m64 b) {
  return (SIMDE__TYPE(m64)) { .i16 = a.i16 + b.i16 };
}
#if defined(_mm_add_pi16)
#  undef _mm_add_pi16
#endif
#define _mm_add_pi16 SIMDE__SYMBOL(__mm_add_pi16)
#if defined(_m_paddw)
#  undef _m_paddw
#endif
#define _m_paddw SIMDE__SYMBOL(__m_paddw)

SIMDE__MMX_INLINE_FUNC
SIMDE__TYPE(m64)
SIMDE__SYMBOL(__mm_add_pi32) (__m64 a, __m64 b) {
  return (SIMDE__TYPE(m64)) { .i32 = a.i32 + b.i32 };
}
#if defined(_mm_add_pi32)
#  undef _mm_add_pi32
#endif
#define _mm_add_pi32 SIMDE__SYMBOL(__mm_add_pi32)
#if defined(_m_paddd)
#  undef _m_paddd
#endif
#define _m_paddd SIMDE__SYMBOL(__mm_add_pi32)

SIMDE__MMX_INLINE_FUNC
SIMDE__TYPE(m64)
SIMDE__SYMBOL(__mm_adds_pi8) (__m64 a, __m64 b) {
  __m64 r;
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
}
#if defined(_mm_adds_pi8)
#  undef _mm_adds_pi8
#endif
#define _mm_adds_pi8 SIMDE__SYMBOL(__mm_adds_pi8)
#if defined(_m_paddsb)
#  undef _m_paddsb
#endif
#define _m_paddsb SIMDE__SYMBOL(__mm_adds_pi8)

SIMDE__MMX_INLINE_FUNC
SIMDE__TYPE(m64)
SIMDE__SYMBOL(__mm_adds_pu8) (__m64 a, __m64 b) {
  __m64 r;
  for (size_t i = 0 ; i < sizeof(r) ; i++) {
    const int x = a.u8[i] + b.u8[i];
    if (x < 0)
      r.u8[i] = 0;
    else if (x > UCHAR_MAX)
      r.u8[i] = UCHAR_MAX;
    else
      r.u8[i] = (unsigned char) x;
  }
  return r;
}
#if defined(_mm_adds_pu8)
#  undef _mm_adds_pu8
#endif
#define _mm_adds_pu8 SIMDE__SYMBOL(__mm_adds_pu8)

SIMDE__MMX_INLINE_FUNC
SIMDE__TYPE(m64)
SIMDE__SYMBOL(__mm_adds_pi16) (__m64 a, __m64 b) {
  __m64 r;
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
}
#if defined(_mm_adds_pi16)
#  undef _mm_adds_pi16
#endif
#define _mm_adds_pi16 SIMDE__SYMBOL(__mm_adds_pi16)
#if defined(_m_paddsw)
#  undef _m_paddsw
#endif
#define _m_paddsw SIMDE__SYMBOL(__mm_adds_pi16)

SIMDE__MMX_INLINE_FUNC
SIMDE__TYPE(m64)
SIMDE__SYMBOL(__mm_adds_pu16) (__m64 a, __m64 b) {
  __m64 r;
  for (size_t i = 0 ; i < (sizeof(r) / sizeof(short)) ; i++) {
    const unsigned int x = a.u16[i] + b.u16[i];
    if (x > USHRT_MAX)
      r.u16[i] = USHRT_MAX;
    else
      r.u16[i] = (unsigned short) x;
  }
  return r;
}
#if defined(_mm_adds_pu16)
#  undef _mm_adds_pu16
#endif
#define _mm_adds_pu16 SIMDE__SYMBOL(__mm_adds_pu16)

SIMDE__MMX_INLINE_FUNC
SIMDE__TYPE(m64)
SIMDE__SYMBOL(__mm_and_si64) (__m64 a, __m64 b) {
  return (SIMDE__TYPE(m64)) { .i64 = a.i64 & b.i64 };
}
#if defined(_mm_and_si64)
#  undef _mm_and_si64
#endif
#define _mm_and_si64 SIMDE__SYMBOL(__mm_and_si64)
#if defined(_m_pand)
#  undef _m_pand
#endif
#define _m_pand SIMDE__SYMBOL(__mm_and_si64)

SIMDE__MMX_INLINE_FUNC
SIMDE__TYPE(m64)
SIMDE__SYMBOL(__mm_andnot_si64) (__m64 a, __m64 b) {
  return (SIMDE__TYPE(m64)) { .i64 = ~(a.i64) & b.i64 };
}
#if defined(_mm_andnot_si64)
#  undef _mm_andnot_si64
#endif
#define _mm_andnot_si64 SIMDE__SYMBOL(__mm_andnot_si64)
#if defined(_m_pandn)
#  undef _m_pandn
#endif
#define _m_pandn SIMDE__SYMBOL(__mm_andnot_si64)

SIMDE__MMX_INLINE_FUNC
SIMDE__TYPE(m64)
SIMDE__SYMBOL(__mm_cmpeq_pi8) (__m64 a, __m64 b) {
  __m64 r;
  for (int i = 0 ; i < 8 ; i++) {
    r.i8[i] = (a.i8[i] == b.i8[i]) * 0xff;
  }
  return r;
}
#if defined(_mm_cmpeq_pi8)
#  undef _mm_cmpeq_pi8
#endif
#define _mm_cmpeq_pi8 SIMDE__SYMBOL(__mm_cmpeq_pi8)
#if defined(_m_pcmpeqb)
#  undef _m_pcmpeqb
#endif
#define _m_pcmpeqb SIMDE__SYMBOL(__mm_cmpeq_pi8)

SIMDE__MMX_INLINE_FUNC
SIMDE__TYPE(m64)
SIMDE__SYMBOL(__mm_cmpeq_pi16) (__m64 a, __m64 b) {
  __m64 r;
  for (int i = 0 ; i < 4 ; i++) {
    r.i16[i] = (a.i16[i] == b.i16[i]) * 0xffff;
  }
  return r;
}
#if defined(_mm_cmpeq_pi16)
#  undef _mm_cmpeq_pi16
#endif
#define _mm_cmpeq_pi16 SIMDE__SYMBOL(__mm_cmpeq_pi16)
#if defined(_m_pcmpeqw)
#  undef _m_pcmpeqw
#endif
#define _m_pcmpeqw SIMDE__SYMBOL(__mm_cmpeq_pi16)

SIMDE__MMX_INLINE_FUNC
SIMDE__TYPE(m64)
SIMDE__SYMBOL(__mm_cmpeq_pi32) (__m64 a, __m64 b) {
  __m64 r;
  for (int i = 0 ; i < 2 ; i++) {
    r.i32[i] = (a.i32[i] == b.i32[i]) * 0xffffffff;
  }
  return r;
}
#if defined(_mm_cmpeq_pi32)
#  undef _mm_cmpeq_pi32
#endif
#define _mm_cmpeq_pi32 SIMDE__SYMBOL(__mm_cmpeq_pi32)
#if defined(_m_cpmpeqd)
#  undef _m_cpmpeqd
#endif
#define _m_cpmpeqd SIMDE__SYMBOL(__m_cpmpeqd)

SIMDE__MMX_INLINE_FUNC
SIMDE__TYPE(m64)
SIMDE__SYMBOL(__mm_cmpgt_pi8) (__m64 a, __m64 b) {
  __m64 r;
  for (int i = 0 ; i < 8 ; i++) {
    r.i8[i] = (a.i8[i] > b.i8[i]) * 0xff;
  }
  return r;
}
#if defined(_mm_cmpgt_pi8)
#  undef _mm_cmpgt_pi8
#endif
#define _mm_cmpgt_pi8 SIMDE__SYMBOL(__mm_cmpgt_pi8)
#if defined(_m_pcmpgtb)
#  undef _m_pcmpgtb
#endif
#define _m_pcmpgtb SIMDE__SYMBOL(__mm_cmpgt_pi8)

SIMDE__MMX_INLINE_FUNC
SIMDE__TYPE(m64)
SIMDE__SYMBOL(__mm_cmpgt_pi16) (__m64 a, __m64 b) {
  __m64 r;
  for (int i = 0 ; i < 4 ; i++) {
    r.i16[i] = (a.i16[i] > b.i16[i]) * 0xffff;
  }
  return r;
}
#if defined(_mm_cmpgt_pi16)
#  undef _mm_cmpgt_pi16
#endif
#define _mm_cmpgt_pi16 SIMDE__SYMBOL(__mm_cmpgt_pi16)
#if defined(_m_pcmpgtw)
#  undef _m_pcmpgtw
#endif
#define _m_pcmpgtw SIMDE__SYMBOL(__mm_cmpgt_pi16)

SIMDE__MMX_INLINE_FUNC
SIMDE__TYPE(m64)
SIMDE__SYMBOL(__mm_cmpgt_pi32) (__m64 a, __m64 b) {
  __m64 r;
  for (int i = 0 ; i < 2 ; i++) {
    r.i32[i] = (a.i32[i] > b.i32[i]) * 0xffffffff;
  }
  return r;
}
#if defined(_mm_cmpgt_pi32)
#  undef _mm_cmpgt_pi32
#endif
#define _mm_cmpgt_pi32 SIMDE__SYMBOL(__mm_cmpgt_pi32)
#if defined(_m_pcmgtd)
#  undef _m_pcmgtd
#endif
#define _m_pcmgtd SIMDE__SYMBOL(__mm_cmpgt_pi32)

SIMDE__MMX_INLINE_FUNC
int64_t
SIMDE__SYMBOL(__mm_cvtm64_si64) (__m64 a) {
  return a.i64;
}
#if defined(_mm_cvtm64_si64)
#  undef _mm_cvtm64_si64
#endif
#define _mm_cvtm64_si64 SIMDE__SYMBOL(__mm_cvtm64_si64)

SIMDE__MMX_INLINE_FUNC
SIMDE__TYPE(m64)
SIMDE__SYMBOL(__mm_cvtsi32_si64) (int a) {
  return (SIMDE__TYPE(m64)) { .i32 = { a, 0 } };
}
#if defined(_mm_cvtsi32_si64)
#  undef _mm_cvtsi32_si64
#endif
#define _mm_cvtsi32_si64 SIMDE__SYMBOL(__mm_cvtsi32_si64)
#if defined(_m_from_int)
#  undef _m_from_int
#endif
#define _m_from_int SIMDE__SYMBOL(__mm_from_int)

SIMDE__MMX_INLINE_FUNC
SIMDE__TYPE(m64)
SIMDE__SYMBOL(__mm_cvtsi64_m64) (int64_t a) {
  return (SIMDE__TYPE(m64)) { .i64 = a };
}
#if defined(_mm_cvtsi64_m64)
#  undef _mm_cvtsi64_m64
#endif
#define _mm_cvtsi64_m64 SIMDE__SYMBOL(__mm_cvtsi64_m64)
#if defined(_m_from_int64)
#  undef _m_from_int64
#endif
#define _m_from_int64 SIMDE__SYMBOL(__m_from_int64)

SIMDE__MMX_INLINE_FUNC
int
SIMDE__SYMBOL(__mm_cvtsi64_si32) (__m64 a) {
  return a.i32[0];
}
#if defined(_mm_cvtsi64_si32)
#  undef _mm_cvtsi64_si32
#endif
#define _mm_cvtsi64_si32 SIMDE__SYMBOL(__mm_cvtsi64_si32)

SIMDE__MMX_INLINE_FUNC
int
SIMDE__SYMBOL(__mm_empty) (__m64 a) {
  return a.i32[0];
}
#if defined(_mm_empty)
#  undef _mm_empty
#endif
#define _mm_empty SIMDE__SYMBOL(__mm_empty)
#if defined(_m_empty)
#  undef _m_empty
#endif
#define _m_empty SIMDE__SYMBOL(__mm_empty)

SIMDE__MMX_INLINE_FUNC
SIMDE__TYPE(m64)
SIMDE__SYMBOL(__mm_madd_pi16) (__m64 a, __m64 b) {
  __m64 r;
  for (int i = 0 ; i < 4 ; i += 2) {
    r.i32[i / 2] = (a.i16[i] * b.i16[i]) + (a.i16[i + 1] * b.i16[i + 1]);
  }
  return r;
}
#if defined(_mm_madd_pi16)
#  undef _mm_madd_pi16
#endif
#define _mm_madd_pi16 SIMDE__SYMBOL(__mm_madd_pi16)
#if defined(_m_pmaddwd)
#  undef _m_pmaddwd
#endif
#define _m_pmaddwd SIMDE__SYMBOL(__m_pmaddwd)

SIMDE__MMX_INLINE_FUNC
SIMDE__TYPE(m64)
SIMDE__SYMBOL(__mm_mulhi_pi16) (__m64 a, __m64 b) {
  __m64 r;
  for (int i = 0 ; i < 4 ; i++) {
    r.i16[i] = (short) ((a.i16[i] * b.i16[i]) >> 16);
  }
  return r;
}
#if defined(_mm_mulhi_pi16)
#  undef _mm_mulhi_pi16
#endif
#define _mm_mulhi_pi16 SIMDE__SYMBOL(__mm_mulhi_pi16)
#if defined(_m_pmulhw)
#  undef _m_pmulhw
#endif
#define _m_pmulhw SIMDE__SYMBOL(__m_pmulhw)

SIMDE__MMX_INLINE_FUNC
SIMDE__TYPE(m64)
SIMDE__SYMBOL(__mm_mullo_pi16) (__m64 a, __m64 b) {
  __m64 r;
  for (int i = 0 ; i < 4 ; i++) {
    r.i16[i] = (short) ((a.i16[i] * b.i16[i]) & 0xffff);
  }
  return r;
}
#if defined(_mm_mullo_pi16)
#  undef _mm_mullo_pi16
#endif
#define _mm_mullo_pi16 SIMDE__SYMBOL(__mm_mullo_pi16)
#if defined(_m_pmullw)
#  undef _m_pmullw
#endif
#define _m_pmullw SIMDE__SYMBOL(__mm_mullo_pi16)

SIMDE__MMX_INLINE_FUNC
SIMDE__TYPE(m64)
SIMDE__SYMBOL(__mm_or_si64) (__m64 a, __m64 b) {
  return (SIMDE__TYPE(m64)) { .i64 = a.i64 | b.i64 };
}
#if defined(_mm_or_si64)
#  undef _mm_or_si64
#endif
#define _mm_or_si64 SIMDE__SYMBOL(__mm_or_si64)
#if defined(_m_por)
#  undef _m_por
#endif
#define _m_por SIMDE__SYMBOL(__mm_or_si64)

SIMDE__MMX_INLINE_FUNC
SIMDE__TYPE(m64)
SIMDE__SYMBOL(__mm_packs_pi16) (__m64 a, __m64 b) {
  __m64 r;

  for (size_t i = 0 ; i < (sizeof(__m64) / sizeof(short)) ; i++) {
    if (a.i16[i] < CHAR_MIN) {
      r.i8[i] = CHAR_MIN;
    } else if (a.i16[i] > CHAR_MAX) {
      r.i8[i] = CHAR_MAX;
    } else {
      r.i8[i] = (char) a.i16[i];
    }
  }

  for (size_t i = 0 ; i < (sizeof(__m64) / sizeof(short)) ; i++) {
    if (b.i16[i] < CHAR_MIN) {
      r.i8[i + 4] = CHAR_MIN;
    } else if (b.i16[i] > CHAR_MAX) {
      r.i8[i + 4] = CHAR_MAX;
    } else {
      r.i8[i + 4] = (char) b.i16[i];
    }
  }

  return r;
}
#if defined(_mm_packs_pi16)
#  undef _mm_packs_pi16
#endif
#define _mm_packs_pi16 SIMDE__SYMBOL(__mm_packs_pi16)

SIMDE__MMX_INLINE_FUNC
SIMDE__TYPE(m64)
SIMDE__SYMBOL(__mm_packs_pi32) (__m64 a, __m64 b) {
  __m64 r;

  for (size_t i = 0 ; i < (sizeof(__m64) / sizeof(a.i32[0])) ; i++) {
    if (a.i32[i] < SHRT_MIN) {
      r.i16[i] = SHRT_MIN;
    } else if (a.i32[i] > SHRT_MAX) {
      r.i16[i] = SHRT_MAX;
    } else {
      r.i16[i] = (short) a.i32[i];
    }
  }

  for (size_t i = 0 ; i < (sizeof(__m64) / sizeof(b.i32[0])) ; i++) {
    if (b.i32[i] < SHRT_MIN) {
      r.i16[i + 2] = SHRT_MIN;
    } else if (b.i32[i] > SHRT_MAX) {
      r.i16[i + 2] = SHRT_MAX;
    } else {
      r.i16[i + 2] = (short) b.i32[i];
    }
  }

  return r;
}
#if defined(_mm_packs_pi32)
#  undef _mm_packs_pi32
#endif
#define _mm_packs_pi32 SIMDE__SYMBOL(__mm_packs_pi32)

SIMDE__MMX_INLINE_FUNC
SIMDE__TYPE(m64)
SIMDE__SYMBOL(__mm_packs_pu16) (__m64 a, __m64 b) {
  __m64 r;

  for (size_t i = 0 ; i < (sizeof(__m64) / sizeof(short)) ; i++) {
    if (a.i16[i] > UCHAR_MAX) {
      r.u8[i] = UCHAR_MAX;
    } else if (a.i16[i] < 0) {
      r.u8[i] = 0;
    } else {
      r.u8[i] = (char) a.i16[i];
    }
  }

  for (size_t i = 0 ; i < (sizeof(__m64) / sizeof(short)) ; i++) {
    if (b.i16[i] > UCHAR_MAX) {
      r.u8[i + 4] = UCHAR_MAX;
    } else if (b.i16[i] < 0) {
      r.u8[i + 4] = 0;
    } else {
      r.u8[i + 4] = (char) b.i16[i];
    }
  }

  return r;
}
#if defined(_mm_packs_pu16)
#  undef _mm_packs_pu16
#endif
#define _mm_packs_pu16 SIMDE__SYMBOL(__mm_packs_pu16)

SIMDE__MMX_INLINE_FUNC
SIMDE__TYPE(m64)
SIMDE__SYMBOL(__mm_set_pi8) (char e7, char e6, char e5, char e4, char e3, char e2, char e1, char e0) {
  return (SIMDE__TYPE(m64)) { .i8 = { e0, e1, e2, e3, e4, e5, e6, e7 } };
}
#if defined(_mm_set_pi8)
#  undef _mm_set_pi8
#endif
#define _mm_set_pi8 SIMDE__SYMBOL(__mm_set_pi8)

SIMDE__MMX_INLINE_FUNC
SIMDE__TYPE(m64)
SIMDE__SYMBOL(__mm_set_pi16) (short e3, short e2, short e1, short e0) {
  return (SIMDE__TYPE(m64)) { .i16 = { e0, e1, e2, e3 } };
}
#if defined(_mm_set_pi16)
#  undef _mm_set_pi16
#endif
#define _mm_set_pi16 SIMDE__SYMBOL(__mm_set_pi16)

SIMDE__MMX_INLINE_FUNC
SIMDE__TYPE(m64)
SIMDE__SYMBOL(__mm_set_pi32) (int e1, int e0) {
  return (SIMDE__TYPE(m64)) { .i32 = { e0, e1 } };
}
#if defined(_mm_set_pi32)
#  undef _mm_set_pi32
#endif
#define _mm_set_pi32 SIMDE__SYMBOL(__mm_set_pi32)

SIMDE__MMX_INLINE_FUNC
SIMDE__TYPE(m64)
SIMDE__SYMBOL(__mm_set1_pi8) (char a) {
  return SIMDE__SYMBOL(__mm_set_pi8)(a, a, a, a, a, a, a, a);
}
#if defined(_mm_set1_pi8)
#  undef _mm_set1_pi8
#endif
#define _mm_set1_pi8 SIMDE__SYMBOL(__mm_set1_pi8)

SIMDE__MMX_INLINE_FUNC
SIMDE__TYPE(m64)
SIMDE__SYMBOL(__mm_set1_pi16) (char a) {
  return SIMDE__SYMBOL(__mm_set_pi16)(a, a, a, a);
}
#if defined(_mm_set1_pi16)
#  undef _mm_set1_pi16
#endif
#define _mm_set1_pi16 SIMDE__SYMBOL(__mm_set1_pi16)

SIMDE__MMX_INLINE_FUNC
SIMDE__TYPE(m64)
SIMDE__SYMBOL(__mm_set1_pi32) (char a) {
  return SIMDE__SYMBOL(__mm_set_pi32)(a, a);
}
#if defined(_mm_set1_pi32)
#  undef _mm_set1_pi32
#endif
#define _mm_set1_pi32 SIMDE__SYMBOL(__mm_set1_pi32)

SIMDE__MMX_INLINE_FUNC
SIMDE__TYPE(m64)
SIMDE__SYMBOL(__mm_setr_pi8) (char e7, char e6, char e5, char e4, char e3, char e2, char e1, char e0) {
  return (SIMDE__TYPE(m64)) { .i8 = { e7, e6, e5, e4, e3, e2, e1, e0 } };
}
#if defined(_mm_setr_pi8)
#  undef _mm_setr_pi8
#endif
#define _mm_setr_pi8 SIMDE__SYMBOL(__mm_setr_pi8)

SIMDE__MMX_INLINE_FUNC
SIMDE__TYPE(m64)
SIMDE__SYMBOL(__mm_setr_pi16) (short e3, short e2, short e1, short e0) {
  return (SIMDE__TYPE(m64)) { .i16 = { e3, e2, e1, e0 } };
}
#if defined(_mm_setr_pi16)
#  undef _mm_setr_pi16
#endif
#define _mm_setr_pi16 SIMDE__SYMBOL(__mm_setr_pi16)

SIMDE__MMX_INLINE_FUNC
SIMDE__TYPE(m64)
SIMDE__SYMBOL(__mm_setr_pi32) (int e1, int e0) {
  return (SIMDE__TYPE(m64)) { .i32 = { e1, e0 } };
}
#if defined(_mm_setr_pi32)
#  undef _mm_setr_pi32
#endif
#define _mm_setr_pi32 SIMDE__SYMBOL(__mm_setr_pi32)

SIMDE__MMX_INLINE_FUNC
SIMDE__TYPE(m64)
SIMDE__SYMBOL(__mm_setzero_si64) (void) {
  return (SIMDE__TYPE(m64)) { .i32 = { 0, 0 } };
}
#if defined(_mm_setzero_si64)
#  undef _mm_setzero_si64
#endif
#define _mm_setzero_si64 SIMDE__SYMBOL(__mm_setr_si64)

SIMDE__MMX_INLINE_FUNC
SIMDE__TYPE(m64)
SIMDE__SYMBOL(__mm_sll_pi16) (__m64 a, __m64 count) {
  return (SIMDE__TYPE(m64)) { .u16 = a.u16 << count.u64 };
}
#if defined(_mm_sll_pi16)
#  undef _mm_sll_pi16
#endif
#define _mm_sll_pi16 SIMDE__SYMBOL(__mm_sll_pi16)

SIMDE__MMX_INLINE_FUNC
SIMDE__TYPE(m64)
SIMDE__SYMBOL(__mm_sll_pi32) (__m64 a, __m64 count) {
  return (SIMDE__TYPE(m64)) { .u32 = a.u32 << count.u64 };
}
#if defined(_mm_sll_pi32)
#  undef _mm_sll_pi32
#endif
#define _mm_sll_pi32 SIMDE__SYMBOL(__mm_sll_pi32)

SIMDE__MMX_INLINE_FUNC
SIMDE__TYPE(m64)
SIMDE__SYMBOL(__mm_slli_pi16) (__m64 a, int count) {
  return (SIMDE__TYPE(m64)) { .u16 = a.u16 << count };
}
#if defined(_mm_slli_pi16)
#  undef _mm_slli_pi16
#endif
#define _mm_slli_pi16 SIMDE__SYMBOL(__mm_slli_pi16)

SIMDE__MMX_INLINE_FUNC
SIMDE__TYPE(m64)
SIMDE__SYMBOL(__mm_slli_pi32) (__m64 a, int count) {
  return (SIMDE__TYPE(m64)) { .u32 = a.u32 << count };
}
#if defined(_mm_slli_pi32)
#  undef _mm_slli_pi32
#endif
#define _mm_slli_pi32 SIMDE__SYMBOL(__mm_slli_pi32)

SIMDE__MMX_INLINE_FUNC
SIMDE__TYPE(m64)
SIMDE__SYMBOL(__mm_slli_si64) (__m64 a, int count) {
  return (SIMDE__TYPE(m64)) { .u64 = a.u64 << count };
}
#if defined(_mm_slli_si64)
#  undef _mm_slli_si64
#endif
#define _mm_slli_si64 SIMDE__SYMBOL(__mm_slli_si64)

SIMDE__MMX_INLINE_FUNC
SIMDE__TYPE(m64)
SIMDE__SYMBOL(__mm_sll_si64) (__m64 a, __m64 count) {
  return (SIMDE__TYPE(m64)) { .u64 = a.u64 << count.u64 };
}
#if defined(_mm_sll_si64)
#  undef _mm_sll_si64
#endif
#define _mm_sll_si64 SIMDE__SYMBOL(__mm_sll_si64)

SIMDE__MMX_INLINE_FUNC
SIMDE__TYPE(m64)
SIMDE__SYMBOL(__mm_srl_pi16) (__m64 a, __m64 count) {
  return (SIMDE__TYPE(m64)) { .u16 = a.u16 >> count.u64 };
}
#if defined(_mm_srl_pi16)
#  undef _mm_srl_pi16
#endif
#define _mm_srl_pi16 SIMDE__SYMBOL(__mm_srl_pi16)

SIMDE__MMX_INLINE_FUNC
SIMDE__TYPE(m64)
SIMDE__SYMBOL(__mm_srl_pi32) (__m64 a, __m64 count) {
  return (SIMDE__TYPE(m64)) { .u32 = a.u32 >> count.u64 };
}
#if defined(_mm_srl_pi32)
#  undef _mm_srl_pi32
#endif
#define _mm_srl_pi32 SIMDE__SYMBOL(__mm_srl_pi32)

SIMDE__MMX_INLINE_FUNC
SIMDE__TYPE(m64)
SIMDE__SYMBOL(__mm_srli_pi16) (__m64 a, int count) {
  return (SIMDE__TYPE(m64)) { .u16 = a.u16 >> count };
}
#if defined(_mm_srli_pi16)
#  undef _mm_srli_pi16
#endif
#define _mm_srli_pi16 SIMDE__SYMBOL(__mm_srli_pi16)

SIMDE__MMX_INLINE_FUNC
SIMDE__TYPE(m64)
SIMDE__SYMBOL(__mm_srli_pi32) (__m64 a, int count) {
  return (SIMDE__TYPE(m64)) { .u32 = a.u32 >> count };
}
#if defined(_mm_srli_pi32)
#  undef _mm_srli_pi32
#endif
#define _mm_srli_pi32 SIMDE__SYMBOL(__mm_srli_pi32)

SIMDE__MMX_INLINE_FUNC
SIMDE__TYPE(m64)
SIMDE__SYMBOL(__mm_srli_si64) (__m64 a, int count) {
  return (SIMDE__TYPE(m64)) { .u64 = a.u64 >> count };
}
#if defined(_mm_srli_si64)
#  undef _mm_srli_si64
#endif
#define _mm_srli_si64 SIMDE__SYMBOL(__mm_srli_si64)

SIMDE__MMX_INLINE_FUNC
SIMDE__TYPE(m64)
SIMDE__SYMBOL(__mm_srl_si64) (__m64 a, __m64 count) {
  return (SIMDE__TYPE(m64)) { .u64 = a.u64 >> count.u64 };
}
#if defined(_mm_srl_si64)
#  undef _mm_srl_si64
#endif
#define _mm_srl_si64 SIMDE__SYMBOL(__mm_srl_si64)

SIMDE__MMX_INLINE_FUNC
SIMDE__TYPE(m64)
SIMDE__SYMBOL(__mm_srai_pi16) (__m64 a, int count) {
  __m64 r;

  const unsigned short m = (unsigned short) ((~0U) << ((sizeof(short) * CHAR_BIT) - count));

  for (size_t i = 0 ; i < (sizeof(__m64) / sizeof(short)) ; i++) {
    const unsigned short is_neg = ((unsigned short) (((a.u16[i]) >> ((sizeof(short) * CHAR_BIT) - 1))));
    r.u16[i] = (a.u16[i] >> count) | (m * is_neg);
  }

  return r;
}
#if defined(_mm_srai_pi16)
#  undef _mm_srai_pi16
#endif
#define _mm_srai_pi16 SIMDE__SYMBOL(__mm_srai_pi16)

SIMDE__MMX_INLINE_FUNC
SIMDE__TYPE(m64)
SIMDE__SYMBOL(__mm_srai_pi32) (__m64 a, int count) {
  __m64 r;

  const unsigned int m = (unsigned int) ((~0U) << ((sizeof(int) * CHAR_BIT) - count));
  for (size_t i = 0 ; i < (sizeof(__m64) / sizeof(int)) ; i++) {
    const unsigned int is_neg = ((unsigned int) (((a.u32[i]) >> ((sizeof(int) * CHAR_BIT) - 1))));
    r.u32[i] = (a.u32[i] >> count) | (m * is_neg);
  }

  return r;
}
#if defined(_mm_srai_pi32)
#  undef _mm_srai_pi32
#endif
#define _mm_srai_pi32 SIMDE__SYMBOL(__mm_srai_pi32)

SIMDE__MMX_INLINE_FUNC
SIMDE__TYPE(m64)
SIMDE__SYMBOL(__mm_sra_pi16) (__m64 a, __m64 count) {
  __m64 r;

  const unsigned short m = (unsigned short) ((~0U) << ((sizeof(short) * CHAR_BIT) - count.i64));

  for (size_t i = 0 ; i < (sizeof(__m64) / sizeof(short)) ; i++) {
    const unsigned short is_neg = ((unsigned short) (((a.u16[i]) >> ((sizeof(short) * CHAR_BIT) - 1))));
    r.u16[i] = (a.u16[i] >> count.i64) | (m * is_neg);
  }

  return r;
}
#if defined(_mm_sra_pi16)
#  undef _mm_sra_pi16
#endif
#define _mm_sra_pi16 SIMDE__SYMBOL(__mm_sra_pi16)

SIMDE__MMX_INLINE_FUNC
SIMDE__TYPE(m64)
SIMDE__SYMBOL(__mm_sra_pi32) (__m64 a, __m64 count) {
  __m64 r;

  const unsigned int m = (unsigned int) ((~0U) << ((sizeof(int) * CHAR_BIT) - count.i64));
  for (size_t i = 0 ; i < (sizeof(__m64) / sizeof(int)) ; i++) {
    const unsigned int is_neg = ((unsigned int) (((a.u32[i]) >> ((sizeof(int) * CHAR_BIT) - 1))));
    r.u32[i] = (a.u32[i] >> count.i64) | (m * is_neg);
  }

  return r;
}
#if defined(_mm_sra_pi32)
#  undef _mm_sra_pi32
#endif
#define _mm_sra_pi32 SIMDE__SYMBOL(__mm_sra_pi32)

SIMDE__MMX_INLINE_FUNC
SIMDE__TYPE(m64)
SIMDE__SYMBOL(__mm_sub_pi8) (__m64 a, __m64 b) {
  return (SIMDE__TYPE(m64)) { .i8 = a.i8 - b.i8 };
}
#if defined(_mm_sub_pi8)
#  undef _mm_sub_pi8
#endif
#define _mm_sub_pi8 SIMDE__SYMBOL(__mm_sub_pi8)
#if defined(_m_psubb)
#  undef _m_psubb
#endif
#define _m_psubb SIMDE__SYMBOL(__mm_sub_pi8)

SIMDE__MMX_INLINE_FUNC
SIMDE__TYPE(m64)
SIMDE__SYMBOL(__mm_sub_pi16) (__m64 a, __m64 b) {
  return (SIMDE__TYPE(m64)) { .i16 = a.i16 - b.i16 };
}
#if defined(_mm_sub_pi16)
#  undef _mm_sub_pi16
#endif
#define _mm_sub_pi16 SIMDE__SYMBOL(__mm_sub_pi16)
#if defined(_m_psubw)
#  undef _m_psubw
#endif
#define _m_psubw SIMDE__SYMBOL(__m_psubw)

SIMDE__MMX_INLINE_FUNC
SIMDE__TYPE(m64)
SIMDE__SYMBOL(__mm_sub_pi32) (__m64 a, __m64 b) {
  return (SIMDE__TYPE(m64)) { .i32 = a.i32 - b.i32 };
}
#if defined(_mm_sub_pi32)
#  undef _mm_sub_pi32
#endif
#define _mm_sub_pi32 SIMDE__SYMBOL(__mm_sub_pi32)
#if defined(_m_psubd)
#  undef _m_psubd
#endif
#define _m_psubd SIMDE__SYMBOL(__mm_sub_pi32)

SIMDE__MMX_INLINE_FUNC
SIMDE__TYPE(m64)
SIMDE__SYMBOL(__mm_subs_pi8) (__m64 a, __m64 b) {
  __m64 r;
  for (size_t i = 0 ; i < (sizeof(r)) ; i++) {
    if (((b.i8[i]) > 0 && (a.i8[i]) < CHAR_MIN + (b.i8[i]))) {
      r.i8[i] = CHAR_MIN;
    } else if ((b.i8[i]) < 0 && (a.i8[i]) > CHAR_MAX + (b.i8[i])) {
      r.i8[i] = CHAR_MAX;
    } else {
      r.i8[i] = (a.i8[i]) - (b.i8[i]);
    }
  }
  return r;
}
#if defined(_mm_subs_pi8)
#  undef _mm_subs_pi8
#endif
#define _mm_subs_pi8 SIMDE__SYMBOL(__mm_subs_pi8)
#if defined(_m_psubsb)
#  undef _m_psubsb
#endif
#define _m_psubsb SIMDE__SYMBOL(__mm_subs_pi8)

SIMDE__MMX_INLINE_FUNC
SIMDE__TYPE(m64)
SIMDE__SYMBOL(__mm_subs_pu8) (__m64 a, __m64 b) {
  __m64 r;
  for (size_t i = 0 ; i < (sizeof(r)) ; i++) {
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
}
#if defined(_mm_subs_pu8)
#  undef _mm_subs_pu8
#endif
#define _mm_subs_pu8 SIMDE__SYMBOL(__mm_subs_pu8)

SIMDE__MMX_INLINE_FUNC
SIMDE__TYPE(m64)
SIMDE__SYMBOL(__mm_subs_pi16) (__m64 a, __m64 b) {
  __m64 r;
  for (size_t i = 0 ; i < (sizeof(r) / sizeof(short)) ; i++) {
    if (((b.i16[i]) > 0 && (a.i16[i]) < SHRT_MIN + (b.i16[i]))) {
      r.i16[i] = SHRT_MIN;
    } else if ((b.i16[i]) < 0 && (a.i16[i]) > SHRT_MAX + (b.i16[i])) {
      r.i16[i] = SHRT_MAX;
    } else {
      r.i16[i] = (a.i16[i]) - (b.i16[i]);
    }
  }
  return r;
}
#if defined(_mm_subs_pi16)
#  undef _mm_subs_pi16
#endif
#define _mm_subs_pi16 SIMDE__SYMBOL(__mm_subs_pi16)
#if defined(_m_psubsw)
#  undef _m_psubsw
#endif
#define _m_psubsw SIMDE__SYMBOL(__mm_subs_pi16)

SIMDE__MMX_INLINE_FUNC
SIMDE__TYPE(m64)
SIMDE__SYMBOL(__mm_subs_pu16) (__m64 a, __m64 b) {
  __m64 r;
  for (size_t i = 0 ; i < (sizeof(r) / sizeof(unsigned short)) ; i++) {
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
}
#if defined(_mm_subs_pu16)
#  undef _mm_subs_pu16
#endif
#define _mm_subs_pu16 SIMDE__SYMBOL(__mm_subs_pu16)

SIMDE__MMX_INLINE_FUNC
SIMDE__TYPE(m64)
SIMDE__SYMBOL(__mm_unpackhi_pi8) (__m64 a, __m64 b) {
  return (SIMDE__TYPE(m64)) { .i8 = {
      a.i8[4], b.i8[4], a.i8[5], b.i8[5],
      a.i8[6], b.i8[6], a.i8[7], b.i8[7]
    }
  };
}
#if defined(_mm_unpackhi_pi8)
#  undef _mm_unpackhi_pi8
#endif
#define _mm_unpackhi_pi8 SIMDE__SYMBOL(__mm_unpackhi_pi8)

SIMDE__MMX_INLINE_FUNC
SIMDE__TYPE(m64)
SIMDE__SYMBOL(__mm_unpackhi_pi16) (__m64 a, __m64 b) {
  return (SIMDE__TYPE(m64)) { .i16 = { a.i16[2], b.i16[2], a.i16[3], b.i16[3] } };
}
#if defined(_mm_unpackhi_pi16)
#  undef _mm_unpackhi_pi16
#endif
#define _mm_unpackhi_pi16 SIMDE__SYMBOL(__mm_unpackhi_pi16)

SIMDE__MMX_INLINE_FUNC
SIMDE__TYPE(m64)
SIMDE__SYMBOL(__mm_unpackhi_pi32) (__m64 a, __m64 b) {
  return (SIMDE__TYPE(m64)) { .i32 = { a.i32[1], b.i32[1] } };
}
#if defined(_mm_unpackhi_pi32)
#  undef _mm_unpackhi_pi32
#endif
#define _mm_unpackhi_pi32 SIMDE__SYMBOL(__mm_unpackhi_pi32)

SIMDE__MMX_INLINE_FUNC
SIMDE__TYPE(m64)
SIMDE__SYMBOL(__mm_unpacklo_pi8) (__m64 a, __m64 b) {
  return (SIMDE__TYPE(m64)) { .i8 = {
      a.i8[0], b.i8[0], a.i8[1], b.i8[1],
      a.i8[2], b.i8[2], a.i8[3], b.i8[3]
    }
  };
}
#if defined(_mm_unpacklo_pi8)
#  undef _mm_unpacklo_pi8
#endif
#define _mm_unpacklo_pi8 SIMDE__SYMBOL(__mm_unpacklo_pi8)

SIMDE__MMX_INLINE_FUNC
SIMDE__TYPE(m64)
SIMDE__SYMBOL(__mm_unpacklo_pi16) (__m64 a, __m64 b) {
  return (SIMDE__TYPE(m64)) { .i16 = { a.i16[0], b.i16[0], a.i16[1], b.i16[1] } };
}
#if defined(_mm_unpacklo_pi16)
#  undef _mm_unpacklo_pi16
#endif
#define _mm_unpacklo_pi16 SIMDE__SYMBOL(__mm_unpacklo_pi16)

SIMDE__MMX_INLINE_FUNC
SIMDE__TYPE(m64)
SIMDE__SYMBOL(__mm_unpacklo_pi32) (__m64 a, __m64 b) {
  return (SIMDE__TYPE(m64)) { .i32 = { a.i32[0], b.i32[0] } };
}
#if defined(_mm_unpacklo_pi32)
#  undef _mm_unpacklo_pi32
#endif
#define _mm_unpacklo_pi32 SIMDE__SYMBOL(__mm_unpacklo_pi32)

SIMDE__MMX_INLINE_FUNC
SIMDE__TYPE(m64)
SIMDE__SYMBOL(__mm_xor_si64) (__m64 a, __m64 b) {
  return (SIMDE__TYPE(m64)) { .i64 = a.i64 ^ b.i64 };
}
#if defined(_mm_xor_si64)
#  undef _mm_xor_si64
#endif
#define _mm_xor_si64 SIMDE__SYMBOL(__mm_xor_si64)

#endif /* !defined(SIMDE__MMX_NATIVE) */
#endif /* !defined(SIMDE__MMX_H) */
