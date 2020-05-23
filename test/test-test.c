/* Quick program to test the top-level code in the test suite. */

#define SIMDE_TEST_ASSERTION_FAILURES_NON_FATAL

#include "test.h"

#define SIMDE_TEST_EXPECT_FAILURE(expr) (!(expr) || (__builtin_abort(), 0))
#define SIMDE_TEST_EXPECT_SUCCESS(expr) ((expr) || (__builtin_abort(), 0))

int main(void) {
  char buf[256];

  {
    simde_test_codegen_f32(sizeof(buf), buf, SIMDE_FLOAT32_C(3.141592654));
    printf("|%s|\n", buf);
    simde_test_codegen_f32(sizeof(buf), buf, SIMDE_MATH_INFINITYF);
    printf("|%s|\n", buf);
    simde_test_codegen_f32(sizeof(buf), buf, -SIMDE_MATH_INFINITYF);
    printf("|%s|\n", buf);
    simde_test_codegen_f32(sizeof(buf), buf, SIMDE_MATH_NAN);
    printf("|%s|\n", buf);
  }

  {
    fputc('\n', stdout);
    simde_test_codegen_f64(sizeof(buf), buf, SIMDE_FLOAT64_C(3.141592654));
    printf("|%s|\n", buf);
    simde_test_codegen_f64(sizeof(buf), buf, SIMDE_MATH_INFINITY);
    printf("|%s|\n", buf);
    simde_test_codegen_f64(sizeof(buf), buf, -SIMDE_MATH_INFINITY);
    printf("|%s|\n", buf);
    simde_test_codegen_f64(sizeof(buf), buf, SIMDE_MATH_NAN);
    printf("|%s|\n", buf);
  }

  {
    fputc('\n', stdout);
    simde_test_codegen_i8(sizeof(buf), buf, INT8_C(3));
    printf("|%s|\n", buf);
    simde_test_codegen_i8(sizeof(buf), buf, -INT8_C(3));
    printf("|%s|\n", buf);
    simde_test_codegen_i8(sizeof(buf), buf, INT8_MIN + 1);
    printf("|%s|\n", buf);
    simde_test_codegen_i8(sizeof(buf), buf, INT8_MAX - 1);
    printf("|%s|\n", buf);
    simde_test_codegen_i8(sizeof(buf), buf, INT8_MIN);
    printf("|%s|\n", buf);
    simde_test_codegen_i8(sizeof(buf), buf, INT8_MAX);
    printf("|%s|\n", buf);
  }

  {
    fputc('\n', stdout);
    simde_test_codegen_i16(sizeof(buf), buf, INT16_C(3));
    printf("|%s|\n", buf);
    simde_test_codegen_i16(sizeof(buf), buf, -INT16_C(3));
    printf("|%s|\n", buf);
    simde_test_codegen_i16(sizeof(buf), buf, INT16_MIN + 1);
    printf("|%s|\n", buf);
    simde_test_codegen_i16(sizeof(buf), buf, INT16_MAX - 1);
    printf("|%s|\n", buf);
    simde_test_codegen_i16(sizeof(buf), buf, INT16_MIN);
    printf("|%s|\n", buf);
    simde_test_codegen_i16(sizeof(buf), buf, INT16_MAX);
    printf("|%s|\n", buf);
  }

  {
    fputc('\n', stdout);
    simde_test_codegen_i32(sizeof(buf), buf, INT32_C(3));
    printf("|%s|\n", buf);
    simde_test_codegen_i32(sizeof(buf), buf, -INT32_C(3));
    printf("|%s|\n", buf);
    simde_test_codegen_i32(sizeof(buf), buf, INT32_MIN + 1);
    printf("|%s|\n", buf);
    simde_test_codegen_i32(sizeof(buf), buf, INT32_MAX - 1);
    printf("|%s|\n", buf);
    simde_test_codegen_i32(sizeof(buf), buf, INT32_MIN);
    printf("|%s|\n", buf);
    simde_test_codegen_i32(sizeof(buf), buf, INT32_MAX);
    printf("|%s|\n", buf);
  }

  {
    fputc('\n', stdout);
    simde_test_codegen_i64(sizeof(buf), buf, INT64_C(3));
    printf("|%s|\n", buf);
    simde_test_codegen_i64(sizeof(buf), buf, -INT64_C(3));
    printf("|%s|\n", buf);
    simde_test_codegen_i64(sizeof(buf), buf, INT64_MIN + 1);
    printf("|%s|\n", buf);
    simde_test_codegen_i64(sizeof(buf), buf, INT64_MAX - 1);
    printf("|%s|\n", buf);
    simde_test_codegen_i64(sizeof(buf), buf, INT64_MIN);
    printf("|%s|\n", buf);
    simde_test_codegen_i64(sizeof(buf), buf, INT64_MAX);
    printf("|%s|\n", buf);
  }

  {
    fputc('\n', stdout);
    simde_test_codegen_u8(sizeof(buf), buf, UINT8_C(3));
    printf("|%s|\n", buf);
    simde_test_codegen_u8(sizeof(buf), buf, UINT8_MAX - 1);
    printf("|%s|\n", buf);
    simde_test_codegen_u8(sizeof(buf), buf, UINT8_MAX);
    printf("|%s|\n", buf);
  }

  {
    fputc('\n', stdout);
    simde_test_codegen_u16(sizeof(buf), buf, UINT16_C(3));
    printf("|%s|\n", buf);
    simde_test_codegen_u16(sizeof(buf), buf, UINT16_MAX - 1);
    printf("|%s|\n", buf);
    simde_test_codegen_u16(sizeof(buf), buf, UINT16_MAX);
    printf("|%s|\n", buf);
  }

  {
    fputc('\n', stdout);
    simde_test_codegen_u32(sizeof(buf), buf, UINT32_C(3));
    printf("|%s|\n", buf);
    simde_test_codegen_u32(sizeof(buf), buf, UINT32_MAX - 1);
    printf("|%s|\n", buf);
    simde_test_codegen_u32(sizeof(buf), buf, UINT32_MAX);
    printf("|%s|\n", buf);
  }

  {
    fputc('\n', stdout);
    simde_test_codegen_u64(sizeof(buf), buf, UINT64_C(3));
    printf("|%s|\n", buf);
    simde_test_codegen_u64(sizeof(buf), buf, UINT64_MAX - 1);
    printf("|%s|\n", buf);
    simde_test_codegen_u64(sizeof(buf), buf, UINT64_MAX);
    printf("|%s|\n", buf);
  }

  {
    fputc('\n', stdout);
    simde_float32 vf32[4];
    simde_codegen_random_vf32(sizeof(vf32) / sizeof(vf32[0]), vf32, -SIMDE_FLOAT32_C(1000.0), SIMDE_FLOAT32_C(1000.0));
    simde_test_codegen_write_vf32(2, sizeof(vf32) / sizeof(vf32[0]), vf32, SIMDE_TEST_VEC_POS_FIRST);
    simde_codegen_random_vf32(sizeof(vf32) / sizeof(vf32[0]), vf32, -SIMDE_FLOAT32_C(1000.0), SIMDE_FLOAT32_C(1000.0));
    simde_test_codegen_write_vf32(2, sizeof(vf32) / sizeof(vf32[0]), vf32, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_codegen_random_vf32(sizeof(vf32) / sizeof(vf32[0]), vf32, -SIMDE_FLOAT32_C(1000.0), SIMDE_FLOAT32_C(1000.0));
    simde_test_codegen_write_vf32(2, sizeof(vf32) / sizeof(vf32[0]), vf32, SIMDE_TEST_VEC_POS_LAST);

    simde_float32 vf32x[4];
    simde_memcpy(vf32x, vf32, sizeof(vf32x));
    SIMDE_TEST_EXPECT_SUCCESS(simde_assert_equal_vf32(sizeof(vf32) / sizeof(vf32[0]), vf32, vf32x, 1));

    simde_memcpy(vf32x, vf32, sizeof(vf32x));
    vf32x[simde_codegen_rand() % HEDLEY_STATIC_CAST(int, sizeof(vf32) / sizeof(vf32[0]))] += SIMDE_FLOAT32_C(0.05);
    SIMDE_TEST_EXPECT_SUCCESS(simde_assert_equal_vf32(sizeof(vf32) / sizeof(vf32[0]), vf32, vf32x, 1));

    simde_memcpy(vf32x, vf32, sizeof(vf32x));
    vf32x[simde_codegen_rand() % HEDLEY_STATIC_CAST(int, sizeof(vf32) / sizeof(vf32[0]))] += SIMDE_FLOAT32_C(0.15);
    SIMDE_TEST_EXPECT_FAILURE(simde_assert_equal_vf32(sizeof(vf32) / sizeof(vf32[0]), vf32, vf32x, 1));

    simde_memcpy(vf32x, vf32, sizeof(vf32x));
    vf32x[simde_codegen_rand() % HEDLEY_STATIC_CAST(int, sizeof(vf32) / sizeof(vf32[0]))] = SIMDE_MATH_INFINITY;
    SIMDE_TEST_EXPECT_FAILURE(simde_assert_equal_vf32(sizeof(vf32) / sizeof(vf32[0]), vf32, vf32x, 1));

    simde_memcpy(vf32x, vf32, sizeof(vf32x));
    vf32x[simde_codegen_rand() % HEDLEY_STATIC_CAST(int, sizeof(vf32) / sizeof(vf32[0]))] = -SIMDE_MATH_INFINITY;
    SIMDE_TEST_EXPECT_FAILURE(simde_assert_equal_vf32(sizeof(vf32) / sizeof(vf32[0]), vf32, vf32x, 1));

    simde_memcpy(vf32, vf32x, sizeof(vf32x));
    vf32[simde_codegen_rand() % HEDLEY_STATIC_CAST(int, sizeof(vf32) / sizeof(vf32[0]))] = -SIMDE_MATH_INFINITY;
    simde_memcpy(vf32x, vf32, sizeof(vf32x));
    SIMDE_TEST_EXPECT_SUCCESS(simde_assert_equal_vf32(sizeof(vf32) / sizeof(vf32[0]), vf32, vf32x, 1));
    simde_codegen_random_vf32(sizeof(vf32) / sizeof(vf32[0]), vf32, -SIMDE_FLOAT32_C(1000.0), SIMDE_FLOAT32_C(1000.0));

    simde_memcpy(vf32x, vf32, sizeof(vf32x));
    vf32[simde_codegen_rand() % HEDLEY_STATIC_CAST(int, sizeof(vf32) / sizeof(vf32[0]))] = SIMDE_MATH_NAN;
    SIMDE_TEST_EXPECT_FAILURE(simde_assert_equal_vf32(sizeof(vf32) / sizeof(vf32[0]), vf32, vf32x, 1));

    simde_memcpy(vf32x, vf32, sizeof(vf32x));
    vf32x[simde_codegen_rand() % HEDLEY_STATIC_CAST(int, sizeof(vf32) / sizeof(vf32[0]))] = SIMDE_MATH_NAN;
    simde_memcpy(vf32, vf32x, sizeof(vf32x));
    SIMDE_TEST_EXPECT_SUCCESS(simde_assert_equal_vf32(sizeof(vf32) / sizeof(vf32[0]), vf32, vf32x, 1));
  }

  {
    fputc('\n', stdout);
    simde_float64 vf64[2];
    simde_codegen_random_vf64(sizeof(vf64) / sizeof(vf64[0]), vf64, -SIMDE_FLOAT64_C(1000.0), SIMDE_FLOAT64_C(1000.0));
    simde_test_codegen_write_vf64(2, sizeof(vf64) / sizeof(vf64[0]), vf64, SIMDE_TEST_VEC_POS_FIRST);
    simde_codegen_random_vf64(sizeof(vf64) / sizeof(vf64[0]), vf64, -SIMDE_FLOAT64_C(1000.0), SIMDE_FLOAT64_C(1000.0));
    simde_test_codegen_write_vf64(2, sizeof(vf64) / sizeof(vf64[0]), vf64, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_codegen_random_vf64(sizeof(vf64) / sizeof(vf64[0]), vf64, -SIMDE_FLOAT64_C(1000.0), SIMDE_FLOAT64_C(1000.0));
    simde_test_codegen_write_vf64(2, sizeof(vf64) / sizeof(vf64[0]), vf64, SIMDE_TEST_VEC_POS_LAST);

    simde_float64 vf64x[2];
    simde_memcpy(vf64x, vf64, sizeof(vf64x));
    SIMDE_TEST_EXPECT_SUCCESS(simde_assert_equal_vf64(sizeof(vf64) / sizeof(vf64[0]), vf64, vf64x, 1));

    simde_memcpy(vf64x, vf64, sizeof(vf64x));
    vf64x[simde_codegen_rand() % HEDLEY_STATIC_CAST(int, sizeof(vf64) / sizeof(vf64[0]))] += SIMDE_FLOAT64_C(0.05);
    SIMDE_TEST_EXPECT_SUCCESS(simde_assert_equal_vf64(sizeof(vf64) / sizeof(vf64[0]), vf64, vf64x, 1));

    simde_memcpy(vf64x, vf64, sizeof(vf64x));
    vf64x[simde_codegen_rand() % HEDLEY_STATIC_CAST(int, sizeof(vf64) / sizeof(vf64[0]))] += SIMDE_FLOAT64_C(0.15);
    SIMDE_TEST_EXPECT_FAILURE(simde_assert_equal_vf64(sizeof(vf64) / sizeof(vf64[0]), vf64, vf64x, 1));

    simde_memcpy(vf64x, vf64, sizeof(vf64x));
    vf64x[simde_codegen_rand() % HEDLEY_STATIC_CAST(int, sizeof(vf64) / sizeof(vf64[0]))] = SIMDE_MATH_INFINITY;
    SIMDE_TEST_EXPECT_FAILURE(simde_assert_equal_vf64(sizeof(vf64) / sizeof(vf64[0]), vf64, vf64x, 1));

    simde_memcpy(vf64x, vf64, sizeof(vf64x));
    vf64x[simde_codegen_rand() % HEDLEY_STATIC_CAST(int, sizeof(vf64) / sizeof(vf64[0]))] = -SIMDE_MATH_INFINITY;
    SIMDE_TEST_EXPECT_FAILURE(simde_assert_equal_vf64(sizeof(vf64) / sizeof(vf64[0]), vf64, vf64x, 1));

    simde_memcpy(vf64, vf64x, sizeof(vf64x));
    vf64[simde_codegen_rand() % HEDLEY_STATIC_CAST(int, sizeof(vf64) / sizeof(vf64[0]))] = -SIMDE_MATH_INFINITY;
    simde_memcpy(vf64x, vf64, sizeof(vf64x));
    SIMDE_TEST_EXPECT_SUCCESS(simde_assert_equal_vf64(sizeof(vf64) / sizeof(vf64[0]), vf64, vf64x, 1));
    simde_codegen_random_vf64(sizeof(vf64) / sizeof(vf64[0]), vf64, -SIMDE_FLOAT64_C(1000.0), SIMDE_FLOAT64_C(1000.0));

    simde_memcpy(vf64x, vf64, sizeof(vf64x));
    vf64[simde_codegen_rand() % HEDLEY_STATIC_CAST(int, sizeof(vf64) / sizeof(vf64[0]))] = SIMDE_MATH_NAN;
    SIMDE_TEST_EXPECT_FAILURE(simde_assert_equal_vf64(sizeof(vf64) / sizeof(vf64[0]), vf64, vf64x, 1));

    simde_memcpy(vf64x, vf64, sizeof(vf64x));
    vf64x[simde_codegen_rand() % HEDLEY_STATIC_CAST(int, sizeof(vf64) / sizeof(vf64[0]))] = SIMDE_MATH_NAN;
    simde_memcpy(vf64, vf64x, sizeof(vf64x));
    SIMDE_TEST_EXPECT_SUCCESS(simde_assert_equal_vf64(sizeof(vf64) / sizeof(vf64[0]), vf64, vf64x, 1));
  }

  {
    fputc('\n', stdout);
    int8_t vi8[16];
    simde_codegen_random_memory(sizeof(vi8) / sizeof(vi8[0]), HEDLEY_REINTERPRET_CAST(uint8_t*, vi8));
    simde_test_codegen_write_vi8(2, sizeof(vi8) / sizeof(vi8[0]), vi8, SIMDE_TEST_VEC_POS_FIRST);
    simde_codegen_random_memory(sizeof(vi8) / sizeof(vi8[0]), HEDLEY_REINTERPRET_CAST(uint8_t*, vi8));
    simde_test_codegen_write_vi8(2, sizeof(vi8) / sizeof(vi8[0]), vi8, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_codegen_random_memory(sizeof(vi8) / sizeof(vi8[0]), HEDLEY_REINTERPRET_CAST(uint8_t*, vi8));
    simde_test_codegen_write_vi8(2, sizeof(vi8) / sizeof(vi8[0]), vi8, SIMDE_TEST_VEC_POS_LAST);

    int8_t vi8x[16];
    simde_memcpy(vi8x, vi8, sizeof(vi8x));
    SIMDE_TEST_EXPECT_SUCCESS(simde_assert_equal_vi8(sizeof(vi8) / sizeof(vi8[0]), vi8, vi8x));

    vi8x[simde_codegen_rand() % HEDLEY_STATIC_CAST(int, sizeof(vi8) / sizeof(vi8[0]))]++;
    SIMDE_TEST_EXPECT_FAILURE(simde_assert_equal_vi8(sizeof(vi8) / sizeof(vi8[0]), vi8, vi8x));
  }

  {
    fputc('\n', stdout);
    int16_t vi16[8];
    simde_codegen_random_memory(sizeof(vi16), HEDLEY_REINTERPRET_CAST(uint8_t*, vi16));
    simde_test_codegen_write_vi16(2, sizeof(vi16) / sizeof(vi16[0]), vi16, SIMDE_TEST_VEC_POS_FIRST);
    simde_codegen_random_memory(sizeof(vi16), HEDLEY_REINTERPRET_CAST(uint8_t*, vi16));
    simde_test_codegen_write_vi16(2, sizeof(vi16), vi16, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_codegen_random_memory(sizeof(vi16), HEDLEY_REINTERPRET_CAST(uint8_t*, vi16));
    simde_test_codegen_write_vi16(2, sizeof(vi16) / sizeof(vi16[0]), vi16, SIMDE_TEST_VEC_POS_LAST);

    int16_t vi16x[8];
    simde_memcpy(vi16x, vi16, sizeof(vi16x));
    SIMDE_TEST_EXPECT_SUCCESS(simde_assert_equal_vi16(sizeof(vi16) / sizeof(vi16[0]), vi16, vi16x));

    vi16x[simde_codegen_rand() % HEDLEY_STATIC_CAST(int, sizeof(vi16) / sizeof(vi16[0]))]++;
    SIMDE_TEST_EXPECT_FAILURE(simde_assert_equal_vi16(sizeof(vi16) / sizeof(vi16[0]), vi16, vi16x));
  }

  {
    fputc('\n', stdout);
    int32_t vi32[4];
    simde_codegen_random_memory(sizeof(vi32), HEDLEY_REINTERPRET_CAST(uint8_t*, vi32));
    simde_test_codegen_write_vi32(2, sizeof(vi32), vi32, SIMDE_TEST_VEC_POS_FIRST);
    simde_codegen_random_memory(sizeof(vi32), HEDLEY_REINTERPRET_CAST(uint8_t*, vi32));
    simde_test_codegen_write_vi32(2, sizeof(vi32), vi32, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_codegen_random_memory(sizeof(vi32), HEDLEY_REINTERPRET_CAST(uint8_t*, vi32));
    simde_test_codegen_write_vi32(2, sizeof(vi32), vi32, SIMDE_TEST_VEC_POS_LAST);

    int32_t vi32x[4];
    simde_memcpy(vi32x, vi32, sizeof(vi32x));
    SIMDE_TEST_EXPECT_SUCCESS(simde_assert_equal_vi32(sizeof(vi32) / sizeof(vi32[0]), vi32, vi32x));

    vi32x[simde_codegen_rand() % HEDLEY_STATIC_CAST(int, sizeof(vi32) / sizeof(vi32[0]))]++;
    SIMDE_TEST_EXPECT_FAILURE(simde_assert_equal_vi32(sizeof(vi32) / sizeof(vi32[0]), vi32, vi32x));
  }

  {
    fputc('\n', stdout);
    int64_t vi64[2];
    simde_codegen_random_memory(sizeof(vi64), HEDLEY_REINTERPRET_CAST(uint8_t*, vi64));
    simde_test_codegen_write_vi64(2, sizeof(vi64), vi64, SIMDE_TEST_VEC_POS_FIRST);
    simde_codegen_random_memory(sizeof(vi64), HEDLEY_REINTERPRET_CAST(uint8_t*, vi64));
    simde_test_codegen_write_vi64(2, sizeof(vi64), vi64, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_codegen_random_memory(sizeof(vi64), HEDLEY_REINTERPRET_CAST(uint8_t*, vi64));
    simde_test_codegen_write_vi64(2, sizeof(vi64), vi64, SIMDE_TEST_VEC_POS_LAST);

    int64_t vi64x[2];
    simde_memcpy(vi64x, vi64, sizeof(vi64x));
    SIMDE_TEST_EXPECT_SUCCESS(simde_assert_equal_vi64(sizeof(vi64) / sizeof(vi64[0]), vi64, vi64x));

    vi64x[simde_codegen_rand() % HEDLEY_STATIC_CAST(int, sizeof(vi64) / sizeof(vi64[0]))]++;
    SIMDE_TEST_EXPECT_FAILURE(simde_assert_equal_vi64(sizeof(vi64) / sizeof(vi64[0]), vi64, vi64x));
  }

  {
    fputc('\n', stdout);
    uint8_t vu8[16];
    simde_codegen_random_memory(sizeof(vu8) / sizeof(vu8[0]), HEDLEY_REINTERPRET_CAST(uint8_t*, vu8));
    simde_test_codegen_write_vu8(2, sizeof(vu8) / sizeof(vu8[0]), vu8, SIMDE_TEST_VEC_POS_FIRST);
    simde_codegen_random_memory(sizeof(vu8) / sizeof(vu8[0]), HEDLEY_REINTERPRET_CAST(uint8_t*, vu8));
    simde_test_codegen_write_vu8(2, sizeof(vu8) / sizeof(vu8[0]), vu8, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_codegen_random_memory(sizeof(vu8) / sizeof(vu8[0]), HEDLEY_REINTERPRET_CAST(uint8_t*, vu8));
    simde_test_codegen_write_vu8(2, sizeof(vu8) / sizeof(vu8[0]), vu8, SIMDE_TEST_VEC_POS_LAST);

    uint8_t vu8x[16];
    simde_memcpy(vu8x, vu8, sizeof(vu8x));
    SIMDE_TEST_EXPECT_SUCCESS(simde_assert_equal_vu8(sizeof(vu8) / sizeof(vu8[0]), vu8, vu8x));

    vu8x[simde_codegen_rand() % HEDLEY_STATIC_CAST(int, sizeof(vu8) / sizeof(vu8[0]))]++;
    SIMDE_TEST_EXPECT_FAILURE(simde_assert_equal_vu8(sizeof(vu8) / sizeof(vu8[0]), vu8, vu8x));
  }

  {
    fputc('\n', stdout);
    uint16_t vu16[8];
    simde_codegen_random_memory(sizeof(vu16) / sizeof(vu16[0]), HEDLEY_REINTERPRET_CAST(uint8_t*, vu16));
    simde_test_codegen_write_vu16(2, sizeof(vu16) / sizeof(vu16[0]), vu16, SIMDE_TEST_VEC_POS_FIRST);
    simde_codegen_random_memory(sizeof(vu16) / sizeof(vu16[0]), HEDLEY_REINTERPRET_CAST(uint8_t*, vu16));
    simde_test_codegen_write_vu16(2, sizeof(vu16) / sizeof(vu16[0]), vu16, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_codegen_random_memory(sizeof(vu16) / sizeof(vu16[0]), HEDLEY_REINTERPRET_CAST(uint8_t*, vu16));
    simde_test_codegen_write_vu16(2, sizeof(vu16) / sizeof(vu16[0]), vu16, SIMDE_TEST_VEC_POS_LAST);

    uint16_t vu16x[8];
    simde_memcpy(vu16x, vu16, sizeof(vu16x));
    SIMDE_TEST_EXPECT_SUCCESS(simde_assert_equal_vu16(sizeof(vu16) / sizeof(vu16[0]), vu16, vu16x));

    vu16x[simde_codegen_rand() % HEDLEY_STATIC_CAST(int, sizeof(vu16) / sizeof(vu16[0]))]++;
    SIMDE_TEST_EXPECT_FAILURE(simde_assert_equal_vu16(sizeof(vu16) / sizeof(vu16[0]), vu16, vu16x));
  }

  {
    fputc('\n', stdout);
    uint32_t vu32[4];
    simde_codegen_random_memory(sizeof(vu32) / sizeof(vu32[0]), HEDLEY_REINTERPRET_CAST(uint8_t*, vu32));
    simde_test_codegen_write_vu32(2, sizeof(vu32) / sizeof(vu32[0]), vu32, SIMDE_TEST_VEC_POS_FIRST);
    simde_codegen_random_memory(sizeof(vu32) / sizeof(vu32[0]), HEDLEY_REINTERPRET_CAST(uint8_t*, vu32));
    simde_test_codegen_write_vu32(2, sizeof(vu32) / sizeof(vu32[0]), vu32, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_codegen_random_memory(sizeof(vu32) / sizeof(vu32[0]), HEDLEY_REINTERPRET_CAST(uint8_t*, vu32));
    simde_test_codegen_write_vu32(2, sizeof(vu32) / sizeof(vu32[0]), vu32, SIMDE_TEST_VEC_POS_LAST);

    uint32_t vu32x[4];
    simde_memcpy(vu32x, vu32, sizeof(vu32x));
    SIMDE_TEST_EXPECT_SUCCESS(simde_assert_equal_vu32(sizeof(vu32) / sizeof(vu32[0]), vu32, vu32x));

    vu32x[simde_codegen_rand() % HEDLEY_STATIC_CAST(int, sizeof(vu32) / sizeof(vu32[0]))]++;
    SIMDE_TEST_EXPECT_FAILURE(simde_assert_equal_vu32(sizeof(vu32) / sizeof(vu32[0]), vu32, vu32x));
  }

  {
    fputc('\n', stdout);
    uint64_t vu64[2];
    simde_codegen_random_memory(sizeof(vu64) / sizeof(vu64[0]), HEDLEY_REINTERPRET_CAST(uint8_t*, vu64));
    simde_test_codegen_write_vu64(2, sizeof(vu64) / sizeof(vu64[0]), vu64, SIMDE_TEST_VEC_POS_FIRST);
    simde_codegen_random_memory(sizeof(vu64) / sizeof(vu64[0]), HEDLEY_REINTERPRET_CAST(uint8_t*, vu64));
    simde_test_codegen_write_vu64(2, sizeof(vu64) / sizeof(vu64[0]), vu64, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_codegen_random_memory(sizeof(vu64) / sizeof(vu64[0]), HEDLEY_REINTERPRET_CAST(uint8_t*, vu64));
    simde_test_codegen_write_vu64(2, sizeof(vu64) / sizeof(vu64[0]), vu64, SIMDE_TEST_VEC_POS_LAST);

    uint64_t vu64x[2];
    simde_memcpy(vu64x, vu64, sizeof(vu64x));
    SIMDE_TEST_EXPECT_SUCCESS(simde_assert_equal_vu64(sizeof(vu64) / sizeof(vu64[0]), vu64, vu64x));

    vu64x[simde_codegen_rand() % HEDLEY_STATIC_CAST(int, sizeof(vu64) / sizeof(vu64[0]))]++;
    SIMDE_TEST_EXPECT_FAILURE(simde_assert_equal_vu64(sizeof(vu64) / sizeof(vu64[0]), vu64, vu64x));
  }

  return 0;
}
