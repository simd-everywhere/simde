/* Copyright (c) 2017-2020 Evan Nemerson <evan@nemerson.com>
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

#if !defined(SIMDE_NEON_H)
#  define SIMDE_INSIDE_NEON_H
#  if !defined(SIMDE_NEON_H)
#    define SIMDE_NEON_H
#  endif
#  include "../simde-common.h"

#  if defined(SIMDE_NEON_FORCE_NATIVE)
#    define SIMDE_NEON_NATIVE
#  elif defined(__ARM_NEON) && !defined(SIMDE_NEON_NO_NATIVE) && !defined(SIMDE_NO_NATIVE)
#    define SIMDE_NEON_NATIVE
#  endif

#  if defined(SIMDE_NEON64_FORCE_NATIVE)
#    define SIMDE_NEON64_NATIVE
#  elif defined(SIMDE_ARCH_AARCH64) && !defined(SIMDE_NEON64_NO_NATIVE) && !defined(SIMDE_NO_NATIVE)
#    define SIMDE_NEON64_NATIVE
#  endif

#  if defined(__MMX__) && !defined(SIMDE_NEON_NO_MMX) && !defined(SIMDE_NO_MMX)
#    define SIMDE_NEON_MMX
#    include <mmintrin.h>
#  endif
#  if defined(__SSE__) && !defined(SIMDE_NEON_NO_SSE) && !defined(SIMDE_NO_SSE)
#    define SIMDE_NEON_SSE
#    include <xmmintrin.h>
#  endif
#  if defined(__SSE2__) && !defined(SIMDE_NEON_NO_SSE2) && !defined(SIMDE_NO_SSE2)
#    define SIMDE_NEON_SSE2
#    include <emmintrin.h>
#  endif
#  if defined(__wasm_simd128__) && !defined(SIMDE_NEON_NO_WASM_SIMD128) && !defined(SIMDE_NO_WASM_SIMD128)
#    define SIMDE_NEON_WASM_SIMD128
#    include <wasm_simd128.h>
#  endif


#  if defined(SIMDE_NEON_NATIVE)
#    include <arm_neon.h>
#  endif
#  include <stdint.h>

SIMDE_BEGIN_DECLS_

#include "neon/int8x8.h"
#include "neon/int16x4.h"
#include "neon/int32x2.h"
#include "neon/int64x1.h"
#include "neon/uint8x8.h"
#include "neon/uint16x4.h"
#include "neon/uint32x2.h"
#include "neon/uint64x1.h"
#include "neon/float32x2.h"
#include "neon/float64x1.h"

#include "neon/int8x16.h"
#include "neon/int16x8.h"
#include "neon/int32x4.h"
#include "neon/int64x2.h"
#include "neon/uint8x16.h"
#include "neon/uint16x8.h"
#include "neon/uint32x4.h"
#include "neon/uint64x2.h"
#include "neon/float32x4.h"
#include "neon/float64x2.h"

SIMDE_FUNCTION_ATTRIBUTES
int8_t
simde_vget_lane_s8(simde_int8x8_t v, const int lane) {
  return v.i8[lane];
}
#if defined(SIMDE_NEON_NATIVE)
#  define simde_vget_lane_s8(v, lane) vget_lane_s8(v.n, lane)
#endif

SIMDE_END_DECLS_

#undef SIMDE_INSIDE_NEON_H
#endif /* !defined(SIMDE_NEON_H) */
