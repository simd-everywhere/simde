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

#if !defined(SIMDE_TEST_ARM_SVE_TEST_SVE_H)
#define SIMDE_TEST_ARM_SVE_TEST_SVE_H

#include "../../test.h"

HEDLEY_DIAGNOSTIC_PUSH
HEDLEY_DIAGNOSTIC_DISABLE_UNUSED_FUNCTION

static int32_t
simde_test_arm_sve_random_length(size_t buf_size, size_t elem_size) {
  return
    (simde_test_codegen_random_i32() & HEDLEY_STATIC_CAST(int32_t, (buf_size / elem_size) - 1)) |
    HEDLEY_STATIC_CAST(int32_t, (buf_size / 2) / elem_size);
}

HEDLEY_DIAGNOSTIC_POP

#if !defined(SIMDE_TEST_BARE)
  #define SIMDE_TEST_DECLARE_SUITE(name) SIMDE_TEST_SUITE_DECLARE_GETTERS(HEDLEY_CONCAT(simde_test_arm_sve_get_suite_,name))
  #include <test/arm/sve/declare-suites.h>
  #undef SIMDE_TEST_DECLARE_SUITE
#endif

#endif /* !defined(SIMDE_TEST_ARM_SVE_TEST_SVE_H) */
