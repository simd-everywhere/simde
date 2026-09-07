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
 *   2021      Atharva Nimbalkar <atharvakn@gmail.com>
 *   2023      Yi-Yen Chung <eric681@andestech.com> (Copyright owned by Andes Technology)
 */

#define SIMDE_TEST_ARM_NEON_INSN qrshrn_n

#include "test-neon.h"
#include <simde/arm/neon/qrshrn_n.h>

static int
test_simde_vqrshrnh_n_u16 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    uint16_t a;
    uint8_t r1;
    uint8_t r3;
    uint8_t r5;
    uint8_t r7;
    uint8_t r8;
  } test_vec[] = {
    {  UINT16_C(  32767),
             UINT8_MAX,
             UINT8_MAX,
             UINT8_MAX,
             UINT8_MAX,
       UINT8_C( 128) },
    {  UINT16_C(   29541),
             UINT8_MAX,
             UINT8_MAX,
             UINT8_MAX,
       UINT8_C( 231),
       UINT8_C( 115) },
    { UINT16_C(  12766),
             UINT8_MAX,
             UINT8_MAX,
             UINT8_MAX,
       UINT8_C( 100),
       UINT8_C(  50) },
    {  UINT16_C(  5687),
             UINT8_MAX,
             UINT8_MAX,
       UINT8_C( 178),
       UINT8_C( 44),
       UINT8_C(  22) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    uint16_t r1 = simde_vqrshrnh_n_u16(test_vec[i].a, 1);
    uint16_t r3 = simde_vqrshrnh_n_u16(test_vec[i].a, 3);
    uint16_t r5 = simde_vqrshrnh_n_u16(test_vec[i].a, 5);
    uint16_t r7 = simde_vqrshrnh_n_u16(test_vec[i].a, 7);
    uint16_t r8 = simde_vqrshrnh_n_u16(test_vec[i].a, 8);

    simde_assert_equal_u16(r1, test_vec[i].r1);
    simde_assert_equal_u16(r3, test_vec[i].r3);
    simde_assert_equal_u16(r5, test_vec[i].r5);
    simde_assert_equal_u16(r7, test_vec[i].r7);
    simde_assert_equal_u16(r8, test_vec[i].r8);
  }

  return 0;
}


SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vqrshrnh_n_u16)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
