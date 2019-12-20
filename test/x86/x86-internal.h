#if !defined(SIMDE__X86_INTERNAL_H)
#define SIMDE__X86_INTERNAL_H

#include "../../simde/hedley.h"

#if HEDLEY_HAS_WARNING("-Wsign-conversion")
#  pragma clang diagnostic ignored "-Wsign-conversion"
#endif
#if HEDLEY_HAS_WARNING("-Wcast-qual")
#  pragma clang diagnostic ignored "-Wcast-qual"
#endif
#if HEDLEY_HAS_WARNING("-Wpadded")
#  pragma clang diagnostic ignored "-Wpadded"
#endif
#if HEDLEY_HAS_WARNING("-Wmissing-variable-declarations")
#  pragma clang diagnostic ignored "-Wmissing-variable-declarations"
#endif
#if HEDLEY_HAS_WARNING("-Wextra-semi")
#  pragma clang diagnostic ignored "-Wextra-semi"
#endif
#if HEDLEY_HAS_WARNING("-Wfloat-equal")
#  pragma clang diagnostic ignored "-Wfloat-equal"
#endif
#if HEDLEY_HAS_WARNING("-Wdouble-promotion")
#  pragma clang diagnostic ignored "-Wdouble-promotion"
#endif
#if HEDLEY_HAS_WARNING("-Wconditional-uninitialized")
#  pragma clang diagnostic ignored "-Wconditional-uninitialized"
#endif

#include "../test.h"

MunitSuite simde_mmx_test_suite;
MunitSuite simde_mmx_emul_test_suite;

MunitSuite simde_sse_test_suite;
MunitSuite simde_sse_emul_test_suite;

MunitSuite simde_sse2_test_suite;
MunitSuite simde_sse2_emul_test_suite;

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

MunitSuite simde_fma_test_suite;
MunitSuite simde_fma_emul_test_suite;


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
#define simde_assert_m128_f32_close(a, b, precision) \
  simde_assert_f32v_close(simde_float32, 4, (simde_float32*) &(a), (simde_float32*) &(b), precision)

#define simde_assert_m128d_f32(a, op, b) \
  simde_assert_typev(simde_float32, "f", 4, (simde_float32*) &(a), op, (simde_float32*) &(b))
#define simde_assert_m128d_f32_equal(a, b, precision) \
  simde_assert_f32v_equal(simde_float32, 4, (simde_float32*) &(a), (simde_float32*) &(b), precision)
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



/* Assert that two vectors are bit-identical without worring about the
   underlying type. */
#define simde_assert_vec_equal(a, b, T) { \
    for (int simde_i_ = 0 ; simde_i_ < (int) (sizeof(a.u32f) / sizeof(a.u32f[0])) ; simde_i_++) { \
      T simde_a_ = (a), simde_b_ = (b); \
      if (HEDLEY_UNLIKELY(simde_a_.u32f[simde_i_] != simde_b_.u32f[simde_i_])) { \
        munit_errorf("assertion failed: " #a ".u32f[%d] (%" PRIxFAST32 ") != " #b ".u32f[%d] (%" PRIxFAST32 ")", \
            simde_i_, simde_a_.u32f[simde_i_], \
            simde_i_, simde_b_.u32f[simde_i_]); \
      } \
    } \
  }
#define simde_assert_m64_equal(a, b) \
  simde_assert_vec_equal(a, b, simde__m64)
#define simde_assert_m128_equal(a, b) \
  simde_assert_vec_equal(a, b, simde__m128)
#define simde_assert_m128i_equal(a, b) \
  simde_assert_vec_equal(a, b, simde__m128i)
#define simde_assert_m128d_equal(a, b) \
  simde_assert_vec_equal(a, b, simde__m128d)
#define simde_assert_m256_equal(a, b) \
  simde_assert_vec_equal(a, b, simde__m256)
#define simde_assert_m256i_equal(a, b) \
  simde_assert_vec_equal(a, b, simde__m256i)
#define simde_assert_m256d_equal(a, b) \
  simde_assert_vec_equal(a, b, simde__m256d)

/* Assert that every integer in two vectors are equal */
#define simde_assert_vec_i(a, op, b, T, accessor, fmt) { \
      const T simde_a_ = (a), simde_b_ = (b); \
      for (int simde_i_ = 0 ; simde_i_ < (int) (sizeof(a.accessor) / sizeof(a.accessor[0])) ; simde_i_++) { \
        if (HEDLEY_UNLIKELY(!(simde_a_.accessor[simde_i_] op simde_b_.accessor[simde_i_]))) { \
          munit_errorf("assertion failed: " #a "." #accessor "[%d] " #op " " #b "." #accessor "[%d] (%" fmt " " #op " %" fmt ")", \
              simde_i_, simde_i_, simde_a_.accessor[simde_i_], simde_b_.accessor[simde_i_]); \
        } \
      } \
    }
