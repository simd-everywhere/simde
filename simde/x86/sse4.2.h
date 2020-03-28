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

#if !defined(SIMDE__SSE4_2_H)
#  if !defined(SIMDE__SSE4_2_H)
#    define SIMDE__SSE4_2_H
#  endif
#  include "sse4.1.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS

#  if defined(SIMDE_SSE4_2_NATIVE)
#    undef SIMDE_SSE4_2_NATIVE
#  endif
#  if defined(SIMDE_ARCH_X86_SSE4_2) && !defined(SIMDE_SSE4_2_NO_NATIVE) && !defined(SIMDE_NO_NATIVE)
#    define SIMDE_SSE4_2_NATIVE
#  elif defined(SIMDE_ARCH_ARM_NEON) && !defined(SIMDE_SSE4_2_NO_NEON) && !defined(SIMDE_NO_NEON)
#    define SIMDE_SSE4_2_NEON
#  elif defined(SIMDE_ARCH_POWER_ALTIVEC)
#    define SIMDE_SSE4_2_POWER_ALTIVEC
#  endif

#  if defined(SIMDE_SSE4_2_NATIVE) && !defined(SIMDE_SSE4_1_NATIVE)
#    if defined(SIMDE_SSE4_2_FORCE_NATIVE)
#      error Native SSE4.2 support requires native SSE4.1 support
#    else
       HEDLEY_WARNING("Native SSE4.2 support requires native SSE4.1 support, disabling")
#      undef SIMDE_SSE4_2_NATIVE
#    endif
#  elif defined(SIMDE_SSE4_2_NEON) && !defined(SIMDE_SSE4_1_NEON)
     HEDLEY_WARNING("SSE4.2 NEON support requires SSE4.1 NEON support, disabling")
#    undef SIMDE_SSE4_2_NEON
#  endif

#  if defined(SIMDE_SSE4_2_NATIVE)
#    include <nmmintrin.h>
#  else
#    if defined(SIMDE_SSE4_1_NEON)
#      include <arm_neon.h>
#    endif
#  endif

#  if !defined(SIMDE_SSE4_2_NATIVE) && defined(SIMDE_ENABLE_NATIVE_ALIASES)
#    define SIMDE_SSE4_2_ENABLE_NATIVE_ALIASES
#  endif

SIMDE__BEGIN_DECLS

SIMDE__FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_cmpgt_epi64 (simde__m128i a, simde__m128i b) {
#if defined(SIMDE_SSE4_2_NATIVE)
  return _mm_cmpgt_epi64(a, b);
#else
  simde__m128i_private
    r_,
    a_ = simde__m128i_to_private(a),
    b_ = simde__m128i_to_private(b);

  #if defined(SIMDE_SSE4_2_NEON) && defined(SIMDE_ARCH_AARCH64)
    r_.neon_i64 = vreinterpretq_s64_u64(vcgtq_s64(a_.neon_i64, b_.neon_i64));
  #elif defined(SIMDE_SSE4_2_POWER_ALTIVEC)
    r_.altivec_i64 = (vector signed long long) vec_cmpgt(a_.altivec_i64, b_.altivec_i64);
  #elif defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
    r_.i64 = HEDLEY_STATIC_CAST(__typeof__(r_.i64), a_.i64 > b_.i64);
  #else
    SIMDE__VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.i64) / sizeof(r_.i64[0])) ; i++) {
      r_.i64[i] = (a_.i64[i] > b_.i64[i]) ? ~INT64_C(0) : INT64_C(0);
    }
  #endif

  return simde__m128i_from_private(r_);
#endif
}
#if defined(SIMDE_SSE2_ENABLE_NATIVE_ALIASES)
#  define _mm_cmpgt_epi64(a, b) simde_mm_cmpgt_epi64(a, b)
#endif

SIMDE__END_DECLS

HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE__SSE4_2_H) */
