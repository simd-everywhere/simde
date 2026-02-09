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
 *   2017      Evan Nemerson <evan@nemerson.com>
 *   2020      Hidayat Khan <huk2209@gmail.com>
 *   2015-2026 SSE2NEON Contributors (https://github.com/DLTcollab/sse2neon, MIT)
 */

#if !defined(SIMDE_X86_SSE4_2_H)
#define SIMDE_X86_SSE4_2_H

#include "sse4.1.h"

#if defined(__ARM_ACLE) || (defined(__GNUC__) && defined(SIMDE_ARCH_ARM_CRC32))
  #include <arm_acle.h>
#endif
//                         ^^ Due to https://gcc.gnu.org/bugzilla/show_bug.cgi?id=70974

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

#if defined(SIMDE_X86_SSE4_2_NATIVE)
  #define SIMDE_SIDD_UBYTE_OPS _SIDD_UBYTE_OPS
  #define SIMDE_SIDD_UWORD_OPS _SIDD_UWORD_OPS
  #define SIMDE_SIDD_SBYTE_OPS _SIDD_SBYTE_OPS
  #define SIMDE_SIDD_SWORD_OPS _SIDD_SWORD_OPS
  #define SIMDE_SIDD_CMP_EQUAL_ANY _SIDD_CMP_EQUAL_ANY
  #define SIMDE_SIDD_CMP_RANGES _SIDD_CMP_RANGES
  #define SIMDE_SIDD_CMP_EQUAL_EACH _SIDD_CMP_EQUAL_EACH
  #define SIMDE_SIDD_CMP_EQUAL_ORDERED _SIDD_CMP_EQUAL_ORDERED
  #define SIMDE_SIDD_POSITIVE_POLARITY _SIDD_POSITIVE_POLARITY
  #define SIMDE_SIDD_NEGATIVE_POLARITY _SIDD_NEGATIVE_POLARITY
  #define SIMDE_SIDD_MASKED_POSITIVE_POLARITY _SIDD_MASKED_POSITIVE_POLARITY
  #define SIMDE_SIDD_MASKED_NEGATIVE_POLARITY _SIDD_MASKED_NEGATIVE_POLARITY
  #define SIMDE_SIDD_LEAST_SIGNIFICANT _SIDD_LEAST_SIGNIFICANT
  #define SIMDE_SIDD_MOST_SIGNIFICANT _SIDD_MOST_SIGNIFICANT
  #define SIMDE_SIDD_BIT_MASK _SIDD_BIT_MASK
  #define SIMDE_SIDD_UNIT_MASK _SIDD_UNIT_MASK
#else
  #define SIMDE_SIDD_UBYTE_OPS 0x00
  #define SIMDE_SIDD_UWORD_OPS 0x01
  #define SIMDE_SIDD_SBYTE_OPS 0x02
  #define SIMDE_SIDD_SWORD_OPS 0x03
  #define SIMDE_SIDD_CMP_EQUAL_ANY 0x00
  #define SIMDE_SIDD_CMP_RANGES 0x04
  #define SIMDE_SIDD_CMP_EQUAL_EACH 0x08
  #define SIMDE_SIDD_CMP_EQUAL_ORDERED 0x0c
  #define SIMDE_SIDD_POSITIVE_POLARITY 0x00
  #define SIMDE_SIDD_NEGATIVE_POLARITY 0x10
  #define SIMDE_SIDD_MASKED_POSITIVE_POLARITY 0x20
  #define SIMDE_SIDD_MASKED_NEGATIVE_POLARITY 0x30
  #define SIMDE_SIDD_LEAST_SIGNIFICANT 0x00
  #define SIMDE_SIDD_MOST_SIGNIFICANT 0x40
  #define SIMDE_SIDD_BIT_MASK 0x00
  #define SIMDE_SIDD_UNIT_MASK 0x40
#endif

#if defined(SIMDE_X86_SSE4_2_ENABLE_NATIVE_ALIASES) && !defined(_SIDD_UBYTE_OPS)
  #define _SIDD_UBYTE_OPS SIMDE_SIDD_UBYTE_OPS
  #define _SIDD_UWORD_OPS SIMDE_SIDD_UWORD_OPS
  #define _SIDD_SBYTE_OPS SIMDE_SIDD_SBYTE_OPS
  #define _SIDD_SWORD_OPS SIMDE_SIDD_SWORD_OPS
  #define _SIDD_CMP_EQUAL_ANY SIMDE_SIDD_CMP_EQUAL_ANY
  #define _SIDD_CMP_RANGES SIMDE_SIDD_CMP_RANGES
  #define _SIDD_CMP_EQUAL_EACH SIMDE_SIDD_CMP_EQUAL_EACH
  #define _SIDD_CMP_EQUAL_ORDERED SIMDE_SIDD_CMP_EQUAL_ORDERED
  #define _SIDD_POSITIVE_POLARITY SIMDE_SIDD_POSITIVE_POLARITY
  #define _SIDD_NEGATIVE_POLARITY SIMDE_SIDD_NEGATIVE_POLARITY
  #define _SIDD_MASKED_POSITIVE_POLARITY SIMDE_SIDD_MASKED_POSITIVE_POLARITY
  #define _SIDD_MASKED_NEGATIVE_POLARITY SIMDE_SIDD_MASKED_NEGATIVE_POLARITY
  #define _SIDD_LEAST_SIGNIFICANT SIMDE_SIDD_LEAST_SIGNIFICANT
  #define _SIDD_MOST_SIGNIFICANT SIMDE_SIDD_MOST_SIGNIFICANT
  #define _SIDD_BIT_MASK SIMDE_SIDD_BIT_MASK
  #define _SIDD_UNIT_MASK SIMDE_SIDD_UNIT_MASK
#endif

/* Core SSE4.2 string comparison engine */

typedef struct {
  int intres2;
  int cflag;
  int sflag;
  int zflag;
  int oflag;
} simde_x_sse42_compare_result_;

static const uint8_t SIMDE_ALIGN_TO(16) simde_x_sse42_mask8b_[16] = {
    0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80,
    0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80,
};
static const uint16_t SIMDE_ALIGN_TO(16) simde_x_sse42_mask16b_[8] = {
    0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80,
};

SIMDE_FUNCTION_ATTRIBUTES
int
simde_x_sse42_implicit_len_8_(simde__m128i_private v) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    uint16x8_t equal_mask = vreinterpretq_u16_u8(
        vceqq_u8(v.neon_u8, vdupq_n_u8(0)));
    uint8x8_t res = vshrn_n_u16(equal_mask, 4);
    uint64_t matches = vget_lane_u64(vreinterpret_u64_u8(res), 0);
    if (matches == 0)
      return 16;
    return HEDLEY_STATIC_CAST(int, __builtin_ctzll(matches) >> 2);
  #else
    for (int i = 0 ; i < 16 ; i++) {
      if (v.i8[i] == 0)
        return i;
    }
    return 16;
  #endif
}

SIMDE_FUNCTION_ATTRIBUTES
int
simde_x_sse42_implicit_len_16_(simde__m128i_private v) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    uint16x8_t equal_mask = vceqq_u16(v.neon_u16, vdupq_n_u16(0));
    uint8x8_t res = vshrn_n_u16(equal_mask, 4);
    uint64_t matches = vget_lane_u64(vreinterpret_u64_u8(res), 0);
    if (matches == 0)
      return 8;
    return HEDLEY_STATIC_CAST(int, __builtin_ctzll(matches) >> 3);
  #else
    for (int i = 0 ; i < 8 ; i++) {
      if (v.i16[i] == 0)
        return i;
    }
    return 8;
  #endif
}

