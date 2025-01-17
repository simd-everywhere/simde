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
 *   2023      Michael R. Crusoe <crusoe@debian.org>
 */

#if !defined(SIMDE_X86_AVX512_ALIGN_H)
#define SIMDE_X86_AVX512_ALIGN_H

#include "types.h"
#include "../avx2.h"
#include "mov.h"
#include "extract.h"

#include <stdio.h>

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_


SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_alignr_epi32 (simde__m512i a, simde__m512i b, const int imm8){
  simde__m512i_private
      a_p = simde__m512i_to_private(a),
      b_p = simde__m512i_to_private(b),
      r_p;

  size_t len = sizeof(a_p)/sizeof(a_p.i32[0]);

  for (size_t i = 0; i < (0xF & imm8); i++) {
    r_p.i32[len-i-1] = a_p.i32[(0xF & imm8) - i - 1];
  }

  for (size_t i = (imm8 & 0xF), j=0; i < len; i++) {
    r_p.i32[len - i - 1] = b_p.i32[len - j - 1];
    j++;
  }

  return simde__m512i_from_private(r_p);
}

#if defined(SIMDE_X86_AVX512F_NATIVE)
  #define simde_mm512_alignr_epi32(a, b, imm8) _mm512_alignr_epi32(a, b, imm8);
#endif

SIMDE_END_DECLS_
HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_X86_AVX512_ALGIN_H) */
