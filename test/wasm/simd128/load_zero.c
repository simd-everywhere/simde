/* Copyright (c) 2021 Evan Nemerson <evan@nemerson.com>
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
 */

#define SIMDE_TEST_WASM_SIMD128_INSN load_zero
#include "../../../simde/wasm/simd128.h"
#include "test-simd128.h"

static int
test_simde_wasm_v128_load32_zero(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      int32_t a;
      int32_t r[sizeof(simde_v128_t) / sizeof(int16_t)];
    } test_vec[] = {
      { -INT32_C(  1663987737),
        { -INT32_C(  1663987737),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
      { -INT32_C(   443825017),
        { -INT32_C(   443825017),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
      {  INT32_C(   395819065),
        {  INT32_C(   395819065),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
      { -INT32_C(  1306750047),
        { -INT32_C(  1306750047),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
      {  INT32_C(  1307801713),
        {  INT32_C(  1307801713),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
      { -INT32_C(   478359472),
        { -INT32_C(   478359472),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
      {  INT32_C(  1705130081),
        {  INT32_C(  1705130081),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
      {  INT32_C(  1894984934),
        {  INT32_C(  1894984934),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t r = simde_wasm_v128_load32_zero(&(test_vec[i].a));
      simde_test_wasm_i32x4_assert_equal(r, simde_wasm_v128_load(test_vec[i].r));
    }
    return 0;
  #else
    fputc('\n', stdout);
    for (int i = 0 ; i < 8 ; i++) {
      int32_t a = simde_test_codegen_random_i32();
      simde_v128_t r;

      r = simde_wasm_v128_load32_zero(&a);

      simde_test_codegen_write_i32(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_i32x4_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_v128_load64_zero(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      int64_t a;
      int64_t r[sizeof(simde_v128_t) / sizeof(int16_t)];
    } test_vec[] = {
      {  INT64_C(  629350488805579936),
        {  INT64_C(  629350488805579936),  INT64_C(                   0) } },
      {  INT64_C( 7989076400909386161),
        {  INT64_C( 7989076400909386161),  INT64_C(                   0) } },
      {  INT64_C( 9067182422419151710),
        {  INT64_C( 9067182422419151710),  INT64_C(                   0) } },
      {  INT64_C(  301869024279662759),
        {  INT64_C(  301869024279662759),  INT64_C(                   0) } },
      { -INT64_C( 7900487491134283995),
        { -INT64_C( 7900487491134283995),  INT64_C(                   0) } },
      {  INT64_C( 5365458524930490530),
        {  INT64_C( 5365458524930490530),  INT64_C(                   0) } },
      { -INT64_C( 1238706882052499426),
        { -INT64_C( 1238706882052499426),  INT64_C(                   0) } },
      { -INT64_C( 7877366110503050539),
        { -INT64_C( 7877366110503050539),  INT64_C(                   0) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t r = simde_wasm_v128_load64_zero(&(test_vec[i].a));
      simde_test_wasm_i64x2_assert_equal(r, simde_wasm_v128_load(test_vec[i].r));
    }
    return 0;
  #else
    fputc('\n', stdout);
    for (int i = 0 ; i < 8 ; i++) {
      int64_t a = simde_test_codegen_random_i64();
      simde_v128_t r;

      r = simde_wasm_v128_load64_zero(&a);

      simde_test_codegen_write_i64(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_i64x2_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_v128_load32_zero)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_v128_load64_zero)
SIMDE_TEST_FUNC_LIST_END

#include "test-simd128-footer.h"
