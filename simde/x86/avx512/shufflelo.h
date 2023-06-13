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
 *   2020      Christopher Moore <moore@free.fr>
 */

#if !defined(SIMDE_X86_AVX512_SHUFFLELO_H)
#define SIMDE_X86_AVX512_SHUFFLELO_H

#include "types.h"
#include "../avx2.h"
#include "mov.h"
#include "extract.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

#if defined(SIMDE_X86_AVX512BW_NATIVE)
#  define simde_mm512_shufflelo_epi16(a, imm8) _mm512_shufflelo_epi16(a, imm8)
#else
#  define simde_mm512_shufflelo_epi16(a, imm8) \
     simde_x_mm512_set_m128i( \
       simde_mm_shufflelo_epi16(simde_mm512_extracti32x4_epi32((a), 3), (imm8)), \
       simde_mm_shufflelo_epi16(simde_mm512_extracti32x4_epi32((a), 2), (imm8)), \
       simde_mm_shufflelo_epi16(simde_mm512_extracti32x4_epi32((a), 1), (imm8)), \
       simde_mm_shufflelo_epi16(simde_mm512_extracti32x4_epi32((a), 0), (imm8)))
#endif
#if defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES)
  #undef _mm512_shufflelo_epi16
  #define _mm512_shufflelo_epi16(a, imm8) simde_mm512_shufflelo_epi16(a, imm8)
#endif

SIMDE_END_DECLS_
HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_X86_AVX512_SHUFFLELO_H) */
