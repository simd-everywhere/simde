/* Permission is hereby granted, free of charge, to any person
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
 *   2019      Evan Nemerson <evan@nemerson.com>
 */

#include "sse2.h"
#if !defined(SIMDE__FMA_H)
#  if !defined(SIMDE__FMA_H)
#    define SIMDE__FMA_H
#  endif
#  include "avx2.h"

#  if defined(SIMDE_FMA_NATIVE)
#    undef SIMDE_FMA_NATIVE
#  endif
#  if defined(SIMDE_FMA_FORCE_NATIVE)
#    define SIMDE_FMA_NATIVE
#  elif defined(__FMA__) && !defined(SIMDE_FMA_NO_NATIVE) && !defined(SIMDE_NO_NATIVE)
#    define SIMDE_FMA_NATIVE
#  elif defined(__ARM_NEON) && !defined(SIMDE_FMA_NO_NEON) && !defined(SIMDE_NO_NEON)
#    define SIMDE_FMA_NEON
#  endif

#  if defined(SIMDE_FMA_NATIVE) && !defined(SIMDE_AVX_NATIVE)
#    if defined(SIMDE_FMA_FORCE_NATIVE)
#      error Native FMA support requires native AVX support
#    else
#      warning Native FMA support requires native AVX support, disabling
#      undef SIMDE_FMA_NATIVE
#    endif
#  elif defined(SIMDE_FMA_NEON) && !defined(SIMDE_AVX_NEON)
#    warning FMA NEON support requires AVX NEON support, disabling
#    undef SIMDE_AVX_NEON
#  endif

#  if defined(SIMDE_FMA_NATIVE)
#    include <immintrin.h>
#  endif

#  if !defined(SIMDE_FMA_NATIVE) && defined(SIMDE_ENABLE_NATIVE_ALIASES)
#    define SIMDE_FMA_ENABLE_NATIVE_ALIASES
#  endif

SIMDE__BEGIN_DECLS

