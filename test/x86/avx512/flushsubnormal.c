#define SIMDE_TEST_X86_AVX512_INSN flushsubnormal

#include <test/x86/avx512/test-avx512.h>
#include <simde/x86/avx512/flushsubnormal.h>

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

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(x_mm_flushsubnormal_ps)
SIMDE_TEST_FUNC_LIST_END

#include <test/x86/avx512/test-avx512-footer.h>
