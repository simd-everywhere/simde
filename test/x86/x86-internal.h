#if !defined(SIMDE__X86_INTERNAL_H)
#define SIMDE__X86_INTERNAL_H

#include "../test.h"

MunitSuite simde_mmx_test_suite;
MunitSuite simde_mmx_emul_test_suite;
MunitSuite simde_mmx_cmp_test_suite;

MunitSuite simde_sse_test_suite;
MunitSuite simde_sse_emul_test_suite;
MunitSuite simde_sse_cmp_test_suite;

MunitSuite simde_sse2_test_suite;
MunitSuite simde_sse2_emul_test_suite;
MunitSuite simde_sse2_cmp_test_suite;

MunitSuite simde_sse3_test_suite;
MunitSuite simde_sse3_emul_test_suite;

MunitSuite simde_ssse3_test_suite;
MunitSuite simde_ssse3_emul_test_suite;

MunitSuite simde_sse4_1_test_suite;
MunitSuite simde_sse4_1_emul_test_suite;

MunitSuite simde_sse4_2_test_suite;
MunitSuite simde_sse4_2_emul_test_suite;

MunitSuite simde_avx_test_suite;
MunitSuite simde_avx_emul_test_suite;

MunitSuite simde_avx2_test_suite;
MunitSuite simde_avx2_emul_test_suite;

#define simde_assert_m64_i8(a, op, b) \
  simde_assert_typev(int8_t, PRId8, 8, (int8_t*) &(a), op, (int8_t*) &(b))
#define simde_assert_m64_u8(a, op, b) \
  simde_assert_typev(uint8_t, PRIu8, 8, (uint8_t*) &(a), op, (uint8_t*) &(b))
#define simde_assert_m64_i16(a, op, b) \
  simde_assert_int16vx(4, (int16_t*) &(a), op, (int16_t*) &(b))
#define simde_assert_m64_u16(a, op, b) \
  simde_assert_uint16vx(4, (uint16_t*) &(a), op, (uint16_t*) &(b))
#define simde_assert_m64_i32(a, op, b) \
  simde_assert_int32vx(2, (int32_t*) &(a), op, (int32_t*) &(b))
#define simde_assert_m64_u32(a, op, b) \
  simde_assert_uint32vx(2, (uint32_t*) &(a), op, (uint32_t*) &(b))
#define simde_assert_m64_i64(a, op, b) \
  simde_assert_int64vx(1, (int64_t*) &(a), op, (int64_t*) &(b))
#define simde_assert_m64_u64(a, op, b) \
  simde_assert_uint64vx(1, (uint64_t*) &(a), op, (uint64_t*) &(b))
#define simde_assert_m64_f32(a, op, b) \
  simde_assert_typev(simde_float32, "f", 2, (simde_float32*) &(a), op, (simde_float32*) &(b))
#define simde_assert_m64_f64(a, op, b) \
  simde_assert_typev(simde_float64, "f", 1, (simde_float64*) &(a), op, (simde_float64*) &(b))
#define simde_assert_m64_f64_equal(a, b, precision) \
  simde_assert_f32v_equal(simde_float64, 1, (simde_float64*) &(a), (simde_float64*) &(b), precision)

#define simde_assert_m128_i8(a, op, b) \
  simde_assert_typev(int8_t, PRId8, 16, (int8_t*) &(a), op, (int8_t*) &(b))
#define simde_assert_m128_u8(a, op, b) \
  simde_assert_typev(uint8_t, PRIu8, 16, (uint8_t*) &(a), op, (uint8_t*) &(b))
#define simde_assert_m128_i16(a, op, b) \
  simde_assert_int16vx(8, (int16_t*) &(a), op, (int16_t*) &(b))
#define simde_assert_m128_u16(a, op, b) \
  simde_assert_uint16vx(8, (uint16_t*) &(a), op, (uint16_t*) &(b))
#define simde_assert_m128_i32(a, op, b) \
  simde_assert_int32vx(4, (int32_t*) &(a), op, (int32_t*) &(b))
#define simde_assert_m128_u32(a, op, b) \
  simde_assert_uint32vx(4, (uint32_t*) &(a), op, (uint32_t*) &(b))
#define simde_assert_m128_i64(a, op, b) \
  simde_assert_int64vx(2, (int64_t*) &(a), op, (int64_t*) &(b))
#define simde_assert_m128_u64(a, op, b) \
  simde_assert_uint64vx(2, (uint64_t*) &(a), op, (uint64_t*) &(b))
#define simde_assert_m128_f32(a, op, b) \
  simde_assert_typev(simde_float32, "f", 4, (simde_float32*) &(a), op, (simde_float32*) &(b))
#define simde_assert_m128_f32_equal(a, b, precision) \
  simde_assert_f32v_equal(simde_float32, 4, (simde_float32*) &(a), (simde_float32*) &(b), precision)
#define simde_assert_m128_f32_close(a, b, precision) \
  simde_assert_f32v_close(simde_float32, 4, (simde_float32*) &(a), (simde_float32*) &(b), precision)
#define simde_assert_m128_f64(a, op, b) \
  simde_assert_typev(simde_float64, "f", 2, (simde_float64*) &(a), op, (simde_float64*) &(b))
