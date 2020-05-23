

#define SIMDE_TEST_ASSERTION_FAILURES_NON_FATAL

#include "test-neon.h"

#define SIMDE_TEST_EXPECT_FAILURE(expr) (!(expr) || (__builtin_abort(), 0))
#define SIMDE_TEST_EXPECT_SUCCESS(expr) ((expr) || (__builtin_abort(), 0))

int main(void) {
  {
    fputc('\n', stdout);
    simde_test_arm_neon_write_f32x4(2, simde_test_arm_neon_random_f32x4(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0)), SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f32x4(2, simde_test_arm_neon_random_f32x4(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0)), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f32x4(2, simde_test_arm_neon_random_f32x4(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0)), SIMDE_TEST_VEC_POS_LAST);

    simde_float32x4_t
      a = simde_test_arm_neon_random_f32x4(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0)),
      b = simde_test_arm_neon_random_f32x4(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
    SIMDE_TEST_EXPECT_FAILURE(simde_test_arm_neon_assert_equal_f32x4(a, b, 1));

    b = a;
    SIMDE_TEST_EXPECT_SUCCESS(simde_test_arm_neon_assert_equal_f32x4(a, b, 1));
  }

  {
    fputc('\n', stdout);
    simde_test_arm_neon_write_f64x2(2, simde_test_arm_neon_random_f64x2(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0)), SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f64x2(2, simde_test_arm_neon_random_f64x2(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0)), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f64x2(2, simde_test_arm_neon_random_f64x2(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0)), SIMDE_TEST_VEC_POS_LAST);

    simde_float64x2_t
      a = simde_test_arm_neon_random_f64x2(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0)),
      b = simde_test_arm_neon_random_f64x2(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    SIMDE_TEST_EXPECT_FAILURE(simde_test_arm_neon_assert_equal_f64x2(a, b, 1));

    b = a;
    SIMDE_TEST_EXPECT_SUCCESS(simde_test_arm_neon_assert_equal_f64x2(a, b, 1));
  }

  {
    fputc('\n', stdout);
    simde_test_arm_neon_write_i8x8(2, simde_test_arm_neon_random_i8x8(), SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i8x8(2, simde_test_arm_neon_random_i8x8(), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i8x8(2, simde_test_arm_neon_random_i8x8(), SIMDE_TEST_VEC_POS_LAST);

    simde_int8x8_t
      a = simde_test_arm_neon_random_i8x8(),
      b = simde_test_arm_neon_random_i8x8();
    SIMDE_TEST_EXPECT_FAILURE(simde_test_arm_neon_assert_equal_i8x8(a, b));

    b = a;
    SIMDE_TEST_EXPECT_SUCCESS(simde_test_arm_neon_assert_equal_i8x8(a, b));
  }

  {
    fputc('\n', stdout);
    simde_test_arm_neon_write_i16x4(2, simde_test_arm_neon_random_i16x4(), SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x4(2, simde_test_arm_neon_random_i16x4(), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x4(2, simde_test_arm_neon_random_i16x4(), SIMDE_TEST_VEC_POS_LAST);

    simde_int16x4_t
      a = simde_test_arm_neon_random_i16x4(),
      b = simde_test_arm_neon_random_i16x4();
    SIMDE_TEST_EXPECT_FAILURE(simde_test_arm_neon_assert_equal_i16x4(a, b));

    b = a;
    SIMDE_TEST_EXPECT_SUCCESS(simde_test_arm_neon_assert_equal_i16x4(a, b));
  }

  {
    fputc('\n', stdout);
    simde_test_arm_neon_write_i32x2(2, simde_test_arm_neon_random_i32x2(), SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x2(2, simde_test_arm_neon_random_i32x2(), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x2(2, simde_test_arm_neon_random_i32x2(), SIMDE_TEST_VEC_POS_LAST);

    simde_int32x2_t
      a = simde_test_arm_neon_random_i32x2(),
      b = simde_test_arm_neon_random_i32x2();
    SIMDE_TEST_EXPECT_FAILURE(simde_test_arm_neon_assert_equal_i32x2(a, b));

    b = a;
    SIMDE_TEST_EXPECT_SUCCESS(simde_test_arm_neon_assert_equal_i32x2(a, b));
  }

  {
    fputc('\n', stdout);
    simde_test_arm_neon_write_i64x1(2, simde_test_arm_neon_random_i64x1(), SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i64x1(2, simde_test_arm_neon_random_i64x1(), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i64x1(2, simde_test_arm_neon_random_i64x1(), SIMDE_TEST_VEC_POS_LAST);

    simde_int64x1_t
      a = simde_test_arm_neon_random_i64x1(),
      b = simde_test_arm_neon_random_i64x1();
    SIMDE_TEST_EXPECT_FAILURE(simde_test_arm_neon_assert_equal_i64x1(a, b));

    b = a;
    SIMDE_TEST_EXPECT_SUCCESS(simde_test_arm_neon_assert_equal_i64x1(a, b));
  }

  {
    fputc('\n', stdout);
    simde_test_arm_neon_write_u8x8(2, simde_test_arm_neon_random_u8x8(), SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u8x8(2, simde_test_arm_neon_random_u8x8(), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x8(2, simde_test_arm_neon_random_u8x8(), SIMDE_TEST_VEC_POS_LAST);

    simde_int8x8_t
      a = simde_test_arm_neon_random_u8x8(),
      b = simde_test_arm_neon_random_u8x8();
    SIMDE_TEST_EXPECT_FAILURE(simde_test_arm_neon_assert_equal_u8x8(a, b));

    b = a;
    SIMDE_TEST_EXPECT_SUCCESS(simde_test_arm_neon_assert_equal_u8x8(a, b));
  }

  {
    fputc('\n', stdout);
    simde_test_arm_neon_write_u16x4(2, simde_test_arm_neon_random_u16x4(), SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u16x4(2, simde_test_arm_neon_random_u16x4(), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x4(2, simde_test_arm_neon_random_u16x4(), SIMDE_TEST_VEC_POS_LAST);

    simde_int16x4_t
      a = simde_test_arm_neon_random_u16x4(),
      b = simde_test_arm_neon_random_u16x4();
    SIMDE_TEST_EXPECT_FAILURE(simde_test_arm_neon_assert_equal_u16x4(a, b));

    b = a;
    SIMDE_TEST_EXPECT_SUCCESS(simde_test_arm_neon_assert_equal_u16x4(a, b));
  }

  {
    fputc('\n', stdout);
    simde_test_arm_neon_write_u32x2(2, simde_test_arm_neon_random_u32x2(), SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x2(2, simde_test_arm_neon_random_u32x2(), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x2(2, simde_test_arm_neon_random_u32x2(), SIMDE_TEST_VEC_POS_LAST);

    simde_int32x2_t
      a = simde_test_arm_neon_random_u32x2(),
      b = simde_test_arm_neon_random_u32x2();
    SIMDE_TEST_EXPECT_FAILURE(simde_test_arm_neon_assert_equal_u32x2(a, b));

    b = a;
    SIMDE_TEST_EXPECT_SUCCESS(simde_test_arm_neon_assert_equal_u32x2(a, b));
  }

  {
    fputc('\n', stdout);
    simde_test_arm_neon_write_u64x1(2, simde_test_arm_neon_random_u64x1(), SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u64x1(2, simde_test_arm_neon_random_u64x1(), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x1(2, simde_test_arm_neon_random_u64x1(), SIMDE_TEST_VEC_POS_LAST);

    simde_int64x1_t
      a = simde_test_arm_neon_random_u64x1(),
      b = simde_test_arm_neon_random_u64x1();
    SIMDE_TEST_EXPECT_FAILURE(simde_test_arm_neon_assert_equal_u64x1(a, b));

    b = a;
    SIMDE_TEST_EXPECT_SUCCESS(simde_test_arm_neon_assert_equal_u64x1(a, b));
  }

  {
    fputc('\n', stdout);
    simde_test_arm_neon_write_i8x16(2, simde_test_arm_neon_random_i8x16(), SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i8x16(2, simde_test_arm_neon_random_i8x16(), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i8x16(2, simde_test_arm_neon_random_i8x16(), SIMDE_TEST_VEC_POS_LAST);

    simde_int8x16_t
      a = simde_test_arm_neon_random_i8x16(),
      b = simde_test_arm_neon_random_i8x16();
    SIMDE_TEST_EXPECT_FAILURE(simde_test_arm_neon_assert_equal_i8x16(a, b));

    b = a;
    SIMDE_TEST_EXPECT_SUCCESS(simde_test_arm_neon_assert_equal_i8x16(a, b));
  }

  {
    fputc('\n', stdout);
    simde_test_arm_neon_write_i16x8(2, simde_test_arm_neon_random_i16x8(), SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x8(2, simde_test_arm_neon_random_i16x8(), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x8(2, simde_test_arm_neon_random_i16x8(), SIMDE_TEST_VEC_POS_LAST);

    simde_int16x8_t
      a = simde_test_arm_neon_random_i16x8(),
      b = simde_test_arm_neon_random_i16x8();
    SIMDE_TEST_EXPECT_FAILURE(simde_test_arm_neon_assert_equal_i16x8(a, b));

    b = a;
    SIMDE_TEST_EXPECT_SUCCESS(simde_test_arm_neon_assert_equal_i16x8(a, b));
  }

  {
    fputc('\n', stdout);
    simde_test_arm_neon_write_i32x4(2, simde_test_arm_neon_random_i32x4(), SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x4(2, simde_test_arm_neon_random_i32x4(), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x4(2, simde_test_arm_neon_random_i32x4(), SIMDE_TEST_VEC_POS_LAST);

    simde_int32x4_t
      a = simde_test_arm_neon_random_i32x4(),
      b = simde_test_arm_neon_random_i32x4();
    SIMDE_TEST_EXPECT_FAILURE(simde_test_arm_neon_assert_equal_i32x4(a, b));

    b = a;
    SIMDE_TEST_EXPECT_SUCCESS(simde_test_arm_neon_assert_equal_i32x4(a, b));
  }

  {
    fputc('\n', stdout);
    simde_test_arm_neon_write_i64x2(2, simde_test_arm_neon_random_i64x2(), SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i64x2(2, simde_test_arm_neon_random_i64x2(), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i64x2(2, simde_test_arm_neon_random_i64x2(), SIMDE_TEST_VEC_POS_LAST);

    simde_int64x2_t
      a = simde_test_arm_neon_random_i64x2(),
      b = simde_test_arm_neon_random_i64x2();
    SIMDE_TEST_EXPECT_FAILURE(simde_test_arm_neon_assert_equal_i64x2(a, b));

    b = a;
    SIMDE_TEST_EXPECT_SUCCESS(simde_test_arm_neon_assert_equal_i64x2(a, b));
  }

  {
    fputc('\n', stdout);
    simde_test_arm_neon_write_u8x16(2, simde_test_arm_neon_random_u8x16(), SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u8x16(2, simde_test_arm_neon_random_u8x16(), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x16(2, simde_test_arm_neon_random_u8x16(), SIMDE_TEST_VEC_POS_LAST);

    simde_uint8x16_t
      a = simde_test_arm_neon_random_u8x16(),
      b = simde_test_arm_neon_random_u8x16();
    SIMDE_TEST_EXPECT_FAILURE(simde_test_arm_neon_assert_equal_u8x16(a, b));

    b = a;
    SIMDE_TEST_EXPECT_SUCCESS(simde_test_arm_neon_assert_equal_u8x16(a, b));
  }

  {
    fputc('\n', stdout);
    simde_test_arm_neon_write_u16x8(2, simde_test_arm_neon_random_u16x8(), SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u16x8(2, simde_test_arm_neon_random_u16x8(), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x8(2, simde_test_arm_neon_random_u16x8(), SIMDE_TEST_VEC_POS_LAST);

    simde_uint16x8_t
      a = simde_test_arm_neon_random_u16x8(),
      b = simde_test_arm_neon_random_u16x8();
    SIMDE_TEST_EXPECT_FAILURE(simde_test_arm_neon_assert_equal_u16x8(a, b));

    b = a;
    SIMDE_TEST_EXPECT_SUCCESS(simde_test_arm_neon_assert_equal_u16x8(a, b));
  }

  {
    fputc('\n', stdout);
    simde_test_arm_neon_write_u32x4(2, simde_test_arm_neon_random_u32x4(), SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x4(2, simde_test_arm_neon_random_u32x4(), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, simde_test_arm_neon_random_u32x4(), SIMDE_TEST_VEC_POS_LAST);

    simde_uint32x4_t
      a = simde_test_arm_neon_random_u32x4(),
      b = simde_test_arm_neon_random_u32x4();
    SIMDE_TEST_EXPECT_FAILURE(simde_test_arm_neon_assert_equal_u32x4(a, b));

    b = a;
    SIMDE_TEST_EXPECT_SUCCESS(simde_test_arm_neon_assert_equal_u32x4(a, b));
  }

  {
    fputc('\n', stdout);
    simde_test_arm_neon_write_u64x2(2, simde_test_arm_neon_random_u64x2(), SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u64x2(2, simde_test_arm_neon_random_u64x2(), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x2(2, simde_test_arm_neon_random_u64x2(), SIMDE_TEST_VEC_POS_LAST);

    simde_uint64x2_t
      a = simde_test_arm_neon_random_u64x2(),
      b = simde_test_arm_neon_random_u64x2();
    SIMDE_TEST_EXPECT_FAILURE(simde_test_arm_neon_assert_equal_u64x2(a, b));

    b = a;
    SIMDE_TEST_EXPECT_SUCCESS(simde_test_arm_neon_assert_equal_u64x2(a, b));
  }

  return 0;
}
