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
 *   2023      Yi-Yen Chung <eric681@andestech.com> (Copyright owned by Andes Technology)
 */

#define SIMDE_TEST_ARM_NEON_INSN rax

#include "test-neon.h"
#include <simde/arm/neon/rax.h>

static int
test_simde_vrax1q_u64(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint64_t a[2];
    uint64_t b[2];
    uint64_t r[2];
  } test_vec[] = {
    { {  UINT64_C( 4463253348756302848),  UINT64_C(10860184980149432320) },
      {  UINT64_C(17184265194103961600),  UINT64_C( 8851118105240138752) },
      {  UINT64_C(16214406776591277057),  UINT64_C( 7142105075931748352) } },
    { {  UINT64_C( 8850082538103601152),  UINT64_C( 6252904576600180736) },
      {  UINT64_C( 6518498614509017088),  UINT64_C( 2880910590451577344) },
      {  UINT64_C(14861167135477090304),  UINT64_C( 1815195031014140928) } },
    { {  UINT64_C( 4077041553727459840),  UINT64_C( 6706187079421546496) },
      {  UINT64_C( 5199775657749716992),  UINT64_C(14890012628132425728) },
      {  UINT64_C(12161459947479290368),  UINT64_C(13859492151541346305) } },
    { {  UINT64_C(15010074573580812288),  UINT64_C( 1750632044653965824) },
      {  UINT64_C( 3595378033484251136),  UINT64_C(11336248542251048960) },
      {  UINT64_C(12935690285040320512),  UINT64_C( 2517403789658436097) } },
    { {  UINT64_C(18373308598954297344),  UINT64_C(14200586596764379136) },
      {  UINT64_C(11922247138848290816),  UINT64_C( 8263558129392568320) },
      {  UINT64_C(12975912749186775041),  UINT64_C( 2327941998128461824) } },
    { {  UINT64_C(11893293961318832128),  UINT64_C(15978523260235173888) },
      {  UINT64_C(14482266865050327040),  UINT64_C( 9699515201028962304) },
      {  UINT64_C( 3817863017225070593),  UINT64_C(15026310053840297985) } },
    { {  UINT64_C( 9911944287546439680),  UINT64_C( 3322222766186657792) },
      {  UINT64_C(10051117776438267904),  UINT64_C(15334687057494210560) },
      {  UINT64_C(11490706210324600833),  UINT64_C( 9765327101966452737) } },
    { {  UINT64_C( 6321102448965192704),  UINT64_C( 5664921145056367616) },
      {  UINT64_C( 8112175989108802560),  UINT64_C( 3134309188162928640) },
      {  UINT64_C(13155413661113451520),  UINT64_C( 1757332903660655616) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x2_t a = simde_vld1q_u64(test_vec[i].a);
    simde_uint64x2_t b = simde_vld1q_u64(test_vec[i].b);
    simde_uint64x2_t r = simde_vrax1q_u64(a, b);

    simde_test_arm_neon_assert_equal_u64x2(r, simde_vld1q_u64(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint64x2_t a = simde_test_arm_neon_random_u64x2();
    simde_uint64x2_t b = simde_test_arm_neon_random_u64x2();
    simde_uint64x2_t r = simde_vrax1q_u64(a, b);

    simde_test_arm_neon_write_u64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vrax1q_u64)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