SIMDE__FUNCTION_ATTRIBUTES
simde__m128d
simde_mm_fmadd_pd (simde__m128d a, simde__m128d b, simde__m128d c) {
  simde__m128d r;

#if defined(SIMDE_FMA_NATIVE)
  r.n = _mm_fmadd_pd(a.n, b.n, c.n);
#else
  r = simde_mm_add_pd(simde_mm_mul_pd(a, b), c);
#endif

  return r;
}
#if defined(SIMDE_FMA_ENABLE_NATIVE_ALIASES)
#  define _mm_fmadd_pd(a, b) SIMDE__M128D_TO_NATIVE(simde_mm_fmadd_pd(SIMDE__M128D_FROM_NATIVE(a), SIMDE__M128D_FROM_NATIVE(b), SIMDE__M128D_FROM_NATIVE(c)))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m256d
simde_mm256_fmadd_pd (simde__m256d a, simde__m256d b, simde__m256d c) {
  simde__m256d r;

#if defined(SIMDE_FMA_NATIVE)
  r.n = _mm256_fmadd_pd(a.n, b.n, c.n);
#else
  r = simde_mm256_add_pd(simde_mm256_mul_pd(a, b), c);
#endif

  return r;
}
#if defined(SIMDE_FMA_ENABLE_NATIVE_ALIASES)
#  define _mm_fmadd_pd(a, b) SIMDE__M256D_TO_NATIVE(simde_mm_fmadd_pd(SIMDE__M256D_FROM_NATIVE(a), SIMDE__M256D_FROM_NATIVE(b), SIMDE__M256D_FROM_NATIVE(c)))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128
simde_mm_fmadd_ps (simde__m128 a, simde__m128 b, simde__m128 c) {
  simde__m128 r;

#if defined(SIMDE_FMA_NATIVE)
  r.n = _mm_fmadd_ps(a.n, b.n, c.n);
#else
  r = simde_mm_add_ps(simde_mm_mul_ps(a, b), c);
#endif

  return r;
}
#if defined(SIMDE_FMA_ENABLE_NATIVE_ALIASES)
#  define _mm_fmadd_ps(a, b) SIMDE__M128_TO_NATIVE(simde_mm_fmadd_ps(SIMDE__M128_FROM_NATIVE(a), SIMDE__M128_FROM_NATIVE(b), SIMDE__M128_FROM_NATIVE(c)))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m256
simde_mm256_fmadd_ps (simde__m256 a, simde__m256 b, simde__m256 c) {
  simde__m256 r;

#if defined(SIMDE_FMA_NATIVE)
  r.n = _mm256_fmadd_ps(a.n, b.n, c.n);
#else
  r = simde_mm256_add_ps(simde_mm256_mul_ps(a, b), c);
#endif

  return r;
}
#if defined(SIMDE_FMA_ENABLE_NATIVE_ALIASES)
#  define _mm_fmadd_ps(a, b) SIMDE__M256_TO_NATIVE(simde_mm_fmadd_ps(SIMDE__M256_FROM_NATIVE(a), SIMDE__M256_FROM_NATIVE(b), SIMDE__M256_FROM_NATIVE(c)))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128d
simde_mm_fmadd_sd (simde__m128d a, simde__m128d b, simde__m128d c) {
  simde__m128d r;

#if defined(SIMDE_FMA_NATIVE)
  r.n = _mm_fmadd_sd(a.n, b.n, c.n);
#else
  r = simde_mm_add_sd(simde_mm_mul_sd(a, b), c);
#endif

  return r;
}
#if defined(SIMDE_FMA_ENABLE_NATIVE_ALIASES)
#  define _mm_fmadd_sd(a, b) SIMDE__M128D_TO_NATIVE(simde_mm_fmadd_sd(SIMDE__M128D_FROM_NATIVE(a), SIMDE__M128D_FROM_NATIVE(b), SIMDE__M128D_FROM_NATIVE(c)))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128
simde_mm_fmadd_ss (simde__m128 a, simde__m128 b, simde__m128 c) {
  simde__m128 r;

#if defined(SIMDE_FMA_NATIVE)
  r.n = _mm_fmadd_ss(a.n, b.n, c.n);
#else
  r = simde_mm_add_ss(simde_mm_mul_ss(a, b), c);
#endif

  return r;
}
#if defined(SIMDE_FMA_ENABLE_NATIVE_ALIASES)
#  define _mm_fmadd_ss(a, b) SIMDE__M128_TO_NATIVE(simde_mm_fmadd_ss(SIMDE__M128_FROM_NATIVE(a), SIMDE__M128_FROM_NATIVE(b), SIMDE__M128_FROM_NATIVE(c)))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128d
simde_mm_fmaddsub_pd (simde__m128d a, simde__m128d b, simde__m128d c) {
  simde__m128d r;

#if defined(SIMDE_FMA_NATIVE)
  r.n = _mm_fmaddsub_pd(a.n, b.n, c.n);
#else
  r = simde_mm_addsub_pd(simde_mm_mul_pd(a, b), c);
#endif

  return r;
}
#if defined(SIMDE_FMA_ENABLE_NATIVE_ALIASES)
#  define _mm_fmaddsub_pd(a, b) SIMDE__M128D_TO_NATIVE(simde_mm_fmaddsub_pd(SIMDE__M128D_FROM_NATIVE(a), SIMDE__M128D_FROM_NATIVE(b), SIMDE__M128D_FROM_NATIVE(c)))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m256d
simde_mm256_fmaddsub_pd (simde__m256d a, simde__m256d b, simde__m256d c) {
  simde__m256d r;

#if defined(SIMDE_FMA_NATIVE)
  r.n = _mm256_fmaddsub_pd(a.n, b.n, c.n);
#else
  r = simde_mm256_addsub_pd(simde_mm256_mul_pd(a, b), c);
#endif

  return r;
}
#if defined(SIMDE_FMA_ENABLE_NATIVE_ALIASES)
#  define _mm_fmaddsub_pd(a, b) SIMDE__M256D_TO_NATIVE(simde_mm_fmaddsub_pd(SIMDE__M256D_FROM_NATIVE(a), SIMDE__M256D_FROM_NATIVE(b), SIMDE__M256D_FROM_NATIVE(c)))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128
simde_mm_fmaddsub_ps (simde__m128 a, simde__m128 b, simde__m128 c) {
  simde__m128 r;

#if defined(SIMDE_FMA_NATIVE)
  r.n = _mm_fmaddsub_ps(a.n, b.n, c.n);
#else
  r = simde_mm_addsub_ps(simde_mm_mul_ps(a, b), c);
#endif

  return r;
}
#if defined(SIMDE_FMA_ENABLE_NATIVE_ALIASES)
#  define _mm_fmaddsub_ps(a, b) SIMDE__M128_TO_NATIVE(simde_mm_fmaddsub_ps(SIMDE__M128_FROM_NATIVE(a), SIMDE__M128_FROM_NATIVE(b), SIMDE__M128_FROM_NATIVE(c)))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m256
simde_mm256_fmaddsub_ps (simde__m256 a, simde__m256 b, simde__m256 c) {
  simde__m256 r;

#if defined(SIMDE_FMA_NATIVE)
  r.n = _mm256_fmaddsub_ps(a.n, b.n, c.n);
#else
  r = simde_mm256_addsub_ps(simde_mm256_mul_ps(a, b), c);
#endif

  return r;
}
#if defined(SIMDE_FMA_ENABLE_NATIVE_ALIASES)
#  define _mm_fmaddsub_ps(a, b) SIMDE__M256_TO_NATIVE(simde_mm_fmaddsub_ps(SIMDE__M256_FROM_NATIVE(a), SIMDE__M256_FROM_NATIVE(b), SIMDE__M256_FROM_NATIVE(c)))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128d
simde_mm_fmsub_pd (simde__m128d a, simde__m128d b, simde__m128d c) {
  simde__m128d r;

#if defined(SIMDE_FMA_NATIVE)
  r.n = _mm_fmsub_pd(a.n, b.n, c.n);
#else
  r = simde_mm_sub_pd(simde_mm_mul_pd(a, b), c);
#endif

  return r;
}
#if defined(SIMDE_FMA_ENABLE_NATIVE_ALIASES)
#  define _mm_fmsub_pd(a, b) SIMDE__M128D_TO_NATIVE(simde_mm_fmsub_pd(SIMDE__M128D_FROM_NATIVE(a), SIMDE__M128D_FROM_NATIVE(b), SIMDE__M128D_FROM_NATIVE(c)))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m256d
simde_mm256_fmsub_pd (simde__m256d a, simde__m256d b, simde__m256d c) {
  simde__m256d r;

#if defined(SIMDE_FMA_NATIVE)
  r.n = _mm256_fmsub_pd(a.n, b.n, c.n);
#else
  r = simde_mm256_sub_pd(simde_mm256_mul_pd(a, b), c);
#endif

  return r;
}
#if defined(SIMDE_FMA_ENABLE_NATIVE_ALIASES)
#  define _mm_fmsub_pd(a, b) SIMDE__M256D_TO_NATIVE(simde_mm_fmsub_pd(SIMDE__M256D_FROM_NATIVE(a), SIMDE__M256D_FROM_NATIVE(b), SIMDE__M256D_FROM_NATIVE(c)))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128
simde_mm_fmsub_ps (simde__m128 a, simde__m128 b, simde__m128 c) {
  simde__m128 r;

#if defined(SIMDE_FMA_NATIVE)
  r.n = _mm_fmsub_ps(a.n, b.n, c.n);
#else
  r = simde_mm_sub_ps(simde_mm_mul_ps(a, b), c);
#endif

  return r;
}
#if defined(SIMDE_FMA_ENABLE_NATIVE_ALIASES)
#  define _mm_fmsub_ps(a, b) SIMDE__M128_TO_NATIVE(simde_mm_fmsub_ps(SIMDE__M128_FROM_NATIVE(a), SIMDE__M128_FROM_NATIVE(b), SIMDE__M128_FROM_NATIVE(c)))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m256
simde_mm256_fmsub_ps (simde__m256 a, simde__m256 b, simde__m256 c) {
  simde__m256 r;

#if defined(SIMDE_FMA_NATIVE)
  r.n = _mm256_fmsub_ps(a.n, b.n, c.n);
#else
  r = simde_mm256_sub_ps(simde_mm256_mul_ps(a, b), c);
#endif

  return r;
}
#if defined(SIMDE_FMA_ENABLE_NATIVE_ALIASES)
#  define _mm_fmsub_ps(a, b) SIMDE__M256_TO_NATIVE(simde_mm_fmsub_ps(SIMDE__M256_FROM_NATIVE(a), SIMDE__M256_FROM_NATIVE(b), SIMDE__M256_FROM_NATIVE(c)))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128d
simde_mm_fmsub_sd (simde__m128d a, simde__m128d b, simde__m128d c) {
  simde__m128d r;

#if defined(SIMDE_FMA_NATIVE)
  r.n = _mm_fmsub_sd(a.n, b.n, c.n);
#else
  r = simde_mm_sub_sd(simde_mm_mul_sd(a, b), c);
#endif

  return r;
}
#if defined(SIMDE_FMA_ENABLE_NATIVE_ALIASES)
#  define _mm_fmsub_sd(a, b) SIMDE__M128D_TO_NATIVE(simde_mm_fmsub_sd(SIMDE__M128D_FROM_NATIVE(a), SIMDE__M128D_FROM_NATIVE(b), SIMDE__M128D_FROM_NATIVE(c)))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128
simde_mm_fmsub_ss (simde__m128 a, simde__m128 b, simde__m128 c) {
  simde__m128 r;

#if defined(SIMDE_FMA_NATIVE)
  r.n = _mm_fmsub_ss(a.n, b.n, c.n);
#else
  r = simde_mm_sub_ss(simde_mm_mul_ss(a, b), c);
#endif

  return r;
}
#if defined(SIMDE_FMA_ENABLE_NATIVE_ALIASES)
#  define _mm_fmsub_ss(a, b) SIMDE__M128_TO_NATIVE(simde_mm_fmsub_ss(SIMDE__M128_FROM_NATIVE(a), SIMDE__M128_FROM_NATIVE(b), SIMDE__M128_FROM_NATIVE(c)))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128d
simde_mm_fmsubadd_pd (simde__m128d a, simde__m128d b, simde__m128d c) {
  simde__m128d r;

#if defined(SIMDE_FMA_NATIVE)
  r.n = _mm_fmsubadd_pd(a.n, b.n, c.n);
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.f64) / sizeof(r.f64[0])) ; i += 2) {
    r.f64[  i  ] = (a.f64[  i  ] * b.f64[  i  ]) + c.f64[  i  ];
    r.f64[i + 1] = (a.f64[i + 1] * b.f64[i + 1]) - c.f64[i + 1];
  }
