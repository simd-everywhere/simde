#if !defined(SIMDE__ARM_INTERNAL_H)
#define SIMDE__ARM_INTERNAL_H

#include "../test.h"

#if !defined(SIMDE_NO_NATIVE)
#  define NEON_TEST_SUITE(name) simde_neon_##name##_emul_test_suite
#else
#  define NEON_TEST_SUITE(name) simde_neon_##name##_test_suite
#endif

MunitSuite simde_neon_vdup_n_test_suite;
MunitSuite simde_neon_vdup_n_emul_test_suite;

#define simde_neon_assert_int8x8(a, op, b) \
  simde_assert_typev(int8_t, PRId8, (sizeof(a) / sizeof(int8_t)), (int8_t*) &(a), op, (int8_t*) &(b))
#define simde_neon_assert_int16x4(a, op, b) \
  simde_assert_typev(int16_t, PRId16, (sizeof(a) / sizeof(int16_t)), (int16_t*) &(a), op, (int16_t*) &(b))
#define simde_neon_assert_int32x2(a, op, b) \
  simde_assert_typev(int32_t, PRId32, (sizeof(a) / sizeof(int32_t)), (int32_t*) &(a), op, (int32_t*) &(b))
#define simde_neon_assert_int64x1(a, op, b) \
  simde_assert_typev(int64_t, PRId64, (sizeof(a) / sizeof(int64_t)), (int64_t*) &(a), op, (int64_t*) &(b))
#define simde_neon_assert_uint8x8(a, op, b) \
  simde_assert_typev(uint8_t, PRId8, (sizeof(a) / sizeof(uint8_t)), (uint8_t*) &(a), op, (uint8_t*) &(b))
#define simde_neon_assert_uint16x4(a, op, b) \
  simde_assert_typev(uint16_t, PRId16, (sizeof(a) / sizeof(uint16_t)), (uint16_t*) &(a), op, (uint16_t*) &(b))
#define simde_neon_assert_uint32x2(a, op, b) \
  simde_assert_typev(uint32_t, PRId32, (sizeof(a) / sizeof(uint32_t)), (uint32_t*) &(a), op, (uint32_t*) &(b))
#define simde_neon_assert_uint64x1(a, op, b) \
  simde_assert_typev(uint64_t, PRId64, (sizeof(a) / sizeof(uint64_t)), (uint64_t*) &(a), op, (uint64_t*) &(b))
#define simde_neon_assert_float32x2(a, op, b) \
  simde_assert_typev(simde_float32, "f", (sizeof(a) / sizeof(simde_float32)), (simde_float32*) &(a), op, (simde_float32*) &(b))
#define simde_neon_assert_float32x2_equal(a, b, precision) \
  simde_assert_f32v_equal(simde_float32, (sizeof(a) / sizeof(simde_float32)), (simde_float32*) &(a), (simde_float32*) &(b), precision)
#define simde_neon_assert_float64x1(a, op, b) \
  simde_assert_typev(simde_float64, "f", (sizeof(a) / sizeof(simde_float64)), (simde_float64*) &(a), op, (simde_float64*) &(b))
#define simde_neon_assert_float64x1_equal(a, b, precision) \
  simde_assert_f32v_equal(simde_float64, (sizeof(a) / sizeof(simde_float64)), (simde_float64*) &(a), (simde_float64*) &(b), precision)

#define simde_neon_assert_int8x16(a, op, b) \
  simde_assert_typev(int8_t, PRId8, (sizeof(a) / sizeof(int8_t)), (int8_t*) &(a), op, (int8_t*) &(b))
#define simde_neon_assert_int16x8(a, op, b) \
  simde_assert_typev(int16_t, PRId16, (sizeof(a) / sizeof(int16_t)), (int16_t*) &(a), op, (int16_t*) &(b))
#define simde_neon_assert_int32x4(a, op, b) \
  simde_assert_typev(int32_t, PRId32, (sizeof(a) / sizeof(int32_t)), (int32_t*) &(a), op, (int32_t*) &(b))
#define simde_neon_assert_int64x2(a, op, b) \
  simde_assert_typev(int64_t, PRId64, (sizeof(a) / sizeof(int64_t)), (int64_t*) &(a), op, (int64_t*) &(b))
#define simde_neon_assert_uint8x16(a, op, b) \
  simde_assert_typev(uint8_t, PRId8, (sizeof(a) / sizeof(uint8_t)), (uint8_t*) &(a), op, (uint8_t*) &(b))
#define simde_neon_assert_uint16x8(a, op, b) \
  simde_assert_typev(uint16_t, PRId16, (sizeof(a) / sizeof(uint16_t)), (uint16_t*) &(a), op, (uint16_t*) &(b))
#define simde_neon_assert_uint32x4(a, op, b) \
  simde_assert_typev(uint32_t, PRId32, (sizeof(a) / sizeof(uint32_t)), (uint32_t*) &(a), op, (uint32_t*) &(b))
#define simde_neon_assert_uint64x2(a, op, b) \
  simde_assert_typev(uint64_t, PRId64, (sizeof(a) / sizeof(uint64_t)), (uint64_t*) &(a), op, (uint64_t*) &(b))
#define simde_neon_assert_float32x4(a, op, b) \
  simde_assert_typev(simde_float32, "f", (sizeof(a) / sizeof(simde_float32)), (simde_float32*) &(a), op, (simde_float32*) &(b))
#define simde_neon_assert_float32x4_equal(a, b, precision) \
  simde_assert_f32v_equal(simde_float32, (sizeof(a) / sizeof(simde_float32)), (simde_float32*) &(a), (simde_float32*) &(b), precision)
#define simde_neon_assert_float64x2(a, op, b) \
  simde_assert_typev(simde_float64, "f", (sizeof(a) / sizeof(simde_float64)), (simde_float64*) &(a), op, (simde_float64*) &(b))
#define simde_neon_assert_float64x2_equal(a, b, precision) \
  simde_assert_f32v_equal(simde_float64, (sizeof(a) / sizeof(simde_float64)), (simde_float64*) &(a), (simde_float64*) &(b), precision)

#endif
