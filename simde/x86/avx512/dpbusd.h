#if !defined(SIMDE_X86_AVX512_DPBUSD_H)
#define SIMDE_X86_AVX512_DPBUSD_H

#include "types.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_dpbusd_epi32(simde__m128i src, simde__m128i a, simde__m128i b) {
  #if defined(SIMDE_X86_AVX512VL_NATIVE) && defined(SIMDE_X86_AVX512VNNI_NATIVE)
    return _mm_dpbusd_epi32(src, a, b);
  #else
    simde__m128i_private
      src_ = simde__m128i_to_private(src),
      a_ = simde__m128i_to_private(a),
      b_ = simde__m128i_to_private(b);
    #if defined(SIMDE_SHUFFLE_VECTOR_) && defined(SIMDE_CONVERT_VECTOR_)
      simde__m512i_private
        r1_,
        r2_;

      a_.u8 = SIMDE_SHUFFLE_VECTOR_(8, 16, a_.u8, a_.u8,  0,  4,  8, 12,  1,  5,  9, 13,  2,  6, 10, 14,  3,  7, 11, 15);
      b_.i8 = SIMDE_SHUFFLE_VECTOR_(8, 16, b_.i8, b_.i8, 16, 20, 24, 28, 17, 21, 25, 29, 18, 22, 26, 30, 19, 23, 27, 31);

      SIMDE_CONVERT_VECTOR_(r1_.u32, a_.u8);
      SIMDE_CONVERT_VECTOR_(r2_.i32, b_.i8);

      src_.i32 +=
        (HEDLEY_REINTERPRET_CAST(__typeof__(a_.i32), r1_.m128i_private[0].u32) * r2_.m128i_private[0].i32) +
        (HEDLEY_REINTERPRET_CAST(__typeof__(a_.i32), r1_.m128i_private[1].u32) * r2_.m128i_private[1].i32) +
        (HEDLEY_REINTERPRET_CAST(__typeof__(a_.i32), r1_.m128i_private[2].u32) * r2_.m128i_private[2].i32) +
        (HEDLEY_REINTERPRET_CAST(__typeof__(a_.i32), r1_.m128i_private[3].u32) * r2_.m128i_private[3].i32);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(a_.u8) / sizeof(a_.u8[0])) ; i++) {
        src_.i32[i / 4] += HEDLEY_STATIC_CAST(uint16_t, a_.u8[i]) * HEDLEY_STATIC_CAST(int16_t, b_.i8[i]);
      }
    #endif

    return simde__m128i_from_private(src_);
  #endif
}
#if defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VNNI_ENABLE_NATIVE_ALIASES)
  #undef _mm_dpbusd_epi32
  #define _mm_dpbusd_epi32(src, a, b) simde_mm_dpbusd_epi32(src, a, b)
#endif

SIMDE_END_DECLS_
HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_X86_AVX512_DPBUSD_H) */
