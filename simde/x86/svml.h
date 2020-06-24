/* SPDX-License-Identifier: MIT
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use, copy,
 * modify, merge, publish, distribute, sublicense, and/or sell copies
 * of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
 * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
 * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 * Copyright:
 *   2020      Evan Nemerson <evan@nemerson.com>
     2020      Himanshi Mathur <himanshi18037@iiitd.ac.in>
 */

#if !defined(SIMDE_SVML_H)
#define SIMDE_SVML_H

#include "avx2.h"
#include "avx512f.h"

#if !defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_ENABLE_NATIVE_ALIASES)
#  define SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES
#endif

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

#if !defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_ENABLE_NATIVE_ALIASES)
#  define SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128
simde_mm_acos_ps (simde__m128 a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_SSE_NATIVE)
    return _mm_acos_ps(a);
  #else
    simde__m128_private
      r_,
      a_ = simde__m128_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f32) / sizeof(r_.f32[0])) ; i++) {
      r_.f32[i] =  simde_math_acosf(a_.f32[i]);
    }

    return simde__m128_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm_acos_ps
  #define _mm_acos_ps(a) simde_mm_acos_ps(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128d
simde_mm_acos_pd (simde__m128d a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_SSE_NATIVE)
    return _mm_acos_pd(a);
  #else
    simde__m128d_private
      r_,
      a_ = simde__m128d_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f64) / sizeof(r_.f64[0])) ; i++) {
      r_.f64[i] =  simde_math_acos(a_.f64[i]);
    }

    return simde__m128d_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm_acos_pd
  #define _mm_acos_pd(a) simde_mm_acos_pd(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256
simde_mm256_acos_ps (simde__m256 a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX_NATIVE)
    return _mm256_acos_ps(a);
  #else
    simde__m256_private
      r_,
      a_ = simde__m256_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f32) / sizeof(r_.f32[0])) ; i++) {
      r_.f32[i] =  simde_math_acosf(a_.f32[i]);
    }

    return simde__m256_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm256_acos_ps
  #define _mm256_acos_ps(a) simde_mm256_acos_ps(a)
#endif


SIMDE_FUNCTION_ATTRIBUTES
simde__m256d
simde_mm256_acos_pd (simde__m256d a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX_NATIVE)
    return _mm256_acos_pd(a);
  #else
    simde__m256d_private
      r_,
      a_ = simde__m256d_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f64) / sizeof(r_.f64[0])) ; i++) {
      r_.f64[i] =  simde_math_acos(a_.f64[i]);
    }

    return simde__m256d_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm256_acos_pd
  #define _mm256_acos_pd(a) simde_mm256_acos_pd(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512
simde_mm512_acos_ps (simde__m512 a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_acos_ps(a);
  #else
    simde__m512_private
      r_,
      a_ = simde__m512_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f32) / sizeof(r_.f32[0])) ; i++) {
      r_.f32[i] =  simde_math_acosf(a_.f32[i]);
    }

    return simde__m512_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm512_acos_ps
  #define _mm512_acos_ps(a) simde_mm512_acos_ps(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512d
simde_mm512_acos_pd (simde__m512d a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_acos_pd(a);
  #else
    simde__m512d_private
      r_,
      a_ = simde__m512d_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f64) / sizeof(r_.f64[0])) ; i++) {
      r_.f64[i] =  simde_math_acos(a_.f64[i]);
    }

    return simde__m512d_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm512_acos_pd
  #define _mm512_acos_pd(a) simde_mm512_acos_pd(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512
simde_mm512_mask_acos_ps(simde__m512 src, simde__mmask16 k, simde__m512 a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_mask_acos_ps(src, k, a);
  #else
    return simde_mm512_mask_mov_ps(src, k, simde_mm512_acos_ps(a));
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_acos_ps
  #define _mm512_mask_acos_ps(src, k, a) simde_mm512_mask_acos_ps(src, k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512d
simde_mm512_mask_acos_pd(simde__m512d src, simde__mmask8 k, simde__m512d a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_mask_acos_pd(src, k, a);
  #else
    return simde_mm512_mask_mov_pd(src, k, simde_mm512_acos_pd(a));
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_acos_pd
  #define _mm512_mask_acos_pd(src, k, a) simde_mm512_mask_acos_pd(src, k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128
simde_mm_acosh_ps (simde__m128 a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_SSE_NATIVE)
    return _mm_acosh_ps(a);
  #else
    simde__m128_private
      r_,
      a_ = simde__m128_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f32) / sizeof(r_.f32[0])) ; i++) {
      r_.f32[i] =  simde_math_acoshf(a_.f32[i]);
    }

    return simde__m128_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm_acosh_ps
  #define _mm_acosh_ps(a) simde_mm_acosh_ps(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128d
simde_mm_acosh_pd (simde__m128d a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_SSE_NATIVE)
    return _mm_acosh_pd(a);
  #else
    simde__m128d_private
      r_,
      a_ = simde__m128d_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f64) / sizeof(r_.f64[0])) ; i++) {
      r_.f64[i] =  simde_math_acosh(a_.f64[i]);
    }

    return simde__m128d_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm_acosh_pd
  #define _mm_acosh_pd(a) simde_mm_acosh_pd(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256
simde_mm256_acosh_ps (simde__m256 a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX_NATIVE)
    return _mm256_acosh_ps(a);
  #else
    simde__m256_private
      r_,
      a_ = simde__m256_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f32) / sizeof(r_.f32[0])) ; i++) {
      r_.f32[i] =  simde_math_acoshf(a_.f32[i]);
    }

    return simde__m256_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm256_acosh_ps
  #define _mm256_acosh_ps(a) simde_mm256_acosh_ps(a)
#endif


SIMDE_FUNCTION_ATTRIBUTES
simde__m256d
simde_mm256_acosh_pd (simde__m256d a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX_NATIVE)
    return _mm256_acosh_pd(a);
  #else
    simde__m256d_private
      r_,
      a_ = simde__m256d_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f64) / sizeof(r_.f64[0])) ; i++) {
      r_.f64[i] =  simde_math_acosh(a_.f64[i]);
    }

    return simde__m256d_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm256_acosh_pd
  #define _mm256_acosh_pd(a) simde_mm256_acosh_pd(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512
simde_mm512_acosh_ps (simde__m512 a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_acosh_ps(a);
  #else
    simde__m512_private
      r_,
      a_ = simde__m512_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f32) / sizeof(r_.f32[0])) ; i++) {
      r_.f32[i] =  simde_math_acoshf(a_.f32[i]);
    }

    return simde__m512_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm512_acosh_ps
  #define _mm512_acosh_ps(a) simde_mm512_acosh_ps(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512d
simde_mm512_acosh_pd (simde__m512d a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_acosh_pd(a);
  #else
    simde__m512d_private
      r_,
      a_ = simde__m512d_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f64) / sizeof(r_.f64[0])) ; i++) {
      r_.f64[i] =  simde_math_acosh(a_.f64[i]);
    }

    return simde__m512d_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm512_acosh_pd
  #define _mm512_acosh_pd(a) simde_mm512_acosh_pd(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512
simde_mm512_mask_acosh_ps(simde__m512 src, simde__mmask16 k, simde__m512 a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_mask_acosh_ps(src, k, a);
  #else
    return simde_mm512_mask_mov_ps(src, k, simde_mm512_acosh_ps(a));
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_acosh_ps
  #define _mm512_mask_acosh_ps(src, k, a) simde_mm512_mask_acosh_ps(src, k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512d
simde_mm512_mask_acosh_pd(simde__m512d src, simde__mmask8 k, simde__m512d a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_mask_acosh_pd(src, k, a);
  #else
    return simde_mm512_mask_mov_pd(src, k, simde_mm512_acosh_pd(a));
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_acosh_pd
  #define _mm512_mask_acosh_pd(src, k, a) simde_mm512_mask_acosh_pd(src, k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128
simde_mm_asin_ps (simde__m128 a) {
   #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_SSE_NATIVE)
    return _mm_asin_ps(a);
  #else
    simde__m128_private
      r_,
      a_ = simde__m128_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f32) / sizeof(r_.f32[0])) ; i++) {
      r_.f32[i] =  simde_math_asinf(a_.f32[i]);
    }

    return simde__m128_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm_asin_ps
  #define _mm_asin_ps(a) simde_mm_asin_ps(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128d
simde_mm_asin_pd (simde__m128d a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_SSE_NATIVE)
    return _mm_asin_pd(a);
  #else
    simde__m128d_private
      r_,
      a_ = simde__m128d_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f64) / sizeof(r_.f64[0])) ; i++) {
      r_.f64[i] =  simde_math_asin(a_.f64[i]);
    }

    return simde__m128d_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm_asin_pd
  #define _mm_asin_pd(a) simde_mm_asin_pd(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256
simde_mm256_asin_ps (simde__m256 a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX_NATIVE)
    return _mm256_asin_ps(a);
  #else
    simde__m256_private
      r_,
      a_ = simde__m256_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f32) / sizeof(r_.f32[0])) ; i++) {
      r_.f32[i] =  simde_math_asinf(a_.f32[i]);
    }

    return simde__m256_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm256_asin_ps
  #define _mm256_asin_ps(a) simde_mm256_asin_ps(a)
#endif


SIMDE_FUNCTION_ATTRIBUTES
simde__m256d
simde_mm256_asin_pd (simde__m256d a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX_NATIVE)
    return _mm256_asin_pd(a);
  #else
    simde__m256d_private
      r_,
      a_ = simde__m256d_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f64) / sizeof(r_.f64[0])) ; i++) {
      r_.f64[i] =  simde_math_asin(a_.f64[i]);
    }

    return simde__m256d_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm256_asin_pd
  #define _mm256_asin_pd(a) simde_mm256_asin_pd(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512
simde_mm512_asin_ps (simde__m512 a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_asin_ps(a);
  #else
    simde__m512_private
      r_,
      a_ = simde__m512_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f32) / sizeof(r_.f32[0])) ; i++) {
      r_.f32[i] =  simde_math_asinf(a_.f32[i]);
    }

    return simde__m512_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm512_asin_ps
  #define _mm512_asin_ps(a) simde_mm512_asin_ps(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512d
simde_mm512_asin_pd (simde__m512d a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_asin_pd(a);
  #else
    simde__m512d_private
      r_,
      a_ = simde__m512d_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f64) / sizeof(r_.f64[0])) ; i++) {
      r_.f64[i] =  simde_math_asin(a_.f64[i]);
    }

    return simde__m512d_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm512_asin_pd
  #define _mm512_asin_pd(a) simde_mm512_asin_pd(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512
simde_mm512_mask_asin_ps(simde__m512 src, simde__mmask16 k, simde__m512 a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_mask_asin_ps(src, k, a);
  #else
    return simde_mm512_mask_mov_ps(src, k, simde_mm512_asin_ps(a));
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_asin_ps
  #define _mm512_mask_asin_ps(src, k, a) simde_mm512_mask_asin_ps(src, k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512d
simde_mm512_mask_asin_pd(simde__m512d src, simde__mmask8 k, simde__m512d a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_mask_asin_pd(src, k, a);
  #else
    return simde_mm512_mask_mov_pd(src, k, simde_mm512_asin_pd(a));
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_asin_pd
  #define _mm512_mask_asin_pd(src, k, a) simde_mm512_mask_asin_pd(src, k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128
simde_mm_asinh_ps (simde__m128 a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_SSE_NATIVE)
    return _mm_asinh_ps(a);
  #else
    simde__m128_private
      r_,
      a_ = simde__m128_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f32) / sizeof(r_.f32[0])) ; i++) {
      r_.f32[i] =  simde_math_asinhf(a_.f32[i]);
    }

    return simde__m128_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm_asinh_ps
  #define _mm_asinh_ps(a) simde_mm_asinh_ps(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128d
simde_mm_asinh_pd (simde__m128d a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_SSE_NATIVE)
    return _mm_asinh_pd(a);
  #else
    simde__m128d_private
      r_,
      a_ = simde__m128d_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f64) / sizeof(r_.f64[0])) ; i++) {
      r_.f64[i] =  simde_math_asinh(a_.f64[i]);
    }

    return simde__m128d_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm_asinh_pd
  #define _mm_asinh_pd(a) simde_mm_asinh_pd(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256
simde_mm256_asinh_ps (simde__m256 a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX_NATIVE)
    return _mm256_asinh_ps(a);
  #else
    simde__m256_private
      r_,
      a_ = simde__m256_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f32) / sizeof(r_.f32[0])) ; i++) {
      r_.f32[i] =  simde_math_asinhf(a_.f32[i]);
    }

    return simde__m256_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm256_asinh_ps
  #define _mm256_asinh_ps(a) simde_mm256_asinh_ps(a)
#endif


SIMDE_FUNCTION_ATTRIBUTES
simde__m256d
simde_mm256_asinh_pd (simde__m256d a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX_NATIVE)
    return _mm256_asinh_pd(a);
  #else
    simde__m256d_private
      r_,
      a_ = simde__m256d_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f64) / sizeof(r_.f64[0])) ; i++) {
      r_.f64[i] =  simde_math_asinh(a_.f64[i]);
    }

    return simde__m256d_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm256_asinh_pd
  #define _mm256_asinh_pd(a) simde_mm256_asinh_pd(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512
simde_mm512_asinh_ps (simde__m512 a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_asinh_ps(a);
  #else
    simde__m512_private
      r_,
      a_ = simde__m512_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f32) / sizeof(r_.f32[0])) ; i++) {
      r_.f32[i] =  simde_math_asinhf(a_.f32[i]);
    }

    return simde__m512_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm512_asinh_ps
  #define _mm512_asinh_ps(a) simde_mm512_asinh_ps(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512d
simde_mm512_asinh_pd (simde__m512d a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_asinh_pd(a);
  #else
    simde__m512d_private
      r_,
      a_ = simde__m512d_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f64) / sizeof(r_.f64[0])) ; i++) {
      r_.f64[i] =  simde_math_asinh(a_.f64[i]);
    }

    return simde__m512d_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm512_asinh_pd
  #define _mm512_asinh_pd(a) simde_mm512_asinh_pd(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512
simde_mm512_mask_asinh_ps(simde__m512 src, simde__mmask16 k, simde__m512 a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_mask_asinh_ps(src, k, a);
  #else
    return simde_mm512_mask_mov_ps(src, k, simde_mm512_asinh_ps(a));
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_asinh_ps
  #define _mm512_mask_asinh_ps(src, k, a) simde_mm512_mask_asinh_ps(src, k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512d
simde_mm512_mask_asinh_pd(simde__m512d src, simde__mmask8 k, simde__m512d a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_mask_asinh_pd(src, k, a);
  #else
    return simde_mm512_mask_mov_pd(src, k, simde_mm512_asinh_pd(a));
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_asinh_pd
  #define _mm512_mask_asinh_pd(src, k, a) simde_mm512_mask_asinh_pd(src, k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128
simde_mm_atan_ps (simde__m128 a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_SSE_NATIVE)
    return _mm_atan_ps(a);
  #else
    simde__m128_private
      r_,
      a_ = simde__m128_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f32) / sizeof(r_.f32[0])) ; i++) {
      r_.f32[i] =  simde_math_atanf(a_.f32[i]);
    }

    return simde__m128_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm_atan_ps
  #define _mm_atan_ps(a) simde_mm_atan_ps(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128d
simde_mm_atan_pd (simde__m128d a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_SSE_NATIVE)
    return _mm_atan_pd(a);
  #else
    simde__m128d_private
      r_,
      a_ = simde__m128d_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f64) / sizeof(r_.f64[0])) ; i++) {
      r_.f64[i] =  simde_math_atan(a_.f64[i]);
    }

    return simde__m128d_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm_atan_pd
  #define _mm_atan_pd(a) simde_mm_atan_pd(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256
simde_mm256_atan_ps (simde__m256 a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX_NATIVE)
    return _mm256_atan_ps(a);
  #else
    simde__m256_private
      r_,
      a_ = simde__m256_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f32) / sizeof(r_.f32[0])) ; i++) {
      r_.f32[i] =  simde_math_atanf(a_.f32[i]);
    }

    return simde__m256_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm256_atan_ps
  #define _mm256_atan_ps(a) simde_mm256_atan_ps(a)
#endif


SIMDE_FUNCTION_ATTRIBUTES
simde__m256d
simde_mm256_atan_pd (simde__m256d a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX_NATIVE)
    return _mm256_atan_pd(a);
  #else
    simde__m256d_private
      r_,
      a_ = simde__m256d_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f64) / sizeof(r_.f64[0])) ; i++) {
      r_.f64[i] =  simde_math_atan(a_.f64[i]);
    }

    return simde__m256d_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm256_atan_pd
  #define _mm256_atan_pd(a) simde_mm256_atan_pd(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512
simde_mm512_atan_ps (simde__m512 a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_atan_ps(a);
  #else
    simde__m512_private
      r_,
      a_ = simde__m512_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f32) / sizeof(r_.f32[0])) ; i++) {
      r_.f32[i] =  simde_math_atanf(a_.f32[i]);
    }

    return simde__m512_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm512_atan_ps
  #define _mm512_atan_ps(a) simde_mm512_atan_ps(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512d
simde_mm512_atan_pd (simde__m512d a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_atan_pd(a);
  #else
    simde__m512d_private
      r_,
      a_ = simde__m512d_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f64) / sizeof(r_.f64[0])) ; i++) {
      r_.f64[i] =  simde_math_atan(a_.f64[i]);
    }

    return simde__m512d_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm512_atan_pd
  #define _mm512_atan_pd(a) simde_mm512_atan_pd(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512
simde_mm512_mask_atan_ps(simde__m512 src, simde__mmask16 k, simde__m512 a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_mask_atan_ps(src, k, a);
  #else
    return simde_mm512_mask_mov_ps(src, k, simde_mm512_atan_ps(a));
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_atan_ps
  #define _mm512_mask_atan_ps(src, k, a) simde_mm512_mask_atan_ps(src, k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512d
simde_mm512_mask_atan_pd(simde__m512d src, simde__mmask8 k, simde__m512d a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_mask_atan_pd(src, k, a);
  #else
    return simde_mm512_mask_mov_pd(src, k, simde_mm512_atan_pd(a));
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_atan_pd
  #define _mm512_mask_atan_pd(src, k, a) simde_mm512_mask_atan_pd(src, k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128
simde_mm_atan2_ps (simde__m128 a, simde__m128 b) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_SSE_NATIVE)
    return _mm_atan2_ps(a, b);
  #else
    simde__m128_private
      r_,
      a_ = simde__m128_to_private(a),
      b_ = simde__m128_to_private(b);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f32) / sizeof(r_.f32[0])) ; i++) {
      r_.f32[i] =  simde_math_atan2f(a_.f32[i], b_.f32[i]);
    }

    return simde__m128_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm_atan2_ps
  #define _mm_atan2_ps(a, b) simde_mm_atan2_ps(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128d
simde_mm_atan2_pd (simde__m128d a, simde__m128d b) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_SSE_NATIVE)
    return _mm_atan2_pd(a, b);
  #else
    simde__m128d_private
      r_,
      a_ = simde__m128d_to_private(a),
      b_ = simde__m128d_to_private(b);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f64) / sizeof(r_.f64[0])) ; i++) {
      r_.f64[i] =  simde_math_atan2(a_.f64[i], b_.f64[i]);
    }

    return simde__m128d_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm_atan2_pd
  #define _mm_atan2_pd(a, b) simde_mm_atan2_pd(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256
simde_mm256_atan2_ps (simde__m256 a, simde__m256 b) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX_NATIVE)
    return _mm256_atan2_ps(a, b);
  #else
    simde__m256_private
      r_,
      a_ = simde__m256_to_private(a),
      b_ = simde__m256_to_private(b);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f32) / sizeof(r_.f32[0])) ; i++) {
      r_.f32[i] =  simde_math_atan2f(a_.f32[i], b_.f32[i]);
    }

    return simde__m256_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm256_atan2_ps
  #define _mm256_atan2_ps(a, b) simde_mm256_atan2_ps(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256d
simde_mm256_atan2_pd (simde__m256d a, simde__m256d b) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX_NATIVE)
    return _mm256_atan2_pd(a, b);
  #else
    simde__m256d_private
      r_,
      a_ = simde__m256d_to_private(a),
      b_ = simde__m256d_to_private(b);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f64) / sizeof(r_.f64[0])) ; i++) {
      r_.f64[i] =  simde_math_atan2(a_.f64[i], b_.f64[i]);
    }

    return simde__m256d_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm256_atan2_pd
  #define _mm256_atan2_pd(a, b) simde_mm256_atan2_pd(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512