#define simde_assert_m128_f64_equal(a, b, precision) \
  simde_assert_f32v_equal(simde_float64, 2, (simde_float64*) &(a), (simde_float64*) &(b), precision)
#define simde_assert_m128_f64_close(a, b, precision) \
  simde_assert_f32v_close(simde_float64, 2, (simde_float64*) &(a), (simde_float64*) &(b), precision)

#define simde_assert_m128i_i8(a, op, b) \
  simde_assert_typev(int8_t, PRId8, 16, (int8_t*) &(a), op, (int8_t*) &(b))
#define simde_assert_m128i_u8(a, op, b) \
  simde_assert_typev(uint8_t, PRIu8, 16, (uint8_t*) &(a), op, (uint8_t*) &(b))
#define simde_assert_m128i_i16(a, op, b) \
  simde_assert_typev(int16_t, PRId16, 8, (int16_t*) &(a), op, (int16_t*) &(b))
#define simde_assert_m128i_u16(a, op, b) \
  simde_assert_typev(uint16_t, PRIu16, 8, (uint16_t*) &(a), op, (uint16_t*) &(b))
#define simde_assert_m128i_i32(a, op, b) \
  simde_assert_typev(int32_t, PRId32, 4, (int32_t*) &(a), op, (int32_t*) &(b))
#define simde_assert_m128i_u32(a, op, b) \
  simde_assert_typev(uint32_t, PRIu32, 4, (uint32_t*) &(a), op, (uint32_t*) &(b))
#define simde_assert_m128i_i64(a, op, b) \
  simde_assert_typev(int64_t, PRId64, 2, (int64_t*) &(a), op, (int64_t*) &(b))
#define simde_assert_m128i_u64(a, op, b) \
  simde_assert_typev(uint64_t, PRIu64, 2, (uint64_t*) &(a), op, (uint64_t*) &(b))

#define simde_assert_m128d_f32(a, op, b) \
  simde_assert_typev(simde_float32, "f", 4, (simde_float32*) &(a), op, (simde_float32*) &(b))
#define simde_assert_m128d_f32_equal(a, b, precision) \
  simde_assert_f32v_equal(simde_float32, 4, (simde_float32*) &(a), (simde_float32*) &(b), precision)
#define simde_assert_m128d_f64(a, op, b) \
  simde_assert_typev(simde_float64, "f", 2, (simde_float64*) &(a), op, (simde_float64*) &(b))
#define simde_assert_m128d_f64_equal(a, b, precision) \
  simde_assert_f32v_equal(simde_float64, 2, (simde_float64*) &(a), (simde_float64*) &(b), precision)
#define simde_assert_m128d_f64_close(a, b, precision) \
  simde_assert_f32v_close(simde_float64, 2, (simde_float64*) &(a), (simde_float64*) &(b), precision)

#define simde_assert_m256i_i8(a, op, b) \
  simde_assert_typev(int8_t, PRId8, 32, (int8_t*) &(a), op, (int8_t*) &(b))
#define simde_assert_m256i_u8(a, op, b) \
  simde_assert_typev(uint8_t, PRIu8, 32, (uint8_t*) &(a), op, (uint8_t*) &(b))
#define simde_assert_m256i_i16(a, op, b) \
  simde_assert_typev(int16_t, PRId16, 16, (int16_t*) &(a), op, (int16_t*) &(b))
#define simde_assert_m256i_u16(a, op, b) \
  simde_assert_typev(uint16_t, PRIu16, 16, (uint16_t*) &(a), op, (uint16_t*) &(b))
#define simde_assert_m256i_i32(a, op, b) \
  simde_assert_typev(int32_t, PRId32, 8, (int32_t*) &(a), op, (int32_t*) &(b))
#define simde_assert_m256i_u32(a, op, b) \
  simde_assert_typev(uint32_t, PRIu32, 8, (uint32_t*) &(a), op, (uint32_t*) &(b))
#define simde_assert_m256i_i64(a, op, b) \
  simde_assert_typev(int64_t, PRId64, 4, (int64_t*) &(a), op, (int64_t*) &(b))
#define simde_assert_m256i_u64(a, op, b) \
  simde_assert_typev(uint64_t, PRIu64, 4, (uint64_t*) &(a), op, (uint64_t*) &(b))

#define simde_assert_m256d_f64(a, op, b) \
  simde_assert_typev(simde_float64, "f", 4, (simde_float64*) &(a), op, (simde_float64*) &(b))
#define simde_assert_m256d_f64_equal(a, b, precision) \
  simde_assert_f32v_equal(simde_float64, 4, (simde_float64*) &(a), (simde_float64*) &(b), precision)
#define simde_assert_m256d_f64_close(a, b, precision) \
  simde_assert_f32v_close(simde_float64, 4, (simde_float64*) &(a), (simde_float64*) &(b), precision)

#define simde_assert_m256_f32(a, op, b) \
  simde_assert_typev(simde_float32, "f", 8, (simde_float32*) &(a), op, (simde_float32*) &(b))
#define simde_assert_m256_f32_equal(a, b, precision) \
  simde_assert_f32v_equal(simde_float32, 8, (simde_float32*) &(a), (simde_float32*) &(b), precision)

#endif
