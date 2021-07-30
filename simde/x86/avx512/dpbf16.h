#if !defined(SIMDE_X86_AVX512_DPBF16_H)
#define SIMDE_X86_AVX512_DPBF16_H

#include "types.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

SIMDE_FUNCTION_ATTRIBUTES
simde__m128
simde_mm_dpbf16_ps (simde__m128 src, simde__m128bh a, simde__m128bh b) {
  #if defined(SIMDE_X86_AVX512BF16_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm_dpbf16_ps(src, a, b);
  #else
    simde__m128_private
      src_ = simde__m128_to_private(src);
    simde__m128bh_private
      a_ = simde__m128bh_to_private(a),
      b_ = simde__m128bh_to_private(b);

    #if defined(SIMDE_VECTOR_SUBSCRIPT_SCALAR) && defined(SIMDE_CONVERT_VECTOR_) && defined(SIMDE_SHUFFLE_VECTOR_)
      uint32_t x1 SIMDE_VECTOR(32);
      uint32_t x2 SIMDE_VECTOR(32);
      simde__m128_private
        r1_[2],
        r2_[2];

      a_.u16 =
        SIMDE_SHUFFLE_VECTOR_(
          16, 16,
          a_.u16, a_.u16,
          0, 2, 4, 6,
          1, 3, 5, 7
        );
      b_.u16 =
        SIMDE_SHUFFLE_VECTOR_(
          16, 16,
          b_.u16, b_.u16,
          0, 2, 4, 6,
          1, 3, 5, 7
        );

      SIMDE_CONVERT_VECTOR_(x1, a_.u16);
      SIMDE_CONVERT_VECTOR_(x2, b_.u16);

      x1 <<= 16;
      x2 <<= 16;

      simde_memcpy(&r1_, &x1, sizeof(x1));
      simde_memcpy(&r2_, &x2, sizeof(x2));

      src_.f32 +=
        HEDLEY_REINTERPRET_CAST(__typeof__(a_.f32), r1_[0].u32) * HEDLEY_REINTERPRET_CAST(__typeof__(a_.f32), r2_[0].u32) +
        HEDLEY_REINTERPRET_CAST(__typeof__(a_.f32), r1_[1].u32) * HEDLEY_REINTERPRET_CAST(__typeof__(a_.f32), r2_[1].u32);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(a_.u16) / sizeof(a_.u16[0])) ; i++) {
        src_.f32[i / 2] += (simde_uint32_as_float32(HEDLEY_STATIC_CAST(uint32_t, a_.u16[i]) << 16) * simde_uint32_as_float32(HEDLEY_STATIC_CAST(uint32_t, b_.u16[i]) << 16));
      }
    #endif

    return simde__m128_from_private(src_);
  #endif
}
#if defined(SIMDE_X86_AVX512BF16_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm_dpbf16_ps
  #define _mm_dpbf16_ps(src, a, b) simde_mm_dpbf16_ps(src, a, b)
#endif

SIMDE_END_DECLS_
HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_X86_AVX512_DPBF16_H) */
