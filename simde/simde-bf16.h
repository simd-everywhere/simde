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
 *   2023      Yi-Yen Chung <eric681@andestech.com> (Copyright owned by Andes Technology)
 */

#include "hedley.h"
#include "simde-common.h"
#include "simde-detect-clang.h"

#if !defined(SIMDE_BFLOAT16_H)
#define SIMDE_BFLOAT16_H

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

/* This implementations is referenced by simde-f16.h */

/* Portable version which should work on pretty much any compiler.
 * Obviously you can't rely on compiler support for things like
 * conversion to/from 32-bit floats, so make sure you always use the
 * functions and macros in this file!
 */
#define SIMDE_BFLOAT16_API_PORTABLE 1
/* _Float16, per C standard (TS 18661-3;
 * <http://www.open-std.org/jtc1/sc22/wg14/www/docs/n1945.pdf>). */
//#define SIMDE_BFLOAT16_API_FLOAT16 2
/* clang >= 6.0 supports __fp16 as an interchange format on all
 * targets, but only allows you to use them for arguments and return
 * values on targets which have defined an ABI.  We get around the
 * restriction by wrapping the __fp16 in a struct, but we can't do
 * that on Arm since it would break compatibility with the NEON F16
 * functions. */
//#define SIMDE_BFLOAT16_API_FP16_NO_ABI 3
/* This is basically __bf16 as specified by Arm, where arugments and
 * return values are raw __fp16 values not structs. */
#define SIMDE_BFLOAT16_API_BF16 4

/* Choosing an implementation.  This is a bit rough, but I don't have
 * any ideas on how to improve it.  If you do, patches are definitely
 * welcome. */
// [TODO] Add conditions to detect whether the compiler supports the bf16 type.
#if !defined(SIMDE_BFLOAT16_API)
  #if defined(SIMDE_ARM_NEON_BF16)
    #define SIMDE_BFLOAT16_API SIMDE_BFLOAT16_API_BF16
  #else
    #define SIMDE_BFLOAT16_API SIMDE_BFLOAT16_API_PORTABLE
  #endif
#endif

//#if SIMDE_FLOAT16_API == SIMDE_FLOAT16_API_FLOAT16
//  typedef _Float16 simde_float16;
//  #define SIMDE_FLOAT16_IS_SCALAR 1
//  #if !defined(__cplusplus)
//    #define SIMDE_FLOAT16_C(value) value##f16
//  #else
//    #define SIMDE_FLOAT16_C(value) HEDLEY_STATIC_CAST(_Float16, (value))
//  #endif
//#elif SIMDE_FLOAT16_API == SIMDE_FLOAT16_API_FP16_NO_ABI
//  typedef struct { __fp16 value; } simde_float16;
//  #if defined(SIMDE_STATEMENT_EXPR_) && !defined(SIMDE_TESTS_H)
//    #define SIMDE_FLOAT16_C(value) (__extension__({ ((simde_float16) { HEDLEY_DIAGNOSTIC_PUSH SIMDE_DIAGNOSTIC_DISABLE_C99_EXTENSIONS_ HEDLEY_STATIC_CAST(__fp16, (value)) }); HEDLEY_DIAGNOSTIC_POP }))
//  #else
//    #define SIMDE_FLOAT16_C(value) ((simde_float16) { HEDLEY_STATIC_CAST(__fp16, (value)) })
//    #define SIMDE_FLOAT16_IS_SCALAR 1
//  #endif
// [TODO] Currently are not implementing C implementations on bf16-related intrinsics.
#if SIMDE_BFLOAT16_API == SIMDE_BFLOAT16_API_BF16
  #include <arm_bf16.h>
  typedef __bf16 simde_bfloat16;
#elif SIMDE_BFLOAT16_API == SIMDE_BFLOAT16_API_PORTABLE
  typedef struct { uint16_t value; } simde_bfloat16;
#else
  #error No 16-bit floating point API.
#endif

/* Reinterpret -- you *generally* shouldn't need these, they're really
 * intended for internal use.  However, on x86 half-precision floats
 * get stuffed into a __m128i/__m256i, so it may be useful. */

/* Conversion -- convert between single-precision and brain half-precision
 * floats. */
static HEDLEY_ALWAYS_INLINE HEDLEY_CONST
simde_bfloat16
simde_bfloat16_from_float32 (simde_float32 value) {
  simde_bfloat16 res;
  char* src = HEDLEY_REINTERPRET_CAST(char*, &value);

#if SIMDE_ENDIAN_ORDER == SIMDE_ENDIAN_LITTLE
  simde_memcpy(&res, src+2, sizeof(res));
#else
  simde_memcpy(&res, src, sizeof(res));
#endif

  return res;
}

static HEDLEY_ALWAYS_INLINE HEDLEY_CONST
simde_float32
simde_bfloat16_to_float32 (simde_bfloat16 value) {
  simde_float32 res = 0;
  char* _res = HEDLEY_REINTERPRET_CAST(char*, &res);

#if SIMDE_ENDIAN_ORDER == SIMDE_ENDIAN_LITTLE
  simde_memcpy(_res+2, &value, sizeof(value));
#else
  simde_memcpy(_res, &value, sizeof(value));
#endif

  return res;
}

SIMDE_DEFINE_CONVERSION_FUNCTION_(simde_uint16_as_bfloat16, simde_bfloat16,      uint16_t)

#define SIMDE_NANBF simde_uint16_as_bfloat16(0xFFC1) // a quiet Not-a-Number
#define SIMDE_INFINITYBF simde_uint16_as_bfloat16(0x7F80)
#define SIMDE_NINFINITYBF simde_uint16_as_bfloat16(0xFF80)

#ifdef SIMDE_BFLOAT16_C
  #define SIMDE_BFLOAT16_VALUE(value) SIMDE_BFLOAT16_C(value)
#else
  #define SIMDE_BFLOAT16_VALUE(value) simde_bfloat16_from_float32(SIMDE_FLOAT32_C(value))
#endif

#if !defined(simde_isinfbf) && defined(simde_math_isinff)
  #define simde_isinfbf(a) simde_math_isinff(simde_bfloat16_to_float32(a))
#endif
#if !defined(simde_isnanbf) && defined(simde_math_isnanf)
  #define simde_isnanbf(a) simde_math_isnanf(simde_bfloat16_to_float32(a))
#endif

SIMDE_END_DECLS_
HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_BFLOAT16_H) */
