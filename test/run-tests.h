#if !defined(SIMDE_RUN_TESTS_H)
#define SIMDE_RUN_TESTS_H

#include  "../simde/hedley.h"
#include "munit/munit.h"
#include "../simde/simde-common.h"

#define SIMDE_TESTS_CONCAT3_EX(a, b, c) a##b##c
#define SIMDE_TESTS_CONCAT3(a, b, c) SIMDE_TESTS_CONCAT3_EX(a, b, c)

#if defined(__cplusplus)
#  define SIMDE_TESTS_CURRENT_LANG cpp
#else
#  define SIMDE_TESTS_CURRENT_LANG c
#endif

#if defined(SIMDE_NO_NATIVE)
#  define SIMDE_TESTS_CURRENT_NATIVE emul
#else
#  define SIMDE_TESTS_CURRENT_NATIVE native
#endif

#define SIMDE_TESTS_GENERATE_SYMBOL_FULL(sym, arch, isa, native, lang) \
  HEDLEY_CONCAT(HEDLEY_CONCAT(HEDLEY_CONCAT(HEDLEY_CONCAT(HEDLEY_CONCAT(HEDLEY_CONCAT(HEDLEY_CONCAT(HEDLEY_CONCAT(simde_tests_, HEDLEY_CONCAT(arch, _)), isa), _), native), _), lang),_),sym)
#define SIMDE_TESTS_GENERATE_SYMBOL(sym) \
  SIMDE_TESTS_GENERATE_SYMBOL_FULL(sym, SIMDE_TESTS_CURRENT_ARCH, SIMDE_TESTS_CURRENT_ISAX, SIMDE_TESTS_CURRENT_NATIVE, SIMDE_TESTS_CURRENT_LANG)

#define SIMDE_TESTS_GENERATE_NAME(name) \
  "/" HEDLEY_STRINGIFY(name) "/" HEDLEY_STRINGIFY(SIMDE_TESTS_CURRENT_NATIVE) "/" HEDLEY_STRINGIFY(SIMDE_TESTS_CURRENT_LANG)

