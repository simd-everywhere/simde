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
 *   2021      Zhi An Ng <zhin@google.com> (Copyright owned by Google, LLC)
 */

#if !defined(SIMDE_ARM_NEON_LD2_H)
#define SIMDE_ARM_NEON_LD2_H

#include "types.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
#if HEDLEY_GCC_VERSION_CHECK(7,0,0) && !HEDLEY_GCC_VERSION_CHECK(9,0,0)
  SIMDE_DIAGNOSTIC_DISABLE_MAYBE_UNINITIAZILED_
#endif
SIMDE_BEGIN_DECLS_

#if !defined(SIMDE_BUG_INTEL_857088)

SIMDE_FUNCTION_ATTRIBUTES
simde_uint8x8x2_t
simde_vld2_u8(uint8_t const ptr[HEDLEY_ARRAY_PARAM(8)]) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vld2_u8(ptr);
  #else
    simde_uint8x8_private r_[2];

    for (size_t i = 0; i < (sizeof(r_) / sizeof(r_[0])); i++) {
      for (size_t j = 0 ; j < (sizeof(r_[0].values) / sizeof(r_[0].values[0])) ; j++) {
        r_[i].values[j] = ptr[i + (j * (sizeof(r_) / sizeof(r_[0])))];
      }
    }

    simde_uint8x8x2_t r = { {
      simde_uint8x8_from_private(r_[0]),
      simde_uint8x8_from_private(r_[1]),
    } };

    return r;
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vld2_u8
  #define vld2_u8(a) simde_vld2_u8((a))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint16x4x2_t
simde_vld2_u16(uint16_t const ptr[HEDLEY_ARRAY_PARAM(8)]) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vld2_u16(ptr);
  #else
    simde_uint16x4_private r_[2];

    for (size_t i = 0; i < (sizeof(r_) / sizeof(r_[0])); i++) {
      for (size_t j = 0 ; j < (sizeof(r_[0].values) / sizeof(r_[0].values[0])) ; j++) {
        r_[i].values[j] = ptr[i + (j * (sizeof(r_) / sizeof(r_[0])))];
      }
    }

    simde_uint16x4x2_t r = { {
      simde_uint16x4_from_private(r_[0]),
      simde_uint16x4_from_private(r_[1]),
    } };

    return r;
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vld2_u16
  #define vld2_u16(a) simde_vld2_u16((a))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint32x2x2_t
simde_vld2_u32(uint32_t const ptr[HEDLEY_ARRAY_PARAM(8)]) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vld2_u32(ptr);
  #else
    simde_uint32x2_private r_[2];

    for (size_t i = 0; i < (sizeof(r_) / sizeof(r_[0])); i++) {
      for (size_t j = 0 ; j < (sizeof(r_[0].values) / sizeof(r_[0].values[0])) ; j++) {
        r_[i].values[j] = ptr[i + (j * (sizeof(r_) / sizeof(r_[0])))];
      }
    }

    simde_uint32x2x2_t r = { {
      simde_uint32x2_from_private(r_[0]),
      simde_uint32x2_from_private(r_[1]),
    } };

    return r;
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vld2_u32
  #define vld2_u32(a) simde_vld2_u32((a))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint8x16x2_t
simde_vld2q_u8(uint8_t const ptr[HEDLEY_ARRAY_PARAM(8)]) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vld2q_u8(ptr);
  #else
    simde_uint8x16_private r_[2];

    for (size_t i = 0; i < (sizeof(r_) / sizeof(r_[0])); i++) {
      for (size_t j = 0 ; j < (sizeof(r_[0].values) / sizeof(r_[0].values[0])) ; j++) {
        r_[i].values[j] = ptr[i + (j * (sizeof(r_) / sizeof(r_[0])))];
      }
    }

    simde_uint8x16x2_t r = { {
      simde_uint8x16_from_private(r_[0]),
      simde_uint8x16_from_private(r_[1]),
    } };

    return r;
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vld2q_u8
  #define vld2q_u8(a) simde_vld2q_u8((a))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint16x8x2_t
simde_vld2q_u16(uint16_t const ptr[HEDLEY_ARRAY_PARAM(8)]) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vld2q_u16(ptr);
  #else
    simde_uint16x8_private r_[2];

    for (size_t i = 0; i < (sizeof(r_) / sizeof(r_[0])); i++) {
      for (size_t j = 0 ; j < (sizeof(r_[0].values) / sizeof(r_[0].values[0])) ; j++) {
        r_[i].values[j] = ptr[i + (j * (sizeof(r_) / sizeof(r_[0])))];
      }
    }

    simde_uint16x8x2_t r = { {
      simde_uint16x8_from_private(r_[0]),
      simde_uint16x8_from_private(r_[1]),
    } };

    return r;
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vld2q_u16
  #define vld2q_u16(a) simde_vld2q_u16((a))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint32x4x2_t
simde_vld2q_u32(uint32_t const ptr[HEDLEY_ARRAY_PARAM(8)]) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vld2q_u32(ptr);
  #else
    simde_uint32x4_private r_[2];

    for (size_t i = 0; i < (sizeof(r_) / sizeof(r_[0])); i++) {
      for (size_t j = 0 ; j < (sizeof(r_[0].values) / sizeof(r_[0].values[0])) ; j++) {
        r_[i].values[j] = ptr[i + (j * (sizeof(r_) / sizeof(r_[0])))];
      }
    }

    simde_uint32x4x2_t r = { {
      simde_uint32x4_from_private(r_[0]),
      simde_uint32x4_from_private(r_[1]),
    } };

    return r;
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vld2q_u32
  #define vld2q_u32(a) simde_vld2q_u32((a))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_float32x4x2_t
simde_vld2q_f32(simde_float32_t const ptr[HEDLEY_ARRAY_PARAM(8)]) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vld2q_f32(ptr);
  #else
    simde_float32x4_private r_[2];

    for (size_t i = 0; i < (sizeof(r_) / sizeof(r_[0])); i++) {
      for (size_t j = 0 ; j < (sizeof(r_[0].values) / sizeof(r_[0].values[0])) ; j++) {
        r_[i].values[j] = ptr[i + (j * (sizeof(r_) / sizeof(r_[0])))];
      }
    }

    simde_float32x4x2_t r = { {
      simde_float32x4_from_private(r_[0]),
      simde_float32x4_from_private(r_[1]),
    } };

    return r;
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vld2q_f32
  #define vld2q_f32(a) simde_vld2q_f32((a))
#endif

#endif /* !defined(SIMDE_BUG_INTEL_857088) */

SIMDE_END_DECLS_
HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_ARM_NEON_LD2_H) */