simde_mm512_atan2_ps (simde__m512 a, simde__m512 b) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_atan2_ps(a, b);
  #else
    simde__m512_private
      r_,
      a_ = simde__m512_to_private(a),
      b_ = simde__m512_to_private(b);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f32) / sizeof(r_.f32[0])) ; i++) {
      r_.f32[i] =  simde_math_atan2f(a_.f32[i], b_.f32[i]);
    }

    return simde__m512_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm512_atan2_ps
  #define _mm512_atan2_ps(a, b) simde_mm512_atan2_ps(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512d
simde_mm512_atan2_pd (simde__m512d a, simde__m512d b) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_atan2_pd(a, b);
  #else
    simde__m512d_private
      r_,
      a_ = simde__m512d_to_private(a),
      b_ = simde__m512d_to_private(b);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f64) / sizeof(r_.f64[0])) ; i++) {
      r_.f64[i] =  simde_math_atan2(a_.f64[i], b_.f64[i]);
    }

    return simde__m512d_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm512_atan2_pd
  #define _mm512_atan2_pd(a, b) simde_mm512_atan2_pd(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512
simde_mm512_mask_atan2_ps(simde__m512 src, simde__mmask16 k, simde__m512 a, simde__m512 b) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_mask_atan2_ps(src, k, a, b);
  #else
    return simde_mm512_mask_mov_ps(src, k, simde_mm512_atan2_ps(a, b));
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_atan2_ps
  #define _mm512_mask_atan2_ps(src, k, a, b) simde_mm512_mask_atan2_ps(src, k, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512d
simde_mm512_mask_atan2_pd(simde__m512d src, simde__mmask8 k, simde__m512d a, simde__m512d b) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_mask_atan2_pd(src, k, a, b);
  #else
    return simde_mm512_mask_mov_pd(src, k, simde_mm512_atan2_pd(a, b));
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_atan2_pd
  #define _mm512_mask_atan2_pd(src, k, a, b) simde_mm512_mask_atan2_pd(src, k, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128
simde_mm_atanh_ps (simde__m128 a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_SSE_NATIVE)
    return _mm_atanh_ps(a);
  #else
    simde__m128_private
      r_,
      a_ = simde__m128_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f32) / sizeof(r_.f32[0])) ; i++) {
      r_.f32[i] =  simde_math_atanhf(a_.f32[i]);
    }

    return simde__m128_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm_atanh_ps
  #define _mm_atanh_ps(a) simde_mm_atanh_ps(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128d
simde_mm_atanh_pd (simde__m128d a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_SSE_NATIVE)
    return _mm_atanh_pd(a);
  #else
    simde__m128d_private
      r_,
      a_ = simde__m128d_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f64) / sizeof(r_.f64[0])) ; i++) {
      r_.f64[i] =  simde_math_atanh(a_.f64[i]);
    }

    return simde__m128d_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm_atanh_pd
  #define _mm_atanh_pd(a) simde_mm_atanh_pd(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256
simde_mm256_atanh_ps (simde__m256 a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX_NATIVE)
    return _mm256_atanh_ps(a);
  #else
    simde__m256_private
      r_,
      a_ = simde__m256_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f32) / sizeof(r_.f32[0])) ; i++) {
      r_.f32[i] =  simde_math_atanhf(a_.f32[i]);
    }

    return simde__m256_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm256_atanh_ps
  #define _mm256_atanh_ps(a) simde_mm256_atanh_ps(a)
#endif


SIMDE_FUNCTION_ATTRIBUTES
simde__m256d
simde_mm256_atanh_pd (simde__m256d a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX_NATIVE)
    return _mm256_atanh_pd(a);
  #else
    simde__m256d_private
      r_,
      a_ = simde__m256d_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f64) / sizeof(r_.f64[0])) ; i++) {
      r_.f64[i] =  simde_math_atanh(a_.f64[i]);
    }

    return simde__m256d_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm256_atanh_pd
  #define _mm256_atanh_pd(a) simde_mm256_atanh_pd(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512
simde_mm512_atanh_ps (simde__m512 a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_atanh_ps(a);
  #else
    simde__m512_private
      r_,
      a_ = simde__m512_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f32) / sizeof(r_.f32[0])) ; i++) {
      r_.f32[i] =  simde_math_atanhf(a_.f32[i]);
    }

    return simde__m512_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm512_atanh_ps
  #define _mm512_atanh_ps(a) simde_mm512_atanh_ps(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512d
simde_mm512_atanh_pd (simde__m512d a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_atanh_pd(a);
  #else
    simde__m512d_private
      r_,
      a_ = simde__m512d_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f64) / sizeof(r_.f64[0])) ; i++) {
      r_.f64[i] =  simde_math_atanh(a_.f64[i]);
    }

    return simde__m512d_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm512_atanh_pd
  #define _mm512_atanh_pd(a) simde_mm512_atanh_pd(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512
simde_mm512_mask_atanh_ps(simde__m512 src, simde__mmask16 k, simde__m512 a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_mask_atanh_ps(src, k, a);
  #else
    return simde_mm512_mask_mov_ps(src, k, simde_mm512_atanh_ps(a));
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_atanh_ps
  #define _mm512_mask_atanh_ps(src, k, a) simde_mm512_mask_atanh_ps(src, k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512d
simde_mm512_mask_atanh_pd(simde__m512d src, simde__mmask8 k, simde__m512d a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_mask_atanh_pd(src, k, a);
  #else
    return simde_mm512_mask_mov_pd(src, k, simde_mm512_atanh_pd(a));
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_atanh_pd
  #define _mm512_mask_atanh_pd(src, k, a) simde_mm512_mask_atanh_pd(src, k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128
simde_mm_cbrt_ps (simde__m128 a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_SSE_NATIVE)
    return _mm_cbrt_ps(a);
  #else
    simde__m128_private
      r_,
      a_ = simde__m128_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f32) / sizeof(r_.f32[0])) ; i++) {
      r_.f32[i] =  simde_math_cbrtf(a_.f32[i]);
    }

    return simde__m128_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm_cbrt_ps
  #define _mm_cbrt_ps(a) simde_mm_cbrt_ps(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128d
simde_mm_cbrt_pd (simde__m128d a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_SSE_NATIVE)
    return _mm_cbrt_pd(a);
  #else
    simde__m128d_private
      r_,
      a_ = simde__m128d_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f64) / sizeof(r_.f64[0])) ; i++) {
      r_.f64[i] =  simde_math_cbrt(a_.f64[i]);
    }

    return simde__m128d_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm_cbrt_pd
  #define _mm_cbrt_pd(a) simde_mm_cbrt_pd(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256
simde_mm256_cbrt_ps (simde__m256 a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX_NATIVE)
    return _mm256_cbrt_ps(a);
  #else
    simde__m256_private
      r_,
      a_ = simde__m256_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f32) / sizeof(r_.f32[0])) ; i++) {
      r_.f32[i] =  simde_math_cbrtf(a_.f32[i]);
    }

    return simde__m256_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm256_cbrt_ps
  #define _mm256_cbrt_ps(a) simde_mm256_cbrt_ps(a)
#endif


SIMDE_FUNCTION_ATTRIBUTES
simde__m256d
simde_mm256_cbrt_pd (simde__m256d a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX_NATIVE)
    return _mm256_cbrt_pd(a);
  #else
    simde__m256d_private
      r_,
      a_ = simde__m256d_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f64) / sizeof(r_.f64[0])) ; i++) {
      r_.f64[i] =  simde_math_cbrt(a_.f64[i]);
    }

    return simde__m256d_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm256_cbrt_pd
  #define _mm256_cbrt_pd(a) simde_mm256_cbrt_pd(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512
simde_mm512_cbrt_ps (simde__m512 a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_cbrt_ps(a);
  #else
    simde__m512_private
      r_,
      a_ = simde__m512_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f32) / sizeof(r_.f32[0])) ; i++) {
      r_.f32[i] =  simde_math_cbrtf(a_.f32[i]);
    }

    return simde__m512_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm512_cbrt_ps
  #define _mm512_cbrt_ps(a) simde_mm512_cbrt_ps(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512d
simde_mm512_cbrt_pd (simde__m512d a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_cbrt_pd(a);
  #else
    simde__m512d_private
      r_,
      a_ = simde__m512d_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f64) / sizeof(r_.f64[0])) ; i++) {
      r_.f64[i] =  simde_math_cbrt(a_.f64[i]);
    }

    return simde__m512d_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm512_cbrt_pd
  #define _mm512_cbrt_pd(a) simde_mm512_cbrt_pd(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512
simde_mm512_mask_cbrt_ps(simde__m512 src, simde__mmask16 k, simde__m512 a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_mask_cbrt_ps(src, k, a);
  #else
    return simde_mm512_mask_mov_ps(src, k, simde_mm512_cbrt_ps(a));
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_cbrt_ps
  #define _mm512_mask_cbrt_ps(src, k, a) simde_mm512_mask_cbrt_ps(src, k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512d
simde_mm512_mask_cbrt_pd(simde__m512d src, simde__mmask8 k, simde__m512d a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_mask_cbrt_pd(src, k, a);
  #else
    return simde_mm512_mask_mov_pd(src, k, simde_mm512_cbrt_pd(a));
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_cbrt_pd
  #define _mm512_mask_cbrt_pd(src, k, a) simde_mm512_mask_cbrt_pd(src, k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128
simde_mm_cdfnorm_ps (simde__m128 a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_SSE_NATIVE)
    return _mm_cdfnorm_ps(a);
  #else
    simde__m128_private
      r_,
      a_ = simde__m128_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f32) / sizeof(r_.f32[0])) ; i++) {
      r_.f32[i] =  simde_math_cdfnormf(a_.f32[i]);
    }

    return simde__m128_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm_cdfnorm_ps
  #define _mm_cdfnorm_ps(a) simde_mm_cdfnorm_ps(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128d
simde_mm_cdfnorm_pd (simde__m128d a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_SSE_NATIVE)
    return _mm_cdfnorm_pd(a);
  #else
    simde__m128d_private
      r_,
      a_ = simde__m128d_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f64) / sizeof(r_.f64[0])) ; i++) {
      r_.f64[i] =  simde_math_cdfnorm(a_.f64[i]);
    }

    return simde__m128d_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm_cdfnorm_pd
  #define _mm_cdfnorm_pd(a) simde_mm_cdfnorm_pd(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256
simde_mm256_cdfnorm_ps (simde__m256 a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX_NATIVE)
    return _mm256_cdfnorm_ps(a);
  #else
    simde__m256_private
      r_,
      a_ = simde__m256_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f32) / sizeof(r_.f32[0])) ; i++) {
      r_.f32[i] =  simde_math_cdfnormf(a_.f32[i]);
    }

    return simde__m256_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm256_cdfnorm_ps
  #define _mm256_cdfnorm_ps(a) simde_mm256_cdfnorm_ps(a)
#endif


SIMDE_FUNCTION_ATTRIBUTES
simde__m256d
simde_mm256_cdfnorm_pd (simde__m256d a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX_NATIVE)
    return _mm256_cdfnorm_pd(a);
  #else
    simde__m256d_private
      r_,
      a_ = simde__m256d_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f64) / sizeof(r_.f64[0])) ; i++) {
      r_.f64[i] =  simde_math_cdfnorm(a_.f64[i]);
    }

    return simde__m256d_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm256_cdfnorm_pd
  #define _mm256_cdfnorm_pd(a) simde_mm256_cdfnorm_pd(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512
simde_mm512_cdfnorm_ps (simde__m512 a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_cdfnorm_ps(a);
  #else
    simde__m512_private
      r_,
      a_ = simde__m512_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f32) / sizeof(r_.f32[0])) ; i++) {
      r_.f32[i] =  simde_math_cdfnormf(a_.f32[i]);
    }

    return simde__m512_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm512_cdfnorm_ps
  #define _mm512_cdfnorm_ps(a) simde_mm512_cdfnorm_ps(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512d
simde_mm512_cdfnorm_pd (simde__m512d a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_cdfnorm_pd(a);
  #else
    simde__m512d_private
      r_,
      a_ = simde__m512d_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f64) / sizeof(r_.f64[0])) ; i++) {
      r_.f64[i] =  simde_math_cdfnorm(a_.f64[i]);
    }

    return simde__m512d_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm512_cdfnorm_pd
  #define _mm512_cdfnorm_pd(a) simde_mm512_cdfnorm_pd(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512
simde_mm512_mask_cdfnorm_ps(simde__m512 src, simde__mmask16 k, simde__m512 a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_mask_cdfnorm_ps(src, k, a);
  #else
    return simde_mm512_mask_mov_ps(src, k, simde_mm512_cdfnorm_ps(a));
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_cdfnorm_ps
  #define _mm512_mask_cdfnorm_ps(src, k, a) simde_mm512_mask_cdfnorm_ps(src, k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512d
simde_mm512_mask_cdfnorm_pd(simde__m512d src, simde__mmask8 k, simde__m512d a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_mask_cdfnorm_pd(src, k, a);
  #else
    return simde_mm512_mask_mov_pd(src, k, simde_mm512_cdfnorm_pd(a));
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_cdfnorm_pd
  #define _mm512_mask_cdfnorm_pd(src, k, a) simde_mm512_mask_cdfnorm_pd(src, k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128
simde_mm_cos_ps (simde__m128 a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_SSE_NATIVE)
    return _mm_cos_ps(a);
  #else
    simde__m128_private
      r_,
      a_ = simde__m128_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f32) / sizeof(r_.f32[0])) ; i++) {
      r_.f32[i] =  simde_math_cosf(a_.f32[i]);
    }

    return simde__m128_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm_cos_ps
  #define _mm_cos_ps(a) simde_mm_cos_ps(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128d
simde_mm_cos_pd (simde__m128d a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_SSE_NATIVE)
    return _mm_cos_pd(a);
  #else
    simde__m128d_private
      r_,
      a_ = simde__m128d_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f64) / sizeof(r_.f64[0])) ; i++) {
      r_.f64[i] =  simde_math_cos(a_.f64[i]);
    }

    return simde__m128d_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm_cos_pd
  #define _mm_cos_pd(a) simde_mm_cos_pd(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256
simde_mm256_cos_ps (simde__m256 a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX_NATIVE)
    return _mm256_cos_ps(a);
  #else
    simde__m256_private
      r_,
      a_ = simde__m256_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f32) / sizeof(r_.f32[0])) ; i++) {
      r_.f32[i] =  simde_math_cosf(a_.f32[i]);
    }

    return simde__m256_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm256_cos_ps
  #define _mm256_cos_ps(a) simde_mm256_cos_ps(a)
#endif


SIMDE_FUNCTION_ATTRIBUTES
simde__m256d
simde_mm256_cos_pd (simde__m256d a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX_NATIVE)
    return _mm256_cos_pd(a);
  #else
    simde__m256d_private
      r_,
      a_ = simde__m256d_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f64) / sizeof(r_.f64[0])) ; i++) {
      r_.f64[i] =  simde_math_cos(a_.f64[i]);
    }

    return simde__m256d_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm256_cos_pd
  #define _mm256_cos_pd(a) simde_mm256_cos_pd(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512
simde_mm512_cos_ps (simde__m512 a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_cos_ps(a);
  #else
    simde__m512_private
      r_,
      a_ = simde__m512_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f32) / sizeof(r_.f32[0])) ; i++) {
      r_.f32[i] =  simde_math_cosf(a_.f32[i]);
    }

    return simde__m512_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm512_cos_ps
  #define _mm512_cos_ps(a) simde_mm512_cos_ps(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512d
simde_mm512_cos_pd (simde__m512d a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_cos_pd(a);
  #else
    simde__m512d_private
      r_,
      a_ = simde__m512d_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f64) / sizeof(r_.f64[0])) ; i++) {
      r_.f64[i] =  simde_math_cos(a_.f64[i]);
    }

    return simde__m512d_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm512_cos_pd
  #define _mm512_cos_pd(a) simde_mm512_cos_pd(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512
simde_mm512_mask_cos_ps(simde__m512 src, simde__mmask16 k, simde__m512 a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_mask_cos_ps(src, k, a);
  #else
    return simde_mm512_mask_mov_ps(src, k, simde_mm512_cos_ps(a));
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_cos_ps
  #define _mm512_mask_cos_ps(src, k, a) simde_mm512_mask_cos_ps(src, k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512d
simde_mm512_mask_cos_pd(simde__m512d src, simde__mmask8 k, simde__m512d a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_mask_cos_pd(src, k, a);
  #else
    return simde_mm512_mask_mov_pd(src, k, simde_mm512_cos_pd(a));
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_cos_pd
  #define _mm512_mask_cos_pd(src, k, a) simde_mm512_mask_cos_pd(src, k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128
simde_mm_cosd_ps (simde__m128 a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_SSE_NATIVE)
    return _mm_cosd_ps(a);
  #else
    simde__m128_private
      r_,
      a_ = simde__m128_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f32) / sizeof(r_.f32[0])) ; i++) {
      r_.f32[i] =  simde_math_cosf(simde_math_deg2radf(a_.f32[i]));
    }

    return simde__m128_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm_cosd_ps
  #define _mm_cosd_ps(a) simde_mm_cosd_ps(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128d
simde_mm_cosd_pd (simde__m128d a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_SSE_NATIVE)
    return _mm_cosd_pd(a);
  #else
    simde__m128d_private
      r_,
      a_ = simde__m128d_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f64) / sizeof(r_.f64[0])) ; i++) {
      r_.f64[i] =  simde_math_cos(simde_math_deg2rad(a_.f64[i]));
    }

    return simde__m128d_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm_cosd_pd
  #define _mm_cosd_pd(a) simde_mm_cosd_pd(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256
simde_mm256_cosd_ps (simde__m256 a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX_NATIVE)
    return _mm256_cosd_ps(a);
  #else
    simde__m256_private
      r_,
      a_ = simde__m256_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f32) / sizeof(r_.f32[0])) ; i++) {
      r_.f32[i] =  simde_math_cosf(simde_math_deg2radf(a_.f32[i]));
    }

    return simde__m256_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm256_cosd_ps
  #define _mm256_cosd_ps(a) simde_mm256_cosd_ps(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256d
simde_mm256_cosd_pd (simde__m256d a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX_NATIVE)
    return _mm256_cosd_pd(a);
  #else
    simde__m256d_private
      r_,
      a_ = simde__m256d_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f64) / sizeof(r_.f64[0])) ; i++) {
      r_.f64[i] =  simde_math_cos(simde_math_deg2rad(a_.f64[i]));
    }

    return simde__m256d_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm256_cosd_pd
  #define _mm256_cosd_pd(a) simde_mm256_cosd_pd(a)
#endif


SIMDE_FUNCTION_ATTRIBUTES
simde__m512
simde_mm512_cosd_ps (simde__m512 a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_cosd_ps(a);
  #else
    simde__m512_private
      r_,
      a_ = simde__m512_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f32) / sizeof(r_.f32[0])) ; i++) {
      r_.f32[i] =  simde_math_cosf(simde_math_deg2radf(a_.f32[i]));
    }

    return simde__m512_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm512_cosd_ps
  #define _mm512_cosd_ps(a) simde_mm512_cosd_ps(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512d
simde_mm512_cosd_pd (simde__m512d a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_cosd_pd(a);
  #else
    simde__m512d_private
      r_,
      a_ = simde__m512d_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f64) / sizeof(r_.f64[0])) ; i++) {
      r_.f64[i] =  simde_math_cos(simde_math_deg2rad(a_.f64[i]));
    }

    return simde__m512d_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm512_cosd_pd
  #define _mm512_cosd_pd(a) simde_mm512_cosd_pd(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512
simde_mm512_mask_cosd_ps(simde__m512 src, simde__mmask16 k, simde__m512 a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_mask_cosd_ps(src, k, a);
  #else
    return simde_mm512_mask_mov_ps(src, k, simde_mm512_cosd_ps(a));
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_cosd_ps
  #define _mm512_mask_cosd_ps(src, k, a) simde_mm512_mask_cosd_ps(src, k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512d
simde_mm512_mask_cosd_pd(simde__m512d src, simde__mmask8 k, simde__m512d a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_mask_cosd_pd(src, k, a);
  #else
    return simde_mm512_mask_mov_pd(src, k, simde_mm512_cosd_pd(a));
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_cosd_pd
  #define _mm512_mask_cosd_pd(src, k, a) simde_mm512_mask_cosd_pd(src, k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128
simde_mm_cosh_ps (simde__m128 a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_SSE_NATIVE)
    return _mm_cosh_ps(a);
  #else
    simde__m128_private
      r_,
      a_ = simde__m128_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f32) / sizeof(r_.f32[0])) ; i++) {
      r_.f32[i] =  simde_math_coshf(a_.f32[i]);
    }

    return simde__m128_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm_cosh_ps
  #define _mm_cosh_ps(a) simde_mm_cosh_ps(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128d
