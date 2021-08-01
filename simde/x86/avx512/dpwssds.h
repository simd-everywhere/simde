#if !defined(SIMDE_X86_AVX512_DPWSSDS_H)
#define SIMDE_X86_AVX512_DPWSSDS_H

#include "types.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_dpwssds_epi32 (simde__m128i src, simde__m128i a, simde__m128i b) {
  #if defined(SIMDE_X86_AVX512VNNI_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm_dpwssds_epi32(src, a, b);
  #else
    simde__m128i_private
      src_ = simde__m128i_to_private(src),
      a_   = simde__m128i_to_private(a),
      b_   = simde__m128i_to_private(b);

    #if defined(SIMDE_SHUFFLE_VECTOR_) && defined(SIMDE_CONVERT_VECTOR_)
      int32_t x1_ SIMDE_VECTOR(32);
      int32_t x2_ SIMDE_VECTOR(32);
      simde__m128i_private
        r1_[2],
        r2_[2];

      a_.i16 =
        SIMDE_SHUFFLE_VECTOR_(
          16, 16,
          a_.i16, a_.i16,
          0, 2, 4, 6,
          1, 3, 5, 7
        );
      b_.i16 =
        SIMDE_SHUFFLE_VECTOR_(
          16, 16,
          b_.i16, b_.i16,
          0, 2, 4, 6,
          1, 3, 5, 7
        );

      SIMDE_CONVERT_VECTOR_(x1_, a_.i16);
      SIMDE_CONVERT_VECTOR_(x2_, b_.i16);

      simde_memcpy(&r1_, &x1_, sizeof(x1_));
      simde_memcpy(&r2_, &x2_, sizeof(x2_));

      uint32_t au SIMDE_VECTOR(16) = HEDLEY_REINTERPRET_CAST(__typeof__(src_.u32), (r1_[0].i32 * r2_[0].i32));
      uint32_t bu SIMDE_VECTOR(16) = HEDLEY_REINTERPRET_CAST(__typeof__(src_.u32), (r1_[1].i32 * r2_[1].i32));
      uint32_t ru SIMDE_VECTOR(16) = au + bu;

      au = (au >> 31) + INT32_MAX;

      uint32_t m SIMDE_VECTOR(16) = HEDLEY_REINTERPRET_CAST(__typeof__(m), HEDLEY_REINTERPRET_CAST(__typeof__(src_.i32), (au ^ bu) | ~(bu ^ ru)) < 0);
      bu = HEDLEY_REINTERPRET_CAST(__typeof__(bu), (au & ~m) | (ru & m));

      au = HEDLEY_REINTERPRET_CAST(__typeof__(src_.u32), src_.i32);
      ru = au + bu;

      au = (au >> 31) + INT32_MAX;

      m = HEDLEY_REINTERPRET_CAST(__typeof__(m), HEDLEY_REINTERPRET_CAST(__typeof__(src_.i32), (au ^ bu) | ~(bu ^ ru)) < 0);
      src_.i32 = HEDLEY_REINTERPRET_CAST(__typeof__(src_.i32), (au & ~m) | (ru & m));
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(a_.u16) / sizeof(a_.i16[0])) ; i++) {
        src_.i32[i / 2] = simde_math_adds_i32(src_.i32[i / 2], HEDLEY_STATIC_CAST(int32_t, a_.i16[i]) * HEDLEY_STATIC_CAST(int32_t, b_.i16[i]));
      }
    #endif

    return simde__m128i_from_private(src_);
  #endif
}
#if defined(SIMDE_X86_AVX512VNNI_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm_dpwssds_epi32
  #define _mm_dpwssds_epi32(src, a, b) simde_mm_dpwssds_epi32(src, a, b)
#endif

SIMDE_END_DECLS_
HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_X86_AVX512_DPWSSDS_H) */
