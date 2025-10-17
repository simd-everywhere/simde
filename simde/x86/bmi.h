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
 *   2025  Thomas Magnusson <herr.thomas.magnusson@gmail.com>
 */

#if !defined(SIMDE_X86_BMI_H)
#define SIMDE_X86_BMI_H

SIMDE_FUNCTION_ATTRIBUTES
uint32_t
simde_pext_u32(uint32_t a, uint32_t mask)
{
#if defined(SIMDE_ARCH_ARM_SVE2_BITPERM) && defined(SIMDE_ARM_SVE2_NATIVE)
  svuint32_t va = svdup_u32(a);
  svuint32_t r = svbext_n_u32(va, mask);
  return svlastb_u32(svptrue_b32(), r);
#else
  uint32_t r = 0;
  int k = 0;
  for (uint32_t m = mask; m; m >>= 1, a >>= 1) {
    if (m & 1) {
      r |= (a & 1) << k++;
    }
  }
  return r;
#endif
}
#if defined(SIMDE_X86_BMI2_NATIVE)
#define simde_pext_u32(a, mask) _pext_u32(a, mask)
#endif
#if defined(SIMDE_X86_BMI2_ENABLE_NATIVE_ALIASES)
#undef _pext_u32
#define _pext_u32(a, mask) simde_pext_u32(a, mask)
#endif

SIMDE_FUNCTION_ATTRIBUTES
uint64_t
simde_pext_u64(uint64_t a, uint64_t mask)
{
#if defined(SIMDE_ARCH_ARM_SVE2_BITPERM) && defined(SIMDE_ARM_SVE2_NATIVE)
  svuint64_t va = svdup_u64(a);
  svuint64_t r = svbext_n_u64(va, mask);
  return svlastb_u64(svptrue_b64(), r);
#else
  uint64_t r = 0;
  int k = 0;
  for (uint64_t m = mask; m; m >>= 1, a >>= 1) {
    if (m & 1) {
      r |= (a & 1) << k++;
    }
  }
  return r;
#endif
}
#if defined(SIMDE_X86_BMI2_NATIVE)
#define simde_pext_u64(a, mask) _pext_u64(a, mask)
#endif
#if defined(SIMDE_X86_BMI2_ENABLE_NATIVE_ALIASES)
#undef _pext_u64
#define _pext_u64(a, mask) simde_pext_u64(a, mask)
#endif

SIMDE_FUNCTION_ATTRIBUTES
uint32_t
simde_pdep_u32(uint32_t a, uint32_t mask)
{
#if defined(SIMDE_ARCH_ARM_SVE2_BITPERM) && defined(SIMDE_ARM_SVE2_NATIVE)
  svuint32_t va = svdup_u32(a);
  svuint32_t r = svbdep_n_u32(va, mask);
  return svlastb_u32(svptrue_b32(), r);
#else
  uint32_t r = 0;
  int k = 0;
  for (uint32_t m = mask; m; m >>= 1, k++) {
    if (m & 1) {
      r |= (a & 1) << k;
      a >>= 1;
    }
  }
  return r;
#endif
}
#if defined(SIMDE_X86_BMI2_NATIVE)
#define simde_pdep_u32(a, mask) _pdep_u32(a, mask)
#endif
#if defined(SIMDE_X86_BMI2_ENABLE_NATIVE_ALIASES)
#undef _pdep_u32
#define _pdep_u32(a, mask) simde_pdep_u32(a, mask)
#endif

SIMDE_FUNCTION_ATTRIBUTES
uint64_t
simde_pdep_u64(uint64_t a, uint64_t mask)
{
#if defined(SIMDE_ARCH_ARM_SVE2_BITPERM) && defined(SIMDE_ARM_SVE2_NATIVE)
  svuint64_t va = svdup_u64(a);
  svuint64_t r = svbdep_n_u64(va, mask);
  return svlastb_u64(svptrue_b64(), r);
#else
  uint64_t r = 0;
  int k = 0;
  for (uint64_t m = mask; m; m >>= 1, k++) {
    if (m & 1) {
      r |= (a & 1) << k;
      a >>= 1;
    }
  }
  return r;
#endif
}
#if defined(SIMDE_X86_BMI2_NATIVE)
#define simde_pdep_u64(a, mask) _pdep_u64(a, mask)
#endif
#if defined(SIMDE_X86_BMI2_ENABLE_NATIVE_ALIASES)
#undef _pdep_u64
#define _pdep_u64(a, mask) simde_pdep_u64(a, mask)
#endif

SIMDE_FUNCTION_ATTRIBUTES
uint32_t
simde_bextr_u32(uint32_t a, unsigned int start, unsigned int len) {
  const uint32_t mask = 0xffffffffu;
  if (len == 0 || start >= 32) return 0;
  if (len > 32 - start) len = 32 - start;
  return (a >> start) & (mask >> (32 - len));
}
#if defined(SIMDE_X86_BMI1_NATIVE)
#define simde_bextr_u32(a, start, len) _bextr_u32(a, start, len)
#endif
#if defined(SIMDE_X86_BMI1_ENABLE_NATIVE_ALIASES)
#undef _bextr_u32
#define _bextr_u32(a, start, len) simde_bextr_u32(a, start, len)
#endif

SIMDE_FUNCTION_ATTRIBUTES
uint64_t
simde_bextr_u64(uint64_t a, unsigned int start, unsigned int len) {
  const uint64_t mask = 0xffffffffffffffffull;
  if (len == 0 || start >= 64) return 0;
  if (len > 64 - start) len = 64 - start;
  return (a >> start) & (mask  >> (64 - len));
}
#if defined(SIMDE_X86_BMI1_NATIVE)
#define simde_bextr_u64(a, start, len) _bextr_u64(a, start, len)
#endif
#if defined(SIMDE_X86_BMI1_ENABLE_NATIVE_ALIASES)
#undef _bextr_u64
#define _bextr_u64(a, start, len) simde_bextr_u64(a, start, len)
#endif

#endif /* !defined(SIMDE_X86_BMI_H) */