simde_mm_cosh_pd (simde__m128d a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_SSE_NATIVE)
    return _mm_cosh_pd(a);
  #else
    simde__m128d_private
      r_,
      a_ = simde__m128d_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f64) / sizeof(r_.f64[0])) ; i++) {
      r_.f64[i] =  simde_math_cosh(a_.f64[i]);
    }

    return simde__m128d_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm_cosh_pd
  #define _mm_cosh_pd(a) simde_mm_cosh_pd(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256
simde_mm256_cosh_ps (simde__m256 a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX_NATIVE)
    return _mm256_cosh_ps(a);
  #else
    simde__m256_private
      r_,
      a_ = simde__m256_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f32) / sizeof(r_.f32[0])) ; i++) {
      r_.f32[i] =  simde_math_coshf(a_.f32[i]);
    }

    return simde__m256_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm256_cosh_ps
  #define _mm256_cosh_ps(a) simde_mm256_cosh_ps(a)
#endif


SIMDE_FUNCTION_ATTRIBUTES
simde__m256d
simde_mm256_cosh_pd (simde__m256d a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX_NATIVE)
    return _mm256_cosh_pd(a);
  #else
    simde__m256d_private
      r_,
      a_ = simde__m256d_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f64) / sizeof(r_.f64[0])) ; i++) {
      r_.f64[i] =  simde_math_cosh(a_.f64[i]);
    }

    return simde__m256d_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm256_cosh_pd
  #define _mm256_cosh_pd(a) simde_mm256_cosh_pd(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512
simde_mm512_cosh_ps (simde__m512 a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_cosh_ps(a);
  #else
    simde__m512_private
      r_,
      a_ = simde__m512_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f32) / sizeof(r_.f32[0])) ; i++) {
      r_.f32[i] =  simde_math_coshf(a_.f32[i]);
    }

    return simde__m512_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm512_cosh_ps
  #define _mm512_cosh_ps(a) simde_mm512_cosh_ps(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512d
simde_mm512_cosh_pd (simde__m512d a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_cosh_pd(a);
  #else
    simde__m512d_private
      r_,
      a_ = simde__m512d_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f64) / sizeof(r_.f64[0])) ; i++) {
      r_.f64[i] =  simde_math_cosh(a_.f64[i]);
    }

    return simde__m512d_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm512_cosh_pd
  #define _mm512_cosh_pd(a) simde_mm512_cosh_pd(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512
simde_mm512_mask_cosh_ps(simde__m512 src, simde__mmask16 k, simde__m512 a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_mask_cosh_ps(src, k, a);
  #else
    return simde_mm512_mask_mov_ps(src, k, simde_mm512_cosh_ps(a));
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_cosh_ps
  #define _mm512_mask_cosh_ps(src, k, a) simde_mm512_mask_cosh_ps(src, k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512d
simde_mm512_mask_cosh_pd(simde__m512d src, simde__mmask8 k, simde__m512d a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_mask_cosh_pd(src, k, a);
  #else
    return simde_mm512_mask_mov_pd(src, k, simde_mm512_cosh_pd(a));
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_cosh_pd
  #define _mm512_mask_cosh_pd(src, k, a) simde_mm512_mask_cosh_pd(src, k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_div_epi8 (simde__m128i a, simde__m128i b) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_div_epi8(a, b);
  #else
    simde__m128i_private
      r_,
      a_ = simde__m128i_to_private(a),
      b_ = simde__m128i_to_private(b);

    #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r_.i8 = a_.i8 / b_.i8;
    #elif defined(SIMDE_WASM_SIMD128_NATIVE)
      r_.wasm_v128 = wasm_i8x4_div(a_.wasm_v128, b_.wasm_v128);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.i8) / sizeof(r_.i8[0])) ; i++) {
        r_.i8[i] = a_.i8[i] / b_.i8[i];
      }
    #endif

    return simde__m128i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm_div_epi8
  #define _mm_div_epi8(a, b) simde_mm_div_epi8((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_div_epi16 (simde__m128i a, simde__m128i b) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_div_epi16(a, b);
  #else
    simde__m128i_private
      r_,
      a_ = simde__m128i_to_private(a),
      b_ = simde__m128i_to_private(b);

    #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r_.i16 = a_.i16 / b_.i16;
    #elif defined(SIMDE_WASM_SIMD128_NATIVE)
      r_.wasm_v128 = wasm_i16x4_div(a_.wasm_v128, b_.wasm_v128);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.i16) / sizeof(r_.i16[0])) ; i++) {
        r_.i16[i] = a_.i16[i] / b_.i16[i];
      }
    #endif

    return simde__m128i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm_div_epi16
  #define _mm_div_epi16(a, b) simde_mm_div_epi16((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_div_epi32 (simde__m128i a, simde__m128i b) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_div_epi32(a, b);
  #else
    simde__m128i_private
      r_,
      a_ = simde__m128i_to_private(a),
      b_ = simde__m128i_to_private(b);

    #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r_.i32 = a_.i32 / b_.i32;
    #elif defined(SIMDE_WASM_SIMD128_NATIVE)
      r_.wasm_v128 = wasm_i32x4_div(a_.wasm_v128, b_.wasm_v128);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.i32) / sizeof(r_.i32[0])) ; i++) {
        r_.i32[i] = a_.i32[i] / b_.i32[i];
      }
    #endif

    return simde__m128i_from_private(r_);
  #endif
}
#define simde_mm_idiv_epi32(a, b) simde_mm_div_epi32(a, b)
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm_div_epi32
  #define _mm_div_epi32(a, b) simde_mm_div_epi32(a, b)
  #undef _mm_idiv_epi32
  #define _mm_idiv_epi32(a, b) simde_mm_div_epi32(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_div_epi64 (simde__m128i a, simde__m128i b) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_div_epi64(a, b);
  #else
    simde__m128i_private
      r_,
      a_ = simde__m128i_to_private(a),
      b_ = simde__m128i_to_private(b);

    #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r_.i64 = a_.i64 / b_.i64;
    #elif defined(SIMDE_WASM_SIMD128_NATIVE)
      r_.wasm_v128 = wasm_i64x4_div(a_.wasm_v128, b_.wasm_v128);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.i64) / sizeof(r_.i64[0])) ; i++) {
        r_.i64[i] = a_.i64[i] / b_.i64[i];
      }
    #endif

    return simde__m128i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm_div_epi64
  #define _mm_div_epi64(a, b) simde_mm_div_epi64((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_div_epu8 (simde__m128i a, simde__m128i b) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_div_epu8(a, b);
  #else
    simde__m128i_private
      r_,
      a_ = simde__m128i_to_private(a),
      b_ = simde__m128i_to_private(b);

    #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r_.u8 = a_.u8 / b_.u8;
    #elif defined(SIMDE_WASM_SIMD128_NATIVE)
      r_.wasm_v128 =  wasm_u8x16_div(a_.wasm_v128, b_.wasm_v128);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.u8) / sizeof(r_.u8[0])) ; i++) {
        r_.u8[i] = a_.u8[i] / b_.u8[i];
      }
    #endif

    return simde__m128i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm_div_epu8
  #define _mm_div_epu8(a, b) simde_mm_div_epu8((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_div_epu16 (simde__m128i a, simde__m128i b) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_div_epu16(a, b);
  #else
    simde__m128i_private
      r_,
      a_ = simde__m128i_to_private(a),
      b_ = simde__m128i_to_private(b);

    #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r_.u16 = a_.u16 / b_.u16;
    #elif defined(SIMDE_WASM_SIMD128_NATIVE)
      r_.wasm_v128 =  wasm_u16x16_div(a_.wasm_v128, b_.wasm_v128);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.u16) / sizeof(r_.u16[0])) ; i++) {
        r_.u16[i] = a_.u16[i] / b_.u16[i];
      }
    #endif

    return simde__m128i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm_div_epu16
  #define _mm_div_epu16(a, b) simde_mm_div_epu16((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_div_epu32 (simde__m128i a, simde__m128i b) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_div_epu32(a, b);
  #else
    simde__m128i_private
      r_,
      a_ = simde__m128i_to_private(a),
      b_ = simde__m128i_to_private(b);

    #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r_.u32 = a_.u32 / b_.u32;
    #elif defined(SIMDE_WASM_SIMD128_NATIVE)
      r_.wasm_v128 =  wasm_u32x16_div(a_.wasm_v128, b_.wasm_v128);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.u32) / sizeof(r_.u32[0])) ; i++) {
        r_.u32[i] = a_.u32[i] / b_.u32[i];
      }
    #endif

    return simde__m128i_from_private(r_);
  #endif
}
#define simde_mm_udiv_epi32(a, b) simde_mm_div_epu32(a, b)
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm_div_epu32
  #define _mm_div_epu32(a, b) simde_mm_div_epu32(a, b)
  #undef _mm_udiv_epi32
  #define _mm_udiv_epi32(a, b) simde_mm_div_epu32(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_div_epu64 (simde__m128i a, simde__m128i b) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_div_epu64(a, b);
  #else
    simde__m128i_private
      r_,
      a_ = simde__m128i_to_private(a),
      b_ = simde__m128i_to_private(b);

    #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r_.u64 = a_.u64 / b_.u64;
    #elif defined(SIMDE_WASM_SIMD128_NATIVE)
      r_.wasm_v128 =  wasm_u64x16_div(a_.wasm_v128, b_.wasm_v128);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.u64) / sizeof(r_.u64[0])) ; i++) {
        r_.u64[i] = a_.u64[i] / b_.u64[i];
      }
    #endif

    return simde__m128i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm_div_epu64
  #define _mm_div_epu64(a, b) simde_mm_div_epu64((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_div_epi8 (simde__m256i a, simde__m256i b) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX_NATIVE)
    return _mm256_div_epi8(a, b);
  #else
    simde__m256i_private
      r_,
      a_ = simde__m256i_to_private(a),
      b_ = simde__m256i_to_private(b);

    #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r_.i8 = a_.i8 / b_.i8;
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.i8) / sizeof(r_.i8[0])) ; i++) {
        r_.i8[i] = a_.i8[i] / b_.i8[i];
      }
    #endif

    return simde__m256i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm256_div_epi8
  #define _mm256_div_epi8(a, b) simde_mm256_div_epi8((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_div_epi16 (simde__m256i a, simde__m256i b) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX_NATIVE)
    return _mm256_div_epi16(a, b);
  #else
    simde__m256i_private
      r_,
      a_ = simde__m256i_to_private(a),
      b_ = simde__m256i_to_private(b);

    #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r_.i16 = a_.i16 / b_.i16;
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.i16) / sizeof(r_.i16[0])) ; i++) {
        r_.i16[i] = a_.i16[i] / b_.i16[i];
      }
    #endif

    return simde__m256i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm256_div_epi16
  #define _mm256_div_epi16(a, b) simde_mm256_div_epi16((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_div_epi32 (simde__m256i a, simde__m256i b) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX_NATIVE)
    return _mm256_div_epi32(a, b);
  #else
    simde__m256i_private
      r_,
      a_ = simde__m256i_to_private(a),
      b_ = simde__m256i_to_private(b);

    #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r_.i32 = a_.i32 / b_.i32;
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.i32) / sizeof(r_.i32[0])) ; i++) {
        r_.i32[i] = a_.i32[i] / b_.i32[i];
      }
    #endif

    return simde__m256i_from_private(r_);
  #endif
}
#define simde_mm256_idiv_epi32(a, b) simde_mm256_div_epi32(a, b)
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm256_div_epi32
  #define _mm256_div_epi32(a, b) simde_mm256_div_epi32(a, b)
  #undef _mm256_idiv_epi32
  #define _mm256_idiv_epi32(a, b) simde_mm256_div_epi32(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_div_epi64 (simde__m256i a, simde__m256i b) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX_NATIVE)
    return _mm256_div_epi64(a, b);
  #else
    simde__m256i_private
      r_,
      a_ = simde__m256i_to_private(a),
      b_ = simde__m256i_to_private(b);

    #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r_.i64 = a_.i64 / b_.i64;
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.i64) / sizeof(r_.i64[0])) ; i++) {
        r_.i64[i] = a_.i64[i] / b_.i64[i];
      }
    #endif

    return simde__m256i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm256_div_epi64
  #define _mm256_div_epi64(a, b) simde_mm256_div_epi64((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_div_epu8 (simde__m256i a, simde__m256i b) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX_NATIVE)
    return _mm256_div_epu8(a, b);
  #else
    simde__m256i_private
      r_,
      a_ = simde__m256i_to_private(a),
      b_ = simde__m256i_to_private(b);

    #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r_.u8 = a_.u8 / b_.u8;
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.u8) / sizeof(r_.u8[0])) ; i++) {
        r_.u8[i] = a_.u8[i] / b_.u8[i];
      }
    #endif

    return simde__m256i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm256_div_epu8
  #define _mm256_div_epu8(a, b) simde_mm256_div_epu8((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_div_epu16 (simde__m256i a, simde__m256i b) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX_NATIVE)
    return _mm256_div_epu16(a, b);
  #else
    simde__m256i_private
      r_,
      a_ = simde__m256i_to_private(a),
      b_ = simde__m256i_to_private(b);

    #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r_.u16 = a_.u16 / b_.u16;
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.u16) / sizeof(r_.u16[0])) ; i++) {
        r_.u16[i] = a_.u16[i] / b_.u16[i];
      }
    #endif

    return simde__m256i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm256_div_epu16
  #define _mm256_div_epu16(a, b) simde_mm256_div_epu16((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_div_epu32 (simde__m256i a, simde__m256i b) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX_NATIVE)
    return _mm256_div_epu32(a, b);
  #else
    simde__m256i_private
      r_,
      a_ = simde__m256i_to_private(a),
      b_ = simde__m256i_to_private(b);

    #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r_.u32 = a_.u32 / b_.u32;
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.u32) / sizeof(r_.u32[0])) ; i++) {
        r_.u32[i] = a_.u32[i] / b_.u32[i];
      }
    #endif

    return simde__m256i_from_private(r_);
  #endif
}
#define simde_mm256_udiv_epi32(a, b) simde_mm256_div_epu32(a, b)
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm256_div_epu32
  #define _mm256_div_epu32(a, b) simde_mm256_div_epu32(a, b)
  #undef _mm256_udiv_epi32
  #define _mm256_udiv_epi32(a, b) simde_mm256_div_epu32(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_div_epu64 (simde__m256i a, simde__m256i b) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX_NATIVE)
    return _mm256_div_epu64(a, b);
  #else
    simde__m256i_private
      r_,
      a_ = simde__m256i_to_private(a),
      b_ = simde__m256i_to_private(b);

    #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r_.u64 = a_.u64 / b_.u64;
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.u64) / sizeof(r_.u64[0])) ; i++) {
        r_.u64[i] = a_.u64[i] / b_.u64[i];
      }
    #endif

    return simde__m256i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm256_div_epu64
  #define _mm256_div_epu64(a, b) simde_mm256_div_epu64((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_div_epi8 (simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_div_epi8(a, b);
  #else
    simde__m512i_private
      r_,
      a_ = simde__m512i_to_private(a),
      b_ = simde__m512i_to_private(b);

    #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r_.i8 = a_.i8 / b_.i8;
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.i8) / sizeof(r_.i8[0])) ; i++) {
        r_.i8[i] = a_.i8[i] / b_.i8[i];
      }
    #endif

    return simde__m512i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm512_div_epi8
  #define _mm512_div_epi8(a, b) simde_mm512_div_epi8((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_div_epi16 (simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_div_epi16(a, b);
  #else
    simde__m512i_private
      r_,
      a_ = simde__m512i_to_private(a),
      b_ = simde__m512i_to_private(b);

    #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r_.i16 = a_.i16 / b_.i16;
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.i16) / sizeof(r_.i16[0])) ; i++) {
        r_.i16[i] = a_.i16[i] / b_.i16[i];
      }
    #endif

    return simde__m512i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm512_div_epi16
  #define _mm512_div_epi16(a, b) simde_mm512_div_epi16((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_div_epi32 (simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_div_epi32(a, b);
  #else
    simde__m512i_private
      r_,
      a_ = simde__m512i_to_private(a),
      b_ = simde__m512i_to_private(b);

    #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r_.i32 = a_.i32 / b_.i32;
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.i32) / sizeof(r_.i32[0])) ; i++) {
        r_.i32[i] = a_.i32[i] / b_.i32[i];
      }
    #endif

    return simde__m512i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm512_div_epi32
  #define _mm512_div_epi32(a, b) simde_mm512_div_epi32((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_mask_div_epi32(simde__m512i src, simde__mmask16 k, simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_mask_div_epi32(src, k, a, b);
  #else
    return simde_mm512_mask_mov_epi32(src, k, simde_mm512_div_epi32(a, b));
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_div_epi32
  #define _mm512_mask_div_epi32(src, k, a, b) simde_mm512_mask_div_epi32(src, k, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_div_epi64 (simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_div_epi64(a, b);
  #else
    simde__m512i_private
      r_,
      a_ = simde__m512i_to_private(a),
      b_ = simde__m512i_to_private(b);

    #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r_.i64 = a_.i64 / b_.i64;
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.i64) / sizeof(r_.i64[0])) ; i++) {
        r_.i64[i] = a_.i64[i] / b_.i64[i];
      }
    #endif

    return simde__m512i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm512_div_epi64
  #define _mm512_div_epi64(a, b) simde_mm512_div_epi64((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_div_epu8 (simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_div_epu8(a, b);
  #else
    simde__m512i_private
      r_,
      a_ = simde__m512i_to_private(a),
      b_ = simde__m512i_to_private(b);

    #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r_.u8 = a_.u8 / b_.u8;
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.u8) / sizeof(r_.u8[0])) ; i++) {
        r_.u8[i] = a_.u8[i] / b_.u8[i];
      }
    #endif

    return simde__m512i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm512_div_epu8
  #define _mm512_div_epu8(a, b) simde_mm512_div_epu8((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_div_epu16 (simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_div_epu16(a, b);
  #else
    simde__m512i_private
      r_,
      a_ = simde__m512i_to_private(a),
      b_ = simde__m512i_to_private(b);

    #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r_.u16 = a_.u16 / b_.u16;
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.u16) / sizeof(r_.u16[0])) ; i++) {
        r_.u16[i] = a_.u16[i] / b_.u16[i];
      }
    #endif

    return simde__m512i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm512_div_epu16
  #define _mm512_div_epu16(a, b) simde_mm512_div_epu16((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_div_epu32 (simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_div_epu32(a, b);
  #else
    simde__m512i_private
      r_,
      a_ = simde__m512i_to_private(a),
      b_ = simde__m512i_to_private(b);

    #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r_.u32 = a_.u32 / b_.u32;
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.u32) / sizeof(r_.u32[0])) ; i++) {
        r_.u32[i] = a_.u32[i] / b_.u32[i];
      }
    #endif

    return simde__m512i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm512_div_epu32
  #define _mm512_div_epu32(a, b) simde_mm512_div_epu32((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_mask_div_epu32(simde__m512i src, simde__mmask16 k, simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_mask_div_epu32(src, k, a, b);
  #else
    return simde_mm512_mask_mov_epi32(src, k, simde_mm512_div_epu32(a, b));
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_div_epu32
  #define _mm512_mask_div_epu32(src, k, a, b) simde_mm512_mask_div_epu32(src, k, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_div_epu64 (simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_div_epu64(a, b);
  #else
    simde__m512i_private
      r_,
      a_ = simde__m512i_to_private(a),
      b_ = simde__m512i_to_private(b);

    #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r_.u64 = a_.u64 / b_.u64;
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.u64) / sizeof(r_.u64[0])) ; i++) {
        r_.u64[i] = a_.u64[i] / b_.u64[i];
      }
    #endif

    return simde__m512i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm512_div_epu64
  #define _mm512_div_epu64(a, b) simde_mm512_div_epu64((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128
simde_mm_erf_ps (simde__m128 a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_SSE_NATIVE)
    return _mm_erf_ps(a);
  #else
    simde__m128_private
      r_,
      a_ = simde__m128_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f32) / sizeof(r_.f32[0])) ; i++) {
      r_.f32[i] =  simde_math_erff(a_.f32[i]);
    }

    return simde__m128_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm_erf_ps
  #define _mm_erf_ps(a) simde_mm_erf_ps(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128d
simde_mm_erf_pd (simde__m128d a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_SSE_NATIVE)
    return _mm_erf_pd(a);
  #else
    simde__m128d_private
      r_,
      a_ = simde__m128d_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f64) / sizeof(r_.f64[0])) ; i++) {
      r_.f64[i] =  simde_math_erf(a_.f64[i]);
    }

    return simde__m128d_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm_erf_pd
  #define _mm_erf_pd(a) simde_mm_erf_pd(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256