SIMDE_FUNCTION_ATTRIBUTES
simde_x_sse42_compare_result_
simde_x_sse42_compare_(simde__m128i_private a_, int la, simde__m128i_private b_, int lb, const int imm8) {
  simde_x_sse42_compare_result_ result;
  const int upper_bound = (imm8 & 1) ? 8 : 16;

  /* Compute flags from raw lengths before clamping */
  result.sflag = (la < upper_bound) ? 1 : 0;
  result.zflag = (lb < upper_bound) ? 1 : 0;

  /* Take absolute value and clamp to [0, upper_bound] */
  int la_eff = la < 0 ? -la : la;
  int lb_eff = lb < 0 ? -lb : lb;
  if (la_eff > upper_bound) la_eff = upper_bound;
  if (lb_eff > upper_bound) lb_eff = upper_bound;

  int intres1 = 0;

  switch ((imm8 >> 2) & 3) {
    case 0: /* Equal Any */
      #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
        if (imm8 & 1) {
          /* Word mode: 8 elements */
          for (int i = 0 ; i < 8 ; i++) {
            if (i >= lb_eff) continue;
            uint16x8_t bi = vdupq_n_u16(b_.u16[i]);
            uint16x8_t eq = vceqq_u16(bi, a_.neon_u16);
            /* Mask by la validity: zero out lanes >= la_eff */
            if (la_eff < 8) {
              uint16x8_t la_mask = vcltq_u16(
                  vcombine_u16(vcreate_u16(0x0003000200010000ULL), vcreate_u16(0x0007000600050004ULL)),
                  vdupq_n_u16(HEDLEY_STATIC_CAST(uint16_t, la_eff)));
              eq = vandq_u16(eq, la_mask);
            }
            if (vmaxvq_u16(eq))
              intres1 |= (1 << i);
          }
        } else {
          /* Byte mode: 16 elements */
          for (int i = 0 ; i < 16 ; i++) {
            if (i >= lb_eff) continue;
            uint8x16_t bi = vdupq_n_u8(b_.u8[i]);
            uint8x16_t eq = vceqq_u8(bi, a_.neon_u8);
            /* Mask by la validity */
            if (la_eff < 16) {
              uint8x16_t la_mask = vcltq_u8(
                  vcombine_u8(vcreate_u8(0x0706050403020100ULL), vcreate_u8(0x0F0E0D0C0B0A0908ULL)),
                  vdupq_n_u8(HEDLEY_STATIC_CAST(uint8_t, la_eff)));
              eq = vandq_u8(eq, la_mask);
            }
            if (vmaxvq_u8(eq))
              intres1 |= (1 << i);
          }
        }
      #else
        for (int i = 0 ; i < upper_bound ; i++) {
          int bit = 0;
          if (i < lb_eff) {
            for (int j = 0 ; j < la_eff ; j++) {
              if (imm8 & 1) {
                if (a_.i16[j] == b_.i16[i]) { bit = 1; break; }
              } else {
                if (a_.i8[j] == b_.i8[i]) { bit = 1; break; }
              }
            }
          }
          intres1 |= (bit << i);
        }
      #endif
      break;

    case 1: /* Ranges */
      for (int i = 0 ; i < upper_bound ; i++) {
        int bit = 0;
        if (i < lb_eff) {
          for (int j = 0 ; j + 1 < la_eff ; j += 2) {
            if (imm8 & 1) {
              /* Word */
              if (imm8 & 2) {
                /* Signed */
                if (a_.i16[j] <= b_.i16[i] && b_.i16[i] <= a_.i16[j + 1]) { bit = 1; break; }
              } else {
                /* Unsigned */
                if (a_.u16[j] <= b_.u16[i] && b_.u16[i] <= a_.u16[j + 1]) { bit = 1; break; }
              }
            } else {
              /* Byte */
              if (imm8 & 2) {
                /* Signed */
                if (a_.i8[j] <= b_.i8[i] && b_.i8[i] <= a_.i8[j + 1]) { bit = 1; break; }
              } else {
                /* Unsigned */
                if (a_.u8[j] <= b_.u8[i] && b_.u8[i] <= a_.u8[j + 1]) { bit = 1; break; }
              }
            }
          }
        }
        intres1 |= (bit << i);
      }
      break;

    case 2: /* Equal Each */
      #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
        if (imm8 & 1) {
          /* Word mode */
          uint16x8_t eq = vceqq_u16(a_.neon_u16, b_.neon_u16);
          /* Build validity masks from la_eff and lb_eff */
          uint16x8_t idx = vcombine_u16(vcreate_u16(0x0003000200010000ULL), vcreate_u16(0x0007000600050004ULL));
          uint16x8_t la_valid = vcltq_u16(idx, vdupq_n_u16(HEDLEY_STATIC_CAST(uint16_t, la_eff)));
          uint16x8_t lb_valid = vcltq_u16(idx, vdupq_n_u16(HEDLEY_STATIC_CAST(uint16_t, lb_eff)));
          /* Both valid: use eq result. Both invalid: 1. Otherwise: 0 */
          uint16x8_t both_valid = vandq_u16(la_valid, lb_valid);
          uint16x8_t neither_valid = vmvnq_u16(vorrq_u16(la_valid, lb_valid));
          uint16x8_t res = vorrq_u16(vandq_u16(eq, both_valid), neither_valid);
          /* Extract bitmask */
          uint16x8_t pos_mask = vld1q_u16(simde_x_sse42_mask16b_);
          uint16x8_t msbs = vshrq_n_u16(res, 15);
          uint16x8_t positioned = vmulq_u16(msbs, pos_mask);
          intres1 = HEDLEY_STATIC_CAST(int, vaddvq_u16(positioned));
        } else {
          /* Byte mode */
          uint8x16_t eq = vceqq_u8(a_.neon_u8, b_.neon_u8);
          uint8x16_t idx = vcombine_u8(vcreate_u8(0x0706050403020100ULL), vcreate_u8(0x0F0E0D0C0B0A0908ULL));
          uint8x16_t la_valid = vcltq_u8(idx, vdupq_n_u8(HEDLEY_STATIC_CAST(uint8_t, la_eff)));
          uint8x16_t lb_valid = vcltq_u8(idx, vdupq_n_u8(HEDLEY_STATIC_CAST(uint8_t, lb_eff)));
          uint8x16_t both_valid = vandq_u8(la_valid, lb_valid);
          uint8x16_t neither_valid = vmvnq_u8(vorrq_u8(la_valid, lb_valid));
          uint8x16_t res = vorrq_u8(vandq_u8(eq, both_valid), neither_valid);
          /* Extract 16-bit bitmask */
          uint8x16_t mask_tbl = vld1q_u8(simde_x_sse42_mask8b_);
          uint8x16_t masked = vandq_u8(res, mask_tbl);
          intres1 = HEDLEY_STATIC_CAST(int,
              vaddv_u8(vget_low_u8(masked)) |
              (vaddv_u8(vget_high_u8(masked)) << 8));
        }
      #else
        for (int i = 0 ; i < upper_bound ; i++) {
          int bit;
          int a_valid = (i < la_eff);
          int b_valid = (i < lb_eff);
          if (a_valid && b_valid) {
            if (imm8 & 1)
              bit = (a_.i16[i] == b_.i16[i]) ? 1 : 0;
            else
              bit = (a_.i8[i] == b_.i8[i]) ? 1 : 0;
          } else if (!a_valid && !b_valid) {
            bit = 1;
          } else {
            bit = 0;
          }
          intres1 |= (bit << i);
        }
      #endif
      break;

    case 3: /* Equal Ordered (substring search) */
      #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
        if (imm8 & 1) {
          /* Word mode: 8x8 matrix transpose + diagonal extraction */
          uint16x8_t rows[8];
          /* Build comparison matrix: rows[i][j] = (a[j] == b[i]) ? 0xFFFF : 0 */
          for (int i = 0 ; i < 8 ; i++) {
            uint16x8_t bi = vdupq_n_u16(b_.u16[i]);
            rows[i] = vceqq_u16(bi, a_.neon_u16);
          }
          /* Transpose the 8x8 word matrix */
          /* Level 1: 2x2 blocks of 16-bit elements */
          for (int i = 0 ; i < 8 ; i += 2) {
            uint16x8x2_t t = vtrnq_u16(rows[i], rows[i + 1]);
            rows[i] = t.val[0];
            rows[i + 1] = t.val[1];
          }
          /* Level 2: 2x2 blocks of 32-bit elements */
          for (int i = 0 ; i < 8 ; i += 4) {
            uint32x4x2_t t0 = vtrnq_u32(vreinterpretq_u32_u16(rows[i]),
                                         vreinterpretq_u32_u16(rows[i + 2]));
            uint32x4x2_t t1 = vtrnq_u32(vreinterpretq_u32_u16(rows[i + 1]),
                                         vreinterpretq_u32_u16(rows[i + 3]));
            rows[i]     = vreinterpretq_u16_u32(t0.val[0]);
            rows[i + 2] = vreinterpretq_u16_u32(t0.val[1]);
            rows[i + 1] = vreinterpretq_u16_u32(t1.val[0]);
            rows[i + 3] = vreinterpretq_u16_u32(t1.val[1]);
          }
          /* Level 3: swap 64-bit halves */
          {
            uint16x8_t tmp;
            #define SIMDE_X_SSE42_SWAP_HL_16_(a, b) \
              tmp = vcombine_u16(vget_low_u16(a), vget_low_u16(b)); \
              b = vcombine_u16(vget_high_u16(a), vget_high_u16(b)); \
              a = tmp
            SIMDE_X_SSE42_SWAP_HL_16_(rows[0], rows[4]);
            SIMDE_X_SSE42_SWAP_HL_16_(rows[1], rows[5]);
            SIMDE_X_SSE42_SWAP_HL_16_(rows[2], rows[6]);
            SIMDE_X_SSE42_SWAP_HL_16_(rows[3], rows[7]);
            #undef SIMDE_X_SSE42_SWAP_HL_16_
          }
          /* Apply masking: rows j >= la_eff → 0xFFFF, columns k >= lb_eff → 0 */
          uint16x8_t vec_ff = vdupq_n_u16(0xFFFF);
          uint16x8_t pos_mask = vld1q_u16(simde_x_sse42_mask16b_);
          uint16x8_t lb_clear = vtstq_u16(
              vdupq_n_u16(HEDLEY_STATIC_CAST(uint16_t, (1U << lb_eff) - 1)), pos_mask);
          for (int j = 0 ; j < la_eff && j < 8 ; j++)
            rows[j] = vandq_u16(rows[j], lb_clear);
          for (int j = la_eff ; j < 8 ; j++)
            rows[j] = vec_ff;
          /* Diagonal extraction via vextq + AND cascade */
          uint16x8_t r = vec_ff;
          r = vandq_u16(r, vextq_u16(rows[0], vec_ff, 0));
          r = vandq_u16(r, vextq_u16(rows[1], vec_ff, 1));
          r = vandq_u16(r, vextq_u16(rows[2], vec_ff, 2));
          r = vandq_u16(r, vextq_u16(rows[3], vec_ff, 3));
          r = vandq_u16(r, vextq_u16(rows[4], vec_ff, 4));
          r = vandq_u16(r, vextq_u16(rows[5], vec_ff, 5));
          r = vandq_u16(r, vextq_u16(rows[6], vec_ff, 6));
          r = vandq_u16(r, vextq_u16(rows[7], vec_ff, 7));
          /* Extract bitmask */
          uint16x8_t msbs = vshrq_n_u16(r, 15);
          uint16x8_t positioned = vmulq_u16(msbs, pos_mask);
          intres1 = HEDLEY_STATIC_CAST(int, vaddvq_u16(positioned));
        } else {
          /* Byte mode: 16x16 matrix transpose + diagonal extraction */
          uint8x16_t rows_b[16];
          for (int i = 0 ; i < 16 ; i++) {
            uint8x16_t bi = vdupq_n_u8(b_.u8[i]);
            rows_b[i] = vceqq_u8(bi, a_.neon_u8);
          }
          /* Transpose the 16x16 byte matrix (4-level hierarchical) */
          /* Level 1: 2x2 blocks of 8-bit elements */
          for (int i = 0 ; i < 16 ; i += 2) {
            uint8x16x2_t t = vtrnq_u8(rows_b[i], rows_b[i + 1]);
            rows_b[i] = t.val[0];
            rows_b[i + 1] = t.val[1];
          }
          /* Level 2: 2x2 blocks of 16-bit elements */
          for (int i = 0 ; i < 16 ; i += 4) {
            uint16x8x2_t t0 = vtrnq_u16(vreinterpretq_u16_u8(rows_b[i]),
                                          vreinterpretq_u16_u8(rows_b[i + 2]));
            uint16x8x2_t t1 = vtrnq_u16(vreinterpretq_u16_u8(rows_b[i + 1]),
                                          vreinterpretq_u16_u8(rows_b[i + 3]));
            rows_b[i]     = vreinterpretq_u8_u16(t0.val[0]);
            rows_b[i + 2] = vreinterpretq_u8_u16(t0.val[1]);
            rows_b[i + 1] = vreinterpretq_u8_u16(t1.val[0]);
            rows_b[i + 3] = vreinterpretq_u8_u16(t1.val[1]);
          }
          /* Level 3: 2x2 blocks of 32-bit elements */
          for (int i = 0 ; i < 16 ; i += 8) {
            uint32x4x2_t t0 = vtrnq_u32(vreinterpretq_u32_u8(rows_b[i]),
                                          vreinterpretq_u32_u8(rows_b[i + 4]));
            uint32x4x2_t t1 = vtrnq_u32(vreinterpretq_u32_u8(rows_b[i + 1]),
                                          vreinterpretq_u32_u8(rows_b[i + 5]));
            uint32x4x2_t t2 = vtrnq_u32(vreinterpretq_u32_u8(rows_b[i + 2]),
                                          vreinterpretq_u32_u8(rows_b[i + 6]));
            uint32x4x2_t t3 = vtrnq_u32(vreinterpretq_u32_u8(rows_b[i + 3]),
                                          vreinterpretq_u32_u8(rows_b[i + 7]));
            rows_b[i]     = vreinterpretq_u8_u32(t0.val[0]);
            rows_b[i + 4] = vreinterpretq_u8_u32(t0.val[1]);
            rows_b[i + 1] = vreinterpretq_u8_u32(t1.val[0]);
            rows_b[i + 5] = vreinterpretq_u8_u32(t1.val[1]);
            rows_b[i + 2] = vreinterpretq_u8_u32(t2.val[0]);
            rows_b[i + 6] = vreinterpretq_u8_u32(t2.val[1]);
            rows_b[i + 3] = vreinterpretq_u8_u32(t3.val[0]);
            rows_b[i + 7] = vreinterpretq_u8_u32(t3.val[1]);
          }
          /* Level 4: swap 64-bit halves between row pairs 0..7 and 8..15 */
          for (int i = 0 ; i < 8 ; i++) {
            uint8x16_t tmp = vcombine_u8(vget_low_u8(rows_b[i]), vget_low_u8(rows_b[i + 8]));
            rows_b[i + 8] = vcombine_u8(vget_high_u8(rows_b[i]), vget_high_u8(rows_b[i + 8]));
            rows_b[i] = tmp;
          }
          /* Apply masking: rows j >= la_eff → 0xFF, columns k >= lb_eff → 0 */
          uint8x16_t vec_ff_b = vdupq_n_u8(0xFF);
          uint8x16_t mask_tbl = vld1q_u8(simde_x_sse42_mask8b_);
          uint16_t lb_bits = HEDLEY_STATIC_CAST(uint16_t, (1U << lb_eff) - 1);
          uint8x16_t lb_clear_b = vtstq_u8(
              vcombine_u8(vdup_n_u8(HEDLEY_STATIC_CAST(uint8_t, lb_bits)),
                          vdup_n_u8(HEDLEY_STATIC_CAST(uint8_t, lb_bits >> 8))),
              mask_tbl);
          for (int j = 0 ; j < la_eff && j < 16 ; j++)
            rows_b[j] = vandq_u8(rows_b[j], lb_clear_b);
          for (int j = la_eff ; j < 16 ; j++)
            rows_b[j] = vec_ff_b;
          /* Diagonal extraction via vextq + AND cascade */
          uint8x16_t rb = vec_ff_b;
          rb = vandq_u8(rb, vextq_u8(rows_b[ 0], vec_ff_b,  0));
          rb = vandq_u8(rb, vextq_u8(rows_b[ 1], vec_ff_b,  1));
          rb = vandq_u8(rb, vextq_u8(rows_b[ 2], vec_ff_b,  2));
          rb = vandq_u8(rb, vextq_u8(rows_b[ 3], vec_ff_b,  3));
          rb = vandq_u8(rb, vextq_u8(rows_b[ 4], vec_ff_b,  4));
          rb = vandq_u8(rb, vextq_u8(rows_b[ 5], vec_ff_b,  5));
          rb = vandq_u8(rb, vextq_u8(rows_b[ 6], vec_ff_b,  6));
          rb = vandq_u8(rb, vextq_u8(rows_b[ 7], vec_ff_b,  7));
          rb = vandq_u8(rb, vextq_u8(rows_b[ 8], vec_ff_b,  8));
          rb = vandq_u8(rb, vextq_u8(rows_b[ 9], vec_ff_b,  9));
          rb = vandq_u8(rb, vextq_u8(rows_b[10], vec_ff_b, 10));
          rb = vandq_u8(rb, vextq_u8(rows_b[11], vec_ff_b, 11));
          rb = vandq_u8(rb, vextq_u8(rows_b[12], vec_ff_b, 12));
          rb = vandq_u8(rb, vextq_u8(rows_b[13], vec_ff_b, 13));
          rb = vandq_u8(rb, vextq_u8(rows_b[14], vec_ff_b, 14));
          rb = vandq_u8(rb, vextq_u8(rows_b[15], vec_ff_b, 15));
          /* Extract 16-bit bitmask */
          uint8x16_t masked_b = vandq_u8(rb, mask_tbl);
          intres1 = HEDLEY_STATIC_CAST(int,
              vaddv_u8(vget_low_u8(masked_b)) |
              (vaddv_u8(vget_high_u8(masked_b)) << 8));
        }
      #else
        for (int i = 0 ; i < upper_bound ; i++) {
          int bit = 1;
          for (int j = 0 ; j < upper_bound - i ; j++) {
            int a_valid = (j < la_eff);
            int b_valid = ((i + j) < lb_eff);
            if (!a_valid) {
              /* Pattern exhausted: match */
              break;
            } else if (!b_valid) {
              /* Haystack exhausted before pattern: no match */
              bit = 0;
              break;
            } else {
              int eq;
              if (imm8 & 1)
                eq = (a_.i16[j] == b_.i16[i + j]) ? 1 : 0;
              else
                eq = (a_.i8[j] == b_.i8[i + j]) ? 1 : 0;
              if (!eq) {
                bit = 0;
                break;
              }
            }
          }
          intres1 |= (bit << i);
        }
      #endif
      break;
  }

  /* Apply polarity */
  int intres2;
  switch ((imm8 >> 4) & 3) {
    case 0: /* Positive Polarity */
    case 2: /* Masked Positive Polarity (same as positive for IntRes2) */
      intres2 = intres1;
      break;
    case 1: /* Negative Polarity */
      intres2 = ~intres1;
      break;
    case 3: /* Masked Negative Polarity */
      intres2 = intres1 ^ ((1 << lb_eff) - 1);
      break;
    default:
      intres2 = intres1;
      break;
  }

  /* Mask to upper_bound bits */
  intres2 &= ((1 << upper_bound) - 1);

  result.intres2 = intres2;
  result.cflag = (intres2 != 0) ? 1 : 0;
  result.oflag = intres2 & 1;
  return result;
}

