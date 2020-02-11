#include "../../simde/x86/sse2.h"

#include "test-sse.h"

#if !defined(SIMDE_TEST_X86_SSE2)
#define SIMDE_TEST_X86_SSE2

SIMDE_TEST_DEFINE_ASSERT_VEC_CLOSE(m128d, f64)

#define simde_assert_m128d_close(a, b, precision) \
  simde_assert_m128d_f64_close_ex(__LINE__, __FILE__, a, b, precision)

#endif /* !defined(SIMDE_TEST_X86_SSE2) */