simde_mm256_erf_ps (simde__m256 a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX_NATIVE)
    return _mm256_erf_ps(a);
  #else
    simde__m256_private
      r_,
      a_ = simde__m256_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f32) / sizeof(r_.f32[0])) ; i++) {
      r_.f32[i] =  simde_math_erff(a_.f32[i]);
    }

    return simde__m256_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm256_erf_ps
  #define _mm256_erf_ps(a) simde_mm256_erf_ps(a)
#endif


SIMDE_FUNCTION_ATTRIBUTES
simde__m256d
simde_mm256_erf_pd (simde__m256d a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX_NATIVE)
    return _mm256_erf_pd(a);
  #else
    simde__m256d_private
      r_,
      a_ = simde__m256d_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f64) / sizeof(r_.f64[0])) ; i++) {
      r_.f64[i] =  simde_math_erf(a_.f64[i]);
    }

    return simde__m256d_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm256_erf_pd
  #define _mm256_erf_pd(a) simde_mm256_erf_pd(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512
simde_mm512_erf_ps (simde__m512 a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_erf_ps(a);
  #else
    simde__m512_private
      r_,
      a_ = simde__m512_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f32) / sizeof(r_.f32[0])) ; i++) {
      r_.f32[i] =  simde_math_erff(a_.f32[i]);
    }

    return simde__m512_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm512_erf_ps
  #define _mm512_erf_ps(a) simde_mm512_erf_ps(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512d
simde_mm512_erf_pd (simde__m512d a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_erf_pd(a);
  #else
    simde__m512d_private
      r_,
      a_ = simde__m512d_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f64) / sizeof(r_.f64[0])) ; i++) {
      r_.f64[i] =  simde_math_erf(a_.f64[i]);
    }

    return simde__m512d_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm512_erf_pd
  #define _mm512_erf_pd(a) simde_mm512_erf_pd(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512
simde_mm512_mask_erf_ps(simde__m512 src, simde__mmask16 k, simde__m512 a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_mask_erf_ps(src, k, a);
  #else
    return simde_mm512_mask_mov_ps(src, k, simde_mm512_erf_ps(a));
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_erf_ps
  #define _mm512_mask_erf_ps(src, k, a) simde_mm512_mask_erf_ps(src, k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512d
simde_mm512_mask_erf_pd(simde__m512d src, simde__mmask8 k, simde__m512d a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_mask_erf_pd(src, k, a);
  #else
    return simde_mm512_mask_mov_pd(src, k, simde_mm512_erf_pd(a));
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_erf_pd
  #define _mm512_mask_erf_pd(src, k, a) simde_mm512_mask_erf_pd(src, k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128
simde_mm_erfc_ps (simde__m128 a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_SSE_NATIVE)
    return _mm_erfc_ps(a);
  #else
    simde__m128_private
      r_,
      a_ = simde__m128_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f32) / sizeof(r_.f32[0])) ; i++) {
      r_.f32[i] =  simde_math_erfcf(a_.f32[i]);
    }

    return simde__m128_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm_erfc_ps
  #define _mm_erfc_ps(a) simde_mm_erfc_ps(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128d
simde_mm_erfc_pd (simde__m128d a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_SSE_NATIVE)
    return _mm_erfc_pd(a);
  #else
    simde__m128d_private
      r_,
      a_ = simde__m128d_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f64) / sizeof(r_.f64[0])) ; i++) {
      r_.f64[i] =  simde_math_erfc(a_.f64[i]);
    }

    return simde__m128d_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm_erfc_pd
  #define _mm_erfc_pd(a) simde_mm_erfc_pd(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256
simde_mm256_erfc_ps (simde__m256 a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX_NATIVE)
    return _mm256_erfc_ps(a);
  #else
    simde__m256_private
      r_,
      a_ = simde__m256_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f32) / sizeof(r_.f32[0])) ; i++) {
      r_.f32[i] =  simde_math_erfcf(a_.f32[i]);
    }

    return simde__m256_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm256_erfc_ps
  #define _mm256_erfc_ps(a) simde_mm256_erfc_ps(a)
#endif


SIMDE_FUNCTION_ATTRIBUTES
simde__m256d
simde_mm256_erfc_pd (simde__m256d a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX_NATIVE)
    return _mm256_erfc_pd(a);
  #else
    simde__m256d_private
      r_,
      a_ = simde__m256d_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f64) / sizeof(r_.f64[0])) ; i++) {
      r_.f64[i] =  simde_math_erfc(a_.f64[i]);
    }

    return simde__m256d_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm256_erfc_pd
  #define _mm256_erfc_pd(a) simde_mm256_erfc_pd(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512
simde_mm512_erfc_ps (simde__m512 a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_erfc_ps(a);
  #else
    simde__m512_private
      r_,
      a_ = simde__m512_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f32) / sizeof(r_.f32[0])) ; i++) {
      r_.f32[i] =  simde_math_erfcf(a_.f32[i]);
    }

    return simde__m512_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm512_erfc_ps
  #define _mm512_erfc_ps(a) simde_mm512_erfc_ps(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512d
simde_mm512_erfc_pd (simde__m512d a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_erfc_pd(a);
  #else
    simde__m512d_private
      r_,
      a_ = simde__m512d_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f64) / sizeof(r_.f64[0])) ; i++) {
      r_.f64[i] =  simde_math_erfc(a_.f64[i]);
    }

    return simde__m512d_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm512_erfc_pd
  #define _mm512_erfc_pd(a) simde_mm512_erfc_pd(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512
simde_mm512_mask_erfc_ps(simde__m512 src, simde__mmask16 k, simde__m512 a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_mask_erfc_ps(src, k, a);
  #else
    return simde_mm512_mask_mov_ps(src, k, simde_mm512_erfc_ps(a));
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_erfc_ps
  #define _mm512_mask_erfc_ps(src, k, a) simde_mm512_mask_erfc_ps(src, k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512d
simde_mm512_mask_erfc_pd(simde__m512d src, simde__mmask8 k, simde__m512d a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_mask_erfc_pd(src, k, a);
  #else
    return simde_mm512_mask_mov_pd(src, k, simde_mm512_erfc_pd(a));
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_erfc_pd
  #define _mm512_mask_erfc_pd(src, k, a) simde_mm512_mask_erfc_pd(src, k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128
simde_mm_exp_ps (simde__m128 a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_SSE_NATIVE)
    return _mm_exp_ps(a);
  #else
    simde__m128_private
      r_,
      a_ = simde__m128_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f32) / sizeof(r_.f32[0])) ; i++) {
      r_.f32[i] =  simde_math_expf(a_.f32[i]);
    }

    return simde__m128_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm_exp_ps
  #define _mm_exp_ps(a) simde_mm_exp_ps(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128d
simde_mm_exp_pd (simde__m128d a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_SSE_NATIVE)
    return _mm_exp_pd(a);
  #else
    simde__m128d_private
      r_,
      a_ = simde__m128d_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f64) / sizeof(r_.f64[0])) ; i++) {
      r_.f64[i] =  simde_math_exp(a_.f64[i]);
    }

    return simde__m128d_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm_exp_pd
  #define _mm_exp_pd(a) simde_mm_exp_pd(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256
simde_mm256_exp_ps (simde__m256 a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX_NATIVE)
    return _mm256_exp_ps(a);
  #else
    simde__m256_private
      r_,
      a_ = simde__m256_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f32) / sizeof(r_.f32[0])) ; i++) {
      r_.f32[i] =  simde_math_expf(a_.f32[i]);
    }

    return simde__m256_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm256_exp_ps
  #define _mm256_exp_ps(a) simde_mm256_exp_ps(a)
#endif


SIMDE_FUNCTION_ATTRIBUTES
simde__m256d
simde_mm256_exp_pd (simde__m256d a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX_NATIVE)
    return _mm256_exp_pd(a);
  #else
    simde__m256d_private
      r_,
      a_ = simde__m256d_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f64) / sizeof(r_.f64[0])) ; i++) {
      r_.f64[i] =  simde_math_exp(a_.f64[i]);
    }

    return simde__m256d_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm256_exp_pd
  #define _mm256_exp_pd(a) simde_mm256_exp_pd(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512
simde_mm512_exp_ps (simde__m512 a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_exp_ps(a);
  #else
    simde__m512_private
      r_,
      a_ = simde__m512_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f32) / sizeof(r_.f32[0])) ; i++) {
      r_.f32[i] =  simde_math_expf(a_.f32[i]);
    }

    return simde__m512_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm512_exp_ps
  #define _mm512_exp_ps(a) simde_mm512_exp_ps(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512d
simde_mm512_exp_pd (simde__m512d a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_exp_pd(a);
  #else
    simde__m512d_private
      r_,
      a_ = simde__m512d_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f64) / sizeof(r_.f64[0])) ; i++) {
      r_.f64[i] =  simde_math_exp(a_.f64[i]);
    }

    return simde__m512d_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm512_exp_pd
  #define _mm512_exp_pd(a) simde_mm512_exp_pd(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512
simde_mm512_mask_exp_ps(simde__m512 src, simde__mmask16 k, simde__m512 a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_mask_exp_ps(src, k, a);
  #else
    return simde_mm512_mask_mov_ps(src, k, simde_mm512_exp_ps(a));
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_exp_ps
  #define _mm512_mask_exp_ps(src, k, a) simde_mm512_mask_exp_ps(src, k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512d
simde_mm512_mask_exp_pd(simde__m512d src, simde__mmask8 k, simde__m512d a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_mask_exp_pd(src, k, a);
  #else
    return simde_mm512_mask_mov_pd(src, k, simde_mm512_exp_pd(a));
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_exp_pd
  #define _mm512_mask_exp_pd(src, k, a) simde_mm512_mask_exp_pd(src, k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128
simde_mm_expm1_ps (simde__m128 a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_SSE_NATIVE)
    return _mm_expm1_ps(a);
  #else
    simde__m128_private
      r_,
      a_ = simde__m128_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f32) / sizeof(r_.f32[0])) ; i++) {
      r_.f32[i] =  simde_math_expm1f(a_.f32[i]);
    }

    return simde__m128_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm_expm1_ps
  #define _mm_expm1_ps(a) simde_mm_expm1_ps(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128d
simde_mm_expm1_pd (simde__m128d a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_SSE_NATIVE)
    return _mm_expm1_pd(a);
  #else
    simde__m128d_private
      r_,
      a_ = simde__m128d_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f64) / sizeof(r_.f64[0])) ; i++) {
      r_.f64[i] =  simde_math_expm1(a_.f64[i]);
    }

    return simde__m128d_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm_expm1_pd
  #define _mm_expm1_pd(a) simde_mm_expm1_pd(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256
simde_mm256_expm1_ps (simde__m256 a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX_NATIVE)
    return _mm256_expm1_ps(a);
  #else
    simde__m256_private
      r_,
      a_ = simde__m256_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f32) / sizeof(r_.f32[0])) ; i++) {
      r_.f32[i] =  simde_math_expm1f(a_.f32[i]);
    }

    return simde__m256_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm256_expm1_ps
  #define _mm256_expm1_ps(a) simde_mm256_expm1_ps(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256d
simde_mm256_expm1_pd (simde__m256d a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX_NATIVE)
    return _mm256_expm1_pd(a);
  #else
    simde__m256d_private
      r_,
      a_ = simde__m256d_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f64) / sizeof(r_.f64[0])) ; i++) {
      r_.f64[i] =  simde_math_expm1(a_.f64[i]);
    }

    return simde__m256d_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm256_expm1_pd
  #define _mm256_expm1_pd(a) simde_mm256_expm1_pd(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512
simde_mm512_expm1_ps (simde__m512 a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_expm1_ps(a);
  #else
    simde__m512_private
      r_,
      a_ = simde__m512_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f32) / sizeof(r_.f32[0])) ; i++) {
      r_.f32[i] =  simde_math_expm1f(a_.f32[i]);
    }

    return simde__m512_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm512_expm1_ps
  #define _mm512_expm1_ps(a) simde_mm512_expm1_ps(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512d
simde_mm512_expm1_pd (simde__m512d a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_expm1_pd(a);
  #else
    simde__m512d_private
      r_,
      a_ = simde__m512d_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f64) / sizeof(r_.f64[0])) ; i++) {
      r_.f64[i] =  simde_math_expm1(a_.f64[i]);
    }

    return simde__m512d_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm512_expm1_pd
  #define _mm512_expm1_pd(a) simde_mm512_expm1_pd(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512
simde_mm512_mask_expm1_ps(simde__m512 src, simde__mmask16 k, simde__m512 a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_mask_expm1_ps(src, k, a);
  #else
    return simde_mm512_mask_mov_ps(src, k, simde_mm512_expm1_ps(a));
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_expm1_ps
  #define _mm512_mask_expm1_ps(src, k, a) simde_mm512_mask_expm1_ps(src, k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512d
simde_mm512_mask_expm1_pd(simde__m512d src, simde__mmask8 k, simde__m512d a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_mask_expm1_pd(src, k, a);
  #else
    return simde_mm512_mask_mov_pd(src, k, simde_mm512_expm1_pd(a));
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_expm1_pd
  #define _mm512_mask_expm1_pd(src, k, a) simde_mm512_mask_expm1_pd(src, k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128
simde_mm_exp2_ps (simde__m128 a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_SSE_NATIVE)
    return _mm_exp2_ps(a);
  #else
    simde__m128_private
      r_,
      a_ = simde__m128_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f32) / sizeof(r_.f32[0])) ; i++) {
      r_.f32[i] =  simde_math_exp2f(a_.f32[i]);
    }

    return simde__m128_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm_exp2_ps
  #define _mm_exp2_ps(a) simde_mm_exp2_ps(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128d
simde_mm_exp2_pd (simde__m128d a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_SSE_NATIVE)
    return _mm_exp2_pd(a);
  #else
    simde__m128d_private
      r_,
      a_ = simde__m128d_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f64) / sizeof(r_.f64[0])) ; i++) {
      r_.f64[i] =  simde_math_exp2(a_.f64[i]);
    }

    return simde__m128d_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm_exp2_pd
  #define _mm_exp2_pd(a) simde_mm_exp2_pd(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256
simde_mm256_exp2_ps (simde__m256 a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX_NATIVE)
    return _mm256_exp2_ps(a);
  #else
    simde__m256_private
      r_,
      a_ = simde__m256_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f32) / sizeof(r_.f32[0])) ; i++) {
      r_.f32[i] =  simde_math_exp2f(a_.f32[i]);
    }

    return simde__m256_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm256_exp2_ps
  #define _mm256_exp2_ps(a) simde_mm256_exp2_ps(a)
#endif


SIMDE_FUNCTION_ATTRIBUTES
simde__m256d
simde_mm256_exp2_pd (simde__m256d a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX_NATIVE)
    return _mm256_exp2_pd(a);
  #else
    simde__m256d_private
      r_,
      a_ = simde__m256d_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f64) / sizeof(r_.f64[0])) ; i++) {
      r_.f64[i] =  simde_math_exp2(a_.f64[i]);
    }

    return simde__m256d_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm256_exp2_pd
  #define _mm256_exp2_pd(a) simde_mm256_exp2_pd(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512
simde_mm512_exp2_ps (simde__m512 a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_exp2_ps(a);
  #else
    simde__m512_private
      r_,
      a_ = simde__m512_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f32) / sizeof(r_.f32[0])) ; i++) {
      r_.f32[i] =  simde_math_exp2f(a_.f32[i]);
    }

    return simde__m512_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm512_exp2_ps
  #define _mm512_exp2_ps(a) simde_mm512_exp2_ps(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512d
simde_mm512_exp2_pd (simde__m512d a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_exp2_pd(a);
  #else
    simde__m512d_private
      r_,
      a_ = simde__m512d_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f64) / sizeof(r_.f64[0])) ; i++) {
      r_.f64[i] =  simde_math_exp2(a_.f64[i]);
    }

    return simde__m512d_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm512_exp2_pd
  #define _mm512_exp2_pd(a) simde_mm512_exp2_pd(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512
simde_mm512_mask_exp2_ps(simde__m512 src, simde__mmask16 k, simde__m512 a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_mask_exp2_ps(src, k, a);
  #else
    return simde_mm512_mask_mov_ps(src, k, simde_mm512_exp2_ps(a));
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_exp2_ps
  #define _mm512_mask_exp2_ps(src, k, a) simde_mm512_mask_exp2_ps(src, k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512d
simde_mm512_mask_exp2_pd(simde__m512d src, simde__mmask8 k, simde__m512d a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_mask_exp2_pd(src, k, a);
  #else
    return simde_mm512_mask_mov_pd(src, k, simde_mm512_exp2_pd(a));
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_exp2_pd
  #define _mm512_mask_exp2_pd(src, k, a) simde_mm512_mask_exp2_pd(src, k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128
simde_mm_exp10_ps (simde__m128 a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_SSE_NATIVE)
    return _mm_exp10_ps(a);
  #else
    simde__m128_private
      r_,
      a_ = simde__m128_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f32) / sizeof(r_.f32[0])) ; i++) {
      r_.f32[i] =  simde_math_exp10f(a_.f32[i]);
    }

    return simde__m128_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm_exp10_ps
  #define _mm_exp10_ps(a) simde_mm_exp10_ps(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128d
simde_mm_exp10_pd (simde__m128d a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_SSE_NATIVE)
    return _mm_exp10_pd(a);
  #else
    simde__m128d_private
      r_,
      a_ = simde__m128d_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f64) / sizeof(r_.f64[0])) ; i++) {
      r_.f64[i] =  simde_math_exp10(a_.f64[i]);
    }

    return simde__m128d_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm_exp10_pd
  #define _mm_exp10_pd(a) simde_mm_exp10_pd(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256
simde_mm256_exp10_ps (simde__m256 a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX_NATIVE)
    return _mm256_exp10_ps(a);
  #else
    simde__m256_private
      r_,
      a_ = simde__m256_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f32) / sizeof(r_.f32[0])) ; i++) {
      r_.f32[i] =  simde_math_exp10f(a_.f32[i]);
    }

    return simde__m256_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm256_exp10_ps
  #define _mm256_exp10_ps(a) simde_mm256_exp10_ps(a)
#endif


SIMDE_FUNCTION_ATTRIBUTES
simde__m256d
simde_mm256_exp10_pd (simde__m256d a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX_NATIVE)
    return _mm256_exp10_pd(a);
  #else
    simde__m256d_private
      r_,
      a_ = simde__m256d_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f64) / sizeof(r_.f64[0])) ; i++) {
      r_.f64[i] =  simde_math_exp10(a_.f64[i]);
    }

    return simde__m256d_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm256_exp10_pd
  #define _mm256_exp10_pd(a) simde_mm256_exp10_pd(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512
simde_mm512_exp10_ps (simde__m512 a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_exp10_ps(a);
  #else
    simde__m512_private
      r_,
      a_ = simde__m512_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f32) / sizeof(r_.f32[0])) ; i++) {
      r_.f32[i] =  simde_math_exp10f(a_.f32[i]);
    }

    return simde__m512_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm512_exp10_ps
  #define _mm512_exp10_ps(a) simde_mm512_exp10_ps(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512d
simde_mm512_exp10_pd (simde__m512d a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_exp10_pd(a);
  #else
    simde__m512d_private
      r_,
      a_ = simde__m512d_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f64) / sizeof(r_.f64[0])) ; i++) {
      r_.f64[i] =  simde_math_exp10(a_.f64[i]);
    }

    return simde__m512d_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm512_exp10_pd
  #define _mm512_exp10_pd(a) simde_mm512_exp10_pd(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512
