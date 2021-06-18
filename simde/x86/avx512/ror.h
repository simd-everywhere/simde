#if !defined(SIMDE_X86_AVX512_ROR_H)
#define SIMDE_X86_AVX512_ROR_H

#include "types.h"
#include "mov.h"
#include "or.h"
#include "srli.h"
#include "slli.h"
#include "../avx2.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

#if defined(SIMDE_X86_AVX512F_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
  #define simde_mm_ror_epi32(a, imm8) _mm_ror_epi32(a, imm8)
#else
  SIMDE_FUNCTION_ATTRIBUTES
  simde__m128i
  simde_mm_ror_epi32_internal_(simde__m128i a, simde__m128i result, int imm8)
      SIMDE_REQUIRE_CONSTANT_RANGE (imm8, 0, 255) {
    simde__m128i retval;

    if(imm8 & 31)
      retval = result;
    else
      retval = a;

    return retval;
  }
  #define simde_mm_ror_epi32(a, imm8) simde_mm_ror_epi32_internal_(a, simde_mm_or_si128(simde_mm_srli_epi32(a, (imm8 & 31)), simde_mm_slli_epi32(a, (32 - (imm8 & 31)))), imm8)
#endif
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm_ror_epi32
  #define _mm_ror_epi32(a, imm8) simde_mm_ror_epi32(a, imm8)
#endif

#if defined(SIMDE_X86_AVX512F_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
  #define simde_mm_mask_ror_epi32(src, k, a, imm8) _mm_mask_ror_epi32(src, k, a, imm8)
#else
  #define simde_mm_mask_ror_epi32(src, k, a, imm8) simde_mm_mask_mov_epi32(src, k, simde_mm_ror_epi32(a, imm8))
#endif
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm_mask_ror_epi32
  #define _mm_mask_ror_epi32(src, k, a, imm8) simde_mm_mask_ror_epi32(src, k, a, imm8)
#endif

#if defined(SIMDE_X86_AVX512F_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
  #define simde_mm_maskz_ror_epi32(k, a, imm8) _mm_maskz_ror_epi32(k, a, imm8)
#else
  #define simde_mm_maskz_ror_epi32(k, a, imm8) simde_mm_maskz_mov_epi32(k, simde_mm_ror_epi32(a, imm8))
#endif
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm_maskz_ror_epi32
  #define _mm_maskz_ror_epi32(src, k, a, imm8) simde_mm_maskz_ror_epi32(src, k, a, imm8)
#endif

#if defined(SIMDE_X86_AVX512F_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
  #define simde_mm256_ror_epi32(a, imm8) _mm256_ror_epi32(a, imm8)
#else
  SIMDE_FUNCTION_ATTRIBUTES
  simde__m256i
  simde_mm256_ror_epi32_internal_(simde__m256i a, simde__m256i result, int imm8)
      SIMDE_REQUIRE_CONSTANT_RANGE (imm8, 0, 255) {
    simde__m256i retval;

    if(imm8 & 31)
      retval = result;
    else
      retval = a;

    return retval;
  }
  #define simde_mm256_ror_epi32(a, imm8) simde_mm256_ror_epi32_internal_(a, simde_mm256_or_si256(simde_mm256_srli_epi32(a, (imm8 & 31)), simde_mm256_slli_epi32(a, (32 - (imm8 & 31)))), imm8)
#endif
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm256_ror_epi32
  #define _mm256_ror_epi32(a, imm8) simde_mm256_ror_epi32(a, imm8)
#endif

#if defined(SIMDE_X86_AVX512F_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
  #define simde_mm256_mask_ror_epi32(src, k, a, imm8) _mm256_mask_ror_epi32(src, k, a, imm8)
#else
  #define simde_mm256_mask_ror_epi32(src, k, a, imm8) simde_mm256_mask_mov_epi32(src, k, simde_mm256_ror_epi32(a, imm8))
#endif
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm256_mask_ror_epi32
  #define _mm256_mask_ror_epi32(src, k, a, imm8) simde_mm256_mask_ror_epi32(src, k, a, imm8)
#endif

#if defined(SIMDE_X86_AVX512F_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
  #define simde_mm256_maskz_ror_epi32(k, a, imm8) _mm256_maskz_ror_epi32(k, a, imm8)
#else
  #define simde_mm256_maskz_ror_epi32(k, a, imm8) simde_mm256_maskz_mov_epi32(k, simde_mm256_ror_epi32(a, imm8))