#endif

  return r;
}
#if defined(SIMDE_FMA_ENABLE_NATIVE_ALIASES)
#  define _mm_fmsubadd_pd(a, b) SIMDE__M128D_TO_NATIVE(simde_mm_fmsubadd_pd(SIMDE__M128D_FROM_NATIVE(a), SIMDE__M128D_FROM_NATIVE(b), SIMDE__M128D_FROM_NATIVE(c)))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m256d
simde_mm256_fmsubadd_pd (simde__m256d a, simde__m256d b, simde__m256d c) {
  simde__m256d r;

#if defined(SIMDE_FMA_NATIVE)
  r.n = _mm256_fmsubadd_pd(a.n, b.n, c.n);
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.f64) / sizeof(r.f64[0])) ; i += 2) {
    r.f64[  i  ] = (a.f64[  i  ] * b.f64[  i  ]) + c.f64[  i  ];
    r.f64[i + 1] = (a.f64[i + 1] * b.f64[i + 1]) - c.f64[i + 1];
  }
#endif

  return r;
}
#if defined(SIMDE_FMA_ENABLE_NATIVE_ALIASES)
#  define _mm_fmsubadd_pd(a, b) SIMDE__M256D_TO_NATIVE(simde_mm_fmsubadd_pd(SIMDE__M256D_FROM_NATIVE(a), SIMDE__M256D_FROM_NATIVE(b), SIMDE__M256D_FROM_NATIVE(c)))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128
simde_mm_fmsubadd_ps (simde__m128 a, simde__m128 b, simde__m128 c) {
  simde__m128 r;

#if defined(SIMDE_FMA_NATIVE)
  r.n = _mm_fmsubadd_ps(a.n, b.n, c.n);
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.f32) / sizeof(r.f32[0])) ; i += 2) {
    r.f32[  i  ] = (a.f32[  i  ] * b.f32[  i  ]) + c.f32[  i  ];
    r.f32[i + 1] = (a.f32[i + 1] * b.f32[i + 1]) - c.f32[i + 1];
  }