simde_mm512_mask_exp10_ps(simde__m512 src, simde__mmask16 k, simde__m512 a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_mask_exp10_ps(src, k, a);
  #else
    return simde_mm512_mask_mov_ps(src, k, simde_mm512_exp10_ps(a));
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_exp10_ps
  #define _mm512_mask_exp10_ps(src, k, a) simde_mm512_mask_exp10_ps(src, k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512d
simde_mm512_mask_exp10_pd(simde__m512d src, simde__mmask8 k, simde__m512d a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_mask_exp10_pd(src, k, a);
  #else
    return simde_mm512_mask_mov_pd(src, k, simde_mm512_exp10_pd(a));
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_exp10_pd
  #define _mm512_mask_exp10_pd(src, k, a) simde_mm512_mask_exp10_pd(src, k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_idivrem_epi32 (simde__m128i* mem_addr, simde__m128i a, simde__m128i b) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_idivrem_epi32(HEDLEY_REINTERPRET_CAST(__m128i*, mem_addr), a, b);
  #else
    simde__m128i r;

    r = simde_mm_div_epi32(a, b);
    *mem_addr = simde_mm_sub_epi32(a, simde_mm_mullo_epi32(r, b));

    return r;
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm_idivrem_epi32
  #define _mm_idivrem_epi32(mem_addr, a, b) simde_mm_idivrem_epi32((mem_addr),(a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_idivrem_epi32 (simde__m256i* mem_addr, simde__m256i a, simde__m256i b) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX_NATIVE)
    return _mm256_idivrem_epi32(HEDLEY_REINTERPRET_CAST(__m256i*, mem_addr), a, b);
  #else
    simde__m256i r;

    r = simde_mm256_div_epi32(a, b);
    *mem_addr = simde_mm256_sub_epi32(a, simde_mm256_mullo_epi32(r, b));

    return r;
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm256_idivrem_epi32
  #define _mm256_idivrem_epi32(mem_addr, a, b) simde_mm256_idivrem_epi32((mem_addr),(a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128
simde_mm_hypot_ps (simde__m128 a, simde__m128 b) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_SSE_NATIVE)
    return _mm_hypot_ps(a, b);
  #else
    simde__m128_private
      r_,
      a_ = simde__m128_to_private(a),
      b_ = simde__m128_to_private(b);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f32) / sizeof(r_.f32[0])) ; i++) {
      r_.f32[i] =  simde_math_hypotf(a_.f32[i], b_.f32[i]);
    }

    return simde__m128_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm_hypot_ps
  #define _mm_hypot_ps(a, b) simde_mm_hypot_ps(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128d
simde_mm_hypot_pd (simde__m128d a, simde__m128d b) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_SSE_NATIVE)
    return _mm_hypot_pd(a, b);
  #else
    simde__m128d_private
      r_,
      a_ = simde__m128d_to_private(a),
      b_ = simde__m128d_to_private(b);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f64) / sizeof(r_.f64[0])) ; i++) {
      r_.f64[i] =  simde_math_hypot(a_.f64[i], b_.f64[i]);
    }

    return simde__m128d_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm_hypot_pd
  #define _mm_hypot_pd(a, b) simde_mm_hypot_pd(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256
simde_mm256_hypot_ps (simde__m256 a, simde__m256 b) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX_NATIVE)
    return _mm256_hypot_ps(a, b);
  #else
    simde__m256_private
      r_,
      a_ = simde__m256_to_private(a),
      b_ = simde__m256_to_private(b);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f32) / sizeof(r_.f32[0])) ; i++) {
      r_.f32[i] =  simde_math_hypotf(a_.f32[i], b_.f32[i]);
    }

    return simde__m256_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm256_hypot_ps
  #define _mm256_hypot_ps(a, b) simde_mm256_hypot_ps(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256d
simde_mm256_hypot_pd (simde__m256d a, simde__m256d b) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX_NATIVE)
    return _mm256_hypot_pd(a, b);
  #else
    simde__m256d_private
      r_,
      a_ = simde__m256d_to_private(a),
      b_ = simde__m256d_to_private(b);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f64) / sizeof(r_.f64[0])) ; i++) {
      r_.f64[i] =  simde_math_hypot(a_.f64[i], b_.f64[i]);
    }

    return simde__m256d_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm256_hypot_pd
  #define _mm256_hypot_pd(a, b) simde_mm256_hypot_pd(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512
simde_mm512_hypot_ps (simde__m512 a, simde__m512 b) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_hypot_ps(a, b);
  #else
    simde__m512_private
      r_,
      a_ = simde__m512_to_private(a),
      b_ = simde__m512_to_private(b);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f32) / sizeof(r_.f32[0])) ; i++) {
      r_.f32[i] =  simde_math_hypotf(a_.f32[i], b_.f32[i]);
    }

    return simde__m512_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm512_hypot_ps
  #define _mm512_hypot_ps(a, b) simde_mm512_hypot_ps(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512d
simde_mm512_hypot_pd (simde__m512d a, simde__m512d b) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_hypot_pd(a, b);
  #else
    simde__m512d_private
      r_,
      a_ = simde__m512d_to_private(a),
      b_ = simde__m512d_to_private(b);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f64) / sizeof(r_.f64[0])) ; i++) {
      r_.f64[i] =  simde_math_hypot(a_.f64[i], b_.f64[i]);
    }

    return simde__m512d_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm512_hypot_pd
  #define _mm512_hypot_pd(a, b) simde_mm512_hypot_pd(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512
simde_mm512_mask_hypot_ps(simde__m512 src, simde__mmask16 k, simde__m512 a, simde__m512 b) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_mask_hypot_ps(src, k, a, b);
  #else
    return simde_mm512_mask_mov_ps(src, k, simde_mm512_hypot_ps(a, b));
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_hypot_ps
  #define _mm512_mask_hypot_ps(src, k, a, b) simde_mm512_mask_hypot_ps(src, k, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512d
simde_mm512_mask_hypot_pd(simde__m512d src, simde__mmask8 k, simde__m512d a, simde__m512d b) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_mask_hypot_pd(src, k, a, b);
  #else
    return simde_mm512_mask_mov_pd(src, k, simde_mm512_hypot_pd(a, b));
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_hypot_pd
  #define _mm512_mask_hypot_pd(src, k, a, b) simde_mm512_mask_hypot_pd(src, k, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128
simde_mm_invcbrt_ps (simde__m128 a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_SSE_NATIVE)
    return _mm_invcbrt_ps(a);
  #else
    return simde_mm_rcp_ps(simde_mm_cbrt_ps(a));
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm_invcbrt_ps
  #define _mm_invcbrt_ps(a) simde_mm_invcbrt_ps(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128d
simde_mm_invcbrt_pd (simde__m128d a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_SSE_NATIVE)
    return _mm_invcbrt_pd(a);
  #else
    return simde_mm_div_pd(simde_mm_set1_pd(SIMDE_FLOAT64_C(1.0)), simde_mm_cbrt_pd(a));
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm_invcbrt_pd
  #define _mm_invcbrt_pd(a) simde_mm_invcbrt_pd(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256
simde_mm256_invcbrt_ps (simde__m256 a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_SSE_NATIVE)
    return _mm256_invcbrt_ps(a);
  #else
    return simde_mm256_rcp_ps(simde_mm256_cbrt_ps(a));
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm256_invcbrt_ps
  #define _mm256_invcbrt_ps(a) simde_mm256_invcbrt_ps(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256d
simde_mm256_invcbrt_pd (simde__m256d a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_SSE_NATIVE)
    return _mm256_invcbrt_pd(a);
  #else
    return simde_mm256_div_pd(simde_mm256_set1_pd(SIMDE_FLOAT64_C(1.0)), simde_mm256_cbrt_pd(a));
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm256_invcbrt_pd
  #define _mm256_invcbrt_pd(a) simde_mm256_invcbrt_pd(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128
simde_mm_invsqrt_ps (simde__m128 a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_SSE_NATIVE)
    return _mm_invsqrt_ps(a);
  #else
    return simde_mm_rcp_ps(simde_mm_sqrt_ps(a));
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm_invsqrt_ps
  #define _mm_invsqrt_ps(a) simde_mm_invsqrt_ps(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128d
simde_mm_invsqrt_pd (simde__m128d a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_SSE_NATIVE)
    return _mm_invsqrt_pd(a);
  #else
    return simde_mm_div_pd(simde_mm_set1_pd(SIMDE_FLOAT64_C(1.0)), simde_mm_sqrt_pd(a));
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm_invsqrt_pd
  #define _mm_invsqrt_pd(a) simde_mm_invsqrt_pd(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256
simde_mm256_invsqrt_ps (simde__m256 a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_SSE_NATIVE)
    return _mm256_invsqrt_ps(a);
  #else
    return simde_mm256_rcp_ps(simde_mm256_sqrt_ps(a));
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm256_invsqrt_ps
  #define _mm256_invsqrt_ps(a) simde_mm256_invsqrt_ps(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256d
simde_mm256_invsqrt_pd (simde__m256d a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_SSE_NATIVE)
    return _mm256_invsqrt_pd(a);
  #else
    return simde_mm256_div_pd(simde_mm256_set1_pd(SIMDE_FLOAT64_C(1.0)), simde_mm256_sqrt_pd(a));
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm256_invsqrt_pd
  #define _mm256_invsqrt_pd(a) simde_mm256_invsqrt_pd(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512
simde_mm512_invsqrt_ps (simde__m512 a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_invsqrt_ps(a);
  #else
    return simde_mm512_div_ps(simde_mm512_set1_ps(SIMDE_FLOAT32_C(1.0)), simde_mm512_sqrt_ps(a));
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm512_invsqrt_ps
  #define _mm512_invsqrt_ps(a) simde_mm512_invsqrt_ps(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512d
simde_mm512_invsqrt_pd (simde__m512d a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_invsqrt_pd(a);
  #else
    return simde_mm512_div_pd(simde_mm512_set1_pd(SIMDE_FLOAT64_C(1.0)), simde_mm512_sqrt_pd(a));
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm512_invsqrt_pd
  #define _mm512_invsqrt_pd(a) simde_mm512_invsqrt_pd(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512
simde_mm512_mask_invsqrt_ps(simde__m512 src, simde__mmask16 k, simde__m512 a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_mask_invsqrt_ps(src, k, a);
  #else
    return simde_mm512_mask_mov_ps(src, k, simde_mm512_invsqrt_ps(a));
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_invsqrt_ps
  #define _mm512_mask_invsqrt_ps(src, k, a) simde_mm512_mask_invsqrt_ps(src, k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512d
simde_mm512_mask_invsqrt_pd(simde__m512d src, simde__mmask8 k, simde__m512d a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_mask_invsqrt_pd(src, k, a);
  #else
    return simde_mm512_mask_mov_pd(src, k, simde_mm512_invsqrt_pd(a));
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_invsqrt_pd
  #define _mm512_mask_invsqrt_pd(src, k, a) simde_mm512_mask_invsqrt_pd(src, k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128
simde_mm_log_ps (simde__m128 a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_SSE_NATIVE)
    return _mm_log_ps(a);
  #else
    simde__m128_private
      r_,
      a_ = simde__m128_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f32) / sizeof(r_.f32[0])) ; i++) {
      r_.f32[i] =  simde_math_logf(a_.f32[i]);
    }

    return simde__m128_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm_log_ps
  #define _mm_log_ps(a) simde_mm_log_ps(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128d
simde_mm_log_pd (simde__m128d a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_SSE_NATIVE)
    return _mm_log_pd(a);
  #else
    simde__m128d_private
      r_,
      a_ = simde__m128d_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f64) / sizeof(r_.f64[0])) ; i++) {
      r_.f64[i] =  simde_math_log(a_.f64[i]);
    }

    return simde__m128d_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm_log_pd
  #define _mm_log_pd(a) simde_mm_log_pd(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256
simde_mm256_log_ps (simde__m256 a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX_NATIVE)
    return _mm256_log_ps(a);
  #else
    simde__m256_private
      r_,
      a_ = simde__m256_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f32) / sizeof(r_.f32[0])) ; i++) {
      r_.f32[i] =  simde_math_logf(a_.f32[i]);
    }

    return simde__m256_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm256_log_ps
  #define _mm256_log_ps(a) simde_mm256_log_ps(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256d
simde_mm256_log_pd (simde__m256d a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX_NATIVE)
    return _mm256_log_pd(a);
  #else
    simde__m256d_private
      r_,
      a_ = simde__m256d_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f64) / sizeof(r_.f64[0])) ; i++) {
      r_.f64[i] =  simde_math_log(a_.f64[i]);
    }

    return simde__m256d_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm256_log_pd
  #define _mm256_log_pd(a) simde_mm256_log_pd(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512
simde_mm512_log_ps (simde__m512 a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_log_ps(a);
  #else
    simde__m512_private
      r_,
      a_ = simde__m512_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f32) / sizeof(r_.f32[0])) ; i++) {
      r_.f32[i] =  simde_math_logf(a_.f32[i]);
    }

    return simde__m512_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm512_log_ps
  #define _mm512_log_ps(a) simde_mm512_log_ps(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512d
simde_mm512_log_pd (simde__m512d a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_log_pd(a);
  #else
    simde__m512d_private
      r_,
      a_ = simde__m512d_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f64) / sizeof(r_.f64[0])) ; i++) {
      r_.f64[i] =  simde_math_log(a_.f64[i]);
    }

    return simde__m512d_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm512_log_pd
  #define _mm512_log_pd(a) simde_mm512_log_pd(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512
simde_mm512_mask_log_ps(simde__m512 src, simde__mmask16 k, simde__m512 a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_mask_log_ps(src, k, a);
  #else
    return simde_mm512_mask_mov_ps(src, k, simde_mm512_log_ps(a));
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_log_ps
  #define _mm512_mask_log_ps(src, k, a) simde_mm512_mask_log_ps(src, k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512d
simde_mm512_mask_log_pd(simde__m512d src, simde__mmask8 k, simde__m512d a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_mask_log_pd(src, k, a);
  #else
    return simde_mm512_mask_mov_pd(src, k, simde_mm512_log_pd(a));
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_log_pd
  #define _mm512_mask_log_pd(src, k, a) simde_mm512_mask_log_pd(src, k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128
simde_mm_erfinv_ps (simde__m128 a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_SSE_NATIVE)
    return _mm_erfinv_ps(a);
  #elif defined(SIMDE_ASSUME_VECTORIZATION)
    /* https://stackoverflow.com/questions/27229371/inverse-error-function-in-c */
    simde__m128 one = simde_mm_set1_ps(SIMDE_FLOAT32_C(1.0));
    simde__m128 sgn = simde_x_mm_copysign_ps(one, a);

    a = simde_mm_mul_ps(simde_mm_sub_ps(one, a), simde_mm_add_ps(one, a));
    simde__m128 lnx = simde_mm_log_ps(a);

    simde__m128 tt1 = simde_mm_mul_ps(simde_mm_set1_ps(HEDLEY_STATIC_CAST(simde_float32, SIMDE_MATH_PI)), simde_mm_set1_ps(SIMDE_FLOAT32_C(0.147)));
    tt1 = simde_mm_div_ps(simde_mm_set1_ps(SIMDE_FLOAT32_C(2.0)), tt1);
    tt1 = simde_mm_add_ps(tt1, simde_mm_mul_ps(simde_mm_set1_ps(SIMDE_FLOAT32_C(0.5)), lnx));

    simde__m128 tt2 = simde_mm_set1_ps(SIMDE_FLOAT32_C(1.0) / SIMDE_FLOAT32_C(0.147));
    tt2 = simde_mm_mul_ps(tt2, lnx);

    simde__m128 r = simde_mm_mul_ps(tt1, tt1);
    r = simde_mm_sub_ps(r, tt2);
    r = simde_mm_sqrt_ps(r);
    r = simde_mm_add_ps(simde_x_mm_negate_ps(tt1), r);
    r = simde_mm_sqrt_ps(r);

    return simde_mm_mul_ps(sgn, r);
  #else
    simde__m128_private
      a_ = simde__m128_to_private(a),
      r_;

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f32) / sizeof(r_.f32[0])) ; i++) {
      r_.f32[i] = simde_math_erfinvf(a_.f32[i]);
    }

    return simde__m128_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm_erfinv_ps
  #define _mm_erfinv_ps(a) simde_mm_erfinv_ps(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128d
simde_mm_erfinv_pd (simde__m128d a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_SSE_NATIVE)
    return _mm_erfinv_pd(a);
  #elif defined(SIMDE_ASSUME_VECTORIZATION)
    simde__m128d one = simde_mm_set1_pd(SIMDE_FLOAT64_C(1.0));
    simde__m128d sgn = simde_x_mm_copysign_pd(one, a);

    a = simde_mm_mul_pd(simde_mm_sub_pd(one, a), simde_mm_add_pd(one, a));
    simde__m128d lnx = simde_mm_log_pd(a);

    simde__m128d tt1 = simde_mm_mul_pd(simde_mm_set1_pd(SIMDE_MATH_PI), simde_mm_set1_pd(SIMDE_FLOAT64_C(0.147)));
    tt1 = simde_mm_div_pd(simde_mm_set1_pd(SIMDE_FLOAT64_C(2.0)), tt1);
    tt1 = simde_mm_add_pd(tt1, simde_mm_mul_pd(simde_mm_set1_pd(SIMDE_FLOAT64_C(0.5)), lnx));

    simde__m128d tt2 = simde_mm_set1_pd(SIMDE_FLOAT64_C(1.0) / SIMDE_FLOAT64_C(0.147));
    tt2 = simde_mm_mul_pd(tt2, lnx);

    simde__m128d r = simde_mm_mul_pd(tt1, tt1);
    r = simde_mm_sub_pd(r, tt2);
    r = simde_mm_sqrt_pd(r);
    r = simde_mm_add_pd(simde_x_mm_negate_pd(tt1), r);
    r = simde_mm_sqrt_pd(r);

    return simde_mm_mul_pd(sgn, r);
  #else
    simde__m128d_private
      a_ = simde__m128d_to_private(a),
      r_;

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f64) / sizeof(r_.f64[0])) ; i++) {
      r_.f64[i] = simde_math_erfinv(a_.f64[i]);
    }

    return simde__m128d_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm_erfinv_pd
  #define _mm_erfinv_pd(a) simde_mm_erfinv_pd(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256
simde_mm256_erfinv_ps (simde__m256 a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX_NATIVE)
    return _mm256_erfinv_ps(a);
  #elif defined(SIMDE_ASSUME_VECTORIZATION)
    simde__m256 one = simde_mm256_set1_ps(SIMDE_FLOAT32_C(1.0));
    simde__m256 sgn = simde_x_mm256_copysign_ps(one, a);

    a = simde_mm256_mul_ps(simde_mm256_sub_ps(one, a), simde_mm256_add_ps(one, a));
    simde__m256 lnx = simde_mm256_log_ps(a);

    simde__m256 tt1 = simde_mm256_mul_ps(simde_mm256_set1_ps(HEDLEY_STATIC_CAST(simde_float32, SIMDE_MATH_PI)), simde_mm256_set1_ps(SIMDE_FLOAT32_C(0.147)));
    tt1 = simde_mm256_div_ps(simde_mm256_set1_ps(SIMDE_FLOAT32_C(2.0)), tt1);
    tt1 = simde_mm256_add_ps(tt1, simde_mm256_mul_ps(simde_mm256_set1_ps(SIMDE_FLOAT32_C(0.5)), lnx));

    simde__m256 tt2 = simde_mm256_set1_ps(SIMDE_FLOAT32_C(1.0) / SIMDE_FLOAT32_C(0.147));
    tt2 = simde_mm256_mul_ps(tt2, lnx);

    simde__m256 r = simde_mm256_mul_ps(tt1, tt1);
    r = simde_mm256_sub_ps(r, tt2);
    r = simde_mm256_sqrt_ps(r);
    r = simde_mm256_add_ps(simde_x_mm256_negate_ps(tt1), r);
    r = simde_mm256_sqrt_ps(r);

    return simde_mm256_mul_ps(sgn, r);
  #else
    simde__m256_private
      a_ = simde__m256_to_private(a),
      r_;

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f32) / sizeof(r_.f32[0])) ; i++) {
      r_.f32[i] = simde_math_erfinvf(a_.f32[i]);
    }

    return simde__m256_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm256_erfinv_ps
  #define _mm256_erfinv_ps(a) simde_mm256_erfinv_ps(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256d
simde_mm256_erfinv_pd (simde__m256d a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX_NATIVE)
    return _mm256_erfinv_pd(a);
  #elif defined(SIMDE_ASSUME_VECTORIZATION)
    simde__m256d one = simde_mm256_set1_pd(SIMDE_FLOAT64_C(1.0));
    simde__m256d sgn = simde_x_mm256_copysign_pd(one, a);

    a = simde_mm256_mul_pd(simde_mm256_sub_pd(one, a), simde_mm256_add_pd(one, a));
    simde__m256d lnx = simde_mm256_log_pd(a);

    simde__m256d tt1 = simde_mm256_mul_pd(simde_mm256_set1_pd(SIMDE_MATH_PI), simde_mm256_set1_pd(SIMDE_FLOAT64_C(0.147)));
    tt1 = simde_mm256_div_pd(simde_mm256_set1_pd(SIMDE_FLOAT64_C(2.0)), tt1);
    tt1 = simde_mm256_add_pd(tt1, simde_mm256_mul_pd(simde_mm256_set1_pd(SIMDE_FLOAT64_C(0.5)), lnx));

    simde__m256d tt2 = simde_mm256_set1_pd(SIMDE_FLOAT64_C(1.0) / SIMDE_FLOAT64_C(0.147));
    tt2 = simde_mm256_mul_pd(tt2, lnx);

    simde__m256d r = simde_mm256_mul_pd(tt1, tt1);
    r = simde_mm256_sub_pd(r, tt2);
    r = simde_mm256_sqrt_pd(r);
    r = simde_mm256_add_pd(simde_x_mm256_negate_pd(tt1), r);
    r = simde_mm256_sqrt_pd(r);

    return simde_mm256_mul_pd(sgn, r);
  #else
    simde__m256d_private
      a_ = simde__m256d_to_private(a),
      r_;

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f64) / sizeof(r_.f64[0])) ; i++) {
      r_.f64[i] = simde_math_erfinv(a_.f64[i]);
    }

    return simde__m256d_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm256_erfinv_pd
  #define _mm256_erfinv_pd(a) simde_mm256_erfinv_pd(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128
