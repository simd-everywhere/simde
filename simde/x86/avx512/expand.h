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
 *   2021      Evan Nemerson <evan@nemerson.com>
 *   2025      Michael R. Crusoe <crusoe@debian.org>
 */

#if !defined(SIMDE_X86_AVX512_EXPAND_H)
#define SIMDE_X86_AVX512_EXPAND_H

#include "types.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_mask_expand_epi8(simde__m128i src, simde__mmask16 k, simde__m128i a) {
  #if defined(SIMDE_X864_AVX512VBMI2_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm_mask_expand_epi8(src, k, a);
  #else
    simde__m128i_private
      a_ = simde__m128i_to_private(a),
      src_ = simde__m128i_to_private(src);
    simde__m128i_private r_;

    size_t src_idx = 0;
    for (size_t i = 0; i < (sizeof(r_.i8) / sizeof(r_.i8[0])) ; i++) {
      if (k & (UINT64_C(1) << i)) {
        r_.i8[i] = a_.i8[src_idx++];
      } else {
        r_.i8[i] = src_.i8[i];
      }
    }

    return simde__m128i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512VBMI2_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm_mask_expand_epi8
  #define _mm_mask_expand_epi8(src, k, a) simde_mm_mask_expand_epi8((src), (k), (a))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_maskz_expand_epi8(simde__mmask16 k, simde__m128i a) {
  #if defined(SIMDE_X864_AVX512VBMI2_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm_maskz_expand_epi8(k, a);
  #else
    simde__m128i_private
      a_ = simde__m128i_to_private(a),
      r_;

    size_t src_idx = 0;
    for (size_t i = 0; i < (sizeof(r_.i8) / sizeof(r_.i8[0])) ; i++) {
      if (k & (UINT64_C(1) << i)) {
        r_.i8[i] = a_.i8[src_idx++];
      } else {
        r_.i8[i] = INT8_C(0);
      }
    }

    return simde__m128i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512VBMI2_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm_maskz_expand_epi8
  #define _mm_maskz_expand_epi8(k, a) simde_mm_maskz_expand_epi8((k), (a))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_mask_expand_epi8(simde__m256i src, simde__mmask32 k, simde__m256i a) {
  #if defined(SIMDE_X864_AVX512VBMI2_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm256_mask_expand_epi8(src, k, a);
  #else
    simde__m256i_private
      a_ = simde__m256i_to_private(a),
      src_ = simde__m256i_to_private(src);
    simde__m256i_private r_;

    size_t src_idx = 0;
    for (size_t i = 0; i < (sizeof(r_.i8) / sizeof(r_.i8[0])) ; i++) {
      if (k & (UINT64_C(1) << i)) {
        r_.i8[i] = a_.i8[src_idx++];
      } else {
        r_.i8[i] = src_.i8[i];
      }
    }

    return simde__m256i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512VBMI2_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm256_mask_expand_epi8
  #define _mm256_mask_expand_epi8(src, k, a) simde_mm256_mask_expand_epi8((src), (k), (a))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_maskz_expand_epi8(simde__mmask32 k, simde__m256i a) {
  #if defined(SIMDE_X864_AVX512VBMI2_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm256_maskz_expand_epi8(k, a);
  #else
    simde__m256i_private
      a_ = simde__m256i_to_private(a),
      r_;

    size_t src_idx = 0;
    for (size_t i = 0; i < (sizeof(r_.i8) / sizeof(r_.i8[0])) ; i++) {
      if (k & (UINT64_C(1) << i)) {
        r_.i8[i] = a_.i8[src_idx++];
      } else {
        r_.i8[i] = INT8_C(0);
      }
    }

    return simde__m256i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512VBMI2_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm256_maskz_expand_epi8
  #define _mm256_maskz_expand_epi8(k, a) simde_mm256_maskz_expand_epi8((k), (a))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_mask_expand_epi8(simde__m512i src, simde__mmask64 k, simde__m512i a) {
  #if defined(SIMDE_X864_AVX512VBMI2_NATIVE)
    return _mm512_mask_expand_epi8(src, k, a);
  #else
    simde__m512i_private
      a_ = simde__m512i_to_private(a),
      src_ = simde__m512i_to_private(src);
    simde__m512i_private r_;

    size_t src_idx = 0;
    for (size_t i = 0; i < (sizeof(r_.i8) / sizeof(r_.i8[0])) ; i++) {
      if (k & (UINT64_C(1) << i)) {
        r_.i8[i] = a_.i8[src_idx++];
      } else {
        r_.i8[i] = src_.i8[i];
      }
    }

    return simde__m512i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512VBMI2_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_expand_epi8
  #define _mm512_mask_expand_epi8(src, k, a) simde_mm512_mask_expand_epi8((src), (k), (a))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_maskz_expand_epi8(simde__mmask64 k, simde__m512i a) {
  #if defined(SIMDE_X864_AVX512VBMI2_NATIVE)
    return _mm512_maskz_expand_epi8(k, a);
  #else
    simde__m512i_private
      a_ = simde__m512i_to_private(a),
      r_;

    size_t src_idx = 0;
    for (size_t i = 0; i < (sizeof(r_.i8) / sizeof(r_.i8[0])) ; i++) {
      if (k & (UINT64_C(1) << i)) {
        r_.i8[i] = a_.i8[src_idx++];
      } else {
        r_.i8[i] = INT8_C(0);
      }
    }

    return simde__m512i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512VBMI2_ENABLE_NATIVE_ALIASES)
  #undef _mm512_maskz_expand_epi8
  #define _mm512_maskz_expand_epi8(k, a) simde_mm512_maskz_expand_epi8((k), (a))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_mask_expand_epi16(simde__m128i src, simde__mmask8 k, simde__m128i a) {
  #if defined(SIMDE_X864_AVX512VBMI2_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm_mask_expand_epi16(src, k, a);
  #else
    simde__m128i_private
      a_ = simde__m128i_to_private(a),
      src_ = simde__m128i_to_private(src);
    simde__m128i_private r_;

    size_t src_idx = 0;
    for (size_t i = 0; i < (sizeof(r_.i16) / sizeof(r_.i16[0])) ; i++) {
      if (k & (UINT64_C(1) << i)) {
        r_.i16[i] = a_.i16[src_idx++];
      } else {
        r_.i16[i] = src_.i16[i];
      }
    }

    return simde__m128i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512VBMI2_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm_mask_expand_epi16
  #define _mm_mask_expand_epi16(src, k, a) simde_mm_mask_expand_epi16((src), (k), (a))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_maskz_expand_epi16(simde__mmask8 k, simde__m128i a) {
  #if defined(SIMDE_X864_AVX512VBMI2_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm_maskz_expand_epi16(k, a);
  #else
    simde__m128i_private
      a_ = simde__m128i_to_private(a),
      r_;

    size_t src_idx = 0;
    for (size_t i = 0; i < (sizeof(r_.i16) / sizeof(r_.i16[0])) ; i++) {
      if (k & (UINT64_C(1) << i)) {
        r_.i16[i] = a_.i16[src_idx++];
      } else {
        r_.i16[i] = INT16_C(0);
      }
    }

    return simde__m128i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512VBMI2_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm_maskz_expand_epi16
  #define _mm_maskz_expand_epi16(k, a) simde_mm_maskz_expand_epi16((k), (a))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_mask_expand_epi16(simde__m256i src, simde__mmask16 k, simde__m256i a) {
  #if defined(SIMDE_X864_AVX512VBMI2_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm256_mask_expand_epi16(src, k, a);
  #else
    simde__m256i_private
      a_ = simde__m256i_to_private(a),
      src_ = simde__m256i_to_private(src);
    simde__m256i_private r_;

    size_t src_idx = 0;
    for (size_t i = 0; i < (sizeof(r_.i16) / sizeof(r_.i16[0])) ; i++) {
      if (k & (UINT64_C(1) << i)) {
        r_.i16[i] = a_.i16[src_idx++];
      } else {
        r_.i16[i] = src_.i16[i];
      }
    }

    return simde__m256i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512VBMI2_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm256_mask_expand_epi16
  #define _mm256_mask_expand_epi16(src, k, a) simde_mm256_mask_expand_epi16((src), (k), (a))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_maskz_expand_epi16(simde__mmask16 k, simde__m256i a) {
  #if defined(SIMDE_X864_AVX512VBMI2_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm_maskz_expand_epi16(k, a);
  #else
    simde__m256i_private
      a_ = simde__m256i_to_private(a),
      r_;

    size_t src_idx = 0;
    for (size_t i = 0; i < (sizeof(r_.i16) / sizeof(r_.i16[0])) ; i++) {
      if (k & (UINT64_C(1) << i)) {
        r_.i16[i] = a_.i16[src_idx++];
      } else {
        r_.i16[i] = INT16_C(0);
      }
    }

    return simde__m256i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512VBMI2_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm256_maskz_expand_epi16
  #define _mm256_maskz_expand_epi16(k, a) simde_mm256_maskz_expand_epi16((k), (a))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_mask_expand_epi16(simde__m512i src, simde__mmask32 k, simde__m512i a) {
  #if defined(SIMDE_X864_AVX512VBMI2_NATIVE)
    return _mm512_mask_expand_epi16(src, k, a);
  #else
    simde__m512i_private
      a_ = simde__m512i_to_private(a),
      src_ = simde__m512i_to_private(src);
    simde__m512i_private r_;

    size_t src_idx = 0;
    for (size_t i = 0; i < (sizeof(r_.i16) / sizeof(r_.i16[0])) ; i++) {
      if (k & (UINT64_C(1) << i)) {
        r_.i16[i] = a_.i16[src_idx++];
      } else {
        r_.i16[i] = src_.i16[i];
      }
    }

    return simde__m512i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512VBMI2_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_expand_epi16
  #define _mm512_mask_expand_epi16(src, k, a) simde_mm512_mask_expand_epi16((src), (k), (a))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_maskz_expand_epi16(simde__mmask32 k, simde__m512i a) {
  #if defined(SIMDE_X864_AVX512VBMI2_NATIVE)
    return _mm512_maskz_expand_epi16(k, a);
  #else
    simde__m512i_private
      a_ = simde__m512i_to_private(a),
      r_;

    size_t src_idx = 0;
    for (size_t i = 0; i < (sizeof(r_.i16) / sizeof(r_.i16[0])) ; i++) {
      if (k & (UINT64_C(1) << i)) {
        r_.i16[i] = a_.i16[src_idx++];
      } else {
        r_.i16[i] = INT16_C(0);
      }
    }

    return simde__m512i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512VBMI2_ENABLE_NATIVE_ALIASES)
  #undef _mm512_maskz_expand_epi16
  #define _mm512_maskz_expand_epi16(k, a) simde_mm512_maskz_expand_epi16((k), (a))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_mask_expand_epi32(simde__m128i src, simde__mmask8 k, simde__m128i a) {
  #if defined(SIMDE_X864_AVX512F_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm_mask_expand_epi32(src, k, a);
  #else
    simde__m128i_private
      a_ = simde__m128i_to_private(a),
      src_ = simde__m128i_to_private(src);
    simde__m128i_private r_;

    size_t src_idx = 0;
    for (size_t i = 0; i < (sizeof(r_.i32) / sizeof(r_.i32[0])) ; i++) {
      if (k & (UINT64_C(1) << i)) {
        r_.i32[i] = a_.i32[src_idx++];
      } else {
        r_.i32[i] = src_.i32[i];
      }
    }

    return simde__m128i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm_mask_expand_epi32
  #define _mm_mask_expand_epi32(src, k, a) simde_mm_mask_expand_epi32((src), (k), (a))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_maskz_expand_epi32(simde__mmask8 k, simde__m128i a) {
  #if defined(SIMDE_X864_AVX512F_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm_maskz_expand_epi32(k, a);
  #else
    simde__m128i_private
      a_ = simde__m128i_to_private(a),
      r_;

    size_t src_idx = 0;
    for (size_t i = 0; i < (sizeof(r_.i32) / sizeof(r_.i32[0])) ; i++) {
      if (k & (UINT64_C(1) << i)) {
        r_.i32[i] = a_.i32[src_idx++];
      } else {
        r_.i32[i] = INT32_C(0);
      }
    }

    return simde__m128i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm_maskz_expand_epi32
  #define _mm_maskz_expand_epi32(k, a) simde_mm_maskz_expand_epi32((k), (a))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_mask_expand_epi32(simde__m256i src, simde__mmask8 k, simde__m256i a) {
  #if defined(SIMDE_X864_AVX512F_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm256_mask_expand_epi32(src, k, a);
  #else
    simde__m256i_private
      a_ = simde__m256i_to_private(a),
      src_ = simde__m256i_to_private(src);
    simde__m256i_private r_;

    size_t src_idx = 0;
    for (size_t i = 0; i < (sizeof(r_.i32) / sizeof(r_.i32[0])) ; i++) {
      if (k & (UINT64_C(1) << i)) {
        r_.i32[i] = a_.i32[src_idx++];
      } else {
        r_.i32[i] = src_.i32[i];
      }
    }

    return simde__m256i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm256_mask_expand_epi32
  #define _mm256_mask_expand_epi32(src, k, a) simde_mm256_mask_expand_epi32((src), (k), (a))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_maskz_expand_epi32(simde__mmask8 k, simde__m256i a) {
  #if defined(SIMDE_X864_AVX512F_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm256_maskz_expand_epi32(k, a);
  #else
    simde__m256i_private
      a_ = simde__m256i_to_private(a),
      r_;

    size_t src_idx = 0;
    for (size_t i = 0; i < (sizeof(r_.i32) / sizeof(r_.i32[0])) ; i++) {
      if (k & (UINT64_C(1) << i)) {
        r_.i32[i] = a_.i32[src_idx++];
      } else {
        r_.i32[i] = INT32_C(0);
      }
    }

    return simde__m256i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm256_maskz_expand_epi32
  #define _mm256_maskz_expand_epi32(k, a) simde_mm256_maskz_expand_epi32((k), (a))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_mask_expand_epi32(simde__m512i src, simde__mmask16 k, simde__m512i a) {
  #if defined(SIMDE_X864_AVX512F_NATIVE)
    return _mm512_mask_expand_epi32(src, k, a);
  #else
    simde__m512i_private
      a_ = simde__m512i_to_private(a),
      src_ = simde__m512i_to_private(src);
    simde__m512i_private r_;

    size_t src_idx = 0;
    for (size_t i = 0; i < (sizeof(r_.i32) / sizeof(r_.i32[0])) ; i++) {
      if (k & (UINT64_C(1) << i)) {
        r_.i32[i] = a_.i32[src_idx++];
      } else {
        r_.i32[i] = src_.i32[i];
      }
    }

    return simde__m512i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_expand_epi32
  #define _mm512_mask_expand_epi32(src, k, a) simde_mm512_mask_expand_epi32((src), (k), (a))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_maskz_expand_epi32(simde__mmask16 k, simde__m512i a) {
  #if defined(SIMDE_X864_AVX512F_NATIVE)
    return _mm512_maskz_expand_epi32(k, a);
  #else
    simde__m512i_private
      a_ = simde__m512i_to_private(a),
      r_;

    size_t src_idx = 0;
    for (size_t i = 0; i < (sizeof(r_.i32) / sizeof(r_.i32[0])) ; i++) {
      if (k & (UINT64_C(1) << i)) {
        r_.i32[i] = a_.i32[src_idx++];
      } else {
        r_.i32[i] = INT32_C(0);
      }
    }

    return simde__m512i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_maskz_expand_epi32
  #define _mm512_maskz_expand_epi32(k, a) simde_mm512_maskz_expand_epi32((k), (a))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_mask_expand_epi64(simde__m128i src, simde__mmask8 k, simde__m128i a) {
  #if defined(SIMDE_X86_AVX512F_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm_mask_expand_epi64(src, k, a);
  #else
    simde__m128i_private
      a_ = simde__m128i_to_private(a),
      src_ = simde__m128i_to_private(src);
    simde__m128i_private r_;

    size_t src_idx = 0;
    for (size_t i = 0; i < (sizeof(r_.i64) / sizeof(r_.i64[0])) ; i++) {
      if (k & (UINT64_C(1) << i)) {
        r_.i64[i] = a_.i64[src_idx++];
      } else {
        r_.i64[i] = src_.i64[i];
      }
    }

    return simde__m128i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm_mask_expand_epi64
  #define _mm_mask_expand_epi64(src, k, a) simde_mm_mask_expand_epi64((src), (k), (a))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_maskz_expand_epi64(simde__mmask8 k, simde__m128i a) {
  #if defined(SIMDE_X86_AVX512F_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm_maskz_expand_epi64(k, a);
  #else
    simde__m128i_private
      a_ = simde__m128i_to_private(a),
      r_;

    size_t src_idx = 0;
    for (size_t i = 0; i < (sizeof(r_.i64) / sizeof(r_.i64[0])) ; i++) {
      if (k & (UINT64_C(1) << i)) {
        r_.i64[i] = a_.i64[src_idx++];
      } else {
        r_.i64[i] = INT64_C(0);
      }
    }

    return simde__m128i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm_maskz_expand_epi64
  #define _mm_maskz_expand_epi64(k, a) simde_mm_maskz_expand_epi64((k), (a))
