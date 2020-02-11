#include "../../simde/x86/avx.h"

#include "test-sse2.h"

#if !defined(SIMDE_TEST_X86_AVX)
#define SIMDE_TEST_X86_AVX

SIMDE_TEST_DEFINE_ASSERT_VEC_CLOSE(m256, f32)
SIMDE_TEST_DEFINE_ASSERT_VEC_CLOSE(m256d, f64)

#define simde_assert_m256_close(a, b, precision) \
  simde_assert_m256_f32_close_ex(__LINE__, __FILE__, a, b, precision)
#define simde_assert_m256d_close(a, b, precision) \
  simde_assert_m256d_f64_close_ex(__LINE__, __FILE__, a, b, precision)

#endif /* !defined(SIMDE_TEST_X86_AVX) */