#define simde_assert_m128i_i8(a, op, b) \
  simde_assert_vec_i(a, op, b, simde__m128i,  i8,  PRId8)
#define simde_assert_m128i_i16(a, op, b) \
  simde_assert_vec_i(a, op, b, simde__m128i, i16, PRId16)
#define simde_assert_m128i_i32(a, op, b) \
  simde_assert_vec_i(a, op, b, simde__m128i, i32, PRId32)
#define simde_assert_m128i_i64(a, op, b) \
  simde_assert_vec_i(a, op, b, simde__m128i, i64, PRId64)
#define simde_assert_m128i_u8(a, op, b) \
  simde_assert_vec_i(a, op, b, simde__m128i,  u8,  PRIu8)
#define simde_assert_m128i_u16(a, op, b) \
  simde_assert_vec_i(a, op, b, simde__m128i, u16, PRIu16)
#define simde_assert_m128i_u32(a, op, b) \
  simde_assert_vec_i(a, op, b, simde__m128i, u32, PRIu32)
#define simde_assert_m128i_u64(a, op, b) \
  simde_assert_vec_i(a, op, b, simde__m128i, u64, PRIu64)
#define simde_assert_m64_i8(a, op, b) \
  simde_assert_vec_i(a, op, b, simde__m64,  i8,  PRId8)
#define simde_assert_m64_i16(a, op, b) \
  simde_assert_vec_i(a, op, b, simde__m64, i16, PRId16)
#define simde_assert_m64_i32(a, op, b) \
  simde_assert_vec_i(a, op, b, simde__m64, i32, PRId32)
#define simde_assert_m64_i64(a, op, b) \
  simde_assert_vec_i(a, op, b, simde__m64, i64, PRId64)
#define simde_assert_m64_u8(a, op, b) \
  simde_assert_vec_i(a, op, b, simde__m64,  u8,  PRIu8)
#define simde_assert_m64_u16(a, op, b) \
  simde_assert_vec_i(a, op, b, simde__m64, u16, PRIu16)
#define simde_assert_m64_u32(a, op, b) \
  simde_assert_vec_i(a, op, b, simde__m64, u32, PRIu32)
#define simde_assert_m64_u64(a, op, b) \
  simde_assert_vec_i(a, op, b, simde__m64, u64, PRIu64)

#if !defined(HEDLEY_PGI_VERSION)
#  define SIMDE_ALMOST_EQUAL_TO "≈"
#else
#  define SIMDE_ALMOST_EQUAL_TO "~=~"
#endif

/* Assert that the floating point values in each vector are approximately equal. */
#define simde_assert_vec_close(a, b, precision, T, accessor) { \
      const T simde_a_ = (a), simde_b_ = (b); \
      for (int simde_i_ = 0 ; simde_i_ < (int) (sizeof(a.accessor) / sizeof(a.accessor[0])) ; simde_i_++) { \
        if (HEDLEY_UNLIKELY(!((simde_a_.accessor[simde_i_] < (simde_b_.accessor[simde_i_] + 1e-##precision)) && (simde_a_.accessor[simde_i_] > (simde_b_.accessor[simde_i_] - 1e-##precision))))) { \
          munit_errorf("assertion failed: " #a "." #accessor "[%d] " SIMDE_ALMOST_EQUAL_TO " " #b "." #accessor "[%d] (%." #precision "f" " " SIMDE_ALMOST_EQUAL_TO " %." #precision "f)", \
              simde_i_, simde_i_, simde_a_.accessor[simde_i_], simde_b_.accessor[simde_i_]); \
        } \
      } \
    }

#define simde_assert_m128_close(a, b, precision) \
  simde_assert_vec_close(a, b, precision, simde__m128, f32)
#define simde_assert_m128d_close(a, b, precision) \
  simde_assert_vec_close(a, b, precision, simde__m128d, f64)
#define simde_assert_m256_close(a, b, precision) \
  simde_assert_vec_close(a, b, precision, simde__m256, f32)
#define simde_assert_m256d_close(a, b, precision) \
  simde_assert_vec_close(a, b, precision, simde__m256d, f64)

#endif