#define SIMDE_TESTS_DEFINE_TEST(name) \
  { (char*) SIMDE_TESTS_GENERATE_NAME(name), test_simde_##name, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }

HEDLEY_BEGIN_C_DECLS

void random_f32v(size_t nmemb, simde_float32 v[HEDLEY_ARRAY_PARAM(nmemb)]);
void random_f64v(size_t nmemb, simde_float64 v[HEDLEY_ARRAY_PARAM(nmemb)]);
simde_float64 random_f64_range(simde_float64 min, simde_float64 max);
simde_float32 random_f32_range(simde_float32 min, simde_float32 max);

#define random_intv_range(T, nmemb, v, min, max) \
  do { \
    for (size_t simde_tmp_i_ = 0 ; simde_tmp_i_ < nmemb ; simde_tmp_i_++) { \
      ((T*) (v))[simde_tmp_i_] = munit_rand_int_range(min, max); \
    } \
  } while (0)

#define TEST_PREFERRED_ITERATIONS (256)

/* I'll probably move these into µnit, but I want to play around with
   them for a while first. */

#define simde_assert_array_full(prefix, suffix, T, fmt, nmemb, a, op, b) \
  do { \
    const T* simde__tmp_a_ = (a); \
    const T* simde__tmp_b_ = (b); \
    for (size_t simde__i_ = 0 ; simde__i_ < nmemb ; simde__i_++) { \
      if (!(simde__tmp_a_[simde__i_] op simde__tmp_b_[simde__i_])) { \
	munit_errorf("assertion failed: (" #a ")[%" MUNIT_SIZE_MODIFIER "u] " #op " (" #b ")[%" MUNIT_SIZE_MODIFIER "u] (" prefix "%" fmt suffix " " #op " " prefix "%" fmt suffix ")", simde__i_, simde__i_, simde__tmp_a_[simde__i_], simde__tmp_b_[simde__i_]); \
      } \
    } \
  } while (0)

#define simde_assert_typev(T, fmt, nmemb, a, op, b) \
  simde_assert_array_full("", "", T, fmt, nmemb, a, op, b)

#define simde_assert_f32v(nmemb, a, op, b) \
  simde_assert_typev(simde_float32, "g", nmemb, a, op, b)

#define simde_assert_intv(nmemb, a, op, b) \
  simde_assert_typev(int, "d", nmemb, a, op, b)

#define simde_assert_uintv(nmemb, a, op, b) \
  simde_assert_typev(int, "u", nmemb, a, op, b)

#define simde_assert_int8v(nmemb, a, op, b) \
  simde_assert_array_full("", "", munit_int8_t, PRId8, nmemb, a, op, b)
#define simde_assert_uint8v(nmemb, a, op, b) \
  simde_assert_array_full("", "", munit_uint8_t, PRIu8, nmemb, a, op, b)
#define simde_assert_int16v(nmemb, a, op, b) \
  simde_assert_array_full("", "", munit_int16_t, PRId16, nmemb, a, op, b)
#define simde_assert_uint16v(nmemb, a, op, b) \
  simde_assert_array_full("", "", munit_uint16_t, PRIu16, nmemb, a, op, b)
#define simde_assert_int32v(nmemb, a, op, b) \
  simde_assert_array_full("", "", munit_int32_t, PRId32, nmemb, a, op, b)
#define simde_assert_uint32v(nmemb, a, op, b) \
  simde_assert_array_full("", "", munit_uint32_t, PRIu32, nmemb, a, op, b)
#define simde_assert_int64v(nmemb, a, op, b) \
  simde_assert_array_full("", "", munit_int64_t,  PRId64, nmemb, a, op, b)
#define simde_assert_uint64v(nmemb, a, op, b) \
  simde_assert_array_full("", "", munit_uint64_t, PRIu64, nmemb, a, op, b)

#define simde_assert_f32v_equal(T, nmemb, a, b, precision) \
  do { \
    const T* simde_tmp_a_ = (a); \
    const T* simde_tmp_b_ = (b); \
    for (size_t simde_i_ = 0 ; simde_i_ < nmemb ; simde_i_++) { \
      const T simde_tmp_diff_ = ((simde_tmp_a_[simde_i_] - simde_tmp_b_[simde_i_]) < 0) ? \
	(simde_tmp_b_[simde_i_] - simde_tmp_a_[simde_i_]) : \
	(simde_tmp_a_[simde_i_] - simde_tmp_b_[simde_i_]); \
      if (MUNIT_UNLIKELY(simde_tmp_diff_ > 1e-##precision)) { \
	munit_errorf("assertion failed: (" #a ")[%" MUNIT_SIZE_MODIFIER "u] == (" #b ")[%" MUNIT_SIZE_MODIFIER "u] (%." #precision "f == %." #precision "f)", simde_i_, simde_i_, simde_tmp_a_[simde_i_], simde_tmp_b_[simde_i_]); \
      } \
    } \
  } while (0)

#define simde_assert_f32v_close(T, nmemb, a, b, precision) \
  do { \
    const T* simde_tmp_a_ = (a); \
    const T* simde_tmp_b_ = (b); \
    for (size_t simde_i_ = 0 ; simde_i_ < nmemb ; simde_i_++) { \
      const T simde_tmp_diff_ = ((simde_tmp_a_[simde_i_] - simde_tmp_b_[simde_i_]) < 0) ? \
	(simde_tmp_b_[simde_i_] - simde_tmp_a_[simde_i_]) : \
	(simde_tmp_a_[simde_i_] - simde_tmp_b_[simde_i_]); \
      if (MUNIT_UNLIKELY(simde_tmp_diff_ > precision)) { \
	munit_errorf("assertion failed: (" #a ")[%" MUNIT_SIZE_MODIFIER "u] == (" #b ")[%" MUNIT_SIZE_MODIFIER "u] (%" #precision ".1f == %" #precision ".1f)", simde_i_, simde_i_, simde_tmp_a_[simde_i_], simde_tmp_b_[simde_i_]); \
      } \
    } \
  } while (0)

#define simde_assert_f64v_close(T, nmemb, a, b, precision) \
  do { \
    const T* simde_tmp_a_ = (a); \
    const T* simde_tmp_b_ = (b); \
    for (size_t simde_i_ = 0 ; simde_i_ < nmemb ; simde_i_++) { \
      const T simde_tmp_diff_ = ((simde_tmp_a_[simde_i_] - simde_tmp_b_[simde_i_]) < 0) ? \
	(simde_tmp_b_[simde_i_] - simde_tmp_a_[simde_i_]) : \
	(simde_tmp_a_[simde_i_] - simde_tmp_b_[simde_i_]); \
      if (MUNIT_UNLIKELY(simde_tmp_diff_ > precision)) { \
	munit_errorf("assertion failed: (" #a ")[%" MUNIT_SIZE_MODIFIER "u] == (" #b ")[%" MUNIT_SIZE_MODIFIER "u] (%" #precision ".1f == %" #precision ".1f)", simde_i_, simde_i_, simde_tmp_a_[simde_i_], simde_tmp_b_[simde_i_]); \
      } \
    } \
  } while (0)

/* These probably won't go into µnit; they're similar to the
   simde_assert_*v macros above, but print in hex. */

#define simde_assert_int8vx(nmemb, a, op, b) \
  simde_assert_array_full("0x", "", munit_int8_t, "02" PRIx8, nmemb, a, op, b)
#define simde_assert_uint8vx(nmemb, a, op, b) \
  simde_assert_array_full("0x", "", munit_uint8_t, "02" PRIx8, nmemb, a, op, b)
#define simde_assert_int16vx(nmemb, a, op, b) \
  simde_assert_array_full("0x", "", munit_int16_t, "04" PRIx16, nmemb, a, op, b)
#define simde_assert_uint16vx(nmemb, a, op, b) \
  simde_assert_array_full("0x", "", munit_uint16_t, "04" PRIx16, nmemb, a, op, b)
#define simde_assert_int32vx(nmemb, a, op, b) \
  simde_assert_array_full("0x", "", munit_int32_t, "08" PRIx32, nmemb, a, op, b)
#define simde_assert_uint32vx(nmemb, a, op, b) \
  simde_assert_array_full("0x", "", munit_uint32_t, "08" PRIx32, nmemb, a, op, b)
#define simde_assert_int64vx(nmemb, a, op, b) \
  simde_assert_array_full("0x", "", munit_int64_t, "016" PRIx64, nmemb, a, op, b)
#define simde_assert_uint64vx(nmemb, a, op, b) \
  simde_assert_array_full("0x", "", munit_uint64_t, "016" PRIx64, nmemb, a, op, b)

#define simde_assert_int32_close(value, target) \
  do { \
    if (value != target && value != target + 1 && value != target - 1) \
      munit_errorf("assertion failed: %s == %s (%" PRId32 " == %" PRId32 ")", #value, #target, value, target); \
  } while (0)

#define simde_assert_int64_close(value, target) \
  do { \
    if (value != target && value != target + 1 && value != target - 1) \
      munit_errorf("assertion failed: %s == %s (%" PRId64 " == %" PRId64 ")", #value, #target, value, target); \
  } while (0)

HEDLEY_END_C_DECLS

#endif /* !defined(SIMDE_RUN_TESTS_H) */