simde_mm_logb_ps (simde__m128 a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_SSE_NATIVE)
    return _mm_logb_ps(a);
  #else
    simde__m128_private
      r_,
      a_ = simde__m128_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f32) / sizeof(r_.f32[0])) ; i++) {
      r_.f32[i] =  simde_math_logbf(a_.f32[i]);
    }

    return simde__m128_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm_logb_ps
  #define _mm_logb_ps(a) simde_mm_logb_ps(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128d
simde_mm_logb_pd (simde__m128d a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_SSE_NATIVE)
    return _mm_logb_pd(a);
  #else
    simde__m128d_private
      r_,
      a_ = simde__m128d_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f64) / sizeof(r_.f64[0])) ; i++) {
      r_.f64[i] =  simde_math_logb(a_.f64[i]);
    }

    return simde__m128d_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm_logb_pd
  #define _mm_logb_pd(a) simde_mm_logb_pd(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256
simde_mm256_logb_ps (simde__m256 a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX_NATIVE)
    return _mm256_logb_ps(a);
  #else
    simde__m256_private
      r_,
      a_ = simde__m256_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f32) / sizeof(r_.f32[0])) ; i++) {
      r_.f32[i] =  simde_math_logbf(a_.f32[i]);
    }

    return simde__m256_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm256_logb_ps
  #define _mm256_logb_ps(a) simde_mm256_logb_ps(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256d
simde_mm256_logb_pd (simde__m256d a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX_NATIVE)
    return _mm256_logb_pd(a);
  #else
    simde__m256d_private
      r_,
      a_ = simde__m256d_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f64) / sizeof(r_.f64[0])) ; i++) {
      r_.f64[i] =  simde_math_logb(a_.f64[i]);
    }

    return simde__m256d_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm256_logb_pd
  #define _mm256_logb_pd(a) simde_mm256_logb_pd(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512
simde_mm512_logb_ps (simde__m512 a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_logb_ps(a);
  #else
    simde__m512_private
      r_,
      a_ = simde__m512_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f32) / sizeof(r_.f32[0])) ; i++) {
      r_.f32[i] =  simde_math_logbf(a_.f32[i]);
    }

    return simde__m512_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm512_logb_ps
  #define _mm512_logb_ps(a) simde_mm512_logb_ps(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512d
simde_mm512_logb_pd (simde__m512d a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_logb_pd(a);
  #else
    simde__m512d_private
      r_,
      a_ = simde__m512d_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f64) / sizeof(r_.f64[0])) ; i++) {
      r_.f64[i] =  simde_math_logb(a_.f64[i]);
    }

    return simde__m512d_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm512_logb_pd
  #define _mm512_logb_pd(a) simde_mm512_logb_pd(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512
simde_mm512_mask_logb_ps(simde__m512 src, simde__mmask16 k, simde__m512 a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_mask_logb_ps(src, k, a);
  #else
    return simde_mm512_mask_mov_ps(src, k, simde_mm512_logb_ps(a));
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_logb_ps
  #define _mm512_mask_logb_ps(src, k, a) simde_mm512_mask_logb_ps(src, k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512d
simde_mm512_mask_logb_pd(simde__m512d src, simde__mmask8 k, simde__m512d a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_mask_logb_pd(src, k, a);
  #else
    return simde_mm512_mask_mov_pd(src, k, simde_mm512_logb_pd(a));
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_logb_pd
  #define _mm512_mask_logb_pd(src, k, a) simde_mm512_mask_logb_pd(src, k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128
simde_mm_log2_ps (simde__m128 a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_SSE_NATIVE)
    return _mm_log2_ps(a);
  #else
    simde__m128_private
      r_,
      a_ = simde__m128_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f32) / sizeof(r_.f32[0])) ; i++) {
      r_.f32[i] =  simde_math_log2f(a_.f32[i]);
    }

    return simde__m128_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm_log2_ps
  #define _mm_log2_ps(a) simde_mm_log2_ps(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128d
simde_mm_log2_pd (simde__m128d a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_SSE_NATIVE)
    return _mm_log2_pd(a);
  #else
    simde__m128d_private
      r_,
      a_ = simde__m128d_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f64) / sizeof(r_.f64[0])) ; i++) {
      r_.f64[i] =  simde_math_log2(a_.f64[i]);
    }

    return simde__m128d_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm_log2_pd
  #define _mm_log2_pd(a) simde_mm_log2_pd(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256
simde_mm256_log2_ps (simde__m256 a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX_NATIVE)
    return _mm256_log2_ps(a);
  #else
    simde__m256_private
      r_,
      a_ = simde__m256_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f32) / sizeof(r_.f32[0])) ; i++) {
      r_.f32[i] =  simde_math_log2f(a_.f32[i]);
    }

    return simde__m256_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm256_log2_ps
  #define _mm256_log2_ps(a) simde_mm256_log2_ps(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128
simde_mm_log1p_ps (simde__m128 a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_SSE_NATIVE)
    return _mm_log1p_ps(a);
  #else
    simde__m128_private
      r_,
      a_ = simde__m128_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f32) / sizeof(r_.f32[0])) ; i++) {
      r_.f32[i] =  simde_math_log1pf(a_.f32[i]);
    }

    return simde__m128_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm_log1p_ps
  #define _mm_log1p_ps(a) simde_mm_log1p_ps(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128d
simde_mm_log1p_pd (simde__m128d a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_SSE_NATIVE)
    return _mm_log1p_pd(a);
  #else
    simde__m128d_private
      r_,
      a_ = simde__m128d_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f64) / sizeof(r_.f64[0])) ; i++) {
      r_.f64[i] =  simde_math_log1p(a_.f64[i]);
    }

    return simde__m128d_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm_log1p_pd
  #define _mm_log1p_pd(a) simde_mm_log1p_pd(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256
simde_mm256_log1p_ps (simde__m256 a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX_NATIVE)
    return _mm256_log1p_ps(a);
  #else
    simde__m256_private
      r_,
      a_ = simde__m256_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f32) / sizeof(r_.f32[0])) ; i++) {
      r_.f32[i] =  simde_math_log1pf(a_.f32[i]);
    }

    return simde__m256_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm256_log1p_ps
  #define _mm256_log1p_ps(a) simde_mm256_log1p_ps(a)
#endif


SIMDE_FUNCTION_ATTRIBUTES
simde__m256d
simde_mm256_log1p_pd (simde__m256d a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX_NATIVE)
    return _mm256_log1p_pd(a);
  #else
    simde__m256d_private
      r_,
      a_ = simde__m256d_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f64) / sizeof(r_.f64[0])) ; i++) {
      r_.f64[i] =  simde_math_log1p(a_.f64[i]);
    }

    return simde__m256d_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm256_log1p_pd
  #define _mm256_log1p_pd(a) simde_mm256_log1p_pd(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512
simde_mm512_log1p_ps (simde__m512 a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_log1p_ps(a);
  #else
    simde__m512_private
      r_,
      a_ = simde__m512_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f32) / sizeof(r_.f32[0])) ; i++) {
      r_.f32[i] =  simde_math_log1pf(a_.f32[i]);
    }

    return simde__m512_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm512_log1p_ps
  #define _mm512_log1p_ps(a) simde_mm512_log1p_ps(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512d
simde_mm512_log1p_pd (simde__m512d a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_log1p_pd(a);
  #else
    simde__m512d_private
      r_,
      a_ = simde__m512d_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f64) / sizeof(r_.f64[0])) ; i++) {
      r_.f64[i] =  simde_math_log1p(a_.f64[i]);
    }

    return simde__m512d_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm512_log1p_pd
  #define _mm512_log1p_pd(a) simde_mm512_log1p_pd(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512
simde_mm512_mask_log1p_ps(simde__m512 src, simde__mmask16 k, simde__m512 a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_mask_log1p_ps(src, k, a);
  #else
    return simde_mm512_mask_mov_ps(src, k, simde_mm512_log1p_ps(a));
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_log1p_ps
  #define _mm512_mask_log1p_ps(src, k, a) simde_mm512_mask_log1p_ps(src, k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512d
simde_mm512_mask_log1p_pd(simde__m512d src, simde__mmask8 k, simde__m512d a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_mask_log1p_pd(src, k, a);
  #else
    return simde_mm512_mask_mov_pd(src, k, simde_mm512_log1p_pd(a));
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_log1p_pd
  #define _mm512_mask_log1p_pd(src, k, a) simde_mm512_mask_log1p_pd(src, k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256d
simde_mm256_log2_pd (simde__m256d a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX_NATIVE)
    return _mm256_log2_pd(a);
  #else
    simde__m256d_private
      r_,
      a_ = simde__m256d_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f64) / sizeof(r_.f64[0])) ; i++) {
      r_.f64[i] =  simde_math_log2(a_.f64[i]);
    }

    return simde__m256d_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm256_log2_pd
  #define _mm256_log2_pd(a) simde_mm256_log2_pd(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512
simde_mm512_log2_ps (simde__m512 a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_log2_ps(a);
  #else
    simde__m512_private
      r_,
      a_ = simde__m512_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f32) / sizeof(r_.f32[0])) ; i++) {
      r_.f32[i] =  simde_math_log2f(a_.f32[i]);
    }

    return simde__m512_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm512_log2_ps
  #define _mm512_log2_ps(a) simde_mm512_log2_ps(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512d
simde_mm512_log2_pd (simde__m512d a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_log2_pd(a);
  #else
    simde__m512d_private
      r_,
      a_ = simde__m512d_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f64) / sizeof(r_.f64[0])) ; i++) {
      r_.f64[i] =  simde_math_log2(a_.f64[i]);
    }

    return simde__m512d_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm512_log2_pd
  #define _mm512_log2_pd(a) simde_mm512_log2_pd(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512
simde_mm512_mask_log2_ps(simde__m512 src, simde__mmask16 k, simde__m512 a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_mask_log2_ps(src, k, a);
  #else
    return simde_mm512_mask_mov_ps(src, k, simde_mm512_log2_ps(a));
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_log2_ps
  #define _mm512_mask_log2_ps(src, k, a) simde_mm512_mask_log2_ps(src, k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512d
simde_mm512_mask_log2_pd(simde__m512d src, simde__mmask8 k, simde__m512d a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_mask_log2_pd(src, k, a);
  #else
    return simde_mm512_mask_mov_pd(src, k, simde_mm512_log2_pd(a));
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_log2_pd
  #define _mm512_mask_log2_pd(src, k, a) simde_mm512_mask_log2_pd(src, k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128
simde_mm_log10_ps (simde__m128 a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_SSE_NATIVE)
    return _mm_log10_ps(a);
  #else
    simde__m128_private
      r_,
      a_ = simde__m128_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f32) / sizeof(r_.f32[0])) ; i++) {
      r_.f32[i] =  simde_math_log10f(a_.f32[i]);
    }

    return simde__m128_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm_log10_ps
  #define _mm_log10_ps(a) simde_mm_log10_ps(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128d
simde_mm_log10_pd (simde__m128d a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_SSE_NATIVE)
    return _mm_log10_pd(a);
  #else
    simde__m128d_private
      r_,
      a_ = simde__m128d_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f64) / sizeof(r_.f64[0])) ; i++) {
      r_.f64[i] =  simde_math_log10(a_.f64[i]);
    }

    return simde__m128d_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm_log10_pd
  #define _mm_log10_pd(a) simde_mm_log10_pd(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256
simde_mm256_log10_ps (simde__m256 a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX_NATIVE)
    return _mm256_log10_ps(a);
  #else
    simde__m256_private
      r_,
      a_ = simde__m256_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f32) / sizeof(r_.f32[0])) ; i++) {
      r_.f32[i] =  simde_math_log10f(a_.f32[i]);
    }

    return simde__m256_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm256_log10_ps
  #define _mm256_log10_ps(a) simde_mm256_log10_ps(a)
#endif


SIMDE_FUNCTION_ATTRIBUTES
simde__m256d
simde_mm256_log10_pd (simde__m256d a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX_NATIVE)
    return _mm256_log10_pd(a);
  #else
    simde__m256d_private
      r_,
      a_ = simde__m256d_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f64) / sizeof(r_.f64[0])) ; i++) {
      r_.f64[i] =  simde_math_log10(a_.f64[i]);
    }

    return simde__m256d_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm256_log10_pd
  #define _mm256_log10_pd(a) simde_mm256_log10_pd(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512
simde_mm512_log10_ps (simde__m512 a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_log10_ps(a);
  #else
    simde__m512_private
      r_,
      a_ = simde__m512_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f32) / sizeof(r_.f32[0])) ; i++) {
      r_.f32[i] =  simde_math_log10f(a_.f32[i]);
    }

    return simde__m512_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm512_log10_ps
  #define _mm512_log10_ps(a) simde_mm512_log10_ps(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512d
simde_mm512_log10_pd (simde__m512d a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_log10_pd(a);
  #else
    simde__m512d_private
      r_,
      a_ = simde__m512d_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f64) / sizeof(r_.f64[0])) ; i++) {
      r_.f64[i] =  simde_math_log10(a_.f64[i]);
    }

    return simde__m512d_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm512_log10_pd
  #define _mm512_log10_pd(a) simde_mm512_log10_pd(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512
simde_mm512_mask_log10_ps(simde__m512 src, simde__mmask16 k, simde__m512 a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_mask_log10_ps(src, k, a);
  #else
    return simde_mm512_mask_mov_ps(src, k, simde_mm512_log10_ps(a));
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_log10_ps
  #define _mm512_mask_log10_ps(src, k, a) simde_mm512_mask_log10_ps(src, k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512d
simde_mm512_mask_log10_pd(simde__m512d src, simde__mmask8 k, simde__m512d a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_mask_log10_pd(src, k, a);
  #else
    return simde_mm512_mask_mov_pd(src, k, simde_mm512_log10_pd(a));
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_log10_pd
  #define _mm512_mask_log10_pd(src, k, a) simde_mm512_mask_log10_pd(src, k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128
simde_mm_pow_ps (simde__m128 a, simde__m128 b) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_SSE_NATIVE)
    return _mm_pow_ps(a, b);
  #else
    simde__m128_private
      r_,
      a_ = simde__m128_to_private(a),
      b_ = simde__m128_to_private(b);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f32) / sizeof(r_.f32[0])) ; i++) {
      r_.f32[i] =  simde_math_powf(a_.f32[i], b_.f32[i]);
    }

    return simde__m128_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm_pow_ps
  #define _mm_pow_ps(a, b) simde_mm_pow_ps(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128d
simde_mm_pow_pd (simde__m128d a, simde__m128d b) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_SSE_NATIVE)
    return _mm_pow_pd(a, b);
  #else
    simde__m128d_private
      r_,
      a_ = simde__m128d_to_private(a),
      b_ = simde__m128d_to_private(b);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f64) / sizeof(r_.f64[0])) ; i++) {
      r_.f64[i] =  simde_math_pow(a_.f64[i], b_.f64[i]);
    }

    return simde__m128d_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm_pow_pd
  #define _mm_pow_pd(a, b) simde_mm_pow_pd(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256
simde_mm256_pow_ps (simde__m256 a, simde__m256 b) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX_NATIVE)
    return _mm256_pow_ps(a, b);
  #else
    simde__m256_private
      r_,
      a_ = simde__m256_to_private(a),
      b_ = simde__m256_to_private(b);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f32) / sizeof(r_.f32[0])) ; i++) {
      r_.f32[i] =  simde_math_powf(a_.f32[i], b_.f32[i]);
    }

    return simde__m256_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm256_pow_ps
  #define _mm256_pow_ps(a, b) simde_mm256_pow_ps(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256d
simde_mm256_pow_pd (simde__m256d a, simde__m256d b) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX_NATIVE)
    return _mm256_pow_pd(a, b);
  #else
    simde__m256d_private
      r_,
      a_ = simde__m256d_to_private(a),
      b_ = simde__m256d_to_private(b);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f64) / sizeof(r_.f64[0])) ; i++) {
      r_.f64[i] =  simde_math_pow(a_.f64[i], b_.f64[i]);
    }

    return simde__m256d_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm256_pow_pd
  #define _mm256_pow_pd(a, b) simde_mm256_pow_pd(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512
simde_mm512_pow_ps (simde__m512 a, simde__m512 b) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_pow_ps(a, b);
  #else
    simde__m512_private
      r_,
      a_ = simde__m512_to_private(a),
      b_ = simde__m512_to_private(b);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f32) / sizeof(r_.f32[0])) ; i++) {
      r_.f32[i] =  simde_math_powf(a_.f32[i], b_.f32[i]);
    }

    return simde__m512_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm512_pow_ps
  #define _mm512_pow_ps(a, b) simde_mm512_pow_ps(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512d
simde_mm512_pow_pd (simde__m512d a, simde__m512d b) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_pow_pd(a, b);
  #else
    simde__m512d_private
      r_,
      a_ = simde__m512d_to_private(a),
      b_ = simde__m512d_to_private(b);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f64) / sizeof(r_.f64[0])) ; i++) {
      r_.f64[i] =  simde_math_pow(a_.f64[i], b_.f64[i]);
    }

    return simde__m512d_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm512_pow_pd
  #define _mm512_pow_pd(a, b) simde_mm512_pow_pd(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512
simde_mm512_mask_pow_ps(simde__m512 src, simde__mmask16 k, simde__m512 a, simde__m512 b) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_mask_pow_ps(src, k, a, b);
  #else
    return simde_mm512_mask_mov_ps(src, k, simde_mm512_pow_ps(a, b));
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_pow_ps
  #define _mm512_mask_pow_ps(src, k, a, b) simde_mm512_mask_pow_ps(src, k, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512d
