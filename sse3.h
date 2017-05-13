/* Copyright (c) 2017 Evan Nemerson <evan@nemerson.com>
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
 */

#if !defined(SIMDE__SSE3_H)
#  if !defined(SIMDE__SSE3_H)
#    define SIMDE__SSE3_H
#  endif
#  include "sse2.h"

#  if defined(SIMDE_SSE3_NATIVE)
#    undef SIMDE_SSE3_NATIVE
#  endif
#  if defined(SIMDE_SSE3_FORCE_NATIVE)
#    define SIMDE_SSE3_NATIVE
#  elif defined(__SSE3__) && (!defined(SIMDE_SSE3_NO_NATIVE) && !defined(SIMDE_NO_NATIVE))
#    define SIMDE_SSE3_NATIVE
#  elif defined(__ARM_NEON) && !defined(SIMDE_SSE3_NO_NEON) && !defined(SIMDE_NO_NEON)
#    define SIMDE_SSE3_NEON
#  endif

#  if defined(SIMDE_SSE3_NATIVE) && !defined(SIMDE_SSE2_NATIVE)
#    if defined(SIMDE_SSE3_FORCE_NATIVE)
#      error Native SSE3 support requires native SSE2 support
#    else
#      warning Native SSE3 support requires native SSE2 support, disabling
#      undef SIMDE_SSE3_NATIVE
#    endif
#  elif defined(SIMDE_SSE3_NEON) && !defined(SIMDE_SSE2_NEON)
#    warning SSE3 NEON support requires SSE2 NEON support, disabling
#    undef SIMDE_SSE3_NEON
#  endif

#  if defined(SIMDE_SSE3_NATIVE)
#    include <pmmintrin.h>
#  endif

SIMDE__BEGIN_DECLS

SIMDE__FUNCTION_ATTRIBUTES
simde__m128
simde_mm_hadd_ps (simde__m128 a, simde__m128 b) {
#if defined(SIMDE_SSE3_NATIVE)
  return SIMDE__M128_C(_mm_hadd_ps(a.n, b.n));
#else
  simde__m128 r;
  r.f32[0] = a.f32[0] + a.f32[1];
  r.f32[1] = a.f32[2] + a.f32[3];
  r.f32[2] = b.f32[0] + b.f32[1];
  r.f32[3] = b.f32[2] + b.f32[3];
  return r;
#endif
}

SIMDE__END_DECLS

#endif /* !defined(SIMDE__SSE3_H) */