/* Explicit-length string comparison functions */

SIMDE_FUNCTION_ATTRIBUTES
int simde_mm_cmpestra (simde__m128i a, int la, simde__m128i b, int lb, const int imm8)
    SIMDE_REQUIRE_CONSTANT_RANGE(imm8, 0, 255) {
  simde__m128i_private a_ = simde__m128i_to_private(a);
  simde__m128i_private b_ = simde__m128i_to_private(b);
  simde_x_sse42_compare_result_ r = simde_x_sse42_compare_(a_, la, b_, lb, imm8);
  return !r.cflag && !r.zflag;
}
#if defined(SIMDE_X86_SSE4_2_NATIVE)
  #if defined(__clang__) && !SIMDE_DETECT_CLANG_VERSION_CHECK(3,8,0)
    #define simde_mm_cmpestra(a, la, b, lb, imm8) \
      _mm_cmpestra( \
        HEDLEY_REINTERPRET_CAST(__v16qi, a), la, \
        HEDLEY_REINTERPRET_CAST(__v16qi, b), lb, \
        imm8)
  #else
    #define simde_mm_cmpestra(a, la, b, lb, imm8) _mm_cmpestra(a, la, b, lb, imm8)
  #endif
#endif
#if defined(SIMDE_X86_SSE4_2_ENABLE_NATIVE_ALIASES)
  #undef _mm_cmpestra
  #define _mm_cmpestra(a, la, b, lb, imm8) simde_mm_cmpestra(a, la, b, lb, imm8)