simde_mm512_mask_pow_pd(simde__m512d src, simde__mmask8 k, simde__m512d a, simde__m512d b) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_mask_pow_pd(src, k, a, b);
  #else
    return simde_mm512_mask_mov_pd(src, k, simde_mm512_pow_pd(a, b));
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_pow_pd
  #define _mm512_mask_pow_pd(src, k, a, b) simde_mm512_mask_pow_pd(src, k, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_rem_epi8 (simde__m128i a, simde__m128i b) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_rem_epi8(a, b);
  #else
    simde__m128i_private
      r_,
      a_ = simde__m128i_to_private(a),
      b_ = simde__m128i_to_private(b);

    #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r_.i8 = a_.i8 % b_.i8;
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.i8) / sizeof(r_.i8[0])) ; i++) {
        r_.i8[i] = a_.i8[i] % b_.i8[i];
      }
    #endif

    return simde__m128i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm_rem_epi8
  #define _mm_rem_epi8(a, b) simde_mm_rem_epi8((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_rem_epi16 (simde__m128i a, simde__m128i b) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_rem_epi16(a, b);
  #else
    simde__m128i_private
      r_,
      a_ = simde__m128i_to_private(a),
      b_ = simde__m128i_to_private(b);

    #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r_.i16 = a_.i16 % b_.i16;
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.i16) / sizeof(r_.i16[0])) ; i++) {
        r_.i16[i] = a_.i16[i] % b_.i16[i];
      }
    #endif

    return simde__m128i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm_rem_epi16
  #define _mm_rem_epi16(a, b) simde_mm_rem_epi16((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_rem_epi32 (simde__m128i a, simde__m128i b) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_rem_epi32(a, b);
  #else
    simde__m128i_private
      r_,
      a_ = simde__m128i_to_private(a),
      b_ = simde__m128i_to_private(b);

    #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r_.i32 = a_.i32 % b_.i32;
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.i32) / sizeof(r_.i32[0])) ; i++) {
        r_.i32[i] = a_.i32[i] % b_.i32[i];
      }
    #endif

    return simde__m128i_from_private(r_);
  #endif
}
#define simde_mm_irem_epi32(a, b) simde_mm_rem_epi32(a, b)
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm_rem_epi32
  #define _mm_rem_epi32(a, b) simde_mm_rem_epi32(a, b)
  #undef _mm_irem_epi32
  #define _mm_irem_epi32(a, b) simde_mm_rem_epi32(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_rem_epi64 (simde__m128i a, simde__m128i b) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_rem_epi64(a, b);
  #else
    simde__m128i_private
      r_,
      a_ = simde__m128i_to_private(a),
      b_ = simde__m128i_to_private(b);

    #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r_.i64 = a_.i64 % b_.i64;
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.i64) / sizeof(r_.i64[0])) ; i++) {
        r_.i64[i] = a_.i64[i] % b_.i64[i];
      }
    #endif

    return simde__m128i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm_rem_epi64
  #define _mm_rem_epi64(a, b) simde_mm_rem_epi64((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_rem_epu8 (simde__m128i a, simde__m128i b) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_rem_epu8(a, b);
  #else
    simde__m128i_private
      r_,
      a_ = simde__m128i_to_private(a),
      b_ = simde__m128i_to_private(b);

    #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r_.u8 = a_.u8 % b_.u8;
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.u8) / sizeof(r_.u8[0])) ; i++) {
        r_.u8[i] = a_.u8[i] % b_.u8[i];
      }
    #endif

    return simde__m128i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm_rem_epu8
  #define _mm_rem_epu8(a, b) simde_mm_rem_epu8((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_rem_epu16 (simde__m128i a, simde__m128i b) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_rem_epu16(a, b);
  #else
    simde__m128i_private
      r_,
      a_ = simde__m128i_to_private(a),
      b_ = simde__m128i_to_private(b);

    #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r_.u16 = a_.u16 % b_.u16;
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.u16) / sizeof(r_.u16[0])) ; i++) {
        r_.u16[i] = a_.u16[i] % b_.u16[i];
      }
    #endif

    return simde__m128i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm_rem_epu16
  #define _mm_rem_epu16(a, b) simde_mm_rem_epu16((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_rem_epu32 (simde__m128i a, simde__m128i b) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_rem_epu32(a, b);
  #else
    simde__m128i_private
      r_,
      a_ = simde__m128i_to_private(a),
      b_ = simde__m128i_to_private(b);

    #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r_.u32 = a_.u32 % b_.u32;
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.u32) / sizeof(r_.u32[0])) ; i++) {
        r_.u32[i] = a_.u32[i] % b_.u32[i];
      }
    #endif

    return simde__m128i_from_private(r_);
  #endif
}
#define simde_mm_urem_epi32(a, b) simde_mm_rem_epu32(a, b)
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm_rem_epu32
  #define _mm_rem_epu32(a, b) simde_mm_rem_epu32(a, b)
  #undef _mm_urem_epi32
  #define _mm_urem_epi32(a, b) simde_mm_rem_epu32(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_rem_epu64 (simde__m128i a, simde__m128i b) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_rem_epu64(a, b);
  #else
    simde__m128i_private
      r_,
      a_ = simde__m128i_to_private(a),
      b_ = simde__m128i_to_private(b);

    #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r_.u64 = a_.u64 % b_.u64;
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.u64) / sizeof(r_.u64[0])) ; i++) {
        r_.u64[i] = a_.u64[i] % b_.u64[i];
      }
    #endif

    return simde__m128i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm_rem_epu64
  #define _mm_rem_epu64(a, b) simde_mm_rem_epu64((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_rem_epi8 (simde__m256i a, simde__m256i b) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX_NATIVE)
    return _mm256_rem_epi8(a, b);
  #else
    simde__m256i_private
      r_,
      a_ = simde__m256i_to_private(a),
      b_ = simde__m256i_to_private(b);

    #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r_.i8 = a_.i8 % b_.i8;
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.i8) / sizeof(r_.i8[0])) ; i++) {
        r_.i8[i] = a_.i8[i] % b_.i8[i];
      }
    #endif

    return simde__m256i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm256_rem_epi8
  #define _mm256_rem_epi8(a, b) simde_mm256_rem_epi8((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_rem_epi16 (simde__m256i a, simde__m256i b) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX_NATIVE)
    return _mm256_rem_epi16(a, b);
  #else
    simde__m256i_private
      r_,
      a_ = simde__m256i_to_private(a),
      b_ = simde__m256i_to_private(b);

    #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r_.i16 = a_.i16 % b_.i16;
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.i16) / sizeof(r_.i16[0])) ; i++) {
        r_.i16[i] = a_.i16[i] % b_.i16[i];
      }
    #endif

    return simde__m256i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm256_rem_epi16
  #define _mm256_rem_epi16(a, b) simde_mm256_rem_epi16((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_rem_epi32 (simde__m256i a, simde__m256i b) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX_NATIVE)
    return _mm256_rem_epi32(a, b);
  #else
    simde__m256i_private
      r_,
      a_ = simde__m256i_to_private(a),
      b_ = simde__m256i_to_private(b);

    #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r_.i32 = a_.i32 % b_.i32;
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.i32) / sizeof(r_.i32[0])) ; i++) {
        r_.i32[i] = a_.i32[i] % b_.i32[i];
      }
    #endif

    return simde__m256i_from_private(r_);
  #endif
}
#define simde_mm256_irem_epi32(a, b) simde_mm256_rem_epi32(a, b)
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm256_rem_epi32
  #define _mm256_rem_epi32(a, b) simde_mm256_rem_epi32(a, b)
  #undef _mm256_irem_epi32
  #define _mm256_irem_epi32(a, b) simde_mm256_rem_epi32(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_rem_epi64 (simde__m256i a, simde__m256i b) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX_NATIVE)
    return _mm256_rem_epi64(a, b);
  #else
    simde__m256i_private
      r_,
      a_ = simde__m256i_to_private(a),
      b_ = simde__m256i_to_private(b);

    #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r_.i64 = a_.i64 % b_.i64;
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.i64) / sizeof(r_.i64[0])) ; i++) {
        r_.i64[i] = a_.i64[i] % b_.i64[i];
      }
    #endif

    return simde__m256i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm256_rem_epi64
  #define _mm256_rem_epi64(a, b) simde_mm256_rem_epi64((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_rem_epu8 (simde__m256i a, simde__m256i b) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX_NATIVE)
    return _mm256_rem_epu8(a, b);
  #else
    simde__m256i_private
      r_,
      a_ = simde__m256i_to_private(a),
      b_ = simde__m256i_to_private(b);

    #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r_.u8 = a_.u8 % b_.u8;
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.u8) / sizeof(r_.u8[0])) ; i++) {
        r_.u8[i] = a_.u8[i] % b_.u8[i];
      }
    #endif

    return simde__m256i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm256_rem_epu8
  #define _mm256_rem_epu8(a, b) simde_mm256_rem_epu8((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_rem_epu16 (simde__m256i a, simde__m256i b) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX_NATIVE)
    return _mm256_rem_epu16(a, b);
  #else
    simde__m256i_private
      r_,
      a_ = simde__m256i_to_private(a),
      b_ = simde__m256i_to_private(b);

    #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r_.u16 = a_.u16 % b_.u16;
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.u16) / sizeof(r_.u16[0])) ; i++) {
        r_.u16[i] = a_.u16[i] % b_.u16[i];
      }
    #endif

    return simde__m256i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm256_rem_epu16
  #define _mm256_rem_epu16(a, b) simde_mm256_rem_epu16((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_rem_epu32 (simde__m256i a, simde__m256i b) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX_NATIVE)
    return _mm256_rem_epu32(a, b);
  #else
    simde__m256i_private
      r_,
      a_ = simde__m256i_to_private(a),
      b_ = simde__m256i_to_private(b);

    #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r_.u32 = a_.u32 % b_.u32;
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.u32) / sizeof(r_.u32[0])) ; i++) {
        r_.u32[i] = a_.u32[i] % b_.u32[i];
      }
    #endif

    return simde__m256i_from_private(r_);
  #endif
}
#define simde_mm256_urem_epi32(a, b) simde_mm256_rem_epu32(a, b)
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm256_rem_epu32
  #define _mm256_rem_epu32(a, b) simde_mm256_rem_epu32(a, b)
  #undef _mm256_urem_epi32
  #define _mm256_urem_epi32(a, b) simde_mm256_rem_epu32(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_rem_epu64 (simde__m256i a, simde__m256i b) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX_NATIVE)
    return _mm256_rem_epu64(a, b);
  #else
    simde__m256i_private
      r_,
      a_ = simde__m256i_to_private(a),
      b_ = simde__m256i_to_private(b);

    #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r_.u64 = a_.u64 % b_.u64;
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.u64) / sizeof(r_.u64[0])) ; i++) {
        r_.u64[i] = a_.u64[i] % b_.u64[i];
      }
    #endif

    return simde__m256i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm256_rem_epu64
  #define _mm256_rem_epu64(a, b) simde_mm256_rem_epu64((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_rem_epi8 (simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_rem_epi8(a, b);
  #else
    simde__m512i_private
      r_,
      a_ = simde__m512i_to_private(a),
      b_ = simde__m512i_to_private(b);

    #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r_.i8 = a_.i8 % b_.i8;
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.i8) / sizeof(r_.i8[0])) ; i++) {
        r_.i8[i] = a_.i8[i] % b_.i8[i];
      }
    #endif

    return simde__m512i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm512_rem_epi8
  #define _mm512_rem_epi8(a, b) simde_mm512_rem_epi8((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_rem_epi16 (simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_rem_epi16(a, b);
  #else
    simde__m512i_private
      r_,
      a_ = simde__m512i_to_private(a),
      b_ = simde__m512i_to_private(b);

    #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r_.i16 = a_.i16 % b_.i16;
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.i16) / sizeof(r_.i16[0])) ; i++) {
        r_.i16[i] = a_.i16[i] % b_.i16[i];
      }
    #endif

    return simde__m512i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm512_rem_epi16
  #define _mm512_rem_epi16(a, b) simde_mm512_rem_epi16((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_rem_epi32 (simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_rem_epi32(a, b);
  #else
    simde__m512i_private
      r_,
      a_ = simde__m512i_to_private(a),
      b_ = simde__m512i_to_private(b);

    #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r_.i32 = a_.i32 % b_.i32;
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.i32) / sizeof(r_.i32[0])) ; i++) {
        r_.i32[i] = a_.i32[i] % b_.i32[i];
      }
    #endif

    return simde__m512i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm512_rem_epi32
  #define _mm512_rem_epi32(a, b) simde_mm512_rem_epi32((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_mask_rem_epi32(simde__m512i src, simde__mmask16 k, simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_mask_rem_epi32(src, k, a, b);
  #else
    return simde_mm512_mask_mov_epi32(src, k, simde_mm512_rem_epi32(a, b));
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_rem_epi32
  #define _mm512_mask_rem_epi32(src, k, a, b) simde_mm512_mask_rem_epi32(src, k, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_rem_epi64 (simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_rem_epi64(a, b);
  #else
    simde__m512i_private
      r_,
      a_ = simde__m512i_to_private(a),
      b_ = simde__m512i_to_private(b);

    #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r_.i64 = a_.i64 % b_.i64;
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.i64) / sizeof(r_.i64[0])) ; i++) {
        r_.i64[i] = a_.i64[i] % b_.i64[i];
      }
    #endif

    return simde__m512i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm512_rem_epi64
  #define _mm512_rem_epi64(a, b) simde_mm512_rem_epi64((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_rem_epu8 (simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_rem_epu8(a, b);
  #else
    simde__m512i_private
      r_,
      a_ = simde__m512i_to_private(a),
      b_ = simde__m512i_to_private(b);

    #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r_.u8 = a_.u8 % b_.u8;
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.u8) / sizeof(r_.u8[0])) ; i++) {
        r_.u8[i] = a_.u8[i] % b_.u8[i];
      }
    #endif

    return simde__m512i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm512_rem_epu8
  #define _mm512_rem_epu8(a, b) simde_mm512_rem_epu8((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_rem_epu16 (simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_rem_epu16(a, b);
  #else
    simde__m512i_private
      r_,
      a_ = simde__m512i_to_private(a),
      b_ = simde__m512i_to_private(b);

    #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r_.u16 = a_.u16 % b_.u16;
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.u16) / sizeof(r_.u16[0])) ; i++) {
        r_.u16[i] = a_.u16[i] % b_.u16[i];
      }
    #endif

    return simde__m512i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm512_rem_epu16
  #define _mm512_rem_epu16(a, b) simde_mm512_rem_epu16((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_rem_epu32 (simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_rem_epu32(a, b);
  #else
    simde__m512i_private
      r_,
      a_ = simde__m512i_to_private(a),
      b_ = simde__m512i_to_private(b);

    #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r_.u32 = a_.u32 % b_.u32;
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.u32) / sizeof(r_.u32[0])) ; i++) {
        r_.u32[i] = a_.u32[i] % b_.u32[i];
      }
    #endif

    return simde__m512i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm512_rem_epu32
  #define _mm512_rem_epu32(a, b) simde_mm512_rem_epu32((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_mask_rem_epu32(simde__m512i src, simde__mmask16 k, simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_mask_rem_epu32(src, k, a, b);
  #else
    return simde_mm512_mask_mov_epi32(src, k, simde_mm512_rem_epu32(a, b));
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_rem_epu32
  #define _mm512_mask_rem_epu32(src, k, a, b) simde_mm512_mask_rem_epu32(src, k, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_rem_epu64 (simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_rem_epu64(a, b);
  #else
    simde__m512i_private
      r_,
      a_ = simde__m512i_to_private(a),
      b_ = simde__m512i_to_private(b);

    #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r_.u64 = a_.u64 % b_.u64;
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.u64) / sizeof(r_.u64[0])) ; i++) {
        r_.u64[i] = a_.u64[i] % b_.u64[i];
      }
    #endif

    return simde__m512i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm512_rem_epu64
  #define _mm512_rem_epu64(a, b) simde_mm512_rem_epu64((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128
simde_mm_sin_ps (simde__m128 a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_SSE_NATIVE)
    return _mm_sin_ps(a);
  #else
    simde__m128_private
      r_,
      a_ = simde__m128_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f32) / sizeof(r_.f32[0])) ; i++) {
      r_.f32[i] =  simde_math_sinf(a_.f32[i]);
    }

    return simde__m128_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm_sin_ps
  #define _mm_sin_ps(a) simde_mm_sin_ps(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128d
simde_mm_sin_pd (simde__m128d a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_SSE_NATIVE)
    return _mm_sin_pd(a);
  #else
    simde__m128d_private
      r_,
      a_ = simde__m128d_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f64) / sizeof(r_.f64[0])) ; i++) {
      r_.f64[i] =  simde_math_sin(a_.f64[i]);
    }

    return simde__m128d_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm_sin_pd
  #define _mm_sin_pd(a) simde_mm_sin_pd(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256
simde_mm256_sin_ps (simde__m256 a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX_NATIVE)
    return _mm256_sin_ps(a);
  #else
    simde__m256_private
      r_,
      a_ = simde__m256_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f32) / sizeof(r_.f32[0])) ; i++) {
      r_.f32[i] =  simde_math_sinf(a_.f32[i]);
    }

    return simde__m256_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm256_sin_ps
  #define _mm256_sin_ps(a) simde_mm256_sin_ps(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256d
simde_mm256_sin_pd (simde__m256d a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX_NATIVE)
    return _mm256_sin_pd(a);
  #else
    simde__m256d_private
      r_,
      a_ = simde__m256d_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f64) / sizeof(r_.f64[0])) ; i++) {
      r_.f64[i] =  simde_math_sin(a_.f64[i]);
    }

    return simde__m256d_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm256_sin_pd
  #define _mm256_sin_pd(a) simde_mm256_sin_pd(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512
simde_mm512_sin_ps (simde__m512 a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_sin_ps(a);
  #else
    simde__m512_private
      r_,
      a_ = simde__m512_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f32) / sizeof(r_.f32[0])) ; i++) {
      r_.f32[i] =  simde_math_sinf(a_.f32[i]);
    }

    return simde__m512_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm512_sin_ps
  #define _mm512_sin_ps(a) simde_mm512_sin_ps(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512d
simde_mm512_sin_pd (simde__m512d a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_sin_pd(a);
  #else
    simde__m512d_private
      r_,
      a_ = simde__m512d_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f64) / sizeof(r_.f64[0])) ; i++) {
      r_.f64[i] =  simde_math_sin(a_.f64[i]);
    }

    return simde__m512d_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm512_sin_pd
  #define _mm512_sin_pd(a) simde_mm512_sin_pd(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512
simde_mm512_mask_sin_ps(simde__m512 src, simde__mmask16 k, simde__m512 a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_mask_sin_ps(src, k, a);
  #else
    return simde_mm512_mask_mov_ps(src, k, simde_mm512_sin_ps(a));
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_sin_ps
  #define _mm512_mask_sin_ps(src, k, a) simde_mm512_mask_sin_ps(src, k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512d
simde_mm512_mask_sin_pd(simde__m512d src, simde__mmask8 k, simde__m512d a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_mask_sin_pd(src, k, a);
  #else
    return simde_mm512_mask_mov_pd(src, k, simde_mm512_sin_pd(a));
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_sin_pd
  #define _mm512_mask_sin_pd(src, k, a) simde_mm512_mask_sin_pd(src, k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128
simde_mm_sind_ps (simde__m128 a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_SSE_NATIVE)
    return _mm_sind_ps(a);
  #else
    simde__m128_private
      r_,
      a_ = simde__m128_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f32) / sizeof(r_.f32[0])) ; i++) {
      r_.f32[i] =  simde_math_sinf(simde_math_deg2radf(a_.f32[i]));
    }

    return simde__m128_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm_sind_ps
  #define _mm_sind_ps(a) simde_mm_sind_ps(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128d
simde_mm_sind_pd (simde__m128d a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_SSE_NATIVE)
    return _mm_sind_pd(a);
  #else
    simde__m128d_private
      r_,
      a_ = simde__m128d_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f64) / sizeof(r_.f64[0])) ; i++) {
      r_.f64[i] =  simde_math_sin(simde_math_deg2rad(a_.f64[i]));
    }

    return simde__m128d_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm_sind_pd
  #define _mm_sind_pd(a) simde_mm_sind_pd(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256
simde_mm256_sind_ps (simde__m256 a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX_NATIVE)
    return _mm256_sind_ps(a);
  #else
    simde__m256_private
      r_,
      a_ = simde__m256_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f32) / sizeof(r_.f32[0])) ; i++) {
      r_.f32[i] =  simde_math_sinf(simde_math_deg2radf(a_.f32[i]));
    }

    return simde__m256_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm256_sind_ps
  #define _mm256_sind_ps(a) simde_mm256_sind_ps(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256d
simde_mm256_sind_pd (simde__m256d a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX_NATIVE)
    return _mm256_sind_pd(a);
  #else
    simde__m256d_private
      r_,
      a_ = simde__m256d_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f64) / sizeof(r_.f64[0])) ; i++) {
      r_.f64[i] =  simde_math_sin(simde_math_deg2rad(a_.f64[i]));
    }

    return simde__m256d_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm256_sind_pd
  #define _mm256_sind_pd(a) simde_mm256_sind_pd(a)
#endif


SIMDE_FUNCTION_ATTRIBUTES
simde__m512
simde_mm512_sind_ps (simde__m512 a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_sind_ps(a);
  #else
    simde__m512_private
      r_,
      a_ = simde__m512_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f32) / sizeof(r_.f32[0])) ; i++) {
      r_.f32[i] =  simde_math_sinf(simde_math_deg2radf(a_.f32[i]));
    }

    return simde__m512_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm512_sind_ps
  #define _mm512_sind_ps(a) simde_mm512_sind_ps(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512d
simde_mm512_sind_pd (simde__m512d a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_sind_pd(a);
  #else
    simde__m512d_private
      r_,
      a_ = simde__m512d_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f64) / sizeof(r_.f64[0])) ; i++) {
      r_.f64[i] =  simde_math_sin(simde_math_deg2rad(a_.f64[i]));
    }

    return simde__m512d_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm512_sind_pd
  #define _mm512_sind_pd(a) simde_mm512_sind_pd(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512
simde_mm512_mask_sind_ps(simde__m512 src, simde__mmask16 k, simde__m512 a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_mask_sind_ps(src, k, a);
  #else
    return simde_mm512_mask_mov_ps(src, k, simde_mm512_sind_ps(a));
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_sind_ps
  #define _mm512_mask_sind_ps(src, k, a) simde_mm512_mask_sind_ps(src, k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512d
simde_mm512_mask_sind_pd(simde__m512d src, simde__mmask8 k, simde__m512d a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_mask_sind_pd(src, k, a);
  #else
    return simde_mm512_mask_mov_pd(src, k, simde_mm512_sind_pd(a));
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_sind_pd
  #define _mm512_mask_sind_pd(src, k, a) simde_mm512_mask_sind_pd(src, k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128
simde_mm_sinh_ps (simde__m128 a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_SSE_NATIVE)
    return _mm_sinh_ps(a);
  #else
    simde__m128_private
      r_,
      a_ = simde__m128_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f32) / sizeof(r_.f32[0])) ; i++) {
      r_.f32[i] =  simde_math_sinhf(a_.f32[i]);
    }

    return simde__m128_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm_sinh_ps
  #define _mm_sinh_ps(a) simde_mm_sinh_ps(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128d