#endif

  return r;
}
#if defined(SIMDE_FMA_ENABLE_NATIVE_ALIASES)
#  define _mm_fmsubadd_ps(a, b) SIMDE__M128_TO_NATIVE(simde_mm_fmsubadd_ps(SIMDE__M128_FROM_NATIVE(a), SIMDE__M128_FROM_NATIVE(b), SIMDE__M128_FROM_NATIVE(c)))
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m256
simde_mm256_fmsubadd_ps (simde__m256 a, simde__m256 b, simde__m256 c) {
  simde__m256 r;

#if defined(SIMDE_FMA_NATIVE)
  r.n = _mm256_fmsubadd_ps(a.n, b.n, c.n);
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r.f32) / sizeof(r.f32[0])) ; i += 2) {
    r.f32[  i  ] = (a.f32[  i  ] * b.f32[  i  ]) + c.f32[  i  ];
    r.f32[i + 1] = (a.f32[i + 1] * b.f32[i + 1]) - c.f32[i + 1];
  }
#endif

  return r;
}
#if defined(SIMDE_FMA_ENABLE_NATIVE_ALIASES)
#  define _mm_fmsubadd_ps(a, b) SIMDE__M256_TO_NATIVE(simde_mm_fmsubadd_ps(SIMDE__M256_FROM_NATIVE(a), SIMDE__M256_FROM_NATIVE(b), SIMDE__M256_FROM_NATIVE(c)))
#endif

SIMDE__END_DECLS

#endif /* !defined(SIMDE__FMA_H) */
