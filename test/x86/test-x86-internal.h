#if !defined(SIMDE_TESTS_X86_INTERNAL_H)
#define SIMDE_TESTS_CURRENT_ARCH x86

#include "../run-tests.h"

/* Assert that two vectors are bit-identical without worring about the
   underlying type. */
#define simde_assert_vec_equal(a, b, T) do { \
    for (int simde_i_ = 0 ; simde_i_ < (int) (sizeof(a.u32f) / sizeof(a.u32f[0])) ; simde_i_++) { \
      T simde_a_ = (a), simde_b_ = (b); \
      if (HEDLEY_UNLIKELY(simde_a_.u32f[simde_i_] != simde_b_.u32f[simde_i_])) { \
        munit_errorf("assertion failed: " #a ".u32f[%d] (%" PRIxFAST32 ") != " #b ".u32f[%d] (%" PRIxFAST32 ")", \
            simde_i_, simde_a_.u32f[simde_i_], \
            simde_i_, simde_b_.u32f[simde_i_]); \
      } \
    } \
  } while(0)
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
#define simde_assert_vec_i(a, op, b, T, accessor, fmt) do { \
      const T simde_a_ = (a), simde_b_ = (b); \
      for (int simde_i_ = 0 ; simde_i_ < (int) (sizeof(a.accessor) / sizeof(a.accessor[0])) ; simde_i_++) { \
        if (HEDLEY_UNLIKELY(!(simde_a_.accessor[simde_i_] op simde_b_.accessor[simde_i_]))) { \
          munit_errorf("assertion failed: " #a "." #accessor "[%d] " #op " " #b "." #accessor "[%d] (%" fmt " " #op " %" fmt ")", \
              simde_i_, simde_i_, simde_a_.accessor[simde_i_], simde_b_.accessor[simde_i_]); \
        } \
      } \
    } while (0)
#define simde_assert_m256i_i8(a, op, b) \
  simde_assert_vec_i(a, op, b, simde__m256i,  i8,  PRId8)
#define simde_assert_m256i_i16(a, op, b) \
  simde_assert_vec_i(a, op, b, simde__m256i, i16, PRId16)
#define simde_assert_m256i_i32(a, op, b) \
  simde_assert_vec_i(a, op, b, simde__m256i, i32, PRId32)
#define simde_assert_m256i_i64(a, op, b) \
  simde_assert_vec_i(a, op, b, simde__m256i, i64, PRId64)
#define simde_assert_m256i_u8(a, op, b) \
  simde_assert_vec_i(a, op, b, simde__m256i,  u8,  PRIu8)
#define simde_assert_m256i_u16(a, op, b) \
  simde_assert_vec_i(a, op, b, simde__m256i, u16, PRIu16)
#define simde_assert_m256i_u32(a, op, b) \
  simde_assert_vec_i(a, op, b, simde__m256i, u32, PRIu32)
#define simde_assert_m256i_u64(a, op, b) \
  simde_assert_vec_i(a, op, b, simde__m256i, u64, PRIu64)
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
#define simde_assert_vec_close(a, b, precision, T, accessor) do { \
      const T simde_a_ = (a), simde_b_ = (b); \
      for (int simde_i_ = 0 ; simde_i_ < (int) (sizeof(a.accessor) / sizeof(a.accessor[0])) ; simde_i_++) { \
        if (HEDLEY_UNLIKELY(!((simde_a_.accessor[simde_i_] < (simde_b_.accessor[simde_i_] + 1e-##precision)) && (simde_a_.accessor[simde_i_] > (simde_b_.accessor[simde_i_] - 1e-##precision))))) { \
          munit_errorf("assertion failed: " #a "." #accessor "[%d] " SIMDE_ALMOST_EQUAL_TO " " #b "." #accessor "[%d] (%." #precision "f" " " SIMDE_ALMOST_EQUAL_TO " %." #precision "f)", \
              simde_i_, simde_i_, simde_a_.accessor[simde_i_], simde_b_.accessor[simde_i_]); \
        } \
      } \
    } while(0)

#define simde_assert_m64_close(a, b, precision) \
  simde_assert_vec_close(a, b, precision, simde__m64, f32)
#define simde_assert_m128_close(a, b, precision) \
  simde_assert_vec_close(a, b, precision, simde__m128, f32)
#define simde_assert_m128d_close(a, b, precision) \
  simde_assert_vec_close(a, b, precision, simde__m128d, f64)
#define simde_assert_m256_close(a, b, precision) \
  simde_assert_vec_close(a, b, precision, simde__m256, f32)
#define simde_assert_m256d_close(a, b, precision) \
  simde_assert_vec_close(a, b, precision, simde__m256d, f64)

HEDLEY_BEGIN_C_DECLS

#define SIMDE_TESTS_GENERATE_SUITE_GETTERS(isax) \
  MunitSuite* SIMDE_TESTS_GENERATE_SYMBOL_FULL(suite, SIMDE_TESTS_CURRENT_ARCH, isax, native, c)(void); \
  MunitSuite* SIMDE_TESTS_GENERATE_SYMBOL_FULL(suite, SIMDE_TESTS_CURRENT_ARCH, isax, native, cpp)(void); \
  MunitSuite* SIMDE_TESTS_GENERATE_SYMBOL_FULL(suite, SIMDE_TESTS_CURRENT_ARCH, isax, emul,   c)(void); \
  MunitSuite* SIMDE_TESTS_GENERATE_SYMBOL_FULL(suite, SIMDE_TESTS_CURRENT_ARCH, isax, emul,   cpp)(void)

SIMDE_TESTS_GENERATE_SUITE_GETTERS(mmx);
SIMDE_TESTS_GENERATE_SUITE_GETTERS(sse);
SIMDE_TESTS_GENERATE_SUITE_GETTERS(sse2);
SIMDE_TESTS_GENERATE_SUITE_GETTERS(sse3);
SIMDE_TESTS_GENERATE_SUITE_GETTERS(ssse3);
SIMDE_TESTS_GENERATE_SUITE_GETTERS(sse4_1);
SIMDE_TESTS_GENERATE_SUITE_GETTERS(sse4_2);
SIMDE_TESTS_GENERATE_SUITE_GETTERS(avx);
SIMDE_TESTS_GENERATE_SUITE_GETTERS(fma);
SIMDE_TESTS_GENERATE_SUITE_GETTERS(avx2);

HEDLEY_END_C_DECLS

#endif /* !defined(SIMDE_TESTS_X86_INTERNAL_H) */
