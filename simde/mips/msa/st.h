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
 *   2021      Evan Nemerson <evan@nemerson.com>
 */

#if !defined(SIMDE_MIPS_MSA_ST_H)
#define SIMDE_MIPS_MSA_ST_H

#include "types.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

SIMDE_FUNCTION_ATTRIBUTES
void
simde_msa_st_b(simde_v16i8 a, void * rs, const int s10)
    SIMDE_REQUIRE_CONSTANT_RANGE(s10, 0, 1023) {
  simde_memcpy(&(HEDLEY_REINTERPRET_CAST(int8_t*, rs)[s10]), &a, sizeof(a));
}
#if defined(SIMDE_MIPS_MSA_NATIVE)
  #define simde_msa_st_b(a, rs, s10) __msa_st_b((a), (rs), (s10))
#endif
#if defined(SIMDE_MIPS_MSA_ENABLE_NATIVE_ALIASES)
  #undef __msa_st_b
  #define __msa_st_b(a, rs, s10) simde_msa_st_b((a), (rs), (s10))
#endif

SIMDE_FUNCTION_ATTRIBUTES
void
simde_msa_st_h(simde_v8i16 a, void * rs, const int s10)
    SIMDE_REQUIRE_CONSTANT_RANGE(s10, 0, 1023)
    HEDLEY_REQUIRE_MSG((s10 % sizeof(int16_t)) == 0, "`s10' must be a multiple of sizeof(int16_t)") {
  simde_memcpy(&(HEDLEY_REINTERPRET_CAST(int8_t*, rs)[s10]), &a, sizeof(a));
}
#if defined(SIMDE_MIPS_MSA_NATIVE)
  #define simde_msa_st_h(a, rs, s10) __msa_st_h((a), (rs), (s10))
#endif
#if defined(SIMDE_MIPS_MSA_ENABLE_NATIVE_ALIASES)
  #undef __msa_st_h
  #define __msa_st_h(a, rs, s10) simde_msa_st_h((a), (rs), (s10))
#endif

SIMDE_FUNCTION_ATTRIBUTES
void
simde_msa_st_w(simde_v4i32 a, void * rs, const int s10)
    SIMDE_REQUIRE_CONSTANT_RANGE(s10, 0, 1023)
    HEDLEY_REQUIRE_MSG((s10 % sizeof(int32_t)) == 0, "`s10' must be a multiple of sizeof(int32_t)") {
  simde_memcpy(&(HEDLEY_REINTERPRET_CAST(int8_t*, rs)[s10]), &a, sizeof(a));
}
#if defined(SIMDE_MIPS_MSA_NATIVE)
  #define simde_msa_st_w(a, rs, s10) __msa_st_w((a), (rs), (s10))
#endif
#if defined(SIMDE_MIPS_MSA_ENABLE_NATIVE_ALIASES)
  #undef __msa_st_w
  #define __msa_st_w(a, rs, s10) simde_msa_st_w((a), (rs), (s10))
#endif

SIMDE_FUNCTION_ATTRIBUTES
void
simde_msa_st_d(simde_v2i64 a, void * rs, const int s10)
    SIMDE_REQUIRE_CONSTANT_RANGE(s10, 0, 1023)
    HEDLEY_REQUIRE_MSG((s10 % sizeof(int64_t)) == 0, "`s10' must be a multiple of sizeof(int64_t)") {
  simde_memcpy(&(HEDLEY_REINTERPRET_CAST(int8_t*, rs)[s10]), &a, sizeof(a));
}
#if defined(SIMDE_MIPS_MSA_NATIVE)
  #define simde_msa_st_d(a, rs, s10) __msa_st_d((a), (rs), (s10))
#endif
#if defined(SIMDE_MIPS_MSA_ENABLE_NATIVE_ALIASES)
  #undef __msa_st_d
  #define __msa_st_d(a, rs, s10) simde_msa_st_d((a), (rs), (s10))
#endif

SIMDE_END_DECLS_
HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_MIPS_MSA_ST_H) */
