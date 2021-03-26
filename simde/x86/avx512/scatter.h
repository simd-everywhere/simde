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
 *   2021      Andrew Rodriguez <anrodriguez@linkedin.com>
 */

#if !defined(SIMDE_X86_AVX512_SCATTER_H)
#define SIMDE_X86_AVX512_SCATTER_H

#include "types.h"
#include "mov.h"
#include "mov_mask.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

inline void simde_mm512_mask_i32scatter_epi64(void* base, simde__mmask8 k, simde__m256i index, simde__m512i a, int scale){
  simde__m256i_private
    index_ = simde__m256i_to_private(index);
  simde__m512i_private
    a_ = simde__m512i_to_private(a);

  for (size_t i = 0; i < (sizeof(a_.u64) / sizeof(a_.u64[0])) ; i++) {
    if (k & (UINT64_C(1) << i)) {
      *(uint64_t*)(&((uint8_t*)base)[index_.u32[i] * scale]) = a_.u64[i];
    }
  }
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_i32scatter_epi64
  #define _mm512_mask_i32scatter_epi64(base, k, index, a, scale) simde_mm512_mask_i32scatter_epi64(base, k, index,a, scale)
#endif

SIMDE_END_DECLS_
HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_X86_AVX512_SCATTER_H) */