#endif

SIMDE_FUNCTION_ATTRIBUTES
int simde_mm_cmpestrc (simde__m128i a, int la, simde__m128i b, int lb, const int imm8)
    SIMDE_REQUIRE_CONSTANT_RANGE(imm8, 0, 255) {
  simde__m128i_private a_ = simde__m128i_to_private(a);
  simde__m128i_private b_ = simde__m128i_to_private(b);
  simde_x_sse42_compare_result_ r = simde_x_sse42_compare_(a_, la, b_, lb, imm8);
  return r.cflag;
}
#if defined(SIMDE_X86_SSE4_2_NATIVE)
  #if defined(__clang__) && !SIMDE_DETECT_CLANG_VERSION_CHECK(3,8,0)
    #define simde_mm_cmpestrc(a, la, b, lb, imm8) \
      _mm_cmpestrc( \
        HEDLEY_REINTERPRET_CAST(__v16qi, a), la, \
        HEDLEY_REINTERPRET_CAST(__v16qi, b), lb, \
        imm8)
  #else
    #define simde_mm_cmpestrc(a, la, b, lb, imm8) _mm_cmpestrc(a, la, b, lb, imm8)
  #endif
#endif
#if defined(SIMDE_X86_SSE4_2_ENABLE_NATIVE_ALIASES)
  #undef _mm_cmpestrc
  #define _mm_cmpestrc(a, la, b, lb, imm8) simde_mm_cmpestrc(a, la, b, lb, imm8)
