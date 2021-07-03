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

#define SIMDE_TEST_WASM_SIMD128_INSN load_splat
#include "../../../simde/wasm/simd128.h"
#include "test-simd128.h"

static int
test_simde_wasm_v128_load8_splat(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      int8_t a;
      int8_t r[sizeof(simde_v128_t) / sizeof(int8_t)];
    } test_vec[8] = {
      {  INT8_C(  31),
        {  INT8_C(  31),  INT8_C(  31),  INT8_C(  31),  INT8_C(  31),  INT8_C(  31),  INT8_C(  31),  INT8_C(  31),  INT8_C(  31),
           INT8_C(  31),  INT8_C(  31),  INT8_C(  31),  INT8_C(  31),  INT8_C(  31),  INT8_C(  31),  INT8_C(  31),  INT8_C(  31) } },
      { -INT8_C(  13),
        { -INT8_C(  13), -INT8_C(  13), -INT8_C(  13), -INT8_C(  13), -INT8_C(  13), -INT8_C(  13), -INT8_C(  13), -INT8_C(  13),
          -INT8_C(  13), -INT8_C(  13), -INT8_C(  13), -INT8_C(  13), -INT8_C(  13), -INT8_C(  13), -INT8_C(  13), -INT8_C(  13) } },
      {  INT8_C(  44),
        {  INT8_C(  44),  INT8_C(  44),  INT8_C(  44),  INT8_C(  44),  INT8_C(  44),  INT8_C(  44),  INT8_C(  44),  INT8_C(  44),
           INT8_C(  44),  INT8_C(  44),  INT8_C(  44),  INT8_C(  44),  INT8_C(  44),  INT8_C(  44),  INT8_C(  44),  INT8_C(  44) } },
      { -INT8_C(   9),
        { -INT8_C(   9), -INT8_C(   9), -INT8_C(   9), -INT8_C(   9), -INT8_C(   9), -INT8_C(   9), -INT8_C(   9), -INT8_C(   9),
          -INT8_C(   9), -INT8_C(   9), -INT8_C(   9), -INT8_C(   9), -INT8_C(   9), -INT8_C(   9), -INT8_C(   9), -INT8_C(   9) } },
      {  INT8_C(  59),
        {  INT8_C(  59),  INT8_C(  59),  INT8_C(  59),  INT8_C(  59),  INT8_C(  59),  INT8_C(  59),  INT8_C(  59),  INT8_C(  59),
           INT8_C(  59),  INT8_C(  59),  INT8_C(  59),  INT8_C(  59),  INT8_C(  59),  INT8_C(  59),  INT8_C(  59),  INT8_C(  59) } },
      {  INT8_C(  24),
        {  INT8_C(  24),  INT8_C(  24),  INT8_C(  24),  INT8_C(  24),  INT8_C(  24),  INT8_C(  24),  INT8_C(  24),  INT8_C(  24),
           INT8_C(  24),  INT8_C(  24),  INT8_C(  24),  INT8_C(  24),  INT8_C(  24),  INT8_C(  24),  INT8_C(  24),  INT8_C(  24) } },
      {  INT8_C(  84),
        {  INT8_C(  84),  INT8_C(  84),  INT8_C(  84),  INT8_C(  84),  INT8_C(  84),  INT8_C(  84),  INT8_C(  84),  INT8_C(  84),
           INT8_C(  84),  INT8_C(  84),  INT8_C(  84),  INT8_C(  84),  INT8_C(  84),  INT8_C(  84),  INT8_C(  84),  INT8_C(  84) } },
      { -INT8_C( 102),
        { -INT8_C( 102), -INT8_C( 102), -INT8_C( 102), -INT8_C( 102), -INT8_C( 102), -INT8_C( 102), -INT8_C( 102), -INT8_C( 102),
          -INT8_C( 102), -INT8_C( 102), -INT8_C( 102), -INT8_C( 102), -INT8_C( 102), -INT8_C( 102), -INT8_C( 102), -INT8_C( 102) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t r = simde_wasm_v128_load8_splat(&(test_vec[i].a));
      simde_test_wasm_i8x16_assert_equal(r, simde_wasm_v128_load(test_vec[i].r));
    }
    return 0;
  #else
    fputc('\n', stdout);
    for (int i = 0 ; i < 8 ; i++) {
      int8_t a = simde_test_codegen_random_i8();
      simde_v128_t r;

      r = simde_wasm_v128_load8_splat(&a);

      simde_test_codegen_write_i8(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_i8x16_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_v128_load16_splat(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      int16_t a;
      int16_t r[sizeof(simde_v128_t) / sizeof(int16_t)];
    } test_vec[8] = {
      {  INT16_C( 21406),
        {  INT16_C( 21406),  INT16_C( 21406),  INT16_C( 21406),  INT16_C( 21406),  INT16_C( 21406),  INT16_C( 21406),  INT16_C( 21406),  INT16_C( 21406) } },
      { -INT16_C( 23942),
        { -INT16_C( 23942), -INT16_C( 23942), -INT16_C( 23942), -INT16_C( 23942), -INT16_C( 23942), -INT16_C( 23942), -INT16_C( 23942), -INT16_C( 23942) } },
      {  INT16_C(  6955),
        {  INT16_C(  6955),  INT16_C(  6955),  INT16_C(  6955),  INT16_C(  6955),  INT16_C(  6955),  INT16_C(  6955),  INT16_C(  6955),  INT16_C(  6955) } },
      {  INT16_C( 30002),
        {  INT16_C( 30002),  INT16_C( 30002),  INT16_C( 30002),  INT16_C( 30002),  INT16_C( 30002),  INT16_C( 30002),  INT16_C( 30002),  INT16_C( 30002) } },
      {  INT16_C( 11751),
        {  INT16_C( 11751),  INT16_C( 11751),  INT16_C( 11751),  INT16_C( 11751),  INT16_C( 11751),  INT16_C( 11751),  INT16_C( 11751),  INT16_C( 11751) } },
      { -INT16_C( 24371),
        { -INT16_C( 24371), -INT16_C( 24371), -INT16_C( 24371), -INT16_C( 24371), -INT16_C( 24371), -INT16_C( 24371), -INT16_C( 24371), -INT16_C( 24371) } },
      {  INT16_C( 21841),
        {  INT16_C( 21841),  INT16_C( 21841),  INT16_C( 21841),  INT16_C( 21841),  INT16_C( 21841),  INT16_C( 21841),  INT16_C( 21841),  INT16_C( 21841) } },
      {  INT16_C( 30322),
        {  INT16_C( 30322),  INT16_C( 30322),  INT16_C( 30322),  INT16_C( 30322),  INT16_C( 30322),  INT16_C( 30322),  INT16_C( 30322),  INT16_C( 30322) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t r = simde_wasm_v128_load16_splat(&(test_vec[i].a));
      simde_test_wasm_i16x8_assert_equal(r, simde_wasm_v128_load(test_vec[i].r));
    }
    return 0;
  #else
    fputc('\n', stdout);
    for (int i = 0 ; i < 8 ; i++) {
      int16_t a = simde_test_codegen_random_i16();
      simde_v128_t r;

      r = simde_wasm_v128_load16_splat(&a);

      simde_test_codegen_write_i16(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_i16x8_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_v128_load32_splat(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      int32_t a;
      int32_t r[sizeof(simde_v128_t) / sizeof(int32_t)];
    } test_vec[8] = {
      { -INT32_C(   107343908),
        { -INT32_C(   107343908), -INT32_C(   107343908), -INT32_C(   107343908), -INT32_C(   107343908) } },
      {  INT32_C(   124744470),
        {  INT32_C(   124744470),  INT32_C(   124744470),  INT32_C(   124744470),  INT32_C(   124744470) } },
      {  INT32_C(  1790061704),
        {  INT32_C(  1790061704),  INT32_C(  1790061704),  INT32_C(  1790061704),  INT32_C(  1790061704) } },
      { -INT32_C(   604916921),
        { -INT32_C(   604916921), -INT32_C(   604916921), -INT32_C(   604916921), -INT32_C(   604916921) } },
      {  INT32_C(  1353672078),
        {  INT32_C(  1353672078),  INT32_C(  1353672078),  INT32_C(  1353672078),  INT32_C(  1353672078) } },
      { -INT32_C(  1448915144),
        { -INT32_C(  1448915144), -INT32_C(  1448915144), -INT32_C(  1448915144), -INT32_C(  1448915144) } },
      { -INT32_C(   259587493),
        { -INT32_C(   259587493), -INT32_C(   259587493), -INT32_C(   259587493), -INT32_C(   259587493) } },
      { -INT32_C(  1145925498),
        { -INT32_C(  1145925498), -INT32_C(  1145925498), -INT32_C(  1145925498), -INT32_C(  1145925498) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t r = simde_wasm_v128_load32_splat(&(test_vec[i].a));
      simde_test_wasm_i32x4_assert_equal(r, simde_wasm_v128_load(test_vec[i].r));
    }
    return 0;
  #else
    fputc('\n', stdout);
    for (int i = 0 ; i < 8 ; i++) {
      int32_t a = simde_test_codegen_random_i32();
      simde_v128_t r;

      r = simde_wasm_v128_load32_splat(&a);

      simde_test_codegen_write_i32(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_i32x4_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_v128_load64_splat(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      int64_t a;
      int64_t r[sizeof(simde_v128_t) / sizeof(int64_t)];
    } test_vec[8] = {
      { -INT64_C( 1756618613288815525),
        { -INT64_C( 1756618613288815525), -INT64_C( 1756618613288815525) } },
      { -INT64_C( 4913853351710458179),
        { -INT64_C( 4913853351710458179), -INT64_C( 4913853351710458179) } },
      { -INT64_C( 1158565484908880836),
        { -INT64_C( 1158565484908880836), -INT64_C( 1158565484908880836) } },
      {  INT64_C( 8816887017734015573),
        {  INT64_C( 8816887017734015573),  INT64_C( 8816887017734015573) } },
      {  INT64_C( 4806413787977121547),
        {  INT64_C( 4806413787977121547),  INT64_C( 4806413787977121547) } },
      {  INT64_C( 8001887655388723035),
        {  INT64_C( 8001887655388723035),  INT64_C( 8001887655388723035) } },
      {  INT64_C( 1874232494995779678),
        {  INT64_C( 1874232494995779678),  INT64_C( 1874232494995779678) } },
      {  INT64_C( 3956841799013427418),
        {  INT64_C( 3956841799013427418),  INT64_C( 3956841799013427418) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t r = simde_wasm_v128_load64_splat(&(test_vec[i].a));
      simde_test_wasm_i64x2_assert_equal(r, simde_wasm_v128_load(test_vec[i].r));
    }
    return 0;
  #else
    fputc('\n', stdout);
    for (int i = 0 ; i < 8 ; i++) {
      int64_t a = simde_test_codegen_random_i64();
      simde_v128_t r;

      r = simde_wasm_v128_load64_splat(&a);

      simde_test_codegen_write_i64(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_i64x2_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_v128_load8_splat)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_v128_load16_splat)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_v128_load32_splat)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_v128_load64_splat)
SIMDE_TEST_FUNC_LIST_END

#include "test-simd128-footer.h"
