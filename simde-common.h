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

#if !defined(SIMDE_COMMON_H)
#define SIMDE_COMMON_H

#include "hedley.h"

#define SIMDE__CONCAT(a,b) a##b
#define SIMDE__XCONCAT(a,b) SIMDE__CONCAT(a,b)
#define SIMDE__CONCAT3(a,b,c) a##b##c
#define SIMDE__XCONCAT3(a,b,c) SIMDE__CONCAT3(a,b,c)

#if defined(__GNUC__)
#  define SIMDE__ALIGN(alignment) __attribute__((aligned(alignment)))
#elif defined(_MSC_VER)
#  define SIMDE__ALIGN(alignment) __declspec(align(alignment))
#else
#  define SIMDE__ALIGN(alignment)
#endif

#if defined(__GNUC__)
#  define SIMDE__FUNCTION_ATTRIBUTES __attribute__((__always_inline__,__gnu_inline__)) static HEDLEY_INLINE
#else
#  define SIMDE__FUNCTION_ATTRIBUTES static HEDLEY_INLINE
#endif

#if !defined(SIMDE_PREFIX)
#  define SIMDE_PREFIX simde
#endif

#if !defined(SIMDE_PREFIX_U)
#  define SIMDE_PREFIX_U SIMDE__XCONCAT(SIMDE_PREFIX, _)
#endif

#if !defined(SIMDE__SYMBOL)
#  define SIMDE__SYMBOL(name) SIMDE__XCONCAT(SIMDE_PREFIX, name)
#endif

#if !defined(SIMDE__SYMBOL_U)
#  define SIMDE__SYMBOL_U(name) SIMDE__XCONCAT(SIMDE_PREFIX_U, name)
#endif

#endif /* SIMDE_COMMON_H */