#endif

SIMDE_FUNCTION_ATTRIBUTES
int simde_mm_cmpestri (simde__m128i a, int la, simde__m128i b, int lb, const int imm8)
    SIMDE_REQUIRE_CONSTANT_RANGE(imm8, 0, 255) {
  simde__m128i_private a_ = simde__m128i_to_private(a);
  simde__m128i_private b_ = simde__m128i_to_private(b);
  simde_x_sse42_compare_result_ r = simde_x_sse42_compare_(a_, la, b_, lb, imm8);
  const int upper_bound = (imm8 & 1) ? 8 : 16;
  if (r.intres2 == 0) return upper_bound;
  if (imm8 & 0x40) {
    /* Most significant bit */
    int idx = upper_bound - 1;
    while (idx >= 0 && !(r.intres2 & (1 << idx))) idx--;
    return idx;
  } else {
    /* Least significant bit */
    int idx = 0;
    while (idx < upper_bound && !(r.intres2 & (1 << idx))) idx++;
    return idx;
  }
}
#if defined(SIMDE_X86_SSE4_2_NATIVE)
  #if defined(__clang__) && !SIMDE_DETECT_CLANG_VERSION_CHECK(3,8,0)
    #define simde_mm_cmpestri(a, la, b, lb, imm8) \
      _mm_cmpestri( \
        HEDLEY_REINTERPRET_CAST(__v16qi, a), la, \
        HEDLEY_REINTERPRET_CAST(__v16qi, b), lb, \
        imm8)
  #else
    #define simde_mm_cmpestri(a, la, b, lb, imm8) _mm_cmpestri(a, la, b, lb, imm8)
  #endif
#endif
#if defined(SIMDE_X86_SSE4_2_ENABLE_NATIVE_ALIASES)
  #undef _mm_cmpestri
  #define _mm_cmpestri(a, la, b, lb, imm8) simde_mm_cmpestri(a, la, b, lb, imm8)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i simde_mm_cmpestrm (simde__m128i a, int la, simde__m128i b, int lb, const int imm8)
    SIMDE_REQUIRE_CONSTANT_RANGE(imm8, 0, 255) {
  simde__m128i_private a_ = simde__m128i_to_private(a);
  simde__m128i_private b_ = simde__m128i_to_private(b);
  simde_x_sse42_compare_result_ r = simde_x_sse42_compare_(a_, la, b_, lb, imm8);
  simde__m128i_private result_ = simde__m128i_to_private(simde_mm_setzero_si128());
  const int upper_bound = (imm8 & 1) ? 8 : 16;
  if (imm8 & 0x40) {
    /* Unit mask: expand each bit to a full element */
    for (int i = 0 ; i < upper_bound ; i++) {
      if (r.intres2 & (1 << i)) {
        if (imm8 & 1)
          result_.i16[i] = -1;
        else
          result_.i8[i] = -1;
      }
    }
  } else {
    /* Bit mask: store IntRes2 in lowest bits */
    result_.i32[0] = r.intres2;
  }
  return simde__m128i_from_private(result_);
}
#if defined(SIMDE_X86_SSE4_2_NATIVE)
  #if defined(__clang__) && !SIMDE_DETECT_CLANG_VERSION_CHECK(3,8,0)
    #define simde_mm_cmpestrm(a, la, b, lb, imm8) \
      _mm_cmpestrm( \
        HEDLEY_REINTERPRET_CAST(__v16qi, a), la, \
        HEDLEY_REINTERPRET_CAST(__v16qi, b), lb, \
        imm8)
  #else
    #define simde_mm_cmpestrm(a, la, b, lb, imm8) _mm_cmpestrm(a, la, b, lb, imm8)
  #endif
#endif
#if defined(SIMDE_X86_SSE4_2_ENABLE_NATIVE_ALIASES)
  #undef _mm_cmpestrm
  #define _mm_cmpestrm(a, la, b, lb, imm8) simde_mm_cmpestrm(a, la, b, lb, imm8)
#endif

SIMDE_FUNCTION_ATTRIBUTES
int simde_mm_cmpestro (simde__m128i a, int la, simde__m128i b, int lb, const int imm8)
    SIMDE_REQUIRE_CONSTANT_RANGE(imm8, 0, 255) {
  simde__m128i_private a_ = simde__m128i_to_private(a);
  simde__m128i_private b_ = simde__m128i_to_private(b);
  simde_x_sse42_compare_result_ r = simde_x_sse42_compare_(a_, la, b_, lb, imm8);
  return r.oflag;
}
#if defined(SIMDE_X86_SSE4_2_NATIVE)
  #if defined(__clang__) && !SIMDE_DETECT_CLANG_VERSION_CHECK(3,8,0)
    #define simde_mm_cmpestro(a, la, b, lb, imm8) \
      _mm_cmpestro( \
        HEDLEY_REINTERPRET_CAST(__v16qi, a), la, \
        HEDLEY_REINTERPRET_CAST(__v16qi, b), lb, \
        imm8)
  #else
    #define simde_mm_cmpestro(a, la, b, lb, imm8) _mm_cmpestro(a, la, b, lb, imm8)
  #endif
#endif
#if defined(SIMDE_X86_SSE4_2_ENABLE_NATIVE_ALIASES)
  #undef _mm_cmpestro
  #define _mm_cmpestro(a, la, b, lb, imm8) simde_mm_cmpestro(a, la, b, lb, imm8)
#endif

/* Implicit-length string comparison functions */

SIMDE_FUNCTION_ATTRIBUTES
int simde_mm_cmpistra (simde__m128i a, simde__m128i b, const int imm8)
    SIMDE_REQUIRE_CONSTANT_RANGE(imm8, 0, 255) {
  simde__m128i_private a_ = simde__m128i_to_private(a);
  simde__m128i_private b_ = simde__m128i_to_private(b);
  int la = (imm8 & 1) ? simde_x_sse42_implicit_len_16_(a_) : simde_x_sse42_implicit_len_8_(a_);
  int lb = (imm8 & 1) ? simde_x_sse42_implicit_len_16_(b_) : simde_x_sse42_implicit_len_8_(b_);
  simde_x_sse42_compare_result_ r = simde_x_sse42_compare_(a_, la, b_, lb, imm8);
  return !r.cflag && !r.zflag;
}
#if defined(SIMDE_X86_SSE4_2_NATIVE)
  #if defined(__clang__) && !SIMDE_DETECT_CLANG_VERSION_CHECK(3,8,0)
    #define simde_mm_cmpistra(a, b, imm8) \
      _mm_cmpistra( \
        HEDLEY_REINTERPRET_CAST(__v16qi, a), \
        HEDLEY_REINTERPRET_CAST(__v16qi, b), \
        imm8)
  #else
    #define simde_mm_cmpistra(a, b, imm8) _mm_cmpistra(a, b, imm8)
  #endif