#endif
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm256_maskz_ror_epi32
  #define _mm256_maskz_ror_epi32(k, a, imm8) simde_mm256_maskz_ror_epi32(k, a, imm8)
#endif

#if defined(SIMDE_X86_AVX512F_NATIVE)
  #define simde_mm512_ror_epi32(a, imm8) _mm512_ror_epi32(a, imm8)
#else
  SIMDE_FUNCTION_ATTRIBUTES
  simde__m512i
  simde_mm512_ror_epi32_internal_(simde__m512i a, simde__m512i result, int imm8)
      SIMDE_REQUIRE_CONSTANT_RANGE (imm8, 0, 255) {
    simde__m512i retval;

    if(imm8 & 31)
      retval = result;
    else
      retval = a;

    return retval;
  }
  #define simde_mm512_ror_epi32(a, imm8) simde_mm512_ror_epi32_internal_(a, simde_mm512_or_epi32(simde_mm512_srli_epi32(a, (imm8 & 31)), simde_mm512_slli_epi32(a, (32 - (imm8 & 31)))), imm8)
#endif
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_ror_epi32
  #define _mm512_ror_epi32(a, imm8) simde_mm512_ror_epi32(a, imm8)
#endif

#if defined(SIMDE_X86_AVX512F_NATIVE)
  #define simde_mm512_mask_ror_epi32(src, k, a, imm8) _mm512_mask_ror_epi32(src, k, a, imm8)
#else
  #define simde_mm512_mask_ror_epi32(src, k, a, imm8) simde_mm512_mask_mov_epi32(src, k, simde_mm512_ror_epi32(a, imm8))
#endif
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_ror_epi32
  #define _mm512_mask_ror_epi32(src, k, a, imm8) simde_mm512_mask_ror_epi32(src, k, a, imm8)
#endif

#if defined(SIMDE_X86_AVX512F_NATIVE)
  #define simde_mm512_maskz_ror_epi32(k, a, imm8) _mm512_maskz_ror_epi32(k, a, imm8)
#else
  #define simde_mm512_maskz_ror_epi32(k, a, imm8) simde_mm512_maskz_mov_epi32(k, simde_mm512_ror_epi32(a, imm8))
#endif
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_maskz_ror_epi32
  #define _mm512_maskz_ror_epi32(k, a, imm8) simde_mm512_maskz_ror_epi32(k, a, imm8)
#endif

#if defined(SIMDE_X86_AVX512F_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
  #define simde_mm_ror_epi64(a, imm8) _mm_ror_epi64(a, imm8)
#else
  SIMDE_FUNCTION_ATTRIBUTES
  simde__m128i
  simde_mm_ror_epi64_internal_(simde__m128i a, simde__m128i result, int imm8)
      SIMDE_REQUIRE_CONSTANT_RANGE (imm8, 0, 255) {
    simde__m128i retval;

    if(imm8 & 63)
      retval = result;
    else
      retval = a;

    return retval;
  }
  #define simde_mm_ror_epi64(a, imm8) simde_mm_ror_epi64_internal_(a, simde_mm_or_si128(simde_mm_srli_epi64(a, (imm8 & 63)), simde_mm_slli_epi64(a, (64 - (imm8 & 63)))), imm8)
#endif
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm_ror_epi64
  #define _mm_ror_epi64(a, imm8) simde_mm_ror_epi64(a, imm8)
#endif

#if defined(SIMDE_X86_AVX512F_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
  #define simde_mm_mask_ror_epi64(src, k, a, imm8) _mm_mask_ror_epi64(src, k, a, imm8)
#else
  #define simde_mm_mask_ror_epi64(src, k, a, imm8) simde_mm_mask_mov_epi64(src, k, simde_mm_ror_epi64(a, imm8))
#endif
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm_mask_ror_epi64
  #define _mm_mask_ror_epi64(src, k, a, imm8) simde_mm_mask_ror_epi64(src, k, a, imm8)
#endif

#if defined(SIMDE_X86_AVX512F_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
  #define simde_mm_maskz_ror_epi64(k, a, imm8) _mm_maskz_ror_epi64(k, a, imm8)
#else
  #define simde_mm_maskz_ror_epi64(k, a, imm8) simde_mm_maskz_mov_epi64(k, simde_mm_ror_epi64(a, imm8))
#endif
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm_maskz_ror_epi64
  #define _mm_maskz_ror_epi64(k, a, imm8) simde_mm_maskz_ror_epi64(k, a, imm8)
