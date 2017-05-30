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
 *   2017      Evan Nemerson <evan@nemerson.com>
 */

#if !defined(SIMDE__EM_H)
#  define SIMDE__EM_H
#  define SIMDE__EM_H_INSIDE
#  include "../simde-common.h"

#  if defined(SIMDE_EM_NATIVE)
#    undef SIMDE_EM_NATIVE
#  endif
#  if defined(SIMDE_EM_FORCE_NATIVE)
#    define SIMDE_EM_NATIVE
#  elif defined(__EMSCRIPTEN__) && !defined(SIMDE_EM_NO_NATIVE) && !defined(SIMDE_NO_NATIVE)
#    define SIMDE_EM_NATIVE
#  elif defined(__SSE__) && !defined(SIMDE_EM_NO_SSE) && !defined(SIMDE_NO_SSE)
#    define SIMDE_EM_SSE
#    if defined(__SSE2__) && !defined(SIMDE_EM_NO_SSE2) && !defined(SIMDE_NO_SSE2)
#      define SIMDE_EM_SSE2
#    endif
#  elif defined(__ARM_NEON) && !defined(SIMDE_EM_NO_NEON) && !defined(SIMDE_NO_NEON)
#    define SIMDE_EM_NEON
#  endif

#  if defined(SIMDE_EM_NATIVE)
#    include <emscripten/vector.h>
#  elif defined(SIMDE_EM_SSE)
#    if defined(__SSE4_1__)
#      include <smmintrin.h>
#    else
#      include <emmintrin.h>
#    endif
#  elif defined(SIMDE_EM_NEON)
#    include <arm_neon.h>
#  endif

SIMDE__BEGIN_DECLS

typedef SIMDE__ALIGN(16) union {
#if defined(SIMDE__ENABLE_GCC_VEC_EXT)
  int32_t       v __attribute__((__vector_size__(16), __may_alias__));
#else
  int32_t       v[4];
#endif

#if defined(SIMDE_EM_NATIVE)
  int32x4       n;
#elif defined(SIMDE_EM_SSE2)
  __m128i       sse;
#elif defined(SIMDE_EM_NEON)
  int32x4_t     neon;
#endif
} simde_em_int32x4;

typedef SIMDE__ALIGN(16) union {
#if defined(SIMDE__ENABLE_GCC_VEC_EXT)
  simde_float32 v __attribute__((__vector_size__(16), __may_alias__));
#else
  simde_float32 v[4];
#endif

#if defined(SIMDE_EM_NATIVE)
  float32x4     n;
#elif defined(SIMDE_EM_SSE)
  __m128        sse;
#elif defined(SIMDE_EM_NEON)
  float32x4_t   neon;
#endif
} simde_em_float32x4;

typedef SIMDE__ALIGN(16) union {
#if defined(SIMDE__ENABLE_GCC_VEC_EXT)
  int32_t       v __attribute__((__vector_size__(16), __may_alias__));
#else
  int32_t       v[4];
#endif

#if defined(SIMDE_EM_NATIVE)
  bool32x4      n;
#elif defined(SIMDE_EM_SSE2)
  __m128i       sse;
#elif defined(SIMDE_EM_NEON)
  int32x4_t     neon;
#endif
} simde_em_bool32x4;

#if defined(SIMDE_EM_NATIVE)
  HEDLEY_STATIC_ASSERT(sizeof(int32x4_t) == sizeof(simde_em_int32x4), "int32x4_t size doesn't match simde__m128i size");
  HEDLEY_STATIC_ASSERT(sizeof(float32x4_t) == sizeof(simde_em_float32x4), "float32x4_t size doesn't match simde__m128d size");
  HEDLEY_STATIC_ASSERT(sizeof(bool32x4_t) == sizeof(simde_em_bool32x4), "bool32x4_t size doesn't match simde__m128i size");
  #define SIMDE_EM_INT32X4_C(expr) ((simde_em_int32x4) { .n = (expr) })
  #define SIMDE_EM_FLOAT32X4_C(expr) ((simde_em_float32x4) { .n = (expr) })
  #define SIMDE_EM_BOOL32X4_C(expr) ((simde_em_bool32x4) { .n = (expr) })
#elif defined(SIMDE_EM_SSE)
  #define SIMDE_EM_FLOAT32X4_SSE_C(expr) ((simde_em_float32x4) { .sse = (expr) })
  #if defined(SIMDE_EM_SSE2)
    #define SIMDE_EM_INT32X4_SSE_C(expr) ((simde_em_int32x4) { .sse = (expr) })
    #define SIMDE_EM_BOOL32X4_SSE_C(expr) ((simde_em_bool32x4) { .sse = (expr) })
  #endif
#elif defined(SIMDE_EM_NEON)
  #define SIMDE_EM_INT32X4_NEON_C(expr) ((simde_em_int32x4) { .neon = (expr) })
  #define SIMDE_EM_FLOAT32X4_NEON_C(expr) ((simde_em_float32x4) { .neon = (expr) })
  #define SIMDE_EM_BOOL32X4_NEON_C(expr) ((simde_em_bool32x4) { .neon = (expr) })
  #define SIMDE_EM_BOOL32X4_NEON_UC(expr) ((simde_em_bool32x4) { .neon = vreinterpretq_s32_u32(expr) })
#endif
HEDLEY_STATIC_ASSERT(16 == sizeof(simde_em_int32x4), "simde_em_int32x4 size incorrect");
HEDLEY_STATIC_ASSERT(16 == sizeof(simde_em_float32x4), "simde_em_float32x4 size incorrect");
HEDLEY_STATIC_ASSERT(16 == sizeof(simde_em_bool32x4), "simde_em_bool32x4 size incorrect");

#include "int32x4.h"
#include "float32x4.h"
#include "bool32x4.h"

SIMDE__END_DECLS

#undef SIMDE__EM_H_INSIDE
#endif /* !defined(SIMDE__EM_H) */