#endif


SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_mask_expand_epi64(simde__m256i src, simde__mmask8 k, simde__m256i a) {
  #if defined(SIMDE_X86_AVX512F_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm256_mask_expand_epi64(src, k, a);
  #else
    simde__m256i_private
      a_ = simde__m256i_to_private(a),
      src_ = simde__m256i_to_private(src);
    simde__m256i_private r_;

    size_t src_idx = 0;
    for (size_t i = 0; i < (sizeof(r_.i64) / sizeof(r_.i64[0])) ; i++) {
      if (k & (UINT64_C(1) << i)) {
        r_.i64[i] = a_.i64[src_idx++];
      } else {
        r_.i64[i] = src_.i64[i];
      }
    }

    return simde__m256i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm256_mask_expand_epi64
  #define _mm256_mask_expand_epi64(src, k, a) simde_mm256_mask_expand_epi64((src), (k), (a))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_maskz_expand_epi64(simde__mmask8 k, simde__m256i a) {
  #if defined(SIMDE_X86_AVX512F_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm256_maskz_expand_epi64(k, a);
  #else
    simde__m256i_private
      a_ = simde__m256i_to_private(a),
      r_;

    size_t src_idx = 0;
    for (size_t i = 0; i < (sizeof(r_.i64) / sizeof(r_.i64[0])) ; i++) {
      if (k & (UINT64_C(1) << i)) {
        r_.i64[i] = a_.i64[src_idx++];
      } else {
        r_.i64[i] = INT64_C(0);
      }
    }

    return simde__m256i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm256_maskz_expand_epi64
  #define _mm256_maskz_expand_epi64(k, a) simde_mm256_maskz_expand_epi64((k), (a))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_mask_expand_epi64(simde__m512i src, simde__mmask8 k, simde__m512i a) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_mask_expand_epi64(src, k, a);
  #else
    simde__m512i_private
      a_ = simde__m512i_to_private(a),
      src_ = simde__m512i_to_private(src);
    simde__m512i_private r_;

    size_t src_idx = 0;
    for (size_t i = 0; i < (sizeof(r_.i64) / sizeof(r_.i64[0])) ; i++) {
      if (k & (UINT64_C(1) << i)) {
        r_.i64[i] = a_.i64[src_idx++];
      } else {
        r_.i64[i] = src_.i64[i];
      }
    }

    return simde__m512i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_expand_epi64
  #define _mm512_mask_expand_epi64(src, k, a) simde_mm512_mask_expand_epi64((src), (k), (a))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_maskz_expand_epi64(simde__mmask8 k, simde__m512i a) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_maskz_expand_epi64(k, a);
  #else
    simde__m512i_private
      a_ = simde__m512i_to_private(a),
      r_;

    size_t src_idx = 0;
    for (size_t i = 0; i < (sizeof(r_.i64) / sizeof(r_.i64[0])) ; i++) {
      if (k & (UINT64_C(1) << i)) {
        r_.i64[i] = a_.i64[src_idx++];
      } else {
        r_.i64[i] = INT64_C(0);
      }
    }

    return simde__m512i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_maskz_expand_epi64
  #define _mm512_maskz_expand_epi64(k, a) simde_mm512_maskz_expand_epi64((k), (a))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128
simde_mm_mask_expand_ps(simde__m128 src, simde__mmask8 k, simde__m128 a) {
  #if defined(SIMDE_X86_AVX512F_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm_mask_expand_ps(src, k, a);
  #else
    simde__m128_private
      a_ = simde__m128_to_private(a),
      src_ = simde__m128_to_private(src);
    simde__m128_private r_;

    size_t src_idx = 0;
    for (size_t i = 0; i < (sizeof(r_.f32) / sizeof(r_.f32[0])) ; i++) {
      if (k & (UINT64_C(1) << i)) {
        r_.f32[i] = a_.f32[src_idx++];
      } else {
        r_.f32[i] = src_.f32[i];
      }
    }

    return simde__m128_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm_mask_expand_ps
  #define _mm_mask_expand_ps(src, k, a) simde_mm_mask_expand_ps((src), (k), (a))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128
simde_mm_maskz_expand_ps(simde__mmask8 k, simde__m128 a) {
  #if defined(SIMDE_X86_AVX512F_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm_maskz_expand_ps(k, a);
  #else
    simde__m128_private
      a_ = simde__m128_to_private(a),
      r_;

    size_t src_idx = 0;
    for (size_t i = 0; i < (sizeof(r_.f32) / sizeof(r_.f32[0])) ; i++) {
      if (k & (UINT64_C(1) << i)) {
        r_.f32[i] = a_.f32[src_idx++];
      } else {
        r_.f32[i] = SIMDE_FLOAT32_C(0.0);
      }
    }

    return simde__m128_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm_maskz_expand_ps
  #define _mm_maskz_expand_ps(k, a) simde_mm_maskz_expand_ps((k), (a))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256
simde_mm256_mask_expand_ps(simde__m256 src, simde__mmask8 k, simde__m256 a) {
  #if defined(SIMDE_X86_AVX512F_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm256_mask_expand_ps(src, k, a);
  #else
    simde__m256_private
      a_ = simde__m256_to_private(a),
      src_ = simde__m256_to_private(src);
    simde__m256_private r_;

    size_t src_idx = 0;
    for (size_t i = 0; i < (sizeof(r_.f32) / sizeof(r_.f32[0])) ; i++) {
      if (k & (UINT64_C(1) << i)) {
        r_.f32[i] = a_.f32[src_idx++];
      } else {
        r_.f32[i] = src_.f32[i];
      }
    }

    return simde__m256_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm256_mask_expand_ps
  #define _mm256_mask_expand_ps(src, k, a) simde_mm256_mask_expand_ps((src), (k), (a))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256
simde_mm256_maskz_expand_ps(simde__mmask8 k, simde__m256 a) {
  #if defined(SIMDE_X86_AVX512F_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm256_maskz_expand_ps(k, a);
  #else
    simde__m256_private
      a_ = simde__m256_to_private(a),
      r_;

    size_t src_idx = 0;
    for (size_t i = 0; i < (sizeof(r_.f32) / sizeof(r_.f32[0])) ; i++) {
      if (k & (UINT64_C(1) << i)) {
        r_.f32[i] = a_.f32[src_idx++];
      } else {
        r_.f32[i] = SIMDE_FLOAT32_C(0.0);
      }
    }

    return simde__m256_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm256_maskz_expand_ps
  #define _mm256_maskz_expand_ps(k, a) simde_mm256_maskz_expand_ps((k), (a))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512
simde_mm512_mask_expand_ps(simde__m512 src, simde__mmask16 k, simde__m512 a) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_mask_expand_ps(src, k, a);
  #else
    simde__m512_private
      a_ = simde__m512_to_private(a),
      src_ = simde__m512_to_private(src);
    simde__m512_private r_;

    size_t src_idx = 0;
    for (size_t i = 0; i < (sizeof(r_.f32) / sizeof(r_.f32[0])) ; i++) {
      if (k & (UINT64_C(1) << i)) {
        r_.f32[i] = a_.f32[src_idx++];
      } else {
        r_.f32[i] = src_.f32[i];
      }
    }

    return simde__m512_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_expand_ps
  #define _mm512_mask_expand_ps(src, k, a) simde_mm512_mask_expand_ps((src), (k), (a))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512
simde_mm512_maskz_expand_ps(simde__mmask16 k, simde__m512 a) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_maskz_expand_ps(k, a);
  #else
    simde__m512_private
      a_ = simde__m512_to_private(a),
      r_;

    size_t src_idx = 0;
    for (size_t i = 0; i < (sizeof(r_.f32) / sizeof(r_.f32[0])) ; i++) {
      if (k & (UINT64_C(1) << i)) {
        r_.f32[i] = a_.f32[src_idx++];
      } else {
        r_.f32[i] = SIMDE_FLOAT32_C(0.0);
      }
    }

    return simde__m512_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_maskz_expand_ps
  #define _mm512_maskz_expand_ps(k, a) simde_mm512_maskz_expand_ps((k), (a))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128d
simde_mm_mask_expand_pd(simde__m128d src, simde__mmask8 k, simde__m128d a) {
  #if defined(SIMDE_X86_AVX512F_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm_mask_expand_pd(src, k, a);
  #else
    simde__m128d_private
      a_ = simde__m128d_to_private(a),
      src_ = simde__m128d_to_private(src);
    simde__m128d_private r_;

    size_t src_idx = 0;
    for (size_t i = 0; i < (sizeof(r_.f64) / sizeof(r_.f64[0])) ; i++) {
      if (k & (UINT64_C(1) << i)) {
        r_.f64[i] = a_.f64[src_idx++];
      } else {
        r_.f64[i] = src_.f64[i];
      }
    }

    return simde__m128d_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm_mask_expand_pd
  #define _mm_mask_expand_pd(src, k, a) simde_mm_mask_expand_pd((src), (k), (a))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128d
simde_mm_maskz_expand_pd(simde__mmask8 k, simde__m128d a) {
  #if defined(SIMDE_X86_AVX512F_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm_maskz_expand_pd(k, a);
  #else
    simde__m128d_private
      a_ = simde__m128d_to_private(a),
      r_;

    size_t src_idx = 0;
    for (size_t i = 0; i < (sizeof(r_.f64) / sizeof(r_.f64[0])) ; i++) {
      if (k & (UINT64_C(1) << i)) {
        r_.f64[i] = a_.f64[src_idx++];
      } else {
        r_.f64[i] = SIMDE_FLOAT64_C(0.0);
      }
    }

    return simde__m128d_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm_maskz_expand_pd
  #define _mm_maskz_expand_pd(k, a) simde_mm_maskz_expand_pd((k), (a))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256d
simde_mm256_mask_expand_pd(simde__m256d src, simde__mmask8 k, simde__m256d a) {
  #if defined(SIMDE_X86_AVX512F_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm256_mask_expand_pd(src, k, a);
  #else
    simde__m256d_private
      a_ = simde__m256d_to_private(a),
      src_ = simde__m256d_to_private(src);
    simde__m256d_private r_;

    size_t src_idx = 0;
    for (size_t i = 0; i < (sizeof(r_.f64) / sizeof(r_.f64[0])) ; i++) {
      if (k & (UINT64_C(1) << i)) {
        r_.f64[i] = a_.f64[src_idx++];
      } else {
        r_.f64[i] = src_.f64[i];
      }
    }

    return simde__m256d_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm256_mask_expand_pd
  #define _mm256_mask_expand_pd(src, k, a) simde_mm256_mask_expand_pd((src), (k), (a))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256d
simde_mm256_maskz_expand_pd(simde__mmask8 k, simde__m256d a) {
  #if defined(SIMDE_X86_AVX512F_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm256_maskz_expand_pd(k, a);
  #else
    simde__m256d_private
      a_ = simde__m256d_to_private(a),
      r_;

    size_t src_idx = 0;
    for (size_t i = 0; i < (sizeof(r_.f64) / sizeof(r_.f64[0])) ; i++) {
      if (k & (UINT64_C(1) << i)) {
        r_.f64[i] = a_.f64[src_idx++];
      } else {
        r_.f64[i] = SIMDE_FLOAT64_C(0.0);
      }
    }

    return simde__m256d_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm256_maskz_expand_pd
  #define _mm256_maskz_expand_pd(k, a) simde_mm256_maskz_expand_pd((k), (a))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512d
simde_mm512_mask_expand_pd(simde__m512d src, simde__mmask8 k, simde__m512d a) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_mask_expand_pd(src, k, a);
  #else
    simde__m512d_private
      a_ = simde__m512d_to_private(a),
      src_ = simde__m512d_to_private(src);
    simde__m512d_private r_;

    size_t src_idx = 0;
    for (size_t i = 0; i < (sizeof(r_.f64) / sizeof(r_.f64[0])) ; i++) {
      if (k & (UINT64_C(1) << i)) {
        r_.f64[i] = a_.f64[src_idx++];
      } else {
        r_.f64[i] = src_.f64[i];
      }
    }

    return simde__m512d_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_expand_pd
  #define _mm512_mask_expand_pd(src, k, a) simde_mm512_mask_expand_pd((src), (k), (a))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512d
simde_mm512_maskz_expand_pd(simde__mmask8 k, simde__m512d a) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_maskz_expand_pd(k, a);
  #else
    simde__m512d_private
      a_ = simde__m512d_to_private(a),
      r_;

    size_t src_idx = 0;
    for (size_t i = 0; i < (sizeof(r_.f64) / sizeof(r_.f64[0])) ; i++) {
      if (k & (UINT64_C(1) << i)) {
        r_.f64[i] = a_.f64[src_idx++];
      } else {
        r_.f64[i] = SIMDE_FLOAT64_C(0.0);
      }
    }

    return simde__m512d_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_maskz_expand_pd
  #define _mm512_maskz_expand_pd(k, a) simde_mm512_maskz_expand_pd((k), (a))
#endif

SIMDE_END_DECLS_
HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_X86_AVX512_EXPAND_H) */
