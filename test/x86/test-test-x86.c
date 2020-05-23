

#define SIMDE_TEST_ASSERTION_FAILURES_NON_FATAL

#include "test-x86-avx512.h"

#define SIMDE_TEST_EXPECT_FAILURE(expr) (!(expr) || (__builtin_abort(), 0))
#define SIMDE_TEST_EXPECT_SUCCESS(expr) ((expr) || (__builtin_abort(), 0))

static void
test_64(void) {
  {
    fputc('\n', stdout);

    simde_test_x86_write_f32x2(2, simde_test_x86_random_f32x2(-1000.0f, 1000.0f), SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f32x2(2, simde_test_x86_random_f32x2(-1000.0f, 1000.0f), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x2(2, simde_test_x86_random_f32x2(-1000.0f, 1000.0f), SIMDE_TEST_VEC_POS_LAST);

    simde__m64
      a = simde_test_x86_random_f32x2(-1000.0f, 1000.0f),
      b = simde_test_x86_random_f32x2(-1000.0f, 1000.0f);
    SIMDE_TEST_EXPECT_FAILURE(simde_test_x86_assert_equal_f32x2(a, b, 1));

    b = a;
    SIMDE_TEST_EXPECT_SUCCESS(simde_test_x86_assert_equal_f32x2(a, b, 1));
  }

  {
    fputc('\n', stdout);

    simde_test_x86_write_f64x1(2, simde_test_x86_random_f64x1(-1000.0, 1000.0), SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f64x1(2, simde_test_x86_random_f64x1(-1000.0, 1000.0), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x1(2, simde_test_x86_random_f64x1(-1000.0, 1000.0), SIMDE_TEST_VEC_POS_LAST);

    simde__m64
      a = simde_test_x86_random_f64x1(-1000.0, 1000.0),
      b = simde_test_x86_random_f64x1(-1000.0, 1000.0);
    SIMDE_TEST_EXPECT_FAILURE(simde_test_x86_assert_equal_f64x1(a, b, 1));

    b = a;
    SIMDE_TEST_EXPECT_SUCCESS(simde_test_x86_assert_equal_f64x1(a, b, 1));
  }

  {
    fputc('\n', stdout);

    simde_test_x86_write_i8x8(2, simde_test_x86_random_i8x8(), SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i8x8(2, simde_test_x86_random_i8x8(), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i8x8(2, simde_test_x86_random_i8x8(), SIMDE_TEST_VEC_POS_LAST);

    simde__m64
      a = simde_test_x86_random_i8x8(),
      b = simde_test_x86_random_i8x8();
    SIMDE_TEST_EXPECT_FAILURE(simde_test_x86_assert_equal_i8x8(a, b));

    b = a;
    SIMDE_TEST_EXPECT_SUCCESS(simde_test_x86_assert_equal_i8x8(a, b));
  }

  {
    fputc('\n', stdout);

    simde_test_x86_write_i16x4(2, simde_test_x86_random_i16x4(), SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i16x4(2, simde_test_x86_random_i16x4(), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x4(2, simde_test_x86_random_i16x4(), SIMDE_TEST_VEC_POS_LAST);

    simde__m64
      a = simde_test_x86_random_i16x4(),
      b = simde_test_x86_random_i16x4();
    SIMDE_TEST_EXPECT_FAILURE(simde_test_x86_assert_equal_i16x4(a, b));

    b = a;
    SIMDE_TEST_EXPECT_SUCCESS(simde_test_x86_assert_equal_i16x4(a, b));
  }

  {
    fputc('\n', stdout);

    simde_test_x86_write_i32x2(2, simde_test_x86_random_i32x2(), SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x2(2, simde_test_x86_random_i32x2(), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x2(2, simde_test_x86_random_i32x2(), SIMDE_TEST_VEC_POS_LAST);

    simde__m64
      a = simde_test_x86_random_i32x2(),
      b = simde_test_x86_random_i32x2();
    SIMDE_TEST_EXPECT_FAILURE(simde_test_x86_assert_equal_i32x2(a, b));

    b = a;
    SIMDE_TEST_EXPECT_SUCCESS(simde_test_x86_assert_equal_i32x2(a, b));
  }

  {
    fputc('\n', stdout);

    simde_test_x86_write_i64x1(2, simde_test_x86_random_i64x1(), SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i64x1(2, simde_test_x86_random_i64x1(), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x1(2, simde_test_x86_random_i64x1(), SIMDE_TEST_VEC_POS_LAST);

    simde__m64
      a = simde_test_x86_random_i64x1(),
      b = simde_test_x86_random_i64x1();
    SIMDE_TEST_EXPECT_FAILURE(simde_test_x86_assert_equal_i64x1(a, b));

    b = a;
    SIMDE_TEST_EXPECT_SUCCESS(simde_test_x86_assert_equal_i64x1(a, b));
  }

  {
    fputc('\n', stdout);

    simde_test_x86_write_u8x8(2, simde_test_x86_random_u8x8(), SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_u8x8(2, simde_test_x86_random_u8x8(), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_u8x8(2, simde_test_x86_random_u8x8(), SIMDE_TEST_VEC_POS_LAST);

    simde__m64
      a = simde_test_x86_random_u8x8(),
      b = simde_test_x86_random_u8x8();
    SIMDE_TEST_EXPECT_FAILURE(simde_test_x86_assert_equal_u8x8(a, b));

    b = a;
    SIMDE_TEST_EXPECT_SUCCESS(simde_test_x86_assert_equal_u8x8(a, b));
  }

  {
    fputc('\n', stdout);

    simde_test_x86_write_u16x4(2, simde_test_x86_random_u16x4(), SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_u16x4(2, simde_test_x86_random_u16x4(), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_u16x4(2, simde_test_x86_random_u16x4(), SIMDE_TEST_VEC_POS_LAST);

    simde__m64
      a = simde_test_x86_random_u16x4(),
      b = simde_test_x86_random_u16x4();
    SIMDE_TEST_EXPECT_FAILURE(simde_test_x86_assert_equal_u16x4(a, b));

    b = a;
    SIMDE_TEST_EXPECT_SUCCESS(simde_test_x86_assert_equal_u16x4(a, b));
  }

  {
    fputc('\n', stdout);

    simde_test_x86_write_u32x2(2, simde_test_x86_random_u32x2(), SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_u32x2(2, simde_test_x86_random_u32x2(), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_u32x2(2, simde_test_x86_random_u32x2(), SIMDE_TEST_VEC_POS_LAST);

    simde__m64
      a = simde_test_x86_random_u32x2(),
      b = simde_test_x86_random_u32x2();
    SIMDE_TEST_EXPECT_FAILURE(simde_test_x86_assert_equal_u32x2(a, b));

    b = a;
    SIMDE_TEST_EXPECT_SUCCESS(simde_test_x86_assert_equal_u32x2(a, b));
  }

  {
    fputc('\n', stdout);

    simde_test_x86_write_u64x2(2, simde_test_x86_random_u64x2(), SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_u64x2(2, simde_test_x86_random_u64x2(), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_u64x2(2, simde_test_x86_random_u64x2(), SIMDE_TEST_VEC_POS_LAST);

    simde__m64
      a = simde_test_x86_random_u64x1(),
      b = simde_test_x86_random_u64x1();
    SIMDE_TEST_EXPECT_FAILURE(simde_test_x86_assert_equal_u64x1(a, b));

    b = a;
    SIMDE_TEST_EXPECT_SUCCESS(simde_test_x86_assert_equal_u64x1(a, b));
  }
}

static void
test_128(void) {
  {
    fputc('\n', stdout);

    simde_test_x86_write_f32x4(2, simde_test_x86_random_f32x4(-1000.0f, 1000.0f), SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f32x4(2, simde_test_x86_random_f32x4(-1000.0f, 1000.0f), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x4(2, simde_test_x86_random_f32x4(-1000.0f, 1000.0f), SIMDE_TEST_VEC_POS_LAST);

    simde__m128
      a = simde_test_x86_random_f32x4(-1000.0f, 1000.0f),
      b = simde_test_x86_random_f32x4(-1000.0f, 1000.0f);
    SIMDE_TEST_EXPECT_FAILURE(simde_test_x86_assert_equal_f32x4(a, b, 1));

    b = a;
    SIMDE_TEST_EXPECT_SUCCESS(simde_test_x86_assert_equal_f32x4(a, b, 1));
  }

  {
    fputc('\n', stdout);

    simde_test_x86_write_f64x2(2, simde_test_x86_random_f64x2(-1000.0, 1000.0), SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f64x2(2, simde_test_x86_random_f64x2(-1000.0, 1000.0), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x2(2, simde_test_x86_random_f64x2(-1000.0, 1000.0), SIMDE_TEST_VEC_POS_LAST);

    simde__m128d
      a = simde_test_x86_random_f64x2(-1000.0, 1000.0),
      b = simde_test_x86_random_f64x2(-1000.0, 1000.0);
    SIMDE_TEST_EXPECT_FAILURE(simde_test_x86_assert_equal_f64x2(a, b, 1));

    b = a;
    SIMDE_TEST_EXPECT_SUCCESS(simde_test_x86_assert_equal_f64x2(a, b, 1));
  }

  {
    fputc('\n', stdout);

    simde_test_x86_write_i8x16(2, simde_test_x86_random_i8x16(), SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i8x16(2, simde_test_x86_random_i8x16(), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i8x16(2, simde_test_x86_random_i8x16(), SIMDE_TEST_VEC_POS_LAST);

    simde__m128i
      a = simde_test_x86_random_i8x16(),
      b = simde_test_x86_random_i8x16();
    SIMDE_TEST_EXPECT_FAILURE(simde_test_x86_assert_equal_i8x16(a, b));

    b = a;
    SIMDE_TEST_EXPECT_SUCCESS(simde_test_x86_assert_equal_i8x16(a, b));
  }

  {
    fputc('\n', stdout);

    simde_test_x86_write_i16x8(2, simde_test_x86_random_i16x8(), SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i16x8(2, simde_test_x86_random_i16x8(), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x8(2, simde_test_x86_random_i16x8(), SIMDE_TEST_VEC_POS_LAST);

    simde__m128i
      a = simde_test_x86_random_i16x8(),
      b = simde_test_x86_random_i16x8();
    SIMDE_TEST_EXPECT_FAILURE(simde_test_x86_assert_equal_i16x8(a, b));

    b = a;
    SIMDE_TEST_EXPECT_SUCCESS(simde_test_x86_assert_equal_i16x8(a, b));
  }

  {
    fputc('\n', stdout);

    simde_test_x86_write_i32x4(2, simde_test_x86_random_i32x4(), SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x4(2, simde_test_x86_random_i32x4(), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, simde_test_x86_random_i32x4(), SIMDE_TEST_VEC_POS_LAST);

    simde__m128i
      a = simde_test_x86_random_i32x4(),
      b = simde_test_x86_random_i32x4();
    SIMDE_TEST_EXPECT_FAILURE(simde_test_x86_assert_equal_i32x4(a, b));

    b = a;
    SIMDE_TEST_EXPECT_SUCCESS(simde_test_x86_assert_equal_i32x4(a, b));
  }

  {
    fputc('\n', stdout);

    simde_test_x86_write_i64x2(2, simde_test_x86_random_i64x2(), SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i64x2(2, simde_test_x86_random_i64x2(), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x2(2, simde_test_x86_random_i64x2(), SIMDE_TEST_VEC_POS_LAST);

    simde__m128i
      a = simde_test_x86_random_i64x2(),
      b = simde_test_x86_random_i64x2();
    SIMDE_TEST_EXPECT_FAILURE(simde_test_x86_assert_equal_i64x2(a, b));

    b = a;
    SIMDE_TEST_EXPECT_SUCCESS(simde_test_x86_assert_equal_i64x2(a, b));
  }

  {
    fputc('\n', stdout);

    simde_test_x86_write_u8x16(2, simde_test_x86_random_u8x16(), SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_u8x16(2, simde_test_x86_random_u8x16(), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_u8x16(2, simde_test_x86_random_u8x16(), SIMDE_TEST_VEC_POS_LAST);

    simde__m128i
      a = simde_test_x86_random_u8x16(),
      b = simde_test_x86_random_u8x16();
    SIMDE_TEST_EXPECT_FAILURE(simde_test_x86_assert_equal_u8x16(a, b));

    b = a;
    SIMDE_TEST_EXPECT_SUCCESS(simde_test_x86_assert_equal_u8x16(a, b));
  }

  {
    fputc('\n', stdout);

    simde_test_x86_write_u16x8(2, simde_test_x86_random_u16x8(), SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_u16x8(2, simde_test_x86_random_u16x8(), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_u16x8(2, simde_test_x86_random_u16x8(), SIMDE_TEST_VEC_POS_LAST);

    simde__m128i
      a = simde_test_x86_random_u16x8(),
      b = simde_test_x86_random_u16x8();
    SIMDE_TEST_EXPECT_FAILURE(simde_test_x86_assert_equal_u16x8(a, b));

    b = a;
    SIMDE_TEST_EXPECT_SUCCESS(simde_test_x86_assert_equal_u16x8(a, b));
  }

  {
    fputc('\n', stdout);

    simde_test_x86_write_u32x4(2, simde_test_x86_random_u32x4(), SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_u32x4(2, simde_test_x86_random_u32x4(), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_u32x4(2, simde_test_x86_random_u32x4(), SIMDE_TEST_VEC_POS_LAST);

    simde__m128i
      a = simde_test_x86_random_u32x4(),
      b = simde_test_x86_random_u32x4();
    SIMDE_TEST_EXPECT_FAILURE(simde_test_x86_assert_equal_u32x4(a, b));

    b = a;
    SIMDE_TEST_EXPECT_SUCCESS(simde_test_x86_assert_equal_u32x4(a, b));
  }

  {
    fputc('\n', stdout);

    simde_test_x86_write_u64x2(2, simde_test_x86_random_u64x2(), SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_u64x2(2, simde_test_x86_random_u64x2(), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_u64x2(2, simde_test_x86_random_u64x2(), SIMDE_TEST_VEC_POS_LAST);

    simde__m128i
      a = simde_test_x86_random_u64x2(),
      b = simde_test_x86_random_u64x2();
    SIMDE_TEST_EXPECT_FAILURE(simde_test_x86_assert_equal_u64x2(a, b));

    b = a;
    SIMDE_TEST_EXPECT_SUCCESS(simde_test_x86_assert_equal_u64x2(a, b));
  }
}

static void
test_256(void) {
  {
    fputc('\n', stdout);

    simde_test_x86_write_f32x8(2, simde_test_x86_random_f32x8(-1000.0f, 1000.0f), SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f32x8(2, simde_test_x86_random_f32x8(-1000.0f, 1000.0f), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x8(2, simde_test_x86_random_f32x8(-1000.0f, 1000.0f), SIMDE_TEST_VEC_POS_LAST);

    simde__m256
      a = simde_test_x86_random_f32x8(-1000.0f, 1000.0f),
      b = simde_test_x86_random_f32x8(-1000.0f, 1000.0f);
    SIMDE_TEST_EXPECT_FAILURE(simde_test_x86_assert_equal_f32x8(a, b, 1));

    b = a;
    SIMDE_TEST_EXPECT_SUCCESS(simde_test_x86_assert_equal_f32x8(a, b, 1));
  }

  {
    fputc('\n', stdout);

    simde_test_x86_write_f64x4(2, simde_test_x86_random_f64x4(-1000.0, 1000.0), SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f64x4(2, simde_test_x86_random_f64x4(-1000.0, 1000.0), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x4(2, simde_test_x86_random_f64x4(-1000.0, 1000.0), SIMDE_TEST_VEC_POS_LAST);

    simde__m256d
      a = simde_test_x86_random_f64x4(-1000.0, 1000.0),
      b = simde_test_x86_random_f64x4(-1000.0, 1000.0);
    SIMDE_TEST_EXPECT_FAILURE(simde_test_x86_assert_equal_f64x4(a, b, 1));

    b = a;
    SIMDE_TEST_EXPECT_SUCCESS(simde_test_x86_assert_equal_f64x4(a, b, 1));
  }

  {
    fputc('\n', stdout);

    simde_test_x86_write_i8x32(2, simde_test_x86_random_i8x32(), SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i8x32(2, simde_test_x86_random_i8x32(), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i8x32(2, simde_test_x86_random_i8x32(), SIMDE_TEST_VEC_POS_LAST);

    simde__m256i
      a = simde_test_x86_random_i8x32(),
      b = simde_test_x86_random_i8x32();
    SIMDE_TEST_EXPECT_FAILURE(simde_test_x86_assert_equal_i8x32(a, b));

    b = a;
    SIMDE_TEST_EXPECT_SUCCESS(simde_test_x86_assert_equal_i8x32(a, b));
  }

  {
    fputc('\n', stdout);

    simde_test_x86_write_i16x16(2, simde_test_x86_random_i16x16(), SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i16x16(2, simde_test_x86_random_i16x16(), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x16(2, simde_test_x86_random_i16x16(), SIMDE_TEST_VEC_POS_LAST);

    simde__m256i
      a = simde_test_x86_random_i16x16(),
      b = simde_test_x86_random_i16x16();
    SIMDE_TEST_EXPECT_FAILURE(simde_test_x86_assert_equal_i16x16(a, b));

    b = a;
    SIMDE_TEST_EXPECT_SUCCESS(simde_test_x86_assert_equal_i16x16(a, b));
  }

  {
    fputc('\n', stdout);

    simde_test_x86_write_i32x8(2, simde_test_x86_random_i32x8(), SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x8(2, simde_test_x86_random_i32x8(), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x8(2, simde_test_x86_random_i32x8(), SIMDE_TEST_VEC_POS_LAST);

    simde__m256i
      a = simde_test_x86_random_i32x8(),
      b = simde_test_x86_random_i32x8();
    SIMDE_TEST_EXPECT_FAILURE(simde_test_x86_assert_equal_i32x8(a, b));

    b = a;
    SIMDE_TEST_EXPECT_SUCCESS(simde_test_x86_assert_equal_i32x8(a, b));
  }

  {
    fputc('\n', stdout);

    simde_test_x86_write_i64x4(2, simde_test_x86_random_i64x4(), SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i64x4(2, simde_test_x86_random_i64x4(), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x4(2, simde_test_x86_random_i64x4(), SIMDE_TEST_VEC_POS_LAST);

    simde__m256i
      a = simde_test_x86_random_i64x4(),
      b = simde_test_x86_random_i64x4();
    SIMDE_TEST_EXPECT_FAILURE(simde_test_x86_assert_equal_i64x4(a, b));

    b = a;
    SIMDE_TEST_EXPECT_SUCCESS(simde_test_x86_assert_equal_i64x4(a, b));
  }

  {
    fputc('\n', stdout);

    simde_test_x86_write_u8x32(2, simde_test_x86_random_u8x32(), SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_u8x32(2, simde_test_x86_random_u8x32(), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_u8x32(2, simde_test_x86_random_u8x32(), SIMDE_TEST_VEC_POS_LAST);

    simde__m256i
      a = simde_test_x86_random_u8x32(),
      b = simde_test_x86_random_u8x32();
    SIMDE_TEST_EXPECT_FAILURE(simde_test_x86_assert_equal_u8x32(a, b));

    b = a;
    SIMDE_TEST_EXPECT_SUCCESS(simde_test_x86_assert_equal_u8x32(a, b));
  }

  {
    fputc('\n', stdout);

    simde_test_x86_write_u16x16(2, simde_test_x86_random_u16x16(), SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_u16x16(2, simde_test_x86_random_u16x16(), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_u16x16(2, simde_test_x86_random_u16x16(), SIMDE_TEST_VEC_POS_LAST);

    simde__m256i
      a = simde_test_x86_random_u16x16(),
      b = simde_test_x86_random_u16x16();
    SIMDE_TEST_EXPECT_FAILURE(simde_test_x86_assert_equal_u16x16(a, b));

    b = a;
    SIMDE_TEST_EXPECT_SUCCESS(simde_test_x86_assert_equal_u16x16(a, b));
  }

  {
    fputc('\n', stdout);

    simde_test_x86_write_u32x8(2, simde_test_x86_random_u32x8(), SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_u32x8(2, simde_test_x86_random_u32x8(), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_u32x8(2, simde_test_x86_random_u32x8(), SIMDE_TEST_VEC_POS_LAST);

    simde__m256i
      a = simde_test_x86_random_u32x8(),
      b = simde_test_x86_random_u32x8();
    SIMDE_TEST_EXPECT_FAILURE(simde_test_x86_assert_equal_u32x8(a, b));

    b = a;
    SIMDE_TEST_EXPECT_SUCCESS(simde_test_x86_assert_equal_u32x8(a, b));
  }

  {
    fputc('\n', stdout);

    simde_test_x86_write_u64x4(2, simde_test_x86_random_u64x4(), SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_u64x4(2, simde_test_x86_random_u64x4(), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_u64x4(2, simde_test_x86_random_u64x4(), SIMDE_TEST_VEC_POS_LAST);

    simde__m256i
      a = simde_test_x86_random_u64x4(),
      b = simde_test_x86_random_u64x4();
    SIMDE_TEST_EXPECT_FAILURE(simde_test_x86_assert_equal_u64x4(a, b));

    b = a;
    SIMDE_TEST_EXPECT_SUCCESS(simde_test_x86_assert_equal_u64x4(a, b));
  }
}

static void
test_512(void) {
  {
    fputc('\n', stdout);

    simde_test_x86_write_f32x16(2, simde_test_x86_random_f32x16(-1000.0f, 1000.0f), SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f32x16(2, simde_test_x86_random_f32x16(-1000.0f, 1000.0f), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x16(2, simde_test_x86_random_f32x16(-1000.0f, 1000.0f), SIMDE_TEST_VEC_POS_LAST);

    simde__m512
      a = simde_test_x86_random_f32x16(-1000.0f, 1000.0f),
      b = simde_test_x86_random_f32x16(-1000.0f, 1000.0f);
    SIMDE_TEST_EXPECT_FAILURE(simde_test_x86_assert_equal_f32x16(a, b, 1));

    b = a;
    SIMDE_TEST_EXPECT_SUCCESS(simde_test_x86_assert_equal_f32x16(a, b, 1));
  }

  {
    fputc('\n', stdout);

    simde_test_x86_write_f64x8(2, simde_test_x86_random_f64x8(-1000.0, 1000.0), SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f64x8(2, simde_test_x86_random_f64x8(-1000.0, 1000.0), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x8(2, simde_test_x86_random_f64x8(-1000.0, 1000.0), SIMDE_TEST_VEC_POS_LAST);

    simde__m512d
      a = simde_test_x86_random_f64x8(-1000.0, 1000.0),
      b = simde_test_x86_random_f64x8(-1000.0, 1000.0);
    SIMDE_TEST_EXPECT_FAILURE(simde_test_x86_assert_equal_f64x8(a, b, 1));

    b = a;
    SIMDE_TEST_EXPECT_SUCCESS(simde_test_x86_assert_equal_f64x8(a, b, 1));
  }

  {
    fputc('\n', stdout);

    simde_test_x86_write_i8x64(2, simde_test_x86_random_i8x64(), SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i8x64(2, simde_test_x86_random_i8x64(), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i8x64(2, simde_test_x86_random_i8x64(), SIMDE_TEST_VEC_POS_LAST);

    simde__m512i
      a = simde_test_x86_random_i8x64(),
      b = simde_test_x86_random_i8x64();
    SIMDE_TEST_EXPECT_FAILURE(simde_test_x86_assert_equal_i8x64(a, b));

    b = a;
    SIMDE_TEST_EXPECT_SUCCESS(simde_test_x86_assert_equal_i8x64(a, b));
  }

  {
    fputc('\n', stdout);

    simde_test_x86_write_i16x32(2, simde_test_x86_random_i16x32(), SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i16x32(2, simde_test_x86_random_i16x32(), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x32(2, simde_test_x86_random_i16x32(), SIMDE_TEST_VEC_POS_LAST);

    simde__m512i
      a = simde_test_x86_random_i16x32(),
      b = simde_test_x86_random_i16x32();
    SIMDE_TEST_EXPECT_FAILURE(simde_test_x86_assert_equal_i16x32(a, b));

    b = a;
    SIMDE_TEST_EXPECT_SUCCESS(simde_test_x86_assert_equal_i16x32(a, b));
  }

  {
    fputc('\n', stdout);

    simde_test_x86_write_i32x16(2, simde_test_x86_random_i32x16(), SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x16(2, simde_test_x86_random_i32x16(), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x16(2, simde_test_x86_random_i32x16(), SIMDE_TEST_VEC_POS_LAST);

    simde__m512i
      a = simde_test_x86_random_i32x16(),
      b = simde_test_x86_random_i32x16();
    SIMDE_TEST_EXPECT_FAILURE(simde_test_x86_assert_equal_i32x16(a, b));

    b = a;
    SIMDE_TEST_EXPECT_SUCCESS(simde_test_x86_assert_equal_i32x16(a, b));
  }

  {
    fputc('\n', stdout);

    simde_test_x86_write_i64x8(2, simde_test_x86_random_i64x8(), SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i64x8(2, simde_test_x86_random_i64x8(), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x8(2, simde_test_x86_random_i64x8(), SIMDE_TEST_VEC_POS_LAST);

    simde__m512i
      a = simde_test_x86_random_i64x8(),
      b = simde_test_x86_random_i64x8();
    SIMDE_TEST_EXPECT_FAILURE(simde_test_x86_assert_equal_i64x8(a, b));

    b = a;
    SIMDE_TEST_EXPECT_SUCCESS(simde_test_x86_assert_equal_i64x8(a, b));
  }

  {
    fputc('\n', stdout);

    simde_test_x86_write_u8x64(2, simde_test_x86_random_u8x64(), SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_u8x64(2, simde_test_x86_random_u8x64(), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_u8x64(2, simde_test_x86_random_u8x64(), SIMDE_TEST_VEC_POS_LAST);

    simde__m512i
      a = simde_test_x86_random_u8x64(),
      b = simde_test_x86_random_u8x64();
    SIMDE_TEST_EXPECT_FAILURE(simde_test_x86_assert_equal_u8x64(a, b));

    b = a;
    SIMDE_TEST_EXPECT_SUCCESS(simde_test_x86_assert_equal_u8x64(a, b));
  }

  {
    fputc('\n', stdout);

    simde_test_x86_write_u16x32(2, simde_test_x86_random_u16x32(), SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_u16x32(2, simde_test_x86_random_u16x32(), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_u16x32(2, simde_test_x86_random_u16x32(), SIMDE_TEST_VEC_POS_LAST);

    simde__m512i
      a = simde_test_x86_random_u16x32(),
      b = simde_test_x86_random_u16x32();
    SIMDE_TEST_EXPECT_FAILURE(simde_test_x86_assert_equal_u16x32(a, b));

    b = a;
    SIMDE_TEST_EXPECT_SUCCESS(simde_test_x86_assert_equal_u16x32(a, b));
  }

  {
    fputc('\n', stdout);

    simde_test_x86_write_u32x16(2, simde_test_x86_random_u32x16(), SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_u32x16(2, simde_test_x86_random_u32x16(), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_u32x16(2, simde_test_x86_random_u32x16(), SIMDE_TEST_VEC_POS_LAST);

    simde__m512i
      a = simde_test_x86_random_u32x16(),
      b = simde_test_x86_random_u32x16();
    SIMDE_TEST_EXPECT_FAILURE(simde_test_x86_assert_equal_u32x16(a, b));

    b = a;
    SIMDE_TEST_EXPECT_SUCCESS(simde_test_x86_assert_equal_u32x16(a, b));
  }

  {
    fputc('\n', stdout);

    simde_test_x86_write_u64x8(2, simde_test_x86_random_u64x8(), SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_u64x8(2, simde_test_x86_random_u64x8(), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_u64x8(2, simde_test_x86_random_u64x8(), SIMDE_TEST_VEC_POS_LAST);

    simde__m512i
      a = simde_test_x86_random_u64x8(),
      b = simde_test_x86_random_u64x8();
    SIMDE_TEST_EXPECT_FAILURE(simde_test_x86_assert_equal_u64x8(a, b));

    b = a;
    SIMDE_TEST_EXPECT_SUCCESS(simde_test_x86_assert_equal_u64x8(a, b));
  }
}

int main(void) {
  test_64();
  test_128();
  test_256();
  test_512();

  return 0;
}