#endif
#if defined(SIMDE_X86_SSE4_2_ENABLE_NATIVE_ALIASES)
  #undef _mm_cmpistra
  #define _mm_cmpistra(a, b, imm8) simde_mm_cmpistra(a, b, imm8)
#endif

SIMDE_FUNCTION_ATTRIBUTES
int simde_mm_cmpistrc (simde__m128i a, simde__m128i b, const int imm8)
    SIMDE_REQUIRE_CONSTANT_RANGE(imm8, 0, 255) {
  simde__m128i_private a_ = simde__m128i_to_private(a);
  simde__m128i_private b_ = simde__m128i_to_private(b);
  int la = (imm8 & 1) ? simde_x_sse42_implicit_len_16_(a_) : simde_x_sse42_implicit_len_8_(a_);
  int lb = (imm8 & 1) ? simde_x_sse42_implicit_len_16_(b_) : simde_x_sse42_implicit_len_8_(b_);
  simde_x_sse42_compare_result_ r = simde_x_sse42_compare_(a_, la, b_, lb, imm8);
  return r.cflag;
}
#if defined(SIMDE_X86_SSE4_2_NATIVE)
  #if defined(__clang__) && !SIMDE_DETECT_CLANG_VERSION_CHECK(3,8,0)
    #define simde_mm_cmpistrc(a, b, imm8) \
      _mm_cmpistrc( \
        HEDLEY_REINTERPRET_CAST(__v16qi, a), \
        HEDLEY_REINTERPRET_CAST(__v16qi, b), \
        imm8)
  #else
    #define simde_mm_cmpistrc(a, b, imm8) _mm_cmpistrc(a, b, imm8)
  #endif
#endif
#if defined(SIMDE_X86_SSE4_2_ENABLE_NATIVE_ALIASES)
  #undef _mm_cmpistrc
  #define _mm_cmpistrc(a, b, imm8) simde_mm_cmpistrc(a, b, imm8)
#endif

SIMDE_FUNCTION_ATTRIBUTES
int simde_mm_cmpistri (simde__m128i a, simde__m128i b, const int imm8)
    SIMDE_REQUIRE_CONSTANT_RANGE(imm8, 0, 255) {
  simde__m128i_private a_ = simde__m128i_to_private(a);
  simde__m128i_private b_ = simde__m128i_to_private(b);
  int la = (imm8 & 1) ? simde_x_sse42_implicit_len_16_(a_) : simde_x_sse42_implicit_len_8_(a_);
  int lb = (imm8 & 1) ? simde_x_sse42_implicit_len_16_(b_) : simde_x_sse42_implicit_len_8_(b_);
  simde_x_sse42_compare_result_ r = simde_x_sse42_compare_(a_, la, b_, lb, imm8);
  const int upper_bound = (imm8 & 1) ? 8 : 16;
  if (r.intres2 == 0) return upper_bound;
  if (imm8 & 0x40) {
    int idx = upper_bound - 1;
    while (idx >= 0 && !(r.intres2 & (1 << idx))) idx--;
    return idx;
  } else {
    int idx = 0;
    while (idx < upper_bound && !(r.intres2 & (1 << idx))) idx++;
    return idx;
  }
}
#if defined(SIMDE_X86_SSE4_2_NATIVE)
  #if defined(__clang__) && !SIMDE_DETECT_CLANG_VERSION_CHECK(3,8,0)
    #define simde_mm_cmpistri(a, b, imm8) \
      _mm_cmpistri( \
        HEDLEY_REINTERPRET_CAST(__v16qi, a), \
        HEDLEY_REINTERPRET_CAST(__v16qi, b), \
        imm8)
  #else
    #define simde_mm_cmpistri(a, b, imm8) _mm_cmpistri(a, b, imm8)
  #endif
#endif
#if defined(SIMDE_X86_SSE4_2_ENABLE_NATIVE_ALIASES)
  #undef _mm_cmpistri
  #define _mm_cmpistri(a, b, imm8) simde_mm_cmpistri(a, b, imm8)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i simde_mm_cmpistrm (simde__m128i a, simde__m128i b, const int imm8)
    SIMDE_REQUIRE_CONSTANT_RANGE(imm8, 0, 255) {
  simde__m128i_private a_ = simde__m128i_to_private(a);
  simde__m128i_private b_ = simde__m128i_to_private(b);
  int la = (imm8 & 1) ? simde_x_sse42_implicit_len_16_(a_) : simde_x_sse42_implicit_len_8_(a_);
  int lb = (imm8 & 1) ? simde_x_sse42_implicit_len_16_(b_) : simde_x_sse42_implicit_len_8_(b_);
  simde_x_sse42_compare_result_ r = simde_x_sse42_compare_(a_, la, b_, lb, imm8);
  simde__m128i_private result_ = simde__m128i_to_private(simde_mm_setzero_si128());
  const int upper_bound = (imm8 & 1) ? 8 : 16;
  if (imm8 & 0x40) {
    for (int i = 0 ; i < upper_bound ; i++) {
      if (r.intres2 & (1 << i)) {
        if (imm8 & 1)
          result_.i16[i] = -1;
        else
          result_.i8[i] = -1;
      }
    }
  } else {
    result_.i32[0] = r.intres2;
  }
  return simde__m128i_from_private(result_);
}
#if defined(SIMDE_X86_SSE4_2_NATIVE)
  #if defined(__clang__) && !SIMDE_DETECT_CLANG_VERSION_CHECK(3,8,0)
    #define simde_mm_cmpistrm(a, b, imm8) \
      _mm_cmpistrm( \
        HEDLEY_REINTERPRET_CAST(__v16qi, a), \
        HEDLEY_REINTERPRET_CAST(__v16qi, b), \
        imm8)
  #else
    #define simde_mm_cmpistrm(a, b, imm8) _mm_cmpistrm(a, b, imm8)
  #endif
#endif
#if defined(SIMDE_X86_SSE4_2_ENABLE_NATIVE_ALIASES)
  #undef _mm_cmpistrm
  #define _mm_cmpistrm(a, b, imm8) simde_mm_cmpistrm(a, b, imm8)
#endif

SIMDE_FUNCTION_ATTRIBUTES
int simde_mm_cmpistro (simde__m128i a, simde__m128i b, const int imm8)
    SIMDE_REQUIRE_CONSTANT_RANGE(imm8, 0, 255) {
  simde__m128i_private a_ = simde__m128i_to_private(a);
  simde__m128i_private b_ = simde__m128i_to_private(b);
  int la = (imm8 & 1) ? simde_x_sse42_implicit_len_16_(a_) : simde_x_sse42_implicit_len_8_(a_);
  int lb = (imm8 & 1) ? simde_x_sse42_implicit_len_16_(b_) : simde_x_sse42_implicit_len_8_(b_);
  simde_x_sse42_compare_result_ r = simde_x_sse42_compare_(a_, la, b_, lb, imm8);
  return r.oflag;
}
#if defined(SIMDE_X86_SSE4_2_NATIVE)
  #if defined(__clang__) && !SIMDE_DETECT_CLANG_VERSION_CHECK(3,8,0)
    #define simde_mm_cmpistro(a, b, imm8) \
      _mm_cmpistro( \
        HEDLEY_REINTERPRET_CAST(__v16qi, a), \
        HEDLEY_REINTERPRET_CAST(__v16qi, b), \
        imm8)
  #else
    #define simde_mm_cmpistro(a, b, imm8) _mm_cmpistro(a, b, imm8)
  #endif
#endif
#if defined(SIMDE_X86_SSE4_2_ENABLE_NATIVE_ALIASES)
  #undef _mm_cmpistro
  #define _mm_cmpistro(a, b, imm8) simde_mm_cmpistro(a, b, imm8)
