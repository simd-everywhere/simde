#define SIMDE_TEST_X86_AVX512_INSN flushsubnormal

#include <test/x86/avx512/test-avx512.h>
#include <simde/x86/avx512/flushsubnormal.h>
#include <simde/x86/avx512/set1.h>

#if !defined(SIMDE_FAST_MATH)
static int
test_simde_x_mm_flushsubnormal_ps (SIMDE_MUNIT_TEST_ARGS) {
  for (size_t i = 0 ; i < 8 ; i++) {
    simde__m128 a, r;
    simde__m128i e;
    if (simde_test_codegen_random_i32() & 1) {
      a = simde_mm_set1_ps(SIMDE_MATH_FLT_MIN / 2.0f);
      e = simde_mm_set1_epi32(0);
    } else {
      a = simde_mm_set1_ps(SIMDE_FLOAT32_C(1.0));
      e = simde_mm_castps_si128(simde_mm_set1_ps(SIMDE_FLOAT32_C(1.0)));
    }
    r = simde_x_mm_flushsubnormal_ps(a);

    simde_test_x86_assert_equal_i32x4(simde_mm_castps_si128(r), e);
  }

  return 0;
}

static int
test_simde_x_mm256_flushsubnormal_ps (SIMDE_MUNIT_TEST_ARGS) {
  for (size_t i = 0 ; i < 8 ; i++) {
    simde__m256 a, r;
    simde__m256i e;
    if (simde_test_codegen_random_i32() & 1) {
      a = simde_mm256_set1_ps(SIMDE_MATH_FLT_MIN / 2.0f);
      e = simde_mm256_set1_epi32(0);
    } else {
      a = simde_mm256_set1_ps(SIMDE_FLOAT32_C(1.0));
      e = simde_mm256_castps_si256(simde_mm256_set1_ps(SIMDE_FLOAT32_C(1.0)));
    }
    r = simde_x_mm256_flushsubnormal_ps(a);

    simde_test_x86_assert_equal_i32x8(simde_mm256_castps_si256(r), e);
  }

  return 0;
}

static int
test_simde_x_mm512_flushsubnormal_ps (SIMDE_MUNIT_TEST_ARGS) {
  for (size_t i = 0 ; i < 8 ; i++) {
    simde__m512 a, r;
    simde__m512i e;
    if (simde_test_codegen_random_i32() & 1) {
      a = simde_mm512_set1_ps(SIMDE_MATH_FLT_MIN / 2.0f);
      e = simde_mm512_set1_epi32(0);
    } else {
      a = simde_mm512_set1_ps(SIMDE_FLOAT32_C(1.0));
      e = simde_mm512_castps_si512(simde_mm512_set1_ps(SIMDE_FLOAT32_C(1.0)));
    }
    r = simde_x_mm512_flushsubnormal_ps(a);

    simde_test_x86_assert_equal_i32x16(simde_mm512_castps_si512(r), e);
  }

  return 0;
}

static int
test_simde_x_mm_flushsubnormal_pd (SIMDE_MUNIT_TEST_ARGS) {
  for (size_t i = 0 ; i < 8 ; i++) {
    simde__m128d a, r;
    simde__m128i e;
    if (simde_test_codegen_random_i32() & 1) {
      a = simde_mm_set1_pd(SIMDE_MATH_DBL_MIN / 2.0);
      e = simde_mm_set1_epi64x(0);
    } else {
      a = simde_mm_set1_pd(SIMDE_FLOAT64_C(1.0));
      e = simde_mm_castpd_si128(simde_mm_set1_pd(SIMDE_FLOAT64_C(1.0)));
    }
    r = simde_x_mm_flushsubnormal_pd(a);

    simde_test_x86_assert_equal_i64x2(simde_mm_castpd_si128(r), e);
  }

  return 0;
}

static int
test_simde_x_mm256_flushsubnormal_pd (SIMDE_MUNIT_TEST_ARGS) {
  for (size_t i = 0 ; i < 8 ; i++) {
    simde__m256d a, r;
    simde__m256i e;
    if (simde_test_codegen_random_i32() & 1) {
      a = simde_mm256_set1_pd(SIMDE_MATH_DBL_MIN / 2.0);
      e = simde_mm256_set1_epi64x(0);
    } else {
      a = simde_mm256_set1_pd(SIMDE_FLOAT64_C(1.0));
      e = simde_mm256_castpd_si256(simde_mm256_set1_pd(SIMDE_FLOAT64_C(1.0)));
    }
    r = simde_x_mm256_flushsubnormal_pd(a);

    simde_test_x86_assert_equal_i64x4(simde_mm256_castpd_si256(r), e);
  }

  return 0;
}

static int
test_simde_x_mm512_flushsubnormal_pd (SIMDE_MUNIT_TEST_ARGS) {
  for (size_t i = 0 ; i < 8 ; i++) {
    simde__m512d a, r;
    simde__m512i e;
    if (simde_test_codegen_random_i32() & 1) {
      a = simde_mm512_set1_pd(SIMDE_MATH_DBL_MIN / 2.0);
      e = simde_mm512_set1_epi64(0);
    } else {
      a = simde_mm512_set1_pd(SIMDE_FLOAT64_C(1.0));
      e = simde_mm512_castpd_si512(simde_mm512_set1_pd(SIMDE_FLOAT64_C(1.0)));
    }
    r = simde_x_mm512_flushsubnormal_pd(a);

    simde_test_x86_assert_equal_i64x8(simde_mm512_castpd_si512(r), e);
  }

  return 0;
}

#else
/* To avoid a warning about expr < 0 always evaluating to false
 * (-Wtype-limits) because there are no functions to test. */

static int
test_simde_dummy (SIMDE_MUNIT_TEST_ARGS) {
  return 0;
}
#endif /* !defined(SIMDE_FAST_MATH) */

SIMDE_TEST_FUNC_LIST_BEGIN
  #if !defined(SIMDE_FAST_MATH)
    SIMDE_TEST_FUNC_LIST_ENTRY(x_mm_flushsubnormal_ps)
    SIMDE_TEST_FUNC_LIST_ENTRY(x_mm256_flushsubnormal_ps)
    SIMDE_TEST_FUNC_LIST_ENTRY(x_mm512_flushsubnormal_ps)
    SIMDE_TEST_FUNC_LIST_ENTRY(x_mm_flushsubnormal_pd)
    SIMDE_TEST_FUNC_LIST_ENTRY(x_mm256_flushsubnormal_pd)
    SIMDE_TEST_FUNC_LIST_ENTRY(x_mm512_flushsubnormal_pd)
  #else
    SIMDE_TEST_FUNC_LIST_ENTRY(dummy)
  #endif
SIMDE_TEST_FUNC_LIST_END

#include <test/x86/avx512/test-avx512-footer.h>
