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

#define SIMDE_TEST_WASM_RELAXED_SIMD_INSN trunc
#include "../../../simde/wasm/relaxed-simd.h"
#include "test-relaxed-simd.h"

static int
test_simde_wasm_i32x4_trunc_f32x4(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      simde_float32 a[sizeof(simde_v128_t) / sizeof(simde_float32)];
      int32_t r[sizeof(simde_v128_t) / sizeof(int32_t)];
    } test_vec[] = {
      { { SIMDE_FLOAT32_C(1196434176.00), SIMDE_FLOAT32_C(562159616.00), SIMDE_FLOAT32_C(1817538176.00), SIMDE_FLOAT32_C(-553928448.00) },
        {  INT32_C(  1196434176),  INT32_C(   562159616),  INT32_C(  1817538176), -INT32_C(   553928448) } },
      { { SIMDE_FLOAT32_C(-917483520.00), SIMDE_FLOAT32_C(-1259906048.00), SIMDE_FLOAT32_C(1148161536.00), SIMDE_FLOAT32_C(-1375460352.00) },
        { -INT32_C(   917483520), -INT32_C(  1259906048),  INT32_C(  1148161536), -INT32_C(  1375460352) } },
      { { SIMDE_FLOAT32_C(-793209728.00), SIMDE_FLOAT32_C(507892992.00), SIMDE_FLOAT32_C(2107121152.00), SIMDE_FLOAT32_C(1676560896.00) },
        { -INT32_C(   793209728),  INT32_C(   507892992),  INT32_C(  2107121152),  INT32_C(  1676560896) } },
      { { SIMDE_FLOAT32_C(-1060059648.00), SIMDE_FLOAT32_C(1394152448.00), SIMDE_FLOAT32_C(-1032503808.00), SIMDE_FLOAT32_C(-248031360.00) },
        { -INT32_C(  1060059648),  INT32_C(  1394152448), -INT32_C(  1032503808), -INT32_C(   248031360) } },
      { { SIMDE_FLOAT32_C(449856768.00), SIMDE_FLOAT32_C(-2101327616.00), SIMDE_FLOAT32_C(-207199744.00), SIMDE_FLOAT32_C(-1684930688.00) },
        {  INT32_C(   449856768), -INT32_C(  2101327616), -INT32_C(   207199744), -INT32_C(  1684930688) } },
      { { SIMDE_FLOAT32_C(556814848.00), SIMDE_FLOAT32_C(495534336.00), SIMDE_FLOAT32_C(2086857472.00), SIMDE_FLOAT32_C(1929632768.00) },
        {  INT32_C(   556814848),  INT32_C(   495534336),  INT32_C(  2086857472),  INT32_C(  1929632768) } },
      { { SIMDE_FLOAT32_C(-1696075392.00), SIMDE_FLOAT32_C(-782602048.00), SIMDE_FLOAT32_C(-1940255360.00), SIMDE_FLOAT32_C(-1691461504.00) },
        { -INT32_C(  1696075392), -INT32_C(   782602048), -INT32_C(  1940255360), -INT32_C(  1691461504) } },
      { { SIMDE_FLOAT32_C(1013248768.00), SIMDE_FLOAT32_C(-909308544.00), SIMDE_FLOAT32_C(-1709259648.00), SIMDE_FLOAT32_C(62199040.00) },
        {  INT32_C(  1013248768), -INT32_C(   909308544), -INT32_C(  1709259648),  INT32_C(    62199040) } },
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t r = simde_wasm_i32x4_trunc_f32x4(a);
      simde_test_wasm_i32x4_assert_equal(r, simde_wasm_v128_load(test_vec[i].r));
    }
    return 0;
  #else
    fputc('\n', stdout);
    for (int i = 0 ; i < 8 ; i++) {
      simde_v128_t
        a = simde_test_wasm_f32x4_random(HEDLEY_STATIC_CAST(simde_float32, INT32_MIN), HEDLEY_STATIC_CAST(simde_float32, INT32_MAX)),
        r;

      r = simde_wasm_i32x4_trunc_f32x4(a);

      simde_test_wasm_f32x4_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_i32x4_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_u32x4_trunc_f32x4(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      simde_float32 a[sizeof(simde_v128_t) / sizeof(simde_float32)];
      uint32_t r[sizeof(simde_v128_t) / sizeof(uint32_t)];
    } test_vec[] = {
      { { SIMDE_FLOAT32_C(2988936192.00), SIMDE_FLOAT32_C(3863598080.00), SIMDE_FLOAT32_C(1913599488.00), SIMDE_FLOAT32_C(3828685568.00) },
        { UINT32_C(2988936192), UINT32_C(3863598080), UINT32_C(1913599488), UINT32_C(3828685568) } },
      { { SIMDE_FLOAT32_C(612808448.00), SIMDE_FLOAT32_C(2608920576.00), SIMDE_FLOAT32_C(1426784640.00), SIMDE_FLOAT32_C(3479707904.00) },
        { UINT32_C( 612808448), UINT32_C(2608920576), UINT32_C(1426784640), UINT32_C(3479707904) } },
      { { SIMDE_FLOAT32_C(1876159232.00), SIMDE_FLOAT32_C(1215616256.00), SIMDE_FLOAT32_C(3617364480.00), SIMDE_FLOAT32_C(3325470208.00) },
        { UINT32_C(1876159232), UINT32_C(1215616256), UINT32_C(3617364480), UINT32_C(3325470208) } },
      { { SIMDE_FLOAT32_C(2396343552.00), SIMDE_FLOAT32_C(3887605248.00), SIMDE_FLOAT32_C(2828944128.00), SIMDE_FLOAT32_C(410412416.00) },
        { UINT32_C(2396343552), UINT32_C(3887605248), UINT32_C(2828944128), UINT32_C( 410412416) } },
      { { SIMDE_FLOAT32_C(3389382400.00), SIMDE_FLOAT32_C(148869808.00), SIMDE_FLOAT32_C(1351892352.00), SIMDE_FLOAT32_C(2799121920.00) },
        { UINT32_C(3389382400), UINT32_C( 148869808), UINT32_C(1351892352), UINT32_C(2799121920) } },
      { { SIMDE_FLOAT32_C(2491012864.00), SIMDE_FLOAT32_C(449565600.00), SIMDE_FLOAT32_C(1779601792.00), SIMDE_FLOAT32_C(387340320.00) },
        { UINT32_C(2491012864), UINT32_C( 449565600), UINT32_C(1779601792), UINT32_C( 387340320) } },
      { { SIMDE_FLOAT32_C(3143272448.00), SIMDE_FLOAT32_C(501831104.00), SIMDE_FLOAT32_C(2874208512.00), SIMDE_FLOAT32_C(2527360000.00) },
        { UINT32_C(3143272448), UINT32_C( 501831104), UINT32_C(2874208512), UINT32_C(2527360000) } },
      { { SIMDE_FLOAT32_C(1166117504.00), SIMDE_FLOAT32_C(4222391296.00), SIMDE_FLOAT32_C(1749291520.00), SIMDE_FLOAT32_C(4155053824.00) },
        { UINT32_C(1166117504), UINT32_C(4222391296), UINT32_C(1749291520), UINT32_C(4155053824) } },
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t r = simde_wasm_u32x4_trunc_f32x4(a);
      simde_test_wasm_u32x4_assert_equal(r, simde_wasm_v128_load(test_vec[i].r));
    }
    return 0;
  #else
    fputc('\n', stdout);
    for (int i = 0 ; i < 8 ; i++) {
      simde_v128_t
        a = simde_test_wasm_f32x4_random(SIMDE_FLOAT32_C(0.0), HEDLEY_STATIC_CAST(simde_float32, UINT32_MAX)),
        r;

      r = simde_wasm_u32x4_trunc_f32x4(a);

      simde_test_wasm_f32x4_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_u32x4_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_i32x4_trunc_f64x2_zero(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      simde_float64 a[sizeof(simde_v128_t) / sizeof(simde_float64)];
      int32_t r[sizeof(simde_v128_t) / sizeof(int32_t)];
    } test_vec[] = {
      { { SIMDE_FLOAT64_C(1643538592.88), SIMDE_FLOAT64_C(1515407276.85) },
        {  INT32_C(  1643538592),  INT32_C(  1515407276),  INT32_C(           0),  INT32_C(           0) } },
      { { SIMDE_FLOAT64_C(1541288496.86), SIMDE_FLOAT64_C(-2038620287.97) },
        {  INT32_C(  1541288496), -INT32_C(  2038620287),  INT32_C(           0),  INT32_C(           0) } },
      { { SIMDE_FLOAT64_C(-170639465.54), SIMDE_FLOAT64_C(-1326894167.81) },
        { -INT32_C(   170639465), -INT32_C(  1326894167),  INT32_C(           0),  INT32_C(           0) } },
      { { SIMDE_FLOAT64_C(1441087532.84), SIMDE_FLOAT64_C(1705519748.90) },
        {  INT32_C(  1441087532),  INT32_C(  1705519748),  INT32_C(           0),  INT32_C(           0) } },
      { { SIMDE_FLOAT64_C(-111277905.53), SIMDE_FLOAT64_C(763484734.68) },
        { -INT32_C(   111277905),  INT32_C(   763484734),  INT32_C(           0),  INT32_C(           0) } },
      { { SIMDE_FLOAT64_C(736022776.67), SIMDE_FLOAT64_C(-2009901581.97) },
        {  INT32_C(   736022776), -INT32_C(  2009901581),  INT32_C(           0),  INT32_C(           0) } },
      { { SIMDE_FLOAT64_C(356122562.58), SIMDE_FLOAT64_C(-730000503.67) },
        {  INT32_C(   356122562), -INT32_C(   730000503),  INT32_C(           0),  INT32_C(           0) } },
      { { SIMDE_FLOAT64_C(-1599489173.87), SIMDE_FLOAT64_C(-549462263.63) },
        { -INT32_C(  1599489173), -INT32_C(   549462263),  INT32_C(           0),  INT32_C(           0) } },
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t r = simde_wasm_i32x4_trunc_f64x2_zero(a);
      simde_test_wasm_i32x4_assert_equal(r, simde_wasm_v128_load(test_vec[i].r));
    }
    return 0;
  #else
    fputc('\n', stdout);
    for (int i = 0 ; i < 8 ; i++) {
      simde_v128_t
        a = simde_test_wasm_f64x2_random(HEDLEY_STATIC_CAST(simde_float64, INT32_MIN), HEDLEY_STATIC_CAST(simde_float64, INT32_MAX)),
        r;

      r = simde_wasm_i32x4_trunc_f64x2_zero(a);

      simde_test_wasm_f64x2_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_i32x4_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_u32x4_trunc_f64x2_zero(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      simde_float64 a[sizeof(simde_v128_t) / sizeof(simde_float64)];
      uint32_t r[sizeof(simde_v128_t) / sizeof(uint32_t)];
    } test_vec[] = {
      { { SIMDE_FLOAT64_C(1566352946.36), SIMDE_FLOAT64_C(1899886804.44) },
        { UINT32_C(1566352946), UINT32_C(1899886804), UINT32_C(         0), UINT32_C(         0) } },
      { { SIMDE_FLOAT64_C(102176116.02), SIMDE_FLOAT64_C(4057365914.94) },
        { UINT32_C( 102176116), UINT32_C(4057365914), UINT32_C(         0), UINT32_C(         0) } },
      { { SIMDE_FLOAT64_C(2349452452.55), SIMDE_FLOAT64_C(1881777742.44) },
        { UINT32_C(2349452452), UINT32_C(1881777742), UINT32_C(         0), UINT32_C(         0) } },
      { { SIMDE_FLOAT64_C(149738930.03), SIMDE_FLOAT64_C(1197757476.28) },
        { UINT32_C( 149738930), UINT32_C(1197757476), UINT32_C(         0), UINT32_C(         0) } },
      { { SIMDE_FLOAT64_C(2383608838.55), SIMDE_FLOAT64_C(3023947188.70) },
        { UINT32_C(2383608838), UINT32_C(3023947188), UINT32_C(         0), UINT32_C(         0) } },
      { { SIMDE_FLOAT64_C(3725117572.87), SIMDE_FLOAT64_C(3549726344.83) },
        { UINT32_C(3725117572), UINT32_C(3549726344), UINT32_C(         0), UINT32_C(         0) } },
      { { SIMDE_FLOAT64_C(2951371180.69), SIMDE_FLOAT64_C(1179441762.27) },
        { UINT32_C(2951371180), UINT32_C(1179441762), UINT32_C(         0), UINT32_C(         0) } },
      { { SIMDE_FLOAT64_C(3409812860.79), SIMDE_FLOAT64_C(2447426124.57) },
        { UINT32_C(3409812860), UINT32_C(2447426124), UINT32_C(         0), UINT32_C(         0) } },
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t r = simde_wasm_u32x4_trunc_f64x2_zero(a);
      simde_test_wasm_u32x4_assert_equal(r, simde_wasm_v128_load(test_vec[i].r));
    }
    return 0;
  #else
    fputc('\n', stdout);
    for (int i = 0 ; i < 8 ; i++) {
      simde_v128_t
        a = simde_test_wasm_f64x2_random(SIMDE_FLOAT64_C(0.0), HEDLEY_STATIC_CAST(simde_float64, UINT32_MAX)),
        r;

      r = simde_wasm_u32x4_trunc_f64x2_zero(a);

      simde_test_wasm_f64x2_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_u32x4_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_i32x4_trunc_f32x4)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_u32x4_trunc_f32x4)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_i32x4_trunc_f64x2_zero)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_u32x4_trunc_f64x2_zero)
SIMDE_TEST_FUNC_LIST_END

#include "test-relaxed-simd-footer.h"
