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

#define SIMDE_TEST_WASM_SIMD128_INSN splat
#include "../../../simde/wasm/simd128.h"
#include "test-simd128.h"

static int
test_simde_wasm_i8x16_splat(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      int8_t a;
      int8_t r[sizeof(simde_v128_t) / sizeof(int8_t)];
    } test_vec[8] = {
      {  INT8_C( 110),
        {  INT8_C( 110),  INT8_C( 110),  INT8_C( 110),  INT8_C( 110),  INT8_C( 110),  INT8_C( 110),  INT8_C( 110),  INT8_C( 110),
           INT8_C( 110),  INT8_C( 110),  INT8_C( 110),  INT8_C( 110),  INT8_C( 110),  INT8_C( 110),  INT8_C( 110),  INT8_C( 110) } },
      { -INT8_C(  74),
        { -INT8_C(  74), -INT8_C(  74), -INT8_C(  74), -INT8_C(  74), -INT8_C(  74), -INT8_C(  74), -INT8_C(  74), -INT8_C(  74),
          -INT8_C(  74), -INT8_C(  74), -INT8_C(  74), -INT8_C(  74), -INT8_C(  74), -INT8_C(  74), -INT8_C(  74), -INT8_C(  74) } },
      {  INT8_C(   4),
        {  INT8_C(   4),  INT8_C(   4),  INT8_C(   4),  INT8_C(   4),  INT8_C(   4),  INT8_C(   4),  INT8_C(   4),  INT8_C(   4),
           INT8_C(   4),  INT8_C(   4),  INT8_C(   4),  INT8_C(   4),  INT8_C(   4),  INT8_C(   4),  INT8_C(   4),  INT8_C(   4) } },
      { -INT8_C(  90),
        { -INT8_C(  90), -INT8_C(  90), -INT8_C(  90), -INT8_C(  90), -INT8_C(  90), -INT8_C(  90), -INT8_C(  90), -INT8_C(  90),
          -INT8_C(  90), -INT8_C(  90), -INT8_C(  90), -INT8_C(  90), -INT8_C(  90), -INT8_C(  90), -INT8_C(  90), -INT8_C(  90) } },
      {  INT8_C(  17),
        {  INT8_C(  17),  INT8_C(  17),  INT8_C(  17),  INT8_C(  17),  INT8_C(  17),  INT8_C(  17),  INT8_C(  17),  INT8_C(  17),
           INT8_C(  17),  INT8_C(  17),  INT8_C(  17),  INT8_C(  17),  INT8_C(  17),  INT8_C(  17),  INT8_C(  17),  INT8_C(  17) } },
      { -INT8_C(  38),
        { -INT8_C(  38), -INT8_C(  38), -INT8_C(  38), -INT8_C(  38), -INT8_C(  38), -INT8_C(  38), -INT8_C(  38), -INT8_C(  38),
          -INT8_C(  38), -INT8_C(  38), -INT8_C(  38), -INT8_C(  38), -INT8_C(  38), -INT8_C(  38), -INT8_C(  38), -INT8_C(  38) } },
      {  INT8_C(   3),
        {  INT8_C(   3),  INT8_C(   3),  INT8_C(   3),  INT8_C(   3),  INT8_C(   3),  INT8_C(   3),  INT8_C(   3),  INT8_C(   3),
           INT8_C(   3),  INT8_C(   3),  INT8_C(   3),  INT8_C(   3),  INT8_C(   3),  INT8_C(   3),  INT8_C(   3),  INT8_C(   3) } },
      {  INT8_C(  37),
        {  INT8_C(  37),  INT8_C(  37),  INT8_C(  37),  INT8_C(  37),  INT8_C(  37),  INT8_C(  37),  INT8_C(  37),  INT8_C(  37),
           INT8_C(  37),  INT8_C(  37),  INT8_C(  37),  INT8_C(  37),  INT8_C(  37),  INT8_C(  37),  INT8_C(  37),  INT8_C(  37) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t r = simde_wasm_i8x16_splat(test_vec[i].a);
      simde_test_wasm_i8x16_assert_equal(r, simde_wasm_v128_load(test_vec[i].r));
    }
    return 0;
  #else
    fputc('\n', stdout);
    for (int i = 0 ; i < 8 ; i++) {
      int8_t a = simde_test_codegen_random_i8();
      simde_v128_t r;

      r = simde_wasm_i8x16_splat(a);

      simde_test_codegen_write_i8(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_i8x16_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_i16x8_splat(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      int16_t a;
      int16_t r[sizeof(simde_v128_t) / sizeof(int16_t)];
    } test_vec[8] = {
      {  INT16_C( 10757),
        {  INT16_C( 10757),  INT16_C( 10757),  INT16_C( 10757),  INT16_C( 10757),  INT16_C( 10757),  INT16_C( 10757),  INT16_C( 10757),  INT16_C( 10757) } },
      {  INT16_C(  3379),
        {  INT16_C(  3379),  INT16_C(  3379),  INT16_C(  3379),  INT16_C(  3379),  INT16_C(  3379),  INT16_C(  3379),  INT16_C(  3379),  INT16_C(  3379) } },
      { -INT16_C(  2123),
        { -INT16_C(  2123), -INT16_C(  2123), -INT16_C(  2123), -INT16_C(  2123), -INT16_C(  2123), -INT16_C(  2123), -INT16_C(  2123), -INT16_C(  2123) } },
      {  INT16_C( 19159),
        {  INT16_C( 19159),  INT16_C( 19159),  INT16_C( 19159),  INT16_C( 19159),  INT16_C( 19159),  INT16_C( 19159),  INT16_C( 19159),  INT16_C( 19159) } },
      { -INT16_C( 29304),
        { -INT16_C( 29304), -INT16_C( 29304), -INT16_C( 29304), -INT16_C( 29304), -INT16_C( 29304), -INT16_C( 29304), -INT16_C( 29304), -INT16_C( 29304) } },
      { -INT16_C(  2227),
        { -INT16_C(  2227), -INT16_C(  2227), -INT16_C(  2227), -INT16_C(  2227), -INT16_C(  2227), -INT16_C(  2227), -INT16_C(  2227), -INT16_C(  2227) } },
      {  INT16_C(  5895),
        {  INT16_C(  5895),  INT16_C(  5895),  INT16_C(  5895),  INT16_C(  5895),  INT16_C(  5895),  INT16_C(  5895),  INT16_C(  5895),  INT16_C(  5895) } },
      { -INT16_C( 10706),
        { -INT16_C( 10706), -INT16_C( 10706), -INT16_C( 10706), -INT16_C( 10706), -INT16_C( 10706), -INT16_C( 10706), -INT16_C( 10706), -INT16_C( 10706) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t r = simde_wasm_i16x8_splat(test_vec[i].a);
      simde_test_wasm_i16x8_assert_equal(r, simde_wasm_v128_load(test_vec[i].r));
    }
    return 0;
  #else
    fputc('\n', stdout);
    for (int i = 0 ; i < 8 ; i++) {
      int16_t a = simde_test_codegen_random_i16();
      simde_v128_t r;

      r = simde_wasm_i16x8_splat(a);

      simde_test_codegen_write_i16(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_i16x8_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_i32x4_splat(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      int32_t a;
      int32_t r[sizeof(simde_v128_t) / sizeof(int32_t)];
    } test_vec[8] = {
      {  INT32_C(   603881482),
        {  INT32_C(   603881482),  INT32_C(   603881482),  INT32_C(   603881482),  INT32_C(   603881482) } },
      { -INT32_C(   954623974),
        { -INT32_C(   954623974), -INT32_C(   954623974), -INT32_C(   954623974), -INT32_C(   954623974) } },
      {  INT32_C(  1855322919),
        {  INT32_C(  1855322919),  INT32_C(  1855322919),  INT32_C(  1855322919),  INT32_C(  1855322919) } },
      { -INT32_C(  1794642062),
        { -INT32_C(  1794642062), -INT32_C(  1794642062), -INT32_C(  1794642062), -INT32_C(  1794642062) } },
      { -INT32_C(    26506932),
        { -INT32_C(    26506932), -INT32_C(    26506932), -INT32_C(    26506932), -INT32_C(    26506932) } },
      {  INT32_C(  1198458724),
        {  INT32_C(  1198458724),  INT32_C(  1198458724),  INT32_C(  1198458724),  INT32_C(  1198458724) } },
      {  INT32_C(   339735158),
        {  INT32_C(   339735158),  INT32_C(   339735158),  INT32_C(   339735158),  INT32_C(   339735158) } },
      { -INT32_C(   965906634),
        { -INT32_C(   965906634), -INT32_C(   965906634), -INT32_C(   965906634), -INT32_C(   965906634) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t r = simde_wasm_i32x4_splat(test_vec[i].a);
      simde_test_wasm_i32x4_assert_equal(r, simde_wasm_v128_load(test_vec[i].r));
    }
    return 0;
  #else
    fputc('\n', stdout);
    for (int i = 0 ; i < 8 ; i++) {
      int32_t a = simde_test_codegen_random_i32();
      simde_v128_t r;

      r = simde_wasm_i32x4_splat(a);

      simde_test_codegen_write_i32(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_i32x4_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_i64x2_splat(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      int64_t a;
      int64_t r[sizeof(simde_v128_t) / sizeof(int64_t)];
    } test_vec[8] = {
      { -INT64_C(  247663184558754775),
        { -INT64_C(  247663184558754775), -INT64_C(  247663184558754775) } },
      { -INT64_C( 9149092932308377280),
        { -INT64_C( 9149092932308377280), -INT64_C( 9149092932308377280) } },
      {  INT64_C( 3325648116972821275),
        {  INT64_C( 3325648116972821275),  INT64_C( 3325648116972821275) } },
      {  INT64_C( 1534122929546164350),
        {  INT64_C( 1534122929546164350),  INT64_C( 1534122929546164350) } },
      { -INT64_C( 1031430905345914519),
        { -INT64_C( 1031430905345914519), -INT64_C( 1031430905345914519) } },
      {  INT64_C( 6132967977206274051),
        {  INT64_C( 6132967977206274051),  INT64_C( 6132967977206274051) } },
      {  INT64_C( 7401617413683461537),
        {  INT64_C( 7401617413683461537),  INT64_C( 7401617413683461537) } },
      {  INT64_C( 3138642831338160560),
        {  INT64_C( 3138642831338160560),  INT64_C( 3138642831338160560) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t r = simde_wasm_i64x2_splat(test_vec[i].a);
      simde_test_wasm_i64x2_assert_equal(r, simde_wasm_v128_load(test_vec[i].r));
    }
    return 0;
  #else
    fputc('\n', stdout);
    for (int i = 0 ; i < 8 ; i++) {
      int64_t a = simde_test_codegen_random_i64();
      simde_v128_t r;

      r = simde_wasm_i64x2_splat(a);

      simde_test_codegen_write_i64(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_i64x2_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_f32x4_splat(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      simde_float32 a;
      simde_float32 r[sizeof(simde_v128_t) / sizeof(simde_float32)];
    } test_vec[8] = {
      { SIMDE_FLOAT32_C(   579.43),
        { SIMDE_FLOAT32_C(   579.43), SIMDE_FLOAT32_C(   579.43), SIMDE_FLOAT32_C(   579.43), SIMDE_FLOAT32_C(   579.43) } },
      { SIMDE_FLOAT32_C(  -941.63),
        { SIMDE_FLOAT32_C(  -941.63), SIMDE_FLOAT32_C(  -941.63), SIMDE_FLOAT32_C(  -941.63), SIMDE_FLOAT32_C(  -941.63) } },
      { SIMDE_FLOAT32_C(  -498.66),
        { SIMDE_FLOAT32_C(  -498.66), SIMDE_FLOAT32_C(  -498.66), SIMDE_FLOAT32_C(  -498.66), SIMDE_FLOAT32_C(  -498.66) } },
      { SIMDE_FLOAT32_C(   569.82),
        { SIMDE_FLOAT32_C(   569.82), SIMDE_FLOAT32_C(   569.82), SIMDE_FLOAT32_C(   569.82), SIMDE_FLOAT32_C(   569.82) } },
      { SIMDE_FLOAT32_C(  -741.31),
        { SIMDE_FLOAT32_C(  -741.31), SIMDE_FLOAT32_C(  -741.31), SIMDE_FLOAT32_C(  -741.31), SIMDE_FLOAT32_C(  -741.31) } },
      { SIMDE_FLOAT32_C(   848.95),
        { SIMDE_FLOAT32_C(   848.95), SIMDE_FLOAT32_C(   848.95), SIMDE_FLOAT32_C(   848.95), SIMDE_FLOAT32_C(   848.95) } },
      { SIMDE_FLOAT32_C(  -572.09),
        { SIMDE_FLOAT32_C(  -572.09), SIMDE_FLOAT32_C(  -572.09), SIMDE_FLOAT32_C(  -572.09), SIMDE_FLOAT32_C(  -572.09) } },
      { SIMDE_FLOAT32_C(  -157.64),
        { SIMDE_FLOAT32_C(  -157.64), SIMDE_FLOAT32_C(  -157.64), SIMDE_FLOAT32_C(  -157.64), SIMDE_FLOAT32_C(  -157.64) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t r = simde_wasm_f32x4_splat(test_vec[i].a);
      simde_test_wasm_f32x4_assert_equal(r, simde_wasm_v128_load(test_vec[i].r), INT_MAX);
    }
    return 0;
  #else
    fputc('\n', stdout);
    for (int i = 0 ; i < 8 ; i++) {
      simde_float32 a = simde_test_codegen_random_f32(-SIMDE_FLOAT32_C(1000.0), SIMDE_FLOAT32_C(1000.0));
      simde_v128_t r;

      r = simde_wasm_f32x4_splat(a);

      simde_test_codegen_write_f32(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_f32x4_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_f64x2_splat(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      simde_float64 a;
      simde_float64 r[sizeof(simde_v128_t) / sizeof(simde_float64)];
    } test_vec[8] = {
      { SIMDE_FLOAT64_C(  -874.05),
        { SIMDE_FLOAT64_C(  -874.05), SIMDE_FLOAT64_C(  -874.05) } },
      { SIMDE_FLOAT64_C(   645.32),
        { SIMDE_FLOAT64_C(   645.32), SIMDE_FLOAT64_C(   645.32) } },
      { SIMDE_FLOAT64_C(  -634.05),
        { SIMDE_FLOAT64_C(  -634.05), SIMDE_FLOAT64_C(  -634.05) } },
      { SIMDE_FLOAT64_C(   402.78),
        { SIMDE_FLOAT64_C(   402.78), SIMDE_FLOAT64_C(   402.78) } },
      { SIMDE_FLOAT64_C(  -471.31),
        { SIMDE_FLOAT64_C(  -471.31), SIMDE_FLOAT64_C(  -471.31) } },
      { SIMDE_FLOAT64_C(   415.20),
        { SIMDE_FLOAT64_C(   415.20), SIMDE_FLOAT64_C(   415.20) } },
      { SIMDE_FLOAT64_C(  -208.73),
        { SIMDE_FLOAT64_C(  -208.73), SIMDE_FLOAT64_C(  -208.73) } },
      { SIMDE_FLOAT64_C(   514.90),
        { SIMDE_FLOAT64_C(   514.90), SIMDE_FLOAT64_C(   514.90) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t r = simde_wasm_f64x2_splat(test_vec[i].a);
      simde_test_wasm_f64x2_assert_equal(r, simde_wasm_v128_load(test_vec[i].r), INT_MAX);
    }
    return 0;
  #else
    fputc('\n', stdout);
    for (int i = 0 ; i < 8 ; i++) {
      simde_float64 a = simde_test_codegen_random_f64(-SIMDE_FLOAT64_C(1000.0), SIMDE_FLOAT64_C(1000.0));
      simde_v128_t r;

      r = simde_wasm_f64x2_splat(a);

      simde_test_codegen_write_f64(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_f64x2_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_i8x16_splat)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_i16x8_splat)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_i32x4_splat)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_i64x2_splat)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_f32x4_splat)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_f64x2_splat)
SIMDE_TEST_FUNC_LIST_END

#include "test-simd128-footer.h"