#endif

SIMDE_FUNCTION_ATTRIBUTES
int simde_mm_cmpestrs (simde__m128i a, int la, simde__m128i b, int lb, const int imm8)
    SIMDE_REQUIRE_CONSTANT_RANGE(imm8, 0, 255) {
  #if !defined(HEDLEY_PGI_VERSION)
    /* https://www.pgroup.com/userforum/viewtopic.php?f=4&p=27590&sid=cf89f8bf30be801831fe4a2ff0a2fa6c */
    (void) a;
    (void) b;
  #endif
  (void) la;
  (void) lb;
  return la <= ((128 / ((imm8 & SIMDE_SIDD_UWORD_OPS) ? 16 : 8)) - 1);
}
#if defined(SIMDE_X86_SSE4_2_NATIVE)
  #if defined(__clang__) && !SIMDE_DETECT_CLANG_VERSION_CHECK(3,8,0)
    #define simde_mm_cmpestrs(a, la, b, lb, imm8) \
      _mm_cmpestrs( \
        HEDLEY_REINTERPRET_CAST(__v16qi, a), la, \
        HEDLEY_REINTERPRET_CAST(__v16qi, b), lb, \
        imm8)
  #else
    #define simde_mm_cmpestrs(a, la, b, lb, imm8) _mm_cmpestrs(a, la, b, lb, imm8)
  #endif
#endif
#if defined(SIMDE_X86_SSE4_2_ENABLE_NATIVE_ALIASES)
  #undef _mm_cmpestrs
  #define _mm_cmpestrs(a, la, b, lb, imm8) simde_mm_cmpestrs(a, la, b, lb, imm8)
#endif

SIMDE_FUNCTION_ATTRIBUTES
int simde_mm_cmpestrz (simde__m128i a, int la, simde__m128i b, int lb, const int imm8)
    SIMDE_REQUIRE_CONSTANT_RANGE(imm8, 0, 255) {
  #if !defined(HEDLEY_PGI_VERSION)
    /* https://www.pgroup.com/userforum/viewtopic.php?f=4&p=27590&sid=cf89f8bf30be801831fe4a2ff0a2fa6c */
    (void) a;
    (void) b;
  #endif
  (void) la;
  (void) lb;
  return lb <= ((128 / ((imm8 & SIMDE_SIDD_UWORD_OPS) ? 16 : 8)) - 1);
}
#if defined(SIMDE_X86_SSE4_2_NATIVE)
  #if defined(__clang__) && !SIMDE_DETECT_CLANG_VERSION_CHECK(3,8,0)
    #define simde_mm_cmpestrz(a, la, b, lb, imm8) \
      _mm_cmpestrz( \
        HEDLEY_REINTERPRET_CAST(__v16qi, a), la, \
        HEDLEY_REINTERPRET_CAST(__v16qi, b), lb, \
        imm8)
  #else
    #define simde_mm_cmpestrz(a, la, b, lb, imm8) _mm_cmpestrz(a, la, b, lb, imm8)
  #endif
#endif
#if defined(SIMDE_X86_SSE4_2_ENABLE_NATIVE_ALIASES)
  #undef _mm_cmpestrz
  #define _mm_cmpestrz(a, la, b, lb, imm8) simde_mm_cmpestrz(a, la, b, lb, imm8)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_cmpgt_epi64 (simde__m128i a, simde__m128i b) {
  #if defined(SIMDE_X86_SSE4_2_NATIVE)
    return _mm_cmpgt_epi64(a, b);
  #elif defined(SIMDE_X86_SSE2_NATIVE)
    /* https://stackoverflow.com/a/65175746/501126 */
    __m128i r = _mm_and_si128(_mm_cmpeq_epi32(a, b), _mm_sub_epi64(b, a));
    r = _mm_or_si128(r, _mm_cmpgt_epi32(a, b));
    return _mm_shuffle_epi32(r, _MM_SHUFFLE(3, 3, 1, 1));
  #else
    simde__m128i_private
      r_,
      a_ = simde__m128i_to_private(a),
      b_ = simde__m128i_to_private(b);

    #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
      r_.neon_u64 = vcgtq_s64(a_.neon_i64, b_.neon_i64);
    #elif defined(SIMDE_ARM_NEON_A32V7_NATIVE)
      /* https://stackoverflow.com/a/65223269/501126 */
      r_.neon_i64 = vshrq_n_s64(vqsubq_s64(b_.neon_i64, a_.neon_i64), 63);
    #elif defined(SIMDE_POWER_ALTIVEC_P8_NATIVE)
      r_.altivec_u64 = HEDLEY_REINTERPRET_CAST(SIMDE_POWER_ALTIVEC_VECTOR(unsigned long long), vec_cmpgt(a_.altivec_i64, b_.altivec_i64));
    #elif defined(SIMDE_WASM_SIMD128_NATIVE)
      r_.wasm_v128 = wasm_i64x2_gt(a_.wasm_v128, b_.wasm_v128);
    #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
      r_.lsx_i64 = __lsx_vslt_d(b_.lsx_i64, a_.lsx_i64);
    #elif defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r_.i64 = HEDLEY_REINTERPRET_CAST(__typeof__(r_.i64), a_.i64 > b_.i64);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.i64) / sizeof(r_.i64[0])) ; i++) {
        r_.i64[i] = (a_.i64[i] > b_.i64[i]) ? ~INT64_C(0) : INT64_C(0);
      }
    #endif

    return simde__m128i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_SSE4_2_ENABLE_NATIVE_ALIASES)
  #undef _mm_cmpgt_epi64
  #define _mm_cmpgt_epi64(a, b) simde_mm_cmpgt_epi64(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
int
simde_mm_cmpistrs_8_(simde__m128i a) {
  simde__m128i_private a_= simde__m128i_to_private(a);
  const int upper_bound = (128 / 8) - 1;
  int a_invalid = 0;
  SIMDE_VECTORIZE
  for (int i = 0 ; i <= upper_bound ; i++) {
    if(!a_.i8[i])
      a_invalid = 1;
  }
  return a_invalid;
}

SIMDE_FUNCTION_ATTRIBUTES
int
simde_mm_cmpistrs_16_(simde__m128i a) {
  simde__m128i_private a_= simde__m128i_to_private(a);
  const int upper_bound = (128 / 16) - 1;
  int a_invalid = 0;
  SIMDE_VECTORIZE
  for (int i = 0 ; i <= upper_bound ; i++) {
    if(!a_.i16[i])
      a_invalid = 1;
  }
  return a_invalid;
}

#if defined(SIMDE_X86_SSE4_2_NATIVE)
  #if defined(__clang__) && !SIMDE_DETECT_CLANG_VERSION_CHECK(3,8,0)
    #define simde_mm_cmpistrs(a, b, imm8) \
      _mm_cmpistrs( \
        HEDLEY_REINTERPRET_CAST(__v16qi, a), \
        HEDLEY_REINTERPRET_CAST(__v16qi, b), \
        imm8)
  #else
    #define simde_mm_cmpistrs(a, b, imm8) _mm_cmpistrs(a, b, imm8)
  #endif
#else
  #define simde_mm_cmpistrs(a, b, imm8) \
     (((imm8) & SIMDE_SIDD_UWORD_OPS) \
       ? simde_mm_cmpistrs_16_((a)) \
       : simde_mm_cmpistrs_8_((a)))