#endif

#if defined(SIMDE_X86_AVX512F_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
  #define simde_mm256_ror_epi64(a, imm8) _mm256_ror_epi64(a, imm8)
#else
  SIMDE_FUNCTION_ATTRIBUTES
  simde__m256i
  simde_mm256_ror_epi64_internal_(simde__m256i a, simde__m256i result, int imm8)
      SIMDE_REQUIRE_CONSTANT_RANGE (imm8, 0, 255) {
    simde__m256i retval;

    if(imm8 & 63)
      retval = result;
    else
      retval = a;

    return retval;
  }
  #define simde_mm256_ror_epi64(a, imm8) simde_mm256_ror_epi64_internal_(a, simde_mm256_or_si256(simde_mm256_srli_epi64(a, (imm8 & 63)), simde_mm256_slli_epi64(a, (64 - (imm8 & 63)))), imm8)
#endif
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm256_ror_epi64
  #define _mm256_ror_epi64(a, imm8) simde_mm256_ror_epi64(a, imm8)
#endif

#if defined(SIMDE_X86_AVX512F_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
  #define simde_mm256_mask_ror_epi64(src, k, a, imm8) _mm256_mask_ror_epi64(src, k, a, imm8)
#else
  #define simde_mm256_mask_ror_epi64(src, k, a, imm8) simde_mm256_mask_mov_epi64(src, k, simde_mm256_ror_epi64(a, imm8))
#endif
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm256_mask_ror_epi64
  #define _mm256_mask_ror_epi64(src, k, a, imm8) simde_mm256_mask_ror_epi64(src, k, a, imm8)
#endif

#if defined(SIMDE_X86_AVX512F_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
  #define simde_mm256_maskz_ror_epi64(k, a, imm8) _mm256_maskz_ror_epi64(k, a, imm8)
#else
  #define simde_mm256_maskz_ror_epi64(k, a, imm8) simde_mm256_maskz_mov_epi64(k, simde_mm256_ror_epi64(a, imm8))
#endif
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm256_maskz_ror_epi64
  #define _mm256_maskz_ror_epi64(k, a, imm8) simde_mm256_maskz_ror_epi64(k, a, imm8)
#endif

#if defined(SIMDE_X86_AVX512F_NATIVE)
  #define simde_mm512_ror_epi64(a, imm8) _mm512_ror_epi64(a, imm8)
#else
  SIMDE_FUNCTION_ATTRIBUTES
  simde__m512i
  simde_mm512_ror_epi64_internal_(simde__m512i a, simde__m512i result, int imm8)
      SIMDE_REQUIRE_CONSTANT_RANGE (imm8, 0, 255) {
    simde__m512i retval;

    if(imm8 & 63)
      retval = result;
    else
      retval = a;

    return retval;
  }
  #define simde_mm512_ror_epi64(a, imm8) simde_mm512_ror_epi64_internal_(a, simde_mm512_or_epi64(simde_mm512_srli_epi64(a, (imm8 & 63)), simde_mm512_slli_epi64(a, (64 - (imm8 & 63)))), imm8)
#endif
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_ror_epi64
  #define _mm512_ror_epi64(a, imm8) simde_mm512_ror_epi64(a, imm8)
#endif

#if defined(SIMDE_X86_AVX512F_NATIVE)
  #define simde_mm512_mask_ror_epi64(src, k, a, imm8) _mm512_mask_ror_epi64(src, k, a, imm8)
#else
  #define simde_mm512_mask_ror_epi64(src, k, a, imm8) simde_mm512_mask_mov_epi64(src, k, simde_mm512_ror_epi64(a, imm8))
#endif
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_ror_epi64
  #define _mm512_mask_ror_epi64(src, k, a, imm8) simde_mm512_mask_ror_epi64(src, k, a, imm8)
#endif

#if defined(SIMDE_X86_AVX512F_NATIVE)
  #define simde_mm512_maskz_ror_epi64(k, a, imm8) _mm512_maskz_ror_epi64(k, a, imm8)
#else
  #define simde_mm512_maskz_ror_epi64(k, a, imm8) simde_mm512_maskz_mov_epi64(k, simde_mm512_ror_epi64(a, imm8))
#endif
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_maskz_ror_epi64
  #define _mm512_maskz_ror_epi64(k, a, imm8) simde_mm512_maskz_ror_epi64(k, a, imm8)
#endif

SIMDE_END_DECLS_
HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_X86_AVX512_ROR_H) */