simde_mm_sinh_pd (simde__m128d a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_SSE_NATIVE)
    return _mm_sinh_pd(a);
  #else
    simde__m128d_private
      r_,
      a_ = simde__m128d_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f64) / sizeof(r_.f64[0])) ; i++) {
      r_.f64[i] =  simde_math_sinh(a_.f64[i]);
    }

    return simde__m128d_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm_sinh_pd
  #define _mm_sinh_pd(a) simde_mm_sinh_pd(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256
simde_mm256_sinh_ps (simde__m256 a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX_NATIVE)
    return _mm256_sinh_ps(a);
  #else
    simde__m256_private
      r_,
      a_ = simde__m256_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f32) / sizeof(r_.f32[0])) ; i++) {
      r_.f32[i] =  simde_math_sinhf(a_.f32[i]);
    }

    return simde__m256_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm256_sinh_ps
  #define _mm256_sinh_ps(a) simde_mm256_sinh_ps(a)
#endif


SIMDE_FUNCTION_ATTRIBUTES
simde__m256d
simde_mm256_sinh_pd (simde__m256d a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX_NATIVE)
    return _mm256_sinh_pd(a);
  #else
    simde__m256d_private
      r_,
      a_ = simde__m256d_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f64) / sizeof(r_.f64[0])) ; i++) {
      r_.f64[i] =  simde_math_sinh(a_.f64[i]);
    }

    return simde__m256d_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm256_sinh_pd
  #define _mm256_sinh_pd(a) simde_mm256_sinh_pd(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512
simde_mm512_sinh_ps (simde__m512 a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_sinh_ps(a);
  #else
    simde__m512_private
      r_,
      a_ = simde__m512_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f32) / sizeof(r_.f32[0])) ; i++) {
      r_.f32[i] =  simde_math_sinhf(a_.f32[i]);
    }

    return simde__m512_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm512_sinh_ps
  #define _mm512_sinh_ps(a) simde_mm512_sinh_ps(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512d
simde_mm512_sinh_pd (simde__m512d a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_sinh_pd(a);
  #else
    simde__m512d_private
      r_,
      a_ = simde__m512d_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f64) / sizeof(r_.f64[0])) ; i++) {
      r_.f64[i] =  simde_math_sinh(a_.f64[i]);
    }

    return simde__m512d_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm512_sinh_pd
  #define _mm512_sinh_pd(a) simde_mm512_sinh_pd(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512
simde_mm512_mask_sinh_ps(simde__m512 src, simde__mmask16 k, simde__m512 a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_mask_sinh_ps(src, k, a);
  #else
    return simde_mm512_mask_mov_ps(src, k, simde_mm512_sinh_ps(a));
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_sinh_ps
  #define _mm512_mask_sinh_ps(src, k, a) simde_mm512_mask_sinh_ps(src, k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512d
simde_mm512_mask_sinh_pd(simde__m512d src, simde__mmask8 k, simde__m512d a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_mask_sinh_pd(src, k, a);
  #else
    return simde_mm512_mask_mov_pd(src, k, simde_mm512_sinh_pd(a));
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_sinh_pd
  #define _mm512_mask_sinh_pd(src, k, a) simde_mm512_mask_sinh_pd(src, k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128
simde_mm_svml_sqrt_ps (simde__m128 a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_SSE_NATIVE)
    return _mm_svml_sqrt_ps(a);
  #else
    return simde_mm_sqrt_ps(a);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm_svml_sqrt_ps
  #define _mm_svml_sqrt_ps(a) simde_mm_svml_sqrt_ps(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128d
simde_mm_svml_sqrt_pd (simde__m128d a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_SSE_NATIVE)
    return _mm_svml_sqrt_pd(a);
  #else
    return simde_mm_sqrt_pd(a);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm_svml_sqrt_pd
  #define _mm_svml_sqrt_pd(a) simde_mm_svml_sqrt_pd(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256
simde_mm256_svml_sqrt_ps (simde__m256 a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX_NATIVE)
    return _mm256_svml_sqrt_ps(a);
  #else
    return simde_mm256_sqrt_ps(a);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm256_svml_sqrt_ps
  #define _mm256_svml_sqrt_ps(a) simde_mm256_svml_sqrt_ps(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256d
simde_mm256_svml_sqrt_pd (simde__m256d a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX_NATIVE)
    return _mm256_svml_sqrt_pd(a);
  #else
    return simde_mm256_sqrt_pd(a);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm256_svml_sqrt_pd
  #define _mm256_svml_sqrt_pd(a) simde_mm256_svml_sqrt_pd(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512
simde_mm512_svml_sqrt_ps (simde__m512 a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_svml_sqrt_ps(a);
  #else
    return simde_mm512_sqrt_ps(a);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm512_svml_sqrt_ps
  #define _mm512_svml_sqrt_ps(a) simde_mm512_svml_sqrt_ps(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512d
simde_mm512_svml_sqrt_pd (simde__m512d a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_svml_sqrt_pd(a);
  #else
    return simde_mm512_sqrt_pd(a);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm512_svml_sqrt_pd
  #define _mm512_svml_sqrt_pd(a) simde_mm512_svml_sqrt_pd(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128
simde_mm_tan_ps (simde__m128 a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_SSE_NATIVE)
    return _mm_tan_ps(a);
  #else
    simde__m128_private
      r_,
      a_ = simde__m128_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f32) / sizeof(r_.f32[0])) ; i++) {
      r_.f32[i] =  simde_math_tanf(a_.f32[i]);
    }

    return simde__m128_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm_tan_ps
  #define _mm_tan_ps(a) simde_mm_tan_ps(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128d
simde_mm_tan_pd (simde__m128d a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_SSE_NATIVE)
    return _mm_tan_pd(a);
  #else
    simde__m128d_private
      r_,
      a_ = simde__m128d_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f64) / sizeof(r_.f64[0])) ; i++) {
      r_.f64[i] =  simde_math_tan(a_.f64[i]);
    }

    return simde__m128d_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm_tan_pd
  #define _mm_tan_pd(a) simde_mm_tan_pd(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256
simde_mm256_tan_ps (simde__m256 a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX_NATIVE)
    return _mm256_tan_ps(a);
  #else
    simde__m256_private
      r_,
      a_ = simde__m256_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f32) / sizeof(r_.f32[0])) ; i++) {
      r_.f32[i] =  simde_math_tanf(a_.f32[i]);
    }

    return simde__m256_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm256_tan_ps
  #define _mm256_tan_ps(a) simde_mm256_tan_ps(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256d
simde_mm256_tan_pd (simde__m256d a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX_NATIVE)
    return _mm256_tan_pd(a);
  #else
    simde__m256d_private
      r_,
      a_ = simde__m256d_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f64) / sizeof(r_.f64[0])) ; i++) {
      r_.f64[i] =  simde_math_tan(a_.f64[i]);
    }

    return simde__m256d_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm256_tan_pd
  #define _mm256_tan_pd(a) simde_mm256_tan_pd(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512
simde_mm512_tan_ps (simde__m512 a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_tan_ps(a);
  #else
    simde__m512_private
      r_,
      a_ = simde__m512_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f32) / sizeof(r_.f32[0])) ; i++) {
      r_.f32[i] =  simde_math_tanf(a_.f32[i]);
    }

    return simde__m512_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm512_tan_ps
  #define _mm512_tan_ps(a) simde_mm512_tan_ps(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512d
simde_mm512_tan_pd (simde__m512d a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_tan_pd(a);
  #else
    simde__m512d_private
      r_,
      a_ = simde__m512d_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f64) / sizeof(r_.f64[0])) ; i++) {
      r_.f64[i] =  simde_math_tan(a_.f64[i]);
    }

    return simde__m512d_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm512_tan_pd
  #define _mm512_tan_pd(a) simde_mm512_tan_pd(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512
simde_mm512_mask_tan_ps(simde__m512 src, simde__mmask16 k, simde__m512 a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_mask_tan_ps(src, k, a);
  #else
    return simde_mm512_mask_mov_ps(src, k, simde_mm512_tan_ps(a));
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_tan_ps
  #define _mm512_mask_tan_ps(src, k, a) simde_mm512_mask_tan_ps(src, k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512d
simde_mm512_mask_tan_pd(simde__m512d src, simde__mmask8 k, simde__m512d a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_mask_tan_pd(src, k, a);
  #else
    return simde_mm512_mask_mov_pd(src, k, simde_mm512_tan_pd(a));
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_tan_pd
  #define _mm512_mask_tan_pd(src, k, a) simde_mm512_mask_tan_pd(src, k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128
simde_mm_tand_ps (simde__m128 a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_SSE_NATIVE)
    return _mm_tand_ps(a);
  #else
    simde__m128_private
      r_,
      a_ = simde__m128_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f32) / sizeof(r_.f32[0])) ; i++) {
      r_.f32[i] =  simde_math_tanf(simde_math_deg2radf(a_.f32[i]));
    }

    return simde__m128_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm_tand_ps
  #define _mm_tand_ps(a) simde_mm_tand_ps(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128d
simde_mm_tand_pd (simde__m128d a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_SSE_NATIVE)
    return _mm_tand_pd(a);
  #else
    simde__m128d_private
      r_,
      a_ = simde__m128d_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f64) / sizeof(r_.f64[0])) ; i++) {
      r_.f64[i] =  simde_math_tan(simde_math_deg2rad(a_.f64[i]));
    }

    return simde__m128d_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm_tand_pd
  #define _mm_tand_pd(a) simde_mm_tand_pd(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256
simde_mm256_tand_ps (simde__m256 a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX_NATIVE)
    return _mm256_tand_ps(a);
  #else
    simde__m256_private
      r_,
      a_ = simde__m256_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f32) / sizeof(r_.f32[0])) ; i++) {
      r_.f32[i] =  simde_math_tanf(simde_math_deg2radf(a_.f32[i]));
    }

    return simde__m256_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm256_tand_ps
  #define _mm256_tand_ps(a) simde_mm256_tand_ps(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256d
simde_mm256_tand_pd (simde__m256d a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX_NATIVE)
    return _mm256_tand_pd(a);
  #else
    simde__m256d_private
      r_,
      a_ = simde__m256d_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f64) / sizeof(r_.f64[0])) ; i++) {
      r_.f64[i] =  simde_math_tan(simde_math_deg2rad(a_.f64[i]));
    }

    return simde__m256d_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm256_tand_pd
  #define _mm256_tand_pd(a) simde_mm256_tand_pd(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512
simde_mm512_tand_ps (simde__m512 a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_tand_ps(a);
  #else
    simde__m512_private
      r_,
      a_ = simde__m512_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f32) / sizeof(r_.f32[0])) ; i++) {
      r_.f32[i] =  simde_math_tanf(simde_math_deg2radf(a_.f32[i]));
    }

    return simde__m512_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm512_tand_ps
  #define _mm512_tand_ps(a) simde_mm512_tand_ps(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512d
simde_mm512_tand_pd (simde__m512d a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_tand_pd(a);
  #else
    simde__m512d_private
      r_,
      a_ = simde__m512d_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f64) / sizeof(r_.f64[0])) ; i++) {
      r_.f64[i] =  simde_math_tan(simde_math_deg2rad(a_.f64[i]));
    }

    return simde__m512d_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm512_tand_pd
  #define _mm512_tand_pd(a) simde_mm512_tand_pd(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512
simde_mm512_mask_tand_ps(simde__m512 src, simde__mmask16 k, simde__m512 a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_mask_tand_ps(src, k, a);
  #else
    return simde_mm512_mask_mov_ps(src, k, simde_mm512_tand_ps(a));
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_tand_ps
  #define _mm512_mask_tand_ps(src, k, a) simde_mm512_mask_tand_ps(src, k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512d
simde_mm512_mask_tand_pd(simde__m512d src, simde__mmask8 k, simde__m512d a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_mask_tand_pd(src, k, a);
  #else
    return simde_mm512_mask_mov_pd(src, k, simde_mm512_tand_pd(a));
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_tand_pd
  #define _mm512_mask_tand_pd(src, k, a) simde_mm512_mask_tand_pd(src, k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128
simde_mm_tanh_ps (simde__m128 a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_SSE_NATIVE)
    return _mm_tanh_ps(a);
  #else
    simde__m128_private
      r_,
      a_ = simde__m128_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f32) / sizeof(r_.f32[0])) ; i++) {
      r_.f32[i] =  simde_math_tanhf(a_.f32[i]);
    }

    return simde__m128_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm_tanh_ps
  #define _mm_tanh_ps(a) simde_mm_tanh_ps(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128d
simde_mm_tanh_pd (simde__m128d a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_SSE_NATIVE)
    return _mm_tanh_pd(a);
  #else
    simde__m128d_private
      r_,
      a_ = simde__m128d_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f64) / sizeof(r_.f64[0])) ; i++) {
      r_.f64[i] =  simde_math_tanh(a_.f64[i]);
    }

    return simde__m128d_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm_tanh_pd
  #define _mm_tanh_pd(a) simde_mm_tanh_pd(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256
simde_mm256_tanh_ps (simde__m256 a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX_NATIVE)
    return _mm256_tanh_ps(a);
  #else
    simde__m256_private
      r_,
      a_ = simde__m256_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f32) / sizeof(r_.f32[0])) ; i++) {
      r_.f32[i] =  simde_math_tanhf(a_.f32[i]);
    }

    return simde__m256_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm256_tanh_ps
  #define _mm256_tanh_ps(a) simde_mm256_tanh_ps(a)
#endif


SIMDE_FUNCTION_ATTRIBUTES
simde__m256d
simde_mm256_tanh_pd (simde__m256d a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX_NATIVE)
    return _mm256_tanh_pd(a);
  #else
    simde__m256d_private
      r_,
      a_ = simde__m256d_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f64) / sizeof(r_.f64[0])) ; i++) {
      r_.f64[i] =  simde_math_tanh(a_.f64[i]);
    }

    return simde__m256d_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm256_tanh_pd
  #define _mm256_tanh_pd(a) simde_mm256_tanh_pd(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512
simde_mm512_tanh_ps (simde__m512 a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_tanh_ps(a);
  #else
    simde__m512_private
      r_,
      a_ = simde__m512_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f32) / sizeof(r_.f32[0])) ; i++) {
      r_.f32[i] =  simde_math_tanhf(a_.f32[i]);
    }

    return simde__m512_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm512_tanh_ps
  #define _mm512_tanh_ps(a) simde_mm512_tanh_ps(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512d
simde_mm512_tanh_pd (simde__m512d a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_tanh_pd(a);
  #else
    simde__m512d_private
      r_,
      a_ = simde__m512d_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f64) / sizeof(r_.f64[0])) ; i++) {
      r_.f64[i] =  simde_math_tanh(a_.f64[i]);
    }

    return simde__m512d_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm512_tanh_pd
  #define _mm512_tanh_pd(a) simde_mm512_tanh_pd(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512
simde_mm512_mask_tanh_ps(simde__m512 src, simde__mmask16 k, simde__m512 a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_mask_tanh_ps(src, k, a);
  #else
    return simde_mm512_mask_mov_ps(src, k, simde_mm512_tanh_ps(a));
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_tanh_ps
  #define _mm512_mask_tanh_ps(src, k, a) simde_mm512_mask_tanh_ps(src, k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512d
simde_mm512_mask_tanh_pd(simde__m512d src, simde__mmask8 k, simde__m512d a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_mask_tanh_pd(src, k, a);
  #else
    return simde_mm512_mask_mov_pd(src, k, simde_mm512_tanh_pd(a));
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_tanh_pd
  #define _mm512_mask_tanh_pd(src, k, a) simde_mm512_mask_tanh_pd(src, k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128
simde_mm_trunc_ps (simde__m128 a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_SSE_NATIVE)
    return _mm_trunc_ps(a);
  #else
    simde__m128_private
      r_,
      a_ = simde__m128_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f32) / sizeof(r_.f32[0])) ; i++) {
      r_.f32[i] =  simde_math_truncf(a_.f32[i]);
    }

    return simde__m128_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm_trunc_ps
  #define _mm_trunc_ps(a) simde_mm_trunc_ps(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128d
simde_mm_trunc_pd (simde__m128d a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_SSE_NATIVE)
    return _mm_trunc_pd(a);
  #else
    simde__m128d_private
      r_,
      a_ = simde__m128d_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f64) / sizeof(r_.f64[0])) ; i++) {
      r_.f64[i] =  simde_math_trunc(a_.f64[i]);
    }

    return simde__m128d_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm_trunc_pd
  #define _mm_trunc_pd(a) simde_mm_trunc_pd(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256
simde_mm256_trunc_ps (simde__m256 a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX_NATIVE)
    return _mm256_trunc_ps(a);
  #else
    simde__m256_private
      r_,
      a_ = simde__m256_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f32) / sizeof(r_.f32[0])) ; i++) {
      r_.f32[i] =  simde_math_truncf(a_.f32[i]);
    }

    return simde__m256_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm256_trunc_ps
  #define _mm256_trunc_ps(a) simde_mm256_trunc_ps(a)
#endif


SIMDE_FUNCTION_ATTRIBUTES
simde__m256d
simde_mm256_trunc_pd (simde__m256d a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX_NATIVE)
    return _mm256_trunc_pd(a);
  #else
    simde__m256d_private
      r_,
      a_ = simde__m256d_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f64) / sizeof(r_.f64[0])) ; i++) {
      r_.f64[i] =  simde_math_trunc(a_.f64[i]);
    }

    return simde__m256d_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm256_trunc_pd
  #define _mm256_trunc_pd(a) simde_mm256_trunc_pd(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512
simde_mm512_trunc_ps (simde__m512 a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_trunc_ps(a);
  #else
    simde__m512_private
      r_,
      a_ = simde__m512_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f32) / sizeof(r_.f32[0])) ; i++) {
      r_.f32[i] =  simde_math_truncf(a_.f32[i]);
    }

    return simde__m512_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm512_trunc_ps
  #define _mm512_trunc_ps(a) simde_mm512_trunc_ps(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512d
simde_mm512_trunc_pd (simde__m512d a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_trunc_pd(a);
  #else
    simde__m512d_private
      r_,
      a_ = simde__m512d_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f64) / sizeof(r_.f64[0])) ; i++) {
      r_.f64[i] =  simde_math_trunc(a_.f64[i]);
    }

    return simde__m512d_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm512_trunc_pd
  #define _mm512_trunc_pd(a) simde_mm512_trunc_pd(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512
simde_mm512_mask_trunc_ps(simde__m512 src, simde__mmask16 k, simde__m512 a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_mask_trunc_ps(src, k, a);
  #else
    return simde_mm512_mask_mov_ps(src, k, simde_mm512_trunc_ps(a));
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_trunc_ps
  #define _mm512_mask_trunc_ps(src, k, a) simde_mm512_mask_trunc_ps(src, k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512d
simde_mm512_mask_trunc_pd(simde__m512d src, simde__mmask8 k, simde__m512d a) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_mask_trunc_pd(src, k, a);
  #else
    return simde_mm512_mask_mov_pd(src, k, simde_mm512_trunc_pd(a));
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_trunc_pd
  #define _mm512_mask_trunc_pd(src, k, a) simde_mm512_mask_trunc_pd(src, k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_udivrem_epi32 (simde__m128i * mem_addr, simde__m128i a, simde__m128i b) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_udivrem_epi32(mem_addr, a, b);
  #else
    simde__m128i r;

    r = simde_mm_div_epu32(a, b);
    *mem_addr = simde_x_mm_sub_epu32(a, simde_x_mm_mullo_epu32(r, b));

    return r;
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm_udivrem_epi32
  #define _mm_udivrem_epi32(mem_addr, a, b) simde_mm_udivrem_epi32((mem_addr),(a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_udivrem_epi32 (simde__m256i* mem_addr, simde__m256i a, simde__m256i b) {
  #if defined(SIMDE_X86_SVML_NATIVE) && defined(SIMDE_X86_AVX_NATIVE)
    return _mm256_udivrem_epi32(HEDLEY_REINTERPRET_CAST(__m256i*, mem_addr), a, b);
  #else
    simde__m256i r;

    r = simde_mm256_div_epu32(a, b);
    *mem_addr = simde_x_mm256_sub_epu32(a, simde_x_mm256_mullo_epu32(r, b));

    return r;
  #endif
}
#if defined(SIMDE_X86_SVML_ENABLE_NATIVE_ALIASES)
  #undef _mm256_udivrem_epi32
  #define _mm256_udivrem_epi32(mem_addr, a, b) simde_mm256_udivrem_epi32((mem_addr),(a), (b))
#endif

SIMDE_END_DECLS_

HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_SVML_H) */