#endif
#if defined(SIMDE_X86_SSE4_2_ENABLE_NATIVE_ALIASES)
  #undef _mm_cmpistrs
  #define _mm_cmpistrs(a, b, imm8) simde_mm_cmpistrs(a, b, imm8)
#endif

SIMDE_FUNCTION_ATTRIBUTES
int
simde_mm_cmpistrz_8_(simde__m128i b) {
  simde__m128i_private b_= simde__m128i_to_private(b);
  const int upper_bound = (128 / 8) - 1;
  int b_invalid = 0;
  SIMDE_VECTORIZE
  for (int i = 0 ; i <= upper_bound ; i++) {
    if(!b_.i8[i])
      b_invalid = 1;
  }
  return b_invalid;
}

SIMDE_FUNCTION_ATTRIBUTES
int
simde_mm_cmpistrz_16_(simde__m128i b) {
  simde__m128i_private b_= simde__m128i_to_private(b);
  const int upper_bound = (128 / 16) - 1;
  int b_invalid = 0;
  SIMDE_VECTORIZE
  for (int i = 0 ; i <= upper_bound ; i++) {
    if(!b_.i16[i])
      b_invalid = 1;
  }
  return b_invalid;
}

#if defined(SIMDE_X86_SSE4_2_NATIVE)
  #if defined(__clang__) && !SIMDE_DETECT_CLANG_VERSION_CHECK(3,8,0)
    #define simde_mm_cmpistrz(a, b, imm8) \
      _mm_cmpistrz( \
        HEDLEY_REINTERPRET_CAST(__v16qi, a), \
        HEDLEY_REINTERPRET_CAST(__v16qi, b), \
        imm8)
  #else
    #define simde_mm_cmpistrz(a, b, imm8) _mm_cmpistrz(a, b, imm8)
  #endif
#else
  #define simde_mm_cmpistrz(a, b, imm8) \
     (((imm8) & SIMDE_SIDD_UWORD_OPS) \
       ? simde_mm_cmpistrz_16_((b)) \
       : simde_mm_cmpistrz_8_((b)))
#endif
#if defined(SIMDE_X86_SSE4_2_ENABLE_NATIVE_ALIASES)
  #undef _mm_cmpistrz
  #define _mm_cmpistrz(a, b, imm8) simde_mm_cmpistrz(a, b, imm8)
#endif

SIMDE_FUNCTION_ATTRIBUTES
uint32_t
simde_mm_crc32_u8(uint32_t prevcrc, uint8_t v) {
  #if defined(SIMDE_X86_SSE4_2_NATIVE)
    return _mm_crc32_u8(prevcrc, v);
  #else
    #if defined(SIMDE_ARM_NEON_A64V8_NATIVE) && defined(SIMDE_ARCH_ARM_CRC32)
      return __crc32cb(prevcrc, v);
    #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
      return __builtin_loongarch_crcc_w_b_w(v, prevcrc);
    #else
      uint32_t crc = prevcrc;
      crc ^= v;
      // Adapted from: https://create.stephan-brumme.com/crc32/
      // Apply half-byte comparision algorithm for the best ratio between
      // performance and lookup table.

      // The lookup table just needs to store every 16th entry
      // of the standard look-up table.
      static const uint32_t crc32_half_byte_tbl[] = {
        0x00000000, 0x105ec76f, 0x20bd8ede, 0x30e349b1, 0x417b1dbc, 0x5125dad3,
        0x61c69362, 0x7198540d, 0x82f63b78, 0x92a8fc17, 0xa24bb5a6, 0xb21572c9,
        0xc38d26c4, 0xd3d3e1ab, 0xe330a81a, 0xf36e6f75,
      };

      crc = (crc >> 4) ^ crc32_half_byte_tbl[crc & 0x0f];
      crc = (crc >> 4) ^ crc32_half_byte_tbl[crc & 0x0f];
      return crc;
    #endif
  #endif
}
#if defined(SIMDE_X86_SSE4_2_ENABLE_NATIVE_ALIASES)
  #define _mm_crc32_u8(prevcrc, v) simde_mm_crc32_u8(prevcrc, v)
#endif

SIMDE_FUNCTION_ATTRIBUTES
uint32_t
simde_mm_crc32_u16(uint32_t prevcrc, uint16_t v) {
  #if defined(SIMDE_X86_SSE4_2_NATIVE)
    return _mm_crc32_u16(prevcrc, v);
  #else
    #if defined(SIMDE_ARM_NEON_A64V8_NATIVE) && defined(SIMDE_ARCH_ARM_CRC32)
      return __crc32ch(prevcrc, v);
    #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
      return __builtin_loongarch_crcc_w_h_w(v, prevcrc);
    #else
      uint32_t crc = prevcrc;
      crc = simde_mm_crc32_u8(crc, v & 0xff);
      crc = simde_mm_crc32_u8(crc, (v >> 8) & 0xff);
      return crc;
    #endif
  #endif
}
#if defined(SIMDE_X86_SSE4_2_ENABLE_NATIVE_ALIASES)
  #define _mm_crc32_u16(prevcrc, v) simde_mm_crc32_u16(prevcrc, v)
#endif

SIMDE_FUNCTION_ATTRIBUTES
uint32_t
simde_mm_crc32_u32(uint32_t prevcrc, uint32_t v) {
  #if defined(SIMDE_X86_SSE4_2_NATIVE)
    return _mm_crc32_u32(prevcrc, v);
  #else
    #if defined(SIMDE_ARM_NEON_A64V8_NATIVE) && defined(SIMDE_ARCH_ARM_CRC32)
      return __crc32cw(prevcrc, v);
    #elif defined(SIMDE_LOONGARCH_LSX_NATIVE)
      return __builtin_loongarch_crcc_w_w_w(v, prevcrc);
    #else
      uint32_t crc = prevcrc;
      crc = simde_mm_crc32_u16(crc, v & 0xffff);
      crc = simde_mm_crc32_u16(crc, (v >> 16) & 0xffff);
      return crc;
    #endif
  #endif
}
#if defined(SIMDE_X86_SSE4_2_ENABLE_NATIVE_ALIASES)
  #define _mm_crc32_u32(prevcrc, v) simde_mm_crc32_u32(prevcrc, v)
#endif

SIMDE_FUNCTION_ATTRIBUTES
uint64_t
simde_mm_crc32_u64(uint64_t prevcrc, uint64_t v) {
  #if defined(SIMDE_X86_SSE4_2_NATIVE) && defined(SIMDE_ARCH_AMD64)
    return _mm_crc32_u64(prevcrc, v);
  #else
    #if defined(SIMDE_ARM_NEON_A64V8_NATIVE) && defined(SIMDE_ARCH_ARM_CRC32)
      return __crc32cd(HEDLEY_STATIC_CAST(uint32_t, prevcrc), v);
    #else
      uint64_t crc = prevcrc;
      crc = simde_mm_crc32_u32(HEDLEY_STATIC_CAST(uint32_t, crc), v & 0xffffffff);
      crc = simde_mm_crc32_u32(HEDLEY_STATIC_CAST(uint32_t, crc), (v >> 32) & 0xffffffff);
      return crc;
    #endif
  #endif
}
#if defined(SIMDE_X86_SSE4_2_ENABLE_NATIVE_ALIASES) || (defined(SIMDE_ENABLE_NATIVE_ALIASES) && !defined(SIMDE_ARCH_AMD64))
  #define _mm_crc32_u64(prevcrc, v) simde_mm_crc32_u64(prevcrc, v)
#endif

SIMDE_END_DECLS_

HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_X86_SSE4_2_H) */
